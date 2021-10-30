// the file NK.c was renamed to BuildSettings.h
// as of 05-07-03 it will now have my misc functions.
// moved these here from Console.c, they help in debug/testing.

// this block allows you to regain control of pchar after a delay. Useful in testing AI funcs on pchar,
// and then getting control back to reset the situation.
// call it with postevent("resetpchar_event", msec); where msec is the delay in ms.
#event_handler("resetpchar_event", "resetpchar");
void resetpchar()
{
	LAi_SetPlayerType(GetMainCharacter());
}

// resets all skills/perks to allow custom assignment
void ResetChar_Cheat(ref ch)
{
	ch.skill.Leadership = 1;
	ch.skill.Fencing = 1;
	ch.skill.Sailing = 1;
	ch.skill.Accuracy = 1;
	ch.skill.Cannons = 1;
	ch.skill.Grappling = 1;
	ch.skill.Repair = 1;
	ch.skill.Defence = 1;
	ch.skill.Commerce = 1;
	ch.skill.Sneak = 1;

	ch.skill.freeskill = sti(ch.rank) * 2;
	DeleteAttribute(ch,"perks");
	ch.perks.freepoints = sti(ch.rank);
	ResetHP(ch); // 05-07-03 use new func
	/*if(sti(ch.index) == GetMainCharacterIndex())
	{
		LAi_SetHP(&ch, LAI_DEFAULT_HP + sti(ch.rank) * 5, LAI_DEFAULT_HP + sti(ch.rank) * 5);
	}
	else { LAi_SetHP(&ch, LAI_DEFAULT_HP + sti(ch.rank) * makeint(11-GetDifficulty()), LAI_DEFAULT_HP + sti(ch.rank) * makeint(11-GetDifficulty())); }*/
}

// creates ship of id shipname, speed srate, turn trate, and max gun caliber cal. Gives long guns of that caliber, and full crew.
void CreateShip_Cheat(string shipname, int nat, float srate, float trate, int cal)
{
	ref pchar = GetMainCharacter();
	pchar.ship.type = shipname;
	int iShipType = GetCharacterShipType(pchar); // KK
	aref arship; makearef(arship, pchar.ship); DeleteAttribute(arship,"stats");
	SetRandomStatsToShip(GetMainCharacterIndex(), iShipType, nat); // KK
	arship.stats.maxcaliber = cal; arship.stats.speedrate = srate; arship.stats.turnrate = trate; arship.cannons.type = GetCannonByTypeAndCaliber("long gun", cal);
	SetCrewQuantity(&pchar, GetMaxCrewQuantity(&pchar));
// KK -->
	if (FindLoadedLocation() >= 0 && locNumShips > 0) {
		DeleteRiggingEnvironment();
		LocLoadShips(&Locations[FindLoadedLocation()]);
	}
// <-- KK
}

// repairs all damage--HP and SP, fixes masts, and removes blots. Masts do not appear until reload sea.
// also resets crew qty and sets morale at max, and sets balls at 700.
void RepairShip_Cheat()
{
	ref pchar = GetMainCharacter();
	ResetCannons(pchar);
	DeleteAttribute(&pchar,"ship.masts");
	pchar.ship.hp = GetCharacterShipHP(pchar) / 9.5;
	pchar.ship.sp = 0.5;
	SetCrewQuantity(&pchar, GetMaxCrewQuantity(&pchar));
	pchar.ship.crew.morale = MORALE_MAX;
	pchar.seatime.basecrewmorale = MORALE_MAX;
	pchar.seatime.tempmorale = MORALE_MAX;
	ProcessSailRepair(&pchar,100.0);
	ProcessHullRepair(&pchar, 100.0);
	SetCharacterGoods(&pchar, GOOD_BALLS, 700);
}


string GetPlayerTypeName(int player_type)
{
	string ret = OFFIC_TYPE_REGCAP;
	switch (player_type)
	{
		// JRMM -->
		case PLAYER_TYPE_ADVENTURER:     	ret = PLAYERTYPE_ADVENTURER;    break;
		case PLAYER_TYPE_AGENT:        		ret = PLAYERTYPE_AGENT;         break;
		case PLAYER_TYPE_MILITARY:       	ret = PLAYERTYPE_MILITARY;      break;
		case PLAYER_TYPE_CORSAIR:        	ret = PLAYERTYPE_CORSAIR;       break;
		case PLAYER_TYPE_ENGINEER:        	ret = PLAYERTYPE_ENGINEER;      break;
		case PLAYER_TYPE_EXPLORER:        	ret = PLAYERTYPE_EXPLORER;      break;
		case PLAYER_TYPE_GAMBLER:       	ret = PLAYERTYPE_GAMBLER;       break;
		case PLAYER_TYPE_GUNNER:       		ret = PLAYERTYPE_GUNNER;        break;
		case PLAYER_TYPE_MARINE:        	ret = PLAYERTYPE_MARINE;        break;
		case PLAYER_TYPE_MERCHANT:       	ret = PLAYERTYPE_MERCHANT;      break;
		case PLAYER_TYPE_NAVAL_OFFICER:		ret = PLAYERTYPE_NAVALOFFICER;  break;
		case PLAYER_TYPE_PHYSICIAN:      	ret = PLAYERTYPE_PHYSICIAN;     break;
		case PLAYER_TYPE_QUARTERMASTER:		ret = PLAYERTYPE_QUARTERMASTER; break;
		case PLAYER_TYPE_REBEL:      		ret = PLAYERTYPE_REBEL; 		break;
		case PLAYER_TYPE_ROGUE:      	  	ret = PLAYERTYPE_ROGUE;         break;
		case PLAYER_TYPE_SAILOR:       		ret = PLAYERTYPE_SAILOR;        break;
		case PLAYER_TYPE_SHIPWRIGHT:		ret = PLAYERTYPE_SHIPWRIGHT;    break;
		case PLAYER_TYPE_SMUGGLER:       	ret = PLAYERTYPE_SMUGGLER;      break;
		case PLAYER_TYPE_SOCIAL_CLIMBER: 	ret = PLAYERTYPE_SOCIALCLIMBER; break;
		case PLAYER_TYPE_SWORD_MASTER: 		ret = PLAYERTYPE_SWORDMASTER;   break;
		case PLAYER_TYPE_CURSED: 			ret = PLAYERTYPE_CURSED;   		break;
		case PLAYER_TYPE_CASTAWAY: 			ret = PLAYERTYPE_CASTAWAY;   	break;
		case PLAYER_TYPE_CUSTOM:         	ret = PLAYERTYPE_CUSTOM;		break;
		case PLAYER_TYPE_LAND_OWNER:        ret = PLAYERTYPE_LAND_OWNER;	break;
		// JRMM <--
	}
	return ret;
}

string GetPlayerType(ref chr)
{
	return GetPlayerTypeName(sti(GetAttribute(chr, "PlayerType")));
}

string GetCaptainType(ref chr)
{
	string CaptainType = OFFIC_TYPE_REGCAP;
	if (IsCompanion(chr))
	{
		if (HasMerchantPassport(GetMainCharacter()))		CaptainType = OFFIC_TYPE_CAPMERCHANT;
		if (IsMainCharacter(chr))
		{
			if (CheckAttribute(chr, "isnotcaptain"))		CaptainType = OFFIC_TYPE_NAVIGATOR;
		}
		if (GetLetterOfMarqueQuantity() > 0)				CaptainType = OFFIC_TYPE_CAPPRIVATEER;
		if (HaveLetterOfMarque(ProfessionalNavyNation()))	CaptainType = OFFIC_TYPE_CAPNAVY;
		if (GetServedNation() == PIRATE)					CaptainType = OFFIC_TYPE_CAPPIRATE;
	}
	else
	{
		if (CheckAttribute(chr, "FantomType"))
		{
			switch(chr.FantomType)
			{
				case "trade":								CaptainType = OFFIC_TYPE_CAPMERCHANT;	break;
				case "pirate":								CaptainType = OFFIC_TYPE_CAPPIRATE;		break;
				case "war":
					if (sti(chr.nation) == PIRATE)			CaptainType = OFFIC_TYPE_CAPPRIVATEER; // PB: I think this never happens
					else									CaptainType = OFFIC_TYPE_CAPNAVY;
				break;
			}
		}
	}
	return CaptainType;
}

float CaptainMultFromOfficerType(string ftype) //Levis
{
	switch(ftype)
	{
		case OFFIC_TYPE_CAPPIRATE: return 1.25; break;
		case OFFIC_TYPE_CAPMERCHANT: return 1.0; break;
		case OFFIC_TYPE_CAPNAVY: return 1.25; break;
		case OFFIC_TYPE_CAPPRIVATEER: return 1.25; break;
	}
	return 1.0;
}

bool HasMerchantPassport(ref chr)
{
	if (CheckCharacterItem(chr, "EITC_Passport"))	return true;
	if (CheckCharacterItem(chr, "Trade_Passport"))	return true;
	if (CheckCharacterItem(chr, "Trade_PassportE"))	return true;
	if (CheckCharacterItem(chr, "Trade_PassportF"))	return true;
	if (CheckCharacterItem(chr, "Trade_PassportS"))	return true;
	if (CheckCharacterItem(chr, "Trade_PassportH"))	return true;
	if (CheckCharacterItem(chr, "Trade_PassportP"))	return true;
	return false;
}

void LevelUp_Cheat(ref rCharacter, bool real)
{
	if(!real) 
	{
		int oldxp = sti(rCharacter.Experience);
		if(!CheckAttribute(rCharacter,"FakeLevels")) rCharacter.FakeLevels = 0;
		rCharacter.FakeLevelUp = true;
		rCharacter.rank = sti(rCharacter.rank) + sti(rCharacter.FakeLevels);
		rCharacter.Experience = CalculateExperienceFromRank(sti(rCharacter.rank));
	}
	int xp = CalculateExperienceFromRank(sti(rCharacter.rank)+1)-sti(rCharacter.Experience);
	AddXPtoChar(rCharacter, "", xp); //We use this function to prevent shared experience etc to work and to bypass the multipliers
	if(!real)
	{
		rCharacter.Experience = oldxp;
		rCharacter.FakeLevels = sti(rCharacter.FakeLevels) + 1;
		rCharacter.rank = sti(rCharacter.rank) - sti(rCharacter.FakeLevels);
		DeleteAttribute(rCharacter,"FakeLevelUp");
	}
/*	if(AUTO_SKILL_SYSTEM)
	{
		rCharacter.quest.officertype = GetCaptainType(rCharacter);
		if (rCharacter.quest.officertype == OFFIC_TYPE_REGCAP)			rCharacter.quest.officertype = OFFIC_TYPE_CAPMERCHANT;    // PB: Because the "captain" type isn't fully operational
		if (rCharacter.quest.officertype == OFFIC_TYPE_CAPPRIVATEER)	rCharacter.quest.officertype = OFFIC_TYPE_CAPNAVY;        // PB: Because the "privateer captain" type isn't used
		if (rCharacter.quest.officertype == OFFIC_TYPE_NAVIGATOR)		rCharacter.quest.officertype = OFFIC_TYPE_CAPNAVY;        // PB: Because the "navigator" type isn't meant for this
		LAi_Officer_SetSkillmodifiers_and_Perks(rCharacter, 0);
		LAi_SetSkill_on_Modifier(rCharacter);
	}*/
}

void Promote_Cheat(ref rCharacter, int iNation)
{
	ref ch;
	switch(iNation)
	{
		case ENGLAND:
			ch = CharacterFromID("John Clifford Brin");
		break;
		case FRANCE:
			ch = CharacterFromID("Joseph Claude Le Moigne");
		break;
		case SPAIN:
			ch = CharacterFromID("Christofor Manuel De Alencar");
		break;
		case HOLLAND:
			ch = CharacterFromID("Reynard Grueneveldt");
		break;
		case PIRATE:
			ch = CharacterFromID("Isenbrandt Jurcksen");
		break;
		case PORTUGAL:
			ch = CharacterFromID("Jacinto Arcibaldo Barreto");
		break;
		case AMERICA:
			ch = CharacterFromID("Cole Arkwright");
		break;
		case PERSONAL_NATION:
			return; // No promotions for your own nation
		break;
	}
	Promote(rCharacter, ch, iNation);
}

void GiveShip2Character(ref char, string shiptype, string shipname, int cannon_type, int nat, bool hirecrew, bool getsupplies)
{
// KK -->
	if(shiptype != SHIP_CURSED) // PB
	{
		int ship_type = GetShipIndex(shiptype);
		if (ship_type < 0 || ship_type == SHIP_NOTUSED) return;
		if (ship_type >= SHIP_TYPES_QUANTITY && shiptype != "Boat") return;
	}
// <-- KK
	char.ship.type = shiptype;
	char.ship.name = shipname;
	aref arship; makearef(arship, char.ship);
	DeleteAttribute(arship,"stats");
// KK -->
	// PB: No free upgrades -->
	if(shiptype != SHIP_CURSED) arSetRandomStatsToShip(arship, ship_type, nat);
	DeleteAttribute(char, "ship.tune");
	// PB: No free upgrades <--
	ref rShip = GetShipByType(GetCharacterShipType(char));
	if (cannon_type != CANNON_TYPE_NONECANNON) {
		ResetCannons(char);
		if (cannon_type < 0 || cannon_type >= CANNON_TYPES_QUANTITY) cannon_type = sti(rShip.Cannon);
/*		int max_caliber = sti(rShip.MaxCaliber);
		int cannon_model = GetCannonType(cannon_type);
		if (sti(GetAttribute(Cannon[cannon_type],"caliber")) > max_caliber) {
			string sCannonType = "long gun";
			if (cannon_model == CANNON_NAME_CARRONADE) sCannonType = "carronade";
			cannon_type = GetCannonByTypeAndCaliber(sCannonType, max_caliber);
		}*/
		char.Ship.Cannons.Type = cannon_type;
	} else {
		SetNoneCannonsOnShip(char);
	}
// <-- KK
	DeleteAttribute(&char,"ship.masts");
// LDH -->
	char.ship.sp = GetCharacterShipSP(char);
// KK -->
	int temp;
	if (CheckAttribute(char, "Ship.Sails")) {
		temp = sti(char.ship.sails);
		DeleteAttribute(char,"ship.sails");
		char.ship.sails = temp;
	}
// <-- KK
	char.ship.hp = GetCharacterShipHP(char);
	// this doen't do anything on sea or dock, only on land away from sea
	DeleteBlots(char,GetBlotsQuantity(char));
// <-- LDH
	if(hirecrew || sti(GetCrewQuantity(&char)) > sti(GetMaxCrewQuantity(&char)))
	{
		SetCrewQuantity(&char, GetMaxCrewQuantity(&char));
	}
//	for (int i = 0; i < GOODS_QUANTITY; i++) AddCharacterGoods(char, i, 0); // KK
	if(getsupplies || sti(GetCargoLoad(&char)) > sti(GetCargoMaxSpace(&char)))
	{
		EmptyShip (char); // First remove all goods from the ship
		SupplyShip(char); // Then add them again
	}
// KK -->
	if (FindLoadedLocation() >= 0 && locNumShips > 0) {
		DeleteRiggingEnvironment();
		LocLoadShips(&Locations[FindLoadedLocation()]);
	}
// <-- KK
}

void EmptyShip(ref char)
{
	string goodsName;
	for(int i=0;i<GOODS_QUANTITY;i++)
	{
		goodsName = Goods[i].name;
		char.Ship.Cargo.Goods.(goodsName) = 0;
	}
	RecalculateCargoLoad(char);
}

void SupplyShip(ref char)
{
	float SupplyScalar = SupplyScalarByCharacter       (char);
	float crewQty      = makefloat(GetCrewQuantity     (char));
	float canQty       = makefloat(GetMaxCannonQuantity(char));
	float shipHP       = makefloat(GetCharacterShipHP  (char));
	if(FOOD_ON)				AddCharacterGoods(char, GOOD_WHEAT   , 1+makeint(crewQty * FOOD_PER_CREW * WHEAT_DAYS * SupplyScalar));
	if(FOOD_ON)				AddCharacterGoods(char, GOOD_RUM     , 1+makeint(crewQty * FOOD_PER_CREW * RUM_DAYS   * SupplyScalar));
							AddCharacterGoods(char, GOOD_BALLS   ,   makeint(canQty  * BALLS_PER                  * SupplyScalar));
							AddCharacterGoods(char, GOOD_GRAPES  ,   makeint(canQty  * GRAPE_PER                  * SupplyScalar));
							AddCharacterGoods(char, GOOD_KNIPPELS,   makeint(canQty  * CHAIN_PER                  * SupplyScalar));
	if(!USE_REAL_CANNONS)	AddCharacterGoods(char, GOOD_BOMBS   ,   makeint(canQty  * BOMBS_PER                  * SupplyScalar));
	if(CANNONPOWDER_MOD && canQty > 0.0)
	{
		int PowderPerShot = 0;
		ref rCannon; makeref(rCannon,Cannon[GetCaracterShipCannonsType(char)]);
		int shotQty = GetCargoGoods(&char,GOOD_BALLS) + GetCargoGoods(&char,GOOD_GRAPES) + GetCargoGoods(&char,GOOD_KNIPPELS) + GetCargoGoods(&char,GOOD_BOMBS);
		if(CheckAttribute(rCannon,"gunpowder")) PowderPerShot = sti(rCannon.gunpowder);
		AddCharacterGoods(char, GOOD_GUNPOWDER, makeint(POWDER_PER * shotQty * PowderPerShot * SupplyScalar));
	}
	AddCharacterGoods(char, GOOD_SAILCLOTH, makeint(shipHP * SAIL_PER   * SupplyScalar));
	AddCharacterGoods(char, GOOD_PLANKS   , makeint(shipHP * PLANKS_PER * SupplyScalar));
}

int GetSupplyWeight(ref refShip)
{
	int   TotalWeight  = 0;
	float SupplyScalar = SupplyScalarByShip(refShip);
	float crewQty      = stf(refShip.MaxCrew);
	float canQty       = stf(refShip.CannonsQuantity);
	float shipHP       = stf(refShip.HP);
	if(FOOD_ON)				TotalWeight += GetGoodWeightByType(GOOD_WHEAT   , 1+makeint(crewQty * FOOD_PER_CREW * WHEAT_DAYS * SupplyScalar));
	if(FOOD_ON)				TotalWeight += GetGoodWeightByType(GOOD_RUM     , 1+makeint(crewQty * FOOD_PER_CREW * RUM_DAYS   * SupplyScalar));
							TotalWeight += GetGoodWeightByType(GOOD_BALLS   ,   makeint(canQty  * BALLS_PER                  * SupplyScalar));
							TotalWeight += GetGoodWeightByType(GOOD_GRAPES  ,   makeint(canQty  * GRAPE_PER                  * SupplyScalar));
							TotalWeight += GetGoodWeightByType(GOOD_KNIPPELS,   makeint(canQty  * CHAIN_PER                  * SupplyScalar));
	if(!USE_REAL_CANNONS)	TotalWeight += GetGoodWeightByType(GOOD_BOMBS   ,   makeint(canQty  * BOMBS_PER                  * SupplyScalar));
	if(CANNONPOWDER_MOD && canQty > 0.0)
	{
		float PowderPerShot = 0.0;
		ref rCannon; makeref(rCannon,Cannon[sti(refShip.Cannon)]);
		float shotQty 					 = canQty * BALLS_PER * SupplyScalar;
		shotQty    						+= canQty * GRAPE_PER * SupplyScalar;
		shotQty    						+= canQty * CHAIN_PER * SupplyScalar;
		if(!USE_REAL_CANNONS)	shotQty += canQty * BOMBS_PER * SupplyScalar;
		if(CheckAttribute(rCannon,"gunpowder")) PowderPerShot = stf(rCannon.gunpowder);
		TotalWeight += GetGoodWeightByType(GOOD_GUNPOWDER, makeint(POWDER_PER * shotQty * PowderPerShot * SupplyScalar));
	}
	TotalWeight += GetGoodWeightByType(GOOD_SAILCLOTH, makeint(shipHP * SAIL_PER   * SupplyScalar));
	TotalWeight += GetGoodWeightByType(GOOD_PLANKS   , makeint(shipHP * PLANKS_PER * SupplyScalar));
	return TotalWeight;
}

