void LocationInitQuebradasCostillas(ref n)
{
	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_QC\port";
	Locations[n].image = "Town_QC_Port";

	Locations[n].id = "QC_port";
	locations[n].id.label = "#stown_name# port."; // KK
	locations[n].worldmap = "Quebradas Costillas";
	//Town sack
	Locations[n].townsack = "Quebradas Costillas"; // KK
	//Sound
	locations[n].type = "seashore";//"port";//MAXIMUS: ordinary seashore with moorage - not port (changed for correct showing of BattleInterface icons)
	locations[n].fastreload = "QC";
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	Locations[n].models.always.locators = "QCport_l";
	Locations[n].models.always.l1 = "QCport";
	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.sb = "QCport_sb";
	Locations[n].models.always.sb.foam = "1";
	Locations[n].models.always.grassPatch = "QCport_g";
	Locations[n].models.always.l2 = "plan_1";
	Locations[n].models.always.l2.level = 9;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan_2";
	Locations[n].models.always.l3.level = 8;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	Locations[n].models.always.l4 = "plan_3";
	Locations[n].models.always.l4.level = 7;
	Locations[n].models.always.l4.tech = "LocationModelBlend";

	//Day
	Locations[n].models.day.charactersPatch = "QCport_p";
	Locations[n].models.day.jumpPatch = "QCport_j";
	//Night
	Locations[n].models.night.charactersPatch = "QCport_p";
	Locations[n].models.night.jumpPatch = "QCport_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map

	Locations[n].reload.l1.name = "reload3";
	Locations[n].reload.l1.go = "QC_town_exit";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3 = 1.0;

	Locations[n].reload.l2.name = "reload1";
	Locations[n].reload.l2.go = "QuebradasCostillas";
	Locations[n].reload.l2.emerge = "reload_1";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.reload1 = 3.0;

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "QuebradasCostillas";
	Locations[n].reload.l3.emerge = "reload_1";
	Locations[n].reload.l3.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l3.label = "Ship.";
	else
		Locations[n].reload.l3.label = "Sea.";

	Locations[n].locators_radius.reload.reload2 = 3.0;

	Locations[n].reload.l4.name = "reload3_back";
	Locations[n].reload.l4.go = "QC_town_exit";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 1.0;


	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_QC\town";
	Locations[n].image = "Town_QC_Town";

	Locations[n].id = "QC_town";
	locations[n].id.label = "#stown_name#";
	locations[n].worldmap = "Quebradas Costillas";
	//Town sack
	Locations[n].townsack = "Quebradas Costillas"; // NK - "Oxbay";
	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "QC";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].vcskip = true; // PB: Fix trouble with starting the Artois/Nigel quest
	//Models
	//Always
	Locations[n].models.always.locators = "QCtown_l";
	Locations[n].models.always.town = "QCtown";
	Locations[n].models.always.grassPatch = "QCtown_g";
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
	Locations[n].models.day.charactersPatch = "QCtown_p";
	Locations[n].models.day.fonar = "QCtown_fd";
	//Night
	Locations[n].models.night.charactersPatch = "QCtown_p";
	Locations[n].models.night.fonar = "QCtown_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "QC_town_exit";
	Locations[n].reload.l1.emerge = "Reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "QC_tavern";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Tavern.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l2.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l3.name = "reload5";
	Locations[n].reload.l3.go = "QC_store";
	Locations[n].reload.l3.emerge = "locator2";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Store.";
	Locations[n].reload.l3.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l3.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l4.name = "reload6";
	Locations[n].reload.l4.go = "QC_UsurerHouse";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Loanshark's Office.";
	Locations[n].reload.l4.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l4.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l5.name = "reload10";
	Locations[n].reload.l5.go = "QC_Residence";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Pirate Chief's House.";
	Locations[n].reload.l5.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l5.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l6.name = "Reload4";
	Locations[n].reload.l6.go = "QC_shipyard";//<<<<<<<----------CHANGED FROM
	Locations[n].reload.l6.emerge = "locator2";//<<<<<<<<--------CHANGED FROM "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "ShipYard.";//<<<<<<<<--------CHANGED FROM
	Locations[n].reload.l6.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l6.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l7.name = "Reload9";
	Locations[n].reload.l7.go = "QC_HouseInsideR9";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "House.";

	Locations[n].reload.l8.name = "Reload3"; // SJG
	Locations[n].reload.l8.go = "Special_House";
	Locations[n].reload.l8.emerge = "reload1";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "House."; // SJG

