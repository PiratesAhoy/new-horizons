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
	Locations[n].models.always.l7 = "Margarita_gate";		
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
	Locations[n].locators_radius.reload.gate = 2.0;

	Locations[n].reload.l9.go = "new_cloister_garden";
	Locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l9.label = "";
	Locations[n].reload.l9.name = "reload9_back";		//use reload9 when coming from new cloister, JRH
	Locations[n].reload.l9.autoreload = "0";

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
	locations[n].id.label = "#stown_name# town";
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
	Locations[n].models.always.locators = "Red01_l_cg";
	Locations[n].models.always.grassPatch = "Red01_g";
	Locations[n].models.always.palace = "Palais";
	Locations[n].models.always.palace.locator.group = "randitem";
	Locations[n].models.always.palace.locator.name = "randitem2";				
	Locations[n].models.always.church = "cathedral";				//JRH, was church1
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
	Locations[n].models.always.L2 = "gate";

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

	Locations[n].reload.l3.name = "reload_1_3";
	Locations[n].reload.l3.go = "Cartagena_Exit";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload_1_3 = 3.0;

	Locations[n].reload.l4.name = "reload_1_3_back";
	Locations[n].reload.l4.go = "Cartagena_Exit";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.reload_1_3_back = 3.0;

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

	Locations[n].reload.l13.name = "door_5";
	Locations[n].reload.l13.go = "CdC_Office";
	Locations[n].reload.l13.emerge = "reload1";
	Locations[n].reload.l13.autoreload = "0";
	Locations[n].reload.l13.label = "Casa de Contratacion.";
	Locations[n].reload.l13.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l13.goto_disable = 1; // Screwface: Disable Go-To location		

	Locations[n].island = "Colombia"; // NK 04-08-29
	n = n + 1;

	// Cartagena_town_02 -------------------------------------------------
	Locations[n].id = "Cartagena_town_02";
	locations[n].id.label = "#stown_name# town.";
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
	Locations[n].reload.l3.emerge = "goto7";		//was reload1
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "cloister.";

	Locations[n].reload.l4.name = "locator22";
	Locations[n].reload.l4.go = "House Grandma";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "House.";
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
	locations[n].type = "Chinese_garden";
	
	//Models
	//Always
	Locations[n].models.always.locators = "cloister_l";
	Locations[n].models.always.town = "cloister_exit";
	Locations[n].models.always.l1 = "Margarita_gate";
	Locations[n].models.always.l2 = "new_wall";
	
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

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "hatch11_S";

	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "iron_gate_big";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "iron_gate_big";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "gatedoor_SPA";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "tree1";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "bench";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "bench";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "bench";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "bench";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "bench";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "bench";

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "bench";

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "bench";

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
	Locations[n].items.randitem14 = "bench";

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	Locations[n].items.randitem15 = "bench";

	Locations[n].locators_radius.randitem.randitem16 = 0.001;
	Locations[n].items.randitem16 = "church_window";

	Locations[n].locators_radius.randitem.randitem17 = 0.001;
	Locations[n].items.randitem17 = "door_fort";

	Locations[n].island = "Colombia"; // NK 04-08-29

	Build_at("cloister_inside", "jungle2", "", -3.4676, 0, 26.249, 0.0, "Building");
	Build_at("cloister_inside", "jungle2", "", 9.7, 0, 26.5, 0.0, "Building");

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
	locations[n].type = "silent_town";

	//Models
	//Always
	Locations[n].models.always.locators = "cloister_exit_l";
	Locations[n].models.always.town = "cloister_exit";
	Locations[n].models.always.l1 = "Margarita_gate";
	Locations[n].models.always.l2 = "new_wall";
	Locations[n].models.always.l3 = "stone_cross";
	Locations[n].models.always.l4 = "cabinchest";

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

	//only in WoodesRogers quest
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Cloister_passage";
	Locations[n].reload.l3.emerge = "goto1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Cloister.";
	Locations[n].locators_radius.reload.reload3 = 0.2;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Cloister_passage";
	Locations[n].reload.l4.emerge = "goto2";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Cloister.";
	Locations[n].locators_radius.reload.reload4 = 1.0;

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "BB_graveyard";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Cloister.";
	Locations[n].locators_radius.reload.reload5 = 2.0;

	Locations[n].locators_radius.box.box1 = 0.001;		//large to activate WoodesRogers entre	
	Locations[n].locators_radius.box.box2 = 0.8;

	Locations[n].locators_radius.randitem.randitem1 = 0.001;
	Locations[n].items.randitem1 = "church_window";
	
	Locations[n].locators_radius.randitem.randitem2 = 0.001;
	Locations[n].items.randitem2 = "iron_gate_big";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "iron_gate3";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "iron_gate3";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "iron_gate45";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "iron_gate3";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "iron_gate3";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "iron_gate3";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "gatedoor_SPA";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "tree1";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "iron_gate3";

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "iron_gate3";

	Locations[n].locators_radius.randitem.randitem13 = 0.001;
	Locations[n].items.randitem13 = "tree2";

	Locations[n].locators_radius.randitem.randitem14 = 0.001;
	Locations[n].items.randitem14 = "well";

	Locations[n].locators_radius.randitem.randitem15 = 0.001;
	Locations[n].items.randitem15 = "tree2";

	Locations[n].locators_radius.randitem.randitem16 = 0.001;
	Locations[n].items.randitem16 = "palm2_big";

	Locations[n].locators_radius.randitem.randitem17 = 0.001;
	Locations[n].items.randitem17 = "palm2_big";

	Locations[n].locators_radius.randitem.randitem18 = 0.001;
	Locations[n].items.randitem18 = "tree2";

	Locations[n].locators_radius.randitem.randitem19 = 0.001;
	Locations[n].items.randitem19 = "tree2";

	Locations[n].locators_radius.randitem.randitem20 = 0.001;
	Locations[n].items.randitem20 = "tree2";

	Locations[n].locators_radius.randitem.randitem21 = 0.001;
	Locations[n].items.randitem21 = "tree2";

	Locations[n].locators_radius.randitem.randitem22 = 0.001;
	Locations[n].items.randitem22 = "tree2";

	Locations[n].locators_radius.randitem.randitem23 = 0.001;
	Locations[n].items.randitem23 = "tree2";

	Locations[n].locators_radius.randitem.randitem24 = 0.001;
	Locations[n].items.randitem24 = "tree2";

	Locations[n].locators_radius.randitem.randitem25 = 0.001;
	Locations[n].items.randitem25 = "tree2";

	Locations[n].locators_radius.randitem.randitem26 = 0.001;
	Locations[n].items.randitem26 = "wheelbarrow";

	Locations[n].locators_radius.randitem.randitem27 = 0.001;
	Locations[n].items.randitem27 = "ladder_biggest";

	Locations[n].locators_radius.randitem.randitem28 = 0.001;
	Locations[n].items.randitem28 = "palm2";

	Locations[n].locators_radius.randitem.randitem29 = 0.001;
	Locations[n].items.randitem29 = "wagon";

	Locations[n].locators_radius.randitem.randitem30 = 0.001;
	Locations[n].items.randitem30 = "palm2";

	Locations[n].locators_radius.randitem.randitem31 = 0.001;
	Locations[n].items.randitem31 = "door_fort_high";

	Locations[n].locators_radius.randitem.randitem32 = 0.001;
	Locations[n].items.randitem32 = "door_fort_high";

	Locations[n].locators_radius.randitem.randitem33 = 0.001;
	Locations[n].items.randitem33 = "church_window";

	Locations[n].locators_radius.randitem.randitem34 = 0.001;
	Locations[n].items.randitem34 = "hatch11_S";

	Locations[n].locators_radius.randitem.randitem35 = 0.001;
	Locations[n].items.randitem35 = "door_fort";
	
	Locations[n].island = "Colombia"; // NK 04-08-29

	Build_at("cloister_exit", "jungle2", "", -3.4676, 0, 26.249, 0.0, "Building");
	Build_at("cloister_exit", "jungle2", "", 9.7, 0, 26.5, 0.0, "Building");

	Build_at("cloister_exit", "hedgerow2", "", -24.1, 0, 10.8, 0.8, "Building");
	Build_at("cloister_exit", "hedgerow2", "", -24.1, 0, -7.5, 0.8, "Building");

	Build_at("cloister_exit", "hedgerow", "", -22.6, 0, -26.1, 0.0, "Building");
	Build_at("cloister_exit", "hedgerow", "", -6.9, 0, -26.1, 0.0, "Building");
	Build_at("cloister_exit", "hedgerow", "", 9.1, 0, -26.1, 0.0, "Building");
	Build_at("cloister_exit", "hedgerow", "", 24.8, 0, -26.1, 0.0, "Building");

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
	Locations[n].filespath.models = "locations\Inside\Residence3_Spa";

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
	locations[n].id.label = "#stown_name# townhall";
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
	locations[n].id.label = "#stown_name# town";
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
	Locations[n].locators_radius.reload.reload4 = 2.0;
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
	Locations[n].locators_radius.reload.reload7 = 1.4;
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

	Locations[n].reload.l13.name = "reload13";
	Locations[n].reload.l13.go = "Cartagena Casino";
	Locations[n].reload.l13.emerge = "reload2";
	Locations[n].reload.l13.autoreload = "0";
	Locations[n].reload.l13.label = "Gaming House.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l13.goto_disable = 1;

	Locations[n].reload.l14.name = "reload14";
	Locations[n].reload.l14.go = "Cartagena Mansion Town";
	Locations[n].reload.l14.emerge = "reload1";
	Locations[n].reload.l14.autoreload = "0";
	Locations[n].reload.l14.label = "Mansion.";
	Locations[n].reload.l14.close_for_night = 1;

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
	Locations[n].townsack = "Cartagena";

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
	Locations[n].models.always.window.level = 100;
	//Day
	Locations[n].models.day.charactersPatch = "LH_F1_p";

	//Night
	Locations[n].models.night.charactersPatch = "LH_F1_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\car_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cartagena_Center";
	Locations[n].reload.l1.emerge = "reload7";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Cartagena Casino";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Cartagena Casino.";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Colombia"; // NK 04-08-29
	n = n + 1;

    // -------------------------------------------------

	Locations[n].filespath.models = "locations\town_Douwesen\exit";
	Locations[n].filespath.textures = "locations\SPAIN";

	Locations[n].id = "Cartagena_exit";
	locations[n].id.label = "Exit from #stown_name#";
	Locations[n].image = "Town_Cartagena_Exit.tga";

	//Town sack
	Locations[n].townsack = "Cartagena";

	//Sound
	locations[n].type = "jungle";
