void LocationInitRedmond(ref n)
{
	// -------------------------------------------------
	Locations[n].id = "Redmond_Town_01";
	locations[n].id.label = "#stown_name#. Center.";
	locations[n].worldmap = "Redmond";
	Locations[n].filespath.models = "locations\Town_Redmond\Town_01";
	Locations[n].filespath.textures = "locations\ENGLAND";
	Locations[n].image = "Town_Redmond_Town_01.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "Redmond";
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	Locations[n].models.always.L1 = "Red01";
	Locations[n].models.always.locators = "Red01_l";
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
	Locations[n].reload.l1.name = "reload_1_4";
	Locations[n].reload.l1.go = "Redmond_Town_04";
	Locations[n].reload.l1.emerge = "reload_4_1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload_1_4 = 2.0;

	Locations[n].reload.l2.name = "reload_1_4_back";
	Locations[n].reload.l2.go = "Redmond_Town_04";
	Locations[n].reload.l2.emerge = "reload_4_1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload_1_4_back = 2.0;

	Locations[n].reload.l3.name = "reload_1_3";
	Locations[n].reload.l3.go = "Redmond_Town_03";
	Locations[n].reload.l3.emerge = "reload_3_1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload_1_3 = 3.0;

	Locations[n].reload.l4.name = "reload_1_3_back";
	Locations[n].reload.l4.go = "Redmond_Town_03";
	Locations[n].reload.l4.emerge = "reload_3_1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload_1_3_back = 3.0;

	Locations[n].reload.l5.name = "reload_from_port";
	Locations[n].reload.l5.go = "redmond_port";
	Locations[n].reload.l5.emerge = "reload_2_city";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Sea port.";

	Locations[n].reload.l6.name = "reload_2_3";
	Locations[n].reload.l6.go = "Redmond_Town_03";
	Locations[n].reload.l6.emerge = "reload_3_2";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload_2_3 = 2.0;

	Locations[n].reload.l7.name = "reload_2_4_back";
	Locations[n].reload.l7.go = "Redmond_Town_04";
	Locations[n].reload.l7.emerge = "reload_4_2";
	Locations[n].reload.l7.autoreload = "1";
	Locations[n].reload.l7.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload_2_4_back = 2.0;

	Locations[n].reload.l8.name = "reload_2_4";
	Locations[n].reload.l8.go = "Redmond_Town_04";
	Locations[n].reload.l8.emerge = "reload_4_2";
	Locations[n].reload.l8.autoreload = "1";
	Locations[n].reload.l8.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload_2_4 = 2.0;

	Locations[n].reload.l9.name = "shipyard";
	Locations[n].reload.l9.go = "Redmond_shipyard";
	Locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "Shipyard.";
	Locations[n].reload.l9.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l9.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l10.name = "door_6";
	Locations[n].reload.l10.go = "Redmond_usurerHouse";
	Locations[n].reload.l10.emerge = "locator2";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "Loanshark's Office.";
	Locations[n].reload.l10.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l10.goto_disable = 1; // Screwface: Disable Go-To location

    Locations[n].reload.l11.name = "door_1";
	Locations[n].reload.l11.go = "Redmond_tavern";
	Locations[n].reload.l11.emerge = "reload1";
	Locations[n].reload.l11.autoreload = "0";
	Locations[n].reload.l11.label = "Tavern.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l11.goto_disable = 1; // Screwface: Disable Go-To location

    Locations[n].reload.l12.name = "door_11";
	Locations[n].reload.l12.go = "Redmond_store";
	Locations[n].reload.l12.emerge = "reload1";
	Locations[n].reload.l12.autoreload = "0";
	Locations[n].reload.l12.label = "Store.";
	Locations[n].reload.l12.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l12.goto_disable = 1; // Screwface: Disable Go-To location

    Locations[n].reload.l13.name = "door_5";
	Locations[n].reload.l13.go = "Redmond_residence";
	Locations[n].reload.l13.emerge = "reload1";
	Locations[n].reload.l13.autoreload = "0";
	Locations[n].reload.l13.label = "Residence.";
	Locations[n].reload.l13.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l13.goto_disable = 1; // Screwface: Disable Go-To location

/*	Locations[n].reload.l7.name = "door_5";
	Locations[n].reload.l7.go = "Redmond_HouseInsideR5(01)";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Дом.";
	Locations[n].reload.l7.close_for_night = 1;

	Locations[n].reload.l8.name = "door_7";
	Locations[n].reload.l8.go = "Redmond_HouseInsideR7(01)";
	Locations[n].reload.l8.emerge = "reload1";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "Дом.";

	Locations[n].reload.l9.name = "door_3";
	Locations[n].reload.l9.go = "Redmond_HouseInsideR3(01)";
	Locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "Дом.";

	Locations[n].reload.l10.name = "door_1";
	Locations[n].reload.l10.go = "Redmond_HouseInsideR1(01)";
	Locations[n].reload.l10.emerge = "reload1";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "Дом.";*/

	// RobC/Alan_Smithee Blacksmiths -->
	if (ENABLE_WEAPONSMOD)
	{
		Locations[n].reload.l14.name = "Door_4";
		Locations[n].reload.l14.go = "Red_blacksmith";
		Locations[n].reload.l14.emerge = "reload1";
		Locations[n].reload.l14.close_for_night = 1;
		if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l14.goto_disable = 1; // Screwface: Disable Go-To location
	}
	// RobC/Alan_Smithee Blacksmiths <--

	// Alan_Smithee Opium Den & Tattoos -->
	Locations[n].reload.l15.name = "Door_3";
	Locations[n].reload.l15.go = "den";
	Locations[n].reload.l15.emerge = "reload1";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l15.goto_disable = 1; //JRH
	// Alan_Smithee Opium Den & Tattoos <--

	// SJG British Naval HQ --->
	Locations[n].reload.l16.name = "Door56";
	Locations[n].reload.l16.go = "Redmond Naval HQ";
	Locations[n].reload.l16.emerge = "reload1";
	Locations[n].reload.l16.autoreload = "0";
	Locations[n].reload.l16.label = "#stown_name# Naval HQ";
	Locations[n].reload.l16.close_for_night = 1;
	Locations[n].reload.l16.disable = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l16.goto_disable = 1; //JRH
	// SJG British Naval HQ <---

	// CTM EITC Office --->
	Locations[n].reload.l17.name = "Door_2";
	Locations[n].reload.l17.go = "EITC_Office";
	Locations[n].reload.l17.emerge = "reload1";
	Locations[n].reload.l17.autoreload = "0";
	Locations[n].reload.l17.label = "Office";
	Locations[n].reload.l17.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l17.goto_disable = 1; //JRH
	// CTM EITC Office <---

	 //JRH -->
	//tavern_storeroom					//on when door is opened from storeroom
	Locations[n].reload.l26.name = "door_7";
	Locations[n].reload.l26.go = "";
	Locations[n].reload.l26.emerge = "";
	Locations[n].reload.l26.autoreload = "0";
	Locations[n].reload.l26.label = "";

	//Locations[n].reload.l26.go = "Tavern_storeroom";
	//Locations[n].reload.l26.emerge = "reload1";
	//Locations[n].reload.l26.autoreload = "0";
	//Locations[n].reload.l26.label = "Tavern storeroom.";
	Locations[n].reload.l26.disable = 1;

	//town to window wr residence
	Locations[n].reload.l18.name = "reload5";
	Locations[n].reload.l18.go = "WR_residence";
	Locations[n].reload.l18.emerge = "reload3";
	Locations[n].reload.l18.autoreload = "0";
	Locations[n].reload.l18.label = "Woodes Rogers' residence.";

	Locations[n].locators_radius.reload.reload5_in = 0.1;		//not used
	Locations[n].locators_radius.reload.reload5_out = 0.1;		//not used

	//town to backdoor loanshark
	Locations[n].reload.l20.name = "reload7";
	Locations[n].reload.l20.go = "Redmond_town_01";
	Locations[n].reload.l20.emerge = "reload7_in";
	Locations[n].reload.l20.autoreload = "0";
	Locations[n].reload.l20.label = "Loanshark's Office.";
	Locations[n].reload.l20.disable = 1;

	Locations[n].reload.l21.name = "reload7_in";
	Locations[n].reload.l21.go = "Redmond_usurerHouse";
	Locations[n].reload.l21.emerge = "reload3";
	Locations[n].reload.l21.autoreload = "0";
	Locations[n].reload.l21.label = "Loanshark's Office.";
	Locations[n].locators_radius.reload.reload7_in = 0.3;

	//gate to terrace to wr residence
	Locations[n].reload.l23.name = "reload6";
	Locations[n].reload.l23.go = "Redmond_town_04";
	Locations[n].reload.l23.emerge = "terr_in1";
	Locations[n].reload.l23.autoreload = "0";
	Locations[n].reload.l23.label = "Redmond.";
	Locations[n].locators_radius.reload.reload6 = 0.7;

	Locations[n].reload.l29.name = "reload13";
	Locations[n].reload.l29.go = "Redmond_Shipyard";
	Locations[n].reload.l29.emerge = "goto11";
	Locations[n].reload.l29.autoreload = "0";
	Locations[n].reload.l29.label = "Shipyard.";

	Locations[n].reload.l27.name = "door58";
	Locations[n].reload.l27.go = "Shop_stairs";
	Locations[n].reload.l27.emerge = "goto1";
	Locations[n].reload.l27.autoreload = "0";
	Locations[n].reload.l27.label = "Rogers' Paintings Furniture & Weapons";
	Locations[n].reload.l27.disable = 1;
	Locations[n].reload.l27.close_for_night = 1;

	//way back from shipyard to shop office
	Locations[n].reload.l28.name = "reload12";
	Locations[n].reload.l28.go = "wr_shop_office";
	Locations[n].reload.l28.emerge = "reload6";
	Locations[n].reload.l28.autoreload = "0";

	Locations[n].reload.l31.name = "balcony";
	Locations[n].reload.l31.go = "Redmond_tavern";
	Locations[n].reload.l31.emerge = "reload3";
	Locations[n].reload.l31.autoreload = "0";
	Locations[n].reload.l31.label = "Tavern.";
	Locations[n].locators_radius.reload.balcony = 0.5;

	Locations[n].locators_radius.goto.defoe = 2.5;
	Locations[n].locators_radius.goto.magic_key = 3.0;

	Locations[n].locators_radius.box.box3 = 0.5;		//lever on roof
	Locations[n].locators_radius.box.box4 = 0.5;		//facade
	Locations[n].locators_radius.box.box5 = 0.5;		//facade
	Locations[n].locators_radius.box.box10 = 0.3;		//facade
	Locations[n].locators_radius.box.box11 = 0.5;		//walk roof
	Locations[n].locators_radius.box.box12 = 0.5;		//walk roof

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "door_N07";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "ROPE_horizontal";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "mast_bridge";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "hatch4";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "lever_up";

	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "lever_down";

	Locations[n].locators_radius.randitem.randitem8 = 0.01;
	Locations[n].items.randitem8 = "hatch4";

	Locations[n].locators_radius.randitem.randitem9 = 0.01;
	Locations[n].items.randitem9 = "door_N06";

	Locations[n].locators_radius.randitem.randitem10 = 0.01;
	Locations[n].items.randitem10 = "door_N06";
   	//<-- JRH

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;


	// -------------------------------------------------
	Locations[n].id = "Redmond_town_03";
	locations[n].id.label = "#stown_name#";
	locations[n].worldmap = "Redmond";
	Locations[n].filespath.models = "locations\Town_Redmond\Town_03";
	Locations[n].filespath.textures = "locations\ENGLAND";
	Locations[n].image = "Town_Redmond_Town_03.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "Redmond";
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	Locations[n].models.always.a = "Red03";
	Locations[n].models.always.locators = "Red03_l";
    Locations[n].models.always.grassPatch = "Red03_g";

    //River
	Locations[n].models.always.dno = "Red03_rb01";
	Locations[n].models.always.dno.level = 95;
	Locations[n].models.always.dno.uvslide.u1 = -0.12;
	Locations[n].models.always.dno.uvslide.v1 = -0.03;
	Locations[n].models.always.dno.tech = "LocationRiverFloor";
	Locations[n].models.always.mirrow = "Red03_re01";
	Locations[n].models.always.mirrow.level = 96;
	Locations[n].models.always.dnoBlend = "Red03_rb01";
	Locations[n].models.always.dnoBlend.level = 97;
	Locations[n].models.always.dnoBlend.uvslide.u1 = -0.1;
	Locations[n].models.always.dnoBlend.uvslide.v1 = 0.04;
	Locations[n].models.always.dnoBlend.tech = "LocationRiverFloorBlend";
	Locations[n].models.always.river = "Red03_rt01";
	Locations[n].models.always.river.level = 98;
	Locations[n].models.always.river.uvslide.v0 = -0.1;
	Locations[n].models.always.river.uvslide.u1 = 0.15;
	Locations[n].models.always.river.tech = "LocationRiver";

	//Day
	Locations[n].models.day.charactersPatch = "Red03_p";
    Locations[n].models.day.fonar = "Red03_fd";
	//Night
	Locations[n].models.night.charactersPatch = "Red03_p";
    Locations[n].models.night.fonar = "Red03_fn";

    Locations[n].locators_radius.camdetector.locator11 = 5.0;

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l99.name = "Door_12";
	Locations[n].reload.l99.go = "Redmond_dungeon_2";
	Locations[n].reload.l99.emerge = "Reload1";
	Locations[n].reload.l99.autoreload = "0";
	Locations[n].reload.l99.label = "#stown_name#.";

	Locations[n].reload.l1.name = "reload_3_2";
	Locations[n].reload.l1.go = "Redmond_Town_01";
	Locations[n].reload.l1.emerge = "reload_2_3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Center.";
	Locations[n].locators_radius.reload.reload_3_2 = 2.0;

	Locations[n].reload.l2.name = "reload_3_1";
	Locations[n].reload.l2.go = "Redmond_Town_01";
	Locations[n].reload.l2.emerge = "reload_1_3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload_3_1 = 2.0;

	Locations[n].reload.l3.name = "reload_3_3";
	Locations[n].reload.l3.go = "Redmond_town_exit_2"; // KK
	Locations[n].reload.l3.emerge = "Reload2";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Jungle.";

	Locations[n].reload.l24.name = "reload_3_2_back";
	Locations[n].reload.l24.go = "Redmond_Town_01";
	Locations[n].reload.l24.emerge = "reload_2_3";
	Locations[n].reload.l24.autoreload = "1";
	Locations[n].reload.l24.label = "#stown_name#. Center.";
	Locations[n].locators_radius.reload.reload_3_2_back = 2.0;

	Locations[n].reload.l5.name = "reload_3_1_back";
	Locations[n].reload.l5.go = "Redmond_Town_01";
	Locations[n].reload.l5.emerge = "reload_1_3";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload_3_1_back = 2.0;

	Locations[n].reload.l6.name = "reload_3_3_back";
	Locations[n].reload.l6.go = "Redmond_town_exit_2"; // KK
	Locations[n].reload.l6.emerge = "Reload2";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Jungle.";

	Locations[n].reload.l4.name = "door_6";
	Locations[n].reload.l4.go = "Redmond_church";
	Locations[n].reload.l4.emerge = "Reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Church.";
	Locations[n].reload.l4.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l4.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l7.name = "door_1";
	Locations[n].reload.l7.go = "Redmond_HouseInsideR1(03)";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "House.";

	Locations[n].reload.l8.name = "door_11";
	Locations[n].reload.l8.go = "Redmond_HouseInsideR11(03)";
	Locations[n].reload.l8.emerge = "reload1";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "House.";

	//JRH -->
	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "medicine_table";

	Locations[n].locators_radius.randitem.randitem4 = 0.001;
	Locations[n].items.randitem4 = "foodchest";

	Locations[n].locators_radius.randitem.randitem5 = 0.001;
	Locations[n].items.randitem5 = "bigfish";

	Locations[n].locators_radius.randitem.randitem6 = 0.001;
	Locations[n].items.randitem6 = "potion1";

	Locations[n].locators_radius.randitem.randitem7 = 0.001;
	Locations[n].items.randitem7 = "potionrum";

	Locations[n].locators_radius.randitem.randitem8 = 0.001;
	Locations[n].items.randitem8 = "potion2";

	Locations[n].locators_radius.randitem.randitem9 = 0.001;
	Locations[n].items.randitem9 = "potion4";

	Locations[n].locators_radius.randitem.randitem10 = 0.001;
	Locations[n].items.randitem10 = "potionwine";

	Locations[n].locators_radius.randitem.randitem11 = 0.001;
	Locations[n].items.randitem11 = "potion3";

	Locations[n].locators_radius.randitem.randitem12 = 0.001;
	Locations[n].items.randitem12 = "ale";
    	//<-- JRH

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Redmond_town_04";
	locations[n].id.label = "#stown_name#";
	locations[n].worldmap = "Redmond";
	Locations[n].filespath.models = "locations\Town_Redmond\Town_04";
	Locations[n].filespath.textures = "locations\ENGLAND";
	Locations[n].image = "Town_Redmond_Town_04.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "Redmond";
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	Locations[n].models.always.locators = "Red04_l";
	Locations[n].models.always.city = "Red04";
	Locations[n].models.always.dno = "Red04_rb";
	Locations[n].models.always.dno.level = 95;
	Locations[n].models.always.dno.uvslide.u1 = -0.12;
	Locations[n].models.always.dno.uvslide.v1 = -0.03;
	Locations[n].models.always.dno.tech = "LocationRiverFloor";
	Locations[n].models.always.mirrow = "Red04_re";
	Locations[n].models.always.mirrow.level = 96;
	Locations[n].models.always.dnoBlend = "Red04_rb";
	Locations[n].models.always.dnoBlend.level = 97;
	Locations[n].models.always.dnoBlend.uvslide.u1 = -0.1;
	Locations[n].models.always.dnoBlend.uvslide.v1 = 0.04;
	Locations[n].models.always.dnoBlend.tech = "LocationRiverFloorBlend";
	Locations[n].models.always.river = "Red04_rt";
	Locations[n].models.always.river.level = 98;
	Locations[n].models.always.river.uvslide.v0 = -0.1;
	Locations[n].models.always.river.uvslide.v1 = 0.15;
	Locations[n].models.always.river.tech = "LocationRiver";
	Locations[n].models.always.grassPatch = "Red04_g";

	//Day
	Locations[n].models.day.fonar = "Red04_fd";
	Locations[n].models.day.rinok = "Red04_e01";
	Locations[n].models.day.charactersPatch = "Red04_pd";
	//Night
	Locations[n].models.night.fonar = "Red04_fn";
	Locations[n].models.night.charactersPatch = "Red04_pn";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload_4_2";
	Locations[n].reload.l1.go = "Redmond_Town_01";
	Locations[n].reload.l1.emerge = "reload_2_4";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "#stown_name#. Center.";
	Locations[n].locators_radius.reload.reload_4_2 = 2.0;

	Locations[n].reload.l21.name = "reload_4_2_back";
	Locations[n].reload.l21.go = "Redmond_Town_01";
	Locations[n].reload.l21.emerge = "reload_2_4";
	Locations[n].reload.l21.autoreload = "1";
	Locations[n].reload.l21.label = "#stown_name#. Center.";
	Locations[n].locators_radius.reload.reload_4_2_back = 2.0;

	Locations[n].reload.l2.name = "reload_4_1";
	Locations[n].reload.l2.go = "Redmond_Town_01";
	Locations[n].reload.l2.emerge = "reload_1_4";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload_4_1 = 2.0;

	Locations[n].reload.l22.name = "reload_4_1_back";
	Locations[n].reload.l22.go = "Redmond_Town_01";
	Locations[n].reload.l22.emerge = "reload_1_4";
	Locations[n].reload.l22.autoreload = "1";
	Locations[n].reload.l22.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload_4_1_back = 2.0;

	Locations[n].reload.l3.name = "reload_2_jungle";
	Locations[n].reload.l3.go = "Redmond_Town_exit_1"; // KK
	Locations[n].reload.l3.emerge = "Reload2";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Jungle.";

	Locations[n].reload.l4.name = "door_7";
	Locations[n].reload.l4.go = "Redmond_prison";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Prison.";
	Locations[n].reload.l4.close_for_night = 1;
	Locations[n].locators_radius.reload.reload1 = 0.75;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l4.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l7.name = "door_1";
	Locations[n].reload.l7.go = "Redmond_HouseInsideR1";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "House.";
	Locations[n].reload.l7.close_for_night = 0;
	Locations[n].locators_radius.reload.reload1 = 0.75;

	Locations[n].reload.l8.name = "door_6";
	Locations[n].reload.l8.go = "Redmond_TailorsShop";
	Locations[n].reload.l8.emerge = "locator2";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "Tailor's Shop.";
	Locations[n].reload.l8.close_for_night = 1;
	Locations[n].locators_radius.reload.reload1 = 0.75;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l8.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l9.name = "door_2";
	Locations[n].reload.l9.go = "Redmond_HouseInsideR2";
	Locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "House.";
	Locations[n].reload.l9.close_for_night = 0;
	Locations[n].locators_radius.reload.reload1 = 0.75;

	Locations[n].reload.l10.name = "door_8";		//JRH was door_4
	Locations[n].reload.l10.go = "Redmond_HouseInsideR4";
	Locations[n].reload.l10.emerge = "reload1";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "House.";
	Locations[n].reload.l10.close_for_night = 0;
	Locations[n].locators_radius.reload.reload1 = 0.75;

	Locations[n].reload.l11.name = "door_9";
	Locations[n].reload.l11.go = "Hit_houseB";
	Locations[n].reload.l11.emerge = "reload1";
	Locations[n].reload.l11.autoreload = "0";
	Locations[n].reload.l11.label = "House.";
	Locations[n].reload.l11.close_for_night = 0;
	Locations[n].locators_radius.reload.reload1 = 0.75;

	//JRH -->
	//crew's quarter
	Locations[n].reload.l19.name = "door_4";
	Locations[n].reload.l19.go = "wr_crew";
	Locations[n].reload.l19.emerge = "reload5";
	Locations[n].reload.l19.autoreload = "0";
	Locations[n].reload.l19.label = "Crew's quarter.";
	Locations[n].locators_radius.reload.reload19 = 0.5;
	Locations[n].reload.l19.disable = 1;

	//ck drawing room to tailor stairs
	Locations[n].reload.l13.name = "reload1";
	Locations[n].reload.l13.go = "Redmond_town_04";
	Locations[n].reload.l13.emerge = "reload2";
	Locations[n].reload.l13.autoreload = "0";
	Locations[n].reload.l13.label = "Redmond.";
	Locations[n].locators_radius.reload.reload1 = 0.5;

	Locations[n].reload.l12.name = "reload2";
	Locations[n].reload.l12.go = "Redmond_town_04";
	Locations[n].reload.l12.emerge = "reload10";
	Locations[n].reload.l12.autoreload = "0";
	Locations[n].reload.l12.label = "Caroline's drawing room.";
	Locations[n].locators_radius.reload.reload2 = 0.5;
	Locations[n].reload.l12.disable = 1;			//locked to ck_drawing_room in wr quest 1

	Locations[n].reload.l20.name = "reload10";
	Locations[n].reload.l20.go = "ck_drawing_room";
	Locations[n].reload.l20.emerge = "reload2";
	Locations[n].reload.l20.autoreload = "0";
	Locations[n].reload.l20.label = "Caroline's drawing room.";
	Locations[n].locators_radius.reload.reload10 = 0.5;

	//garden to wr residence
	Locations[n].reload.l18.name = "reload7";
	Locations[n].reload.l18.go = "wr_residence";
	Locations[n].reload.l18.emerge = "reload1";
	Locations[n].reload.l18.autoreload = "0";
	Locations[n].reload.l18.label = "Woodes Rogers´residence.";
	Locations[n].locators_radius.reload.reload7 = 0.2;

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "door_NGR";

	Locations[n].locators_radius.goto.goto_50 = 2.0;
   //<-- JRH

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "REDMOND_PORT";
	locations[n].id.label = "#stown_name# port";
	locations[n].worldmap = "Redmond";
	Locations[n].filespath.models = "locations\Town_Redmond\Port";
	Locations[n].filespath.textures = "locations\ENGLAND";
	Locations[n].image = "Town_Redmond_Port.tga";

	//Town sack
	Locations[n].townsack = "Redmond";
	if(GetCurrentPeriod() >= PERIOD_COLONIAL_POWERS) Locations[n].navy = 1;

	//Sound
	locations[n].type = "port";
	locations[n].fastreload = "Redmond";
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	Locations[n].models.always.l1 = "RedPort";
	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.locators = "RedPort_l";
	Locations[n].models.always.grassPatch = "Redport_g";
    Locations[n].models.always.seabed = "RedPort_sb";
	Locations[n].models.always.seabed.foam = "1";

	//Day
	Locations[n].models.day.charactersPatch = "RedPort_pd";
	Locations[n].models.day.rinok = "RedPort_e01"; //рынок
	Locations[n].models.day.fonar = "RedPort_fd";
	Locations[n].models.day.jumppatch = "RedPort_j";
	//Night
	Locations[n].models.night.charactersPatch = "Redport_pn";
	Locations[n].models.night.fonar = "Redport_fn";
	Locations[n].models.night.jumppatch = "RedPort_j";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	//Reload map
	Locations[n].reload.l1.name = "reload_2_city";
	Locations[n].reload.l1.go = "Redmond_Town_01";
	Locations[n].reload.l1.emerge = "reload_from_port";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].reload.l2.name = "sea_1";
	Locations[n].reload.l2.go = "Redmond";
	Locations[n].reload.l2.emerge = "reload_2";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";

	Locations[n].locators_radius.reload.sea_1 = 3.0;
	Locations[n].locators_radius.goto.goto_60 = 1.5; // SJG 8MAR09
	Locations[n].reload.l3.name = "sea_2";
	Locations[n].reload.l3.go = "Redmond";
	Locations[n].reload.l3.emerge = "reload_2";
	Locations[n].reload.l3.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l3.label = "Ship.";
	else
		Locations[n].reload.l3.label = "Sea.";
	Locations[n].locators_radius.reload.sea_2 = 3.0;

	Locations[n].reload.l4.name = "sea_1_back";
	Locations[n].reload.l4.go = "Redmond";
	Locations[n].reload.l4.emerge = "reload_2";
	Locations[n].reload.l4.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l4.label = "Ship.";
	else
		Locations[n].reload.l4.label = "Sea.";
	Locations[n].locators_radius.reload.sea_1_back = 2.0;

	Locations[n].reload.l5.name = "sea_2_back";
	Locations[n].reload.l5.go = "Redmond";
	Locations[n].reload.l5.emerge = "reload_2";
	Locations[n].reload.l5.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l5.label = "Ship.";
	else
		Locations[n].reload.l5.label = "Sea.";
	Locations[n].locators_radius.reload.sea_2_back = 2.0;

	Locations[n].reload.l6.name = "Door_1";
	Locations[n].reload.l6.go = "Redmond_Head_port_house";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Head Port House.";

    //JRH -->
	Locations[n].locators_radius.goto.very_nice = 1.0;

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "bladebarrel";

	Locations[n].locators_radius.randitem.randitem3 = 0.01;
	Locations[n].items.randitem3 = "ladder_very_big";
     //<-- JRH

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

    // -------------------------------------------------
    Locations[n].id = "Redmond_town_exit_1";
	locations[n].id.label = "Exit from #stown_name#";
	Locations[n].filespath.models = "locations\Town_Redmond\REDexit1";
	Locations[n].filespath.textures = "locations\ENGLAND";
	Locations[n].image = "Town_Redmond_Exit1.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "jungle";
