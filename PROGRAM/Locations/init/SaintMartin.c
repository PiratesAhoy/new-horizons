void LocationInitSaintMartin(ref n)
{
// ------------- SaintMartin ------------------------------------------------------------


	// Marigot fake forts--------------------------------------

	//ID
	Locations[n].id = "Marigot_fakefort1";		//new ID
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";	//A warning sign at the gate :)
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_1";
	Locations[n].image = "Fort_Inside_Fort_1.tga";

	//Town sack
	Locations[n].townsack = "Marigot";
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
	Locations[n].reload.l1.go = "Marigot_town";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reloadC4";
	Locations[n].reload.l2.go = "Marigot_fakefort2";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l3.name = "reloadc5";
	Locations[n].reload.l3.go = "Marigot_armory";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].reload.l4.name = "reloadc1";
	Locations[n].reload.l4.go = "Marigot_fakefort3";
	Locations[n].reload.l4.emerge = "reloadc1";
	Locations[n].reload.l4.autoreload = "0";

	Locations[n].island = "SaintMartin";	
	n = n + 1;

	// Marigot fake fort 2----------------------------------

	//ID
	Locations[n].id = "Marigot_fakefort2";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";

	//Town sack
	Locations[n].townsack = "Marigot";


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
	Locations[n].reload.l1.go = "Marigot_fakefort1";
	Locations[n].reload.l1.emerge = "reloadc4";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reloadc1";
	Locations[n].reload.l2.go = "Marigot_fakefort3";
	Locations[n].reload.l2.emerge = "reloadc2";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].island = "SaintMartin";
	n = n + 1;

	// Marigot fake fort 3----------------------------------

	//ID
	Locations[n].id = "Marigot_fakefort3";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";


	//Town sack
	Locations[n].townsack = "Marigot";

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
	Locations[n].reload.l1.go = "Marigot_fakefort1";
	Locations[n].reload.l1.emerge = "reloadc1";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reloadc2";
	Locations[n].reload.l2.go = "Marigot_fakefort2";
	Locations[n].reload.l2.emerge = "reloadc1";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l3.name = "reloadc4";
	Locations[n].reload.l3.go = "Marigot_armory";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].island = "SaintMartin";
	n = n + 1;


	// Marigot armory-------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\LargeStore";
	Locations[n].id = "Marigot_armory";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";
	Locations[n].image = "Fort_Inside_Fort_2.tga";

	//Town sack
	Locations[n].townsack = "Marigot";
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
	Locations[n].reload.l1.go = "Marigot_fakefort1";
	Locations[n].reload.l1.emerge = "reloadc5";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Marigot_fakefort3";
	Locations[n].reload.l3.emerge = "reloadC4";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].island = "SaintMartin";
	n = n + 1;


	// --------- Marigot_store ----------------------------------------

	Locations[n].filespath.models = "locations\Inside\StoreSmall";
	Locations[n].image = "Inside_StoreSmall.tga";

	Locations[n].id = "Marigot_store"; // KK
	locations[n].id.label = "Store";

	//Town sack
	Locations[n].townsack = "Marigot";

	//Sound
	locations[n].type = "shop"; // KK
	locations[n].fastreload = "Marigot";
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
	Locations[n].models.night.fonar = "ss_fn";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\oxss_";
	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "Marigot_port";
	Locations[n].reload.l1.emerge = "shipyard";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.locator2 = 0.7;

	Locations[n].reload.l2.name = "locator1";
	Locations[n].reload.l2.go = "Marigot_bedroom";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].island = "SaintMartin";
	n = n + 1;

	// ----------Bedroom of Marigot store---------------------------------------
	Locations[n].id = "Marigot_bedroom";
	locations[n].id.label = "Bedroom";
	Locations[n].image = "Inside_Doubleflour_House_Upper.tga";

	//Town sack
	Locations[n].townsack = "Marigot";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Marigot";
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
	Locations[n].models.back = "back\oxlf2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Marigot_store"; // KK
	Locations[n].reload.l1.emerge = "locator1";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].island = "SaintMartin";
	n = n + 1;





	// Marigot tavern -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\LargeTavern";

	Locations[n].id = "Marigot_tavern";
	locations[n].id.label = "Tavern";		// ccc oct06
	Locations[n].image = "Inside_LargeTavern.tga";

	//Town sack
	Locations[n].townsack = "Marigot"; // KK

	//Sound
	locations[n].type = "tavern"; // KK
	locations[n].fastreload = "Marigot";
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
	Locations[n].models.back = "back\oxlt_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Marigot_Town_02";
	Locations[n].reload.l1.emerge = "door_1";

//MAXIMUS -->
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Marigot_tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Room in #stown_name# tavern.";
	LAi_LocationFightDisable(&Locations[n], true);
//MAXIMUS <--

	Locations[n].island = "SaintMartin";
	n = n + 1;

// KK -->	--------------------------------------------------
	Locations[n].id = "Marigot_tavern_upstairs";
	locations[n].id.label = "Room in #stown_name# tavern.";
	Locations[n].image = "Inside_Doubleflour_House_Room.tga";

	//Town sack
	Locations[n].townsack = "Marigot";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Marigot";
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
	Locations[n].reload.l1.go = "Marigot_tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# tavern.";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "SaintMartin";
	n = n + 1;
