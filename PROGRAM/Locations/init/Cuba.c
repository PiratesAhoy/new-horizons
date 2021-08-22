void LocationInitCuba(ref n)
{
	// -------------------------------------------------
	Locations[n].id = "Cuba_port";
	locations[n].id.label = "#stown_name# port";
	locations[n].worldmap = "Havana";
	Locations[n].filespath.models = "locations\Town_Redmond\Port";
	Locations[n].filespath.textures = "locations\SPAIN";
	Locations[n].image = "Town_Redmond_Port_Spain.tga";

	//Town sack
	Locations[n].townsack = "Havana";
	if(GetCurrentPeriod() >= PERIOD_COLONIAL_POWERS) Locations[n].navy = 1;

	//Sound
	locations[n].type = "port";
	locations[n].fastreload = "Havana";
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	Locations[n].models.always.l1 = "RedPort";
	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.locators = "RedPort_l";
	Locations[n].models.always.grassPatch = "Redport_g";
    Locations[n].models.always.seabed = "RedPort_sb";
	Locations[n].models.always.seabed.foam = "1";

	//Day
	Locations[n].models.day.charactersPatch = "RedPort_pd";
	Locations[n].models.day.rinok = "RedPort_e01"; //рынок
	Locations[n].models.day.fonar = "RedPort_fd";
	Locations[n].models.day.jumppatch = "RedPort_j";
	//Night
	Locations[n].models.night.charactersPatch = "Redport_pn";
	Locations[n].models.night.fonar = "Redport_fn";
	Locations[n].models.night.jumppatch = "RedPort_j";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	//Reload map
	Locations[n].reload.l1.name = "reload_2_city";
	Locations[n].reload.l1.go = "Havana_town_01";
	Locations[n].reload.l1.emerge = "reload_from_port";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].reload.l2.name = "sea_1";
	Locations[n].reload.l2.go = "Cuba";
	Locations[n].reload.l2.emerge = "reload_3";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";

	Locations[n].locators_radius.reload.sea_1 = 3.0;

	Locations[n].reload.l3.name = "sea_2";
	Locations[n].reload.l3.go = "Cuba";
	Locations[n].reload.l3.emerge = "reload_3";
	Locations[n].reload.l3.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l3.label = "Ship.";
	else
		Locations[n].reload.l3.label = "Sea.";
	Locations[n].locators_radius.reload.sea_2 = 3.0;

	Locations[n].reload.l4.name = "sea_1_back";
	Locations[n].reload.l4.go = "Cuba";
	Locations[n].reload.l4.emerge = "reload_3";
	Locations[n].reload.l4.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l4.label = "Ship.";
	else
		Locations[n].reload.l4.label = "Sea.";
	Locations[n].locators_radius.reload.sea_1_back = 2.0;

	Locations[n].reload.l5.name = "sea_2_back";
	Locations[n].reload.l5.go = "Cuba";
	Locations[n].reload.l5.emerge = "reload_3";
	Locations[n].reload.l5.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l5.label = "Ship.";
	else
		Locations[n].reload.l5.label = "Sea.";
	Locations[n].locators_radius.reload.sea_2_back = 2.0;

	Locations[n].reload.l6.name = "Door_1";
	Locations[n].reload.l6.go = "";
	Locations[n].reload.l6.emerge = "";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Head Port House.";

	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;

	//-----------------------------------------------------------------
	Locations[n].id = "Havana_Town_01";
	locations[n].id.label = "#stown_name#";
	locations[n].worldmap = "Havana";
	Locations[n].filespath.models = "locations\Town_Redmond\Town_01";
	Locations[n].filespath.textures = "locations\SPAIN";
	Locations[n].image = "Town_Redmond_Town_01_Spain.tga";

	//Town sack
	Locations[n].townsack = "Havana";

	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "Havana";
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	Locations[n].models.always.L1 = "Red01";
	Locations[n].models.always.locators = "Red01_l";
	Locations[n].models.always.grassPatch = "Red01_g";
	//River
	Locations[n].models.always.dno = "Red01_rb01";
	Locations[n].models.always.dno.level = 95;
	Locations[n].models.always.dno.uvslide.u1 = -0.12;
	Locations[n].models.always.dno.uvslide.v1 = -0.03;
	Locations[n].models.always.dno.tech = "LocationRiverFloor";
	Locations[n].models.always.mirrow = "Red01_re01";
	Locations[n].models.always.mirrow.level = 96;
	Locations[n].models.always.dnoBlend = "Red01_rb01";
	Locations[n].models.always.dnoBlend.level = 97;
	Locations[n].models.always.dnoBlend.uvslide.u1 = -0.1;
	Locations[n].models.always.dnoBlend.uvslide.v1 = 0.04;
	Locations[n].models.always.dnoBlend.tech = "LocationRiverFloorBlend";
	Locations[n].models.always.river = "Red01_rt01";
	Locations[n].models.always.river.level = 98;
	Locations[n].models.always.river.uvslide.v0 = -0.1;
	Locations[n].models.always.river.uvslide.u1 = 0.15;
	Locations[n].models.always.river.tech = "LocationRiver";

	//Day
	Locations[n].models.day.fonar = "Red01_fd";
	Locations[n].models.day.charactersPatch = "Red01_p";
	Locations[n].models.day.rinok = "Red01_e01";
	//Night
	Locations[n].models.night.fonar = "Red01_fn";
	Locations[n].models.night.charactersPatch = "Red01_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload_1_4";
	Locations[n].reload.l1.go = "Havana_Town_05";
	Locations[n].reload.l1.emerge = "reload_4_1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload_1_4 = 2.0;

	Locations[n].reload.l2.name = "reload_1_4_back";
	Locations[n].reload.l2.go = "Havana_Town_05";
	Locations[n].reload.l2.emerge = "reload_4_1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload_1_4_back = 2.0;

/*	Locations[n].reload.l2.name = "reload_1_2";
	Locations[n].reload.l2.go = "Redmond_Town_02";
	Locations[n].reload.l2.emerge = "reload_2_1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Redmond. Centrum.";
	Locations[n].locators_radius.reload.reload_1_2 = 2.0;

	Locations[n].reload.l22.name = "reload_1_2_back";
	Locations[n].reload.l22.go = "Redmond_Town_02";
	Locations[n].reload.l22.emerge = "reload_2_1";
	Locations[n].reload.l22.autoreload = "1";
	Locations[n].reload.l22.label = "Redmond. Centrum.";
	Locations[n].locators_radius.reload.reload_1_2_back = 2.0;*/

	Locations[n].reload.l3.name = "reload_1_3";
	Locations[n].reload.l3.go = "Havana_Town_02";
	Locations[n].reload.l3.emerge = "reload10";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload_1_3 = 3.0;

	Locations[n].reload.l4.name = "reload_1_3_back";
	Locations[n].reload.l4.go = "Havana_Town_02";
	Locations[n].reload.l4.emerge = "reload10";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload_1_3_back = 3.0;

	Locations[n].reload.l5.name = "reload_from_port";
	Locations[n].reload.l5.go = "Cuba_port";
	Locations[n].reload.l5.emerge = "reload_2_city";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Sea port.";

	Locations[n].reload.l6.name = "reload_2_3";
	Locations[n].reload.l6.go = "Havana_Town_02";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload_2_3 = 2.0;

	Locations[n].reload.l7.name = "reload_2_4_back";
	Locations[n].reload.l7.go = "Havana_Town_05";
	Locations[n].reload.l7.emerge = "reload_4_2";
	Locations[n].reload.l7.autoreload = "1";
	Locations[n].reload.l7.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload_2_4_back = 2.0;

	Locations[n].reload.l8.name = "reload_2_4";
	Locations[n].reload.l8.go = "Havana_Town_05";
	Locations[n].reload.l8.emerge = "reload_4_2";
	Locations[n].reload.l8.autoreload = "1";
	Locations[n].reload.l8.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload_2_4 = 2.0;

	Locations[n].reload.l9.name = "shipyard";
	Locations[n].reload.l9.go = "Havana_shipyard";
	Locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "#stown_name#.";
	Locations[n].reload.l9.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l9.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l10.name = "door_6";
	Locations[n].reload.l10.go = "Havana_House_01";
	Locations[n].reload.l10.emerge = "reload1";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "Loanshark's Office.";
	Locations[n].reload.l10.close_for_night = 1;

    Locations[n].reload.l11.name = "door_1";
	Locations[n].reload.l11.go = "Havana_store";
	Locations[n].reload.l11.emerge = "reload1";
	Locations[n].reload.l11.autoreload = "0";
	Locations[n].reload.l11.label = "Store.";
	Locations[n].reload.l11.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l11.goto_disable = 1; // Screwface: Disable Go-To location

    Locations[n].reload.l12.name = "door_11";
	Locations[n].reload.l12.go = "";
	Locations[n].reload.l12.emerge = "reload1";
	Locations[n].reload.l12.autoreload = "0";
	Locations[n].reload.l12.label = "Store.";
	Locations[n].reload.l12.close_for_night = 1;

    Locations[n].reload.l13.name = "door_5";
	Locations[n].reload.l13.go = "Havana_House_03";
	Locations[n].reload.l13.emerge = "reload1";
	Locations[n].reload.l13.autoreload = "0";
	Locations[n].reload.l13.label = "Residence.";
	Locations[n].reload.l13.close_for_night = 1;

    Locations[n].reload.l14.name = "door_55";
	Locations[n].reload.l14.go = "Damski_House";
	Locations[n].reload.l14.emerge = "reload1";
	Locations[n].reload.l14.autoreload = "0";
	Locations[n].reload.l14.label = "Damski's House";
	Locations[n].reload.l14.disable = true;	

