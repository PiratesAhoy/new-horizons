void LocationInitHispaniola(ref n)
{
	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Shore_9";

	Locations[n].id = "Hispaniola_shore_03";
	locations[n].id.label = "Cape Francos."; // KK
	locations[n].worldmap = "HiShore 3";
	Locations[n].image = "Outside_Shore_9.tga";
	Locations[n].name = "Cape Francos"; 		// TALISMAN added to make beach name appear in smuggler tavern dialog
	//Sound
	locations[n].type = "seashore";

	//Models
	//Always
	Locations[n].models.always.locators = "Shore09_l";
	Locations[n].models.always.shore = "Shore09";
	Locations[n].models.always.shore.foam = "1";
	Locations[n].models.always.seabed = "Shore09_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "Shore09_g";
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
	Locations[n].models.day.charactersPatch = "Shore09_p";
	//Night
	Locations[n].models.night.charactersPatch = "Shore09_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "locator3";
	Locations[n].reload.l1.go = "Hispaniola_Jungle_07";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.locator3 = 2.0;

	Locations[n].reload.l3.name = "locator3_back";
	Locations[n].reload.l3.go = "Hispaniola_Jungle_07";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.locator3_back = 2.0;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Hispaniola";
	Locations[n].reload.l2.emerge = "reload_5";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 9.0;

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Jungle_2";

	Locations[n].id = "Hispaniola_Jungle_07";
	locations[n].id.label = "Jungle";
	Locations[n].image = "Outside_Jungle_2.tga";
	//Sound
	locations[n].type = "Jungle";
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
	Locations[n].reload.l1.go = "Hispaniola_shore_03";
	Locations[n].reload.l1.emerge = "locator3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Cape Francos.";
	Locations[n].locators_radius.reload.reload1 = 4;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Hispaniola_shore_03";
	Locations[n].reload.l4.emerge = "locator3";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Cape Francos.";
	Locations[n].locators_radius.reload.reload1_back = 4;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Hispaniola_Jungle_09";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 4;

	Locations[n].reload.l5.name = "reload2_back";
	Locations[n].reload.l5.go = "Hispaniola_Jungle_09";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Hispaniola_Temple";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3 = 4;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Hispaniola_Temple";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 4;

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Hispaniola_Temple";
	Locations[n].filespath.models = "locations\Incas Temple\Temple"; // qf"
	//Sound
	locations[n].type = "jungle";
	locations[n].ambush = true;
	Locations[n].image = "Incas_Temple_Temple.tga";
	locations[n].id.label = "Temple";
	//Models
	//Always
	Locations[n].models.always.locators = "hram_l";
	Locations[n].models.always.l1 = "Hram";
	Locations[n].models.always.grasspatch = "hram_g";	
	//Day
	Locations[n].models.day.charactersPatch = "Hram_p";
	Locations[n].models.day.jumppatch = "hram_j";
	//Night
	Locations[n].models.night.charactersPatch = "Hram_p";
	Locations[n].models.night.jumppatch = "hram_j";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Hispaniola_Jungle_07";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Hispaniola_Jungle_07";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 3;
/*
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Hispaniola_Labirint_1";
	Locations[n].reload.l2.emerge = "reload27";
	Locations[n].reload.l2.autoreload = "1";
*/
	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Cave Entrance";

	Locations[n].id = "Hispaniola_Jungle_09";
	locations[n].id.label = "Cave entrance";
	Locations[n].image = "Outside_Cave_Entrance.tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].ambush = true;
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
	Locations[n].reload.l3.go = "Hispaniola_Grot2";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Cave.";
	Locations[n].locators_radius.reload.Reload1 = 1;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Hispaniola_Grot2";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Cave.";
	Locations[n].locators_radius.reload.Reload1_back = 1.3;

	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Hispaniola_Jungle_07";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2 = 2.0;

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Hispaniola_Jungle_07";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 2.0;

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Cavern";

	Locations[n].id = "Hispaniola_Grot2";
	locations[n].id.label = "Cavern";
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
	Locations[n].reload.l1.go = "Hispaniola_Jungle_09";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Hispaniola_Jungle_09";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Hispaniola_passage";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Passage";

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Hispaniola_passage";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Passage";
	Locations[n].locators_radius.reload.reload2_back = 2;

	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 0, 24);

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Passage";

	Locations[n].id = "Hispaniola_passage";
	locations[n].id.label = "Passage";
	Locations[n].image = "Outside_Passage2.tga";
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
	Locations[n].reload.l1.go = "Hispaniola_shore_05";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	//Locations[n].locators_radius.reload.reload2 = 2.0;
	Locations[n].reload.l1.label = "Shore.";
	Locations[n].reload.l1.disable = 1;	

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Hispaniola_shore_05";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload2 = 2.0;
	Locations[n].reload.l2.label = "Shore.";
	Locations[n].reload.l2.disable = 1;	

	Locations[n].reload.l3.name = "reload1";
	Locations[n].reload.l3.go = "Hispaniola_Grot2";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Cavern";
	Locations[n].locators_radius.reload.reload1 = 2.0;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Hispaniola_Grot2";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Cavern";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l5.name = "reload9";
	Locations[n].reload.l5.go = "Hispaniola_Grot3";
	Locations[n].reload.l5.emerge = "monster4";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 1.0;
	Locations[n].reload.l5.label = "Hidden Cave.";

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Shore_5";

	Locations[n].id = "Hispaniola_shore_05";
	locations[n].id.label = "Playa del Muerte"; // KK
	Locations[n].image = "Outside_Shore_5.tga";
	Locations[n].name = "Playa del muerte";

	//Sound
	locations[n].type = "seashore";

	//Models
	//Always
	Locations[n].models.always.jungle = "Shore05";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.locators = "Shore05_l_x";
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
	Locations[n].reload.l1.go = "Hispaniola_passage";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 3;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Hispaniola_passage";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3;

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	//-------------------------------------------------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Grot";

	Locations[n].id = "Hispaniola_Grot3";
	locations[n].id.label = "Hidden Cave";
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
	Locations[n].reload.l1.go = "Hispaniola_Grot2";
	Locations[n].reload.l1.emerge = "monster7";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Cave.";

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Hispaniola_Grot2";
	Locations[n].reload.l2.emerge = "monster7";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Cave.";
	Locations[n].locators_radius.reload.reload1_back = 2;

	//Locations[n].reload.l3.name = "randitem1";
	//Locations[n].reload.l3.go = "Conceicao_passage";
	//Locations[n].reload.l3.emerge = "goto4";
	//Locations[n].reload.l3.autoreload = "0";
	//Locations[n].reload.l3.label = "Conceicao Passage.";

	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 0, 24);

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Shore_2";

	Locations[n].id = "Hispaniola_shore_04";
	locations[n].id.label = "Ile a Vache."; // KK
	locations[n].worldmap = "HiShore 4";
	Locations[n].image = "Outside_Shore_2.tga";
	Locations[n].name = "Ile a Vache";
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
	Locations[n].reload.l1.go = "Hispaniola_Jungle_01";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 3.0;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Hispaniola_Jungle_01";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3.0;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Hispaniola";
	Locations[n].reload.l2.emerge = "reload_9";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";

	Locations[n].locators_radius.reload.boat = 9.0;

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Cave Entrance";

	Locations[n].id = "Hispaniola_Jungle_01";
	locations[n].id.label = "Cave entrance";
	Locations[n].image = "Outside_Cave_Entrance.tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].ambush = true;
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
	Locations[n].reload.l3.go = "Hispaniola_Grot";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Grot.";
	Locations[n].locators_radius.reload.Reload1 = 1;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Hispaniola_Grot";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Grot.";
	Locations[n].locators_radius.reload.Reload1_back = 1.3;

	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Hispaniola_shore_04";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Shore.";
	Locations[n].locators_radius.reload.Reload2 = 2.0;

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Hispaniola_shore_04";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Shore.";
	Locations[n].locators_radius.reload.reload2_back = 2.0;

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	//-------------------------------------------------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Grot";

	Locations[n].id = "Hispaniola_Grot";
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
	Locations[n].reload.l1.go = "Hispaniola_Jungle_01";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Hispaniola_Jungle_01";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2;

	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 0, 24);

	Locations[n].items.randitem1 = "blade36";

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Shore_8";

	Locations[n].id = "Hispaniola_shore_02";
	locations[n].id.label = "Boca de Hubon.";		//spell-checked by KAM // KK
	locations[n].worldmap = "HiShore 2";
	Locations[n].image = "Outside_Shore_8.tga";
	Locations[n].name = "Boca de Hubon";
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
	Locations[n].reload.l1.go = "Hispaniola_Jungle_02";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 3;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Hispaniola_Jungle_02";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Hispaniola";
	Locations[n].reload.l2.emerge = "reload_4";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.boat = 9.0;
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Hispaniola_Jungle_02";
	locations[n].id.label = "Jungle";
	Locations[n].filespath.models = "locations\Outside\jungle_8"; // qf"
	Locations[n].image = "Outside_Jungle_8.tga";
 	//Sound
	locations[n].type = "jungle";
	locations[n].ambush = true;
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
	Locations[n].reload.l1.go = "Hispaniola_shore_02";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Boca de Hubon.";
	Locations[n].locators_radius.reload.reload1 = 3.0;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Hispaniola_shore_02";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Hispaniola_Jungle_03";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Boca de Hubon.";
	Locations[n].locators_radius.reload.reload2 = 3.0;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Hispaniola_Jungle_03";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 2.0;

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\smugglerLairExit";
	//Locations[n].filespath.textures = "locations\JUNGLES";

	Locations[n].id = "Hispaniola_Jungle_03";
	locations[n].id.label = "Jungle";
	Locations[n].image = "Buccaneer_camp_exit.tga";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "smugglerLairExit_locators";
	Locations[n].models.always.jungle = "smugglerLairExit";
	Locations[n].models.always.grassPatch = "smugglerLairExit_grass";
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
	Locations[n].models.day.fonar = "smugglerLairExit_fd";	
	Locations[n].models.day.charactersPatch = "smugglerLairExit_patch";
	//Night
	Locations[n].models.night.fonar = "smugglerLairExit_fn";	
	Locations[n].models.night.charactersPatch = "smugglerLairExit_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Hispaniola_Jungle_02";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1 = 3.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Buccaneers_Camp";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.label = "Buccaneers camp.";
	Locations[n].locators_radius.reload.Reload2 = 3.0;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Hispaniola_Jungle_04";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload3 = 3.0;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Hispaniola_Jungle_02";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1_back = 2.0;
/*
	Locations[n].reload.l5.name = "reload2_back";
	Locations[n].reload.l5.go = "Buccaneers_Camp";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Buccaneers camp.";
	Locations[n].locators_radius.reload.Reload2_back = 2.0;
*/
	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Hispaniola_Jungle_04";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload3_back = 2.0;

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\smugglerLairTown";

	Locations[n].id = "Buccaneers_Camp";
	locations[n].id.label = "Buccaneers Camp";
	Locations[n].image = "Buccaneer.tga";

	//Town sack
	Locations[n].townsack = "Buccaneers Camp";

	//Sound
//	locations[n].type = "jungle";
	locations[n].type = "town";
	Locations[n].fastreload = "BuccaneersCamp";

	//Models
	//Always
	Locations[n].models.always.locators = "smugglerLairTown_locators";
	Locations[n].models.always.town = "smugglerLairTown";
	Locations[n].models.always.grasspatch = "smugglerLairTown_grass";
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
	Locations[n].models.day.fonar = "smugglerLairTown_fd";
	Locations[n].models.day.charactersPatch = "smugglerLairTown_patch";
	//Night
	Locations[n].models.night.fonar = "smugglerLairTown_fn";
	Locations[n].models.night.charactersPatch = "smugglerLairTown_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