// <-- KK

	// Marigot Shipyard -------------------------------------------------

	Locations[n].id = "Marigot_shipyard"; // KK
	locations[n].id.label = "Shipwright's Office"; // KK
	Locations[n].filespath.models = "locations\Inside\shipyard";
	Locations[n].image = "Inside_Shipyard1.tga"; // KK

	//Town sack
	Locations[n].townsack = "Marigot";

	//Sound
	locations[n].type = "shop"; // KK
	locations[n].fastreload = "Marigot";
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
	Locations[n].reload.l1.go = "Marigot_port";	
	Locations[n].reload.l1.emerge = "locator32";	
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].island = "SaintMartin";
	n = n + 1;


	// Marigot mansion -------------------------------------------------
	Locations[n].id = "Marigot_mansion_hall";
	locations[n].id.label = "Mansion";
	Locations[n].filespath.models = "locations\inside\Residence_BackHall";
	Locations[n].image = "Inside_Residence_BackHall.tga"; // KK
	//Town sack
	Locations[n].townsack = "Marigot";

	//Sound
	locations[n].type = "residence"; // KK
	locations[n].fastreload = "Marigot";
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
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Marigot_Town_01";
	Locations[n].reload.l1.emerge = "door_9";
	Locations[n].reload.l1.autoreload = "0";
	
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Marigot_mansion_study";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Study.";

	Locations[n].island = "SaintMartin";
	n = n + 1;

	// study for Marigot mansion-------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Residence3";

	Locations[n].id = "Marigot_mansion_study";
	locations[n].id.label = "Study";
	Locations[n].image = "Inside_Residence3.tga";

	//Town sack
	Locations[n].townsack = "Marigot";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Marigot";
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
	Locations[n].reload.l1.go = "Marigot_mansion_hall";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Hall";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Marigot_mansion_bedroom";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Study.";

	Locations[n].island = "SaintMartin";
	n = n + 1;

	// bedroom for Marigot mansion-------------------------------------------------
	Locations[n].id = "Marigot_mansion_bedroom";
	locations[n].id.label = "Bedroom";
	Locations[n].filespath.models = "locations\inside\ResBedRoom";
	Locations[n].image = "Inside_ResBedRoom.tga";

	//Town sack
	Locations[n].townsack = "Marigot";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Marigot";
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
	Locations[n].reload.l1.go = "Marigot_mansion_study";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Study.";

	Locations[n].island = "SaintMartin";
	n = n + 1;



// ------------- Marigot port
	Locations[n].id = "Marigot_port";
	locations[n].id.label = "#stown_name# Port."; // KK
	locations[n].worldmap = "Marigot";
	Locations[n].image = "Town_FalaiseDeFleur_Port_Buildings.tga";
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\port";
	Locations[n].filespath.textures = "locations\FRANCE";

	//Town sack
	Locations[n].townsack = "Marigot";

	//Sound
	locations[n].type = "port"; // KK
	locations[n].fastreload = "Marigot";
	//Models
	//Always
	Locations[n].models.always.city = "FFport01";
	Locations[n].models.always.city.foam = "1";
	Locations[n].models.always.seabed = "FFport01_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.locators = "FFport01_l";
   	Locations[n].models.always.grassPatch = "FFport01_g";
 	//Day
	Locations[n].models.day.fonar = "FFport01_fd";
	Locations[n].models.day.charactersPatch = "FFport01_p";
  	Locations[n].models.day.jumpPatch = "FFport01_j";
	//Night
	Locations[n].models.night.fonar = "FFport01_fn";
	Locations[n].models.night.charactersPatch = "FFport01_p";
  	Locations[n].models.night.jumpPatch = "FFport01_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	LAi_LocationFantomsGen(&locations[n], true);
	Locations[n].reload.l1.name = "Falaise_de_fleur_location_01_02";
	Locations[n].reload.l1.go = "Marigot_Town_01";
	Locations[n].reload.l1.emerge = "reload_3_3";
  	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "werf";
	Locations[n].reload.l2.go = "Marigot_town";
	Locations[n].reload.l2.emerge = "Reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.werf = 3;

	Locations[n].reload.l3.name = "werf_back";
	Locations[n].reload.l3.go = "Marigot_town";
	Locations[n].reload.l3.emerge = "Reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "#stown_name#";
	Locations[n].locators_radius.reload.werf_back = 2;

	Locations[n].reload.l4.name = "sea";
	Locations[n].reload.l4.go = "SaintMartin";
	Locations[n].reload.l4.emerge = "reload_3";
	Locations[n].reload.l4.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l4.label = "Ship.";
	else
		Locations[n].reload.l4.label = "Sea.";
	Locations[n].locators_radius.reload.sea = 3;

	Locations[n].reload.l5.name = "sea_back";
	Locations[n].reload.l5.go = "SaintMartin";
	Locations[n].reload.l5.emerge = "reload_3";
	Locations[n].reload.l5.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l5.label = "Ship.";
	else
		Locations[n].reload.l5.label = "Sea.";
	Locations[n].locators_radius.reload.sea_back = 2;
	
	Locations[n].reload.l6.name = "shipyard";
	Locations[n].reload.l6.go = "Marigot_store"; // KK
	Locations[n].reload.l6.emerge = "locator2";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l6.goto_disable = 1; // Screwface: Disable Go-To location
	
	Locations[n].reload.l7.name = "locator33";
	Locations[n].reload.l7.go = "";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	
	Locations[n].reload.l8.name = "locator32";
	Locations[n].reload.l8.go = "Marigot_shipyard";
	Locations[n].reload.l8.emerge = "reload1";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l8.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].island = "SaintMartin";
	n = n + 1;

	//Marigot church -------------------------------------------------
	Locations[n].id = "Marigot_Church";
	locations[n].id.label = "#stown_name# Church";
	Locations[n].image = "GB_Charleston_church.tga";
	Locations[n].filespath.models = "locations\inside\Church_4";

	//Town sack
	Locations[n].townsack = "Marigot";

	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "Marigot";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\church_4";
	locations[n].models.always.churchInside2 = "churchInsideBig1";
	locations[n].models.always.churchInside2.level = 65538;
	locations[n].models.always.locators = "churchInsideBig1_locators";

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
	
	//Day
	locations[n].models.day.charactersPatch = "churchInsideBig1_patch";
	//Night
	locations[n].models.night.charactersPatch = "churchInsideBig1_patch";
	//Environment
	locations[n].environment.weather = "false";
	locations[n].environment.sea = "false";
	
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Marigot_town_01";
	locations[n].reload.l1.emerge = "door_6";
	locations[n].reload.l1.autoreload = "0";

	Locations[n].island = "SaintMartin";
	n = n + 1;
	
