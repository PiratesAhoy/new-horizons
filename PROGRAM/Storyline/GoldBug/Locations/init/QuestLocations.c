void LocationInitQuestLocations(ref n)
{
	Locations[n].filespath.models = "locations\Outside\Shore_ship";
	Locations[n].id = "Sullivan_shore3";
	locations[n].id.label = "Sullivan shore";
	Locations[n].image = "Outside_Shore_Ship.tga";
	//Sound
	locations[n].type = "silent_seashore";
	//locations[n].type = "indian_seashore";
	//locations[n].type = "Sullivan_seashore";

	//Models
	//Always
	Locations[n].models.always.jungle = "ShoreShip";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.locators = "ShoreShip_l_GB_birds";		//ShoreShip_l_GB_wood
	Locations[n].models.always.grassPatch = "ShoreShip_g";
	Locations[n].models.always.seabed = "ShoreShip_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	//Locations[n].models.always.l3 = "plan_3";
	//Locations[n].models.always.l3.level = 7;
	//Locations[n].models.always.l3.tech = "LocationModelBlend";

	Locations[n].models.always.mill_movie = "MillFan";
	Locations[n].models.always.mill_movie.locator.group = "Windmill";
	Locations[n].models.always.mill_movie.locator.name = "fan";
	Locations[n].models.always.mill_movie.rotate.x = 0.0;
	Locations[n].models.always.mill_movie.rotate.y = 0.0;
	Locations[n].models.always.mill_movie.rotate.z = 1.0;
	Locations[n].models.always.mill_movie.tech = "dLightModel";

	//Day
	Locations[n].models.day.charactersPatch = "ShoreShip_p";
	//Night
	Locations[n].models.night.charactersPatch = "ShoreShip_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.4;

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "fake_Fort_Moultrie_exit";
	Locations[n].reload.l1.emerge = "box1";
	Locations[n].reload.l1.autoreload = "1";			
	Locations[n].reload.l1.label = "The cavern";
	Locations[n].locators_radius.reload.reload1 = 1;

	Locations[n].reload.l10.name = "reload1_back";
	Locations[n].reload.l10.go = "fake_Fort_Moultrie_exit";
	Locations[n].reload.l10.emerge = "box1";
	Locations[n].reload.l10.autoreload = "1";
	Locations[n].reload.l10.label = "The cavern";
	Locations[n].locators_radius.reload.reload1_back = 3;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Kidds_cabin";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";			
	Locations[n].reload.l2.label = "The cavern";
	Locations[n].locators_radius.reload.reload2 = 0.5;
	if(ENABLE_CHEATMODE)
	{
		Locations[n].reload.l2.disable = 0;
	}
	else Locations[n].reload.l2.disable = 1;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "windmill_mast";

	Locations[n].locators_radius.box.box2 = 0.0001;

	Locations[n].items.randitem2 = "1_log";
	Locations[n].items.randitem3 = "1_log";
	Locations[n].items.randitem4 = "marsh_hen";
	Locations[n].items.randitem5 = "marsh_hen";
	Locations[n].items.randitem6 = "marsh_hen";
	Locations[n].items.randitem7 = "marsh_hen";

	LAi_LocationMonstersGen(&locations[n], false);
	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;
//--------------------------------------------------------------------------
	locations[n].id = "Kidds_cabin";
	locations[n].id.label = "Adventure Galley";
	locations[n].filespath.models = "locations\decks\Kidds_cabin";
	locations[n].image = "GB_Adventure_Galley.tga";
	
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "galleon_open";
	
	//Models
	//Always	
	Locations[n].models.always.inside = "PlutoStoreSmall";	
	Locations[n].models.always.windows = "PlutoStoreSmall_windows";
	Locations[n].models.always.windows.tech = "LocationWindows";
	Locations[n].models.always.windows.level = 65539;	
	Locations[n].models.always.locators = "PlutoStoreSmall_locators_GB";	
			
	//Day
	locations[n].models.day.charactersPatch = "PlutoStoreSmall_patch_day";
	locations[n].models.day.fonarday = "PlutoStoreSmall_fd";	
	//Night
	locations[n].models.night.charactersPatch = "PlutoStoreSmall_patch_day";	
	Locations[n].models.night.fonarnight = "PlutoStoreSmall_fn";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	
	Locations[n].locators_radius.goto.kidd = 3.0;

	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Sullivan_shore3";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Sullivan shore";
	Locations[n].locators_radius.reload.reload1 = 0.7;

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "Sullivan_shore3";
	locations[n].reload.l3.emerge = "reload2";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "";
	Locations[n].reload.l3.disable = 1;
	Locations[n].locators_radius.reload.reload3 = 0.5;

	locations[n].reload.l4.name = "reload4";
	locations[n].reload.l4.go = "Sullivan_shore3";
	locations[n].reload.l4.emerge = "reload2";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "";
	Locations[n].reload.l4.disable = 1;
	Locations[n].locators_radius.reload.reload4 = 0.5;

	Locations[n].island = "Oxbay";
	n = n + 1;

//--------------------------------------------------------------------------	
	Locations[n].filespath.models = "locations\Outside\Shore_2";
	Locations[n].id = "Sullivan_shore2";
	locations[n].id.label = "Sullivan shore";
	//locations[n].worldmap = "OShore 2";
	Locations[n].image = "Outside_Shore_2.tga";
	//Sound
	locations[n].type = "silent_seashore";
	//locations[n].type = "indian_seashore";
	//locations[n].type = "Sullivan_seashore";
	//Models
	//Always
	Locations[n].models.always.jungle = "Shore02";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.locators = "Shore02_l_GB_shells";		//Shore02_l_GB_wood later
	Locations[n].models.always.grassPatch = "Shore02_g";
	Locations[n].models.always.seabed = "Shore02_sb";
	Locations[n].models.always.seabed.foam = "1";

	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
//	Locations[n].models.always.l3 = "plan_3";
//	Locations[n].models.always.l3.level = 7;
//	Locations[n].models.always.l3.tech = "LocationModelBlend";

	Locations[n].models.always.mill_movie1 = "MillFan1";
	Locations[n].models.always.mill_movie1.locator.group = "Windmill";
	Locations[n].models.always.mill_movie1.locator.name = "fan1";
	Locations[n].models.always.mill_movie1.rotate.x = 0.0;
	Locations[n].models.always.mill_movie1.rotate.y = 0.0;
	Locations[n].models.always.mill_movie1.rotate.z = 1.0;
	Locations[n].models.always.mill_movie1.tech = "dLightModel";

	Locations[n].models.always.mill_movie2 = "MillFan2";
	Locations[n].models.always.mill_movie2.locator.group = "Windmill";
	Locations[n].models.always.mill_movie2.locator.name = "fan2";
	Locations[n].models.always.mill_movie2.rotate.x = 0.0;
	Locations[n].models.always.mill_movie2.rotate.y = 0.0;
	Locations[n].models.always.mill_movie2.rotate.z = 1.0;
	Locations[n].models.always.mill_movie2.tech = "dLightModel";

	Locations[n].models.always.mill_movie3 = "MillFan3";
	Locations[n].models.always.mill_movie3.locator.group = "Windmill";
	Locations[n].models.always.mill_movie3.locator.name = "fan3";
	Locations[n].models.always.mill_movie3.rotate.x = 0.0;
	Locations[n].models.always.mill_movie3.rotate.y = 0.0;
	Locations[n].models.always.mill_movie3.rotate.z = 1.0;
	Locations[n].models.always.mill_movie3.tech = "dLightModel";

	Locations[n].models.always.mill_movie4 = "MillFan4";
	Locations[n].models.always.mill_movie4.locator.group = "Windmill";
	Locations[n].models.always.mill_movie4.locator.name = "fan4";
	Locations[n].models.always.mill_movie4.rotate.x = 0.0;
	Locations[n].models.always.mill_movie4.rotate.y = 0.0;
	Locations[n].models.always.mill_movie4.rotate.z = 1.0;
	Locations[n].models.always.mill_movie4.tech = "dLightModel";

	//Day
	Locations[n].models.day.charactersPatch = "Shore02_p";
	//Night
	Locations[n].models.night.charactersPatch = "Shore02_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.4;
	//Reload map

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "shipwreck3";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "windmill_mast";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "windmill_mast";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "windmill_mast";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "windmill_mast";

	Locations[n].items.randitem6 = "1_log";

	Locations[n].locators_radius.randitem.randitem7 = 2.0;
	Locations[n].items.randitem7 = "1_log";

	Locations[n].locators_radius.randitem.randitem8 = 2.0;
	Locations[n].items.randitem8 = "1_log";

	Locations[n].items.randitem9 = "shell1";
	Locations[n].items.randitem10 = "shell2";
	Locations[n].items.randitem11 = "shell3";
	Locations[n].items.randitem12 = "shell4";
	Locations[n].items.randitem13 = "shell5";
	Locations[n].items.randitem14 = "shell6";

	Locations[n].locators_radius.box.box2 = 2.0;
	Locations[n].locators_radius.box.box4 = 0.001;			//2.0 later
	Locations[n].locators_radius.box.box5 = 0.001;			//2.0 later
	Locations[n].locators_radius.box.box8 = 3.0;

//	Build_at("Sullivan_shore2", "windmill", "", 3.0, 1.0, 169.0, 1, "");	//yes ok
	
	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Shore_10";

	Locations[n].id = "Sullivan_shore1";
	locations[n].id.label = "Sullivan shore";
	Locations[n].image = "Outside_Shore_10.tga";
	//Sound
	locations[n].type = "silent_seashore";
	//locations[n].type = "indian_seashore";
	//locations[n].type = "Sullivan_seashore";
	//Models
	//Always
	Locations[n].models.always.jungle = "shore10";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.locators = "shore10_l_GB_bug";			//shore10_l_GB_wood		
    	Locations[n].models.always.seabed = "shore10_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "Shore10_g";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	//Locations[n].models.always.l3 = "plan_3";
	//Locations[n].models.always.l3.level = 7;
	//Locations[n].models.always.l3.tech = "LocationModelBlend";

	Locations[n].models.always.mill_movie = "MillFan";
	Locations[n].models.always.mill_movie.locator.group = "Windmill";
	Locations[n].models.always.mill_movie.locator.name = "fan";
	Locations[n].models.always.mill_movie.rotate.x = 0.0;
	Locations[n].models.always.mill_movie.rotate.y = 0.0;
	Locations[n].models.always.mill_movie.rotate.z = 1.0;
	Locations[n].models.always.mill_movie.tech = "dLightModel";

	//Day
	Locations[n].models.day.charactersPatch = "shore10_p";
	//Night
	Locations[n].models.night.charactersPatch = "shore10_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.4;
	//Reload map
/*
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Sullivan_shore2";
	Locations[n].reload.l1.emerge = "box1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 3;
*/
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Sullivan_jungle1";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 3;

	Locations[n].reload.l20.name = "reload2_back";
	Locations[n].reload.l20.go = "Sullivan_jungle1";
	Locations[n].reload.l20.emerge = "reload2";
	Locations[n].reload.l20.autoreload = "1";
	Locations[n].reload.l20.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 2;

	//Build_at("Sullivan_shore1", "jungle", "", -0.7, -0.1, 9.9, 1, "");

	Locations[n].locators_radius.goto.stop = 2.0;
	Locations[n].locators_radius.goto.dialog = 2.0;
	Locations[n].locators_radius.box.box1 = 2.0;
	Locations[n].locators_radius.box.box4 = 2.0;
	Locations[n].locators_radius.box.box5 = 0.001;
	Locations[n].locators_radius.box.box6 = 1.5;

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "windmill_mast";

	Locations[n].items.randitem1 = "1_log";
	Locations[n].items.randitem3 = "1_log";
	Locations[n].items.randitem4 = "1_log";
	Locations[n].items.randitem5 = "1_log";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "crypto";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "goldbug";		

	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_QC";
	Locations[n].id = "Sullivan_jungle1";
	locations[n].id.label = "Sullivan jungle";
	Locations[n].image = "GB_Legrands_hut_outside.tga";
	//Town sack
	Locations[n].townsack = "Quebradas Costillas"; // KK
	//Sound
	locations[n].type = "Sullivan_jungle";
	locations[n].fastreload = "QC";
	LAi_LocationMonstersGen(&locations[n], false);
	
	//Models
	//Always
	Locations[n].models.always.locators = "QCexit_l_GB";
	Locations[n].models.always.exit = "QCexit";
	Locations[n].models.always.grassPatch = "QCexit_g";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";

	//Day
	Locations[n].models.day.charactersPatch = "QCexit_p";
	//Night
	Locations[n].models.night.charactersPatch = "QCexit_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map

	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Legrands_house";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].reload.l2.name = "Reload2";
	Locations[n].reload.l2.go = "Sullivan_shore1";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Sea port.";
	Locations[n].locators_radius.reload.reload2 = 3.0;

	Locations[n].reload.l3.name = "Reload3";
	Locations[n].reload.l3.go = "Sullivan_jungle2";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3 = 3.0;

	Locations[n].reload.l4.name = "Reload2_back";
	Locations[n].reload.l4.go = "Sullivan_shore1";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Sea port.";
	Locations[n].locators_radius.reload.Reload2_back = 2.0;

	Locations[n].reload.l5.name = "Reload3_back";
	Locations[n].reload.l5.go = "Sullivan_jungle2";
	Locations[n].reload.l5.emerge = "reload3";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload3_back = 2.0;

	Locations[n].locators_radius.box.box9 = 0.2;
	Locations[n].locators_radius.box.box10 = 0.2;
	Locations[n].locators_radius.box.box11 = 0.2;
	Locations[n].locators_radius.box.box12 = 0.2;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "pirate_house";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "chimney_pot";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "horse_fence";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "horse_fence";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "door_N06";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "well";

	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "horse_fence";

	Locations[n].locators_radius.randitem.randitem8 = 0.01;
	Locations[n].items.randitem8 = "horse_fence";

	Locations[n].locators_radius.randitem.randitem9 = 0.01;
	Locations[n].items.randitem9 = "horse_fence";

	Locations[n].locators_radius.randitem.randitem10 = 0.01;
	Locations[n].items.randitem10 = "horse_fence";

	Locations[n].locators_radius.randitem.randitem11 = 0.01;
	Locations[n].items.randitem11 = "barrel3";

	Locations[n].locators_radius.randitem.randitem12 = 0.01;
	Locations[n].items.randitem12 = "wheelbarrow";

	Locations[n].locators_radius.randitem.randitem13 = 0.01;
	Locations[n].items.randitem13 = "barrel3";

	Locations[n].locators_radius.randitem.randitem14 = 0.01;
	Locations[n].items.randitem14 = "iron_gate";

	Locations[n].locators_radius.randitem.randitem15 = 0.01;
	Locations[n].items.randitem15 = "iron_gate";

	Locations[n].locators_radius.randitem.randitem16 = 0.01;
	Locations[n].items.randitem16 = "iron_gate";

	Locations[n].locators_radius.randitem.randitem17 = 0.01;
	Locations[n].items.randitem17 = "door_attic";

	Locations[n].locators_radius.randitem.randitem18 = 0.01;
	Locations[n].items.randitem18 = "ladder_very_big_45";

	Locations[n].locators_radius.randitem.randitem19 = 0.01;
	Locations[n].items.randitem19 = "green";

	Locations[n].locators_radius.randitem.randitem20 = 0.01;
	Locations[n].items.randitem20 = "green";

	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_QC";
	Locations[n].id = "Legrands_backyard";
	locations[n].id.label = "Legrands backyard";
	Locations[n].image = "GB_Legrands_backyard.tga";
	//Town sack
	Locations[n].townsack = "Quebradas Costillas"; // KK
	//Sound
	locations[n].type = "silent_jungle";
	Locations[n].lockCamAngle = 0.0;
	locations[n].fastreload = "QC";
	LAi_LocationMonstersGen(&locations[n], false);
	
	//Models
	//Always
	Locations[n].models.always.locators = "QCexit_l_GB";
	Locations[n].models.always.exit = "QCexit";
	Locations[n].models.always.grassPatch = "QCexit_g";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
//	Locations[n].models.always.l3 = "plan_3";
//	Locations[n].models.always.l3.level = 7;
//	Locations[n].models.always.l3.tech = "LocationModelBlend";

	//Day
	Locations[n].models.day.charactersPatch = "QCexit_p";
	//Night
	Locations[n].models.night.charactersPatch = "QCexit_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map

	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Legrands_house";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].reload.l2.name = "Reload2";
	Locations[n].reload.l2.go = "Sullivan_shore";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Sea port.";
	Locations[n].locators_radius.reload.reload2 = 3.0;

	Locations[n].reload.l3.name = "Reload3";
	Locations[n].reload.l3.go = "Fort_Moultrie_exit";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3 = 3.0;

	Locations[n].reload.l4.name = "Reload2_back";
	Locations[n].reload.l4.go = "Sullivan_shore";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Sea port.";
	Locations[n].locators_radius.reload.Reload2_back = 2.0;

	Locations[n].reload.l5.name = "Reload3_back";
	Locations[n].reload.l5.go = "Fort_Moultrie_exit";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload3_back = 2.0;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "pirate_house";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "chimney_pot";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "horse_fence";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "horse_fence";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "door_N06";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "well";

	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "horse_fence";

	Locations[n].locators_radius.randitem.randitem8 = 0.01;
	Locations[n].items.randitem8 = "horse_fence";

	Locations[n].locators_radius.randitem.randitem9 = 0.01;
	Locations[n].items.randitem9 = "horse_fence";

	Locations[n].locators_radius.randitem.randitem10 = 0.01;
	Locations[n].items.randitem10 = "horse_fence";

	Locations[n].locators_radius.randitem.randitem11 = 0.01;
	Locations[n].items.randitem11 = "barrel3";

	Locations[n].locators_radius.randitem.randitem12 = 0.01;
	Locations[n].items.randitem12 = "wheelbarrow";

	Locations[n].locators_radius.randitem.randitem13 = 0.01;
	Locations[n].items.randitem13 = "barrel3";

	Locations[n].locators_radius.randitem.randitem14 = 0.01;
	Locations[n].items.randitem14 = "iron_gate";

	Locations[n].locators_radius.randitem.randitem15 = 0.01;
	Locations[n].items.randitem15 = "iron_gate";

	Locations[n].locators_radius.randitem.randitem16 = 0.01;
	Locations[n].items.randitem16 = "iron_gate";

	Locations[n].locators_radius.randitem.randitem17 = 0.01;
	Locations[n].items.randitem17 = "door_attic";

	Locations[n].locators_radius.randitem.randitem18 = 0.01;
	Locations[n].items.randitem18 = "ladder_very_big_45";

	Locations[n].locators_radius.randitem.randitem19 = 0.01;
	Locations[n].items.randitem19 = "green";

	Locations[n].locators_radius.randitem.randitem20 = 0.01;
	Locations[n].items.randitem20 = "green";

	Locations[n].locators_radius.randitem.randitem21 = 0.001;
	Locations[n].items.randitem21 = "fallen_tree2";

	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Pirate_House";
	Locations[n].id = "Legrands_house";
	locations[n].id.label = "Legrands house";
	Locations[n].image = "GB_Legrands_hut_inside.tga";
	//Sound
	locations[n].type = "Legrands_house";
	//Models
	//Always
	Locations[n].models.always.locators = "pirh_l_GB";
	Locations[n].models.always.house = "pirh";
	Locations[n].models.always.window = "pirh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "pirh_p";

	//Night
	Locations[n].models.night.charactersPatch = "pirh_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\juch_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Sullivan_jungle1";
	Locations[n].reload.l1.emerge = "box9";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Exit.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Legrands_kitchen";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 0.6;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Legrands_grot";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].locators_radius.reload.reload3 = 0.7;
	Locations[n].reload.l3.disable = 1;			

	Locations[n].locators_radius.box.box1 = 0.7;
	Locations[n].locators_radius.box.box2 = 0.6;
	Locations[n].locators_radius.box.box3 = 0.6;
	Locations[n].locators_radius.box.box4 = 0.6;
	Locations[n].locators_radius.box.box5 = 0.6;
	Locations[n].locators_radius.box.box6 = 0.6;
	Locations[n].locators_radius.box.box7 = 0.6;
	Locations[n].locators_radius.box.box8 = 0.001;			//to bed
	Locations[n].locators_radius.box.box9 = 0.001;			//to grot
	Locations[n].locators_radius.goto.treasure_gone = 1.0;
	Locations[n].locators_radius.officers.box4_2 = 2.0;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_U1";			//kitchen

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "door_N06";			//out

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "door_N";			//food cellar

//	Locations[n].locators_radius.randitem.randitem4 = 0.01;		
	Locations[n].items.randitem4 = "key20";				//only when locfile = pirh_l_GB_key

	Locations[n].locators_radius.randitem.randitem5 = 0.01;		
	Locations[n].items.randitem5 = "chest3L_vco";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;		
	Locations[n].items.randitem6 = "sack3";	

	Locations[n].locators_radius.randitem.randitem7 = 0.01;		
	Locations[n].items.randitem7 = "sack3";	

	Locations[n].locators_radius.randitem.randitem8 = 0.01;		
	Locations[n].items.randitem8 = "sack3";	

	Locations[n].locators_radius.randitem.randitem9 = 0.01;		
	Locations[n].items.randitem9 = "sack3";	

	Locations[n].locators_radius.randitem.randitem10 = 0.01;		
	Locations[n].items.randitem10 = "sack3";

	Locations[n].locators_radius.randitem.randitem11 = 0.01;		
	Locations[n].items.randitem11 = "sack3";	

	Locations[n].locators_radius.randitem.randitem12 = 0.01;		
	Locations[n].items.randitem12 = "sack3";	

	Locations[n].locators_radius.randitem.randitem13 = 0.01;		
	Locations[n].items.randitem13 = "sack3";

//	Locations[n].locators_radius.randitem.randitem14 = 0.01;		
	Locations[n].items.randitem14 = "poe_manuscript";		

	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	locations[n].id = "Legrands_kitchen";
	locations[n].id.label = "Legrands kitchen";
	Locations[n].image = "GB_Legrands_kitchen.tga";
	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "Legrands_house";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Legrands_kitchen";
	locations[n].models.always.l1 = "mediumhouse01";
	locations[n].models.always.l2 = "wood3";			//wood3 = glowing, wood4 = new unlit, wood5 = burned, "" = not enough wood left
	locations[n].models.always.l3 = "plank_up";
	locations[n].models.always.l4 = "damper_half";			//damper_closed, _half, _open
	locations[n].models.always.l5 = "";				//crypto_roll
	locations[n].models.always.l6 = "";				//fryingpan
	locations[n].models.always.l7 = "rope_up";
	locations[n].models.always.l8 = "";			//crypto_flat m.fl
	locations[n].models.always.l9 = "";				//cauldron3 or cauldron3_w later
//	locations[n].models.always.l10 = "ashes1";
	Locations[n].models.always.l10.tech = "EnvironmentShader";
	Locations[n].models.always.l10.reflection = 1;
//	locations[n].models.always.l11 = "ashes2";
	Locations[n].models.always.l11.tech = "EnvironmentShader";
	Locations[n].models.always.l11.reflection = 1;
					
	locations[n].models.always.locators = "mediumhouse01_locators_GB1";	//GB0, GB1, GB2

	Locations[n].models.always.window = "mediumhouse01_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
			
	//Day
	locations[n].models.day.charactersPatch = "mediumhouse01_patch";
	//Night
	locations[n].models.night.charactersPatch = "mediumhouse01_patch";
	//Environment
	locations[n].environment.weather = "false";		//coas true, potc false
	locations[n].environment.sea = "false";
	Locations[n].models.back = "back\juch_";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Legrands_house";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "";
	Locations[n].locators_radius.reload.reload1 = 0.5;

	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.box.box6 = 0.7;
	Locations[n].locators_radius.box.box7 = 0.5;
	Locations[n].locators_radius.goto.start = 1.0;
	Locations[n].locators_radius.goto.close = 0.3;
	Locations[n].locators_radius.goto.wake_up = 0.001;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "stool";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "door_U1";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "carpet1";

	Locations[n].items.randitem4 = "inkpen";

	LAi_LocationFightDisable(&Locations[n], true);	
	Locations[n].island = "Redmond";
	n = n + 1;

//  -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Grot";

	Locations[n].id = "Legrands_grot";
//	locations[n].id.label = "Legrands food cellar";		//later when opened
	Locations[n].image = "GB_Legrands_storeroom.tga";
	//Sound
	locations[n].type = "silent_cave_seashore";
	//Models
	Locations[n].models.back = "back\grotenv_";
	//Always
	Locations[n].models.always.cave = "Grot";
	Locations[n].models.always.locators = "Grot_l_GB";
	//Day
	Locations[n].models.day.charactersPatch = "Grot_p";
	//Night
	Locations[n].models.night.charactersPatch = "Grot_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Legrands_house";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 1;

	Locations[n].locators_radius.goto.jupiter = 2.0;
	Locations[n].locators_radius.goto.legrand = 0.1;
	Locations[n].locators_radius.box.box2 = 1.5;
	Locations[n].locators_radius.box.box4 = 0.001;			//1.2 when basket is p.u
	Locations[n].locators_radius.box.box5 = 1.1;
	Locations[n].locators_radius.box.box3 = 1.0;
	Locations[n].locators_radius.box.box8 = 1.0;
	Locations[n].locators_radius.box.box9 = 0.5;
	Locations[n].locators_radius.box.box10 = 0.5;
	Locations[n].locators_radius.box.box11 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.0001;
	Locations[n].items.randitem1 = "gatedoor_w";

	Locations[n].locators_radius.randitem.randitem2 = 0.0001;
	Locations[n].items.randitem2 = "door_N";

	Locations[n].locators_radius.randitem.randitem3 = 0.0001;
	Locations[n].items.randitem3 = "bookcase";

	Locations[n].locators_radius.randitem.randitem4 = 0.0001;
	Locations[n].items.randitem4 = "barrel3";

	Locations[n].locators_radius.randitem.randitem5 = 0.0001;
	Locations[n].items.randitem5 = "chest1";

	Locations[n].locators_radius.randitem.randitem6 = 0.0001;
	Locations[n].items.randitem6 = "toolchest1";

	Locations[n].locators_radius.randitem.randitem7 = 0.0001;
	Locations[n].items.randitem7 = "medicine_table";

	Locations[n].locators_radius.randitem.randitem8 = 0.0001;
	Locations[n].items.randitem8 = "barrel3";

	Locations[n].locators_radius.randitem.randitem9 = 0.0001;
	Locations[n].items.randitem9 = "bookcase";

	Locations[n].locators_radius.randitem.randitem10 = 0.0001;
	Locations[n].items.randitem10 = "sack3";

	Locations[n].locators_radius.randitem.randitem11 = 0.0001;
	Locations[n].items.randitem11 = "sack3";

	Locations[n].locators_radius.randitem.randitem12 = 0.0001;
	Locations[n].items.randitem12 = "chest5_coas";