// KK -->
void CreatePortLandscape(string sPortLandscape)
{
	int i = 0;
	int j = 0;
	int inum = 0;
	int jnum = 0;
	int locidx = FindLocation(sPortLandscape);
	string gmfile, sLandscape, port, island;
	ref deck, rIsland;
	aref arLandscapes;
	ref PChar = GetMainCharacter();
	if (locidx < 0) return;
	makeref(deck, Locations[FindLocation(GetCharacterShipQDeck(PChar))]);
	if (!CheckAttribute(&Locations[locidx], "models.always.l1")) return;
	if (CheckAttribute(deck, "models.always.port1")) DeleteAttribute(deck,"models.always.port1");
	if (CheckAttribute(deck, "models.always.port2")) DeleteAttribute(deck,"models.always.port2");
	arLandscapes = GetFiles("RESOURCE\MODELS\" + Locations[locidx].filespath.models, "*_landscape.gm");
	inum = GetAttributesNum(arLandscapes);
	for (i = 0; i < inum; i++) {
		gmfile = GetAttributeValue(GetAttributeN(arLandscapes, i));
		gmfile = strcut(gmfile, 0, strlen(gmfile) - 4);
		sLandscape = Locations[locidx].filespath.models + "\" + gmfile;
		port = "port" + (i + 1);
		deck.models.always.(port) = "..\..\..\" + sLandscape;
	}
	island = Locations[locidx].island;
	rIsland = GetIslandByID(island);
	if (CheckAttribute(deck, "locators.ships_other")) DeleteAttribute(deck, "locators.ships_other");
	deck.locators.ships_other = "";
	aref dships; makearef(dships, deck.locators.ships_other);
	aref arIslandReload; makearef(arIslandReload, rIsland.reload);
	int num = GetAttributesNum(arIslandReload);
	for (i = 0; i < num; i++) {
		aref curReload = GetAttributeN(arIslandReload, i);
		if (curReload.go == sPortLandscape) {
			aref iships; makearef(iships, curReload.ships);
			jnum = GetAttributesNum(iships);
			for (j = 0; j < jnum; j++) {
				aref ariship = GetAttributeN(iships, j);
				string l = GetAttributeName(ariship);
				dships.(l) = "";
				aref ardship; makearef(ardship, dships.(l));
				CopyAttributes(ardship, ariship);
			}
		}
	}
}

void DeletePortLandscape()
{
	ref PChar = GetMainCharacter();
	ref deck = &Locations[FindLocation(GetCharacterShipQDeck(PChar))];
	if (CheckAttribute(deck, "models.always.port1")) DeleteAttribute(deck,"models.always.port1");
	if (CheckAttribute(deck, "models.always.port2")) DeleteAttribute(deck,"models.always.port2");
}

string IsPortLandscapeEnabled(string sLocation)
{
	int locidx, llocidx;
	bool bEnable = bCanEnterToLand;
	ref deck, port;
	locidx = FindLocation(sLocation);
	if (locidx < 0) return "";
	makeref(port, Locations[locidx]); 
	llocidx = FindLocation(Characters[GetMainCharacterIndex()].location);
	if (llocidx < 0) return "";
	makeref(deck, Locations[llocidx]);
	if (llocidx > 0 && HasSubStr(deck.id, "ShipDeck") == false) return "";
	if (CheckAttribute(deck, "PortLandscape")) {
		if (sti(deck.PortLandscape) == true) bEnable = true;
		DeleteAttribute(deck, "PortLandscape");
	}
	if (!bEnable) return "";
	if (!CheckAttribute(port, "filespath.models") || !CheckAttribute(port, "models.always.l1")) return "";
	if (FindFile("RESOURCE\MODELS\" + port.filespath.models, "*_landscape.gm", port.models.always.l1 + "_landscape.gm") != "") return sLocation;
	return "";
}
// <-- KK

// ----------------
// PB FUNCTIONS -->
// ----------------

bool EnableLimitedShipClass()
{
	if (iRealismMode>0)						return true;
	if (ENABLE_LIMITED_SHIPCLASS)			return true;
											return false;
}

int DynamicInterfaceLevel()
{
	if (sti(GetStorylineVar(FindCurrentStoryline(), "DYNAMIC_INTERFACES")) == 1)	return 1;
	if (bAnimation)																	return 2;
	else																			return 0;
}

bool DisableReloadWhileFighting() // PB: To allow CANNOT_RELOAD_WHILE_FIGHTING to override the Realism Mode
{
	if (CANNOT_RELOAD_WHILE_FIGHTING == 0)	return false;
	if (CANNOT_RELOAD_WHILE_FIGHTING == 2)	return true;
	if (iRealismMode>0)						return true;
											return false;
}

string LogsToggleDescription()
{
	switch(LogsToggle)
	{
		case LOG_QUIET:		return "Quiet";		break;
		case LOG_LACONIC:	return "Laconic";	break;
		case LOG_NORMAL:	return "Normal";	break;
		case LOG_VERBOSE:	return "Verbose";	break;
	}
}

string Cheat_ScrollCharacterName(int charnum)
{
	string logmessage;
	ref PChar = GetMainCharacter();
	if (charnum == 0)
	{
		logmessage = "player, " + GetMySimpleName(PChar);
	}
	else
	{
		if (charnum > 0 && charnum < OFFICER_MAX)
		{
			logmessage = "officer, " + GetMySimpleName( GetCharacter(GetOfficersIndex (PChar, charnum)) );
		}
		else
		{
			logmessage = "companion, " + GetMySimpleName( GetCharacter(GetCompanionIndex(PChar, charnum-OFFICER_MAX+1)) );
		}
	}
	return logmessage;
}

int Cheat_GetCharacterIndex(int charnum)
{
	int charIndex;
	ref PChar = GetMainCharacter();
	if (charnum == 0)
	{
		charIndex = GetMainCharacterIndex();
	}
	else
	{
		if (charnum > 0 && charnum < OFFICER_MAX)
		{
			charIndex = GetOfficersIndex (PChar, charnum);
		}
		else
		{
			charIndex = GetOfficersIndex (PChar, charnum-OFFICER_MAX+1);
		}
	}
	return charIndex;
}

void JoinNavy(int iNation)
{
	int i;
	ref ch;
	string model;
	ref pchar = GetMainCharacter();

	if(iNation == PERSONAL_NATION)
	{
		DeleteAttribute(pchar, "professionalnavy");
		return;
	}

	SetRelationsAsNation (iNation);
	ReceiveLetterOfMarque(iNation);

	if(iNation != PIRATE)
	{
		SetRank(pchar, iNation, 1);
		pchar.professionalnavy = iNation;

		pchar.boardingmodels = "Soldiers";
		pchar.boardingmodels.nation = iNation;
		for (i = 1; i <= 5; i++)
		{
			ch = CharacterFromID("Crewmember_0" + i);
			model = GetRandomModelForTypeExSubCheck(true, "Soldiers", "man", iNation);
			SetModelfromArray(ch, GetModelIndex(model));
		}
		for (i = 1; i <= 10; i++)
		{
			ch = CharacterFromID("Treas_Crewmember_" + i);
			model = GetRandomModelForTypeExSubCheck(true, "Soldiers", "man", iNation);
			SetModelfromArray(ch, GetModelIndex(model));
		}
	}
	else
		DeleteAttribute(pchar, "professionalnavy");
}

void GivePromotionReward(int iNation)
{
	ref pchar = GetMainCharacter();
	ref ch;
	string qual = "";
	if (ENABLE_WEAPONSMOD) qual = "+2";

	int PlayerRank     = GetRank(pchar, iNation);

	// Nations Relations Tutorial
	if (!CheckAttribute(pchar, "Got_Relation_Book") && iNation != PIRATE)
	{
		GiveItem2Character(pchar, "relationbook");
		PChar.Got_Relation_Book = true;
	}
	if (!CheckAttribute(pchar, "Got_Pirate_Book") && iNation == PIRATE)
	{
		GiveItem2Character(pchar, "piratebook");
		PChar.Got_Pirate_Book = true;
	}

	// Sword and Abilities
	GiveSwordAndPerks(PlayerRank, iNation);

	// Player Uniform
	string PlayerModel = OfficerUniform4Player(PlayerRank, iNation);
	if (PlayerModel != "") GiveModel2Player(PlayerModel, true);

	// Officers
	GivePromotionOfficers(PlayerRank, iNation);

	// Fleet
	if (ProfessionalNavyNation() == UNKNOWN_NATION) return; // only for navy characters
	switch(iNation)
	{
		case ENGLAND:
			switch(PlayerRank)
			{
				case 1: // Midshipman
					switch (GetMySimpleOldName(PChar))
					{
						case "Horatio Hornblower":
							GiveShip2Character(pchar, "PO_Hoy", "Caroline", -1, ENGLAND, true, true); // Hoy
						break;

						//default:
						switch(GetCurrentPeriod())
						{
							case PERIOD_EARLY_EXPLORERS:
								GiveShip2Character(pchar, "Cutter2", "Minion", -1, ENGLAND, true, true); // Sloop
							break;

							case PERIOD_THE_SPANISH_MAIN:
								GiveShip2Character(pchar, "KetchNavy", "Seaflower", -1, ENGLAND, true, true); // Naval Ketch
							break;

							case PERIOD_GOLDEN_AGE_OF_PIRACY:
								GiveShip2Character(pchar, "KetchNavy", "Morning Star", -1, ENGLAND, true, true); // Naval Ketch
							break;

							case PERIOD_COLONIAL_POWERS:
								GiveShip2Character(pchar, "PO_Hoy", "Forester", -1, ENGLAND, true, true); // Lyon Hoy
							break;

							case PERIOD_REVOLUTIONS:
								GiveShip2Character(pchar, "PO_Hoy", "Black Joke", -1, ENGLAND, true, true); // Lyon Hoy
							break;

							case PERIOD_NAPOLEONIC:
								GiveShip2Character(pchar, "Cutter2", "Witch of Endor", -1, ENGLAND, true, true); // Naval Cutter
							break;
						}
					}
				break;
				case 2: // Junior Lieutenant
					switch (GetMySimpleOldName(PChar))
					{
						case "Horatio Hornblower":
							GiveShip2Character(pchar, "Cutter2", "Witch of Endor", -1, ENGLAND, true, true); // Naval Cutter
						break;

						//default:
						switch(GetCurrentPeriod())
						{
							case PERIOD_EARLY_EXPLORERS:
								GiveShip2Character(pchar, "Sloop2", "Hare", -1, ENGLAND, true, true); // Naval Cutter
							break;

							case PERIOD_THE_SPANISH_MAIN:
								GiveShip2Character(pchar, "Sloop2", "Dolphin", -1, ENGLAND, true, true); // Naval Cutter
							break;

							case PERIOD_GOLDEN_AGE_OF_PIRACY:
								GiveShip2Character(pchar, "Sloop2", "Shark", -1, ENGLAND, true, true); // Naval Cutter
							break;

							case PERIOD_COLONIAL_POWERS:
								GiveShip2Character(pchar, "Sloop2", "Success", -1, ENGLAND, true, true); // Naval Cutter
							break;

							case PERIOD_REVOLUTIONS:
								GiveShip2Character(pchar, "HMS_Bounty", "Bounty", -1, ENGLAND, true, true); // HMS Bounty
							break;

							case PERIOD_NAPOLEONIC:
								GiveShip2Character(pchar, "HMS_Interceptor", "Interceptor", -1, ENGLAND, true, true); // Fast Brig
							break;
						}
					}
				break;
				case 3: // Lieutenant
					switch (GetMySimpleOldName(PChar))
					{
						case "Horatio Hornblower":
							GiveShip2Character(pchar,"FR_Sloop","Le Rиve",-1,FRANCE,true,true); // Captured from the French
						break;

						case "Jack Aubrey":
							GiveShip2Character(pchar,"HMS_Sophie", "Sophie", -1, ENGLAND, true, true);
						break;

						case "James Norrington":
							GiveShip2Character(pchar, "HMS_Interceptor", "Interceptor", -1, ENGLAND, true, true); // Fast Brig
						break;

						//default:
						switch(GetCurrentPeriod())
						{
							case PERIOD_EARLY_EXPLORERS:
								GiveShip2Character(pchar, "Caravel2", "George", -1, ENGLAND, true, true); // Caravela Redonda
							break;

							case PERIOD_THE_SPANISH_MAIN:
								GiveShip2Character(pchar, "BrigRoyal", "Hunter", -1, ENGLAND, true, true); // Sloop-of-War
							break;

							case PERIOD_GOLDEN_AGE_OF_PIRACY:
								GiveShip2Character(pchar, "RN_Brig", "Drake", -1, ENGLAND, true, true); // Sloop-of-War
							break;

							case PERIOD_COLONIAL_POWERS:
								GiveShip2Character(pchar, "RN_Brig", "Jamaica", -1, ENGLAND, true, true); // Sloop-of-War
							break;

							case PERIOD_REVOLUTIONS:
								GiveShip2Character(pchar, "HMS_Speedy", "Badger", -1, ENGLAND, true, true); // Speedy class Brig
							break;

							case PERIOD_NAPOLEONIC:
								GiveShip2Character(pchar, "HMS_Sophie", "Sophie", -1, ENGLAND, true, true); // Brig Sloop
							break;
						}
					}
				break;
				case 4: // Senior Lieutenant
					switch (GetMySimpleOldName(PChar))
					{
						case "Horatio Hornblower":
							GiveShip2Character(pchar, "RN_Volage", "Hotspur", -1, ENGLAND, true, true); // Heavy Sloop-of-War
						break;

						case "Horatio Nelson":
							GiveShip2Character(pchar, "HMS_Greyhound", "Hinchinbrook", -1, ENGLAND, true, true); // 6th rate frigate
						break;

						case "Jack Aubrey":
							GiveShip2Character(pchar,"RN_Volage", "Polychrest", -1, ENGLAND, true, true);
						break;

						//default:
						switch(GetCurrentPeriod())
						{
							case PERIOD_EARLY_EXPLORERS:
								GiveShip2Character(pchar, "FR_Derfflinger", "Flower de Luce", -1, ENGLAND, true, true); // Fluyt
							break;

							case PERIOD_THE_SPANISH_MAIN:
								GiveShip2Character(pchar, "FR_NeptunusE", "Swann", -1, ENGLAND, true, true); // Sloop-of-War
							break;

							case PERIOD_GOLDEN_AGE_OF_PIRACY:
								GiveShip2Character(pchar, "RN_Postillionen", "Enterprise", -1, ENGLAND, true, true); // 6th Rate Frigate
							break;

							case PERIOD_COLONIAL_POWERS:
								GiveShip2Character(pchar, "HMS_Greyhound", "Andromeda", -1, ENGLAND, true, true); // 6th Rate Frigate
							break;

							case PERIOD_REVOLUTIONS:
								GiveShip2Character(pchar, "HMS_Greyhound", "Andromeda", -1, ENGLAND, true, true); // 6th Rate Frigate
							break;

							case PERIOD_NAPOLEONIC:
								GiveShip2Character(pchar, "RN_Volage", "Curlew", -1, ENGLAND, true, true); // Heavy Sloop-of-War
							break;
						}
					}
				break;
				case 5: // Commander
					switch (GetMySimpleOldName(PChar))
					{
						case "Horatio Hornblower":
							GiveShip2Character(pchar, "HMS_Greyhound", "Atropos", -1, ENGLAND, true, true); // 6th Rate Frigate
						break;

						case "Horatio Nelson":
							GiveShip2Character(pchar, "HMS_Unicorn", "Albemarle", -1, ENGLAND, true, true); // Lyme class frigate
						break;

						case "Jack Aubrey":
							GiveShip2Character(pchar, "HMS_Surprise", "Surprise", -1, ENGLAND, true, true); // Surprise class Frigate
						break;

						//default:
						switch(GetCurrentPeriod())
						{
							case PERIOD_EARLY_EXPLORERS:
								GiveShip2Character(pchar, "FleutWar", "Pelican", -1, ENGLAND, true, true); // Light Fluyt-of-War
							break;

							case PERIOD_THE_SPANISH_MAIN:
								GiveShip2Character(pchar, "FleutWar", "Roebuck", -1, ENGLAND, true, true); // Light Fluyt-of-War
							break;

							case PERIOD_GOLDEN_AGE_OF_PIRACY:
								GiveShip2Character(pchar, "RN_RaaFrigate", "Edinburgh", -1, ENGLAND, true, true); // Raa class Frigate
							break;

							case PERIOD_COLONIAL_POWERS:
								GiveShip2Character(pchar, "HMS_Unicorn", "Unicorn", -1, ENGLAND, true, true); // Lyme class Frigate
							break;

							case PERIOD_REVOLUTIONS:
								GiveShip2Character(pchar, "RN_Corvette", "Blanche", -1, ENGLAND, true, true); // Aurora class Frigate
							break;

							case PERIOD_NAPOLEONIC:
								GiveShip2Character(pchar, "RN_Surprise", "Success", -1, ENGLAND, true, true); // Unitй class Frigate
							break;
						}
					}
				break;
				case 6: // Post Captain
					switch (GetMySimpleOldName(PChar))
					{
						case "Horatio Hornblower":
							GiveShip2Character(pchar, "RN_Essex", "Lydia", -1, ENGLAND, true, true); // Razйe Frigate
						break;

						case "Horatio Nelson":
							GiveShip2Character(pchar, "RN_Superbe", "Agamemnon", -1, ENGLAND, true, true); // America class 3rd rate
						break;

						case "Jack Aubrey":
							// Nothing on purpose
						break;

						//default:
						switch(GetCurrentPeriod())
						{
							case PERIOD_EARLY_EXPLORERS:
								GiveShip2Character(pchar, "RN_RevengeM", "Swiftsure", -1, ENGLAND, true, true); // English War Galleon, 12lb guns
							break;

							case PERIOD_THE_SPANISH_MAIN:
								GiveShip2Character(pchar, "RN_RevengeW", "Ark Royal", -1, ENGLAND, true, true); // English War Galleon, 12lb guns
							break;

							case PERIOD_GOLDEN_AGE_OF_PIRACY:
								GiveShip2Character(pchar, "HMS_Mordaunt", "Mordaunt", -1, ENGLAND, true, true); // Advanced Warship
							break;

							case PERIOD_COLONIAL_POWERS:
								GiveShip2Character(pchar, "HMS_Surprise", "Amazon", -1, ENGLAND, true, true); // Surprise class Frigate
							break;

							case PERIOD_REVOLUTIONS:
								GiveShip2Character(pchar, "RN_BattleFrigate", "Endymion", -1, ENGLAND, true, true); // Endymion class Frigate
							break;

							case PERIOD_NAPOLEONIC:
								GiveShip2Character(pchar, "RN_BattleFrigate", "Endymion", -1, ENGLAND, true, true); // Endymion class Frigate
							break;
						}
					}
				break;
				case 7: // Commodore
					switch (GetMySimpleOldName(PChar))
					{
						case "Horatio Hornblower":
							GiveShip2Character(PChar, "HMS_Bellona", "Nonsuch", -1, ENGLAND, true, true);	// Was "RN_Superbe", "Sutherland", but he now gets that from a quest
						break;
						case "Theodore Groves":
							GiveShip2Character(PChar, "HMS_Dauntless", "Dauntless", -1, ENGLAND, true, true); // Dauntless
						break;
						case "Andrew Gillette":
							GiveShip2Character(PChar, "HMS_Dauntless", "Dauntless", -1, ENGLAND, true, true); // Dauntless
						break;
						case "James Norrington":
							GiveShip2Character(pchar, "HMS_Dauntless", "Dauntless", -1, ENGLAND, true, true); // Dauntless class 1st Rate
						break;

						case "Horatio Nelson":
							if (GetCompanionIndex(pchar,1) == -1 || GetCompanionIndex(pchar,2) == -1 || GetCompanionIndex(pchar,3) == -1) // GR
							{
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "brtcpt1_18", 3, ENGLAND, false);
								GiveShip2Character(ch, "HMS_Greyhound", "Enterprise", -1, ENGLAND, true, true); // 6th rate frigate
								SetCompanionIndex(pchar, -1, GetCharacterIndex(ch.id));
								RemovePassenger  (pchar,     CharacterFromID  (ch.id));
							}
							else
								LogIt("You seem to have a pretty impressive squadron of your own. Looks like you won't be needing the promotion ship.");
						break;

						case "Jack Aubrey":
							GiveShip2Character(PChar, "HMS_Bellona", "Bellona", -1, ENGLAND, true, true); // Bellona class 3rd Rate
						break;

						//default:
						if (GetCompanionIndex(pchar,1) == -1 || GetCompanionIndex(pchar,2) == -1 || GetCompanionIndex(pchar,3) == -1) // GR
						{
							if(GetCurrentPeriod() < PERIOD_COLONIAL_POWERS)
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Kieron", 3, ENGLAND, false);
							else
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "brtcpt1_18", 3, ENGLAND, false);
							switch(GetCurrentPeriod())
							{
								case PERIOD_EARLY_EXPLORERS:
									GiveShip2Character(ch, "Galeon2", "Dreadnought", -1, ENGLAND, true, true); // Light Manila galleon
								break;

								case PERIOD_THE_SPANISH_MAIN:
									GiveShip2Character(ch, "Galeon2", "Dreadnought", -1, ENGLAND, true, true); // Light Manila galleon
								break;

								case PERIOD_GOLDEN_AGE_OF_PIRACY:
									GiveShip2Character(ch, "RN_RaaFrigate", "Ambuscade", -1, ENGLAND, true, true); // Raa class Frigate
								break;

								case PERIOD_COLONIAL_POWERS:
									GiveShip2Character(ch, "RN_RaaFrigate", "Ambuscade", -1, ENGLAND, true, true); // Raa class Frigate
								break;

								case PERIOD_REVOLUTIONS:
									GiveShip2Character(ch, "RN_Essex", "Shannon", -1, ENGLAND, true, true); // Essex class Frigate
								break;

								case PERIOD_NAPOLEONIC:
									GiveShip2Character(ch, "RN_Essex", "Shannon", -1, ENGLAND, true, true); // Essex class Frigate
								break;
							}
							SetCompanionIndex(pchar, -1, GetCharacterIndex(ch.id));
							RemovePassenger  (pchar,     CharacterFromID  (ch.id));
						}
						else
							LogIt("You seem to have a pretty impressive squadron of your own. Looks like you won't be needing the promotion ship.");
					}
				break;
				case 8: // Rear Admiral
					switch (GetMySimpleOldName(PChar))
					{
						case "Horatio Hornblower":
							if (GetCompanionIndex(pchar,1) == -1 || GetCompanionIndex(pchar,2) == -1 || GetCompanionIndex(pchar,3) == -1) // GR
							{
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "47_Blaze_brtlt", 3, ENGLAND, false);
								ch.lastname = TranslateString("","Vickery");
								GiveShip2Character(ch, "RN_Volage", "Lotus", -1, ENGLAND, true, true); // Sloop of war
								SetCompanionIndex(pchar, -1, GetCharacterIndex(ch.id));
								RemovePassenger  (pchar,     CharacterFromID  (ch.id));
							}
							else
								LogIt("You seem to have a pretty impressive squadron of your own. Looks like you won't be needing the promotion ship.");
						break;
						case "Horatio Nelson":
							// Nothing on purpose
						break;
						case "Theodore Groves":
							// Nothing on purpose
						break;
						case "Andrew Gillette":
							// Nothing on purpose
						break;
						case "James Norrington":
							// Nothing on purpose
						break;

						case "Jack Aubrey":
							if (GetCompanionIndex(pchar,1) == -1 || GetCompanionIndex(pchar,2) == -1 || GetCompanionIndex(pchar,3) == -1) // GR
							{
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "brtcpt2_18", 3, ENGLAND, false);
								GiveShip2Character(ch, "RN_Essex", "Pomone", -1, ENGLAND, true, true); // 
								SetCompanionIndex(pchar, -1, GetCharacterIndex(ch.id));
								RemovePassenger  (pchar,     CharacterFromID  (ch.id));
							}
							else
								LogIt("You seem to have a pretty impressive squadron of your own. Looks like you won't be needing the promotion ship.");
						break;

						//default:
						switch(GetCurrentPeriod())
						{
							case PERIOD_EARLY_EXPLORERS:
								GiveShip2Character(pchar, "RN_RevengeW", "Revenge", -1, ENGLAND, true, true); // English war galleon, 18lb guns
							break;

							case PERIOD_THE_SPANISH_MAIN:
								GiveShip2Character(pchar, "HeavyLineship", "Vanguard", -1, ENGLAND, true, true); // Pinnace-of-War
							break;

							case PERIOD_GOLDEN_AGE_OF_PIRACY:
								GiveShip2Character(pchar, "RN_Poseidon", "Poseidon", -1, ENGLAND, true, true); // Poseidon class 3rd Rate
							break;

							case PERIOD_COLONIAL_POWERS:
								GiveShip2Character(pchar, "HMS_Centurion", "Centurion", -1, ENGLAND, true, true); // Centurion class 4th Rate
							break;

							case PERIOD_REVOLUTIONS:
								GiveShip2Character(pchar, "RN_Superbe", "Agamemnon", -1, ENGLAND, true, true); // America class 3rd Rate
							break;

							case PERIOD_NAPOLEONIC:
								GiveShip2Character(pchar, "HMS_Bellona", "Bellona", -1, ENGLAND, true, true); // Bellona class 3rd Rate
							break;
						}
					}
				break;
				case 9: // Vice Admiral
					switch (GetMySimpleOldName(PChar))
					{
						case "Horatio Hornblower":
							GiveShip2Character(pchar, "RN_SotL", "Prince", -1, ENGLAND, true, true); // 94-gun 2nd rate
						break;

						case "Horatio Nelson":
							GiveShip2Character(pchar, "HMS_Victory", "Victory", -1, ENGLAND, true, true); // Victory class 1st Rate
						break;

						case "Jack Aubrey":
							if (GetCompanionIndex(pchar,1) == -1 || GetCompanionIndex(pchar,2) == -1 || GetCompanionIndex(pchar,3) == -1) // GR
							{
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "brtcpt1_18", 3, ENGLAND, false);
								GiveShip2Character(ch, "RN_Surprise", "Success", -1, ENGLAND, true, true); // Unitй class Frigate
								SetCompanionIndex(pchar, -1, GetCharacterIndex(ch.id));
								RemovePassenger  (pchar,     CharacterFromID  (ch.id));
							}
							else
								LogIt("You seem to have a pretty impressive squadron of your own. Looks like you won't be needing the promotion ship.");
						break;

						case "Theodore Groves":
							// Nothing on purpose
						break;
						case "Andrew Gillette":
							// Nothing on purpose
						break;
						case "James Norrington":
							// Nothing on purpose
						break;

						//default:
						switch(GetCurrentPeriod())
						{
							case PERIOD_EARLY_EXPLORERS:
								if (GetCompanionIndex(pchar,1) == -1 || GetCompanionIndex(pchar,2) == -1 || GetCompanionIndex(pchar,3) == -1) // GR
								{
									ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Offic_eng_15", 3, ENGLAND, false);
									GiveShip2Character(ch, "RN_RevengeF", "Antelope", -1, ENGLAND, true, true); // English War Galleon
									SetCompanionIndex(pchar, -1, GetCharacterIndex(ch.id));
									RemovePassenger  (pchar,     CharacterFromID  (ch.id));
								}
								else
									LogIt("You seem to have a pretty impressive squadron of your own. Looks like you won't be needing the promotion ship.");
							break;

							case PERIOD_THE_SPANISH_MAIN:
								GiveShip2Character(pchar, "Battleship2", "Royal Charles", -1, ENGLAND, true, true); // 3rd Rate Battleship
							break;

							case PERIOD_GOLDEN_AGE_OF_PIRACY:
								GiveShip2Character(pchar, "FR_Trinity", "Resolution", -1, ENGLAND, true, true); // Trinity class 2nd Rate
							break;

							case PERIOD_COLONIAL_POWERS:
								GiveShip2Character(pchar, "RN_Poseidon", "Poseidon", -1, ENGLAND, true, true); // Poseidon class 3rd Rate
							break;

							case PERIOD_REVOLUTIONS:
								GiveShip2Character(pchar, "RN_FirstRate", "Princess Royal", -1, ENGLAND, true, true); // Victory class 1st Rate
							break;

							case PERIOD_NAPOLEONIC:
								GiveShip2Character(pchar, "HMS_Victory", "Victory", -1, ENGLAND, true, true); // Victory class 1st Rate
							break;
						}
					}
				break;
				case 10: // Admiral
					if (GetCompanionIndex(pchar,1) == -1 || GetCompanionIndex(pchar,2) == -1 || GetCompanionIndex(pchar,3) == -1) // GR
					{
						if(GetCurrentPeriod() < PERIOD_COLONIAL_POWERS)
							ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Offic_eng_16", 3, ENGLAND, false);
						else
							ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "brtcpt2_18", 3, ENGLAND, false);
						switch (GetMySimpleOldName(PChar))
						{
							case "Horatio Hornblower":
								GiveShip2Character(ch, "RN_Essex", "Clorinda", -1, ENGLAND, true, true); // Essex class Frigate
							break;

							case "Horatio Nelson":
								ch.name = TranslateString("","Cuthbert");
								ch.lastname = TranslateString("","Collingwood");
								GiveShip2Character(ch, "HMS_Dauntless", "Royal Sovereign", -1, ENGLAND, true, true); // Dauntless class 1st Rate
							break;

							case "Jack Aubrey":
								GiveShip2Character(ch, "RN_Superbe", "Suffolk", -1, ENGLAND, true, true); // America class 3rd Rate
							break;

							case "James Norrington":
								GiveShip2Character(ch, "HMS_Endeavour", "Endeavour", -1, ENGLAND, true, true); // Dauntless class 1st Rate
							break;
							case "Theodore Groves":
								GiveShip2Character(ch, "HMS_Endeavour", "Endeavour", -1, ENGLAND, true, true); // Dauntless class 1st Rate
							break;

							//default:
							switch(GetCurrentPeriod())
							{
								case PERIOD_EARLY_EXPLORERS:
									GiveShip2Character(ch, "RN_RevengeW", "Triumph", -1, ENGLAND, true, true); // English War Galleon
								break;

								case PERIOD_THE_SPANISH_MAIN:
									GiveShip2Character(ch, "RN_RevengeW", "Triumph", -1, ENGLAND, true, true); // English War Galleon
								break;

								case PERIOD_GOLDEN_AGE_OF_PIRACY:
									GiveShip2Character(ch, "FR_Trinity", "Norfolk", -1, ENGLAND, true, true); // Trinity class 2nd Rate
								break;

								case PERIOD_COLONIAL_POWERS:
									GiveShip2Character(ch, "FR_Trinity", "Ramillies", -1, ENGLAND, true, true); // Trinity class 2nd Rate
								break;

								case PERIOD_REVOLUTIONS:
									GiveShip2Character(ch, "RN_SotL", "Barfleur", -1, ENGLAND, true, true); // Barfleur class 2nd Rate
								break;

								case PERIOD_NAPOLEONIC:
									GiveShip2Character(ch, "HMS_Dauntless", "Queen Charlotte", -1, ENGLAND, true, true); // Dauntless class 1st Rate
								break;
							}
						}
						SetCompanionIndex(pchar, -1, GetCharacterIndex(ch.id));
						RemovePassenger  (pchar,     CharacterFromID  (ch.id));
					}
					else
						LogIt("You seem to have a pretty impressive squadron of your own. Looks like you won't be needing the promotion ship.");
				break;
			}
		break;

		case HOLLAND:
			switch(PlayerRank)
			{
				case 1: // Cadet Officier
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "Lugger1", "Witte Valk", -1, HOLLAND, true, true); //
						break;

						case PERIOD_THE_SPANISH_MAIN:
							if (GetMySimpleOldName(PChar) == "Michiel de Ruyter")	GiveShip2Character(pchar, "KetchNavy", "Den Graeuwen Heynst", -1, HOLLAND, true, true); //
							else												GiveShip2Character(pchar, "KetchNavy", "Papeghaij", -1, HOLLAND, true, true); //
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "KetchNavy", "Papeghaij", -1, HOLLAND, true, true); //
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "Cutter1", "Greta Tuin", -1, HOLLAND, true, true); //
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "US_Hannah", "Piet Hein", -1, HOLLAND, true, true); //
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "US_Hannah", "Piet Hein", -1, HOLLAND, true, true); //
						break;
					}
				break;
				case 2: // Adjutant Onderofficier
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "Cutter1", "Edam", -1, HOLLAND, true, true); //
						break;

						case PERIOD_THE_SPANISH_MAIN:
							if (GetMySimpleOldName(PChar) == "Michiel de Ruyter")	GiveShip2Character(pchar, "Cutter1", "Groene Leeuw", -1, HOLLAND, true, true); //
							else												GiveShip2Character(pchar, "Cutter1", "Gouda", -1, HOLLAND, true, true); //
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "Cutter1", "Leerdammer", -1, HOLLAND, true, true); //
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "Schooner1", "Maaslander", -1, HOLLAND, true, true); //
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "Schooner1", "Parrano", -1, HOLLAND, true, true); //
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "Schooner1", "Prima Donna", -1, HOLLAND, true, true); //
						break;
					}
				break;
				case 3: // Derde Luitenant
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "NL_Derfflinger", "Zwarte Beer", -1, HOLLAND, true, true);
						break;

						case PERIOD_THE_SPANISH_MAIN:
							if (GetMySimpleOldName(PChar) == "Michiel de Ruyter")	GiveShip2Character(pchar, "NL_Derfflinger", "Haas", -1, HOLLAND, true, true);
							else												GiveShip2Character(pchar, "NL_Derfflinger", "Zwarte Beer", -1, HOLLAND, true, true);
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "NL_NeptunusE", "Neptunis", -1, HOLLAND, true, true);
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "NL_Neptunus", "Neptunus", -1, HOLLAND, true, true);
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "SchoonerWar", "Meermin", -1, HOLLAND, true, true);
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "SchoonerWar", "Meermin", -1, HOLLAND, true, true);
						break;
					}
				break;
				case 4: // Tweede Luitenant
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "Carrack", "Groote Christoffel", -1, HOLLAND, true, true); //
						break;

						case PERIOD_THE_SPANISH_MAIN:
							if (GetMySimpleOldName(PChar) == "Michiel de Ruyter")	GiveShip2Character(pchar, "NL_NeptunusE", "Neptunus", -1, HOLLAND, true, true);
							else												GiveShip2Character(pchar, "NL_Pinnace", "Prins Maurits", -1, HOLLAND, true, true); //
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "NL_Postillionen", "Postiljon", -1, HOLLAND, true, true); // 6th Rate Frigate
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "NL_Postillionen", "Postiljon", -1, HOLLAND, true, true); // 6th Rate Frigate
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "HMS_Greyhound", "Leeuw", -1, HOLLAND, true, true); // 6th Rate Frigate
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "HMS_Greyhound", "Leeuw", -1, HOLLAND, true, true); // 6th Rate Frigate
						break;
					}
				break;
				case 5: // Eerste Luitenant
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "NL_Fleut50", "Gouden Leeuwin", -1, HOLLAND, true, true); // 
						break;

						case PERIOD_THE_SPANISH_MAIN:
							if (GetMySimpleOldName(PChar) == "Michiel de Ruyter")	GiveShip2Character(pchar, "NL_Fleut50", "Witte Lam", -1, HOLLAND, true, true);
							else												GiveShip2Character(pchar, "NL_Fleut50", "Gouden Leeuwin", -1, HOLLAND, true, true); //
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "NL_Batavia", "Maarsen", -1, HOLLAND, true, true); // 
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "NL_Frigate47", "Eensgezindheid", -1, HOLLAND, true, true); // 
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "Corvette2", "Wilhelmina", -1, HOLLAND, true, true); // 
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "Corvette2", "Embuscade", -1, HOLLAND, true, true); // 
						break;
					}
				break;
				case 6: // Kapitein-Luitenant
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "FastGalleon1", "Utrecht", -1, HOLLAND, true, true); // Fast Galleon
						break;

						case PERIOD_THE_SPANISH_MAIN:
							if (GetMySimpleOldName(PChar) == "Michiel de Ruyter")	GiveShip2Character(pchar, "NL_FleutWar", "Huis te Kruiningen", -1, HOLLAND, true, true);
							else												GiveShip2Character(pchar, "FastGalleon1", "Utrecht", -1, HOLLAND, true, true); // Fast Galleon
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "NL_FleutWar", "Huis van Nassau", -1, HOLLAND, true, true); // 4th rate Battle Frigate
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "NL_Amsterdam", "Oranje", -1, HOLLAND, true, true); // Spiegelretourschip
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "NL_Amsterdam", "Wapen van Rotterdam", -1, HOLLAND, true, true); // Spiegelretourschip
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "NL_Essex", "Ijssel", -1, HOLLAND, true, true); // Essex class Frigate
						break;
					}
				break;
				case 7: // Kapitein ter Zee
					if (GetCompanionIndex(pchar,1) == -1 || GetCompanionIndex(pchar,2) == -1 || GetCompanionIndex(pchar,3) == -1) // GR
					{
						if(GetCurrentPeriod() < PERIOD_COLONIAL_POWERS)
							ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Man6_1", 3, HOLLAND, false);
						else
							ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "9JdHol", 3, HOLLAND, false);
						switch(GetCurrentPeriod())
						{
							case PERIOD_EARLY_EXPLORERS:
								GiveShip2Character(ch, "NL_FleutWar", "Valk", -1, HOLLAND, true, true); // Fleut of War
							break;
								case PERIOD_THE_SPANISH_MAIN:
								if (GetMySimpleOldName(PChar) == "Michiel de Ruyter")	GiveShip2Character(ch, "NL_FleutWar", "Huijs te Zwieten", -1, HOLLAND, true, true);
								else												GiveShip2Character(ch, "NL_FleutWar", "Eendracht", -1, HOLLAND, true, true); // Fleut of War
							break;
								case PERIOD_GOLDEN_AGE_OF_PIRACY:
								GiveShip2Character(ch, "NL_WarGalleon", "Kampen", -1, HOLLAND, true, true); // Indiaman
							break;
								case PERIOD_COLONIAL_POWERS:
								GiveShip2Character(ch, "NL_Frigate47", "Schoonoord", -1, HOLLAND, true, true); // Rossiya Frigate
							break;
								case PERIOD_REVOLUTIONS:
								GiveShip2Character(ch, "SuperFrigate", "Argo", -1, HOLLAND, true, true); // Iceni Queen
							break;
								case PERIOD_NAPOLEONIC:
								GiveShip2Character(ch, "NL_Essex", "Jason", -1, HOLLAND, true, true); // Essex class Frigate
							break;
						}
						SetCompanionIndex(pchar, -1, GetCharacterIndex(ch.id));
						RemovePassenger  (pchar,     CharacterFromID  (ch.id));
					}
					else
						LogIt("You seem to have a pretty impressive squadron of your own. Looks like you won't be needing the promotion ship.");
				break;
				case 8: // Commandeur
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "Galeon1", "Engel", -1, HOLLAND, true, true); // Royal Manila Galleon
						break;

						case PERIOD_THE_SPANISH_MAIN:
							if (GetMySimpleOldName(PChar) == "Michiel de Ruyter")	GiveShip2Character(pchar, "NL_ConvoiShip", "Spiegel", -1, HOLLAND, true, true);
							else												GiveShip2Character(pchar, "NL_SevenProvincien", "Aemilia", -1, HOLLAND, true, true); // 3rd Rate Battleship
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "NL_FWzP", "Graaf van Albemarle", -1, HOLLAND, true, true); // Brandenburg Frigate
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "NL_FWzP", "Prins Willem", -1, HOLLAND, true, true); // Brandenburg Frigate
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "Lineship47", "Haarlem", -1, HOLLAND, true, true); //
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "NL_Superbe", "Vrijheid", -1, HOLLAND, true, true); //
						break;
					}
				break;
				case 9: // Schout-bij-Nacht
					if (GetCompanionIndex(pchar,1) == -1 || GetCompanionIndex(pchar,2) == -1 || GetCompanionIndex(pchar,3) == -1) // GR
					{
						switch(GetCurrentPeriod())
						{
							case PERIOD_EARLY_EXPLORERS:
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Offic_hol_15", 3, HOLLAND, false);
								GiveShip2Character(ch, "FastGalleon2", "Zeewolf", -1, HOLLAND, true, true); // War Galleon
							break;

							case PERIOD_THE_SPANISH_MAIN:
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Offic_hol_16", 3, HOLLAND, false);
								if (GetMySimpleOldName(PChar) == "Michiel de Ruyter")	GiveShip2Character(ch, "HeavyLineship", "Hollandia", -1, HOLLAND, true, true);
								else												GiveShip2Character(ch, "NL_ConvoiShip", "Zeelandia", -1, HOLLAND, true, true); // Wappen von Hamburg
							break;

							case PERIOD_GOLDEN_AGE_OF_PIRACY:
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Offic_hol_17", 3, HOLLAND, false);
								GiveShip2Character(ch, "NL_Lineship", "Veere", -1, HOLLAND, true, true); // 
							break;

							case PERIOD_COLONIAL_POWERS:
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Offic_hol_18", 3, HOLLAND, false);
								GiveShip2Character(ch, "NL_PinnaceofWar47", "Prinses Royaal", -1, HOLLAND, true, true); // 
							break;

							case PERIOD_REVOLUTIONS:
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Offic_hol_18", 3, HOLLAND, false);
								GiveShip2Character(ch, "RN_SuperiorWarship", "Vrijheid", -1, HOLLAND, true, true); //
							break;

							case PERIOD_NAPOLEONIC:
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Offic_hol_18", 3, HOLLAND, false);
								GiveShip2Character(ch, "SuperFrigate", "Juno", -1, HOLLAND, true, true); // Iceni Queen
							break;
						}
						SetCompanionIndex(pchar, -1, GetCharacterIndex(ch.id));
						RemovePassenger  (pchar,     CharacterFromID  (ch.id));
					}
					else
						LogIt("You seem to have a pretty impressive squadron of your own. Looks like you won't be needing the promotion ship.");
				break;
				case 10: // Vice-Admiraal
					if (GetCompanionIndex(pchar,1) == -1 || GetCompanionIndex(pchar,2) == -1 || GetCompanionIndex(pchar,3) == -1) // GR
					{
						if(GetCurrentPeriod() < PERIOD_COLONIAL_POWERS)
							ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Man6_1", 3, HOLLAND, false);
						else
							ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "9JdHol", 3, HOLLAND, false);

						switch(GetCurrentPeriod())
						{
							case PERIOD_EARLY_EXPLORERS:
								GiveShip2Character(ch, "FastGalleon2", "Vergulde Raven", -1, HOLLAND, true, true); // War Galleon
							break;

							case PERIOD_THE_SPANISH_MAIN:
								if (GetMySimpleOldName(PChar) == "Michiel de Ruyter")	GiveShip2Character(ch, "NL_SevenProvincien", "Zeven Provincien", -1, HOLLAND, true, true);
								else												GiveShip2Character(ch, "NL_Lineship", "	Huis te Oosterwijk", -1, HOLLAND, true, true); // 
							break;

							case PERIOD_GOLDEN_AGE_OF_PIRACY:
								GiveShip2Character(ch, "NL_ConvoiShip", "Raadhuis van Edam", -1, HOLLAND, true, true); // 
							break;

							case PERIOD_COLONIAL_POWERS:
								GiveShip2Character(ch, "NL_FWzP", "Prinses Royaal", -1, HOLLAND, true, true); // Brandenburg Frigate
							break;

							case PERIOD_REVOLUTIONS:
								GiveShip2Character(ch, "SuperFrigate", "Jager", -1, HOLLAND, true, true); // Iceni Queen
							break;

							case PERIOD_NAPOLEONIC:
								GiveShip2Character(ch, "NL_Superbe", "Admiraal Zoutman", -1, HOLLAND, true, true); // Bellona class
							break;
						}
						SetCompanionIndex(pchar, -1, GetCharacterIndex(ch.id));
						RemovePassenger  (pchar,     CharacterFromID  (ch.id));
					}
					else
						LogIt("You seem to have a pretty impressive squadron of your own. Looks like you won't be needing the promotion ship.");
				break;
			}
		break;

		case FRANCE:
			switch(PlayerRank)
			{
				case 1: // Enseigne
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "Lugger1", "Loire", -1, FRANCE, true, true); // Lugger
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "Lugger1", "Loire", -1, FRANCE, true, true); // Lugger
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "FR_Hoy", "Foudre", -1, FRANCE, true, true); // Hoy
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "FR_Hoy", "Foudre", -1, FRANCE, true, true); // Hoy
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "FR_Hoy", "Foudre", -1, FRANCE, true, true); // Hoy
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "FR_Hoy", "Foudre", -1, FRANCE, true, true); // Hoy
						break;
					}
				break;
				case 2: // Sous-Lieutenant de Vaisseau
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "Cutter1", "Mutin", -1, FRANCE, true, true); // Naval Cutter
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "Cutter1", "Mutin", -1, FRANCE, true, true); // Naval Cutter
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "KetchNavy", "Joyeaux", -1, FRANCE, true, true); // Naval Ketch
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "FR_Sloop", "Cassiopee", -1, FRANCE, true, true); // Sloop
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "FR_Sloop", "Cassiopee", -1, FRANCE, true, true); // Sloop
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "FR_Sloop", "Cassiopee", -1, FRANCE, true, true); // Fast Brig
						break;
					}
				break;
				case 3: // Lieutenant de Vaisseau
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "Polacca", "Lйopard", -1, FRANCE, true, true);
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "Polacca", "Lйopard", -1, FRANCE, true, true);
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "BrigRoyal", "Magicienne", -1, FRANCE, true, true);
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "BrigRoyal", "Magicienne", -1, FRANCE, true, true);
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "Brig2", "Йlan", -1, FRANCE, true, true);
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "Brig2", "Йlan", -1, FRANCE, true, true);
						break;
					}
				break;
				case 4: // Capitaine de Corvette
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "FR_Derfflinger", "Le Cochon Noir", -1, FRANCE, true, true); // Fluyt
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "FR_NeptunusE", "Duc de la Guerre", -1, FRANCE, true, true); // Sloop-of-War
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "FR_Postillionen", "Mйduse", -1, FRANCE, true, true); // 6th Rate Frigate
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "SchoonerXebec", "Indiscret", -1, FRANCE, true, true); // Grand Schooner
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "FR_Postillionen", "Mйduse", -1, FRANCE, true, true); // 6th Rate Frigate
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "FR_Greyhound", "Comte de Trйville", -1, FRANCE, true, true); // Heavy Sloop-of-War
						break;
					}
				break;
				case 5: // Capitaine de Fregate
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "Carrack", "Bon Aventure", -1, FRANCE, true, true); // Advanced Warship
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "Carrack", "Bon Aventure", -1, FRANCE, true, true); // Advanced Warship
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "RN_RaaFrigate", "Йtoile", -1, FRANCE, true, true); // Frigate
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "Corvette1", "Iphigйnie", -1, FRANCE, true, true); // Aurora class Frigate
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "Corvette1", "Iphigйnie", -1, FRANCE, true, true); // Aurora class Frigate
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "FR_Surprise", "DuQuesne", -1, FRANCE, true, true); // Unitй class Frigate
						break;
					}
				break;
				case 6: // Capitaine de Vaisseau
					switch (GetMySimpleOldName(PChar))
					{
						case "Franзois-Louis Rousselet":
							GiveShip2Character(PChar, "WallerPinnace", "Le Saint Louis", -1, FRANCE, true, true); // Heavy Pinnace of War
						break;

						//default:
						switch(GetCurrentPeriod())
						{
							case PERIOD_EARLY_EXPLORERS:
								GiveShip2Character(pchar, "FastGalleon2", "Asterix", -1, FRANCE, true, true); // Fast Galleon
							break;

							case PERIOD_THE_SPANISH_MAIN:
								GiveShip2Character(pchar, "FastGalleon2", "Asterix", -1, FRANCE, true, true); // Fast Galleon
							break;

							case PERIOD_GOLDEN_AGE_OF_PIRACY:
								GiveShip2Character(pchar, "FR_Frigate", "Mйduse", -1, FRANCE, true, true); // Rossiya Frigate
							break;

							case PERIOD_COLONIAL_POWERS:
								GiveShip2Character(pchar, "FR_Boussole", "Richelieu", -1, FRANCE, true, true); // Advanced Frigate
							break;

							case PERIOD_REVOLUTIONS:
								GiveShip2Character(pchar, "FR_BattleFrigate", "Achйron", -1, FRANCE, true, true); // Artйmise class Frigate
							break;

							case PERIOD_NAPOLEONIC:
								GiveShip2Character(pchar, "FR_BattleFrigate", "Achйron", -1, FRANCE, true, true); // Artйmise class Frigate
							break;
						}
					}
				break;
				case 7: // Contre-Amiral
					if (GetCompanionIndex(pchar,1) == -1 || GetCompanionIndex(pchar,2) == -1 || GetCompanionIndex(pchar,3) == -1) // GR
					{
						if(GetCurrentPeriod() < PERIOD_COLONIAL_POWERS)
							ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Kieron", 3, FRANCE, false);
						else
							ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "fra_cpt_18", 3, FRANCE, false);
						switch(GetCurrentPeriod())
						{
							case PERIOD_EARLY_EXPLORERS:
								GiveShip2Character(ch, "Galeon2", "Espadon", -1, FRANCE, true, true); // War Galleon
							break;
								case PERIOD_THE_SPANISH_MAIN:
								GiveShip2Character(ch, "Galeon2", "Espadon", -1, FRANCE, true, true); // War Galleon
							break;
								case PERIOD_GOLDEN_AGE_OF_PIRACY:
								GiveShip2Character(ch, "FR_Licorne", "La Licorne", -1, FRANCE, true, true); // Indiaman
							break;
								case PERIOD_COLONIAL_POWERS:
								GiveShip2Character(ch, "FR_Boussole", "Jeanne d'Arc", -1, FRANCE, true, true); // Advanced Frigate
							break;
								case PERIOD_REVOLUTIONS:
								GiveShip2Character(ch, "FR_Boussole", "Jeanne d'Arc", -1, FRANCE, true, true); // Advanced Frigate
							break;
								case PERIOD_NAPOLEONIC:
								GiveShip2Character(ch, "FR_Essex", "Railleuse", -1, FRANCE, true, true); // Essex class Frigate
							break;
						}
						SetCompanionIndex(pchar, -1, GetCharacterIndex(ch.id));
						RemovePassenger  (pchar,     CharacterFromID  (ch.id));
					}
					else
						LogIt("You seem to have a pretty impressive squadron of your own. Looks like you won't be needing the promotion ship.");
				break;
				case 8: // Vice-Amiral
					switch (GetMySimpleOldName(PChar))
					{
						case "Franзois-Louis Rousselet":
							GiveShip2Character(PChar, "FR_SoleilRoyal", "Dauphin Royal", -1, FRANCE, true, true); // Heavy Pinnace of War
						break;

						//default:
						switch(GetCurrentPeriod())
						{
							case PERIOD_EARLY_EXPLORERS:
								GiveShip2Character(pchar, "Galeon1", "Forte", -1, FRANCE, true, true); // Royal Manila Galleon
							break;
							case PERIOD_THE_SPANISH_MAIN:
								GiveShip2Character(pchar, "HeavyLineship", "Maillй Brйzй", -1, FRANCE, true, true); // Pinnace-of-War
							break;
							case PERIOD_GOLDEN_AGE_OF_PIRACY:
								GiveShip2Character(pchar, "FR_Fleuron", "Le Fleuron", -1, FRANCE, true, true); // Fleuron class 3rd Rate
							break;
							case PERIOD_COLONIAL_POWERS:
								GiveShip2Character(pchar, "FR_Fleuron", "Le Fleuron", -1, FRANCE, true, true); // Fleuron class 3rd Rate
							break;
							case PERIOD_REVOLUTIONS:
								GiveShip2Character(pchar, "FR_Superbe", "Redoutable", -1, FRANCE, true, true); // America class 3rd Rate
							break;
							case PERIOD_NAPOLEONIC:
								GiveShip2Character(pchar, "FR_Bellona", "Tйmйraire", -1, FRANCE, true, true); // Bellona class 3rd Rate
							break;
						}
					}
				break;
				case 9: // Vice-Amiral d'Escadre
					switch (GetMySimpleOldName(PChar))
					{
						case "Franзois-Louis Rousselet":
							// Nothing on purpose
						break;

						//default:
						switch(GetCurrentPeriod())
						{
							case PERIOD_EARLY_EXPLORERS:
								GiveShip2Character(pchar, "Galeon50", "Brennus", -1, FRANCE, true, true); // War Galleon
							break;

							case PERIOD_THE_SPANISH_MAIN:
								GiveShip2Character(pchar, "Battleship2", "Challenger", -1, FRANCE, true, true); // 3rd Rate Battleship
							break;

							case PERIOD_GOLDEN_AGE_OF_PIRACY:
								GiveShip2Character(pchar, "FR_Belette", "Le Terrible", -1, FRANCE, true, true); // Superior Warship
							break;

							case PERIOD_COLONIAL_POWERS:
								GiveShip2Character(pchar, "FR_Trinity", "Triomphant", -1, FRANCE, true, true); // Trinity class 2nd Rate
							break;

							case PERIOD_REVOLUTIONS:
								GiveShip2Character(pchar, "FR_FirstRate", "Bucentaure", -1, FRANCE, true, true); // Victory class 1st Rate
							break;

							case PERIOD_NAPOLEONIC:
								GiveShip2Character(pchar, "FR_FirstRate", "Bucentaure", -1, FRANCE, true, true); // Victory class 1st Rate
							break;
						}
					}
				break;
				case 10: // Amiral
					if (GetCompanionIndex(pchar,1) == -1 || GetCompanionIndex(pchar,2) == -1 || GetCompanionIndex(pchar,3) == -1) // GR
					{
						if(GetCurrentPeriod() < PERIOD_COLONIAL_POWERS)
							ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Huber_Fra4_17", 3, FRANCE, false);
						else
							ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "fra_cpt2_18", 3, FRANCE, false);
						switch(GetCurrentPeriod())
						{
							case PERIOD_EARLY_EXPLORERS:
								GiveShip2Character(ch, "FastGalleon2", "Serpente", -1, FRANCE, true, true); // War Galleon
							break;

							case PERIOD_THE_SPANISH_MAIN:
								GiveShip2Character(ch, "FR_Couronne", "La Couronne", -1, FRANCE, true, true); // French War Galleon
							break;

							case PERIOD_GOLDEN_AGE_OF_PIRACY:
								GiveShip2Character(ch, "FR_SoleilRoyal", "Soleil Royal", -1, FRANCE, true, true); // Man of war
							break;

							case PERIOD_COLONIAL_POWERS:
								GiveShip2Character(ch, "FR_Trinity", "Foudroyant", -1, FRANCE, true, true); // Trinity class 2nd Rate
							break;

							case PERIOD_REVOLUTIONS:
								GiveShip2Character(ch, "FR_SotL", "Fougueux", -1, FRANCE, true, true); // Intrйpide class 1st Rate
							break;

							case PERIOD_NAPOLEONIC:
								GiveShip2Character(ch, "FR_SotL", "Fougueux", -1, FRANCE, true, true); // Intrйpide class 1st Rate
							break;
						}
						SetCompanionIndex(pchar, -1, GetCharacterIndex(ch.id));
						RemovePassenger  (pchar,     CharacterFromID  (ch.id));
					}
					else
						LogIt("You seem to have a pretty impressive squadron of your own. Looks like you won't be needing the promotion ship.");
				break;
			}
		break;

		case SPAIN:
			switch(PlayerRank)
			{
				case 1: // Aspirante
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "Lugger3", "San Miguel", -1, SPAIN, true, true); // Lugger
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "Lugger3", "San Andreas", -1, SPAIN, true, true); // Lugger
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "SP_Hoy", "Santa Helena", -1, SPAIN, true, true); // Hoy
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "SP_Hoy", "Santa Lucia", -1, SPAIN, true, true); // Hoy
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "SP_Hoy", "Santa Barbara", -1, SPAIN, true, true); // Hoy
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "Lugger3", "Santa Teresa", -1, SPAIN, true, true); // Hoy
						break;
					}
				break;
				case 2: // Alfйrez de Fragate
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "Cutter1", "Espaciosa", -1, SPAIN, true, true); // Naval Cutter
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "Cutter1", "Espaciosa", -1, SPAIN, true, true); // Naval Cutter
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "KetchNavy", "Ventura", -1, SPAIN, true, true); // Naval Ketch
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "KetchNavy", "Ventura", -1, SPAIN, true, true); // Sloop
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "sloop1", "Dafne", -1, SPAIN, true, true); // Sloop
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "sloop1", "Casanova", -1, SPAIN, true, true); // Sloop
						break;
					}
				break;

				case 3: // Alfйrez de Navнo
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "Polacca_N", "Su Madre", -1, SPAIN, true, true);
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "Galeoth1", "Toro", -1, SPAIN, true, true);
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "Galeoth1", "Santa Lauren", -1, SPAIN, true, true);
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "Galeoth1", "Don Quixote", -1, SPAIN, true, true);
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "Galeoth1", "San Jeronimo", -1, SPAIN, true, true);
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "Galeoth1", "Extremeсa", -1, SPAIN, true, true);
						break;
					}
				break;

				case 4: // Teniente de Navнo
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "SP_Derfflinger", "Girona", -1, SPAIN, true, true); // 
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "SP_NeptunusE", "Lion de Oro", -1, SPAIN, true, true); // 
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "SP_Neptunus", "San Cayetano", -1, SPAIN, true, true); // 
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "SP_Postillionen", "Estrella", -1, SPAIN, true, true); // 6th Rate Frigate
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "SP_Postillionen", "Esmeralda", -1, SPAIN, true, true); // 6th Rate Frigate
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "SP_Volage", "San Isidro", -1, SPAIN, true, true); // Heavy Sloop-of-War
						break;
					}
				break;

				case 5: // Capitбn de Corbeta
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "SP_ApostolFelipe", "Apostуl Felipe", -1, SPAIN, true, true); // 
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "SP_ApostolFelipe", "Apostуl Felipe", -1, SPAIN, true, true); // 
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "SP_ApostolFelipe", "Apostуl Felipe", -1, SPAIN, true, true); // 
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "Corvette1", "Santa Catalina", -1, SPAIN, true, true); // Aurora class Frigate
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "Corvette1", "Santa Catalina", -1, SPAIN, true, true); // Aurora class Frigate
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "SP_Surprise", "Cornelia", -1, SPAIN, true, true); // Unitй class Frigate
						break;
					}
				break;

				case 6: // Capitбn de Fragata
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "FastGalleon2", "San Esteban", -1, SPAIN, true, true); // Fast Galleon
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "FastGalleon2", "Madonna del Populo", -1, SPAIN, true, true); // Fast Galleon
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "Frigate2", "San Fernando", -1, SPAIN, true, true); // Rossiya Frigate
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "Frigate2", "Hermione", -1, SPAIN, true, true); // Rossiya Frigate
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "SuperFrigate", "Santa Margarita", -1, SPAIN, true, true); // Iceni Queen
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "SP_Essex", "Mercurio", -1, SPAIN, true, true); // Essex class Frigate
						break;
					}
				break;

				case 7: // Capitбn de Navнo
					if (GetCompanionIndex(pchar,1) == -1 || GetCompanionIndex(pchar,2) == -1 || GetCompanionIndex(pchar,3) == -1) // GR
					{
						if(GetCurrentPeriod() < PERIOD_COLONIAL_POWERS)
							ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Huber_spa", 3, SPAIN, false);
						else
							ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "spa_cpt_18", 3, SPAIN, false);
						switch(GetCurrentPeriod())
						{
							case PERIOD_EARLY_EXPLORERS:
								GiveShip2Character(ch, "SP_Galeon50", "Santa Rosa", -1, SPAIN, true, true); // Royal Galleon
							break;

							case PERIOD_THE_SPANISH_MAIN:
								GiveShip2Character(ch, "SP_Galeon50", "	Nuestra Seсora del Pueblo", -1, SPAIN, true, true); // Royal Galleon
							break;

							case PERIOD_GOLDEN_AGE_OF_PIRACY:
								GiveShip2Character(ch, "SP_WarGalleon", "San Lorenzo", -1, SPAIN, true, true); // Indiaman
							break;

							case PERIOD_COLONIAL_POWERS:
								GiveShip2Character(ch, "Frigate2", "Aquila", -1, SPAIN, true, true); // Rossiya Frigate
							break;

							case PERIOD_REVOLUTIONS:
								GiveShip2Character(ch, "SP_Surprise", "Santa Marta", -1, SPAIN, true, true); // Unitй class Frigate
							break;

							case PERIOD_NAPOLEONIC:
								GiveShip2Character(ch, "SP_Warship", "Natividad", -1, SPAIN, true, true); // Warship
							break;
						}
						SetCompanionIndex(pchar, -1, GetCharacterIndex(ch.id));
						RemovePassenger  (pchar,     CharacterFromID  (ch.id));
					}
					else
						LogIt("You seem to have a pretty impressive squadron of your own. Looks like you won't be needing the promotion ship.");
				break;

				case 8: // Contra Almirante
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "Galeon50", "San Juan", -1, SPAIN, true, true); // War Galleon
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "Galeon50", "Don Juan", -1, SPAIN, true, true); // War Galleon
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "FR_Fleuron", "Gran Princesa de los Cielos", -1, SPAIN, true, true); // Fleuron class 3rd Rate
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "FR_Fleuron", "San Francisco", -1, SPAIN, true, true); // Fleuron class 3rd Rate
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "FR_Superbe", "San Agustнn", -1, SPAIN, true, true); // America class 3rd Rate
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "FR_Superbe", "San Agustнn", -1, SPAIN, true, true); // America class 3rd Rate
						break;
					}
				break;

				case 9: // Vice Almirante
					switch (GetMySimpleOldName(PChar))
					{
						case "Blas de Lezo":
							GiveShip2Character(pchar, "PO_Poseidon", "Conquistador", -1, SPAIN, true, true); // Poseidon class 3rd Rate
						break;

						//default:
						switch(GetCurrentPeriod())
						{
							case PERIOD_EARLY_EXPLORERS:
								GiveShip2Character(pchar, "SP_BattleGalleon", "San Martin", -1, SPAIN, true, true); // San Martin
							break;

							case PERIOD_THE_SPANISH_MAIN:
								GiveShip2Character(pchar, "SP_SanFelipe", "San Felipe", -1, SPAIN, true, true); // Man of war
							break;

							case PERIOD_GOLDEN_AGE_OF_PIRACY:
								GiveShip2Character(pchar, "SP_SanFelipe", "San Felipe", -1, SPAIN, true, true); // Man of war
							break;

							case PERIOD_COLONIAL_POWERS:
								GiveShip2Character(pchar, "SP_Trinity", "Nuevo Invencible", -1, SPAIN, true, true); // Trinity class 2nd Rate
							break;

							case PERIOD_REVOLUTIONS:
								GiveShip2Character(pchar, "SP_SotL", "Santнsima Trinidad", -1, SPAIN, true, true); // Victory class 1st Rate
							break;

							case PERIOD_NAPOLEONIC:
								GiveShip2Character(pchar, "SP_SotL", "Santнsima Trinidad", -1, SPAIN, true, true); // Victory class 1st Rate
							break;
						}
					}
				break;

				case 10: // Almirante
					if (GetCompanionIndex(pchar,1) == -1 || GetCompanionIndex(pchar,2) == -1 || GetCompanionIndex(pchar,3) == -1) // GR
					{
						if(GetCurrentPeriod() < PERIOD_COLONIAL_POWERS)
							ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Huber_Spa4_17", 3, SPAIN, false);
						else
							ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "spa_cpt1_18", 3, SPAIN, false);
						switch (GetMySimpleOldName(PChar))
						{
							case "Blas de Lezo":
								ch.name = TranslateString("","Francisco");
								ch.middlename = TranslateString("","Josй");
								ch.lastname = TranslateString("","de Ovando");
								GiveShip2Character(ch, "PO_Poseidon", "Dragуn", -1, SPAIN, true, true);
							break;

							//default:
							switch(GetCurrentPeriod())
							{
								case PERIOD_EARLY_EXPLORERS:
									GiveShip2Character(ch, "FastGalleon2", "San Marcos", -1, SPAIN, true, true); // War Galleon
								break;

								case PERIOD_THE_SPANISH_MAIN:
									GiveShip2Character(ch, "Galeon50", "Nuestra Seсora de las Mercedes", -1, SPAIN, true, true); // War Galleon
								break;

								case PERIOD_GOLDEN_AGE_OF_PIRACY:
									GiveShip2Character(ch, "SP_Battleship", "Principe de Asturias", -1, SPAIN, true, true); // Battleship
								break;

								case PERIOD_COLONIAL_POWERS:
									GiveShip2Character(ch, "SP_Trinity", "Principe", -1, SPAIN, true, true); // Trinity class 2nd Rate
								break;

								case PERIOD_REVOLUTIONS:
									GiveShip2Character(ch, "FR_FirstRate", "San Carlos", -1, SPAIN, true, true); // Intrйpide class 1st Rate
								break;

								case PERIOD_NAPOLEONIC:
									GiveShip2Character(ch, "FR_FirstRate", "San Carlos", -1, SPAIN, true, true); // Intrйpide class 1st Rate
								break;
							}
						}
						SetCompanionIndex(pchar, -1, GetCharacterIndex(ch.id));
						RemovePassenger  (pchar,     CharacterFromID  (ch.id));
					}
					else
						LogIt("You seem to have a pretty impressive squadron of your own. Looks like you won't be needing the promotion ship.");
				break;
			}
		break;

		case PORTUGAL:
			switch(PlayerRank)
			{
				case 1: // Aspirante
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "LuggerCT", "Nossa Senhora da Oliveira e Santo Antуnio", -1, PORTUGAL, true, true); // Lugger
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "LuggerCT", "Sao Muche", -1, PORTUGAL, true, true); // Lugger
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "PO_Hoy", "Sao Bartolomeu", -1, PORTUGAL, true, true); // Hoy
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "PO_Hoy", "Sao Feng", -1, PORTUGAL, true, true); // Hoy
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "PO_Hoy", "Sao Watte", -1, PORTUGAL, true, true); // Hoy
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "LuggerCT", "Sao Dere", -1, PORTUGAL, true, true); // Hoy
						break;
					}
				break;
				case 2: // Subtenente
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "Cutter1", "Coroa", -1, PORTUGAL, true, true); // Naval Cutter
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "Cutter1", "Coroa", -1, PORTUGAL, true, true); // Naval Cutter
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "KetchNavy", "Sao Francisco Xavier", -1, PORTUGAL, true, true); // Naval Ketch
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "KetchNavy", "Sao Francisco Xavier", -1, PORTUGAL, true, true); // Sloop
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "sloop1", "Nossa Senhora da Boa Viagem", -1, PORTUGAL, true, true); // Sloop
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "sloop1", "Nossa Senhora da Boa Viagem", -1, PORTUGAL, true, true); // Sloop
						break;
					}
				break;

				case 3: // Segundo-Tenente
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "Polacca_N", "Lebre", -1, PORTUGAL, true, true);
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "Galeoth2", "Volador", -1, PORTUGAL, true, true);
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "Galeoth2", "Volador", -1, PORTUGAL, true, true);
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "Galeoth2", "Serpento do Mar", -1, PORTUGAL, true, true);
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "Galeoth2", "Serpento do Mar", -1, PORTUGAL, true, true);
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "Galeoth2", "Giavota", -1, PORTUGAL, true, true);
						break;
					}
				break;

				case 4: // Primeiro-Tenente
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "Caravel1", "Sao Pedro", -1, PORTUGAL, true, true); // Caravela latina
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "PO_NeptunusE", "Sao Pedro", -1, PORTUGAL, true, true); // Sloop of war
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "PO_Neptunus", "Sao Jose", -1, PORTUGAL, true, true); // Sloop of war
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "PO_Postillionen", "Aguia", -1, PORTUGAL, true, true); // 6th Rate Frigate
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "PO_Greyhound", "Sao Joao Magnвnimo", -1, PORTUGAL, true, true); // 6th Rate Frigate
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "PO_Greyhound", "Sao Joao Magnвnimo", -1, PORTUGAL, true, true); // 6th Rate Frigate
						break;
					}
				break;

				case 5: // Capitгo-Tenente
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "FastGalleon1", "Santa Ana e Maria", -1, PORTUGAL, true, true); // Fast Galleon
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "FastGalleon1", "Santa Ana e Maria", -1, PORTUGAL, true, true); // Fast Galleon
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "PO_FastNavy", "Nossa Senhora da Nazare", -1, PORTUGAL, true, true); // Fragata Latina
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "PO_FastNavy", "Nossa Senhora da Nazare", -1, PORTUGAL, true, true); // Fragata Latina
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "Corvette2", "Principe do Brasil", -1, PORTUGAL, true, true); // Aurora class Frigate
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "RN_Surprise", "Principe Dom Pedro", -1, PORTUGAL, true, true); // Unitй class Frigate
						break;
					}
				break;

				case 6: // Capitгo-de-Fragata
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "Galeon2", "Santissimo Sacramento da Trindade", -1, PORTUGAL, true, true); // Light Manila Galleon
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "Galeon2", "Nossa Senhora da Ajuda", -1, PORTUGAL, true, true); // Light Manila Galleon
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "Frigate2", "Santa Ana e Santo Joaquim", -1, PORTUGAL, true, true); // Rossiya Frigate
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "Frigate2", "Golfinho", -1, PORTUGAL, true, true); // Rossiya Frigate
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "SuperFrigate", "Nossa Senhora das Necessidades", -1, PORTUGAL, true, true); // Iceni Queen
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "NL_Essex", "Princesa Carlota", -1, PORTUGAL, true, true); // Essex class Frigate
						break;
					}
				break;

				case 7: // Capitгo-de-Mar-e-Guerra
					if (GetCompanionIndex(pchar,1) == -1 || GetCompanionIndex(pchar,2) == -1 || GetCompanionIndex(pchar,3) == -1) // GR
					{
						switch(GetCurrentPeriod())
						{
							case PERIOD_EARLY_EXPLORERS:
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Offic_por_15", 3, PORTUGAL, false);
								GiveShip2Character(ch, "SP_Galeon50", "Nossa Senhora do Loreto", -1, PORTUGAL, true, true); // Royal Galleon
							break;

							case PERIOD_THE_SPANISH_MAIN:
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Offic_por_16", 3, PORTUGAL, false);
								GiveShip2Character(ch, "SP_Galeon50", "Nossa Senhora do Cardais", -1, PORTUGAL, true, true); // Royal Galleon
							break;

							case PERIOD_GOLDEN_AGE_OF_PIRACY:
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Offic_por_172", 3, PORTUGAL, false);
								GiveShip2Character(ch, "PO_WarGalleon", "Sao Boaventura", -1, PORTUGAL, true, true); // Indiaman
							break;

							case PERIOD_COLONIAL_POWERS:
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Offic_por_17", 3, PORTUGAL, false);
								GiveShip2Character(ch, "Frigate2", "Santo Miguel e Almas Santas", -1, PORTUGAL, true, true); // Rossiya Frigate
							break;

							case PERIOD_REVOLUTIONS:
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Offic_por_18", 3, PORTUGAL, false);
								GiveShip2Character(ch, "PO_Warship", "Amazona", -1, PORTUGAL, true, true); // Warship
							break;

							case PERIOD_NAPOLEONIC:
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Offic_por_19", 3, PORTUGAL, false);
								GiveShip2Character(ch, "RN_Surprise", "Uniгo", -1, PORTUGAL, true, true); // Unitй class Frigate
							break;
						}
						SetCompanionIndex(pchar, -1, GetCharacterIndex(ch.id));
						RemovePassenger  (pchar,     CharacterFromID  (ch.id));
					}
					else
						LogIt("You seem to have a pretty impressive squadron of your own. Looks like you won't be needing the promotion ship.");
				break;

				case 8: // Comodoro
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "Galeon50", "Santa Teresa", -1, PORTUGAL, true, true); // War Galleon
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "Galeon50", "Santo Antonio", -1, PORTUGAL, true, true); // War Galleon
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "PO_Poseidon", "Salvador do Mundo", -1, PORTUGAL, true, true); // Fleuron class 3rd Rate
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "PO_Poseidon", "Princesa do Ceu", -1, PORTUGAL, true, true); // Fleuron class 3rd Rate
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "RN_Superbe", "Rainha de Portugal", -1, PORTUGAL, true, true); // Superbe class 3rd Rate
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "RN_Superbe", "Rainha de Portugal", -1, PORTUGAL, true, true); // Superbe class 3rd Rate
						break;
					}
				break;

				case 9: // Contra-Almirante
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							if (GetCompanionIndex(pchar,1) == -1 || GetCompanionIndex(pchar,2) == -1 || GetCompanionIndex(pchar,3) == -1) // GR
							{
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "huber_por", 3, PORTUGAL, false);
								GiveShip2Character(pchar, "Galeon1", "Sacramento", -1, PORTUGAL, true, true); // Manila Galleon
								SetCompanionIndex(pchar, -1, GetCharacterIndex(ch.id));
								RemovePassenger  (pchar,     CharacterFromID  (ch.id));
							}
							else
								LogIt("You seem to have a pretty impressive squadron of your own. Looks like you won't be needing the promotion ship.");
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "WallerPinnace", "Santissimo Sacramento da Trindade", -1, PORTUGAL, true, true); // Man of war
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "PO_Trinity", "Nossa Senhora do Cabo e Sao Pedro de Alcantara", -1, PORTUGAL, true, true); // Man of war
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "PO_Trinity", "Nossa Senhora Madre de Deus e Sao Francisco Xavier", -1, PORTUGAL, true, true); // Trinity class 2nd Rate
						break;

						case PERIOD_REVOLUTIONS:
							if (GetCompanionIndex(pchar,1) == -1 || GetCompanionIndex(pchar,2) == -1 || GetCompanionIndex(pchar,3) == -1) // GR
							{
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Offic_por_18", 3, PORTUGAL, false);
								GiveShip2Character(ch, "SuperFrigate", "Nossa Senhora do Bom Despacho", -1, PORTUGAL, true, true); // Warship
								SetCompanionIndex(pchar, -1, GetCharacterIndex(ch.id));
								RemovePassenger  (pchar,     CharacterFromID  (ch.id));
							}
							else
								LogIt("You seem to have a pretty impressive squadron of your own. Looks like you won't be needing the promotion ship.");
						break;

						case PERIOD_NAPOLEONIC:
							if (GetCompanionIndex(pchar,1) == -1 || GetCompanionIndex(pchar,2) == -1 || GetCompanionIndex(pchar,3) == -1) // GR
							{
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Offic_por_18", 3, PORTUGAL, false);
								GiveShip2Character(ch, "PO_Warship", "Martim de Freitas", -1, PORTUGAL, true, true); // Warship
								SetCompanionIndex(pchar, -1, GetCharacterIndex(ch.id));
								RemovePassenger  (pchar,     CharacterFromID  (ch.id));
							}
							else
								LogIt("You seem to have a pretty impressive squadron of your own. Looks like you won't be needing the promotion ship.");
						break;
					}
				break;

				case 10: // Vice-Almirante
					if (GetCompanionIndex(pchar,1) == -1 || GetCompanionIndex(pchar,2) == -1 || GetCompanionIndex(pchar,3) == -1) // GR
					{
						if(GetCurrentPeriod() < PERIOD_COLONIAL_POWERS)
							ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Huber_Por_17", 3, PORTUGAL, false);
						else
							ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Navy_Portugal", 3, PORTUGAL, false);
						switch(GetCurrentPeriod())
						{
							case PERIOD_EARLY_EXPLORERS:
								GiveShip2Character(ch, "Galeon50", "Sao Joao de Deus", -1, PORTUGAL, true, true); // War Galleon
							break;

							case PERIOD_THE_SPANISH_MAIN:
								GiveShip2Character(ch, "Battleship2", "Nossa Senhora da Gloria", -1, PORTUGAL, true, true); // War Galleon
							break;

							case PERIOD_GOLDEN_AGE_OF_PIRACY:
								GiveShip2Character(ch, "Battleship3", "Nossa Senhora da Conceicao", -1, PORTUGAL, true, true); // Battleship
							break;

							case PERIOD_COLONIAL_POWERS:
								GiveShip2Character(ch, "Battleship3", "Nossa Senhora da Conceicao", -1, PORTUGAL, true, true); // Trinity class 2nd Rate
							break;

							case PERIOD_REVOLUTIONS:
								GiveShip2Character(ch, "RN_Superbe", "Santo Augustinho", -1, PORTUGAL, true, true); // Intrйpide class 1st Rate
							break;

							case PERIOD_NAPOLEONIC:
								GiveShip2Character(ch, "RN_Superbe", "Santo Augustinho", -1, PORTUGAL, true, true); // Intrйpide class 1st Rate
							break;
						}
						SetCompanionIndex(pchar, -1, GetCharacterIndex(ch.id));
						RemovePassenger  (pchar,     CharacterFromID  (ch.id));
					}
					else
						LogIt("You seem to have a pretty impressive squadron of your own. Looks like you won't be needing the promotion ship.");
				break;
			}
		break;

		case AMERICA:
			switch(PlayerRank)
			{
				case 1: // Ensign
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "Lugger3", "San Miguel", -1, SPAIN, true, true); // Lugger
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "Lugger3", "San Andreas", -1, SPAIN, true, true); // Lugger
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "KetchNavy", "Morning Star", -1, ENGLAND, true, true); // Naval Ketch
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "PO_Hoy", "Forester", -1, ENGLAND, true, true); // Lyon Hoy
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "Lugger4", "Hancock", -1, AMERICA, true, true); // Weathered lugger
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "Lugger4", "Hancock", -1, AMERICA, true, true); // Weathered lugger
						break;
					}
				break;
				case 2: // Junior Lieutenant
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "Cutter1", "Espaciosa", -1, SPAIN, true, true); // Naval Cutter
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "Cutter1", "Espaciosa", -1, SPAIN, true, true); // Naval Cutter
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "Sloop2", "Shark", -1, ENGLAND, true, true); // Naval Cutter
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "Sloop2", "Success", -1, ENGLAND, true, true); // Naval Cutter
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "SloopBermuda", "Rattlesnake", -1, AMERICA, true, true); // Bermuda Sloop
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "SloopBermuda", "Rattlesnake", -1, AMERICA, true, true); // Bermuda Sloop
						break;
					}
				break;

				case 3: // Lieutenant
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "Polacca_N", "Su Madre", -1, SPAIN, true, true);
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "Galeoth1", "Toro", -1, SPAIN, true, true);
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "RN_Brig", "Drake", -1, ENGLAND, true, true); // Sloop-of-War
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "RN_Brig", "Jamaica", -1, ENGLAND, true, true); // Sloop-of-War
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "USS_Enterprise", "Enterprise", -1, AMERICA, true, true);
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "US_Brig47", "Comet", -1, AMERICA, true, true);
						break;
					}
				break;

				case 4: // Senior Lieutenant
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "SP_Derfflinger", "Girona", -1, SPAIN, true, true); // 
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "SP_NeptunusE", "Kasteel van Medemblik", -1, SPAIN, true, true); // 
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "RN_Postillionen", "Enterprise", -1, ENGLAND, true, true); // 6th Rate Frigate
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "HMS_Greyhound", "Andromeda", -1, ENGLAND, true, true); // 6th Rate Frigate
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "RN_Volage", "Leeroy Jenkins", -1, AMERICA, true, true); // Heavy sloop of war
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "US_PrinceNeufchatel", "Prince de Neufchatel", -1, AMERICA, true, true); // 
						break;
					}
				break;

				case 5: // Commander
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "SP_ApostolFelipe", "Apostуl Felipe", -1, SPAIN, true, true); // 
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "SP_ApostolFelipe", "Apostуl Felipe", -1, SPAIN, true, true); // 
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "RN_RaaFrigate", "Edinburgh", -1, ENGLAND, true, true); // Raa class Frigate
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "HMS_Unicorn", "Unicorn", -1, ENGLAND, true, true); // Lyme class Frigate
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "RN_Surprise", "Insurgent", -1, AMERICA, true, true); // Unitй class Frigate
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "RN_Surprise", "Delaware", -1, AMERICA, true, true); // Unitй class Frigate
						break;
					}
				break;

				case 6: // Post Captain
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "FastGalleon2", "San Esteban", -1, SPAIN, true, true); // Fast Galleon
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "FastGalleon2", "Madonna del Populo", -1, SPAIN, true, true); // Fast Galleon
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "HMS_Mordaunt", "Mordaunt", -1, ENGLAND, true, true); // Advanced Warship
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "HMS_Surprise", "Amazon", -1, ENGLAND, true, true); // Surprise class Frigate
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "USS_Constitution", "Constitution", -1, AMERICA, true, true); // Battle frigate
						break;

						case PERIOD_NAPOLEONIC:
							switch(rand(3))
							{
								case 0: GiveShip2Character(pchar, "USS_Constitution", "Constitution", -1, AMERICA, true, true); break;
								case 1: GiveShip2Character(pchar, "USS_Constitution", "Constitution", -1, AMERICA, true, true); break;
								case 2: GiveShip2Character(pchar, "US_BattleFrigate", "United States", -1, AMERICA, true, true); break;
								case 3: GiveShip2Character(pchar, "US_SteamFrigate", "Hudson", -1, AMERICA, true, true); break;
							}
							if (GetMySimpleOldName(PChar) == "Robert Fulton")	GiveShip2Character(pchar, "US_SteamFrigate", "Hudson", -1, AMERICA, true, true);
						break;
					}
				break;

				case 7: // Commodore
					if (GetCompanionIndex(pchar,1) == -1 || GetCompanionIndex(pchar,2) == -1 || GetCompanionIndex(pchar,3) == -1) // GR
					{
						switch(GetCurrentPeriod())
						{
							case PERIOD_EARLY_EXPLORERS:
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Huber_spa", 3, SPAIN, false);
								GiveShip2Character(ch, "SP_Galeon50", "Santa Rosa", -1, SPAIN, true, true); // Royal Galleon
							break;

							case PERIOD_THE_SPANISH_MAIN:
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Huber_spa", 3, SPAIN, false);
								GiveShip2Character(ch, "SP_Galeon50", "	Nuestra Seсora del Pueblo", -1, SPAIN, true, true); // Royal Galleon
							break;

							case PERIOD_GOLDEN_AGE_OF_PIRACY:
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Kieron", 3, ENGLAND, false);
								GiveShip2Character(ch, "RN_RaaFrigate", "Ambuscade", -1, ENGLAND, true, true); // Raa class Frigate
							break;

							case PERIOD_COLONIAL_POWERS:
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "brtcpt1_18", 3, ENGLAND, false);
								GiveShip2Character(ch, "RN_RaaFrigate", "Ambuscade", -1, ENGLAND, true, true); // Raa class Frigate
							break;

							case PERIOD_REVOLUTIONS:
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "USA_lut_18", 3, AMERICA, false);
								GiveShip2Character(ch, "RN_Surprise", "Bourbon", -1, AMERICA, true, true); // Unitй class Frigate
							break;

							case PERIOD_NAPOLEONIC:
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "USA_lut_18", 3, AMERICA, false);
								GiveShip2Character(ch, "RN_Surprise", "Adams", -1, AMERICA, true, true); // Unitй class Frigate
							break;
						}
						SetCompanionIndex(pchar, -1, GetCharacterIndex(ch.id));
						RemovePassenger  (pchar,     CharacterFromID  (ch.id));
					}
					else
						LogIt("You seem to have a pretty impressive squadron of your own. Looks like you won't be needing the promotion ship.");
				break;

				case 8: // Rear Admiral
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "Galeon50", "San Juan", -1, SPAIN, true, true); // War Galleon
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "Galeon50", "Don Juan", -1, SPAIN, true, true); // War Galleon
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "RN_Poseidon", "Poseidon", -1, ENGLAND, true, true); // Poseidon class 3rd Rate
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "HMS_Centurion", "Centurion", -1, ENGLAND, true, true); // Centurion class 4th Rate
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "FR_Superbe", "America", -1, AMERICA, true, true); // America class 3rd Rate
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "US_Bellona", "Washington", -1, AMERICA, true, true); // Bellona class 3rd Rate
						break;
					}
				break;

				case 9: // Vice Admiral
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "SP_BattleGalleon", "San Martin", -1, SPAIN, true, true); // San Martin
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "SP_SanFelipe", "San Felipe", -1, SPAIN, true, true); // Man of war
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "FR_Trinity", "Resolution", -1, ENGLAND, true, true); // Trinity class 2nd Rate
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "RN_Poseidon", "Poseidon", -1, ENGLAND, true, true); // Poseidon class 3rd Rate
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "US_FirstRate", "Franklin", -1, AMERICA, true, true); // 1st Rate
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "US_FirstRate", "Columbus", -1, AMERICA, true, true); // 1st Rate
						break;
					}
				break;

				case 10: // Admiral
					if (GetCompanionIndex(pchar,1) == -1 || GetCompanionIndex(pchar,2) == -1 || GetCompanionIndex(pchar,3) == -1) // GR
					{
						switch(GetCurrentPeriod())
						{
							case PERIOD_EARLY_EXPLORERS:
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Huber_Spa4_17", 3, SPAIN, false);
								GiveShip2Character(ch, "FastGalleon2", "San Marcos", -1, SPAIN, true, true); // War Galleon
							break;

							case PERIOD_THE_SPANISH_MAIN:
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Huber_Spa4_17", 3, SPAIN, false);
								GiveShip2Character(ch, "Galeon50", "Nuestra Seсora de las Mercedes", -1, SPAIN, true, true); // War Galleon
							break;

							case PERIOD_GOLDEN_AGE_OF_PIRACY:
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Offic_eng_16", 3, ENGLAND, false);
								GiveShip2Character(ch, "FR_Trinity", "Norfolk", -1, ENGLAND, true, true); // Trinity class 2nd Rate
							break;

							case PERIOD_COLONIAL_POWERS:
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "brtcpt2_18", 3, ENGLAND, false);
								GiveShip2Character(ch, "FR_Trinity", "Ramillies", -1, ENGLAND, true, true); // Trinity class 2nd Rate
							break;

							case PERIOD_REVOLUTIONS:
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "USA_cpt_18", 3, AMERICA, false);
								GiveShip2Character(ch, "US_SotL", "Ohio", -1, AMERICA, true, true); // Victory class 1st Rate
							break;

							case PERIOD_NAPOLEONIC:
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "USA_cpt_18", 3, AMERICA, false);
								GiveShip2Character(ch, "US_SotL", "Independence", -1, AMERICA, true, true); // Victory class 1st Rate
							break;
						}
						SetCompanionIndex(pchar, -1, GetCharacterIndex(ch.id));
						RemovePassenger  (pchar,     CharacterFromID  (ch.id));
					}
					else
						LogIt("You seem to have a pretty impressive squadron of your own. Looks like you won't be needing the promotion ship.");
				break;
			}
		break;

		case PIRATE: // Apparently used by Sao Feng, the Turks governor in the Jack Sparrow storyline
			switch(PlayerRank)
			{
				case 1: // Unknown Freebooter
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "Cutter1", "Rabbit", -1, PIRATE, true, true); // Lugger
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "Cutter1", "Redface", -1, PIRATE, true, true); // Lugger
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "Cutter1", "Riddler", -1, PIRATE, true, true); // Hoy
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "Cutter1", "Rover", -1, PIRATE, true, true); // Hoy
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "Cutter1", "Ruffian", -1, PIRATE, true, true); // Hoy
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "Cutter1", "Rye", -1, PIRATE, true, true); // Hoy
						break;
					}
				break;
				case 2: // Unknown Pirate
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "Sloop1", "Ardent", -1, PIRATE, true, true); // Sloop
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "Sloop1", "Ardent", -1, PIRATE, true, true); // Sloop
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "Sloop1", "Argonaut", -1, PIRATE, true, true); // Sloop
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "Sloop1", "Argonaut", -1, PIRATE, true, true); // Sloop
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "PiratHannah", "Zaragozana", -1, PIRATE, true, true); // Light schooner
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "PiratHannah", "Zaragozana", -1, PIRATE, true, true); // Light schooner
						break;
					}
				break;

				case 3: // Freebooter
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "Caravel1", "Whydah Helnot", -1, PIRATE, true, true); // Caravela Latina
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "PiratBrig50", "Serpento do Mar", -1, PIRATE, true, true);
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "Empress", "Ying Tong", -1, PIRATE, true, true); // 
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "Schooner50", "Soucoupe Volante", -1, PIRATE, true, true); // Rum Runner
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "Xebec3", "Montezuma's Revenge", -1, PIRATE, true, true); // Xebec Barbarossa
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "Hooker", "Lady of the Night", -1, PIRATE, true, true); // Hooker schooner
						break;
					}
				break;

				case 4: // Cutthroat
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "FastCaravel", "Santo Domingo", -1, PIRATE, true, true); // Santiago
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "FastCaravel", "Santo Domingo", -1, PIRATE, true, true); // Santiago
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "PiratPostillionen", "Cormorant", -1, PIRATE, true, true); // 6th rate frigate
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "PiratPostillionen", "Atlantis", -1, PIRATE, true, true); // 6th Rate Frigate
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "PO_Volage", "Thor", -1, PIRATE, true, true); // Heavy sloop of war
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "PO_Volage", "Penguin", -1, PIRATE, true, true); // Heavy sloop of war
						break;
					}
				break;

				case 5: // Promising Pirate
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "FastGalleon1", "Nosferatu", -1, PIRATE, true, true); // Fast Galleon
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "FastGalleon1", "Nosferatu", -1, PIRATE, true, true); // Fast Galleon
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "FleutWar", "Dementor", -1, PIRATE, true, true); // 34 gun Fleut of war
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "CrimsonBlood", "Crimson Blood", -1, PIRATE, true, true); // Pirate corvette
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "PiratCorvette", "Black Heart", -1, PIRATE, true, true); // Pirate corvette
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "XebecAS", "Evil Under The Sun", -1, PIRATE, true, true); // Dolphin Xebec
						break;
					}
				break;

				case 6: // Well-known Pirate
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "PiratFastGal", "Sudden Death", -1, PIRATE, true, true); // Pirate Fast Galleon
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "PiratFastGal", "Sudden Death", -1, PIRATE, true, true); // Pirate Fast Galleon
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "QueenAnnesRevenge", "Queen Anne's Revenge", -1, PIRATE, true, true); // Queen Anne's Revenge
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "PiratFrigateSup", "Marauder", -1, PIRATE, true, true); // Rossiya Frigate
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "SuperFrigate", "Sea Eagle", -1, PIRATE, true, true); // Iceni Queen
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "SuperFrigate", "Sea Eagle", -1, PIRATE, true, true); // Iceni Queen
						break;
					}
				break;

				case 7: // Famous Pirate
					if (GetCompanionIndex(pchar,1) == -1 || GetCompanionIndex(pchar,2) == -1 || GetCompanionIndex(pchar,3) == -1) // GR
					{
						
						ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "33_Ronal2", 3, PIRATE, false);
						switch(GetCurrentPeriod())
						{
							case PERIOD_EARLY_EXPLORERS:
								GiveShip2Character(ch, "FleutWar", "Mistress of Mayhem", -1, PIRATE, true, true); // Fleut of war
							break;

							case PERIOD_THE_SPANISH_MAIN:	
								GiveShip2Character(ch, "FleutWar", "Mistress of Mayhem", -1, PIRATE, true, true); // Fleut of war
							break;

							case PERIOD_GOLDEN_AGE_OF_PIRACY:
								GiveShip2Character(ch, "FR_WarGalleon", "Sir Killalot", -1, PIRATE, true, true); // Indiaman
							break;

							case PERIOD_COLONIAL_POWERS:
								GiveShip2Character(ch, "PiratFrigateSup", "No More Mr Nice Guy", -1, PIRATE, true, true); // Rossiya Frigate
							break;

							case PERIOD_REVOLUTIONS:
								GiveShip2Character(ch, "PiratCorvette", "Nervous Energy", -1, PIRATE, true, true); // Warship
							break;

							case PERIOD_NAPOLEONIC:
								GiveShip2Character(ch, "PO_Warship", "Black Pig", -1, PIRATE, true, true); // 5th rate warship
							break;
						}
						SetCompanionIndex(pchar, -1, GetCharacterIndex(ch.id));
						RemovePassenger  (pchar,     CharacterFromID  (ch.id));
					}
					else
						LogIt("You seem to have a pretty impressive squadron of your own. Looks like you won't be needing the promotion ship.");
				break;

				case 8: // Infamous Pirate
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							GiveShip2Character(pchar, "GaleonWar", "Su Madre", -1, PIRATE, true, true); // War Galleon
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "GaleonWar", "Su Madre", -1, PIRATE, true, true); // War Galleon
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "Battleship2", "So Much For Subtlety", -1, PIRATE, true, true); // 3rd rate battleship
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "PO_Poseidon", "Unfortunate Conflict Of Evidence", -1, PIRATE, true, true); // Fleuron class 3rd Rate
						break;

						case PERIOD_REVOLUTIONS:
							GiveShip2Character(pchar, "RN_Superbe", "Ultimate Ship II", -1, PIRATE, true, true); // Superbe class 3rd Rate
						break;

						case PERIOD_NAPOLEONIC:
							GiveShip2Character(pchar, "US_Bellona", "Attitude Adjuster", -1, PIRATE, true, true); // Superbe class 3rd Rate
						break;
					}
				break;

				case 9: // Dread Pirate
					switch(GetCurrentPeriod())
					{
						case PERIOD_EARLY_EXPLORERS:
							if (GetCompanionIndex(pchar,1) == -1 || GetCompanionIndex(pchar,2) == -1 || GetCompanionIndex(pchar,3) == -1) // GR
							{
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "50_Boss1", 3, PIRATE, false);
								GiveShip2Character(pchar, "PiratFastGal", "Sacrificial Minion", -1, PIRATE, true, true); // Pirate Fast Galleon
								SetCompanionIndex(pchar, -1, GetCharacterIndex(ch.id));
								RemovePassenger  (pchar,     CharacterFromID  (ch.id));
							}
							else
								LogIt("You seem to have a pretty impressive squadron of your own. Looks like you won't be needing the promotion ship.");
						break;

						case PERIOD_THE_SPANISH_MAIN:
							GiveShip2Character(pchar, "WallerPinnace", "Problem Child", -1, PIRATE, true, true); // Man of war
						break;

						case PERIOD_GOLDEN_AGE_OF_PIRACY:
							GiveShip2Character(pchar, "SP_Trinity", "Armeartes", -1, PIRATE, true, true); // Man of war
						break;

						case PERIOD_COLONIAL_POWERS:
							GiveShip2Character(pchar, "SP_Trinity", "Armeartes", -1, PIRATE, true, true); // Trinity class 2nd Rate
						break;

						case PERIOD_REVOLUTIONS:
							if (GetCompanionIndex(pchar,1) == -1 || GetCompanionIndex(pchar,2) == -1 || GetCompanionIndex(pchar,3) == -1) // GR
							{
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "50Evl2in", 3, PIRATE, false);
								GiveShip2Character(ch, "SuperFrigate", "Sea Devil", -1, PIRATE, true, true); // Iceni Queen
								SetCompanionIndex(pchar, -1, GetCharacterIndex(ch.id));
								RemovePassenger  (pchar,     CharacterFromID  (ch.id));
							}
							else
								LogIt("You seem to have a pretty impressive squadron of your own. Looks like you won't be needing the promotion ship.");
						break;

						case PERIOD_NAPOLEONIC:
							if (GetCompanionIndex(pchar,1) == -1 || GetCompanionIndex(pchar,2) == -1 || GetCompanionIndex(pchar,3) == -1) // GR
							{
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "50Evl2in", 3, PIRATE, false);
								GiveShip2Character(ch, "SuperFrigate", "Sea Devil", -1, PIRATE, true, true); // Iceni Queen
								SetCompanionIndex(pchar, -1, GetCharacterIndex(ch.id));
								RemovePassenger  (pchar,     CharacterFromID  (ch.id));
							}
							else
								LogIt("You seem to have a pretty impressive squadron of your own. Looks like you won't be needing the promotion ship.");
						break;
					}
				break;

				case 10: // Scourge of the Archipelago
					GiveShip2Character(pchar, "FlyingDutchman", "Flying Dutchman", -1, PIRATE, true, true); // Flying Dutchman
					GiveItem2Character(pchar, "cursedcoin");												// Curse of Cortes
				break;
			}
		break;
	}
}

