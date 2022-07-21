void LocationInitQuestLocations(ref n)
{
	// -------------------------------------------------

	Locations[n].id = "Family_deck";
	locations[n].id.label = "Ship deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deckBig";	
	Locations[n].image = "Sea.tga";

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

	//---------------------------------------------

	//ID
	Locations[n].id = "Merchant_deck";
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

	//---------------------------------------------

	//ID
	Locations[n].id = "Merchant_cabin";
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


//----------------------------------------


}