//	locations[n].fastreload = "Cartagena";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);
	//Models
	//Always
	Locations[n].models.always.locators = "DouExit_l";

	Locations[n].models.always.Waterfall1 = "waterfall";
    Locations[n].models.always.Waterfall1.uvslide.u0 = 0.3;
	Locations[n].models.always.Waterfall1.tech = "LocationWaterFall";
	Locations[n].models.always.Waterfall1.level = 50;
    //Locations[n].models.always.Waterfall2 = "waterfall1";
    //Locations[n].models.always.Waterfall2.uvslide.u0 = 0.4;
	//Locations[n].models.always.Waterfall2.tech = "LocationWaterFall";
	//Locations[n].models.always.Waterfall2.level = 51;
    Locations[n].models.always.Waterfall3 = "waterfall2";
    Locations[n].models.always.Waterfall3.uvslide.u0 = 0.2;
	Locations[n].models.always.Waterfall3.tech = "LocationWaterFall";
	Locations[n].models.always.Waterfall3.level = 52;

	Locations[n].models.always.exit = "DouExit";
	Locations[n].models.always.grassPatch = "DouExit_g";
	Locations[n].models.always.l0 = "plan_4";
	Locations[n].models.always.l0.level = 9;
	Locations[n].models.always.l0.tech = "LocationModelBlend";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 8;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 7;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan_3";
	Locations[n].models.always.l3.level = 6;
	Locations[n].models.always.l3.tech = "LocationModelBlend";


	//Day
	Locations[n].models.day.charactersPatch = "DouExit_p";
	Locations[n].models.day.fonar = "DouExit_fd";
	//Night
	Locations[n].models.night.charactersPatch = "DouExit_p";
	Locations[n].models.night.fonar = "DouExit_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "Reload2";
	Locations[n].reload.l1.go = "Cartagena_town_01";
	Locations[n].reload.l1.emerge = "reload_1_3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].reload.l2.name = "Reload1";
	Locations[n].reload.l2.go = "Colombia_Jungle_05";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 4;
	Locations[n].reload.l2.label = "#sisland_name# jungles";

	Locations[n].reload.l3.name = "Reload1_back";
	Locations[n].reload.l3.go = "Colombia_Jungle_05";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.Reload1_back = 4;
	Locations[n].reload.l3.label = "#sisland_name# jungles";

