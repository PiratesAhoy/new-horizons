void LocationInitAlanSmitheeLocations(ref n)
{

//++++++++++++++++++++++++++++++++++++++++++++++
//==================Conceição===================
//++++++++++++++++++++++++++++++++++++++++++++++

// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Blacksmith1";
	Locations[n].id = "Con_blacksmith";

//	locations[n].id.label = "Portuguese Gunsmith";	//JRH
	locations[n].id.label = "#stown_name# Gunsmith"; // GR: use town name rather than nation, then it works for all periods
	Locations[n].image = "Inside_Blacksmith1.tga"; // KK

	//Town sack
	Locations[n].townsack = "Conceicao";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Conceicao";
	//Models
	//Always
	Locations[n].models.always.locators = "MH_l";
	Locations[n].models.always.house = "MH";
	//Locations[n].models.always.env = "smalltavern_env";
	Locations[n].models.always.window = "MH_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	Locations[n].models.always.l1 = "sword1";
	Locations[n].models.always.l1.locator.name = "stuff1";
	Locations[n].models.always.l1.locator.group = "gm";
	Locations[n].models.always.l1.tech = "dLightModel";
	Locations[n].models.always.l2 = "sword2";
	Locations[n].models.always.l2.locator.name = "stuff2";
	Locations[n].models.always.l2.locator.group = "gm";
	Locations[n].models.always.l2.tech = "dLightModel";
	Locations[n].models.always.l4 = "sword3";
	Locations[n].models.always.l4.locator.name = "stuff3";
	Locations[n].models.always.l4.locator.group = "gm";
	Locations[n].models.always.l4.tech = "dLightModel";
	Locations[n].models.always.l5 = "gun";
	Locations[n].models.always.l5.locator.name = "stuff4";
	Locations[n].models.always.l5.locator.group = "gm";
	Locations[n].models.always.l5.tech = "dLightModel";
	Locations[n].models.always.l6 = "gun";
	Locations[n].models.always.l6.locator.name = "stuff5";
	Locations[n].models.always.l6.locator.group = "gm";
	Locations[n].models.always.l6.tech = "dLightModel";
	Locations[n].models.always.l7 = "anvil";
	Locations[n].models.always.l7.locator.name = "anvil";
	Locations[n].models.always.l7.locator.group = "gm";
	Locations[n].models.always.l7.tech = "dLightModel";
	Locations[n].models.always.l8 = "lamp";
	Locations[n].models.always.l8.locator.name = "lamp";
	Locations[n].models.always.l8.locator.group = "gm";
	Locations[n].models.always.l8.tech = "dLightModel";
	Locations[n].models.always.l3 = "cannon";
	Locations[n].models.always.l3.locator.name = "cannon";
	Locations[n].models.always.l3.locator.group = "gm";
	Locations[n].models.always.l3.tech = "dLightModel";
	
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
	Locations[n].reload.l1.go = "Conceicao_town";
	Locations[n].reload.l1.emerge = "reload6";
	
	
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Conceicao"; // NK 04-08-29
	n = n + 1;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//======================Falaise de Fleur ==========================
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	
// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Blacksmith2";

	Locations[n].id = "FdF_blacksmith";
//	locations[n].id.label = "French Blacksmith";
	locations[n].id.label = "#stown_name# BlacksmithF"; // GR: "BlacksmithF" is for a female blacksmith, necessary for translations
	Locations[n].image = "Inside_Blacksmith2.tga"; // KK

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Sound
	locations[n].type = "shop"; // PB: was "store"

	//Models
	//Always
	Locations[n].models.always.locators = "MH02_l";
	Locations[n].models.always.house = "MH02";
	//Locations[n].models.always.env = "smalltavern_env";
	Locations[n].models.always.window = "MH02_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	Locations[n].models.always.l1 = "sword1";
	Locations[n].models.always.l1.locator.name = "stuff1";
	Locations[n].models.always.l1.locator.group = "gm";
	Locations[n].models.always.l1.tech = "dLightModel";
	Locations[n].models.always.l2 = "sword2";
	Locations[n].models.always.l2.locator.name = "stuff2";
	Locations[n].models.always.l2.locator.group = "gm";
	Locations[n].models.always.l2.tech = "dLightModel";
	Locations[n].models.always.l4 = "sword3";
	Locations[n].models.always.l4.locator.name = "stuff3";
	Locations[n].models.always.l4.locator.group = "gm";
	Locations[n].models.always.l4.tech = "dLightModel";
	Locations[n].models.always.l5 = "sword4";
	Locations[n].models.always.l5.locator.name = "stuff4";
	Locations[n].models.always.l5.locator.group = "gm";
	Locations[n].models.always.l5.tech = "dLightModel";
	Locations[n].models.always.l7 = "anvil";
	Locations[n].models.always.l7.locator.name = "anvil";
	Locations[n].models.always.l7.locator.group = "gm";
	Locations[n].models.always.l7.tech = "dLightModel";
	Locations[n].models.always.l6 = "lamp";
	Locations[n].models.always.l6.locator.name = "lamp";
	Locations[n].models.always.l6.locator.group = "gm";
	Locations[n].models.always.l6.tech = "dLightModel";
	Locations[n].models.always.l3 = "cannon";
	Locations[n].models.always.l3.locator.name = "cannon";
	Locations[n].models.always.l3.locator.group = "gm";
	Locations[n].models.always.l3.tech = "dLightModel";
	//Day
	Locations[n].models.day.charactersPatch = "MH02_p";

	//Night
	Locations[n].models.night.charactersPatch = "MH02_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\smumh2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_03";
	Locations[n].reload.l1.emerge = "home1";

	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;





//++++++++++++++++++++++++++++++++++++++++++++++++++
//===============Isla Muelle========================
//++++++++++++++++++++++++++++++++++++++++++++++++++

// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Blacksmith2";

	Locations[n].id = "IM_blacksmith";
//	locations[n].id.label = "Spanish Blacksmith";
	locations[n].id.label = "#stown_name# Blacksmith"; // GR: use town name rather than nation, then it works for all periods
	Locations[n].image = "Inside_Blacksmith2.tga"; // KK


	//Town sack
	Locations[n].townsack = "Isla Muelle";
	locations[n].fastreload = "Muelle";
	//Sound
	locations[n].type = "shop"; // PB: was "store"

	//Models
	//Always
	Locations[n].models.always.locators = "MH02_l";
	Locations[n].models.always.house = "MH02";
	//Locations[n].models.always.env = "smalltavern_env";
	Locations[n].models.always.window = "MH02_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	Locations[n].models.always.l1 = "sword1";
	Locations[n].models.always.l1.locator.name = "stuff1";
	Locations[n].models.always.l1.locator.group = "gm";
	Locations[n].models.always.l1.tech = "dLightModel";
	Locations[n].models.always.l2 = "sword2";
	Locations[n].models.always.l2.locator.name = "stuff2";
	Locations[n].models.always.l2.locator.group = "gm";
	Locations[n].models.always.l2.tech = "dLightModel";
	Locations[n].models.always.l4 = "sword3";
	Locations[n].models.always.l4.locator.name = "stuff3";
	Locations[n].models.always.l4.locator.group = "gm";
	Locations[n].models.always.l4.tech = "dLightModel";
	Locations[n].models.always.l5 = "sword4";
	Locations[n].models.always.l5.locator.name = "stuff4";
	Locations[n].models.always.l5.locator.group = "gm";
	Locations[n].models.always.l5.tech = "dLightModel";
	Locations[n].models.always.l7 = "anvil";
	Locations[n].models.always.l7.locator.name = "anvil";
	Locations[n].models.always.l7.locator.group = "gm";
	Locations[n].models.always.l7.tech = "dLightModel";
	Locations[n].models.always.l6 = "lamp";
	Locations[n].models.always.l6.locator.name = "lamp";
	Locations[n].models.always.l6.locator.group = "gm";
	Locations[n].models.always.l6.tech = "dLightModel";
	Locations[n].models.always.l3 = "cannon";
	Locations[n].models.always.l3.locator.name = "cannon";
	Locations[n].models.always.l3.locator.group = "gm";
	Locations[n].models.always.l3.tech = "dLightModel";
	//Day
	Locations[n].models.day.charactersPatch = "MH02_p";

	//Night
	Locations[n].models.night.charactersPatch = "MH02_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\smumh2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Muelle_town_03";
	Locations[n].reload.l1.emerge = "reload3";

	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "IslaMuelle"; // NK 04-08-29
	n = n + 1;




//+++++++++++++++++++++++++++++++++++++++++++++++
//====================Redmond====================
//+++++++++++++++++++++++++++++++++++++++++++++++

// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Blacksmith1";
	Locations[n].id = "red_blacksmith";
	locations[n].id.label = "#stown_name# Blacksmith";
	Locations[n].image = "Inside_Blacksmith1.tga"; // KK

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Redmond";
	//Models
	//Always
	Locations[n].models.always.locators = "MH_l";
	Locations[n].models.always.house = "MH";
	//Locations[n].models.always.env = "smalltavern_env";
	Locations[n].models.always.window = "MH_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	Locations[n].models.always.l1 = "sword1";
	Locations[n].models.always.l1.locator.name = "stuff1";
	Locations[n].models.always.l1.locator.group = "gm";
	Locations[n].models.always.l1.tech = "dLightModel";
	Locations[n].models.always.l2 = "sword2";
	Locations[n].models.always.l2.locator.name = "stuff2";
	Locations[n].models.always.l2.locator.group = "gm";
	Locations[n].models.always.l2.tech = "dLightModel";
	Locations[n].models.always.l4 = "sword3";
	Locations[n].models.always.l4.locator.name = "stuff3";
	Locations[n].models.always.l4.locator.group = "gm";
	Locations[n].models.always.l4.tech = "dLightModel";
	Locations[n].models.always.l5 = "gun";
	Locations[n].models.always.l5.locator.name = "stuff4";
	Locations[n].models.always.l5.locator.group = "gm";
	Locations[n].models.always.l5.tech = "dLightModel";
	Locations[n].models.always.l6 = "gun";
	Locations[n].models.always.l6.locator.name = "stuff5";
	Locations[n].models.always.l6.locator.group = "gm";
	Locations[n].models.always.l6.tech = "dLightModel";
	Locations[n].models.always.l7 = "anvil";
	Locations[n].models.always.l7.locator.name = "anvil";
	Locations[n].models.always.l7.locator.group = "gm";
	Locations[n].models.always.l7.tech = "dLightModel";
	Locations[n].models.always.l8 = "lamp";
	Locations[n].models.always.l8.locator.name = "lamp";
	Locations[n].models.always.l8.locator.group = "gm";
	Locations[n].models.always.l8.tech = "dLightModel";
	Locations[n].models.always.l3 = "cannon";
	Locations[n].models.always.l3.locator.name = "cannon";
	Locations[n].models.always.l3.locator.group = "gm";
	Locations[n].models.always.l3.tech = "dLightModel";
	
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
	Locations[n].reload.l1.go = "Redmond_Town_01";
	Locations[n].reload.l1.emerge = "Door_4";
	
	
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

//__________________________________________________________

	Locations[n].id = "den";
	locations[n].id.label = "Opium Den";
	Locations[n].filespath.models = "locations\inside\den"; 
	Locations[n].image = "Inside_Den.tga"; // KK

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "den"; // KK
	locations[n].fastreload = "Redmond";
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
	Locations[n].reload.l1.go = "Redmond_Town_01";
	Locations[n].reload.l1.emerge = "Door_3";
	Locations[n].reload.l1.autoreload = "0";


	LAi_LocationFightDisable(&Locations[n], true); // PB: Disable fighting in Alan Smithee's Opium Parlour


	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;


//+++++++++++++++++++++++++++++++++++++++++++++++
//====================Douwesen===================
//+++++++++++++++++++++++++++++++++++++++++++++++

// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Blacksmith2";

	Locations[n].id = "Douw_blacksmith";
//	locations[n].id.label = "Dutch Blacksmith";
	locations[n].id.label = "#stown_name# Blacksmith"; // GR: use town name rather than nation, then it works for all periods
	Locations[n].image = "Inside_Blacksmith2.tga"; // KK

	//Town sack
	Locations[n].townsack = "Douwesen"; // NK 04-08-29

	//Sound
	locations[n].type = "shop"; // PB: was "store"
	locations[n].fastreload = "Douwesen";

	//Models
	//Always
	Locations[n].models.always.locators = "MH02_l";
	Locations[n].models.always.house = "MH02";
	//Locations[n].models.always.env = "smalltavern_env";
	Locations[n].models.always.window = "MH02_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	Locations[n].models.always.l1 = "sword1";
	Locations[n].models.always.l1.locator.name = "stuff1";
	Locations[n].models.always.l1.locator.group = "gm";
	Locations[n].models.always.l1.tech = "dLightModel";
	Locations[n].models.always.l2 = "sword2";
	Locations[n].models.always.l2.locator.name = "stuff2";
	Locations[n].models.always.l2.locator.group = "gm";
	Locations[n].models.always.l2.tech = "dLightModel";
	Locations[n].models.always.l4 = "sword3";
	Locations[n].models.always.l4.locator.name = "stuff3";
	Locations[n].models.always.l4.locator.group = "gm";
	Locations[n].models.always.l4.tech = "dLightModel";
	Locations[n].models.always.l5 = "sword4";
	Locations[n].models.always.l5.locator.name = "stuff4";
	Locations[n].models.always.l5.locator.group = "gm";
	Locations[n].models.always.l5.tech = "dLightModel";
	Locations[n].models.always.l7 = "anvil";
	Locations[n].models.always.l7.locator.name = "anvil";
	Locations[n].models.always.l7.locator.group = "gm";
	Locations[n].models.always.l7.tech = "dLightModel";
	Locations[n].models.always.l6 = "lamp";
	Locations[n].models.always.l6.locator.name = "lamp";
	Locations[n].models.always.l6.locator.group = "gm";
	Locations[n].models.always.l6.tech = "dLightModel";
	Locations[n].models.always.l3 = "cannon";
	Locations[n].models.always.l3.locator.name = "cannon";
	Locations[n].models.always.l3.locator.group = "gm";
	Locations[n].models.always.l3.tech = "dLightModel";
	//Day
	Locations[n].models.day.charactersPatch = "MH02_p";

	//Night
	Locations[n].models.night.charactersPatch = "MH02_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\smumh2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Douwesen_town";
	Locations[n].reload.l1.emerge = "reload7";

	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Douwesen"; // NK 04-08-29
	n = n + 1;



//++++++++++++++++++++++++++++++++++++++++++++++++++++++
//====================Quebradas Costillas===============
//++++++++++++++++++++++++++++++++++++++++++++++++++++++

// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Blacksmith1";
	Locations[n].id = "QC_blacksmith";
//	locations[n].id.label = "Pirate Blacksmith";
	locations[n].id.label = "#stown_name# Blacksmith";
	Locations[n].image = "Inside_Blacksmith1.tga"; // KK

	//Town sack
	Locations[n].townsack = "Quebradas Costillas";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "QC";
	//Models
	//Always
	Locations[n].models.always.locators = "MH_l";
	Locations[n].models.always.house = "MH";
	//Locations[n].models.always.env = "smalltavern_env";
	Locations[n].models.always.window = "MH_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	Locations[n].models.always.l1 = "sword1";
	Locations[n].models.always.l1.locator.name = "stuff1";
	Locations[n].models.always.l1.locator.group = "gm";
	Locations[n].models.always.l1.tech = "dLightModel";
	Locations[n].models.always.l2 = "sword2";
	Locations[n].models.always.l2.locator.name = "stuff2";
	Locations[n].models.always.l2.locator.group = "gm";
	Locations[n].models.always.l2.tech = "dLightModel";
	Locations[n].models.always.l4 = "sword3";
	Locations[n].models.always.l4.locator.name = "stuff3";
	Locations[n].models.always.l4.locator.group = "gm";
	Locations[n].models.always.l4.tech = "dLightModel";
	Locations[n].models.always.l5 = "gun";
	Locations[n].models.always.l5.locator.name = "stuff4";
	Locations[n].models.always.l5.locator.group = "gm";
	Locations[n].models.always.l5.tech = "dLightModel";
	Locations[n].models.always.l6 = "gun";
	Locations[n].models.always.l6.locator.name = "stuff5";
	Locations[n].models.always.l6.locator.group = "gm";
	Locations[n].models.always.l6.tech = "dLightModel";
	Locations[n].models.always.l7 = "anvil";
	Locations[n].models.always.l7.locator.name = "anvil";
	Locations[n].models.always.l7.locator.group = "gm";
	Locations[n].models.always.l7.tech = "dLightModel";
	Locations[n].models.always.l8 = "lamp";
	Locations[n].models.always.l8.locator.name = "lamp";
	Locations[n].models.always.l8.locator.group = "gm";
	Locations[n].models.always.l8.tech = "dLightModel";
	Locations[n].models.always.l3 = "cannon";
	Locations[n].models.always.l3.locator.name = "cannon";
	Locations[n].models.always.l3.locator.group = "gm";
	Locations[n].models.always.l3.tech = "dLightModel";
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
	Locations[n].reload.l1.go = "QC_town_exit";
	Locations[n].reload.l1.emerge = "reload4";
	
	
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "QuebradasCostillas"; // NK 04-08-29
	n = n + 1;



//++++++++++++++++++++++++++++++++++++++++++++++++++
//===============Oxbay/Greenford====================
//++++++++++++++++++++++++++++++++++++++++++++++++++


// Steven Mather-Wren's Apothecary -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\apothecary";	

	Locations[n].id = "apothecary";
	locations[n].id.label = "Apothecary";
	Locations[n].image = "Inside_Apothecary.tga"; // KK
	//Town sack
	Locations[n].townsack = "Greenford"; 
	//Sound
	locations[n].type = "residence"; 
	locations[n].fastreload = "Greenford";
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
	Locations[n].models.back = "back\grms_";
	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Greenford_town";
	Locations[n].reload.l1.emerge = "Reload13";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].island = "Oxbay"; // NK 04-08-29

	n = n + 1;