//	Locations[n].locators_radius.randitem.randitem13 = 0.0001;
	Locations[n].items.randitem13 = "basket";

	Locations[n].locators_radius.randitem.randitem14 = 0.0001;
	Locations[n].items.randitem14 = "ale";

	Locations[n].locators_radius.randitem.randitem15 = 0.0001;
	Locations[n].items.randitem15 = "bigfish";

	Locations[n].locators_radius.randitem.randitem16 = 0.0001;
	Locations[n].items.randitem16 = "key12";			//small green box

	Locations[n].locators_radius.randitem.randitem17 = 0.0001;
	Locations[n].items.randitem17 = "sack3";

	Locations[n].locators_radius.randitem.randitem18 = 0.0001;
	Locations[n].items.randitem18 = "surgery_kit";

	Locations[n].locators_radius.randitem.randitem19 = 0.0001;
	Locations[n].items.randitem19 = "pillow";

	Locations[n].locators_radius.randitem.randitem20 = 0.0001;
	Locations[n].items.randitem20 = "book49";

	Locations[n].locators_radius.randitem.randitem21 = 0.0001;
	Locations[n].items.randitem21 = "violin";				

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------	

	Locations[n].filespath.models = "locations\Inside\Hut_attic";
	Locations[n].id = "Legrands_attic";
	locations[n].id.label = "Legrands attic";
	Locations[n].image = "GB_Legrands_attic.tga";
	//Sound
	locations[n].type = "Pym_tower";
	//Models
	//Always
	Locations[n].models.always.locators = "Hut_attic_locators";
	Locations[n].models.always.house = "Hut_attic";
	Locations[n].models.always.l1 = "Hut_attic_green";
	//Locations[n].models.always.window = "pirh_w";
	//Locations[n].models.always.window.tech = "LocationWindows";
	//Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Hut_attic_patch";

	//Night
	Locations[n].models.night.charactersPatch = "Hut_attic_patch";
	Locations[n].models.night.fonar = "Hut_attic_cloth";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\juch_";

	Locations[n].locators_radius.box.box4 = 0.001;			//0.5 when door is blocked
	Locations[n].locators_radius.box.box6 = 0.5;
	Locations[n].locators_radius.box.box7 = 0.5;
	Locations[n].locators_radius.box.box8 = 0.5;
	Locations[n].locators_radius.box.box9 = 0.5;
	Locations[n].locators_radius.box.box10 = 0.5;
	Locations[n].locators_radius.box.box11 = 0.5;
	Locations[n].locators_radius.box.box12 = 0.5;
	Locations[n].locators_radius.box.box13 = 0.5;
	Locations[n].locators_radius.box.box14 = 1.0;				

	Locations[n].locators_radius.randitem.randitem1 = 0.0001;
	Locations[n].items.randitem1 = "toolchest1";

	Locations[n].locators_radius.randitem.randitem2 = 1.0;
	Locations[n].items.randitem2 = "sack3";

	Locations[n].locators_radius.randitem.randitem3 = 1.0;
	Locations[n].items.randitem3 = "sack3";

	Locations[n].locators_radius.randitem.randitem4 = 0.0001;
	Locations[n].items.randitem4 = "jars";

	//.......................................................	

	Locations[n].locators_radius.randitem.randitem5 = 0.0001;
	Locations[n].items.randitem5 = "sack3";

	Locations[n].locators_radius.randitem.randitem6 = 0.0001;
	Locations[n].items.randitem6 = "sack3";	

	Locations[n].locators_radius.randitem.randitem7 = 0.0001;
	Locations[n].items.randitem7 = "sack3";	

	Locations[n].locators_radius.randitem.randitem8 = 0.0001;
	Locations[n].items.randitem8 = "sack3";	

	Locations[n].locators_radius.randitem.randitem9 = 0.0001;
	Locations[n].items.randitem9 = "sack3";	

	Locations[n].locators_radius.randitem.randitem10 = 0.0001;
	Locations[n].items.randitem10 = "sack3";

	Locations[n].locators_radius.randitem.randitem11 = 0.0001;
	Locations[n].items.randitem11 = "chest3U_vco";	

	Locations[n].locators_radius.randitem.randitem12 = 0.0001;
	Locations[n].items.randitem12 = "sack3";

	Locations[n].locators_radius.randitem.randitem13 = 0.0001;
	Locations[n].items.randitem13 = "sack3";		
	
	LAi_LocationFightDisable(&Locations[n], true);	
	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------	

	Locations[n].filespath.models = "locations\Outside\Jungle_6";

	Locations[n].id = "Sullivan_jungle2";
	locations[n].id.label = "Sullivan jungle";
	Locations[n].image = "Outside_Jungle_6.tga";
	//Sound
	locations[n].type = "Sullivan_jungle";
	LAi_LocationMonstersGen(&locations[n], false);
	
	//Models
	//Always
	Locations[n].models.always.locators = "Jungle06_l_GB";
	Locations[n].models.always.jungle = "Jungle06";
	Locations[n].models.always.grassPatch = "JUNGLE06_g";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	//Locations[n].models.always.l3 = "plan_3";
	//Locations[n].models.always.l3.level = 7;
	//Locations[n].models.always.l3.tech = "LocationModelBlend";

	//Day
	Locations[n].models.day.charactersPatch = "Jungle06_p";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle06_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload3";
	Locations[n].reload.l1.go = "Sullivan_jungle1";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1 = 1.0;

	Locations[n].reload.l2.name = "reload1";
	Locations[n].reload.l2.go = "Fort_Moultrie_exit";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2 = 3.0;

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Legrands_boathouse";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload3 = 3.0;

	Locations[n].reload.l4.name = "reload3_back";
	Locations[n].reload.l4.go = "Sullivan_jungle1";
	Locations[n].reload.l4.emerge = "reload3";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l5.name = "reload1_back";
	Locations[n].reload.l5.go = "Fort_Moultrie_exit";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3.0;

	Locations[n].reload.l6.name = "reload2_back";
	Locations[n].reload.l6.go = "Legrands_boathouse";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 3.0;

	Locations[n].island = "Conceicao"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Legrands_boathouse";
	locations[n].id.label = "Legrands boathouse";
	Locations[n].filespath.models = "locations\Outside\Shore_7";
	Locations[n].image = "GB_Legrands_boathouse.tga";
	//Sound
	locations[n].type = "silent_seashore";
   	 //Models
	//Always
	Locations[n].models.always.jungle = "Shore07";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.locators = "Shore07_l_GB";
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
	Locations[n].MaxSeaHeight = 0.2;
	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Sullivan_jungle2";
	Locations[n].reload.l1.emerge = "Reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 3.0;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Sullivan_jungle2";
	Locations[n].reload.l3.emerge = "Reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3.0;

	Locations[n].reload.l2.name = "boat";			//ev later
	Locations[n].reload.l2.go = "Redmond";
	Locations[n].reload.l2.emerge = "reload_1";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 9.0;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "pirate_shed";

	Locations[n].locators_radius.randitem.randitem2 = 1.0;
	Locations[n].items.randitem2 = "bladewoodsack";

	Locations[n].locators_radius.randitem.randitem3 = 1.8;
	Locations[n].items.randitem3 = "sail";

	Locations[n].locators_radius.box.box1 = 1.0;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.box.box6 = 0.5;
	Locations[n].locators_radius.box.box7 = 0.5;
	Locations[n].locators_radius.box.box8 = 0.5;
	Locations[n].locators_radius.box.box9 = 0.5;
	Locations[n].locators_radius.goto.exit_stop = 2.0;
	Locations[n].locators_radius.goto.attack = 20.0;
	
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Smuggler Lair\Exit";
	Locations[n].id = "Fort_Moultrie_exit";
	locations[n].id.label = "Sullivan jungle";
	Locations[n].image = "GB_Moultrie_village_outside.tga";

	//Town sack
	Locations[n].townsack = "Smugglers Lair"; // NK 04-08-29

	//Sound
	locations[n].type = "Sullivan_jungle";
	LAi_LocationMonstersGen(&locations[n], false);

	//Models
	//Always
	Locations[n].models.always.locators = "SmLexit_l_GB_start";
	Locations[n].models.always.exit = "SmLexit";
	Locations[n].models.always.townWalls = "fort_walls_stucco_2";
	Locations[n].models.always.l4 = "";				//start = "", later "fireplace_wood"
	Locations[n].models.always.grassPatch = "SmLexit_g";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	//Locations[n].models.always.l3 = "plan_3";
	//Locations[n].models.always.l3.level = 7;
	//Locations[n].models.always.l3.tech = "LocationModelBlend";

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
	Locations[n].reload.l1.go = "Sullivan_jungle2";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 2;
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Fort_Moultrie_shore";
	Locations[n].reload.l2.emerge = "locator3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload2 = 2;
	Locations[n].reload.l2.label = "Leviathan Rock.";

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Sullivan_jungle2";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 2;
	Locations[n].reload.l4.label = "Jungle.";

	Locations[n].reload.l5.name = "reload2_back";
	Locations[n].reload.l5.go = "Fort_Moultrie_shore";
	Locations[n].reload.l5.emerge = "locator3";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].locators_radius.reload.reload2_back = 2;
	Locations[n].reload.l5.label = "Leviathan Rock.";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Fort_Moultrie_village";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "#stown_name#.";

	Locations[n].locators_radius.reload.tipi1 = 2;
	Locations[n].locators_radius.reload.tipi2 = 2;
	Locations[n].locators_radius.box.box2 = 0.001;			//skip the shortcut

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "tipi";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "tipi";				

	Locations[n].island = "Conceicao"; // NK 04-08-29
	LAi_LocationFightDisable(&Locations[n], true);
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Smuggler Lair\Exit";
	Locations[n].id = "fake_Fort_Moultrie_exit";
	locations[n].id.label = "Sullivan jungle";
	Locations[n].image = "Smuggler_Lair_Exit.tga";

	//Town sack
	Locations[n].townsack = "Smugglers Lair"; // NK 04-08-29

	//Sound
	locations[n].type = "silent_jungle";
	LAi_LocationMonstersGen(&locations[n], false);

	//Models
	//Always
	Locations[n].models.always.locators = "SmLexit_l_GB_start";
	Locations[n].models.always.exit = "SmLexit";
	Locations[n].models.always.townWalls = "fort_walls_stucco_2";
	Locations[n].models.always.l4 = "";				//start = "", later "fireplace_wood"
	Locations[n].models.always.grassPatch = "SmLexit_g";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	//Locations[n].models.always.l3 = "plan_3";
	//Locations[n].models.always.l3.level = 7;
	//Locations[n].models.always.l3.tech = "LocationModelBlend";

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
	Locations[n].reload.l1.go = "Sullivan_jungle2";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 2;
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Fort_Moultrie_shore";
	Locations[n].reload.l2.emerge = "locator3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload2 = 2;
	Locations[n].reload.l2.label = "Leviathan Rock.";

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Sullivan_jungle2";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 2;
	Locations[n].reload.l4.label = "Jungle.";

	Locations[n].reload.l5.name = "reload2_back";
	Locations[n].reload.l5.go = "Fort_Moultrie_shore";
	Locations[n].reload.l5.emerge = "locator3";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].locators_radius.reload.reload2_back = 2;
	Locations[n].reload.l5.label = "Leviathan Rock.";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Fort_Moultrie_village";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "#stown_name#.";

	Locations[n].locators_radius.reload.tipi1 = 2;
	Locations[n].locators_radius.reload.tipi2 = 2;
	Locations[n].locators_radius.box.box2 = 0.001;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "tipi";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "tipi";				

	Locations[n].island = "Conceicao"; // NK 04-08-29
	LAi_LocationFightDisable(&Locations[n], true);
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Smuggler Lair\town";
	Locations[n].id = "Fort_Moultrie_village";
	locations[n].id.label = "Fort Moultrie village";
	Locations[n].image = "GB_Moultrie_village.tga";

	//Town sack
	Locations[n].townsack = "Smugglers Lair"; // NK 04-08-29

	//Sound
//	locations[n].type = "Fort_Moultrie_village";
	locations[n].type = "Empty_Moultrie_village";
	//locations[n].fastreload = "SL"; // Fast reload is SL, "conceicao" is for the conceicao town

	//Models
	//Always
	Locations[n].models.always.locators = "SmL_l_GB_closed";		//start
//Locations[n].models.always.locators = "SmL_l_GB_closed_smoke1";		//temp testing
	Locations[n].models.always.town = "SmL";
	Locations[n].models.always.townWalls = "fort_walls_stucco_1";
	Locations[n].models.always.l5 = "fort_entre";
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
//	Locations[n].models.always.l4 = "plan_4";
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
	Locations[n].reload.l1.go = "Fort_Moultrie_exit";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Moultrie_gatehouse";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Store.";
	//Locations[n].reload.l2.close_for_night = 1;		//later
	Locations[n].reload.l2.disable = 1;			//opened later
	
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Moultrie_finehouse";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Store.";
	//Locations[n].reload.l3.close_for_night = 1;		//later
	Locations[n].reload.l3.disable = 1;			//opened later

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Moultrie_smallhouse";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	//Locations[n].reload.l4.close_for_night = 1;		//later
	Locations[n].reload.l4.disable = 1;			//opened later

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "Fort_Moultrie_stairs";
	Locations[n].reload.l5.emerge = "goto1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Rheims' House.";

	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "Moultrie_hotel";
	Locations[n].reload.l6.emerge = "locator2";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Tavern.";
	//Locations[n].reload.l6.close_for_night = 1;		//later
	Locations[n].reload.l6.disable = 1;			//opened later

	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "Moultrie_largehouse";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Chief's House.";
	//Locations[n].reload.l7.close_for_night = 1;		//later
	Locations[n].reload.l7.disable = 1;			//opened later

	Locations[n].reload.l8.name = "reload8";
	Locations[n].reload.l8.go = "Moultrie_store";
	Locations[n].reload.l8.emerge = "reload1";
	Locations[n].reload.l8.autoreload = "0";
	//Locations[n].reload.l6.close_for_night = 1;		//later when opened
	Locations[n].reload.l8.disable = 1;			//opened later
			
	Locations[n].reload.l9.name = "reload9";
	Locations[n].reload.l9.go = "Moultrie_restaurant_kitchen";
	Locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l9.autoreload = "0";
	//Locations[n].reload.l6.close_for_night = 1;		//later when opened
	Locations[n].reload.l9.disable = 1;	
				
	Locations[n].reload.l10.name = "reload10";
	Locations[n].reload.l10.go = "Moultrie_restaurant";
	Locations[n].reload.l10.emerge = "reload2";
	Locations[n].reload.l10.disable = "0";
	Locations[n].reload.l10.autoreload = "0";
	//Locations[n].reload.l10.close_for_night = 1;		//later when opened
	Locations[n].reload.l10.disable = 1;			//opened later
	
	Locations[n].locators_radius.reload.reload11 = 0.5;

	Locations[n].reload.l12.name = "reload12";
	Locations[n].reload.l12.go = "Fort_Moultrie";
	Locations[n].reload.l12.emerge = "reload1";
	Locations[n].reload.l12.autoreload = "0";
	Locations[n].reload.l12.disable = 1;			//always closed, visible only when fort is locked
	Locations[n].locators_radius.reload.reload12 = 0.5;

	Locations[n].reload.l13.name = "reload13";
	Locations[n].reload.l13.go = "Moultrie_hotel";
	Locations[n].reload.l13.emerge = "reload3";
	Locations[n].reload.l13.disable = "0";
	Locations[n].reload.l13.autoreload = "0";
	Locations[n].reload.l13.disable = 1;			//opened later
						
	Locations[n].locators_radius.goto.closed = 1.0;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "Door_N07";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "Door_N07";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "Door_N07";

	LAi_LocationMonstersGen(&locations[n], false);
	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Conceicao"; // NK 04-08-29

	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Moultrie_hotel";
	//locations[n].id.label = "Fort Moultrie Hotel";			//later
	locations[n].id.label = "OPEN ONLY DURING TOURIST SEASON";
	Locations[n].image = "GB_Moultrie_hotel.tga";
	//Town sack
	Locations[n].townsack = "Quebradas Costillas"; // NK - "Oxbay";
	//Sound
	locations[n].type = "brothel_shop";

	//Models
	//Always
	Locations[n].filespath.models = "locations\Inside\StoreSmall";	
	Locations[n].models.always.locators = "SS_l_GB_hotel";
	Locations[n].models.always.l1 = "ss";
	Locations[n].models.always.window = "ss_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "ss_p";
	Locations[n].models.day.fonar = "SS_fn";

	//Night
	Locations[n].models.night.charactersPatch = "ss_p";
	Locations[n].models.night.fonar = "SS_fn";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\qcss_";
	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "Fort_Moultrie_village";
	Locations[n].reload.l1.emerge = "Reload6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.locator2 = 1.0;

	Locations[n].reload.l2.name = "locator1";
	Locations[n].reload.l2.go = "Moultrie_hotel_room1";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Store upstairs.";
	Locations[n].reload.l2.disable = 1;	

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Fort_Moultrie_village";
	Locations[n].reload.l3.emerge = "Reload13";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].locators_radius.reload.reload3 = 0.8;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Moultrie_hotel_stairs";
	Locations[n].reload.l4.emerge = "goto4";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Store upstairs.";
	Locations[n].reload.l4.disable = 1;

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "Moultrie_hotel";
	Locations[n].reload.l5.emerge = "box4";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.disable = 1;
	Locations[n].locators_radius.reload.reload5 = 0.5;		//0.0 when counter opened	

	Locations[n].locators_radius.box.box1 = 0.0001;
	Locations[n].locators_radius.box.box2 = 0.0001;		
	Locations[n].locators_radius.box.box3 = 0.0001;			//0.5 when counter opened
	Locations[n].locators_radius.box.box4 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_N09";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "armchair02";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "number_plate1";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "number_plate2";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Moultrie_hotel_room1";
	locations[n].id.label = "Room";
	Locations[n].image = "GB_hotel_room.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_private";		//temp
	locations[n].fastreload = "Redmond";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Doubleflour_house";
	Locations[n].models.always.locators = "LH_F2_l_GB";
	Locations[n].models.always.tavern = "LH_F2";
//	Locations[n].models.always.window = "LH_F2_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "LH_F2_p";

	//Night
	Locations[n].models.night.charactersPatch = "LH_F2_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Locations[n].models.back = "back\smumt_";		//this one existed
	Locations[n].models.back = "back\smumh_";		//added

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Moultrie_hotel";
	Locations[n].reload.l1.emerge = "locator1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "armchair02";

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Moultrie_hotel_stairs";
	locations[n].id.label = "Room";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house\\";
	Locations[n].image = "GB_small_stairs.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_private";
	
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F1_l_JRH";
	Locations[n].models.always.tavern = "LH_F1";
	Locations[n].models.always.window = "LF1_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "LH_F1_p";

	//Night
	Locations[n].models.night.charactersPatch = "LH_F1_p";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redlf2_";

	//Reload map
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Moultrie_hotel_room2";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Moultrie_hotel_stairs";
	Locations[n].reload.l3.emerge = "reload4";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Moultrie_hotel";
	Locations[n].reload.l4.emerge = "reload4";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.3;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_N09";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "gatedoor_w";

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Moultrie_hotel_room2";
	locations[n].id.label = "Room";
	Locations[n].filespath.models = "locations\inside\Tavern_room";
	Locations[n].image = "ck_bedroom.tga";

	//Town sack
	Locations[n].townsack = "Redmond"; // NK 04-08-29
	Locations[n].island = "Redmond"; // NK 04-08-29

	//Sound
	locations[n].type = "Rogers_private";
	//Models
	//Always
	Locations[n].models.always.locators = "tavern_room_locators_GB";
	Locations[n].models.always.l1 = "Tavern_room";
//	Locations[n].models.always.window = "Tavern_room_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Tavern_room_patch";

	//Night
	Locations[n].models.night.charactersPatch = "Tavern_room_patch";	

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Locations[n].models.back = "back\redmh_";
	Locations[n].models.back = "back\smumt_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Moultrie_hotel_stairs";
	Locations[n].reload.l1.emerge = "Reload2";
	Locations[n].reload.l1.autoreload = "0";
//	Locations[n].reload.l1.label = "Woodes Rogers' kitchen.";

	Locations[n].locators_radius.box.box1 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
//	Locations[n].items.randitem1 = "bed";				//not used

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "armchair02";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "armchair02";

	LAi_LocationFightDisable(&Locations[n], true);
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Moultrie_restaurant";
	locations[n].id.label = "OPEN ONLY DURING TOURIST SEASON";	
	Locations[n].filespath.models = "locations\inside\Tavern_2";
	Locations[n].image = "GB_Moultre_restaurant.tga";

	//Town sack
	Locations[n].townsack = "Havana";

	//Sound
	//locations[n].type = "Moultrie_restaurant";
	locations[n].type = "brothel_QC";

	//Models
	//Always
	Locations[n].models.always.tavern = "Tavern_2";
	Locations[n].models.always.locators = "Tavern_2_l_GB";
	//Day
	Locations[n].models.day.charactersPatch = "Tavern_2_p";

	//Night
	Locations[n].models.night.charactersPatch = "Tavern_2_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\SMUMH_";	
	//Reload map
/*
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Havana_town_02";
	Locations[n].reload.l1.emerge = "reload18";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
*/
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Fort_Moultrie_village";
	Locations[n].reload.l2.emerge = "reload10";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Moultrie_restaurant_kitchen";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Room in #stown_name# tavern.";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Hut";

	Locations[n].id = "Moultrie_restaurant_kitchen";
	locations[n].id.label = "Staff only";
	Locations[n].image = "GB_restaurant_kitchen.tga";

	//Sound
	//locations[n].type = "Rogers_jail";
	//locations[n].type = "brothel_QC";
	locations[n].type = "party";
	//Models
	//Always
	Locations[n].models.always.locators = "Hut_locators_GB";
	Locations[n].models.always.house = "Hut";
	//Locations[n].models.always.l1 = "mine";
	//Day
	Locations[n].models.day.charactersPatch = "Hut_patch";
	//Night
	Locations[n].models.night.charactersPatch = "Hut_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\SMUMH_";
	//Reload map

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Fort_Moultrie_village";
	Locations[n].reload.l1.emerge = "reload9";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 0.0001;		//1.0 later	
	
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Moultrie_restaurant";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].locators_radius.box.box1 = 1.0;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "gatedoor_small_stone";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "gatedoor_small_stone";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;		//not used

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "gatedoor_small_stone";

	Locations[n].items.randitem5 = "empty_bottle";

	Locations[n].island = "Redmond";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Moultrie_store";
	locations[n].id.label = "OPEN ONLY DURING TOURIST SEASON";		
	Locations[n].filespath.models = "locations\inside\store04";
	Locations[n].image = "GB_Moultrie_store.tga";
	//Locations[n].image = "";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "brothel_room_QC";

	//Models
	//Always
	Locations[n].models.always.locators = "store04_locators_GB_store";
//	Locations[n].models.always.locators = "store04_locators";
	Locations[n].models.always.tavern = "store04";
	Locations[n].models.always.window = "store04_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "store04_patch";

	//Night
	Locations[n].models.night.charactersPatch = "store04_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\SMUMH_";

	//Reload map
	//town
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Fort_Moultrie_village";
	Locations[n].reload.l1.emerge = "reload8";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Redmond.";
	Locations[n].locators_radius.reload.reload1 = 0.5;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Moultrie_store_room";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Private.";
	Locations[n].locators_radius.reload.reload2 = 0.0001;		//0.8 when opened	

	Locations[n].locators_radius.goto.stop = 0.8;

	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.7;
	Locations[n].locators_radius.box.box4 = 0.7;
	Locations[n].locators_radius.box.box5 = 0.6;
	Locations[n].locators_radius.box.box6 = 0.7;

	Locations[n].locators_radius.box.box7 = 0.6;
	Locations[n].locators_radius.box.box8 = 0.6;
	Locations[n].locators_radius.box.box9 = 0.6;
	Locations[n].locators_radius.box.box10 = 0.6;
	Locations[n].locators_radius.box.box11 = 0.6;
	Locations[n].locators_radius.box.box12 = 0.6;
	Locations[n].locators_radius.box.box13 = 0.6;
	Locations[n].locators_radius.box.box14 = 0.6;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "gatedoor_Wi2";		

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "gatedoor_CRY";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "chair";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Moultrie_store_room";
//	locations[n].id.label = "Woodes Rogers' secret room";		//open = on
	Locations[n].filespath.models = "locations\inside\MediumStore_inner";
	Locations[n].image = "GB_storeroom.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "brothel_room_QC";

	//Models
	//Always
	Locations[n].models.always.locators = "MS_l_GB";
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
	//Locations[n].models.back = "back\redms_";

	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Moultrie_store";
	Locations[n].reload.l1.emerge = "goto1";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].locators_radius.box.box1 = 0.0001;			//not used
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.box.box6 = 0.5;
	Locations[n].locators_radius.box.box7 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "gatedoor_p";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "gatedoor_p";

	Locations[n].locators_radius.randitem.randitem3 = 1.0;
	Locations[n].items.randitem3 = "pistolbedlinen";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "ale";

	Locations[n].locators_radius.camdetector.camera1 = 5;

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Moultrie_gatehouse";
	locations[n].id.label = "Summer cottage";
	Locations[n].image = "Inside_mh6.tga";

	//Town sack
	//Locations[n].townsack = "Redmond";

	//Sound
	//locations[n].type = "brothel_room_QC";
	locations[n].type = "Rogers_study";
	
	//locations[n].fastreload = "Redmond";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\mh6";
	Locations[n].models.always.city = "mh6";
	Locations[n].models.always.locators = "mh6_l";
	Locations[n].models.always.window = "mh6_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
//	Locations[n].models.day.lamp = "FalaiseDeFleur05_day";
	Locations[n].models.day.charactersPatch = "mh6_p";

	//Night
//	Locations[n].models.night.lamp = "FalaiseDeFleur05_night";
	Locations[n].models.night.charactersPatch = "mh6_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redmh6_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Fort_Moultrie_village";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Moultrie_finehouse";
	locations[n].id.label = "Summer cottage";
	Locations[n].filespath.models = "locations\inside\mh5";
	Locations[n].image = "Inside_mh5.tga";

	//Town sack
	//Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "Rogers_study";
	//locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].models.always.locators = "mh5_l";
	Locations[n].models.always.house = "mh5";
	Locations[n].models.always.window = "mh5_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "mh5_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh5_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\ffmh5_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Fort_Moultrie_village";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Slums.";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\MediumHouse2";

	Locations[n].id = "Moultrie_largehouse";
	locations[n].id.label = "Summer cottage";
	Locations[n].image = "wr_friday.tga";

	//Town sack
	//Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_study";

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
	Locations[n].models.back = "back\SMUMH2_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Fort_Moultrie_village";
	Locations[n].reload.l1.emerge = "reload7";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Woodes Rogers' booty room";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Moultrie_smallhouse";
	locations[n].id.label = "Summer cottage";
	Locations[n].filespath.models = "locations\inside\IndianHome";
	Locations[n].image = "Inside_IndianHome.tga";

	//Town sack
	//Locations[n].townsack = "Aruba";

	//Sound
	locations[n].type = "Rogers_study";
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
	Locations[n].models.back = "back\SMUSH_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Fort_Moultrie_village";
	Locations[n].reload.l1.emerge = "Reload4";
	Locations[n].reload.l1.autoreload = "0";
	//Locations[n].reload.l1.label = "Arawak_Village";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "Aruba"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Dungeon_1_wood";
	Locations[n].id = "Fort_Moultrie_stairs";
	locations[n].id.label = "Fort Moultrie exit";
	Locations[n].image = "GB_Fort_stairs.tga";
	
	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "silent_loghouse";

	//Models
	//Always
	Locations[n].models.always.locators = "d01_l_GB";
	Locations[n].models.always.house = "d01";
	//Day
	Locations[n].models.day.charactersPatch = "d01_p";
	//Night
	Locations[n].models.night.charactersPatch = "d01_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Fort_Moultrie";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Redmond shipyard.";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Fort_Moultrie_village";
	Locations[n].reload.l3.emerge = "reload11";
	Locations[n].reload.l3.autoreload = "1";				
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "gatedoor_small";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "gatedoor_small";

	Locations[n].locators_radius.randitem.randitem8 = 0.1;
	Locations[n].items.randitem8 = "gatedoor_w";

	Locations[n].island = "Redmond";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Fort_Moultrie";
	locations[n].id.label = "Fort Moultrie";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\White_fort";
	Locations[n].image = "GB_Fort_Moultrie.tga"; // KK

	//Town sack
	Locations[n].townsack = "Greenford";
	//Sound
	locations[n].type = "Fort_Moultrie";

	//Models
	//Always
	Locations[n].models.always.locators = "fort2_locators_GB1";
	Locations[n].models.always.l1 = "fort2";
	Locations[n].models.always.l2 = "ropesA";
	Locations[n].models.always.l3 = "plankA";
	Locations[n].models.always.l4 = "plankB";
	//Day
	Locations[n].models.day.charactersPatch = "fort2_patch";
	Locations[n].models.day.fonar = "fort2_fd";
	//Night
	Locations[n].models.night.charactersPatch = "fort2_patch";
	Locations[n].models.night.fonar = "fort2_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	//reload map.

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Fort_Moultrie_stairs";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Fort_Moultrie_prison";
	Locations[n].reload.l2.emerge = "goto130";
	Locations[n].reload.l2.autoreload = "0";
	//Locations[n].reload.l2.disable = 1;				//open from start
	
	//tower 1
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Fort_M_tower1A";
	Locations[n].reload.l3.emerge = "goto3";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.disable = 1;

	//closed storehouse
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Fort_M_closed_loc";
	Locations[n].reload.l4.emerge = "goto3";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.disable = 1;

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "Lieutenant_G_kitchen";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.disable = 1;	

	//tower 2
	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "Fort_M_tower2A";
	Locations[n].reload.l6.emerge = "goto3";
	Locations[n].reload.l6.autoreload = "0";

	//closed storehouse
	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "Fort_M_closed_loc";
	Locations[n].reload.l7.emerge = "goto3";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.disable = 1;
	Locations[n].locators_radius.reload.reload7 = 0.6;

	//closed storehouse
	Locations[n].reload.l8.name = "reload8";
	Locations[n].reload.l8.go = "Fort_M_closed_loc";
	Locations[n].reload.l8.emerge = "goto3";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.disable = 1;

	//tower 3
	Locations[n].reload.l9.name = "reload9";
	Locations[n].reload.l9.go = "Fort_M_tower3A";
	Locations[n].reload.l9.emerge = "goto3";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.disable = 1;

	Locations[n].reload.l10.name = "reload10";
	Locations[n].reload.l10.go = "Fort_Moultrie_barracks_entre";
	Locations[n].reload.l10.emerge = "reload1";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.disable = 1;

	//tower 4
	Locations[n].reload.l12.name = "reload12";
	Locations[n].reload.l12.go = "Fort_M_tower4A";
	Locations[n].reload.l12.emerge = "goto3";
	Locations[n].reload.l12.autoreload = "0";

	Locations[n].reload.l13.name = "reload13";
	Locations[n].reload.l13.go = "Fort_Moultrie_armory";
	Locations[n].reload.l13.emerge = "reload2";
	Locations[n].reload.l13.autoreload = "0";
	Locations[n].reload.l13.disable = 1;					//opened from inside

	Locations[n].reload.l15.name = "reload15";
	Locations[n].reload.l15.go = "Fort_M_tower1B";
	Locations[n].reload.l15.emerge = "reload9";
	Locations[n].reload.l15.autoreload = "0";
	
	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box11 = 0.5;
	Locations[n].locators_radius.box.box14 = 0.5;
	Locations[n].locators_radius.box.box15 = 0.5;
	Locations[n].locators_radius.box.box16 = 0.5;
	Locations[n].locators_radius.box.box18 = 0.5;
	Locations[n].locators_radius.box.box19 = 0.5;
	Locations[n].locators_radius.box.box20 = 0.5;
	Locations[n].locators_radius.box.box21 = 0.5;
	Locations[n].locators_radius.box.box22 = 0.5;			//not used
	Locations[n].locators_radius.box.box23 = 0.0001;		//not used
	Locations[n].locators_radius.box.box24 = 0.1;
	Locations[n].locators_radius.box.box25 = 0.5;
	Locations[n].locators_radius.box.box26 = 0.5;
	Locations[n].locators_radius.box.box27 = 0.5;
	Locations[n].locators_radius.box.box28 = 0.5;
	Locations[n].locators_radius.box.box29 = 0.5;
	Locations[n].locators_radius.box.box30 = 0.5;
	Locations[n].locators_radius.box.box31 = 0.5;
	Locations[n].locators_radius.box.box32 = 0.5;
	Locations[n].locators_radius.box.box33 = 0.1;
	Locations[n].locators_radius.box.box34 = 0.5;
	Locations[n].locators_radius.box.box35 = 0.1;
	Locations[n].locators_radius.box.box36 = 0.0001;		//door to barracks
	Locations[n].locators_radius.box.box37 = 0.0001;		//door to prison
	Locations[n].locators_radius.box.box38 = 0.0001;		//door to G house
	Locations[n].locators_radius.box.box39 = 0.5;			//top2 down
	Locations[n].locators_radius.box.box40 = 0.5;			//top3 down
	Locations[n].locators_radius.box.box41 = 0.5;			//to tower4

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "door_barn";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "bench";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "hatch13";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "bench";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "hatch13";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "hatch11";

	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "door_fort";

	Locations[n].locators_radius.randitem.randitem8 = 0.01;
	Locations[n].items.randitem8 = "door_fort";

	Locations[n].locators_radius.randitem.randitem9 = 0.01;
	Locations[n].items.randitem9 = "ladder_big";

	Locations[n].locators_radius.randitem.randitem10 = 2.0;
	Locations[n].items.randitem10 = "ladder_big_45";

	Locations[n].locators_radius.randitem.randitem11 = 0.01;
	Locations[n].items.randitem11 = "door_N06";			//to 5C

	Locations[n].locators_radius.randitem.randitem12 = 0.01;
	Locations[n].items.randitem12 = "hatch11";

	Locations[n].locators_radius.randitem.randitem13 = 0.01;
	Locations[n].items.randitem13 = "hatch11D_O2";

	Locations[n].locators_radius.randitem.randitem14 = 0.01;
	Locations[n].items.randitem14 = "swamp_island2";

	Locations[n].locators_radius.randitem.randitem15 = 0.01;
	Locations[n].items.randitem15 = "qcport_plan3";

	Locations[n].locators_radius.randitem.randitem16 = 0.01;
	Locations[n].items.randitem16 = "qcport_plan3";

	Locations[n].locators_radius.randitem.randitem17 = 0.01;		//low, left
	Locations[n].items.randitem17 = "qcport_plan3";

	Locations[n].locators_radius.randitem.randitem18 = 0.01;		//low, right
	Locations[n].items.randitem18 = "qcport_plan3";

	Locations[n].locators_radius.randitem.randitem19 = 0.01;
	Locations[n].items.randitem19 = "qcport_plan3";

	Locations[n].locators_radius.randitem.randitem20 = 0.01;
	Locations[n].items.randitem20 = "swamp_island2";

	Locations[n].locators_radius.randitem.randitem21 = 0.01;
	Locations[n].items.randitem21 = "swamp_island2";

	Locations[n].locators_radius.randitem.randitem22 = 0.01;
	Locations[n].items.randitem22 = "swamp_island2";

	//Locations[n].locators_radius.randitem.randitem23 = 0.5;
	Locations[n].items.randitem23 = "spyglass6";

	Build_at("Fort_Moultrie", "church", "", 163.0, 10.0, -423.0, 5.0, "");

	Locations[n].island = "Antigua";
	LAi_LocationMonstersGen(&locations[n], false);
	Locations[n].vcskip = true;
	LAi_LocationFightDisable(&Locations[n], true);
	n = n + 1;

