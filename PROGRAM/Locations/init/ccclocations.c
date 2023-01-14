void LocationInitCCCLocations(ref n)
{

	// ccc Oxbay suburb-------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\pirateresidence";	

	Locations[n].id = "Oxbayhouse1";
	locations[n].id.label = "House";
	Locations[n].image = "Inside_PirateResidence";
	//Town sack
	Locations[n].townsack = "Oxbay";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Oxbay";
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
	Locations[n].reload.l1.go = "Oxbay_suburb";
	Locations[n].reload.l1.emerge = "locator19";
	Locations[n].reload.l1.autoreload = "0";


	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// ccc Oxbay suburb------------------------------------------
	
	Locations[n].filespath.models = "locations\Inside\Pirate_House";	

	Locations[n].id = "Oxbayhouse2";
	locations[n].id.label = "House";
	Locations[n].image = "Inside_Pirate_House";
	//Town sack
	Locations[n].townsack = "Oxbay";
	locations[n].fastreload = "Oxbay";
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
	Locations[n].models.back = "back\qcpirh_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_suburb";
	Locations[n].reload.l1.emerge = "locator20";
	Locations[n].reload.l1.autoreload = "0";


	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1; 



	// ccc oxbay suburb-------------------------------------------------

	Locations[n].id = "Oxbayhouse3";		//change, new id
	Locations[n].id.label = "House";
	Locations[n].image = "Inside_MediumHouse";

	//Town sack
	Locations[n].townsack = "Oxbay";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Oxbay";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\MediumHouse";
	Locations[n].models.always.locators = "mh_l";
	Locations[n].models.always.house = "mh";
	Locations[n].models.always.window = "mh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "mh_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\oxmh_";

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_suburb";
	Locations[n].reload.l1.emerge = "locator22";		// change, exit back to new doorlocator
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// ccc new mansion near yard-------------------------------------------------
	Locations[n].id = "Oxbay_mansion_hall";	//new ID
	locations[n].id.label = "Mansion";		//change
	Locations[n].filespath.models = "locations\inside\Residence_BackHall";
	Locations[n].image = "Inside_Residence_BackHall";	//use any image you like

	//Town sack
	Locations[n].townsack = "Oxbay";		//change

	//Sound
	locations[n].type = "house";		//change to enable residents and fights
	locations[n].fastreload = "Oxbay";		//change
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
	Locations[n].models.back = "back\redrsb_";	//the view out of windows, leave original, no Oxbay model fits

	//Reload map
	Locations[n].reload.l1.name = "reload3";		//building kit
	Locations[n].reload.l1.go = "Oxbay_suburb";		//building kit
	Locations[n].reload.l1.emerge = "home_01";		//building kit
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Town.";		//change, just eyecandy
	
	Locations[n].reload.l2.name = "reload2";		//building kit
	Locations[n].reload.l2.go = "Oxbay_mansion_study";	//new door
	Locations[n].reload.l2.emerge = "reload1";		//new door
	Locations[n].reload.l2.autoreload = "0";		//new door
	Locations[n].reload.l2.label = "Study.";		//new door

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// ccc study for Oxbay mansion-------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Residence3";

	Locations[n].id = "Oxbay_mansion_study";		//change
	locations[n].id.label = "Study";			//change
	Locations[n].image = "Inside_Residence3";

	//Town sack
	Locations[n].townsack = "Oxbay";			//change

	//Sound
	locations[n].type = "house";			//change
	locations[n].fastreload = "Oxbay";			//change
	//Models
	//Always
	Locations[n].models.always.locators = "Res03_l";
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
	Locations[n].models.back = "back\mures3_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_mansion_hall";		//change
	Locations[n].reload.l1.emerge = "reload2";			//building kit
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Hall";			//change
	// LAi_LocationFightDisable(&Locations[n], true);		outcomment

	Locations[n].reload.l2.name = "reload2";		//new door to bedroom
	Locations[n].reload.l2.go = "Oxbay_mansion_bedroom";	//new door 
	Locations[n].reload.l2.emerge = "reload1";		//new door 
	Locations[n].reload.l2.autoreload = "0";		//new door 
	Locations[n].reload.l2.label = "Study.";		//new door

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	//  ccc bedroom for Oxbay mansion-------------------------------------------------
	Locations[n].id = "Oxbay_mansion_bedroom";	//change
	locations[n].id.label = "Bedroom";			//change
	Locations[n].filespath.models = "locations\inside\ResBedRoom";
	Locations[n].image = "Inside_ResBedRoom";
	//Sound
	locations[n].type = "house";			//change
	locations[n].fastreload = "Oxbay";			//add to enable quickteleport
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
	Locations[n].reload.l1.go = "Oxbay_mansion_study";	//change
	Locations[n].reload.l1.emerge = "reload2";		//change
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Study.";		//change, just eyecandy

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;



	// ccc new suburb cloned from Falaise_de_fleur_location_02 ---------------
	Locations[n].id = "Oxbay_suburb";		//change
	locations[n].id.label = "Town";		//change
	locations[n].worldmap = "Oxbay";		//change
	Locations[n].image = "Town_FalaiseDeFleur_Town_01_England";	//change

	//Town sack
	Locations[n].townsack = "Oxbay";		//change

	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].fastreload = "Oxbay";		//change
	//Models
	//Always
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\town_01";
	Locations[n].filespath.textures = "locations\ENGLAND";
	Locations[n].models.always.city = "OxTown_02"; // Thomas the Terror
	Locations[n].models.always.locators = "FF01_l";
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
	//Reload map -----------
	//Do NOT change "Falaise_de_fleur" in the reload..names cause these belong to the model !!!! 
	Locations[n].reload.l1.name = "Falaise_de_fleur_location_02_01"; //do NOT change
	Locations[n].reload.l1.go = "Oxbay_town_exit";	//change
	Locations[n].reload.l1.emerge = "reload3";		//change
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "Falaise_de_fleur_location_02_03"; //do NOT change
	Locations[n].reload.l2.go = "Oxbay_town"; //change
	Locations[n].reload.l2.emerge = "reload12"; //change
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l3.name = "Falaise_de_fleur_location_02_perechod"; //do NOT change
	Locations[n].reload.l3.go = "Oxbay_fakefort1"; //change
	Locations[n].reload.l3.emerge = "reloadc3"; //change
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "MILITARY AREA. NO TRESPASSING!";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l3.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l4.name = "locator19";
	Locations[n].reload.l4.go = "Oxbayhouse1";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";

	Locations[n].reload.l5.name = "locator20";
	Locations[n].reload.l5.go = "Oxbayhouse2";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";

	Locations[n].reload.l6.name = "locator22";
	Locations[n].reload.l6.go = "Oxbayhouse3";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";

	Locations[n].reload.l15.name = "home_01";	// ccc building kit 		
	Locations[n].reload.l15.go = "Oxbay_mansion_hall";	// ccc building kit 
	Locations[n].reload.l15.emerge = "reload3";	// ccc building kit 
	Locations[n].reload.l15.autoreload = "0";	// ccc building kit 
	Locations[n].reload.l15.label = "Mansion.";	// ccc building kit 
	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// ccc fake forts--------------------------------------

	//ID
	Locations[n].id = "Oxbay_fakefort1";		//new ID
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";	//A warning sign at the gate :)
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_1";
	Locations[n].image = "Fort_Inside_Fort_1";

	//Town sack
	Locations[n].townsack = "Oxbay";		//change
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
	Locations[n].reload.l1.go = "Oxbay_suburb";
	Locations[n].reload.l1.emerge = "Falaise_de_fleur_location_02_perechod";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reloadC4";
	Locations[n].reload.l2.go = "Oxbay_fakefort2";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l3.name = "reloadc5";
	Locations[n].reload.l3.go = "Oxbay_armory";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].reload.l4.name = "reloadc1";
	Locations[n].reload.l4.go = "Oxbay_fakefort3";
	Locations[n].reload.l4.emerge = "reloadc1";
	Locations[n].reload.l4.autoreload = "0";

	Locations[n].island = "Oxbay"; // NK 04-08-29	
	n = n + 1;

	// ccc oxbay fake fort 2----------------------------------

	//ID
	Locations[n].id = "Oxbay_fakefort2";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";

	//Town sack
	Locations[n].townsack = "Oxbay";


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
	Locations[n].reload.l1.go = "Oxbay_fakefort1";
	Locations[n].reload.l1.emerge = "reloadc4";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reloadc1";
	Locations[n].reload.l2.go = "Oxbay_fakefort3";
	Locations[n].reload.l2.emerge = "reloadc2";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// ccc oxbay fake fort 3----------------------------------

	//ID
	Locations[n].id = "Oxbay_fakefort3";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";


	//Town sack
	Locations[n].townsack = "oxbay";

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
	Locations[n].reload.l1.go = "Oxbay_fakefort1";
	Locations[n].reload.l1.emerge = "reloadc1";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reloadc2";
	Locations[n].reload.l2.go = "Oxbay_fakefort2";
	Locations[n].reload.l2.emerge = "reloadc1";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l3.name = "reloadc4";
	Locations[n].reload.l3.go = "Oxbay_armory";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;


	// ccc oxbay armory-------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\LargeStore";
	Locations[n].id = "Oxbay_armory";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";
	Locations[n].image = "Fort_Inside_Fort_2";

	//Town sack
	Locations[n].townsack = "Oxbay";
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
	Locations[n].reload.l1.go = "Oxbay_fakefort1";
	Locations[n].reload.l1.emerge = "reloadc5";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Oxbay_fakefort3";
	Locations[n].reload.l3.emerge = "reloadC4";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;


	// ccc greenford fake forts--------------------------------------

	//ID
	Locations[n].id = "greenford_fakefort1";		//new ID
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";	//A warning sign at the gate :)
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_1";
	Locations[n].image = "Fort_Inside_Fort_1";

	//Town sack
	Locations[n].townsack = "greenford";		//change
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
// KK -->
	Locations[n].reload.l1.name = "reloadc1";
	Locations[n].reload.l1.go = "greenford_suburb";
	Locations[n].reload.l1.emerge = "reload_3_1";
	Locations[n].reload.l1.autoreload = "0";
