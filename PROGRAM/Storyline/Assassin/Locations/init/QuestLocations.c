void LocationInitQuestLocations(ref n)
{
	Locations[n].id = "Quest_FDF_townhall";
	locations[n].id.label = "#stown_name# townhall";
	Locations[n].filespath.models = "locations\inside\Residence1";
	Locations[n].image = "Inside_Residence1.tga";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].models.always.locators = "res01_l";
	Locations[n].models.always.jungle = "res01";
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

	Locations[n].island = "FalaiseDeFleur"; // PB: To avoid errors
	n = n + 1;
//   -------------------------------------------------------
	Locations[n].id = "Quest_FDF_Center";
	locations[n].id.label = "#stown_name#";
	Locations[n].image = "Town_FalaiseDeFleur_Town_02.tga";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "town";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\town_02";
	Locations[n].filespath.textures = "locations\FRANCE";
	Locations[n].models.always.locators = "FF02_l_x";
	Locations[n].models.always.grassPatch = "FF02_g";
	Locations[n].models.always.city = "FF02";
		//Day
	Locations[n].models.day.fonar = "FF02_fd";
	Locations[n].models.day.charactersPatch = "FF02_pd";
	Locations[n].models.day.jumppatch = "FF02_j";
	Locations[n].models.day.rinok = "FF02_e01";
	//Night
	Locations[n].models.night.fonar = "FF02_fn";
	Locations[n].models.night.charactersPatch = "FF02_pn";
	Locations[n].models.night.jumppatch = "FF02_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	Locations[n].island = "FalaiseDeFleur"; // PB: To avoid errors
	n = n + 1;	
//   -------------------------------------------------------
	Locations[n].id = "Quest_FDF_CenterB";
	locations[n].id.label = "#stown_name#";
	Locations[n].image = "Town_FalaiseDeFleur_Town_02.tga";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "town";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\town_02";
	Locations[n].filespath.textures = "locations\FRANCE";
	Locations[n].models.always.locators = "FF02_l_xs";
	Locations[n].models.always.grassPatch = "FF02_g";
	Locations[n].models.always.city = "FF02";
		//Day
	Locations[n].models.day.fonar = "FF02_fd";
	Locations[n].models.day.charactersPatch = "FF02_pd";
	Locations[n].models.day.jumppatch = "FF02_j";
	Locations[n].models.day.rinok = "FF02_e01";
	//Night
	Locations[n].models.night.fonar = "FF02_fn";
	Locations[n].models.night.charactersPatch = "FF02_pn";
	Locations[n].models.night.jumppatch = "FF02_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map	
	Locations[n].reload.l1.name = "Falaise_de_fleur_location_03_02";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_02";
	Locations[n].reload.l1.emerge = "Falaise_de_fleur_location_02_03";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Slums.";
	
	Locations[n].island = "FalaiseDeFleur"; // PB: To avoid errors
	n = n + 1;
//   -------------------------------------------------------
	Locations[n].id = "Quest_FDF_church";
	locations[n].id.label = "#stown_name# church";
	Locations[n].image = "Inside_Church_inside.tga";
	Locations[n].filespath.models = "locations\inside\Church_inside";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "church";
	//Models
	//Always
	Locations[n].models.always.city = "Church";
	Locations[n].models.always.locators = "Church_l";
	Locations[n].models.always.window = "church_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
//	Locations[n].models.day.lamp = "FalaiseDeFleur05_day";
	Locations[n].models.day.charactersPatch = "Church_p";

	//Night
//	Locations[n].models.night.lamp = "FalaiseDeFleur05_night";
	Locations[n].models.night.charactersPatch = "Church_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Quest_FDF_CenterB";
	Locations[n].reload.l1.emerge = "home5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Center.";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "FalaiseDeFleur"; // PB: To avoid errors
	n = n + 1;
	
//--------------------------------------------------------------------------
	Locations[n].id = "Quest_ShipDeck2";
	locations[n].id.label = "Ship deck";
	//Info
	Locations[n].filespath.models = "locations\decks\udeck1";
	Locations[n].image = "Sea.tga";
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
	// Gun decks/cargo hold
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Quest_Deck1";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	
	Locations[n].vcskip = true;	

	n = n + 1;

