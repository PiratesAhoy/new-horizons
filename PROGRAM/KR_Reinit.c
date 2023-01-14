void Reinit_KhaelRoa()
{
	int n;

	if (Locations[FindLocation("KhaelRoa_port")].reload.l2.go == "Temple")
	{  
	// Test to avoid of adding the locations several times if you reinit again and again

	// To insert Jungle locations between 2 existing locations, you'll have to redefine the existing
	// doors (locators) at departure and in arrival
	// DEPARTURE
	Locations[FindLocation("KhaelRoa_port")].reload.l2.name = "reload1";
	Locations[FindLocation("KhaelRoa_port")].reload.l2.go = "KhaelRoa_jungle_01";
	Locations[FindLocation("KhaelRoa_port")].reload.l2.emerge = "reload1";
	Locations[FindLocation("KhaelRoa_port")].reload.l2.autoreload = "1";

	Locations[FindLocation("KhaelRoa_port")].reload.l3.name = "reload1_back";
	Locations[FindLocation("KhaelRoa_port")].reload.l3.go = "KhaelRoa_Jungle_01";
	Locations[FindLocation("KhaelRoa_port")].reload.l3.emerge = "reload3";
	Locations[FindLocation("KhaelRoa_port")].reload.l3.autoreload = "1";
	Locations[FindLocation("KhaelRoa_port")].locators_radius.reload.reload1_back = 2;
	// The locator to the temple is now linked with the first new jungle area
	
	n = nLocationsNum;

	// -------------------------------------------------

// ADDITION OF THE NEW LOCATIONS
	Locations[n].filespath.models = "locations\Outside\Jungle_6";

	Locations[n].id = "KhaelRoa_Jungle_01";
	locations[n].id.label = "Khael Roa jungles";		//spell-checked by KAM
	Locations[n].image = "Outside_Jungle_6"; // KK
	//Sound
	locations[n].type = "KR_Jungle";
	Locations[n].island = "KhaelRoa"; // NK 04-11-03
		
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
	Locations[n].reload.l1.go = "KhaelRoa_Jungle_02";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 2.5;
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Roa_Cave";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload2 = 2.5;
	Locations[n].reload.l2.label = "Shore.";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "KhaelRoa_Port";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.reload3 = 2.5;
	Locations[n].reload.l3.label = "Jungle.";

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Roa_Cave";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].locators_radius.reload.reload2_back = 2.5;
	Locations[n].reload.l4.label = "Shore";

	Locations[n].reload.l5.name = "reload3_back";
	Locations[n].reload.l5.go = "KhaelRoa_port";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].locators_radius.reload.reload3_back = 3;
	Locations[n].reload.l5.label = "Jungle.";

	Locations[n].reload.l6.name = "reload1_back";
	Locations[n].reload.l6.go = "KhaelRoa_Jungle_02";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 2.5;
	Locations[n].reload.l6.label = "Jungle.";

	Locations[n].island = "KhaelRoa"; // NK 04-08-29
	n = n + 1;
        
	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_6";

	Locations[n].id = "KhaelRoa_Jungle_01";
	locations[n].id.label = "Khael Roa jungles";		//spell-checked by KAM
	Locations[n].image = "Outside_Jungle_6";
	//Sound
	locations[n].type = "KR_Jungle";
	Locations[n].island = "KhaelRoa"; // NK 04-11-03
		
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
	Locations[n].reload.l1.go = "KhaelRoa_Jungle_02";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 2.5;
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Roa_Cave";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].locators_radius.reload.reload2 = 2.5;
	Locations[n].reload.l2.label = "Shore.";

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "KhaelRoa_Port";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.reload3 = 2.5;
	Locations[n].reload.l3.label = "Jungle.";

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Roa_Cave";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].locators_radius.reload.reload2_back = 2.5;
	Locations[n].reload.l4.label = "Shore";

	Locations[n].reload.l5.name = "reload3_back";
	Locations[n].reload.l5.go = "KhaelRoa_port";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].locators_radius.reload.reload3_back = 3;
	Locations[n].reload.l5.label = "Jungle.";

	Locations[n].reload.l6.name = "reload1_back";
	Locations[n].reload.l6.go = "KhaelRoa_Jungle_02";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].locators_radius.reload.reload1_back = 2.5;
	Locations[n].reload.l6.label = "Jungle.";

	Locations[n].island = "KhaelRoa"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_7";

	Locations[n].id = "KhaelRoa_Jungle_02";
	locations[n].id.label = "Khael Roa jungles";
	Locations[n].image = "Outside_Jungle_7";
	//Sound
	locations[n].type = "KR_Jungle";
	//LAi_LocationMonstersGen(&locations[n], true);
	//LAi_LocationSetMonstersTime(&locations[n], 22, 6);
	Locations[n].island = "KhaelRoa"; // NK 04-11-03


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
	Locations[n].reload.l1.go = "KhaelRoa_Jungle_01";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1 = 4;

	Locations[n].reload.l5.name = "reload1_back";
	Locations[n].reload.l5.go = "KhaelRoa_Jungle_01";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 1;

	Locations[n].reload.l4.name = "reload2";
	Locations[n].reload.l4.go = "Temple";
	Locations[n].reload.l4.emerge = "reload1"; // fix
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Incas Temple.";
	Locations[n].locators_radius.reload.reload2 = 4;

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Temple";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Incas Temple.";
	Locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "KhaelRoa_Jungle_03";
	Locations[n].reload.l3.emerge = "reload1"; // fix
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3 = 4;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "KhaelRoa_Jungle_03";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 2;

	Locations[n].island = "KhaelRoa"; // NK 04-08-29
	n = n + 1;

	// ************************************************************-------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_1";

	Locations[n].id = "KhaelRoa_Jungle_03";
	locations[n].id.label = "Khael Roa jungles";
	Locations[n].image = "Outside_Jungle_1";
	//Sound
	locations[n].type = "KR_Jungle";
	Locations[n].island = "KhaelRoa"; // NK 04-11-03

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
	Locations[n].reload.l1.go = "KhaelRoa_Jungle_02";
	Locations[n].reload.l1.emerge = "reload3"; // fix
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1 = 3.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Roa_Cave2";
	Locations[n].reload.l2.emerge = "locator3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Cave.";
	Locations[n].locators_radius.reload.Reload2 = 3.0;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "KhaelRoa_Jungle_02";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Roa_Cave2";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Cave.";
	Locations[n].locators_radius.reload.reload2_back = 2.0;

	Locations[n].island = "KhaelRoa"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Cave Entrance";

	Locations[n].id = "Roa_Cave2";
	locations[n].id.label = "Khael Roa cave entrance";
	Locations[n].image = "Outside_Cave_Entrance";
	//Sound
	locations[n].type = "KR_Jungle";
	//LAi_LocationMonstersGen(&locations[n], true);
	//LAi_LocationSetMonstersTime(&locations[n], 22, 6);
	Locations[n].island = "KhaelRoa"; // NK 04-11-03

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
	Locations[n].reload.l3.go = "Roa_dungeon";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Cave.";
	Locations[n].locators_radius.reload.Reload1 = 1;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Roa_dungeon";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Cave.";
	Locations[n].locators_radius.reload.Reload1_back = 1.3;

	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "KhaelRoa_Jungle_03";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2 = 2.0;

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "KhaelRoa_Jungle_03";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 2.0;

	Locations[n].island = "KhaelRoa"; // NK 04-08-29
	n = n + 1;

	// -----------------Mosh D24--------------------
	Locations[n].filespath.models = "locations\Inside\Dungeon_4";
	Locations[n].id.label = "Dungeon";
	Locations[n].id = "Roa_dungeon";
	Locations[n].image = "Inside_Dungeon_4";
