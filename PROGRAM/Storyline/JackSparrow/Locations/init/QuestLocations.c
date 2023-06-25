void LocationInitQuestLocations(ref n)
{
	Locations[n].id = "Quest_redmond_tavern";
	locations[n].id.label = "#stown_name# tavern";
	Locations[n].filespath.models = "locations\inside\Largetavern";
	Locations[n].image = "Inside_LargeTavern.tga";

	//Town sack
	Locations[n].townsack = "Redmond"; // NK 04-08-29
	Locations[n].island = "Redmond"; // NK 04-08-29

	//Sound
	locations[n].type = "tavern";
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
	Locations[n].models.back = "back\redlt_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Redmond_Town_01";
	Locations[n].reload.l1.emerge = "door_1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Center.";
	LAi_LocationFightDisable(&Locations[n], true);

	n = n + 1; 


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_IslaMuelle\town_01";
	Locations[n].image = "Town_IslaMuelle_Town_01.tga";

	Locations[n].id = "Quest_Muelle_town_01";
	locations[n].id.label = "#stown_name#";

	//Town sack
	Locations[n].townsack = "Isla Muelle"; // NK 04-08-29
	Locations[n].island = "IslaMuelle"; // NK 04-08-29

	//Sound
	locations[n].type = "town";
	//Models
	//Always
	Locations[n].models.always.l1 = "Mu01";
	Locations[n].models.always.locators = "Mu01_l";
	Locations[n].models.always.grassPatch = "Mu01_g";
	//Day
	Locations[n].models.day.rinok = "Mu01_e1";
	Locations[n].models.day.fonar = "Mu01_fd";
	Locations[n].models.day.jumppatch = "Mu01_j";
	Locations[n].models.day.charactersPatch = "Mu01_pd";
	//Night
	Locations[n].models.night.fonar = "Mu01_fn";
	Locations[n].models.night.charactersPatch = "Mu01_pn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
		
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "Quest_Residence";
	locations[n].id.label = "Redmond Townhall. Silehards's Bedroom";
	Locations[n].filespath.models = "locations\inside\ResBedRoom";
	Locations[n].image = "Inside_ResBedRoom.tga";

	//Town sack
	Locations[n].townsack = "Redmond"; // NK 04-08-29
	Locations[n].island = "Redmond"; // NK 04-08-29

	//Sound
	locations[n].type = "residence";
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
	Locations[n].reload.l1.go = "Redmond_Town_01";
	Locations[n].reload.l1.emerge = "door_5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Redmond. Center.";

	n = n + 1;

// KK -->
	// -------------------------------------------------
	// ------------------------------Fake Greenford fort
	Locations[n].id = "Fake_Greenford_fort";
	locations[n].id.label = "Fort inside";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_1";
	Locations[n].image = "Fort_Inside_Fort_1.tga";
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
	Locations[n].boarding.nextdeck = "NEXT1_Fake_Greenford_fort";

	Locations[n].island = "Oxbay";
	n = n + 1;

	//ID
	Locations[n].id = "NEXT1_Fake_Greenford_fort";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_2";
	Locations[n].image = "Fort_Inside_Fort_2.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "fort2_l";
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
	Locations[n].boarding = "fort";
	Locations[n].boarding.nextdeck = "NEXT2_Fake_Greenford_fort";

	Locations[n].island = "Oxbay";
	n = n + 1;

	//ID
	Locations[n].id = "NEXT2_Fake_Greenford_fort";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_3";
	Locations[n].image = "Fort_Inside_Fort_3.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "fort3_l";
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
	Locations[n].boarding = "fort";
	Locations[n].boarding.nextdeck = "";

	Locations[n].island = "Oxbay";
	n = n + 1;
// <-- KK

	//  -------------------------------------------------
	Locations[n].filespath.models = "locations\town_Greenford\port";	
	Locations[n].image = "Town_Greenford_Port.tga";

	Locations[n].id = "Fake_Greenford_port";
	locations[n].id.label = "#stown_name# port";

	//Town sack
	// 04-12-14 disable this, this borks MQ - Locations[n].townsack = "Greenford"; // NK 04-08-29
	Locations[n].island = "Oxbay"; // NK 04-08-29

	//Sound
	locations[n].type = "port";
	//Models
	//Always
	Locations[n].models.always.locators = "GrPort_l";
	Locations[n].models.always.l1 = "GrPort";
	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.seabed = "GrPort_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "GrPort_g";
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
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reload4";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "";
	Locations[n].reload.l2.autoreload = "0";

	n = n + 1;


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_Greenford\town";
	Locations[n].image = "Town_Greenford_Town.tga";

	Locations[n].id = "Fake_Greenford_town";
	locations[n].id.label = "#stown_name#";

	//Town sack
	// 04-12-14 disable this, this borks MQ - Locations[n].townsack = "Greenford"; // NK 04-08-29
	Locations[n].island = "Oxbay"; // NK 04-08-29

	//Sound
	locations[n].type = "town";
	//Models
	//Always
	Locations[n].models.always.locators = "GrTown_l";
	Locations[n].models.always.l1 = "GrTown";
	Locations[n].models.always.grassPatch = "GrTown_g";
	//Day
	Locations[n].models.day.rinok = "GrTown_e01";
	Locations[n].models.day.fonar = "GrTown_fd";
	Locations[n].models.day.charactersPatch = "GrTown_pd";
	//Night
	Locations[n].models.night.fonar = "GrTown_fn";
	Locations[n].models.night.charactersPatch = "GrTown_pn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map

	n = n + 1;

//---------------------------------------------------------------------------


	Locations[n].id = "Fake_Greenford_prison";
	locations[n].id.label = "#stown_name# prison";
	Locations[n].filespath.models = "locations\inside\prison";

	//Town sack
	// 04-12-14 disable this, this borks MQ - Locations[n].townsack = "Greenford"; // NK 04-08-29
	Locations[n].island = "Oxbay"; // NK 04-08-29
	
	//Sound
	locations[n].type = "jail";
	Locations[n].image = "Inside_Prison.tga";
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
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Decks\qdeck";
	Locations[n].image = "sea.tga";

	Locations[n].id = "Ship_deck";
	locations[n].id.label = "Pirate bark";
	//Sound
	locations[n].type = "deck";
	//Models
	//Always
	Locations[n].models.always.locators = "qdeck_l";
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
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.disable = 1;
	Locations[n].reload.l1.emerge = "reload2";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Decks\qdeck";
	Locations[n].image = "sea.tga";

	Locations[n].id = "Gamboa_ship";
	locations[n].id.label = "Gamboa ship";

    // Swindler added type to avoid bug connected to LoginCharactersInLocation() function
    locations[n].type = "deck";

	//Sound
	Locations[n].models.always.locators = "qdeck_l";
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
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.disable = 1;
	Locations[n].reload.l1.emerge = "reload2";
	n = n + 1;

	//Lucas

	//Santiago

	Locations[n].filespath.models = "locations\Decks\qdeck";
	Locations[n].image = "sea.tga";

	Locations[n].id = "Santiago_ship";
	locations[n].id.label = "Santiago ship";

    // Swindler added type to avoid bug connected to LoginCharactersInLocation() function
    locations[n].type = "deck";

	//Sound
	Locations[n].models.always.locators = "qdeck_l";
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
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.disable = 1;
	Locations[n].reload.l1.emerge = "reload2";
	n = n + 1;

	//Santiago

	//First Contact

	Locations[n].id = "Quest_FalaiseDeFleur_Port2";
	locations[n].id.label = "Falaise De Fleur Port";
	Locations[n].image = "Town_FalaiseDeFleur_Port2.tga";

	//Town sack
	Locations[n].townsack = "Falaise_De_Fleur";

	//Sound
	locations[n].type = "port";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\port2";
	Locations[n].models.always.city = "FFport02";
	Locations[n].models.always.city.foam = "1";
	Locations[n].models.always.seabed = "FFport02_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.locators = "FFport02_l";
	Locations[n].models.always.grassPatch = "FFport02_g";
	//Day
	Locations[n].models.day.fonar = "FFport02_fd";
	Locations[n].models.day.charactersPatch = "FFport02_p";
	//Night
	Locations[n].models.night.fonar = "FFport02_fn";
	Locations[n].models.night.charactersPatch = "FFport02_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	LAi_LocationFantomsGen(&locations[n], true);
	Locations[n].reload.l1.name = "Falaise_de_fleur_location_01_05";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.label = "Town.";

	Locations[n].vcskip = true; // PB

	Locations[n].island = "FalaiseDeFleur"; 
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\town_02";
	Locations[n].filespath.textures = "locations\FRANCE";
	
	Locations[n].id = "Quest_Falaise_de_fleur_location_03";
	locations[n].id.label = "Falaise De Fleur";
	Locations[n].image = "Town_FalaiseDeFleur_Town_02.tga";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].models.always.locators = "FF02_l";
	Locations[n].models.always.grassPatch = "FF02_g";
	Locations[n].models.always.city = "FF02";
		//Day
	Locations[n].models.day.fonar = "FF02_fd";
	Locations[n].models.day.charactersPatch = "FF02_pd";
	Locations[n].models.day.jumppatch = "FF02_j";
	//Locations[n].models.day.rinok = "FF02_e01";
	//Night
	Locations[n].models.night.fonar = "FF02_fn";
	Locations[n].models.night.charactersPatch = "FF02_pn";
	Locations[n].models.night.jumppatch = "FF02_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "Falaise_de_fleur_location_03_04";
	Locations[n].reload.l1.go = "Quest_Falaise_de_fleur_location_04";
	Locations[n].reload.l1.emerge = "Falaise_de_fleur_location_04_03";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Saint Pierre";

	Locations[n].reload.l2.name = "Falaise_de_fleur_townhall";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "";
	Locations[n].reload.l2.label = "Residence.";

	Locations[n].vcskip = true;

	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

	//--------------------------------------------------

	Locations[n].id = "Quest_Falaise_de_fleur_location_04";
	locations[n].id.label = "Falaise De Fleur";

	Locations[n].image = "Town_FalaiseDeFleur_Town_03.tga";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\town_03";
	Locations[n].filespath.textures = "locations\FRANCE";
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
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.label = "Falaise De Fleur Center.";

	Locations[n].vcskip = true;

	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

	//First Contact

	//Isla de Muerte I

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Decks\udeck2";
	Locations[n].image = "sea.tga";

	Locations[n].id = "Black_Pearl";
	locations[n].id.label = "Black Pearl";

    // Swindler added type to avoid bug connected to LoginCharactersInLocation() function
    locations[n].type = "deck";

	//Always
	Locations[n].models.always.locators = "udeck_ld";
	Locations[n].models.always.l1 = "udeck";
	//Day
	Locations[n].models.day.charactersPatch = "udeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "udeck_p";
	Locations[n].lockCamAngle = 0.4;
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l5.name = "boatr";
	Locations[n].reload.l5.go = "Interceptor_deck";
	Locations[n].reload.l5.emerge = "loc4";
	Locations[n].reload.l5.autoreload = "0";

	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "Interceptor_deck";
	locations[n].id.label = "Ship deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deckBig";	
	Locations[n].image = "Sea.tga";

	Locations[n].id = "Interceptor_deck";
	locations[n].id.label = "Ship deck";

    // Swindler added type to avoid bug connected to LoginCharactersInLocation() function
    locations[n].type = "deck";

	//Always
	Locations[n].models.always.locators = "deckBig_l";
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

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Shore_8";

	Locations[n].id = "Deserted_Island_shore_01";
	locations[n].id.label = "Deserted Island Shore 1";
	Locations[n].image = "Outside_Shore_8.tga";
	Locations[n].name = "Deserted Island Shore 1";
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
	Locations[n].reload.l1.go = "Deserted_island_Jungle_01";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 3;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Deserted_island_Jungle_01";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3;
	
	Locations[n].island = "IslaMona";
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Shore_9";

	Locations[n].id = "Deserted_island_shore_02";
	locations[n].id.label = "Deserted Island Shore 2"; 
	Locations[n].image = "Outside_Shore_9.tga";
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
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.locator3 = 2.0;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "IslaMona";
	Locations[n].reload.l2.emerge = "Reload_1";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 9.0;

	Locations[n].reload.l3.name = "locator3_back";
	Locations[n].reload.l3.go = "";
	Locations[n].reload.l3.emerge = "";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.locator3_back = 2.0;
	
	Locations[n].island = "IslaMona";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_6";

	Locations[n].id = "Deserted_island_Jungle_01";
	locations[n].id.label = "Jungle";		
	Locations[n].image = "Outside_Jungle_6.tga";
	//Sound
	locations[n].type = "jungle";

	//Models
	//Always
	Locations[n].models.always.locators = "Jungle06_l";
	Locations[n].models.always.jungle = "Jungle06";
	Locations[n].models.always.grassPatch = "JUNGLE06_g";
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
	Locations[n].models.day.charactersPatch = "Jungle06_p";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle06_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Deserted_island_shore_02";
	Locations[n].reload.l3.emerge = "locator3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.reload3 = 2.5;
	Locations[n].reload.l3.label = "Shore.";

	Locations[n].reload.l5.name = "reload3_back";
	Locations[n].reload.l5.go = "Deserted_island_shore_02";
	Locations[n].reload.l5.emerge = "locator3_back";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].locators_radius.reload.reload3_back = 3;
	Locations[n].reload.l5.label = "Shore.";
	
	Locations[n].island = "IslaMona";
	n = n + 1;

	// ----------------------------------
	Locations[n].id = "Quest_Redmond_fort";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";


	//Town sack
	Locations[n].townsack = "Redmond";

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

	Locations[n].vcskip = true; // PB

	n = n + 1;

	//Isla de Muerte I

	//  -------------------------------------------------
	Locations[n].id = "Ransom_house_f1";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "Locations\Inside\Doubleflour_house";
	Locations[n].image = "Inside_Doubleflour_House_Lower.tga";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur"; // NK 04-08-29
	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	
	//Sound
	locations[n].type = "residence";
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F1_l";
	Locations[n].models.always.l1 = "LH_F1";

	//Day
	Locations[n].models.day.charactersPatch = "LH_F1_p";

	//Night
	Locations[n].models.night.charactersPatch = "LH_F1_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\fflf1_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_03";
	Locations[n].reload.l1.emerge = "home7";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Street";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Ransom_house_f2";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "2nd floor";

	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "Ransom_house_f2";
	locations[n].id.label = "Kidnappers' Hideout, 2nd floor";
	Locations[n].filespath.models = "Locations\Inside\Doubleflour_house";
	Locations[n].image = "Inside_Doubleflour_House_Upper.tga";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur"; // NK 04-08-29
	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	
	//Sound
	locations[n].type = "residence";
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F2_l";
	Locations[n].models.always.l1 = "LH_F2";
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
	Locations[n].models.back = "back\fflf2_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Ransom_house_f1";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "1st floor";

	n = n + 1;

