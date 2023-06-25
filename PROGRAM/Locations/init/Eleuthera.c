void LocationInitEleuthera(ref n)
{
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ELEUTHERA
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Eleuthera_Port";
	locations[n].id.label = "#stown_name# Port";
	locations[n].worldmap = "Eleuthera";
	locations[n].filespath.models = "locations\Town_Eleuthera";
	locations[n].image = "Town_Eleuthera.tga";

	//Town sack
	locations[n].townsack = "Eleuthera";
	if(GetCurrentPeriod() >= PERIOD_COLONIAL_POWERS) Locations[n].navy = 1;

	//Sound
	locations[n].type = "port"; // put port for water ambiance
	locations[n].fastreload = "Eleuthera";
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	locations[n].models.always.town = "Eleuthera";
	locations[n].models.always.town.foam = "1";
	locations[n].models.always.L1 = "Eleuthera_signsA";
	Locations[n].models.always.seabed = "Eleuthera_sb";
	Locations[n].models.always.seabed.foam = "1";
	locations[n].models.always.locators = "Eleuthera_locators";
	locations[n].models.always.grassPatch = "Eleuthera_grass";
	
	locations[n].models.always.plan = "plan1";
	locations[n].models.always.plan.level = 9;

	//Day
	locations[n].models.day.fonar = "Eleuthera_fd";
	locations[n].models.day.charactersPatch = "Eleuthera_patch_day";
	locations[n].models.day.rinok = "Eleuthera_rinok";
	//Night
	locations[n].models.night.fonar = "Eleuthera_fn";
	locations[n].models.night.charactersPatch = "Eleuthera_patch_night";

    //upgrades
	Locations[n].upgrades = "upgrades";
	Locations[n].models.always.shipyard = "shipyard4";
	Locations[n].models.always.shipyard.status = "shipyard4";
	InitUpgrades(Locations[n].id);

	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map

	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Eleuthera";
	locations[n].reload.l1.emerge = "reload_1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Sea";
	locations[n].locators_radius.reload.reload1_back = 1.8;

    locations[n].reload.l2.name = "reload1";
	locations[n].reload.l2.go = "Eleuthera";
	locations[n].reload.l2.emerge = "reload_1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Sea";
	locations[n].locators_radius.reload.reload1 = 1.8;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Eleuthera_townhall";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "#stown_name# Residence";
	Locations[n].reload.l3.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l3.goto_disable = 1; // Screwface: Disable Go-To location

	locations[n].reload.l4.name = "reload4_back";
	locations[n].reload.l4.go = "Eleuthera_tavern";
	locations[n].reload.l4.emerge = "reload2";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "#stown_name# Tavern";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l4.goto_disable = 1; // Screwface: Disable Go-To location

	locations[n].reload.l5.name = "reload5_back";
	locations[n].reload.l5.go = "Eleuthera_shipyard";
	locations[n].reload.l5.emerge = "reload1";
	locations[n].reload.l5.autoreload = "0";
	locations[n].reload.l5.label = "#stown_name# Shipyard";
	Locations[n].reload.l5.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l5.goto_disable = 1; // Screwface: Disable Go-To location

	locations[n].reload.l6.name = "reload6_back";
	locations[n].reload.l6.go = "Eleuthera_store";
	locations[n].reload.l6.emerge = "reload1";
	locations[n].reload.l6.autoreload = "0";
	locations[n].reload.l6.label = "#stown_name# Store";
	Locations[n].reload.l6.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l6.goto_disable = 1; // Screwface: Disable Go-To location

	locations[n].reload.l7.name = "reload7_back";
	locations[n].reload.l7.go = "Eleuthera_church";
	locations[n].reload.l7.emerge = "reload1";
	locations[n].reload.l7.autoreload = "0";
	locations[n].reload.l7.label = "#stown_name# Church";
	Locations[n].reload.l7.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l7.goto_disable = 1; // Screwface: Disable Go-To location

	locations[n].reload.l8.name = "reload8_back";
	locations[n].reload.l8.go = "Eleuthera_bank";
	locations[n].reload.l8.emerge = "reload1";
	locations[n].reload.l8.autoreload = "0";
	locations[n].reload.l8.label = "#stown_name# Loanshark's Office.";
	//locations[n].reload.l8.disable = 1;
	Locations[n].reload.l8.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l8.goto_disable = 1; // Screwface: Disable Go-To location

    	Locations[n].reload.l11.name = "gate";
	Locations[n].reload.l11.go = "EleutheraPlantation";
	Locations[n].reload.l11.emerge = "reload1";
	Locations[n].reload.l11.autoreload = "0";
	Locations[n].reload.l11.label = "#stown_name# Plantation";
	Locations[n].locators_radius.reload.gate = 2.0;

	if(IsBrothelEnabled())
	{
		Locations[n].reload.l12.name = "HouseS2";
		Locations[n].reload.l12.go = "Eleuthera_brothel";
		Locations[n].reload.l12.emerge = "reload1_back";
		Locations[n].reload.l12.autoreload = "0";
		Locations[n].reload.l12.label = "#stown_name# Brothel";
		if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l12.goto_disable = 1; // Screwface: Disable Go-To location
	}

	Locations[n].reload.l13.name = "HouseSp1";
	Locations[n].reload.l13.go = "Eleuthera_TailorsShop";
	Locations[n].reload.l13.emerge = "locator2";
	Locations[n].reload.l13.autoreload = "0";
	Locations[n].reload.l13.label = "Tailor's Shop.";
	Locations[n].reload.l13.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l13.goto_disable = 1;

	Locations[n].island = "Eleuthera"; // added
	n = n + 1;

  	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// TAVERN
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Locations[n].id = "Eleuthera_tavern";
	locations[n].id.label = "#stown_name# Tavern";
	//Town sack
	locations[n].townsack = "Eleuthera";
	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "Eleuthera";
	//Models

	InitTavern01(Locations[n].id);

	//Reload map
	Locations[n].reload.l2.go = "Eleuthera_Port";
	locations[n].reload.l2.emerge = "reload4";
	Locations[n].reload.l2.label = "#stown_name# Port";

	Locations[n].reload.l1.go = "Eleuthera_tavern_upstairs";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Cellar in #stown_name# tavern";
	Locations[n].reload.l1.disable = true; // KK

	Locations[n].island = "Eleuthera"; // added
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ÊÎÌÍÀÒÀ Â ÒÀÂÅÐÍÅ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Eleuthera_tavern_upstairs";
	locations[n].id.label = "Cellar in #stown_name# tavern.";
    locations[n].filespath.models = "locations\inside\Cellar_downstairs";
	locations[n].image = "Inside_Cellar_downstairs.tga";

	//Town sack
	locations[n].townsack = "Eleuthera";

	//Sound
	locations[n].type = "dungeon";
	locations[n].fastreload = "Eleuthera";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Cellar_downstairs";
	locations[n].models.always.locators = "Cellar_downstairs_locators_Eleuthera";
	locations[n].models.always.tavern = "Cellar_downstairs";
	locations[n].models.always.rays = "Cellar_downstairs_rays";
	locations[n].models.always.stuff = "Cellar_downstairs_stuff";

	//Day
	locations[n].models.day.charactersPatch = "Cellar_downstairs_patch";

	//Night
	locations[n].models.night.charactersPatch = "Cellar_downstairs_patch";

	//Environment
	locations[n].environment.weather = "false";
	locations[n].environment.sea = "false";

	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Eleuthera_Tavern";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "#stown_name# Tavern";
	locations[n].locators_radius.reload.reload1 = 0.8;

    Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Eleuthera_CavernMedium";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "?????";

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Eleuthera_CavernMedium";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "?????";

	locations[n].reload.l2.name = "reload3_back";			//JRH
	locations[n].reload.l2.go = "Eleuthera_Shore";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "#stown_name# Tavern";

	Locations[n].locators_radius.randitem.randitem3 = 0.0001;
	Locations[n].items.randitem3 = "gatedoor_w8";

	Locations[n].island = "Eleuthera";
	n = n + 1;
	//---------------------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Passage";

	Locations[n].id = "Eleuthera_shore";
	locations[n].id.label = "Citadel Rock."; 
	locations[n].worldmap = "EleutheraShore 1";
	Locations[n].image = "Outside_Citadel_Rock.tga";
	Locations[n].name = "Citadel Rock";

	//Town sack
	locations[n].townsack = "Eleuthera";

	//Sound
	locations[n].type = "seashore";

	//Models
	//Always
	Locations[n].models.always.locators = "Pass1_l_Eleuthera";
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
	Locations[n].models.always.l4 = "fort_ruin";
	Locations[n].models.always.l5 = "";			//leverC_up, leverC_down
	Locations[n].models.always.l6 = "anchor_big1";		//anchor_big1, 2, 3

	//Day
	Locations[n].models.day.charactersPatch = "Pass1_p";
	//Night
	Locations[n].models.night.charactersPatch = "Pass1_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l2.name = "reload1";
	Locations[n].reload.l2.go = "Eleuthera_tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Sea Passage.";

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Eleuthera_tavern_upstairs";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Sea Passage.";

	Locations[n].reload.l1.name = "boat";
	Locations[n].reload.l1.go = "Eleuthera";
	Locations[n].reload.l1.emerge = "reload_4";
	Locations[n].reload.l1.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l1.label = "Ship.";
	else
		Locations[n].reload.l1.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 9.0;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "Citadel_cave";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].locators_radius.reload.reload4 = 0.001;		//large when discovered from inside

	Locations[n].reload.l5.name = "reload5";
	Locations[n].reload.l5.go = "Citadel_tower_stairs1";
	Locations[n].reload.l5.emerge = "reload8";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].locators_radius.reload.reload5 = 0.2;		

	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "Citadel_tower_stairs2";
	Locations[n].reload.l6.emerge = "reload8";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].locators_radius.reload.reload6 = 0.2;

	Locations[n].locators_radius.box.box2 = 0.2;
	Locations[n].locators_radius.box.box12 = 0.2;
	Locations[n].locators_radius.box.box13 = 0.2;
	Locations[n].locators_radius.box.box20 = 0.2;
	Locations[n].locators_radius.box.box25 = 0.2;
	Locations[n].locators_radius.box.box27 = 0.2;
	Locations[n].locators_radius.box.box28 = 0.2;
	Locations[n].locators_radius.box.box29 = 0.2;
	Locations[n].locators_radius.box.box31 = 0.2;
	Locations[n].locators_radius.box.box32 = 0.2;
	Locations[n].locators_radius.box.box33 = 0.2;
	Locations[n].locators_radius.box.box34 = 0.2;
	Locations[n].locators_radius.box.box35 = 0.2;
	Locations[n].locators_radius.box.box37 = 0.2;
	Locations[n].locators_radius.box.box38 = 0.2;
	Locations[n].locators_radius.box.box39 = 0.2;
	Locations[n].locators_radius.box.box40 = 0.0001;
	Locations[n].locators_radius.quest.quest11 = 1.0;

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "gatedoor_w8";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "suspension_bridge_ropes";		

	Locations[n].locators_radius.randitem.randitem4 = 0.01;		//bridge: closed
	Locations[n].items.randitem4 = "door_H1_small";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;		//ground: closed
	Locations[n].items.randitem5 = "door_H1_small";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "pole1";

	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "stoneblock";

	Locations[n].locators_radius.randitem.randitem8 = 0.01;
	Locations[n].items.randitem8 = "steplock_v";

	Locations[n].locators_radius.randitem.randitem9 = 0.01;
	Locations[n].items.randitem9 = "suspension_bridge";

	Locations[n].locators_radius.randitem.randitem10 = 0.01;
	Locations[n].items.randitem10 = "hatch11";

	Locations[n].locators_radius.randitem.randitem11 = 0.01;		//bridge: open
	Locations[n].items.randitem11 = "door_H1_small";

	Locations[n].locators_radius.randitem.randitem12 = 0.01;		//bridge: inner door
	Locations[n].items.randitem12 = "door_N09";	
	
	Locations[n].locators_radius.randitem.randitem13 = 0.01;		//ground: open
	Locations[n].items.randitem13 = "door_H1_small";

	Locations[n].locators_radius.randitem.randitem14 = 0.01;		//ground: inner door
	Locations[n].items.randitem14 = "door_N09";

	Locations[n].locators_radius.randitem.randitem15 = 0.01;
	Locations[n].items.randitem15 = "small_planks";

	Locations[n].island = "Eleuthera"; // NK 04-08-29
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// STORE
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Eleuthera_store";
	locations[n].id.label = "#stown_name# store";
	locations[n].filespath.models = "locations\inside\Store03";
	locations[n].image = "Inside_Store03.tga";

	//Town sack
	locations[n].townsack = "Eleuthera";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Eleuthera";
	//Models
	//Always
	locations[n].models.always.locators = "Store03_locators";
	locations[n].models.always.store = "Store03";
	locations[n].models.always.window = "store03_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 50;

	Locations[n].models.back = "..\back\inside_back_";
	//Day
	locations[n].models.day.charactersPatch = "Store03_patch";

	//Night
	locations[n].models.night.charactersPatch = "Store03_patch";

	//Environment
	locations[n].environment.weather = "false";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Eleuthera_Port";
	locations[n].reload.l1.emerge = "reload6";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "#stown_name# Port";
	LAi_LocationFightDisable(&locations[n], true);

	Locations[n].island = "Eleuthera";
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// BANK
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Eleuthera_bank";
	locations[n].id.label = "#stown_name# Loanshark's Office";
	//Town sack
	locations[n].townsack = "Eleuthera";
	//Sound
	locations[n].type = "shop"; // change to avoid other people than loanshark "house";
	locations[n].fastreload = "Eleuthera";

	InitBank(Locations[n].id);

	//Reload map
	locations[n].reload.l1.go = "Eleuthera_Port";
	locations[n].reload.l1.emerge = "reload8";
	Locations[n].reload.l1.label = "#stown_name# Port";
	LAi_LocationFightDisable(&locations[n], true);

	Locations[n].island = "Eleuthera";
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// SHIPYARD
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Eleuthera_Shipyard";
	locations[n].id.label = "#stown_name# shipyard";
	locations[n].filespath.models = "locations\inside\Shipyard5";
	locations[n].image = "Inside_Shipyard5.tga";

	//Town sack
	locations[n].townsack = "Eleuthera";

	//Sound
	locations[n].type = "shipyard";
	locations[n].fastreload = "Eleuthera";
	//Models
	//Always
	locations[n].models.always.locators = "sh05_locators";
	locations[n].models.always.shipyard = "sh05";
	//Day
	locations[n].models.day.charactersPatch = "sh05_patch";

	//Night
	locations[n].models.night.charactersPatch = "sh05_patch";

	//Environment
	locations[n].environment.weather = "false";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Eleuthera_Port";
	locations[n].reload.l1.emerge = "reload5";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "#stown_name# Port";
	LAi_LocationFightDisable(&locations[n], true);

	Locations[n].island = "Eleuthera";
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// TOWNHALL
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Eleuthera_townhall";
	locations[n].id.label = "#stown_name# townhall";
	//Town sack
	locations[n].townsack = "Eleuthera";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Eleuthera";

	InitResidence7(Locations[n].id);

	//Reload map
	Locations[n].reload.l1.go = "Eleuthera_Port";
	Locations[n].reload.l1.label = "#stown_name# Port";
	LAi_LocationFightDisable(&locations[n], true);

	Locations[n].island = "Eleuthera";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// CHURCH
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Eleuthera_church";
	locations[n].id.label = "#stown_name# Church";
	//Town sack
	locations[n].townsack = "Eleuthera";
	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "Eleuthera";

	InitChurch1(Locations[n].id);

	//Reload map
	Locations[n].reload.l1.go = "Eleuthera_Port";
	locations[n].reload.l1.emerge = "reload7";
	Locations[n].reload.l1.label = "#stown_name# Port";

	Locations[n].island = "Eleuthera";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// TAILOR'S SHOP
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "Eleuthera_TailorsShop";	
	Locations[n].id.label = "Tailor's Shop.";
	Locations[n].image = "Inside_StoreSmall.tga";

	//Town sack
	Locations[n].townsack = "Eleuthera";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Eleuthera";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Inside\StoreSmall";
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
	Locations[n].models.back = "..\back\inside_back_";

	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "Eleuthera_Port";
	Locations[n].reload.l1.emerge = "HouseSp1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";
	Locations[n].locators_radius.reload.locator2 = 0.7;

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Eleuthera"; // NK 04-08-29
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// SHORE SHIP
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].filespath.models = "locations\Outside\Shore_ship";

	Locations[n].id = "Eleuthera_shore_Ship";
	locations[n].id.label = "Eleuthera shore";
	Locations[n].image = "Outside_Shore_Ship.tga";
	Locations[n].name = "Ship";
	//Sound
	locations[n].type = "seashore";

	//Models
	//Always
	Locations[n].models.always.jungle = "Shoreship";
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
	Locations[n].reload.l2.name = "reload1";//au lieu de 2
	Locations[n].reload.l2.go = "Eleuthera_jungle2";
	Locations[n].reload.l2.emerge = "reload2";//au lieu de 2
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle";
	Locations[n].locators_radius.reload.reload2 = 1;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Eleuthera_jungle2";
	Locations[n].reload.l3.emerge = "reload2";//au lieu de 2
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle";
	Locations[n].locators_radius.reload.reload2_back = 3;
       
	LAi_LocationMonstersGen(&locations[n], false);

	Locations[n].island = "Eleuthera";
	n = n + 1;

    // -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Cavern";

	Locations[n].id = "Eleuthera_Cavern";
	locations[n].id.label = "Eleuthera Cavern";
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
	Locations[n].reload.l1.go = "Eleuthera_CavernMedium";
	Locations[n].reload.l1.emerge = "reload1";//au lieu de 6
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "#stown_name# Outskirts.";

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Eleuthera_CavernMedium";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "#stown_name# Outskirts";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Eleuthera_Cave_Exit";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "?????";

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Eleuthera_Cave_Exit";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "?????";
	Locations[n].locators_radius.reload.reload2_back = 2;


	Locations[n].island = "Eleuthera";
	n = n + 1;

    // -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\CavernMedium";

	Locations[n].id = "Eleuthera_CavernMedium";
	locations[n].id.label = "Eleuthera Cavern";
	Locations[n].image = "Inside_cavernMedium.tga";

	//Sound
	locations[n].type = "cave";
	//Models
	//Always
	Locations[n].models.always.locators = "CavernMedium_locators";
	Locations[n].models.always.l1 = "CavernMedium";
	//Locations[n].models.always.l2 = "Crystals";
	//Locations[n].models.always.l2.tech = "EnvironmentShader";
	//Locations[n].models.always.l2.reflection = 0.25;

	Locations[n].models.always.l3 = "cavernMedium_lamps";

	//Locations[n].models.always.Waterfall1 = "water";
	//Locations[n].models.always.Waterfall1.uvslide.v0 = 0.0;
    //Locations[n].models.always.Waterfall1.uvslide.v1 = 0.0;
    //Locations[n].models.always.Waterfall1.tech = "LocationWaterFall";
	//Locations[n].models.always.Waterfall1.level = 50;

	//Locations[n].models.always.Waterfall2 = "cfall";
	//Locations[n].models.always.Waterfall2.uvslide.v0 = 0.3;
    //Locations[n].models.always.Waterfall2.uvslide.v1 = 0.0;
	//Locations[n].models.always.Waterfall2.tech = "LocationWaterFall";
	//Locations[n].models.always.Waterfall2.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "CavernMedium_patch";
	//Night
	Locations[n].models.night.charactersPatch = "CavernMedium_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Eleuthera_Cavern";//au lieu de CavernMedium
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "#stown_name# Outskirts";

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Eleuthera_Cavern";
	Locations[n].reload.l2.emerge = "reload1";//au lieu de 4
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "#stown_name# Outskirts";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Eleuthera_tavern_upstairs";
	Locations[n].reload.l3.emerge = "reload2";//au lieu de 1
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "?????";

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Eleuthera_tavern_upstairs";
	Locations[n].reload.l4.emerge = "reload2";//au lieu de 1
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "?????";
	Locations[n].locators_radius.reload.reload2_back = 2;

	LAi_LocationMonstersGen(&locations[n], false);
	//LAi_LocationSetMonstersTime(&locations[n], 0, 24);

	Locations[n].island = "Eleuthera";
	n = n + 1;

  // -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Jungle2";

	Locations[n].id = "Eleuthera_Jungle2";
	locations[n].id.label = "Jungle";
	Locations[n].image = "Outside_Jungle2.tga";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "Jungle2_locators";
	Locations[n].models.always.jungle = "Jungle2";
	//Locations[n].models.always.Well_big = "Well_big";
    Locations[n].models.always.grassPatch = "JUNGLE2_grass";
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
	Locations[n].models.day.charactersPatch = "Jungle2_patch";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle2_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	
	Locations[n].reload.l1.name = "reload2";//au lieu de 1
	Locations[n].reload.l1.go = "Eleuthera_shore_Ship";
	Locations[n].reload.l1.emerge = "reload1";//au lieu de 2
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload2 = 2.5;
	Locations[n].reload.l1.label = "Shore";

    Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Eleuthera_shore_Ship";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload2_back = 2.5;
	Locations[n].reload.l2.label = "Shore";

	Locations[n].reload.l3.name = "reload1";//au lieu de 3
	Locations[n].reload.l3.go = "Eleuthera_jungle3";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.reload3 = 2.5;
	Locations[n].reload.l3.label = "Jungle";
	
	Locations[n].reload.l5.name = "reload1_back";
	Locations[n].reload.l5.go = "Eleuthera_jungle3";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].locators_radius.reload.reload3_back = 3;
	Locations[n].reload.l5.label = "Jungle";

    Locations[n].reload.l6.name = "reload3";
	Locations[n].reload.l6.go = "Alice_exit";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].locators_radius.reload.reload3 = 2.5;
	Locations[n].reload.l6.label = "Jungle";

	Locations[n].reload.l7.name = "reload3_back";
	Locations[n].reload.l7.go = "Alice_exit";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "1";
	Locations[n].locators_radius.reload.reload3_back = 2.5;
	Locations[n].reload.l7.label = "Jungle";
	
	Locations[n].island = "Eleuthera";
	n = n + 1;

 // -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Jungle3";

	Locations[n].id = "Eleuthera_Jungle3";
	locations[n].id.label = "Jungle";
	Locations[n].image = "Outside_Jungle3.tga";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "Jungle3_locators";
	Locations[n].models.always.jungle = "Jungle3";
    Locations[n].models.always.grassPatch = "JUNGLE3_grass";
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
	Locations[n].models.day.charactersPatch = "Jungle3_patch";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle3_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
    Locations[n].reload.l1.name = "reload3";
	Locations[n].reload.l1.go = "Eleuthera_jungle4";
	Locations[n].reload.l1.emerge = "reload3_back";//au lieu de 2
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle";
	Locations[n].locators_radius.reload.reload2 = 1;

	Locations[n].reload.l2.name = "reload3_back";
	Locations[n].reload.l2.go = "Eleuthera_jungle4";
	Locations[n].reload.l2.emerge = "reload3";//
	Locations[n].reload.l2.autoreload = "1";//
	Locations[n].reload.l2.label = "Jungle";
	Locations[n].locators_radius.reload.reload2_back = 3;

    Locations[n].reload.l5.name = "reload1";//au lieu de 3
	Locations[n].reload.l5.go = "Eleuthera_jungle2";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].locators_radius.reload.reload3 = 2.5;
	Locations[n].reload.l5.label = "Jungle";

	Locations[n].reload.l6.name = "reload1_back";
	Locations[n].reload.l6.go = "Eleuthera_jungle2";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].locators_radius.reload.reload3_back = 3;
	Locations[n].reload.l6.label = "Jungle";

    Locations[n].reload.l7.name = "reload2";
	Locations[n].reload.l7.go = "Eleuthera_Cave_Exit";
	Locations[n].reload.l7.emerge = "reload2";//au lieu de 2
	Locations[n].reload.l7.autoreload = "1";
	Locations[n].reload.l7.label = "Cavern";
	Locations[n].locators_radius.reload.reload2 = 1;

	Locations[n].reload.l8.name = "reload2_back";
	Locations[n].reload.l8.go = "Eleuthera_Cave_Exit";
	Locations[n].reload.l8.emerge = "reload2";//
	Locations[n].reload.l8.autoreload = "1";//
	Locations[n].reload.l8.label = "Cavern";
	Locations[n].locators_radius.reload.reload2_back = 3;

	Locations[n].island = "Eleuthera";
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Cave Entrance";

	Locations[n].id = "Eleuthera_Cave_Exit";
	locations[n].id.label = "#sisland_name# cave entrance";
	Locations[n].image = "Outside_Cave_Entrance.tga";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

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

    Locations[n].reload.l3.name = "reload1";
	Locations[n].reload.l3.go = "Eleuthera_cavern";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Cavern";
	Locations[n].locators_radius.reload.reload2 = 1;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Eleuthera_cavern";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Cavern";
	Locations[n].locators_radius.reload.reload2_back = 3;

	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Eleuthera_Jungle3";
	Locations[n].reload.l1.emerge = "reload2";//au lieu de 3
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle";
	Locations[n].locators_radius.reload.Reload2 = 2.0;

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Eleuthera_Jungle3";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle";
	Locations[n].locators_radius.reload.reload2_back = 2.0;

	Locations[n].island = "Eleuthera"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\outside\Plantation";

	Locations[n].id = "EleutheraPlantation";
	locations[n].id.label = "#stown_name# Plantation";
	Locations[n].image = "Outside_Plantation.tga";

	//Town sack
	locations[n].townsack = "Eleuthera";

	//Sound
	locations[n].type = "jungle";
	//LAi_LocationMonstersGen(&locations[n], true);
	//LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "Plantation_locators";
	Locations[n].models.always.Plantation = "Plantation";
    Locations[n].models.always.gateopen = "Plantation_gateopen";
    Locations[n].models.always.reflect = "Plantation_reflect";
	Locations[n].models.always.grassPatch = "Plantation_grass";
	Locations[n].models.always.l1 = "plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
    Locations[n].models.always.l4 = "plan4";
	Locations[n].models.always.l4.level = 6;
	Locations[n].models.always.l4.tech = "LocationModelBlend";

	//Day
	Locations[n].models.day.charactersPatch = "Plantation_patchopen";
	Locations[n].models.day.fonar = "Plantation_fd";
	//Night
	Locations[n].models.night.charactersPatch = "Plantation_patchopen";
	Locations[n].models.night.fonar = "Plantation_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0; // screwface

	//Reload map
	Locations[n].reload.l1.name = "Reload1_back";//au lieu de 2
	Locations[n].reload.l1.go = "Eleuthera_Port";
	Locations[n].reload.l1.emerge = "gate";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# Port";

	Locations[n].reload.l2.name = "houseSP1";
	Locations[n].reload.l2.go = "Jocard_house";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.disable = true;

    Locations[n].reload.l3.name = "Reload2_back";
	Locations[n].reload.l3.go = "Eleuthera_Jungle4";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle";

    Locations[n].reload.l4.name = "Reload2";
	Locations[n].reload.l4.go = "Eleuthera_Jungle4";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle";

    Locations[n].island = "Eleuthera"; // NK 04-08-29
	n = n + 1;