void GiveSwordAndPerks(int PlayerRank, int iNation)
{
	string PCharTitle; // DeathDaisy
	ref pchar = GetMainCharacter();
	ref ch;
	string qual = "";
	if (ENABLE_WEAPONSMOD) qual = "+2";

	int 							PlayerType = 1; // Privateer
	if (ProfessionalNavyNation() != UNKNOWN_NATION)		PlayerType = 2; // Navy
	if (iNation == PIRATE)					PlayerType = 3; // Pirate

	switch(PlayerRank)
	{
		case 2: // Junior Lieutenant
			switch(PlayerType)
			{
				case 1: UnlockPerkCharacter(PChar ,"BasicLandOwner");	break;	// Privateer
				case 2: UnlockPerkCharacter(PChar ,"Trustworthy");		break;	// Navy
			}
		break;
		case 3: // Lieutenant
			switch(iNation)
			{
				case ENGLAND:
					switch (GetMySimpleOldName(PChar))
					{
						case "Francis Drake":
							GiveItem2Character(pchar,"bladeFD2");
							EquipCharacterByItem(pchar,"bladeFD2");
						break;

						case "Theodore Groves":
							SetRankTitle(PChar, TranslateString("", "Commander"));
						break;

						//default:
						GiveItem2Character(pchar,"blade24"+qual); // English Officer's Saber
						EquipCharacterByItem(pchar,"blade24"+qual);
					}
				break;
				case HOLLAND:
					GiveItem2Character(pchar,"blade23"+qual); // Dutch Admiralty Sword
					EquipCharacterByItem(pchar,"blade23"+qual);
				break;
				case FRANCE:
					GiveItem2Character(pchar,"blade9"+qual); // French Admiralty Rapier
					EquipCharacterByItem(pchar,"blade9"+qual);
				break;
				case SPAIN:
					GiveItem2Character(pchar,"blade33"+qual); // Moorish Saber
					EquipCharacterByItem(pchar,"blade33"+qual);
				break;
				case PORTUGAL:
					GiveItem2Character(pchar,"blade29"+qual); // Portugese Officer's Sword
					EquipCharacterByItem(pchar,"blade29"+qual);
				break;
				case AMERICA:
					GiveItem2Character(pchar,"blade43"+qual); // US Cavalry Saber
					EquipCharacterByItem(pchar,"blade43"+qual);
				break;
				case PIRATE:
					GiveItem2Character(pchar,"blade34"+qual); // Dragon's Head
					EquipCharacterByItem(pchar,"blade34"+qual);
				break;
			}
		break;
		case 5: // Commander
			switch(PlayerType)
			{
				case 1: UnlockPerkCharacter(PChar ,"Trustworthy");		break;	// Privateer
				case 2: UnlockPerkCharacter(PChar ,"Troopers");			break;	// Navy
			}
			switch (GetMySimpleOldName(PChar))
			{
				case "Theodore Groves":
					DeleteAttribute(ch, "title");
				break;
			}
		break;
		case 6: // Captain
		break;
		case 7:		// Commodore/Knight
			switch(iNation)
			{
				case ENGLAND:
					if (!CheckAttribute(PChar, "knighted"))
					{
						// DeathDaisy -->
						if (PChar.sex == "woman") PCharTitle = "Dame";
						else PCharTitle = "Sir";
						// DeathDaisy <--
						SetRankTitle(PChar, TranslateString("", PCharTitle));
						PChar.knighted = iNation;
					}
				break;

				case FRANCE:
					if (!CheckAttribute(PChar, "knighted") && GetCurrentPeriod() < PERIOD_NAPOLEONIC)
					{
						SetRankTitle(PChar, TranslateString("", "Chevalier"));
						PChar.knighted = iNation;
					}
				break;

				case SPAIN:
					if (!CheckAttribute(PChar, "knighted"))
					{
						if (PChar.sex == "woman") PCharTitle = "Doсa";
						else PCharTitle = "Don";
						SetRankTitle(PChar, TranslateString("", PCharTitle));
						PChar.knighted = iNation;
					}
				break;

				case PORTUGAL:
					if (!CheckAttribute(PChar, "knighted"))
					{
						if (PChar.sex == "woman") PCharTitle = "Dona";
						else PCharTitle = "Dom";
						SetRankTitle(PChar, TranslateString("", PCharTitle));
						PChar.knighted = iNation;
					}
				break;
			}

			switch(PlayerType)
			{
				case 1: UnlockPerkCharacter(PChar ,"Troopers");			break;	// Privateer
				case 2: UnlockPerkCharacter(PChar ,"BasicLandOwner");	break;	// Navy
				case 3: UnlockPerkCharacter(PChar ,"Troopers");			break;	// Pirate
			}
		break;
		case 8: // Rear Admiral/Baronet
			switch(iNation)
			{
				case ENGLAND:
				switch (GetMySimpleOldName(PChar))
				{
					case "Francis Drake":
						if (PlayerType != 2)	// If Drake is a naval officer then he'll get a free ship anyway
						{
							if (GetCompanionIndex(pchar,1) == -1 || GetCompanionIndex(pchar,2) == -1 || GetCompanionIndex(pchar,3) == -1) // GR
							{
								ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Offic_eng_15", 3, ENGLAND, false);
								GiveShip2Character(ch, "RN_RevengeF", "Revenge", -1, ENGLAND, true, true); // English War Galleon
								SetCompanionIndex(pchar, -1, GetCharacterIndex(ch.id));
								RemovePassenger  (pchar,     CharacterFromID  (ch.id));
							}
							else
								LogIt("You seem to have a pretty impressive squadron of your own. Looks like you won't be needing the promotion ship.");
						}
					break;
					//default:
					GiveItem2Character(pchar,"blade22"+qual); // Corsair's Pride
					EquipCharacterByItem(pchar,"blade22"+qual);
				}
				break;
				case HOLLAND:
					GiveItem2Character(pchar,"blade26"+qual); // Solingen Rapier
					EquipCharacterByItem(pchar,"blade26"+qual);
				break;
				case FRANCE:
					GiveItem2Character(pchar,"blade25"+qual); // French Nobility Sword
					EquipCharacterByItem(pchar,"blade25"+qual);
				break;
				case SPAIN:
					GiveItem2Character(pchar,"blade14"+qual); // Spanish Nobility Longsword
					EquipCharacterByItem(pchar,"blade14"+qual);
				break;
				case PORTUGAL:
					GiveItem2Character(pchar,"blade32"+qual); // Damascus Shamshir
					EquipCharacterByItem(pchar,"blade32"+qual);
				break;
				case AMERICA:
					// none
				break;
				case PIRATE:
					// none
				break;
			}
		break;

		case 10:	// Admiral/Viscount
			switch(iNation)
			{
				case ENGLAND:
					if (!CheckAttribute(PChar, "knighted") || sti(GetAttribute(PChar, "knighted")) == iNation)
					{
						// DeathDaisy -->
						if (PChar.sex == "woman") PCharTitle = "Lady";
						else PCharTitle = "Lord";
						// DeathDaisy <--
						SetRankTitle(PChar, TranslateString("", PCharTitle));
						PChar.knighted = iNation;
					}
				break;
			}
		break;
	}
}