//	locations[n].fastreload = "Redmond";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

    //Models
	//Always
	Locations[n].models.always.locators = "Redexit1_l";
	Locations[n].models.always.exit = "Redexit1";
	Locations[n].models.always.grassPatch = "Redexit1_g";
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
	Locations[n].models.day.charactersPatch = "Redexit1_p";
	Locations[n].models.day.fonar = "redexit1_fd";
	//Night
	Locations[n].models.night.charactersPatch = "redexit1_p";
	Locations[n].models.night.fonar = "redexit1_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "Reload2";
	Locations[n].reload.l1.go = "Redmond_Town_04"; // KK
	Locations[n].reload.l1.emerge = "reload_2_jungle"; // KK
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].reload.l2.name = "Reload1";
	Locations[n].reload.l2.go = "Redmond_shore_01";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Devil's Throat.";
	Locations[n].locators_radius.reload.reload1 = 3.0;

	Locations[n].reload.l3.name = "Reload1_back";
	Locations[n].reload.l3.go = "Redmond_shore_01";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Devil's Throat.";
	Locations[n].locators_radius.reload.Reload1_back = 2.0;


	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

    // ---------------------------------------------------
    Locations[n].id = "Redmond_town_exit_2";
	locations[n].id.label = "Exit from #stown_name#";
	Locations[n].filespath.models = "locations\Town_Redmond\REDexit2";
	Locations[n].filespath.textures = "locations\ENGLAND";
	Locations[n].image = "Town_Redmond_Exit2.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "jungle";
