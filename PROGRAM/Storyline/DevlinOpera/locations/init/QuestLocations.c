void LocationInitQuestLocations(ref n)
{
	// ------------------------------------------------- BEATRICE SHIP DECK

	Locations[n].id = "Family_deck";
	locations[n].id.label = "Ship deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deckBig";	
	Locations[n].image = "Sea";

	Locations[n].id = "Family_deck";
	locations[n].id.label = "Ship deck";

    // Swindler added type to avoid bug connected to LoginCharactersInLocation() function
    locations[n].type = "deck";

	//Always
	Locations[n].models.always.locators = "deckBig_ld_x";
	Locations[n].models.always.l1 = "deckBig";
	//Day
	Locations[n].models.day.charactersPatch = "deckBig_p";
	Locations[n].models.day.fonar = "deckBig_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deckBig_p";
	Locations[n].models.night.fonar = "deckBig_fn";
	Locations[n].lockCamAngle = 0.4;
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l5.name = "boatr";
	Locations[n].reload.l5.go = "";
	Locations[n].reload.l5.emerge = "";
	Locations[n].reload.l5.autoreload = "0";

	n = n + 1;

	//---------------------------------------------  BLAZE SHIP DECK

	//ID
	Locations[n].id = "Merchant_deck";
	locations[n].id.label = "Ship deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deckLow";
	Locations[n].image = "Sea";
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

	//---------------------------------------------  BLAZE CABIN

	//ID
	Locations[n].id = "Merchant_cabin";
	locations[n].id.label = "Crew's quarters";
	//Info
	Locations[n].filespath.models = "locations\decks\seadogs"; // KK
	Locations[n].image = "deck_seadogs"; // KK
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
	// Door near table

	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Guadeloupe";
	Locations[n].reload.l1.emerge = "reload_1";
	Locations[n].reload.l1.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l1.label = "Ship.";
	else
		Locations[n].reload.l1.label = "Sea.";
	Locations[n].locators_radius.reload.sea = 3;
// <-- KK

	Locations[n].vcskip = true;

	n = n + 1;


//----------------------------------------   GENERAL STORE SANTO DOMINGO


	locations[n].id = "lorena_shop";
//	locations[n].id.label = "General Store";				//label when opened
	Locations[n].image = "Inside_LargeStore.tga";

	//Town sack
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Santo_Domingo";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\sklad03";
	locations[n].models.always.locators = "sklad03_locators_JRH";
	locations[n].models.always.l1 = "sklad03";

	//Day
	locations[n].models.day.charactersPatch = "sklad03_patch";
	//Night
	locations[n].models.night.charactersPatch = "sklad03_patch";
	//Environment
	locations[n].environment.weather = "false";
	locations[n].environment.sea = "false";

	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Santo_Domingo_town";
	locations[n].reload.l1.emerge = "reload10";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "#stown_name#.";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Hispaniola";
	n = n + 1;

//--------------------------------------------   ADDITIONAL JUNGLE HISPANIOLA

	Locations[n].filespath.models = "locations\Outside\Jungle_4";

	Locations[n].id = "Hispaniola_Jungle_Devlin";
	locations[n].id.label = "Jungle";
	Locations[n].image = "Outside_Jungle_4.tga";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Town sack
	Locations[n].townsack = "Santo Domingo";

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
	Locations[n].reload.l1.go = "Hispaniola_Jungle_08";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1 = 4;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Hispaniola_Jungle_08";
	Locations[n].reload.l4.emerge = "reload3";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].reload.l2.name = "reload3";
	Locations[n].reload.l2.go = "Hispaniola_village_exit";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 4;

	Locations[n].reload.l5.name = "reload3_back";
	Locations[n].reload.l5.go = "Hispaniola_village_exit";
	Locations[n].reload.l5.emerge = "reload3";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Devlin_tavern_outside";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3 = 4;

	Locations[n].reload.l6.name = "reload2_back";
	Locations[n].reload.l6.go = "Devlin_tavern_outside";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 3;

	Locations[n].island = "Hispaniola"; // NK 04-08-29
	Locations[n].vcskip = true;
	n = n + 1;


	// -------------------------------------------------  ENTRANCE TO PUZZLE TAVERN

	Locations[n].filespath.models = "locations\Outside\Pirate_Outer_Location";

	Locations[n].id = "Devlin_tavern_outside";
	locations[n].id.label = "Entrance to strange house";
	Locations[n].image = "Outside_Pirate_Outer_location.tga";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "Pirl_l";
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
	Locations[n].reload.l1.go = "Hispaniola_Jungle_Devlin";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Hispaniola_Jungle_Devlin";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 3.0;
	Locations[n].reload.l3.label = "Jungle.";


	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Puzzle_tavern";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Tavern.";


	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	Locations[n].vcskip = true;
	n = n + 1;


//-------------------------------------------------------------- PUZZLE TAVERN


	Locations[n].id = "Puzzle_tavern";
	locations[n].id.label = "Tavern";
	Locations[n].filespath.models = "locations\inside\Largetavern";
	Locations[n].image = "Inside_LargeTavern.tga";

	//Town sack
	Locations[n].townsack = "Santo Domingo";

	//Sound
	locations[n].type = "yohoho_tavern";
	//locations[n].fastreload = "Santo_Domingo";
	//Models
	//Always
	Locations[n].models.always.tavern = "LT";
	Locations[n].models.always.locators = "LT_l_BTP";
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
	Locations[n].reload.l1.go = "Devlin_tavern_outside";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Jungle.";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "hispaniola"; // NK 04-08-29
	Locations[n].vcskip = true;
	n = n + 1;

//-------------------------------------------------------------- BONAMY CARGO HOLD
	//ID
	Locations[n].id = "Devlin_Hold1";
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


}
