 
void LocationInitQuestLocations(ref n)
{
	Locations[n].id = "mutiny_cabin";
	Locations[n].id.label = "Officer's cabin";
	//Info
	Locations[n].filespath.models = "locations\decks\Cabin\cap";
	Locations[n].image = "Deck_Cap.tga";

	//locations[n].lockWeather = "Inside";//no effect
	//Sound
	Locations[n].type = "Rogers_gunroom";
	
	//Models
	//Always
	Locations[n].models.always.locators = "cap_l_JRH_mutiny";	
	Locations[n].models.always.l1 = "cap";
	Locations[n].models.always.window = "cap_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "cap_p";
	Locations[n].models.day.fonar = "cap_fd";
	//Night
	Locations[n].models.night.charactersPatch = "cap_p";
	Locations[n].models.night.fonar = "cap_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "mutiny_deckWR";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "mutiny_deckWR";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].reload.l2.disable = 1;
	locations[n].locators_radius.reload.reload2 = 0.5;	

	Locations[n].locators_radius.box.box1 = 0.1;
	Locations[n].locators_radius.box.box2 = 0.1;

	Locations[n].locators_radius.goto.check1 = 2.0;
	Locations[n].locators_radius.goto.goto4 = 2.0;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_M11";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "mutinyknife";
	
	Locations[n].rats = "true";
	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; 
	n = n + 1;
//--------------------------------------------------------------------------

	Locations[n].id = "mutiny_deckWR";
	locations[n].id.label = "Somewhere in the Caribbean";
	//Info
	Locations[n].filespath.models = "locations\decks\deckLow";
	Locations[n].image = "Sea.tga";
	//Sound
	locations[n].type = "silent_seashore";
	Locations[n].lockCamAngle = 0.2;			//was 0.4
	Locations[n].camshuttle = 1;

	//Models
	//Always
	Locations[n].models.always.locators = "deckLow_ld_JRH";
	Locations[n].models.always.l1 = "deckLow";
	
	//Day
	Locations[n].models.day.charactersPatch = "deckLow_p";
	Locations[n].models.day.fonar = "deckLow_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deckLow_p";
	Locations[n].models.night.fonar = "deckLow_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].windinfo = "true";
	
	Locations[n].MaxSeaHeight = 0.6; //JRH          was 0.8 by screwface
	//============| Reload map |============//
	// Captain's cabin
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "mutiny_cabin";
	Locations[n].reload.l1.emerge = "goto4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.disable = 1;
	
	Locations[n].locators_radius.goto.goto32 = 2.0;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "swamp_island1";

	Locations[n].rats = "true";
	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; 
	n = n + 1;
	
//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\jungle2";
	Locations[n].id = "Swamp_island1";
	locations[n].id.label = "Marooned Island";
	Locations[n].image = "wr_marooned_island.tga";
	//Town sack
	locations[n].townsack = "Redmond";
	//Sound
	locations[n].type = "silent_seashore";
	//locations[n].type = "prison_ships";
   	//Models
    	//Always
   	Locations[n].models.always.locators = "Jungle2_locators_JRH1";	
   	Locations[n].models.always.jungle = "Jungle2";
   	Locations[n].models.always.grassPatch = "JUNGLE2_grass";

// 	Locations[n].models.always.l1 = "plan1";
   	Locations[n].models.always.l1.level = 9;
   	Locations[n].models.always.l1.tech = "LocationModelBlend";
// 	Locations[n].models.always.l2 = "plan2";
    	Locations[n].models.always.l2.level = 8;
   	Locations[n].models.always.l2.tech = "LocationModelBlend";
//  	Locations[n].models.always.l3 = "plan3";
    	Locations[n].models.always.l3.level = 7;
    	Locations[n].models.always.l3.tech = "LocationModelBlend";

    	//Day
   	 Locations[n].models.day.charactersPatch = "Jungle2_patch";
    	//Night
    	Locations[n].models.night.charactersPatch = "Jungle2_patch";
    	//Environment
    	Locations[n].environment.weather = "true";
    	Locations[n].environment.sea = "true";
    
	//Reload map
	Locations[n].locators_radius.box.box4 = 4;
	Locations[n].locators_radius.box.box5 = 3;
	Locations[n].locators_radius.box.box6 = 4;

	Locations[n].locators_radius.box.box7 = 2.5;		
	Locations[n].locators_radius.goto.push7 = 3;

	Locations[n].locators_radius.box.box9 = 0.5;
	Locations[n].locators_radius.box.box10 = 3;
	Locations[n].locators_radius.box.box12 = 6;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "swamp_island2";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "shipwreck2";

	Locations[n].island = "Redmond"; 
	n = n + 1;

//--------------------------------------------------------------------------

	locations[n].id = "Swamp_island2";
	//locations[n].id = "TownExitW_flooded";
	locations[n].id.label = "Swamp Island";
	locations[n].image = "wr_shipwreck_island.tga";
	//Town sack
	locations[n].townsack = "Redmond";
	//Sound
	locations[n].type = "silent_seashore";
	//locations[n].type = "prison_ships";
	//locations[n].islandId = "Redmond";
	//locations[n].islandIdAreal = "Cartahena";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Swamp_Island2";
	Locations[n].models.always.townExit = "townExitW";

//	Locations[n].models.always.townWalls = "townExitW_stucco";
	Locations[n].models.always.locators = "townExitW_locators_JRH4";
		
	Locations[n].models.always.grassPatch = "townExitW_grass";
//	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
	
//	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
//	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
//	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	
	//Day
	locations[n].models.day.charactersPatch = "townExitW_patch";
//	locations[n].models.day.fonars = "townExitW_fd";
	//Night
	locations[n].models.night.charactersPatch = "townExitW_patch";
//	locations[n].models.night.fonars = "townExitW_fn";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	
	//Reload map
	locations[n].reload.l1.name = "reload4";
	locations[n].reload.l1.go = "Cartahena_town";
	locations[n].reload.l1.emerge = "gate_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Cartahena";

	locations[n].reload.l4.name = "reload3_back";
	locations[n].reload.l4.go = "swamp_wreck_inside";
	locations[n].reload.l4.emerge = "reload7";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Cartahena Fort";
	locations[n].locators_radius.reload.reload3_back = 2.0;

	locations[n].reload.l5.name = "reload5";
	locations[n].reload.l5.go = "loghouse";
	locations[n].reload.l5.emerge = "goto2";			//inside blockhouse
	locations[n].reload.l5.autoreload = "0";
	locations[n].reload.l5.label = "Cartahena Fort";

	locations[n].reload.l7.name = "reload7";
	locations[n].reload.l7.go = "swamp_wreck_inside";
	locations[n].reload.l7.emerge = "goto_fall";			//inside blockhouse
	locations[n].reload.l7.autoreload = "0";
	locations[n].reload.l7.label = "Cartahena Fort";

	locations[n].reload.l8.name = "reload8";
	locations[n].reload.l8.go = "Swamp_grot";
	locations[n].reload.l8.emerge = "reload1";			
	locations[n].reload.l8.autoreload = "0";
	locations[n].reload.l8.label = "Cartahena Fort";

	locations[n].locators_radius.reload.reload9 = 0.0001;

	Locations[n].locators_radius.box.box7 = 0.01;			//start to build one
	Locations[n].locators_radius.box.box16 = 2;			//just looking at logs

	Locations[n].locators_radius.box.box8 = 2.0;			//ri 15
	Locations[n].locators_radius.box.box9 = 1.0;			//ri 20
	Locations[n].locators_radius.box.box10 = 1.5;			//ri  7
	Locations[n].locators_radius.box.box11 = 1.0;
	Locations[n].locators_radius.box.box12 = 2.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "mill_destroyed";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "forest";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "forest";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "forest";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "forest";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "shipwreck2";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;	
	Locations[n].items.randitem7 = "raft_ropes";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "koster1";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "koster1";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "koster1";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "koster1";

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "koster1";

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "koster1";

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
	Locations[n].items.randitem14 = "koster1";

	Locations[n].locators_radius.randitem.randitem15 = 0.00001;			
	Locations[n].items.randitem15 = "koster1";

	Locations[n].locators_radius.randitem.randitem16 = 0.001;
	Locations[n].items.randitem16 = "koster1";

	Locations[n].locators_radius.randitem.randitem17 = 0.001;
	Locations[n].items.randitem17 = "koster1";

	Locations[n].locators_radius.randitem.randitem18 = 0.001;
	Locations[n].items.randitem18 = "koster1";
	
	Locations[n].locators_radius.randitem.randitem19 = 1.5;			
	Locations[n].items.randitem19 = "koster3";

	Locations[n].locators_radius.randitem.randitem20 = 0.00001;			
	Locations[n].items.randitem20 = "koster4";

	Locations[n].locators_radius.randitem.randitem21 = 0.001;
	Locations[n].items.randitem21 = "koster3";

	Locations[n].locators_radius.randitem.randitem22 = 0.001;
	Locations[n].items.randitem22 = "koster3";

	Locations[n].locators_radius.randitem.randitem23 = 0.001;
	Locations[n].items.randitem23 = "koster3";

	Locations[n].locators_radius.randitem.randitem24 = 0.001;
	Locations[n].items.randitem24 = "Door_N06";

	Locations[n].locators_radius.randitem.randitem25 = 0.001;
	Locations[n].items.randitem25 = "koster5";

	Locations[n].locators_radius.randitem.randitem26 = 0.001;
	Locations[n].items.randitem26 = "koster3";

	Locations[n].locators_radius.randitem.randitem27 = 0.001;
	Locations[n].items.randitem27 = "koster2";

	Locations[n].locators_radius.randitem.randitem28 = 0.001;
	Locations[n].items.randitem28 = "koster2";
	
	Locations[n].locators_radius.randitem.randitem29 = 0.001;
	Locations[n].items.randitem29 = "koster5";

	Locations[n].locators_radius.randitem.randitem30 = 0.001;
	Locations[n].items.randitem30 = "door_H1";

	Locations[n].locators_radius.randitem.randitem31 = 1.5;			
	Locations[n].items.randitem31 = "koster3";

	Locations[n].locators_radius.randitem.randitem32 = 0.001;			
	Locations[n].items.randitem32 = "raft2_logs";

	Locations[n].locators_radius.randitem.randitem33 = 0.001;			
	Locations[n].items.randitem33 = "raft2_ropes";

	Locations[n].locators_radius.randitem.randitem34 = 0.001;				
	Locations[n].items.randitem34 = "swamp_island1";

	Locations[n].island = "Redmond";
	n = n + 1;
//--------------------------------------------------------------------------

	locations[n].id = "swamp_wreck_inside";
	locations[n].id.label = "Swamp Wreck";
	locations[n].filespath.models = "locations\decks\SwampWreck";
	locations[n].image = "wr_wreck_inside.tga";
	//Town sack
	locations[n].townsack = "Redmond";
	locations[n].lockWeather = "Inside";
	//Sound
	//locations[n].type = "prison_ships";
	locations[n].type = "galleon_open";
	//locations[n].fastreload = "LostShipsCity";
	//locations[n].islandId = "LostShipsCity";	
	//Models
	//Always	
//	Locations[n].models.always.inside = "CeresSmithy";
//	Locations[n].models.always.inside.level = 65538;
    Locations[n].models.always.l1 = "CeresSmithy";
    Locations[n].models.always.l1.level = 65538;
	Locations[n].models.always.seabed = "CeresSmithy_sb";
//	Locations[n].models.always.outdoor = "CeresSmithy_outdoor";		
//	Locations[n].models.always.reflect = "CeresSmithy_reflect";
	Locations[n].models.always.reflect.level = 65531;
	Locations[n].models.always.reflect.sea_reflection = 1;	
	Locations[n].models.always.windows = "CeresSmithy_windows";
	Locations[n].models.always.windows.tech = "LocationWindows";
	Locations[n].models.always.windows.level = 65539;	
//	Locations[n].models.always.sails = "CeresSmithy_sails";
	Locations[n].models.always.sails.tech = "LocationWindows";
	Locations[n].models.always.sails.level = 65534;	
//	Locations[n].models.always.plan1 = "Plan1";
	Locations[n].models.always.plan1.tech = "LocationWindows";
	Locations[n].models.always.plan1.level = 65533;
	Locations[n].models.always.plan1.sea_reflection = 1;	
//	Locations[n].models.always.plan2 = "Plan2";
	Locations[n].models.always.plan2.tech = "LocationWindows";
	Locations[n].models.always.plan2.level = 65532;	
	Locations[n].models.always.locators = "CeresSmithy_locators_JRH";	
	Locations[n].models.always.grassPatch = "CeresSmithy_grass";
//	Locations[n].models.always.grassPatch.texture = "grass\algaeU1.tga.tx";					
	//Day
	locations[n].models.day.charactersPatch = "CeresSmithy_patch_day";
	//Locations[n].models.day.jumpPatch = "CeresSmithy_jump_patch";
//	locations[n].models.day.fonarday = "CeresSmithy_fd";	
	//Night
	locations[n].models.night.charactersPatch = "CeresSmithy_patch_day";	
	//Locations[n].models.night.jumpPatch = "CeresSmithy_jump_patch";
//	Locations[n].models.night.fonarnight = "CeresSmithy_fn";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Swamp_island2";
	locations[n].reload.l1.emerge = "goto1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "LSC Town";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Swamp_island2";
	locations[n].reload.l2.emerge = "reload3_back";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "LSC Town";
	Locations[n].reload.l2.disable = 1;

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "Swamp_island2";
	locations[n].reload.l3.emerge = "reload3_back";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "LSC Town";
	Locations[n].reload.l3.disable = 1;

	locations[n].reload.l4.name = "reload4";
	locations[n].reload.l4.go = "Swamp_island2";
	locations[n].reload.l4.emerge = "reload3_back";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "LSC Town";
	Locations[n].reload.l4.disable = 1;

	locations[n].reload.l5.name = "reload5";
	locations[n].reload.l5.go = "Swamp_island2";
	locations[n].reload.l5.emerge = "reload3_back";
	locations[n].reload.l5.autoreload = "0";
	locations[n].reload.l5.label = "LSC Town";
	Locations[n].reload.l5.disable = 1;

	locations[n].reload.l6.name = "reload6";
	locations[n].reload.l6.go = "Swamp_island2";
	locations[n].reload.l6.emerge = "reload3_back";
	locations[n].reload.l6.autoreload = "0";
	locations[n].reload.l6.label = "LSC Town";
	Locations[n].reload.l6.disable = 1;

	locations[n].reload.l7.name = "reload7";
	locations[n].reload.l7.go = "Swamp_island2";
	locations[n].reload.l7.emerge = "reload3";
	locations[n].reload.l7.autoreload = "0";
	locations[n].reload.l7.label = "LSC Town";

	locations[n].reload.l8.name = "reload8";
	locations[n].reload.l8.go = "Swamp_island2";
	locations[n].reload.l8.emerge = "reload3_back";
	locations[n].reload.l8.autoreload = "0";
	locations[n].reload.l8.label = "LSC Town";
	Locations[n].reload.l8.disable = 1;

	Locations[n].rats = "true";
	Locations[n].island = "Redmond";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Loghouse";
	locations[n].id.label = "Log-house";		//open = on, try from start
	Locations[n].image = "wr_loghouse.tga";

	//Town sack
	Locations[n].townsack = "Redmond";
	//locations[n].lockWeather = "Inside";//no effect
	//Sound
	locations[n].type = "silent_loghouse";

	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Smallhome";
	Locations[n].filespath.textures = "locations\inside\Smallhome\loghouse";

	Locations[n].models.always.city = "sh";
	Locations[n].models.always.locators = "sh_l_JRH_loghouse";
	Locations[n].models.always.window = "sh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "sh_p";

	//Night
	Locations[n].models.night.charactersPatch = "sh_p";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.2;

	//Reload map
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Swamp_island2";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Storeroom attic";
	Locations[n].locators_radius.reload.reload2 = 0.7;
				
	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "hatch11V";			//cover one window

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	//Locations[n].items.randitem2 = "door_NGR";			
	Locations[n].items.randitem2 = "door_N06";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	//Locations[n].items.randitem3 = "door_NGR";			
	Locations[n].items.randitem3 = "door_N06";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond";
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Grot";

	Locations[n].id = "Swamp_grot";
	locations[n].id.label = "Pirate's Cave";
	Locations[n].image = "Inside_Grot.tga";
	//Sound
	locations[n].type = "silent_cave_seashore";
	//Models
	Locations[n].models.back = "back\grotenv_";
	//Always
	Locations[n].models.always.cave = "Grot";
	Locations[n].models.always.locators = "Grot_l_JRH";
	//Day
	Locations[n].models.day.charactersPatch = "Grot_p";
	//Night
	Locations[n].models.night.charactersPatch = "Grot_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Swamp_island2";
	Locations[n].reload.l1.emerge = "reload9";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].locators_radius.randitem.randitem1 = 0.0001;
	Locations[n].items.randitem1 = "gatedoor_w7";
	
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------
	locations[n].id = "at_sea_in_fog";
	//locations[n].id = "TownExitW_flooded";
	locations[n].id.label = "";
	Locations[n].image = "Sea.tga";
	//Town sack
	locations[n].townsack = "Redmond";
	//Sound
	locations[n].type = "silent_seashore";
	//Models
	//Always
	locations[n].filespath.models = "locations\Outside\Swamp_Island2";
	Locations[n].models.always.townExit = "townExitW";

//	Locations[n].models.always.townWalls = "townExitW_stucco";
	Locations[n].models.always.locators = "townExitW_locators_JRH_sea";
		
	Locations[n].models.always.grassPatch = "townExitW_grass";
//	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
	
//	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
//	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
//	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	
	//Day
	locations[n].models.day.charactersPatch = "townExitW_patch";
//	locations[n].models.day.fonars = "townExitW_fd";
	//Night
	locations[n].models.night.charactersPatch = "townExitW_patch";
//	locations[n].models.night.fonars = "townExitW_fn";	
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	Locations[n].windinfo = "true";
	Locations[n].MaxSeaHeight = 0.1;
	
	//Reload map
	locations[n].reload.l1.name = "reload4";
	locations[n].reload.l1.go = "Cartahena_town";
	locations[n].reload.l1.emerge = "gate_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Cartahena";

	locations[n].reload.l4.name = "reload3_back";
	locations[n].reload.l4.go = "swamp_wreck_inside";
	locations[n].reload.l4.emerge = "reload7";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Cartahena Fort";
	locations[n].locators_radius.reload.reload3_back = 2.0;

	locations[n].reload.l5.name = "reload5";
	locations[n].reload.l5.go = "loghouse";
	locations[n].reload.l5.emerge = "goto2";			//inside blockhouse
	locations[n].reload.l5.autoreload = "0";
	locations[n].reload.l5.label = "Cartahena Fort";

	locations[n].reload.l7.name = "reload7";
	locations[n].reload.l7.go = "swamp_wreck_inside";
	locations[n].reload.l7.emerge = "goto_fall";			//inside blockhouse
	locations[n].reload.l7.autoreload = "0";
	locations[n].reload.l7.label = "Cartahena Fort";

	locations[n].reload.l8.name = "reload8";
	locations[n].reload.l8.go = "Swamp_grot";
	locations[n].reload.l8.emerge = "reload1";			
	locations[n].reload.l8.autoreload = "0";
	locations[n].reload.l8.label = "Cartahena Fort";

	Locations[n].island = "Redmond";
	n = n + 1;

	//--------------------------------------------------------------------------

	Locations[n].id = "Manowar_hold";
	//Locations[n].id.label = "Manowar Hold";
	Locations[n].id.label = "Manowar hold";
	//Info

	Locations[n].filespath.models = "locations\decks\hold";
	Locations[n].image = "deck_hold.tga";
	//Sound
	locations[n].type = "silent_cave_seashore";
	//Models
	//Always
	Locations[n].models.always.locators = "hold_l_JRH_manowar"; 	//...2 after open to cabin above
	Locations[n].models.always.l1 = "hold";
	//Day
	Locations[n].models.day.charactersPatch = "hold_p";
	Locations[n].models.day.fonar = "hold_fd";
	//Night
	Locations[n].models.night.charactersPatch = "hold_p";
	Locations[n].models.night.fonar = "hold_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "at_sea_in_fog";
	locations[n].reload.l1.emerge = "reload5";
	locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.disable = 1;

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "at_sea_in_fog";
	locations[n].reload.l2.emerge = "reload5";
	locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.disable = 1;

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "at_sea_in_fog";
	locations[n].reload.l3.emerge = "reload5";
	locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.disable = 1;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;	//not used
	Locations[n].locators_radius.randitem.randitem2 = 0.001;	//not used

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "barrel_big";	

	Locations[n].locators_radius.randitem.randitem4 = 0.001;	//not used yet
	Locations[n].locators_radius.randitem.randitem5 = 0.001;	//not used yet

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "hatch12R";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "hatch12R";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "hatch12R";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "hatch12R";

	Locations[n].rats = "true";
	Locations[n].island = "Redmond";
	n = n + 1;

//===============================================================================

	//  -------------------------------------------------
	Locations[n].id = "BB_Hornigold_shore";
	Locations[n].filespath.models = "locations\Outside\Shore_6";
	Locations[n].image = "Hornigold_shore.tga";

	//Sound
	locations[n].type = "Blackbeard_shore";

	//Models
	//Always
	Locations[n].models.always.locators = "Shore06_l_JRH";
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
	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "FalaiseDeFleur";
	Locations[n].reload.l2.emerge = "reload_2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 0.001;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "boat2_C";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "boat2_C";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "boat2_B";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

// Rdm _______________________________________________________________________________________________________
	Locations[n].id = "wr_claire";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\MediumHouse\\";
	Locations[n].filespath.textures = "locations\inside\MediumHouse";
	Locations[n].image = "wr_claire.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Claire_house";
	locations[n].fastreload = "Redmond";
	//Models
	//Always
	Locations[n].models.always.locators = "mh_l_JRH";
	Locations[n].models.always.shipyard = "mh";
	Locations[n].models.always.window = "mh_w2";
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
	Locations[n].reload.l1.go = "Redmond_Town_01";
	Locations[n].reload.l1.emerge = "door_9";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Redmond.";

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "door_largeh2";

	Locations[n].locators_radius.randitem.randitem2 = 0.0001;
	Locations[n].items.randitem2 = "carpet2";

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "JRH_tavern_upstairs";		//see also "Redmond_tavern_upstairs" in Redmond (standard alternative: sleep/reincarnation)
	locations[n].id.label = "Room in Redmond tavern";
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
	Locations[n].reload.l1.go = "Redmond_tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Tavern.";
	Locations[n].locators_radius.reload.reload1 = 0.8;

   //JRH -->
	//WR bedroom
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_bedroom";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Woodes Rogers' Bedroom.";
	Locations[n].locators_radius.reload.reload2 = 0.75;

	Locations[n].locators_radius.box.box3 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "doubledoor";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "hatch14";
   //<-- JRH

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].id = "wr_bedroom";
	locations[n].id.label = "Woodes Rogers' bedroom";
	Locations[n].filespath.models = "locations\inside\ResBedRoom";
	Locations[n].filespath.textures = "locations\inside\wr_bedroom";
	Locations[n].image = "wr_bedroom.tga";

	//Town sack
	Locations[n].townsack = "Redmond"; // NK 04-08-29
	Locations[n].island = "Redmond"; // NK 04-08-29

	//Sound
	locations[n].type = "Rogers_private";
	//Models
	//Always
	Locations[n].models.always.locators = "bed_l_JRH";
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
	Locations[n].reload.l1.go = "JRH_tavern_upstairs";
	Locations[n].reload.l1.emerge = "Reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Room in Redmond tavern.";

	//hidden to WR kitchen
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "WR_kitchen";
	Locations[n].reload.l2.emerge = "Reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Woodes Rogers' kitchen.";
	Locations[n].reload.l2.disable = 1;
	
	Locations[n].locators_radius.goto.goto8 = 1.3;
	Locations[n].locators_radius.box.box2 = 0.0001;		//door to kitchen 
	Locations[n].items.randitem1 = "pistol201";

	LAi_LocationFightDisable(&Locations[n], true);
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].id = "WR_kitchen";
	locations[n].id.label = "Woodes Rogers' kitchen";		//exit D2 = on, try on from start
	Locations[n].filespath.models = "locations\inside\flamhouse";
	Locations[n].image = "wr_kitchen.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	//locations[n].type = "house";
	locations[n].type = "Rogers_residence";

	//Models
	//Always
	Locations[n].models.always.locators = "FlamHouse_locators_JRH2";
	Locations[n].models.always.tavern = "Flamhouse";
	//locations[n].models.always.l1 = "lever1_up";
	//locations[n].models.always.l2 = "steplock_v";
	Locations[n].models.always.l1 = "lever_base";

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
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Redmond_Town_01";
	Locations[n].reload.l1.emerge = "door56";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Redmond.";
	Locations[n].locators_radius.reload.reload1 = 0.5;
	Locations[n].reload.l1.disable = 1;			

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_bedroom";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Woodes Rogers' Bedroom.";
	Locations[n].locators_radius.reload.reload2 = 0.5;
	Locations[n].reload.l2.disable = 1;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "wr_food_supply";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Woodes Rogers´food supply.";
	Locations[n].locators_radius.reload.reload3 = 0.5;
	Locations[n].reload.l3.disable = 1;				

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "wr_booty";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Woodes Rogers' booty room";
	Locations[n].locators_radius.reload.reload4 = 0.5;

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "ck_bedroom";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Caroline's bedroom.";
	Locations[n].locators_radius.reload.reload5 = 0.5;
	Locations[n].reload.l5.disable = 1;

	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "wr_crew";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "";
	Locations[n].locators_radius.reload.reload6 = 0.5;
	Locations[n].reload.l6.disable = 1;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "door_N03";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "door_N03";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "door_N03";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "lever_down";

	Locations[n].locators_radius.randitem.randitem5 = 0.1;
	Locations[n].items.randitem5 = "lever_up";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "gatedoor_vsmall_GN3";

	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "gatedoor_vsmall_GN3R";

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

	//  -------------------------------------------------

	Locations[n].id = "ck_bedroom";
//	locations[n].id.label = "Caroline K's bedroom";		//open = on
	Locations[n].filespath.models = "locations\inside\Tavern_room";
	Locations[n].image = "ck_bedroom.tga";

	//Town sack
	Locations[n].townsack = "Redmond"; // NK 04-08-29
	Locations[n].island = "Redmond"; // NK 04-08-29

	//Sound
	locations[n].type = "Rogers_private";
	//Models
	//Always
	Locations[n].models.always.locators = "tavern_room_locators_JRH";
	Locations[n].models.always.l1 = "Tavern_room";
	Locations[n].models.always.window = "Tavern_room_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Tavern_room_patch";

	//Night
	Locations[n].models.night.charactersPatch = "Tavern_room_patch";	

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redmh_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_kitchen";
	Locations[n].reload.l1.emerge = "Reload5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Woodes Rogers' kitchen.";

	Locations[n].locators_radius.goto.goto3 = 2.0;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "bed";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "armchair02";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "armchair02";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "steplock";

	Locations[n].items.randitem5 = "key8";
	LAi_LocationFightDisable(&Locations[n], true);
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].id = "wr_food_supply";
//	locations[n].id.label = "Woodes Rogers' food cellar";		//open = on
	Locations[n].filespath.models = "locations\inside\store03";
	Locations[n].image = "wr_food_supply.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_cellar";

	//Models
	//Models
	//Always
	Locations[n].models.always.locators = "store03_locators_JRH";
	Locations[n].models.always.tavern = "store03";
	Locations[n].models.always.window = "store03_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "store03_patch";

	//Night
	Locations[n].models.night.charactersPatch = "store03_patch";

	//Environment
	Locations[n].environment.weather = "false";		//ev fog, white stones gets a little too bright though
	Locations[n].environment.sea = "false";			//don't flood, cellar connects to dry part of mine	
	Locations[n].models.back = "back\redb_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_kitchen";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Woodes Rogers' kitchen.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_mine";
	Locations[n].reload.l2.emerge = "goto13";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Woodes Rogers' tunnel.";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "wr_wine_cellar";
	Locations[n].reload.l5.emerge = "goto2";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "";
	Locations[n].reload.l5.disable = 1;

	Locations[n].locators_radius.goto.goto1 = 0.8;
	Locations[n].locators_radius.goto.goto3 = 1.0;
	Locations[n].locators_radius.goto.bible = 2.0;

	Locations[n].locators_radius.box.box10 = 0.5;
	Locations[n].locators_radius.box.box11 = 0.5;
	Locations[n].locators_radius.box.box12 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "door_N06";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "gatedoor_white_stone";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "gatedoor_white_stone";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "gatedoor_store4_wall";

	Locations[n].locators_radius.randitem.randitem5 = 0.1;
	Locations[n].items.randitem5 = "gatedoor_store4_wall";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "foodchest";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "mdchest2";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "pistolmdcloth";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "pistolmdsack";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].id = "wr_crew";
//	locations[n].id.label = "Crew's quarter";		
	Locations[n].filespath.models = "locations\inside\tavern03";
	Locations[n].image = "wr_crew.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_crew";

	//Models
	//Always
	Locations[n].models.always.locators = "tavern03_locators_JRH2";//start with lever up (open) but counter closed.
	Locations[n].models.always.tavern = "tavern03";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "tavern03_patch";

	//Night
	Locations[n].models.night.charactersPatch = "tavern03_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redmh4_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_kitchen";
	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "Redmond_Town_04";
	Locations[n].reload.l5.emerge = "Door_4";
	Locations[n].reload.l5.autoreload = "0"
	Locations[n].locators_radius.reload.reload5 = 0.3;

	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "wr_crew";
	Locations[n].reload.l7.emerge = "reload5";
	Locations[n].reload.l7.autoreload = "0"
	Locations[n].locators_radius.reload.reload7 = 0.3;

	Locations[n].locators_radius.box.box1 = 0.8;
	Locations[n].locators_radius.box.box2 = 0.8;
	Locations[n].locators_radius.box.box3 = 0.8;
	Locations[n].locators_radius.box.box4 = 0.8;
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.box.box6 = 0.5;
	Locations[n].locators_radius.box.box7 = 0.5;
	Locations[n].locators_radius.box.box8 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "gatedoor_pgreen";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "gatedoor_pgreen";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "lever_up";
	
	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "lever_down";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "door_N10";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "chest3";
	
	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "hatch7";

	Locations[n].locators_radius.randitem.randitem8 = 0.1;
	Locations[n].items.randitem8 = "door_sklad";			

	Locations[n].locators_radius.randitem.randitem9 = 0.1;	
	Locations[n].items.randitem9 = "gatedoor_pgreen";

	Locations[n].locators_radius.randitem.randitem10 = 0.1;
	Locations[n].items.randitem10 = "gatedoor_pgreen";

	Locations[n].locators_radius.randitem.randitem11 = 0.1;
	Locations[n].items.randitem11 = "lever_base";				

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].id = "Tavern_storeroom";
	locations[n].id.label = "Tavern storeroom";		
	Locations[n].filespath.models = "locations\inside\store04";
	Locations[n].image = "tavern_storeroom.tga";
	//Locations[n].image = "";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_neutral";

	//Models
	//Always
	Locations[n].models.always.locators = "store04_locators_JRH";
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
	//town
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Redmond_town_01";
	Locations[n].reload.l1.emerge = "Door_7";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Redmond.";
	Locations[n].locators_radius.reload.reload1 = 0.5;
	Locations[n].reload.l1.disable = 1;

	//tavern
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Redmond_tavern";
	Locations[n].reload.l2.emerge = "reload6";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Redmond tavern.";
	Locations[n].locators_radius.reload.reload2 = 0.7;

	//library
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "wr_library";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Woodes Rogers´ library.";

	//Charles Windem room
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Charles_Windem_room";
	Locations[n].reload.l4.emerge = "reload3";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Private.";
	Locations[n].reload.l4.disable = 1;

	Locations[n].locators_radius.reload.reload7 = 0.5;
	Locations[n].locators_radius.goto.goto2 = 2.0;
	Locations[n].locators_radius.box.box1 = 0.0001;			//use door key
	Locations[n].locators_radius.box.box2 = 0.5;			//behind counter
	Locations[n].locators_radius.box.box3 = 0.5;			//behind counter

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

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "Charles_Windem_room";
	locations[n].id.label = "Charles Windem's room";		//open = on
	Locations[n].image = "Charles_Windem_room.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_neutral";

	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Smallhome";
	Locations[n].filespath.textures = "locations\inside\Smallhome\store";

	Locations[n].models.always.city = "sh";
	Locations[n].models.always.locators = "sh_l_JRH";
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
	Locations[n].models.back = "back\redsh_";

	//Reload map
	//floor hatch
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Tavern_storeroom";
	Locations[n].reload.l1.emerge = "goto1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	Locations[n].locators_radius.reload.reload1 = 0.2;

	//attic
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "storeroom_attic";
	Locations[n].reload.l2.emerge = "goto2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Storeroom attic";
	Locations[n].locators_radius.reload.reload2 = 0.7;
	Locations[n].reload.l2.disable = 1;			

	//stairs tavern storeroom
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Tavern_storeroom";
	Locations[n].reload.l3.emerge = "reload4";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Tavern storeroom.";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "door_A01";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "door_N";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "door_N";

	Locations[n].locators_radius.goto.goto4 = 1.0;
	Locations[n].locators_radius.goto.goto5 = 1.0;
	Locations[n].locators_radius.box.box1 = 0.01;

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].id = "wr_library";
	locations[n].id.label = "Woodes Rogers' library";		
	Locations[n].image = "wr_library.tga";
	Locations[n].filespath.models = "locations\inside\Residence2\\";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_residence";

	//Models
	//Always
	Locations[n].models.always.city = "Res02";
	Locations[n].models.always.l1 = "lever_base";
	Locations[n].models.always.locators = "Res02_l_JRH";
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
	Locations[n].models.back = "back\redrsb_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Tavern_storeroom";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Tavern storeroom.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_residence";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Woodes Rogers´residence.";
	Locations[n].locators_radius.reload.reload2 = 0.1;//0.5 later on

	//attic
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "storeroom_attic";
	Locations[n].reload.l3.emerge = "goto3";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Storeroom attic.";
	Locations[n].reload.l3.disable = 1;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "ck_drawing_room";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Caroline's drawing room.";
	Locations[n].reload.l4.disable = 1;

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "wr_study";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Woodes Rogers' study.";
	Locations[n].locators_radius.reload.reload5 = 0.5;
	Locations[n].reload.l5.disable = 1;

	//Locations[n].reload.l6.name = "reload6";			//on when door is opened from here to LS
	//Locations[n].reload.l6.go = "Redmond_UsurerHouse";
	//Locations[n].reload.l6.emerge = "reload5";
	//Locations[n].reload.l6.autoreload = "0";
	//Locations[n].reload.l6.label = "Loanshark's Office.";
	Locations[n].locators_radius.reload.reload6 = 0.5;

    //temp case when locked

	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "wr_study";			//to avoid showing LS when locked, (was storeroom attic)
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.disable = 1;

	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "wr_gunroom";		
	Locations[n].reload.l7.emerge = "reload2";		
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].locators_radius.reload.reload7 = 0.5;
	Locations[n].reload.l7.disable = 1;

	Locations[n].locators_radius.reload.reload8 = 0.2;

	Locations[n].locators_radius.reload.reload9 = 0.0001;		//not used anymore
	Locations[n].locators_radius.reload.reload10 = 0.0001;		//not used anymore

	Locations[n].locators_radius.goto.goto9 = 1.0;
	Locations[n].locators_radius.goto.goto13 = 0.8;
	Locations[n].locators_radius.goto.goto20 = 0.8;
	Locations[n].locators_radius.goto.goto27 = 1.0;
	Locations[n].locators_radius.goto.goto29 = 1.0;
	Locations[n].locators_radius.goto.arrive_look = 0.2;

	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.box.box6 = 0.8;
	Locations[n].locators_radius.box.box7 = 0.5;
	Locations[n].locators_radius.box.box8 = 0.5;
	Locations[n].locators_radius.box.box9 = 0.5;
	Locations[n].locators_radius.box.box10 = 0.5;
	Locations[n].locators_radius.box.box11 = 0.0001;
	Locations[n].locators_radius.box.box12 = 0.5;
	Locations[n].locators_radius.box.box13 = 0.5;
	Locations[n].locators_radius.box.box14 = 0.5;
	Locations[n].locators_radius.box.box15 = 0.5;			//start locked padlock, later walk (to erotica)
	
	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "door_N02";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "door_N02";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "door_N05";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "door_N05";

	Locations[n].locators_radius.randitem.randitem5 = 0.1;
	Locations[n].items.randitem5 = "door_N05R";

	Locations[n].locators_radius.randitem.randitem6 = 0.1;
	Locations[n].items.randitem6 = "door_N05R";

	Locations[n].locators_radius.randitem.randitem7 = 0.1;
	Locations[n].items.randitem7 = "door_N05";

	Locations[n].locators_radius.randitem.randitem8 = 0.1;
	Locations[n].items.randitem8 = "door_N05";

	Locations[n].locators_radius.randitem.randitem9 = 0.01;
	Locations[n].items.randitem9 = "bookshelf4";

	Locations[n].locators_radius.randitem.randitem10 = 0.1;
	Locations[n].items.randitem10 = "bed2";

	Locations[n].locators_radius.randitem.randitem11 = 0.1;
	Locations[n].items.randitem11 = "door_A02";

	Locations[n].locators_radius.randitem.randitem12 = 0.1;
	Locations[n].items.randitem12 = "door_A02R";

	Locations[n].locators_radius.randitem.randitem13 = 0.1;
	Locations[n].items.randitem13 = "mine";

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
	Locations[n].items.randitem14 = "steplock";

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	Locations[n].items.randitem15 = "steplock";

	Locations[n].locators_radius.randitem.randitem16 = 0.001;
	Locations[n].items.randitem16 = "steplock";

	Locations[n].locators_radius.randitem.randitem17 = 0.001;
	Locations[n].items.randitem17 = "steplock";

	Locations[n].locators_radius.randitem.randitem18 = 0.001;
	Locations[n].items.randitem18 = "steplock";

	Locations[n].locators_radius.randitem.randitem19 = 0.01;
	Locations[n].items.randitem19 = "bookshelf2";

	Locations[n].locators_radius.randitem.randitem20 = 0.01;
	Locations[n].items.randitem20 = "bookshelf2";

	Locations[n].locators_radius.randitem.randitem21 = 0.01;
	Locations[n].items.randitem21 = "door_M12";

	Locations[n].locators_radius.randitem.randitem22 = 0.01;
	Locations[n].items.randitem22 = "door_M12";

	Locations[n].locators_radius.randitem.randitem23 = 0.01;
	Locations[n].items.randitem23 = "bookshelf2";

	Locations[n].locators_radius.randitem.randitem24 = 0.01;
	Locations[n].items.randitem24 = "bookshelf4";

	Locations[n].locators_radius.randitem.randitem25 = 0.01;
	Locations[n].items.randitem25 = "bookshelf4";

	Locations[n].locators_radius.randitem.randitem26 = 0.01;
	Locations[n].items.randitem26 = "mine";

	Locations[n].locators_radius.randitem.randitem27 = 0.01;
	Locations[n].items.randitem27 = "box";

	Locations[n].locators_radius.randitem.randitem28 = 0.01;
	Locations[n].items.randitem28 = "box";

	Locations[n].locators_radius.randitem.randitem29 = 0.01;
	Locations[n].items.randitem29 = "lever_up";

	Locations[n].locators_radius.randitem.randitem30 = 0.01;
	Locations[n].items.randitem30 = "lever_down";

	Locations[n].locators_radius.randitem.randitem31 = 0.01;
	Locations[n].items.randitem31 = "bookshelf2";		

	Locations[n].locators_radius.randitem.randitem32 = 0.01;
	Locations[n].items.randitem32 = "bookshelf2";		

	Locations[n].locators_radius.randitem.randitem33 = 0.01;
	Locations[n].items.randitem33 = "bookshelf2";

	Locations[n].locators_radius.randitem.randitem34 = 0.01;
	Locations[n].items.randitem34 = "bookshelf2";

	Locations[n].locators_radius.randitem.randitem35 = 0.01;
	Locations[n].items.randitem35 = "bookshelf2";

	Locations[n].locators_radius.randitem.randitem36 = 0.01;
	Locations[n].items.randitem36 = "bookshelf2";

	Locations[n].locators_radius.randitem.randitem37 = 0.01;
	Locations[n].items.randitem37 = "bookshelf2";

	Locations[n].locators_radius.randitem.randitem38 = 0.01;
	Locations[n].items.randitem38 = "door_N05";

	Locations[n].locators_radius.randitem.randitem39 = 0.01;
	Locations[n].items.randitem39 = "door_N05L";

	Locations[n].locators_radius.randitem.randitem40 = 0.01;
	Locations[n].items.randitem40 = "door_N05L";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond";
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Residence3_red";

	Locations[n].id = "ck_drawing_room";
//	locations[n].id.label = "Caroline K's drawing room";			//open = on
	Locations[n].image = "ck_drawing_room.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_residence";		//was _private

	//Models
	//Always
	Locations[n].models.always.locators = "Res03_l_JRH";
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
	Locations[n].models.back = "back\redrsb_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_library";
	Locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Woodes Rogers' library.";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Redmond_Town_04";
	Locations[n].reload.l2.emerge = "reload2";		
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Redmond.";
	Locations[n].reload.l2.disable = 1;
	Locations[n].locators_radius.reload.reload2 = 0.6;

	Locations[n].locators_radius.goto.goto8 = 0.7;
	Locations[n].locators_radius.box.box1 = 0.1;
	Locations[n].locators_radius.box.box2 = 0.1;

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	// --------------------------------------------------

	Locations[n].id = "wr_study";
//	locations[n].id.label = "Woodes Rogers' study";		//open = on
	Locations[n].image = "wr_study.tga";
	Locations[n].filespath.models = "locations\inside\shipyard5\\";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	//locations[n].type = "house";
	locations[n].type = "Rogers_study";

	//Models
	//Always
	Locations[n].models.always.city = "sh05";

	Locations[n].models.always.l5 = "bars_down";
	Locations[n].models.always.l6 = "girder_block";

	Locations[n].models.always.locators = "sh05_locators_JRH";	//start = JRH
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
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_library";
	Locations[n].reload.l1.emerge = "reload5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Woodes Rogers' library.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_secret";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Woodes Rogers' secret room.";
	Locations[n].locators_radius.reload.reload2 = 0.0001;		//0.5 later
	Locations[n].reload.l2.disable = 1;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "wr_study";
	Locations[n].reload.l3.emerge = "goto6";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Woodes Rogers' study.";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].locators_radius.goto.goto9 = 1.0;
	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.box.box6 = 0.5;
	Locations[n].locators_radius.box.box7 = 0.5;
	Locations[n].locators_radius.box.box8 = 0.0001;		
	Locations[n].locators_radius.box.box9 = 0.0001;		
	Locations[n].locators_radius.box.box10 = 0.0001;	
	Locations[n].locators_radius.box.box11 = 0.0001;
	Locations[n].locators_radius.box.box12 = 0.0001;		
	Locations[n].locators_radius.box.box13 = 0.0001;		
	Locations[n].locators_radius.box.box14 = 0.0001;	
	Locations[n].locators_radius.box.box15 = 0.0001;
	Locations[n].locators_radius.box.box16 = 0.0001;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "gatedoor_pgreen";

	Locations[n].locators_radius.randitem.randitem2 = 1.2;
	Locations[n].items.randitem2 = "bladewood";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "steplock_v";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "steplock_v";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "steplock_v";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "steplock_v";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond";
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].id = "wr_secret";
//	locations[n].id.label = "Woodes Rogers' secret room";		//open = on
	Locations[n].filespath.models = "locations\inside\MediumStore_inner";
	Locations[n].image = "wr_secret.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_study";

	//Models
	//Always
	Locations[n].models.always.locators = "MS_l_JRH_sec";
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
	Locations[n].reload.l1.go = "wr_study";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Woodes Rogers' study.";

	Locations[n].locators_radius.box.box1 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "gatedoor_p";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "gatedoor_p";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "chest4_coas";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "ale";

	Locations[n].locators_radius.camdetector.camera1 = 5;

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

 	//  -------------------------------------------------

	Locations[n].id = "wr_residence";
	locations[n].id.label = "Woodes Rogers' residence";
	Locations[n].filespath.models = "locations\inside\Residence1";
	Locations[n].image = "wr_residence.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_residence";

	//Models
	//Always
	Locations[n].models.always.locators = "res01_l_JRH";
	Locations[n].models.always.jungle = "res01";
	Locations[n].models.always.window = "res01_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "res01_p";

	//Night
	Locations[n].models.night.charactersPatch = "res01_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redms_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Redmond_Town_04";
	Locations[n].reload.l1.emerge = "terr_out1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Redmond.";
	Locations[n].reload.l1.disable = 1;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_library";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Woodes Rogers' library.";
	Locations[n].locators_radius.reload.reload2 = 0.8;		

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Redmond_Town_01";
	Locations[n].reload.l3.emerge = "reload5";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Redmond. Centrum.";
	Locations[n].locators_radius.reload.reload3 = 0.7;
	Locations[n].reload.l3.disable = 1;

	Locations[n].locators_radius.reload.reload5 = 0.1;	//not used

	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "wr_residence";
	Locations[n].reload.l6.emerge = "goto8";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "";
	Locations[n].locators_radius.reload.reload6 = 0.5;

	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "wr_armory";
	Locations[n].reload.l7.emerge = "reload2";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Armory";
	Locations[n].locators_radius.reload.reload7 = 0.5;
	Locations[n].reload.l7.disable = 1;

	Locations[n].locators_radius.goto.goto1 = 1.0;
	Locations[n].locators_radius.goto.goto4 = 1.5;
	Locations[n].locators_radius.box.box1 = 0.01;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "door_N04";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "door_N04";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "door_N04R";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "door_N04R";

	Locations[n].locators_radius.goto.goto6 = 0.7;
	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;

	Locations[n].locators_radius.box.box4 = 0.0001;		//walk to clock

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond";
	n = n + 1;
	
	//  -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\LargeStore";
	Locations[n].image = "wr_armory.tga";

	Locations[n].id = "wr_armory";
	locations[n].id.label = "Woodes Rogers' armory";		//open = on, try on from start

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_cellar";

	//Models
	//Always
	Locations[n].models.always.locators = "LS_l_JRH0";
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
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_gunpowder";
	Locations[n].reload.l1.emerge = "Reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 0.5;
	Locations[n].reload.l1.disable = 1;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_residence";
	Locations[n].reload.l2.emerge = "Reload7";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "chest1";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "sack";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "steplock";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "barrel_big";

	Locations[n].locators_radius.randitem.randitem5 = 0.1;
	Locations[n].items.randitem5 = "cannonball_box";

	Locations[n].locators_radius.randitem.randitem6 = 0.1;
	Locations[n].items.randitem6 = "key8";			//invisible

	Locations[n].locators_radius.randitem.randitem7 = 0.1;
	Locations[n].items.randitem7 = "barrel_big";

	Locations[n].locators_radius.randitem.randitem8 = 0.1;
	Locations[n].items.randitem8 = "roll_of_rolls";

	Locations[n].locators_radius.randitem.randitem9 = 0.1;
	Locations[n].items.randitem9 = "basket";

	Locations[n].locators_radius.randitem.randitem10 = 0.1;
	Locations[n].items.randitem10 = "barrel_big";

	Locations[n].locators_radius.randitem.randitem11 = 0.1;
	Locations[n].items.randitem11 = "barrel2_roll";

	Locations[n].locators_radius.randitem.randitem12 = 0.1;//small from start so it can't be taken from stairs
	Locations[n].items.randitem12 = "cannonball_box2";

	Locations[n].locators_radius.randitem.randitem13 = 1.5;
	Locations[n].items.randitem13 = "blade4";

	Locations[n].locators_radius.randitem.randitem14 = 0.1;
	Locations[n].items.randitem14 = "box";

	Locations[n].locators_radius.randitem.randitem15 = 0.1;
	Locations[n].items.randitem15 = "cannonball2";

	Locations[n].locators_radius.box.box4 = 0.1;	//the closed one, NOT used any longer
	Locations[n].locators_radius.goto.goto1 = 0.7;
	Locations[n].locators_radius.goto.goto12 = 2.0;
	Locations[n].locators_radius.goto.goto14 = 0.7;
	Locations[n].locators_radius.goto.goto18 = 2.8;	//was 2.5
	Locations[n].locators_radius.officers.reload2_3 = 0.7;

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond";
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].id = "wr_gunpowder";
	locations[n].id.label = "Gunpowder storage";
	Locations[n].filespath.models = "locations\inside\MediumStore_Gps";
	Locations[n].image = "wr_gunpowder.tga";

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
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_armory";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Armory";

	Locations[n].reload.l3.name = "reload3_D";
	Locations[n].reload.l3.go = "wr_gunroom";
	Locations[n].reload.l3.emerge = "reload6";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].locators_radius.reload.reload3_D = 0.5;
	Locations[n].reload.l3.disable = 1;

	Locations[n].locators_radius.reload.reload3_A = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "gatedoor_stone";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "gatedoor_stone";

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

	Locations[n].locators_radius.goto.goto9 = 1.2;
	Locations[n].locators_radius.box.box2 = 0.7;

	Locations[n].locators_radius.camdetector.camera1 = 5;
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Tavern02";

	Locations[n].id = "wr_gunroom";
//	locations[n].id.label = "Gunroom";	//open from gps = on
	Locations[n].image = "wr_gunroom.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_gunroom";

	//Models
	//Always
	Locations[n].models.always.locators = "tavern02_locators_JRH0";//start = ..._JRH0
	Locations[n].models.always.house = "tavern02";
	Locations[n].models.always.l1 = "";			//wood, wood_lit, sack2, sack2_lit all later on
	//Locations[n].models.always.env = "smalltavern_env";
	Locations[n].models.always.window = "tavern02_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "tavern02_patch";

	//Night
	Locations[n].models.night.charactersPatch = "tavern02_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Locations[n].models.back = "back\smumh2_";		//needed?

	//Reload map
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_library";
	Locations[n].reload.l2.emerge = "reload7";		
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "wr_gunpowder";
	Locations[n].reload.l3.emerge = "goto5";		
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].locators_radius.reload.reload3 = 0.1;	//not to be seen
	Locations[n].reload.l3.disable = 1;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "door_N08";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "textile2";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "door_N08";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "door_N08";

	Locations[n].locators_radius.randitem.randitem5 = 0.1;
	Locations[n].items.randitem5 = "door_N08";

	Locations[n].locators_radius.randitem.randitem6 = 0.1;
	Locations[n].items.randitem6 = "door_N08";

	Locations[n].locators_radius.randitem.randitem7 = 0.1;
	Locations[n].items.randitem7 = "distillery";

	Locations[n].locators_radius.randitem.randitem8 = 0.1;
	Locations[n].items.randitem8 = "distillery_tank";

	Locations[n].locators_radius.randitem.randitem9 = 0.1;
	Locations[n].items.randitem9 = "cannon_pipe";

	Locations[n].locators_radius.randitem.randitem10 = 0.1;
	Locations[n].items.randitem10 = "damper_half";

	Locations[n].locators_radius.randitem.randitem11 = 0.1;
	Locations[n].items.randitem11 = "damper_closed";

	Locations[n].locators_radius.randitem.randitem12 = 0.1;
	Locations[n].items.randitem12 = "distillery_lid";

	Locations[n].locators_radius.randitem.randitem13 = 0.1;
	Locations[n].items.randitem13 = "cannon_pipe";

	Locations[n].locators_radius.randitem.randitem14 = 0.1;
	Locations[n].items.randitem14 = "damper_open";

	Locations[n].locators_radius.randitem.randitem15 = 0.1;
	Locations[n].items.randitem15 = "bladebarrel";

	Locations[n].locators_radius.reload.reload1 = 0.5;
	Locations[n].locators_radius.reload.reload6 = 0.5;
	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.waitress.stay1 = 2.0;

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].id = "Loanshark_cellar";
//	locations[n].id.label = "Loanshark cellar";		//open from tunnel = on
	Locations[n].filespath.models = "locations\inside\mh9_cellar";
	Locations[n].image = "loanshark_cellar.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_neutral";

	//Models
	//Always
	Locations[n].models.always.city = "mh9";
	Locations[n].models.always.locators = "mh9_l_JRH";
	Locations[n].models.always.window = "mh9_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "mh9_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh9_p";

	//Environment
	Locations[n].environment.weather = "false";	//fog looks good here!
	Locations[n].environment.sea = "false";		//possible to flood but waterlevel too high
	//Locations[n].models.back = "back\redmh9_";	//try without any

	//Reload map
	//tunnel
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_mine";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Woodes Rogers' tunnel.";
	Locations[n].reload.l1.disable = 1;			

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Redmond_UsurerHouse";
	Locations[n].reload.l2.emerge = "reload4";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	
	Locations[n].id = "wr_booty";
	locations[n].id.label = "Woodes Rogers' booty room";
	Locations[n].image = "wr_booty.tga";
	
	Locations[n].filespath.models = "locations\Inside\Pirate_House";
	//Sound
	locations[n].type = "Rogers_private";
	//Models
	//Always
	Locations[n].models.always.locators = "pirh_l_JRH";
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
	Locations[n].models.back = "back\redmh10_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_kitchen";
	Locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Woodes Rogers' kitchen";

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "wr_friday";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Friday's room.";
	
	Locations[n].locators_radius.goto.reload2 = 0.5;
	Locations[n].locators_radius.goto.reload3 = 0.5;
	Locations[n].locators_radius.reload.reload4 = 0.5;
	Locations[n].locators_radius.goto.goto11 = 0.7;
	Locations[n].locators_radius.goto.goto15 = 1.2;
	Locations[n].locators_radius.box.box3 = 0.7;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "door_N07";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "gatefloor_w";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "door_N07";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "door_N07";

	Locations[n].locators_radius.randitem.randitem5 = 0.1;
	Locations[n].items.randitem5 = "distillery";

	Locations[n].locators_radius.randitem.randitem6 = 1.2;
	Locations[n].items.randitem6 = "pistol202";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\MediumHouse2";

	Locations[n].id = "wr_friday";
//	locations[n].id.label = "Friday's room";
	locations[n].id.label = "Fried Egg's room";
	Locations[n].image = "wr_friday.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_private";

	//Models
	//Always
	Locations[n].models.always.locators = "MH02_l_JRH";
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
	Locations[n].models.back = "back\redmh10_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_booty";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Woodes Rogers' booty room";

	Locations[n].reload.l2.name = "window";
	Locations[n].reload.l2.go = "Redmond_Town_01";
	Locations[n].reload.l2.emerge = "cat_burglar1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Redmond";
	Locations[n].locators_radius.reload.window = 0.6;
	Locations[n].reload.l2.disable = 1;

	Locations[n].locators_radius.goto.dialog = 0.8;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "door_N07";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "gatedoor_small_stone";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "gatedoor_small_stone";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "FransHals";
	
	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "chair";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "Shop_stairs";
//	locations[n].id.label = "Rogers' Paintings Furniture & Weapons";	//yes something to wonder about
	Locations[n].filespath.models = "locations\inside\store04_stone";
	Locations[n].image = "Shop_stairs.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_shop";

	//Models
	//Always
	Locations[n].models.always.locators = "store04_locators_JRH2";
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
	
	//wr shop
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "wr_shop";
	Locations[n].reload.l4.emerge = "reload3";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Rogers' Paintings Furniture & Weapons";

	//Redmond
	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "Redmond_town_01";
	Locations[n].reload.l7.emerge = "door58";
	Locations[n].reload.l7.autoreload = "1";
	Locations[n].reload.l7.label = "Redmond.";

	//Dave Edna
	Locations[n].reload.l8.name = "reload8";
	Locations[n].reload.l8.go = "Dave_Edna_room";
	Locations[n].reload.l8.emerge = "reload1";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "";
	Locations[n].locators_radius.reload.reload8 = 0.5;

	Locations[n].locators_radius.reload.reload6 = 0.5;
	Locations[n].locators_radius.goto.goto1 = 0.6;

	Locations[n].locators_radius.randitem.randitem11 = 0.01;
	Locations[n].items.randitem11 = "gatedoor_stone";

	Locations[n].locators_radius.randitem.randitem12 = 0.01;
	Locations[n].items.randitem12 = "armchair02";

	Locations[n].locators_radius.randitem.randitem13 = 0.01;
	Locations[n].items.randitem13 = "gatedoor_stone";

	Locations[n].locators_radius.randitem.randitem14 = 0.01;
	Locations[n].items.randitem14 = "gatedoor_stone";

	Locations[n].locators_radius.randitem.randitem15 = 0.01;
	Locations[n].items.randitem15 = "door_A03";

	Locations[n].locators_radius.randitem.randitem16 = 0.01;
	Locations[n].items.randitem16 = "door_N01";	

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "Dave_Edna_room";
	locations[n].id.label = "Dave Edna's Room";		
	Locations[n].image = "Dave_Edna_room.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_private";

	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Smallhome";
	Locations[n].filespath.textures = "locations\inside\Smallhome\stone";

	Locations[n].models.always.city = "sh";
	Locations[n].models.always.locators = "sh_l_JRH1";
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
	Locations[n].models.back = "back\redsh_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Shop_stairs";
	Locations[n].reload.l1.emerge = "reload8";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Dave_Edna_room";
	Locations[n].reload.l2.emerge = "goto5";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";

	Locations[n].locators_radius.randitem.randitem1 = 0.0001;
	Locations[n].items.randitem1 = "clock_big";

	Locations[n].locators_radius.randitem.randitem2 = 0.0001;
	Locations[n].items.randitem2 = "clock_big";

	Locations[n].locators_radius.randitem.randitem3 = 0.0001;
	Locations[n].items.randitem3 = "fur1";			

	Locations[n].locators_radius.box.box1 = 0.3;
	Locations[n].locators_radius.box.box3 = 0.0001;				//unlock door

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\StoreHouse_Rogers";	//was residence05_flaman

	Locations[n].id = "wr_shop";
	locations[n].id.label = "Rogers' Paintings Furniture & Weapons";	//open = on, try visible from start
	Locations[n].image = "wr_shop.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_shop";

	//Models
	//Always
	Locations[n].models.always.locators = "residence05_locators_JRH_Lup_P3";
	Locations[n].models.always.house = "residence05";
	Locations[n].models.always.l1 = "lever_base";
	Locations[n].models.always.window = "residence05_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "residence05_patch";

	//Night
	Locations[n].models.night.charactersPatch = "residence05_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redb_";

	//Reload map
	
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_shop_office";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].reload.l2.disable = 1;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Shop_stairs";
	Locations[n].reload.l3.emerge = "reload4";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Shop stairs";
	Locations[n].reload.l3.disable = 1;

	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "Redmond_UsurerHouse";
	Locations[n].reload.l6.emerge = "locator1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Loanshark's Office.";
	Locations[n].locators_radius.reload.reload6 = 0.5;

	Locations[n].locators_radius.reload.reload7 = 0.5;
	Locations[n].locators_radius.reload.reload8 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "globe";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "gatedoor_stone";
	
	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "lever_up";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "lever_down";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "clock_big2";

	Locations[n].items.randitem6 = "pistol203";

	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "mdchest";

	Locations[n].locators_radius.randitem.randitem8 = 1.0;
	Locations[n].items.randitem8 = "surgery_kit";

	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;		
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.box.box6 = 0.0001;		//not used
	Locations[n].locators_radius.box.box7 = 0.5;
	Locations[n].locators_radius.box.box8 = 0.5;
	Locations[n].locators_radius.box.box9 = 0.5;
	Locations[n].locators_radius.box.box10 = 0.5;
	Locations[n].locators_radius.box.box11 = 0.5;
	Locations[n].locators_radius.box.box12 = 0.5;

	Locations[n].locators_radius.goto.goto13 = 1.0;

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\shipyard3";

	Locations[n].id = "wr_shop_office";
//	locations[n].id.label = "Shop office";
	Locations[n].image = "wr_shop_office.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_shop";
	
	//Models
	//Always
	Locations[n].models.always.locators = "sh03_l_JRH";
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
	Locations[n].reload.l1.go = "wr_shop";
	Locations[n].reload.l1.emerge = "Reload2";
	Locations[n].reload.l1.label = "";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 0.5;
	Locations[n].reload.l1.disable = 1;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_mother_stairs";
	Locations[n].reload.l2.emerge = "goto4";
	Locations[n].reload.l2.label = "";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "Redmond_Town_01";
	Locations[n].reload.l6.emerge = "roof_start";
	Locations[n].reload.l6.label = "";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].locators_radius.reload.reload6 = 0.5;
	Locations[n].reload.l6.disable = 1;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "gatedoor_vsmall_GSH";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "door_N09";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "door_N06";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "gatedoor_stone";		

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "gatedoor_vsmall_GSHR";

	Locations[n].locators_radius.box.box1 = 0.1;

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "wr_mother_stairs";
//	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house\\";
	Locations[n].image = "wr_mother_stairs.tga";

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
	Locations[n].reload.l2.go = "wr_mother";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "wr_mother_stairs";
	Locations[n].reload.l3.emerge = "reload4";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "wr_shop_office";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.3;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_N09";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "gatedoor_w";

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "wr_mother";
	locations[n].id.label = "Grandmother Rogers' room";		
	Locations[n].image = "wr_mother.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_private";

	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\brothel_room_wr";
	//Locations[n].models.always.locators = "brothel_room_locators";
	Locations[n].models.always.locators = "brothel_room_locators_JRH3_p";//starts with pistol, changed later on to ...JRH3 (invisible pistol if shortcut 7) is used
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
	Locations[n].reload.l1.go = "wr_mother_stairs";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	Locations[n].reload.l1.disable = 1;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_mother";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "wr_mother";
	Locations[n].reload.l3.emerge = "goto1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "textileB";

	Locations[n].locators_radius.randitem.randitem2 = 0.0001;
	Locations[n].items.randitem2 = "clock_big";

	Locations[n].locators_radius.randitem.randitem3 = 0.0001;
	Locations[n].items.randitem3 = "clock_big";

	Locations[n].locators_radius.randitem.randitem4 = 2.0;
	Locations[n].items.randitem4 = "pistol204";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "steplock";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "bladebarrel";

	Locations[n].locators_radius.box.box1 = 0.3;

	Locations[n].locators_radius.goto.goto1 = 0.8;

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Mine";

	Locations[n].id = "wr_mine";
	//locations[n].id.label = "Port Royal old mine";	//label not to be seen from LS cellar, switched on later
	Locations[n].image = "wr_mine.tga";

	//Sound
	locations[n].type = "Rogers_mine";
	//Models
	//Always
	Locations[n].models.always.locators = "mine_l_JRH0";//start JRH0 = all lights off in mine
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
	Locations[n].reload.l1.go = "wr_food_supply";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Woodes Rogers' food supply.";
	Locations[n].locators_radius.reload.reload1_back = 0.5;

	Locations[n].reload.l2.name = "reload2";
	//Locations[n].reload.l2.go = "Loanshark_cellar";
	//Locations[n].reload.l2.emerge = "reload1";
	//Locations[n].reload.l2.label = "Loanshark cellar.";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].reload.l2.disable = 1;
	Locations[n].locators_radius.reload.reload2 = 1.0;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "wr_prison_guard";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Guard room.";

	//tunnel 3
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "wr_dungeon4_main";
	Locations[n].reload.l4.emerge = "goto1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Port Royal old mine.";
	Locations[n].reload.l4.disable = 1;

	//tunnel 2
	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "wr_dungeon3_left";
	Locations[n].reload.l5.emerge = "goto6";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Port Royal old mine.";
	Locations[n].reload.l5.disable = 1;

	//tunnel 1
	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "wr_dungeon3_right";
	Locations[n].reload.l6.emerge = "goto1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Port Royal old mine.";
	Locations[n].reload.l6.disable = 1;

	//gas lights control room
	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "wr_mine_control";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "";
	Locations[n].reload.l7.disable = 1;

	Locations[n].locators_radius.box.box1 = 0.0001;			//tunnel B
	Locations[n].locators_radius.box.box2 = 0.0001;			//tunnel A
	Locations[n].locators_radius.box.box3 = 0.0001;			//tunnel Z
	Locations[n].locators_radius.goto.goto2 = 3.0;			
	Locations[n].locators_radius.goto.goto5 = 1.5;	
	Locations[n].locators_radius.goto.goto17 = 3.0;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "gatedoor";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "door_N06";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "gatedoor_small_N06";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "door_N06";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "gatedoor_small_N06";
	
	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "gatedoor_w";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "gatedoor_small_N06";
	
	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "gatedoor_w";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "torch42";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "number_plate2";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "number_plate3";

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "number_plate1";

	Locations[n].island = "Redmond";
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Hut";

	Locations[n].id = "wr_prison_guard";
	locations[n].id.label = "Guard room";
	Locations[n].image = "wr_prison_guard.tga";

	//Sound
	locations[n].type = "Rogers_jail";
	//Models
	//Always
	Locations[n].models.always.locators = "Hut_locators_JRH1";
	Locations[n].models.always.house = "Hut";
	//Locations[n].models.always.l1 = "mine";
	//Day
	Locations[n].models.day.charactersPatch = "Hut_patch";
	//Night
	Locations[n].models.night.charactersPatch = "Hut_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_prison";
	Locations[n].reload.l1.emerge = "goto1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Woodes Rogers' prison.";
	
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_mine";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Woodes Rogers' tunnel.";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "wr_dungeon4_loop";
	Locations[n].reload.l3.emerge = "reload7";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Woodes Rogers' tunnel.";
	Locations[n].locators_radius.reload.reload3 = 0.0001;		//0.5 later
	Locations[n].reload.l3.disable = 1;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "gatedoor_small_stone";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "gatedoor_small_stone";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "gatedoor_small_stone";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "gatedoor_small_stone";
	
	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "chair";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "chair_fallen";

	Locations[n].island = "Redmond";
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].id = "wr_prison";
	locations[n].id.label = "Woodes Rogers' prison";
	Locations[n].filespath.models = "locations\inside\prison";
	Locations[n].image = "wr_prison.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_jail";

	//Models
	//Always
	Locations[n].models.always.prison = "Pri";
	Locations[n].models.always.locators = "Pri_l_JRH";		//start
	
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
	//guard room
	Locations[n].locators_radius.reload.reload13 = 2.0;		//checkpoint for reload loop to guardroom

	//floor hatch cell
	locations[n].reload.l15.name = "reload15";
	locations[n].reload.l15.go = "wr_dungeon3_right";
	locations[n].reload.l15.emerge = "reload1";
	Locations[n].reload.l15.autoreload = "0";
	//locations[n].reload.l15.disable = 1;
	Locations[n].locators_radius.reload.reload15 = 0.5;

	//gibbet room
	Locations[n].locators_radius.reload.reload16 = 2.0;		//checkpoint for reload loop to gibbet

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "gatedoor_store4_wall";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "gatedoor_store4_wall";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "gatedoor_vsmall_HUT";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "gatedoor_vsmall_HUTR";

	Locations[n].locators_radius.randitem.randitem5 = 0.1;
	Locations[n].items.randitem5 = "chest1_vco";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "plank2";			//in cell

	Locations[n].locators_radius.randitem.randitem7 = 0.0001;
	Locations[n].items.randitem7 = "steplock2";			//in cell, opens wall hatch

	Locations[n].locators_radius.randitem.randitem8 = 0.0001;
	Locations[n].items.randitem8 = "steplock2";			//outside cell, opens floor hatch

	Locations[n].locators_radius.randitem.randitem9 = 0.01;
	Locations[n].items.randitem9 = "hatch3U";			//storeroom style	yes!

	Locations[n].locators_radius.randitem.randitem10 = 0.01;
	Locations[n].items.randitem10 = "hatch8";			//wall hatch

	Locations[n].locators_radius.randitem.randitem11 = 0.01;
	Locations[n].items.randitem11 = "hatch8";			//wall hatch

	Locations[n].locators_radius.randitem.randitem12 = 0.01;
	Locations[n].items.randitem12 = "hatch3U_T";			//open floor hatch

	Locations[n].locators_radius.randitem.randitem13 = 0.01;
	Locations[n].items.randitem13 = "hatch9";			//black on floor

	Locations[n].locators_radius.randitem.randitem14 = 0.1;			
	Locations[n].items.randitem14 = "bladebarrel";			//on top of plank in cell

	Locations[n].locators_radius.randitem.randitem15 = 0.1;
	Locations[n].items.randitem15 = "gatedoor_store4_wall";

	Locations[n].locators_radius.randitem.randitem16 = 0.1;
	Locations[n].items.randitem16 = "gatedoor_store4_wall";

	Locations[n].locators_radius.randitem.randitem17 = 0.1;
	Locations[n].items.randitem17 = "gatedoor_vsmall_HUT";

	Locations[n].locators_radius.randitem.randitem18 = 0.1;
	Locations[n].items.randitem18 = "gatedoor_vsmall_HUTR";

	Locations[n].locators_radius.randitem.randitem19 = 0.1;			
	Locations[n].items.randitem19 = "bladebarrel";			//to step on to reach chest

	Locations[n].locators_radius.randitem.randitem20 = 0.1;			
	Locations[n].items.randitem20 = "bladebarrel";			//on steplock in cell

	Locations[n].locators_radius.randitem.randitem21 = 0.001;		
	Locations[n].items.randitem21 = "bladebarrel";			//on steplock outside cell

	Locations[n].locators_radius.randitem.randitem22 = 0.01;
	Locations[n].items.randitem22 = "plank3";			//in cell blocking wall hatch

	Locations[n].locators_radius.randitem.randitem23 = 0.01;
	Locations[n].items.randitem23 = "skull2";			//in cell blocking floor hatch

	Locations[n].locators_radius.randitem.randitem24 = 0.5;		//start position inner cell
	Locations[n].items.randitem24 = "key13";

	Locations[n].locators_radius.randitem.randitem25 = 0.5;
	Locations[n].items.randitem25 = "key14";

	Locations[n].locators_radius.randitem.randitem26 = 1.0;		//later position outer cell
	Locations[n].items.randitem26 = "key13";

	Locations[n].locators_radius.randitem.randitem27 = 0.01;
	Locations[n].items.randitem27 = "hatch8_tilt";			//wall hatch, stuck half way up

	Locations[n].locators_radius.goto.goto2 = 0.3;
	Locations[n].locators_radius.goto.goto3 = 0.7;
	
	Locations[n].locators_radius.goto.goto4 = 0.3;
	Locations[n].locators_radius.goto.goto5 = 0.7;

	Locations[n].locators_radius.goto.goto6 = 0.3;
	
	Locations[n].locators_radius.goto.goto9 = 0.1;
	Locations[n].locators_radius.goto.goto12 = 0.1;

	Locations[n].locators_radius.goto.goto17 = 0.3;
	Locations[n].locators_radius.goto.goto19 = 0.7;

	Locations[n].locators_radius.box.box1 = 0.3;			//barrel function on steplock A
	Locations[n].locators_radius.box.box2 = 0.3;			//barrel function on steplock B
	Locations[n].locators_radius.box.box3 = 0.6;
	Locations[n].locators_radius.box.box4 = 0.001;			//on top of open floor hatch, (in JRH8)
	Locations[n].locators_radius.box.box6 = 0.5;			//blue chest
	Locations[n].locators_radius.box.box8 = 0.5;			//cell door
	Locations[n].locators_radius.box.box9 = 0.5;			//cell door
	Locations[n].locators_radius.box.box10 = 0.5;			//step on open hatch
	Locations[n].locators_radius.box.box11 = 0.5;			//jump down again
	Locations[n].locators_radius.box.box12 = 0.4;			//step on barrel

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].id = "wr_gibbet";
	locations[n].id.label = "Woodes Rogers' prison";
	Locations[n].filespath.models = "locations\inside\prison";
	Locations[n].image = "wr_gibbet.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_jail";

	//Models
	//Always
	Locations[n].models.always.prison = "Pri";
	Locations[n].models.always.locators = "Pri_l_gibbet_JRH";
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
	//prison
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
	Locations[n].items.randitem5 = "gibbet1";
	
	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "bladebarrel2";				//down, standing up & empty, NOT for pickup
	
	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "pole1";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "pole1";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "plank1";				//horizontal up

	Locations[n].locators_radius.randitem.randitem10 = 0.1;
	Locations[n].items.randitem10 = "gibbet2";
	
	Locations[n].locators_radius.randitem.randitem11 = 0.1;
	Locations[n].items.randitem11 = "gibbet3";
					
	Locations[n].locators_radius.randitem.randitem12 = 0.1;
	Locations[n].items.randitem12 = "gibbet4";				//horizontal up
	
	Locations[n].locators_radius.randitem.randitem13 = 0.1;
	Locations[n].items.randitem13 = "barrel2_roll";				//up, lying down
	
	Locations[n].locators_radius.randitem.randitem14 = 0.1;
	Locations[n].items.randitem14 = "gibbet4";				//horizontal on floor

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	Locations[n].items.randitem15 = "pole2";				//cut off pole

	Locations[n].locators_radius.randitem.randitem16 = 0.001;
	Locations[n].items.randitem16 = "pole3";				//pole1 horizontal on floor

	Locations[n].locators_radius.randitem.randitem17 = 0.001;
	Locations[n].items.randitem17 = "plank3";				//plank1 45

	Locations[n].locators_radius.randitem.randitem18 = 0.5;
	Locations[n].items.randitem18 = "key12";				//key box

	Locations[n].locators_radius.randitem.randitem19 = 0.5;
	Locations[n].items.randitem19 = "bladeskull1";
	
	Locations[n].locators_radius.randitem.randitem20 = 0.5;
	Locations[n].items.randitem20 = "bladebarrel2";				//down, standing up & empty, for pickup!

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].id = "wr_mine_control";
	locations[n].id.label = "Port Royal old mine";
	Locations[n].filespath.models = "locations\inside\Dungeon_2\\";
	Locations[n].image = "wr_mine_control.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_mine";
	locations[n].fastreload = "Redmond";
	//Models
	//Always
	Locations[n].models.always.locators = "d02_l_JRH1_F";			//lever1 down (mine on), lever right down & flame
	Locations[n].models.always.dungeon = "d02";
	Locations[n].models.always.fonar = "d02_fn";
	//Day
	Locations[n].models.day.charactersPatch = "d02_p";

	//Night
	Locations[n].models.night.charactersPatch = "d02_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_mine";
	Locations[n].reload.l1.emerge = "reload7";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Port Royal old mine.";
	Locations[n].locators_radius.reload.reload1 = 0.5;

	Locations[n].locators_radius.goto.goto5 = 0.5;
	Locations[n].locators_radius.goto.goto6 = 2.0;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "gatedoor_w6";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "lever_up";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "lever_up";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "lever_up";

	Locations[n].locators_radius.randitem.randitem5 = 0.1;
	Locations[n].items.randitem5 = "lever3_up";			//right side, was lever_up

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "periscope_tilted";

	Locations[n].locators_radius.randitem.randitem7 = 0.1;
	Locations[n].items.randitem7 = "lever_down";

	Locations[n].locators_radius.randitem.randitem8 = 0.1;
	Locations[n].items.randitem8 = "lever_down";
	
	Locations[n].locators_radius.randitem.randitem9 = 0.1;
	Locations[n].items.randitem9 = "lever_down";

	Locations[n].locators_radius.randitem.randitem10 = 0.1;
	Locations[n].items.randitem10 = "lever3_down";			//right side, was lever_down

	Locations[n].locators_radius.randitem.randitem11 = 0.1;
	Locations[n].items.randitem11 = "lever_base";

	Locations[n].locators_radius.randitem.randitem12 = 0.1;
	Locations[n].items.randitem12 = "lever_base";	

	Locations[n].locators_radius.randitem.randitem13 = 0.1;
	Locations[n].items.randitem13 = "lever_base";	

	Locations[n].locators_radius.randitem.randitem14 = 0.1;
	Locations[n].items.randitem14 = "steplock_v3";			//to lever3

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	Locations[n].items.randitem15 = "number_plate1";

	Locations[n].locators_radius.randitem.randitem16 = 0.001;
	Locations[n].items.randitem16 = "number_plate2_floor";

	Locations[n].locators_radius.randitem.randitem17 = 0.001;
	Locations[n].items.randitem17 = "number_plate3";

	LAi_LocationFantomsGen(&locations[n], true);

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------
	//tunnel 2 + swimming

	Locations[n].filespath.models = "locations\Inside\Dungeon_3";
	Locations[n].id = "wr_dungeon3_left";
	Locations[n].image = "wr_dungeon3_left.tga";
	locations[n].id.label = "Port Royal old mine";

	//Sound
	locations[n].type = "Rogers_mine";
	//Models
	Locations[n].models.back = "back\d03env_";
	//Always
	Locations[n].models.always.locators = "d03_l_JRH_L1";
	Locations[n].models.always.house = "d03";
	//Day
	Locations[n].models.day.charactersPatch = "d03_p";
	//Night
	Locations[n].models.night.charactersPatch = "d03_p";

	//Environment
	//Locations[n].environment.weather = "true";	//true needed for dark water (Flooded Mine) or any fog weather, but switch in q_r
	Locations[n].environment.weather = "false";	//from start to avoid rain
	Locations[n].environment.sea = "false";		//change this to "true" from quest_reaction	

	//Reload map
	//wall stop - later swim over it
	Locations[n].locators_radius.reload.reload5 = 2.0;		//checkpoint for wall stop (swim over later)

	//after swim 2 back to 1
	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "wr_dungeon3_right";
	Locations[n].reload.l7.emerge = "goto4";
	Locations[n].reload.l7.autoreload = "1";
	Locations[n].reload.l7.label = "Port Royal old mine.";
	Locations[n].locators_radius.reload.reload7 = 2.0;

	//A exit to mine
	Locations[n].reload.l8.name = "reload8";
	Locations[n].reload.l8.go = "wr_mine";
	Locations[n].reload.l8.emerge = "reload5";
	Locations[n].reload.l8.autoreload = "1";
	Locations[n].reload.l8.label = "Port Royal old mine.";
	Locations[n].locators_radius.reload.reload8 = 2.0;

	//A to dark loop
	Locations[n].reload.l9.name = "reload9";
	Locations[n].reload.l9.go = "wr_dungeon3_left";
	Locations[n].reload.l9.emerge = "goto7";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "Port Royal old mine.";
	Locations[n].locators_radius.reload.reload9 = 0.6;

	//A to dark loop
	Locations[n].reload.l10.name = "reload10";
	Locations[n].reload.l10.go = "wr_dungeon3_left";
	Locations[n].reload.l10.emerge = "goto8";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "Port Royal old mine.";
	Locations[n].locators_radius.reload.reload10 = 0.8;

	//dark loop to A
	Locations[n].reload.l11.name = "reload11";
	Locations[n].reload.l11.go = "wr_dungeon3_left";
	Locations[n].reload.l11.emerge = "reload9";
	Locations[n].reload.l11.autoreload = "1";
	Locations[n].reload.l11.label = "Port Royal old mine.";
	Locations[n].locators_radius.reload.reload11 = 2.0;

	//dark loop to A
	Locations[n].reload.l12.name = "reload12";
	Locations[n].reload.l12.go = "wr_dungeon3_left";
	Locations[n].reload.l12.emerge = "reload10";
	Locations[n].reload.l12.autoreload = "1";
	Locations[n].reload.l12.label = "Port Royal old mine.";
	Locations[n].locators_radius.reload.reload12 = 2.0;

	Locations[n].locators_radius.reload.reload13 = 0.0001;
	
	Locations[n].locators_radius.goto.new_shaft = 2.0;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "gatedoor_small_N06";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "gatedoor_small_N06";
	
	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "gatedoor_stone";		//left lit
	
	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "gatedoor_small_N06";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "door_N06";

	Locations[n].locators_radius.randitem.randitem6 = 0.1;
	Locations[n].items.randitem6 = "gatedoor_small_N06";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "door_N06";

	Locations[n].locators_radius.randitem.randitem8 = 0.5;			
	Locations[n].items.randitem8 = "bladehammer";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "door_N06";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "door_N06";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "torch42";

	Locations[n].locators_radius.randitem.randitem12 = 0.1;
	Locations[n].items.randitem12 = "gatedoor_stone";		//right lit

	Locations[n].locators_radius.randitem.randitem13 = 0.1;
	Locations[n].items.randitem13 = "gateroof_wood";			

	Locations[n].locators_radius.randitem.randitem14 = 0.1;		//up to cell
	Locations[n].items.randitem14 = "hatch11D";

	Locations[n].locators_radius.randitem.randitem15 = 0.1;		//up to cell
	Locations[n].items.randitem15 = "hatch11D_O";

	Locations[n].locators_radius.randitem.randitem16 = 0.001;
	Locations[n].items.randitem16 = "torch42";

	Locations[n].locators_radius.randitem.randitem17 = 0.001;
	Locations[n].items.randitem17 = "torch42";

	Locations[n].locators_radius.randitem.randitem18 = 0.1;
	Locations[n].items.randitem18 = "gatedoor_small_N06";

	Locations[n].locators_radius.randitem.randitem19 = 0.1;
	Locations[n].items.randitem19 = "gatedoor_small_N06";

	Locations[n].locators_radius.randitem.randitem20 = 0.001;
	Locations[n].items.randitem20 = "hatch11";			//down to animist tunnel

	Locations[n].locators_radius.randitem.randitem21 = 0.001;	//after swim
	Locations[n].items.randitem21 = "torch42";

	Locations[n].locators_radius.randitem.randitem22 = 0.001;	//after swim
	Locations[n].items.randitem22 = "torch42";

	Locations[n].locators_radius.randitem.randitem23 = 0.001;	//left unlit
	Locations[n].items.randitem23 = "gatedoor_dark_stone";

	Locations[n].locators_radius.randitem.randitem24 = 0.001;	//right unlit
	Locations[n].items.randitem24 = "gatedoor_dark_stone";

	Locations[n].locators_radius.randitem.randitem25 = 0.1;
	Locations[n].items.randitem25 = "gatedoor_stone";		//LOW: left lit (looks dark in flooded weather)

	Locations[n].locators_radius.randitem.randitem26 = 0.1;
	Locations[n].items.randitem26 = "gatedoor_dark_stone";		//LOW: right unlit

	Locations[n].locators_radius.randitem.randitem27 = 1.0;
	Locations[n].items.randitem27 = "bladepickaxe2";

	Locations[n].locators_radius.randitem.randitem28 = 0.1;		//B
	Locations[n].items.randitem28 = "gateroof_wood";

	Locations[n].locators_radius.randitem.randitem29 = 0.1;		//A left
	Locations[n].items.randitem29 = "gateroof_wood";			

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------
	//tunnel 1 + connection to tunnel 2

	Locations[n].filespath.models = "locations\Inside\Dungeon_3";
	Locations[n].id = "wr_dungeon3_right";
	Locations[n].image = "wr_dungeon3_right.tga";
	locations[n].id.label = "Port Royal old mine";

	//Sound
	locations[n].type = "Rogers_mine";
	//Models
	Locations[n].models.back = "back\d03env_";
	//Always
	Locations[n].models.always.locators = "d03_l_JRH_R1";
	Locations[n].models.always.house = "d03";
	//Day
	Locations[n].models.day.charactersPatch = "d03_p";
	//Night
	Locations[n].models.night.charactersPatch = "d03_p";

	//Environment
	//Locations[n].environment.weather = "true";	//true needed for dark water (Flooded Mine) or any fog weather, but switch in q_r
	Locations[n].environment.weather = "false";	//from start to avoid rain
	Locations[n].environment.sea = "false";		//change this to "true" from quest_reaction	

	//Reload map
	//B ladder up to cell
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_prison";
	Locations[n].reload.l1.emerge = "reload15";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Woodes Rogers' prison.";
	locations[n].reload.l1.disable = 1;

	//B exit to mine
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_mine";
	Locations[n].reload.l2.emerge = "reload6";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Port Royal old mine.";
	Locations[n].locators_radius.reload.reload2 = 2.0;

	Locations[n].locators_radius.reload.reload6 = 2.0;		//checkpoint for blockloop + teleport later
	Locations[n].locators_radius.reload.reload7 = 2.0;		//checkpoint for teleport back to tunnel 1
	Locations[n].locators_radius.reload.reload13 = 2.0;		//checkpoint for wallstop

	//floor hatch after swim
	Locations[n].reload.l14.name = "reload14";
	Locations[n].reload.l14.go = "wr_dungeon4_low";
	Locations[n].reload.l14.emerge = "reload2";
	Locations[n].reload.l14.autoreload = "0";
	Locations[n].reload.l14.label = "Port Royal old mine.";
	Locations[n].locators_radius.reload.reload14 = 0.5;

	Locations[n].locators_radius.reload.reload5 = 0.0001;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "gatedoor_small_N06";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "gatedoor_small_N06";
	
	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "gatedoor_stone";		//left lit
	
	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "gatedoor_small_N06";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "door_N06";

	Locations[n].locators_radius.randitem.randitem6 = 0.1;
	Locations[n].items.randitem6 = "gatedoor_small_N06";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "door_N06";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "door_NGR";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "door_N06";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "door_N06";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "torch42";

	Locations[n].locators_radius.randitem.randitem12 = 0.1;
	Locations[n].items.randitem12 = "gatedoor_stone";		//right lit

	Locations[n].locators_radius.randitem.randitem13 = 0.1;
	Locations[n].items.randitem13 = "gateroof_wood";			

	Locations[n].locators_radius.randitem.randitem14 = 0.1;		//up to cell
	Locations[n].items.randitem14 = "hatch11D";

	Locations[n].locators_radius.randitem.randitem15 = 0.1;		//up to cell
	Locations[n].items.randitem15 = "hatch11D_O";

	Locations[n].locators_radius.randitem.randitem16 = 0.001;
	Locations[n].items.randitem16 = "torch42";

	Locations[n].locators_radius.randitem.randitem17 = 0.001;
	Locations[n].items.randitem17 = "torch42";

	Locations[n].locators_radius.randitem.randitem18 = 0.1;
	Locations[n].items.randitem18 = "gatedoor_small_N06";

	Locations[n].locators_radius.randitem.randitem19 = 0.1;
	Locations[n].items.randitem19 = "gatedoor_small_N06";

	Locations[n].locators_radius.randitem.randitem20 = 0.001;
	Locations[n].items.randitem20 = "hatch11";			//down to animist tunnel

	Locations[n].locators_radius.randitem.randitem21 = 0.001;	//after swim
	Locations[n].items.randitem21 = "torch42";

	Locations[n].locators_radius.randitem.randitem22 = 0.001;	//after swim
	Locations[n].items.randitem22 = "torch42";

	Locations[n].locators_radius.randitem.randitem23 = 0.001;	//left unlit
	Locations[n].items.randitem23 = "gatedoor_dark_stone";

	Locations[n].locators_radius.randitem.randitem24 = 0.001;	//right unlit
	Locations[n].items.randitem24 = "gatedoor_dark_stone";

	Locations[n].locators_radius.randitem.randitem25 = 0.1;
	Locations[n].items.randitem25 = "gatedoor_stone";		//LOW: left lit (looks dark in flooded weather)

	Locations[n].locators_radius.randitem.randitem26 = 0.1;
	Locations[n].items.randitem26 = "gatedoor_dark_stone";		//LOW: right unlit

	Locations[n].locators_radius.randitem.randitem27 = 1.0;
	Locations[n].items.randitem27 = "bladepickaxe2";

	Locations[n].locators_radius.randitem.randitem28 = 0.1;
	Locations[n].items.randitem28 = "gateroof_wood";			

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------
	//tunnel 3 start

	Locations[n].filespath.models = "locations\Inside\Dungeon_4";
	Locations[n].id = "wr_dungeon4_main";
	Locations[n].image = "wr_dungeon4_main.tga";
	locations[n].id.label = "Port Royal old mine";

	//Sound
	locations[n].type = "Rogers_mine";
	//Models
	Locations[n].models.back = "back\d04env_";
	//Always
	Locations[n].models.always.locators = "d04_l_JRH_OFF1";		//old start
	Locations[n].models.always.house = "d04";
	//Day
	Locations[n].models.day.charactersPatch = "d04_p";
	//Night
	Locations[n].models.night.charactersPatch = "d04_p";

	//Environment
	Locations[n].environment.weather = "true";	//ok with true from start, (1st visit should be medium foggy mine)
	Locations[n].environment.sea = "false";		//change this to "true" from quest_reaction
	//Locations[n].environment.sea = "true";

	//Reload map
	//Z ladder up
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_dungeon4_main";
	Locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Port Royal old mine.";
	locations[n].reload.l1.disable = 1;			//opened by Caroline K later ?
	
	//Z ladder up to well
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Redmond_town_exit_2";
	Locations[n].reload.l4.emerge = "goto9";		
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Exit from Redmond.";
	Locations[n].locators_radius.reload.reload4 = 0.2;

	//Z to loop X
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_dungeon4_main";
	Locations[n].reload.l2.emerge = "goto10";			
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Port Royal old mine.";
	Locations[n].locators_radius.reload.reload2 = 2.0;

	//Z ladder down
	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "wr_dungeon4_main";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Port Royal old mine.";
	Locations[n].locators_radius.reload.reload5 = 0.2;
	
	//Z exit to mine
	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "wr_mine";
	Locations[n].reload.l6.emerge = "reload4";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Port Royal old mine.";
	Locations[n].locators_radius.reload.reload6 = 2.0;

	//rope to guard room
	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "wr_prison_guard";
	Locations[n].reload.l7.emerge = "reload3";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Guard room";

	//just in case loop
	//Locations[n].reload.l8.name = "reload8";			//checkpoint for loop

	//just in case loop
	//Locations[n].reload.l9.name = "reload9";			//checkpoint for loop
	
	Locations[n].locators_radius.goto.goto6 = 1.5;
	Locations[n].locators_radius.goto.goto7 = 3.0;
	Locations[n].locators_radius.goto.goto9 = 1.0;

	Locations[n].locators_radius.goto.skel5 = 1.5;
	Locations[n].locators_radius.goto.skel6 = 1.5;
	Locations[n].locators_radius.goto.fire_hint = 2.0;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "gatedoor_small_N06";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "gatedoor_small_N06";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "gatedoor_small_N06";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "rope_vertical";

	Locations[n].locators_radius.randitem.randitem5 = 0.1;
	Locations[n].items.randitem5 = "gateroof_white_stone";

	Locations[n].locators_radius.randitem.randitem6 = 0.1;
	Locations[n].items.randitem6 = "hatch10";

	Locations[n].locators_radius.randitem.randitem7 = 0.1;
	Locations[n].items.randitem7 = "gateroof_wood";

	Locations[n].locators_radius.randitem.randitem8 = 0.1;
	Locations[n].items.randitem8 = "hatch11D";

	Locations[n].locators_radius.randitem.randitem9 = 0.1;
	Locations[n].items.randitem9 = "gatedoor_small_N06";

	Locations[n].locators_radius.randitem.randitem10 = 0.1;
	Locations[n].items.randitem10 = "gatedoor_small_N06";

	Locations[n].locators_radius.randitem.randitem11 = 0.1;		
	Locations[n].items.randitem11 = "gatedoor_small_N06";

	Locations[n].locators_radius.randitem.randitem16 = 0.01;
	Locations[n].items.randitem16 = "gatedoor_small_N06";

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//  -------------------------------------------------
	//tunnel 3 loop

	Locations[n].filespath.models = "locations\Inside\Dungeon_4";
	Locations[n].id = "wr_dungeon4_loop";
	Locations[n].image = "wr_dungeon4_loop.tga";
	locations[n].id.label = "Port Royal old mine";

	//Sound
	locations[n].type = "Rogers_mine";
	//Models
	Locations[n].models.back = "back\d04env_";
	//Always
	Locations[n].models.always.locators = "d04_l_JRH_ON1";		//old always
	Locations[n].models.always.house = "d04";
	//Day
	Locations[n].models.day.charactersPatch = "d04_p";
	//Night
	Locations[n].models.night.charactersPatch = "d04_p";

	//Environment
	Locations[n].environment.weather = "true";	//ok with true from start, (1st visit should be medium foggy mine)
	Locations[n].environment.sea = "false";		//change this to "true" from quest_reaction
	//Locations[n].environment.sea = "true";

	//Reload map

	//back from loop X to Z
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "wr_dungeon4_main";
	Locations[n].reload.l3.emerge = "goto2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Port Royal old mine.";
	Locations[n].locators_radius.reload.reload3 = 2.0;

	//rope to guard room
	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "wr_prison_guard";
	Locations[n].reload.l7.emerge = "reload3";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Guard room";

	Locations[n].locators_radius.goto.goto6 = 1.5;
	Locations[n].locators_radius.goto.goto7 = 3.0;
	Locations[n].locators_radius.goto.goto9 = 1.0;

	Locations[n].locators_radius.goto.skel5 = 1.5;
	Locations[n].locators_radius.goto.skel6 = 1.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "gatedoor_small_N06";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "gatedoor_small_N06";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "gatedoor_small_N06";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "rope_vertical";

	Locations[n].locators_radius.randitem.randitem5 = 0.1;
	Locations[n].items.randitem5 = "gateroof_white_stone";

	Locations[n].locators_radius.randitem.randitem6 = 0.1;
	Locations[n].items.randitem6 = "hatch10";

	Locations[n].locators_radius.randitem.randitem7 = 0.1;
	Locations[n].items.randitem7 = "gateroof_wood";

	Locations[n].locators_radius.randitem.randitem8 = 0.1;
	Locations[n].items.randitem8 = "hatch11D";

	Locations[n].locators_radius.randitem.randitem9 = 0.1;
	Locations[n].items.randitem9 = "gatedoor_small_N06";

	Locations[n].locators_radius.randitem.randitem10 = 0.1;
	Locations[n].items.randitem10 = "gatedoor_small_N06";

	Locations[n].locators_radius.randitem.randitem11 = 0.1;		
	Locations[n].items.randitem11 = "gatedoor_small_N06";

	Locations[n].locators_radius.randitem.randitem12 = 0.5;
	Locations[n].items.randitem12 = "bladeaxe4";

	Locations[n].locators_radius.randitem.randitem13 = 0.01;
	Locations[n].items.randitem13 = "skull2";			

	Locations[n].locators_radius.randitem.randitem14 = 0.01;
	Locations[n].items.randitem14 = "skull2";

	Locations[n].locators_radius.randitem.randitem15 = 0.01;
	Locations[n].items.randitem15 = "skull2";

	Locations[n].locators_radius.randitem.randitem16 = 0.01;
	Locations[n].items.randitem16 = "gatedoor_small_N06";

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------
	//low tunnel Y (under tunnelA right)

	Locations[n].filespath.models = "locations\Inside\Dungeon_4";
	Locations[n].id = "wr_dungeon4_low";
	Locations[n].image = "wr_dungeon4_low.tga";
	locations[n].id.label = "Port Royal old mine";

	//Sound
	locations[n].type = "Rogers_mine";
	//Models
	Locations[n].models.back = "back\d04env_";
	//Always
	Locations[n].models.always.locators = "d04_l_JRH_low";
	Locations[n].models.always.house = "d04";
	Locations[n].models.always.l1 = "";		//rock3 after roof has fallen down
	//Day
	Locations[n].models.day.charactersPatch = "d04_p";
	//Night
	Locations[n].models.night.charactersPatch = "d04_p";

	//Environment
	Locations[n].environment.weather = "false";		
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_dungeon3_right";
	Locations[n].reload.l2.emerge = "reload14";			
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Port Royal old mine.";
	//Locations[n].locators_radius.reload.reload2 = 2.0;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "wr_cavern";
	Locations[n].reload.l3.emerge = "reload3";	
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.0001;		//1.0 later

	Locations[n].locators_radius.reload.reload4 = 2.0;		//checkpoint for back off
	Locations[n].locators_radius.reload.reload5 = 2.0;		//checkpoint for back off

	Locations[n].locators_radius.goto.cavern = 1.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "gateroof_wood";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "hatch11D";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "gatedoor_small_N06";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "gatedoor_small_N06";

	//Locations[n].locators_radius.randitem.randitem5 = 0.5;
	Locations[n].items.randitem5 = "bladesaw";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "rope_vertical";

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].filespath.models = "locations\outside\Mayak_inside";

	Locations[n].id = "wr_cannon_tower";
	locations[n].id.label = "Cannon tower";
	Locations[n].image = "wr_cannon_tower.tga";
	//Sound
	locations[n].type = "Vane_towers";			

	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.shore = "imayak";
	Locations[n].models.always.shore.foam = "1";
	Locations[n].models.always.seabed = "iMayak_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.l3 = "";				//barrel3 from [16]
	//Models
	//Always
	Locations[n].models.always.locators = "imayak_l_JRH";
	Locations[n].models.always.shore = "imayak";
	Locations[n].models.always.window = "iMayak_w";
	//Day
	Locations[n].models.day.charactersPatch = "imayak_p";
	Locations[n].models.day.jumpPatch = "imayak_j";

	//Night
	Locations[n].models.night.charactersPatch = "imayak_p";
	Locations[n].models.night.jumpPatch = "imayak_j";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_cave_shore";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Rocky Shore.";
	Locations[n].locators_radius.reload.Reload1 = 1.0;

	Locations[n].locators_radius.box.box1 = 0.0001;			//gunpowder barrel r = 0.7 from [16]
	Locations[n].locators_radius.box.box2 = 0.5;			//musket lever
	Locations[n].locators_radius.box.box3 = 0.5;			//musket lever
	Locations[n].locators_radius.box.box5 = 0.5;			//missing/place musket lever

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "cannon_bigger";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "gatedoor_vsmall_HUT";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "gatedoor_pgrey";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "gatedoor_pgrey";

	Locations[n].locators_radius.randitem.randitem5 = 0.1;
	Locations[n].items.randitem5 = "gatedoor_vsmall_HUTR";

	Locations[n].locators_radius.randitem.randitem6 = 0.1;
	Locations[n].items.randitem6 = "cannon_very_big";

	Locations[n].locators_radius.randitem.randitem7 = 0.1;
	Locations[n].items.randitem7 = "gatedoor_pgrey";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;	//was 1.5
	Locations[n].items.randitem8 = "key8";				//inisible model, the orig key16 is not longer in use	

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "Cannonbox";

	Locations[n].locators_radius.randitem.randitem10 = 0.1;
	Locations[n].items.randitem10 = "gatedoor_pgrey";

	Locations[n].locators_radius.randitem.randitem11 = 0.1;
	Locations[n].items.randitem11 = "cannon_very_big";

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "Cannonbox";

	Locations[n].locators_radius.randitem.randitem13 = 0.1;
	Locations[n].items.randitem13 = "cannon_bigger";

	Locations[n].locators_radius.randitem.randitem14 = 0.01;
	Locations[n].items.randitem14 = "musket_item";

	Locations[n].locators_radius.randitem.randitem15 = 0.01;
	Locations[n].items.randitem15 = "musket_item";

	Locations[n].locators_radius.randitem.randitem16 = 0.01;
	Locations[n].items.randitem16 = "musket_item";

	Locations[n].locators_radius.randitem.randitem17 = 0.01;
	Locations[n].items.randitem17 = "musket_item2";

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Shore_4";
	
	Locations[n].id = "wr_cave_shore";
	locations[n].id.label = "Cave shore";
	locations[n].worldmap = "RShore 2";			//instead of Rocky Shore
	Locations[n].image = "wr_cave_shore.tga";

	//Sound
	locations[n].type = "Vane_seashore";

	//locations[n].townsack = "Redmond";
	//Locations[n].townsack = "Falaise de Fleur";
	//Locations[n].townsack = "Isla Muelle";
	//Locations[n].townsack = "Conceicao";
	//Locations[n].townsack = "Douwesen";
	Locations[n].townsack = "Grand Turk"; 

	//Models
	//Always
	Locations[n].models.always.locators = "Shore04_l_JRH";	
	Locations[n].models.always.shore = "Shore04";
	Locations[n].models.always.l4 = "wood_tower";
	Locations[n].models.always.l5 = "short_ladder";
	Locations[n].models.always.l6 = "flagpole";
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

	//sea
	Locations[n].reload.l4.name = "sea";
	Locations[n].reload.l4.go = "Redmond";
	Locations[n].reload.l4.emerge = "reload_3";
	Locations[n].reload.l4.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l4.label = "Ship.";
	else
		Locations[n].reload.l4.label = "Sea.";
	Locations[n].locators_radius.reload.sea = 3.0;

	Locations[n].reload.l11.name = "rock1";
	Locations[n].reload.l11.go = "wr_Cavern";
	Locations[n].reload.l11.emerge = "goto3";
	Locations[n].reload.l11.autoreload = "0";	
	Locations[n].reload.l11.label = "Hidden Cave.";

	Locations[n].reload.l111.name = "rock1_back";
	Locations[n].reload.l111.go = "wr_Cavern";
	Locations[n].reload.l111.emerge = "goto3";
	Locations[n].reload.l111.autoreload = "0";
	Locations[n].locators_radius.reload.rock1_back = 0.5;
	Locations[n].reload.l111.label = "Hidden Cave.";

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Redmond_shore_02";
	Locations[n].reload.l1.emerge = "arrive";			//was reload3Z
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 4.0;
	Locations[n].reload.l1.label = "Rocky Shore.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_cannon_tower";
	Locations[n].reload.l2.emerge = "goto4";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	locations[n].reload.l2.disable = 1;				//closed 1:st visit, open 2:nd visit

	Locations[n].reload.l33.name = "locator3";
	Locations[n].reload.l33.go = "wr_cave_shore";
	Locations[n].reload.l33.emerge = "reload3";
	Locations[n].reload.l33.autoreload = "0";
	Locations[n].reload.l33.label = "";
	locations[n].reload.l33.disable = 1;
	Locations[n].locators_radius.reload.reload33 = 0.5;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "wr_church_outside";
	Locations[n].reload.l3.emerge = "reload8";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "wr_wood_tower1";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "";
	Locations[n].locators_radius.reload.reload6 = 0.1;

	Locations[n].reload.l7.name = "reload7";
   	Locations[n].reload.l7.go = "wr_wood_tower2";
   	Locations[n].reload.l7.emerge = "reload4";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "";
	Locations[n].locators_radius.reload.reload7 = 0.01;
	
	Locations[n].reload.l10.name = "reload10";
   	Locations[n].reload.l10.go = "wr_wood_tower3";
   	Locations[n].reload.l10.emerge = "goto4";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "";
	Locations[n].locators_radius.reload.reload10 = 0.01;

	Locations[n].reload.l77.name = "boat7D";
	Locations[n].reload.l77.go = "wr_cave_shore";
	Locations[n].reload.l77.emerge = "boat7";
	Locations[n].reload.l77.autoreload = "0";
	Locations[n].reload.l77.label = "";
	Locations[n].locators_radius.reload.boat7D = 0.7;

	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box2 = 1.5;
	Locations[n].locators_radius.box.box3 = 0.5;	
	Locations[n].locators_radius.box.box5 = 0.7;	
	Locations[n].locators_radius.box.box9 = 0.1;	
	Locations[n].locators_radius.goto.megaphone = 3.8;
		
	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "gatedoor_w7";				//to cavern

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "mill_destroyed";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "cannon_pipe";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;		
	Locations[n].items.randitem4 = "fallen_tree";					

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	//Locations[n].items.randitem5 = "";					//not used

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "cannon_pipe";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "cannon_pipe";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "cannon_very_big_upside_down";	

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "cannon_very_big";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "cannon_pipe";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "gatedoor_w7";				//to sacristy

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "rock1";

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	//Locations[n].items.randitem13 = "";					//not used				

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
	//Locations[n].items.randitem14 = "";					//not used

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	//Locations[n].items.randitem15 = "";					//not used
					
	Locations[n].locators_radius.randitem.randitem16 = 0.001;
	Locations[n].items.randitem16 = "cannon";

	Locations[n].locators_radius.randitem.randitem17 = 0.001;
	Locations[n].items.randitem17 = "cannonbox";

	Locations[n].locators_radius.randitem.randitem18 = 0.001;
	Locations[n].items.randitem18 = "door_largeh";

	Locations[n].locators_radius.randitem.randitem19 = 0.001;
	Locations[n].items.randitem19 = "rock1";

	Locations[n].locators_radius.randitem.randitem20 = 0.001;
	Locations[n].items.randitem20 = "ladder_very_big";

	Locations[n].locators_radius.randitem.randitem21 = 0.001;
	Locations[n].items.randitem21 = "hatch11_O";
	
	Locations[n].locators_radius.randitem.randitem22 = 0.001;
	Locations[n].items.randitem22 = "hatch11_T";

	Locations[n].locators_radius.randitem.randitem23 = 0.001;
	Locations[n].items.randitem23 = "door_N06";

	Locations[n].locators_radius.randitem.randitem24 = 0.001;
	Locations[n].items.randitem24 = "door_N07";

	Locations[n].locators_radius.randitem.randitem25 = 0.001;
	Locations[n].items.randitem25 = "boat3";

	Locations[n].locators_radius.randitem.randitem26 = 0.001;
	Locations[n].items.randitem26 = "chest3U_vco";

	Locations[n].locators_radius.randitem.randitem27 = 0.001;
	Locations[n].items.randitem27 = "boat4";

	Locations[n].locators_radius.randitem.randitem28 = 0.001;
	Locations[n].items.randitem28 = "cannonl";

	Locations[n].items.randitem29 = "spyglass5";

	Locations[n].locators_radius.randitem.randitem30 = 0.5;
	Locations[n].items.randitem30 = "key19";

	Locations[n].island = "Redmond";
	
	n = n + 1;

// -------------------------------------------------
	locations[n].id = "wr_wood_tower1";
	locations[n].id.label = "Wood tower";
	Locations[n].image = "wr_wood_tower1.tga";
	
	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "Vane_towers";		
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\largehouse01";
	Locations[n].filespath.textures = "locations\inside\largehouse01\wood_tower";
	locations[n].models.always.l1 = "largehouse01";
	locations[n].models.always.locators = "largehouse01_locators_JRH_wood";

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
	locations[n].reload.l1.go = "wr_cave_shore";
	locations[n].reload.l1.emerge = "reload9";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "";
	
	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "wr_wood_tower2";
	locations[n].reload.l2.emerge = "goto3";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "";

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "wr_farm_booty";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "";

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "gatedoor_WT1";	

	Locations[n].locators_radius.randitem.randitem2 = 1.0;
	Locations[n].items.randitem2 = "megaphone";			
	
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond";
	n = n + 1;

// -------------------------------------------------

	Locations[n].id = "wr_wood_tower2";
	locations[n].id.label = "Wood tower";
	Locations[n].filespath.models = "locations\inside\store04";
	Locations[n].filespath.textures = "locations\inside\store04\wood_tower";
	Locations[n].image = "wr_wood_tower2.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Vane_towers";		

	//Models
	//Always
	Locations[n].models.always.locators = "store04_locators_JRH6";	//JRH6 start (cannon out), JRH7 later (cannon in)
	Locations[n].models.always.tavern = "store04";
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
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "wr_cave_shore";
    	Locations[n].reload.l4.emerge = "R7";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.5;
	locations[n].reload.l4.disable = 1;			//opened later	

	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "wr_wood_tower1";
	Locations[n].reload.l7.emerge = "reload2";
	Locations[n].reload.l7.autoreload = "1";
	Locations[n].reload.l7.label = "";

	Locations[n].locators_radius.goto.goto3 = 1.0;
	Locations[n].locators_radius.box.box1 = 0.7;
	Locations[n].locators_radius.box.box2 = 0.7;

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
	Locations[n].items.randitem13 = "gatedoor_LH1";	

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
//	Locations[n].items.randitem14 = "gatedoor_p";

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	Locations[n].items.randitem15 = "lilgun";

	Locations[n].locators_radius.randitem.randitem16 = 0.001;
	Locations[n].items.randitem16 = "gatedoor_WT1";			

	Locations[n].locators_radius.randitem.randitem17 = 0.001;
	Locations[n].items.randitem17 = "gatedoor_wT1";			

	Locations[n].locators_radius.randitem.randitem18 = 0.001;
	Locations[n].items.randitem18 = "gatedoor_WT2";			

	Locations[n].locators_radius.randitem.randitem19 = 0.001;
	Locations[n].items.randitem19 = "chest5_coas";		

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "wr_wood_tower3";
	locations[n].id.label = "Wood tower";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house\\";
	Locations[n].filespath.textures = "locations\inside\Doubleflour_house\wood_tower";
	Locations[n].image = "wr_wood_tower3.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Vane_towers";		
	
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F1_l_JRH3_M";	//later ...JRH3 (musket picked up), later ...JRH3_L (ladder)
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
	Locations[n].reload.l2.go = "wr_cave_shore";
	Locations[n].reload.l2.emerge = "spyglass";		//later head,JRH3 (was reload8) 
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "wr_wood_tower3";
	Locations[n].reload.l3.emerge = "reload4";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "wr_cave_shore";			
    	Locations[n].reload.l4.emerge = "R10";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.3;
	
	Locations[n].locators_radius.box.box1 = 0.5;		//obs 1.0 when boathook is picked up
	Locations[n].locators_radius.box.box2 = 0.3;		//walk to musket

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_N06";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "gatedoor_w";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "gateroof_wood";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "gatedoor_w";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "ladder_big";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;		//ri2 from attic stairs
	Locations[n].items.randitem6 = "hatch11D";

	Locations[n].items.randitem7 = "musket_item";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Cavern_blue";
	Locations[n].id = "wr_Cavern";
	locations[n].id.label = "Blue cavern";
	Locations[n].image = "wr_cavern.tga";

	//Sound
	locations[n].type = "blue_cavern";
	//Models
	//Always
	Locations[n].models.always.locators = "cavern_l_JRH_ground_open";		//new start mode (coming from mine)

	Locations[n].models.always.l1 = "cavern";
	Locations[n].models.always.l2 = "Crystals";
	Locations[n].models.always.l2.tech = "EnvironmentShader";
	Locations[n].models.always.l2.reflection = 0.25;
	//Locations[n].models.always.l3 = "ladder_very_big";				//later on
	Locations[n].models.always.l3 = "";						//start

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
	Locations[n].reload.l1.go = "wr_church_outside";
	Locations[n].reload.l1.emerge = "goto1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	Locations[n].locators_radius.reload.reload1 = 0.5;
	locations[n].reload.l1.disable = 1;				//new start mode (coming from mine)	

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_cave_shore";
	Locations[n].reload.l2.emerge = "rock1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "?????";
	Locations[n].locators_radius.reload.reload2 = 0.5;
	locations[n].reload.l2.disable = 1;				//opened later after medicine quest is given

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "wr_dungeon4_low";
	Locations[n].reload.l3.emerge = "return";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Port Royal old mine.";
	Locations[n].locators_radius.reload.reload3 = 0.00001;		

	Locations[n].locators_radius.box.box4 = 0.00001;		//1.0 when red chest is picked up from uder boat
	Locations[n].locators_radius.goto.goto6 = 1.0;
	Locations[n].locators_radius.goto.water = 2.0;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "gatedoor_wN";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;	//out to cave shore
	Locations[n].items.randitem2 = "door_N11";			//was door_N10

	Locations[n].locators_radius.randitem.randitem3 = 0.001;	//out to pirate church
	Locations[n].items.randitem3 = "gatedoor_vsmall_BRG";		//was gatedoor_very_small

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "gatedoor_wN";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "window2";			//lower (closed) pos

	Locations[n].locators_radius.randitem.randitem6 = 0.001;	
	Locations[n].items.randitem6 = "window2";			//upper (open) pos

	Locations[n].locators_radius.randitem.randitem7 = 0.001;	
	Locations[n].items.randitem7 = "rope_vertical_bright";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;	
	Locations[n].items.randitem8 = "chest3L_vco";			//in air OR on ground

	Locations[n].locators_radius.randitem.randitem9 = 0.001;	
	Locations[n].items.randitem9 = "hook";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;	
	Locations[n].items.randitem10 = "hook";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;	
	Locations[n].items.randitem11 = "chest3U_vco";			//on ground

	Locations[n].items.randitem12 = "boathook";

	LAi_LocationMonstersGen(&locations[n], false);

	Locations[n].island = "Redmond";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Pirate_Outer_Location_2";
	Locations[n].id = "wr_church_outside";
	locations[n].id.label = "Outside pirate church";
	Locations[n].image = "wr_church_outside.tga";
	//Sound
	locations[n].type = "Vane_jungle";

	//Models
	//Always
	Locations[n].models.always.locators = "Pirl_l_JRH_outside";	
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
	Locations[n].reload.l1.go = "wr_Cavern";
	Locations[n].reload.l1.emerge = "goto2";
	Locations[n].reload.l1.autoreload = "0";	
	Locations[n].reload.l1.label = "Cave.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_church_inside";
	Locations[n].reload.l2.emerge = "reload7";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.8;

	//exit main entrance to sand
	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "wr_church_outside";
	Locations[n].reload.l5.emerge = "goto6";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "";
	Locations[n].locators_radius.reload.reload5 = 0.5;

	//exit side entrance to sand
	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "wr_church_outside";
	Locations[n].reload.l6.emerge = "goto7";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "";
	Locations[n].locators_radius.reload.reload6 = 0.5;

	//exit sacristy to cave shore
	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "wr_cave_shore";
	Locations[n].reload.l7.emerge = "reload4";		
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "";
	Locations[n].locators_radius.reload.reload7 = 0.5;

	//exit cave shore to sacristy
	Locations[n].reload.l8.name = "reload8";
	Locations[n].reload.l8.go = "wr_sacristy";
	Locations[n].reload.l8.emerge = "reload3";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "";
	Locations[n].locators_radius.reload.reload8 = 0.5;

	//return to main entrance from distillery
	Locations[n].reload.l9.name = "reload9";
	Locations[n].reload.l9.go = "wr_church_inside";
	Locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "";
	Locations[n].locators_radius.reload.reload9 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "church_destroyed";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "gatedoor_very_small";		

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "fence";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "fence";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "fence";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "gatedoor_w7";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;		//hide backdoor
	Locations[n].items.randitem7 = "fence";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;		
	Locations[n].items.randitem8 = "rock2";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "door_A05";				//to sacristy door + window

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "window";	

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "door_A05B";

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "rum_party3";

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "rum_party2";

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
	Locations[n].items.randitem14 = "medicine_table";

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	Locations[n].items.randitem15 = "rum_party1";

	Locations[n].locators_radius.randitem.randitem16 = 0.001;
	Locations[n].items.randitem16 = "rum_party1";

	Locations[n].locators_radius.randitem.randitem17 = 0.001;
	Locations[n].items.randitem17 = "long_table";

	Locations[n].locators_radius.randitem.randitem18 = 0.001;
	Locations[n].items.randitem18 = "barrel3";

	Locations[n].locators_radius.randitem.randitem19 = 0.001;
	Locations[n].items.randitem19 = "distillery";

	Locations[n].locators_radius.randitem.randitem20 = 0.001;
	Locations[n].items.randitem20 = "barrel3";

	Locations[n].locators_radius.randitem.randitem21 = 0.001;
	Locations[n].items.randitem21 = "barrel3";

	Locations[n].locators_radius.randitem.randitem22 = 0.001;
	Locations[n].items.randitem22 = "barrel3";

	Locations[n].locators_radius.randitem.randitem23 = 0.001;
	Locations[n].items.randitem23 = "barrel3";

	Locations[n].locators_radius.randitem.randitem24 = 0.001;
	Locations[n].items.randitem24 = "barrel3";

	//-------------------------------------------------------

	Locations[n].locators_radius.randitem.randitem25 = 0.001;
	Locations[n].items.randitem25 = "barrel_roll";

	Locations[n].locators_radius.randitem.randitem26 = 0.001;
	Locations[n].items.randitem26 = "chimney_pot_night";

	Locations[n].locators_radius.randitem.randitem27 = 0.001;
	Locations[n].items.randitem27 = "brF17R";

	Locations[n].island = "Redmond";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "wr_church_attic_stairs";
	locations[n].id.label = "Entrance to church attic";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house\\";
	Locations[n].filespath.textures = "locations\inside\Doubleflour_house\church_attic";
	Locations[n].image = "wr_church_attic_stairs.tga";

	//Town sack
	//Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Vane_church";

	//Models
	//Always
	Locations[n].models.always.locators = "LH_F1_l_JRH1";
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
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_church_inside";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_church_attic";
	Locations[n].reload.l2.emerge = "goto3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].locators_radius.box.box1 = 1.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "gatedoor_pgrey";

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

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Pirate_Outer_Location_2";
	Locations[n].id = "wr_church_attic";
	locations[n].id.label = "Church attic";
	Locations[n].image = "wr_church_attic.tga";
	//Sound
	locations[n].type = "jungle_pirates";

	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "Pirl_l_JRH_attic";		
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
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "wr_church_outside";
	Locations[n].reload.l3.emerge = "goto5";		
	Locations[n].reload.l3.autoreload = "0";	
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "wr_church_attic_stairs";
	Locations[n].reload.l4.emerge = "attic";		
	Locations[n].reload.l4.autoreload = "0";	
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.5;


	Locations[n].locators_radius.box.box3 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "storehouse_destroyed";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "gatedoor_very_small";		

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "fence";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "fence";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "fence";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "hatch11";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "Cannon";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "armchair02";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "hatch11";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "hatch1";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "chair";

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "chair";

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "bladearmchair";

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
	Locations[n].items.randitem14 = "bladebarrel";

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	Locations[n].items.randitem15 = "rum_party1";

	Locations[n].locators_radius.randitem.randitem16 = 0.001;
	Locations[n].items.randitem16 = "rum_party1";

	Locations[n].locators_radius.randitem.randitem17 = 0.001;
	Locations[n].items.randitem17 = "long_table";

	Locations[n].locators_radius.randitem.randitem18 = 0.001;
	Locations[n].items.randitem18 = "barrel3";

	Locations[n].locators_radius.randitem.randitem19 = 0.001;
	Locations[n].items.randitem19 = "distillery";

	Locations[n].locators_radius.randitem.randitem20 = 0.001;
	Locations[n].items.randitem20 = "rum_party3";

	Locations[n].locators_radius.randitem.randitem21 = 0.001;
	Locations[n].items.randitem21 = "rum_party2";

	Locations[n].locators_radius.randitem.randitem22 = 0.001;
	Locations[n].items.randitem22 = "medicine_table";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\shipyard3";
	Locations[n].filespath.textures = "locations\inside\Shipyard3\sacristy";
	Locations[n].id = "wr_sacristy";
	//locations[n].id.label = "Sacristy";		//not from start
	Locations[n].image = "wr_sacristy.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Vane_church";
	
	//Models
	//Always
	Locations[n].models.always.locators = "sh03_l_JRH1";		//later sh03_l_JRH1_cloth
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
	Locations[n].models.back = "back\pcha_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_church_outside";
	Locations[n].reload.l1.emerge = "side_entre";
	Locations[n].reload.l1.label = "";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 0.5;
	locations[n].reload.l1.disable = 1;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_church_inside";
	Locations[n].reload.l2.emerge = "Reload2";
	Locations[n].reload.l2.label = "";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "wr_church_outside";
	Locations[n].reload.l4.emerge = "reload7";
	Locations[n].reload.l4.label = "";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].locators_radius.reload.reload4 = 0.5;

	Locations[n].locators_radius.box.box1 = 0.00001;		//0.5 later very small from start
	Locations[n].locators_radius.box.box2 = 0.5;			//to reload4 (to between)

	Locations[n].locators_radius.goto.goto6 = 1.0;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_A05";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "door_A05R";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "door_A05";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "door_A05";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "pack_of_red_cloth";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Church_1";

	Locations[n].id = "wr_church_inside";
	locations[n].id.label = "Pirate church";
	Locations[n].image = "wr_church_inside.tga";

	//Sound
	locations[n].type = "Vane_church";		//"tavern" later on
	//Models
	//Always
	Locations[n].models.always.locators = "church_1_locators_JRH_up";
	Locations[n].models.always.city = "Church_1";
	locations[n].models.always.l1 = "ship_up";
	locations[n].models.always.l2 = "rope_up";
	locations[n].models.always.l3 = "";
	locations[n].models.always.l4 = "collectbox";

	Locations[n].models.always.window = "Church_1_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Church_1_patch";
	//Night
	Locations[n].models.night.charactersPatch = "Church_1_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";	
	Locations[n].models.back = "back\pcha_";

	//Reload map
	//main entrance
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_church_outside";
	Locations[n].reload.l1.emerge = "main_entre";
	Locations[n].reload.l1.label = "";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 1.0;

	//to sacristy
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_sacristy";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;
	Locations[n].reload.l2.disable = 1;

	//to attic stairs
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "wr_church_attic_stairs";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	//out through broken tower
	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "wr_church_outside";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "";
	Locations[n].locators_radius.reload.reload6 = 0.5;

	//attic stairs
	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "wr_church_outside";
	Locations[n].reload.l7.emerge = "reload2";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "";
	Locations[n].locators_radius.reload.reload6 = 0.5;

	//chapel stairs
	Locations[n].reload.l8.name = "reload8";
	Locations[n].reload.l8.go = "wr_chapel_stairs";
	Locations[n].reload.l8.emerge = "reload4";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "";
	Locations[n].reload.l8.disable = 1;

	Locations[n].locators_radius.goto.goto8 = 2.0;
	Locations[n].locators_radius.goto.coins = 1.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;		//not used
	Locations[n].items.randitem1 = "steplock";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "door_N44T";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "door_N44";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "door_N44";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;		//moved under floor, right position: y = 0.8
	Locations[n].items.randitem5 = "door_N44T";
	
	Locations[n].island = "Redmond";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "wr_chapel_stairs";
	//locations[n].id.label = "Chapel stairs";			//not from start
	Locations[n].filespath.models = "locations\inside\store04";
	Locations[n].filespath.textures = "locations\inside\store04\church";
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
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "wr_church_inside";
	Locations[n].reload.l4.emerge = "reload8";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	//Locations[n].reload.l4.disable = 1;

	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "wr_chapel";
	Locations[n].reload.l7.emerge = "reload1";
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

	// -------------------------------------------------
	Locations[n].id = "wr_chapel";
	locations[n].id.label = "Chapel";
	Locations[n].image = "wr_chapel.tga";
	Locations[n].filespath.models = "locations\inside\Church_2\\";
	Locations[n].filespath.textures = "locations\inside\Church_2\chapel";
	


	//Sound
	locations[n].type = "Vane_chapel";

	//Models
	//Always
	Locations[n].models.always.city = "Church2";
	Locations[n].models.always.locators = "Church2_l_JRH";
	Locations[n].models.always.window = "church2_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Church2_p";

	//Night
	Locations[n].models.night.charactersPatch = "Church2_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_chapel_stairs";
	Locations[n].reload.l1.emerge = "goto3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_animists_stairs";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].reload.l2.disable = 1;			

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "door_N07";

	Locations[n].locators_radius.goto.goto13 = 1.0;

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "wr_animists_stairs";
//	locations[n].id.label = "Temple stairs";				//turn it on later
	Locations[n].filespath.models = "locations\inside\Doubleflour_house\\";
	Locations[n].filespath.textures = "locations\inside\Doubleflour_house\chapel";
	Locations[n].image = "wr_animists_stairs.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Vane_chapel";		
	
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F1_l_JRH2";
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
	Locations[n].reload.l2.go = "wr_chapel";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "wr_animists_stairs";
	Locations[n].reload.l3.emerge = "reload4";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "wr_animists";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.3;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_N05";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "gatedoor_Mine";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "gateroof_wood";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "door_N07";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "gatedoor_Mine";

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\ANIMISTS_Cave";
	Locations[n].filespath.textures = "locations\inside\ANIMISTS_Cave\mandala1";
	Locations[n].id = "wr_animists";
	locations[n].id.label = "Temple";
	Locations[n].image = "wr_animists.tga";
	//Sound
	locations[n].type = "Vane_temple";

	//Models
	//Always
	Locations[n].models.always.locators = "SCave_l_JRH_OFF";
	Locations[n].models.always.l1 = "SCave";
	Locations[n].models.always.l2 = "lever_base";
	Locations[n].models.always.l3 = "lever_base2";

	Locations[n].models.always.l4 = "wood_box";				//was ri7 hatch1
	Locations[n].models.always.l5 = "";				//was ri8 mine_bomb as a building item
	//Locations[n].models.always.l6 = "plank2";

	//Day
	Locations[n].models.day.charactersPatch = "SCave_p";
	//Night
	Locations[n].models.night.charactersPatch = "SCave_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_crypt";
	Locations[n].reload.l1.emerge = "goto5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	Locations[n].reload.l1.disable = 1;			//locked from start

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_animists_stairs";
	Locations[n].reload.l2.emerge = "goto4";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].locators_radius.reload.reload13 = 0.001;
	Locations[n].locators_radius.box.box1 = 0.2;
	Locations[n].locators_radius.box.box5 = 0.5;

	Locations[n].locators_radius.box.box8 = 0.5;
	Locations[n].locators_radius.box.box9 = 0.5;
	Locations[n].locators_radius.box.box10 = 0.5;
	Locations[n].locators_radius.box.box11 = 0.5;
	Locations[n].locators_radius.box.box12 = 0.5;
	Locations[n].locators_radius.box.box13 = 0.5;
	Locations[n].locators_radius.box.box14 = 0.5;
	Locations[n].locators_radius.box.box15 = 0.5;
	Locations[n].locators_radius.box.box16 = 0.5;
	Locations[n].locators_radius.box.box17 = 0.5;

	Locations[n].locators_radius.goto.goto36 = 1.5;
	Locations[n].locators_radius.goto.goto41 = 1.5;
	Locations[n].locators_radius.goto.crypt_closed = 0.7;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "door_N05";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "steplock2";				//throne was steplock3

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "lever_up";
	
	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "lever_down";

	Locations[n].locators_radius.randitem.randitem5 = 0.1;
	Locations[n].items.randitem5 = "gatedoor_wN";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "steplock";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "";				//was hatch1 (wooden box)

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "";				//was mine_bomb

	Locations[n].locators_radius.randitem.randitem9 = 1.0;
	Locations[n].items.randitem9 = "bladeaxe5";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;   
	Locations[n].items.randitem10 = "bladedefense";		

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Dungeon_1";
	Locations[n].filespath.textures = "locations\inside\Dungeon_1\crypt";
	Locations[n].id = "wr_crypt";
//	locations[n].id.label = "Port Royal catacombs";		//later
	Locations[n].image = "wr_crypt.tga";
	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "crypt";			

	//Models
	//Always
	Locations[n].models.always.locators = "d01_l_JRH1";		//JRH2 (mummies later)
	Locations[n].models.always.house = "d01";
	//Day
	Locations[n].models.day.charactersPatch = "d01_p";
	//Night
	Locations[n].models.night.charactersPatch = "d01_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "wr_animists";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Redmond_church";
	Locations[n].reload.l4.emerge = "reload3";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 1.5;

	Locations[n].locators_radius.goto.goto8 = 1.0;
	Locations[n].locators_radius.goto.goto11 = 2.3;
	Locations[n].locators_radius.goto.goto14 = 1.0;
	Locations[n].locators_radius.goto.goto15 = 2.0;
	Locations[n].locators_radius.goto.goto17 = 0.7;
	Locations[n].locators_radius.goto.goto18 = 1.5;
	Locations[n].locators_radius.goto.goto19 = 2.0;

	Locations[n].locators_radius.reload.reloadc3 = 0.001;
	Locations[n].locators_radius.randitem.randitem1 = 0.001;	

	Locations[n].locators_radius.randitem.randitem4 = 0.1;		//door
	Locations[n].items.randitem4 = "gatedoor_CR2";

	Locations[n].locators_radius.randitem.randitem5 = 0.1;
	Locations[n].items.randitem5 = "gatedoor_wN";

	Locations[n].locators_radius.randitem.randitem6 = 0.1;		//upper no door
	Locations[n].items.randitem6 = "gatedoor_GC2";

	Locations[n].locators_radius.randitem.randitem7 = 0.1;
	Locations[n].items.randitem7 = "gatedoor_w";

	Locations[n].locators_radius.randitem.randitem13 = 0.1;
	Locations[n].items.randitem13 = "gatedoor_wN";

	Locations[n].locators_radius.randitem.randitem14 = 0.1;
	Locations[n].items.randitem14 = "gatedoor_wR";

	LAi_LocationFantomsGen(&locations[n], false);

	Locations[n].island = "Redmond";
	n = n + 1;
//----------------------------------------------------------------------------------------------

	locations[n].id = "wr_wine_cellar";
	locations[n].image = "loading\inside\dungeon.tga";
	//locations[n].id.label = "Roger's wine cellar";
	locations[n].id.label = "";
	Locations[n].image = "wr_wine_cellar.tga";
	//Sound
	Locations[n].townsack = "Redmond";
	locations[n].type = "Rogers_cellar";		//was dungeon

	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Cellar_downstairs";
	locations[n].models.always.Cellar_downstairs = "Cellar_downstairs";
	locations[n].models.always.Cellar_downstairsStuff = "Cellar_downstairs_stuff";
	locations[n].models.always.rays = "Cellar_downstairs_rays";
	locations[n].models.always.l1 = "steplock_v";
	locations[n].models.always.l2 = "lever1_up";		//means 'open' = flood
	locations[n].models.always.locators = "Cellar_downstairs_locators_JRH_flood1";
	//Day
	locations[n].models.day.charactersPatch = "Cellar_downstairs_patch";
	//Night
	locations[n].models.night.charactersPatch = "Cellar_downstairs_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";		
 	//Reload map

	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "wr_food_supply";
	locations[n].reload.l1.emerge = "reload5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1_back = 1.0;

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "church_wine_cellar";
	locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload2 = 6.0;

	Locations[n].locators_radius.reload.reload3 = 0.7;		//backoff locators
	Locations[n].locators_radius.reload.reload4 = 0.8;

	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box2 = 0.5;

	LAi_LocationFantomsGen(&locations[n], false);

	Locations[n].island = "Redmond";
	n = n + 1;

	//  -------------------------------------------------

	locations[n].id = "church_wine_cellar";
	//locations[n].id.label = "Church wine cellar";
	locations[n].id.label = "";
	Locations[n].image = "church_wine_cellar.tga";
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

	locations[n].models.always.locators = "cwc_flood_down";			
	
	//Day
	locations[n].models.day.charactersPatch = "DungeonVault1_patch";
	//Night
	locations[n].models.night.charactersPatch = "DungeonVault1_patch";
	//Environment
	locations[n].environment.weather = "true";		//true is always ok
	locations[n].environment.sea = "false";			//only change is to FALSE

	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "church_choir";		
	locations[n].reload.l1.emerge = "reload1_back";		
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.disable = 1;			//opened later on

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "wr_wine_cellar";
	locations[n].reload.l2.emerge = "goto6";
	locations[n].reload.l2.autoreload = "1";
	locations[n].locators_radius.reload.reload2_back = 1.5;

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
	Locations[n].items.randitem1 = "steplock2";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "steplock2";

	Locations[n].island = "Redmond";
	n = n + 1;

//  -------------------------------------------------

	locations[n].id = "church_choir";
	//locations[n].id.label = "Port Royal Church Choir";
	locations[n].id.label = "";
	Locations[n].image = "church_choir.tga";
	//Town sack
	locations[n].townsack = "Redmond";
	//Sound
	locations[n].type = "choir";
	
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Bank";
	Locations[n].filespath.textures = "locations\inside\choir";
	Locations[n].models.always.house = "Bank";		
	locations[n].models.always.locators = "Bank_locators_JRH1";	//JRH1 = start
	Locations[n].models.always.window = "choir_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	locations[n].models.day.charactersPatch = "Bank_patch";
	//Night
	locations[n].models.night.charactersPatch = "Bank_patch";
	//Environment
	locations[n].environment.weather = "false";
	locations[n].environment.sea = "false";

	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Redmond_church";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].locators_radius.reload.reload1 = 0.7;

	locations[n].reload.l4.name = "reload1_back";
	locations[n].reload.l4.go = "church_wine_cellar";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "0";
	locations[n].locators_radius.reload.reload1_back = 0.7;
	
	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.box.box6 = 0.5;
	Locations[n].locators_radius.box.box7 = 0.5;
	Locations[n].locators_radius.box.box8 = 0.5;
	Locations[n].locators_radius.box.box9 = 0.5;
	Locations[n].locators_radius.box.box10 = 1.5;
	Locations[n].locators_radius.box.box11 = 0.5;
	Locations[n].locators_radius.box.box12 = 0.5;
	Locations[n].locators_radius.box.box13 = 0.5;
	Locations[n].locators_radius.box.box14 = 0.5;
	Locations[n].locators_radius.box.box15 = 0.5;
	Locations[n].locators_radius.box.box16 = 0.5;
	Locations[n].locators_radius.box.box17 = 0.5;
	Locations[n].locators_radius.box.box18 = 0.4;
	Locations[n].locators_radius.box.box19 = 0.4;
	
	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "ladder_medium";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "clockkey";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "handle";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "stuckkey";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "cello";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "violin";

	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "violin";

	Locations[n].locators_radius.randitem.randitem8 = 0.01;
	Locations[n].items.randitem8 = "flute";

	Locations[n].locators_radius.randitem.randitem9 = 0.01;
	Locations[n].items.randitem9 = "sheet_music";

	Locations[n].locators_radius.randitem.randitem10 = 0.01;
	Locations[n].items.randitem10 = "sheet_music";

	Locations[n].locators_radius.randitem.randitem11 = 0.01;
	Locations[n].items.randitem11 = "sheet_music";

	Locations[n].locators_radius.randitem.randitem12 = 0.5;
	Locations[n].items.randitem12 = "lockpick_JRH";

	Locations[n].locators_radius.randitem.randitem13 = 0.01;
	Locations[n].items.randitem13 = "pillow";

	Locations[n].locators_radius.randitem.randitem14 = 0.01;
	Locations[n].items.randitem14 = "violin";

	Locations[n].locators_radius.randitem.randitem15 = 0.01;
	Locations[n].items.randitem15 = "lockpick_JRH";

	Locations[n].locators_radius.randitem.randitem16 = 0.01;
	Locations[n].items.randitem16 = "PiratesDagger";

	LAi_LocationFightDisable(&Locations[n], true);	

	Locations[n].island = "Redmond";
	n = n + 1;

//------------------------------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Dungeon_1_wood";
	Locations[n].id = "shipyard_stairs";
//	locations[n].id.label = "Shipyard stairs";		//open = on
	Locations[n].image = "shipyard_stairs.tga";
	//Locations[n].monsters = "1";
	
	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "shop";

	//Models
	//Always
	Locations[n].models.always.locators = "d01_l_JRH";
	Locations[n].models.always.house = "d01";
	//Day
	Locations[n].models.day.charactersPatch = "d01_p";
	//Night
	Locations[n].models.night.charactersPatch = "d01_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//LAi_LocationFantomsGen(&locations[n], true);

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Redmond_Shipyard";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Redmond shipyard.";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Shipyard_shore";
	Locations[n].reload.l3.emerge = "Falaise_de_fleur_location_01_05";
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

	//  -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Dungeon_1_wood";
	Locations[n].id = "storeroom_attic";
//	locations[n].id.label = "Storeroom attic";		//open = on
	Locations[n].image = "storeroom_attic.tga";
	
	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_residence";

	//Models
	//Always
	Locations[n].models.always.locators = "d01_l_JRH";
	Locations[n].models.always.house = "d01";
	//Day
	Locations[n].models.day.charactersPatch = "d01_p";
	//Night
	Locations[n].models.night.charactersPatch = "d01_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "wr_library";
	Locations[n].reload.l4.emerge = "reload3";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].locators_radius.reload.reload4 = 1.2;

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "Charles_Windem_room";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].locators_radius.reload.reload5 = 1.2;

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "gatedoor_w5";

	Locations[n].locators_radius.randitem.randitem5 = 0.1;
	Locations[n].items.randitem5 = "gatedoor_wN";

	Locations[n].locators_radius.randitem.randitem6 = 0.1;
	Locations[n].items.randitem6 = "gatedoor_w";

	Locations[n].locators_radius.randitem.randitem7 = 0.1;
	Locations[n].items.randitem7 = "gatedoor_w";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "steplock";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "steplock";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "steplock";
	
	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "steplock";

	Locations[n].locators_radius.goto.goto4 = 1.2;

	LAi_LocationFantomsGen(&locations[n], false);
	LAi_LocationMonstersGen(&locations[n], false);

	Locations[n].island = "Redmond";
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].id = "Shipyard_shore";
	locations[n].id.label = "Shipyard shore";
//	locations[n].worldmap = "Redmond";
	Locations[n].image = "Shipyard_shore.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "blues_port";			

	//Models
	//Always
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\port2";
	Locations[n].models.always.city = "FFport02";
	Locations[n].models.always.city.foam = "1";
	Locations[n].models.always.seabed = "FFport02_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.locators = "FFport02_l_JRH_out";
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

	//shipyard door
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "shipyard_docks";
	Locations[n].reload.l1.emerge = "dock2";			
	Locations[n].reload.l1.autoreload = "0";
	
	//shipyard door
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "shipyard_docks";
	Locations[n].reload.l2.emerge = "dock2";			
	Locations[n].reload.l2.autoreload = "0";

	//back off locators
	Locations[n].locators_radius.reload.reload7 = 2.0;
	Locations[n].locators_radius.reload.reload8 = 2.0;
	Locations[n].locators_radius.reload.reload9 = 2.0;
	Locations[n].locators_radius.reload.reload10 = 2.0;
	Locations[n].locators_radius.reload.reload11 = 2.0;
	Locations[n].locators_radius.reload.reload12 = 1.3;
	Locations[n].locators_radius.reload.reload13 = 0.5;
	Locations[n].locators_radius.reload.reload16 = 1.2;
	Locations[n].locators_radius.reload.reload18 = 1.3;
	Locations[n].locators_radius.reload.reload21 = 1.5;
	Locations[n].locators_radius.reload.reload22 = 2.0;
	Locations[n].locators_radius.reload.reload23 = 2.0;
	Locations[n].locators_radius.reload.reload24 = 2.0;
	Locations[n].locators_radius.reload.reload26 = 2.5;
	Locations[n].locators_radius.reload.reload27 = 0.5;

	//shipyard stairs
	Locations[n].reload.l30.name = "Falaise_de_fleur_location_01_05";
	Locations[n].reload.l30.go = "shipyard_stairs";
	Locations[n].reload.l30.emerge = "goto1";
	Locations[n].reload.l30.autoreload = "0";
	Locations[n].reload.l30.label = "Shipyard.";

	//prison ships
	Locations[n].reload.l31.name = "locationext";
	Locations[n].reload.l31.go = "Redmond_shore_ship";
	Locations[n].reload.l31.emerge = "reload1";
	Locations[n].reload.l31.autoreload = "1";
	Locations[n].reload.l31.label = "Sea port.";

	Locations[n].reload.l32.name = "locationext_back";
	Locations[n].reload.l32.go = "Redmond_shore_ship";
	Locations[n].reload.l32.emerge = "reload1";
	Locations[n].reload.l32.autoreload = "1";
	Locations[n].reload.l32.label = "Sea port.";
	Locations[n].locators_radius.reload.locationext_back = 2.5;

	Locations[n].reload.l41.name = "window1";
	Locations[n].reload.l41.go = "stonehouse_inside";
	Locations[n].reload.l41.emerge = "reload1";
	Locations[n].reload.l41.autoreload = "1";
	Locations[n].reload.l41.label = "";

	Locations[n].reload.l42.name = "window2";
	Locations[n].reload.l42.go = "stonehouse_inside";
	Locations[n].reload.l42.emerge = "reload2";
	Locations[n].reload.l42.autoreload = "1";
	Locations[n].reload.l42.label = "";

	Locations[n].reload.l43.name = "window3";
	Locations[n].reload.l43.go = "stonehouse_inside";
	Locations[n].reload.l43.emerge = "reload3";
	Locations[n].reload.l43.autoreload = "1";
	Locations[n].reload.l43.label = "";

	Locations[n].locators_radius.goto.claire = 3.0;			

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "shipyard1";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "shipwreck";
	
	Locations[n].locators_radius.randitem.randitem3 = 0.001;
//	Locations[n].items.randitem3 = "hut2";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "workshop";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "smg11";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "stoneH1";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
//	Locations[n].items.randitem7 = "stoneH1";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "ffport02_planks";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "ffport02_planks";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "xebec_wreck";

	LAi_LocationFantomsGen(&locations[n], false);
	Locations[n].vcskip = true; // PB
	Locations[n].monsters = 0; // KK

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].id = "Shipyard_docks";
	locations[n].id.label = "Docks";
	Locations[n].image = "Shipyard_docks.tga";
	
	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "blues_port";

	//Models
	//Always
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\port2";
	Locations[n].models.always.city = "FFport02";
	Locations[n].models.always.city.foam = "1";
	Locations[n].models.always.seabed = "FFport02_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.locators = "FFport02_l_JRH_in";
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
	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "Defoes_cabin";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "shipyard1";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "shipwreck";
	
	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "door_shya";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "door_shya";

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;
	//  -------------------------------------------------

	Locations[n].id = "Defoes_cabin";
	locations[n].id.label = "De Foe's Home";
	Locations[n].image = "Defoes_cabin.tga";

	//Town sack
	Locations[n].townsack = "Redmond";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "Defoe_cabin";

	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\ShipyardPirates";
    	Locations[n].models.always.l1 = "ShipyardPirates";
    	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.seabed = "ShipyardPirates";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.locators = "ShipyardPirates_locators_JRH";
	//Locations[n].models.always.grassPatch = "FFport02_g";

	//Day
	Locations[n].models.day.fonar = "ShipyardPirates_fn";
	Locations[n].models.day.charactersPatch = "ShipyardPirates_patch";
	//Night
	Locations[n].models.night.fonar = "ShipyardPirates_fn";
	Locations[n].models.night.charactersPatch = "ShipyardPirates_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	//Reload map

	//main entrance
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "shipyard_docks";
	Locations[n].reload.l1.emerge = "reload5";
	Locations[n].reload.l1.autoreload = "0";

	//side door
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "shipyard_shore";
	Locations[n].reload.l2.emerge = "goto9";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].locators_radius.goto.goto1 = 2.0;

	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.box.box6 = 0.5;

	Locations[n].rats = "true";
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;
	
	//  -------------------------------------------------

	locations[n].id = "stonehouse_inside";
	locations[n].id.label = "Port Royal Military Head Quarter";
	Locations[n].image = "stonehouse_inside.tga";

	//Sound
	locations[n].type = "military";

	//Models
	//Always
	locations[n].filespath.models = "locations\inside\ResidenceSmall2";
	locations[n].models.always.locators = "SmallResidence_locators_JRH";
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
	locations[n].reload.l1.go = "Shipyard_shore";
	locations[n].reload.l1.emerge = "window1_exit"; 
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Shipyard_shore";
	locations[n].reload.l2.emerge = "window2_exit"; 
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "";

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "Shipyard_shore";
	locations[n].reload.l3.emerge = "window3_exit"; 
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "";

	locations[n].reload.l4.name = "reload4";
	locations[n].reload.l4.go = "fake_fort_JRH";
	locations[n].reload.l4.emerge = "reload1"; 
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Port Royale Fort";
	Locations[n].reload.l4.disable = 1;			//never opened just for the label

	Locations[n].items.randitem1 = "chest5_coas";
	Locations[n].locators_radius.randitem.randitem1 = 0.001;

	n = n + 1;

	//  -------------------------------------------------

	locations[n].id = "fake_fort_JRH";
	locations[n].id.label = "Port Royale Fort";
	Locations[n].image = "stonehouse_inside.tga";

	//Sound
	locations[n].type = "military";

	//Models
	//Always
	locations[n].filespath.models = "locations\inside\ResidenceSmall2";
	locations[n].models.always.locators = "SmallResidence_locators_JRH";
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

	n = n + 1;

	//  -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Shore_ship";

	Locations[n].id = "Redmond_shore_ship";
	locations[n].id.label = "Prison ships";
	Locations[n].image = "Redmond_shore_ship.tga";
	Locations[n].name = "Ship";
	//Sound
	locations[n].type = "prison_ships";

	//Models
	//Always
	Locations[n].models.always.jungle = "ShoreShip";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.locators = "ShoreShip_l_JRH";
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
	Locations[n].reload.l1.go = "Shipyard_shore";
	Locations[n].reload.l1.emerge = "locationext";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Redmond shore.";
	Locations[n].locators_radius.reload.reload2 = 1;

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Shipyard_shore";
	Locations[n].reload.l2.emerge = "locationext";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Redmond shore.";
	Locations[n].locators_radius.reload.reload2_back = 3;

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Redmond_shore_03";
	Locations[n].reload.l3.emerge = "goto9";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Boat shore.";
	Locations[n].locators_radius.reload.reload2 = 3;

   	Locations[n].items.randitem1 = "smg3";
	Locations[n].locators_radius.randitem.randitem1 = 0.001;

	Locations[n].items.randitem2 = "chest1";
	Locations[n].locators_radius.randitem.randitem2 = 0.001;

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "smg1_A";

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;
	
	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Shore_10";

	Locations[n].id = "Redmond_shore_03";
	locations[n].id.label = "Boat shore";
	Locations[n].image = "Redmond_shore_03.tga";

	//Sound
	locations[n].type = "indian_seashore";

	//Models
	//Always
	Locations[n].models.always.jungle = "shore10";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.locators = "shore10_l_JRH";
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
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_port";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Redmond shore.";
	Locations[n].locators_radius.reload.reload2 = 3;

	Locations[n].reload.l22.name = "reload2_back";
	Locations[n].reload.l22.go = "wr_port";
	Locations[n].reload.l22.emerge = "reload3";
	Locations[n].reload.l22.autoreload = "1";
	Locations[n].reload.l22.label = "Redmond shore.";
	Locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Redmond_shore_ship";
	Locations[n].reload.l1.emerge = "monster1";		
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Redmond shore.";

	Locations[n].locators_radius.reload.reload3 = 2.5;

	Locations[n].items.randitem1 = "smg3";
	Locations[n].locators_radius.randitem.randitem1 = 0.001;

	Locations[n].items.randitem2 = "smg7";
	Locations[n].locators_radius.randitem.randitem2 = 0.001;

	Locations[n].items.randitem3 = "textileB";
	Locations[n].locators_radius.randitem.randitem3 = 0.001;

	Locations[n].items.randitem4 = "textileB";
	Locations[n].locators_radius.randitem.randitem4 = 0.001;

	LAi_LocationMonstersGen(&locations[n], false);

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_QC\port";	
	Locations[n].image = "wr_port.tga";

	Locations[n].id = "wr_port";
	locations[n].id.label = "Woodes Rogers' port";
	locations[n].worldmap = "RShore 1";		//instead of Devil's throat

	//Sound
	locations[n].type = "indian_seashore";

	//Models
	//Always
	Locations[n].models.always.locators = "QCport_l_JRH";
	Locations[n].models.always.l1 = "QCport";
	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.sb = "QCport_sb";
	Locations[n].models.always.sb.foam = "1";
	Locations[n].models.always.grassPatch = "QCport_g";
	Locations[n].models.always.l2 = "plan_1";
	Locations[n].models.always.l2.level = 9;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan_2";
	Locations[n].models.always.l3.level = 8;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	Locations[n].models.always.l4 = "plan_3";
	Locations[n].models.always.l4.level = 7;
	Locations[n].models.always.l4.tech = "LocationModelBlend";
	Locations[n].models.always.l5 = "Window";
	Locations[n].models.always.l6 = "BlackWindow";

	//Day
	Locations[n].models.day.charactersPatch = "QCport_wrp";		//orig QCport_p
	Locations[n].models.day.jumpPatch = "QCport_j";
	//Night
	Locations[n].models.night.charactersPatch = "QCport_wrp";	//orig QCport_p
	Locations[n].models.night.jumpPatch = "QCport_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	//Reload map

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_ships";
	Locations[n].reload.l1.emerge = "reload1";			
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	Locations[n].locators_radius.reload.reload1 = 0.00001;			//1.5 later

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Redmond_shore_03";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Boat shore.";
	Locations[n].locators_radius.reload.reload3 = 1.0;

	Locations[n].reload.l33.name = "reload3_back";
	Locations[n].reload.l33.go = "Redmond_shore_03";
	Locations[n].reload.l33.emerge = "reload2";
	Locations[n].reload.l33.autoreload = "1";
	Locations[n].reload.l33.label = "Boat shore.";
	Locations[n].locators_radius.reload.reload3_back = 1.0;

	//farmhouse
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_farm_kitchen";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 1.0;

	//sea
	Locations[n].reload.l4.name = "sea";
	Locations[n].reload.l4.go = "Redmond";
	Locations[n].reload.l4.emerge = "reload_1";
	Locations[n].reload.l4.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l4.label = "Ship.";
	else
		Locations[n].reload.l4.label = "Sea.";
	Locations[n].locators_radius.reload.sea = 3.0;

	//back off locators
	Locations[n].locators_radius.reload.reload7 = 0.5;
	Locations[n].locators_radius.reload.reload8 = 0.5;
	Locations[n].locators_radius.reload.reload9 = 1.0;
	Locations[n].locators_radius.reload.reload10 = 0.5;
	Locations[n].locators_radius.reload.boat = 0.3;

	Locations[n].locators_radius.goto.R5 = 2.0;		
	Locations[n].locators_radius.goto.goto11 = 1.5;
	Locations[n].locators_radius.goto.goto13 = 2.5;
	Locations[n].locators_radius.goto.goto15 = 1.7;
	Locations[n].locators_radius.goto.pchar_splash = 2.0;
	Locations[n].locators_radius.goto.pchar_swim = 5.0;
	Locations[n].locators_radius.goto.sloop = 1.5;		

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "Boat2_B";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "fence";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "fence";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "hut3";			//hut3 = the farm

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "hut3";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "hut3_C";

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "wr_ships";
	locations[n].id.label = "Prize ships";
	//Info
	Locations[n].filespath.models = "locations\decks\udeck_open";
	Locations[n].image = "wr_ships.tga";
	//Sound
	
	locations[n].type = "Rogers_ships";

	Locations[n].lockCamAngle = 0.4;

	//Models
	//Always
//	Locations[n].models.always.locators = "udeck_l_JRH_E1";		//start E: cannon points at east = sea
	Locations[n].models.always.locators = "udeck_l_JRH_E1_start";	//dito but temp action at anchor mechanism

	Locations[n].models.always.l1 = "udeck";
	Locations[n].models.always.l2 = "deck_box";
	Locations[n].models.always.l3 = "goods_pile";
	Locations[n].models.always.l4 = "cannon_E1";		//1 box (start), 2 air, 3 high air, 0 deck (later)
	Locations[n].models.always.l5 = "anchor1";		//1 deck, 0 water
	Locations[n].models.always.l6 = "elevator&ropes_C1";	//C1 deck, C2 air
//	Locations[n].models.always.l7 = "elevator&ropes_G2";	//elevatorG0 hold, G1 deck, G2 air, ropes0 hold, ropes2 air
//	Locations[n].models.always.l8 = "irontool";		//irontool only when G2
//	Locations[n].models.always.l9 = "plank1";		//plank 1 deck, 2 air
//	Locations[n].models.always.l10 = "pinion_large_L";	//"" start  10 = left pos
//	Locations[n].models.always.l11 = "pinion_small_R";	//"" start  11 = right pos
	Locations[n].models.always.l12 = "hubs";
//	Locations[n].models.always.l13 = "wheel_R";		//"" start
//	Locations[n].models.always.l14 = "";			//ropesA anchor 
	Locations[n].models.always.l15 = "pinion_large_H";	//
//	Locations[n].models.always.l16 = "Flotsam12";		//not from start
	Locations[n].models.always.l17 = "steering_wheel";
	Locations[n].models.always.l18 = "door_N12";		//door_broken later

//	Locations[n].models.always.l20 = "elevator&ropes_G0";	//temp post: only via code in q_r etc

	//Day
	Locations[n].models.day.charactersPatch = "udeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "udeck_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "wr_port";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "";

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "wr_corv_capmd";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "";
	Locations[n].reload.l5.disable = 1;

	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "wr_corv_crew";
	Locations[n].reload.l6.emerge = "goto13";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "";
	Locations[n].locators_radius.reload.reload6 = 0.001;	//not visible from start
	Locations[n].reload.l6.disable = 1;

	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "wr_corv_deck1";
	Locations[n].reload.l7.emerge = "reload5";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "";
	Locations[n].locators_radius.reload.reload7 = 0.001;	//not visible from start

	Locations[n].reload.l8.name = "reload8";
	Locations[n].reload.l8.go = "wr_gall_deck2_stern";
	Locations[n].reload.l8.emerge = "reload3";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "";
	Locations[n].reload.l8.disable = 1;			//blocked from inside

	Locations[n].reload.l9.name = "reload9";
	Locations[n].reload.l9.go = "wr_gall_deck2_stern";
	Locations[n].reload.l9.emerge = "reload2";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "";
	Locations[n].reload.l9.disable = 1;			//blocked from inside

	Locations[n].reload.l10.name = "reload10";
	Locations[n].reload.l10.go = "wr_gall_deck2_prow";
	Locations[n].reload.l10.emerge = "reload3";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "";
	Locations[n].reload.l10.disable = 1;			//blocked from inside

	Locations[n].reload.l11.name = "reload11";
	Locations[n].reload.l11.go = "wr_gall_deck2_prow";
	Locations[n].reload.l11.emerge = "reload2";
	Locations[n].reload.l11.autoreload = "0";
	Locations[n].reload.l11.label = "";
	Locations[n].reload.l11.disable = 1;			//blocked from inside

	Locations[n].reload.l12.name = "reload12";
	Locations[n].reload.l12.go = "wr_gall_hold_first";
	Locations[n].reload.l12.emerge = "fall";
	Locations[n].reload.l12.autoreload = "1";
	Locations[n].reload.l12.label = "";
	//Locations[n].locators_radius.reload.reload12 = 0.0001;

	Locations[n].reload.l13.name = "reload13";
	Locations[n].reload.l13.go = "wr_ships";
	Locations[n].reload.l13.emerge = "steering";		
	Locations[n].reload.l13.autoreload = "0";
	Locations[n].reload.l13.label = "";

	Locations[n].reload.l14.name = "reload14";
	Locations[n].reload.l14.go = "wr_gall_cap_outer";
	Locations[n].reload.l14.emerge = "reload4";
	Locations[n].reload.l14.autoreload = "0";
	Locations[n].reload.l14.label = "";

	Locations[n].reload.l17.name = "reload17";
	Locations[n].reload.l17.go = "wr_gall_deck2_prow";
	Locations[n].reload.l17.emerge = "reload5";
	Locations[n].reload.l17.autoreload = "0";
	Locations[n].reload.l17.label = "";
	Locations[n].reload.l17.disable = 1;			//open after final battle

	Locations[n].locators_radius.rld.captain = 2.0;
	Locations[n].locators_radius.box.box1 = 0.001;		//not visible from start
	Locations[n].locators_radius.box.box2 = 0.001;		//not visible from start
	Locations[n].locators_radius.box.box3 = 0.5;		//bell
	Locations[n].locators_radius.box.box4 = 0.8;		//crew hatch backoff
	Locations[n].locators_radius.box.box5 = 0.7;		//cannon up
	Locations[n].locators_radius.box.box6 = 0.0001;		//cannon down - box not visible from start
	Locations[n].locators_radius.box.box7 = 0.7;		//cannon high up
	Locations[n].locators_radius.box.box8 = 0.5;		//anchor down
	Locations[n].locators_radius.box.box9 = 0.5;		//anchor down up
	Locations[n].locators_radius.box.box10 = 0.0001;	//place ropes in the air
	Locations[n].locators_radius.box.box11 = 0.0001;	//place planks over hole
	Locations[n].locators_radius.box.box12 = 0.0001;	//pick up pinion_large_H
	Locations[n].locators_radius.box.box14 = 0.3;		//place anchor
	Locations[n].locators_radius.box.box15 = 0.0001;	//climb to place anchor later
	Locations[n].locators_radius.box.box16 = 0.5;		//jump to corvette
	Locations[n].locators_radius.box.box17 = 0.5;		//jump to corvette
	Locations[n].locators_radius.box.box23 = 0.5;		//(anchor down) stringlog
	Locations[n].locators_radius.box.box24 = 0.5;		//stringlog

	Locations[n].locators_radius.goto.backoff1 = 0.05;
	Locations[n].locators_radius.goto.backoff2 = 0.05;
	Locations[n].locators_radius.goto.backoff3 = 0.05;
	Locations[n].locators_radius.goto.backoff4 = 0.05;
	Locations[n].locators_radius.goto.backoff5 = 0.05;
	Locations[n].locators_radius.goto.backoff6 = 0.05;
	Locations[n].locators_radius.goto.backoff7 = 0.05;
	Locations[n].locators_radius.goto.backoff8 = 0.05;
	Locations[n].locators_radius.goto.sidestep5 = 0.05;
	Locations[n].locators_radius.goto.sidestep6 = 0.05;
	Locations[n].locators_radius.goto.sidestep7 = 0.05;
	Locations[n].locators_radius.goto.sidestep8 = 0.05;
	Locations[n].locators_radius.goto.passage5 = 0.05;
	Locations[n].locators_radius.goto.passage6 = 0.05;
	Locations[n].locators_radius.goto.passage7 = 0.05;
	Locations[n].locators_radius.goto.passage8 = 0.05;
	Locations[n].locators_radius.goto.fire = 0.05;
	Locations[n].locators_radius.goto.turnW = 0.1;
	Locations[n].locators_radius.goto.turnN = 0.1;
	Locations[n].locators_radius.goto.turnE = 0.1;
	Locations[n].locators_radius.goto.turnS = 0.1;
	Locations[n].locators_radius.goto.see_tool = 3.0;	

	Locations[n].locators_radius.randitem.randitem1 = 0.001;	
	Locations[n].items.randitem1 = "hatch12";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.001;	//locator bigger later on	
	Locations[n].items.randitem2 = "elevator_ropes";		//the visible ropes one are not these!!!
									//these are fake pick ups

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "qcport";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "qcport_plan3";

	Locations[n].rats = "true";
	LAi_LocationFightDisable(&Locations[n], true);
	n = n + 1;
// -------------------------------------------------
	//this one is used when galleon is sunken
	Locations[n].id = "wr_corvette";
	locations[n].id.label = "Prize ship";
	//Info
	Locations[n].filespath.models = "locations\decks\qdeck_open";
	Locations[n].image = "wr_corvette.tga";
	//Sound
	locations[n].type = "silent_seashore";		

	Locations[n].lockCamAngle = 0.4;

	//Models
	//Always
	Locations[n].models.always.locators = "qdeck_l_JRH";		

	Locations[n].models.always.l1 = "qdeck";

	Locations[n].models.always.l2 = "";
	Locations[n].models.always.l3 = "";
	Locations[n].models.always.l4 = "cannon_pipe";	
//	Locations[n].models.always.l5 = "";			//by code in q_r
//	Locations[n].models.always.l6 = "";			//by code in q_r
	Locations[n].models.always.l7 = "";	
	Locations[n].models.always.l8 = "";		
	Locations[n].models.always.l9 = "";
	Locations[n].models.always.l10 = "pinion_small_L";	
	Locations[n].models.always.l11 = "pinion_large_R";	
	Locations[n].models.always.l12 = "hubs";
	Locations[n].models.always.l13 = "wheel_R";		
	Locations[n].models.always.l14 = "";			
	Locations[n].models.always.l15 = "";	
	Locations[n].models.always.l16 = "";		
	Locations[n].models.always.l17 = "";
	Locations[n].models.always.l18 = "door_broken";		
	Locations[n].models.always.l20 = "";

	//Day
	Locations[n].models.day.charactersPatch = "qdeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "qdeck_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_corvette";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	Locations[n].locators_radius.reload.reload1 = 0.5;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_corvette";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "wr_port";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "";

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "wr_corv_capmd";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "";

	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "wr_corv_crew";
	Locations[n].reload.l6.emerge = "reload4";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "";
	Locations[n].locators_radius.reload.reload6 = 1.0;	
	Locations[n].reload.l6.disable = 1;

	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "wr_corv_deck1";
	Locations[n].reload.l7.emerge = "reload5";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "";

	Locations[n].reload.l8.name = "reload8";
	Locations[n].reload.l8.go = "wr_gall_deck2_stern";
	Locations[n].reload.l8.emerge = "reload3";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "";
	Locations[n].reload.l8.disable = 1;			//blocked from inside

	Locations[n].reload.l9.name = "reload9";
	Locations[n].reload.l9.go = "wr_gall_deck2_stern";
	Locations[n].reload.l9.emerge = "reload2";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "";
	Locations[n].reload.l9.disable = 1;			//blocked from inside

	Locations[n].reload.l10.name = "reload10";
	Locations[n].reload.l10.go = "wr_gall_deck2_prow";
	Locations[n].reload.l10.emerge = "reload3";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "";
	Locations[n].reload.l10.disable = 1;			//blocked from inside

	Locations[n].reload.l11.name = "reload11";
	Locations[n].reload.l11.go = "wr_gall_deck2_prow";
	Locations[n].reload.l11.emerge = "reload2";
	Locations[n].reload.l11.autoreload = "0";
	Locations[n].reload.l11.label = "";
	Locations[n].reload.l11.disable = 1;			//blocked from inside

	Locations[n].reload.l12.name = "reload12";
	Locations[n].reload.l12.go = "wr_gall_hold_first";
	Locations[n].reload.l12.emerge = "fall";
	Locations[n].reload.l12.autoreload = "1";
	Locations[n].reload.l12.label = "";

	Locations[n].reload.l13.name = "reload13";
	Locations[n].reload.l13.go = "wr_ships";
	Locations[n].reload.l13.emerge = "steering";		
	Locations[n].reload.l13.autoreload = "0";
	Locations[n].reload.l13.label = "";

	Locations[n].reload.l14.name = "reload14";
	Locations[n].reload.l14.go = "wr_gall_cap_outer";
	Locations[n].reload.l14.emerge = "reload4";
	Locations[n].reload.l14.autoreload = "0";
	Locations[n].reload.l14.label = "";

	Locations[n].reload.l15.name = "reload15";
	Locations[n].reload.l15.go = "wr_ships";
	Locations[n].reload.l15.emerge = "reload16";
	Locations[n].reload.l15.autoreload = "0";
	Locations[n].reload.l15.label = "";
	Locations[n].locators_radius.reload.reload15 = 1.0;

	Locations[n].reload.l16.name = "reload16";
	Locations[n].reload.l16.go = "wr_ships";
	Locations[n].reload.l16.emerge = "reload15";
	Locations[n].reload.l16.autoreload = "0";
	Locations[n].reload.l16.label = "";
	Locations[n].locators_radius.reload.reload16 = 0.5;

	Locations[n].reload.l17.name = "reload17";
	Locations[n].reload.l17.go = "wr_gall_deck2_prow";
	Locations[n].reload.l17.emerge = "reload5";
	Locations[n].reload.l17.autoreload = "0";
	Locations[n].reload.l17.label = "";
	Locations[n].reload.l17.disable = 1;			//open after final battle

	Locations[n].locators_radius.rld.captain = 0.001;
	Locations[n].locators_radius.box.box1 = 0.001;		//not visible from start
	Locations[n].locators_radius.box.box2 = 0.001;		//not visible from start
	Locations[n].locators_radius.box.box3 = 0.5;		//bell
	Locations[n].locators_radius.box.box4 = 0.0001;		//crew hatch
	Locations[n].locators_radius.box.box5 = 0.7;		//cannon up
	Locations[n].locators_radius.box.box6 = 0.0001;		//cannon down - box not visible from start
	Locations[n].locators_radius.box.box7 = 0.7;		//cannon high up
	Locations[n].locators_radius.box.box8 = 0.5;		//anchor down
	Locations[n].locators_radius.box.box9 = 0.5;		//anchor down up
	Locations[n].locators_radius.box.box10 = 0.0001;	//place ropes in the air
	Locations[n].locators_radius.box.box11 = 0.0001;	//place planks over hole
	Locations[n].locators_radius.box.box12 = 0.0001;	//pick up pinion_large_H
	Locations[n].locators_radius.box.box14 = 0.3;		//place anchor
	Locations[n].locators_radius.box.box15 = 0.0001;	//climb to place anchor later
	Locations[n].locators_radius.box.box16 = 0.5;		//jump to corvette
	Locations[n].locators_radius.box.box17 = 0.5;		//jump to corvette

	Locations[n].locators_radius.goto.backoff1 = 0.05;
	Locations[n].locators_radius.goto.backoff2 = 0.05;
	Locations[n].locators_radius.goto.backoff3 = 0.05;
	Locations[n].locators_radius.goto.backoff4 = 0.05;
	Locations[n].locators_radius.goto.backoff5 = 0.05;
	Locations[n].locators_radius.goto.backoff6 = 0.05;
	Locations[n].locators_radius.goto.backoff7 = 0.05;
	Locations[n].locators_radius.goto.backoff8 = 0.05;
	Locations[n].locators_radius.goto.sidestep5 = 0.05;
	Locations[n].locators_radius.goto.sidestep6 = 0.05;
	Locations[n].locators_radius.goto.sidestep7 = 0.05;
	Locations[n].locators_radius.goto.sidestep8 = 0.05;
	Locations[n].locators_radius.goto.passage5 = 0.05;
	Locations[n].locators_radius.goto.passage6 = 0.05;
	Locations[n].locators_radius.goto.passage7 = 0.05;
	Locations[n].locators_radius.goto.passage8 = 0.05;
	Locations[n].locators_radius.goto.fire = 0.05;
	Locations[n].locators_radius.goto.turnW = 0.1;
	Locations[n].locators_radius.goto.turnN = 0.1;
	Locations[n].locators_radius.goto.turnE = 0.1;
	Locations[n].locators_radius.goto.turnS = 0.1;	
	Locations[n].locators_radius.goto.look7 = 0.7;
	

	Locations[n].locators_radius.randitem.randitem1 = 0.001;	
//	Locations[n].items.randitem1 = "hatch12";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.001;	//locator bigger later on	
	Locations[n].items.randitem2 = "elevator_ropes";		//the visible ropes one are not these!!!
									//these are fake pick ups
	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "qcport";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "qcport_plan3";

	Locations[n].rats = "true";
	LAi_LocationFightDisable(&Locations[n], true);
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "wr_corv_capmd";
	Locations[n].id.label = "Captain's cabin";
	//Info
	Locations[n].filespath.models = "locations\decks\cabin\capmd";
	Locations[n].image = "Deck_Capmd.tga";
	//Sound
	Locations[n].type = "corvette_closed";

	//Models
	//Always
	Locations[n].models.always.locators = "capmd_l_JRH";
	Locations[n].models.always.l1 = "capmd";
	Locations[n].models.always.l2 = "flush";
	Locations[n].models.always.window = "capmd_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "capmd_pd";
	Locations[n].models.day.fonar = "capmd_fd";
	//Night
	Locations[n].models.night.charactersPatch = "capmd_pn";
	Locations[n].models.night.fonar = "capmd_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	//Reload map

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_ships";
	Locations[n].reload.l1.emerge = "reload5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
/*	
	Locations[n].reload.l2.name = "reload2";			//keep this until part 10 is finished, way up wc etc
	Locations[n].reload.l2.go = "wr_corv_capmd";
	Locations[n].reload.l2.emerge = "wc_stay";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;
*/
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "wr_corv_capsm";
	Locations[n].reload.l3.emerge = "goto1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.0001;

	Locations[n].locators_radius.box.box3 = 0.3;	//wc
	Locations[n].locators_radius.box.box4 = 0.5;	//before wc

	Locations[n].locators_radius.goto.goto4 = 1.0;
	Locations[n].locators_radius.goto.goto5 = 1.0;

	Locations[n].rats = "true";
	n = n + 1;

	// -------------------------------------------------

	//ID
	Locations[n].id = "wr_corv_capsm";
	Locations[n].id.label = "Cabin";
	//Info
	Locations[n].filespath.models = "locations\decks\cabin\capsm";
	Locations[n].image = "Deck_Capsm.tga";
	//Sound
	Locations[n].type = "corvette_closed";

	//Models
	//Always
	Locations[n].models.always.locators = "capsm_l_JRH";
	Locations[n].models.always.l1 = "capsm";
	Locations[n].models.always.l2 = "stopboom_L";

	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "capsm_p";
	Locations[n].models.day.fonar = "capsm_fd";
	//Night
	Locations[n].models.night.charactersPatch = "capsm_p";
	Locations[n].models.night.fonar = "capsm_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	//Reload map

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_corv_crew";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	Locations[n].locators_radius.reload.reload1 = 0.6;		//always 0.5
	Locations[n].reload.l1.disable = 1;				//blocked from start

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "wr_corv_capmd";
	Locations[n].reload.l3.emerge = "goto3";			//was reload2
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.2;

	Locations[n].locators_radius.box.box1 = 0.0001;	
	Locations[n].locators_radius.box.box2 = 0.7;
	Locations[n].locators_radius.box.box3 = 0.7;
	Locations[n].locators_radius.box.box4 = 0.5;		

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "hatch10";

	Locations[n].locators_radius.randitem.randitem2 = 0.9;
	Locations[n].items.randitem2 = "chestmap1";

	Locations[n].locators_radius.randitem.randitem3 = 0.8;
	Locations[n].items.randitem3 = "bladecompasses";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "bladebarrel2";

	Locations[n].rats = "true";
	LAi_LocationFightDisable(&Locations[n], true);
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "wr_corv_crew";
	Locations[n].id.label = "Crew's quarters";
	//Info
	Locations[n].filespath.models = "locations\decks\seadogs";
	Locations[n].image = "Deck_seadogs.tga";
	//Sound
	Locations[n].type = "corvette_closed";

	//Models
	//Always
	Locations[n].models.always.locators = "camp_deck_l_JRH1A";	//was JRH1		
	Locations[n].models.always.l1 = "camp_deck";
	Locations[n].models.always.l2 = "";			//floormap1 later
	Locations[n].models.always.l3 = "";			//keysimple1 later

	Locations[n].models.always.window = "camp_deck_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "camp_deck_pd";
	Locations[n].models.day.fonar = "camp_deck_fd";
	//Night
	Locations[n].models.night.charactersPatch = "camp_deck_pn";
	Locations[n].models.night.fonar = "camp_deck_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	//Reload map

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_corv_deck1";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	Locations[n].reload.l1.disable = 1;			//opened with compasses + map
	
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_corv_capsm";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].reload.l2.disable = 1;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "wr_ships";
	Locations[n].reload.l3.emerge = "reload6";			
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.2;

	Locations[n].locators_radius.reload.reload5 = 0.5;
	Locations[n].locators_radius.reload.reload6 = 0.5;

	Locations[n].locators_radius.goto.goto12 = 1.0;

	Locations[n].locators_radius.box.box0 = 0.01;
	Locations[n].locators_radius.box.box2 = 0.01;
	Locations[n].locators_radius.box.box3 = 0.0001;		//big when compasses & map etc
	Locations[n].locators_radius.box.box4 = 0.5;		//floor to chair, was 0.7

	Locations[n].items.randitem1 = "bladebarrel2";		//empty barrel
	Locations[n].locators_radius.randitem.randitem1 = 1.0;

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "dummy_belt";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "dummy";

	Locations[n].rats = "true";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "wr_corv_smallcabin_L";
	Locations[n].id.label = "Cabin";
	//Info
	Locations[n].filespath.models = "locations\decks\seadogs";
	Locations[n].image = "wr_corv_smallcabin.tga";
	//Sound
	Locations[n].type = "corvette_closed";

	//Models
	//Always
	Locations[n].models.always.locators = "camp_deck_l_JRH2L";
	Locations[n].models.always.l1 = "camp_deck";
	Locations[n].models.always.l2 = "wheel_V";

	Locations[n].models.always.window = "camp_deck_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "camp_deck_pd";
	Locations[n].models.day.fonar = "camp_deck_fd";
	//Night
	Locations[n].models.night.charactersPatch = "camp_deck_pd";	//always day case
	Locations[n].models.night.fonar = "camp_deck_fd";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	//Reload map
	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "wr_corv_deck1";
	Locations[n].reload.l7.emerge = "reload7";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "";
	Locations[n].locators_radius.reload.reload7 = 0.0001;		//large after wheel pick up

	Locations[n].locators_radius.goto.box2 = 0.5;			//function go to wheel	

	Locations[n].rats = "true";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "wr_corv_smallcabin_R";
//	Locations[n].id.label = "Cabin";
	Locations[n].id.label = "This heavy cast iron door has a copper lock";
	//Info
	Locations[n].filespath.models = "locations\decks\seadogs";
	Locations[n].image = "wr_corv_smallcabin.tga";
	//Sound
	Locations[n].type = "corvette_closed";

	//Models
	//Always
	Locations[n].models.always.locators = "camp_deck_l_JRH2R";
	Locations[n].models.always.l1 = "camp_deck";
	Locations[n].models.always.l2 = "wheel_V";

	Locations[n].models.always.window = "camp_deck_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "camp_deck_pd";
	Locations[n].models.day.fonar = "camp_deck_fd";
	//Night
	Locations[n].models.night.charactersPatch = "camp_deck_pd";	//always day case
	Locations[n].models.night.fonar = "camp_deck_fd";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	//Reload map
	Locations[n].reload.l8.name = "reload8";
	Locations[n].reload.l8.go = "wr_corv_deck1";
	Locations[n].reload.l8.emerge = "reload4";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "";
	Locations[n].locators_radius.reload.reload8 = 0.0001;		//large after ingredients pick up

	Locations[n].locators_radius.goto.box2 = 0.5;			//function go to chest

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "door_H1";

	Locations[n].rats = "true";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "wr_corv_deck1";
	Locations[n].id.label = "Gun deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deck1_yellow";
	Locations[n].image = "wr_corv_deck1.tga";
	//Sound
	Locations[n].type = "corvette_closed";
	
	//Models
	//Always
	Locations[n].models.always.locators = "deck1_l_JRH";	//JRH_fight later on
	Locations[n].models.always.l1 = "deck1";
	Locations[n].models.always.l2 = "elevator&ropes_G1";	//G1 deck, G2 air	
	//Day
	Locations[n].models.day.charactersPatch = "deck1_p";
	Locations[n].models.day.fonar = "deck1_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deck1_p";
	Locations[n].models.night.fonar = "deck1_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	//to crew quarters
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "wr_corv_crew";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.2;

	//from crew quarters to belt
	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "wr_corv_deck1";
	Locations[n].reload.l6.emerge = "stair";			
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "";
	Locations[n].locators_radius.reload.reload6 = 0.2;

	//ladder to deck
	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "wr_ships";
	Locations[n].reload.l5.emerge = "reload7";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "";

	//small cabin right metal door
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "wr_corv_smallcabin_R";
	Locations[n].reload.l4.emerge = "cabR";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].reload.l4.disable = 1;

	//small cabin left door
	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "wr_corv_smallcabin_L";
	Locations[n].reload.l7.emerge = "cabL";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "";

	//to crew
	Locations[n].reload.l11.name = "reload11";
	Locations[n].reload.l11.go = "wr_corv_crew";
	Locations[n].reload.l11.emerge = "reload1";
	Locations[n].reload.l11.autoreload = "0";
	Locations[n].reload.l11.label = "";
	Locations[n].locators_radius.reload.reload11 = 0.2;

	Locations[n].locators_radius.box.box1 = 0.001;
	Locations[n].locators_radius.box.box3 = 0.2;
	Locations[n].locators_radius.box.box4 = 0.2;

	Locations[n].locators_radius.goto.box2 = 6.0;	
	Locations[n].locators_radius.goto.box4 = 0.2;		

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "ladder_hold";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "box";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "hatch12R";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	//Locations[n].items.randitem4 = "";				//not used

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "2groups_of_boxes";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "blade3carpets";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "barrel_big";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "box";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "box";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "barrel_roll";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "basket";

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "cannon_pipe2";
	
	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "box";

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
	Locations[n].items.randitem14 = "clock_big";

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	Locations[n].items.randitem15 = "clock_big";

	Locations[n].locators_radius.randitem.randitem16 = 0.001;
	Locations[n].items.randitem16 = "anvil";

	Locations[n].locators_radius.randitem.randitem17 = 1.0;
	Locations[n].items.randitem17 = "dummy_belt";

	Locations[n].locators_radius.randitem.randitem18 = 0.001;
	Locations[n].items.randitem18 = "dummy";

	Locations[n].locators_radius.randitem.randitem19 = 0.001;
	Locations[n].items.randitem19 = "door_H1";

	Locations[n].rats = "true";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "wr_gall_deck2_prow";
	Locations[n].id.label = "Gun deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deck2_red";
	Locations[n].image = "wr_gall_deck2_prow.tga";
	//Sound
	Locations[n].type = "galleon_closed";

	//Models
	//Always
	Locations[n].models.always.locators = "deck2_l_JRH_prow";
	Locations[n].models.always.l1 = "deck2";
	Locations[n].models.always.l2 = "pinion_small_H";
	//Day
	Locations[n].models.day.charactersPatch = "deck2_p";
	Locations[n].models.day.fonar = "deck2_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deck2_p";
	Locations[n].models.night.fonar = "deck2_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_gall_galley";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	//Locations[n].reload.l1.disable = 1;			//irontool needed to open
	Locations[n].locators_radius.reload.reload1 = 0.0001;

	Locations[n].reload.l2.name = "reload2";		//left
	Locations[n].reload.l2.go = "wr_ships";
	Locations[n].reload.l2.emerge = "reload11";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	//Locations[n].reload.l2.disable = 1;			//(locked from start)
	Locations[n].locators_radius.reload.reload2 = 0.0001;

	Locations[n].reload.l3.name = "reload3";		//right
	Locations[n].reload.l3.go = "wr_ships";
	Locations[n].reload.l3.emerge = "reload10";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "";
	//Locations[n].reload.l3.disable = 1;			//(locked from start)
	Locations[n].locators_radius.reload.reload3 = 0.0001;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "wr_gall_hold_first";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";

	Locations[n].reload.l5.name = "reload5";		//fish
	Locations[n].reload.l5.go = "wr_ships";
	Locations[n].reload.l5.emerge = "gotoR17";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "";
	Locations[n].reload.l5.disable = 1;			//open after final battle
	Locations[n].locators_radius.reload.reload5 = 0.8;

	Locations[n].locators_radius.box.gunpowder_1 = 0.01;
	Locations[n].locators_radius.box.box3 = 1.2;
	Locations[n].locators_radius.box.box4 = 1.0;		//plank blocking galley door, was 0.0001 from start
	Locations[n].locators_radius.goto.anvil = 1.0;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "fish02";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "hatch12";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "hatch12R";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "hatch12R";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;	//small radius until irontool is found
	Locations[n].items.randitem5 = "plank1_long";
	
	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "anvil";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "anvil_tilt";

	Locations[n].rats = "true";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "wr_gall_deck2_stern";
	Locations[n].id.label = "Gun deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deck2_red";
	Locations[n].image = "wr_gall_deck2_stern.tga";
	//Sound
	Locations[n].type = "galleon_closed";

	//Models
	//Always
	Locations[n].models.always.locators = "deck2_l_JRH_stern";
	Locations[n].models.always.l1 = "deck2";
	//Day
	Locations[n].models.day.charactersPatch = "deck2_p";
	Locations[n].models.day.fonar = "deck2_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deck2_p";
	Locations[n].models.night.fonar = "deck2_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_gall_cap_inner";
	Locations[n].reload.l1.emerge = "goto4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_ships";
	Locations[n].reload.l2.emerge = "reload9";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.0001;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "wr_ships";
	Locations[n].reload.l3.emerge = "reload8";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.0001;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "wr_gall_cap_outer";	
	Locations[n].reload.l4.emerge = "goto4";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.0001;			//from start

	Locations[n].reload.l5.name = "reload5";				//only for the label
	Locations[n].reload.l5.go = "wr_gall_cap_outer";
	Locations[n].reload.l5.emerge = "goto4";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "";
	Locations[n].locators_radius.reload.reload5 = 0.5;
	Locations[n].reload.l5.disable = 1;

	Locations[n].locators_radius.box.box11 = 0.0001;
	Locations[n].locators_radius.box.box12 = 1.0;				//replaces reload4 from start

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "hatch13R";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "hatch12R";

	Locations[n].rats = "true";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "wr_gall_galley";
	locations[n].id.label = "Galley";
	Locations[n].image = "wr_gall_galley.tga";

	//Sound
	Locations[n].type = "galleon_open";		//closed later

	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\mh6_galley\\";
    	Locations[n].models.always.l1 = "mh6";
	Locations[n].models.always.locators = "mh6_l_JRH";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "mh6_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh6_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	
	Locations[n].models.back = "back\shp_";		//test skip for flood

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_gall_deck2_prow";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "hatch5";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "hatch5";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "hatch6";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "hatch6";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "hatch5_A";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "hatch5_A";

	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "hatch5_B";

	Locations[n].locators_radius.randitem.randitem8 = 0.01;
	Locations[n].items.randitem8 = "hatch5_B";

	Locations[n].rats = "true";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "wr_gall_galley_flooded";
	locations[n].id.label = "Galley";
	Locations[n].image = "wr_gall_galley.tga";

	//Sound
	Locations[n].type = "galleon_closed";

	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\mh6_galley\\";
    	Locations[n].models.always.l1 = "mh6";
	Locations[n].models.always.locators = "mh6_l_JRH_closed";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "mh6_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh6_p";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_gall_deck2_prow";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";

	Locations[n].locators_radius.box.box1 = 0.0001;
	Locations[n].locators_radius.box.box2 = 0.0001;
	Locations[n].locators_radius.box.box3 = 0.0001;
	Locations[n].locators_radius.box.box4 = 0.0001;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "hatch5";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "hatch5";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "hatch6";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "hatch6";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "hatch5_A";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "hatch5_A";

	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "hatch5_B";

	Locations[n].locators_radius.randitem.randitem8 = 0.01;
	Locations[n].items.randitem8 = "hatch5_B";

	Locations[n].rats = "true";
	n = n + 1;

	// -------------------------------------------------
	
	Locations[n].id = "wr_gall_cap_inner";
	Locations[n].id.label = "Officer's cabin";
	//Info
	Locations[n].filespath.models = "locations\decks\cabin\cap";
	Locations[n].image = "Deck_Cap.tga";
	//Sound
	Locations[n].type = "galleon_closed";

	//Models
	//Always
	Locations[n].models.always.locators = "cap_l_JRH_inner";
	Locations[n].models.always.l1 = "cap";
	Locations[n].models.always.window = "cap_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "cap_p";
	Locations[n].models.day.fonar = "cap_fd";
	//Night
	Locations[n].models.night.charactersPatch = "cap_p";
	Locations[n].models.night.fonar = "cap_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_gall_deck2_stern";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_gall_hold_second";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";

	Locations[n].locators_radius.box.box9 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_M11";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "hatch12";	

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "barrel3";

	Locations[n].rats = "true";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "wr_gall_cap_outer";
	//Locations[n].id.label = "Captain's deck";
	Locations[n].id.label = "This heavy cast iron door has a gold lock";
	//Info
	Locations[n].filespath.models = "locations\decks\cabin\cap";
	Locations[n].image = "wr_gall_cap_outer.tga";
	//Sound
	Locations[n].type = "galleon_closed";

	//Models
	//Always
	Locations[n].models.always.locators = "cap_l_JRH_outer";
	Locations[n].models.always.l1 = "cap";
	Locations[n].models.always.window = "cap_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "cap_p";
	Locations[n].models.day.fonar = "cap_fd";
	//Night
	Locations[n].models.night.charactersPatch = "cap_p";
	Locations[n].models.night.fonar = "cap_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	
	Locations[n].reload.l1.name = "reload1";			
	Locations[n].reload.l1.go = "wr_gall_deck2_stern";
	Locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_gall_captain";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].reload.l2.disable = 1;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "wr_ships";
	Locations[n].reload.l3.emerge = "qdeck";		
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "";

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "wr_ships";
	Locations[n].reload.l4.emerge = "qdeck";		
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].reload.l4.disable = 1;			//never to be opened

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "wr_gall_deck2_stern";
	Locations[n].reload.l5.emerge = "reload4";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "";
	Locations[n].locators_radius.reload.reload5 = 0.5;

	Locations[n].locators_radius.goto.gunner = 2.0;	
	Locations[n].locators_radius.goto.goto7 = 0.0001;	

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "gatedoor_CAB";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "door_M11";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "door_M11";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "door_M11";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "door_M11";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "hatch13";

	Locations[n].rats = "true";
	n = n + 1;

// -------------------------------------------------
	Locations[n].id = "wr_gall_captain";
	Locations[n].id.label = "Captain's cabin";
	//Info
	Locations[n].filespath.models = "locations\decks\cabin\Cabin02";
	Locations[n].image = "Deck_Cabin2.tga";
	//Sound
	Locations[n].type = "galleon_closed";

	//Models
	//Always
	Locations[n].models.always.locators = "Cabin02_locators_JRH";
	Locations[n].models.always.l1 = "Cabin02";
	Locations[n].models.always.l2 = "trunk";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "Cabin02_patch";
	//Night
	Locations[n].models.night.charactersPatch = "Cabin02_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	//Reload map

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_gall_cap_outer";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_gall_captain";
	Locations[n].reload.l2.emerge = "goto1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;	

	Locations[n].locators_radius.box.box3 = 1.3;	

	Locations[n].rats = "true";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "wr_gall_hold_first";
	Locations[n].id.label = "Cargo Hold";
	//Info
	Locations[n].filespath.models = "locations\decks\hold_red";
	Locations[n].image = "wr_gall_hold_first.tga";
	//Sound
	Locations[n].type = "galleon_closed";

	//Models
	//Always
	Locations[n].models.always.locators = "hold_l_JRH_first";
	Locations[n].models.always.l1 = "hold";
	//Locations[n].models.always.l2 = "plank2";		//1 deck, 2 air
	//Locations[n].models.always.l3 = "elevator&ropes_G2";	//elevator&ropes_G0 hold, G1 deck, G2 air, ropes0 hold, ropes2 air
	Locations[n].models.always.l4 = "elevatornoropes_G0";	//elevatornoropes_G0
	//Locations[n].models.always.l5 = "irontool2";		//1 deck, 2 air
	Locations[n].models.always.l6 = "short_ladder";		

	//Day
	Locations[n].models.day.charactersPatch = "hold_p";
	Locations[n].models.day.fonar = "hold_fd";
	//Night
	Locations[n].models.night.charactersPatch = "hold_p";
	Locations[n].models.night.fonar = "hold_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_gall_hold_second";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	Locations[n].reload.l1.disable = 1;				//silver lock
	Locations[n].locators_radius.reload.reload1 = 0.001;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_gall_deck2_prow";
	Locations[n].reload.l2.emerge = "reload4";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";

	Locations[n].locators_radius.box.box1 = 0.001;			//place ropes function
	Locations[n].locators_radius.box.box2 = 0.001;			//pick up bladeirontool
	Locations[n].locators_radius.box.box3 = 0.001;			//= door to next hold
	Locations[n].locators_radius.box.box4 = 0.5;			//short ladder
	Locations[n].locators_radius.box.box5 = 0.5;			//short ladder
	Locations[n].locators_radius.box.box6 = 0.5;			//short ladder	
	Locations[n].locators_radius.box.box7 = 1.0;			//crew sound only	

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "key8";				//not used yet

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "boat2_C";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "boat2_B";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "boat2_B";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "ladder_hold";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "hatch12R";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "hatch12R";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	//Locations[n].items.randitem8 = "";				//not used

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "hatch12R";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "temp_plank0";

	Locations[n].rats = "true";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "wr_gall_hold_second";
	//Locations[n].id.label = "Cargo Hold";
	//Locations[n].id.label = "This heavy cast iron door has a silver lock";
	//Info
	//Locations[n].filespath.models = "locations\decks\hold_A";
	Locations[n].filespath.models = "locations\decks\hold_red";
	Locations[n].image = "wr_gall_hold_second.tga";
	//Sound
	Locations[n].type = "galleon_closed";

	//Models
	//Always
	Locations[n].models.always.locators = "hold_l_JRH_second"; 
	Locations[n].models.always.l1 = "hold";
	//Day
	Locations[n].models.day.charactersPatch = "hold_p";
	Locations[n].models.day.fonar = "hold_fd";
	//Night
	Locations[n].models.night.charactersPatch = "hold_p";
	Locations[n].models.night.fonar = "hold_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_gall_hold_first";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_gall_cap_inner";
	Locations[n].reload.l2.emerge = "reload2";		
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.0001;		//large when opened

	Locations[n].locators_radius.box.box1 = 1.0;			//small when opened

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "ladder_hold";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "box";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "barrel_big";	

	Locations[n].locators_radius.randitem.randitem4 = 0.001;	//not used yet
	Locations[n].locators_radius.randitem.randitem5 = 0.001;	//not used yet

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "hatch12R";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "hatch12R";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "hatch12R";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "hatch12R";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "plank2_long";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "plank2_long";

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "hammock";

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "hammock";

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
	Locations[n].items.randitem14 = "hammock";

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	Locations[n].items.randitem15 = "hammock";

	Locations[n].rats = "true";
	n = n + 1;


//farm start==================================================================================================

	locations[n].id = "wr_farm_kitchen";
	locations[n].id.label = "Rogers' kitchen";
	Locations[n].image = "wr_farm_kitchen.tga";
	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "Rogers_residence";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\largehouse01";
	locations[n].models.always.l1 = "largehouse01";
	Locations[n].models.always.l2 = "largehouse01_rand";
	Locations[n].models.always.l3 = "door_sklad";
	locations[n].models.always.locators = "largehouse01_locators_JRH_farm";

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
	locations[n].reload.l1.go = "wr_port";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "";
	
	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "wr_farm_bedroom";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "";

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "wr_farm_booty";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "";

	Locations[n].locators_radius.goto.goto1 = 2.0;	

	Locations[n].locators_radius.randitem.randitem1 = 1.0;
	Locations[n].items.randitem1 = "cauldron1";		//ok - no water

	Locations[n].island = "Redmond";
	n = n + 1;

	// -------------------------------------------------

	locations[n].id = "wr_farm_bedroom";
	locations[n].id.label = "Rogers' bedroom";
	Locations[n].image = "wr_farm_bedroom.tga";
	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "Rogers_private";					//start shop, later seashore
	
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\largehouse02_farm";
	locations[n].models.always.locators = "largehouse02_locators_JRH1";	//1 hidden, 2 open niche
	locations[n].models.always.l1 = "largehouse02";
	Locations[n].models.always.l2 = "largehouse02_rand";
	Locations[n].models.always.l3 = "2doors_largeh";
	//Locations[n].models.always.l4 = "largehouse02_windows3";		//later with windows2 = open
	
	Locations[n].models.always.window = "largehouse02_windows";		//start closed
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
	locations[n].reload.l1.go = "wr_farm_kitchen";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "wr_farm_corridor";		
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "";
	Locations[n].reload.l2.disable = 1;

	Locations[n].locators_radius.goto.servant = 1.0;
	Locations[n].locators_radius.box.box2 = 0.7;
	Locations[n].locators_radius.box.box3 = 0.0001;

	Locations[n].locators_radius.randitem.randitem1 = 0.0001;
	Locations[n].items.randitem1 = "chart1";

	Locations[n].locators_radius.randitem.randitem2 = 0.0001;
	Locations[n].items.randitem2 = "chart2A";

	Locations[n].locators_radius.randitem.randitem3 = 0.0001;
	Locations[n].items.randitem3 = "chart2B";

	Locations[n].locators_radius.randitem.randitem4 = 0.0001;
	Locations[n].items.randitem4 = "chart2C";

	Locations[n].locators_radius.randitem.randitem5 = 0.0001;
	Locations[n].items.randitem5 = "chart2D";

	Locations[n].locators_radius.randitem.randitem6 = 0.0001;
	Locations[n].items.randitem6 = "niche_wall";

	Locations[n].locators_radius.randitem.randitem7 = 0.5;
	Locations[n].items.randitem7 = "book49";

	Locations[n].island = "Redmond";
	n = n + 1;

       //-------------------------------------------------

	Locations[n].id = "wr_farm_corridor";
	//locations[n].id.label = "Rogers' passage";				//when opened
	Locations[n].filespath.models = "locations\inside\Corridor\\";
	Locations[n].filespath.textures = "locations\inside\Corridor\dark";	//start dark, normal later

	Locations[n].image = "wr_farm_corridor.tga";

	//Sound
	locations[n].type = "Rogers_corridor";					//JRH sound: no monster breathe
	
	//Models
	//Always
	Locations[n].models.always.locators = "StoreSmall_locators_JRH_dark";	//start dark		
	Locations[n].models.always.store = "StoreSmall";
	Locations[n].models.always.l1 = "scroll46";				//key placed when scroll is picked up (if candles are lit)				

	//Day
	Locations[n].models.day.charactersPatch = "StoreSmall_patch";

	//Night
	Locations[n].models.night.charactersPatch = "StoreSmall_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l4.name = "reload1";
	Locations[n].reload.l4.go = "wr_farm_bedroom";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload1 = 0.5;
	
	Locations[n].reload.l5.name = "reload2";
	Locations[n].reload.l5.go = "wr_farm_servant";
	Locations[n].reload.l5.emerge = "reload3";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;		
	Locations[n].reload.l5.disable = 1;				//key18 to unlock
	
	Locations[n].locators_radius.box.box1 = 0.5;			//candle
	Locations[n].locators_radius.box.box2 = 0.0001;			//0.5 when key 18 is found

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

	// -------------------------------------------------

	Locations[n].id = "wr_farm_servant";
	//locations[n].id.label = "Minervas room";				//later
	Locations[n].image = "wr_farm_servant.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_private";

	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Smallhome";
	Locations[n].filespath.textures = "locations\inside\Smallhome\farm";
	Locations[n].models.always.city = "sh";
	Locations[n].models.always.locators = "sh_l_JRH2_closed";		//hatch closed from start
	Locations[n].models.always.window = "sh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	locations[n].models.always.l2 = "door_fort";
	//Day
	Locations[n].models.day.charactersPatch = "sh_p";

	//Night
	Locations[n].models.night.charactersPatch = "sh_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\farm_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_farm_alchemy";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	Locations[n].locators_radius.reload.reload1 = 1.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_farm_alchemy2";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.7;
	Locations[n].reload.l2.disable = 1;			//open in WR part 2

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "wr_farm_corridor";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.5;	
	
	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "door_largeh";

	Locations[n].locators_radius.randitem.randitem2 = 0.0001;
	Locations[n].items.randitem2 = "bookcase";

	Locations[n].locators_radius.randitem.randitem3 = 0.0001;
	Locations[n].items.randitem3 = "books1";

	Locations[n].locators_radius.randitem.randitem4 = 0.0001;
	Locations[n].items.randitem4 = "carpet1";

	Locations[n].locators_radius.randitem.randitem5 = 0.0001;
	Locations[n].items.randitem5 = "hatch3V";			//cover one window

	Locations[n].locators_radius.randitem.randitem6 = 0.5;
	Locations[n].items.randitem6 = "book47";			//a scroll under the carpet

	Locations[n].locators_radius.randitem.randitem7 = 1.0;
	Locations[n].items.randitem7 = "book42";

	Locations[n].locators_radius.goto.goto4 = 1.0;
	Locations[n].locators_radius.box.box1 = 1.0;

	Locations[n].locators_radius.box.box2 = 0.0001;			//bookcase was 0.8 now skipped
	Locations[n].locators_radius.box.box3 = 0.5;			//pull carpet
	Locations[n].locators_radius.box.box4 = 0.5;			//pull carpet
	Locations[n].locators_radius.box.box5 = 0.001;			//unlock to alchemy2

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	locations[n].id = "wr_farm_booty";
	locations[n].id.label = "Rogers' storeroom";
	Locations[n].image = "wr_farm_booty.tga";

	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "Rogers_residence";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\sklad";
	locations[n].models.always.locators = "sklad_locators_JRH1";		//no door to alchemy
	locations[n].models.always.l1 = "sklad";

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
	locations[n].reload.l1.go = "wr_farm_kitchen";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "wr_farm_alchemy";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond";
	n = n + 1;
//JRH1
	// -------------------------------------------------

	locations[n].id = "wr_farm_alchemy";
	locations[n].id.label = "Rogers' laboratory";
	Locations[n].image = "wr_farm_alchemy.tga";
	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "Rogers_study";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\alchemist";
	locations[n].models.always.l1 = "mediumhouse01";
	locations[n].models.always.l2 = "wood3";
	locations[n].models.always.l3 = "plank_up";
	locations[n].models.always.l4 = "bars_down";
	locations[n].models.always.l5 = "bottle_ME0";			//bottle on mix table		
	locations[n].models.always.l6 = "lever1_down";
	locations[n].models.always.l7 = "rope_up";
	locations[n].models.always.l8 = "steplock_v";
	locations[n].models.always.l9 = "";				//cauldron3 or cauldron3_w later
	locations[n].models.always.l10 = "";				//retort_E0 later 
	locations[n].models.always.l11 = "";				//top3 later
	locations[n].models.always.l12 = "";				//glass_tube3 later
	locations[n].models.always.l13 = "";				//bottle_FE0 at fireplace later
	locations[n].models.always.l14 = "door_largeh2";
	locations[n].models.always.l15 = "";			//hatch7 Q2
	locations[n].models.always.l16 = "";			//bottle_LE0 Q2
	
	locations[n].models.always.locators = "mediumhouse01_locators_JRH0";

	Locations[n].models.always.window = "mediumhouse01_windows2";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
			
	//Day
	locations[n].models.day.charactersPatch = "mediumhouse01_patch";
	//Night
	locations[n].models.night.charactersPatch = "mediumhouse01_patch";
	//Environment
	locations[n].environment.weather = "false";		//coas true, potc false
	locations[n].environment.sea = "false";

	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "wr_farm_booty";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "";
	Locations[n].locators_radius.reload.reload1 = 0.0001;	//0.6 later

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "wr_farm_alchemy2";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.6;
	Locations[n].reload.l2.disable = 1;			//open in WR part 2

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "wr_farm_servant";
	locations[n].reload.l3.emerge = "goto7";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.5;
	Locations[n].reload.l3.disable = 1;			//locked from start when carpet is covering hatch in servant room

	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.0001;		//0.5 when bars are lifted
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.box.box6 = 0.6;
	Locations[n].locators_radius.box.box7 = 0.0001;		//larger for big bottle Q2
	Locations[n].locators_radius.box.box8 = 0.001;		//unlock to alchemy2

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "ladder_big";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "hatch11D";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "stool";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "medicine_table";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "armchair02";

	Locations[n].locators_radius.randitem.randitem6 = 0.5;
	Locations[n].items.randitem6 = "book45";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond";
	n = n + 1;

	// -------------------------------------------------
//JRH2	
	Locations[n].id = "wr_farm_alchemy2";
	//locations[n].id.label = "Rogers' secret laboratory";			//quest 2
	Locations[n].image = "wr_farm_alchemy2.tga";
	
	Locations[n].filespath.models = "locations\Inside\TwoFloorHouse";
	//Sound
//	locations[n].type = "Rogers_private";
	locations[n].type = "Rogers_study";
	//Models
	//Always
	Locations[n].models.always.locators = "TwoFloorHouse_locators_JRH0";	//start TwoFloorHouse_locators_JRH0
	Locations[n].models.always.house = "TwoFloorAlchm";
	Locations[n].models.always.window = "TwoFloorHouse_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//locations[n].models.always.l1 = "TwoFloorHouse_rand";			//better not used
	locations[n].models.always.l2 = "oven";
	locations[n].models.always.l3 = "door_largeh2";
	locations[n].models.always.l4 = "door_fort";
	locations[n].models.always.l5 = "ladder_big";
	locations[n].models.always.l6 = "wood32";
	locations[n].models.always.l7 = "cauldron2";				//cauldron2 or cauldron2_tilt
	locations[n].models.always.l8 = "";				//oven bottle_FS1 m fl
	locations[n].models.always.l9 = "wheel";
	locations[n].models.always.l10 = "";				//liquid_white, _grey, _orange, 
										//powder_white, _grey,
										//solid_brown, _red or ""
	locations[n].models.always.l11 = "";				//funnel
	locations[n].models.always.l12 = "glass_tube3";	
	locations[n].models.always.l13 = "";				//"", cloth_clean, cloth_dirty
	locations[n].models.always.l14 = "";				//grinding, bottle_GE0, _GC1, _GG1
	locations[n].models.always.l15 = "";				//"", powder_white_filter, powder_red_filter	
	locations[n].models.always.l16 = "leadbar";			//goldbar later
	locations[n].models.always.l17 = "carpetM";			//under oven
	locations[n].models.always.l18 = "filter_grid";			
	
	//Day
	Locations[n].models.day.charactersPatch = "TwoFloorHouse_patch";

	//Night
	Locations[n].models.night.charactersPatch = "TwoFloorHouse_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\farm_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "wr_farm_booty2";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	Locations[n].locators_radius.reload.reload1 = 0.7;
	Locations[n].reload.l1.disable = 1;			//will be opened in Q2, last alchemy part

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "wr_farm_alchemy";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.7;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "wr_farm_servant";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.7;
	
	Locations[n].locators_radius.box.box1 = 0.7;
	Locations[n].locators_radius.box.box2 = 0.7;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.7;
	Locations[n].locators_radius.box.box5 = 0.0001;			//big barrel not used
	Locations[n].locators_radius.box.box6 = 0.7;
	Locations[n].locators_radius.box.box7 = 0.5;
	Locations[n].locators_radius.box.box8 = 0.5;
	Locations[n].locators_radius.box.box9 = 0.45;
	Locations[n].locators_radius.box.box10 = 0.7;
	Locations[n].locators_radius.box.box11 = 0.7;
	Locations[n].locators_radius.box.box12 = 0.7;
	Locations[n].locators_radius.box.box13 = 0.7;
	Locations[n].locators_radius.box.box14 = 0.45;
	Locations[n].locators_radius.box.box15 = 0.5;
	Locations[n].locators_radius.box.box16 = 0.5;
	Locations[n].locators_radius.box.box19 = 0.7;
	Locations[n].locators_radius.goto.woodstop = 0.8;
	Locations[n].locators_radius.goto.woodback = 0.1;

	Locations[n].locators_radius.randitem.randitem1 = 0.0001;
	Locations[n].items.randitem1 = "bladewoodX";

	Locations[n].locators_radius.randitem.randitem2 = 0.0001;
	Locations[n].items.randitem2 = "boom_item_metal";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "barrel3";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "cauldron1";				//at filtering

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "crank2";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "distillery_tank";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "cannon_pipe45s";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "cauldron1";				//at grinding

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "rope_ale";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "rope_ale";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "handle";

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "bladewoodX";

	Locations[n].locators_radius.randitem.randitem13 = 0.0001;
	Locations[n].items.randitem13 = "chart3A";

	Locations[n].locators_radius.randitem.randitem14 = 0.0001;
	Locations[n].items.randitem14 = "chart3B";

	Locations[n].locators_radius.randitem.randitem15 = 0.0001;
	Locations[n].items.randitem15 = "chart3C";

	Locations[n].locators_radius.randitem.randitem16 = 0.0001;
	Locations[n].items.randitem16 = "chart3D";

	Locations[n].locators_radius.randitem.randitem17 = 0.0001;
	Locations[n].items.randitem17 = "mdchest";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond";
	n = n + 1;

//  -------------------------------------------------

	locations[n].id = "wr_farm_booty2";
//	locations[n].id.label = "Rogers' secret storeroom";				//label when opened
	Locations[n].image = "wr_farm_booty2.tga";

	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "Rogers_residence";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\sklad03";
	locations[n].models.always.locators = "sklad03_locators_JRH";
	locations[n].models.always.l1 = "sklad03";
	locations[n].models.always.l2 = "leadbars";			//later goldbars
	locations[n].models.always.l3 = "leadbars_chest";		//later goldbars_chest

	//Day
	locations[n].models.day.charactersPatch = "sklad03_patch";
	//Night
	locations[n].models.night.charactersPatch = "sklad03_patch";
	//Environment
	locations[n].environment.weather = "false";
	locations[n].environment.sea = "false";

	Locations[n].locators_radius.box.box7 = 0.001;			//0.5 Q2

	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "wr_farm_alchemy2";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "";

	Locations[n].locators_radius.randitem.randitem1 = 0.0001;
	Locations[n].items.randitem1 = "chest6U_vco";

	Locations[n].locators_radius.randitem.randitem2 = 0.0001;
	Locations[n].items.randitem2 = "chest6U_vco";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond";
	n = n + 1;

//farm ==================================================================================================


//QC ====================================================================================================

	Locations[n].filespath.models = "locations\Inside\MediumTavern";

	Locations[n].id = "QC_store_upstairs";
	locations[n].id.label = "Store upstairs";
	Locations[n].image = "Inside_MediumTavern.tga";

	//Town sack
	Locations[n].townsack = "Quebradas Costillas";

	//Sound
	locations[n].type = "brothel_shop";					//was ""

	//Models
	//Always
	Locations[n].models.always.locators = "MT_l_JRH";
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
	Locations[n].models.back = "back\qcsh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "QC_store_JRH";
	Locations[n].reload.l1.emerge = "goto10";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Quebradas Costillas store.";

	//roof
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "QC_town";
	Locations[n].reload.l2.emerge = "goto66";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Quebradas Costillas.";
	Locations[n].reload.l2.disable = 1;

	//terrace
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "QC_town";
	Locations[n].reload.l3.emerge = "reload23";		//goto23 not reload23? 1st time changed to emerge reload26 which doesn't work
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Quebradas Costillas.";
   
	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].locators_radius.goto.goto7 = 3.0;	

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\StoreSmall";	
	Locations[n].image = "Inside_StoreSmall.tga";

	Locations[n].id = "QC_Store_JRH";
	locations[n].id.label = "#stown_name# store";
	//Town sack
	Locations[n].townsack = "Quebradas Costillas"; // NK - "Oxbay";
	//Sound
	locations[n].type = "brothel_shop";

	//Models
	//Always
	Locations[n].models.always.locators = "SS_l_JRH";
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
	Locations[n].reload.l1.go = "QC_town";
	Locations[n].reload.l1.emerge = "Reload5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Quebradas Costillas.";
	Locations[n].reload.l1.disable = true;
	Locations[n].locators_radius.reload.locator2 = 0.5;

	Locations[n].reload.l2.name = "locator1";
	Locations[n].reload.l2.go = "QC_store_upstairs";
	Locations[n].reload.l2.emerge = "goto10";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Store upstairs.";
	
	Locations[n].reload.l3.name = "reload1";
	Locations[n].reload.l3.go = "QC_store_JRH";
	Locations[n].reload.l3.emerge = "Reload2";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload1 = 0.5;	
	Locations[n].reload.l3.disable = true;

	Locations[n].reload.l4.name = "reload2";		
	Locations[n].reload.l4.go = "QC_store_JRH";
	Locations[n].reload.l4.emerge = "reload1";
   	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;	
	Locations[n].reload.l4.disable = true;

	Locations[n].reload.l5.name = "reload3";
	Locations[n].reload.l5.go = "QC_store_bedroom";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Bedroom";
	Locations[n].locators_radius.reload.reload3 = 0.5;
	Locations[n].reload.l5.disable = true;

	Locations[n].locators_radius.box.box1  = 0.0001;
	Locations[n].locators_radius.box.box2  = 0.0001;

	Locations[n].locators_radius.randitem.randitem1 = 1.75;
	Locations[n].items.randitem1 = "mtoon_item";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;

// --------------------------------------------------

	Locations[n].id = "QC_store_bedroom";
	locations[n].id.label = "Bedroom";
	Locations[n].filespath.models = "locations\inside\mh10";
	Locations[n].image = "Inside_mh10.tga";

	//Town sack
	Locations[n].townsack = "Quebradas Costillas";

	//Sound
	locations[n].type = "brothel_shop";					

	//Models
	//Always
	Locations[n].models.always.locators = "mh10_l_JRH";
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
	Locations[n].reload.l1.go = "QC_Store_JRH";
	Locations[n].reload.l1.emerge = "Reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Quebradas Costillas store.";
	Locations[n].locators_radius.reload.reload1 = 0.5;

	Locations[n].locators_radius.box.box1 = 0.001;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.randitem.randitem1 = 0.5;
	Locations[n].locators_radius.item.item3 = 0.01;

	Locations[n].items.randitem1 = "potion1";

	LAi_LocationFightDisable(&Locations[n], true);	

	Locations[n].island = "QuebradasCostillas";
	n = n + 1;

// --------------------------------------------------

	//before roof has fallen down
	Locations[n].filespath.models = "locations\inside\shipyard2";//"locations\Inside\shipyard";
	Locations[n].id = "QC_shipyard1_JRH";
	locations[n].id.label = "#stown_name# shipyard";
	//Locations[n].image = "Shipyard_01.tga";
	Locations[n].image = "";//no loading picture please

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
	Locations[n].reload.l1.go = "QC_town";
	Locations[n].reload.l1.emerge = "Reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Quebradas Costillas.";
	Locations[n].reload.l1.disable = true;
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;

// --------------------------------------------------

	//after roof has fallen down
	Locations[n].filespath.models = "locations\inside\shipyard2";//"locations\Inside\shipyard";
	Locations[n].id = "QC_shipyard2_JRH";
	locations[n].id.label = "#stown_name# shipyard";
	Locations[n].image = "";//no loading picture please

	//Town sack
	Locations[n].townsack = "Quebradas Costillas"; // NK - "Oxbay";

	//Sound
	locations[n].type = "silent_shipyard";

	//Models
	//Always

	//THIS PART IS FOR THE Falaise de Fleur STYLE SHIPYARD(FANCY)
	//Locations[n].models.always.locators = "sh02_l";	
	Locations[n].models.always.locators = "sh02_l_JRH";		//sh02_l_JRH = start, sh02_l_JRH2 = mast horiz		
	Locations[n].models.always.tavern = "sh02";
	Locations[n].models.always.l1 = "BeamR";			//R = start pos

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
	Locations[n].reload.l1.go = "QC_town";
	Locations[n].reload.l1.emerge = "goto80";//was reload4

	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Quebradas Costillas.";
	Locations[n].reload.l1.disable = true;				//just to be sure
	Locations[n].locators_radius.reload.locator2 = 0.001;		//smallest possible, bugs if 0.0001
	
	//roof
	Locations[n].locators_radius.randitem.randitem14 = 0.1;
	Locations[n].items.randitem14 = "brF17R";
	Locations[n].locators_radius.randitem.randitem15 = 0.1;
	Locations[n].items.randitem15 = "brF7R";
	Locations[n].locators_radius.randitem.randitem16 = 0.1;
	Locations[n].items.randitem16 = "brF7R";

	//broken roof pieces to stay
	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "brF12";
	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "brF11";
	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "brF17";	
	Locations[n].locators_radius.randitem.randitem5 = 0.1;
	Locations[n].items.randitem5 = "brF16";

//________________________________________________________________
	//beam enabled to move
	Locations[n].locators_radius.randitem.randitem18 = 0.1;		//jrh2	
	Locations[n].items.randitem18 = "brF12horiz";			

	Locations[n].locators_radius.randitem.randitem4 = 0.1;		//not used
//	Locations[n].items.randitem4 = "brF15";

	Locations[n].locators_radius.randitem.randitem19 = 0.1;		//not used, was it ever?
//	Locations[n].items.randitem19 = "brF15";

	Locations[n].locators_radius.randitem.randitem22 = 0.1;		//not used
//	Locations[n].items.randitem22 = "brF15Down";
//________________________________________________________________

	//blocking the beam
	Locations[n].locators_radius.randitem.randitem20 = 0.1;
	Locations[n].items.randitem20 = "barrel_big";

	Locations[n].locators_radius.randitem.randitem21 = 1.5;
	Locations[n].items.randitem21 = "barrel_big";

	//key from big chest in corner
	Locations[n].locators_radius.randitem.randitem23 = 0.1;
	Locations[n].items.randitem23 = "key4";

	//in front of door
	Locations[n].locators_radius.randitem.randitem6 = 1.0;
	Locations[n].items.randitem6 = "brderrick";

	//writing desk
	Locations[n].locators_radius.randitem.randitem9 = 0.1;
	Locations[n].items.randitem9 = "brF14R";

	//commode
	Locations[n].locators_radius.randitem.randitem13 = 1.0;
	Locations[n].items.randitem13 = "brF13";
	
	//window
	Locations[n].locators_radius.randitem.randitem10 = 0.2;		//not used any longer
	//Locations[n].items.randitem10 = "sack";

	//sacks on basket chest
	Locations[n].locators_radius.randitem.randitem24 = 1.2;
	Locations[n].items.randitem24 = "sack";
	Locations[n].locators_radius.randitem.randitem25 = 0.1;
	Locations[n].items.randitem25 = "basket";

	//hiding existing axe
	Locations[n].locators_radius.randitem.randitem17 = 0.1;
	Locations[n].items.randitem17 = "brF4R";

	//cutlass under Blowhorn
	Locations[n].locators_radius.randitem.randitem11 = 0.3;		
	Locations[n].items.randitem11 = "blade4";			//skipped

	//dagger under Nickerson
	Locations[n].locators_radius.randitem.randitem12 = 0.3;		
	Locations[n].items.randitem12 = "blade5";			//skipped

	//carpenters chest
	Locations[n].locators_radius.randitem.randitem7 = 0.2;
	Locations[n].items.randitem7 = "toolchest1";			//empty one
	Locations[n].locators_radius.randitem.randitem8 = 0.01;
	Locations[n].items.randitem8 = "";				//not used

										
	Locations[n].locators_radius.box.box1  = 0.2;	//F commode by the door
	Locations[n].locators_radius.box.box2  = 0.2;	//B lower chest		
	Locations[n].locators_radius.box.box3  = 0.1;	//E writing desk: chest function
	Locations[n].locators_radius.box.box4  = 0.1;	//C drill barrel in corner	
	Locations[n].locators_radius.box.box5  = 0.1;	//A upper chest		
	Locations[n].locators_radius.box.box6  = 0.2;	//D basket chest
    	Locations[n].locators_radius.box.box7  = 1.0;	//J mast blocking chest of drawers
	Locations[n].locators_radius.box.box9  = 0.1;	//P commode chest function
	Locations[n].locators_radius.box.box10 = 0.1;	//H push beam
	Locations[n].locators_radius.box.box11 = 1.0;	//= box2, 5 push beam

	Locations[n].locators_radius.box.box12 = 0.9;	//G large lock		
	Locations[n].locators_radius.box.box13 = 0.1;	//G push beam
	Locations[n].locators_radius.box.box14 = 0.6;	//H ordinary lock

	Locations[n].locators_radius.box.box15 = 1.0;	//K door

	Locations[n].locators_radius.box.box16  = 1.0;	//J chest of drawers
	Locations[n].locators_radius.box.box17  = 0.1;	//C big chest in corner
	Locations[n].locators_radius.box.box18  = 0.1;	//P commode push beam
	Locations[n].locators_radius.box.box19  = 1.0;	//E writing desk : beam

	Locations[n].locators_radius.goto.goto5L  = 0.3;
	Locations[n].locators_radius.goto.goto5  = 0.3;
	Locations[n].locators_radius.goto.goto5R  = 0.3;

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;

//============================================================================
//WoodesRogers part 2 locations
//JRH Hands Charlestown Maltains

	locations[n].id = "bb_Maltains";
	locations[n].id.label = "Order of Malta";
	Locations[n].image = "Inside_Maltains.tga";
	//Town sack
	locations[n].townsack = "QuebradasCostillas";
	//Sound
	locations[n].type = "Rogers_cellar";
	
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Maltains";
	locations[n].models.always.l1 = "Malta_Base";
	locations[n].models.always.l2 = "bars_down";		//closed from start	
	locations[n].models.always.fonars = "Malta_fonars";
	locations[n].models.always.locators = "Malta_locators_JRH";	

	//Day
	locations[n].models.day.charactersPatch = "Malta_patch";
	//Night
	locations[n].models.night.charactersPatch = "Malta_patch";
	
	//Environment
	locations[n].environment.weather = "true";		//must be true to give fonars at night
	locations[n].environment.sea = "false";
	Locations[n].MaxSeaHeight = 0.2;
	Locations[n].lockWeather = "Clear";

	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Charlestown_port";		
	locations[n].reload.l1.emerge = "reload17";		
	locations[n].reload.l1.autoreload = "0";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "bb_maltains_office";
	locations[n].reload.l2.emerge = "arrive";
	locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.disable = 1;

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "Charlestown_port";
	locations[n].reload.l3.emerge = "reload18";
	locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.disable = 1;			//bars down from start

	Locations[n].locators_radius.box.box1  = 0.5;
	Locations[n].locators_radius.box.box2  = 0.5;
	Locations[n].locators_radius.box.box3  = 0.5;
	Locations[n].locators_radius.box.box4  = 0.5;
	Locations[n].locators_radius.box.box5  = 0.5;
	Locations[n].locators_radius.box.box6  = 0.5;
	Locations[n].locators_radius.box.box7  = 0.5;
	Locations[n].locators_radius.box.box8  = 0.5;
	Locations[n].locators_radius.box.box9  = 0.5;
	Locations[n].locators_radius.box.box10  = 0.5;
	Locations[n].locators_radius.box.box11  = 0.5;
	Locations[n].locators_radius.box.box12  = 0.5;
	Locations[n].locators_radius.box.box13  = 0.5;
	Locations[n].locators_radius.box.box14  = 0.5;
	Locations[n].locators_radius.box.box15  = 0.5;
	Locations[n].locators_radius.box.box16  = 0.5;
	Locations[n].locators_radius.box.box17  = 0.5;
	Locations[n].locators_radius.box.box18  = 0.5;
	Locations[n].locators_radius.box.box19  = 0.5;
	Locations[n].locators_radius.box.box20  = 0.5;
	Locations[n].locators_radius.box.box21  = 0.001;	//to maltains_office
	Locations[n].locators_radius.box.box22  = 0.5;
	Locations[n].locators_radius.box.box23  = 0.5;
	Locations[n].locators_radius.box.box24  = 0.6;
	Locations[n].locators_radius.box.box25  = 0.5;
	Locations[n].locators_radius.box.box26  = 0.5;
	Locations[n].locators_radius.box.box27  = 0.5;
	Locations[n].locators_radius.box.box28  = 0.5;
	Locations[n].locators_radius.box.box29  = 0.5;
	Locations[n].locators_radius.box.box30  = 0.2;
	Locations[n].locators_radius.box.box31  = 0.5;
	Locations[n].locators_radius.box.box32  = 0.2;
	Locations[n].locators_radius.box.box33  = 0.5;
	Locations[n].locators_radius.box.box34  = 0.3;
	Locations[n].locators_radius.box.box35  = 0.3;
	Locations[n].locators_radius.quest.quest2  = 1.5;
	Locations[n].locators_radius.quest.quest4  = 1.5;

	Locations[n].locators_radius.randitem.randitem1 = 1.0;
	Locations[n].items.randitem1 = "book68";			//scroll
	
	Locations[n].locators_radius.randitem.randitem2 = 1.0;
	Locations[n].items.randitem2 = "pillow";

	Locations[n].locators_radius.randitem.randitem3 = 0.0001;
	Locations[n].items.randitem3 = "chest5_coas";

	Locations[n].locators_radius.randitem.randitem4 = 0.0001;
	Locations[n].items.randitem4 = "book67";			//document

	Locations[n].locators_radius.randitem.randitem5 = 1.3;
	Locations[n].items.randitem5 = "book63";			//medicine

	Locations[n].locators_radius.randitem.randitem6 = 0.0001;
	Locations[n].items.randitem6 = "elevator_button_up";

	Locations[n].locators_radius.randitem.randitem7 = 0.0001;
	Locations[n].items.randitem7 = "elevator_button_down";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "QuebradasCostillas";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\inside\shipyard2";
	Locations[n].filespath.textures = "locations\inside\Shipyard2\malta";
	Locations[n].id = "bb_maltains_office";
	locations[n].id.label = "Secret room";
	Locations[n].image = "Inside_Maltains_Secret.tga";

	//Town sack
	Locations[n].townsack = "Quebradas Costillas";

	//Sound
	locations[n].type = "";//was "shop"

	//Models
	//Always
	//THIS PART IS FOR THE Falaise de Fleur STYLE SHIPYARD(FANCY)
	Locations[n].models.always.locators = "sh02_l_Malta";
	Locations[n].models.always.tavern = "sh02";
	Locations[n].models.always.window = "sh02_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	locations[n].models.always.l1 = "closed_windows";

	//Day
	//THIS PART IS FOR THE Falaise de Fleur STYLE SHIPYARD(FANCY)
	Locations[n].models.day.charactersPatch = "sh02_p";

	//Night
	//THIS PART IS FOR THE Falaise de Fleur STYLE SHIPYARD(FANCY)
	Locations[n].models.night.charactersPatch = "sh02_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "Charlestown_store";
	Locations[n].reload.l1.emerge = "locator1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.disable = 1;			//opened by guard

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "bb_Maltains";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 0.5;
	Locations[n].reload.l2.disable = 1;

	Locations[n].locators_radius.sit.sit3 = 4.0;
	
	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "hatch11";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;

//Hands prison start

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_IslaMuelle\port";
	Locations[n].image = "wr_prison_port.tga";

	Locations[n].id = "bb_prison_port";
	locations[n].id.label = "Entrance to Prison";

	//Town sack
	Locations[n].townsack = "St John's";

	//Sound
	locations[n].type = "prison_ships";

	//Models
	//Always
	Locations[n].models.always.locators = "MuPort_l_JRH";
	Locations[n].models.always.grassPatch = "MuPort_g";
	Locations[n].models.always.l1 = "MuPort";
	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.l2 = "MuPort_sb";
	Locations[n].models.always.l2.foam = "1";
	Locations[n].models.always.l3 = "cages";
	Locations[n].models.always.l4 = "small_fort";
	//Day
   	 Locations[n].models.day.rinok = "MuPort_e1";	
	Locations[n].models.day.fonar = "MuPort_fd";
    	Locations[n].models.day.charactersPatch = "MuPort_pd";
	//Night
	Locations[n].models.night.fonar = "MuPort_fn";
	Locations[n].models.night.charactersPatch = "MuPort_pn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.2;
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "bb_prison_alcove";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 0.5;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Antigua_fakefort1";
	Locations[n].reload.l2.emerge = "reloadc1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 2.0;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "bb_prison_elevator";
	Locations[n].reload.l3.emerge = "goto4";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].locators_radius.reload.reload3 = 0.3;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Antigua_port";
	Locations[n].reload.l4.emerge = "box7";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].locators_radius.reload.reload4 = 0.0001;

	Locations[n].reload.l5.name = "prison_door";
	Locations[n].reload.l5.go = "bb_prison_elevator";
	Locations[n].reload.l5.emerge = "goto3";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].locators_radius.reload.prison_door = 0.5;

	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box2 = 1.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.box.box6 = 0.5;
	Locations[n].locators_radius.box.box7 = 0.5;
	Locations[n].locators_radius.box.box8 = 0.5;
	
	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "prison_building";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "prison_pier";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "porch";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "prison_bridge";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "door_N_90";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "door_sklad";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "hanged_man";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "hatch11D";

	Locations[n].locators_radius.randitem.randitem9 = 0.01;
	Locations[n].items.randitem9 = "gibbet4";

	Locations[n].locators_radius.randitem.randitem10 = 0.01;
	Locations[n].items.randitem10 = "gibbet4";

	Locations[n].island = "Antigua";
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].id = "bb_prison_elevator";
	locations[n].id.label = "Elevator";
	Locations[n].filespath.models = "locations\inside\Dungeon_2\\";
	Locations[n].filespath.textures = "locations\inside\Dungeon_2\elevator";
	Locations[n].image = "wr_prison_elevator.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "silent_loghouse";
	//Models
	//Always
	Locations[n].models.always.locators = "d02_l_JRH1_elev";
	Locations[n].models.always.dungeon = "d02";
	Locations[n].models.always.fonar = "d02_fn";
	//Day
	Locations[n].models.day.charactersPatch = "d02_p";

	//Night
	Locations[n].models.night.charactersPatch = "d02_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map

	Locations[n].locators_radius.goto.goto5 = 0.5;
	Locations[n].locators_radius.goto.goto6 = 2.0;

	Locations[n].locators_radius.box.box1 = 0.6;
	Locations[n].locators_radius.box.box2 = 0.6;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "gatedoor_elevator";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "gatedoor_elevator";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "elevator_button_up";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "elevator_button_down";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "door_N_90";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "porch";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "gateroof_elevator";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "gateroof_elevator";

	LAi_LocationFantomsGen(&locations[n], false);

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "bb_prison_alcove";
	Locations[n].filespath.models = "locations\Incas Temple\Alcove";
	Locations[n].filespath.textures = "locations\inside\Alcove\prison";
	//Sound
	Locations[n].image = "wr_prison_alcove.tga";
	locations[n].type = "Rogers_jail";
	locations[n].id.label = "Prison central hall";
	//Models
	//Always
	Locations[n].models.always.locators = "Alcove_l_JRH1";		//JRH2 when crate has fallen down
	Locations[n].models.always.l1 = "alcove";
	//Rays
	Locations[n].models.always.l2 = "rays";
	Locations[n].models.always.l2.level = 100;
	Locations[n].models.always.l2.tech = "LocVisRays";
	Locations[n].models.always.l2.uvslide.u1 = -0.02;
	Locations[n].models.always.l2.uvslide.v1 = -0.02;
	Locations[n].models.always.l3 = "";				//rope_gibbet later

	//Day
	Locations[n].models.day.charactersPatch = "alcove_p";
	//Night
	Locations[n].models.night.charactersPatch = "alcove_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].lockWeather = "Alcove";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "bb_prison_port";
	Locations[n].reload.l1.emerge = "box7";
    	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "bb_prison_stairs1";
	Locations[n].reload.l2.emerge = "reload1";			//was reload2
    	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 0.001;		//large when unlocked

	Locations[n].locators_radius.box.box1 = 0.0;			//0.7 when crate has fallen down
	Locations[n].locators_radius.box.box2 = 0.9;
	Locations[n].locators_radius.box.box3 = 0.9;
	Locations[n].locators_radius.box.box4 = 0.9;
	Locations[n].locators_radius.box.box5 = 1.2;
	Locations[n].locators_radius.box.box6 = 1.2;
	Locations[n].locators_radius.box.box7 = 0.8;
	Locations[n].locators_radius.goto.stop4 = 0.6;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "prison_bars";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "gibbet";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "crate2";			//crate upstairs that can be pushed down

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "crate";				//crate fallen down

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "crate2";			//crate upstairs	

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "prison_bars";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "prison_bars";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "prison_bars";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "prison_bars";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "prison_bars";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "prison_bars";

	Locations[n].locators_radius.randitem.randitem12 = 0.6;
	Locations[n].items.randitem12 = "raft_ropes";

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "mdchest_broken";

	Locations[n].locators_radius.randitem.randitem14 = 0.8;
	Locations[n].items.randitem14 = "boom_item";

	LAi_LocationMonstersGen(&locations[n], false);
	Locations[n].island = "KhaelRoa"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Dungeon_1_wood";
	Locations[n].id = "bb_prison_stairs1";		//open = on
	Locations[n].image = "GB_big_stairs.tga";
	
	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_jail";

	//Models
	//Always
	Locations[n].models.always.locators = "d01_l_JRH_prison";	//without officers
	Locations[n].models.always.house = "d01";
	//Day
	Locations[n].models.day.charactersPatch = "d01_p";
	//Night
	Locations[n].models.night.charactersPatch = "d01_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//LAi_LocationFantomsGen(&locations[n], true);

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "bb_prison_alcove";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "bb_prison";
	Locations[n].reload.l3.emerge = "reload2";
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

	//  -------------------------------------------------

	Locations[n].id = "bb_prison";
	locations[n].id.label = "Rotunda lower levels";
	Locations[n].filespath.models = "locations\inside\prison";
	Locations[n].image = "Inside_prison.tga";

	//Town sack
	//Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_jail";
	
	//Models
	//Always
	Locations[n].models.always.prison = "Pri";
	Locations[n].models.always.locators = "Pri_l_Bonnet";
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
	Locations[n].reload.l1.go = "bb_prison_stairs2";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.label = "#stown_name#.";
	Locations[n].reload.l1.disable = 1;			//opened after Dover dead + officer dialog
	
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "bb_prison_stairs1";
	Locations[n].reload.l2.emerge = "goto1";
	Locations[n].reload.l2.label = "#stown_name#.";
	Locations[n].reload.l2.disable = 1;			//never opened

	Locations[n].locators_radius.box.box2 = 0.5; Locations[n].locators_radius.box.box13 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5; Locations[n].locators_radius.box.box14 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5; Locations[n].locators_radius.box.box15 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.5; Locations[n].locators_radius.box.box16 = 0.5;
	Locations[n].locators_radius.box.box6 = 0.5; Locations[n].locators_radius.box.box17 = 0.5;
	Locations[n].locators_radius.box.box7 = 0.5; Locations[n].locators_radius.box.box18 = 0.5;
	Locations[n].locators_radius.box.box8 = 0.5; Locations[n].locators_radius.box.box19 = 0.5;
	Locations[n].locators_radius.box.box9 = 0.5; Locations[n].locators_radius.box.box20 = 0.5;
	Locations[n].locators_radius.box.box10 = 0.5; Locations[n].locators_radius.box.box21 = 0.5;
	Locations[n].locators_radius.box.box11 = 0.5; Locations[n].locators_radius.box.box22 = 0.5;
	Locations[n].locators_radius.box.box12 = 0.5; Locations[n].locators_radius.box.box23 = 0.5;
	Locations[n].locators_radius.quest.stop = 3.0; Locations[n].locators_radius.quest.alarm = 3.0;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "gatedoor_small";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "key8";				//invisible = not used

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "door_Tortuga";

	Locations[n].vcskip = true; // PB
	Locations[n].monsters = 0; // KK
	LAi_LocationMonstersGen(&locations[n], false);

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------
//pär
	Locations[n].id = "bb_prison_stairs2";
//	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house\\";
	Locations[n].filespath.textures = "locations\inside\Doubleflour_house\Tortuga";	
	Locations[n].image = "Inside_Townhall_Stairs_Tortuga.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_jail";
	
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
	Locations[n].reload.l2.go = "bb_prison";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "bb_prison_stairs2";
	Locations[n].reload.l3.emerge = "reload4";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "bb_prison2";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.3;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_TortugaT";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "gatedoor_Mine";

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].id = "bb_prison2";
	locations[n].id.label = "Rotunda bottom level";
	Locations[n].filespath.models = "locations\inside\prison2";
	Locations[n].image = "wr_prison2.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_jail";

	//Models
	//Always
	Locations[n].models.always.prison = "Pri2";
	Locations[n].models.always.l1 = "a5";
	Locations[n].models.always.l2 = "ju";
	Locations[n].models.always.l3 = "chest";
	Locations[n].models.always.locators = "Pri2_l_JRH";

	Locations[n].models.always.river = "a5";
	Locations[n].models.always.river.level = 98;
	Locations[n].models.always.river.uvslide.v0 = -0.1;		//ORIG = -0.1 (fast), -0.05 = ok for slow together with only models.always.river = "a5"
	Locations[n].models.always.river.uvslide.v1 = 0.15;
	Locations[n].models.always.river.tech = "LocationRiver";
	
	//Locations[n].models.always.window = "Pri_w";
	//Locations[n].models.always.flame = "prison_flame";
	//Day
	Locations[n].models.day.charactersPatch = "Pri2_p";
	//Night
	Locations[n].models.night.charactersPatch = "Pri2_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false"; 

	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.7;
	Locations[n].locators_radius.box.box6 = 0.7;
	Locations[n].locators_radius.box.box7 = 0.001;		//hatch exit, big later	
	Locations[n].locators_radius.box.box9 = 1.5;
	Locations[n].locators_radius.box.box10 = 0.7;
	Locations[n].locators_radius.box.box11 = 1.0;
	Locations[n].locators_radius.box.box12 = 0.001;
	Locations[n].locators_radius.box.box13 = 0.001;
	Locations[n].locators_radius.quest.trick = 3.0;						

	//Reload map

	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "bb_prison_stairs2";
	locations[n].reload.l1.emerge = "goto4";		
	Locations[n].reload.l1.autoreload = "0";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "bb_prison_officer";
	locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.disable = 1;
	
	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "prison_bars";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "prison_bars";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "prison_bars";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "prison_bars";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "anvil";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "prison_bars";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "prison_bars";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "prison_bars";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "prison_bars";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "prison_bars";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "prison_bars";

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "door_R_90";

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "door_R_90";

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
	Locations[n].items.randitem14 = "prison_bars";

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	Locations[n].items.randitem15 = "prison_bars";

	Locations[n].locators_radius.randitem.randitem16 = 0.001;
	Locations[n].items.randitem16 = "hatch11";

	Locations[n].locators_radius.randitem.randitem17 = 0.1;
	Locations[n].items.randitem17 = "door_N06";

	Locations[n].locators_radius.randitem.randitem18 = 0.001;
	Locations[n].items.randitem18 = "door_TortugaT";

	Locations[n].locators_radius.randitem.randitem19 = 0.001;
	Locations[n].items.randitem19 = "chair";

	Locations[n].locators_radius.randitem.randitem20 = 0.001;
	Locations[n].items.randitem20 = "chair";

	Locations[n].items.randitem21 = "bladesaw";

	Locations[n].items.randitem22 = "bladeaxe4";

	Locations[n].items.randitem23 = "bladehammer";

	Locations[n].locators_radius.randitem.randitem24 = 0.001;
	Locations[n].items.randitem24 = "IronMaiden";

	Locations[n].locators_radius.randitem.randitem25 = 0.001;
	Locations[n].items.randitem25 = "skull2";

	Locations[n].locators_radius.randitem.randitem26 = 0.001;
	Locations[n].items.randitem26 = "skull2";

	Locations[n].locators_radius.randitem.randitem27 = 0.001;
	Locations[n].items.randitem27 = "skull2";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].id = "bb_prison_officer";
	locations[n].id.label = "Prison Office";
	Locations[n].filespath.models = "locations\inside\store03";
	Locations[n].filespath.textures = "locations\inside\store03\prison";	
	Locations[n].image = "wr_prison_office.tga";

	//Sound
	locations[n].type = "Rogers_jail";

	//Models
	//Models
	//Always
	Locations[n].models.always.locators = "store03_locators_WR2";
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
	Locations[n].models.back = "back\shp_";

	//Reload map
	Locations[n].reload.l5.name = "reload2";
	Locations[n].reload.l5.go = "bb_prison2";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].locators_radius.goto.goto1 = 0.8;
	Locations[n].locators_radius.goto.goto3 = 1.0;
	Locations[n].locators_radius.goto.bible = 2.0;

	Locations[n].locators_radius.box.box5 = 0.2;
	Locations[n].locators_radius.box.box6 = 0.8;			//testing
	Locations[n].locators_radius.box.box10 = 0.001;			//0.5 later
	Locations[n].locators_radius.box.box11 = 0.2;
	Locations[n].locators_radius.box.box12 = 0.5;
	Locations[n].locators_radius.box.box13 = 0.6;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "door_N06";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "gatedoor_PRI";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "gatedoor_PRI";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "gatedoor_PRI";

	Locations[n].locators_radius.randitem.randitem5 = 0.1;
	Locations[n].items.randitem5 = "raft_ropes";

	Locations[n].locators_radius.randitem.randitem6 = 0.1;
	Locations[n].items.randitem6 = "raft_ropes";

	Locations[n].locators_radius.randitem.randitem7 = 0.1;
	Locations[n].items.randitem7 = "armchair02";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//JRH
//-------------------------------------------------------------------------------
//KRISTIANIA START

	Locations[n].filespath.models = "locations\outside\Canyon";
	Locations[n].id = "Kristiania_canyon";
	locations[n].id.label = "Kristiania canyon";
	Locations[n].image = "wr_Kr_canyon.tga";

	//Town sack
	Locations[n].townsack = "Khael Roa";

	//Sound
	locations[n].type = "canyon";

	//Models
	//Always
	Locations[n].models.always.locators = "rift_l_JRH";
	Locations[n].models.always.rift = "rift_swedish";
	Locations[n].models.always.grassPatch = "rift_g";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "qc_door";
	Locations[n].models.always.l4 = "blocking_stones";

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
	Locations[n].reload.l1.go = "Kristiania_entre";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload1 = 1.0;

	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "IslaMona_port_exit";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "";
	Locations[n].locators_radius.reload.Reload6 = 1.3;
	
	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "ladder_very_big";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "pole1";

	Locations[n].island = "KhaelRoa";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "Kristiania_entre";
	locations[n].id.label = "Kristiania entre";
	Locations[n].image = "wr_Kr_entre.tga";

	//Town sack
	Locations[n].townsack = "Khael Roa";

	//Sound						
	locations[n].type = "silent_town";					//"town" after auction				
	LAi_LocationMonstersGen(&locations[n], false);				//while auction
	locations[n].vcskip = true;

	//Models
	//Always
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\town_01";

	Locations[n].models.always.city = "FF01_swedish";
	Locations[n].models.always.locators = "FF01_l_JRH_stop1_auction";
	Locations[n].models.always.grassPatch = "FF01_g";
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
	Locations[n].models.day.fonar = "FF01_fd";
	Locations[n].models.day.charactersPatch = "FF01_p";
	//Night
	Locations[n].models.night.fonar = "FF01_fn";
	Locations[n].models.night.charactersPatch = "FF01_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	Locations[n].locators_radius.quest.sit4 = 20.0;			//was 10, 15

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Kristiania_canyon";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Nueva_Suecia_upper_town";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Sea port.";
	Locations[n].reload.l2.disable = 1;				//stop1	

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Kristiania_center";
	Locations[n].reload.l3.emerge = "reload26";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "#stown_name#. Center.";

	Locations[n].reload.l5.name = "locator20";
	Locations[n].reload.l5.go = "";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Opium house. Closed auction days.";
	Locations[n].reload.l5.disable = 1;

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "pole1";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "derrick";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "derrick";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "long_table";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "chair";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "bench";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "bench";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "bench";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "chair";

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "chair";

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "chair";

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
	Locations[n].items.randitem14 = "auction_list_roll";

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	Locations[n].items.randitem15 = "chair";

	Locations[n].locators_radius.randitem.randitem16 = 0.001;
	Locations[n].items.randitem16 = "fort_tower_wall";

	Locations[n].locators_radius.randitem.randitem17 = 0.001;
	Locations[n].items.randitem17 = "pole1";

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Nueva_Suecia_upper_town";
	Locations[n].filespath.models = "locations\town_IslaMuelle\town_03";
	locations[n].id.label = "Nueva Suecia upper town";
	Locations[n].image = "wr_NS_high.tga";

	//Town sack
	Locations[n].townsack = "Khael Roa";

	//Sound
//	locations[n].type = "town";
	locations[n].type = "silent_repair_town";
	LAi_LocationFantomsGen(&locations[n], true);
	
	//Models
	//Always
	Locations[n].models.always.l1 = "Mu03_swedish";
	Locations[n].models.always.l2 = "oriel";
	Locations[n].models.always.l3 = "lever_up";
	Locations[n].models.always.l4 = "gatedoor_KRI";
	Locations[n].models.always.locators = "Mu03_l_JRH_stop1";
	Locations[n].models.always.grassPatch = "Mu03_g";
	//Day
	Locations[n].models.day.rinok = "Mu03_e1";
	Locations[n].models.day.fonar = "Mu03_fd";
	Locations[n].models.day.jumppatch = "Mu03_j";
	Locations[n].models.day.charactersPatch = "Mu03_pd";
	//Night
	Locations[n].models.night.fonar = "Mu03_fn";
	Locations[n].models.night.jumppatch = "Mu03_j";
	Locations[n].models.night.charactersPatch = "Mu03_pn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "Reload1";
//	Locations[n].reload.l1.go = "Kristiania_entre";			//later when opened
	Locations[n].reload.l1.go = "open_today";	
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].reload.l1.disable = 1;				//stop1	

	Locations[n].reload.l6.name = "Reload6";
	Locations[n].reload.l6.go = "Nueva_Suecia_lower_town";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "#stown_name#. Trade Square.";
	Locations[n].locators_radius.reload.reload6 = 2.0;		

	Locations[n].reload.l9.name = "Reload9";
	Locations[n].reload.l9.go = "Nueva_Suecia_hidden_town";
	Locations[n].reload.l9.emerge = "reload4";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "#stown_name#. Trade Square.";
	Locations[n].locators_radius.reload.reload9 = 2.0;

	Locations[n].reload.l60.name = "Reload6_back";
	Locations[n].reload.l60.go = "Nueva_Suecia_lower_town";
	Locations[n].reload.l60.emerge = "reload2";
	Locations[n].reload.l60.autoreload = "1";
	Locations[n].reload.l60.label = "#stown_name#. Trade Square.";
	Locations[n].locators_radius.reload.reload6_back = 0.8;		//was 2.0

	Locations[n].reload.l90.name = "Reload9_back";
	Locations[n].reload.l90.go = "Nueva_Suecia_hidden_town";
	Locations[n].reload.l90.emerge = "reload4";
	Locations[n].reload.l90.autoreload = "0";
	Locations[n].reload.l90.label = "#stown_name#. Trade Square.";
	Locations[n].locators_radius.reload.reload9_back = 1.0;
	Locations[n].reload.l90.disable = true;				//always locked

	Locations[n].reload.l11.name = "Reload11";
	Locations[n].reload.l11.go = "Nueva_Suecia_TailorsShop";
	Locations[n].reload.l11.emerge = "locator2";
	Locations[n].reload.l11.autoreload = "0";

	Locations[n].reload.l12.name = "Reload12";
	Locations[n].reload.l12.go = "Oriel_room";
	Locations[n].reload.l12.emerge = "reload2";
	Locations[n].reload.l12.autoreload = "0";
	Locations[n].reload.l12.label = "House.";
	Locations[n].locators_radius.reload.reload12 = 0.3;

	Locations[n].reload.l13.name = "Reload13";
	Locations[n].reload.l13.go = "Oriel_room_stairs";
	Locations[n].reload.l13.emerge = "goto4";
	Locations[n].reload.l13.autoreload = "0";
	Locations[n].reload.l13.label = "House.";
	Locations[n].locators_radius.reload.reload13 = 0.2;

	Locations[n].reload.l3.name = "Reload3";
	Locations[n].reload.l3.go = "Nueva_Suecia_upper_town";
	Locations[n].reload.l3.emerge = "box32";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].locators_radius.reload.reload3 = 0.7;
	Locations[n].reload.l3.disable = true;

	Locations[n].reload.l14.name = "Reload14";
	Locations[n].reload.l14.go = "Nueva_Suecia_upper_town";
	Locations[n].reload.l14.emerge = "reload3";
	Locations[n].reload.l14.autoreload = "0";
	Locations[n].locators_radius.reload.reload14 = 0.1;

	Locations[n].reload.l7.name = "Reload7";
	Locations[n].reload.l7.go = "";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Kristiania Usurerhouse. Closed today because of the naval visit.";
	Locations[n].reload.l7.disable = 1;

	Locations[n].locators_radius.box.box1 = 0.1;		
	Locations[n].locators_radius.box.box2 = 0.2;
	Locations[n].locators_radius.box.box3 = 0.2;
	Locations[n].locators_radius.box.box4 = 0.2;
	Locations[n].locators_radius.box.box5 = 0.2;
	Locations[n].locators_radius.box.box6 = 0.2;
	Locations[n].locators_radius.box.box7 = 0.2;
	Locations[n].locators_radius.box.box8 = 0.2;
	Locations[n].locators_radius.box.box9 = 0.2;
	Locations[n].locators_radius.box.box10 = 0.2;
	Locations[n].locators_radius.box.box11 = 0.2;
	Locations[n].locators_radius.box.box12 = 0.2;
	Locations[n].locators_radius.box.box13 = 0.2;
	Locations[n].locators_radius.box.box14 = 0.5;
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
	Locations[n].locators_radius.box.box28 = 0.2;
	Locations[n].locators_radius.box.box29 = 0.2;
	Locations[n].locators_radius.box.box30 = 0.2;
	Locations[n].locators_radius.box.box31 = 0.2;
	Locations[n].locators_radius.box.box32 = 0.1;
	Locations[n].locators_radius.box.box33 = 2.0;
	Locations[n].locators_radius.box.box34 = 0.8;
	Locations[n].locators_radius.quest.see_oriel = 0.01;			//1.5 later
	Locations[n].locators_radius.reload.reload10 = 0.5;
	Locations[n].locators_radius.box.box35 = 0.7;
	Locations[n].locators_radius.box.box37 = 0.6;
	Locations[n].locators_radius.box.box38 = 0.7;
	Locations[n].locators_radius.box.box39 = 0.2;
	Locations[n].locators_radius.box.box41 = 0.2;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "key8";					//not used			

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "house";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "port_tower";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "pole1";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "spanish_church";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "spanish_church";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "barrel3";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "door_window2";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "bars_down";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "steplock_v";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "derrick";

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "barrel3";

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Nueva_Suecia_TailorsShop";
	Locations[n].filespath.models = "locations\Inside\StoreSmall";	
	Locations[n].filespath.textures = "locations\inside\StoreSmall\Spanish";
	Locations[n].image = "wr_NS_tailor.tga";	
	locations[n].id.label = "Nueva Suecia tailor's shop";
	//Town sack
	Locations[n].townsack = "Khael Roa";
	//Sound
//	locations[n].type = "Rogers_study";
	locations[n].type = "shop";			//for shipyard icon

	//Models
	//Always
	Locations[n].models.always.locators = "SS_l_Kristiania_tailor";
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
	Locations[n].models.back = "back\mumh9_";

	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "Nueva_Suecia_upper_town";
	Locations[n].reload.l1.emerge = "Reload11";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Kristiania.";
	Locations[n].locators_radius.reload.locator2 = 0.5;

	Locations[n].reload.l2.name = "locator1";
	Locations[n].reload.l2.go = "Nueva_Suecia_tailor_upstairs";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Store upstairs.";

	Locations[n].locators_radius.box.box1  = 0.8;
	
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

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Nueva_Suecia_tailor_upstairs";
	locations[n].id.label = "Storeroom textiles";
	Locations[n].filespath.models = "locations\inside\mh5";
	Locations[n].image = "wr_NS_textiles.tga";

	//Town sack
	//Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "Rogers_study";
	//locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].models.always.locators = "mh5_l_Q2";
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
	Locations[n].models.back = "back\mumh5_";

	Locations[n].locators_radius.box.box4  = 0.7;

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Nueva_Suecia_upper_town";
	Locations[n].reload.l1.emerge = "box2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Slums.";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Nueva_Suecia_TailorsShop";
	Locations[n].reload.l2.emerge = "locator1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name#. Slums.";
	Locations[n].locators_radius.reload.reload2 = 0.8;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "door_N07";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "door_N07";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "roll_of_rolls";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "blade3carpets";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "pole1";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "dummy";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "Textile4";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "bed";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "carpet2";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "blade3carpets";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "blade3carpets";

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\mh3";
	Locations[n].id = "Oriel_room";
	locations[n].id.label = "Tailor's room";
	Locations[n].image = "Inside_mh3.tga";

	//Town sack
	//Locations[n].townsack = "Douwesen";

	//Sound
	locations[n].type = "brothel_room_QC";

	//Models
	//Always
	Locations[n].models.always.locators = "MH3_l_Q2";
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
	Locations[n].reload.l1.go = "Oriel_room_stairs";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Nueva_Suecia_upper_town";
	Locations[n].reload.l2.emerge = "oriel";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload2 = 0.8;

	Locations[n].locators_radius.box.box2  = 0.7;
	Locations[n].locators_radius.box.box3  = 0.7;
	Locations[n].locators_radius.box.box4  = 0.7;

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Oriel_room_stairs";
	locations[n].id.label = "Stairs";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house\\";
	Locations[n].image = "GB_small_stairs.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "brothel_room_QC";
	
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
	Locations[n].reload.l2.go = "Oriel_room";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Oriel_room_stairs";
	Locations[n].reload.l3.emerge = "reload4";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Nueva_Suecia_upper_town";
	Locations[n].reload.l4.emerge = "box31";
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

	Locations[n].id = "Nueva_Suecia_hidden_town";
	Locations[n].filespath.models = "locations\town_IslaMuelle\town_01";
	locations[n].id.label = "Nueva Suecia inner town";
	Locations[n].image = "wr_NS_inner.tga";

	//Town sack
	Locations[n].townsack = "Khael Roa";

	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	
	//Models
	//Always
	Locations[n].models.always.l1 = "Mu01_swedish";
	Locations[n].models.always.l2 = "building";
	Locations[n].models.always.locators = "Mu01_l_JRH2";
	Locations[n].models.always.grassPatch = "Mu01_g";
	//Day
	Locations[n].models.day.rinok = "Mu01_e1";
	Locations[n].models.day.fonar = "Mu01_fd";
	//Locations[n].models.day.jumppatch = "Mu01_j";			//must be off
	Locations[n].models.day.charactersPatch = "Mu01_pd";
	//Night
	Locations[n].models.night.fonar = "Mu01_fn";
	Locations[n].models.night.charactersPatch = "Mu01_pn";
	Locations[n].models.night.jumppatch = "Mu01_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Kristiania_cathedral";
	Locations[n].reload.l1.emerge = "hidden_town";			//was reload2
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Cathedral";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "NS_hidden_town_Tavern";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Tavern";
	Locations[n].locators_radius.reload.reload2 = 1.4;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Nueva_Suecia_upper_town";
	Locations[n].reload.l4.emerge = "reload9";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "#stown_name#.";

	Locations[n].reload.l40.name = "reload4_back";
	Locations[n].reload.l40.go = "Nueva_Suecia_upper_town";
	Locations[n].reload.l40.emerge = "reload9";
	Locations[n].reload.l40.autoreload = "0";
	Locations[n].reload.l40.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload4_back = 1.5;

	Locations[n].locators_radius.box.box1  = 1.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "spanish_church";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "gatedoor_KRI";	

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "house";	

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "NS_hidden_town_Tavern";
	locations[n].id.label = "The Siberia.";
	Locations[n].filespath.models = "locations\Inside\Tavern_1";
	Locations[n].filespath.textures = "locations\inside\Tavern_1\spanish";	
	Locations[n].image = "Inside_Tavern_1_white.tga";

	//Sound
	locations[n].type = "tavern";
	
	//Models
	//Always
	Locations[n].models.always.locators = "Tavern_1_l_KR";
	Locations[n].models.always.l1 = "Tavern_1";
	//Day
	Locations[n].models.day.charactersPatch = "Tavern_1_p";
	//Night
	Locations[n].models.night.charactersPatch = "Tavern_1_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\mulf2_";	

	Locations[n].locators_radius.box.box1 = 0.001;

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Nueva_Suecia_hidden_town";
	Locations[n].reload.l1.emerge = "reload200";			//was exit_house
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "NS_hidden_town_priest";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Room in #stown_name# tavern.";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "empty_bottle";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "book49";

	Locations[n].island = "KhaelRoa";
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "NS_hidden_town_priest";
	locations[n].id.label = "Priest's room";
	Locations[n].image = "Inside_Doubleflour_House_Room.tga";

	//Town sack

	//Sound
	locations[n].type = "silent_residence";
	
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Doubleflour_house";
	Locations[n].models.always.locators = "LH_F2_l_GB";
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
	Locations[n].reload.l1.go = "NS_hidden_town_Tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# tavern."; // KK
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "armchair02";

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Nueva_Suecia_lower_town";
	Locations[n].filespath.models = "locations\town_IslaMuelle\town_01";

	locations[n].id.label = "Nueva Suecia lower town";
	Locations[n].image = "wr_NS_low.tga";

	//Town sack
	Locations[n].townsack = "Khael Roa";

	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	
	//Models
	//Always
	Locations[n].models.always.l1 = "Mu01_swedish";
	Locations[n].models.always.l2 = "oriel";
	Locations[n].models.always.l3 = "gatedoors_KRI";
	Locations[n].models.always.locators = "Mu01_l_JRH";
	Locations[n].models.always.grassPatch = "Mu01_g";
	//Day
	Locations[n].models.day.rinok = "Mu01_e1";
	Locations[n].models.day.fonar = "Mu01_fd";
	//Locations[n].models.day.jumppatch = "Mu01_j";			//must be off
	Locations[n].models.day.charactersPatch = "Mu01_pd";
	//Night
	Locations[n].models.night.fonar = "Mu01_fn";
	Locations[n].models.night.charactersPatch = "Mu01_pn";
	Locations[n].models.night.jumppatch = "Mu01_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload32";
	Locations[n].reload.l1.go = "Kristiania_Port";
	Locations[n].reload.l1.emerge = "Reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Sea port.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Nueva_Suecia_upper_town";
	Locations[n].reload.l2.emerge = "reload6";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name#.";

	Locations[n].reload.l17.name = "reload17";
	Locations[n].reload.l17.go = "Kristiania_shipyard";
	Locations[n].reload.l17.emerge = "reload1";
	Locations[n].reload.l17.autoreload = "0";
	Locations[n].reload.l17.label = "#stown_name#.";
	Locations[n].reload.l17.disable = 1;					//locked from start

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Nueva_Suecia_upper_town";
	Locations[n].reload.l3.emerge = "reload6";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload2_back = 1.5;

	Locations[n].reload.l30.name = "Reload30";
	Locations[n].reload.l30.go = "Kristiania_cathedral";
	Locations[n].reload.l30.emerge = "lower_town";			//was reload1
	Locations[n].reload.l30.autoreload = "1";
	Locations[n].reload.l30.label = "Kristiania";
	Locations[n].locators_radius.reload.reload30 = 1.5;

	Locations[n].reload.l31.name = "Reload31";
	Locations[n].reload.l31.go = "Kristiania_cathedral_passage";
	Locations[n].reload.l31.emerge = "goto3";
	Locations[n].reload.l31.autoreload = "1";
	Locations[n].reload.l31.label = "Kristiania";
	Locations[n].locators_radius.reload.reload31 = 1.6;

	Locations[n].locators_radius.reload.reload33 = 1.9;
	Locations[n].locators_radius.box.box1 = 1.5;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.box.box6 = 0.5;
	Locations[n].locators_radius.box.box7 = 0.5;
	Locations[n].locators_radius.quest.shipyard = 1.0;
	Locations[n].locators_radius.quest.cardinal = 2.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "gatedoor_KRI";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "gatedoor_white_stone";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "spanish_church";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	//Locations[n].items.randitem4 = "gateroof_church_stone";		//not needed any more as the gap is closed
	Locations[n].items.randitem4 = "key8";					//invisible

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	//Locations[n].items.randitem5 = "gateroof_church_stone";		//not needed any more as the gap is closed
	Locations[n].items.randitem5 = "key8";					//invisible

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "key8";					//invisible		

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "key8";					//invisible

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "spanish_church";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "port_tower";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "pole1";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "door_window2";

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "bars_down";

	Locations[n].locators_radius.randitem.randitem13 = 0.01;
	Locations[n].items.randitem13 = "ladder_big";

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Kristiania_cathedral";
	locations[n].id.label = "Kristiania cathedral";
	Locations[n].image = "Inside_Church_3.tga";
	Locations[n].filespath.models = "locations\inside\Church_3";

	//Town sack
	Locations[n].townsack = "Khael Roa";

	//Sound
//	locations[n].type = "Turks_church";				//later whith priests
	locations[n].type = "Kristiania_church";
	
	//Models
	//Always
	Locations[n].models.always.city = "Church3";
	Locations[n].models.always.locators = "Church3_l_ON_closed";

	Locations[n].models.always.window = "church3_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	Locations[n].models.always.l1 = "door_button_missing";		//door_button later
	Locations[n].models.always.l2 = "wire";				//"" later

	//Day
	Locations[n].models.day.charactersPatch = "Church3_p";

	//Night
	Locations[n].models.night.charactersPatch = "Church3_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.65;
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.goto.door_button = 0.2;
	Locations[n].locators_radius.goto.see_button = 0.2;		

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Nueva_Suecia_lower_town";
	Locations[n].reload.l1.emerge = "reload30A";			//was goto200
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Center.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Nueva_Suecia_hidden_town";
	Locations[n].reload.l2.emerge = "reload100";			//was exit_church
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name#. Center.";
	Locations[n].locators_radius.reload.reload2 = 0.5;
	Locations[n].reload.l2.disable = 1;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "confessional";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "door_panel";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "door_largeh";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "lever_base";			//not used

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "lever_up";			//nit used

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "lever_down";			//not used

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "1_lanternF_night";
	
	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "1_lanternF_night";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "1_lanternF_night";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "1_lanternF_night";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "1_lanternF_night";

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "1_lanternF_night";

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "1_lanternF_night";

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
	Locations[n].items.randitem14 = "1_lanternF_night";		//behind altar

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	Locations[n].items.randitem15 = "steplock_v3";

	Locations[n].locators_radius.randitem.randitem16 = 0.001;
	Locations[n].items.randitem16 = "lever3_down";

	Locations[n].locators_radius.randitem.randitem17 = 0.001;
	Locations[n].items.randitem17 = "lever3_up";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "KhaelRoa";
	n = n + 1;

// -------------------------------------------------
//JRH shya
	Locations[n].filespath.models = "locations\Inside\shipyard3";

	Locations[n].id = "Kristiania_shipyard";
	locations[n].id.label = "Kristiania shipyard";
	Locations[n].image = "Inside_shipyard3.tga";

	//Town sack
	Locations[n].townsack = "Khael Roa";

	//Sound
//	locations[n].type = "Rogers_shop";
	locations[n].type = "shop";			//for shipyard icon
	
	//Models
	//Always
	Locations[n].models.always.locators = "sh03_l_KR";
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
//	Locations[n].models.back = "back\redb_";
	Locations[n].models.back = "back\mures2_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Nueva_Suecia_lower_town";
	Locations[n].reload.l1.emerge = "reload17";
	Locations[n].reload.l1.label = "";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 0.5;
	Locations[n].reload.l1.disable = 1;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Kristiania_shipyard_stairs";
	Locations[n].reload.l2.emerge = "Reload2";
	Locations[n].reload.l2.label = "";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].locators_radius.box.box1 = 0.6;
	Locations[n].locators_radius.box.box2 = 0.8;
	Locations[n].locators_radius.box.box4 = 0.6;
	Locations[n].locators_radius.box.box5 = 0.001;
	Locations[n].locators_radius.box.box6 = 0.6;
	
	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_largeh2";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "KhaelRoa";
	n = n + 1;

// -------------------------------------------------

	Locations[n].id = "Kristiania_shipyard_stairs";
	locations[n].id.label = "Shipyard stairs";
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
	Locations[n].reload.l2.go = "Kristiania_shipyard";
	Locations[n].reload.l2.emerge = "return";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
//	Locations[n].reload.l2.disable = 1;				//test with this unlocked
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Kristiania_shipyard_stairs";
	Locations[n].reload.l3.emerge = "reload4";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Kristiania_port";
	Locations[n].reload.l4.emerge = "box1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.3;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_N09";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "gatedoor_w";

	Locations[n].island = "KhaelRoa";
	n = n + 1;

// -------------------------------------------------

	locations[n].id = "Kristiania_shipwreck";
	locations[n].id.label = "Spanish galleon";
	locations[n].filespath.models = "locations\decks\Kidds_cabin";
	locations[n].image = "wr_wreck_inside.tga";
	
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "galleon_open";
	
	//Models
	//Always	
	Locations[n].models.always.inside = "PlutoStoreSmall";	
	Locations[n].models.always.windows = "PlutoStoreSmall_windows";
	Locations[n].models.always.windows.tech = "LocationWindows";
	Locations[n].models.always.windows.level = 65539;	
	Locations[n].models.always.locators = "PlutoStoreSmall_locators_KR";	
			
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
	//Locations[n].locators_radius.box.box3 = 0.001;

	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Kristiania_port";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "";
	Locations[n].reload.l1.disable = 1;
	Locations[n].locators_radius.reload.reload1 = 1.0;

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Kristiania_port";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "";
	Locations[n].reload.l2.disable = 1;
	Locations[n].locators_radius.reload.reload2 = 1.0;

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "Kristiania_port";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "";
	Locations[n].reload.l3.disable = 1;
	Locations[n].locators_radius.reload.reload3 = 1.0;

	locations[n].reload.l4.name = "reload4";
	locations[n].reload.l4.go = "Kristiania_port";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "";
	Locations[n].reload.l4.disable = 1;
	Locations[n].locators_radius.reload.reload4 = 1.0;

	locations[n].reload.l5.name = "reload5";
	locations[n].reload.l5.go = "Kristiania_port";
	locations[n].reload.l5.emerge = "reload1";
	locations[n].reload.l5.autoreload = "0";
	locations[n].reload.l5.label = "";
	Locations[n].reload.l5.disable = 1;
	Locations[n].locators_radius.reload.reload5 = 1.0;

	locations[n].reload.l6.name = "reload6";
	locations[n].reload.l6.go = "Kristiania_port";
	locations[n].reload.l6.emerge = "reload1";
	locations[n].reload.l6.autoreload = "0";
	locations[n].reload.l6.label = "";
	Locations[n].reload.l6.disable = 1;
	Locations[n].locators_radius.reload.reload6 = 1.0;

	locations[n].reload.l7.name = "reload7";
	locations[n].reload.l7.go = "Kristiania_port";
	locations[n].reload.l7.emerge = "reload1";
	locations[n].reload.l7.autoreload = "0";
	locations[n].reload.l7.label = "";
	Locations[n].reload.l7.disable = 1;
	Locations[n].locators_radius.reload.reload7 = 1.0;

	locations[n].reload.l8.name = "reload8";
	locations[n].reload.l8.go = "Kristiania_port";
	locations[n].reload.l8.emerge = "reload1";
	locations[n].reload.l8.autoreload = "0";
	locations[n].reload.l8.label = "";
	Locations[n].locators_radius.reload.reload8 = 1.0;

	Locations[n].locators_radius.box.box4 = 1.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "door_wreck";

	Locations[n].island = "KhaelRoa";
	n = n + 1;

// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_Greenford\port";
	Locations[n].image = "wr_Kr_port.tga";

	Locations[n].id = "Kristiania_port";
	locations[n].id.label = "Kristiania port";

	//Town sack
	Locations[n].townsack = "Khael Roa";

	//Sound
	locations[n].type = "port";
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	Locations[n].models.always.locators = "GrPort_l_JRH";
	Locations[n].models.always.l1 = "GrPort_swedish";
	Locations[n].models.always.l1.foam = "1";
//	Locations[n].models.always.l2 = "GrPort_PB";
	Locations[n].models.always.seabed = "GrPort_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "GrPort_g";

	Locations[n].models.always.shipyard = "shipyard_destroyed";
	Locations[n].models.always.shipyard.locator.group = "upgrades";
	Locations[n].models.always.shipyard.locator.name = "Shipyard";

	Locations[n].models.always.hut3_c = "hut3_c";
	Locations[n].models.always.hut3_c.locator.group = "upgrades";
	Locations[n].models.always.hut3_c.locator.name = "hut3_c";

	Locations[n].models.always.shipwreck3 = "shipwreck3";
	Locations[n].models.always.shipwreck3.locator.group = "upgrades";
	Locations[n].models.always.shipwreck3.locator.name = "shipwreck3";

	Locations[n].models.always.loghouse1 = "loghouse1";
	Locations[n].models.always.loghouse1.locator.group = "upgrades";
	Locations[n].models.always.loghouse1.locator.name = "loghouse1";

	Locations[n].models.always.loghouse2 = "loghouse2";
	Locations[n].models.always.loghouse2.locator.group = "upgrades";
	Locations[n].models.always.loghouse2.locator.name = "loghouse2";

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

	if (VISIT_DECK == 1)
		Locations[n].reload.l1.label = "Ship.";
	else
		Locations[n].reload.l1.label = "Sea.";

	Locations[n].locators_radius.reload.Reload1 = 3.0;

/*
	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Oxbay";
	Locations[n].reload.l3.emerge = "reload_1";
	Locations[n].reload.l3.autoreload = "0";
*/
	if (VISIT_DECK == 1)
		Locations[n].reload.l3.label = "Ship.";
	else
		Locations[n].reload.l3.label = "Sea.";
	Locations[n].locators_radius.reload.reload1_back = 3.0;

	Locations[n].reload.l2.name = "reload4";
	Locations[n].reload.l2.go = "Nueva_Suecia_lower_town";
	Locations[n].reload.l2.emerge = "reload32";
	Locations[n].reload.l2.autoreload = "0";
	//Locations[n].reload.l2.label = "#stown_name#.";
	
	Locations[n].reload.l4.name = "prison";
	Locations[n].reload.l4.go = "";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Kristiania prison. Vistors not allowed.";
	locations[n].reload.l4.disable = 1;

	Locations[n].locators_radius.rld.guard1 = 0.5;
	Locations[n].locators_radius.rld.guard2 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.0001;			//raft to wreck
	
	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "door_N09";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "door_H1";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "gibbet_high";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "hanged_man";
	
	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\town_Greenford\town";
	Locations[n].image = "wr_Kr_center.tga";

	Locations[n].id = "Kristiania_center";
	locations[n].id.label = "Kristiania center";
	//locations[n].worldmap = "Greenford";

	//Town sack
	Locations[n].townsack = "Khael Roa";

	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	Locations[n].models.always.locators = "GrTown_l_JRH";
	Locations[n].models.always.town = "GrTown_swedish";
	Locations[n].models.always.grassPatch = "GrTown_g";
	Locations[n].models.always.l1 = "grtown_b02";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "grtown_b03";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "grtown_b04";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";	//Day
	Locations[n].models.always.l4 = "gatedoors_KRI";
	Locations[n].models.day.rinok = "GrTown_e01";
	Locations[n].models.day.fonar = "GrTown_fd";
	Locations[n].models.day.charactersPatch = "GrTown_pd";
	Locations[n].models.day.jumpPatch = "GrTown_j";
	//Night
	Locations[n].models.night.fonar = "GrTown_fn";
	Locations[n].models.night.charactersPatch = "GrTown_pn";
	Locations[n].models.night.jumpPatch = "GrTown_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	LAi_LocationFantomsGen(&locations[n], true);
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_port";
	Locations[n].reload.l1.emerge = "Reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# port."; // KK

//here to suburb
	Locations[n].reload.l2.name = "reload40";
	Locations[n].reload.l2.go = "Kristiania_suburb";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l30.name = "reload19";
	Locations[n].reload.l30.go = "Kristiania_fort";
	Locations[n].reload.l30.emerge = "reloadc1";
	Locations[n].reload.l30.autoreload = "0";
	Locations[n].reload.l30.label = "Fort";
	Locations[n].locators_radius.reload.reload19 = 0.0001;
	
	Locations[n].reload.l3.name = "reload26";
	Locations[n].reload.l3.go = "Kristiania_entre";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Canyon. Mines.";

	Locations[n].reload.l23.name = "reload23";
	Locations[n].reload.l23.go = "Kristiania_store";
	Locations[n].reload.l23.emerge = "locator2";
	Locations[n].reload.l23.autoreload = "0";
	Locations[n].reload.l23.label = "Store.";

	Locations[n].reload.l41.name = "reload41";
	Locations[n].reload.l41.go = "Kristiania_brothel_stairs";
	Locations[n].reload.l41.emerge = "goto4";
	Locations[n].reload.l41.autoreload = "1";
	//Locations[n].locators_radius.reload.reload41 = 1.6;

	Locations[n].reload.l42.name = "reload42";
	Locations[n].reload.l42.go = "Kristiania_center_stairs";
	Locations[n].reload.l42.emerge = "reload1";
	Locations[n].reload.l42.autoreload = "1";

  	Locations[n].reload.l9.name = "reload27";
	Locations[n].reload.l9.go = "Kristiania_townhall_entre";
	Locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "Entre";
//	Locations[n].reload.l9.close_for_night = 1;
	Locations[n].reload.l9.disable = 1;				//opened later

	Locations[n].reload.l11.name = "reload15";
	Locations[n].reload.l11.go = "Kristiania_chapel";
	Locations[n].reload.l11.emerge = "reload1";
	Locations[n].reload.l11.autoreload = "0";
	Locations[n].reload.l11.label = "Church.";
	Locations[n].reload.l11.close_for_night = 1;

	Locations[n].locators_radius.reload.reload43 = 0.5;
	Locations[n].locators_radius.reload.reload44 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "swedish_stonehouse";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "key8";				//not used

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "fort_wall";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "fort_tower";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "pole1";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "key8";				//not used

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "derrick";

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	//OFFICE + SHIPYARD4 
	Locations[n].id = "Kristiania_townhall_entre";
	locations[n].id.label = "Townhall office - open later today";
	Locations[n].filespath.models = "locations\inside\Office";
	Locations[n].image = "wr_Kr_TH_office.tga";

	//Town sack
	Locations[n].townsack = "Khael Roa";

	//Sound
	locations[n].type = "Swe_inside";
	
	//Models
	Locations[n].models.back = "back\grms_";
	//Always
	Locations[n].models.always.locators = "office_locators";
	Locations[n].models.always.shipyard = "office";
	Locations[n].models.always.window = "office_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "office_patch";
//	Locations[n].models.day.fd = "Sh01_fd";

	//Night
	Locations[n].models.night.charactersPatch = "office_patch";
//	Locations[n].models.night.fn = "Sh01_fn";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Kristiania_center";
	Locations[n].reload.l1.emerge = "reload27";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Kristiania";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Kristiania_townhall";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].locators_radius.reload.reload2 = 0.7;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "";		
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Private";
	Locations[n].reload.l3.disable = 1;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "";		
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Private";
	Locations[n].reload.l4.disable = 1;

	Locations[n].locators_radius.box.box1 = 1.0;
	Locations[n].locators_radius.box.box2 = 0.001;
	Locations[n].locators_radius.box.box3 = 0.001;
	Locations[n].locators_radius.box.box4 = 0.001;
	Locations[n].locators_radius.box.box5 = 0.001;	

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Kristiania_townhall";
	locations[n].id.label = "Swedish Governor Walter";
	//Town sack
	Locations[n].townsack = "Khael Roa";
	//Sound
	locations[n].type = "Swe_inside";
	
	Locations[n].filespath.models = "locations\Inside\Shipyard4";
	Locations[n].image = "wr_Kr_TH.tga";
	//Models
	Locations[n].models.back = "back\grms_";
	//Always
	Locations[n].models.always.l1 = "Sh04";
	Locations[n].models.always.locators = "Sh04_locators_KR";
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
	Locations[n].reload.l1.go = "Kristiania_townhall_entre";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.label = "Kristiania";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Private";
	Locations[n].reload.l2.disable = 1;
	
	Locations[n].locators_radius.box.box1 = 0.001;
	Locations[n].locators_radius.box.box2 = 0.001;
	Locations[n].locators_radius.box.box3 = 1.2;
	Locations[n].locators_radius.box.box4 = 0.001;
	Locations[n].locators_radius.box.box5 = 0.001;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "carpet1";

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Kristiania_store";
	Locations[n].filespath.models = "locations\Inside\StoreSmall";
	Locations[n].filespath.textures = "locations\inside\StoreSmall\Tortuga";	
	Locations[n].image = "wr_Kr_store.tga";
	locations[n].id.label = "Kristiana store.";
	//Town sack
	Locations[n].townsack = "Khael Roa";
	//Sound
	locations[n].type = "shop";
	Locations[n].townsack = "Khael Roa";
	//Models
	//Always
	Locations[n].models.always.locators = "SS_l_Kristiania_store";
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
	Locations[n].models.back = "back\grmh9_";
	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "Kristiania_center";
	Locations[n].reload.l1.emerge = "Reload23";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.locator2 = 1.0;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "gatedoor_pgrey";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Kristiania_brothel_stairs";
	locations[n].id.label = "To the Brothel";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house\\";
//	Locations[n].filespath.textures = "locations\inside\Doubleflour_house\church_attic";
	Locations[n].filespath.textures = "locations\inside\Doubleflour_house\wood_tower";
	Locations[n].image = "GB_small_stairs.tga";

	//Town sack
	Locations[n].townsack = "Khael Roa";

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
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "reload1";			
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Brothel open all days except Mondays.";
	Locations[n].locators_radius.reload.reload2 = 0.5;
	Locations[n].reload.l2.disable = 1;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Kristiania_brothel_stairs";
	Locations[n].reload.l3.emerge = "reload4";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Kristiania_center";
	Locations[n].reload.l4.emerge = "reload41A";	//was goto41
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.3;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_N09";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.01;
//	Locations[n].items.randitem2 = "gatedoor_attic_brick";
	Locations[n].items.randitem2 = "gatedoor_w";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "door_N09";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
//	Locations[n].items.randitem4 = "gatedoor_attic_brick";
	Locations[n].items.randitem4 = "gatedoor_w";

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Dungeon_1_wood";
	Locations[n].id = "Kristiania_center_stairs";
	locations[n].id.label = "To Kristiania center";
	Locations[n].image = "GB_big_stairs.tga";
	//Locations[n].monsters = "1";
	
	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "shop";

	//Models
	//Always
	Locations[n].models.always.locators = "d01_l_JRH_prison";	//without officers
	Locations[n].models.always.house = "d01_KR";
	//Day
	Locations[n].models.day.charactersPatch = "d01_p";
	//Night
	Locations[n].models.night.charactersPatch = "d01_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Kristiania_center";
	Locations[n].reload.l1.emerge = "reload42A";			//was goto42
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Kristiania center";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Kristiania_jungle_exit";
	Locations[n].reload.l3.emerge = "reload30";				//was exit
	Locations[n].reload.l3.autoreload = "1";				
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "gatedoor_small";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "gatedoor_small";

	Locations[n].locators_radius.randitem.randitem8 = 0.1;
	Locations[n].items.randitem8 = "gatedoor_w";

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Kristiania_jungle_exit";
	locations[n].id.label = "Exit from Kristiania";
	Locations[n].image = "wr_Kr_jungleX.tga";

	//Town sack
	
	//Sound
	locations[n].type = "silent_jungle";
	LAi_LocationMonstersGen(&locations[n], false);
	locations[n].vcskip = true;

	//Models
	//Always
	Locations[n].filespath.models = "locations\town_Oxbay\exit";
	Locations[n].models.always.locators = "OXexit_l_Q2";
	Locations[n].models.always.exit = "oxexit_swedish";
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
	Locations[n].reload.l1.name = "reload3";
	Locations[n].reload.l1.go = "Kristiania_center_stairs";
	Locations[n].reload.l1.emerge = "goto1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].reload.l2.name = "Reload2";
	Locations[n].reload.l2.go = "KR_jungle_2";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 2.0;

	Locations[n].reload.l3.name = "Reload1";
	Locations[n].reload.l3.go = "KR_jungle_1";
	Locations[n].reload.l3.emerge = "Reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1 = 4.0;

	Locations[n].reload.l4.name = "Reload2_back";
	Locations[n].reload.l4.go = "KR_jungle_2";
	Locations[n].reload.l4.emerge = "reload3";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2_back = 2.0;

	Locations[n].reload.l5.name = "Reload1_back";
	Locations[n].reload.l5.go = "KR_jungle_1";
	Locations[n].reload.l5.emerge = "Reload3";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1_back = 3.0;

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Kristiania_chapel";
	locations[n].id.label = "Kristiania Chapel";
	Locations[n].image = "wr_chapel.tga";
	Locations[n].filespath.models = "locations\inside\Church_2\\";
	Locations[n].filespath.textures = "locations\inside\Church_2\chapel";
	
	//Sound
	locations[n].type = "Vane_chapel";

	//Models
	//Always
	Locations[n].models.always.city = "Church2";
	Locations[n].models.always.locators = "Church2_l";
	Locations[n].models.always.window = "church2_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Church2_p";

	//Night
	Locations[n].models.night.charactersPatch = "Church2_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Kristiania_center";
	Locations[n].reload.l1.emerge = "reload15";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Kristiania_fort";
	//locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";
	locations[n].id.label = "Fort Waxholm";
	
	//Town sack
	Locations[n].townsack = "Khael Roa";

	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_2";
	//Locations[n].filespath.textures = "locations\SPAIN";
	
	Locations[n].image = "wr_Kr_fort.tga";
	//Sound
	//locations[n].type = "silent_seashore";
	//locations[n].type = "silent_cave_seashore";
	locations[n].type = "Vane_silent_temple";

	//Models
	//Always
	Locations[n].models.always.locators = "fort2_l_JRH";
	Locations[n].models.always.l1 = "fort2";
	Locations[n].models.always.l2 = "gatedoor_KRI";

	//Day
	Locations[n].models.day.charactersPatch = "fort2_p";
	Locations[n].models.day.fonar = "fort2_fd";
	//Night
	Locations[n].models.night.charactersPatch = "fort2_p";
	Locations[n].models.night.fonar = "fort2_fn";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
/*
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Kristiania_fort_commander";
	Locations[n].reload.l1.emerge = "locator2";
	Locations[n].reload.l1.autoreload = "0";
*/
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Kristiania_fort_stairs";
	Locations[n].reload.l1.emerge = "goto3";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l10.name = "reloadc1";
	Locations[n].reload.l10.go = "Kristiania_center";
	Locations[n].reload.l10.emerge = "reload19";
	Locations[n].reload.l10.autoreload = "0";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Kristiania_downhill";
	Locations[n].reload.l2.emerge = "Falaise_de_fleur_location_05_04";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].locators_radius.goto.guard1 = 1.5;
	Locations[n].locators_radius.quest.change1 = 1.0;
	Locations[n].locators_radius.quest.change2A = 1.0;
	Locations[n].locators_radius.quest.change2B = 1.0;
	Locations[n].locators_radius.quest.change1_up = 0.3;
	Locations[n].locators_radius.quest.change2A_up = 0.3;
	Locations[n].locators_radius.quest.change2B_up = 0.3;
	Locations[n].locators_radius.quest.change1_down = 0.3;
	Locations[n].locators_radius.quest.change2A_down = 0.3;
	Locations[n].locators_radius.quest.change2B_down = 0.3;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
//	Locations[n].items.randitem1 = "gatedoor_KRI";
	Locations[n].items.randitem1 = "key8";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "pole1";

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Kristiania_fort_stairs";
	locations[n].id.label = "Fort tower";
	Locations[n].filespath.models = "locations\inside\store04";
	Locations[n].filespath.textures = "locations\inside\store04\fort";
	Locations[n].image = "wr_tower_stairsA.tga";

	//Town sack
	Locations[n].townsack = "Khael Roa";

	//Sound
	locations[n].type = "silent_cave_seashore";		

	//Models
	//Always
	Locations[n].models.always.locators = "store04_locators_JRH9";		//was 8
	Locations[n].models.always.tavern = "store04";
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
	Locations[n].reload.l4.go = "Kristiania_fort_commander";
    	Locations[n].reload.l4.emerge = "locator2";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.5;
	locations[n].reload.l4.disable = 0;

	//down
	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "Kristiania_fort";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "1";
	Locations[n].reload.l7.label = "";

	Locations[n].locators_radius.goto.goto3 = 1.0;
	Locations[n].locators_radius.box.box1 = 0.7;
	Locations[n].locators_radius.box.box2 = 0.7;

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
	Locations[n].items.randitem13 = "gatedoor_LH1";	

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
    Locations[n].items.randitem14 = "ladder_big";

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	Locations[n].items.randitem15 = "lilgun";

	Locations[n].locators_radius.randitem.randitem16 = 0.001;
	Locations[n].items.randitem16 = "gatedoor_WT1";			

	Locations[n].locators_radius.randitem.randitem17 = 0.001;
	Locations[n].items.randitem17 = "gatedoor_wT1";			

	Locations[n].locators_radius.randitem.randitem18 = 0.001;
	Locations[n].items.randitem18 = "gatedoor_WT2";			

	Locations[n].locators_radius.randitem.randitem19 = 0.001;
    Locations[n].items.randitem19 = "hatch11DB";		

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------
	
	Locations[n].id = "Kristiania_fort_commander";
	locations[n].id.label = "Fort Commander Hilpershaussen";
	Locations[n].image = "wr_Kr_fort_commander.tga";

	//Town sack
	Locations[n].townsack = "Khael Roa";

	//Sound
	//locations[n].type = "silent_cave_seashore";
	locations[n].type = "Vane_silent_temple";

	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\shipyard2";
	Locations[n].filespath.textures = "locations\inside\shipyard2\fort";

	//THIS PART IS FOR THE Falaise de Fleur STYLE SHIPYARD(FANCY)	
	Locations[n].models.always.locators = "sh02_l_JRH_fort";		
	Locations[n].models.always.tavern = "sh02";
				
	Locations[n].models.always.window = "sh02_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	
	//THIS PART IS FOR THE Falaise de Fleur STYLE SHIPYARD(FANCY)
	Locations[n].models.day.charactersPatch = "sh02_p";

	//Night

	//THIS PART IS FOR THE Falaise de Fleur STYLE SHIPYARD(FANCY)
	Locations[n].models.night.charactersPatch = "sh02_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\shp_";

	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "Kristiania_fort_stairs";
	Locations[n].reload.l1.emerge = "reload4";

	Locations[n].locators_radius.reload.reload2 = 0.001;	
	
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Kristiania_downhill";
	locations[n].id.label = "Kristiania downhill";
	locations[n].worldmap = "Falaise De Fleur";
	Locations[n].image = "wr_Kr_downhill.tga";

	//Town sack
	Locations[n].townsack = "Khael Roa";

	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\town_04";
	//Locations[n].filespath.textures = "locations\FRANCE";
	//Locations[n].filespath.textures = "locations\ENGLAND";
	//Locations[n].filespath.textures = "locations\SPAIN";
	//Locations[n].filespath.textures = "locations\HOLLAND";
	//Locations[n].filespath.textures = "locations\FRANCE";

	Locations[n].models.always.city = "FF04_swedish";
	Locations[n].models.always.locators = "FF04_l_JRH";
	Locations[n].models.always.grassPatch = "FF04_g";
/*
	Locations[n].models.always.window = "grotto1_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
*/
	//Day
	Locations[n].models.day.fonar = "FF04_fd";
	Locations[n].models.day.charactersPatch = "FF04_p";
	//Night
	Locations[n].models.night.fonar = "FF04_fn";
	Locations[n].models.night.charactersPatch = "FF04_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "Falaise_de_fleur_location_05_04";
	Locations[n].reload.l1.go = "Kristiania_fort";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].reload.l2.name = "Falaise_de_fleur_location_05_01";
	Locations[n].reload.l2.go = "Kristiania_cathedral_passage";
	Locations[n].reload.l2.emerge = "goto2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Nueva Suecia.";

	Locations[n].reload.l5.name = "locator7";
	Locations[n].reload.l5.go = "";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Kristiania Blacksmith. Closed today because of the naval visit.";
	locations[n].reload.l5.disable = 1;

	Locations[n].reload.l6.name = "locator11";
	Locations[n].reload.l6.go = "";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Kristiania Apothecary. Closed because of illness.";
	locations[n].reload.l6.disable = 1;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "spanish_church";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "fort_tower_wall";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "pole1";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "church_window";

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Dungeon_1";
	Locations[n].id = "Kristiania_cathedral_passage";
	locations[n].id.label = "Kristiania cathedral passage";
	Locations[n].image = "wr_Kr_passage.tga";
	
	//Town sack
	Locations[n].townsack = "Khael Roa";

	//Sound
	locations[n].type = "silent_residence";

	//Models
	//Always
	Locations[n].models.always.locators = "d01_l_Q2";
	Locations[n].models.always.house = "d01_white";
	//Day
	Locations[n].models.day.charactersPatch = "d01_p";
	//Night
	Locations[n].models.night.charactersPatch = "d01_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Nueva_Suecia_lower_town";
	Locations[n].reload.l4.emerge = "reload31A";			//was goto201
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].locators_radius.reload.reload4 = 1.2;

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "Kristiania_downhill";
	Locations[n].reload.l5.emerge = "Falaise_de_fleur_location_05_01";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].locators_radius.reload.reload5 = 1.2;

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "gatedoor_KRI";

	Locations[n].locators_radius.randitem.randitem5 = 0.1;
	Locations[n].items.randitem5 = "gatedoor_KRI";

	Locations[n].locators_radius.randitem.randitem6 = 0.1;
	Locations[n].items.randitem6 = "gatedoor_church_stone";

	Locations[n].locators_radius.randitem.randitem7 = 0.1;
	Locations[n].items.randitem7 = "gatedoor_church_stone";

	Locations[n].locators_radius.randitem.randitem9 = 0.1;
	Locations[n].items.randitem9 = "gateroof_church_stone";

	Locations[n].locators_radius.randitem.randitem10 = 0.1;
	Locations[n].items.randitem10 = "gateroof_church_stone";

	Locations[n].locators_radius.randitem.randitem11 = 0.1;
	Locations[n].items.randitem11 = "gateroof_church_stone";

	Locations[n].locators_radius.goto.goto4 = 1.2;

	LAi_LocationFantomsGen(&locations[n], false);
	LAi_LocationMonstersGen(&locations[n], false);

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Kristiania_suburb";
	locations[n].id.label = "Kristiania suburb";
	locations[n].worldmap = "Falaise De Fleur";

	Locations[n].image = "wr_Kr_suburb.tga";

	//Town sack
	Locations[n].townsack = "Khael Roa";

	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	
	//Models
	//Always
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\town_03";

	Locations[n].models.always.city = "FF03_swedish";
	Locations[n].models.always.locators = "FF03_l_JRH";
	Locations[n].models.always.grassPatch = "FF03_g";
	//Day
	Locations[n].models.day.fonar = "FF03_fd";
	Locations[n].models.day.charactersPatch = "FF03_p";
	//Night
	Locations[n].models.night.fonar = "FF03_fn";
	Locations[n].models.night.charactersPatch = "FF03_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "kristiania_center";
	Locations[n].reload.l1.emerge = "reload40";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Center.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Kristiania_swamp_exit";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name#. Slums.";

	Locations[n].reload.l3.name = "Falaise_de_fleur_store";
	Locations[n].reload.l3.go = "";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Magasin is swedish for warehouse. Stay away - the owner.";
	locations[n].reload.l3.disable = 1;

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Kristiania_swamp_exit";
	locations[n].id.label = "Kristiania swamp exit";
	Locations[n].image = "wr_Kr_swampX.tga";

	//Town sack
	Locations[n].townsack = "Khael Roa";
	//Sound
	locations[n].type = "silent_distant_seashore";

	//Models
	//Always
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\exit";
	Locations[n].models.always.jungle = "FFexit_swedish";
	Locations[n].models.always.locators = "FFexit_l_KR";
	Locations[n].models.always.grassPatch = "FFexit_g";
/*	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan_3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
*/
	//Day
	Locations[n].models.day.charactersPatch = "FFexit_p";
	Locations[n].models.day.fonar = "FFexit_fd";
	//Night
	Locations[n].models.night.charactersPatch = "FFexit_p";
	Locations[n].models.night.fonar = "FFexit_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.1;

	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "BB_island1";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 4;
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "Reload2";
	Locations[n].reload.l2.go = "Kristiania_suburb";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name#.";

	Locations[n].reload.l10.name = "Reload1_back";
	Locations[n].reload.l10.go = "BB_island1";
	Locations[n].reload.l10.emerge = "reload1";
	Locations[n].reload.l10.autoreload = "1";
	Locations[n].locators_radius.reload.Reload1_back = 4;
	Locations[n].reload.l10.label = "Jungle.";

	Locations[n].reload.l3.name = "Reload3";
	Locations[n].reload.l3.go = "";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Executioner. Leave me alone.";
	locations[n].reload.l3.disable = 1;

	LAi_LocationMonstersGen(&locations[n], false);
	locations[n].vcskip = true;
	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_7";

	Locations[n].id = "KR_Jungle_1";
	locations[n].id.label = "#sisland_name# jungle";
	Locations[n].image = "wr_Kr_green_swamp.tga";
	//Sound
	locations[n].type = "indian_jungle";
	LAi_LocationMonstersGen(&locations[n], false);
	locations[n].vcskip = true;

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
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.1;
    	Locations[n].environment.swamp2 = "true";
	

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "KR_jungle_3";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1 = 4;

	Locations[n].reload.l5.name = "reload1_back";
	Locations[n].reload.l5.go = "KR_jungle_3";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 1;

	Locations[n].reload.l4.name = "reload2";
	Locations[n].reload.l4.go = "KR_jungle_4";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 4;

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "KR_jungle_4";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Kristiania_jungle_exit";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3 = 4;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Kristiania_jungle_exit";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 2;

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_5";
	Locations[n].id = "KR_jungle_2";
	locations[n].id.label = "#sisland_name# jungles";
	Locations[n].image = "wr_Kr_green_swamp.tga";
	//Sound
	locations[n].type = "indian_jungle";
	LAi_LocationMonstersGen(&locations[n], false);
	locations[n].vcskip = true;

	//Models
	//Always
	Locations[n].models.always.locators = "Jungle05_l";
	//Locations[n].models.always.jungle = "Jungle05";
	Locations[n].models.always.jungle = "jungle05_signless";
	Locations[n].models.always.grassPatch = "JUNGLE05_g";
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
	Locations[n].models.day.charactersPatch = "Jungle05_p";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle05_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.1;
    	Locations[n].environment.swamp2 = "true";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "KR_jungle_5";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1 = 3.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "KR_jungle_6";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2 = 3.0;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Kristiania_jungle_exit";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "To #stown_name#.";
	Locations[n].locators_radius.reload.Reload3 = 3.0;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "KR_jungle_5";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1_back = 2.0;

	Locations[n].reload.l5.name = "reload2_back";
	Locations[n].reload.l5.go = "KR_jungle_6";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2_back = 2.0;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Kristiania_jungle_exit";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "To #stown_name#.";
	Locations[n].locators_radius.reload.Reload3_back = 2.0;

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_4";
	Locations[n].id = "KR_jungle_3";
	locations[n].id.label = "#sisland_name# jungles";
	Locations[n].image = "wr_Kr_green_swamp.tga";
	//Sound
	locations[n].type = "indian_jungle";
	LAi_LocationMonstersGen(&locations[n], false);
	locations[n].vcskip = true;
	
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
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.1;
    	Locations[n].environment.swamp2 = "true";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "KR_jungle_7";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1 = 4;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "KR_jungle_7";
	Locations[n].reload.l4.emerge = "reload3";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "KR_jungle_1";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 4;

	Locations[n].reload.l5.name = "reload2_back";
	Locations[n].reload.l5.go = "KR_jungle_1";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "KR_jungle_7";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3 = 4;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "KR_jungle_7";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 3;

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_3";
	Locations[n].filespath.textures = "locations\JUNGLES";			//huh?
	Locations[n].id = "KR_Jungle_4";
	locations[n].id.label = "#sisland_name# jungle";
	Locations[n].image = "wr_Kr_green_swamp.tga";
	//Sound
	locations[n].type = "indian_jungle";
	LAi_LocationMonstersGen(&locations[n], false);
	locations[n].vcskip = true;

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
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.1;
    	Locations[n].environment.swamp2 = "true";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "KR_jungle_1";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1 = 1.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "KR_jungle_9";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2 = 3.0;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "KR_jungle_8";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload3 = 3.0;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "KR_jungle_1";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l5.name = "reload2_back";
	Locations[n].reload.l5.go = "KR_jungle_9";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3.0;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "KR_jungle_8";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 3.0;

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_3";
	Locations[n].filespath.textures = "locations\JUNGLES";			//huh?
	Locations[n].id = "KR_Jungle_5";
	locations[n].id.label = "#sisland_name# jungle";
	Locations[n].image = "wr_Kr_green_swamp.tga";
	//Sound
	locations[n].type = "indian_jungle";
	LAi_LocationMonstersGen(&locations[n], false);
	locations[n].vcskip = true;

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
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.1;
    	Locations[n].environment.swamp2 = "true";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "KR_jungle_2";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1 = 1.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "KR_jungle_10";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2 = 3.0;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "KR_jungle_9";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload3 = 3.0;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "KR_jungle_2";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l5.name = "reload2_back";
	Locations[n].reload.l5.go = "KR_jungle_10";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3.0;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "KR_jungle_9";
	Locations[n].reload.l6.emerge = "reload3";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 3.0;

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle3";
	Locations[n].id = "KR_jungle_6";
	locations[n].id.label = "Jungle";
	Locations[n].image = "wr_Kr_green_swamp.tga";
	//Sound
	locations[n].type = "indian_jungle";
	LAi_LocationMonstersGen(&locations[n], false);
	locations[n].vcskip = true;

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
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.1;
    	Locations[n].environment.swamp2 = "true";

	//Reload map
    	Locations[n].reload.l1.name = "reload3";
	Locations[n].reload.l1.go = "KR_jungle_11";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle";
	Locations[n].locators_radius.reload.reload3 = 1;

	Locations[n].reload.l2.name = "reload3_back";
	Locations[n].reload.l2.go = "KR_jungle_11";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle";
	Locations[n].locators_radius.reload.reload3_back = 3;

    	Locations[n].reload.l5.name = "reload1";
	Locations[n].reload.l5.go = "KR_jungle_2";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 2.5;
	Locations[n].reload.l5.label = "Jungle";

	Locations[n].reload.l6.name = "reload1_back";
	Locations[n].reload.l6.go = "KR_jungle_2";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 3;
	Locations[n].reload.l6.label = "Jungle";

   	Locations[n].reload.l7.name = "reload2";
	Locations[n].reload.l7.go = "KR_jungle_11";
	Locations[n].reload.l7.emerge = "reload3";
	Locations[n].reload.l7.autoreload = "1";
	Locations[n].reload.l7.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 1;

	Locations[n].reload.l8.name = "reload2_back";
	Locations[n].reload.l8.go = "KR_jungle_11";
	Locations[n].reload.l8.emerge = "reload3";
	Locations[n].reload.l8.autoreload = "1";
	Locations[n].reload.l8.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3;

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_4";
	Locations[n].id = "KR_jungle_7";
	locations[n].id.label = "#sisland_name# jungles";
	Locations[n].image = "Outside_Jungle_4.tga";
	//Sound
	locations[n].type = "indian_jungle";
	LAi_LocationMonstersGen(&locations[n], false);
	locations[n].vcskip = true;
	
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
//	Locations[n].environment.sea = "true";
//	Locations[n].MaxSeaHeight = 0.1;
//    	Locations[n].environment.swamp2 = "true";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "KR_jungle_3";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Shore.";
	Locations[n].locators_radius.reload.reload1 = 4;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "KR_jungle_3";
	Locations[n].reload.l4.emerge = "reload3";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Shore.";
	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "KR_jungle_12";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Shore.";
	Locations[n].locators_radius.reload.reload2 = 4;

	Locations[n].reload.l5.name = "reload2_back";
	Locations[n].reload.l5.go = "KR_jungle_12";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Shore.";
	Locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "KR_jungle_3";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3 = 4;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "KR_jungle_3";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 3;

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "KR_jungle_8";
	locations[n].id.label = "#sisland_name# jungle";
	Locations[n].image = "Outside_Jungle_6.tga";
	//Sound
	locations[n].type = "indian_jungle";
	LAi_LocationMonstersGen(&locations[n], false);
	locations[n].vcskip = true;

	//Models
	//Always
	Locations[n].filespath.models = "locations\Outside\Jungle_6";
	Locations[n].models.always.locators = "Jungle06_l";
	Locations[n].models.always.jungle = "Jungle06_JRH";
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
	Locations[n].models.always.l4 = "stump";	

	//Day
	Locations[n].models.day.charactersPatch = "Jungle06_p";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle06_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "KR_jungle_16";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 2.5;
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "KR_jungle_4";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload2 = 2.5;
	Locations[n].reload.l2.label = "Jungle.";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "KR_jungle_10";		//later KR_jungle_13 reload3
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.reload3 = 2.5;
	Locations[n].reload.l3.label = "Jungle.";

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "KR_jungle_4";
	Locations[n].reload.l4.emerge = "reload3";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].locators_radius.reload.reload2_back = 2.5;
	Locations[n].reload.l4.label = "Jungle.";

	Locations[n].reload.l5.name = "reload3_back";
	Locations[n].reload.l5.go = "KR_jungle_10";		//later KR_jungle_13 reload3
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].locators_radius.reload.reload3_back = 3;
	Locations[n].reload.l5.label = "Jungle.";

	Locations[n].reload.l6.name = "reload1_back";
	Locations[n].reload.l6.go = "KR_jungle_16";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 2.5;
	Locations[n].reload.l6.label = "Jungle.";

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_QC";
	Locations[n].id = "KR_jungle_9";
	Locations[n].image = "wr_Kr_indian_camp.tga";
	
	//Sound
	locations[n].type = "indian_jungle";
	LAi_LocationMonstersGen(&locations[n], false);
	locations[n].vcskip = true;
	
	//Models
	//Always
	Locations[n].models.always.locators = "QCexit_l_Q2";
	Locations[n].models.always.exit = "QCexit";
	Locations[n].models.always.grassPatch = "QCexit_g";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.donkey1 = "donkey";
	Locations[n].models.always.donkey1.locator.group = "quest";
	Locations[n].models.always.donkey1.locator.name = "donkey1";
	Locations[n].models.always.donkey2 = "donkey";
	Locations[n].models.always.donkey2.locator.group = "quest";
	Locations[n].models.always.donkey2.locator.name = "donkey2";
	Locations[n].models.always.donkey3 = "donkey";
	Locations[n].models.always.donkey3.locator.group = "quest";
	Locations[n].models.always.donkey3.locator.name = "donkey3";
	Locations[n].models.always.donkey4 = "donkey";
	Locations[n].models.always.donkey4.locator.group = "quest";
	Locations[n].models.always.donkey4.locator.name = "donkey4";

	//Day
	Locations[n].models.day.charactersPatch = "QCexit_p";
	//Night
	Locations[n].models.night.charactersPatch = "QCexit_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
    	
	//Reload map
	Locations[n].locators_radius.reload.reload1 = 0.0001;

	Locations[n].reload.l2.name = "Reload2";
	Locations[n].reload.l2.go = "KR_jungle_4";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 3.0;

	Locations[n].reload.l3.name = "Reload3";
	Locations[n].reload.l3.go = "KR_jungle_5";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3 = 3.0;

	Locations[n].reload.l4.name = "Reload2_back";
	Locations[n].reload.l4.go = "KR_jungle_4";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2_back = 2.0;

	Locations[n].reload.l5.name = "Reload3_back";
	Locations[n].reload.l5.go = "KR_jungle_5";
	Locations[n].reload.l5.emerge = "reload3";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload3_back = 2.0;

	Locations[n].locators_radius.box.box1 = 0.0001;
	Locations[n].locators_radius.box.box9 = 0.2;
	Locations[n].locators_radius.box.box10 = 0.2;
	Locations[n].locators_radius.box.box11 = 0.2;
	Locations[n].locators_radius.box.box12 = 0.2;

	Locations[n].locators_radius.goto.ambush = 32.0;
	Locations[n].locators_radius.goto.box9 = 3.0;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "tipi";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "tipi";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "horse_fence";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "horse_fence";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "tipi";

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
	Locations[n].items.randitem14 = "horse_fence";

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "KR_jungle_10";
	locations[n].id.label = "#sisland_name# jungle";
	Locations[n].image = "Outside_Jungle_6.tga";
	//Sound
	locations[n].type = "indian_jungle";
	LAi_LocationMonstersGen(&locations[n], false);
	locations[n].vcskip = true;

	//Models
	//Always
	Locations[n].filespath.models = "locations\Outside\Jungle_6";
	Locations[n].models.always.locators = "Jungle06_l";
	Locations[n].models.always.jungle = "Jungle06_JRH";
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
	Locations[n].models.always.l4 = "stump";	

	//Day
	Locations[n].models.day.charactersPatch = "Jungle06_p";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle06_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "KR_jungle_8";		//later KR_jungle_13 reload1	
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 2.5;
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "KR_jungle_5";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload2 = 2.5;
	Locations[n].reload.l2.label = "Jungle.";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "KR_jungle_16";		
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.reload3 = 2.5;
	Locations[n].reload.l3.label = "Jungle.";

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "KR_jungle_5";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].locators_radius.reload.reload2_back = 2.5;
	Locations[n].reload.l4.label = "Jungle.";

	Locations[n].reload.l5.name = "reload3_back";
	Locations[n].reload.l5.go = "KR_jungle_16";		 
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].locators_radius.reload.reload3_back = 3;
	Locations[n].reload.l5.label = "Jungle.";

	Locations[n].reload.l6.name = "reload1_back";
	Locations[n].reload.l6.go = "KR_jungle_8";		//later KR_jungle_13 reload1	
	Locations[n].reload.l6.emerge = "reload3";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 2.5;
	Locations[n].reload.l6.label = "Jungle.";

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "KR_jungle_11";
	locations[n].id.label = "Jungle";
	Locations[n].filespath.models = "locations\Outside\jungle5"; 
	Locations[n].image = "wr_Kr_green_swamp.tga";
 	//Sound
	locations[n].type = "indian_jungle";
	LAi_LocationMonstersGen(&locations[n], false);
	locations[n].vcskip = true;

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
    	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.1;
    	Locations[n].environment.swamp2 = "true";

    	//Reload map
  	Locations[n].reload.l1.name = "reload1";
    	Locations[n].reload.l1.go = "KR_jungle_14";
    	Locations[n].reload.l1.emerge = "reload2";
   	Locations[n].reload.l1.autoreload = "1";
    	Locations[n].reload.l1.label = "Jungle.";
    	Locations[n].locators_radius.reload.Reload1 = 3.0;

    	Locations[n].reload.l2.name = "reload2";
    	Locations[n].reload.l2.go = "KR_jungle_6";
    	Locations[n].reload.l2.emerge = "reload3";
    	Locations[n].reload.l2.autoreload = "1";
    	Locations[n].reload.l2.label = "Jungle.";
    	Locations[n].locators_radius.reload.Reload2 = 3.0;

    	Locations[n].reload.l4.name = "reload1_back";
    	Locations[n].reload.l4.go = "KR_jungle_14";
    	Locations[n].reload.l4.emerge = "reload2";
    	Locations[n].reload.l4.autoreload = "1";
    	Locations[n].reload.l4.label = "Jungle.";
    	Locations[n].locators_radius.reload.Reload1_back = 2.0;

    	Locations[n].reload.l5.name = "reload2_back";
    	Locations[n].reload.l5.go = "KR_jungle_6";
    	Locations[n].reload.l5.emerge = "reload3";
    	Locations[n].reload.l5.autoreload = "1";
    	Locations[n].reload.l5.label = "Jungle.";
    	Locations[n].locators_radius.reload.Reload2_back = 2.0;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "KR_jungle_6";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3 = 4;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "KR_jungle_6";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 4;

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Shore_2";
	Locations[n].id = "KR_jungle_12";
	locations[n].id.label = "Shore.";
	Locations[n].image = "Town_QC_Port.tga";
	//Sound
	locations[n].type = "indian_seashore";
	LAi_LocationMonstersGen(&locations[n], false);
	locations[n].vcskip = true;

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
	Locations[n].reload.l1.go = "KR_Jungle_7";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 3.0;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "KR_Jungle_7";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3.0;

	Locations[n].locators_radius.reload.reload1 = 0.0001;
	Locations[n].locators_radius.reload.reload3 = 0.0001;
	Locations[n].locators_radius.reload.boat = 0.0001;

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "KR_jungle_13";
	locations[n].id.label = "#sisland_name# jungle";
	Locations[n].image = "Outside_Jungle_6.tga";
	//Sound
	locations[n].type = "indian_jungle";
	LAi_LocationMonstersGen(&locations[n], false);
	locations[n].vcskip = true;

	//Models
	//Always
	Locations[n].filespath.models = "locations\Outside\Jungle_6";
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
	Locations[n].reload.l1.go = "KR_jungle_10";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 2.5;
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Kristiania_jungle_house";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload2 = 2.5;
	Locations[n].reload.l2.label = "Jungle.";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "KR_jungle_8";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.reload3 = 2.5;
	Locations[n].reload.l3.label = "Jungle.";

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Kristiania_jungle_house";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].locators_radius.reload.reload2_back = 2.5;
	Locations[n].reload.l4.label = "Jungle.";

	Locations[n].reload.l5.name = "reload3_back";
	Locations[n].reload.l5.go = "KR_jungle_8";
	Locations[n].reload.l5.emerge = "reload3";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].locators_radius.reload.reload3_back = 3;
	Locations[n].reload.l5.label = "Jungle.";

	Locations[n].reload.l6.name = "reload1_back";
	Locations[n].reload.l6.go = "KR_jungle_10";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 2.5;
	Locations[n].reload.l6.label = "Jungle.";

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Cave Entrance";
	Locations[n].id = "KR_jungle_14";
	locations[n].id.label = "Jungle";
	Locations[n].image = "Outside_Cave_Entrance.tga";
	//Sound
	locations[n].type = "indian_jungle";
	LAi_LocationMonstersGen(&locations[n], false);
	locations[n].vcskip = true;

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
	Locations[n].reload.l1.go = "KR_jungle_15";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Cave.";

	Locations[n].reload.l2.name = "Reload1";
	Locations[n].reload.l2.go = "KR_jungle_15";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Cave.";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "KR_jungle_11";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 2.0;

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "KR_jungle_11";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 2.0;

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Grot";
	Locations[n].id = "KR_jungle_15";
	locations[n].id.label = "Hidden Cave";
	Locations[n].image = "Inside_Grot.tga";
	//Sound
	locations[n].type = "KhaelRoa";
	LAi_LocationMonstersGen(&locations[n], false);
	locations[n].vcskip = true;

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
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "KR_jungle_14";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "KR_jungle_14";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "KR_jungle_16";
	locations[n].id.label = "Jungle";
	Locations[n].filespath.models = "locations\Outside\jungle_8";
	Locations[n].image = "Outside_Jungle_8.tga";
 	//Sound
	locations[n].type = "indian_jungle";
	//LAi_LocationMonstersGen(&locations[n], true);
	//LAi_LocationSetMonstersTime(&locations[n], 22, 6);

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
	Locations[n].reload.l1.go = "KR_Jungle_8";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle";
	Locations[n].locators_radius.reload.reload1 = 3.0;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "KR_Jungle_8";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "KR_jungle_10";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle";
	Locations[n].locators_radius.reload.reload2 = 3.0;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "KR_jungle_10";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle";
	Locations[n].locators_radius.reload.reload2_back = 2.0;

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_Church";
	Locations[n].id = "Kristiania_jungle_house";
	locations[n].id.label = "Charleston swamp";
	Locations[n].image = "wr_redhouse_outside.tga";
	//Sound
	locations[n].type = "silent_jungle";
	//Models
	//Always
//	Locations[n].models.always.locators = "Rhouse_l_redhouse";
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
//	Locations[n].models.always.l4 = "rhouse_b04";
//	Locations[n].models.always.l4.level = 6;
//	Locations[n].models.always.l4.tech = "LocationModelBlend";

	Locations[n].models.always.l5 = "redhouse";

	locations[n].vcskip = true; // PB
	//Day
	Locations[n].models.day.charactersPatch = "Rhouse_p";
	Locations[n].models.day.locators = "Rhouse_l_redhouse_day";
//	Locations[n].models.day.fonar = "redhouse_fd";
	//Night
	Locations[n].models.night.charactersPatch = "Rhouse_p";
	Locations[n].models.night.locators = "Rhouse_l_redhouse_night";
//	Locations[n].models.night.fonar = "redhouse_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "KR_jungle_13";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "KR_jungle_13";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].reload.l2.name = "Reload2";
	Locations[n].reload.l2.go = "Redhouse_entre";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Red house.";
	Locations[n].locators_radius.reload.reload2 = 0.2;

	Locations[n].locators_radius.box.box2 = 0.2;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "wagon";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "loghouse";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "loghouse";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "loghouse";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "1_lanternE_day";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "1_lanternE_day";

	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "ladder_biggest";

	Locations[n].locators_radius.randitem.randitem8 = 0.01;
	Locations[n].items.randitem8 = "1_lanternE_day";

	Locations[n].locators_radius.randitem.randitem9 = 0.01;
	Locations[n].items.randitem9 = "1_lanternE_day";

	Locations[n].locators_radius.randitem.randitem10 = 0.01;
	Locations[n].items.randitem10 = "1_lanternE_night";

	Locations[n].locators_radius.randitem.randitem11 = 0.01;
	Locations[n].items.randitem11 = "1_lanternE_night";

	Locations[n].locators_radius.randitem.randitem12 = 0.01;
	Locations[n].items.randitem12 = "1_lanternE_night";

	Locations[n].locators_radius.randitem.randitem13 = 0.01;
	Locations[n].items.randitem13 = "1_lanternE_night";

	LAi_LocationMonstersGen(&locations[n], false);
	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Redhouse_entre";
	locations[n].id.label = "Hall";
	Locations[n].filespath.models = "locations\inside\flamhouse";
	
	Locations[n].image = "wr_redhouse_hall.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	//locations[n].type = "house";
	locations[n].type = "Rogers_residence";

	//Models
	//Always
	Locations[n].models.always.locators = "WoodHouse_locators";
	Locations[n].models.always.tavern = "Woodhouse";
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
	Locations[n].models.back = "back\juch_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Kristiania_jungle_house";
	Locations[n].reload.l1.emerge = "reload3";				//was box2
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 0.5;

	//private
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Private";
	Locations[n].locators_radius.reload.reload2 = 0.5;
	locations[n].reload.l2.disable = 1;

	//office
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "BB_Eden_office";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].locators_radius.reload.reload3 = 0.5;
	locations[n].reload.l3.disable = 1;

	//bedroom
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "QC_store_bedroom";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].locators_radius.reload.reload4 = 0.5;	
	locations[n].reload.l4.disable = 1;

	//dining room
	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "BB_Eden_dining_room";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].locators_radius.reload.reload6 = 0.5;
	locations[n].reload.l6.disable = 1;
			
	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "Redhouse_room";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].locators_radius.reload.reload5 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "door_N03";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "door_N03";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "door_N03";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "door_N03";			//half covered window

	Locations[n].locators_radius.randitem.randitem5 = 0.1;
	Locations[n].items.randitem5 = "door_N03";			//covered new window

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "gatedoor_vsmall_GN3";

	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "gatedoor_vsmall_GN3R";

	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.5;

	Locations[n].locators_radius.goto.goto6 = 1.5;
	Locations[n].locators_radius.goto.goto7 = 1.0;

	Locations[n].island = "KhaelRoa";
	LAi_LocationFightDisable(&Locations[n], true);
	n = n + 1;

	//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Residence3";
	Locations[n].filespath.textures = "locations\inside\Residence3\jrh";

	Locations[n].id = "Redhouse_room";
	locations[n].id.label = "Living Room";
	Locations[n].image = "wr_redhouse_livingroom.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Rogers_residence";

	//Models
	//Always
	Locations[n].models.always.locators = "Res03_l_Q2";
	Locations[n].models.always.l1 = "Res03";
	Locations[n].models.always.window = "Res03_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	Locations[n].models.always.l2 = "ceiling";
	Locations[n].models.always.l3 = "bookshelf_white";
	Locations[n].models.always.l4 = "doors_jrh";

	//Day
	Locations[n].models.day.charactersPatch = "Res03_p";

	//Night
	Locations[n].models.night.charactersPatch = "Res03_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\juch2_";

	//Reload map
	//bedroom
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "QC_store_bedroom";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 0.5;	
	locations[n].reload.l1.disable = 1;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Redhouse_entre";
	Locations[n].reload.l2.emerge = "reload5";		
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 0.6;

	Locations[n].locators_radius.goto.goto8 = 0.7;
	Locations[n].locators_radius.box.box1 = 1.0;
	Locations[n].locators_radius.box.box2 = 1.0;
	Locations[n].locators_radius.box.box3 = 0.7;
	Locations[n].locators_radius.box.box4 = 0.7;
	Locations[n].locators_radius.box.box5 = 0.7;
	Locations[n].locators_radius.box.box6 = 0.7;

	Locations[n].locators_radius.randitem.randitem1 = 0.0001;
	Locations[n].items.randitem1 = "carpet4S";
	
	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "KhaelRoa";
	n = n + 1;

//============================================================================

	Locations[n].filespath.models = "locations\Outside\Jungle_7";

	Locations[n].id = "BB_island1";
	locations[n].id.label = "Jungle";
	Locations[n].image = "wr_Kr_swamp.tga";
	//Sound
	locations[n].type = "silent_seashore";
	
	//Models
	//Always
	Locations[n].models.always.locators = "Jungle07_l_JRH";
	Locations[n].models.always.jungle = "Jungle07";
	Locations[n].models.always.l1 = "";			//later blade1
	Locations[n].models.always.grassPatch = "JUNGLE07_g";

	//Day
	Locations[n].models.day.charactersPatch = "Jungle07_p";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle07_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.4;

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Kristiania_swamp_exit";	
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 4;

	Locations[n].reload.l10.name = "reload1_back";		//same spot
	Locations[n].reload.l10.go = "Kristiania_swamp_exit";	
	Locations[n].reload.l10.emerge = "reload1";
	Locations[n].reload.l10.autoreload = "1";
	Locations[n].locators_radius.reload.reload10_back = 1;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "BB_island2";	
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload2 = 4;

	Locations[n].reload.l20.name = "reload2_back";
	Locations[n].reload.l20.go = "BB_island2";	
	Locations[n].reload.l20.emerge = "reload2";
	Locations[n].reload.l20.autoreload = "1";
	Locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "BB_island2";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3 = 4;

	Locations[n].reload.l30.name = "reload3_back";
	Locations[n].reload.l30.go = "BB_island2";
	Locations[n].reload.l30.emerge = "reload1";
	Locations[n].reload.l30.autoreload = "1";
	Locations[n].reload.l30.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 2;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "BB_mountain_tunnel";
	Locations[n].reload.l4.emerge = "goto1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.reload4 = 0.2;

	Locations[n].locators_radius.box.box2 = 0.2;
	Locations[n].locators_radius.box.box3 = 0.2;
	Locations[n].locators_radius.box.box4 = 0.2;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "ladder_very_big";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "ladder_very_big";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "raft2_ropes";				//between ladders

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
//	Locations[n].items.randitem4 = "";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "raft2_ropes";				//top

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "blockdoor";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "steplock_v";

	LAi_LocationMonstersGen(&locations[n], false);

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Dungeon_3";
	Locations[n].id = "BB_mountain_tunnel";
	Locations[n].image = "wr_BB_mountain.tga";
	locations[n].id.label = "Port Royal old mine";

	//Sound
	locations[n].type = "Rogers_mine";
	//Models
	Locations[n].models.back = "back\d03env_";
	//Always
	Locations[n].models.always.locators = "d03_l_JRH_BB";
	Locations[n].models.always.house = "d03";
	
	//Day
	Locations[n].models.day.charactersPatch = "d03_p";
	//Night
	Locations[n].models.night.charactersPatch = "d03_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	//
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_island1";
	Locations[n].reload.l1.emerge = "box3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1 = 1.0;

	//
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "BB_island2";
	Locations[n].reload.l2.emerge = "box1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 1.0;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "gatedoor_Mine_light";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "gatedoor_Mine_light";	

	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------	
	Locations[n].filespath.models = "locations\Outside\Jungle_1";

	Locations[n].id = "BB_island2";
	locations[n].id.label = "#sisland_name# jungle";
	Locations[n].image = "wr_BB_tower.tga";
	
	Locations[n].townsack = "Grand Turk"; 					//needed for pirate flag

	//Sound
	locations[n].type = "Blackbeard_shore";

	//Models
	//Always
	Locations[n].models.always.locators = "jungle01_l_JRH";			//start without any flag raised
	Locations[n].models.always.jungle = "jungle01";
	Locations[n].models.always.l1 = "";					//later blade2
	Locations[n].models.always.grassPatch = "jungle01_g";

	//Day
	Locations[n].models.day.charactersPatch = "jungle01_p";
	//Night
	Locations[n].models.night.charactersPatch = "jungle01_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.2;

	//Reload map

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_island1";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1 = 3.0;

	Locations[n].reload.l10.name = "reload1_back";
	Locations[n].reload.l10.go = "BB_island1";
	Locations[n].reload.l10.emerge = "reload3";
	Locations[n].reload.l10.autoreload = "1";
	Locations[n].reload.l10.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "BB_island1";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Shore.";
	Locations[n].locators_radius.reload.Reload2 = 3.0;

	Locations[n].reload.l20.name = "reload2_back";
	Locations[n].reload.l20.go = "BB_island1";
	Locations[n].reload.l20.emerge = "Reload2";
	Locations[n].reload.l20.autoreload = "1";
	Locations[n].reload.l20.label = "Shore.";
	Locations[n].locators_radius.reload.reload2_back = 2.0;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "BB_tower";
	Locations[n].reload.l4.emerge = "goto4";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload4 = 0.1;

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "BB_mountain_tunnel";
	Locations[n].reload.l5.emerge = "goto2";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload5 = 0.2;
/*
	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "BB_tower";
	Locations[n].reload.l6.emerge = "goto1";	
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload6 = 0.3;
*/
	Locations[n].locators_radius.box.box1 = 0.2;
	Locations[n].locators_radius.box.box2 = 0.1;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.2;
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.box.box6 = 0.3;
	Locations[n].locators_radius.box.box7 = 0.1;

	Locations[n].locators_radius.goto.box2 = 0.1;
	Locations[n].locators_radius.goto.box7 = 0.1;
	
	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "blockdoor";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "suspension_bridge";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "ellipse_tower";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "blockdoor";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "hatch11";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "pole1";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "tourist_spyglass";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "steplock_v";

	LAi_LocationMonstersGen(&locations[n], false);
	//Locations[n].island = "KhaelRoa";
	Locations[n].island = "Turks";			//doesn't matter for pirate flag
	n = n + 1;
//--------------------------------------------------------------------------
	
   	Locations[n].filespath.models = "locations\Fort_Inside\FortVRight";
	
    	Locations[n].id = "BB_tower";
	locations[n].id.label = "Blackbeard's tower";
	Locations[n].image = "wr_BB_tower_inside.tga";

	//Town sack
	Locations[n].townsack = "Khael Roa";

	//Sound
	locations[n].type = "Rogers_cellar";

	//Models
	//Always
	Locations[n].models.always.locators = "FortVRight_locators_JRH";
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
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	locations[n].environment.weather.rain = false;

    	//Reloadmap
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "BB_island2";
	Locations[n].reload.l3.emerge = "box2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3 = 0.7;
/*
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "BB_island2";
	Locations[n].reload.l4.emerge = "box5";				//was reload6
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Jungle.";
	//Locations[n].locators_radius.reload.reload4 = 0.8;
	Locations[n].locators_radius.reload.reload4 = 0.5;
*/
	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "BB_upper_cave";
	Locations[n].reload.l5.emerge = "box2";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Grot";
	Locations[n].locators_radius.reload.reload5 = 0.7;			//small when water is pumped out	

	Locations[n].locators_radius.goto.goto2 = 0.001;			//0.7 when water is pumped out	
	Locations[n].locators_radius.box.box4 = 0.5;	

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "ladder_big";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "gatedoor_tower";		

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "gatedoor_tower";	

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "gatedoor_tower_45";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "hatch11D";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "door_N";

	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "door_N10";		

	Locations[n].island = "KhaelRoa";
    	n = n + 1;

//  -------------------------------------------------

	locations[n].id = "BB_upper_cave";
	locations[n].id.label = "Grot";
    	locations[n].image = "wr_BB_upper_cave.tga";
	//Sound
	locations[n].type = "silent_cave_seashore";
	
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\grotto1";
	locations[n].models.always.grotto1 = "grotto1";
	Locations[n].models.always.l1 = "bars_down";
	Locations[n].models.always.l2 = "pinion_small_H";
	Locations[n].models.always.l3 = "girder_free2";				//or girder_block2
	locations[n].models.always.grotto1alpha = "grotto1_alpha";
	Locations[n].models.always.grotto1alpha.tech = "LocationWindows";	
	locations[n].models.always.grotto1alpha.level = 65532;	
	locations[n].models.always.locators = "grotto1_l_Hup_st";		//start case

	//reload
	Locations[n].models.always.window = "grotto1_w";			//start case
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;

	//Day
	locations[n].models.day.charactersPatch = "grotto1_patch";	
	//Night
	locations[n].models.night.charactersPatch = "grotto1_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	locations[n].environment.weather.rain = false;
	Locations[n].MaxSeaHeight = 0.2;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "BB_tower";
	locations[n].reload.l1.emerge = "goto3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Grot";
	Locations[n].locators_radius.reload.reload1 = 0.5;

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "BB_lower_cave";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Grot";
	Locations[n].locators_radius.reload.reload2 = 0.6;

	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.box.box6 = 0.5;
	Locations[n].locators_radius.box.box7 = 0.5;
	Locations[n].locators_radius.box.box8 = 0.5;
	Locations[n].locators_radius.box.box9 = 0.5;
	Locations[n].locators_radius.box.box10 = 0.8;
	Locations[n].locators_radius.box.box14 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "L_bridge";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "ladder_very_big";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "hammock";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "steplock_v3";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "stoneblock";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "lever3_down";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "lilgun";			//pointing at door

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "hatch11_S";			//open hatch

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "hatch11";			//closed hatch

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "lever3_up";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "gatedoor_tower";

	Locations[n].locators_radius.randitem.randitem12 = 0.01;
	Locations[n].items.randitem12 = "door_N10";

	Locations[n].locators_radius.randitem.randitem13 = 0.01;
	Locations[n].items.randitem13 = "ropes_blocks";			//ropes to open hatch
	
	Locations[n].locators_radius.randitem.randitem14 = 0.001;
	Locations[n].items.randitem14 = "ropes_blocks";			//ropes to closed hatch

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	Locations[n].items.randitem15 = "hatch11V";			//vertical hatch

	Locations[n].locators_radius.randitem.randitem16 = 0.001;
	Locations[n].items.randitem16 = "fireplace_wood";

	Locations[n].locators_radius.randitem.randitem17 = 0.001;
	Locations[n].items.randitem17 = "lilgun";			//pointing at window

	Locations[n].locators_radius.randitem.randitem18 = 0.0001;
	Locations[n].items.randitem18 = "bookcase";

	Locations[n].locators_radius.randitem.randitem19 = 0.0001;
	Locations[n].items.randitem19 = "cauldron1";

	Locations[n].locators_radius.randitem.randitem20 = 0.0001;
	Locations[n].items.randitem20 = "stool";

	Locations[n].locators_radius.randitem.randitem21 = 0.0001;
	Locations[n].items.randitem21 = "boom_item";			//pointing at window

	Locations[n].locators_radius.randitem.randitem22 = 0.0001;
	Locations[n].items.randitem22 = "books1";

	Locations[n].locators_radius.randitem.randitem23 = 0.0001;
	Locations[n].items.randitem23 = "rum_party1";

	Locations[n].locators_radius.randitem.randitem24 = 0.0001;
	Locations[n].items.randitem24 = "boom_item";			//pointing at door

	Locations[n].locators_radius.randitem.randitem25 = 0.0001;
	Locations[n].items.randitem25 = "book45";

	Locations[n].locators_radius.randitem.randitem26 = 0.0001;
	Locations[n].items.randitem26 = "book49";

	Locations[n].locators_radius.randitem.randitem27 = 0.0001;
	Locations[n].items.randitem27 = "book42";			

	Locations[n].locators_radius.randitem.randitem28 = 0.0001;
	Locations[n].items.randitem28 = "armchair02";			

	Locations[n].locators_radius.randitem.randitem29 = 0.001;
	Locations[n].items.randitem29 = "chest1";

	Locations[n].locators_radius.randitem.randitem30 = 0.1;
	Locations[n].items.randitem30 = "bladebarrel";

	Locations[n].locators_radius.randitem.randitem31 = 0.001;
	Locations[n].items.randitem31 = "bigfish";

	//boat items---------------------------------------------

	Locations[n].locators_radius.randitem.randitem32 = 0.001;
	Locations[n].items.randitem32 = "cherub";

	Locations[n].locators_radius.randitem.randitem33 = 0.001;
	Locations[n].items.randitem33 = "sack3";

	Locations[n].locators_radius.randitem.randitem34 = 0.001;
	Locations[n].items.randitem34 = "sack3";

	Locations[n].locators_radius.randitem.randitem35 = 0.001;
	Locations[n].items.randitem35 = "sack3";

	Locations[n].locators_radius.randitem.randitem36 = 0.001;
	Locations[n].items.randitem36 = "sack3";

	Locations[n].locators_radius.randitem.randitem37 = 0.001;
	Locations[n].items.randitem37 = "sack3";

	Locations[n].locators_radius.randitem.randitem38 = 0.001;
	Locations[n].items.randitem38 = "sack3";

	Locations[n].locators_radius.randitem.randitem39 = 0.001;
	Locations[n].items.randitem39 = "chest_BB1";

	Locations[n].locators_radius.randitem.randitem40 = 0.001;
	Locations[n].items.randitem40 = "sack3";

	Locations[n].island = "KhaelRoa";
	n = n + 1;

// -------------------------------------------------
	//flooded cave
	locations[n].id = "BB_lower_cave";
	locations[n].id.label = "Grot";
    	locations[n].image = "wr_BB_lower_cave.tga";
	//Sound
	locations[n].type = "silent_cave_seashore";

	//Models
	//Always
	locations[n].filespath.models = "locations\inside\grotto2";
	locations[n].models.always.grotto2 = "grotto2";
	Locations[n].models.always.l1 = "bars_down";
	locations[n].models.always.grotto2.sea_reflection = 1;
	locations[n].models.always.grotto2alpha = "grotto2_alpha";
	Locations[n].models.always.grotto2alpha.tech = "LocationWindows";	
	locations[n].models.always.grotto2alpha.level = 65532;	
	locations[n].models.always.locators = "grotto2_l_flood";	

	Locations[n].models.always.church = "church";
	Locations[n].models.always.church.locator.group = "upgrades";
	Locations[n].models.always.church.locator.name = "church";

	//Day
	locations[n].models.day.charactersPatch = "grotto2_patch";
	//Night
	locations[n].models.night.charactersPatch = "grotto2_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	locations[n].environment.weather.rain = false;
	Locations[n].MaxSeaHeight = 0.2;
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "BB_upper_cave";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Grot";
	Locations[n].locators_radius.reload.reload1 = 1.0;

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "BB_burning_cave";
	locations[n].reload.l2.emerge = "arrive";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Grot";
	Locations[n].locators_radius.reload.reload2 = 0.8;

	Locations[n].locators_radius.box.box1 = 0.001;		//start

	Locations[n].locators_radius.box.box2 = 0.001;		//not used
	Locations[n].locators_radius.box.box3 = 0.001;		
	Locations[n].locators_radius.box.box4 = 0.001;
	Locations[n].locators_radius.box.box5 = 0.001;

	//4 groups of heavy chests
	Locations[n].locators_radius.box.box6 = 1.0;
	Locations[n].locators_radius.box.box7 = 0.7;
	Locations[n].locators_radius.box.box8 = 0.7;
	Locations[n].locators_radius.box.box9 = 0.7;

	//idol
	Locations[n].locators_radius.box.box10 = 0.001;		//0.9 when snakewand is p.u.

	//2 groups of sacks
	Locations[n].locators_radius.box.box11 = 0.8;
	Locations[n].locators_radius.box.box12 = 0.8;

	//at painting
	Locations[n].locators_radius.box.box15 = 0.6;
	Locations[n].locators_radius.quest.no_fight = 1.7;

	Locations[n].locators_radius.goto.fanfare = 1.0;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "gatedoor_stone";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "hatch11D";			//closed hatch

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "hatch11D_O";			//open hatch

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "gateroof_wood";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "rig";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "gatedoor_tower";
	
	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "door_fort";

	Locations[n].locators_radius.randitem.randitem8 = 0.01;
	Locations[n].items.randitem8 = "steplock2";



	Locations[n].locators_radius.randitem.randitem9 = 0.01;
	Locations[n].items.randitem9 = "chest_BB1";

	Locations[n].locators_radius.randitem.randitem10 = 0.01;
	Locations[n].items.randitem10 = "chest_BB2";

	Locations[n].locators_radius.randitem.randitem11 = 0.01;
	Locations[n].items.randitem11 = "chest_BB3";

	Locations[n].locators_radius.randitem.randitem12 = 0.01;
	Locations[n].items.randitem12 = "chest5_coas";

	Locations[n].locators_radius.randitem.randitem13 = 0.01;
	Locations[n].items.randitem13 = "chest_BB1";

	Locations[n].locators_radius.randitem.randitem14 = 0.01;
	Locations[n].items.randitem14 = "chest_BB2";

	Locations[n].locators_radius.randitem.randitem15 = 0.01;
	Locations[n].items.randitem15 = "chest_BB3";

	Locations[n].locators_radius.randitem.randitem16 = 0.01;
	Locations[n].items.randitem16 = "chest_BB2";

	Locations[n].locators_radius.randitem.randitem17 = 0.001;
	Locations[n].items.randitem17 = "cherub";

	Locations[n].locators_radius.randitem.randitem18 = 0.01;
	Locations[n].items.randitem18 = "2_sacks";

	Locations[n].locators_radius.randitem.randitem19 = 0.01;
	Locations[n].items.randitem19 = "4_sacks";

	Locations[n].locators_radius.randitem.randitem20 = 0.01;
	Locations[n].items.randitem20 = "2_sacks";

	Locations[n].locators_radius.randitem.randitem21 = 0.01;
	Locations[n].items.randitem21 = "4_sacks";

	Locations[n].locators_radius.randitem.randitem22 = 0.01;
	Locations[n].items.randitem22 = "FransHals_frame45";

	Locations[n].locators_radius.randitem.randitem23 = 0.01;		//1.1 later
	Locations[n].items.randitem23 = "FransHals_45";

	Locations[n].locators_radius.randitem.randitem24 = 0.01;		//1.3 later
	Locations[n].items.randitem24 = "book71_9_start";

	Locations[n].locators_radius.randitem.randitem25 = 0.01;
	Locations[n].items.randitem25 = "key8";					//not used

	Locations[n].locators_radius.randitem.randitem26 = 0.01;
	Locations[n].items.randitem26 = "key8";					//not used
	
	Locations[n].locators_radius.randitem.randitem27 = 0.01;
	Locations[n].items.randitem27 = "key8";					//not used

	Locations[n].locators_radius.randitem.randitem28 = 0.01;
	Locations[n].items.randitem28 = "key8";					//not used

	Locations[n].locators_radius.randitem.randitem29 = 0.01;
	Locations[n].items.randitem29 = "key8";					//not used

	Locations[n].locators_radius.randitem.randitem30 = 1.5;
	Locations[n].items.randitem30 = "book73_closed";

	Locations[n].locators_radius.randitem.randitem31 = 0.01;
	Locations[n].items.randitem31 = "chest_BB2";

	Locations[n].locators_radius.randitem.randitem32 = 1.0;
	Locations[n].items.randitem32 = "boom_item";

	Locations[n].locators_radius.randitem.randitem33 = 0.001;
	Locations[n].items.randitem33 = "hatch7";

	Locations[n].locators_radius.randitem.randitem34 = 0.001;
	Locations[n].items.randitem34 = "mtoon_item";

	Locations[n].locators_radius.randitem.randitem35 = 0.001;
	Locations[n].items.randitem35 = "mtoon_item";

	Locations[n].locators_radius.randitem.randitem36 = 1.0;
	Locations[n].items.randitem36 = "censer_item";

//	Locations[n].locators_radius.randitem.randitem37 = 0.001;
	Locations[n].items.randitem37 = "snakewand";

	Locations[n].rats = "true";
	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "KhaelRoa";
	n = n + 1;

// -------------------------------------------------

	locations[n].id = "BB_burning_cave";
//	locations[n].id.label = "Grot";
	locations[n].id.label = "into the unknown...";
    	locations[n].image = "wr_unknown1.tga";
	//Sound
	locations[n].type = "silent_burning_cave";				//later "burning_cave" (music)

	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Dungeon_5";
	locations[n].models.always.grotto2 = "d05_fake";			//a barrel as placeholder
	Locations[n].models.always.l1 = "fetters";
	Locations[n].models.always.l2 = "cross";	//best as add
	Locations[n].models.always.l3 = "estate_fd";
	Locations[n].models.always.l4 = "Indian_totem1";

	locations[n].models.always.locators = "locator";
//	locations[n].models.always.locators = "locator_high";

	Locations[n].models.always.d05 = "d05";
	Locations[n].models.always.d05.locator.group = "upgrades";
	Locations[n].models.always.d05.locator.name = "d05";

	Locations[n].models.always.floor = "floor";
	Locations[n].models.always.floor.locator.group = "upgrades";
	Locations[n].models.always.floor.locator.name = "floor";

	Locations[n].models.always.churchdoor = "churchdoor";
	Locations[n].models.always.churchdoor.locator.group = "upgrades";
	Locations[n].models.always.churchdoor.locator.name = "churchdoor";

	Locations[n].models.always.porches = "porches";
	Locations[n].models.always.porches.locator.group = "upgrades";
	Locations[n].models.always.porches.locator.name = "porches";

	Locations[n].models.always.estate_facade = "estate_facade";
	Locations[n].models.always.estate_facade.locator.group = "upgrades";
	Locations[n].models.always.estate_facade.locator.name = "estate_facade";
	
	Locations[n].models.always.chimneys = "chimneys";
	Locations[n].models.always.chimneys.locator.group = "upgrades";
	Locations[n].models.always.chimneys.locator.name = "chimneys";

	Locations[n].models.always.cages = "cages";
	Locations[n].models.always.cages.locator.group = "upgrades";
	Locations[n].models.always.cages.locator.name = "cages";

	Locations[n].models.always.choirchairsL = "choirchairsL";
	Locations[n].models.always.choirchairsL.locator.group = "upgrades";
	Locations[n].models.always.choirchairsL.locator.name = "choirchairsL";

	Locations[n].models.always.choirchairsR = "choirchairsR";
	Locations[n].models.always.choirchairsR.locator.group = "upgrades";
	Locations[n].models.always.choirchairsR.locator.name = "choirchairsR";

	Locations[n].models.always.benchesL1 = "benchesL1";
	Locations[n].models.always.benchesL1.locator.group = "upgrades";
	Locations[n].models.always.benchesL1.locator.name = "benchesL1";

	Locations[n].models.always.benchesL2 = "benchesL2";
	Locations[n].models.always.benchesL2.locator.group = "upgrades";
	Locations[n].models.always.benchesL2.locator.name = "benchesL2";

	Locations[n].models.always.benchesR1 = "benchesR1";
	Locations[n].models.always.benchesR1.locator.group = "upgrades";
	Locations[n].models.always.benchesR1.locator.name = "benchesR1";

	Locations[n].models.always.benchesR2 = "benchesR2";
	Locations[n].models.always.benchesR2.locator.group = "upgrades";
	Locations[n].models.always.benchesR2.locator.name = "benchesR2";

	//Day
	locations[n].models.day.charactersPatch = "walk_patch_SHORT";
	//locations[n].models.day.charactersPatch = "walk_patch_LONG";
	//locations[n].models.day.charactersPatch = "walk_patch_HIGH";

	//Night
	locations[n].models.night.charactersPatch = "walk_patch_SHORT";
	//locations[n].models.night.charactersPatch = "walk_patch_LONG";
	//locations[n].models.night.charactersPatch = "walk_patch_HIGH";

	//Environment
	locations[n].environment.weather = "false";
	locations[n].environment.sea = "false";
	
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "BB_lower_cave";
	locations[n].reload.l1.emerge = "goto1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Grot";
	Locations[n].locators_radius.reload.reload1 = 1.0;
//	locations[n].reload.l1.disable = 1;				//test open and stays open				

	Locations[n].locators_radius.quest.gate1M = 0.7;
	Locations[n].locators_radius.quest.gate1L = 0.7;
	Locations[n].locators_radius.quest.gate1R = 0.7;
	Locations[n].locators_radius.quest.gate2M = 0.7;
	Locations[n].locators_radius.quest.gate2L = 0.7;
	Locations[n].locators_radius.quest.gate2R = 0.7;
	Locations[n].locators_radius.quest.gate3M = 0.7;
	Locations[n].locators_radius.quest.gate3L = 0.9;
	Locations[n].locators_radius.quest.gate3R = 0.7;

	Locations[n].locators_radius.quest.holeL1 = 0.8;
	Locations[n].locators_radius.quest.holeL2 = 0.8;
	Locations[n].locators_radius.quest.holeR1 = 0.7;
	Locations[n].locators_radius.quest.holeR2 = 0.7;
	Locations[n].locators_radius.quest.hell_fire = 4.0;

	Locations[n].locators_radius.goto.guard10 = 1.1;
	Locations[n].locators_radius.goto.guard11 = 1.1;
	Locations[n].locators_radius.goto.mummyC = 0.7;
	Locations[n].locators_radius.goto.mummyS = 1.0;
	Locations[n].locators_radius.goto.hole1 = 3.0;

	Locations[n].locators_radius.box.box4 = 0.1;
	Locations[n].locators_radius.box.box6 = 0.2;
	Locations[n].locators_radius.box.box8 = 0.2;
	Locations[n].locators_radius.box.box9 = 0.2;
	Locations[n].locators_radius.box.box10 = 0.0001;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "gibbet_high";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "IronMaiden";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "AltarPicture_big";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "ladder_very_big";			//start pos prison1

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "prison_bars_big";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "guillotine";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "chest6U_vco";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "green2";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "chest6U_vco";

	Locations[n].items.randitem10 = "chair";				 //start pos

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "chair";				 //new pos

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "gatedoor";

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "gatedoor_open";

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
	Locations[n].items.randitem14 = "irongates";

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	Locations[n].items.randitem15 = "ladder_very_big";			//new pos prison2		

	Locations[n].locators_radius.randitem.randitem16 = 0.001;
	Locations[n].items.randitem16 = "chest6U_vco";

	Locations[n].items.randitem17 = "toolbox_item";

	Locations[n].locators_radius.randitem.randitem18 = 0.001;
//	Locations[n].items.randitem18 = "chest_BB3";
	Locations[n].items.randitem18 = "chest6U_vco";

	Locations[n].locators_radius.randitem.randitem19 = 0.001;
	Locations[n].items.randitem19 = "ladder_very_big";			//"wrong" pos prison1

	Locations[n].locators_radius.randitem.randitem20 = 0.001;
	Locations[n].items.randitem20 = "chair";				//last pos

	Locations[n].locators_radius.randitem.randitem21 = 0.001;
	Locations[n].items.randitem21 = "ladder_very_big";			//last pos, on top of chair

	Locations[n].locators_radius.randitem.randitem22 = 0.001;
	Locations[n].items.randitem22 = "irongates_open";

	Locations[n].rats = "true";
	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "KhaelRoa";
	n = n + 1;

// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Passage";

	Locations[n].id = "meditation_path";
	locations[n].id.label = "";
	Locations[n].image = "";
	//Sound
	locations[n].type = "Claire_outside";

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

	LAi_LocationFantomsGen(&locations[n], false);
	Locations[n].vcskip = true;
	Locations[n].monsters = 0;
	
	Locations[n].locators_radius.randitem.randitem1 = 0.01;

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "IslaMuelle"; // NK 04-08-29
	n = n + 1;

// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Isle";

	Locations[n].id = "BB_isle";
	locations[n].id.label = "Islet";
	Locations[n].image = "wr_isle.tga";
	//Sound
//	locations[n].type = "Blackbeard_shore";
	locations[n].type = "Rogers_ships";

	//Models
	//Always
	Locations[n].models.always.locators = "isle_l_JRH";
	Locations[n].models.always.jungle = "isle";

	//Day
	Locations[n].models.day.charactersPatch = "isle_p";
	//Night
	Locations[n].models.night.charactersPatch = "isle_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	
	Locations[n].locators_radius.box.box1 = 3.0;
	Locations[n].locators_radius.box.box2 = 2.0;
//	Locations[n].locators_radius.goto.chimney = 2.0;
	
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_isle_passage";
    	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	locations[n].reload.l1.disable = 1;				//locked from start

	Locations[n].locators_radius.randitem.randitem1 = 0.0001;
	Locations[n].items.randitem1 = "small_hut";

	Locations[n].locators_radius.randitem.randitem2 = 0.0001;
	Locations[n].items.randitem2 = "door_largeh2";

	Locations[n].locators_radius.randitem.randitem3 = 0.0001;
	Locations[n].items.randitem3 = "hut3_C";

	Locations[n].locators_radius.randitem.randitem4 = 0.0001;
	Locations[n].items.randitem4 = "boat4";

	Locations[n].locators_radius.randitem.randitem5 = 0.0001;
	Locations[n].items.randitem5 = "cannon2";

	Locations[n].locators_radius.randitem.randitem6 = 0.0001;
	Locations[n].items.randitem6 = "fishingnet";

	Locations[n].island = "KhaelRoa";
	n = n + 1;

	//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Hut_attic";
	locations[n].id = "BB_isle_passage";
	locations[n].id.label = "Passage";
	Locations[n].image = "wr_isle_hut1.tga";
	//Sound
	locations[n].type = "silent_cave_seashore";
	//Models
	//Always
	Locations[n].models.always.locators = "Hut_attic_locators_isle";
	Locations[n].models.always.l1 = "Hut_attic";
	Locations[n].models.always.l2 = "Hut_attic_barrels";

	//Day
	Locations[n].models.day.charactersPatch = "Hut_attic_patch";

	//Night
	Locations[n].models.night.charactersPatch = "Hut_attic_patch";
	Locations[n].models.night.fonar = "Hut_attic_cloth";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Locations[n].models.back = "back\juch_";

	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "BB_isle";
	locations[n].reload.l1.emerge = "goto1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "BB_isle_hut";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "";

	Locations[n].locators_radius.box.box1 = 0.8;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "big_hut";		

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "door_largeh2";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "sandfloor";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "door_largeh2";	

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "door_largeh2";

	Locations[n].locators_radius.randitem.randitem6 = 0.0001;
	Locations[n].items.randitem6 = "toolchest1";

	Locations[n].locators_radius.randitem.randitem7 = 0.0001;
	Locations[n].items.randitem7 = "sack3";

	Locations[n].locators_radius.randitem.randitem8 = 0.0001;
	Locations[n].items.randitem8 = "sack3";

	Locations[n].locators_radius.randitem.randitem9 = 0.0001;
	Locations[n].items.randitem9 = "jars";	
	
	LAi_LocationFightDisable(&Locations[n], true);	
	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;

	//--------------------------------------------------------------------------

	Locations[n].id = "BB_isle_hut";
	locations[n].id.label = "Hideout";
	Locations[n].filespath.models = "locations\inside\Hut_isle";
	Locations[n].image = "wr_isle_hut2.tga";

	//Town sack
	Locations[n].townsack = "Khael Roa";

	//Sound
	locations[n].type = "silent_cave_seashore";

	//Models
	//Always
	Locations[n].models.always.locators = "Hut_isle_locators";
	Locations[n].models.always.l1 = "Hut_isle";
	
	//Day
	Locations[n].models.day.charactersPatch = "Hut_isle_patch";

	//Night
	Locations[n].models.night.charactersPatch = "Hut_isle_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\shp_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_isle_passage";
    	Locations[n].reload.l1.emerge = "exit2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].locators_radius.box.box2 = 0.0001;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "sandfloor";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "chest5_coas";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "carpet1";			

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Eleuthera";
	n = n + 1;

	//--------------------------------------------------------------------------

	Locations[n].id = "BB_sloop";
	locations[n].id.label = "Sloop";
	Locations[n].filespath.models = "locations\decks\deckLow";
	Locations[n].image = "Teach_sloop.tga";

	//Sound
	locations[n].type = "Blackbeard_shore";	

	Locations[n].lockCamAngle = 0.2;		//was 0.4	

	//Models
	//Always
	Locations[n].models.always.locators = "deckLow_l_Q2";
	Locations[n].models.always.l1 = "deckLow";

    	Locations[n].models.always.l3 = "plan_3";
    	Locations[n].models.always.l3.level = 7;
   	Locations[n].models.always.l3.tech = "LocationModelBlend";

	//Day
	Locations[n].models.day.charactersPatch = "deckLow_p";
	Locations[n].models.day.fonar = "deckLow_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deckLow_p";
	Locations[n].models.day.night = "deckLow_fn";	

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.1;

	//Reload map
	Locations[n].reload.l1.name = "loc0";
	Locations[n].reload.l1.go = "BB_sloop_hold";
    	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	locations[n].reload.l1.disable = 1;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "swamp_island1";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "swamp_island1";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "swamp_island1";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "shipwreck3";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Eleuthera";
	n = n + 1;

	//--------------------------------------------------------------------------

	Locations[n].id = "BB_sloop_hold";		//never visited
	locations[n].id.label = "Hold";
	Locations[n].filespath.models = "locations\decks\deckLow";
	Locations[n].image = "Teach_sloop.tga";

	//Sound
	locations[n].type = "Blackbeard_shore";	

	//Models
	//Always
	Locations[n].models.always.locators = "deckLow_l";
	Locations[n].models.always.l1 = "deckLow";

	//Day
	Locations[n].models.day.charactersPatch = "deckLow_p";
	Locations[n].models.day.fonar = "deckLow_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deckLow_p";
	Locations[n].models.day.night = "deckLow_fn";	

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Eleuthera";
	n = n + 1;

	//--------------------------------------------------------------------------

	//CHARLESTON BLOCKADE
	Locations[n].id = "BB_QAR_cabin";
	Locations[n].id.label = "Large Cabin";
	//Info
	Locations[n].filespath.models = "locations\decks\cabin\Cabin01";
	Locations[n].image = "Teach_ship.tga";				//first time
//	Locations[n].image = "deck_cabin1.tga";				//later
	//Sound
	Locations[n].type = "Blackbeard_house";

	//Models
	//Always
	Locations[n].models.always.locators = "Cabin01_l_Q2";
	Locations[n].models.always.l1 = "Cabin01";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "Cabin01_patch";
	Locations[n].models.day.fonar = "cabin01_fonar";
	//Night
	Locations[n].models.night.charactersPatch = "Cabin01_patch";
	Locations[n].models.night.fonar = "cabin01_fonar";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	
	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "BB_QAR_deck";
    	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "BB_QAR_captain";
    	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	locations[n].reload.l2.disable = 1;

	Locations[n].models.always.Charlestown = "Charlestown";
	Locations[n].models.always.Charlestown.locator.group = "upgrades";
	Locations[n].models.always.Charlestown.locator.name = "Charlestown";

	Locations[n].locators_radius.box.box1 = 0.001;

	Locations[n].rats = "true";
	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Eleuthera";
	n = n + 1;

	//--------------------------------------------------------------------------

	//HANDS SHOT
	Locations[n].id = "BB_QAR_cabinH";
	Locations[n].id.label = "Large Cabin";
	//Info
	Locations[n].filespath.models = "locations\decks\cabin\Cabin01";

	Locations[n].image = "Teach_cabin.tga";				

	//Sound
	Locations[n].type = "Blackbeard_party";

	//Models
	//Always
	Locations[n].models.always.locators = "Cabin01_l_Q2H_1";		//Cabin01_l_Q2H_1, 2, 3 etc
	Locations[n].models.always.l1 = "Cabin01";				//"Cabin01_dark" later
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "Cabin01_patch";
	Locations[n].models.day.fonar = "cabin01_fonar";
	//Night
	Locations[n].models.night.charactersPatch = "Cabin01_patch";
	Locations[n].models.night.fonar = "cabin01_fonar";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	
	//Reload map
/*
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "BB_QAR_deck";
    	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "BB_QAR_captain";
    	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	locations[n].reload.l2.disable = 1;
*/

	Locations[n].models.always.chair3 = "chair3";
	Locations[n].models.always.chair3.locator.group = "upgrades";
	Locations[n].models.always.chair3.locator.name = "chair3";

	Locations[n].models.always.chair4 = "chair4";
	Locations[n].models.always.chair4.locator.group = "upgrades";
	Locations[n].models.always.chair4.locator.name = "chair4";

	Locations[n].locators_radius.box.box1 = 0.001;		//Hands body

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "armchair01";	

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "armchair02";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "rum_party1";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "rum_party1_dark";			

	Locations[n].rats = "true";
	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Eleuthera";
	n = n + 1;

	//--------------------------------------------------------------------------

	Locations[n].id = "BB_QAR_captain";		//never visited
	locations[n].id.label = "Captains cabin";
	Locations[n].filespath.models = "locations\decks\deckLow";
	Locations[n].image = "Teach_sloop.tga";

	//Sound
	locations[n].type = "Blackbeard_shore";	

	//Models
	//Always
	Locations[n].models.always.locators = "deckLow_l";
	Locations[n].models.always.l1 = "deckLow";

	//Day
	Locations[n].models.day.charactersPatch = "deckLow_p";
	Locations[n].models.day.fonar = "deckLow_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deckLow_p";
	Locations[n].models.day.night = "deckLow_fn";	

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Eleuthera";
	n = n + 1;

	//--------------------------------------------------------------------------

	Locations[n].id = "BB_QAR_deck";
	locations[n].id.label = "Queen Anne's Revenge";
	//Info
	Locations[n].filespath.models = "locations\decks\deckLowVSBig";
	Locations[n].image = "Sea.tga";

	Locations[n].townsack = "Grand Turk"; 					//needed for pirate flag
	//Sound
	locations[n].type = "Blackbeard_shore";
//	Locations[n].lockCamAngle = 0.4;
	//Models
	//Always
	Locations[n].models.always.locators = "deckLowVSBig_l_Q2";
	Locations[n].models.always.l1 = "deckLowVSBig";
	//Day
	Locations[n].models.day.charactersPatch = "deckLowVSBig_p";
	Locations[n].models.day.fonar = "deckLowVSBig_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deckLowVSBig_p";
	Locations[n].models.night.fonar = "deckLowVSBig_fn";

	Locations[n].models.always.Charlestown = "Charlestown";
	Locations[n].models.always.Charlestown.locator.group = "upgrades";
	Locations[n].models.always.Charlestown.locator.name = "Charlestown";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.4;	//JRH

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_QAR_cabin";
    	Locations[n].reload.l1.emerge = "reload1_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "BB_QAR_captain";
    	Locations[n].reload.l2.emerge = "reload1_back";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	locations[n].reload.l2.disable = 1;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "wr_gall_cap_inner";
    	Locations[n].reload.l3.emerge = "reload1_back";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "";
	locations[n].reload.l3.disable = 1;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "wr_corv_crew";
    	Locations[n].reload.l4.emerge = "reload1_back";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	locations[n].reload.l4.disable = 1;

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "wr_corv_smallcabin_L";
    	Locations[n].reload.l5.emerge = "reload1_back";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "";
	locations[n].reload.l5.disable = 1;

	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "BB_sloop_hold";
    	Locations[n].reload.l6.emerge = "reload1_back";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "";
	locations[n].reload.l6.disable = 1;

	Locations[n].locators_radius.quest.hole = 1.3;
	Locations[n].locators_radius.quest.richards2 = 2.0;

	Locations[n].rats = "true";
	Locations[n].island = "Eleuthera";
	n = n + 1;

	//--------------------------------------------------------------------------

	Locations[n].id = "Citadel_tower_stairs1";
	locations[n].id.label = "Citadel";
	Locations[n].filespath.models = "locations\inside\store04";
	Locations[n].filespath.textures = "locations\inside\store04\fort";
	Locations[n].image = "wr_tower_stairsA.tga";

	//Town sack
	Locations[n].townsack = "Khael Roa";

	//Sound
	locations[n].type = "silent_cave_seashore";		

	//Models
	//Always
	Locations[n].models.always.locators = "store04_locators_JRH_C";
	Locations[n].models.always.tavern = "store04";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "store04_patch_JRH";

	//Night
	Locations[n].models.night.charactersPatch = "store04_patch_JRH";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\shp_";

	//Reload map

	//up
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Citadel_tower_bedroom";
    	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.5;
	locations[n].reload.l4.disable = 0;

	//down = blocked
	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "Citadel_damaged";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "";
	locations[n].reload.l7.disable = 1;

	//bridge
	Locations[n].reload.l8.name = "reload8";
	Locations[n].reload.l8.go = "Eleuthera_shore";
	Locations[n].reload.l8.emerge = "box17";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "";

	Locations[n].locators_radius.goto.goto3 = 1.0;
	Locations[n].locators_radius.box.box1 = 0.7;
	Locations[n].locators_radius.box.box2 = 0.7;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "gatedoor_LH1";	

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "door_N09";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "key8";			//invisible

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Eleuthera";
	n = n + 1;

	//--------------------------------------------------------------------------

	//only for the label
	Locations[n].id = "Citadel_damaged";
	locations[n].id.label = "This part of the Citadel is damaged";
	Locations[n].filespath.models = "locations\inside\store04";
	Locations[n].filespath.textures = "locations\inside\store04\fort";
	Locations[n].image = "wr_wood_tower2.tga";

	//Town sack
	Locations[n].townsack = "Khael Roa";

	//Sound
	locations[n].type = "silent_cave_seashore";		

	//Models
	//Always
	Locations[n].models.always.locators = "store04_locators_JRH_C";
	Locations[n].models.always.tavern = "store04";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "store04_patch_JRH";

	//Night
	Locations[n].models.night.charactersPatch = "store04_patch_JRH";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "gatedoor_LH1";	

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "door_N09";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Eleuthera";
	n = n + 1;

	//--------------------------------------------------------------------------

	Locations[n].id = "Citadel_tower_bedroom";
	locations[n].id.label = "Maynard's room";
	Locations[n].filespath.models = "locations\inside\mh5";
	Locations[n].filespath.textures = "locations\inside\mh5\fort";
	Locations[n].image = "wr_Maynard.tga";

	//Town sack
//	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "Fort_Moultrie_inside";
//	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].models.always.locators = "mh5_l_JRH";
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
	Locations[n].models.back = "back\shp_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Citadel_tower_stairs1";
	Locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Eleuthera_shore";
	Locations[n].reload.l2.emerge = "quest3";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 0.6;

	Locations[n].locators_radius.box.box1 = 0.001;
	Locations[n].locators_radius.box.box2 = 0.001;
	Locations[n].locators_radius.box.box3 = 0.001;
	Locations[n].locators_radius.box.box4 = 0.001;
	Locations[n].locators_radius.box.box5 = 0.001;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "hatch11D";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "gatedoor_store4_wall";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "gatedoor_store4_wall";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "gatedoor_store4_wall";

	Locations[n].locators_radius.randitem.randitem5 = 0.0001;
	Locations[n].items.randitem5 = "carpet1";
	
	Locations[n].island = "Eleuthera";
	n = n + 1;

	//--------------------------------------------------------------------------

	Locations[n].id = "Citadel_tower_stairs2";
	locations[n].id.label = "Citadel";
	Locations[n].filespath.models = "locations\inside\store04";
	Locations[n].filespath.textures = "locations\inside\store04\fort";
	Locations[n].image = "wr_tower_stairsA.tga";

	//Town sack
	Locations[n].townsack = "Khael Roa";

	//Sound
	locations[n].type = "silent_cave_seashore";		

	//Models
	//Always
	Locations[n].models.always.locators = "store04_locators_JRH_C";
	Locations[n].models.always.tavern = "store04";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "store04_patch_JRH";

	//Night
	Locations[n].models.night.charactersPatch = "store04_patch_JRH";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\shp_";

	//Reload map

	//up = blocked
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Citadel_damaged";
    	Locations[n].reload.l4.emerge = "reload6";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.5;
	locations[n].reload.l4.disable = 1;

	//down
	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "Citadel_tower_stairs3";
	Locations[n].reload.l7.emerge = "reload4";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "";
	Locations[n].locators_radius.reload.reload7 = 1.8;

	//ground
	Locations[n].reload.l8.name = "reload8";
	Locations[n].reload.l8.go = "Eleuthera_shore";
	Locations[n].reload.l8.emerge = "box32";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "";

	Locations[n].locators_radius.goto.goto3 = 1.0;
	Locations[n].locators_radius.box.box1 = 0.7;
	Locations[n].locators_radius.box.box2 = 0.7;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "gatedoor_LH1";	

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "door_N09";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "key8";			//invisible

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Eleuthera";
	n = n + 1;

	//--------------------------------------------------------------------------

	Locations[n].id = "Citadel_tower_stairs3";
	locations[n].id.label = "Citadel";	
	Locations[n].filespath.models = "locations\inside\store04";
	Locations[n].filespath.textures = "locations\inside\store04\fort_darker";
	Locations[n].image = "wr_tower_stairsB.tga";

	//Town sack
	Locations[n].townsack = "Khael Roa";

	//Sound
	locations[n].type = "silent_cave_seashore";		

	//Models
	//Always
	Locations[n].models.always.locators = "store04_locators_JRH_C";
	Locations[n].models.always.tavern = "store04";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "store04_patch_JRH";

	//Night
	Locations[n].models.night.charactersPatch = "store04_patch_JRH";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map

	//up
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Citadel_tower_stairs2";
    	Locations[n].reload.l4.emerge = "goto3";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.5;

	//down
	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "Citadel_tower_stairs4";
	Locations[n].reload.l7.emerge = "reload4";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "";

	Locations[n].locators_radius.reload.reload8 = 0.0001;
	Locations[n].locators_radius.goto.goto3 = 1.0;
	Locations[n].locators_radius.box.box1 = 0.7;
	Locations[n].locators_radius.box.box2 = 0.7;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "gatedoor_LH1";	

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "key8";			//invisible

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "gatedoor_church_stone";	

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Eleuthera";
	n = n + 1;

	//--------------------------------------------------------------------------

	Locations[n].id = "Citadel_tower_stairs4";
	locations[n].id.label = "Citadel";
	Locations[n].filespath.models = "locations\inside\store04_stone";
	Locations[n].image = "wr_tower_stairsC.tga";

	//Town sack
	Locations[n].townsack = "Khael Roa";

	//Sound
	locations[n].type = "silent_cave_seashore";		

	//Models
	//Always
	Locations[n].models.always.locators = "store04_locators_JRH_C3";
	Locations[n].models.always.tavern = "store04";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "store04_patch_JRH";

	//Night
	Locations[n].models.night.charactersPatch = "store04_patch_JRH";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map

	//up = stairs 2
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Citadel_tower_stairs3";
    	Locations[n].reload.l4.emerge = "goto3";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.5;
	locations[n].reload.l4.disable = 0;

	Locations[n].locators_radius.goto.goto3 = 1.0;
	Locations[n].locators_radius.box.box1 = 0.7;
	Locations[n].locators_radius.box.box2 = 0.7;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "gatedoor_LH1";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "gatedoor_stone";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Eleuthera";
	n = n + 1;

	//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Grot";

	Locations[n].id = "Citadel_cave";
	locations[n].id.label = "Citadel Cave";
	Locations[n].image = "Inside_Grot.tga";
	//Sound
	locations[n].type = "silent_cave_seashore";
	//Models
	Locations[n].models.back = "back\grotenv_";
	//Always
	Locations[n].models.always.cave = "Grot";
	Locations[n].models.always.locators = "Grot_l_JRH_C";
	//Day
	Locations[n].models.day.charactersPatch = "Grot_p";
	//Night
	Locations[n].models.night.charactersPatch = "Grot_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "true";
	//Reload map

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Eleuthera_shore";
	Locations[n].reload.l2.emerge = "reload4";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Jungle.";

	Locations[n].locators_radius.randitem.randitem1 = 0.0001;
	Locations[n].items.randitem1 = "gatedoor_w7";

	Locations[n].island = "Eleuthera"; // NK 04-08-29
	n = n + 1;

// -------------------------------------------------

	Locations[n].id = "Turks_balcony_room";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\mh7";
	Locations[n].image = "Inside_mh7.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "silent_residence";
	locations[n].fastreload = "Redmond";
	//Models
	//Always
	Locations[n].models.always.locators = "mh7_l";
	Locations[n].models.always.shipyard = "mh7";
	Locations[n].models.always.window = "mh7_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "mh7_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh7_p";

	//Environment
	Locations[n].environment.weather = "false";		//true?
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redmh7_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Turks_port";
	Locations[n].reload.l1.emerge = "no_officers";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].island = "Turks"; // NK 04-08-29
	n = n + 1;

// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Sewer"; // PB: Flood the sewer as per an original idea by CCC
	Locations[n].id = "Turks_sewer";
	Locations[n].image = "wr_sewer.tga";
	locations[n].id.label = "#stown_name# Sewer";

	//Sound
	locations[n].type = "Dungeon";
	//Models
	//Always
	Locations[n].models.always.locators = "d01_l_KR";
	Locations[n].models.always.house = "d01";
	//Day
	Locations[n].models.day.charactersPatch = "d01_p";
	//Night
	Locations[n].models.night.charactersPatch = "d01_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.3;			//was 0.0
	Locations[n].environment.sewer = "true";

	LAi_LocationFantomsGen(&locations[n], false);
	Locations[n].vcskip = true;
	Locations[n].monsters = 0;

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Turks_wreck_shore";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 0.001;

	Locations[n].reload.l10.name = "reload1_back";
	Locations[n].reload.l10.go = "Turks_wreck_shore";
	Locations[n].reload.l10.emerge = "reload1";
	Locations[n].reload.l10.autoreload = "1";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Turks_port";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Turks_port";
//	Locations[n].reload.l3.emerge = "reload_sewer";
	Locations[n].reload.l3.emerge = "exit";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.reload2_back = 3.0;

	Locations[n].locators_radius.randitem.randitem1 = 0.0001;
	Locations[n].items.randitem1 = "ladder_very_big";

	Locations[n].locators_radius.randitem.randitem2 = 0.0001;
	Locations[n].items.randitem2 = "gatedoor_w8";

	Locations[n].locators_radius.randitem.randitem3 = 0.0001;
	Locations[n].items.randitem3 = "hatch11D";

	Locations[n].rats = "true";
	Locations[n].island = "Turks";
	n = n + 1;

// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Shore_ship1";

	Locations[n].id = "Turks_wreck_shore";
	//locations[n].id.label = "Prison ships";
	Locations[n].image = "wr_wreck_shore.tga";
	Locations[n].name = "Ship";
	//Sound
	locations[n].type = "prison_ships";

	//Models
	//Always
	Locations[n].models.always.jungle = "ShoreShip1";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.locators = "ShoreShip1_locators_KR";
//	Locations[n].models.always.grassPatch = "ShoreShip_g";
	Locations[n].models.always.seabed = "ShoreShip1_sb";
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
	Locations[n].models.always.l4 = "stoneblock";
	Locations[n].models.always.l5 = "rig";

	//Day
	Locations[n].models.day.charactersPatch = "ShoreShip1_patch";
	//Night
	Locations[n].models.night.charactersPatch = "ShoreShip1_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Turks_sewer";
	Locations[n].reload.l1.emerge = "arrive_shore";			//was reload1
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Redmond shore.";
	Locations[n].locators_radius.reload.reload1 = 1;

	Locations[n].reload.l3.name = "boat";
	Locations[n].reload.l3.go = "BB_sloop_wreck_cabin";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].locators_radius.reload.boat = 3;

	Locations[n].locators_radius.box.box3 = 2;
	Locations[n].locators_radius.box.box12 = 0.3;
	Locations[n].locators_radius.box.box13 = 0.3;

   	Locations[n].locators_radius.randitem.randitem1 = 0.0001;
	Locations[n].items.randitem1 = "gatedoor_w8";

	Locations[n].locators_radius.randitem.randitem2 = 0.0001;	
	Locations[n].items.randitem2 = "shipwreck3";			//Douwesen style

	Locations[n].locators_radius.randitem.randitem3 = 0.0001;
	Locations[n].items.randitem3 = "xebec_wreck";

	Locations[n].locators_radius.randitem.randitem4 = 0.0001;
	Locations[n].items.randitem4 = "shipwreck";			//Tortuga style

	Locations[n].items.randitem5 = "bladebottle_CB2";

	Locations[n].island = "Turks"; // NK 04-08-29
	n = n + 1;

// -------------------------------------------------

	//ID
	Locations[n].id = "BB_sloop_wreck_cabin";
	Locations[n].id.label = "Cabin";
	//Info
	Locations[n].filespath.models = "locations\decks\cabin\capsm";
	Locations[n].filespath.textures = "locations\decks\wreck";
	Locations[n].image = "wr_wreck_cabin.tga";
	//Sound
	Locations[n].type = "corvette_closed";

	//Models
	//Always
	Locations[n].models.always.locators = "capsm_l_KR";
	Locations[n].models.always.l1 = "capsm";
	Locations[n].models.always.l2 = "";		// "", gp_dry, gp_wet

	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "capsm_p";
//	Locations[n].models.day.fonar = "capsm_fd";
	//Night
	Locations[n].models.night.charactersPatch = "capsm_p";
//	Locations[n].models.night.fonar = "capsm_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_sloop_wreck_hold";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	Locations[n].locators_radius.reload.reload1 = 1.0;					

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Turks_wreck_shore";
	Locations[n].reload.l2.emerge = "sea";	
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 1.0;

	Locations[n].locators_radius.goto.stuck = 0.2;
	Locations[n].locators_radius.goto.free = 0.2;

	Locations[n].locators_radius.randitem.randitem1 = 0.0001;
	Locations[n].items.randitem1 = "gpmap";

	Locations[n].rats = "true";
	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Turks";
	n = n + 1;

// -------------------------------------------------

	Locations[n].id = "BB_sloop_wreck_hold";
	//Locations[n].id.label = "Cargo Hold";
	Locations[n].filespath.models = "locations\decks\hold_wreck";
	Locations[n].filespath.textures = "locations\decks\wreck";
	Locations[n].image = "wr_wreck_hold.tga";
	//Sound
	Locations[n].type = "galleon_closed";

	//Models
	//Always
	Locations[n].models.always.locators = "hold_l_KR"; 
	Locations[n].models.always.l1 = "hold";
	//Day
	Locations[n].models.day.charactersPatch = "hold_p";
//	Locations[n].models.day.fonar = "hold_fd";
	//Night
	Locations[n].models.night.charactersPatch = "hold_p";
//	Locations[n].models.night.fonar = "hold_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_sloop_wreck_cabin";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Turks_wreck_shore";
	Locations[n].reload.l2.emerge = "sea";			
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;
	locations[n].reload.l2.disable = 1;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Turks_wreck_shore";
	Locations[n].reload.l3.emerge = "sea";			
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.5;
	locations[n].reload.l3.disable = 1;

	Locations[n].locators_radius.box.box1 = 0.6;
	Locations[n].locators_radius.goto.goto3 = 2.0;
	
	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "hatch12G";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "hatch12G";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "hatch12G";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "hatch12G";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "door_N13";			//GPS green copperdoor

	Locations[n].rats = "true";
	Locations[n].island = "Turks";
	n = n + 1;

//JRH Tortuga questlocations
// -------------------------------------------------
	Locations[n].id = "Tortuga_gunsmith_kitchen";
	locations[n].id.label = "#stown_name# gunsmith";
	Locations[n].filespath.models = "locations\inside\DoubleFlour_house";
	Locations[n].filespath.textures = "locations\inside\Doubleflour_house\Tortuga";					
	Locations[n].image = "wr_surgeon3_house.tga";

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
	Locations[n].models.back = "back\tor2_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Tortuga_port";
//	Locations[n].reload.l1.emerge = "box8";
	Locations[n].reload.l1.emerge = "reloadQ9";			//to enable officers locators
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].reload.l3.name = "reload3";		
	Locations[n].reload.l3.go = "Tortuga_gunsmith_workshop";
	Locations[n].reload.l3.emerge = "gunsmith";		
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].locators_radius.reload.reload3 = 0.8;			

	Locations[n].locators_radius.box.box1 = 1.0;
	Locations[n].locators_radius.box.box2 = 0.01;
	Locations[n].locators_radius.box.box3 = 0.01;
	Locations[n].locators_radius.box.box4 = 0.01;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_A05";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "door_A05R";

	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;

// -------------------------------------------------
	
	Locations[n].id = "Tortuga_gunsmith_workshop";
	locations[n].id.label = "Gunsmith workshop";
	
	locations[n].worldmap = "Tortuga";

	//Town sack
	Locations[n].townsack = "Tortuga";
	//Models
	Locations[n].filespath.models = "locations\Town_Tortuga";
	Locations[n].models.always.locators = "Tortuga_l_inside";
	Locations[n].image = "wr_surgeon3_shop.tga";
	//Sound
	locations[n].type = "Rogers_repair_residence";
	locations[n].fastreload = "Tortuga";
	LAi_LocationFantomsGen(&locations[n], true);

	//Always
	Locations[n].models.always.l1 = "Tortuga";			//this is to get the Tortuga_landscape to show up, the model is sunk 50 m down, actual city models are Tortuga_fn, Tortuga_fd.
	Locations[n].models.always.l1.foam = "1";
//	Locations[n].models.always.l2 = "Tortuga_sb";
//	Locations[n].models.always.l2.foam = "1";
	Locations[n].models.always.l3 = "flagpole";
	Locations[n].models.always.l4 = "flagpole2";
//	Locations[n].models.always.l5 = "short_ladder";			//replaced by randitem ladder_hold

	//Day
	Locations[n].models.day.fonar = "Tortuga_fd";
	Locations[n].models.day.charactersPatch = "walk_patch";
	
	//Night
	Locations[n].models.night.fonar = "Tortuga_fn";
	Locations[n].models.night.charactersPatch = "walk_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Tortuga_gunsmith_kitchen";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].locators_radius.reload.reload3 = 0.5;
	
	Locations[n].locators_radius.reload.reload1 = 0.2;
	Locations[n].locators_radius.reload.reload2 = 0.2;
	Locations[n].locators_radius.box.box1 = 0.2;
	Locations[n].locators_radius.box.box2 = 0.2;
	Locations[n].locators_radius.box.box3 = 0.2;
	Locations[n].locators_radius.box.box4 = 0.2;
	Locations[n].locators_radius.box.box6 = 0.2;

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "door_A05";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "cannon2";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "cannon1";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "build_clock2";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "anvil";

	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "musket_item";

	Locations[n].locators_radius.randitem.randitem8 = 0.01;
	Locations[n].items.randitem8 = "musket_item";

	Locations[n].locators_radius.randitem.randitem9 = 0.01;
	Locations[n].items.randitem9 = "musket_item";

	Locations[n].locators_radius.randitem.randitem10 = 0.01;
	Locations[n].items.randitem10 = "medicine_table2";

	Locations[n].locators_radius.randitem.randitem11 = 0.01;
	Locations[n].items.randitem11 = "bladearmchair";

	Locations[n].locators_radius.randitem.randitem12 = 0.01;
	Locations[n].items.randitem12 = "bladearmchair";

	Locations[n].locators_radius.randitem.randitem32 = 0.01;
	Locations[n].items.randitem32 = "ladder_hold";

	Locations[n].vcskip = true;
	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

// -------------------------------------------------
	
	Locations[n].id = "Tortuga_surgeon2";				//small woodhouse
	locations[n].id.label = "#stown_name# surgeon";
	
	locations[n].worldmap = "Tortuga";
	Locations[n].image = "wr_surgeon2.tga";

	//Town sack
	Locations[n].townsack = "Tortuga";
	//Models
	Locations[n].filespath.models = "locations\Town_Tortuga";
	Locations[n].models.always.locators = "Tortuga_l_inside";

	//Sound
	locations[n].type = "shop";
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
	
	//Night
	Locations[n].models.night.fonar = "Tortuga_fn";
	Locations[n].models.night.charactersPatch = "walk_patch";

	//Reload map
	Locations[n].reload.l1.name = "reload4";
	Locations[n].reload.l1.go = "Tortuga_port";
	Locations[n].reload.l1.emerge = "reloadQ4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload4 = 0.3;
	
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	Locations[n].locators_radius.box.box5 = 0.2;

	Locations[n].locators_radius.randitem.randitem15 = 0.01;
	Locations[n].items.randitem15 = "wood_floor";

	Locations[n].locators_radius.randitem.randitem19 = 0.01;
	Locations[n].items.randitem19 = "bed";

	Locations[n].locators_radius.randitem.randitem20 = 0.01;
	Locations[n].items.randitem20 = "pyrite_basket_up";

	Locations[n].locators_radius.randitem.randitem21 = 0.01;
	Locations[n].items.randitem21 = "pistol_armchair";

	Locations[n].locators_radius.randitem.randitem23 = 0.01;
	Locations[n].items.randitem23 = "medicine_table";

	Locations[n].locators_radius.randitem.randitem24 = 0.01;
	Locations[n].items.randitem24 = "chest5_coas";

	Locations[n].locators_radius.randitem.randitem29 = 0.01;
	Locations[n].items.randitem29 = "carpet2";

	Locations[n].locators_radius.randitem.randitem30 = 0.01;
	Locations[n].items.randitem30 = "chair";

	Locations[n].vcskip = true;
	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

// -------------------------------------------------
	
	Locations[n].id = "Tortuga_sailmaker";
	locations[n].id.label = "#stown_name# sailmaker";
	
	locations[n].worldmap = "Tortuga";
	Locations[n].image = "wr_sailmaker.tga";

	//Town sack
	Locations[n].townsack = "Tortuga";
	//Models
	Locations[n].filespath.models = "locations\Town_Tortuga";
	Locations[n].models.always.locators = "Tortuga_l_inside";

	//Sound
	locations[n].type = "shop";
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
	
	//Night
	Locations[n].models.night.fonar = "Tortuga_fn";
	Locations[n].models.night.charactersPatch = "walk_patch";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Tortuga_port";
	Locations[n].reload.l1.emerge = "reloadQ1";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Tortuga_port";
	Locations[n].reload.l2.emerge = "box2";
	Locations[n].reload.l2.autoreload = "0";
	
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "ladder_biggest";
	
	Locations[n].locators_radius.reload.reload1 = 0.2;
	Locations[n].locators_radius.reload.reload2 = 0.2;
	Locations[n].locators_radius.box.box1 = 0.2;
	Locations[n].locators_radius.box.box2 = 0.2;
	Locations[n].locators_radius.box.box3 = 0.2;
	Locations[n].locators_radius.box.box4 = 0.2;

	Locations[n].locators_radius.randitem.randitem13 = 0.01;
	Locations[n].items.randitem13 = "roll_of_rolls";

	Locations[n].locators_radius.randitem.randitem14 = 0.01;
	Locations[n].items.randitem14 = "sailcloth_wall";

	Locations[n].locators_radius.randitem.randitem16 = 0.01;
	Locations[n].items.randitem16 = "sailcloth_wall";

	Locations[n].locators_radius.randitem.randitem17 = 0.01;
	Locations[n].items.randitem17 = "roll_of_rolls";

	Locations[n].locators_radius.randitem.randitem18 = 0.01;
	Locations[n].items.randitem18 = "port_mast1";

	Locations[n].locators_radius.randitem.randitem22 = 0.01;
	Locations[n].items.randitem22 = "sailcloth_floor";

	Locations[n].locators_radius.randitem.randitem25 = 0.01;
	Locations[n].items.randitem25 = "stool";

	Locations[n].locators_radius.randitem.randitem26 = 0.01;
	Locations[n].items.randitem26 = "stool";

	Locations[n].locators_radius.randitem.randitem27 = 0.01;
	Locations[n].items.randitem27 = "roll_of_rolls";

	Locations[n].locators_radius.randitem.randitem28 = 0.01;
	Locations[n].items.randitem28 = "roll_of_rolls";

	Locations[n].locators_radius.randitem.randitem31 = 0.01;
	Locations[n].items.randitem31 = "sailcloth_wall";

	Locations[n].vcskip = true;
	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Tortuga_tower";
	locations[n].id.label = "#stown_name# tower";
	Locations[n].image = "wr_Tortuga_tower_inside.tga";
	
	locations[n].worldmap = "Tortuga";

	//Town sack
	Locations[n].townsack = "Tortuga";
	//Models
	Locations[n].filespath.models = "locations\Town_Tortuga";
	Locations[n].models.always.locators = "Tortuga_l_tower";		

	//Sound
	locations[n].type = "Rogers_cellar";
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
	
	//Night
	Locations[n].models.night.fonar = "Tortuga_fn";
	Locations[n].models.night.charactersPatch = "walk_patch";

	//Reload map
	Locations[n].reload.l1.name = "reloadQ4";
	Locations[n].reload.l1.go = "Tortuga_tower_passage";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reloadQ5";
	Locations[n].reload.l2.go = "Tortuga_port";
	Locations[n].reload.l2.emerge = "box11";
	Locations[n].reload.l2.autoreload = "0";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	
	Locations[n].locators_radius.reload.reloadQ4 = 0.4;
	Locations[n].locators_radius.reload.reloadQ5 = 0.2;
	Locations[n].locators_radius.box.box8 = 0.4;
	Locations[n].locators_radius.box.box9 = 0.4;
	Locations[n].locators_radius.box.box10 = 0.4;
	Locations[n].locators_radius.box.box11 = 0.4;
	Locations[n].locators_radius.box.box12 = 0.4;
	Locations[n].locators_radius.box.box13 = 0.4;
	Locations[n].locators_radius.box.box14 = 0.4;
	Locations[n].locators_radius.box.box15 = 0.4;
	Locations[n].locators_radius.box.box16 = 0.4;
	Locations[n].locators_radius.box.box17 = 0.4;
	Locations[n].locators_radius.box.box18 = 0.4;
	Locations[n].locators_radius.box.box19 = 0.4;
	Locations[n].locators_radius.box.box20 = 0.4;
	Locations[n].locators_radius.box.box21 = 0.4;
	Locations[n].locators_radius.box.box22 = 0.4;
	Locations[n].locators_radius.box.box23 = 0.4;
	Locations[n].locators_radius.box.box24 = 0.2;
	Locations[n].locators_radius.box.box25 = 0.2;
	Locations[n].locators_radius.box.box26 = 0.2;
	Locations[n].locators_radius.box.box27 = 0.2;
	Locations[n].locators_radius.box.box28 = 0.2;
	Locations[n].locators_radius.box.box29 = 0.2;
	Locations[n].locators_radius.box.box30 = 0.2;

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

	Locations[n].locators_radius.randitem.randitem132 = 0.01;
	Locations[n].items.randitem132 = "ladder_very_big";

	Locations[n].locators_radius.randitem.randitem133 = 0.01;
	Locations[n].items.randitem133 = "door_N10";

	Locations[n].vcskip = true;
	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
//pär
	Locations[n].id = "Tortuga_tower_stairs_A";
	locations[n].id.label = "Tower stairs";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house\\";
	Locations[n].filespath.textures = "locations\inside\Doubleflour_house\Tortuga";
	Locations[n].image = "Inside_Townhall_Stairs_Tortuga.tga";
	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Pym_tower";		
	
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F1_l_JRH2";
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
	Locations[n].reload.l2.go = "Tortuga_tower_stairs_B";
	Locations[n].reload.l2.emerge = "goto4";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Tortuga_tower_stairs_A";
	Locations[n].reload.l3.emerge = "reload4";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Tortuga_port";			
   	Locations[n].reload.l4.emerge = "box20";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.3;
	
	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_TortugaT";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "gatedoor_Mine";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "gateroof_wood";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "door_TortugaT";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "gatedoor_Mine";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "Tortuga_tower_stairs_B";
	locations[n].id.label = "To the Dovecote";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house\\";
	Locations[n].filespath.textures = "locations\inside\Doubleflour_house\Tortuga";
	Locations[n].image = "Inside_Townhall_Stairs_Tortuga.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Pym_tower";			
	
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F1_l_JRH3_L";
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
	Locations[n].reload.l2.go = "Tortuga_port";
	Locations[n].reload.l2.emerge = "dovecote1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Tortuga_tower_stairs_B";
	Locations[n].reload.l3.emerge = "reload4";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Tortuga_tower_stairs_A";			
    	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.3;
	
	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box2 = 0.3;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	//Locations[n].items.randitem1 = "door_N06";
Locations[n].items.randitem1 = "door_TortugaT";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "gatedoor_Mine";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "gateroof_wood";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "gatedoor_Mine";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "ladder_big";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;		//ri2 from attic stairs
	Locations[n].items.randitem6 = "hatch11D";

	Locations[n].items.randitem7 = "musket_item";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Tortuga_surgeon1";					//above sailmaker
	locations[n].id.label = "#stown_name# surgeon";
	Locations[n].image = "Inside_Tavern_Room_Tortuga.tga";

	//Town sack
	Locations[n].townsack = "Tortuga";

	//Sound
	locations[n].type = "Legrands_house";
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
	Locations[n].reload.l1.go = "Tortuga_port";
	Locations[n].reload.l1.emerge = "box5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;		
	Locations[n].items.randitem1 = "door_N06T";

	Locations[n].locators_radius.box.box1 = 0.1;
	Locations[n].locators_radius.goto.goto4 = 3.5;	

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].id = "Tortuga_tower_passage";
	//locations[n].id.label = "Tower passage";				//when opened
	Locations[n].filespath.models = "locations\inside\Corridor\\";
	Locations[n].filespath.textures = "locations\inside\Corridor\fort";
	Locations[n].image = "wr_Tortuga_tower_passage.tga";

	//Sound
	locations[n].type = "silent_residence";
	
	//Models
	//Always
	Locations[n].models.always.locators = "StoreSmall_locators_JRH_normal";			
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
	Locations[n].reload.l1.go = "Tortuga_Townhall";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	Locations[n].locators_radius.reload.reload1 = 0.5;
	
	Locations[n].reload.l5.name = "reload2";
	Locations[n].reload.l5.go = "Tortuga_tower";
	Locations[n].reload.l5.emerge = "box8";
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
	Locations[n].island = "Hispaniola";
	n = n + 1;

//JRH monastary
	//--------------------------------------------------------------------------	

	Locations[n].filespath.models = "locations\Town_Cartagena\Cloister_exit";
	Locations[n].image = "Town_Cartagena_Cloister_Inside.tga";

	Locations[n].vcskip = true;

	Locations[n].id = "cloister_passage";
	locations[n].id.label = "cloister passage";
	//Town sack
	Locations[n].townsack = "Cartagena";
	locations[n].fastreload = "Cartagena";		
	//Sound
//	locations[n].type = "town";
	locations[n].type = "Chinese_garden";
	//Models
	//Always
	Locations[n].models.always.locators = "cloister_passage_l";
	Locations[n].models.always.town = "cloister_exit";
	Locations[n].models.always.l1 = "Margarita_gate";
	Locations[n].models.always.l2 = "new_wall";

	//Day
	Locations[n].models.day.charactersPatch = "cloister_passage_p";
	//Night
	Locations[n].models.night.charactersPatch = "cloister_passage_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "cloister_exit";
	Locations[n].reload.l1.emerge = "goto5";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Cloister.";
    	Locations[n].locators_radius.reload.reload1 = 4.0;		//was 4.0

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "cloister_exit";
	Locations[n].reload.l2.emerge = "reload4";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Cloister.";
	Locations[n].locators_radius.reload.reload2 = 1.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "hatch11_S";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "iron_gate_big";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "iron_gate_big";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "tree1";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "church_window";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "bench";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "bench";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "bench";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "bench";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "bench";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "bench";

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "bench";

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "bench";

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
	Locations[n].items.randitem14 = "bench";

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	Locations[n].items.randitem15 = "bench";

	Locations[n].locators_radius.randitem.randitem16 = 0.001;
	Locations[n].items.randitem16 = "door_fort";

	Locations[n].island = "Colombia"; // NK 04-08-29

	Build_at("cloister_passage", "jungle2", "", -3.4676, 0, 26.249, 0.0, "Building");
	Build_at("cloister_passage", "jungle2", "", 9.7, 0, 26.5, 0.0, "Building");

	n = n + 1;

	//--------------------------------------------------------------------------	
	
	Locations[n].id = "BB_graveyard";
	locations[n].id.label = "Abbey";
	Locations[n].filespath.models = "locations\Outside\Graveyard";
	Locations[n].image = "wr_abbey.tga";
	
	//Sound
	locations[n].type = "deserted_mountains";

	//Models
	//Always
	Locations[n].models.always.jungle = "Churchyard";
	Locations[n].models.always.grassPatch = "Churchyard_grass";
	Locations[n].models.always.l1 = "Churchyard_plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "Churchyard_plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l4 = "Building";
	Locations[n].models.always.l5 = "Building2";
	Locations[n].models.always.l6 = "chimney_45";
	Locations[n].models.always.l7 = "stone_cross";
	Locations[n].models.always.l8 = "fort_walls_stucco_1";

	//Day
	Locations[n].models.day.locators = "Churchyard_ld";
	Locations[n].models.day.charactersPatch = "Churchyard_patch";
	//Night
	Locations[n].models.night.locators = "Churchyard_ln";
	Locations[n].models.night.charactersPatch = "Churchyard_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l10.name = "reload1_back";
	Locations[n].reload.l10.go = "BB_refectory";
	Locations[n].reload.l10.emerge = "reload3";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].locators_radius.reload.reload1_back = 1.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "cloister_exit";
	Locations[n].reload.l2.emerge = "goto6";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Cloister.";
	Locations[n].locators_radius.reload.Reload2 = 3.0;

	Locations[n].reload.l20.name = "reload2_back";
	Locations[n].reload.l20.go = "cloister_exit";
	Locations[n].reload.l20.emerge = "goto6";
	Locations[n].reload.l20.autoreload = "0";
	Locations[n].reload.l20.label = "Cloister.";
	Locations[n].locators_radius.reload.reload2_back = 0.3;

	Locations[n].reload.l3.name = "reload3";			//via door
	Locations[n].reload.l3.go = "BB_church_room";			
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Chapel";
	Locations[n].locators_radius.reload.Reload3 = 1.0;
	Locations[n].reload.l3.disable = 1;				//locked/blocked from inside

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "BB_crypt2_1";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Crypt";
	Locations[n].locators_radius.reload.Reload4 = 1.0;
	Locations[n].reload.l4.disable = 1;

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "BB_crypt1";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Crypt";
	Locations[n].locators_radius.reload.Reload5 = 1.0;
	Locations[n].reload.l5.disable = 1;

	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "BB_bell_tower";			//bell tower
	Locations[n].reload.l6.emerge = "bell";	
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Bell tower";
	Locations[n].locators_radius.reload.Reload6 = 1.0;
	Locations[n].reload.l6.disable = 1;				//opened later

	Locations[n].reload.l7.name = "reload7";			//via window
	Locations[n].reload.l7.go = "BB_church_room";
	Locations[n].reload.l7.emerge = "box3";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Chapel";
	Locations[n].locators_radius.reload.Reload7 = 1.0;
	Locations[n].reload.l7.disable = 1;

	Locations[n].locators_radius.box.box4 = 2.5;
	Locations[n].locators_radius.box.box3 = 0.001;			//1.0 later

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "hatch11_O";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "hatch11_T";

	LAi_LocationMonstersGen(&locations[n], false);
	Locations[n].island = "Colombia";
	n = n + 1;

	//--------------------------------------------------------------------------	
	
	Locations[n].id = "BB_bell_tower";
	locations[n].id.label = "Bell tower";
	Locations[n].filespath.models = "locations\Outside\Graveyard";
	Locations[n].image = "wr_bell_tower.tga";
	
	//Sound
	locations[n].type = "deserted_mountains";

	//Models
	//Always
//	Locations[n].models.always.locators = "jungle01_l_JRH";
	Locations[n].models.always.jungle = "Churchyard";
	Locations[n].models.always.grassPatch = "Churchyard_grass";
	Locations[n].models.always.l1 = "Churchyard_plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "Churchyard_plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "Churchyard_plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	Locations[n].models.always.l4 = "Building";
	Locations[n].models.always.l5 = "Building2";

	//Day
	Locations[n].models.day.locators = "Churchyard_ld";
	Locations[n].models.day.charactersPatch = "Churchyard_patch";
	//Night
	Locations[n].models.night.locators = "Churchyard_ln";
	Locations[n].models.night.charactersPatch = "Churchyard_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "hatch11_O";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "hatch11_T";

	LAi_LocationMonstersGen(&locations[n], false);
	Locations[n].island = "Colombia";
	n = n + 1;

	//--------------------------------------------------------------------------	

	Locations[n].id = "BB_refectory";
	locations[n].id.label = "Refectory";	
	Locations[n].filespath.models = "locations\inside\Tavern_2";
	Locations[n].image = "wr_refectory.tga";

	//Town sack
	//Locations[n].townsack = "Havana";

	//Sound
	//locations[n].type = "silent_residence";
	//locations[n].type = "Moultrie_restaurant";
	//locations[n].type = "brothel_QC";
	//locations[n].type = "church";
	locations[n].type = "Vane_church";

	//Models
	//Always
	Locations[n].models.always.tavern = "Tavern_2";
	Locations[n].models.always.l1 = "door_chapel";
	Locations[n].models.always.l2 = "cross";
	Locations[n].models.always.locators = "Tavern_2_l_monastary";
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

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "BB_graveyard";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].locators_radius.reload.reload3 = 1.0;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "BB_abbess";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.disable = 1;				//opened later

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "BB_monastary_chapel";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.disable = 1;				//opened later

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "door_largeh2";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "door_sklad";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "door_largeh";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "door_Tortuga";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "door_fort";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "door_N44T";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "door_largeh";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "door_largeh";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "door_fort";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "door_MdTav";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "door_MdTav";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Colombia";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "BB_monastary_chapel";
	locations[n].id.label = "Chapel";
	Locations[n].image = "Inside_Church_2.tga";
	Locations[n].filespath.models = "locations\inside\Church_2\\";
	
	//Sound
	//locations[n].type = "Vane_chapel";
	locations[n].type = "choir";

	//Models
	//Always
	Locations[n].models.always.city = "Church2";
	Locations[n].models.always.locators = "Church2_l";
	Locations[n].models.always.window = "church2_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Church2_p";

	//Night
	Locations[n].models.night.charactersPatch = "Church2_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_refectory";
	Locations[n].reload.l1.emerge = "reload5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";

	Locations[n].locators_radius.goto.goto11 = 2.5;

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Colombia";
	n = n + 1;

	//--------------------------------------------------------------------------

	Locations[n].id = "BB_abbess";
	locations[n].id.label = "Abbess";
	Locations[n].filespath.models = "locations\inside\Tavern_room";
	Locations[n].image = "Inside_Tavern_Room.tga";

	//Town sack
	//Locations[n].townsack = "Redmond"; // NK 04-08-29
	//Locations[n].island = "Redmond"; // NK 04-08-29

	//Sound
	locations[n].type = "Rogers_private";
	//Models
	//Always
	Locations[n].models.always.locators = "tavern_room_locators_abbess";
	Locations[n].models.always.l1 = "Tavern_room";
	Locations[n].models.always.window = "Tavern_room_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Tavern_room_patch";

	//Night
	Locations[n].models.night.charactersPatch = "Tavern_room_patch";	

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redmh_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_refectory";
	Locations[n].reload.l1.emerge = "Reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Woodes Rogers' kitchen.";

	Locations[n].locators_radius.box.box1 = 0.7;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "AltarPicture";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Colombia";
	n = n + 1;

	//--------------------------------------------------------------------------	

	Locations[n].filespath.models = "locations\Inside\Church_room";	
	Locations[n].image = "wr_church_room.tga";

	Locations[n].id = "BB_church_room";
	locations[n].id.label = "Small Chapel";
	//Town sack
	//Locations[n].townsack = "Khael Roa";
	//Sound
	locations[n].type = "Vane_chapel";		
	
	//Models
	//Always
	Locations[n].models.always.locators = "church_IM_locators";
	Locations[n].models.always.l1 = "church_IM";
	Locations[n].models.always.window = "church_IM_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	
	//Day
	Locations[n].models.day.charactersPatch = "church_IM_patch";
	
	//Night
	Locations[n].models.night.charactersPatch = "church_IM_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";	

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_graveyard";
	Locations[n].reload.l1.emerge = "Reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 0.001;		//large after pushed open

	Locations[n].locators_radius.box.box1 = 0.7;
	Locations[n].locators_radius.box.box4 = 0.6;

	Locations[n].locators_radius.randitem.randitem1 = 1.0;
	Locations[n].items.randitem1 = "book62";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Colombia";
	n = n + 1;

	//--------------------------------------------------------------------------	

	Locations[n].filespath.models = "locations\Inside\Crypt1";	
	Locations[n].image = "wr_crypt1.tga";

	Locations[n].id = "BB_crypt1";
	locations[n].id.label = "Crypt ";
	//Town sack
	//Locations[n].townsack = "Khael Roa";
	//Sound
	locations[n].type = "crypt";			

	//Models
	//Always
	Locations[n].models.always.locators = "crypt_inside_locators";
	Locations[n].models.always.l1 = "crypt_inside";
	
	//Day
	Locations[n].models.day.charactersPatch = "crypt_inside_patch";
	
	//Night
	Locations[n].models.night.charactersPatch = "crypt_inside_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";	

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_graveyard";
	Locations[n].reload.l1.emerge = "Reload5";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].locators_radius.box.box4 = 1.0;
	Locations[n].locators_radius.box.box5 = 1.0;

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Colombia";
	n = n + 1;

	//--------------------------------------------------------------------------	

	Locations[n].filespath.models = "locations\Inside\Crypt2_1";	
	Locations[n].image = "wr_crypt2_1.tga";

	Locations[n].id = "BB_crypt2_1";
	locations[n].id.label = "Crypt ";
	//Town sack
	//Locations[n].townsack = "Khael Roa";
	//Sound
	locations[n].type = "crypt";			

	//Models
	//Always
	Locations[n].models.always.l1 = "crypt_2_1_inside";
	
	//Day
	Locations[n].models.day.locators = "crypt_2_1_inside_ld";
	Locations[n].models.day.charactersPatch = "crypt_2_1_inside_patch";
	
	//Night
	Locations[n].models.night.locators = "crypt_2_1_inside_ln";
	Locations[n].models.night.charactersPatch = "crypt_2_1_inside_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";	

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_graveyard";
	Locations[n].reload.l1.emerge = "Reload4";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "BB_crypt2_2";
	Locations[n].reload.l2.emerge = "Reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.disable = 1;

	Locations[n].locators_radius.box.box2 = 0.001;

	Locations[n].locators_radius.randitem.randitem1 = 1.6;
	Locations[n].items.randitem1 = "key33";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Colombia";
	n = n + 1;

//--------------------------------------------------------------------------	

	Locations[n].filespath.models = "locations\Inside\Crypt2_2";	
	Locations[n].image = "wr_crypt2_2.tga";

	Locations[n].id = "BB_crypt2_2";
	locations[n].id.label = "Crypt ";
	//Town sack
	//Locations[n].townsack = "Khael Roa";
	//Sound
	locations[n].type = "crypt";			

	//Models
	//Always
	Locations[n].models.always.l1 = "crypt_2_2_inside";
	Locations[n].models.always.locators = "crypt_2_2_inside_locators";
	
	//Day
	Locations[n].models.day.charactersPatch = "crypt_2_2_inside_patch";
	
	//Night
	Locations[n].models.night.charactersPatch = "crypt_2_2_inside_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";	

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_crypt2_1";
	Locations[n].reload.l1.emerge = "Reload2";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "BB_abbey_cell";
	Locations[n].reload.l2.emerge = "Reload3";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.disable = 1;

	Locations[n].locators_radius.box.box2 = 0.7;
	Locations[n].locators_radius.box.box5 = 0.6;
	Locations[n].locators_radius.box.box6 = 0.6;
	Locations[n].locators_radius.box.box7 = 0.6;
	Locations[n].locators_radius.box.box8 = 0.6;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "hatch11";

	LAi_LocationFightDisable(&Locations[n], true);
	LAi_LocationFantomsGen(&locations[n], false);
	Locations[n].vcskip = true;
	Locations[n].monsters = 0;

	Locations[n].island = "Colombia";
	n = n + 1;

	//--------------------------------------------------------------------------	

	Locations[n].filespath.models = "locations\Inside\Crypt2_2";	
	Locations[n].image = "wr_abbey_cell.tga";

	Locations[n].id = "BB_abbey_cell";
	locations[n].id.label = "Cell";
	//Town sack
	//Locations[n].townsack = "Khael Roa";
	//Sound
	locations[n].type = "crypt";			

	//Models
	//Always
	Locations[n].models.always.l1 = "crypt_2_2_inside";
	Locations[n].models.always.l2 = "straw";
	Locations[n].models.always.locators = "crypt_2_2_inside_locators";
	
	//Day
	Locations[n].models.day.charactersPatch = "crypt_2_2_inside_patch";
	
	//Night
	Locations[n].models.night.charactersPatch = "crypt_2_2_inside_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";	

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_crypt2_1";
	Locations[n].reload.l1.emerge = "Reload2";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "BB_crypt2_2";
	Locations[n].reload.l3.emerge = "Reload2";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].locators_radius.box.box2 = 0.7;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "hatch11";

	LAi_LocationFightDisable(&Locations[n], true);
	LAi_LocationFantomsGen(&locations[n], false);
	Locations[n].vcskip = true;
	Locations[n].monsters = 0;

	Locations[n].island = "Colombia";
	n = n + 1;

	//--------------------------------------------------------------------------	
	
	Locations[n].id = "BB_Eden_estate";
	locations[n].id.label = "Estate";
	Locations[n].filespath.models = "locations\Outside\Estate";
	Locations[n].image = "wr_estate.tga";
	
	//Sound
	locations[n].type = "Chinese_garden";

	//Models
	//Always
	Locations[n].models.always.locators = "Estate_locators_Q2";
	Locations[n].models.always.jungle = "Estate";
	Locations[n].models.always.window = "estate_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	Locations[n].models.always.grassPatch = "Estate_grass";
	Locations[n].models.always.l1 = "tower1";
	Locations[n].models.always.l2 = "tower2";
	Locations[n].models.always.l3 = "Bonner_house";
	Locations[n].models.always.l4 = "tunnel_entrance";
	Locations[n].models.always.l5 = "tunnel_door";
	Locations[n].models.always.l6 = "townwall";
	Locations[n].models.always.l7 = "green_square";

	//Day
	Locations[n].models.day.fonar = "estate_fd";
	Locations[n].models.day.charactersPatch = "estate_patch";
	//Night
	Locations[n].models.night.fonar = "estate_fn";
	Locations[n].models.night.charactersPatch = "estate_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_crypt2_1";
	Locations[n].reload.l1.emerge = "Reload2";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "BB_Eden_bedroom2";
	Locations[n].reload.l2.emerge = "Reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.disable = 1;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "BB_Eden_kitchen";
	Locations[n].reload.l3.emerge = "Reload3";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.disable = 1;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "BB_Eden_bedroom1";
	Locations[n].reload.l4.emerge = "Reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.disable = 1;

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "BB_Eden_office";
	Locations[n].reload.l5.emerge = "Reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.disable = 1;

	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "BB_Eden_chapel";
	Locations[n].reload.l6.emerge = "Reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.disable = 1;

	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "BB_Eden_maze";
	Locations[n].reload.l7.emerge = "Reload2";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].locators_radius.reload.reload7 = 0.001;		//0.7 when detected
	
	Locations[n].reload.l8.name = "reload8";
	Locations[n].reload.l8.go = "BB_Eden_maze";
	Locations[n].reload.l8.emerge = "Reload3";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].locators_radius.reload.reload8 = 0.001;		//0.7 when detected

	Locations[n].reload.l9.name = "reload9";
	Locations[n].reload.l9.go = "BB_Eden_dining_room";
	Locations[n].reload.l9.emerge = "Reload1";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].locators_radius.reload.reload9 = 0.7;
	Locations[n].reload.l9.disable = 1;

	Locations[n].reload.l10.name = "reload10";
	Locations[n].reload.l10.go = "Grand_Cayman_town";
	Locations[n].reload.l10.emerge = "box3";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].locators_radius.reload.reload10 = 0.5;
	
	Locations[n].locators_radius.box.box17 = 1.3;
	Locations[n].locators_radius.box.box18 = 1.5;
	Locations[n].locators_radius.box.box20 = 0.6;
	Locations[n].locators_radius.goto.unlock = 3.0;
	Locations[n].locators_radius.goto.entre = 2.5;
	Locations[n].locators_radius.goto.goto6 = 3.4;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "door_green";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "door_green";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "door_H1_small";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "Boat2_C";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "wagon";

	LAi_LocationMonstersGen(&locations[n], false);
	Locations[n].island = "KhaelRoa";
	n = n + 1;

//--------------------------------------------------------------------------	

	Locations[n].id = "BB_Eden_estate_wreck";
	locations[n].id.label = "Estate";
	Locations[n].filespath.models = "locations\Outside\Estate";
	Locations[n].image = "Eden_estate.tga";
	
	//Sound
	locations[n].type = "silent_jungle";

	//Models
	//Always
	Locations[n].models.always.locators = "Estate_locators_Q2_wreck";
	Locations[n].models.always.jungle = "Estate";
	Locations[n].models.always.window = "estate_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	Locations[n].models.always.grassPatch = "Estate_grass";
	Locations[n].models.always.l1 = "tower1";
	Locations[n].models.always.l2 = "tower2";
	Locations[n].models.always.l3 = "Bonner_house";
	Locations[n].models.always.l4 = "tunnel_entrance";
	Locations[n].models.always.l5 = "tunnel_door";
	Locations[n].models.always.l6 = "townwall";
	Locations[n].models.always.l7 = "shipwreck";

	//Day
	Locations[n].models.day.fonar = "estate_fd";
	Locations[n].models.day.charactersPatch = "estate_patch";
	//Night
	Locations[n].models.night.fonar = "estate_fn";
	Locations[n].models.night.charactersPatch = "estate_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_crypt2_1";
	Locations[n].reload.l1.emerge = "Reload2";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "BB_Eden_bedroom2";
	Locations[n].reload.l2.emerge = "Reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.disable = 1;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "BB_Eden_kitchen";
	Locations[n].reload.l3.emerge = "Reload3";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.disable = 1;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "BB_Eden_bedroom1";
	Locations[n].reload.l4.emerge = "Reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.disable = 1;

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "BB_Eden_office";
	Locations[n].reload.l5.emerge = "Reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.disable = 1;

	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "BB_Eden_chapel";
	Locations[n].reload.l6.emerge = "Reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.disable = 1;

	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "BB_Eden_maze";
	Locations[n].reload.l7.emerge = "Reload2";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].locators_radius.reload.reload7 = 0.001;		//0.7 when detected
	
	Locations[n].reload.l8.name = "reload8";
	Locations[n].reload.l8.go = "BB_Eden_maze";
	Locations[n].reload.l8.emerge = "Reload3";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].locators_radius.reload.reload8 = 0.001;		//0.7 when detected

	Locations[n].reload.l9.name = "reload9";
	Locations[n].reload.l9.go = "BB_Eden_dining_room";
	Locations[n].reload.l9.emerge = "Reload1";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].locators_radius.reload.reload9 = 0.7;
	Locations[n].reload.l9.disable = 1;

	Locations[n].reload.l10.name = "reload10";
	Locations[n].reload.l10.go = "Grand_Cayman_town";
	Locations[n].reload.l10.emerge = "box3";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].locators_radius.reload.reload10 = 0.5;
	
	Locations[n].locators_radius.box.box17 = 1.3;
	Locations[n].locators_radius.box.box18 = 1.5;
	Locations[n].locators_radius.box.box20 = 0.6;
	Locations[n].locators_radius.goto.unlock = 3.0;
	Locations[n].locators_radius.goto.entre = 2.5;
	Locations[n].locators_radius.goto.goto6 = 3.2;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "door_green";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "door_green";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "door_H1_small";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "Boat2_C";

	LAi_LocationMonstersGen(&locations[n], false);
	Locations[n].island = "KhaelRoa";
	n = n + 1;

	//--------------------------------------------------------------------------	

	Locations[n].filespath.models = "locations\Outside\Maze";

	Locations[n].id = "BB_Eden_maze";
	locations[n].id.label = "Garden";
	Locations[n].image = "wr_maze.tga";
	
	//Sound
	locations[n].type = "Chinese_garden";

	//Models
	//Always
	Locations[n].models.always.locators = "Maze_l";
	Locations[n].models.always.L1 = "Maze";
	Locations[n].models.always.L2 = "estate_facade";

	Locations[n].models.always.l3 = "fontain1";
	Locations[n].models.always.l3.locator.group = "quest";
	Locations[n].models.always.l3.locator.name = "quest1";
	Locations[n].models.always.l3.uvslide.u0 = 0.0005;
	Locations[n].models.always.l3.uvslide.v0 = 0.2;
	Locations[n].models.always.l3.level = 999;
	Locations[n].models.always.l3.tech = "LocationWaterFall";
	
	Locations[n].models.always.l4 = "fontain2";
	Locations[n].models.always.l4.locator.group = "quest";
	Locations[n].models.always.l4.locator.name = "quest2";
	Locations[n].models.always.l4.uvslide.u0 = 0.04;
	Locations[n].models.always.l4.uvslide.v0 = 0.01;
	Locations[n].models.always.l4.level = 999;
	Locations[n].models.always.l4.tech = "LocationWaterFall";

	Locations[n].models.always.l5 = "fontain_model";
	Locations[n].models.always.l6 = "apples";
	Locations[n].models.always.l7 = "bushes_plants";
	Locations[n].models.always.l8 = "palms_cart";
	Locations[n].models.always.l9 = "toltecs";	
	
	//Day
	Locations[n].models.day.charactersPatch = "Maze_p";
	//Night
	Locations[n].models.night.charactersPatch = "Maze_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map

	Locations[n].locators_radius.quest.F1 = 2.0;
	Locations[n].locators_radius.quest.F2 = 2.0;
	Locations[n].locators_radius.quest.F3 = 2.0;
	Locations[n].locators_radius.quest.F4 = 2.0;

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_Eden_garden_house";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "bb_Eden_estate";
	Locations[n].reload.l2.emerge = "reload7";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Shore.";
	Locations[n].locators_radius.reload.reload2 = 0.8;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "bb_Eden_estate";
	Locations[n].reload.l3.emerge = "reload8";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Shore.";
	Locations[n].locators_radius.reload.reload3 = 0.8;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "iron_gate3";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "iron_gate3";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "door_green";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "tree2";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "tree2";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "door_window";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "iron_gate3";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "iron_gate3";

	Locations[n].locators_radius.randitem.randitem9 = 0.01;
	Locations[n].items.randitem9 = "door_window";

	Locations[n].locators_radius.randitem.randitem10 = 0.01;
	Locations[n].items.randitem10 = "green";

	Locations[n].locators_radius.randitem.randitem11 = 0.01;
	Locations[n].items.randitem11 = "tree2";

	Locations[n].locators_radius.randitem.randitem12 = 0.01;
	Locations[n].items.randitem12 = "green";

	Locations[n].locators_radius.randitem.randitem13 = 0.01;
	Locations[n].items.randitem13 = "door_green";

	Locations[n].locators_radius.randitem.randitem14 = 0.01;
	Locations[n].items.randitem14 = "door_green";

	Locations[n].locators_radius.randitem.randitem15 = 0.01;
	Locations[n].items.randitem15 = "green";

	Locations[n].locators_radius.randitem.randitem16 = 0.01;
	Locations[n].items.randitem16 = "green";

	Locations[n].locators_radius.randitem.randitem17 = 0.01;
	Locations[n].items.randitem17 = "armchair02";

	Locations[n].locators_radius.randitem.randitem18 = 0.01;
	Locations[n].items.randitem18 = "tree2";
	
	Locations[n].locators_radius.randitem.randitem19 = 0.01;
	Locations[n].items.randitem19 = "tree2";

	Locations[n].locators_radius.randitem.randitem20 = 0.01;
	Locations[n].items.randitem20 = "tree2";

	Locations[n].locators_radius.randitem.randitem21 = 0.01;
	Locations[n].items.randitem21 = "tree1";

	Locations[n].locators_radius.randitem.randitem22 = 0.01;
	Locations[n].items.randitem22 = "tree1";

	Locations[n].locators_radius.randitem.randitem23 = 0.01;
	Locations[n].items.randitem23 = "tree1";

	Locations[n].locators_radius.randitem.randitem24 = 0.01;
	Locations[n].items.randitem24 = "tree1";

	Locations[n].locators_radius.randitem.randitem25 = 0.01;
	Locations[n].items.randitem25 = "tree_barrel";

	Locations[n].locators_radius.randitem.randitem26 = 0.01;
	Locations[n].items.randitem26 = "tree_barrel";

	Locations[n].locators_radius.randitem.randitem27 = 0.01;
	Locations[n].items.randitem27 = "tree_barrel";

	Locations[n].locators_radius.randitem.randitem28 = 0.01;
	Locations[n].items.randitem28 = "tree1";

	Locations[n].locators_radius.randitem.randitem29 = 0.01;
	Locations[n].items.randitem29 = "wheelbarrow";

	Locations[n].locators_radius.randitem.randitem30 = 0.01;
	Locations[n].items.randitem30 = "tree_barrel";

	Locations[n].locators_radius.randitem.randitem31 = 0.01;
	Locations[n].items.randitem31 = "tree_barrel";

	Locations[n].locators_radius.randitem.randitem32 = 0.01;
	Locations[n].items.randitem32 = "tree_barrel";

	Locations[n].locators_radius.randitem.randitem33 = 0.01;
	Locations[n].items.randitem33 = "bench";

	Locations[n].locators_radius.randitem.randitem34 = 0.01;
	Locations[n].items.randitem34 = "bench";

	Locations[n].locators_radius.randitem.randitem35 = 0.01;
	Locations[n].items.randitem35 = "bench";

	Locations[n].locators_radius.randitem.randitem36 = 0.01;
	Locations[n].items.randitem36 = "bench";

	Locations[n].locators_radius.randitem.randitem37 = 0.01;
	Locations[n].items.randitem37 = "tree1";

	Locations[n].locators_radius.randitem.randitem38 = 0.01;
	Locations[n].items.randitem38 = "tree2";

	Locations[n].locators_radius.randitem.randitem39 = 0.01;
	Locations[n].items.randitem39 = "tree2";

	Locations[n].locators_radius.randitem.randitem40 = 0.01;
	Locations[n].items.randitem40 = "tree2";

	Locations[n].locators_radius.randitem.randitem41 = 0.01;
	Locations[n].items.randitem41 = "tree2";

	Locations[n].locators_radius.randitem.randitem42 = 0.01;
	Locations[n].items.randitem42 = "tree2";

	Locations[n].locators_radius.randitem.randitem43 = 0.01;
	Locations[n].items.randitem43 = "tree2";

	Locations[n].locators_radius.randitem.randitem44 = 0.01;
	Locations[n].items.randitem44 = "tree2";

	Locations[n].locators_radius.randitem.randitem45 = 0.01;
	Locations[n].items.randitem45 = "tree2";

	Locations[n].locators_radius.randitem.randitem46 = 0.01;
	Locations[n].items.randitem46 = "tree2";

	Locations[n].locators_radius.randitem.randitem47 = 0.01;
	Locations[n].items.randitem47 = "tree2";

	Locations[n].locators_radius.randitem.randitem48 = 0.01;
	Locations[n].items.randitem48 = "tree2";

	Locations[n].locators_radius.randitem.randitem49 = 0.01;
	Locations[n].items.randitem49 = "tree2";

	Locations[n].locators_radius.randitem.randitem50 = 0.01;
	Locations[n].items.randitem50 = "tree2";

	Locations[n].locators_radius.randitem.randitem51 = 0.01;
	Locations[n].items.randitem51 = "tree2";

	Locations[n].locators_radius.randitem.randitem52 = 0.01;
	Locations[n].items.randitem52 = "tree2";

	Locations[n].locators_radius.randitem.randitem53 = 0.01;
	Locations[n].items.randitem53 = "hedgerow";

	Locations[n].locators_radius.randitem.randitem54 = 0.01;
	Locations[n].items.randitem54 = "hedgerow";

	Locations[n].locators_radius.randitem.randitem55 = 0.01;
	Locations[n].items.randitem55 = "hedgerow";

	Locations[n].locators_radius.randitem.randitem56 = 0.01;
	Locations[n].items.randitem56 = "hedgerow";

	Locations[n].locators_radius.randitem.randitem57 = 0.01;
	Locations[n].items.randitem57 = "hedgerow";

	Locations[n].locators_radius.randitem.randitem58 = 0.01;
	Locations[n].items.randitem58 = "hedgerow";

	Locations[n].locators_radius.randitem.randitem59 = 0.01;
	Locations[n].items.randitem59 = "well";

	Locations[n].locators_radius.randitem.randitem60 = 0.01;
	Locations[n].items.randitem60 = "hedgerow2";

	Locations[n].locators_radius.randitem.randitem61 = 0.01;
	Locations[n].items.randitem61 = "tree_barrel";

	Locations[n].locators_radius.randitem.randitem62 = 0.01;
	Locations[n].items.randitem62 = "hedgerow2";

	Locations[n].locators_radius.randitem.randitem63 = 0.01;
	Locations[n].items.randitem63 = "tree1";


	Locations[n].island = "KhaelRoa";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "bb_Eden_garden_house";
	locations[n].id.label = "Garden house";
	Locations[n].filespath.models = "locations\Inside\ResidenceSmall1";
	Locations[n].filespath.textures = "locations\inside\ResidenceSmall1";	
	Locations[n].image = "wr_garden_house.tga";
	
	//Sound
//	locations[n].type = "residence";
	locations[n].type = "Legrands_house";
	
	//Models
	//Always
	Locations[n].models.always.locators = "resp_l_Q2";
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
	Locations[n].reload.l1.go = "BB_Eden_maze";
	Locations[n].reload.l1.emerge = "arrive1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 0.7;

	Locations[n].locators_radius.box.box1 = 0.8;
	Locations[n].locators_radius.box.box2 = 0.8;
	Locations[n].locators_radius.box.box3 = 0.7;
	Locations[n].locators_radius.box.box4 = 0.001;
	Locations[n].locators_radius.box.box5 = 0.001;
	Locations[n].locators_radius.box.box6 = 0.001;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "tree2";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "tree2";

	Locations[n].island = "Aruba"; // NK 04-08-29
	n = n + 1;

	//--------------------------------------------------------------------------	

	Locations[n].id = "BB_Eden_office";
	locations[n].id.label = "Office";
	Locations[n].filespath.models = "locations\inside\EstateOffice";
	Locations[n].image = "Inside_estate_office.tga";

	//Town sack
	//Locations[n].townsack = "Redmond"; // NK 04-08-29
	//Locations[n].island = "Redmond"; // NK 04-08-29

	//Sound
	locations[n].type = "Rogers_private";
	//Models
	//Always
	Locations[n].models.always.locators = "EstateOffice_locators_Q2_Eden";	//for Eden bribing scene, EstateOffice_locators_Q2 for playing it as Pyle
	Locations[n].models.always.l1 = "estateOffice";
	Locations[n].models.always.window = "estateOffice_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	Locations[n].models.always.grassPatch = "estateOffice_grass";
	//Day
	Locations[n].models.day.fonar = "estateOffice_fd";
	Locations[n].models.day.charactersPatch = "estateOffice_patch";

	//Night
	Locations[n].models.night.fonar = "estateOffice_fn";
	Locations[n].models.night.charactersPatch = "estateOffice_patch";	

	//Environment
	Locations[n].environment.weather = "true";	//yes!
	Locations[n].environment.sea = "false";
	
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_Eden_estate";
	Locations[n].reload.l1.emerge = "Reload5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.disable = 1;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "BB_Eden_tunnel";
	Locations[n].reload.l2.emerge = "Reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.disable = 1;

	Locations[n].locators_radius.box.box1 = 0.7;
	Locations[n].locators_radius.box.box2 = 0.7;
	Locations[n].locators_radius.box.box3 = 0.7;
	Locations[n].locators_radius.box.box4 = 0.7;
	Locations[n].locators_radius.box.box5 = 0.7;
	Locations[n].locators_radius.box.box6 = 0.7;

	Locations[n].island = "Redmond";
	n = n + 1;

	//--------------------------------------------------------------------------

	Locations[n].id = "BB_Eden_bedroom1";
	locations[n].id.label = "Bedroom";
	Locations[n].image = "Inside_estate_bedroom1.tga";
	Locations[n].filespath.models = "locations\inside\EstateBedRoom1\\";
	
	//Sound
//	locations[n].type = "residence";
	locations[n].type = "Estate_sneaking";

	//Models
	//Always
	Locations[n].models.always.l1 = "estateBedRoom1";
	Locations[n].models.always.locators = "EstateBedRoom1_locators_Q2";
	Locations[n].models.always.window = "estateBedRoom1_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	Locations[n].models.always.grassPatch = "estateRooms_grass";
	//Day
	Locations[n].models.day.fonar = "estateRooms_fd";
	Locations[n].models.day.charactersPatch = "estateBedRoom1_patch";

	//Night
	Locations[n].models.night.fonar = "estateRooms_fn";
	Locations[n].models.night.charactersPatch = "estateBedRoom1_patch";

	//Environment
	Locations[n].environment.weather = "true";	//yes!
	Locations[n].environment.sea = "false";
	
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_Eden_estate";
	Locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "BB_Eden_kitchen";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";

	Locations[n].locators_radius.box.box1 = 0.001;
				
	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "door_fort";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond";
	n = n + 1;

	//--------------------------------------------------------------------------

	locations[n].id = "BB_Eden_kitchen";
	locations[n].id.label = "Kitchen";
	Locations[n].image = "Inside_largehouse1.tga";
	
	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
//	locations[n].type = "Vane_towers";
	locations[n].type = "Estate_sneaking";		
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\largehouse01";
	locations[n].models.always.l1 = "largehouse01";
	Locations[n].models.always.l2 = "largehouse01_rand";
	Locations[n].models.always.l3 = "door_sklad";
	locations[n].models.always.locators = "largehouse01_locators_JRH_estate";

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
	locations[n].reload.l1.go = "BB_Eden_bedroom1";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "";
	
	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "BB_Eden_attic1";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "";

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "BB_Eden_estate";
	locations[n].reload.l3.emerge = "reload3";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "";
	Locations[n].reload.l3.disable = 1;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "gatedoor_BRI";	

	Locations[n].locators_radius.box.box1 = 0.001;		//not used

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "KhaelRoa";
	n = n + 1;

	//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Hut_attic";
	Locations[n].id = "BB_Eden_attic1";
	locations[n].id.label = "Attic";
	Locations[n].image = "wr_hut_attic.tga";
	//Sound
	locations[n].type = "Pym_tower";
	//Models
	//Always
	Locations[n].models.always.locators = "Hut_attic_locators_Q2";	//new one soon
	Locations[n].models.always.house = "Hut_attic";

	//Day
	Locations[n].models.day.charactersPatch = "Hut_attic_patch";

	//Night
	Locations[n].models.night.charactersPatch = "Hut_attic_patch";
	Locations[n].models.night.fonar = "Hut_attic_cloth";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Locations[n].models.back = "back\juch_";

	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "BB_Eden_kitchen";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "BB_Eden_attic2";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "";

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_largeh2";	

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "door_largeh";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "gatedoor_pgrey";			
	
	LAi_LocationFightDisable(&Locations[n], true);	
	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;

	//--------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\MediumHouse2";

	Locations[n].id = "BB_Eden_attic2";
	locations[n].id.label = "Attic room";
	Locations[n].image = "wr_mediumhouse2_attic.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Pym_tower";

	//Models
	//Always
	Locations[n].models.always.locators = "MH02_l_Q2";
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
	Locations[n].models.back = "back\juch_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_Eden_attic3";
	Locations[n].reload.l1.emerge = "reload1";			//was reload2
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Woodes Rogers' booty room";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "BB_Eden_attic1";
	Locations[n].reload.l2.emerge = "arrive";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 0.6;

	Locations[n].locators_radius.box.box1 = 0.001;
	Locations[n].locators_radius.box.box2 = 0.001;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "door_N07";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "gatedoor_small_stone";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "gatedoor_small_stone";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "WhalingShip";
	
	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "chair";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "door_largeh";	

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	//--------------------------------------------------------------------------


	Locations[n].filespath.models = "locations\Inside\Hut_attic";
	Locations[n].id = "BB_Eden_attic3";
	locations[n].id.label = "Attic";
	Locations[n].image = "wr_hut_attic.tga";
	//Sound
	locations[n].type = "Pym_tower";
	//Models
	//Always
	Locations[n].models.always.locators = "Hut_attic_locators_Q2_A";
	Locations[n].models.always.house = "Hut_attic";

	//Day
	Locations[n].models.day.charactersPatch = "Hut_attic_patch";

	//Night
	Locations[n].models.night.charactersPatch = "Hut_attic_patch";
	Locations[n].models.night.fonar = "Hut_attic_cloth";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Locations[n].models.back = "back\juch_";

	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "BB_Eden_attic2";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "BB_Eden_dining_room";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "";

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "hatch11";	

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "door_N07";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "gatedoor_pgrey";			
	
	LAi_LocationFightDisable(&Locations[n], true);	
	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;

	//--------------------------------------------------------------------------

	Locations[n].id = "BB_Eden_dining_room";
	locations[n].id.label = "Dining room";
	Locations[n].image = "Inside_diningroom.tga";
	Locations[n].filespath.models = "locations\inside\Dining_room\\";
	
	//Sound
//	locations[n].type = "residence";
	locations[n].type = "Estate_sneaking";

	//Models
	//Always
	Locations[n].models.always.l1 = "Dining_room";
	
	Locations[n].models.always.window = "Dining_room_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	Locations[n].models.always.grassPatch = "estateRooms_grass";
	//Day
	Locations[n].models.day.locators = "Dining_room_locators_Q2";
	Locations[n].models.day.charactersPatch = "Dining_room_patch";

	//Night
	Locations[n].models.night.locators = "Dining_room_Nlocators_Q2";
	Locations[n].models.night.charactersPatch = "Dining_room_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\juch2_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_Eden_estate";
	Locations[n].reload.l1.emerge = "reload9";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	Locations[n].reload.l1.disable = 1;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "BB_Eden_attic3";
	Locations[n].reload.l2.emerge = "arrive";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.7;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "BB_Eden_bedroom2";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.7;

	Locations[n].locators_radius.box.box1 = 0.001;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "hatch11D";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "door_fort";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "rope_ale";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond";
	n = n + 1;

	//--------------------------------------------------------------------------

	Locations[n].id = "BB_Eden_bedroom2";
	locations[n].id.label = "Bedroom";
	Locations[n].image = "Inside_estate_bedroom2.tga";
	Locations[n].filespath.models = "locations\inside\EstateBedRoom2\\";
	
	//Sound
	locations[n].type = "Estate_sneaking";

	//Models
	//Always
	Locations[n].models.always.l1 = "estateBedRoom2";
	Locations[n].models.always.locators = "EstateBedRoom2_locators_Q2";
	Locations[n].models.always.window = "estateBedRoom2_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	Locations[n].models.always.grassPatch = "estateRooms_grass";
	//Day
	Locations[n].models.day.fonar = "estateRooms_fd";
	Locations[n].models.day.charactersPatch = "estateBedRoom2_patch";

	//Night
	Locations[n].models.night.fonar = "estateRooms_fn";
	Locations[n].models.night.charactersPatch = "estateBedRoom2_patch";

	//Environment
	Locations[n].environment.weather = "true";	//yes!
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_Eden_estate";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	Locations[n].reload.l1.disable = 1;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "BB_Eden_tower";
	Locations[n].reload.l2.emerge = "reload4";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "BB_Eden_dining_room";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "";

	Locations[n].locators_radius.box.box1 = 0.001;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "door_fort";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond";
	n = n + 1;

	//--------------------------------------------------------------------------

	Locations[n].id = "BB_Eden_tower";
	locations[n].id.label = "Chapel stairs";
	Locations[n].filespath.models = "locations\inside\store04";
	Locations[n].filespath.textures = "locations\inside\store04\church";
	Locations[n].image = "wr_chapel_stairs.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Pym_tower";

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

	//Reload map
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "BB_Eden_bedroom2";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";

	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "BB_Eden_chapel";
	Locations[n].reload.l7.emerge = "reload2";
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

	Locations[n].id = "BB_Eden_chapel";
	locations[n].id.label = "Chapel";
	Locations[n].image = "Inside_chapel.tga";
	Locations[n].filespath.models = "locations\inside\Church_2\\";
//	Locations[n].filespath.textures = "locations\inside\Church_2\chapel";
	
	//Sound
//	locations[n].type = "Vane_chapel";
	locations[n].type = "crypt";

	//Models
	//Always
	Locations[n].models.always.city = "Church2";
	Locations[n].models.always.l1 = "girder_block";
	Locations[n].models.always.locators = "Church2_l_Q2";
	Locations[n].models.always.window = "church2_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Church2_p";

	//Night
	Locations[n].models.night.charactersPatch = "Church2_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_Eden_estate";
	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	Locations[n].locators_radius.reload.reload1 = 0.001;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "BB_Eden_tower";
	Locations[n].reload.l2.emerge = "goto3";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";		

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "door_N07";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond";
	n = n + 1;
	
	//--------------------------------------------------------------------------
	//--------------------------------------------------------------------------	

	Locations[n].id = "BB_Teach_kitchen";
	locations[n].id.label = "Teach house";
	Locations[n].filespath.models = "locations\inside\DoubleFlour_house";
	Locations[n].image = "Inside_Doubleflour_House_Lower.tga";

	//Town sack
//	Locations[n].townsack = "Douwesen";

	//Sound
	//locations[n].type = "Rogers_residence";
	locations[n].type = "Blackbeard_house";

	//Models
	//Always
	Locations[n].models.always.locators = "LH_F1_l_Q2";
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
	Locations[n].reload.l1.go = "BB_Teach_drawing_room";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Lieutenant_G_bedroom";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 0.8;
	Locations[n].reload.l2.disable = 1;

	Locations[n].reload.l3.name = "reload3";		
	Locations[n].reload.l3.go = "Lieutenant_G_office";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].locators_radius.reload.reload3 = 0.8;
	Locations[n].reload.l3.disable = 1;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "BB_Eden_estate";
	Locations[n].reload.l4.emerge = "box4";		
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Redmond.";
	Locations[n].locators_radius.reload.reload4 = 0.6;

	Locations[n].locators_radius.box.box1 = 0.01;
	Locations[n].locators_radius.box.box2 = 0.01;
	Locations[n].locators_radius.box.box3 = 0.01;
	Locations[n].locators_radius.box.box4 = 0.01;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_A05";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "door_A05R";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "door_fort";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "gatedoor_BRI";

	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;

	//--------------------------------------------------------------------------	

	Locations[n].filespath.models = "locations\Inside\Residence3";

	Locations[n].id = "BB_Teach_drawing_room";
	locations[n].id.label = "Teach room";			//open = on
	Locations[n].image = "wr_Teach_room.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Blackbeard_house";

	//Models
	//Always
	Locations[n].models.always.locators = "Res03_l_Teach";
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
	Locations[n].models.back = "back\juch2_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_Teach_kitchen";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Woodes Rogers' library.";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "BB_Eden_estate";
	Locations[n].reload.l2.emerge = "box5";		
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Redmond.";
	Locations[n].locators_radius.reload.reload2 = 0.6;

	Locations[n].locators_radius.goto.goto8 = 0.7;
	Locations[n].locators_radius.box.box1 = 1.0;
	Locations[n].locators_radius.box.box2 = 1.0;

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	//--------------------------------------------------------------------------

	locations[n].id = "BB_Eden_tunnel";
	locations[n].id.label = "Estate wine cellar";
	Locations[n].image = "Inside_wine_cellar.tga";
	//Town sack
	locations[n].townsack = "Redmond";
	//Sound
	locations[n].type = "Rogers_cellar";
	
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Wine_cellar2";
	locations[n].models.always.DungeonVault1 = "DungeonVault2";
	locations[n].models.always.InquisitionDungeonVault2Fonars = "DungeonVault2_fonars";
	locations[n].models.always.locators = "DungeonVault2_locators_Q2";	
	Locations[n].models.always.l1 = "tunnel_entrance";
	Locations[n].models.always.l2 = "tunnel_door";
	Locations[n].models.always.l3 = "elevator_down";		//down or up, start = down
	Locations[n].models.always.l4 = "bars_up";			//down or up, start = up
	Locations[n].models.always.l5 = "lever1_down";			//down or up, start = down
	Locations[n].models.always.l6 = "lever2_up";			//down or up, start = up
	Locations[n].models.always.l7 = "";				//"", barrel_elevator_down or _up, start = ""
	Locations[n].models.always.l8 = "";				//"", bottle_elevator_down or _up, start = ""
	Locations[n].models.always.l9 = "barrel_niche";			//niche, 
	Locations[n].models.always.l10 = "bottle_niche_cork";		//niche, niche_cork, start = niche_cork   
	Locations[n].models.always.l11 = "bars2_down";			//down or up, start = down	

	//Day
	locations[n].models.day.charactersPatch = "DungeonVault2_patch";
	//Night
	locations[n].models.night.charactersPatch = "DungeonVault2_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
//	Locations[n].MaxSeaHeight = 0.0;
//	Locations[n].environment.cellar = "true";		//water color

	//Reload map

	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "BB_Eden_office";		
	locations[n].reload.l1.emerge = "reload3";			//was reload2		
	locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.disable = 1;				//start = locked

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "BB_Eden_estate";
	locations[n].reload.l2.emerge = "box13";
	locations[n].reload.l2.autoreload = "0";
	locations[n].locators_radius.reload.reload2_back = 0.7;

	locations[n].locators_radius.goto.steplock = 0.4;		//start 0.001?
	locations[n].locators_radius.goto.elevator1 = 1.2;
	locations[n].locators_radius.goto.elevator2 = 1.2;
	locations[n].locators_radius.goto.gate_back1 = 0.2;
	locations[n].locators_radius.goto.gate_back2 = 0.2;
	locations[n].locators_radius.goto.gate2_back = 0.2;
	locations[n].locators_radius.goto.gate_stop1 = 0.001;		//0.5 later
	locations[n].locators_radius.goto.gate_stop2 = 0.001;		//0.5 later
	locations[n].locators_radius.goto.door_where = 1.0;
	locations[n].locators_radius.box.box3 = 0.001;			//0.7 later
	locations[n].locators_radius.box.box5 = 0.7;
	locations[n].locators_radius.box.box4 = 1.2;
	locations[n].locators_radius.box.box6 = 0.7;
	locations[n].locators_radius.box.box7 = 0.7;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "steplock";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "steplock_v";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "steplock_v";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "steplock";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "key16";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond";
	n = n + 1;

	//--------------------------------------------------------------------------

	Locations[n].id = "open_today";		//to enable special label for locked location in Kristiania
	locations[n].id.label = "Repairs finished. The Gate will open today.";
	Locations[n].image = "Inside_Grot.tga";
	//Sound
	locations[n].type = "silent_cave_seashore";
	//Models
	Locations[n].models.back = "back\grotenv_";
	Locations[n].filespath.models = "locations\Inside\Grot";
	//Always
	Locations[n].models.always.cave = "Grot";
	Locations[n].models.always.locators = "Grot_l_JRH";
	//Day
	Locations[n].models.day.charactersPatch = "Grot_p";
	//Night
	Locations[n].models.night.charactersPatch = "Grot_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Swamp_island2";
	Locations[n].reload.l1.emerge = "reload9";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "BB_careen_shore";
	Locations[n].filespath.models = "locations\Outside\Shore_6";
	Locations[n].image = "wr_careen_shore.tga";

	Locations[n].townsack = "Grand Turk"; 

	//Sound
	locations[n].type = "silent_seashore";

	//Models
	//Always
	Locations[n].models.always.locators = "Shore06_l_careen";
//Locations[n].models.always.locators = "Shore06_l_careen_S3";		//testing
	Locations[n].models.always.shore = "Shore06";
	Locations[n].models.always.shore.foam = "1";
	Locations[n].models.always.seabed = "Shore06_sb";
	Locations[n].models.always.seabed.foam = "1";
	//Locations[n].models.always.grassPatch = "Shore06_g";
	Locations[n].models.always.l1 = "FR_Sloop_careen";
//Locations[n].models.always.l1 = "FR_Sloop_careen_hit";
	Locations[n].models.always.l2 = "flagpole";
	Locations[n].models.always.l3 = "stoneblock";
	Locations[n].models.always.l4 = "stoneblock1";
	Locations[n].models.always.l5 = "";
//Locations[n].models.always.l5 = "FR_sloop_railing";		//start ""

	//Day
	Locations[n].models.day.charactersPatch = "Shore06_p";
	//Night
	Locations[n].models.night.charactersPatch = "Shore06_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_careen_blockhouse";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1 = 1;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "FalaiseDeFleur";
	Locations[n].reload.l2.emerge = "reload_2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 0.001;

	Locations[n].locators_radius.quest.1 = 3.0;
	Locations[n].locators_radius.quest.2 = 3.0;
	Locations[n].locators_radius.quest.3 = 3.0;
	Locations[n].locators_radius.quest.4 = 1.5;
	Locations[n].locators_radius.quest.5 = 1.7;
	Locations[n].locators_radius.quest.6 = 3.0;
	Locations[n].locators_radius.quest.pyle_swim = 2.5;

	Locations[n].locators_radius.barmen.7 = 3.3;
	Locations[n].locators_radius.barmen.8 = 3.3;
	Locations[n].locators_radius.barmen.9 = 3.0;

	Locations[n].locators_radius.box.box2 = 2.2;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.box.box6 = 0.001;		//0.5 later
	Locations[n].locators_radius.box.box7 = 2.0;
	Locations[n].locators_radius.box.box8 = 0.5;
	Locations[n].locators_radius.box.box9 = 0.5;
	Locations[n].locators_radius.box.box10 = 0.5;
	Locations[n].locators_radius.box.box13 = 0.2;
	Locations[n].locators_radius.box.box14 = 0.2;
	Locations[n].locators_radius.box.box15 = 0.001;		//0.5 later

	Locations[n].locators_radius.goto.trigger1 = 18.0;
	Locations[n].locators_radius.goto.trigger2 = 9.0;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "rope_horizontal_long";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "dovecote";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "rope_horizontal_long";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "rope_horizontal_long";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "rope_horizontal_long";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "cannon2";

	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "cannon2";

	Locations[n].locators_radius.randitem.randitem8 = 0.01;
	Locations[n].items.randitem8 = "door_Tortuga";

	Locations[n].locators_radius.randitem.randitem9 = 0.01;
	Locations[n].items.randitem9 = "cannon2";

	Locations[n].locators_radius.randitem.randitem10 = 0.01;
	Locations[n].items.randitem10 = "cannon2";

	Locations[n].locators_radius.randitem.randitem11 = 0.01;
	Locations[n].items.randitem11 = "cannon2";

	Locations[n].locators_radius.randitem.randitem12 = 0.01;
	Locations[n].items.randitem12 = "cannon2";

	Locations[n].locators_radius.randitem.randitem13 = 0.01;
	Locations[n].items.randitem13 = "watchtower";

	Locations[n].locators_radius.randitem.randitem14 = 0.01;
	Locations[n].items.randitem14 = "chimney_pot_night";

	Locations[n].locators_radius.randitem.randitem15 = 0.01;
	Locations[n].items.randitem15 = "cannon2";

	Locations[n].locators_radius.randitem.randitem16 = 0.01;
	Locations[n].items.randitem16 = "cannon2";

	Locations[n].locators_radius.randitem.randitem17 = 0.01;
	Locations[n].items.randitem17 = "cannon2";

	Locations[n].locators_radius.randitem.randitem18 = 0.01;
	Locations[n].items.randitem18 = "ladder_biggest";

	Locations[n].locators_radius.randitem.randitem19 = 0.01;
	Locations[n].items.randitem19 = "barrel3";

	Locations[n].locators_radius.randitem.randitem20 = 0.01;
	Locations[n].items.randitem20 = "smg11";

	Locations[n].locators_radius.randitem.randitem21 = 0.01;
	Locations[n].items.randitem21 = "roll_of_planks1";

	Locations[n].locators_radius.randitem.randitem22 = 0.01;
	Locations[n].items.randitem22 = "port_mast1";

	Locations[n].locators_radius.randitem.randitem23 = 0.01;
	Locations[n].items.randitem23 = "cannon2";

	Locations[n].locators_radius.randitem.randitem24 = 0.01;
	Locations[n].items.randitem24 = "port_rey1";

	Locations[n].locators_radius.randitem.randitem25 = 0.01;
	Locations[n].items.randitem25 = "port_rey1";

	Locations[n].locators_radius.randitem.randitem26 = 0.01;
	Locations[n].items.randitem26 = "roll_of_planks1";

	Locations[n].locators_radius.randitem.randitem27 = 0.01;
	Locations[n].items.randitem27 = "chair";

	Locations[n].locators_radius.randitem.randitem28 = 0.01;
	Locations[n].items.randitem28 = "chair";

	Locations[n].locators_radius.randitem.randitem29 = 0.01;
	Locations[n].items.randitem29 = "TextileA";

	Locations[n].locators_radius.randitem.randitem30 = 0.01;
	Locations[n].items.randitem30 = "TextileA";

	Locations[n].locators_radius.randitem.randitem31 = 0.01;
	Locations[n].items.randitem31 = "rum_party1";

	Locations[n].locators_radius.randitem.randitem32 = 0.01;
	Locations[n].items.randitem32 = "derrick";

	Locations[n].locators_radius.randitem.randitem33 = 0.01;
	Locations[n].items.randitem33 = "dovecote";			//just to hide the sky behind the visible house

	Locations[n].locators_radius.randitem.randitem34 = 0.01;
	Locations[n].items.randitem34 = "anchor_big";

	Locations[n].locators_radius.randitem.randitem35 = 0.01;
	Locations[n].items.randitem35 = "cannon2";

	Locations[n].locators_radius.randitem.randitem36 = 0.01;
	Locations[n].items.randitem36 = "ladder_biggest";

	Locations[n].locators_radius.randitem.randitem37 = 0.01;
	Locations[n].items.randitem37 = "smuggler_goods";

	Locations[n].locators_radius.randitem.randitem38 = 0.01;
	Locations[n].items.randitem38 = "2_close_boxes";

	Locations[n].locators_radius.randitem.randitem39 = 0.01;
	Locations[n].items.randitem39 = "small_planks";

	Locations[n].locators_radius.randitem.randitem40 = 0.01;
	Locations[n].items.randitem40 = "bonfire";

	Locations[n].locators_radius.randitem.randitem41 = 0.01;
	Locations[n].items.randitem41 = "rum_party1";

	Locations[n].locators_radius.randitem.randitem42 = 0.01;
	Locations[n].items.randitem42 = "cannon2";

	Locations[n].locators_radius.randitem.randitem43 = 0.01;
	Locations[n].items.randitem43 = "bench";

	Locations[n].locators_radius.randitem.randitem44 = 0.01;
	Locations[n].items.randitem44 = "anvil";

	Locations[n].locators_radius.randitem.randitem45 = 0.01;
	Locations[n].items.randitem45 = "barrel3";

	Locations[n].locators_radius.randitem.randitem46 = 0.01;
	Locations[n].items.randitem46 = "boat2_C";

	Locations[n].locators_radius.randitem.randitem47 = 0.01;
	Locations[n].items.randitem47 = "boat2_B";

	Locations[n].locators_radius.randitem.randitem48 = 0.01;
	Locations[n].items.randitem48 = "bench";

	Locations[n].locators_radius.randitem.randitem49 = 0.01;
	Locations[n].items.randitem49 = "plank2_very_long_dark";

	Locations[n].locators_radius.randitem.randitem50 = 0.001;		//not used
	Locations[n].items.randitem50 = "lilgun";

	Locations[n].locators_radius.randitem.randitem51 = 0.001;
	Locations[n].items.randitem51 = "palm2";

	Locations[n].locators_radius.randitem.randitem52 = 0.001;
	Locations[n].items.randitem52 = "palm2_big";

	Locations[n].locators_radius.randitem.randitem53 = 0.001;
	Locations[n].items.randitem53 = "palm3";

	Locations[n].locators_radius.randitem.randitem54 = 0.001;
	Locations[n].items.randitem54 = "palm2_big";

	Locations[n].locators_radius.randitem.randitem55 = 0.001;
	Locations[n].items.randitem55 = "palm2";

	Locations[n].locators_radius.randitem.randitem56 = 0.001;
	Locations[n].items.randitem56 = "palm2";

	Locations[n].locators_radius.randitem.randitem57 = 0.001;
	Locations[n].items.randitem57 = "palm2_big_night";

	Locations[n].locators_radius.randitem.randitem58 = 0.001;
	Locations[n].items.randitem58 = "palm2_big_night";

	Locations[n].locators_radius.randitem.randitem59 = 0.001;
	Locations[n].items.randitem59 = "palm2_big";

	Locations[n].locators_radius.randitem.randitem60 = 0.001;
	Locations[n].items.randitem60 = "palm2_big_night";

	Locations[n].locators_radius.randitem.randitem61 = 0.001;
	Locations[n].items.randitem61 = "palm2";

	Locations[n].locators_radius.randitem.randitem62 = 0.001;
	Locations[n].items.randitem62 = "palm2";

	Locations[n].locators_radius.randitem.randitem63 = 0.001;
	Locations[n].items.randitem63 = "palm3";

	Locations[n].locators_radius.randitem.randitem64 = 0.001;
	Locations[n].items.randitem64 = "palm2_big";

	Locations[n].locators_radius.randitem.randitem65 = 0.001;
	Locations[n].items.randitem65 = "palm2_big";

	Locations[n].locators_radius.randitem.randitem66 = 0.001;
	Locations[n].items.randitem66 = "palm2_big";

	Locations[n].locators_radius.randitem.randitem67 = 0.001;
	Locations[n].items.randitem67 = "palm2_big";

	Locations[n].locators_radius.randitem.randitem68 = 0.5;
	Locations[n].items.randitem68 = "potionrum";

	Locations[n].locators_radius.randitem.randitem69 = 0.5;
	Locations[n].items.randitem69 = "potionrum";

	Locations[n].locators_radius.randitem.randitem70 = 0.01;
	Locations[n].items.randitem70 = "cannon2";

	Locations[n].locators_radius.randitem.randitem71 = 0.01;
	Locations[n].items.randitem71 = "cannon2";

	Locations[n].locators_radius.randitem.randitem72 = 0.01;
	Locations[n].items.randitem72 =	"key8";			//invisible, was rope_ale

	Locations[n].locators_radius.randitem.randitem73 = 0.01;
	Locations[n].items.randitem73 = "rope_horizontal_long";
    //-------------------------------------------------------------
	Locations[n].locators_radius.randitem.randitem74 = 0.01;
	Locations[n].items.randitem74 = "derrick_broken";

	Locations[n].locators_radius.randitem.randitem75 = 0.01;
	Locations[n].items.randitem75 = "brF17W";

	Locations[n].locators_radius.randitem.randitem76 = 0.01;
	Locations[n].items.randitem76 = "brF17W";

	Locations[n].locators_radius.randitem.randitem77 = 0.01;
	Locations[n].items.randitem77 = "brF7R";

	Locations[n].locators_radius.randitem.randitem78 = 0.01;
	Locations[n].items.randitem78 = "mast_bridge";

	Locations[n].locators_radius.randitem.randitem79 = 0.01;
	Locations[n].items.randitem79 = "hatch12";				//not used, invisible	

	Locations[n].locators_radius.randitem.randitem80 = 0.01;
	Locations[n].items.randitem80 = "brF17W";

	Locations[n].locators_radius.randitem.randitem81 = 0.01;
	Locations[n].items.randitem81 = "rope_45_long";			//other end of rope ri73

	Locations[n].locators_radius.randitem.randitem82 = 0.01;
	Locations[n].items.randitem82 = "rope_45_long";			//other end of rope ri3

	Locations[n].locators_radius.randitem.randitem83 = 0.01;
	Locations[n].items.randitem83 = "rope_45_long";			//other end of rope ri1

	Locations[n].locators_radius.randitem.randitem84 = 0.01;
	Locations[n].items.randitem84 = "rope_45_long";			//other end of rope ri4

	Locations[n].locators_radius.randitem.randitem85 = 0.01;
	Locations[n].items.randitem85 = "rope_45_long";			//other end of rope ri5

	Locations[n].locators_radius.randitem.randitem86 = 0.01;
	Locations[n].items.randitem86 = "watchtower_damaged";		//replaces ri13, loc file T

	Locations[n].locators_radius.randitem.randitem87 = 0.01;
	Locations[n].items.randitem87 = "watchtower_roof";
     //-------------------------------------------------------------
	Locations[n].locators_radius.randitem.randitem88 = 0.001;
	Locations[n].items.randitem88 = "mket_item";

	Locations[n].locators_radius.randitem.randitem89 = 0.001;
	Locations[n].items.randitem89 = "mket_item";

	Locations[n].locators_radius.randitem.randitem90 = 0.001;
	Locations[n].items.randitem90 = "mket_item";

	Locations[n].locators_radius.randitem.randitem91 = 0.001;
	Locations[n].items.randitem91 = "mket_item";

	Locations[n].locators_radius.randitem.randitem92 = 0.001;
	Locations[n].items.randitem92 = "mket_item";

     //-------------------------------------------------------------
	Locations[n].locators_radius.randitem.randitem93 = 0.001;
	Locations[n].items.randitem93 = "mket_item";

	Locations[n].locators_radius.randitem.randitem94 = 0.001;
	Locations[n].items.randitem94 = "mket_item";

	Locations[n].locators_radius.randitem.randitem95 = 0.001;
	Locations[n].items.randitem95 = "mket_item";

	Locations[n].locators_radius.randitem.randitem96 = 0.001;
	Locations[n].items.randitem96 = "mket_item";

	Locations[n].locators_radius.randitem.randitem97 = 0.001;
	Locations[n].items.randitem97 = "mket_item";

	Locations[n].locators_radius.randitem.randitem98 = 0.001;
	Locations[n].items.randitem98 = "mket_item";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Turks"; // NK 04-08-29
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "BB_careen_blockhouse";
	locations[n].id.label = "Blockhouse";
	Locations[n].image = "wr_careen_blockhouse.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "silent_cave_seashore";

	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Smallhome";
	Locations[n].filespath.textures = "locations\inside\Smallhome\farm";
	Locations[n].models.always.city = "sh";
	Locations[n].models.always.locators = "sh_l_JRH_car";
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
	Locations[n].models.back = "back\farm_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_careen_shore";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	Locations[n].locators_radius.reload.reload1 = 0.6;
	Locations[n].reload.l1.disable = 1;				//start = locked

	Locations[n].locators_radius.box.box1 = 1.5;
	Locations[n].locators_radius.box.box3 = 0.001;			//unlock function door to shore

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "porthole";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "porthole";
	
	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "door_Tortuga";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "door_largeh2";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "porthole";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "mket_item";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "mket_item";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "mket_item";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "hatch11D";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "ladder_big";

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//...........................................................................
//careen corvette start

	Locations[n].id = "BB_careen_corvette";
	locations[n].id.label = "Weather deck";
	//Info
	Locations[n].filespath.models = "locations\decks\qdeck";
	Locations[n].image = "Sea.tga";
	//Sound
	locations[n].type = "silent_seashore";		

	Locations[n].lockCamAngle = 0.4;

	//Models
	//Always
	Locations[n].models.always.locators = "qdeck_l_careen";		
	Locations[n].models.always.l1 = "qdeck";

	//Day
	Locations[n].models.day.charactersPatch = "qdeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "qdeck_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_careen_capmd_2";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "BB_careen_deck2";
	Locations[n].reload.l2.emerge = "reload4";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "BB_careen_deck1";
	Locations[n].reload.l3.emerge = "reload5";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "";	
	
	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "hatch12";

	Locations[n].rats = "true";
	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Redmond";
	n = n + 1;

//--------------------------------------------------------------------------
//careen corvette end

	Locations[n].id = "BB_careen_corvette_end";
	locations[n].id.label = "Weather deck";
	//Info
	Locations[n].filespath.models = "locations\decks\qdeck";
	Locations[n].image = "Sea.tga";
	//Sound
	locations[n].type = "silent_seashore";		

	Locations[n].lockCamAngle = 0.4;

	//Models
	//Always
	Locations[n].models.always.locators = "qdeck_l_careen_end";		
	Locations[n].models.always.l1 = "qdeck";

	//Day
	Locations[n].models.day.charactersPatch = "qdeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "qdeck_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_careen_capmd_2";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	Locations[n].reload.l1.disable = 1;				//blocked from inside
	Locations[n].locators_radius.reload.reload1 = 0.001;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "BB_careen_deck2";
	Locations[n].reload.l2.emerge = "reload4";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.001;

	Locations[n].reload.l3.name = "reload3_back";
	Locations[n].reload.l3.go = "BB_careen_deck1";
	Locations[n].reload.l3.emerge = "reload5";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3_back = 0.001;

	Locations[n].reload.l4.name = "boat";
	Locations[n].reload.l4.go = "IslaMona_port";
	Locations[n].reload.l4.emerge = "boat";
	Locations[n].reload.l4.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 0.001;	
	
	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "hatch12";

	Locations[n].rats = "true";
	Locations[n].island = "Redmond";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "BB_careen_capmd_2";
	Locations[n].id.label = "Captain's cabin";
	//Info
	Locations[n].filespath.models = "locations\decks\cabin\capmd_2";
	Locations[n].image = "wr_careen_capmd.tga";
	//Sound
	Locations[n].type = "silent_cabin";

	//Models
	//Always
	Locations[n].models.always.locators = "capmd_2_l_careen";	
	Locations[n].models.always.l1 = "capmd_2";
	Locations[n].models.always.l2 = "capmd_2_rand";
	Locations[n].models.always.l4 = "carpet2";
	Locations[n].models.always.l5 = "weapons_locker";

	Locations[n].models.always.window = "capmd_2_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;

	//Day
	Locations[n].models.day.charactersPatch = "capmd_2_patch";
	Locations[n].models.day.l3 = "capmd_2_ld";

	//Night
	Locations[n].models.night.charactersPatch = "capmd_2_patch";
	Locations[n].models.night.l3 = "capmd_2_ln";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	//Reload map
	Locations[n].locators_radius.reload.reload1 = 0.001;		//not used	

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "BB_careen_capsm";
	Locations[n].reload.l2.emerge = "goto2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.001;		//0.7 later

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "BB_careen_corvette";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.8;

	Locations[n].locators_radius.rld.aloc0 = 0.001;
	Locations[n].locators_radius.rld.aloc1 = 0.001;
	Locations[n].locators_radius.rld.aloc2 = 0.001;
	Locations[n].locators_radius.rld.aloc3 = 0.001;
	Locations[n].locators_radius.rld.loc0 = 0.001;
	Locations[n].locators_radius.rld.loc1 = 0.001;
	Locations[n].locators_radius.rld.loc2 = 0.001;

	Locations[n].locators_radius.box.box2 = 1.3;
	Locations[n].locators_radius.box.box3 = 1.3;
	Locations[n].locators_radius.box.box4 = 0.001;
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.box.box6 = 0.5;
	Locations[n].locators_radius.box.box7 = 0.8;
	Locations[n].locators_radius.box.box8 = 0.8;
	Locations[n].locators_radius.box.box9 = 0.8;
	Locations[n].locators_radius.box.box10 = 0.5;

	Locations[n].locators_radius.quest.king_inner = 0.2;
	Locations[n].locators_radius.quest.king_outer = 0.2;
	
	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "book62";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "key8";				//invisible

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "hatch11_S";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "key39";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "pillow1";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "handle";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "handle";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "pitchfork";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "pitchfork_item";

	Locations[n].rats = "true";
	Locations[n].island = "Redmond";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "BB_careen_capsm";
	Locations[n].id.label = "Small Cabin";
	//Info
	Locations[n].filespath.models = "locations\decks\cabin\capsm";
	Locations[n].filespath.textures = "locations\decks\red";
	Locations[n].image = "wr_careen_capsm.tga";
	//Sound
	Locations[n].type = "silent_deck";

	//Models
	//Always
	Locations[n].models.always.locators = "capsm_l_careen";
	Locations[n].models.always.l1 = "capsm";
	Locations[n].models.always.l2 = "stopboom_hatch";

	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "capsm_p";
	Locations[n].models.day.fonar = "capsm_fd";
	//Night
	Locations[n].models.night.charactersPatch = "capsm_p";
	Locations[n].models.night.fonar = "capsm_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	//Reload map

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_careen_deck2";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	Locations[n].locators_radius.reload.reload1 = 0.6;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "BB_careen_capmd_2";
	Locations[n].reload.l2.emerge = "R2";		//instead of reload2
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";

	Locations[n].locators_radius.box.box2 = 1.7;
	Locations[n].locators_radius.quest.start = 2.3;
	
	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "hatch11D";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "Gatefloor_w";
//--------------------------------------------------------------------
	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "hatch11D_O2";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "Gatefloor_w2";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
//	Locations[n].items.randitem5 = "hatch11V";
	Locations[n].items.randitem5 = "hatch11_T";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "rope_ale";

	Locations[n].rats = "true";
	LAi_LocationFightDisable(&Locations[n], true);			//enabled later when you got the right tool
	Locations[n].island = "Redmond";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "BB_careen_deck1";
	Locations[n].id.label = "Gun deck prow";
	//Info
	Locations[n].filespath.models = "locations\decks\deck1_red";
	Locations[n].image = "wr_careen_crew.tga";
	//Sound
	Locations[n].type = "silent_sneaking_deck";
	
	//Models
	//Always
	Locations[n].models.always.locators = "deck1_l_careen";
	Locations[n].models.always.l1 = "deck1";	
	//Day
	Locations[n].models.day.charactersPatch = "deck1_p";
	Locations[n].models.day.fonar = "deck1_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deck1_p";
	Locations[n].models.night.fonar = "deck1_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	//to weather deck
	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "BB_careen_corvette";
	Locations[n].reload.l5.emerge = "reload3";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "";

	//to deck2
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "BB_careen_deck2";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";

	//to deck2
	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "BB_careen_deck2";
	Locations[n].reload.l7.emerge = "reload3";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "";
	Locations[n].reload.l7.disable = 1;

	//to hold animals
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_careen_holdP";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";

	//to hold convicts
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "BB_careen_holdPP";		//locked to fake location - but gives label
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].reload.l2.disable = 1;

	Locations[n].locators_radius.quest.KD_guard = 2.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "ladder_hold";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "box";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "hatch12R";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "hatch12R";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "2groups_of_boxes";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "blade3carpets";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "barrel_big";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "box";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "box";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "barrel_roll";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "basket";

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "cannon_pipe2";
	
	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "box";

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
	Locations[n].items.randitem14 = "clock_big";

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	Locations[n].items.randitem15 = "clock_big";

	Locations[n].locators_radius.randitem.randitem16 = 0.001;
	Locations[n].items.randitem16 = "anvil";

	Locations[n].locators_radius.randitem.randitem17 = 0.001;
	Locations[n].items.randitem17 = "hatch12";

	Locations[n].locators_radius.randitem.randitem18 = 0.001;
	Locations[n].items.randitem18 = "hatch12";

	Locations[n].locators_radius.randitem.randitem19 = 0.001;
	Locations[n].items.randitem19 = "hammock_ropes";

	Locations[n].locators_radius.randitem.randitem20 = 0.001;
	Locations[n].items.randitem20 = "hammock_ropes";

	Locations[n].locators_radius.randitem.randitem21 = 0.001;
	Locations[n].items.randitem21 = "hammock_ropes";

	Locations[n].locators_radius.randitem.randitem22 = 0.001;
	Locations[n].items.randitem22 = "hammock_ropes";

	Locations[n].locators_radius.randitem.randitem23 = 0.001;
	Locations[n].items.randitem23 = "hammock_ropes";

	Locations[n].locators_radius.randitem.randitem24 = 0.001;
	Locations[n].items.randitem24 = "hammock_ropes";

	Locations[n].locators_radius.randitem.randitem25 = 0.001;
	Locations[n].items.randitem25 = "hammock_ropes";

	Locations[n].locators_radius.randitem.randitem26 = 0.001;
	Locations[n].items.randitem26 = "hammock_ropes";

	Locations[n].locators_radius.randitem.randitem27 = 0.001;
	Locations[n].items.randitem27 = "hammock_ropes";

	Locations[n].locators_radius.randitem.randitem28 = 0.001;
	Locations[n].items.randitem28 = "hammock_ropes";

	Locations[n].locators_radius.randitem.randitem29 = 0.001;
	Locations[n].items.randitem29 = "hammock_ropes";

	Locations[n].locators_radius.randitem.randitem30 = 0.001;
	Locations[n].items.randitem30 = "hammock_ropes";

	Locations[n].locators_radius.randitem.randitem31 = 0.001;
	Locations[n].items.randitem31 = "hammock_ropes";

	Locations[n].locators_radius.randitem.randitem32 = 0.001;
	Locations[n].items.randitem32 = "hammock_ropes";

	Locations[n].locators_radius.randitem.randitem33 = 0.001;
	Locations[n].items.randitem33 = "hammock_ropes";

	Locations[n].locators_radius.randitem.randitem34 = 0.001;
	Locations[n].items.randitem34 = "hammock_ropes";

	Locations[n].locators_radius.randitem.randitem35 = 0.001;
	Locations[n].items.randitem35 = "hammock_ropes";

	Locations[n].locators_radius.randitem.randitem36 = 0.001;
	Locations[n].items.randitem36 = "hammock_ropes";

	Locations[n].locators_radius.randitem.randitem37 = 0.001;
	Locations[n].items.randitem37 = "hammock_ropes";

	Locations[n].locators_radius.randitem.randitem38 = 0.001;
	Locations[n].items.randitem38 = "hammock_ropes";

	Locations[n].locators_radius.randitem.randitem39 = 0.001;
	Locations[n].items.randitem39 = "hammock_ropes";

	Locations[n].locators_radius.randitem.randitem40 = 0.001;
	Locations[n].items.randitem40 = "hammock_ropes";

	Locations[n].locators_radius.randitem.randitem41 = 0.001;
	Locations[n].items.randitem41 = "hammock_ropes";

	Locations[n].locators_radius.randitem.randitem42 = 0.001;
	Locations[n].items.randitem42 = "hammock_ropes";

	Locations[n].locators_radius.randitem.randitem43 = 0.001;
	Locations[n].items.randitem43 = "hammock_ropes";

	Locations[n].locators_radius.randitem.randitem44 = 0.001;
	Locations[n].items.randitem44 = "hammock_ropes";

	Locations[n].locators_radius.randitem.randitem45 = 0.001;
	Locations[n].items.randitem45 = "hammock_ropes";

	Locations[n].locators_radius.randitem.randitem46 = 0.001;
	Locations[n].items.randitem46 = "hammock_ropes";
	//......................................................
	//Left side
	Locations[n].locators_radius.randitem.randitem47 = 0.001;
	Locations[n].items.randitem47 = "Lo_jrh_1";

	Locations[n].locators_radius.randitem.randitem48 = 0.001;
	Locations[n].items.randitem48 = "pillow1";

	Locations[n].locators_radius.randitem.randitem49 = 0.001;
	Locations[n].items.randitem49 = "pillow1_u";

	Locations[n].locators_radius.randitem.randitem50 = 0.001;
	Locations[n].items.randitem50 = "Lo_jrh_2";

	Locations[n].locators_radius.randitem.randitem51 = 0.001;
	Locations[n].items.randitem51 = "pillow2";

	Locations[n].locators_radius.randitem.randitem52 = 0.001;
	Locations[n].items.randitem52 = "pillow2_u";

	Locations[n].locators_radius.randitem.randitem53 = 0.001;
	Locations[n].items.randitem53 = "Lo_jrh_3";

	Locations[n].locators_radius.randitem.randitem54 = 0.001;
	Locations[n].items.randitem54 = "pillow3";

	Locations[n].locators_radius.randitem.randitem55 = 0.001;
	Locations[n].items.randitem55 = "pillow3_u";

	Locations[n].locators_radius.randitem.randitem56 = 0.001;
	Locations[n].items.randitem56 = "Lo_jrh_4";

	Locations[n].locators_radius.randitem.randitem57 = 0.001;
	Locations[n].items.randitem57 = "pillow1";

	Locations[n].locators_radius.randitem.randitem58 = 0.001;
	Locations[n].items.randitem58 = "pillow1_u";

	Locations[n].locators_radius.randitem.randitem59 = 0.001;
	Locations[n].items.randitem59 = "Lo_jrh_5";

	Locations[n].locators_radius.randitem.randitem60 = 0.001;
	Locations[n].items.randitem60 = "pillow3";

	Locations[n].locators_radius.randitem.randitem61 = 0.001;
	Locations[n].items.randitem61 = "pillow3_u";

	Locations[n].locators_radius.randitem.randitem62 = 0.001;
	Locations[n].items.randitem62 = "Lo_jrh_1";

	Locations[n].locators_radius.randitem.randitem63 = 0.001;
	Locations[n].items.randitem63 = "pillow2";

	Locations[n].locators_radius.randitem.randitem64 = 0.001;
	Locations[n].items.randitem64 = "pillow2_u";

	Locations[n].locators_radius.randitem.randitem65 = 0.001;
	Locations[n].items.randitem65 = "Lo_jrh_2";

	Locations[n].locators_radius.randitem.randitem66 = 0.001;
	Locations[n].items.randitem66 = "pillow2";

	Locations[n].locators_radius.randitem.randitem67 = 0.001;
	Locations[n].items.randitem67 = "pillow2_u";

	Locations[n].locators_radius.randitem.randitem68 = 0.001;
	Locations[n].items.randitem68 = "Lo_jrh_3";

	Locations[n].locators_radius.randitem.randitem69 = 0.001;
	Locations[n].items.randitem69 = "pillow3";

	Locations[n].locators_radius.randitem.randitem70 = 0.001;
	Locations[n].items.randitem70 = "pillow3_u";

	Locations[n].locators_radius.randitem.randitem71 = 0.001;
	Locations[n].items.randitem71 = "Lo_jrh_4";

	Locations[n].locators_radius.randitem.randitem72 = 0.001;
	Locations[n].items.randitem72 = "pillow1";

	Locations[n].locators_radius.randitem.randitem73 = 0.001;
	Locations[n].items.randitem73 = "pillow1_u";

	Locations[n].locators_radius.randitem.randitem74 = 0.001;
	Locations[n].items.randitem74 = "Lo_jrh_5";

	Locations[n].locators_radius.randitem.randitem75 = 0.001;
	Locations[n].items.randitem75 = "pillow1";

	Locations[n].locators_radius.randitem.randitem76 = 0.001;
	Locations[n].items.randitem76 = "pillow1_u";

	Locations[n].locators_radius.randitem.randitem77 = 0.001;
	Locations[n].items.randitem77 = "Lo_jrh_1";

	Locations[n].locators_radius.randitem.randitem78 = 0.001;
	Locations[n].items.randitem78 = "pillow2";

	Locations[n].locators_radius.randitem.randitem79 = 0.001;
	Locations[n].items.randitem79 = "pillow2_u";

	Locations[n].locators_radius.randitem.randitem80 = 0.001;
	Locations[n].items.randitem80 = "Lo_jrh_2";

	Locations[n].locators_radius.randitem.randitem81 = 0.001;
	Locations[n].items.randitem81 = "pillow3";

	Locations[n].locators_radius.randitem.randitem82 = 0.001;
	Locations[n].items.randitem82 = "pillow3_u";
	//......................................................
	//Right side
	Locations[n].locators_radius.randitem.randitem83 = 0.001;
	Locations[n].items.randitem83 = "Lo_jrh_2";

	Locations[n].locators_radius.randitem.randitem84 = 0.001;
	Locations[n].items.randitem84 = "pillow3";

	Locations[n].locators_radius.randitem.randitem85 = 0.001;
	Locations[n].items.randitem85 = "pillow3_u";

	Locations[n].locators_radius.randitem.randitem86 = 0.001;
	Locations[n].items.randitem86 = "Lo_jrh_3";

	Locations[n].locators_radius.randitem.randitem87 = 0.001;
	Locations[n].items.randitem87 = "pillow2";

	Locations[n].locators_radius.randitem.randitem88 = 0.001;
	Locations[n].items.randitem88 = "pillow2_u";

	Locations[n].locators_radius.randitem.randitem89 = 0.001;
	Locations[n].items.randitem89 = "Lo_jrh_4";

	Locations[n].locators_radius.randitem.randitem90 = 0.001;
	Locations[n].items.randitem90 = "pillow1";

	Locations[n].locators_radius.randitem.randitem91 = 0.001;
	Locations[n].items.randitem91 = "pillow1_u";

	Locations[n].locators_radius.randitem.randitem92 = 0.001;
	Locations[n].items.randitem92 = "Lo_jrh_5";

	Locations[n].locators_radius.randitem.randitem93 = 0.001;
	Locations[n].items.randitem93 = "pillow2";

	Locations[n].locators_radius.randitem.randitem94 = 0.001;
	Locations[n].items.randitem94 = "pillow2_u";

	Locations[n].locators_radius.randitem.randitem95 = 0.001;
	Locations[n].items.randitem95 = "Lo_jrh_1";

	Locations[n].locators_radius.randitem.randitem96 = 0.001;
	Locations[n].items.randitem96 = "pillow2";

	Locations[n].locators_radius.randitem.randitem97 = 0.001;
	Locations[n].items.randitem97 = "pillow2_u";

	Locations[n].locators_radius.randitem.randitem98 = 0.001;
	Locations[n].items.randitem98 = "Lo_jrh_2";

	Locations[n].locators_radius.randitem.randitem99 = 0.001;
	Locations[n].items.randitem99 = "pillow3";

	Locations[n].locators_radius.randitem.randitem100 = 0.001;
	Locations[n].items.randitem100 = "pillow3_u";

	Locations[n].locators_radius.randitem.randitem101 = 0.001;
	Locations[n].items.randitem101 = "Lo_jrh_1";

	Locations[n].locators_radius.randitem.randitem102 = 0.001;
	Locations[n].items.randitem102 = "pillow1";

	Locations[n].locators_radius.randitem.randitem103 = 0.001;
	Locations[n].items.randitem103 = "pillow1_u";

	Locations[n].locators_radius.randitem.randitem104 = 0.001;
	Locations[n].items.randitem104 = "Lo_jrh_2";

	Locations[n].locators_radius.randitem.randitem105 = 0.001;
	Locations[n].items.randitem105 = "pillow2";

	Locations[n].locators_radius.randitem.randitem106 = 0.001;
	Locations[n].items.randitem106 = "pillow2_u";

	Locations[n].locators_radius.randitem.randitem107 = 0.001;
	Locations[n].items.randitem107 = "Lo_jrh_3";

	Locations[n].locators_radius.randitem.randitem108 = 0.001;
	Locations[n].items.randitem108 = "pillow1";

	Locations[n].locators_radius.randitem.randitem109 = 0.001;
	Locations[n].items.randitem109 = "pillow1_u";

	Locations[n].locators_radius.randitem.randitem110 = 0.001;
	Locations[n].items.randitem110 = "Lo_jrh_4";

	Locations[n].locators_radius.randitem.randitem111 = 0.001;
	Locations[n].items.randitem111 = "pillow1";

	Locations[n].locators_radius.randitem.randitem112 = 0.001;
	Locations[n].items.randitem112 = "pillow1_u";

	Locations[n].locators_radius.randitem.randitem113 = 0.001;
	Locations[n].items.randitem113 = "Lo_jrh_5";

	Locations[n].locators_radius.randitem.randitem114 = 0.001;
	Locations[n].items.randitem114 = "pillow3";

	Locations[n].locators_radius.randitem.randitem115 = 0.001;
	Locations[n].items.randitem115 = "pillow3_u";

	Locations[n].locators_radius.randitem.randitem116 = 0.001;
	Locations[n].items.randitem116 = "Lo_jrh_1";

	Locations[n].locators_radius.randitem.randitem117 = 0.001;
	Locations[n].items.randitem117 = "pillow2";

	Locations[n].locators_radius.randitem.randitem118 = 0.001;
	Locations[n].items.randitem118 = "pillow2_u";

	Locations[n].locators_radius.randitem.randitem119 = 0.001;
	Locations[n].items.randitem119 = "Lo_jrh_2";

	Locations[n].locators_radius.randitem.randitem120 = 0.001;
	Locations[n].items.randitem120 = "pillow3";

	Locations[n].locators_radius.randitem.randitem121 = 0.001;
	Locations[n].items.randitem121 = "pillow3_u";

	Locations[n].locators_radius.randitem.randitem122 = 0.001;
	Locations[n].items.randitem122 = "Lo_jrh_3";

	Locations[n].locators_radius.randitem.randitem123 = 0.001;
	Locations[n].items.randitem123 = "pillow1";

	Locations[n].locators_radius.randitem.randitem124 = 0.001;
	Locations[n].items.randitem124 = "pillow1_u";

	Locations[n].locators_radius.randitem.randitem125 = 0.001;
	Locations[n].items.randitem125 = "Lo_jrh_5";

	Locations[n].locators_radius.randitem.randitem126 = 0.001;
	Locations[n].items.randitem126 = "pillow2";

	Locations[n].locators_radius.randitem.randitem127 = 0.001;
	Locations[n].items.randitem127 = "pillow2_u";

	Locations[n].locators_radius.randitem.randitem128 = 0.001;
	Locations[n].items.randitem128 = "Lo_jrh_4";

	Locations[n].locators_radius.randitem.randitem129 = 0.001;
	Locations[n].items.randitem129 = "pillow1";

	Locations[n].locators_radius.randitem.randitem130 = 0.001;
	Locations[n].items.randitem130 = "pillow1_u";

	Locations[n].locators_radius.randitem.randitem131 = 0.001;
	Locations[n].items.randitem131 = "plank2_long";

	Locations[n].locators_radius.randitem.randitem132 = 0.001;
	Locations[n].items.randitem132 = "plank2_long";

	Locations[n].rats = "true";
	Locations[n].island = "Redmond";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "BB_careen_deck2";
	Locations[n].id.label = "Gun deck stern";
	//Info
	Locations[n].filespath.models = "locations\decks\deck2_red";
	Locations[n].image = "wr_gall_deck2_stern.tga";
	//Sound
//	Locations[n].type = "silent_deck";
	Locations[n].type = "silent_sneaking_deck";			//to begin with, changes very soon

	//Models
	//Always
	Locations[n].models.always.locators = "deck2_l_careen";
	Locations[n].models.always.l1 = "deck2";
	//Day
	Locations[n].models.day.charactersPatch = "deck2_p";
	Locations[n].models.day.fonar = "deck2_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deck2_p";
	Locations[n].models.night.fonar = "deck2_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	//to weather deck
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "BB_careen_corvette";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";

	//to deck1
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "BB_careen_deck1";
	Locations[n].reload.l2.emerge = "reload4";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";

	//to deck1
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "BB_careen_deck1";
	Locations[n].reload.l3.emerge = "reload7";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "";
	Locations[n].reload.l3.disable = 1;

	//to capsm
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_careen_capsm";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";

	//to hold slaves
	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "BB_careen_holdS";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "";
	Locations[n].reload.l5.disable = 1;

	//to hold slaves
	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "BB_careen_holdS";
	Locations[n].reload.l6.emerge = "reload3";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "";
	Locations[n].reload.l6.disable = 1;

	Locations[n].locators_radius.goto.psst = 2.0;
	
	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "hatch13R";		//yes because a covered hatch on deck

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "hatch12R";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "hatch12G_U";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "hatch12G_U";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "plank2_long";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "plank2_long";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "plank2_long";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "plank2_long";

	Locations[n].rats = "true";
	Locations[n].island = "Redmond";
	n = n + 1;

//--------------------------------------------------------------------------

//ONE location, ONE locator file, only switch the patch file (by using a box)
	Locations[n].id = "BB_careen_holdP";
	Locations[n].id.label = "Animals hold prow";
	//Info
	Locations[n].filespath.models = "locations\decks\hold";
	Locations[n].filespath.textures = "locations\decks\BlackPearl";
	Locations[n].image = "wr_careen_donkeys.tga";
	//Sound
	Locations[n].type = "galleon_closed";

	//Models
	//Always
	Locations[n].models.always.locators = "hold_l_careenP";
	Locations[n].models.always.l1 = "hold";
	//Day
	Locations[n].models.day.charactersPatch = "hold_p_animals";
	Locations[n].models.day.fonar = "hold_fd";
	//Night
	Locations[n].models.night.charactersPatch = "hold_p_animals";
	Locations[n].models.night.fonar = "hold_fn";

	Locations[n].models.always.donkey1 = "donkey";
	Locations[n].models.always.donkey1.locator.group = "goto";
	Locations[n].models.always.donkey1.locator.name = "stay1";
	Locations[n].models.always.donkey2 = "donkey";
	Locations[n].models.always.donkey2.locator.group = "goto";
	Locations[n].models.always.donkey2.locator.name = "stay2";
	Locations[n].models.always.donkey3 = "donkey";
	Locations[n].models.always.donkey3.locator.group = "goto";
	Locations[n].models.always.donkey3.locator.name = "stay3";
    	Locations[n].models.always.donkey4 = "donkey";
	Locations[n].models.always.donkey4.locator.group = "goto";
	Locations[n].models.always.donkey4.locator.name = "stay4";
	Locations[n].models.always.hay1 = "hay";
	Locations[n].models.always.hay1.locator.group = "goto";
	Locations[n].models.always.hay1.locator.name = "hay1";
	Locations[n].models.always.hay2 = "hay";
	Locations[n].models.always.hay2.locator.group = "goto";
	Locations[n].models.always.hay2.locator.name = "hay2";
	Locations[n].models.always.hay3 = "hay";
	Locations[n].models.always.hay3.locator.group = "goto";
	Locations[n].models.always.hay3.locator.name = "hay3";
	Locations[n].models.always.hay4 = "hay";
	Locations[n].models.always.hay4.locator.group = "goto";
	Locations[n].models.always.hay4.locator.name = "hay4";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "BB_careen_holdS";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";

	//to deck1
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "BB_careen_deck1";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";

	//to deck1
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "BB_careen_deck1";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "";
	Locations[n].reload.l3.disable = 1;
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].locators_radius.goto.stay1 = 0.1;
	Locations[n].locators_radius.goto.stay2 = 0.1;
	Locations[n].locators_radius.goto.stay3 = 0.1;
	Locations[n].locators_radius.goto.stay4 = 0.1;

	Locations[n].locators_radius.goto.stay1_L = 0.6;
	Locations[n].locators_radius.goto.stay1_R = 0.6;
	Locations[n].locators_radius.goto.stay2_L = 0.6;
	Locations[n].locators_radius.goto.stay2_R = 0.6;
	Locations[n].locators_radius.goto.stay3_L = 0.6;
	Locations[n].locators_radius.goto.stay3_R = 0.6;
	Locations[n].locators_radius.goto.stay4_L = 0.6;
	Locations[n].locators_radius.goto.stay4_R = 0.6;

	Locations[n].locators_radius.quest.stay1_L = 0.2;
	Locations[n].locators_radius.quest.stay1_R = 0.2;
	Locations[n].locators_radius.quest.stay2_L = 0.2;
	Locations[n].locators_radius.quest.stay2_R = 0.2;
	Locations[n].locators_radius.quest.stay3_L = 0.2;
	Locations[n].locators_radius.quest.stay3_R = 0.2;
	Locations[n].locators_radius.quest.stay4_L = 0.2;
	Locations[n].locators_radius.quest.stay4_R = 0.2;

	Locations[n].locators_radius.goto.kick1_fall = 0.2;
	Locations[n].locators_radius.goto.kick2_fall = 0.2;
	Locations[n].locators_radius.goto.kick3_fall = 0.2;
	Locations[n].locators_radius.goto.kick4_fall = 0.2;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "stool";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "bars_down";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "barrel_big";	

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "bars_down";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "bars_down";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "hatch12R";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "hatch12R";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "hatch12R";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "hatch12R";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "door_Tortuga";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "door_Tortuga";

	Locations[n].items.randitem12 = "pitchfork";

	LAi_LocationFightDisable(&Locations[n], true);
//	Locations[n].rats = "true";			//fewer rats added via animals.c
	Locations[n].island = "Redmond";
	n = n + 1;
//pär här
//--------------------------------------------------------------------------
//fake location - never visited -just for the label

	Locations[n].id = "BB_careen_holdPP";
	Locations[n].id.label = "Convicts hold prow";
	//Info
	Locations[n].filespath.models = "locations\decks\hold";
	//Sound
	Locations[n].type = "galleon_closed";

	//Models
	//Always
	Locations[n].models.always.locators = "hold_l";
	Locations[n].models.always.l1 = "hold";
	//Day
	Locations[n].models.day.charactersPatch = "hold_p";
	Locations[n].models.day.fonar = "hold_fd";
	//Night
	Locations[n].models.night.charactersPatch = "hold_p";
	Locations[n].models.night.fonar = "hold_fn";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	Locations[n].island = "Redmond";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "BB_careen_holdS";
	Locations[n].id.label = "Slaves hold stern";
	//Info
	Locations[n].filespath.models = "locations\decks\hold_wreck";
	Locations[n].filespath.textures = "locations\decks\BlackPearl";
	Locations[n].image = "wr_careen_slaves.tga";
	//Sound
	Locations[n].type = "galleon_closed";

	//Models
	//Always
	Locations[n].models.always.locators = "hold_l_careenS"; 
	Locations[n].models.always.l1 = "hold";
	//Day
	Locations[n].models.day.charactersPatch = "hold_p";
	Locations[n].models.day.fonar = "hold_fd";
	//Night
	Locations[n].models.night.charactersPatch = "hold_p";
	Locations[n].models.night.fonar = "hold_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "BB_careen_holdP";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	Locations[n].locators_radius.reload.reload1_back = 0.8;

	//to deck2
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "BB_careen_deck2";
	Locations[n].reload.l2.emerge = "reload5";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].reload.l2.disable = 1;

	//to deck2
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "BB_careen_deck2";
	Locations[n].reload.l3.emerge = "reload6";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "";
	Locations[n].reload.l3.disable = 1;

	Locations[n].locators_radius.goto.second = 3.3;
	Locations[n].locators_radius.goto.third = 3.3;
	Locations[n].locators_radius.goto.king_last = 1.7;
	Locations[n].locators_radius.quest.slave16_P = 1.8;
	Locations[n].locators_radius.goto.swim_dialog = 2.5;

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "barrel_big";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "hatch12G";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "hatch12G";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "hatch12G";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "hatch12G";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "door_N13";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "box";	

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "barrel_big";

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "chain_horizontal";

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
	Locations[n].items.randitem14 = "chain_horizontal";

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	Locations[n].items.randitem15 = "chain_horizontal";

	Locations[n].locators_radius.randitem.randitem16 = 0.001;
	Locations[n].items.randitem16 = "chain_horizontal";

	Locations[n].locators_radius.randitem.randitem17 = 0.001;
	Locations[n].items.randitem17 = "chain_horizontal";

	Locations[n].locators_radius.randitem.randitem18 = 0.001;
	Locations[n].items.randitem18 = "chain_horizontal";

	Locations[n].locators_radius.randitem.randitem19 = 0.001;
	Locations[n].items.randitem19 = "chain_horizontal";

	Locations[n].locators_radius.randitem.randitem20 = 0.001;
	Locations[n].items.randitem20 = "chain_horizontal";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].rats = "true";
	Locations[n].island = "Redmond";
	n = n + 1;

//--------------------------------------------------------------------------

	Locations[n].id = "Bath_Tavern";
	locations[n].id.label = "Tavern.";
	Locations[n].filespath.models = "locations\Inside\Tavern_1";
	Locations[n].filespath.textures = "locations\inside\Tavern_1\spanish";	
	Locations[n].image = "Teach_tavern.tga";

	//Sound
//	locations[n].type = "tavern";
	locations[n].type = "Blackbeard_party";
	
	//Models
	//Always
	Locations[n].models.always.locators = "Tavern_1_l_KR";
	Locations[n].models.always.l1 = "Tavern_1";
	//Day
	Locations[n].models.day.charactersPatch = "Tavern_1_p_JRH";
	//Night
	Locations[n].models.night.charactersPatch = "Tavern_1_p_JRH";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\mulf2_";	

	Locations[n].locators_radius.box.box1 = 0.001;
/*
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Nueva_Suecia_hidden_town";
	Locations[n].reload.l1.emerge = "reload200";			//was exit_house
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "NS_hidden_town_priest";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Room in #stown_name# tavern.";
	LAi_LocationFightDisable(&Locations[n], true);
*/
	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "empty_bottle";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "book49";
	
	Locations[n].island = "KhaelRoa";
	n = n + 1;



	//--------------------------------------------------------------------------

	Build_at("Kristiania_port", "workshop", "", 8.0, 3.7, 33.2, 0.25, "building");
	Build_at("Kristiania_port", "ladder", "", -1.4, 0.0, 61.4, -1.5, "building");

	Build_at("BB_graveyard", "church", "", 26.5, 2.9, -38.5, -2.2, "building");
	Build_at("BB_Eden_estate", "Mansion", "", -224.0, 38.0, -16.0, 1.4, "building");
	Build_at("BB_Eden_estate", "Mansion", "", -227.5, 38.0, -10.0, 1.4, "building");

	Build_at("BB_Eden_estate", "Mansion", "", -225.5, 34.5, -9.0, 1.4, "building");
	Build_at("BB_Eden_estate", "Mansion", "", -220.5, 34.5, -22.0, 1.4, "building");

	Build_at("Tortuga_gunsmith_workshop", "Field_Cannon_1", "", -12.7, 5.9, 40.3, -1.24, "building");
	Build_at("bb_Eden_maze", "jungle", "", 0.0, 2.7, 0.0, -1.24, "wild_jungles");
	Build_at("bb_Eden_maze", "jungle", "", 30.0, 2.7, 0.0, -3.0, "wild_jungles");
	Build_at("bb_Eden_maze", "jungle", "", 0.0, 2.7, 30.0, -2.0, "wild_jungles");
	Build_at("bb_Eden_maze", "jungle", "", -30.0, 2.7, 0.0, -1.0, "wild_jungles");
	Build_at("bb_Eden_maze", "jungle", "", 0.0, 2.7, -30.0, -1.0, "wild_jungles");

	Build_at("bb_Eden_maze", "jungle", "", 70.0, 2.7, 70.0, -1.24, "wild_jungles");
	Build_at("bb_Eden_maze", "jungle", "", -70.0, 2.7, 70.0, -1.24, "wild_jungles");
	Build_at("bb_Eden_maze", "jungle", "", -70.0, 2.7, -70.0, -1.24, "wild_jungles");
	Build_at("bb_Eden_maze", "jungle", "", 70.0, 2.7, -70.0, -1.24, "wild_jungles");

	Build_at("bb_Eden_maze", "jungle", "", 100.0, 2.7, 100.0, 1.0, "wild_jungles");
	Build_at("bb_Eden_maze", "jungle", "", -100.0, 2.7, 100.0, 2.0, "wild_jungles");
	Build_at("bb_Eden_maze", "jungle", "", -100.0, 2.7, -100.0, 1.0, "wild_jungles");
	Build_at("bb_Eden_maze", "jungle", "", 100.0, 2.7, -100.0, 2.0, "wild_jungles");

	Build_at("bb_burning_cave", "church", "", 85.27, 7.55, -27.62, 3.93, "building");
}