// -------------------------------------------------
	Locations[n].id = "Marigot_town_01";
	locations[n].id.label = "#stown_name#";
	locations[n].worldmap = "Marigot";
	Locations[n].filespath.models = "locations\Town_Redmond\Town_03";
	Locations[n].filespath.textures = "locations\FRANCE";
	Locations[n].image = "Town_Redmond_Town_03_France.tga";

	//Town sack
	Locations[n].townsack = "Marigot";

	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "Marigot";
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	Locations[n].models.always.a = "Red03";
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
	Locations[n].reload.l99.name = "Door_12";
	Locations[n].reload.l99.go = "Marigot_Cellar";
	Locations[n].reload.l99.emerge = "reload2";
	Locations[n].reload.l99.autoreload = "0";
	Locations[n].reload.l99.label = "#stown_name#.";

	Locations[n].reload.l1.name = "reload_3_2";
	Locations[n].reload.l1.go = "Marigot_Town_02";
	Locations[n].reload.l1.emerge = "reload_4_2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";
	Locations[n].locators_radius.reload.reload_3_2 = 2.0;

	Locations[n].reload.l2.name = "reload_3_1";
	Locations[n].reload.l2.go = "Marigot_Town_02";
	Locations[n].reload.l2.emerge = "reload_4_1_back";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "#stown_name#";
	Locations[n].locators_radius.reload.reload_3_1 = 2.0;

	Locations[n].reload.l3.name = "reload_3_3";
	Locations[n].reload.l3.go = "Marigot_port"; // KK
	Locations[n].reload.l3.emerge = "Falaise_de_fleur_location_01_02";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Port.";

	Locations[n].reload.l24.name = "reload_3_2_back";
	Locations[n].reload.l24.go = "Marigot_Town_02";
	Locations[n].reload.l24.emerge = "reload_4_2";
	Locations[n].reload.l24.autoreload = "0";
	Locations[n].reload.l24.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload_3_2_back = 2.0;

	Locations[n].reload.l5.name = "reload_3_1_back";
	Locations[n].reload.l5.go = "Marigot_Town_02";
	Locations[n].reload.l5.emerge = "reload_4_1_back";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload_3_1_back = 2.0;

	Locations[n].reload.l6.name = "reload_3_3_back";
	Locations[n].reload.l6.go = "Marigot_port"; // KK
	Locations[n].reload.l6.emerge = "Falaise_de_fleur_location_01_02";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Port.";
/*
	Locations[n].reload.l4.name = "door_6";
	Locations[n].reload.l4.go = "Marigot_church";
	Locations[n].reload.l4.emerge = "Reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Church.";
	Locations[n].reload.l4.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l4.goto_disable = 1; // Screwface: Disable Go-To location
*/
	Locations[n].reload.l7.name = "door_9";
	Locations[n].reload.l7.go = "Marigot_mansion_hall";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Mansion.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l7.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l8.name = "door_11";
	Locations[n].reload.l8.go = "Marigot_HouseInsideR11(03)";
	Locations[n].reload.l8.emerge = "reload1";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "House.";
	
	Locations[n].reload.l9.name = "door_6";
	Locations[n].reload.l9.go = "Marigot_Church";
	Locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "Church";


	Locations[n].island = "SaintMartin"; // NK 04-08-29
	n = n + 1;
	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Doubleflour_house";
	Locations[n].id = "Marigot_Cellar";
	locations[n].id.label = "House.";
	Locations[n].image = "Inside_Doubleflour_House_Lower.tga";

	//Town sack
	Locations[n].townsack = "Marigot";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Marigot";
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
	Locations[n].models.back = "back\mulf1_";
	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Marigot_Town_01";
	Locations[n].reload.l1.emerge = "Door_12";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	
	Locations[n].reload.l2.name = "reload1";
	Locations[n].reload.l2.go = "Marigot_dungeon";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Dungeon.";
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "SaintMartin"; // NK 04-08-29
	n = n + 1;
	// -------------------------------------------------
	Locations[n].id = "Marigot_town_02";
	locations[n].id.label = "#stown_name#";
	locations[n].worldmap = "Marigot";
	Locations[n].filespath.models = "locations\Town_Redmond\Town_04";
	Locations[n].filespath.textures = "locations\FRANCE";
	Locations[n].image = "Town_Redmond_Town_04_France.tga";

	//Town sack
	Locations[n].townsack = "Marigot";

	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "Marigot";
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
	Locations[n].reload.l1.go = "Marigot_Town_01";
	Locations[n].reload.l1.emerge = "reload_3_2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload_4_2 = 2.0;

	Locations[n].reload.l21.name = "reload_4_2_back";
	Locations[n].reload.l21.go = "Marigot_Town_01";
	Locations[n].reload.l21.emerge = "reload_3_2";
	Locations[n].reload.l21.autoreload = "1";
	Locations[n].reload.l21.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload_4_2_back = 2.0;

	Locations[n].reload.l2.name = "reload_4_1";
	Locations[n].reload.l2.go = "Marigot_Town_01";
	Locations[n].reload.l2.emerge = "reload_3_1_back";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload_4_1 = 2.0;

	Locations[n].reload.l22.name = "reload_4_1_back";
	Locations[n].reload.l22.go = "Marigot_Town_01";
	Locations[n].reload.l22.emerge = "reload_3_1_back";
	Locations[n].reload.l22.autoreload = "1";
	Locations[n].reload.l22.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload_4_1_back = 2.0;

	Locations[n].reload.l3.name = "reload_2_jungle";
	Locations[n].reload.l3.go = "Marigot_exit"; // KK
	Locations[n].reload.l3.emerge = "Reload2";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Jungle.";

	Locations[n].reload.l4.name = "door_7";
	Locations[n].reload.l4.go = ""; // KK
	Locations[n].reload.l4.emerge = "";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";

	Locations[n].reload.l7.name = "door_1";
	Locations[n].reload.l7.go = "Marigot_tavern";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Tavern.";
	Locations[n].reload.l7.close_for_night = 0;
	Locations[n].locators_radius.reload.reload1 = 0.75;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l7.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l9.name = "door_2";
	Locations[n].reload.l9.go = "Marigot_HouseInsideR2";
	Locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "House.";
	Locations[n].reload.l9.close_for_night = 0;
	Locations[n].locators_radius.reload.reload1 = 0.75;

	Locations[n].reload.l10.name = "door_4";
	Locations[n].reload.l10.go = "Marigot_HouseInsideR4";
	Locations[n].reload.l10.emerge = "reload1";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "House.";
	Locations[n].reload.l10.close_for_night = 0;
	Locations[n].locators_radius.reload.reload1 = 0.75;


	Locations[n].island = "SaintMartin"; // NK 04-08-29
	n = n + 1;
    // ---------------------------------------------------
    Locations[n].id = "Marigot_exit";
	locations[n].id.label = "Jungle";
	Locations[n].filespath.models = "locations\Town_Redmond\REDexit2";
	Locations[n].filespath.textures = "locations\FRANCE";
	Locations[n].image = "Town_Redmond_Exit2.tga";

	//Town sack
	Locations[n].townsack = "Marigot";

	//Sound
	locations[n].type = "dungeon";	// for warzone atmosphere
	LAi_LocationMonstersGen(&locations[n], false);
	LAi_LocationFantomsGen(&locations[n], true);

    //Models
	//Always
	Locations[n].models.always.locators = "Redexit2_l";
	Locations[n].models.always.exit = "Redexit2";
	Locations[n].models.always.grassPatch = "Redexit2_g";

	//Day
	Locations[n].models.day.charactersPatch = "Redexit2_p";
	Locations[n].models.day.fonar = "Redexit2_fd";
	//Night
	Locations[n].models.night.charactersPatch = "Redexit2_p";
	Locations[n].models.night.fonar = "Redexit2_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "Reload2";
	Locations[n].reload.l1.go = "Marigot_Town_02";
	Locations[n].reload.l1.emerge = "reload_2_jungle";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].reload.l3.name = "Reload2_back";
	Locations[n].reload.l3.go = "Marigot_Town_02";
	Locations[n].reload.l3.emerge = "reload_2_jungle";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "#stown_name#.";

	Locations[n].reload.l2.name = "Reload1";
	Locations[n].reload.l2.go = "SaintMartin_jungle_01";
	Locations[n].reload.l2.emerge = "Reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 2.0;

	Locations[n].reload.l4.name = "Reload1_back";
	Locations[n].reload.l4.go = "SaintMartin_jungle_01";
	Locations[n].reload.l4.emerge = "Reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 2.0;

	Locations[n].island = "SaintMartin";
	n = n + 1;

	// ------------ Marigot_town -------------------------------------

	Locations[n].id = "Marigot_town";
	locations[n].id.label = "#stown_name#";
	Locations[n].image = "Town_FalaiseDeFleur_Exit_Buildings.tga";
	//Sound
	locations[n].type = "town";
