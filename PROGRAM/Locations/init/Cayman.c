void LocationInitCayman(ref n)
{
	// Falaise_de_fleur_location_06 -------------------------------------------------
	Locations[n].id = "Cayman_Port";
	locations[n].id.label = "#stown_name# Port";
	locations[n].worldmap = "Grand Cayman";
	Locations[n].image = "Town_FalaiseDeFleur_Port2_England";

	//Town sack
	Locations[n].townsack = "Grand Cayman";

	//Sound
	locations[n].type = "port";
	locations[n].fastreload = "Grand_Cayman";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\port2";
	Locations[n].filespath.textures = "locations\ENGLAND"; 
	Locations[n].models.always.city = "FFport02";
	Locations[n].models.always.city.foam = "1";
	Locations[n].models.always.seabed = "FFport02_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.locators = "FFport02_l";
	Locations[n].models.always.grassPatch = "FFport02_g";
	//Day
	Locations[n].models.day.fonar = "FFport02_fd";
	Locations[n].models.day.charactersPatch = "FFport02_p";
	//Night
	Locations[n].models.night.fonar = "FFport02_fn";
	Locations[n].models.night.charactersPatch = "FFport02_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	LAi_LocationFantomsGen(&locations[n], true);
	Locations[n].reload.l1.name = "Falaise_de_fleur_location_01_05";
	Locations[n].reload.l1.go = "Grand_Cayman_Town";
	Locations[n].reload.l1.emerge = "reload9";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Town.";

	Locations[n].reload.l2.name = "locationext";
	Locations[n].reload.l2.go = "Cayman_Jungle_01";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";

	Locations[n].reload.l3.name = "locationext_back";
	Locations[n].reload.l3.go = "Cayman_Jungle_01";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.locationext_back = 2.5;

	Locations[n].reload.l4.name = "sea";
	Locations[n].reload.l4.go = "Cayman";
	Locations[n].reload.l4.emerge = "reload_1";
	Locations[n].reload.l4.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l4.label = "Ship.";
	else
		Locations[n].reload.l4.label = "Sea.";
	Locations[n].locators_radius.reload.sea = 3;

	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\town_Douwesen\town";
	Locations[n].filespath.textures = "locations\ENGLAND";

	Locations[n].id = "Grand_Cayman_town";
	locations[n].id.label = "#stown_name#";
	Locations[n].image = "Town_Douwesen_Town_England";
	locations[n].worldmap = "Grand Cayman";

	//Town sack
	Locations[n].townsack = "Grand Cayman";

	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "Grand_Cayman";
	//Models
	//Always
	Locations[n].models.always.locators = "DouTown_l";
	Locations[n].models.always.grassPatch = "DouTown_g";
	Locations[n].models.always.town = "DouTown";
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
	//Locations[n].models.day.rinok = "DouTown_e01";
	Locations[n].models.day.fonar = "DouTown_fd";
	Locations[n].models.day.charactersPatch = "DouTown_p";
	Locations[n].models.day.jumppatch = "DouTown_j";

	//Night
	Locations[n].models.night.fonar = "DouTown_fn";
	Locations[n].models.night.charactersPatch = "DouTown_p";
	Locations[n].models.night.jumppatch = "DouTown_j";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload9";
	Locations[n].reload.l1.go = "Cayman_port";
	Locations[n].reload.l1.emerge = "Falaise_de_fleur_location_01_05";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Sea port.";

	Locations[n].reload.l3.name = "reload14";
	Locations[n].reload.l3.go = "Grand_Cayman_Tavern";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Tavern.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l3.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l7.name = "reload16";
	Locations[n].reload.l7.go = "Grand_Cayman_Store";
	Locations[n].reload.l7.emerge = "locator2";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Store.";
	Locations[n].reload.l7.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l7.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l8.name = "reload19";
	Locations[n].reload.l8.go = "Cayman_Jungle_02";
	Locations[n].reload.l8.emerge = "reload2";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "Jungle.";

	Locations[n].reload.l9.name = "reload15";
	Locations[n].reload.l9.go = "Grand_Cayman_townhall"; // KK
	Locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "Residence.";
	Locations[n].reload.l9.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l9.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l2.name = "reload3";
	Locations[n].reload.l2.go = "Grand_Cayman_House_01";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "House.";

	Locations[n].reload.l4.name = "reload6";
	Locations[n].reload.l4.go = "Grand_Cayman_shipyard";
	Locations[n].reload.l4.emerge = "locator2";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Shipyard.";
	Locations[n].reload.l4.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l4.goto_disable = 1; // Screwface: Disable Go-To location

	//only in WoodesRogers
	Locations[n].reload.l22.name = "reload22";
	Locations[n].reload.l22.go = "BB_Eden_estate";
	Locations[n].reload.l22.emerge = "box23";
	Locations[n].reload.l22.autoreload = "0";
	Locations[n].reload.l22.label = "Estate.";
	Locations[n].locators_radius.reload.reload22 = 0.2;

	Locations[n].reload.l23.name = "reload23";
	Locations[n].reload.l23.go = "Grand_Cayman_townhall";
	Locations[n].reload.l23.emerge = "box1";
	Locations[n].reload.l23.autoreload = "0";
	Locations[n].reload.l23.label = "Residence.";
	Locations[n].locators_radius.reload.reload23 = 0.2;	

	Locations[n].locators_radius.box.box2 = 0.2;
	Locations[n].locators_radius.box.box3 = 0.2;

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "door_N04";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "door_H1_small";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "ladder_very_big_45";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "gatedoor_white_stone_90";

	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Grand_Cayman_shipyard";
	Locations[n].filespath.models = "locations\inside\shipyard2";
	locations[n].id.label = "#stown_name# shipyard";
	Locations[n].image = "Inside_Shipyard2";

	//Town sack
	Locations[n].townsack = "Grand Cayman";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Grand_Cayman";
	//Models
	//Always
	Locations[n].models.always.locators = "sh02_l";
	Locations[n].models.always.tavern = "sh02";
	Locations[n].models.always.window = "sh02_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "sh02_p";

	//Night
	Locations[n].models.night.charactersPatch = "sh02_p";

	//Environment
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\ffsh2_";
	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "Grand_Cayman_town";
	Locations[n].reload.l1.emerge = "Reload6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	Locations[n].locators_radius.reload.locator2 = 0.8;
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\MediumTavern";

	Locations[n].id = "Grand_Cayman_Tavern";
	locations[n].id.label = "#stown_name# tavern";
	Locations[n].image = "Inside_MediumTavern";

	//Town sack
	Locations[n].townsack = "Grand Cayman";

	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "Grand_Cayman";
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
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\grmt_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Grand_Cayman_town";
	Locations[n].reload.l1.emerge = "reload14";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Grand_Cayman_Tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Room.";
	Locations[n].reload.l2.disable = true;
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Grand_Cayman_Tavern_upstairs";
	locations[n].id.label = "Room in #stown_name# tavern.";
	Locations[n].image = "Inside_Doubleflour_House_Room";

	//Town sack
	Locations[n].townsack = "Grand Cayman";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Grand_Cayman";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Doubleflour_house";
	Locations[n].models.always.locators = "LH_F2_l";
	Locations[n].models.always.tavern = "LH_F2";
	Locations[n].models.always.window = "LH_F2_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "LH_F2_p";

	//Night
	Locations[n].models.night.charactersPatch = "LH_F2_p";

	//Environment
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\grlf2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Grand_Cayman_Tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# tavern."; // KK
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\StoreSmall";
	Locations[n].image = "Inside_StoreSmall";

	Locations[n].id = "Grand_Cayman_Store";
	locations[n].id.label = "#stown_name# store";

	//Town sack
	Locations[n].townsack = "Grand Cayman";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Grand_Cayman";
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
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\muss_";
	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "Grand_Cayman_town";
	Locations[n].reload.l1.emerge = "Reload16";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;

// KK --------------------------------------------------->
	Locations[n].id = "Grand_Cayman_townhall";
	locations[n].id.label = "#stown_name# townhall";
	Locations[n].filespath.models = "locations\inside\Residence1";
	Locations[n].image = "Inside_Residence1";

	//Town sack
	Locations[n].townsack = "Grand Cayman";

	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Grand_Cayman";
	//Models
	//Always
	Locations[n].models.always.locators = "res01_l";
	Locations[n].models.always.jungle = "res01";
	Locations[n].models.always.window = "res01_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "res01_p";

	//Night
	Locations[n].models.night.charactersPatch = "res01_p";

	//Environment
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\ffres1_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Grand_Cayman_town";
	Locations[n].reload.l1.emerge = "reload15";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	Locations[n].locators_radius.reload.locator1 = 0.8;

	Locations[n].locators_radius.box.box1 = 0.001;		//used in WoodesRogers
	Locations[n].locators_radius.goto.box1 = 0.001;		//used in WoodesRogers
	
	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Cayman";
	n = n + 1;
// <-- KK

	// 06 -------------------------------------------------
	Locations[n].id = "Cayman_Jungle_02";
	locations[n].id.label = "#sisland_name# jungle";
	Locations[n].image = "Town_FalaiseDeFleur_Exit";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\exit";
	Locations[n].models.always.jungle = "FFexit";
	Locations[n].models.always.locators = "FFexit_l";
	Locations[n].models.always.grassPatch = "FFexit_g";
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
	Locations[n].models.day.charactersPatch = "FFexit_p";
	Locations[n].models.day.fonar = "FFexit_fd";
	//Night
	Locations[n].models.night.charactersPatch = "FFexit_p";
	Locations[n].models.night.fonar = "FFexit_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Grand_Cayman_town";
	Locations[n].reload.l1.emerge = "reload19";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Town";

	Locations[n].reload.l2.name = "reload1";
	Locations[n].reload.l2.go = "Cayman_Jungle_03";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1 = 3;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Cayman_Jungle_03";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].reload.l4.name = "reload3";
	Locations[n].reload.l4.go = "Outskirts_House";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "House";

	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Jungle_4";

	Locations[n].id = "Cayman_Jungle_03";
	locations[n].id.label = "#sisland_name# jungle";
	Locations[n].image = "Outside_Jungle_4";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "Jungle04_l";
	Locations[n].models.always.jungle = "Jungle04";
	Locations[n].models.always.grassPatch = "JUNGLE04_g";
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
	Locations[n].models.day.charactersPatch = "Jungle04_p";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle04_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cayman_shore_01";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Eden Rock."; // KK
	Locations[n].locators_radius.reload.reload1 = 4;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Cayman_shore_01";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Eden Rock."; // KK
	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Cayman_jungle_04";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 4;

	Locations[n].reload.l5.name = "reload2_back";
	Locations[n].reload.l5.go = "Cayman_jungle_04";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Cayman_jungle_02";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3 = 4;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Cayman_jungle_02";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 3;

	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\town_Greenford\exit";
	Locations[n].filespath.textures = "locations\ENGLAND";

	Locations[n].id = "Cayman_jungle_04";
	locations[n].id.label = "Jungle.";
	Locations[n].image = "Town_Greenford_Exit";

	//Town sack
	Locations[n].townsack = "Grand Cayman";

	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "GrExit_l";
	Locations[n].models.always.exit = "GrExit";
	Locations[n].models.always.grassPatch = "GrExit_g";
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
	Locations[n].models.day.charactersPatch = "GrExit_p";
	Locations[n].models.day.fonar = "GrExit_fd";
	//Night
	Locations[n].models.night.charactersPatch = "GrExit_p";
	Locations[n].models.night.fonar = "GrExit_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "Reload2";
	Locations[n].reload.l1.go = "Cayman_fakefort1";
	Locations[n].reload.l1.emerge = "reloadc2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Fort.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l1.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l2.name = "Reload1";
	Locations[n].reload.l2.go = "Cayman_jungle_03";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1 = 3;

	Locations[n].reload.l3.name = "Reload1_back";
	Locations[n].reload.l3.go = "Cayman_jungle_03";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1_back = 3;

	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;

	// ccc fake forts--------------------------------------
	//ID
	Locations[n].id = "Cayman_fakefort1";		//new ID
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";	//A warning sign at the gate :)
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_1";
	Locations[n].image = "Fort_Inside_Fort_1";

	//Town sack
	Locations[n].townsack = "Grand Cayman";		//change
	//Sound
	locations[n].type = "military";

	//Models
	//Always
	Locations[n].models.always.locators = "fort1_l_ccc";
	Locations[n].models.always.l1 = "fort1";
	//Day
	Locations[n].models.day.charactersPatch = "fort1_p";
	Locations[n].models.day.fonar = "fort1_fd";
	//Night
	Locations[n].models.night.charactersPatch = "fort1_p";
	Locations[n].models.night.fonar = "fort1_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//reload map.
	Locations[n].reload.l1.name = "reloadc2";
	Locations[n].reload.l1.go = "Cayman_jungle_04";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reloadC4";
	Locations[n].reload.l2.go = "Cayman_fakefort2";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l3.name = "reloadc5";
	Locations[n].reload.l3.go = "Cayman_armory";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].reload.l4.name = "reloadc1";
	Locations[n].reload.l4.go = "Cayman_fakefort3";
	Locations[n].reload.l4.emerge = "reloadc1";
	Locations[n].reload.l4.autoreload = "0";

	Locations[n].island = "Cayman"; // NK 04-08-29	
	n = n + 1;

	// ccc oxbay fake fort 2----------------------------------
	//ID
	Locations[n].id = "Cayman_fakefort2";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";

	//Town sack
	Locations[n].townsack = "Grand Cayman";

	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_2";
	Locations[n].image = "Fort_Inside_Fort_1";
	//Sound
	locations[n].type = "military";

	//Models
	//Always
	Locations[n].models.always.locators = "fort2_l_ccc";
	Locations[n].models.always.l1 = "fort2";
	//Day
	Locations[n].models.day.charactersPatch = "fort2_p";
	Locations[n].models.day.fonar = "fort2_fd";
	//Night
	Locations[n].models.night.charactersPatch = "fort2_p";
	Locations[n].models.night.fonar = "fort2_fn";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cayman_fakefort1";
	Locations[n].reload.l1.emerge = "reloadc4";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reloadc1";
	Locations[n].reload.l2.go = "Cayman_fakefort3";
	Locations[n].reload.l2.emerge = "reloadc2";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;
	
	// ccc oxbay fake fort 3----------------------------------
	//ID
	Locations[n].id = "Cayman_fakefort3";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";


	//Town sack
	Locations[n].townsack = "Grand Cayman";

	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_3";
	Locations[n].image = "Fort_Inside_Fort_1";
	//Sound
	Locations[n].type = "military";

	//Models
	//Always
	Locations[n].models.always.locators = "fort3_l_ccc";
	Locations[n].models.always.l1 = "fort3";
	//Day
	Locations[n].models.day.charactersPatch = "fort3_p";
	Locations[n].models.day.fonar = "fort3_fd";
	//Night
	Locations[n].models.night.charactersPatch = "fort3_p";
	Locations[n].models.night.fonar = "fort3_fn";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	Locations[n].reload.l1.name = "reloadc1";
	Locations[n].reload.l1.go = "Cayman_fakefort1";
	Locations[n].reload.l1.emerge = "reloadc1";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reloadc2";
	Locations[n].reload.l2.go = "Cayman_fakefort2";
	Locations[n].reload.l2.emerge = "reloadc1";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l3.name = "reload1";
	Locations[n].reload.l3.go = "Cayman_armory";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;

	// ccc oxbay armory-------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\LargeStore";
	Locations[n].id = "Cayman_armory";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";
	Locations[n].image = "Fort_Inside_Fort_2";

	//Town sack
	Locations[n].townsack = "Grand Cayman";
	//Sound
	locations[n].type = "military";

	//Models
	//Always
	Locations[n].models.always.locators = "LS_l_ccc";
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
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\douls_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cayman_fakefort1";
	Locations[n].reload.l1.emerge = "reloadc5";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Cayman_fakefort3";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
   	Locations[n].id = "Cayman_Shore_01";
	locations[n].id.label = "Eden Rock."; // KK
	locations[n].worldmap = "CaymanShore 1";
	Locations[n].filespath.models = "locations\Outside\Shore_7";
	Locations[n].image = "Outside_Shore_7";
	Locations[n].name = "Eden Rock";
	//Sound
	locations[n].type = "seashore";
   	 //Models
	//Always
	Locations[n].models.always.jungle = "Shore07";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.locators = "Shore07_l";
	Locations[n].models.always.grassPatch = "Shore07_g";
	Locations[n].models.always.seabed = "Shore07_sb";
	Locations[n].models.always.seabed.foam = "1";

	//Day
	Locations[n].models.day.charactersPatch = "Shore07_p";
	//Night
	Locations[n].models.night.charactersPatch = "Shore07_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Cayman_Jungle_03";
	Locations[n].reload.l1.emerge = "Reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 3.0;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Cayman_Jungle_03";
	Locations[n].reload.l3.emerge = "Reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3.0;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Cayman";
	Locations[n].reload.l2.emerge = "reload_4";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 9.0;

	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;

	//------------------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Jungle_1";

	Locations[n].id = "Cayman_Jungle_01";
	locations[n].id.label = "#sisland_name# jungle";
	Locations[n].image = "Outside_Jungle_1";
	//Sound
	locations[n].type = "jungle";

	//Models
	//Always
	Locations[n].models.always.locators = "jungle01_l";
	Locations[n].models.always.jungle = "jungle01";
	Locations[n].models.always.grassPatch = "jungle01_g";
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
	Locations[n].models.day.charactersPatch = "jungle01_p";
	//Night
	Locations[n].models.night.charactersPatch = "jungle01_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cayman_port";
	Locations[n].reload.l1.emerge = "locationext";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1 = 3.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Cayman_passage";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Shore.";
	Locations[n].locators_radius.reload.Reload2 = 3.0;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Cayman_port";
	Locations[n].reload.l3.emerge = "locationext";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Cayman_passage";
	Locations[n].reload.l4.emerge = "Reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Shore.";
	Locations[n].locators_radius.reload.reload2_back = 2.0;

	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Passage";

	Locations[n].id = "Cayman_passage";
	locations[n].id.label = "#sisland_name# passage";
	Locations[n].image = "Outside_Passage2";
	//Sound
	locations[n].type = "seashore";

	//Models
	//Always
	Locations[n].models.always.locators = "pass2_l";
	Locations[n].models.always.jungle = "pass2";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.seabed = "pass2_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "pass2_g";
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
	Locations[n].models.day.charactersPatch = "pass2_p";
	//Night
	Locations[n].models.night.charactersPatch = "pass2_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Cayman_Jungle_05";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	//Locations[n].locators_radius.reload.reload2 = 2.0;
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Cayman_Jungle_05";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload2 = 2.0;
	Locations[n].reload.l2.label = "Jungle.";

	Locations[n].reload.l3.name = "reload1";
	Locations[n].reload.l3.go = "Cayman_Jungle_01";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
