void LocationInitAntigua(ref n)
{
	// ccc Antigua fake forts--------------------------------------

	//ID
	Locations[n].id = "Antigua_fakefort1";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_1";
	Locations[n].image = "Fort_Inside_Fort_1"; // KK

	//Town sack
	Locations[n].townsack = "St John's";
	//Sound
	locations[n].type = "military";

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
	Locations[n].reload.l1.name = "reloadc2";
	Locations[n].reload.l1.go = "Antigua_fakefort3";
	Locations[n].reload.l1.emerge = "reloadc2";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reloadC4";
	Locations[n].reload.l2.go = "Antigua_armory";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l3.name = "reloadc5";
	Locations[n].reload.l3.go = "Antigua_fakefort2";
	Locations[n].reload.l3.emerge = "reload1";

	Locations[n].island = "Antigua";
	n = n + 1;

	// ccc Antigua fake fort 2----------------------------------

	//ID
	Locations[n].id = "Antigua_fakefort2";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";

	//Town sack
	Locations[n].townsack = "St John's";


	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_2";
	Locations[n].image = "Fort_Inside_Fort_2";
	//Sound
	locations[n].type = "military";

	//Models
	//Always
	Locations[n].models.always.locators = "fort2_l_ccc";
	Locations[n].models.always.l1 = "fort2";
	//Day
	Locations[n].models.day.charactersPatch = "fort2_p";
	Locations[n].models.day.fonar = "fort2_fd";
	//Night
	Locations[n].models.night.charactersPatch = "fort2_p";
	Locations[n].models.night.fonar = "fort2_fn";


	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";


	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Antigua_fakefort1";
	Locations[n].reload.l1.emerge = "reloadc5";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reloadc1";
	Locations[n].reload.l2.go = "Antigua_fakefort3";
	Locations[n].reload.l2.emerge = "reloadc1";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].island = "Antigua";
	n = n + 1;

	// ccc Antigua fake fort 3----------------------------------

	//ID
	Locations[n].id = "Antigua_fakefort3";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";


	//Town sack
	Locations[n].townsack = "St John's";

	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_3";
	Locations[n].image = "Fort_Inside_Fort_1";
	//Sound
	Locations[n].type = "military";

	//Models
	//Always
	Locations[n].models.always.locators = "fort3_l_ccc";
	Locations[n].models.always.l1 = "fort3";
	//Day
	Locations[n].models.day.charactersPatch = "fort3_p";
	Locations[n].models.day.fonar = "fort3_fd";
	//Night
	Locations[n].models.night.charactersPatch = "fort3_p";
	Locations[n].models.night.fonar = "fort3_fn";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	Locations[n].reload.l1.name = "reloadc1";
	Locations[n].reload.l1.go = "Antigua_fakefort2";
	Locations[n].reload.l1.emerge = "reloadc1";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reloadc2";
	Locations[n].reload.l2.go = "Antigua_fakefort1";
	Locations[n].reload.l2.emerge = "reloadc2";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l3.name = "reloadc4";
	Locations[n].reload.l3.go = "Antigua_port";
	Locations[n].reload.l3.emerge = "reload7_back";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].reload.l4.name = "reload1";
	Locations[n].reload.l4.go = "Antigua_armory";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "0";

	Locations[n].island = "Antigua";
	n = n + 1;


	// ccc Antigua armory-------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\LargeStore";
	Locations[n].id = "Antigua_armory";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";
	Locations[n].image = "Fort_Inside_Fort_2";

	//Town sack
	Locations[n].townsack = "St John's";
	//Sound
	locations[n].type = "military";

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
	Locations[n].reload.l1.go = "Antigua_fakefort1";
	Locations[n].reload.l1.emerge = "reloadc4";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Antigua_fakefort3";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].island = "Antigua";
	n = n + 1;

	// ccc fake fort end

	// -------------------------------------------------
	//ccc sep07 AOP st eustatius model for Antigua
	Locations[n].id = "Antigua_port";
	locations[n].id.label = "#stown_name# port.";
	locations[n].worldmap = "Antigua";
	Locations[n].filespath.models = "locations\Town_StJohns";
	Locations[n].image = "Town_StJohns";

	//Town sack
	Locations[n].townsack = "St John's";
	Locations[n].navy = 1;

	//Sound
	locations[n].type = "town"; // CCC - MUST be 'town' or no NPCs show up Nov17'06 // KK
	locations[n].soundskip = true;//MAXIMUS: will resolve trouble with sounds [strange, but StaticSounds not works in AOP locations. I'm wondering - all was OK with these locations]
	locations[n].fastreload = "Antigua"; // KK
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	locations[n].models.always.l1 = "StJohns";
	Locations[n].models.always.l1.foam = "1";
	// ccc no signs locations[n].models.always.L1 = "StEustatius_signsA";
	Locations[n].models.always.seabed = "StJohns_sb";
	Locations[n].models.always.seabed.foam = "1";
	locations[n].models.always.locators = "StJohns_locators";
	locations[n].models.always.grassPatch = "StJohns_grass";

	locations[n].models.always.plan = "plan1";
	locations[n].models.always.plan.level = 9;

	locations[n].models.always.add1 = "StJohnsAdd";
	locations[n].models.always.l2 = "bench";						//JRH: WR2

	//Day
	locations[n].models.day.fonar = "StJohns_fd";
	locations[n].models.day.charactersPatch = "StJohns_patch_night"; // ccc night patch !
	// ccc no traders locations[n].models.day.rinok = "StEustatius_rinok";
	//Night
	locations[n].models.night.fonar = "StJohns_fn";
	locations[n].models.night.charactersPatch = "StJohns_patch_night";

  // ccc sep07 end

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.95; // screwface

	//Reload map
	Locations[n].reload.l1.name = "reload_2_city";
	Locations[n].reload.l1.go = "Antigua_outskirts";
	Locations[n].reload.l1.emerge = "Reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Outskirts";

	Locations[n].reload.l3.name = "sea_2";
	Locations[n].reload.l3.go = "Antigua";
	Locations[n].reload.l3.emerge = "reload_2";
	Locations[n].reload.l3.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l3.label = "Ship.";
	else
		Locations[n].reload.l3.label = "Sea.";
	Locations[n].locators_radius.reload.sea_2 = 3.0;

	Locations[n].reload.l5.name = "sea_2_back";
	Locations[n].reload.l5.go = "Antigua";
	Locations[n].reload.l5.emerge = "reload_2";
	if (VISIT_DECK == 1)
		Locations[n].reload.l5.label = "Ship.";
	else
		Locations[n].reload.l5.label = "Sea.";
	Locations[n].locators_radius.reload.sea_2_back = 2.0;

	Locations[n].reload.l6.name = "Door_7";
	Locations[n].reload.l6.go = "Antigua_dungeon1";
	Locations[n].reload.l6.emerge = "reload1";

	Locations[n].reload.l7.name = "reload3_back";  //ccc oct07
	Locations[n].reload.l7.go = "Antigua_Residence";
	Locations[n].reload.l7.emerge = "reload1";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l7.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l8.name = "reload5_back";  //ccc oct07
	Locations[n].reload.l8.go = "Antigua_yard";
	Locations[n].reload.l8.emerge = "reload2";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l8.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l9.name = "houseS5";  //ccc oct07
	Locations[n].reload.l9.go = "Antigua_store";
	Locations[n].reload.l9.emerge = "locator2";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l9.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l10.name = "houseF1";  //ccc oct07
	Locations[n].reload.l10.go = "Antigua_house2";
	Locations[n].reload.l10.emerge = "reload1";

	Locations[n].reload.l11.name = "houseH2";  //ccc oct07
	Locations[n].reload.l11.go = "Antigua_house3";
	Locations[n].reload.l11.emerge = "reload1";

	Locations[n].reload.l12.name = "houseS3";  //ccc oct07
	Locations[n].reload.l12.go = "Antigua_house6";
	Locations[n].reload.l12.emerge = "reload1";

	// ccc oct07
	Locations[n].reload.l23.name = "reload7_back";
	Locations[n].reload.l23.go = "Antigua_fakefort3";
	Locations[n].reload.l23.emerge = "reloadC4";
	Locations[n].locators_radius.reload.reload7_back = 2.0;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l23.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l27.name = "houseS1";
	Locations[n].reload.l27.go = "Antigua_Residence";
	Locations[n].reload.l27.emerge = "reload3";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l27.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l25.name = "reload6_back";
	Locations[n].reload.l25.go = "Antigua_store";
	Locations[n].reload.l25.emerge = "locator1";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l25.goto_disable = 1; //JRH

  // ccc oct07
