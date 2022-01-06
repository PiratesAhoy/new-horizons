void LocationInitCuracao(ref n)
{
	//  -------------------------------------------------
	Locations[n].id = "Willemstad_port";
	locations[n].id.label = "#stown_name# port."; // KK
	locations[n].worldmap = "Curacao";
	Locations[n].image = "Town_FalaiseDeFleur_Port_Holland.tga";
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\port";
	Locations[n].filespath.textures = "locations\HOLLAND";

	//Town sack
	Locations[n].townsack = "Willemstad";

	//Sound
	locations[n].type = "port";
	locations[n].fastreload = "Willemstad";
	//Models
	//Always
	Locations[n].models.always.city = "FFport01";
	Locations[n].models.always.city.foam = "1";
	Locations[n].models.always.seabed = "FFport01_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.locators = "FFport01_l_x";
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
	Locations[n].reload.l1.go = "Willemstad_town";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

/*	Locations[n].reload.l2.name = "werf";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.werf = 3;*/

	Locations[n].reload.l3.name = "sea";
	Locations[n].reload.l3.go = "Curacao";
	Locations[n].reload.l3.emerge = "reload_1";
	Locations[n].reload.l3.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l3.label = "Ship.";
	else
		Locations[n].reload.l3.label = "Sea.";
	Locations[n].locators_radius.reload.sea = 3;

/*	Locations[n].reload.l4.name = "werf_back";
	Locations[n].reload.l4.go = "";
	Locations[n].reload.l4.emerge = "";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.werf_back = 2;*/

	Locations[n].reload.l5.name = "sea_back";
	Locations[n].reload.l5.go = "Curacao";
	Locations[n].reload.l5.emerge = "reload_1";
	Locations[n].reload.l5.autoreload = "0";
		if (VISIT_DECK == 1)
		Locations[n].reload.l5.label = "Ship.";
	else
		Locations[n].reload.l5.label = "Sea.";
                Locations[n].locators_radius.reload.sea_back = 2;

	Locations[n].reload.l7.name = "locator33";
	Locations[n].reload.l7.go = "DWIC";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Dutch West India Company.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l7.goto_disable = 1; //JRH

	Locations[n].island = "Curacao"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_Greenford\town";
	Locations[n].filespath.textures = "locations\HOLLAND";
	Locations[n].image = "Town_Greenford_Town_Holland.tga";

	Locations[n].id = "Willemstad_town";
	locations[n].id.label = "#stown_name#";
	locations[n].worldmap = "Willemstad";

	//Town sack
	Locations[n].townsack = "Willemstad";

	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "Willemstad";
	//Models
	//Always
	Locations[n].models.always.locators = "GrTown_l";
	Locations[n].models.always.town = "GrTown";
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
	Locations[n].reload.l1.go = "Willemstad_port";
	Locations[n].reload.l1.emerge = "Falaise_de_fleur_location_01_02";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# port."; // KK

	Locations[n].reload.l2.name = "reload19";
	Locations[n].reload.l2.go = "Willemstad_town_3";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name# town.";

	Locations[n].reload.l3.name = "reload26";
	Locations[n].reload.l3.go = "Willemstad_town_2";
	Locations[n].reload.l3.emerge = "Falaise_de_fleur_location_04_05";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "#stown_name# town.";

	Locations[n].reload.l4.name = "reload7";
	Locations[n].reload.l4.go = "Willemstad_tavern";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Tavern.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l4.goto_disable = 1; // Screwface: Disable Go-To location

/*	Locations[n].reload.l5.name = "reload6";
	Locations[n].reload.l5.go = "";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "House.";

	Locations[n].reload.l6.name = "reload14";
	Locations[n].reload.l6.go = "";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "House.";*/

	Locations[n].reload.l7.name = "reload23";
	Locations[n].reload.l7.go = "Willemstad_Store";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Store.";
	Locations[n].reload.l7.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l7.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l8.name = "reload3";
	Locations[n].reload.l8.go = "Willemstad_Shipyard";
	Locations[n].reload.l8.emerge = "reload1";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "Shipyard.";
	Locations[n].reload.l8.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l8.goto_disable = 1; // Screwface: Disable Go-To location

/* 	Locations[n].reload.l9.name = "reload27";
	Locations[n].reload.l9.go = "";
	Locations[n].reload.l9.emerge = "";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "";
	//Locations[n].reload.l9.close_for_night = 1;

	Locations[n].reload.l10.name = "reload17";// Mosh
	Locations[n].reload.l10.go = "";
	Locations[n].reload.l10.emerge = "reload1";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "House.";
	Locations[n].reload.l10.close_for_night = 1;*/

	Locations[n].reload.l11.name = "reload15";
	Locations[n].reload.l11.go = "Willemstad_church";
	Locations[n].reload.l11.emerge = "reload1";
	Locations[n].reload.l11.autoreload = "0";
	Locations[n].reload.l11.label = "Church.";
	Locations[n].reload.l11.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l11.goto_disable = 1; // Screwface: Disable Go-To location

/*	Locations[n].reload.l12.name = "reload9";
	Locations[n].reload.l12.go = "";
	Locations[n].reload.l12.emerge = "";
	Locations[n].reload.l12.autoreload = "0";
	Locations[n].reload.l12.label = "";
	//Locations[n].reload.l12.close_for_night = 1;

	Locations[n].reload.l13.name = "reload11";
	Locations[n].reload.l13.go = "";
	Locations[n].reload.l13.emerge = "reload1";
	Locations[n].reload.l13.autoreload = "0";
	Locations[n].reload.l13.label = "House.";*/

	Locations[n].reload.l14.name = "reload28";
	Locations[n].reload.l14.go = "Willemstad_TailorsShop";
	Locations[n].reload.l14.emerge = "locator2";
	Locations[n].reload.l14.autoreload = "0";
	Locations[n].reload.l14.label = "Tailor's Shop.";
	Locations[n].reload.l14.close_for_night   = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l14.goto_disable = 1; // Screwface: Disable Go-To location
	
/*	Locations[n].reload.l15.name = "reload25";
	Locations[n].reload.l15.go = "";
	Locations[n].reload.l15.emerge = "reload1";
	Locations[n].reload.l15.autoreload = "0";
	Locations[n].reload.l15.label = "House.";

	Locations[n].reload.l16.name = "reload22";
	Locations[n].reload.l16.go = "";
	Locations[n].reload.l16.emerge = "reload1";
	Locations[n].reload.l16.autoreload = "0";
	Locations[n].reload.l16.label = "House.";*/

	Locations[n].island = "Curacao"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\LargeTavern";

	Locations[n].id = "Willemstad_Tavern";
	locations[n].id.label = "#stown_name# tavern";
	Locations[n].image = "Inside_LargeTavern.tga";

	//Town sack
	Locations[n].townsack = "Willemstad";

	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "Willemstad";
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
	Locations[n].reload.l1.go = "Willemstad_town";
	Locations[n].reload.l1.emerge = "reload7";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Willemstad_tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Room in #stown_name# tavern.";
	Locations[n].reload.l2.disable = true; // KK
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Curacao"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Willemstad_tavern_upstairs";
	locations[n].id.label = "Room in #stown_name# tavern";
	Locations[n].image = "Inside_Doubleflour_House_Room.tga";

	//Town sack
	Locations[n].townsack = "Willemstad";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Willemstad";
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
	Locations[n].reload.l1.go = "Willemstad_tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Tavern.";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "Curacao"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Willemstad_UsurerHouse";
	locations[n].id.label = "Loanshark's Office";
	Locations[n].image = "Inside_Doubleflour_House_Lower.tga";

	//Town sack
	Locations[n].townsack = "Willemstad";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Willemstad";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Doubleflour_house";
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
	Locations[n].models.back = "back\oxlf1_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Willemstad_town_2";
	Locations[n].reload.l1.emerge = "locator21";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Curacao"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\MediumStore";
	Locations[n].image = "Inside_MediumStore.tga";

	Locations[n].id = "Willemstad_Store";
	locations[n].id.label = "#stown_name# store";

	//Town sack
	Locations[n].townsack = "Willemstad";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Willemstad";
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
	Locations[n].models.back = "back\grms_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Willemstad_town";
	Locations[n].reload.l1.emerge = "Reload23";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	Locations[n].locators_radius.camdetector.camera1 = 5;
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Curacao"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\shipyard3";

	Locations[n].id = "Willemstad_shipyard";
	locations[n].id.label = "#stown_name# shipyard";
	Locations[n].image = "Inside_Shipyard3.tga";

	//Town sack
	Locations[n].townsack = "Willemstad";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Willemstad";
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
	Locations[n].models.back = "back\grsh3_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Willemstad_town";
	Locations[n].reload.l1.emerge = "Reload3";
	Locations[n].reload.l1.label = "#stown_name#.";
	Locations[n].reload.l1.autoreload = "0";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Curacao"; // NK 04-08-29
	n = n + 1;

	// ------------------------------------------------------------------

	Locations[n].id = "Willemstad_church";
	locations[n].id.label = "#stown_name# church";
	Locations[n].image = "Inside_Church_2.tga";
	Locations[n].filespath.models = "locations\inside\Church_2";

	//Town sack
	Locations[n].townsack = "Willemstad";

	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "Willemstad";
	//Models
	//Always
	Locations[n].models.always.city = "Church2";
	Locations[n].models.always.locators = "Church2_l";
	Locations[n].models.always.window = "church2_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
//	Locations[n].models.day.lamp = "FalaiseDeFleur05_day";
	Locations[n].models.day.charactersPatch = "Church2_p";

	//Night
//	Locations[n].models.night.lamp = "FalaiseDeFleur05_night";
	Locations[n].models.night.charactersPatch = "Church2_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Willemstad_town";
	Locations[n].reload.l1.emerge = "reload15";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Curacao"; // NK 04-08-29
	n = n + 1;

	// ******************************************************************************************

	// Curacao Tailor
	Locations[n].id = "Willemstad_TailorsShop";	
	Locations[n].id.label = "Tailor's Shop.";
	Locations[n].image = "Inside_StoreSmall.tga";

	//Town sack
	Locations[n].townsack = "Willemstad";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Willemstad";
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
	Locations[n].models.back = "back\oxss_";

	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "Willemstad_town";
	Locations[n].reload.l1.emerge = "reload28";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";
	Locations[n].locators_radius.reload.locator2 = 0.7;
	
	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Curacao"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\inside\residenceA03";

	Locations[n].id = "Willemstad_townhall";
	locations[n].id.label = "#stown_name# townhall";
	locations[n].image = "Inside_ResidencA3.tga";

	//Town sack
	Locations[n].townsack = "Willemstad";

	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Willemstad";
	//Models
	//Always
	Locations[n].models.always.locators = "residence03_locators";
	Locations[n].models.always.l1 = "residence03";
	Locations[n].models.always.window = "residence03_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "Residence03_patch";

	//Night
	Locations[n].models.night.charactersPatch = "Residence03_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\cores5_";

	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Willemstad_town_3";
	Locations[n].reload.l1.emerge = "reload14";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Curacao"; // NK 04-08-29

	n = n + 1;

 	//-------------------------------------------------
	Locations[n].id = "DWIC";
	locations[n].id.label = "Dutch West India Company";
	Locations[n].filespath.models = "locations\inside\Residence_BackHall";
	Locations[n].image = "Inside_Residence_BackHall.tga";

	//Town sack
	Locations[n].townsack = "Willemstad";

	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Willemstad";
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
	Locations[n].reload.l1.go = "Willemstad_port";
	Locations[n].reload.l1.emerge = "locator33";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# port";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Curacao"; // NK 04-08-29
	n = n + 1;

	//  Willemstad_town_2 -------------------------------------------------
	Locations[n].id = "Willemstad_town_2";
	locations[n].id.label = "#stown_name#";
	locations[n].worldmap = "Willemstad";
	Locations[n].image = "Town_FalaiseDeFleur_Town_03_Holland.tga";

	//Town sack
	Locations[n].townsack = "Willemstad";

	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].fastreload = "Willemstad";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\town_03";
	Locations[n].filespath.textures = "locations\HOLLAND";
	Locations[n].models.always.city = "FF03";
	Locations[n].models.always.locators = "FF03_l";
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
	Locations[n].reload.l1.name = "Falaise_de_fleur_location_04_03";
	Locations[n].reload.l1.go = "Curacao_Jungle_02";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Exit.";

	Locations[n].reload.l2.name = "Falaise_de_fleur_location_04_05";
	Locations[n].reload.l2.go = "Willemstad_town";
	Locations[n].reload.l2.emerge = "reload26";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name#. Center.";

	//Locations[n].reload.l3.name = "";
	//Locations[n].reload.l3.go = "";
	//Locations[n].reload.l3.emerge = "";
	//Locations[n].reload.l3.autoreload = "0";
	//Locations[n].reload.l3.label = "";
	//Locations[n].reload.l3.close_for_night = 1;

	Locations[n].reload.l4.name = "locator21";
	Locations[n].reload.l4.go = "Willemstad_UsurerHouse";
	Locations[n].reload.l4.emerge = "reload1"; 
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Loanshark's Office.";
	Locations[n].reload.l4.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l4.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].island = "Curacao"; // NK 04-08-29

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_1";

	Locations[n].id = "Curacao_Jungle_01";
	locations[n].id.label = "Outskirts.";
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
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Willemstad_town_3";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "#stown_name#.";
	Locations[n].locators_radius.reload.Reload1 = 3.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2 = 3.0;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Willemstad_town_3";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "";
	Locations[n].reload.l4.emerge = "";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 2.0;


	Locations[n].island = "Curacao"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "Curacao_Jungle_02";
	locations[n].id.label = "#sisland_name# jungle";
	Locations[n].image = "Town_FalaiseDeFleur_Exit.tga";
	//Sound
	locations[n].type = "jungle";