//JRH -->
	//store house upper door
	Locations[n].reload.l18.name = "reload23";
	Locations[n].reload.l18.go = "QC_store_upstairs";
	Locations[n].reload.l18.emerge = "goto30";
	Locations[n].reload.l18.autoreload = "0";
	Locations[n].reload.l18.label = "Store upstairs";
	Locations[n].locators_radius.reload.reload23 = 0.001;

	//store house middle
	Locations[n].reload.l19.name = "reload25";
	Locations[n].reload.l19.go = "QC_town";
	Locations[n].reload.l19.emerge = "reload23";
	Locations[n].reload.l19.autoreload = "0";
	Locations[n].reload.l19.label = "";
	Locations[n].reload.l19.disable = 1;
	Locations[n].locators_radius.reload.reload25 = 0.5;

	//store house middle
	Locations[n].reload.l26.name = "reload26";
	Locations[n].reload.l26.go = "QC_town";
	Locations[n].reload.l26.emerge = "reload25";
	Locations[n].reload.l26.autoreload = "0";
	Locations[n].reload.l26.label = "";
	Locations[n].reload.l26.disable = 1;
	Locations[n].locators_radius.reload.reload26 = 0.5;	//was 1.0

	//store house left window
	Locations[n].reload.l44.name = "reload44";
	Locations[n].reload.l44.go = "QC_store_bedroom";
	Locations[n].reload.l44.emerge = "goto2";
	Locations[n].reload.l44.autoreload = "0";
	Locations[n].reload.l44.label = "Bedroom.";
	//Locations[n].reload.l44.disable = 1;

	Locations[n].locators_radius.reload.reload20 = 0.5;
	Locations[n].locators_radius.reload.reload22 = 0.5;
	Locations[n].locators_radius.reload.reload44 = 0.5;
	Locations[n].locators_radius.reload.reload45 = 0.5;

	Locations[n].locators_radius.box.box1 = 0.5;
	Locations[n].locators_radius.box.box2 = 0.5;
	Locations[n].locators_radius.box.box3 = 0.5;
	Locations[n].locators_radius.box.box4 = 0.8;
	Locations[n].locators_radius.box.box5 = 0.1;
	Locations[n].locators_radius.box.box6 = 0.1;
	Locations[n].locators_radius.box.box7 = 0.001;
	Locations[n].locators_radius.box.box8 = 0.1;

	//ground left
	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "koster3";

	//ground right
	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "koster3";

	//standing left
	Locations[n].locators_radius.randitem.randitem5 = 0.1;
	Locations[n].items.randitem5 = "koster4";

	//standing left
	Locations[n].locators_radius.randitem.randitem6 = 0.1;
	Locations[n].items.randitem6 = "koster2";

	//standing right
	Locations[n].locators_radius.randitem.randitem7 = 0.1;
	Locations[n].items.randitem7 = "koster2";

	//standing right
	Locations[n].locators_radius.randitem.randitem8 = 0.1;
	Locations[n].items.randitem8 = "koster4";

	//derrick
	Locations[n].locators_radius.randitem.randitem9 = 0.1;
	Locations[n].items.randitem9 = "mine";

	//roof hatch
	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "hatch1";
//<-- JRH

	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_QC\exit";

	Locations[n].id = "QC_town_exit";
	locations[n].id.label = "Exit from #stown_name#";
	Locations[n].image = "Town_QC_Exit";
	//Town sack
	Locations[n].townsack = "Quebradas Costillas"; // KK
	//Sound
	locations[n].type = "jungle";
	locations[n].fastreload = "QC";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "QCexit_l";
	Locations[n].models.always.exit = "QCexit";
	Locations[n].models.always.grassPatch = "QCexit_g";
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
	Locations[n].models.day.charactersPatch = "QCexit_p";
	//Night
	Locations[n].models.night.charactersPatch = "QCexit_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map

	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "QC_town";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].reload.l2.name = "Reload2";
	Locations[n].reload.l2.go = "QC_port";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Sea port.";
	Locations[n].locators_radius.reload.reload2 = 3.0;

	Locations[n].reload.l3.name = "Reload3";
	Locations[n].reload.l3.go = "QC_Jungle_04";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3 = 3.0;

	Locations[n].reload.l4.name = "Reload2_back";
	Locations[n].reload.l4.go = "QC_port";
	Locations[n].reload.l4.emerge = "reload3";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Sea port.";
	Locations[n].locators_radius.reload.Reload2_back = 2.0;

	Locations[n].reload.l5.name = "Reload3_back";
	Locations[n].reload.l5.go = "QC_Jungle_04";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload3_back = 2.0;

	// RobC/Alan_Smithee Blacksmiths -->
	if (ENABLE_WEAPONSMOD)
	{
		Locations[n].reload.l6.name = "reload4";
		Locations[n].reload.l6.go = "QC_blacksmith";
		Locations[n].reload.l6.emerge = "reload1";
		Locations[n].reload.l6.close_for_night = 1;
		if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l6.goto_disable = 1; // Screwface: Disable Go-To location
	}
	// RobC/Alan_Smithee Blacksmiths <--

//JRH burned kosters -->
	Locations[n].locators_radius.randitem.randitem2 = 0.1;
	Locations[n].items.randitem2 = "koster4";

	Locations[n].locators_radius.randitem.randitem3 = 0.1;
	Locations[n].items.randitem3 = "koster4";

	Locations[n].locators_radius.randitem.randitem4 = 0.1;
	Locations[n].items.randitem4 = "koster3";

	Locations[n].locators_radius.randitem.randitem5 = 0.1;
	Locations[n].items.randitem5 = "koster3";

	Locations[n].locators_radius.randitem.randitem6 = 0.1;
	Locations[n].items.randitem6 = "koster3";

	Locations[n].locators_radius.randitem.randitem7 = 0.1;
	Locations[n].items.randitem7 = "koster2";