//__________________________________________________________

	Locations[n].id = "Jocard_house";
	locations[n].id.label = "Head's House";
	Locations[n].filespath.models = "locations\inside\den"; 
	Locations[n].image = ""; // KK

	//Town sack
	Locations[n].townsack = "Eleuthera";

	//Sound
	locations[n].type = "den"; // KK
	//locations[n].fastreload = "Redmond";
	//Models
	//Always
	Locations[n].models.always.city = "mh5";
	Locations[n].models.always.locators = "mh5_l";
	Locations[n].models.always.window = "mh5_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day

	Locations[n].models.day.charactersPatch = "mh5_p";

	//Night

	Locations[n].models.night.charactersPatch = "mh5_p";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redmh5_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "EleutheraPlantation";
	Locations[n].reload.l1.emerge = "houseSP1";
	Locations[n].reload.l1.autoreload = "0";


	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Eleuthera"; // NK 04-08-29
	n = n + 1;

    ////////////////////////////////////////////////////////
    Locations[n].filespath.models = "locations\Outside\Jungle3";

	Locations[n].id = "Eleuthera_Jungle4";
	locations[n].id.label = "Jungle";
	Locations[n].image = "Outside_Jungle3.tga";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "Jungle3_locators";
	Locations[n].models.always.jungle = "Jungle3";
	//Locations[n].models.always.Well_big = "Well_big";
    Locations[n].models.always.grassPatch = "Jungle3_grass";
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
	Locations[n].models.day.charactersPatch = "Jungle3_patch";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle3_patch";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
       
    Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "FortVRight";
	Locations[n].reload.l1.emerge = "reload1_back";//au lieu de 2//"reload1_back";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Fort";
	
	Locations[n].reload.l2.name = "reload2_back";//"reload3_back"
	Locations[n].reload.l2.go = "FortVRight";
	Locations[n].reload.l2.emerge = "reload1";//"reload1"
	Locations[n].reload.l2.autoreload = "1";//
	Locations[n].reload.l2.label = "Fort";
	
    Locations[n].reload.l5.name = "reload1";//au lieu de 3
	Locations[n].reload.l5.go = "EleutheraPlantation";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Jungle";

	Locations[n].reload.l6.name = "reload1_back";
	Locations[n].reload.l6.go = "EleutheraPlantation";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle";

    Locations[n].reload.l7.name = "reload3";
	Locations[n].reload.l7.go = "Eleuthera_Jungle3";
	Locations[n].reload.l7.emerge = "reload3";
	Locations[n].reload.l7.autoreload = "1";
	Locations[n].reload.l7.label = "Jungle";

	Locations[n].reload.l8.name = "reload3_back";
	Locations[n].reload.l8.go = "Eleuthera_Jungle3";
	Locations[n].reload.l8.emerge = "reload3";//
	Locations[n].reload.l8.autoreload = "1";
	Locations[n].reload.l8.label = "Jungle";

	Locations[n].island = "Eleuthera";	
    n = n + 1;

    ///////////////////////////////////////////////////////
    Locations[n].filespath.models = "locations\Fort_Inside\FortVRight";
	
    Locations[n].id = "FortVRight";
	locations[n].id.label = "#stown_name# Fort";
	Locations[n].image = "Fort_Inside_FortVRight.tga";

	//Town sack
	locations[n].townsack = "Eleuthera";

	//Sound
	locations[n].type = "jungle";
