void LocationInitTurks(ref n)
{
	Locations[n].filespath.models = "locations\Town_GrandTurk\Port";	
	Locations[n].image = "Town_Grand_Turk.tga";

	Locations[n].id = "Turks_port";
	locations[n].id.label = "#stown_name# port";
	locations[n].worldmap = "Grand Turk";
	//Sound
	locations[n].type = "port";
	Locations[n].townsack = "Grand Turk"; 
	locations[n].fastreload = "Grand_Turk";
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	Locations[n].models.always.locators = "Margarita_locators";
	Locations[n].models.always.l1 = "Margarita";
	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.sb = "Margarita_sb";
	Locations[n].models.always.sb.foam = "1";
	Locations[n].models.always.grassPatch = "Margarita_grass";

	Locations[n].models.always.academy = "academy_destroyed";
	Locations[n].models.always.academy.locator.group = "upgrades";
	Locations[n].models.always.academy.locator.name = "Academy";

	Locations[n].models.always.huts = "huts_destroyed";
	Locations[n].models.always.huts.locator.group = "upgrades";
	Locations[n].models.always.huts.locator.name = "Huts";

	Locations[n].models.always.shipyard = "shipyard_destroyed";
	Locations[n].models.always.shipyard.locator.group = "upgrades";
	Locations[n].models.always.shipyard.locator.name = "Shipyard";

	Locations[n].models.always.Fishingpier = "Fishingpier1";
	Locations[n].models.always.Fishingpier.locator.group = "upgrades";
	Locations[n].models.always.Fishingpier.locator.name = "Fishingpier";

	Locations[n].models.always.mill = "Mill1";
	Locations[n].models.always.mill.locator.group = "upgrades";
	Locations[n].models.always.mill.locator.name = "mill";

	Locations[n].models.always.mill_movie = "mill_movie";
	Locations[n].models.always.mill_movie.locator.group = "upgrades";
	Locations[n].models.always.mill_movie.locator.name = "Mill_movie";
	Locations[n].models.always.mill_movie.rotate.x = 0.0;
	Locations[n].models.always.mill_movie.rotate.y = 0.0;
	Locations[n].models.always.mill_movie.rotate.z = 1.0;
	Locations[n].models.always.mill_movie.tech = "dLightModel";

	Locations[n].models.always.l9 = "Margarita_gate";
//	Locations[n].models.always.l9 = "Margarita_gatebroken";
//	Locations[n].models.always.l2 = "Margarita_ships";

	Locations[n].models.always.l3 = "fontain1";
	Locations[n].models.always.l3.uvslide.u0 = 0.0005;
	Locations[n].models.always.l3.uvslide.v0 = 0.2;
	Locations[n].models.always.l3.level = 999;
	Locations[n].models.always.l3.tech = "LocationWaterFall";
	Locations[n].models.always.l4 = "fontain2";
	Locations[n].models.always.l4.uvslide.u0 = 0.04;
	Locations[n].models.always.l4.uvslide.v0 = 0.01;
	Locations[n].models.always.l4.level = 999;
	Locations[n].models.always.l4.tech = "LocationWaterFall";
	Locations[n].models.always.l5 = "fontain1";
	Locations[n].models.always.l5.uvslide.u0 = 0.0005;
	Locations[n].models.always.l5.uvslide.v0 = 0.2;
	Locations[n].models.always.l5.level = 999;
	Locations[n].models.always.l5.tech = "LocationWaterFall";
	Locations[n].models.always.l6 = "fontain2";
	Locations[n].models.always.l6.uvslide.u0 = 0.04;
	Locations[n].models.always.l6.uvslide.v0 = 0.01;
	Locations[n].models.always.l6.level = 999;
	Locations[n].models.always.l6.tech = "LocationWaterFall";

	Locations[n].models.always.l7 = "church1";
	Locations[n].models.always.l8 = "storehouse1";
	Locations[n].models.always.l10 = "";		//watergate later

	//Day
	Locations[n].models.day.charactersPatch = "Margarita_patch_day";
//	Locations[n].models.day.charactersPatch = "Margarita_patch_roof";
	Locations[n].models.day.jumpPatch = "Margarita_jump_patch";
	Locations[n].models.day.fonar = "Margarita_fd";
	Locations[n].models.day.rinok = "Margarita_rinok";
	//Night
	Locations[n].models.night.charactersPatch = "Margarita_patch_night";
//	Locations[n].models.night.charactersPatch = "Margarita_patch_roof";
	Locations[n].models.night.jumpPatch = "Margarita_jump_patch";
	Locations[n].models.night.fonar = "Margarita_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.5;
	//Reload map

	Locations[n].reload.l111.name = "reload1_back";
	Locations[n].reload.l111.go = "Turks";
	Locations[n].reload.l111.emerge = "reload_1";
	Locations[n].reload.l111.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l111.label = "Ship.";
	else
		Locations[n].reload.l111.label = "Sea.";
	

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Turks";
	Locations[n].reload.l1.emerge = "reload_1";
	Locations[n].reload.l1.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l1.label = "Ship.";
	else
		Locations[n].reload.l1.label = "Sea.";
	

	Locations[n].reload.l3.name = "reload3_back";
	Locations[n].reload.l3.go = "Turks_townhall";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Enter.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l3.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l4.name = "reload4_back";
	Locations[n].reload.l4.go = "Turks_Tavern";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Tavern.";
	Locations[n].locators_radius.reload.reload4_back = 1.0;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l4.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l5.name = "reload5_back";
	Locations[n].reload.l5.go = "Grand_Turk_Shipyard";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Shipyard.";
	Locations[n].reload.l5.close_for_night = 1;
	Locations[n].locators_radius.reload.reload5_back = 1.0;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l5.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l7.name = "reload7_back";
	Locations[n].reload.l7.go = "Turks_church";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Shipyard.";
	Locations[n].reload.l7.close_for_night = 1;
	Locations[n].locators_radius.reload.reload7_back = 1.0;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l7.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l10.name = "houseS1";
	Locations[n].reload.l10.go = "Turks_store";
	Locations[n].reload.l10.emerge = "reload1";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "Store.";
	Locations[n].reload.l10.close_for_night = 1;
	Locations[n].locators_radius.reload.houseS1 = 1.0;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l10.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l11.name = "gate_back";
	Locations[n].reload.l11.go = "Turks_Jungle_03";
	Locations[n].reload.l11.emerge = "reload2";
	Locations[n].reload.l11.autoreload = "0";
	Locations[n].reload.l11.label = "Jungle.";
	Locations[n].locators_radius.reload.gate_back = 1.0;

	// --> RobC/Alan_Smithee Blacksmith mod
	if (ENABLE_WEAPONSMOD)
	{
		Locations[n].reload.l13.name = "houseSp3";
		Locations[n].reload.l13.go = "Turks_blacksmith";
		Locations[n].reload.l13.emerge = "reload1";
		Locations[n].reload.l13.autoreload = "0";
		Locations[n].reload.l13.label = "Blacksmith.";
		Locations[n].reload.l13.close_for_night = 1;
		Locations[n].locators_radius.reload.houseSp3 = 1.0;
		if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l13.goto_disable = 1; // Screwface: Disable Go-To location
	}
	// RobC/Alan_Smithee Blacksmiths <--

	Locations[n].reload.l14.name = "houseS4";
	Locations[n].reload.l14.go = "Turks_library";
	Locations[n].reload.l14.emerge = "reload1";
	Locations[n].reload.l14.autoreload = "0";
	Locations[n].reload.l14.label = "Library.";
	Locations[n].reload.l14.close_for_night = 1;
	Locations[n].locators_radius.reload.houseS4 = 1.0;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l14.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l15.name = "houseS5";
	Locations[n].reload.l15.go = "Turks_TailorsShop";
	Locations[n].reload.l15.emerge = "locator2";
	Locations[n].reload.l15.autoreload = "0";
	Locations[n].reload.l15.label = "Tailor's Shop.";
	Locations[n].reload.l15.close_for_night   = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l15.goto_disable = 1; // Screwface: Disable Go-To location
//JRH -->	
	Locations[n].reload.l16.name = "reload_sewer";
	Locations[n].reload.l16.go = "Turks_sewer";
	Locations[n].reload.l16.emerge = "reload2";
	Locations[n].reload.l16.autoreload = "1";			//1 first time
	Locations[n].locators_radius.reload.reload_sewer = 0.0;		//1.0 later
	Locations[n].reload.l16.disable = 1;

	Locations[n].locators_radius.goto.P_goto11 = 1.0;
	Locations[n].locators_radius.goto.steplockL = 0.2;
	Locations[n].locators_radius.goto.steplockM = 0.2;
	Locations[n].locators_radius.goto.steplockR = 0.2;
	Locations[n].locators_radius.goto.stepbackL = 0.3;
	Locations[n].locators_radius.goto.stepbackM = 0.3;
	Locations[n].locators_radius.goto.stepbackR = 0.3;
	Locations[n].locators_radius.goto.waterstop = 0.0;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "hatch11";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "steplock";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "steplock";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "steplock";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "hatch11_S";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "hatch11_T";
//<-- JRH
	Locations[n].island = "Turks"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Jungle_Church_inside";

	Locations[n].id = "Turks_church";
	locations[n].id.label = "Brethren of the Coast";
	Locations[n].image = "Inside_Turks_Church.tga";

	//Sound
	locations[n].type = "Turks_church";
	//Models
	//Always
	Locations[n].models.always.locators = "church01_locators_Turks";
	Locations[n].models.always.city = "Church01";
	locations[n].models.always.l1 = "ship_up";
	locations[n].models.always.l2 = "rope_up";
	locations[n].models.always.l3 = "collectbox";

	Locations[n].models.always.window = "Church01_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Church01_patch";
	//Night
	Locations[n].models.night.charactersPatch = "Church01_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";	
	Locations[n].models.back = "back\turkC_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Turks_port";
	Locations[n].reload.l1.emerge = "reload7";
	Locations[n].reload.l1.label = "";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 1.0;
	
	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Turks";
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\MediumTavern";

	Locations[n].id = "Turks_Tavern";
	locations[n].id.label = "#stown_name# Tavern";
	Locations[n].image = "Inside_MediumTavern.tga";

	//Town sack
	Locations[n].townsack = "Grand Turk"; // NK 04-08-29

	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "Grand_Turk";
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
	Locations[n].models.back = "back\turkC_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Turks_port";
	Locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	//fake reload_to_room
	Locations[n].reload.l2.name = "reload2";//MAXIMUS: was "to_room"
	Locations[n].reload.l2.go = "Turks_tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Room.";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Turks_Tavern_kitchen";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Tavern.";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Turks"; // NK 04-08-29
	n = n + 1;
	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Doubleflour_house";

	Locations[n].id = "Turks_tavern_upstairs";
	locations[n].id.label = "Room in #stown_name# tavern";	//spell-checked by KAM
	Locations[n].image = "Inside_Doubleflour_House_Room.tga";

	//Town sack
	Locations[n].townsack = "Grand Turk";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Grand_Turk";
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F2_l";
	Locations[n].models.always.house = "LH_F2";
	Locations[n].models.always.window = "LH_F2_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "LH_F2_p";

	//Night
	Locations[n].models.night.charactersPatch = "LH_F2_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\colf2_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Turks_Tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Tavern.";

	Locations[n].island = "Turks"; // NK 04-08-29
	n = n + 1;
//JRH
	//  -------------------------------------------------
	Locations[n].id = "Turks_tavern_kitchen";
	locations[n].id.label = "Kitchen - staff only";
	Locations[n].filespath.models = "locations\inside\flamhouse";
	Locations[n].image = "wr_kitchen.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Legrands_house";
	
	//Models
	//Always
	Locations[n].models.always.locators = "FlamHouse_locators_Turks";
	Locations[n].models.always.tavern = "Flamhouse";
	//locations[n].models.always.l1 = "lever1_up";
	//locations[n].models.always.l2 = "steplock_v";
	//Locations[n].models.always.l1 = "lever_base";

	Locations[n].models.always.window = "FlamHouse_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "FlamHouse_patch";

	//Night
	Locations[n].models.night.charactersPatch = "FlamHouse_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\turkK_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Turks_port";
	Locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 0.5;
	Locations[n].reload.l1.disable = 1;			

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Turks_tavern";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 0.5;
	
	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "Turks_tavern_bedroom";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].locators_radius.reload.reload5 = 0.5;
	Locations[n].reload.l5.disable = 1;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "door_N03";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "door_N03";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "door_N03";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "door_MdTav";

	Locations[n].locators_radius.randitem.randitem5 = 0.1;
	Locations[n].items.randitem5 = "door_MdTav";

	Locations[n].locators_radius.randitem.randitem6 = 0.1;
	Locations[n].items.randitem6 = "door_MdTav";

	Locations[n].locators_radius.box.box1 = 1.0;

	Locations[n].island = "Turks";
	LAi_LocationFightDisable(&Locations[n], true);
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\JinoRoom";

	Locations[n].id = "Turks_tavern_bedroom";
	locations[n].id.label = "Private";
	Locations[n].image = "Inside_Shipyard3.tga";

	//Town sack
	Locations[n].townsack = "Grand Turk";

	//Sound
	locations[n].type = "Legrands_house";
	
	//Models
	//Always
	Locations[n].models.always.locators = "JinoRoom_locators_Turks";
	Locations[n].models.always.l1 = "JinoRoom";
	Locations[n].models.always.window = "JinoRoom_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "JinoRoom_patch";

	//Night
	Locations[n].models.night.charactersPatch = "JinoRoom_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\turkJ_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Turks_tavern_kitchen";
	Locations[n].reload.l1.emerge = "Reload5";
	Locations[n].reload.l1.autoreload = "0";
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].locators_radius.box.box4 = 0.7;

	Locations[n].island = "Turks"; // NK 04-08-29
	n = n + 1;


















	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Shipyard3";

	Locations[n].id = "Grand_Turk_Shipyard";
	locations[n].id.label = "#stown_name# Shipyard";
	Locations[n].image = "Inside_Shipyard3.tga";

	//Town sack
	Locations[n].townsack = "Grand Turk";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Grand_Turk";
	//Models
	//Always
	Locations[n].models.always.locators = "sh03_l";
	Locations[n].models.always.l1 = "Sh03";
	Locations[n].models.always.window = "sh03_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "Sh03_p";

	//Night
	Locations[n].models.night.charactersPatch = "Sh03_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\shp_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Turks_port";
	Locations[n].reload.l1.emerge = "Reload5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Turks"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\LargeStore";
	Locations[n].image = "Inside_LargeStore.tga";

	Locations[n].id = "Turks_Store";
	locations[n].id.label = "#stown_name# store";

	//Town sack
	Locations[n].townsack = "Grand Turk";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Grand_Turk";
	//Models
	//Always
	Locations[n].models.always.locators = "LS_l";
	Locations[n].models.always.tavern = "LS";
	//Locations[n].models.always.env = "largestore_env";
	Locations[n].models.always.window = "LS_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	Locations[n].models.always.fonar = "ls_fn";

	//Day
	Locations[n].models.day.charactersPatch = "LS_p";

	//Night
	Locations[n].models.night.charactersPatch = "LS_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\turkT_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Turks_port";
	Locations[n].reload.l1.emerge = "houseS1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Turks"; // NK 04-08-29
	n = n + 1;

	// ******************************************************************************************

	// Tailor mod
	Locations[n].id = "Turks_TailorsShop";
	Locations[n].id.label = "Tailor's Shop.";
	Locations[n].image = "Inside_StoreSmall.tga";

	//Town sack
	Locations[n].townsack = "Grand Turk";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Grand_Turk";
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
	Locations[n].models.back = "back\turkT_";

	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "Turks_port";
	Locations[n].reload.l1.emerge = "houseS5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";
	Locations[n].locators_radius.reload.locator2 = 0.7;

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Turks"; // NK 04-08-29
	n = n + 1;

	// ******************************************************************************************

	Locations[n].filespath.models = "locations\Inside\apothecary";	

	Locations[n].id = "Turks_library";
	locations[n].id.label = "Library";
	Locations[n].image = "Inside_Library.tga"; // KK
	//Town sack
	Locations[n].townsack = "Grand Turk"; 
	//Sound
	locations[n].type = "residence"; 
	locations[n].fastreload = "Grand_Turk";
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
	Locations[n].models.back = "back\turkT_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Turks_port";
	Locations[n].reload.l1.emerge = "houseS4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";
	Locations[n].locators_radius.reload.locator2 = 0.7;

	Locations[n].island = "Turks"; // NK 04-08-29

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\inside\Residence4";

	Locations[n].id = "Turks_townhall";
	locations[n].id.label = "#stown_name# Townhall";
	Locations[n].image = "Inside_Residence4.tga";

	//Town sack
	Locations[n].townsack = "Grand Turk";

	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Grand_Turk";
	//Models
	//Always
	Locations[n].models.always.locators = "Res04_l";
	Locations[n].models.always.l1 = "Res04";
	Locations[n].models.always.window = "Res04_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "Res04_p";

	//Night
	Locations[n].models.night.charactersPatch = "Res04_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\turkT_";

	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Turks_port";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# Residence";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Turks"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Jungle_6";

	Locations[n].id = "Turks_Jungle_03";
	locations[n].id.label = "#sisland_name# jungle";
	Locations[n].image = "Outside_Jungle_6.tga";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "Jungle06_l_Turks";
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
	Locations[n].models.always.l4 = "town_walls";


	Locations[n].models.always.gate = "Margarita_gate";
	Locations[n].models.always.gate.locator.group = "upgrades";
	Locations[n].models.always.gate.locator.name = "gate";

