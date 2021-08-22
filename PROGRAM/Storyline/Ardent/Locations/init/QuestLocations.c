void LocationInitQuestLocations(ref n)
{
	//ID
	Locations[n].id = "Quest_Cabin";
	locations[n].id.label = "Cabin";
	//Info
	Locations[n].filespath.models = "locations\decks\cabin\capsm";
	Locations[n].image = "Deck_Capsm.tga"; // KK
	//Sound
	Locations[n].type = "ship";
	Locations[n].lockCamAngle = 0.4;
//	Locations[n].camshuttle = 1;
//	Locations[n].fastreload = "ship";
//	Locations[n].monsters = 0; // KK

	//Models
	//Always
	Locations[n].models.always.locators = "capsm_ld"; // KK
	Locations[n].models.always.l1 = "capsm";
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
	Locations[n].reload.l1.go = "Quest_ShipDeck4";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Deck";

	n = n + 1;

	//---------------------------------------------
	//ID
	Locations[n].id = "Quest_Hold1";
	locations[n].id.label = "Cargo hold";
	//Info
	Locations[n].filespath.models = "locations\decks\hold";
	Locations[n].image = "deck_hold.tga"; // KK
	//Sound
//	Locations[n].type = "ship";
	Locations[n].type = "deck";
//	Locations[n].camshuttle = 1;
//	Locations[n].fastreload = "ship";
//	Locations[n].monsters = 1; // KK

	//Models
	//Always
	Locations[n].models.always.locators = "hold_ld"; // KK
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
	Locations[n].environment.curse = "false"; // PB: Cursed Coins

	n = n + 1;

	//---------------------------------------------

	//ID
	Locations[n].id = "Quest_ShipDeck4";
	locations[n].id.label = "Ship deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deckLow";
	Locations[n].image = "Sea.tga";
	//Sound
	locations[n].type = "deck";
//	locations[n].type = "own_deck";
	Locations[n].lockCamAngle = 0.4;
	Locations[n].camshuttle = 1;
	Locations[n].fastreload = "ship";
	Locations[n].monsters = 1;

	//Models
	//Always
	Locations[n].models.always.locators = "deckLow_ld"; // KK
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
	Locations[n].boarding = "true";
	Locations[n].MaxSeaHeight = 0.4; // JRH
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Quest_Cabin";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Cabin";

	n = n + 1;

	// -------------------------------------------------

	//ID
	Locations[n].id = "Quest_ShipDeck6";
	locations[n].id.label = "Ship deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deckBig";
	Locations[n].image = "Sea.tga";
	//Sound
	locations[n].type = "own_deck";
	Locations[n].lockCamAngle = 0.4;
	Locations[n].camshuttle = 1;
	Locations[n].fastreload = "ship";
	Locations[n].monsters = 1;

	//Models
	//Always
	Locations[n].models.always.locators = "deckBig_ld"; // KK
	Locations[n].models.always.l1 = "deckBig";
	//Day
	Locations[n].models.day.charactersPatch = "deckBig_p";
	Locations[n].models.day.fonar = "deckBig_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deckBig_p";
	Locations[n].models.night.fonar = "deckBig_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.8; // screwface
	//============| Reload map |============//
	// Captain's cabin
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";
	// Nothing
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "";
	Locations[n].reload.l2.autoreload = "0";
	// Cargo hold
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "";
	Locations[n].reload.l3.emerge = "";
	Locations[n].reload.l3.autoreload = "0";
	// Land on bakbort
	Locations[n].reload.l4.name = "boatl";
	Locations[n].reload.l4.go = "";
	Locations[n].reload.l4.emerge = "";
	Locations[n].reload.l4.autoreload = "0";
	// Land on starbort
	Locations[n].reload.l5.name = "boatr";
	Locations[n].reload.l5.go = "";
	Locations[n].reload.l5.emerge = "";
	Locations[n].reload.l5.autoreload = "0";
// KK -->
	// Sea
	Locations[n].reload.l6.name = "sea";
	Locations[n].reload.l6.go = "Sea";
	Locations[n].reload.l6.emerge = "";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Sea.";
	// Captain's cabin on bakbort
	Locations[n].reload.l7.name = "reload4";
	Locations[n].reload.l7.go = "";
	Locations[n].reload.l7.emerge = "";
	Locations[n].reload.l7.autoreload = "0";
	// Cargo hold on bakbort
	Locations[n].reload.l8.name = "reload5";
	Locations[n].reload.l8.go = "";
	Locations[n].reload.l8.emerge = "";
	Locations[n].reload.l8.autoreload = "0";
// <-- KK

	n = n + 1;

	//---------------------------------------------

	//ID
	Locations[n].id = "Quest_Seadogs";
	locations[n].id.label = "Crew's quarters";
	//Info
	Locations[n].filespath.models = "locations\decks\seadogs"; // KK
	Locations[n].image = "deck_seadogs.tga"; // KK
	//Sound
	Locations[n].type = "crew";
//	Locations[n].lockCamAngle = 0.4;	// LDH removed 23Mar09
	Locations[n].camshuttle = 1;
	Locations[n].fastreload = "ship";
	Locations[n].monsters = 1; // KK

	//Models
	//Always
	Locations[n].models.always.locators = "camp_deck_l";
	Locations[n].models.always.l1 = "camp_deck";
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
	Locations[n].environment.curse = "false"; // PB: Cursed Coins
// KK -->
	//Reload map
	// Corridor
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cabin2SJG";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Cabin";
	// Door near table
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "";
	Locations[n].reload.l2.autoreload = "0";
// <-- KK

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Pirate Fort";
	Locations[n].filespath.textures = "locations\NATIVES";

	Locations[n].id = "Quest_Arawak_Village";
	locations[n].id.label = "Taino Village";
	Locations[n].image = "Pirate_Fort_Native.tga";

	//Town sack
//	Locations[n].townsack = "Khael Roa";

	//Sound
	locations[n].type = "KR_jungle";

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
	Locations[n].reload.l1.go = "IslaMona_port_exit";
	Locations[n].reload.l1.emerge = "Reload1";
	Locations[n].reload.l1.label = "Port outskirts";
	Locations[n].reload.l1.autoreload = 1;
	Locations[n].locators_radius.reload.reload1 = 1;

	Locations[n].reload.l5.name = "Reload1_back";
	Locations[n].reload.l5.go = "IslaMona_port_exit";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.label = "Port outskirts";
	Locations[n].reload.l5.autoreload = 1;
	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].reload.l2.name = "Reload5";
	Locations[n].reload.l2.go = "Quest_Indian_house";
	Locations[n].reload.l2.emerge = "Reload1";
	Locations[n].reload.l2.label = "Chief's House.";

	Locations[n].island = "IslaMona"; // NK 04-08-29

	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "Quest_Indian_house";
	locations[n].id.label = "Chief's House";
	Locations[n].filespath.models = "locations\inside\IndianHome";
	Locations[n].image = "Inside_IndianHome.tga";

	//Town sack
