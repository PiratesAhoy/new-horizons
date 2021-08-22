void LocationInitShip(ref n)
{
	// -------------------------------------------------
	
// KK -->
	//ID
	Locations[n].id = "Deck1";
	locations[n].id.label = "Main cannons deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deck2";
	Locations[n].image = "deck_deck2.tga";
	//Sound
	Locations[n].type = "ship";
	Locations[n].camshuttle = 1;
	Locations[n].fastreload = "ship";
	Locations[n].monsters = 1;

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
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";
	// door
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "";
	Locations[n].reload.l2.autoreload = "0";
	// bakbort door
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "";
	Locations[n].reload.l3.emerge = "";
	Locations[n].reload.l3.autoreload = "0";
	// starbort door
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "";
	Locations[n].reload.l4.emerge = "";
	Locations[n].reload.l4.autoreload = "0";

	Locations[n].locators_radius.box.gunpowder_1 = 0.5;

	n = n + 1;

	//ID
	Locations[n].id = "Deck2";
	locations[n].id.label = "Middle cannons deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deck1";
	Locations[n].image = "deck_deck1.tga";
	//Sound
	Locations[n].type = "ship";
	Locations[n].camshuttle = 1;
	Locations[n].fastreload = "ship";
	Locations[n].monsters = 1;

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
	// starbort stair
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";
	// bakbort stair
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "";
	Locations[n].reload.l2.autoreload = "0";
	// bakbort door
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "";
	Locations[n].reload.l3.emerge = "";
	Locations[n].reload.l3.autoreload = "0";
	// starbort door
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "";
	Locations[n].reload.l4.emerge = "";
	Locations[n].reload.l4.autoreload = "0";

	Locations[n].locators_radius.box.gunpowder_1 = 0.5;

	n = n + 1;

	//ID
	Locations[n].id = "Deck3";
	locations[n].id.label = "Lower cannons deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deck1";
	Locations[n].image = "deck_deck1.tga";
	//Sound
	Locations[n].type = "ship";
	Locations[n].camshuttle = 1;
	Locations[n].fastreload = "ship";
	Locations[n].monsters = 1;

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
	// starbort stair
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";
	// bakbort stair
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "";
	Locations[n].reload.l2.autoreload = "0";
	// bakbort door
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "";
	Locations[n].reload.l3.emerge = "";
	Locations[n].reload.l3.autoreload = "0";
	// starbort door
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "";
	Locations[n].reload.l4.emerge = "";
	Locations[n].reload.l4.autoreload = "0";

	Locations[n].locators_radius.box.gunpowder_1 = 0.5;

	n = n + 1;
// <-- KK

	//ID
	Locations[n].id = "Hold1";
	locations[n].id.label = "Cargo hold";
	//Info
	Locations[n].filespath.models = "locations\decks\hold";
	Locations[n].image = "deck_hold.tga"; // KK
	//Sound
	Locations[n].type = "ship";
	Locations[n].camshuttle = 1;
	Locations[n].fastreload = "ship";
	Locations[n].monsters = 1; // KK

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
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";
	// door
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "";
	Locations[n].reload.l2.autoreload = "0";
// <-- KK

	n = n + 1;

// KK -->
	//ID
	Locations[n].id = "Hold2";
	locations[n].id.label = "Cargo hold";
	//Info
	Locations[n].filespath.models = "locations\decks\hold";
	Locations[n].image = "deck_hold.tga"; // KK
	//Sound
	Locations[n].type = "ship";
	Locations[n].camshuttle = 1;
	Locations[n].fastreload = "ship";
	Locations[n].monsters = 1; // KK

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
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";
	// door
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "";
	Locations[n].reload.l2.autoreload = "0";
// <-- KK

	n = n + 1;

	//ID
	Locations[n].id = "ShipDeck1";
	locations[n].id.label = "Ship deck";
	//Info
	Locations[n].filespath.models = "locations\Decks\qdeck";
	Locations[n].image = "Sea.tga"; // KK
	//Sound
	locations[n].type = "own_deck";
	Locations[n].lockCamAngle = 0.4;
	Locations[n].camshuttle = 1;
	Locations[n].fastreload = "ship";
	Locations[n].monsters = 1;
	//Models
	//Always
	Locations[n].models.always.locators = "qdeck_ld";
	Locations[n].models.always.l1 = "qdeck";
	//Day
	Locations[n].models.day.charactersPatch = "qdeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "qdeck_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.8; // screwface
	//Reload map
	// Captain's cabin
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";
	// Crew quarters
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "";
	Locations[n].reload.l2.autoreload = "0";
	// Gun decks/cargo hold
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
	// Sea
	Locations[n].reload.l6.name = "sea";
	Locations[n].reload.l6.go = "Sea";
	Locations[n].reload.l6.emerge = "";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Sea.";

	n = n + 1;

	//ID
	Locations[n].id = "ShipDeck2";
	locations[n].id.label = "Ship deck";
	//Info
	Locations[n].filespath.models = "locations\decks\udeck1";
	Locations[n].image = "Sea.tga";
	//Sound
	locations[n].type = "own_deck";
	Locations[n].lockCamAngle = 0.4;
	Locations[n].camshuttle = 1;
	Locations[n].fastreload = "ship";
	Locations[n].monsters = 1;

	//Models
	//Always
	Locations[n].models.always.locators = "udeck_ld";
	Locations[n].models.always.l1 = "udeck";
	Locations[n].models.always.l2 = "udeck_f";
	//Day
	Locations[n].models.day.charactersPatch = "udeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "udeck_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.8; // screwface
	//Reload map
	// Captain's cabin on bakbort
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";
	// Crew Quarters
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "";
	Locations[n].reload.l2.autoreload = "0";
	// Gun decks/cargo hold
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
	// Sea
	Locations[n].reload.l6.name = "sea";
	Locations[n].reload.l6.go = "Sea";
	Locations[n].reload.l6.emerge = "";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Sea.";
	// Captain's cabin on starbort
	Locations[n].reload.l7.name = "reload4";
	Locations[n].reload.l7.go = "";
	Locations[n].reload.l7.emerge = "";
	Locations[n].reload.l7.autoreload = "0";

	n = n + 1;

	//ID
	Locations[n].id = "ShipDeck3";
	locations[n].id.label = "Ship deck";
	//Info
	Locations[n].filespath.models = "locations\decks\udeck2";
	Locations[n].image = "Sea.tga"; // KK
	//Sound
	locations[n].type = "own_deck";
	Locations[n].lockCamAngle = 0.4;
	Locations[n].camshuttle = 1;
	Locations[n].fastreload = "ship";
	Locations[n].monsters = 1;

	//Models
	//Always
	Locations[n].models.always.locators = "udeck_ld";
	Locations[n].models.always.l1 = "udeck";
	Locations[n].models.always.l2 = "udeck_f";
	//Day
	Locations[n].models.day.charactersPatch = "udeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "udeck_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.8; // screwface
	//Reload map
	// Captain's cabin
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";
	// Crew quarters
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "";
	Locations[n].reload.l2.autoreload = "0";
	// Nothing
	Locations[n].reload.l3.name = "";
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
	// Sea
	Locations[n].reload.l6.name = "sea";
	Locations[n].reload.l6.go = "Sea";
	Locations[n].reload.l6.emerge = "";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Sea.";

	n = n + 1;
// <-- KK

//MAXIMUS -->
	//ID
	Locations[n].id = "ShipDeck4";
	locations[n].id.label = "Ship deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deckLow";
	Locations[n].image = "Sea.tga";
	//Sound
	locations[n].type = "own_deck";
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
	Locations[n].MaxSeaHeight = 0.4; // JRH
	//============| Reload map |============//
	// Captain's cabin
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";
	// Crew quarters
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
// <-- KK

	n = n + 1;

	//ID
	Locations[n].id = "ShipDeck5";
	locations[n].id.label = "Ship deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deckMedium";
	Locations[n].image = "Sea.tga";
	//Sound
	locations[n].type = "own_deck";
	Locations[n].lockCamAngle = 0.4;
	Locations[n].camshuttle = 1;
	Locations[n].fastreload = "ship";
	Locations[n].monsters = 1;

	//Models
	//Always
	Locations[n].models.always.locators = "deckMedium_ld"; // KK
	Locations[n].models.always.l1 = "deckMedium";
	//Day
	Locations[n].models.day.charactersPatch = "deckMedium_p";
	Locations[n].models.day.fonar = "deckMedium_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deckMedium_p";
	Locations[n].models.night.fonar = "deckMedium_fn";
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
	// Crew quarters
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "";
	Locations[n].reload.l2.autoreload = "0";
	// Nothing
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
// <-- KK
	
	n = n + 1;

	//ID
	Locations[n].id = "ShipDeck6";
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
//MAXIMUS <--

	//ID
	Locations[n].id = "ShipDeck7";
	locations[n].id.label = "Ship deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deckBP";
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

	//ID
	Locations[n].id = "Seadogs";
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
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";
	// Door near table
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "";
	Locations[n].reload.l2.autoreload = "0";
// <-- KK

	n = n + 1;

	//ID
	Locations[n].id = "Cabin_small";
	locations[n].id.label = "Captain's cabin";
	//Info
	Locations[n].filespath.models = "locations\decks\cabin\capsm"; // KK
	Locations[n].image = "deck_capsm.tga"; // KK
	//Sound
	Locations[n].type = "own_deck";
	Locations[n].lockCamAngle = 0.4;
	Locations[n].camshuttle = 1;
	Locations[n].fastreload = "ship";
	Locations[n].monsters = 0; // KK

	//Models
	//Always
	Locations[n].models.always.locators = "capsm_ld"; // KK
	Locations[n].models.always.l1 = "capsm";
	Locations[n].models.always.l2 = "cabinchest";
	Locations[n].models.always.l3 = "trunk";			//fake - not visible
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
	Locations[n].environment.curse = "false"; // PB: Cursed Coins

// KK -->
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";
// <-- KK

	n = n + 1;

	//ID
	Locations[n].id = "Cabin_medium";
	locations[n].id.label = "Captain's cabin";
	//Info
	Locations[n].filespath.models = "locations\decks\cabin\capmd"; // KK
	Locations[n].image = "deck_capmd.tga"; // KK
	//Sound
	Locations[n].type = "own_deck";
	Locations[n].lockCamAngle = 0.4;
	Locations[n].camshuttle = 1;
	Locations[n].fastreload = "ship";
	Locations[n].monsters = 0; // KK

	//Models
	//Always
	Locations[n].models.always.locators = "capmd_ld"; // KK
	Locations[n].models.always.l1 = "capmd";
	Locations[n].models.always.l2 = "cabinchest";
	Locations[n].models.always.l3 = "trunk";			//fake - not visible
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
	Locations[n].environment.curse = "false"; // PB: Cursed Coins

// KK -->
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";
// <-- KK

	n = n + 1;

	Locations[n].id = "Tutorial_Deck";
	Locations[n].id.label = "Captain's Cabin"; // KK
	Locations[n].filespath.models = "locations\DECKS\cabin\tut_deck"; // KK
	Locations[n].image = "battle.tga";
	//Sound
	locations[n].type = "own_deck";
	locations[n].fastreload = "ship"; // KK
	locations[n].randitemsstay = true; // NK 05-03-25 so randitems don't become random here.
	//Models
	//Always
	Locations[n].models.always.locators = "tut_Deck_l";
	Locations[n].models.always.l1 = "tut_Deck";
	Locations[n].models.always.l2 = "cabinchest";			//JRH, 
	Locations[n].models.always.l3 = "trunk";			//were missinng
	Locations[n].models.always.window = "tut_deck_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;

	//Day
	Locations[n].models.day.charactersPatch = "tut_Deck_p";
	Locations[n].models.day.fonar = "tut_Deck_fd";

	//Night
	Locations[n].models.night.charactersPatch = "tut_Deck_p";
	Locations[n].models.night.fonar = "tut_Deck_fn";

	//Environment
	Locations[n].environment.sea = "true";
	Locations[n].environment.curse = "false"; // PB: Cursed Coins
	Locations[n].environment.weather = "true";
	//Locations[n].lockWeather = "Alcove";  //JA 14DEC06 having this weather locked means it revert to blue sky everytime you visit any cabin

	if (WEAPONSLOCKER) Locations[n].WeaponsLocker.disabled = false; // KK

//	Locations[n].models.back = "back\colf2_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "";
	Locations[n].reload.l1.label = "";

// added by MAXIMUS [choose character mod] --> // KK -->
//	Locations[n].reload.l2.name = "reloadc2";
//	Locations[n].reload.l2.go = "";
//	Locations[n].reload.l2.emerge = "";
//	Locations[n].reload.l2.autoreload = "";
//	Locations[n].reload.l2.label = "";
// added by MAXIMUS [choose character mod] <-- // <-- KK

	// ccc experimental door to gundeck
	// NK 05-04-06 fix l1 to l2 for this
	/* Commented out 05-06-27 for 12.2
	Locations[n].reload.l2.name = "reloadc2";
	Locations[n].reload.l2.go = "NEXT_SLOOP";
	Locations[n].reload.l2.emerge = "loc0";
	Locations[n].reload.l2.label = "Gundeck";*/

	Locations[n].locators_radius.randitem.randitem1 = 1;

	Locations[n].items.randitem1 = "blade1";

	n = n + 1;

// KK -->
	Locations[n].id = "Companion_Cabin_1";
	Locations[n].id.label = "Captain's Cabin";
	Locations[n].filespath.models = "locations\DECKS\cabin\tut_deck";
	Locations[n].image = "battle.tga";
	//Sound
	locations[n].type = "own_deck";
	locations[n].fastreload = "ship";
	locations[n].randitemsstay = true; // NK 05-03-25 so randitems don't become random here.
	//Models
	//Always
	Locations[n].models.always.locators = "tut_Deck_l";
	Locations[n].models.always.l1 = "tut_Deck";
	Locations[n].models.always.window = "tut_deck_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;

	//Day
	Locations[n].models.day.charactersPatch = "tut_Deck_p";
	Locations[n].models.day.fonar = "tut_Deck_fd";

	//Night
	Locations[n].models.night.charactersPatch = "tut_Deck_p";
	Locations[n].models.night.fonar = "tut_Deck_fn";

	//Environment
	Locations[n].environment.sea = "true";
	Locations[n].environment.curse = "false"; // PB: Cursed Coins
	Locations[n].environment.weather = "true";

	if (WEAPONSLOCKER) Locations[n].WeaponsLocker.disabled = false;

//	Locations[n].models.back = "back\colf2_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "";
	Locations[n].reload.l1.label = "";

	Locations[n].locators_radius.randitem.randitem1 = 1;

	Locations[n].items.randitem1 = "blade1";

	n = n + 1;

	Locations[n].id = "Companion_Cabin_2";
	Locations[n].id.label = "Captain's Cabin";
	Locations[n].filespath.models = "locations\DECKS\cabin\tut_deck";
	Locations[n].image = "battle.tga";
	//Sound
	locations[n].type = "own_deck";
	locations[n].fastreload = "ship";
	locations[n].randitemsstay = true; // NK 05-03-25 so randitems don't become random here.
	//Models
	//Always
	Locations[n].models.always.locators = "tut_Deck_l";
	Locations[n].models.always.l1 = "tut_Deck";
	Locations[n].models.always.window = "tut_deck_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;

	//Day
	Locations[n].models.day.charactersPatch = "tut_Deck_p";
	Locations[n].models.day.fonar = "tut_Deck_fd";

	//Night
	Locations[n].models.night.charactersPatch = "tut_Deck_p";
	Locations[n].models.night.fonar = "tut_Deck_fn";

	//Environment
	Locations[n].environment.sea = "true";
	Locations[n].environment.curse = "false"; // PB: Cursed Coins
	Locations[n].environment.weather = "true";

	if (WEAPONSLOCKER) Locations[n].WeaponsLocker.disabled = false;

//	Locations[n].models.back = "back\colf2_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "";
	Locations[n].reload.l1.label = "";

	Locations[n].locators_radius.randitem.randitem1 = 1;

	Locations[n].items.randitem1 = "blade1";

	n = n + 1;

	Locations[n].id = "Companion_Cabin_3";
	Locations[n].id.label = "Captain's Cabin";
	Locations[n].filespath.models = "locations\DECKS\cabin\tut_deck";
	Locations[n].image = "battle.tga";
	//Sound
	locations[n].type = "own_deck";
	locations[n].fastreload = "ship";
	locations[n].randitemsstay = true; // NK 05-03-25 so randitems don't become random here.
	//Models
	//Always
	Locations[n].models.always.locators = "tut_Deck_l";
	Locations[n].models.always.l1 = "tut_Deck";
	Locations[n].models.always.window = "tut_deck_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;

	//Day
	Locations[n].models.day.charactersPatch = "tut_Deck_p";
	Locations[n].models.day.fonar = "tut_Deck_fd";

	//Night
	Locations[n].models.night.charactersPatch = "tut_Deck_p";
	Locations[n].models.night.fonar = "tut_Deck_fn";

	//Environment
	Locations[n].environment.sea = "true";
	Locations[n].environment.curse = "false"; // PB: Cursed Coins
	Locations[n].environment.weather = "true";

	if (WEAPONSLOCKER) Locations[n].WeaponsLocker.disabled = false;

//	Locations[n].models.back = "back\colf2_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "";
	Locations[n].reload.l1.label = "";

	Locations[n].locators_radius.randitem.randitem1 = 1;

	Locations[n].items.randitem1 = "blade1";

	n = n + 1;
// <-- KK

	//ID
	Locations[n].id = "Cabin1"; // KK
	locations[n].id.label = "Captain's cabin";
	//Info
	Locations[n].filespath.models = "locations\decks\cabin\cap"; // KK
	Locations[n].image = "deck_cap.tga"; // KK
	//Sound
	Locations[n].type = "own_deck";
	Locations[n].lockCamAngle = 0.4;
	Locations[n].camshuttle = 1;
	Locations[n].fastreload = "ship";
	Locations[n].monsters = 0; // KK

	//Models
	//Always
	Locations[n].models.always.locators = "cap_ld"; // KK
	Locations[n].models.always.l1 = "cap";
	Locations[n].models.always.l2 = "cabinchest";			//fake - not visible
	Locations[n].models.always.l3 = "trunk";			//fake - not visible
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
	Locations[n].environment.curse = "false"; // PB: Cursed Coins

// KK -->
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";
// <-- KK

	n = n + 1;

	//ID
	Locations[n].id = "Cabin2"; // KK
	locations[n].id.label = "Captain's cabin";
	//Info
	Locations[n].filespath.models = "locations\decks\cabin\cabin01"; // KK
	Locations[n].image = "deck_cabin1.tga"; // KK
	//Sound
	Locations[n].type = "own_deck";
	Locations[n].lockCamAngle = 0.4;
	Locations[n].camshuttle = 1;
	Locations[n].fastreload = "ship";
	Locations[n].monsters = 0; // KK

	//Models
	//Always
	Locations[n].models.always.locators = "cabin01_ld"; // KK
	Locations[n].models.always.l1 = "cabin01";
	Locations[n].models.always.l2 = "cabinchest";			//fake - not visible
	Locations[n].models.always.l3 = "trunk";			//fake - not visible
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "cabin01_patch";
	Locations[n].models.day.fonar = "cabin01_fonar"; // KK
	//Night
	Locations[n].models.night.charactersPatch = "cabin01_patch";
	Locations[n].models.night.fonar = "cabin01_fonar"; // KK
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].environment.curse = "false"; // PB: Cursed Coins

