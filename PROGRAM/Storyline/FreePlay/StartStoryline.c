void StartStoryLine()
{
	ref PChar, ch;
	PChar = GetMainCharacter();
	ch = CharacterFromID("Malcolm Hatcher");

	bChangeNation = false;// MAXIMUS 7-8-06
	ref TutDeck = &Locations[FindLocation("Tutorial_Deck")];

// KK -->
	aref arstart = GetStorylineStartParams(FindCurrentStoryline());
	string loadPort = arstart.port;
	string rldGroup = "reload";
	string rldLocator = "reload1";
	int loc = FindLocation(arstart.location);
	int iNation = GetCurrentFlag();

	sTeleportLocName = arstart.location;

	// PB: Override Character Type -->
	PChar.start_weapon.blade = FindCharacterItemByGroup(&PChar, BLADE_ITEM_TYPE);
	PChar.start_weapon.gun   = FindCharacterItemByGroup(&PChar, GUN_ITEM_TYPE);
	TakeItemFromCharacter(PChar, PChar.start_weapon.blade);
	TakeItemFromCharacter(PChar, PChar.start_weapon.gun);
	TakeItemFromCharacter(PChar, "spyglass2");
	// PB: Override Character Type <--

	switch(CharPlayerType)
	{
		case PLAYER_TYPE_REBEL:
			if (GetMySimpleName(PChar) == "Julian McAllister" || pchar.model == "47_JRMMSub")
			{
				GiveModel2Player("47_Blaze_brtlt",false);
				GiveModel2Player("Blaze4",false);
				GiveModel2Player("Blaze5",false);
				GiveModel2Player("Blaze6",false);
				GiveModel2Player("Blaze7",false);
				GiveModel2Player("Blaze",false);
				GiveModel2Player("Blaze_NB",false);
				GiveModel2Player("wf1blaze",false);
				GiveModel2Player("Corsair1_J",false);
				GiveModel2Player("Corsair2_J",false);
				GiveModel2Player("Corsair4_J",false);
			}
			
			if (GetMySimpleName(PChar) == "Julian McAllister" && iNation == ENGLAND)
			{
				GiveItem2Character(PChar,"luckcharm");

				if(ENABLE_AMMOMOD)
				{
					TutDeck.box1.items.powderflask = 1;  //JRMM
					TutDeck.box1.items.ammopouch = 1;  //JRMM
				}
				TutDeck.box1.items.bladekit = 1;  //JRMM

				TutDeck.box1.items.medical1 = 4; //JRMM
				TutDeck.box1.items.potion3 = 1;  //JRMM

				// Robert Fletcher
				ch = CharacterFromID("Malcolm Hatcher");
				ch.nation = iNation;
				ch.Dialog.Filename = "Robert Fletcher_dialog.c";
				ch.skill.Leadership = "5";
				ch.skill.Accuracy = "1";
				ch.skill.Cannons = "1";
				ch.name = TranslateString("","Robert");
				ch.lastname = TranslateString("","Fletcher");
				SetModelfromArray(ch, GetModelIndex("pir_cap6"));
			}
		break;

		case PLAYER_TYPE_NAVAL_OFFICER:
			if(ProfessionalNavyNation() != UNKNOWN_NATION)
			{
				// Admiral
				ch = CharacterFromID("Malcolm Hatcher");
				ch.Dialog.Filename = "Robert Fletcher_dialog.c";
				ch.nation = iNation;
				ch.professionalnavy = iNation;
				if (GetMySimpleName(PChar) == "Horatio Hornblower")
				{
					ch.name = TranslateString("","Edward");
					ch.lastname = TranslateString("","Pellew");
					SetRank(ch, iNation, 7);
					SetRankTitle(ch, TranslateString("", "Sir"));
					SetModelfromArray(ch, GetModelIndex("PellewX_18"));
				}
				else
				{
					DeleteAttribute(ch, "questchar")
					SetRandomNameToCharacter(ch);
					SetRank(ch, iNation, 12);
					switch(iNation)
					{
						case ENGLAND:
							SetRankTitle(ch, TranslateString("", "Sir"));
							if(GetCurrentPeriod() < PERIOD_COLONIAL_POWERS)	SetModelfromArray(ch, GetModelIndex("hugnt18"));
							else											SetModelfromArray(ch, GetModelIndex("brtadm2_18"));
						break;
						case FRANCE:
							if(GetCurrentPeriod() < PERIOD_COLONIAL_POWERS)	SetModelfromArray(ch, GetModelIndex("hugnt18"));
							else											SetModelfromArray(ch, GetModelIndex("fra_adm_18"));
						break;
						case SPAIN:
							if(GetCurrentPeriod() < PERIOD_COLONIAL_POWERS)	SetModelfromArray(ch, GetModelIndex("admiral"));
							else											SetModelfromArray(ch, GetModelIndex("spa_adm_18"));
						break;
						case HOLLAND:
							SetModelfromArray(ch, GetModelIndex("Gherarde_De_Jongh"));
						break;
						case PORTUGAL:
							SetModelfromArray(ch, GetModelIndex("admiral"));
						break;
						case AMERICA:
							SetModelfromArray(ch, GetModelIndex("USA_adm_18"));
						break;
					}
				}
			}
		break;

		case PLAYER_TYPE_ROGUE:
			// Elbaron Caron
			ch = CharacterFromID("Malcolm Hatcher");
			ch.Dialog.Filename = "Robert Fletcher_dialog.c";
			ch.nation = iNation;
			if (iNation == FRANCE)
			{
				ch.name = TranslateString("","Elbaron");
				ch.lastname = TranslateString("","Caron");
				SetModelfromArray(ch, GetModelIndex("50M5"));
			}
			else
			{
				DeleteAttribute(ch, "questchar")
				SetRandomNameToCharacter(ch);
			}
		break;

		case PLAYER_TYPE_GAMBLER:
			// Elbaron Caron
			ch = CharacterFromID("Malcolm Hatcher");
			ch.Dialog.Filename = "Robert Fletcher_dialog.c";
			ch.nation = iNation;
			if (iNation == FRANCE)
			{
				ch.name = TranslateString("","Elbaron");
				ch.lastname = TranslateString("","Caron");
				SetModelfromArray(ch, GetModelIndex("50M5"));
			}
			else
			{
				DeleteAttribute(ch, "questchar")
				SetRandomNameToCharacter(ch);
			}
		break;

		case PLAYER_TYPE_SMUGGLER:
			ch = CharacterFromID("Malcolm Hatcher");
			ch.Dialog.Filename = "Robert Fletcher_dialog.c";
			SetModelfromArray(ch, GetModelIndex(GetRandomModelForTypeExSubCheck(1, OFFIC_TYPE_BOATSWAIN, "man", PIRATE)));
			DeleteAttribute(ch, "questchar")
			SetRandomNameToCharacter(ch);
		break;

		case PLAYER_TYPE_AGENT:
			// Admiral
			ch = CharacterFromID("Malcolm Hatcher");
			ch.Dialog.Filename = "Robert Fletcher_dialog.c";
			if (GetMySimpleName(PChar) == "Jean Lafitte" && GetCurrentPeriod() >= PERIOD_REVOLUTIONS)
				iNation = AMERICA;															// Encourage play for America
			ch.nation = iNation;
			DeleteAttribute(ch, "questchar")
			SetRandomNameToCharacter(ch);
			ch.professionalnavy = iNation;
			SetRank(ch, iNation, 12);
			switch(iNation)
			{
				case ENGLAND:
					SetRankTitle(ch, TranslateString("", "Sir"));
					SetModelfromArray(ch, GetModelIndex("brtadm2_18"));
				break;
				case FRANCE:
					if (GetMySimpleName(PChar) == "Milady de Winter")
					{
						SetModelfromArray(ch, GetModelIndex("Maltese"));
						ch.name = TranslateString("","Cardinal");
						ch.lastname = TranslateString("","Richelieu");
						PChar.reputation = REPUTATION_HORROR;
						DeleteAttribute(ch, "nations."+ ch.professionalnavy + ".Rank");
						DeleteAttribute(ch, "professionalnavy");
					}
					else
					{
						SetModelfromArray(ch, GetModelIndex("fra_cpt2_18"));
					}
				break;
				case SPAIN:
					SetModelfromArray(ch, GetModelIndex("spa_adm_18"));
				break;
				case HOLLAND:
					SetModelfromArray(ch, GetModelIndex("Gherarde_De_Jongh"));
				break;
				case PORTUGAL:
					SetModelfromArray(ch, GetModelIndex("admiral"));
				break;
				case AMERICA:
					SetModelfromArray(ch, GetModelIndex("USA_adm_18"));
				break;
				case PIRATE:
					SetModelfromArray(ch, GetModelIndex("CaptainTeague"));
					ch.name = TranslateString("","Teague");
					ch.lastname = TranslateString("","Sparrow");
				break;
				case PERSONAL_NATION:
					SetModelfromArray(ch, GetModelIndex("hadoque"));
					ch.name = TranslateString("","François");
					ch.lastname = TranslateString("","de Hadoque");
				break;
			}
		break;

		case PLAYER_TYPE_CURSED:
			ch = CharacterFromID("Malcolm Hatcher");
			ch.Dialog.Filename = "Robert Fletcher_dialog.c";
			ch.nation = iNation;
			if(CheckCharacterItem(PChar, "Davy_Chest"))
			{
				SetModelfromArray(ch, GetModelIndex("davy1"));
				ch.name = "Koleniko";
				ch.lastname = "";
			}
			else
			{
				if (PChar.ship.type == SHIP_CURSED) GiveShip2Character(PChar,"BlackPearl",PreprocessText("#scursed_ship#"),-1,PIRATE,true,true); // So you can actually lift the curse
				locations[FindLocation("Grotto")].box1.items.cursedcoin = 0;
				TutDeck.WeaponsLocker.items.cursedcoin = GetCursedCoinCount() - 1 - GetDifficulty()*2;

				// Ragetti
				if (GetMySimpleName(PChar) == "Hector Barbossa")
				{
					SetModelfromArray(ch, GetModelIndex("Ragetti"));
					ch.name = "Ragetti";
					ch.lastname = "";
				}
				else
				{
					SetModelfromArray(ch, GetModelIndex("BadV"));
					DeleteAttribute(ch, "questchar")
					SetRandomNameToCharacter(ch);
				}
			}
		break;

		case PLAYER_TYPE_CORSAIR:
			ch = CharacterFromID("Malcolm Hatcher");
			ch.nation = iNation;
			if (NationNoIsland(iNation, GetCurrentPeriod()))
			{
				SetModelfromArray(ch, GetModelIndex(GetRandomModelForTypeExSubCheck(1, OFFIC_TYPE_BOATSWAIN, "man", iNation)));
				DeleteAttribute(ch, "questchar")
				SetRandomNameToCharacter(ch);
				ch.Dialog.Filename = "Robert Fletcher_dialog.c";
			}
		break;

		case PLAYER_TYPE_CASTAWAY:
			ch = CharacterFromID("Malcolm Hatcher");
			ch.Dialog.Filename = "Robert Fletcher_dialog.c";
			ch.nation = iNation;
			DeleteAttribute(ch, "questchar")
			SetRandomNameToCharacter(ch);
			SetModelfromArray(ch, GetModelIndex(GetRandomModelForTypeExSubCheck(1, "Captains", "man", iNation)));
		break;
	}

	TakeNItems(PChar, "medical1", 2); // PB

	if (ENABLE_AMMOMOD)
	{
		TakeNItems(PChar, "gunpowder", 6);
		TakeNItems(PChar, "pistolbullets", 6);
	}

	//NK -->
	PChar.Ship.HP = MakeInt(GetCharacterShipHP(PChar) * 3 / 5);
	PChar.Ship.crew.quantity = MakeInt(GetMaxCrewQuantity(PChar) * 3/5);
	PChar.Ship.SP = MakeInt(GetCharacterShipSP(PChar) * 4 / 5); // MAXIMUS interface MOD
	// to fix the good overup stuff 05-04-06 NK -->
	string goods_id;
	for(int n=0; n<GOODS_QUANTITY; n++)
	{
		if(!CheckAttribute(Goods[n],"name")) continue;
		goods_id = Goods[n].name;
		PChar.Ship.Cargo.Goods.(goods_id) = 0;
	}
	// NK <--
	int space = GetCargoMaxSpace(PChar); // MAXIMUS interface MOD // KK

// KK -->

// Levis: moved up so we can determine the cargo for the new port
	string cabinID = GetCharacterShipCabin(PChar);
	rldGroup = "rld";
	rldLocator = "startloc";
	if (cabinID != "Cabin_none") {
		iShipCaptain = GetMainCharacterIndex();
		SetUpCabin(PChar);
		if (cabinID != "Tutorial_Deck") TutDeck.items.randitem1 = "";
	} else {
		SetModelFromID(ch, "Corsair5");
		iShipCaptain = sti(ch.index);
		SetUpCabin(GetCharacter(iShipCaptain));
		rldGroup = "reload";
		rldLocator = "reload1";
	}

	string rldLocator_Port = "";

	if (CharPlayerType == PLAYER_TYPE_REBEL)			iNation = PIRATE;					// Traitors start at Nevis
	if (NationNoIsland(iNation, GetCurrentPeriod()))	iNation = PIRATE;					// Need some place to start

	switch(iNation)
	{
		case ENGLAND:
			loadPort = "Oxbay_port";
			rldLocator_Port = "reload2";
		break;
		case FRANCE:
			loadPort = "Falaise_de_fleur_port_01";
			rldLocator_Port = "sea";
		break;
		case SPAIN:
			loadPort = "Muelle_port";
			rldLocator_Port = "reload3";
		break;
		case PIRATE:
			loadPort = "QC_port";
			rldLocator_Port = "reload1";
		break;
		case HOLLAND:
			loadPort = "Douwesen_port";
			rldLocator_Port = "reload2";
		break;
		case PORTUGAL:
			loadPort = "Conceicao_port";
			rldLocator_Port = "reload2";
		break;
		case AMERICA:
			loadPort = "Eleuthera_Port";
			rldLocator_Port = "reload1_back";
		break;
		case PERSONAL_NATION:
			loadPort = "Oxbay_port";
			rldLocator_Port = "reload2";
		break;
	}

	string ship_deck = "";
	if (cabinID != "Cabin_none")
		ship_deck = GetCharacterShipQDeck(PChar);
	else
	{
		ship_deck = GetCharacterShipQDeck(ch);
		ch.nation = GetCurrentFlag();			// PB: Just for fun
		SetCharacterShipLocation(ch, loadPort);	// PB: Just for fun
	}
	Locations[loc].reload.l1.go = ship_deck;
	Locations[loc].reload.l1.emerge = "reload1";
	Locations[FindLocation(ship_deck)].reload.l4.go = loadPort;
	Locations[FindLocation(ship_deck)].reload.l4.emerge = rldLocator_Port;
	Locations[FindLocation(ship_deck)].reload.l4.disable = 1;
	Locations[FindLocation(ship_deck)].reload.l5.go = loadPort;
	Locations[FindLocation(ship_deck)].reload.l5.emerge = rldLocator_Port;
	Locations[FindLocation(ship_deck)].reload.l5.disable = 1;
	// PB: Can we CreatePortLandscape for the tutorial?

	trace("Made change of cabin and deck parameters for "+CharShipType);
// <-- KK

// added by MAXIMUS [gunpowder mod] -->
	// fixed 05-04-06 to use makeint() -->
	int loadBalls = makeint(GetCannonQuantity(PChar)*BALLS_PER);
	int loadGrapes = makeint(GetCannonQuantity(PChar)*GRAPE_PER);
	int loadChain = makeint(GetCannonQuantity(PChar)*CHAIN_PER);
	int loadBombs = makeint(GetCannonQuantity(PChar)*BOMBS_PER*(!USE_REAL_CANNONS));
	int loadWheat = makeint(sti(PChar.ship.crew.quantity) * FOOD_PER_CREW * WHEAT_DAYS * 1.5);	// PB: Jamaica is pretty far with the new Worldmap
	int loadRum = makeint(sti(PChar.ship.crew.quantity) * FOOD_PER_CREW * RUM_DAYS * 1.5);		// PB: And refitting your ship takes 15 days

	int loadGunpowder = makeint(GetCannonQuantity(PChar) * GetCannonChargesPerCannon(PChar)) * CANNONPOWDER_MOD;
	if (loadGunpowder < 0) loadGunpowder = 0;
	loadGunpowder *= (BALLS_PER + GRAPE_PER + CHAIN_PER + BOMBS_PER*(!USE_REAL_CANNONS));

	int loadCargo = GetGoodWeightByType(GOOD_BALLS, loadBalls) + GetGoodWeightByType(GOOD_GRAPES, loadGrapes) + GetGoodWeightByType(GOOD_KNIPPELS, loadChain) + GetGoodWeightByType(GOOD_BOMBS, loadBombs) + GetGoodWeightByType(GOOD_WHEAT, loadWheat) + GetGoodWeightByType(GOOD_RUM, loadRum) + GetGoodWeightByType(GOOD_GUNPOWDER, loadGunpowder);

	if (space < loadCargo) {
		int cargo_count = makeint((loadBalls > 0) + (loadGrapes > 0) + (loadChain > 0) + (loadBombs > 0) + (loadWheat > 0) + (loadRum > 0));
		if (cargo_count != 0) {
			loadBalls /= cargo_count;
			loadGrapes /= cargo_count;
			loadChain /= cargo_count;
			loadBombs /= cargo_count;
			loadWheat /= cargo_count;
			loadRum /= cargo_count;
			loadGunpowder /= cargo_count;
		}
	}
	SetCharacterGoods(&PChar, GOOD_BALLS, loadBalls);
	SetCharacterGoods(&PChar, GOOD_GRAPES, loadGrapes);
	SetCharacterGoods(&PChar, GOOD_KNIPPELS, loadChain);
	SetCharacterGoods(&PChar, GOOD_BOMBS, loadBombs);
	SetCharacterGoods(&PChar, GOOD_WHEAT, loadWheat);
	SetCharacterGoods(&PChar, GOOD_RUM, loadRum);
	SetCharacterGoods(&PChar, GOOD_GUNPOWDER, loadGunpowder);

	int attempts = 0;
	CharGood1 = 0;
	CharGood2 = 0;
	while(CharGood1 == CharGood2)
	{
		CharGood1 = getRandomImportGood(GetIslandByID(FindIslandByLocation(loadPort)));
		CharGood2 = getRandomImportGood(GetIslandByID(FindIslandByLocation(loadPort)));
		// PB: Keep looping until *valid* goods are found -->
		if (CharGood1 == GOOD_SAILCLOTH	|| CharGood2 == GOOD_SAILCLOTH	) CharGood1 = CharGood2;
		if (CharGood1 == GOOD_PLANKS	|| CharGood2 == GOOD_PLANKS		) CharGood1 = CharGood2;
		if (CharGood1 == GOOD_WHEAT		|| CharGood2 == GOOD_WHEAT		) CharGood1 = CharGood2;
		if (CharGood1 == GOOD_RUM 		|| CharGood2 == GOOD_RUM		) CharGood1 = CharGood2;
		if (CharGood1 == GOOD_GUNPOWDER	|| CharGood2 == GOOD_GUNPOWDER	) CharGood1 = CharGood2;
		// PB: Keep looping until *valid* goods are found <--
		attempts++;
		if(attempts > 20) break;
	}
	
	/*if (CharGood1 == GOOD_SAILCLOTH || CharGood1 == GOOD_PLANKS) 	CharGood1 = GOOD_SILK;
	if (CharGood1 == GOOD_WHEAT || CharGood1 == GOOD_RUM) 			CharGood1 = GOOD_SILK;
	if (CharGood2 == GOOD_SAILCLOTH || CharGood2 == GOOD_PLANKS) 	CharGood2 = GOOD_WINE;
	if (CharGood2 == GOOD_WHEAT || CharGood2 == GOOD_RUM) 			CharGood2 = GOOD_WINE;*/

	space -= loadCargo;
	float cargo_div = Rand(100)/100.0;
	loadCargo = makeint(cargo_div*space);
	if (loadCargo > 100) loadCargo = 100;
	SetCharacterGoods(&PChar, CharGood1, loadCargo);
	space -= loadCargo;
	loadCargo = makeint((1.0-cargo_div)*space);
	if (loadCargo > 100) loadCargo = 100;
	SetCharacterGoods(&PChar, CharGood2, loadCargo);


// by this section we are adding money to character (if he has a unsufficiently sum for ship's repair and crew's hiring) -->
	ref sto; makeref(sto, Stores[CharStore]);
	int cargoPrice1 = GetGoodPriceByType(sto, PChar, CharGood1, GetCargoGoods(PChar,CharGood1),PRICE_TYPE_SELL);
	int cargoPrice2 = GetGoodPriceByType(sto, PChar, CharGood2, GetCargoGoods(PChar,CharGood2),PRICE_TYPE_SELL);
    float qty = 1;
	switch(Rand(5))
    {
		case 0: qty = 1.356; break;
		case 1: qty = 1.890; break;
		case 2: qty = 1.674; break;
		case 3: qty = 1.724; break;
		case 4: qty = 1.057; break;
		case 5: qty = 1.532; break;
    }

	int sailCostPercent = 10;
	int hullCostPercent = 20;
	aref arCurShip; makearef(arCurShip, PChar.ship);
	int shipPrice = sti(GetLocalShipAttrib(arCurShip, GetCharacterShipType(PChar), "Price"));
	int hireQty = makeint(GetMaxCrewQuantity(PChar) - GetCrewQuantity(PChar));

	int hireCost = sti(GetCrewHireCost(PChar) * hireQty);
	int repCost = MakeInt(makeint((((shipPrice*hullCostPercent+99)/100)*makeint(100 - MakeInt(GetHullPercent(PChar)))+99)/100)) + MakeInt((makeint((shipPrice*sailCostPercent+99)/100)*makeint(100 - MakeInt(GetSailPercent(PChar)))+99)/100);

	int avPrice = makeint(cargoPrice1 + cargoPrice2)*qty;
	if (makeint(cargoPrice1 + cargoPrice2) < sti(hireCost+repCost)) {
		int addMoney = makeint(sti(hireCost+repCost)-avPrice);
		if (addMoney > 0)
			AddMoneyToCharacter(PChar, addMoney);
		else
			AddMoneyToCharacter(PChar, sti(hireCost+repCost));
	} else {
		PChar.money = makeint(5000*qty);// TIH fixed decimal gold on start new game
	}
// by this section we are adding money to character (if he has a unsufficiently sum for ship's repair and crew's hiring) <--

// added by MAXIMUS [gunpowder mod] <--


	Reinit_KhaelRoa();

//================================| BEGINNING QUESTS |================================//

	PChar.quest.StartAdventure.win_condition.l1 = "Timer";
	PChar.quest.StartAdventure.win_condition.l1.date.day = GetAddingDataDay(0, 0, 0);
	PChar.quest.StartAdventure.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
	PChar.quest.StartAdventure.win_condition.l1.date.year = GetAddingDataYear(0, 0, 0);
	PChar.quest.StartAdventure.win_condition = "StartAdventure";

	PChar.quest.Tut_start.win_condition.l1 = "location";
	PChar.quest.Tut_start.win_condition.l1.character = PChar.id;
	PChar.quest.Tut_start.win_condition.l1.location = "Tutorial_Deck";
	PChar.quest.Tut_start.win_condition = "Tut_start";

	// PB: Started Later -->
	DeleteAttribute(PChar, "quest.Install_Voysey_And_Blythe");
	// PB: Started Later <--

//===============================| QUESTS SECTION END |===============================//

	ReloadProgressUpdate();

	AllDaysCount = 1;//MAXIMUS: calculates days amount (updating in calendar.c)
	PChar.newGameStart = true;//MAXIMUS: for adding new locators
	PChar.location.first = true;
	PChar.vcskip = true; // PB: To prevent random characters until AFTER the tutorial

	LoadMainCharacterInFirstLocation(sTeleportLocName, rldGroup, rldLocator, loadPort); // KK

	// Level
	ref rModel;
	makeref(rModel, Models[GetModelIndex(PChar.model)]);
	int i;
	int PlayerLevel = sti(PChar.rank);
	int ModelLevel  = GetAttribute(rModel, "minlevel");
	if (ModelLevel > PlayerLevel)
	{
		for (i = PlayerLevel; i < ModelLevel; i++)
		{
			LevelUp_Cheat(PChar, 1);
		}
	}

	// PB: Modify Default Relations
	if (GetDataYear() >= 1688 && GetDataYear() <= 1697)
	{
		SetNationRelationBoth(ENGLAND, SPAIN,    RELATION_FRIEND);	// Relations as for War of the League of Augsburg, 1688 - 1697
		SetNationRelationBoth(FRANCE,  SPAIN,    RELATION_ENEMY);
		SetNationRelationBoth(SPAIN,   HOLLAND,  RELATION_FRIEND);
		SetNationRelationBoth(SPAIN,   PORTUGAL, RELATION_NEUTRAL);
	}
	iNation = GetCurrentFlag();
	SetRelationsAsNation(iNation);																	// Set nations as per selected flag

	int DefaultStart = 2;
	switch(CharPlayerType)
	{
		case PLAYER_TYPE_REBEL:
			if(iRealismMode == 0)			SetRelationsAsNation(PERSONAL_NATION);					// Don't keep original nation relations on Arcade Game Mode
			if(iNation == PERSONAL_NATION)	iNation = iNation = rand(NATIONS_QUANTITY-1);			// Make sure you do have an enemy!
			if(iNation != PIRATE)			SetRMRelation(PChar, PIRATE, REL_AFTERATTACK);			// You saved a group of pirates from torture and death
			SetRMRelation(PChar, iNation, REL_MIN);													// You are a traitor to the crown
			HoistFlag(PIRATE);																		// Make port at Nevis, so should hoist pirate flag
			SetServedNation(PERSONAL_NATION);														// Prevent traitor behaviour at game start
			DefaultStart = 0;																		// Already start as pirate, so skip the extra check later
		break;

		case PLAYER_TYPE_NAVAL_OFFICER:
			if(ProfessionalNavyNation() != UNKNOWN_NATION)
			{
				// Rank
				int PlayerRank = 3;																	// If commissioned, Lieutenant (=default)
				if (GetAttribute(rModel, "minrank") > 0)	PlayerRank = sti(rModel.minrank);

				// Promotion
				if(PlayerRank == 1) GivePromotionReward(iNation);									// PB: For Midshipmen
				for (i = 0; i < PlayerRank-1; i++)
				{
					Promote_Cheat(PChar, iNation);
				}
			}
			DefaultStart = 1;																		// Do ensure the pirates are set to friendly, if necessary
		break;

		case PLAYER_TYPE_CORSAIR:
			if (iNation != PIRATE)
			{
				if (GetMySimpleName(PChar) == "José Joaquín Almeida" && GetCurrentPeriod() >= PERIOD_REVOLUTIONS)
				{
					iNation = AMERICA;
					SetServedNation(iNation);
					SetRMRelation(PChar, iNation, REL_NEUTRAL);										// Encourage play for America
				}
				else
				{
					SetRMRelation(PChar, PIRATE, REL_AFTERATTACK);									// But are still neutral to the pirates
				}
				SetRank(PChar, iNation, 0);															// Non-pirate corsairs get a Letter of Marque
			}
		break;

		case PLAYER_TYPE_CURSED:
			if(CheckCharacterItem(PChar, "Davy_Chest"))	Nations_SetAllHostile();					// Hostile to everybody
			DefaultStart = 0;																		// Have to remain hostile to everyone, so skip the extra check later
		break;
	}

	if (DefaultStart > 0 && NationNoIsland(iNation, GetCurrentPeriod()))
	{
		SetRMRelation(PChar, PIRATE, REL_AFTERATTACK);												// You do need some sort of safe base of operation
		if (DefaultStart > 1) SafePortLeave(PIRATE, false);											// Hoist False Flag if Required
	}
}
