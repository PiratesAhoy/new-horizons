void LocationInitQuestLocations(ref n)
{
	Locations[n].id = "Quest_ShipDeck6";
	locations[n].id.label = "Ship deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deckBig";
	Locations[n].image = "Sea";
	//Sound
	locations[n].type = "own_deck";
	Locations[n].lockCamAngle = 0.4;
	Locations[n].camshuttle = 1;
	Locations[n].fastreload = "ship";
	Locations[n].monsters = 0;

	//Models
	//Always
	Locations[n].models.always.locators = "deckBig_ld";
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
	n = n + 1;

//------------------------------------------------------------------
	Locations[n].id = "Quest_FireShipDeck";
	locations[n].id.label = "Fire Ship deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deckMedium";
	Locations[n].image = "sea";
	//Sound
	locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;
	//Models
	//Always
	Locations[n].models.always.locators = "deckMedium_l_x";
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
	Locations[n].boarding = "true";

	n = n + 1;
//-------------------------------------------------------------------
	//ID
	Locations[n].id = "Quest_ShipDeck1";
	locations[n].id.label = "HMS Hotspur";
	//Info
	Locations[n].filespath.models = "locations\Decks\qdeck";
	Locations[n].image = "Sea"; // KK
	//Sound
	locations[n].type = "own_deck";
	Locations[n].lockCamAngle = 0.4;
	Locations[n].camshuttle = 1;
//	Locations[n].fastreload = "ship";
	Locations[n].monsters = 0;
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

	n = n + 1 
//-------------------------------------------------------------------
	//ID
	Locations[n].id = "Quest_ShipDeck6XX";
	locations[n].id.label = "Ship deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deckBig";
	Locations[n].image = "Sea";
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
	Locations[n].boarding = "true";
	//============| Reload map |============//
	// Captain's cabin
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cabin4";
	Locations[n].reload.l1.emerge = "reload1";
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
	Locations[n].id = "Cabin4"; // KK
	locations[n].id.label = "Captain's cabin";
	//Info
	Locations[n].filespath.models = "locations\decks\cabin\cabin03";
	Locations[n].image = "deck_cabin2"; // KK
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

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Quest_ShipDeck6XX";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";


	n = n + 1;
//-----------------------------------------------------------------
	Locations[n].id = "Fake_Guadeloupe_fort";
	locations[n].id.label = "French Battery";


	//Town sack
	Locations[n].townsack = "Guadeloupe";

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

	Locations[n].vcskip = true; // PB

	n = n + 1;


}
