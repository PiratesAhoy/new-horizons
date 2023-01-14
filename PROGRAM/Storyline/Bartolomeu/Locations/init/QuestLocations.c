void LocationInitQuestLocations(ref n)
{
	// Retextured Santo Domingo
	Locations[n].filespath.models = "locations\town_Greenford\port";
	Locations[n].filespath.textures = "locations\SPAIN";
	Locations[n].image = "Town_Greenford_Port_Spain";

	Locations[n].id = "Quest_Domingo_port";
	locations[n].id.label = "Santo Domingo port.";

	//Town sack
	Locations[n].townsack = "Santo Domingo";

	//Sound
	locations[n].type = "port";
	locations[n].fastreload = "Santo_Domingo";
	//Models
	//Always
	Locations[n].models.always.locators = "GrPort_l_x";
	Locations[n].models.always.l1 = "GrPort";
	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.seabed = "GrPort_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "GrPort_g";
	Locations[n].models.always.add = "GrPort_SD"; // additional buildings - ccc may07 Location Remodeling Campaign
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
	Locations[n].reload.l1.go = "Hispaniola";
	Locations[n].reload.l1.emerge = "reload_3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Sea.";
	Locations[n].locators_radius.reload.Reload1 = 3.0;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Hispaniola";
	Locations[n].reload.l3.emerge = "reload_3";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Sea.";
	Locations[n].locators_radius.reload.reload1_back = 3.0;

	Locations[n].island = "Hispaniola"; // PB: To avoid errors
	n = n + 1;

	//---------------------------------------------

	//ID
	Locations[n].id = "Quest_Hold1";
	locations[n].id.label = "Cargo hold";
	//Info
	Locations[n].filespath.models = "locations\decks\hold";
	Locations[n].image = "deck_hold"; // KK
	//Sound
	Locations[n].type = "ship";
	Locations[n].lockCamAngle = 0.4;
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

	n = n + 1;

	//---------------------------------------------

	//ID
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
	Locations[n].models.always.locators = "deckBig_ld_x";
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

	//---------------------------------------------
// KK -->
	CopyAttributes(&Locations[n], &Locations[FindLocation("Charlestown_port")]);

	Locations[n].id = "Quest_Charlestown";
	Locations[n].index = n;
// <-- KK
	//Sound
	locations[n].type = "dungeon";	
	LAi_LocationFantomsGen(&locations[n], false);
	n = n + 1;

	//---------------------------------------------

	//ID
	Locations[n].id = "Santiago_ship";
	locations[n].id.label = "Santiago ship";
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

	//---------------------------------------------

	Locations[n].filespath.models = "locations\town_IslaMuelle\town_04";
	Locations[n].filespath.textures = "locations\SPAIN";

	Locations[n].id = "Muelle_Town_Quest";
	locations[n].id.label = "Center.";
	Locations[n].image = "Town_IslaMuelle_Town_04";

	//Town sack
	Locations[n].townsack = "Isla Muelle";

	//Sound
	locations[n].type = "town";
	//Models
	//Always
	Locations[n].models.always.locators = "Mu04_l_x";
	Locations[n].models.always.l1 = "Mu04";
	Locations[n].models.always.grassPatch = "Mu04_g";
	//Day
	Locations[n].models.day.fonar = "Mu04_fd";
	Locations[n].models.day.charactersPatch = "Mu04_pd";
	Locations[n].models.day.jumpPatch = "Mu04_j";
	//Night
	Locations[n].models.night.fonar = "Mu04_fn";
	Locations[n].models.night.charactersPatch = "Mu04_pn";
	Locations[n].models.night.jumpPatch = "Mu04_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map

	Locations[n].reload.l5.name = "reload9";
	Locations[n].reload.l5.go = "Major_house";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "House.";

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Muelle_town_exit";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].reload.l4.disable = 1;

	Locations[n].island = "IslaMuelle"; // PB: To avoid errors
	n = n + 1;

	//---------------------------------------------

	Locations[n].id = "Major_house";
	locations[n].id.label = "House";
	Locations[n].image = "Inside_Residence2";
	Locations[n].filespath.models = "locations\inside\Residence2";

	//Town sack
	Locations[n].townsack = "Isla Muelle";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Muelle";
	//Models
	//Always
	Locations[n].models.always.city = "Res02";
	Locations[n].models.always.locators = "Res02_l_ttt"; // entry for bedroom
	Locations[n].models.always.window = "Res02_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
//	Locations[n].models.day.lamp = "FalaiseDeFleur05_day";
	Locations[n].models.day.charactersPatch = "Res02_p";

	//Night
//	Locations[n].models.night.lamp = "FalaiseDeFleur05_night";
	Locations[n].models.night.charactersPatch = "Res02_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\mures2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Isla Muelle. Center.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Major_bedroom";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";

	Locations[n].island = "IslaMuelle"; // PB: To avoid errors
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "Major_bedroom";
	locations[n].id.label = "Bedroom";
	Locations[n].filespath.models = "locations\inside\ResBedRoom";
	Locations[n].image = "Inside_ResBedRoom";

	//Town sack
	Locations[n].townsack = "Isla Muelle";

	//Sound
	locations[n].type = "residence";
	//Models
	//Always
	Locations[n].models.always.locators = "bed_l_x"; //exit from window
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
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Residence";

	Locations[n].island = "IslaMuelle"; // PB: To avoid errors
	n = n + 1;
	
	//  -------------------------------------------------	
	
	locations[n].id = "Quest_Eleuthera_townhall";
	locations[n].id.label = "#stown_name# townhall";
	Locations[n].filespath.models = "locations\Inside\residence7";
	Locations[n].image = "Inside_Residence7";
	
	//Town sack
	locations[n].townsack = "Eleuthera";
	//Sound
	locations[n].type = "residence";	

	//Models
	Locations[n].models.back = "..\back\inside_back_";
	//Always
	Locations[n].models.always.cave = "res07";
	Locations[n].models.always.locators = "res07_locators_x";
	Locations[n].models.always.window = "res07_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "res07_patch";
	//Night
	Locations[n].models.night.charactersPatch = "res07_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";	
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.label = "";
	
	LAi_LocationFightDisable(&locations[n], true);

	Locations[n].island = "Eleuthera"; // PB: To avoid errors
	n = n + 1;

	//  -------------------------------------------------		
    Locations[n].filespath.models = "locations\Fort_Inside\FortVRight";
	
    Locations[n].id = "Quest_FortVRight";
	locations[n].id.label = "Fort";
	Locations[n].image = "Fort_Inside_FortVRight";

	//Town sack
	locations[n].townsack = "Eleuthera";

	//Sound
	locations[n].type = "jungle";

	//Models
	//Always
	Locations[n].models.always.locators = "FortVRight_locators_x";
	Locations[n].models.always.FortVRight = "FortVRight";
    Locations[n].models.always.grassPatch = "FortVRight_grass";
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	//Locations[n].models.always.attack = "FortVRight_attack";
	Locations[n].models.always.rock = "FortVRight_rock";
	Locations[n].models.always.sb = "FortVRight_sb";
	Locations[n].models.always.fd = "FortVRight_fd";
	Locations[n].models.always.fn = "FortVRight_fn";
	//Locations[n].models.always.lAttack = "FortVRight_lAttack";
    //Locations[n].models.always.patch = "FortVRight_patch";
        
	//Day
	Locations[n].models.day.charactersPatch = "FortVRight_patch";
	//Locations[n].models.day.fonar = "FortVRight_fd";
	//Night
	Locations[n].models.night.charactersPatch = "FortVRight_patch";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

    //Reloadmap
    Locations[n].reload.l1.name = "reload1";//"reload1";
	Locations[n].reload.l1.go = "Eleuthera_Jungle4";
	Locations[n].reload.l1.emerge = "reload2_back";//au lieu de 2
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle";
	Locations[n].locators_radius.reload.reload2 = 1;
	Locations[n].reload.l1.disable = 1;	

	Locations[n].reload.l2.name = "reload1_back";//"reload1_back";
	Locations[n].reload.l2.go = "Eleuthera_Jungle4";
	Locations[n].reload.l2.emerge = "reload2";//
	Locations[n].reload.l2.autoreload = "1";//
	Locations[n].reload.l2.label = "Jungle";
	Locations[n].locators_radius.reload.reload2_back = 3;
	Locations[n].reload.l2.disable = 1;	

    Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Quest_Fort_prison";
	Locations[n].reload.l3.emerge = "reload1_back";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Prison";
    Locations[n].reload.l3.disable = true;	

	Locations[n].island = "Eleuthera"; // PB: To avoid errors
    n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Quest_Fort_prison";
	Locations[n].id.label = "#stown_name# prison";
	Locations[n].filespath.models = "locations\inside\Residence6";
	Locations[n].image = "Inside_Prison";

	//Town sack
	Locations[n].townsack = "Eleuthera";	
	//Sound
	locations[n].type = "dungeon";
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
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Quest_FortVRight";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.label = "Fort";	

	Locations[n].island = "Eleuthera"; // PB: To avoid errors
	n = n + 1;

	//-----------------------------------------------------------------
	Locations[n].id = "Quest_Havana_Town_01";
	locations[n].id.label = "#stown_name#";
	Locations[n].filespath.models = "locations\Town_Redmond\Town_01";
	Locations[n].filespath.textures = "locations\SPAIN";
	Locations[n].image = "Town_Redmond_Town_01_Spain";

	//Town sack
	Locations[n].townsack = "Havana";

	//Sound
	locations[n].type = "town";
	//Models
	//Always
	Locations[n].models.always.L1 = "Red01";
	Locations[n].models.always.locators = "Red01_l_x";
	Locations[n].models.always.grassPatch = "Red01_g";
	//River
	Locations[n].models.always.dno = "Red01_rb01";
	Locations[n].models.always.dno.level = 95;
	Locations[n].models.always.dno.uvslide.u1 = -0.12;
	Locations[n].models.always.dno.uvslide.v1 = -0.03;
	Locations[n].models.always.dno.tech = "LocationRiverFloor";
	Locations[n].models.always.mirrow = "Red01_re01";
	Locations[n].models.always.mirrow.level = 96;
	Locations[n].models.always.dnoBlend = "Red01_rb01";
	Locations[n].models.always.dnoBlend.level = 97;
	Locations[n].models.always.dnoBlend.uvslide.u1 = -0.1;
	Locations[n].models.always.dnoBlend.uvslide.v1 = 0.04;
	Locations[n].models.always.dnoBlend.tech = "LocationRiverFloorBlend";
	Locations[n].models.always.river = "Red01_rt01";
	Locations[n].models.always.river.level = 98;
	Locations[n].models.always.river.uvslide.v0 = -0.1;
	Locations[n].models.always.river.uvslide.u1 = 0.15;
	Locations[n].models.always.river.tech = "LocationRiver";

	//Day
	Locations[n].models.day.fonar = "Red01_fd";
	Locations[n].models.day.charactersPatch = "Red01_p";
	Locations[n].models.day.rinok = "Red01_e01";
	//Night
	Locations[n].models.night.fonar = "Red01_fn";
	Locations[n].models.night.charactersPatch = "Red01_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
    Locations[n].reload.l13.name = "door_5";
	Locations[n].reload.l13.go = "";
	Locations[n].reload.l13.emerge = "";
	Locations[n].reload.l13.autoreload = "0";
	Locations[n].reload.l13.label = "Residence.";

	Locations[n].island = "Cuba"; // PB: To avoid errors
	n = n + 1;

	// -----------Beach near Vera Cruz--------------------
	Locations[n].filespath.models = "locations\Outside\Shore_4";

	Locations[n].id = "Vera_Cruz_Beach";
	locations[n].id.label = "Playa Blanca"; 
	Locations[n].image = "Outside_Shore_4";
	Locations[n].name = "Playa Blanca";
	//Sound
	locations[n].type = "seashore";

	//Models
	//Always
	Locations[n].models.always.locators = "Shore04_l";
	Locations[n].models.always.shore = "Shore04";
	Locations[n].models.always.shore.foam = "1";
	Locations[n].models.always.seabed = "Shore04_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "Shore04_g";
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
	Locations[n].models.day.charactersPatch = "Shore04_p";
	//Night
	Locations[n].models.night.charactersPatch = "Shore04_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.boat = 9.0;

	Locations[n].island = "IslaMuelle"; // PB: To avoid errors
	n = n + 1;

	//-------Morgan's Cabin---------------------
	Locations[n].id = "Quest_Cabin2"; // KK
	locations[n].id.label = "Captain's cabin";
	//Info
	Locations[n].filespath.models = "locations\decks\cabin\cabin01"; // KK
	Locations[n].image = "Deck_Cabin1"; // KK
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

// KK -->
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";
// <-- KK

	n = n + 1;
	
    //-------------Morgan' ship deck--------------------------------------------
	Locations[n].id = "Morgan_ShipDeck";
	locations[n].id.label = "Ship deck";
	//Info
	Locations[n].filespath.models = "locations\decks\udeck1";
	Locations[n].image = "Sea";
	//Sound
	locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;
	Locations[n].camshuttle = 1;
	Locations[n].monsters = 0;	

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
	//Reload map
	// Land on bakbort
	Locations[n].reload.l4.name = "boatl";
	Locations[n].reload.l4.go = "";
	Locations[n].reload.l4.emerge = "";
	Locations[n].reload.l4.autoreload = "0";	
	
	Locations[n].vcskip = true;	

	n = n + 1;
	
	// Morro fort inside 1--------------------------------------
	Locations[n].id = "Quest_Morro_fort1";
	//Info
	Locations[n].filespath.models = "locations\Fort_Inside\Morro\\";
	Locations[n].image = "Fort_Inside_Morro";

	//Town sack
	Locations[n].townsack = "Havana";		//change
	//Sound
	locations[n].type = "town";

	//Models
	//Always
	Locations[n].models.always.locators = "morro_l";
	Locations[n].models.always.l1 = "morro";
	Locations[n].models.always.l2 = "plan_1";
	Locations[n].models.always.l2.level = 9;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan_3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";	
	//Day
	Locations[n].models.day.charactersPatch = "morro_p";
	//Locations[n].models.day.fonar = "morro_fd";
	//Night
	Locations[n].models.night.charactersPatch = "morro_p";
	//Locations[n].models.night.fonar = "morro_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//reload map.
	Locations[n].reload.l1.name = "reloadc3";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";
	
	Locations[n].vcskip = true;
	
    Build_at("Quest_Morro_fort1", "boxes", "", 18.2, 0, 6.57, 1.6437, "Building");
    Build_at("Quest_Morro_fort1", "fence2", "", -9.799, 0, 19.535, -0.776, "Building");	
    Build_at("Quest_Morro_fort1", "box", "", -0.909, 0.5, 10.663, -0.743, "Building");
    Build_at("Quest_Morro_fort1", "box", "", -7.545, 0.5, 20.268, -0.743, "Building");   	
	
	n = n + 1;	
	
	// Morro fort inside 2--------------------------------------
	Locations[n].id = "Quest_Morro_fort2";
	//Info
	Locations[n].filespath.models = "locations\Fort_Inside\Morrob\\";
	Locations[n].image = "Fort_Inside_Morrob";

	//Town sack
	Locations[n].townsack = "Havana";		//change
	//Sound
	locations[n].type = "town";

	//Models
	//Always
	Locations[n].models.always.locators = "morro_lb";
	Locations[n].models.always.l1 = "morro";	
	//Day
	Locations[n].models.day.charactersPatch = "morro_pb";
	//Locations[n].models.day.fonar = "morro_fd";
	//Night
	Locations[n].models.night.charactersPatch = "morro_pb";
	//Locations[n].models.night.fonar = "morro_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	
	Locations[n].vcskip = true;		

	n = n + 1;

 	// -------------------------------------------------
	Locations[n].id = "Morro_warehouse";
	locations[n].id.label = "Morro warehouse";	
	Locations[n].filespath.models = "locations\inside\Warehouse\\";
	Locations[n].image = "Inside_Warehouse";

	//Town sack
	Locations[n].townsack = "Havana";

	//Sound
	locations[n].type = "shop";
	//Models
	//Always
	Locations[n].models.always.locators = "warehouse_l";
	Locations[n].models.always.shipyard = "warehouse";
	Locations[n].models.always.trone = "throne";
	Locations[n].models.always.trone.locator.group = "goto";
	Locations[n].models.always.trone.locator.name = "goto7";		
	//Day
	Locations[n].models.day.charactersPatch = "warehouse_p";
	//Night
	Locations[n].models.night.charactersPatch = "warehouse_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	n = n + 1;	

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_IslaMuelle\town_01";
	Locations[n].filespath.textures = "locations\SPAIN";

	Locations[n].id = "Vera_Cruz_01";
	locations[n].id.label = "Vera Cruz. Plaza de Armas";
	Locations[n].image = "Town_IslaMuelle_Town_01_Spain";

	//Town sack
	Locations[n].townsack = "Havana";	
	//Sound
	locations[n].type = "town";
	//Models
	//Always
	Locations[n].models.always.l1 = "Mu01";
	Locations[n].models.always.locators = "Mu01_l_x";
	Locations[n].models.always.grassPatch = "Mu01_g";
	Locations[n].models.always.mercado = "market";
	Locations[n].models.always.mercado.locator.group = "goto";
	Locations[n].models.always.mercado.locator.name = "goto1";	
	//Day
	Locations[n].models.day.rinok = "Mu01_e1";
	Locations[n].models.day.fonar = "Mu01_fd";
	Locations[n].models.day.jumppatch = "Mu01_j";
	Locations[n].models.day.charactersPatch = "Mu01_pd";
	//Night
	Locations[n].models.night.fonar = "Mu01_fn";
	Locations[n].models.night.charactersPatch = "Mu01_pn";
	Locations[n].models.night.jumppatch = "Mu01_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Vera_Cruz_Port";
	Locations[n].reload.l2.emerge = "Falaise_de_fleur_location_01_02";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name#.";

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Vera_Cruz_Port";
	Locations[n].reload.l3.emerge = "Falaise_de_fleur_location_01_02";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload2_back = 1.5;

	Locations[n].reload.l11.name = "reload14";
	Locations[n].reload.l11.go = "Vera_Cruz_Tavern";
	Locations[n].reload.l11.emerge = "reload1";
	Locations[n].reload.l11.autoreload = "0";
	Locations[n].reload.l11.label = "Tavern.";
	
	Locations[n].reload.l12.name = "reload25";
	Locations[n].reload.l12.go = "Vera_Cruz_House_1";
	Locations[n].reload.l12.emerge = "reload1";
	Locations[n].reload.l12.autoreload = "0";
	Locations[n].reload.l12.label = "Agilo Casamayor's house";	

	Locations[n].island = "IslaMuelle"; // PB: To avoid errors
	n = n + 1;
	
	// Vera Cruz Port -------------------------------------------------
	Locations[n].id = "Vera_Cruz_Port";
	locations[n].id.label = "Vera Cruz port."; // KK
	Locations[n].image = "Town_FalaiseDeFleur_Port_Spain";
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\port";
	Locations[n].filespath.textures = "locations\SPAIN";

	//Town sack
	Locations[n].townsack = "Havana";	
	//Sound
	locations[n].type = "port";
	//Models
	//Always
	Locations[n].models.always.city = "FFport01";
	Locations[n].models.always.city.foam = "1";
	Locations[n].models.always.seabed = "FFport01_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.locators = "FFport01_l";
	Locations[n].models.always.grassPatch = "FFport01_g";
	Locations[n].models.always.fishing = "fishingpier1";
	Locations[n].models.always.fishing.locator.group = "goto";
	Locations[n].models.always.fishing.locator.name = "goto20";		
 	//Day
	Locations[n].models.day.fonar = "FFport01_fd";
	Locations[n].models.day.charactersPatch = "FFport01_p";
	Locations[n].models.day.jumpPatch = "FFport01_j";
	//Night
	Locations[n].models.night.fonar = "FFport01_fn";
	Locations[n].models.night.charactersPatch = "FFport01_p";
	Locations[n].models.night.jumpPatch = "FFport01_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	LAi_LocationFantomsGen(&locations[n], true);
	Locations[n].reload.l1.name = "Falaise_de_fleur_location_01_02";
	Locations[n].reload.l1.go = "Vera_Cruz_01";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Vera Cruz town";
	
	Locations[n].reload.l6.name = "shipyard";
	Locations[n].reload.l6.go = "VeraCruz_Headporthouse";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Head port house.";

	Locations[n].island = "IslaMuelle"; // PB: To avoid errors
	n = n + 1;
	
	// -------------------------------------------------

	Locations[n].id = "VeraCruz_Headporthouse";
	locations[n].id.label = "Head port house";
	//Sound
	Locations[n].filespath.models = "locations\inside\mh5";
	Locations[n].image = "Inside_mh5";

	//Town sack
	Locations[n].townsack = "Havana";

	//Sound
	locations[n].type = "house";
	//Models
	Locations[n].models.always.locators = "mh5_l";
	Locations[n].models.always.house = "mh5";
	Locations[n].models.always.window = "mh5_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "mh5_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh5_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\ffmh5_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Vera_Cruz_port";
	Locations[n].reload.l1.emerge = "shipyard";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Vera Cruz Port.";

	Locations[n].vcskip = true; // KK
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "IslaMuelle"; // PB: To avoid errors
	n = n + 1;

// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\MediumTavern";

	Locations[n].id = "Vera_Cruz_Tavern";
	locations[n].id.label = "Vera Cruz Tavern";
	Locations[n].image = "Inside_MediumTavern";

	//Town sack
	Locations[n].townsack = "Havana";
	//Sound
	locations[n].type = "tavern";
	//Models
	//Always
	Locations[n].models.always.locators = "MT_l";
	Locations[n].models.always.l1 = "MT";
	Locations[n].models.always.window = "MT_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "MT_p";

	//Night
	Locations[n].models.night.charactersPatch = "MT_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\grmt_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Vera_Cruz_01";
	Locations[n].reload.l1.emerge = "reload14";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Vera Cruz town";

	LAi_LocationFightDisable(&Locations[n], true);
	
    Build_at("Vera_Cruz_Port", "jungle2", "", 58.382, 3.32, 36, 0, "building");
    Build_at("Vera_Cruz_Port", "Keep3", "", 40.316, 11.08, -4.21, 0, "building");	
    Build_at("Vera_Cruz_01", "fence", "",  -25.565, 0, 10.07, -3, "");	

	Locations[n].island = "IslaMuelle"; // PB: To avoid errors
	n = n + 1;

	// Agilo Casamayor's house-----------------------------------------

	Locations[n].filespath.models = "locations\Inside\mh8";

	Locations[n].id = "Vera_Cruz_House_1";
	locations[n].id.label = "House.";
	Locations[n].image = "Inside_mh8";

	//Town sack
	Locations[n].townsack = "Havana";

	//Sound
	locations[n].type = "house";
	//Models
	//Always
	Locations[n].models.always.locators = "mh8_l";
	Locations[n].models.always.house = "mh8";
	//Locations[n].models.always.env = "smallhome_FF_02_env";
	Locations[n].models.always.window = "mh8_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "mh8_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh8_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\comh8_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Vera_Cruz_01";
	Locations[n].reload.l1.emerge = "reload25";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Vera Cruz town";

	Locations[n].locators_radius.camdetector.camera1 = 3.0;
	Locations[n].locators_radius.camdetector.camera2 = 1.8;

	Locations[n].island = "IslaMuelle"; // PB: To avoid errors
	n = n + 1;

	// Vera Cruz Fort-----------------------------------------	
	//ID
	Locations[n].id = "Vera Cruz Fort";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_1\\";
	Locations[n].image = "Fort_Inside_Fort_1"; // KK

	//Town sack
	Locations[n].townsack = "Havana";
	//Sound
	locations[n].type = "town";

	//Models
	//Always
	Locations[n].models.always.locators = "fort1_l_bart";
	Locations[n].models.always.l1 = "fort1";
	Locations[n].models.always.trone = "throne";
	Locations[n].models.always.trone.locator.group = "goto";
	Locations[n].models.always.trone.locator.name = "goto10";			
	//Day
	Locations[n].models.day.charactersPatch = "fort1_p";
	Locations[n].models.day.fonar = "fort1_fd";
	//Night
	Locations[n].models.night.charactersPatch = "fort1_p";
	Locations[n].models.night.fonar = "fort1_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//reload map.
	Locations[n].reload.l1.name = "reloadc2";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reloadC4";
	Locations[n].reload.l2.go = "VeraCruz_armory";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l3.name = "reloadc5";
	Locations[n].reload.l3.go = "";
	Locations[n].reload.l3.emerge = "";

	Locations[n].island = "IslaMuelle"; // PB: To avoid errors
	n = n + 1;
	
	// ccc Antigua armory-------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\LargeStore";
	Locations[n].id = "VeraCruz_armory";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";
	Locations[n].image = "Inside_LargeStore";

	//Town sack
	Locations[n].townsack = "Havana";
	//Sound
	locations[n].type = "town";

	//Models
	//Always
	Locations[n].models.always.locators = "LS_l_ccc";
	Locations[n].models.always.tavern = "LS";
	//Locations[n].models.always.env = "largestore_env";
	Locations[n].models.always.window = "LS_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	Locations[n].models.always.fonar = "ls_fn";

	//Day
	Locations[n].models.day.charactersPatch = "LS_p";

	//Night
	Locations[n].models.night.charactersPatch = "LS_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\douls_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "";
	Locations[n].reload.l3.emerge = "";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].island = "IslaMuelle"; // PB: To avoid errors
	n = n + 1;

	// -------------------------------------------------	

	Locations[n].filespath.models = "locations\outside\Morro";

	Locations[n].id = "Morro_Fort";
	locations[n].id.label = "El Morro Fort."; // KK
	Locations[n].image = "Fort_Inside_Morro";
	//Sound
	locations[n].type = "seashore";
	//Models
	//Always
	Locations[n].models.always.locators = "morro_l";
	Locations[n].models.always.shore = "morro";
	Locations[n].models.always.shore.foam = "1";