// KK -->
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";
// <-- KK

	n = n + 1;

	//ID
	Locations[n].id = "Cabin2SJG"; // KK //SJG
	locations[n].id.label = "Captain's cabin";
	//Info
	Locations[n].filespath.models = "locations\decks\cabin\cabin01"; // KK
	Locations[n].image = "deck_cabin1.tga"; // KK
	//Sound
	Locations[n].type = "Silence"; //"own_deck";//SJG
	Locations[n].lockCamAngle = 0.4;
	Locations[n].camshuttle = 1;
	Locations[n].fastreload = "ship";
	Locations[n].monsters = 0; // KK

	//Models
	//Always
	Locations[n].models.always.locators = "cabin01_ld"; // KK
	Locations[n].models.always.l1 = "cabin01";
	Locations[n].models.always.l2 = "cabinchest";			//fake - not visible
	Locations[n].models.always.l3 = "trunk";			//fake - not visible
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "cabin01_patch";
	Locations[n].models.day.fonar = "cabin01_fonar"; // KK
	//Night
	Locations[n].models.night.charactersPatch = "cabin01_patch";
	Locations[n].models.night.fonar = "cabin01_fonar"; // KK
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].environment.curse = "false"; // PB: Cursed Coins

// KK -->
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";
// <-- KK

	n = n + 1;

	//ID
	Locations[n].id = "Cabin3"; // KK
	locations[n].id.label = "Captain's cabin";
	//Info
	Locations[n].filespath.models = "locations\decks\cabin\cabin02";
	Locations[n].image = "deck_cabin2.tga"; // KK
	//Sound
	Locations[n].type = "own_deck";
	Locations[n].lockCamAngle = 0.4;
	Locations[n].camshuttle = 1;
	Locations[n].fastreload = "ship";
	Locations[n].monsters = 0; // KK

	//Models
	//Always
	Locations[n].models.always.locators = "cabin02_ld"; // KK
	Locations[n].models.always.l1 = "cabin02";
	Locations[n].models.always.l2 = "cabinchest";			//fake - not visible
	Locations[n].models.always.l3 = "trunk";			//JRH
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "cabin02_patch";
	Locations[n].models.day.fonar = "cabin02_fonar"; // KK
	//Night
	Locations[n].models.night.charactersPatch = "cabin02_patch";
	Locations[n].models.night.fonar = "cabin02_fonar"; // KK
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].environment.curse = "false"; // PB: Cursed Coins