//	Locations[n].locators_radius.reload.reload1 = 2.0;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Cayman_Jungle_01";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Jungle_6";

	Locations[n].id = "Cayman_Jungle_05";
	locations[n].id.label = "#sisland_name# jungle";
	Locations[n].image = "Outside_Jungle_6";
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
	Locations[n].reload.l1.go = "Cayman_Jungle_06";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 2.5;
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Cayman_Shore_02";
	Locations[n].reload.l2.emerge = "locator3";	// ccc Nov06, was wrong,"reload1"
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload2 = 2.5;
	Locations[n].reload.l2.label = "Cayman Kai.";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Cayman_passage";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.reload3 = 2.5;
	Locations[n].reload.l3.label = "Passage.";

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Cayman_Shore_02";
	Locations[n].reload.l4.emerge = "locator3";	// ccc Nov06, was wrong,"reload1"
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].locators_radius.reload.reload2_back = 2.5;
	Locations[n].reload.l4.label = "Cayman Kai.";

	Locations[n].reload.l5.name = "reload3_back";
	Locations[n].reload.l5.go = "Cayman_passage";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].locators_radius.reload.reload3_back = 3;
	Locations[n].reload.l5.label = "Passage.";

	Locations[n].reload.l6.name = "reload1_back";
	Locations[n].reload.l6.go = "Cayman_Jungle_06";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 2.5;
	Locations[n].reload.l6.label = "Jungle.";

	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;