//Lucas

//Hitman SCM Changes

	//  -------------------------------------------------
	Locations[n].id = "Hit_house";
	Locations[n].id.label = "House of Mateus Santos";
	Locations[n].filespath.models = "locations\inside\Residence6";
	Locations[n].image = "Inside_Residence6.tga";

	//Town sack
	Locations[n].townsack = "Isla Muelle"; // NK 04-08-29
	Locations[n].island = "IslaMuelle"; // NK 04-08-29
	
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Muelle";
	//Models
	//Always
	Locations[n].models.always.locators = "Res06_l";
	Locations[n].models.always.l1 = "Res06";
	Locations[n].models.always.window = "Res06_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;  

	//Day
	Locations[n].models.day.charactersPatch = "Res06_p";

	//Night
	Locations[n].models.night.charactersPatch = "Res06_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\mures6_";
	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Muelle_town_01";
	Locations[n].reload.l1.emerge = "Reload21";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";

	Locations[n].reload.l2.name = "Reload2"; //SCM
	Locations[n].reload.l2.go = "Hit_study"; //SCM
	Locations[n].reload.l2.emerge = "Reload1"; //SCM
	Locations[n].reload.l2.autoreload = "0"; //SCM
	Locations[n].reload.l2.label = "Study of Mateus Santos"; //SCM 
	

	n = n + 1;

	// ------------------------------------------------- SCM
	Locations[n].id = "Hit_study";
	Locations[n].id.label = "Study of Mateus Santos";
	Locations[n].filespath.models = "locations\inside\Residence6";
	Locations[n].image = "Inside_Residence6_Study.tga";

	//Town sack
	Locations[n].townsack = "Isla Muelle"; // NK 04-08-29
	Locations[n].island = "IslaMuelle"; // NK 04-08-29
	
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Muelle";
	//Models
	//Always
	Locations[n].models.always.locators = "Res06_1_l";
	Locations[n].models.always.l2 = "Res06_1";
	Locations[n].models.always.window = "Res06_1_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;  

	//Day
	Locations[n].models.day.charactersPatch = "Res06_1_p";

	//Night
	Locations[n].models.night.charactersPatch = "Res06_1_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\mures6_";
	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Hit_house";
	Locations[n].reload.l1.emerge = "Reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "House of Mateus Santos";

	Locations[n].reload.l2.name = "Reload2_back";
	Locations[n].reload.l2.go = "Hit_passage";
	Locations[n].reload.l2.emerge = "Reload13_back";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Secret Passage";


	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Hit_passage";
	Locations[n].id.label = "Secret Passage";
	Locations[n].filespath.models = "locations\inside\Residence6";
	Locations[n].image = "Inside_Residence6_Prison.tga";

	//Town sack
	Locations[n].townsack = "Isla Muelle"; // NK 04-08-29
	Locations[n].island = "IslaMuelle"; // NK 04-08-29
	
	//Sound
	locations[n].type = "dungeon";
	locations[n].fastreload = "Muelle";
	//Models
	//Always
	Locations[n].models.always.locators = "Res06_2_l";
	Locations[n].models.always.l1 = "Res06_2";
	Locations[n].models.always.window = "Res06_2_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;  

	//Day
	Locations[n].models.day.charactersPatch = "Res06_2_p";

	//Night
	Locations[n].models.night.charactersPatch = "Res06_2_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "Reload10";
	Locations[n].reload.l1.go = "Muelle_church";
	Locations[n].reload.l1.emerge = "Reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Alas poor Yorick!";


	n = n + 1;

	
	// -------------------------------------------------
	Locations[n].id = "Hit_house1";
	locations[n].id.label = "House of Geffrey Bampfylde";
	Locations[n].filespath.models = "locations\inside\Residence1";
	Locations[n].image = "Inside_Residence1_Hitman.tga";

	//Town sack
	Locations[n].townsack = "Greenford"; // NK 04-08-29
	Locations[n].island = "Oxbay"; // NK 04-08-29

	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Greenford";
	//Models
	//Always
	Locations[n].models.always.locators = "res01_l";
	Locations[n].models.always.house = "res01";
	Locations[n].models.always.window = "res01_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;    
	//Day
	Locations[n].models.day.charactersPatch = "res01_p";

	//Night
	Locations[n].models.night.charactersPatch = "res01_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\ffres1_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_town";
	Locations[n].reload.l1.emerge = "reload5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "Hit_house2";
	Locations[n].id.label = "House of Amérigo Vieira";		//spell-checked by KAM
	Locations[n].filespath.models = "Locations\Inside\Doubleflour_house";
	Locations[n].image = "Inside_Doubleflour_House_Hitman.tga";

	//Town sack
	Locations[n].townsack = "Conceicao"; // NK 04-08-29
	Locations[n].island = "Conceicao"; // NK 04-08-29

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Conceicao";
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F2_l";
	Locations[n].models.always.l1 = "LH_F2";