//SJG MAY 09
	locations[n].reload.l16.name = "reload4_back";// <---------------------SJG
	locations[n].reload.l16.go = "Antigua_Academy";
	locations[n].reload.l16.emerge = "reload1";
	locations[n].reload.l16.autoreload = "0";
	locations[n].reload.l16.label = "Naval Academy";
//	locations[n].reload.l16.disable = 0;							//JRH: conflict with fast reload
	Locations[n].reload.l16.close_for_night = 1;// <---------------------SJG
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l16.goto_disable = 1;    //JRH
//SJG MAY 09
	Locations[n].reload.l17.name = "reload9";
	Locations[n].reload.l17.go = "Antigua_mansion_bedroom2";
	Locations[n].reload.l17.emerge = "reload1";
	Locations[n].reload.l17.disable = 1;

	Locations[n].reload.l18.name = "reload10";						//JRH: WoodesRogers quest
	Locations[n].reload.l18.go = "Antigua_yard";
	Locations[n].reload.l18.emerge = "reload1";

	Locations[n].locators_radius.quest.defoe = 2.0;						//JRH: WR2
	Locations[n].locators_radius.quest.whistle = 2.5;					//JRH: WR2

	Locations[n].locators_radius.randitem.randitem1 = 0.001;				//JRH: WoodesRogers quest
	Locations[n].items.randitem1 = "gatedoor_shipyard";
	
	Locations[n].island = "Antigua";
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\pirateresidence";	

	Locations[n].id = "Antigua_house6";
	locations[n].id.label = "House";
	Locations[n].image = "Inside_PirateResidence";
	//Sound
	locations[n].type = "house";
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
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Antigua_port";
	Locations[n].reload.l1.emerge = "houseS3";  //ccc oct07

	Locations[n].island = "Antigua";
	n = n + 1;

	// ------------------------------------------
	
	Locations[n].filespath.models = "locations\Inside\Pirate_House";	

	Locations[n].id = "Antigua_house2";
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
	Locations[n].reload.l1.go = "Antigua_port";
	Locations[n].reload.l1.emerge = "houseF1";  //ccc oct07

	Locations[n].island = "Antigua";
	n = n + 1; 



	// -------------------------------------------------

	Locations[n].id = "Antigua_house3";
	Locations[n].image = "Inside_MediumHouse";

	//Sound
	locations[n].type = "house";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\MediumHouse";
	Locations[n].models.always.locators = "mh_l";
	Locations[n].models.always.house = "mh";
	Locations[n].models.always.window = "mh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "mh_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\oxmh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Antigua_port";
	Locations[n].reload.l1.emerge = "houseH2";  //ccc oct07

	Locations[n].island = "Antigua";
	n = n + 1;

	// Store -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\StoreSmall";
	Locations[n].image = "Inside_StoreSmall";

	Locations[n].id = "Antigua_Store";
	locations[n].id.label = "Naval Store";

	//Town sack
	Locations[n].townsack = "St John's";
	Locations[n].navy = 1;

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Antigua";
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
	Locations[n].models.night.fonar = "ss_fn";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\oxss_";
	//Reload map
	//ccc sep07
	Locations[n].reload.l1.name = "locator1";
	Locations[n].reload.l1.go = "Antigua_port";
	Locations[n].reload.l1.emerge = "reload6_back";

	Locations[n].reload.l2.name = "locator2";
	Locations[n].reload.l2.go = "Antigua_port";
	Locations[n].reload.l2.emerge = "houseS5";
	//ccc sep07

	Locations[n].island = "Antigua";
	n = n + 1;


	// Navy yard -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\shipyard";

	Locations[n].id = "Antigua_yard";
	locations[n].id.label = "Naval Shipyard";
	Locations[n].image = "Inside_Shipyard1";

	//Town sack
	Locations[n].townsack = "St John's";
	Locations[n].fastreload = "Antigua"; // KK
	Locations[n].navy = 1;

	//Sound
	locations[n].type = "shop";
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

	Locations[n].reload.l2.name = "reload2";	
	Locations[n].reload.l2.go = "Antigua_port";	
	Locations[n].reload.l2.emerge = "reload5_back";  //ccc oct07

	Locations[n].island = "Antigua";
	n = n + 1;


 	//-------------------------------------------------
	Locations[n].id = "Antigua_Residence";
	locations[n].id.label = "British Naval Headquarters"; // SJG MAY09
	Locations[n].filespath.models = "locations\inside\Residence_BackHall";
	Locations[n].image = "Inside_Residence_BackHall";

	//Town sack
	Locations[n].townsack = "St John's";
	Locations[n].navy = 1;

	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Antigua";
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
	Locations[n].reload.l1.go = "Antigua_port";
	Locations[n].reload.l1.emerge = "reload3_back"; // ccc oct07

	
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Antigua_mansion_study";
	Locations[n].reload.l2.emerge = "reload1";
	// ccc oct07
	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Antigua_port";
	Locations[n].reload.l3.emerge = "houseS1";
	//ccc oct07
	Locations[n].island = "Antigua";
	n = n + 1;

	// ccc study for Antigua mansion-------------------------------------------------

	Locations[n].filespath.models = "locations\inside\Residence2";

	Locations[n].id = "Antigua_mansion_study";
	locations[n].id.label = "British Naval Headquarters Study";
	Locations[n].image = "Inside_Residence2";

	//Town sack
	Locations[n].townsack = "St John's";
	//Sound
	locations[n].type = "residence";
	Locations[n].navy = 1; // KK
	//Models
	//Always
	Locations[n].models.always.city = "Res02";
	Locations[n].models.always.locators = "Res02_l_ccc";
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
	Locations[n].reload.l1.go = "Antigua_residence";
	Locations[n].reload.l1.emerge = "reload2";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Antigua_mansion_bedroom";
	Locations[n].reload.l2.emerge = "reload1";

	Locations[n].island = "Antigua";
	n = n + 1;

	//  ccc bedroom for Antigua mansion-------------------------------------------------
	Locations[n].id = "Antigua_mansion_bedroom";
	locations[n].id.label = "Bedroom";
	Locations[n].filespath.models = "locations\inside\ResBedRoom";
	Locations[n].image = "Inside_ResBedRoom";

	Locations[n].townsack = "St John's"; // KK
	Locations[n].fastreload = "Antigua"; // KK

	//Sound
	locations[n].type = "house";
	//Models
	//Always
	Locations[n].models.always.locators = "bed_l";
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
	Locations[n].reload.l1.go = "Antigua_mansion_study";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].island = "Antigua";
	n = n + 1;

	//  ccc bedroom for Antigua mansion-------------------------------------------------
	Locations[n].id = "Antigua_mansion_bedroom2";
	locations[n].id.label = "Bedroom";
	Locations[n].filespath.models = "locations\inside\ResBedRoom";
	Locations[n].image = "Inside_ResBedRoom";

	Locations[n].townsack = "St John's"; // KK
	Locations[n].fastreload = "Antigua"; // KK

	//Sound
	locations[n].type = "house";
	//Models
	//Always
	Locations[n].models.always.locators = "bed_l";
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
	Locations[n].reload.l1.go = "Antigua_port";
	Locations[n].reload.l1.emerge = "reload9";
	Locations[n].island = "Antigua";
	n = n + 1;
	
	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_Douwesen\exit";
	Locations[n].filespath.textures = "locations\ENGLAND";

	Locations[n].id = "Antigua_outskirts";
	locations[n].id.label = "Antigua";
	Locations[n].image = "Town_Douwesen_Exit";


	Locations[n].fastreload = "Antigua"; // KK
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	//Models
	//Always
	Locations[n].models.always.locators = "DouExit_l";

