void LocationInitColombia(ref n)
{
	// -------------------------------------------------
	Locations[n].id = "Residence_Cartagena";
	locations[n].id.label = "Residence.";
	locations[n].worldmap = "Cartagena";
	Locations[n].image = "Town_Cartagena_Residence.tga";
	Locations[n].vcskip = true;
	//Town sack
	Locations[n].townsack = "Cartagena";
	locations[n].fastreload = "Cartagena";	
	//Sound
	locations[n].type = "town";
	locations[n].soundskip = true;
	//Models
	Locations[n].filespath.models = "locations\Town_Cartagena\Residence";
	Locations[n].models.always.locators = "Townhall_l";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.8; // screwface

	//Always
	Locations[n].models.always.grassPatch = "Townhall_g";
	Locations[n].models.always.l1 = "Townhall";
	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.l2 = "Townhall_sb";
	Locations[n].models.always.l2.foam = "1";
	Locations[n].models.always.pedra = "pierre";
	Locations[n].models.always.pedra.locator.group = "goto";
	Locations[n].models.always.pedra.locator.name = "goto25";
	Locations[n].models.always.pedrab = "pierre2";
	Locations[n].models.always.pedrab.locator.group = "goto";
	Locations[n].models.always.pedrab.locator.name = "goto26";
	Locations[n].models.always.pedrac = "pierre3";
	Locations[n].models.always.pedrac.locator.group = "goto";
	Locations[n].models.always.pedrac.locator.name = "goto27";
	Locations[n].models.always.l3 = "fontain1";
	Locations[n].models.always.l3.locator.group = "randitem";
	Locations[n].models.always.l3.locator.name = "randitem1";
	Locations[n].models.always.l3.uvslide.u0 = 0.0005;
	Locations[n].models.always.l3.uvslide.v0 = 0.2;
	Locations[n].models.always.l3.level = 999;
	Locations[n].models.always.l3.tech = "LocationWaterFall";
	Locations[n].models.always.l4 = "fontain2";
	Locations[n].models.always.l4.locator.group = "randitem";
	Locations[n].models.always.l4.locator.name = "randitem2";
	Locations[n].models.always.l4.uvslide.u0 = 0.04;
	Locations[n].models.always.l4.uvslide.v0 = 0.01;
	Locations[n].models.always.l4.level = 999;
	Locations[n].models.always.l4.tech = "LocationWaterFall";
	Locations[n].models.always.l5 = "fontain1";
	Locations[n].models.always.l5.locator.group = "randitem";
	Locations[n].models.always.l5.locator.name = "randitem3";
	Locations[n].models.always.l5.uvslide.u0 = 0.0005;
	Locations[n].models.always.l5.uvslide.v0 = 0.2;
	Locations[n].models.always.l5.level = 999;
	Locations[n].models.always.l5.tech = "LocationWaterFall";
	Locations[n].models.always.l6 = "fontain2";
	Locations[n].models.always.l6.locator.group = "randitem";
	Locations[n].models.always.l6.locator.name = "randitem4";
	Locations[n].models.always.l6.uvslide.u0 = 0.04;
	Locations[n].models.always.l6.uvslide.v0 = 0.01;
	Locations[n].models.always.l6.level = 999;
	Locations[n].models.always.l6.tech = "LocationWaterFall";		
	//Day
	Locations[n].models.day.charactersPatch = "Townhall_pd";
	//Night
	Locations[n].models.night.charactersPatch = "Townhall_pn";

	//Reload map
	Locations[n].reload.l5.go = "Cartagena_townhall";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.name = "reload3_back";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Residence.";
	Locations[n].reload.l5.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l5.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l10.go = "Cartagena_town_02";
	Locations[n].reload.l10.emerge = "Falaise_de_fleur_location_02_01";
	Locations[n].reload.l10.label = "Town.";
	Locations[n].reload.l10.name = "gate";
	Locations[n].reload.l10.autoreload = "0";

	Build_at("Residence_Cartagena", "farm", "", -11.864, 7.01, -40.385, 1.7, "Building");
	Build_at("Residence_Cartagena", "windmill", "", -18.434, 12, -55.73, 0.0, "Building");
	Build_at("Residence_Cartagena", "hedgerow", "", 30.087, 3.01, -32.243, 2.0, "Building");
	Build_at("Residence_Cartagena", "hedgerow", "", 1.2461, 2.01, -17.081, 2.0, "Building");
	Build_at("Residence_Cartagena", "hedgerow2", "", -25.873, 2.01, 23.558, 1.5, "Building");
	Build_at("Residence_Cartagena", "hedgerow2", "", 30.24, 2.01, 32.578, 0.0, "Building");

	Locations[n].island = "Colombia";
	n = n + 1;

// -----------------------------------------------------------------
	Locations[n].filespath.models = "locations\Town_Cartagena\Port";
	Locations[n].filespath.textures = "locations\SPAIN";
	Locations[n].image = "Town_Cartagena_Port.tga";

	Locations[n].id = "Cartagena_port";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].id.label = "#stown_name# port."; // KK
	locations[n].worldmap = "Cartagena";

	//Town sack
	Locations[n].townsack = "Cartagena";
	locations[n].fastreload = "Cartagena";	
	//Sound
	locations[n].type = "port";
//	locations[n].fastreload = "Cartagena";
	//Models
	//Always
	Locations[n].models.always.SanFelipe = "SanFelipe";
	Locations[n].models.always.locators = "CartPort_l";
	Locations[n].models.always.grassPatch = "CartPort_g";
	Locations[n].models.always.l1 = "CartPort";
	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.l2 = "CartPort_sb";
	Locations[n].models.always.l2.foam = "1";
	//Day