//	locations[n].fastreload = "QC";
	LAi_LocationMonstersGen(&locations[n], true);

	//Town sack
	Locations[n].townsack = "Marigot";

	//Models
	//Always
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\exit";
	Locations[n].filespath.textures = "locations\FRANCE";
	Locations[n].models.always.jungle = "FFexit";
	Locations[n].models.always.locators = "FFexit_l";

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
	Locations[n].reload.l1.go = "Marigot_fakefort1";
	Locations[n].reload.l1.emerge = "reloadC3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Fort";

	Locations[n].reload.l2.name = "reload1";
	Locations[n].reload.l2.go = "Marigot_port";
	Locations[n].reload.l2.emerge = "werf";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "#stown_name#";
	Locations[n].locators_radius.reload.reload1 = 3;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Marigot_port";
	Locations[n].reload.l3.emerge = "werf";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "#stown_name#";
	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].island = "SaintMartin";
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Marigot_HouseInsideR11(03)";
	locations[n].id.label = "House";
	Locations[n].image = "Inside_mh6.tga";

	//Town sack
	Locations[n].townsack = "Marigot";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Marigot";
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
	Locations[n].reload.l1.go = "Marigot_town_01";
	Locations[n].reload.l1.emerge = "door_11";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";

	Locations[n].island = "SaintMartin"; // NK 04-08-29
	n = n + 1;

		// -------------------------------------------------
	Locations[n].id = "Marigot_HouseInsideR2";
	locations[n].id.label = "House";
	Locations[n].image = "Inside_Smallhome.tga";

	//Town sack
	Locations[n].townsack = "Marigot";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Marigot";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Smallhome";
	Locations[n].models.always.city = "sh";
	Locations[n].models.always.locators = "sh_l";
	Locations[n].models.always.window = "sh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
//	Locations[n].models.day.lamp = "FalaiseDeFleur05_day";
	Locations[n].models.day.charactersPatch = "sh_p";

	//Night
//	Locations[n].models.night.lamp = "FalaiseDeFleur05_night";
	Locations[n].models.night.charactersPatch = "sh_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redsh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Marigot_town_02";
	Locations[n].reload.l1.emerge = "door_2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";

	Locations[n].island = "SaintMartin"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Marigot_HouseInsideR4";
	locations[n].id.label = "House";
	Locations[n].image = "Inside_mh8.tga";

	//Town sack
	Locations[n].townsack = "Marigot";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Marigot";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\mh8";
	Locations[n].models.always.city = "mh8";
	Locations[n].models.always.locators = "mh8_l";
	Locations[n].models.always.window = "mh8_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
//	Locations[n].models.day.lamp = "FalaiseDeFleur05_day";
	Locations[n].models.day.charactersPatch = "mh8_p";

	//Night