//	Locations[n].monsters = "1";

	//Sound
	locations[n].type = "KhaelRoa";
	Locations[n].island = "KhaelRoa"; // NK 04-11-03
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
	Locations[n].reload.l1.go = "Roa_Cave2";//Mosh
	Locations[n].reload.l1.emerge = "reload1";

	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 0, 24);

	Locations[n].items.randitem1 = "blade12";

	Locations[n].island = "KhaelRoa"; // NK 04-08-29
	n = n + 1;

// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Cave Entrance";

	Locations[n].id = "roa_Cave";
	locations[n].id.label = "Entrance to #sisland_name# cave";
	Locations[n].image = "Outside_Cave_Entrance";
	//Sound
	locations[n].type = "KR_Jungle";
	//LAi_LocationSetMonstersTime(&locations[n], 22, 6);
	Locations[n].island = "KhaelRoa"; // NK 04-11-03

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
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "KhaelRoa_Cavern";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Cave.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "KhaelRoa_Jungle_01";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 2.0;

	Locations[n].reload.l3.name = "reload2_back";      //if you return to the jungle
	Locations[n].reload.l3.go = "KhaelRoa_Jungle_01";
	Locations[n].reload.l3.emerge = "reload2";      //you arrive here
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 2.0;

	Locations[n].island = "KhaelRoa"; // NK 04-08-29
	n = n + 1;

// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Cavern";

	Locations[n].id = "KhaelRoa_Cavern";
	locations[n].id.label = "#sisland_name# Cavern";
	Locations[n].image = "Inside_Cavern";

	//Sound
	locations[n].type = "KhaelRoa";
	Locations[n].island = "KhaelRoa"; // NK 04-11-03
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
	Locations[n].reload.l1.go = "Roa_Cave";
	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Roa_Cave";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Roa_Hideout";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Secret Hideout";

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Roa_Hideout";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Secret Hideout";
	Locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].island = "KhaelRoa"; // NK 04-08-29
	n = n + 1;

// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Cave_Ship"; // SD

	Locations[n].id = "Roa_Hideout";
	locations[n].id.label = "Secret Hideout";
	Locations[n].image = "Inside_Cave_Ship";

	//Town sack
	locations[n].townsack = "Khael Roa"; // Screwface : to be allowed berth ships here

	//Sound
	locations[n].type = "KhaelRoa";
	Locations[n].island = "KhaelRoa"; // NK 04-11-03
	//Models
	//Always
	Locations[n].models.always.locators = "Cave_Ship_l";
	Locations[n].models.always.l1 = "Cave_Ship";
//	Locations[n].models.always.l2 = "Cave_Ship_add1";
	//Day
	Locations[n].models.day.charactersPatch = "Cave_Ship_p";
	//Night
	Locations[n].models.night.charactersPatch = "Cave_Ship_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0.0; // screwface

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "KhaelRoa_Cavern";
	Locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Hideout.";

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "KhaelRoa_Cavern";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Hideout.";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Roa_Cabin";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Captain's Cabin";

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Roa_Cabin";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Captain's Cabin";

	Locations[n].island = "KhaelRoa"; // NK 04-08-29
	n = n + 1;

// -------------------------------------------------

	locations[n].id = "Roa_Cabin";
	locations[n].id.label = "Captain's Cabin";
	locations[n].filespath.models = "locations\Inside\ShipyardPirates";
	locations[n].image = "Inside_ShipyardPirates";

	//Town sack
	Locations[n].townsack = "Quebradas Costillas";

	//Sound
	locations[n].type = "music_pirate_governor";

	//Models
	//Always
	locations[n].models.always.locators = "ShipyardPirates_locators_KR";
	locations[n].models.always.shipyard = "ShipyardPirates";
	locations[n].models.always.window = "ShipyardPirates_fn";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65532;

	//Day
	locations[n].models.day.charactersPatch = "ShipyardPirates_patch";
	//Night
	locations[n].models.night.charactersPatch = "ShipyardPirates_patch";


	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	
	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Roa_Hideout";
	Locations[n].reload.l1.emerge = "reload2_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Hideout.";

	Locations[n].island = "KhaelRoa"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