string OfficerUniform4Player(int PlayerRank, int iNation)
{
	ref pchar = GetMainCharacter();
	if (!CheckAttribute(pchar, "model"))						return "";
	if (ProfessionalNavyNation() == UNKNOWN_NATION)				return "";
	if (pchar.sex == "woman")									return "";
	if (GetAttribute(PChar, "location") == "Tutorial_Deck")		return ""; // PB: Skip this on Start New Game

	string PlayerModel = "";
	switch(iNation)
	{
		case ENGLAND:
			switch(PlayerRank)
			{
				case 1: // Midshipman
					switch(GetMySimpleOldName(PChar))
					{
						case "James Norrington":
							PlayerModel = "Mdnorrington";
						break;
						// default
						if (HasSubStr(pchar.model, "blaze"))
						{
							PlayerModel = "47_Blaze_brtmds";
						}
						else
						{
							switch(rand(3))
							{
								case 0: PlayerModel = "brtmds1_18"; break;
								case 1: PlayerModel = "brtmds2_18"; break;
								case 2: PlayerModel = "brtmds3_18"; break;
								case 3: PlayerModel = "brtmds4_18"; break;
							}
						}
					}
				break;
				case 2: // Junior Lieutenant
					switch(GetMySimpleOldName(PChar))
					{
						case "Jack Sparrow":
							PlayerModel = "47_Ltsparrow";
						break;
						case "James Norrington":
							PlayerModel = "Ltnorrington";
						break;
						case "Andrew Gillette":
							PlayerModel = "Gillette";
						break;
						case "Horatio Hornblower":
							PlayerModel = "brtH3rdLt_18";
						break;
						// default
						if (HasSubStr(pchar.model, "blaze"))
						{
							PlayerModel = "47_Blaze_brtlt";
						}
						else
						{
							if (HasSubStr(pchar.model, "JRMM"))
							{
								PlayerModel = "47_JRMMLt1";
							}
							else
							{
								switch(rand(2))
								{
									case 0: PlayerModel = "brtlut1_18"; break;
									case 1: PlayerModel = "brtlut2_18"; break;
									case 2: PlayerModel = "brtlut3_18"; break;
								}
							}
						}
					}
				break;
				case 3: // Lieutenant
				break;
				case 4: // Senior Lieutenant
				break;
				case 5: // Commander
					switch(GetMySimpleOldName(PChar))
					{
						case "Horatio Hornblower":
							PlayerModel = "brtHComdr_18";
						break;
						case "Horatio Nelson":
							PlayerModel = "Cpnnelson";
						break;
						case "Jack Aubrey":
							PlayerModel = "Aubrey";
						break;
					}
				break;
				case 6: // Post Captain
					switch(GetMySimpleOldName(PChar))
					{
						case "Jack Sparrow":
							PlayerModel = "47_Cptsparrow";
						break;
						case "James Norrington":
							PlayerModel = "Cpnorrington";
						break;
						case "Andrew Gillette":
							PlayerModel = "GilletteCpt";
						break;
						case "Theodore Groves":
							if (PChar.model == "Groves")	PlayerModel = "GrovesCpt";
							else							PlayerModel = "GrovesCpt_EITC";
						break;
						case "Horatio Hornblower":
							PlayerModel = "brtHCap_18";
						break;
						case "Jack Aubrey":
							// Intentionally nothing (skip generic model)
						break;
						// default
						if (HasSubStr(pchar.model, "blaze"))
						{
							PlayerModel = "47_Blaze_brtcpt";
						}
						else
						{
							if (HasSubStr(pchar.model, "JRMM"))
							{
								PlayerModel = "47_JRMMCpt";
							}
							else
							{
								switch(rand(1))
								{
									case 0: PlayerModel = "brtcpt1_18"; break;
									case 1: PlayerModel = "brtcpt2_18"; break;
								}
							}
						}
					}
				break;
				case 7: // Commodore
					switch(GetMySimpleOldName(PChar))
					{
						case "Jack Sparrow":
							PlayerModel = "47_Cosparrow";
						break;
						case "James Norrington":
							PlayerModel = "Conorrington";
						break;
						case "Andrew Gillette":
							PlayerModel = "GilletteC";
						break;
						case "Theodore Groves":
							PlayerModel = "GrovesC";
						break;
						case "Horatio Hornblower":
							PlayerModel = "brtHComdr_18";
						break;
						case "Jack Aubrey":
							// Intentionally nothing (skip generic model)
						break;
						// default
						if (HasSubStr(pchar.model, "blaze"))
						{
							PlayerModel = "47_Blaze_brtco";
						}
						else
						{
							PlayerModel = "brtbath_18";
						}
					}
				break;
				case 8: // Rear Admiral
				break;
				case 9: // Vice Admiral
				break;
				case 10: // Admiral
					switch(GetMySimpleOldName(PChar))
					{
						case "Jack Sparrow":
							PlayerModel = "47_Admsparrow";
						break;
						case "James Norrington":
							PlayerModel = "ANorrington";
						break;
						case "Andrew Gillette":
							PlayerModel = "GilletteA";
						break;
						case "Theodore Groves":
							PlayerModel = "GrovesA";
						break;
						// default
						if (HasSubStr(pchar.model, "blaze"))
						{
							PlayerModel = "47_Blaze_brtadm";
						}
						else
						{
							switch(rand(1))
							{
								case 0: PlayerModel = "brtadm1_18"; break;
								case 1: PlayerModel = "brtadm2_18"; break;
							}
						}
					}
				break;
			}
		break;

		case HOLLAND:
			switch(PlayerRank)
			{
				case 1: // Cadet Officier
				break;
				case 2: // Adjutant Onderofficier
				break;
				case 3: // Derde Luitenant
				break;
				case 4: // Tweede Luitenant
				break;
				case 5: // Eerste Luitenant
				break;
				case 6: // Kapitein-Luitenant
				break;
				case 7: // Kapitein ter zee
				break;
				case 8: // Commandeur
				break;
				case 9: // Schout-bij-Nacht
				break;
				case 10: // Vice-Admiraal
				break;
				case 11: // Luitenant-Admiraal
				break;
				case 12: // Admiraal
				break;
			}
		break;

		case FRANCE:
			switch(PlayerRank)
			{
				case 1: // Enseigne
					switch(GetMySimpleOldName(PChar))
					{
						case "Jack Sparrow":
							PlayerModel = "47_Sparrow_france";
						break;
						// default
						if (HasSubStr(pchar.model, "blaze"))
						{
							PlayerModel = "47_Blaze_france";
						}
						else
						{
							PlayerModel = "Offic_fra_17";
						}
					}
				break;
				case 2: // Sous-Lieutenant de Vaisseau
					switch(GetMySimpleOldName(PChar))
					{
						case "Jack Sparrow":
							PlayerModel = "9JdFra";
						break;
						// default
						switch(rand(2))
						{
							case 0: PlayerModel = "fra_lut_18"; break;
							case 1: PlayerModel = "fra_lut2_18"; break;
							case 2: PlayerModel = "fra_lut3_18"; break;
						}
					}
				break;
				case 3: // Lieutenant de Vaisseau
				break;
				case 4: // Capitaine de Corvette
				break;
				case 5: // Capitaine de Fregate
				break;
				case 6: // Capitaine de Vaisseau
					switch(rand(1))
					{
						case 0: PlayerModel = "fra_cpt_18"; break;
						case 1: PlayerModel = "fra_cpt2_18"; break;
					}
				break;
				case 7: // Contre-Amiral
					PlayerModel = "fra_cmd_18"; break;
				break;
				case 8: // Vice-Amiral
				break;
				case 9: // Vice-Amiral d'Escadre
				break;
				case 10: // Amiral
					PlayerModel = "fra_adm_18"; break;
				break;
			}
		break;

		case SPAIN:
			switch(PlayerRank)
			{
				case 1: // Aspirante
					switch(GetMySimpleOldName(PChar))
					{
						case "Jack Sparrow":
							PlayerModel = "47_Sparrow_spain";
						break;
						// default
						if (HasSubStr(pchar.model, "blaze"))
						{
							PlayerModel = "47_Blaze_spain";
						}
						else
						{
							switch (rand(1))
							{
								case 0: PlayerModel = "spa_mds1_18"; break;
								case 1: PlayerModel = "spa_mds2_18"; break;
							}
						}
					}
				break;
				case 2: // Alfйrez de Fragate
					switch (rand(2))
					{
						case 0: PlayerModel = "spa_lut_18"; break;
						case 1: PlayerModel = "spa_lut1_18"; break;
						case 2: PlayerModel = "spa_lut2_18"; break;
					}
				break;
				case 3: // Alfйrez de Navнo
				break;
				case 4: // Teniente de Navнo
				break;
				case 5: // Capitбn de Corbeta
				break;
				case 6: // Capitбn de Fragata
					switch(rand(2))
					{
						case 0: PlayerModel = "spa_cpt_18"; break;
						case 1: PlayerModel = "spa_cpt1_18"; break;
						case 2: PlayerModel = "spa_cpt2_18"; break;
					}
				break;
				case 7: // Capitбn de Navнo
				break;
				case 8: // Contra Almirante
				break;
				case 9: // Vice Almirante
				break;
				case 10: // Almirante
					PlayerModel = "spa_adm_18"; break;
				break;
				case 11: // Almirante General
				break;
				case 12: // Capitбn General
				break;
			}
		break;
		case PORTUGAL:
			switch(PlayerRank)
			{
				case 1: // Aspirante
				break;
				case 2: // Subtenente
				break;
				case 3: // Segundo-Tenente
				break;
				case 4: // Primeiro-Tenente
				break;
				case 5: // Capitгo-Tenente
				break;
				case 6: // Capitгo-de-Fragata
				break;
				case 7: // Capitгo-de-Mar-e-Guerra
				break;
				case 8: // Comodoro
				break;
				case 9: // Contra-Almirante
				break;
				case 10: // Vice-Almirante
				break;
				case 11: // Almirante
				break;
				case 12: // Almirante da Armada
				break;
			}
		break;
		case AMERICA:
			switch(PlayerRank)
			{
				case 1: // Ensign
				break;
				case 2: // Junior Lieutenant
					switch(GetMySimpleOldName(PChar))
					{
						case "John Paul Jones":
							PlayerModel = "JP_Jones_lut";
						break;
						// default
						PlayerModel = "USA_lut_18";
					}
				break;
				case 3: // Lieutenant
				break;
				case 4: // Senior Lieutenant
				break;
				case 5: // Commander
				break;
				case 6: // Post Captain
					switch(GetMySimpleOldName(PChar))
					{
						case "John Paul Jones":
							PlayerModel = "JP_Jones_cpt";
						break;
						// default
						PlayerModel = "USA_cpt_18";
					}
				break;
				case 7: // Commodore
				break;
				case 8: // Rear Admiral
					switch(GetMySimpleOldName(PChar))
					{
						case "John Paul Jones":
							PlayerModel = "JP_Jones_adm";
						break;
						// default
						PlayerModel = "USA_adm_18";
					}
				break;
				case 9: // Vice Admiral
				break;
				case 10: // Admiral
				break;
				case 11: // Fleet Admiral
				break;
				case 12: // Chief of Naval Operations
				break;
			}
		break;
/*		case EITC: // UNUSED: Just to remind us to use those models at some point
			switch(PlayerRank)
			{
				case 2: // Lieutenant
					switch(GetMySimpleOldName(PChar))
					{
						case "Jack Sparrow":
							PlayerModel = "47_Sparrow_Eitc_lt";
						break;
						// default
						if (HasSubStr(pchar.model, "blaze"))
						{
							PlayerModel = "47Blaze_Eitc_lt";
						}
					}
				break;
				case 4: // Captain
					switch(GetMySimpleOldName(PChar))
					{
						case "Jack Sparrow":
							PlayerModel = "47_Sparrow_Eitc_cpt";
						break;
						// default
						if (HasSubStr(pchar.model, "blaze"))
						{
							PlayerModel = "47Blaze_Eitc_cpt";
						}
					}
				break;
			}
		break;
*/
	}
	return PlayerModel;
}