//	Locations[n].models.always.Waterfall1 = "waterfall";
//    Locations[n].models.always.Waterfall1.uvslide.u0 = 0.3;
//	Locations[n].models.always.Waterfall1.tech = "LocationWaterFall";
//	Locations[n].models.always.Waterfall1.level = 50;

    Locations[n].models.always.Waterfall3 = "waterfall2";
    Locations[n].models.always.Waterfall3.uvslide.u0 = 0.1;	// 0.2
	Locations[n].models.always.Waterfall3.tech = "LocationWaterFall";
	Locations[n].models.always.Waterfall3.level = 52;	//52

	Locations[n].models.always.exit = "DouExit";
	Locations[n].models.always.grassPatch = "DouExit_g";
	//Locations[n].models.always.l0 = "plan_4";
	//Locations[n].models.always.l0.level = 9;
	//Locations[n].models.always.l0.tech = "LocationModelBlend";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 8;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	//Locations[n].models.always.l2 = "plan_2";
	//Locations[n].models.always.l2.level = 7;
	//Locations[n].models.always.l2.tech = "LocationModelBlend";

	//Locations[n].models.always.l3 = "plan_3";
	//Locations[n].models.always.l3.level = 6;
	//Locations[n].models.always.l3.tech = "LocationModelBlend";


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
	Locations[n].reload.l1.go = "Antigua_Jungle_02";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 4;
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l3.name = "Reload1_back";
	Locations[n].reload.l3.go = "Antigua_Jungle_02";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.Reload1_back = 4;

	Locations[n].reload.l2.name = "Reload2";
	Locations[n].reload.l2.go = "Antigua_port";
	Locations[n].reload.l2.emerge = "reload_2_city";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Sea port.";

	Locations[n].reload.l4.name = "Reload6";
	Locations[n].reload.l4.go = "Antigua_Dungeon1";
	Locations[n].reload.l4.emerge = "reload2";