//	Locations[n].models.day.rinok = "CartPort_e1";
	Locations[n].models.day.fonar = "CartPort_fd";
	Locations[n].models.day.charactersPatch = "CartPort_pd";
	//Night
	Locations[n].models.night.fonar = "CartPort_fn";
	Locations[n].models.night.charactersPatch = "CartPort_pn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map

	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Cartagena_town_01";
	Locations[n].reload.l1.emerge = "reload_from_port";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Town.";
	Locations[n].locators_radius.reload.reload2 = 2.0;


	Locations[n].reload.l2.name = "reload1";
	Locations[n].reload.l2.go = "Colombia";
	Locations[n].reload.l2.emerge = "reload_1";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.reload1 = 2.0;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Colombia";
	Locations[n].reload.l4.emerge = "reload_1";
	Locations[n].reload.l4.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l4.label = "Ship.";
	else
		Locations[n].reload.l4.label = "Sea.";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Colombia";
	Locations[n].reload.l3.emerge = "reload_1";
	Locations[n].reload.l3.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l3.label = "Ship.";
	else
		Locations[n].reload.l3.label = "Sea.";

	Locations[n].locators_radius.reload.reload3 = 2.0;

	Locations[n].reload.l5.name = "reload3_back";
	Locations[n].reload.l5.go = "Colombia";
	Locations[n].reload.l5.emerge = "reload_1";
	Locations[n].reload.l5.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l5.label = "Ship.";
	else
		Locations[n].reload.l5.label = "Sea.";

	Locations[n].locators_radius.reload.reload3_back = 2.0;

	Locations[n].island = "Colombia"; // NK 04-08-29
	n = n + 1;

// -----------------------------------------------------------------
	Locations[n].filespath.models = "locations\Town_Cartagena\Port";
	Locations[n].filespath.textures = "locations\SPAIN";
	Locations[n].image = "Town_Cartagena_Port.tga";

	Locations[n].id = "Cartagena_PortB";//location only for climbing ship
	locations[n].id.label = "Cartagena port."; // KK
	locations[n].worldmap = "Cartagena";
	Locations[n].vcskip = true;
	
	//Town sack
	Locations[n].townsack = "Cartagena";
	//Sound
	locations[n].type = "port";
	//Models
	//Always
	Locations[n].models.always.SanFelipe = "SanFelipe";
	Locations[n].models.always.locators = "CartPortB_l";
	Locations[n].models.always.grassPatch = "CartPort_g";
	Locations[n].models.always.l1 = "CartPort";
	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.l2 = "CartPort_sb";
	Locations[n].models.always.l2.foam = "1";
	//Day
//	Locations[n].models.day.rinok = "CartPort_e1";
	Locations[n].models.day.fonar = "CartPort_fd";
	Locations[n].models.day.charactersPatch = "CartPortB_pd";
	//Night
	Locations[n].models.night.fonar = "CartPort_fn";
	Locations[n].models.night.charactersPatch = "CartPortB_pn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map

	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Ship.";
	Locations[n].locators_radius.reload.reload2 = 2.0;


	Locations[n].reload.l2.name = "reload1";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.reload1 = 2.0;

	Locations[n].island = "Colombia"; // NK 04-08-29
	n = n + 1;	

	// Cartagena_town_01 -------------------------------------------------
	Locations[n].filespath.models = "locations\Town_Redmond\Town_01";
	Locations[n].filespath.textures = "locations\SPAIN";
	Locations[n].image = "Town_Redmond_Town_01_Cartagena.tga";

	Locations[n].id = "Cartagena_town_01";
	locations[n].id.label = "Cartagena town";
	locations[n].worldmap = "Cartagena";

	//Town sack
	Locations[n].townsack = "Cartagena";
	locations[n].fastreload = "Cartagena";		
	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	Locations[n].models.always.L1 = "Red01";
	Locations[n].models.always.locators = "Red01_l_xb";
	Locations[n].models.always.grassPatch = "Red01_g";
	Locations[n].models.always.palace = "Palais";
	Locations[n].models.always.palace.locator.group = "randitem";
	Locations[n].models.always.palace.locator.name = "randitem2";
	Locations[n].models.always.church = "Church1";
	Locations[n].models.always.church.locator.group = "randitem";
	Locations[n].models.always.church.locator.name = "randitem3";
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
	Locations[n].reload.l1.name = "reload_1_4";
	Locations[n].reload.l1.go = "Cartagena_town_02";
	Locations[n].reload.l1.emerge = "Falaise_de_fleur_location_02_03";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Town.";
	Locations[n].locators_radius.reload.reload_1_4 = 2.0;

	Locations[n].reload.l2.name = "reload_1_4_back";
	Locations[n].reload.l2.go = "Cartagena_town_02";
	Locations[n].reload.l2.emerge = "Falaise_de_fleur_location_02_03";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Town.";
	Locations[n].locators_radius.reload.reload_1_4_back = 2.0;

	Locations[n].reload.l5.name = "reload_from_port";
	Locations[n].reload.l5.go = "Cartagena_port";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Sea port.";

	Locations[n].reload.l6.name = "reload_2_3";
	Locations[n].reload.l6.go = "Palace";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Palace";
	Locations[n].locators_radius.reload.reload_2_3 = 2.0;
	
	Locations[n].reload.l7.name = "reload_2_4_back";
	Locations[n].reload.l7.go = "Cartagena_Center";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "1";
	Locations[n].reload.l7.label = "Cartagena town.";
	Locations[n].locators_radius.reload.reload_2_4_back = 2.0;

	Locations[n].reload.l8.name = "reload_2_4";
	Locations[n].reload.l8.go = "Cartagena_Center";
	Locations[n].reload.l8.emerge = "reload1";
	Locations[n].reload.l8.autoreload = "1";
	Locations[n].reload.l8.label = "Cartagena town.";
	Locations[n].locators_radius.reload.reload_2_4 = 2.0;

    Locations[n].reload.l11.name = "door_1";
	Locations[n].reload.l11.go = "Cartagena_tavern";
	Locations[n].reload.l11.emerge = "reload1";
	Locations[n].reload.l11.autoreload = "0";
	Locations[n].reload.l11.label = "Tavern.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l11.goto_disable = 1; // Screwface: Disable Go-To location		

	Locations[n].island = "Colombia"; // NK 04-08-29
	n = n + 1;

	// Cartagena_town_02 -------------------------------------------------
	Locations[n].id = "Cartagena_town_02";
	locations[n].id.label = "Cartagena town.";
	locations[n].worldmap = "Cartagena";
	Locations[n].image = "Town_FalaiseDeFleur_town_01_Spain.tga";

	//Town sack
	Locations[n].townsack = "Cartagena";
	locations[n].fastreload = "Cartagena";	
	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\town_01";
	Locations[n].filespath.textures = "locations\SPAIN";
	Locations[n].models.always.city = "FF01";
	Locations[n].models.always.locators = "FF01_l";
	Locations[n].models.always.grassPatch = "FF01_g";
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
	Locations[n].models.day.fonar = "FF01_fd";
	Locations[n].models.day.charactersPatch = "FF01_p";
	//Night
	Locations[n].models.night.fonar = "FF01_fn";
	Locations[n].models.night.charactersPatch = "FF01_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "Falaise_de_fleur_location_02_01";
	Locations[n].reload.l1.go = "Residence_Cartagena";
	Locations[n].reload.l1.emerge = "gate";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Townhall";

	Locations[n].reload.l2.name = "Falaise_de_fleur_location_02_03";
	Locations[n].reload.l2.go = "Cartagena_town_01";
	Locations[n].reload.l2.emerge = "reload_1_4";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Town.";

	Locations[n].reload.l3.name = "Falaise_de_fleur_location_02_perechod";
	Locations[n].reload.l3.go = "cloister_exit";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "cloister.";