// END OF THE ADDITION

	// The locator in the temple location where we arrived from the shore is now relinked
	// with a jungle section
	locations[FindLocation("Temple")].type = "KR_Jungle";
	Locations[FindLocation("Temple")].reload.l1.name = "reload1";
	Locations[FindLocation("Temple")].reload.l1.go = "KhaelRoa_Jungle_02";
	Locations[FindLocation("Temple")].reload.l1.emerge = "reload2"; // fix
	Locations[FindLocation("Temple")].reload.l1.autoreload = "1";

	Locations[FindLocation("Temple")].reload.l3.name = "reload1_back";
	Locations[FindLocation("Temple")].reload.l3.go = "KhaelRoa_Jungle_02";
	Locations[FindLocation("Temple")].reload.l3.emerge = "reload2"; // fix
	Locations[FindLocation("Temple")].reload.l3.autoreload = "1";
	Locations[FindLocation("Temple")].locators_radius.reload.reload1_back = 3;

	// -------------------------------------------------

	nlocationsNum = n;
	ReloadProgressUpdate();
	Add_KR_Characters();
	}

	Island_SetReloadEnableGlobal("KhaelRoa", true); //<--I added this line 
	Island_SetReloadEnableLocal("KhaelRoa", "reload_1", true); // restore the access to Khael Roa beach (anchor icon)
	Island_SetGotoEnableLocal("KhaelRoa", "reload_1", true); // restore the fast travel to the KR shore (icon of the beach in sea mode)
	
	// restore the locator to return to the ship when you're on the shore
	Locations[FindLocation("KhaelRoa_port")].reload.l2.name = "boat";
	Locations[FindLocation("KhaelRoa_port")].reload.l2.go = "KhaelRoa";
	Locations[FindLocation("KhaelRoa_port")].reload.l2.emerge = "reload_1";
	Locations[FindLocation("KhaelRoa_port")].reload.l2.autoreload = "0";
	Locations[FindLocation("KhaelRoa_port")].locators_radius.reload.boat = 9.0;
	Locations[FindLocation("KhaelRoa_port")].reload.l2.label = "Sea.";

	// To be able to come out again of the temple by SirChristopherMings
	// SirChris -- Island_SetReloadEnableLocal("Maze", "reload_1", true); 
	// SirChris -- Island_SetGotoEnableLocal("Maze", "reload_1", true); 
	Locations[FindLocation("Labirint_1")].reload.l1.disable = 0; 
	Locations[FindLocation("Labirint_1")].reload.l1.name = "reload27"; 
	Locations[FindLocation("Labirint_1")].reload.l1.go = "Temple"; 
	Locations[FindLocation("Labirint_1")].reload.l2.go = "KhaelRoa"; 
	Locations[FindLocation("Labirint_1")].reload.l1.emerge = "reload2"; 
	Locations[FindLocation("Labirint_1")].reload.l1.autoreload = "1";

	Locations[FindLocation("KhaelRoa_port")].reload.l1.disable = 0; //<--I added this line 
	Locations[FindLocation("KhaelRoa_port")].reload.l2.disable = 0; //<--I added this line 
	
	Islands[FindIsland("KhaelRoa")].model = "KhaelRoa1";      //seems to set an accessible model for KR by CCC
	Islands[FindIsland("KhaelRoa")].filespath.models = "islands\KhaelRoa1"; 
	Islands[FindIsland("KhaelRoa")].refl_model = "KhaelRoa1_refl";
}