//	Locations[n].models.night.lamp = "FalaiseDeFleur05_night";
	Locations[n].models.night.charactersPatch = "mh8_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redmh8_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Marigot_town_02";
	Locations[n].reload.l1.emerge = "door_4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";

	Locations[n].locators_radius.camdetector.camera1 = 3.0;
	Locations[n].locators_radius.camdetector.camera2 = 1.8;

	Locations[n].island = "SaintMartin"; // NK 04-08-29
	n = n + 1;

	// jungle 1 -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_7";

	Locations[n].id = "SaintMartin_Jungle_01";
	locations[n].id.label = "Jungle";
	Locations[n].image = "Outside_Jungle_7.tga";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);

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
	Locations[n].reload.l1.go = "Marigot_exit";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 4;

	Locations[n].reload.l5.name = "reload1_back";
	Locations[n].reload.l5.go = "Marigot_exit";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 1;

	Locations[n].reload.l4.name = "reload2";
	Locations[n].reload.l4.go = "SaintMartin_Jungle_02";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].locators_radius.reload.reload2 = 4;

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "SaintMartin_Jungle_02";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "SaintMartin_shore_01";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Simpson Bay";
	Locations[n].locators_radius.reload.reload3 = 4;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "SaintMartin_shore_01";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Simpson Bay";
	Locations[n].locators_radius.reload.reload3_back = 2;


	Locations[n].island = "SaintMartin";
	n = n + 1;


	//  -------- Simpson Bay -----------------------------------------
	Locations[n].id = "SaintMartin_shore_01";
	locations[n].id.label = "Simpson Bay."; // KK
	// locations[n].worldmap = "SaintMartin_shore_01";
	Locations[n].filespath.models = "locations\Outside\Shore_6";
	Locations[n].image = "Outside_Shore_6.tga";
	Locations[n].name = "Simpson Bay";
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
	Locations[n].reload.l1.go = "SaintMartin_Jungle_01";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.locator3 = 1;

	Locations[n].reload.l3.name = "Reload2_back";
	Locations[n].reload.l3.go = "SaintMartin_Jungle_01";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.Reload2_back = 5;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "SaintMartin";
	Locations[n].reload.l2.emerge = "reload_2";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 11.0;

	Locations[n].island = "SaintMartin";
	n = n + 1;



	// ------- Baie Orient ------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Shore_4";

	Locations[n].id = "SaintMartin_shore_02";
	locations[n].id.label = "Baie Orient."; // KK
	locations[n].worldmap = "SaintMartin_shore_02"; // KK
	Locations[n].image = "Outside_Shore_4.tga";
	Locations[n].name = "Baie Orient";
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
	Locations[n].reload.l4.go = "Philipsburg_Dungeon";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";	
	Locations[n].reload.l4.label = "Hidden Cave.";

	Locations[n].reload.l5.name = "rock1_back";
	Locations[n].reload.l5.go = "Philipsburg_Dungeon";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].locators_radius.reload.rock1_back = 1.5;
	Locations[n].reload.l5.label = "Hidden Cave.";


	Locations[n].reload.l1.name = "locator3";
	Locations[n].reload.l1.go = "SaintMartin_jungle_02";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.locator3 = 3;
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l3.name = "locator3_back";
	Locations[n].reload.l3.go = "SaintMartin_jungle_02";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.locator3_back = 1;
	Locations[n].reload.l3.label = "Jungle.";

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "SaintMartin";
	Locations[n].reload.l2.emerge = "reload_4";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.boat = 9.0;
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";

	Locations[n].island = "SaintMartin";
	n = n + 1;

	// jungle 2 -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_3";
	Locations[n].filespath.textures = "locations\JUNGLES";

	Locations[n].id = "SaintMartin_Jungle_02";
	locations[n].id.label = "jungle";
	Locations[n].image = "Outside_Jungle_3.tga";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);

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
	Locations[n].reload.l1.go = "SaintMartin_shore_02";
	Locations[n].reload.l1.emerge = "locator3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1 = 1.0;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "SaintMartin_shore_02";
	Locations[n].reload.l4.emerge = "locator3";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "SaintMartin_Jungle_01";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2 = 3.0;

	Locations[n].reload.l5.name = "reload2_back";
	Locations[n].reload.l5.go = "SaintMartin_Jungle_01";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3.0;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Philipsburg_exit";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload3 = 3.0;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Philipsburg_exit";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 3.0;


	Locations[n].island = "SaintMartin";
	n = n + 1;


// ----------- Marigot_dungeon --------------------------------------

	Locations[n].filespath.models = "locations\Inside\Mine";

	Locations[n].id = "Marigot_dungeon";
	locations[n].id.label = "Mine";
	Locations[n].image = "Inside_Mine.tga";

	//Sound
	locations[n].type = "dungeon";
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
	Locations[n].reload.l1.go = "Philipsburg_Dungeon";
	Locations[n].reload.l1.emerge = "reloadc3";
	Locations[n].reload.l1.autoreload = "1";

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Philipsburg_Dungeon";
	Locations[n].reload.l2.emerge = "reloadc3";
	Locations[n].reload.l2.autoreload = "1";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Marigot_Cellar";
	Locations[n].reload.l3.emerge = "reload1";


	Locations[n].island = "SaintMartin";
	n = n + 1;


	// ----------------- Philipsburg_Dungeon --------------------
	Locations[n].filespath.models = "locations\Inside\Sewer"; // PB: Flood the sewer as per an original idea by CCC
	Locations[n].id = "Philipsburg_Dungeon";
	Locations[n].image = "Inside_Sewer.tga";
	Locations[n].monsters = "1";
	locations[n].id.label = "#stown_name# Sewer";

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
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.0; // screwface

	LAi_LocationFantomsGen(&locations[n], true);

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Philipsburg_town";
	Locations[n].reload.l1.emerge = "reload10";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "SaintMartin_shore_02";
	Locations[n].reload.l2.emerge = "rock1";
	Locations[n].reload.l2.autoreload = "1";

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "SaintMartin_shore_02";
	Locations[n].reload.l3.emerge = "rock1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.reload2_back = 1.5;

// ccc new exit 

	Locations[n].reload.l11.name = "reloadc3";
	Locations[n].reload.l11.go = "Marigot_dungeon";
	Locations[n].reload.l11.emerge = "Reload1";
	Locations[n].reload.l11.autoreload = "1";
/*
	Locations[n].reload.l12.name = "reloadc4";
	Locations[n].reload.l12.go = "Marigot_dungeon";
	Locations[n].reload.l12.emerge = "reload2";
*/

	Locations[n].items.randitem1 = "blade20";

	Locations[n].island = "SaintMartin";
	n = n + 1;