//----------------------------------------------------------
	Locations[n].id = "Quest_Deck1";
	locations[n].id.label = "Upper cannons deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deck2";
	Locations[n].image = "deck_deck2.tga";
	//Sound
	Locations[n].type = "deck";
	Locations[n].camshuttle = 1;
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

	//Reload map
	// stair
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Quest_ShipDeck2";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	// bakbort door
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Quest_Deck3";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "0";	
	// starbort door
	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "";
	Locations[n].reload.l4.emerge = "";
	Locations[n].reload.l4.autoreload = "0";	
	Locations[n].reload.l4.label = "Gunpowder Storage";
	
	Locations[n].locators_radius.box.gunpowder_1 = 0.5;
	
	Locations[n].vcskip = true;	

	n = n + 1;

//--------------------------------------------------------
	Locations[n].id = "Quest_Deck3";
	locations[n].id.label = "Main cannons deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deck1";
	Locations[n].image = "deck_deck1.tga";
	//Sound
	Locations[n].type = "deck";
	Locations[n].camshuttle = 1;
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
	
	Locations[n].vcskip = true;	

	n = n + 1;

//--------------------------------------------------------------------

	Locations[n].id = "Quest_Hold1";
	locations[n].id.label = "Cargo hold";
	//Info
	Locations[n].filespath.models = "locations\decks\hold";
	Locations[n].image = "deck_hold.tga"; // KK
	//Sound
	Locations[n].type = "deck";
	Locations[n].camshuttle = 1;
	Locations[n].monsters = 0;	

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

	// Reload Map
	// stair
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Quest_Deck3";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	
	Locations[n].vcskip = true;	

	n = n + 1;

//Modified Hitman

	//  -------------------------------------------------
	Locations[n].id = "Hit_houseB";
	Locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\Residence6";
	Locations[n].image = "Inside_Residence6.tga";

	//Town sack
	Locations[n].townsack = "Redmond"; // NK 04-08-29
	Locations[n].island = "Redmond"; // NK 04-08-29
	
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Redmond";
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
	Locations[n].reload.l1.go = "Redmond_Town_04";
	Locations[n].reload.l1.emerge = "door_9";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";

	Locations[n].reload.l2.name = "Reload2"; //SCM
	Locations[n].reload.l2.go = "Hit_study"; //SCM
	Locations[n].reload.l2.emerge = "Reload1"; //SCM
	Locations[n].reload.l2.autoreload = "0"; //SCM
	Locations[n].reload.l2.label = "Study of Mateus Santos"; //SCM	
	LAi_LocationFightDisable(&Locations[n], true);
	
	n = n + 1;

	// ------------------------------------------------- SCM
	Locations[n].id = "Hit_study";
	Locations[n].id.label = "Study of Mateus Santos";
	Locations[n].filespath.models = "locations\inside\Residence6";
	Locations[n].image = "Inside_Residence6_Study.tga";

	//Town sack
	Locations[n].townsack = "Redmond"; // NK 04-08-29
	Locations[n].island = "Redmond"; // NK 04-08-29
	
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Redmond";
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
	Locations[n].reload.l1.go = "Hit_houseB";
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
	Locations[n].townsack = "Redmond"; // NK 04-08-29
	Locations[n].island = "Redmond"; // NK 04-08-29
	
	//Sound
	locations[n].type = "dungeon";
	locations[n].fastreload = "Redmond";
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
	Locations[n].reload.l1.go = "Redmond_church";
	Locations[n].reload.l1.emerge = "Reload3";
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

//Modified Hitman

