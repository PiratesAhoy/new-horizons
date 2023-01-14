void LocationInitBattleRocks(ref n)
{
	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Shore_4";

	Locations[n].id = "Devil_Creek";
	locations[n].id.label = "Devil Creek"; 
	locations[n].worldmap = "Battle Rocks";
	Locations[n].image = "Outside_Shore_4";
	Locations[n].name = "Devil Creek";
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
	Locations[n].reload.l1.name = "locator3";
	Locations[n].reload.l1.go = "Battle_Rocks_Jungle_04";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.locator3 = 3;
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l3.name = "locator3_back";
	Locations[n].reload.l3.go = "Battle_Rocks_Jungle_04";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.locator3_back = 1;
	Locations[n].reload.l3.label = "Jungle.";

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Battle_Rocks";
	Locations[n].reload.l2.emerge = "reload_1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.boat = 9.0;
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";

	Locations[n].island = "Battle_Rocks"; 
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Cave Entrance";

	Locations[n].id = "Battle_Rocks_Jungle_01";
	locations[n].id.label = "Mine.";
	Locations[n].image = "Outside_Cave_Entrance";
	//Sound
	locations[n].type = "jungle";
	locations[n].ambush = true;

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
	Locations[n].reload.l3.go = "Battle_Rocks_mine";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Mine.";
	Locations[n].locators_radius.reload.Reload1 = 1;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Battle_Rocks_mine";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Mine.";
	Locations[n].locators_radius.reload.Reload1_back = 1.3;

	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Spanish_Camp";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2 = 2.0;

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Spanish_Camp";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 2.0;


	Locations[n].island = "Battle_Rocks";
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Jungle2";

	Locations[n].id = "Battle_Rocks_Jungle_02";
	locations[n].id.label = "Jungle";
	Locations[n].image = "Outside_Jungle2";
	//Sound
	locations[n].type = "jungle";
	locations[n].ambush = true;

    //Models
    //Always
    Locations[n].models.always.locators = "Jungle2_locators";
    Locations[n].models.always.jungle = "Jungle2";
    Locations[n].models.always.grassPatch = "JUNGLE2_grass";
    Locations[n].models.always.l1 = "plan1";
    Locations[n].models.always.l1.level = 9;
    Locations[n].models.always.l1.tech = "LocationModelBlend";
    Locations[n].models.always.l2 = "plan2";
    Locations[n].models.always.l2.level = 8;
    Locations[n].models.always.l2.tech = "LocationModelBlend";
    Locations[n].models.always.l3 = "plan3";
    Locations[n].models.always.l3.level = 7;
    Locations[n].models.always.l3.tech = "LocationModelBlend";

    //Day
    Locations[n].models.day.charactersPatch = "Jungle2_patch";
    //Night
    Locations[n].models.night.charactersPatch = "Jungle2_patch";
    //Environment
    Locations[n].environment.weather = "true";
    Locations[n].environment.sea = "false";

    //Day
    Locations[n].models.day.charactersPatch = "Jungle2_patch";
    //Night
    Locations[n].models.night.charactersPatch = "Jungle2_patch";
    //Environment
    Locations[n].environment.weather = "true";
    Locations[n].environment.sea = "false";
    
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Spanish_Camp";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Spanish Camp.";
	Locations[n].locators_radius.reload.reload1 = 4;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Spanish_Camp";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Spanish Camp.";
	Locations[n].locators_radius.reload.reload1_back = 4;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Battle_Rocks_Jungle_04";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 4;

	Locations[n].reload.l5.name = "reload2_back";
	Locations[n].reload.l5.go = "Battle_Rocks_Jungle_04";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3;

	Locations[n].island = "Battle_Rocks"; 
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Battle_Rocks_Jungle_04";
	locations[n].id.label = "Jungle";
	Locations[n].filespath.models = "locations\Outside\jungle_8"; 
	Locations[n].image = "Outside_Jungle_8";
 	//Sound
	locations[n].type = "jungle";
	locations[n].ambush = true;
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
	//Night
	Locations[n].models.night.charactersPatch = "jungle08_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Battle_Rocks_Jungle_02";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1 = 3.0;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Battle_Rocks_Jungle_02";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Devil_Creek";
	Locations[n].reload.l2.emerge = "locator3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Devil Creek.";
	Locations[n].locators_radius.reload.reload2 = 3.0;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Devil_Creek";
	Locations[n].reload.l3.emerge = "locator3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Devil Creek.";
	Locations[n].locators_radius.reload.reload2_back = 2.0;


	Locations[n].island = "Battle_Rocks"; 
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Jungle3";

	Locations[n].id = "Spanish_Camp";
	locations[n].id.label = "Spanish Camp";
	Locations[n].image = "Outside_Jungle3_Camp";

	//Town sack
	Locations[n].townsack = "Spanish Camp"; 

	//Sound
	locations[n].type = "jungle";

        //Models
        //Always
        Locations[n].models.always.locators = "Jungle3_locators";
        Locations[n].models.always.jungle = "Jungle3";
        Locations[n].models.always.grassPatch = "JUNGLE3_grass";
        Locations[n].models.always.l1 = "plan1";
        Locations[n].models.always.l1.level = 9;
        Locations[n].models.always.l1.tech = "LocationModelBlend";
        Locations[n].models.always.l2 = "plan2";
        Locations[n].models.always.l2.level = 8;
        Locations[n].models.always.l2.tech = "LocationModelBlend";
        Locations[n].models.always.l3 = "plan3";
        Locations[n].models.always.l3.level = 7;
        Locations[n].models.always.l3.tech = "LocationModelBlend";

        //Day
        Locations[n].models.day.charactersPatch = "Jungle3_patch";
        //Night
        Locations[n].models.night.charactersPatch = "Jungle3_patch";
        //Environment
        Locations[n].environment.weather = "true";
        Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Battle_Rocks_Jungle_05";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle."; 
	Locations[n].locators_radius.reload.Reload1 = 1.0;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Battle_Rocks_Jungle_05";
	Locations[n].reload.l4.emerge = "reload3";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle."; 
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Battle_Rocks_Jungle_02";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2 = 3.0;

	Locations[n].reload.l5.name = "reload2_back";
	Locations[n].reload.l5.go = "Battle_Rocks_Jungle_02";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3.0;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Battle_Rocks_Jungle_01";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload3 = 3.0;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Battle_Rocks_Jungle_01";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 3.0;

	Locations[n].island = "Battle_Rocks"; 
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_6";

	Locations[n].id = "Battle_Rocks_Jungle_05";
	locations[n].id.label = "Jungle";		
	Locations[n].image = "Outside_Jungle_6";
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
	Locations[n].reload.l1.go = "Battle_Rocks_Jungle_03";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 2.5;
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "spanish_camp";
	Locations[n].reload.l3.emerge = "Reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.reload3 = 2.5;
	Locations[n].reload.l3.label = "spanish camp.";

	Locations[n].reload.l5.name = "reload3_back";
	Locations[n].reload.l5.go = "spanish_camp";
	Locations[n].reload.l5.emerge = "Reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].locators_radius.reload.reload3_back = 3;
	Locations[n].reload.l5.label = "spanish camp.";

	Locations[n].reload.l6.name = "reload1_back";
	Locations[n].reload.l6.go = "Battle_Rocks_Jungle_03";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 2.5;
	Locations[n].reload.l6.label = "Jungle.";

	Locations[n].island = "Battle_Rocks"; 
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Battle_Rocks_Jungle_03";
	locations[n].id.label = "Jungle";
	Locations[n].filespath.models = "locations\Outside\jungle5"; 
	Locations[n].image = "Outside_Jungle5";
 	//Sound
	locations[n].type = "jungle";
	locations[n].ambush = true;

    //Models
    //Always
    Locations[n].models.always.locators = "Jungle5_locators";
    Locations[n].models.always.jungle = "Jungle5";
    Locations[n].models.always.grassPatch = "JUNGLE5_grass";
    Locations[n].models.always.l1 = "plan1";
    Locations[n].models.always.l1.level = 9;
    Locations[n].models.always.l1.tech = "LocationModelBlend";
    Locations[n].models.always.l2 = "plan2";
    Locations[n].models.always.l2.level = 8;
    Locations[n].models.always.l2.tech = "LocationModelBlend";
    Locations[n].models.always.l3 = "plan3";
    Locations[n].models.always.l3.level = 7;
    Locations[n].models.always.l3.tech = "LocationModelBlend";
	Locations[n].models.always.donkey1 = "donkey";
	Locations[n].models.always.donkey1.locator.group = "goto";
	Locations[n].models.always.donkey1.locator.name = "goto9";
	Locations[n].models.always.donkey2 = "donkey";
	Locations[n].models.always.donkey2.locator.group = "goto";
	Locations[n].models.always.donkey2.locator.name = "goto10";
	Locations[n].models.always.donkey3 = "donkey";
	Locations[n].models.always.donkey3.locator.group = "goto";
	Locations[n].models.always.donkey3.locator.name = "goto11";
    Locations[n].models.always.donkey4 = "donkey";
	Locations[n].models.always.donkey4.locator.group = "goto";
	Locations[n].models.always.donkey4.locator.name = "goto12";	

    //Day
    Locations[n].models.day.charactersPatch = "Jungle5_patch";
    //Night
    Locations[n].models.night.charactersPatch = "Jungle5_patch";
    //Environment
    Locations[n].environment.weather = "true";
    Locations[n].environment.sea = "false";
    //Reload map
    Locations[n].reload.l1.name = "reload1";
    Locations[n].reload.l1.go = "Battle_Rocks_port";
    Locations[n].reload.l1.emerge = "reload2";
    Locations[n].reload.l1.autoreload = "1";
    Locations[n].reload.l1.label = "Shore.";
    Locations[n].locators_radius.reload.Reload1 = 3.0;

    Locations[n].reload.l2.name = "reload2";
    Locations[n].reload.l2.go = "Battle_Rocks_Jungle_05";
    Locations[n].reload.l2.emerge = "reload1";
    Locations[n].reload.l2.autoreload = "1";
    Locations[n].reload.l2.label = "Jungle.";
    Locations[n].locators_radius.reload.Reload2 = 3.0;

    Locations[n].reload.l4.name = "reload1_back";
    Locations[n].reload.l4.go = "Battle_Rocks_port";
    Locations[n].reload.l4.emerge = "reload2";
    Locations[n].reload.l4.autoreload = "1";
    Locations[n].reload.l4.label = "Shore.";
    Locations[n].locators_radius.reload.Reload1_back = 2.0;

    Locations[n].reload.l5.name = "reload2_back";
    Locations[n].reload.l5.go = "Battle_Rocks_Jungle_05";
    Locations[n].reload.l5.emerge = "reload1";
    Locations[n].reload.l5.autoreload = "1";
    Locations[n].reload.l5.label = "Jungle.";
    Locations[n].locators_radius.reload.Reload2_back = 2.0;

	Locations[n].island = "Battle_Rocks"; 
	n = n + 1;
	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Shore_2";

	Locations[n].id = "Battle_Rocks_port";
	locations[n].id.label = "Battle Rocks port"; 
	Locations[n].image = "Outside_Shore_2";
	Locations[n].name = "Battle Rocks port";
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
	Locations[n].reload.l1.go = "Battle_Rocks_Jungle_03";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 3.0;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Battle_Rocks_Jungle_03";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3.0;


	Locations[n].island = "Battle_Rocks"; 
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Mine";

	Locations[n].id = "Battle_Rocks_mine";
	locations[n].id.label = "Battle Rocks mine";
	Locations[n].image = "Inside_Mine";

	//Sound
	locations[n].type = "cave";
	//Models
	//Always
	Locations[n].models.always.locators = "mine_l";
	Locations[n].models.always.l1 = "mine";
	//Day
	Locations[n].models.day.charactersPatch = "mine_p";
	//Night
	Locations[n].models.night.charactersPatch = "mine_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Battle_Rocks_Jungle_01";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Battle_Rocks_Jungle_01";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";

	Locations[n].island = "Battle_Rocks";
	n = n + 1;

	// -------------------------------------------------

	Build_at("Spanish_Camp", "bastion2", "", 2.71, 0.25, 3.22, 1.90, "building");
	Build_at("Spanish_Camp", "workshop", "", -5.46, 1.92, -10.31, -0.75, "building");
	Build_at("Spanish_Camp", "farm", "", 10.46, 0.00, -2.21, -1.61, "building");
	Build_at("Spanish_Camp", "fence2", "", -29.84, 0.00, 7.32, -1.46, "building");
	Build_at("Spanish_Camp", "fence2", "", -30.76, 0.18, 13.40, -1.86, "building");
	Build_at("Spanish_Camp", "fence2", "", -33.90, 0.00, 18.70, -2.49, "building");
	Build_at("Spanish_Camp", "house", "", 2.34, 0.00, -21.89, 0.00, "building");
	Build_at("Battle_Rocks_Jungle_04", "jungle2", "", -19.56, -2.59, -145.53, -1.11, "wild_jungles");
	Build_at("Battle_Rocks_Jungle_04", "jungle2", "", -15.97, -2.55, -119.08, 0.17, "wild_jungles");
	Build_at("Battle_Rocks_Jungle_04", "jungle2", "", -48.46, -2.39, -102.47, 1.57, "wild_jungles");
	Build_at("Battle_Rocks_Jungle_04", "jungle2", "", -29.39, -2.49, -91.46, -3.13, "wild_jungles");
	Build_at("Battle_Rocks_Jungle_04", "jungle2", "", -27.64, -3.40, -69.12, 1.63, "wild_jungles");
	Build_at("Battle_Rocks_Jungle_01", "forest", "mine", 5.31, -0.68, -0.77, 1.22, "wild_jungles");
	Build_at("Battle_Rocks_Jungle_04", "jungle2", "", -19.56, -2.59, -145.53, -1.11, "wild_jungles");
	Build_at("Devil_Creek", "jungle2", "", 7.28, 3.05, -18.91, -3.02, "wild_jungles");
	Build_at("Devil_Creek", "jungle2", "", -7.44, 4.54, -23.42, -0.45, "wild_jungles");
	Build_at("Battle_Rocks_Jungle_02", "jungle2", "", 33.96, -0.71, -34.44, 1.92, "wild_jungles");
	Build_at("Battle_Rocks_Jungle_02", "jungle2", "", 15.70, -1.60, -29.10, 2.26, "wild_jungles");
	Build_at("Battle_Rocks_Jungle_03", "jungle2", "", -15.66, 0.52, -10.73, -1.49, "wild_jungles");
	Build_at("Battle_Rocks_Jungle_03", "jungle2", "", -25.98, 0.00, -9.78, 0.34, "wild_jungles");
	Build_at("Battle_Rocks_Jungle_03", "jungle2", "", -27.77, 0.43, -2.97, -2.55, "wild_jungles");
	Build_at("Battle_Rocks_port", "keep2", "", 19.94, 4.61, -1.70, 2.80, "Building");
//	Build_at("Battle_Rocks_port", "jungle2", "", -26.78, 1.29, 11.72, 0.40, "wild_jungles"); // PB: Obstructs view of ship
	Build_at("Battle_Rocks_Jungle_03", "Box", "", 5.56, 0.00, -6.42, 1.61, "Building");
	Build_at("Battle_Rocks_Jungle_03", "Box", "", 9.21, 0.28, -6.66, 1.59, "Building");
	Build_at("Battle_Rocks_Jungle_03", "Box", "", 9.33, 0.16, -9.01, -3.03, "Building");
	Build_at("Battle_Rocks_Jungle_03", "Box", "", 6.02, 0.00, -8.14, -1.55, "Building");
	Build_at("Battle_Rocks_Jungle_05", "jungle2", "", 13.94, 0.00, -1.10, -1.70, "wild_jungles");
	Build_at("Battle_Rocks_Jungle_05", "jungle2", "", -16.14, -0.19, -0.80, 1.58, "wild_jungles");
	Build_at("Battle_Rocks_Jungle_05", "jungle2", "", 8.81, 0.00, -12.29, -1.09, "wild_jungles");
	Build_at("Battle_Rocks_Jungle_05", "jungle2", "", 5.87, 0.00, 18.78, -1.88, "wild_jungles");
}


