void LocationInitDouwesen(ref n)
{
	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_Douwesen\port";
	Locations[n].filespath.textures = "locations\HOLLAND";
	Locations[n].image = "Town_Douwesen_Port.tga";
	locations[n].worldmap = "Douwesen";
	Locations[n].id = "Douwesen_port";
	locations[n].id.label = "#stown_name# port."; // KK

	//Town sack
	Locations[n].townsack = "Douwesen";

	//Sound
	locations[n].type = "port";
	locations[n].fastreload = "Douwesen";
	//Models
	//Always
	Locations[n].models.always.locators = "DouPort_l";
	Locations[n].models.always.seabed = "DouPort_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.l1 = "DouPort";
	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.grasspatch = "DouPort_g";
	Locations[n].models.always.grasspatch.texture = "Grass\grass_flower.tga";
	//Day
	Locations[n].models.day.rinok = "DouPort_e01";
	Locations[n].models.day.charactersPatch = "DouPort_pd";
	Locations[n].models.day.fonar = "DouPort_fd";
	//Night
	Locations[n].models.night.fonar = "DouPort_fn";
	Locations[n].models.night.charactersPatch = "DouPort_pn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map

	Locations[n].reload.l1.name = "reload3";
	Locations[n].reload.l1.go = "Douwesen_town";
	Locations[n].reload.l1.emerge = "reload9";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Douwesen";
	Locations[n].reload.l2.emerge = "reload_1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.reload2 = 3;
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Douwesen";
	Locations[n].reload.l3.emerge = "reload_1";
	Locations[n].reload.l3.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l3.label = "Ship.";
	else
		Locations[n].reload.l3.label = "Sea.";
	Locations[n].locators_radius.reload.reload1_back = 3;

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Douwesen";
	Locations[n].reload.l4.emerge = "reload_1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].locators_radius.reload.reload2_back = 3;
	if (VISIT_DECK == 1)
		Locations[n].reload.l4.label = "Ship.";
	else
		Locations[n].reload.l4.label = "Sea.";


	Locations[n].reload.l5.name = "reload1";
	Locations[n].reload.l5.go = "Douwesen";
	Locations[n].reload.l5.emerge = "reload_1";
	Locations[n].reload.l5.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l5.label = "Ship.";
	else
		Locations[n].reload.l5.label = "Sea.";
	Locations[n].locators_radius.reload.reload1 = 3;


	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_Douwesen\town";
	Locations[n].filespath.textures = "locations\HOLLAND";

	Locations[n].id = "Douwesen_town";
	locations[n].id.label = "#stown_name# town";
	Locations[n].image = "Town_Douwesen_Town.tga";
	locations[n].worldmap = "Douwesen";

	//Town sack
	Locations[n].townsack = "Douwesen";

	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "Douwesen";
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
	Locations[n].reload.l1.go = "Douwesen_port";
	Locations[n].reload.l1.emerge = "Reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Sea port.";

	Locations[n].reload.l2.name = "reload11";
	Locations[n].reload.l2.go = "Douwesen_shipyard";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Shipyard.";
	Locations[n].reload.l2.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l2.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Douwesen_tavern";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Tavern.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l3.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l4.name = "reload6";
	Locations[n].reload.l4.go = "Douwesen_UsurerHouse";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Loanshark's Office.";
	Locations[n].reload.l4.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l4.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l5.name = "reload4";
	Locations[n].reload.l5.go = "Douwesen_Store";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Store.";
	Locations[n].reload.l5.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l5.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l6.name = "reload19";
	Locations[n].reload.l6.go = "Douwesen_town_exit";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Jungle.";

	Locations[n].reload.l7.name = "reload15";
	Locations[n].reload.l7.go = "Douwesen_townhall";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Residence.";
	Locations[n].reload.l7.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l7.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l8.name = "reload18";
	Locations[n].reload.l8.go = "Douwesen_TailorsShop";
	Locations[n].reload.l8.emerge = "locator2"; //"reload1";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "Tailor's Shop";
	Locations[n].reload.l8.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l8.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l9.name = "reload1";
	Locations[n].reload.l9.go = "Douwesen_HouseInsideR1";
	Locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "House.";

	Locations[n].reload.l10.name = "reload5";
	Locations[n].reload.l10.go = "Douwesen_Dungeon";
	Locations[n].reload.l10.emerge = "reload1";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "????";

	// RobC/Alan_Smithee Blacksmiths -->
	if (ENABLE_WEAPONSMOD)
	{
		Locations[n].reload.l11.name = "reload7";
		Locations[n].reload.l11.go = "douw_blacksmith";
		Locations[n].reload.l11.emerge = "reload1";
		Locations[n].reload.l11.autoreload = "0";
		Locations[n].reload.l11.label = "Smithy";
		Locations[n].reload.l11.close_for_night = 1;
		if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l11.goto_disable = 1; // Screwface: Disable Go-To location
	}
	// RobC/Alan_Smithee Blacksmiths <--

	Locations[n].reload.l12.name = "reload14";
	Locations[n].reload.l12.go = "Dutch_Smuggler_Home";
	Locations[n].reload.l12.emerge = "reload1";
	Locations[n].reload.l12.autoreload = "0";
	Locations[n].reload.l12.label = "House.";
	Locations[n].reload.l12.disable = 1;

	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\inside\Residence4";

	Locations[n].id = "Douwesen_townhall";
	locations[n].id.label = "#stown_name# townhall";
	Locations[n].image = "Inside_Residence4.tga";

	//Town sack
	Locations[n].townsack = "Douwesen";

	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Douwesen";
	//Models
	//Always
	Locations[n].models.always.locators = "Res04_l";
	Locations[n].models.always.l1 = "Res04";
	Locations[n].models.always.window = "Res04_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "Res04_p";

	//Night
	Locations[n].models.night.charactersPatch = "Res04_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\dour4_";

	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Douwesen_town";
	Locations[n].reload.l1.emerge = "reload15";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;
	// -------------------------------------------------
	Locations[n].id = "Dutch_Smuggler_Home";
	locations[n].id.label = "Smuggler's Home";
	Locations[n].filespath.models = "locations\inside\DoubleFlour_house";
	Locations[n].image = "Inside_Doubleflour_House_Lower.tga";

	//Town sack
	Locations[n].townsack = "Douwesen";

	//Sound
	locations[n].type = "house";

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
	Locations[n].models.back = "back\doulf2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Douwesen_town";
	Locations[n].reload.l1.emerge = "reload14";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Town.";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_Douwesen\exit";
	Locations[n].filespath.textures = "locations\HOLLAND";

	Locations[n].id = "Douwesen_town_exit";
	locations[n].id.label = "Exit from #stown_name#";
	Locations[n].image = "Town_Douwesen_Exit.tga";

	//Town sack
	Locations[n].townsack = "Douwesen";

	//Sound
	locations[n].type = "jungle";
//	locations[n].fastreload = "Douwesen";
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
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Douwesen_Jungle_03";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 4;
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "Reload2";
	Locations[n].reload.l2.go = "Douwesen_town";
	Locations[n].reload.l2.emerge = "reload19";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name#.";

	Locations[n].reload.l3.name = "Reload1_back";
	Locations[n].reload.l3.go = "Douwesen_Jungle_03";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.Reload1_back = 4;
	Locations[n].reload.l3.label = "Jungle.";

	Locations[n].reload.l4.name = "Reload6";
	Locations[n].reload.l4.go = "Douwesen_Cavern";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "????";


	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\shipyard";

	Locations[n].id = "Douwesen_shipyard";
	locations[n].id.label = "#stown_name# shipyard";
	Locations[n].image = "Inside_Shipyard1.tga";

	//Town sack
	Locations[n].townsack = "Douwesen";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Douwesen";
	//Models
	//Always
	Locations[n].models.always.locators = "sh01_l";
	Locations[n].models.always.shipyard = "sh01";
	Locations[n].models.always.window = "sh01_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "sh01_p";
	Locations[n].models.day.fd = "sh01_fd";

	//Night
	Locations[n].models.night.charactersPatch = "sh01_p";
	Locations[n].models.night.fn = "sh01_fn";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\doush1_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Douwesen_town";
	Locations[n].reload.l1.emerge = "Reload11";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\LargeStore";
	Locations[n].image = "Inside_LargeStore.tga";

	Locations[n].id = "Douwesen_Store";
	locations[n].id.label = "#stown_name# store";

	//Town sack
	Locations[n].townsack = "Douwesen";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Douwesen";
	//Models
	//Always
	Locations[n].models.always.locators = "LS_l";
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
	Locations[n].reload.l1.go = "Douwesen_town";
	Locations[n].reload.l1.emerge = "Reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\SmallTavern";

	Locations[n].id = "Douwesen_Tavern";
	locations[n].id.label = "#stown_name# tavern.";
	Locations[n].image = "Inside_SmallTavern.tga";

	//Town sack
	Locations[n].townsack = "Douwesen";

	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "Douwesen";
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
	Locations[n].models.back = "back\doust_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Douwesen_Town";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	LAi_LocationFightDisable(&Locations[n], true);

//MAXIMUS -->
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Douwesen_tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Room in #stown_name# tavern.";
	Locations[n].reload.l2.disable = 1;
	LAi_LocationFightDisable(&Locations[n], true);
//MAXIMUS <--


	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;

// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Doubleflour_house";
	Locations[n].id = "Douwesen_tavern_upstairs";
	locations[n].id.label = "Room in #stown_name# tavern."; // KK
	Locations[n].image = "Inside_Doubleflour_House_Room.tga";

	//Town sack
	Locations[n].townsack = "Douwesen";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Douwesen";
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F2_l";
	Locations[n].models.always.tavern = "LH_F2";
	Locations[n].models.always.window = "LH_F2_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Locations[n].models.always.env = "smalltavern_env";
	//Day
	Locations[n].models.day.charactersPatch = "LH_F2_p";

	//Night
	Locations[n].models.night.charactersPatch = "LH_F2_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\doulf2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Douwesen_tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# tavern."; // KK


	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\MediumHouse";
	Locations[n].id = "Douwesen_UsurerHouse";
	locations[n].id.label = "Loanshark's Office.";
	Locations[n].image = "Inside_MediumHouse.tga";

	//Town sack
	Locations[n].townsack = "Douwesen";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Douwesen";
	//Models
	//Always
	Locations[n].models.always.locators = "MH_l";
	Locations[n].models.always.house = "MH";
	//Locations[n].models.always.env = "smalltavern_env";
	Locations[n].models.always.window = "MH_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "MH_p";

	//Night
	Locations[n].models.night.charactersPatch = "MH_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\doumh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Douwesen_town";
	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;


	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\mh3";
	Locations[n].id = "Douwesen_HouseInsideR1";
	locations[n].id.label = "House.";
	Locations[n].image = "Inside_mh3.tga";

	//Town sack
	Locations[n].townsack = "Douwesen";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Douwesen";
	//Models
	//Always
	Locations[n].models.always.locators = "MH3_l";
	Locations[n].models.always.house = "MH3";
	//Locations[n].models.always.env = "smalltavern_env";
	Locations[n].models.always.window = "MH3_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "MH3_p";

	//Night
	Locations[n].models.night.charactersPatch = "MH3_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\doumh3_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Douwesen_town";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";


	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	
	// Douwesen Tailor
	Locations[n].id = "Douwesen_TailorsShop";
	locations[n].id.label = "Tailor's Shop";
	Locations[n].image = "Inside_StoreSmall.tga";

	//Town sack
	Locations[n].townsack = "Douwesen";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Douwesen";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\StoreSmall";
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
	Locations[n].models.back = "back\doulf1_";
	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "Douwesen_town";
	Locations[n].reload.l1.emerge = "reload18";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	Locations[n].locators_radius.reload.locator2 = 0.7;

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Pirate Fort";

	Locations[n].id = "Pirate_Fort";
	locations[n].id.label = "Pirate Fort";
	Locations[n].image = "Pirate_Fort.tga";

	//Town sack
	Locations[n].townsack = "Pirate Fort"; // NK 04-08-29

	//Sound
	locations[n].type = "jungle";
	Locations[n].fastreload = "Pirate_fort";

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
	Locations[n].reload.l1.go = "Douwesen_Jungle_01";
	Locations[n].reload.l1.emerge = "Reload1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].reload.l1.autoreload = 1;
	Locations[n].locators_radius.reload.reload1 = 1;

	Locations[n].reload.l5.name = "Reload1_back";
	Locations[n].reload.l5.go = "Douwesen_Jungle_01";
	Locations[n].reload.l5.emerge = "Reload1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].reload.l5.autoreload = 1;
	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].reload.l2.name = "Reload5";
	Locations[n].reload.l2.go = "Douwesen_Pirate_Residence";
	Locations[n].reload.l2.emerge = "Reload1";
	Locations[n].reload.l2.label = "Chief's House.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l2.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l3.name = "Reload6";
	Locations[n].reload.l3.go = "Pirate_tavern";
	Locations[n].reload.l3.emerge = "Reload1";
	Locations[n].reload.l3.label = "Tavern.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l3.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l4.name = "Reload2";
	Locations[n].reload.l4.go = "Douwesen_Pirates_TailorsShop";
	Locations[n].reload.l4.emerge = "locator2"; //r1
	Locations[n].reload.l4.label = "Tailor's Shop.";
	Locations[n].reload.l4.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l4.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l6.name = "reload3";
	Locations[n].reload.l6.go = "Pirate_Store";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Store.";
	Locations[n].reload.l6.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l6.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;

		//---------------------------------------------------

	Locations[n].filespath.models = "locations\inside\mediumHouse";

	Locations[n].id = "Douwesen_Pirate_Residence";
	locations[n].id.label = "House of leader of #sisland_name# pirates";
	Locations[n].image = "Inside_MediumHouse.tga";

	//Town sack
	Locations[n].townsack = "Pirate Fort"; // NK 04-08-29

	//Sound
	locations[n].type = "house";
	Locations[n].fastreload = "Pirate_fort";

	//Models
	//Always
	Locations[n].models.always.locators = "MH_l";
	Locations[n].models.always.house = "MH";
	//Locations[n].models.always.env = "smalltavern_env";
	Locations[n].models.always.window = "MH_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "MH_p";

	//Night
	Locations[n].models.night.charactersPatch = "MH_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\doumh_";
	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Pirate_Fort";
	Locations[n].reload.l1.emerge = "Reload5";
	//fake reload
	/*
	Locations[n].reload.l2.name = "to_Ship_deck";
	Locations[n].reload.l2.go = "Ship_deck";
	Locations[n].reload.l2.emerge = "locator2";
	*/

	Locations[n].vcskip = true; // KK

	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;


	// -------------------------------------------------

	// Douwesen Pirates Tailor
	Locations[n].id = "Douwesen_Pirates_TailorsShop";
	Locations[n].id.label = "Tailor's Shop";
	Locations[n].image = "Inside_StoreSmall.tga";
	
	//Town sack
	Locations[n].townsack = "Pirate Fort"; // NK 04-08-29

	//Sound
	locations[n].type = "shop";
	Locations[n].fastreload = "Pirate_fort";
		
	//Models
	Locations[n].filespath.models = "locations\inside\StoreSmall";
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
	Locations[n].models.back = "back\pifsh_";
	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "Pirate_Fort";
	Locations[n].reload.l1.emerge = "Reload2";
	Locations[n].reload.l1.label = "Pirate Fort.";
	Locations[n].locators_radius.reload.locator2 = 0.7;

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;
	
	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\LargeStore";
	Locations[n].image = "Inside_LargeStore.tga";

	Locations[n].id = "Pirate_Store";
	locations[n].id.label = "#stown_name# store";

	//Town sack
	Locations[n].townsack = "Pirate Fort"; // NK 04-08-29

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Pirate_Fort";
	//Models
	//Always
	Locations[n].models.always.locators = "LS_l";
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
	Locations[n].reload.l1.go = "Pirate_Fort";
	Locations[n].reload.l1.emerge = "Reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;
	
	// -------------------------------------------------


	Locations[n].filespath.models = "locations\Outside\Jungle_2";

	Locations[n].id = "Douwesen_Jungle_01";
	locations[n].id.label = "#sisland_name# jungles";
	Locations[n].image = "Outside_Jungle_2.tga";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	Locations[n].fastreload = "Pirate_fort";

	//Models
	//Always
	Locations[n].models.always.locators = "Jungle02_l";
	Locations[n].models.always.jungle = "Jungle02";
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
	Locations[n].reload.l1.go = "Pirate_Fort";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Pirate Fort.";
	Locations[n].locators_radius.reload.reload1 = 4;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Pirate_Fort";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Pirate Fort.";
	Locations[n].locators_radius.reload.reload1_back = 4;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Douwesen_Shore_01";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Palm Beach.";
	Locations[n].locators_radius.reload.reload2 = 4;

	Locations[n].reload.l5.name = "reload2_back";
	Locations[n].reload.l5.go = "Douwesen_Shore_01";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Palm Beach.";
	Locations[n].locators_radius.reload.reload2_back = 3;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Douwesen_jungle_02";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3 = 4;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Douwesen_jungle_02";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 4;

	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Shore_5";

	Locations[n].id = "Douwesen_shore_01";
	locations[n].id.label = "Palm Beach"; // KK
	Locations[n].image = "Outside_Shore_5.tga";
	Locations[n].name = "Palm Beach";
	locations[n].worldmap = "DShore 1";

	//Sound
	locations[n].type = "seashore";

	Locations[n].townsack = "Pirate Fort"; // KK
	Locations[n].fastreload = "Pirate_fort";
	//Models
	//Always
	Locations[n].models.always.jungle = "Shore05";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.locators = "Shore05_l";
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
	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Douwesen_Jungle_01";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 3;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Douwesen_Jungle_01";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Douwesen";
	Locations[n].reload.l2.emerge = "reload_2";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 9.0;


	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_7";

	Locations[n].id = "Douwesen_Jungle_02";
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
	Locations[n].reload.l1.go = "Rheims_house";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "House.";
	Locations[n].locators_radius.reload.reload1 = 4;

	Locations[n].reload.l5.name = "reload1_back";
	Locations[n].reload.l5.go = "Rheims_house";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "House.";
	Locations[n].locators_radius.reload.reload1_back = 1;

	Locations[n].reload.l4.name = "reload2";
	Locations[n].reload.l4.go = "Douwesen_jungle_01";
	Locations[n].reload.l4.emerge = "reload3";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 4;

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Douwesen_jungle_01";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Douwesen_Jungle_03";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3 = 4;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Douwesen_Jungle_03";
	Locations[n].reload.l6.emerge = "reload3";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 2;


	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Shore_10";

	Locations[n].id = "Douwesen_shore_02";
	locations[n].id.label = "Crab Cliffs"; // KK
	Locations[n].image = "Outside_Shore_10.tga";
	Locations[n].name = "Crab Cliffs";
	Locations[n].worldmap = "DShore 2";
	//Sound
	locations[n].type = "seashore";

	//Models
	//Always
	Locations[n].models.always.jungle = "shore10";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.locators = "shore10_l";
    Locations[n].models.always.seabed = "shore10_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "Shore10_g";
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
	Locations[n].models.day.charactersPatch = "shore10_p";
	//Night
	Locations[n].models.night.charactersPatch = "shore10_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Douwesen_Jungle_03";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 3;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Douwesen_Jungle_03";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Douwesen";
	Locations[n].reload.l2.emerge = "reload_3";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 9.0;

	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;

// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_4";

	Locations[n].id = "Douwesen_Jungle_03";
	locations[n].id.label = "#sisland_name# jungles";
	Locations[n].image = "Outside_Jungle_4.tga";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);


	//Models
	//Always
	Locations[n].models.always.locators = "Jungle04_l";
	Locations[n].models.always.jungle = "Jungle04";
	Locations[n].models.always.grassPatch = "JUNGLE04_g";
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
	Locations[n].models.day.charactersPatch = "Jungle04_p";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle04_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Douwesen_town_exit";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1 = 4;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Douwesen_town_exit";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Douwesen_Shore_02";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Crab Cliffs.";
	Locations[n].locators_radius.reload.reload2 = 4;

	Locations[n].reload.l5.name = "reload2_back";
	Locations[n].reload.l5.go = "Douwesen_Shore_02";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Crab Cliffs.";
	Locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Douwesen_jungle_02";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3 = 4;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Douwesen_jungle_02";
	Locations[n].reload.l6.emerge = "reload3";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 3;


	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Rheims House";

	Locations[n].id = "Rheims_House";
	locations[n].id.label = "House in Jungle";
	Locations[n].image = "Outside_Rheims_House.tga";
	//Sound
	locations[n].type = "house";

	//Models
	//Always
	Locations[n].models.always.locators = "Rhouse_l";
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

	//Day
	Locations[n].models.day.charactersPatch = "Rhouse_p";
	//Night
	Locations[n].models.night.charactersPatch = "Rhouse_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Douwesen_jungle_02";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1 = 3;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Douwesen_jungle_02";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 3;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Rheims_house_inside";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "House";