// --------------------------------------

	//ID
	Locations[n].id = "Quest_Havana_fort";
	//Info
	Locations[n].filespath.models = "locations\Fort_Inside\Fort_1";
	Locations[n].filespath.textures = "locations\SPAIN";
	Locations[n].image = "Fort_Inside_Fort_1.tga";

	//Town sack
	Locations[n].townsack = "Havana";		//change
	//Sound
	locations[n].type = "town";

	//Models
	//Always
	Locations[n].models.always.locators = "fort1_l_ccc";
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

	//reload map.
	Locations[n].reload.l1.name = "reloadc3";
	Locations[n].reload.l1.go = "Havana_town_02";
	Locations[n].reload.l1.emerge = "reload9";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].island = "Cuba"; // PB: To avoid errors
	n = n + 1;
	
	//-----------------------------------------------------------------
	Locations[n].id = "Quest_Havana_Town_01";
	locations[n].id.label = "#stown_name#";
	Locations[n].filespath.models = "locations\Town_Redmond\Town_01";
	Locations[n].filespath.textures = "locations\SPAIN";
	Locations[n].image = "Town_Redmond_Town_01_Spain.tga";

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

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_IslaMuelle\town_01";
	Locations[n].filespath.textures = "locations\SPAIN";

	Locations[n].id = "Vera_Cruz_01";
	locations[n].id.label = "Vera Cruz. Plaza de Armas";
	Locations[n].image = "Town_IslaMuelle_Town_01_Spain.tga";

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

	Locations[n].island = "IslaMuelle"; // PB: To avoid errors
	n = n + 1;
	
	// Vera Cruz Port -------------------------------------------------
	Locations[n].id = "Vera_Cruz_Port";
	locations[n].id.label = "Vera Cruz port."; // KK
	Locations[n].image = "Town_FalaiseDeFleur_Port_Spain.tga";
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
	Locations[n].image = "Inside_mh5.tga";

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
	Locations[n].image = "Inside_MediumTavern.tga";

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

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_1";

	Locations[n].id = "Indian_Village";
	locations[n].id.label = "Indian Village";
	Locations[n].image = "Outside_Jungle_1.tga";
	//Sound
	locations[n].type = "jungle";

	//Models
	//Always
	Locations[n].models.always.locators = "jungle01_l";
	Locations[n].models.always.jungle = "jungle01";
	Locations[n].models.always.grassPatch = "jungle01_g";
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
	Locations[n].models.day.charactersPatch = "jungle01_p";
	//Night
	Locations[n].models.night.charactersPatch = "jungle01_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";		

    Build_at("Indian_Village", "hutindy", "", 14.132, 0, -6.424, -1.7, "building");
    Build_at("Indian_Village", "hutindy", "", 3.8, 0.49, -17.761, 0.15, "building");
    Build_at("Indian_Village", "hutindy", "", 12.934, 0, -16.151, -1.44, "building");
    Build_at("Indian_Village", "hutindy", "", -10.5, 0, 9.15, 0.96, "building");

	Locations[n].island = "IslaMuelle"; // PB: To avoid errors
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Shore_5";

	Locations[n].id = "Quest_Douwesen_shore";
	locations[n].id.label = "Palm Beach"; // KK
	Locations[n].image = "Outside_Shore_5.tga";
	Locations[n].name = "Palm Beach";

	//Sound
	locations[n].type = "seashore";
	//Models
	//Always
	Locations[n].models.always.jungle = "Shore05";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.locators = "Shore05_lbx";
	Locations[n].models.always.grassPatch = "Shore05_g";
	Locations[n].models.always.seabed = "Shore05_sb";
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
	Locations[n].models.day.charactersPatch = "Shore05_p";
	//Night
	Locations[n].models.night.charactersPatch = "Shore05_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	Locations[n].island = "Douwesen"; // PB: To avoid errors
	n = n + 1;
	
	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Smuggler Lair\Exit";
	Locations[n].filespath.textures = "locations\HOLLAND";

	Locations[n].id = "Quest_Oranjestad_exit";
	locations[n].id.label = "Exit from Oranjestad";
	Locations[n].image = "Smuggler_Lair_Exit.tga";

	//Town sack
	Locations[n].townsack = "Oranjestad";

	//Sound
	locations[n].type = "jungle";

	//Models
	//Always
	Locations[n].models.always.locators = "SmLexit_lx";
	Locations[n].models.always.exit = "SmLexit";
	Locations[n].models.always.grassPatch = "SmLexit_g";
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
	Locations[n].models.day.charactersPatch = "SmLexit_p";
	Locations[n].models.day.fonar = "SmLexit_fd";
	//Night
	Locations[n].models.night.charactersPatch = "SmLexit_p";
	Locations[n].models.night.fonar = "SmLexit_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Quest_Oranjestad_town";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Oranjestad.";
	Locations[n].reload.l3.disable = 1;	
	
	 Build_at("Quest_Oranjestad_exit", "Field_Cannon_1", "", -20.054, 0, -12.067, 2.4, "building");
     Build_at("Quest_Oranjestad_exit", "Field_Cannon_1", "", 7.248, 0, -15.027, 1.4, "building");

	Locations[n].island = "Aruba"; // PB: To avoid errors
	n = n + 1;
	
	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Smuggler Lair\town";
	Locations[n].filespath.textures = "locations\HOLLAND";
	
	Locations[n].id = "Quest_Oranjestad_town";
	locations[n].id.label = "Oranjestad";
	Locations[n].image = "Smuggler_Lair_Town.tga";

	//Town sack
	Locations[n].townsack = "Oranjestad";

	//Sound
	locations[n].type = "dungeon";

	//Models
	//Always
	Locations[n].models.always.locators = "SmL_lx";
	Locations[n].models.always.town = "SmL";
	Locations[n].models.always.grassPatch = "SmL_g";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan_3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	Locations[n].models.always.l4 = "plan_4";
	Locations[n].models.always.l4.level = 6;
	Locations[n].models.always.l4.tech = "LocationModelBlend";

	//Day
	Locations[n].models.day.charactersPatch = "SmL_p";
	Locations[n].models.day.fonar = "SmL_fd";
	Locations[n].models.day.jumppatch = "SmL_j";
	//Night
	Locations[n].models.night.charactersPatch = "SmL_p";
	Locations[n].models.night.fonar = "SmL_fn";
	Locations[n].models.night.jumppatch = "SmL_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Quest_Oranjestad_exit";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].island = "Aruba"; // PB: To avoid errors
	n = n + 1;

	//---------------------------------------------

	Locations[n].id = "Santiago_ship";
	locations[n].id.label = "Santiago ship";
	//Info
	Locations[n].filespath.models = "locations\decks\deckMedium";
	Locations[n].image = "sea.tga";
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

	//  -------------------------------------------------		
    Locations[n].filespath.models = "locations\Fort_Inside\FortVRight";
	
    Locations[n].id = "Quest_FortVRight";
	locations[n].id.label = "Fort";
	Locations[n].image = "Fort_Inside_FortVRight.tga";

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

	Locations[n].island = "Eleuthera"; // PB: To avoid errors
    n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Quest_Fort_prison";
	Locations[n].id.label = "#stown_name# prison";
	Locations[n].filespath.models = "locations\inside\Residence6";
	Locations[n].image = "Inside_Prison.tga";

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
	
	// -------------------------------------------------
	
    locations[n].id = "Quest_Alice";
	locations[n].id.label = "Alice Port";
	locations[n].filespath.models = "locations\Town_Alice";
	locations[n].image = "Town_Alice.tga";

	//Town sack
	locations[n].townsack = "Alice";
	//Sound
	locations[n].type = "town";
	//Models
	//Always
	locations[n].models.always.town = "Alice_Town";
	locations[n].models.always.L1 = "Alice_Town_signsA";
	Locations[n].models.always.seabed = "Alice_Town_sb";
	locations[n].models.always.locators = "Alice_Town_locators";
	locations[n].models.always.grassPatch = "Alice_Town_grass";