//	locations[n].fastreload = "Eleuthera";
	//LAi_LocationMonstersGen(&locations[n], true);
	//LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "FortVRight_locators";
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

	Locations[n].reload.l2.name = "reload1_back";//"reload1_back";
	Locations[n].reload.l2.go = "Eleuthera_Jungle4";
	Locations[n].reload.l2.emerge = "reload2";//
	Locations[n].reload.l2.autoreload = "1";//
	Locations[n].reload.l2.label = "Jungle";
	Locations[n].locators_radius.reload.reload2_back = 3;

    Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Fort_prison";
	Locations[n].reload.l3.emerge = "reload1_back";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Prison";

	Locations[n].island = "Eleuthera";
    n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Fort_prison";
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
	Locations[n].reload.l1.go = "FortVRight";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.label = "#stown_name# Fort";	

	Locations[n].island = "Eleuthera";
	n = n + 1;	

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////   ALICE                    ////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

    locations[n].id = "Alice_Port";
	locations[n].id.label = "#stown_name# Port";
	locations[n].worldmap = "Eleuthera";
	locations[n].filespath.models = "locations\Town_Alice";
	locations[n].image = "Town_Alice.tga";

	//Town sack
	locations[n].townsack = "Alice";

	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "Alice";
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	locations[n].models.always.town = "Alice_Town";
	locations[n].models.always.town.foam = "1";
	locations[n].models.always.L1 = "Alice_Town_signsA";
	Locations[n].models.always.seabed = "Alice_Town_sb";
	locations[n].models.always.seabed.foam = "1";
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
	locations[n].MaxSeaHeight = 0.9; // screwface

	//Reload map
	locations[n].reload.l1.name = "reload61_back";
	locations[n].reload.l1.go = "Eleuthera";
	locations[n].reload.l1.emerge = "reload_3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Sea";
	locations[n].locators_radius.reload.reload61_back = 1.8;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Alice_townhall";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "#stown_name# Residence";
	Locations[n].reload.l3.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l3.goto_disable = 1; // Screwface: Disable Go-To location

	locations[n].reload.l4.name = "reload4_back";
	locations[n].reload.l4.go = "Alice_tavern";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "#stown_name# Tavern";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l4.goto_disable = 1; // Screwface: Disable Go-To location

	locations[n].reload.l5.name = "reload5_back";
	locations[n].reload.l5.go = "Alice_shipyard";
	locations[n].reload.l5.emerge = "reload1";
	locations[n].reload.l5.autoreload = "0";
	locations[n].reload.l5.label = "#stown_name# Shipyard";
	Locations[n].reload.l5.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l5.goto_disable = 1; // Screwface: Disable Go-To location

	locations[n].reload.l6.name = "reload6_back";
	locations[n].reload.l6.go = "Alice_store";
	locations[n].reload.l6.emerge = "reload1";
	locations[n].reload.l6.autoreload = "0";
	locations[n].reload.l6.label = "#stown_name# Store";
	Locations[n].reload.l6.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l6.goto_disable = 1; // Screwface: Disable Go-To location

	locations[n].reload.l7.name = "reload7_back";
	locations[n].reload.l7.go = "Alice_church";
	locations[n].reload.l7.emerge = "reload1";
	locations[n].reload.l7.autoreload = "0";
	locations[n].reload.l7.label = "#stown_name# Church";
	Locations[n].reload.l7.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l7.goto_disable = 1; // Screwface: Disable Go-To location

	locations[n].reload.l8.name = "reload8_back";
	locations[n].reload.l8.go = "Alice_usurer";
	locations[n].reload.l8.emerge = "reload1";
	locations[n].reload.l8.autoreload = "0";
	locations[n].reload.l8.label = "#stown_name# Loanshark's Office.";
	Locations[n].reload.l8.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l8.goto_disable = 1; // Screwface: Disable Go-To location

	if(IsBrothelEnabled())
	{
    		Locations[n].reload.l9.name = "houseS1";
		Locations[n].reload.l9.go = "Alice_Brothel";
		Locations[n].reload.l9.emerge = "reload1";
		Locations[n].reload.l9.autoreload = "0";
		Locations[n].reload.l9.label = "#stown_name# Brothel";
		Locations[n].reload.l9.close_for_night = 0;
		if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l9.goto_disable = 1; // Screwface: Disable Go-To location
	}

    Locations[n].reload.l10.name = "gate_back";
	Locations[n].reload.l10.go = "Alice_exit";
	Locations[n].reload.l10.emerge = "reload2";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "Jungle.";