// <-- KK

	Locations[n].reload.l2.name = "reloadC4";
	Locations[n].reload.l2.go = "greenford_armory";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l3.name = "reloadc5";
	Locations[n].reload.l3.go = "greenford_fakefort2";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].island = "Oxbay"; // NK 04-08-29	
	n = n + 1;

	// ccc greenford fake fort 2----------------------------------

	//ID
	Locations[n].id = "greenford_fakefort2";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";

	//Town sack
	Locations[n].townsack = "greenford";


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
	Locations[n].reload.l1.go = "greenford_fakefort1";
	Locations[n].reload.l1.emerge = "reloadc5";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reloadc1";
	Locations[n].reload.l2.go = "greenford_fakefort3";
	Locations[n].reload.l2.emerge = "reloadc1";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// ccc greenford fake fort 3----------------------------------

	//ID
	Locations[n].id = "greenford_fakefort3";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";


	//Town sack
	Locations[n].townsack = "greenford";

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
	Locations[n].reload.l1.go = "greenford_fakefort2";
	Locations[n].reload.l1.emerge = "reloadc1";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reloadc2";
	Locations[n].reload.l2.go = "greenford_fakefort1";
	Locations[n].reload.l2.emerge = "reloadc2";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l3.name = "reloadc4";
	Locations[n].reload.l3.go = "greenford_suburb";
	Locations[n].reload.l3.emerge = "door_11";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].reload.l4.name = "reload1";
	Locations[n].reload.l4.go = "greenford_armory";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "0";

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;


	// ccc greenford armory-------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\LargeStore";
	Locations[n].id = "greenford_armory";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";
	Locations[n].image = "Fort_Inside_Fort_2";

	//Town sack
	Locations[n].townsack = "greenford";
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
	Locations[n].reload.l1.go = "greenford_fakefort1";
	Locations[n].reload.l1.emerge = "reloadc4";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "greenford_fakefort3";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;


	// ccc fake fort end



	//**********************************************************************************