// Screwface : for water in fontain and millfan
	Locations[n].models.always.Waterfall2 = "fontain1";
	Locations[n].models.always.Waterfall2.uvslide.v0 = 0.5;
	Locations[n].models.always.Waterfall2.uvslide.v1 = 0.0;
	Locations[n].models.always.Waterfall2.tech = "LocationWaterFall";
	Locations[n].models.always.Waterfall2.level = 50;

	Locations[n].models.always.Waterfall1 = "fontain2";
	Locations[n].models.always.Waterfall1.uvslide.v0 = 0.2;
	Locations[n].models.always.Waterfall1.uvslide.v1 = 0.0;
	Locations[n].models.always.Waterfall1.tech = "LocationWaterFall";
	Locations[n].models.always.Waterfall1.level = 49;

	Locations[n].models.always.mill_movie = "MillFan";
	Locations[n].models.always.mill_movie.locator.group = "Windmill";
	Locations[n].models.always.mill_movie.locator.name = "fan";
	Locations[n].models.always.mill_movie.rotate.x = 0.0;
	Locations[n].models.always.mill_movie.rotate.y = 0.0;
	Locations[n].models.always.mill_movie.rotate.z = 1.0;
	Locations[n].models.always.mill_movie.tech = "dLightModel";
// Screwface : end
	
	//Day
	locations[n].models.day.fonar = "Alice_Town_fd";
	locations[n].models.day.charactersPatch = "Alice_Town_patch_day";
	locations[n].models.day.rinok = "Alice_Town_rinok";
	//Night
	locations[n].models.night.fonar = "Alice_Town_fn";
	locations[n].models.night.charactersPatch = "Alice_Town_patch_night";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
 
	Locations[n].island = "Eleuthera"; // PB: To avoid errors
	n = n + 1;
	
	// -------------------------------------------------	

	Locations[n].filespath.models = "locations\outside\Morro";

	Locations[n].id = "Morro_Fort";
	locations[n].id.label = "El Morro Fort."; // KK
	Locations[n].image = "Outside_Morro.tga";
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

	// Benavides Residence-------------------------------------------------
	Locations[n].id = "Quest_Havana_House_03";
	locations[n].id.label = "Residence";
	Locations[n].filespath.models = "locations\inside\Residence_BackHall";
	Locations[n].filespath.textures = "locations\SPAIN";
	Locations[n].image = "Inside_Residence_BackHall_Spain.tga";

	//Town sack
	Locations[n].townsack = "Havana";

	//Sound
	locations[n].type = "Residence";
	//Models
	//Always
	Locations[n].models.always.locators = "ResB_lx";
	Locations[n].models.always.l1 = "ResB";
	Locations[n].models.always.window = "ResB_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "ResB_p";
	Locations[n].models.day.lights.candles = "candelabrum_small";

	//Night
	Locations[n].models.night.charactersPatch = "ResB_p";
	Locations[n].models.night.lights.candles = "candelabrum_small";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redrsb_";

	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	//ccc LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].reload.l2.name = "reload1";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Town.";

	Locations[n].island = "Cuba"; // PB: To avoid errors
	n = n + 1;
	
	//------- Diablo's Deck-----------------------
	Locations[n].id = "Quest_ShipDeck5";
	locations[n].id.label = "Ship deck";
	//Info
	Locations[n].filespath.models = "locations\decks\deckMedium";
	Locations[n].image = "Sea.tga";
	//Sound
	Locations[n].type = "deck";
	Locations[n].lockCamAngle = 0.4;
	Locations[n].camshuttle = 1;
	Locations[n].fastreload = "ship";
	Locations[n].monsters = 0;

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
	
	Locations[n].vcskip = true;		

	n = n + 1;

	// -----------Beach near Vera Cruz--------------------
	Locations[n].filespath.models = "locations\Outside\Shore_4";

	Locations[n].id = "Vera_Cruz_Beach";
	locations[n].id.label = "Playa Blanca"; 
	Locations[n].image = "Outside_Shore_4.tga";
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
	Locations[n].image = "Sea.tga";
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
	Locations[n].filespath.models = "locations\Fort_Inside\Morro";
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

	Locations[n].island = "Cuba"; // PB: To avoid errors
	n = n + 1;	
	
	// Morro fort inside 2--------------------------------------
	Locations[n].id = "Quest_Morro_fort2";
	//Info
	Locations[n].filespath.models = "locations\Fort_Inside\Morrob";
	Locations[n].image = "Fort_Inside_Morrob.tga";

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

	Locations[n].island = "Cuba"; // PB: To avoid errors
	n = n + 1;

 	// -------------------------------------------------
	Locations[n].id = "Morro_warehouse";
	locations[n].id.label = "Morro warehouse";	
	Locations[n].filespath.models = "locations\inside\Warehouse";
	Locations[n].image = "Inside_Warehouse.tga";

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

	Locations[n].island = "Cuba"; // PB: To avoid errors
	n = n + 1;	
	
}