/*	Locations[n].reload.l7.name = "door_5";
	Locations[n].reload.l7.go = "Redmond_HouseInsideR5(01)";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Дом.";
	Locations[n].reload.l7.close_for_night = 1;

	Locations[n].reload.l8.name = "door_7";
	Locations[n].reload.l8.go = "Redmond_HouseInsideR7(01)";
	Locations[n].reload.l8.emerge = "reload1";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "Дом.";

	Locations[n].reload.l9.name = "door_3";
	Locations[n].reload.l9.go = "Redmond_HouseInsideR3(01)";
	Locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "Дом.";

	Locations[n].reload.l10.name = "door_1";
	Locations[n].reload.l10.go = "Redmond_HouseInsideR1(01)";
	Locations[n].reload.l10.emerge = "reload1";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "Дом.";*/

	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;


	// -------------------------------------------------
	Locations[n].id = "Havana_town_05";
	locations[n].id.label = "#stown_name#";
	locations[n].worldmap = "Havana";
	Locations[n].filespath.models = "locations\Town_Redmond\Town_04";
	Locations[n].filespath.textures = "locations\SPAIN";
	Locations[n].image = "Town_Redmond_Town_04_Spain.tga";

	//Town sack
	Locations[n].townsack = "Havana";

	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "Havana";
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	Locations[n].models.always.locators = "Red04_l";
	Locations[n].models.always.city = "Red04";
	Locations[n].models.always.dno = "Red04_rb";
	Locations[n].models.always.dno.level = 95;
	Locations[n].models.always.dno.uvslide.u1 = -0.12;
	Locations[n].models.always.dno.uvslide.v1 = -0.03;
	Locations[n].models.always.dno.tech = "LocationRiverFloor";
	Locations[n].models.always.mirrow = "Red04_re";
	Locations[n].models.always.mirrow.level = 96;
	Locations[n].models.always.dnoBlend = "Red04_rb";
	Locations[n].models.always.dnoBlend.level = 97;
	Locations[n].models.always.dnoBlend.uvslide.u1 = -0.1;
	Locations[n].models.always.dnoBlend.uvslide.v1 = 0.04;
	Locations[n].models.always.dnoBlend.tech = "LocationRiverFloorBlend";
	Locations[n].models.always.river = "Red04_rt";
	Locations[n].models.always.river.level = 98;
	Locations[n].models.always.river.uvslide.v0 = -0.1;
	Locations[n].models.always.river.uvslide.v1 = 0.15;
	Locations[n].models.always.river.tech = "LocationRiver";
	Locations[n].models.always.grassPatch = "Red04_g";

	//Day
	Locations[n].models.day.fonar = "Red04_fd";
	Locations[n].models.day.rinok = "Red04_e01";
	Locations[n].models.day.charactersPatch = "Red04_pd";
	//Night
	Locations[n].models.night.fonar = "Red04_fn";
	Locations[n].models.night.charactersPatch = "Red04_pn";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload_4_2";
	Locations[n].reload.l1.go = "Havana_Town_01";
	Locations[n].reload.l1.emerge = "reload_2_4";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Center.";
	Locations[n].locators_radius.reload.reload_4_2 = 2.0;

	Locations[n].reload.l21.name = "reload_4_2_back";
	Locations[n].reload.l21.go = "Havana_Town_01";
	Locations[n].reload.l21.emerge = "reload_2_4";
	Locations[n].reload.l21.autoreload = "1";
	Locations[n].reload.l21.label = "Center.";
	Locations[n].locators_radius.reload.reload_4_2_back = 2.0;

	Locations[n].reload.l2.name = "reload_4_1";
	Locations[n].reload.l2.go = "Havana_Town_01";
	Locations[n].reload.l2.emerge = "reload_1_4";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload_4_1 = 2.0;

	Locations[n].reload.l22.name = "reload_4_1_back";
	Locations[n].reload.l22.go = "Havana_Town_01";
	Locations[n].reload.l22.emerge = "reload_1_4";
	Locations[n].reload.l22.autoreload = "1";
	Locations[n].reload.l22.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload_4_1_back = 2.0;

	Locations[n].reload.l3.name = "reload_2_jungle";
	Locations[n].reload.l3.go = "Havana_Outskirts"; // KK
	Locations[n].reload.l3.emerge = "Reload2";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Jungle.";

	Locations[n].reload.l4.name = "door_7";
	Locations[n].reload.l4.go = "Havana_prison";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Prison.";
//	Locations[n].reload.l4.close_for_night = 1; Quest purposes (Bartolomeu Main Quest)
	Locations[n].locators_radius.reload.reload1 = 0.75;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l4.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l7.name = "door_1";
	Locations[n].reload.l7.go = "";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "House.";
	Locations[n].reload.l7.close_for_night = 0;
	Locations[n].locators_radius.reload.reload1 = 0.75;

	Locations[n].reload.l9.name = "door_2";
	Locations[n].reload.l9.go = "";
	Locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "House.";
	Locations[n].reload.l9.close_for_night = 0;
	Locations[n].locators_radius.reload.reload1 = 0.75;

	Locations[n].reload.l10.name = "door_4";
	Locations[n].reload.l10.go = "";
	Locations[n].reload.l10.emerge = "reload1";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "House.";
	Locations[n].reload.l10.close_for_night = 0;
	Locations[n].locators_radius.reload.reload1 = 0.75;

	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Town_Havana\center";

	Locations[n].id = "Havana_Town_02";
	locations[n].id.label = "#stown_name# town";
	Locations[n].image = "Town_Havana_center.tga";
	locations[n].worldmap = "Havana";

	//Town sack
	Locations[n].townsack = "Havana";

	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "Havana";
	//Models
	//Always
	Locations[n].models.always.locators = "Havana_center_l";
	//Locations[n].models.always.grassPatch = "DouTown_g";
	Locations[n].models.always.town = "Havana_center";
	Locations[n].models.always.add = "light";
	Locations[n].models.always.tree = "tree";
	Locations[n].models.always.l5 = "fontain";
	Locations[n].models.always.l5.uvslide.v0 = -0.5;
	Locations[n].models.always.l5.uvslide.v1 = 0.0;
	Locations[n].models.always.l5.level = 50;
	Locations[n].models.always.l5.tech = "LocationWaterFall";
	Locations[n].models.always.l6 = "bottom";
	Locations[n].models.always.l6.uvslide.u0 = 0.04;
	Locations[n].models.always.l6.uvslide.v0 = 0.01;
	Locations[n].models.always.l6.level = 999;
	Locations[n].models.always.l6.tech = "LocationWaterFall";	
	//Day
	//Locations[n].models.day.rinok = "DouTown_e01";
	//Locations[n].models.day.fonar = "DouTown_fd";
	Locations[n].models.day.charactersPatch = "walk_patch";
	//Locations[n].models.day.jumppatch = "DouTown_j";

	//Night
	//Locations[n].models.night.fonar = "DouTown_fn";
	Locations[n].models.night.charactersPatch = "walk_patch";
	//Locations[n].models.night.jumppatch = "DouTown_j";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload9";
	Locations[n].reload.l1.go = "Havana_fakefort1";
	Locations[n].reload.l1.emerge = "reloadc3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Sea port.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l1.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l2.name = "reload1";
	Locations[n].reload.l2.go = "Havana_town_01";
	Locations[n].reload.l2.emerge = "reload_2_3";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name#.";	

	// --> RobC/Alan_Smithee Blacksmith mod
	if (ENABLE_WEAPONSMOD)
	{
		Locations[n].reload.l5.name = "reload4";
		Locations[n].reload.l5.go = "Havana_blacksmith";
		Locations[n].reload.l5.emerge = "reload1";
		Locations[n].reload.l5.autoreload = "0";
		Locations[n].reload.l5.label = "Smithy.";
		Locations[n].reload.l5.close_for_night = 1;
		if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l5.goto_disable = 1; // Screwface: Disable Go-To location
	}
	// RobC/Alan_Smithee Blacksmiths <--

	Locations[n].reload.l7.name = "reload15";
	Locations[n].reload.l7.go = "Havana_townhall";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Residence.";
	Locations[n].reload.l7.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l7.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l8.name = "reload18";
	Locations[n].reload.l8.go = "Havana_tavern";
	Locations[n].reload.l8.emerge = "reload1";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "Tavern";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l8.goto_disable = 1; // Screwface: Disable Go-To location
	
	Locations[n].reload.l4.name = "door_6";
	Locations[n].reload.l4.go = "Havana_church";
	Locations[n].reload.l4.emerge = "Reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Church.";
	Locations[n].reload.l4.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l4.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l3.name = "door_5";
	Locations[n].reload.l3.go = "Havana_church";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Church.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l3.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l10.name = "reload10_back";
	Locations[n].reload.l10.go = "Havana_Town_01";
	Locations[n].reload.l10.emerge = "reload_1_3";
	Locations[n].reload.l10.autoreload = "1";
	Locations[n].reload.l10.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload10_back = 2.0;	

	Locations[n].reload.l6.name = "reload10";
	Locations[n].reload.l6.go = "Havana_Town_01";
	Locations[n].reload.l6.emerge = "reload_1_3";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload10 = 2.0;

	Locations[n].reload.l9.name = "reload7";
	Locations[n].reload.l9.go = "Suarez_House";
	Locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "Suarez's house";
	Locations[n].reload.l9.close_for_night = 1;

	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;
	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\MediumStore";
	Locations[n].image = "Inside_MediumStore.tga";

	Locations[n].id = "Havana_Store";
	locations[n].id.label = "#stown_name# store";

	//Town sack
	Locations[n].townsack = "Havana";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Havana";
	//Models
	//Always
	Locations[n].models.always.locators = "MS_l";
	Locations[n].models.always.store = "MS";
	Locations[n].models.always.window = "MS_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "MS_p";

	//Night
	Locations[n].models.night.charactersPatch = "MS_p";
	//Environment

	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\coms_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Havana_town_01";
	Locations[n].reload.l1.emerge = "door_1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	Locations[n].locators_radius.camdetector.camera1 = 5;
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;

 	// -------------------------------------------------
	Locations[n].id = "Havana_Shipyard";
	locations[n].id.label = "#stown_name# shipyard";
	Locations[n].filespath.models = "locations\inside\Shipyard";
	Locations[n].image = "Inside_Shipyard1.tga";

	//Town sack
	Locations[n].townsack = "Havana";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Havana";
	//Models
	Locations[n].models.back = "back\redsh1_";
	//Always
	Locations[n].models.always.locators = "sh01_l";
	Locations[n].models.always.shipyard = "sh01";
	Locations[n].models.always.window = "sh01_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "sh01_p";
	Locations[n].models.day.fd = "Sh01_fd";

	//Night
	Locations[n].models.night.charactersPatch = "sh01_p";
	Locations[n].models.night.fn = "Sh01_fn";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Havana_Town_01";
	Locations[n].reload.l1.emerge = "shipyard";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;
	
	// -------------------------------------------------
	Locations[n].id = "Havana_tavern";
	locations[n].id.label = "#stown_name# tavern";	
	Locations[n].filespath.models = "locations\inside\Tavern_2";
	Locations[n].image = "Inside_Tavern_2.tga";

	//Town sack
	Locations[n].townsack = "Havana";

	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "Havana";
	//Models
	//Always
	Locations[n].models.always.tavern = "Tavern_2";
	Locations[n].models.always.locators = "tavern_2_l_Havana";
	//Day
	Locations[n].models.day.charactersPatch = "Tavern_2_p";

	//Night
	Locations[n].models.night.charactersPatch = "Tavern_2_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\DOUMH_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Havana_town_02";
	Locations[n].reload.l1.emerge = "reload18";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	LAi_LocationFightDisable(&Locations[n], true);