/*	Locations[n].models.always.window = "LH_F2_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;  */

	//Day
	Locations[n].models.day.charactersPatch = "LH_F2_p";

	//Night
	Locations[n].models.night.charactersPatch = "LH_F2_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\colf2_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Conceicao_town";
	Locations[n].reload.l1.emerge = "reload15";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";
	n = n + 1;

//Hitman SCM Changes end

// Dead Man's Chest Locations -->

	Locations[n].filespath.models = "locations\Outside\Jungle_Church";
	Locations[n].id = "Jungle_Church";
	locations[n].id.label = "Church in Jungle";
	Locations[n].image = "Outside_Jungle_Church.tga";
	//Sound
	locations[n].type = "jungle";
	//Models
	//Always
	Locations[n].models.always.locators = "Rhouse_l_jungle";
	Locations[n].models.always.house = "Rhouse";
	Locations[n].models.always.grassPatch = "Rhouse_g";
	Locations[n].models.always.l1 = "rhouse_b01";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "rhouse_b02";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "rhouse_b03";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	Locations[n].models.always.l4 = "rhouse_b04";
	Locations[n].models.always.l4.level = 6;
	Locations[n].models.always.l4.tech = "LocationModelBlend";

	locations[n].vcskip = true; // PB
	//Day
	Locations[n].models.day.charactersPatch = "Rhouse_p";
	//Night
	Locations[n].models.night.charactersPatch = "Rhouse_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1 = 3;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 3;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Jungle_Church_inside";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "church";

	LAi_LocationMonstersGen(&locations[n], false);
