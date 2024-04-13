void StartStoryLine()
{
	ref PChar = GetMainCharacter();
	string loadPort = "";
	string sTeleportLocName = "";
	string rldGroup = "";
	string rldLocator = "";
	pchar.testlocnum = "Estate";
	switch(pchar.testlocnum)
	{
	case "Estate":
	sTeleportLocName = "Estate";
	rldGroup = "goto";
	rldLocator = "goto1";
	DeleteAttribute(PChar,"ship");
	DeleteAttribute(PChar,"equip");
	DeleteAttribute(PChar,"money");
	DeleteAttribute(PChar,"items");
	pchar.money = 0;
	break;
	case "Havana_Restoran":
	sTeleportLocName = "Havana_Restoran";
	rldGroup = "goto";
	rldLocator = "goto1";
	break;
	case "Test_Fort_1":
	loadPort = "Test_Fort_1";
	sTeleportLocName = "Test_Fort_1";
	rldGroup = "reload";
	rldLocator = "reload3";
	break;
	case "Test_Fort_2":
	loadPort = "Test_Fort_2";
	sTeleportLocName = "Test_Fort_2";
	rldGroup = "reload";
	rldLocator = "reload2";
	break;
	case "Test_Fort_3":
	loadPort = "Test_Fort_3";
	sTeleportLocName = "Test_Fort_3";
	rldGroup = "reload";
	rldLocator = "reload2";
	break;
	case "Guadeloupe_shore_test":
	loadPort = "Guadeloupe_shore_test";
	sTeleportLocName = "Guadeloupe_shore_test";
	rldGroup = "goto";
	rldLocator = "goto8";
	break;
	case "MountainPathDMChest":
	loadPort = "MountainPathDMChest";
	sTeleportLocName = "MountainPathDMChest";
	rldGroup = "goto";
	rldLocator = "goto8";
	break;
	case "Antigua_shore_test":
	loadPort = "Antigua_shore_test";
	sTeleportLocName = "Antigua_shore_test";
	rldGroup = "goto";
	rldLocator = "goto8";
	break;
	case "Bermudes_town":
	loadPort = "Bermudes_town";
	sTeleportLocName = "Bermudes_town";
	rldGroup = "reload";
	rldLocator = "reload3_back";
	break;
	case "Greenford_town_2":
	loadPort = "Greenford_port";
	sTeleportLocName = "Greenford_town_2";
	rldGroup = "reload";
	rldLocator = "reload_18";
	break;
	case "Oxbay_town":
	loadPort = "Oxbay_town";
	sTeleportLocName = "Oxbay_tavern";
	rldGroup = "goto";
	rldLocator = "goto3";
	break;
	case "LostShipsCity_town":
	loadPort = "LostShipsCity_town";
	sTeleportLocName = "LostShipsCity_town";
	rldGroup = "reload";
	rldLocator = "reload41";
	break;
	}
// KK -->
 
// <-- SJG
	ReloadProgressUpdate();

	AllDaysCount = 1;//MAXIMUS: calculates days amount (updating in calendar.c)
	PChar.newGameStart = true;//MAXIMUS: for adding new locators
	LoadMainCharacterInFirstLocation(sTeleportLocName, rldGroup, rldLocator, loadPort); // KK
	LAi_SetPlayerType(pchar);
	LAi_SetImmortal(pchar, true);
	Pchar.questTemp.CapBloodLine.stat = "Begining";
	DoQuestCheckDelay("Blood0", 1.0);
	}