//	Locations[n].townsack = "Khael Roa";

	//Sound
	locations[n].type = "residence";
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
	Locations[n].models.back = "back\ffsh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Quest_Arawak_Village";
	Locations[n].reload.l1.emerge = "Reload5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Quest_Arawak_Village";
	Locations[n].locators_radius.reload.reload1 = 0.8;


	Locations[n].island = "IslaMona"; // NK 04-08-29

	n = n + 1;
	
	// -------------------------------------------------
	Locations[n].id = "Quest_Hispaniola_Labirint_1";
	Locations[n].filespath.models = "locations\Incas Temple\Labirint";
	//Sound
	Locations[n].image = "Incas_Temple_Labirint.tga";
	locations[n].type = "inca_temple";
	locations[n].id.label = "Maze";
	//Models
	//Always
	Locations[n].models.always.locators = "lab1_l";
	Locations[n].models.always.l1 = "lab1";
	//Day
	Locations[n].models.day.charactersPatch = "lab1_p";
	//Night
	Locations[n].models.night.charactersPatch = "lab1_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].lockWeather = "Alcove";
	
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 0, 24);

	//Reload map
	Locations[n].reload.l1.name = "reload27";
	Locations[n].reload.l1.go = "Hispaniola_Temple";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload4";
	Locations[n].reload.l2.go = "Quest_Hispaniola_Labirint_2";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "1";
      
	Locations[n].reload.l22.name = "reload4_back";
	Locations[n].reload.l22.go = "Quest_Hispaniola_Labirint_2";
	Locations[n].reload.l22.emerge = "reload3";
	Locations[n].reload.l22.autoreload = "1";

    	Locations[n].reload.l3.name = "reload11";
	Locations[n].reload.l3.go = "Quest_Hispaniola_Labirint_2";
	Locations[n].reload.l3.emerge = "Reload12";
	Locations[n].reload.l3.autoreload = "1";

	Locations[n].reload.l23.name = "reload11_back";
	Locations[n].reload.l23.go = "Quest_Hispaniola_Labirint_2";
	Locations[n].reload.l23.emerge = "Reload12";
	Locations[n].reload.l23.autoreload = "1";

