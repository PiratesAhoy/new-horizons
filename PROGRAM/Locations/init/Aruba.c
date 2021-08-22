void LocationInitAruba(ref n)
{

// -------------------------------------------------

	Locations[n].filespath.models = "locations\Town_Oranjestad\port";	
	Locations[n].image = "Town_Oranjestad_Port.tga";

	Locations[n].id = "Oranjestad_port";
	locations[n].id.label = "#stown_name# port."; // KK
	locations[n].worldmap = "Oranjestad";
	//Town sack
	Locations[n].townsack = "Oranjestad"; // KK
	//Sound
	locations[n].type = "port";
	locations[n].fastreload = "Oranjestad";
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	Locations[n].models.always.locators = "locator_l";
	Locations[n].models.always.l1 = "OJport";
	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.add = "light";
	Locations[n].models.always.tree = "tree";
	Locations[n].models.always.add2 = "ludeng";
	Locations[n].models.always.add3 = "ladder2";			//JRH	
	Locations[n].models.always.add4 = "door_OJ2_A";			//JRH
	Locations[n].models.always.add5 = "door_OJ2_B";			//JRH	

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "wood_long_log";
	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "wood_long_log";

	//Day
	Locations[n].models.day.charactersPatch = "walk_patch";

	//Night
	Locations[n].models.night.charactersPatch = "walk_patch";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map

	Locations[n].reload.l1.name = "reload3";
	Locations[n].reload.l1.go = "Oranjestad_exit";
	Locations[n].reload.l1.emerge = "reload2_back";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3 = 1.0;

	Locations[n].reload.l2.name = "reload1";
	Locations[n].reload.l2.go = "Aruba";
	Locations[n].reload.l2.emerge = "reload_1";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.reload1 = 3.0;

	Locations[n].reload.l4.name = "reload3_back";
	Locations[n].reload.l4.go = "Oranjestad_exit";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 1.0;
	
	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "Aruba_HouseInsideR1";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "House.";
	Locations[n].locators_radius.reload.reload5 = 1.0;

	Locations[n].reload.l6.name = "reload4";
	Locations[n].reload.l6.go = "Oranjestad_Store_02";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Store.";
	Locations[n].locators_radius.reload.reload4 = 1.0;
	Locations[n].reload.l6.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l6.goto_disable = 1; // Screwface: Disable Go-To location
	
	Locations[n].reload.l7.name = "reload6";
	Locations[n].reload.l7.go = "Oranjestad_Port_Captain_House";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "House.";
	Locations[n].locators_radius.reload.reload6 = 1.0;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l7.goto_disable = 1; // Screwface: Disable Go-To location	

	Locations[n].island = "Aruba"; // NK 04-08-29
	n = n + 1;
	
	// -------------------------------------------------


	Locations[n].filespath.models = "locations\Smuggler Lair\Exit";
	Locations[n].filespath.textures = "locations\HOLLAND";

	Locations[n].id = "Oranjestad_exit";
	locations[n].id.label = "Exit from #stown_name#";
	Locations[n].image = "Smuggler_Lair_Exit.tga";

	//Town sack
	Locations[n].townsack = "Oranjestad"; // NK 04-08-29

	//Sound
	locations[n].type = "jungle";
	locations[n].fastreload = "Oranjestad";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "SmLexit_l";
	Locations[n].models.always.exit = "SmLexit";
	Locations[n].models.always.grassPatch = "SmLexit_g";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan_3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";

	//Day
	Locations[n].models.day.charactersPatch = "SmLexit_p";
	Locations[n].models.day.fonar = "SmLexit_fd";
	//Night
	Locations[n].models.night.charactersPatch = "SmLexit_p";
	Locations[n].models.night.fonar = "SmLexit_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Aruba_Jungle_01";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 2;
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Oranjestad_port";
	Locations[n].reload.l2.emerge = "reload3_back";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload2 = 2;
	Locations[n].reload.l2.label = "#stown_name# port.";

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Aruba_Jungle_01";
	Locations[n].reload.l4.emerge = "reload3";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 2;
	Locations[n].reload.l4.label = "Jungle.";

	Locations[n].reload.l5.name = "reload2_back";
	Locations[n].reload.l5.go = "Oranjestad_port";
	Locations[n].reload.l5.emerge = "reload3_back";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].locators_radius.reload.reload2_back = 2;
	Locations[n].reload.l5.label = "#stown_name# port.";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Oranjestad_town";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "#stown_name#.";


	Locations[n].island = "Aruba"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Smuggler Lair\town";
	Locations[n].filespath.textures = "locations\HOLLAND";

	Locations[n].id = "Oranjestad_town";
	locations[n].id.label = "#stown_name#";
	Locations[n].image = "Smuggler_Lair_Town.tga";

	//Town sack
	Locations[n].townsack = "Oranjestad"; // NK 04-08-29

	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "Oranjestad";

	//Models
	//Always
	Locations[n].models.always.locators = "SmL_l";
	Locations[n].models.always.town = "SmL";
	Locations[n].models.always.grassPatch = "SmL_g";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan_3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	Locations[n].models.always.l4 = "plan_4";
	Locations[n].models.always.l4.level = 6;
	Locations[n].models.always.l4.tech = "LocationModelBlend";

	//Day
	Locations[n].models.day.charactersPatch = "SmL_p";
	Locations[n].models.day.fonar = "SmL_fd";
	Locations[n].models.day.jumppatch = "SmL_j";
	//Night
	Locations[n].models.night.charactersPatch = "SmL_p";
	Locations[n].models.night.fonar = "SmL_fn";
	Locations[n].models.night.jumppatch = "SmL_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oranjestad_exit";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload8";
	Locations[n].reload.l2.go = "Oranjestad_Tavern";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Tavern.";
	Locations[n].reload.l2.close_for_night  = 0;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l2.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l3.name = "reload6";
	Locations[n].reload.l3.go = "Oranjestad_Store";
	Locations[n].reload.l3.emerge = "locator2";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Store.";
	Locations[n].reload.l3.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l3.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l4.name = "reload7";
	Locations[n].reload.l4.go = "Oranjestad_townhall";
	Locations[n].reload.l4.emerge = "Reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Townhall.";
	Locations[n].reload.l4.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l4.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l15.name = "reload10";
	Locations[n].reload.l15.go = "Oranjestad_TailorsShop";
	Locations[n].reload.l15.emerge = "locator2";
	Locations[n].reload.l15.autoreload = "0";
	Locations[n].reload.l15.label = "Tailor's Shop.";
	Locations[n].reload.l15.close_for_night   = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l15.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].island = "Aruba"; // NK 04-08-29
	n = n + 1;
	
	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\ResidenceSmall1";	

	Locations[n].id = "Oranjestad_townhall";
	locations[n].id.label = "#stown_name# Townhall";
	Locations[n].image = "Inside_ResidenceSmall1.tga";
	//Town sack
	Locations[n].townsack = "Oranjestad"; // NK - "Oxbay";
	//Sound
	locations[n].type = "residence"; //"house";
	locations[n].fastreload = "Oranjestad";
	//Models
	//Always
	Locations[n].models.always.locators = "resp_l";
	Locations[n].models.always.l1 = "resp";
	Locations[n].models.always.window = "resp_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "resp_p";

	//Night
	Locations[n].models.night.charactersPatch = "resp_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\qcresp_";
	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Oranjestad_town";
	Locations[n].reload.l1.emerge = "reload7";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#."; // KK


	Locations[n].island = "Aruba"; // NK 04-08-29
	n = n + 1;
	
	//-------------------------------------------------
	Locations[n].id = "Oranjestad_Store";
	locations[n].id.label = "Store";
	Locations[n].filespath.models = "locations\inside\StoreSmall";
	Locations[n].image = "Inside_StoreSmall.tga";

	//Town sack
	Locations[n].townsack = "Oranjestad";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Oranjestad";
	//Models
	//Always
	Locations[n].models.always.locators = "SS_l";
	Locations[n].models.always.store = "SS";
	Locations[n].models.always.window = "SS_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "SS_p";
	Locations[n].models.day.fonar = "SS_fn";

	//Night
	Locations[n].models.night.charactersPatch = "SS_p";
	Locations[n].models.night.fonar = "SS_fn";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redss_";
	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "Oranjestad_town";
	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Aruba"; // NK 04-08-29
	n = n + 1;
	
	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\MediumTavern";

	Locations[n].id = "Oranjestad_tavern";
	locations[n].id.label = "#stown_name# tavern";
	Locations[n].image = "Inside_MediumTavern.tga";

	//Town sack
	Locations[n].townsack = "Oranjestad"; // NK 04-08-29

	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "Oranjestad";

	//Models
	//Always
	Locations[n].models.always.locators = "MT_l";
	Locations[n].models.always.l1 = "MT";
	Locations[n].models.always.window = "MT_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "MT_p";

	//Night
	Locations[n].models.night.charactersPatch = "MT_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\smumt_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oranjestad_town";
	Locations[n].reload.l1.emerge = "reload8";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Oranjestad_tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Room in #stown_name# tavern.";
	Locations[n].reload.l2.disable = true; // KK

	Locations[n].island = "Aruba"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Doubleflour_house";
	Locations[n].id = "Oranjestad_tavern_upstairs";
	locations[n].id.label = "Room in #stown_name# tavern."; // KK
	Locations[n].image = "Inside_Doubleflour_House_Room.tga";

	//Town sack
	Locations[n].townsack = "Oranjestad";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Oranjestad";
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F2_l";
	Locations[n].models.always.tavern = "LH_F2";
	Locations[n].models.always.window = "LH_F2_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Locations[n].models.always.env = "smalltavern_env";
	//Day
	Locations[n].models.day.charactersPatch = "LH_F2_p";

	//Night
	Locations[n].models.night.charactersPatch = "LH_F2_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\doulf2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oranjestad_tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# tavern."; // KK


	Locations[n].island = "Aruba"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_6";

	Locations[n].id = "Aruba_Jungle_01";
	locations[n].id.label = "#sisland_name# jungle";
	Locations[n].image = "Outside_Jungle_6.tga";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "Jungle06_l";
	Locations[n].models.always.jungle = "Jungle06";
	Locations[n].models.always.grassPatch = "JUNGLE06_g";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan_3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";

	//Day
	Locations[n].models.day.charactersPatch = "Jungle06_p";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle06_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Arawak_Village";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 2.5;
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Aruba_shore";
	Locations[n].reload.l2.emerge = "locator3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload2 = 2.5;
	Locations[n].reload.l2.label = "Rocky Cove.";

	if(GetCurrentPeriod() == PERIOD_EARLY_EXPLORERS)
	{
		Locations[n].reload.l3.name = "reload3";
		Locations[n].reload.l3.go = "Aruba_shore2";
		Locations[n].reload.l3.emerge = "reload2";
		Locations[n].reload.l3.autoreload = "1";
		Locations[n].locators_radius.reload.reload3 = 2.5;
		Locations[n].reload.l3.label = "Jungle.";

		Locations[n].reload.l5.name = "reload3_back";
		Locations[n].reload.l5.go = "Aruba_shore2";
		Locations[n].reload.l5.emerge = "reload2";
		Locations[n].reload.l5.autoreload = "1";
		Locations[n].locators_radius.reload.reload3_back = 3;
		Locations[n].reload.l5.label = "Jungle.";
	}
	else
	{
		Locations[n].reload.l3.name = "reload3";
		Locations[n].reload.l3.go = "Oranjestad_exit";
		Locations[n].reload.l3.emerge = "reload1";
		Locations[n].reload.l3.autoreload = "1";
		Locations[n].locators_radius.reload.reload3 = 2.5;
		Locations[n].reload.l3.label = "Jungle.";

		Locations[n].reload.l5.name = "reload3_back";
		Locations[n].reload.l5.go = "Oranjestad_exit";
		Locations[n].reload.l5.emerge = "reload1";
		Locations[n].reload.l5.autoreload = "1";
		Locations[n].locators_radius.reload.reload3_back = 3;
		Locations[n].reload.l5.label = "Jungle.";
	}

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Aruba_shore";
	Locations[n].reload.l4.emerge = "locator3";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].locators_radius.reload.reload2_back = 2.5;
	Locations[n].reload.l4.label = "Rocky Shore.";

	Locations[n].reload.l6.name = "reload1_back";
	Locations[n].reload.l6.go = "Arawak_Village";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 2.5;
	Locations[n].reload.l6.label = "Jungle.";

	Locations[n].island = "Conceicao"; // NK 04-08-29
	n = n + 1;
	
	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Shore_4";

	Locations[n].id = "Aruba_shore";
	locations[n].id.label = "Rocky Cove."; // KK
	locations[n].worldmap = "ArubaShore";
	Locations[n].image = "Outside_Shore_4.tga";
	Locations[n].name = "Rocky Cove";
	//Sound
	locations[n].type = "seashore";

	//Town sack
	Locations[n].townsack = "Oranjestad"; // KK

	//Models
	//Always
	Locations[n].models.always.locators = "Shore04_l";
	Locations[n].models.always.shore = "Shore04";
	Locations[n].models.always.shore.foam = "1";
	Locations[n].models.always.seabed = "Shore04_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "Shore04_g";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan_3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";

	//Day
	Locations[n].models.day.charactersPatch = "Shore04_p";
	//Night
	Locations[n].models.night.charactersPatch = "Shore04_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l5.name = "rock1_back";
	Locations[n].reload.l5.go = "Aruba_Dungeon";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].locators_radius.reload.rock1_back = 1.5;
	Locations[n].reload.l5.label = "Arawak Burialground.";

	Locations[n].reload.l1.name = "locator3";
	Locations[n].reload.l1.go = "Aruba_Jungle_01";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.locator3 = 3;
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l3.name = "locator3_back";
	Locations[n].reload.l3.go = "Aruba_Jungle_01";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.locator3_back = 1;
	Locations[n].reload.l3.label = "Jungle.";

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Aruba";
	Locations[n].reload.l2.emerge = "reload_3";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.boat = 9.0;
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";


	Locations[n].island = "Aruba"; // NK 04-08-29
	n = n + 1;
	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Pirate Fort";
	Locations[n].filespath.textures = "locations\NATIVES";

	Locations[n].id = "Arawak_Village";
	locations[n].id.label = "Arawak Village";
	Locations[n].image = "Pirate_Fort_Native.tga";

	//Town sack
	Locations[n].townsack = "Pirate Fort"; // NK 04-08-29

	//Sound
	locations[n].type = "KR_jungle";

	//Models
	//Always
	Locations[n].models.always.locators = "PiF_l";
	Locations[n].models.always.town = "PiF";
	Locations[n].models.always.grasspatch = "PiF_g";
	Locations[n].models.always.l1 = "pif_b01";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "pif_b02";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "pif_b03";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	Locations[n].models.always.l4 = "pif_b04";
	Locations[n].models.always.l4.level = 6;
	Locations[n].models.always.l4.tech = "LocationModelBlend";


	//Day
	Locations[n].models.day.fonar = "PiF_fd";
	Locations[n].models.day.charactersPatch = "PiF_p";
	//Night
	Locations[n].models.night.fonar = "PiF_fn";
	Locations[n].models.night.charactersPatch = "PiF_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Aruba_Jungle_01";
	Locations[n].reload.l1.emerge = "Reload1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].reload.l1.autoreload = 1;
	Locations[n].locators_radius.reload.reload1 = 1;

	Locations[n].reload.l5.name = "Reload1_back";
	Locations[n].reload.l5.go = "Aruba_Jungle_01";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].reload.l5.autoreload = 1;
	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].reload.l2.name = "Reload5";
	Locations[n].reload.l2.go = "Indian_house";
	Locations[n].reload.l2.emerge = "Reload1";
	Locations[n].reload.l2.label = "Chief's House.";

	Locations[n].island = "Aruba"; // NK 04-08-29
	n = n + 1;

	// Oranjestad Tailor
	Locations[n].id = "Oranjestad_TailorsShop";
	Locations[n].id.label = "Tailor's Shop.";
	Locations[n].image = "Inside_StoreSmall.tga";

	//Town sack
	Locations[n].townsack = "Oranjestad";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Oranjestad";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Inside\StoreSmall";
	Locations[n].models.always.locators = "SS_l";
	Locations[n].models.always.store = "SS";
	Locations[n].models.always.window = "SS_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch   = "SS_p";
	Locations[n].models.day.fonar			 = "SS_fn";

	//Night
	Locations[n].models.night.charactersPatch = "SS_p";
	Locations[n].models.night.fonar		   = "ss_fn";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\oxss_";

	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "Oranjestad_town";
	Locations[n].reload.l1.emerge = "reload10";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";
	Locations[n].locators_radius.reload.locator2 = 0.7;

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Aruba"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "Indian_house";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\IndianHome";
	Locations[n].image = "Inside_IndianHome.tga";

	//Town sack
	Locations[n].townsack = "Aruba";

	//Sound
	locations[n].type = "residence";
	//Models
	//Always
	Locations[n].models.always.locators = "sh_l";
	Locations[n].models.always.house = "sh";
	Locations[n].models.always.window = "sh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "sh_p";

	//Night
	Locations[n].models.night.charactersPatch = "sh_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\ffsh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Arawak_Village";
	Locations[n].reload.l1.emerge = "Reload5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Arawak_Village";
	Locations[n].locators_radius.reload.reload1 = 0.8;


	Locations[n].island = "Aruba"; // NK 04-08-29
	n = n + 1;
	
	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\mh3";
	Locations[n].id = "Aruba_HouseInsideR1";
	locations[n].id.label = "House.";
	Locations[n].image = "Inside_mh3.tga";

	//Town sack
	Locations[n].townsack = "Aruba";

	//Sound
	locations[n].type = "house";
	//Models
	//Always
	Locations[n].models.always.locators = "MH3_l";
	Locations[n].models.always.house = "MH3";
	//Locations[n].models.always.env = "smalltavern_env";
	Locations[n].models.always.window = "MH3_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "MH3_p";

	//Night
	Locations[n].models.night.charactersPatch = "MH3_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\doumh3_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oranjestad_port";
	Locations[n].reload.l1.emerge = "reload5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].island = "Aruba"; // NK 04-08-29
	n = n + 1;