//	Locations[n].models.always.gatebroken = "Margarita_gatebroken";
	Locations[n].models.always.gatebroken.locator.group = "upgrades";
	Locations[n].models.always.gatebroken.locator.name = "gatebroken";

	//Day
	Locations[n].models.day.charactersPatch = "Jungle06_p";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle06_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Turks_port";
	Locations[n].reload.l2.emerge = "gate_back";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 2.5;
	Locations[n].reload.l2.label = "Jungle.";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Turks_Jungle_02";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.reload3 = 2.5;
	Locations[n].reload.l3.label = "Jungle.";

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Turks_port";
	Locations[n].reload.l4.emerge = "gate_back";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].locators_radius.reload.reload2_back = 2.5;
	Locations[n].reload.l4.label = "Jungle.";
	
	Locations[n].reload.l5.name = "reload3_back";
	Locations[n].reload.l5.go = "Turks_Jungle_02";
	Locations[n].reload.l5.emerge = "reload3";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].locators_radius.reload.reload3_back = 3;
	Locations[n].reload.l5.label = "Jungle.";

	Locations[n].reload.l6.name = "reload1_back";
	Locations[n].reload.l6.go = "Turks_old_Fort";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Old Fort.";
	Locations[n].locators_radius.reload.reload1_back = 3.0;
	Locations[n].reload.l6.disable = 0;

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "lamp";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "lamp";

	Locations[n].island = "Turks"; // NK 04-08-29
	n = n + 1;
	// -------------------------------------------------
	Locations[n].filespath.models = "locations\outside\Canyon";

	Locations[n].id = "Turks_Jungle_04";
	locations[n].id.label = "#sisland_name# canyon";
	Locations[n].image = "Outside_Canyon.tga";

	//Town sack
	Locations[n].townsack = "Turks";

	//Sound
	locations[n].type = "Jungle";
