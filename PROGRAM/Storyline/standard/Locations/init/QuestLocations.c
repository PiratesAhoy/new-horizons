void LocationInitQuestLocations(ref n)
{
	Locations[n].id = "Quest_redmond_tavern";
	locations[n].id.label = "#stown_name# tavern";
	Locations[n].filespath.models = "locations\inside\Largetavern";
	Locations[n].image = "Inside_LargeTavern.tga";

	//Town sack
	Locations[n].townsack = "Redmond"; // NK 04-08-29
	Locations[n].island = "Redmond"; // NK 04-08-29

	//Sound
	locations[n].type = "tavern";
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

	Locations[n].island = "Redmond";
	n = n + 1; 


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_IslaMuelle\town_01";
	Locations[n].image = "Town_IslaMuelle_Town_01.tga";

	Locations[n].id = "Quest_Muelle_town_01";
	locations[n].id.label = "#stown_name#";

	//Town sack
	Locations[n].townsack = "Isla Muelle"; // NK 04-08-29
	Locations[n].island = "IslaMuelle"; // NK 04-08-29

	//Sound
	locations[n].type = "town";
	//Models
	//Always
	Locations[n].models.always.l1 = "Mu01";
	Locations[n].models.always.locators = "Mu01_l";
	Locations[n].models.always.grassPatch = "Mu01_g";
	//Day
	Locations[n].models.day.rinok = "Mu01_e1";
	Locations[n].models.day.fonar = "Mu01_fd";
	Locations[n].models.day.jumppatch = "Mu01_j";
	Locations[n].models.day.charactersPatch = "Mu01_pd";
	//Night
	Locations[n].models.night.fonar = "Mu01_fn";
	Locations[n].models.night.charactersPatch = "Mu01_pn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	Locations[n].island = "IslaMuelle";
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "Quest_Residence";
	locations[n].id.label = "Redmond Townhall. Silehards's Bedroom";
	Locations[n].filespath.models = "locations\inside\ResBedRoom";
	Locations[n].image = "Inside_ResBedRoom.tga";

	//Town sack
	Locations[n].townsack = "Redmond"; // NK 04-08-29
	Locations[n].island = "Redmond"; // NK 04-08-29

	//Sound
	locations[n].type = "residence";
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
	Locations[n].reload.l1.go = "Redmond_Town_01";
	Locations[n].reload.l1.emerge = "door_5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Redmond. Center.";

	Locations[n].island = "Redmond";
	n = n + 1;

// KK -->
	// -------------------------------------------------
	// ------------------------------Fake Greenford fort
	Locations[n].id = "Fake_Greenford_fort";
	locations[n].id.label = "Fort inside";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_1";
	Locations[n].image = "Fort_Inside_Fort_1.tga";
	//Sound
	locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "fort1_l";
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
	Locations[n].boarding = "fort";
	Locations[n].boarding.nextdeck = "NEXT1_Fake_Greenford_fort";

	Locations[n].island = "Oxbay";
	n = n + 1;

	//ID
	Locations[n].id = "NEXT1_Fake_Greenford_fort";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_2";
	Locations[n].image = "Fort_Inside_Fort_2.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "fort2_l";
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
	Locations[n].boarding = "fort";
	Locations[n].boarding.nextdeck = "NEXT2_Fake_Greenford_fort";

	Locations[n].island = "Oxbay";
	n = n + 1;

	//ID
	Locations[n].id = "NEXT2_Fake_Greenford_fort";
	Locations[n].id.label = "Boarding deck";
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_3";
	Locations[n].image = "Fort_Inside_Fort_3.tga";
	//Sound
	Locations[n].type = "deck";

	//Models
	//Always
	Locations[n].models.always.locators = "fort3_l";
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
	Locations[n].boarding = "fort";
	Locations[n].boarding.nextdeck = "";

	Locations[n].island = "Oxbay";
	n = n + 1;
// <-- KK

	//  -------------------------------------------------
	Locations[n].filespath.models = "locations\town_Greenford\port";	
	Locations[n].image = "Town_Greenford_Port.tga";

	Locations[n].id = "Fake_Greenford_port";
	locations[n].id.label = "#stown_name# port";

	//Town sack
	// 04-12-14 disable this, this borks MQ - Locations[n].townsack = "Greenford"; // NK 04-08-29
	Locations[n].island = "Oxbay"; // NK 04-08-29

	//Sound
	locations[n].type = "port";
	//Models
	//Always
	Locations[n].models.always.locators = "GrPort_l";
	Locations[n].models.always.l1 = "GrPort";
	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.seabed = "GrPort_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "GrPort_g";
	//Day
	Locations[n].models.day.charactersPatch = "GrPort_p";
	Locations[n].models.day.fonar = "GrPort_fd";
	//Night
	Locations[n].models.night.charactersPatch = "GrPort_p";
	Locations[n].models.night.fonar= "GrPort_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reload4";
	Locations[n].reload.l2.go = "";
	Locations[n].reload.l2.emerge = "";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].island = "Oxbay";
	n = n + 1;


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_Greenford\town";
	Locations[n].image = "Town_Greenford_Town.tga";

	Locations[n].id = "Fake_Greenford_town";
	locations[n].id.label = "#stown_name#";

	//Town sack
	// 04-12-14 disable this, this borks MQ - Locations[n].townsack = "Greenford"; // NK 04-08-29
	Locations[n].island = "Oxbay"; // NK 04-08-29

	//Sound
	locations[n].type = "town";
	//Models
	//Always
	Locations[n].models.always.locators = "GrTown_l";
	Locations[n].models.always.l1 = "GrTown";
	Locations[n].models.always.grassPatch = "GrTown_g";
	//Day
	Locations[n].models.day.rinok = "GrTown_e01";
	Locations[n].models.day.fonar = "GrTown_fd";
	Locations[n].models.day.charactersPatch = "GrTown_pd";
	//Night
	Locations[n].models.night.fonar = "GrTown_fn";
	Locations[n].models.night.charactersPatch = "GrTown_pn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map

	Locations[n].island = "Oxbay";
	n = n + 1;

//---------------------------------------------------------------------------


	Locations[n].id = "Fake_Greenford_prison";
	locations[n].id.label = "#stown_name# prison";
	Locations[n].filespath.models = "locations\inside\prison";

	//Town sack
	// 04-12-14 disable this, this borks MQ - Locations[n].townsack = "Greenford"; // NK 04-08-29
	Locations[n].island = "Oxbay"; // NK 04-08-29
	
	//Sound
	locations[n].type = "jail";
	Locations[n].image = "Inside_Prison.tga";
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
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].island = "Oxbay";
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Decks\qdeck";
	Locations[n].image = "sea.tga";

	Locations[n].id = "Ship_deck";
	locations[n].id.label = "Pirate bark";
	//Sound
	locations[n].type = "deck";
	//Models
	//Always
	Locations[n].models.always.locators = "qdeck_l";
	Locations[n].models.always.l1 = "qdeck";
	//Day
	Locations[n].models.day.charactersPatch = "qdeck_p";
	//Night
	Locations[n].models.night.charactersPatch = "qdeck_p";
	Locations[n].lockCamAngle = 0.4;
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.disable = 1;
	Locations[n].reload.l1.emerge = "reload2";
	n = n + 1;
}