//--------------------------------------------------------------------------

	//fake locations Fort Moultrie - never opened
	Locations[n].id = "Fort_M_closed_loc";
	//locations[n].id.label = "Storehouse";
	Locations[n].filespath.models = "locations\inside\store04";

	//Town sack
//	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Fort_Moultrie_inside";

	//Models
	//Always

	Locations[n].models.always.locators = "store04_locators_GB_tower1B";
	Locations[n].models.always.tavern = "store04";
	Locations[n].models.always.window = "store04_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "store04_patch";

	//Night
	Locations[n].models.night.charactersPatch = "store04_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Locations[n].models.back = "back\redmh4_";
	Locations[n].models.back = "back\fort_";
	//Locations[n].models.back = "back\shp_";

	//Reload map
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Fort_M_tower4B";
	Locations[n].reload.l4.emerge = "reload4";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "";

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	//Tower 1A
	Locations[n].id = "Fort_M_tower1A";
	locations[n].id.label = "North tower";
	Locations[n].filespath.models = "locations\inside\store04";
	Locations[n].filespath.textures = "locations\inside\store04\church";
	Locations[n].image = "GB_Fort_tower.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Fort_Moultrie_inside";

	//Models
	//Always
	Locations[n].models.always.locators = "store04_locators_JRH5";
	Locations[n].models.always.tavern = "store04";
	Locations[n].models.always.window = "store04_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "store04_patch";

	//Night
	Locations[n].models.night.charactersPatch = "store04_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\smumh_";

	//Reload map
	//up
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Fort_M_tower1B";
	Locations[n].reload.l4.emerge = "goto3";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.5;

	//down
	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "Fort_Moultrie";
	Locations[n].reload.l7.emerge = "reload3";
	Locations[n].reload.l7.autoreload = "1";
	Locations[n].reload.l7.label = "";

	Locations[n].locators_radius.goto.goto3 = 1.0;

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "gatedoor_CRY";

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
//	Locations[n].items.randitem14 = "gatedoor_p";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	//Tower 1B
	Locations[n].id = "Fort_M_tower1B";
	locations[n].id.label = "North tower";
	Locations[n].filespath.models = "locations\inside\store04";
	Locations[n].filespath.textures = "locations\inside\store04\church";
	Locations[n].image = "GB_Fort_tower.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Fort_Moultrie_inside";

	//Models
	//Always
	Locations[n].models.always.locators = "store04_locators_GB_tower1B";
	Locations[n].models.always.tavern = "store04";
	Locations[n].models.always.window = "store04_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "store04_patch";

	//Night
	Locations[n].models.night.charactersPatch = "store04_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\fort_";

	//Reload map

	//up
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Fort_M_tower1C";		//fake loc
	Locations[n].reload.l4.emerge = "goto3";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.5;
	Locations[n].reload.l4.disable = 1;

	Locations[n].reload.l8.name = "reload8";
	Locations[n].reload.l8.go = "Fort_Moultrie";
	Locations[n].reload.l8.emerge = "box12";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "";
	Locations[n].locators_radius.reload.reload8 = 0.5;
	Locations[n].reload.l8.disable = 1;

	Locations[n].reload.l9.name = "reload9";
	Locations[n].reload.l9.go = "Fort_Moultrie";
	Locations[n].reload.l9.emerge = "reload15";		
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "";
	Locations[n].locators_radius.reload.reload9 = 0.5;

	//down
	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "Fort_M_tower1A";
	Locations[n].reload.l7.emerge = "reload4";
	Locations[n].reload.l7.autoreload = "1";
	Locations[n].reload.l7.label = "";

	Locations[n].locators_radius.goto.goto3 = 1.0;

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "door_fort";

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "door_fort";

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "gatedoor_CRY";

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
//	Locations[n].items.randitem14 = "gatedoor_p";

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	Locations[n].items.randitem15 = "key8";				//no lilgun

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	//fake Tower 1C
	Locations[n].id = "Fort_M_tower1C";
	locations[n].id.label = "The upper part of the tower is destroyed";
	Locations[n].filespath.models = "locations\inside\store04";

	//Town sack
//	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Fort_Moultrie_inside";

	//Models
	//Always

	Locations[n].models.always.locators = "store04_locators_GB_tower1B";
	Locations[n].models.always.tavern = "store04";
	Locations[n].models.always.window = "store04_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "store04_patch";

	//Night
	Locations[n].models.night.charactersPatch = "store04_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Fort_M_tower1B";
	Locations[n].reload.l4.emerge = "reload4";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "";

	Locations[n].island = "Redmond"; // NK 04-08-29

	n = n + 1;

//--------------------------------------------------------------------------

	//Tower 2A
	Locations[n].id = "Fort_M_tower2A";
	locations[n].id.label = "East tower";
	Locations[n].filespath.models = "locations\inside\store04";
	Locations[n].filespath.textures = "locations\inside\store04\church";
	Locations[n].image = "GB_Fort_tower.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Fort_Moultrie_inside";

	//Models
	//Always
	Locations[n].models.always.locators = "store04_locators_JRH5";
	Locations[n].models.always.tavern = "store04";
	Locations[n].models.always.window = "store04_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "store04_patch";

	//Night
	Locations[n].models.night.charactersPatch = "store04_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\fort_";

	//Reload map
	//up
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Fort_M_tower2B";
	Locations[n].reload.l4.emerge = "goto3";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.5;

	//down
	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "Fort_Moultrie";
	Locations[n].reload.l7.emerge = "reload6";
	Locations[n].reload.l7.autoreload = "1";
	Locations[n].reload.l7.label = "";

	Locations[n].locators_radius.goto.goto3 = 1.0;

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "gatedoor_CRY";

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
//	Locations[n].items.randitem14 = "gatedoor_p";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	//Tower 2B
	Locations[n].id = "Fort_M_tower2B";
	locations[n].id.label = "East tower";
	Locations[n].filespath.models = "locations\inside\store04";
	Locations[n].filespath.textures = "locations\inside\store04\church";
	Locations[n].image = "GB_Fort_tower.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Fort_Moultrie_inside";

	//Models
	//Always
	Locations[n].models.always.locators = "store04_locators_GB_tower2B";
	Locations[n].models.always.tavern = "store04";
	Locations[n].models.always.window = "store04_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "store04_patch";

	//Night
	Locations[n].models.night.charactersPatch = "store04_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\shp_";

	//Reload map

	//up
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Fort_M_tower2C";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.5;
	Locations[n].reload.l4.disable = 1;

	Locations[n].reload.l8.name = "reload8";
	Locations[n].reload.l8.go = "Fort_Moultrie";
	Locations[n].reload.l8.emerge = "box3";			//direction G house
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "";
	Locations[n].locators_radius.reload.reload8 = 0.5;

	//down
	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "Fort_M_tower2A";
	Locations[n].reload.l7.emerge = "reload4";
	Locations[n].reload.l7.autoreload = "1";
	Locations[n].reload.l7.label = "";

	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.goto.goto3 = 1.0;

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "door_fort";

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "door_fort";

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "gatedoor_CRY";

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
//	Locations[n].items.randitem14 = "gatedoor_p";

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	Locations[n].items.randitem15 = "lilgun";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Fort_M_tower2C";
	locations[n].id.label = "East tower";
	Locations[n].filespath.models = "locations\inside\mh5";
	Locations[n].image = "Inside_mh5.tga";

	//Town sack
//	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "Fort_Moultrie_inside";
//	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].models.always.locators = "mh5_l_GB";
	Locations[n].models.always.house = "mh5";
//	Locations[n].models.always.window = "mh5_w";			//try off
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "mh5_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh5_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\fort_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Fort_M_tower2B";		//was 2C
	Locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Fort_Moultrie";
	Locations[n].reload.l2.emerge = "top2A";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 0.6;

	Locations[n].locators_radius.box.box4 = 0.7;
	Locations[n].locators_radius.box.box5 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "hatch11D";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "gatedoor_store4_wall";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "gatedoor_store4_wall";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "gatedoor_store4_wall";
	
	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	//Tower 3A
	Locations[n].id = "Fort_M_tower3A";
	locations[n].id.label = "South tower under repair";
	Locations[n].filespath.models = "locations\inside\store04";
	Locations[n].filespath.textures = "locations\inside\store04\church";
	Locations[n].image = "GB_Fort_tower.tga";

	//Town sack
//	Locations[n].townsack = "Redmond";

	//Sound
	//locations[n].type = "Fort_Moultrie_inside";
	locations[n].type = "silent_repair";

	//Models
	//Always
	Locations[n].models.always.locators = "Store04_locators_GB_tower3A";
	Locations[n].models.always.tavern = "store04";
	Locations[n].models.always.window = "store04_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "store04_patch";

	//Night
	Locations[n].models.night.charactersPatch = "store04_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\shp_";

	//Reload map
	//up
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Fort_M_tower3B";
	Locations[n].reload.l4.emerge = "goto3";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.5;

	//down
	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "Fort_Moultrie";
	Locations[n].reload.l7.emerge = "reload9";
	Locations[n].reload.l7.autoreload = "1";
	Locations[n].reload.l7.label = "";

	Locations[n].locators_radius.goto.goto3 = 1.0;
	Locations[n].locators_radius.goto.stop = 1.0;

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "gatedoor_CRY";

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
//	Locations[n].items.randitem14 = "gatedoor_p";

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	Locations[n].items.randitem15 = "derrick";

	Locations[n].locators_radius.randitem.randitem16 = 0.001;
	Locations[n].items.randitem16 = "2_close_boxes";

	Locations[n].locators_radius.randitem.randitem17 = 0.001;
	Locations[n].items.randitem17 = "damper_open";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	//Tower 3B
	Locations[n].id = "Fort_M_tower3B";
	locations[n].id.label = "South tower";
	Locations[n].filespath.models = "locations\inside\store04";
	Locations[n].filespath.textures = "locations\inside\store04\church";
	Locations[n].image = "GB_Fort_tower.tga";

	//Town sack
//	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Fort_Moultrie_inside";

	//Models
	//Always
	Locations[n].models.always.locators = "store04_locators_GB_tower3B";
	Locations[n].models.always.tavern = "store04";
	Locations[n].models.always.window = "store04_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "store04_patch";

	//Night
	Locations[n].models.night.charactersPatch = "store04_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\fort_";

	//Reload map
	//up
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Fort_M_tower3C";		
	Locations[n].reload.l4.emerge = "reload1";		//was reload4
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.5;
/*
	Locations[n].reload.l8.name = "reload8";
	Locations[n].reload.l8.go = "Fort_Moultrie";
	Locations[n].reload.l8.emerge = "box11";			//direction G house
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "";
	Locations[n].locators_radius.reload.reload8 = 0.5;
//Locations[n].reload.l8.disable = 1;
*/

	//never opened
	Locations[n].reload.l9.name = "reload9";
	Locations[n].reload.l9.go = "Fort_Moultrie";
	Locations[n].reload.l9.emerge = "reload14";		
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "";
	Locations[n].locators_radius.reload.reload9 = 0.5;
	Locations[n].reload.l9.disable = 1;

	//down
	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "Fort_M_tower3A";
	Locations[n].reload.l7.emerge = "reload4";
	Locations[n].reload.l7.autoreload = "1";
	Locations[n].reload.l7.label = "";

	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.goto.goto3 = 1.0;

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "door_fort";

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "door_fort";

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "gatedoor_CRY";

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
//	Locations[n].items.randitem14 = "gatedoor_p";

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	Locations[n].items.randitem15 = "lilgun";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Fort_M_tower3C";
	locations[n].id.label = "South tower";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house\\";
	Locations[n].filespath.textures = "locations\inside\Doubleflour_house\church_attic";
	Locations[n].image = "GB_Fort_room.tga";

	//Town sack
	//Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Fort_Moultrie_inside";

	//Models
	//Always
	Locations[n].models.always.locators = "LH_F1_l_GB3";		//was JRH1
	Locations[n].models.always.tavern = "LH_F1";
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

	//Reload map
	//down
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Fort_M_tower3B";
	Locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";

	//up
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Fort_Moultrie";
	Locations[n].reload.l2.emerge = "box34";			//was top3A, top3temp at flag pole
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].locators_radius.box.box1 = 1.0;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "gatedoor_BRI";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "hatch11D";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "gateroof_wood";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "gatedoor_attic_brick";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "ladder_big";

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	//Tower 4A
	Locations[n].id = "Fort_M_tower4A";
	locations[n].id.label = "West tower";
	Locations[n].filespath.models = "locations\inside\store04";
	Locations[n].filespath.textures = "locations\inside\store04\church";
	Locations[n].image = "GB_Fort_tower.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Fort_Moultrie_inside";

	//Models
	//Always
	Locations[n].models.always.locators = "store04_locators_JRH5";
	Locations[n].models.always.tavern = "store04";
	Locations[n].models.always.window = "store04_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "store04_patch";

	//Night
	Locations[n].models.night.charactersPatch = "store04_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\fort_";

	//Reload map
	//up
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Fort_M_tower4B";
	Locations[n].reload.l4.emerge = "goto3";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.5;

	//down
	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "Fort_Moultrie";
	Locations[n].reload.l7.emerge = "reload12";
	Locations[n].reload.l7.autoreload = "1";
	Locations[n].reload.l7.label = "";

	Locations[n].locators_radius.goto.goto3 = 1.0;

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "gatedoor_CRY";

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
//	Locations[n].items.randitem14 = "gatedoor_p";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	//Tower 4B
	Locations[n].id = "Fort_M_tower4B";
	locations[n].id.label = "West tower";
	Locations[n].filespath.models = "locations\inside\store04";
	Locations[n].filespath.textures = "locations\inside\store04\church";
	Locations[n].image = "GB_Fort_tower.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Fort_Moultrie_inside";

	//Models
	//Always
	Locations[n].models.always.locators = "store04_locators_GB_tower4B";
	Locations[n].models.always.tavern = "store04";
	Locations[n].models.always.window = "store04_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "store04_patch";

	//Night
	Locations[n].models.night.charactersPatch = "store04_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\smumh_";

	//Reload map

	//up
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Fort_M_tower4C";		//fake loc
	Locations[n].reload.l4.emerge = "goto3";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.5;
	Locations[n].reload.l4.disable = 1;

	//never opened
	Locations[n].reload.l8.name = "reload8";
	Locations[n].reload.l8.go = "Fort_Moultrie";
	Locations[n].reload.l8.emerge = "reload14";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "";	
	Locations[n].locators_radius.reload.reload8 = 0.5;
	Locations[n].reload.l8.disable = 1;

	Locations[n].reload.l9.name = "reload9";
	Locations[n].reload.l9.go = "Fort_Moultrie";
	Locations[n].reload.l9.emerge = "reload14";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "";
	Locations[n].locators_radius.reload.reload9 = 0.5;	

	//down
	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "Fort_M_tower4A";
	Locations[n].reload.l7.emerge = "reload4";
	Locations[n].reload.l7.autoreload = "1";
	Locations[n].reload.l7.label = "";

	Locations[n].locators_radius.goto.goto3 = 1.0;

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "door_fort";

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "door_fort";

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "gatedoor_CRY";

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
//	Locations[n].items.randitem14 = "gatedoor_p";

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	Locations[n].items.randitem15 = "lilgun";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	//fake Tower 4C
	Locations[n].id = "Fort_M_tower4C";
	locations[n].id.label = "The upper part of the tower is destroyed";
	Locations[n].filespath.models = "locations\inside\store04";

	//Town sack
//	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Fort_Moultrie_inside";

	//Models
	//Always

	Locations[n].models.always.locators = "store04_locators_GB_tower1B";
	Locations[n].models.always.tavern = "store04";
	Locations[n].models.always.window = "store04_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "store04_patch";

	//Night
	Locations[n].models.night.charactersPatch = "store04_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Fort_M_tower4B";
	Locations[n].reload.l4.emerge = "reload4";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "";

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Fort_M_tower5A";
	locations[n].id.label = "Gate tower stairs";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house\\";
	Locations[n].image = "GB_small_stairs.tga";

	//Town sack
	//Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Fort_Moultrie_inside";
	
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F1_l_GB2";
	Locations[n].models.always.tavern = "LH_F1";
	Locations[n].models.always.window = "LF1_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "LH_F1_p";

	//Night
	Locations[n].models.night.charactersPatch = "LH_F1_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "true";
//	Locations[n].models.back = "back\redlf2_";

	//Reload map
	//up
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Fort_M_tower5B";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	//step back
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Fort_M_tower5A";
	Locations[n].reload.l3.emerge = "reload4";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	//down
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Fort_Moultrie";
	Locations[n].reload.l4.emerge = "box17";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.3;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
//	Locations[n].items.randitem1 = "door_N06";
	Locations[n].items.randitem1 = "door_fort";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "gatedoor_w";
	
/*
	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "gateroof_wood";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "gatedoor_w";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "ladder_big";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "hatch11D";
*/
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Fort_M_tower5B";
	locations[n].id.label = "Gate tower stairs";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house\\";
	Locations[n].image = "GB_small_stairs.tga";

	//Town sack
	//Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Fort_Moultrie_inside";
	
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F1_l_GB2";
	Locations[n].models.always.tavern = "LH_F1";
	Locations[n].models.always.window = "LF1_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "LH_F1_p";

	//Night
	Locations[n].models.night.charactersPatch = "LH_F1_p";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redlf2_";

	//Reload map
	//up
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Fort_M_tower5A";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	//step back
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Fort_M_tower5B";
	Locations[n].reload.l3.emerge = "reload4";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	//down
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Fort_Moultrie";
	Locations[n].reload.l4.emerge = "box18";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.3;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
//	Locations[n].items.randitem1 = "door_N06";
	Locations[n].items.randitem1 = "door_fort";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "gatedoor_w";

/*
	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "gateroof_wood";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "gatedoor_w";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "ladder_big";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "hatch11D";
*/
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Fort_M_tower5C";
	locations[n].id.label = "Gate tower";
	Locations[n].filespath.models = "locations\inside\store03";
	Locations[n].image = "GB_Fort_sergeant.tga";

	//Town sack
//	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Fort_Moultrie_inside";

	//Models
	//Models
	//Always
	Locations[n].models.always.locators = "store03_locators_GB";
	Locations[n].models.always.tavern = "store03";
	Locations[n].models.always.window = "store03_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "store03_patch";

	//Night
	Locations[n].models.night.charactersPatch = "store03_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";		
	Locations[n].models.back = "back\redb_";

	//Reload map
	Locations[n].reload.l5.name = "reload2";
	Locations[n].reload.l5.go = "Fort_Moultrie";
	Locations[n].reload.l5.emerge = "box18";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].locators_radius.goto.goto1 = 0.8;
	Locations[n].locators_radius.goto.goto3 = 1.0;
	Locations[n].locators_radius.goto.bible = 2.0;

	Locations[n].locators_radius.box.box10 = 0.5;
	Locations[n].locators_radius.box.box11 = 0.5;
	Locations[n].locators_radius.box.box12 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "door_N06";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "gatedoor_fto";		//was gatedoor_store4_wall

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "gatedoor_fto";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "gatedoor_fto";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Fort_Moultrie_prison";
	locations[n].id.label = "Fort Moultrie prison";
	Locations[n].filespath.models = "locations\inside\prison";
	Locations[n].filespath.textures = "locations\inside\Prison\fort_moultrie";
	Locations[n].image = "GB_Fort_prison.tga";

	//Town sack
	//Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_jail";
	
	//Models
	//Always
	Locations[n].models.always.prison = "Pri";
	Locations[n].models.always.locators = "Pri_l_GB";
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
	Locations[n].reload.l13.name = "reload13";
	Locations[n].reload.l13.go = "Fort_Moultrie";
	Locations[n].reload.l13.emerge = "reload2";
	Locations[n].reload.l13.autoreload = "1";
	Locations[n].locators_radius.reload.reload13 = 0.7;

	Locations[n].reload.l14.name = "reload14";
	Locations[n].reload.l14.go = "Fort_Moultrie_prison_stairs";
	Locations[n].reload.l14.emerge = "goto3";
	Locations[n].reload.l14.autoreload = "1";
	Locations[n].locators_radius.reload.reload14 = 0.0001;		//0.7 when open

	Locations[n].locators_radius.goto.stop = 0.7;
	Locations[n].locators_radius.box.box1 = 0.001;			//not used
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.box.box6 = 0.5;
	Locations[n].locators_radius.box.box7 = 0.5;
	Locations[n].locators_radius.box.box8 = 0.5;
	Locations[n].locators_radius.box.box9 = 0.5;
	Locations[n].locators_radius.box.box10 = 0.5;
	Locations[n].locators_radius.box.box11 = 0.5;
	Locations[n].locators_radius.box.box12 = 0.5;
	Locations[n].locators_radius.box.box13 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "gatedoor_store4_wall";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "gatedoor_store4_wall";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "door_N06T";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "door_N06T";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Fort_Moultrie_prison_stairs";
	locations[n].id.label = "Prison stairs";
	Locations[n].filespath.models = "locations\inside\store04";
	Locations[n].filespath.textures = "locations\inside\store04\fort_prison";
	Locations[n].image = "GB_prison_stairs.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_jail";

	//Models
	//Always
	Locations[n].models.always.locators = "store04_locators_JRH5";			//JRH5 if store04, JRH2 if store04_stone
	Locations[n].models.always.tavern = "store04";
	Locations[n].models.always.window = "store04_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "store04_patch";

	//Night
	Locations[n].models.night.charactersPatch = "store04_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redmh4_";

	//Reload map
	//up
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Fort_Moultrie_gunpowder";
	Locations[n].reload.l4.emerge = "goto5";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";

	//down
	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "Fort_Moultrie_prison";
	Locations[n].reload.l7.emerge = "goto140";
	Locations[n].reload.l7.autoreload = "1";
	Locations[n].reload.l7.label = "";

	Locations[n].locators_radius.goto.goto3 = 1.0;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "door_A01";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "textile3";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "chest1";

	Locations[n].locators_radius.randitem.randitem5 = 0.1;
	Locations[n].items.randitem5 = "gatedoor_5";

	Locations[n].locators_radius.randitem.randitem6 = 0.1;
	Locations[n].items.randitem6 = "textile3";

	Locations[n].locators_radius.randitem.randitem7 = 0.1;
	Locations[n].items.randitem7 = "chest1";
	
	Locations[n].locators_radius.randitem.randitem8 = 0.1;
	Locations[n].items.randitem8 = "clock";

	Locations[n].locators_radius.randitem.randitem9 = 0.1;
	Locations[n].items.randitem9 = "barrel_big";

	Locations[n].locators_radius.randitem.randitem10 = 0.1;
	Locations[n].items.randitem10 = "bookshelf";

	Locations[n].locators_radius.randitem.randitem11 = 0.1;
	Locations[n].items.randitem11 = "gatedoor_p5";

	Locations[n].locators_radius.randitem.randitem12 = 0.1;
	Locations[n].items.randitem12 = "hatch3";

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "gatedoor_CRY";

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
	Locations[n].items.randitem14 = "gatedoor_stone";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Fort_Moultrie_gunpowder";
	locations[n].id.label = "Gunpowder storage";
	Locations[n].filespath.models = "locations\inside\MediumStore";
	Locations[n].filespath.textures = "locations\inside\MediumStore\fort_gps";
	Locations[n].image = "GB_Fort_GPS.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_cellar";

	//Models
	//Always
	Locations[n].models.always.locators = "MS_l_JRH_gps";
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

	//Reload map
	//armory
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Fort_Moultrie_armory";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Armory";

	//stairs
	Locations[n].reload.l3.name = "reload3_D";
	Locations[n].reload.l3.go = "Fort_Moultrie_prison_stairs";
	Locations[n].reload.l3.emerge = "reload4";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].locators_radius.reload.reload3_D = 0.5;

	Locations[n].locators_radius.reload.reload3_A = 0.5;

	Locations[n].locators_radius.box.box1 = 0.0001;
	Locations[n].locators_radius.box.box2 = 0.0001;
	Locations[n].locators_radius.box.box3 = 0.7;
	Locations[n].locators_radius.box.box4 = 0.9;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	//Locations[n].items.randitem1 = "gatedoor_stone";
	//Locations[n].items.randitem1 = "gatedoor_store4_wall";
	Locations[n].items.randitem1 = "gatedoor_whf";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	//Locations[n].items.randitem2 = "gatedoor_stone";
	//Locations[n].items.randitem2 = "gatedoor_store4_wall";
	Locations[n].items.randitem2 = "gatedoor_whf";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "chest1";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "barrel_big";
	
	Locations[n].locators_radius.randitem.randitem5 = 0.1;
	Locations[n].items.randitem5 = "door_A03";

	Locations[n].locators_radius.randitem.randitem6 = 0.1;
	Locations[n].items.randitem6 = "door_A03R";

	Locations[n].locators_radius.randitem.randitem7 = 0.1;
	Locations[n].items.randitem7 = "barrel2";

	Locations[n].locators_radius.randitem.randitem8 = 0.1;
	Locations[n].items.randitem8 = "barrel2_roll";

	Locations[n].locators_radius.camdetector.camera1 = 5;
	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------
	
	Locations[n].id = "Fort_Moultrie_armory";
	//locations[n].id.label = "Fort Moultrie armory";		//label when opened
	Locations[n].image = "GB_Fort_armory.tga";
	Locations[n].filespath.models = "locations\Inside\LargeStore";
	Locations[n].filespath.textures = "locations\inside\LargeStore\fort_armory";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_cellar";

	//Models
	//Always
	Locations[n].models.always.locators = "LS_l_GB";			//was JRH0
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

	//Reload map
	//door
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Fort_Moultrie_gunpowder";
	Locations[n].reload.l1.emerge = "Reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 0.5;
	
	//stairs
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Fort_Moultrie";
	Locations[n].reload.l2.emerge = "Reload13";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 0.001;

	Locations[n].locators_radius.box.box1 = 1.0;
	Locations[n].locators_radius.box.box3 = 0.7;
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.box.box6 = 0.5;
	Locations[n].locators_radius.box.box7 = 0.5;
	Locations[n].locators_radius.box.box8 = 0.5;
	Locations[n].locators_radius.box.box9 = 0.8;
	Locations[n].locators_radius.goto.goto1 = 2.7;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "chest1";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "sack";

	Locations[n].locators_radius.randitem.randitem5 = 0.1;
	Locations[n].items.randitem5 = "key8";				//invisible

	Locations[n].locators_radius.randitem.randitem6 = 0.1;
	Locations[n].items.randitem6 = "key8";				//invisible

	Locations[n].locators_radius.randitem.randitem7 = 0.1;
	Locations[n].items.randitem7 = "key8";				//invisible

	Locations[n].locators_radius.randitem.randitem10 = 0.1;
	Locations[n].items.randitem10 = "key8";				//invisible

	Locations[n].locators_radius.randitem.randitem14 = 0.1;
	Locations[n].items.randitem14 = "box";

	Locations[n].locators_radius.randitem.randitem15 = 0.1;
	Locations[n].items.randitem15 = "cannonball2";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Fort_Moultrie_barracks_entre";
	locations[n].id.label = "Fort Moultrie barracks";				//when opened
	Locations[n].filespath.models = "locations\inside\Corridor\\";
	Locations[n].filespath.textures = "locations\inside\Corridor\fort";

	Locations[n].image = "GB_Fort_barracks_entre.tga";

	//Sound
//	locations[n].type = "Fort_Moultrie_inside";
//	locations[n].type = "silent_loghouse";
	locations[n].type = "party";
	
	//Models
	//Always
	Locations[n].models.always.locators = "StoreSmall_locators_JRH_normal";	
	Locations[n].models.always.store = "StoreSmall";
//	Locations[n].models.always.l1 = "scroll46";

	//Day
	Locations[n].models.day.charactersPatch = "StoreSmall_patch";

	//Night
	Locations[n].models.night.charactersPatch = "StoreSmall_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l4.name = "reload1";
	Locations[n].reload.l4.go = "Fort_Moultrie";
	Locations[n].reload.l4.emerge = "reload10";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload1 = 0.5;
	
	Locations[n].reload.l5.name = "reload2";
	Locations[n].reload.l5.go = "Fort_Moultrie_barracks";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;		
	
	Locations[n].locators_radius.box.box1 = 0.0001;
	Locations[n].locators_radius.box.box2 = 0.0001;

	Locations[n].locators_radius.randitem.randitem1 = 0.0001;
	Locations[n].items.randitem1 = "gatedoor_fta";

	Locations[n].locators_radius.randitem.randitem2 = 0.0001;
	Locations[n].items.randitem2 = "gatedoor_fta";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "door_largeh";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "door_largeh";

	Locations[n].locators_radius.randitem.randitem5 = 0.0001;
	Locations[n].items.randitem5 = "gatedoor_w_45";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Fort_Moultrie_barracks";
	Locations[n].filespath.models = "locations\inside\smalltavern";
	Locations[n].filespath.textures = "locations\inside\SmallTavern";
	locations[n].id.label = "Fort Moultrie barracks";
	Locations[n].image = "GB_Fort_barracks.tga";

	//Town sack
	//Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "Fort_Moultrie_barracks";
	
	//Models
	//Always
	Locations[n].models.always.locators = "ST_l";
	Locations[n].models.always.tavern = "ST";
	Locations[n].models.always.window = "St_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "ST_p";

	//Night
	Locations[n].models.night.charactersPatch = "ST_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Locations[n].models.back = "back\ffst_";
	Locations[n].models.back = "back\fort_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Fort_Moultrie_barracks_entre";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Fort_Moultrie_barracks";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 0.8;
	Locations[n].reload.l2.disable = 1;			//never opened

	Locations[n].locators_radius.sit.sit13 = 2.0;

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Lieutenant_G_kitchen";
	//locations[n].id.label = "Lieutenant G:s house";
	Locations[n].filespath.models = "locations\inside\DoubleFlour_house";
	Locations[n].image = "Inside_Doubleflour_House_Lower.tga";

	//Town sack