/*
	Locations[n].reload.l4.name = "locator21";
	Locations[n].reload.l4.go = "house_of_Elzire_Ayarai";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "House.";

	Locations[n].reload.l5.name = "locator20";
	Locations[n].reload.l5.go = "HouseInsideR20";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "House.";
*/
	Locations[n].island = "Colombia"; // NK 04-08-29
	n = n + 1;

// -----------------------------------------------------------------
	Locations[n].filespath.models = "locations\Town_Cartagena\Port";
	Locations[n].filespath.textures = "locations\SPAIN";
	Locations[n].image = "Town_Cartagena_Fort.tga";

	Locations[n].id = "Cartagena_fort";
	locations[n].id.label = "Cartagena fort."; // KK
	locations[n].worldmap = "Cartagena";

	Locations[n].vcskip = true;

	//Town sack
	Locations[n].townsack = "Cartagena";

	//Sound
	locations[n].type = "San_Felipe_fort";
	//Models
	//Always
	Locations[n].models.always.SanFelipe = "SanFelipe";
	Locations[n].models.always.locators = "Cartfort_l";
	Locations[n].models.always.grassPatch = "CartPort_g";
	Locations[n].models.always.l1 = "CartPort";
	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.l2 = "CartPort_sb";
	Locations[n].models.always.l2.foam = "1";
	//Day
	Locations[n].models.day.rinok = "CartPort_e1";
	Locations[n].models.day.fonar = "CartPort_fd";
	Locations[n].models.day.charactersPatch = "Cartfort_pd";
	//Night
	Locations[n].models.night.fonar = "CartPort_fn";
	Locations[n].models.night.charactersPatch = "Cartfort_pn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map

	Build_at("Cartagena_Fort", "cannonl", "", -102.89, 23.968, -107.18, 2.6, "");
	Build_at("Cartagena_Fort", "cannonl", "", -71.131, 21.667, -189.49, 2.7, "");
	Build_at("Cartagena_Fort", "cannonl", "", -80.127, 21.923, -170.66, 2.7, "");		
	Build_at("Cartagena_Fort", "cannonl", "", -184.61, 10.428, -129.41, 3.1, "");
	Build_at("Cartagena_Fort", "cannonl", "", -181.84, 15.917, -48.384, 2.8, "");	
	
	Locations[n].island = "Colombia"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Town_Cartagena\Cloister_exit";
	Locations[n].image = "Town_Cartagena_Cloister_Inside.tga";

	Locations[n].vcskip = true;

	Locations[n].id = "Cloister_inside";
	locations[n].id.label = "cloister inside";
	//Town sack
	Locations[n].townsack = "Cartagena";
	locations[n].fastreload = "Cartagena";		
	//Sound
	locations[n].type = "town";
	//Models
	//Always
	Locations[n].models.always.locators = "cloister_l";
	Locations[n].models.always.town = "cloister_exit";

	//Day
	Locations[n].models.day.charactersPatch = "cloister_p";
	//Night
	Locations[n].models.night.charactersPatch = "cloister_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "cloister_exit";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Cloister.";

	Locations[n].island = "Colombia"; // NK 04-08-29

	Build_at("cloister_inside", "jungle2", "", -3.4676, 0, 26.249, 0.0, "Building");

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Town_Cartagena\Cloister_exit";
	Locations[n].image = "Town_Cartagena_Cloister_Outside.tga";

	Locations[n].vcskip = true;

	Locations[n].id = "cloister_exit";
	locations[n].id.label = "cloister exit";
	//Town sack
	Locations[n].townsack = "Cartagena";
	locations[n].fastreload = "Cartagena";		
	//Sound
	locations[n].type = "town";
	//Models
	//Always
	Locations[n].models.always.locators = "cloister_exit_l";
	Locations[n].models.always.town = "cloister_exit";

	//Day
	Locations[n].models.day.charactersPatch = "cloister_exit_p";
	//Night
	Locations[n].models.night.charactersPatch = "cloister_exit_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cartagena_town_02";
	Locations[n].reload.l1.emerge = "Falaise_de_fleur_location_02_perechod";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Town.";
    Locations[n].locators_radius.reload.reload1 = 1.5;	

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Cloister_inside";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Cloister.";

	Locations[n].island = "Colombia"; // NK 04-08-29

	Build_at("cloister_exit", "jungle2", "", -3.4676, 0, 26.249, 0.0, "Building");

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Town_Cartagena\Palace";
	Locations[n].image = "Town_Cartagena_Palace.tga";