//	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;


// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Jungle_Church_inside";

	Locations[n].id = "Jungle_Church_inside";
	locations[n].id.label = "Pirate church";
	Locations[n].image = "Inside_Jungle_Church_inside.tga";

	//Sound
	locations[n].type = "church";	
	//Models
	//Always
	Locations[n].models.always.locators = "church01_locators_jungle";
	Locations[n].models.always.city = "Church01";
	Locations[n].models.always.window = "Church01_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Church01_patch";
	//Night
	Locations[n].models.night.charactersPatch = "Church01_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";	
	Locations[n].models.back = "back\juch_";

	//Reload map
	//out
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Jungle_Church";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.label = "";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 1.0;

	//to grot
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Jungle_Church_Grot";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 1.0;
	
	//to pulpit
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Jungle_Church_inside";
	Locations[n].reload.l4.emerge = "reload5";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.5;

	//from pulpit
	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "Jungle_Church_inside";
	Locations[n].reload.l5.emerge = "reload4";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "";
	Locations[n].locators_radius.reload.reload5 = 0.5;

	Locations[n].locators_radius.reload.reload3 = 1.0;

	//Locations[n].island = "Redmond";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Grot";

	Locations[n].id = "Jungle_Church_Grot";
	locations[n].id.label = "Hidden Cave";
	Locations[n].image = "Inside_Grot.tga";
	//Sound
	locations[n].type = "cave";
	//Models
	Locations[n].models.back = "back\grotenv_";
	//Always
	Locations[n].models.always.cave = "Grot";
	Locations[n].models.always.locators = "Grot_l";
	//Day
	Locations[n].models.day.charactersPatch = "Grot_p";
	//Night
	Locations[n].models.night.charactersPatch = "Grot_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Jungle_Church_inside";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "";

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Jungle_Church_inside";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload1_back = 2;

//	LAi_LocationMonstersGen(&locations[n], true);
//	LAi_LocationSetMonstersTime(&locations[n], 0, 24);

	Locations[n].items.randitem1 = "blade8";

//	Locations[n].island = "Conceicao";
	n = n + 1;

// Dead Man's Chest Locations <--

//Hitman SCM Changes

	//  -------------------------------------------------
	Locations[n].id = "Hit_house";
	Locations[n].id.label = "House of Mateus Santos";
	Locations[n].filespath.models = "locations\inside\Residence6";
	Locations[n].image = "Inside_Residence6.tga";

	//Town sack
	Locations[n].townsack = "Isla Muelle"; // NK 04-08-29
	Locations[n].island = "IslaMuelle"; // NK 04-08-29
	
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Muelle";
	//Models
	//Always
	Locations[n].models.always.locators = "Res06_l";
	Locations[n].models.always.l1 = "Res06";
	Locations[n].models.always.window = "Res06_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;  

	//Day
	Locations[n].models.day.charactersPatch = "Res06_p";

	//Night
	Locations[n].models.night.charactersPatch = "Res06_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\mures6_";
	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Muelle_town_01";
	Locations[n].reload.l1.emerge = "Reload21";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";

	Locations[n].reload.l2.name = "Reload2"; //SCM
	Locations[n].reload.l2.go = "Hit_study"; //SCM
	Locations[n].reload.l2.emerge = "Reload1"; //SCM
	Locations[n].reload.l2.autoreload = "0"; //SCM
	Locations[n].reload.l2.label = "Study of Mateus Santos"; //SCM 
	

	n = n + 1;

	// ------------------------------------------------- SCM
	Locations[n].id = "Hit_study";
	Locations[n].id.label = "Study of Mateus Santos";
	Locations[n].filespath.models = "locations\inside\Residence6";
	Locations[n].image = "Inside_Residence6_Study.tga";

	//Town sack
	Locations[n].townsack = "Isla Muelle"; // NK 04-08-29
	Locations[n].island = "IslaMuelle"; // NK 04-08-29
	
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Muelle";
	//Models
	//Always
	Locations[n].models.always.locators = "Res06_1_l";
	Locations[n].models.always.l2 = "Res06_1";
	Locations[n].models.always.window = "Res06_1_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;  

	//Day
	Locations[n].models.day.charactersPatch = "Res06_1_p";

	//Night
	Locations[n].models.night.charactersPatch = "Res06_1_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\mures6_";
	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Hit_house";
	Locations[n].reload.l1.emerge = "Reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "House of Mateus Santos";

	Locations[n].reload.l2.name = "Reload2_back";
	Locations[n].reload.l2.go = "Hit_passage";
	Locations[n].reload.l2.emerge = "Reload13_back";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Secret Passage";


	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Hit_passage";
	Locations[n].id.label = "Secret Passage";
	Locations[n].filespath.models = "locations\inside\Residence6";
	Locations[n].image = "Inside_Residence6_Prison.tga";

	//Town sack
	Locations[n].townsack = "Isla Muelle"; // NK 04-08-29
	Locations[n].island = "IslaMuelle"; // NK 04-08-29
	
	//Sound
	locations[n].type = "dungeon";
	locations[n].fastreload = "Muelle";
	//Models
	//Always
	Locations[n].models.always.locators = "Res06_2_l";
	Locations[n].models.always.l1 = "Res06_2";
	Locations[n].models.always.window = "Res06_2_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;  

	//Day
	Locations[n].models.day.charactersPatch = "Res06_2_p";

	//Night
	Locations[n].models.night.charactersPatch = "Res06_2_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "Reload10";
	Locations[n].reload.l1.go = "Muelle_church";
	Locations[n].reload.l1.emerge = "Reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Alas poor Yorick!";


	n = n + 1;

	
	// -------------------------------------------------
	Locations[n].id = "Hit_house1";
	locations[n].id.label = "House of Geffrey Bampfylde";
	Locations[n].filespath.models = "locations\inside\Residence1";
	Locations[n].image = "Inside_Residence1_Hitman.tga";

	//Town sack
	Locations[n].townsack = "Greenford"; // NK 04-08-29
	Locations[n].island = "Oxbay"; // NK 04-08-29

	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Greenford";
	//Models
	//Always
	Locations[n].models.always.locators = "res01_l";
	Locations[n].models.always.house = "res01";
	Locations[n].models.always.window = "res01_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;    
	//Day
	Locations[n].models.day.charactersPatch = "res01_p";

	//Night
	Locations[n].models.night.charactersPatch = "res01_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\ffres1_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_town";
	Locations[n].reload.l1.emerge = "reload5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "Hit_house2";
	Locations[n].id.label = "House of Amérigo Vieira";		//spell-checked by KAM
	Locations[n].filespath.models = "Locations\Inside\Doubleflour_house";
	Locations[n].image = "Inside_Doubleflour_House_Hitman.tga";

	//Town sack
	Locations[n].townsack = "Conceicao"; // NK 04-08-29
	Locations[n].island = "Conceicao"; // NK 04-08-29

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Conceicao";
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F2_l";
	Locations[n].models.always.l1 = "LH_F2";