/*	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Hispaniola_Jungle_03";
	Locations[n].reload.l1.emerge = "Reload2";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 1;
*/
	Locations[n].reload.l5.name = "reload1";
	Locations[n].reload.l5.go = "Hispaniola_Jungle_03";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1 = 1.5;// new value in order to avoid bugs of reloading

	Locations[n].reload.l6.name = "Reload4";
	Locations[n].reload.l6.go = "BC_Tavern";
	Locations[n].reload.l6.emerge = "Reload1";
	Locations[n].reload.l6.label = "Tavern.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l6.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l7.name = "Reload6";
	Locations[n].reload.l7.go = "BC_Store";
	Locations[n].reload.l7.emerge = "locator2";
	Locations[n].reload.l7.label = "Store.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l7.goto_disable = 1; // Screwface: Disable Go-To location

	//Locations[n].reload.l2.name = "Reload5";
	//Locations[n].reload.l2.go = "Douwesen_Pirate_Residence";
	//Locations[n].reload.l2.emerge = "Reload1";
	//Locations[n].reload.l2.label = "Chief's House.";

	//Locations[n].reload.l3.name = "Reload6";
	//Locations[n].reload.l3.go = "Pirate_tavern";
	//Locations[n].reload.l3.emerge = "Reload1";
	//Locations[n].reload.l3.label = "Tavern.";

	Locations[n].reload.l4.name = "Reload2";
	Locations[n].reload.l4.go = "BC_ForgerHouse";
	Locations[n].reload.l4.emerge = "Reload1";
	Locations[n].reload.l4.label = "House of Pablo Escriva.";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.disable = 1;	// GR: locked until needed by quest

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;
	//-------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Jungle_1";

	Locations[n].id = "Hispaniola_Jungle_04";
	locations[n].id.label = "Jungle";
	Locations[n].image = "Outside_Jungle_1.tga";
	//Sound
	locations[n].type = "jungle";
	locations[n].ambush = true;

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
	Locations[n].reload.l1.go = "Hispaniola_Jungle_03";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1 = 3.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Hispaniola_Jungle_05";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Far Beach.";
	Locations[n].locators_radius.reload.Reload2 = 3.0;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Hispaniola_Jungle_03";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Hispaniola_Jungle_05";
	Locations[n].reload.l4.emerge = "reload3";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Far Beach.";
	Locations[n].locators_radius.reload.reload2_back = 2.0;

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Jungle_4";

	Locations[n].id = "Hispaniola_Jungle_05";
	locations[n].id.label = "Jungle";
	Locations[n].image = "Outside_Jungle_4.tga";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Town sack
	Locations[n].townsack = "Port au Prince";

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
	Locations[n].reload.l1.go = "Hispaniola_Jungle_06";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "To Fort.";
	Locations[n].locators_radius.reload.reload1 = 4;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Hispaniola_Jungle_06";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "To Fort.";
	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "PoPrince_town_exit";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 4;

	Locations[n].reload.l5.name = "reload2_back";
	Locations[n].reload.l5.go = "PoPrince_town_exit";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Hispaniola_Jungle_04";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3 = 4;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Hispaniola_Jungle_04";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 3;

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// 06 -------------------------------------------------
	Locations[n].id = "Hispaniola_Jungle_06";
	locations[n].id.label = "Jungle";
	Locations[n].image = "Town_FalaiseDeFleur_Exit.tga";
	//Sound
	locations[n].type = "jungle";

	//Town sack
	Locations[n].townsack = "Port au Prince";

	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\exit";
	Locations[n].filespath.textures = "locations\FRANCE";
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
	Locations[n].reload.l1.go = "PoPrince_fakefort1";
	Locations[n].reload.l1.emerge = "reloadc2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Fort.";

	Locations[n].reload.l2.name = "reload1";
	Locations[n].reload.l2.go = "Hispaniola_Jungle_05";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1 = 3;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Hispaniola_Jungle_05";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// ccc fake forts--------------------------------------
	//ID
	Locations[n].id = "PoPrince_fakefort1";		//new ID
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";	//A warning sign at the gate :)
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_1";
	Locations[n].image = "Fort_Inside_Fort_1.tga";

	//Town sack
	Locations[n].townsack = "Port au Prince";
	locations[n].fastreload = "PoPrince";
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
	Locations[n].reload.l1.go = "Hispaniola_Jungle_06";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reloadC4";
	Locations[n].reload.l2.go = "PoPrince_fakefort2";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l3.name = "reloadc5";
	Locations[n].reload.l3.go = "PoPrince_armory";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].reload.l4.name = "reloadc1";
	Locations[n].reload.l4.go = "PoPrince_fakefort3";
	Locations[n].reload.l4.emerge = "reloadc1";
	Locations[n].reload.l4.autoreload = "0";

// ccc may07 Location Remodeling Campaign -->
	Locations[n].reload.l31.name = "reloadc3";
	Locations[n].reload.l31.go = "PoPrince_town";
	Locations[n].reload.l31.emerge = "reload8";
	Locations[n].reload.l31.autoreload = "0";
	Locations[n].reload.l31.label = "Town.";
// <-- ccc may07 Location Remodeling Campaign

	Locations[n].island = "Hispaniola"; // NK 04-08-29	
	n = n + 1;

	// ccc oxbay fake fort 2----------------------------------
	//ID
	Locations[n].id = "PoPrince_fakefort2";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";

	//Town sack
	Locations[n].townsack = "Port au Prince";
	locations[n].fastreload = "PoPrince";

	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_2";
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
	Locations[n].reload.l1.go = "PoPrince_fakefort1";
	Locations[n].reload.l1.emerge = "reloadc4";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reloadc1";
	Locations[n].reload.l2.go = "PoPrince_fakefort3";
	Locations[n].reload.l2.emerge = "reloadc2";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;
	
	// ccc oxbay fake fort 3----------------------------------
	//ID
	Locations[n].id = "PoPrince_fakefort3";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";


	//Town sack
	Locations[n].townsack = "Port au Prince";
	locations[n].fastreload = "PoPrince";

	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_3";
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
	Locations[n].reload.l1.go = "PoPrince_fakefort1";
	Locations[n].reload.l1.emerge = "reloadc1";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reloadc2";
	Locations[n].reload.l2.go = "PoPrince_fakefort2";
	Locations[n].reload.l2.emerge = "reloadc1";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l3.name = "reload1";
	Locations[n].reload.l3.go = "PoPrince_armory";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// ccc oxbay armory-------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\LargeStore";
	Locations[n].id = "PoPrince_armory";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";
	Locations[n].image = "Fort_Inside_Fort_2.tga";

	//Town sack
	Locations[n].townsack = "Port au Prince";
	locations[n].fastreload = "PoPrince";
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
	Locations[n].reload.l1.go = "PoPrince_fakefort1";
	Locations[n].reload.l1.emerge = "reloadc5";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "PoPrince_fakefort3";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\town_Conceicao\exit";

	Locations[n].id = "PoPrince_town_exit";
	locations[n].id.label = "Jungle";		//spell-checked by KAM
	Locations[n].image = "Town_Conceicao_Exit.tga";

	//Town sack
	Locations[n].townsack = "Port au Prince";

	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);
//	locations[n].fastreload = "PoPrince";
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
	Locations[n].reload.l1.go = "Hispaniola_Jungle_05";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1 = 2;

	Locations[n].reload.l3.name = "Reload1_back";
	Locations[n].reload.l3.go = "Hispaniola_Jungle_05";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1_back = 2;

	Locations[n].reload.l2.name = "Reload2";
	Locations[n].reload.l2.go = "PoPrince_town";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload2 = 1.5;

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;
	// -------------------------------------------------
	Locations[n].filespath.models = "locations\town_PoPrince\town"; // ccc may07 Location Remodeling Campaign

	Locations[n].id = "PoPrince_town";
	locations[n].id.label = "#stown_name#";
	locations[n].worldmap = "Port au Prince";
	Locations[n].image = "Town_PoPrince_Town.tga";

	//Town sack
	Locations[n].townsack = "Port au Prince";

	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "PoPrince";
	//Models
	//Always
	Locations[n].models.always.locators = "ConTown_l_pap";
	Locations[n].models.always.town = "ConTown";
	Locations[n].models.always.l1 = "Contown_b04";
	Locations[n].models.always.l1.level = 7;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.Always.add = "contown_add"; // new buildings - ccc may07 Location Remodeling Campaign
	//Day
	Locations[n].models.day.fonar = "ConTown_fd";
	Locations[n].models.day.charactersPatch = "ConTown_pd";
	Locations[n].models.day.jumpPatch = "ConTown_j";
	//Night
	Locations[n].models.night.fonar = "ConTown_fn";
	Locations[n].models.night.charactersPatch = "ConTown_pd";
	Locations[n].models.night.jumpPatch = "ConTown_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	LAi_LocationFantomsGen(&locations[n], true);

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "PoPrince_town_exit";
	Locations[n].reload.l1.emerge = "Reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "PoPrince_Port";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Sea port.";

	Locations[n].reload.l3.name = "reload11";
	Locations[n].reload.l3.go = "PoPrince_Store";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Store.";
	Locations[n].reload.l3.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l3.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l4.name = "reload18";
	Locations[n].reload.l4.go = "PoPrince_House_02";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "House.";

	Locations[n].reload.l5.name = "reload13";
	Locations[n].reload.l5.go = "PoPrince_tavern";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Tavern.";
	Locations[n].reload.l5.close_for_night = 0;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l5.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l12.name = "reload12";
	Locations[n].reload.l12.go = "PoPrince_House_01";
	Locations[n].reload.l12.emerge = "reload1";
	Locations[n].reload.l12.autoreload = "0";
	Locations[n].reload.l12.label = "House.";

	Locations[n].reload.l14.name = "reload0";
	Locations[n].reload.l14.go = "PoPrince_town_02";
	Locations[n].reload.l14.emerge = "reload6";
	Locations[n].reload.l14.autoreload = "1";
	Locations[n].reload.l14.label = "Town.";
	Locations[n].locators_radius.reload.reload0 = 2;

	Locations[n].reload.l15.name = "reload15";
	Locations[n].reload.l15.go = "PoPrince_Shipyard";
	Locations[n].reload.l15.emerge = "reload1";
	Locations[n].reload.l15.autoreload = "0";
	Locations[n].reload.l15.label = "Shipyard.";	//spell-checked by KAM
	Locations[n].reload.l15.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l15.goto_disable = 1; // Screwface: Disable Go-To location

// KK -->
	Locations[n].reload.l6.name = "reload14";
	Locations[n].reload.l6.go = "PoPrince_townhall";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Residence.";
	Locations[n].reload.l6.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l6.goto_disable = 1; // Screwface: Disable Go-To location
// <-- KK

	if(GetCurrentPeriod() >= PERIOD_THE_SPANISH_MAIN)
	{
		Locations[n].reload.l16.name = "reload3";
		Locations[n].reload.l16.go = "French_WIC_Office";
		Locations[n].reload.l16.emerge = "reload1";
		Locations[n].reload.l16.autoreload = "0";
		Locations[n].reload.l16.label = "French West India Company.";
		Locations[n].reload.l16.close_for_night = 1;
		if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l16.goto_disable = 1; // Screwface: Disable Go-To location
	}

// ccc may07 Location Remodeling Campaign -->
  // additional gate to fort
	Locations[n].reload.l31.name = "reload8";
	Locations[n].reload.l31.go = "PoPrince_fakefort1";
	Locations[n].reload.l31.emerge = "reloadc3";
	Locations[n].reload.l31.autoreload = "0";
	Locations[n].reload.l31.label = "Fort.";
// <--  ccc may07 Location Remodeling Campaign

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\town_IslaMuelle\town_04";
	Locations[n].filespath.textures = "locations\FRANCE";

	Locations[n].id = "PoPrince_town_02";
	locations[n].id.label = "#stown_name#";
	locations[n].worldmap = "Port au Prince";
	Locations[n].image = "Town_PoPrince_Town.tga";

	//Town sack
	Locations[n].townsack = "Port au Prince";
	locations[n].fastreload = "PoPrince";

	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].fastreload = "PoPrince";
	//Models
	//Always
	Locations[n].models.always.locators = "Mu04_l";
	Locations[n].models.always.l1 = "Mu04";
	Locations[n].models.always.grassPatch = "Mu04_g";
	//Day
	Locations[n].models.day.fonar = "Mu04_fd";
	Locations[n].models.day.charactersPatch = "Mu04_pd";
	Locations[n].models.day.jumpPatch = "Mu04_j";
	//Night
	Locations[n].models.night.fonar = "Mu04_fn";
	Locations[n].models.night.charactersPatch = "Mu04_pn";
	Locations[n].models.night.jumpPatch = "Mu04_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map

	Locations[n].reload.l8.name = "reload6";
	Locations[n].reload.l8.go = "PoPrince_town";
	Locations[n].reload.l8.emerge = "reload0";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "#stown_name#.";

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\shipyard"; // ccc may07 Location Remodeling Campaign
	Locations[n].id = "PoPrince_Shipyard";
	locations[n].id.label = "#stown_name# shipyard";
	Locations[n].image = "Inside_Shipyard1.tga";

	//Town sack
	Locations[n].townsack = "Port au Prince";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "PoPrince";
	//Models
	//Always
	Locations[n].models.always.locators = "sh01_l";
	Locations[n].models.always.l1 = "Sh01";
	Locations[n].models.always.window = "sh01_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "Sh01_p";
	Locations[n].models.day.fd = "sh01_fd";

	//Night
	Locations[n].models.night.charactersPatch = "Sh01_p";
	Locations[n].models.night.fn = "sh01_fn";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\oxsh1_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "PoPrince_town";
	Locations[n].reload.l1.emerge = "Reload15";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "PoPrince_tavern";
	Locations[n].filespath.models = "locations\inside\smalltavern";
	locations[n].id.label = "#stown_name# tavern";
	Locations[n].image = "Inside_SmallTavern.tga";

	//Town sack
	Locations[n].townsack = "Port au Prince";

	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "PoPrince";
	//Models
	//Always
	Locations[n].models.always.locators = "ST_PoP_l";
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
	Locations[n].models.back = "back\ffst_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "PoPrince_town";
	Locations[n].reload.l1.emerge = "Reload13";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "PoPrince_tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.label = "Room.";
	Locations[n].locators_radius.reload.reload2 = 0.8;
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "PoPrince_tavern_upstairs";
	locations[n].id.label = "Room in #stown_name# tavern";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house";
	Locations[n].image = "Inside_Doubleflour_House_Room.tga";

	//Town sack
	Locations[n].townsack = "Port au Prince";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PoPrince";
	//Models
	//Always
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
	Locations[n].models.back = "back\fflf2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "PoPrince_tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# tavern."; // KK
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\MediumStore";
	Locations[n].image = "Inside_MediumStore.tga";

	Locations[n].id = "PoPrince_Store";
	locations[n].id.label = "#stown_name# store";

	//Town sack
	Locations[n].townsack = "Port au Prince";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "PoPrince";
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
	Locations[n].reload.l1.go = "PoPrince_town";
	Locations[n].reload.l1.emerge = "Reload11";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	Locations[n].locators_radius.camdetector.camera1 = 5;
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

// KK --------------------------------------------------->
	locations[n].filespath.models = "locations\inside\ResidenceA02";

	Locations[n].id = "PoPrince_townhall";
	locations[n].id.label = "#stown_name# townhall";
	Locations[n].image = "Inside_ResidencA2.tga";

	//Town sack
	Locations[n].townsack = "Port au Prince";

	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "PoPrince";

	//Models
	//Always
	locations[n].models.always.locators = "residence02_locators";
	locations[n].models.always.l1 = "residence02";
	locations[n].models.always.window = "residence02_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 50;
	//Day
	locations[n].models.day.charactersPatch = "residence02_patch";

	//Night
	locations[n].models.night.charactersPatch = "residence02_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\cores5_";

	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "PoPrince_Town";
	Locations[n].reload.l1.emerge = "reload14";
	Locations[n].reload.l1.autoreload = "0";
	locations[n].id.label = "#stown_name#.";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Hispaniola";
	n = n + 1;