// KK ------------------------------------------------->
	Locations[n].id = "Cayman_Shore_02";
	//Locations[n].worldmap = "";
	Locations[n].filespath.models = "locations\Outside\Shore_1";
	Locations[n].image = "Outside_Shore_1";
	locations[n].id.label = "Cayman Kai.";
	Locations[n].name = "Cayman Kai";
	//Sound
	locations[n].type = "seashore";
	//Models
	//Always
	Locations[n].models.always.locators = "Shore01_l";
	Locations[n].models.always.shore = "Shore01";
	Locations[n].models.always.shore.foam = "1";
	Locations[n].models.always.seabed = "Shore01_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "Shore01_g";
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
	Locations[n].models.day.charactersPatch = "Shore01_p";
	//Night
	Locations[n].models.night.charactersPatch = "Shore01_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "locator3";	// ccc Nov06, was wrong,"reload1";
	Locations[n].reload.l1.go = "Cayman_Jungle_05";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "locator3_back";	// ccc Nov06, was wrong,"reload1_back";
	Locations[n].reload.l2.go = "Cayman_Jungle_05";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].reload.l3.name = "boat";
	Locations[n].reload.l3.go = "Cayman";
	Locations[n].reload.l3.emerge = "reload_2";
	Locations[n].reload.l3.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l3.label = "Ship.";
	else
		Locations[n].reload.l3.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 9.0;

	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;
