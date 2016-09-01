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
	}