//JRH burned kosters <--

	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\pirateresidence";

	Locations[n].id = "QC_residence";
	locations[n].id.label = "House of leader #stown_name# pirates";
	Locations[n].image = "Inside_PirateResidence";
	//Town sack
	Locations[n].townsack = "Quebradas Costillas"; // NK - "Oxbay";
	//Sound
	locations[n].type = "residence"; // NK bugfix 04-08
	locations[n].fastreload = "QC";
	//Models
	//Always
	Locations[n].models.always.locators = "resp_l";
	Locations[n].models.always.l1 = "resp";
	Locations[n].models.always.window = "resp_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "resp_p";

	//Night
	Locations[n].models.night.charactersPatch = "resp_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\qcresp_";
	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "QC_town";
	Locations[n].reload.l1.emerge = "Reload10";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#."; // KK


	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\StoreSmall";
	Locations[n].image = "Inside_StoreSmall";

	Locations[n].id = "QC_Store";
	locations[n].id.label = "#stown_name# store";
	//Town sack
	Locations[n].townsack = "Quebradas Costillas"; // NK - "Oxbay";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "QC";
	//Models
	//Always
	Locations[n].models.always.locators = "SS_l";
	Locations[n].models.always.l1 = "ss";
	Locations[n].models.always.window = "ss_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "ss_p";
	Locations[n].models.day.fonar = "SS_fn";

	//Night
	Locations[n].models.night.charactersPatch = "ss_p";
	Locations[n].models.night.fonar = "SS_fn";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\qcss_";
	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "QC_town";
	Locations[n].reload.l1.emerge = "Reload5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;

	// ----------------ADDED BY VERRUCKT------------------------

	Locations[n].filespath.models = "locations\inside\shipyard2";//"locations\Inside\shipyard";

	Locations[n].id = "QC_shipyard";
	locations[n].id.label = "#stown_name# shipyard";
	Locations[n].image = "Inside_Shipyard2";

	//Town sack
	Locations[n].townsack = "Quebradas Costillas"; // NK - "Oxbay";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "QC";
	//Models
	//Always
	//THIS PART IS FOR THE OXBAY STYLE SHIPYARD(BIG)
	/*Locations[n].models.always.locators = "sh01_l";
	Locations[n].models.always.shipyard = "sh01";
	Locations[n].models.always.window = "sh01_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;*/

	//THIS PART IS FOR THE Falaise de Fleur STYLE SHIPYARD(FANCY)
	Locations[n].models.always.locators = "sh02_l";
	Locations[n].models.always.tavern = "sh02";
	Locations[n].models.always.window = "sh02_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	//THIS PART IS FOR THE OXBAY STYLE SHIPYARD(BIG)
	/*Locations[n].models.day.charactersPatch = "sh01_p";
	Locations[n].models.day.fd = "sh01_fd";*/

	//THIS PART IS FOR THE Falaise de Fleur STYLE SHIPYARD(FANCY)
	Locations[n].models.day.charactersPatch = "sh02_p";

	//Night
	//THIS PART IS FOR THE OXBAY STYLE SHIPYARD(BIG)
	/*Locations[n].models.night.charactersPatch = "sh01_p";
	Locations[n].models.night.fn = "sh01_fn";*/

	//THIS PART IS FOR THE Falaise de Fleur STYLE SHIPYARD(FANCY)
	Locations[n].models.night.charactersPatch = "sh02_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\ffsh2_";//<<<--------------FOR OXBAY USE "back\oxsh1_";
	//Reload map
	Locations[n].reload.l1.name = "locator2";//<<<<-------------THIS USED TO BE "reload1";
	Locations[n].reload.l1.go = "QC_town";
	Locations[n].reload.l1.emerge = "Reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;
	//------------------END ADDED BY VERRUCKT--------------------
	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\SmallHome";

	Locations[n].id = "QC_UsurerHouse";
	locations[n].id.label = "Loanshark's Office.";
	Locations[n].image = "Inside_Smallhome";
	//Town sack
	Locations[n].townsack = "Quebradas Costillas"; // NK - "Oxbay";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "QC";
	//Models
	//Always
	Locations[n].models.always.locators = "Sh_L";
	Locations[n].models.always.l1 = "SH";
	Locations[n].models.always.window = "sh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "SH_p";

	//Night
	Locations[n].models.night.charactersPatch = "SH_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\qcsh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "QC_town";
	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\SmallTavern";

	Locations[n].id = "QC_Tavern";
	locations[n].id.label = "#stown_name# tavern";
	Locations[n].image = "Inside_SmallTavern";
	//Town sack
	Locations[n].townsack = "Quebradas Costillas"; // NK - "Oxbay";
	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "QC";
	//Models
	//Always
	Locations[n].models.always.locators = "ST_l";
	Locations[n].models.always.l1 = "ST";
	Locations[n].models.always.window = "ST_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "ST_p";

	//Night
	Locations[n].models.night.charactersPatch = "ST_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\qcst_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "QC_town";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "QC_tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.disable = 1;
	Locations[n].reload.l2.label = "Room.";
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\SmallHome";

	Locations[n].id = "QC_tavern_upstairs";
	locations[n].id.label = "Room in #stown_name# tavern";
	Locations[n].image = "Inside_Doubleflour_House_Room"; // ccc: Skip VC in room
	//Town sack
	Locations[n].townsack = "Quebradas Costillas"; // NK - "Oxbay";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "QC";
	//Models
	//Always
	Locations[n].models.always.locators = "SH_l";
	Locations[n].models.always.l1 = "SH";
	Locations[n].models.always.window = "sh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "SH_p";

	//Night
	Locations[n].models.night.charactersPatch = "SH_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\qcsh_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "QC_tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# tavern."; // KK


	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Pirate_Outer_Location";

	Locations[n].id = "QC_Pirate_house";
	locations[n].id.label = "Entrance to strange house";
	Locations[n].image = "Outside_Pirate_Outer_location";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "Pirl_l";
	Locations[n].models.always.house = "pirl";
	Locations[n].models.always.grassPatch = "pirl_g";
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
	Locations[n].models.day.charactersPatch = "Pirl_p";
	Locations[n].models.day.fonar = "pirl_fd";
	//Night
	Locations[n].models.night.charactersPatch = "pirl_p";
	Locations[n].models.night.fonar = "pirl_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "QC_Jungle_04";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "QC_Jungle_04";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 3.0;
	Locations[n].reload.l3.label = "Jungle.";


	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "QC_Pirate_house_inside";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Enter.";


	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Pirate_House";

	Locations[n].id = "QC_Pirate_house_inside";
	locations[n].id.label = "Inside strange house";
	Locations[n].image = "Inside_Pirate_House";
	//Sound
	locations[n].type = "house";
	//Models
	//Always
	Locations[n].models.always.locators = "pirh_l";
	Locations[n].models.always.house = "pirh";
	Locations[n].models.always.window = "pirh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "pirh_p";

	//Night
	Locations[n].models.night.charactersPatch = "pirh_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\qcpirh_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "QC_pirate_house";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Exit.";


	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Smallhome";
	Locations[n].id = "QC_HouseInsideR4";
	locations[n].id.label = "House";
	Locations[n].image = "Inside_Smallhome";

	//Town sack
	Locations[n].townsack = "Quebradas Costillas"; // NK

	//Sound
	locations[n].type = "house";
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
	Locations[n].models.back = "back\qcsh_";
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "QC_town";
	Locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";



	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;


	// -------------------------------------------------
	// -------------------------------------------------
	Locations[n].id = "QC_brothel_upstairs";
	locations[n].id.label = "Room in #stown_name# brothel.";
	if (IsBrothelEnabled()) {
		//Town sack
		Locations[n].townsack = "Quebradas Costillas";
		//Sound
		locations[n].type = "room";
		locations[n].fastreload = "QC";
		LAi_LocationFantomsGen(&locations[n], false);

		InitBrothelRoom(Locations[n].id);

		Locations[n].island = "QuebradasCostillas";
	}
	n = n + 1;

	// -----BROTHEL--------------------------------------------
	Locations[n].id = "QC_brothel";
	if (IsBrothelEnabled()) InitQCBrothel(); // MAXIMUS: possibility to initialize brothel during game
	n = n + 1;

 	//-------------------------------------------------
	//------------------END ADDED BY VERRUCKT--------------------
	// -------------------------------------------------
	Locations[n].id = "QC_HouseInsideR9";
	locations[n].id.label = "House";
	Locations[n].image = "Inside_Doubleflour_House_Upper";

	//Town sack
	Locations[n].townsack = "Quebradas Costillas"; // NK

	//Sound
	locations[n].type = "house";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Doubleflour_house";
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
	Locations[n].models.back = "back\qclf2_";
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "QC_town";
	Locations[n].reload.l1.emerge = "reload9";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";



	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;
	//---------------------------------------------
	//--------CHARLESTOWN Thomas the Terror--------
	//---------------------------------------------
	locations[n].id = "Charlestown_port";
	Locations[n].name = "Charlestown Port";
	locations[n].id.label = "#stown_name# Port."; // KK
	locations[n].worldmap = "Charlestown";

	locations[n].townsack = "Charlestown";
	locations[n].fastreload = "Charlestown";

	//Models
	locations[n].filespath.models = "locations\Town_Charlestown";
	locations[n].image = "Town_Charlestown";

	Locations[n].models.always.locators = "Charlestown_l";

	//Upgrades
	Locations[n].models.always.shipyard = "..\upgrades\shipyard1";
	Locations[n].models.always.shipyard.status = "..\upgrades\shipyard1";
	InitUpgrades(Locations[n].id); // KK
	//Sound
	locations[n].type = "port";
	locations[n].soundskip = true;//MAXIMUS: will resolve trouble with sounds [strange, but StaticSounds not works in AOP locations. I'm wondering - all was OK with these locations]
	LAi_LocationFantomsGen(&locations[n], true);

	//Always
	Locations[n].models.always.grassPatch = "Charlestown_g";
	Locations[n].models.always.l1 = "Charlestown";
	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.l2 = "Charlestown_sb";
	Locations[n].models.always.l2.foam = "1";

	Locations[n].models.always.l4 = "Charlestown_signsA";
	Locations[n].models.always.l4.level = 9;

	//Day
	Locations[n].models.day.rinok = "Charlestown_e1";
	Locations[n].models.day.fonar = "Charlestown_fd";
	Locations[n].models.day.charactersPatch = "Charlestown_pd";
	//Night
	Locations[n].models.night.fonar = "Charlestown_fn";
	Locations[n].models.night.charactersPatch = "Charlestown_pn";

	//Reload map