//++++++++++++++++++++++++++++++++++++++++++++++++++
//===============HAVANA========================
//++++++++++++++++++++++++++++++++++++++++++++++++++

// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Blacksmith2";

	Locations[n].id = "Havana_blacksmith";
//	locations[n].id.label = "Spanish Blacksmith";
	locations[n].id.label = "#stown_name# Blacksmith"; // GR: use town name rather than nation, then it works for all periods
	Locations[n].image = "Inside_Blacksmith2.tga";


	//Town sack
	Locations[n].townsack = "Havana";
	locations[n].fastreload = "Havana";
	//Sound
	locations[n].type = "shop"; // PB: was "store"

	//Models
	//Always
	Locations[n].models.always.locators = "MH02_l";
	Locations[n].models.always.house = "MH02";
	//Locations[n].models.always.env = "smalltavern_env";
	Locations[n].models.always.window = "MH02_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	Locations[n].models.always.l1 = "sword1";
	Locations[n].models.always.l1.locator.name = "stuff1";
	Locations[n].models.always.l1.locator.group = "gm";
	Locations[n].models.always.l1.tech = "dLightModel";
	Locations[n].models.always.l2 = "sword2";
	Locations[n].models.always.l2.locator.name = "stuff2";
	Locations[n].models.always.l2.locator.group = "gm";
	Locations[n].models.always.l2.tech = "dLightModel";
	Locations[n].models.always.l4 = "sword3";
	Locations[n].models.always.l4.locator.name = "stuff3";
	Locations[n].models.always.l4.locator.group = "gm";
	Locations[n].models.always.l4.tech = "dLightModel";
	Locations[n].models.always.l5 = "sword4";
	Locations[n].models.always.l5.locator.name = "stuff4";
	Locations[n].models.always.l5.locator.group = "gm";
	Locations[n].models.always.l5.tech = "dLightModel";
	Locations[n].models.always.l7 = "anvil";
	Locations[n].models.always.l7.locator.name = "anvil";
	Locations[n].models.always.l7.locator.group = "gm";
	Locations[n].models.always.l7.tech = "dLightModel";
	Locations[n].models.always.l6 = "lamp";
	Locations[n].models.always.l6.locator.name = "lamp";
	Locations[n].models.always.l6.locator.group = "gm";
	Locations[n].models.always.l6.tech = "dLightModel";
	Locations[n].models.always.l3 = "cannon";
	Locations[n].models.always.l3.locator.name = "cannon";
	Locations[n].models.always.l3.locator.group = "gm";
	Locations[n].models.always.l3.tech = "dLightModel";
	//Day
	Locations[n].models.day.charactersPatch = "MH02_p";

	//Night
	Locations[n].models.night.charactersPatch = "MH02_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\smumh2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Havana_town_02";
	Locations[n].reload.l1.emerge = "reload4";

	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Cuba"; // NK 04-08-29
	n = n + 1;