/*	Locations[n].reload.l4.name = "reload17"; // commented out section starts here
	Locations[n].reload.l4.go = "Quest_Hispaniola_Labirint_2";
	Locations[n].reload.l4.emerge = "reload18";
	Locations[n].reload.l4.autoreload = "1";
      
	Locations[n].reload.l5.name = "reload20";
	Locations[n].reload.l5.go = "Quest_Hispaniola_Labirint_2";
	Locations[n].reload.l5.emerge = "Reload19";
	Locations[n].reload.l5.autoreload = "1";

	Locations[n].reload.l6.name = "reload22";
	Locations[n].reload.l6.go = "Quest_Hispaniola_Labirint_2";
	Locations[n].reload.l6.emerge = "reload21";
	Locations[n].reload.l6.autoreload = "1";
      
    	Locations[n].reload.l7.name = "reload23";
	Locations[n].reload.l7.go = "Quest_Hispaniola_Labirint_2";
	Locations[n].reload.l7.emerge = "Reload24";
	Locations[n].reload.l7.autoreload = "1"; */

	Locations[n].reload.l8.name = "reload26";
	Locations[n].reload.l8.go = "Quest_Hispaniola_Labirint_2";
	Locations[n].reload.l8.emerge = "reload25";
	Locations[n].reload.l8.autoreload = "1";

	Locations[n].reload.l28.name = "reload26_back";
	Locations[n].reload.l28.go = "Quest_Hispaniola_Labirint_2";
	Locations[n].reload.l28.emerge = "reload25";
	Locations[n].reload.l28.autoreload = "1";

   	Locations[n].reload.l9.name = "reload1";
	Locations[n].reload.l9.go = "Quest_Hispaniola_Labirint_3";
	Locations[n].reload.l9.emerge = "Reload2";
	Locations[n].reload.l9.autoreload = "1";

	Locations[n].reload.l29.name = "reload1_back";
	Locations[n].reload.l29.go = "Quest_Hispaniola_Labirint_3";
	Locations[n].reload.l29.emerge = "Reload2";
	Locations[n].reload.l29.autoreload = "1";

	Locations[n].reload.l10.name = "reload6";
	Locations[n].reload.l10.go = "Quest_Hispaniola_Labirint_3";
	Locations[n].reload.l10.emerge = "reload5";
	Locations[n].reload.l10.autoreload = "1";

	Locations[n].reload.l20.name = "reload6_back";
	Locations[n].reload.l20.go = "Quest_Hispaniola_Labirint_3";
	Locations[n].reload.l20.emerge = "reload5";
	Locations[n].reload.l20.autoreload = "1";
      
	Locations[n].reload.l11.name = "reload7";
	Locations[n].reload.l11.go = "Quest_Hispaniola_Labirint_3";
	Locations[n].reload.l11.emerge = "Reload8";
	Locations[n].reload.l11.autoreload = "1";

	Locations[n].reload.l21.name = "reload7_back";
	Locations[n].reload.l21.go = "Quest_Hispaniola_Labirint_3";
	Locations[n].reload.l21.emerge = "Reload8";
	Locations[n].reload.l21.autoreload = "1";

	Locations[n].reload.l12.name = "reload9";
	Locations[n].reload.l12.go = "Quest_Hispaniola_Labirint_3";
	Locations[n].reload.l12.emerge = "reload10";
	Locations[n].reload.l12.autoreload = "1";

	Locations[n].reload.l22.name = "reload9_back";
	Locations[n].reload.l22.go = "Quest_Hispaniola_Labirint_3";
	Locations[n].reload.l22.emerge = "reload10";
	Locations[n].reload.l22.autoreload = "1";

	Locations[n].island = "Hispaniola"; // GR 09-02-2016
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Quest_Hispaniola_Labirint_2";
	Locations[n].filespath.models = "locations\Incas Temple\Labirint";
	//Sound
		Locations[n].image = "Incas_Temple_Labirint.tga";
	locations[n].type = "inca_temple";
	locations[n].id.label = "Maze";
	//Models
	//Always
	Locations[n].models.always.locators = "lab2_l";
	Locations[n].models.always.l1 = "lab2";
	//Day
	Locations[n].models.day.charactersPatch = "lab2_p";
	//Night
	Locations[n].models.night.charactersPatch = "lab2_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].lockWeather = "Alcove";
	
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 0, 24);

	//Reload map

	Locations[n].reload.l2.name = "reload3";
	Locations[n].reload.l2.go = "Quest_Hispaniola_Labirint_1";
	Locations[n].reload.l2.emerge = "reload4";
	Locations[n].reload.l2.autoreload = "1";

	Locations[n].reload.l22.name = "reload3_back";
	Locations[n].reload.l22.go = "Quest_Hispaniola_Labirint_1";
	Locations[n].reload.l22.emerge = "reload4";
	Locations[n].reload.l22.autoreload = "1";
      
	Locations[n].reload.l3.name = "reload12";
	Locations[n].reload.l3.go = "Quest_Hispaniola_Labirint_1";
	Locations[n].reload.l3.emerge = "Reload11";
	Locations[n].reload.l3.autoreload = "1";

	Locations[n].reload.l23.name = "reload12_back";
	Locations[n].reload.l23.go = "Quest_Hispaniola_Labirint_1";
	Locations[n].reload.l23.emerge = "Reload11";
	Locations[n].reload.l23.autoreload = "1";