//MAXIMUS -->
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Havana_tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Room in #stown_name# tavern.";
	LAi_LocationFightDisable(&Locations[n], true);
//MAXIMUS <--

	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;
	
	// -------------------------------------------------
	Locations[n].id = "Havana_tavern_upstairs";
	locations[n].id.label = "Room in #stown_name# tavern";
	Locations[n].image = "Inside_Doubleflour_House_Room.tga";

	//Town sack
	Locations[n].townsack = "Havana";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Havana";
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
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redlf2_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Havana_tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# tavern."; // KK
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;

// KK ------------------------------------------------->

	Locations[n].id = "Havana_townhall";
	locations[n].id.label = "#stown_name# residence";
	Locations[n].image = "Town_Havana_Townhall.tga";
	Locations[n].filespath.models = "locations\Town_Havana\Residence2";

	//Town sack
	Locations[n].townsack = "Havana";

	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Havana";
	//Models
	//Always
	Locations[n].models.always.city = "Res02";
	Locations[n].models.always.locators = "Res02_l_ttt";
	Locations[n].models.always.window = "Res02_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
//	Locations[n].models.day.lamp = "FalaiseDeFleur05_day";
	Locations[n].models.day.charactersPatch = "Res02_p";

	//Night
//	Locations[n].models.night.lamp = "FalaiseDeFleur05_night";
	Locations[n].models.night.charactersPatch = "Res02_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\mures2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Havana_town_02";
	Locations[n].reload.l1.emerge = "reload15";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Townhall_bedroom";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name#.";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].items.randitem1 = "pistol6";


	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;
	
	//  -------------------------------------------------
	Locations[n].id = "Townhall_bedroom";
	locations[n].id.label = "Bedroom";
	Locations[n].filespath.models = "locations\Town_Havana\ResBedRoom";
	Locations[n].image = "Inside_ResBedRoom.tga";

	//Town sack
	Locations[n].townsack = "Havana";

	//Sound
	locations[n].type = "Residence";
	locations[n].fastreload = "Havana";
	//Models
	//Always
	Locations[n].models.always.locators = "bed_l";
	Locations[n].models.always.l1 = "bed";
	Locations[n].models.always.window = "bed_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "bed_p";

	//Night
	Locations[n].models.night.charactersPatch = "bed_p";	

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redb_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";		
	Locations[n].reload.l1.go = "Havana_Townhall";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# residence.";

	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;
	
	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Residence3_Spa";

	Locations[n].id = "Suarez_House";
	locations[n].id.label = "House";
	Locations[n].image = "Inside_Residence3.tga";

	//Town sack
	Locations[n].townsack = "Havana";
	locations[n].fastreload = "Havana";	
	//Sound
	locations[n].type = "Residence";
	//Models
	//Always
	Locations[n].models.always.locators = "Res03_l_BoP1";
	Locations[n].models.always.l1 = "Res03";
	Locations[n].models.always.window = "Res03_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Res03_p";

	//Night
	Locations[n].models.night.charactersPatch = "Res03_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Locations[n].models.back = "back\mures3_";
	Locations[n].models.back = "back\redrsb_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Havana_town_02";
	Locations[n].reload.l1.emerge = "reload7";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].island = "Cuba";
	n = n + 1;	
	
	// Thomas the Terror => -------------------------------------------------
	Locations[n].id = "Havana_church";
	locations[n].id.label = "#stown_name# church";
	Locations[n].image = "Inside_Church_inside.tga";

	//Town sack
	Locations[n].townsack = "Havana";

	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "Havana";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Church_inside";
	Locations[n].models.always.city = "Church";
	Locations[n].models.always.locators = "Church_l";
	Locations[n].models.always.window = "church_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
//	Locations[n].models.day.lamp = "FalaiseDeFleur05_day";
	Locations[n].models.day.charactersPatch = "Church_p";

	//Night
//	Locations[n].models.night.lamp = "FalaiseDeFleur05_night";
	Locations[n].models.night.charactersPatch = "Church_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Havana_town_02";
	Locations[n].reload.l1.emerge = "door_6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";
	
	Locations[n].reload.l2.name = "reload3";
	Locations[n].reload.l2.go = "Havana_town_02";
	Locations[n].reload.l2.emerge = "door_5";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name#";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;
	
	//  -------------------------------------------------
	Locations[n].id = "Havana_prison";
	locations[n].id.label = "#stown_name# prison";
	Locations[n].filespath.models = "locations\inside\prison";
	Locations[n].image = "Inside_Prison.tga";

	//Town sack
	Locations[n].townsack = "Havana";

	//Sound
	locations[n].type = "jail";
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	Locations[n].models.always.prison = "Pri";
	Locations[n].models.always.locators = "Pri_l";
	Locations[n].models.always.window = "Pri_w";
	//Locations[n].models.always.flame = "prison_flame";
	//Day
	Locations[n].models.day.charactersPatch = "Pri_p";
	//Night
	Locations[n].models.night.charactersPatch = "Pri_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Havana_town_05";
	Locations[n].reload.l1.emerge = "door_7";
	Locations[n].reload.l1.label = "#stown_name#.";

	locations[n].reload.l2.name = "reload12";
	locations[n].reload.l2.go = "";
	locations[n].reload.l2.emerge = "reload12";
	locations[n].reload.l2.disable = 1;
	Locations[n].locators_radius.reload.reload12 = 0.5;
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;
	//  -------------------------------------------------------------
	Locations[n].filespath.models = "locations\town_Conceicao\exit";
	Locations[n].filespath.textures = "locations\SPAIN";

	Locations[n].id = "Havana_Outskirts";
	locations[n].id.label = "#stown_name# Outskirts.";
	Locations[n].image = "Town_Conceicao_Exit_Spain.tga";

	//Town sack
	Locations[n].townsack = "Havana";

	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);
	//Models
	//Always
	Locations[n].models.always.locators = "ConExit_l";
	Locations[n].models.always.exit = "ConExit";
	Locations[n].models.always.grassPatch = "ConExit_g";
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
	Locations[n].models.day.fonar = "ConExit_fd";
	Locations[n].models.day.charactersPatch = "ConExit_p";
	//Night
	Locations[n].models.night.fonar = "ConExit_fn";
	Locations[n].models.night.charactersPatch = "ConExit_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Cuba_Jungle_01";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1 = 2;

	Locations[n].reload.l3.name = "Reload1_back";
	Locations[n].reload.l3.go = "Cuba_Jungle_01";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1_back = 2;

	Locations[n].reload.l2.name = "Reload2";
	Locations[n].reload.l2.go = "Havana_Town_05";
	Locations[n].reload.l2.emerge = "reload_2_jungle";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload2 = 1.5;

	Locations[n].island = "Cuba";
	n = n + 1;