//	locations[n].fastreload = "Redmond";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

    //Models
	//Always
	Locations[n].models.always.locators = "Redexit2_l";
	Locations[n].models.always.exit = "Redexit2";
	Locations[n].models.always.grassPatch = "Redexit2_g";
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
	Locations[n].models.day.charactersPatch = "Redexit2_p";
	Locations[n].models.day.fonar = "Redexit2_fd";
	//Night
	Locations[n].models.night.charactersPatch = "Redexit2_p";
	Locations[n].models.night.fonar = "Redexit2_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "Reload2";
	Locations[n].reload.l1.go = "Redmond_town_03"; // KK
	Locations[n].reload.l1.emerge = "reload_3_3"; // KK
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].reload.l3.name = "Reload2_back";
	Locations[n].reload.l3.go = "Redmond_town_03"; // KK
	Locations[n].reload.l3.emerge = "reload_3_3"; // KK
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "#stown_name#.";

/*	Locations[n].reload.l2.name = "reload1";
	Locations[n].reload.l2.go = "Redmond_shore_02";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Бухта.";
	Locations[n].locators_radius.reload.reload2 = 3.0;*/

	Locations[n].reload.l2.name = "Reload1";
	Locations[n].reload.l2.go = "Redmond_jungle_01";
	Locations[n].reload.l2.emerge = "Reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1 = 2.0;

	Locations[n].reload.l4.name = "Reload1_back";
	Locations[n].reload.l4.go = "Redmond_jungle_01";
	Locations[n].reload.l4.emerge = "Reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1 = 2.0;