/*
	Locations[n].reload.l1.name = "reload2_back";
	Locations[n].reload.l1.autoreload = "0";
// KK -->
	if (VISIT_DECK == 1)
		Locations[n].reload.l1.label = "Ship.";
	else
		Locations[n].reload.l1.label = "Sea.";
// <-- KK
	Locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.autoreload = "0";
// KK -->
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
// <-- KK
	Locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].reload.l3.name = "reload5_back";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Shipyard.";
	Locations[n].reload.l3.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l3.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l4.name = "reload6_back";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Store.";
	Locations[n].reload.l4.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l4.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l5.name = "reload3_back";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Residence.";
	Locations[n].reload.l5.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l5.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l6.name = "reload4_back";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Tavern.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l6.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l7.name = "houseS1";
	Locations[n].reload.l7.autoreload = "0";

	Locations[n].reload.l8.name = "reload8_back";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "Loanshark's Office.";
	Locations[n].reload.l8.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l8.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l9.name = "reload7_back";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "Church.";
	Locations[n].reload.l9.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l9.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l10.name = "gate";
	Locations[n].reload.l10.autoreload = "0";

	Locations[n].reload.l11.name = "brothel";
	Locations[n].reload.l11.autoreload = "0";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l11.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l12.name = "houseS3";
	Locations[n].reload.l12.autoreload = "0";

	Locations[n].reload.l13.name = "houseH1";
	Locations[n].reload.l13.autoreload = "0";

	Locations[n].reload.l14.name = "barracks";
	Locations[n].reload.l14.autoreload = "0";
	Locations[n].reload.l14.close_for_night = 1;

	Locations[n].reload.l15.name = "storehouse";
	Locations[n].reload.l15.autoreload = "0";
	Locations[n].reload.l15.close_for_night = 1;

	Locations[n].reload.l16.name = "reload10_1";
	Locations[n].reload.l16.autoreload = "0";
	Locations[n].reload.l16.label = "Naval Academy";
	Locations[n].reload.l16.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l16.goto_disable = 1; //JRH
*/
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.8;		//JRH: water was visible in town sometimes
	//Reload map

	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "QuebradasCostillas";
	locations[n].reload.l1.emerge = "reload_2";
	locations[n].reload.l1.autoreload = "0";
//	locations[n].reload.l1.label = "Sea.";
// KK -->
	if (VISIT_DECK == 1)
		Locations[n].reload.l1.label = "Ship.";
	else
		Locations[n].reload.l1.label = "Sea.";