/*	Locations[n].models.always.window = "LH_F2_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;  */

	//Day
	Locations[n].models.day.charactersPatch = "LH_F2_p";

	//Night
	Locations[n].models.night.charactersPatch = "LH_F2_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\colf2_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Conceicao_town";
	Locations[n].reload.l1.emerge = "reload15";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";
	n = n + 1;

//Hitman SCM Changes end

//Sebrian locations start

	//  -------------------------------------------------

	Locations[n].id = "Tia_Dalma_swamp";
	locations[n].id.label = "Swamp";
	Locations[n].image = "Outside_Dalma_swamp.tga";
	
	//Sound
	locations[n].type = "night_sneaking";
	LAi_LocationMonstersGen(&locations[n], false);
	locations[n].vcskip = true;
	
	//Models
	//Always
	Locations[n].filespath.models = "locations\Outside\Jungle_QC";
	Locations[n].models.always.locators = "QCexit_l_Dalma";
	Locations[n].models.always.exit = "QCexit";
	Locations[n].models.always.grassPatch = "QCexit_g";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";

	//Day
	Locations[n].models.day.charactersPatch = "QCexit_p";
	//Night
	Locations[n].models.night.charactersPatch = "QCexit_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.05;
    	Locations[n].environment.swamp2 = "true";
    	
	//Reload map
/*	
	Locations[n].reload.l10.name = "Reload1_back";
	Locations[n].reload.l10.go = "QC_town";
	Locations[n].reload.l10.emerge = "reload1";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "#stown_name#.";	*/
	Locations[n].locators_radius.reload.Reload1_back = 2.0;

/*	Locations[n].reload.l20.name = "Reload2_back";
	Locations[n].reload.l20.go = "QC_port";
	Locations[n].reload.l20.emerge = "reload3";
	Locations[n].reload.l20.autoreload = "1";
	Locations[n].reload.l20.label = "Sea port.";		*/
	Locations[n].locators_radius.reload.Reload2_back = 2.0;

/*	Locations[n].reload.l30.name = "Reload3_back";
	Locations[n].reload.l30.go = "QC_Jungle_04";
	Locations[n].reload.l30.emerge = "reload1";
	Locations[n].reload.l30.autoreload = "1";
	Locations[n].reload.l30.label = "Jungle.";		*/
	Locations[n].locators_radius.reload.Reload3_back = 2.0;

	Locations[n].reload.l40.name = "Reload4_back";
	Locations[n].reload.l40.go = "Tia_Dalma_hut";
	Locations[n].reload.l40.emerge = "reload1";
	Locations[n].reload.l40.autoreload = "1";
	Locations[n].reload.l40.label = "Hut.";
	Locations[n].locators_radius.reload.Reload4_back = 2.0;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "big_hut";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "barn1";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "koster1";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "koster1";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "koster1";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "koster1";

	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "tree1";

	Locations[n].locators_radius.randitem.randitem8 = 0.01;
	Locations[n].items.randitem8 = "ladder_big";

	Locations[n].locators_radius.randitem.randitem9 = 0.01;
	Locations[n].items.randitem9 = "3Feet";

	Locations[n].locators_radius.randitem.randitem10 = 0.01;
	Locations[n].items.randitem10 = "3Feet";

	Locations[n].locators_radius.randitem.randitem11 = 0.01;
	Locations[n].items.randitem11 = "jars";

	Locations[n].locators_radius.randitem.randitem12 = 0.01;
	Locations[n].items.randitem12 = "skull3";

	Locations[n].locators_radius.randitem.randitem13 = 0.01;
	Locations[n].items.randitem13 = "";				//not used
	
	Locations[n].locators_radius.randitem.randitem14 = 0.01;
	Locations[n].items.randitem14 = "box";

	Locations[n].locators_radius.randitem.randitem15 = 0.01;
	Locations[n].items.randitem15 = "door_attic1";

	Locations[n].island = "Antigua";
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].id = "Tia_Dalma_hut";
	locations[n].id.label = "Tia Dalma";
	Locations[n].filespath.models = "locations\inside\Hut_isle";
	Locations[n].image = "Inside_Dalma_hut.tga";

	//Sound
	locations[n].type = "Poe_home";

	//Models
	//Always
	Locations[n].models.always.locators = "Hut_Dalma_locators";
	Locations[n].models.always.l1 = "Hut_isle";
	
	//Day
	Locations[n].models.day.charactersPatch = "Hut_isle_patch";

	//Night
	Locations[n].models.night.charactersPatch = "Hut_isle_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\shp_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Tia_Dalma_swamp";
    	Locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "door_largeh2";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "door_attic1";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "fur1";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "rope_ale";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "rope_ale";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "carpet3V";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "potion4";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "potionwine";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "medicine_table";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "rope_ale";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "jars";

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "potion3";

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "rope_ale";

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
	Locations[n].items.randitem14 = "potion1";

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	Locations[n].items.randitem15 = "books1";

	Locations[n].locators_radius.randitem.randitem16 = 0.001;
	Locations[n].items.randitem16 = "pyrite_basket_up";

	Locations[n].locators_radius.randitem.randitem17 = 0.001;
	Locations[n].items.randitem17 = "chest5_coas";

	Locations[n].locators_radius.randitem.randitem18 = 0.001;
	Locations[n].items.randitem18 = "rope_ale";

	Locations[n].locators_radius.randitem.randitem19 = 0.001;
	Locations[n].items.randitem19 = "potion2";

	Locations[n].locators_radius.randitem.randitem20 = 0.001;
	Locations[n].items.randitem20 = "rope_ale";

	Locations[n].locators_radius.randitem.randitem21 = 0.001;
	Locations[n].items.randitem21 = "potionrum";

	Locations[n].locators_radius.randitem.randitem22 = 0.001;
	Locations[n].items.randitem22 = "cauldron1";

	Locations[n].locators_radius.randitem.randitem23 = 0.001;
	Locations[n].items.randitem23 = "skull3";

	Locations[n].locators_radius.randitem.randitem24 = 0.001;
	Locations[n].items.randitem24 = "rope_ale";

	Locations[n].locators_radius.randitem.randitem25 = 0.001;
	Locations[n].items.randitem25 = "potionrum";

	Locations[n].locators_radius.randitem.randitem26 = 0.001;
	Locations[n].items.randitem26 = "blowgun";

	Locations[n].locators_radius.randitem.randitem27 = 0.001;
	Locations[n].items.randitem27 = "flute";

	Locations[n].locators_radius.randitem.randitem28 = 0.001;
	Locations[n].items.randitem28 = "censer_item";

	Locations[n].locators_radius.randitem.randitem29 = 0.001;
	Locations[n].items.randitem29 = "books1";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Antigua";
	n = n + 1;

	//  -------------------------------------------------
    //Prison on Turks
	Locations[n].id = "Fake_Turks_prison";
	locations[n].id.label = "Prison chambers";
	Locations[n].filespath.models = "locations\inside\prison";

	//Town sack
	// 04-12-14 disable this, this borks MQ - Locations[n].townsack = "Greenford"; // NK 04-08-29
	Locations[n].island = "Turks"; // NK 04-08-29
	
	//Sound
	locations[n].type = "jail";
	Locations[n].image = "Inside_Prison.tga";
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
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "reload1";
	n = n + 1;


	//---------------------------------------------

	//ID
	Locations[n].id = "Fake_Seadogs";
	locations[n].id.label = "Crew's quarters";
	//Info
	Locations[n].filespath.models = "locations\decks\seadogs"; // KK
	Locations[n].image = "deck_seadogs.tga"; // KK
	//Sound
	Locations[n].type = "crew";
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
	Locations[n].reload.l1.disable = 1;
	// Door near table
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l1.disable = 1;
	// <-- KK
	n = n + 1;
	
	//---------------------------------------------

	//ID
	Locations[n].id = "Fake_Hold1";
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
	
	
	// -------------------------------------------------
	Locations[n].id = "KhaelRoa_shore_fake";
	//Locations[n].worldmap = "Khael Roa";
	Locations[n].filespath.models = "locations\Incas Temple\Port";
	Locations[n].image = "Incas_Temple_Port.tga";
	locations[n].id.label = "#sisland_name# shore";
	//Sound
	locations[n].type = "seashore";
	//Models
	//Always
	Locations[n].models.always.locators = "KRport_l";
	Locations[n].models.always.shore = "KRport";
	Locations[n].models.always.shore.foam = "1";
	Locations[n].models.always.seabed = "KRport_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grasspatch = "KRport_g";
	
	
	//Day
	Locations[n].models.day.charactersPatch = "KRport_p";	
	//Night
	Locations[n].models.night.charactersPatch = "KRport_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "KhaelRoa";
	Locations[n].reload.l1.emerge = "reload_1";
	Locations[n].reload.l1.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l1.label = "Ship.";
	else
		Locations[n].reload.l1.label = "Sea.";

	Locations[n].reload.l2.name = "reload1";
	Locations[n].reload.l2.go = "KhaelRoa_Jungle_Fake_1";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "KhaelRoa_Jungle_Fake_1";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].island = "KhaelRoa"; // NK 04-08-29
	n = n + 1;
	
	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_6";

	Locations[n].id = "KhaelRoa_Jungle_Fake_1";
	locations[n].id.label = "Khael Roa jungles";		//spell-checked by KAM
	Locations[n].image = "Outside_Jungle_6.tga";
	//Sound
	locations[n].type = "indian_jungle";
	Locations[n].island = "KhaelRoa"; // NK 04-11-03
		
	//Models
	//Always
	Locations[n].models.always.locators = "Jungle06_l";
	Locations[n].models.always.jungle = "Jungle06";
	Locations[n].models.always.grassPatch = "JUNGLE06_g";
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
	Locations[n].models.day.charactersPatch = "Jungle06_p";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle06_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	