//	Locations[n].locators_radius.reload.gate_back = 2.0;

    locations[n].reload.l11.name = "reload10_back";
	locations[n].reload.l11.go = "Alice_Prison";
	locations[n].reload.l11.emerge = "reload1";
	locations[n].reload.l11.autoreload = "0";
	locations[n].reload.l11.label = "#stown_name# Prison";
	Locations[n].reload.l11.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l11.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l12.name = "HouseF3";
	Locations[n].reload.l12.go = "Alice_TailorsShop";
	Locations[n].reload.l12.emerge = "locator2";
	Locations[n].reload.l12.autoreload = "0";
	Locations[n].reload.l12.label = "Tailor's Shop.";
	Locations[n].reload.l12.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l12.goto_disable = 1;

    Locations[n].island = "Eleuthera"; // NK 04-08-29
	n = n + 1;

    //-----------------------------------------------------
    Locations[n].id = "Alice_usurer";
	locations[n].id.label = "#stown_name# Loanshark's Office";
	//Town sack
	Locations[n].townsack = "Alice";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Alice";

	InitBank(Locations[n].id);

	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Alice_Port";
	locations[n].reload.l1.emerge = "reload8_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "#stown_name# Port";

	Locations[n].island = "Eleuthera";
	n = n + 1;

   // -------------------------------------------------
	Locations[n].id = "Alice_tavern";
	locations[n].id.label = "#stown_name# Tavern";
	//Town sack
	Locations[n].townsack = "Alice";
	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "Alice";
	//Models

	InitTavern01(Locations[n].id);

	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Alice_Port";
	locations[n].reload.l1.emerge = "reload4_back";//reload4_back
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "#stown_name# Port";
	LAi_LocationFightDisable(&locations[n], true);

    Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Alice_tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Room in #stown_name# tavern";
	Locations[n].reload.l2.disable = 1;

	Locations[n].island = "Eleuthera"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Alice_tavern_upstairs";
	locations[n].id.label = "Room in #stown_name# tavern";
	Locations[n].image = "Inside_Tavern_Room.tga";

	//Town sack
	Locations[n].townsack = "Alice";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Alice";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Tavern_room";
	locations[n].models.always.locators = "Tavern_room_locators";
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
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Alice_Tavern";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "#stown_name# Tavern";
	locations[n].locators_radius.reload.reload1 = 0.8;

    	Locations[n].island = "Eleuthera"; // NK 04-08-29
	n = n + 1;

 	//-------------------------------------------------
	Locations[n].id = "Alice_store";
	locations[n].id.label = "#stown_name# Store";
	//Town sack
	Locations[n].townsack = "Alice";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Alice";

	InitStore01(Locations[n].id);

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Alice_Port";
	locations[n].reload.l1.emerge = "reload6_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "#stown_name# Port";

	Locations[n].island = "Eleuthera"; // NK 04-08-29
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// BROTHEL
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Alice_Brothel";
	locations[n].id.label = "#stown_name# Brothel";
	locations[n].filespath.models = "locations\inside\Brothel";
	locations[n].image = "Inside_Brothel.tga";

	//Town sack
	locations[n].townsack = "Alice";

	//Sound
	locations[n].type = "brothel"; // there's a type for brothel
	locations[n].fastreload = "Alice";
	//Models
	//Always
	locations[n].models.always.locators = "Brothel_locators";
	locations[n].models.always.store = "Brothel";
	locations[n].models.always.window = "Brothel_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 50;
	
	Locations[n].models.back = "..\back\inside_back_";

	//Day
	locations[n].models.day.charactersPatch = "Brothel_patch";

	//Night
	locations[n].models.night.charactersPatch = "Brothel_patch";

	//Environment
	locations[n].environment.weather = "false";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Alice_Port";
	locations[n].reload.l1.emerge = "houseS1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "#stown_name# Port";
	LAi_LocationFightDisable(&locations[n], true);

	locations[n].reload.l2.name = "reload1_back";
	locations[n].reload.l2.go = "Alice_Brothel_bedroom";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "#stown_name# Brothel room";
	Locations[n].reload.l2.disable = 1;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Alice_Brothel_room";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "#stown_name# Brothel room";

    	Locations[n].permanent_mom = true; // GR: needed so that LEnc_monsters.c does not spawn random mistress
    	Locations[n].island = "Eleuthera"; // NK 04-08-29	
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "Alice_Brothel_room";
	locations[n].id.label = "#stown_name# Brothel";
	Locations[n].filespath.models = "locations\inside\den"; 
	Locations[n].image = "Inside_Den_Room.tga"; // PB
	//Town sack
	Locations[n].townsack = "Alice";
	//Sound
	locations[n].type = "room";
	locations[n].fastreload = "Alice";
	LAi_LocationFantomsGen(&locations[n], false);
	//Models
	Locations[n].models.back = "back\redmh5_";
	//Always
	Locations[n].models.always.city = "mh5";
	Locations[n].models.always.locators = "mh5_l";
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

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Alice_Brothel";
	Locations[n].reload.l1.emerge = "reload2_back";
	Locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "#stown_name# Brothel";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Eleuthera";
	n = n + 1;

	//  -------------------------------------------------
	locations[n].id = "Alice_Brothel_bedroom";
	locations[n].id.label = "Brothel Bedroom";
	locations[n].filespath.models = "locations\inside\Brothel_room";
	locations[n].image = "Inside_Brothel_Room.tga";

	//Town sack
	locations[n].townsack = "Alice";

	//Sound
	locations[n].type = "room";
	locations[n].fastreload = "Alice";
	//Models
	//Always
	locations[n].models.always.locators = "Brothel_room_locators";
	locations[n].models.always.store = "Brothel_room";
	locations[n].models.always.window = "Brothel_room_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 50;
	
	Locations[n].models.back = "..\back\inside_back_";

	//Day
	locations[n].models.day.charactersPatch = "Brothel_room_patch";

	//Night
	locations[n].models.night.charactersPatch = "Brothel_room_patch";

	//Environment
	locations[n].environment.weather = "false";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Alice_brothel";
	locations[n].reload.l1.emerge = "reload1_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "#stown_name# Brothel";
	LAi_LocationFightDisable(&locations[n], true);

    	Locations[n].island = "Eleuthera";
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "Alice_StoneHouse";
	locations[n].id.label = "House";
	//Town sack
	Locations[n].townsack = "Alice";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Alice";

	InitStoneHouse(Locations[n].id);

	//Reload map
	Locations[n].reload.l1.go = "Alice_Port";
	Locations[n].reload.l1.emerge = Locations[FindLocation(Locations[n].reload.l1.go)].reload.l11.name;
	locations[n].reload.l1.label = "#stown_name# Port";

	Locations[n].island = "Eleuthera";
	n = n + 1;

    // -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\shipyard";

	Locations[n].id = "Alice_shipyard";
	locations[n].id.label = "#stown_name# shipyard";
	Locations[n].image = "Inside_Shipyard1.tga";

	//Town sack
	Locations[n].townsack = "Alice";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Alice";
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
	Locations[n].models.back = "back\oxsh1_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Alice_Port";
	Locations[n].reload.l1.emerge = "Reload5_back";
	Locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "#stown_name# Port";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Eleuthera"; // NK 04-08-29
	n = n + 1;

    // --------------------------------------------------->
	Locations[n].filespath.models = "locations\inside\Residence5";

	Locations[n].id = "Alice_townhall";
	locations[n].id.label = "#stown_name# townhall";
	Locations[n].image = "Inside_Residence5.tga";

	//Town sack
	Locations[n].townsack = "Alice";

	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Alice";

	//Models
	//Always
	Locations[n].models.always.locators = "Res05_l";
	Locations[n].models.always.l1 = "ResX5"; // ccc may07 Location Remodeling Campaign
	Locations[n].models.always.window = "ResX5_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "Res05_p";
	//Night
	Locations[n].models.night.charactersPatch = "Res05_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\cores5_";

	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Alice_Port";
	Locations[n].reload.l1.emerge = "reload3_back";
	Locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "#stown_name# Port";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Eleuthera";
	n = n + 1;

  	//////////////////////////////////////////
	// CHURCH
	//////////////////////////////////////////
	locations[n].id = "Alice_church";
	locations[n].id.label = "#stown_name# Church";
	//Town sack
	locations[n].townsack = "Alice";
	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "Alice";

	InitChurch1(Locations[n].id);

	//Reload map
	Locations[n].reload.l1.go = "Alice_Port";
	locations[n].reload.l1.emerge = "reload7";
	Locations[n].reload.l1.label = "#stown_name# Port";

	locations[n].reload.l2.name = "goto1";
	locations[n].reload.l2.go = "Alice_dungeon_2";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "#stown_name# Dungeon";	

	Locations[n].island = "Eleuthera";

	n = n + 1;

    // --------------------------------------------------->
	Locations[n].id = "Alice_dungeon_2";
	locations[n].id.label = "#stown_name# Dungeon";
	Locations[n].filespath.models = "locations\inside\dungeon_2";
	Locations[n].image = "Inside_Dungeon_2.tga";

	//Town sack
	Locations[n].townsack = "Alice";

	//Sound
	locations[n].type = "dungeon";
	locations[n].fastreload = "Alice";
	//Models
	//Always
	Locations[n].models.always.locators = "d02_l_phil";
	Locations[n].models.always.dungeon = "d02";
	Locations[n].models.always.fonar = "d02_fn";
	//Day
	Locations[n].models.day.charactersPatch = "d02_p";