// <-- KK
	Locations[n].locators_radius.reload.boat = 12.0;

	locations[n].reload.l3.name = "reload3_back";
	locations[n].reload.l3.go = "Charlestown_Residence";
	locations[n].reload.l3.emerge = "locator2";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Residence";
	Locations[n].reload.l3.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l3.goto_disable = 1; // Screwface: Disable Go-To location

	locations[n].reload.l4.name = "reload4_back";
	locations[n].reload.l4.go = "Charlestown_Tavern";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "Tavern";
	Locations[n].reload.l4.close_for_night = 0;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l4.goto_disable = 1; // Screwface: Disable Go-To location

	locations[n].reload.l5.name = "reload5_back";
	locations[n].reload.l5.go = "Charlestown_shipyard";
	locations[n].reload.l5.emerge = "reload1";
	locations[n].reload.l5.autoreload = "0";
	locations[n].reload.l5.label = "Shipyard";
	Locations[n].reload.l5.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l5.goto_disable = 1; // Screwface: Disable Go-To location

	locations[n].reload.l6.name = "reload6_back";
	locations[n].reload.l6.go = "Charlestown_Store";
	locations[n].reload.l6.emerge = "locator2";
	locations[n].reload.l6.autoreload = "0";
	locations[n].reload.l6.label = "Store";
	Locations[n].reload.l6.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l6.goto_disable = 1; // Screwface: Disable Go-To location

	locations[n].reload.l7.name = "reload7_back";
	locations[n].reload.l7.go = "Charlestown_church";
	locations[n].reload.l7.emerge = "reload1";
	locations[n].reload.l7.autoreload = "0";
	locations[n].reload.l7.label = "Church";
	Locations[n].reload.l7.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l7.goto_disable = 1;

	locations[n].reload.l8.name = "reload8_back";
	locations[n].reload.l8.go = "Charlestown_usurer";
	locations[n].reload.l8.emerge = "reload1";
	locations[n].reload.l8.autoreload = "0";
	locations[n].reload.l8.label = "Bank";
//	locations[n].reload.l8.disable = 0;			//JRH: conflict with fast reload
	Locations[n].reload.l8.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l8.goto_disable = 1; // Screwface: Disable Go-To location

	locations[n].reload.l10.name = "gate";
	locations[n].reload.l10.go = "QC_Jungle_03";
	locations[n].reload.l10.emerge = "reload1";
	locations[n].reload.l10.autoreload = "0";
	locations[n].reload.l10.label = "Jungle";

	locations[n].reload.l11.name = "houseS2";
	locations[n].reload.l11.go = "Charlestown_Guardhouse";
	locations[n].reload.l11.emerge = "reload2";
	locations[n].reload.l11.autoreload = "0";
	locations[n].reload.l11.label = "prison";
//	Locations[n].reload.l11.disable = 0;			// GR: conflict with fast travel
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l11.goto_disable = 1;

	locations[n].reload.l12.name = "housesp3";
	locations[n].reload.l12.go = "Charlestown_House_03";
	locations[n].reload.l12.emerge = "reload1";
	locations[n].reload.l12.autoreload = "0";
	locations[n].reload.l12.label = "House";
	locations[n].reload.l12.disable = 0;
	Locations[n].reload.l12.close_for_night = 1;

	locations[n].reload.l13.name = "housesp4";
	locations[n].reload.l13.go = "Charlestown_House_02";
	locations[n].reload.l13.emerge = "reload1";
	locations[n].reload.l13.autoreload = "0";
	locations[n].reload.l13.label = "House";
	locations[n].reload.l13.disable = 0;
	Locations[n].reload.l13.close_for_night = 1;

	locations[n].reload.l14.name = "househ2";
	locations[n].reload.l14.go = "Charlestown_House_01";
	locations[n].reload.l14.emerge = "reload1";
	locations[n].reload.l14.autoreload = "0";
	locations[n].reload.l14.label = "House";
	locations[n].reload.l14.disable = 0;
	Locations[n].reload.l14.close_for_night = 1;

//SJG for Mudd MAY09
	locations[n].reload.l15.name = "houseH1";
	locations[n].reload.l15.go = "Mystery_House";
	locations[n].reload.l15.emerge = "reload1";
	locations[n].reload.l15.autoreload = "0";
	locations[n].reload.l15.label = "Mystery House";
	locations[n].reload.l15.disable = 0;
	Locations[n].reload.l15.close_for_night = 0;
//SJG for Mudd MAY09

	// SJG -->
	locations[n].reload.l16.name = "reload10_1";
	locations[n].reload.l16.go = "Charlestown_Academy";
	locations[n].reload.l16.emerge = "reload1";
	locations[n].reload.l16.autoreload = "0";
	locations[n].reload.l16.label = "Naval Academy";