//	locations[n].fastreload = "Turks";
	//Models
	//Always
	Locations[n].models.always.locators = "rift_l";
	Locations[n].models.always.rift = "rift";
	Locations[n].models.always.grassPatch = "rift_g";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";

	//Day
	Locations[n].models.day.charactersPatch = "rift_p";
	Locations[n].models.day.fonar = "rift_fd";
	//Night
	Locations[n].models.night.charactersPatch = "rift_p";
	Locations[n].models.night.fonar = "rift_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Turks_old_Fort";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Old Fort.";
	Locations[n].locators_radius.reload.reload1 = 1.0;
	Locations[n].reload.l1.disable = 0;

	Locations[n].reload.l2.name = "reload6_back";
	Locations[n].reload.l2.go = "Turks_Jungle_03";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload6_back = 3.0;

	Locations[n].reload.l3.name = "reload6";
	Locations[n].reload.l3.go = "Turks_Jungle_03";
	Locations[n].reload.l3.emerge = "reload1_back";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].locators_radius.reload.Reload6 = 3.0;

	//Locations[n].reload.l3.name = "reload4";
	//Locations[n].reload.l3.go = "Oxbay_Mine";
	//Locations[n].reload.l3.emerge = "reload1";
	//Locations[n].reload.l3.autoreload = "1";
	//Locations[n].reload.l3.label = "Mines.";

	//Locations[n].reload.l4.name = "reload5";
	//Locations[n].reload.l4.go = "Mines_commander_house";
	//Locations[n].reload.l4.emerge = "reload1";
	//Locations[n].reload.l4.autoreload = "0";
	//Locations[n].reload.l4.label = "Mines Office.";

	Locations[n].island = "Turks"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

    ///////////////////////////////////////////////////////
    Locations[n].filespath.models = "locations\Fort_Inside\FortVRight";

    Locations[n].id = "Turks_old_Fort";
	locations[n].id.label = "#stown_name# Fort";
	Locations[n].image = "Fort_Inside_FortVRight.tga";

	//Town sack
	locations[n].townsack = "Grand Turk";

	//Sound
	locations[n].type = "jungle";