/*
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "";
	Locations[n].reload.l3.emerge = "";*/


	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\inside\mediumHouse";

	Locations[n].id = "Rheims_House_inside";
	locations[n].id.label = "Rheims house on #sisland_name#";
	Locations[n].image = "Inside_MediumHouse.tga";
	//Sound
	locations[n].type = "house";

	//Models
	//Always
	Locations[n].models.always.locators = "MH_l";
	Locations[n].models.always.house = "MH";
	//Locations[n].models.always.env = "smalltavern_env";
	Locations[n].models.always.window = "MH_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "MH_p";

	//Night
	Locations[n].models.night.charactersPatch = "MH_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\smumh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Rheims_House";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Exit.";


	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;

// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\MediumTavern";

	Locations[n].id = "Pirate_Tavern";
	locations[n].id.label = "Tavern";
	Locations[n].image = "Inside_MediumTavern.tga";

	//Town sack
	Locations[n].townsack = "Pirate Fort"; // NK 04-08-29

	//Sound
	locations[n].type = "tavern";
	Locations[n].fastreload = "Pirate_fort";

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
	Locations[n].models.back = "back\smumt_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Pirate_Fort";
	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Pirate Fort.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Pirate_tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Room.";
	Locations[n].reload.l2.disable = 1;

	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Doubleflour_house";
	Locations[n].id = "Pirate_tavern_upstairs";
	locations[n].id.label = "Room in Pirate tavern";
	Locations[n].image = "Inside_Doubleflour_House_Room.tga";

	//Town sack
	Locations[n].townsack = "Pirate Fort"; // NK 04-08-29

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Douwesen";
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
	Locations[n].models.back = "back\smumt_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Pirate_tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Pirate tavern."; // KK
	Locations[n].reload.l1.disable = 0;
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;

	// ------------------------------------------------- Корабль с сокровищами для квеста про Найджела Блайта

	Locations[n].filespath.models = "locations\Outside\Shore_ship";

	Locations[n].id = "Douwesen_shore_ship";
	locations[n].id.label = "#sisland_name# shore.";
	Locations[n].image = "Outside_Shore_Ship.tga";
	Locations[n].name = "Ship";
	//Sound
	locations[n].type = "seashore";

	//Models
	//Always
	Locations[n].models.always.jungle = "ShoreShip";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.locators = "ShoreShip_l";
	Locations[n].models.always.grassPatch = "ShoreShip_g";
	Locations[n].models.always.seabed = "ShoreShip_sb";
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
	Locations[n].models.day.charactersPatch = "ShoreShip_p";
	//Night
	Locations[n].models.night.charactersPatch = "ShoreShip_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Douwesen_cavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "The cavern";
	Locations[n].locators_radius.reload.reload2 = 1;

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Douwesen_cavern";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "The cavern";
	Locations[n].locators_radius.reload.reload2_back = 3;

	if(GetCurrentPeriod() < PERIOD_REVOLUTIONS)	Locations[n].items.randitem1 = "pistol8";
	else										Locations[n].items.randitem1 = "pistol4";

	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 0, 24);


	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;

	// -----------------Mosh D24--------------------
	Locations[n].filespath.models = "locations\Inside\Dungeon_4";
	Locations[n].id = "Douwesen_dungeon";
	Locations[n].image = "Inside_Dungeon_4.tga";
//	Locations[n].monsters = "1";

	//Sound
	locations[n].type = "dungeon";
	//Models
	Locations[n].models.back = "back\d04env_";
	//Always
	Locations[n].models.always.locators = "d04_l";
	Locations[n].models.always.house = "d04";
	//Day
	Locations[n].models.day.charactersPatch = "d04_p";
	//Night
	Locations[n].models.night.charactersPatch = "d04_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Douwesen_town";//Mosh
	Locations[n].reload.l1.emerge = "reload5";

	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 0, 24);

	Locations[n].items.randitem1 = "blade12";


	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;


// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Cavern";

	Locations[n].id = "Douwesen_Cavern";
	locations[n].id.label = "#sisland_name# Cavern";
	Locations[n].image = "Inside_Cavern.tga";

	//Sound
	locations[n].type = "cave";
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
	Locations[n].reload.l1.go = "Douwesen_town_exit";
	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "#sisland_name# Outskirts.";

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Douwesen_town_exit";
	Locations[n].reload.l2.emerge = "reload6";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "#sisland_name# Outskirts";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Douwesen_shore_ship";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "?????";

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Douwesen_shore_ship";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "?????";
	Locations[n].locators_radius.reload.reload2_back = 2;

	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 0, 24);



	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;
}