// -----------Philipsburg -------------------------------------------------

	Locations[n].filespath.models = "locations\Town_Greenford\port";
	Locations[n].filespath.textures = "locations\HOLLAND";
	Locations[n].image = "Town_Greenford_Port_Holland.tga";

	Locations[n].id = "Philipsburg_port";
	locations[n].id.label = "#stown_name# port."; // KK
	locations[n].worldmap = "Philipsburg";

	//Town sack
	Locations[n].townsack = "Philipsburg";

	//Sound
	locations[n].type = "port"; // KK
	locations[n].fastreload = "Philipsburg";
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	Locations[n].models.always.locators = "GrPort_l";
	Locations[n].models.always.l1 = "GrPort";
	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.seabed = "GrPort_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "GrPort_g";
	Locations[n].models.always.add = "GrPort_PB";
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
	Locations[n].reload.l1.go = "SaintMartin";
	Locations[n].reload.l1.emerge = "reload_1";
	Locations[n].reload.l1.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l1.label = "Ship.";
	else
		Locations[n].reload.l1.label = "Sea.";
	Locations[n].locators_radius.reload.Reload1 = 3.0;


	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "SaintMartin";
	Locations[n].reload.l3.emerge = "reload_1";
	Locations[n].reload.l3.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l3.label = "Ship.";
	else
		Locations[n].reload.l3.label = "Sea.";

	Locations[n].locators_radius.reload.reload1_back = 3.0;

	Locations[n].reload.l2.name = "reload4";
	Locations[n].reload.l2.go = "Philipsburg_town";
	Locations[n].reload.l2.emerge = "Reload9_back";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name#.";


	Locations[n].island = "SaintMartin";
	n = n + 1;

	// Philipsburg store -------------------------------------------------

	Locations[n].id = "Philipsburg_store"; // KK
	locations[n].id.label = "#stown_name# store";

	//Sound
	locations[n].type = "shop"; // KK
	locations[n].fastreload = "Philipsburg";

	Locations[n].filespath.models = "locations\Inside\MediumStore";
	Locations[n].image = "Inside_MediumStore.tga";

	//Town sack
	Locations[n].townsack = "Philipsburg"; // KK

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
	Locations[n].reload.l1.go = "Philipsburg_town_02";
	Locations[n].reload.l1.emerge = "reload2";

	Locations[n].island = "SaintMartin";
	n = n + 1;


	// Philipsburg tavern -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\LargeTavern";

	Locations[n].id = "Philipsburg_tavern";
	locations[n].id.label = "#stown_name# tavern";		// ccc oct06
	Locations[n].image = "Inside_LargeTavern.tga";

	//Town sack
	Locations[n].townsack = "Philipsburg"; // KK

	//Sound
	locations[n].type = "tavern"; // KK
	locations[n].fastreload = "Philipsburg";
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
	Locations[n].models.back = "back\oxlt_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Philipsburg_town_02";
	Locations[n].reload.l1.emerge = "reload3";

//MAXIMUS -->
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Philipsburg_tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Room in #stown_name# tavern.";
	LAi_LocationFightDisable(&Locations[n], true);
//MAXIMUS <--

	Locations[n].island = "SaintMartin";
	n = n + 1;

// KK --> -------------------------------------------------
	Locations[n].id = "Philipsburg_tavern_upstairs";
	locations[n].id.label = "Room in #stown_name# tavern.";
	Locations[n].image = "Inside_Doubleflour_House_Room.tga";

	//Town sack
	Locations[n].townsack = "Philipsburg";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Philipsburg";
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
	Locations[n].reload.l1.go = "Philipsburg_tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# tavern.";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "SaintMartin"; // NK 04-08-29
	n = n + 1;
// <-- KK

	// Philipsburg town -------------------------------------------------
	Locations[n].id = "Philipsburg_town";
	locations[n].id.label = "#stown_name#";
	locations[n].worldmap = "Philipsburg";
	Locations[n].image = "Town_IslaMuelle_Town_03_Holland.tga";

	//Town sack
	Locations[n].townsack = "Philipsburg";

	Locations[n].filespath.models = "locations\Town_IslaMuelle\town_03";
	Locations[n].filespath.textures = "locations\HOLLAND";


	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "Philipsburg";
	LAi_LocationFantomsGen(&locations[n], true);
	// locations[n].fastreload = "Muelle";
	//Models
	//Always
	Locations[n].models.always.l1 = "Mu03";
	Locations[n].models.always.locators = "Mu03_l";
	Locations[n].models.always.grassPatch = "Mu03_g";
	Locations[n].models.always.add = "mu03_add"; 
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
	Locations[n].reload.l1.go = "Philipsburg_exit";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "Reload6_back";
	Locations[n].reload.l2.go = "Philipsburg_town_02";
	Locations[n].reload.l2.emerge = "Reload4";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name#";

	Locations[n].reload.l3.name = "Reload8";
	Locations[n].reload.l3.go = "Philipsburg_fakefort3";
	Locations[n].reload.l3.emerge = "reloadC4";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Fort";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l3.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l4.name = "Reload3";
	Locations[n].reload.l4.go = "Philipsburg_shipyard";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l4.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l5.name = "Reload10";
	Locations[n].reload.l5.go = "Philipsburg_dungeon";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";

	Locations[n].reload.l6.name = "Reload4";
	Locations[n].reload.l6.go = "Philipsburg_residence";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "0";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l6.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l7.name = "Reload7";
	Locations[n].reload.l7.go = "Philipsburg_house2"; // KK
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";

	Locations[n].reload.l8.name = "Reload2";
	Locations[n].reload.l8.go = "Philipsburg_house1";
	Locations[n].reload.l8.emerge = "reload1";
	Locations[n].reload.l8.autoreload = "0";

	Locations[n].reload.l9.name = "Reload9_back";
	Locations[n].reload.l9.go = "Philipsburg_port";
	Locations[n].reload.l9.emerge = "reload4";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "Sea port.";

	Locations[n].island = "SaintMartin";
	n = n + 1;
	// ------------------------------------------
	Locations[n].filespath.models = "locations\Town_IslaMuelle\town_02";
	Locations[n].filespath.textures = "locations\HOLLAND";

	Locations[n].id = "Philipsburg_town_02";
	locations[n].id.label = "#stown_name#";
	locations[n].worldmap = "Philipsburg";
	Locations[n].image = "Town_IslaMuelle_Town_02_Holland.tga";
	//Sound

	//Town sack
	Locations[n].townsack = "Philipsburg";

	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].fastreload = "Philipsburg";
	//Models
	//Always
	Locations[n].models.always.locators = "Mu02_l";
	Locations[n].models.always.l1 = "Mu02";
	Locations[n].models.always.grassPatch = "Mu02_g";
	//Day
	Locations[n].models.day.charactersPatch = "Mu02_p";
	Locations[n].models.day.jumpPatch = "Mu02_j";
	Locations[n].models.day.fonar = "Mu02_fd";
	//Night
	Locations[n].models.night.charactersPatch = "Mu02_p";
	Locations[n].models.night.fonar = "Mu02_fn";
	Locations[n].models.night.jumpPatch = "Mu02_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	//Reload map

	Locations[n].reload.l1.name = "Reload4";
	Locations[n].reload.l1.go = "Philipsburg_town";
	Locations[n].reload.l1.emerge = "Reload6_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";

	Locations[n].reload.l2.name = "reload3";
	Locations[n].reload.l2.go = "Philipsburg_tavern";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Tavern";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l2.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Philipsburg_store";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Store.";
	Locations[n].reload.l3.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l3.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].island = "SaintMartin"; // NK 04-08-29
	n = n + 1;
	// ------------------------------------------
	
	Locations[n].filespath.models = "locations\Inside\Pirate_House";	

	Locations[n].id = "Philipsburg_house1";
	locations[n].id.label = "House";
	Locations[n].image = "Inside_Pirate_House.tga";
	//Town sack
	Locations[n].townsack = "Philipsburg";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Philipsburg";
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
	Locations[n].reload.l1.go = "Philipsburg_town";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].island = "SaintMartin";
	n = n + 1; 