/*
	Locations[n].reload.l4.name = "Reload6";
	Locations[n].reload.l4.go = "Douwesen_Cavern";	// For future use: define a location behind the waterfall and rename this locator
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "????";
*/


	Locations[n].island = "Colombia"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
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
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Colombia_Jungle_04";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.locator3 = 1;

	Locations[n].reload.l3.name = "Reload2_back";
	Locations[n].reload.l3.go = "Colombia_Jungle_04";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.Reload2_back = 5;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Colombia";
	Locations[n].reload.l2.emerge = "reload_2";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 11.0;

	Locations[n].island = "Colombia"; // NK 04-08-29
	n = n + 1;
	
	// -------------------------------------------------
	// Levis: Casino

	Locations[n].filespath.models = "locations\Inside\Casino";

	Locations[n].id = "Cartagena Casino";
	locations[n].id.label = "#stown_name# Gambling House";
	Locations[n].image = "Casino.tga";
	Locations[n].vcskip = true;

	//Town sack
	Locations[n].townsack = "Cartagena";

	//Sound
	locations[n].type = "casino";
	locations[n].fastreload = "Cartagena";
	
	//Models
	//Always
	Locations[n].models.always.locators = "casino_locators";
	Locations[n].models.always.casino = "casino";
	
	Locations[n].models.always.table1 = "long_table";
	Locations[n].models.always.table1.locator.group = "tables";
	Locations[n].models.always.table1.locator.name = "table1";
	
	Locations[n].models.always.table2 = "long_table";
	Locations[n].models.always.table2.locator.group = "tables";
	Locations[n].models.always.table2.locator.name = "table2";
	
	Locations[n].models.always.roulette1 = "roulette";
	Locations[n].models.always.roulette1.locator.group = "tables";
	Locations[n].models.always.roulette1.locator.name = "roulette";
	
	Locations[n].models.always.roulette2 = "roulette2";
	Locations[n].models.always.roulette2.locator.group = "tables";
	Locations[n].models.always.roulette2.locator.name = "roulette";
	Locations[n].models.always.roulette2.rotate.x = 0;
	Locations[n].models.always.roulette2.rotate.y = 0.5;
	Locations[n].models.always.roulette2.rotate.z = 0;
	
	Locations[n].models.always.chair1 = "armchair02";
	Locations[n].models.always.chair1.locator.group = "tables";
	Locations[n].models.always.chair1.locator.name = "chair1";
	
	Locations[n].models.always.chair2 = "armchair02";
	Locations[n].models.always.chair2.locator.group = "tables";
	Locations[n].models.always.chair2.locator.name = "chair2";

	Locations[n].models.always.window = "casino_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 100;
	//Day
	Locations[n].models.day.charactersPatch = "casino_patch";

	//Night
	Locations[n].models.night.charactersPatch = "casino_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\car_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cartagena_UsurerHouse";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.close_for_night = 1;
	
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Cartagena_Center";
	Locations[n].reload.l2.emerge = "reload13";
	Locations[n].reload.l2.autoreload = "0";

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
	locations[n].fastreload = "Cartagena";

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
	locations[n].fastreload = "Cartagena";
	
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

 	//-------------------------------------------------
	Locations[n].id = "CdC_Office";
	locations[n].id.label = "Casa de Contratacion";
	Locations[n].filespath.models = "locations\inside\residenceCdC";
	Locations[n].filespath.textures = "locations\inside\Residence_CdC";
	Locations[n].image = "Inside_Residenc_CdC.tga";

	//Town sack
	Locations[n].townsack = "Cartagena";

	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Cartagena";

	//Models
	//Always
	locations[n].models.always.locators = "Residence01_locators";
	locations[n].models.always.l1 = "Residence01";
	locations[n].models.always.window = "residence01_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 50;
	//Day
	locations[n].models.day.charactersPatch = "Residence01_patch";

	//Night
	locations[n].models.night.charactersPatch = "Residence01_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redrsb_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cartagena_town_01";
	Locations[n].reload.l1.emerge = "door_5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Center.";
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Colombia"; // NK 04-08-29
	n = n + 1;

	//---------------------------------
	//Levis: Cartagena Mansion
	Locations[n].id = "Cartagena Mansion Town";
	locations[n].id.label = "Mansion";
	Locations[n].filespath.models = "locations\inside\Office";
	Locations[n].image = "Mansion_Inside.tga";
	Locations[n].vcskip = true;

	//Town sack
	Locations[n].townsack = "Cartagena";
	locations[n].fastreload = "Cartagena";	

	//Sound
	locations[n].type = "residence";
	
	//Models
	Locations[n].models.back = "back\mumh9_";
	//Always
	Locations[n].models.always.locators = "office_locators2";
	Locations[n].models.always.residence = "office2";
	Locations[n].models.always.window = "office_windows";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65;
	//Day
	Locations[n].models.day.charactersPatch = "office_patch";

	//Night
	Locations[n].models.night.charactersPatch = "office_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cartagena_Center";
	Locations[n].reload.l1.emerge = "reload14";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].island = "Colombia";
	n = n + 1;
	
	//---------------------------------
	//Levis: House of Grandma
	
	Locations[n].id = "House Grandma";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\Smallhome";
	Locations[n].image = "Inside_Smallhome.tga";
	Locations[n].vcskip = true;

	//Town sack
	Locations[n].townsack = "Cartagena";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Cartagena";
	//Models
	//Always
	Locations[n].models.always.locators = "sh_l";
	Locations[n].models.always.shipyard = "sh";
	Locations[n].models.always.window = "sh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 55;

	//Day
	Locations[n].models.day.charactersPatch = "sh_p";

	//Night
	Locations[n].models.night.charactersPatch = "sh_p";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\ffsh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cartagena_town_02";
	Locations[n].reload.l1.emerge = "locator22";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].island = "Colombia";
	n = n + 1;

    //------------------------------------------------------------------------------
    //NEW CLOISTER

	Locations[n].filespath.models = "locations\Town_Cartagena\New_cloister";
	Locations[n].image = "Town_Cartagena_New_Cloister_Outside.tga";

	Locations[n].vcskip = true;

	Locations[n].id = "new_cloister_garden";
	locations[n].id.label = "New Cloister Garden";
	//Town sack
	Locations[n].townsack = "Cartagena";
	locations[n].fastreload = "Cartagena";		
	//Sound
	locations[n].type = "Cloister_garden";

	//Models
	//Always
	Locations[n].models.always.locators = "new_cloister_l_outer";
	Locations[n].models.always.town = "new_cloister";

	Locations[n].models.always.l1 = "Margarita_gate";
	Locations[n].models.always.l2 = "graveyard_trees";
	Locations[n].models.always.l3 = "church_door";
	Locations[n].models.always.l4 = "Palms_stones_apples_bushes";
	Locations[n].models.always.l5 = "stone_path";
	Locations[n].models.always.l6 = "white_buildings";
	Locations[n].models.always.l7 = "clocktower";
	Locations[n].models.always.l8 = "plants_oriel_trees1";

	Locations[n].models.always.donkey1 = "donkey";
	Locations[n].models.always.donkey1.locator.group = "quest";
	Locations[n].models.always.donkey1.locator.name = "donkey1";

	//Day
	Locations[n].models.day.fonar = "lamps_outside_fd";
	Locations[n].models.day.charactersPatch = "new_cloister_garden_p";
	//Night
	Locations[n].models.night.fonar = "lamps_outside_fn";
	Locations[n].models.night.charactersPatch = "new_cloister_garden_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Residence_Cartagena";
	Locations[n].reload.l1.emerge = "reload9";
	Locations[n].reload.l1.autoreload = "0";
    	Locations[n].locators_radius.reload.reload1 = 1.5;	

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "new_cloister_inside";
	Locations[n].reload.l2.emerge = "reload1_back";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "new_cloister_chapel";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";

	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "new_cloister_inside";
	Locations[n].reload.l6.emerge = "reload4";
	Locations[n].reload.l6.autoreload = "0";

	Locations[n].locators_radius.quest.defoe = 1.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "horse_fence";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "horse_fence";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;	
	Locations[n].items.randitem3 = "window2";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;		
	Locations[n].items.randitem4 = "tree2";				

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "tree2";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "tree2";

	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "horse_fence";

	Locations[n].locators_radius.randitem.randitem8 = 0.01;
	Locations[n].items.randitem8 = "horse_fence";

	Locations[n].locators_radius.randitem.randitem9 = 0.01;
	Locations[n].items.randitem9 = "ladder_very_big";

	Locations[n].locators_radius.randitem.randitem10 = 0.01;
	Locations[n].items.randitem10 = "window2";

	Locations[n].locators_radius.randitem.randitem11 = 0.01;
	Locations[n].items.randitem11 = "irongates";

	Locations[n].locators_radius.randitem.randitem12 = 0.01;
	Locations[n].items.randitem12 = "irongates";

	Locations[n].locators_radius.randitem.randitem13 = 0.01;
	Locations[n].items.randitem13 = "irongates";

	Locations[n].locators_radius.randitem.randitem14 = 0.01;
	Locations[n].items.randitem14 = "irongates";

	Locations[n].locators_radius.randitem.randitem15 = 0.01;
	Locations[n].items.randitem15 = "tree2";

	Locations[n].locators_radius.randitem.randitem16 = 0.01;	
	Locations[n].items.randitem16 = "spanish_church";

	Locations[n].locators_radius.randitem.randitem17 = 0.01;		
	Locations[n].items.randitem17 = "tree2";			

	Locations[n].locators_radius.randitem.randitem18 = 0.01;
	Locations[n].items.randitem18 = "tree2";

	Locations[n].locators_radius.randitem.randitem19 = 0.01;
	Locations[n].items.randitem19 = "tree2";

	Locations[n].locators_radius.randitem.randitem20 = 0.01;
	Locations[n].items.randitem20 = "wagon";

	Locations[n].locators_radius.randitem.randitem21 = 0.01;		
	Locations[n].items.randitem21 = "tree2";				

	Locations[n].locators_radius.randitem.randitem22 = 0.01;
	Locations[n].items.randitem22 = "tree2";

	Locations[n].locators_radius.randitem.randitem23 = 0.01;
	Locations[n].items.randitem23 = "barrel3";

	Locations[n].locators_radius.randitem.randitem24 = 0.01;
	Locations[n].items.randitem24 = "barrel3";

	Locations[n].locators_radius.randitem.randitem25 = 0.01;
	Locations[n].items.randitem25 = "wood_pier";

	Locations[n].locators_radius.randitem.randitem26 = 0.01;
	Locations[n].items.randitem26 = "barrel3";

	Locations[n].locators_radius.randitem.randitem27 = 0.01;
	Locations[n].items.randitem27 = "wood_pier";

	Locations[n].locators_radius.randitem.randitem28 = 0.01;
	Locations[n].items.randitem28 = "wood_pier";

	Locations[n].locators_radius.randitem.randitem29 = 0.01;		
	Locations[n].items.randitem29 = "wood_pier";				

	Locations[n].locators_radius.randitem.randitem30 = 0.01;
	Locations[n].items.randitem30 = "window2";

	Locations[n].locators_radius.randitem.randitem31 = 0.01;
	Locations[n].items.randitem31 = "tree2";

	Locations[n].locators_radius.randitem.randitem32 = 0.01;
	Locations[n].items.randitem32 = "tree2";

	Locations[n].locators_radius.randitem.randitem33 = 0.01;
	Locations[n].items.randitem33 = "barrel3";

	Locations[n].locators_radius.randitem.randitem34 = 0.01;
	Locations[n].items.randitem34 = "door_window";

	Locations[n].locators_radius.randitem.randitem35 = 0.01;
	Locations[n].items.randitem35 = "ladder_very_big";

	Locations[n].locators_radius.randitem.randitem36 = 0.01;
	Locations[n].items.randitem36 = "ladder_big";

	Locations[n].locators_radius.randitem.randitem37 = 0.01;
	Locations[n].items.randitem37 = "barrel3";

	Locations[n].locators_radius.randitem.randitem38 = 0.01;
	Locations[n].items.randitem38 = "window2";

	Locations[n].locators_radius.randitem.randitem39 = 0.01;
	Locations[n].items.randitem39 = "distillery";

	Locations[n].locators_radius.randitem.randitem40 = 0.01;
	Locations[n].items.randitem40 = "Bench";

	Locations[n].locators_radius.randitem.randitem41 = 0.01;
	Locations[n].items.randitem41 = "Bench";
	
	Locations[n].locators_radius.randitem.randitem42 = 0.01;
	Locations[n].items.randitem42 = "Bench";

	Locations[n].locators_radius.randitem.randitem43 = 0.01;
	Locations[n].items.randitem43 = "Bench";

	Locations[n].locators_radius.randitem.randitem44 = 0.01;
	Locations[n].items.randitem44 = "gatedoor_WT1";

	Locations[n].locators_radius.randitem.randitem45 = 0.01;
	Locations[n].items.randitem45 = "window2";

	Locations[n].locators_radius.randitem.randitem46 = 0.01;
	Locations[n].items.randitem46 = "jars";

	Locations[n].locators_radius.randitem.randitem47 = 0.01;
	Locations[n].items.randitem47 = "pole1";

	Locations[n].locators_radius.randitem.randitem48 = 0.01;
	Locations[n].items.randitem48 = "Bench";

	Locations[n].locators_radius.randitem.randitem49 = 0.01;
	Locations[n].items.randitem49 = "window2";

	Locations[n].locators_radius.randitem.randitem50 = 0.01;
	Locations[n].items.randitem50 = "window2";

	Locations[n].locators_radius.randitem.randitem51 = 0.01;
	Locations[n].items.randitem51 = "hut";

	Locations[n].locators_radius.randitem.randitem52 = 0.01;
	Locations[n].items.randitem52 = "rum_party1";

	Locations[n].locators_radius.randitem.randitem53 = 0.01;
	Locations[n].items.randitem53 = "barrel3";

	Locations[n].locators_radius.randitem.randitem54 = 0.01;
	Locations[n].items.randitem54 = "chair";

	Locations[n].locators_radius.randitem.randitem55 = 0.01;
	Locations[n].items.randitem55 = "roll_of_planks1";

	Locations[n].locators_radius.randitem.randitem56 = 0.01;
	Locations[n].items.randitem56 = "barrel3";

	Locations[n].locators_radius.randitem.randitem57 = 0.01;
	Locations[n].items.randitem57 = "smuggler_goods";

	Locations[n].locators_radius.randitem.randitem58 = 0.01;
	Locations[n].items.randitem58 = "wheelbarrow";

	Locations[n].locators_radius.randitem.randitem59 = 0.01;
	Locations[n].items.randitem59 = "tree_barrel";

	Locations[n].locators_radius.randitem.randitem60 = 0.01;
	Locations[n].items.randitem60 = "toolbox_item";

	Locations[n].locators_radius.randitem.randitem61 = 0.01;
	Locations[n].items.randitem61 = "Bench";

	Locations[n].locators_radius.randitem.randitem62 = 0.01;
	Locations[n].items.randitem62 = "door_fort_high";

	Locations[n].locators_radius.randitem.randitem63 = 0.01;
	Locations[n].items.randitem63 = "barrel3";

	Locations[n].locators_radius.randitem.randitem64 = 0.01;
	Locations[n].items.randitem64 = "spanish_church";

	Locations[n].locators_radius.randitem.randitem65 = 0.01;
	Locations[n].items.randitem65 = "door_fort_high";

	Locations[n].locators_radius.randitem.randitem66 = 0.01;
	Locations[n].items.randitem66 = "spanish_church";

	Locations[n].locators_radius.randitem.randitem67 = 0.01;
	Locations[n].items.randitem67 = "tree2";

	Locations[n].locators_radius.randitem.randitem68 = 0.01;
	Locations[n].items.randitem68 = "spanish_church";

	Locations[n].locators_radius.randitem.randitem69 = 0.01;
	Locations[n].items.randitem69 = "spanish_church";

	Locations[n].locators_radius.randitem.randitem70 = 0.01;
	Locations[n].items.randitem70 = "door_fort_high";

	Locations[n].locators_radius.randitem.randitem71 = 0.01;
	Locations[n].items.randitem71 = "door_fort_high";

	Locations[n].locators_radius.randitem.randitem72 = 0.01;
	Locations[n].items.randitem72 = "chimney";

	Locations[n].locators_radius.randitem.randitem73 = 0.01;
	Locations[n].items.randitem73 = "chimney";

	Locations[n].locators_radius.randitem.randitem74 = 0.01;
	Locations[n].items.randitem74 = "door_N13";

	Locations[n].locators_radius.randitem.randitem75 = 0.01;
	Locations[n].items.randitem75 = "ladder_hold";

	Locations[n].locators_radius.randitem.randitem76 = 0.01;
	Locations[n].items.randitem76 = "church_window_small";

	Locations[n].locators_radius.randitem.randitem77 = 0.01;
	Locations[n].items.randitem77 = "church_window_small";

	Locations[n].locators_radius.randitem.randitem78 = 0.01;
	Locations[n].items.randitem78 = "church_window_small";

	Locations[n].locators_radius.randitem.randitem79 = 0.01;
	Locations[n].items.randitem79 = "church_window_small";

	Locations[n].locators_radius.randitem.randitem80 = 0.01;
	Locations[n].items.randitem80 = "church_window_small";

	Locations[n].locators_radius.randitem.randitem81 = 0.01;
	Locations[n].items.randitem81 = "tree_barrel";

	Locations[n].locators_radius.randitem.randitem82 = 0.01;
	Locations[n].items.randitem82 = "wheelbarrow";

	Locations[n].locators_radius.randitem.randitem83 = 0.01;
	Locations[n].items.randitem83 = "Bench";

	Locations[n].locators_radius.randitem.randitem84 = 0.01;
	Locations[n].items.randitem84 = "Bench";

	Locations[n].locators_radius.randitem.randitem85 = 0.01;
	Locations[n].items.randitem85 = "chest6U_vco";

	Locations[n].locators_radius.randitem.randitem86 = 0.01;
	Locations[n].items.randitem86 = "jars";

	Locations[n].island = "Colombia"; // NK 04-08-29

	n = n + 1;

	Build_at("new_cloister_garden", "warehouse", "", 66.0, 0.1, -10., 0.0, "Building");
	Build_at("new_cloister_garden", "hedgerow", "", -29, -0.3, -75.7, 0.0, "Building");
	Build_at("new_cloister_garden", "hedgerow", "", -29.0, -0.1, -64.7, 0.0, "Building");
	Build_at("new_cloister_garden", "hedgerow", "", -29.0, -0.1, -53.7, 0.0, "Building");
	Build_at("new_cloister_garden", "hedgerow", "", -29.0, -0.1, -42.7, 0.0, "Building");
	Build_at("new_cloister_garden", "hedgerow", "", -29.0, -0.1, -31.7, 0.0, "Building");

	//------------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Town_Cartagena\New_cloister";
	Locations[n].image = "Town_Cartagena_New_Cloister_Outside.tga";

	Locations[n].vcskip = true;

	Locations[n].id = "new_cloister_graveyard";
	locations[n].id.label = "Graveyard";
	//Town sack
	Locations[n].townsack = "Cartagena";
	locations[n].fastreload = "Cartagena";		
	//Sound
	locations[n].type = "Cloister_garden";

	//Models
	//Always
	Locations[n].models.always.locators = "new_cloister_l_graveyard";	//was new_cloister_l_outer
	Locations[n].models.always.town = "new_cloister";

	Locations[n].models.always.l1 = "Margarita_gate";
	Locations[n].models.always.l2 = "graveyard_trees";
	Locations[n].models.always.l3 = "church_door";
	Locations[n].models.always.l4 = "Palms_stones_apples_bushes";
	Locations[n].models.always.l5 = "stone_path";
	Locations[n].models.always.l6 = "white_buildings";
	Locations[n].models.always.l7 = "clocktower";
	Locations[n].models.always.l8 = "plants_oriel_trees1";

	//Day
	Locations[n].models.day.fonar = "lamps_outside_fd";
	Locations[n].models.day.charactersPatch = "new_cloister_graveyard_p";
	//Night
	Locations[n].models.night.fonar = "lamps_outside_fn";
	Locations[n].models.night.charactersPatch = "new_cloister_graveyard_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "new_cloister_inside";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "new_cloister_crypt2_1";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.disable = true;			//only in Assassin storyline
    	
	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "horse_fence";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "horse_fence";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;	
	Locations[n].items.randitem3 = "window2";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;		
	Locations[n].items.randitem4 = "tree2";				

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "tree2";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "tree2";

	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "horse_fence";

	Locations[n].locators_radius.randitem.randitem8 = 0.01;
	Locations[n].items.randitem8 = "horse_fence";

	Locations[n].locators_radius.randitem.randitem9 = 0.01;
	Locations[n].items.randitem9 = "ladder_very_big";

	Locations[n].locators_radius.randitem.randitem10 = 0.01;
	Locations[n].items.randitem10 = "window2";

	Locations[n].locators_radius.randitem.randitem11 = 0.01;
	Locations[n].items.randitem11 = "irongates";

	Locations[n].locators_radius.randitem.randitem12 = 0.01;
	Locations[n].items.randitem12 = "irongates";

	Locations[n].locators_radius.randitem.randitem13 = 0.01;
	Locations[n].items.randitem13 = "irongates";

	Locations[n].locators_radius.randitem.randitem14 = 0.01;
	Locations[n].items.randitem14 = "irongates";

	Locations[n].locators_radius.randitem.randitem15 = 0.01;
	Locations[n].items.randitem15 = "tree2";

	Locations[n].locators_radius.randitem.randitem16 = 0.01;	
	Locations[n].items.randitem16 = "spanish_church";

	Locations[n].locators_radius.randitem.randitem17 = 0.01;		
	Locations[n].items.randitem17 = "tree2";			

	Locations[n].locators_radius.randitem.randitem18 = 0.01;
	Locations[n].items.randitem18 = "tree2";

	Locations[n].locators_radius.randitem.randitem19 = 0.01;
	Locations[n].items.randitem19 = "tree2";

	Locations[n].locators_radius.randitem.randitem20 = 0.01;
	Locations[n].items.randitem20 = "wagon";

	Locations[n].locators_radius.randitem.randitem21 = 0.01;		
	Locations[n].items.randitem21 = "tree2";				

	Locations[n].locators_radius.randitem.randitem22 = 0.01;
	Locations[n].items.randitem22 = "tree2";

	Locations[n].locators_radius.randitem.randitem23 = 0.01;
	Locations[n].items.randitem23 = "barrel3";

	Locations[n].locators_radius.randitem.randitem24 = 0.01;
	Locations[n].items.randitem24 = "barrel3";

	Locations[n].locators_radius.randitem.randitem25 = 0.01;
	Locations[n].items.randitem25 = "wood_pier";

	Locations[n].locators_radius.randitem.randitem26 = 0.01;
	Locations[n].items.randitem26 = "barrel3";

	Locations[n].locators_radius.randitem.randitem27 = 0.01;
	Locations[n].items.randitem27 = "wood_pier";

	Locations[n].locators_radius.randitem.randitem28 = 0.01;
	Locations[n].items.randitem28 = "wood_pier";

	Locations[n].locators_radius.randitem.randitem29 = 0.01;		
	Locations[n].items.randitem29 = "wood_pier";				

	Locations[n].locators_radius.randitem.randitem30 = 0.01;
	Locations[n].items.randitem30 = "window2";

	Locations[n].locators_radius.randitem.randitem31 = 0.01;
	Locations[n].items.randitem31 = "tree2";

	Locations[n].locators_radius.randitem.randitem32 = 0.01;
	Locations[n].items.randitem32 = "tree2";

	Locations[n].locators_radius.randitem.randitem33 = 0.01;
	Locations[n].items.randitem33 = "barrel3";

	Locations[n].locators_radius.randitem.randitem34 = 0.01;
	Locations[n].items.randitem34 = "door_window";

	Locations[n].locators_radius.randitem.randitem35 = 0.01;
	Locations[n].items.randitem35 = "ladder_very_big";

	Locations[n].locators_radius.randitem.randitem36 = 0.01;
	Locations[n].items.randitem36 = "ladder_big";

	Locations[n].locators_radius.randitem.randitem37 = 0.01;
	Locations[n].items.randitem37 = "barrel3";

	Locations[n].locators_radius.randitem.randitem38 = 0.01;
	Locations[n].items.randitem38 = "window2";

	Locations[n].locators_radius.randitem.randitem39 = 0.01;
	Locations[n].items.randitem39 = "distillery";

	Locations[n].locators_radius.randitem.randitem40 = 0.01;
	Locations[n].items.randitem40 = "Bench";

	Locations[n].locators_radius.randitem.randitem41 = 0.01;
	Locations[n].items.randitem41 = "Bench";
	
	Locations[n].locators_radius.randitem.randitem42 = 0.01;
	Locations[n].items.randitem42 = "Bench";

	Locations[n].locators_radius.randitem.randitem43 = 0.01;
	Locations[n].items.randitem43 = "Bench";

	Locations[n].locators_radius.randitem.randitem44 = 0.01;
	Locations[n].items.randitem44 = "gatedoor_WT1";

	Locations[n].locators_radius.randitem.randitem45 = 0.01;
	Locations[n].items.randitem45 = "window2";

	Locations[n].locators_radius.randitem.randitem46 = 0.01;
	Locations[n].items.randitem46 = "jars";

	Locations[n].locators_radius.randitem.randitem47 = 0.01;
	Locations[n].items.randitem47 = "pole1";

	Locations[n].locators_radius.randitem.randitem48 = 0.01;
	Locations[n].items.randitem48 = "Bench";

	Locations[n].locators_radius.randitem.randitem49 = 0.01;
	Locations[n].items.randitem49 = "window2";

	Locations[n].locators_radius.randitem.randitem50 = 0.01;
	Locations[n].items.randitem50 = "window2";

	Locations[n].locators_radius.randitem.randitem51 = 0.01;
	Locations[n].items.randitem51 = "hut";

	Locations[n].locators_radius.randitem.randitem52 = 0.01;
	Locations[n].items.randitem52 = "rum_party1";

	Locations[n].locators_radius.randitem.randitem53 = 0.01;
	Locations[n].items.randitem53 = "barrel3";

	Locations[n].locators_radius.randitem.randitem54 = 0.01;
	Locations[n].items.randitem54 = "chair";

	Locations[n].locators_radius.randitem.randitem55 = 0.01;
	Locations[n].items.randitem55 = "roll_of_planks1";

	Locations[n].locators_radius.randitem.randitem56 = 0.01;
	Locations[n].items.randitem56 = "barrel3";

	Locations[n].locators_radius.randitem.randitem57 = 0.01;
	Locations[n].items.randitem57 = "smuggler_goods";

	Locations[n].locators_radius.randitem.randitem58 = 0.01;
	Locations[n].items.randitem58 = "wheelbarrow";

	Locations[n].locators_radius.randitem.randitem59 = 0.01;
	Locations[n].items.randitem59 = "tree_barrel";

	Locations[n].locators_radius.randitem.randitem60 = 0.01;
	Locations[n].items.randitem60 = "toolbox_item";

	Locations[n].locators_radius.randitem.randitem61 = 0.01;
	Locations[n].items.randitem61 = "Bench";

	Locations[n].locators_radius.randitem.randitem62 = 0.01;
	Locations[n].items.randitem62 = "door_fort_high";

	Locations[n].locators_radius.randitem.randitem63 = 0.01;
	Locations[n].items.randitem63 = "barrel3";

	Locations[n].locators_radius.randitem.randitem64 = 0.01;
	Locations[n].items.randitem64 = "spanish_church";

	Locations[n].locators_radius.randitem.randitem65 = 0.01;
	Locations[n].items.randitem65 = "door_fort_high";

	Locations[n].locators_radius.randitem.randitem66 = 0.01;
	Locations[n].items.randitem66 = "spanish_church";

	Locations[n].locators_radius.randitem.randitem67 = 0.01;
	Locations[n].items.randitem67 = "tree2";

	Locations[n].locators_radius.randitem.randitem68 = 0.01;
	Locations[n].items.randitem68 = "spanish_church";

	Locations[n].locators_radius.randitem.randitem69 = 0.01;
	Locations[n].items.randitem69 = "spanish_church";

	Locations[n].locators_radius.randitem.randitem70 = 0.01;
	Locations[n].items.randitem70 = "door_fort_high";

	Locations[n].locators_radius.randitem.randitem71 = 0.01;
	Locations[n].items.randitem71 = "door_fort_high";

	Locations[n].locators_radius.randitem.randitem72 = 0.01;
	Locations[n].items.randitem72 = "chimney";

	Locations[n].locators_radius.randitem.randitem73 = 0.01;
	Locations[n].items.randitem73 = "chimney";

	Locations[n].locators_radius.randitem.randitem74 = 0.01;
	Locations[n].items.randitem74 = "door_N13";

	Locations[n].locators_radius.randitem.randitem75 = 0.01;
	Locations[n].items.randitem75 = "ladder_hold";

	Locations[n].locators_radius.randitem.randitem76 = 0.01;
	Locations[n].items.randitem76 = "church_window_small";

	Locations[n].locators_radius.randitem.randitem77 = 0.01;
	Locations[n].items.randitem77 = "church_window_small";

	Locations[n].locators_radius.randitem.randitem78 = 0.01;
	Locations[n].items.randitem78 = "church_window_small";

	Locations[n].locators_radius.randitem.randitem79 = 0.01;
	Locations[n].items.randitem79 = "church_window_small";

	Locations[n].locators_radius.randitem.randitem80 = 0.01;
	Locations[n].items.randitem80 = "church_window_small";

	Locations[n].locators_radius.randitem.randitem81 = 0.01;
	Locations[n].items.randitem81 = "tree_barrel";

	Locations[n].locators_radius.randitem.randitem82 = 0.01;
	Locations[n].items.randitem82 = "wheelbarrow";

	Locations[n].locators_radius.randitem.randitem83 = 0.01;
	Locations[n].items.randitem83 = "Bench";

	Locations[n].locators_radius.randitem.randitem84 = 0.01;
	Locations[n].items.randitem84 = "Bench";

	Locations[n].locators_radius.randitem.randitem85 = 0.01;
	Locations[n].items.randitem85 = "chest6U_vco";

	Locations[n].island = "Colombia"; // NK 04-08-29

	n = n + 1;

	Build_at("new_cloister_graveyard", "warehouse", "", 66.0, 0.1, -10., 0.0, "Building");
	Build_at("new_cloister_graveyard", "hedgerow", "", -29.0, -0.3, -75.7, 0.0, "Building");
	Build_at("new_cloister_graveyard", "hedgerow", "", -29.0, -0.1, -64.7, 0.0, "Building");
	Build_at("new_cloister_graveyard", "hedgerow", "", -29.0, -0.1, -53.7, 0.0, "Building");
	Build_at("new_cloister_graveyard", "hedgerow", "", -29.0, -0.1, -42.7, 0.0, "Building");
	Build_at("new_cloister_graveyard", "hedgerow", "", -29.0, -0.1, -31.7, 0.0, "Building");

	 //------------------------------------------------------------------------------

	Locations[n].filespath.models = "locations\Town_Cartagena\New_cloister";
	Locations[n].image = "Town_Cartagena_New_Cloister_Inside.tga";

	Locations[n].vcskip = true;

	Locations[n].id = "new_cloister_inside";
	locations[n].id.label = "Cloister yard";
	//Town sack
	Locations[n].townsack = "Cartagena";
		
	//Sound
	locations[n].type = "Cloister_garden";

	//Models
	//Always
	Locations[n].models.always.locators = "new_cloister_l_inner";
	Locations[n].models.always.town = "new_cloister";	

	Locations[n].models.always.l1 = "fontain1";
	Locations[n].models.always.l1.locator.group = "quest";
	Locations[n].models.always.l1.locator.name = "quest1";
	Locations[n].models.always.l1.uvslide.u0 = 0.0005;
	Locations[n].models.always.l1.uvslide.v0 = 0.2;
	Locations[n].models.always.l1.level = 999;
	Locations[n].models.always.l1.tech = "LocationWaterFall";
	
	Locations[n].models.always.l2 = "fontain2";
	Locations[n].models.always.l2.locator.group = "quest";
	Locations[n].models.always.l2.locator.name = "quest2";
	Locations[n].models.always.l2.uvslide.u0 = 0.04;
	Locations[n].models.always.l2.uvslide.v0 = 0.01;
	Locations[n].models.always.l2.level = 999;
	Locations[n].models.always.l2.tech = "LocationWaterFall";

	Locations[n].models.always.l3 = "fontain_model";
	Locations[n].models.always.l4 = "clocktower";
	Locations[n].models.always.l5 = "Palms_stones_apples_bushes";

	//Day
	Locations[n].models.day.fonar = "lamps_inside_fd";
	Locations[n].models.day.charactersPatch = "new_cloister_inner_p";
	//Night
	Locations[n].models.night.fonar = "lamps_inside_fn";
	Locations[n].models.night.charactersPatch = "new_cloister_inner_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "new_cloister_garden";
	Locations[n].reload.l1.emerge = "reload2_back";
	Locations[n].reload.l1.autoreload = "0";
    	Locations[n].locators_radius.reload.reload1 = 1.5;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "new_cloister_graveyard";
	Locations[n].reload.l2.emerge = "reload3_back";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "new_cloister_room";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.disable = true;			//only in Assassin storyline

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "new_cloister_garden";
	Locations[n].reload.l4.emerge = "reload6";
	Locations[n].reload.l4.autoreload = "0";

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "new_cloister_library";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.disable = true;			//only in Freeplay as engineer

	Locations[n].locators_radius.quest.F1 = 2.0;
	Locations[n].locators_radius.quest.F2 = 2.0;
	Locations[n].locators_radius.quest.F3 = 2.0;
	Locations[n].locators_radius.quest.F4 = 2.0;
	Locations[n].locators_radius.sit.sit1 = 2.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "door_N13";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "pole1";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "door_fort_high";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "door_fort_high";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "door_H1_45";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "door_H1_45";
	
	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "plank2_very_long";

	Locations[n].locators_radius.randitem.randitem8 = 0.01;
	Locations[n].items.randitem8 = "door_N13";

	Locations[n].locators_radius.randitem.randitem9 = 0.01;
	Locations[n].items.randitem9 = "door_N13";

	Locations[n].locators_radius.randitem.randitem10 = 0.01;
	Locations[n].items.randitem10 = "bench";

	Locations[n].locators_radius.randitem.randitem11 = 0.01;
	Locations[n].items.randitem11 = "bench";

	Locations[n].locators_radius.randitem.randitem12 = 0.01;
	Locations[n].items.randitem12 = "church_window_small";

	Locations[n].locators_radius.randitem.randitem13 = 0.01;
	Locations[n].items.randitem13 = "church_window_small";

	Locations[n].locators_radius.randitem.randitem14 = 0.01;
	Locations[n].items.randitem14 = "church_window_small";

	Locations[n].locators_radius.randitem.randitem15 = 0.01;
	Locations[n].items.randitem15 = "door_LBR";

	Locations[n].locators_radius.randitem.randitem16 = 0.01;
	Locations[n].items.randitem16 = "chair";
	
	Locations[n].island = "Colombia"; // NK 04-08-29

	n = n + 1;

