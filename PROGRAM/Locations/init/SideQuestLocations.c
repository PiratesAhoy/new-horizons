void LocationInitSideQuestLocations(ref n)
{


// SAVING TOFF'S DAUGHTER

	Locations[n].filespath.models = "locations\Decks\qdeck";
	Locations[n].image = "sea";

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

// ELIZABETH SHAW'S DISAPPEARENCE (Davy Jones First Contact quest)

	Locations[n].id = "Quest_Cayman_Port";
	locations[n].id.label = "#stown_name# Port";
	Locations[n].image = "Town_FalaiseDeFleur_Port2_England";

	//Town sack
	Locations[n].townsack = "Grand Cayman";

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

	Locations[n].island = "Cayman"; 
	n = n + 1;
	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_Douwesen\town";
	Locations[n].filespath.textures = "locations\ENGLAND";

	Locations[n].id = "Quest_Grand_Cayman_town";
	locations[n].id.label = "#stown_name#";
	Locations[n].image = "Town_Douwesen_Town_England";

	//Town sack
	Locations[n].townsack = "Grand Cayman";

	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "Grand_Cayman";
	//Models
	//Always
	Locations[n].models.always.locators = "DouTown_l";
	Locations[n].models.always.grassPatch = "DouTown_g";
	Locations[n].models.always.town = "DouTown";
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
	//Locations[n].models.day.rinok = "DouTown_e01";
	Locations[n].models.day.fonar = "DouTown_fd";
	Locations[n].models.day.charactersPatch = "DouTown_p";
	Locations[n].models.day.jumppatch = "DouTown_j";

	//Night
	Locations[n].models.night.fonar = "DouTown_fn";
	Locations[n].models.night.charactersPatch = "DouTown_p";
	Locations[n].models.night.jumppatch = "DouTown_j";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload9";
	Locations[n].reload.l1.go = "Quest_Cayman_port";
	Locations[n].reload.l1.emerge = "Falaise_de_fleur_location_01_05";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Sea port.";


	Locations[n].reload.l9.name = "reload15";
	Locations[n].reload.l9.go = ""; 
	Locations[n].reload.l9.emerge = "";
	Locations[n].reload.l9.label = "Residence.";

	Locations[n].vcskip = true; // PB

	Locations[n].island = "Cayman"; 
	n = n + 1;

// ELIZABETH SHAW'S DISAPPEARENCE (Davy Jones First Contact quest)


// FIND THE MISSING SON OF THE SPANISH ADMIRAL (Lucas Da Saldanha quest)

	Locations[n].id = "Ransom_house_f1";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "Locations\Inside\Doubleflour_house";
	Locations[n].image = "Inside_Doubleflour_House_Lower";

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
	Locations[n].image = "Inside_Doubleflour_House_Upper";

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
// FIND THE MISSING SON OF THE SPANISH ADMIRAL (Lucas Da Saldanha quest)

	//Santiago

	Locations[n].filespath.models = "locations\Decks\qdeck";
	Locations[n].image = "sea";

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

//Hitman SCM Changes

	//  -------------------------------------------------
	Locations[n].id = "Hit_house";
	Locations[n].id.label = "House of Mateus Santos";
	Locations[n].filespath.models = "locations\inside\Residence6";
	Locations[n].image = "Inside_Residence6";

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
	Locations[n].image = "Inside_Residence6_Study";

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
	Locations[n].image = "Inside_Residence6_Prison";

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
	Locations[n].image = "Inside_Residence1_Hitman";

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
	Locations[n].image = "Inside_Doubleflour_House_Hitman";

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

	// ----------------------------------------------
	Locations[n].id = "VogelStruijs";
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
	Locations[n].boarding = "false";

	n = n + 1;
	
	// ----------------------------------------------
	Locations[n].id = "VogelStruijs_Hold";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\decks\hold";
	Locations[n].image = "deck_hold";
	//Sound
	Locations[n].type = "deck";
	//Models
	//Always
	Locations[n].models.always.locators = "hold_ld";
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
	Locations[n].boarding = "false";
	
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Denielle_deck";
	Locations[n].filespath.models = "locations\Decks\qdeck";
	//Sound
	locations[n].type = "deck";
	Locations[n].image = "Sea";
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

//JRH: The mysterious plants

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\JinoRoom";

	Locations[n].id = "Cartagena_hotel_room1";
	locations[n].id.label = "Room 1";
	Locations[n].image = "Inside_JinoHotelRoom";

	//Town sack
	Locations[n].townsack = "Cartagena";

	//Sound
	locations[n].type = "Poe_home";
	
	//Models
	//Always
	Locations[n].models.always.locators = "JinoRoom_locators_hotel_open";
	Locations[n].models.always.l1 = "JinoRoom";
	Locations[n].models.always.window = "JinoRoom_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "JinoRoom_patch";

	//Night
	Locations[n].models.night.charactersPatch = "JinoRoom_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\turkJ_";
	
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cartagena Hotel";
	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 0.7;
	Locations[n].reload.l1.disable = 1;				//always locked from inside

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Cartagena_center_facade";
	Locations[n].reload.l3.emerge = "box7";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "Cartagena_Hotel_attic";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].locators_radius.reload.reload5 = 0.1;

	Locations[n].locators_radius.reload.reload4 = 0.001;
	Locations[n].locators_radius.box.box1 = 0.9;
	Locations[n].locators_radius.box.box2 = 0.001;
	Locations[n].locators_radius.box.box3 = 0.7;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.goto.goto1 = 2.0;

	LAi_LocationFightDisable(&Locations[n], true);
	LAi_LocationFantomsGen(&locations[n], false);	
	Locations[n].vcskip = true;
	Locations[n].island = "Colombia";
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\JinoRoom";

	Locations[n].id = "Cartagena_hotel_room2";
	locations[n].id.label = "Room 2";
	Locations[n].image = "Inside_JinoHotelRoom";

	//Town sack
	Locations[n].townsack = "Cartagena";

	//Sound
	locations[n].type = "Poe_home";
	
	//Models
	//Always
	Locations[n].models.always.locators = "JinoRoom_locators_hotel_closed";
	Locations[n].models.always.l1 = "JinoRoom";
	Locations[n].models.always.window = "JinoRoom_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "JinoRoom_patch";

	//Night
	Locations[n].models.night.charactersPatch = "JinoRoom_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\turkJ_";
	
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cartagena Hotel";
	Locations[n].reload.l1.emerge = "reload7";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 0.7;
	Locations[n].reload.l1.disable = 1;				//always locked from inside

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "Cartagena_Hotel_attic";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].locators_radius.reload.reload5 = 0.1;
	
	Locations[n].locators_radius.box.box1 = 0.9;
	Locations[n].locators_radius.box.box2 = 1.1;
	Locations[n].locators_radius.box.box3 = 0.7;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.goto.goto1 = 2.0;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_M11";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2= "hatch11";

	LAi_LocationFightDisable(&Locations[n], true);
	LAi_LocationFantomsGen(&locations[n], false);	
	Locations[n].vcskip = true;
	Locations[n].island = "Colombia";
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\JinoRoom";

	Locations[n].id = "Cartagena_hotel_room3";
	locations[n].id.label = "Room 3";
	Locations[n].image = "Inside_JinoHotelRoom";

	//Town sack
	Locations[n].townsack = "Cartagena";

	//Sound
	locations[n].type = "Poe_home";
	
	//Models
	//Always
	Locations[n].models.always.locators = "JinoRoom_locators_hotel_open";
	Locations[n].models.always.l1 = "JinoRoom";
	Locations[n].models.always.window = "JinoRoom_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "JinoRoom_patch";

	//Night
	Locations[n].models.night.charactersPatch = "JinoRoom_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\turkJ_";
	
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cartagena Hotel";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 0.7;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Cartagena_center_facade";
	Locations[n].reload.l4.emerge = "box4";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].locators_radius.reload.reload4 = 0.5;
	
	Locations[n].locators_radius.reload.reload3 = 0.001;
	Locations[n].locators_radius.reload.reload5 = 0.001;
	Locations[n].locators_radius.box.box1 = 0.9;
	Locations[n].locators_radius.box.box2 = 1.1;
	Locations[n].locators_radius.box.box3 = 0.7;
	Locations[n].locators_radius.box.box4 = 0.001;
	Locations[n].locators_radius.goto.goto4 = 2.5;

	LAi_LocationFightDisable(&Locations[n], true);
	LAi_LocationFantomsGen(&locations[n], false);	
	Locations[n].vcskip = true;
	Locations[n].island = "Colombia";
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\JinoRoom";

	Locations[n].id = "Cartagena_hotel_room4";
	locations[n].id.label = "Room 4";
	Locations[n].image = "Inside_JinoHotelRoom";

	//Town sack
	Locations[n].townsack = "Cartagena";

	//Sound
	locations[n].type = "Poe_home";
	
	//Models
	//Always
	Locations[n].models.always.locators = "JinoRoom_locators_hotel_closed_door";
	Locations[n].models.always.l1 = "JinoRoom";
	Locations[n].models.always.window = "JinoRoom_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "JinoRoom_patch";

	//Night
	Locations[n].models.night.charactersPatch = "JinoRoom_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\turkJ_";
	
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cartagena Hotel";
	Locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 0.7;
	Locations[n].reload.l1.disable = 1;				//always locked from inside

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Cartagena_Hotel_office";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Cartagena_center_facade";
	Locations[n].reload.l4.emerge = "box6";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].locators_radius.reload.reload4 = 0.5;
	
	Locations[n].locators_radius.box.box1 = 0.9;
	Locations[n].locators_radius.box.box2 = 1.1;
	Locations[n].locators_radius.box.box3 = 0.01;
	Locations[n].locators_radius.box.box4 = 0.01;
	Locations[n].locators_radius.goto.goto3 = 2.0;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_M11";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "door_N03";

	LAi_LocationFightDisable(&Locations[n], true);
	LAi_LocationFantomsGen(&locations[n], false);	
	Locations[n].vcskip = true;
	Locations[n].island = "Colombia";
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\flamhouse_office";

	Locations[n].id = "Cartagena_hotel_office";
	locations[n].id.label = "Office";
	Locations[n].image = "Inside_Flamhouse_Office";

	//Town sack
	Locations[n].townsack = "Cartagena";

	//Sound
	locations[n].type = "Poe_home";
	
	//Models
	//Always
	Locations[n].models.always.l1 = "SwensonRoom";
	Locations[n].models.always.window = "SwensonRoom_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 10;

	//Day
	Locations[n].models.day.charactersPatch = "SwensonRoom_patch";
	Locations[n].models.day.locators = "SwensonRoom_ld";

	//Night
	Locations[n].models.night.charactersPatch = "SwensonRoom_patch";
	Locations[n].models.night.locators = "SwensonRoom_ln";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\turkJ_";
	
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cartagena_Hotel_room4";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 0.7;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Cartagena Hotel";
	Locations[n].reload.l2.emerge = "reload5";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 0.001;			//0.7 when chair is removed 		

	Locations[n].locators_radius.box.box1 = 1.2;
	Locations[n].locators_radius.box.box3 = 0.8;
	Locations[n].locators_radius.sit.sit1 = 4.0;
	
	Locations[n].locators_radius.randitem.randitem1 = 0.8;
	Locations[n].items.randitem1 = "chair_45";

	LAi_LocationFightDisable(&Locations[n], true);
	LAi_LocationFantomsGen(&locations[n], false);	
	Locations[n].vcskip = true;
	Locations[n].island = "Colombia";
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "Cartagena_hotel_private";
	locations[n].id.label = "Private room";