//	Locations[n].models.day.fonar = "d02_fd";
	//Night
	Locations[n].models.night.charactersPatch = "d02_p";
//	Locations[n].models.night.env = "d02_fn";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].monsters = 0;
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Alice_Church";
	Locations[n].reload.l1.emerge = "goto1"; // PB: "reload3" doesn't exist
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# Church";

    Locations[n].reload.l2.name = "reload3";
	Locations[n].reload.l2.go = "Alice_Prison";
	Locations[n].reload.l2.emerge = "reload10";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name# Prison";
	
    Locations[n].island = "Eleuthera"; // NK 04-08-29 cuba
	n = n + 1;

    //  -------------------------------------------------
	Locations[n].id = "Alice_Prison";
	locations[n].id.label = "#stown_name# prison";
	Locations[n].filespath.models = "locations\inside\Prison";
	Locations[n].image = "Inside_Prison.tga";

	//Town sack
	Locations[n].townsack = "Alice";

	//Sound
	locations[n].type = "jail";
	locations[n].fastreload = "Alice";
	LAi_LocationFantomsGen(&locations[n], true);
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
	Locations[n].reload.l1.go = "Alice_Port";
	Locations[n].reload.l1.emerge = "reload10_back";
    locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "#stown_name# Port";

	locations[n].reload.l2.name = "reload12";
	locations[n].reload.l2.go = "Alice_Prison";
	locations[n].reload.l2.emerge = "reload39";
    Locations[n].reload.l1.label = "#stown_name# Prison";
	LAi_LocationFightDisable(&Locations[n], true);

    Locations[n].reload.l3.name = "reload10";//39
	Locations[n].reload.l3.go = "Alice_dungeon_2";
	Locations[n].reload.l3.emerge = "reload3";
    locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "#stown_name# Dungeon";

	Locations[n].island = "Eleuthera"; // NK 04-08-29 cuba
	n = n + 1;

    // -------------------------------------------------
    Locations[n].filespath.models = "locations\town_Redmond\redexit1";

	Locations[n].id = "Alice_exit";
	locations[n].id.label = "#stown_name# exit";
	Locations[n].image = "Town_Redmond_Exit1.tga";

	//Town sack
	Locations[n].townsack = "Alice";

	//Sound
	locations[n].type = "jungle";