//--------------------------------------------------------------------------	

	Locations[n].filespath.models = "locations\Inside\Crypt2_1";	
	Locations[n].image = "wr_crypt2_1.tga";

	Locations[n].id = "new_cloister_crypt2_1";
	locations[n].id.label = "Crypt";
	//Town sack
	Locations[n].townsack = "Cartagena";
	//Sound
	locations[n].type = "crypt";			

	//Models
	//Always
	Locations[n].models.always.l1 = "crypt_2_1_inside";
	
	//Day
	Locations[n].models.day.locators = "crypt_2_1_inside_ld_BOP";
	Locations[n].models.day.charactersPatch = "crypt_2_1_inside_patch";
	
	//Night
	Locations[n].models.night.locators = "crypt_2_1_inside_ln_BOP";
	Locations[n].models.night.charactersPatch = "crypt_2_1_inside_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";	

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "new_cloister_graveyard";
	Locations[n].reload.l1.emerge = "Reload4_back";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "new_cloister_crypt2_2A";
	Locations[n].reload.l2.emerge = "Reload1";
	Locations[n].reload.l2.autoreload = "0";
	
	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Colombia";
	n = n + 1;

//--------------------------------------------------------------------------	

	Locations[n].filespath.models = "locations\Inside\Crypt2_2";	
	Locations[n].image = "wr_crypt2_2.tga";

	Locations[n].id = "new_cloister_crypt2_2A";
	locations[n].id.label = "Crypt";
	//Town sack
	Locations[n].townsack = "Cartagena";
	//Sound
	locations[n].type = "crypt";			

	//Models
	//Always
	Locations[n].models.always.l1 = "crypt_2_2_inside";
	Locations[n].models.always.locators = "crypt_2_2_inside_locators_BOP";
	
	//Day
	Locations[n].models.day.charactersPatch = "crypt_2_2_inside_patch";
	
	//Night
	Locations[n].models.night.charactersPatch = "crypt_2_2_inside_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";	

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "new_cloister_crypt2_1";
	Locations[n].reload.l1.emerge = "Reload2";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "new_cloister_crypt2_2B";
	Locations[n].reload.l2.emerge = "Reload3";
	Locations[n].reload.l2.autoreload = "0";

	LAi_LocationFightDisable(&Locations[n], true);
	LAi_LocationFantomsGen(&locations[n], false);
	Locations[n].vcskip = true;
	Locations[n].monsters = 0;

	Locations[n].island = "Colombia";
	n = n + 1;

	//--------------------------------------------------------------------------	

	Locations[n].filespath.models = "locations\Inside\Crypt2_2";	
	Locations[n].image = "wr_abbey_cell.tga";

	Locations[n].id = "new_cloister_crypt2_2B";
	locations[n].id.label = "Cell";
	//Town sack
	Locations[n].townsack = "Cartagena";
	//Sound
	locations[n].type = "crypt";			

	//Models
	//Always
	Locations[n].models.always.l1 = "crypt_2_2_inside";
	Locations[n].models.always.locators = "crypt_2_2_inside_locators_BOP";
	
	//Day
	Locations[n].models.day.charactersPatch = "crypt_2_2_inside_patch";
	
	//Night
	Locations[n].models.night.charactersPatch = "crypt_2_2_inside_patch";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";	

	//Reload map
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "new_cloister_crypt2_2A";
	Locations[n].reload.l3.emerge = "Reload2";
	Locations[n].reload.l3.autoreload = "0";

	LAi_LocationFightDisable(&Locations[n], true);
	LAi_LocationFantomsGen(&locations[n], false);
	Locations[n].vcskip = true;
	Locations[n].monsters = 0;

	Locations[n].island = "Colombia";
	n = n + 1;

	//--------------------------------------------------------------------------

	Locations[n].id = "New_cloister_chapel";
	locations[n].id.label = "Chapel";
	Locations[n].image = "Inside_Church_2.tga";
	Locations[n].filespath.models = "locations\inside\Church_2\\";
	
	//Town sack
	Locations[n].townsack = "Cartagena";

	//Sound
	locations[n].type = "Vane_chapel";

	//Models
	//Always
	Locations[n].models.always.city = "Church2";
	Locations[n].models.always.locators = "Church2_l";
	Locations[n].models.always.window = "church2_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Church2_p";

	//Night
	Locations[n].models.night.charactersPatch = "Church2_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "New_cloister_garden";
	Locations[n].reload.l1.emerge = "reload5_back";
	Locations[n].reload.l1.autoreload = "0";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Colombia";
	n = n + 1;

	//--------------------------------------------------------------------------

	Locations[n].id = "New_cloister_room";
	locations[n].id.label = "Room";
	Locations[n].filespath.models = "locations\inside\Tavern_room";
	Locations[n].image = "Inside_Tavern_Room.tga";

	//Town sack
	Locations[n].townsack = "Cartagena";

	//Sound
	locations[n].type = "silent_residence";
	//Models
	//Always
	Locations[n].models.always.locators = "tavern_room_locators";
	Locations[n].models.always.l1 = "Tavern_room";
	Locations[n].models.always.window = "Tavern_room_window";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Tavern_room_patch";

	//Night
	Locations[n].models.night.charactersPatch = "Tavern_room_patch";	

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redmh_";

	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "New_cloister_inside";
	Locations[n].reload.l1.emerge = "Reload3";
	Locations[n].reload.l1.autoreload = "0";

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Colombia";
	n = n + 1;

	//--------------------------------------------------------------------------