//JRH
	//-------------------------------------------------
	Locations[n].id = "Oranjestad_Store_02";
	locations[n].id.label = "Store";
	Locations[n].filespath.models = "locations\inside\HutRoundInside";
	Locations[n].image = "Inside_HutRoundInside_Store.tga";

	//Town sack
	Locations[n].townsack = "Oranjestad";

	//Sound
	locations[n].type = "indian_shop";
	locations[n].fastreload = "Oranjestad";

	//Models
	//Always
	Locations[n].models.always.locators = "HutRoundInside_locators";
	Locations[n].models.always.store = "HutRoundInside";
	Locations[n].models.always.l1 = "chimney";
	Locations[n].models.always.l2 = "wood4";

	//Day
	Locations[n].models.day.charactersPatch = "HutRoundInside_patch";
	//Locations[n].models.day.fonar = "SS_fn";

	//Night
	Locations[n].models.night.charactersPatch = "HutRoundInside_patch";
	//Locations[n].models.night.fonar = "SS_fn";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	
	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Oranjestad_port";
	Locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload1_back = 0.8;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "carpet4";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "textile4";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "jars";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Aruba"; // NK 04-08-29
	n = n + 1;	
	
	//Levis:
	//-------------------------------------------------
	Locations[n].id = "Oranjestad_Port_Captain_House";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\HutRoundInside";
	Locations[n].image = "Inside_HutRoundInside.tga";

	//Town sack
	Locations[n].townsack = "Oranjestad";

	//Sound
	locations[n].type = "house";

	//Models
	//Always
	Locations[n].models.always.locators = "HutRoundInside2_locators";
	Locations[n].models.always.house = "HutRoundInside";

	//Day
	Locations[n].models.day.charactersPatch = "HutRoundInside_patch";
	//Locations[n].models.day.fonar = "SS_fn";

	//Night
	Locations[n].models.night.charactersPatch = "HutRoundInside_patch";
	//Locations[n].models.night.fonar = "SS_fn";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	
	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Oranjestad_port";
	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload1_back = 0.8;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "carpet4";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "jars";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "jars";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Aruba"; // NK 04-08-29
	n = n + 1;	
	
	// ----------------- Aruba_Dungeon --------------------
	Locations[n].filespath.models = "locations\Inside\Dungeon_1";
	Locations[n].id = "Aruba_Dungeon";
	Locations[n].image = "Inside_Dungeon_1.tga";
	Locations[n].monsters = "1";
	locations[n].id.label = "Arawak Burialground";

	//Sound
	locations[n].type = "Dungeon";
	//Models
	//Always
	Locations[n].models.always.locators = "d01_l";
	Locations[n].models.always.house = "d01";
	//Day
	Locations[n].models.day.charactersPatch = "d01_p";
	//Night
	Locations[n].models.night.charactersPatch = "d01_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	LAi_LocationFantomsGen(&locations[n], true);

	//Reload map
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Aruba_shore";
	Locations[n].reload.l2.emerge = "rock1_back";
	Locations[n].reload.l2.autoreload = "1";

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Aruba_shore";
	Locations[n].reload.l3.emerge = "rock1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.reload2_back = 1.5;

