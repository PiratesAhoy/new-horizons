void LocationInitFalaiseDeFleur(ref n)
{
	// Falaise_de_fleur_location_01 -------------------------------------------------
	Locations[n].id = "Falaise_de_fleur_port_01";
	locations[n].id.label = "#stown_name# port."; // KK
	locations[n].worldmap = "Falaise De Fleur";
	Locations[n].image = "Town_FalaiseDeFleur_Port";
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\port";
	Locations[n].filespath.textures = "locations\FRANCE";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "port";
	locations[n].fastreload = "Falaise_De_Fleur";
	if(GetCurrentPeriod() >= PERIOD_COLONIAL_POWERS) Locations[n].navy = 1;
	//Models
	//Always
	Locations[n].models.always.city = "FFport01";
	Locations[n].models.always.city.foam = "1";
	Locations[n].models.always.seabed = "FFport01_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.locators = "FFport01_l";
	Locations[n].models.always.grassPatch = "FFport01_g";
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
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_02";
	Locations[n].reload.l1.emerge = "Falaise_de_fleur_location_02_01";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Slums.";

	Locations[n].reload.l2.name = "werf";
	Locations[n].reload.l2.go = "Falaise_de_fleur_port_02";
	Locations[n].reload.l2.emerge = "locationext";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Beach.";
	Locations[n].locators_radius.reload.werf = 3;

	Locations[n].reload.l3.name = "sea";
	Locations[n].reload.l3.go = "FalaiseDeFleur";
	Locations[n].reload.l3.emerge = "reload_1";
	Locations[n].reload.l3.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l3.label = "Ship.";
	else
		Locations[n].reload.l3.label = "Sea.";
	Locations[n].locators_radius.reload.sea = 3;

	Locations[n].reload.l4.name = "werf_back";
	Locations[n].reload.l4.go = "Falaise_de_fleur_port_02";
	Locations[n].reload.l4.emerge = "locationext";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Beach.";
	Locations[n].locators_radius.reload.werf_back = 2;

	Locations[n].reload.l5.name = "sea_back";
	Locations[n].reload.l5.go = "FalaiseDeFleur";
	Locations[n].reload.l5.emerge = "reload_1";
	Locations[n].reload.l5.autoreload = "0";
		if (VISIT_DECK == 1)
		Locations[n].reload.l5.label = "Ship.";
	else
		Locations[n].reload.l5.label = "Sea.";
	Locations[n].locators_radius.reload.sea_back = 2;
	
	Locations[n].reload.l6.name = "shipyard";
	Locations[n].reload.l6.go = "Head_port_house";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Head port house.";

	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

	// Falaise_de_fleur_location_06 -------------------------------------------------
	Locations[n].id = "Falaise_de_fleur_port_02";
	locations[n].id.label = "#sisland_name# beach";
	locations[n].worldmap = "Falaise De Fleur";
	if(GetCurrentPeriod() == PERIOD_NAPOLEONIC) Locations[n].image = "Town_FalaiseDeFleur_Port2_Nap";
	else Locations[n].image = "Town_FalaiseDeFleur_Port2";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";
	if(GetCurrentPeriod() >= PERIOD_COLONIAL_POWERS) Locations[n].navy = 1;

	//Sound
	locations[n].type = "port";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\port2";
	Locations[n].filespath.textures = "locations\FRANCE";
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
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_05";
	Locations[n].reload.l1.emerge = "Falaise_de_fleur_location_05_01";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Slums.";

	Locations[n].reload.l2.name = "locationext";
	Locations[n].reload.l2.go = "Falaise_De_Fleur_port_01";
	Locations[n].reload.l2.emerge = "werf";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Sea port.";

	Locations[n].reload.l3.name = "locationext_back";
	Locations[n].reload.l3.go = "Falaise_De_Fleur_port_01";
	Locations[n].reload.l3.emerge = "werf";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Sea port.";
	Locations[n].locators_radius.reload.locationext_back = 2.5;

/*	Locations[n].reload.l3.name = "sea";
	Locations[n].reload.l3.go = "FalaiseDeFleur";
	Locations[n].reload.l3.emerge = "reload_1";
	Locations[n].reload.l3.autoreload = "1";*/

	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

	// Falaise_de_fleur_location_02 -------------------------------------------------
	Locations[n].id = "Falaise_de_fleur_location_02";
	locations[n].id.label = "#stown_name#. Slums.";
	locations[n].worldmap = "Falaise De Fleur";
	Locations[n].image = "Town_FalaiseDeFleur_Town_01";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\town_01";
	Locations[n].filespath.textures = "locations\FRANCE";
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
	Locations[n].reload.l1.go = "Falaise_de_fleur_port_01";
	Locations[n].reload.l1.emerge = "Falaise_de_fleur_location_01_02";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Sea port.";

	Locations[n].reload.l2.name = "Falaise_de_fleur_location_02_03";
	Locations[n].reload.l2.go = "Falaise_de_fleur_location_03";
	Locations[n].reload.l2.emerge = "Falaise_de_fleur_location_03_02";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name#. Center.";

	Locations[n].reload.l3.name = "Falaise_de_fleur_location_02_perechod";
	Locations[n].reload.l3.go = "Falaise_de_Fleur_jungle";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Jungle.";

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

	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

	// Falaise_de_fleur_location_03 -------------------------------------------------
	Locations[n].id = "Falaise_de_fleur_location_03";
	locations[n].id.label = "#stown_name#";
	locations[n].worldmap = "Falaise De Fleur";
	Locations[n].image = "Town_FalaiseDeFleur_Town_02";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\town_02";
	Locations[n].filespath.textures = "locations\FRANCE";
	Locations[n].models.always.locators = "FF02_l";
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

	Locations[n].reload.l2.name = "Falaise_de_fleur_location_03_04";
	Locations[n].reload.l2.go = "Falaise_de_fleur_location_04";
	Locations[n].reload.l2.emerge = "Falaise_de_fleur_location_04_03";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name#.";

	Locations[n].reload.l3.name = "Falaise_de_fleur_townhall";
	Locations[n].reload.l3.go = "Falaise_de_fleur_townhall";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Residence.";
	Locations[n].reload.l3.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l3.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l4.name = "Falaise_de_fleur_tavern";
	Locations[n].reload.l4.go = "Falaise_de_fleur_tavern";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Tavern.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l4.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l5.name = "Falaise_de_fleur_shipyard";
	Locations[n].reload.l5.go = "Falaise_de_fleur_shipyard";
	Locations[n].reload.l5.emerge = "locator2";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Shipyard.";
	Locations[n].reload.l5.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l5.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l6.name = "Falause_de_fleur_smuggler";
	Locations[n].reload.l6.go = "house_of_smuggler_in_FiF";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "House.";

	locations[n].reload.l7.name = "home5";
	Locations[n].reload.l7.go = "Falaise_de_fleur_church";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Church.";
	Locations[n].reload.l7.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l7.goto_disable = 1; // Screwface: Disable Go-To location

	locations[n].reload.l8.name = "home3";
	Locations[n].reload.l8.go = "FF_usurerHouse";
	Locations[n].reload.l8.emerge = "reload1";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "Loanshark's Office.";
	Locations[n].reload.l8.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l8.goto_disable = 1; // Screwface: Disable Go-To location

	locations[n].reload.l9.name = "home6";
	Locations[n].reload.l9.go = "Falause_de_fleur_InsideHouseR6";
	Locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "House.";
	Locations[n].reload.l9.close_for_night = 1;


	locations[n].reload.l10.name = "home2";
	Locations[n].reload.l10.go = "Falause_de_fleur_InsideHouseR1";
	Locations[n].reload.l10.emerge = "reload1";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "House.";
	Locations[n].reload.l10.close_for_night = 1;

	// RobC/Alan_Smithee Blacksmiths -->
	if (ENABLE_WEAPONSMOD)
	{
		locations[n].reload.l11.name = "home1";
		Locations[n].reload.l11.go = "FdF_blacksmith";
		Locations[n].reload.l11.emerge = "reload1";
		Locations[n].reload.l11.close_for_night = 1;
		Locations[n].reload.l11.autoreload = "0";
		Locations[n].reload.l11.label = "Smithy";
		if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l11.goto_disable = 1; // Screwface: Disable Go-To location
	}
	// RobC/Alan_Smithee Blacksmiths <--

	//Lucas

	Locations[n].reload.l12.name = "home7";
	Locations[n].reload.l12.go = "Ransom_house_f1";
	Locations[n].reload.l12.emerge = "reload1";
	Locations[n].reload.l12.autoreload = "0";
	Locations[n].reload.l12.label = "House.";
	Locations[n].reload.l12.close_for_night = 0;

	//Lucas


	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

	// Falaise_de_fleur_location_04 -------------------------------------------------
	Locations[n].id = "Falaise_de_fleur_location_04";
	locations[n].id.label = "#stown_name#";
	locations[n].worldmap = "Falaise De Fleur";

	Locations[n].image = "Town_FalaiseDeFleur_Town_03";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
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
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_03";
	Locations[n].reload.l1.emerge = "Falaise_de_fleur_location_03_04";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Center.";

	Locations[n].reload.l2.name = "Falaise_de_fleur_location_04_05";
	Locations[n].reload.l2.go = "Falaise_de_fleur_location_05";
	Locations[n].reload.l2.emerge = "Falaise_de_fleur_location_05_04";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name#. Slums.";

	Locations[n].reload.l3.name = "Falaise_de_fleur_store";
	Locations[n].reload.l3.go = "Falaise_de_Fleur_store";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Store.";
	Locations[n].reload.l3.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l3.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l4.name = "locator21";
	Locations[n].reload.l4.go = "Falaise_de_fleur_TailorsShop";
	Locations[n].reload.l4.emerge = "locator2"; //r1
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Tailor's Shop.";
	Locations[n].reload.l4.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l4.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

	// Falaise_de_fleur_location_05 -------------------------------------------------
	Locations[n].id = "Falaise_de_fleur_location_05";
	locations[n].id.label = "#stown_name#. Slums";
	locations[n].worldmap = "Falaise De Fleur";
	Locations[n].image = "Town_FalaiseDeFleur_Town_04";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\town_04";
	Locations[n].filespath.textures = "locations\FRANCE";
	Locations[n].models.always.city = "FF04";
	Locations[n].models.always.locators = "FF04_l";
	Locations[n].models.always.grassPatch = "FF04_g";
	//Day
	Locations[n].models.day.fonar = "FF04_fd";
	Locations[n].models.day.charactersPatch = "FF04_p";
	//Night
	Locations[n].models.night.fonar = "FF04_fn";
	Locations[n].models.night.charactersPatch = "FF04_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "Falaise_de_fleur_location_05_04";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_04";
	Locations[n].reload.l1.emerge = "Falaise_de_fleur_location_04_05";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].reload.l2.name = "Falaise_de_fleur_location_05_01";
	Locations[n].reload.l2.go = "Falaise_de_fleur_port_02";
	Locations[n].reload.l2.emerge = "Falaise_de_fleur_location_01_05";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Beach.";

	Locations[n].reload.l3.name = "home";
	Locations[n].reload.l3.go = "house_of_laurence";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "House.";

	Locations[n].reload.l4.name = "locator6";
	Locations[n].reload.l4.go = "Falaise_de_fleur_InsideHouseR6(05)";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "House.";

	Locations[n].reload.l5.name = "locator7";
	Locations[n].reload.l5.go = "Falaise_de_fleur_InsideHouseR7(05)";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "House.";

	Locations[n].reload.l6.name = "locator11";
	Locations[n].reload.l6.go = "Falaise_de_fleur_InsideHouseR11(05)";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "House.";


	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	// Falaise de Fleur Tailor
	Locations[n].id = "Falaise_de_fleur_TailorsShop";	
	Locations[n].id.label = "Tailor's Shop";
	Locations[n].image = "Inside_StoreSmall";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	Locations[n].filespath.models			 = "locations\Inside\StoreSmall";
	//Always
	Locations[n].models.always.locators	   = "SS_l";
	Locations[n].models.always.store		  = "SS";
	Locations[n].models.always.window		 = "SS_w";
	Locations[n].models.always.window.tech	= "LocationWindows";
	Locations[n].models.always.window.level   = 50;
	//Day
	Locations[n].models.day.charactersPatch   = "SS_p";
	Locations[n].models.day.fonar			 = "SS_fn";

	//Night
	Locations[n].models.night.charactersPatch = "SS_p";
	Locations[n].models.night.fonar		   = "ss_fn";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\fflf1_";
	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_04";
	Locations[n].reload.l1.emerge = "locator21";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Center.";
	Locations[n].locators_radius.reload.locator2 = 0.7;

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "Falaise_de_fleur_InsideHouseR6(05)";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\DoubleFlour_house";
	Locations[n].image = "Inside_Doubleflour_House_Lower";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Falaise_De_Fleur";
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
	Locations[n].models.back = "back\fflf1_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_05";
	Locations[n].reload.l1.emerge = "locator6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Slums.";
	Locations[n].locators_radius.reload.reload1 = 0.8;


	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "Falaise_de_fleur_InsideHouseR7(05)";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\mh5";
	Locations[n].image = "Inside_mh5";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
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
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_05";
	Locations[n].reload.l1.emerge = "locator7";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Slums.";
	Locations[n].locators_radius.reload.reload1 = 0.8;


	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "Falaise_de_fleur_InsideHouseR11(05)";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\Smallhome";
	Locations[n].image = "Inside_Smallhome";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].models.always.locators = "sh_l";
	Locations[n].models.always.house = "sh";
	Locations[n].models.always.window = "sh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "sh_p";

	//Night
	Locations[n].models.night.charactersPatch = "sh_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\ffsh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_05";
	Locations[n].reload.l1.emerge = "locator11";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Slums.";
	Locations[n].locators_radius.reload.reload1 = 0.8;


	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

	// Falaise_de_fleur_church -------------------------------------------------
	Locations[n].id = "Falaise_de_fleur_church";
	locations[n].id.label = "#stown_name# church";
	Locations[n].image = "Inside_Church_inside";
	Locations[n].filespath.models = "locations\inside\Church_inside";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "Falaise_De_Fleur";
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
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_03";
	Locations[n].reload.l1.emerge = "home5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Center.";
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

	// 06 -------------------------------------------------
	Locations[n].id = "Falaise_De_Fleur_Jungle";
	locations[n].id.label = "#sisland_name# jungle";
	Locations[n].image = "Town_FalaiseDeFleur_Exit";
	//Sound
	locations[n].type = "jungle";