/*  Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "KhaelRoa_Jungle_02";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 2.5;
	Locations[n].reload.l1.label = "Jungle.";
*/

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "roa_Cave_fake";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload2 = 2.5;
	Locations[n].reload.l2.label = "Shore.";


	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "roa_Cave_fake";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].locators_radius.reload.reload2_back = 2.5;
	Locations[n].reload.l4.label = "Shore";

/**/
/*	Locations[n].reload.l6.name = "reload1_back";
	Locations[n].reload.l6.go = "KhaelRoa_Jungle_02";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 2.5;
	Locations[n].reload.l6.label = "Jungle.";
	
*/
	Locations[n].vcskip = true; // SEB

	Locations[n].island = "KhaelRoa"; // NK 04-08-29
	n = n + 1;
	
	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Cave Entrance";

	Locations[n].id = "roa_Cave_fake";
	locations[n].id.label = "Entrance to #sisland_name# cave";
	Locations[n].image = "Outside_Cave_Entrance.tga";
	//Sound
	locations[n].type = "indian_jungle";
	//LAi_LocationSetMonstersTime(&locations[n], 22, 6);
	Locations[n].island = "KhaelRoa"; // NK 04-11-03

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
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "KhaelRoa_Cavern_fake";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Cave.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "KhaelRoa_Jungle_Fake_1";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 2.0;

	Locations[n].reload.l3.name = "reload2_back";      //if you return to the jungle
	Locations[n].reload.l3.go = "KhaelRoa_Jungle_Fake_1";
	Locations[n].reload.l3.emerge = "reload2";      //you arrive here
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 2.0;
	
	Locations[n].vcskip = true; // SEB

	Locations[n].island = "KhaelRoa"; // NK 04-08-29
	n = n + 1;

// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Cavern";

	Locations[n].id = "KhaelRoa_Cavern_fake";
	locations[n].id.label = "#sisland_name# Cavern";
	Locations[n].image = "Inside_Cavern.tga";

	//Sound
	locations[n].type = "indian_jungle";
	Locations[n].island = "KhaelRoa"; // NK 04-11-03
	//Models
	//Always
	Locations[n].models.always.locators = "cavern_l";
	Locations[n].models.always.l1 = "cavern";
	Locations[n].models.always.l2 = "Crystals";
	Locations[n].models.always.l2.tech = "EnvironmentShader";
	Locations[n].models.always.l2.reflection = 0.25;


	Locations[n].models.always.Waterfall1 = "water";
	Locations[n].models.always.Waterfall1.uvslide.v0 = 0.0;
    Locations[n].models.always.Waterfall1.uvslide.v1 = 0.0;
    Locations[n].models.always.Waterfall1.tech = "LocationWaterFall";
	Locations[n].models.always.Waterfall1.level = 50;

	Locations[n].models.always.Waterfall2 = "cfall";
	Locations[n].models.always.Waterfall2.uvslide.v0 = 0.3;
    Locations[n].models.always.Waterfall2.uvslide.v1 = 0.0;
	Locations[n].models.always.Waterfall2.tech = "LocationWaterFall";
	Locations[n].models.always.Waterfall2.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "cavern_p";
	//Night
	Locations[n].models.night.charactersPatch = "cavern_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "roa_Cave_fake";
	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "roa_Cave_fake";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "KhaelRoa_Jungle_Fake_Bridge";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Old Bridge";

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "KhaelRoa_Jungle_Fake_Bridge";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Old Bridge";
	Locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].vcskip = true; // SEB

	Locations[n].island = "KhaelRoa"; // NK 04-08-29
	n = n + 1;