//++++++++++++++++++++++++++++++++++++++++++++++
//==================Grand Turk==================
//++++++++++++++++++++++++++++++++++++++++++++++

// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Blacksmith1";
	Locations[n].id = "Turks_blacksmith";
	//if (GetAttribute(Pchar, "Turks") == Brotherhood){locations[n].id.label = "Pirates Ahoy! Blacksmith";}
//	locations[n].id.label = "Pirate Gun- and Blacksmith";		//JRH
	locations[n].id.label = "#stown_name# Gun- and Blacksmith";	// GR: use town name rather than nation, then it works in all periods
	Locations[n].image = "Inside_Blacksmith1.tga"; // KK

	//Town sack
	Locations[n].townsack = "Grand Turk";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Grand_Turk";
	//Models
	//Always
	Locations[n].models.always.locators = "MH_l";
	Locations[n].models.always.house = "MH";
	//Locations[n].models.always.env = "smalltavern_env";
	Locations[n].models.always.window = "MH_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	Locations[n].models.always.l1 = "sword1";
	Locations[n].models.always.l1.locator.name = "stuff1";
	Locations[n].models.always.l1.locator.group = "gm";
	Locations[n].models.always.l1.tech = "dLightModel";
	Locations[n].models.always.l2 = "sword2";
	Locations[n].models.always.l2.locator.name = "stuff2";
	Locations[n].models.always.l2.locator.group = "gm";
	Locations[n].models.always.l2.tech = "dLightModel";
	Locations[n].models.always.l4 = "sword3";
	Locations[n].models.always.l4.locator.name = "stuff3";
	Locations[n].models.always.l4.locator.group = "gm";
	Locations[n].models.always.l4.tech = "dLightModel";
	Locations[n].models.always.l5 = "gun";
	Locations[n].models.always.l5.locator.name = "stuff4";
	Locations[n].models.always.l5.locator.group = "gm";
	Locations[n].models.always.l5.tech = "dLightModel";
	Locations[n].models.always.l6 = "gun";
	Locations[n].models.always.l6.locator.name = "stuff5";
	Locations[n].models.always.l6.locator.group = "gm";
	Locations[n].models.always.l6.tech = "dLightModel";
	Locations[n].models.always.l7 = "anvil";
	Locations[n].models.always.l7.locator.name = "anvil";
	Locations[n].models.always.l7.locator.group = "gm";
	Locations[n].models.always.l7.tech = "dLightModel";
	Locations[n].models.always.l8 = "lamp";
	Locations[n].models.always.l8.locator.name = "lamp";
	Locations[n].models.always.l8.locator.group = "gm";
	Locations[n].models.always.l8.tech = "dLightModel";
	Locations[n].models.always.l3 = "cannon";
	Locations[n].models.always.l3.locator.name = "cannon";
	Locations[n].models.always.l3.locator.group = "gm";
	Locations[n].models.always.l3.tech = "dLightModel";
	
	//Day
	Locations[n].models.day.charactersPatch = "MH_p";

	//Night
	Locations[n].models.night.charactersPatch = "MH_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\shp_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Turks_port";
	Locations[n].reload.l1.emerge = "houseSp3";
	
	
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Turks"; // NK 04-08-29
	n = n + 1;