//	locations[n].fastreload = "Willemstad";
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
	Locations[n].reload.l1.go = "Willemstad_town_2";
	Locations[n].reload.l1.emerge = "Falaise_de_fleur_location_04_03";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. town.";

	Locations[n].reload.l2.name = "reload1";
	Locations[n].reload.l2.go = "Curacao_Jungle_03";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1 = 3;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Curacao_Jungle_03";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].island = "Curacao"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_3";
	Locations[n].filespath.textures = "locations\JUNGLES";

	Locations[n].id = "Curacao_Jungle_03";
	locations[n].id.label = "#sisland_name# jungles";
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
	Locations[n].reload.l1.go = "Curacao_village";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Village."; // KK
	Locations[n].locators_radius.reload.Reload1 = 1.0;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Curacao_village";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Village."; // KK
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Curacao_Jungle_02";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2 = 3.0;

	Locations[n].reload.l5.name = "reload2_back";
	Locations[n].reload.l5.go = "Curacao_Jungle_02";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3.0;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Curacao_shore_01";
	Locations[n].reload.l3.emerge = "locator3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Shore.";
	Locations[n].locators_radius.reload.Reload3 = 3.0;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Curacao_shore_01";
	Locations[n].reload.l6.emerge = "locator3";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Shore.";
	Locations[n].locators_radius.reload.reload3_back = 3.0;

	Locations[n].island = "Curacao";
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Shore_9";

	Locations[n].id = "Curacao_shore_01";
	locations[n].id.label = "Bullen Bay";
	//locations[n].worldmap = "MShore 2";
	Locations[n].image = "Outside_Shore_9.tga";
	Locations[n].name = "Bullen Bay";   // TALISMAN added to make beach name appear in smuggler tavern dialog
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
	Locations[n].reload.l1.go = "Curacao_Jungle_03";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.locator3 = 2.0;

	Locations[n].reload.l3.name = "locator3_back";
	Locations[n].reload.l3.go = "Curacao_Jungle_03";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.locator3_back = 2.0;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Curacao";
	Locations[n].reload.l2.emerge = "reload_2";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 9.0;


	Locations[n].island = "Curacao"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "Curacao_shore_03";
	locations[n].id.label = "Mixteca Bay."; // KK
	Locations[n].filespath.models = "locations\Outside\Shore_6";
	Locations[n].image = "Outside_Shore_6.tga";
	Locations[n].name = "Mixteca Bay";
	//Sound
	locations[n].type = "seashore";

	//Models
	//Always
	Locations[n].models.always.locators = "Shore06_l_x";
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
	Locations[n].environment.sea = "true";

	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Curacao_Jungle_04";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.locator3 = 1;

	Locations[n].reload.l3.name = "Reload2_back";
	Locations[n].reload.l3.go = "Curacao_Jungle_04";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2_back = 5;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Curacao_shore_04";
	Locations[n].reload.l2.emerge = "boat";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Darien Beach.";
	Locations[n].locators_radius.reload.boat = 3.0;

	Locations[n].island = "Curacao"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Shore_8";

	Locations[n].id = "Curacao_shore_02";
	locations[n].id.label = "Bocht Van Hato."; // KK
	Locations[n].image = "Outside_Shore_8.tga";
	Locations[n].name = "Bocht Van Hato";
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
	Locations[n].reload.l1.go = "Curacao_Jungle_04";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 3;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Curacao_Jungle_04";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Curacao";
	Locations[n].reload.l2.emerge = "reload_3";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.boat = 9.0;
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";


	Locations[n].island = "Curacao"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_2";

	Locations[n].id = "Curacao_Jungle_04";
	locations[n].id.label = "#sisland_name# jungles";
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
	Locations[n].reload.l1.go = "Curacao_shore_03";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Mixteca Bay.";
	Locations[n].locators_radius.reload.reload1 = 4;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Curacao_shore_03";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Mixteca Bay.";
	Locations[n].locators_radius.reload.reload1_back = 4;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Curacao_shore_02";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Bocht Van Hato.";
	Locations[n].locators_radius.reload.reload3 = 4;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Curacao_shore_02";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Bocht Van Hato.";
	Locations[n].locators_radius.reload.reload3_back = 4;

	Locations[n].island = "Curacao"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Passage";

	Locations[n].id = "Curacao_shore_04";
	locations[n].id.label = "Darien Beach."; // KK
	Locations[n].image = "Outside_Passage1.tga";
	Locations[n].name = "Darien Beach";
	//Sound
	locations[n].type = "seashore";

	//Models
	//Always
	Locations[n].models.always.locators = "Pass1_l_x";
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
	Locations[n].reload.l1.go = "Curacao_Jungle_05";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Curacao_Jungle_05";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Curacao_shore_03";
	Locations[n].reload.l2.emerge = "boat";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Mixteca Bay.";
	Locations[n].locators_radius.reload.boat = 3.0;

	Locations[n].island = "Curacao"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Cave Entrance";

	Locations[n].id = "Curacao_Jungle_05";
	locations[n].id.label = "Jungle.";
	Locations[n].image = "Outside_Cave_Entrance.tga";
	//Sound
	locations[n].type = "Jungle";

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
	Locations[n].reload.l3.go = "Curacao_shore_04";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Darien Beach.";
	Locations[n].locators_radius.reload.Reload1 = 1;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Curacao_shore_04";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Darien Beach.";
	Locations[n].locators_radius.reload.Reload1_back = 1.3;

	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Curacao_Jungle_06";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2 = 2.0;

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Curacao_Jungle_06";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 2.0;

	Locations[n].island = "Curacao";
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Labirint_4";
	Locations[n].filespath.models = "locations\Incas Temple\Labirint";
	//Sound
	Locations[n].image = "Incas_Temple_Alcove.tga";
	locations[n].type = "inca_temple";
	locations[n].id.label = "Alcove";
	//Models
	//Always
	Locations[n].models.always.locators = "lab3_l_x";
	Locations[n].models.always.l1 = "lab3";

	//Day
	Locations[n].models.day.charactersPatch = "lab3_p";
	//Night
	Locations[n].models.night.charactersPatch = "lab3_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].lockWeather = "Alcove";

	//Reload map

	Locations[n].reload.l28.name = "reload30_back";
	Locations[n].reload.l28.go = "Curacao_Jungle_06";
	Locations[n].reload.l28.emerge = "Reload2";
	Locations[n].reload.l28.autoreload = "0";

	Locations[n].reload.l2.name = "reload13";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "";
        Locations[n].reload.l2.autoreload = "0";

	Locations[n].items.randitem1 = "Darien_idol";

	Locations[n].island = "Curacao"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_7";

	Locations[n].id = "Curacao_Jungle_06";
	locations[n].id.label = "#sisland_name# jungles";
	Locations[n].image = "Outside_Jungle_7.tga";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);


	//Models
	//Always
	Locations[n].models.always.locators = "Jungle07_l_x";
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
	Locations[n].reload.l1.go = "Curacao_Jungle_05";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1 = 4;

	Locations[n].reload.l5.name = "reload1_back";
	Locations[n].reload.l5.go = "Curacao_Jungle_05";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 1;

	Locations[n].reload.l4.name = "reload2";
	Locations[n].reload.l4.go = "Labirint_4";
	Locations[n].reload.l4.emerge = "reload30_back";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Alcove.";
	Locations[n].locators_radius.reload.reload2 = 4;

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Labirint_4";
	Locations[n].reload.l2.emerge = "reload30_back";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Alcove.";
	Locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "";
	Locations[n].reload.l3.emerge = "";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3 = 4;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "";
	Locations[n].reload.l6.emerge = "";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 2;

	Locations[n].island = "Curacao"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_QC\town";
	Locations[n].filespath.textures = "locations\HOLLAND";
	Locations[n].image = "Town_QC_Town.tga";

	Locations[n].id = "Curacao_village";
	locations[n].id.label = "Village.";
	//locations[n].worldmap = "Quebradas Costillas";
	//Town sack
	Locations[n].townsack = "Willemstad";
	//Sound
	locations[n].type = "town";
	//locations[n].fastreload = "QC";
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	Locations[n].models.always.locators = "QCtown_l";
	Locations[n].models.always.town = "QCtown";
	Locations[n].models.always.grassPatch = "QCtown_g";
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
	Locations[n].models.day.charactersPatch = "QCtown_p";
	Locations[n].models.day.fonar = "QCtown_fd";
	//Night
	Locations[n].models.night.charactersPatch = "QCtown_p";
	Locations[n].models.night.fonar = "QCtown_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Curacao_Jungle_03";
	Locations[n].reload.l1.emerge = "Reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Village_House_01";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "House";

	Locations[n].reload.l3.name = "reload5";
	Locations[n].reload.l3.go = "";
	Locations[n].reload.l3.emerge = "";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "";
	Locations[n].reload.l3.close_for_night = 1;

	Locations[n].reload.l4.name = "reload6";
	Locations[n].reload.l4.go = "";
	Locations[n].reload.l4.emerge = "";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].reload.l4.close_for_night = 1;
		
	Locations[n].reload.l5.name = "reload10";
	Locations[n].reload.l5.go = "";
	Locations[n].reload.l5.emerge = "";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "";
	Locations[n].reload.l5.close_for_night = 1;

	Locations[n].reload.l6.name = "Reload4";
	Locations[n].reload.l6.go = "";
	Locations[n].reload.l6.emerge = "";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "";
	Locations[n].reload.l6.close_for_night = 1;

	Locations[n].reload.l7.name = "Reload9";
	Locations[n].reload.l7.go = "Village_Tavern";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Tavern";

	Locations[n].island = "Curacao"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\MediumTavern";

	Locations[n].id = "Village_Tavern";
	locations[n].id.label = "Tavern";
	Locations[n].image = "Inside_MediumTavern.tga";

	//Town sack
	Locations[n].townsack = "Willemstad"; // NK 04-08-29

	//Sound
	locations[n].type = "tavern";
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
	Locations[n].models.back = "back\smumt_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Curacao_village";
	Locations[n].reload.l1.emerge = "reload9";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	//fake reload_to_room
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Village_tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Room.";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Curacao"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Village_tavern_upstairs";
	locations[n].id.label = "Room in tavern";
	Locations[n].image = "Inside_Doubleflour_House_Room.tga";

	//Town sack
	Locations[n].townsack = "Willemstad";

	//Sound
	locations[n].type = "house";
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
	Locations[n].reload.l1.go = "Village_tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Tavern.";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "Curacao"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Pirate_House";	

	Locations[n].id = "Village_House_01";
	locations[n].id.label = "House";
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
	Locations[n].models.back = "back\qcpirh_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Curacao_village";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Village";

	Locations[n].island = "Curacao"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_Conceicao\town";
	Locations[n].filespath.textures = "locations\HOLLAND";

	Locations[n].id = "Willemstad_town_3";
	locations[n].id.label = "#stown_name# town";
	locations[n].worldmap = "Willemstad";
	Locations[n].image = "Town_Conceicao_Town_Holland.tga";

	//Town sack
	Locations[n].townsack = "Willemstad";

	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "Willemstad";
	//Models
	//Always
	Locations[n].models.always.locators = "ConTown_l";
  	Locations[n].models.always.grassPatch = "ConTown_g";
	Locations[n].models.always.town = "ConTown";
	Locations[n].models.always.l1 = "Contown_b02";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "Contown_b03";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "Contown_b04";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	//Day
	Locations[n].models.day.fonar = "ConTown_fd";
	Locations[n].models.day.charactersPatch = "ConTown_pd";
	Locations[n].models.day.jumpPatch = "ConTown_j";
	//Night
	Locations[n].models.night.fonar = "ConTown_fn";
	Locations[n].models.night.charactersPatch = "ConTown_pn";
	Locations[n].models.night.jumpPatch = "ConTown_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	LAi_LocationFantomsGen(&locations[n], true);
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Curacao_Jungle_01";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Outskirts.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Willemstad_town";
	Locations[n].reload.l2.emerge = "reload19";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name#.";

	Locations[n].reload.l3.name = "reload4";
	Locations[n].reload.l3.go = "";
	Locations[n].reload.l3.emerge = "";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "";

	Locations[n].reload.l4.name = "reload18";
	Locations[n].reload.l4.go = "";
	Locations[n].reload.l4.emerge = "";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	//Locations[n].reload.l4.close_for_night = 1;

	Locations[n].reload.l5.name = "reload13";
	Locations[n].reload.l5.go = "";
	Locations[n].reload.l5.emerge = "";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "";
	//Locations[n].reload.l5.close_for_night = 1;

	Locations[n].reload.l6.name = "reload14";
	Locations[n].reload.l6.go = "Willemstad_townhall";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Residence.";
	Locations[n].reload.l6.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l6.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "";
	Locations[n].reload.l7.emerge = "";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Church.";
	//Locations[n].reload.l7.close_for_night = 1;

	Locations[n].reload.l8.name = "reload12";
	Locations[n].reload.l8.go = "";
	Locations[n].reload.l8.emerge = "";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "";
	//Locations[n].reload.l8.close_for_night = 1;

	Locations[n].reload.l9.name = "reload16";
	Locations[n].reload.l9.go = "";
	Locations[n].reload.l9.emerge = ""; 
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "";
	//Locations[n].reload.l9.close_for_night = 1;

	Locations[n].reload.l10.name = "reload11";
	Locations[n].reload.l10.go = "";
	Locations[n].reload.l10.emerge = "";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "";

	Locations[n].reload.l11.name = "reload15";
	Locations[n].reload.l11.go = "";
	Locations[n].reload.l11.emerge = "";
	Locations[n].reload.l11.autoreload = "0";
	Locations[n].reload.l11.label = "";

	Locations[n].reload.l12.name = "reload6";
	Locations[n].reload.l12.go = "";
	Locations[n].reload.l12.emerge = "";
	Locations[n].reload.l12.autoreload = "0";
	Locations[n].reload.l12.label = "";
	//Locations[n].reload.l12.close_for_night = 1;

	Locations[n].island = "Curacao"; // NK 04-08-29
	n = n + 1;

	Build_at("Curacao_Jungle_06", "entrance", "", 6.08, 3.91, -36.0, 0.16, "building");
	Build_at("Labirint_4", "wall", "", -77.39, 6.9, -8.0, 0.15, "building");
	Build_at("Curacao_Jungle_04", "jungle2", "", -3.52, -0.27, -0.1, 2.82, "wild_jungles");
	Build_at("Curacao_Jungle_04", "jungle2", "", -2.29, -1.60, -15.13, 0.31, "wild_jungles");
	Build_at("Curacao_Jungle_04", "jungle2", "", 20.10, -2.34, -25.54, -0.37, "wild_jungles");
	Build_at("Curacao_Jungle_04", "jungle2", "", 2.95, -1.95, -10.00, -2.85, "wild_jungles");
	Build_at("Curacao_Jungle_04", "jungle2", "", -7.45, -0.10, 13.87, 2.71, "wild_jungles");
	Build_at("Curacao_Jungle_04", "jungle2", "", 20.68, 0.29, 21.10, 0.24, "wild_jungles");
	Build_at("Curacao_Jungle_04", "jungle2", "", -15.00, 0.12, -21.20, -0.28, "wild_jungles");
	Build_at("Curacao_Jungle_04", "jungle2", "", -18.87, 0.29, -16.61, 2.17, "wild_jungles");
	Build_at("Curacao_Jungle_04", "jungle", "", 9.75, -1.92, -18.23, 1.38, "wild_jungles");
	Build_at("Curacao_Jungle_04", "jungle2", "", 9.75, -1.92, -18.23, 1.38, "wild_jungles");
	Build_at("Curacao_Jungle_03", "windmill", "windmillfan", -6.96, 0.0, 10.12, -0.11, "");
	Build_at("Curacao_shore_01", "jungle2", "", -5.5, 2.95, -17.57, 1.2, "wild_jungles");

	Build_at("Curacao_Jungle_03", "fence2", "", 36.79, -0.17, 17.68, -1.36, "building");

	Build_at("Curacao_shore_03", "jungle2", "", 26.95, 3.93, -5.67, -1.02, "wild_jungles");
	Build_at("Curacao_shore_03", "jungle2", "", 54.05, 3.89, -21.54, 0.12, "wild_jungles");
	Build_at("Curacao_shore_03", "jungle2", "", -4.1, 3.15, 6.28, 1.36, "wild_jungles");
	Build_at("Curacao_Jungle_01", "windmill", "windmillfan", 10.74, 0.0, 8.35, -1.64, "");
	Build_at("Curacao_Jungle_01", "farm", "", 14.2, 0.0, -14.3, -1.16, "");
	Build_at("Curacao_Jungle_02", "jungle2", "", -8.43, 1.09, -8.77, 1.26, "");
	Build_at("Curacao_Jungle_01", "jungle2", "", 12.62, 0.33, -27.4, -0.44, "");
	Build_at("Curacao_Jungle_01", "tower", "", -8.45, 0.0, -43.91, 0.88, "");
	Build_at("Curacao_Jungle_01", "farm", "", -1.47, 0.0, 21.21, 3.08, "");

	Build_at("Curacao_Jungle_06", "jungle2", "", 25.31, 1.64, -17.41, -1.25, "wild_jungles");
	Build_at("Curacao_Jungle_06", "jungle2", "", -25.49, 0.0, -9.16, -1.36, "wild_jungles");
	Build_at("Curacao_Jungle_06", "jungle2", "", -0.52, 0.25, 14.66, 0.0, "wild_jungles");
	Build_at("Curacao_Jungle_06", "jungle2", "", -7.25, 0.68, -0.31, -1.13, "wild_jungles");
	Build_at("Curacao_Jungle_06", "jungle2", "", 1.45, 0.11, -16.84, -1.34, "wild_jungles");
	Build_at("Curacao_Jungle_06", "jungle2", "", 12.67, 0.5, -13.04, -1, "wild_jungles");
	Build_at("Willemstad_port", "barracks", "", 50.51, 3.74, 36.1, 0.0, "building");
	Build_at("Willemstad_port", "bale", "", 59.57, 2.99, 37.59, 1.51, "Building");
	Build_at("Willemstad_port", "bale", "", 62.88, 3.01, 36.64, 2.56, "Building");
	Build_at("Willemstad_port", "box", "", 44.57, 2.78, 40.7, -0.62, "Building");
	Build_at("Willemstad_port", "box", "", 59.22, 3.29, 35.65, 2.18, "Building");

}
