void LocationInitIslaMona(ref n)
{
	// -------------------------------------------------
	Locations[n].filespath.models = "locations\outside\Mayak";

	Locations[n].id = "IslaMona_port";
	Locations[n].name = "Port";
	locations[n].id.label = "Isla Mona Port";
	Locations[n].image = "Outside_Mayak.tga";
	//Sound
	locations[n].type = "seashore";
	//Models
	//Always
	Locations[n].models.always.locators = "mayak_ls";
	Locations[n].models.always.shore = "mayak";
	Locations[n].models.always.shore.foam = "1";
	Locations[n].models.always.seabed = "Mayak_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "Mayak_g";

	//Day
	Locations[n].models.day.charactersPatch = "mayak_p";
	Locations[n].models.day.fonar = "Mayak_fd";
	//Night
	Locations[n].models.night.charactersPatch = "mayak_p";
	Locations[n].models.night.fonar = "Mayak_fn";
	Locations[n].models.night.window = "Mayak_win";
	Locations[n].models.night.light = "Mayak_fl";
	Locations[n].models.night.light.level = 80;
	Locations[n].models.night.light.tech = "LighthouseLight";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "IslaMona_port_exit";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "";
	Locations[n].locators_radius.reload.Reload1 = 3.0;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "IslaMona_port_exit";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload1_back = 3.0;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "IslaMona";
	Locations[n].reload.l2.emerge = "Reload_1";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 12.0;

	Locations[n].reload.l4.name = "reload5";
	Locations[n].reload.l4.go = "IslaMona_headport_house";
	Locations[n].reload.l4.emerge = "Reload1";
	Locations[n].reload.l4.label = "head port house.";

	Locations[n].reload.l5.name = "reload2";
	Locations[n].reload.l5.go = "IslaMona_Tavern";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Tavern.";
	Locations[n].locators_radius.reload.Reload1 = 3.0;
	
	Locations[n].reload.l6.name = "reload6";
	Locations[n].reload.l6.go = "IslaMona_warehouse";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "warehouse";
	Locations[n].locators_radius.reload.Reload1 = 3.0;	

	Locations[n].island = "IslaMona"; // NK 04-08-29
	n = n + 1;
	
	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\MediumTavern";

	Locations[n].id = "IslaMona_Tavern";
	locations[n].id.label = "Isla Mona Tavern";
	Locations[n].image = "Inside_MediumTavern.tga";

	//Town sack
	Locations[n].townsack = "Isla Mona"; // NK 04-08-29

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
	Locations[n].models.back = "back\smumt_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "IslaMona_port";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Isla Mona Port";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "IslaMona"; // NK 04-08-29
	n = n + 1;	

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\outside\Mayak_inside";

	Locations[n].id = "IslaMona_headport_house";
	Locations[n].name = "head port house";
	locations[n].id.label = "head port house.";
	Locations[n].image = "Outside_Mayak_Inside.tga";
	//Sound
	locations[n].type = "house";

	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.shore = "imayak";
	Locations[n].models.always.shore.foam = "1";
	Locations[n].models.always.seabed = "iMayak_sb";
	Locations[n].models.always.seabed.foam = "1";
	//Models
	//Always
	Locations[n].models.always.locators = "imayak_l";
	Locations[n].models.always.shore = "imayak";
	Locations[n].models.always.window = "iMayak_w";
	//Day
	Locations[n].models.day.charactersPatch = "imayak_p";
	Locations[n].models.day.jumpPatch = "imayak_j";
	//Night
	Locations[n].models.night.charactersPatch = "imayak_p";
	Locations[n].models.night.jumpPatch = "imayak_j";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "IslaMona_Port";
	Locations[n].reload.l1.emerge = "reload5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Isla Mona Port";
	Locations[n].locators_radius.reload.Reload1 = 1.5;

	Locations[n].items.randitem1 = "spyglass4";

	Locations[n].island = "IslaMona"; // NK 04-08-29
	n = n + 1;
	

 	// -------------------------------------------------
	Locations[n].id = "IslaMona_warehouse";
	locations[n].id.label = "Isla Mona warehouse";
	Locations[n].filespath.models = "locations\inside\Shipyard";
	Locations[n].image = "Inside_Warehouse.tga";

	//Town sack
	Locations[n].townsack = "Isla Mona";
	//Sound
	locations[n].type = "shop";
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
	Locations[n].reload.l1.go = "IslaMona_port";
	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Isla Mona Port";

	Locations[n].island = "IslaMona"; // NK 04-08-29
	n = n + 1;	
	
	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\pirateresidence";	

	Locations[n].id = "IslaMona_residence";
	locations[n].id.label = "Commander's House";
	Locations[n].image = "Inside_PirateResidence_IslaMona.tga";
	//Town sack
	Locations[n].townsack = "Isla Mona"; 
	//Sound
	locations[n].type = "residence";
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
	Locations[n].reload.l1.go = "IslaMona_port_exit";
	Locations[n].reload.l1.emerge = "Reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "outskirts"; // KK
	
	LAi_LocationFightDisable(&Locations[n], true);	

	Locations[n].island = "IslaMona"; // NK 04-08-29
	n = n + 1;	
	
	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_QC\exit";	

	Locations[n].id = "IslaMona_port_exit";
	locations[n].id.label = "Exit from port";
	Locations[n].image = "Town_QC_Exit.tga";
	//Town sack
	Locations[n].townsack = "Isla Mona"; 
	//Sound
	locations[n].type = "jungle";

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

	Locations[n].reload.l2.name = "Reload2";
	Locations[n].reload.l2.go = "IslaMona_port";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Sea port.";
	Locations[n].locators_radius.reload.reload2 = 3.0;

	Locations[n].reload.l20.name = "Reload2_back";
	Locations[n].reload.l20.go = "IslaMona_port";
	Locations[n].reload.l20.emerge = "reload1";
	Locations[n].reload.l20.autoreload = "1";
	Locations[n].reload.l20.label = "Sea port.";
	Locations[n].locators_radius.reload.Reload2_back = 2.0;

	Locations[n].reload.l3.name = "Reload3";
	Locations[n].reload.l3.go = "IslaMona_passage";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Sea port.";
	Locations[n].locators_radius.reload.reload3 = 3.0;

	Locations[n].reload.l30.name = "Reload3_back";
	Locations[n].reload.l30.go = "IslaMona_passage";
	Locations[n].reload.l30.emerge = "reload2";
	Locations[n].reload.l30.autoreload = "1";
	Locations[n].reload.l30.label = "Sea port.";
	Locations[n].locators_radius.reload.Reload3_back = 2.0;

	Locations[n].reload.l4.name = "reload4";
	Locations[n].reload.l4.go = "IslaMona_residence";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.close_for_night = 1;

	Locations[n].island = "IslaMona"; // NK 04-08-29
	n = n + 1;
	
	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Passage";

	Locations[n].id = "IslaMona_passage";
	locations[n].id.label = "#sisland_name# passage";
	Locations[n].image = "Outside_Passage2.tga";
	Locations[n].vcskip = true;
	//Sound
	locations[n].type = "seashore";

	//Models
	//Always
	Locations[n].models.always.locators = "pass2_l_BOP";
	Locations[n].models.always.jungle = "pass2";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.seabed = "pass2_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "pass2_g";
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
	Locations[n].reload.l1.go = "IslaMona_port_exit";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	//Locations[n].locators_radius.reload.reload2 = 2.0;
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "IslaMona_port_exit";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload2 = 2.0;
	Locations[n].reload.l2.label = "Jungle.";

	Locations[n].reload.l3.name = "reload1";
	Locations[n].reload.l3.go = "Fort_Entry";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "fort entry";
//	Locations[n].locators_radius.reload.reload1 = 2.0;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Fort_Entry";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "fort entry";
	Locations[n].locators_radius.reload.reload1_back = 2.0;
	if(sti(GetStorylineVar(FindCurrentStoryline(), "ASSN_PUZZLES")) > 0)
	{
		Locations[n].reload.l4.disable = 0;
	}
	else Locations[n].reload.l4.disable = 1;

	Locations[n].locators_radius.randitem.randitem2 = 0.01;
	Locations[n].items.randitem2 = "gatedoor_w8";

	Locations[n].island = "IslaMona"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Mine";

	Locations[n].id = "Fort_Entry";
	if(sti(GetStorylineVar(FindCurrentStoryline(), "ASSN_PUZZLES")) > 0)
	{
		locations[n].id.label = "Fort";
	}
	Locations[n].image = "Inside_Mine.tga";

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
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "IslaMona_passage";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "IslaMona_passage";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	
	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "IslaMona_fort";
	Locations[n].reload.l3.emerge = "reloadc1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Fort.";	

	Locations[n].island = "IslaMona";
	n = n + 1;
	
	// ----------------------------------
	//ID
	Locations[n].id = "IslaMona_fort";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";

	//Town sack
	Locations[n].townsack = "Isla Mona";

	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_2";
	Locations[n].image = "Fort_Inside_Fort_1.tga";
	//Sound
	locations[n].type = "town";

	//Models
	//Always
	Locations[n].models.always.locators = "fort2_l_s";
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

	Locations[n].reload.l1.name = "reloadc1";
	Locations[n].reload.l1.go = "Fort_Entry";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	
	Locations[n].island = "IslaMona";	
	n = n + 1;

    Build_at("IslaMona_port", "tower", "", -89.308, 4.317, -58.78, -2.278, "building");	
	Build_at("IslaMona_port", "warehouse", "", 5.867, 11.604, -70.479, 0, "building");
	Build_at("IslaMona_fort", "cannonb", "", -6.519, 13.244, -2.6, -1.5, "building");
	Build_at("IslaMona_fort", "cannonb", "", 4.33, 13.244, -2.6, -1.5, "building");

	Build_at("IslaMona_warehouse", "bale", "", -7.17, 0.00, -8.50, -1.47, "Building");
	Build_at("IslaMona_warehouse", "bale", "", 5.12, 0.00, -6.75, 1.71, "Building");
	Build_at("IslaMona_warehouse", "bale", "", -0.41, 0.00, -11.53, 3.12, "Building");
	Build_at("IslaMona_warehouse", "bale", "", -2.07, 0.00, -10.00, 0.00, "Building");
	Build_at("IslaMona_warehouse", "bale", "", 0.75, 0.00, -3.68, 1.27, "Building");
	Build_at("IslaMona_warehouse", "bale", "", 1.95, 0.00, -7.61, -3.00, "Building");
	Build_at("IslaMona_warehouse", "bale", "", -2.01, 0.00, -11.36, 0.00, "Building");
	Build_at("IslaMona_warehouse", "bale", "", 7.13, 0.00, -7.00, 0.00, "Building");
}