// <-- KK

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\town_PoPrince\port"; //ccc new model directory

	Locations[n].id = "PoPrince_Port";
	locations[n].id.label = "#stown_name# port."; // KK
	locations[n].worldmap = "Port au Prince";
	Locations[n].image = "Town_PoPrince_Port.tga";

	//Town sack
	Locations[n].townsack = "Port au Prince";

	//Sound
	locations[n].act.fantoms = 1;
	locations[n].type = "port";
	locations[n].fastreload = "PoPrince";

	//Models
	//Always
	Locations[n].models.always.locators = "PoPport_l";
	Locations[n].models.always.seabed = "PoPport_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.l1 = "PoPport";
	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.l2 = "PoPport_b04";
	Locations[n].models.always.l2.level = 9;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.grassPatch = "PoPport_g";
	//Day
	Locations[n].models.day.rinok = "PoPport_e01";
	//Locations[n].models.day.fonar = "PoPport_fd"; //ccc no streetlamps anymore
	Locations[n].models.day.charactersPatch = "PoPport_p"; //ccc same walkpatch day & night
	//Night
	Locations[n].models.night.rinok = "PoPport_e01"; //ccc merchant goods remain at night
	//ccc Locations[n].models.night.fonar = "PoPport_fn"; //ccc no streetlamps anymore
	Locations[n].models.night.charactersPatch = "PoPport_p"; //ccc same walkpatch day & night
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	LAi_LocationFantomsGen(&locations[n], true);
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "PoPrince_town";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Hispaniola";
	Locations[n].reload.l4.emerge = "reload_1";
	Locations[n].reload.l4.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l4.label = "Ship.";
	else
		Locations[n].reload.l4.label = "Sea.";
	Locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Hispaniola";
	Locations[n].reload.l3.emerge = "reload_1";
	Locations[n].reload.l3.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l3.label = "Ship.";
	else
		Locations[n].reload.l3.label = "Sea.";
	Locations[n].locators_radius.reload.reload2 = 3;

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

// -------------------------------------------------
	Locations[n].filespath.models = "locations\inside\Residence5";

	Locations[n].id = "French_WIC_Office";
	locations[n].id.label = "French West India Company";
	Locations[n].image = "Inside_FWIC_Office.tga";

	//Town sack
	Locations[n].townsack = "Port au Prince";

	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Port au Prince";

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
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "PoPrince_town";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;
	
	// -------------------------------------------------
	// Swindler 2006-07-11 -->
	// Retextured Santo Domingo
	Locations[n].filespath.models = "locations\town_Greenford\port";
	Locations[n].filespath.textures = "locations\SPAIN";
	Locations[n].image = "Town_Greenford_Port_Spain.tga";

	Locations[n].id = "Santo_Domingo_port";
	locations[n].id.label = "#stown_name# port.";
	locations[n].worldmap = "Santo Domingo";

	//Town sack
	Locations[n].townsack = "Santo Domingo";
	if(GetCurrentPeriod() >= PERIOD_COLONIAL_POWERS) Locations[n].navy = 1;

	//Sound
	locations[n].type = "port";
	locations[n].fastreload = "Santo_Domingo";
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	Locations[n].models.always.locators = "GrPort_l";
	Locations[n].models.always.l1 = "GrPort";
	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.seabed = "GrPort_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "GrPort_g";
	Locations[n].models.always.add = "GrPort_SD"; // additional buildings - ccc may07 Location Remodeling Campaign
	//Day
	Locations[n].models.day.charactersPatch = "GrPort_p";
	Locations[n].models.day.fonar = "GrPort_fd";
	//Night
	Locations[n].models.night.charactersPatch = "GrPort_p";
	Locations[n].models.night.fonar= "GrPort_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Hispaniola";
	Locations[n].reload.l1.emerge = "reload_3";
	Locations[n].reload.l1.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l1.label = "Ship.";
	else
		Locations[n].reload.l1.label = "Sea.";
	Locations[n].locators_radius.reload.Reload1 = 3.0;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Hispaniola";
	Locations[n].reload.l3.emerge = "reload_3";
	Locations[n].reload.l3.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l3.label = "Ship.";
	else
		Locations[n].reload.l3.label = "Sea.";
	Locations[n].locators_radius.reload.reload1_back = 3.0;

	Locations[n].reload.l2.name = "reload4";
	Locations[n].reload.l2.go = "Santo_Domingo_town";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name#.";

	Locations[n].reload.l4.name = "reload2";
	Locations[n].reload.l4.go = "Santo_Domingo_House_02";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "House.";

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Town_SantoDomingo\center";
	Locations[n].image = "Town_SantoDomingo_center.tga";

	Locations[n].id = "Santo_Domingo_town";
	locations[n].id.label = "#stown_name#";
	locations[n].worldmap = "Santo Domingo";

	//Town sack
	Locations[n].townsack = "Santo Domingo";

	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "Santo_Domingo";
	//Models
	//Always
	Locations[n].models.always.locators = "SDTown_l";
	Locations[n].models.always.town = "SDTown";
	Locations[n].models.always.add = "lights";
	Locations[n].models.always.tree = "tree";
	//Day
	//Locations[n].models.day.fonar = "Ideng";
	Locations[n].models.day.charactersPatch = "walk_patch";
	//Night
	//Locations[n].models.night.fonar = "Ideng";
	Locations[n].models.night.charactersPatch = "walk_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	LAi_LocationFantomsGen(&locations[n], true);
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Santo_Domingo_port";
	Locations[n].reload.l1.emerge = "Reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Sea port.";

	Locations[n].reload.l2.name = "reload19";
	Locations[n].reload.l2.go = "Santo_Domingo_fakefort1";
	Locations[n].reload.l2.emerge = "reloadc1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";

	Locations[n].reload.l21.name = "reload21";
	Locations[n].reload.l21.go = "Santo_Domingo_Tavern";
	Locations[n].reload.l21.emerge = "reload1";
	Locations[n].reload.l21.autoreload = "0";
	Locations[n].reload.l21.label = "Tavern.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l21.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l3.name = "reload26";
	Locations[n].reload.l3.go = "Santo_Domingo_town_exit_1";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Jungle.";

  	Locations[n].reload.l9.name = "reload4";
	Locations[n].reload.l9.go = "Santo_Domingo_House_01";
	Locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "House.";

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "Santo_Domingo_store";
	Locations[n].reload.l5.emerge = "locator2";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Store.";
	Locations[n].reload.l5.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l5.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l18.name = "reload13";
	Locations[n].reload.l18.go = "Santo_Domingo_Shipyard";
	Locations[n].reload.l18.emerge = "reload1";
	Locations[n].reload.l18.autoreload = "0";
	Locations[n].reload.l18.label = "Shipyard";
	Locations[n].reload.l18.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l18.goto_disable = 1; // Screwface: Disable Go-To location

// KK -->
	Locations[n].reload.l4.name = "reload27";
	Locations[n].reload.l4.go = "Santo_Domingo_Townhall";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "#stown_name# Townhall.";
	Locations[n].reload.l4.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l4.goto_disable = 1; // Screwface: Disable Go-To location
// <-- KK

  	Locations[n].reload.l25.name = "reload25";
	Locations[n].reload.l25.go = "Santo_Domingo_Historian_House";
	Locations[n].reload.l25.emerge = "reload1";
	Locations[n].reload.l25.autoreload = "0";
	Locations[n].reload.l25.label = "House in #stown_name#";
	Locations[n].reload.l25.close_for_night = 1;

	Locations[n].reload.l20.name = "reload2";
	Locations[n].reload.l20.go = "Santo_Domingo_usurer";
	Locations[n].reload.l20.emerge = "reload1";
	Locations[n].reload.l20.autoreload = "0";
	Locations[n].reload.l20.label = "Loanshark";
	Locations[n].reload.l20.close_for_night = 1;
	Locations[n].locators_radius.reload.reload2 = 0.5;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l20.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l30.name = "reload3";
	Locations[n].reload.l30.go = "Santo_Domingo_usurer_stairs_down";
	Locations[n].reload.l30.emerge = "reload2";
	Locations[n].reload.l30.autoreload = "0";
	Locations[n].reload.l30.label = "Loanshark";
	Locations[n].reload.l30.close_for_night = 1;
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].reload.l60.name = "reload6";
	Locations[n].reload.l60.go = "Santo_Domingo_usurer_stairs_up";
	Locations[n].reload.l60.emerge = "goto4";
	Locations[n].reload.l60.autoreload = "0";
	Locations[n].reload.l60.label = "Loanshark";
	Locations[n].reload.l60.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l60.goto_disable = 1;

	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box2 = 0.5;

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "Santo_Domingo_usurer_stairs_up";
	locations[n].id.label = "To the Loanshark";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house\\";
	Locations[n].filespath.textures = "locations\inside\Doubleflour_house\church_attic";
	Locations[n].image = "GB_small_stairs.tga";

	//Town sack
	Locations[n].townsack = "Santo Domingo";

	//Sound
	locations[n].type = "silent_residence";
	
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F1_l_Domingo";
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
	Locations[n].reload.l2.go = "Santo_Domingo_town";
	Locations[n].reload.l2.emerge = "box2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Santo_Domingo_usurer_stairs_up";
	Locations[n].reload.l3.emerge = "reload4";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Santo_Domingo_town";
	Locations[n].reload.l4.emerge = "reload6";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.3;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_A05";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "gatedoor_attic_brick";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "door_A05";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "gatedoor_attic_brick";

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Santo_Domingo_usurer_stairs_down";
	locations[n].id.label = "Exit";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house\\";
	Locations[n].filespath.textures = "locations\inside\Doubleflour_house\church_attic";
	Locations[n].image = "GB_small_stairs.tga";

	//Town sack
	Locations[n].townsack = "Santo Domingo";

	//Sound
	locations[n].type = "silent_residence";
	
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F1_l_Domingo";
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
	Locations[n].reload.l2.go = "Santo_Domingo_town";
	Locations[n].reload.l2.emerge = "box2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Santo_Domingo_usurer_stairs_down";
	Locations[n].reload.l3.emerge = "reload4";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Santo_Domingo_town";
	Locations[n].reload.l4.emerge = "reload6";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.3;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_A05";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "gatedoor_attic_brick";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "door_A05";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "gatedoor_attic_brick";

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].id = "Santo_Domingo_usurer";
	locations[n].id.label = "Loanshark's Office";
	//Town sack
	Locations[n].townsack = "Santo Domingo";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Santo_Domingo";

	//InitBank(Locations[n].id);

	Locations[n].filespath.models = "locations\Inside\Bank";
	Locations[n].image = "Inside_Bank.tga";
	//Models
	Locations[n].models.back = "back\tor3_";				//JRH
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
	Locations[n].reload.l1.emerge = "box1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.go = "Santo_Domingo_town";
	Locations[n].reload.l1.label = "#stown_name#";

	Locations[n].island = "Hispaniola";
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\StoreSmall";
	Locations[n].image = "Inside_StoreSmall.tga";

	Locations[n].id = "Santo_Domingo_store";
	locations[n].id.label = "#stown_name# store";

	//Town sack
	Locations[n].townsack = "Santo Domingo";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Santo_Domingo";
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
	Locations[n].models.back = "back\muss_";
	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "Santo_Domingo_town";
	Locations[n].reload.l1.emerge = "Reload5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\pirateresidence";	

	Locations[n].id = "Santo_Domingo_Shipyard";
	locations[n].id.label = "#stown_name# shipyard";
	Locations[n].image = "Inside_PirateResidence_Shipyard.tga";
	//Town sack
	Locations[n].townsack = "Santo Domingo"; // NK - "Oxbay";
	//Sound
	locations[n].type = "shop"; //"house";
	locations[n].fastreload = "Santo_Domingo";
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
	Locations[n].reload.l1.go = "Santo_Domingo_town";
	Locations[n].reload.l1.emerge = "Reload13";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

    // -------------------------------------------------
	Locations[n].id = "Santo_Domingo_tavern";
	locations[n].id.label = "#stown_name# tavern";
	Locations[n].filespath.models = "locations\inside\Largetavern";
	Locations[n].image = "Inside_LargeTavern.tga";

	//Town sack
	Locations[n].townsack = "Santo Domingo";

	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "Santo_Domingo";
	//Models
	//Always
	Locations[n].models.always.tavern = "LT";
	Locations[n].models.always.locators = "LT_l";
	Locations[n].models.always.window = "LT_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "LT_p";

	//Night
	Locations[n].models.night.charactersPatch = "LT_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redlt_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Santo_Domingo_town";
	Locations[n].reload.l1.emerge = "reload21";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	LAi_LocationFightDisable(&Locations[n], true);

//MAXIMUS -->
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Santo_Domingo_tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Room in #stown_name# tavern.";
	Locations[n].reload.l2.disable = true; // KK
	LAi_LocationFightDisable(&Locations[n], true);
//MAXIMUS <--

	Locations[n].island = "hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Santo_Domingo_tavern_upstairs";
	locations[n].id.label = "Room in #stown_name# tavern";
	Locations[n].image = "Inside_Doubleflour_House_Room.tga";

	//Town sack
	Locations[n].townsack = "Santo Domingo";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Santo_Domingo";
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
	Locations[n].reload.l1.go = "Santo_Domingo_tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# tavern."; // KK
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