//	Locations[n].models.always.seabed = "morro_sb";
//	Locations[n].models.always.seabed.foam = "1";
//	Locations[n].models.always.grassPatch = "morro_g";
	Locations[n].models.always.morro = "MorroFort";
	Locations[n].models.always.morro.locator.group = "reload";
	Locations[n].models.always.morro.locator.name = "reload5";	
	//Day
	Locations[n].models.day.charactersPatch = "morro_p";
	//Night
	Locations[n].models.night.charactersPatch = "morro_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	Locations[n].locators_radius.reload.Reload1 = 3.0;

	Locations[n].reload.l4.name = "reload5";
	Locations[n].reload.l4.go = "";
	Locations[n].reload.l4.emerge = "";
	Locations[n].reload.l4.label = "";
//	Locations[n].reload.l4.close_for_night = 1;
	Locations[n].reload.l4.disable = 1;
	
	Build_at("Morro_Fort", "bastion2", "", 77.019, 26.267, -218.54, 0, "Building");
	Build_at("Morro_Fort", "jungle", "", 92.747, 7.1396, -437.42, -1.2798, "Building");
	Build_at("Morro_Fort", "shipyard", "", -28.739, 1.0908, -446, -0.77, "Building");
	Build_at("Morro_Fort", "barracks", "", -10.054, 1.427, -396.47, -1.6468, "Building");
    Build_at("Morro_Fort", "tent", "", 121.41, 26.644, -179.63, -1.5, "Building");
    Build_at("Morro_Fort", "tent", "", 87.05, 29.605, -180, -1.5, "Building");
    Build_at("Morro_Fort", "tent", "", 49.927, 31.178, -182.62, -1.5, "Building");
    Build_at("Morro_Fort", "tent", "", 15.903, 31.439, -186.09, -1.5, "Building");
    Build_at("Morro_Fort", "tent", "", -0.324, 33.099, -140.59, -1.5, "Building");
    Build_at("Morro_Fort", "tent", "", 31.049, 33.156, -130.62, -1.5, "Building");
    Build_at("Morro_Fort", "tent", "", 72.548, 32.47, -117.27, -1.5, "Building");
    Build_at("Morro_Fort", "tent", "", 106.96, 31.443, -110.27, -1.5, "Building");
    Build_at("Morro_Fort", "Field_Cannon_2", "", 22.421, 32.504, -154.62, -1.5, "Building");
    Build_at("Morro_Fort", "Field_Cannon_2", "", 100.58, 30.348, -142.78, -1.5, "Building");
    Build_at("Morro_Fort", "pit", "", 92.347, 30.826, -143.51, 0, "Building");
    Build_at("Morro_Fort", "pit", "", 30.594, 32.449, -155.09, 0, "Building");	

	Locations[n].island = "IslaMuelle"; // PB: To avoid errors
	n = n + 1;		
	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Isle";

	Locations[n].id = "Ilot";
	locations[n].id.label = "The Lost Islet";
	Locations[n].image = "Outside_Isle";
	//Sound
	locations[n].type = "seashore";

	//Models
	//Always
	Locations[n].models.always.locators = "isle_l";
	Locations[n].models.always.jungle = "isle";

	//Day
	Locations[n].models.day.charactersPatch = "isle_p";
	//Night
	Locations[n].models.night.charactersPatch = "isle_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	
	n = n + 1;
	
	// San Martin Deck-------------------------------------------------
	//ID
	Locations[n].id = "Quest_ShipDeck6Bis";
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
	Locations[n].models.always.locators = "deckBigB_ld";
	Locations[n].models.always.l1 = "deckBig";
	//Day
	Locations[n].models.day.charactersPatch = "deckBigB_p";
	Locations[n].models.day.fonar = "deckBig_fd";
	//Night
	Locations[n].models.night.charactersPatch = "deckBigB_p";
	Locations[n].models.night.fonar = "deckBig_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	
	n = n + 1;	