// <-- KK

	// Havana--------------------------------------

	//ID
	Locations[n].id = "Havana_fakefort1";		//new ID
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";	//A warning sign at the gate :)
	//Info
	Locations[n].filespath.models = "locations\Fort_Inside\Fort_1";
	Locations[n].filespath.textures = "locations\SPAIN";
	Locations[n].image = "Fort_Inside_Fort_1.tga";

	//Town sack
	Locations[n].townsack = "Havana";		//change
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
	Locations[n].reload.l1.name = "reloadc3";
	Locations[n].reload.l1.go = "Havana_town_02";
	Locations[n].reload.l1.emerge = "reload9";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reloadC4";
	Locations[n].reload.l2.go = "Havana_fakefort2";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l3.name = "reloadc5";
	Locations[n].reload.l3.go = "Havana_armory";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].reload.l4.name = "reloadc1";
	Locations[n].reload.l4.go = "Havana_fakefort3";
	Locations[n].reload.l4.emerge = "reloadc1";
	Locations[n].reload.l4.autoreload = "0";

	Locations[n].island = "Cuba"; // NK 04-08-29	
	n = n + 1;

	// Havana fake fort 2----------------------------------

	//ID
	Locations[n].id = "Havana_fakefort2";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";

	//Town sack
	Locations[n].townsack = "Havana";


	//Info
	Locations[n].filespath.models = "locations\Fort_Inside\Fort_2";
	Locations[n].filespath.textures = "locations\SPAIN";
	Locations[n].image = "Fort_Inside_Fort_1.tga";
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
	Locations[n].reload.l1.go = "Havana_fakefort1";
	Locations[n].reload.l1.emerge = "reloadc4";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reloadc1";
	Locations[n].reload.l2.go = "Havana_fakefort3";
	Locations[n].reload.l2.emerge = "reloadc2";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;

	// Havana fake fort 3----------------------------------

	//ID
	Locations[n].id = "Havana_fakefort3";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";


	//Town sack
	Locations[n].townsack = "Havana";

	//Info
	Locations[n].filespath.models = "locations\Fort_Inside\Fort_3";
	Locations[n].filespath.textures = "locations\SPAIN";
	Locations[n].image = "Fort_Inside_Fort_1.tga";
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
	Locations[n].reload.l1.go = "Havana_fakefort1";
	Locations[n].reload.l1.emerge = "reloadc1";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reloadc2";
	Locations[n].reload.l2.go = "Havana_fakefort2";
	Locations[n].reload.l2.emerge = "reloadc1";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l3.name = "reloadc4";
	Locations[n].reload.l3.go = "Havana_armory";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;


	// ccc oxbay armory-------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\LargeStore";
	Locations[n].id = "Havana_armory";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";
	Locations[n].image = "Fort_Inside_Fort_2.tga";

	//Town sack
	Locations[n].townsack = "Havana";
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
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\douls_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Havana_fakefort1";
	Locations[n].reload.l1.emerge = "reloadc5";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Havana_fakefort3";
	Locations[n].reload.l3.emerge = "reloadC4";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Cuba_shore_01";
	//Locations[n].worldmap = "CubShore 1";
	Locations[n].filespath.models = "locations\Outside\Shore_6";
	Locations[n].image = "Outside_Shore_6.tga";
	locations[n].id.label = "Bahia de San Antonio";
	Locations[n].name = "Bahia de San Antonio";		// TALISMAN added to make beach name appear in smuggler tavern dialog
	//Sound
	locations[n].type = "seashore";
	//Models
	//Always
	Locations[n].models.always.jungle = "Shore06";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.locators = "Shore06_l";
	Locations[n].models.always.grassPatch = "Shore06_g";
	Locations[n].models.always.seabed = "Shore06_sb";
	Locations[n].models.always.seabed.foam = "1";

	//Day
	Locations[n].models.day.charactersPatch = "Shore06_p";
	//Night
	Locations[n].models.night.charactersPatch = "Shore06_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Cuba_Jungle_01";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 3.0;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Cuba_Jungle_01";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 5.0;		//JRH 3.0 was too small

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Cuba";
	Locations[n].reload.l2.emerge = "reload_2";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 9.0;

	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_2";

	Locations[n].id = "Cuba_Jungle_01";
	locations[n].id.label = "Jungle.";
	Locations[n].image = "Outside_Jungle_2.tga";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "Jungle02_l";
	Locations[n].models.always.jungle = "Jungle02";
	Locations[n].models.always.grassPatch = "JUNGLE02_g";
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
	Locations[n].models.day.charactersPatch = "Jungle02_p";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle02_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cuba_Jungle_02";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1 = 4;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Cuba_Jungle_02";
	Locations[n].reload.l4.emerge = "reload3";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 4;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Havana_outskirts";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Outskirts.";
	Locations[n].locators_radius.reload.reload2 = 4;

	Locations[n].reload.l5.name = "reload2_back";
	Locations[n].reload.l5.go = "Havana_outskirts";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Outskirts.";
	Locations[n].locators_radius.reload.reload2_back = 3;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Cuba_shore_01";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Bahia de San Antonio";
	Locations[n].locators_radius.reload.reload3 = 4;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Cuba_shore_01";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Bahia de San Antonio";
	Locations[n].locators_radius.reload.reload3_back = 4;

	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_6";

	Locations[n].id = "Cuba_Jungle_02";
	locations[n].id.label = "Jungle.";		//spell-checked by KAM
	Locations[n].image = "Outside_Jungle_6.tga";
	//Sound
	locations[n].type = "jungle";

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
	Locations[n].reload.l1.go = "Cuba_Shore_03";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 2.5;
	Locations[n].reload.l1.label = "Punta de Maisi";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Cuba_Jungle_03";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload2 = 2.5;
	Locations[n].reload.l2.label = "Jungle.";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Cuba_Jungle_01";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.reload3 = 2.5;
	Locations[n].reload.l3.label = "Jungle.";

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Cuba_Jungle_03";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].locators_radius.reload.reload2_back = 2.5;
	Locations[n].reload.l4.label = "Jungle.";

	Locations[n].reload.l5.name = "reload3_back";
	Locations[n].reload.l5.go = "Cuba_Jungle_01";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].locators_radius.reload.reload3_back = 3;
	Locations[n].reload.l5.label = "Jungle.";

	Locations[n].reload.l6.name = "reload1_back";
	Locations[n].reload.l6.go = "Cuba_Shore_03";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 2.5;
	Locations[n].reload.l6.label = "Punta de Maisi";


	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;

  // -------------------------------------------------
   	Locations[n].id = "Cuba_Shore_03";
	locations[n].id.label = "Punta de Maisi"; // KK
	locations[n].worldmap = "CubShore 3";
	Locations[n].filespath.models = "locations\Outside\Shore_7";
	Locations[n].image = "Outside_Shore_7.tga";
	Locations[n].name = "Punta de Maisi";
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

/*	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan_3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";*/

	//Day
	Locations[n].models.day.charactersPatch = "Shore07_p";
	//Night
	Locations[n].models.night.charactersPatch = "Shore07_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Cuba_Jungle_02";
	Locations[n].reload.l1.emerge = "Reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 3.0;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Cuba_Jungle_02";
	Locations[n].reload.l3.emerge = "Reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3.0;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Cuba";
	Locations[n].reload.l2.emerge = "reload_7";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 9.0;


	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_7";

	Locations[n].id = "Cuba_Jungle_03";
	locations[n].id.label = "Jungle.";
	Locations[n].image = "Outside_Jungle_7.tga";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);


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
	Locations[n].reload.l1.go = "Smugglers_Fort";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Smugglers Fort";
	Locations[n].locators_radius.reload.reload1 = 4;

	Locations[n].reload.l5.name = "reload1_back";
	Locations[n].reload.l5.go = "Smugglers_Fort";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Smugglers Fort";
	Locations[n].locators_radius.reload.reload1_back = 1;

	Locations[n].reload.l4.name = "reload2";
	Locations[n].reload.l4.go = "Cuba_Jungle_02";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 4;

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Cuba_Jungle_02";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Cuba_Shore_04";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Playa de Sabana";
	Locations[n].locators_radius.reload.reload3 = 4;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Cuba_Shore_04";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Playa de Sabana";
	Locations[n].locators_radius.reload.reload3_back = 2;


	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Shore_2";

	Locations[n].id = "Cuba_Shore_04";
	locations[n].id.label = "Playa de Sabana"; // KK
	locations[n].worldmap = "CubShore 4";
	Locations[n].image = "Outside_Shore_2.tga";
	Locations[n].name = "Playa de Sabana";
	//Sound
	locations[n].type = "seashore";
	//Models
	//Always
	Locations[n].models.always.jungle = "Shore02";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.locators = "Shore02_l";
	Locations[n].models.always.grassPatch = "Shore02_g";
	Locations[n].models.always.seabed = "Shore02_sb";
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
	Locations[n].models.day.charactersPatch = "Shore02_p";
	//Night
	Locations[n].models.night.charactersPatch = "Shore02_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Cuba_Jungle_03";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 3.0;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Cuba_Jungle_03";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3.0;
// SJG -->
	Locations[n].reload.l4.name = "reload3";
	Locations[n].reload.l4.go = "Prison_Shore";
	Locations[n].reload.l4.emerge = "reload4";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Prison Shore";
	Locations[n].locators_radius.reload3 = 3.0;