//	locations[n].fastreload = "Grand_Turk";
	//LAi_LocationMonstersGen(&locations[n], true);
	//LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "FortVRight_locators";
	Locations[n].models.always.FortVRight = "FortVRight";
    Locations[n].models.always.grassPatch = "FortVRight_grass";
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	//Locations[n].models.always.attack = "FortVRight_attack";
	Locations[n].models.always.rock = "FortVRight_rock";
	Locations[n].models.always.sb = "FortVRight_sb";
	Locations[n].models.always.fd = "FortVRight_fd";
	Locations[n].models.always.fn = "FortVRight_fn";
	//Locations[n].models.always.lAttack = "FortVRight_lAttack";
    //Locations[n].models.always.patch = "FortVRight_patch";

	//Day
	Locations[n].models.day.charactersPatch = "FortVRight_patch";
	//Locations[n].models.day.fonar = "FortVRight_fd";
	//Night
	Locations[n].models.night.charactersPatch = "FortVRight_patch";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

    //Reloadmap
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Turks_Jungle_03";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle";
	Locations[n].locators_radius.reload.reload1_back = 3.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Turks_Fort_Office";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Office";
	Locations[n].locators_radius.reload.reload1_back = 1;

	Locations[n].island = "Turks";
   	n = n + 1;