//	locations[n].fastreload = "Falaise_De_Fleur";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\exit";
	Locations[n].models.always.jungle = "FFexit";
	Locations[n].models.always.locators = "FFexit_l";
	Locations[n].models.always.grassPatch = "FFexit_g";
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
	Locations[n].models.day.charactersPatch = "FFexit_p";
	Locations[n].models.day.fonar = "FFexit_fd";
	//Night
	Locations[n].models.night.charactersPatch = "FFexit_p";
	Locations[n].models.night.fonar = "FFexit_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_02";
	Locations[n].reload.l1.emerge = "Falaise_de_fleur_location_02_perechod";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Slums.";

	Locations[n].reload.l2.name = "reload1";
	Locations[n].reload.l2.go = "Falaise_de_fleur_shore";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Octopus Bay.";
	Locations[n].locators_radius.reload.reload1 = 3;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Falaise_de_fleur_shore";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Octopus Bay.";
	Locations[n].locators_radius.reload.reload1_back = 2;


	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "Falaise_de_fleur_shore";
	locations[n].id.label = "Octopus Bay."; // KK
	locations[n].worldmap = "FShore 1";
	Locations[n].filespath.models = "locations\Outside\Shore_6";
	Locations[n].image = "Outside_Shore_6";
	Locations[n].name = "Octopus Bay";
	//Sound
	locations[n].type = "seashore";

	//Models
	//Always
	Locations[n].models.always.locators = "Shore06_l_xc";	// GR: added locators for route to bridge
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
	Locations[n].reload.l1.go = "Falaise_De_Fleur_Jungle";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.locator3 = 1;

	Locations[n].reload.l3.name = "Reload2_back";
	Locations[n].reload.l3.go = "Falaise_De_Fleur_Jungle";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2_back = 5;

	Locations[n].reload.l4.name = "reload3_back";
	Locations[n].reload.l4.go = "FalaiseDeFleur_Grot";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Hidden cave.";
	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "FalaiseDeFleur";
	Locations[n].reload.l2.emerge = "reload_2";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 11.0;

	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

	// 06 -------------------------------------------------
	Locations[n].id = "Falaise_De_Fleur_townhall";
	locations[n].id.label = "#stown_name# townhall";
	Locations[n].filespath.models = "locations\inside\Residence1";
	Locations[n].image = "Inside_Residence1";

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
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_03";
	Locations[n].reload.l1.emerge = "Falaise_de_fleur_townhall";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Center.";
	Locations[n].locators_radius.reload.locator1 = 0.8;
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Falaise_de_fleur_tavern";
	Locations[n].filespath.models = "locations\inside\smalltavern";
	locations[n].id.label = "#stown_name# Tavern";
	Locations[n].image = "Inside_SmallTavern";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].models.always.locators = "ST_l";
	Locations[n].models.always.tavern = "ST";
	Locations[n].models.always.window = "St_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "ST_p";

	//Night
	Locations[n].models.night.charactersPatch = "ST_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\ffst_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_03";
	Locations[n].reload.l1.emerge = "Falaise_de_fleur_tavern";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Center.";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Falaise_de_fleur_tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.label = "Room in #stown_name# tavern.";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 0.8;
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Falaise_de_fleur_tavern_upstairs";
	locations[n].id.label = "Room in #stown_name# tavern";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house";
	Locations[n].image = "Inside_Doubleflour_House_Room";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
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
	Locations[n].models.back = "back\fflf2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# tavern."; // KK
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Falaise_de_fleur_shipyard";
	Locations[n].filespath.models = "locations\inside\shipyard2";
	locations[n].id.label = "#stown_name# shipyard";
	Locations[n].image = "Inside_Shipyard2";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].models.always.locators = "sh02_l";
	Locations[n].models.always.tavern = "sh02";
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
	Locations[n].models.back = "back\ffsh2_";
	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_03";
	Locations[n].reload.l1.emerge = "Falaise_de_fleur_shipyard";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Center.";
	Locations[n].locators_radius.reload.locator2 = 0.8;
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Falaise_de_Fleur_store";
	locations[n].id.label = "#stown_name# store";
	Locations[n].filespath.models = "locations\inside\LargeStore";
	Locations[n].image = "Inside_LargeStore";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Falaise_De_Fleur";
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
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_04";
	Locations[n].reload.l1.emerge = "Falaise_de_fleur_store";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "house_of_smuggler_in_FiF";
	locations[n].id.label = "House in #stown_name#";
	Locations[n].filespath.models = "locations\inside\DoubleFlour_house";
	Locations[n].image = "Inside_Doubleflour_House_Lower";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Falaise_De_Fleur";
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
	Locations[n].models.back = "back\fflf1_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_03";
	Locations[n].reload.l1.emerge = "Falause_de_fleur_smuggler";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Center.";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "FF_usurerHouse";
	locations[n].id.label = "Loanshark's Office.";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house";
	Locations[n].image = "Inside_Doubleflour_House_Lower";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Falaise_De_Fleur";
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
	Locations[n].models.back = "back\fflf1_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_03";
	Locations[n].reload.l1.emerge = "home3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Center.";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;


	// -------------------------------------------------
	Locations[n].id = "house_of_laurence";
	locations[n].id.label = "House in #stown_name#";
	Locations[n].filespath.models = "locations\inside\smallhome";
	Locations[n].image = "Inside_Smallhome";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].models.always.locators = "SH_l";
	Locations[n].models.always.house = "SH";
	//Locations[n].models.always.env = "smallhome_FF_02_env";
	Locations[n].models.always.window = "Sh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Sh_p";

	//Night
	Locations[n].models.night.charactersPatch = "Sh_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\ffsh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_05";
	Locations[n].reload.l1.emerge = "home";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Slums.";
	Locations[n].locators_radius.reload.reload1 = 0.8;


	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "house_of_Elzire_Ayarai";
	locations[n].id.label = "House in #stown_name#";
	Locations[n].filespath.models = "locations\inside\smallhome";
	Locations[n].image = "Inside_Smallhome";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].models.always.locators = "SH_l";
	Locations[n].models.always.house = "SH";
	Locations[n].models.always.window = "Sh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Sh_p";

	//Night
	Locations[n].models.night.charactersPatch = "Sh_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\ffsh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_02";
	Locations[n].reload.l1.emerge = "locator21";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Slums.";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].vcskip = true; // KK

	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "HouseInsideR20";
	locations[n].id.label = "House in #stown_name#";
	Locations[n].filespath.models = "locations\inside\mh5";
	Locations[n].image = "Inside_mh5";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
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
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_02";
	Locations[n].reload.l1.emerge = "locator20";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Slums.";
	Locations[n].locators_radius.reload.reload1 = 0.8;


	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

	// -^------------------------------------------------

	Locations[n].id = "Falause_de_fleur_InsideHouseR6";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\mh6";
	Locations[n].image = "Inside_mh6";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].models.always.locators = "mh6_l";
	Locations[n].models.always.house = "mh6";
	Locations[n].models.always.window = "mh6_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "mh6_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh6_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\ffmh6_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_03";
	Locations[n].reload.l1.emerge = "home6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Center.";


	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

	// -^------------------------------------------------

	Locations[n].id = "Falause_de_fleur_InsideHouseR1";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\mh10";
	Locations[n].image = "Inside_mh10";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].models.always.locators = "mh10_l";
	Locations[n].models.always.house = "mh10";
	Locations[n].models.always.window = "mh10_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "mh10_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh10_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\ffmh10_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_03";
	Locations[n].reload.l1.emerge = "home1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Center.";


	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "Falause_de_fleur_InsideHouseR7";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\mh5";
	Locations[n].image = "Inside_mh5";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
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
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_03";
	Locations[n].reload.l1.emerge = "home7";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Center.";


	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;
	
	// -------------------------------------------------

	Locations[n].id = "Head_port_house";
	locations[n].id.label = "Head port house";
	//Sound
	Locations[n].filespath.models = "locations\inside\mh5";
	Locations[n].image = "Inside_mh5";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Falaise_De_Fleur";
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
	Locations[n].reload.l1.go = "Falaise_de_fleur_port_01";
	Locations[n].reload.l1.emerge = "shipyard";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Port.";

	Locations[n].vcskip = true; // KK
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