// KK -------------------------------------------------->

	Locations[n].filespath.models = "locations\inside\Residence5";

	Locations[n].id = "Santo_Domingo_townhall";
	locations[n].id.label = "#stown_name# townhall";
	Locations[n].image = "Inside_Residence5.tga";

	//Town sack
	Locations[n].townsack = "Santo Domingo";

	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Santo_Domingo";

	//Models
	//Always
	Locations[n].models.always.locators = "Res05_l";
	Locations[n].models.always.l1 = "Res05";
	Locations[n].models.always.window = "Res05_w";
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
	Locations[n].reload.l1.go = "Santo_Domingo_Town";
	Locations[n].reload.l1.emerge = "reload27";
	Locations[n].reload.l1.autoreload = "0";
	locations[n].id.label = "#stown_name#";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Hispaniola";
	n = n + 1;
// <-- KK

	// ccc fake forts--------------------------------------
	//ID
	Locations[n].id = "Santo_Domingo_fakefort1";		//new ID
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";	//A warning sign at the gate :)
	//Info
	Locations[n].filespath.models = "locations\Fort_Inside\Fort_1";
	Locations[n].filespath.textures = "locations\SPAIN";
	Locations[n].image = "Fort_Inside_Fort_1.tga";

	//Town sack
	Locations[n].townsack = "Santo Domingo";		//change
	locations[n].fastreload = "Santo_Domingo";		//change
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
	Locations[n].reload.l1.go = "Santo_Domingo_fakefort3";
	Locations[n].reload.l1.emerge = "reloadc1";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reloadC3";
	Locations[n].reload.l2.go = "Santo_Domingo_armory";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l3.name = "reloadc5";
	Locations[n].reload.l3.go = "Santo_Domingo_fakefort2";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].reload.l4.name = "reloadc1";
	Locations[n].reload.l4.go = "Santo_Domingo_town";
	Locations[n].reload.l4.emerge = "reload19";
	Locations[n].reload.l4.autoreload = "0";

	Locations[n].island = "Hispaniola"; // NK 04-08-29	
	n = n + 1;

	// ccc oxbay fake fort 2----------------------------------
	//ID
	Locations[n].id = "Santo_Domingo_fakefort2";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";

	//Town sack
	Locations[n].townsack = "Santo Domingo";
	locations[n].fastreload = "Santo_Domingo";

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
	Locations[n].reload.l1.go = "Santo_Domingo_fakefort1";
	Locations[n].reload.l1.emerge = "reloadc5";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reloadc1";
	Locations[n].reload.l2.go = "Santo_Domingo_fakefort3";
	Locations[n].reload.l2.emerge = "reloadc2";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;
	
	// ccc oxbay fake fort 3----------------------------------
	//ID
	Locations[n].id = "Santo_Domingo_fakefort3";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";


	//Town sack
	Locations[n].townsack = "Santo Domingo";
	locations[n].fastreload = "Santo_Domingo";

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
	Locations[n].reload.l1.go = "Santo_Domingo_fakefort1";
	Locations[n].reload.l1.emerge = "reloadc2";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reloadc2";
	Locations[n].reload.l2.go = "Santo_Domingo_fakefort2";
	Locations[n].reload.l2.emerge = "reloadc1";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l3.name = "reload1";
	Locations[n].reload.l3.go = "Santo_Domingo_armory";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// ccc oxbay armory-------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\LargeStore";
	Locations[n].id = "Santo_Domingo_armory";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";
	Locations[n].image = "Fort_Inside_Fort_2.tga";

	//Town sack
	Locations[n].townsack = "Santo Domingo";
	locations[n].fastreload = "Santo_Domingo";
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
	Locations[n].reload.l1.go = "Santo_Domingo_fakefort1";
	Locations[n].reload.l1.emerge = "reloadc3";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Santo_Domingo_fakefort3";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Santo_Domingo_town_exit_1";
	locations[n].id.label = "Jungle";
	Locations[n].filespath.models = "locations\Town_Redmond\REDexit1";
	Locations[n].filespath.textures = "locations\SPAIN";
	Locations[n].image = "Town_Redmond_Exit1.tga";

	//Town sack
	Locations[n].townsack = "Santo Domingo";

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
	Locations[n].reload.l1.go = "Santo_Domingo_town";
	Locations[n].reload.l1.emerge = "reload26";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].reload.l2.name = "Reload1";
	Locations[n].reload.l2.go = "Hispaniola_Jungle_08";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1 = 3.0;

	Locations[n].reload.l3.name = "Reload1_back";
	Locations[n].reload.l3.go = "Hispaniola_Jungle_08";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1_back = 2.0;

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Jungle_6";

	Locations[n].id = "Hispaniola_Jungle_08";
	locations[n].id.label = "Jungle";		//spell-checked by KAM
	Locations[n].image = "Outside_Jungle_6.tga";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "Jungle06_l_Hispaniola";
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
	Locations[n].reload.l1.go = "Santo_Domingo_town_exit_1";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 2.5;
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Hispaniola_shore_01";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload2 = 2.5;
	Locations[n].reload.l2.label = "Boca de Yuman.";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Hispaniola_village_Exit";
	Locations[n].reload.l3.emerge = "Reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.reload3 = 2.5;
	Locations[n].reload.l3.label = "village.";

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Hispaniola_shore_01";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].locators_radius.reload.reload2_back = 2.5;
	Locations[n].reload.l4.label = "Boca de Yuman.";

	Locations[n].reload.l5.name = "reload3_back";
	Locations[n].reload.l5.go = "Hispaniola_village_Exit";
	Locations[n].reload.l5.emerge = "Reload3";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].locators_radius.reload.reload3_back = 3;
	Locations[n].reload.l5.label = "village.";

	Locations[n].reload.l6.name = "reload1_back";
	Locations[n].reload.l6.go = "Santo_Domingo_town_exit_1";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 2.5;
	Locations[n].reload.l6.label = "Jungle.";
	
	Locations[n].reload.l7.name = "reload4";
	Locations[n].reload.l7.go = "Hispaniola_Jungle_Captain_House";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "House.";
	Locations[n].locators_radius.reload.reload7 = 1.0;

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;
	
	//Levis:
	//-------------------------------------------------
	Locations[n].id = "Hispaniola_Jungle_Captain_House";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\HutRoundInside";
	Locations[n].image = "Inside_IndianHome.tga"; //Todo

	//Town sack
	Locations[n].townsack = "Santo Domingo";

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
	Locations[n].reload.l1.go = "Hispaniola_Jungle_08";
	Locations[n].reload.l1.emerge = "reload4";
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

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\town_QC\exit";	
	Locations[n].id = "Hispaniola_village_Exit";
	locations[n].id.label = "Jungle";
	Locations[n].image = "Town_QC_Exit.tga";
	//Sound
	locations[n].type = "town";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "QCexit_l";
	Locations[n].models.always.exit = "QCexit";
	Locations[n].models.always.grassPatch = "QCexit_g";
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
	Locations[n].models.day.charactersPatch = "QCexit_p";
	//Night
	Locations[n].models.night.charactersPatch = "QCexit_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Hispaniola_village";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "village.";

	Locations[n].reload.l2.name = "Reload2";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 3.0;

	Locations[n].reload.l3.name = "Reload3";
	Locations[n].reload.l3.go = "Hispaniola_Jungle_08";
	Locations[n].reload.l3.emerge = "Reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Shore.";
	Locations[n].locators_radius.reload.reload3 = 3.0;

	Locations[n].reload.l4.name = "Reload2_back";
	Locations[n].reload.l4.go = "";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2_back = 2.0;

	Locations[n].reload.l5.name = "Reload3_back";
	Locations[n].reload.l5.go = "Hispaniola_Jungle_08";
	Locations[n].reload.l5.emerge = "Reload3";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Shore.";
	Locations[n].locators_radius.reload.Reload3_back = 2.0;

	Locations[n].reload.l6.name = "Reload6";
	Locations[n].reload.l6.go = "Village_church";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Church.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l6.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Pirate Fort";
	Locations[n].filespath.textures = "locations\SPAIN";

	Locations[n].id = "Hispaniola_village";
	locations[n].id.label = "Village";
	Locations[n].image = "Pirate_Fort.tga";

	//Town sack
	Locations[n].townsack = "Santo Domingo"; // NK 04-08-29

	//Sound
	locations[n].type = "town";

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
	Locations[n].reload.l1.go = "Hispaniola_village_Exit";
	Locations[n].reload.l1.emerge = "Reload1";
	Locations[n].reload.l1.label = "village.";
	Locations[n].reload.l1.autoreload = 1;
	Locations[n].locators_radius.reload.reload1 = 1;

	Locations[n].reload.l5.name = "Reload1_back";
	Locations[n].reload.l5.go = "Hispaniola_village_Exit";
	Locations[n].reload.l5.emerge = "Reload1";
	Locations[n].reload.l5.label = "village.";
	Locations[n].reload.l5.autoreload = 1;
	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

   	// -------------------------------------------------
    	Locations[n].id = "Hispaniola_shore_01";
	locations[n].id.label = "Boca de Yuman."; // KK
	locations[n].worldmap = "HiShore 1";
	Locations[n].filespath.models = "locations\Outside\Shore_3";
	Locations[n].image = "Outside_Shore_3.tga";
	Locations[n].name = "Boca de Yuman";
 	//Sound
	locations[n].type = "seashore";
   	//Models
	//Always
	Locations[n].models.always.jungle = "shore03";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.locators = "shore03_l";
    	Locations[n].models.always.seabed = "shore03_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "Shore03_g";

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
	Locations[n].models.day.charactersPatch = "shore03_p";
	//Night
	Locations[n].models.night.charactersPatch = "shore03_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Hispaniola_Jungle_08";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 2.0;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Hispaniola_Jungle_08";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 2.0;

 	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Hispaniola";
	Locations[n].reload.l2.emerge = "reload_2";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 9.0;

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].image = "Town_Tortuga.tga";

	Locations[n].id = "Tortuga_port";
	locations[n].id.label = "#stown_name# port.";
	locations[n].worldmap = "Tortuga";

	//Town sack
	Locations[n].townsack = "Tortuga";
	//Models
	Locations[n].filespath.models = "locations\Town_Tortuga";
	Locations[n].models.always.locators = "Tortuga_l";		//empty locatorfile to make Tortuga_lb load when capture town	

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.autoreload = "0";
// KK -->
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
// <-- KK
	Locations[n].locators_radius.reload.reload1_back = 2;
	//Sound
	locations[n].type = "port";
	locations[n].fastreload = "Tortuga";
	LAi_LocationFantomsGen(&locations[n], true);

	//Always
	Locations[n].models.always.l1 = "Tortuga";			//this is to get the Tortuga_landscape to show up, the model is sunk 50 m down, actual city models are Tortuga_fn, Tortuga_fd.
	Locations[n].models.always.l1.foam = "1";
//	Locations[n].models.always.l2 = "Tortuga_sb";
//	Locations[n].models.always.l2.foam = "1";
	Locations[n].models.always.l3 = "flagpole";
	Locations[n].models.always.l4 = "flagpole2";

	//Day
	Locations[n].models.day.fonar = "Tortuga_fd";
	Locations[n].models.day.charactersPatch = "walk_patch";
	Locations[n].models.day.locators = "Tortuga_l_day";

	//Night
	Locations[n].models.night.fonar = "Tortuga_fn";
	Locations[n].models.night.charactersPatch = "walk_patch";
	Locations[n].models.night.locators = "Tortuga_l_night";

	//Reload map
	Locations[n].reload.l1.go = "Hispaniola";
	Locations[n].reload.l1.emerge = "reload_7";
	Locations[n].reload.l1.name = "reload2_back";
	Locations[n].reload.l1.autoreload = "0";
// KK -->
	if (VISIT_DECK == 1)
		Locations[n].reload.l1.label = "Ship.";
	else
		Locations[n].reload.l1.label = "Sea.";
// <-- KK
	Locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].reload.l2.go = "Hispaniola";
	Locations[n].reload.l2.emerge = "reload_7";
//	Locations[n].reload.l2.name = "reload2_back";			//reload1_back above, turned off temp JRH
	Locations[n].reload.l2.autoreload = "0";