// <-- KK

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Cave Entrance";

	Locations[n].id = "Cayman_Jungle_06";
	locations[n].id.label = "#sisland_name# Grot entrance";
	Locations[n].image = "Outside_Cave_Entrance";
	//Sound
	locations[n].type = "jungle";
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
	Locations[n].reload.l3.go = "Cayman_Grot_01";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Grot.";
	Locations[n].locators_radius.reload.Reload1 = 1;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Cayman_Grot_01";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Grot.";
	Locations[n].locators_radius.reload.Reload1_back = 1.3;

	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Cayman_Jungle_05";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2 = 2.0;

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Cayman_Jungle_05";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 2.0;

	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;

	//-------------------------------------------------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Grot";

	Locations[n].id = "Cayman_Grot_01";
	locations[n].id.label = "Hidden Cave";
	Locations[n].image = "Inside_Grot";
	//Sound
	locations[n].type = "cave";
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
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cayman_Jungle_06";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Cayman_Jungle_06";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2;

	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 0, 24);

	Locations[n].items.randitem1 = "blade36";

	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Shore_5";

	Locations[n].id = "Cayman_Shore_03";
	locations[n].id.label = "Sand Bluff."; // KK
	Locations[n].image = "Outside_Shore_5";
	Locations[n].name = "Sand Bluff";
	locations[n].worldmap = "DShore 1";

	//Sound
	locations[n].type = "seashore";

	//Models
	//Always
	Locations[n].models.always.jungle = "Shore05";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.locators = "Shore05_l";
	Locations[n].models.always.grassPatch = "Shore05_g";
	Locations[n].models.always.seabed = "Shore05_sb";
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
	Locations[n].models.day.charactersPatch = "Shore05_p";
	//Night
	Locations[n].models.night.charactersPatch = "Shore05_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Cayman_Jungle_07";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 3;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Cayman_Jungle_07";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Cayman";
	Locations[n].reload.l2.emerge = "reload_3";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 9.0;

	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_7";

	Locations[n].id = "Cayman_Jungle_07";
	locations[n].id.label = "#sisland_name# jungle";
	Locations[n].image = "Outside_Jungle_7";
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
	Locations[n].reload.l1.go = "Cayman_Pirate_house_01";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "House.";
	Locations[n].locators_radius.reload.reload1 = 4;

	Locations[n].reload.l5.name = "reload1_back";
	Locations[n].reload.l5.go = "Cayman_Pirate_house_01";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "House.";
	Locations[n].locators_radius.reload.reload1_back = 1;

	Locations[n].reload.l4.name = "reload2";
	Locations[n].reload.l4.go = "Cayman_Shore_03";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Sand Bluff.";
	Locations[n].locators_radius.reload.reload2 = 4;

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Cayman_Shore_03";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Sand Bluff.";
	Locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Cayman_Jungle_08";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3 = 4;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Cayman_Jungle_08";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 2;

	Locations[n].island = "Cayman"; // NK 04-11-03
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Pirate_Outer_Location";	

	Locations[n].id = "Cayman_Pirate_house_01";
	locations[n].id.label = "Entrance to house";
	Locations[n].image = "Outside_Pirate_Outer_location";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "Pirl_l";
	Locations[n].models.always.house = "pirl";
	Locations[n].models.always.grassPatch = "pirl_g";
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
	Locations[n].models.day.charactersPatch = "Pirl_p";
	Locations[n].models.day.fonar = "pirl_fd";
	//Night
	Locations[n].models.night.charactersPatch = "pirl_p";
	Locations[n].models.night.fonar = "pirl_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cayman_Jungle_07";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";	
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Cayman_Jungle_07";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 3.0;
	Locations[n].reload.l3.label = "Jungle.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Cayman_Pirate_house_01_inside";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Enter.";

	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Pirate_House";	

	Locations[n].id = "Cayman_Pirate_house_01_inside";
	locations[n].id.label = "Inside house";
	Locations[n].image = "Inside_Pirate_House";
	//Sound
	locations[n].type = "Residence";
	//Models
	//Always
	Locations[n].models.always.locators = "pirh_l";
	Locations[n].models.always.house = "pirh";
	Locations[n].models.always.window = "pirh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "pirh_p";

	//Night
	Locations[n].models.night.charactersPatch = "pirh_p";

	//Environment
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\qcpirh_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cayman_Pirate_house_01";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Exit.";

	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1; 

	// -------------------------------------------------
	Locations[n].id = "Cayman_Jungle_08";
	locations[n].id.label = "#sisland_name# jungle";
	Locations[n].filespath.models = "locations\Outside\jungle_8";
	Locations[n].image = "Outside_Jungle_8";
 	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.jungle = "jungle08";
	Locations[n].models.always.locators = "jungle08_l";
	Locations[n].models.always.grassPatch = "JUNGLE08_g";
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
	Locations[n].models.day.charactersPatch = "jungle08_p";