//-------------------------------------------------------------------------------------------


	Locations[n].filespath.models = "locations\Inside\Grot";

	Locations[n].id = "FalaiseDeFleur_Grot";
	locations[n].id.label = "Hidden Cave";
	Locations[n].image = "Inside_Grot";
	//Sound
	locations[n].type = "cave";
	//Models
	Locations[n].models.back = "back\grotenv_";
	//Always
	Locations[n].models.always.cave = "Grot";
	Locations[n].models.always.locators = "Grot_l_GR";
	//Day
	Locations[n].models.day.charactersPatch = "Grot_p";
	//Night
	Locations[n].models.night.charactersPatch = "Grot_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "FalaiseDeFleur_Bridge";
	Locations[n].reload.l1.emerge = "reload1_back";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Bridge.";
	Locations[n].locators_radius.reload.reload1 = 2;

//	Locations[n].reload.l2.name = "reload1_back";
//	Locations[n].reload.l2.go = "FalaiseDeFleur_Bridge";
//	Locations[n].reload.l2.emerge = "reload1_back";
//	Locations[n].reload.l2.autoreload = "1";
//	Locations[n].reload.l2.label = "Bridge.";
//	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Falaise_de_fleur_shore";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Octopus Bay.";
	Locations[n].locators_radius.reload.reload2 = 2;

	Locations[n].vcskip = true; // KK

	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Passage";

	Locations[n].id = "FalaiseDeFleur_Bridge";
	locations[n].id.label = "Old Bridge";
	Locations[n].image = "Outside_Passage1";
	//Sound
	locations[n].type = "seashore";

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
	Locations[n].reload.l1.go = "FalaiseDeFleur_jungle_01";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload4 = 2.0;

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "FalaiseDeFleur_Grot";
	Locations[n].reload.l2.emerge = "reload1_back";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Hidden Cave";

	Locations[n].vcskip = true; // KK

	Locations[n].island = "FalaiseDeFleur";

	Locations[n].locators_radius.goto.goto30 = 0.2;
	Locations[n].locators_radius.goto.goto31 = 0.2;
	Locations[n].locators_radius.goto.goto40 = 0.2;
	Locations[n].locators_radius.goto.goto41 = 0.2;
	Build_at("FalaiseDeFleur_Bridge", "jungle2", "", -9.0, 13.51, -29.27, 1.22, "wild_jungles");

	n = n + 1;

    // -------------------------------------------------
	Locations[n].id = "FalaiseDeFleur_jungle_01";
	Locations[n].id.label = "#sisland_name# jungles";
	Locations[n].filespath.models = "locations\Outside\jungle_8";
	Locations[n].image = "Outside_Jungle_8";
 	//Sound
	locations[n].type = "jungle";