// KK -->
	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Doubleflour_house";
	Locations[n].id = "Philipsburg_House2";
	locations[n].id.label = "House.";
	Locations[n].image = "Inside_Doubleflour_House_Upper.tga";

	//Town sack
	Locations[n].townsack = "Philipsburg";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Philipsburg";
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
	Locations[n].reload.l1.go = "Philipsburg_town";
	Locations[n].reload.l1.emerge = "reload7";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].island = "SaintMartin";
	n = n + 1;
// <-- KK

// Philipsburg_residence -------------------------------------------------
	Locations[n].id = "Philipsburg_residence";
	Locations[n].filespath.models = "locations\Inside\Residence3";

	locations[n].id.label = "#stown_name# townhall."; // KK
	Locations[n].image = "Inside_Residence3.tga"; // KK

	//Town sack
	Locations[n].townsack = "Philipsburg";

	//Sound
	locations[n].type = "residence"; // KK
	locations[n].fastreload = "Philipsburg";
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
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Philipsburg_town";
	Locations[n].reload.l2.emerge = "reload4"; 
	Locations[n].reload.l2.autoreload = "0"; 

	Locations[n].island = "SaintMartin";
	n = n + 1;


	// Philipsburg shipyard -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\shipyard";

	Locations[n].id = "Philipsburg_shipyard"; // KK
	locations[n].id.label = "Shipwright's Office"; // KK
	Locations[n].image = "Inside_Shipyard1.tga"; // KK

	//Town sack
	Locations[n].townsack = "Philipsburg";

	//Sound
	locations[n].type = "shop"; // KK
	locations[n].fastreload = "Philipsburg";
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
	Locations[n].reload.l1.go = "Philipsburg_town";	
	Locations[n].reload.l1.emerge = "reload3";	
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reload2";	
	Locations[n].reload.l2.go = "Philipsburg_fakefort1";	
	Locations[n].reload.l2.emerge = "reloadC1";
	Locations[n].reload.l2.autoreload = "0";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l2.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].island = "SaintMartin";
	n = n + 1;



	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_IslaMuelle\exit";

	Locations[n].id = "Philipsburg_exit";
	locations[n].id.label = "Exit from #stown_name#";
	Locations[n].image = "Town_IslaMuelle_Exit.tga";

	//Town sack
	Locations[n].townsack = "Philipsburg";

	//Sound
	locations[n].type = "dungeon";	// for warzone atmosphere
	LAi_LocationMonstersGen(&locations[n], false);
	LAi_LocationFantomsGen(&locations[n], true);

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
	Locations[n].reload.l3.go = "SaintMartin_jungle_02";
	Locations[n].reload.l3.emerge = "Reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle";

	Locations[n].reload.l1.name = "Reload1_back";
	Locations[n].reload.l1.go = "SaintMartin_jungle_02";
	Locations[n].reload.l1.emerge = "Reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 3.5;
	Locations[n].reload.l1.label = "Jungle";

	Locations[n].reload.l2.name = "Reload2";
	Locations[n].reload.l2.go = "Philipsburg_Town";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name#";


	Locations[n].island = "SaintMartin";
	n = n + 1;



	// Philipsburg fake forts--------------------------------------

	//ID
	Locations[n].id = "Philipsburg_fakefort1";		//new ID
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";	//A warning sign at the gate :)
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_1";
	Locations[n].image = "Fort_Inside_Fort_1.tga";

	//Town sack
	Locations[n].townsack = "Philipsburg";
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
	Locations[n].reload.l1.go = "Philipsburg_fakefort3";
	Locations[n].reload.l1.emerge = "reloadc2";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reloadC4";
	Locations[n].reload.l2.go = "Philipsburg_armory";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l3.name = "reloadc5";
	Locations[n].reload.l3.go = "Philipsburg_fakefort2";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].reload.l4.name = "";
	Locations[n].reload.l4.go = "";
	Locations[n].reload.l4.emerge = "";
	Locations[n].reload.l4.autoreload = "0";

	Locations[n].reload.l5.name = "reloadc1";
	Locations[n].reload.l5.go = "Philipsburg_shipyard";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "0";

	Locations[n].island = "SaintMartin";
	n = n + 1;

	//  Philipsburg fake fort 2----------------------------------

	//ID
	Locations[n].id = "Philipsburg_fakefort2";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";

	//Town sack
	Locations[n].townsack = "Philipsburg";

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
	Locations[n].reload.l1.go = "Philipsburg_fakefort1";
	Locations[n].reload.l1.emerge = "reloadc5";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l3.name = "reloadc1";
	Locations[n].reload.l3.go = "Philipsburg_fakefort3";
	Locations[n].reload.l3.emerge = "reloadc1";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].island = "SaintMartin";
	n = n + 1;

	// ccc Philipsburg fake fort 3----------------------------------

	//ID
	Locations[n].id = "Philipsburg_fakefort3";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";


	//Town sack
	Locations[n].townsack = "Philipsburg";

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
	Locations[n].reload.l1.go = "Philipsburg_fakefort2";
	Locations[n].reload.l1.emerge = "reloadc1";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reloadc2";
	Locations[n].reload.l2.go = "Philipsburg_fakefort1";
	Locations[n].reload.l2.emerge = "reloadc2";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l3.name = "reloadc4";
	Locations[n].reload.l3.go = "Philipsburg_town";
	Locations[n].reload.l3.emerge = "reload8";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].reload.l4.name = "reload1";
	Locations[n].reload.l4.go = "Philipsburg_armory";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "0";

	Locations[n].island = "SaintMartin";
	n = n + 1;


	// ccc Philipsburg armory-------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\LargeStore";
	Locations[n].id = "Philipsburg_armory";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";
	Locations[n].image = "Fort_Inside_Fort_2.tga";

	//Town sack
	Locations[n].townsack = "Philipsburg";
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
	Locations[n].reload.l1.go = "Philipsburg_fakefort1";
	Locations[n].reload.l1.emerge = "reloadc4";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Philipsburg_fakefort3";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].island = "SaintMartin";
	n = n + 1;