//	Locations[n].townsack = "Douwesen";

	//Sound
	locations[n].type = "Rogers_residence";

	//Models
	//Always
	Locations[n].models.always.locators = "LH_F1_l_GB1";
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
//	Locations[n].models.back = "back\doulf2_";
//	Locations[n].models.back = "..\back\inside_back_";
//	Locations[n].models.back = "back\smumh_";
	Locations[n].models.back = "back\fort_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Fort_Moultrie";
	Locations[n].reload.l1.emerge = "reload5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Lieutenant_G_bedroom";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name#";
	Locations[n].locators_radius.reload.reload2 = 0.8;

	Locations[n].reload.l3.name = "reload3";		
	Locations[n].reload.l3.go = "Lieutenant_G_office";
	Locations[n].reload.l3.emerge = "reload2";		//r2 if sacristy, r1 if wr shop
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].locators_radius.reload.reload3 = 0.8;
	Locations[n].reload.l3.disable = 1;			//opened later

	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_A05";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "door_A05R";

	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\shipyard3";
	Locations[n].id = "Lieutenant_G_office";
	//locations[n].id.label = "Lieutenant G:s office";	//label when opened
	Locations[n].image = "GB_lutG_office.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_residence";
	
	//Models
	//Always
	Locations[n].models.always.locators = "sh03_l_GB_lutG";
	Locations[n].models.always.l1 = "Sh03";
	Locations[n].models.always.l2 = "";				//scales1 later
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
//	Locations[n].models.back = "back\pcha_";
//	Locations[n].models.back = "..\back\inside_back_";
//	Locations[n].models.back = "back\redb_";
	Locations[n].models.back = "back\fort_";

	//Reload map
	Locations[n].reload.l2.name = "reload2";			//if sacristy style
	Locations[n].reload.l2.go = "Lieutenant_G_kitchen";
	Locations[n].reload.l2.emerge = "Reload3";
	Locations[n].reload.l2.label = "";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.9;
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.box.box6 = 0.5;
	Locations[n].locators_radius.goto.goto6 = 1.0;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_A05";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "door_A05R";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "gatedoor_stone";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "carpet3";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;			//not used
	Locations[n].items.randitem5 = "";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;			//not used
	Locations[n].items.randitem6 = "";

	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "clock_big";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Lieutenant_G_bedroom";
	locations[n].id.label = "Lieutenant G:s bedroom";	
	Locations[n].image = "GB_lutG_bedroom.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_residence";

	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Smallhome";
	Locations[n].filespath.textures = "locations\inside\Smallhome\store";

	Locations[n].models.always.city = "sh";
	Locations[n].models.always.locators = "sh_l_GB";
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
//	Locations[n].models.back = "back\redsh_";
//	Locations[n].models.back = "..\back\inside_back_";
//	Locations[n].models.back = "back\smush_";
	Locations[n].models.back = "back\fort_";

	//Reload map
	//stairs tavern storeroom
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Lieutenant_G_kitchen";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "door_largeh2";

	Locations[n].locators_radius.randitem.randitem2 = 0.0001;
	Locations[n].items.randitem2 = "fur1";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "Bugillustration";

	Locations[n].locators_radius.box.box1 = 1.0;
	Locations[n].locators_radius.box.box2 = 1.0;
	Locations[n].locators_radius.box.box3 = 0.7;

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Fort_Moultrie_shore";
	locations[n].id.label = "Fort Moultrie shore";
	Locations[n].image = "GB_Moultrie_shore.tga";
	//Sound
	locations[n].type = "silent_seashore";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Outside\Shore_1";
	Locations[n].models.always.townWalls = "fort_walls_stucco_3";
	Locations[n].models.always.locators = "Shore01_l_GB1";		//start = GB1, later GB2
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
//	Locations[n].models.always.l3 = "plan_3";
//	Locations[n].models.always.l3.level = 7;
//	Locations[n].models.always.l3.tech = "LocationModelBlend";

	//Day
	Locations[n].models.day.charactersPatch = "Shore01_p";
	//Night
	Locations[n].models.night.charactersPatch = "Shore01_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.6;

	//Reload map
	Locations[n].reload.l1.name = "locator3";
	Locations[n].reload.l1.go = "Fort_Moultrie_exit";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.locator3 = 2.0;

	Locations[n].reload.l2.name = "locator3_back";
	Locations[n].reload.l2.go = "Fort_Moultrie_exit";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.locator3_back = 1.0;
/*
	Locations[n].reload.l3.name = "boat";
	
	if (VISIT_DECK == 1)
		Locations[n].reload.l3.label = "Ship.";
	else
		Locations[n].reload.l3.label = "Sea.";

	Locations[n].reload.l3.go = "GB_Charleston_port";
	Locations[n].reload.l3.emerge = "box1";
	Locations[n].reload.l3.autoreload = "0";
//	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.boat = 0.5;
*/

	Locations[n].locators_radius.reload.box3 = 0.5;

	Locations[n].locators_radius.goto.pier1 = 0.8;
	Locations[n].locators_radius.goto.pier3 = 0.8;
	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "wood_pier";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "ladder_hold";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "swamp_island2";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "qcport_plan3";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "qcport_plan3";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;		//low, left
	Locations[n].items.randitem6 = "qcport_plan3";

	Locations[n].locators_radius.randitem.randitem7 = 0.01;		//low, right
	Locations[n].items.randitem7 = "qcport_plan3";

	Build_at("Fort_Moultrie_shore", "church", "", -138.0, 10.0, 395.0, 2.5, "");	//dir2 not so bad, y was 10

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------
	
	Locations[n].id = "GB_Charleston_port";
	locations[n].id.label = "Charleston port";
	Locations[n].filespath.models = "locations\QuestTown_Charleston\Port";
	Locations[n].image = "GB_Charleston_port.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
//	locations[n].type = "port";
//	locations[n].type = "silent_seashore";				//temp
	locations[n].type = "Charleston_port";
	
	//Models
	//Always
	Locations[n].models.always.l1 = "1018002";
	Locations[n].models.always.l1.foam = "1";
	//Locations[n].models.always.l2 = "smallmodel";
	Locations[n].models.always.l3 = "tree";

	Locations[n].models.always.locators = "locator_port";
//	Locations[n].models.always.grassPatch = "Redport_g";
//    	Locations[n].models.always.seabed = "RedPort_sb";
//	Locations[n].models.always.seabed.foam = "1";

	Locations[n].models.always.l6 = "port_doors";

	//Day
	Locations[n].models.day.charactersPatch = "walk_patch";
	Locations[n].models.day.l4 = "day_windows";
	Locations[n].models.day.fonar = "smallmodel";

	//Night
	Locations[n].models.night.charactersPatch = "walk_patch";
//	Locations[n].models.night.fonar = "night_deng";					//???
	Locations[n].models.night.l5 = "night_windows";	
	Locations[n].models.night.fonar = "night_smallmodel";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.6;
	//Reload map

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "GB_Charleston_port_tavern";
	Locations[n].reload.l1.emerge = "reload1";	
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "GB_Charleston_town";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "GB_Charleston_shipyard";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "GB_Charleston_harbour_master_stairs_in";
	Locations[n].reload.l4.emerge = "goto1";
	Locations[n].reload.l4.autoreload = "0";

	Locations[n].locators_radius.reload.box9 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "jungle";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "stonewall45";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "jungle";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "jungle";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "wood_pier";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "wood_pier";

	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "boat2_C";

	Locations[n].locators_radius.randitem.randitem8 = 0.01;
	Locations[n].items.randitem8 = "boat2_B";

	Locations[n].locators_radius.randitem.randitem9 = 0.01;
	Locations[n].items.randitem9 = "boat4";

	Locations[n].locators_radius.randitem.randitem10 = 0.01;
	Locations[n].items.randitem10 = "swamp_island1";

	Locations[n].locators_radius.randitem.randitem11 = 0.01;
	Locations[n].items.randitem11 = "swamp_island1";

	Locations[n].locators_radius.randitem.randitem12 = 0.01;
	Locations[n].items.randitem12 = "swamp_island1";

	Locations[n].locators_radius.randitem.randitem13 = 0.01;
	Locations[n].items.randitem13 = "gatefloor_w45";

	Build_at("GB_Charleston_port", "Field_Cannon_1", "", 26.0, 21, -97.9, 2, "");
	Build_at("GB_Charleston_port", "Field_Cannon_1", "", 42.2, 21, -115.1, 2, "");
	Build_at("GB_Charleston_port", "Field_Cannon_1", "", 33.4, 21, -106.1, 2, "");

	Build_at("GB_Charleston_port", "gallows", "", 61.7, 7.2, -54.9, 2.3, "");
	Build_at("GB_Charleston_port", "townwalls", "", 98.0, 4.0, 511.0, 1.0, "");

	Locations[n].locators_radius.box.box1 = 0.7;
	Locations[n].locators_radius.goto.steam = 35.0;
	Locations[n].locators_radius.goto.steam_off = 10.0;
	Locations[n].locators_radius.box.box13 = 0.2;
	Locations[n].locators_radius.box.box14 = 0.2;

	LAi_LocationFantomsGen(&locations[n], false);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "GB_Charleston_port_tavern";
//	locations[n].id.label = "Charleston port tavern";
	locations[n].id.label = "The Maelstrom";
	Locations[n].image = "Inside_MediumTavern.tga";

	//Town sack
	Locations[n].townsack = "Eleuthera";

	//Sound
	locations[n].type = "tavern";	//music alarm in sound.c

	//Models
	//Always
	Locations[n].filespath.models = "locations\Inside\MediumTavern";
	Locations[n].models.always.locators = "MT_l";
	Locations[n].models.always.l1 = "MT";
	Locations[n].models.always.window = "MT_w_closed";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "MT_p";

	//Night
	Locations[n].models.night.charactersPatch = "MT_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Locations[n].models.back = "back\qcsh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "GB_Charleston_port";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Quebradas Costillas store.";

	//up
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "GB_Charleston_port_tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Quebradas Costillas.";
	Locations[n].reload.l2.disable = 1;
	
	//stairs to balcony
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "GB_Charleston_port_tavern_stairs";
	Locations[n].reload.l3.emerge = "goto4";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Quebradas Costillas.";
  
	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Eleuthera";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "GB_Charleston_port_tavern_stairs";
	locations[n].id.label = "";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house\\";
	Locations[n].filespath.textures = "locations\inside\Doubleflour_house\church_attic";
	Locations[n].image = "GB_small_stairs.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_private";
	
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F1_l_GB_Dupin";	//later LH_F1_l_GB_Dupin
	Locations[n].models.always.tavern = "LH_F1";
	Locations[n].models.always.window = "LF1_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "LH_F1_p";

	//Night
	Locations[n].models.night.charactersPatch = "LH_F1_p";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redlf2_";

	//Reload map
	//balcony
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "GB_Charleston_port";
	Locations[n].reload.l2.emerge = "box13";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	//tavern
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "GB_Charleston_port_tavern_stairs";
	Locations[n].reload.l3.emerge = "reload4";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "GB_Charleston_port_tavern";
	Locations[n].reload.l4.emerge = "reload3";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.3;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_N09";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.01;
//	Locations[n].items.randitem2 = "gatedoor_w";
	Locations[n].items.randitem2 = "gatedoor_attic_brick";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "door_N09";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "gatedoor_attic_brick";

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "GB_Charleston_port_tavern_upstairs";
	locations[n].id.label = "Room in the Maelstrom";
	Locations[n].image = "Inside_Doubleflour_House_Room.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_neutral";
	locations[n].fastreload = "Redmond";
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
	Locations[n].reload.l1.go = "GB_Charleston_port_tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Tavern.";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "GB_Charleston_shipyard";
	locations[n].id.label = "Charleston shipyard";
	locations[n].image = "Inside_Shipyard5.tga";
	Locations[n].filespath.models = "locations\inside\shipyard5\\";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	//locations[n].type = "house";
	//locations[n].type = "Rogers_study";
	locations[n].type = "shop";

	//Models
	//Always
	Locations[n].models.always.city = "sh05";
	Locations[n].models.always.locators = "sh05_locators_GB";
	Locations[n].models.always.window = "sh05_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "sh05_patch";
	//Night
	Locations[n].models.night.charactersPatch = "sh05_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Locations[n].models.back = "back\mures2_";
	Locations[n].models.back = "back\redb_";

	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "GB_Charleston_port";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "GB_Charleston_port";
	Locations[n].reload.l2.emerge = "reload4";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.disable = 1;

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Dungeon_1_wood";
	Locations[n].id = "GB_Charleston_harbour_master_stairs_in";
	locations[n].id.label = "To the Harbour Master";
	Locations[n].image = "GB_big_stairs.tga";
	
	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "silent_loghouse";

	//Models
	//Always
	Locations[n].models.always.locators = "d01_l_GB2";
	Locations[n].models.always.house = "d01";
	//Day
	Locations[n].models.day.charactersPatch = "d01_p";
	//Night
	Locations[n].models.night.charactersPatch = "d01_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "GB_Charleston_harbour_master";
	Locations[n].reload.l1.emerge = "locator2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Redmond shipyard.";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "GB_Charleston_port";
	Locations[n].reload.l3.emerge = "reload4";
	Locations[n].reload.l3.autoreload = "1";				
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "gatedoor_small";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
//	Locations[n].items.randitem3 = "gatedoor_small";		//test off
	Locations[n].items.randitem3 = "door_largeh2";

	Locations[n].locators_radius.randitem.randitem8 = 0.1;
	Locations[n].items.randitem8 = "gatedoor_w";

	Locations[n].island = "Redmond";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Dungeon_1_wood";
	Locations[n].id = "GB_Charleston_harbour_master_stairs_out";
	locations[n].id.label = "Exit";
	Locations[n].image = "GB_big_stairs.tga";
	
	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "silent_loghouse";

	//Models
	//Always
	Locations[n].models.always.locators = "d01_l_GB";
	Locations[n].models.always.house = "d01";
	//Day
	Locations[n].models.day.charactersPatch = "d01_p";
	//Night
	Locations[n].models.night.charactersPatch = "d01_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "GB_Charleston_harbour_master";
	Locations[n].reload.l1.emerge = "locator2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Redmond shipyard.";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "GB_Charleston_port";
	Locations[n].reload.l3.emerge = "reload4";
	Locations[n].reload.l3.autoreload = "1";				
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "gatedoor_small";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
//	Locations[n].items.randitem3 = "gatedoor_small";		//test off
	Locations[n].items.randitem3 = "door_largeh2";

	Locations[n].locators_radius.randitem.randitem8 = 0.1;
	Locations[n].items.randitem8 = "gatedoor_w";

	Locations[n].island = "Redmond";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\inside\shipyard2";
	Locations[n].id = "GB_Charleston_harbour_master";
	locations[n].id.label = "Charleston Harbour Master";
	Locations[n].image = "GB_harbour_master.tga";

	//Town sack
	Locations[n].townsack = "Quebradas Costillas"; // NK - "Oxbay";

	//Sound
	locations[n].type = "";//was "shop"

	//Models
	//Always
	//THIS PART IS FOR THE Falaise de Fleur STYLE SHIPYARD(FANCY)
	//Locations[n].models.always.locators = "sh02_l";
	Locations[n].models.always.locators = "sh02_l_before_roof";
	Locations[n].models.always.tavern = "sh02";
	Locations[n].models.always.window = "sh02_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	//THIS PART IS FOR THE Falaise de Fleur STYLE SHIPYARD(FANCY)
	Locations[n].models.day.charactersPatch = "sh02_p";

	//Night
	//THIS PART IS FOR THE Falaise de Fleur STYLE SHIPYARD(FANCY)
	Locations[n].models.night.charactersPatch = "sh02_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\qcsh_";

	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "GB_Charleston_harbour_master_stairs_out";
	Locations[n].reload.l1.emerge = "Reload1";
	Locations[n].reload.l1.autoreload = "0";
	
	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "GB_Charleston_town";
	locations[n].id.label = "Charleston";
	Locations[n].filespath.models = "locations\QuestTown_Charleston\Town";
	Locations[n].image = "GB_Charleston_town.tga";

	//Town sack
	Locations[n].townsack = "Charleston";

	//Sound
	locations[n].type = "Charleston_town";
	
	//Models
	//Always
	Locations[n].models.always.l1 = "1018001";
	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.l3 = "tree";
	Locations[n].models.always.l4 = "buyuan";
	Locations[n].models.always.townWalls = "fort_walls_stucco_4";
	
	Locations[n].models.always.river = "heshui";
	Locations[n].models.always.river.level = 999;				
	Locations[n].models.always.river.uvslide.v0 = -0.1;
	Locations[n].models.always.river.uvslide.v1 = 0.15;
	Locations[n].models.always.river.tech = "LocationWaterFall";

	Locations[n].models.always.l5 = "water1";
	Locations[n].models.always.l5.uvslide.u0 = -0.0005;
	Locations[n].models.always.l5.uvslide.v0 = -0.2;
	Locations[n].models.always.l5.level = 999;
	Locations[n].models.always.l5.tech = "LocationWaterFall";

	Locations[n].models.always.l6 = "water02";			//flat circle
	Locations[n].models.always.l6.uvslide.u0 = 0.04;
	Locations[n].models.always.l6.uvslide.v0 = 0.01;
	Locations[n].models.always.l6.level = 999;
	Locations[n].models.always.l6.tech = "LocationWaterFall";

	Locations[n].models.always.l7 = "water03";			//flat circle
	Locations[n].models.always.l7.uvslide.u0 = 0.04;
	Locations[n].models.always.l7.uvslide.v0 = 0.01;
	Locations[n].models.always.l7.level = 999;
	Locations[n].models.always.l7.tech = "LocationWaterFall";

	Locations[n].models.always.l10 = "chinese_gate";
	Locations[n].models.always.l11 = "town_doors";

	//Day
	Locations[n].models.day.charactersPatch = "walk_patch";
	Locations[n].models.day.l8 = "day_windows";
	Locations[n].models.day.fonar = "smallmodel";
	Locations[n].models.day.locators = "locator_town";
	
	//Night
	Locations[n].models.night.charactersPatch = "walk_patch";					
	Locations[n].models.night.l9 = "night_windows";	
	Locations[n].models.night.fonar = "night_smallmodel";
	Locations[n].models.night.locators = "locator_town_night";
					
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.box.box6 = 0.4;
	Locations[n].locators_radius.box.box7 = 0.2;
	Locations[n].locators_radius.box.box8 = 0.2;
	Locations[n].locators_radius.box.box9 = 0.2;
	Locations[n].locators_radius.box.box10 = 0.2;
	Locations[n].locators_radius.box.box11 = 0.2;
	Locations[n].locators_radius.box.box12 = 0.2;
	Locations[n].locators_radius.box.box13 = 0.2;
	Locations[n].locators_radius.box.box14 = 0.2;
	Locations[n].locators_radius.box.box15 = 0.2;
	Locations[n].locators_radius.box.box16 = 0.2;

	Locations[n].locators_radius.box.box25 = 0.5;
	Locations[n].locators_radius.box.box26 = 0.5;
	Locations[n].locators_radius.box.box27 = 0.5;
	Locations[n].locators_radius.box.box28 = 0.5;

	Locations[n].locators_radius.box.box39 = 0.5;
	Locations[n].locators_radius.box.box54 = 0.5;
	Locations[n].locators_radius.box.box55 = 0.3;
	Locations[n].locators_radius.box.box60 = 0.5;
	Locations[n].locators_radius.box.box62 = 0.5;
	Locations[n].locators_radius.box.box64 = 0.5;

	Locations[n].locators_radius.box.box24 = 0.0001;		//1.0 when tour2 is opened
	Locations[n].locators_radius.box.box53 = 0.0001;		//1.0 when tour3 is opened

	Locations[n].locators_radius.reload.check1 = 0.5;
	Locations[n].locators_radius.reload.check2 = 0.5;
	Locations[n].locators_radius.goto.church = 20.0;
	Locations[n].locators_radius.goto.church2 = 24.0;
	Locations[n].locators_radius.sit.fersen = 2.0;
	Locations[n].locators_radius.goto.brothel_key = 2.0;
	Locations[n].locators_radius.goto.where_to = 2.0;
	Locations[n].locators_radius.goto.priest = 2.0;
	Locations[n].locators_radius.goto.box53 = 2.5;

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "GB_Charleston_port";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
//	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Bessop_plantation";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
//	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 0.7;
	Locations[n].reload.l2.disable = 1;			//opened after cipher is solved

	Locations[n].reload.l3.name = "Reload3";
	Locations[n].reload.l3.go = "Dupin_stairs_up";
	Locations[n].reload.l3.emerge = "goto4";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Jungle";
	Locations[n].reload.l3.disable = 1;			//opened after Poe visit

	Locations[n].reload.l4.name = "Reload4";
	Locations[n].reload.l4.go = "GB_Charleston_warehouse_stairs";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Jungle";

	Locations[n].reload.l5.name = "Reload5";
	Locations[n].reload.l5.go = "GB_Chinatown";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Chinatown";
	Locations[n].locators_radius.reload.reload5 = 0.7;
	Locations[n].reload.l5.disable = 1;			//opened after 1:st visit to plantation

	Locations[n].reload.l7.name = "Reload7";
	Locations[n].reload.l7.go = "GB_Charleston_townhall";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Residence";

	Locations[n].reload.l8.name = "Reload8";
	Locations[n].reload.l8.go = "GB_Charleston_store";
	Locations[n].reload.l8.emerge = "reload1";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "Residence";

	Locations[n].reload.l9.name = "Reload9";
	Locations[n].reload.l9.go = "GB_Charleston_blacksmith";
	Locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "Residence";

	Locations[n].reload.l10.name = "Reload10";
	Locations[n].reload.l10.go = "GB_Charleston_high_house_entre";
	Locations[n].reload.l10.emerge = "goto3";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "Residence";
	Locations[n].locators_radius.reload.reload10 = 0.2;

	Locations[n].reload.l11.name = "Reload11";
	Locations[n].reload.l11.go = "GB_Charleston_usurerhouse";
	Locations[n].reload.l11.emerge = "reload1";
	Locations[n].reload.l11.autoreload = "0";
	Locations[n].reload.l11.label = "Post Office";

	Locations[n].reload.l12.name = "Reload12";
	Locations[n].reload.l12.go = "Pym_drawing_room";
	Locations[n].reload.l12.emerge = "box3";
	Locations[n].reload.l12.autoreload = "0";
	Locations[n].locators_radius.reload.reload12 = 0.2;

	Locations[n].reload.l13.name = "Reload13";
	Locations[n].reload.l13.go = "GB_Charleston_tailorsShop";
	Locations[n].reload.l13.emerge = "locator2";
	Locations[n].reload.l13.autoreload = "0";
	Locations[n].reload.l13.disable = 1;			//locked from inside

	Locations[n].reload.l14.name = "reload14";
	Locations[n].reload.l14.go = "Pym_drawing_room";
	Locations[n].reload.l14.emerge = "reload1";
	Locations[n].reload.l14.autoreload = "0";
	Locations[n].locators_radius.reload.reload14 = 0.3;
	
	Locations[n].reload.l15.name = "Reload15";
	Locations[n].reload.l15.go = "GB_Charleston_tailorsShop";
	Locations[n].reload.l15.emerge = "locator1";
	Locations[n].reload.l15.autoreload = "0";
	Locations[n].locators_radius.reload.reload15 = 0.3;

	Locations[n].reload.l16.name = "reload16";
	Locations[n].reload.l16.go = "GB_Charleston_town_tavern";
	Locations[n].reload.l16.emerge = "reload2";
	Locations[n].reload.l16.autoreload = "0";
	Locations[n].reload.l16.label = "Brothel.";

	Locations[n].reload.l17.name = "reload17";
	Locations[n].reload.l17.go = "Dupin_private";
	Locations[n].reload.l17.emerge = "box2";			//was reload1
	Locations[n].reload.l17.autoreload = "0";

	Locations[n].reload.l18.name = "reload18";
	Locations[n].reload.l18.go = "GB_Charleston_riverhouse_stairs";
	Locations[n].reload.l18.emerge = "goto4";
	Locations[n].reload.l18.autoreload = "0";
	Locations[n].locators_radius.reload.reload18 = 0.5;

	Locations[n].reload.l19.name = "reload19";
	Locations[n].reload.l19.go = "GB_Charleston_brothel1_stairs_in";
	Locations[n].reload.l19.emerge = "goto4";
	Locations[n].reload.l19.autoreload = "0";
	Locations[n].reload.l19.label = "Brothel.";
	Locations[n].locators_radius.reload.reload19 = 0.2;

	Locations[n].reload.l20.name = "reload20";
	Locations[n].reload.l20.go = "GB_Charleston_town";
	Locations[n].reload.l20.emerge = "reload21";
	Locations[n].reload.l20.autoreload = "0";
	Locations[n].locators_radius.reload.reload20 = 1.0;

	Locations[n].reload.l21.name = "reload21";
	Locations[n].reload.l21.go = "GB_Charleston_town";
	Locations[n].reload.l21.emerge = "reload20";
	Locations[n].reload.l21.autoreload = "0";
	Locations[n].locators_radius.reload.reload21 = 1.0;

	Locations[n].reload.l22.name = "reload22";
	Locations[n].reload.l22.go = "GB_Charleston_church_office";
	Locations[n].reload.l22.emerge = "reload1";
	Locations[n].reload.l22.autoreload = "0";
	Locations[n].locators_radius.reload.reload22 = 1.0;

	Locations[n].reload.l23.name = "reload23";
	Locations[n].reload.l23.go = "GB_Charleston_opium";
	Locations[n].reload.l23.emerge = "reload1";
	Locations[n].reload.l23.autoreload = "0";
	Locations[n].locators_radius.reload.reload23 = 0.5;

	Locations[n].reload.l24.name = "reload24";
	Locations[n].reload.l24.go = "GB_Charleston_brothel1";
	Locations[n].reload.l24.emerge = "reload2_back";
	Locations[n].reload.l24.autoreload = "0";
	Locations[n].locators_radius.reload.reload24 = 0.3;

	Locations[n].reload.l30.name = "penthouse";
	Locations[n].reload.l30.go = "GB_Charleston_penthouse";
	Locations[n].reload.l30.emerge = "reload2";
	Locations[n].reload.l30.autoreload = "0";
	Locations[n].locators_radius.reload.penthouse = 1.0;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "palm2";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "palm2";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "derrick_45";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "derrick_45";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "derrick_45";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "counter";

	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "derrick_45";

	Locations[n].locators_radius.randitem.randitem8 = 0.01;
	Locations[n].items.randitem8 = "market_V_X1";

	Locations[n].locators_radius.randitem.randitem9 = 0.01;
	Locations[n].items.randitem9 = "horse_fence";

	Locations[n].locators_radius.randitem.randitem10 = 0.01;
	Locations[n].items.randitem10 = "chair";

	Locations[n].locators_radius.randitem.randitem11 = 0.01;
	Locations[n].items.randitem11 = "textileB_45";

	Locations[n].locators_radius.randitem.randitem12 = 0.01;
	Locations[n].items.randitem12 = "palm2";

	Locations[n].locators_radius.randitem.randitem13 = 0.01;
	Locations[n].items.randitem13 = "book49";

	Locations[n].locators_radius.randitem.randitem14 = 0.01;
	Locations[n].items.randitem14 = "door_sklad45";

	Locations[n].locators_radius.randitem.randitem15 = 0.01;
	Locations[n].items.randitem15 = "door_sklad45";

	Locations[n].locators_radius.randitem.randitem16 = 0.01;
	Locations[n].items.randitem16 = "plank2_very_long";

	Locations[n].locators_radius.randitem.randitem17 = 0.01;
	Locations[n].items.randitem17 = "horse_fence";

	Locations[n].locators_radius.randitem.randitem18 = 0.01;
	Locations[n].items.randitem18 = "hatch11V";

	Locations[n].locators_radius.randitem.randitem19 = 0.01;
	Locations[n].items.randitem19 = "wheelbarrow";

	Locations[n].locators_radius.randitem.randitem20 = 0.01;
	Locations[n].items.randitem20 = "barrel3";

	Locations[n].locators_radius.randitem.randitem21 = 0.01;
	Locations[n].items.randitem21 = "loghouse";

	Locations[n].locators_radius.randitem.randitem22 = 0.01;
	Locations[n].items.randitem22 = "barrel3";

	Locations[n].locators_radius.randitem.randitem23 = 0.01;
	Locations[n].items.randitem23 = "wheelbarrow";

	Locations[n].locators_radius.randitem.randitem24 = 0.01;
	Locations[n].items.randitem24 = "wood_pier";

	Locations[n].locators_radius.randitem.randitem25 = 0.01;
	Locations[n].items.randitem25 = "ladder_big";

	Locations[n].locators_radius.randitem.randitem26 = 0.01;
	Locations[n].items.randitem26 = "doubledoor_45";

	Locations[n].locators_radius.randitem.randitem27 = 0.01;
	Locations[n].items.randitem27 = "door_N06_45";

	Locations[n].locators_radius.randitem.randitem28 = 0.01;
	Locations[n].items.randitem28 = "door_H1_45";

	Locations[n].locators_radius.randitem.randitem29 = 0.01;
	Locations[n].items.randitem29 = "door_N_45";

	Locations[n].locators_radius.randitem.randitem30 = 0.01;
	Locations[n].items.randitem30 = "plank2_very_long";

	Locations[n].locators_radius.randitem.randitem31 = 0.01;
	Locations[n].items.randitem31 = "door_H1_45";

	Locations[n].locators_radius.randitem.randitem32 = 0.01;
	Locations[n].items.randitem32 = "ladder_very_big";

	Locations[n].locators_radius.randitem.randitem33 = 0.001;
	Locations[n].items.randitem33 = "horse_fence";

	Locations[n].locators_radius.randitem.randitem34 = 0.001;
	Locations[n].items.randitem34 = "horse_fence";

	Locations[n].locators_radius.randitem.randitem35 = 0.001;
	Locations[n].items.randitem35 = "horse_fence";

	Locations[n].locators_radius.randitem.randitem36 = 0.01;
	Locations[n].items.randitem36 = "barrel3";

	Locations[n].locators_radius.randitem.randitem37 = 0.01;
	Locations[n].items.randitem37 = "palm3";

	Locations[n].locators_radius.randitem.randitem38 = 0.01;
	Locations[n].items.randitem38 = "palm2";

	Locations[n].locators_radius.randitem.randitem39 = 0.01;
	Locations[n].items.randitem39 = "palm2";

	Locations[n].locators_radius.randitem.randitem40 = 0.01;
	Locations[n].items.randitem40 = "palm2";

	Locations[n].locators_radius.randitem.randitem41 = 0.01;
	Locations[n].items.randitem41 = "palm3";

	Locations[n].locators_radius.randitem.randitem42 = 0.01;
	Locations[n].items.randitem42 = "small_roof";

	Locations[n].locators_radius.randitem.randitem43 = 0.01;
	Locations[n].items.randitem43 = "barrel3";

	Locations[n].locators_radius.randitem.randitem44 = 0.01;
	Locations[n].items.randitem44 = "market_C4";

	Locations[n].locators_radius.randitem.randitem45 = 0.01;
	Locations[n].items.randitem45 = "palm2";

	Locations[n].locators_radius.randitem.randitem46 = 0.01;
	Locations[n].items.randitem46 = "market_P2";

	Locations[n].locators_radius.randitem.randitem47 = 0.01;
	Locations[n].items.randitem47 = "market_P1";

	Locations[n].locators_radius.randitem.randitem48 = 0.01;
	Locations[n].items.randitem48 = "palm2";

	Locations[n].locators_radius.randitem.randitem49 = 0.01;
	Locations[n].items.randitem49 = "market_C1+1";

	Locations[n].locators_radius.randitem.randitem50 = 0.01;
	Locations[n].items.randitem50 = "palm2";

	Locations[n].locators_radius.randitem.randitem51 = 0.01;