//	Locations[n].vcskip = true;

	Locations[n].id = "Palace";
	locations[n].id.label = "Palace square";
	//Town sack
	Locations[n].townsack = "Cartagena";
	locations[n].fastreload = "Cartagena";		
	//Sound
	locations[n].type = "town";
	//Models
	Locations[n].models.always.mercado1 = "market";
	Locations[n].models.always.mercado1.locator.group = "goto";
	Locations[n].models.always.mercado1.locator.name = "goto1";
	//Always
	Locations[n].models.always.locators = "Palais_l";
	Locations[n].models.always.town = "Palais";

	//Day
	Locations[n].models.day.charactersPatch = "Palais_p";
	//Night
	Locations[n].models.night.charactersPatch = "Palais_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cartagena_town_01";
	Locations[n].reload.l1.emerge = "reload_2_3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Town.";
	Locations[n].locators_radius.reload.reload1 = 1.5;	

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Palace_Residence";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Residence";
	Locations[n].reload.l2.disable = 1;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Admiral_Office";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Admiral's Office.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l3.goto_disable = 1; //JRH

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Governor_Daughter_House";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Lucia Montavez's House.";

	Locations[n].island = "Colombia"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Tunel";
	Locations[n].filespath.models = "locations\Incas Temple\Labirint";
	//Sound
	Locations[n].image = "Town_Cartagena_Tunnel.tga";
	locations[n].type = "military";
	locations[n].id.label = "Fort Tunnel";
	//Models
	//Always
	Locations[n].models.always.locators = "lab1_l";
	Locations[n].models.always.l1 = "lab1";
	//Day
	Locations[n].models.day.charactersPatch = "Tunel_p";
	//Night
	Locations[n].models.night.charactersPatch = "Tunel_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].lockWeather = "Alcove";

	//Reload map
	Locations[n].reload.l1.name = "reload27";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l8.name = "reload26";
	Locations[n].reload.l8.go = "inside_Cartagena_Fort";
	Locations[n].reload.l8.emerge = "reload2";
	Locations[n].reload.l8.autoreload = "1";
	Locations[n].locators_radius.reload.reload26 = 2.0;	

	Locations[n].reload.l28.name = "reload26_back";
	Locations[n].reload.l28.go = "inside_Cartagena_Fort";
	Locations[n].reload.l28.emerge = "reload2";
	Locations[n].reload.l28.autoreload = "1";
	Locations[n].locators_radius.reload.reload26_back = 2.0;	

	Build_at("Tunel", "boxes", "", 0.15658, 0, 11.382, -3.0977, "Building");
	Build_at("Tunel", "Field_Cannon_broken", "", -3.6373, -6.7726, -76.457, 0.0, "Building");
	Build_at("Tunel", "bale", "", -10.02, 0, -3.7811, 1.6198, "Building");
	Build_at("Tunel", "bale", "", -10.02, 0, 6.7764, 1.6198, "Building");
	Build_at("Tunel", "bale", "", 10.087, 0, 6.6039, -1.5344, "Building");
	Build_at("Tunel", "bale", "", 44.509, 0, -16.099, -1.5871, "Building");
	Build_at("Tunel", "bale", "", 40.864, 0, -70.508, 0.0, "Building");
	Build_at("Tunel", "bale", "", 47.101, 0, -66.994, -1.6107, "Building");

	Locations[n].island = "Colombia"; // NK 04-08-29
	n = n + 1;
	
    //-------------------------------------------------
//--------------------------------------------------------------------------

	locations[n].id = "inside_Cartagena_Fort";
	locations[n].id.label = "Cartagena Fort";
	Locations[n].image = "inside_San_Felipe.tga";
	//Town sack
	locations[n].townsack = "Cartagena";
	//Sound
	locations[n].type = "military";
	
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Wine_cellar";
	locations[n].models.always.DungeonVault1 = "DungeonVault1_orig";
	locations[n].models.always.InquisitionDungeonVault1Fonars = "DungeonVault1_fonars";

	locations[n].models.always.locators = "insidefort_locators";
    Locations[n].models.always.porte = "door_N10";
	Locations[n].models.always.porte.locator.group = "goto";
	Locations[n].models.always.porte.locator.name = "goto2";

    Locations[n].models.always.porta = "bars_down";
	Locations[n].models.always.porta.locator.group = "goto";
	Locations[n].models.always.porta.locator.name = "goto40";		
	
	//Day
	locations[n].models.day.charactersPatch = "DungeonVault1b_patch";
	//Night
	locations[n].models.night.charactersPatch = "DungeonVault1b_patch";
	//Environment
	locations[n].environment.weather = "false";
	locations[n].environment.sea = "false";

	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Cartagena_fort";		
	locations[n].reload.l1.emerge = "reload1";		
	locations[n].reload.l1.autoreload = "0";
	
	locations[n].reload.l3.name = "reload2";
	locations[n].reload.l3.go = "Tunel";
	locations[n].reload.l3.emerge = "reload26";
	locations[n].reload.l3.autoreload = "1";
	locations[n].locators_radius.reload.reload2 = 2.0;	

	Locations[n].island = "Colombia";
	n = n + 1;	

	//-------------------------------------------------
	Locations[n].id = "Admiral_Office";
	locations[n].id.label = "Admiral's Office";
	Locations[n].image = "Town_Havana_Townhall.tga";
	Locations[n].filespath.models = "locations\Inside\Residence2_admiral";
	//Locations[n].filespath.textures = "locations\inside\admiral_office";

	//Town sack
	Locations[n].townsack = "Cartagena";
	locations[n].fastreload = "Cartagena";	
	//Sound
	locations[n].type = "residence";
	//Models
	//Always
	Locations[n].models.always.city = "Res02";
	Locations[n].models.always.l1 = "bars_down";