// -------------------------------------------------
	
	
	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Passage";

	Locations[n].id = "KhaelRoa_Jungle_Fake_Bridge";
	locations[n].id.label = "Old Bridge";
	Locations[n].image = "Outside_Passage1.tga";
	//Sound
	locations[n].type = "indian_jungle";

	//Models
	//Always
	Locations[n].models.always.locators = "pass1_l_GR";
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

	Locations[n].reload.l1.name = "reload4";
	Locations[n].reload.l1.go = "Indian_Village2";
	Locations[n].reload.l1.emerge = "loc0";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload4 = 2.0;

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "KhaelRoa_Cavern_fake";
	Locations[n].reload.l2.emerge = "monster4";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Hidden Cave";

	Locations[n].vcskip = true; // SEB

	Locations[n].island = "KhaelRoa"; // NK 04-08-29

	n = n + 1;
	
	// -------------------------------------------------
	Locations[n].id = "Indian_Village2";
	locations[n].id.label = "Indian Village";
	Locations[n].filespath.models = "locations\Indian Village2";
	Locations[n].image = "Outside_indian_village.tga";

	//Sound
	locations[n].type = "indian_jungle";	
	//Models
	//Always
	Locations[n].models.always.locators = "village_locators";
	Locations[n].models.always.jungle = "village";
   	Locations[n].models.always.grassPatch = "village_grass";
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	
	//Day
	Locations[n].models.day.charactersPatch = "village_patch";
	//Night
	Locations[n].models.night.charactersPatch = "village_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";	
	

	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "KhaelRoa_Jungle_Fake_Bridge";
	Locations[n].reload.l1.emerge = "reload4_back";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Old Bridge";


	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "tipi";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "totem5";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "totem1";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "totem2";

	Locations[n].island = "KhaelRoa";
	
	n = n + 1;
	
	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_6";

	Locations[n].id = "Cuba_Jungle_02_fake";
	locations[n].id.label = "Jungle.";		//spell-checked by KAM
	Locations[n].image = "Outside_Jungle_6.tga";
	//Sound
	locations[n].type = "jungle";

	//Models
	//Always
	Locations[n].models.always.locators = "Jungle06_l";
	Locations[n].models.always.jungle = "Jungle06";
	Locations[n].models.always.grassPatch = "JUNGLE06_g";
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
	Locations[n].models.day.charactersPatch = "Jungle06_p";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle06_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	
/*	
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cuba_Shore_03";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 2.5;
	Locations[n].reload.l1.label = "Punta de Maisi";
*/
	/**/
	//cuba jung 3
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Tia_Dalma_swamp";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload2 = 2.5;
	Locations[n].reload.l2.label = "Jungle.";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Smugglers_Fort_fake";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.reload3 = 2.5;
	Locations[n].reload.l3.label = "Jungle.";

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Tia_Dalma_swamp";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].locators_radius.reload.reload2_back = 2.5;
	Locations[n].reload.l4.label = "Jungle.";

	Locations[n].reload.l5.name = "reload3_back";
	Locations[n].reload.l5.go = "Smugglers_Fort_fake";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].locators_radius.reload.reload3_back = 3;
	Locations[n].reload.l5.label = "Jungle.";