//	Locations[n].items.randitem51 = "chinese_gate";			//not used

	Locations[n].locators_radius.randitem.randitem52 = 0.01;
//	Locations[n].items.randitem52 = "market_V_L4";			//not used

	Locations[n].locators_radius.randitem.randitem53 = 0.01;
	Locations[n].items.randitem53 = "textileB";

	Locations[n].locators_radius.randitem.randitem54 = 0.01;
	Locations[n].items.randitem54 = "market_P1";

	Locations[n].locators_radius.randitem.randitem55 = 0.01;
	Locations[n].items.randitem55 = "1_lanternF_night";

	Locations[n].locators_radius.randitem.randitem56 = 0.01;
	Locations[n].items.randitem56 = "1_lanternF_night";

	Locations[n].locators_radius.randitem.randitem57 = 0.01;
	Locations[n].items.randitem57 = "1_lanternF_day";

	Locations[n].locators_radius.randitem.randitem58 = 0.01;
	Locations[n].items.randitem58 = "1_lanternF_day";

	Build_at("GB_Charleston_town", "jungle2", "", 20.3, 6.5, -49.3, 1, "");	//was forest
	Build_at("GB_Charleston_town", "jungle2", "", 2.0, 6.5, -52.6, 1, "");	//was forest
	Build_at("GB_Charleston_town", "jungle2", "", -11.6, 6.5, -40.5, 1, "");
	Build_at("GB_Charleston_town", "workshop", "", 50.4, 4.2, 33.3, 1, "");
	Build_at("GB_Charleston_town", "workshop", "", 53.7, 4.2, 29.8, 1, "");

	Build_at("GB_Charleston_town", "boxes", "", 54.1, 4.3, 26.0, 0.95, "");
	Build_at("GB_Charleston_town", "box", "distillery", 57.3, 4.2, 25.1, 0.95, "");

	LAi_LocationFantomsGen(&locations[n], false);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "GB_Chinatown";
	locations[n].id.label = "Chinatown";
	Locations[n].filespath.models = "locations\outside\Chinatown\\";
//	Locations[n].filespath.textures = "locations\outside\Chinatown";
	Locations[n].image = "GB_Chinatown.tga";

	//Town sack
	//Locations[n].townsack = "Redmond";

	//Sound
	//locations[n].type = "Chinatown";
	//locations[n].type = "silent_jungle";
	locations[n].type = "Chinese_garden";
	
	//Models
	//Always
//	Locations[n].models.always.locators = "Chinatown_locator";
	Locations[n].models.always.l1 = "1054007";
	//Locations[n].models.always.l2 = "nc";
	Locations[n].models.always.l3 = "tree";
	
	//Day
	Locations[n].models.day.charactersPatch = "walk_patch";
	Locations[n].models.day.fonar = "nc";
	Locations[n].models.day.locators = "Chinatown_locator";

	//Night
	Locations[n].models.night.charactersPatch = "walk_patch";
	Locations[n].models.night.fonar = "night_nc";
	Locations[n].models.night.locators = "Chinatown_locator_night";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "GB_Charleston_town";
	Locations[n].reload.l1.emerge = "reload5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "GB_Chinese_restaurant";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "GB_Chinese_restaurant";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "";

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "GB_Chinese_restaurant";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "GB_Chinese_restaurant";
	Locations[n].reload.l5.emerge = "reload3";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "";

	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "GB_Chinese_restaurant";
	Locations[n].reload.l6.emerge = "reload3";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "";
/*
	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "GB_Chinatown_rooms";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "";
*/
	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "GB_Chinese_nitre";
	Locations[n].reload.l7.emerge = "box6";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "";
	Locations[n].locators_radius.reload.reload7 = 0.0001;		//0.5 when opened

	Locations[n].reload.l8.name = "reload8";
	Locations[n].reload.l8.go = "GB_sulphur_corridor";
	Locations[n].reload.l8.emerge = "reload1";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "";
	Locations[n].reload.l8.disable = 1;				//locked from start

	Locations[n].reload.l9.name = "reload9";
	Locations[n].reload.l9.go = "GB_chinese_gunpowder";
	Locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "";
	Locations[n].locators_radius.reload.reload9 = 0.0001;

	Locations[n].reload.l10.name = "reload10";
	Locations[n].reload.l10.go = "GB_charcoal_stairs";
	Locations[n].reload.l10.emerge = "box2";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "";
	Locations[n].locators_radius.reload.reload10 = 0.0001;		//0.5 when opened

	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.box.box6 = 0.5;
	Locations[n].locators_radius.goto.chinese = 1.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "tree1";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "door_largeh_dark";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "hut3_C";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "well";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "hut3_C";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "door_largeh";

	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "door_largeh";

	Locations[n].locators_radius.randitem.randitem8 = 0.01;
	Locations[n].items.randitem8 = "stonebox";

	Locations[n].locators_radius.randitem.randitem9 = 0.01;
	Locations[n].items.randitem9 = "door_sklad";

	Locations[n].locators_radius.randitem.randitem10 = 0.01;
	Locations[n].items.randitem10 = "door_largeh2";

	Locations[n].locators_radius.randitem.randitem11 = 0.01;
	Locations[n].items.randitem11 = "stonebox";

	Locations[n].locators_radius.randitem.randitem12 = 0.01;
	Locations[n].items.randitem12 = "roof_top";

	Locations[n].locators_radius.randitem.randitem13 = 0.01;
	Locations[n].items.randitem13 = "tree2";

	Locations[n].locators_radius.randitem.randitem14 = 0.01;
	Locations[n].items.randitem14 = "tree_barrel";

	Locations[n].locators_radius.randitem.randitem15 = 0.01;
	Locations[n].items.randitem15 = "tree2";

	Locations[n].locators_radius.randitem.randitem16 = 0.01;
	Locations[n].items.randitem16 = "tree_barrel";

	Locations[n].locators_radius.randitem.randitem17 = 0.01;
	Locations[n].items.randitem17 = "tree2";

	Locations[n].locators_radius.randitem.randitem18 = 0.01;
	Locations[n].items.randitem18 = "tree_barrel";

	Locations[n].locators_radius.randitem.randitem19 = 0.01;
	Locations[n].items.randitem19 = "tree2";

	Locations[n].locators_radius.randitem.randitem20 = 0.01;
	Locations[n].items.randitem20 = "tree_barrel";

	Locations[n].locators_radius.randitem.randitem21 = 0.01;
	Locations[n].items.randitem21 = "tree2";

	Locations[n].locators_radius.randitem.randitem22 = 0.01;
	Locations[n].items.randitem22 = "tree_barrel";

	Locations[n].locators_radius.randitem.randitem23 = 0.01;
	Locations[n].items.randitem23 = "tree2";

	Locations[n].locators_radius.randitem.randitem24 = 0.01;
	Locations[n].items.randitem24 = "tree_barrel";

	Locations[n].locators_radius.randitem.randitem25 = 0.01;
	Locations[n].items.randitem25 = "tree2";

	Locations[n].locators_radius.randitem.randitem26 = 0.01;
	Locations[n].items.randitem26 = "tree_barrel";

	Locations[n].locators_radius.randitem.randitem27 = 0.01;
	Locations[n].items.randitem27 = "tree2";

	Locations[n].locators_radius.randitem.randitem28 = 0.01;
	Locations[n].items.randitem28 = "tree_barrel";

	Locations[n].locators_radius.randitem.randitem29 = 0.01;
	Locations[n].items.randitem29 = "stonebox";

	Locations[n].locators_radius.randitem.randitem30 = 0.01;
	Locations[n].items.randitem30 = "stonebox";

	Locations[n].locators_radius.randitem.randitem31 = 0.01;
	Locations[n].items.randitem31 = "stonebox";

	Locations[n].locators_radius.randitem.randitem32 = 0.01;
	Locations[n].items.randitem32 = "stonebox";

	Locations[n].locators_radius.randitem.randitem33 = 0.01;
	Locations[n].items.randitem33 = "1_lanternF_night";

	Locations[n].locators_radius.randitem.randitem34 = 0.01;
	Locations[n].items.randitem34 = "1_lanternF_night";

	Locations[n].locators_radius.randitem.randitem35 = 0.01;
	Locations[n].items.randitem35 = "1_lanternF_night";

	Locations[n].locators_radius.randitem.randitem36 = 0.01;
	Locations[n].items.randitem36 = "1_lanternF_day";

	Locations[n].locators_radius.randitem.randitem37 = 0.01;
	Locations[n].items.randitem37 = "1_lanternF_day";

	Locations[n].locators_radius.randitem.randitem38 = 0.01;
	Locations[n].items.randitem38 = "1_lanternF_day";

	Locations[n].locators_radius.randitem.randitem39 = 0.01;
	Locations[n].items.randitem39 = "1_lanternF_night";

	Locations[n].locators_radius.randitem.randitem40 = 0.01;
	Locations[n].items.randitem40 = "1_lanternF_day";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "GB_chinese_room";
//	locations[n].id.label = "Fireworks laboratory";			//later when opened
	Locations[n].filespath.models = "locations\outside\Chinatown\\";
//	Locations[n].filespath.textures = "locations\outside\Chinatown";
	Locations[n].image = "GB_chinese_room.tga";

	//Town sack
	//Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "silent_residence";
	
	//Models
	//Always
	Locations[n].models.always.locators = "chinese_room_locator_chest";
	Locations[n].models.always.l1 = "1054007";
	Locations[n].models.always.l2 = "nc";
	Locations[n].models.always.l3 = "tree";
	
	//Day
	Locations[n].models.day.charactersPatch = "walk_patch";

	//Night
	Locations[n].models.night.charactersPatch = "walk_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "GB_Chinese_restaurant";
	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	Locations[n].locators_radius.reload.reload1 = 0.3;

	Locations[n].locators_radius.box.box1 = 0.3;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "carpet1";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "bench_scales";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "pyrite_basket_up";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "medicine_table";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "long_table";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "armchair01";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "clock_big2";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "bookcase";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "book47";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "cauldron1";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "chest5_coas";

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "pistolbarrel_gp0";

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "pistolbarrel_gp0";

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
	Locations[n].items.randitem14 = "book49";

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	Locations[n].items.randitem15 = "book47";

	Locations[n].locators_radius.randitem.randitem16 = 0.001;
	Locations[n].items.randitem16 = "book47";

	Locations[n].locators_radius.randitem.randitem17 = 0.001;
	Locations[n].items.randitem17 = "potion2";

	Locations[n].locators_radius.randitem.randitem18 = 0.001;
	Locations[n].items.randitem18 = "potion3";

	Locations[n].locators_radius.randitem.randitem19 = 0.001;
	Locations[n].items.randitem19 = "pistolbarrel_gp0";

	Locations[n].locators_radius.randitem.randitem20 = 0.001;
	Locations[n].items.randitem20 = "pistolbarrel_gp0";

	Locations[n].locators_radius.randitem.randitem21 = 0.001;
	Locations[n].items.randitem21 = "pistolbarrel_gp0";

	Locations[n].locators_radius.randitem.randitem22 = 0.001;
	Locations[n].items.randitem22 = "pistolbarrel_gp0";

	Locations[n].locators_radius.randitem.randitem23 = 0.001;
	Locations[n].items.randitem23 = "FWchest";			

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "GB_closed_chinese_room";
	locations[n].id.label = "";			
	Locations[n].filespath.models = "locations\outside\Chinatown\\";

	//Town sack
	//Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "silent_residence";
	
	//Models
	//Always
	Locations[n].models.always.locators = "chinese_room_locator";
	Locations[n].models.always.l1 = "1054007";
	Locations[n].models.always.l2 = "nc";
	Locations[n].models.always.l3 = "tree";
	
	//Day
	Locations[n].models.day.charactersPatch = "walk_patch";

	//Night
	Locations[n].models.night.charactersPatch = "walk_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	locations[n].id = "GB_chinese_gunpowder";
	locations[n].id.label = "Gunpowder mill";
	Locations[n].image = "GB_gunpowder_mill.tga";

	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "Rogers_study";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\sklad_gunpowder";
	locations[n].models.always.locators = "sklad_l_GB_barrel";			//start _empty, changed to barrel
	locations[n].models.always.l1 = "sklad";
	locations[n].models.always.l2 = "bottle_ME0";					//2 = normal bottle, for ex "bottle_MC2", start = ""	
	locations[n].models.always.l3 = "bottle_LE0";					//3 = large bottle,  for ex "bottle_LN1", start = ""
	
	Locations[n].models.always.window = "sklad_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;			
	//Day
	locations[n].models.day.charactersPatch = "sklad_patch";
	//Night
	locations[n].models.night.charactersPatch = "sklad_patch";
	//Environment
	locations[n].environment.weather = "false";
	locations[n].environment.sea = "false";
	Locations[n].models.back = "back\farm2_";

	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "GB_Chinatown";
	locations[n].reload.l1.emerge = "reload9";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "";
	Locations[n].locators_radius.reload.reload1 = 0.5;

	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box8 = 0.5;
	Locations[n].locators_radius.box.box9 = 0.8;
	Locations[n].locators_radius.box.box10 = 0.5;
	Locations[n].locators_radius.box.box11 = 0.5;
	Locations[n].locators_radius.box.box12 = 0.5;
	Locations[n].locators_radius.box.box13 = 0.5;
	Locations[n].locators_radius.box.box14 = 0.5;
	Locations[n].locators_radius.box.box15 = 0.5;
	Locations[n].locators_radius.box.box16 = 0.7;
	Locations[n].locators_radius.box.box17 = 0.7;
	Locations[n].locators_radius.box.box18 = 0.3;

	Locations[n].locators_radius.goto.box12 = 0.2;
	Locations[n].locators_radius.goto.box13 = 0.2;
	Locations[n].locators_radius.goto.box3 = 0.2;
	Locations[n].locators_radius.goto.stuck12 = 0.2;
	Locations[n].locators_radius.goto.stuck13 = 0.2;
	Locations[n].locators_radius.goto.stuck3 = 0.2;
	Locations[n].locators_radius.goto.ingredients = 0.2;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "rum_party3";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "rope_ale";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "medicine_table2";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "Cannonbox";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "ladder_big";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "crank";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "gatedoor_CRY";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "2_close_boxes";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "cauldron1";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "2_close_boxes";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "2_close_boxes";

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "cannon_pipe45";

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "bladebarrel";			

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
	Locations[n].items.randitem14 = "barrel3";

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	Locations[n].items.randitem15 = "stool";

	Locations[n].locators_radius.randitem.randitem16 = 0.001;
	Locations[n].items.randitem16 = "";				//not used

	Locations[n].locators_radius.randitem.randitem17 = 1.1;
	Locations[n].items.randitem17 = "pistolbarrel_gp0";		//empty in right corner (covering key27)

	Locations[n].locators_radius.randitem.randitem18 = 0.001;
	Locations[n].items.randitem18 = "";				//not used

	Locations[n].locators_radius.randitem.randitem19 = 0.001;
	Locations[n].items.randitem19 = "periscope";

	Locations[n].locators_radius.randitem.randitem20 = 0.001;
	Locations[n].items.randitem20 = "rope_vertical";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "GB_chinese_nitre";
	locations[n].id.label = "Salpeter barn";	
	Locations[n].filespath.models = "locations\inside\Warehouse";
	//Locations[n].filespath.textures = "locations\inside\warehouse\brick";
	Locations[n].image = "GB_salpeter.tga";

	//Town sack
	Locations[n].townsack = "Santiago";

	//Sound
	locations[n].type = "Rogers_cellar";
	locations[n].fastreload = "Santiago";
	//Models
	//Always
	Locations[n].models.always.locators = "warehouse_l_nitre_WW";
	Locations[n].models.always.shipyard = "warehouse";
	locations[n].models.always.l1 = "steplock_v";
	locations[n].models.always.l2 = "lever1_down";
	locations[n].models.always.l3 = "steplock2_v";
	locations[n].models.always.l4 = "lever2_down";
	locations[n].models.always.l5 = "roll_of_planks3";
	locations[n].models.always.l6 = "lever0_up";

	//Day
	Locations[n].models.day.charactersPatch = "warehouse_p";
	//Night
	Locations[n].models.night.charactersPatch = "warehouse_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Locations[n].environment.weather = "true";
	//Locations[n].environment.sea = "true";
	//Locations[n].MaxSeaHeight = 0.1;

	//Reload map

	Locations[n].locators_radius.box.box1 = 0.7;
	Locations[n].locators_radius.box.box2 = 0.7;
	Locations[n].locators_radius.box.box3 = 0.01;		//temp small 2.0

	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 2.6;
	Locations[n].locators_radius.box.box8 = 0.5;
	Locations[n].locators_radius.box.box9 = 2.0;		//same place as box3 but for bucket_nitre
	Locations[n].locators_radius.box.box10 = 0.5;
	Locations[n].locators_radius.goto.splash1 = 1.4;
	Locations[n].locators_radius.goto.splash2 = 1.5;
	Locations[n].locators_radius.goto.steplock = 0.35;
	Locations[n].locators_radius.goto.stepback = 0.2;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;		//tub2: water
	Locations[n].items.randitem1 = "2_tubs4";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;		//under tub2 (invisible)
	Locations[n].items.randitem2 = "2_tubs4";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;		//not used
	//Locations[n].items.randitem3 = "box";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;		//tub3: water
	Locations[n].items.randitem4 = "2_tubs4";

	Locations[n].locators_radius.randitem.randitem5 = 0.1;
	Locations[n].items.randitem5 = "oven";

	Locations[n].locators_radius.randitem.randitem6 = 0.1;
	Locations[n].items.randitem6 = "cannon_pipe";

	Locations[n].locators_radius.randitem.randitem7 = 0.1;
	Locations[n].items.randitem7 = "oven";

	Locations[n].locators_radius.randitem.randitem8 = 0.1;		//not used
	//Locations[n].items.randitem8 = "box";				

	Locations[n].locators_radius.randitem.randitem9 = 0.1;
	Locations[n].items.randitem9 = "2_tubs4";			//tub1

	Locations[n].locators_radius.randitem.randitem10 = 0.1;
	Locations[n].items.randitem10 = "gatefloor_oven";

	Locations[n].locators_radius.randitem.randitem11 = 0.1;
	Locations[n].items.randitem11 = "cannon_pipe";

	Locations[n].locators_radius.randitem.randitem12 = 0.1;
	Locations[n].items.randitem12 = "cannon_pipe_up";

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "rope_ale";

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
	Locations[n].items.randitem14 = "rope_ale";

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	Locations[n].items.randitem15 = "bladewood";

	Locations[n].locators_radius.randitem.randitem16 = 0.001;
	Locations[n].items.randitem16 = "bladewood";

	Locations[n].locators_radius.randitem.randitem17 = 0.001;
	Locations[n].items.randitem17 = "chimney";

	Locations[n].locators_radius.randitem.randitem18 = 0.001;
	Locations[n].items.randitem18 = "hay";

	Locations[n].locators_radius.randitem.randitem19 = 0.001;
	Locations[n].items.randitem19 = "hay";

	Locations[n].locators_radius.randitem.randitem20 = 0.001;
	Locations[n].items.randitem20 = "hay";

	Locations[n].locators_radius.randitem.randitem21 = 0.0001;
	Locations[n].items.randitem21 = "cannon_pipe_up";

	Locations[n].locators_radius.randitem.randitem22 = 0.0001;
	Locations[n].items.randitem22 = "cannon_pipe45_up";

	Locations[n].locators_radius.randitem.randitem23 = 0.0001;
	Locations[n].items.randitem23 = "steplock";

	Locations[n].locators_radius.randitem.randitem24 = 0.0001;
	Locations[n].items.randitem24 = "steplock_v";

	Locations[n].locators_radius.randitem.randitem25 = 0.0001;
	Locations[n].items.randitem25 = "cannon_pipe45";

	Locations[n].locators_radius.randitem.randitem26 = 0.0001;		//tub2: dirt
	Locations[n].items.randitem26 = "2_tubs1";

	Locations[n].locators_radius.randitem.randitem27 = 0.0001;		//tub2: nitre
	Locations[n].items.randitem27 = "2_tubs3";

	Locations[n].locators_radius.randitem.randitem28 = 0.0001;		//tub3: dirt
	Locations[n].items.randitem28 = "2_tubs1";

	Locations[n].locators_radius.randitem.randitem29 = 0.0001;		//tub3: nitre
	Locations[n].items.randitem29 = "2_tubs3";

	Locations[n].locators_radius.randitem.randitem30 = 0.8;		
	Locations[n].items.randitem30 = "key26";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "GB_charcoal_stairs";
//	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house\\";
	Locations[n].image = "GB_small_stairs.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_jail";
	
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F1_l_charcoal";
	Locations[n].models.always.tavern = "LH_F1";
	Locations[n].models.always.window = "LF1_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "LH_F1_p";

	//Night
	Locations[n].models.night.charactersPatch = "LH_F1_p";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redlf2_";

	//Reload map

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "GB_charcoal_stairs";
	Locations[n].reload.l3.emerge = "reload4";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].reload.l4.name = "reload4";		//down
	Locations[n].reload.l4.go = "GB_chinese_charcoal";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.3;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	//Locations[n].items.randitem1 = "door_N09";
	Locations[n].items.randitem1 = "door_A03";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "gatedoor_w";

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;


//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Hut";

	Locations[n].id = "GB_chinese_charcoal";
	locations[n].id.label = "Charcoal oven";
	Locations[n].image = "GB_charcoal.tga";

	//Sound
	locations[n].type = "Rogers_jail";
	//Models
	//Always
	Locations[n].models.always.locators = "Hut_locators_charcoal1";
	Locations[n].models.always.house = "Hut";
	Locations[n].models.always.l1 = "";		//wood3 = glowing, wood4 = fresh, wood5 = black
	Locations[n].models.always.l2 = "";		//wood_short_floor, wood_short_stump, wood4_stump
	
	//Day
	Locations[n].models.day.charactersPatch = "Hut_patch";
	//Night
	Locations[n].models.night.charactersPatch = "Hut_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "GB_charcoal_storeroom";
	Locations[n].reload.l1.emerge = "arrive";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";	
	Locations[n].locators_radius.reload.reload1 = 0.0001;		//large when opened
	Locations[n].reload.l1.disable = 1;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "GB_charcoal_stairs";
	Locations[n].reload.l2.emerge = "goto4";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 0.7;

	Locations[n].locators_radius.goto.box1 = 0.5;
	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.8;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.7;			//locked door to storeroom
	Locations[n].locators_radius.box.box6 = 0.6;			//at wood_short_floor
	Locations[n].locators_radius.box.box7 = 0.5;			//at stump for pick up wood4 here

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "gatedoor_small_stone";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "gatedoor_small_stone";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "gatedoor_small_stone";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "gatedoor_small_stone";
	
	Locations[n].locators_radius.randitem.randitem5 = 0.001;	//log out - instead of ri11
	Locations[n].items.randitem5 = "wood_long_log";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "wood_long_log";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "wood_long_log";

	Locations[n].locators_radius.randitem.randitem8 = 0.6;
//	Locations[n].items.randitem8 = "wood_short_logs";		//not used

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "2_close_boxes";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "stump";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;	//log in - instead of ri5
	Locations[n].items.randitem11 = "wood_long_log";

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "2_close_boxes";

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
//	Locations[n].items.randitem13 = "wood_short_standing";		//ready for an axe, not used

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
//	Locations[n].items.randitem14 = "wood4_item";			//small wood ready to pick up, not used	

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	Locations[n].items.randitem15 = "wood_long_log";

	Locations[n].locators_radius.randitem.randitem16 = 0.001;
	Locations[n].items.randitem16 = "wood_long_log";

	Locations[n].locators_radius.randitem.randitem17 = 0.001;
	Locations[n].items.randitem17 = "wood_long_log";

	Locations[n].locators_radius.randitem.randitem18 = 1.0;
	Locations[n].items.randitem18 = "key24";	

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "GB_charcoal_storeroom";
	locations[n].id.label = "Charcoal storeroom";
	Locations[n].filespath.models = "locations\inside\prison";
	Locations[n].image = "GB_charcoal_storeroom.tga";

	//Town sack
	//Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_jail";

	//Models
	//Always
	Locations[n].models.always.prison = "Pri";
	Locations[n].models.always.locators = "Pri_l_gibbet_GB";
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
	Locations[n].reload.l1.go = "GB_chinese_charcoal";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "";	
	Locations[n].locators_radius.reload.reload1 = 2.0;			//checkpoint for reload loop to prison

	Locations[n].locators_radius.goto.goto3 = 1.0;

	Locations[n].locators_radius.box.box3 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "gatedoor_store4_wall";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "gatedoor_store4_wall";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "gatedoor_vsmall_HUT";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "gatedoor_vsmall_HUTR";

	Locations[n].locators_radius.randitem.randitem5 = 0.1;
	Locations[n].items.randitem5 = "bookcase";
	
	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "bookcase";

	Locations[n].locators_radius.randitem.randitem7 = 1.5;
	Locations[n].items.randitem7 = "bladesaw";

	Locations[n].locators_radius.randitem.randitem8 = 0.8;
	Locations[n].items.randitem8 = "pistolbucket_empty";

	Locations[n].locators_radius.randitem.randitem9 = 1.4;
	Locations[n].items.randitem9 = "doc4A";	

	Locations[n].locators_radius.randitem.randitem10 = 0.8;
	Locations[n].items.randitem10 = "bladebarrel_gp0";				
	
	LAi_LocationMonstersGen(&locations[n], false);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "GB_sulphur_corridor";
	//locations[n].id.label = "Rogers' passage";
	Locations[n].filespath.models = "locations\inside\Corridor\\";
	Locations[n].filespath.textures = "locations\inside\Corridor\dark";

	Locations[n].image = "GB_sulfur_passage.tga";

	//Sound
	locations[n].type = "silent_residence";
	
	//Models
	//Always
	Locations[n].models.always.locators = "StoreSmall_locators_JRH_dark_sulfur";		
	Locations[n].models.always.store = "StoreSmall";
	Locations[n].models.always.l1 = "scroll46";

	//Day
	Locations[n].models.day.charactersPatch = "StoreSmall_patch";

	//Night
	Locations[n].models.night.charactersPatch = "StoreSmall_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "GB_Chinatown";
	Locations[n].reload.l1.emerge = "reload8";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	Locations[n].locators_radius.reload.reload1 = 0.5;
	
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "GB_chinese_sulphur";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;		
	
	Locations[n].locators_radius.box.box1 = 0.0001;			//candle
	Locations[n].locators_radius.box.box2 = 0.5;			//counter

	Locations[n].locators_radius.randitem.randitem1 = 0.0001;
	Locations[n].items.randitem1 = "gatedoor_Mine";

	Locations[n].locators_radius.randitem.randitem2 = 0.0001;
	Locations[n].items.randitem2 = "gatedoor_Mine";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "door_largeh";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "door_largeh";

	Locations[n].locators_radius.randitem.randitem5 = 0.0001;
	Locations[n].items.randitem5 = "gatedoor_w_45";

	//...........................................................

	Locations[n].locators_radius.randitem.randitem6 = 0.0001;
	Locations[n].items.randitem6 = "gatedoor_Mine_dark";

	Locations[n].locators_radius.randitem.randitem7 = 0.0001;
	Locations[n].items.randitem7 = "gatedoor_Mine_dark";

	Locations[n].locators_radius.randitem.randitem8 = 0.1;
	Locations[n].items.randitem8 = "door_largeh_dark";

	Locations[n].locators_radius.randitem.randitem9 = 0.1;
	Locations[n].items.randitem9 = "door_largeh_dark";

	Locations[n].locators_radius.randitem.randitem10 = 0.0001;
	Locations[n].items.randitem10 = "gatedoor_w_45_dark";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	locations[n].id = "GB_chinese_sulphur";
	locations[n].id.label = "Sulfur room";
	Locations[n].image = "GB_sulfur.tga";

	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "Rogers_mine";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\TempleRoundInside";
	locations[n].models.always.locators = "TRI_l_sulphur_closed";
	locations[n].models.always.l1 = "TempleRoundInside";
	locations[n].models.always.l2 = "wood_floor";		//wood_floor, wood_sulph
	locations[n].models.always.l3 = "lever_up";
	locations[n].models.always.l4 = "";			//pyrite_stones2
	locations[n].models.always.l5 = "";			//pytite_stones1
			
	//Day
	locations[n].models.day.charactersPatch = "TempleRoundInside_patch";
	//Night
	locations[n].models.night.charactersPatch = "TempleRoundInside_patch";
	//Environment
	locations[n].environment.weather = "false";
	locations[n].environment.sea = "false";

	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "GB_sulphur_corridor";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "";

	Locations[n].locators_radius.box.box1 = 1.4;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box6 = 1.4;
	Locations[n].locators_radius.box.box7 = 0.5;
	Locations[n].locators_radius.box.box8 = 0.5;
	Locations[n].locators_radius.box.box9 = 0.5;
	Locations[n].locators_radius.goto.steplock = 0.3;
	Locations[n].locators_radius.goto.step_back = 0.1;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "distillery";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;		//not used
	Locations[n].items.randitem2 = "";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "ladder_big";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "clock_big";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "lever_base";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "hatch11V";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "mdchest";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "pyrite_basket";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "steplock";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "hatch11_T";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "rope_ale";

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "hatch11V_O";

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "handle";			

	Locations[n].locators_radius.randitem.randitem14 = 0.7;
	Locations[n].items.randitem14 = "pistolbarrel_gp0";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "GB_Chinese_restaurant";
	locations[n].id.label = "Restaurant Tin Ho";
	Locations[n].filespath.models = "locations\inside\Chinese_restaurant\\";
	Locations[n].filespath.textures = "locations\outside\Chinatown";
	Locations[n].image = "GB_chinese_restaurant.tga";

	//Town sack
	//Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "silent_residence";			//"Chinese_restaurant" when opened
	
	//Models
	//Always
	Locations[n].models.always.locators = "chinarest_l_empty";
	Locations[n].models.always.l1 = "1054004";
	Locations[n].models.always.l2 = "nc";
	
	//Day
	Locations[n].models.day.charactersPatch = "walk_patch";

	//Night
	Locations[n].models.night.charactersPatch = "walk_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "GB_Chinatown";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "GB_Chinatown";
	Locations[n].reload.l2.emerge = "reload4";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "GB_Chinatown";
	Locations[n].reload.l3.emerge = "reload5";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "";
	
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "GB_closed_chinese_room";
	Locations[n].reload.l4.emerge = "goto1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].reload.l4.disable = 1;				//never opened

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "GB_closed_chinese_room";
	Locations[n].reload.l5.emerge = "goto1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "";
	Locations[n].reload.l5.disable = 1;				//never opened

	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "GB_chinese_room";
	Locations[n].reload.l6.emerge = "goto1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "";
	Locations[n].reload.l6.disable = 1;

	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "GB_closed_chinese_room";
	Locations[n].reload.l7.emerge = "goto1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "";
	Locations[n].reload.l7.disable = 1;				//never opened

	Locations[n].locators_radius.box.box1 = 0.7;
	Locations[n].locators_radius.goto.dialog = 1.0;
	Locations[n].locators_radius.goto.goto2 = 2.0;
	Locations[n].locators_radius.goto.goto6 = 2.0;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "gatedoor_chi";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "stool";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "gatedoor_chi";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "gatedoor_chi";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "gatedoor_chi";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "";				//not used

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "";				//not used

	Locations[n].items.randitem8 = "pistolpyrite_E";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "32_chairs_R";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "32_chairs_L";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "chair";

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "chair";

	//Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "bladepickaxe1";

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
	Locations[n].items.randitem14 = "toolchest1";	

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Dupin_stairs_up";
	locations[n].id.label = "Detective Agency 1st floor";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house\\";
	Locations[n].filespath.textures = "locations\inside\Doubleflour_house\church_attic";
	Locations[n].image = "GB_small_stairs.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_private";
	
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F1_l_GB_Dupin";	//later LH_F1_l_GB_Dupin
	Locations[n].models.always.tavern = "LH_F1";
	Locations[n].models.always.window = "LF1_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "LH_F1_p";

	//Night
	Locations[n].models.night.charactersPatch = "LH_F1_p";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redlf2_";

	//Reload map
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Dupin_office";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Dupin_stairs_up";
	Locations[n].reload.l3.emerge = "reload4";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "GB_Charleston_town";
	Locations[n].reload.l4.emerge = "reload3";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.3;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_N09";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.01;