//	Locations[n].models.day.fonar = "jungle01_fd";
	//Night
	Locations[n].models.night.charactersPatch = "jungle08_p";
//	Locations[n].models.night.fonar = "jungle01_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cayman_Jungle_07";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1 = 3.0;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Cayman_Jungle_07";
	Locations[n].reload.l4.emerge = "reload3";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Cayman_Jungle_09";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 3.0;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Cayman_Jungle_09";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 2.0;

	Locations[n].reload.l5.name = "goto9";
	Locations[n].reload.l5.go = "Cayman_Grot_02";
	Locations[n].reload.l5.emerge = "monster39";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].locators_radius.reload.goto9 = 2.0;

	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Rheims House";

	Locations[n].id = "Cayman_Jungle_09";
	locations[n].id.label = "House in Jungle";
	Locations[n].image = "Outside_Rheims_House";
	//Sound
	locations[n].type = "Jungle";

	//Models
	//Always
	Locations[n].models.always.locators = "Rhouse_l";
	Locations[n].models.always.house = "Rhouse";
	Locations[n].models.always.grassPatch = "Rhouse_g";
	Locations[n].models.always.l1 = "rhouse_b01";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "rhouse_b02";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "rhouse_b03";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	Locations[n].models.always.l4 = "rhouse_b04";
	Locations[n].models.always.l4.level = 6;
	Locations[n].models.always.l4.tech = "LocationModelBlend";

	//Day
	Locations[n].models.day.charactersPatch = "Rhouse_p";
	//Night
	Locations[n].models.night.charactersPatch = "Rhouse_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cayman_Jungle_08";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1 = 3;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Cayman_Jungle_08";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 3;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Cayman_Pirate_house_02_inside";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "House";

	Locations[n].reload.l4.name = "randitem1";
	Locations[n].reload.l4.go = "Cayman_Grot_02";
	Locations[n].reload.l4.emerge = "reload1";

	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\inside\mediumHouse";

	Locations[n].id = "Cayman_Pirate_house_02_inside";
	locations[n].id.label = "Inside house";
	Locations[n].image = "Inside_MediumHouse";
	//Sound
	locations[n].type = "House";

	//Models
	//Always
	Locations[n].models.always.locators = "MH_l";
	Locations[n].models.always.house = "MH";
	//Locations[n].models.always.env = "smalltavern_env";
	Locations[n].models.always.window = "MH_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "MH_p";

	//Night
	Locations[n].models.night.charactersPatch = "MH_p";

	//Environment
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\smumh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cayman_Jungle_09";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Exit.";

	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;

	// -----------------Mosh D24--------------------
	Locations[n].filespath.models = "locations\Inside\Dungeon_3";
	Locations[n].id = "Cayman_Grot_02";
	Locations[n].image = "Inside_Dungeon_3";
