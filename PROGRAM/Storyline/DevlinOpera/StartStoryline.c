void StartStoryLine()
{
	ref PChar = GetMainCharacter();
	string loadPort = "Redmond_port";
	sTeleportLocName = "Redmond_port";
// KK -->
	string rldGroup = "reload";
	string rldLocator = "sea_1";

	string cabinID = GetCharacterShipCabin(PChar);
	if (cabinID != "Cabin_none")
	{
		iShipCaptain = GetMainCharacterIndex();
		SetUpCabin(PChar);

		Locations[FindLocation("Tutorial_deck")].models.always.l2 = "cabinchest";	//JRH
		Locations[FindLocation("Tutorial_deck")].models.always.l3 = "trunk";		//JRH
	}

	TakeNItems(PChar, "spyglass2", 1);
	TakeNItems(PChar, "medical1", 2); // PB
	if (ENABLE_AMMOMOD)
	{
		TakeNItems(PChar, "gunpowder", 6);
		TakeNItems(PChar, "pistolbullets", 6);
	}
	//JRH ammo mod <--

	EquipCharacterbyItem(Pchar, FindCharacterItemByGroup(&PChar, BLADE_ITEM_TYPE));
	EquipCharacterbyItem(Pchar, FindCharacterItemByGroup(&PChar, GUN_ITEM_TYPE));
	EquipCharacterbyItem(Pchar, "Spyglass2");
// <-- KK

// SJG -->
	SetNextWeather("Blue Sky"); 
// <-- SJG

	Reinit_KhaelRoa();
	Towns[GetTownIndex("Grand Turk")].gov = "Short Jack Gold";
	Characters[GetCharacterIndex("Short Jack Gold")].dialog.filename = "Nathan Kell (GOV)_dialog.c";
	ChangeCharacterAddressGroup(characterFromID("Dante Siciliano"), "none", "", "");

//================================| LOCATIONS |=======================================//

	Locations[FindLocation("Redmond_port")].reload.l7.name = "Door_4";
	Locations[FindLocation("Redmond_port")].reload.l7.go = "Storyteller_house";
	Locations[FindLocation("Redmond_port")].reload.l7.emerge = "reload1";
	Locations[FindLocation("Redmond_port")].reload.l7.autoreload = "0";
	Locations[FindLocation("Redmond_port")].reload.l7.label = "House.";

//================================| BEGINNING QUESTS |================================//

	//Beatrice
	PChar.quest.Start = "";
	PChar.quest.Start.win_condition.l1 = "location";
	PChar.quest.Start.win_condition.l1.character = PChar.id;
	PChar.quest.Start.win_condition.l1.location = "Redmond_port";
	PChar.quest.Start.win_condition = "Start";
	//Beatrice

	DeleteAttribute(PChar, "quest.Install_Voysey_And_Blythe");										//disables sidequest in Nevis
	DeleteAttribute(&Locations[FindLocation("QC_town")],"vcskip");									//disables sidequest in Nevis

//===============================| QUESTS SECTION END |===============================//

	ReloadProgressUpdate();

	AllDaysCount = 1;//MAXIMUS: calculates days amount (updating in calendar.c)
	PChar.newGameStart = true;//MAXIMUS: for adding new locators

	LoadMainCharacterInFirstLocation(sTeleportLocName, rldGroup, rldLocator, loadPort); // KK

	// PB: Modify Default Relations
	SetRelationsAsNation(GetCurrentFlag());
	SafePortLeave(SPAIN, false);
}