//	Locations[n].items.randitem2 = "gatedoor_w";
	Locations[n].items.randitem2 = "gatedoor_attic_brick";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "door_N09";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "gatedoor_attic_brick";

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;


//--------------------------------------------------------------------------

	Locations[n].id = "Dupin_stairs_down";
	locations[n].id.label = "Exit";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house\\";
	Locations[n].filespath.textures = "locations\inside\Doubleflour_house\church_attic";
	Locations[n].image = "GB_small_stairs.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_private";
	
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F1_l_GB_Dupin";	//later LH_F1_l_GB_Dupin
	Locations[n].models.always.tavern = "LH_F1";
	Locations[n].models.always.window = "LF1_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "LH_F1_p";

	//Night
	Locations[n].models.night.charactersPatch = "LH_F1_p";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redlf2_";

	//Reload map
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Dupin_office";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Dupin_stairs_down";
	Locations[n].reload.l3.emerge = "reload4";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "GB_Charleston_town";
	Locations[n].reload.l4.emerge = "reload3";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.3;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_N09";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "gatedoor_attic_brick";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "door_N09";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "gatedoor_attic_brick";

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Dupin_office";
	locations[n].id.label = "C. Auguste Dupin - Private Investigator";
	Locations[n].filespath.models = "locations\Inside\shipyard3";
//	Locations[n].filespath.textures = "locations\inside\Shipyard3\sacristy";
	Locations[n].filespath.textures = "locations\inside\Shipyard3\dupin";
	Locations[n].image = "GB_Dupin_office.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_shop";
	
	//Models
	//Always
	Locations[n].models.always.locators = "sh03_l_GB_Dupin";
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
	Locations[n].models.back = "back\redb_";

	//Reload map

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "GB_Charleston_town";
	Locations[n].reload.l1.emerge = "box39";
	Locations[n].reload.l1.label = "";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 0.5;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Dupin_stairs_down";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.label = "";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 0.5;
	
	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_N09";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "hatch15";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "hatch15";

	Locations[n].locators_radius.randitem.randitem4 = 0.0001;
	Locations[n].items.randitem4 = "carpet3";

	Locations[n].locators_radius.box.box1 = 0.1;
	Locations[n].locators_radius.box.box2 = 0.6;
	Locations[n].locators_radius.box.box3 = 0.6;
	Locations[n].locators_radius.box.box4 = 0.6;
	Locations[n].locators_radius.box.box5 = 0.6;
	Locations[n].locators_radius.box.box6 = 0.5;
	Locations[n].locators_radius.box.box7 = 0.5;
	Locations[n].locators_radius.box.box8 = 0.5;
	Locations[n].locators_radius.box.box9 = 0.5;

	Locations[n].locators_radius.goto.sit2 = 1.5;
	Locations[n].locators_radius.goto.start_L = 1.2;

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Dupin_private";
	locations[n].id.label = "Dupin's room";
	Locations[n].filespath.models = "locations\inside\mh10";
	Locations[n].image = "Inside_mh10.tga";

	//Town sack
	Locations[n].townsack = "Quebradas Costillas";

	//Sound
	locations[n].type = "brothel_room_QC";					

	//Models
	//Always
	Locations[n].models.always.locators = "mh10_l_dupin_closed";
	Locations[n].models.always.house = "mh10";
	Locations[n].models.always.window = "mh10_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "mh10_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh10_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\qcsh_";
	//Reload map

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "GB_Charleston_town";
	Locations[n].reload.l1.emerge = "Reload17";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 0.5;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "GB_Charleston_opium";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 0.001;		//0.7 later
	Locations[n].reload.l2.disable = 1;
	
/*
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "GB_Charleston_town";
	Locations[n].reload.l3.emerge = "box28";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].locators_radius.reload.reload3 = 0.3;
*/
	Locations[n].locators_radius.box.box1 = 0.8;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.7;
	Locations[n].locators_radius.box.box6 = 0.5;
	Locations[n].locators_radius.box.box7 = 0.5;			//0.001 later
	Locations[n].locators_radius.box.box8 = 0.5;	
	Locations[n].locators_radius.item.item3 = 0.01;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "hatch11";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "lever_base";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "stool";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "chair";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "lever_up";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "lever_down";

	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "hatch11_O";

	Locations[n].locators_radius.randitem.randitem8 = 0.01;
	Locations[n].items.randitem8 = "hatch11_T";

	LAi_LocationFightDisable(&Locations[n], true);	

	Locations[n].island = "QuebradasCostillas";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "GB_Charleston_opium";
	locations[n].id.label = "Opium Den";
	Locations[n].filespath.models = "locations\inside\den"; 
	Locations[n].image = "Inside_Den.tga"; // KK

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	//locations[n].type = "blue_cavern";
	locations[n].type = "den";
	locations[n].fastreload = "Redmond";
	//Models
	//Always
	Locations[n].models.always.city = "mh5";
	Locations[n].models.always.locators = "mh5_l_dupin";
	Locations[n].models.always.window = "mh5_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day

	Locations[n].models.day.charactersPatch = "mh5_p";

	//Night

	Locations[n].models.night.charactersPatch = "mh5_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redmh5_";

	//Reload map

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "GB_Charleston_town";
	Locations[n].reload.l1.emerge = "box63";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Dupin_private";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 0.001;		//0.6 later
	Locations[n].reload.l2.disable = 1;

	Locations[n].locators_radius.box.box4 = 0.7;
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.box.box7 = 0.6;			//0.001 later

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "hatch11D";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "carpet1";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "GB_Charleston_penthouse";
	locations[n].id.label = "Bedroom";
	Locations[n].filespath.models = "locations\inside\mh10";
	Locations[n].image = "Inside_mh10.tga";

	//Town sack
	Locations[n].townsack = "Quebradas Costillas";

	//Sound
	locations[n].type = "brothel_room_QC";					

	//Models
	//Always
	Locations[n].models.always.locators = "mh10_l_GB";
	Locations[n].models.always.house = "mh10";
	Locations[n].models.always.window = "mh10_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "mh10_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh10_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\qcsh_";
	//Reload map

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "GB_Charleston_penthouse_first_floor";
	Locations[n].reload.l1.emerge = "Reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Quebradas Costillas store.";
	Locations[n].locators_radius.reload.reload1 = 0.5;
	Locations[n].reload.l1.disable = 1;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "GB_Charleston_town";
	Locations[n].reload.l2.emerge = "penthouse";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 0.5;
	Locations[n].reload.l2.disable = 1;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "GB_Charleston_town";
	Locations[n].reload.l3.emerge = "box28";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].locators_radius.reload.reload3 = 0.3;

	Locations[n].locators_radius.box.box1 = 0.001;
	Locations[n].locators_radius.box.box2 = 0.001;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.item.item3 = 0.01;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "ladder_big";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "hatch11B";

	LAi_LocationFightDisable(&Locations[n], true);	

	Locations[n].island = "QuebradasCostillas";
	n = n + 1;

//--------------------------------------------------------------------------

	//FAKE LOCATION
	Locations[n].id = "GB_Charleston_penthouse_first_floor";
	locations[n].id.label = "First floor";
	
	Locations[n].filespath.models = "locations\inside\mh10";
	Locations[n].image = "Inside_mh10.tga";

	//Town sack
	Locations[n].townsack = "Quebradas Costillas";
	//Sound
	locations[n].type = "brothel_room_QC";					
	//Models
	//Always
	Locations[n].models.always.locators = "mh10_l";
	Locations[n].models.always.house = "mh10";
	Locations[n].models.always.window = "mh10_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "mh10_p";
	//Night
	Locations[n].models.night.charactersPatch = "mh10_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\qcsh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "GB_Charleston_penthouse_first_floor";
	Locations[n].reload.l1.emerge = "Reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Quebradas Costillas store.";
	Locations[n].locators_radius.reload.reload1 = 0.5;
	Locations[n].reload.l1.disable = 1;

	Locations[n].island = "QuebradasCostillas";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Pym_drawing_room";
	locations[n].id.label = "Pym's drawing room";
	Locations[n].image = "Inside_Residence4.tga";

	//Town sack
	Locations[n].townsack = "Willemstad";

	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Willemstad";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Residence4";
	Locations[n].models.always.locators = "Res04_l_GB";
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
	Locations[n].models.back = "back\dour4_";

	//Reload map
	//bridge
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "GB_Charleston_town";
	Locations[n].reload.l1.emerge = "box55";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].reload.l2.name = "Reload2";
	Locations[n].reload.l2.go = "Pym_bedroom";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].locators_radius.box.box2 = 0.1;			//not used
	Locations[n].locators_radius.box.box3 = 0.7;			
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.box.box6 = 0.5;
	Locations[n].locators_radius.box.box7 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "gatedoor_store4_wall";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "door_N44T";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Curacao"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Pym_bedroom";
	locations[n].id.label = "Bedroom";
	Locations[n].image = "Inside_Doubleflour_House_Room.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_neutral";
	locations[n].fastreload = "Redmond";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Doubleflour_house";
	Locations[n].models.always.locators = "LH_F2_l_pym_CLOSED";
	Locations[n].models.always.tavern = "LH_F2";
//	Locations[n].models.always.window = "LH_F2_w";
	Locations[n].models.always.window = "LH_F2_w_pym";	
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
	Locations[n].reload.l1.go = "Pym_stairs";
	Locations[n].reload.l1.emerge = "goto4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	Locations[n].reload.l1.disable = 1;			//unlocked by Pym later

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Pym_drawing_room";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 0.8;

	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.7;
	Locations[n].locators_radius.box.box5 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "NicheBooks";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;		//painting down
	Locations[n].items.randitem2 = "WhalingShip";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;		//rope down
	Locations[n].items.randitem3 = "rope_ale";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "anchor_item";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;		//rope up
	Locations[n].items.randitem5 = "rope_ale";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;		//painting up
	Locations[n].items.randitem6 = "WhalingShip";

	Locations[n].locators_radius.randitem.randitem7 = 0.01;		//rope painting
	Locations[n].items.randitem7 = "rope_ale";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Pym_stairs";
	//locations[n].id.label = "Stairs";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house\\";
	Locations[n].image = "GB_small_stairs.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_private";
	
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F1_l_pym";
	Locations[n].models.always.tavern = "LH_F1";
	Locations[n].models.always.window = "LF1_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "LH_F1_p";

	//Night
	Locations[n].models.night.charactersPatch = "LH_F1_p";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redlf2_";

	//Reload map
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Pym_study";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Pym_stairs";
	Locations[n].reload.l3.emerge = "reload4";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Pym_bedroom";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.3;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_largeh2";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "gatedoor_w";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "door_N05";

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\apothecary";	

	Locations[n].id = "Pym_study";
	locations[n].id.label = "Study";
	Locations[n].image = "GB_Pym_study.tga"; // KK
	//Town sack
	Locations[n].townsack = "Greenford"; 
	//Sound
	locations[n].type = "Rogers_study";
	//locations[n].fastreload = "Greenford";
	//Models
	//Always
	Locations[n].models.always.locators = "resp_l_pym_CLOSED";
	Locations[n].models.always.l1 = "resp";
	Locations[n].models.always.l2 = "";			//sack2, sack2_big or ""
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
	Locations[n].models.back = "back\grms_";
	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Pym_stairs";
	Locations[n].reload.l1.emerge = "Reload2";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.box.box6 = 0.5;
	Locations[n].locators_radius.box.box7 = 0.5;
	Locations[n].locators_radius.box.box8 = 0.5;
	Locations[n].locators_radius.box.box9 = 0.5;
	Locations[n].locators_radius.box.box10 = 0.5;
	Locations[n].locators_radius.box.box11 = 0.5;
	Locations[n].locators_radius.box.box12 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "pirate_flag";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "ladder_big";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "steplock2";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "hatch11D_O3";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "hatch11_T";			//not used

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "hatch11DB";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Pym_towerroom";
	locations[n].id.label = "Tower room";
	locations[n].image = "GB_Pym_chamber.tga";
	Locations[n].filespath.models = "locations\inside\SmallChamber\\";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Pym_tower";

	//Models
	//Always
	Locations[n].models.always.city = "sh05";
	Locations[n].models.always.locators = "sh05_l_chamber1";
	Locations[n].models.always.window = "sh05_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "sh05_patch";
	//Night
	Locations[n].models.night.charactersPatch = "sh05_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Locations[n].models.back = "back\mures2_";
	Locations[n].models.back = "back\redb_";

	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Pym_study";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box2 = 0.3;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.box.box6 = 0.5;
	Locations[n].locators_radius.box.box7 = 0.0001;			//window
	Locations[n].locators_radius.box.box8 = 0.0001;			//try brake hatch open
	Locations[n].locators_radius.box.box9 = 0.0001;			//pour gp on hatch
	Locations[n].locators_radius.box.box10 = 0.5;			//got to hiding place
	Locations[n].locators_radius.box.box11 = 0.2;			//leave hiding place

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "gatefloor_oven";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "hatch11_O";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "hatch11V";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "skull3";

	Locations[n].locators_radius.randitem.randitem5 = 0.1;
	Locations[n].items.randitem5 = "bookcase";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "carpet3V";			//to the left (start)

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "chest5_coas";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "2_sabres";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "carpet3V";			//to the right

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "carpet3V";			//very much to the left

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "pole3_small";

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "hatch11";

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "mdchest";

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
	Locations[n].items.randitem14 = "bladepaperroll";

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	Locations[n].items.randitem15 = "mdchest_broken";

	Locations[n].locators_radius.randitem.randitem16 = 0.001;
	Locations[n].items.randitem16 = "hatch11_T";

	LAi_LocationFightDisable(&Locations[n], true);			
	Locations[n].island = "Redmond";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "GB_Charleston_tailorsShop";
	Locations[n].filespath.models = "locations\Inside\StoreSmall";	
	Locations[n].image = "Inside_StoreSmall.tga";
//	locations[n].id.label = "Charleston tailor - back again next week";
	locations[n].id.label = "Charleston tailor";
	//Town sack
	//Locations[n].townsack = "Redmond";
	//Sound
//	locations[n].type = "brothel_shop";
	locations[n].type = "shop";

	//Models
	//Always
	Locations[n].models.always.locators = "SS_l_GB_tailor";
	Locations[n].models.always.l1 = "ss";
	Locations[n].models.always.window = "ss_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "ss_p";
	Locations[n].models.day.fonar = "SS_fn";

	//Night
	Locations[n].models.night.charactersPatch = "ss_p";
	Locations[n].models.night.fonar = "SS_fn";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\qcss_";
	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "GB_Charleston_town";
	Locations[n].reload.l1.emerge = "Reload13";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.locator2 = 0.0001;	//unlock first

	Locations[n].reload.l2.name = "locator1";
	Locations[n].reload.l2.go = "GB_Charleston_town";
	Locations[n].reload.l2.emerge = "box60";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].locators_radius.box.box1  = 1.0;		//unlock lower door
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.7;
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.box.box6 = 0.5;
	Locations[n].locators_radius.box.box7 = 0.7;
	Locations[n].locators_radius.box.box8 = 0.1;
	Locations[n].locators_radius.box.box9 = 0.5;
	Locations[n].locators_radius.box.box10 = 0.5;
	Locations[n].locators_radius.box.box11 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "Textile3";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "blade3carpets";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "bed";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "dummy";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "pole1";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Conceicao";
	n = n + 1;

//--------------------------------------------------------------------------

	locations[n].id = "GB_Charleston_warehouse_stairs";
	locations[n].id.label = "To the Wine Cellar";
	Locations[n].image = "GB_church_winecellar_entre.tga";
	//Town sack
	locations[n].townsack = "Redmond";
	//Sound
	locations[n].type = "Rogers_cellar";
	
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Wine_cellar";
	locations[n].models.always.DungeonVault1 = "DungeonVault1";
	locations[n].models.always.InquisitionDungeonVault1Fonars = "DungeonVault1_fonars";
	locations[n].models.always.l1 = "elevator3_down";		//elevator3: down, up = fixed by a rope, final = on barrel
	locations[n].models.always.l2 = "rope_up";			//rope: up, down, 45
	locations[n].models.always.l3 = "hub";
	locations[n].models.always.l4 = "steplock_v";
	locations[n].models.always.l5 = "lever1_up";			//lever1:up = flood, down = dry		
	locations[n].models.always.l6 = "barrel3_down";			//barrel3: down, up, steplock

	locations[n].models.always.locators = "cwc_GB";			
	
	//Day
	locations[n].models.day.charactersPatch = "DungeonVault1_patch";
	//Night
	locations[n].models.night.charactersPatch = "DungeonVault1_patch";
	//Environment
	locations[n].environment.weather = "true";		//true is always ok
	locations[n].environment.sea = "false";			//only change is to FALSE

	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "GB_Charleston_town";		
	locations[n].reload.l1.emerge = "reload4";		
	locations[n].reload.l1.autoreload = "0";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "GB_Charleston_wine_cellar";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].locators_radius.reload.reload2_back = 1.0;

	locations[n].locators_radius.reload.reload3 = 0.9;		//back off locators
	locations[n].locators_radius.reload.reload4 = 0.9;
	locations[n].locators_radius.reload.reload5 = 0.9;
	locations[n].locators_radius.reload.reload6 = 0.5;

	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.box.box6 = 0.5;
	Locations[n].locators_radius.box.box7 = 0.5;

	Locations[n].locators_radius.box.box14 = 0.5;			//walk locators
	Locations[n].locators_radius.box.box15 = 0.5;
	Locations[n].locators_radius.box.box16 = 0.5;
	Locations[n].locators_radius.box.box17 = 0.5;
	Locations[n].locators_radius.box.box18 = 0.5;
	Locations[n].locators_radius.box.box19 = 0.5;

	Locations[n].locators_radius.goto.flood = 1.0;
	Locations[n].locators_radius.goto.boatswain = 2.0;
	Locations[n].locators_radius.goto.goto15 = 2.0;			
	Locations[n].locators_radius.goto.goto16 = 2.0;			

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "gatedoor_stone";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "door_A03";

	Locations[n].island = "Redmond";
	n = n + 1;

//--------------------------------------------------------------------------

	locations[n].id = "GB_Charleston_wine_cellar";
	locations[n].id.label = "Church wine cellar";
	Locations[n].image = "GB_church_winecellar.tga";
	//Sound
	Locations[n].townsack = "Redmond";
	locations[n].type = "Rogers_cellar";
//	locations[n].type = "crypt";			//after a while
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Cellar_downstairs";
	locations[n].models.always.Cellar_downstairs = "Cellar_downstairs";
	locations[n].models.always.Cellar_downstairsStuff = "Cellar_downstairs_stuff";
	locations[n].models.always.rays = "Cellar_downstairs_rays";
	locations[n].models.always.locators = "Cellar_downstairs_locators_GB";

	//Day
	locations[n].models.day.charactersPatch = "Cellar_downstairs_patch";
	//Night
	locations[n].models.night.charactersPatch = "Cellar_downstairs_patch";
	//Environment
	locations[n].environment.weather = "false";
	locations[n].environment.sea = "false";		
 	//Reload map

	Locations[n].locators_radius.goto.alertA = 1.0;
	Locations[n].locators_radius.goto.alertB = 1.0;
	Locations[n].locators_radius.goto.alertC = 1.0;
	Locations[n].locators_radius.goto.alertD = 1.0;
	Locations[n].locators_radius.goto.alertE = 1.0;
	Locations[n].locators_radius.goto.alertF = 0.001;		//not used
	Locations[n].locators_radius.goto.see_ladder = 1.0;
	Locations[n].locators_radius.goto.crypt_sound = 0.7;

	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "GB_Charleston_warehouse_stairs";
	locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1_back = 1.0;

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "GB_Charleston_church";
	locations[n].reload.l2.emerge = "arrive";		//was reload2
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "gateroof_white_stone";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "hatch11D";

	LAi_LocationFantomsGen(&locations[n], false);
	Locations[n].island = "Redmond";
	n = n + 1;

//--------------------------------------------------------------------------

	locations[n].id = "GB_Charleston_church";
	locations[n].id.label = "Cathedral";
	locations[n].image = "GB_Charleston_church.tga";
	//Town sack
	//locations[n].townsack = "SanJuan";
	//locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "silent_repair";
	//locations[n].fastreload = "SanJuan";
	//locations[n].islandId = "PuertoRico";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\church_4";
	locations[n].models.always.churchInside2 = "churchInsideBig1";
	locations[n].models.always.churchInside2.level = 65538;
	locations[n].models.always.locators = "churchInsideBig1_locators_GB";

	Locations[n].models.always.churchInside2windows = "churchInsideBig1_windows";
	Locations[n].models.always.churchInside2windows.tech = "LocationWindows";
//	locations[n].models.always.churchInside2windows.level = 65541;
	locations[n].models.always.churchInside2windows.level = 50;

	Locations[n].models.always.churchInside2alpha = "churchInsideBig1_alpha";
	Locations[n].models.always.churchInside2alpha.tech = "LocationWindows";
	locations[n].models.always.churchInside2alpha.level = 65540;

	Locations[n].models.always.churchInside2gold = "churchInsideBig1_gold";
	Locations[n].models.always.churchInside2gold.reflection = 0.6;
	Locations[n].models.always.churchInside2gold.tech = "EnvironmentShader";
	locations[n].models.always.churchInside2gold.level = 65539;

//	locations[n].models.always.back = "..\inside_back";
//	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "churchInsideBig1_patch";
	//Night
	locations[n].models.night.charactersPatch = "churchInsideBig1_patch";
	//Environment
	locations[n].environment.weather = "false";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "GB_Charleston_town";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.disable = 1;

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "GB_Charleston_wine_cellar";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "GB_Charleston_church_office";
	locations[n].reload.l3.emerge = "reload3";
	locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.disable = 1;
	Locations[n].locators_radius.reload.reload3 = 0.5;

	locations[n].reload.l4.name = "reload4";
	locations[n].reload.l4.go = "GB_Charleston_church_office";
	locations[n].reload.l4.emerge = "reload3";
	locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.disable = 1;
	Locations[n].locators_radius.reload.reload4 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "door_largeh";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "hatch11";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "mine";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "key8";				//was roll_of_planks1
	
	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "key8";				//was roll_of_planks2

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "barrel3";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "barrel3";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "toolchest1";

	Locations[n].locators_radius.randitem.randitem9 = 0.7;
	Locations[n].items.randitem9 = "knitting_basket";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "handle";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "handle";

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "handle";

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "handle";

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
	Locations[n].items.randitem14 = "handle_v";

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	Locations[n].items.randitem15 = "handle_v";

	Locations[n].locators_radius.randitem.randitem16 = 0.001;
	Locations[n].items.randitem16 = "handle_v";

	Locations[n].locators_radius.randitem.randitem17 = 0.001;
	Locations[n].items.randitem17 = "handle_v";

	Locations[n].locators_radius.randitem.randitem18 = 0.001;
	Locations[n].items.randitem18 = "handle_v";

	Locations[n].locators_radius.randitem.randitem19 = 0.001;
	Locations[n].items.randitem19 = "handle_v";

	Locations[n].locators_radius.box.box2 = 0.0001;			//0.5 when key is picked up
	Locations[n].locators_radius.box.box3 = 0.0001;			//0.5 when key is picked up
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 1.5;
	Locations[n].locators_radius.box.box6 = 0.6;
	Locations[n].locators_radius.box.box7 = 0.5;
	Locations[n].locators_radius.box.box8 = 0.5;
	Locations[n].locators_radius.box.box9 = 0.5;
	Locations[n].locators_radius.box.box10 = 0.001;
	Locations[n].locators_radius.box.box11 = 0.001;
	Locations[n].locators_radius.box.box12 = 0.5;
	Locations[n].locators_radius.box.box13 = 0.001;
	Locations[n].locators_radius.box.box14 = 0.001;
	Locations[n].locators_radius.box.box15 = 0.5;
	Locations[n].locators_radius.box.box16 = 0.5;

	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "GB_Charleston_church_office";
	locations[n].id.label = "Sacristy";
	//Town sack
	//Locations[n].townsack = "Antigua";
	//Sound
	locations[n].type = "choir";			//was residence
	//locations[n].fastreload = "Antigua";
	Locations[n].filespath.models = "locations\Inside\Shipyard4";
	Locations[n].image = "GB_sacristy.tga";
	//Models
	Locations[n].models.back = "..\back\inside_back_";
	//Always
	Locations[n].models.always.cave = "Sh04";
	Locations[n].models.always.locators = "Sh04_locators_GB";
	Locations[n].models.always.window = "Sh04_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Sh04_patch";
	//Night
	Locations[n].models.night.charactersPatch = "Sh04_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "GB_Charleston_town";
	Locations[n].reload.l1.emerge = "reload22";
	Locations[n].reload.l1.label = "Antigua";

	locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "GB_Charleston_church";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.label = "Antigua";
	Locations[n].reload.l3.disable = 1;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "door_largeh";

	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 1.0;
	Locations[n].locators_radius.goto.goto5 = 3.0;

	Locations[n].island = "Antigua";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "GB_Charleston_townhall";
	locations[n].id.label = "Charleston townhall";
	Locations[n].filespath.models = "locations\inside\Residence_BackHall";
	Locations[n].filespath.textures = "locations\inside\Residence_BackHall";
	Locations[n].image = "GB_townhall.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Redmond";
	//Models
	//Always
	Locations[n].models.always.locators = "ResB_l_GB";
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
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "GB_Charleston_town";
	locations[n].reload.l1.emerge = "reload7";
	locations[n].reload.l1.autoreload = "0";
    	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "GB_Charleston_governor_office";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.disable = 1;
    	
	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "GB_Charleston_governor_kitchen";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.disable = 1;

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "GB_Charleston_governor_office";
	locations[n].id.label = "Governor's Office";
	Locations[n].image = "Town_Havana_Townhall.tga";
	Locations[n].filespath.models = "locations\Inside\Residence2_admiral";
	//Locations[n].filespath.textures = "locations\inside\admiral_office";

	//Town sack
	Locations[n].townsack = "Cartagena";

	//Sound
	locations[n].type = "residence";
	//Models
	//Always
	Locations[n].models.always.city = "Res02";	
	Locations[n].models.always.locators = "Res02_l_GB";
	Locations[n].models.always.window = "Res02_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Res02_p";
	//Night
	Locations[n].models.night.charactersPatch = "Res02_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\mures2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "GB_Charleston_townhall";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "GB_Charleston_governor_bedroom";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "GB_Charleston_governor_kitchen";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.box.box6 = 0.5;
	Locations[n].locators_radius.box.box7 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "build_clock2";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "door_largeh";

	Locations[n].island = "Colombia"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "GB_Charleston_governor_bedroom";
	locations[n].id.label = "Governor's Bedroom";
	Locations[n].filespath.models = "locations\inside\ResBedRoom";
	Locations[n].filespath.textures = "locations\inside\wr_bedroom";
	Locations[n].image = "wr_bedroom.tga";

	//Town sack
	Locations[n].townsack = "Redmond"; // NK 04-08-29
	Locations[n].island = "Redmond"; // NK 04-08-29

	//Sound
	locations[n].type = "residence";
	//Models
	//Always
	Locations[n].models.always.locators = "bed_l_GB";
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
	Locations[n].reload.l1.go = "GB_Charleston_governor_office";
	Locations[n].reload.l1.emerge = "Reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Room in Redmond tavern.";

	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.5;

	LAi_LocationFightDisable(&Locations[n], true);
	n = n + 1;