// KK -->
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";
// <-- KK

	n = n + 1;

	//ID
	Locations[n].id = "Cabin4"; // KK
	locations[n].id.label = "Captain's cabin";
	//Info
	Locations[n].filespath.models = "locations\decks\cabin\cabin03";
	Locations[n].image = "deck_cabin3.tga"; // KK
	//Sound
	Locations[n].type = "own_deck";
	Locations[n].lockCamAngle = 0.4;
	Locations[n].camshuttle = 1;
	Locations[n].fastreload = "ship";
	Locations[n].monsters = 0; // KK

	//Models
	//Always
	Locations[n].models.always.locators = "cabin03_ld"; // KK
	Locations[n].models.always.l1 = "cabin03";
	Locations[n].models.always.l2 = "cabinchest";			//fake - not visible
	Locations[n].models.always.l3 = "trunk";			//JRH
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "cabin03_patch";
	Locations[n].models.day.fonar = "cabin03_fonar"; // KK
	//Night
	Locations[n].models.night.charactersPatch = "cabin03_patch";
	Locations[n].models.night.fonar = "cabin03_fonar"; // KK
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].environment.curse = "false"; // PB: Cursed Coins

// KK -->
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";
// <-- KK

	n = n + 1;

	//ID
	Locations[n].id = "Cabin5"; // KK
	locations[n].id.label = "Captain's cabin";
	//Info
	Locations[n].filespath.models = "locations\decks\cabin\cabin01"; // KK
	Locations[n].image = "deck_cabin1.tga"; // KK
	//Sound
	Locations[n].type = "own_deck";
	Locations[n].lockCamAngle = 0.4;
	Locations[n].camshuttle = 1;
	Locations[n].fastreload = "ship";
	Locations[n].monsters = 0; // KK

	//Models
	//Always
	Locations[n].models.always.locators = "cabin01_ld"; // KK
	Locations[n].models.always.l1 = "cabin01";
	Locations[n].models.always.l2 = "cabinchest";			//fake - not visible
	Locations[n].models.always.l3 = "trunk";			//fake - not visible
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "cabin01_patch";
	Locations[n].models.day.fonar = "cabin01_fonar"; // KK
	//Night
	Locations[n].models.night.charactersPatch = "cabin01_patch";
	Locations[n].models.night.fonar = "cabin01_fonar"; // KK
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].environment.curse = "false"; // PB: Cursed Coins

// KK -->
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";
// <-- KK

	n = n + 1;
}