//<-- SJG
	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Cuba";
	Locations[n].reload.l2.emerge = "reload_9";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 9.0;


	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Pirate Fort";

	Locations[n].id = "Smugglers_Fort";
	locations[n].id.label = "Smugglers Fort";
	Locations[n].image = "Pirate_Fort.tga";

	//Town sack
	Locations[n].townsack = "Smugglers Fort"; // NK 04-08-29

	//Sound
	locations[n].type = "jungle";

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
	Locations[n].reload.l1.go = "Cuba_Jungle_03";
	Locations[n].reload.l1.emerge = "Reload1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].reload.l1.autoreload = 1;
	Locations[n].locators_radius.reload.reload1 = 1;

	Locations[n].reload.l5.name = "Reload1_back";
	Locations[n].reload.l5.go = "Cuba_Jungle_03";
	Locations[n].reload.l5.emerge = "Reload1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].reload.l5.autoreload = 1;
	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].reload.l2.name = "Reload5";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "";
	Locations[n].reload.l2.label = "";

	Locations[n].reload.l3.name = "Reload6";
	Locations[n].reload.l3.go = "";
	Locations[n].reload.l3.emerge = "";
	Locations[n].reload.l3.label = "";

	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Shore_5";

	Locations[n].id = "Cuba_Shore_05";
	locations[n].id.label = "Playa de Sierra Maestra"; // KK
	Locations[n].image = "Outside_Shore_5.tga";
	Locations[n].name = "Playa de Sierra Maestra";
	locations[n].worldmap = "CubShore 5";

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
	Locations[n].reload.l1.go = "Cuba_Jungle_04";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 3;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Cuba_Jungle_04";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Cuba";
	Locations[n].reload.l2.emerge = "reload_8";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Sea.";
        Locations[n].locators_radius.reload.boat = 9.0;


	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_1";

	Locations[n].id = "Cuba_Jungle_04";
	locations[n].id.label = "Jungle.";
	Locations[n].image = "Outside_Jungle_1.tga";
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

	//Reload map
	if(sti(GetStorylineVar(FindCurrentStoryline(), "BART_PUZZLES")) > 0)
	{
		Locations[n].reload.l2.name = "reload2";
		Locations[n].reload.l2.go = "Santiago_outskirts";	// Bartolomeu storyline: link to outskirts with warehouses
		Locations[n].reload.l2.emerge = "reload1";
		Locations[n].reload.l2.autoreload = "1";
		Locations[n].reload.l2.label = "Santiago outskirts";
		Locations[n].locators_radius.reload.Reload2 = 3.0; 

		Locations[n].reload.l4.name = "reload2_back";
		Locations[n].reload.l4.go = "Santiago_outskirts";
		Locations[n].reload.l4.emerge = "reload1";
		Locations[n].reload.l4.autoreload = "1";
		Locations[n].reload.l4.label = "Santiago outskirts";
		Locations[n].locators_radius.reload.reload2_back = 2.0;
	}
	else
	{
		Locations[n].reload.l2.name = "reload2";
		Locations[n].reload.l2.go = "Santiago_town_exit1";	// Other storylines: link to normal outskirts
		Locations[n].reload.l2.emerge = "reload1";
		Locations[n].reload.l2.autoreload = "1";
		Locations[n].reload.l2.label = "Santiago outskirts";
		Locations[n].locators_radius.reload.Reload2 = 3.0;

		Locations[n].reload.l4.name = "reload2_back";
		Locations[n].reload.l4.go = "Santiago_town_exit1";
		Locations[n].reload.l4.emerge = "reload1";
		Locations[n].reload.l4.autoreload = "1";
		Locations[n].reload.l4.label = "Santiago outskirts";
		Locations[n].locators_radius.reload.reload2_back = 2.0;
	}

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cuba_Shore_05";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Playa de Sierra Maestra";
	Locations[n].locators_radius.reload.Reload1 = 3.0;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Cuba_Shore_05";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Playa de Sierra Maestra";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_Greenford\exit";

	Locations[n].id = "Santiago_outskirts";
	locations[n].id.label = "outskirts.";
	Locations[n].image = "Town_Greenford_Exit.tga";

	//Town sack
	Locations[n].townsack = "Santiago";

	//Sound
	locations[n].type = "jungle";

	//Models
	//Always
	Locations[n].models.always.locators = "SaExit_l";
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

	Locations[n].reload.l1.name = "Reload2_back";
	Locations[n].reload.l1.go = "Santiago_town_01";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Santiago.";
	Locations[n].locators_radius.reload.Reload2_back = 3;
//	Locations[n].reload.l1.disable = 1;

	Locations[n].reload.l11.name = "Reload2";
	Locations[n].reload.l11.go = "Santiago_town_01";
	Locations[n].reload.l11.emerge = "reload2";
	Locations[n].reload.l11.autoreload = "0";
	Locations[n].reload.l11.label = "Santiago.";
	Locations[n].locators_radius.reload.Reload2 = 3;
//	Locations[n].reload.l11.disable = 1;

	Locations[n].reload.l2.name = "Reload1";
	Locations[n].reload.l2.go = "Cuba_Jungle_04";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1 = 3;

	Locations[n].reload.l3.name = "Reload1_back";
	Locations[n].reload.l3.go = "Cuba_Jungle_04";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1_back = 3;

	Locations[n].reload.l4.name = "Reload3";
	Locations[n].reload.l4.go = "Santiago_warehouse_01";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Warehouse.";
	Locations[n].reload.l4.disable = 1;

	Locations[n].reload.l5.name = "Reload4";
	Locations[n].reload.l5.go = "Santiago_warehouse_02";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Warehouse.";
	Locations[n].reload.l5.disable = 1;

	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	
	Locations[n].filespath.models = "locations\town_QC\port";	
	Locations[n].image = "Town_QC_Port.tga";

	Locations[n].id = "Cuba_Shore_06";
	locations[n].id.label = "Peninsula de Zapata"; // KK
	Locations[n].name = "Peninsula de Zapata";
	locations[n].worldmap = "CubShore 6";

	//Sound
	locations[n].type = "port";
	//locations[n].fastreload = "Havana"; // PB: Definitely NOT "QC"!