/*
	Locations[n].reload.l12.name = "reloadc4";
	Locations[n].reload.l12.go = "Marigot_dungeon";
	Locations[n].reload.l12.emerge = "reload2";
*/

	Locations[n].items.randitem1 = "blade20";

	Locations[n].island = "Aruba";
	n = n + 1;


	//  -------- Sandy Beach -----------------------------------------
	Locations[n].id = "Aruba_shore2";
	locations[n].id.label = "Sandy Beach."; // KK
	locations[n].worldmap = "ArubaShore2";
	Locations[n].filespath.models = "locations\Outside\Shore_6";
	Locations[n].image = "Outside_Shore_6.tga";
	Locations[n].name = "Sandy Beach";
	//Sound
	locations[n].type = "seashore";

	//Models
	//Always
	Locations[n].models.always.locators = "Shore06_l";
	Locations[n].models.always.shore = "Shore06";
	Locations[n].models.always.shore.foam = "1";
	Locations[n].models.always.seabed = "Shore06_sb";
	Locations[n].models.always.seabed.foam = "1";
	//Locations[n].models.always.grassPatch = "Shore06_g";

	//Day
	Locations[n].models.day.charactersPatch = "Shore06_p";
	//Night
	Locations[n].models.night.charactersPatch = "Shore06_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Aruba_Jungle_01";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 2;
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l3.name = "Reload2_back";
	Locations[n].reload.l3.go = "Aruba_Jungle_01";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.Reload2_back = 5;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Aruba";
	Locations[n].reload.l2.emerge = "reload_1";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 11.0;

	Locations[n].island = "Aruba";
	n = n + 1;
	// -------------------------------------------------
}

	