//JRH -->
	Locations[n].reload.l5.name = "Reload3";
	Locations[n].reload.l5.go = "wr_dungeon4_main";
	Locations[n].reload.l5.emerge = "Reload5";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Redmond old mine.";
	Locations[n].locators_radius.reload.reload5 = 0.5;
//<-- JRH

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

  // -------------------------------------------------
   	Locations[n].id = "Redmond_Shore_01";
	locations[n].id.label = "Devil's Throat."; // KK
	locations[n].worldmap = "RShore 1";
	Locations[n].filespath.models = "locations\Outside\Shore_7";
	Locations[n].image = "Outside_Shore_7.tga";
	Locations[n].name = "Devil's Throat";
	//Sound
	locations[n].type = "seashore";
   	 //Models
	//Always
	Locations[n].models.always.jungle = "Shore07";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.locators = "Shore07_l";
	Locations[n].models.always.grassPatch = "Shore07_g";
	Locations[n].models.always.seabed = "Shore07_sb";
	Locations[n].models.always.seabed.foam = "1";

/*	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan_3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";*/

	//Day
	Locations[n].models.day.charactersPatch = "Shore07_p";
	//Night
	Locations[n].models.night.charactersPatch = "Shore07_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Redmond_Town_exit_1";
	Locations[n].reload.l1.emerge = "Reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 3.0;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Redmond_Town_exit_1";
	Locations[n].reload.l3.emerge = "Reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3.0;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Redmond";
	Locations[n].reload.l2.emerge = "reload_1";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 9.0;


	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

    // -------------------------------------------------
    Locations[n].id = "Redmond_jungle_01";
	locations[n].id.label = "#sisland_name# jungles";
	Locations[n].filespath.models = "locations\Outside\jungle_8";
	Locations[n].image = "Outside_Jungle_8.tga";
 	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

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
	Locations[n].reload.l1.go = "Redmond_town_exit_2";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1 = 3.0;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Redmond_town_exit_2";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Redmond_shore_02";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Rocky Shore.";
	Locations[n].locators_radius.reload.reload2 = 3.0;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Redmond_shore_02";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Rocky Shore.";
	Locations[n].locators_radius.reload.reload2_back = 2.0;


	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

   	// -------------------------------------------------
    Locations[n].id = "Redmond_shore_02";
	locations[n].id.label = "Rocky Shore."; // KK
	locations[n].worldmap = "RShore 2";
	Locations[n].filespath.models = "locations\Outside\Shore_3";
	Locations[n].image = "Outside_Shore_3.tga";
	Locations[n].name = "Rocky Shore";
 	//Sound
	locations[n].type = "seashore";
   	//Models
	//Always
	Locations[n].models.always.jungle = "shore03";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.locators = "shore03_l";
    	Locations[n].models.always.seabed = "shore03_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "Shore03_g";

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
	Locations[n].models.day.charactersPatch = "shore03_p";
	//Night
	Locations[n].models.night.charactersPatch = "shore03_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Redmond_jungle_01";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 2.0;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Redmond_jungle_01";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 2.0;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Redmond";
	Locations[n].reload.l2.emerge = "reload_3";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 9.0;

    //JRH -->
	Locations[n].reload.l4.name = "reload4D";
	Locations[n].reload.l4.go = "wr_cave_shore";
	Locations[n].reload.l4.emerge = "goto1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "";
	Locations[n].locators_radius.reload.reload4D = 0.5;

	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 1.0;
	Locations[n].locators_radius.box.box5 = 0.5;
	Locations[n].locators_radius.box.box6 = 0.5;
	Locations[n].locators_radius.box.box7 = 0.5;
    //<-- JRH

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

    // -------------------------------------------------
	Locations[n].id = "Redmond_tavern";
	locations[n].id.label = "#stown_name# tavern";
	Locations[n].filespath.models = "locations\inside\Largetavern";
	Locations[n].image = "Inside_LargeTavern.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "Redmond";
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