//--------------------------------------------------------------------------

	locations[n].id = "GB_Charleston_governor_kitchen";
	locations[n].id.label = "Kitchen";
	Locations[n].image = "wr_farm_kitchen.tga";
	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "residence";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\largehouse01";
	locations[n].models.always.l1 = "largehouse01";
	Locations[n].models.always.l2 = "largehouse01_rand";
	locations[n].models.always.locators = "largehouse01_locators_GB2";

	Locations[n].models.always.window = "largehouse01_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	
	//Day
	locations[n].models.day.charactersPatch = "largehouse01_patch";
	//Night
	locations[n].models.night.charactersPatch = "largehouse01_patch";
	//Environment
	locations[n].environment.weather = "false";
	locations[n].environment.sea = "false";
	Locations[n].models.back = "back\farm_";

	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "GB_Charleston_townhall";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "";
	
	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "GB_Charleston_governor_office";
	locations[n].reload.l2.emerge = "reload3";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "";

	Locations[n].locators_radius.box.box2 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "doubledoor";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "gatedoor_BRI";

	Locations[n].island = "Redmond";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "GB_Charleston_store";
	locations[n].id.label = "Charleston store";
	//Town sack
	Locations[n].townsack = "Pointe a Pitre";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Pointe_a_pitre";
	Locations[n].filespath.models = "locations\Inside\store02";
	Locations[n].image = "Inside_Store02.tga";

	//Models
	Locations[n].models.back = "..\back\inside_back_";
	//Always
	Locations[n].models.always.cave = "store02";
	Locations[n].models.always.locators = "store02_locators_GB";
	Locations[n].models.always.window = "store02_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "store02_patch";
	//Night
	Locations[n].models.night.charactersPatch = "store02_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "GB_Charleston_town";
	locations[n].reload.l1.emerge = "reload8";
	locations[n].reload.l1.autoreload = "0";
    	locations[n].reload.l1.label = "Street";

	Locations[n].locators_radius.box.box1 = 0.7;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 1.0;
	Locations[n].locators_radius.box.box5 = 1.0;
	Locations[n].locators_radius.box.box6 = 0.5;
	Locations[n].locators_radius.box.box7 = 1.0;
	Locations[n].locators_radius.box.box8 = 1.0;
	Locations[n].locators_radius.box.box9 = 0.5;
	Locations[n].locators_radius.box.box10 = 0.5;
	Locations[n].locators_radius.box.box11 = 0.5;
	Locations[n].locators_radius.box.box12 = 0.5;
	Locations[n].locators_radius.box.box13 = 0.5;

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Blacksmith1";
	Locations[n].id = "GB_Charleston_blacksmith";
	locations[n].id.label = "Charleston blacksmith";
	Locations[n].image = "Inside_Blacksmith1.tga"; // KK

	//Town sack
	//Locations[n].townsack = "Conceicao";

	//Sound
	locations[n].type = "shop";
	//locations[n].fastreload = "Conceicao";
	//Models
	//Always
	Locations[n].models.always.locators = "MH_l_GB";
	Locations[n].models.always.house = "MH";
	//Locations[n].models.always.env = "smalltavern_env";
	Locations[n].models.always.window = "MH_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	Locations[n].models.always.l1 = "sword1";
	Locations[n].models.always.l1.locator.name = "stuff1";
	Locations[n].models.always.l1.locator.group = "gm";
	Locations[n].models.always.l1.tech = "dLightModel";
	Locations[n].models.always.l2 = "sword2";
	Locations[n].models.always.l2.locator.name = "stuff2";
	Locations[n].models.always.l2.locator.group = "gm";
	Locations[n].models.always.l2.tech = "dLightModel";
	Locations[n].models.always.l4 = "sword3";
	Locations[n].models.always.l4.locator.name = "stuff3";
	Locations[n].models.always.l4.locator.group = "gm";
	Locations[n].models.always.l4.tech = "dLightModel";
	Locations[n].models.always.l5 = "gun";
	Locations[n].models.always.l5.locator.name = "stuff4";
	Locations[n].models.always.l5.locator.group = "gm";
	Locations[n].models.always.l5.tech = "dLightModel";
	Locations[n].models.always.l6 = "gun";
	Locations[n].models.always.l6.locator.name = "stuff5";
	Locations[n].models.always.l6.locator.group = "gm";
	Locations[n].models.always.l6.tech = "dLightModel";
	Locations[n].models.always.l7 = "anvil";
	Locations[n].models.always.l7.locator.name = "anvil";
	Locations[n].models.always.l7.locator.group = "gm";
	Locations[n].models.always.l7.tech = "dLightModel";
	Locations[n].models.always.l8 = "lamp";
	Locations[n].models.always.l8.locator.name = "lamp";
	Locations[n].models.always.l8.locator.group = "gm";
	Locations[n].models.always.l8.tech = "dLightModel";
	Locations[n].models.always.l3 = "cannon";
	Locations[n].models.always.l3.locator.name = "cannon";
	Locations[n].models.always.l3.locator.group = "gm";
	Locations[n].models.always.l3.tech = "dLightModel";
	
	//Day
	Locations[n].models.day.charactersPatch = "MH_p";

	//Night
	Locations[n].models.night.charactersPatch = "MH_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\doumh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "GB_Charleston_town";
	Locations[n].reload.l1.emerge = "reload9";
	
	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	//Locations[n].items.randitem1 = "gatedoor_store4_wall";
	//Locations[n].items.randitem1 = "gatedoor_stone";
	Locations[n].items.randitem1 = "gatedoor_p";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "gatedoor_p";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Conceicao"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "GB_Charleston_high_house_entre";
	//locations[n].id.label = "Chapel stairs";
	Locations[n].filespath.models = "locations\inside\store04";
	//Locations[n].filespath.textures = "locations\inside\store04\church";
	Locations[n].image = "wr_chapel_stairs.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Vane_church";

	//Models
	//Always
	Locations[n].models.always.locators = "store04_locators_JRH5";
	Locations[n].models.always.tavern = "store04";
	Locations[n].models.always.window = "store04_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "store04_patch";

	//Night
	Locations[n].models.night.charactersPatch = "store04_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redmh4_";

	//Reload map
	//up
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "GB_Charleston_high_house_kitchen";
	Locations[n].reload.l4.emerge = "reload3";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	//Locations[n].reload.l4.disable = 1;

	//down
	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "GB_Charleston_town";
	Locations[n].reload.l7.emerge = "box9";
	Locations[n].reload.l7.autoreload = "1";
	Locations[n].reload.l7.label = "";

	Locations[n].locators_radius.goto.goto3 = 1.0;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "door_A01";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "textile3";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "chest1";

	Locations[n].locators_radius.randitem.randitem5 = 0.1;
	Locations[n].items.randitem5 = "gatedoor_5";

	Locations[n].locators_radius.randitem.randitem6 = 0.1;
	Locations[n].items.randitem6 = "textile3";

	Locations[n].locators_radius.randitem.randitem7 = 0.1;
	Locations[n].items.randitem7 = "chest1";
	
	Locations[n].locators_radius.randitem.randitem8 = 0.1;
	Locations[n].items.randitem8 = "clock";

	Locations[n].locators_radius.randitem.randitem9 = 0.1;
	Locations[n].items.randitem9 = "barrel_big";

	Locations[n].locators_radius.randitem.randitem10 = 0.1;
	Locations[n].items.randitem10 = "bookshelf";

	Locations[n].locators_radius.randitem.randitem11 = 0.1;
	Locations[n].items.randitem11 = "gatedoor_p5";

	Locations[n].locators_radius.randitem.randitem12 = 0.1;
	Locations[n].items.randitem12 = "hatch3";

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "gatedoor_CRY";

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
	Locations[n].items.randitem14 = "gatedoor_p";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "GB_Charleston_high_house_kitchen";
	locations[n].id.label = "Woodes Rogers' kitchen";
	Locations[n].filespath.models = "locations\inside\flamhouse";
	Locations[n].image = "wr_kitchen.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	//locations[n].type = "house";
	locations[n].type = "Rogers_residence";

	//Models
	//Always
	Locations[n].models.always.locators = "FlamHouse_locators_GB";
	Locations[n].models.always.tavern = "Flamhouse";
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
	Locations[n].models.back = "back\redb_";

	//Reload map
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "GB_Charleston_high_house_entre";
	Locations[n].reload.l3.emerge = "reload4";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Woodes Rogers´food supply.";
	Locations[n].locators_radius.reload.reload3 = 0.5;
					
/*
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "wr_booty";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Woodes Rogers' booty room";
	
	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "ck_bedroom";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Caroline's bedroom.";
	Locations[n].reload.l5.disable = 1;
*/

	Locations[n].locators_radius.reload.reload4 = 0.5;
	Locations[n].locators_radius.reload.reload5 = 0.5;

	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.5;

	Locations[n].locators_radius.goto.goto6 = 1.5;
	Locations[n].locators_radius.goto.goto7 = 1.0;

	Locations[n].island = "Redmond"; // NK 04-08-29
	LAi_LocationFightDisable(&Locations[n], true);
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "GB_Charleston_usurerhouse";
	locations[n].id.label = "Charleston Post & Bank";
	//Town sack
	//Locations[n].townsack = "Charlestown";
	//Sound
//	locations[n].type = "residence";
	locations[n].type = "house";

	//locations[n].fastreload = "Charlestown";

	Locations[n].filespath.models = "locations\Inside\Bank";
	Locations[n].image = "Inside_Bank.tga";
	//Models
	Locations[n].models.back = "..\back\inside_back_";
	//Always
	Locations[n].models.always.cave = "Bank";
	Locations[n].models.always.l1 = "bars_down";
	Locations[n].models.always.locators = "Bank_locators";
	Locations[n].models.always.window = "Bank_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Bank_patch";
	//Night
	Locations[n].models.night.charactersPatch = "Bank_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "GB_Charleston_Town";
	Locations[n].reload.l1.emerge = "reload11";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# port";

	Locations[n].reload.l10.name = "reload1_back";
	Locations[n].reload.l10.go = "GB_Charleston_strongroom";
	Locations[n].reload.l10.emerge = "reload11";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "#stown_name# port";
	Locations[n].reload.l10.disable = 1;			//never opened

	Locations[n].island = "Redmond";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "GB_Charleston_strongroom";
	locations[n].id.label = "Strongroom";
	//Town sack
	//Locations[n].townsack = "Charlestown";
	//Sound
	locations[n].type = "residence";
	//locations[n].fastreload = "Charlestown";

	Locations[n].filespath.models = "locations\Inside\Bank";
	Locations[n].image = "Inside_Bank.tga";
	//Models
	Locations[n].models.back = "..\back\inside_back_";
	//Always
	Locations[n].models.always.cave = "Bank";
	Locations[n].models.always.locators = "Bank_locators";
	Locations[n].models.always.window = "Bank_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Bank_patch";
	//Night
	Locations[n].models.night.charactersPatch = "Bank_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "GB_Charleston_usurerhouse";
	Locations[n].reload.l1.emerge = "reload1_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# port";

	Locations[n].island = "Redmond";
	n = n + 1;

//--------------------------------------------------------------------------

	locations[n].id = "Poe_entre";
	locations[n].id.label = "Poe's house";
	Locations[n].image = "GB_Poe_entre.tga";
	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
//	locations[n].type = "Rogers_residence";
//	locations[n].type = "Rogers_private";
//	locations[n].type = "silent_residence";
	locations[n].type = "Poe_home";

	//Models
	//Always
	locations[n].filespath.models = "locations\inside\largehouse01";
	locations[n].models.always.l1 = "largehouse01";
	Locations[n].models.always.l2 = "largehouse01_rand";
	Locations[n].models.always.l3 = "door_N03";
	locations[n].models.always.locators = "largehouse01_locators_GB";

	Locations[n].models.always.window = "largehouse01_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	
	//Day
	locations[n].models.day.charactersPatch = "largehouse01_patch";
	//Night
	locations[n].models.night.charactersPatch = "largehouse01_patch";
	//Environment
	locations[n].environment.weather = "false";
	locations[n].environment.sea = "false";
	Locations[n].models.back = "back\farm_";

	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "GB_Charleston_town";
	locations[n].reload.l1.emerge = "box14";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "";
	
	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Poe_bedroom";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "";

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "landlady_private";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "";
	Locations[n].reload.l3.disable = 1;			//opened from indise later

	Locations[n].locators_radius.box.box2 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "gatedoor_store4_wall";

	Locations[n].island = "Redmond";
	n = n + 1;

// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\JinoRoom";

	Locations[n].id = "landlady_private";
	locations[n].id.label = "Landlady private";
	Locations[n].image = "Inside_JinoRoom.tga";

	//Town sack
	Locations[n].townsack = "Grand Turk";

	//Sound
//	locations[n].type = "Rogers_residence";
//	locations[n].type = "Rogers_private";
//	locations[n].type = "silent_residence";
	locations[n].type = "Poe_home";
	
	//Models
	//Always
	Locations[n].models.always.locators = "JinoRoom_locators_GB";
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
	Locations[n].reload.l1.go = "Poe_entre";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 0.7;

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Poe_bedroom";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;
	
	Locations[n].locators_radius.box.box1 = 0.7;
	Locations[n].locators_radius.box.box2 = 1.1;
	Locations[n].locators_radius.box.box3 = 0.6;

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Turks"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	locations[n].id = "Poe_bedroom";
	locations[n].id.label = "Poe's bedroom";
	Locations[n].image = "GB_Poe_bedroom.tga";
	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
//	locations[n].type = "Rogers_private";
	locations[n].type = "Poe_home";
	
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\largehouse02_farm";
	locations[n].models.always.locators = "largehouse02_locators_GB_closed";	//_open later
	locations[n].models.always.l1 = "largehouse02";

	Locations[n].models.always.window = "largehouse02_windows";			//closed
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;			
	//Day
	locations[n].models.day.charactersPatch = "largehouse02_patch";
	//Night
	locations[n].models.night.charactersPatch = "largehouse02_patch";
	//Environment
	locations[n].environment.weather = "false";
	locations[n].environment.sea = "false";
	Locations[n].models.back = "back\farm_";

	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Poe_entre";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "";
	Locations[n].locators_radius.reload.reload1 = 0.5;

	locations[n].reload.l2.name = "reload2";					//opened later
	locations[n].reload.l2.go = "landlady_private";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;				

	Locations[n].locators_radius.goto.start = 1.3;
	Locations[n].locators_radius.box.box1 = 0.8;
	Locations[n].locators_radius.box.box2 = 0.7;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.box.box6 = 1.0;
	Locations[n].locators_radius.box.box7 = 0.5;
	Locations[n].locators_radius.goto.stay4 = 0.7;
	Locations[n].locators_radius.box.box8 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.0001;
	Locations[n].items.randitem1 = "EdgarPoe";	

	Locations[n].locators_radius.randitem.randitem2 = 0.0001;
	Locations[n].items.randitem2 = "book49";

	Locations[n].locators_radius.randitem.randitem3 = 0.0001;
	Locations[n].items.randitem3 = "armchair01";

	Locations[n].locators_radius.randitem.randitem4 = 0.0001;
	Locations[n].items.randitem4 = "chair";

	Locations[n].locators_radius.randitem.randitem5 = 0.0001;
	Locations[n].items.randitem5 = "bookshelf2";

	Locations[n].locators_radius.randitem.randitem6 = 0.0001;
	Locations[n].items.randitem6 = "bookcase";

	Locations[n].locators_radius.randitem.randitem7 = 0.0001;
	Locations[n].items.randitem7 = "carpet2";

	Locations[n].locators_radius.randitem.randitem8 = 0.0001;
	Locations[n].items.randitem8 = "books1";

	Locations[n].locators_radius.randitem.randitem9 = 0.0001;
	Locations[n].items.randitem9 = "FransHals";								

	Locations[n].locators_radius.randitem.randitem10 = 0.0001;
	Locations[n].items.randitem10 = "armchair01";

	Locations[n].locators_radius.randitem.randitem11 = 0.0001;
	Locations[n].items.randitem11 = "bookshelf2";

	Locations[n].locators_radius.randitem.randitem12 = 0.0001;
	Locations[n].items.randitem12 = "stool";

	Locations[n].locators_radius.randitem.randitem13 = 0.0001;
	Locations[n].items.randitem13 = "hatch11";

	Locations[n].locators_radius.randitem.randitem14 = 0.0001;
	Locations[n].items.randitem14 = "hatch11_O";

	Locations[n].locators_radius.randitem.randitem15 = 0.0001;
	Locations[n].items.randitem15 = "hatch11V";

	Locations[n].island = "Redmond";
	n = n + 1;

//--------------------------------------------------------------------------

	locations[n].id = "GB_Charleston_town_tavern";
	locations[n].id.label = "The Red Death";
	Locations[n].filespath.models = "locations\Inside\Tavern01";
	Locations[n].image = "Inside_Tavern01.tga";

	//Town sack
	//locations[n].townsack = "Eleuthera";

	//Sound
	//locations[n].type = "rogers_gunroom";
	locations[n].type = "tavern";

	//Models
	//Locations[n].models.back = "..\back\inside_back_";
	//Always
	Locations[n].models.always.cave = "Tavern01";
	Locations[n].models.always.locators = "Tavern01_locators_GB";
	Locations[n].models.always.window = "Tavern01_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Tavern01_patch";
	//Night
	Locations[n].models.night.charactersPatch = "Tavern01_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	//Locations[n].reload.l1.name = "reload1";
	//Locations[n].reload.l1.emerge = "reload4_back";
	//Locations[n].reload.l1.autoreload = "0";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "GB_Charleston_town";
	locations[n].reload.l2.emerge = "reload16";
	locations[n].reload.l2.autoreload = "0";
	
	Locations[n].island = "Eleuthera"; // NK 04-08-29	
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "GB_Charleston_riverhouse_stairs";
//	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house\\";
	Locations[n].image = "GB_small_stairs.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_private";
	
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F1_l_JRH";
	Locations[n].models.always.tavern = "LH_F1";
	Locations[n].models.always.window = "LF1_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "LH_F1_p";

	//Night
	Locations[n].models.night.charactersPatch = "LH_F1_p";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redlf2_";

	//Reload map
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "GB_Charleston_riverhouse";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;
	Locations[n].reload.l2.disable = 1;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "GB_Charleston_riverhouse_stairs";
	Locations[n].reload.l3.emerge = "reload4";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "GB_Charleston_town";
	Locations[n].reload.l4.emerge = "box22";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.3;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_N09";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "gatedoor_w";

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	locations[n].id = "GB_Charleston_riverhouse";
	locations[n].id.label = "Robert Cook and Maya";
	Locations[n].image = "stonehouse_inside.tga";

	//Sound
	locations[n].type = "military";

	//Models
	//Always
	locations[n].filespath.models = "locations\inside\ResidenceSmall2";
	locations[n].models.always.locators = "SmallResidence_locators";
	locations[n].models.always.house = "SmallResidence";
	locations[n].models.always.house.level = 65538;
	locations[n].models.always.window = "SmallResidence_windows";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;

	//Day
	locations[n].models.day.charactersPatch = "SmallResidence_patch";
	//Night
	locations[n].models.night.charactersPatch = "SmallResidence_patch";
	//Environment
	locations[n].environment.weather = "false";
	locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redb_";

	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "GB_Charleston_riverhouse_stairs";
	locations[n].reload.l1.emerge = "reload2"; 
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "";

	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "GB_Charleston_brothel1_stairs_in";
	locations[n].id.label = "To the Brothel";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house\\";
	Locations[n].filespath.textures = "locations\inside\Doubleflour_house\church_attic";
	Locations[n].image = "GB_small_stairs.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_private";
	
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F1_l_GB_Dupin";	//later LH_F1_l_GB_Dupin
	Locations[n].models.always.tavern = "LH_F1";
	Locations[n].models.always.window = "LF1_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "LH_F1_p";

	//Night
	Locations[n].models.night.charactersPatch = "LH_F1_p";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redlf2_";

	//Reload map
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "GB_Charleston_brothel1";
	Locations[n].reload.l2.emerge = "reload1";			//change this
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "GB_Charleston_brothel1_stairs";
	Locations[n].reload.l3.emerge = "reload4";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "GB_Charleston_town";
	Locations[n].reload.l4.emerge = "box7";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.3;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_N09";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.01;
//	Locations[n].items.randitem2 = "gatedoor_w";
	Locations[n].items.randitem2 = "gatedoor_attic_brick";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "door_N09";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "gatedoor_attic_brick";

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "GB_Charleston_brothel1_stairs_out";
	locations[n].id.label = "Exit";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house\\";
	Locations[n].filespath.textures = "locations\inside\Doubleflour_house\church_attic";
	Locations[n].image = "GB_small_stairs.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_private";
	
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F1_l_GB_Dupin";	//later LH_F1_l_GB_Dupin
	Locations[n].models.always.tavern = "LH_F1";
	Locations[n].models.always.window = "LF1_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "LH_F1_p";

	//Night
	Locations[n].models.night.charactersPatch = "LH_F1_p";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redlf2_";

	//Reload map
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "GB_Charleston_brothel1";
	Locations[n].reload.l2.emerge = "reload1";			//change this
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "GB_Charleston_brothel1_stairs_out";
	Locations[n].reload.l3.emerge = "reload4";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "GB_Charleston_town";
	Locations[n].reload.l4.emerge = "box7";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.3;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_N09";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.01;
//	Locations[n].items.randitem2 = "gatedoor_w";
	Locations[n].items.randitem2 = "gatedoor_attic_brick";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "door_N09";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "gatedoor_attic_brick";

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	locations[n].id = "GB_Charleston_brothel1";
	locations[n].id.label = "Charleston Brothel";
	locations[n].filespath.models = "locations\inside\Brothel";
	locations[n].image = "Inside_Brothel.tga";

	//Town sack
	locations[n].townsack = "Eleuthera";

	//Sound
//	locations[n].type = "Charleston_brothel";
	locations[n].type = "brothel";
//	locations[n].fastreload = "Eleuthera";
	//Models
	//Always
	locations[n].models.always.locators = "Brothel_locators";
	locations[n].models.always.store = "Brothel";
	locations[n].models.always.window = "Brothel_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 50;
	
	Locations[n].models.back = "..\back\inside_back_";

	//Day
	locations[n].models.day.charactersPatch = "Brothel_patch";

	//Night
	locations[n].models.night.charactersPatch = "Brothel_patch";

	//Environment
	locations[n].environment.weather = "false";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "GB_Charleston_brothel1_stairs_out";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	
	locations[n].reload.l10.name = "reload1_back";
	locations[n].reload.l10.go = "GB_Charleston_brothel1_room";
	locations[n].reload.l10.emerge = "reload1";
	locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.disable = 1;
	
	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "GB_Charleston_town";
	locations[n].reload.l2.emerge = "brothel_balcony";
	locations[n].reload.l2.autoreload = "0";

	LAi_LocationFightDisable(&locations[n], true);
    	Locations[n].island = "Eleuthera"; // NK 04-08-29	
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "GB_Charleston_brothel1_room";
	locations[n].id.label = "Bedroom";		
	Locations[n].image = "wr_mother.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_private";

	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\brothel_room";
	//Locations[n].models.always.locators = "brothel_room_locators";
	Locations[n].models.always.locators = "brothel_room_locators";
	Locations[n].models.always.tavern = "brothel_room";
	Locations[n].models.always.window = "Brothel_room_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Brothel_room_patch";

	//Night
	Locations[n].models.night.charactersPatch = "Brothel_room_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redb_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "GB_Charleston_brothel1";
	Locations[n].reload.l1.emerge = "reload1_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\outside\Plantation";
	Locations[n].id = "Bessop_plantation";
	locations[n].id.label = "Exit from Charleston";	//changed to "Bessop Plantation" when pchar has entered the plantation
	Locations[n].image = "Outside_Plantation.tga";

	//Town sack
	locations[n].townsack = "Eleuthera";

	//Sound
	locations[n].type = "Plantation";
	//locations[n].type = "night_sneaking";

	//Models
	//Always
	Locations[n].models.always.Plantation = "Plantation";
//   	Locations[n].models.always.gateopen = "Plantation_gateopen";
	Locations[n].models.always.gateopen = "Plantation_gateclouse";
    	Locations[n].models.always.reflect = "Plantation_reflect";
	Locations[n].models.always.grassPatch = "Plantation_grass";
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
//    	Locations[n].models.always.l4 = "plan4";
//	Locations[n].models.always.l4.level = 6;
//	Locations[n].models.always.l4.tech = "LocationModelBlend";

	//Day
	Locations[n].models.day.locators = "Plantation_l_GB_day";
//	Locations[n].models.day.charactersPatch = "Plantation_patchopen";
	Locations[n].models.day.charactersPatch = "Plantation_patchclouse";
	Locations[n].models.day.fonar = "Plantation_fd";
	
	//Night
	Locations[n].models.night.locators = "Plantation_l_GB_night";
//	Locations[n].models.night.charactersPatch = "Plantation_patchopen";
	Locations[n].models.night.charactersPatch = "Plantation_patchclouse";
	Locations[n].models.night.fonar = "Plantation_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0; // screwface

	//Reload map
	Locations[n].locators_radius.box.box3 = 0.0001;			//radius later = 1.0, to swamp
//Locations[n].locators_radius.box.box3 = 1.0;
	Locations[n].locators_radius.box.box7 = 2.0;
	Locations[n].locators_radius.box.box8 = 0.7;
	Locations[n].locators_radius.box.box9 = 0.7;
	Locations[n].locators_radius.box.box10 = 0.7;
	Locations[n].locators_radius.box.box11 = 0.7;
	Locations[n].locators_radius.box.box12 = 0.7;
	Locations[n].locators_radius.box.box13 = 0.7;
	Locations[n].locators_radius.box.box14 = 0.7;
	Locations[n].locators_radius.box.box15 = 0.0001;		//1.5 later, climb mountain
	Locations[n].locators_radius.box.box17 = 0.0001;
	Locations[n].locators_radius.box.box18 = 0.0001;
	Locations[n].locators_radius.box.box19 = 0.5;
	Locations[n].locators_radius.box.box20 = 0.5;
	Locations[n].locators_radius.box.box21 = 0.5;
	Locations[n].locators_radius.box.box22 = 0.5;
	Locations[n].locators_radius.box.box23 = 0.5;
	Locations[n].locators_radius.box.box24 = 0.5;
	Locations[n].locators_radius.box.box25 = 0.5;
	Locations[n].locators_radius.box.box26 = 0.5;
	Locations[n].locators_radius.box.box27 = 1.0;
	Locations[n].locators_radius.box.box28 = 1.0;
	Locations[n].locators_radius.box.box29 = 0.5;
	Locations[n].locators_radius.box.box30 = 0.5;
	Locations[n].locators_radius.box.box31 = 0.5;
	Locations[n].locators_radius.box.box32 = 0.5;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box33 = 0.5;
	Locations[n].locators_radius.box.box34 = 0.5;
	Locations[n].locators_radius.box.box35 = 0.5;
	Locations[n].locators_radius.box.box36 = 0.5;
	Locations[n].locators_radius.box.box37 = 0.5;
	Locations[n].locators_radius.box.box38 = 0.5;
	Locations[n].locators_radius.box.box39 = 0.5;
	Locations[n].locators_radius.box.box40 = 0.5;
	Locations[n].locators_radius.box.box41 = 0.5;
	Locations[n].locators_radius.box.box42 = 0.5;
	Locations[n].locators_radius.box.box43 = 0.5;
	Locations[n].locators_radius.box.box44 = 0.5;
	Locations[n].locators_radius.box.box45 = 0.5;
	Locations[n].locators_radius.box.box46 = 0.5;
	Locations[n].locators_radius.box.box47 = 0.5;
	Locations[n].locators_radius.box.box48 = 0.5;
	Locations[n].locators_radius.box.box49 = 0.5;
	Locations[n].locators_radius.box.box50 = 0.5;
	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box52 = 0.2;
	Locations[n].locators_radius.box.box53 = 0.5;
	Locations[n].locators_radius.box.box54 = 0.2;
	Locations[n].locators_radius.box.box55 = 0.5;
	Locations[n].locators_radius.box.box59 = 0.5;
	Locations[n].locators_radius.box.box60 = 0.5;
	Locations[n].locators_radius.box.box73 = 0.5;
	Locations[n].locators_radius.box.box74 = 0.5;
	Locations[n].locators_radius.box.box75 = 0.5;
	Locations[n].locators_radius.box.box76 = 0.5;
	Locations[n].locators_radius.box.box80 = 0.7;
	Locations[n].locators_radius.box.box81 = 0.7;
	Locations[n].locators_radius.box.box82 = 0.7;
	Locations[n].locators_radius.box.box84 = 0.7;
	Locations[n].locators_radius.box.box85 = 0.7;
	Locations[n].locators_radius.box.box86 = 0.7;
	Locations[n].locators_radius.box.box87 = 0.7;
	Locations[n].locators_radius.box.box88 = 0.7;
	Locations[n].locators_radius.box.box89 = 0.5;
	Locations[n].locators_radius.box.box90 = 0.5;
	Locations[n].locators_radius.box.box91 = 0.0001;			//0.7 after witch dialog

	Locations[n].locators_radius.goto.gate = 1.5;
	Locations[n].locators_radius.goto.goto11 = 5.0;
	Locations[n].locators_radius.goto.goto11A = 2.0;
	Locations[n].locators_radius.goto.goto11B = 5.0;
	Locations[n].locators_radius.goto.goto11C = 3.0;
	Locations[n].locators_radius.goto.goto26 = 5.0;
	Locations[n].locators_radius.goto.patrol2 = 5.0;		
	Locations[n].locators_radius.goto.barrack_in = 0.2;
	Locations[n].locators_radius.goto.barrack_out = 0.2;
	Locations[n].locators_radius.goto.barrack2_in = 0.2;
	Locations[n].locators_radius.goto.barrack2_out = 0.2;
	Locations[n].locators_radius.officers.reload14_3 = 2.0;
	Locations[n].locators_radius.goto.FW = 3.5;

	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "GB_Charleston_town";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# Port";

	Locations[n].reload.l3.name = "Reload3";
	Locations[n].reload.l3.go = "Charleston_swamp";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Jungle";

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Bessop_tavern";
	Locations[n].reload.l4.emerge = "reload3";
	Locations[n].reload.l4.autoreload = "0";
	//Locations[n].reload.l4.disable = 1;

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "Bessop_storeroom1";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	
	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "Bessop_storeroom4";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	//Locations[n].reload.l6.disable = 1;

	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "Bessop_storeroom2";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.disable = 1;

	Locations[n].reload.l8.name = "reload8";
	Locations[n].reload.l8.go = "Bessop_storeroom3";
	Locations[n].reload.l8.emerge = "reload1";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.disable = 1;

	Locations[n].reload.l9.name = "reload9";
	Locations[n].reload.l9.go = "Bessop_tavern";
	Locations[n].reload.l9.emerge = "arrive";
	Locations[n].reload.l9.autoreload = "0";
	//Locations[n].reload.l9.disable = 1;

	Locations[n].reload.l10.name = "reload10";
	Locations[n].reload.l10.go = "Bessop_storeroom1";
	Locations[n].reload.l10.emerge = "reload2";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].locators_radius.reload.reload10 = 0.4;

	Locations[n].reload.l11.name = "reload11";
	Locations[n].reload.l11.go = "Bessop_storeroom2";
	Locations[n].reload.l11.emerge = "reload2";
	Locations[n].reload.l11.autoreload = "0";
	Locations[n].locators_radius.reload.reload11 = 0.4;

	Locations[n].reload.l12.name = "reload12";
	Locations[n].reload.l12.go = "Bessop_storeroom2";
	Locations[n].reload.l12.emerge = "reload3";
	Locations[n].reload.l12.autoreload = "0";
	Locations[n].locators_radius.reload.reload12 = 0.4;

	Locations[n].reload.l13.name = "reload13";
	Locations[n].reload.l13.go = "Bessop_storeroom3";
	Locations[n].reload.l13.emerge = "reload2";
	Locations[n].reload.l13.autoreload = "0";
	Locations[n].locators_radius.reload.reload13 = 0.4;




	Locations[n].reload.l20.name = "houseSP1";
	Locations[n].reload.l20.go = "GB_closed_chinese_room";
	Locations[n].reload.l20.emerge = "reload1";
	Locations[n].reload.l20.autoreload = "0";
	Locations[n].reload.l20.disable = 1;

	Locations[n].reload.l21.name = "houseF1";
	Locations[n].reload.l21.go = "Bessop_tavern";
	Locations[n].reload.l21.emerge = "reload4";
	Locations[n].reload.l21.autoreload = "0";
	Locations[n].reload.l21.disable = 1;

	Locations[n].reload.l22.name = "houseS1";
	Locations[n].reload.l22.go = "GB_closed_chinese_room";
	Locations[n].reload.l22.emerge = "reload1";
	Locations[n].reload.l22.autoreload = "0";
	Locations[n].reload.l22.disable = 1;

	Locations[n].reload.l23.name = "houseF2";
	Locations[n].reload.l23.go = "Bessop_tavern";
	Locations[n].reload.l23.emerge = "reload2";
	Locations[n].reload.l23.autoreload = "0";
	Locations[n].reload.l23.disable = 1;

	Locations[n].reload.l24.name = "houseS2";
	Locations[n].reload.l24.go = "GB_closed_chinese_room";
	Locations[n].reload.l24.emerge = "reload1";
	Locations[n].reload.l24.autoreload = "0";
	Locations[n].reload.l24.disable = 1;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "ladder_big";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "door_barn";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "door_barn";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "door_barn";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "door_barn";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "door_barn";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "door_barn";

    	Locations[n].island = "Eleuthera"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	locations[n].id = "Bessop_storeroom1";
	//locations[n].id.label = "#stown_name# Brothel";
	locations[n].filespath.models = "locations\inside\dark_storeroom";
	locations[n].image = "GB_dark_storeroom.tga";

	//Town sack
	locations[n].townsack = "Eleuthera";

	//Sound
	locations[n].type = "silent_loghouse";
