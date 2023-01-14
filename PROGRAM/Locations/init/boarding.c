void LocationInitBoarding(ref n)
{
	// -------------------------------------------------
	//Default
	// -------------------------------------------------
	//ID
	Locations[n].id = LOCINITBRD_DEFAULTLOCATION;
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\udeck";
	Locations[n].image = "Boarding";
	//Sound
	locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;

	//Models
	//Always
	Locations[n].models.always.locators = "udeck_l";
	Locations[n].models.always.l1 = "udeck";
	//Day
	Locations[n].models.day.charactersPatch = "udeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "udeck_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	
	n = n + 1;
	
	// -------------------------------------------------
	//ID
	Locations[n].id = "ship default deck next";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\hold";
	Locations[n].image = "deck_hold";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "hold_l";
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
	Locations[n].boarding = "true";
	
	n = n + 1;

// KK -->
	// ----------------------------------------------
	Locations[n].id = "BOARDING_ShipDeck1";
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\udeck";
	Locations[n].image = "Boarding";
	//Sound
	locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;
	//Models
	//Always
	Locations[n].models.always.locators = "udeck_l";
	Locations[n].models.always.l1 = "udeck";
	//Day
	Locations[n].models.day.charactersPatch = "udeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "udeck_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";

	n = n + 1;

	// ----------------------------------------------
	Locations[n].id = "BOARDING_ShipDeck2";
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\udeck1";
	Locations[n].image = "Boarding";
	//Sound
	locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;
	//Models
	//Always
	Locations[n].models.always.locators = "udeck_l";
	Locations[n].models.always.l1 = "udeck";
	Locations[n].models.always.window = "udeck_alpha";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "udeck_p";
	Locations[n].models.day.fonar = "udeck_f";
	//Night
	Locations[n].models.night.charactersPatch = "udeck_p";
	Locations[n].models.night.fonar = "udeck_f";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	
	n = n + 1;

	// ----------------------------------------------
	Locations[n].id = "BOARDING_ShipDeck3";
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\udeck2";
	Locations[n].image = "Boarding";
	//Sound
	locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;
	//Models
	//Always
	Locations[n].models.always.locators = "udeck_l";
	Locations[n].models.always.l1 = "udeck";
	Locations[n].models.always.window = "udeck_alpha";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "udeck_p";
	Locations[n].models.day.fonar = "udeck_f";
	//Night
	Locations[n].models.night.charactersPatch = "udeck_p";
	Locations[n].models.night.fonar = "udeck_f";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";

	n = n + 1;

	//ID
	Locations[n].id = "BOARDING_ShipDeck4";
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deckLow";
	Locations[n].image = "Boarding";
	//Sound
	locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;
	//Models
	//Always
	Locations[n].models.always.locators = "deckLow_l";
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
	Locations[n].MaxSeaHeight = 0.4; 	//JRH

	n = n + 1;

	//ID
	Locations[n].id = "BOARDING_ShipDeck5";
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deckMedium";
	Locations[n].image = "Boarding";
	//Sound
	locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;
	//Models
	//Always
	Locations[n].models.always.locators = "deckMedium_l";
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

	//ID
	Locations[n].id = "BOARDING_ShipDeck6";
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deckBig";
	Locations[n].image = "Boarding";
	//Sound
	locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;
	//Models
	//Always
	Locations[n].models.always.locators = "deckBig_l";
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
	
	n = n + 1;

	//ID
	Locations[n].id = "BOARDING_ShipDeck7";
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deckBP";
	Locations[n].image = "Boarding";
	//Sound
	locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;
	//Models
	//Always
	Locations[n].models.always.locators = "deckBig_l";
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
	
	n = n + 1;

	//ID
	Locations[n].id = "BOARDING_ShipDeck4vs5";
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deckLowVSMedium";
	Locations[n].image = "Boarding";
	//Sound
	locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;
	//Models
	//Always
	Locations[n].models.always.locators = "deckLowVSMedium_l";
	Locations[n].models.always.l1 = "deckLowVSMedium";
	//Day
	Locations[n].models.day.charactersPatch = "deckLowVSMedium_p";
	Locations[n].models.day.fonar = "deckLowVSMedium_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deckLowVSMedium_p";
	Locations[n].models.night.fonar = "deckLowVSMedium_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].MaxSeaHeight = 0.4;	//JRH

	n = n + 1;

	// ----------------------------------------------
	Locations[n].id = "BOARDING_ShipDeck4vs6";
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deckLowVSBig";
	Locations[n].image = "Boarding";
	//Sound
	locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;
	//Models
	//Always
	Locations[n].models.always.locators = "deckLowVSBig_l";
	Locations[n].models.always.l1 = "deckLowVSBig";
	//Day
	Locations[n].models.day.charactersPatch = "deckLowVSBig_p";
	Locations[n].models.day.fonar = "deckLowVSBig_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deckLowVSBig_p";
	Locations[n].models.night.fonar = "deckLowVSBig_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";
	Locations[n].MaxSeaHeight = 0.4;	//JRH

	n = n + 1;

	//ID
	Locations[n].id = "BOARDING_ShipDeck5vs6";
	locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deckMediumVSBig";
	Locations[n].image = "Boarding";
	//Sound
	locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;
	//Models
	//Always
	Locations[n].models.always.locators = "deckMediumVSBig_l";
	Locations[n].models.always.l1 = "deckMediumVSBig";
	//Day
	Locations[n].models.day.charactersPatch = "deckMediumVSBig_p";
	Locations[n].models.day.fonar = "deckMediumVSBig_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deckMediumVSBig_p";
	Locations[n].models.night.fonar = "deckMediumVSBig_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].boarding = "true";

	n = n + 1;

	// ----------------------------------------------
	Locations[n].id = "BOARDING_Deck1";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deck2";
	Locations[n].image = "deck_deck2";
	//Sound
	Locations[n].type = "deck";
	//Models
	//Always
	Locations[n].models.always.locators = "deck2_l";
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
	Locations[n].boarding = "true";
	
	n = n + 1;

	// ----------------------------------------------
	Locations[n].id = "BOARDING_Deck2";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deck1";
	Locations[n].image = "deck_deck1";
	//Sound
	Locations[n].type = "deck";
	//Models
	//Always
	Locations[n].models.always.locators = "deck1_l";
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
	Locations[n].boarding = "true";
	
	n = n + 1;

	// ----------------------------------------------
	Locations[n].id = "BOARDING_Deck3";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deck1";
	Locations[n].image = "deck_deck1";
	//Sound
	Locations[n].type = "deck";
	//Models
	//Always
	Locations[n].models.always.locators = "deck1_l";
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
	Locations[n].boarding = "true";
	
	n = n + 1;

	// ----------------------------------------------
	Locations[n].id = "BOARDING_Hold";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\hold";
	Locations[n].image = "deck_hold";
	//Sound
	Locations[n].type = "deck";
	//Models
	//Always
	Locations[n].models.always.locators = "hold_l";
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
	Locations[n].boarding = "true";
	
	n = n + 1;


	// -------------------------------------------------
	// -------------------------------------NEW LOCATIONS FOR CAPTAINS CAPTURE------------------------------

	//ID
	Locations[n].id = "Boarding_Cabin_small";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\cabin\capsm"; // KK
	Locations[n].image = "deck_capsm";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "capsm_l";
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
	Locations[n].environment.curse = "false"; // PB: Cursed Coins

	if (ENABLE_AMMOMOD) Locations[n].WeaponsLocker.disabled = false; // KK

	//Reload map
	Locations[n].boarding = "true";

	n = n + 1;

	//ID
	Locations[n].id = "Boarding_Cabin_medium";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\cabin\capmd"; // KK
	Locations[n].image = "deck_capmd";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "capmd_l";
	Locations[n].models.always.l1 = "capmd";
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

	if (ENABLE_AMMOMOD) Locations[n].WeaponsLocker.disabled = false; // KK

	//Reload map
	Locations[n].boarding = "true";

	n = n + 1;

	//ID
	Locations[n].id = "Boarding_Cabin1";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\cabin\cap"; // KK
	Locations[n].image = "deck_cap";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "cap_l";
	Locations[n].models.always.l1 = "cap";
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

	if (ENABLE_AMMOMOD) Locations[n].WeaponsLocker.disabled = false; // KK

	//Reload map
	Locations[n].boarding = "true";

	n = n + 1;

	//ID
	Locations[n].id = "Boarding_Cabin2";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\cabin\Cabin01"; // KK
	Locations[n].image = "deck_cabin1";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "Cabin01_l"; // KK
	Locations[n].models.always.l1 = "Cabin01";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "Cabin01_patch";
	//Night
	Locations[n].models.night.charactersPatch = "Cabin01_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].environment.curse = "false"; // PB: Cursed Coins

	if (ENABLE_AMMOMOD) Locations[n].WeaponsLocker.disabled = false; // KK

	//Reload map
	Locations[n].boarding = "true";

	n = n + 1;

	//ID
	Locations[n].id = "Boarding_Cabin3";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\cabin\Cabin02"; // KK
	Locations[n].image = "deck_cabin2";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "Cabin02_l"; // KK
	Locations[n].models.always.l1 = "Cabin02";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "Cabin02_patch";
	//Night
	Locations[n].models.night.charactersPatch = "Cabin02_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].environment.curse = "false"; // PB: Cursed Coins

	if (ENABLE_AMMOMOD) Locations[n].WeaponsLocker.disabled = false; // KK

	//Reload map
	Locations[n].boarding = "true";

	n = n + 1;

	//ID
	Locations[n].id = "Boarding_Cabin4";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\cabin\Cabin03"; // KK
	Locations[n].image = "deck_cabin1";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "Cabin03_l"; // KK
	Locations[n].models.always.l1 = "Cabin03";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "Cabin03_patch";
	//Night
	Locations[n].models.night.charactersPatch = "Cabin03_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].environment.curse = "false"; // PB: Cursed Coins

	if (ENABLE_AMMOMOD) Locations[n].WeaponsLocker.disabled = false; // KK

	//Reload map
	Locations[n].boarding = "true";

	n = n + 1;

	//ID
	Locations[n].id = "Boarding_Cabin5";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\cabin\Cabin01"; // KK
	Locations[n].image = "deck_cabin1";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "Cabin01_l"; // KK
	Locations[n].models.always.l1 = "Cabin01";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65531;
	//Day
	Locations[n].models.day.charactersPatch = "Cabin01_patch";
	//Night
	Locations[n].models.night.charactersPatch = "Cabin01_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].environment.curse = "false"; // PB: Cursed Coins

	if (ENABLE_AMMOMOD) Locations[n].WeaponsLocker.disabled = false; // KK

	//Reload map
	Locations[n].boarding = "true";

	n = n + 1;


	// -------------------------------------------------
	/////////////////////////////////////////////////////
	////////////////////////////////FORTS////////////////
	/////////////////////////////////////////////////////
// KK -->
	//ID
	Locations[n].id = "BOARDING_Fort";
	locations[n].id.label = "Fort inside";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_1";
	Locations[n].image = "Fort_Inside_Fort_1";
	//Sound
	locations[n].type = "deck";
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

	// ID
	Locations[n].id = "BOARDING_Town";
	Locations[n].id.label = "Boarding town";
	n = n + 1;

	// ID
	Locations[n].id = "BOARDING_Residence";
	Locations[n].id.label = "Boarding town";
	n = n + 1;

	// ID
	Locations[n].id = "MUTINY_Deck";
	Locations[n].id.label = "Boarding deck";
	n = n + 1;
// <-- KK
}
