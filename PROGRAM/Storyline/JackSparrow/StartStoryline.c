void StartStoryLine()
{
	ref PChar = GetMainCharacter();
	string loadPort = "Tortuga_Port";
	sTeleportLocName = "Tortuga_Port";
// KK -->
	string rldGroup = "reload";
	string rldLocator = "reload1_back";

	string cabinID = GetCharacterShipCabin(PChar);
	if (cabinID != "Cabin_none")
	{
		iShipCaptain = GetMainCharacterIndex();
		SetUpCabin(PChar);

		Locations[FindLocation("Tutorial_deck")].models.always.l2 = "cabinchest";	//JRH
		Locations[FindLocation("Tutorial_deck")].models.always.l3 = "trunk";		//JRH
	}

	// PB: Override Character Type -->
	DeleteAttribute(PChar, "items");
	GiveItem2Character(PChar, "map");
	// PB: Override Character Type <--

	SetModelfromArray(PChar, GetModelIndex("Fawn"));
	// MAXIMUS 05.09.2018 ==>
	PChar.old.name = "Guy";
	PChar.old.lastname = "Verbinski";
	PChar.name = TranslateString("", "Guy");
	PChar.lastname = TranslateString("", "Verbinski"); 
	// MAXIMUS 05.09.2018 <==
	GiveShip2Character(pchar,"KetchNavy",TranslateString("","White Swan"),-1,PIRATE,true,true);

	GiveItem2Character(Pchar, "bladeX4");	// PB: Gives you your fists
	TakeNItems(PChar, "blade1", 1);
	TakeNItems(PChar, "pistol1", 1);
	TakeNItems(PChar, "spyglass2", 1);
	TakeNItems(PChar, "medical1", 2); // PB
	if (ENABLE_AMMOMOD)
	{
		TakeNItems(PChar, "gunpowder", 6);
		TakeNItems(PChar, "pistolbullets", 6);
	}
	//JRH ammo mod <--
	TakenItems(Pchar, "compass1", 1) // SJG
	TakenItems (Pchar, "clock1", 1) // SJG

	EquipCharacterbyItem(Pchar, "blade1");
	EquipCharacterbyItem(Pchar, "pistol1");
	EquipCharacterbyItem(Pchar, "Spyglass2");
	EquipCharacterbyItem(Pchar, "compass1"); // SJG
	EquipCharacterbyItem(Pchar, "clock1"); // SJG

	PChar.Flags.Pirate = 1;
	PChar.Flags.Pirate.texture = 1;

	CaptureTownForNation("Tortuga", PIRATE);
	SetTownName("Tortuga", "Tortuga");
	Preprocessor_Delete("Tortuga");
	Preprocessor_Save("Tortuga", FindTownName("Tortuga"));
	Towns[GetTownIndex("Quebradas Costillas")].gov = "Skull";				// PB: Set this for real
	Towns[GetTownIndex("Grand Turk")].gov = "Sao Feng";						// PB: Set this for real
	SetCharacterShipLocation(CharacterFromID("Sao Feng"), "Turks_port");	// PB: Just for fun
	 // MAXIMUS 05.09.2018 ==>
	Characters[GetCharacterIndex("John Clifford Brin")].old.name = "John";
	Characters[GetCharacterIndex("John Clifford Brin")].old.middlename = "Clifford";
	Characters[GetCharacterIndex("John Clifford Brin")].old.lastname = "Brin";
	Characters[GetCharacterIndex("John Clifford Brin")].name = TranslateString("", "John");
	Characters[GetCharacterIndex("John Clifford Brin")].middlename = TranslateString("", "Clifford");
	Characters[GetCharacterIndex("John Clifford Brin")].lastname = TranslateString("", "Brin");
	 // MAXIMUS 05.09.2018 <==

	Reinit_KhaelRoa();

//================================| BEGINNING QUESTS |================================//
	//Jack Sparrow Quest
	PChar.quest.Sparrow = "";

	pchar.quest.TotBB_HtC.win_condition.l1 = "location";
	pchar.quest.TotBB_HtC.win_condition.l1.location = "Tortuga_Port";
	pchar.quest.TotBB_HtC.win_condition = "opening";
	Locations[FindLocation("Tortuga_Port")].vcskip = true;
	Locations[FindLocation("Tortuga_Tavern")].vcskip = true;
//	DisableFastTravel(true);
	bQuestDisableSeaEnter = true;
	DeleteAttribute(&locations[FindLocation("Tortuga_port")], "reload.l6.goto_disable");	// Enable fast travel to tavern right away

	pchar.quest.Sparrow_start.win_condition.l1 = "locator";
	pchar.quest.Sparrow_start.win_condition.l1.location = "Cayman_Port";
	pchar.quest.Sparrow_start.win_condition.l1.locator_group = "reload";
	pchar.quest.Sparrow_start.win_condition.l1.locator = "Falaise_de_fleur_location_01_05";
	pchar.quest.Sparrow_start.win_condition = "Sparrow_load";
	Locations[FindLocation("Cayman_Port")].vcskip = true;
	//Jack Sparrow Quest

	ChangeCharacterAddress(characterFromID("EITC Officer"), "none", "");

	// PB: Sidequests -->

	// Ammand the Corsair - Help the Church
		// Custom version of Help the Church sidequest
		// Start is OK (I think)
		// immediately available

	// Capt Chevalle - Rescue his Crew
		// Custom version of regular Peter Blood sidequest, without Search for Peter Bloods Ship extension
		ChangeCharacterAddress(characterFromID("Bartolomeu o Portugues"), "none", "");
		DeleteAttribute(PChar, "quest.Bartolomeu");
		DeleteAttribute(PChar, "quest.Bart_start");
		DeleteAttribute(PChar, "quest.Santiago");
		DeleteAttribute(PChar, "quest.Santiago_start");
		// enabled in case "storm_complete"

	// Gentleman Jocard - A Slaver - Free the Slaves
		// Custom version of Artois Voysey/Nigel Blythe sidequest
		DeleteAttribute(PChar, "quest.Install_Voysey_And_Blythe");
		DeleteAttribute(&Locations[FindLocation("QC_town")],"vcskip");
		// enabled in case "storm_complete"

	// Lucas the Admirals Son
		// Custom version of Find the missing son of the Spanish Admiral sidequest
		PChar.quest.Lucas = "";
		PChar.quest.Luc_start.win_condition.l1 = "location";
		PChar.quest.Luc_start.win_condition.l1.character = PChar.id;
		PChar.quest.Luc_start.win_condition.l1.location = "Santo_Domingo_townhall";
		PChar.quest.Luc_start.win_condition = "Luc_start";
		// immediately available

	// Justine Le Moigne
		// Custom version of Elizabeth Shaw’s Disappearance sidequest
		PChar.quest.Firstcontact = "";
		PChar.quest.Contact_start.win_condition.l1 = "location";
		PChar.quest.Contact_start.win_condition.l1.character = PChar.id;
		PChar.quest.Contact_start.win_condition.l1.location = "Falaise_de_Fleur_townhall";
		PChar.quest.Contact_start.win_condition = "Contact_start";
		// immediately available

	// Sao Feng's Missing Bodyguards
		// Custom version of Strange Things going on in the Caribbean (Animists) sidequest
		ChangeCharacterAddress(characterFromID("Rian Dekkers"), "none", "");
		ChangeCharacterAddress(characterFromID("Janneke Blinkerhof"), "none", "");
		ChangeCharacterAddress(characterFromID("Lisebet Schefold"), "none", "");
		ChangeCharacterAddress(characterFromID("ANIMISTS_01"), "none", "");
		ChangeCharacterAddress(characterFromID("ANIMISTS_02"), "none", "");
		ChangeCharacterAddress(characterFromID("ANIMISTS_03"), "none", "");
		ChangeCharacterAddress(characterFromID("ANIMISTS_04"), "none", "");
		ChangeCharacterAddress(characterFromID("ANIMISTS_05"), "none", "");
		ChangeCharacterAddress(characterFromID("ANIMISTS_06"), "none", "");
		ChangeCharacterAddress(characterFromID("ANIMISTS_07"), "none", "");
		ChangeCharacterAddress(characterFromID("ANIMISTS_08"), "none", "");
		ChangeCharacterAddress(characterFromID("ANIMISTS_09"), "none", "");
		SetRumourState("Children_start", false);	// Disable standard rumour
		// enabled in case "storm_complete"

	// Sri Sumbhajee Angria – Saving Askays Brother
		// Custom version of Saving Toff's Daughter sidequest
		ChangeCharacterAddress(characterFromID("Toff Oremans"), "none", "");
		pchar.quest.spanish_soldier_alone.win_condition.l1 = "locator";
		pchar.quest.spanish_soldier_alone.win_condition.l1.location = "Havana_town_02";
		pchar.quest.spanish_soldier_alone.win_condition.l1.locator_group = "reload";
		pchar.quest.spanish_soldier_alone.win_condition.l1.locator = "reload18";
		pchar.quest.spanish_soldier_alone.win_condition = "spanish_soldier_alone";
		// immediately available

	// Villanueva - Help Two Pirates
		// Custom version of The Silver Train sidequest
		DeleteAttribute(PChar, "quest.Jackpot");
		DeleteAttribute(PChar, "quest.Jackpot_start");
		// enabled in case "storm_complete"

	// Hard Labours of an Assassin - change "thug9" from Jack Sparrow to Nathaniel Hawk
		SetModelFromID(CharacterFromID("thug9"), "blaze");
		Characters[GetCharacterIndex("thug9")].name = TranslateString("", "Nathaniel");
		Characters[GetCharacterIndex("thug9")].lastname = TranslateString("", "Hawk");
		Characters[GetCharacterIndex("thug9")].greeting = "Gr_Nathaniel";
		Characters[GetCharacterIndex("thug9")].Dialog.Filename = "Nathaniel Hawk_dialog.c";
		Characters[GetCharacterIndex("thug9")].Dialog.CurrentNode = "intro";
	// PB: Sidequests  <--

	//Tortuga Atmosphere
	DeleteAttribute(PChar, "quest.Tortuga_atmosphere");
	PChar.quest.Tortuga_jack.win_condition.l1 = "location";
	PChar.quest.Tortuga_jack.win_condition.l1.character = PChar.id;
	PChar.quest.Tortuga_jack.win_condition.l1.location = "Tortuga_port";
	PChar.quest.Tortuga_jack.win_condition = "Tortuga_jack";
	PChar.quest.Tortuga_jack.skip = "yes";
	//Tortuga Atmosphere

//===============================| QUESTS SECTION END |===============================//

	ReloadProgressUpdate();

	AllDaysCount = 1;//MAXIMUS: calculates days amount (updating in calendar.c)
	PChar.newGameStart = true;//MAXIMUS: for adding new locators

	LoadMainCharacterInFirstLocation(sTeleportLocName, rldGroup, rldLocator, loadPort); // KK

	// PB: Modify Default Relations
	SetRelationsAsNation(PIRATE);	// Starting character is a pirate (is overridden later on for Jack Sparrow)
}
