void LocationInitQuestLocations(ref n)
{

	// ----------------------------------------------
	Locations[n].filespath.models = "locations\Decks\qdeck";
	Locations[n].image = "sea.tga";

	Locations[n].id = "smuggler_ship";
	locations[n].id.label = "Smuggler ship";

    // Swindler added type to avoid bug connected to LoginCharactersInLocation() function
    locations[n].type = "deck";

	//Sound
	Locations[n].models.always.locators = "qdeck_ld";
	Locations[n].models.always.l1 = "qdeck";
	//Day
	Locations[n].models.day.charactersPatch = "qdeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "qdeck_p";
	Locations[n].lockCamAngle = 0.4;
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	// Captain's cabin
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";
	// Crew quarters
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Smuggler_Quarter";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";

	n = n + 1;

	// ----------------------------------------------
	Locations[n].id = "Smuggler_Quarter";
	locations[n].id.label = "Crew's quarters";
	//Info
	Locations[n].filespath.models = "locations\decks\seadogs"; // KK
	Locations[n].image = "deck_seadogs.tga"; // KK
	//Sound
	Locations[n].type = "deck";
//	Locations[n].lockCamAngle = 0.4;	// LDH removed 23Mar09
	Locations[n].camshuttle = 1;

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
// KK -->
	//Reload map
	// Corridor
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "smuggler_ship";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	// Door near table
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Smuggler_Cabin";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
// <-- KK
	n = n + 1;

	// ----------------------------------------------
	Locations[n].id = "Smuggler_Cabin";
	locations[n].id.label = "Captain's cabin";
	//Info
	Locations[n].filespath.models = "locations\decks\cabin\capsm"; // KK
	Locations[n].image = "deck_capsm.tga"; // KK
	//Sound
	Locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;
	Locations[n].camshuttle = 1;

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

// KK -->
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Smuggler_Quarter";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
// <-- KK

	n = n + 1;
	
	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\mh3";
	Locations[n].id = "Tortuga_Pirate_House";
	locations[n].id.label = "House";
	Locations[n].image = "Inside_mh3.tga";
	//Sound
	locations[n].type = "house";
	//Models
	//Always
	Locations[n].models.always.locators = "MH3_l";
	Locations[n].models.always.house = "MH3";
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
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";
	
	Locations[n].vcskip = true; // KK
	
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\MediumHouse2";

	Locations[n].id = "Laura_Cotton_House";
	locations[n].id.label = "House";
	Locations[n].image = "Inside_MediumHouse2.tga";

	//Sound
	locations[n].type = "house";

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
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Town.";

    Locations[n].vcskip = true; // KK

	n = n + 1;

	// -------------------------------------------------
	//ID
	Locations[n].id = "Quest_ShipDeck6";
	locations[n].id.label = "Ship deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deckBig";
	Locations[n].image = "Sea.tga";
	//Sound
	locations[n].type = "ship";
	Locations[n].lockCamAngle = 0.4;
	Locations[n].camshuttle = 1;
	Locations[n].fastreload = "ship";
	Locations[n].monsters = 0;
	Locations[n].vcskip = true;		

	//Models
	//Always
	Locations[n].models.always.locators = "quest_deckBig_ld"; // KK
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
	// Cargo hold
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Quest_Deck1";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
// <-- KK

	n = n + 1;

	// -------------------------------------------------
	
// KK -->
	//ID
	Locations[n].id = "Quest_Deck1";
	locations[n].id.label = "Main cannons deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deck2";
	Locations[n].image = "deck_deck2.tga";
	//Sound
	Locations[n].type = "ship";
	Locations[n].camshuttle = 1;
	Locations[n].fastreload = "ship";
	Locations[n].monsters = 0;

	//Models
	//Always
	Locations[n].models.always.locators = "deck2_ld";
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
	Locations[n].environment.curse = "false"; // PB: Cursed Coins

	//Reload map
	// stair
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Quest_ShipDeck6";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	// bakbort door
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Quest_Deck2";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].locators_radius.box.gunpowder_1 = 0.5;

	n = n + 1;
	// -------------------------------------------------
	//ID
	Locations[n].id = "Quest_Deck2";
	locations[n].id.label = "Lower cannons deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deck1";
	Locations[n].image = "deck_deck1.tga";
	//Sound
	Locations[n].type = "ship";
	Locations[n].camshuttle = 1;
	Locations[n].fastreload = "ship";
	Locations[n].monsters = 0;

	//Models
	//Always
	Locations[n].models.always.locators = "deck1_ld";
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
	Locations[n].environment.curse = "false"; // PB: Cursed Coins

	//Reload map
	// bakbort stair
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Quest_Deck1";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "0";
	// bakbort door
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Quest_Hold1";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].locators_radius.box.gunpowder_1 = 0.5;

	n = n + 1;
	// -------------------------------------------------	
	//ID
	Locations[n].id = "Quest_Hold1";
	locations[n].id.label = "Cargo hold";
	//Info
	Locations[n].filespath.models = "locations\decks\hold";
	Locations[n].image = "deck_hold.tga"; // KK
	//Sound
	Locations[n].type = "ship";
	Locations[n].camshuttle = 1;
	Locations[n].fastreload = "ship";
	Locations[n].monsters = 0; // KK

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

// KK -->
	// Reload Map
	// stair
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Quest_Deck2";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
// <-- KK

	n = n + 1;	
	}