//MAXIMUS -->
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Redmond_tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Room in #stown_name# tavern.";
	Locations[n].reload.l2.disable = true; // KK
	LAi_LocationFightDisable(&Locations[n], true);
//MAXIMUS <--

//JRH -->
	//balcony
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Redmond_Town_01";
	Locations[n].reload.l3.emerge = "goto57";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Redmond. Center.";

	//tavern storeroom
	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "Tavern_storeroom";
	Locations[n].reload.l6.emerge = "Reload2";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Tavern Storeroom.";
	Locations[n].locators_radius.reload.reload6 = 0.5;

	Locations[n].locators_radius.box.box1 = 0.5;		//walking behind the counter
	Locations[n].locators_radius.box.box2 = 0.5;		//walking behind the counter
  //<-- JRH

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Redmond_tavern_upstairs";
	locations[n].id.label = "Room in #stown_name# tavern";
	Locations[n].image = "Inside_Doubleflour_House_Room.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Redmond";
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
	Locations[n].reload.l1.go = "Redmond_tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# tavern.";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

 	//-------------------------------------------------
	Locations[n].id = "Redmond_store";
	locations[n].id.label = "#stown_name# store";
	Locations[n].filespath.models = "locations\inside\MediumStore";
	Locations[n].image = "Inside_MediumStore.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Redmond";
	//Models
	//Always
	Locations[n].models.always.locators = "MS_l";
	Locations[n].models.always.store = "MS";
	Locations[n].models.always.window = "MS_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "MS_p";

	//Night
	Locations[n].models.night.charactersPatch = "MS_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redms_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Redmond_Town_01";
	Locations[n].reload.l1.emerge = "door_11";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Center.";
	Locations[n].locators_radius.camdetector.camera1 = 5;
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

 	//-------------------------------------------------
	Locations[n].id = "Redmond_UsurerHouse";
	locations[n].id.label = "Loanshark's Office";
	Locations[n].filespath.models = "locations\inside\StoreSmall";
	Locations[n].image = "Inside_StoreSmall.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Redmond";
	//Models
	//Always
	Locations[n].models.always.locators = "SS_l";
	Locations[n].models.always.store = "SS";
	Locations[n].models.always.window = "SS_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "SS_p";
	Locations[n].models.day.fonar = "SS_fn";

	//Night
	Locations[n].models.night.charactersPatch = "SS_p";
	Locations[n].models.night.fonar = "SS_fn";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redss_";
	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "Redmond_Town_01";
	Locations[n].reload.l1.emerge = "door_6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	LAi_LocationFightDisable(&Locations[n], true);

	//JRH -->
	//wr shop
	Locations[n].reload.l2.name = "locator1";
	Locations[n].reload.l2.go = "wr_shop";
	Locations[n].reload.l2.emerge = "reload6";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Rogers' Paintings Furniture & Weapons";
	Locations[n].reload.l2.disable = 1;

	//library						//on when door is opened from library
	//Locations[n].reload.l3.name = "reload5";
	//Locations[n].reload.l3.go = "wr_library";
	//Locations[n].reload.l3.emerge = "reload6";
	//Locations[n].reload.l3.autoreload = "0";
	//Locations[n].reload.l3.label = "Woodes Rogers´ library.";

    //temp case when locked
    	Locations[n].reload.l3.name = "reload5";
	Locations[n].reload.l3.go = "ck_drawing_room";			//to avoid showing library when locked
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.disable = 1;
	Locations[n].locators_radius.reload.reload5 = 0.5;

	//loanshark cellar
	Locations[n].reload.l6.name = "reload4";
	Locations[n].reload.l6.go = "Loanshark_cellar";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "";
	Locations[n].locators_radius.reload.reload4 = 0.5;
	Locations[n].reload.l6.disable = 1;

	//backdoor to town
	Locations[n].reload.l7.name = "reload3";
	Locations[n].reload.l7.go = "Redmond_Town_01";
	Locations[n].reload.l7.emerge = "reload7";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Redmond.";

	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "door_N07";

	Locations[n].locators_radius.randitem.randitem3 = 0.001;
	Locations[n].items.randitem3 = "hatch2";

	Locations[n].locators_radius.goto.goto16 = 1.5;

	Locations[n].locators_radius.box.box1 = 0.0001;			//key function door to shop
	Locations[n].locators_radius.box.box2 = 0.0001;			//brake hatch lock with some tool (before removing it)
   	Locations[n].locators_radius.box.box3 = 0.5;			//counter
	Locations[n].locators_radius.box.box4 = 0.5;			//counter
	//<-- JRH

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;


 	// -------------------------------------------------
	Locations[n].id = "Redmond_Shipyard";
	locations[n].id.label = "#stown_name# shipyard";
	Locations[n].filespath.models = "locations\inside\Shipyard";
	Locations[n].image = "Inside_Shipyard1.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Redmond";
	//Models
	Locations[n].models.back = "back\redsh1_";
	//Always
	Locations[n].models.always.locators = "sh01_l";
	Locations[n].models.always.shipyard = "sh01";
	Locations[n].models.always.window = "sh01_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "sh01_p";
	Locations[n].models.day.fd = "Sh01_fd";

	//Night
	Locations[n].models.night.charactersPatch = "sh01_p";
	Locations[n].models.night.fn = "Sh01_fn";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Redmond_Town_01";
	Locations[n].reload.l1.emerge = "shipyard";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	//JRH -->
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "shipyard_stairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Redmond.";
	Locations[n].reload.l2.disable = 1;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Redmond_Town_01";
	Locations[n].reload.l3.emerge = "back1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Redmond.";

	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box2 = 0.5;

	Locations[n].locators_radius.randitem.randitem1 = 0.01;
	Locations[n].items.randitem1 = "gatedoor_semi_small";

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "smuggler_goods";

	Locations[n].locators_radius.randitem.randitem3 = 1.0;
	Locations[n].items.randitem3 = "pistol205";

	Locations[n].locators_radius.randitem.randitem4 = 0.01;
	Locations[n].items.randitem4 = "globe";

	Locations[n].locators_radius.randitem.randitem5 = 0.01;
	Locations[n].items.randitem5 = "blade3carpets";

	Locations[n].locators_radius.randitem.randitem6 = 0.01;
	Locations[n].items.randitem6 = "bladearmchair";

	Locations[n].locators_radius.randitem.randitem7 = 0.01;
	Locations[n].items.randitem7 = "chest1";				//was chest2???

	Locations[n].locators_radius.randitem.randitem8 = 0.01;
	Locations[n].items.randitem8 = "armchair02";

	Locations[n].locators_radius.randitem.randitem9 = 0.01;
	Locations[n].items.randitem9 = "blade3carpets";
   	//<-- JRH

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

 	//-------------------------------------------------
	Locations[n].id = "Redmond_Residence";
	locations[n].id.label = "#stown_name# townhall";
	Locations[n].filespath.models = "locations\inside\Residence_BackHall";
	Locations[n].image = "Inside_Residence_BackHall.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Redmond";
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
	Locations[n].reload.l1.go = "Redmond_Town_01";
	Locations[n].reload.l1.emerge = "door_5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Center.";
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