// KK -->
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
// <-- KK
	Locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].reload.l3.go = "Tortuga_shipyard";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.name = "reload5_back";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Shipyard.";
	Locations[n].reload.l3.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l3.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l4.go = "Tortuga_store";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.label = "House.";
	Locations[n].reload.l4.name = "reload6_back";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Store.";
	Locations[n].reload.l4.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l4.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l5.go = "Tortuga_townhall";	
	Locations[n].reload.l5.emerge = "locator2";
	Locations[n].reload.l5.name = "reload3_back";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l5.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l6.go = "Tortuga_tavern";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.name = "reload4_back";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Tavern.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l6.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l7.go = "";//House
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.name = "houseS1";
	Locations[n].reload.l7.autoreload = "0";

	Locations[n].reload.l8.go = "Tortuga_usurer";
	Locations[n].reload.l8.emerge = "reload1";
	Locations[n].reload.l8.name = "reload8_back";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "Loanshark's Office.";
	Locations[n].reload.l8.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l8.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l9.go = "";//"Tortuga_Church";
	Locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l9.name = "reload7_back";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "Church.";
	Locations[n].reload.l9.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l9.goto_disable = 1; // Screwface: Disable Go-To location

	//Locations[n].reload.l10.go = "Tortuga_town_01";
	//Locations[n].reload.l10.emerge = "reload1";
	//Locations[n].reload.l10.label = "#stown_name#.";
	Locations[n].reload.l10.go = "Tortuga_stairs";
	Locations[n].reload.l10.emerge = "reload1";
	Locations[n].reload.l10.name = "gate";
	Locations[n].reload.l10.autoreload = "0";

	Locations[n].reload.l11.go = "Tortuga_StoneHouse";
	Locations[n].reload.l11.emerge = "reload1";
	Locations[n].reload.l11.label = "House.";
	if (!IsBrothelEnabled()) Locations[n].reload.l11.close_for_night = 1;
	Locations[n].reload.l11.name = "brothel";
	Locations[n].reload.l11.autoreload = "0";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l11.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l12.go = "";//House
	Locations[n].reload.l12.emerge = "reload1";
	Locations[n].reload.l12.label = "House.";
	Locations[n].reload.l12.disable = 1;
	Locations[n].reload.l12.name = "houseS3";
	Locations[n].reload.l12.autoreload = "0";

	Locations[n].reload.l13.go = "";//House
	Locations[n].reload.l13.emerge = "reload1";
	Locations[n].reload.l13.label = "House.";
	Locations[n].reload.l13.disable = 1;
	Locations[n].reload.l13.name = "houseH1";
	Locations[n].reload.l13.autoreload = "0";

	Locations[n].reload.l14.go = "";//"Tortuga_Huts";
	Locations[n].reload.l14.emerge = "reload1";
	Locations[n].reload.l14.label = "House.";
	Locations[n].reload.l14.name = "barracks";
	Locations[n].reload.l14.autoreload = "0";
	Locations[n].reload.l14.close_for_night = 1;

	Locations[n].reload.l15.go = "";//"Tortuga_Storehouse";
	Locations[n].reload.l15.emerge = "reload1";
	Locations[n].reload.l15.label = "House.";
	Locations[n].reload.l15.name = "storehouse";
	Locations[n].reload.l15.autoreload = "0";
	Locations[n].reload.l15.close_for_night = 1;

	Locations[n].reload.l16.go = "";//"Tortuga_Academy";
	Locations[n].reload.l16.emerge = "reload1";
	Locations[n].reload.l16.label = "House.";
	Locations[n].reload.l16.disable = 1;
	Locations[n].reload.l16.name = "academy";
	Locations[n].reload.l16.autoreload = "0";
	Locations[n].reload.l16.close_for_night = 1;

	Locations[n].reload.l17.name = "reload10_back";			//moved here from Tortuga_town_01
	Locations[n].reload.l17.go = "Tortuga_Prison";
	Locations[n].reload.l17.emerge = "reload1";
	Locations[n].reload.l17.autoreload = "0";
	Locations[n].reload.l17.label = "Tortuga Prison";
	Locations[n].reload.l17.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l17.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l18.name = "reload9_back";			//moved here from Tortuga_town_01
	Locations[n].reload.l18.go = "Will_Turner_house_inside";
	Locations[n].reload.l18.emerge = "reload1";
	Locations[n].reload.l18.autoreload = "0";
	Locations[n].reload.l18.label = "House.";
	Locations[n].reload.l18.disable = 1;

	Locations[n].reload.l19.name = "reload11";			//JRH back door to shipyard
	Locations[n].reload.l19.go = "Tortuga_shipyard";
	Locations[n].reload.l19.emerge = "reload2";
	Locations[n].reload.l19.autoreload = "0";
	Locations[n].reload.l19.label = "Shipyard.";
	Locations[n].reload.l19.close_for_night = 1;

	Locations[n].reload.l20.name = "reload13";
	Locations[n].reload.l20.go = "Tortuga_tailorsShop";
	Locations[n].reload.l20.emerge = "locator2";
	Locations[n].reload.l20.autoreload = "0";
	Locations[n].reload.l20.label = "Tailor's Shop.";
	Locations[n].reload.l20.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l20.goto_disable = 1;

	//WoodesRogers quest
	Locations[n].reload.l21.name = "reloadQ1";
	Locations[n].reload.l21.go = "Tortuga_sailmaker";
	Locations[n].reload.l21.emerge = "box1";
	Locations[n].reload.l21.autoreload = "0";
	Locations[n].reload.l21.close_for_night = 1;

	Locations[n].reload.l22.name = "reloadQ2";
	Locations[n].reload.l22.go = "Tortuga_surgeon1";
	Locations[n].reload.l22.emerge = "reload1";
	Locations[n].reload.l22.autoreload = "0";

	Locations[n].reload.l23.name = "reloadQ3";
	Locations[n].reload.l23.go = "Tortuga_sailmaker";
	Locations[n].reload.l23.emerge = "box3";
	Locations[n].reload.l23.autoreload = "0";

	Locations[n].reload.l24.name = "reloadQ4";
	Locations[n].reload.l24.go = "Tortuga_surgeon2";
	Locations[n].reload.l24.emerge = "gotoQ1";
	Locations[n].reload.l24.autoreload = "0";
	Locations[n].reload.l24.close_for_night = 1;

	Locations[n].reload.l25.name = "reloadQ5";
	Locations[n].reload.l25.go = "Tortuga_gunsmith_kitchen";
	Locations[n].reload.l25.emerge = "reload1";
	Locations[n].reload.l25.autoreload = "0";
	Locations[n].reload.l25.close_for_night = 1;

	Locations[n].reload.l26.name = "reloadQ6";
	Locations[n].reload.l26.go = "Tortuga_tower_stairs_A";
	Locations[n].reload.l26.emerge = "goto4";
	Locations[n].reload.l26.autoreload = "0";

	Locations[n].reload.l27.name = "reloadQ7";
	Locations[n].reload.l27.go = "Tortuga_tower_stairs_B";
	Locations[n].reload.l27.emerge = "stairs";
	Locations[n].reload.l27.autoreload = "0";

	Locations[n].reload.l28.name = "reloadQ8";
	Locations[n].reload.l28.go = "Tortuga_tower";
	Locations[n].reload.l28.emerge = "box28";
	Locations[n].reload.l28.autoreload = "0";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "chimney_45";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "chimney_45";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "chimney_45";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "chimney_45";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "chimney_45";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "chimney_45";

	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "chimney_45";

	Locations[n].locators_radius.randitem.randitem8 = 0.01;
	Locations[n].items.randitem8 = "chimney_45";

	Locations[n].locators_radius.randitem.randitem9 = 0.01;
	Locations[n].items.randitem9 = "chimney_pot";

	Locations[n].locators_radius.randitem.randitem10 = 0.01;
	Locations[n].items.randitem10 = "chimney_pot";

	Locations[n].locators_radius.randitem.randitem11 = 0.01;
	Locations[n].items.randitem11 = "chimney_pot";

	Locations[n].locators_radius.randitem.randitem12 = 0.01;
	Locations[n].items.randitem12 = "chimney_pot";

	Locations[n].locators_radius.randitem.randitem13 = 0.01;
	Locations[n].items.randitem13 = "port_mast1";
	
	Locations[n].locators_radius.randitem.randitem14 = 0.01;
	Locations[n].items.randitem14 = "port_mast2";

	Locations[n].locators_radius.randitem.randitem15 = 0.01;
	Locations[n].items.randitem15 = "chimney_pot";

	Locations[n].locators_radius.randitem.randitem16 = 0.01;
	Locations[n].items.randitem16 = "chimney_pot";

	Locations[n].locators_radius.randitem.randitem17 = 0.01;
	Locations[n].items.randitem17 = "chimney_45";

	Locations[n].locators_radius.randitem.randitem18 = 0.01;
	Locations[n].items.randitem18 = "chimney_45";

	Locations[n].locators_radius.randitem.randitem19 = 0.01;
	Locations[n].items.randitem19 = "port_rey1";

	Locations[n].locators_radius.randitem.randitem20 = 0.01;
	Locations[n].items.randitem20 = "port_rey1";

	Locations[n].locators_radius.randitem.randitem21 = 0.01;
	Locations[n].items.randitem21 = "ladder_very_big";

	Locations[n].locators_radius.randitem.randitem22 = 0.01;
	Locations[n].items.randitem22 = "port_rey1";

	Locations[n].locators_radius.randitem.randitem23 = 0.01;
	Locations[n].items.randitem23 = "port_rey1";

	Locations[n].locators_radius.randitem.randitem24 = 0.01;
	Locations[n].items.randitem24 = "port_mast2";

	Locations[n].locators_radius.randitem.randitem25 = 0.01;
	Locations[n].items.randitem25 = "market_P1+W";

	Locations[n].locators_radius.randitem.randitem26 = 0.01;
	Locations[n].items.randitem26 = "market_C4";

	Locations[n].locators_radius.randitem.randitem27 = 0.01;
	Locations[n].items.randitem27 = "market_P1";

	Locations[n].locators_radius.randitem.randitem28 = 0.01;
	Locations[n].items.randitem28 = "market_P2";

	Locations[n].locators_radius.randitem.randitem29 = 0.01;
	Locations[n].items.randitem29 = "market_C1+1";

	Locations[n].locators_radius.randitem.randitem30 = 0.01;
	Locations[n].items.randitem30 = "market_P2";

	Locations[n].locators_radius.randitem.randitem31 = 0.01;
	Locations[n].items.randitem31 = "market_tent_fruit";

	Locations[n].locators_radius.randitem.randitem32 = 0.01;
	Locations[n].items.randitem32 = "market_tent";

	Locations[n].locators_radius.randitem.randitem33 = 0.01;
	Locations[n].items.randitem33 = "cannon2";

	Locations[n].locators_radius.randitem.randitem34 = 0.01;
	Locations[n].items.randitem34 = "cannon2";

	Locations[n].locators_radius.randitem.randitem35 = 0.01;
	Locations[n].items.randitem35 = "cannon2";

	Locations[n].locators_radius.randitem.randitem36 = 0.01;
	Locations[n].items.randitem36 = "cannon1";

	Locations[n].locators_radius.randitem.randitem37 = 0.01;
	Locations[n].items.randitem37 = "cannon1";

	Locations[n].locators_radius.randitem.randitem38 = 0.01;
	Locations[n].items.randitem38 = "cannon1";

	Locations[n].locators_radius.randitem.randitem39 = 0.01;
	Locations[n].items.randitem39 = "cannon2";

	Locations[n].locators_radius.randitem.randitem40 = 0.01;
	Locations[n].items.randitem40 = "cannon1";

	Locations[n].locators_radius.randitem.randitem41 = 0.01;
	Locations[n].items.randitem41 = "cannon1";

	Locations[n].locators_radius.randitem.randitem42 = 0.01;
	Locations[n].items.randitem42 = "cannon2";

	Locations[n].locators_radius.randitem.randitem43 = 0.01;
	Locations[n].items.randitem43 = "cannon2";

	Locations[n].locators_radius.randitem.randitem44 = 0.01;
	Locations[n].items.randitem44 = "cannon2";

	Locations[n].locators_radius.randitem.randitem45 = 0.01;
	Locations[n].items.randitem45 = "cannon2";

	Locations[n].locators_radius.randitem.randitem46 = 0.01;
	Locations[n].items.randitem46 = "cannon2";

	Locations[n].locators_radius.randitem.randitem47 = 0.01;
	Locations[n].items.randitem47 = "cannon2";

	Locations[n].locators_radius.randitem.randitem48 = 0.01;
	Locations[n].items.randitem48 = "gatedoor_Tortuga2";			//to jungle stairs, was gatedoor

	Locations[n].locators_radius.randitem.randitem49 = 0.01;
	Locations[n].items.randitem49 = "bars_down";

	Locations[n].locators_radius.randitem.randitem50 = 0.01;
	Locations[n].items.randitem50 = "bars_down";

	Locations[n].locators_radius.randitem.randitem51 = 0.01;
	Locations[n].items.randitem51 = "bars_down";

	Locations[n].locators_radius.randitem.randitem52 = 0.01;
	Locations[n].items.randitem52 = "bars_down";

	Locations[n].locators_radius.randitem.randitem53 = 0.01;
	Locations[n].items.randitem53 = "medicine_table";

	Locations[n].locators_radius.randitem.randitem54 = 0.01;		//shipyard
	Locations[n].items.randitem54 = "2_lanternsA_night";

	Locations[n].locators_radius.randitem.randitem55 = 0.01;
	Locations[n].items.randitem55 = "2_lanternsA_day";

	Locations[n].locators_radius.randitem.randitem56 = 0.01;		//store
	Locations[n].items.randitem56 = "2_lanternsB_night";				//was A

	Locations[n].locators_radius.randitem.randitem57 = 0.01;
	Locations[n].items.randitem57 = "2_lanternsB_day";				//was A

	Locations[n].locators_radius.randitem.randitem58 = 0.01;		//prison
	Locations[n].items.randitem58 = "2_lanternsA_night";

	Locations[n].locators_radius.randitem.randitem59 = 0.01;
	Locations[n].items.randitem59 = "2_lanternsA_day";

	Locations[n].locators_radius.randitem.randitem60 = 0.01;		//loanshark
	Locations[n].items.randitem60 = "2_lanternsB_night";

	Locations[n].locators_radius.randitem.randitem61 = 0.01;
	Locations[n].items.randitem61 = "2_lanternsB_day";

	Locations[n].locators_radius.randitem.randitem62 = 0.01;		//townhall
	Locations[n].items.randitem62 = "2_lanternsB_night";

	Locations[n].locators_radius.randitem.randitem63 = 0.01;		
	Locations[n].items.randitem63 = "2_lanternsB_day";

	Locations[n].locators_radius.randitem.randitem64 = 0.01;		//brothel
	Locations[n].items.randitem64 = "2_lanternsC_night";

	Locations[n].locators_radius.randitem.randitem65 = 0.01;
	Locations[n].items.randitem65 = "2_lanternsC_day";

	Locations[n].locators_radius.randitem.randitem66 = 0.01;		//tavern
	Locations[n].items.randitem66 = "2_lanternsA_night";

	Locations[n].locators_radius.randitem.randitem67 = 0.01;
	Locations[n].items.randitem67 = "2_lanternsA_day";

	Locations[n].locators_radius.randitem.randitem68 = 0.01;		//Will Turner home
	Locations[n].items.randitem68 = "1_lanternD_night";

	Locations[n].locators_radius.randitem.randitem69 = 0.01;
	Locations[n].items.randitem69 = "1_lanternD_day";

	Locations[n].locators_radius.randitem.randitem70 = 0.01;
	Locations[n].items.randitem70 = "gatedoor_shipyard";			//shipyard backside

	Locations[n].locators_radius.randitem.randitem71 = 0.01;		//gate to stairs
	Locations[n].items.randitem71 = "1_lanternE_night";

	Locations[n].locators_radius.randitem.randitem72 = 0.01;
	Locations[n].items.randitem72 = "1_lanternE_day";

	Locations[n].locators_radius.randitem.randitem73 = 0.01;		//gate to stairs
	Locations[n].items.randitem73 = "1_lanternE_night";

	Locations[n].locators_radius.randitem.randitem74 = 0.01;
	Locations[n].items.randitem74 = "1_lanternE_day";

	Locations[n].locators_radius.randitem.randitem75 = 0.01;
	Locations[n].items.randitem75 = "tree2";

	Locations[n].locators_radius.randitem.randitem76 = 0.01;
	Locations[n].items.randitem76 = "tree2";

	Locations[n].locators_radius.randitem.randitem77 = 0.01;
	Locations[n].items.randitem77 = "tree2";

	Locations[n].locators_radius.randitem.randitem78 = 0.01;
	Locations[n].items.randitem78 = "tree2";

	Locations[n].locators_radius.randitem.randitem79 = 0.01;
	Locations[n].items.randitem79 = "tree2";

	Locations[n].locators_radius.randitem.randitem80 = 0.01;
	Locations[n].items.randitem80 = "palm2_big";

	Locations[n].locators_radius.randitem.randitem81 = 0.01;
	Locations[n].items.randitem81 = "palm2_big";

	Locations[n].locators_radius.randitem.randitem82 = 0.01;
	Locations[n].items.randitem82 = "palm2_big";

	Locations[n].locators_radius.randitem.randitem83 = 0.01;
	Locations[n].items.randitem83 = "palm2_big";

	Locations[n].locators_radius.randitem.randitem84 = 0.01;
	Locations[n].items.randitem84 = "palm2_big";

	Locations[n].locators_radius.randitem.randitem85 = 0.01;
	Locations[n].items.randitem85 = "ship_building";

	Locations[n].locators_radius.randitem.randitem86 = 0.01;
	Locations[n].items.randitem86 = "boat2_C";

	Locations[n].locators_radius.randitem.randitem87 = 0.01;
	Locations[n].items.randitem87 = "well";

	Locations[n].locators_radius.randitem.randitem88 = 0.01;
	Locations[n].items.randitem88 = "wagon";

	Locations[n].locators_radius.randitem.randitem89 = 0.01;
	Locations[n].items.randitem89 = "anchor_big";

	Locations[n].locators_radius.randitem.randitem90 = 0.01;
	Locations[n].items.randitem90 = "shipwreck";

	Locations[n].locators_radius.randitem.randitem91 = 0.01;
	Locations[n].items.randitem91 = "body";

	Locations[n].locators_radius.randitem.randitem92 = 0.01;
	Locations[n].items.randitem92 = "palm2_big";

	Locations[n].items.randitem93 = "clock1";

	Locations[n].locators_radius.randitem.randitem94 = 0.01;
	Locations[n].items.randitem94 = "boat2_C";

	Locations[n].locators_radius.randitem.randitem95 = 0.01;
	Locations[n].items.randitem95 = "boat2_B";

	Locations[n].locators_radius.randitem.randitem96 = 0.01;
	Locations[n].items.randitem96 = "plank2_very_long";

	Locations[n].locators_radius.randitem.randitem97 = 0.01;
	Locations[n].items.randitem97 = "anchor_big";

	Locations[n].locators_radius.randitem.randitem98 = 0.01;
	Locations[n].items.randitem98 = "ladder_very_big";

	Locations[n].locators_radius.randitem.randitem99 = 0.01;
	Locations[n].items.randitem99 = "gatedoor_Tortuga1";

	Locations[n].locators_radius.randitem.randitem100 = 0.01;
	Locations[n].items.randitem100 = "gatedoor_Tortuga1_night";

	Locations[n].locators_radius.randitem.randitem101 = 0.01;
	Locations[n].items.randitem101 = "chimney_45_night";

	Locations[n].locators_radius.randitem.randitem102 = 0.01;
	Locations[n].items.randitem102 = "chimney_45_night";

	Locations[n].locators_radius.randitem.randitem103 = 0.01;
	Locations[n].items.randitem103 = "chimney_45_night";

	Locations[n].locators_radius.randitem.randitem104 = 0.01;
	Locations[n].items.randitem104 = "chimney_45_night";

	Locations[n].locators_radius.randitem.randitem105 = 0.01;
	Locations[n].items.randitem105 = "chimney_45_night";

	Locations[n].locators_radius.randitem.randitem106 = 0.01;
	Locations[n].items.randitem106 = "chimney_45_night";

	Locations[n].locators_radius.randitem.randitem107 = 0.01;
	Locations[n].items.randitem107 = "chimney_45_night";

	Locations[n].locators_radius.randitem.randitem108 = 0.01;
	Locations[n].items.randitem108 = "chimney_45_night";

	Locations[n].locators_radius.randitem.randitem109 = 0.01;
	Locations[n].items.randitem109 = "chimney_pot_night";

	Locations[n].locators_radius.randitem.randitem110 = 0.01;
	Locations[n].items.randitem110 = "chimney_pot_night";

	Locations[n].locators_radius.randitem.randitem111 = 0.01;
	Locations[n].items.randitem111 = "chimney_pot_night";

	Locations[n].locators_radius.randitem.randitem112 = 0.01;
	Locations[n].items.randitem112 = "chimney_pot_night";

	Locations[n].locators_radius.randitem.randitem113 = 0.01;
	Locations[n].items.randitem113 = "chimney_45_night";

	Locations[n].locators_radius.randitem.randitem114 = 0.01;
	Locations[n].items.randitem114 = "chimney_45_night";

	Locations[n].locators_radius.randitem.randitem115 = 0.01;
	Locations[n].items.randitem115 = "chimney_pot_night";

	Locations[n].locators_radius.randitem.randitem116 = 0.01;
	Locations[n].items.randitem116 = "chimney_pot_night";

	Locations[n].locators_radius.randitem.randitem117 = 0.01;
	Locations[n].items.randitem117 = "tree2_night";

	Locations[n].locators_radius.randitem.randitem118 = 0.01;
	Locations[n].items.randitem118 = "tree2_night";

	Locations[n].locators_radius.randitem.randitem119 = 0.01;
	Locations[n].items.randitem119 = "tree2_night";

	Locations[n].locators_radius.randitem.randitem120 = 0.01;
	Locations[n].items.randitem120 = "tree2_night";

	Locations[n].locators_radius.randitem.randitem121 = 0.01;
	Locations[n].items.randitem121 = "tree2_night";

	Locations[n].locators_radius.randitem.randitem122 = 0.01;
	Locations[n].items.randitem122 = "palm2_big_night";

	Locations[n].locators_radius.randitem.randitem123 = 0.01;
	Locations[n].items.randitem123 = "palm2_big_night";

	Locations[n].locators_radius.randitem.randitem124 = 0.01;
	Locations[n].items.randitem124 = "palm2_big_night";

	Locations[n].locators_radius.randitem.randitem125 = 0.01;
	Locations[n].items.randitem125 = "palm2_big_night";

	Locations[n].locators_radius.randitem.randitem126 = 0.01;
	Locations[n].items.randitem126 = "palm2_big_night";

	Locations[n].locators_radius.randitem.randitem127 = 0.01;
	Locations[n].items.randitem127 = "palm2_big_night";

	Locations[n].locators_radius.randitem.randitem128 = 0.01;
	Locations[n].items.randitem128 = "ship_building_night";

	Locations[n].locators_radius.randitem.randitem129 = 0.01;
	Locations[n].items.randitem129 = "2_lanternsA_night";			//Tailor's

	Locations[n].locators_radius.randitem.randitem130 = 0.01;
	Locations[n].items.randitem130 = "2_lanternsA_day";			//Tailor's

	Locations[n].locators_radius.randitem.randitem131 = 0.01;
	Locations[n].items.randitem131 = "door_largeh";

	//WoodesRogers quest - - - - - - - - - - - - -

	Locations[n].locators_radius.randitem.randitem132 = 0.01;
	Locations[n].items.randitem132 = "hatch11";

	Locations[n].locators_radius.randitem.randitem133 = 0.01;
	Locations[n].items.randitem133 = "door_TortugaT";

	Locations[n].locators_radius.randitem.randitem134 = 0.01;
	Locations[n].items.randitem134 = "door_N10";

	Locations[n].locators_radius.randitem.randitem135 = 0.01;
	Locations[n].items.randitem135 = "ladder_medium";

	Locations[n].locators_radius.reload.reloadQ1 = 0.001;			//sailmaker 0.9 later
	Locations[n].locators_radius.reload.reloadQ2 = 0.2;
	Locations[n].locators_radius.reload.reloadQ3 = 0.2;
	Locations[n].locators_radius.reload.reloadQ4 = 0.001;			//small wood 1.5 later
	Locations[n].locators_radius.reload.reloadQ6 = 0.2;
	Locations[n].locators_radius.reload.reloadQ7 = 0.2;
	Locations[n].locators_radius.reload.reloadQ8 = 0.2;
	Locations[n].locators_radius.box.box2 = 0.2;
	Locations[n].locators_radius.box.box5 = 0.2;
	Locations[n].locators_radius.box.box7 = 0.2;
	Locations[n].locators_radius.box.box8 = 0.001;				//gunsmith 1.0 later
	Locations[n].locators_radius.box.box9 = 0.001;				//to carriage 1.5 later
	Locations[n].locators_radius.box.box11 = 0.2;
	Locations[n].locators_radius.box.box12 = 0.2;
	Locations[n].locators_radius.box.box13 = 0.2;
	Locations[n].locators_radius.box.box14 = 0.2;
	Locations[n].locators_radius.box.box15 = 0.2;
	Locations[n].locators_radius.box.box16 = 0.2;
	Locations[n].locators_radius.box.box17 = 0.2;
	Locations[n].locators_radius.box.box18 = 0.2;
	Locations[n].locators_radius.box.box19 = 0.2;
	Locations[n].locators_radius.box.box20 = 0.2;
	Locations[n].locators_radius.box.box21 = 0.2;
	Locations[n].locators_radius.box.box22 = 0.2;
	Locations[n].locators_radius.box.box23 = 0.2;
	Locations[n].locators_radius.box.box24 = 0.2;
	Locations[n].locators_radius.box.box25 = 0.2;
	Locations[n].locators_radius.box.box26 = 0.2;
	Locations[n].locators_radius.box.box27 = 0.2;
		
	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Tortuga_tailorsShop";
	Locations[n].filespath.models = "locations\Inside\StoreSmall";
	Locations[n].filespath.textures = "locations\inside\StoreSmall\Tortuga";	
	Locations[n].image = "Inside_Tortuga_Tailor.tga";
	locations[n].id.label = "Tailor's Shop.";
	//Town sack
	Locations[n].townsack = "Tortuga";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Tortuga";
	//Models
	//Always
	Locations[n].models.always.locators = "SS_l_Tortuga_tailor";
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
//	Locations[n].models.back = "back\qcss_";
	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "Tortuga_port";
	Locations[n].reload.l1.emerge = "Reload13";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.locator2 = 1.0;

	Locations[n].locators_radius.box.box1  = 0.0001;
	Locations[n].locators_radius.box.box2 = 0.0001;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.0001;
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

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "carpet3V";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Hispaniola";
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Dungeon_1_wood";
	Locations[n].id = "Tortuga_stairs";
	locations[n].id.label = "#stown_name# Exit";
	Locations[n].image = "Inside_Tortuga_stairs.tga";
	
	//Town sack
	Locations[n].townsack = "Tortuga";
	locations[n].fastreload = "Tortuga";

	//Sound
	locations[n].type = "silent_loghouse";

	//Models
	//Always
	Locations[n].models.always.locators = "d01_l_GB";			//was d01_l_JRH
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
	Locations[n].reload.l1.go = "Tortuga_port";
	Locations[n].reload.l1.emerge = "gate";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Tortuga_town_exit";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";				
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "gatedoor_small";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "gatedoor_small";

	Locations[n].locators_radius.randitem.randitem8 = 0.1;
	Locations[n].items.randitem8 = "gatedoor_w";

	Locations[n].island = "Hispaniola";
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\shipyard";
	Locations[n].filespath.textures = "locations\inside\shipyard\Tortuga";

	Locations[n].id = "Tortuga_shipyard";
	locations[n].id.label = "#stown_name# shipyard";
	Locations[n].image = "Inside_Shipyard_Tortuga.tga";

	//Town sack
	Locations[n].townsack = "Tortuga";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Tortuga";
	//Models
	//Always
	Locations[n].models.always.locators = "sh01_l_Tortuga";
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
	Locations[n].models.back = "back\tor3_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Tortuga_port";
	Locations[n].reload.l1.emerge = "reload5_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].reload.l2.name = "reload2";			//JRH backdoor to port
	Locations[n].reload.l2.go = "Tortuga_port";
	Locations[n].reload.l2.emerge = "reload11";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name#.";

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "door_Tortuga";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].id = "Tortuga_usurer";
	locations[n].id.label = "Loanshark's Office";
	//Town sack
	Locations[n].townsack = "Tortuga";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Tortuga";

	//InitBank(Locations[n].id);

	Locations[n].filespath.models = "locations\Inside\Bank";
	Locations[n].filespath.textures = "locations\inside\Bank\Tortuga";
	Locations[n].image = "Inside_Bank_Tortuga.tga";
	//Models
	Locations[n].models.back = "back\tor3_";				//JRH
	//Always
	Locations[n].models.always.cave = "Bank";
	Locations[n].models.always.locators = "Bank_locators_Tortuga";		//JRH
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
	Locations[n].reload.l1.emerge = "reload8_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.go = "Tortuga_port";
	Locations[n].reload.l1.label = "#stown_name#";

	Locations[n].locators_radius.randitem.randitem1 = 0.001;		//JRH		
	Locations[n].items.randitem1 = "carpet2";

	Locations[n].island = "Hispaniola";
	n = n + 1;

   // -------------------------------------------------

	Locations[n].id = "Tortuga_tavern";
	Locations[n].filespath.textures = "locations\inside\tavern01\Tortuga";
	//locations[n].id.label = "Tavern";
	locations[n].id.label = "The Dark Frigate";
	//Town sack
	Locations[n].townsack = "Tortuga";
	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "Tortuga";
	//Models

	Locations[n].filespath.models = "locations\Inside\Tavern01";
	Locations[n].image = "Inside_Tavern01_Tortuga.tga";
	//Models
	Locations[n].models.back = "back\tor_";					//JRH
	//Always
	Locations[n].models.always.cave = "Tavern01";
	Locations[n].models.always.locators = "Tavern01_locators_Tortuga";	//JRH
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
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.emerge = "reload4_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.go = "Tortuga_port";
	Locations[n].reload.l1.label = "#stown_name#";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.go = "Tortuga_tavern_upstairs";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Room in #stown_name# tavern.";
	Locations[n].reload.l2.disable = true; // KK