// ccc new greenford locations start ---------------------------------------------------------------------------------------


//building kit start
	// ccc new mansion-------------------------------------------------
	Locations[n].id = "greenford_mansion_hall";	//new ID
	locations[n].id.label = "Mansion";		//change
	Locations[n].filespath.models = "locations\inside\Residence_BackHall";
	Locations[n].image = "Inside_Residence_BackHall";

	//Town sack
	Locations[n].townsack = "greenford";		//change

	//Sound
	locations[n].type = "house";		//change to enable residents and fights
	locations[n].fastreload = "greenford";		//change
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
	Locations[n].models.back = "back\redrsb_";	//the view out of windows, leave original, no Oxbay model fits

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "greenford_suburb";
	Locations[n].reload.l1.emerge = "door_2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Town.";	
	
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "greenford_mansion_study";	//new door
	Locations[n].reload.l2.emerge = "reload1";		//new door
	Locations[n].reload.l2.autoreload = "0";		//new door
	Locations[n].reload.l2.label = "Study.";		//new door

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// ccc study for greenford mansion-------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Residence3";

	Locations[n].id = "greenford_mansion_study";		//change
	locations[n].id.label = "Study";			//change
	Locations[n].image = "Inside_Residence3";

	//Town sack
	Locations[n].townsack = "greenford";			//change

	//Sound
	locations[n].type = "house";			//change
	locations[n].fastreload = "greenford";			//change
	//Models
	//Always
	Locations[n].models.always.locators = "Res03_l";
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
	Locations[n].models.back = "back\mures3_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "greenford_mansion_hall";		//change
	Locations[n].reload.l1.emerge = "reload2";			//building kit
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Hall";			//change
	// LAi_LocationFightDisable(&Locations[n], true);		outcomment

	Locations[n].reload.l2.name = "reload2";		//new door to bedroom
	Locations[n].reload.l2.go = "greenford_mansion_bedroom";	//new door 
	Locations[n].reload.l2.emerge = "reload1";		//new door 
	Locations[n].reload.l2.autoreload = "0";		//new door 
	Locations[n].reload.l2.label = "Study.";		//new door

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	//  ccc bedroom for greenford mansion-------------------------------------------------
	Locations[n].id = "greenford_mansion_bedroom";	//change
	locations[n].id.label = "Bedroom";			//change
	Locations[n].filespath.models = "locations\inside\ResBedRoom";
	Locations[n].image = "Inside_ResBedRoom";
	//Sound
	locations[n].type = "house";			//change
	locations[n].fastreload = "greenford";			//add to enable quickteleport
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
	Locations[n].reload.l1.go = "greenford_mansion_study";	//change
	Locations[n].reload.l1.emerge = "reload2";		//change
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Study.";		//change, just eyecandy

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;
	// building kit end

	// -------------------------------------------------
	Locations[n].id = "Greenford_suburb";
	locations[n].id.label = "Town";
	locations[n].worldmap = "Greenford";
	Locations[n].filespath.models = "locations\Town_Redmond\Town_03";
	Locations[n].filespath.textures = "locations\ENGLAND";
	Locations[n].image = "Town_Redmond_Town_03_England";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "Greenford";
	LAi_LocationFantomsGen(&locations[n], true);	
	//Models
	//Always
	Locations[n].models.always.a = "GrTown_02"; // Thomas the Terror
	Locations[n].models.always.locators = "Red03_l";
    Locations[n].models.always.grassPatch = "Red03_g";

    //River
	Locations[n].models.always.dno = "Red03_rb01";
	Locations[n].models.always.dno.level = 95;
	Locations[n].models.always.dno.uvslide.u1 = -0.12;
	Locations[n].models.always.dno.uvslide.v1 = -0.03;
	Locations[n].models.always.dno.tech = "LocationRiverFloor";
	Locations[n].models.always.mirrow = "Red03_re01";
	Locations[n].models.always.mirrow.level = 96;
	Locations[n].models.always.dnoBlend = "Red03_rb01";
	Locations[n].models.always.dnoBlend.level = 97;
	Locations[n].models.always.dnoBlend.uvslide.u1 = -0.1;
	Locations[n].models.always.dnoBlend.uvslide.v1 = 0.04;
	Locations[n].models.always.dnoBlend.tech = "LocationRiverFloorBlend";
	Locations[n].models.always.river = "Red03_rt01";
	Locations[n].models.always.river.level = 98;
	Locations[n].models.always.river.uvslide.v0 = -0.1;
	Locations[n].models.always.river.uvslide.u1 = 0.15;
	Locations[n].models.always.river.tech = "LocationRiver";

	//Day
	Locations[n].models.day.charactersPatch = "Red03_p";
	Locations[n].models.day.fonar = "Red03_fd";
	//Night
	Locations[n].models.night.charactersPatch = "Red03_p";
	Locations[n].models.night.fonar = "Red03_fn";

	Locations[n].locators_radius.camdetector.locator11 = 5.0;

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map

	Locations[n].reload.l1.name = "reload_3_2";
	Locations[n].reload.l1.go = "Greenford_town_exit";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Jungle";
	Locations[n].locators_radius.reload.reload_3_2 = 2.0;

	Locations[n].reload.l3.name = "reload_3_3_back";	// to center
	Locations[n].reload.l3.go = "Greenford_town";
	Locations[n].reload.l3.emerge = "reload19";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Towncenter.";

	Locations[n].reload.l5.name = "reload_3_1_back";
	Locations[n].reload.l5.go = "Greenford_fakefort1"; // KK
	Locations[n].reload.l5.emerge = "reloadc1"; // KK
	Locations[n].reload.l5.autoreload = "0";
	//Locations[n].locators_radius.reload.reload_3_1_back = 2.0;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l5.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l6.name = "Door_12";
	Locations[n].reload.l6.go =  "Greenford_suburbhouse14";
	Locations[n].reload.l6.emerge = "Reload1";
	Locations[n].reload.l6.autoreload = "0";

	Locations[n].reload.l16.name = "Door_13";
	Locations[n].reload.l16.go =  "Greenford_suburbhouse14";
	Locations[n].reload.l16.emerge = "Reload2";
	Locations[n].reload.l16.autoreload = "0";

	Locations[n].reload.l4.name = "door_6";	// church
	Locations[n].reload.l4.go = "Greenford_M_church";
	Locations[n].reload.l4.emerge = "Reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Danger! Abbey out of repair!";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l4.goto_disable = 1;	//JRH

	Locations[n].reload.l41.name = "door_5";	// church
	Locations[n].reload.l41.go = "Greenford_M_undercroft";
	Locations[n].reload.l41.emerge = "Reload1";
	Locations[n].reload.l41.autoreload = "0";
	Locations[n].reload.l41.label = "Danger! Abbey out of repair!";

	Locations[n].reload.l7.name = "door_11";
	Locations[n].reload.l7.go = "greenford_fakefort3";
	Locations[n].reload.l7.emerge = "reloadc4";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "MILITARY AREA. NO TRESPASSING!";

	Locations[n].reload.l8.name = "door_1";
	Locations[n].reload.l8.go =  "greenford_warehouse";
	Locations[n].reload.l8.emerge = "reload1";
	Locations[n].reload.l8.autoreload = "0";

	// building kit
    Locations[n].reload.l13.name = "door_14";	
	Locations[n].reload.l13.go = "greenford_warehouse";
	Locations[n].reload.l13.emerge = "reload2";
	Locations[n].reload.l13.autoreload = "0";

    Locations[n].reload.l14.name = "door_2";	
	Locations[n].reload.l14.go = "greenford_mansion_hall";
	Locations[n].reload.l14.emerge = "reload1";
	Locations[n].reload.l14.autoreload = "0";
	// building kit end

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------  

	// ccc warehouse -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\shipyard";

	Locations[n].id = "greenford_warehouse";
	locations[n].id.label = "Warehouse";
	Locations[n].image = "Inside_Shipyard_Warehouse";	//change, just to have another loading screen than shipyard

	//Town sack
	Locations[n].townsack = "Greenford";	// mar 06

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Greenford";	// mar 06
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
	Locations[n].reload.l1.name = "reload1";	
	Locations[n].reload.l1.go = "Greenford_suburb";	
	Locations[n].reload.l1.emerge = "door_1";	
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reload2";	
	Locations[n].reload.l2.go = "Greenford_suburb";	
	Locations[n].reload.l2.emerge = "door_14";		// building kit	
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;


