#include "QUESTS\Quest_Messages.h"
#include "QUESTS\facemaker.c" // function now moved to a separate file by KAM

#define DEBUG_FETCH_QUEST		0 	//(bool) set to 1 for debug messages
#define CHANCE_FETCH_QUEST		150 //(int)  this is the chance of 1 in X.
#define MAX_NUMBER_FETCH_QUEST	2	//(int)  Amount of fetch quests per island (max)
#define FETCH_QUEST_POST_CHANCE	80  //(int)  0-100 chance of fetch quest getting posted in tavern news.

bool bQuestDisableAllCommands = false; // KK

// boal -->
void GenerateQuestShip(string character_id, int iNation) // KK
{
	bool isEnemy = false;
	if(character_id == "Quest pirate" ) isEnemy = true;
	if(character_id == "Convoy pirate") isEnemy = true;
	InitQuestCaptain(character_id, iNation, isEnemy);		// LDH 05Sep06 // KK

	ref PChar = GetMainCharacter(); // KK
	int iShipType, iTradeMoney, irank, pRank;

	//PB: Generate Rank and Skills
	pRank = sti(PChar.rank);
	if(GetShipCap()) { if((8-GetCharacterShipClass(PChar)) * 2 < pRank) { pRank = (8-GetCharacterShipClass(PChar)) * 2; } } // NK
	irank = makeint((pRank/2.0 + Rand(pRank/2)) * (2.0/3.0 + ((makefloat(GetDifficulty())-1.0)/5.0)) + 0.5);
	if(irank < 1) irank = 1;
	if(isEnemy) irank += GetRank(PChar, iNation); // PB: Increase Difficulty for Higher Nation Rank
	ref rFantom = characterFromID(character_id); // KK

	if( sti(rFantom.nation) >= NATIONS_QUANTITY)	rFantom.nation = PIRATE; // KB- Fix Governor Pirate Quest bug // KK
													rFantom.FantomType = "war";
	if( sti(rFantom.nation) == PIRATE)				rFantom.FantomType = "pirate";
	float mult = 1.0;
	switch(rFantom.FantomType)
	{
		case "war":
			mult *= 1.25;
			rFantom.quest.officertype = OFFIC_TYPE_CAPNAVY;
			break;

		case "pirate":
			mult *= 1.5; //note this is different from AIFantom! Because the gov knows this pirate is hunting near his island!
			rFantom.quest.officertype = OFFIC_TYPE_CAPPIRATE;
			break;
	}
	//rFantom.skill.freeskill  = 2*irank;
	//rFantom.Perks.Freepoints = irank;
	/*LAi_Officer_SetSkillmodifiers_and_Perks(rFantom, 0);
	LAi_SetSkill_on_Modifier(rFantom);*/
	//ResetSkillsandPerks(rFantom);
	rFantom.rank = irank;
	rFantom.skipPostInit = true; // PB: Make sure this captain is initialized RIGHT NOW and not later!
	InitCharacterSkills(rFantom);
	Fantom_SetRandomMoney(rFantom, rFantom.FantomType);
	rFantom.money = sti(rFantom.ShipMoney)/3;						// GR: Give some of shipmoney to captain so you can rob him
	rFantom.ShipMoney = sti(rFantom.ShipMoney)*200/300;

	TakeItemFromCharacter(rFantom, CheckCharacterEquipByGroup(&rFantom, BLADE_ITEM_TYPE));	// GR: Remove whatever random weapons the captain has kept from a previous role...
	TakeItemFromCharacter(rFantom, CheckCharacterEquipByGroup(&rFantom, GUN_ITEM_TYPE));
	LAi_NPC_Equip(rFantom, sti(rFantom.rank), true, 0.5*mult);				// GR: ... and give him new weapons suited to his level and type																									   
													
	SetRandomNameToCharacter(rFantom);
	rFantom.old.name = rFantom.name; // KK
	rFantom.old.lastname = rFantom.lastname; // KK

	//PB: Generate Ship
	DeleteAttribute(rFantom, "Ship");

	int maxclass, minclass;
	maxclass = GetShipMinClassForSkills(sti(rFantom.skill.Leadership), sti(rFantom.skill.Sailing));	// PB: Same limit as for player
	if(sti(rFantom.nation) == PIRATE             && maxclass < MAXPIRATECLASS)			maxclass = MAXPIRATECLASS;		// KK
	if(HasSubStr(character_id,"Coastal_Captain") && maxclass < MAXCOASTGUARDCLASS)		maxclass = MAXCOASTGUARDCLASS;	// PB
	if(GetCurrentPeriod() <= PERIOD_EARLY_EXPLORERS || GetCurrentPeriod() >= PERIOD_NAPOLEONIC)
	{
		if(sti(rFantom.nation) == HOLLAND        && maxclass < 3)						maxclass = 3;
		if(sti(rFantom.nation) == PORTUGAL       && maxclass < 3)						maxclass = 3;
	}

	minclass =			maxclass + 2;
	if(minclass > 8)	minclass = 8;

	iShipType = Force_GetShipType(maxclass, minclass, "War", sti(rFantom.nation)); // PS
	GiveShip2Character(rFantom, GetShipID(iShipType), "Ship Name", -1, sti(rFantom.nation), true, true); // PB: Generic Function
	SetRandomNameToShip(rFantom);
	Ship_SetFantomData(rFantom);

	aref arship; makearef(arship, rFantom.ship);
	ref Shiptype = GetShipByType(iShipType);
	int iMCShipClass = makeint(GetCharacterShipClass(PChar)); // KK
	if(makeint(Shiptype.Class) < iMCShipClass) mult *= 1.5;
	if(makeint(Shiptype.Class) > iMCShipClass) mult *= 0.75;
	rFantom.Points = mult * stf(GetLocalShipAttrib(arship, Shiptype, "Weight")) / 5000; // PRS3
	rFantom.recognized = true; // PB: Have these ships always hostile, regardless of flag

	if(character_id == "Quest pirate")	// PB: For Governor Quest Ships only
	{
		//NK edit trademoney
		float shipmult = 5.0 * sqrt(intRet(sti(Shiptype.CannonsQuantity),sti(Shiptype.CannonsQuantity),1) * sti(GetLocalShipAttrib(arship, Shiptype, "HP")) * stf(GetLocalShipAttrib(arship, Shiptype, "SpeedRate"))); // PRS3
		float commult = 1.0 + makeint(CalcCharacterSkill(PChar, SKILL_COMMERCE))/20.0;

		iTradeMoney = makeint(sqrt(irank) * shipmult * commult/25)*25;
		if(iTradeMoney < 100) iTradeMoney = 100;

		pchar.quest.generate_kill_quest = "begin";
		pchar.quest.generate_kill_quest.money = iTradeMoney;
		pchar.quest.generate_kill_quest.town = GetCurrentTownID();//MAXIMUS
		pchar.quest.generate_kill_quest.destination = Islands[GetCharacterCurrentIsland(Pchar)].id;
		pchar.quest.generate_kill_quest.nation = sti(rFantom.nation); // KK // MAXIMUS
		pchar.quest.generate_kill_quest.shipname = rFantom.Ship.Name;
	}
}
// boal <--

bool CreateParticleSystemOnLocator(string _location_id, string _locatorName, string _particleName)
{
	aref locator;
	if (!FindLocator(_location_id, _locatorName, &locator, true))
		return false;

	CreateParticleSystemX(_particleName,stf(locator.x),stf(locator.y),stf(locator.z), stf(locator.vz.x),stf(locator.vz.y),stf(locator.vz.z),0);
	return true;
}

int GenerateNationTrade(int nation)
{
	int i = -1;
	string friendlyNations = "";
	bool has_town = false;
	for(int j=0; j<NATIONS_QUANTITY; j++)
	{
		if (j != PIRATE)											// PB: Any pirate town is fair game
		{
		//	if (GetNationRelation2MainCharacter(j) == RELATION_ENEMY)			continue;	// PB: You should never have to go to ports hostile to yourself
			if (GetNationRelation(nation, j) == RELATION_ENEMY && nation != PIRATE)		continue;	// PB: Nor towns that are hostile to the current location (unless it is pirate)

			//GR: Don't trade with nations which have nowhere to trade!
			i = 0;
			has_town = false;
			while (!has_town && i < TOWNS_QUANTITY)
			{
				if (CheckAttribute(Towns[i],"id") && GetAttribute(Towns[i],"skiptrade")!=true && CheckAttribute(Towns[i],"nation") && sti(Towns[i].nation)==j) has_town = true;
				i++;
			}
			if (!has_town) continue;
			//End of check for trading towns
		}
		string tmpNat = j;
		friendlyNations = StoreString(friendlyNations,tmpNat);
	}
	trace("GenerateNationTrade: list of friendly nations = " + friendlyNations);
	i = sti(GetRandSubString(friendlyNations));
	if (nation != PIRATE && i == PIRATE)
	{
		trace("Nation: " + GetNationNameByType(nation) + ", trying to send to " + GetNationNameByType(i));
		i = sti(GetRandSubString(friendlyNations));		// GR: Attempt to fix excessive amount of trade quests to Pirate stores.  If Pirates are chosen for a non-pirate nation, try once more.
		trace("GenerateNationTrade: trying not to send " + GetNationDescByType(nation) + " trade to Pirates");
		trace("friendlyNations = " + friendlyNations);
		trace("Now sending to " + GetNationNameByType(i));
	}

	return i;
}

// NK -->
int GenerateGoodForTrade(int FromNat, int ToNat, ref fromprice, ref toprice) // NK add prices 05-05-12
{
	//int fstoreidx = GetTownStoreIndex(GetTownIDFromGroup(Stores[GetCharacterCurrentStore(GetMainCharacter())].group));
	int fstoreidx = GetTownStoreIndex(GetCurrentTownID());
	//trace("from " + fstoreidx + " of " + GetCurrentTownID());
	string destCol;
	string friendlyTowns = "";
	for(int j=0; j<TOWNS_QUANTITY; j++)
	{
		if(!CheckAttribute(&Towns[j],"id")) continue;
		if(!CheckAttribute(&Towns[j],"nation")) continue;
		if(CheckAttribute(&Towns[j],"skiptrade") && Towns[j].skiptrade==true) continue;//MAXIMUS: added for some towns (such as St. John's on Antigua)
		if(Towns[j].nation!=ToNat) continue;
		if(GetIslandIDFromTown(Towns[j].id) == GetIslandIDFromTown(GetCurrentTownID())) continue;
		friendlyTowns = StoreString(friendlyTowns,Towns[j].id);
	}
	if(friendlyTowns!="")
	{
		destCol = GetRandSubString(friendlyTowns);
		while(destCol=="" || HasSubStr(destCol,",")) { destCol = GetRandSubString(friendlyTowns); }
	}
	else
	{
		switch (ToNat)
		{
			case FRANCE: destCol = FRA_COLONY; break;
			case SPAIN: destCol = SPA_COLONY; break;
			case HOLLAND: destCol = HOL_COLONY; break;
			case PORTUGAL: destCol = POR_COLONY; break;
			case ENGLAND:  destCol = RED_COLONY; break;
		}
	}
	int tstoreidx = GetTownStoreIndex(destCol);
	//trace("to " + tstoreidx + " of " + destCol);
	ref sfrom, sto;
	makeref(sfrom, Stores[fstoreidx]);
	makeref(sto, Stores[tstoreidx]);
	int gt;
	bool found = false;
	for(int i = 0; i < 512; i++) //to
	{
		gt = rand(GOODS_QUANTITY - 1); // KK
		if(CheckAttribute(Goods[gt],"skip") && sti(Goods[gt].skip)) { continue; }
		if(GetStoreGoodsType(sfrom, gt) == TRADE_TYPE_CONTRABAND_NAME) continue;
		if(GetStoreGoodsType(sfrom, gt) == TRADE_TYPE_IMPORT_NAME) continue; // Sulan: Usually to make profit, don't export import goods
		if(GetStoreGoodsType(sto, gt) == TRADE_TYPE_CONTRABAND_NAME) continue;
		if(GetStoreGoodsType(sto, gt) == TRADE_TYPE_EXPORT_NAME) continue; // Sulan: Usually to make profit, don't import export goods
		found = true;
		break;
	}

	ref PChar = GetMainCharacter();
	if(!found) gt = GOOD_CHOCOLATE;
	// yes this is not dynamic-price compliant, but then TheDiamond will be redoing the economics anyway. NK 05-05-12
	fromprice = round(makefloat(GetStoreGoodsPrice(sfrom, gt, PRICE_TYPE_BUY, PChar, 0)) / GetCharPriceMod(PChar, PRICE_TYPE_BUY, true, false));
	toprice = round(makefloat(GetStoreGoodsPrice(sto, gt, PRICE_TYPE_SELL, PChar, 0)) / GetCharPriceMod(PChar, PRICE_TYPE_SELL, true, false));
	// NK 05-05-12 <--
	return gt;
}
// NK <--

void OfficersReaction(string alignment)
{
	int iPassenger;
	ref PChar;
	PChar = GetMainCharacter();

	for (int io = 0; io<GetPassengersQuantity(pchar); io++)
	{
		iPassenger = GetPassenger(pchar, io);
		if(GetAttribute(characters[iPassenger], "alignment") != "neutral")
		{
			if(CheckAttribute(characters[iPassenger], "loyality") && CheckAttribute(characters[iPassenger], "alignment"))
			{
				if (characters[iPassenger].alignment == alignment)
				{
					characters[iPassenger].loyality = makeint(characters[iPassenger].loyality) + 1;
				}
				else
				{
					characters[iPassenger].loyality = makeint(characters[iPassenger].loyality) - 1;

					if(makeint(characters[iPassenger].loyality) < 1)
					{
						PlaceCharacter(&characters[iPassenger], "goto");
						characters[iPassenger].selfdialog.filename = characters[iPassenger].dialog.filename;
						characters[iPassenger].selfdialog.currentnode = characters[iPassenger].dialog.currentnode;
						characters[iPassenger].dialog.filename = "anacleto_dialog.c";
						characters[iPassenger].dialog.currentnode = "remove";
						LAi_SetActorType(&characters[iPassenger]);
						LAi_ActorDialog(&characters[iPassenger], pchar, "player_back", 2.0, 1.0);
						LAi_SetStayType(pchar);
					}
				}
			}
		}
	}
}

// NK itemtrade 05-03-26 move Item trader functions to items_utilite.c

string GenerateDestination()
{
	ref PChar = GetMainCharacter();
	string sdestination = "";
	string friendlyTowns = "";

//MAXIMUS -[such functions must be universal (IMHO), if we are planning to make a real Caribbean in the future]->
	for(int i=0; i<TOWNS_QUANTITY; i++)
	{
		ref ctown; makeref(ctown, Towns[i]);
		if (GetAttribute(ctown,"skiptrade") == true)												continue;	// MAXIMUS: added for some towns (such as St. John's on Antigua)
		if (sti(ctown.nation) != PIRATE)																												// PB: Any pirate town is fair game
		{
		//	if (GetNationRelation2MainCharacter(sti(ctown.nation)) == RELATION_ENEMY)							continue;	// PB: You should never have to go to ports hostile to yourself
			if (GetNationRelation(GetCurrentLocationNation(), sti(ctown.nation)) == RELATION_ENEMY && GetCurrentLocationNation() != PIRATE)	continue;	// PB: Nor towns that are hostile to the current location (unless it is pirate)
		}

		friendlyTowns = StoreString(friendlyTowns,ctown.id);
	}
	if (friendlyTowns != "")
	{
		sdestination = GetRandSubString(friendlyTowns);
		while (sdestination=="" || HasSubStr(sdestination,",") || GetIslandIDFromTown(sdestination)==GetIslandIDFromTown(GetCurrentTownId())) sdestination = GetRandSubString(friendlyTowns);

		if (GetCurrentLocationNation() != PIRATE && GetTownNation(sdestination) == PIRATE)		//GR: if a pirate destination has been picked for a non-pirate source, try once more
		{
			sdestination = GetRandSubString(friendlyTowns);
			while (sdestination=="" || HasSubStr(sdestination,",") || GetIslandIDFromTown(sdestination)==GetIslandIDFromTown(GetCurrentTownId())) sdestination = GetRandSubString(friendlyTowns);
			trace("GenerateDestination: trying not to use Pirates as destination for " + GetNationNameByType(GetCurrentLocationNation()));
			trace("Now sending to " + sdestination);
		}
	}
	else
	{
		sdestination = DEFAULT_DESTINATION;
	}
//MAXIMUS <-[such functions must be universal (IMHO), if we are planning to make a real Caribbean in the future]-

	return sdestination;
}

string FindDestinationName(string sdest)
{
	ref PChar = GetMainCharacter();
	string sIsland = PChar.quest.generate_convoy_quest.island;
	string sDestin = "";
	for(int di=sti(Locations[0].IslandsList.(sIsland).begin); di<sti(Locations[0].IslandsList.(sIsland).end); di++)
	{
		if(CheckAttribute(&locations[di],"townsack") && locations[di].townsack==PChar.quest.generate_convoy_quest.destination)
		{
			if(CheckAttribute(&locations[di],"id") && HasSubStr(locations[di].id,"port"))
			{
				sdest = locations[di].id;
				if(FindLocation(sdest)!=-1)
				{
					switch(LanguageGetLanguage())
					{
						case "SPANISH": sDestin = "puerto de "+ FindTownName(PChar.quest.generate_convoy_quest.destination); break;
						sDestin = FindTownName(PChar.quest.generate_convoy_quest.destination) + " " + TranslateString("", "SeaPort");
					}
				}
				break;
			}
		}
	}
	if(sdest=="") // No valid port found for this town, so get shore instead
	{
		switch(sIsland)
		{
			case "Conceicao":			sdest = "Conceicao_shore_02";	break;
			case "Douwesen":			sdest = "Douwesen_Shore_01";	break; // PB
			case "Hispaniola":			sdest = "Hispaniola_shore_02";	break; // PB
		}
		if(FindLocation(sdest)!=-1) sDestin = TranslateString("",locations[FindLocation(sdest)].id.label);
	}
	sDestin = strreplace(sDestin, ".", ""); // PB: No dots in the middle of a sentence, please
	return sDestin;
}

void GenerateConvoyQuest()
{
	ref PChar = GetMainCharacter();
	ref rTrader = characterFromID("Quest trader"); // KK
	int iShipType, iCargoType, iTradeGoods, iTradeMoney, irank;
	irank = sti(PChar.rank); // PS
	DeleteAttribute(rTrader, "Ship");
	DeleteAttribute(rTrader, "cancel_mutiny"); // PB

	string cDestination;
	if(CheckAttribute(pchar,"quest.generate_convoy_quest.destination"))
		cDestination = pchar.quest.generate_convoy_quest.destination;
	else
	{
		cDestination = GenerateDestination();
		pchar.quest.generate_convoy_quest.destination = cDestination;
	}
	pchar.quest.generate_convoy_quest.island = GetIslandIDFromTown(cDestination);
	if(cDestination == DEFAULT_DESTINATION || cDestination == "")
	{
		pchar.quest.generate_convoy_quest.destination = DEFAULT_DESTINATION;
		pchar.quest.generate_convoy_quest.island = DEFAULT_TRADEISLAND;
	}

// PB -->
	int iNation = GetCurrentLocationNation();
	int nNation = GetTownNation(cDestination);
	
	if (iNation == PIRATE)	iNation = nNation;							// If pirate, use the other one
	if (nNation == PIRATE)	nNation = iNation;							// If pirate, use the other one
	if (rand(1) == 0)		iNation = nNation;							// Use either of the two
	if (iNation == PIRATE)	FindFriendlyNation2Nation(PERSONAL_NATION);	// Apparently BOTH are pirate, so get a nation friendly to the player
	rTrader.nation = iNation;

	SetRandomNameToCharacter(rTrader);
	SetModelfromArray(rTrader, GetModelIndex(GetRandomModelForTypeExSubCheck(-1, "Upper_Citizens", "man", iNation)));
// PB <--

	// PS -->
	irank = 8 - irank/2;
	if(irank < MAXMERCHANTCLASS) irank = MAXMERCHANTCLASS;
	if(irank > 5) irank = 5;
	iShipType = Force_GetShipType(7, irank, "trade", iNation); // PB: Was personal nation???
	rTrader.ship.type = GetShipID(iShipType);
	// PS <--
	SetRandomNameToShip(rTrader);
	SetBaseShipData(rTrader);

	SetCharacterGoods(rTrader, GOOD_WHEAT, makeint(sti(rTrader.ship.crew.quantity) * FOOD_PER_CREW * (WHEAT_DAYS + RUM_DAYS))); // KK
	iTradeGoods = rand(20) + 6;
	iCargoType = GetCharacterFreeSpace(rTrader, iTradeGoods);
	AddCharacterGoods(rTrader, iTradeGoods, iCargoType);
	
	//Levis: Moved money after destination and take distance into account.
	string dislandid = GetIslandIDFromTown(cDestination);
	string cislandid = GetIslandIDFromTown(GetCurrentTownID());
//	trace("distance between "+dislandid+" and "+cislandid+": "+stf(worldMap.islands.(dislandid).position.x)+" , "+stf(worldMap.islands.(dislandid).position.z)+" , "+stf(worldMap.islands.(cislandid).position.x)+" , "+stf(worldMap.islands.(cislandid).position.z));
	int distancedestination = GetDistance2D(stf(worldMap.islands.(dislandid).position.x), stf(worldMap.islands.(dislandid).position.z), stf(worldMap.islands.(cislandid).position.x), stf(worldMap.islands.(cislandid).position.z));
	
	iTradeMoney = pow((0.5*Goods[iTradeGoods].Cost + iCargoType)*(1.0+(5.0-GetDifficulty())/5.0),0.5) * 0.05 * pow(irank ,0.5) * pow(distancedestination,1.2);

	rTrader.money = iTradeMoney * rand(irank) + rand(100); // KK
	rTrader.reputation = iClamp(REPUTATION_RASCAL,REPUTATION_GOOD,sti(PChar.reputation)-10+rand(20)); // PB: Near player reputation

	SetCargoLocked(rTrader, true);

	pchar.quest.generate_convoy_quest.convoymoney = iTradeMoney;

	pchar.quest.generate_convoy_quest.win_condition.l1 = "Timer";
	pchar.quest.generate_convoy_quest.win_condition.l1.date.day = GetAddingDataDay(0, 20, 0);
	pchar.quest.generate_convoy_quest.win_condition.l1.date.month = GetAddingDataMonth(0, 20, 0);
	pchar.quest.generate_convoy_quest.win_condition.l1.date.year = GetAddingDataYear(0, 20, 0);
	pchar.quest.generate_convoy_quest.win_condition = "generate_convoy_quest";
	pchar.quest.generate_convoy_quest_progress = "begin";

	pchar.quest.generate_convoy_quest_failed.win_condition.l1 = "NPC_Death";
	pchar.quest.generate_convoy_quest_failed.win_condition.l1.character = "Quest trader";
	pchar.quest.generate_convoy_quest_failed.win_condition = "generate_convoy_quest_failed";
}

// Levis: Fetch Quest New -->
void initCargos(int loopnum)
{
	for(int i=0;i<loopnum;i++)
	{
		UpdateAllCargos();
	}
}

string GenerateFetchCargo(ref ctown) //temp function until economy overhaul
{
	string cargoid = "";
	if(!CheckAttribute(ctown,"island")) return "";
	if(CheckAttribute(ctown,"store"))
	{
		ref Pchar = GetMainCharacter();
		aref storetype, tisland;
		makearef(tisland, Islands[FindIsland(ctown.island)]);
		string options[3];
		int option = 0;
		int storenum = GetAttributesNum(Stores[sti(ctown.store)]);
		for(int i=0;i<storenum;i++)
		{
			storetype = GetAttributeN(&Stores[ctown.store],i);
			switch(GetAttributeName(storetype))
			{
				case "dockyard":
					options[option]="dockyard"; option++;
					break;
				case "taylor":
					options[option]="tailor"; option++;
					break;
				case "blacksmith":
					if (ENABLE_WEAPONSMOD) {options[option]="blacksmith"; option++;} // PB: NOT if the relevant mod is OFF!
					break;
				case "gunsmith":
					if (ENABLE_WEAPONSMOD) {options[option]="gunsmith"; option++;} // PB: NOT if the relevant mod is OFF!
					break;
				case "apothecary":
					options[option]="apothecary"; option++;
					break;
			}
		}
		if (option==0) return "";
		string choose = options[rand((option-1))];
		//Check if there is a fetch quest for this store already
		cargoid = getFetchQuestCargo(choose,ctown);
		if(cargoid != "")
		{
			return "";
		}
		//Go on to check for the goods
		int goodoptions[5];
		option = 0;
		switch(choose)
		{
		case "dockyard":
			goodoptions[option] = GOOD_SANDAL; option++;
			goodoptions[option] = GOOD_LINEN; option++;
			if(sti(Pchar.rank)>15)
			{
				goodoptions[option] = GOOD_MAHOGANY; option++;
			}
			if(sti(Pchar.rank)>30)
			{
				goodoptions[option] = GOOD_EBONY; option++;
			}
		break;
		case "tailor":
			goodoptions[option]= GOOD_LEATHER; option++;
			goodoptions[option]= GOOD_COTTON; option++;
			if(sti(Pchar.rank)>12)
			{
				goodoptions[option]= GOOD_CLOTHES; option++;
			}
			if(sti(Pchar.rank)>35)
			{
				goodoptions[option]= GOOD_SILK; option++;
			}
		break;
		
		case "blacksmith":
			goodoptions[option]= GOOD_OIL; option++;
			if(sti(Pchar.rank)>20)
			{
				goodoptions[option]= GOOD_SILVER; option++;
			}
			if(sti(Pchar.rank)>40)
			{
				goodoptions[option]= GOOD_GOLD; option++;
			}
		break;
		
		case "gunsmith":
			if(ENABLE_AMMOMOD) goodoptions[option]= GOOD_GUNPOWDER; option++;
			goodoptions[option]= GOOD_SILVER; option++;
			if(sti(Pchar.rank)>25)
			{
				goodoptions[option]= GOOD_EBONY; option++;
			}
		break;
		
		case "apothecary":
			goodoptions[option]= GOOD_TREATMENT; option++;
		break;
		}
		int choosegood = goodoptions[rand((option-1))];
		int amount = makefloat( (1+rand(GetDifficulty()*sti(Pchar.rank))) * (60+rand(GetTownEconomy(ctown)*20)) ) / makefloat(Goods[choosegood].Weight); // PB: Corrected brackets and floating point operations
		if(DEBUG_FETCH_QUEST) trace("FETCH QUEST: made cargo for type: "+choose+" good: "+Goods[choosegood].name+" amount: "+amount);
		if(!CheckAttribute(tisland,"cargonum")) tisland.cargonum = 0;
		int cargonum = tisland.cargonum;
		cargoid = "cargo_"+cargonum;
		tisland.cargos.(cargoid).good = choosegood;
		tisland.cargos.(cargoid).amount = amount;
		tisland.cargos.(cargoid).town = ctown.id;
		tisland.cargos.(cargoid).requester = choose;
		tisland.cargonum = sti(tisland.cargonum)+1;
	}
	return cargoid;
}

void AnnounceFetchQuestEvent(String IslandID, string cargoid) //will be moved later
{
	if(cargoid != "")
	{
		aref tisland;
		makearef(tisland, Islands[FindIsland(IslandID)]);
		tisland.cargos.(cargoid).assigned = "fetchquest";
		int expiredays = rand(28);
		int expiremonths = rand(2)+1; //Changed from 3+2 to 2+1 to have them expire more quickly
		tisland.cargos.(cargoid).expireDay = GetAddingDataDay(0, expiremonths, expiredays);
		tisland.cargos.(cargoid).expireMonth = GetAddingDataMonth(0, expiremonths, expiredays);
		tisland.cargos.(cargoid).expireYear = GetAddingDataYear(0, expiremonths, expiredays);
		string logTitle, logEntry;
		Preprocessor_Add("requester", XI_ConvertString(tisland.cargos.(cargoid).requester));
		Preprocessor_Add("town", FindTownName(tisland.cargos.(cargoid).town));
		logTitle = PreprocessText(GetTranslatedLog("The #srequester# of #stown# needs help."));
		Preprocessor_Delete("town");
		Preprocessor_Delete("requester");
		switch(tisland.cargos.(cargoid).requester)
		{
			case "dockyard":
				logEntry = GetTranslatedLog("The governor ordered to build more ships but there aren't enough resources on the island to make them. Looks like they need help to get these goods.");
			break;
			case "tailor":
				logEntry = GetTranslatedLog("The governor wants to increase the amount of troops on the island and they will all need new uniforms. They need help to get the resources required.");
			break;
			case "blacksmith":
				logEntry = GetTranslatedLog("The military ordered new weapons as it is time to amortize their current stock. The blacksmith needs help to acquire the resources to make them.");
			break;
			
			case "gunsmith":
				logEntry = GetTranslatedLog("The gunsmith has gotten lots of new orders lately. Everyone wants a new sword or a firearm and he doesn't have the means to make them all.");
			break;
			
			// TALISMAN -->
			// added to fill blank page in Ship's Log
			case "apothecary":
				logEntry = GetTranslatedLog("There has been a serious outbreak of disease lately, and the Apothecary is running out of medicines to treat the sick. He needs help to get supplies.");
			break;
			// TALISMAN <--
		}
		//There is a chance the event isn't widly known so it won't get posted in the rumours
		if(rand(99)<FETCH_QUEST_POST_CHANCE)
		{
			if(DEBUG_FETCH_QUEST) trace("FETCH QUEST: the message is posted");
			WriteNewLogEntry(logTitle, logEntry, "General", false);
		}
	}
}

void UpdateAllCargos() //for now placed here. will be moved later
{
	bool fetch_expired;
	if(DEBUG_FETCH_QUEST) trace("FETCH QUEST: Update all cargos");
	for(int n=0; n<ISLANDS_QUANTITY; n++) 
	{
		ref tisland = GetIslandByIndex(n);
		if(IsIslandDisabled(tisland.id)) continue; // PB
		aref cargos, cargo;
		int fetchquest = 0;
		if(CheckAttribute(tisland,"cargos"))
		{
			makearef(cargos,tisland.cargos);
			int cargonum = GetAttributesNum(cargos);
			for(int i=0;i<cargonum;i++)
			{
				cargo = GetAttributeN(cargos,i);
				//Count amount of fetchquests
				if(CheckAttribute(cargo,"assigned"))
				{
					if(cargo.assigned == "fetchquest") fetchquest += 1;
				}
				//Check for expiration
//				if((GetDataYear() >= sti(cargo.expireYear)) && (GetDataMonth() >= sti(cargo.expireMonth)) && (GetDataDay() >= sti(cargo.expireDay)))
				fetch_expired = false;
				if(GetDataYear() > sti(cargo.expireYear)) fetch_expired = true;
				if(GetDataYear() == sti(cargo.expireYear))
				{
					if(GetDataMonth() > sti(cargo.expireMonth)) fetch_expired = true;
					if(GetDataMonth() == sti(cargo.expireMonth))
					{
						if(GetDataDay() >= sti(cargo.expireDay)) fetch_expired = true;
					}
				}
				if(fetch_expired)
				{
					if(DEBUG_FETCH_QUEST) trace("FETCH QUEST: "+cargoid+" on island "+tisland.name+" expired");
					string cargoid = GetAttributeName(cargo);
					removeCargoFromIsland(tisland, cargoid);
					cargonum --;
					i--;
				}
			}
		}
		//If there are less then 2 fetchquests on the island see if one is generated
		if(fetchquest < MAX_NUMBER_FETCH_QUEST)
		{
			if(rand(CHANCE_FETCH_QUEST)<1)
			{
				int townnum = rand(GetIslandTownsQuantity(tisland.id)-1)+1;
				if(townnum>0)
				{
					ref ttown = GetTownFromID(GetTownIDFromIsland(tisland.id, townnum));
					if(DEBUG_FETCH_QUEST) trace("FETCH QUEST: make fetch quest for "+tisland.name+" with "+townnum+" towns. Pick town "+ttown.name);
					cargoid = GenerateFetchCargo(ttown);
					AnnounceFetchQuestEvent(ttown.island, cargoid);
				}
			}
		}
	}
}

void removeCargoFromIsland(ref tisland, string cargoid) //will be moved later
{
	aref cargos;
	makearef(cargos,tisland.cargos);
	DeleteAttribute(cargos,cargoid);
	if(DEBUG_FETCH_QUEST) trace("FETCH QUEST: delete cargo "+cargoid+" for island "+tisland.name);
}

int getCargoAmount(ref tisland, string cargoID) //will be moved later
{
	return sti(tisland.cargos.(cargoID).amount);
}

int getCargoGood(ref tisland, string cargoID) //will be moved later
{
	return sti(tisland.cargos.(cargoID).good);
}

string getFetchQuestExpireDate(ref tisland, string cargoID)
{
	string date = GetHumanDate(sti(tisland.cargos.(cargoid).expireYear),sti(tisland.cargos.(cargoid).expireMonth),sti(tisland.cargos.(cargoid).expireDay));
	return date;
}

void setFetchQuestExpireQuest(ref tisland, string cargoID, string questbookname, string chrid)
{
	ref PChar = GetMainCharacter();
	//This function sets a quest to expire the fetchquest.
	PChar.quest.(questbookname).win_condition.l1 = "Timer";
	int year = sti(tisland.cargos.(cargoid).expireYear);
	int month = sti(tisland.cargos.(cargoid).expireMonth);
	int day = sti(tisland.cargos.(cargoid).expireDay);
	PChar.quest.(questbookname).chrid = chrid;
	if(DEBUG_FETCH_QUEST) trace("FETCH QUEST: set quest "+questbookname+" timer to (yyyy,mm,dd) "+year+","+month+","+day);
	PChar.quest.(questbookname).win_condition.l1.date.day = day;
	PChar.quest.(questbookname).win_condition.l1.date.month = month;
	PChar.quest.(questbookname).win_condition.l1.date.year = year;
	PChar.quest.(questbookname).win_condition = "Fetch Quest Expire";
}

string getFetchQuestCargo(string type, ref ctown)
{
	aref cargos, cargo;
	makearef(cargos,Islands[FindIsland(ctown.island)].cargos);
	int cargonum = GetAttributesNum(cargos);
	for(int i=0;i<cargonum;i++)
	{
		cargo = GetAttributeN(cargos,i);
		if(cargo.assigned == "fetchquest" && cargo.requester == type && cargo.town == ctown.id)
		{
			return GetAttributeName(cargo);
		}
	}
	return "";
}

string getAllFetchQuestCargo(int num, ref ctown)
{
	aref cargos, cargo;
	makearef(cargos,Islands[FindIsland(ctown.island)].cargos);
	int cargonum = GetAttributesNum(cargos);
	int count = 0;
	for(int i=0;i<cargonum;i++)
	{
		cargo = GetAttributeN(cargos,i);
		if(cargo.assigned == "fetchquest" && cargo.town == ctown.id)
		{
			if(num == count)
			{
				return GetAttributeName(cargo);
			}
			else
			{
				count --;
			}
		}
	}
	return "";
}

int getFetchQuestReward(int amount, int good, ref ctown)
{
	ref Pchar = GetMainCharacter();
	float baseprice = stf(Goods[good].Cost);
	float startmult = (1.0+((4.0-GetDifficulty())/10.0));
	float pricemult = startmult + (startmult * ((sti(Pchar.skill.Commerce)+((ctown.economy+3.0)*2.0))/(10.0+10.0))) + (rand(8.0-GetDifficulty())/20);
	int price = baseprice * pricemult * amount;
	return price;
}
// Levis: Fetch Quest New <--

void TavernWaitDate(string date)
{
	int iTime, iAddTime;
	iTime = sti(environment.time);
	if (date == "wait_day")
	{
		if (iTime >= 22) iAddTime = 24 - iTime + 10;
		if (iTime <= 10) iAddTime = 10 - iTime;
		//this is handled by nextday NK 05-04-17 StoreDayUpdate();
	}
	else
	{
		if (iTime < 22) iAddTime = 22 - iTime;
	}
	LAi_Fade("", "");
	WaitDate("",0,0,0,iAddTime,1);
	RecalculateJumpTable();
}

void TavernWaitDate2(string date)
{
	int iTime, iAddTime;
	iTime = sti(environment.time);
	if (date == "wait_day")
	{
		if (iTime >= 22) iAddTime = 24 - iTime + 10;
		if (iTime <= 10) iAddTime = 10 - iTime;
		//this is handled by nextday NK 05-04-17 StoreDayUpdate();
	}
	else
	{
		if (iTime < 22) iAddTime = 22 - iTime;
	}
	WaitDate("",0,0,0,iAddTime,1);
	RecalculateJumpTable();
}

void PlaceCharacter(aref ch, string group)
{
	float locx, locy, locz;
	string homelocator;
	ref mc = GetMainCharacter(); // KK
	GetCharacterPos(mc, &locx, &locy, &locz);
	homelocator = LAi_FindNearestFreeLocator(group, locx, locy, locz);
	ChangeCharacterAddressGroup(ch, mc.location, group, homelocator);
}


// LDH - Added 05Sep06 to generate a better selection of pirate captains
// updated 18Oct06 for correct animations, take character sex from model file
string RandomCaptain(int iNation) // KK
{
	if (iNation != PIRATE && CheckAttribute(Nations[iNation], "fantomModel.m0")) return Nations[iNation].fantomModel.m0; // KK

//	A note on adding characters to this function:
//	Place the name of the character you wish to test in the line below, uncomment the line in LAi_boarding.c that says:
//	Put the surrendered captain in your hold, then go to the hold and offer to make them an officer.
//  If anything doesn't work, don't put the new character in this function.
//	If the captain works, add it to the appropriate switch statement below.
//  Note that female captains will not sit in your hold, but stand instead. The greeting voice will be wrong as well.
//	Don't forget to comment the two lines out again when you're done.

//  Uncomment the line below to test new characters.  See instructions above.
//	return "test character here";
//	return "33_Piratess10";	// Example.

	string CaptainSex = "man";
	if (rand(19) == 0) CaptainSex = "woman";		// one in 20 chance of female captain, easter egg

	if (CaptainSex == "man")
	{
		switch(rand(19))
		{
			case 0:  return "33_Ronald";	 break;
			case 1:  return "BadV";			 break;
			case 2:  return "Black_corsair"; break;
			case 3:  return "Capitan";		 break;
			case 4:  return "Capnhook";		 break;
			case 5:  return "Corsair1";		 break;
			case 6:  return "Corsair1_2";	 break;
			case 7:  return "Corsair1_3";	 break;
			case 8:  return "Corsair1_4";	 break;
			case 9:  return "Corsair2";		 break;
			case 10: return "Corsair3";		 break;
			case 11: return "Corsair4";		 break;
			case 12: return "Corsair5";		 break;
			case 13: return "Pirat1";		 break;
			case 14: return "Pirat11";		 break;
			case 15: return "Pirat13";		 break;
			case 16: return "Searcher_navy"; break;
			case 17: return "Shkiper";		 break;
			case 18: return "9Jc";			 break;
			case 19: return "9Jd";			 break;
		}
		return "Corsair3";
	}
	else
	{
		switch(rand(7))
		{
			case 0:  return "33_Piratess10";	break;
			case 1:  return "9Td";			break;
			case 2:  return "9CATa";		break;
			case 3:  return "girlpatch";		break;
			case 4:  return "33_Affrica";		break;
			case 5:  return "Beatrice";		break;
			case 6:  return "Daniell1";		break;
			case 7:  return "gipsygirl";		break;
		}
		return "33_Piratess10";
	}
}

// LDH --> Added 05Sep06 to get rid of problems with uninitialized data
// Taken from Characters_init.c and StoryCharacters.c
void InitQuestCaptain(string QuestCharacter, int iNation, bool isEnemy)
{
	ref ch = CharacterFromID(QuestCharacter);
	int idx = sti(ch.index);

	int CharacterNation;
	if(isEnemy) CharacterNation = LotHostileNation(iNation);
	else		CharacterNation = iNation;

	DeleteAttribute(ch, "");

	ch.id			= QuestCharacter;
	ch.index		= idx;
	ch.old.name		= "Deadly";		// will be overwritten
	ch.old.lastname = "Pirate";
	ch.name			= TranslateString("","Deadly");		// will be overwritten
	ch.lastname		= TranslateString("","Pirate");

	ch.model	= RandomCaptain(CharacterNation);
	ch.model.entity = "NPCharacter";

	// LDH 18Oct06 fixes for characters with special animations
	// we are intentionally not using Character_PostInit()
	int mdlIndex = GetModelIndex(ch.model);
	if (mdlIndex < 0)		// just in case, especially if someone mistypes the name for a test
	{
		ch.model = "Corsair3";
		mdlIndex = GetModelIndex(ch.model);
	}
	ref mdl = &Models[mdlIndex];
	ch.model.animation = mdl.ani;
	ch.model.ani = mdl.ani;
	ch.sex = mdl.sex;
//	Facemaker(ch);		// unneeded, this is set elsewhere

	if (ch.sex == "man")
	{
// KK -->
		if (CharacterNation == PIRATE) {
			ch.sound_type = "pirate";
			ch.greeting = "Gr_Vincent Bethune";	// this gets overwritten when twin character is made
		} else {
			ch.sound_type = "soldier";
			ch.greeting = GetSoldiersGreeting(CharacterNation, "");
		}
// <-- KK
	}
	else
	{
		ch.sound_type = "female_citizen";
		ch.greeting = "Gr_Pirate_f";	// this gets overwritten when twin character is made
	}
	ch.nation = CharacterNation; // KK

	if (rand(4) < 3) {
		string pistol = "pistol" + (rand(5) + 1);
		if (ENABLE_WEAPONSMOD) pistol += stringRet(rand(1), "+", "-") + rand(2);	// LDH quality only if weaponsmod enabled - 26Dec08
		GiveItem2Character(ch, pistol);
		ch.equip.gun = pistol;
		//JRH ammo mod -->
		if (ENABLE_AMMOMOD) {	// LDH change
			TakenItems(ch, "gunpowder", 1 + rand(2));
			TakenItems(ch, "pistolbullets", 1 + rand(2));
		}
		//JRH ammo mod <--
  	}
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "none";
	ch.location.from_sea = "";
	ch.Ship.Type = SHIP_NOTUSED_TYPE_NAME;
	ch.Dialog.Filename = "Vincent Bethune_dialog.c";	// will be overwritten
	ch.Dialog.CurrentNode = "First time";
	ch.Dialog.TempNode = ch.Dialog.CurrentNode;
	ch.quest.meeting = "0";
	ch.quest = "True";

	ch.rank 	= rand(10); // KK
	if (CharacterNation == PIRATE)
		ch.reputation = "40";
	else
		ch.reputation = rand(88) + 1;
	ch.experience = "240000";
	ch.skill.freeskill = 0;
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "6";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "4";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "8";
	ch.money = "10";

	ch.AbordageMode = 1;

	LAi_SetGuardianType(ch);	// PB: Matches with Coast Raider initialization
//	LAi_SetMerchantType(ch);	// makes captain cower in hold if you threaten him with a sword
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
}
// LDH <--

// KK -->
void ProcessLateLoan(string town)
{
	ref Pchar = GetMainCharacter();
	int iUsurer = GetTownUsurerIndex(town);
	if (iUsurer < 0) return;
	ref rUsurer = GetCharacter(iUsurer);
	// a simple virtual sailor --->
	ChangeCharacterReputation(Pchar, -12); //was -20
	if (CheckAttribute(Pchar, "mad_usurer"))
		Pchar.mad_usurer = makeint(Pchar.mad_usurer) + 1;
	else
		PChar.mad_usurer = 1;
	rUsurer.is_mad = true; 
	// a simple virtual sailor <--
	rUsurer.Dialog.CurrentNode = "DeadMotherfucker";

	Group_CreateGroup("Usurer_Avenger");
	GenerateQuestShip("Usurer_Avenger01", rUsurer.nation); // PB: Use Generic Function
	Group_AddCharacter("Usurer_Avenger", "Usurer_Avenger01");
	Group_SetGroupCommander("Usurer_Avenger", "Usurer_Avenger01");

	GenerateQuestShip("Usurer_Avenger02", rUsurer.nation); // PB: Use Generic Function
	Group_addCharacter("Usurer_Avenger", "Usurer_Avenger02");

	GenerateQuestShip("Coastal_Captain03", rUsurer.nation); // PB: Use Generic Function
	Group_addCharacter("Usurer_Avenger", "Coastal_Captain03");

	Group_SetTaskAttack("Usurer_Avenger", PLAYER_GROUP, true);
	Group_LockTask("Usurer_Avenger");

	Encounter_SetQuestMapEncounter("Usurer_Avenger", ENCOUNTER_WAR, true, 50);
// KK todo: what if someone use only direct sail? Does quest map encounters really work?
}

void CommonQuestComplete(string sQuestName)
{
	ref PChar = GetMainCharacter();
	ref NPChar, OPchar, sld, port, period;
	int i, iOfficer;
	int iDonation, iRepRank, iRep, iMult, iCost;
	int cc, iColony, iTradeGoods, iQuantityGoods, iTradeNation, iPassenger;
	float locx, locy, locz;
	float x, y, z;// MAXIMUS
	float u, v, w;// JRH
	float GunCurCharge; // Levis
	string nearloc;// MAXIMUS
	string homelocation, homegroup, homelocator, tavernfriend, questbookname, attr;

// JRH -->
	string weaponID = GetCharacterEquipByGroup(Pchar,GUN_ITEM_TYPE);
	aref weapon, curTable, store;
	Items_FindItem(weaponID, &weapon);
// <-- JRH

// KK -->
	if (HasSubStr(sQuestName, "Loans_")) {
		sQuestName = strcut(sQuestName, 6, strlen(sQuestName) - 1);
		if (GetTownIndex(sQuestName) >= 0) ProcessLateLoan(sQuestName);
		return;
	}
// <-- KK

	switch (sQuestName) {

		// PB: How about we add this into the common file???
		// Was only in "standard" folder, so might cause trouble in other storylines
		case "player_back":
			Lai_SetPlayerType(pchar);
			Pchar.dialog.filename = "blaze_dialog.c"; // PB: To ensure this is reset after using a custom file for self dialog
		break;

		// Grey Roger: This is also taken from "standard"
		// Needed for "Strange Things Going On", also for one of the Thiefbuster traps
		case "God_hit_us":
			PlayStereoSound("NATURE\thunder3.wav");
			GetCharacterPos(GetMainCharacter(), &locx, &locy, &locz);
			CreateParticleSystemX("blast", locx, locy, locz, locx, locy, locz,0);
			LAi_ApplyCharacterDamage(pchar, 20);
		break;

		//Levis: Added for treasurequest
		case "Found Treasure":
			CloseQuestHeader("treasure");

			Group_DelCharacter("Treasure_Pirate", "Treasure Pirate");
			Group_deleteGroup("Treasure_Pirate");
		break;
		
		////////////////////////////////////////////////////////////////////////
		//  Fetch Quest
		////////////////////////////////////////////////////////////////////////
		
		case "Fetch Quest Expire":
			questbookname = pchar.quest.completed_win_condition; //Levis: get the quest which triggered this.
			if(DEBUG_FETCH_QUEST) trace("FETCH QUEST: triggered expire quest for "+questbookname);
			//Questbook
			AddQuestRecord(questbookname, 4);
			CloseQuestHeader(questbookname);
			//Clean Up
			NPChar = CharacterFromID(PChar.quest.(questbookname).chrid);
			DeleteAttribute(NPChar,"fetch_quest");
			DeleteAttribute(NPChar,"fetch_quest_active");
			if(!CheckAttribute(PChar,"fetchquestfailed")) PChar.fetchquestfailed = 0;
			PChar.fetchquestfailed = sti(PChar.fetchquestfailed) + 1;
			
		break;

		////////////////////////////////////////////////////////////////////////
		//  SMUGGLING
		////////////////////////////////////////////////////////////////////////

		case "Prepare Smuggling":
			//Keep track of how many times we did this
			if(!CheckAttribute(Pchar,"amount_smuggleruns")) Pchar.amount_smuggleruns = 0;
			Pchar.amount_smuggleruns = sti(Pchar.amount_smuggleruns) + 1;
			//Set the contraband stuff
			lockIslandContraband(Islands[GetCharacterCurrentIsland(Pchar)]); //Make sure the contraband wont change
			Pchar.quest.Contraband.islandindex = GetCharacterCurrentIsland(Pchar);
			Pchar.quest.Contraband.active = true;
			Pchar.quest.Contraband.scout = true;
			Pchar.quest.Contraband.tavern = pchar.location; //Added so we know where to spawn the officer when he returns.
			//Levis add smuggling questbook
			Preprocessor_AddQuestData("island",Islands[GetCharacterCurrentIsland(Pchar)].name);
			Preprocessor_AddQuestData("location",TranslateString("",locations[FindLocation(Pchar.quest.contraband.CurrentPlace)].name));
			//DeleteQuestHeader("smuggle&number=0"); //we dont have to delete anymore now
			questbookname = "smuggle&number="+Pchar.amount_smuggleruns; //Set a questname
			SetQuestHeader(questbookname);
			AddQuestRecord(questbookname, 1);
			Preprocessor_Remove("island");
			Preprocessor_Remove("location");
			//Give player the book the first time
			if(!CheckAttribute(Pchar,"quest.smuggling_got_book"))
			{
				Lai_QuestDelay("Smugglers First Meeting",0.0);
			}
			PChar.quest.Prepare_Smuggling_Fail.win_condition.l1 = "Timer";
			PChar.quest.Prepare_Smuggling_Fail.win_condition.l1.date.day = GetAddingDataDay(0,0,7);
			PChar.quest.Prepare_Smuggling_Fail.win_condition.l1.date.month = GetAddingDataMonth(0,0,7);
			PChar.quest.Prepare_Smuggling_Fail.win_condition.l1.date.year = GetAddingDataYear(0,0,7);
			PChar.quest.Prepare_Smuggling_Fail.win_condition = "Prepare Smuggling Fail";
		break;
		
		case "Prepare Smuggling Fail": // DeathDaisy: this happens if you fail to get back to the smuggler agent with the patrol times within a week
			ref ch = characterFromID(PChar.quest.Contraband.contact);
			ch.Dialog.CurrentNode = ch.Dialog.TempNode;
			questbookname = "smuggle&number="+Pchar.amount_smuggleruns;
			AddQuestRecord(questbookname, 16);
			CloseQuestHeader(questbookname);
			ChangeSmugglerLiking(Pchar, -2); //Add liking
			RemoveSmugglersFromShore();
		break;
		
		case "Cancel_Smuggling":
			questbookname = "smuggle&number="+Pchar.amount_smuggleruns;
			AddQuestRecord(questbookname, 15);
			CloseQuestHeader(questbookname);
			ChangeSmugglerLiking(Pchar, -2); //Add liking
			RemoveSmugglersFromShore();
		break;

		case "Send Officer to scout":
			//Levis add smuggling questbook
			Preprocessor_AddQuestData("location",TranslateString("",locations[FindLocation(Pchar.quest.contraband.CurrentPlace)].name));
			questbookname = "smuggle&number="+Pchar.amount_smuggleruns; //Set a questname
			AddQuestRecord(questbookname, 11);
			Preprocessor_Remove("location");
			Pchar.quest.Contraband.scout.done = true;
			//In 1 day he has to return
			NPChar = characterFromID(PChar.quest.Contraband.officerID);
			NPChar.StoredFellow = True;
			if(DEBUG_SMUGGLING>2)trace("SMUGGLING removed "+NPChar.id+" as officer");
			LAi_SetActorType(NPChar);
			LAi_ActorRunToLocation(NPChar, "reload", "reload1", "None", "", "", "Send Officer Gone", -1);
		break;

		case "Send Officer Gone":
			NPChar = characterFromID(PChar.quest.Contraband.officerID);
			RemovePassenger(PChar, NPChar);
			BLI_UpdateOfficers();
			if(DEBUG_SMUGGLING>2)trace("SMUGGLING removed "+NPChar.id+" from location");
			PChar.quest.Contraband_Scouting.win_condition.l1 = "Timer";
			PChar.quest.Contraband_Scouting.win_condition.l1.date.day = GetAddingDataDay(0, 0, 1);
			PChar.quest.Contraband_Scouting.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			PChar.quest.Contraband_Scouting.win_condition.l1.date.year = GetAddingDataYear(0, 0, 1);
			PChar.quest.Contraband_Scouting.win_condition = "Send Officer time expired";
			if(DEBUG_SMUGGLING>0)trace("SMUGGLING timer set 1 day later ");
		break;

		case "Send Officer time expired":
			if(DEBUG_SMUGGLING>0)trace("SMUGGLING time expired you should go to: "+Pchar.quest.Contraband.tavern);
			NPChar = characterFromID(PChar.quest.Contraband.officerID);
			PChar.quest.Contraband_Scouting2.win_condition.l1 = "location";
			PChar.quest.Contraband_Scouting2.win_condition.l1.location = Pchar.quest.Contraband.tavern;
			ref smugisland = GetIslandByIndex(sti(Pchar.quest.Contraband.islandindex));
			//First determine if the officer get caught.
			//int caughtchance = getSmugglingState(smugisland)*20 + (GetDifficulty()*5);
			// DeathDaisy: chance of getting caught and getting info is now dependent of NPC skill and perks
			int luck = CalcCharacterSkill(NPChar,SKILL_SNEAK);
			int fencing = CalcCharacterSkill(NPChar,SKILL_FENCING);
			int commerce = CalcCharacterSkill(NPChar,SKILL_COMMERCE);
			int caughtchance = makeint((pow(getSmugglingState(smugisland),1.5)*10) - (luck*3) - (fencing*2) - (commerce));
			if(CheckCharacterPerk(NPChar,"Trustworthy")) caughtchance = caughtchance*0.9;
			if(CheckCharacterPerk(NPChar,"ImproveSmuggling")) caughtchance = caughtchance*0.8;
			if(CheckCharacterPerk(NPChar,"AdvanceSmuggling")) caughtchance = caughtchance*0.5;
			
			if(DEBUG_SMUGGLING>2)trace("SMUGGLING caughtchance for officer is: "+caughtchance);
			if(rand(99) < caughtchance)
			{
				//Officer caught
				PChar.quest.Contraband_Scouting2.win_condition = "Send Officer doesnt return";
				if(DEBUG_SMUGGLING>2)trace("SMUGGLING officer is caught");
			}
			else
			{
				int GetInfoSuccess = luck;
				if(CheckCharacterPerk(NPChar,"Trustworthy")) GetInfoSuccess = GetInfoSuccess+1;
				if(CheckCharacterPerk(NPChar,"ImproveSmuggling")) GetInfoSuccess = GetInfoSuccess+1;
				if(CheckCharacterPerk(NPChar,"AdvanceSmuggling")) GetInfoSuccess = GetInfoSuccess+1;
				//Based on officer luck and perks
				if(rand(9)<GetInfoSuccess)
				{
					//Success
					PChar.quest.Contraband_Scouting2.win_condition = "Send Officer has time";
					if(DEBUG_SMUGGLING>2)trace("SMUGGLING officer success");
				}
				else
				{
					//Failed
					PChar.quest.Contraband_Scouting2.win_condition = "Send Officer failed";
					if(DEBUG_SMUGGLING>2)trace("SMUGGLING officer failed");
				}
			}
		break;

		case "Send Officer doesnt return":
			if(DEBUG_SMUGGLING>0) trace("SMUGGLING officer was caught so lets reset stuff");
			questbookname = "smuggle&number="+Pchar.amount_smuggleruns; //Set a questname
			AddQuestRecord(questbookname, 14);
			ChangeCharacterReputation(pchar, -5);
			NPChar = characterFromID(PChar.quest.Contraband.officerID);
			DeleteAttribute(NPChar,"StoredFellow");
			DeleteAttribute(Pchar,"quest.Contraband.scout.done");
			LAi_KillCharacter(NPChar);
		break;

		case "Send Officer failed":
			if(DEBUG_SMUGGLING>0) trace("SMUGGLING officer appears in tavern");
			NPChar = characterFromID(PChar.quest.Contraband.officerID);
			ChangeCharacterAddressGroup(NPChar, Pchar.quest.Contraband.tavern, "reload", "reload1");
			LAi_SetActorType(NPChar);
			NPChar.dialog.currentnode = "Patrolschedule_failed";
			LAi_ActorDialog(NPChar,Pchar,"",10.0,1.0); // PB: was "Send Officer back in slot"
			DeleteAttribute(Pchar,"quest.Contraband.scout.done");
		break;

		case "Send Officer has time":
			if(DEBUG_SMUGGLING>0) trace("SMUGGLING officer "+PChar.quest.Contraband.officerID+" appears in tavern");
			NPChar = characterFromID(PChar.quest.Contraband.officerID);
			ChangeCharacterAddressGroup(NPChar, Pchar.quest.Contraband.tavern, "reload", "reload1");
			LAi_SetActorType(NPChar);
			NPChar.dialog.currentnode = "Patrolschedule_got";
			LAi_ActorDialog(NPChar,Pchar,"",10.0,1.0); // PB: was "Send Officer back in slot"
			AddPartyExpChar(NPChar, SKILL_SNEAK, 500);
		break;

		case "Send Officer back in slot":
			if(DEBUG_SMUGGLING>0) trace("SMUGGLING officer becomes passenger again");
			NPChar = characterFromID(PChar.quest.Contraband.officerID);
			DeleteAttribute(NPChar,"StoredFellow");
			AddPassenger(PChar, NPChar, 0);
			LAi_SetOfficerType(NPChar);
			SetOfficersIndex(Pchar, -1, sti(NPChar.index)); // PB: Use index instead of reference
			NPChar.dialog.currentnode = "hired";            // PB: Reset his dialog
			BLI_UpdateOfficers();
		break;

		case "Made Deal with Smuggler":
			PlaceSmugglersOnShore(Pchar.quest.contraband.CurrentPlace);
			Preprocessor_AddQuestData("location",TranslateString("",locations[FindLocation(Pchar.quest.contraband.CurrentPlace)].name));
			questbookname = "smuggle&number="+Pchar.amount_smuggleruns;
			AddQuestRecord(questbookname, 10);
			Preprocessor_Remove("location");
			DeleteAttribute(Pchar,"quest.Contraband.scout");
			DeleteAttribute(Pchar,"quest.Contraband.Talked");
			DeleteAttribute(Pchar,"quest.Contraband.Cardwon");
			Pchar.quest.Pre_Process_CoastGuard.win_condition.l1 = "location";
			Pchar.quest.Pre_Process_CoastGuard.win_condition.l1.character = PChar.id;
			Pchar.quest.Pre_Process_CoastGuard.win_condition.l1.location = Pchar.quest.contraband.CurrentPlace;
			Pchar.quest.Pre_Process_CoastGuard.win_condition = "GenerateCoastGuard";
		break;

		case "GiveBookToCommander":
			if(pchar.location == Pchar.quest.contraband.CurrentPlace)
			{
				string idbook = CreatePatrolBook(Islands[GetCharacterCurrentIsland(Pchar)]);
				sld = getCharacter(sti(Pchar.quest.contraband.SoldierIDX1));
				if(!CheckCharacterItem(Pchar, idbook)) GiveItem2Character(sld, idbook); // PB: Prevent multiple instances of the same book
				MoveBackSmugglersOnShore(); //attempt to fix smugglers doing weird after the fight
				DeleteAttribute(pchar,"quest.smuggling.spotted");
			}
		break;

		case "GenerateCoastGuard":
			StartCoastGuardCheck();
		break;
		
		case "Remove Coast Guard":
			CoastGuardPatrolGoAway();
		break;
		
		case "Coast Guard Away":
			CoastGuardPatrolRemove();
		break;

		case "Rand_Smuggling": // this occurs if you fail to show up for the smuggling
			questbookname = "smuggle&number="+Pchar.amount_smuggleruns;
			AddQuestRecord(questbookname, 4);
			CloseQuestHeader(questbookname);
			ChangeSmugglerLiking(Pchar, -10); //Add liking
			RemoveSmugglersFromShore();
		break;

		case "Rand_SmugglingRemove":
			StopCoastGuardCheck();
			questbookname = "smuggle&number="+PChar.amount_smuggleruns;
			CloseQuestHeader(questbookname);

			ref rIsland = GetIslandByIndex(GetCharacterCurrentIsland(PChar));
			if(CheckAttribute(PChar,"quest.smuggling_guild.governor_smuggling") && CheckAttribute(rIsland, "id") && GetAttribute(PChar, "quest.smuggling_guild.governor_smuggling.island") == rIsland.id && GetAttribute(PChar, "quest.smuggling_guild.governor_smuggling") != "report_made" && GetAttribute(PChar, "quest.smuggling_guild.governor_smuggling") != "report_handed_in")
			{
				Lai_QuestDelay("Made First Smuggling Report",0.0);
			}
			ChangeCharacterAddressGroup(CharacterFromID("Rand_Smug01"), "None", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Rand_Smug02"), "None", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Rand_Smug03"), "None", "", "");
			RemoveGeometryFromLocation(PChar.Quest.SelectedSmugglingLocation, "smg");	// PB: Moved here
			DeleteAttribute(pchar,"quest.smuggling_guild.governor_quest.usedpaper");

			PChar.quest.delete_smugglingbook.win_condition.l1 = "Timer";			// Repeatedly smuggling leaves your questbook full of completed smuggling reports
			PChar.quest.delete_smugglingbook.win_condition.l1.date.day   = GetAddingDataDay  (0, 0, 2);
			PChar.quest.delete_smugglingbook.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 2);
			PChar.quest.delete_smugglingbook.win_condition.l1.date.year  = GetAddingDataYear (0, 0, 2);
			PChar.quest.delete_smugglingbook.win_condition = "delete_smugglingbook";
		break;

		case "delete_smugglingbook":
			questbookname = "smuggle&number="+PChar.amount_smuggleruns;
			DeleteQuestHeader(questbookname);
		break;

		case "Rand_ContrabandInterruption":
			CreateCoastGuardPatrol(); //Levis moved to seperate function
			questbookname = "smuggle&number="+Pchar.amount_smuggleruns;
			AddQuestRecord(questbookname, 6);
			//CloseQuestHeader(questbookname);
			if(Pchar.quest.contraband.fromsea == true) SetCoastalGuardPursuit();

			Lai_QuestDelay("Rand_CoastalPatrolAppear", 1.0);

			//Levis give the officer a patrolling schedule -->
			sld = getCharacter(sti(Pchar.quest.contraband.SoldierIDX1));
			Pchar.quest.CoastGuardKilled.win_condition.l1 = "NPC_Death";
			Pchar.quest.CoastGuardKilled.win_condition.l1.character = sld.id;
			Pchar.quest.CoastGuardKilled.win_condition = "GiveBookToCommander";
			//Levis give the officer a patrolling schedule <--
		/*	Pchar.quest.Rand_ContrabandInterruptionAtSea.win_condition.l1 = "location";
			Pchar.quest.Rand_ContrabandInterruptionAtSea.win_condition.l1.character = PChar.id;
			Pchar.quest.Rand_ContrabandInterruptionAtSea.win_condition.l1.location = Islands[GetCharacterCurrentIsland(pchar)].id;
			Pchar.quest.Rand_ContrabandInterruptionAtSea.win_condition = "Rand_ContrabandInterruptionAtSea";*/
		break;

		case "Rand_CoastalPatrolAppear":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], true);
			pchar.cleanlocidx = FindLocation(pchar.location);
			pchar.quest.smuggling.spotted = true;
			Pchar.quest.Rand_ContrabandInterruptionCleanup.win_condition.l1 = "ExitFromLocation";
			Pchar.quest.Rand_ContrabandInterruptionCleanup.win_condition.l1.location = pchar.location;
			Pchar.quest.Rand_ContrabandInterruptionCleanup.win_condition = "Rand_ContrabandInterruptionCleanup";
		break;

		case "Rand_ContrabandInterruptionCleanup":
			// if the player DID run away screaming like a little wuss, we do cleanup because the dialog never happened
			if ( CheckAttribute( &Locations[sti(pchar.cleanlocidx)],"noFight" ) ) {
				LAi_LocationFightDisable(&Locations[sti(pchar.cleanlocidx)], false);
			//	Pchar.quest.Rand_ContrabandInterruptionAtSeaEnded.win_condition.l1 = "MapEnter";
			//	Pchar.quest.Rand_ContrabandInterruptionAtSeaEnded.win_condition = "Rand_ContrabandInterruptionAtSeaEnded";
			}
			StopCoastGuardCheck();
			RemoveSmugglersFromShore();
			DeleteAttribute(pchar,"cleanlocidx");
			DeleteAttribute(pchar,"quest.smuggling.spotted");
		break;

		case "Rand_ContrabandInterruptionAtSeaEnded":
			StopCoastalGuardPursuit();
		break;

		////////////////////////////////////////////////////////////////////////
		//  OPIUM SMUGGLING
		////////////////////////////////////////////////////////////////////////

		case "Start Opium Smuggle Quest":
			//Keep track of how many times we did this
			if(!CheckAttribute(Pchar,"amount_smuggleruns_opium")) Pchar.amount_smuggleruns_opium = 0;
			Pchar.amount_smuggleruns_opium = sti(Pchar.amount_smuggleruns_opium) + 1;
			questbookname = "smuggle_opium&number="+Pchar.amount_smuggleruns_opium; //Set a questname
			//Add Questbook Data
			Preprocessor_AddQuestData("buyer", PChar.quest.opium_smuggling.lastbuyer.name);
			Preprocessor_AddQuestData("place", GetPrettyLocationName(pchar.location));
			Preprocessor_AddQuestData("amount", PChar.quest.opium_smuggling.lastbuyer.amount);
			SetQuestHeader(questbookname);
			AddQuestRecord(questbookname, 1);
			Preprocessor_Remove("buyer");
			Preprocessor_Remove("place");
			Preprocessor_Remove("amount");
			//Set attribute to keep track the quest is bussy
			PChar.quest.opium_smuggling.questgiven = true;
			//Set expiration timer
			PChar.quest.Opium_Smuggling_Expire.win_condition.l1 = "Timer";
			PChar.quest.Opium_Smuggling_Expire.win_condition.l1.date.day = GetAddingDataDay(0,2,0);       // TALISMAN corrected - timer was 2 days?!! not 2 months
			PChar.quest.Opium_Smuggling_Expire.win_condition.l1.date.month = GetAddingDataMonth(0,2,0);   // TALISMAN corrected - timer was 2 days?!! not 2 months
			PChar.quest.Opium_Smuggling_Expire.win_condition.l1.date.year = GetAddingDataYear(0,2,0);     // TALISMAN corrected - timer was 2 days?!! not 2 months
			PChar.quest.Opium_Smuggling_Expire.win_condition = "Opium Smuggle Expire";
		break;
		
		case "Opium Smuggle Got Opium":
			if(CheckAttribute(pchar,"quest.opium_smuggling.questgiven"))
			{
				questbookname = "smuggle_opium&number="+Pchar.amount_smuggleruns_opium;
				Preprocessor_AddQuestData("place", GetPrettyLocationName(pchar.location));
				AddQuestRecord(questbookname, 2);
				Preprocessor_Remove("place");
			}
		break;
		
		case "Complete Opium Smuggle Quest":
			questbookname = "smuggle_opium&number="+Pchar.amount_smuggleruns_opium;
			AddQuestRecord(questbookname, 3);
			CloseQuestHeader(questbookname);
			DeleteAttribute(pchar,"quest.opium_smuggling.questgiven");
			Lai_QuestDelay("Made Second Smuggling Report",0.0);
		break;
		
		case "Opium Smuggle Expire":
			if(CheckAttribute(pchar,"quest.opium_smuggling.questgiven"))
			{
				questbookname = "smuggle_opium&number="+Pchar.amount_smuggleruns_opium;
				AddQuestRecord(questbookname, 4);
				CloseQuestHeader(questbookname);
				ChangeSmugglerLiking(pchar,-13);
				DeleteAttribute(pchar,"quest.opium_smuggling.questgiven");
			}
		break;

		case "Opium_set_first_ambush":
			if(DEBUG_SMUGGLING>2)trace("OPIUM SMUGGLING disabled due to bugs");
/*
			if(DEBUG_SMUGGLING>2)trace("OPIUM SMUGGLING set first ambush");
			pchar.quest.opium_smugglingset.win_condition.l1 = "ExitFromLocation";
			pchar.quest.opium_smugglingset.win_condition.l1.location = pchar.location;
			pchar.quest.opium_smugglingset.win_condition = "Opium_Ambush";
			Lai_QuestDelay("Opium Smuggle Got Opium",0.0);
			Lai_QuestDelay("Smugglers Opium Discovery",1.0);
*/
		break;

		case "Opium_Ambush":
			//Clean up previous dialog
			if(CheckAttribute(pchar,"quest.opium_smuggling.guards.send"))
			{
				if(sti(pchar.quest.opium_smuggling.guards.send) > -1)
				{
					sld = getCharacter(sti(pchar.quest.opium_smuggling.guards.send));
					LAi_SetGuardianType(sld);
					sld.Dialog.CurrentNode = "First time";
				}
			}
			pchar.quest.opium_smuggling.guards.send = -1;
			//Time for the ambush
			if(CheckCharacterItem(pchar,"opium"))
			{
				//Only go if the character has opium
				int radius = 30;
				int closeidx = FindGuards(radius); //return -1 if there are no guards nearby; otherwise it returns the closes guard in the quest attributes
				String guardid = "Guard"+closeidx;
				if(closeidx > 0)
				{
					//If the closest guard is still too far away, they won't spot you and you'll be safe
					if(stf(pchar.quest.opium_smuggling.guards.(guardid).dist) < 25)
					{
						//There are type guard close by so they can ambush you
						int chance = getOpiumCaughtChance();
						if(DEBUG_SMUGGLING>2)trace("OPIUM SMUGGLING check if guard talks to you with chance: "+chance);
						if(rand(100)<chance)
						{
							sld = getCharacter(sti(pchar.quest.opium_smuggling.guards.(guardid).idx));
							if(DEBUG_SMUGGLING>2)trace("OPIUM SMUGGLING send guard: "+sld.id);
							LAi_SetActorType(sld);
							LAi_ActorDialog(sld, pchar, "", 120, 0);
							pchar.quest.opium_smuggling.guards.send = pchar.quest.opium_smuggling.guards.(guardid).idx;
							sld.Dialog.Filename.SmugglerGuard = "Smuggler_Guard.c";
							sld.Dialog.CurrentNode = "OpiumCaught";
						}
					}
				}
			}
			Lai_QuestDelay("Set_Next_Ambush",0);
		break;

		case "Set_Next_Ambush":
			if(CheckCharacterItem(pchar,"opium"))
			{
				if(DEBUG_SMUGGLING>2)trace("OPIUM SMUGGLING set new ambush");
				pchar.quest.opium_smugglingset.win_condition.l1 = "ExitFromLocation";
				pchar.quest.opium_smugglingset.win_condition.l1.location = pchar.location;
				pchar.quest.opium_smugglingset.win_condition = "Opium_Ambush";
			}
			else
			{
				if(DEBUG_SMUGGLING>2)trace("OPIUM SMUGGLING standby for next time");
				DeleteAttribute(pchar, "quest.Opium_set_first_ambush");
				DeleteAttribute(pchar, "quest.opium_smugglingset");
				pchar.quest.opium_smugglingset.win_condition.l1 = "item";
				pchar.quest.opium_smugglingset.win_condition.l1.character = pchar.id;
				pchar.quest.opium_smugglingset.win_condition.l1.item = "opium";
				pchar.quest.opium_smugglingset.win_condition = "Opium_Ambush";
			}
		break;

		case "Opium Fight":
			GuardsAttackOpium();
			if(!CheckAttribute(pchar,"quest.opium_smuggling.Encountered_Opium_Guard")) Lai_QuestDelay("First Encounter Opium Guard",0.0);
		break;

		case "Opium Don't Fight":
			//Clean up previous dialog
			if(CheckAttribute(pchar,"quest.opium_smuggling.guards.send"))
			{
				if(sti(pchar.quest.opium_smuggling.guards.send) > -1)
				{
					sld = getCharacter(sti(pchar.quest.opium_smuggling.guards.send));
					LAi_SetGuardianType(sld);
					sld.Dialog.CurrentNode = "First time";
				}
			}
			if(!CheckAttribute(pchar,"quest.opium_smuggling.Encountered_Opium_Guard")) Lai_QuestDelay("First Encounter Opium Guard",0.0);
		break;
		
		case "Opium Bribe":
			//Clean up previous dialog
			if(CheckAttribute(pchar,"quest.opium_smuggling.guards.send"))
			{
				if(sti(pchar.quest.opium_smuggling.guards.send) > -1)
				{
					sld = getCharacter(sti(pchar.quest.opium_smuggling.guards.send));
					LAi_SetGuardianType(sld);
					sld.Dialog.CurrentNode = "First time";
				}
			}
			if(!CheckAttribute(pchar,"quest.opium_smuggling.Encountered_Opium_Guard")) Lai_QuestDelay("First Encounter Opium Guard",0.0);
		break;
		
		case "remove_opium_effect":
			//TODO: Make use of Buff/Debuff system when made
			//TODO: Probably fails when used multiple times but don't know for sure. Need to check
			aref OpiumUse; makearef(OpiumUse,pchar.quest.opium_use.users);
			string used_id = GetAttributeName(GetAttributeN(OpiumUse,0));
			string iduser = pchar.quest.opium_use.users.(used_id).userid;
			ref User = CharacterFromID(iduser);
			float sickness = stf(User.quest.opium_use.opiumsickness);
			sickness = sickness - 0.2;
			if(sickness < 0.0) sickness = 0.0;
			User.quest.opium_use.opiumsickness = sickness;
			DeleteAttribute(OpiumUse,used_id);
		break;
		
		case "Remove Vegetal Effect":
			aref VegetalUse; makearef(VegetalUse,PChar.quest.vegetal_effect.users);
			string idcase = GetAttributeName(GetAttributeN(VegetalUse,0));
			sld = CharacterFromID(PChar.quest.vegetal_effect.users.(idcase).charid);
			RemoveVegetalEffect(sld);
			DeleteAttribute(VegetalUse,idcase);
		break;

////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////LAND ENCOUNTERS QUESTS///////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////


//------------------------------------------RAIDERS----------------------------------------------------
		case "LandEnc_RaidersLogin":
			LAi_group_SetRelation("ENC_RAIDERS_GROUP", LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);

			LAi_SetCheckMinHP(characterFromID("Enc_Char1"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char1")) - 1), false, "LandEnc_RaidersFight");
			LAi_SetCheckMinHP(characterFromID("Enc_Char2"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char2")) - 1), false, "LandEnc_RaidersFight");
			LAi_SetCheckMinHP(characterFromID("Enc_Char3"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char3")) - 1), false, "LandEnc_RaidersFight");
			LAi_SetCheckMinHP(characterFromID("Enc_Char4"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char4")) - 1), false, "LandEnc_RaidersFight");
		break;


		case "LandEnc_RaidersStart":

// LDH traces 03Apr09
//TraceAndLog("Raiders Start ************");

			// LDH - A character index of -1 can happen when they've logged in but you left the area before encountering them. - 03Apr09
			// They're still there when you go back, but no longer logged in.
			// I have no idea if this will fix the problem.
			if (GetCharacterIndex("Enc_Char1") != -1)
			{
				LAi_SetActorType(CharacterFromID("Enc_Char1"));
				LAi_SetActorType(CharacterFromID("Enc_Char2"));
				LAi_SetActorType(CharacterFromID("Enc_Char3"));
				LAi_SetActorType(CharacterFromID("Enc_Char4"));

				LAi_group_MoveCharacter(CharacterFromID("Enc_Char1"), "ENC_RAIDERS_GROUP");
				LAi_group_MoveCharacter(CharacterFromID("Enc_Char2"), "ENC_RAIDERS_GROUP");
				LAi_group_MoveCharacter(CharacterFromID("Enc_Char3"), "ENC_RAIDERS_GROUP");
				LAi_group_MoveCharacter(CharacterFromID("Enc_Char4"), "ENC_RAIDERS_GROUP");

				LAi_SetCheckMinHP(characterFromID("Enc_Char1"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char1")) - 1), false, "LandEnc_RaidersFight");
				LAi_SetCheckMinHP(characterFromID("Enc_Char2"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char2")) - 1), false, "LandEnc_RaidersFight");
				LAi_SetCheckMinHP(characterFromID("Enc_Char3"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char3")) - 1), false, "LandEnc_RaidersFight");
				LAi_SetCheckMinHP(characterFromID("Enc_Char4"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char4")) - 1), false, "LandEnc_RaidersFight");

				LAi_ActorDialog(CharacterFromID("Enc_Char1"), Pchar, "", 10, 0);
				LAi_ActorDialog(CharacterFromID("Enc_Char2"), Pchar, "", 10, 0);
				LAi_ActorDialog(CharacterFromID("Enc_Char3"), Pchar, "", 10, 0);
				LAi_ActorDialog(CharacterFromID("Enc_Char4"), Pchar, "", 10, 0);

				LAi_SetFightMode(PChar, false);
				LAi_LockFightMode(Pchar, true);
			}

			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest1")) pchar.quest.LandEnc_StartingQuest1.over = "yes";
			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest2")) pchar.quest.LandEnc_StartingQuest2.over = "yes";
			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest3")) pchar.quest.LandEnc_StartingQuest3.over = "yes";

		break;

		case "LandEnc_RaidersFight":
			LAi_LockFightMode(Pchar, false);

			LAi_RemoveCheckMinHP(characterFromID("Enc_Char1"));
			LAi_RemoveCheckMinHP(characterFromID("Enc_Char2"));
			LAi_RemoveCheckMinHP(characterFromID("Enc_Char3"));
			LAi_RemoveCheckMinHP(characterFromID("Enc_Char4"));

			LAi_type_actor_Reset(CharacterFromID("Enc_Char1"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char2"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char3"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char4"));

			LAi_SetWarriorTypeNoGroup(CharacterFromID("Enc_Char1"));
			LAi_SetWarriorTypeNoGroup(CharacterFromID("Enc_Char2"));
			LAi_SetWarriorTypeNoGroup(CharacterFromID("Enc_Char3"));
			LAi_SetWarriorTypeNoGroup(CharacterFromID("Enc_Char4"));

			LAi_group_MoveCharacter(CharacterFromID("Enc_Char1"), "ENC_RAIDERS_GROUP");
			LAi_group_MoveCharacter(CharacterFromID("Enc_Char2"), "ENC_RAIDERS_GROUP");
			LAi_group_MoveCharacter(CharacterFromID("Enc_Char3"), "ENC_RAIDERS_GROUP");
			LAi_group_MoveCharacter(CharacterFromID("Enc_Char4"), "ENC_RAIDERS_GROUP");

			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest1")) pchar.quest.LandEnc_StartingQuest1.over = "yes";
			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest2")) pchar.quest.LandEnc_StartingQuest2.over = "yes";
			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest3")) pchar.quest.LandEnc_StartingQuest3.over = "yes";

			LAi_group_FightGroups("ENC_RAIDERS_GROUP", LAI_GROUP_PLAYER, false);
		break;

		case "LandEnc_RaidersRunAway":
			LAi_LockFightMode(Pchar, false);

			LAi_type_actor_Reset(CharacterFromID("Enc_Char1"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char2"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char3"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char4"));

			LAi_ActorAfraid(CharacterFromID("Enc_Char1"), Pchar, true);
			LAi_ActorAfraid(CharacterFromID("Enc_Char2"), Pchar, true);
			LAi_ActorAfraid(CharacterFromID("Enc_Char3"), Pchar, true);
			LAi_ActorAfraid(CharacterFromID("Enc_Char4"), Pchar, true);

			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest1")) pchar.quest.LandEnc_StartingQuest1.over = "yes";
			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest2")) pchar.quest.LandEnc_StartingQuest2.over = "yes";
			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest3")) pchar.quest.LandEnc_StartingQuest3.over = "yes";

			Characters[GetCharacterIndex("Enc_Char1")].Dialog.CurrentNode = "GetTheHellOut";
			Characters[GetCharacterIndex("Enc_Char2")].Dialog.CurrentNode = "GetTheHellOut";
			Characters[GetCharacterIndex("Enc_Char3")].Dialog.CurrentNode = "GetTheHellOut";
			Characters[GetCharacterIndex("Enc_Char4")].Dialog.CurrentNode = "GetTheHellOut";
		break;

		case "LandEnc_RaidersNoFight":
			LAi_LockFightMode(Pchar, false);

			LAi_type_actor_Reset(CharacterFromID("Enc_Char1"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char2"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char3"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char4"));

			LAi_SetWarriorTypeNoGroup(CharacterFromID("Enc_Char1"));
			LAi_SetWarriorTypeNoGroup(CharacterFromID("Enc_Char2"));
			LAi_SetWarriorTypeNoGroup(CharacterFromID("Enc_Char3"));
			LAi_SetWarriorTypeNoGroup(CharacterFromID("Enc_Char4"));

			LAi_warrior_DialogEnable(CharacterFromID("Enc_Char1"), true);
			LAi_warrior_DialogEnable(CharacterFromID("Enc_Char2"), true);
			LAi_warrior_DialogEnable(CharacterFromID("Enc_Char3"), true);
			LAi_warrior_DialogEnable(CharacterFromID("Enc_Char4"), true);

			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest1")) pchar.quest.LandEnc_StartingQuest1.over = "yes";
			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest2")) pchar.quest.LandEnc_StartingQuest2.over = "yes";
			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest3")) pchar.quest.LandEnc_StartingQuest3.over = "yes";

			Characters[GetCharacterIndex("Enc_Char1")].Dialog.CurrentNode = "GetLost";
			Characters[GetCharacterIndex("Enc_Char2")].Dialog.CurrentNode = "GetLost";
			Characters[GetCharacterIndex("Enc_Char3")].Dialog.CurrentNode = "GetLost";
			Characters[GetCharacterIndex("Enc_Char4")].Dialog.CurrentNode = "GetLost";
		break;

		case "LandEnc_RaidersRobbed":
			LAi_LockFightMode(Pchar, false);

			LAi_type_actor_Reset(CharacterFromID("Enc_Char1"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char2"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char3"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char4"));

			LAi_SetWarriorTypeNoGroup(CharacterFromID("Enc_Char1"));
			LAi_SetWarriorTypeNoGroup(CharacterFromID("Enc_Char2"));
			LAi_SetWarriorTypeNoGroup(CharacterFromID("Enc_Char3"));
			LAi_SetWarriorTypeNoGroup(CharacterFromID("Enc_Char4"));

			LAi_warrior_DialogEnable(CharacterFromID("Enc_Char1"), true);
			LAi_warrior_DialogEnable(CharacterFromID("Enc_Char2"), true);
			LAi_warrior_DialogEnable(CharacterFromID("Enc_Char3"), true);
			LAi_warrior_DialogEnable(CharacterFromID("Enc_Char4"), true);

			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest1")) pchar.quest.LandEnc_StartingQuest1.over = "yes";
			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest2")) pchar.quest.LandEnc_StartingQuest2.over = "yes";
			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest3")) pchar.quest.LandEnc_StartingQuest3.over = "yes";

			Characters[GetCharacterIndex("Enc_Char1")].Dialog.CurrentNode = "OnceAgain";
			Characters[GetCharacterIndex("Enc_Char2")].Dialog.CurrentNode = "OnceAgain";
			Characters[GetCharacterIndex("Enc_Char3")].Dialog.CurrentNode = "OnceAgain";
			Characters[GetCharacterIndex("Enc_Char4")].Dialog.CurrentNode = "OnceAgain";
		break;


//------------------------------------------RAPERS----------------------------------------------------

// Viper - Rapers MOD Start
		case "LandEnc_RapersLogin":

			Characters[GetCharacterIndex("Enc_Char2")].nodisarm = 1; // PB: Disable disarming
			Characters[GetCharacterIndex("Enc_Char3")].nodisarm = 1; // PB: Disable disarming
			Characters[GetCharacterIndex("Enc_Char4")].nodisarm = 1; // PB: Disable disarming

			LAi_group_SetRelation("ENC_RAPERS_GROUP", LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);

			LAi_SetCheckMinHP(characterFromID("Enc_Char2"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char2")) - 1), false, "LandEnc_RapersFight");
			LAi_SetCheckMinHP(characterFromID("Enc_Char3"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char3")) - 1), false, "LandEnc_RapersFight");
			LAi_SetCheckMinHP(characterFromID("Enc_Char4"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char4")) - 1), false, "LandEnc_RapersFight");

			LAi_QuestDelay("LandEnc_RapersPursue", 1); // NK was 5
		break;

		case "LandEnc_RapersPursue":
			LAi_SetActorType(CharacterFromID("Enc_Char1"));
			LAi_SetActorType(CharacterFromID("Enc_Char2"));
			LAi_SetActorType(CharacterFromID("Enc_Char3"));
			LAi_SetActorType(CharacterFromID("Enc_Char4"));

// GR: improved rapist scenario, woman is now armed
			GiveItem2Character(CharacterFromID("Enc_Char1"), "Barmansknife");
			EquipCharacterByItem(CharacterFromID("Enc_Char1"), "Barmansknife");
			Characters[GetCharacterIndex("Enc_Char1")].nodisarm = 1; // PB: Disable disarming
			LAi_SetImmortal(CharacterFromID("Enc_Char1"), true);

			//При первом подходе или истечении времени сработает квест
			LAi_ActorAfraid(CharacterFromID("Enc_Char1"), CharacterFromID("Enc_Char2"), true);
			LAi_ActorFollow(CharacterFromID("Enc_Char2"), CharacterFromID("Enc_Char1"), "", 240);
			LAi_ActorFollow(CharacterFromID("Enc_Char3"), CharacterFromID("Enc_Char1"), "", 240);
			LAi_ActorFollow(CharacterFromID("Enc_Char4"), CharacterFromID("Enc_Char1"), "", 240);

			LAi_ActorDialog(CharacterFromID("Enc_Char1"), Pchar, "", 45, 0);

			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest1")) pchar.quest.LandEnc_StartingQuest1.over = "yes";
			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest2")) pchar.quest.LandEnc_StartingQuest2.over = "yes";
			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest3")) pchar.quest.LandEnc_StartingQuest3.over = "yes";
		break;
// Viper - Rapers MOD End

		case "LandEnc_RapersTalk":
			LAi_SetActorType(CharacterFromID("Enc_Char2"));
			LAi_SetActorType(CharacterFromID("Enc_Char3"));
			LAi_SetActorType(CharacterFromID("Enc_Char4"));

			if (CalcCharacterSkill(PChar, SKILL_FENCING) >= 3)
			{
				LAi_ActorAfraid(CharacterFromID("Enc_Char1"), CharacterFromID("Enc_Char2"), true);
			}
			else
			{
				LAi_SetActorType(CharacterFromID("Enc_Char1"));
				LAi_ActorFollow(CharacterFromID("Enc_Char1"), PChar, "", 30.0);
			}

			LAi_SetCheckMinHP(characterFromID("Enc_Char2"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char2")) - 1), false, "LandEnc_RapersFight");
			LAi_SetCheckMinHP(characterFromID("Enc_Char3"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char3")) - 1), false, "LandEnc_RapersFight");
			LAi_SetCheckMinHP(characterFromID("Enc_Char4"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char4")) - 1), false, "LandEnc_RapersFight");

			LAi_ActorDialog(CharacterFromID("Enc_Char2"), Pchar, "", 1, 0);
			LAi_ActorDialog(CharacterFromID("Enc_Char3"), Pchar, "", 1, 0);
			LAi_ActorDialog(CharacterFromID("Enc_Char4"), Pchar, "", 1, 0);
		break;

		case "LandEnc_RapersFight":
			LAi_RemoveCheckMinHP(characterFromID("Enc_Char2"));
			LAi_RemoveCheckMinHP(characterFromID("Enc_Char3"));
			LAi_RemoveCheckMinHP(characterFromID("Enc_Char4"));

			LAi_SetWarriorType(CharacterFromID("Enc_Char2"));
			LAi_SetWarriorType(CharacterFromID("Enc_Char3"));
			LAi_SetWarriorType(CharacterFromID("Enc_Char4"));
			LAi_group_MoveCharacter(CharacterFromID("Enc_Char1"), LAI_DEFAULT_GROUP);
			LAi_group_MoveCharacter(CharacterFromID("Enc_Char2"), "ENC_RAPERS_GROUP");
			LAi_group_MoveCharacter(CharacterFromID("Enc_Char3"), "ENC_RAPERS_GROUP");
			LAi_group_MoveCharacter(CharacterFromID("Enc_Char4"), "ENC_RAPERS_GROUP");

			Pchar.quest.LandEnc_KillAllRapers.win_condition.l1 = "NPC_Death";
			Pchar.quest.LandEnc_KillAllRapers.win_condition.l1.character = "Enc_Char2";
			Pchar.quest.LandEnc_KillAllRapers.win_condition.l2 = "NPC_Death";
			Pchar.quest.LandEnc_KillAllRapers.win_condition.l2.character = "Enc_Char3";
			Pchar.quest.LandEnc_KillAllRapers.win_condition.l3 = "NPC_Death";
			Pchar.quest.LandEnc_KillAllRapers.win_condition.l3.character = "Enc_Char4";
			PChar.quest.LandEnc_KillAllRapers.win_condition = "LandEnc_KillAllRapers";

			if (CalcCharacterSkill(PChar, SKILL_FENCING) >= 3)
			{
				LAi_ActorAfraid(CharacterFromID("Enc_Char1"), CharacterFromID("Enc_Char2"), true);
			}
			else
			{
				LAi_SetWarriorType(CharacterFromID("Enc_Char1"));
				LAi_SetActorTypeNoGroup(CharacterFromID("Enc_Char1"));
				LAi_SetActorTypeNoGroup(CharacterFromID("Enc_Char2"));
				LAi_ActorAttack(CharacterFromID("Enc_Char1"), CharacterFromID("Enc_Char2"), "");	// Force one enemy to attack woman
				LAi_ActorAttack(characterfromID("Enc_Char2"), CharacterFromID("Enc_Char1"), "");
			}

			LAi_group_FightGroups("ENC_RAPERS_GROUP", LAI_GROUP_PLAYER, false);
		break;

		case "LandEnc_KillAllRapers":
			//Pchar.reputation = makeint(Pchar.reputation) + 5;
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", makeint(Pchar.rank)*100); }
			else { AddPartyExp(pchar, makeint(Pchar.rank)*100); }
			LAi_SetActorType(CharacterFromID("Enc_Char1"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char1"));
			Characters[GetCharacterIndex("Enc_Char1")].Dialog.CurrentNode = "ThanksForHelp";
			LAi_ActorDialog(CharacterFromID("Enc_Char1"), Pchar, "", 15, 0);

			LAi_Group_MoveCharacter(CharacterFromID("Enc_Char1"), LAI_GROUP_PLAYER);
			for (i=1; i<OFFICER_MAX; i++)
			{
				if(GetOfficersIndex(Pchar, i) != -1)
				{
					LAi_SetActorType(characters[GetOfficersIndex(Pchar, i)]);
					LAi_type_actor_Reset(characters[GetOfficersIndex(Pchar, i)]);
					LAi_SetOfficerType(characters[GetOfficersIndex(Pchar, i)]));
				}
			}
		break;

		case "LandEnc_Char1_Leaves":	// Triggered by dialog with "Enc_Char1", i.e. the woman
			LAi_SetActorType(CharacterFromID("Enc_Char1"));
			LAi_ActorGoToLocation(CharacterFromID("Enc_Char1"), "reload", LocatorExitSence(PChar.location, "from", "reload"), "none", "", "", "", -1);
		break;


//-----------------------------------------Defector---------------------------------------------------

// Grey Roger - Defector MOD Start
		case "LandEnc_DefectorLogin":

			Characters[GetCharacterIndex("Enc_Char2")].nodisarm = 1; // PB: Disable disarming
			Characters[GetCharacterIndex("Enc_Char3")].nodisarm = 1; // PB: Disable disarming
			Characters[GetCharacterIndex("Enc_Char4")].nodisarm = 1; // PB: Disable disarming

			LAi_group_SetRelation("ENC_DEFECTORS_GROUP", LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);

			LAi_SetCheckMinHP(characterFromID("Enc_Char2"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char2")) - 1), false, "LandEnc_Defector_PursuersFight");
			LAi_SetCheckMinHP(characterFromID("Enc_Char3"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char3")) - 1), false, "LandEnc_Defector_PursuersFight");
			LAi_SetCheckMinHP(characterFromID("Enc_Char4"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char4")) - 1), false, "LandEnc_Defector_PursuersFight");

			LAi_QuestDelay("LandEnc_DefectorPursuit", 1); // NK was 5
		break;

		case "LandEnc_DefectorPursuit":
			LAi_SetActorType(CharacterFromID("Enc_Char1"));
			LAi_SetActorType(CharacterFromID("Enc_Char2"));
			LAi_SetActorType(CharacterFromID("Enc_Char3"));
			LAi_SetActorType(CharacterFromID("Enc_Char4"));

			//При первом подходе или истечении времени сработает квест
			LAi_ActorAfraid(CharacterFromID("Enc_Char1"), CharacterFromID("Enc_Char2"), true);
			LAi_ActorFollow(CharacterFromID("Enc_Char2"), CharacterFromID("Enc_Char1"), "", 240);
			LAi_ActorFollow(CharacterFromID("Enc_Char3"), CharacterFromID("Enc_Char1"), "", 240);
			LAi_ActorFollow(CharacterFromID("Enc_Char4"), CharacterFromID("Enc_Char1"), "", 240);

			LAi_ActorDialog(CharacterFromID("Enc_Char1"), Pchar, "", 45, 0);

			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest1")) pchar.quest.LandEnc_StartingQuest1.over = "yes";
			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest2")) pchar.quest.LandEnc_StartingQuest2.over = "yes";
			if(CheckAttribute(Pchar, "quest.LandEnc_StartingQuest3")) pchar.quest.LandEnc_StartingQuest3.over = "yes";
		break;

		case "LandEnc_Defector_PursuersTalk":
			LAi_SetActorType(CharacterFromID("Enc_Char2"));
			LAi_SetActorType(CharacterFromID("Enc_Char3"));
			LAi_SetActorType(CharacterFromID("Enc_Char4"));

//			LAi_ActorAfraid(CharacterFromID("Enc_Char1"), CharacterFromID("Enc_Char2"), true);
//			LAi_SetOfficerType(CharacterFromID("Enc_Char1"));
			LAi_SetActorType(CharacterFromID("Enc_Char1"));
			LAi_ActorFollow(CharacterFromID("Enc_Char1"), PChar, "", 30.0);

			LAi_SetCheckMinHP(characterFromID("Enc_Char2"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char2")) - 1), false, "LandEnc_Defector_PursuersFight");
			LAi_SetCheckMinHP(characterFromID("Enc_Char3"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char3")) - 1), false, "LandEnc_Defector_PursuersFight");
			LAi_SetCheckMinHP(characterFromID("Enc_Char4"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char4")) - 1), false, "LandEnc_Defector_PursuersFight");

			LAi_ActorDialog(CharacterFromID("Enc_Char2"), Pchar, "", 1, 0);
			LAi_ActorDialog(CharacterFromID("Enc_Char3"), Pchar, "", 1, 0);
			LAi_ActorDialog(CharacterFromID("Enc_Char4"), Pchar, "", 1, 0);
		break;

		case "LandEnc_Defector_PursuersFight":
			Characters[GetCharacterIndex("Enc_Char2")].fight_started = "true";
			LAi_RemoveCheckMinHP(characterFromID("Enc_Char2"));
			LAi_RemoveCheckMinHP(characterFromID("Enc_Char3"));
			LAi_RemoveCheckMinHP(characterFromID("Enc_Char4"));

			LAi_SetWarriorType(CharacterFromID("Enc_Char2"));
			LAi_SetWarriorType(CharacterFromID("Enc_Char3"));
			LAi_SetWarriorType(CharacterFromID("Enc_Char4"));

			LAi_group_MoveCharacter(CharacterFromID("Enc_Char2"), "ENC_DEFECTORS_GROUP");
			LAi_group_MoveCharacter(CharacterFromID("Enc_Char3"), "ENC_DEFECTORS_GROUP");
			LAi_group_MoveCharacter(CharacterFromID("Enc_Char4"), "ENC_DEFECTORS_GROUP");

			Pchar.quest.LandEnc_Defector_KillAllPursuers.win_condition.l1 = "NPC_Death";
			Pchar.quest.LandEnc_Defector_KillAllPursuers.win_condition.l1.character = "Enc_Char2";
			Pchar.quest.LandEnc_Defector_KillAllPursuers.win_condition.l2 = "NPC_Death";
			Pchar.quest.LandEnc_Defector_KillAllPursuers.win_condition.l2.character = "Enc_Char3";
			Pchar.quest.LandEnc_Defector_KillAllPursuers.win_condition.l3 = "NPC_Death";
			Pchar.quest.LandEnc_Defector_KillAllPursuers.win_condition.l3.character = "Enc_Char4";
			PChar.quest.LandEnc_Defector_KillAllPursuers.win_condition = "LandEnc_Defector_KillAllPursuers";

			LAi_ActorAfraid(CharacterFromID("Enc_Char1"), CharacterFromID("Enc_Char2"), true);
			LAi_group_FightGroups("ENC_DEFECTORS_GROUP", LAI_GROUP_PLAYER, false);
		break;

		case "LandEnc_Defector_NoFight":
			Characters[GetCharacterIndex("Enc_Char2")].exit_locator = LocatorExitSence(PChar.location, "from", "reload");
			LAi_SetActorType(CharacterFromID("Enc_Char1"));
			LAi_ActorRunToLocation(CharacterFromID("Enc_Char1"), "reload", Characters[GetCharacterIndex("Enc_Char2")].exit_locator, "none", "", "", "LandEnc_Defector_Escaped", -1);
			LAi_SetActorTypeNoGroup(CharacterFromID("Enc_Char2"));
			LAi_SetActorTypeNoGroup(CharacterFromID("Enc_Char3"));
			LAi_SetActorTypeNoGroup(CharacterFromID("Enc_Char4"));

			LAi_group_MoveCharacter(CharacterFromID("Enc_Char2"), "ENC_DEFECTORS_GROUP");
			LAi_group_MoveCharacter(CharacterFromID("Enc_Char3"), "ENC_DEFECTORS_GROUP");
			LAi_group_MoveCharacter(CharacterFromID("Enc_Char4"), "ENC_DEFECTORS_GROUP");

			LAi_ActorAttack(characterfromID("Enc_Char2"), CharacterFromID("Enc_Char1"), "");
			LAi_ActorAttack(characterfromID("Enc_Char3"), CharacterFromID("Enc_Char1"), "");
			LAi_ActorAttack(characterfromID("Enc_Char4"), CharacterFromID("Enc_Char1"), "");

			LAi_group_SetRelation("ENC_DEFECTORS_GROUP", LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);
			LAi_SetCheckMinHP(characterFromID("Enc_Char2"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char2")) - 1), false, "LandEnc_Defector_PursuersFight");
			LAi_SetCheckMinHP(characterFromID("Enc_Char3"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char3")) - 1), false, "LandEnc_Defector_PursuersFight");
			LAi_SetCheckMinHP(characterFromID("Enc_Char4"), (LAi_GetCharacterHP(CharacterFromID("Enc_Char4")) - 1), false, "LandEnc_Defector_PursuersFight");

		break;

		case "LandEnc_Defector_KillAllPursuers":
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", makeint(Pchar.rank)*100); }
			else { AddPartyExp(pchar, makeint(Pchar.rank)*100); }
			if (!CheckAttribute(CharacterFromID("Enc_Char1"), "escaped_from_attackers"))
			{
				LAi_SetActorType(CharacterFromID("Enc_Char1"));
				LAi_type_actor_Reset(CharacterFromID("Enc_Char1"));
				Characters[GetCharacterIndex("Enc_Char1")].Dialog.CurrentNode = "ThanksForHelp";
				LAi_ActorDialog(CharacterFromID("Enc_Char1"), Pchar, "", 15, 0);
			}
		break;

		case "LandEnc_Defector_Escaped":
			Characters[GetCharacterIndex("Enc_Char1")].escaped_from_attackers = "true";
			if (!CheckAttribute(CharacterFromID("Enc_Char2"), "fight_started"))
			{
				for(i = 2; i <= 4; i++)
				{
					sld = CharacterFromID("Enc_Char" + i);
					if (!LAi_IsDead(sld))
					LAi_SetActorType(sld);
					LAi_ActorRunToLocation(sld, "reload", Characters[GetCharacterIndex("Enc_Char2")].exit_locator, "none", "", "", "", -1);
				}
			}
		break;

//-----------------------------------------Lady in bedroom---------------------------------------------

		case "LandEnc_ladykiller":	// Grey Roger: you just killed the lady in the bedroom of a mansion, now face the consequences
			if(CheckAttribute(PChar, "quest.bedroomlady") && sti(GetCharacterIndex(PChar.quest.bedroomlady)) != -1)
			{			// Check that she still exists - fix for bug whereby you're penalised for killing her because she disappeared
				ChangeCharacterReputation(PChar, -10);
				PChar.quest.ladykiller_countdown = 5;
				PChar.quest.LandEnc_ladykiller_revenge.win_condition.l1 = "ExitFromLocation";
				PChar.quest.LandEnc_ladykiller_revenge.win_condition.l1.location = PChar.location;
				PChar.quest.LandEnc_ladykiller_revenge.win_condition = "LandEnc_ladykiller_revenge";
			}
		break;

		case "LandEnc_ladykiller_revenge":
			LAi_CreateFantomGroup("Rich_Citizens", 4, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND, ALL_NATIONS, "", 2, true, "", "", "Avengers", "reload1");
		break;

		case "LandEnc_cancel_ladykiller":
			PChar.quest.LandEnc_ladykiller.over = "yes";
		break;

//------------------------------------------OFFICER----------------------------------------------------

		case "LandEnc Talk to player about hireing":
			NPChar = characterFromID(PChar.quest.hire_enc_walker);
			LAi_SetActorType(NPChar);
			LAi_ActorDialogNow(NPChar,Pchar,"Return LandEnc to citizentype",-1);
		break;
		
		case "Return LandEnc to citizentype":
			NPChar = characterFromID(PChar.quest.hire_enc_walker);
			DeleteAttribute(PChar,"quest.hire_enc_walker");
			Lai_SetCitizenType(NPChar);
		break;

		case "LandEnc_OfficerHired":
		// This action is still used by the following applications:
		// 		Enc_fort_dialog.c
		// 		Enc_Officer_dialog.c
		// This is NO LONGER used by the following:
		// 		Cabinfight_dialog.c
		// 		Prisoned_dialog.c

			int freeidx = FindFreeRandomOfficer(); // NK do once
			if(freeidx != -1)
			{
				Pchar.quest.FreeRandomOfficerIdx = Characters[freeidx].index;
				Pchar.quest.FreeRandomOfficerID = Characters[makeint(Pchar.quest.FreeRandomOfficerIdx)].id;

				trace("Free Random Officer IDX is " + Pchar.quest.FreeRandomOfficerIdx + " and he has id  " + Pchar.quest.FreeRandomOfficerID);

				CopyAttributes(&Characters[makeint(Pchar.quest.FreeRandomOfficerIdx)], &Characters[makeint(Pchar.quest.HiringOfficerIDX)]);

				Characters[makeint(Pchar.quest.FreeRandomOfficerIdx)].index = Pchar.quest.FreeRandomOfficerIdx;
				Characters[makeint(Pchar.quest.FreeRandomOfficerIdx)].id = Pchar.quest.FreeRandomOfficerID;
// added by MAXIMUS [for placing new officer in empty slot (default for some officers)] -->
// GR: disabled because it can kick an unremovable quest officer out of the slot
/*
				int ofNum = 3;
				switch(Characters[makeint(Pchar.quest.FreeRandomOfficerIdx)].quest.officertype)
				{
					case OFFIC_TYPE_FIRSTMATE: ofNum = 1; break;
					case OFFIC_TYPE_BOATSWAIN: ofNum = 2; break;
					case OFFIC_TYPE_NAVIGATOR: ofNum = 3; break;
				}
				SetOfficersIndex(Pchar, ofNum, makeint(Pchar.quest.FreeRandomOfficerIdx));
// added by MAXIMUS [for placing new officer in empty slot (default for some officers)] <--
*/
// GR: try to put new officer into a free slot, also explicitly add the officer as a passenger as failsafe -->
				SetOfficersIndex(PChar, -1, sti(PChar.quest.FreeRandomOfficerIdx));
				AddPassenger(PChar, Characters[sti(PChar.quest.FreeRandomOfficerIdx)], 0);

				Characters[makeint(Pchar.quest.FreeRandomOfficerIdx)].location = "None";

			/*	Pchar.quest.LandEnc_OfficerJoined.win_condition.l1 = "ExitFromLocation";
				Pchar.quest.LandEnc_OfficerJoined.win_condition.l1.location = Pchar.location;
				Pchar.quest.LandEnc_OfficerJoined.win_condition = "LandEnc_OfficerJoined";*/

				// TIH --> move any money they may have into their wealth, so MC cant steal their money Oct31'06
				ref NewOfficer = GetCharacter(sti(Pchar.quest.FreeRandomOfficerIdx));
				// this is copied from the TIH_OfficerHiredProcess function
				// since this questaction has yet to be converted to use that function
				if (CheckAttribute(NewOfficer,"money") && sti(NewOfficer.money) > 0)
				{
					if (!CheckAttribute(NewOfficer,"wealth")) { NewOfficer.wealth = 0; } // set if not set
					NewOfficer.wealth = makeint(sti(NewOfficer.wealth) + sti(NewOfficer.money)); // merge together into wealth
					NewOfficer.money = 0; // clear out their money now that its moved
				}
				// TIH <--

				if(Characters[makeint(Pchar.quest.HiringOfficerIDX)].chr_ai.type==LAI_TYPE_SIT) LAi_Fade("LandEnc_OfficerJoined", "");
				else LAi_QuestDelay("LandEnc_OfficerJoined",0);
			}
			else
			{
				Log_SetStringToLog(GlobalStringConvert("QUEST_MESSAGE12"));
				DeleteAttribute(Pchar, "quest.FreeRandomOfficerIdx");
				DeleteAttribute(Pchar, "quest.FreeRandomOfficerID");
			}
		break;

		case "LandEnc_OfficerJoined":
			characters[makeint(Pchar.quest.FreeRandomOfficerIdx)].Dialog.CurrentNode = "hired";
			// boal 05.09.03 offecer need to go to abordage -->
			characters[makeint(Pchar.quest.FreeRandomOfficerIdx)].AbordageMode = makeint(1);
			// boal 05.09.03 offecer need to go to abordage <--
			//MAXIMUS: process with random officers, made from citizens, will look realistic -->
			if(Characters[makeint(Pchar.quest.HiringOfficerIDX)].chr_ai.type==LAI_TYPE_SIT)
			{
				ChangeCharacterAddressGroup(&Characters[makeint(Pchar.quest.HiringOfficerIDX)], "None", "", "");
				PlaceCharacter(characterFromID(Pchar.quest.FreeRandomOfficerID), "goto");
				if(IsOfficer(CharacterFromID(PChar.quest.FreeRandomOfficerID)))
				{
					DialogMain(characterFromID(Pchar.quest.FreeRandomOfficerID)); // added by MAXIMUS
					LAi_SetOfficerType(characterFromID(Pchar.quest.FreeRandomOfficerID));
				}
				else
				{
					Characters[sti(PChar.quest.HiringOfficerIDX)].location = "none";
					Characters[sti(PChar.quest.HiringOfficerIDX)].Dialog.Filename = "Enc_Officer_dialog.c";
					Characters[sti(PChar.quest.HiringOfficerIDX)].Dialog.CurrentNode = "hired";
					LAi_group_MoveCharacter(&Characters[sti(PChar.quest.HiringOfficerIDX)], LAI_GROUP_PLAYER);
					LAi_SetActorType(CharacterFromID(PChar.quest.FreeRandomOfficerID));
					LAi_ActorGoToLocation(CharacterFromID(PChar.quest.FreeRandomOfficerID), "reload", "reload1", "none", "", "", "", -1);
				}
			}
			else
			{
				Characters[makeint(Pchar.quest.HiringOfficerIDX)].location = PChar.location;
				Characters[makeint(Pchar.quest.HiringOfficerIDX)].Dialog.Filename = "";
				Characters[makeint(Pchar.quest.HiringOfficerIDX)].Dialog.CurrentNode = "";
				LAi_group_MoveCharacter(&Characters[makeint(Pchar.quest.HiringOfficerIDX)], LAI_GROUP_PLAYER);
				LAi_SetActorType(&Characters[makeint(Pchar.quest.HiringOfficerIDX)]);
				LAi_ActorRunToLocation(&Characters[makeint(Pchar.quest.HiringOfficerIDX)], "reload", LocatorExitSence(PChar.location, "from", "house"), "none", "", "", "", -1);
			}
			//MAXIMUS: process with random officers, made from citizens, will look realistic <--

			DeleteAttribute(Pchar, "quest.FreeRandomOfficerIdx");
			DeleteAttribute(Pchar, "quest.FreeRandomOfficerID");
			DeleteAttribute(Pchar, "quest.HiringOfficerIDX");
// added by MAXIMUS [for officers icons updates after new officer hire] -->
			PostEvent(EVENT_CHANGE_OFFICERS, 500);//MAXIMUS: officers-icons fixed
// added by MAXIMUS [for officers icons updates after new officer hire] <--

			if(CheckAttribute(Pchar, "quest.OldCrewMember"))
			{
				PChar.quest.ResetCrewmember.win_condition.l1 = "ExitFromLocation";
				PChar.quest.ResetCrewmember.win_condition.l1.character = PChar.id;
				PChar.quest.ResetCrewmember.win_condition.l1.location = PChar.location;
				PChar.quest.ResetCrewmember.win_condition = "ResetCrewmember";
			}
		break;

		case "ResetCrewmember":
			characters[GetCharacterIndex(Pchar.quest.OldCrewMember)].name = TranslateString("","TEST");
			characters[GetCharacterIndex(Pchar.quest.OldCrewMember)].lastname = TranslateString("","");
			characters[GetCharacterIndex(Pchar.quest.OldCrewMember)].Dialog.Filename = "permanent_crewmember_dialog.c";
			characters[GetCharacterIndex(Pchar.quest.OldCrewMember)].Dialog.CurrentNode = "First time";
			characters[GetCharacterIndex(Pchar.quest.OldCrewMember)].skill.Leadership = "1";
			characters[GetCharacterIndex(Pchar.quest.OldCrewMember)].skill.Fencing = "1";
			characters[GetCharacterIndex(Pchar.quest.OldCrewMember)].skill.Sailing = "1";
			characters[GetCharacterIndex(Pchar.quest.OldCrewMember)].skill.Accuracy = "1";
			characters[GetCharacterIndex(Pchar.quest.OldCrewMember)].skill.Cannons = "1";
			characters[GetCharacterIndex(Pchar.quest.OldCrewMember)].skill.Grappling = "1";
			characters[GetCharacterIndex(Pchar.quest.OldCrewMember)].skill.Repair = "1";
			characters[GetCharacterIndex(Pchar.quest.OldCrewMember)].skill.Defence = "1";
			characters[GetCharacterIndex(Pchar.quest.OldCrewMember)].skill.Commerce = "1";
			characters[GetCharacterIndex(Pchar.quest.OldCrewMember)].skill.Sneak = "1";
			SetModelFromID(CharacterFromID(Pchar.quest.OldCrewMember), GetRandomModelForTypeSex(true, "Sailors", "man"));
			DeleteAttribute(Pchar, "quest.OldCrewMember");
		break;

		case "LandEnc_OfficerFired":
			NPChar = GetCharacter(sti(Pchar.quest.FiringOfficerIDX));
			RemovePassenger(Pchar, NPChar);
			LAi_SetCitizenType(NPChar);
			NPChar.Dialog.CurrentNode = "Fired";
			NPChar.location = "none";

			DeleteAttribute(Pchar, "quest.FiringOfficerIDX");
			BLI_UpdateOfficers();
		break;

		// SA (NK bugfix 04-09-06) -->
		case "LandEnc_OfficerFiredGood":
			NPChar = GetCharacter(sti(Pchar.quest.FiringOfficerIDX));
			RemovePassenger(Pchar, NPChar);
			LAi_SetCitizenType(NPChar);
			NPChar.Dialog.CurrentNode = "Departed";
			// Maybe we should change this? But doing so would mean we'd have to keep the slot open...
			NPChar.location = "none";

			DeleteAttribute(Pchar, "quest.FiringOfficerIDX");
			BLI_UpdateOfficers();
		break;
		// SA <--

		// SA (NK bugfix 04-09-06) -->
		case "LandEnc_OfficerFiredGoodPayed":
			NPChar = GetCharacter(sti(Pchar.quest.FiringOfficerIDX));
			int PayOwed = 0;
			if(CheckAttribute(NPChar,"quest.OfficerPayOwed")) PayOwed += sti(NPChar.quest.OfficerPayOwed);
			if (GetCharacterMoney(PChar) < PayOwed) PayOwed = GetCharacterMoney(PChar);

			AddMoneyToCharacter(Pchar,-PayOwed);
			AddWealthToCharacter(&NPChar, PayOwed);
			NPChar.quest.OfficerPayOwed = 0;

			RemovePassenger(Pchar, NPChar);
			LAi_SetCitizenType(NPChar);
			NPChar.Dialog.CurrentNode = "Departed";
			// Maybe we should change this? But doing so would mean we'd have to keep the slot open...
			NPChar.location = "none";

			DeleteAttribute(Pchar, "quest.FiringOfficerIDX");
			BLI_UpdateOfficers();
		break;
		// SA <--

		// boal 05.09.03 offecer need to go to abordage -->
		case "Boal_LandEnc_OfficerStay":
			SetCharacterTask_Stay(Characters[makeint(Pchar.quest.HiringOfficerIDX)]);
			DeleteAttribute(Pchar, "quest.HiringOfficerIDX");
		break;
		// boal 05.09.03 offecer need to go to abordage <--

//------------------------------------------END OFFICER------------------------------------------------

		// NK -->
		case "NK_FightMonstersEvent":
			/*LAi_group_FightGroups(LAI_GROUP_MONSTERS, PLAYER_GROUP, false);

			for(int i = 0; i < MAX_LOGINED_CHARACTERS_IN_LOCATION; i++)
			{
				chr = &Characters[LOC_FANTOM_CHARACTERS + i];
				if(!CheckAttribute(chr,"chr_ai.group")) continue;
				if(chr.chr_ai.group == LAI_GROUP_MONSTERS)
				{
					EnableEquip(chr, BLADE_ITEM_TYPE, true);
					EquipCharacterByItem(chr, FindCharacterItemByGroup(chr, BLADE_ITEM_TYPE));
					ExecuteCharacterEquip(chr);
					if(CheckAttribute(chr,"patroltype"))
					{
						LAi_type_patrol_Init(chr);
					}
					LAi_SetWarriorType(chr);
					LAi_warrior_SetStay(chr, true);
				}
			}*/
		break;
		// NK <--

		case "removed_officer_runaway":
			GetCharacterPos(PChar, &locx, &locy, &locz);
			NPChar = GetCharacter(sti(Pchar.removed_officer)); // PB: Use this instead of character index as it is more direct
			LAi_ActorRunToLocation(NPChar, "reload", LAi_FindNearestFreeLocator("reload", locx, locy, locz), NPChar.homelocation, NPChar.homelocation.group, NPChar.homelocation.locator, "removing_officer_comleted", 10.0);
		break;

		// PB: Rewritten to match with "LandEnc_OfficerFired" -->
		case "removing_officer_comleted":
			NPChar = GetCharacter(sti(Pchar.removed_officer));
			RemovePassenger(Pchar, NPChar);
			switch (NPChar.homestate)
			{
				case "sit":     LAi_SetSitType    (NPChar); break;
				case "citizen": LAi_SetCitizenType(NPChar); break;
			}
			NPChar.Dialog.CurrentNode = "hired_again";
			NPChar.location = NPChar.homelocation;
			NPChar.location.group = NPChar.homelocation.group;
			NPChar.location.locator = NPChar.homelocation.locator;

			DeleteAttribute(Pchar, "removed_officer");
			BLI_UpdateOfficers();
		break;
		// PB: Rewritten to match with "LandEnc_OfficerFired" <--

		case "donation":
// LDH --> 23Sep06 total rewrite, math is identical but simplified and fixed some bugs
			iDonation = sti(pchar.quest.donate);

			//Levis for mysterious plants
			if(CheckAttribute(PChar,"quest.mysterious_plants.donate") && sti(GetAttribute(PChar,"quest.mysterious_plants.donate")) < 1000 && Pchar.location == "Greenford_church")
			{
				PChar.quest.mysterious_plants.donate = sti(GetAttribute(PChar,"quest.mysterious_plants.donate")) + iDonation;
			}
			//Levis end mysterious plants

			iRepRank = makeint(pow(sti(PChar.rank),1.25));	// same as makeint(sqrt(sqrt(sti(PChar.rank)^5))) but without overflow problems

			while (iDonation > 0)
			{
				// Determine cost per point of reputation increase
				iRep = sti(PChar.reputation);
				iMult = 1;
				if (iabs(45-iRep) > 5)  iMult = 2;
				if (iabs(45-iRep) > 10) iMult = 4;	// original code would not have used this, was a bug I think
				if (iabs(45-iRep) > 15) iMult = 8;
				if (iabs(45-iRep) > 25) iMult = 16;
				iCost = (iRepRank * 500) * iMult;

				if (iDonation >= iCost) {
					ChangeCharacterReputation(PChar, 9999); // special case for donations, adds 1 without doubling
					iDonation -= iCost;
					if (iDonation == 0) PChar.quest.donate = 0;
				} else {
					PChar.quest.donate = iDonation;	// if there's any left over, save it for next time
					iDonation = 0;		// tell the loop we're done
				}
			}
/*
Cost for raising a character from the lowest rep (1) to the highest (89)
Cost for level 10 is  7,131,500
Cost for level 20 is 17,619,000
Cost for level 30 is 29,365,000
Cost for level 40 is 41,950,000
Cost for level 50 is 55,374,000
*/
// LDH <--
		break;
		
		//GENERATE
		case "generate_trade_quest":
			if (pchar.quest.generate_trade_quest_progress == "begin")
			{
				pchar.quest.generate_trade_quest_progress = "failed";
				Log_SetStringToLog(GlobalStringConvert("QUEST_MESSAGE2"));
				AddQuestRecord("trade", 2);
			}
		break;

		case "trade_quest_open":
			iTradeGoods = sti(pchar.quest.generate_trade_quest_progress.iTradeGoods);
			iQuantityGoods = sti(pchar.quest.generate_trade_quest_progress.iQuantityGoods);
			iTradeNation = sti(pchar.quest.generate_trade_quest_progress.iTradeNation);

			AddCharacterGoods(pchar, iTradeGoods, iQuantityGoods);
			//задаем квест
			pchar.quest.generate_trade_quest.win_condition.l1 = "Timer";
			pchar.quest.generate_trade_quest.win_condition.l1.date.day = GetAddingDataDay(0, 1, 0);
			pchar.quest.generate_trade_quest.win_condition.l1.date.month = GetAddingDataMonth(0, 1, 0);
			pchar.quest.generate_trade_quest.win_condition.l1.date.year = GetAddingDataYear(0, 1, 0);
			pchar.quest.generate_trade_quest.win_condition = "generate_trade_quest";
			pchar.quest.generate_trade_quest_progress = "begin";

// KK -->
			Preprocessor_AddQuestData("town", FindTownName(pchar.quest.generate_trade_quest_progress.iTradeColony));
			Preprocessor_AddQuestData("island", FindIslandName(GetIslandIDFromTown(pchar.quest.generate_trade_quest_progress.iTradeColony)));
			Preprocessor_AddQuestData("quantity", iQuantityGoods);
			Preprocessor_AddQuestData("cargo", XI_ConvertString(Goods[iTradeGoods].name));
			Preprocessor_AddQuestData("deadline", GetHumanDate(sti(pchar.quest.generate_trade_quest.win_condition.l1.date.year), sti(pchar.quest.generate_trade_quest.win_condition.l1.date.month), sti(pchar.quest.generate_trade_quest.win_condition.l1.date.day)));
			Preprocessor_AddQuestData("store_owner", pchar.quest.generate_trade_quest_progress.iStoreOwner);
			SetQuestHeader("trade");
			AddQuestRecord("trade", 1);
			Preprocessor_Remove("town");
			Preprocessor_Remove("island"); // PB
			Preprocessor_Remove("quantity");
			Preprocessor_Remove("cargo");
			Preprocessor_Remove("deadline");
			Preprocessor_Remove("store_owner");
// <-- KK
		break;

		case "close_trade_quest":
			DeleteQuestHeader("trade"); // KK
		break;

		case "prepare_for_convoy_quest":
			GenerateConvoyQuest(); // PB: Do everything in here
			NPChar = characterFromID("Quest trader");
			homelocation = pchar.location;
			ChangeCharacterAddressGroup(NPChar, homelocation, "reload", "reload1");
			//PlaceCharacter(characterFromID("Quest trader"), "reload");
			pchar.quest.generate_convoy_quest_progress = "begin";
			LAi_SetActorType(NPChar);
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, NPChar, "", 5.0);
			LAi_ActorFollow(NPChar, pchar, "prepare_for_convoy_quest_2", 5.0);
		break;

		case "prepare_for_convoy_quest_2":
			LAi_SetPlayerType(pchar);
			characters[GetCharacterIndex("quest trader")].Dialog.Filename = "anacleto_dialog.c";
			characters[GetCharacterIndex("quest trader")].dialog.currentnode = "prepare_convoy_quest";
			LAi_ActorDialog(characterFromID("Quest trader"), pchar, "", 10.0, 1.0);
		break;

		case "convoy_refused":
			pchar.quest.generate_convoy_quest.over = "yes";
			pchar.quest.generate_convoy_quest_failed.over = "yes";
			pchar.quest.generate_convoy_quest_completed.over = "yes";
			GetCharacterPos(GetMainCharacter(), &locx, &locy, &locz);
			homelocator = LAi_FindNearestFreeLocator("reload", locx, locy, locz);
			LAi_SetActorType(characterFromID("quest trader"));
			LAi_ActorGoToLocation(characterFromID("quest trader"), "reload", homelocator, "none", "", "", "", 10.0);
		
			if (checkquestattribute("generate_convoy_quest_progress", "completed"))
			{
				iPassenger = makeint(pchar.quest.generate_convoy_quest.convoymoney) + makeint(pchar.rank)*100;
				if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Commerce", iPassenger); }
				else { AddPartyExp(pchar, iPassenger); }
				iPassenger = makeint(pchar.quest.generate_convoy_quest.convoymoney);
				// PB: Cumulative Reward for Saving Trader -->
				if(CheckAttribute(characterFromID("quest trader"), "enemyShip"))
				{
					if(!CheckAttribute(characterFromID("Quest trader"), "numSaved"))   iDonation = 0;
					else iDonation = sti(characters[GetCharacterIndex("quest trader")].numSaved) + 1;
					iDonation = iDonation + 1;
					characters[GetCharacterIndex("quest trader")].numSaved = iDonation;
					ChangeCharacterReputation(pchar, 1);
					iPassenger = iPassenger + 100*(iDonation + rand(iDonation));
				}
				// PB: Cumulative Reward for Saving Trader <--
				AddMoneyToCharacter(pchar, iPassenger);
				ChangeCharacterReputation(pchar, 1);
				RemoveCharacterCompanion(Pchar, characterFromID("quest trader"));
				pchar.quest.generate_convoy_quest_progress = "";
			}
			if (!checkquestattribute("generate_convoy_quest_progress", "begin"))
			{
				DeleteQuestHeader("convoy"); // KK
			}
			pchar.quest.generate_convoy_quest_progress = "";
			DeleteAttribute(Pchar,"quest.generate_convoy_quest.destination"); // PB
			Group_DelCharacter("Convoy_Pirate", "Convoy Pirate");
			Group_deleteGroup("Convoy_Pirate");
		break;

		case "generate_convoy_quest":
			ChangeCharacterReputation(pchar, -3);
			DoQuestCheckDelay("convoy_failed", 0.0);
		break;

		case "generate_convoy_quest_failed":
			ChangeCharacterReputation(pchar, -5);
			DoQuestCheckDelay("convoy_failed", 0.0);
		break;

		case "convoy_failed":
			RemoveCharacterCompanion(Pchar, characterFromID("quest trader"));
			pchar.quest.generate_convoy_quest_progress = "";
			pchar.quest.generate_convoy_quest.over = "yes";
			pchar.quest.generate_convoy_quest_failed.over = "yes";
			pchar.quest.generate_convoy_quest_completed.over = "yes";
			if (!CheckAttribute(pchar, "quest.generate_convoy_quest.storm") && !CheckAttribute(pchar, "quest.generate_convoy_quest.board") && !CheckAttribute(pchar, "quest.generate_convoy_quest.attack"))
				AddQuestRecord("convoy", 5);
			if (CheckAttribute(pchar, "quest.generate_convoy_quest.storm")) {
				AddQuestRecord("convoy", 2);
				DeleteAttribute(pchar, "quest.generate_convoy_quest.storm");
			}
			if (CheckAttribute(pchar, "quest.generate_convoy_quest.board")) {
				AddQuestRecord("convoy", 3);
				DeleteAttribute(pchar, "quest.generate_convoy_quest.board");
			}
			if (CheckAttribute(pchar, "quest.generate_convoy_quest.attack")) { // KK -->
				Preprocessor_AddQuestData("attacker", pchar.quest.generate_convoy_quest_failed.attack);
				AddQuestRecord("convoy", 4);
				Preprocessor_Remove("attacker"); // <-- KK
				DeleteAttribute(pchar,"quest.generate_convoy_quest.attack");
			}
			CloseQuestHeader("convoy");
			DeleteAttribute(characterFromID("Quest trader"), "numSaved") // PB: Reset cumulative counter
		break;

		case "generate_convoy_quest_completed":
			homelocation = pchar.location;
			port = &Locations[FindLocation(pchar.location)];
			DeleteAttribute(port,"vcskip");								// PB: Reset this to normal
			if(pchar.location == "Antigua_Port")						// PB: Weird pier needs special case
				ChangeCharacterAddressGroup(CharacterFromID("quest trader"), homelocation, "reload", "reload2");
			else
				SetCharacterToNearLocatorFromMe("quest trader", 3); // PB
			LAi_SetActorType(characterFromID("quest trader"));
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, characterFromID("quest trader"), "", -1);
			LAi_ActorFollow(characterFromID("quest trader"), pchar, "generate_convoy_quest_completed_2", -1);
		break;

		case "generate_convoy_quest_completed_2":
			LAi_type_actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("quest trader"));
			LAi_ActorDialog(characterFromID("quest trader"), pchar, "player_back", 2.0, 1.0);
			characters[GetCharacterIndex("quest trader")].dialog.currentnode = "complete_convoy_quest";
			pchar.quest.generate_convoy_quest_progress = "completed";
		break;

		case "convoy_agreeded":
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("quest trader"));
			SetCharacterRemovable(characterFromID("quest trader"), false);
			
			// KK GetCharacterPos(GetMainCharacter(), &locx, &locy, &locz);
			// KK homelocator = LAi_FindNearestFreeLocator("reload", locx, locy, locz);
			LAi_SetActorType(characterFromID("quest trader"));
			LAi_ActorGoToLocation(characterFromID("quest trader"), "reload", LocatorExitSence(PChar.location, "from", "house"), "none", "", "", "", -1);

			string sdest = "";
			string sIsland = pchar.quest.generate_convoy_quest.island;
			string sDestin = FindDestinationName(&sdest); // PB: Use function with two outputs
			Locations[FindLocation(sdest)].vcskip = true; // PB: Ensure there are no extra characters at the destination port

// KK -->
			Preprocessor_AddQuestData("island", FindIslandName(GetIslandIDFromTown(pchar.quest.generate_convoy_quest.destination)));
			Preprocessor_AddQuestData("destination", sDestin);
			Preprocessor_AddQuestData("money", pchar.quest.generate_convoy_quest.convoymoney); // PB
			SetQuestHeader("convoy");
			AddQuestRecord("convoy", 1);
			Preprocessor_Remove("island");
			Preprocessor_Remove("destination");
			Preprocessor_Remove("money"); // PB
// <-- KK
			characters[GetCharacterIndex("quest trader")].dialog.currentnode = "convoy_in_progress"; // PB: Prevent 'gibberish' in his cabin
			character_SetCompanionEnemyEnable(characterFromID("quest trader"), true);
			pchar.quest.generate_convoy_quest_completed.win_condition.l1 = "Location";
			pchar.quest.generate_convoy_quest_completed.win_condition.l1.location = sDest;
			pchar.quest.generate_convoy_quest_completed.win_condition = "generate_convoy_quest_completed";

			// PB: Possibility for Enemy at Destination -->
			if(rand(1) == 0) // Fixed 50% chance
			{
				if(CheckAttribute(characterFromID("quest trader"), "nation")) iTradeNation = sti(characters[GetCharacterIndex("quest trader")].nation);
				else iTradeNation = GetServedNation());
//				GenerateQuestShip("Convoy Pirate", GetServedNation());	// PB: Use Generic Function
				GenerateQuestShip("Convoy Pirate", iTradeNation);	// GR: make the enemy hostile to the trader
				Group_CreateGroup("Convoy_Pirate");
				Group_AddCharacter("Convoy_Pirate", "Convoy Pirate");
				Group_SetGroupCommander("Convoy_Pirate", "Convoy Pirate");
				Group_SetTaskAttack("Convoy_Pirate", PLAYER_GROUP, true);
				Group_LockTask("Convoy_Pirate");
				Group_SetPursuitGroup("Convoy_Pirate", PLAYER_GROUP);
				Group_SetAddress("Convoy_Pirate", sIsland, "", "");
				characters[GetCharacterIndex("quest trader")].enemyShip = true;
			}
			else
			{
				DeleteAttribute(characterFromID("quest trader"), "enemyShip");
			}
			// PB: Possibility for Enemy at Destination <--
		break;

	/*	case "prepare_gen_convoy_quest":
			GenerateConvoyQuest();
			characters[GetCharacterIndex("quest trader")].dialog.currentnode = "prepare_convoy_quest_4";
			LAi_ActorDialog(characterfromID("quest trader"), pchar, "", 1.0, 1.0);
		break;*/

//boal -->
		case "kill_pirate_agree":
			pchar.quest.prepare_for_kill_pirate.win_condition.l1 = "location";
			pchar.quest.prepare_for_kill_pirate.win_condition.l1.location = pchar.quest.generate_kill_quest.destination;
			pchar.quest.prepare_for_kill_pirate.win_condition = "prepare_for_kill_pirate";
			pchar.quest.prepare_for_kill_pirate.town = GetCurrentTownID();
			//завод книги
			//Log_SetStringToLog("kill_pirate_agree");
// KK -->
			Preprocessor_AddQuestData("island", TranslateString("", FindIslandName(pchar.quest.generate_kill_quest.destination)));
			Preprocessor_AddQuestData("ship_descr", GetShipDescribe("Quest pirate", true, true, true, true));
			SetQuestHeader("hunting");
			AddQuestRecord("hunting", 1);
			Preprocessor_Remove("island");
			Preprocessor_Remove("ship_descr");
// <-- KK
		break;

		case "prepare_for_kill_pirate":
			//NK, use fantom calls way up top.
			Group_AddCharacter("Story_Pirate", "Quest pirate");
			//Log_SetStringToLog("prepare_for_kill_pirate");
			Group_SetGroupCommander("Story_Pirate", "Quest pirate");
			Group_SetTaskAttack("Story_Pirate", PLAYER_GROUP, true);
			//Group_SetAddress("Story_Pirate", Characters[GetMainCharacterIndex()].location, "Quest_ships", "Quest_ship_3");
			Group_SetAddress("Story_Pirate", Pchar.location, "Quest_ships", GetRandomQuestShipLocator(pchar.location)); // PB: Add some variety

			Group_LockTask("Story_Pirate");

			PChar.quest.generate_kill_quest = "searching";

			pchar.quest.kill_pirate_complete.win_condition.l1 = "NPC_Death";
			pchar.quest.kill_pirate_complete.win_condition.l1.character = "Quest pirate";
			pchar.quest.kill_pirate_complete.win_condition = "kill_pirate_complete";
			// PB: Expire this quest after a month -->
			pchar.quest.kill_pirate_complete.fail_condition.l1 = "Timer";
			pchar.quest.kill_pirate_complete.fail_condition.l1.date.day   = GetAddingDataDay  (0, 1, 0);
			pchar.quest.kill_pirate_complete.fail_condition.l1.date.month = GetAddingDataMonth(0, 1, 0);
			pchar.quest.kill_pirate_complete.fail_condition.l1.date.year  = GetAddingDataYear (0, 1, 0);
			pchar.quest.kill_pirate_complete.fail_condition = "kill_pirate_refused_3";
			// PB: Expire this quest after a month <--
		break;

		case "kill_pirate_complete":
			if(!CheckAttribute(pchar,"quest.generate_kill_quest")) break;//MAXIMUS
			if(pchar.quest.generate_kill_quest=="completed") break;//MAXIMUS
			ChangeCharacterReputation(PChar, 4); //Add some reputation gain -Levis
			pchar.quest.generate_kill_quest = "completed";
// KK -->
			if (sti(Pchar.quest.generate_kill_quest.nation) == PIRATE)
				Preprocessor_AddQuestData("type", XI_ConvertString("1Pirate"));
			else
				Preprocessor_AddQuestData("type", XI_ConvertString(GetNationDescByType(sti(pchar.quest.generate_kill_quest.nation))) + " " + XI_ConvertString("Corsair"));
			cc = 0;
			for (iColony = 1; iColony <= GetIslandTownsQuantity(pchar.quest.generate_kill_quest.destination); iColony++) {
				if (GetTownGovernorIndex(GetTownIDFromIsland(pchar.quest.generate_kill_quest.destination, iColony)) != -1) cc++;
			}
			if (cc > 1)
				Preprocessor_AddQuestData("town", FindTownName(PChar.quest.generate_kill_quest.town) + " " + TranslateString("", "onisland") + " " + FindIslandName(pchar.quest.generate_kill_quest.destination));
			else
				Preprocessor_AddQuestData("town", FindTownName(PChar.quest.generate_kill_quest.town));
			Preprocessor_AddQuestData("ship_descr", GetShipDescribe("Quest pirate", true, true, true, true));
			AddQuestRecord("hunting", rand(4) + 2);
			Preprocessor_Remove("type");
			Preprocessor_Remove("town");
			Preprocessor_Remove("ship_descr");
// <-- KK
		break;

		case "kill_pirate_refused":
			pchar.quest.kill_pirate_refused_timer.win_condition.l1 = "Timer";
			pchar.quest.kill_pirate_refused_timer.win_condition.l1.date.day   = GetAddingDataDay  (0, 0, 3);
			pchar.quest.kill_pirate_refused_timer.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 3);
			pchar.quest.kill_pirate_refused_timer.win_condition.l1.date.year  = GetAddingDataYear (0, 0, 3);
			pchar.quest.kill_pirate_refused_timer.win_condition = "kill_pirate_refused_timer";
		break;

		case "kill_pirate_refused_2":
			//Log_SetStringToLog("kill_pirate_refused_2");
			pchar.quest.kill_pirate_refused_timer.win_condition.l1 = "Timer";
			pchar.quest.kill_pirate_refused_timer.win_condition.l1.date.day   = GetAddingDataDay  (0, 0, 3);
			pchar.quest.kill_pirate_refused_timer.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 3);
			pchar.quest.kill_pirate_refused_timer.win_condition.l1.date.year  = GetAddingDataYear (0, 0, 3);
			pchar.quest.kill_pirate_refused_timer.win_condition = "kill_pirate_refused_timer";
			DeleteQuestHeader("hunting");
			DeleteQuestAttribute("hunting");
		break;

		case "kill_pirate_refused_3":
			ChangeCharacterReputation(PChar, -1); //Add some reputation loss -Levis
			pchar.quest.kill_pirate_refused_timer.win_condition.l1 = "Timer";
			pchar.quest.kill_pirate_refused_timer.win_condition.l1.date.day   = GetAddingDataDay  (0, 0, 3);
			pchar.quest.kill_pirate_refused_timer.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 3);
			pchar.quest.kill_pirate_refused_timer.win_condition.l1.date.year  = GetAddingDataYear (0, 0, 3);
			pchar.quest.kill_pirate_refused_timer.win_condition = "kill_pirate_refused_timer";
			DeleteQuestHeader("hunting");
			DeleteQuestAttribute("hunting");
		break;

		case "kill_pirate_refused_timer":
			//Log_SetStringToLog("kill_pirate_refused_timer");
			DeleteAttribute(pchar, "quest.generate_kill_quest");
			//pchar.quest.generate_kill_quest = "";
		break;

		case "kill_pirate_failed":
			PChar.quest.generate_kill_quest = "gave_up";
			ChangeCharacterReputation(PChar, -1); //Add some reputation loss -Levis
			PChar.quest.kill_pirate_refused_timer.win_condition.l1 = "Timer";
			PChar.quest.kill_pirate_refused_timer.win_condition.l1.date.day   = GetAddingDataDay  (0, 0, 3);
			PChar.quest.kill_pirate_refused_timer.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 3);
			PChar.quest.kill_pirate_refused_timer.win_condition.l1.date.year  = GetAddingDataYear (0, 0, 3);
			PChar.quest.kill_pirate_refused_timer.win_condition = "kill_pirate_refused_timer";
			i = Group_FindGroup("Story_Pirate");
			if (i >= 0) Group_DeleteGroupIndex(i);
			ChangeCharacterAddressGroup(CharacterFromID("Quest Pirate"), "None", "", "");
			DeleteQuestHeader("hunting");
			DeleteQuestAttribute("hunting");
		break;
// boal <--

		case "sleep_in_tavern":
//			RecalculateJumpTable();
//			DoQuestReloadToLocation(pchar.location + "_upstairs", "goto", "goto2", "restore_hp");
			string roomName = pchar.location;//MAXIMUS -->
			aref cLoctr; makearef(cLoctr,locations[FindLocation(pchar.location)].reload);
			for(int h=0; h<GetAttributesNum(cLoctr); h++)
			{
				aref curItem = GetAttributeN(cLoctr,h);
				string attrName = GetAttributeName(curItem);
				if(CheckAttribute(cLoctr,attrName+".go"))
				{
					if(HasSubStr(cLoctr.(attrName).go,"_upstairs") || HasSubStr(cLoctr.(attrName).go,"_bedroom")) roomName = cLoctr.(attrName).go;
				}
			}
			// Philippe: For Eleuthera -->
			if(CheckAttribute(pchar,"reloadto"))
			{
				homelocator = pchar.reloadto;
				if(HasSubStr(homelocator,"reload")) homegroup = "reload";
				else homegroup = "goto";
				DeleteAttribute(pchar,"reloadto");
			}
			else
			{
				homelocator = "goto2";
				homegroup = "goto";
			}
			// Philippe: For Eleuthera <--
			DoQuestReloadToLocation(roomName, homegroup, homelocator, "restore_hp");//MAXIMUS <--
		break;
		
		//Levis: Extra atmosphere -->
		case "sleep_in_tavern_with_girl":
			string roomNamegirl = pchar.location;//MAXIMUS -->
			aref cLoctrgirl; makearef(cLoctrgirl,locations[FindLocation(pchar.location)].reload);
			for(h=0; h<GetAttributesNum(cLoctrgirl); h++)
			{
				aref curItemgirl = GetAttributeN(cLoctrgirl,h);
				string attrNamegirl = GetAttributeName(curItemgirl);
				if(CheckAttribute(cLoctrgirl,attrNamegirl+".go"))
				{
					if(HasSubStr(cLoctrgirl.(attrNamegirl).go,"_upstairs") || HasSubStr(cLoctrgirl.(attrNamegirl).go,"_bedroom")) roomNamegirl = cLoctrgirl.(attrNamegirl).go;
				}
			}
			homelocator = "goto4";
			homegroup = "goto";
			DoQuestReloadToLocation(roomNamegirl, homegroup, homelocator, "girl_leaves");//MAXIMUS <--
		break;
		
		case "girl_leaves":
			NPChar = characterFromID(Pchar.sexwith);
			ChangeCharacterAddressGroup(NPChar, pchar.location, "goto", "goto5");
			LAi_SetActorType(NPChar);
			NPChar.Dialog.CurrentNode = Pchar.sexwith.CurrentNode;
			LAi_ActorDialog(NPChar,Pchar,"girl_leaves_2",5.0,5.0);
		break;
		
		case "girl_leaves_2":
			NPChar = characterFromID(Pchar.sexwith);
			LAi_SetActorType(PChar);
			LAi_SetCurHPMax(pchar);
			for (i = 1; i < 4; i++)
			{
				iOfficer = GetOfficersIndex(Pchar, i);
				if (iOfficer != -1) LAi_SetCurHPMax(&characters[iOfficer]);
			}
			LAi_ActorRunToLocator(NPChar,"reload","reload1","girl_gone",40);
		break;
		//Levis: Extra atmosphere <--

		//GR: brothel bedroom -->
		case "to_bedroom_for_girl":
			NPChar = LAi_CreateFantomCharacter(true, 0, true, false, 0.00, GetRandSubString(GetBrothelModels()), "goto", "goto5");
			NPChar.nation = GetTownNation(GetCurrentTownID());
			SetRandomNameToCharacter(NPChar);
			NPChar.dialog.filename = "wenched_dialog.c";
			NPChar.greeting = "Gr_Wench";
			LAi_SetWaitressType(NPChar);
			// LAi_SetStayType(NPChar);
			LAi_QuestDelay("restore_hp", 0.0);
		break;
		//GR: brothel bedroom <--
		
		//Levis: Add waiting time on ship -->
		case "waited_on_ship_for_time":
			NPChar = characterFromID(Pchar.waitedonship);
			LAi_SetActorType(NPChar);
			NPChar.dialog.currentnode = "whatsthetime";
			LAi_ActorDialog(NPChar,Pchar,"",5.0,1.0);
		break;
		
		case "reset after waiting":
			if(CheckAttribute(PChar, "waitedonship"))
			{
				NPChar = characterFromID(Pchar.waitedonship);
				if(NPChar.location.locator == "sit3") LAi_SetHuberType(NPChar);
				else LAi_SetCitizenType(NPChar);
				LAi_group_MoveCharacter(NPChar, LAI_GROUP_PLAYER);
			}
		break;
		//Levis: Add waiting time on ship <--
		
		case "girl_gone":
			NPChar = characterFromID(Pchar.sexwith);
			ChangeCharacterAddressGroup(NPChar,NPChar.tavern.location,NPChar.location.group,NPChar.location.locator);
			LAi_SetWaitressType(NPChar);
			LAi_SetPlayerType(PChar);
		break;

		case "restore_hp":
			LAi_SetCurHPMax(pchar);
			for (i = 1; i < OFFICER_MAX; i++)
			{
				iOfficer = GetOfficersIndex(Pchar, i);
				if (iOfficer != -1) LAi_SetCurHPMax(&characters[iOfficer]);
			}
		break;

		case "drink_talk_with_soldier":
			tavernfriend = pchar.quest.friend_in_tavern;
			LAi_SetSitType(characterFromID(tavernfriend));
			attr = "m" + (rand(5)+1); // Random uniform for soldier
			switch(pchar.location)
			{
				case "Redmond_tavern":
					sld = CharacterFromID("Drink Soldier");
					LAi_SetHP(sld, 80.0, 80.0);
					sld.nation = ENGLAND;
					SetModelfromID(sld, Nations[ENGLAND].fantomModel.(attr));
					DeleteAttribute(sld, "questchar");	// SetRandomNameToCharacter doesn't work on quest characters
					SetRandomNameToCharacter(sld);
					sld.questchar = true;
					LAi_SetGuardianType(sld);
					if (CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE)) == "" GiveSoldierWeapon(sld, ENGLAND);
					LAi_group_MoveCharacter(sld, "ENGLAND_SOLDIERS");
					ChangeCharacterAddressGroup(sld, "Redmond_town_01", "goto", "cityzen9");
					PChar.friend_in_tavern2 = "ENGLAND_SOLDIERS";
					DoQuestReloadToLocation("Redmond_town_01", "goto", "goto12", "drink_speak_with_soldier");
				break;

				case "Oxbay_tavern":
					sld = CharacterFromID("Drink Soldier");
					LAi_SetHP(sld, 80.0, 80.0);
					sld.nation = ENGLAND;
					SetModelfromID(sld, Nations[ENGLAND].fantomModel.(attr));
					DeleteAttribute(sld, "questchar");	// SetRandomNameToCharacter doesn't work on quest characters
					SetRandomNameToCharacter(sld);
					sld.questchar = true;
					LAi_SetGuardianType(sld);
					if (CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE)) == "" GiveSoldierWeapon(sld, ENGLAND);
					LAi_group_MoveCharacter(sld, "ENGLAND_SOLDIERS");
					ChangeCharacterAddressGroup(sld, "Oxbay_town", "goto", "goto37");
					PChar.friend_in_tavern2 = "ENGLAND_SOLDIERS";
					DoQuestReloadToLocation("Oxbay_town", "goto", "goto36", "drink_speak_with_soldier");
				break;

				case "Greenford_tavern":
					sld = CharacterFromID("Drink Soldier");
					LAi_SetHP(sld, 80.0, 80.0);
					sld.nation = ENGLAND;
					SetModelfromID(sld, Nations[ENGLAND].fantomModel.(attr));
					DeleteAttribute(sld, "questchar");	// SetRandomNameToCharacter doesn't work on quest characters
					SetRandomNameToCharacter(sld);
					sld.questchar = true;
					LAi_SetGuardianType(sld);
					if (CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE)) == "" GiveSoldierWeapon(sld, ENGLAND);
					ChangeCharacterAddressGroup(sld, "Greenford_town", "goto", "goto9");
					LAi_group_MoveCharacter(sld, "ENGLAND_SOLDIERS");
					PChar.friend_in_tavern2 = "ENGLAND_SOLDIERS";
					DoQuestReloadToLocation("Greenford_town", "goto", "goto14", "drink_speak_with_soldier");
				break;

				case "Falaise_De_Fleur_tavern":
					sld = CharacterFromID("Drink Soldier");
					LAi_SetHP(sld, 80.0, 80.0);
					sld.nation = FRANCE;
					SetModelfromID(sld, Nations[FRANCE].fantomModel.(attr));
					DeleteAttribute(sld, "questchar");	// SetRandomNameToCharacter doesn't work on quest characters
					SetRandomNameToCharacter(sld);
					sld.questchar = true;
					LAi_SetGuardianType(sld);
					if (CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE)) == "" GiveSoldierWeapon(sld, FRANCE);
					LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
					ChangeCharacterAddressGroup(sld, "Falaise_de_fleur_location_03", "goto", "locator12");
					PChar.friend_in_tavern2 = "FRANCE_SOLDIERS";
					DoQuestReloadToLocation("Falaise_De_fleur_location_03", "goto", "locator11", "drink_speak_with_soldier");
				break;

				case "Muelle_tavern":
					sld = CharacterFromID("Drink Soldier");
					LAi_SetHP(sld, 80.0, 80.0);
					sld.nation = SPAIN;
					SetModelfromID(sld, Nations[SPAIN].fantomModel.(attr));
					DeleteAttribute(sld, "questchar");	// SetRandomNameToCharacter doesn't work on quest characters
					SetRandomNameToCharacter(sld);
					sld.questchar = true;
					LAi_SetGuardianType(sld);
					if (CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE)) == "" GiveSoldierWeapon(sld, SPAIN);
					LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
					ChangeCharacterAddressGroup(sld, "Muelle_town_01", "goto", "goto23");
					PChar.friend_in_tavern2 = "SPAIN_SOLDIERS";
					DoQuestReloadToLocation("Muelle_town_01", "goto", "goto100", "drink_speak_with_soldier");
				break;

				case "Douwesen_tavern":
					sld = CharacterFromID("Drink Soldier");
					LAi_SetHP(sld, 80.0, 80.0);
					sld.nation = HOLLAND;
					SetModelfromID(sld, Nations[HOLLAND].fantomModel.(attr));
					DeleteAttribute(sld, "questchar");	// SetRandomNameToCharacter doesn't work on quest characters
					SetRandomNameToCharacter(sld);
					sld.questchar = true;
					LAi_SetGuardianType(sld);
					if (CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE)) == "" GiveSoldierWeapon(sld, HOLLAND);
					LAi_group_MoveCharacter(sld, "DOUWESEN_SOLDIERS");
					ChangeCharacterAddressGroup(sld, "Douwesen_town", "goto", "goto3");
					PChar.friend_in_tavern2 = "DOUWESEN_SOLDIERS";
					DoQuestReloadToLocation("Douwesen_town", "goto", "goto5", "drink_speak_with_soldier");
				break;

				case "Pirate_tavern":
					sld = CharacterFromID("Pirate soldier");
					LAi_SetHP(sld, 80.0, 80.0);
					SetModelfromID(sld, "man1");
					DeleteAttribute(sld, "questchar");	// SetRandomNameToCharacter doesn't work on quest characters
					SetRandomNameToCharacter(sld);
					sld.questchar = true;
					LAi_SetGuardianType(sld);
					if (CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE)) == "" GiveSoldierWeapon(sld, PIRATE);
					ChangeCharacterAddress(sld, "Pirate_fort", "character9");
					LAi_group_MoveCharacter(sld, "DOUWESEN_PIRATE_SOLDIERS");
					PChar.friend_in_tavern2 = "DOUWESEN_PIRATE_SOLDIERS";
					DoQuestReloadToLocation("Pirate_fort", "goto", "character10", "drink_speak_with_soldier");
				break;

				case "Conceicao_tavern":
					sld = CharacterFromID("Drink Soldier");
					LAi_SetHP(sld, 80.0, 80.0);
					sld.nation = PORTUGAL;
					SetModelfromID(sld, Nations[PORTUGAL].fantomModel.(attr));
					DeleteAttribute(sld, "questchar");	// SetRandomNameToCharacter doesn't work on quest characters
					SetRandomNameToCharacter(sld);
					sld.questchar = true;
					LAi_SetGuardianType(sld);
					if (CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE)) == "" GiveSoldierWeapon(sld, PORTUGAL);
					LAi_group_MoveCharacter(sld, "CONCEICAO_SOLDIERS");
					ChangeCharacterAddressGroup(sld, "Conceicao_town", "goto", "goto5");
					PChar.friend_in_tavern2 = "CONCEICAO_SOLDIERS";
					DoQuestReloadToLocation("Conceicao_town", "goto", "goto4", "drink_speak_with_soldier");
				break;

				case "Smugglers_tavern":
					LAi_SetHP(characterFromID("Smugglers soldier"), 80.0, 80.0);
					ChangeCharacterAddress(characterFromID("Smugglers Soldier"), "Smugglers_lair", "goto12");
					DoQuestReloadToLocation("Smugglers_lair", "goto", "goto11", "drink_speak_with_soldier");
					LAi_group_MoveCharacter(characterFromID("Smugglers Soldier"), "SMUGGLER_SOLDIERS");
					pchar.friend_in_tavern2 = "SMUGGLER_SOLDIERS";
				break;

				case "QC_tavern":
					sld = CharacterFromID("Pirate soldier");
					LAi_SetHP(sld, 80.0, 80.0);
					SetModelfromID(sld, "corsair2");
					DeleteAttribute(sld, "questchar");	// SetRandomNameToCharacter doesn't work on quest characters
					SetRandomNameToCharacter(sld);
					sld.questchar = true;
					LAi_SetGuardianType(sld);
					if (CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE)) == "" GiveSoldierWeapon(sld, PIRATE);
					LAi_group_MoveCharacter(sld, "QC_SOLDIERS");
					PChar.friend_in_tavern2 = "QC_SOLDIERS";
					DoQuestReloadToLocation("QC_town", "goto", "character4", "drink_speak_with_soldier");
				break;

				case "QC_brothel"://<<<<-------------------------------------------------------------------added here, love verruckt
					sld = CharacterFromID("Pirate soldier");
					LAi_SetHP(sld, 80.0, 80.0);
					SetModelfromID(sld, "corsair2");
					DeleteAttribute(sld, "questchar");	// SetRandomNameToCharacter doesn't work on quest characters
					SetRandomNameToCharacter(sld);
					sld.questchar = true;
					LAi_SetGuardianType(sld);
					if (CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE)) == "" GiveSoldierWeapon(sld, PIRATE);
					LAi_group_MoveCharacter(sld, "QC_SOLDIERS");
					PChar.friend_in_tavern2 = "QC_SOLDIERS";
					DoQuestReloadToLocation("QC_town", "goto", "goto18", "drink_speak_with_soldier");
				break;

				case "PoPrince_Tavern":
					sld = CharacterFromID("Drink Soldier");
					LAi_SetHP(sld, 80.0, 80.0);
					sld.nation = FRANCE;
					SetModelfromID(sld, Nations[FRANCE].fantomModel.(attr));
					DeleteAttribute(sld, "questchar");	// SetRandomNameToCharacter doesn't work on quest characters
					SetRandomNameToCharacter(sld);
					sld.questchar = true;
					LAi_SetGuardianType(sld);
					if (CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE)) == "" GiveSoldierWeapon(sld, FRANCE);
					LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
					DoQuestReloadToLocation("PoPrince_town", "goto", "goto4", "drink_speak_with_soldier");
					PChar.friend_in_tavern2 = "FRANCE_SOLDIERS";
				break;

				case "Havana_Tavern":
					sld = CharacterFromID("Drink Soldier");
					LAi_SetHP(sld, 80.0, 80.0);
					sld.nation = SPAIN;
					SetModelfromID(sld, Nations[SPAIN].fantomModel.(attr));
					DeleteAttribute(sld, "questchar");	// SetRandomNameToCharacter doesn't work on quest characters
					SetRandomNameToCharacter(sld);
					sld.questchar = true;
					LAi_SetGuardianType(sld);
					if (CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE)) == "" GiveSoldierWeapon(sld, SPAIN);
					LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
					DoQuestReloadToLocation("Havana_Town_02", "goto", "goto39", "drink_speak_with_soldier");
					PChar.friend_in_tavern2 = "SPAIN_SOLDIERS";
				break;

				case "Santiago_Tavern":
					sld = CharacterFromID("Drink Soldier");
					LAi_SetHP(sld, 80.0, 80.0);
					sld.nation = SPAIN;
					SetModelfromID(sld, Nations[SPAIN].fantomModel.(attr));
					DeleteAttribute(sld, "questchar");	// SetRandomNameToCharacter doesn't work on quest characters
					SetRandomNameToCharacter(sld);
					sld.questchar = true;
					LAi_SetGuardianType(sld);
					if (CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE)) == "" GiveSoldierWeapon(sld, SPAIN);
					LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
					DoQuestReloadToLocation("Santiago_town_01", "officers", "reload3_1", "drink_speak_with_soldier");
					PChar.friend_in_tavern2 = "SPAIN_SOLDIERS";
				break;
			}
		break;

		case "drink_speak_with_soldier":
			LAi_SetActorType(pchar);

			switch(pchar.location)
			{
				case "Redmond_town_01":
					Characters[GetCharacterIndex("Drink Soldier")].dialog.currentnode = "drink";
					LAi_ActorDialog(PChar, CharacterFromID("Drink Soldier"), "player_back", 5.0, 1.0);
				break;

				case "Oxbay_town":
					Characters[GetCharacterIndex("Drink Soldier")].dialog.currentnode = "drink";
					LAi_ActorDialog(PChar, CharacterFromID("Drink Soldier"), "player_back", 5.0, 1.0);
				break;

				case "Greenford_town":
					Characters[GetCharacterIndex("Drink Soldier")].dialog.currentnode = "drink";
					LAi_ActorDialog(PChar, CharacterFromID("Drink Soldier"), "player_back", 5.0, 1.0);
				break;

				case "Falaise_de_fleur_location_03": // PW: was "Falaise_De_Fleur_town"
					Characters[GetCharacterIndex("Drink Soldier")].dialog.currentnode = "drink";
					LAi_ActorDialog(PChar, CharacterFromID("Drink Soldier"), "player_back", 5.0, 1.0);
				break;

				case "Muelle_town_01":
					Characters[GetCharacterIndex("Drink Soldier")].dialog.currentnode = "drink";
					LAi_ActorDialog(PChar, CharacterFromID("Drink Soldier"), "player_back", 5.0, 1.0);
				break;

				case "Douwesen_town":
					Characters[GetCharacterIndex("Drink Soldier")].dialog.currentnode = "drink";
					LAi_ActorDialog(PChar, CharacterFromID("Drink Soldier"), "player_back", 5.0, 1.0);
				break;

				case "Pirate_fort": // PW: was "Pirate_town"
					Characters[GetCharacterIndex("Pirate Soldier")].dialog.currentnode = "drink";
					LAi_ActorDialog(PChar, CharacterFromID("Pirate Soldier"), "player_back", 5.0, 1.0);
				break;

				case "Conceicao_town":
					Characters[GetCharacterIndex("Drink Soldier")].dialog.currentnode = "drink";
					LAi_ActorDialog(PChar, CharacterFromID("Drink Soldier"), "player_back", 5.0, 1.0);
				break;

				case "Smugglers_lair": // PW: was "Smugglers_town"
					characters[GetCharacterIndex("Smugglers Soldier")].dialog.currentnode = "drink";
					LAi_ActorDialog(pchar, characterFromID("Smugglers Soldier"), "player_back", 5.0, 1.0);
				break;

				case "QC_town":
					PlaceCharacter(CharacterFromID("Pirate Soldier"), "goto");
					Characters[GetCharacterIndex("Pirate Soldier")].dialog.currentnode = "drink";
					LAi_ActorDialog(PChar, characterFromID("Pirate Soldier"), "player_back", 5.0, 1.0);
				break;
				// Default using generic soldier character
				sld = CharacterFromID("Drink Soldier");
				PlaceCharacter(sld, "goto");
				sld.dialog.currentnode = "drink";
				LAi_ActorDialog(PChar, sld, "player_back", 5.0, 1.0);
			}
		break;

		//ASVS moved it here
		case "fight_with_soldier_for_drink":
			LAi_group_FightGroups(PChar.friend_in_tavern2, LAI_GROUP_PLAYER, true);
		break;

		case "without_memory":
			LAi_Fade("exit_sit_2", "saved_by_off");
		break;

		case "drink_fight_in_tavern_with_fantoms":
			LAi_Fade("exit_sit_2", "fighting2");
		break;

		case "fighting":
			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "man1", "reload", "reload1");
			sld.headmodel = "h_man1";
			sld.dialog.filename = "tavern fightingman_dialog.c";

			LAi_SetActorType(sld);
			LAi_group_MoveCharacter(sld, "TAVERN_FIGHTER");
			LAi_ActorDialogNow(sld, pchar, "", -1);
		break;

		case "fighting2":
			locCameraFollow();
			LAi_SetSitType(characterFromID(pchar.quest.friend_in_tavern));
			LAi_SetPlayerType(pchar);
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);

			LAi_group_FightGroups("TAVERN_FIGHTER", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("TAVERN_FIGHTER", "kill_tavern_fightman_complete");
		break;

		///////////////////////////////////////////////////////////////
		// Quest Line Rescue Girls
		///////////////////////////////////////////////////////////////
// added by MAXIMUS 18.11.2006 [for nice show of this process] -->
		case "go_to_see_girl":
			LAi_Fade("go_to_room", "");
			LAi_SetActorType(Pchar);
		break;

		case "go_to_room":
			string offLocat = "";
			string offGroup = "";
			offLocat = LAi_FindIndexedLocator(Pchar.location, "goto","goto");
			if(offLocat!="" && offLocat!=Pchar.location.locator) { offGroup = "goto"; }
			else
			{
				offLocat = LAi_FindIndexedLocator(Pchar.location, "rld","loc");
				if(offLocat!="" && offLocat!=Pchar.location.locator) { offGroup = "rld"; }
				else
				{
					offLocat = LAi_FindIndexedLocator(Pchar.location, "officers","reload");
					if(offLocat!="" && offLocat!=Pchar.location.locator) { offGroup = "officers"; }
					else
					{
						offLocat = LAi_FindIndexedLocator(Pchar.location, "reload","reload");
						if(offLocat!="" && offLocat!=Pchar.location.locator) { offGroup = "reload"; }
						else { offLocat = ""; offGroup = ""; }
					}
				}
			}
			LAi_ClearIndexedLocators(Pchar.location, offGroup);
			if(offLocat!="") { ChangeCharacterAddressGroup(characterFromID(Pchar.quest.friend_in_tavern), Pchar.location, offGroup, offLocat); }
			LAi_SetActorType(characterFromID(Pchar.quest.friend_in_tavern));
			LAi_ActorTurnToCharacter(Pchar, CharacterFromID(Pchar.quest.friend_in_tavern));
			string neededLocator = "";
			string neededID = "None";
			for(int rel=1; rel<10; rel++)
			{
				string relName = "l"+rel;
				if(CheckAttribute(locations[FindLocation(Pchar.location)],"reload."+relName+".go"))
				{
					neededID = locations[FindLocation(Pchar.location)].reload.(relName).go;
					if(HasSubStr(neededID,"_upstairs"))
					{
						neededLocator = locations[FindLocation(Pchar.location)].reload.(relName).name;
					}
				}
			}
			LAi_ActorGoToLocator(CharacterFromID(Pchar.quest.friend_in_tavern), "reload", neededLocator, "go_to_see_girl_1", -1);
			if(AlwaysRunToggle)
			{
				PChar.quest.run_toggled = "true";
				AlwaysRunToggle = false;
				BeginChangeCharacterActions(GetMainCharacter());
				SetDefaultNormWalk(GetMainCharacter());
				SetDefaultFight(GetMainCharacter());
				EndChangeCharacterActions(GetMainCharacter());
			}
			LAi_ActorFollow(pchar, characterFromID(Pchar.quest.friend_in_tavern), "", -1);
		break;

		case "go_to_see_girl_1":
			ChangeCharacterAddressGroup(characterFromID(Pchar.quest.friend_in_tavern), "None", "", "");
			Lai_QuestDelay("to_the_room_for_see_girl", 1.0);
		break;
// added by MAXIMUS 18.11.2006 [for nice show of this process] <--

		case "to_the_room_for_see_girl":
			locations[FindLocation(pchar.location + "_upstairs")].reload.l1.disable = 1;
			DoQuestReloadToLocation(pchar.location + "_upstairs", "reload", "reload1", "to_the_girl");// changed by MAXIMUS 18.11.2006 [for nice show of this process]
		break;

// changed by MAXIMUS 18.11.2006 [for nice show of this process] -->
		case "to_the_girl":
			LAi_SetActorType(pchar);
			LAi_type_actor_Reset(pchar);
			LAi_SetActorType(characterFromID(pchar.quest.friend_in_tavern));
			LAi_SetActorType(characterFromID("Virginie d'Espivant"));
			string freelocator = LAi_FindIndexedLocator(pchar.location, "goto", "goto");
			ChangeCharacterAddressGroup(characterFromID(pchar.quest.friend_in_tavern), pchar.location, "goto", LAi_FindIndexedLocator(pchar.location, "goto", "goto"));
			ChangeCharacterAddressGroup(characterFromID("Virginie d'Espivant"), pchar.location, "goto", LAi_FindIndexedLocator(pchar.location, "goto", "goto"));
			LAi_ActorGoToLocator(characterFromID("Virginie d'Espivant"), "goto", freelocator, "", 6.0);
			LAi_ActorGoToLocator(Pchar, "goto", characters[GetCharacterIndex("Virginie d'Espivant")].location.locator, "to_the_room_for_see_girl_2", 6.0);
		break;

		case "to_the_room_for_see_girl_2":
			LAi_SetPlayerType(pchar);
		    if(!AlwaysRunToggle && CheckAttribute(PChar, "quest.run_toggled"))	// GR: If you previously had always-run set and were forced into walking mode, revert to always running
			{
				AlwaysRunToggle = true;
				BeginChangeCharacterActions(GetMainCharacter());
				SetDefaultNormWalk(GetMainCharacter());
				SetDefaultFight(GetMainCharacter());
				EndChangeCharacterActions(GetMainCharacter());
				DeleteQuestAttribute("run_toggled");
			}
			
			LAi_ClearIndexedLocators(Pchar.location, "goto");
			LAi_SetStayType(characterFromID("Virginie d'Espivant"));
// changed by MAXIMUS 18.11.2006 [for nice show of this process] <--
			LAi_ActorDialog(characterFromID(pchar.quest.friend_in_tavern), pchar, "", 2.0, 1.0);
		break;

		case "fight_in_upstairs_for_girl":
			LAi_SetFightMode(PChar, true);// MAXIMUS: prepared for fight
			GiveItem2Character(CharacterFromId(pchar.quest.friend_in_tavern), "blade5");
			EquipCharacterByItem(CharacterFromId(pchar.quest.friend_in_tavern), "blade5");
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], 0);
			LAi_ActorAttack(characterFromID(pchar.quest.friend_in_tavern), pchar, "");
			pchar.quest.kill_man_in_upstairs_for_girl.win_condition.l1 = "NPC_Death";
			pchar.quest.kill_man_in_upstairs_for_girl.win_condition.l1.character = pchar.quest.friend_in_tavern;
			pchar.quest.kill_man_in_upstairs_for_girl.win_condition = "kill_man_in_upstairs_for_girl";
		break;

		case "kill_man_in_upstairs_for_girl":
			Characters[GetCharacterIndex(PChar.quest.friend_in_tavern)].location = "none"; // GR: remove gambler so he doesn't appear if you rent the same room
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], 0);
			LAi_SetFightMode(pchar, false);
			pchar.quest.gambling_with_girl = "gambled";
			LAi_SetActorType(characterFromID("Virginie d'Espivant"));
			LAi_ActorDialog(characterFromID("Virginie d'Espivant"), pchar, "open_room", 2.0, 1.0);
		break;
		
		case "open_room":
			locations[FindLocation(pchar.location)].reload.l1.disable = 0;// MAXIMUS: was pchar.location + "_upstairs", WHY?
		break;

		case "girl_for_sale":
			LAi_type_actor_Reset(CharacterFromID("Virginie d'Espivant"));
			ChangeCharacterAddress(CharacterFromID("Virginie d'Espivant"), "none", "none");/*
			PostEvent("CheckQuestPossibility", 100, "1", 0);
			pchar.quest.not_to_the_ship_2.win_condition.l1 = "ExitFromLocation";
			pchar.quest.not_to_the_ship_2.win_condition.l1.location = pchar.location;
			pchar.quest.not_to_the_ship_2.win_condition = "girl_for_sale_2";*///MAXIMUS: moved to MAXIMUS_Functions.c
		break;

		case "girl_for_sale_2":
			LAi_SetHP(characterFromID("danielle_quests_corsair_1"), 80.0, 80.0);
//			ChangeCharacterAddressGroup(characterFromID("danielle_quests_corsair_1"), pchar.location, "reload", "reload1");								// PB: Reset this to normal
			if(pchar.location == "Antigua_Port")						// PB: Weird pier needs special case
				ChangeCharacterAddressGroup(CharacterFromID("danielle_quests_corsair_1"), homelocation, "reload", "reload2");
			else										// GR: attempt to spawn pirate wherever you are. 
				SetCharacterToNearLocatorFromMe("danielle_quests_corsair_1", 3);	// 'SetCharacterToNearLocatorFromMe' takes character ID, not ref, as parameter

			LAi_SetActorType(characterFromID("danielle_quests_corsair_1"));
			LAi_ActorDialog(characterFromID("danielle_quests_corsair_1"), pchar, "", 2.0, 1.0);
		break;

		case "habitue_exit_from_room":
			LAi_ActorGoToLocator(characterFromID(pchar.quest.friend_in_tavern), "reload", "reload1", "habitue_exit_from_room_2_complete", 4.0);
			LAi_SetActorType(characterFromID("Virginie d'Espivant"));
			LAi_ActorDialog(characterFromID("Virginie d'Espivant"), pchar, "open_room", 2.0, 1.0);
		break;

		case "girl_exit_from_room":
			pchar.quest.cure_bag_girl_exit_from_room_2.win_condition.l1 = "ExitFromLocation";
			pchar.quest.cure_bag_girl_exit_from_room_2.win_condition.l1.location = pchar.location;
			pchar.quest.cure_bag_girl_exit_from_room_2.win_condition = "girl_exit_from_room_2_complete";

			LAi_ActorGoToLocator(characterFromID("Virginie d'Espivant"), "reload", "reload1", "girl_exit_from_room_2_complete", 4.0);
		break;

		case "girl_exit_from_room_2_complete":
			LAi_type_actor_Reset(CharacterFromID("Virginie d'Espivant"));
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", 5000); }
			else { AddPartyExp(pchar, 5000); }
			pchar.quest.gambling_with_girl = "done";
			ChangeCharacterAddress(CharacterFromID("Virginie d'Espivant"), "none", "none");
		break;

		case "habitue_exit_from_room_2_complete":
			switch(pchar.location)
			{
				case "Oxbay_tavern_upstairs":
					ChangeCharacterAddressGroup(&characters[getCharacterIndex(pchar.quest.friend_in_tavern)], "Oxbay_tavern", "sit", characters[getCharacterIndex(pchar.quest.friend_in_tavern)].quest.locator);
				break;

				case "Greenford_tavern_upstairs":
					ChangeCharacterAddressGroup(&characters[getCharacterIndex(pchar.quest.friend_in_tavern)], "Greenford_tavern", "sit", characters[getCharacterIndex(pchar.quest.friend_in_tavern)].quest.locator);
				break;

				case "Redmond_tavern_upstairs":
					ChangeCharacterAddressGroup(&characters[getCharacterIndex(pchar.quest.friend_in_tavern)], "Redmond_tavern", "sit", characters[getCharacterIndex(pchar.quest.friend_in_tavern)].quest.locator);
				break;

				case "Muelle_tavern_upstairs":
					ChangeCharacterAddressGroup(&characters[getCharacterIndex(pchar.quest.friend_in_tavern)], "Muelle_tavern", "sit", characters[getCharacterIndex(pchar.quest.friend_in_tavern)].quest.locator);
				break;

				case "Douwesen_tavern_upstairs":
					ChangeCharacterAddressGroup(&characters[getCharacterIndex(pchar.quest.friend_in_tavern)], "Douwesen_tavern", "sit", characters[getCharacterIndex(pchar.quest.friend_in_tavern)].quest.locator);
				break;

				case "Conceicao_tavern_upstairs":
					ChangeCharacterAddressGroup(&characters[getCharacterIndex(pchar.quest.friend_in_tavern)], "Conceicao_tavern", "sit", characters[getCharacterIndex(pchar.quest.friend_in_tavern)].quest.locator);
				break;

				case "Smugglers_tavern_upstairs":
					ChangeCharacterAddressGroup(&characters[getCharacterIndex(pchar.quest.friend_in_tavern)], "Smugglers_tavern", "sit", characters[getCharacterIndex(pchar.quest.friend_in_tavern)].quest.locator);
				break;

				case "Pirate_tavern_upstairs":
					ChangeCharacterAddressGroup(&characters[getCharacterIndex(pchar.quest.friend_in_tavern)], "Pirate_tavern", "sit", characters[getCharacterIndex(pchar.quest.friend_in_tavern)].quest.locator);
				break;

				case "QC_tavern_upstairs":
					ChangeCharacterAddressGroup(&characters[getCharacterIndex(pchar.quest.friend_in_tavern)], "QC_tavern", "sit", characters[getCharacterIndex(pchar.quest.friend_in_tavern)].quest.locator);
				break;

				case "Falaise_de_fleur_tavern_upstairs":
					ChangeCharacterAddressGroup(&characters[getCharacterIndex(pchar.quest.friend_in_tavern)], "Falaise_De_fleur_tavern", "sit", characters[getCharacterIndex(pchar.quest.friend_in_tavern)].quest.locator);
				break;
				ChangeCharacterAddressGroup(&characters[getCharacterIndex(pchar.quest.friend_in_tavern)], strcut(pchar.location,0,strlen(pchar.location)-10), "sit", characters[getCharacterIndex(pchar.quest.friend_in_tavern)].quest.locator);// added by MAXIMUS for new islands
			}
			LAi_SetSitType(characterFromID(pchar.quest.friend_in_tavern));
		break;

		case "gambled_girl_to_FdF"://MAXIMUS: -->
			LAi_type_actor_Reset(CharacterFromID("Virginie d'Espivant"));
			AddPassenger(pchar, CharacterFromID("Virginie d'Espivant"), 0);
			SetCharacterRemovable(characterFromID("Virginie d'Espivant"), false);
			if(GetCharacterShipCabin(pchar)!="Cabin_none")
			{
				ChangeCharacterAddressGroup(characterFromID("Virginie d'Espivant"), GetCharacterShipCabin(pchar), "goto", "goto1");
				characters[GetCharacterIndex("Virginie d'Espivant")].chr_ai.type = LAI_TYPE_CITIZEN;
				SetEventHandler("CharacterTypeUpdate","LAi_CharacterTypeUpdate",1);
				PostEvent("CharacterTypeUpdate",3000,"s","Virginie d'Espivant");
			}
			else ChangeCharacterAddress(CharacterFromID("Virginie d'Espivant"), "none", "none");//MAXIMUS: <--
			OfficersReaction("good");
			pchar.quest.gambling_with_girl = "to_FDF";
			pchar.quest.gambled_girl_comes_to_FDF_tavern.win_condition.l1 = "location";
			pchar.quest.gambled_girl_comes_to_FDF_tavern.win_condition.l1.location = "Falaise_De_fleur_tavern";
			pchar.quest.gambled_girl_comes_to_FDF_tavern.win_condition = "gambled_girl_comes_to_FDF_tavern_complete";
			Locations[FindLocation("Falaise_De_Fleur_tavern")].reload.l1.disable = 1;
			Locations[FindLocation(pchar.location)].reload.l1.disable = 0;
		break;

		case "gambled_girl_comes_to_FDF_tavern_complete":
			ChangeCharacterAddress(characterFromID("Raymond Bouchez"), "Falaise_De_Fleur_Tavern", "goto4");
			ChangeCharacterAddress(characterFromID("Virginie d'Espivant"), "Falaise_De_Fleur_Tavern", "goto5");
			
			LAi_SetActorType(characterFromID("Virginie d'Espivant"));
			LAi_SetActorType(characterFromID("Falaise_De_Fleur_officiant"));
			LAi_SetActorType(characterFromID("Raymond Bouchez"));
			LAi_SetActorType(pchar);
			//LAi_ActorTurnToCharacter(characterFromID("Raymond Bouchez"), characterFromID("Falaise_De_Fleur_officiant"));
			LAi_ActorFollow(pchar, characterFromID("Raymond Bouchez"), "", 2.0);
			LAi_ActorFollow(characterFromID("Virginie d'Espivant"), characterFromID("Raymond Bouchez"), "gambled_girl_comes_to_FDF_tavern_2_complete", 2.0);
			LAi_ActorFollow(characterFromID("Falaise_De_Fleur_officiant"), characterFromID("Raymond Bouchez"), "", 3.0);
		break;

		case "gambled_girl_comes_to_FDF_tavern_2_complete":
			LAi_type_actor_Reset(pchar);
			LAi_type_actor_Reset(characterFromID("Raymond Bouchez"));
			LAi_ActorWaitDialog(pchar, characterFromID("Raymond Bouchez"));
			LAi_ActorDialog(characterFromID("Raymond Bouchez"), pchar, "", 2.0, 1.0);
		break;

		case "virginie_speak":
			LAi_QuestDelay("virginie_speak_2", 0.3);
		break;

		case "virginie_speak_2":
			LAi_type_actor_Reset(pchar);
			LAi_type_actor_Reset(characterFromID("Virginie d'Espivant"));
			LAi_ActorWaitDialog(pchar, characterFromID("Virginie d'Espivant"));
			LAi_ActorDialog(characterFromID("Virginie d'Espivant"), pchar, "", 2.0, 1.0);
		break;

		case "Raymond_speak":
			LAi_QuestDelay("Raymond_speak_2", 0.3);
		break;

		case "Raymond_speak_2":
			LAi_type_actor_Reset(pchar);
			LAi_type_actor_Reset(characterFromID("Raymond Bouchez"));
			LAi_ActorWaitDialog(pchar, characterFromID("Raymond Bouchez"));
			LAi_ActorDialog(characterFromID("Raymond Bouchez"), pchar, "", 2.0, 1.0);
		break;

		case "sister_speak":
			LAi_QuestDelay("sister_speak_2", 0.3);
		break;

		case "sister_speak_2":
			LAi_type_actor_Reset(pchar);
			LAi_type_actor_Reset(characterFromID("Falaise_De_Fleur_officiant"));
			LAi_ActorWaitDialog(pchar, characterFromID("Falaise_De_Fleur_officiant"));
			LAi_ActorDialog(characterFromID("Falaise_De_Fleur_officiant"), pchar, "", 2.0, 1.0);
		break;

		case "gambled_girl_exit_from_FDF_tavern":
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", 5000); }
			else { AddPartyExp(pchar, 5000); }
			LAi_SetCitizenType(characterFromID("Falaise_De_Fleur_officiant"));
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(pchar, "reload", "reload1", "gambled_girl_exit_from_tavern_complete", 3.0);
		break;

		case "gambled_girl_exit_from_tavern_complete":
			DoQuestReloadToLocation("Falaise_de_fleur_location_03", "reload", "Falaise_de_fleur_tavern", "last_speak_with_virginia");
			characters[GetCharacterIndex("Raymond Bouchez")].location = "none";
			Locations[FindLocation("Falaise_De_Fleur_tavern")].reload.l1.disable = 0;
		break;

		case "last_speak_with_virginia":
			pchar.quest.gambling_with_girl = "to_hovernor";
			Locations[FindLocation("Falaise_De_Fleur_location_03")].reload.l3.disable = 0; //NK so you can see the governor to return her even if Oxbay hasn't been recaptured.
			ChangeCharacterAddress(characterFromID("Virginie d'Espivant"), "Falaise_de_fleur_location_03", "locator9");
			LAi_SetPlayerType(pchar);
			LAi_type_actor_Reset(characterFromID("Virginie d'Espivant"));
			LAi_ActorDialog(characterFromID("Virginie d'Espivant"), pchar, "", 2.0, 1.0);
		break;

		case "virginie_follow":
			LAi_ActorFollow(characterFromID("Virginie d'Espivant"), PChar, "", -1);
			characters[getCharacterIndex("joseph claude le moigne")].dialog.currentnode = "quests";
		break;

		case "remove_virginie_complete":
			RemovePassenger(pchar, characterFromID("Virginie d'Espivant"));
			if(pchar.location != "Falaise_de_fleur_location_03") ChangeCharacterAddress(characterFromID("Virginie d'Espivant"), "Falaise_de_fleur_location_03", "locator9");
			LAi_SetCitizenType(characterFromID("Virginie d'Espivant"));
			pchar.quest.virginie_goes_home.win_condition.l1 = "ExitFromLocation";
			pchar.quest.virginie_goes_home.win_condition.l1.location = pchar.location;
			pchar.quest.virginie_goes_home.win_condition = "virginie_goes_home";
		break;

		case "virginie_goes_home":
			ChangeCharacterAddress(characterFromID("Virginie d'Espivant"), "None", ""); // GR: Virgine disappears as she returns to France
		break;

		///////////////////////////////////////////////////////////////
		// Quest Line Rescue Girls
		///////////////////////////////////////////////////////////////

		case "saved_by_off":
			LAi_SetStayType(PChar);
			AddMoneyToCharacter(PChar, -100);
			homelocation = PChar.location;
			switch(homelocation)
			{
/*				case "Redmond_tavern":
					PlaceCharacter(characterFromID("Redmond_officiant"), "goto");
					LAi_SetActorType(characterFromID("Redmond_officiant"));
					LAi_SetActorType(PChar);
					LAi_ActorTurnToCharacter(PChar,characterFromID("Redmond_officiant"));
					LAi_ActorWaitDialog(PChar, CharacterFromID("Redmond_officiant"));
					characters[GetCharacterIndex("Redmond_officiant")].dialog.currentnode = "without_money";
					LAi_ActorDialog(characterFromID("Redmond_officiant"), PChar,"",2.0, 1.0);
				break;

				case "Oxbay_tavern":
					PlaceCharacter(characterFromID("Oxbay_officiant"), "goto");
					LAi_SetActorType(characterFromID("Oxbay_officiant"));
					LAi_SetActorType(PChar);
					LAi_ActorTurnToCharacter(PChar,characterFromID("Oxbay_officiant"));
					LAi_ActorWaitDialog(PChar, CharacterFromID("Oxbay_officiant"));
					characters[GetCharacterIndex("Oxbay_officiant")].dialog.currentnode = "without_money";
					LAi_ActorDialog(characterFromID("Oxbay_officiant"), PChar,"",2.0, 1.0);
				break;

				case "Greenford_tavern":
					PlaceCharacter(characterFromID("Greenford_officiant"), "goto");
					LAi_SetActorType(characterFromID("Greenford_officiant"));
					LAi_SetActorType(PChar);
					LAi_ActorTurnToCharacter(PChar,characterFromID("Greenford_officiant"));
					LAi_ActorWaitDialog(PChar, CharacterFromID("Greenford_officiant"));
					characters[GetCharacterIndex("Greenford_officiant")].dialog.currentnode = "without_money";
					LAi_ActorDialog(characterFromID("Greenford_officiant"), PChar,"",2.0, 1.0);
				break;

				case "Falaise_De_Fleur_tavern":
					PlaceCharacter(characterFromID("Falaise_De_Fleur_officiant"), "goto");
					LAi_SetActorType(characterFromID("Falaise_De_fleur_officiant"));
					LAi_SetActorType(PChar);
					LAi_ActorTurnToCharacter(PChar,characterFromID("Falaise_De_fleur_officiant"));
					LAi_ActorWaitDialog(PChar, CharacterFromID("Falaise_De_fleur_officiant"));
					characters[GetCharacterIndex("Falaise_De_Fleur_officiant")].dialog.currentnode = "without_money";
					LAi_ActorDialog(characterFromID("Falaise_de_fleur_officiant"), PChar,"",2.0, 1.0);
					
				break;

				case "Muelle_tavern":
					PlaceCharacter(characterFromID("Muelle_officiant"), "goto");
					LAi_SetActorType(characterFromID("Muelle_officiant"));
					LAi_SetActorType(PChar);
					LAi_ActorTurnToCharacter(PChar,characterFromID("Muelle_officiant"));
					LAi_ActorWaitDialog(PChar, CharacterFromID("Muelle_officiant"));
					characters[GetCharacterIndex("Muelle_officiant")].dialog.currentnode = "without_money";
					LAi_ActorDialog(characterFromID("Muelle_officiant"), PChar,"",2.0, 1.0);
				break;

				case "Douwesen_tavern":
					PlaceCharacter(characterFromID("Douwesen_officiant"), "goto");
					LAi_SetActorType(characterFromID("Douwesen_officiant"));
					LAi_SetActorType(PChar);
					LAi_ActorTurnToCharacter(PChar,characterFromID("Douwesen_officiant"));
					LAi_ActorWaitDialog(PChar, CharacterFromID("Douwesen_officiant"));
					characters[GetCharacterIndex("Douwesen_officiant")].dialog.currentnode = "without_money";
					LAi_ActorDialog(characterFromID("Douwesen_officiant"), PChar,"",2.0, 1.0);
				break;
*/
				case "Pirate_tavern":
					PlaceCharacter(characterFromID("Pirate_officiant"), "goto");
					LAi_SetActorType(characterFromID("Pirate_officiant"));
					LAi_SetActorType(PChar);
					LAi_ActorTurnToCharacter(PChar,characterFromID("Pirate_officiant"));
					LAi_ActorWaitDialog(PChar, CharacterFromID("Pirate_officiant"));
					characters[GetCharacterIndex("Pirate_officiant")].dialog.currentnode = "without_money";
					LAi_ActorDialog(characterFromID("Pirate_officiant"), PChar,"",2.0, 1.0);
				break;
/*
				case "Conceicao_tavern":
					PlaceCharacter(characterFromID("Conceicao_officiant"), "goto");
					LAi_SetActorType(characterFromID("Conceicao_officiant"));
					LAi_SetActorType(PChar);
					LAi_ActorTurnToCharacter(PChar,characterFromID("Conceicao_officiant"));
					LAi_ActorWaitDialog(PChar, CharacterFromID("Conceicao_officiant"));
					characters[GetCharacterIndex("Conceicao_officiant")].dialog.currentnode = "without_money";
					LAi_ActorDialog(characterFromID("Conceicao_officiant"), PChar,"",2.0, 1.0);
				break;
*/
				case "Smugglers_tavern":
					PlaceCharacter(characterFromID("Smugglers_officiant"), "goto");
					LAi_SetActorType(characterFromID("Smugglers_officiant"));
					LAi_SetActorType(PChar);
					LAi_ActorTurnToCharacter(PChar,characterFromID("Smugglers_officiant"));
					LAi_ActorWaitDialog(PChar, CharacterFromID("Smugglers_officiant"));
					characters[GetCharacterIndex("Smugglers_officiant")].dialog.currentnode = "without_money";
					LAi_ActorDialog(characterFromID("Smugglers_officiant"), PChar,"",2.0, 1.0);
				break;

				case "QC_tavern":
					PlaceCharacter(characterFromID("QC_officiant"), "goto");
					LAi_SetActorType(characterFromID("QC_officiant"));
					LAi_SetActorType(PChar);
					LAi_ActorTurnToCharacter(PChar,characterFromID("QC_officiant"));
					LAi_ActorWaitDialog(PChar, CharacterFromID("QC_officiant"));
					characters[GetCharacterIndex("QC_officiant")].dialog.currentnode = "without_money";
					LAi_ActorDialog(characterFromID("QC_officiant"), PChar,"",2.0, 1.0);
				break;

				case "QC_brothel"://<<<----------------------------------------------------------------Added here, love verruckt
					if (GetTime() <= 12.0) NPChar = CharacterFromID("wench1");
					else NPChar = CharacterFromID("wench2");
//					PlaceCharacter(NPChar, "goto");
					ChangeCharacterAddressGroup(NPChar, PChar.location, "goto", "goto3");
					NPChar.dialog.currentnode = "without_money";
					LAi_SetActorType(NPChar);
					LAi_ActorDialog(NPChar, PChar, "", 5.0, 1.0);
				break;
				// Default for other locations
				NPChar = GetTownOfficiant(GetCurrentTownID());
				PlaceCharacter(NPChar, "goto");
				LAi_SetActorType(NPChar);
				LAi_SetActorType(PChar);
				LAi_ActorTurnToCharacter(PChar, NPChar);
				LAi_ActorWaitDialog(PChar, NPChar);
				NPChar.dialog.currentnode = "without_money";
				LAi_ActorDialog(NPChar, PChar,"",2.0, 1.0);
			}
		break;

		case "officiant_back_to_citizen":
			LAi_SetPlayerType(pchar);
			AddMoneyToCharacter(pchar, -100);
			switch(pchar.location)
			{
				case "Redmond_tavern":
					LAi_SetWaitressType(characterFromID("Redmond_officiant"));
					LAi_group_MoveCharacter(characterFromID("Redmond_officiant"), "ENGLAND_CITIZENS");
				break;

				case "Oxbay_tavern":
					LAi_SetWaitressType(characterFromID("Oxbay_officiant"));
					LAi_group_MoveCharacter(characterFromID("Oxbay_officiant"), "ENGLAND_CITIZENS");
				break;

				case "Greenford_tavern":
					LAi_SetWaitressType(characterFromID("Greenford_officiant"));
					LAi_group_MoveCharacter(characterFromID("Greenford_officiant"), "ENGLAND_CITIZENS");
				break;

				case "Falaise_De_Fleur_tavern":
					LAi_SetWaitressType(characterFromID("Falaise_De_fleur_officiant"));
					LAi_group_MoveCharacter(characterFromID("Falaise_De_fleur_officiant"), "FRANCE_CITIZENS");
				break;

				case "Muelle_tavern":
					LAi_SetWaitressType(characterFromID("Muelle_officiant"));
					LAi_group_MoveCharacter(characterFromID("Muelle_officiant"), "SPAIN_CITIZENS");
				break;

				case "Douwesen_tavern":
					LAi_SetWaitressType(characterFromID("Douwesen_officiant"));
					LAi_group_MoveCharacter(characterFromID("Douwesen_officiant"), "DOUWESEN_CITIZENS");
				break;

				case "Pirate_tavern":
					LAi_SetWaitressType(characterFromID("Pirate_officiant"));
					LAi_group_MoveCharacter(characterFromID("Pirate_officiant"), "DOUWESEN_PIRATE_CITIZENS");
				break;

				case "Conceicao_tavern":
					LAi_SetWaitressType(characterFromID("Conceicao_officiant"));
					LAi_group_MoveCharacter(characterFromID("Conceicao_officiant"), "CONCEICAO_CITIZENS");
				break;

				case "Smugglers_tavern":
					LAi_SetWaitressType(characterFromID("Smugglers_officiant"));
					LAi_group_MoveCharacter(characterFromID("Smugglers_officiant"), "SMUGGLERS_CITIZENS");
				break;

				case "QC_tavern":
					LAi_SetWaitressType(characterFromID("QC_officiant"));
					LAi_group_MoveCharacter(characterFromID("QC_officiant"), "QC_CITIZENS");
				break;

				case "QC_brothel"://<<------------------------------------------------------------------Added here, Love Verruckt
					if (GetTime() <= 17.0) NPChar = CharacterFromID("wench2");
					else NPChar = CharacterFromID("wench1");
					LAi_SetWaitressType(NPChar);
					LAi_group_MoveCharacter(NPChar, "ENGLAND_CITIZENS");
				break;
				// Default for other locations
				NPChar = GetTownOfficiant(GetCurrentTownID());
				LAi_SetWaitressType(NPChar);
				LAi_group_MoveCharacter(NPChar, GetCurrentCitizenGroup());
			}
		break;

		case "alc":
			LAi_Fade("alc_2_prepare", "alc2");
		break;

		case "alc_2_prepare":
			LAi_SetSitType(pchar);
			LAi_SetActorType(characterFromID(pchar.quest.friend_in_tavern));
			LAi_ActorSetSitMode(characterFromID(pchar.quest.friend_in_tavern));

			GetCharacterPos(pchar, &Land_posx[0], &Land_posy[0], &Land_posz[0]);	//ASVS
			GetCharacterAy(pchar, &Land_angle[0]);									//ASVS

			switch(pchar.location) //PW all opposite locators now set as candles to prevent NPC use
			{
				case "Redmond_tavern":
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit1") ChangeCharacterAddressGroup(pchar, "Redmond_tavern", "candles", "sit11");
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit3") ChangeCharacterAddressGroup(pchar, "Redmond_tavern", "candles", "sit2");
				break;

				case "Oxbay_tavern":
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit1") ChangeCharacterAddressGroup(pchar, "Oxbay_tavern", "candles", "sit11");
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit3") ChangeCharacterAddressGroup(pchar, "Oxbay_tavern", "candles", "sit2");
				break;

				case "Greenford_tavern":
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit1") ChangeCharacterAddressGroup(pchar, "Greenford_tavern", "candles", "sit2");
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit5") ChangeCharacterAddressGroup(pchar, "Greenford_tavern", "candles", "sit6");
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit4") ChangeCharacterAddressGroup(pchar, "Greenford_tavern", "candles", "sit3");
				break;

				case "Falaise_De_Fleur_tavern":
					// PW No fixed people - random often to full table -but default would put to wrong near locator
				break;

				case "Muelle_tavern":
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit1") ChangeCharacterAddressGroup(pchar, "Muelle_tavern", "sit2", "sit2");
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit7") ChangeCharacterAddressGroup(pchar, "Muelle_tavern", "sit2", "sit3");
				break;

				case "Douwesen_tavern":
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit1") ChangeCharacterAddressGroup(pchar, "Douwesen_tavern", "sit2", "sit2");
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit7") ChangeCharacterAddressGroup(pchar, "Douwesen_tavern", "sit2", "sit3");
				break;

				case "Pirate_tavern":
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit1") ChangeCharacterAddressGroup(pchar, "Pirate_tavern", "candles", "sit2");
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit5") ChangeCharacterAddressGroup(pchar, "Pirate_tavern", "candles", "sit6");
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit4") ChangeCharacterAddressGroup(pchar, "Pirate_tavern", "candles", "sit3");
				break;

				case "Conceicao_tavern":
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit1") ChangeCharacterAddressGroup(pchar, "Conceicao_tavern", "sit2", "sit2");
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit7") ChangeCharacterAddressGroup(pchar, "Conceicao_tavern", "sit2", "sit3");
				break;

				case "Smugglers_tavern":
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit1") ChangeCharacterAddressGroup(pchar, "Smugglers_tavern", "candles", "sit2");
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit5") ChangeCharacterAddressGroup(pchar, "Smugglers_tavern", "candles", "sit6");
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit4") ChangeCharacterAddressGroup(pchar, "Smugglers_tavern", "candles", "sit3");
				break;

				case "QC_tavern":
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit1") ChangeCharacterAddressGroup(pchar, "QC_tavern", "sit2", "sit2");
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit7") ChangeCharacterAddressGroup(pchar, "QC_tavern", "sit2", "sit3"); //PW was sit3 using sit7 but sit3 no longer a valid locator so won't be used?
				break;

				case "QC_brothel"://<<<<------------------------------------------------------------------Added This, Love Verruckt
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit1")
					{
						ChangeCharacterAddressGroup(pchar, "QC_brothel", "candles", "sit11");
					}
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit3")
					{
						ChangeCharacterAddressGroup(pchar, "QC_brothel", "candles", "sit2");
					}
				break;

				case "PoPrince_Tavern":
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit8") ChangeCharacterAddressGroup(pchar, "PoPrince_Tavern", "sit2", "sit4");
				break;

				case "Havana_Tavern":
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit6") ChangeCharacterAddressGroup(pchar, "Havana_Tavern", "sit2", "sit8");
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit20") ChangeCharacterAddressGroup(pchar, "Havana_Tavern", "sit2", "sit17");
				break;

				case "Santiago_Tavern":
					if (characters[GetCharacterIndex(pchar.quest.friend_in_tavern)].location.locator == "sit12") ChangeCharacterAddressGroup(pchar, "Santiago_Tavern", "sit2", "sit11");
				break;

				// default:
					GetCharacterPos(characters[GetCharacterIndex(pchar.quest.friend_in_tavern)], &x, &y, &z);
					if(!CheckAttribute(pchar,"habitue.location")) pchar.habitue.location = pchar.location;
					else
					{
						if(pchar.habitue.location!=pchar.location) pchar.habitue.location = pchar.location;
					}

					if(!CheckAttribute(pchar,"habitue.locator"))
					{
						nearloc = LAi_FindNearestFreeLocator("sit", x, y, z);
						pchar.habitue.locator = nearloc;
					}
					else
					{
						if(pchar.habitue.location!=pchar.location) nearloc = LAi_FindNearestFreeLocator("sit", x, y, z);
						else nearloc = pchar.habitue.locator;
						pchar.habitue.locator = nearloc; //PW line added otherwise nearloc is not used in the changecharacteraddress so why bother??
					}
					ChangeCharacterAddressGroup(pchar, pchar.location, "sit", pchar.habitue.locator);
					DeleteAttribute(pchar,"habitue.locator"); // PW reset so that this is not retained in case a "quest friend" character is in a different seat next time
			}
		break;

		case "alc2":
			LAi_ActorDialogNow(characterFromID(pchar.quest.friend_in_tavern), pchar, "", -1);
		break;

		case "exit_sit":
			if (CheckQuestAttribute("fight_in_tavern", "fight"))
			{
				pchar.quest.fight_in_tavern = "0";
				LAi_SetSitType(characterFromID(pchar.quest.friend_in_tavern));
			}
			else
			{
				LAi_SetPlayerType(pchar);
				LAi_SetSitType(characterFromID(pchar.quest.friend_in_tavern));
				LAi_Fade("exit_sit_2", "");
			}
		break;

		case "exit_sit_2":
			homelocation = pchar.quest.friend_in_tavern;
			LAi_SetSitType(characterFromID(homelocation));
			LAi_SetPlayerType(pchar);

			switch(pchar.location)
			{
				case "Redmond_tavern":
					LAi_group_MoveCharacter(characterFromID(pchar.quest.friend_in_tavern), "ENGLAND_CITIZENS");
				break;

				case "Oxbay_tavern":
					LAi_group_MoveCharacter(characterFromID(pchar.quest.friend_in_tavern), "ENGLAND_CITIZENS");
				break;

				case "Greenford_tavern":
					LAi_group_MoveCharacter(characterFromID(pchar.quest.friend_in_tavern), "ENGLAND_CITIZENS");
				break;

				case "Falaise_De_Fleur_tavern":
					LAi_group_MoveCharacter(characterFromID(pchar.quest.friend_in_tavern), "FRANCE_CITIZENS");
				break;

				case "Muelle_tavern":
					LAi_group_MoveCharacter(characterFromID(pchar.quest.friend_in_tavern), "SPAIN_CITIZENS");
				break;

				case "Douwesen_tavern":
					LAi_group_MoveCharacter(characterFromID(pchar.quest.friend_in_tavern), "DOUWESEN_CITIZENS");
				break;

				case "Pirate_tavern":
					LAi_group_MoveCharacter(characterFromID(pchar.quest.friend_in_tavern), "DOUWESEN_PIRATE_CITIZENS");
				break;

				case "Conceicao_tavern":
					LAi_group_MoveCharacter(characterFromID(pchar.quest.friend_in_tavern), "CONCEICAO_CITIZENS");
				break;

				case "Smugglers_tavern":
					LAi_group_MoveCharacter(characterFromID(pchar.quest.friend_in_tavern), "SMUGGLERS_CITIZENS");
				break;

				case "QC_tavern":
					LAi_group_MoveCharacter(characterFromID(pchar.quest.friend_in_tavern), "QC_CITIZENS");
				break;

				case "QC_brothel"://<---------------------------------------------------------------HERE Brothel Mod , love Verruckt!
					LAi_group_MoveCharacter(characterFromID(pchar.quest.friend_in_tavern), "ENGLAND_CITIZENS");
				break;
				
				case "Cartagena Casino":
					ReadLocatorCoordinates("reload", "reload4", &Land_posx[0], &Land_posy[0], &Land_posz[0]);
				break;
//				case "default":// MAXIMUS [for new locations]
/*					string charGroup = "QC_CITIZENS";
					for(int log=0; log<LAi_numloginedcharacters; log++)
					{
						int logIdx = LAi_loginedcharacters[log];
						if(logIdx>=0 && !bAllies(&Characters[logIdx]) && !LAi_IsDead(&Characters[logIdx]) && CheckAttribute(&Characters[logIdx],"chr_ai.group") && CheckAttribute(&Characters[logIdx],"chr_ai.type") && Characters[logIdx].chr_ai.type==LAI_TYPE_BARMAN)
						{
							charGroup = Characters[logIdx].chr_ai.group; break;
						}
					}*/
					LAi_group_MoveCharacter(characterFromID(pchar.quest.friend_in_tavern), GetCurrentCitizenGroup());
//					LAi_group_MoveCharacter(characterFromID(pchar.quest.friend_in_tavern), charGroup);
/*					GetCharacterPos(&characters[GetCharacterIndex(pchar.quest.friend_in_tavern)], &x, &y, &z);
					nearloc = LAi_FindNearestFreeLocator("goto", x, y, z);
					ChangeCharacterAddress(pchar, pchar.location, nearloc);
*/					if(CheckAttribute(pchar,"habitue.locator"))
					{
						if(pchar.habitue.location!=pchar.location) DeleteAttribute(pchar,"habitue.locator");
					}
//				break;
			}

			if (!CheckAttribute(PChar,"quest.poker.started")) 
			{
				TeleportCharacterToPosAy(pchar, Land_posx[0], Land_posy[0], Land_posz[0], Land_angle[0]);
			}
			else
			{
				ChangeCharacterAddressGroup(pchar, "Turks_poker_room", "goto", "goto13");
				LAi_SetActorType(Pchar);
				Lai_ActorRunToLocator(pchar, "goto", "goto12", "Competition_day_end", 0);
			
			}
			
		break;

		case "kill_tavern_fightman_complete":
			LAi_SetStayType(pchar);
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], true);
			LAi_SetPlayerType(pchar);
		break;

		case "tavern_keeper":
			homelocation = pchar.location;
			switch(homelocation)
			{
				case "Redmond_tavern":
					characters[GetCharacterIndex("Charles Windem")].dialog.currentnode = "tavern_keeper";
					LAi_ActorWaitDialog(pchar, characterFromID("Charles Windem"));
					LAi_SetActorType(characterFromID("Charles Windem"));
					LAi_ActorDialogNow(characterFromID("Charles Windem"), pchar, "tavern_keeper_2", -1);
				break;

				case "Oxbay_tavern":
					characters[GetCharacterIndex("Everard Gordon")].dialog.currentnode = "tavern_keeper";
					LAi_ActorWaitDialog(pchar, characterFromID("Everard Gordon"));
					LAi_SetActorType(characterFromID("Everard Gordon"));
					LAi_ActorDialogNow(characterFromID("Everard Gordon"), pchar, "tavern_keeper_2", -1);
				break;

				case "Greenford_tavern":
					characters[GetCharacterIndex("Simon Hanpool")].dialog.currentnode = "tavern_keeper";
					LAi_ActorWaitDialog(pchar, characterFromID("Simon Hanpool"));
					LAi_SetActorType(characterFromID("Simon Hanpool"));
					LAi_ActorDialogNow(characterFromID("Simon Hanpool"), pchar, "tavern_keeper_2", -1);
				break;

				case "Falaise_De_Fleur_tavern":
					characters[GetCharacterIndex("Antoine Lebretton")].dialog.currentnode = "tavern_keeper";
					LAi_ActorWaitDialog(pchar, characterFromID("Antoine Lebretton"));
					LAi_SetActorType(characterFromID("Antoine Lebretton"));
					LAi_ActorDialogNow(characterFromID("Antoine Lebretton"), pchar, "tavern_keeper_2", -1);
				break;

				case "Muelle_tavern":
					characters[GetCharacterIndex("Claudio Burrieza")].dialog.currentnode = "tavern_keeper";
					LAi_ActorWaitDialog(pchar, characterFromID("Claudio Burrieza"));
					LAi_SetActorType(characterFromID("Claudio Burrieza"));
					LAi_ActorDialogNow(characterFromID("Claudio Burrieza"), pchar, "tavern_keeper_2", -1);
				break;

				case "Douwesen_tavern":
					characters[GetCharacterIndex("Friedrich Corleis")].dialog.currentnode = "tavern_keeper";
					LAi_ActorWaitDialog(pchar, characterFromID("Friedrich Corleis"));
					LAi_SetActorType(characterFromID("Friedrich Corleis"));
					LAi_ActorDialogNow(characterFromID("Friedrich Corleis"), pchar, "tavern_keeper_2", -1);
				break;

				case "Pirate_tavern":
					characters[GetCharacterIndex("Mario Figuiera")].dialog.currentnode = "tavern_keeper";
					LAi_ActorWaitDialog(pchar, characterFromID("Mario Figuiera"));
					LAi_SetActorType(characterFromID("Mario Figuiera"));
					LAi_ActorDialogNow(characterFromID("Mario Figuiera"), pchar, "tavern_keeper_2", -1);
				break;

				case "Conceicao_tavern":
					characters[GetCharacterIndex("Duarte Correja")].dialog.currentnode = "tavern_keeper";
					LAi_ActorWaitDialog(pchar, characterFromID("Duarte Correja"));
					LAi_SetActorType(characterFromID("Duarte Correja"));
					LAi_ActorDialogNow(characterFromID("Duarte Correja"), pchar, "tavern_keeper_2", -1);
				break;

				case "Smugglers_tavern":
					characters[GetCharacterIndex("Fabiao Dunga")].dialog.currentnode = "tavern_keeper";
					LAi_ActorWaitDialog(pchar, characterFromID("Fabiao Dunga"));
					LAi_SetActorType(characterFromID("Fabiao Dunga"));
					LAi_ActorDialogNow(characterFromID("Fabiao Dunga"), pchar, "tavern_keeper_2", -1);
				break;

				case "QC_tavern":
					characters[GetCharacterIndex("Ines Diaz")].dialog.currentnode = "tavern_keeper";
					LAi_ActorWaitDialog(pchar, characterFromID("Ines Diaz"));
					LAi_SetActorType(characterFromID("Ines Diaz"));
					LAi_ActorDialogNow(characterFromID("Ines Diaz"), pchar, "tavern_keeper_2", -1);
				break;

				case "QC_brothel":
					Characters[GetCharacterIndex("QCbartender")].dialog.currentnode = "tavern_keeper";
					LAi_ActorWaitDialog(PChar, CharacterFromID("QCbartender"));
					LAi_SetActorType(CharacterFromID("QCbartender"));
					LAi_ActorDialogNow(CharacterFromID("QCbartender"), PChar, "tavern_keeper_2", -1);
				break;
				// Default
				i = GetTownTavernOwnerIndex(GetCurrentTownID());
				NPChar = GetCharacter(i);
				NPChar.dialog.currentnode = "tavern_keeper";
				LAi_ActorWaitDialog(PChar, NPChar);
				LAi_SetActorType(NPChar);
				LAi_ActorDialogNow(NPChar, PChar, "tavern_keeper_2", -1);
			}
		break;

		case "tavern_keeper_2":
			homelocation = pchar.location;
			switch(homelocation)
			{
				case "Redmond_tavern":
					characters[GetCharacterIndex("Charles Windem")].dialog.currentnode = "First time";
					LAi_SetBarmanType(characterFromID("Charles Windem"));
				break;

				case "Oxbay_tavern":
					characters[GetCharacterIndex("Everard Gordon")].dialog.currentnode = "First time";
					LAi_SetBarmanType(characterFromID("Everard Gordon"));
				break;

			/*	case "Greenford_tavern":
					LAi_SetBarmanType(characterFromID("Simon Hanpool"));
					characters[GetCharacterIndex("Simon Hanpool")].dialog.currentnode = "second time";
				break;

				case "Falaise_De_Fleur_tavern":
					LAi_SetBarmanType(characterFromID("Antoine Lebretton"));
					characters[GetCharacterIndex("Antoine Lebretton")].dialog.currentnode = "second time";
				break;

				case "Muelle_tavern":
					LAi_SetBarmanType(characterFromID("Claudio Burrieza"));
					characters[GetCharacterIndex("Claudio Burrieza")].dialog.currentnode = "second time";
				break;

				case "Douwesen_tavern":
					LAi_SetBarmanType(characterFromID("Friedrich Corleis"));
					characters[GetCharacterIndex("Friedrich Corleis")].dialog.currentnode = "second time";
				break; */

				case "Pirate_tavern":
					LAi_SetBarmanType(characterFromID("Mario Figuiera"));
					characters[GetCharacterIndex("Mario Figuiera")].dialog.currentnode = "second time";
				break;

			/*	case "Conceicao_tavern":
					LAi_SetBarmanType(characterFromID("Duarte Correja"));
					characters[GetCharacterIndex("Duarte Correja")].dialog.currentnode = "second time";
				break; */

				case "Smugglers_tavern":
					LAi_SetBarmanType(characterFromID("Fabiao Dunga"));
					characters[GetCharacterIndex("Fabiao Dunga")].dialog.currentnode = "second time";
				break;

				case "QC_tavern":
					LAi_SetBarmanType(characterFromID("Ines Diaz"));
					characters[GetCharacterIndex("Ines Diaz")].dialog.currentnode = "second time";
				break;

				case "QC_brothel":
					LAi_SetBarmanType(CharacterFromID("QCbartender"));
					characters[GetCharacterIndex("QCbartender")].dialog.currentnode = "First time";
				break;
				// Default
				i = GetTownTavernOwnerIndex(GetCurrentTownID());
				NPChar = GetCharacter(i);
				LAi_SetBarmanType(NPChar);
				NPChar.dialog.currentnode = "second time";
			}
		break;

		// NK -->
		case "marriageduel":
			//PChar.marriageduel.loc = PCHar.location;
			//PChar.marriageduel.MRid
			//for now, just spawn character here.
			string loc;
			float dist;
			GetNearLocator( "goto", &dist, &loc, 0);
			if (PChar.sex == "man") sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, SelectSoldierModelbyLocationNation("", "officer"), "goto", loc);
			else sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, GetRandomModelForTypeSex(-1, "Rich_Citizens", "woman"), "goto", loc);
			sld.id = "Suitor";
			sld.nation = Characters[GetCharacterIndex(PChar.marriageduel.MRid)].nation;
			LAi_SetActorType(CharacterFromID("Suitor"));
			sld.dialog.filename = "Gov MR_dialog.c";
			sld.dialog.currentnode = "engarde";
			LAi_ActorDialog(CharacterFromID("Suitor"), PChar, "", 0.01, 1.0);
		break;

		case "marriageduel_fight":
			LAi_LocationFightDisable(&Locations[FindLocation(PChar.location)], false);
			LAi_SetWarriorType(CharacterFromID("Suitor"));
			LAi_group_MoveCharacter(characterFromID("Suitor"), "BANDITS");
			LAi_group_FightGroups("BANDITS", LAI_GROUP_PLAYER, true);
			LAi_SetCheckMinHP(CharacterFromID("Suitor"), 0.875*LAi_GetCharacterHP(characterFromID("Suitor")), true, "marriageduel_won"); // KK
		break;

		case "marriageduel_won":
			LAi_LocationFightDisable(&Locations[FindLocation(PChar.location)], true);
			LAi_SetFightMode(GetMainCharacter(), false)
			sld = CharacterFromID("Suitor");
			LAi_SetImmortal(CharacterFromID("Suitor"), false);
			LAi_SetActorType(CharacterFromID("Suitor"));
			sld.dialog.currentnode = "duelend";
			LAi_ActorDialog(CharacterFromID("Suitor"), PChar, "", 0.01, 1.0);
		break;

		case "marriageduel_end":
			ChangeCharacterAddress(CharacterFromID("Suitor"), "none", "none");
			sld = CharacterFromID(PChar.marriageduel.MRid);
			sld.dialog.currentnode = "married";
			LAi_ActorDialogNow(sld, PChar, "", -1);
		break;

		case "RemoveMRs":
			ClearMRLocations();
		break;

		// NK 05-04-17 add "updatedays" handler for when you want the day to update but
		case "updatedays":
			PChar = GetMainCharacter();
			if(!CheckAttribute(PChar,"updatedays")) break;
			int daysn = sti(PChar.updatedays);
			bool disableDCU = CheckAttribute(PChar,"updatedays.disableDCU");
			bool curDCU = !CheckAttribute(PChar,"disableDCU");
			bool disableIT = CheckAttribute(PChar,"updatedays.disableIT");
			bool curIT = CheckAttribute(ShipLookupTable,"itemtraders") && sti(ShipLookupTable.itemtraders);
			if(disableDCU) PChar.disableDCU = true;
			if(disableIT && curIT) ShipLookupTable.itemtraders = false;
			//if(FindLoadedLocation() != -1) LAi_Fade("", "");
			int s, dn;
			//int start = 0; if(CheckAttribute(wdmgrid,"lastupdate.day")) { start = sti(wdmgrid.lastupdate.start)+1; }
			for(dn = 0; dn < daysn-1; dn++)
			{
				trace("Gauging: Start day " + dn);
				AddDataToCurrent(0, 0, 1, true); //Changed to true so everything is updated
				ReloadProgressUpdate();
				//DailyCrewUpdate();
				//ReloadProgressUpdate();
				//UpdateAllTowns(false);
				//trace("Gauging: Towns done");
				//ReloadProgressUpdate();
				//UpdateAllStores(false);
				//wdmFleetsUpdateDay(); //wdmFleetsUpdate(false, false); // WM 05-04-24
			}
			if(curDCU) DeleteAttribute(PChar,"disableDCU");
			ReloadProgressUpdate();

			if(curIT)
			{
				ShipLookupTable.itemtraders = true;
				UpdateAllItemTraders(2); // make everyone blank, but put off the actual updates until you speak with them.
			}
			ReloadProgressUpdate();
			AddDataToCurrent(0, 0, 1, true); // do the last day with the normal post.
			DeleteAttribute(PChar,"updatedays");
		break;
// NK <--

		// MAXIMUS =================================== Prisoners and Captived Captains Section =================================== >
		case "Surrendered_Captain_Dialog":
			LAi_SetPlayerType(PChar);
			if(CheckAttribute(PChar,"quest.CaptiveIdx"))
			{
				LAi_SetStayType(GetCharacter(sti(PChar.quest.CaptiveIdx)));
				DialogMain(GetCharacter(sti(PChar.quest.CaptiveIdx)));
				DeleteAttribute(PChar,"quest.CaptiveIdx");
			}
		break;

		case "Surrendered_Captain_Poor":
			if(CheckAttribute(PChar,"prisonerIDX"))
			{
				LAi_SetPoorType(&characters[makeint(PChar.prisonerIDX)]);
				DeleteAttribute(PChar,"prisonerIDX");
			}
		break;

		case "Surrendered_Captain_Stay":
			if(CheckAttribute(PChar,"prisonerIDX")) LAi_SetStayType(&characters[makeint(PChar.prisonerIDX)]);
		break;

		case "Surrendered_Captain_Turn":
			if(CheckAttribute(PChar,"prisonerIDX"))
			{
				LAi_ActorTurnToCharacter(&characters[makeint(PChar.prisonerIDX)], PChar);
				LAi_SetStayType(&characters[makeint(PChar.prisonerIDX)]);
			}
		break;

		case "Surrendered_Captain_Afraid":
			if(CheckAttribute(PChar,"prisonerIDX"))
			{
				LAi_ActorAnimation(&characters[makeint(PChar.prisonerIDX)], "afraid","", -1);
				DeleteAttribute(PChar,"prisonerIDX");
			}
		break;

		case "Surrendered_Captain_Dead":
			if(CheckAttribute(PChar,"prisonerIDX"))
			{
				switch(Rand(1))
				{
					case 0: LAi_ActorAnimation(&characters[makeint(PChar.prisonerIDX)], "death_afraid_1","", -1); break;
					case 1: LAi_ActorAnimation(&characters[makeint(PChar.prisonerIDX)], "death_afraid_2","", -1); break;
				}
				DeleteAttribute(PChar,"prisonerIDX");
			}
		break;

		case "Surrendered_Captain_Dead1":
			if(CheckAttribute(PChar,"prisonerIDX"))
			{
				NPChar = GetCharacter(sti(PChar.prisonerIDX));
				LAi_ActorAnimation(NPChar, "Ground_Afraid_Death","", -1);
				RemovePassenger(PChar,NPChar);
				DeleteAttribute(NPChar,"prisoned");
				DeleteAttribute(PChar,"prisonerIDX");
			}
		break;

		case "Surrendered_Captain_Run":
			if(CheckAttribute(PChar,"prisonerIDX"))
			{
				NPChar = GetCharacter(sti(PChar.prisonerIDX));
				LAi_ActorRunToLocation(NPChar, "reload", LAi_FindRandomLocator("reload"), "None", "reload", "", "", -1);
				RemovePassenger(PChar,NPChar);
				DeleteAttribute(NPChar,"prisoned");
				DeleteAttribute(PChar,"prisonerIDX");
				NPChar.ClearUponExit = true; // PB: So this guy is cleared upon exit
			}
		break;
		// MAXIMUS =================================== Prisoners and Captived Captains Section =================================== <
		// MAXIMUS =================================== Guadeloupe governor Section =================================== >
		case "ChangeHoverPos1":
			characters[sti(pchar.quest.ChangeHoverPos1.idx)].location	= "PaP_townhall";
			characters[sti(pchar.quest.ChangeHoverPos1.idx)].location.group = "goto";
			characters[sti(pchar.quest.ChangeHoverPos1.idx)].location.locator = "goto8";
			LAi_SetLoginTime(&characters[sti(pchar.quest.ChangeHoverPos1.idx)], 12.0, 24.0);
			LAi_SetHuberStayType(&characters[sti(pchar.quest.ChangeHoverPos1.idx)]);
			LAi_SetStayHuberPointWindow(&characters[sti(pchar.quest.ChangeHoverPos1.idx)], "goto", "goto1");
			LAi_SetStayHuberPointMap(&characters[sti(pchar.quest.ChangeHoverPos1.idx)], "goto", "goto3");
			pchar.quest.ChangeHoverPos1_progress = "completed";
		break;

		case "ChangeHoverPos2":
			characters[sti(pchar.quest.ChangeHoverPos2.idx)].location	= "PaP_townhall";
			characters[sti(pchar.quest.ChangeHoverPos2.idx)].location.group = "sit";
			characters[sti(pchar.quest.ChangeHoverPos2.idx)].location.locator = "sit1";
			LAi_SetLoginTime(&characters[sti(pchar.quest.ChangeHoverPos2.idx)], 0.0, 12.0);
			LAi_SetHuberType(&characters[sti(pchar.quest.ChangeHoverPos2.idx)]);
			pchar.quest.ChangeHoverPos_progress = "completed";
		break;
		// MAXIMUS =================================== Guadeloupe governor Section =================================== <
		// PURSEON =================================== Begin Training fight Section =================================== >
		case "StartTrainingFight":
			NPChar = characterFromID("TrainingFight_1");
			if (PChar.TrainingFight.level == 2)
			{
				NPChar.rank = PChar.rank*2;
				NPChar.experience = PChar.experience*2;
				NPChar.skill.Fencing = 10;	
				NPChar.perks.list.BasicDefence = true;
				NPChar.perks.list.AdvancedDefence = true;
				NPChar.perks.list.SwordplayProfessional = true;
				NPChar.perks.list.CriticalHit = true;
				NPChar.perks.list.Gunman = true;
				NPChar.perks.list.GunProfessional = true;
			}
			else
			{
				NPChar.rank = PChar.rank;
				NPChar.experience = PChar.experience;
				NPChar.skill.Fencing = GetAttribute(PChar, "skill.Fencing");
				NPChar.perks.list.BasicDefence = GetAttribute(PChar, "perks.list.BasicDefence");
				NPChar.perks.list.AdvancedDefence = GetAttribute(PChar, "perks.list.AdvancedDefence");
				NPChar.perks.list.SwordplayProfessional = GetAttribute(PChar, "perks.list.SwordplayProfessional");
				NPChar.perks.list.CriticalHit = GetAttribute(PChar, "perks.list.CriticalHit");
				NPChar.perks.list.Gunman = GetAttribute(PChar, "perks.list.Gunman");
				NPChar.perks.list.GunProfessional = GetAttribute(PChar, "perks.list.GunProfessional");
			}
			if (LAi_GetCharacterHP(PChar) < 200)
			{
				LAi_SetHP(PChar, 200.0, 200.0);
				LAi_SetHP(NPChar, 200.0, 200.0);
			}
			else
			{
				LAi_SetHP(NPChar, LAi_GetCharacterHP(PChar), LAi_GetCharacterHP(PChar));
			}
			LAi_SetActorTypeNoGroup(PChar);
			LAi_SetActorType(PChar);
			LAi_SetActorType(NPChar);

			Lai_SetPlayerType(PChar);
			LAi_LockFightMode(PChar, false);
			Lai_SetImmortal(NPChar, false);

			LAi_SetFightMode(PChar, true);

			LAi_SetActorTypeNoGroup(NPChar); 
			LAi_ActorAttack(NPChar, PChar, "");

			Lai_SetCheckMinHP(PChar, 0.5*LAi_GetCharacterHP(PChar), false, "TrainingFightFinished1"); 
			Lai_SetCheckMinHP(NPChar, 0.5*LAi_GetCharacterHP(NPChar), true, "TrainingFightFinished2"); 
		break;

		case "TrainingFightFinished1":
			NPChar = characterFromID("TrainingFight_1");
			LAi_RemoveCheckMinHP(NPChar);
			LAi_SetCurHPMax(NPChar);
			ResetHP(NPChar);
			LAi_type_actor_Reset(NPChar);
			LAi_RemoveCheckMinHP(Pchar);
			LAi_SetCurHPMax(Pchar);
			ResetHP(Pchar);
			LAi_SetActorTypeNoGroup(PChar);
			Lai_ActorWaitDialog(Pchar, NPChar);
			LAi_SetFightMode(PChar, false);
			Lai_QuestDelay("TrainingFightFinished1_1", 1.5);
		break;

		case "TrainingFightFinished1_1":
			NPChar = characterFromID("TrainingFight_1");
			Characters[sti(PChar.TrainingFight.leader)].Dialog.CurrentNode = "EnoughForYou1";
			LAi_ActorDialog(NPChar, PChar, "", 1.0, 1.0);
		break;

		case "TrainingFightFinished2":
			NPChar = characterFromID("TrainingFight_1");
			LAi_RemoveCheckMinHP(NPChar);
			LAi_SetCurHPMax(NPChar);
			ResetHP(NPChar);
			LAi_type_actor_Reset(NPChar);
			LAi_RemoveCheckMinHP(Pchar);
			LAi_SetCurHPMax(Pchar);
			ResetHP(Pchar);
			LAi_SetActorTypeNoGroup(PChar);
			Lai_ActorWaitDialog(Pchar, NPChar);
			LAi_SetFightMode(PChar, false);
			Lai_QuestDelay("TrainingFightFinished2_1", 1.5);
		break;

		case "TrainingFightFinished2_1":
			NPChar = characterFromID("TrainingFight_1");
			Characters[sti(PChar.TrainingFight.leader)].Dialog.CurrentNode = "EnoughForYou2";
			LAi_ActorDialog(NPChar, PChar, "", 1.0, 1.0);
		break;
		// PURSEON =================================== End Training fight Section =================================== <

		case "piratefun":
			JoinNavy(PIRATE); // PB: Even simpler

			// Rename "Pirates" to "Brethren of the Coast"
			makeref(period, Periods[GetCurrentPeriod()]);
			period.Nations.OfficialName.Pirate = "Brethren of the Coast";

			// Tortuga: Not in Bartolomeu Storyline
			if (sti(GetStorylineVar(FindCurrentStoryline(), "BART_PUZZLES")) != 1)
			{
				if (iRealismMode == 0 && GetTownNation("Tortuga") == FRANCE)
				{
					CaptureTownForNation("Tortuga", PIRATE);
					SetTownName("Tortuga", "Tortuga");
					Preprocessor_Delete("Tortuga");
					Preprocessor_Save("Tortuga", FindTownName("Tortuga"));
				}
				Characters[GetCharacterIndex("Bertrand Ogeron")].Dialog.Filename = "PGov_dialog.c";
				Characters[GetCharacterIndex("Bertrand Ogeron")].Dialog.Filename.GroupDialog = "governor.c";
			}

			// Turks: Not in Jack Sparrow Storyline
			if (sti(GetStorylineVar(FindCurrentStoryline(), "JACK_SPARROW")) != 1)
			{ 
				Characters[GetCharacterIndex("Dante Siciliano")].Dialog.Filename = "PGov_dialog.c";
				Characters[GetCharacterIndex("Dante Siciliano")].Dialog.Filename.GroupDialog = "governor.c";
			}

			// Nevis: Not in Standard Storyline
			if (sti(GetStorylineVar(FindCurrentStoryline(), "START_MIN_LEVEL")) != 1)
			{ 
				Characters[GetCharacterIndex("Isenbrandt Jurcksen")].Dialog.Filename = "PGov_dialog.c";
				Characters[GetCharacterIndex("Isenbrandt Jurcksen")].Dialog.Filename.GroupDialog = "governor.c";
			}

			// JRH&Levis: Change the Nevis blacksmith to gunsmith -->
			if (ENABLE_WEAPONSMOD)
			{
				// Modify the reload icon
				Locations[FindLocation("QC_town_exit")].reload.l6.go = "QC_Gunsmith";
				Locations[FindLocation("QC_blacksmith")].id.label = "Pirate Gun- and Blacksmith";
				Locations[FindLocation("QC_blacksmith")].id = "QC_Gunsmith";
				Characters[GetCharacterIndex("QC_blacksmith")].Location = "QC_Gunsmith";
				
				// Modify the Fast Travel icon
				makearef(curTable,objFastReloadTable.table.QC);
				curTable.l6.pic = FRP_GUNBLACKSMITH;
				curTable.l6.tex = FRT_GUNBLACKSMITH;
				curTable.l6.note = FRN_GUNBLACKSMITH;
				curTable.l6.location = "QC_Gunsmith";
				RecalculateJumpTable();
				
				// Give him the alternate dialog
				Characters[GetCharacterIndex("QC_blacksmith")].Dialog.Filename = "Gunsmith_dialog.c";
				
				// And enable the correct fetch quests
				Characters[GetCharacterIndex("QC_blacksmith")].Dialog.Filename.Groupdialog = "Gunsmith_fetch.c";
				makearef(store, Stores[PIRATES_STORE]);
				DeleteAttribute(store,"blacksmith");
				store.gunsmith = "Arne Saknussem";
			}
			// JRH&Levis: Change the Nevis blacksmith to gunsmith <--

			// RM -->
			/*SetNationRelation2MainCharacter(ENGLAND, RELATION_ENEMY);
			SetNationRelation2MainCharacter(FRANCE, RELATION_ENEMY);
			SetNationRelation2MainCharacter(SPAIN, RELATION_ENEMY);
			SetNationRelation2MainCharacter(PORTUGAL, RELATION_ENEMY);
			SetNationRelation2MainCharacter(PIRATE, RELATION_FRIEND);
			SetNationRelation2MainCharacter(HOLLAND, RELATION_ENEMY);*/
			/*LeaveService(PChar, ENGLAND, false);
			LeaveService(PChar, FRANCE, false);
			LeaveService(PChar, SPAIN, false);
			LeaveService(PChar, HOLLAND, false);
			LeaveService(PChar, PORTUGAL, false);
			if(GetRMRelation(GetMainCharacter(), PIRATE) < REL_AMNESTY) SetRMRelation(GetMainCharacter(), PIRATE, REL_AMNESTY);*/
			// RM <--
		break;

		// PB: Reset Back to Normal -->
		case "pirateend":
			makeref(period, Periods[GetCurrentPeriod()]);
			DeleteAttribute(period, "Nations.OfficialName.Pirate");

			// Tortuga: Not in Jack Sparrow Storyline
			if (sti(GetStorylineVar(FindCurrentStoryline(), "JACK_SPARROW")) != 1)
			{
				if (GetTownNation("Tortuga") == PIRATE)
				{
					CaptureTownForNation("Tortuga", FRANCE);
					SetTownName("Tortuga", "La Tortue");
					Preprocessor_Delete("Tortuga");
					Preprocessor_Save("Tortuga", FindTownName("Tortuga"));
				}
				Characters[GetCharacterIndex("Bertrand Ogeron")].Dialog.Filename = "Bertrand Ogeron_dialog.c";
				Characters[GetCharacterIndex("Bertrand Ogeron")].Dialog.CurrentNode = "First time";
				DeleteAttribute(CharacterFromID("Bertrand Ogeron"), "Dialog.Filename.GroupDialog");
			}

			// Turks: Not in Jack Sparrow Storyline
			if (sti(GetStorylineVar(FindCurrentStoryline(), "JACK_SPARROW")) != 1)
			{ 
				Characters[GetCharacterIndex("Dante Siciliano")].Dialog.Filename = "Nathan Kell (Gov)_dialog.c";
				Characters[GetCharacterIndex("Dante Siciliano")].Dialog.CurrentNode = "First time";
				DeleteAttribute(CharacterFromID("Dante Siciliano"), "Dialog.Filename.GroupDialog");
			}

			// Nevis: Not in Standard Storyline
			if (sti(GetStorylineVar(FindCurrentStoryline(), "START_MIN_LEVEL")) != 1)
			{
				Characters[GetCharacterIndex("Isenbrandt Jurcksen")].Dialog.Filename = "Isenbrandt Jurcksen_dialog.c";
				Characters[GetCharacterIndex("Isenbrandt Jurcksen")].Dialog.CurrentNode = "First time";
				DeleteAttribute(CharacterFromID("Isenbrandt Jurcksen"), "Dialog.Filename.GroupDialog");
			}

			// JRH&Levis: Change the Nevis blacksmith to gunsmith -->
			if (ENABLE_WEAPONSMOD)
			{
				// Modify the reload icon
				Locations[FindLocation("QC_town_exit")].reload.l6.go = "QC_blacksmith";
				Locations[FindLocation("QC_Gunsmith")].id.label = "Pirate Blacksmith";
				Locations[FindLocation("QC_Gunsmith")].id = "QC_blacksmith";
				Characters[GetCharacterIndex("QC_blacksmith")].Location = "QC_blacksmith";
				
				// Modify the Fast Travel icon
				makearef(curTable,objFastReloadTable.table.QC);
				curTable.l6.pic = FRP_BLACKSMITH;
				curTable.l6.tex = FRT_BLACKSMITH;
				curTable.l6.note = FRN_BLACKSMITH;
				curTable.l6.location = "QC_blacksmith";
				RecalculateJumpTable();
				
				// Give him the alternate dialog
				Characters[GetCharacterIndex("QC_blacksmith")].Dialog.Filename = "Blacksmith5_dialog.c";
				
				// And enable the correct fetch quests
				Characters[GetCharacterIndex("QC_blacksmith")].Dialog.Filename.Groupdialog = "Blacksmith_fetch.c";
				makearef(store, Stores[PIRATES_STORE]);
				DeleteAttribute(store,"gunsmith");
				store.blacksmith = "Arne Saknussem";
			}
			// JRH&Levis: Change the Nevis blacksmith to gunsmith <--
		break;
		// PB: Reset Back to Normal <--


// KK ----------------- Resurrection Event -------------------------------------
		case "PreResurrection":
			if (Resurrectingofficiant.id == "Eleuthera_officiant")
			{
				ChangeCharacterAddressGroup(ResurrectingOfficiant, ResurrectingOfficiant.resurrection.location, "goto", "stab");
				PChar.quest.ResurrectionEvent.win_condition.l1 = "location";
				PChar.quest.ResurrectionEvent.win_condition.l1.location = ResurrectingOfficiant.resurrection.location;
				PChar.quest.ResurrectionEvent.win_condition = "ResurrectionEvent";
				DoReloadCharacterToLocation(ResurrectingOfficiant.resurrection.location, "goto", "goto3");
			}
			else
			{
				ChangeCharacterAddressGroup(ResurrectingOfficiant, ResurrectingOfficiant.resurrection.location, "goto", "goto3");
				PChar.quest.ResurrectionEvent.win_condition.l1 = "location";
				PChar.quest.ResurrectionEvent.win_condition.l1.location = ResurrectingOfficiant.resurrection.location;
				PChar.quest.ResurrectionEvent.win_condition = "ResurrectionEvent";
				DoReloadCharacterToLocation(ResurrectingOfficiant.resurrection.location, "goto", "goto2");
			}
			Locations[FindLocation(ResurrectingOfficiant.resurrection.location)].reload.l1.disable = 1;
		break;

		case "ResurrectionEvent":
			Log_SetStringToLog(TranslateString("","You regain consciousness after a long feverish sleep"));
			PlaySound("AMBIENT\SHOP\sigh2.wav");
			if (GetNationRelation2MainCharacter(GetCurrentLocationNation()) != RELATION_ENEMY)
				LAi_QuestDelay("ResurrectionEvent_BlazeWakes", 0.0);
			else
				LAi_QuestDelay("ResurrectionEvent_BlazeMustEscape", 0.0);
		break;

		case "ResurrectionEvent_BlazeWakes":
			LAi_SetActorType(PChar);
			LAi_SetActorType(ResurrectingOfficiant);
			LAi_ActorFollow(PChar, ResurrectingOfficiant, "", 1.5);
			LAi_ActorFollow(ResurrectingOfficiant, PChar, "ResurrectionEvent_DialogStart", 1.5);
		break;

		case "ResurrectionEvent_DialogStart":
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, ResurrectingOfficiant);
			LAi_ActorDialog(ResurrectingOfficiant, PChar, "", 1.0, 1.0);
			LAi_SetPlayerType(PChar);
		break;

		case "ResurrectionEvent_OfficiantLeaves":
			LAi_SetActorType(ResurrectingOfficiant);
			LAi_ActorGoToLocation(ResurrectingOfficiant, "reload", "reload1", ResurrectingOfficiant.tavern.location, ResurrectingOfficiant.tavern.location.group, ResurrectingOfficiant.tavern.location.locator, "ResurrectionEvent_OfficiantLeftTavernUpstairs", 10.0);
		break;

		case "ResurrectionEvent_OfficiantLeftTavernUpstairs":
			LAi_SetWaitressType(ResurrectingOfficiant);
			Locations[FindLoadedLocation()].reload.l1.disable = 0;
			DeleteAttribute(PChar, "NoSave");
			DeleteAttribute(ResurrectingOfficiant, "isResurrecting");
		break;

		case "ResurrectionEvent_BlazeMustEscape":
			ResurrectingOfficiant.Dialog.CurrentNode = "Blaze_must_escape";
			LAi_SetActorType(PChar);
			LAi_SetActorType(ResurrectingOfficiant);
			LAi_ActorTurnToCharacter(PChar, ResurrectingOfficiant);
			LAi_ActorFollow(ResurrectingOfficiant, PChar, "ResurrectionEvent_DialogStart", 1.5);
		break;

//	----------- Safe Port Leave ------------------------------------------------

		case "Safe_port_leave":
			iForceDetectionFalseFlag = 0;
			HoistFlag(sti(PChar.quest.Safe_Port_Leave.flag)); // GR: Restore original flag after false flag
			DeleteQuestAttribute("Safe_Port_Leave.flag");
		break;

//	----------- Colony Capture -------------------------------------------------

		case "ColonyCapture_Capture":
			if (CheckAttribute(PChar, "colony_capture")) {
				CaptureColony(PChar.colony_capture.town, sti(PChar.colony_capture.nation));
				DeleteAttribute(PChar, "colony_capture");
			}
		break;

		case "ColonyCapture_ContinueDialog":
			if (CheckAttribute(PChar, "colony_capture")) {
				NPChar = GetCharacter(sti(PChar.colony_capture.govidx));
				NPChar.Dialog.CurrentNode = "First time";
				NPChar.Dialog.TempNode = "First time";
				LAi_SetActorType(PChar);
				LAi_ActorDialog(PChar, NPChar, "Surrendered_Captain_Dialog", 60.0, 0);	// surrender dialog
			}
		break;

		case "ColonyCapture_TownCommandant_1":
			if (CheckAttribute(PChar, "colony_capture")) {
				NPChar = GetCharacter(sti(PChar.colony_capture.govidx));
				PlaceCharacter(NPChar, "goto");
			}
		break;

		case "ColonyCapture_TownCommandant_2":
			if (CheckAttribute(PChar, "colony_capture")) {
				NPChar = GetCharacter(sti(PChar.colony_capture.govidx));
				LAi_SetActorType(PChar);
				LAi_SetActorType(NPChar);
				Lai_ActorFollow(pchar, NPChar, "ColonyCapture_TownCommandant_3", 2.0);
			}
		break;

		case "ColonyCapture_TownCommandant_3":
			if (CheckAttribute(PChar, "colony_capture")) {
				NPChar = GetCharacter(sti(PChar.colony_capture.govidx));
				DeleteAttribute(PChar, "colony_capture");
				LAi_ActorWaitDialog(pchar, NPChar);
				LAi_SetActorType(NPChar);
				LAi_ActorDialog(NPChar, PChar, "player_back", 10.0, 1.0);
			}
		break;

//	----------- Boarding & Mutiny ----------------------------------------------
		case "Abordage_Quest":
			PChar.quest.Abordage_End.win_condition.l1 = "Group_Death";
			PChar.quest.Abordage_End.win_condition.l1.group = LAI_GROUP_BRDENEMY;
			PChar.quest.Abordage_End.win_condition = "Abordage_End";
		break;

		case "Abordage_End":
			if (bMutinyDeckStarted) {
				PostEvent("LAi_event_mutiny_EnableReload", 1000.0);
			} else {
				if (LAi_IsBoardingProcess()) PostEvent("LAi_event_boarding_EnableReload", 1000.0);
			}
		break;
// <-- KK

		case "reset_abordage":
			//log_setStringToLog("Abordage characters was reseted");
			pchar.quest.abordage = 0;
		break;

		case "DPFader": DPDoFade(); break;
	
		case "stand_up":
			LAi_Fade("stand_up1", "stand_up2");
			LAi_SetPlayerType(Pchar); 
		break;
	
		case "stand_up1":
// NK -->
			if(CheckAttribute(pchar, "quest.Attwood1.leave"))
			{
				DeleteAttribute(pchar, "quest.Attwood1.leave");
				ChangeCharacterAddressGroup(CharacterFromID("Jack Greenfield"), "none", "sit", "sit10");
				ChangeCharacterAddressGroup(CharacterFromID("Martin Warner"), "none", "sit", "sit5");
			}
// NK <--
			TeleportCharacterToLocator(Pchar, "goto", "goto20");
			LAi_ActorSetStayMode(Pchar);
		break;
	
		case "stand_up2":
			LAi_SetPlayerType(Pchar); 
		break;

//============================================================================
// SIDE QUESTS
//============================================================================

//------------------
//Tortuga Atmosphere
//------------------

		case "Tortuga_start":
			//JRH -->
			if(CheckAttribute(Pchar,"quest.Tortuga_ships") && Pchar.quest.Tortuga_ships == "5")
			{

			}
			else
			{
				if(CheckAttribute(Pchar,"quest.Tortuga_ships") && Pchar.quest.Tortuga_ships == "4")
				{
					Pchar.quest.Tortuga_ships = "5";
		
					GiveShip2Character(characterFromID("Tor_soldier_3"),"MerchantPinnace","Victory",-1,PIRATE,true,true);
					setCharacterShipLocation(characterFromID("Tor_soldier_3"), "Tortuga_port");
				}
				else
				{
					if(CheckAttribute(Pchar,"quest.Tortuga_ships") && Pchar.quest.Tortuga_ships == "2")
					{
						Pchar.quest.Tortuga_ships = "4";

						GiveShip2Character(characterFromID("Tor_patrol_1"),"SchoonerXebec","Victory",-1,PIRATE,true,true);
						GiveShip2Character(characterFromID("Tor_patrol_2"),"FR_Sloop","Victory",-1,PIRATE,true,true);
						setCharacterShipLocation(characterFromID("Tor_patrol_1"), "Tortuga_port");
						setCharacterShipLocation(characterFromID("Tor_patrol_2"), "Tortuga_port");
					}
					else
					{
						Pchar.quest.Tortuga_ships = "2";

						GiveShip2Character(characterFromID("Tor_soldier_1"),"Sloop2","Victory",-1,PIRATE,true,true);
						GiveShip2Character(characterFromID("Tor_soldier_2"),"PiratBrig50","Victory",-1,PIRATE,true,true);
						setCharacterShipLocation(characterFromID("Tor_soldier_1"), "Tortuga_port"); 	
						setCharacterShipLocation(characterFromID("Tor_soldier_2"), "Tortuga_port");	
					}
				}
			}
			//<-- JRH

			PChar.quest.Tortuga_atmosphere.win_condition.l1 = "location";
			PChar.quest.Tortuga_atmosphere.win_condition.l1.character = PChar.id;
			PChar.quest.Tortuga_atmosphere.win_condition.l1.location = "Tortuga_port";
			PChar.quest.Tortuga_atmosphere.win_condition = "Tortuga_atmosphere";
			pchar.quest.Tortuga_atmosphere.skip = "yes";
		break;

		case "Tortuga_atmosphere":
			Pchar.quest.Tortuga_start.win_condition.l1 = "ExitFromLocation";
			Pchar.quest.Tortuga_start.win_condition.l1.location = "Tortuga_port";
			Pchar.quest.Tortuga_start.win_condition = "Tortuga_start";
			pchar.quest.Tortuga_start.skip = "yes";

			port = &locations[FindLocation("Tortuga_port")];
			if(GetAttribute(pchar, "vcskip") < 1 && GetAttribute(port, "vcskip") < 1)
			{
				if(!CheckAttribute(PChar,"scarlett"))
				{
					sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Towngirl7", "goto", LAi_FindRandomLocator("goto"));
					LAi_SetImmortal(sld, true);
					sld.dialog.filename = "Dame_dialog.c";
					sld.id = "dame1";
					sld.name = TranslateString("Scarlett", "");
					sld.lastname = "";
					LAi_SetCitizenType(characterFromID("dame1"));

					sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Towngirl1_1", "goto", LAi_FindRandomLocator("goto"));
					LAi_SetImmortal(sld, true);
					sld.dialog.filename = "Dame_dialog.c";
					sld.id = "dame2";
					sld.name = TranslateString("Giselle","");
					sld.lastname = "";
					LAi_SetCitizenType(characterFromID("dame2"));

					if (PChar.model == "Anamaria" || GetMySimpleOldName(PChar) == "Anamaria")
					{
						sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Danblack", "goto", LAi_FindRandomLocator("goto"));
						sld.name = TranslateString("Harriett", "");
						sld.lastname = "";
					}
					else
					{
						sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Anamaria", "goto", LAi_FindRandomLocator("goto"));
						sld.name = TranslateString("Anamaria","");
						sld.lastname = "";
					}
					LAi_SetImmortal(sld, true);
					sld.dialog.filename = "Dame_dialog.c";
					sld.id = "dame3";
					LAi_SetCitizenType(characterFromID("dame3"));
				}
				else
				{
					sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, GetRandomModelForTypeSex(-1, "women", "woman"), "goto", LAi_FindRandomLocator("goto"));
					LAi_SetImmortal(sld, true);
					sld.dialog.filename = "Dame_dialog.c";
					sld.id = "dame1";
					LAi_SetCitizenType(characterFromID("dame1"));

					sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, GetRandomModelForTypeSex(-1, "women", "woman"), "goto", LAi_FindRandomLocator("goto"));
					LAi_SetImmortal(sld, true);
					sld.dialog.filename = "Dame_dialog.c";
					sld.id = "dame2";
					LAi_SetCitizenType(characterFromID("dame2"));

					sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, GetRandomModelForTypeSex(-1, "women", "woman"), "goto", LAi_FindRandomLocator("goto"));
					LAi_SetImmortal(sld, true);
					sld.dialog.filename = "Dame_dialog.c";
					sld.id = "dame3";
					LAi_SetCitizenType(characterFromID("dame3"));
				}

				sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, GetRandomModelForTypeNation(1, "Captains", PIRATE), "goto", LAi_FindRandomLocator("goto"));
				LAi_SetImmortal(sld, true);
				LAi_group_MoveCharacter(sld, "bagarreur");

				sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, GetRandomModelForTypeNation(1, "Captains", PIRATE), "goto", LAi_FindRandomLocator("goto"));
				LAi_SetImmortal(sld, true);
				LAi_group_MoveCharacter(sld, "bagarreur1");
				LAi_group_FightGroups("bagarreur", "bagarreur1", true);

				sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, GetRandomModelForTypeNation(1, "Captains", PIRATE), "goto", LAi_FindRandomLocator("goto"));
				LAi_SetImmortal(sld, true);
				LAi_group_MoveCharacter(sld, "bagarreur2");

				sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, GetRandomModelForTypeNation(1, "Captains", PIRATE), "goto", LAi_FindRandomLocator("goto"));
				LAi_SetImmortal(sld, true);
				LAi_group_MoveCharacter(sld, "bagarreur3");
				LAi_group_FightGroups("bagarreur2", "bagarreur3", true);

				sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, GetRandomModelForTypeNation(1, "Captains", PIRATE), "goto", LAi_FindRandomLocator("goto"));
				LAi_SetImmortal(sld, true);
				LAi_group_MoveCharacter(sld, "bagarreur4");

				sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, GetRandomModelForTypeNation(1, "Captains", PIRATE), "goto", LAi_FindRandomLocator("goto"));
				LAi_SetImmortal(sld, true);
				LAi_group_MoveCharacter(sld, "bagarreur5");
				LAi_group_FightGroups("bagarreur4", "bagarreur5", true);

				if(rand(100) < 50)
				{
					string SkelLocator = LAi_FindRandomLocator("goto");
					sld = LAi_CreateFantomCharacter(false, 0, true, false, 0.25, GetRandomModelForType(-1,"Monks"), "goto", SkelLocator);
					LAi_SetImmortal(sld, true);
					sld.id = "bagarreur6";
					sld.name = TranslateString("Scared Monk", "");
					sld.lastname = "";
					LAi_SetActorType(characterFromID("bagarreur6"));
					LAi_ActorRunToLocation(characterFromID("bagarreur6"), "reload", "reload7_back", "none", "", "", "skeleton_leaves", 0.0);

					sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, GetRandomModelForType(-1,"Skeletons"), "goto", SkelLocator);
					LAi_SetImmortal(sld, true);
					sld.id = "bagarreur7";
					sld.name = TranslateString("Cursed Skeleton", "");
					sld.lastname = "";
					LAi_SetWarriorType(characterFromID("bagarreur7"));
					LAi_warrior_SetCommander(CharacterFromID("bagarreur7"), CharacterFromID("bagarreur6"));
				}
			}
		break;

		case "skeleton_leaves":
			LAi_SetActorType(characterFromID("bagarreur7"));
			LAi_ActorGoToLocation(characterFromID("bagarreur7"), "reload", LAi_FindRandomLocator("reload"), "None", "reload", "", "", -1);
		break;

		case "Dame_1":
			LAi_ActorGoToLocation(TortugaDame1, "reload", LAi_FindRandomLocator("reload"), "None", "reload", "", "", -1);

			switch(TortugaDame1.id)
			{
				case "dame1":
					switch(rand(1))
					{
						case 0: TortugaDame2 = characterFromID("dame2"); TortugaDame3 = characterFromID("dame3"); break;
						case 1: TortugaDame2 = characterFromID("dame3"); TortugaDame3 = characterFromID("dame2"); break;
					}
				break;

				case "dame2":
					switch(rand(1))
					{
						case 0: TortugaDame2 = characterFromID("dame1"); TortugaDame3 = characterFromID("dame3"); break;
						case 1: TortugaDame2 = characterFromID("dame3"); TortugaDame3 = characterFromID("dame1"); break;
					}
				break;

				case "dame3":
					switch(rand(1))
					{
						case 0: TortugaDame2 = characterFromID("dame1"); TortugaDame3 = characterFromID("dame2"); break;
						case 1: TortugaDame2 = characterFromID("dame2"); TortugaDame3 = characterFromID("dame1"); break;
					}
				break;
			}

			LAi_SetActorType(TortugaDame2);
			LAi_ActorFollow(TortugaDame2, PChar, "Dame_2", 100.5);
			TortugaDame2.dialog.currentnode = "begin_2";
			LAi_SetActorType(TortugaDame3);
			LAi_ActorFollow(TortugaDame3, PChar, "Dame_2", 100.5);
			TortugaDame3.dialog.currentnode = "begin_2";
		break;

		case "Dame_2":
			LAi_ActorWaitDialog(PChar, TortugaDame2);
			LAi_ActorDialog(TortugaDame2, PChar, "", 1.0, 1.0);

			LAi_ActorWaitDialog(PChar, TortugaDame3);
			LAi_ActorDialog(TortugaDame3, PChar, "", 1.0, 1.0);
		break;

		case "Dame_3":
			LAi_ActorGoToLocation(TortugaDame2, "reload", LAi_FindRandomLocator("reload"), "None", "reload", "", "", -1);

			switch(TortugaDame1.id)
			{
				case "dame1":
					switch(TortugaDame2.id)
					{
						case "dame2": TortugaDame3 = characterFromID("dame3"); break;
						case "dame3": TortugaDame3 = characterFromID("dame2"); break;
					}
				break;

				case "dame2":
					switch(TortugaDame2.id)
					{
						case "dame1": TortugaDame3 = characterFromID("dame3"); break;
						case "dame3": TortugaDame3 = characterFromID("dame1"); break;
					}
				break;

				case "dame3":
					switch(TortugaDame2.id)
					{
						case "dame1": TortugaDame3 = characterFromID("dame2"); break;
						case "dame2": TortugaDame3 = characterFromID("dame1"); break;
					}
				break;
			}

			LAi_SetActorType(TortugaDame3);
			LAi_ActorFollow(TortugaDame3, PChar, "Dame_4", 100.5);
			TortugaDame3.dialog.currentnode = "begin_4";
		break;

		case "Dame_4":
			LAi_ActorWaitDialog(PChar, TortugaDame3);
			LAi_ActorDialog(TortugaDame3, PChar, "", 1.0, 1.0);
		break;

		case "Dame_5":
			LAi_ActorGoToLocation(TortugaDame3, "reload", LAi_FindRandomLocator("reload"), "None", "reload", "", "", -1);
		break;

		case "Muerte_restore":
			PChar.quest.Muerte_start.win_condition.l1 = "location";
			PChar.quest.Muerte_start.win_condition.l1.character = PChar.id;
			PChar.quest.Muerte_start.win_condition.l1.location = "Tortuga_tavern";
			PChar.quest.Muerte_start.win_condition = "Muerte_start";
		break;

		case "Muerte_start":
			Pchar.quest.Muerte_restore.win_condition.l1 = "ExitFromLocation";
			Pchar.quest.Muerte_restore.win_condition.l1.location = "Tortuga_tavern";
			Pchar.quest.Muerte_restore.win_condition = "Muerte_restore";
			PChar.quest.Muerte_restore.skip = "yes";
			if(!CheckAttribute(PChar,"gibbs"))
			{
				sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "bocman5", "sit", LAi_FindRandomLocator("sit"));
				LAi_SetImmortal(sld, true);
				sld.dialog.filename = "Mr. Gibbs_dialog.c";
				sld.greeting = "Gr_Mr. Gibbs";
				sld.money = rand(100);
				sld.id = "Mr. Gibbs";
				sld.name = TranslateString("","Joshamee");
				sld.lastname = TranslateString("","Gibbs");
				sld.reputation = REPUTATION_GOOD;
				sld.nation = PIRATE;
				sld.sex = "man";
				sld.grsex = "man";
				sld.quest.officertype = OFFIC_TYPE_BOATSWAIN;
				sld.quest.officerprice = 0;//PB
				LAi_SetSitType(sld);
				LAi_group_MoveCharacter(sld, "TORTUGA_CITIZENS");
				LAi_SetImmortal(sld, true);
			}
		break;

		// GR: Mary Wood in Tortuga tavern reverts to normal AI group when you leave tavern so she doesn't keep attacking
		case "Reset_Mary_Wood":
			LAi_group_MoveCharacter(CharacterFromID("Mary Wood"), "TORTUGA_CITIZENS");
		break;

		// PB: Shotgun Easter Egg -->
		case "clint_eastwood":
			LAi_SetActorType(CharacterFromID("Clint Eastwood"));
			LAi_ActorDialog(CharacterFromID("Clint Eastwood"), PChar, "", 0.0, 0.0);
		break;
		// PB: Shotgun Easter Egg <--

		// PB: Sword of Triton -->
		case "blackbeard_shore":
			LAi_SetActorType(CharacterFromID("Blackbeard"));
			LAi_ActorDialog(CharacterFromID("Blackbeard"), PChar, "", 0.0, 0.0);
		break;
		// PB: Sword of Triton <--

		// PB: Relations Tutorial -->
		case "relationbook":
			SetQuestHeader("relations_book");
			AddQuestRecord("relations_book", 1);
			if (HasMerchantPassport(PChar)) AddQuestRecord("relations_book", 2);
			PChar.quest.relation_tutorial = 1;
			PChar.quest.relationbook_timeout.win_condition.l1 = "Timer";
			PChar.quest.relationbook_timeout.win_condition.l1.date.day = GetAddingDataDay(0, 1, 0);
			PChar.quest.relationbook_timeout.win_condition.l1.date.month = GetAddingDataMonth(0, 1, 0);
			PChar.quest.relationbook_timeout.win_condition.l1.date.year = GetAddingDataYear(0, 1, 0);
			PChar.quest.relationbook_timeout.win_condition = "relationbook_timeout";
		break;

		case "relationbook_timeout":
			CloseQuestHeader("relations_book");
			DeleteQuestHeader("relations_book");
			PChar.quest.Got_Relation_Book.over = "yes";
		break;

		case "Got_Relation_Book":
			if (!CheckActiveQuest("relations_book")) SetQuestHeader("relations_book");
			AddQuestRecord("relations_book", 3);
			PChar.quest.relation_tutorial = 1;
			PChar.quest.relationbook_timeout.over = "yes";
			PChar.Got_Relation_Book = true;
			PChar.quest.read_relation_book_timeout.win_condition.l1 = "Timer";
			PChar.quest.read_relation_book_timeout.win_condition.l1.date.day = GetAddingDataDay(0, 1, 0);
			PChar.quest.read_relation_book_timeout.win_condition.l1.date.month = GetAddingDataMonth(0, 1, 0);
			PChar.quest.read_relation_book_timeout.win_condition.l1.date.year = GetAddingDataYear(0, 1, 0);
			PChar.quest.read_relation_book_timeout.win_condition = "Read_Relation_Book";
		break;

		case "Read_Relation_Book":
			CloseQuestHeader("relations_book");
			PChar.quest.relation_tutorial = 1;
		break;
		// PB: Relations Tutorial <--

		// GR: Pirate alternative to relations tutorial -->
		case "piratebook":
			SetQuestHeader("pirate_book");
			AddQuestRecord("pirate_book", 1);
			PChar.quest.pirate_tutorial = 1;
			PChar.quest.piratebook_timeout.win_condition.l1 = "Timer";
			PChar.quest.piratebook_timeout.win_condition.l1.date.day = GetAddingDataDay(0, 1, 0);
			PChar.quest.piratebook_timeout.win_condition.l1.date.month = GetAddingDataMonth(0, 1, 0);
			PChar.quest.piratebook_timeout.win_condition.l1.date.year = GetAddingDataYear(0, 1, 0);
			PChar.quest.piratebook_timeout.win_condition = "piratebook_timeout";
		break;

		case "piratebook_timeout":
			CloseQuestHeader("pirate_book");
			DeleteQuestHeader("pirate_book");
			PChar.quest.Got_pirate_Book.over = "yes";
		break;

		case "Got_Pirate_Book":
			if (!CheckActiveQuest("pirate_book")) SetQuestHeader("pirate_book");
			AddQuestRecord("pirate_book", 2);
			PChar.quest.pirate_tutorial = 1;
			PChar.quest.piratebook_timeout.over = "yes";
			PChar.Got_Pirate_Book = true;
		break;

		case "Read_Pirate_Book":
			CloseQuestHeader("pirate_book");
			PChar.quest.pirate_tutorial = 1;
		break;
		// GR: Pirate alternative to relations tutorial <--

		case "oxbay_port_earthquake":
			// PB: Move this here, so the buildings are gone only AFTER you entered the map sailing mode
			port = &Locations[FindLocation("Oxbay_port")];    // ccc Feb06
			if(CheckAttribute(port,"building") ) DeleteAttribute(port,"building");    // ccc Feb06
		break;

//============================================================================
// OTHER
//============================================================================

// Levis -->
		case "get_shot_gun_mode":
			globalSGMode = true;
			if(FREE_CAMERA)		locCameraCurMode = LOCCAMERA_TRANS; // Needed to return properly
			PlaySound("OBJECTS\duel\reload1.wav");
		break;
		
		case "get_sword_ready":
			LAi_SetFightMode(Pchar, true);
		break;
// Levis <---
//---------------------------------------------------------------------------------
		case "place_LR_BT_on_back":
			GunCurCharge = LAi_GetCharacterRelCharge(Pchar); // Levis
			weapon.model = "LongRifle_BT_back";
			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE );
			EquipCharacterByItem(Pchar, "LongRifle_BT");
			PlaySound("PEOPLE\clothes1.wav");
		break;

		case "place_LR_CT_on_back":
			GunCurCharge = LAi_GetCharacterRelCharge(Pchar); // Levis
			weapon.model = "LongRifle_CT_back";
			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE );
			EquipCharacterByItem(Pchar, "LongRifle_CT");
			Pchar.chr_ai.charge = GunCurCharge; // Levis
			PlaySound("PEOPLE\clothes1.wav");
		break;

		case "place_LR_WT_on_back":
			GunCurCharge = LAi_GetCharacterRelCharge(Pchar); // Levis
			weapon.model = "LongRifle_WT_back";
			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE );
			EquipCharacterByItem(Pchar, "LongRifle_WT");
			Pchar.chr_ai.charge = GunCurCharge; // Levis
			PlaySound("PEOPLE\clothes1.wav");
		break;
	/*
		case "place_LR_C_on_back":
			GunCurCharge = LAi_GetCharacterRelCharge(Pchar); // Levis
			weapon.model = "LongRifle_C_back";
			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE );
			EquipCharacterByItem(Pchar, "LongRifle_C");
			Pchar.chr_ai.charge = GunCurCharge; // Levis
			PlaySound("PEOPLE\clothes1.wav");
		break;

		case "place_LR_C_on_hip":
			GunCurCharge = LAi_GetCharacterRelCharge(Pchar); // Levis
			weapon.model = "LongRifle_C";
			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE );
			EquipCharacterByItem(Pchar, "LongRifle_C");
			Pchar.chr_ai.charge = GunCurCharge; // Levis
			PlaySound("PEOPLE\clothes1.wav");
		break;
	*/
	/*
		case "place_LR_W_on_back":
			GunCurCharge = LAi_GetCharacterRelCharge(Pchar); // Levis
			weapon.model = "LongRifle_W_back";
			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE );
			EquipCharacterByItem(Pchar, "LongRifle_W");
			Pchar.chr_ai.charge = GunCurCharge; // Levis
			PlaySound("PEOPLE\clothes1.wav");
		break;

		case "place_LR_W_on_hip":
			GunCurCharge = LAi_GetCharacterRelCharge(Pchar); // Levis
			weapon.model = "LongRifle_W";
			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE );
			EquipCharacterByItem(Pchar, "LongRifle_W");
			Pchar.chr_ai.charge = GunCurCharge; // Levis
			PlaySound("PEOPLE\clothes1.wav");
		break;
	*/
//---------------------------------------------------------------------------------
		case "equip_new_arrow":
			PlaySound("OBJECTS\duel\arrow.wav");
			EquipCharacterByItem(pchar, "bladearrows");
		break;

		case "off_equip_new_arrow":
			PlaySound("OBJECTS\duel\arrow.wav");
			if(CheckAttribute(Pchar, "off_bow")) NPChar = characterFromID(Pchar.off_bow);
			GiveItem2Character(NPChar, "bladearrows");
			EquipCharacterByItem(NPChar, "bladearrows");
		break;

		case "NPC_equip_new_arrow":
			PlaySound("OBJECTS\duel\arrow.wav");
			if(CheckAttribute(Pchar, "npc_bow")) NPChar = characterFromID(Pchar.npc_bow);
			GiveItem2Character(NPChar, "bladearrows");
			EquipCharacterByItem(NPChar, "bladearrows");
		break;

		case "indian_arrows_equip_check":
			if(IsEquipCharacterByItem(Pchar, "pistolbow"))
			{
				//ok
			}
			else RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);	
		break;

		case "indian_pistols_equip_check":
			if(IsEquipCharacterByItem(Pchar, "bladearrows")
			|| IsEquipCharacterByItem(Pchar, "shield_hand") || IsEquipCharacterByItem(Pchar, "shield_back"))
			{
				RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
				if(!CheckCharacterItem(Pchar, "bladeX4")) GiveItem2Character(Pchar, "bladeX4");
				EquipCharacterByItem(Pchar, "bladeX4");
			}
		break;

		case "indian_shield_equip_check":
			if(IsEquipCharacterByItem(Pchar, "pistolbow") || IsEquipCharacterByItem(Pchar, "blowgun"))
			{
				//only these 2 go well with the shield
			}
			else RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
		break;

		case "cauterization_smoke":
			GetCharacterPos(Pchar, &x, &y, &z);
			CreateParticleSystem("gunfire_black" , x, y+1.5, z, 0.0, 0.0, 0.0, sti(20) );//smoke puff
		break;

		case "cauterization_sound":
			if(Pchar.sex == "man") {PlaySound("OBJECTS\VOICES\DEAD\male\dead6.wav");}
			else{PlaySound("OBJECTS\VOICES\DEAD\female\dead_wom1.wav");}
		break;

		case "pchar_curare":
			if(CheckAttribute(Pchar, "chr_ai.curare"))
			{
				LAi_ApplyCharacterDamage(Pchar, 1);

				LAi_QuestDelay("pchar_curare", 10.0);
			}
		break;

		case "shield_stopped_dart":
			PlaySound("OBJECTS\DUEL\arrow_shield.wav");
		break;

		case "shield_stopped_arrow":
			PlaySound("OBJECTS\DUEL\arrow_shield.wav");
			PlaySound("OBJECTS\DUEL\arrow_shield.wav");
		break;

		case "pchar_rocket_hit":
			GetCharacterPos(Pchar, &x, &y, &z);
			CreateParticleSystem("canfire" , x, y, z, 5.1, 4.0, 0.0, sti(20) );		//nr 18
			CreateParticleSystem("blast" , x, y, z, 5.1, 4.0, 0.0, sti(20) );		//nr 35
			CreateParticleSystem("blast_dirt_small" , x, y, z, 5.1, 4.0, 0.0, sti(20) );	//nr 31
			CreateParticleSystem("splinters" , x, y+1.2, z, 5.1, 4.0, 0.0, sti(20) );
			CreateParticleSystem("splinters2" , x, y+1.2, z, 5.1, 4.0, 0.0, sti(20) );

			PlaySound("OBJECTS\DUEL\pistol_mtoon.wav");
		break;

		case "NPC_rocket_hit":
			NPChar = characterFromID(Pchar.npc_rocket);
			GetCharacterPos(NPchar, &u, &v, &w);
			CreateParticleSystem("canfire" , u, v, w, 5.1, 4.0, 0.0, sti(20) );		//nr 18
			CreateParticleSystem("blast" , u, v, w, 5.1, 4.0, 0.0, sti(20) );		//nr 35
			CreateParticleSystem("blast_dirt_small" , u, v, w, 5.1, 4.0, 0.0, sti(20) );	//nr 31
			CreateParticleSystem("splinters" , u, v+1.2, w, 5.1, 4.0, 0.0, sti(20) );
			CreateParticleSystem("splinters2" , u, v+1.2, w, 5.1, 4.0, 0.0, sti(20) );
		
			PlaySound("OBJECTS\DUEL\pistol_mtoon.wav");
		break;
//JRH
		case "NPC_flaming_hit":
			NPChar = characterFromID(Pchar.npc_flaming);
			weaponID = GetCharacterEquipByGroup(NPchar,BLADE_ITEM_TYPE);
		//	Items_FindItem(weaponID, &weapon); // PB: This line does not do anything?

			GetCharacterPos(NPchar, &u, &v, &w);

			PlaySound("NATURE\fireplace3.wav");
			CreateParticleSystem("rocket_fire" , u, v+1.2, w, 5.1, 4.0, 0.0, sti(20) );
			CreateParticleSystem("MMcancloud2" , u, v, w, 5.1, 4.0, 0.0, sti(20) );		//nr 14
			CreateParticleSystem("MMcancloud2" , u, v, w, 5.1, 4.0, 0.0, sti(20) );		//nr 14

			LAi_QuestDelay("NPC_flaming_hit1", 1.0);
	
			if(IsMainCharacter(NPChar) || IsOfficer(NPChar))
			{
				//don't make them staytype
			}
			else
			{
				if(!LAi_IsFightMode(NPChar))
				{
					LAi_SetStayType(NPChar);

					if(weaponID != "")
					{
						LAi_QuestDelay("NPC_flaming_hit4", 2.0);
					}
					else
					{
						LAi_QuestDelay("NPC_flaming_hit5", 2.0);
					}
				}
			}
		break;

		case "NPC_flaming_hit1":
			NPChar = characterFromID(Pchar.npc_flaming);

			if(IsMainCharacter(NPChar))
			{
				if(NPChar.sex == "man") {PlaySound("OBJECTS\Voices\dead\male\dead6.wav");}
				else{PlaySound("OBJECTS\Voices\dead\female\dead_wom1.wav");}
			}
			else
			{
				if(NPChar.sex == "man") {PlaySound("OBJECTS\Voices\dead\male\Death_NPC_08.wav");}
				else{PlaySound("OBJECTS\Voices\dead\male\Death_NPC_04.wav");}
			}

			LAi_ApplyCharacterDamage(NPchar, 20.0);	//extra damage when flaming arrows

			GetCharacterPos(NPchar, &u, &v, &w);
			CreateParticleSystem("rocket_fire" , u, v+1.2, w, 5.1, 4.0, 0.0, sti(20) );
			CreateParticleSystem("MMcancloud2" , u, v, w, 5.1, 4.0, 0.0, sti(20) );		//nr 14
			CreateParticleSystem("MMcancloud2" , u, v, w, 5.1, 4.0, 0.0, sti(20) );		//nr 14

			LAi_QuestDelay("NPC_flaming_hit2", 1.0);
		break;

		case "NPC_flaming_hit2":
			NPChar = characterFromID(Pchar.npc_flaming);
			GetCharacterPos(NPchar, &u, &v, &w);
			CreateParticleSystem("rocket_fire" , u, v+1.2, w, 5.1, 4.0, 0.0, sti(20) );
			CreateParticleSystem("MMcancloud2" , u, v, w, 5.1, 4.0, 0.0, sti(20) );		//nr 14

			LAi_QuestDelay("NPC_flaming_hit3", 1.0);
		break;

		case "NPC_flaming_hit3":
			NPChar = characterFromID(Pchar.npc_flaming);
			GetCharacterPos(NPchar, &u, &v, &w);
			CreateParticleSystem("rocket_fire" , u, v+1.2, w, 5.1, 4.0, 0.0, sti(20) );
			CreateParticleSystem("MMcancloud2" , u, v, w, 5.1, 4.0, 0.0, sti(20) );		//nr 14
		break;

		case "NPC_flaming_hit4":
			NPChar = characterFromID(Pchar.npc_flaming);

			LAi_SetActorType(NPChar);
			LAi_ActorAttack(NPChar, PChar, "");
		break;

		case "NPC_flaming_hit5":
			NPChar = characterFromID(Pchar.npc_flaming);

			LAi_SetActorType(NPChar);
			LAi_ActorAfraid(NPChar, Pchar, true);
		break;

		case "delayed_disarm_sound":
			PlaySound("OBJECTS\DUEL\sword_disarmed.wav");
			PlaySound("INTERFACE\metal_fall2.wav");
			NPChar = characterFromID(Pchar.npc_whip);
			string enemy_blade = GetCharacterEquipByGroup(NPChar,BLADE_ITEM_TYPE);
			TakeItemFromCharacter(NPChar, enemy_blade);
			if(!CheckCharacterItem(NPChar, "bladeX4")) GiveItem2Character(NPChar, "bladeX4");
			EquipCharacterByItem(NPChar, "bladeX4");
		break;
	
		case "reset_whip_rolled_pchar":
			//LogIt("PCHAR");
			weapon.model = "whip_rolled";
			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE );
			EquipCharacterByItem(Pchar, "pistolwhip");		
		break;
	
		case "reset_whip_rolled_officer":
			//LogIt("OFFICER");

			OPChar = characterFromID(Pchar.opc_whip);
			weaponID = GetCharacterEquipByGroup(OPchar,GUN_ITEM_TYPE);
			Items_FindItem(weaponID, &weapon);
			//LogIt("officer model 1 = " + weapon.model);
			
			weapon.model = "whip_rolled";
			RemoveCharacterEquip(OPchar, GUN_ITEM_TYPE );
			EquipCharacterByItem(OPchar, "pistolwhip");

			weaponID = GetCharacterEquipByGroup(OPchar,GUN_ITEM_TYPE);
			Items_FindItem(weaponID, &weapon);
			//LogIt("officer model 2 = " + weapon.model);		
		break;

		case "pchar_hip_mode_check":
			//from reload.c only for pchar

			if (weaponID != "") // PB: For cases where you don't have any gun equipped
			{
				aref weapon3;
				Items_FindItem(weaponID, &weapon3);

				if(weapon3.model == "musket_back")
				{
					weapon3.model = "musket";
					RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
					EquipCharacterByItem(Pchar, "pistolmket");
				}
				if(weapon3.model == "musketB_back")
				{
					weapon3.model = "musketB";
					RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
					EquipCharacterByItem(Pchar, "pistolmketB");
				}
				if(weapon3.model == "musketoon_back")
				{
					weapon3.model = "musketoon";
					RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
					EquipCharacterByItem(Pchar, "pistolmtoon");
				}
				if(weapon3.model == "Arguebuse_back")
				{
					weapon3.model = "Arguebuse";
					RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
					EquipCharacterByItem(Pchar, "Arguebuse");
				}
				if(weapon3.model == "blunder1_10_back")
				{
					weapon3.model = "blunder1_10";
					RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
					EquipCharacterByItem(Pchar, "pistolbbuss");
				}
				if(weapon3.model == "pistol13_back")
				{
					weapon3.model = "pistol13";
					RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
					EquipCharacterByItem(Pchar, "pistol13");
				}
				if(weapon3.model == "LongRifle_C_back")
				{
					weapon3.model = "LongRifle_C";
					RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
					EquipCharacterByItem(Pchar, "LongRifle_C");
				}
				if(weapon3.model == "LongRifle_H_back")
				{
					weapon3.model = "LongRifle_H";
					RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
					EquipCharacterByItem(Pchar, "LongRifle_H");
				}
				if(weapon3.model == "LongRifle_CT_back")
				{
					weapon3.model = "LongRifle_CT";
					RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
					EquipCharacterByItem(Pchar, "LongRifle_CT");
				}
				if(weapon3.model == "LongRifle_BT_back")
				{
					weapon3.model = "LongRifle_BT";
					RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
					EquipCharacterByItem(Pchar, "LongRifle_BT");
				}
				if(weapon3.model == "LongRifle_W_back")
				{
					weapon3.model = "LongRifle_W";
					RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
					EquipCharacterByItem(Pchar, "LongRifle_W");
				}
				if(weapon3.model == "LongRifle_WT_back")
				{
					weapon3.model = "LongRifle_WT";
					RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
					EquipCharacterByItem(Pchar, "LongRifle_WT");
				}
				if(weapon3.model == "portugize_back")
				{
					weapon3.model = "portugize";
					RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
					EquipCharacterByItem(Pchar, "portugize");
				}
			}
		break;

		case "gunner_ammo":
			SupplyAmmo(false);
		break;

		case "stealing_holycross_Turks":
			if(locations[FindLocation(Pchar.location)].box1.items.holycross1 == 0)
			{
				LAi_QuestDelay("Coastbrothers_Turks_attack", 0.1);
			}
		break;

		case "Coastbrothers_Turks_attack":
			LAi_LocationFightDisable(&Locations[FindLocation(PChar.location)], false);

			PlaySound("OBJECTS\ABORDAGE\abordage2.wav");

			LAi_SetActorType(CharacterFromID("CB1"));
			LAi_SetActorType(CharacterFromID("CB2"));
			LAi_SetActorType(CharacterFromID("CB3"));
			LAi_SetActorType(CharacterFromID("CB4"));
			LAi_SetActorType(CharacterFromID("CB5"));
			LAi_SetActorType(CharacterFromID("CB6"));
			LAi_SetActorType(CharacterFromID("CB7"));
			LAi_SetActorType(CharacterFromID("CB8"));
			LAi_SetActorType(CharacterFromID("CB9"));
			LAi_SetActorType(CharacterFromID("CB10"));
			LAi_SetActorType(CharacterFromID("CB11"));
			LAi_SetActorType(CharacterFromID("CB21"));

			LAi_ActorAttack(CharacterFromID("CB1"), Pchar, "");
			LAi_ActorAttack(CharacterFromID("CB2"), Pchar, "");
			LAi_ActorAttack(CharacterFromID("CB3"), Pchar, "");
			LAi_ActorAttack(CharacterFromID("CB4"), Pchar, "");
			LAi_ActorAttack(CharacterFromID("CB5"), Pchar, "");
			LAi_ActorAttack(CharacterFromID("CB6"), Pchar, "");
			LAi_ActorAttack(CharacterFromID("CB7"), Pchar, "");
			LAi_ActorAttack(CharacterFromID("CB8"), Pchar, "");
			LAi_ActorAttack(CharacterFromID("CB9"), Pchar, "");
			LAi_ActorAttack(CharacterFromID("CB10"), Pchar, "");
			LAi_ActorAttack(CharacterFromID("CB11"), Pchar, "");
			LAi_ActorAttack(CharacterFromID("CB21"), Pchar, "");
		break;
// <-- JRH

// JRH: Cartagena New_cloister -->
	//----------------------------------------------------------------------------------------------
		case "cloister_start":
			LAi_QuestDelay("cloister_distillery", 0.1);
			LAi_QuestDelay("cloister_F1_check", 0.1);
			LAi_QuestDelay("cloister_F2_check", 0.1);
			LAi_QuestDelay("cloister_F3_check", 0.1);
			LAi_QuestDelay("cloister_F4_check", 0.1);

			pchar.quest.cloister_fountain.win_condition.l1 = "location";
			pchar.quest.cloister_fountain.win_condition.l1.location = "new_cloister_inside";
			pchar.quest.cloister_fountain.win_condition = "cloister_fountain";
		
			pchar.quest.cloister_stair1_go.win_condition.l1 = "locator";
			pchar.quest.cloister_stair1_go.win_condition.l1.location = "new_cloister_inside";
			pchar.quest.cloister_stair1_go.win_condition.l1.locator_group = "quest";
			pchar.quest.cloister_stair1_go.win_condition.l1.locator = "stair1";
			pchar.quest.cloister_stair1_go.win_condition = "cloister_stair1_go";
		break;
	//----------------------------------------------------------------------------------------------
		case "cloister_stair1":
			pchar.quest.cloister_stair1_go.win_condition.l1 = "locator";
			pchar.quest.cloister_stair1_go.win_condition.l1.location = "new_cloister_inside";
			pchar.quest.cloister_stair1_go.win_condition.l1.locator_group = "quest";
			pchar.quest.cloister_stair1_go.win_condition.l1.locator = "stair1";
			pchar.quest.cloister_stair1_go.win_condition = "cloister_stair1_go";
		break;

		case "cloister_stair1_go":
			if(CheckAttribute(pchar,"cloister_stair1") && pchar.cloister_stair1 == "down_ready")
			{
				pchar.cloister_stair1 = "up_ready";
				ChangeCharacterAddressGroup(pchar, "new_cloister_inside", "goto", "st1_do");
			}
			else 
			{
				pchar.cloister_stair1 = "down_ready";
				ChangeCharacterAddressGroup(pchar, "new_cloister_inside", "goto", "st1_up");

				pchar.quest.cloister_stair2A_go.win_condition.l1 = "locator";
				pchar.quest.cloister_stair2A_go.win_condition.l1.location = "new_cloister_inside";
				pchar.quest.cloister_stair2A_go.win_condition.l1.locator_group = "quest";
				pchar.quest.cloister_stair2A_go.win_condition.l1.locator = "stair2A";
				pchar.quest.cloister_stair2A_go.win_condition = "cloister_stair2A_go";

				pchar.quest.cloister_stair2B_go.win_condition.l1 = "locator";
				pchar.quest.cloister_stair2B_go.win_condition.l1.location = "new_cloister_inside";
				pchar.quest.cloister_stair2B_go.win_condition.l1.locator_group = "quest";
				pchar.quest.cloister_stair2B_go.win_condition.l1.locator = "stair2B";
				pchar.quest.cloister_stair2B_go.win_condition = "cloister_stair2B_go";
			}

			LAi_QuestDelay("cloister_stair1", 0.5);
		break;
	//----------------------------------------------------------------------------------------------
		case "cloister_stair2":
			pchar.quest.cloister_stair2A_go.win_condition.l1 = "locator";
			pchar.quest.cloister_stair2A_go.win_condition.l1.location = "new_cloister_inside";
			pchar.quest.cloister_stair2A_go.win_condition.l1.locator_group = "quest";
			pchar.quest.cloister_stair2A_go.win_condition.l1.locator = "stair2A";
			pchar.quest.cloister_stair2A_go.win_condition = "cloister_stair2A_go";

			pchar.quest.cloister_stair2B_go.win_condition.l1 = "locator";
			pchar.quest.cloister_stair2B_go.win_condition.l1.location = "new_cloister_inside";
			pchar.quest.cloister_stair2B_go.win_condition.l1.locator_group = "quest";
			pchar.quest.cloister_stair2B_go.win_condition.l1.locator = "stair2B";
			pchar.quest.cloister_stair2B_go.win_condition = "cloister_stair2B_go";
		break;
			
		case "cloister_stair2A_go":
			if(CheckAttribute(pchar,"cloister_stair2") && pchar.cloister_stair2 == "down_ready")
			{
				pchar.cloister_stair2 = "up_ready";
				ChangeCharacterAddressGroup(pchar, "new_cloister_inside", "goto", "st2A_do");
			}
			else 
			{
				pchar.cloister_stair2 = "down_ready";
				ChangeCharacterAddressGroup(pchar, "new_cloister_inside", "goto", "st2A_up");

				pchar.quest.cloister_stair3_go.win_condition.l1 = "locator";
				pchar.quest.cloister_stair3_go.win_condition.l1.location = "new_cloister_inside";
				pchar.quest.cloister_stair3_go.win_condition.l1.locator_group = "quest";
				pchar.quest.cloister_stair3_go.win_condition.l1.locator = "stair3";
				pchar.quest.cloister_stair3_go.win_condition = "cloister_stair3_go";
			}

			LAi_QuestDelay("cloister_stair2", 0.5);
		break;

		case "cloister_stair2B_go":
			if(CheckAttribute(pchar,"cloister_stair2") && pchar.cloister_stair2 == "down_ready")
			{
				pchar.cloister_stair2 = "up_ready";
				ChangeCharacterAddressGroup(pchar, "new_cloister_inside", "goto", "st2B_do");
			}
			else 
			{
				pchar.cloister_stair2 = "down_ready";
				ChangeCharacterAddressGroup(pchar, "new_cloister_inside", "goto", "st2B_up");

				pchar.quest.cloister_stair3_go.win_condition.l1 = "locator";
				pchar.quest.cloister_stair3_go.win_condition.l1.location = "new_cloister_inside";
				pchar.quest.cloister_stair3_go.win_condition.l1.locator_group = "quest";
				pchar.quest.cloister_stair3_go.win_condition.l1.locator = "stair3";
				pchar.quest.cloister_stair3_go.win_condition = "cloister_stair3_go";
			}

			LAi_QuestDelay("cloister_stair2", 0.5);
		break;
	//----------------------------------------------------------------------------------------------
		case "cloister_stair3_go":
			ChangeCharacterAddressGroup(pchar, "new_cloister_inside", "sit", "st3_up");		//was goto

			pchar.quest.cloister_stair4_go.win_condition.l1 = "locator";
			pchar.quest.cloister_stair4_go.win_condition.l1.location = "new_cloister_inside";
			pchar.quest.cloister_stair4_go.win_condition.l1.locator_group = "quest";
			pchar.quest.cloister_stair4_go.win_condition.l1.locator = "stair4";
			pchar.quest.cloister_stair4_go.win_condition = "cloister_stair4_go";
		break;
	//----------------------------------------------------------------------------------------------
		case "cloister_stair4_go":
			ChangeCharacterAddressGroup(pchar, "new_cloister_inside", "goto", "st4_do");

			pchar.quest.cloister_stair3_go.win_condition.l1 = "locator";
			pchar.quest.cloister_stair3_go.win_condition.l1.location = "new_cloister_inside";
			pchar.quest.cloister_stair3_go.win_condition.l1.locator_group = "quest";
			pchar.quest.cloister_stair3_go.win_condition.l1.locator = "stair3";
			pchar.quest.cloister_stair3_go.win_condition = "cloister_stair3_go";
		break;
	//----------------------------------------------------------------------------------------------
		case "cloister_fountain":
			if(Pchar.location == "new_cloister_inside")
			{
				Play3DSound("NATURE\fountain.wav", 2.4, 1.5, -15.4);
				Play3DSound("NATURE\fountain.wav", 2.4, 1.5, -15.4);

				LAi_QuestDelay("cloister_fountain_1", 0.4);
				LAi_QuestDelay("cloister_fountain", 2.8);
			}
			else
			{
				//no fountain sound please

				pchar.quest.cloister_fountain.win_condition.l1 = "location";
				pchar.quest.cloister_fountain.win_condition.l1.location = "new_cloister_inside";
				pchar.quest.cloister_fountain.win_condition = "cloister_fountain";
			}
		break;

		case "cloister_fountain_1":
			Play3DSound("NATURE\fountain.wav", 2.4, 1.5, -15.4);
			Play3DSound("NATURE\fountain.wav", 2.4, 1.5, -15.4);
		break;
	//----------------------------------------------------------------------------------------------
		case "cloister_distillery":
			if(Pchar.location == "new_cloister_garden")
			{
				if(IsDay())
				{
					Play3DSound("INTERFACE\bubbles2.wav", -42.0, 1.5, -87.0);
			
					LAi_QuestDelay("cloister_distillery_1", 0.4);
				}

				LAi_QuestDelay("cloister_distillery", 5.0);
			}
			else
			{
				//no distillery sound please

				pchar.quest.cloister_distillery.win_condition.l1 = "location";
				pchar.quest.cloister_distillery.win_condition.l1.location = "new_cloister_garden";
				pchar.quest.cloister_distillery.win_condition = "cloister_distillery";
			}
		break;

		case "cloister_distillery_1":
			Play3DSound("INTERFACE\bubbles2.wav", -42.0, 1.5, -87.0);
		break;
	//----------------------------------------------------------------------------------------------
		case "cloister_F1_check":
			LAi_SetPlayerType(Pchar);

			pchar.quest.cloister_F1_back.win_condition.l1 = "locator";
			pchar.quest.cloister_F1_back.win_condition.l1.location = "new_cloister_inside";
			pchar.quest.cloister_F1_back.win_condition.l1.locator_group = "quest";
			pchar.quest.cloister_F1_back.win_condition.l1.locator = "F1";
			pchar.quest.cloister_F1_back.win_condition = "cloister_F1_back";
		break;
		
		case "cloister_F1_back":
			LAi_SetStayType(Pchar);
			ChangeCharacterAddressGroup(Pchar, "new_cloister_inside", "goto", "F1_back");

			LAi_QuestDelay("cloister_F1_check", 0.2);
		break;

		case "cloister_F2_check":
			LAi_SetPlayerType(Pchar);

			pchar.quest.cloister_F2_back.win_condition.l1 = "locator";
			pchar.quest.cloister_F2_back.win_condition.l1.location = "new_cloister_inside";
			pchar.quest.cloister_F2_back.win_condition.l1.locator_group = "quest";
			pchar.quest.cloister_F2_back.win_condition.l1.locator = "F2";
			pchar.quest.cloister_F2_back.win_condition = "cloister_F2_back";
		break;
		
		case "cloister_F2_back":
			LAi_SetStayType(Pchar);
			ChangeCharacterAddressGroup(Pchar, "new_cloister_inside", "goto", "F2_back");

			LAi_QuestDelay("cloister_F2_check", 0.2);
		break;

		case "cloister_F3_check":
			LAi_SetPlayerType(Pchar);

			pchar.quest.cloister_F3_back.win_condition.l1 = "locator";
			pchar.quest.cloister_F3_back.win_condition.l1.location = "new_cloister_inside";
			pchar.quest.cloister_F3_back.win_condition.l1.locator_group = "quest";
			pchar.quest.cloister_F3_back.win_condition.l1.locator = "F3";
			pchar.quest.cloister_F3_back.win_condition = "cloister_F3_back";
		break;
		
		case "cloister_F3_back":
			LAi_SetStayType(Pchar);
			ChangeCharacterAddressGroup(Pchar, "new_cloister_inside", "goto", "F3_back");

			LAi_QuestDelay("cloister_F3_check", 0.2);
		break;

		case "cloister_F4_check":
			LAi_SetPlayerType(Pchar);

			pchar.quest.cloister_F4_back.win_condition.l1 = "locator";
			pchar.quest.cloister_F4_back.win_condition.l1.location = "new_cloister_inside";
			pchar.quest.cloister_F4_back.win_condition.l1.locator_group = "quest";
			pchar.quest.cloister_F4_back.win_condition.l1.locator = "F4";
			pchar.quest.cloister_F4_back.win_condition = "cloister_F4_back";
		break;
		
		case "cloister_F4_back":
			LAi_SetStayType(Pchar);
			ChangeCharacterAddressGroup(Pchar, "new_cloister_inside", "goto", "F4_back");

			LAi_QuestDelay("cloister_F4_check", 0.2);
		break;
	
	//----------------------------------------------------------------------------------------------
// <-- JRH: Cartagena New_cloister

// GR: Easter egg for Rheims' house because guards are always there. Triggered by dialog with one of them. -->
		case "Rheims_house_setup":
			PChar.quest.rheims_house.done = true;
			Locations[FindLocation("Rheims_house_in_smugglers")].vcskip = true;
			LAi_SetFightMode(PChar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("Rheims_house_in_smugglers")], true);
			PChar.quest.Rheims_house_window_setup.win_condition.l1 = "locator";
			PChar.quest.Rheims_house_window_setup.win_condition.l1.location = "Smugglers_Lair";
			PChar.quest.Rheims_house_window_setup.win_condition.l1.locator_group = "reload";
			PChar.quest.Rheims_house_window_setup.win_condition.l1.locator = "window";
			PChar.quest.Rheims_house_window_setup.win_condition.l2 = "Time";
			PChar.quest.Rheims_house_window_setup.win_condition.l2.time = DAY_TIME_NIGHT;
			PChar.quest.Rheims_house_window_setup.win_condition = "Rheims_house_window_setup";
		break;

		case "Rheims_house_window_setup":
			PChar.quest.rheims_house.current_year = GetDataYear();
			SetCurrentDate(GetDataDay(), GetDataMonth(), 1750);
			Locations[FindLocation("Rheims_house_in_smugglers")].reload.l1.disable = 1;
			DoQuestReloadToLocation("Rheims_house_in_smugglers", "goto", "goto2", "Rheims_house_inside");
		break;

		case "Rheims_house_inside":
			Locations[FindLocation("Rheims_house_in_smugglers")].type = "shop";	// Temporarily turn Rheims' house into "shop" type to prevent alert if you loot a chest
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "blaze", "reload", "reload1");
			sld.id = "Fake_Nathaniel";
			sld.old.name = "Nathaniel";
			sld.old.lastname = "Hawk";
			sld.name 	= TranslateString("","Nathaniel");
			sld.lastname 	= TranslateString("","Hawk");
			sld.Dialog.Filename = "Evaristo Filho_dialog.c";
			sld.dialog.CurrentNode = "Nathaniel_surprise";
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld,PChar,"",5.0,5.0);
		break;

		case "Rheims_exit_setup":	// Triggered by dialog with "Fake_Nathaniel"
			LAi_SetCitizenType(CharacterFromID("Fake_Nathaniel"));
			PChar.quest.Rheims_exit.win_condition.l1 = "locator";
			PChar.quest.Rheims_exit.win_condition.l1.location = "Rheims_house_in_smugglers";
			PChar.quest.Rheims_exit.win_condition.l1.locator_group = "reload";
			PChar.quest.Rheims_exit.win_condition.l1.locator = "reload1";
			PChar.quest.Rheims_exit.win_condition = "Rheims_exit";
		break;

		case "Rheims_exit":
			Locations[FindLocation("Rheims_house_in_smugglers")].type = "house";
			Locations[FindLocation("Rheims_house_in_smugglers")].reload.l1.disable = 0;
			SetCurrentDate(GetDataDay(), GetDataMonth(), sti(PChar.quest.rheims_house.current_year));
			DoQuestReloadToLocation("Smugglers_Lair", "reload", "reload10", "_");
		break;
// <<-- GR: End of Rheims House Easter egg

		PChar.questnotfound = true; // PB: Testing
	}
}
// <-- KK

//JRH -->
#event_handler("mket_on_hip", "hip_mket");
void hip_mket()
{
	aref attack = GetEventData();
	string weaponID = GetCharacterEquipByGroup(attack,GUN_ITEM_TYPE);
	if (weaponID == "") return; // PB: Prevent potential error messages
	aref weapon;
	Items_FindItem(weaponID, &weapon);

	float GunCurCharge = LAi_GetCharacterRelCharge(attack); // Levis
	weapon.model = "musket";
	RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
	EquipCharacterByItem(attack, "pistolmket");
	attack.chr_ai.charge = GunCurCharge; // Levis

	if(IsMainCharacter(attack) && DisableReloadWhileFighting()) PlaySound("OBJECTS\DUEL\reload1.wav");
}

#event_handler("mket_on_back", "back_mket");
void back_mket()
{
	aref attack = GetEventData();
	string weaponID = GetCharacterEquipByGroup(attack,GUN_ITEM_TYPE);
	if (weaponID == "") return; // PB: Prevent potential error messages
	aref weapon;
	Items_FindItem(weaponID, &weapon);

	if(weapon.model == "musket")
	{
		float GunCurCharge = LAi_GetCharacterRelCharge(attack); // Levis
		weapon.model = "musket_back";
		RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
		EquipCharacterByItem(attack, "pistolmket");

		attack.chr_ai.charge = GunCurCharge; // Levis

		if(IsMainCharacter(attack) && DisableReloadWhileFighting()) PlaySound("PEOPLE\clothes1.wav");
	}
}

#event_handler("mketK_as_blade", "blade_mketK");
void blade_mketK()
{
	aref attack = GetEventData();
	string weaponID = GetCharacterEquipByGroup(attack,GUN_ITEM_TYPE);
	if (weaponID == "") return; // PB: Prevent potential error messages
	aref weapon;
	Items_FindItem(weaponID, &weapon);

	int bmf = GetCharacterItem(attack, "blade_mKnife");
	int pmk = GetCharacterItem(attack, "pistolmket");

	RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
	if(pmk == 1) TakeItemFromCharacter(attack, "pistolmket");		//JRH: amount was reduced if > 1, ok for pchar(1), off(1), pchar(>1)

	RemoveCharacterEquip(attack, BLADE_ITEM_TYPE );
	if(bmf == 1) TakeItemFromCharacter(attack, "blade_mKnife");		//JRH: amount was reduced if > 1, ok for pchar(1), off(1), pchar(>1)

	if(!CheckCharacterItem(attack, "blademketK"))
	{
		GiveItem2Character(attack, "blademketK");		//JRH: just to be sure
	}
	EquipCharacterByItem(attack, "blademketK");
	
	if(IsMainCharacter(attack) && DisableReloadWhileFighting()) PlaySound("OBJECTS\DUEL\reload1.wav");
}

#event_handler("blademketK_as_gun", "gun_mketK");
void gun_mketK()
{
	aref attack = GetEventData();

	RemoveCharacterEquip(attack, BLADE_ITEM_TYPE );
	TakeItemFromCharacter(attack, "blademketK");
	if(!CheckCharacterItem(attack, "blade_mKnife"))
	{
		GiveItem2Character(attack, "blade_mKnife");		//JRH: multiple weapons fix
	}
	EquipCharacterByItem(attack, "blade_mKnife");

	float GunCurCharge = LAi_GetCharacterRelCharge(attack); // Levis
	RemoveCharacterEquip(attack, GUN_ITEM_TYPE );

	if(!CheckCharacterItem(attack, "pistolmket"))
	{
		GiveItem2Character(attack, "pistolmket");		//JRH: multiple weapons fix
	}
	EquipCharacterByItem(attack, "pistolmket");

	aref weapon;
	string weaponID = GetCharacterEquipByGroup(attack,GUN_ITEM_TYPE);
	if (weaponID == "") return; // PB: Prevent potential error messages
	Items_FindItem(weaponID, &weapon);
	if(weapon.model == "musket")
	{
		weapon.model = "musket_back";
		RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
		EquipCharacterByItem(attack, "pistolmket");
	}	

	attack.chr_ai.charge = GunCurCharge; // Levis

	if(IsMainCharacter(attack) && DisableReloadWhileFighting()) PlaySound("PEOPLE\clothes1.wav");
}

//---------------------------------------------------------------------------

#event_handler("mtoon_on_hip", "hip_mtoon");
void hip_mtoon()
{
	aref attack = GetEventData();
	string weaponID = GetCharacterEquipByGroup(attack,GUN_ITEM_TYPE);
	if (weaponID == "") return; // PB: Prevent potential error messages
	aref weapon;
	Items_FindItem(weaponID, &weapon);

	float GunCurCharge = LAi_GetCharacterRelCharge(attack); // Levis
	weapon.model = "musketoon";
	RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
	EquipCharacterByItem(attack, "pistolmtoon");
	attack.chr_ai.charge = GunCurCharge; // Levis

	if(IsMainCharacter(attack) && DisableReloadWhileFighting()) PlaySound("OBJECTS\DUEL\reload1.wav");
}

#event_handler("mtoon_on_back", "back_mtoon");
void back_mtoon()
{
	aref attack = GetEventData();
	string weaponID = GetCharacterEquipByGroup(attack,GUN_ITEM_TYPE);
	if (weaponID == "") return; // PB: Prevent potential error messages
	aref weapon;
	Items_FindItem(weaponID, &weapon);

	if(weapon.model == "musketoon")
	{
		float GunCurCharge = LAi_GetCharacterRelCharge(attack); // Levis
		weapon.model = "musketoon_back";
		RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
		EquipCharacterByItem(attack, "pistolmtoon");
		attack.chr_ai.charge = GunCurCharge; // Levis

		if(IsMainCharacter(attack) && DisableReloadWhileFighting()) PlaySound("PEOPLE\clothes1.wav");
	}
}

//---------------------------------------------------------------------------

#event_handler("mketB_on_hip", "hip_mketB");
void hip_mketB()
{
	aref attack = GetEventData();
	string weaponID = GetCharacterEquipByGroup(attack,GUN_ITEM_TYPE);
	if (weaponID == "") return; // PB: Prevent potential error messages
	aref weapon;
	Items_FindItem(weaponID, &weapon);

	EquipCharacterByItem(attack, FindCharacterItemByGroup(attack, BLADE_ITEM_TYPE));	//so you can use your best blade while the loaded bayonet-musket is ready to fire on your hip

	float GunCurCharge = LAi_GetCharacterRelCharge(attack); // Levis
	weapon.model = "musketB";
	RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
	EquipCharacterByItem(attack, "pistolmketB");
	attack.chr_ai.charge = GunCurCharge; // Levis

	if(IsMainCharacter(attack) && DisableReloadWhileFighting()) PlaySound("OBJECTS\DUEL\reload1.wav");
}

#event_handler("mketB_as_blade", "blade_mketB");
void blade_mketB()
{
	aref attack = GetEventData();
	string weaponID = GetCharacterEquipByGroup(attack,GUN_ITEM_TYPE);
	if (weaponID == "") return; // PB: Prevent potential error messages
	aref weapon;
	Items_FindItem(weaponID, &weapon);

	int pmkB = GetCharacterItem(attack, "pistolmketB");

	RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
	if(pmkB == 1) TakeItemFromCharacter(attack, "pistolmketB");		//JRH: amount was reduced if > 1, ok for pchar(1), off(1), pchar(>1)

	if(!CheckCharacterItem(attack, "blademketB"))
	{
		GiveItem2Character(attack, "blademketB");		//JRH: just to be sure
	}
	EquipCharacterByItem(attack, "blademketB");
	
	if(IsMainCharacter(attack) && DisableReloadWhileFighting()) PlaySound("PEOPLE\clothes1.wav");
}

#event_handler("blademketB_as_gun", "gun_mketB");
void gun_mketB()
{
	aref attack = GetEventData();

	RemoveCharacterEquip(attack, BLADE_ITEM_TYPE );
	TakeItemFromCharacter(attack, "blademketB");
/*	if(!CheckCharacterItem(attack, "bladeX4")) GiveItem2Character(attack, "bladeX4");
	EquipCharacterByItem(attack, "bladeX4");	*/
EquipCharacterByItem(attack, FindCharacterItemByGroup(attack, BLADE_ITEM_TYPE));

	float GunCurCharge = LAi_GetCharacterRelCharge(attack); // Levis
	RemoveCharacterEquip(attack, GUN_ITEM_TYPE );

	if(!CheckCharacterItem(attack, "pistolmketB"))
	{
		GiveItem2Character(attack, "pistolmketB");		//JRH: just to be sure
	}
	EquipCharacterByItem(attack, "pistolmketB");

	aref weapon;
	string weaponID = GetCharacterEquipByGroup(attack,GUN_ITEM_TYPE);
	if (weaponID == "") return; // PB: Prevent potential error messages
	Items_FindItem(weaponID, &weapon);
	if(weapon.model == "musketB")
	{
		weapon.model = "musketB_back";
		RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
		EquipCharacterByItem(attack, "pistolmketB");
	}

	attack.chr_ai.charge = GunCurCharge; // Levis

	if(IsMainCharacter(attack) && DisableReloadWhileFighting()) PlaySound("PEOPLE\clothes1.wav");
}

#event_handler("mketB_on_back", "back_mketB");
void back_mketB()
{
	aref attack = GetEventData();
	string weaponID = GetCharacterEquipByGroup(attack,GUN_ITEM_TYPE);
	if (weaponID == "") return; // PB: Prevent potential error messages
	aref weapon;
	Items_FindItem(weaponID, &weapon);

	if(weapon.model == "musketB")
	{
		float GunCurCharge = LAi_GetCharacterRelCharge(attack); // Levis
		weapon.model = "musketB_back";
		RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
		EquipCharacterByItem(attack, "pistolmketB");
		attack.chr_ai.charge = GunCurCharge; // Levis

		if(IsMainCharacter(attack) && DisableReloadWhileFighting()) PlaySound("PEOPLE\clothes1.wav");
	}
}

//---------------------------------------------------------------------------

#event_handler("Arguebuse_on_hip", "hip_Arguebuse");
void hip_Arguebuse()
{
	aref attack = GetEventData();
	string weaponID = GetCharacterEquipByGroup(attack,GUN_ITEM_TYPE);
	if (weaponID == "") return; // PB: Prevent potential error messages
	aref weapon;
	Items_FindItem(weaponID, &weapon);

	float GunCurCharge = LAi_GetCharacterRelCharge(attack); // Levis
	weapon.model = "Arguebuse";
	RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
	EquipCharacterByItem(attack, "Arguebuse");
	attack.chr_ai.charge = GunCurCharge; // Levis

	if(IsMainCharacter(attack) && DisableReloadWhileFighting()) PlaySound("OBJECTS\DUEL\reload1.wav");
}

#event_handler("Arguebuse_on_back", "back_Arguebuse");
void back_Arguebuse()
{
	aref attack = GetEventData();
	string weaponID = GetCharacterEquipByGroup(attack,GUN_ITEM_TYPE);
	if (weaponID == "") return; // PB: Prevent potential error messages
	aref weapon;
	Items_FindItem(weaponID, &weapon);

	if(weapon.model == "Arguebuse")
	{
		float GunCurCharge = LAi_GetCharacterRelCharge(attack); // Levis
		weapon.model = "Arguebuse_back";
		RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
		EquipCharacterByItem(attack, "Arguebuse");
		attack.chr_ai.charge = GunCurCharge; // Levis

		if(IsMainCharacter(attack) && DisableReloadWhileFighting()) PlaySound("PEOPLE\clothes1.wav");
	}
}

//---------------------------------------------------------------------------

#event_handler("bbuss_on_hip", "hip_bbuss");
void hip_bbuss()
{
	aref attack = GetEventData();
	string weaponID = GetCharacterEquipByGroup(attack,GUN_ITEM_TYPE);
	if (weaponID == "") return; // PB: Prevent potential error messages
	aref weapon;
	Items_FindItem(weaponID, &weapon);

	float GunCurCharge = LAi_GetCharacterRelCharge(attack); // Levis
	weapon.model = "blunder1_10";
	RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
	EquipCharacterByItem(attack, "pistolbbuss");
	attack.chr_ai.charge = GunCurCharge; // Levis

	if(IsMainCharacter(attack) && DisableReloadWhileFighting()) PlaySound("OBJECTS\DUEL\reload1.wav");
}

#event_handler("bbuss_on_back", "back_bbuss");
void back_bbuss()
{
	aref attack = GetEventData();
	string weaponID = GetCharacterEquipByGroup(attack,GUN_ITEM_TYPE);
	if (weaponID == "") return; // PB: Prevent potential error messages
	aref weapon;
	Items_FindItem(weaponID, &weapon);

	if(weapon.model == "blunder1_10")
	{
		float GunCurCharge = LAi_GetCharacterRelCharge(attack); // Levis
		weapon.model = "blunder1_10_back";
		RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
		EquipCharacterByItem(attack, "pistolbbuss");
		attack.chr_ai.charge = GunCurCharge; // Levis

		if(IsMainCharacter(attack) && DisableReloadWhileFighting()) PlaySound("PEOPLE\clothes1.wav");
	}
}

//---------------------------------------------------------------------------

#event_handler("pistol13_on_hip", "hip_pistol13");
void hip_pistol13()
{
	aref attack = GetEventData();
	string weaponID = GetCharacterEquipByGroup(attack,GUN_ITEM_TYPE);
	if (weaponID == "") return; // PB: Prevent potential error messages
	aref weapon;
	Items_FindItem(weaponID, &weapon);

	float GunCurCharge = LAi_GetCharacterRelCharge(attack); // Levis
	weapon.model = "pistol13";
	RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
	EquipCharacterByItem(attack, "pistol13");
	attack.chr_ai.charge = GunCurCharge; // Levis

	if(IsMainCharacter(attack) && DisableReloadWhileFighting()) PlaySound("OBJECTS\DUEL\reload1.wav");
}

#event_handler("pistol13_on_back", "back_pistol13");
void back_pistol13()
{
	aref attack = GetEventData();
	string weaponID = GetCharacterEquipByGroup(attack,GUN_ITEM_TYPE);
	if (weaponID == "") return; // PB: Prevent potential error messages
	aref weapon;
	Items_FindItem(weaponID, &weapon);

	if(weapon.model == "pistol13")
	{
		float GunCurCharge = LAi_GetCharacterRelCharge(attack); // Levis
		weapon.model = "pistol13_back";
		RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
		EquipCharacterByItem(attack, "pistol13");
		attack.chr_ai.charge = GunCurCharge; // Levis

		if(IsMainCharacter(attack) && DisableReloadWhileFighting()) PlaySound("PEOPLE\clothes1.wav");
	}
}

//---------------------------------------------------------------------------

#event_handler("LongRifle_C_on_hip", "hip_LongRifle_C");
void hip_LongRifle_C()
{
	aref attack = GetEventData();
	string weaponID = GetCharacterEquipByGroup(attack,GUN_ITEM_TYPE);
	if (weaponID == "") return; // PB: Prevent potential error messages
	aref weapon;
	Items_FindItem(weaponID, &weapon);

	float GunCurCharge = LAi_GetCharacterRelCharge(attack); // Levis
	weapon.model = "LongRifle_C";
	RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
	EquipCharacterByItem(attack, "LongRifle_C");
	attack.chr_ai.charge = GunCurCharge; // Levis

	if(IsMainCharacter(attack) && DisableReloadWhileFighting()) PlaySound("OBJECTS\DUEL\reload1.wav");
}

#event_handler("LongRifle_C_on_back", "back_LongRifle_C");
void back_LongRifle_C()
{
	aref attack = GetEventData();
	string weaponID = GetCharacterEquipByGroup(attack,GUN_ITEM_TYPE);
	if (weaponID == "") return; // PB: Prevent potential error messages
	aref weapon;
	Items_FindItem(weaponID, &weapon);

	if(weapon.model == "LongRifle_C")
	{
		float GunCurCharge = LAi_GetCharacterRelCharge(attack); // Levis
		weapon.model = "LongRifle_C_back";
		RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
		EquipCharacterByItem(attack, "LongRifle_C");
		attack.chr_ai.charge = GunCurCharge; // Levis

		if(IsMainCharacter(attack) && DisableReloadWhileFighting()) PlaySound("PEOPLE\clothes1.wav");
	}
}

//---------------------------------------------------------------------------

#event_handler("LongRifle_H_on_hip", "hip_LongRifle_H");
void hip_LongRifle_H()
{
	aref attack = GetEventData();
	string weaponID = GetCharacterEquipByGroup(attack,GUN_ITEM_TYPE);
	if (weaponID == "") return; // PB: Prevent potential error messages
	aref weapon;
	Items_FindItem(weaponID, &weapon);

	float GunCurCharge = LAi_GetCharacterRelCharge(attack); // Levis
	weapon.model = "LongRifle_H";
	RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
	EquipCharacterByItem(attack, "LongRifle_H");
	attack.chr_ai.charge = GunCurCharge; // Levis

	if(IsMainCharacter(attack) && DisableReloadWhileFighting()) PlaySound("OBJECTS\DUEL\reload1.wav");
}

#event_handler("LongRifle_H_on_back", "back_LongRifle_H");
void back_LongRifle_H()
{
	aref attack = GetEventData();
	string weaponID = GetCharacterEquipByGroup(attack,GUN_ITEM_TYPE);
	if (weaponID == "") return; // PB: Prevent potential error messages
	aref weapon;
	Items_FindItem(weaponID, &weapon);

	if(weapon.model == "LongRifle_H")
	{
		float GunCurCharge = LAi_GetCharacterRelCharge(attack); // Levis
		weapon.model = "LongRifle_H_back";
		RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
		EquipCharacterByItem(attack, "LongRifle_H");
		attack.chr_ai.charge = GunCurCharge; // Levis

		if(IsMainCharacter(attack) && DisableReloadWhileFighting()) PlaySound("PEOPLE\clothes1.wav");
	}
}

//---------------------------------------------------------------------------

#event_handler("LongRifle_W_on_hip", "hip_LongRifle_W");
void hip_LongRifle_W()
{
	aref attack = GetEventData();
	string weaponID = GetCharacterEquipByGroup(attack,GUN_ITEM_TYPE);
	if (weaponID == "") return; // PB: Prevent potential error messages
	aref weapon;
	Items_FindItem(weaponID, &weapon);

	float GunCurCharge = LAi_GetCharacterRelCharge(attack); // Levis
	weapon.model = "LongRifle_W";
	RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
	EquipCharacterByItem(attack, "LongRifle_W");
	attack.chr_ai.charge = GunCurCharge; // Levis

	if(IsMainCharacter(attack) && DisableReloadWhileFighting()) PlaySound("OBJECTS\DUEL\reload1.wav");
}

#event_handler("LongRifle_W_on_back", "back_LongRifle_W");
void back_LongRifle_W()
{
	aref attack = GetEventData();
	string weaponID = GetCharacterEquipByGroup(attack,GUN_ITEM_TYPE);
	if (weaponID == "") return; // PB: Prevent potential error messages
	aref weapon;
	Items_FindItem(weaponID, &weapon);

	if(weapon.model == "LongRifle_W")
	{
		float GunCurCharge = LAi_GetCharacterRelCharge(attack); // Levis
		weapon.model = "LongRifle_W_back";
		RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
		EquipCharacterByItem(attack, "LongRifle_W");
		attack.chr_ai.charge = GunCurCharge; // Levis

		if(IsMainCharacter(attack) && DisableReloadWhileFighting()) PlaySound("PEOPLE\clothes1.wav");
	}
}

//---------------------------------------------------------------------------

#event_handler("portugize_on_hip", "hip_portugize");
void hip_portugize()
{
	aref attack = GetEventData();
	string weaponID = GetCharacterEquipByGroup(attack,GUN_ITEM_TYPE);
	if (weaponID == "") return; // PB: Prevent potential error messages
	aref weapon;
	Items_FindItem(weaponID, &weapon);

	float charge = stf(attack.chr_ai.charge);
	weapon.model = "portugize";
	RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
	EquipCharacterByItem(attack, "portugize");
	attack.chr_ai.charge = charge;

	if(IsMainCharacter(attack) && DisableReloadWhileFighting()) PlaySound("OBJECTS\DUEL\reload1.wav");
}

#event_handler("portugize_on_back", "back_portugize");
void back_portugize()
{
	aref attack = GetEventData();
	string weaponID = GetCharacterEquipByGroup(attack,GUN_ITEM_TYPE);
	if (weaponID == "") return; // PB: Prevent potential error messages
	aref weapon;
	Items_FindItem(weaponID, &weapon);

	if(weapon.model == "portugize")
	{
		float charge = stf(attack.chr_ai.charge);
		weapon.model = "portugize_back";
		RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
		EquipCharacterByItem(attack, "portugize");
		attack.chr_ai.charge = charge;

		if(IsMainCharacter(attack) && DisableReloadWhileFighting()) PlaySound("PEOPLE\clothes1.wav");
	}
}

//---------------------------------------------------------------------------

#event_handler("bax_on_hip", "hip_bax");
void hip_bax()
{
	aref attack = GetEventData();
	string weaponID = GetCharacterEquipByGroup(attack,BLADE_ITEM_TYPE);
	if (weaponID == "") return; // PB: Prevent potential error messages
	aref weapon;
	Items_FindItem(weaponID, &weapon);

	weapon.model = "battleax";
	RemoveCharacterEquip(attack, BLADE_ITEM_TYPE );
	EquipCharacterByItem(attack, "battleax");

	if(IsMainCharacter(attack) && DisableReloadWhileFighting()) PlaySound("PEOPLE\clothes1.wav");
}

#event_handler("bax_on_back", "back_bax");
void back_bax()
{
	aref attack = GetEventData();
	string weaponID = GetCharacterEquipByGroup(attack,BLADE_ITEM_TYPE);
	if (weaponID == "") return; // PB: Prevent potential error messages
	aref weapon;
	Items_FindItem(weaponID, &weapon);

	if(weapon.model == "battleax")
	{
		weapon.model = "battleax_back";
		RemoveCharacterEquip(attack, BLADE_ITEM_TYPE );
		EquipCharacterByItem(attack, "battleax");

		if(IsMainCharacter(attack) && DisableReloadWhileFighting()) PlaySound("PEOPLE\clothes1.wav");
	}
}

//---------------------------------------------------------------------------

#event_handler("witcher_steel_on_hip", "hip_witcher_steel");
void hip_witcher_steel()
{
	aref attack = GetEventData();
	string weaponID = GetCharacterEquipByGroup(attack,BLADE_ITEM_TYPE);
	if (weaponID == "") return; // PB: Prevent potential error messages
	aref weapon;
	Items_FindItem(weaponID, &weapon);

	if(IsEquipCharacterByItem(attack, "witcher_steel-2")) {attack.bladeID = "witcher_steel-2"}
	if(IsEquipCharacterByItem(attack, "witcher_steel-1")) {attack.bladeID = "witcher_steel-1"}
	if(IsEquipCharacterByItem(attack, "witcher_steel")) {attack.bladeID = "witcher_steel"}
	if(IsEquipCharacterByItem(attack, "witcher_steel+1")) {attack.bladeID = "witcher_steel+1"}
	if(IsEquipCharacterByItem(attack, "witcher_steel+2")) {attack.bladeID = "witcher_steel+2"}
	if(IsEquipCharacterByItem(attack, "witcher_steel+3")) {attack.bladeID = "witcher_steel+3"}

	weapon.model = "witcher_steel";
	RemoveCharacterEquip(attack, BLADE_ITEM_TYPE );

	if(CheckAttribute(attack,"bladeID"))
	{
		switch(attack.bladeID)
		{
			case "witcher_steel-2": EquipCharacterByItem(attack, "witcher_steel-2"); break;
			case "witcher_steel-1": EquipCharacterByItem(attack, "witcher_steel-1"); break;
			case "witcher_steel": EquipCharacterByItem(attack, "witcher_steel"); break;
			case "witcher_steel+1": EquipCharacterByItem(attack, "witcher_steel+1"); break;
			case "witcher_steel+2": EquipCharacterByItem(attack, "witcher_steel+2"); break;
			case "witcher_steel+3": EquipCharacterByItem(attack, "witcher_steel+3"); break;
		}
	}

	if(IsMainCharacter(attack) && DisableReloadWhileFighting()) PlaySound("PEOPLE\clothes1.wav");
}

#event_handler("witcher_steel_on_back", "back_witcher_steel");
void back_witcher_steel()
{
	aref attack = GetEventData();
	string weaponID = GetCharacterEquipByGroup(attack,BLADE_ITEM_TYPE);
	if (weaponID == "") return; // PB: Prevent potential error messages
	aref weapon;
	Items_FindItem(weaponID, &weapon);

	if(weapon.model == "witcher_steel")
	{
		if(IsEquipCharacterByItem(attack, "witcher_steel-2")) {attack.bladeID = "witcher_steel-2"}
		if(IsEquipCharacterByItem(attack, "witcher_steel-1")) {attack.bladeID = "witcher_steel-1"}
		if(IsEquipCharacterByItem(attack, "witcher_steel")) {attack.bladeID = "witcher_steel"}
		if(IsEquipCharacterByItem(attack, "witcher_steel+1")) {attack.bladeID = "witcher_steel+1"}
		if(IsEquipCharacterByItem(attack, "witcher_steel+2")) {attack.bladeID = "witcher_steel+2"}
		if(IsEquipCharacterByItem(attack, "witcher_steel+3")) {attack.bladeID = "witcher_steel+3"}

		weapon.model = "witcher_steel_back";
		RemoveCharacterEquip(attack, BLADE_ITEM_TYPE );
	
		if(CheckAttribute(attack,"bladeID"))
		{
			switch(attack.bladeID)
			{
				case "witcher_steel-2": EquipCharacterByItem(attack, "witcher_steel-2"); break;
				case "witcher_steel-1": EquipCharacterByItem(attack, "witcher_steel-1"); break;
				case "witcher_steel": EquipCharacterByItem(attack, "witcher_steel"); break;
				case "witcher_steel+1": EquipCharacterByItem(attack, "witcher_steel+1"); break;
				case "witcher_steel+2": EquipCharacterByItem(attack, "witcher_steel+2"); break;
				case "witcher_steel+3": EquipCharacterByItem(attack, "witcher_steel+3"); break;
			}
		}

		if(IsMainCharacter(attack) && DisableReloadWhileFighting()) PlaySound("PEOPLE\clothes1.wav");
	}
}

//---------------------------------------------------------------------------

#event_handler("mguns_reset_check", "reset_check_mguns");
void reset_check_mguns()
{
	ref PChar = GetMainCharacter();
	aref attack = GetEventData();
	ref tmpChr;
	float GunCurCharge;
	
	for (int i = 0; i < LAi_numloginedcharacters; i++)
	{
		int index = LAi_loginedcharacters[i];
		if (index >= 0)
		{
			makeref(tmpChr, Characters[index]);
		
			aref weapon;

			string weaponID2 = GetCharacterEquipByGroup(tmpChr,BLADE_ITEM_TYPE);
			aref weapon2;
			Items_FindItem(weaponID2, &weapon2);			

			if (!LAi_IsDead(tmpChr) && !LAi_IsFightMode(tmpChr))
			{
				GunCurCharge = LAi_GetCharacterRelCharge(tmpChr); // Levis
				if(IsEquipCharacterByItem(tmpChr, "pistolmket"))
				{
					if(CheckCharacterItem(tmpChr, "blade_mKnife"))
					{
						if(!IsEquipCharacterByItem(tmpChr, "blade_mKnife")) EquipCharacterByItem(tmpChr, "blade_mKnife");
					}

					Items_FindItem("pistolmket", &weapon);
					weapon.model = "musket_back";
					EquipCharacterByItem(tmpChr, "pistolmket");
					tmpChr.chr_ai.charge = GunCurCharge; // Levis
				}

				if(IsEquipCharacterByItem(tmpChr, "battleax"))
				{
					Items_FindItem("battleax", &weapon);
					weapon.model = "battleax_back";
					EquipCharacterByItem(tmpChr, "battleax");
				}
			
				if(IsEquipCharacterByItem(tmpChr, "witcher_steel-2") || IsEquipCharacterByItem(tmpChr, "witcher_steel-1") 
				|| IsEquipCharacterByItem(tmpChr, "witcher_steel") || IsEquipCharacterByItem(tmpChr, "witcher_steel+1") 
				|| IsEquipCharacterByItem(tmpChr, "witcher_steel+2") || IsEquipCharacterByItem(tmpChr, "witcher_steel+3"))
				{
					weapon2.model = "witcher_steel_back";

					if(IsEquipCharacterByItem(tmpChr, "witcher_steel-2")) {tmpChr.bladeID = "witcher_steel-2"}
					if(IsEquipCharacterByItem(tmpChr, "witcher_steel-1")) {tmpChr.bladeID = "witcher_steel-1"}
					if(IsEquipCharacterByItem(tmpChr, "witcher_steel")) {tmpChr.bladeID = "witcher_steel"}
					if(IsEquipCharacterByItem(tmpChr, "witcher_steel+1")) {tmpChr.bladeID = "witcher_steel+1"}
					if(IsEquipCharacterByItem(tmpChr, "witcher_steel+2")) {tmpChr.bladeID = "witcher_steel+2"}
					if(IsEquipCharacterByItem(tmpChr, "witcher_steel+3")) {tmpChr.bladeID = "witcher_steel+3"}

					if(CheckAttribute(tmpChr,"bladeID"))
					{
						switch(tmpChr.bladeID)
						{
							case "witcher_steel-2": EquipCharacterByItem(tmpChr, "witcher_steel-2"); break;
							case "witcher_steel-1": EquipCharacterByItem(tmpChr, "witcher_steel-1"); break;
							case "witcher_steel": EquipCharacterByItem(tmpChr, "witcher_steel"); break;
							case "witcher_steel+1": EquipCharacterByItem(tmpChr, "witcher_steel+1"); break;
							case "witcher_steel+2": EquipCharacterByItem(tmpChr, "witcher_steel+2"); break;
							case "witcher_steel+3": EquipCharacterByItem(tmpChr, "witcher_steel+3"); break;
						}
					}
				}
			
				if(IsEquipCharacterByItem(tmpChr, "blademketK"))
				{
					RemoveCharacterEquip(tmpChr, BLADE_ITEM_TYPE );
					TakeItemFromCharacter(tmpChr, "blademketK");
					GiveItem2Character(tmpChr, "blade_mKnife");
					EquipCharacterByItem(tmpChr, "blade_mKnife");

					GiveItem2Character(tmpChr, "pistolmket");
					EquipCharacterByItem(tmpChr, "pistolmket");
					tmpChr.chr_ai.charge = GunCurCharge; // Levis
				}

				if(IsEquipCharacterByItem(tmpChr, "pistolmtoon"))
				{
					Items_FindItem("pistolmtoon", &weapon);
					weapon.model = "musketoon_back";
					EquipCharacterByItem(tmpChr, "pistolmtoon");
					tmpChr.chr_ai.charge = GunCurCharge; // Levis
				}

				if(IsEquipCharacterByItem(tmpChr, "pistolmketB"))
				{
					Items_FindItem("pistolmketB", &weapon);
					weapon.model = "musketB_back";
					EquipCharacterByItem(tmpChr, "pistolmketB");
					tmpChr.chr_ai.charge = GunCurCharge; // Levis
				}

				if(IsEquipCharacterByItem(tmpChr, "blademketB"))
				{
					TakeItemFromCharacter(tmpChr, "blademketB");
				/*	if(!CheckCharacterItem(tmpChr, "bladeX4")) GiveItem2Character(tmpChr, "bladeX4");
					EquipCharacterByItem(tmpChr, "bladeX4");	*/
				EquipCharacterByItem(tmpChr, FindCharacterItemByGroup(tmpChr, BLADE_ITEM_TYPE));

					GiveItem2Character(tmpChr, "pistolmketB");
					EquipCharacterByItem(tmpChr, "pistolmketB");
					tmpChr.chr_ai.charge = GunCurCharge; // Levis
				}

				if(IsEquipCharacterByItem(tmpChr, "Arguebuse"))
				{
					Items_FindItem("Arguebuse", &weapon);
					weapon.model = "Arguebuse_back";
					EquipCharacterByItem(tmpChr, "Arguebuse");
					tmpChr.chr_ai.charge = GunCurCharge; // Levis
				}

				if(IsEquipCharacterByItem(tmpChr, "pistolbbuss"))
				{
					Items_FindItem("pistolbbuss", &weapon);
					weapon.model = "blunder1_10_back";
					EquipCharacterByItem(tmpChr, "pistolbbuss");
					tmpChr.chr_ai.charge = GunCurCharge; // Levis
				}

				if(IsEquipCharacterByItem(tmpChr, "pistol13"))
				{
					Items_FindItem("pistol13", &weapon);
					weapon.model = "pistol13_back";
					EquipCharacterByItem(tmpChr, "pistol13");
					tmpChr.chr_ai.charge = GunCurCharge; // Levis
				}

				if(IsEquipCharacterByItem(tmpChr, "LongRifle_C"))
				{
					Items_FindItem("LongRifle_C", &weapon);
					weapon.model = "LongRifle_C_back";
					EquipCharacterByItem(tmpChr, "LongRifle_C");
					tmpChr.chr_ai.charge = GunCurCharge; // Levis
				}

				if(IsEquipCharacterByItem(tmpChr, "LongRifle_H"))
				{
					Items_FindItem("LongRifle_H", &weapon);
					weapon.model = "LongRifle_H_back";
					EquipCharacterByItem(tmpChr, "LongRifle_H");
					tmpChr.chr_ai.charge = GunCurCharge; // Levis
				}

				if(IsEquipCharacterByItem(tmpChr, "LongRifle_W"))
				{
					Items_FindItem("LongRifle_W", &weapon);
					weapon.model = "LongRifle_W_back";
					EquipCharacterByItem(tmpChr, "LongRifle_W");
					tmpChr.chr_ai.charge = GunCurCharge; // Levis
				}

				if(IsEquipCharacterByItem(tmpChr, "portugize"))
				{
					float charge = stf(tmpChr.chr_ai.charge);
					Items_FindItem("portugize", &weapon);
					weapon.model = "portugize_back";
					EquipCharacterByItem(tmpChr, "portugize");
					tmpChr.chr_ai.charge = Charge;
				}
			}
		}
	}
}

#event_handler("mguns_fight_check", "fight_check_mguns");
void fight_check_mguns()
{
	ref PChar = GetMainCharacter();
	aref attack = GetEventData();
	ref tmpChr;
	float GunCurCharge;

	for (int i = 0; i < LAi_numloginedcharacters; i++)
	{
		int index = LAi_loginedcharacters[i];
		if (index >= 0)
		{
			makeref(tmpChr, Characters[index]);

			aref weapon;
			if (!LAi_IsDead(tmpChr) && LAi_IsFightMode(tmpChr))
			{
				GunCurCharge = LAi_GetCharacterRelCharge(tmpChr); // Levis

			    if(GunCurCharge < 1.0)
				{
					if(IsEquipCharacterByItem(tmpChr, "pistolmket"))
					{
						if(CheckCharacterItem(tmpChr, "blade_mKnife"))
						{
							if(!IsEquipCharacterByItem(tmpChr, "blade_mKnife")) EquipCharacterByItem(tmpChr, "blade_mKnife");
						}

						Items_FindItem("pistolmket", &weapon);
						weapon.model = "musket_back";
						EquipCharacterByItem(tmpChr, "pistolmket");
						tmpChr.chr_ai.charge = GunCurCharge; // Levis
					}

					if(IsEquipCharacterByItem(tmpChr, "pistolmtoon"))
					{
						Items_FindItem("pistolmtoon", &weapon);
						weapon.model = "musketoon_back";
						EquipCharacterByItem(tmpChr, "pistolmtoon");
						tmpChr.chr_ai.charge = GunCurCharge; // Levis
					}

					if(IsEquipCharacterByItem(tmpChr, "Arguebuse"))
					{
						Items_FindItem("Arguebuse", &weapon);
						weapon.model = "Arguebuse_back";
						EquipCharacterByItem(tmpChr, "Arguebuse");
						tmpChr.chr_ai.charge = GunCurCharge; // Levis
					}

					if(IsEquipCharacterByItem(tmpChr, "pistolbbuss"))
					{
						Items_FindItem("pistolbbuss", &weapon);
						weapon.model = "blunder1_10_back";
						EquipCharacterByItem(tmpChr, "pistolbbuss");
						tmpChr.chr_ai.charge = GunCurCharge; // Levis
					}

					if(IsEquipCharacterByItem(tmpChr, "pistol13"))
					{
						Items_FindItem("pistol13", &weapon);
						weapon.model = "pistol13_back";
						EquipCharacterByItem(tmpChr, "pistol13");
						tmpChr.chr_ai.charge = GunCurCharge; // Levis
					}

					if(IsEquipCharacterByItem(tmpChr, "LongRifle_C"))
					{
						Items_FindItem("LongRifle_C", &weapon);
						weapon.model = "LongRifle_C_back";
						EquipCharacterByItem(tmpChr, "LongRifle_C");
						tmpChr.chr_ai.charge = GunCurCharge; // Levis
					}

					if(IsEquipCharacterByItem(tmpChr, "LongRifle_H"))
					{
						Items_FindItem("LongRifle_H", &weapon);
						weapon.model = "LongRifle_H_back";
						EquipCharacterByItem(tmpChr, "LongRifle_H");
						tmpChr.chr_ai.charge = GunCurCharge; // Levis
					}

					if(IsEquipCharacterByItem(tmpChr, "LongRifle_W"))
					{
						Items_FindItem("LongRifle_W", &weapon);
						weapon.model = "LongRifle_W_back";
						EquipCharacterByItem(tmpChr, "LongRifle_W");
						tmpChr.chr_ai.charge = GunCurCharge; // Levis
					}

					if(IsEquipCharacterByItem(tmpChr, "portugize"))
					{
						float charge = stf(tmpChr.chr_ai.charge);
						Items_FindItem("portugize", &weapon);
						weapon.model = "portugize_back";
						EquipCharacterByItem(tmpChr, "portugize");
						tmpChr.chr_ai.charge = Charge;
					}
				}
			}
		}
	}
}

void SupplyAmmo(bool bOverride)
{
	if(ENABLE_AMMOMOD)
	{
		ref PChar = GetMainCharacter();
		ref NPChar;
		int i, iOfficer, cc;

		string weaponID;
		aref weapon;

		bool tmpAbleRefill = false;
		bool bGotAmmo      = false;
		if (bOverride)												{ tmpAbleRefill = true; }
		if (CharacterHasOfficerType(pchar, OFFIC_TYPE_CANNONEER))	{ tmpAbleRefill = true; }
		if (AMMOMOD_ABLECAPTAIN)									{ tmpAbleRefill = true; }

		if (tmpAbleRefill)
		{
			//PLAYER AND OFFICERS
			for(i = 0; i < 4; i++)
			{
				iOfficer = GetOfficersIndex(PChar, i);
				if(iOfficer < 0) continue;
				NPChar = GetCharacter(iOfficer);

				weaponID = GetCharacterEquipByGroup(NPChar,GUN_ITEM_TYPE);
				if(weaponID != "")
				{
					Items_FindItem(weaponID, &weapon);
					if(CheckAttribute(weapon, "shottype"))
					{
						if(weapon.shottype == "pg2" || weapon.shottype == "pg" || weapon.shottype == "mb" || weapon.shottype == "pb" || weapon.shottype == "pb2")
						{
							int OpriorGP = GetCharacterItem(NPChar,"gunpowder");
							int OpriorPB = GetCharacterItem(NPChar,"pistolbullets");
							int OpriorPG = GetCharacterItem(NPChar,"pistolgrapes");
							int OpriorMB = GetCharacterItem(NPChar,"musketbullets");

							DeleteAttribute(NPChar,"Items.gunpowder");
							DeleteAttribute(NPChar,"Items.pistolbullets");
							DeleteAttribute(NPChar,"Items.pistolgrapes");
							DeleteAttribute(NPChar,"Items.musketbullets");

							if(CheckCharacterItem(NPChar,"powderbarrel")) { TakeNItems(NPChar,"gunpowder", (4 * MAX_GUNPOWDER)); } 
							else
							{
								if(CheckCharacterItem(NPChar,"powderflask")) { TakeNItems(NPChar,"gunpowder", (2 * MAX_GUNPOWDER)); }
								else { TakeNItems(NPChar,"gunpowder", MAX_GUNPOWDER); }
							}
							if(CheckCharacterItem(NPChar,"ammobag")) { cc = (4 * MAX_SHOTS); }
							else
							{
								if(CheckCharacterItem(NPChar,"ammopouch")) { cc = (2 * MAX_SHOTS); }
								else { cc = MAX_SHOTS; }
							}
							//LogIt("cc = " + cc);
							if(cc > OpriorGP)																										{ bGotAmmo = true; }

							if(weapon.shottype == "pg2" || weapon.shottype == "pg")	{ TakeNItems(NPChar,"pistolgrapes" , cc);    if (cc > OpriorPG)	{ bGotAmmo = true; } }	
							if(weapon.shottype == "mb") 							{ TakeNItems(NPChar,"musketbullets", cc/2);  if (cc > OpriorMB)	{ bGotAmmo = true; } }
							if(weapon.shottype == "pb2" || weapon.shottype == "pb")	{ TakeNItems(NPChar,"pistolbullets", cc);    if (cc > OpriorPB)	{ bGotAmmo = true; } }
						}
					}
				}
			}
			if(bGotAmmo)
			{
				LogIt(TranslateString("","Your shore party has been resupplied with Ammunition!"));
				PlaySound("INTERFACE\important_item.flac");
			}
		}
	}
}
// <-- JRH