//JRH -->
	Locations[n].locators_radius.randitem.randitem1 = 0.1;		
	Locations[n].items.randitem1 = "hatch16_T";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;		
	Locations[n].items.randitem2 = "hatch16_T";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;		
	Locations[n].items.randitem3 = "hatch16_V";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;		
	Locations[n].items.randitem4 = "door_Tortuga";

	Locations[n].locators_radius.randitem.randitem5 = 0.1;		
	Locations[n].items.randitem5 = "hatch16_T";

	Locations[n].locators_radius.randitem.randitem6 = 0.1;		
	Locations[n].items.randitem6 = "hatch16_V";

	Locations[n].locators_radius.randitem.randitem7 = 0.1;		
	Locations[n].items.randitem7 = "hatch16_T";

	Locations[n].locators_radius.randitem.randitem8 = 0.1;		
	Locations[n].items.randitem8 = "hatch16_T";

	Locations[n].locators_radius.randitem.randitem9 = 0.1;		
	Locations[n].items.randitem9 = "hatch16_V";

	Locations[n].locators_radius.randitem.randitem10 = 0.1;		
	Locations[n].items.randitem10 = "hatch16_T";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;		
	Locations[n].items.randitem11 = "door_N06T";
//<-- JRH
	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Tortuga_tavern_upstairs";
	locations[n].id.label = "Room in #stown_name# tavern";
	Locations[n].image = "Inside_Tavern_Room_Tortuga.tga";

	//Town sack
	Locations[n].townsack = "Tortuga";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Tortuga";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Doubleflour_house";
	Locations[n].filespath.textures = "locations\inside\Doubleflour_house\wood_tower";
	Locations[n].models.always.locators = "LH_F2_l_Tortuga";
	Locations[n].models.always.tavern = "LH_F2";