//JRH armory
	//------------------------------------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\armory";	

	Locations[n].id = "Turks_Fort_Office";
	locations[n].id.label = "Armory";
	Locations[n].image = "Inside_Armory.tga";
	//Sound
	locations[n].type = "Fort_Moultrie_inside";
	//Models
	//Always
	Locations[n].models.always.locators = "armory_locators";
	Locations[n].models.always.l1 = "armory";
	Locations[n].models.always.l2 = "armory_lamps";

	//Day
	Locations[n].models.day.charactersPatch = "armory_patch";

	//Night
	Locations[n].models.night.charactersPatch = "armory_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	
	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Turks_Old_Fort";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# Fort";

	Locations[n].island = "Turks"; // NK 04-08-29
	n = n + 1;

//---------------------------------------------------------------------
	Locations[n].filespath.models = "locations\outside\Mayak";

	Locations[n].id = "Turks_Lighthouse";
	Locations[n].name = "Old lighthouse";
	locations[n].id.label = "Turtle Bay."; // KK
//	locations[n].worldmap = "TShore 2";
	Locations[n].image = "Outside_Mayak.tga";
	//Sound
	locations[n].type = "seashore";
	//Models
	//Always
	Locations[n].models.always.locators = "mayak_l";
	Locations[n].models.always.shore = "mayak";
	Locations[n].models.always.shore.foam = "1";
	Locations[n].models.always.seabed = "Mayak_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "Mayak_g";

	//Day
	Locations[n].models.day.charactersPatch = "mayak_p";
	Locations[n].models.day.fonar = "Mayak_fd";
	//Night
	Locations[n].models.night.charactersPatch = "mayak_p";
	Locations[n].models.night.fonar = "Mayak_fn";
	Locations[n].models.night.window = "Mayak_win";
	Locations[n].models.night.light = "Mayak_fl";
	Locations[n].models.night.light.level = 80;
	Locations[n].models.night.light.tech = "LighthouseLight";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Turks_Jungle_02";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1 = 3.0;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Turks_Jungle_02";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 3.0;

	Locations[n].reload.l5.name = "reload2";
	Locations[n].reload.l5.go = "Turks_House1_Inside";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "House.";
	Locations[n].locators_radius.reload.Reload1 = 3.0;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Turks";
	Locations[n].reload.l2.emerge = "Reload_2";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 12.0;

	//Locations[n].reload.l4.name = "reload5";
	//Locations[n].reload.l4.go = "";
	//Locations[n].reload.l4.emerge = "Reload1";
	//Locations[n].reload.l4.autoreload = "0";
	//Locations[n].reload.l4.label = "Lighthouse Inside.";

	Locations[n].island = "Turks"; // NK 04-08-29
	n = n + 1;
	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\pirateresidence";	

	Locations[n].id = "Turks_House1_Inside";
	locations[n].id.label = "Inside House";
	Locations[n].image = "Inside_PirateResidence.tga";
	//Sound
	locations[n].type = "Residence"; //"house";
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
	Locations[n].models.back = "back\juch_";
	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Turks_Lighthouse";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Exit.";

	Locations[n].island = "Turks"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Jungle_7";

	Locations[n].id = "Turks_Jungle_02";
	locations[n].id.label = "#sisland_name# jungle";
	Locations[n].image = "Outside_Jungle_7.tga";
	//Sound
	locations[n].type = "Jungle";
	//LAi_LocationMonstersGen(&locations[n], true);
	//LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "Jungle07_l";
	Locations[n].models.always.jungle = "Jungle07";
	Locations[n].models.always.grassPatch = "JUNGLE07_g";
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
	Locations[n].models.day.charactersPatch = "Jungle07_p";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle07_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Turks_shore_05";
	Locations[n].reload.l1.emerge = "locator3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Shore.";
	Locations[n].locators_radius.reload.reload1 = 4;

	Locations[n].reload.l5.name = "reload1_back";
	Locations[n].reload.l5.go = "Turks_shore_05";
	Locations[n].reload.l5.emerge = "locator3";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Shore.";
	Locations[n].locators_radius.reload.reload1_back = 1;

	Locations[n].reload.l4.name = "reload2";
	Locations[n].reload.l4.go = "Turks_Lighthouse";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Shore.";
	Locations[n].locators_radius.reload.reload2 = 4;

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Turks_Lighthouse";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Shore.";
	Locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Turks_Jungle_03";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3 = 4;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Turks_Jungle_03";
	Locations[n].reload.l6.emerge = "reload3";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 2;

	Locations[n].island = "Turks"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Shore_4";

	Locations[n].id = "Turks_shore_05";
	locations[n].id.label = "Birds Cove."; // KK
	//locations[n].worldmap = "TShore 5";
	Locations[n].image = "Outside_Shore_4.tga";
	Locations[n].name = "Birds Cove";
	//Sound
	locations[n].type = "seashore";

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
	Locations[n].reload.l4.name = "rock1";
	Locations[n].reload.l4.go = "Turks_Cavern_02";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";	
	Locations[n].reload.l4.label = "Hidden Cave.";

	Locations[n].reload.l5.name = "rock1_back";
	Locations[n].reload.l5.go = "Turks_Cavern_02";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].locators_radius.reload.rock1_back = 1.5;
	Locations[n].reload.l5.label = "Hidden Cave.";

	Locations[n].reload.l1.name = "locator3";
	Locations[n].reload.l1.go = "Turks_Jungle_02";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.locator3 = 3;
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l3.name = "locator3_back";
	Locations[n].reload.l3.go = "Turks_Jungle_02";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.locator3_back = 1;
	Locations[n].reload.l3.label = "Jungle.";

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Turks";
	Locations[n].reload.l2.emerge = "reload_5";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.boat = 9.0;
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";

	Locations[n].island = "Turks"; // NK 04-08-29
	n = n + 1;

	//-------------------------------------------------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Grot";

	Locations[n].id = "Turks_Cavern_02";
	locations[n].id.label = "Hidden Cave";
	Locations[n].image = "Inside_Grot.tga";
	//Sound
	locations[n].type = "KhaelRoa";
	//Models
	Locations[n].models.back = "back\grotenv_";
	//Always
	Locations[n].models.always.cave = "Grot";
	Locations[n].models.always.locators = "Grot_l";
	//Day
	Locations[n].models.day.charactersPatch = "Grot_p";
	//Night
	Locations[n].models.night.charactersPatch = "Grot_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Turks_shore_05";
	Locations[n].reload.l1.emerge = "rock1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Birds Cove.";

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Turks_shore_05";
	Locations[n].reload.l2.emerge = "rock1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Birds Cove.";
	Locations[n].locators_radius.reload.reload1_back = 2;

	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 0, 24);

	Locations[n].items.randitem1 = "blade36";

	Locations[n].island = "Turks"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Passage";

	Locations[n].id = "Turks_shore_04";
	locations[n].id.label = "Sandy Point."; // KK
	locations[n].worldmap = "TShore 4";
	Locations[n].image = "Outside_Passage1.tga";
	Locations[n].name = "Sandy Point";
	//Sound
	locations[n].type = "seashore";

	//Models
	//Always
	Locations[n].models.always.locators = "Pass1_l";
	Locations[n].models.always.shore = "Pass1";
	Locations[n].models.always.shore.foam = "1";
	Locations[n].models.always.seabed = "Pass1_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "Pass1_g";
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
	Locations[n].models.day.charactersPatch = "Pass1_p";
	//Night
	Locations[n].models.night.charactersPatch = "Pass1_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Turks_Cavern_03";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Sea Passage.";

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Turks_Cavern_03";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Sea Passage.";

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Turks";
	Locations[n].reload.l2.emerge = "reload_4";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 9.0;

	Locations[n].island = "Turks"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Cavern";

	Locations[n].id = "Turks_Cavern_03";
	locations[n].id.label = "#sisland_name# Cavern";
	Locations[n].image = "Inside_Cavern.tga";

	//Sound
	locations[n].type = "cave";
	//Models
	//Always
	Locations[n].models.always.locators = "cavern_l";
	Locations[n].models.always.l1 = "cavern";
	Locations[n].models.always.l2 = "Crystals";
	Locations[n].models.always.l2.tech = "EnvironmentShader";
	Locations[n].models.always.l2.reflection = 0.25;


	Locations[n].models.always.Waterfall1 = "water";
	Locations[n].models.always.Waterfall1.uvslide.v0 = 0.0;
    Locations[n].models.always.Waterfall1.uvslide.v1 = 0.0;
    Locations[n].models.always.Waterfall1.tech = "LocationWaterFall";
	Locations[n].models.always.Waterfall1.level = 50;

	Locations[n].models.always.Waterfall2 = "cfall";
	Locations[n].models.always.Waterfall2.uvslide.v0 = 0.3;
    Locations[n].models.always.Waterfall2.uvslide.v1 = 0.0;
	Locations[n].models.always.Waterfall2.tech = "LocationWaterFall";
	Locations[n].models.always.Waterfall2.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "cavern_p";
	//Night
	Locations[n].models.night.charactersPatch = "cavern_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Turks_Cave_Exit_02";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Turks_Cave_Exit_02";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Turks_shore_04";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Shore.";

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Turks_shore_04";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Shore.";
	Locations[n].locators_radius.reload.reload2_back = 2;

	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 0, 24);

	Locations[n].island = "Turks"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Cave Entrance";

	Locations[n].id = "Turks_Cave_Exit_02";
	locations[n].id.label = "Jungle";
	Locations[n].image = "Outside_Cave_Entrance.tga";
	//Sound
	locations[n].type = "Jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "Cave_l";
	Locations[n].models.always.cave = "Cave";
	Locations[n].models.always.grassPatch = "CAVE_g";
	Locations[n].models.always.l1 = "cave_b01";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "cave_b02";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "cave_b03";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	Locations[n].models.always.l4 = "cave_b04";
	Locations[n].models.always.l4.level = 6;
	Locations[n].models.always.l4.tech = "LocationModelBlend";

	//Day
	Locations[n].models.day.charactersPatch = "Cave_p";
	//Night
	Locations[n].models.night.charactersPatch = "Cave_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Turks_Cavern_03";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Cavern.";

	Locations[n].reload.l2.name = "Randitem1";
	Locations[n].reload.l2.go = "Turks_dungeon_01";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Cave.";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload2 = 2.0;

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload2_back = 2.0;

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;
	// -----------------Mosh D24--------------------
	Locations[n].filespath.models = "locations\Inside\Dungeon_4";
	Locations[n].id = "Turks_dungeon_01";
	Locations[n].image = "Inside_Dungeon_4.tga";
	Locations[n].monsters = "1";

	//Sound
	locations[n].type = "dungeon";
	//Models
	Locations[n].models.back = "back\d04env_";
	//Always
	Locations[n].models.always.locators = "d04_l";
	Locations[n].models.always.house = "d04";
	//Day
	Locations[n].models.day.charactersPatch = "d04_p";
	//Night
	Locations[n].models.night.charactersPatch = "d04_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Turks_Cave_Exit_02";//Mosh
	Locations[n].reload.l1.emerge = "reload2";

	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 0, 24);

	Locations[n].items.randitem1 = "blade12";

	Locations[n].island = "Turks"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Shore_10";

	Locations[n].id = "Turks_shore_01";
	locations[n].id.label = "White Reefs."; // KK
	Locations[n].image = "Outside_Shore_10.tga";
	Locations[n].name = "White Reefs";
	//Locations[n].worldmap = "TShore 1";
	//Sound
	locations[n].type = "seashore";

	//Models
	//Always
	Locations[n].models.always.jungle = "shore10";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.locators = "shore10_l";
   	Locations[n].models.always.seabed = "shore10_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "Shore10_g";
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
	Locations[n].models.day.charactersPatch = "shore10_p";
	//Night
	Locations[n].models.night.charactersPatch = "shore10_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Turks_Jungle_01";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 3;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Turks_Jungle_01";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Turks";
	Locations[n].reload.l2.emerge = "reload_3";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 9.0;

	Locations[n].island = "Turks"; // NK 04-08-29
	n = n + 1;
	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Jungle_3";
	Locations[n].filespath.textures = "locations\JUNGLES";

	Locations[n].id = "Turks_Jungle_01";
	locations[n].id.label = "#sisland_name# jungle";
	Locations[n].image = "Outside_Jungle_3.tga";
	//Sound
	locations[n].type = "Jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "Jungle03_l";
	Locations[n].models.always.jungle = "Jungle03";
	Locations[n].models.always.grassPatch = "JUNGLE03_g";
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
	Locations[n].models.day.charactersPatch = "Jungle03_p";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle03_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Turks_Cave_Exit_01";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1 = 1.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Turks_shore_ship";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Shore.";
	Locations[n].locators_radius.reload.Reload2 = 3.0;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Turks_shore_01";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload3 = 3.0;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Turks_Cave_Exit_01";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l5.name = "reload2_back";
	Locations[n].reload.l5.go = "Turks_shore_ship";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Shore.";
	Locations[n].locators_radius.reload.reload2_back = 3.0;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Turks_shore_01";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 3.0;

	Locations[n].island = "Turks"; // NK 04-08-29
	n = n + 1;
	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Cave Entrance";

	Locations[n].id = "Turks_Cave_Exit_01";
	locations[n].id.label = "#sisland_name# cave entrance";
	Locations[n].image = "Outside_Cave_Entrance.tga";
	//Sound
	locations[n].type = "Jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "Cave_l";
	Locations[n].models.always.cave = "Cave";
	Locations[n].models.always.grassPatch = "CAVE_g";
	Locations[n].models.always.l1 = "cave_b01";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "cave_b02";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "cave_b03";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	Locations[n].models.always.l4 = "cave_b04";
	Locations[n].models.always.l4.level = 6;
	Locations[n].models.always.l4.tech = "LocationModelBlend";
	//Day
	Locations[n].models.day.charactersPatch = "Cave_p";
	//Night
	Locations[n].models.night.charactersPatch = "Cave_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map

	Locations[n].reload.l3.name = "reload1";
	Locations[n].reload.l3.go = "Turks_Cavern_01";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Cave.";
	Locations[n].locators_radius.reload.Reload1 = 1;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Turks_Cavern_01";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Cave.";
	Locations[n].locators_radius.reload.Reload1_back = 1.3;

	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Turks_Jungle_01";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2 = 2.0;

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Turks_Jungle_01";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 2.0;

	Locations[n].island = "Turks"; // NK 04-08-29
	n = n + 1;
	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\ANIMISTS_Cave";
	Locations[n].id = "Turks_Cavern_01";
	locations[n].id.label = "Pirate Lair";
	Locations[n].image = "Inside_Animists_Cave_Lair.tga";
	//Sound
	locations[n].type = "cave";

	//Models
	//Always
	Locations[n].models.always.locators = "SCave_l";
	Locations[n].models.always.l1 = "SCave";
	//Day
	Locations[n].models.day.charactersPatch = "SCave_p";
	//Night
	Locations[n].models.night.charactersPatch = "SCave_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Turks_Cave_Exit_01";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Turks_Cave_Exit_01";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].island = "Turks"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Shore_ship";

	Locations[n].id = "Turks_shore_ship";
	locations[n].id.label = "Wreckage shore."; // KK