/*	Locations[n].reload.l4.name = "reload18"; // commented out section starts here
	Locations[n].reload.l4.go = "Quest_Hispaniola_Labirint_1";
	Locations[n].reload.l4.emerge = "reload17";
	Locations[n].reload.l4.autoreload = "1";
      
	Locations[n].reload.l5.name = "reload19";
	Locations[n].reload.l5.go = "Quest_Hispaniola_Labirint_1";
	Locations[n].reload.l5.emerge = "Reload20";
	Locations[n].reload.l5.autoreload = "1";

	Locations[n].reload.l6.name = "reload21";
	Locations[n].reload.l6.go = "Quest_Hispaniola_Labirint_1";
	Locations[n].reload.l6.emerge = "reload22";
	Locations[n].reload.l6.autoreload = "1";
      
	Locations[n].reload.l7.name = "reload24";
	Locations[n].reload.l7.go = "Quest_Hispaniola_Labirint_1";
	Locations[n].reload.l7.emerge = "Reload23";
	Locations[n].reload.l7.autoreload = "1"; */

	Locations[n].reload.l8.name = "reload25";
	Locations[n].reload.l8.go = "Quest_Hispaniola_Labirint_1";
	Locations[n].reload.l8.emerge = "reload26";
	Locations[n].reload.l8.autoreload = "1";

	Locations[n].reload.l28.name = "reload25_back";
	Locations[n].reload.l28.go = "Quest_Hispaniola_Labirint_1";
	Locations[n].reload.l28.emerge = "reload26";
	Locations[n].reload.l28.autoreload = "1";

	Locations[n].reload.l9.name = "reload14";
	Locations[n].reload.l9.go = "Quest_Hispaniola_Labirint_3";
	Locations[n].reload.l9.emerge = "Reload13";
	Locations[n].reload.l9.autoreload = "1";

	Locations[n].reload.l29.name = "reload14_back";
	Locations[n].reload.l29.go = "Quest_Hispaniola_Labirint_3";
	Locations[n].reload.l29.emerge = "Reload13";
	Locations[n].reload.l29.autoreload = "1";

	Locations[n].reload.l10.name = "reload16";
	Locations[n].reload.l10.go = "Quest_Hispaniola_Labirint_3";
	Locations[n].reload.l10.emerge = "reload15";
	Locations[n].reload.l10.autoreload = "1";

	Locations[n].reload.l20.name = "reload16_back";
	Locations[n].reload.l20.go = "Quest_Hispaniola_Labirint_3";
	Locations[n].reload.l20.emerge = "reload15";
	Locations[n].reload.l20.autoreload = "1";

	Locations[n].island = "Hispaniola"; // GR 09-02-2016
	n = n + 1;
	
	// -------------------------------------------------
	Locations[n].id = "Quest_Hispaniola_Labirint_3";
	Locations[n].filespath.models = "locations\Incas Temple\Labirint";
	//Sound
		Locations[n].image = "Incas_Temple_Labirint.tga";
	locations[n].type = "inca_temple";
	locations[n].id.label = "Maze";
	//Models
	//Always
	Locations[n].models.always.locators = "lab3_l";
	Locations[n].models.always.l1 = "lab3";

	//Day
	Locations[n].models.day.charactersPatch = "lab3_p";
	//Night
	Locations[n].models.night.charactersPatch = "lab3_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].lockWeather = "Alcove";

	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 0, 24);

	//Reload map
	Locations[n].reload.l2.name = "reload13";
	Locations[n].reload.l2.go = "Quest_Hispaniola_Labirint_2";
	Locations[n].reload.l2.emerge = "reload14";
	Locations[n].reload.l2.autoreload = "1";

	Locations[n].reload.l22.name = "reload13_back";
	Locations[n].reload.l22.go = "Quest_Hispaniola_Labirint_2";
	Locations[n].reload.l22.emerge = "reload14";
	Locations[n].reload.l22.autoreload = "1";

	Locations[n].reload.l3.name = "reload15";
	Locations[n].reload.l3.go = "Quest_Hispaniola_Labirint_2";
	Locations[n].reload.l3.emerge = "Reload16";
	Locations[n].reload.l3.autoreload = "1";

	Locations[n].reload.l23.name = "reload15_back";
	Locations[n].reload.l23.go = "Quest_Hispaniola_Labirint_2";
	Locations[n].reload.l23.emerge = "Reload16";
	Locations[n].reload.l23.autoreload = "1";

	Locations[n].reload.l4.name = "reload2";
	Locations[n].reload.l4.go = "Quest_Hispaniola_Labirint_1";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";

	Locations[n].reload.l24.name = "reload2_back";
	Locations[n].reload.l24.go = "Quest_Hispaniola_Labirint_1";
	Locations[n].reload.l24.emerge = "reload1";
	Locations[n].reload.l24.autoreload = "1";
      
	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "Quest_Hispaniola_Labirint_1";
	Locations[n].reload.l5.emerge = "Reload6";
	Locations[n].reload.l5.autoreload = "1";

	Locations[n].reload.l25.name = "reload5_back";
	Locations[n].reload.l25.go = "Quest_Hispaniola_Labirint_1";
	Locations[n].reload.l25.emerge = "Reload6";
	Locations[n].reload.l25.autoreload = "1";

	Locations[n].reload.l6.name = "reload8";
	Locations[n].reload.l6.go = "Quest_Hispaniola_Labirint_1";
	Locations[n].reload.l6.emerge = "reload7";
	Locations[n].reload.l6.autoreload = "1";

	Locations[n].reload.l26.name = "reload8_back";
	Locations[n].reload.l26.go = "Quest_Hispaniola_Labirint_1";
	Locations[n].reload.l26.emerge = "reload7";
	Locations[n].reload.l26.autoreload = "1";
      
	Locations[n].reload.l7.name = "reload10";
	Locations[n].reload.l7.go = "Quest_Hispaniola_Labirint_1";
	Locations[n].reload.l7.emerge = "Reload9";
	Locations[n].reload.l7.autoreload = "1";

	Locations[n].reload.l27.name = "reload10_back";
	Locations[n].reload.l27.go = "Quest_Hispaniola_Labirint_1";
	Locations[n].reload.l27.emerge = "Reload9";
	Locations[n].reload.l27.autoreload = "1";