void GivePromotionOfficers(int PlayerRank, int iNation)
{
	ref pchar = GetMainCharacter();
	ref ch;

	if (ProfessionalNavyNation() == UNKNOWN_NATION)				return;
	if (iNation == PIRATE)										return;

	switch(PlayerRank)
	{
		case 1: // Midshipman
			// Boatswain:
			switch(GetMySimpleOldName(PChar))
			{
				case "Jack Aubrey":
					ch = CreateOfficer_Cheat(OFFIC_TYPE_BOATSWAIN, "man1_1", 3, iNation, false);
					ch.name = TranslateString("","Barret");
					ch.lastname = TranslateString("","Bonden");
				break;
				case "Horatio Nelson":
					ch = CreateOfficer_Cheat(OFFIC_TYPE_BOATSWAIN, "man1_1", 3, iNation, false);
					ch.name = TranslateString("","Frank");
					ch.lastname = TranslateString("","Lepee");
				break;
				ch = CreateOfficer_Cheat(OFFIC_TYPE_BOATSWAIN, GetRandomModelForTypeExSubCheck(1, OFFIC_TYPE_BOATSWAIN, "man", iNation), 3, iNation, false);
			}
		break;
		case 2: // Junior Lieutenant
			// Navigator:
			switch(GetMySimpleOldName(PChar))
			{
				case "Jack Aubrey":
					ch = CreateOfficer_Cheat(OFFIC_TYPE_NAVIGATOR, "Storeman2", 3, iNation, false);
					ch.name = TranslateString("","Michael");
					ch.lastname = TranslateString("","Allen");
				break;
				case "Horatio Nelson":
					ch = CreateOfficer_Cheat(OFFIC_TYPE_NAVIGATOR, "Corsair3_J", 3, iNation, false);
					ch.name = TranslateString("","John");
					ch.lastname = TranslateString("","Wilson");
				break;
				ch = CreateOfficer_Cheat(OFFIC_TYPE_NAVIGATOR, GetRandomModelForTypeExSubCheck(1, OFFIC_TYPE_NAVIGATOR, "man", iNation), 3, iNation, false);
			}
		break;
		case 3: // Lieutenant
			// Doctor:
			switch(GetMySimpleOldName(PChar))
			{
				case "Jack Aubrey":
					ch = CreateOfficer_Cheat(OFFIC_TYPE_DOCTOR, "apothecary", 3, iNation, false);
					ch.name = TranslateString("","Stephen");
					ch.lastname = TranslateString("","Maturin");
				break;
				case "Horatio Nelson":
					ch = CreateOfficer_Cheat(OFFIC_TYPE_DOCTOR, "9S_Nat", 3, iNation, false);
					ch.name = TranslateString("","Francis");
					ch.lastname = TranslateString("","Forster");
				break;
				ch = CreateOfficer_Cheat(OFFIC_TYPE_DOCTOR, GetRandomModelForTypeExSubCheck(1, OFFIC_TYPE_DOCTOR, "man", iNation), 3, iNation, false);
			}

			// Midshipman:
			if(GetCurrentPeriod() >= PERIOD_COLONIAL_POWERS)
			{
				switch(iNation)
				{
					case ENGLAND:	ch = CreateOfficer_Cheat(OFFIC_TYPE_ABORDAGE, "brtmds1_18", 3, iNation, false);		break;
					case SPAIN:		ch = CreateOfficer_Cheat(OFFIC_TYPE_ABORDAGE, "spa_mds1_18" , 3, iNation, false);	break;
				}
			}
			else
			{
				ch = CreateOfficer_Cheat(OFFIC_TYPE_ABORDAGE, GetRandomModelForTypeExSubCheck(true, "Land_Officers", "man", iNation), 3, iNation, false);
			}
			SetRank(ch, iNation, 1);
			switch(GetMySimpleOldName(PChar))
			{
				case "Jack Aubrey":
					ch.name = TranslateString("","Peter");
					ch.lastname = TranslateString("","Calamy");
				break;
				case "Horatio Nelson":
					ch.name = TranslateString("","Henry");
					ch.lastname = TranslateString("","Lee");
				break;
				case "James Norrington":
					ch = CreateOfficer_Cheat(OFFIC_TYPE_FIRSTMATE, "Gillette", 3, iNation, false);
					ch.name = TranslateString("","Andrew");
					ch.lastname = TranslateString("","Gillette");
					GiveItem2Character(ch, "blade24+3");
					GiveItem2Character(ch, "PiratesPistol+2");
					ch.equip.blade = "blade24+3";
					ch.equip.gun = "PiratesPistol+2";
					ch.HPBonus = 100;
					ch.professionalnavy = ch.nation;
					SetRank(ch, iNation, 3);
				break;
				case "Theodore Groves":
					ch = CreateOfficer_Cheat(OFFIC_TYPE_FIRSTMATE, "Gillette", 3, iNation, false);
					ch.name = TranslateString("","Andrew");
					ch.lastname = TranslateString("","Gillette");
					GiveItem2Character(ch, "blade24+3");
					GiveItem2Character(ch, "PiratesPistol+2");
					ch.equip.blade = "blade24+3";
					ch.equip.gun = "PiratesPistol+2";
					ch.HPBonus = 100;
					ch.professionalnavy = ch.nation;
					SetRank(ch, iNation, 3);
				break;
			}
		break;
		case 4: // Senior Lieutenant
			// Quartermaster:
			switch(GetMySimpleOldName(PChar))
			{
				case "Horatio Nelson":
					ch = CreateOfficer_Cheat(OFFIC_TYPE_QMASTER, "BadV", 3, iNation, false);
					ch.name = TranslateString("","John");
					ch.lastname = TranslateString("","Tyson");
				break;
				ch = CreateOfficer_Cheat(OFFIC_TYPE_QMASTER, GetRandomModelForTypeExSubCheck(1, OFFIC_TYPE_QMASTER, "man", iNation), 3, iNation, false);
			}
			// Cannoneer:
			switch(GetMySimpleOldName(PChar))
			{
				case "Horatio Nelson":
					ch = CreateOfficer_Cheat(OFFIC_TYPE_CANNONEER, "capstan", 3, iNation, false);
					ch.name = TranslateString("","William");
					ch.lastname = TranslateString("","Sylvan");
				break;
				ch = CreateOfficer_Cheat(OFFIC_TYPE_CANNONEER, GetRandomModelForTypeExSubCheck(1, OFFIC_TYPE_CANNONEER, "man", iNation), 3, iNation, false);
			}
		break;
		case 5: // Commander
			// First Mate:
			switch(iNation)
			{
				case ENGLAND:
					if(GetCurrentPeriod() < PERIOD_COLONIAL_POWERS)
						ch = CreateOfficer_Cheat(OFFIC_TYPE_FIRSTMATE, "9JdEng", 3, iNation, false);
					else
						ch = CreateOfficer_Cheat(OFFIC_TYPE_FIRSTMATE, "brtlut3_18", 3, iNation, false);
				break;
				case FRANCE:
					if(GetCurrentPeriod() < PERIOD_COLONIAL_POWERS)
						ch = CreateOfficer_Cheat(OFFIC_TYPE_FIRSTMATE, "9JdFra", 3, iNation, false);
					else
						ch = CreateOfficer_Cheat(OFFIC_TYPE_FIRSTMATE, "fra_lut3_18", 3, iNation, false);
				break;
				case SPAIN:
					if(GetCurrentPeriod() < PERIOD_COLONIAL_POWERS)
						ch = CreateOfficer_Cheat(OFFIC_TYPE_FIRSTMATE, "9JdSpa", 3, iNation, false);
					else
						ch = CreateOfficer_Cheat(OFFIC_TYPE_FIRSTMATE, "spa_lut2_18", 3, iNation, false);
				break;
				case HOLLAND:
					ch = CreateOfficer_Cheat(OFFIC_TYPE_FIRSTMATE, "9JdHol", 3, iNation, false);
				break;
				case PORTUGAL:
					ch = CreateOfficer_Cheat(OFFIC_TYPE_FIRSTMATE, "9JdPor", 3, iNation, false);
				break;
				case AMERICA:
					ch = CreateOfficer_Cheat(OFFIC_TYPE_FIRSTMATE, "USA_lut_18", 3, iNation, false);
				break;
			}
			SetRank(ch, iNation, 3);
			switch(GetMySimpleOldName(PChar))
			{
				case "Horatio Nelson":
					ch.name = TranslateString("","Osborne");
					ch.lastname = TranslateString("","Edwards");
				break;
				case "Jack Aubrey":
					ch.name = TranslateString("","William");
					ch.lastname = TranslateString("","Mowett");
				break;
				case "Horatio Hornblower":
					if(GetCharacterIndex("Lt. William Bush") != -1)	// If a real Lt. Bush exists, use him
					{
						RemoveOfficersIndex(PChar, ch);
						RemovePassenger(PChar, ch);
						ch = CharacterFromID("Lt. William Bush");
						LAi_SetOfficerType(ch);
						AddPassenger(PChar, ch, false);
					}
					else							// otherwise create a fake one
					{
						SetModelFromID(ch, "BushLtn_18");
						ch.name = TranslateString("","William");
						ch.lastname = TranslateString("","Bush");
						SetRank(ch, ENGLAND, 4);
					}
				break;
				case "James Norrington":
					ch = CreateOfficer_Cheat(OFFIC_TYPE_FIRSTMATE, "Groves", 3, iNation, false);
					ch.name = TranslateString("","Theodore");
					ch.lastname = TranslateString("","Groves");
					GiveItem2Character(ch, "blade24+3");
					GiveItem2Character(ch, "PiratesPistol+2");
					ch.equip.blade = "blade24+3";
					ch.equip.gun = "PiratesPistol+2";
					ch.HPBonus = 100;
					ch.professionalnavy = ch.nation;
					SetRank(ch, iNation, 3);
					SetRankTitle(ch, TranslateString("", "Commander"));
				break;
				case "Andrew Gillette":
					ch = CreateOfficer_Cheat(OFFIC_TYPE_FIRSTMATE, "Groves", 3, iNation, false);
					ch.name = TranslateString("","Theodore");
					ch.lastname = TranslateString("","Groves");
					GiveItem2Character(ch, "blade24+3");
					GiveItem2Character(ch, "PiratesPistol+2");
					ch.equip.blade = "blade24+3";
					ch.equip.gun = "PiratesPistol+2";
					ch.HPBonus = 100;
					ch.professionalnavy = ch.nation;
					SetRank(ch, iNation, 3);
					SetRankTitle(ch, TranslateString("", "Commander"));
				break;
			}
		break;
		case 6: // Post Captain
			// Carpenter:
			switch(GetMySimpleOldName(PChar))
			{
				case "Horatio Nelson":
					ch = CreateOfficer_Cheat(OFFIC_TYPE_CARPENTER, "will_2", 3, iNation, false);
					ch.name = TranslateString("","William");
					ch.lastname = TranslateString("","Orswood");
				break;

				case "Horatio Hornblower":
					if(GetCharacterIndex("Lieutenant Gerard") != -1)	// If a real Lieutenant Gerard exists, use him
					{
						ch = CharacterFromID("Lieutenant Gerard");
						LAi_SetOfficerType(ch);
						AddPassenger(PChar, ch, false);
					}
					else							// otherwise create a fake one
					{
						ch = CreateOfficer_Cheat(OFFIC_TYPE_CARPENTER, "brtlut2_18", 3, iNation, false);
						ch.name = TranslateString("","Lieutenant");;
						ch.lastname = TranslateString("","Gerard");
						SetRank(ch, ENGLAND, 3);
					}
				break;
				ch = CreateOfficer_Cheat(OFFIC_TYPE_CARPENTER, GetRandomModelForTypeExSubCheck(1, OFFIC_TYPE_CARPENTER, "man", iNation), 3, iNation, false);
			}
		break;
		case 8: // Rear Admiral
			// First Mate:
			switch(GetMySimpleOldName(PChar))
			{
				case "Andrew Gillette":
					ch = CreateOfficer_Cheat(OFFIC_TYPE_FIRSTMATE, "Conorrington", 3, iNation, false);
					ch.name = TranslateString("","James");
					ch.lastname = TranslateString("","Norrington");
					GiveItem2Character(ch, "blade22+3");
					GiveItem2Character(ch, "PiratesPistol+2");
					ch.equip.blade = "blade22+3";
					ch.equip.gun = "PiratesPistol+2";
					ch.HPBonus = 100;
					ch.professionalnavy = ch.nation;
					SetRank(ch, iNation, 7);
				break;
				case "Theodore Groves":
					ch = CreateOfficer_Cheat(OFFIC_TYPE_FIRSTMATE, "Conorrington", 3, iNation, false);
					ch.name = TranslateString("","James");
					ch.lastname = TranslateString("","Norrington");
					GiveItem2Character(ch, "blade22+3");
					GiveItem2Character(ch, "PiratesPistol+2");
					ch.equip.blade = "blade22+3";
					ch.equip.gun = "PiratesPistol+2";
					ch.HPBonus = 100;
					ch.professionalnavy = ch.nation;
					SetRank(ch, iNation, 7);
				break;
			}
		break;
	}
}