//	locations[n].fastreload = "Eleuthera";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

    //Models
	//Always
	Locations[n].models.always.locators = "redexit1_l";
	Locations[n].models.always.exit = "redexit1";
	Locations[n].models.always.grassPatch = "redexit1_g";
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
	Locations[n].models.day.charactersPatch = "redexit1_p";
	Locations[n].models.day.fonar = "redexit1_fd";
	//Night
	Locations[n].models.night.charactersPatch = "redexit1_p";
	Locations[n].models.night.fonar = "redexit1_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Eleuthera_Jungle2";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle";
	Locations[n].locators_radius.reload.reload2 = 2.0;

    Locations[n].reload.l2.name = "Reload1_back";
	Locations[n].reload.l2.go = "Eleuthera_Jungle2";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle";
	Locations[n].locators_radius.reload.Reload2_back = 2.0;

    Locations[n].reload.l3.name = "Reload2";
	Locations[n].reload.l3.go = "Alice_Port";
	Locations[n].reload.l3.emerge = "gate_back";
	Locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l1.label = "#stown_name# Port";
	Locations[n].locators_radius.reload.reload2 = 2.0;

   	Locations[n].island = "Eleuthera";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// TAILOR'S SHOP
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Locations[n].id = "Alice_TailorsShop";	
	Locations[n].id.label = "Tailor's Shop.";
	Locations[n].image = "Inside_StoreSmall.tga";

	//Town sack
	Locations[n].townsack = "Alice";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Alice";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Inside\StoreSmall";
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
	Locations[n].models.back = "..\back\inside_back_";

	Locations[n].reload.l1.name = "locator2";
	locations[n].reload.l1.go = "Alice_Port";
	Locations[n].reload.l1.emerge = "HouseF3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";
	Locations[n].locators_radius.reload.locator2 = 0.7;

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Eleuthera"; // NK 04-08-29
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// BROTHEL
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Eleuthera_Brothel";
	locations[n].id.label = "#stown_name# Brothel";
	locations[n].filespath.models = "locations\inside\Brothel";
	locations[n].image = "Inside_Brothel.tga";

	//Town sack
	locations[n].townsack = "Eleuthera";

	//Sound
	locations[n].type = "brothel"; // there's a type for brothel
	locations[n].fastreload = "Eleuthera";
	//Models
	//Always
	locations[n].models.always.locators = "Brothel_locators";
	locations[n].models.always.store = "Brothel";
	locations[n].models.always.window = "Brothel_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 50;
	
	Locations[n].models.back = "..\back\inside_back_";

	//Day
	locations[n].models.day.charactersPatch = "Brothel_patch";

	//Night
	locations[n].models.night.charactersPatch = "Brothel_patch";

	//Environment
	locations[n].environment.weather = "false";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Eleuthera_Port";
	locations[n].reload.l1.emerge = "houseS2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "#stown_name# Port";
	LAi_LocationFightDisable(&locations[n], true);

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Eleuthera_Brothel_bedroom";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "#stown_name# Brothel room";
	Locations[n].reload.l2.disable = 1;

    	Locations[n].permanent_mom = true; // GR: needed so that LEnc_monsters.c does not spawn random mistress
    	Locations[n].island = "Eleuthera"; // NK 04-08-29	
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Brothel Room
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Eleuthera_Brothel_bedroom";
	locations[n].id.label = "#stown_name# Brothel room";
	locations[n].filespath.models = "locations\inside\Brothel_room";
	locations[n].image = "Inside_Brothel_Room.tga";

	//Town sack
	locations[n].townsack = "Eleuthera";

	//Sound
	locations[n].type = "room";
	locations[n].fastreload = "Eleuthera";
	//Models
	//Always
	locations[n].models.always.locators = "Brothel_room_locators";
	locations[n].models.always.store = "Brothel_room";
	locations[n].models.always.window = "Brothel_room_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 50;
	
	Locations[n].models.back = "..\back\inside_back_";

	//Day
	locations[n].models.day.charactersPatch = "Brothel_room_patch";

	//Night
	locations[n].models.night.charactersPatch = "Brothel_room_patch";

	//Environment
	locations[n].environment.weather = "false";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Eleuthera_brothel";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "#stown_name# Brothel";
	LAi_LocationFightDisable(&locations[n], true);

    	Locations[n].island = "Eleuthera";
	n = n + 1;

	//return n;
}