//	Locations[n].models.always.l2 = "Adm_lever_down";			//later
//	Locations[n].models.always.l3 = "cannonball";				//later	
//	Locations[n].models.always.l4 = "clockkey";				//later		
	Locations[n].models.always.locators = "Res02_l_BoP1";
	Locations[n].models.always.window = "Res02_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Res02_p";
	//Night
	Locations[n].models.night.charactersPatch = "Res02_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\mures2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Tunel";
	Locations[n].reload.l1.emerge = "reload27";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Tunnel.";
	Locations[n].reload.l1.disable = 1;
	Locations[n].locators_radius.reload.reload1 = 0.0001;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Palace";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Square Palace.";

	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box2 = 0.3;
	Locations[n].locators_radius.box.box3 = 0.6;
	Locations[n].locators_radius.box.box4 = 0.9;
	Locations[n].locators_radius.box.box5 = 0.8;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "steplock2";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "steplock_v";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "build_clock2";

	Locations[n].locators_radius.randitem.randitem4 = 0.8;
	Locations[n].items.randitem4 = "cannonball2";			//on floor

	Locations[n].island = "Colombia"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "Palace_Residence";
	locations[n].id.label = "Residence";
	//Town sack
	Locations[n].townsack = "Cartagena";
	locations[n].fastreload = "Cartagena";		
	//Sound
	locations[n].type = "residence";

	InitResidence7(Locations[n].id);

    	Locations[n].models.always.locators = "res07_locators_BoP";

	//Reload map
	Locations[n].reload.l1.go = "Palace";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.label = "Square Palace";

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "lever_item";

	Locations[n].locators_radius.randitem.randitem2 = 0.8;
	Locations[n].items.randitem2 = "pillow";

	Locations[n].island = "Colombia";
	n = n + 1;

	// -------------------------------------------------
//	Locations[n].filespath.models = "locations\Inside\Residence3";
	Locations[n].filespath.models = "locations\Inside\Residence3_red";

	Locations[n].id = "Governor_Daughter_House";
	locations[n].id.label = "House";
	Locations[n].image = "Inside_Residence3.tga";

	//Town sack
	Locations[n].townsack = "Cartagena";
	locations[n].fastreload = "Cartagena";	
	//Sound
	locations[n].type = "Residence";
	//Models
	//Always
	Locations[n].models.always.locators = "Res03_l_BoP1";
	Locations[n].models.always.l1 = "Res03";
	Locations[n].models.always.window = "Res03_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Res03_p";

	//Night
	Locations[n].models.night.charactersPatch = "Res03_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Locations[n].models.back = "back\mures3_";
	Locations[n].models.back = "back\redrsb_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Palace";
	Locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Square Palace.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Woman_Palace_bedroom";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Bedroom.";
	Locations[n].reload.l2.disable = 1;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "clockkey";

	Locations[n].locators_radius.randitem.randitem2 = 0.7;
	Locations[n].items.randitem2 = "clockkey";

	Locations[n].island = "Colombia";
	n = n + 1;

	// -------------------------------------------------
	locations[n].id = "Woman_Palace_bedroom";
	locations[n].id.label = "Bedroom";
	Locations[n].filespath.models = "locations\inside\ResBedRoom";
	Locations[n].filespath.textures = "locations\inside\wr_bedroom";
	Locations[n].image = "Inside_ResBedRoom.tga";
	//Town sack
	Locations[n].townsack = "Cartagena";
	//Sound
	locations[n].type = "Residence";
	//Models
	//Always
	Locations[n].models.always.locators = "bed_l_BoP";
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
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Governor_Daughter_House";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "House";

	Locations[n].locators_radius.randitem.randitem1 = 1.2;
	Locations[n].items.randitem1 = "fire_irons_item";

	Locations[n].island = "Colombia";
	n = n + 1;

 	//-------------------------------------------------
	Locations[n].id = "Cartagena_Townhall";
	locations[n].id.label = "Townhall";
	Locations[n].filespath.models = "locations\inside\Residence_BackHall";
	Locations[n].image = "Inside_Residence_BackHall.tga";

	//Town sack
	Locations[n].townsack = "Cartagena";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Cartagena";	
	//Models
	//Always
	Locations[n].models.always.locators = "ResB_l";
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
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Residence_Cartagena";
	Locations[n].reload.l1.emerge = "reload3_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Townhall's Garden.";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Colombia"; // NK 04-08-29
	n = n + 1;

 	//-------------------------------------------------
	Locations[n].filespath.models = "locations\Town_Cartagena\town";
	Locations[n].image = "Town_Cartagena_Town.tga";

	Locations[n].id = "Cartagena_Center";
	locations[n].id.label = "Cartagena town.";
	locations[n].worldmap = "Cartagena";

	//Town sack
	Locations[n].townsack = "Cartagena";
	locations[n].fastreload = "Cartagena";		
	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);	
	//Models
	//Always
	Locations[n].models.always.locators = "cartTown_l";
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
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cartagena_town_01";
	Locations[n].reload.l1.emerge = "Reload_2_4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Cartagena town.";
	Locations[n].locators_radius.reload.reload1 = 2.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Cartagena_church";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Church.";
    Locations[n].locators_radius.reload.reload2 = 2.0;	
	Locations[n].reload.l2.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l2.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Cartagena_shipyard";
	Locations[n].reload.l3.emerge = "locator2";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "shipyard.";
	Locations[n].reload.l3.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l3.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Cartagena_store";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "store.";
	Locations[n].reload.l4.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l4.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "Cartagena_tavern2";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Tavern.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l5.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "Cartagena_TailorsShop";
	Locations[n].reload.l6.emerge = "locator2";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Tailor's Shop.";
	Locations[n].reload.l6.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l6.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "Cartagena_UsurerHouse";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Loanshark's Office.";
	Locations[n].reload.l7.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l7.goto_disable = 1; // Screwface: Disable Go-To location

	// --> RobC/Alan_Smithee Blacksmith mod
	if (ENABLE_WEAPONSMOD)
	{
		Locations[n].reload.l8.name = "reload8";
		Locations[n].reload.l8.go = "Cartagena_blacksmith";
		Locations[n].reload.l8.emerge = "reload1";
		Locations[n].reload.l8.autoreload = "0";
		Locations[n].reload.l8.label = "Smithy.";
		Locations[n].reload.l8.close_for_night = 1;
		if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l8.goto_disable = 1; // Screwface: Disable Go-To location
	}
	// RobC/Alan_Smithee Blacksmiths <--

	//Levis:
	Locations[n].reload.l9.name = "reload11";
	Locations[n].reload.l9.go = "Cartagena Hotel";
	Locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "Cartagena Hotel.";
	Locations[n].reload.l9.close_for_night = 0;

	Locations[n].reload.l10.name = "reload10";
	Locations[n].reload.l10.go = "Cartagena Hotel Pension";
	Locations[n].reload.l10.emerge = "reload1";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "Cartagena Hotel Pension.";
	Locations[n].reload.l10.close_for_night = 1;
	Locations[n].reload.l10.disable = true;

	Locations[n].reload.l12.name = "reload12";
	Locations[n].reload.l12.go = "Cartagena Hotel";
	Locations[n].reload.l12.emerge = "reload8";
	Locations[n].reload.l12.autoreload = "0";
	Locations[n].reload.l12.label = "Cartagena Hotel.";
	Locations[n].locators_radius.reload.reload12 = 0.5;	

	Locations[n].locators_radius.box.box1 = 0.001;			//climb derrick
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "key8";				//invisible, derrick later

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "key8";				//invisible, derrick later

	Locations[n].island = "Colombia"; // NK 04-08-29	
	n = n + 1;

 	//-------------------------------------------------	
	Locations[n].id = "Cartagena_tavern";
	locations[n].id.label = "#stown_name# tavern";	
	Locations[n].filespath.models = "locations\inside\Tavern_2";
	Locations[n].image = "Inside_Tavern_2.tga";

	//Town sack
	Locations[n].townsack = "Cartagena";

	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "Cartagena";
	//Models
	//Always
	Locations[n].models.always.tavern = "Tavern_2";
	Locations[n].models.always.locators = "Tavern_2_l";
	//Day
	Locations[n].models.day.charactersPatch = "Tavern_2_p";

	//Night
	Locations[n].models.night.charactersPatch = "Tavern_2_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\DOUMH_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cartagena_town_01";
	Locations[n].reload.l1.emerge = "Door_1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	LAi_LocationFightDisable(&Locations[n], true);