//	locations[n].worldmap = "TShore 3";
	Locations[n].image = "Outside_Shore_Ship.tga";
	Locations[n].name = "Wreck";
	//Sound
	locations[n].type = "seashore";

	//Models
	//Always
	Locations[n].models.always.jungle = "ShoreShip";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.locators = "ShoreShip_l_x";
	Locations[n].models.always.grassPatch = "ShoreShip_g";
	Locations[n].models.always.seabed = "ShoreShip_sb";
	Locations[n].models.always.seabed.foam = "1";
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
	Locations[n].models.day.charactersPatch = "ShoreShip_p";
	//Night
	Locations[n].models.night.charactersPatch = "ShoreShip_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Turks_Jungle_01";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 1;

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Turks_Jungle_01";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3;

	Locations[n].items.randitem1 = "pistol8";

//	LAi_LocationMonstersGen(&locations[n], true);
//	LAi_LocationSetMonstersTime(&locations[n], 0, 24);

	Locations[n].island = "Turks"; // NK 04-08-29
	n = n + 1;
	// -------------------------------------------------

// Additional Buildings, works only if Buildingset is installed -----------------------
	Build_at("Turks_Shore_01", "jungle2", "", 19.56, 3.08, -4.32, -0.67, "wild_jungles");
	Build_at("Turks_Shore_01", "jungle2", "", 3.47, 2.80, -12.18, 1.72, "wild_jungles");
	Build_at("Turks_Jungle_01", "jungle", "", -7.32, 0.24, 8.62, -2.56, "wild_jungles");
	Build_at("Turks_Jungle_01", "jungle2", "", 23.04, -0.40, 20.77, -0.44, "wild_jungles");
	Build_at("Turks_Jungle_01", "jungle2", "", 1.04, 4.33, 16.64, -2.28, "wild_jungles");
	Build_at("Turks_Jungle_01", "jungle2", "", 3.11, -8.44, -18.35, -0.66, "wild_jungles");
	Build_at("Turks_Lighthouse", "jungle2", "", -4.57, 14.22, -45.36, -1.49, "wild_jungles");
	Build_at("Turks_Jungle_02", "jungle", "", -3.67, 0.74, -3.05, 2.27, "wild_jungles");
	Build_at("Turks_Jungle_02", "jungle2", "", -3.67, 0.74, -3.05, 2.27, "wild_jungles");
	Build_at("Turks_Jungle_01", "jungle2", "", -7.32, 0.24, 8.62, -2.56, "wild_jungles");
	Build_at("Turks_Jungle_01", "jungle", "", -18.25, 0.23, 13.66, -1.93, "wild_jungles");
	Build_at("Turks_Jungle_01", "jungle", "", -1.36, 0.02, -19.22, 2.20, "wild_jungles");
	Build_at("Turks_Jungle_01", "jungle", "", -4.1, 0.00, 21.28, 1.48, "wild_jungles");
	Build_at("Turks_Jungle_03", "jungle", "", -3.67, 0.00, 15.71, -1.94, "wild_jungles");
}