//	Locations[n].models.always.window = "LH_F2_w";			//JRH
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "LH_F2_p";

	//Night
	Locations[n].models.night.charactersPatch = "LH_F2_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Locations[n].models.back = "back\redlf2_";
	Locations[n].models.back = "back\tor2_";				//JRH

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Tortuga_tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Tavern.";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;		
	Locations[n].items.randitem1 = "door_N06T";

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

 	//-------------------------------------------------

	Locations[n].id = "Tortuga_store";
	locations[n].id.label = "Store";
	//Town sack
	Locations[n].townsack = "Tortuga";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Tortuga";

	Locations[n].filespath.models = "locations\Inside\store01";
	Locations[n].filespath.textures = "locations\inside\store01\Tortuga";
	Locations[n].image = "Inside_Store01_Tortuga.tga";

	//Models
	Locations[n].models.back = "back\tor2_";				//JRH
	//Always
	Locations[n].models.always.cave = "store01";
	Locations[n].models.always.locators = "store01_locators";
	Locations[n].models.always.window = "store01_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "store01_patch";
	//Night
	Locations[n].models.night.charactersPatch = "store01_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.emerge = "reload6_back";
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.autoreload = "0";

	LAi_LocationFightDisable(&Locations[n], true);

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.go = "Tortuga_port";
	Locations[n].reload.l1.label = "#stown_name#";

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].id = "Tortuga_Brothel_bedroom";
	if (IsBrothelEnabled()) {
		locations[n].id.label = "Brothel Bedroom";
		//Town sack
		Locations[n].townsack = "Tortuga";
		//Sound
		locations[n].type = "brothel_room";
		locations[n].fastreload = "Tortuga";
		LAi_LocationFantomsGen(&locations[n], false);

		Locations[n].filespath.models = "locations\Inside\brothel_room";
		Locations[n].image = "Inside_Brothel_Room_Tortuga.tga";
		//Models
		Locations[n].filespath.textures = "locations\inside\brothel_room\Tortuga";
		Locations[n].models.back = "back\tor_";				//JRH
		
		//Always
		Locations[n].models.always.cave = "brothel_room";
		Locations[n].models.always.locators = "brothel_room_locators";
		Locations[n].models.always.window = "brothel_room_window";
		Locations[n].models.always.window.tech = "LocationWindows";
		Locations[n].models.always.window.level = 50;
		//Day
		Locations[n].models.day.charactersPatch = "brothel_room_patch";
		//Night
		Locations[n].models.night.charactersPatch = "brothel_room_patch";
		//Environment
		Locations[n].environment.weather = "false";
		Locations[n].environment.sea = "false";

		//Reload map
		Locations[n].reload.l1.name = "reload1";
		Locations[n].reload.l1.autoreload = "0";
		LAi_LocationFightDisable(&Locations[n], true);
		LAi_LocationMonstersGen(&Locations[n], false);

		Locations[n].island = "Hispaniola";
	}
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].id = "Tortuga_Brothel_room";
	if (IsBrothelEnabled()) {
		locations[n].id.label = "#stown_name# Brothel";
		Locations[n].filespath.models = "locations\inside\den";
		Locations[n].image = "Inside_Den_Room.tga"; // PB
		//Town sack
		Locations[n].townsack = "Tortuga";
		//Sound
		locations[n].type = "room";
		locations[n].fastreload = "Tortuga";
		LAi_LocationFantomsGen(&locations[n], false);
		//Models
		Locations[n].models.back = "back\tor_";				//JRH
		//Always
		Locations[n].models.always.city = "mh5";
		Locations[n].models.always.locators = "mh5_l";
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

		LAi_LocationFightDisable(&Locations[n], true);

		Locations[n].island = "Hispaniola";
	}
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].id = "Tortuga_Brothel";
	if (IsBrothelEnabled()) {
		InitTortugaBrothel(); // KK

		Locations[n].filespath.models = "locations\Inside\Brothel";
		Locations[n].image = "Inside_Brothel_Tortuga.tga";
		//Models
		Locations[n].models.back = "back\tor2_";				
		//Always
		Locations[n].models.always.cave = "Brothel";
		Locations[n].models.always.locators = "Brothel_locators";
		Locations[n].models.always.window = "Brothel_window";
		Locations[n].models.always.window.tech = "LocationWindows";
		Locations[n].models.always.window.level = 50;
		//Day
		Locations[n].models.day.charactersPatch = "Brothel_patch";
		//Night
		Locations[n].models.night.charactersPatch = "Brothel_patch";
		//Environment
		Locations[n].environment.weather = "false";
		Locations[n].environment.sea = "false";

		//Reload map
		Locations[n].reload.l1.name = "reload1";
		Locations[n].reload.l1.autoreload = "0";

		Locations[n].reload.l2.name = "reload1_back";
		Locations[n].reload.l2.autoreload = "0";

		Locations[n].reload.l3.name = "reload2_back";
		Locations[n].reload.l3.autoreload = "0";
		Locations[n].monsters = "0";

		LAi_LocationFightDisable(Locations[n], true);
	}
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].id = "Tortuga_StoneHouse";
	locations[n].id.label = "House";
	//Town sack
	Locations[n].townsack = "Tortuga";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Tortuga";

	Locations[n].filespath.models = "locations\Inside\StoneHouse";
	Locations[n].image = "Inside_Stonehouse_Tortuga.tga";
	//Models
	Locations[n].filespath.textures = "locations\inside\Stonehouse\Tortuga";
	Locations[n].models.back = "back\tor2_";				//JRH
	
	//Always
	Locations[n].models.always.cave = "StoneHouse";
	Locations[n].models.always.locators = "StoneHouse_locators";
	Locations[n].models.always.window = "StoneHouse_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "StoneHouse_patch";
	//Night
	Locations[n].models.night.charactersPatch = "StoneHouse_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.go = "Tortuga_Port";
	Locations[n].reload.l1.emerge = Locations[FindLocation(Locations[n].reload.l1.go)].reload.l11.name;
	Locations[n].reload.l1.label = "#stown_name#";

	Locations[n].island = "Hispaniola";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_Oxbay\exit";

	Locations[n].id = "Tortuga_town_exit";
	locations[n].id.label = "Jungle";
	Locations[n].image = "Town_Oxbay_Exit.tga";

	//Town sack
	Locations[n].townsack = "Tortuga";

	//Sound
	locations[n].type = "jungle";
//	locations[n].fastreload = "Tortuga";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "OXexit_l_Tortuga";	//JRH
	Locations[n].models.always.exit = "oxexit";
	Locations[n].models.always.grassPatch = "OXexit_g";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan_3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	Locations[n].models.always.l4 = "Tortuga_walls";		//JRH
	Locations[n].models.always.l5 = "flagpole";			//JRH
	Locations[n].models.always.l6 = "hill";				//JRH

	//Day
	Locations[n].models.day.charactersPatch = "OXexit_p";
	Locations[n].models.day.fonar = "OXexit_fd";
	//Night
	Locations[n].models.night.charactersPatch = "OXexit_p";
	Locations[n].models.night.fonar = "OXexit_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map
	//Locations[n].reload.l1.name = "reload3";
	//Locations[n].reload.l1.go = "Tortuga_town_01";	
	//Locations[n].reload.l1.emerge = "reload12";
	//Locations[n].reload.l1.autoreload = "0";
	//Locations[n].reload.l1.label = "#stown_name#.";

	//JRH change
	Locations[n].reload.l1.name = "reload3";
	Locations[n].reload.l1.go = "Tortuga_stairs";	
	Locations[n].reload.l1.emerge = "goto1";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "Reload2";
	Locations[n].reload.l2.go = "Tortuga_Jungle_01";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 2.0;

	Locations[n].reload.l3.name = "Reload1";
	Locations[n].reload.l3.go = "";
	Locations[n].reload.l3.emerge = "Reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1 = 4.0;

	Locations[n].reload.l4.name = "Reload2_back";
	Locations[n].reload.l4.go = "Tortuga_Jungle_01";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2_back = 2.0;

	Locations[n].reload.l5.name = "Reload1_back";
	Locations[n].reload.l5.go = "";
	Locations[n].reload.l5.emerge = "Reload2";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1_back = 3.0;

	Locations[n].locators_radius.randitem.randitem2 = 0.1;		//JRH
	Locations[n].items.randitem2 = "watchtower";

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Rheims House";

	Locations[n].id = "Tortuga_Jungle_01";
	locations[n].id.label = "House in Jungle";
	Locations[n].image = "Outside_Rheims_House.tga";
	//Sound
	locations[n].type = "house";

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
	Locations[n].reload.l1.go = "Tortuga_town_exit";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1 = 3;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Tortuga_town_exit";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 3;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "House";

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].id = "Tortuga_Townhall";
	locations[n].id.label = "#stown_name# Townhall";
	//Town sack
	Locations[n].townsack = "Tortuga";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Tortuga";

	Locations[n].filespath.models = "locations\Inside\StoreHouse";
	Locations[n].image = "Inside_Storehouse_Tortuga.tga";

	//Models
	Locations[n].models.back = "back\tor3_";
	//Always
	Locations[n].models.always.cave = "storehouse";
	Locations[n].models.always.locators = "storehouse_locators_Tortuga";
	Locations[n].models.always.window = "";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "storehouse_patch";
	//Night
	Locations[n].models.night.charactersPatch = "storehouse_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "Tortuga_port";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Tortuga_tower_passage";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.disable = 1;					//open in WoodesRogers quest part 2	

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Hispaniola";
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].id = "Tortuga_prison";
	locations[n].id.label = "#stown_name# prison";
	Locations[n].filespath.models = "locations\inside\prison";
	Locations[n].filespath.textures = "locations\inside\prison\Tortuga";
	Locations[n].image = "Inside_Prison_Tortuga.tga";

	//Town sack
	Locations[n].townsack = "Tortuga";

	//Sound
	locations[n].type = "Jail";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].fastreload = "Tortuga";

	Locations[n].locators_radius.camdetector.camera13 = 2.5;//Mosh
	Locations[n].locators_radius.camdetector.camera12 = 0.5;//Mosh
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
//	Locations[n].reload.l1.go = "Tortuga_town_01";
//	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.go = "Tortuga_port";
	Locations[n].reload.l1.emerge = "reload10_back";
	Locations[n].reload.l1.label = "Town";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\SmallTavern";	

	Locations[n].id = "BC_Tavern";
	locations[n].id.label = "#stown_name# tavern";
	Locations[n].image = "Inside_SmallTavern.tga";
	//Town sack
	Locations[n].townsack = "Buccaneers Camp"; // NK - "Oxbay";
	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "BuccaneersCamp";
	//Models
	//Always
	Locations[n].models.always.locators = "ST_l";
	Locations[n].models.always.l1 = "ST";
	Locations[n].models.always.window = "ST_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "ST_p";

	//Night
	Locations[n].models.night.charactersPatch = "ST_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\qcst_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Buccaneers_Camp";
	Locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Buccaneers Camp.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "BC_tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.disable = 1;
	Locations[n].reload.l2.label = "Room.";
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\SmallHome";	

	Locations[n].id = "BC_tavern_upstairs";
	locations[n].id.label = "Room in #stown_name# tavern";
	Locations[n].image = "Inside_Doubleflour_House_Room.tga"; // ccc: Skip VC in room
	//Town sack
	Locations[n].townsack = "Buccaneers Camp";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "BuccaneersCamp";
	//Models
	//Always
	Locations[n].models.always.locators = "SH_l";
	Locations[n].models.always.l1 = "SH";
	Locations[n].models.always.window = "sh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "SH_p";

	//Night
	Locations[n].models.night.charactersPatch = "SH_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\qcsh_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BC_tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Buccaneers tavern."; // KK


	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\StoreSmall";	
	Locations[n].image = "Inside_StoreSmall.tga";

	Locations[n].id = "BC_Store";
	locations[n].id.label = "#stown_name# store";
	//Town sack
	Locations[n].townsack = "Buccaneers Camp";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "BuccaneersCamp";
	//Models
	//Always
	Locations[n].models.always.locators = "SS_l";
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
	Locations[n].reload.l1.go = "Buccaneers_Camp";
	Locations[n].reload.l1.emerge = "Reload6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Buccaneers Camp.";
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