//	locations[n].reload.l16.disable = 0;			//JRH: conflict with fast reload
	Locations[n].reload.l16.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l16.goto_disable = 1; //JRH
	// SJG <--

	locations[n].reload.l17.name = "reload17";
	locations[n].reload.l17.go = "bb_Maltains";
	locations[n].reload.l17.emerge = "reload1";
	locations[n].reload.l17.autoreload = "0";
	locations[n].reload.l17.label = "Order of Malta only in WoodesRogers quest";	
	locations[n].reload.l17.disable = 1;			//JRH WoodesRogers: close_for_day after info from Hands

	locations[n].reload.l18.name = "reload18";
	locations[n].reload.l18.go = "bb_Maltains";
	locations[n].reload.l18.emerge = "reload3";
	locations[n].reload.l18.autoreload = "0";
	locations[n].reload.l18.label = "Order of Malta only in WoodesRogers quest";
	locations[n].reload.l18.disable = 1;

	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "Charlestown_church";
	locations[n].id.label = "Church";
	//Town sack
	Locations[n].townsack = "Charlestown";
	//Sound
	locations[n].type = "Church";
	locations[n].fastreload = "Charlestown";

	InitChurch1(Locations[n].id);

	//Reload map
	Locations[n].reload.l1.go = "Charlestown_Port";
	Locations[n].reload.l1.label = "Charlestown";

	Locations[n].island = "QuebradasCostillas";
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "Charlestown_usurer";
	locations[n].id.label = "Loanshark's Office";
	//Town sack
	Locations[n].townsack = "Charlestown";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Charlestown";

	InitBank(Locations[n].id);

	//Reload map
	Locations[n].reload.l1.go = "Charlestown_Port";
	Locations[n].reload.l1.label = "#stown_name# port";

	Locations[n].island = "QuebradasCostillas";
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "Charlestown_Academy";
	locations[n].id.label = "Naval academy";
	//Town sack
	Locations[n].townsack = "Charlestown";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Charlestown";

	InitShipyard4(Locations[n].id);

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Charlestown_Port";
	Locations[n].reload.l1.emerge = "reload10_1";
	Locations[n].reload.l1.label = "Charlestown";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Town_Tunnel";
	Locations[n].reload.l2.emerge = "reload1_back";
	Locations[n].reload.l2.label = "Cellar";

	Locations[n].island = "QuebradasCostillas";
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "Charlestown_Brothel_bedroom";
	if (IsBrothelEnabled()) {
		locations[n].id.label = "Brothel Bedroom";
		//Town sack
		Locations[n].townsack = "Charlestown";
		//Sound
		locations[n].type = "room";
		locations[n].fastreload = "Charlestown";
		LAi_LocationFantomsGen(&locations[n], false);

		InitBrothelRoom(Locations[n].id);

		Locations[n].island = "QuebradasCostillas";
	}
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "Charlestown_Brothel";
	if (IsBrothelEnabled()) InitCharlestownBrothel(); // KK
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "Charlestown_Guardhouse";
	locations[n].id.label = "Guardhouse";
	//Town sack
	Locations[n].townsack = "Charlestown";
	//Sound
	locations[n].type = "jail";
	locations[n].fastreload = "Charlestown";

	InitHut(Locations[n].id);

	//Reload map
	Locations[n].reload.l1.go = "Charlestown_port";
	Locations[n].reload.l1.label = "Charlestown.";
	Locations[n].reload.l1.emerge = "houses2";

	Locations[n].reload.l2.go = "Charlestown_prison";
	Locations[n].reload.l2.label = "Prison";
	Locations[n].reload.l2.emerge = "reload1";

	Locations[n].island = "QuebradasCostillas";
	n = n + 1;

    //  -------------------------------------------------
	Locations[n].id = "Charlestown_prison";
	locations[n].id.label = "Prison";
	Locations[n].filespath.models = "locations\inside\prison";
	Locations[n].image = "Inside_Prison";

	//Town sack
	Locations[n].townsack = "Charlestown";

	//Sound
	locations[n].type = "jail";
	//Models
	//Always
	Locations[n].models.always.prison = "Pri";
	Locations[n].models.always.locators = "Pri_l";
	Locations[n].models.always.window = "Pri_w";
	//Day
	Locations[n].models.day.charactersPatch = "Pri_p";
	//Night
	Locations[n].models.night.charactersPatch = "Pri_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Charlestown_Guardhouse";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.label = "Guardhouse.";

	locations[n].reload.l2.name = "reload12";
	locations[n].reload.l2.go = "";
	locations[n].reload.l2.emerge = "reload12";
	locations[n].reload.l2.disable = 1;
	Locations[n].locators_radius.reload.reload12 = 0.5;
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "QuebradasCostillas";
	n = n + 1;
	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\shipyard3";

	Locations[n].id = "Charlestown_shipyard";
	locations[n].id.label = "#stown_name# shipyard";
	Locations[n].image = "Inside_Shipyard3";

	//Town sack
	Locations[n].townsack = "Charlestown";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Charlestown";
	//Models
	//Always
	Locations[n].models.always.locators = "sh03_l";
	Locations[n].models.always.l1 = "Sh03";
	Locations[n].models.always.window = "sh03_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "Sh03_p";

	//Night
	Locations[n].models.night.charactersPatch = "Sh03_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\grsh3_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Charlestown_Port";
	Locations[n].reload.l1.emerge = "reload5_back";
	Locations[n].reload.l1.label = "SeaPort";
	Locations[n].reload.l1.autoreload = "0";
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Charlestown_Residence";
	Locations[n].filespath.models = "locations\inside\shipyard2";
	locations[n].id.label = "Townhall";
	Locations[n].image = "Inside_Shipyard2_Townhall";

	//Town sack
	Locations[n].townsack = "Charlestown";

	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Charlestown";
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
	Locations[n].reload.l1.go = "Charlestown_Port";
	Locations[n].reload.l1.emerge = "reload3_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";
	Locations[n].locators_radius.reload.locator2 = 0.8;
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;
	//------------------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\MediumTavern";

	Locations[n].id = "Charlestown_Tavern";
	locations[n].id.label = "Tavern";
	Locations[n].image = "Inside_MediumTavern";

	//Town sack
	Locations[n].townsack = "Charlestown";

	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "Charlestown";
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
	Locations[n].reload.l1.go = "Charlestown_Port";
	Locations[n].reload.l1.emerge = "reload4_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Charlestown_tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Room in #stown_name# tavern."; // KK
	Locations[n].reload.l2.disable = true;
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Charlestown_tavern_upstairs";
	locations[n].id.label = "Room in tavern"; // KK
	Locations[n].image = "Inside_Doubleflour_House_Room";

	//Town sack
	Locations[n].townsack = "Charlestown";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Charlestown"; // KK
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
	Locations[n].models.back = "back\grlf2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Charlestown_tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Tavern";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;

	//-------------------------------------------------
	Locations[n].id = "Charlestown_Store";
	locations[n].id.label = "#stown_name# store";
	Locations[n].filespath.models = "locations\inside\StoreSmall";
	Locations[n].image = "Inside_StoreSmall";

	//Town sack
	Locations[n].townsack = "Charlestown";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Charlestown";
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
	Locations[n].reload.l2.name = "locator2";
	Locations[n].reload.l2.go = "Charlestown_Port";
	Locations[n].reload.l2.emerge = "reload6_back";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name#";

	Locations[n].reload.l1.name = "locator1";
	Locations[n].reload.l1.go = "bb_Maltains_office";
	Locations[n].reload.l1.emerge = "locator2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Secret room only in Woodes Rogers storyline";
	Locations[n].reload.l1.disable = true;			//only in WoodesRogers

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;
	// -------------------------------------------------
	// HOUSES
	// -------------------------------------------------

	Locations[n].id = "Charlestown_House_01";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house";
	Locations[n].image = "Inside_Doubleflour_House_Lower";

	//Town sack
	Locations[n].townsack = "Charlestown";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Charlestown";
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
	Locations[n].reload.l1.go = "Charlestown_port";
	Locations[n].reload.l1.emerge = "househ2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Town.";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "QuebradasCostillas";
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\MediumHouse";
	Locations[n].id = "Charlestown_House_02";
	locations[n].id.label = "House";
	Locations[n].image = "Inside_MediumHouse";

	//Town sack
	Locations[n].townsack = "Charlestown";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Charlestown";
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
	Locations[n].reload.l1.go = "Charlestown_Port";
	Locations[n].reload.l1.emerge = "housesp4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";

	Locations[n].island = "QuebradasCostillas";
	n = n + 1;

	//----------------------------------------------------
	Locations[n].id = "Charlestown_House_03";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\mh9";
	Locations[n].image = "Inside_mh9";

	//Town sack
	Locations[n].townsack = "Charlestown";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Charlestown";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\mh9";
	Locations[n].models.always.city = "mh9";
	Locations[n].models.always.locators = "mh9_l";
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
	Locations[n].reload.l1.go = "Charlestown_Port";
	Locations[n].reload.l1.emerge = "housesp3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Town.";

	Locations[n].island = "QuebradasCostillas";
	n = n + 1;