// SJG ---> British Naval HQ 5/30/2009
	Locations[n].id = "Redmond Naval HQ";
	locations[n].id.label = "#stown_name# Naval HQ";
	Locations[n].image = "Inside_Residence2.tga";
	Locations[n].filespath.models = "locations\inside\Residence2";

	Locations[n].vcskip = true;

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Redmond";
	//Models
	//Always
	Locations[n].models.always.city = "Res02";
	Locations[n].models.always.locators = "Res02_l_ccc"; // SJG 3Mar09
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
	Locations[n].locators_radius.goto.goto8 = 1.5; // SJG 18MAR09
	Locations[n].reload.l1.go = "Redmond_Town_01";
	Locations[n].reload.l1.emerge = "Door56";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Center.";
	LAi_LocationFightDisable(&Locations[n], false);

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Head_of_Jamaica_Station";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Head_of_Jamaica_Station";
	LAi_LocationFightDisable(&Locations[n], false);

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\inside\Residence4";

	Locations[n].id = "Head_of_Jamaica_Station";
	locations[n].id.label = "Officer Commanding #stown_name# Naval HQ";
	Locations[n].image = "Inside_Residence4.tga";

	Locations[n].vcskip = true;

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "silence"; //"residence"; SJG
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
	Locations[n].reload.l1.go = "Redmond Naval HQ";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# Naval HQ";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

