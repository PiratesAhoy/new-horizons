void LocationInitCayman(ref n)
{
        //------------------------------------

//======================== JUNGLE INTERSECTION (EDEN ROCK / SPANISH CAMP)

	Locations[n].filespath.models = "locations\Outside\Jungle_6";

	Locations[n].id = "Devlin_Cayman_01";
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
	Locations[n].reload.l1.go = "Devlin_Cayman_02";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 2.5;
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Cayman_Shore_01";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload2 = 2.5;
	Locations[n].reload.l2.label = "Eden Rock.";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Devlin_Fort_Camp";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.reload3 = 2.5;
	Locations[n].reload.l3.label = "Pirate Fort.";

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Cayman_Shore_01";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].locators_radius.reload.reload2_back = 2.5;
	Locations[n].reload.l4.label = "Eden Rock.";

	Locations[n].reload.l5.name = "reload3_back";
	Locations[n].reload.l5.go = "Devlin_Fort_Camp";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].locators_radius.reload.reload3_back = 3;
	Locations[n].reload.l5.label = "Pirate Fort.";

	Locations[n].reload.l6.name = "reload1_back";
	Locations[n].reload.l6.go = "Devlin_Cayman_02";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 2.5;
	Locations[n].reload.l6.label = "Jungle.";


	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;

//======================== SPANISH CAMP

	Locations[n].filespath.models = "locations\Pirate Fort";

	Locations[n].id = "Devlin_Fort_Camp";
	locations[n].id.label = "Pirate Fort";
	Locations[n].image = "Pirate_Fort.tga";

	//Town sack
	//Locations[n].townsack = "Pirate Fort"; // NK 04-08-29

	//Sound
	locations[n].type = "jungle";
	Locations[n].fastreload = "Pirate_fort";

	//Models
	//Always
	Locations[n].models.always.locators = "PiF_l_BTP";
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
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Devlin_Cayman_01";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].reload.l1.autoreload = 1;
	Locations[n].locators_radius.reload.reload1 = 1;

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Devlin_Cayman_01";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].reload.l2.autoreload = 1;
	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;

//======================== JUNGLE INTERSECTION (O'BYRNE HOUSE)

	Locations[n].filespath.models = "locations\Outside\Jungle3";

	Locations[n].id = "Devlin_Cayman_02";
	locations[n].id.label = "Jungle";
	Locations[n].image = "Outside_Jungle3.tga";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

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
    Locations[n].reload.l1.name = "reload3";
	Locations[n].reload.l1.go = "Byrne_outside";            // LEADS TO O'BYRNE HOUSE
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "House.";
	Locations[n].locators_radius.reload.reload2 = 1;

	Locations[n].reload.l2.name = "reload3_back";
	Locations[n].reload.l2.go = "Byrne_outside";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "House.";
	Locations[n].locators_radius.reload.reload2_back = 3;

    Locations[n].reload.l5.name = "reload1";                    // LEADS TO NEXT INTERSECTION (CORSAIR'S BEACH)
	Locations[n].reload.l5.go = "Devlin_Cayman_03";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].locators_radius.reload.reload3 = 2.5;
	Locations[n].reload.l5.label = "Jungle.";

	Locations[n].reload.l6.name = "reload1_back";
	Locations[n].reload.l6.go = "Devlin_Cayman_03";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].locators_radius.reload.reload3_back = 3;
	Locations[n].reload.l6.label = "Jungle.";

    Locations[n].reload.l7.name = "reload2";                    // LEADS BACK TO FIRST INTERSECTION
	Locations[n].reload.l7.go = "Devlin_Cayman_01";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "1";
	Locations[n].reload.l7.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 1;

	Locations[n].reload.l8.name = "reload2_back";
	Locations[n].reload.l8.go = "Devlin_Cayman_01";
	Locations[n].reload.l8.emerge = "reload1";
	Locations[n].reload.l8.autoreload = "1";
	Locations[n].reload.l8.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3;

	Locations[n].island = "Cayman";
	n = n + 1;

//======================== ENTRANCE TO O'BYRNE HOUSE

	Locations[n].filespath.models = "locations\Outside\Rheims House";

	Locations[n].id = "Byrne_outside";
	locations[n].id.label = "House in Jungle";
	Locations[n].image = "Outside_Rheims_House.tga";
	//Sound
	locations[n].type = "jungle";

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
	Locations[n].reload.l1.go = "Devlin_Cayman_02";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1 = 3;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Devlin_Cayman_02";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 3;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Byrne_inside";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "House";

/*
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "";
	Locations[n].reload.l3.emerge = "";*/

	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;

