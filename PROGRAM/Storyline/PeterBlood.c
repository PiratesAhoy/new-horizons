void RegisterStoryline(int n)
{
	ref storyline; makeref(storyline, Storylines);
	aref sl; makearef(sl, storyline.list);
	string sn = "sl" + (n + 1);
	sl.(sn).id = "PeterBlood";
	sl.(sn).index = n;
	sl.(sn).dir = "PeterBlood\";
	string loadPort = "none";
	string sTeleportLocName = "";
	string rldGroup = "";
	string rldLocator = "";
	string testlocnum = "Oxbay_town";
	switch(testlocnum)
	{
	case "Estate":
	sTeleportLocName = "Estate";
	rldGroup = "goto";
	rldLocator = "goto1";
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
	sl.(sn).start.location = testlocnum;
	sl.(sn).start.port = loadPort;
	sl.(sn).start.model = "bocman3";
	sl.(sn).start.model.lock = true;
	sl.(sn).start.name = "Peter";
	sl.(sn).start.lastname = "Blood";
	sl.(sn).start.name.lock = true;
	sl.(sn).start.nation = ENGLAND;
	sl.(sn).start.nation.lock = true;
	sl.(sn).start.playertype = PLAYER_TYPE_SOCIAL_CLIMBER;
	sl.(sn).start.playertype.lock = true;
	sl.(sn).start.difficulty = DIFFICULTY_SEADOG;
	sl.(sn).start.Flags.Pirate = 4;
	sl.(sn).start.Flags.Personal = 8;
	sl.(sn).start.date.hour = 11;
	sl.(sn).start.date.min = 00;
	sl.(sn).start.date.sec = 00;
	sl.(sn).start.date.day = 1;
	sl.(sn).start.date.month = 1;
	sl.(sn).start.date.year = 1665;
	sl.(sn).start.date.lock = true;
	sl.(sn).start.freedom_level = 2; // PB: Scripted opening, but free play available
sl.(sn).start.ship = "FastGalleon1";
	sl.(sn).start.ship.lock = true;
	sl.(sn).start.shipname = "Discovery";
	sl.(sn).start.shipname.lock = true;
	switch (LanguageGetLanguage())
	{
		// default:
			sl.(sn).title = "Peter Blood";
			sl.(sn).description = "Bachelor of Medicine, professional military officer. Irish by birth and Catholic by religion. He was distinguished by his composure, courage and irony. He served in the Dutch Navy and was promoted to officer by the famous Admiral de Ruyter. It was thanks to him that Blood became a brilliant naval commander. He spent two years in a Spanish prison as a prisoner of war, where he mastered the Spanish language perfectly. After leaving prison, he entered the service of the French and, as part of the French army, participated in battles in the territory of Holland occupied by the Spaniards. Five years or so before the book takes place, Captain Gobart saw Blood in the French army at Tangier. After a dark period in his life, success came to him, but only the reciprocity of Miss Arabella Bishop could bring him real happiness.";
		break;
	}
	AddStorylineVar(n, "CHANGING_RELATIONS", "1");	// PB: Changing Relations always on
	AddStorylineVar(n, "ISLA_DE_MUERTE", "0");		// PB: Curse not in effect, but can visit Isla de Muerte
}