//	locations[n].fastreload = "Eleuthera";
	//Models
	//Always
	locations[n].models.always.locators = "dark_storeroom_l_GB1";
	locations[n].models.always.store = "dark_storeroom";
	
	//Day
	locations[n].models.day.charactersPatch = "dark_storeroom_p";

	//Night
	locations[n].models.night.charactersPatch = "dark_storeroom_p";

	//Environment
	locations[n].environment.weather = "false";
	locations[n].environment.sea = "false";

	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Bessop_plantation";
	locations[n].reload.l1.emerge = "reload5";
	locations[n].reload.l1.autoreload = "0";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Bessop_plantation";
	locations[n].reload.l2.emerge = "reload10";
	locations[n].reload.l2.autoreload = "0";
	
	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "door_PL";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "door_barn";

	LAi_LocationFightDisable(&locations[n], true);
    	Locations[n].island = "Eleuthera"; // NK 04-08-29	
	n = n + 1;

//--------------------------------------------------------------------------

	locations[n].id = "Bessop_storeroom2";
	//locations[n].id.label = "#stown_name# Brothel";
	locations[n].filespath.models = "locations\inside\dark_storeroom";
	locations[n].image = "GB_dark_storeroom.tga";

	//Town sack
	locations[n].townsack = "Eleuthera";

	//Sound
	locations[n].type = "silent_loghouse";
//	locations[n].fastreload = "Eleuthera";
	//Models
	//Always
	locations[n].models.always.locators = "dark_storeroom_l_GB2";
	locations[n].models.always.store = "dark_storeroom";
	
	//Day
	locations[n].models.day.charactersPatch = "dark_storeroom_p";

	//Night
	locations[n].models.night.charactersPatch = "dark_storeroom_p";

	//Environment
	locations[n].environment.weather = "false";
	locations[n].environment.sea = "false";

	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Bessop_plantation";
	locations[n].reload.l1.emerge = "reload7";
	locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.disable = 1;

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Bessop_plantation";
	locations[n].reload.l2.emerge = "reload11";
	locations[n].reload.l2.autoreload = "0";

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "Bessop_plantation";
	locations[n].reload.l3.emerge = "reload12";
	locations[n].reload.l3.autoreload = "0";
	
	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "door_PL";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "door_barn";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "door_barn";

	LAi_LocationFightDisable(&locations[n], true);
    	Locations[n].island = "Eleuthera"; // NK 04-08-29	
	n = n + 1;

//--------------------------------------------------------------------------

	locations[n].id = "Bessop_storeroom3";
	//locations[n].id.label = "#stown_name# Brothel";
	locations[n].filespath.models = "locations\inside\dark_storeroom";
	locations[n].image = "GB_dark_storeroom.tga";

	//Town sack
	locations[n].townsack = "Eleuthera";

	//Sound
	locations[n].type = "silent_loghouse";
//	locations[n].fastreload = "Eleuthera";
	//Models
	//Always
	locations[n].models.always.locators = "dark_storeroom_l_GB2";
	locations[n].models.always.store = "dark_storeroom";
	
	//Day
	locations[n].models.day.charactersPatch = "dark_storeroom_p";

	//Night
	locations[n].models.night.charactersPatch = "dark_storeroom_p";

	//Environment
	locations[n].environment.weather = "false";
	locations[n].environment.sea = "false";

	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Bessop_plantation";
	locations[n].reload.l1.emerge = "reload8";
	locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.disable = 1;

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Bessop_plantation";
	locations[n].reload.l2.emerge = "reload13";
	locations[n].reload.l2.autoreload = "0";

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "Bessop_plantation";
	locations[n].reload.l3.emerge = "box73";
	locations[n].reload.l3.autoreload = "0";
	
	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "door_PL";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "door_barn";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "door_barn";

	LAi_LocationFightDisable(&locations[n], true);
    	Locations[n].island = "Eleuthera"; // NK 04-08-29	
	n = n + 1;

//--------------------------------------------------------------------------

	locations[n].id = "Bessop_storeroom4";
	//locations[n].id.label = "#stown_name# Brothel";
	locations[n].filespath.models = "locations\inside\dark_storeroom";
	locations[n].image = "GB_dark_storeroom.tga";

	//Town sack
	locations[n].townsack = "Eleuthera";

	//Sound
	locations[n].type = "silent_loghouse";
//	locations[n].fastreload = "Eleuthera";
	//Models
	//Always
	locations[n].models.always.locators = "dark_storeroom_l_GB4";
	locations[n].models.always.store = "dark_storeroom";
	
	//Day
	locations[n].models.day.charactersPatch = "dark_storeroom_p";

	//Night
	locations[n].models.night.charactersPatch = "dark_storeroom_p";

	//Environment
	locations[n].environment.weather = "false";
	locations[n].environment.sea = "false";

	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Bessop_plantation";
	locations[n].reload.l1.emerge = "reload6";
	locations[n].reload.l1.autoreload = "0";

	locations[n].reload.l4.name = "reload4";
	locations[n].reload.l4.go = "Bessop_plantation";
	locations[n].reload.l4.emerge = "box74";
	locations[n].reload.l4autoreload = "0";
	
	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "door_PL";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "door_barn";

	LAi_LocationFightDisable(&locations[n], true);
    	Locations[n].island = "Eleuthera"; // NK 04-08-29	
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Bessop_tavern";
	locations[n].id.label = "Guards only";	
	Locations[n].filespath.models = "locations\inside\Tavern_2";
	Locations[n].image = "GB_Bessop_tavern.tga";

	//Town sack
	Locations[n].townsack = "Havana";

	//Sound
	locations[n].type = "silent_residence";
	//locations[n].type = "Moultrie_restaurant";
	//locations[n].type = "brothel_QC";

	//Models
	//Always
	Locations[n].models.always.tavern = "Tavern_2";
	Locations[n].models.always.locators = "Tavern_2_l_bessop";
	//Day
	Locations[n].models.day.charactersPatch = "Tavern_2_p";

	//Night
	Locations[n].models.night.charactersPatch = "Tavern_2_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\SMUMH_";	
	//Reload map
	Locations[n].locators_radius.box.box1 = 0.7;
	Locations[n].locators_radius.box.box2 = 0.7;
	Locations[n].locators_radius.box.box3 = 0.5;

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Bessop_plantation";
	Locations[n].reload.l1.emerge = "reload9";
	Locations[n].reload.l1.autoreload = "1";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Bessop_plantation";
	Locations[n].reload.l2.emerge = "houseF2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.disable = 1;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Bessop_plantation";
	Locations[n].reload.l3.emerge = "reload4";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].locators_radius.reload.reload3 = 1.0;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Bessop_plantation";
	Locations[n].reload.l4.emerge = "houseF1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.disable = 1;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "gatedoor_plantation";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "door_largeh";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "door_largeh";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "door_largeh";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "door_largeh";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "door_largeh";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "door_largeh";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "door_largeh";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_5";
	Locations[n].id = "Charleston_swamp";
	locations[n].id.label = "Charleston swamp";
	Locations[n].image = "GB_swamp.tga";
	//Sound
	locations[n].type = "silent_seashore";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "Jungle05_l_GB";
	//Locations[n].models.always.jungle = "Jungle05";
	Locations[n].models.always.jungle = "jungle05_signless";
	Locations[n].models.always.grassPatch = "JUNGLE05_g";
	//Locations[n].models.always.l1 = "plan_1";
	//Locations[n].models.always.l1.level = 9;
	//Locations[n].models.always.l1.tech = "LocationModelBlend";
	//Locations[n].models.always.l2 = "plan_2";
	//Locations[n].models.always.l2.level = 8;
	//Locations[n].models.always.l2.tech = "LocationModelBlend";
	//Locations[n].models.always.l3 = "plan_3";
	//Locations[n].models.always.l3.level = 7;
	//Locations[n].models.always.l3.tech = "LocationModelBlend";

	//Day
	Locations[n].models.day.charactersPatch = "Jungle05_p";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle05_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.1;
	//Reload map
	Locations[n].reload.l5.name = "reload1_back";
	Locations[n].reload.l5.go = "Charleston_swamp_end";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Bessop_plantation";
	Locations[n].reload.l6.emerge = "reload14";		//was goto box3
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 3;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "jungle";				

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_Church";
	Locations[n].id = "Charleston_swamp_end";
	locations[n].id.label = "Charleston swamp";
	Locations[n].image = "GB_loghouse_outside.tga";
	//Sound
	locations[n].type = "silent_seashore";
	//Models
	//Always
	Locations[n].models.always.locators = "Rhouse_l_GB";
	Locations[n].models.always.house = "Rhouse";
	Locations[n].models.always.grassPatch = "Rhouse_g";
//	Locations[n].models.always.l1 = "rhouse_b01";
//	Locations[n].models.always.l1.level = 9;
//	Locations[n].models.always.l1.tech = "LocationModelBlend";
//	Locations[n].models.always.l2 = "rhouse_b02";
//	Locations[n].models.always.l2.level = 8;
//	Locations[n].models.always.l2.tech = "LocationModelBlend";
//	Locations[n].models.always.l3 = "rhouse_b03";
//	Locations[n].models.always.l3.level = 7;
//	Locations[n].models.always.l3.tech = "LocationModelBlend";
//	Locations[n].models.always.l4 = "rhouse_b04";
//	Locations[n].models.always.l4.level = 6;
//	Locations[n].models.always.l4.tech = "LocationModelBlend";

	locations[n].vcskip = true; // PB
	//Day
	Locations[n].models.day.charactersPatch = "Rhouse_p";
	//Night
	Locations[n].models.night.charactersPatch = "Rhouse_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.2;
	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Charleston_swamp";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 3;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Swamp_loghouse";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.7;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "mill_destroyed";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "door_N06";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "chimney_pot";

	LAi_LocationMonstersGen(&locations[n], false);
//	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------
	
	Locations[n].id = "Swamp_loghouse";
	locations[n].id.label = "Log-house";
	Locations[n].image = "GB_loghouse.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "silent_loghouse";

	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Smallhome";
	Locations[n].filespath.textures = "locations\inside\Smallhome\loghouse";

	Locations[n].models.always.city = "sh";
	Locations[n].models.always.locators = "sh_l_GB_loghouse";
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
//	Locations[n].models.back = "back\farm_";

	//Reload map
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Charleston_swamp_end";
	Locations[n].reload.l2.emerge = "reload3";			//was goto9, reload2
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Charleston swamp";
	Locations[n].locators_radius.reload.reload2 = 0.7;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Loghouse_stairs";
	Locations[n].reload.l3.emerge = "stairs";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 1.6;
	Locations[n].reload.l3.disable = 1;
				
	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "hatch11V";			//cover one window

	Locations[n].locators_radius.randitem.randitem2 = 0.1;			
	Locations[n].items.randitem2 = "door_N06";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;		
	Locations[n].items.randitem3 = "door_N06";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Loghouse_stairs";
	//locations[n].id.label = "Loghouse stairs";				//when opened			
	Locations[n].filespath.models = "locations\inside\Doubleflour_house\\";
	Locations[n].filespath.textures = "locations\inside\Doubleflour_house\chapel";
	Locations[n].image = "GB_hideout_stairs.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "silent_loghouse";		
	
	//Models
	//Always
	Locations[n].models.always.locators = "lh_F1_l_GB_maroon";
	Locations[n].models.always.tavern = "LH_F1";
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
	Locations[n].models.back = "back\redlf2_";

	//Reload map
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Swamp_loghouse";
	Locations[n].reload.l2.emerge = "goto3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Loghouse_stairs";
	Locations[n].reload.l3.emerge = "box2";				//was reload4
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].locators_radius.box.box2 = 0.3;			//instead of reload4

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_N06";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "gatedoor_Mine";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "gateroof_wood";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "gatedoor_w";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "ladder_big";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "hatch11D";

	Locations[n].items.randitem7 = "";

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Cave_Ship"; // SD

	Locations[n].id = "Maroon_hideout";
	locations[n].id.label = "Maroon Hideout";
	Locations[n].image = "Inside_Cave_Ship.tga";

	//Town sack
	locations[n].townsack = "Khael Roa"; // Screwface : to be allowed berth ships here

	//Sound
	locations[n].type = "KhaelRoa";
	Locations[n].island = "KhaelRoa"; // NK 04-11-03
	//Models
	//Always
	Locations[n].models.always.locators = "Cave_Ship_l_GB_box";
	Locations[n].models.always.l1 = "Cave_Ship";
	Locations[n].models.always.l2 = "Cave_Ship_add1";
	//Day
	Locations[n].models.day.charactersPatch = "Cave_Ship_p";
	//Night
	Locations[n].models.night.charactersPatch = "Cave_Ship_p";
	//Environment
	locations[n].lockWeather = "Inside";
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.2; 			//was 0.0

	//Reload map
	Locations[n].locators_radius.reload.reload3 = 0.0001;

	Locations[n].locators_radius.box.box1 = 0.7;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.2;
	Locations[n].locators_radius.box.box4 = 0.2;
	Locations[n].locators_radius.box.box5 = 0.2;
	Locations[n].locators_radius.box.box6 = 0.2;
	Locations[n].locators_radius.box.box7 = 0.2;
	Locations[n].locators_radius.box.box8 = 0.2;
	Locations[n].locators_radius.box.box9 = 0.2;
	Locations[n].locators_radius.box.box10 = 1.5;
	Locations[n].locators_radius.box.box11 = 0.2;			//on raft
	Locations[n].locators_radius.box.box12 = 0.0001;		//to raft 1.0 later on
	Locations[n].locators_radius.box.box13 = 0.2;			//on raft

	Locations[n].locators_radius.goto.steplock = 0.0001;		//0.5 when box is gone
	Locations[n].locators_radius.goto.box = 0.7;			//small when box is gone
	
	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_NGR";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "bookshelf";			//hiding the secret exit, temp off

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "bookshelf";			//high up

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "steplock";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "door_M11";			//from cabin

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "door_M11";			//from secret passage

	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "gatedoor_BRI";

	Locations[n].locators_radius.randitem.randitem8 = 0.1;
	Locations[n].items.randitem8 = "box";

	Locations[n].locators_radius.randitem.randitem9 = 0.1;
	Locations[n].items.randitem9 = "hammock";

	Locations[n].locators_radius.randitem.randitem10 = 0.1;
	Locations[n].items.randitem10 = "hammock";

	Locations[n].locators_radius.randitem.randitem11 = 0.1;
	Locations[n].items.randitem11 = "hammock";

	Locations[n].locators_radius.randitem.randitem12 = 0.1;
	Locations[n].items.randitem12 = "hammock";

	Locations[n].locators_radius.randitem.randitem13 = 0.1;
	Locations[n].items.randitem13 = "hammock";

	Locations[n].locators_radius.randitem.randitem14 = 0.1;
	Locations[n].items.randitem14 = "hammock";

	Locations[n].locators_radius.randitem.randitem15 = 0.1;
	Locations[n].items.randitem15 = "hammock";

	Locations[n].locators_radius.randitem.randitem16 = 0.1;
	Locations[n].items.randitem16 = "hammock";

	Locations[n].items.randitem17 = "key30";

	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Passage";

	Locations[n].id = "Charleston_passage";
	locations[n].id.label = "Charleston passage";
	Locations[n].image = "Outside_Passage2.tga";
	//Sound
	locations[n].type = "silent_seashore";
	//locations[n].type = "deserted_seashore";

	//Models
	//Always
	Locations[n].models.always.locators = "pass2_l_GB";
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

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Charleston_swamp";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload2 = 2.0;
	Locations[n].reload.l2.label = "Jungle.";
	
	Locations[n].locators_radius.goto.weather = 1.5;
	Locations[n].locators_radius.box.box2 = 1.7;			//instead of reload1
	Locations[n].locators_radius.goto.maroon_stop = 6.0;
	Locations[n].locators_radius.goto.maroon_ohoh = 2.5;
	Locations[n].locators_radius.goto.maroon_prep = 3.5;	

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "gatedoor_w8";
	
	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "IslaMuelle"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\CavernMedium";

	Locations[n].id = "Maroon_Cavern";
	locations[n].id.label = "Maroon Cavern";
	Locations[n].image = "Inside_cavernMedium.tga";

	//Sound
	//locations[n].type = "cave";
	//locations[n].type = "Rogers_jail";
	locations[n].type = "galleon_closed";
	//Models
	//Always
	Locations[n].models.always.locators = "CavernMedium_locators_GB_flooded";
	Locations[n].models.always.l1 = "CavernMedium";
	//Locations[n].models.always.l2 = "Crystals";
	//Locations[n].models.always.l2.tech = "EnvironmentShader";
	//Locations[n].models.always.l2.reflection = 0.25;
	Locations[n].models.always.l3 = "cavernMedium_lamps";
	Locations[n].models.always.l4 = "ladder_bottom";	//ladder_bottom or ""	
	Locations[n].models.always.l5 = "barrelA";		//barrelA, B or C    -"-
	Locations[n].models.always.l6 = "";			//ladder_wall,_ladder_rope or ""
	Locations[n].models.always.l7 = "bottleA_cork";		//bottleA, bottleA_cork, also for B & C

//Locations[n].models.always.l20 = "barrelB";			//testing
//Locations[n].models.always.l21 = "barrelC";			//testing
//Locations[n].models.always.l22 = "bottleB";		//testing
//Locations[n].models.always.l23 = "bottleC";		//testing



	/*
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
	*/
	//Day
	Locations[n].models.day.charactersPatch = "CavernMedium_patch";
	//Night
	Locations[n].models.night.charactersPatch = "CavernMedium_patch";
	//Environment
	//locations[n].lockWeather = "Inside";		//no effect
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.15;		//was 0.2

	//Reload map

	Locations[n].locators_radius.box.box4 = 0.9;	
	Locations[n].locators_radius.box.box5 = 1.5;		//instead of reload1
	Locations[n].locators_radius.box.box6 = 1.5;		//instead of reload3
	Locations[n].locators_radius.box.box7 = 1.5;		//instead of reload4
	Locations[n].locators_radius.box.box8 = 0.001;		//0.7 later when ladder can be picked up
	
	Locations[n].locators_radius.box.box9 = 0.5;		//push barrelA
	Locations[n].locators_radius.box.box10 = 0.001;		//push barrelC
	Locations[n].locators_radius.box.box11 = 0.5;		//tap barrelA
	Locations[n].locators_radius.box.box12 = 0.001;		//tap barrelB
	Locations[n].locators_radius.box.box13 = 0.001;		//tap barrelC
	Locations[n].locators_radius.box.box14 = 0.001;		//middle of the stuck ladder 1.0 later

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "gatedoor_w8";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "gatedoor_w8";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "gatedoor_wN";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "gatedoor_wR";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "steplock2";			//brighter
	
	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "steplock";			//normal, darker

	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "gatefloor_cavern";

	Locations[n].locators_radius.randitem.randitem8 = 0.01;
	Locations[n].items.randitem8 = "gatefloor_cavern";

	Locations[n].island = "Eleuthera";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Passage";

	Locations[n].id = "Charleston_shore";
	locations[n].id.label = "Charleston shore";
	Locations[n].image = "Outside_Passage1.tga";
	//Sound
	locations[n].type = "silent_seashore";
	//locations[n].type = "deserted_seashore";
	//Models
	//Always
	Locations[n].models.always.locators = "Pass1_l_GB";
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
	Locations[n].models.always.l4 = "bars_down";			//bars_down, bars_up & bars_stuck
	Locations[n].models.always.l5 = "";				//rope_gibbet or ""
	Locations[n].models.always.l6 = "";				//plank2A later
	Locations[n].models.always.l7 = "plank2B";			//plank2B, plank_gate or ""
	Locations[n].models.always.l8 = "";				//lever_up, lever_down, lever_ground or ""
	Locations[n].models.always.l9 = "";				//ladder_rope, ladder_gibbet or ladder_lever	
	Locations[n].models.always.l10= "wood_step1";			//wood_step1 or ""
	Locations[n].models.always.l11= "wood_step2";			//wood_step2
	
	//Day
	Locations[n].models.day.charactersPatch = "Pass1_p";
	//Night
	Locations[n].models.night.charactersPatch = "Pass1_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	//Reload map

	Locations[n].locators_radius.box.box8 = 0.001;			//0.5 later
	Locations[n].locators_radius.box.box14 = 0.001;			//large later	
	Locations[n].locators_radius.box.box16 = 0.5;
	Locations[n].locators_radius.box.box17 = 0.001;			//0.5 later
	Locations[n].locators_radius.box.box18 = 0.5;
	Locations[n].locators_radius.box.box20 = 0.3;
	Locations[n].locators_radius.box.box25 = 0.5;
	Locations[n].locators_radius.box.box26 = 0.5;
	Locations[n].locators_radius.box.box27 = 0.5;
	Locations[n].locators_radius.box.box28 = 0.5;
	Locations[n].locators_radius.box.box30 = 0.001;			//0.5 later
	Locations[n].locators_radius.box.box31 = 0.001;			//0.6 later
	Locations[n].locators_radius.box.box32 = 0.8;			//0.8 from start
	Locations[n].locators_radius.box.box33 = 0.5;
	Locations[n].locators_radius.box.box34 = 0.5;
	Locations[n].locators_radius.box.box35 = 0.001;			//0.5 later
	Locations[n].locators_radius.box.box36 = 0.5;
	Locations[n].locators_radius.box.box37 = 0.5;
	Locations[n].locators_radius.box.box38 = 0.001;			//0.8 later
	Locations[n].locators_radius.box.box39 = 0.001;			//0.6 later
	Locations[n].locators_radius.box.box40 = 0.0001;		//1.5 later, instead of reload1
	Locations[n].locators_radius.box.box41 = 0.3;
	Locations[n].locators_radius.box.box42 = 0.3;
	Locations[n].locators_radius.box.box44 = 0.0001;		//1.5 later, to raft pos 2
	Locations[n].locators_radius.box.box45 = 0.001;			//1.5 later
	Locations[n].locators_radius.goto.fall1 = 0.6;
	Locations[n].locators_radius.goto.fall2 = 0.6;
	Locations[n].locators_radius.goto.stop_bars = 1.0;
	Locations[n].locators_radius.goto.falling_lever = 1.0;
	Locations[n].locators_radius.goto.other_side = 1.0;
	Locations[n].locators_radius.goto.attack = 22.0;
	Locations[n].locators_radius.goto.goto4A = 2.0;
	Locations[n].locators_radius.officers.reload3_1 = 1.0;
	Locations[n].locators_radius.goto.4A_look = 0.1;
	Locations[n].locators_radius.goto.4_look = 0.1;
	Locations[n].locators_radius.quest.greeting = 5.0;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "steplock_v";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "gatedoor_w8";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "fence";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "fence";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "fence";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "fence";

	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "gibbet";

	Locations[n].locators_radius.randitem.randitem8 = 0.01;
	Locations[n].items.randitem8 = "fence";

	Locations[n].locators_radius.randitem.randitem9 = 0.01;
	Locations[n].items.randitem9 = "hatch11_O";

	Locations[n].locators_radius.randitem.randitem10 = 0.01;
	Locations[n].items.randitem10 = "hatch11_T";

	Locations[n].locators_radius.randitem.randitem11 = 0.01;
	Locations[n].items.randitem11 = "stonebox";

	Locations[n].locators_radius.randitem.randitem12 = 0.01;
	Locations[n].items.randitem12 = "plank1_long";

	Locations[n].locators_radius.randitem.randitem13 = 0.01;
	//Locations[n].items.randitem13 = "wood_step";			//not used

	Locations[n].locators_radius.randitem.randitem14 = 0.01;
	//Locations[n].items.randitem14 = "wood_step";			//not used

	Locations[n].locators_radius.randitem.randitem15 = 0.01;
	Locations[n].items.randitem15 = "tree2";

	Locations[n].items.randitem16 = "pole3_small";
	
	//LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "IslaMuelle"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Bishops_Hostel";
	locations[n].id = "Bishops_Hostel";
	locations[n].id.label = "Bishops Hostel";
	Locations[n].image = "GB_Bishops_hostel.tga";
	//Town sack
	Locations[n].townsack = "Quebradas Costillas"; // KK
	//Sound
	locations[n].type = "deserted_seashore";
	
	//locations[n].fastreload = "QC";
	LAi_LocationMonstersGen(&locations[n], false);
	
	//Models
	//Always
	Locations[n].models.always.locators = "locator_BH1";
	Locations[n].models.always.exit = "1510001";
	Locations[n].models.always.l1 = "trees";
	Locations[n].models.always.l2= "wood_step1";
	Locations[n].models.always.l3= "wood_step2";
	Locations[n].models.always.l4= "wood_step3";
//	Locations[n].models.always.l5= "stake1A";		//stake1A near
//	Locations[n].models.always.l6= "stake1B";		//stake1B far	
//	Locations[n].models.always.l7= "stake2A";		//stake2A near
//	Locations[n].models.always.l8= "stake2B";		//stake2B far
//	Locations[n].models.always.l9= "rope_up";		//rope_up or _down	
//	locations[n].models.always.l10 = "goldbug_up";		//goldbug_up or _down
//	locations[n].models.always.l11 = "ground1";		//ground1 first
//	locations[n].models.always.l12 = "pile1A_large";	//pile1A_small or pile1A_large
//	locations[n].models.always.l13 = "pile1B_large";	//pile1B_small or pile1B_large
//	locations[n].models.always.l14 = "ground2";		//ground2 second
//	locations[n].models.always.l15 = "pile2A_large";	//pile2A_small or pile2A_large
//	locations[n].models.always.l16 = "pile2B_large";	//pile2B_small or pile2B_large
//	locations[n].models.always.l17 = "bone";		//bone
//	locations[n].models.always.l18 = "chest_free";		//chest_buried, _locked, _open, _free
	

	
	//Day
	Locations[n].models.day.charactersPatch = "walk_patch_p";
	//Night
	Locations[n].models.night.charactersPatch = "walk_patch_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
//Locations[n].environment.weather = "false";
//Locations[n].environment.sea = "false";

	//Reload map
/*	
	Locations[n].reload.l2.name = "Reload2";
	Locations[n].reload.l2.go = "Charleston_shore";
	Locations[n].reload.l2.emerge = "box7";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload2 = 6.0;
*/
	Locations[n].reload.l4.name = "Reload4";
	Locations[n].reload.l4.go = "Bishops_Hostel";
	Locations[n].reload.l4.emerge = "devils_seat";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "#stown_name#.";
	
	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "rope_ale";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "rope_vertical_long";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;		
	Locations[n].items.randitem3 = "walk_plank_180";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "lever_item";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;		
	Locations[n].items.randitem5 = "lever_item";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;		
	Locations[n].items.randitem6 = "tree3";				//big tulip-tree

	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "bladeskull1";

	Locations[n].locators_radius.randitem.randitem8 = 0.01;		//not used
//	Locations[n].items.randitem8 = "";

	Locations[n].locators_radius.randitem.randitem9 = 0.01;		
	Locations[n].items.randitem9 = "wood_pier";

	Locations[n].locators_radius.randitem.randitem10 = 0.01;
	Locations[n].items.randitem10 = "ladder_very_big";

	Locations[n].locators_radius.randitem.randitem11 = 0.01;
	Locations[n].items.randitem11 = "ladder_very_big2";

	Locations[n].locators_radius.randitem.randitem12 = 0.01;
	Locations[n].items.randitem12 = "devils_seat";

	Locations[n].locators_radius.randitem.randitem13 = 0.01;
	Locations[n].items.randitem13 = "ladder_very_big";

	Locations[n].locators_radius.randitem.randitem14 = 0.01;
	Locations[n].items.randitem14 = "wood_pier";

	Locations[n].locators_radius.randitem.randitem15 = 0.01;
	Locations[n].items.randitem15 = "ladder_very_big2";

	Locations[n].locators_radius.randitem.randitem16 = 0.01;
	Locations[n].items.randitem16 = "wood_pier";

	Locations[n].locators_radius.randitem.randitem17 = 0.01;		
	Locations[n].items.randitem17 = "walk_plank";

	Locations[n].locators_radius.box.box1 = 3.0;
	Locations[n].locators_radius.box.box3 = 3.0;
	Locations[n].locators_radius.box.box11 = 0.2;
	Locations[n].locators_radius.box.box12 = 0.2;
	Locations[n].locators_radius.box.box14 = 0.2;
	Locations[n].locators_radius.box.box15 = 0.2;
	Locations[n].locators_radius.box.box16 = 0.2;
	Locations[n].locators_radius.box.box20 = 6.0;
	Locations[n].locators_radius.box.box37 = 0.2;
	Locations[n].locators_radius.box.box49 = 0.2;
	Locations[n].locators_radius.box.box50 = 0.2;
	Locations[n].locators_radius.box.box54 = 0.001;			//to the raft
	Locations[n].locators_radius.box.box55 = 0.2;			//raft departure
	Locations[n].locators_radius.box.box56 = 0.001;			//goldbug on ground
	Locations[n].locators_radius.box.box57 = 0.001;			//at skeletons
	Locations[n].locators_radius.box.box58 = 0.2;			//to the boat & raft
	Locations[n].locators_radius.box.box59 = 0.001;			//to place sacks in boat
	Locations[n].locators_radius.goto.look_rock = 10.0;
	Locations[n].locators_radius.goto.look_rockB = 5.0;
	Locations[n].locators_radius.goto.look_rockC = 7.0;
	Locations[n].locators_radius.goto.tree_base = 7.0;
	Locations[n].locators_radius.officers.L_hole1_1 = 0.001;	//2.0 later
	Locations[n].locators_radius.officers.L_hole2_1 = 0.001;		//2.0 later

	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

}