//MAXIMUS -->
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Cartagena_tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Room in #stown_name# tavern.";
	LAi_LocationFightDisable(&Locations[n], true);
//MAXIMUS <--

	Locations[n].island = "Colombia"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Cartagena_tavern_upstairs";
	locations[n].id.label = "Room in #stown_name# tavern";
	Locations[n].image = "Inside_Doubleflour_House_Room.tga";

	//Town sack
	Locations[n].townsack = "Cartagena";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Cartagena";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Doubleflour_house";
	Locations[n].models.always.locators = "LH_F2_l";
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
	Locations[n].models.back = "back\redlf2_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cartagena_tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# tavern."; // KK
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "Colombia"; // NK 04-08-29
	n = n + 1;
//JRH
	// Cartagena_church -------------------------------------------------
	Locations[n].id = "Cartagena_church";
	locations[n].id.label = "#stown_name# church";
	Locations[n].image = "Inside_Church_3.tga";
	Locations[n].filespath.models = "locations\inside\Church_3";

	//Town sack
	Locations[n].townsack = "Cartagena";

	//Sound
	locations[n].type = "church";

	locations[n].fastreload = "Cartagena";
	//Models
	//Always
	Locations[n].models.always.city = "Church3";
	Locations[n].models.always.locators = "Church3_l_BOP_neutral";
	Locations[n].models.always.window = "church3_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
//	Locations[n].models.day.lamp = "FalaiseDeFleur05_day";
	Locations[n].models.day.charactersPatch = "Church3_p";

	//Night
//	Locations[n].models.night.lamp = "FalaiseDeFleur05_night";
	Locations[n].models.night.charactersPatch = "Church3_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cartagena_Center";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Center.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Cartagena_church_stairs";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
//	Locations[n].reload.l2.label = "#stown_name#. Center.";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].locators_radius.box.box2 = 0.001;			//open door from inside
	Locations[n].locators_radius.box.box3 = 0.5;			//lever is up
	Locations[n].locators_radius.box.box4 = 0.5;			//lever is down

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "confessional";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "door_panel";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "door_largeh";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "lever_base";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "lever_up";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "lever_down";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Colombia"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
//JRH -->
	Locations[n].id = "Cartagena_church_stairs";
	locations[n].id.label = "Secret passage";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house\\";
	Locations[n].image = "secret_passage.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "silent_loghouse";	
	
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F1_l_JRH";
	Locations[n].models.always.tavern = "LH_F1";
	Locations[n].models.always.window = "LF1_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "LH_F1_p";

	//Night
	Locations[n].models.night.charactersPatch = "LH_F1_p";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redlf2_";

	//Reload map
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Cartagena_church";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.5;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Cartagena_church_stairs";
	Locations[n].reload.l3.emerge = "reload4";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload3 = 0.5;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Cartagena_church_cave";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.3;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_N09";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "gatedoor_w";

	Locations[n].island = "Colombia"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\InquisitionCave";
	Locations[n].id = "Cartagena_church_cave";
	locations[n].id.label = "Inquisition Cave";			//label when opened
	Locations[n].image = "inquisition_cave.tga";
	//Sound
	locations[n].type = "inquisition";

	//Models
	//Always
	Locations[n].models.always.locators = "InquisitionCave_locators_BOP";
	Locations[n].models.always.l1 = "InquisitionCave";
	Locations[n].models.always.l2 = "InquisitionCave_alpha";
	Locations[n].models.always.l3 = "InquisitionCave_rand";
	Locations[n].models.always.l4 = "InquisitionCave_torches";
	
	//Day
	Locations[n].models.day.charactersPatch = "InquisitionCave_patch";
	//Night
	Locations[n].models.night.charactersPatch = "InquisitionCave_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cartagena_church_stairs";
	Locations[n].reload.l1.emerge = "goto4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";

	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.5;
	Locations[n].locators_radius.box.box5 = 0.001;		//0.5 after cloth is picked up
	Locations[n].locators_radius.box.box6 = 0.001;		//0.5 after Elting's first dialog
	Locations[n].locators_radius.box.box7 = 0.5;
	Locations[n].locators_radius.box.box8 = 0.5;
	Locations[n].locators_radius.box.box9 = 0.5;
	Locations[n].locators_radius.box.box10 = 0.5;
	Locations[n].locators_radius.box.box11 = 0.5;
	Locations[n].locators_radius.box.box12 = 0.001;		//larger after Elting's first dialog
	Locations[n].locators_radius.box.box13 = 0.001;		//larger after Elting's first dialog
	Locations[n].locators_radius.box.box14 = 0.001;		//larger after Elting's first dialog
	Locations[n].locators_radius.box.box15 = 0.001;		//larger after Elting's first dialog
	Locations[n].locators_radius.box.box16 = 0.001;		//larger after Elting's first dialog
	Locations[n].locators_radius.box.box17 = 0.001;		//larger after Elting's first dialog

	Locations[n].locators_radius.goto.snoring = 6.0;	//was 5.0
	Locations[n].locators_radius.goto.silence1 = 1.0;
	Locations[n].locators_radius.goto.goto20 = 0.001;	//not used
	
	Locations[n].items.randitem1 = "Animist_cloth";
	Locations[n].items.randitem2 = "medical2";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Colombia"; // NK 04-08-29
	n = n + 1;