//======================== INSIDE O'BYRNE HOUSE

	Locations[n].filespath.models = "locations\Inside\MediumHouse2";

	Locations[n].id = "Byrne_inside";
	locations[n].id.label = "House.";
	Locations[n].image = "Inside_MediumHouse2.tga";

	//Town sack
	//Locations[n].townsack = "Smugglers Lair"; // NK 04-08-29

	//Sound
	locations[n].type = "house";
	//locations[n].fastreload = "SL"; // Fast reload is SL, "conceicao" is for the conceicao town

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
	Locations[n].reload.l1.go = "Byrne_outside";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Jungle.";
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;

//======================== JUNGLE INTERSECTION (CORSAIR'S BEACH)

	Locations[n].id = "Devlin_Cayman_03";
	locations[n].id.label = "Jungle";
	Locations[n].filespath.models = "locations\Outside\jungle5"; 
	Locations[n].image = "Outside_Jungle5.tga";
 	//Sound
	locations[n].type = "jungle";

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

        //Day
        Locations[n].models.day.charactersPatch = "Jungle5_patch";
        //Night
        Locations[n].models.night.charactersPatch = "Jungle5_patch";
        //Environment
        Locations[n].environment.weather = "true";
        Locations[n].environment.sea = "false";
        //Reload map
        Locations[n].reload.l1.name = "reload1";            // LEADS TO BEACH
        Locations[n].reload.l1.go = "Devlin_Cayman_beach";
        Locations[n].reload.l1.emerge = "reload2";
        Locations[n].reload.l1.autoreload = "1";
        Locations[n].reload.l1.label = "Shore.";
        Locations[n].locators_radius.reload.Reload1 = 3.0;

        Locations[n].reload.l2.name = "reload2";            // LEADS BACK TO SECOND INTERSECTION
        Locations[n].reload.l2.go = "Devlin_Cayman_02";
        Locations[n].reload.l2.emerge = "reload1";
        Locations[n].reload.l2.autoreload = "1";
        Locations[n].reload.l2.label = "Jungle.";
        Locations[n].locators_radius.reload.Reload2 = 3.0;

        Locations[n].reload.l4.name = "reload1_back";
        Locations[n].reload.l4.go = "Devlin_Cayman_beach";  // LEADS TO BEACH
        Locations[n].reload.l4.emerge = "reload2";
        Locations[n].reload.l4.autoreload = "1";
        Locations[n].reload.l4.label = "Shore.";
        Locations[n].locators_radius.reload.Reload1_back = 2.0;

        Locations[n].reload.l5.name = "reload2_back";       // LEADS BACK TO SECOND INTERSECTION
        Locations[n].reload.l5.go = "Devlin_Cayman_02";
        Locations[n].reload.l5.emerge = "reload1";
        Locations[n].reload.l5.autoreload = "1";
        Locations[n].reload.l5.label = "Jungle.";
        Locations[n].locators_radius.reload.Reload2_back = 2.0;

        Locations[n].reload.l6.name = "reload3";
        Locations[n].reload.l6.go = "Cayman_Jungle_03";    // LEADS TO OUTSKIRTS
        Locations[n].reload.l6.emerge = "reload1";
        Locations[n].reload.l6.autoreload = "1";
        Locations[n].reload.l6.label = "Jungle.";
        Locations[n].locators_radius.reload.Reload1_back = 2.0;

        Locations[n].reload.l7.name = "reload3_back";       // LEADS TO OUTSKIRTS
        Locations[n].reload.l7.go = "Cayman_Jungle_03";
        Locations[n].reload.l7.emerge = "reload1";
        Locations[n].reload.l7.autoreload = "1";
        Locations[n].reload.l7.label = "Jungle.";
        Locations[n].locators_radius.reload.Reload2_back = 2.0;

	Locations[n].island = "Cayman"; 
	n = n + 1;

//======================== CORSAIR'S BEACH

	Locations[n].filespath.models = "locations\Outside\Shore_8";

	Locations[n].id = "Devlin_Cayman_beach";
	locations[n].id.label = "Sunny Haven."; // KK
	//locations[n].worldmap = "CShore 1";
	Locations[n].image = "Outside_Shore_8.tga";
	Locations[n].name = "Punta el Ron";
	//Sound
	locations[n].type = "seashore";

	//Models
	//Always
	Locations[n].models.always.jungle = "Shore08";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.locators = "Shore08_l";
	Locations[n].models.always.grassPatch = "Shore08_g";
	Locations[n].models.always.seabed = "Shore08_sb";
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
	Locations[n].models.day.charactersPatch = "Shore08_p";
	//Night
	Locations[n].models.night.charactersPatch = "Shore08_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Devlin_Cayman_03";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 3;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Devlin_Cayman_03";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3;

	//Locations[n].reload.l2.name = "boat";
	//Locations[n].reload.l2.go = "Conceicao";
	//Locations[n].reload.l2.emerge = "reload_2";
	//Locations[n].reload.l2.autoreload = "0";
	//Locations[n].locators_radius.reload.boat = 9.0;

	Locations[n].island = "Cayman"; // NK 04-08-29
	n = n + 1;

}