/* Duplicate entry?
//++++++++++++++++++++++++++++++++++++++++++++++++++
//===============Oxbay/Greenford====================
//++++++++++++++++++++++++++++++++++++++++++++++++++


// Steven Mather-Wren's Apothecary -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\apothecary";	

	Locations[n].id = "apothecary";
	locations[n].id.label = "Apothecary";
	Locations[n].image = "Inside_Apothecary.tga"; // KK
	//Town sack
	Locations[n].townsack = "Greenford"; 
	//Sound
	locations[n].type = "residence"; 
	locations[n].fastreload = "Greenford";
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
	Locations[n].models.back = "back\grms_";
	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Greenford_town";
	Locations[n].reload.l1.emerge = "Reload13";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].island = "Oxbay"; // NK 04-08-29

	n = n + 1;
	
*/
//++++++++++++++++++++++++++++++++++++++++++++++++++
//===============Cartagena========================
//++++++++++++++++++++++++++++++++++++++++++++++++++

// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Blacksmith2";

	Locations[n].id = "Cartagena_blacksmith";
//	locations[n].id.label = "Spanish Blacksmith";
	locations[n].id.label = "#stown_name# Blacksmith"; // GR: use town name rather than nation, then it works for all periods
	Locations[n].image = "Inside_Blacksmith2.tga"; // KK


	//Town sack
	Locations[n].townsack = "Cartagena";
	locations[n].fastreload = "Cartagena";
	//Sound
	locations[n].type = "shop"; // PB: was "store"

	//Models
	//Always
	Locations[n].models.always.locators = "MH02_l";
	Locations[n].models.always.house = "MH02";
	//Locations[n].models.always.env = "smalltavern_env";
	Locations[n].models.always.window = "MH02_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	Locations[n].models.always.l1 = "sword1";
	Locations[n].models.always.l1.locator.name = "stuff1";
	Locations[n].models.always.l1.locator.group = "gm";
	Locations[n].models.always.l1.tech = "dLightModel";
	Locations[n].models.always.l2 = "sword2";
	Locations[n].models.always.l2.locator.name = "stuff2";
	Locations[n].models.always.l2.locator.group = "gm";
	Locations[n].models.always.l2.tech = "dLightModel";
	Locations[n].models.always.l4 = "sword3";
	Locations[n].models.always.l4.locator.name = "stuff3";
	Locations[n].models.always.l4.locator.group = "gm";
	Locations[n].models.always.l4.tech = "dLightModel";
	Locations[n].models.always.l5 = "sword4";
	Locations[n].models.always.l5.locator.name = "stuff4";
	Locations[n].models.always.l5.locator.group = "gm";
	Locations[n].models.always.l5.tech = "dLightModel";
	Locations[n].models.always.l7 = "anvil";
	Locations[n].models.always.l7.locator.name = "anvil";
	Locations[n].models.always.l7.locator.group = "gm";
	Locations[n].models.always.l7.tech = "dLightModel";
	Locations[n].models.always.l6 = "lamp";
	Locations[n].models.always.l6.locator.name = "lamp";
	Locations[n].models.always.l6.locator.group = "gm";
	Locations[n].models.always.l6.tech = "dLightModel";
	Locations[n].models.always.l3 = "cannon";
	Locations[n].models.always.l3.locator.name = "cannon";
	Locations[n].models.always.l3.locator.group = "gm";
	Locations[n].models.always.l3.tech = "dLightModel";
	//Day
	Locations[n].models.day.charactersPatch = "MH02_p";

	//Night
	Locations[n].models.night.charactersPatch = "MH02_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\smumh2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Cartagena_Center";
	Locations[n].reload.l1.emerge = "reload8";

	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Colombia"; // NK 04-08-29
	n = n + 1;	
}