// SJG
	Locations[n].locators_radius.goto.goto51 = 1.0;
	Locations[n].locators_radius.goto.goto60 = 2.0;
	Locations[n].locators_radius.goto.goto25 = 2.0;
	Locations[n].locators_radius.goto.goto72 = 2.0;
	Locations[n].locators_radius.goto.goto73 = 2.0;
// SJG
	Locations[n].reload.l6.name = "reload3";
	Locations[n].reload.l6.go = "Antigua_Tavern"; // KK
	Locations[n].reload.l6.emerge = "reload1";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l6.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l7.name = "reload4";
	Locations[n].reload.l7.go = "Antigua_house4";
	Locations[n].reload.l7.emerge = "reload1";

	Locations[n].island = "Antigua";
	n = n + 1;

	//Antigua tavern -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\LargeTavern";

	Locations[n].id = "Antigua_Tavern"; // KK
	locations[n].id.label = "#stown_name# tavern";		// ccc oct06
	Locations[n].image = "Inside_LargeTavern";

	locations[n].townsack = "Antigua"; // KK
	locations[n].fastreload = "Antigua"; // KK

	//Sound
	locations[n].type = "tavern"; // KK
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
	Locations[n].models.back = "back\oxlt_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Antigua_outskirts";
	Locations[n].reload.l1.emerge = "reload3";