//	Locations[n].image = "GB_hotel_room";
	Locations[n].image = "Inside_Doubleflour_House_Room";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "Poe_home";
	
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Doubleflour_house";
	Locations[n].models.always.locators = "LH_F2_l_hotel";
	Locations[n].models.always.tavern = "LH_F2";
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
	//Locations[n].models.back = "back\smumt_";		//this one existed
	Locations[n].models.back = "back\smumh_";		//added

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cartagena Hotel";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 0.001;	//0.8 when unlocked

	Locations[n].locators_radius.box.box1 = 1.3;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.8;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "hatch11D_O3";

	LAi_LocationFightDisable(&Locations[n], true);
	LAi_LocationFantomsGen(&locations[n], false);	
	Locations[n].vcskip = true;
	Locations[n].island = "Colombia"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "Cartagena_hotel_attic";
	locations[n].id.label = "Attic";
	Locations[n].filespath.models = "locations\inside\Corridor\\";
	Locations[n].filespath.textures = "locations\inside\Corridor\dark";

	Locations[n].image = "GB_sulfur_passage";

	//Sound
	locations[n].type = "silent_residence";
	
	//Models
	//Always
	Locations[n].models.always.locators = "StoreSmall_locators_hotel";			
	Locations[n].models.always.store = "StoreSmall";

	//Day
	Locations[n].models.day.charactersPatch = "StoreSmall_patch";

	//Night
	Locations[n].models.night.charactersPatch = "StoreSmall_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cartagena_hotel_room1";
	Locations[n].reload.l1.emerge = "box4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	Locations[n].locators_radius.reload.reload1 = 0.5;
	
	Locations[n].reload.l5.name = "reload2";
	Locations[n].reload.l5.go = "Cartagena_hotel_room2";
	Locations[n].reload.l5.emerge = "box4";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;		
	
	Locations[n].locators_radius.box.box1 = 0.0001;			//candle
	Locations[n].locators_radius.box.box2 = 0.0001;	
	Locations[n].locators_radius.box.box3 = 1.1;	

	Locations[n].locators_radius.randitem.randitem1 = 0.0001;
	Locations[n].items.randitem1 = "gatedoor_dark_stone";

	Locations[n].locators_radius.randitem.randitem2 = 0.0001;
	Locations[n].items.randitem2 = "gatedoor_dark_stone";

	Locations[n].locators_radius.randitem.randitem3 = 0.0001;
	Locations[n].items.randitem3 = "hatch2";

	Locations[n].locators_radius.randitem.randitem4 = 0.0001;
	Locations[n].items.randitem4 = "hatch2";

	Locations[n].locators_radius.randitem.randitem5 = 0.0001;
	Locations[n].items.randitem5 = "gatedoor_w_45";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Colombia";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Town_Cartagena\town";
	Locations[n].image = "Town_Cartagena_Town";

	Locations[n].id = "Cartagena_Center_facade";
	locations[n].id.label = "Cartagena town.";
	locations[n].worldmap = "Cartagena";
	Locations[n].vcskip = true;
	
	//Town sack
	Locations[n].townsack = "Cartagena";
		
	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], false);	

	//Models
	//Always
	Locations[n].models.always.locators = "cartTown_l_facade";
	Locations[n].models.always.town = "cartTown";
	Locations[n].models.always.tree = "tree";
	Locations[n].models.always.tree.locator.group = "locator";
	Locations[n].models.always.tree.locator.name = "001";

	//Day
	Locations[n].models.day.fonar = "ludeng";	
	Locations[n].models.day.charactersPatch = "cartTown_pd";

	//Night
	Locations[n].models.night.fonar = "ludeng";	
	Locations[n].models.night.charactersPatch = "cartTown_pd";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l12.name = "reload12";
	Locations[n].reload.l12.go = "Cartagena Hotel";
	Locations[n].reload.l12.emerge = "reload8";
	Locations[n].reload.l12.autoreload = "0";
	Locations[n].reload.l12.label = "Cartagena Hotel.";
	Locations[n].locators_radius.reload.reload12 = 0.5;

	Locations[n].reload.l13.name = "reload13";
	Locations[n].reload.l13.go = "Cartagena_Hotel_room1";
	Locations[n].reload.l13.emerge = "reload3";
	Locations[n].reload.l13.autoreload = "0";
	Locations[n].reload.l13.label = "Cartagena Hotel.";
	Locations[n].locators_radius.reload.reload13 = 0.5;

	Locations[n].reload.l14.name = "reload14";
	Locations[n].reload.l14.go = "Cartagena_Hotel_room4";
	Locations[n].reload.l14.emerge = "reload4";
	Locations[n].reload.l14.autoreload = "0";
	Locations[n].reload.l14.label = "Cartagena Hotel.";
	Locations[n].locators_radius.reload.reload14 = 0.5;

	Locations[n].reload.l15.name = "reload15";
	Locations[n].reload.l15.go = "Cartagena_Hotel_room2";
	Locations[n].reload.l15.emerge = "reload3";
	Locations[n].reload.l15.autoreload = "0";
	Locations[n].reload.l15.label = "Cartagena Hotel.";
	Locations[n].locators_radius.reload.reload15 = 0.5;

	Locations[n].reload.l16.name = "reload16";
	Locations[n].reload.l16.go = "Cartagena_Hotel_room3";
	Locations[n].reload.l16.emerge = "reload4";
	Locations[n].reload.l16.autoreload = "0";
	Locations[n].reload.l16.label = "Cartagena Hotel.";
	Locations[n].locators_radius.reload.reload16 = 0.5;			

	Locations[n].locators_radius.box.box1 = 0.001;			//climb derrick, not used here
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.box.box6 = 0.5;
	Locations[n].locators_radius.box.box7 = 0.5;

	Locations[n].island = "Colombia"; // NK 04-08-29	
	n = n + 1;

	//-------------------------------------------------
	// GR: for use with "Crystal Skull" quest
	//-------------------------------------------------
	Locations[n].id = "Guadeloupe_Indian_House";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\HutRoundInside";
	Locations[n].image = "Inside_IndianHome"; //Todo

	//Town sack
	Locations[n].townsack = "Pointe a Pitre";

	//Sound
	locations[n].type = "house";

	//Models
	//Always
	Locations[n].models.always.locators = "HutRoundInside2_locators";
	Locations[n].models.always.house = "HutRoundInside_noclock";

	//Day
	Locations[n].models.day.charactersPatch = "HutRoundInside_patch";
	//Locations[n].models.day.fonar = "SS_fn";

	//Night
	Locations[n].models.night.charactersPatch = "HutRoundInside_patch";
	//Locations[n].models.night.fonar = "SS_fn";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	
	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Guadeloupe_Jungle_02";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 0.6;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "carpet4";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "jars";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "jars";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Guadeloupe"; // NK 04-08-29
	n = n + 1;

	Locations[n].vcskip = true;

}
