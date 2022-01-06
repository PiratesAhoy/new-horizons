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
}