void Add_KR_Characters()
{
	int n;
	ref ch;
	  
	n = FindBlankCharSlot();
	CHARACTERS_QUANTITY++; // NK 05-04-05
	makeref(ch,Characters[n]);
	ch.old.name = "Crewmember";
	ch.old.lastname = "";
	ch.name 	= TranslateString("","Crewmember");
	ch.lastname = "";
	ch.id		= "KR_Crew1";
	ch.model	= "bocman";
	ch.headmodel = "h_bocman";
	ch.sound_type = "seaman";
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Roa_Hideout";
	ch.location.group = "goto";
	ch.location.locator = "goto2";
	ch.Dialog.Filename = "KR_crewmember.c";
	ch.nation = PIRATE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "15";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "7";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "7";
	ch.money = "1";
	ch.quest.sex = 0;
	ch.sex.time = 0;
	//LAi_SetStayType(ch);
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 60.0, 60.0);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	/*
	LAi_SetSitType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	*/

	n = FindBlankCharSlot();
	CHARACTERS_QUANTITY++; // NK 05-04-05
	makeref(ch,Characters[n]);
	ch.old.name = "Crewmember";
	ch.old.lastname = "";
	ch.name 	= TranslateString("","Crewmember");
	ch.lastname = "";
	ch.id		= "KR_Crew2";
	ch.model	= "sailor5";
	ch.headmodel = "h_sailor5";
	ch.sound_type = "seaman";
	ch.sex = "man";
	GiveItem2Character(ch, "blade27");
	ch.equip.blade = "blade27";
	GiveItem2Character(ch, "pistol2");
	ch.equip.gun = "pistol2";
    //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {		// LDH added check
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
    //JRH ammo mod <--
	ch.location	= "Roa_Hideout";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "KR_crewmember.c";
	ch.nation = PIRATE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "20";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "7";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "7";
	ch.money = "1";
	ch.quest.sex = 0;
	ch.sex.time = 0;
	//LAi_SetStayType(ch);
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 60.0, 60.0);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	/*
	LAi_SetSitType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	*/

	n = FindBlankCharSlot();
	CHARACTERS_QUANTITY++; // NK 05-04-05
	makeref(ch,Characters[n]);		
	ch.old.name = "Crewmember";
	ch.old.lastname = "";
	ch.name 	= TranslateString("","Crewmember");
	ch.lastname = "";
	ch.id		= "KR_Crew3";
	ch.model	= "sailor6";
	ch.headmodel = "h_sailor6";
	ch.sound_type = "seaman";
	ch.sex = "man";
	GiveItem2Character(ch, "blade1");
	ch.equip.blade = "blade1";
	if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)
	{
		GiveItem2Character(ch, "pistol1");
		ch.equip.gun = "pistol1";
	}
	else
	{
		GiveItem2Character(ch, "pistol1a");
		ch.equip.gun = "pistol1a";
	}
    //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {		// LDH added check
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
    //JRH ammo mod <--
 	ch.location	= "Roa_Hideout";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "KR_crewmember.c";
	ch.nation = PIRATE;
	ch.rank 	= 4;
	ch.reputation = "None";
	ch.experience = "50";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "7";
	ch.skill.Accuracy = "7";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "1";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "7";
	ch.money = "1";
	ch.quest.sex = 0;
	ch.sex.time = 0;
	//LAi_SetStayType(ch);
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 60.0, 60.0);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	/*
	LAi_SetSitType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	*/

	n = FindBlankCharSlot();
	CHARACTERS_QUANTITY++; // NK 05-04-05
	makeref(ch,Characters[n]);		
	ch.old.name = "Crewmember";
	ch.old.lastname = "";
	ch.name 	= TranslateString("","Crewmember");
	ch.lastname = "";
	ch.id		= "KR_Crew4";
	ch.model	= "sailor4";
	ch.headmodel = "h_sailor4";
	ch.sound_type = "seaman";
	ch.sex = "man";
	GiveItem2Character(ch, "blade27");
	ch.equip.blade = "blade27";
	GiveItem2Character(ch, "pistol3");
	ch.equip.gun = "pistol3";
    //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolgrapes", 1 + rand(2));
	}
    //JRH ammo mod <--
	ch.location	= "Roa_Hideout";
	ch.location.group = "goto";
	ch.location.locator = "goto4";
	ch.Dialog.Filename = "KR_crewmember.c";
	ch.nation = PIRATE;
	ch.rank 	= 3;
	ch.reputation = "None";
	ch.experience = "40";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "7";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "7";
	ch.money = "1";
	ch.quest.sex = 0;
	ch.sex.time = 0;
	//LAi_SetStayType(ch);
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 60.0, 60.0);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	/*
	LAi_SetSitType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	*/
}