// Forger's house -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\SmallHome";

	Locations[n].id = "BC_ForgerHouse";
	locations[n].id.label = "House of Pablo Escriva.";
	Locations[n].image = "Inside_Smallhome.tga";
	//Town sack
	Locations[n].townsack = "Buccaneers Camp"; // GR - wrong, but less wrong than others
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "BuccaneersCamp";
	//Models
	//Always
	Locations[n].models.always.locators = "Sh_L";
	Locations[n].models.always.l1 = "SH";
	Locations[n].models.always.window = "sh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "SH_p";

	//Night
	Locations[n].models.night.charactersPatch = "SH_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\qcsh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Buccaneers_Camp";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Buccaneers Camp.";
	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].vcskip = true;

	Locations[n].island = "Hispaniola"; // GR 2017-01-02
	n = n + 1;

	// Village_church -------------------------------------------------
	Locations[n].id = "Village_church";
	locations[n].id.label = "Village church";
	Locations[n].image = "Inside_Church_3.tga";
	Locations[n].filespath.models = "locations\inside\Church_3";

	//Town sack
	Locations[n].townsack = "Santo Domingo";

	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "Hispaniola";
	//Models
	//Always
	Locations[n].models.always.city = "Church3";
	Locations[n].models.always.locators = "Church3_l";
	Locations[n].models.always.window = "church3_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
//	Locations[n].models.day.lamp = "FalaiseDeFleur05_day";
	Locations[n].models.day.charactersPatch = "Church3_p";

	//Night
//	Locations[n].models.night.lamp = "FalaiseDeFleur05_night";
	Locations[n].models.night.charactersPatch = "Church3_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Hispaniola_Village_exit";
	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Village Exit.";
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	//HOUSES----------------
	// -------------------------------------------------
	Locations[n].id = "Santo_Domingo_House_01";
	Locations[n].id.label = "House";
	Locations[n].image = "Inside_mh10.tga";

	//Town sack
	Locations[n].townsack = "Santo Domingo";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Santo_Domingo";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\mh10";
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
	Locations[n].models.back = "back\oxmh10_";

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Santo_Domingo_town";
	Locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Town";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Santo_Domingo_Historian_House";
	Locations[n].id.label = "House in #stown_name#";
	Locations[n].image = "Inside_Residence2.tga";
	Locations[n].filespath.models = "locations\inside\Residence2";

	//Town sack
	Locations[n].townsack = "Santo Domingo";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Santo_Domingo";
	//Models
	//Always
	Locations[n].models.always.city = "Res02";
	Locations[n].models.always.locators = "Res02_l_ccc";
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
	Locations[n].reload.l1.go = "Santo_Domingo_town";
	Locations[n].reload.l1.emerge = "reload25";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Town";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].vcskip = true;

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// --------------------------------------------------
	// HOUSES
	// -^------------------------------------------------

	Locations[n].id = "Santo_Domingo_House_02";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\mh6";
	Locations[n].image = "Inside_mh6.tga";

	//Town sack
	Locations[n].townsack = "Santo Domingo";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Santo_Domingo";
	//Models
	//Always
	Locations[n].models.always.locators = "mh6_l";
	Locations[n].models.always.house = "mh6";
	Locations[n].models.always.window = "mh6_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "mh6_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh6_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\ffmh6_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Santo_Domingo_port";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Sea port.";

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Doubleflour_house";
	Locations[n].id = "PoPrince_House_01";
	locations[n].id.label = "House";
	Locations[n].image = "Inside_Doubleflour_House_Room.tga";

	//Town sack
	Locations[n].townsack = "Port au prince";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PoPrince";
	//Models
	//Always
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
	Locations[n].models.back = "back\mulf2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "PoPrince_town";
	Locations[n].reload.l1.emerge = "reload12";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Town.";

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "PoPrince_House_02";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house";
	Locations[n].image = "Inside_Doubleflour_House_Lower.tga";

	//Town sack
	Locations[n].townsack = "Port au prince";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "PoPrince";
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
	Locations[n].models.back = "back\fflf1_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "PoPrince_town";
	Locations[n].reload.l1.emerge = "reload18";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Town.";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Pirate_House";

	Locations[n].id = "Will_Turner_house_inside";
	locations[n].id.label = "Will Turner's House";
	Locations[n].image = "Inside_Pirate_House.tga";
	//Sound
	locations[n].type = "house";
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
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Locations[n].models.back = "back\qcpirh_";
	Locations[n].models.back = "back\tor2_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
//	Locations[n].reload.l1.go = "Tortuga_Town_01";
//	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].reload.l1.go = "Tortuga_port";
	Locations[n].reload.l1.emerge = "reload9_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Exit.";


	Locations[n].island = "Hispaniola"; 
	n = n + 1; 

	// -------------------------------------------------


// Additional Buildings, works only if Buildingset is installed -----------------------
	Build_at("Hispaniola_jungle_07", "jungle2", "", -3.52, -0.27, -0.1, 2.82, "wild_jungles");
	Build_at("Hispaniola_jungle_07", "jungle2", "", -2.29, -1.60, -15.13, 0.31, "wild_jungles");
	Build_at("Hispaniola_jungle_07", "jungle2", "", 20.10, -2.34, -25.54, -0.37, "wild_jungles");
	Build_at("Hispaniola_jungle_07", "jungle2", "", 2.95, -1.95, -10.00, -2.85, "wild_jungles");
	Build_at("Hispaniola_jungle_07", "jungle2", "", -7.45, -0.10, 13.87, 2.71, "wild_jungles");
	Build_at("Hispaniola_jungle_07", "jungle2", "", 20.68, 0.29, 21.10, 0.24, "wild_jungles");
	Build_at("Hispaniola_jungle_07", "jungle2", "", -15.00, 0.12, -21.20, -0.28, "wild_jungles");
	Build_at("Hispaniola_jungle_07", "jungle2", "", -18.87, 0.29, -16.61, 2.17, "wild_jungles");
	Build_at("Hispaniola_jungle_07", "jungle", "", 9.75, -1.92, -18.23, 1.38, "wild_jungles");
	Build_at("Hispaniola_jungle_07", "jungle2", "", 9.75, -1.92, -18.23, 1.38, "wild_jungles");
	Build_at("Hispaniola_Shore_03", "jungle2", "", -0.46, 2.05, -12.65, 0.10, "wild_jungles");
	Build_at("Hispaniola_Shore_03", "jungle2", "", 9.5, 3.68, -22.01, 0.39, "wild_jungles");
	Build_at("Hispaniola_Shore_02", "jungle2", "", -19.95, 2.33, 42.89, 0.32, "wild_jungles");
	Build_at("Hispaniola_Shore_02", "jungle2", "", -13.61, 4.19, 11.41, -0.28, "wild_jungles");
	Build_at("Hispaniola_Temple", "jungle2", "", -68.15, 5.30, 56.72, 0.23, "wild_jungles");
	Build_at("Hispaniola_Temple", "jungle2", "", -30.83, 15.28, 16.94, -1.80, "wild_jungles");
	Build_at("Hispaniola_jungle_09", "jungle2", "", 3.83, -0.79, -2.79, -2.66, "wild_jungles");
	Build_at("Hispaniola_Passage", "jungle2", "", 21.00, 10.25, -13.27, -1.82, "wild_jungles");
	Build_at("Hispaniola_jungle_02", "jungle2", "", -19.56, -2.59, -145.53, -1.11, "wild_jungles");
	Build_at("Hispaniola_jungle_02", "jungle2", "", -15.97, -2.55, -119.08, 0.17, "wild_jungles");
	Build_at("Hispaniola_jungle_02", "jungle2", "", -48.46, -2.39, -102.47, 1.57, "wild_jungles");
	Build_at("Hispaniola_jungle_02", "jungle2", "", -29.39, -2.49, -91.46, -3.13, "wild_jungles");
	Build_at("Hispaniola_jungle_02", "jungle2", "", -27.64, -3.40, -69.12, 1.63, "wild_jungles");
	//Build_at("Hispaniola_jungle_03", "jungle2", "", 1.98, 0.40, -12.71, 0.29, "wild_jungles");
	//Build_at("Hispaniola_jungle_03", "jungle2", "", 7.13, 0.01, -8.50, -2.26, "wild_jungles");
	//Build_at("Hispaniola_jungle_03", "jungle2", "", -5.98, 1.03, -6.43, 2.61, "wild_jungles");
	//Build_at("Hispaniola_jungle_03", "jungle2", "", -20.14, 0.19, -9.96, 0.12, "wild_jungles");
	Build_at("Hispaniola_jungle_04", "jungle2", "", 6.07, 0.00, -24.51, 2.01, "wild_jungles");
	Build_at("Hispaniola_jungle_04", "jungle2", "", 14.97, 0.00, -13.85, -1.86, "wild_jungles");
	Build_at("Hispaniola_jungle_04", "jungle2", "", 9.65, 0.00, -2.70, 2.07, "wild_jungles");
	Build_at("Hispaniola_jungle_04", "jungle2", "", 19.35, 0.00, -1.91, -1.52, "wild_jungles");
	Build_at("Hispaniola_jungle_04", "jungle2", "", 12.01, 0.00, 10.42, -1.53, "wild_jungles");
	Build_at("Hispaniola_jungle_04", "jungle2", "", -3.20, 0.47, 14.69, -0.22, "wild_jungles");
	Build_at("Hispaniola_jungle_05", "jungle2", "", 4.55, -2.08, -12.74, -2.59, "wild_jungles");
	Build_at("Hispaniola_jungle_05", "jungle2", "", -5.84, -0.82, -18.78, -0.11, "wild_jungles");
	Build_at("PoPrince_Town_Exit", "jungle2", "", -26.52, -2.46, -108.29, 2.89, "wild_jungles");
	Build_at("Hispaniola_village_Exit", "house", "", 6.32, 0.00, 18.78, -1.85, "building");
	Build_at("Hispaniola_village_Exit", "house", "", -20.18, 0.00, -8.63, 1.09, "building");
	Build_at("Hispaniola_village_Exit", "farm", "", 11.61, 0.45, -10.35, -1.37, "building");
	Build_at("Hispaniola_village_Exit", "church", "", -24.73, -0.21, 4.45, 1.52, "building");
	Build_at("Hispaniola_village_Exit", "windmill", "windmillfan", 13.67, 0.00, -0.51, -1.83, "building");
	Build_at("Hispaniola_village_Exit", "windmill", "windmillfan", 13.67, 0.00, -0.51, -1.83, "building");
	Build_at("Hispaniola_village_Exit", "box", "mine", -22.97, 0.43, -14.75, 1.23, "building");
	Build_at("Hispaniola_village_Exit", "jungle2", "", 27.51, 0.10, 2.30, -3.07, "wild_jungles");
	Build_at("Hispaniola_village_Exit", "jungle2", "", 23.92, 0.02, 1.62, 0.07, "wild_jungles");
	Build_at("Santo_Domingo_town_exit_1", "jungle", "", -20.35, -2.55, -96.56, -1.02, "wild_jungles");
	Build_at("Santo_Domingo_town_exit_1", "farm", "", -11.79, -2.56, -111.82, -0.84, "building");
	Build_at("Santo_Domingo_town_exit_1", "farm", "", -23.49, -2.29, -64.58, -0.97, "building");
	Build_at("Santo_Domingo_town_exit_1", "house", "", -42.52, -2.44, -59.89, 1.77, "building");
	//Build_at("Santo_Domingo_town_exit_1", "college", "", -32.21, -2.50, -48.64, -2.90, "building"); // BOP: Cannot be placed properly
	Build_at("Santo_Domingo_town_exit_1", "jungle", "", -46.14, -2.55, -102.21, 2.84, "wild_jungles");
	Build_at("Santo_Domingo_town_exit_1", "jungle2", "", -46.14, -2.55, -102.21, 2.84, "wild_jungles");
	Build_at("Hispaniola_jungle_08", "Windmill", "", -4.00, 1.81, -0.10, -1.60, "building");
	Build_at("Hispaniola_jungle_08", "jungle", "", 11.68, 0.15, 22.21, -1.24, "wild_jungles");
	Build_at("Tortuga_port", "dovecote", "", -25.5, 76.00, -80.1, -1.17, "building");
	Build_at("Tortuga_port", "stone_floor", "", -24.9, 81.3, -77.0, -1.17, "building");
}