//	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	Locations[n].models.always.locators = "QCport_l_smg";
	Locations[n].models.always.port = "QCport";
	Locations[n].models.always.port.foam = "1";
	Locations[n].models.always.sb = "QCport_sb";
	Locations[n].models.always.sb.foam = "1";
	Locations[n].models.always.grassPatch = "QCport_g";
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
	Locations[n].models.day.charactersPatch = "QCport_p";
	Locations[n].models.day.jumpPatch = "QCport_j";
	//Night
	Locations[n].models.night.charactersPatch = "QCport_p";
	Locations[n].models.night.jumpPatch = "QCport_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map

	Locations[n].reload.l1.name = "reload3";
	Locations[n].reload.l1.go = "Cuba_exit_grot";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Exit from Cave";
	Locations[n].locators_radius.reload.reload3 = 1.0;

	Locations[n].reload.l2.name = "reload1";
	Locations[n].reload.l2.go = "Cuba";
	Locations[n].reload.l2.emerge = "reload_6";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.reload1 = 3.0;

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Cuba";
	Locations[n].reload.l3.emerge = "reload_6";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Sea.";
	Locations[n].locators_radius.reload.reload2 = 3.0;

	Locations[n].reload.l4.name = "reload3_back";
	Locations[n].reload.l4.go = "Cuba_exit_grot";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Exit from Cave";
	Locations[n].locators_radius.reload.reload3_back = 1.0;

	Locations[n].vcskip = true; // KK

	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Cave Entrance";

	Locations[n].id = "Cuba_exit_grot";
	locations[n].id.label = "Cave entrance";
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
	Locations[n].reload.l3.go = "Cuba_Grot";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Cave.";
	Locations[n].locators_radius.reload.Reload1 = 1;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Cuba_Grot";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Cave.";
	Locations[n].locators_radius.reload.Reload1_back = 1.3;

	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Cuba_Shore_06";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Peninsula de Zapata";
	Locations[n].locators_radius.reload.Reload2 = 2.0;

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Cuba_Shore_06";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Peninsula de Zapata";
	Locations[n].locators_radius.reload.reload2_back = 2.0;

	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;

      //----------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Grot";

	Locations[n].id = "Cuba_Grot";
	locations[n].id.label = "Small Cave";
	Locations[n].image = "Inside_Grot.tga";
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
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cuba_exit_grot";
	Locations[n].reload.l1.emerge = "Reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Cave entrance";

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Cuba_exit_grot";
	Locations[n].reload.l2.emerge = "Reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Cave entrance";
	Locations[n].locators_radius.reload.reload1_back = 2;

	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 0, 24);

	Locations[n].items.randitem1 = "bladeC12";


	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;

 	// -------------------------------------------------
	Locations[n].id = "Santiago_warehouse_01";
	locations[n].id.label = "Santiago warehouse";	
	Locations[n].filespath.models = "locations\inside\Warehouse";
	Locations[n].image = "Inside_Warehouse.tga";

	//Town sack
	Locations[n].townsack = "Santiago";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Santiago";
	//Models
	//Always
	Locations[n].models.always.locators = "warehouse_l";
	Locations[n].models.always.shipyard = "warehouse";
	//Day
	Locations[n].models.day.charactersPatch = "warehouse_p";
	//Night
	Locations[n].models.night.charactersPatch = "warehouse_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Santiago_outskirts";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Santiago.";

	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;

 	// -------------------------------------------------
	Locations[n].id = "Santiago_warehouse_02";
	locations[n].id.label = "Santiago warehouse";
	Locations[n].filespath.models = "locations\inside\Warehouse";
	Locations[n].image = "Inside_Warehouse.tga";

	//Town sack
	Locations[n].townsack = "Santiago";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Santiago";
	//Models
	//Always
	Locations[n].models.always.locators = "warehouse_l";
	Locations[n].models.always.shipyard = "warehouse";
	//Day
	Locations[n].models.day.charactersPatch = "warehouse_p";
	//Night
	Locations[n].models.night.charactersPatch = "warehouse_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Santiago_outskirts";
	Locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Santiago.";

	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;

	// HOUSES
	// -------------------------------------------------

	// -------------------------------------------------
	Locations[n].id = "Havana_House_01";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\DoubleFlour_house";
	Locations[n].image = "Inside_Doubleflour_House_Lower.tga";

	//Town sack
	Locations[n].townsack = "Havana";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Havana";
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
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\mulf2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Havana_town_01";
	Locations[n].reload.l1.emerge = "door_6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Town.";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\MediumHouse2";

	Locations[n].id = "Havana_House_02";
	locations[n].id.label = "House";
	Locations[n].image = "Inside_MediumHouse2.tga";

	//Town sack
	Locations[n].townsack = "Havana"; // NK 04-08-29

	//Sound
	locations[n].type = "house";

	//Models
	//Always
	Locations[n].models.always.locators = "MH02_l";
	Locations[n].models.always.house = "MH02";
	//Locations[n].models.always.env = "smalltavern_env";
	Locations[n].models.always.window = "MH02_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "MH02_p";

	//Night
	Locations[n].models.night.charactersPatch = "MH02_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\smumh2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Havana_town_01";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Town.";

	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;

	// ccc new mansion near yard-------------------------------------------------
	Locations[n].id = "Havana_House_03";
	locations[n].id.label = "Vice Admiral's residence";
	Locations[n].filespath.models = "locations\inside\Residence_BackHall";
	Locations[n].filespath.textures = "locations\SPAIN";
	Locations[n].image = "Inside_Residence_BackHall_Spain.tga";

	//Town sack
	Locations[n].townsack = "Havana";

	//Sound
	locations[n].type = "Residence";
	locations[n].fastreload = "Havana";
	//Models
	//Always
	Locations[n].models.always.locators = "ResB_l";
	Locations[n].models.always.l1 = "ResB";
	Locations[n].models.always.window = "ResB_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "ResB_p";
	Locations[n].models.day.lights.candles = "candelabrum_small";

	//Night
	Locations[n].models.night.charactersPatch = "ResB_p";
	Locations[n].models.night.lights.candles = "candelabrum_small";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redrsb_";

	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Havana_House_03_bedroom";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Bedroom.";
	//ccc LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].reload.l2.name = "reload1";
	Locations[n].reload.l2.go = "Havana_town_01";
	Locations[n].reload.l2.emerge = "door_5";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Town.";

	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "Havana_House_03_bedroom";
	locations[n].id.label = "Bedroom";
	Locations[n].filespath.models = "locations\inside\ResBedRoom";
	Locations[n].image = "Inside_ResBedRoom.tga";

	//Town sack
	Locations[n].townsack = "Havana";

	//Sound
	locations[n].type = "Residence";
	locations[n].fastreload = "Havana";
	//Models
	//Always
	Locations[n].models.always.locators = "bed_l";
	Locations[n].models.always.l1 = "bed";
	Locations[n].models.always.window = "bed_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "bed_p";

	//Night
	Locations[n].models.night.charactersPatch = "bed_p";	

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redb_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";		
	Locations[n].reload.l1.go = "Havana_House_03";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "House.";

	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;

	//-----------------------------------------------------------
	Locations[n].id = "Havana_House_04";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\MediumHouse";
	Locations[n].image = "Inside_MediumHouse.tga";

	//Town sack
	Locations[n].townsack = "Havana";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Havana";
	//Models
	//Always
	Locations[n].models.always.locators = "mh_l";
	Locations[n].models.always.shipyard = "mh";
	Locations[n].models.always.window = "mh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "mh_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh_p";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redmh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Havana_Town_01";
	Locations[n].reload.l1.emerge = "reload7";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Town.";

	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;
	
	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\mh3";
	Locations[n].id = "Damski_House";
	locations[n].id.label = "Damski's House";
	Locations[n].image = "Inside_mh3.tga";

	//Town sack
	Locations[n].townsack = "Havana";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Havana";
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
	Locations[n].models.back = "back\mumh3_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Havana_town_01";
	Locations[n].reload.l1.emerge = "door_55";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Town.";
	
	Locations[n].vcskip = true; // KK
	
	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;	

// KK -------------------------------------------------
	Locations[n].filespath.models = "locations\Town_Santiago\port";
	Locations[n].image = "Town_Santiago_port.tga";

	Locations[n].id = "Santiago_port";
	locations[n].id.label = "#stown_name# port.";
	locations[n].worldmap = "Santiago";

	//Town sack
	Locations[n].townsack = "Santiago";

	//Sound
	locations[n].type = "port";
	locations[n].fastreload = "Santiago";
	LAi_LocationFantomsGen(&locations[n], true);
	//Models	
	//Always
	Locations[n].models.always.l1 = "SCport";
	Locations[n].models.always.l1.foam = "1";	
	Locations[n].models.always.locators = "SCport_l";
	Locations[n].models.always.add = "light";
	Locations[n].models.always.tree = "tree";
	//Locations[n].models.always.grassPatch = "SCport_g";
	Locations[n].models.always.add2 = "xiao";
	Locations[n].models.always.add3 = "pole";
	Locations[n].models.always.add4 = "chimneys";	//JRH-->
	Locations[n].models.always.add5 = "palmsPA";		
	Locations[n].models.always.add6 = "palmsPB";		
	Locations[n].models.always.add7 = "cannons";		
	Locations[n].models.always.add8 = "wagons";		
	Locations[n].models.always.add9 = "boats";		
	Locations[n].models.always.add10 = "ladder";	//<--JRH	

	//Day
	//Locations[n].models.day.fonar = "OXport_fd";
	Locations[n].models.day.charactersPatch = "walk_patch";
	//Locations[n].models.day.rinok = "OXport_e1";
	//Night
	//Locations[n].models.night.fonar = "OXport_fn";
	Locations[n].models.night.charactersPatch = "walk_patch";
	//Locations[n].models.night.jumpPatch = "OXport_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Santiago_town_01";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Cuba";
	Locations[n].reload.l3.emerge = "reload_1";
	Locations[n].reload.l3.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l3.label = "Ship.";
	else
		Locations[n].reload.l3.label = "Sea.";
	Locations[n].locators_radius.reload.reload2 = 3.0;		

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Cuba";
	Locations[n].reload.l2.emerge = "reload_1";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.reload2_back = 3;

	Locations[n].reload.l4.name = "reload3";
	Locations[n].reload.l4.go = "Santiago_shipyard";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Shipyard";
	Locations[n].reload.l4.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l4.goto_disable = 1; // Screwface: Disable Go-To location
	
	Locations[n].reload.l5.name = "reload4";
	Locations[n].reload.l5.go = "Santiago_town_exit2";
	Locations[n].reload.l5.emerge = "Reload2";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Jungle.";	

	Locations[n].island = "Cuba";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "Santiago_town_01";
	locations[n].id.label = "#stown_name#";
	locations[n].worldmap = "Santiago";
	Locations[n].image = "Town_Santiago_center.tga";

	//Town sack
	Locations[n].townsack = "Santiago";

	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "Santiago";
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	Locations[n].filespath.models = "locations\Town_Santiago\center";
	Locations[n].models.always.locators = "SC_center_l";	
	Locations[n].models.always.city = "SC_center";
	Locations[n].models.always.add = "light";
	Locations[n].models.always.tree = "tree";
	Locations[n].models.always.add2 = "xiao";
	Locations[n].models.always.add3 = "store_stuff";	//JRH-->
	Locations[n].models.always.add4 = "chimneys";
	Locations[n].models.always.add5 = "palms";
	Locations[n].models.always.add6 = "town_stuff";
	Locations[n].models.always.add7 = "diagonal";
	Locations[n].models.always.add8 = "wheelbarrow";
	Locations[n].models.always.add9 = "";			//<--JRH "globe" later, shows the way to the cartographer

		//Day
//	Locations[n].models.day.fonar = "FF02_fd";
	Locations[n].models.day.charactersPatch = "walk_patch";
//	Locations[n].models.day.jumppatch = "FF02_j";
//	Locations[n].models.day.rinok = "FF02_e01";
	//Night
//	Locations[n].models.night.fonar = "FF02_fn";
	Locations[n].models.night.charactersPatch = "walk_patch";