// KK -->
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Antigua_Tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Room in #stown_name# tavern.";
	Locations[n].reload.l2.disable = 1;
	LAi_LocationFightDisable(&Locations[n], true);
// <-- KK

	Locations[n].island = "Antigua";
	n = n + 1;

	// KK ------------------------------------------------->
	Locations[n].filespath.models = "locations\Inside\Doubleflour_house";

	Locations[n].id = "Antigua_Tavern_upstairs";
	Locations[n].id.label = "Room in #stown_name# tavern.";
	Locations[n].image = "Inside_Doubleflour_House_Room";

	locations[n].townsack = "Antigua";
	locations[n].fastreload = "Antigua";

	//Sound
	locations[n].type = "house";
	//Models
	//Always
	Locations[n].models.always.locators = "LH_F2_l";
	Locations[n].models.always.house = "LH_F2";
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
	Locations[n].models.back = "back\colf2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Antigua_Tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# tavern.";


	Locations[n].island = "Antigua";
	n = n + 1;
// <-- KK

	//outskirt hut -------------------------------------------------

	Locations[n].id = "Antigua_house4";
	Locations[n].image = "Inside_MediumHouse";

	//Sound
	locations[n].type = "house";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\MediumHouse";
	Locations[n].models.always.locators = "mh_l";
	Locations[n].models.always.house = "mh";
	Locations[n].models.always.window = "mh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "mh_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\oxmh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Antigua_outskirts";
	Locations[n].reload.l1.emerge = "reload4";

	Locations[n].island = "Antigua";
	n = n + 1;

//SJG MAY 09  -------------------------------------------------
	Locations[n].id = "Antigua_Academy";
	locations[n].id.label = "Naval Academy";
	//Town sack
	Locations[n].townsack = "Antigua";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Antigua";

	InitShipyard4(Locations[n].id);

	//Reload map
	Locations[n].reload.l1.go = "Antigua_Port";
	Locations[n].reload.l1.emerge = "reload4_back";
	Locations[n].reload.l1.label = "Antigua";

	Locations[n].island = "Antigua";
	n = n + 1;