// Additional Buildings

	Build_at("Philipsburg_Port", "barracks", "", -3.0, 6.8, 15.2, 0.1, "");
	Build_at("Philipsburg_Port", "windmill", "windmillfan", -3.5, 3.8, 33.0, 0.1, "");
	Build_at("Philipsburg_Port", "shipyard2", "", -11.7, 3.8, 59.9, 0.1, ""); // PB
//	Build_at("Philipsburg_Port", "keep", "", 8.0, 4.6, 50.9, 3.2, "");
	Build_at("Philipsburg_Port", "warehouse", "", 11.8, 3.7, 34.2, -1.5, "");

	Build_at("Philipsburg_Town", "keep", "", -29.0, 1.0, -3.0, 0.2, "");
	Build_at("Philipsburg_Town", "barracks", "", 4.2, 2.1, 27.3, -1.5, "");
	Build_at("Philipsburg_Town", "fence", "",  -25.5, -1.0, 6.0, 0.0, "");
	Build_at("Philipsburg_Town", "mansion", "", -15.689, 2.17366, 26.274, 5., ""); // KK

 	Build_at("Philipsburg_exit", "fence", "cannon", -58.0, 1.3, 80.0, 2.5, LAI_GROUP_MONSTERS);	// shoots at player and defenders
 	Build_at("Philipsburg_exit", "fence", "cannon", -56.0, 1.1, 81.0, 2.5, LAI_GROUP_MONSTERS);	// shoots at player and defenders
 	Build_at("Philipsburg_exit", "forest", "marketstall", -53.0, 1.1, 89.0, 2.5, LAI_GROUP_MONSTERS);

 	Build_at("Philipsburg_exit", "box", "cannon", 2.2, 6.1, 44.5, -2.6, LAI_GROUP_PLAYER);	// supports player and defenders
 	Build_at("Philipsburg_exit", "box", "cannon", -8.5, 3.7, 32.85, -1.5, LAI_GROUP_PLAYER);

 	Build_at("Marigot_exit", "box", "cannon", -5.2, 1.8, -47.25, 1.7, LAI_GROUP_PLAYER);	// supports player and defenders
 	Build_at("Marigot_exit", "box", "cannon", -16.3, 1.8, -47.25, 1.7, LAI_GROUP_PLAYER);

	Build_at("Marigot_exit", "fence", "cannon", -3.0, -2.0, -84.0, -0.3, LAI_GROUP_MONSTERS);
	Build_at("Marigot_exit", "fence", "cannon", -3.0, -2.0, -89.0, -0.6, LAI_GROUP_MONSTERS);
 	Build_at("Marigot_exit", "forest", "marketstall", -1.0, -2.0, -96.0, -1.5, LAI_GROUP_MONSTERS);

 	Build_at("SaintMartin_jungle_02", "windmill", "windmillfan", -5.0, 0.0, 9.0, -3.1, "");

	Build_at("Marigot_town", "windmill", "", 3.1, 1.2, 2.5, 0.2, "");
 	Build_at("Marigot_town", "workshop", "mine", 3.7, 0.6, -2.0, 1.7, "");
 	Build_at("Marigot_town", "workshop", "", 6.4, 0.6, 0.5, 0.1, "");
 	Build_at("Marigot_town", "workshop", "", 3.9, 0.6, 3.6, -1.5, "");
 	Build_at("Marigot_town", "college", "foundry", -14.5, 2.9, -2.0, -1.7, "");
 	Build_at("Marigot_town", "house", "foundry", 18.0, 7.5, 7.5, -3.0, "");
	Build_at("Marigot_town", "keep", "", 0.0, 0.1, -17.7, -0.2, "");

	Build_at("Marigot_port", "mansion", "", 39.0, 6.5, 28.0, 0.2, "");
	Build_at("Marigot_port", "mansion", "", 49.0, 6.5, 29.0, 0.2, "");
	Build_at("Marigot_port", "shipyard2", "", 46.4, 1.6, 72.4, 1.5, ""); // PB
	Build_at("Marigot_port", "bastion", "", 66.0, 7.6, 54.0, 1.7, "");
	Build_at("Marigot_port", "bastion", "", 61.0, 1.6, 64.4, 2.7, "");
	Build_at("Marigot_port", "church", "", 55.0, 14.5, 13.5, 0.2, "");
}