//-------------------------------------------------------------------
//JRH test location for boulder
	Locations[n].filespath.models = "locations\Inside\Dungeon_4";
	Locations[n].id = "boulder_tunnel";
	Locations[n].image = "wr_dungeon4_loop";
	locations[n].id.label = "Port Royal old mine";

	//Sound
//	locations[n].type = "Rogers_mine";
	locations[n].type = "Vane_silent_temple";
	//Models
	Locations[n].models.back = "back\d04env_";
	//Always
	Locations[n].models.always.locators = "d04_l_JRH_ON1";		//old always
	Locations[n].models.always.house = "d04";
	//Day
	Locations[n].models.day.charactersPatch = "d04_p";
	//Night
	Locations[n].models.night.charactersPatch = "d04_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	
	//Reload map

	//back from loop X to Z
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "wr_dungeon4_main";
	Locations[n].reload.l3.emerge = "goto2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Port Royal old mine.";
	Locations[n].locators_radius.reload.reload3 = 2.0;

	//rope to guard room
	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "wr_prison_guard";
	Locations[n].reload.l7.emerge = "reload3";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Guard room";

	Locations[n].locators_radius.goto.goto3 = 1.5;
	Locations[n].locators_radius.goto.goto6 = 1.5;
	Locations[n].locators_radius.goto.goto7 = 3.0;
	Locations[n].locators_radius.goto.goto9 = 1.0;

	Locations[n].locators_radius.goto.skel5 = 1.5;
	Locations[n].locators_radius.goto.skel6 = 1.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "gatedoor_small_N06";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "gatedoor_small_N06";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "gatedoor_small_N06";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "rope_vertical";

	Locations[n].locators_radius.randitem.randitem5 = 0.1;
	Locations[n].items.randitem5 = "gateroof_white_stone";

	Locations[n].locators_radius.randitem.randitem6 = 0.1;
	Locations[n].items.randitem6 = "hatch10";

	Locations[n].locators_radius.randitem.randitem7 = 0.1;
	Locations[n].items.randitem7 = "gateroof_wood";

	Locations[n].locators_radius.randitem.randitem8 = 0.1;
	Locations[n].items.randitem8 = "hatch11D";

	Locations[n].locators_radius.randitem.randitem9 = 0.1;
	Locations[n].items.randitem9 = "gatedoor_small_N06";

	Locations[n].locators_radius.randitem.randitem10 = 0.1;
	Locations[n].items.randitem10 = "gatedoor_small_N06";

	Locations[n].locators_radius.randitem.randitem11 = 0.1;		
	Locations[n].items.randitem11 = "gatedoor_small_N06";

	Locations[n].locators_radius.randitem.randitem12 = 0.5;
	Locations[n].items.randitem12 = "bladeaxe4";

	Locations[n].locators_radius.randitem.randitem13 = 0.01;
	Locations[n].items.randitem13 = "skull2";			

	Locations[n].locators_radius.randitem.randitem14 = 0.01;
	Locations[n].items.randitem14 = "skull2";

	Locations[n].locators_radius.randitem.randitem15 = 0.01;
	Locations[n].items.randitem15 = "skull2";

	Locations[n].locators_radius.randitem.randitem16 = 0.01;
	Locations[n].items.randitem16 = "gatedoor_small_N06";

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;
	
}