//SJG MAY 09  -------------------------------------------------

	// ----------------- Antigua_Dungeon1 --------------------
	Locations[n].filespath.models = "locations\Inside\Dungeon_1";
	Locations[n].id = "Antigua_Dungeon1";
	Locations[n].image = "Inside_Dungeon_1";
	Locations[n].map = "mapOxbay_Dungeon";
	Locations[n].monsters = "1";
	locations[n].id.label = "Cellar";

	//Sound
	locations[n].type = "Dungeon";
	//Models
	//Always
	Locations[n].models.always.locators = "d01_l";
	Locations[n].models.always.house = "d01";
	//Day
	Locations[n].models.day.charactersPatch = "d01_p";
	//Night
	Locations[n].models.night.charactersPatch = "d01_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";

	LAi_LocationFantomsGen(&locations[n], true);

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Antigua_port";
	Locations[n].reload.l1.emerge = "door_7";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Antigua_outskirts";
	Locations[n].reload.l2.emerge = "reload6";
	Locations[n].reload.l2.autoreload = "1";

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Antigua_outskirts";
	Locations[n].reload.l3.emerge = "reload6";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.reload2_back = 1.5;

	Locations[n].items.randitem1 = "blade20";


	Locations[n].island = "Antigua";
	n = n + 1;

	// jungle 1, confusing trap -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_7";

	Locations[n].id = "Antigua_Jungle_01";
	locations[n].id.label = "Jungle";
	Locations[n].image = "Outside_Jungle_7";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);

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
	Locations[n].reload.l1.go = "Antigua_Jungle_03";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 4;

	Locations[n].reload.l5.name = "reload1_back";
	Locations[n].reload.l5.go = "Antigua_Jungle_03";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 1;

	Locations[n].reload.l4.name = "reload2";
	Locations[n].reload.l4.go = "Antigua_Jungle_03";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].locators_radius.reload.reload2 = 4;

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Antigua_Jungle_03";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Antigua_Jungle_02";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3 = 4;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Antigua_Jungle_02";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 2;


	Locations[n].island = "Antigua";
	n = n + 1;

	// jungle 2 -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_3";
	Locations[n].filespath.textures = "locations\JUNGLES";

	Locations[n].id = "Antigua_Jungle_02";
	locations[n].id.label = "#sisland_name# jungles";
	Locations[n].image = "Outside_Jungle_3";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);

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
	Locations[n].reload.l1.go = "Antigua_shore";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Muscetto Cove."; // KK
	Locations[n].locators_radius.reload.Reload1 = 1.0;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Antigua_shore";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Muscetto Cove."; // KK
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Antigua_jungle_01";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2 = 3.0;

	Locations[n].reload.l5.name = "reload2_back";
	Locations[n].reload.l5.go = "Antigua_jungle_01";
	Locations[n].reload.l5.emerge = "reload3";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3.0;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Antigua_outskirts";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload3 = 3.0;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Antigua_outskirts";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 3.0;


	Locations[n].island = "Antigua";
	n = n + 1;

	//-------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Jungle_1";

	Locations[n].id = "Antigua_Jungle_03";
	locations[n].id.label = "Jungle";
	Locations[n].image = "Outside_Jungle_1";
	//Sound
	locations[n].type = "Jungle";

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
	Locations[n].reload.l1.go = "Antigua_Jungle_01";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 3.0;

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Antigua_Jungle_01";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 3.0;

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Antigua_Jungle_01";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.reload2 = 3.0;

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Antigua_Jungle_01";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].locators_radius.reload.reload2_back = 3.0;

	Locations[n].island = "Antigua";
	n = n + 1;


	//  -------------------------------------------------
	Locations[n].id = "Antigua_shore";
	locations[n].id.label = "Muscetto Cove."; // KK
	//locations[n].worldmap = "Muscetto Cove"; // KK
	Locations[n].filespath.models = "locations\Outside\Shore_6";
	Locations[n].image = "Outside_Shore_6";
	Locations[n].name = "Muscetto Cove";
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

	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Antigua_Jungle_02";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.locator3 = 1;

	Locations[n].reload.l3.name = "Reload2_back";
	Locations[n].reload.l3.go = "Antigua_Jungle_02";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2_back = 5;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Antigua";
	Locations[n].reload.l2.emerge = "reload_3";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 11.0;

	Locations[n].island = "Antigua";
	n = n + 1;

// Additional Buildings
// SJG ->
	Build_at("Antigua_port", "cannonl", "", 12.500, 1.9500, -10.824, -3.0000, "");
	Build_at("Antigua_port", "cannonl", "", 12.500, 1.9500, -16.835, -3.0000, ""); 
// <- SJG
	Build_at("Antigua_outskirts", "windmill", "windmillfan", 1.7, 6.0, 40.0, -3.0, "");
	Build_at("Antigua_outskirts", "tower", "", 43.2, -1.0, 91.2, -1.75, "");

	Build_at("Antigua_jungle_02", "workshop", "mine", -9.7, 0.0, 8.1, -3.1, "");

// SJG	Build_at("Antigua_shore", "bigforest", "", 72.0, 2.0, -4.0, -1.0, "");

	SetTownNation("St John's", ENGLAND); // KK
}
