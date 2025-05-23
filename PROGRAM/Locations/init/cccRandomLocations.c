void LocationInitCCCRandomLocations(ref n)
{

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\pirateresidence";	

	Locations[n].id = "Randomhouse0";
	Locations[n].randloc = 1;
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

	n = n + 1;

	// ------------------------------------------
	
	Locations[n].filespath.models = "locations\Inside\Pirate_House";	

	Locations[n].id = "Randomhouse1";
	Locations[n].randloc = 1;
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

	n = n + 1; 



	// -------------------------------------------------

	Locations[n].id = "Randomhouse2";
	Locations[n].randloc = 1;
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

	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Randomhouse3";
	Locations[n].randloc = 1;
	locations[n].id.label = "Mansion";
	Locations[n].filespath.models = "locations\inside\Residence_BackHall";
	Locations[n].image = "Inside_Residence_BackHall";

	//Sound
	locations[n].type = "house";
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

	n = n + 1;

	// ccc study -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Residence3";

	Locations[n].id = "Randomhouse4";
	Locations[n].randloc = 1;
	locations[n].id.label = "Study";			
	Locations[n].image = "Inside_Residence3";

	//Sound
	locations[n].type = "house";
	//Models
	//Always
	Locations[n].models.always.locators = "Res03_l";
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
	Locations[n].models.back = "back\mures3_";

	n = n + 1;

	//  ccc bedroom -------------------------------------------------
	Locations[n].id = "Randomhouse5";
	Locations[n].randloc = 1;
	locations[n].id.label = "Bedroom";
	Locations[n].filespath.models = "locations\inside\ResBedRoom";
	Locations[n].image = "Inside_ResBedRoom";
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

	n = n + 1;




	// ccc armory-------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\LargeStore";
	Locations[n].id = "Randomhouse6";
	Locations[n].randloc = 1;
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";
	Locations[n].image = "Fort_Inside_Fort_2";


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

	n = n + 1;

 
	// ccc warehouse -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\shipyard";

	Locations[n].id = "Randomhouse7";
	Locations[n].randloc = 1;
	locations[n].id.label = "Warehouse";
	Locations[n].image = "Inside_Shipyard_Warehouse";
 
	//Sound
	locations[n].type = "house";
 
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
 
	n = n + 1;


//  -------------------------------------------------
	Locations[n].id = "Randomhouse8";
	Locations[n].randloc = 1;
	locations[n].id.label = "House";
	Locations[n].image = "Inside_Residence2";
	Locations[n].filespath.models = "locations\inside\Residence2";
 
	//Sound
	locations[n].type = "house";
 
	//Models
	//Always
	Locations[n].models.always.city = "Res02";
	Locations[n].models.always.locators = "Res02_l_ccc";
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
 
	n = n + 1;

 
//___________________________________________________________________

	Locations[n].id = "Randomhouse9";
	Locations[n].randloc = 1;
	locations[n].id.label = "Undercroft";
	Locations[n].filespath.models = "locations\inside\Dungeon_2";
	Locations[n].image = "";
	Locations[n].map = "mapRedmond_Dungeon";
 
	//Sound
	locations[n].type = "dungeon";
 	//Models
	//Always
	Locations[n].models.always.locators = "d02_l_ccc";
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
 
	LAi_LocationFantomsGen(&locations[n], true);
 
	n = n + 1;
	

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_IslaMuelle\town_02";

	Locations[n].id = "Randomhouse10";
	Locations[n].randloc = 1;
	locations[n].id.label = "Yard";
	Locations[n].image = "Town_IslaMuelle_Town_02";

	//Sound
	locations[n].type = "house";

	//Models
	//Always
	Locations[n].models.always.locators = "Mu02_l";
	Locations[n].models.always.l1 = "Mu02";
	Locations[n].models.always.grassPatch = "Mu02_g";
	//Day
	Locations[n].models.day.charactersPatch = "Mu02_p";
	Locations[n].models.day.jumpPatch = "Mu02_j";
	Locations[n].models.day.fonar = "Mu02_fd";
	//Night
	Locations[n].models.night.charactersPatch = "Mu02_p";
	Locations[n].models.night.fonar = "Mu02_fn";
	Locations[n].models.night.jumpPatch = "Mu02_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	n = n + 1;

	// 06 -------------------------------------------------
	Locations[n].id = "Randomhouse11";
	Locations[n].randloc = 1;
	locations[n].id.label = "Study";
	Locations[n].filespath.models = "locations\inside\Residence1";
	Locations[n].image = "Inside_Residence1";

	//Sound
	locations[n].type = "house";
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

	n = n + 1;


	// Tradepost -------------------------------------------------

	Locations[n].id = "Randomhouse12";
	Locations[n].randloc = 1;
	locations[n].id.label = "Tradepost";

	//Sound
	locations[n].type = "house";	// leave house for VC !!

	Locations[n].filespath.models = "locations\Inside\MediumStore";
	Locations[n].image = "Inside_MediumStore";

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
	Locations[n].models.back = "back\coms_";

	n = n + 1;


	// Inn -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\LargeTavern";

	Locations[n].id = "Randomhouse13";
	Locations[n].randloc = 1;
	locations[n].id.label = "Inn";
	Locations[n].image = "Inside_LargeTavern";

	//Sound
	locations[n].type = "house";	// leave house for VC !!
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

	n = n + 1;
}