//SJG for Mudd MAY 09 -------------------------------------------------

	Locations[n].id = "Mystery_House";
	locations[n].id.label = "Mystery House";
	Locations[n].filespath.models = "locations\inside\StoreHouse";
	Locations[n].image = "Inside_Storehouse";

	//Town sack
	Locations[n].townsack = "Charlestown";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Charlestown";

	InitStoreHouse(Locations[n].id);

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\fflf1_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Charlestown_port";
	Locations[n].reload.l1.emerge = "houseH1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Charlestown Port";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Back_Room";
	Locations[n].reload.l2.emerge = "locator2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Back Room";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Tunnel";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Tunnel to Beach";


	Locations[n].island = "QuebradasCostillas";
	n = n + 1;

// SJG cont. ---------------------------------------------------------

	Locations[n].id = "Back_Room";
	locations[n].id.label = "Back Room";
	Locations[n].filespath.models = "locations\inside\shipyard2";
	Locations[n].image = "Inside_Shipyard2";

	//Town sack
	Locations[n].townsack = "Charlestown";

	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Charlestown";

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
	Locations[n].reload.l1.go = "Mystery_House";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Mystery House";
	Locations[n].locators_radius.reload.locator2 = 0.8;

	Locations[n].reload.l2.name = "Reload2";
	Locations[n].reload.l2.go = "Town_Tunnel";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Cellar";
	Locations[n].locators_radius.reload.locator2 = 0.5;

	Locations[n].island = "QuebradasCostillas";
	n = n + 1;

// SJG --------------------------------------------------------------
	Locations[n].id = "Town_Tunnel";
	locations[n].id.label = "Cellar";
	Locations[n].filespath.models = "locations\Inside\Cellar_downstairs";
	Locations[n].image = "Inside_Cellar_downstairs";

	//Town sack
	Locations[n].townsack = "Charlestown";
	//Sound
	locations[n].type = "dungeon";

	//Models
	//Always
	locations[n].filespath.models = "locations\inside\Cellar_downstairs";
	locations[n].models.always.locators = "Cellar_downstairs_locators";
	locations[n].models.always.tavern = "Cellar_downstairs";
	locations[n].models.always.rays = "Cellar_downstairs_rays";
	locations[n].models.always.stuff = "Cellar_downstairs_stuff";

	//Day
	Locations[n].models.day.charactersPatch = "cellar_downstairs_patch";
	//Night
	Locations[n].models.night.charactersPatch = "cellar_downstairs_patch";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload3";
	Locations[n].reload.l1.go = "Back_Room";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Back Room";

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Charlestown_Academy";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Naval Academy";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Pirate_Entrance";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Pirate Entrance";

	Locations[n].island = "QuebradasCostillas";
	n = n + 1;

// SJG --------------------------------------------------------------
	Locations[n].id = "Tunnel";
	locations[n].id.label = "Beach Tunnel";
	Locations[n].filespath.models = "locations\Inside\Mine";
	Locations[n].image = "Inside_Mine";

	//Town sack
	Locations[n].townsack = "Charlestown";
	//Sound
	locations[n].type = "cave";

	//Models
	//Always
	Locations[n].models.always.locators = "mine_l";
	Locations[n].models.always.l1 = "mine";
	//Day
	Locations[n].models.day.charactersPatch = "mine_p";
	//Night
	Locations[n].models.night.charactersPatch = "mine_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Mystery_House";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Mystery House";

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "QC_Shore1";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Beach";

	Locations[n].island = "QuebradasCostillas";
	n = n + 1;