//	Locations[n].monsters = "1";
	locations[n].id.label = "#sisland_name# underground";
	//Sound
	locations[n].type = "Dungeon";
	//Models
	Locations[n].models.back = "back\d03env_";
	//Always
	Locations[n].models.always.locators = "d03_l";
	Locations[n].models.always.house = "d03";
	//Day
	Locations[n].models.day.charactersPatch = "d03_p";
	//Night
	Locations[n].models.night.charactersPatch = "d03_p";
	//Environment
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cayman_Jungle_09";//Mosh
	Locations[n].reload.l1.emerge = "goto4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Jungle.";

	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 0, 24);

	Locations[n].items.randitem1 = "blade308";

	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\inside\mediumHouse";

	Locations[n].id = "Outskirts_House";
	locations[n].id.label = "Inside house";
	Locations[n].image = "Inside_MediumHouse";
	//Sound
	locations[n].type = "House";

	//Models
	//Always
	Locations[n].models.always.locators = "MH_l";
	Locations[n].models.always.house = "MH";
	//Locations[n].models.always.env = "smalltavern_env";
	Locations[n].models.always.window = "MH_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "MH_p";

	//Night
	Locations[n].models.night.charactersPatch = "MH_p";

	//Environment
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\smumh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cayman_Jungle_02";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Exit.";

	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	// HOUSES
	// -------------------------------------------------

	// -------------------------------------------------
	Locations[n].id = "Grand_Cayman_House_01";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\DoubleFlour_house";
	Locations[n].image = "Inside_Doubleflour_House_Lower";

	//Town sack
	Locations[n].townsack = "Grand Cayman";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Grand_Cayman";
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F1_l";
	Locations[n].models.always.house = "LH_F1";
	Locations[n].models.always.window = "LF1_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "LH_F1_p";

	//Night
	Locations[n].models.night.charactersPatch = "LH_F1_p";

	//Environment
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\doulf2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Grand_Cayman_town";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Town.";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;