//pär
	Locations[n].id = "New_cloister_library";
	locations[n].id.label = "Library";
	Locations[n].filespath.models = "locations\inside\Dungeon_2\\";
	Locations[n].filespath.textures = "locations\inside\Dungeon_2\library";
	Locations[n].image = "Inside_Cloister_Library.tga";

	//Town sack
	Locations[n].townsack = "Cartagena";

	//Sound
	locations[n].type = "Rogers_mine";
	
	//Models
	//Always
	Locations[n].models.always.locators = "d02_l_library";
	Locations[n].models.always.dungeon = "d02";
	Locations[n].models.always.fonar = "d02_fn";

	Locations[n].lockCamAngle = 0.15;

	//Day
	Locations[n].models.day.charactersPatch = "d02_p";

	//Night
	Locations[n].models.night.charactersPatch = "d02_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "new_cloister_inside";
	Locations[n].reload.l1.emerge = "reload5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].locators_radius.reload.reload1 = 0.5;

	Locations[n].locators_radius.box.box13 = 0.0001;
	Locations[n].locators_radius.quest.end = 1.5;

	Locations[n].items.randitem1 = "port_mechanism";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "body";

	Locations[n].items.randitem3 = "port_tools";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "number_plate1";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "number_plate3";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "number_plate4";

	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "number_plate2";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Colombia";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle3";

	Locations[n].id = "Colombia_Jungle_01";
	locations[n].id.label = "#sisland_name# jungles";
	Locations[n].image = "Outside_Jungle3.tga";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "jungle3_locators";
	Locations[n].models.always.jungle = "jungle3";
	Locations[n].models.always.grassPatch = "jungle3_grass";
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
	Locations[n].models.day.charactersPatch = "jungle3_patch";
	//Night
	Locations[n].models.night.charactersPatch = "jungle3_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Colombia_Jungle_04";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.Reload1 = 1.0;

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Colombia_Jungle_04";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Colombia_Jungle_02";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.Reload2 = 3.0;

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Colombia_Jungle_02";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.reload2_back = 3.0;

	Locations[n].reload.l5.name = "reload3";
	Locations[n].reload.l5.go = "Colombia_swamp";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.Reload3 = 3.0;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Colombia_swamp";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.reload3_back = 3.0;

	Locations[n].island = "Colombia"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Jungle_6";

    	Locations[n].id = "Colombia_swamp";
	locations[n].id.label = "#sisland_name# jungles";
	Locations[n].image = "Outside_Colombia_Swamp.tga";
	//Sound
	locations[n].type = "Jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

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
	Locations[n].environment.sea = "true";
	Locations[n].environment.swamp = "true"; // PB: Swamps
	Locations[n].MaxSeaHeight = 0.6; // screwface

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Colombia_Jungle_03";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.reload1 = 4;
	Locations[n].reload.l1.disable = 1;	// Not available until after "Colombian Silver" sidequest

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Colombia_Jungle_03";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.reload1_back = 4;
	Locations[n].reload.l2.disable = 1;	// Not available until after "Colombian Silver" sidequest

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Colombia_Jungle_01";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.reload2 = 4;

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Colombia_Jungle_01";
	Locations[n].reload.l4.emerge = "reload3";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.reload2_back = 3;

	Locations[n].reload.l5.name = "reload3";
	Locations[n].reload.l5.go = "Colombia_Jungle_02";
	Locations[n].reload.l5.emerge = "reload3";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.reload3 = 4;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Colombia_Jungle_02";
	Locations[n].reload.l6.emerge = "reload3";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.reload3_back = 4;

	Locations[n].island = "Colombia";

	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Jungle_2";

    	Locations[n].id = "Colombia_Jungle_02";
	locations[n].id.label = "#sisland_name# jungles";
	Locations[n].image = "Outside_Jungle2.tga";
	//Sound
	locations[n].type = "Jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "JUNGLE02_l_GR";
	Locations[n].models.always.jungle = "jungle02_no_statue";
	Locations[n].models.always.grassPatch = "JUNGLE02_g";
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
	Locations[n].models.day.charactersPatch = "Jungle02_p";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle02_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Colombian_Indian_Village";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Indian Village.";
	Locations[n].locators_radius.reload.reload1 = 4;
	Locations[n].reload.l1.disable = true;		// No access to village until allowed by "Colombian Silver" quest

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Colombian_Indian_Village";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Indian Village.";
	Locations[n].locators_radius.reload.reload1_back = 4;
	Locations[n].reload.l2.disable = true;		// No access to village until allowed by "Colombian Silver" quest

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Colombia_Jungle_01";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.reload2 = 4;

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Colombia_Jungle_01";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.reload2_back = 3;

	Locations[n].reload.l5.name = "reload3";
	Locations[n].reload.l5.go = "Colombia_swamp";
	Locations[n].reload.l5.emerge = "reload3";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.reload3 = 4;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Colombia_swamp";
	Locations[n].reload.l6.emerge = "reload3";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.reload3_back = 4;

	Locations[n].island = "Colombia";

 	Build_at("Colombia_Jungle_02", "jungle2", "", -16.0, -0.23, -16.0, 1.5, "wild_jungles");
 	Build_at("Colombia_Jungle_02", "jungle2", "", -14.0, -0.23, -16.0, -1.5, "wild_jungles");

	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_7";

	Locations[n].id = "Colombia_Jungle_03";
	locations[n].id.label = "#sisland_name# jungles";
	Locations[n].image = "Outside_Jungle_7.tga";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);


	//Models
	//Always
	Locations[n].models.always.locators = "Jungle07_l";
	Locations[n].models.always.jungle = "Jungle07";
	Locations[n].models.always.grassPatch = "JUNGLE07_g";
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
	Locations[n].models.day.charactersPatch = "Jungle07_p";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle07_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Colombia_swamp";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.reload1 = 4;

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Colombia_swamp";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.reload1_back = 1;

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Colombia_Jungle_05";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.reload3 = 4;

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Colombia_Jungle_05";
	Locations[n].reload.l4.emerge = "reload3";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.reload3_back = 2;

	Locations[n].island = "Colombia";

	Build_at("Colombia_Jungle_03", "jungle2", "", 0.3, 0.45, 11.0, 0, "wild_jungles");
	Build_at("Colombia_Jungle_03", "jungle2", "", -0.3, 0.45, 16.0, 3, "wild_jungles");
	Build_at("Colombia_Jungle_03", "jungle2", "", -6.0, 0.80, -0.5, -0.2, "wild_jungles");
	Build_at("Colombia_Jungle_03", "jungle2", "", 8.5, 2.0, -4.5, 3.65, "wild_jungles");

	n = n + 1;


	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Jungle_2";

    	Locations[n].id = "Colombia_Jungle_04";
	locations[n].id.label = "#sisland_name# jungles";
	Locations[n].image = "Outside_Jungle2.tga";
	//Sound
	locations[n].type = "Jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "JUNGLE02_l_GR";
	Locations[n].models.always.jungle = "jungle02_no_statue";
	Locations[n].models.always.grassPatch = "JUNGLE02_g";
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
	Locations[n].models.day.charactersPatch = "Jungle02_p";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle02_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Colombia_Jungle_05";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.reload1 = 4;

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Colombia_Jungle_05";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.reload1_back = 4;

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Colombia_Jungle_01";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.reload2 = 4;

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Colombia_Jungle_01";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.reload2_back = 3;

	Locations[n].reload.l5.name = "reload3";
	Locations[n].reload.l5.go = "Colombia_shore";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Dolphin Sands.";
	Locations[n].locators_radius.reload.reload3 = 4;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Colombia_shore";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Dolphin Sands.";
	Locations[n].locators_radius.reload.reload3_back = 4;

	Locations[n].island = "Colombia";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_5";
	Locations[n].filespath.textures = "locations\SPAIN";

	Locations[n].id = "Colombia_Jungle_05";
	locations[n].id.label = "#sisland_name# jungles";
	Locations[n].image = "Outside_Jungle_5.tga";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "Jungle05_l";
	Locations[n].models.always.jungle = "jungle05_signless";
	Locations[n].models.always.grassPatch = "JUNGLE05_g";
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
	Locations[n].models.day.charactersPatch = "Jungle05_p";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle05_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Colombia_Jungle_04";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.Reload1 = 3.0;

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Colombia_Jungle_04";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.Reload1_back = 2.0;

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Cartagena_Exit";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.Reload2 = 3.0;

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Cartagena_Exit";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.Reload2_back = 2.0;

	Locations[n].reload.l5.name = "reload3";
	Locations[n].reload.l5.go = "Colombia_Jungle_03";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.Reload3 = 3.0;
	Locations[n].reload.l5.disable = 1;	// Not available until after "Colombian Silver" sidequest

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Colombia_Jungle_03";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.Reload3_back = 2.0;
	Locations[n].reload.l6.disable = 1;	// Not available until after "Colombian Silver" sidequest

	Locations[n].island = "Colombia";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Indian Village";
	Locations[n].filespath.textures = "locations\NATIVES";

	Locations[n].id = "Colombian_Indian_Village";
	locations[n].id.label = "Indian Village";
	Locations[n].image = "Native_village.tga";

	//Town sack
	Locations[n].townsack = "Cartagena"; // NK 04-08-29

	//Sound
	locations[n].type = "KR_jungle";

	//Models
	//Always
	Locations[n].models.always.locators = "Empty_l";
	Locations[n].models.always.town = "Empty";
	Locations[n].models.always.grasspatch = "pif_g";
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
	Locations[n].models.day.charactersPatch = "PiF_p";
	//Night
	Locations[n].models.night.charactersPatch = "PiF_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Colombia_Jungle_02";
	Locations[n].reload.l1.emerge = "Reload1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].reload.l1.autoreload = 1;
	Locations[n].locators_radius.reload.reload1 = 1;

	Locations[n].reload.l2.name = "Reload1_back";
	Locations[n].reload.l2.go = "Colombia_Jungle_02";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].reload.l2.autoreload = 1;
	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].island = "Colombia"; // NK 04-08-29

	Build_at("Colombian_Indian_Village", "Tipi3", "", 3.5, -0.4, -11.0, 1.0, "");
	Build_at("Colombian_Indian_Village", "Tipi2", "", 9.0, 0.0, 4.0, 0.0, "");
	Build_at("Colombian_Indian_Village", "Tipi2", "", 18.05, -0.0, -2.0, 3.0, "");
	Build_at("Colombian_Indian_Village", "Tipi3", "", 21.0, -0.5, -9.0, 0.5, "");
	Build_at("Colombian_Indian_Village", "Tipi3", "", -1.0, -0.5, 2.0, 0.5, "");

	n = n + 1;

}