//	LAi_LocationMonstersGen(&locations[n], true);
//	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.jungle = "jungle08";
	Locations[n].models.always.locators = "jungle08_l";
	Locations[n].models.always.grassPatch = "JUNGLE08_g";
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
	Locations[n].models.day.charactersPatch = "jungle08_p";
//	Locations[n].models.day.fonar = "jungle01_fd";
	//Night
	Locations[n].models.night.charactersPatch = "jungle08_p";
//	Locations[n].models.night.fonar = "jungle01_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "FalaiseDeFleur_jungle_02";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1 = 3.0;

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "FalaiseDeFleur_jungle_02";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "FalaiseDeFleur_Bridge";
	Locations[n].reload.l3.emerge = "reload4_back";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Old Bridge";
	Locations[n].locators_radius.reload.reload2 = 3.0;

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "FalaiseDeFleur_Bridge";
	Locations[n].reload.l4.emerge = "reload4_back";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Old Bridge";
	Locations[n].locators_radius.reload.reload2_back = 2.0;

	Locations[n].vcskip = true; // KK

	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Jungle_2";

    	Locations[n].id = "FalaiseDeFleur_jungle_02";
	locations[n].id.label = "#sisland_name# jungles";
	Locations[n].image = "Outside_Jungle2";
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
	Locations[n].reload.l1.go = "FalaiseDeFleur_jungle_01";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.reload1 = 4;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "FalaiseDeFleur_jungle_01";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "#sisland_name# jungles";
	Locations[n].locators_radius.reload.reload1_back = 4;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "FalaiseDeFleur_passage";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Falaise de Fleur";
	Locations[n].locators_radius.reload.reload2 = 4;

	Locations[n].reload.l5.name = "reload2_back";
	Locations[n].reload.l5.go = "FalaiseDeFleur_passage";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Falaise de Fleur";
	Locations[n].locators_radius.reload.reload2_back = 3;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "FalaiseDeFleur_passage";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Falaise de Fleur";
	Locations[n].locators_radius.reload.reload3 = 4;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "FalaiseDeFleur_passage";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Falaise de Fleur";
	Locations[n].locators_radius.reload.reload3_back = 4;

	Locations[n].vcskip = true; // KK
	Build_at("FalaiseDeFleur_jungle_02", "jungle2", "", 17.48, -1.7, -29.2, 0, "wild_jungles");

	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29

	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Passage";

	Locations[n].id = "FalaiseDeFleur_passage";
	locations[n].id.label = "Falaise de Fleur";
	Locations[n].image = "Outside_Passage2";
	//Sound
	locations[n].type = "seashore";

	//Models
	//Always
	Locations[n].models.always.locators = "pass2_l";
	Locations[n].models.always.jungle = "pass2";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.seabed = "pass2_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "pass2_g";
	Locations[n].models.always.grasspatch.texture = "Grass\grass_flower.tga";
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
	Locations[n].models.day.charactersPatch = "pass2_p";
	//Night
	Locations[n].models.night.charactersPatch = "pass2_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "FalaiseDeFleur_jungle_02";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	//Locations[n].locators_radius.reload.reload2 = 2.0;
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "FalaiseDeFleur_jungle_02";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload2 = 2.0;
	Locations[n].reload.l2.label = "Jungle.";

	Locations[n].reload.l3.name = "reload1";
	Locations[n].reload.l3.go = "FalaiseDeFleur_jungle_02";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1 = 2.0;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "FalaiseDeFleur_jungle_02";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].vcskip = true; // KK

	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
}
