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

	sTeleportLocName = arstart.location;

//ASVS --->
	PChar.main_theme.value = "0";
	PChar.main_theme.musicname = "music_main_theme";
//ASVS <---

	// PB: Override Character Type -->
	PChar.start_weapon.blade = FindCharacterItemByGroup(&PChar, BLADE_ITEM_TYPE);
	PChar.start_weapon.gun   = FindCharacterItemByGroup(&PChar, GUN_ITEM_TYPE);
	TakeItemFromCharacter(Pchar, PChar.start_weapon.blade);
	TakeItemFromCharacter(Pchar, PChar.start_weapon.gun);
	TakeItemFromCharacter(Pchar, "spyglass2");
	// PB: Override Character Type <--

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

		TutDeck.models.always.l2 = "cabinchest";			//JRH
		TutDeck.models.always.l3 = "trunk";				//JRH

		if (cabinID != "Tutorial_Deck") TutDeck.items.randitem1 = "";
	} else {
		SetModelFromID(ch, "Corsair5");
		iShipCaptain = sti(ch.index);
		SetUpCabin(GetCharacter(iShipCaptain));
		rldGroup = "reload";
		rldLocator = "reload1";
	}

	string rldLocator_Port = "";

	switch(GetCurrentFlag())
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
		PChar.money = makeint(1000*qty);// TIH fixed decimal gold on start new game
	}
// by this section we are adding money to character (if he has a unsufficiently sum for ship's repair and crew's hiring) <--

// added by MAXIMUS [gunpowder mod] <--

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

	// PB: Quest Corrections -->
	DeleteAttribute(PChar, "quest.Install_Voysey_And_Blythe");
	characters[GetCharacterIndex("Edgar Attwood")].quest.to_hire = "0";
	Characters[GetCharacterIndex("Arabella Silehard")].lastname = Characters[GetCharacterIndex("Robert Christopher Silehard")].lastname; // Name after actual governor
	if (PChar.sex == "woman")
	{
		ch = CharacterFromID("Danielle");
		ch.name = TranslateString("","Nathaniel");
		ch.lastname = TranslateString("","Hawk");
		ch.model.animation = "man";
		ch.sex = "man";
		ch.greeting = "Gr_Nathaniel";
		switch(Rand(4))			// For a bit of fun, give Nathaniel a random choice of "Blaze" outfit
    		{
			case 0: SetModelFromID(ch, "Blaze"); break;
			case 1: SetModelFromID(ch, "Blaze4"); break;
			case 2: SetModelFromID(ch, "Blaze5"); break;
			case 3: SetModelFromID(ch, "Blaze6"); break;
			case 4: SetModelFromID(ch, "Blaze7"); break;
    		}
	}

	SetModelfromID(CharacterFromID("Joaquin Da Saldanha"), "admiral");	// Restore Lucas and admiral to original models
	SetModelfromID(CharacterFromID("Lucas Da Saldanha"), "lucas");
	// PB: Quest Corrections <--

//===============================| QUESTS SECTION END |===============================//

	ReloadProgressUpdate();

	AllDaysCount = 1;//MAXIMUS: calculates days amount (updating in calendar.c)
	PChar.newGameStart = true;//MAXIMUS: for adding new locators
	PChar.location.first = true;
	PChar.vcskip = true; // PB: To prevent random characters until AFTER the tutorial

	LoadMainCharacterInFirstLocation(sTeleportLocName, rldGroup, rldLocator, loadPort); // KK

	// PB: Modify Default Relations
	SetRelationsAsNation(GetCurrentFlag());												// Set nations as per selected flag
	if(GetCurrentFlag() == PERSONAL_NATION)	SetRMRelation(PChar, ENGLAND, REL_AMNESTY);	// PB: Starts for England, so need to be at least Neutral
	if(GetCurrentFlag() == ENGLAND)														// Will be returned to ENGLAND after the French invasion
	{
		HoistFlag(PERSONAL_NATION);														// PB: ALWAYS hoist personal flag to prevent English players from dying
		SetRMRelation(PChar, FRANCE, REL_AFTERATTACK);									// TIH: set to rel_afterattack, was "REL_WAR + 1." Nov2'06
	}
}