//SJG-------------------------------------------------
	Locations[n].id = "Pirate_Entrance";
	locations[n].id.label = "Pirate Entrance";
	Locations[n].image = "Inside_ShipyardPirates";
	Locations[n].filespath.models = "locations\Inside\ShipyardPirates";

	//Town sack

	//Sound
	locations[n].type = "shop";
	//Models
	//Always
	Locations[n].models.always.locators = "ShipyardPirates_locators";
	locations[n].models.always.shipyard = "ShipyardPirates";
	Locations[n].models.always.window = "ShipyardPirates_fn";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65532;

	//Day
	locations[n].models.day.charactersPatch = "ShipyardPirates_patch";
	//Night
	locations[n].models.night.charactersPatch = "ShipyardPirates_patch";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Special_House";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Pirate House";

	locations[n].reload.l2.name = "reload3";
	locations[n].reload.l2.go = "Town_Tunnel";
	locations[n].reload.l2.emerge = "reload2";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Town Tunnel";

	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\SmallHome";

	Locations[n].id = "Special_House";
	locations[n].id.label = "Pirate House";
	Locations[n].image = "Inside_Smallhome";
	//Town sack
	Locations[n].townsack = "Quebradas Costillas";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "QC";
	//Models
	//Always
	Locations[n].models.always.locators = "Sh_L";
	Locations[n].models.always.l1 = "SH";
	Locations[n].models.always.window = "sh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "SH_p";

	//Night
	Locations[n].models.night.charactersPatch = "SH_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\qcsh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "QC_town";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Pirate_Entrance";
	Locations[n].reload.l2.emerge = "reload1_back";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Pirate Entrance";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;

//End SJG	// -------------------------------------------------

	Locations[n].id = "QC_Shore1";
	locations[n].id.label = "White Bay"; // KK
	locations[n].worldmap = "QC_Shore1";
	Locations[n].filespath.models = "locations\Outside\Shore_7";
	Locations[n].image = "Outside_Shore_7";
	Locations[n].name = "White Bay";
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

	//Day
	Locations[n].models.day.charactersPatch = "Shore07_p";
	//Night
	Locations[n].models.night.charactersPatch = "Shore07_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "QC_jungle_01";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle";
	Locations[n].locators_radius.reload.reload2 = 3.0;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "QC_jungle_01";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle";
	Locations[n].locators_radius.reload.reload2_back = 3.0;
//> SJG MAY 09
	Locations[n].reload.l4.name = "reload3";
	Locations[n].reload.l4.go = "Tunnel";
	Locations[n].reload.l4.emerge = "reload1_back";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Tunnel";
	Locations[n].locators_radius.reload.reload3 = 0.5;
//< SJG
	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "QuebradasCostillas";
	Locations[n].reload.l2.emerge = "reload_3";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 9.0;


	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;

	 // -------------------------------------------------
    Locations[n].id = "QC_jungle_01";
	locations[n].id.label = "Jungle";
	Locations[n].filespath.models = "locations\Outside\jungle_8";
	Locations[n].image = "Outside_Jungle_8";
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
	Locations[n].reload.l1.go = "QC_Jungle_2";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle";
	Locations[n].locators_radius.reload.reload1 = 3.0;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "QC_Jungle_2";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "QC_Shore1";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "White Bay";
	Locations[n].locators_radius.reload.reload2 = 3.0;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "QC_Shore1";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "White Bay";
	Locations[n].locators_radius.reload.reload2_back = 2.0;


	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;
	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Jungle_1";

	Locations[n].id = "QC_Jungle_03";
	locations[n].id.label = "Jungle";
	Locations[n].image = "Outside_Jungle_1";
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

	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Charlestown_port";
	Locations[n].reload.l1.emerge = "gate";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle";
	Locations[n].locators_radius.reload.Reload1 = 3.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "QC_Jungle_2";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle";
	Locations[n].locators_radius.reload.Reload2 = 3.0;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Charlestown_port";
	Locations[n].reload.l3.emerge = "gate";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "QC_Jungle_2";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle";
	Locations[n].locators_radius.reload.reload2_back = 2.0;


	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;
// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_3";
	Locations[n].filespath.textures = "locations\JUNGLES";

	Locations[n].id = "QC_Jungle_2";
	locations[n].id.label = "Jungle";
	Locations[n].image = "Outside_Jungle_3";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "Jungle03_l";
	Locations[n].models.always.jungle = "Jungle03";
	Locations[n].models.always.grassPatch = "JUNGLE03_g";
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
	Locations[n].models.day.charactersPatch = "Jungle03_p";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle03_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "QC_Jungle_03";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle";
	Locations[n].locators_radius.reload.Reload1 = 1.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "QC_jungle_01";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle";
	Locations[n].locators_radius.reload.Reload2 = 3.0;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "QC_Jungle_04";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle";
	Locations[n].locators_radius.reload.Reload3 = 3.0;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "QC_Jungle_03";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l5.name = "reload2_back";
	Locations[n].reload.l5.go = "QC_jungle_01";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Jungle";
	Locations[n].locators_radius.reload.reload2_back = 3.0;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "QC_Jungle_04";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle";
	Locations[n].locators_radius.reload.reload3_back = 3.0;


	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;
	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_6";

	Locations[n].id = "QC_Jungle_04";
	locations[n].id.label = "#sisland_name# jungle";
	Locations[n].image = "Outside_Jungle_6";
	//Sound
	locations[n].type = "jungle";
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
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "QC_town_exit";
	Locations[n].reload.l1.emerge = "Reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 2.5;
	Locations[n].reload.l1.label = "Jungle";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "QC_Jungle_2";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload2 = 2.5;
	Locations[n].reload.l2.label = "Jungle";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "QC_Pirate_house";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.reload3 = 2.5;
	Locations[n].reload.l3.label = "Jungle";

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "QC_Jungle_2";
	Locations[n].reload.l4.emerge = "reload3";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].locators_radius.reload.reload2_back = 2.5;
	Locations[n].reload.l4.label = "House";

	Locations[n].reload.l5.name = "reload3_back";
	Locations[n].reload.l5.go = "QC_Pirate_house";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].locators_radius.reload.reload3_back = 3;
	Locations[n].reload.l5.label = "House";

	Locations[n].reload.l6.name = "reload1_back";
	Locations[n].reload.l6.go = "QC_town_exit";
	Locations[n].reload.l6.emerge = "Reload3";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 2.5;
	Locations[n].reload.l6.label = "Jungle";


	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
}