// SJG <--- -------------------------------------------------
	Locations[n].id = "Redmond_prison";
	locations[n].id.label = "#stown_name# prison";
	Locations[n].filespath.models = "locations\inside\prison";
	Locations[n].image = "Inside_Prison.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "jail";
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
	Locations[n].reload.l1.go = "Redmond_Town_04";
	Locations[n].reload.l1.emerge = "door_7";
	Locations[n].reload.l1.label = "#stown_name#.";

	locations[n].reload.l2.name = "reload12";
	locations[n].reload.l2.go = "";
	locations[n].reload.l2.emerge = "reload12";
	locations[n].reload.l2.disable = 1;
	Locations[n].locators_radius.reload.reload12 = 0.5;
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	// Redmond_church -------------------------------------------------
	Locations[n].id = "Redmond_church";
	locations[n].id.label = "#stown_name# church";
	Locations[n].image = "Inside_Church_inside.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "Redmond";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Church_inside";
	Locations[n].models.always.city = "Church";
	Locations[n].models.always.locators = "Church_l";
	Locations[n].models.always.window = "church_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Church_p";

	//Night
	Locations[n].models.night.charactersPatch = "Church_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Redmond_town_03";
	Locations[n].reload.l1.emerge = "door_6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";

	//JRH -->
	Locations[n].locators_radius.goto.goto13 = 2.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "church_choir";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "";
	locations[n].reload.l2.disable = 1;			//opened later on

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "wr_crypt";
	Locations[n].reload.l3.emerge = "goto3";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "";
	locations[n].reload.l3.disable = 1;			//opened later on
    	//<-- JRH

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Redmond_TailorsShop";
	Locations[n].id.label = "Tailor's Shop.";
	Locations[n].image = "Inside_StoreSmall.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Redmond";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\StoreSmall";
	Locations[n].models.always.store = "SS";
	Locations[n].models.always.locators = "SS_l";
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
	Locations[n].models.back = "back\redmh4_";
	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "Redmond_town_04";
	Locations[n].reload.l1.emerge = "door_6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";
	Locations[n].locators_radius.reload.locator2 = 0.7;

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Redmond_HouseInsideR1";
	locations[n].id.label = "House";
	Locations[n].image = "Inside_mh6.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Redmond";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\mh6";
	Locations[n].models.always.city = "mh6";
	Locations[n].models.always.locators = "mh6_l";
	Locations[n].models.always.window = "mh6_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
//	Locations[n].models.day.lamp = "FalaiseDeFleur05_day";
	Locations[n].models.day.charactersPatch = "mh6_p";

	//Night
//	Locations[n].models.night.lamp = "FalaiseDeFleur05_night";
	Locations[n].models.night.charactersPatch = "mh6_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redmh6_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Redmond_town_04";
	Locations[n].reload.l1.emerge = "door_1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";



	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

		// -------------------------------------------------
	Locations[n].id = "Redmond_HouseInsideR2";
	locations[n].id.label = "House";
	Locations[n].image = "Inside_Smallhome.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Redmond";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Smallhome";
	Locations[n].models.always.city = "sh";
	Locations[n].models.always.locators = "sh_l";
	Locations[n].models.always.window = "sh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
//	Locations[n].models.day.lamp = "FalaiseDeFleur05_day";
	Locations[n].models.day.charactersPatch = "sh_p";

	//Night
//	Locations[n].models.night.lamp = "FalaiseDeFleur05_night";
	Locations[n].models.night.charactersPatch = "sh_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redsh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Redmond_town_04";
	Locations[n].reload.l1.emerge = "door_2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";


	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Redmond_HouseInsideR4";
	locations[n].id.label = "House";
	Locations[n].image = "Inside_mh8.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Redmond";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\mh8";
	Locations[n].models.always.city = "mh8";
	Locations[n].models.always.locators = "mh8_l";
	Locations[n].models.always.window = "mh8_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
//	Locations[n].models.day.lamp = "FalaiseDeFleur05_day";
	Locations[n].models.day.charactersPatch = "mh8_p";

	//Night
//	Locations[n].models.night.lamp = "FalaiseDeFleur05_night";
	Locations[n].models.night.charactersPatch = "mh8_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redmh8_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Redmond_town_04";
	Locations[n].reload.l1.emerge = "door_4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";

	Locations[n].locators_radius.camdetector.camera1 = 3.0;
	Locations[n].locators_radius.camdetector.camera2 = 1.8;


	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;
//___________________________________________________________________

	Locations[n].id = "Redmond_HouseInsideR1(03)";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\MediumHouse";
	Locations[n].image = "Inside_MediumHouse.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Redmond";
	//Models
	//Always
	Locations[n].models.always.locators = "mh_l";
	Locations[n].models.always.shipyard = "mh";
	Locations[n].models.always.window = "mh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "mh_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh_p";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redmh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Redmond_Town_03";
	Locations[n].reload.l1.emerge = "door_1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";


	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	//___________________________________________________________________

	Locations[n].id = "Redmond_HouseInsideR11(03)";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\mh7";
	Locations[n].image = "Inside_mh7.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Redmond";
	//Models
	//Always
	Locations[n].models.always.locators = "mh7_l";
	Locations[n].models.always.shipyard = "mh7";
	Locations[n].models.always.window = "mh7_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "mh7_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh7_p";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redmh7_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Redmond_Town_03";
	Locations[n].reload.l1.emerge = "door_11";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";


	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	//___________________________________________________________________

	Locations[n].id = "Redmond_HouseInsideR12";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\MediumHouse";
	Locations[n].image = "Inside_MediumHouse.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Redmond";
	//Models
	//Always
	Locations[n].models.always.locators = "mh_l";
	Locations[n].models.always.shipyard = "mh";
	Locations[n].models.always.window = "mh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "mh_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh_p";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redmh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Redmond_Town_01";
	Locations[n].reload.l1.emerge = "door_12";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";


	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;


	//___________________________________________________________________

	Locations[n].id = "Redmond_HouseInsideR7(01)";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\mh9";
	Locations[n].image = "Inside_mh9.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Redmond";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\mh9";
	Locations[n].models.always.city = "mh9";
	Locations[n].models.always.locators = "mh9_l";
	Locations[n].models.always.window = "mh9_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