/*
	Locations[n].reload.l6.name = "reload1_back";
	Locations[n].reload.l6.go = "Cuba_Shore_03";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 2.5;
	Locations[n].reload.l6.label = "Punta de Maisi";
*/
	Locations[n].vcskip = true; // SEB
	
	Locations[n].island = "Antigua"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Pirate Fort";

	Locations[n].id = "Smugglers_Fort_fake";
	locations[n].id.label = "Smugglers Fort";
	Locations[n].image = "Pirate_Fort.tga";

	//Town sack
	Locations[n].townsack = "Smugglers Fort"; // NK 04-08-29

	//Sound
	locations[n].type = "jungle";

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
	Locations[n].reload.l1.go = "Cuba_Jungle_02_fake";
	Locations[n].reload.l1.emerge = "Reload1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].reload.l1.autoreload = 1;
	Locations[n].locators_radius.reload.reload1 = 1;

	Locations[n].reload.l5.name = "Reload1_back";
	Locations[n].reload.l5.go = "Cuba_Jungle_02_fake";
	Locations[n].reload.l5.emerge = "reload3_back";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].reload.l5.autoreload = 1;
	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].reload.l2.name = "Reload5";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "";
	Locations[n].reload.l2.label = "";

	Locations[n].reload.l3.name = "Reload6";
	Locations[n].reload.l3.go = "";
	Locations[n].reload.l3.emerge = "";
	Locations[n].reload.l3.label = "";

	Locations[n].vcskip = true; // SEB
	
	Locations[n].island = "Antigua"; // NK 04-08-29
	n = n + 1;
	
	
	//  -------------------------------------------------

	Locations[n].id = "SFSI_deck";
	locations[n].id.label = "Shipwreck";
	locations[n].filespath.models = "locations\decks\SfsiWreck";
	Locations[n].image = "Sfsi_wreck.tga";

	//Sound
	locations[n].type = "galleon_open";	
	//Models
	//Always
	Locations[n].models.always.locators = "jrh_deck_l";
	Locations[n].models.always.l1 = "SFSI_deck";
	
	Locations[n].models.always.windows = "windows_outside";			//outside windows
	Locations[n].models.always.windows.tech = "LocationWindows";
	Locations[n].models.always.windows.level = 65539;

	Locations[n].models.always.l3 = "grid_MD";
	Locations[n].models.always.l4 = "grid_FC";
	Locations[n].models.always.l5 = "SantaFlorentinaShipInside4_reflect";	//minor change here (sarg sänkt)
  	
	//Day
	Locations[n].models.day.charactersPatch = "jrh_patch";
	//Night
	Locations[n].models.night.charactersPatch = "jrh_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";	

	Locations[n].locators_radius.quest.S1_low = 0.8;
	Locations[n].locators_radius.quest.S1_high = 0.8;
	Locations[n].locators_radius.goto.S1A_up = 0.1;
	Locations[n].locators_radius.goto.S1B_up = 0.1;
	Locations[n].locators_radius.goto.S1C_up = 0.1;
	Locations[n].locators_radius.goto.S1D_up = 0.1;
	Locations[n].locators_radius.goto.S1E_up = 0.1;
	Locations[n].locators_radius.goto.S1A_down = 0.1;
	Locations[n].locators_radius.goto.S1B_down = 0.1;
	Locations[n].locators_radius.goto.S1C_down = 0.1;
	Locations[n].locators_radius.goto.S1D_down = 0.1;
	Locations[n].locators_radius.goto.S1E_down = 0.1;

	Locations[n].locators_radius.quest.S2_low = 0.8;
	Locations[n].locators_radius.quest.S2_high = 0.8;
	Locations[n].locators_radius.goto.S2A_up = 0.1;
	Locations[n].locators_radius.goto.S2B_up = 0.1;
	Locations[n].locators_radius.goto.S2C_up = 0.1;
	Locations[n].locators_radius.goto.S2D_up = 0.1;
	Locations[n].locators_radius.goto.S2E_up = 0.1;
	Locations[n].locators_radius.goto.S2A_down = 0.1;
	Locations[n].locators_radius.goto.S2B_down = 0.1;
	Locations[n].locators_radius.goto.S2C_down = 0.1;
	Locations[n].locators_radius.goto.S2D_down = 0.1;
	Locations[n].locators_radius.goto.S2E_down = 0.1;

	Locations[n].locators_radius.quest.S3_low = 0.8;
	Locations[n].locators_radius.quest.S3_high = 0.8;
	Locations[n].locators_radius.goto.S3A_up = 0.1;
	Locations[n].locators_radius.goto.S3B_up = 0.1;
	Locations[n].locators_radius.goto.S3C_up = 0.1;
	Locations[n].locators_radius.goto.S3D_up = 0.1;
	Locations[n].locators_radius.goto.S3A_down = 0.1;
	Locations[n].locators_radius.goto.S3B_down = 0.1;
	Locations[n].locators_radius.goto.S3C_down = 0.1;
	Locations[n].locators_radius.goto.S3D_down = 0.1;

	Locations[n].locators_radius.goto.S4A = 0.1;
	Locations[n].locators_radius.goto.S4B = 0.1;
	Locations[n].locators_radius.goto.S4C = 0.1;
	Locations[n].locators_radius.goto.S4D = 0.1;
	Locations[n].locators_radius.goto.S4E_up = 0.1;

	Locations[n].locators_radius.quest.Q1 = 0.8;

	//Locations[n].island = "Antigua";
	
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].id = "SFSI_deck_Dutchman";
	locations[n].id.label = "Shipwreck";
	locations[n].filespath.models = "locations\decks\SfsiWreck";
	Locations[n].image = "Sfsi_wreck.tga";

	//Sound
	locations[n].type = "galleon_open";	
	//Models
	//Always
	Locations[n].models.always.locators = "jrh_deck_dutchman";
	Locations[n].models.always.l1 = "SFSI_deck";
	
	Locations[n].models.always.windows = "windows_outside";			//outside windows
	Locations[n].models.always.windows.tech = "LocationWindows";
	Locations[n].models.always.windows.level = 65539;

	Locations[n].models.always.l3 = "grid_MD";
	Locations[n].models.always.l4 = "grid_FC";
	Locations[n].models.always.l5 = "SantaFlorentinaShipInside4_reflect";	//minor change here (sarg sänkt)
  	
	//Day
	Locations[n].models.day.charactersPatch = "jrh_patch";
	//Night
	Locations[n].models.night.charactersPatch = "jrh_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";	

	Locations[n].locators_radius.quest.S1_low = 0.8;
	Locations[n].locators_radius.quest.S1_high = 0.8;
	Locations[n].locators_radius.goto.S1A_up = 0.1;
	Locations[n].locators_radius.goto.S1B_up = 0.1;
	Locations[n].locators_radius.goto.S1C_up = 0.1;
	Locations[n].locators_radius.goto.S1D_up = 0.1;
	Locations[n].locators_radius.goto.S1E_up = 0.1;
	Locations[n].locators_radius.goto.S1A_down = 0.1;
	Locations[n].locators_radius.goto.S1B_down = 0.1;
	Locations[n].locators_radius.goto.S1C_down = 0.1;
	Locations[n].locators_radius.goto.S1D_down = 0.1;
	Locations[n].locators_radius.goto.S1E_down = 0.1;

	Locations[n].locators_radius.quest.S2_low = 0.8;
	Locations[n].locators_radius.quest.S2_high = 0.8;
	Locations[n].locators_radius.goto.S2A_up = 0.1;
	Locations[n].locators_radius.goto.S2B_up = 0.1;
	Locations[n].locators_radius.goto.S2C_up = 0.1;
	Locations[n].locators_radius.goto.S2D_up = 0.1;
	Locations[n].locators_radius.goto.S2E_up = 0.1;
	Locations[n].locators_radius.goto.S2A_down = 0.1;
	Locations[n].locators_radius.goto.S2B_down = 0.1;
	Locations[n].locators_radius.goto.S2C_down = 0.1;
	Locations[n].locators_radius.goto.S2D_down = 0.1;
	Locations[n].locators_radius.goto.S2E_down = 0.1;

	Locations[n].locators_radius.quest.S3_low = 0.8;
	Locations[n].locators_radius.quest.S3_high = 0.8;
	Locations[n].locators_radius.goto.S3A_up = 0.1;
	Locations[n].locators_radius.goto.S3B_up = 0.1;
	Locations[n].locators_radius.goto.S3C_up = 0.1;
	Locations[n].locators_radius.goto.S3D_up = 0.1;
	Locations[n].locators_radius.goto.S3A_down = 0.1;
	Locations[n].locators_radius.goto.S3B_down = 0.1;
	Locations[n].locators_radius.goto.S3C_down = 0.1;
	Locations[n].locators_radius.goto.S3D_down = 0.1;

	Locations[n].locators_radius.goto.S4A = 0.1;
	Locations[n].locators_radius.goto.S4B = 0.1;
	Locations[n].locators_radius.goto.S4C = 0.1;
	Locations[n].locators_radius.goto.S4D = 0.1;
	Locations[n].locators_radius.goto.S4E_up = 0.1;

	Locations[n].locators_radius.quest.Q1 = 0.8;

	//Locations[n].island = "Antigua";
	
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "Tortuga_tavern_fake";
	Locations[n].filespath.textures = "locations\inside\tavern01\Tortuga";
	//locations[n].id.label = "Tavern";
	locations[n].id.label = "The Dark Frigate";
	//Town sack
	Locations[n].townsack = "Tortuga";
	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "Tortuga";
	//Models

	Locations[n].filespath.models = "locations\Inside\Tavern01";
	Locations[n].image = "Inside_Tavern01_Tortuga.tga";
	//Models
	Locations[n].models.back = "back\tor_";					//JRH
	//Always
	Locations[n].models.always.cave = "Tavern01";
	Locations[n].models.always.locators = "Tavern01_locators_Tortuga_Fake";	//JRH
	Locations[n].models.always.window = "Tavern01_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Tavern01_patch";
	//Night
	Locations[n].models.night.charactersPatch = "Tavern01_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.emerge = "reload4_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.go = "Tortuga_port";
	Locations[n].reload.l1.label = "#stown_name#";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.go = "Tortuga_tavern_upstairs";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Room in #stown_name# tavern.";
	Locations[n].reload.l2.disable = true; // KK

//JRH -->
	Locations[n].locators_radius.randitem.randitem1 = 0.1;		
	Locations[n].items.randitem1 = "hatch16_T";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;		
	Locations[n].items.randitem2 = "hatch16_T";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;		
	Locations[n].items.randitem3 = "hatch16_V";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;		
	Locations[n].items.randitem4 = "door_Tortuga";

	Locations[n].locators_radius.randitem.randitem5 = 0.1;		
	Locations[n].items.randitem5 = "hatch16_T";

	Locations[n].locators_radius.randitem.randitem6 = 0.1;		
	Locations[n].items.randitem6 = "hatch16_V";

	Locations[n].locators_radius.randitem.randitem7 = 0.1;		
	Locations[n].items.randitem7 = "hatch16_T";

	Locations[n].locators_radius.randitem.randitem8 = 0.1;		
	Locations[n].items.randitem8 = "hatch16_T";

	Locations[n].locators_radius.randitem.randitem9 = 0.1;		
	Locations[n].items.randitem9 = "hatch16_V";

	Locations[n].locators_radius.randitem.randitem10 = 0.1;		
	Locations[n].items.randitem10 = "hatch16_T";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;		
	Locations[n].items.randitem11 = "door_N06T";
//<-- JRH
	Locations[n].vcskip = true; // SEB
	
	Locations[n].island = "Hispaniola"; // NK 04-08-29
	n = n + 1;	

}