/*	Locations[n].reload.l28.name = "reload30_back";
	Locations[n].reload.l28.go = "Treasure_Alcove";
	Locations[n].reload.l28.emerge = "Reload1";
	Locations[n].reload.l28.autoreload = "1"; */

	Locations[n].locators_radius.randitem.randitem1 = 0.5;
	Locations[n].items.randitem1 = "TainoRug";

	Locations[n].island = "Hispaniola"; // GR 09-02-2016
	n = n + 1;

	//-------------------------------------------------
	Locations[n].id = "Quest_Santiago_Bedroom";
	locations[n].id.label = "Bedroom";
	Locations[n].filespath.models = "locations\inside\ResBedRoom";
	Locations[n].image = "Inside_ResBedRoom.tga";

	//Town sack
	Locations[n].townsack = "Santiago";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Santiago";			//add to enable quickteleport
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
	Locations[n].reload.l1.go = "Santiago_townhall";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Residence.";
	Locations[n].reload.l1.disable = 1;
	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].vcskip = true;

	Locations[n].island = "Cuba"; // GR 25-02-2016
	n = n + 1;

 	//-------------------------------------------------
	Locations[n].id = "Quest_Merchant_House";
	locations[n].id.label = "House of Gilbert Downing";
	Locations[n].filespath.models = "locations\inside\Residence_BackHall";
	Locations[n].image = "Downing_House.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Port au Prince";
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
	Locations[n].models.back = "back\redrsb_"; // View out of windows is wrong but file is dictated by "type" and "models" lines
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Redmond_town_03";
	Locations[n].reload.l1.emerge = "Door_14";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Center.";
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Redmond"; // GR 17-03-2016
	n = n + 1;

 	//-------------------------------------------------
	Locations[n].id = "Quest_Cellar_Prison";
	locations[n].id.label = "Old Inquisition prison";
	Locations[n].filespath.models = "locations\inside\prison";
	Locations[n].image = "Inside_Prison.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

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
	Locations[n].reload.l1.go = "Quest_Merchant_House";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.label = "Way out.";