// Greenford suburb near small gate-------------------------------------------------
	Locations[n].id = "Greenford_suburbhouse14";
	locations[n].id.label = "House";
	Locations[n].image = "Inside_Residence2";
	Locations[n].filespath.models = "locations\inside\Residence2";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Greenford";
	//Models
	//Always
	Locations[n].models.always.city = "Res02";
	Locations[n].models.always.locators = "Res02_l_ccc";
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
	Locations[n].reload.l1.go = "Greenford_suburb";
	Locations[n].reload.l1.emerge = "Door_12";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Town";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Greenford_suburb";
	Locations[n].reload.l2.emerge = "Door_13";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Town";

	Locations[n].items.randitem1 = "pistol6";

	n = n + 1;


	// "Greenford_M_church" -------------------------------------------------
	Locations[n].id = "Greenford_M_church";
	locations[n].id.label = "Abbey of the Maltese order";
	Locations[n].image = "Inside_Church_3";
	Locations[n].filespath.models = "locations\inside\Church_3";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "dungeon";	// ccc nov05 "church";
	locations[n].fastreload = "Greenford";
	locations[n].abbey = true; // KK
	//Models
	//Always
	Locations[n].models.always.city = "Church3";
	Locations[n].models.always.locators = "Church3_l_maltese";
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
	Locations[n].reload.l1.go = "Greenford_suburb";
	Locations[n].reload.l1.emerge = "Door_6";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reload2";	// trapdoor to crypt
	Locations[n].reload.l2.go = "Greenford_M_crypt"; // KK
	Locations[n].reload.l2.emerge = "reload1";	// ccc Nov05
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload2 = 0.7;	//JRH, to match the visible trapdoor

	// JRH -->
	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "hatch11";
	// JRH <--

	LAi_LocationFightDisable(&Locations[n], false);
	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	
	// -------------------------------------------------
	Locations[n].id = "Greenford_M_crypt"; // KK
	locations[n].id.label = "Abbey of the Maltese order";
	Locations[n].filespath.models = "locations\Incas Temple\Labirint";
	//Sound
	Locations[n].image = "Incas_Temple_Labirint_Crypt";
	locations[n].type = "dungeon";
	locations[n].abbey = true; // KK

	//Models
	//Always
	Locations[n].models.always.locators = "lab2_l_ccc";
	Locations[n].models.always.l1 = "lab2";
	Locations[n].models.always.l2 = "hatch11D";		//JRH visible trapdoor from below
	//Day
	Locations[n].models.day.charactersPatch = "lab2_p";
	//Night
	Locations[n].models.night.charactersPatch = "lab2_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].lockWeather = "Alcove";
	
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 0, 24);

	//Reload map

	Locations[n].reload.l2.name = "reload3";
	Locations[n].reload.l2.go = "dungeon 1";
	Locations[n].reload.l2.emerge = "reloadc3";
	Locations[n].reload.l2.autoreload = "1";

	Locations[n].reload.l3.name = "reload12";	// circle to reload25
	Locations[n].reload.l3.go = "Greenford_M_crypt"; // KK
	Locations[n].reload.l3.emerge = "Reload25";
	Locations[n].reload.l3.autoreload = "1";

	Locations[n].reload.l8.name = "reload25";	// circle to reload12
	Locations[n].reload.l8.go = "Greenford_M_crypt"; // KK
	Locations[n].reload.l8.emerge = "reload12";
	Locations[n].reload.l8.autoreload = "1";

	Locations[n].reload.l9.name = "reload14";
	Locations[n].reload.l9.go = "Greenford_M_undercroft";
	Locations[n].reload.l9.emerge = "reload3";
	Locations[n].reload.l9.autoreload = "1";

	Locations[n].reload.l10.name = "reload16";
	Locations[n].reload.l10.go = "oxbay_cave";
	Locations[n].reload.l10.emerge = "monster30";
	Locations[n].reload.l10.autoreload = "1";

	// PB -->
	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "body";
	Locations[n].items.randitem2 = "LongRifle_C";
	Locations[n].items.randitem3 = "book_exorcist";
	Locations[n].items.randitem4 = "jewelry9";
	// PB <--

	Locations[n].island = "Oxbay"; // NK 04-08-29  
    n = n + 1;