//<-- JRH
	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\shipyard2";

	Locations[n].id = "Cartagena_shipyard";
	locations[n].id.label = "#stown_name# shipyard";
	Locations[n].image = "Inside_Shipyard2.tga";

	//Town sack
	Locations[n].townsack = "Cartagena";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Cartagena";
	//Models
	//Always
	Locations[n].models.always.locators = "sh02_l";
	Locations[n].models.always.shipyard = "sh02";
	Locations[n].models.always.window = "sh02_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "sh02_p";

	//Night
	Locations[n].models.night.charactersPatch = "sh02_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\mush2_";
	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "Cartagena_Center";
	Locations[n].reload.l1.emerge = "Reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Center.";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Colombia"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Cartagena_store";
	locations[n].id.label = "#stown_name# store";
	Locations[n].filespath.models = "locations\inside\LargeStore";
	Locations[n].image = "Inside_LargeStore.tga";

	//Town sack
	Locations[n].townsack = "Cartagena";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Cartagena";
	//Models
	//Always
	Locations[n].models.always.locators = "LS_l";
	Locations[n].models.always.tavern = "LS";
	Locations[n].models.always.window = "LS_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	Locations[n].models.always.fonar = "LS_fn";
	//Day
	Locations[n].models.day.charactersPatch = "LS_p";

	//Night
	Locations[n].models.night.charactersPatch = "LS_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\ffls_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cartagena_Center";
	Locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Colombia"; // NK 04-08-29
	n = n + 1;

    // -------------------------------------------------
	Locations[n].id = "Cartagena_tavern2";
	locations[n].id.label = "#stown_name# tavern";
	Locations[n].filespath.models = "locations\inside\Largetavern";
	Locations[n].image = "Inside_LargeTavern.tga";

	//Town sack
	Locations[n].townsack = "Cartagena";

	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "Cartagena";
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
	Locations[n].reload.l1.go = "Cartagena_Center";
	Locations[n].reload.l1.emerge = "reload5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	LAi_LocationFightDisable(&Locations[n], true);

//MAXIMUS -->
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Cartagena_upstairs2";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Room in #stown_name# tavern.";
	Locations[n].reload.l2.disable = true; // KK
	LAi_LocationFightDisable(&Locations[n], true);