void GiveModel2Player(string model, bool assign)
{
	if(assign) SetModelfromArray(GetMainCharacter(), GetModelIndex(model));
/*	else
	{
		if (!CheckAttribute(GetMainCharacter(), "clothes." + model))   LogIt("You got the " + model + " outfit: " + Models[GetModelIndex(model)].description);
	}*/
	Characters[GetMainCharacterIndex()].clothes.(model) = true;
}

string GetAttribute(ref tmp, string att)
{
	if(CheckAttribute(tmp,att)) return tmp.(att);
	return "-1";//MAXIMUS: and now we can use it for int and float check
}

float GetTimeScale()
{
	float basetime = 1.0;
	ref pchar = GetMainCharacter();
	if(CheckAttribute(PChar,"basetime"))	basetime = stf(PChar.basetime);
	return basetime;
}

#event_handler("CheckTimeScale", "UpdateTimeScale");
void UpdateTimeScale()
{
	float basetime = GetTimeScale();
	SetTimeScale(basetime);
	ILog.Log.speed       = 0.1  / GetTimeScale(); // text doesn't scroll quicker on higher time compression
	ILog.Log.color_speed = 0.01 / GetTimeScale(); // text doesn't scroll quicker on higher time compression
	if(basetime > 1.0)						AddPerkToActiveList("TimeSpeed");
	else									DelPerkFromActiveList("TimeSpeed");
}

void ResetTimeToNormal()
{
	if(GetTimeScale() > 1.0)				// skip this if you are already on normal
	{
		Characters[GetMaincharacterIndex()].basetime = 1.0;
		UpdateTimeScale();
	}
}

bool KrakenAttackEnabled()
{
	ref pchar = GetMainCharacter();
	ref ch;
	if(CheckAttribute(pchar, "KrakenAttack"))				return false;	// No Kraken attack is available until a set time after the previous attack
	if(CheckAttribute(pchar, "ship.SubmergeDutchman"))			return false;	// No Kraken attack is available while the Dutchman is submerged
	for (int i = 0; i < COMPANION_MAX; i++)
	{
		if (GetCompanionIndex(pchar, i) < 0) continue;
		ch = GetCharacter(GetCompanionIndex(pchar, i));
		if(GetAttribute(ch, "ship.type") == "CursedDutchman")		return true;	// Only the CURSED Flying Dutchman can call upon the Kraken
	}
	return false;
}

void KrakenAttack(aref rCharacter, int iSwimQuantity)
// Character and number of tentacles
{
	if (!bSeaActive) return;
	ref pchar = GetMainCharacter();
	int delay = 0;
	for (int i=0; i < iSwimQuantity; i++)
	{
		PostEvent("CreateKrakenTentacle", delay, "i", rCharacter);
		delay = delay + rand(1000);
	}
	if(IsMainCharacter(rCharacter)) LogIt("Captain, we're being attacked by the Kraken!");
	else
	{
		LogIt("Captain, the " + rCharacter.ship.name + " is under attack by the Kraken!");
		pchar.KrakenAttack = true;
	}
	PostEvent("KrakenAttackFinished", delay, "i", rCharacter);
}

#event_handler("KrakenAttackFinished", "FinishKrakenAttack");
void FinishKrakenAttack()
{
	ref pchar = GetMainCharacter();
	aref rCharacter = GetEventData();
	LogIt("Captain, the Kraken has finished its attack on the " + rCharacter.ship.name + "!");
	if(CheckAttribute(pchar, "KrakenAttack"))	PostEvent("EnableKraken", 5*60*1000);
}

#event_handler("EnableKraken", "KrakenEnabled");
void KrakenEnabled()
{
	ref pchar = GetMainCharacter();
	DeleteAttribute(pchar, "KrakenAttack");
	if(KrakenAttackEnabled()) LogIt("Captain, the Kraken is ready for another attack!"); // Just in case you swap ships
}

#event_handler("CreateKrakenTentacle", "KrakenTentacle");
void KrakenTentacle()
{
	if (!bSeaActive) return;
	aref rCharacter = GetEventData();
	if(CheckAttribute(rCharacter,"Ship"))
	{
		switch(rand(15))
		{
			case  0: Direct_AddGood(rCharacter, "Oil", "tentacle1_0",  0.0,105,10+rand(40),Degree2Radian(rand(20)-10)+Degree2Radian(135.0)-stf(rCharacter.Ship.Ang.y)); break;
			case  1: Direct_AddGood(rCharacter, "Oil", "tentacle1_90", 0.0,105,10+rand(40),Degree2Radian(rand(20)-10)+Degree2Radian(225.0)-stf(rCharacter.Ship.Ang.y)); break;
			case  2: Direct_AddGood(rCharacter, "Oil", "tentacle1_180",0.0,105,10+rand(40),Degree2Radian(rand(20)-10)+Degree2Radian(315.0)-stf(rCharacter.Ship.Ang.y)); break;
			case  3: Direct_AddGood(rCharacter, "Oil", "tentacle1_270",0.0,105,10+rand(40),Degree2Radian(rand(20)-10)+Degree2Radian(45.0) -stf(rCharacter.Ship.Ang.y)); break;
			case  4: Direct_AddGood(rCharacter, "Oil", "tentacle2_0",  0.0,105, 5+rand(40),Degree2Radian(rand(20)-10)+Degree2Radian(70.0) -stf(rCharacter.Ship.Ang.y)); break;
			case  5: Direct_AddGood(rCharacter, "Oil", "tentacle2_90", 0.0,105, 5+rand(40),Degree2Radian(rand(20)-10)+Degree2Radian(160.0)-stf(rCharacter.Ship.Ang.y)); break;
			case  6: Direct_AddGood(rCharacter, "Oil", "tentacle2_180",0.0,105, 5+rand(40),Degree2Radian(rand(20)-10)+Degree2Radian(250.0)-stf(rCharacter.Ship.Ang.y)); break;
			case  7: Direct_AddGood(rCharacter, "Oil", "tentacle2_270",0.0,105, 5+rand(40),Degree2Radian(rand(20)-10)+Degree2Radian(340.0)-stf(rCharacter.Ship.Ang.y)); break;
			case  8: Direct_AddGood(rCharacter, "Oil", "tentacle3_0",  0.0,105,10+rand(20),Degree2Radian(rand(20)-10)+Degree2Radian(90.0) -stf(rCharacter.Ship.Ang.y)); break;
			case  9: Direct_AddGood(rCharacter, "Oil", "tentacle3_90", 0.0,105,10+rand(20),Degree2Radian(rand(20)-10)+Degree2Radian(180.0)-stf(rCharacter.Ship.Ang.y)); break;
			case 10: Direct_AddGood(rCharacter, "Oil", "tentacle3_180",0.0,105,10+rand(20),Degree2Radian(rand(20)-10)+Degree2Radian(270.0)-stf(rCharacter.Ship.Ang.y)); break;
			case 11: Direct_AddGood(rCharacter, "Oil", "tentacle3_270",0.0,105,10+rand(20),Degree2Radian(rand(20)-10)+Degree2Radian(0.0)  -stf(rCharacter.Ship.Ang.y)); break;
			case 12: Direct_AddGood(rCharacter, "Oil", "tentacle4_0",  0.0,105, 5+rand(20),Degree2Radian(rand(20)-10)+Degree2Radian(90.0) -stf(rCharacter.Ship.Ang.y)); break;
			case 13: Direct_AddGood(rCharacter, "Oil", "tentacle4_90", 0.0,105, 5+rand(20),Degree2Radian(rand(20)-10)+Degree2Radian(180.0)-stf(rCharacter.Ship.Ang.y)); break;
			case 14: Direct_AddGood(rCharacter, "Oil", "tentacle4_180",0.0,105, 5+rand(20),Degree2Radian(rand(20)-10)+Degree2Radian(270.0)-stf(rCharacter.Ship.Ang.y)); break;
			case 15: Direct_AddGood(rCharacter, "Oil", "tentacle4_270",0.0,105, 5+rand(20),Degree2Radian(rand(20)-10)+Degree2Radian(0.0)  -stf(rCharacter.Ship.Ang.y)); break;
		}
	}
}