//	Locations[n].models.day.lamp = "FalaiseDeFleur05_day";
	Locations[n].models.day.charactersPatch = "mh9_p";

	//Night
//	Locations[n].models.night.lamp = "FalaiseDeFleur05_night";
	Locations[n].models.night.charactersPatch = "mh9_p";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redmh9_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Redmond_Town_01";
	Locations[n].reload.l1.emerge = "door_7";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";


	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	//___________________________________________________________________

	Locations[n].id = "Redmond_HouseInsideR3(01)";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\mh10";
	Locations[n].image = "Inside_mh10.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Redmond";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\mh10";
	Locations[n].models.always.city = "mh10";
	Locations[n].models.always.locators = "mh10_l";
	Locations[n].models.always.window = "mh10_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
//	Locations[n].models.day.lamp = "FalaiseDeFleur05_day";
	Locations[n].models.day.charactersPatch = "mh10_p";

	//Night
//	Locations[n].models.night.lamp = "FalaiseDeFleur05_night";
	Locations[n].models.night.charactersPatch = "mh10_p";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redmh10_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Redmond_Town_01";
	Locations[n].reload.l1.emerge = "door_3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";


	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

		//___________________________________________________________________

	Locations[n].id = "Redmond_HouseInsideR1(01)";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\mh5";
	Locations[n].image = "Inside_mh5.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Redmond";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\mh5";
	Locations[n].models.always.city = "mh5";
	Locations[n].models.always.locators = "mh5_l";
	Locations[n].models.always.window = "mh5_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
//	Locations[n].models.day.lamp = "FalaiseDeFleur05_day";
	Locations[n].models.day.charactersPatch = "mh5_p";

	//Night
//	Locations[n].models.night.lamp = "FalaiseDeFleur05_night";
	Locations[n].models.night.charactersPatch = "mh5_p";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redmh5_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Redmond_Town_01";
	Locations[n].reload.l1.emerge = "door_1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";


	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	//___________________________________________________________________

	Locations[n].id = "Redmond_HouseInsideR5(01)";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house";
	Locations[n].image = "Inside_Doubleflour_House_Lower.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Redmond";
	//Models
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F1_l";
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
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Redmond_Town_01";
	Locations[n].reload.l1.emerge = "door_5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";


	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

		//___________________________________________________________________

	Locations[n].id = "Redmond_HouseInsideR4(02)";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\mh10";
	Locations[n].image = "Inside_mh10.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Redmond";
	//Models
	//Always
	Locations[n].models.always.locators = "mh10_l";
	Locations[n].models.always.shipyard = "mh10";
	Locations[n].models.always.window = "mh10_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "mh10_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh10_p";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redmh10_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Redmond_Town_01";
	Locations[n].reload.l1.emerge = "door_4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";


	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	//___________________________________________________________________

	Locations[n].id = "Redmond_HouseInsideR3(02)";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\mh7";
	Locations[n].image = "Inside_mh7.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Redmond";
	//Models
	//Always
	Locations[n].models.always.locators = "mh7_l";
	Locations[n].models.always.shipyard = "mh7";
	Locations[n].models.always.window = "mh7_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "mh7_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh7_p";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redmh7_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Redmond_Town_01";
	Locations[n].reload.l1.emerge = "door_3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";


	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	//___________________________________________________________________

	Locations[n].id = "Redmond_HouseInsideR2(02)";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\mh9";
	Locations[n].image = "Inside_mh9.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Redmond";
	//Models
	//Always
	Locations[n].models.always.locators = "mh9_l";
	Locations[n].models.always.shipyard = "mh9";
	Locations[n].models.always.window = "mh9_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "mh9_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh9_p";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redmh9_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Redmond_Town_01";
	Locations[n].reload.l1.emerge = "door_2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";


	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	//___________________________________________________________________

	Locations[n].id = "Redmond_HouseInsideR7(02)";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\Smallhome";
	Locations[n].image = "Inside_Smallhome.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Redmond";
	//Models
	//Always
	Locations[n].models.always.locators = "sh_l";
	Locations[n].models.always.shipyard = "sh";
	Locations[n].models.always.window = "sh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "sh_p";

	//Night
	Locations[n].models.night.charactersPatch = "sh_p";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redsh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Redmond_Town_01";
	Locations[n].reload.l1.emerge = "door_7";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";


	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//___________________________________________________________________

	Locations[n].id = "Redmond_Dungeon_2";
	locations[n].id.label = "Dungeon";
	Locations[n].filespath.models = "locations\inside\Dungeon_2";
	Locations[n].image = "Inside_Dungeon_2.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "dungeon";
	locations[n].fastreload = "Redmond";
	//Models
	//Always
	Locations[n].models.always.locators = "d02_l";
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
	Locations[n].monsters = 1;
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Redmond_Town_03";
	Locations[n].reload.l1.emerge = "door_12";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].items.randitem1 = "bladeC2";

	LAi_LocationFantomsGen(&locations[n], true);


	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	Locations[n].id = "Redmond_Head_port_house";
	locations[n].id.label = "Head port house";
	//Sound
	Locations[n].filespath.models = "locations\inside\mh5";
	Locations[n].image = "Inside_mh5.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "redmond";
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
	Locations[n].reload.l1.go = "redmond_port";
	Locations[n].reload.l1.emerge = "door_1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# port.";
	Locations[n].vcskip = true; // KK
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

	//-------------------------------------------------------------------
	Locations[n].id = "EITC_Office";
	locations[n].id.label = "Office";
	Locations[n].image = "Inside_Residence2.tga";
	Locations[n].filespath.models = "locations\inside\Residence2";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Redmond";
	//Models
	//Always
	Locations[n].models.always.city = "Res02";
	Locations[n].models.always.locators = "Res02_l_ccc"; // SJG 3Mar09
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
	//Locations[n].locators_radius.goto.goto8 = 1.5; // SJG 18MAR09
	Locations[n].reload.l1.go = "Redmond_Town_01";
	Locations[n].reload.l1.emerge = "Door_2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Center.";
	LAi_LocationFightDisable(&Locations[n], false);

	//Locations[n].items.randitem1 = "pistol6";


	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;
}