//___________________________________________________________________

	Locations[n].id = "Greenford_M_undercroft";
	locations[n].id.label = "Abbey of the Maltese order";
	Locations[n].filespath.models = "locations\inside\Dungeon_2";
	Locations[n].image = "Incas_Temple_Labirint_Crypt";

	//Town sack
	Locations[n].townsack = "Greenford";
	locations[n].abbey = true; // KK

	//Sound
	locations[n].type = "dungeon";
	//Models
	//Always
	Locations[n].models.always.locators = "d02_l_ccc";
	Locations[n].models.always.dungeon = "d02";
	Locations[n].models.always.fonar = "d02_fn";
	//Day
	Locations[n].models.day.charactersPatch = "d02_p";
//	Locations[n].models.day.fonar = "d02_fd";
	//Night
	Locations[n].models.night.charactersPatch = "d02_p";
//	Locations[n].models.night.env = "d02_fn";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].monsters = 1;
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_suburb";
	Locations[n].reload.l1.emerge = "door_5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Town";

	Locations[n].reload.l2.name = "reload3";
	Locations[n].reload.l2.go = "Greenford_M_crypt"; // KK
	Locations[n].reload.l2.emerge = "reload14";
	Locations[n].reload.l2.autoreload = "1";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "dungeon 1";
	Locations[n].reload.l3.emerge = "reloadc4";
	Locations[n].reload.l3.autoreload = "0";


	LAi_LocationFantomsGen(&locations[n], true);
	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

// ccc new greenford locations end ---------------------------------------------------------------------------------------

// KK -->
	//ID
	Locations[n].id = "Fort";
	locations[n].id.label = "Fort inside";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_1";
	Locations[n].image = "Fort_Inside_Fort_1";
	//Sound
	locations[n].type = "military";
	//Models
	//Always
	Locations[n].models.always.locators = "fort1_l";
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
	Locations[n].boarding = "fort";

	Locations[n].island = "";
	Locations[n].townsack = "";
	n = n + 1;
// <-- KK
}