//	Locations[n].models.night.jumppatch = "FF02_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Santiago_port";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# Port.";

	if(sti(GetStorylineVar(FindCurrentStoryline(), "BART_PUZZLES")) > 0)
	{
		Locations[n].reload.l2.name = "reload2";
		Locations[n].reload.l2.go = "Santiago_outskirts";	// Bartolomeu storyline: use outskirts location with warehouses
		Locations[n].reload.l2.emerge = "reload2";
		Locations[n].reload.l2.autoreload = "0";
		Locations[n].reload.l2.label = "Outskirts.";
	}
	else
	{
		Locations[n].reload.l2.name = "reload2";
		Locations[n].reload.l2.go = "Santiago_town_exit1";	// Any other storyline: use normal outskirts location
		Locations[n].reload.l2.emerge = "reload2";
		Locations[n].reload.l2.autoreload = "0";
		Locations[n].reload.l2.label = "Outskirts.";
	}

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Santiago_townhall";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Residence.";
	Locations[n].reload.l4.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l4.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "Santiago_church";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Church.";
	Locations[n].reload.l5.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l5.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "Santiago_store";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "#stown_name# store.";
	Locations[n].reload.l6.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l6.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l7.name = "reload3";
	Locations[n].reload.l7.go = "Santiago_Tavern";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "#stown_name# tavern.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l7.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l8.name = "reload7";
	Locations[n].reload.l8.go = "Cartographer_House";
	Locations[n].reload.l8.emerge = "reload1";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "Cartographer's House";
	Locations[n].reload.l8.close_for_night = 1;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "WallMap";

	Locations[n].island = "Cuba";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\shipyard";

	Locations[n].id = "Santiago_shipyard";
	locations[n].id.label = "#stown_name# shipyard";
	Locations[n].image = "Inside_Shipyard1.tga";

	//Town sack
	Locations[n].townsack = "Santiago";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Santiago";
	//Models
	//Always
	Locations[n].models.always.locators = "sh01_l";
	Locations[n].models.always.shipyard = "sh01";
	Locations[n].models.always.window = "sh01_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "sh01_p";
	Locations[n].models.day.fd = "sh01_fd";

	//Night
	Locations[n].models.night.charactersPatch = "sh01_p";
	Locations[n].models.night.fn = "sh01_fn";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\oxsh1_";
	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Santiago_port";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# Port.";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Cuba";
	n = n + 1;

	// ----------------------------------------------------
	Locations[n].id = "Santiago_townhall";
	locations[n].id.label = "#stown_name# townhall";
	locations[n].filespath.models = "locations\inside\ResidenceA01";
	locations[n].image = "Inside_ResidencA1.tga";

	//Town sack
	Locations[n].townsack = "Santiago";

	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Santiago";
	//Models
	//Always
	locations[n].models.always.locators = "Residence01_locators";
	locations[n].models.always.l1 = "Residence01";
	locations[n].models.always.window = "residence01_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 50;
	//Day
	locations[n].models.day.charactersPatch = "Residence01_patch";

	//Night
	locations[n].models.night.charactersPatch = "Residence01_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\ffres1_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Santiago_Town_01";
	Locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	Locations[n].locators_radius.reload.locator1 = 0.8;
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Cuba";
	n = n + 1;

	//Santiago_church -------------------------------------------------
	Locations[n].id = "Santiago_church";
	locations[n].id.label = "#stown_name# Church.";
	Locations[n].image = "Inside_Church_inside.tga";
	Locations[n].filespath.models = "locations\inside\Church_inside";

	//Town sack
	Locations[n].townsack = "Santiago";

	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "Santiago";
	//Models
	//Always
	Locations[n].models.always.city = "Church";
	Locations[n].models.always.locators = "Church_l";
	Locations[n].models.always.window = "church_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
//	Locations[n].models.day.lamp = "FalaiseDeFleur05_day";
	Locations[n].models.day.charactersPatch = "Church_p";

	//Night
//	Locations[n].models.night.lamp = "FalaiseDeFleur05_night";
	Locations[n].models.night.charactersPatch = "Church_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Santiago_Town_01";
	Locations[n].reload.l1.emerge = "reload5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;


 	//-------------------------------------------------
	Locations[n].id = "Santiago_store";
	locations[n].id.label = "#stown_name# store";
	Locations[n].filespath.models = "locations\inside\MediumStore";
	Locations[n].image = "Inside_MediumStore.tga";

	//Town sack
	Locations[n].townsack = "Santiago";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Santiago";
	//Models
	//Always
	Locations[n].models.always.locators = "MS_l";
	Locations[n].models.always.store = "MS";
	Locations[n].models.always.window = "MS_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "MS_p";

	//Night
	Locations[n].models.night.charactersPatch = "MS_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redms_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Santiago_Town_01";
	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	Locations[n].locators_radius.camdetector.camera1 = 5;
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Cuba";
	n = n + 1;

// -------------------------------------------------
	Locations[n].id = "Santiago_Tavern";
	locations[n].id.label = "#stown_name# tavern.";
	Locations[n].filespath.models = "locations\Inside\Tavern_1";	
	Locations[n].image = "Inside_Tavern_1.tga";

	//Town sack
	Locations[n].townsack = "Santiago";

	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "Santiago";
	//Models
	//Always
	Locations[n].models.always.locators = "Tavern_1_l";
	Locations[n].models.always.l1 = "Tavern_1";
	//Day
	Locations[n].models.day.charactersPatch = "Tavern_1_p";
	//Night
	Locations[n].models.night.charactersPatch = "Tavern_1_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\DOUMH_";	
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Santiago_Town_01";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Santiago_tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Room in #stown_name# tavern.";
	Locations[n].reload.l2.disable = true;
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Cuba";
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Santiago_tavern_upstairs";
	locations[n].id.label = "Room in #stown_name# tavern.";
	Locations[n].image = "Inside_Doubleflour_House_Room.tga";

	//Town sack
	Locations[n].townsack = "Santiago";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Santiago";
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
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\grlf2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Santiago_tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# tavern."; // KK
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "Cuba";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Pirate_House";
	Locations[n].filespath.textures = "locations\Inside\Pirate_House";

	Locations[n].id = "Cartographer_House";
	locations[n].id.label = "Cartographer's House";
	Locations[n].image = "Inside_cartographer.tga";
	//Sound
	locations[n].type = "house";
	//Models
	//Always
	Locations[n].models.always.locators = "pirh_l_cartographer";
	Locations[n].models.always.house = "pirh";
	Locations[n].models.always.l2 = "plank";
	Locations[n].models.always.l3 = "map_rolls";
	
	Locations[n].models.always.window = "pirh_w4";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "pirh_p";

	//Night
	Locations[n].models.night.charactersPatch = "pirh_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
//	Locations[n].models.back = "back\qcpirh_";
	Locations[n].models.back = "back\mumh3_";		//more spanish, 3 is ok

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Santiago_town_01";
	Locations[n].reload.l1.emerge = "reload7";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Exit.";

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "WallMap";
	
	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;	

	// -------------------------------------------------
	Locations[n].id = "Santiago_town_exit1";
	locations[n].id.label = "Outskirts";
	Locations[n].filespath.models = "locations\Town_Redmond\REDexit1";
	Locations[n].image = "Town_Redmond_Exit1.tga";

	//Town sack
	Locations[n].townsack = "Santiago";

	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "Redexit1_l";
	Locations[n].models.always.exit = "Redexit1";
	Locations[n].models.always.grassPatch = "Redexit1_g";
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
	Locations[n].models.day.charactersPatch = "Redexit1_p";
	Locations[n].models.day.fonar = "redexit1_fd";
	//Night
	Locations[n].models.night.charactersPatch = "redexit1_p";
	Locations[n].models.night.fonar = "redexit1_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "Reload2";
	Locations[n].reload.l1.go = "Santiago_Town_01";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].reload.l2.name = "Reload1";
	Locations[n].reload.l2.go = "Cuba_Jungle_04";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle";
	Locations[n].locators_radius.reload.reload1 = 3.0;

	Locations[n].reload.l3.name = "Reload1_back";
	Locations[n].reload.l3.go = "Cuba_Jungle_04";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle";
	Locations[n].locators_radius.reload.Reload1_back = 2.0;

	Locations[n].island = "Cuba";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_IslaMuelle\exit";
	Locations[n].filespath.textures = "locations\SPAIN";

	Locations[n].id = "Santiago_town_exit2";
	locations[n].id.label = "Outskirts";
	Locations[n].image = "Town_IslaMuelle_Exit.tga";

	//Town sack
	Locations[n].townsack = "Santiago";

	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "muexit_l";
	Locations[n].models.always.l1 = "muexit";
	Locations[n].models.always.grassPatch = "muexit_g";
	Locations[n].models.always.l4 = "plan_1";
	Locations[n].models.always.l4.level = 9;
	Locations[n].models.always.l4.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan_3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	//Day
	Locations[n].models.day.charactersPatch = "muexit_p";
	Locations[n].models.day.fonar = "muexit_fd";
	//Night
	Locations[n].models.night.charactersPatch = "muexit_p";
	Locations[n].models.night.fonar = "muexit_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map

	Locations[n].reload.l3.name = "Reload1";
	Locations[n].reload.l3.go = "Cuba_shore_02";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Shore.";

	Locations[n].reload.l1.name = "Reload1_back";
	Locations[n].reload.l1.go = "Cuba_shore_02";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 3.5;
	Locations[n].reload.l1.label = "Shore.";

	Locations[n].reload.l2.name = "Reload2";
	Locations[n].reload.l2.go = "Santiago_port";
	Locations[n].reload.l2.emerge = "reload4";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name#. Port";

	Locations[n].island = "Cuba";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Passage";

	Locations[n].id = "Cuba_shore_02";
	locations[n].id.label = "Bahia de Moa";
	locations[n].worldmap = "MShore 1";
	Locations[n].image = "Outside_Passage1.tga";
	Locations[n].name = "Bahia de Moa";
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
	Locations[n].reload.l1.go = "Santiago_town_exit2";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Outskirts.";

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Santiago_town_exit2";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Outskirts.";

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Cuba";
	Locations[n].reload.l2.emerge = "reload_5";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 9.0;

	Locations[n].island = "Cuba";
	n = n + 1;