//	locations[n].reload.l1.disable = 1;

	locations[n].reload.l2.name = "reload10";
	locations[n].reload.l2.go = "Redmond_dungeon_2";
	locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.label = "Hidden passage.";
//	locations[n].reload.l2.disable = 1;
//	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].vcskip = true;


	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

// Port au Prince townhall archive -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\apothecary";	

	Locations[n].id = "PoPrince_archive";
	locations[n].id.label = "???";
	Locations[n].image = "Inside_PaP_Archives.tga"; // KK
	//Town sack
	Locations[n].townsack = "Port au Prince"; 
	//Sound
	locations[n].type = "residence"; 
	locations[n].fastreload = "Port au Prince";
	//Models
	//Always
	Locations[n].models.always.locators = "resp_l";
	Locations[n].models.always.l1 = "ResP2";
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
	Locations[n].reload.l1.go = "PoPrince_Town";
	Locations[n].reload.l1.emerge = "reload20";
	Locations[n].reload.l1.autoreload = "0";
	locations[n].id.label = "#stown_name#.";

	Locations[n].island = "Hispaniola";

	n = n + 1;

	//Port Royale fort
	Locations[n].id = "Quest_Fort";
	locations[n].id.label = "Fort inside";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_1";
	Locations[n].image = "Fort_Inside_Fort_1.tga";
	//Sound
	locations[n].type = "deck";
	//Models
	//Always
	Locations[n].models.always.locators = "fort1_l_GR";
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

	Locations[n].island = "Redmond";
	Locations[n].townsack = "Redmond";
	n = n + 1;

}