// Additional Buildings, works only if Buildingset is installed -----------------------
	Build_at("Cayman_jungle_09", "jungle2", "", 5.88, 2.36, -7.44, 0.93, "wild_jungles");
	Build_at("Cayman_jungle_09", "jungle2", "", 0.78, 0.10, 5.54, 0.43, "wild_jungles");
	Build_at("Cayman_Port", "barracks", "", -2.55, 5.20, 37.69, 0.00, "building");
	Build_at("Cayman_jungle_03", "jungle", "", -0.08, -1.94, -12.77, 1.17, "wild_jungles");
	Build_at("Cayman_jungle_03", "jungle2", "", -0.08, -1.94, -12.77, 1.17, "wild_jungles");
	Build_at("Cayman_jungle_07", "jungle", "", 1.28, 0.32, 14.04, 1.30, "wild_jungles");
	Build_at("Cayman_jungle_07", "jungle2", "", 1.28, 0.32, 14.04, 1.30, "wild_jungles");
	Build_at("Cayman_jungle_07", "jungle", "", 0.23, 0.23, 6.89, -2.35, "wild_jungles");
	Build_at("Cayman_jungle_07", "jungle2", "", 0.23, 0.23, 6.89, -2.35, "wild_jungles");
	Build_at("Cayman_jungle_07", "jungle", "", 13.14, 0.30, -17.97, 1.93, "wild_jungles");
	Build_at("Cayman_jungle_07", "jungle2", "", 13.14, 0.30, -17.97, 1.93, "wild_jungles");
	Build_at("Cayman_jungle_08", "jungle", "", -44.09, -2.55, -103.96, -2.61, "wild_jungles");
	Build_at("Cayman_jungle_08", "jungle2", "", -44.09, -2.55, -103.96, -2.61, "wild_jungles");
	Build_at("Cayman_jungle_08", "jungle", "", -17.00, -2.54, -136.73, -2.08, "wild_jungles");
	Build_at("Cayman_jungle_08", "jungle2", "", -17.00, -2.54, -136.73, -2.08, "wild_jungles");

}