// <-- KK

// -------------------------------------------------

//SJG -->
	Locations[n].filespath.models = "locations\Outside\Passage";

	Locations[n].id = "Prison_Shore";
	locations[n].id.label = "Prison Shore";
//	locations[n].worldmap = "MShore 1";
	Locations[n].image = "Outside_Passage1.tga";
//	Locations[n].name = "Bahia de Moa";
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
	Locations[n].reload.l1.name = "reload4";
	Locations[n].reload.l1.go = "Cuba_Shore_04";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Playa de Sabana";

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Havana_fakefort4";
	Locations[n].reload.l2.emerge = "reloadc4";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Spanish Prison";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Cuba";
	n = n + 1;

//-------------------------------------------------------------------
	//ID
	Locations[n].id = "Havana_fakefort4";		//new ID
	locations[n].id.label = "Spanish Prison";
	//Info
	Locations[n].filespath.models = "locations\Fort_Inside\Fort_1";
	Locations[n].filespath.textures = "locations\SPAIN";
	Locations[n].image = "Fort_Inside_Fort_1.tga";

	//Town sack
	Locations[n].townsack = "Havana";		//change
	//Sound
	locations[n].type = "residence"; //SJG - was "military";

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
	Locations[n].reload.l1.name = "reloadc4";
	Locations[n].reload.l1.go = "Prison_Shore";
	Locations[n].reload.l1.emerge = "reload1_back";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reloadC5";
	Locations[n].reload.l2.go = "Dining_Room";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Cuba";	
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\inside\Residence5";

	Locations[n].id = "Dining_Room";
	locations[n].id.label = "Prison Dining Room";
	Locations[n].image = "Inside_Residence5.tga";

	//Town sack

	//Sound
	locations[n].type = "residence";

	//Models
	//Always
	Locations[n].models.always.locators = "Res05_l";
	Locations[n].models.always.l1 = "ResX5"; // ccc may07 Location Remodeling Campaign
	Locations[n].models.always.window = "ResX5_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "Res05_p";
	//Night
	Locations[n].models.night.charactersPatch = "Res05_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\cores5_";

	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Havana_fakefort4";
	Locations[n].reload.l1.emerge = "reloadc5";
	Locations[n].reload.l1.autoreload = "0";
	locations[n].id.label = "Spanish Prison";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Cuba";
	n = n + 1;
//<-- SJG

	// -------------------------------------------------
    Build_at("Havana_town_02", "gallows", "", 1.7591, 0.13162, -14.759, 0.18, "building");
    Build_at("Cuba_port", "chain", "", 100, 10, 75, 0.77, "building");	
	Build_at("Cuba_port", "bastion", "", -2.59, 7.00, 28.93, 1.98, "Building");
	Build_at("Cuba_port", "bastion", "", 17.96, 15.5, -103.14, -2.91, "Building");
	Build_at("Cuba_port", "College", "", 109.3, 5.00, -72.82, -0.13, "Building");
	Build_at("Cuba_port", "warehouse", "", 142.7, 4.00, -54.85, -0.38, "Building");
	Build_at("Cuba_port", "warehouse", "", 124.43, 5.00, -62.82, -0.38, "Building");
	Build_at("Cuba_port", "keep3", "", 162.57, 5.00, 21.73, 0.71, "Building");
	Build_at("Cuba_port", "church", "", -28.2, 8.00, -54.81, 1.24, "Building");
	Build_at("Cuba_port", "bastion", "", -19.17, 7.00, -5.05, -1.31, "Building");
	Build_at("Cuba_port", "bastion", "", 12.6, 7.00, 62.07, 2.04, "Building");
	Build_at("Cuba_port", "bastion2", "", 69.12, 9.00, -91.63, -2.91, "Building");
	Build_at("Cuba_port", "mansion", "", -17.3, 13.5, -84.06, 0.87, "Building");
	Build_at("Havana_Outskirts", "jungle2", "", -47.71, -2.79, -100.8, 1.78, "wild_jungles");
	Build_at("Havana_Outskirts", "jungle2", "", -18.68, -2.60, -57.62, -2.51, "wild_jungles");
	Build_at("Havana_Outskirts", "jungle2", "", -33.37, -1.99, -54.40, 1.30, "wild_jungles");
	Build_at("Havana_Outskirts", "farm", "", -21.83, -2.51, -66.11, -1.15, "building");
	Build_at("Santiago_town_exit2", "farm", "", -63.53, 0.00, 83.75, 1.36, "building");
	Build_at("Santiago_town_exit2", "jungle2", "", -35.62, 0.10, 50.04, 0.54, "wild_jungles");
	Build_at("Santiago_town_exit2", "jungle2", "", -51.96, 1.00, 70.59, 0.80, "wild_jungles");
	Build_at("Santiago_town_exit2", "jungle2", "", -10.54, 0.00, 56.32, -2.12, "wild_jungles");
	Build_at("Santiago_town_exit2", "jungle2", "", -34.17, 1.00, 84.25, -3.04, "wild_jungles");
	Build_at("Santiago_town_exit2", "farm", "", -35.28, 0.00, 56.79, 0.40, "wild_jungles");
	Build_at("Santiago_town_exit1", "jungle2", "", -18.24, -2.29, -59.37, -1.59, "wild_jungles");
	Build_at("Santiago_town_exit1", "jungle2", "", -78.27, -2.67, -115.39, 1.78, "wild_jungles");
	Build_at("Cuba_shore_05", "jungle2", "", 16.13, 2.06, 40.28, -2.00, "wild_jungles");
	Build_at("Cuba_shore_05", "jungle2", "", 8.24, 1.98, 35.86, -0.42, "wild_jungles");
	Build_at("Cuba_shore_05", "jungle2", "", -13.90, 1.71, 46.33, 0.53, "wild_jungles");
	Build_at("Cuba_shore_05", "jungle2", "", -23.19, 1.68, 55.72, 0.93, "wild_jungles");
	Build_at("Santiago_outskirts", "warehouse", "", -15.76, 0.00, -15.27, 1.33, "building");
	Build_at("Santiago_outskirts", "warehouse", "", -16.60, 0.00, 2.74, 1.75, "building");
	Build_at("Santiago_outskirts", "windmill", "", 6.38, 0.14, 16.37, 0.00, "building");
	Build_at("Cuba_Jungle_04", "jungle2", "", 12.14, 0.00, -6.78, -1.45, "wild_jungles");
	Build_at("Cuba_Jungle_04", "jungle2", "", 10.83, 0.00, -19.56, -2.24, "wild_jungles");
	Build_at("Cuba_Jungle_04", "jungle2", "", 21.27, 0.00, -13.57, -1.37, "wild_jungles");
	Build_at("Cuba_Jungle_04", "jungle2", "", -8.17, 0.35, 12.67, 0.91, "wild_jungles");
	Build_at("Cuba_Jungle_04", "jungle2", "", 6.62, 0.00, -25.63, -1.76, "wild_jungles");
	Build_at("Cuba_Jungle_04", "jungle2", "", 10.97, 0.00, 7.80, -1.98, "wild_jungles");
	Build_at("Santiago_outskirts", "jungle2", "", -11.90, 0.18, -26.54, 0.54, "wild_jungles");
	Build_at("Cuba_Jungle_01", "jungle2", "", -1.51, -1.46, -16.36, 0.00, "wild_jungles");
	Build_at("Cuba_Jungle_01", "jungle2", "", 3.54, -1.66, -5.89, -2.06, "wild_jungles");
	Build_at("Cuba_shore_03", "jungle2", "", 8.29, 1.42, -7.92, -0.33, "wild_jungles");
	Build_at("Cuba_shore_03", "jungle2", "", -13.04, 1.10, 2.35, 1.03, "wild_jungles");
	Build_at("Cuba_Jungle_03", "jungle2", "", -3.76, 0.75, -3.53, 2.65, "wild_jungles");
	Build_at("Cuba_Jungle_03", "jungle2", "", 4.86, 0.91, -19.86, 0.15, "wild_jungles");

	Build_at("Santiago_warehouse_01", "bale", "", 4.064, 0, -5.5451, -1.47, "Building");
	Build_at("Santiago_warehouse_01", "bale", "", -1.6984, 0, -9.8593, -1.47, "Building");

	Build_at("Santiago_warehouse_02", "bale", "", 1.9, 0, -7.1347, -1.47, "Building");
	Build_at("Santiago_warehouse_02", "bale", "", 4.7356, 0, 2.08, -1.47, "Building");

	Build_at("Santiago_port", "gallows", "", -70.9, 14.5, -76.8, 0.43, "building");		//JRH
	Build_at("Santiago_town_01", "keep", "", 35.0, 6.0, -79.0, 0.0, "building");		//JRH
	Build_at("Santiago_town_01", "keep", "", 57.0, 6.0, -1.0, 0.0, "building");		//JRH
}