#event_handler("UpdateDutchmanSubmersion", "SubmergeDutchman");
void SubmergeDutchman()
{
	aref rCharacter = GetEventData();

	if(CheckAttribute(rCharacter, "ship.SubmergeDutchman"))
	{
		float fX, fY, fZ, fAY, gX, gY, gZ;
		fX = 0; fY = 0; fZ = 0;
		if(CheckAttribute(rCharacter,"Ship.pos.x")) fX=stf(rCharacter.Ship.pos.x);
			else return;
		if(CheckAttribute(rCharacter,"Ship.pos.y")) fY=stf(rCharacter.Ship.pos.y);
			else return;
		if(CheckAttribute(rCharacter,"Ship.pos.z")) fZ=stf(rCharacter.Ship.pos.z);
			else return;
		if(CheckAttribute(rCharacter,"Ship.Ang.y")) fAY=stf(rCharacter.Ship.Ang.y);
			else return;
		rCharacter.firedrill = true;
		if(!CheckAttribute(rCharacter, "ship.EmergeDutchman"))
		{
			rCharacter.ship.SubmergeDutchman = makefloat(rCharacter.ship.SubmergeDutchman) + 0.35;
			if(!CheckAttribute(rCharacter, "ship.PlayedSplash"))
			{
				rCharacter.ship.PlayedSplash = 1;
				gX =  0; gY = 0; gZ = 30;
				CreateParticleSystemX("dutchman_submerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  5; gY = 0; gZ = 20;
				CreateParticleSystemX("dutchman_submerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX = -5; gY = 0; gZ = 20;
				CreateParticleSystemX("dutchman_submerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  5; gY = 0; gZ = 10;
				CreateParticleSystemX("dutchman_submerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX = -5; gY = 0; gZ = 10;
				CreateParticleSystemX("dutchman_submerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  5; gY = 0; gZ = 0;
				CreateParticleSystemX("dutchman_submerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX = -5; gY = 0; gZ = 0;
				CreateParticleSystemX("dutchman_submerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  5; gY = 0; gZ = -10;
				CreateParticleSystemX("dutchman_submerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX = -5; gY = 0; gZ = -10;
				CreateParticleSystemX("dutchman_submerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  5; gY = 0; gZ = -20;
				CreateParticleSystemX("dutchman_submerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX = -5; gY = 0; gZ = -20;
				CreateParticleSystemX("dutchman_submerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  0; gY = 0; gZ = -30;
				CreateParticleSystemX("dutchman_submerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				PlayStereoSound("objects\shipcharge\take_prey.wav");
			}
			if(stf(rCharacter.ship.SubmergeDutchman) >= 53)
			{
				rCharacter.ship.SubmergeDutchman = 53;
			}
			rCharacter.ship.immersion = rCharacter.ship.SubmergeDutchman;
		}
		else
		{
			rCharacter.ship.SubmergeDutchman =  makefloat(rCharacter.ship.SubmergeDutchman) - 0.30;
			if(stf(rCharacter.ship.SubmergeDutchman)-50 <= stf(rCharacter.ship.CorrectImmersion) && !CheckAttribute(rCharacter, "ship.PlayedSplash"))
			{
				gX =  0; gY = 52 - stf(rCharacter.ship.SubmergeDutchman); gZ = -2;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				PauseAllSounds();
				FadeOutMusic(150);
				PlaystereoOGG("music_emerge_dutchman");
				//FadeOutMusic(500);
				if (!bDisableMapEnter)	PostEvent("LoadSceneSound", 110000);
				else					PostEvent("LoadSceneSound", 41500);
				rCharacter.ship.PlayedSplash = 1;
			}
			if(stf(rCharacter.ship.SubmergeDutchman)-48 <= stf(rCharacter.ship.CorrectImmersion) && sti(GetAttribute(rCharacter, "ship.PlayedSplash")) == 1)
			{
				Ship_ChangeCharge(rCharacter, sti(rCharacter.Ship.Cannons.Charge.Type)); 
				gX = 0; gY = 45 - stf(rCharacter.ship.SubmergeDutchman); gZ = 16;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
			//	PlayStereoSound("objects\shipcharge\ball_splash1.wav");
				rCharacter.ship.PlayedSplash = 2;
			}
			if(stf(rCharacter.ship.SubmergeDutchman)-45 <= stf(rCharacter.ship.CorrectImmersion) && sti(GetAttribute(rCharacter, "ship.PlayedSplash")) == 2)
			{
				gX = 0; gY = 45 - stf(rCharacter.ship.SubmergeDutchman); gZ = 16;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
			//	PlayStereoSound("objects\shipcharge\ball_splash1.wav");
				rCharacter.ship.PlayedSplash = 3;
			}
			if(stf(rCharacter.ship.SubmergeDutchman)-40 <= stf(rCharacter.ship.CorrectImmersion) && sti(GetAttribute(rCharacter, "ship.PlayedSplash")) == 3)
			{
				gX = 0; gY = 45 - stf(rCharacter.ship.SubmergeDutchman); gZ = 16;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
			//	PlayStereoSound("objects\shipcharge\ball_splash1.wav");
				rCharacter.ship.PlayedSplash = 4;
			}
			if(stf(rCharacter.ship.SubmergeDutchman)-35 <= stf(rCharacter.ship.CorrectImmersion) && sti(GetAttribute(rCharacter, "ship.PlayedSplash")) == 4)
			{
				gX = 0; gY = 35 - stf(rCharacter.ship.SubmergeDutchman); gZ = -13;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
			//	PlayStereoSound("objects\shipcharge\ball_splash1.wav");
				rCharacter.ship.PlayedSplash = 5;
			}
			if(stf(rCharacter.ship.SubmergeDutchman)-25 <= stf(rCharacter.ship.CorrectImmersion) && sti(GetAttribute(rCharacter, "ship.PlayedSplash")) == 5)
			{
				gX = 0; gY = 45 - stf(rCharacter.ship.SubmergeDutchman); gZ = 16;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
			//	PlayStereoSound("objects\shipcharge\ball_splash1.wav");
				rCharacter.ship.PlayedSplash = 6;
			}
			if(stf(rCharacter.ship.SubmergeDutchman)-10 <= stf(rCharacter.ship.CorrectImmersion) && sti(GetAttribute(rCharacter, "ship.PlayedSplash")) == 6)
			{

				gX =  0; gY = 0; gZ = 30;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  5; gY = 0; gZ = 25;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX = -5; gY = 0; gZ = 25;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  5; gY = 0; gZ = 20;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX = -5; gY = 0; gZ = 20;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  5; gY = 0; gZ = 15;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX = -5; gY = 0; gZ = 15;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  5; gY = 0; gZ = 10;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX = -5; gY = 0; gZ = 10;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  5; gY = 0; gZ = 5;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX = -5; gY = 0; gZ = 5;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  5; gY = 0; gZ = 0;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX = -5; gY = 0; gZ = 0;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  5; gY = 0; gZ = -5;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX = -5; gY = 0; gZ = -5;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  5; gY = 0; gZ = -10;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX = -5; gY = 0; gZ = -10;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  5; gY = 0; gZ = -15;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX = -5; gY = 0; gZ = -15;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  5; gY = 0; gZ = -20;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX = -5; gY = 0; gZ = -20;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  5; gY = 0; gZ = -25;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX = -5; gY = 0; gZ = -25;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  0; gY = 0; gZ = -30;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
			//	PlayStereoSound("objects\shipcharge\ball_splash1.wav");
				rCharacter.ship.PlayedSplash = 7;
			}
			if(stf(rCharacter.ship.SubmergeDutchman)-0 <= stf(rCharacter.ship.CorrectImmersion) && sti(GetAttribute(rCharacter, "ship.PlayedSplash")) == 7)
			{
				gX =  0; gY = 0; gZ = 30;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  5; gY = 0; gZ = 25;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX = -5; gY = 0; gZ = 25;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  5; gY = 0; gZ = 20;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX = -5; gY = 0; gZ = 20;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  5; gY = 0; gZ = 15;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX = -5; gY = 0; gZ = 15;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  5; gY = 0; gZ = 10;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX = -5; gY = 0; gZ = 10;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  5; gY = 0; gZ = 5;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX = -5; gY = 0; gZ = 5;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  5; gY = 0; gZ = 0;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX = -5; gY = 0; gZ = 0;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  5; gY = 0; gZ = -5;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX = -5; gY = 0; gZ = -5;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  5; gY = 0; gZ = -10;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX = -5; gY = 0; gZ = -10;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  5; gY = 0; gZ = -15;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX = -5; gY = 0; gZ = -15;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  5; gY = 0; gZ = -20;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX = -5; gY = 0; gZ = -20;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  5; gY = 0; gZ = -25;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX = -5; gY = 0; gZ = -25;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  0; gY = 0; gZ = -30;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
			//	PlayStereoSound("objects\shipcharge\ball_splash1.wav");
				rCharacter.ship.PlayedSplash = 8;
			}
			if(stf(rCharacter.ship.SubmergeDutchman) <= stf(rCharacter.ship.CorrectImmersion))
			{
				rCharacter.ship.immersion = rCharacter.ship.CorrectImmersion;
				//Ship_ChangeCharge(rCharacter, sti(rCharacter.Ship.Cannons.Charge.Type)); // Reload cannons
				gX = 0; gY = 15 - stf(rCharacter.ship.SubmergeDutchman); gZ = 16;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  0; gY = 0; gZ = 30;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  0; gY = 0; gZ = 20;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  0; gY = 0; gZ = 10;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  0; gY = 0; gZ = -10;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  0; gY = 0; gZ = -20;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				gX =  0; gY = 0; gZ = -30;
				CreateParticleSystemX("dutchman_emerge",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 3.0, 0.0, 2);
				DeleteAttribute(rCharacter, "ship.SubmergeDutchman");
				DeleteAttribute(rCharacter, "ship.EmergeDutchman");
				DeleteAttribute(rCharacter, "ship.PlayedSplash");
			}
			else
				rCharacter.ship.immersion = rCharacter.ship.SubmergeDutchman;
		}
	}
}

#event_handler("CreateCursedPearlFog", "CursedPearlFog");
void CursedPearlFog()
{
	aref rCharacter = GetEventData();
	float fX, fY, fZ, fAY;
	fX = 0; fY = 0; fZ = 0;

	if(CheckAttribute(rCharacter,"Ship.pos.x")) fX=stf(rCharacter.Ship.pos.x);
		else return;
	if(CheckAttribute(rCharacter,"Ship.pos.y")) fY=stf(rCharacter.Ship.pos.y);
		else return;
	if(CheckAttribute(rCharacter,"Ship.pos.z")) fZ=stf(rCharacter.Ship.pos.z);
		else return;
	if(CheckAttribute(rCharacter,"Ship.Ang.y")) fAY=stf(rCharacter.Ship.Ang.y);
		else return;
	float gX, gY, gZ;
	gX = 0; // Width
	gY = 0; // Height
	gZ = 10; // Length
	CreateParticleSystemX("pearlfog",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 0.0, 0.0, 2);
}

#event_handler("CreateCursedDevilFog", "CursedDevilFog");
void CursedDevilFog()
{
	aref rCharacter = GetEventData();
	float fX, fY, fZ, fAY;
	fX = 0; fY = 0; fZ = 0;

	if(CheckAttribute(rCharacter,"Ship.pos.x")) fX=stf(rCharacter.Ship.pos.x);
		else return;
	if(CheckAttribute(rCharacter,"Ship.pos.y")) fY=stf(rCharacter.Ship.pos.y);
		else return;
	if(CheckAttribute(rCharacter,"Ship.pos.z")) fZ=stf(rCharacter.Ship.pos.z);
		else return;
	if(CheckAttribute(rCharacter,"Ship.Ang.y")) fAY=stf(rCharacter.Ship.Ang.y);
		else return;
	float gX, gY, gZ;
	gX = 0; // Width
	gY = 0; // Height
	gZ = 10; // Length
	CreateParticleSystemX("devilfog",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), 0.0, 0.0, 0.0, 2);
}

bool BPSweepsEnabled()
{
	ref pchar = GetMainCharacter();
	if(sti(GetAttribute(pchar, "ship.type")) != SHIP_CURSED)		return false;	// Only the Cursed Black Pearl can use the sweeps
	if(CheckAttribute(pchar, "ship.speedburst"))					return false;	// Sweeps cannot be used for a certain period of time
	return true;
}

bool QARSwordEnabled()
{
	ref pchar = GetMainCharacter();
	if(!CheckCharacterItem(pchar, "Blade_Triton"))					return false;	// You need to have the item
	if(CheckAttribute(pchar, "ship.speedburst"))					return false;	// Sword of Triton needs time to recharge after using
	return true;
}

#event_handler("FinishSpeedBurst", "FinishedSpeedBurst");
void FinishedSpeedBurst()
{
	ref pchar = GetMainCharacter();
	PostEvent("SpeedBurstFinished",120000, "i", pchar);
	pchar.Ship.Impulse.Rotate.z = 0.0;
	if (GetAttribute(pchar, "ship.speedburst") == "PearlSweeps")	DelPerkFromActiveList("PearlSweeps");
}

#event_handler("SpeedBurstFinished", "SpeedBurstAvailable");
void SpeedBurstAvailable()
{
	ref pchar = GetMainCharacter();
	if (GetAttribute(pchar, "ship.speedburst") == "PearlSweeps")	LogIt("Captain, the crew is ready for another go at the oars!");
	if (GetAttribute(pchar, "ship.speedburst") == "QARSword")		LogIt("Captain, the Sword of Triton has recharged itself!");
	DeleteAttribute (pchar, "ship.speedburst");
}

int GetCursedCoinCount()
{
	ref loc = &locations[FindLocation("Grotto")];
	int CursedCoins = 882;
	if(CheckAttribute(loc, "box1.items.cursedcoin"))
		CursedCoins = CursedCoins - sti(loc.box1.items.cursedcoin);
	if(CursedCoins<0)	CursedCoins = 0;
	return CursedCoins;
}

void CheckCharacterCurse(ref chr)
{
	float x,y,z;
	bool UnCurse = false;
	bool DoCurse = false;
	if(!CheckAttribute(chr, "location")) return;
	ref lcn = &Locations[FindLocation(chr.location)];

	DoCurse = Whr_IsNight() && GetAttribute(lcn, "environment.weather") == "true";
	if(DoCurse && GetAttribute(lcn, "environment.curse") == "false")
	{
		DoCurse = false;
	}

	if(CheckCharacterItem(chr,"cursedcoin") && GetCursedCoinCount()>0)
	{
		if(!CheckAttribute(chr, "model.old"))
		{
			if(DoCurse)
			{
				chr.model.old = chr.model;
				if(!CheckAttribute(chr, "model.cursed"))
					chr.model.cursed = GetCharacterCursedModel(chr);
				SetModelFromID(chr, chr.model.cursed);
				ChangeHPBonus(chr, 300);
			}
		}
		else
		{
			if(!DoCurse)
			{
				UnCurse = true;
			}
		}
	}
	else
	{
		UnCurse = true;
	}
	if(CheckAttribute(chr, "model.old") && UnCurse)
	{
		SetModelFromID(chr, chr.model.old);
		DeleteAttribute(chr, "model.old");
		ChangeHPBonus(chr, -300);
	}
}

string GetCharacterCursedModel(ref chr)
{
	ref pchar = GetMainCharacter();
	if(HasSubStr(chr.model, "sparrow"))				return "47_Jack_Skel";
	if(HasSubStr(chr.model, "47_Jack"))				return "47_Jack_Skel";
	if(chr.model == "Jack")							return "47_Jack_Skel";
	if(chr.model == "depp")							return "47_Jack_Skel";
	if(chr.model == "JGod")							return "47_Jack_Skel";
	if(chr.model == "47YoungJack")					return "47_Jack_Skel";
	if(chr.model == "Bmunk")						return chr.model;
	if(chr.model == "Skel1")						return chr.model;
	if(chr.model == "Skel2")						return chr.model;
	if(chr.model == "Skel3")						return chr.model;
	if(chr.model == "Skel4")						return chr.model;
	if(chr.model == "Skelt")						return chr.model;
	if(chr.model == "DavyJones")					return chr.model;
	if(chr.model == "davy1")						return chr.model;
	if(chr.model == "davy2")						return chr.model;
	if(chr.model == "davy3")						return chr.model;
	if(chr.model == "davy4")						return chr.model;
	if(chr.model == "davy5")						return chr.model;
	if(chr.model == "Vanderdecken")					return chr.model;
	if(chr.model == "Orellana")						return "Skelt";
	if(IsMainCharacter(chr))						return "Bmunk";
	if(chr.index == GetOfficersIndex(Pchar, 1))		return "Skel2";
	if(chr.index == GetOfficersIndex(Pchar, 2))		return "Skel3";
	if(chr.index == GetOfficersIndex(Pchar, 3))		return "Skel1";
	return "Skel"+makeint(1+rand(3));
}

string GetCharacterCursedSails(ref chr)
{
	ref pchar = GetMainCharacter();
	string tempstring = "";
	string CursedSails = "";

	int st = GetCharacterShipType(chr);
	ref shref = GetShipByType(st);

	if(CheckAttribute(chr, "EmblemedSails.nationFileName"))
	{
		tempstring = chr.EmblemedSails.nationFileName;
	}
	else
	{
		if (CheckAttribute(shref, "EmblemedSails.nationFileName"))
		{
			tempstring = shref.EmblemedSails.nationFileName;
		}
		else
		{
			if(IsCompanion(chr) && CheckAttribute(pchar, "EmblemedSails.nationFileName"))
			{
				tempstring = pchar.EmblemedSails.nationFileName;
			}
		}
	}

	if(HasSubStr(tempstring, "red"))			CursedSails = "sail_torn_red_plain.tga";
	if(HasSubStr(tempstring, "black"))			CursedSails = "sail_torn_black_plain.tga";
	if(HasSubStr(tempstring, "tan"))			CursedSails = "sail_torn_tan_plain.tga";
	if(HasSubStr(tempstring, "weathered"))			CursedSails = "sail_torn_weathered_plain.tga";
	if(HasSubStr(tempstring, "patch"))			CursedSails = "sail_BlackPearl_torn.tga";	// Black Pearl - Gets cursed sails
	if(HasSubStr(tempstring, "BlackPearl"))			CursedSails = "sail_BlackPearl_torn.tga";	// Black Pearl - Keeps her own sails
	if(HasSubStr(tempstring, "dutchman"))			CursedSails = "sail_dutchman2.tga";		// Cursed Flying Dutchman keeps her own sails, uncursed Dutchman gets cursed Dutchman sails
	if(HasSubStr(tempstring, "Empress"))			CursedSails = "sail_torn_red_plain.tga";	// Empress - Torn red sails
	if(HasSubStr(tempstring, "Empres2"))			CursedSails = "sail_torn_red_plain.tga";	// Empress - Torn red sails
	if(HasSubStr(tempstring, "qar"))			CursedSails = "sail_torn_red_qar.tga";		// Queen Anne's Revenge - Keeps her own sails
	if(HasSubStr(tempstring, "mariana"))			CursedSails = "sail_mariana.tga";			// Mariana - Keeps her own sails
	if(HasSubStr(tempstring, "sws_christian_maria"))	CursedSails = "sws_christian_maria_torn.tga";	// Torn versions of special sails
	if(HasSubStr(tempstring, "castile_leon"))		CursedSails = "sail_castile_leon_torn.tga";
	if(HasSubStr(tempstring, "holy_roman_empire"))		CursedSails = "sail_holy_roman_empire_torn.tga";
	if(HasSubStr(tempstring, "DeathVessel_whole"))		CursedSails = "sail_DeathVessel_torn.tga";
	if(HasSubStr(tempstring, "DeathVessel_whole1"))		CursedSails = "sail_DeathVessel_torn1.tga";
	if(HasSubStr(tempstring, "Black_Red"))			CursedSails = "sail_Black_Red_torn.tga";
	if(HasSubStr(tempstring, "Diamond"))			CursedSails = "sail_Diamond_torn.tga";
	if(HasSubStr(tempstring, "Experto"))			CursedSails = "sail_Experto_torn.tga";
	if(HasSubStr(tempstring, "Experto1"))			CursedSails = "sail_Experto_torn1.tga";
	if(HasSubStr(tempstring, "Explorer"))			CursedSails = "sail_Explorer_torn.tga";
	if(HasSubStr(tempstring, "Explorer1"))			CursedSails = "sail_Explorer_torn1.tga";
	if(HasSubStr(tempstring, "Gilded"))			CursedSails = "sail_Gilded_torn.tga";
	if(HasSubStr(tempstring, "Gilded_plain"))		CursedSails = "sail_torn_Gilded_plain.tga";
	if(HasSubStr(tempstring, "Navigator"))			CursedSails = "sail_Navigator_torn.tga";
	if(HasSubStr(tempstring, "Navigator1"))			CursedSails = "sail_Navigator_torn1.tga";
	if(HasSubStr(tempstring, "Officer"))			CursedSails = "sail_Officer_torn.tga";
	if(HasSubStr(tempstring, "Officer1"))			CursedSails = "sail_Officer_torn1.tga";
	if(HasSubStr(tempstring, "Red_Striped"))		CursedSails = "sail_Red_Striped_torn.tga";
	if(HasSubStr(tempstring, "Templar"))			CursedSails = "sail_Templar_torn.tga";
	if(HasSubStr(tempstring, "Templar1"))			CursedSails = "sail_Templar_torn1.tga";
	if(HasSubStr(tempstring, "petros"))			CursedSails = "sail_torn_red_plain.tga";
	if(HasSubStr(tempstring, "petros_plain"))		CursedSails = "sail_torn_petros_plain.tga";
	if(HasSubStr(tempstring, "petros_black_red"))		CursedSails = "sail_torn_petros_black_red.tga";
	if(HasSubStr(tempstring, "petros_blue_white"))		CursedSails = "sail_torn_petros_blue_white.tga";
	if(HasSubStr(tempstring, "barbarossa"))			CursedSails = "sail_torn_barbarossa_plain.tga";
	if(CursedSails == "")
		CursedSails = "sail_torn_white_plain.tga";

	return CursedSails;
}

void StackSteam(aref rCharacter, int puffs_per_second)
// Character and number of tentacles
{
	if (!bSeaActive) return;
	bool PlayEngineSound = false;
	int delay = 0;

	// Particle Effects
	for (int i=0; i < puffs_per_second; i++)
	{
		PostEvent("CreateStackSteam", delay, "i", rCharacter);
		delay = delay + 1000/puffs_per_second;
	}

	if(IsMainCharacter(rCharacter) && abs(sti(GetAttribute(rCharacter,"Ship.Power"))) > 0)
	{
		// Sound
		if(!CheckAttribute(rCharacter,"Ship.PlayedEngineSound"))
		{
			rCharacter.Ship.PlayedEngineSound = GetSeaTime();
			PlayEngineSound = true;
		}
		if(GetSeaTime() >= sti(rCharacter.Ship.PlayedEngineSound) + sti(rCharacter.basetime)) PlayEngineSound = true;

		if(PlayEngineSound)
		{
			int SoundID;
			SoundID = PlayStereoSound("objects\engine.wav");
			float volume;
			volume = 0.1 + 0.9*abs(stf(GetAttribute(rCharacter,"Ship.Power")))/100;
			SendMessage(Sound,"llf",MSG_SOUND_SET_VOLUME, SoundID, volume);
			rCharacter.Ship.PlayedEngineSound = GetSeaTime();
		}

		// Fuel Consumption
		if(!CheckAttribute(rCharacter,"Ship.FuelConsumption"))	rCharacter.Ship.FuelConsumption = 0;
		else	rCharacter.Ship.FuelConsumption = stf(rCharacter.Ship.FuelConsumption) + abs(stf(GetAttribute(rCharacter,"Ship.Power")))/100;
		if(stf(rCharacter.Ship.FuelConsumption) >= 195)
		{
			RemoveCharacterGoods(rCharacter,GOOD_PLANKS,1);
			rCharacter.Ship.FuelConsumption = 0;
		}
	}
}

#event_handler("CreateStackSteam", "StackSteamPuff");
void StackSteamPuff()
{
	if (!bSeaActive || bAbordageStarted) return;
	aref rCharacter = GetEventData();

	float fX, fY, fZ, fAY;
	fX = 0; fY = 0; fZ = 0;
	if(CheckAttribute(rCharacter,"Ship.pos.x")) fX=stf(rCharacter.Ship.pos.x);
		else return;
	if(CheckAttribute(rCharacter,"Ship.pos.y")) fY=stf(rCharacter.Ship.pos.y);
		else return;
	if(CheckAttribute(rCharacter,"Ship.pos.z")) fZ=stf(rCharacter.Ship.pos.z);
		else return;
	if(CheckAttribute(rCharacter,"Ship.Ang.y")) fAY=stf(rCharacter.Ship.Ang.y);
		else return;

	float gX, gY, gZ;
	gX = 0; gY = 0; gZ = 0;
	gX=GetCharacterShipValue(rCharacter, "stack1X");
	gY=GetCharacterShipValue(rCharacter, "stack1Y");
	float comp = 0.75 * sti(rCharacter.Ship.Speed.z);
	gZ=GetCharacterShipValue(rCharacter, "stack1Z") + comp; // PB: Not a proper fix, but appears better at speed
	CreateParticleSystemX("steamer_smoke",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), Whr_GetWindSpeed()*sin(Whr_GetWindAngle()), 10*Degree2Radian(90.0), Whr_GetWindSpeed()*cos(Whr_GetWindAngle()), 0);

	if(HasCharacterShipAttribute(rCharacter, "stack2X") || HasCharacterShipAttribute(rCharacter, "stack2Y") || HasCharacterShipAttribute(rCharacter, "stack2Z"))
	{
		gX = 0; gY = 0; gZ = 0;
		gX=GetCharacterShipValue(rCharacter, "stack2X");
		gY=GetCharacterShipValue(rCharacter, "stack2Y");
		gZ=GetCharacterShipValue(rCharacter, "stack2Z") + comp; // PB: Not a proper fix, but appears better at speed
		CreateParticleSystemX("steamer_smoke2",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), Whr_GetWindSpeed()*sin(Whr_GetWindAngle()), 10*Degree2Radian(90.0), Whr_GetWindSpeed()*cos(Whr_GetWindAngle()), 0);
	}

	if(abs(sti(GetAttribute(rCharacter,"Ship.Power"))) > 0)
	{
		if(sti(GetAttribute(rCharacter,"Ship.Power")) < 0)
		{
			fAY = fAY + PI;
		}
		if(HasCharacterShipAttribute(rCharacter, "prop1X") || HasCharacterShipAttribute(rCharacter, "prop1Y") || HasCharacterShipAttribute(rCharacter, "prop1Z"))
		{
			gX = 0; gY = 0; gZ = 0;
			gX=GetCharacterShipValue(rCharacter, "prop1X");
			gY=GetCharacterShipValue(rCharacter, "prop1Y");
			gZ=GetCharacterShipValue(rCharacter, "prop1Z");
			CreateParticleSystemX("steamer_wake",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), sin(fAY), 0.0, cos(fAY), 0);
		}

		if(HasCharacterShipAttribute(rCharacter, "prop2X") || HasCharacterShipAttribute(rCharacter, "prop2Y") || HasCharacterShipAttribute(rCharacter, "prop2Z"))
		{
			gX = 0; gY = 0; gZ = 0;
			gX=GetCharacterShipValue(rCharacter, "prop2X");
			gY=GetCharacterShipValue(rCharacter, "prop2Y");
			gZ=GetCharacterShipValue(rCharacter, "prop2Z");
			CreateParticleSystemX("steamer_wake",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), sin(fAY), 0.0, cos(fAY), 0);
		}
	}
// PB: Testing -->
/*
	gX = -3; gY = 12; gZ = -23;
	CreateParticleSystemX("stern_light",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), sin(fAY), 0.0, cos(fAY), 0);
	gX = 3; gY = 12; gZ = -23;
	CreateParticleSystemX("stern_light",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), sin(fAY), 0.0, cos(fAY), 0);
	gX = 0; gY = 13; gZ = -23;
	CreateParticleSystemX("stern_light",fX - gX*cos(fAY) + gZ*sin(fAY), fY + gY, fZ + gX*sin(fAY) + gZ*cos(fAY), sin(fAY), 0.0, cos(fAY), 0);
*/
// PB: Testing <--
}

void UpdateShipPower()
{
	ref rCharacter = GetMainCharacter();
	string sshippower = "";
	IShipPower.Log.color = COLOR_NORMAL;
	if(SteamShip(rCharacter))
	{
		switch(abs(sti(GetAttribute(rCharacter,"Ship.Power"))))
		{
			case  100:	sshippower = "Engines: Full";
				IShipPower.Log.color = COLOR_GREEN;
				if(sti(GetAttribute(rCharacter,"Ship.Power")) < 0)
					IShipPower.Log.color = COLOR_RED;
			break;
			case   75:	sshippower = "Engines: Half";
				IShipPower.Log.color = COLOR_GREEN_LIGHT;
				if(sti(GetAttribute(rCharacter,"Ship.Power")) < 0)
					IShipPower.Log.color = COLOR_RED_LIGHT;
			break;
			case   50:	sshippower = "Engines: Slow";
				IShipPower.Log.color = COLOR_YELLOW;
			break;
			case   25:	sshippower = "Engines: Dead Slow";
				IShipPower.Log.color = COLOR_YELLOW_LIGHT;
			break;
			case    0:	sshippower = "Engines: ALL STOP";
				IShipPower.Log.color = COLOR_NORMAL;
			break;
		}
		if(sti(GetAttribute(rCharacter,"Ship.Power")) > 0)
			sshippower = sshippower + " Ahead";
		if(sti(GetAttribute(rCharacter,"Ship.Power")) < 0)
			sshippower = sshippower + " Astern";
		if(GetCargoGoods(rCharacter, GOOD_PLANKS) < 1)
		{
			sshippower = "Engines: NO FUEL";
			IShipPower.Log.color = COLOR_BLUE;
		}
	}
	SendMessage(&IShipPower, "lll", LOG_AND_ACTIONS_INIT, false, true);
	SendMessage(&IShipPower, "lls", LOG_ADD_STRING, true, sshippower);
}

// Capsizing -->
#define ROLL_ANGLE_WARNING 11 // Armada: For testing purposes, you can decrease any of the values on the left
#define ROLL_ANGLE_MORALE  12 // to make the various events occur more easily.
#define ROLL_ANGLE_GOODS   13
#define ROLL_ANGLE_DAMAGE  14
#define ROLL_ANGLE_CAPSIZE 15

void UpdateShipRoll()
{
	ref rCharacter = GetMainCharacter();
	if(Whr_IsStorm() && CheckAttribute(rCharacter,"Capsize") && GetCharacterShipClass(rCharacter) < 8)
	{
		int RollDamageValue;
		int i;
		string sshiproll;
		float fX = stf(rCharacter.Ship.pos.x);
		float fY = stf(rCharacter.Ship.pos.y);
		float fZ = stf(rCharacter.Ship.pos.z);
		float RollAngle = makeint(-Radian2Degree(stf(GetAttribute(rCharacter, "ship.ang.z"))));
		if(RollAngle < -180) RollAngle = RollAngle + 360;

		if(RollAngle > 0 )	sshiproll = "Roll angle is " + abs(makeint(RollAngle)) + " degrees to starboard";
		else				sshiproll = "Roll angle is " + abs(makeint(RollAngle)) + " degrees to port";
		if(RollAngle == 0)	sshiproll = "Roll angle is " + abs(makeint(RollAngle)) + " degrees";

		switch(sti(GetAttribute(rCharacter, "Capsize.Warning")))
		{
			case ROLL_ANGLE_WARNING: // First Warning
				IShipRoll.Log.color = COLOR_NORMAL;
				if(abs(RollAngle) >  ROLL_ANGLE_WARNING) IShipRoll.Log.color = COLOR_GREEN_LIGHT;
				if(abs(RollAngle) >  ROLL_ANGLE_MORALE ) IShipRoll.Log.color = COLOR_GREEN;
				if(abs(RollAngle) >  ROLL_ANGLE_GOODS  ) IShipRoll.Log.color = COLOR_YELLOW;
				if(abs(RollAngle) >  ROLL_ANGLE_DAMAGE ) IShipRoll.Log.color = COLOR_RED_LIGHT;
				if(abs(RollAngle) >  ROLL_ANGLE_CAPSIZE) IShipRoll.Log.color = COLOR_RED;
				if(GetSeaTime() > 10 && abs(RollAngle) > ROLL_ANGLE_WARNING)
				{
					LogIt("Captain, we have to put our bow to the waves to decrease the rolling movement of the ship");

					rCharacter.Capsize.Warning  = ROLL_ANGLE_MORALE;
					rCharacter.Capsize.Time = GetSeaTime();
				}
			break;

			case ROLL_ANGLE_MORALE: // Second Warning
				IShipRoll.Log.color = COLOR_GREEN_LIGHT;
				if(abs(RollAngle) >  ROLL_ANGLE_MORALE ) IShipRoll.Log.color = COLOR_GREEN;
				if(abs(RollAngle) >  ROLL_ANGLE_GOODS  ) IShipRoll.Log.color = COLOR_YELLOW;
				if(abs(RollAngle) >  ROLL_ANGLE_DAMAGE ) IShipRoll.Log.color = COLOR_RED_LIGHT;
				if(abs(RollAngle) >  ROLL_ANGLE_CAPSIZE) IShipRoll.Log.color = COLOR_RED;
				if(GetSeaTime() - sti(rCharacter.Capsize.Time) > 10 && abs(RollAngle) > ROLL_ANGLE_MORALE)
				{
					RollDamageValue = sti(rCharacter.Ship.Crew.Morale) - 10;
					LogIt("Captain, the morale of the crew decreased from " + XI_ConvertString(GetMoraleName(rCharacter.Ship.Crew.Morale)) + " to " + XI_ConvertString(GetMoraleName(RollDamageValue)) + " because the ship's rolling is making them seasick");
					rCharacter.Ship.Crew.Morale = RollDamageValue; // Decrease morale one level
					if (sti(rCharacter.Ship.Crew.morale)<MORALE_MIN) rCharacter.Ship.Crew.morale=MORALE_MIN;

					rCharacter.Capsize.Warning  = ROLL_ANGLE_GOODS;
					rCharacter.Capsize.Time = GetSeaTime();
				}
			break;

			case ROLL_ANGLE_GOODS: // Third Warning
				IShipRoll.Log.color = COLOR_GREEN;
				if(abs(RollAngle) >  ROLL_ANGLE_GOODS  ) IShipRoll.Log.color = COLOR_YELLOW;
				if(abs(RollAngle) >  ROLL_ANGLE_DAMAGE ) IShipRoll.Log.color = COLOR_RED_LIGHT;
				if(abs(RollAngle) >  ROLL_ANGLE_CAPSIZE) IShipRoll.Log.color = COLOR_RED;
				if(GetSeaTime() - sti(rCharacter.Capsize.Time) > 10 && abs(RollAngle) > ROLL_ANGLE_GOODS)
				{
					for(i=GOODS_QUANTITY-1;i>=0;i--)
					{
						if(GetCargoGoods(rCharacter, i) <= 0) continue; // Don't dump cargo that isn't in the hold
						if (CheckQuestAttribute("generate_trade_quest_progress", "begin")) // Only during an ACTIVE trade quest
						{
							if ( i == sti(rCharacter.quest.generate_trade_quest_progress.iTradeGoods) ) continue; // Don't dump quest cargo (not realistic, but less frustrating)
						}
						break;
					}
					if(GetCargoGoods(rCharacter, i) > 0)
					{
						RollDamageValue = 1 + makeint(0.1*GetCargoGoods(rCharacter, i));
						LogIt("Captain, the cargo has started shifting due to the rolling and " + RollDamageValue + " " + Goods[i].Name + " went overboard");
						RemoveCharacterGoods(rCharacter, i, RollDamageValue);
					}
					else // The cargo hold is empty
					{
						RollDamageValue = makeint(0.1*GetCrewQuantity(rCharacter));
						LogIt("*" + RollDamageValue + " crewmembers are heard yelling from inside the empty cargo hold*");
						RemoveCharacterCrew(rCharacter, RollDamageValue); // 10% crew damage
					}
					PlaySound("objects\abordage\abordage_loosing.wav"); // Armada: crew shout out
					rCharacter.Capsize.Warning  = ROLL_ANGLE_DAMAGE;
					rCharacter.Capsize.Time = GetSeaTime();
				}
			break;

			case ROLL_ANGLE_DAMAGE: // Fourth Warning
				IShipRoll.Log.color = COLOR_YELLOW;
				if(abs(RollAngle) >  ROLL_ANGLE_DAMAGE ) IShipRoll.Log.color = COLOR_RED_LIGHT;
				if(abs(RollAngle) >  ROLL_ANGLE_CAPSIZE) IShipRoll.Log.color = COLOR_RED;
				if(GetSeaTime() - sti(rCharacter.Capsize.Time) > 10 && abs(RollAngle) > ROLL_ANGLE_DAMAGE)
				{
					switch(rand(1))
					{
						case 0:
							RollDamageValue = makeint(0.1*sti(rCharacter.Ship.HP));
							PlaySound("objects\abordage\abordage_loosing.wav"); // Armada: crew shout out
							PlaySound("objects\shipcharge\ship_explosion.wav")
							CreateParticleSystemX("gunfire",    fX+4-rand(8), fY+4-rand(8), fZ+4-rand(8), 6.0, 4.0, 0.0, 0); // Armada: not yet working
							LogIt("Captain, shifting cargo did " + RollDamageValue + " damage to the hull");
							Ship_ApplyHullHitpoints(rCharacter, RollDamageValue, KILL_BY_TOUCH, -1); // 10% hull damage
						break;

						case 1:
							RollDamageValue = makeint(0.1*GetCrewQuantity(rCharacter));
							PlaySound("objects\abordage\abordage_loosing.wav"); // Armada: crew shout out
							for(i=0;i<RollDamageValue;i++)
							{
								if(rand(1) == 0)	CreateParticleSystem("flyers",      fX+4-rand(8), fY+4-rand(8), fZ+4-rand(8), 0.0, 0.0, 0.0, 0);
								else				CreateParticleSystem("flyers2",     fX+4-rand(8), fY+4-rand(8), fZ+4-rand(8), 0.0, 0.0, 0.0, 0);
							}
							AISeaGoods.ModelsPath = "LowCharacters";   //path to the crewmodels
							switch(rand(4)) // Put a crewmember in the sea behind the ship
							{
								case 0:
									Direct_AddGood(rCharacter, "Oil", "Lo_Man",  100.0, RollDamageValue, 800, Degree2Radian(180.0));
								break;
								case 1:
									Direct_AddGood(rCharacter, "Oil", "Lo_Man2", 100.0, RollDamageValue, 800, Degree2Radian(180.0));
								break;
								case 2:
									Direct_AddGood(rCharacter, "Oil", "Lo_Man3", 100.0, RollDamageValue, 800, Degree2Radian(180.0));
								break;
								case 3:
									Direct_AddGood(rCharacter, "Oil", "Lo_Man4", 100.0, RollDamageValue, 800, Degree2Radian(180.0));
								break;
								case 4:
									Direct_AddGood(rCharacter, "Oil", "Lo_Man5", 100.0, RollDamageValue, 800, Degree2Radian(180.0));
								break;
							}
							AISeaGoods.ModelsPath = "SwimGoods";   //reset path to the salvagemodels
							LogIt("Captain, that last violent roll washed " + RollDamageValue + " crewmembers overboard");
							RemoveCharacterCrew(rCharacter, RollDamageValue); // 10% crew damage
						break;
					}
					rCharacter.Capsize.Warning  = ROLL_ANGLE_CAPSIZE;
					rCharacter.Capsize.Time = GetSeaTime();
				}
			break;

			case ROLL_ANGLE_CAPSIZE: // Fifth Warning
				IShipRoll.Log.color = COLOR_RED_LIGHT;
				if(abs(RollAngle) >  ROLL_ANGLE_CAPSIZE) IShipRoll.Log.color = COLOR_RED;
				if(GetSeaTime() - sti(rCharacter.Capsize.Time) > 10 && abs(RollAngle) > ROLL_ANGLE_CAPSIZE)
				{
					if(RollAngle > 0)	LogIt("Captain, we're capsizing to starboard... ABANDON SHIP!");
					else				LogIt("Captain, we're capsizing to port... ABANDON SHIP!");
					CapsizeShip(rCharacter);
				}
			break;
		}
		SendMessage(&IShipRoll, "lll", LOG_AND_ACTIONS_INIT, false, true);
	}
	else sshiproll = "";
	SendMessage(&IShipRoll, "lls", LOG_ADD_STRING, true, sshiproll);
}

#event_handler("DoCapsize", "CheckCapsize");
void CheckCapsize()
{
	if (!bSeaActive || bAbordageStarted) return;
	aref rCharacter = GetEventData();

	DeleteAttribute(rCharacter, "Ship.Unstable");
	rCharacter.Ship.Capsize = true;
	RecalculateCargoLoad(rCharacter);
}

void CapsizeShip(ref rCharacter)
{
	if (!bSeaActive || bAbordageStarted) return;

	float RollAngle = makeint(-Radian2Degree(stf(GetAttribute(rCharacter, "ship.ang.z"))));
	if(RollAngle < -180) RollAngle = RollAngle + 360;

	PlaySound("objects\shipcharge\_Abandon0.wav");
	PlaySound("objects\abordage\abordage_loosing.wav");
	Playsound("objects\shipcharge\mast_fall3.wav"); // Armada: ship capsizing- uses mast falling sound
	rCharacter.Capsize.Angle = RollAngle;
	ShipDead(sti(rCharacter.Index), KILL_BY_OWNER, sti(rCharacter.Index));
}
// Capsizing <--

bool AllowUnlimitedLoot()
{
	ref PChar = GetMainCharacter();
	if (ProfessionalNavyNation() != UNKNOWN_NATION)	return true;	// LDH add test for navy character if available - 16Apr09
	if (CheckAttribute(PChar, "isnotcaptain"))		return true;	// Crew doesn't mind, because you're not the captain anyway
	if (GetServedNation() == PIRATE)				return false;	// Pirates will always be envious of captains with a lot of money
	if (HasMerchantPassport(PChar))					return true;	// Always OK if you have documents indicating you are an honest merchant
	return GetLetterOfMarqueQuantity() == 0;						// Crew is OK with your money as long as you're not a privateer
}

string GetRandomQuestShipLocator(string islandstr)
{
	int quest_locators = 0;
	switch(islandstr)
	{
	//	case "Antigua":					quest_locators = 15;	break;
		case "Aruba":					quest_locators =  8;	break;
		case "Colombia":				quest_locators = 10;	break;
	//	case "Cayman":					quest_locators = 15;	break;
	//	case "Conceicao":				quest_locators = 15;	break;
	//	case "Cuba":					quest_locators = 15;	break;
		case "Curacao":					quest_locators =  8;	break;
		case "Douwesen":				quest_locators = 12;	break;
		case "Eleuthera":				quest_locators = 10;	break;
		case "FalaiseDeFleur":			quest_locators = 22;	break;
	//	case "Hispaniola":				quest_locators = 15;	break;
	//	case "Guadeloupe":				quest_locators = 15;	break;
		case "IslaDeMuerte":			quest_locators =  7;	break;
		case "IslaMona":				quest_locators =  7;	break;
	//	case "IslaMuelle":				quest_locators = 15;	break;
		case "KhaelRoa":				quest_locators =  8;	break;
		case "Oxbay":					quest_locators = 27;	break;
		case "QuebradasCostillas":		quest_locators = 11;	break;
		case "Redmond":					quest_locators = 26;	break;
	//	case "SaintMartin":				quest_locators = 15;	break;
	//	case "Turks":					quest_locators = 15;	break;
	//	case "Battle_Rocks":			quest_locators = 15;	break;
		case "Colombia":				quest_locators = 10;	break;
		quest_locators = 15;
	}
	return "Quest_Ship_"  + (1 + rand(quest_locators-1));			//random position
}

int GetSmugglingNation()
{
	ref Pchar = GetMainCharacter();
	ref island = GetIslandByIndex(GetCharacterCurrentIsland(Pchar));
	return sti(island.smuggling_nation);
}

void ReloadToTexturedModel(string model, string texture)
{
	string locid = "";
	ref loc;
	for(int i = 0; i < nLocationsNum; i++)
	{
		loc = &Locations[i];
		if(!CheckAttribute(loc, "filespath.models")) continue;
		if(texture == "")
		{
			if(CheckAttribute(loc, "filespath.textures")) continue;
			if(loc.filespath.models == "locations\" + model)
			{
				locid = loc.id;
				break;
			}
		}
		else
		{
			if(!CheckAttribute(loc, "filespath.textures")) continue;
			if(loc.filespath.models == "locations\" + model && loc.filespath.textures == "locations\" + texture)
			{
				locid = loc.id;
				break;
			}
		}
	}
	if(texture == "") texture = "DEFAULT";
	if(locid != "")
	{
		DoQuestReloadToLocation(locid, "reload", loc.reload.l1.name, "_");
		if(loc.type == "port" || loc.type == "seashore") SetCharacterShipLocation(GetMainCharacter(), locid);
	}
	else LogIt("No location with model folder = " + model + " and texture folder = " + texture);
}

void CycleThroughTexturedModels(string model)
{
	ref pchar = GetMainCharacter();
	if(!CheckAttribute(pchar, "modeltexturefolder")) pchar.modeltexturefolder = "";
	ReloadToTexturedModel(model, pchar.modeltexturefolder);
	switch(pchar.modeltexturefolder)
	{
		case "":			pchar.modeltexturefolder = "decks";		break;
		case "decks":		pchar.modeltexturefolder = "ENGLAND";	break;
		case "ENGLAND":		pchar.modeltexturefolder = "FRANCE";	break;
		case "FRANCE":		pchar.modeltexturefolder = "HOLLAND";	break;
		case "HOLLAND":		pchar.modeltexturefolder = "NATIVES";	break;
		case "NATIVES":		pchar.modeltexturefolder = "SPAIN";		break;
		case "SPAIN":		pchar.modeltexturefolder = "AMERICA";	break;
		case "AMERICA":		pchar.modeltexturefolder = "";			break;
	}
}

bool IsBrothelEnabled()
{
	if(ENABLE_BROTHEL)														return true;
	if(sti(GetStorylineVar(FindCurrentStoryline(), "ENABLE_BROTHEL")) > 0)	return true;
	return false;
}

// stljeffbb Jan 15 2012 -->
void InitOpenSeaMod()
{
	ref PChar = GetMainCharacter();
	if(iRealismMode>1 || OPEN_SEA_MOD)
	{
		DIRECTENCOUNTERCHANCE =								25;		// chance in percent that an encounter fleet appears every hour
		DIRECTENCOUNTERDISTANCE =							2250;	// distance from player at which random ships appear 
		ENCOUNTERBREAK =									3.0;	// LDH - Changed to float, number is hours per encounter, directsail is called every 5 minutes occasionally
		// so you can let the clock run faster (by increasing TIMESCALAR_SEA below), meaning longer voyagetimes, without getting too many encounters.

		TIMESCALAR_SEA =									15;		// INT - how many seconds of gametime one second of realtime is at sea
		MAX_WBALLAST =										10;		// INT - how far the weighting will swing in favor of current trend.. use positive integer between 0 and 50 - 0 is no swing - 50 is major swing.. this is for Windspeed
		MAX_RBALLAST =										10;		// ^^DITTO for rain
		MAX_FBALLAST =										10;		// ^^DITTO for fog
		MAX_ABALLAST =										10.0;	// FLOAT - ^^DITTO for wind angle

		MAX_WINDCHANGE =									 3;		// INT - How much the wind CAN change in one hour - use positive integer between 0 and 20
		MAX_FOGCHANGE =										 3;		// INT - ^^DITTO for fog
		MAX_RAINCHANGE =									 3;		// INT - ^^DITTO for rain

		COASTRAIDER_CHANCE = 								0.01;	// FLOAT - Generates local ships in ports and around the islands. Some are local merchants, others pirates.
																	// 0.0 : Stock PotC, no local ships at all
																	// 0.1 - 0.9 : The higher that value the more pirates instead of merchants appear
		NAVYRAIDER_CHANCE = 								2.0; 	// FLOAT - Ditto, but chance that raider is a foreign warship. Chance for that is coastraider_chance * navyraider_chance
		MIN_ENEMY_DISTANCE_TO_DISABLE_MAP_ENTER =			100.0;	// FLOAT - original value is 500 - Petros: reset to 500.0 to prevent trouble
		MIN_ENEMY_DISTANCE_TO_DISABLE_ENTER_2_LOCATION =	100.0;	// FLOAT - original value is 500
		RANGE_TO_ENEMY =									3500;	// INT - in feet/yards/whatever unit the game uses.

		WDM_MAP_TO_SEA_SCALE =								60;		// orig 19.607843 for this and next line
		WDM_MAP_TO_SEA_ENCOUNTERS_SCALE =					60;		// was 60 in build, 10.0 in stock. NK 05-04-30
	}
	else
	{
		DIRECTENCOUNTERCHANCE =								50;		// chance in percent that an encounter fleet appears every hour
		DIRECTENCOUNTERDISTANCE =							1000;	// distance from player at which random ships appear 
		ENCOUNTERBREAK =									1.0;	// LDH - Changed to float, number is hours per encounter, directsail is called every 5 minutes occasionally
		// so you can let the clock run faster (by increasing TIMESCALAR_SEA below), meaning longer voyagetimes, without getting too many encounters.

		TIMESCALAR_SEA =									 5;		// INT - how many seconds of gametime one second of realtime is at sea
		MAX_WBALLAST =										25;		// INT - how far the weighting will swing in favor of current trend.. use positive integer between 0 and 50 - 0 is no swing - 50 is major swing.. this is for Windspeed
		MAX_RBALLAST =										25;		// ^^DITTO for rain
		MAX_FBALLAST =										25;		// ^^DITTO for fog
		MAX_ABALLAST =										25.0;	// FLOAT - ^^DITTO for wind angle

		MAX_WINDCHANGE =									5;		// INT - How much the wind CAN change in one hour - use positive integer between 0 and 20
		MAX_FOGCHANGE =										5;		// INT - ^^DITTO for fog
		MAX_RAINCHANGE =									5;		// INT - ^^DITTO for rain

		COASTRAIDER_CHANCE = 								0.2;	// FLOAT - Generates local ships in ports and around the islands. Some are local merchants, others pirates.
																	// 0.0 : Stock PotC, no local ships at all
																	// 0.1 - 0.9 : The higher that value the more pirates instead of merchants appear
		NAVYRAIDER_CHANCE = 								0.4; 	// FLOAT - Ditto, but chance that raider is a foreign warship. Chance for that is coastraider_chance * navyraider_chance
		MIN_ENEMY_DISTANCE_TO_DISABLE_MAP_ENTER =			500.0;	// FLOAT - original value is 500 - Petros: reset to 500.0 to prevent trouble
		MIN_ENEMY_DISTANCE_TO_DISABLE_ENTER_2_LOCATION =	500.0;	// FLOAT - original value is 500
		RANGE_TO_ENEMY =									3000;	// INT - in feet/yards/whatever unit the game uses.

		WDM_MAP_TO_SEA_SCALE =							19.607843;	// orig 19.607843 for this and next line
		WDM_MAP_TO_SEA_ENCOUNTERS_SCALE =				19.607843;	// was 60 in build, 10.0 in stock. NK 05-04-30
	}
}
// stljeffbb Jan 15 2012 <--

// ----------------
// PB FUNCTIONS <--
// ----------------

// sets wind to 30kts
void Wind_Cheat()
{
	Weather.Wind.Speed = 30.0;
	fWeatherSpeed = 30.0;
}

// sets up lvl12 characters with skills, perks, and items as I like. Allows types "player", qm, nav, can, and capnavy.
void SetUpChar_Cheat(ref ch, string otype)
{
	string stmp;

	switch(otype)
	{
		case "player":
			ch.skill.freeskill = 0;
			ch.skill.leadership = 8;
			ch.skill.fencing = 9;
			ch.skill.sailing = 4;
			ch.skill.accuracy = 1;
			ch.skill.cannons = 1;
			ch.skill.grappling = 1;
			ch.skill.repair = 1;
			ch.skill.defence = 1;
			ch.skill.commerce = 1;
			ch.skill.sneak = 7;
			ch.items.bladex4 = 1;
			ch.items.blade1 = 1;
			ch.items.potion1 = 22;
			if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY) ch.items.pistol1 = 1;
			else ch.items.pistol1a = 1;
			ch.items.spyglass1 = 1;
			ch.items.commonarmor = 1;
			stmp = "blade19+2";
			ch.items.(stmp) = 1;
			stmp = "pistol8+2";
			ch.items.(stmp) = 1;
			ch.items.spyglass4 = 1;
			ch.items.jewelry2 = 1;
			ch.items.jewelry3 = 1;
			ch.items.jewelry4 = 1;
			ch.items.jewelry10 = 1;
			ch.items.indian5 = 1;
			ch.items.mineral16 = 2;
			ch.items.jewelry8 = 1;
			ch.items.jewelry9 = 1;
			ch.items.indian7 = 1;
			ch.items.mineral3 = 2;
			ch.items.potion2 = 3;
			ch.items.potion3 = 5;
			ch.items.potionrum = 2;
			ch.perks.freepoints = 0;
			ch.perks.list = "";
			ch.perks.list.BasicDefence = 1;
			ch.perks.list.AdvancedDefence = 1;
			ch.perks.list.CriticalHit = 1;
			ch.perks.list.SwordplayProfessional = 1;
			ch.perks.list.Gunman = 1;
			ch.perks.list.SharedExperience = 1;
			ch.perks.list.IronWill = 1;
			ch.perks.list.ShipSpeedUp = 1;
			ch.perks.list.ShipTurnRateUp = 1;
			ch.perks.list.StormProfessional = 1;
			ch.perks.list.Turn180 = 1;
			ch.perks.list.SandbankManeuver = 1;
		break;

		case OFFIC_TYPE_NAVIGATOR:
			ch.skill.freeskill = 0;
			ch.skill.leadership = 1;
			ch.skill.fencing = 7;
			ch.skill.sailing = 7;
			ch.skill.accuracy = 1;
			ch.skill.cannons = 1;
			ch.skill.grappling = 1;
			ch.skill.repair = 1;
			ch.skill.defence = 9;
			ch.skill.commerce = 1;
			ch.skill.sneak = 5;
			ch.items.commonarmor = 1;
			stmp = "blade19+2";
			ch.items.(stmp) = 1;
			stmp = "pistol8+2";
			ch.items.(stmp) = 1;
			ch.items.jewelry3 = 1;
			ch.items.jewelry4 = 1;
			ch.items.indian5 = 1;
			ch.items.mineral3 = 2;
			ch.items.mineral16 = 2;
			ch.items.jewelry8 = 1;
			ch.items.jewelry9 = 1;
			ch.items.indian7 = 1;
			ch.perks.freepoints = 0;
			ch.perks.list = "";
			ch.perks.list.ShipSpeedUp = 1;
			ch.perks.list.ShipTurnRateUp = 1;
			ch.perks.list.StormProfessional = 1;
			ch.perks.list.Turn180 = 1;
			ch.perks.list.SandbankManeuver = 1;
			ch.perks.list.SailingProfessional = 1;
			ch.perks.list.BasicDefence = 1;
			ch.perks.list.AdvancedDefence = 1;
			ch.perks.list.CriticalHit = 1;
			ch.perks.list.SwordplayProfessional = 1;
			ch.perks.list.Gunman = 1;
			ch.perks.list.SharedExperience = 1;
		break;

		case OFFIC_TYPE_QMASTER:
			ch.skill.freeskill = 0;
			ch.skill.leadership = 1;
			ch.skill.fencing = 1;
			ch.skill.sailing = 1;
			ch.skill.accuracy = 1;
			ch.skill.cannons = 1;
			ch.skill.grappling = 8;
			ch.skill.repair = 9;
			ch.skill.defence = 2;
			ch.skill.commerce = 9;
			ch.skill.sneak = 1;
			ch.items.commonarmor = 1;
			stmp = "blade19+2";
			ch.items.(stmp) = 1;
			//stmp = "pistol8+2";
			//ch.items.(stmp) = 1;
			ch.items.jewelry3 = 1;
			ch.items.jewelry8 = 1;
			ch.items.jewelry10 = 1;
			ch.items.indian7 = 1;
			ch.items.mineral3 = 2;
			ch.items.mineral7 = 1;
			ch.items.mineral8 = 1;
			ch.items.jewelry9 = 1;
			ch.perks.freepoints = 0;
			ch.perks.list = "";
			ch.perks.list.LongRangeGrappling = 1;
			ch.perks.list.GrapplingProfessional = 1;
			ch.perks.list.BasicDamageControl = 1;
			ch.perks.list.Rigging = 1;
			ch.perks.list.BasicFirstAid = 1;
			ch.perks.list.LightRepair = 1;
			ch.perks.list.InstantRepair = 1;
			ch.perks.list.Trustworthy = 1;
			ch.perks.list.BasicCommerce = 1;
			ch.perks.list.AdvancedCommerce = 1;
			ch.perks.list.BasicLandOwner = 1;
			ch.perks.list.SharedExperience = 1;
		break;

		case OFFIC_TYPE_CANNONEER:
			ch.skill.freeskill = 0;
			ch.skill.leadership = 1;
			ch.skill.fencing = 7;
			ch.skill.sailing = 1;
			ch.skill.accuracy = 9;
			ch.skill.cannons = 8;
			ch.skill.grappling = 1;
			ch.skill.repair = 1;
			ch.skill.defence = 1;
			ch.skill.commerce = 1;
			ch.skill.sneak = 4;
			ch.items.commonarmor = 1;
			stmp = "blade19+2";
			ch.items.(stmp) = 1;
			stmp = "pistol8+2";
			ch.items.(stmp) = 1;
			ch.items.jewelry3 = 1;
			ch.items.jewelry8 = 1;
			ch.items.jewelry9 = 1;
			ch.items.indian7 = 1;
			ch.items.mineral1 = 3;
			ch.items.mineral15 = 1;
			ch.items.chinatiger = 1;
			ch.perks.freepoints = 0;
			ch.perks.list = "";
			ch.perks.list.FastReload = 1;
			ch.perks.list.HullDamageUp = 1;
			ch.perks.list.SailsDamageUp = 1;
			ch.perks.list.CrewDamageUp = 1;
			ch.perks.list.CriticalShoot = 1;
			ch.perks.list.LongRangeShoot = 1;
			ch.perks.list.CannonProfessional = 1;
			ch.perks.list.BasicDefence = 1;
			ch.perks.list.AdvancedDefence = 1;
			ch.perks.list.CriticalHit = 1;
			ch.perks.list.SwordplayProfessional = 1;
			ch.perks.list.Gunman = 1;
		break;

		case OFFIC_TYPE_CAPNAVY:
			ch.skill.freeskill = 0;
			ch.skill.leadership = 5;
			ch.skill.fencing = 1;
			ch.skill.sailing = 7;
			ch.skill.accuracy = 5;
			ch.skill.cannons = 3;
			ch.skill.grappling = 1;
			ch.skill.repair = 1;
			ch.skill.defence = 9;
			ch.skill.commerce = 1;
			ch.skill.sneak = 1;
			ch.items.commonarmor = 1;
			stmp = "blade19+2";
			ch.items.(stmp) = 1;
			stmp = "pistol8+2";
			ch.items.(stmp) = 1;
			ch.items.jewelry2 = 1;
			ch.items.jewelry3 = 1;
			ch.items.jewelry4 = 1;
			ch.items.jewelry10 = 1;
			ch.items.indian5 = 1;
			ch.items.mineral1 = 3;
			ch.items.mineral7 = 1;
			ch.items.mineral8 = 1;
			ch.items.mineral15 = 1;
			ch.items.mineral16 = 2;
			ch.items.chinatiger = 1;
			ch.items.mineral3 = 2;
			ch.perks.freepoints = 0;
			ch.perks.list = "";
			ch.perks.list.BasicDamageControl = 1;
			ch.perks.list.AdvancedDamageControl = 1;
			ch.perks.list.ProfessionalDamageControl = 1;
			ch.perks.list.Rigging = 1;
			ch.perks.list.RiggingAdvance = 1;
			ch.perks.list.StormProfessional = 1;
			ch.perks.list.SharedExperience = 1;
			ch.perks.list.IronWill = 1;
			ch.perks.list.HullDamageUp = 1;
			ch.perks.list.SailsDamageUp = 1;
			ch.perks.list.CrewDamageUp = 1;
			ch.perks.list.CriticalShoot = 1;
			ch.perks.list.FastReload = 1;
		break;
	}
}

bool ReloadToLocModel(string model)
{
	string locid = "";
	ref loc;
	for(int i = 0; i < nLocationsNum; i++)
	{
		loc = &Locations[i];
		if(!CheckAttribute(loc, "models.always.locators")) continue;
		if(loc.models.always.locators == model)
		{
			locid = loc.id;
			break;
		}
	}
	if(locid != "") return DoQuestReloadToLocation(locid, "reload", loc.reload.l1.name, "_");
	else return false;
}