//MAXIMUS <--

	Locations[n].island = "Colombia"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Cartagena_upstairs2";
	locations[n].id.label = "Room in #stown_name# tavern";
	Locations[n].image = "Inside_Doubleflour_House_Room.tga";

	//Town sack
	Locations[n].townsack = "Cartagena";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Cartagena";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Doubleflour_house";
	Locations[n].models.always.locators = "LH_F2_l";
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
	Locations[n].models.back = "back\redlf2_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cartagena_tavern2";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# tavern."; // KK
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "Colombia"; // NK 04-08-29
	n = n + 1;

	// --------------------------------------------------
	// Cartagena Tailor
	Locations[n].id = "Cartagena_TailorsShop";

	Locations[n].id.label = "Tailor's Shop";
	Locations[n].image = "Inside_StoreSmall.tga";

	//Town sack
	Locations[n].townsack = "Cartagena";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Cartagena";
	//Models
	Locations[n].filespath.models = "locations\Inside\StoreSmall";
	//Always
	Locations[n].models.always.locators = "SS_l";
	Locations[n].models.always.store = "SS";
	Locations[n].models.always.window = "SS_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch   = "SS_p";
	Locations[n].models.day.fonar			 = "SS_fn";

	//Night
	Locations[n].models.night.charactersPatch = "SS_p";
	Locations[n].models.night.fonar		   = "ss_fn";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\mumh9_";
	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "Cartagena_Center";
	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Center";
	Locations[n].locators_radius.reload.locator2 = 0.7;

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Colombia"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Doubleflour_house";
	Locations[n].id = "Cartagena_UsurerHouse";
	locations[n].id.label = "Loanshark's Office.";
	Locations[n].image = "Inside_Doubleflour_House_Lower.tga";

	//Town sack
	Locations[n].townsack = "Cartagena";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Cartagena";
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F1_l";
	Locations[n].models.always.house = "LH_F1";
	Locations[n].models.always.window = "LF1_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "LH_F1_p";

	//Night
	Locations[n].models.night.charactersPatch = "LH_F1_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\mulf1_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cartagena_Center";
	Locations[n].reload.l1.emerge = "reload7";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Colombia"; // NK 04-08-29
	n = n + 1;	

	Locations[n].id = "Colombia_shore";
	locations[n].id.label = "Dolphin Sands."; // Pillat
	locations[n].worldmap = "Colombia_shore";
	Locations[n].filespath.models = "locations\Outside\Shore_6";
	Locations[n].image = "Outside_Shore_6.tga";
	Locations[n].name = "Dolphin Sands";
	//Sound
	locations[n].type = "seashore";

	//Models
	//Always
	Locations[n].models.always.locators = "Shore06_l";
	Locations[n].models.always.shore = "Shore06";
	Locations[n].models.always.shore.foam = "1";
	Locations[n].models.always.seabed = "Shore06_sb";
	Locations[n].models.always.seabed.foam = "1";
	//Locations[n].models.always.grassPatch = "Shore06_g";

	//Day
	Locations[n].models.day.charactersPatch = "Shore06_p";
	//Night
	Locations[n].models.night.charactersPatch = "Shore06_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].environment.sea = "true";

	//Reload map
	/*Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Falaise_De_Fleur_Jungle";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.locator3 = 1;

	Locations[n].reload.l3.name = "Reload2_back";
	Locations[n].reload.l3.go = "Colombia";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2_back = 5;*/ //Pillat: Add Jungle Locations for Colombia first

	Locations[n].reload.l1.name = "boat";
	Locations[n].reload.l1.go = "Colombia";
	Locations[n].reload.l1.emerge = "reload_2";
	Locations[n].reload.l1.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l1.label = "Ship.";
	else
		Locations[n].reload.l1.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 11.0;

	Locations[n].island = "Colombia"; // NK 04-08-29
	n = n + 1;	
	
	//-----------------------------------------
	//Hotel
	Locations[n].id = "Cartagena Hotel";
	locations[n].id.label = "Cartagena Hotel";
	Locations[n].filespath.models = "locations\inside\flamhouse";
	Locations[n].image = "Inside_Flamhouse.tga";
	Locations[n].vcskip = true;

	//Town sack
	Locations[n].townsack = "Cartagena";

	//Sound
	locations[n].type = "house";
	
	//Models
	//Always
	Locations[n].models.always.locators = "FlamHouse_locators_hotel";
	Locations[n].models.always.tavern = "Flamhouse";

	Locations[n].models.always.window = "FlamHouse_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "FlamHouse_patch";

	//Night
	Locations[n].models.night.charactersPatch = "FlamHouse_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\turkK_"; //TODO: Change for Cartagena

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cartagena_Center";
	Locations[n].reload.l1.emerge = "reload11";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 0.5;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Cartagena_Hotel_private";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 0.7;
	Locations[n].reload.l2.disable = true;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Cartagena_Hotel_room3";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].locators_radius.reload.reload3 = 0.4;
	Locations[n].reload.l3.disable = true;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Cartagena_Hotel_room4";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].locators_radius.reload.reload4 = 0.5;
	Locations[n].reload.l4.disable = true;

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "Cartagena_Hotel_office";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].locators_radius.reload.reload5 = 0.4;
	Locations[n].reload.l5.disable = true;

	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "Cartagena_Hotel_room1";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].locators_radius.reload.reload6 = 0.4;
	Locations[n].reload.l6.disable = true;

	Locations[n].reload.l7.name = "reload7";
	Locations[n].reload.l7.go = "Cartagena_Hotel_room2";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].locators_radius.reload.reload7 = 0.4;
	Locations[n].reload.l7.disable = true;

	Locations[n].reload.l8.name = "reload8";
	Locations[n].reload.l8.go = "Cartagena_center_facade";
	Locations[n].reload.l8.emerge = "box2";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].locators_radius.reload.reload8 = 0.001;		//0.4 later when 'open'

	Locations[n].island = "Colombia";
	LAi_LocationFightDisable(&Locations[n], true);
	
	Locations[n].locators_radius.goto.goto8 = 1.5;
	Locations[n].locators_radius.box.box1 = 0.7;
	Locations[n].locators_radius.box.box2 = 0.8;
	Locations[n].locators_radius.box.box3 = 0.8;
	Locations[n].locators_radius.box.box4 = 0.7;

	Locations[n].locators_radius.randitem.randitem1 = 0.1;
	Locations[n].items.randitem1 = "door_M11";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "door_M11";
	
	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "door_M11";
	
	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "door_M11";
	
	Locations[n].locators_radius.randitem.randitem5 = 0.1;
	Locations[n].items.randitem5 = "door_M11";
	
	Locations[n].locators_radius.randitem.randitem6 = 0.1;
	Locations[n].items.randitem6 = "door_M11";
	
	Locations[n].locators_radius.randitem.randitem7 = 0.1;
	Locations[n].items.randitem7 = "door_M11";
	
	Locations[n].locators_radius.randitem.randitem8 = 0.1;
	Locations[n].items.randitem8 = "door_M11";
	
	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "carpet2";
	n = n + 1;
	//------------------------------------
	//Hotel Pension
	Locations[n].id = "Cartagena Hotel Pension";
	locations[n].id.label = "Cartagena Hotel Pension";
	Locations[n].filespath.models = "locations\inside\Tavern_Room";
	Locations[n].image = "Inside_Tavern_Room.tga";
	Locations[n].vcskip = true;

	//Town sack
	Locations[n].townsack = "Cartagena";

	//Sound
	locations[n].type = "house";
	
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Tavern_room";
	locations[n].models.always.locators = "Tavern_Room_locators";
	locations[n].models.always.tavern = "Tavern_room";
	locations[n].models.always.window = "tavern_room_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 50;
	//Day
	locations[n].models.day.charactersPatch = "Tavern_room_patch";

	//Night
	locations[n].models.night.charactersPatch = "Tavern_room_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "..\back\inside_back_";

	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Cartagena_Center";
	Locations[n].reload.l1.emerge = "reload10";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].island = "Colombia";
	
	n = n + 1;
}


