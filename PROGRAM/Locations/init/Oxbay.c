void LocationInitOxbay(ref n)
{

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_Oxbay\port";
	Locations[n].filespath.textures = "locations\ENGLAND";
	Locations[n].image = "Town_Oxbay_Port";

	Locations[n].id = "Oxbay_port";
	locations[n].id.label = "#stown_name# port.";
	locations[n].worldmap = "Oxbay";

	//Town sack
	Locations[n].townsack = "Oxbay";

	//Sound
	locations[n].type = "port";
	locations[n].fastreload = "Oxbay";
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	Locations[n].models.always.locators = "OXport_l";
	Locations[n].models.always.l1 = "OXport";
	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.l2 = "OXport_sb";
	Locations[n].models.always.l2.foam = "1";
	Locations[n].models.always.grassPatch = "OXport_g";
	//Day
	Locations[n].models.day.fonar = "OXport_fd";
	Locations[n].models.day.charactersPatch = "OXport_pd";
	Locations[n].models.day.rinok = "OXport_e1";
	Locations[n].models.day.jumpPatch = "OXport_j";
	//Night
	Locations[n].models.night.fonar = "OXport_fn";
	Locations[n].models.night.charactersPatch = "OXport_pn";
	Locations[n].models.night.jumpPatch = "OXport_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_town";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#sisland_name#.";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Oxbay";
	Locations[n].reload.l3.emerge = "reload_2";
	Locations[n].reload.l3.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l3.label = "Ship.";
	else
		Locations[n].reload.l3.label = "Sea.";

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Oxbay";
	Locations[n].reload.l2.emerge = "reload_2";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.reload2_back = 3; // KK

	Locations[n].reload.l4.name = "reload3";
	Locations[n].reload.l4.go = "Dungeon 1";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Cave.";
	Locations[n].locators_radius.reload.reload3 = 3; // KK



	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_Oxbay\town";
	Locations[n].filespath.textures = "locations\ENGLAND";
	Locations[n].image = "Town_Oxbay_Town";

	Locations[n].id = "Oxbay_town";
	locations[n].id.label = "#stown_name#";
	locations[n].worldmap = "Oxbay";

	//Town sack
	Locations[n].townsack = "Oxbay";

	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "Oxbay";
	LAi_LocationFantomsGen(&locations[n], true);
	// NK -->
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 0, 24);
	// NK <--
	//Models
	//Always
	Locations[n].models.always.locators = "OXtown_l";
	Locations[n].models.always.grassPatch = "OXtown_g";
	Locations[n].models.always.town = "OXtown";
	Locations[n].models.always.l1 = "oxtown_b04";
	Locations[n].models.always.l1.level = 6;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	//Day
	Locations[n].models.day.fonar = "OXtown_fd";
	Locations[n].models.day.charactersPatch = "OXtown_pd";
	Locations[n].models.day.jumpPatch = "OXtown_j";
	Locations[n].models.day.rinok = "OXtown_e1";
	//Night
	Locations[n].models.night.fonar = "OXtown_fn";
	Locations[n].models.night.charactersPatch = "OXtown_pn";
	Locations[n].models.night.jumpPatch = "OXtown_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_port";
	Locations[n].reload.l1.emerge = "Reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Sea port.";

	Locations[n].reload.l2.name = "reload7";
	Locations[n].reload.l2.go = "Oxbay_HouseInsideR7";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "House.";

	Locations[n].reload.l3.name = "reload5";
	Locations[n].reload.l3.go = "Oxbay_HouseInsideR5";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "House.";

// ccc new door at corner opposite shipyard, leads to loanshark
	Locations[n].reload.l4.name = "reload6";		// new .lxx. number and reload locator
	Locations[n].reload.l4.go = "Oxbay_UsurerHouse";	// leads to Loanshark
	Locations[n].reload.l4.emerge = "reload2";		// reload2 is upstairs
	Locations[n].reload.l4.autoreload = "0";		
	Locations[n].reload.l4.label = "Loanshark's backdoor.";		// just eyecandy
	Locations[n].reload.l4.close_for_night = 1; // KK
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l4.goto_disable = 1; // Screwface: Disable Go-To location

// ccc pitfall to dungeon right of portgate
if ( CCC_PITFALLS > 0 ) // TIH proper toggle
{
	Locations[n].reload.l5.name = "reload11";
	Locations[n].reload.l5.go = "Dungeon 1";
	Locations[n].reload.l5.emerge = "reload2";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Pitfall!!!!.";
	Locations[n].locators_radius.reload.reload11 = makefloat(CCC_PITFALLS);
}
	Locations[n].reload.l6.name = "reload9";
	Locations[n].reload.l6.go = "Oxbay_TailorsShop";
	Locations[n].reload.l6.emerge = "locator2";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Tailor's Shop.";
	Locations[n].reload.l6.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l6.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l7.name = "reload8";
	Locations[n].reload.l7.go = "Oxbay_HouseInsideR8";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "House.";

	Locations[n].reload.l8.name = "reload17";
	Locations[n].reload.l8.go = "Oxbay_HouseInsideR17";
	Locations[n].reload.l8.emerge = "reload1";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "House.";

	//ccc locator changed to lead to new suburb
	Locations[n].reload.l9.name = "reload12";
	Locations[n].reload.l9.go = "Oxbay_suburb";	//now leading to new suburb
	Locations[n].reload.l9.emerge = "Falaise_de_fleur_location_02_03";	//to this lctr
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "Town.";		//change

	Locations[n].reload.l10.name = "reload15";
	Locations[n].reload.l10.go = "Oxbay_store";
	Locations[n].reload.l10.emerge = "locator2";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "Store.";
	Locations[n].reload.l10.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l10.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l11.name = "reload13";
	Locations[n].reload.l11.go = "Oxbay_tavern";
	Locations[n].reload.l11.emerge = "reload1";
	Locations[n].reload.l11.autoreload = "0";
	Locations[n].reload.l11.label = "Tavern.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l11.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l12.name = "reload18";
	Locations[n].reload.l12.go = "Oxbay_UsurerHouse";
	Locations[n].reload.l12.emerge = "reload1";
	Locations[n].reload.l12.autoreload = "0";
	Locations[n].reload.l12.label = "Loanshark's Office.";
	Locations[n].reload.l12.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l12.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l13.name = "reload3";
	Locations[n].reload.l13.go = "Oxbay_Shipyard";
	Locations[n].reload.l13.emerge = "reload1";
	Locations[n].reload.l13.autoreload = "0";
	Locations[n].reload.l13.label = "Shipyard.";
	Locations[n].reload.l13.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l13.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l14.name = "reload19";
	Locations[n].reload.l14.go = "Dungeon 1";
	Locations[n].reload.l14.emerge = "reload1";
	Locations[n].reload.l14.autoreload = "0";
	Locations[n].reload.l14.label = "Underworld.";
	Locations[n].reload.l14.close_for_night = 0;

	Locations[n].reload.l15.name = "reload4";
	Locations[n].reload.l15.go = "Mings_townhall";
	Locations[n].reload.l15.emerge = "reload1";
	Locations[n].reload.l15.autoreload = "0";
	Locations[n].reload.l15.label = "House";
	Locations[n].reload.l15.close_for_night = 0;
	Locations[n].reload.l15.disable = 1;

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;
	
	
	Locations[n].id = "Oxbay_town_center";
	locations[n].id.label = "#stown_name#";
	locations[n].worldmap = "Oxbay";
	Locations[n].image = "Town_FalaiseDeFleur_Town_02";

	//Town sack
	Locations[n].townsack = "oxbay";

	//Sound
	locations[n].type = "town";
	LAi_LocationFantomsGen(&locations[n], true);
	locations[n].fastreload = "oxbay";
	//Models
	//Always
	Locations[n].filespath.models = "locations\Town_FalaiseDeFleur\town_02";
	Locations[n].filespath.textures = "locations\ENGLAND";
	Locations[n].models.always.locators = "FF02_l";
	Locations[n].models.always.grassPatch = "FF02_g";
	Locations[n].models.always.city = "FF02";
		//Day
	Locations[n].models.day.fonar = "FF02_fd";
	Locations[n].models.day.charactersPatch = "FF02_pd";
	Locations[n].models.day.jumppatch = "FF02_j";
	Locations[n].models.day.rinok = "FF02_e01";
	//Night
	Locations[n].models.night.fonar = "FF02_fn";
	Locations[n].models.night.charactersPatch = "FF02_pn";
	Locations[n].models.night.jumppatch = "FF02_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "Falaise_de_fleur_location_03_02";
	Locations[n].reload.l1.go = "Oxbay_Near_Plantation";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Slums.";

	Locations[n].reload.l2.name = "Falaise_de_fleur_location_03_04";
	Locations[n].reload.l2.go = "Falaise_de_fleur_location_04";
	Locations[n].reload.l2.emerge = "Falaise_de_fleur_location_04_03";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name#.";

	Locations[n].reload.l3.name = "Falaise_de_fleur_townhall";
	Locations[n].reload.l3.go = "Oxbay_townhall";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Residence.";
	Locations[n].reload.l3.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l3.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l4.name = "Falaise_de_fleur_tavern";
	Locations[n].reload.l4.go = "Oxbay_mansion_hall";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Tavern.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l4.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l5.name = "Falaise_de_fleur_shipyard";
	Locations[n].reload.l5.go = "Oxbayhouse1";
	Locations[n].reload.l5.emerge = "locator2";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Shipyard.";

	Locations[n].reload.l6.name = "Falause_de_fleur_smuggler";
	Locations[n].reload.l6.go = "Oxbayhouse2";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "House.";

	locations[n].reload.l7.name = "home5";
	Locations[n].reload.l7.go = "Oxbay_church";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Church.";
	Locations[n].reload.l7.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l7.goto_disable = 1; // Screwface: Disable Go-To location

	locations[n].reload.l8.name = "home3";
	Locations[n].reload.l8.go = "Oxbay_Brothel";
	Locations[n].reload.l8.emerge = "reload1";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "Loanshark's Office.";
	Locations[n].reload.l8.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l8.goto_disable = 1; // Screwface: Disable Go-To location

	locations[n].reload.l9.name = "home6";
	Locations[n].reload.l9.go = "Oxbayhouse3";
	Locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "House.";

	locations[n].reload.l10.name = "home2";
	Locations[n].reload.l10.go = "";
	Locations[n].reload.l10.emerge = "reload1";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "House.";
	Locations[n].reload.l10.close_for_night = 1;

		locations[n].reload.l11.name = "home1";
		Locations[n].reload.l11.go = "FdF_blacksmith";
		Locations[n].reload.l11.emerge = "reload1";
		Locations[n].reload.l11.close_for_night = 1;
		Locations[n].reload.l11.autoreload = "0";
		Locations[n].reload.l11.label = "Smithy";

	Locations[n].reload.l12.name = "home7";
	Locations[n].reload.l12.go = "Ransom_house_f1";
	Locations[n].reload.l12.emerge = "reload1";
	Locations[n].reload.l12.autoreload = "0";
	Locations[n].reload.l12.label = "House.";
	Locations[n].reload.l12.close_for_night = 0;

	Locations[n].island = "oxbay"; // NK 04-08-29
	n = n + 1;

 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// РЕЗИДЕНЦИЯ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Oxbay_townhall";
	locations[n].id.label = "Townhall";
	locations[n].filespath.models = "locations\inside\ResidenceA01";
	locations[n].image = "Inside_ResidencA1.tga";
	//Town sack
	locations[n].townsack = "Oxbay";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Oxbay";
	locations[n].island = "Oxbay";
	// стража
	locations[n].soldiers = true;
	LAi_LocationFantomsGen(&locations[n], true);
	//Models
	//Always
	locations[n].models.always.locators = "Residence01_locators";
	locations[n].models.always.l1 = "Residence01";
	locations[n].models.always.l1.level = 65538;
	locations[n].models.always.window = "residence01_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;	
Locations[n].models.back = "..\back\inside_back_";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Residence01_patch";
	//Night
	locations[n].models.night.charactersPatch = "Residence01_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Oxbay_town_center";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Oxbay_Res_Room_1";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Room";

	locations[n].reload.l3.name = "reload3"; //кабинет направо от входа
	locations[n].reload.l3.go = "Oxbay_TownhallRoom";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "TownhallRoom";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Oxbay_TownhallRoom"; //кабинет со спальней и выходом в город сбоку
	locations[n].id.label = "TownhallRoom";
	locations[n].image = "loading\inside\BigHouseBack.tga";
	//Town sack
	locations[n].townsack = "Oxbay";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Oxbay";
	locations[n].island = "Oxbay";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\BigHouseBack";
	locations[n].models.always.house = "BigHouseBack";
	locations[n].models.always.house.level = 65538;
	locations[n].models.always.window = "BigHouseBack_windows";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;

Locations[n].models.back = "..\back\inside_back_";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "BigHouseBack_patch";
	locations[n].models.day.locators = "BigHouseBack_locators";
	//Night
	locations[n].models.night.charactersPatch = "BigHouseBack_patch";
	locations[n].models.night.locators = "BigHouseBack_Nlocators";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Oxbay_townhall";
	locations[n].reload.l1.emerge = "reload3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Townhall";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Oxbay_Res_Room_2";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "BedRoom";

	locations[n].reload.l3.name = "reload3";
	locations[n].reload.l3.go = "Oxbay_town";
	locations[n].reload.l3.emerge = "reloadR1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Street";
	locations[n].locators_radius.item.item1 = 1.0;
	n = n + 1;
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Oxbay_Res_Room_1";
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\BigHouse04.tga";
	locations[n].townsack = "Oxbay";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Oxbay";
	locations[n].island = "Oxbay";
	//Always
	locations[n].filespath.models = "locations\Inside\BigHouse04";
	locations[n].models.always.house = "BigHouse04";
	locations[n].models.always.house.level = 65538;
	locations[n].models.always.window = "BigHouse04_windows";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;

Locations[n].models.back = "..\back\inside_back_";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "BigHouse04_patch";
	locations[n].models.day.locators = "BigHouse04_locators";
	//Night
	locations[n].models.night.charactersPatch = "BigHouse04_patch";
	locations[n].models.night.locators = "BigHouse04_Nlocators";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Oxbay_townhall";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "";
	n = n + 1;


 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Bedroom
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Oxbay_Res_Room_2";
	locations[n].id.label = "Bedroom";
	locations[n].image = "loading\inside\Bedroom.tga";
	//Town sack
locations[n].townsack = "Oxbay";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Oxbay";
	locations[n].island = "Oxbay";
	//Always
	locations[n].filespath.models = "locations\inside\bedRoom1";
	locations[n].models.always.bedRoom1 = "bedRoom1";
	locations[n].models.always.bedRoom1.level = 65538;
	Locations[n].models.always.bedRoom1windows = "BedRoom1_windows";
	Locations[n].models.always.bedRoom1windows.tech = "LocationWindows";
	locations[n].models.always.bedRoom1windows.level = 65539;
Locations[n].models.back = "..\back\inside_back_";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.locators = "bedRoom1_locators";
	Locations[n].models.day.bedRoom1rand = "bedRoom1_rand";
	locations[n].models.day.charactersPatch = "bedRoom1_patch";
	//Night
	locations[n].models.night.locators = "bedRoom1_Nlocators";
	locations[n].models.night.charactersPatch = "bedRoom1_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Oxbay_TownhallRoom";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Room";
	n = n + 1;


	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// БОРДЕЛЬ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Oxbay_Brothel";
	locations[n].id.label = "Brothel";
	locations[n].filespath.models = "locations\inside\Brothel";
	locations[n].image = "loading\inside\brothell_hall.tga";
	//Town sack
	locations[n].townsack = "Oxbay";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "brothel";
	locations[n].fastreload = "Oxbay";
	locations[n].island = "Oxbay";
	locations[n].brothel = true;	
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
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Oxbay_town_center";
	locations[n].reload.l1.emerge = "home3";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	
	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Oxbay_Brothel_room";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Brothel Room";
	locations[n].reload.l2.disable = 1;  //закроем, но связка пусть будет для квестов.

	locations[n].reload.l3.name = "reload1_back";
	locations[n].reload.l3.go = "Oxbay_SecBrRoom";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "Brothel";
   	Locations[n].permanent_mom = true; // GR: needed so that LEnc_monsters.c does not spawn random mistress
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Комнаты в борделе
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Oxbay_Brothel_room";
	locations[n].id.label = "Brothel Room";
	locations[n].filespath.models = "locations\inside\Brothel_room";
	locations[n].image = "loading\inside\brothell_room.tga";
	//Town sack
	locations[n].townsack = "Oxbay";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "room";
	locations[n].fastreload = "Oxbay";
	locations[n].island = "Oxbay";
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
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Oxbay_brothel";
	locations[n].reload.l1.emerge = "reload2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Brothel";
	LAi_LocationFightDisable(&locations[n], true);
	locations[n].locators_radius.item.item1 = 1;
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Oxbay_SecBrRoom"; // вторая комната борделя
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\BigHouse03.tga";
 	//Town sack
	locations[n].townsack = "Oxbay";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "room";
	locations[n].fastreload = "Oxbay";
	locations[n].island = "Oxbay";
	locations[n].brothel = true;	
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\BigHouse03";
	locations[n].models.always.house = "BigHouse03";
	locations[n].models.always.house.level = 65538;
	locations[n].models.always.window = "BigHouse03_windows";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;

Locations[n].models.back = "..\back\inside_back_";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "BigHouse03_patch";
	locations[n].models.day.locators = "BigHouse03_locators";
	//Night
	locations[n].models.night.charactersPatch = "BigHouse03_patch";
	locations[n].models.night.locators = "BigHouse03_Nlocators";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Oxbay_Brothel";
	locations[n].reload.l1.emerge = "reload1_back";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Brothel";

	locations[n].reload.l2.name = "reload2";
	locations[n].reload.l2.go = "Oxbay_town";
	locations[n].reload.l2.emerge = "reload91";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ЦЕРКОВЬ
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Oxbay_church";
	locations[n].filespath.models = "locations\inside\Church01";
	locations[n].id.label = "Church";
	locations[n].image = "loading\inside\church.tga";
	//Town sack
	locations[n].townsack = "Oxbay";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "Oxbay";
	locations[n].island = "Oxbay";
	locations[n].fanatic = true;
	//Models
	//Always
	locations[n].models.always.locators = "Church01_locators";
	locations[n].models.always.tavern = "Church01";
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.window = "Church01_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;

Locations[n].models.back = "..\back\inside_back_";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Church01_patch";
	//Night
	locations[n].models.night.charactersPatch = "Church01_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "Oxbay_town_center";
	locations[n].reload.l1.emerge = "home5";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;
	
 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ПОРТОВЫЙ ОФИС
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Oxbay_PortOffice";
	locations[n].id.label = "PortOffice";
	locations[n].image = "loading\inside\portoffice.tga";
	//Town sack
	locations[n].townsack = "Oxbay";
	locations[n].lockWeather = "Inside";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Oxbay";
	locations[n].island = "Oxbay";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\PortOffice";
	locations[n].models.always.housePortOffice = "PortOffice";
	locations[n].models.always.housePortOffice.level = 65538;
	locations[n].models.always.locators = "PortOffice_locators";

	Locations[n].models.always.PortOffice = "PortOffice_windows";
	Locations[n].models.always.PortOffice.tech = "LocationWindows";
	locations[n].models.always.PortOffice.level = 65539;

Locations[n].models.back = "..\back\inside_back_";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "PortOffice_patch";
	//Night
	locations[n].models.night.charactersPatch = "PortOffice_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Oxbay_town";
	locations[n].reload.l1.emerge = "reload10";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Street";
	LAi_LocationFightDisable(&locations[n], true);
	n = n + 1;
	

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_Oxbay\exit";
	Locations[n].filespath.textures = "locations\ENGLAND";

	Locations[n].id = "Oxbay_town_exit";
	locations[n].id.label = "Exit from #stown_name#";
	Locations[n].image = "Town_Oxbay_Exit";

	//Town sack
	Locations[n].townsack = "Oxbay";

	//Sound
	locations[n].type = "jungle";
//	locations[n].fastreload = "Oxbay";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "OXexit_l";
	Locations[n].models.always.exit = "oxexit";
	Locations[n].models.always.grassPatch = "OXexit_g";
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
	Locations[n].models.day.charactersPatch = "OXexit_p";
	Locations[n].models.day.fonar = "OXexit_fd";
	//Night
	Locations[n].models.night.charactersPatch = "OXexit_p";
	Locations[n].models.night.fonar = "OXexit_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload3";
	Locations[n].reload.l1.go = "Oxbay_suburb";	//now leading to new suburb
	Locations[n].reload.l1.emerge = "Falaise_de_fleur_location_02_01";	//now to this lctr
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].reload.l2.name = "Reload2";
	Locations[n].reload.l2.go = "Oxbay_Jungle_01";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 2.0;

	Locations[n].reload.l3.name = "Reload1";
	Locations[n].reload.l3.go = "Oxbay_Jungle_02";
	Locations[n].reload.l3.emerge = "Reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1 = 4.0;

	Locations[n].reload.l4.name = "Reload2_back";
	Locations[n].reload.l4.go = "Oxbay_Jungle_01";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2_back = 2.0;

	Locations[n].reload.l5.name = "Reload1_back";
	Locations[n].reload.l5.go = "Oxbay_Jungle_02";
	Locations[n].reload.l5.emerge = "Reload2";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1_back = 3.0;

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\shipyard";

	Locations[n].id = "Oxbay_shipyard";
	locations[n].id.label = "#stown_name# shipyard";
	Locations[n].image = "Inside_Shipyard1";

	//Town sack
	Locations[n].townsack = "Oxbay";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Oxbay";
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
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\oxsh1_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_town";
	Locations[n].reload.l1.emerge = "Reload3";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\StoreSmall";
	Locations[n].image = "Inside_StoreSmall";

	Locations[n].id = "Oxbay_Store";
	locations[n].id.label = "#stown_name# store";

	//Town sack
	Locations[n].townsack = "Oxbay";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Oxbay";
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
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\oxss_";
	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "Oxbay_town";
	Locations[n].reload.l1.emerge = "Reload15";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	Locations[n].locators_radius.reload.locator2 = 0.7;
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\LargeTavern";

	Locations[n].id = "Oxbay_Tavern";
	locations[n].id.label = "#stown_name# tavern";
	Locations[n].image = "Inside_LargeTavern";

	//Town sack
	Locations[n].townsack = "Oxbay";

	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "Oxbay";
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
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\oxlt_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_Town";
	Locations[n].reload.l1.emerge = "reload13";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

//MAXIMUS -->
	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Oxbay_tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Room in #stown_name# tavern.";
	Locations[n].reload.l2.disable = true; // KK
	LAi_LocationFightDisable(&Locations[n], true);
//MAXIMUS <--

	//Fake locators
	Locations[n].reload.l10.name = "reload_to_town_for_Massoni";
	Locations[n].reload.l10.go = "Oxbay_Town";
	Locations[n].reload.l10.emerge = "goto39";
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Oxbay_tavern_upstairs";
	locations[n].id.label = "Room in #stown_name# tavern";
	Locations[n].image = "Inside_Doubleflour_House_Room";

	//Town sack
	Locations[n].townsack = "Oxbay";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Oxbay";
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
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\oxlf2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Tavern.";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Oxbay_UsurerHouse";
	locations[n].id.label = "Loanshark's Office";
	Locations[n].image = "Inside_Doubleflour_House_Lower";

	Locations[n].vcskip = true; // KK

	//Town sack
	Locations[n].townsack = "Oxbay";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Oxbay";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Doubleflour_house";
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
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\oxlf1_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_town";
	Locations[n].reload.l1.emerge = "reload18";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "Oxbay_HouseInsideR7";
	locations[n].id.label = "House";
	Locations[n].image = "Inside_mh5";

	//Town sack
	Locations[n].townsack = "Oxbay";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Oxbay";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\mh5";
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
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\oxmh5_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_town";
	Locations[n].reload.l1.emerge = "reload7";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "Oxbay_HouseInsideR5";
	Locations[n].id.label = "House";
	Locations[n].image = "Inside_Smallhome";

	//Town sack
	Locations[n].townsack = "Oxbay";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Oxbay";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Smallhome";
	Locations[n].models.always.locators = "sH_l";
	Locations[n].models.always.house = "sh";
	Locations[n].models.always.window = "sh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "sh_p";

	//Night
	Locations[n].models.night.charactersPatch = "sh_p";

	//Environment
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\oxsh_";

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_town";
	Locations[n].reload.l1.emerge = "reload5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// ******************************************************************************************

	// Tailor mod
	Locations[n].id = "Oxbay_TailorsShop";	
	Locations[n].id.label = "Tailor's Shop.";
	Locations[n].image = "Inside_StoreSmall";

	//Town sack
	Locations[n].townsack = "Oxbay";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Oxbay";
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
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\oxss_";

	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "Oxbay_town";
	Locations[n].reload.l1.emerge = "reload9";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";
	Locations[n].locators_radius.reload.locator2 = 0.7;

	LAi_LocationFightDisable(&Locations[n], true);
	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "Oxbay_HouseInsideR8";
	Locations[n].id.label = "House";
	Locations[n].image = "Inside_mh10";

	//Town sack
	Locations[n].townsack = "Oxbay";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Oxbay";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\mh10";
	Locations[n].models.always.locators = "mh10_l";
	Locations[n].models.always.house = "mh10";
	Locations[n].models.always.window = "mh10_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "mh10_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh10_p";

	//Environment
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\oxmh10_";

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_town";
	Locations[n].reload.l1.emerge = "reload8";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "Oxbay_HouseInsideR17";
	Locations[n].id.label = "House";
	Locations[n].image = "Inside_mh7";

	//Town sack
	Locations[n].townsack = "Oxbay";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Oxbay";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\mh7";
	Locations[n].models.always.locators = "mh7_l";
	Locations[n].models.always.house = "mh7";
	Locations[n].models.always.window = "mh7_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "mh7_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh7_p";

	//Environment
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\oxmh7_";

	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_town";
	Locations[n].reload.l1.emerge = "reload17";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// ************************************************************-------------------------------------------------



	Locations[n].filespath.models = "locations\Outside\Jungle_1";

	Locations[n].id = "Oxbay_Jungle_01";
	locations[n].id.label = "#sisland_name# jungles";
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
	Locations[n].reload.l1.go = "Oxbay_town_exit";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1 = 3.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Oxbay_shore_01";
	Locations[n].reload.l2.emerge = "locator3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Far Beach.";
	Locations[n].locators_radius.reload.Reload2 = 3.0;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Oxbay_town_exit";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l4.name = "reload2_back";
	Locations[n].reload.l4.go = "Oxbay_shore_01";
	Locations[n].reload.l4.emerge = "locator3";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Far Beach.";
	Locations[n].locators_radius.reload.reload2_back = 2.0;


	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Shore_1";

	Locations[n].id = "Oxbay_shore_01";
	locations[n].id.label = "Far Beach."; // KK
	locations[n].worldmap = "OShore 1";
	Locations[n].image = "Outside_Shore_1";
	Locations[n].name = "Far Beach";
	//Sound
	locations[n].type = "seashore";
	//Models
	//Always
	Locations[n].models.always.locators = "Shore01_l";
	Locations[n].models.always.shore = "Shore01";
	Locations[n].models.always.shore.foam = "1";
	Locations[n].models.always.seabed = "Shore01_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "Shore01_g";
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
	Locations[n].models.day.charactersPatch = "Shore01_p";
	//Night
	Locations[n].models.night.charactersPatch = "Shore01_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "locator3";
	Locations[n].reload.l1.go = "Oxbay_Jungle_01";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.locator3 = 2.0;

	Locations[n].reload.l2.name = "locator3_back";
	Locations[n].reload.l2.go = "Oxbay_Jungle_01";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.locator3_back = 1.0;

	Locations[n].reload.l3.name = "boat";
	Locations[n].reload.l3.go = "Oxbay";
	Locations[n].reload.l3.emerge = "reload_5";
	Locations[n].reload.l3.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l3.label = "Ship.";
	else
		Locations[n].reload.l3.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 9.0;


	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_3";
	if(GetCurrentPeriod() == PERIOD_EARLY_EXPLORERS) Locations[n].filespath.textures = "locations\SPAIN";

	Locations[n].id = "Oxbay_Jungle_02";
	locations[n].id.label = "#sisland_name# jungles";
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
	Locations[n].reload.l1.go = "Oxbay_jungle_03";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1 = 1.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Oxbay_Town_exit";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2 = 3.0;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Oxbay_Cave_exit";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload3 = 3.0;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Oxbay_jungle_03";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	Locations[n].reload.l5.name = "reload2_back";
	Locations[n].reload.l5.go = "Oxbay_Town_exit";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3.0;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Oxbay_Cave_exit";
	Locations[n].reload.l6.emerge = "reload2";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.reload3_back = 3.0;


	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Cave Entrance";

	Locations[n].id = "Oxbay_Cave_Exit";
	locations[n].id.label = "#sisland_name# cave entrance";
	Locations[n].image = "Outside_Cave_Entrance";
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
	Locations[n].reload.l3.go = "Oxbay_Cave";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Cave.";
	Locations[n].locators_radius.reload.Reload1 = 1;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Oxbay_Cave";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Cave.";
	Locations[n].locators_radius.reload.Reload1_back = 1.3;

	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Oxbay_Jungle_02";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2 = 2.0;

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Oxbay_Jungle_02";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 2.0;


	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Jungle_5";
	if(GetCurrentPeriod() == PERIOD_EARLY_EXPLORERS) Locations[n].filespath.textures = "locations\SPAIN";

	Locations[n].id = "Oxbay_jungle_03";
	locations[n].id.label = "#sisland_name# jungles";
	Locations[n].image = "Outside_Jungle_5";
	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "Jungle05_l";
	Locations[n].models.always.jungle = "Jungle05";
	Locations[n].models.always.grassPatch = "JUNGLE05_g";
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
	Locations[n].models.day.charactersPatch = "Jungle05_p";
	//Night
	Locations[n].models.night.charactersPatch = "Jungle05_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_shore_02";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Gray Rock Bay.";
	Locations[n].locators_radius.reload.Reload1 = 3.0;

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Oxbay_Jungle_02";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2 = 3.0;

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Greenford_town_exit";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "To #stown_name#.";
	Locations[n].locators_radius.reload.Reload3 = 3.0;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "Oxbay_shore_02";
	Locations[n].reload.l4.emerge = "reload2";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Gray Rock Bay.";
	Locations[n].locators_radius.reload.Reload1_back = 2.0;

	Locations[n].reload.l5.name = "reload2_back";
	Locations[n].reload.l5.go = "Oxbay_Jungle_02";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "1";
	Locations[n].reload.l5.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2_back = 2.0;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Greenford_town_exit";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "To #stown_name#.";
	Locations[n].locators_radius.reload.Reload3_back = 2.0;


	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Shore_2";

	Locations[n].id = "Oxbay_shore_02";
	locations[n].id.label = "Gray Rock Bay."; // KK
	locations[n].worldmap = "OShore 2";
	Locations[n].image = "Outside_Shore_2";
	Locations[n].name = "Gray Rock Bay";
	//Sound
	locations[n].type = "seashore";
	//Models
	//Always
	Locations[n].models.always.jungle = "Shore02";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.locators = "Shore02_l";
	Locations[n].models.always.grassPatch = "Shore02_g";
	Locations[n].models.always.seabed = "Shore02_sb";
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
	Locations[n].models.day.charactersPatch = "Shore02_p";
	//Night
	Locations[n].models.night.charactersPatch = "Shore02_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Oxbay_Jungle_03";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 3.0;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Oxbay_Jungle_03";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3.0;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Oxbay";
	Locations[n].reload.l2.emerge = "reload_3";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 9.0;


	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;



//____________________________________________________// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_Greenford\port";
	Locations[n].filespath.textures = "locations\ENGLAND";
	Locations[n].image = "Town_Greenford_Port";

	Locations[n].id = "Greenford_port";
	locations[n].id.label = "#stown_name# port";
	locations[n].worldmap = "Greenford";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "port";
	locations[n].fastreload = "Greenford";
	LAi_LocationFantomsGen(&locations[n], true);
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
	Locations[n].reload.l1.go = "Oxbay";
	Locations[n].reload.l1.emerge = "reload_1";
	Locations[n].reload.l1.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l1.label = "Ship.";
	else
		Locations[n].reload.l1.label = "Sea.";
	Locations[n].locators_radius.reload.Reload1 = 3.0;


	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Oxbay";
	Locations[n].reload.l3.emerge = "reload_1";
	Locations[n].reload.l3.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l3.label = "Ship.";
	else
		Locations[n].reload.l3.label = "Sea.";
	Locations[n].locators_radius.reload.reload1_back = 3.0;

	Locations[n].reload.l2.name = "reload4";
	Locations[n].reload.l2.go = "Greenford_town";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name#.";


	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_Greenford\town";
	Locations[n].filespath.textures = "locations\ENGLAND";
	Locations[n].image = "Town_Greenford_Town";

	Locations[n].id = "Greenford_town";
	locations[n].id.label = "#stown_name#";
	locations[n].worldmap = "Greenford";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "town";
	locations[n].fastreload = "Greenford";
	//Models
	//Always
	Locations[n].models.always.locators = "GrTown_l";
	Locations[n].models.always.town = "GrTown";
	Locations[n].models.always.grassPatch = "GrTown_g";
	Locations[n].models.always.l1 = "grtown_b02";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "grtown_b03";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "grtown_b04";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";	//Day
	Locations[n].models.day.rinok = "GrTown_e01";
	Locations[n].models.day.fonar = "GrTown_fd";
	Locations[n].models.day.charactersPatch = "GrTown_pd";
	Locations[n].models.day.jumpPatch = "GrTown_j";
	//Night
	Locations[n].models.night.fonar = "GrTown_fn";
	Locations[n].models.night.charactersPatch = "GrTown_pn";
	Locations[n].models.night.jumpPatch = "GrTown_j";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	LAi_LocationFantomsGen(&locations[n], true);
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_port";
	Locations[n].reload.l1.emerge = "Reload4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# port."; // KK

	// ccc changed to lead to new suburb
	Locations[n].reload.l2.name = "reload19";
	Locations[n].reload.l2.go = "Greenford_suburb";
	Locations[n].reload.l2.emerge = "reload_3_3";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Suburb";
	// ccc <-

	Locations[n].reload.l3.name = "reload26";
	Locations[n].reload.l3.go = "Oxbay_Canyon";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Canyon. Mines.";

	Locations[n].reload.l4.name = "reload7";
	Locations[n].reload.l4.go = "Greenford_tavern";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Tavern.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l4.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l5.name = "reload6";
	Locations[n].reload.l5.go = "Greenford_InsideHouseR6";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "House.";

	Locations[n].reload.l6.name = "reload14";
	Locations[n].reload.l6.go = "Greenford_InsideHouseR14";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "House.";

	Locations[n].reload.l7.name = "reload23";
	Locations[n].reload.l7.go = "Greenford_Store";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.autoreload = "0";
	Locations[n].reload.l7.label = "Store.";
	Locations[n].reload.l7.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l7.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l8.name = "reload3";
	Locations[n].reload.l8.go = "Greenford_Shipyard";
	Locations[n].reload.l8.emerge = "reload1";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "Shipyard.";
	Locations[n].reload.l8.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l8.goto_disable = 1; // Screwface: Disable Go-To location

  	Locations[n].reload.l9.name = "reload27";
	Locations[n].reload.l9.go = "Greenford_prison";
	Locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "Prison.";
	Locations[n].reload.l9.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l9.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l10.name = "reload17";// Mosh
	Locations[n].reload.l10.go = "Greenford_house_Figuiera";
	Locations[n].reload.l10.emerge = "reload1";
	Locations[n].reload.l10.autoreload = "0";
	Locations[n].reload.l10.label = "House.";
	Locations[n].reload.l10.close_for_night = 1;

	Locations[n].reload.l11.name = "reload15";
	Locations[n].reload.l11.go = "Greenford_church";
	Locations[n].reload.l11.emerge = "reload1";
	Locations[n].reload.l11.autoreload = "0";
	Locations[n].reload.l11.label = "Church.";
	Locations[n].reload.l11.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l11.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l12.name = "reload9";
	Locations[n].reload.l12.go = "Greenford_UsurerHouse";
	Locations[n].reload.l12.emerge = "reload1";
	Locations[n].reload.l12.autoreload = "0";
	Locations[n].reload.l12.label = "Loanshark's Office.";
	Locations[n].reload.l12.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l12.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l13.name = "reload11";
	Locations[n].reload.l13.go = "Yedam Kinne_house";
	Locations[n].reload.l13.emerge = "reload1";
	Locations[n].reload.l13.autoreload = "0";
	Locations[n].reload.l13.label = "House of Yedam Kinne.";

	Locations[n].reload.l14.name = "reload28";
	Locations[n].reload.l14.go = "Greenford_TailorsShop";
	Locations[n].reload.l14.emerge = "locator2";
	Locations[n].reload.l14.autoreload = "0";
	Locations[n].reload.l14.label = "Tailor's Shop.";
	Locations[n].reload.l14.close_for_night   = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l14.goto_disable = 1; // Screwface: Disable Go-To location
	
	Locations[n].reload.l15.name = "reload25";
	Locations[n].reload.l15.go = "Greenford_InsideHouseR25";
	Locations[n].reload.l15.emerge = "reload1";
	Locations[n].reload.l15.autoreload = "0";
	Locations[n].reload.l15.label = "House.";

	Locations[n].reload.l16.name = "reload22";
	Locations[n].reload.l16.go = "Greenford_InsideHouseR22";
	Locations[n].reload.l16.emerge = "reload1";
	Locations[n].reload.l16.autoreload = "0";
	Locations[n].reload.l16.label = "House.";

//Hitman
	Locations[n].reload.l17.name = "reload5";
	Locations[n].reload.l17.go = "Hit_house1";
	Locations[n].reload.l17.emerge = "reload1";
	Locations[n].reload.l17.autoreload = "0";
	Locations[n].reload.l17.label = "House of Geffrey Bampfylde";
//Hitman

// Alan_Smithee Apothecary -->
	Locations[n].reload.l18.name = "reload13";
	Locations[n].reload.l18.go = "Apothecary";
	Locations[n].reload.l18.emerge = "reload1";
	Locations[n].reload.l18.autoreload = "0";
	Locations[n].reload.l18.label = "Apothecary";
	Locations[n].reload.l18.close_for_night = 1; //Levis
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l18.goto_disable = 1;	//JRH
// <-- ditto

	// SJG British Naval HQ --->
	Locations[n].reload.l19.name = "reload10";
	Locations[n].reload.l19.go = "Greenford Naval HQ";
	Locations[n].reload.l19.emerge = "reload1";
	Locations[n].reload.l19.autoreload = "0";
	Locations[n].reload.l19.label = "#stown_name# Naval HQ";
	Locations[n].reload.l19.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l19.goto_disable = 1;	//JRH
	// SJG British Naval HQ <---

	Locations[n].reload.l20.name = "reload21";
	Locations[n].reload.l20.go = "Mrs. Mason's House";
	Locations[n].reload.l20.emerge = "reload1";
	Locations[n].reload.l20.autoreload = "0";
	Locations[n].reload.l20.label = "Mrs. Mason's House";
	Locations[n].reload.l20.close_for_night = 0;

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\town_Greenford\exit";
	Locations[n].filespath.textures = "locations\ENGLAND";

	Locations[n].id = "Greenford_town_exit";
	locations[n].id.label = "Exit from #stown_name#";
	Locations[n].image = "Town_Greenford_Exit";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "jungle";
//	locations[n].fastreload = "Greenford";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "GrExit_l";
	Locations[n].models.always.exit = "GrExit";
	Locations[n].models.always.grassPatch = "GrExit_g";
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
	Locations[n].models.day.charactersPatch = "GrExit_p";
	Locations[n].models.day.fonar = "GrExit_fd";
	//Night
	Locations[n].models.night.charactersPatch = "GrExit_p";
	Locations[n].models.night.fonar = "GrExit_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map
	// ccc changed to lead to new Greenford suburb
	Locations[n].reload.l1.name = "Reload2";
	Locations[n].reload.l1.go = "Greenford_suburb";
	Locations[n].reload.l1.emerge = "reload_3_2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	// ccc <-

	Locations[n].reload.l2.name = "Reload1";
	Locations[n].reload.l2.go = "Oxbay_Jungle_03";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1 = 3;

	Locations[n].reload.l3.name = "Reload1_back";
	Locations[n].reload.l3.go = "Oxbay_Jungle_03";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1_back = 3;


	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\shipyard3";

	Locations[n].id = "Greenford_shipyard";
	locations[n].id.label = "#stown_name# shipyard";
	Locations[n].image = "Inside_Shipyard3";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Greenford";
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
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\grsh3_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_town";
	Locations[n].reload.l1.emerge = "Reload3";
	Locations[n].reload.l1.label = "#stown_name#.";
	Locations[n].reload.l1.autoreload = "0";
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;


	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\MediumStore";
	Locations[n].image = "Inside_MediumStore";

	Locations[n].id = "Greenford_Store";
	locations[n].id.label = "#stown_name# store";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Greenford";
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
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\grms_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_town";
	Locations[n].reload.l1.emerge = "Reload23";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	Locations[n].locators_radius.camdetector.camera1 = 5;
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;


// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\MediumTavern";

	Locations[n].id = "Greenford_Tavern";
	locations[n].id.label = "#stown_name# tavern";
	Locations[n].image = "Inside_MediumTavern";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "Greenford";
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
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\grmt_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_Town";
	Locations[n].reload.l1.emerge = "reload7";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Greenford_tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Room in #stown_name# tavern."; // KK
	Locations[n].reload.l2.disable = true;
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Greenford_tavern_upstairs";
	locations[n].id.label = "Room in #stown_name# tavern."; // KK
	Locations[n].image = "Inside_Doubleflour_House_Room";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Greenford"; // KK
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
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\grlf2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Tavern.";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].id = "Greenford_UsurerHouse";
	locations[n].id.label = "Loanshark's Office.";
	Locations[n].filespath.models = "locations\inside\MediumHouse";
	Locations[n].image = "Inside_MediumHouse";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Greenford";
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
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\grmh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_town";
	Locations[n].reload.l1.emerge = "reload9";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	LAi_LocationFightDisable(&Locations[n], true);



	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	//_____________________________________________________

	Locations[n].filespath.models = "locations\Inside\mh4";

	Locations[n].id = "Greenford_InsideHouseR6";
	locations[n].id.label = "House";
	Locations[n].image = "Inside_mh4";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Greenford";
	//Models
	//Always
	Locations[n].models.always.locators = "mh4_l";
	Locations[n].models.always.l1 = "mh4";
	Locations[n].models.always.window = "mh4_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "mh4_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh4_p";

	//Environment
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\grmh4_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_Town";
	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";


	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	//_____________________________________________________
	// Greenford Tailor
	Locations[n].filespath.models = "locations\Inside\StoreSmall";

	Locations[n].id = "Greenford_TailorsShop";
	locations[n].id.label = "Tailor's Shop";
	Locations[n].image = "Inside_StoreSmall";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Greenford";
	//Models
	//Always
	Locations[n].models.always.locators = "SS_l";
	Locations[n].models.always.store = "SS";
	Locations[n].models.always.window = "SS_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	
	//Day
	Locations[n].models.day.charactersPatch = "SS_p";
	Locations[n].models.day.fonar			 = "SS_fn";

	//Night
	Locations[n].models.night.charactersPatch = "SS_p";
	Locations[n].models.night.fonar		   = "ss_fn";

	//Environment
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\grmh9_";
	//Reload map
	Locations[n].reload.l1.name = "locator2";
	Locations[n].reload.l1.go = "Greenford_Town";
	Locations[n].reload.l1.emerge = "reload28";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	Locations[n].locators_radius.reload.locator2 = 0.7;

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;


	//--------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\mh8";

	Locations[n].id = "Greenford_InsideHouseR25";
	locations[n].id.label = "House";
	Locations[n].image = "Inside_mh8";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Greenford";
	//Models
	//Always
	Locations[n].models.always.locators = "mh8_l";
	Locations[n].models.always.l1 = "mh8";
	Locations[n].models.always.window = "mh8_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "mh8_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh8_p";

	//Environment
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\grmh8_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_Town";
	Locations[n].reload.l1.emerge = "reload25";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].locators_radius.camdetector.camera1 = 3.0;
	Locations[n].locators_radius.camdetector.camera2 = 1.8;


	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	//_____________________________________________________

	Locations[n].filespath.models = "locations\Inside\mh9";

	Locations[n].id = "Greenford_InsideHouseR22";
	locations[n].id.label = "House";
	Locations[n].image = "Inside_mh9";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Greenford";
	//Models
	//Always
	Locations[n].models.always.locators = "mh9_l";
	Locations[n].models.always.l1 = "mh9";
	Locations[n].models.always.window = "mh9_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "mh9_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh9_p";

	//Environment
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\grmh9_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_Town";
	Locations[n].reload.l1.emerge = "reload22";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";


	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;


	//_____________________________________________________

	Locations[n].filespath.models = "locations\Inside\Doubleflour_house";

	Locations[n].id = "Greenford_InsideHouseR14";
	locations[n].id.label = "House";
	Locations[n].image = "Inside_Doubleflour_House_Lower";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Greenford";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Doubleflour_house";
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
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\grlf1_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_Town";
	Locations[n].reload.l1.emerge = "reload14";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";


	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

//----------------------------------------------------------------------
// SJG ---> Greenford Naval HQ 5/30/2009
	Locations[n].id = "Greenford Naval HQ";
	locations[n].id.label = "#stown_name# Naval HQ";
	Locations[n].image = "Inside_Residence2";
	Locations[n].filespath.models = "locations\inside\Residence2";

	Locations[n].vcskip = true;

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Greenford";
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
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\mures2_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].locators_radius.goto.goto8 = 1.5; // SJG 18MAR09
	Locations[n].reload.l1.go = "Greenford_town";
	Locations[n].reload.l1.emerge = "reload10";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#. Center.";
	LAi_LocationFightDisable(&Locations[n], false);

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Greenford_Station";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Officer Commanding #stown_name# Naval HQ";
	LAi_LocationFightDisable(&Locations[n], false);

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\inside\Residence4";

	Locations[n].id = "Greenford_Station";
	locations[n].id.label = "Officer Commanding #stown_name# Naval HQ";
	Locations[n].image = "Inside_Residence4";

	Locations[n].vcskip = true;

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "residence";
//	locations[n].fastreload = "Greenford";
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
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\dour4_";

	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Greenford Naval HQ";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# Naval HQ";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Oxbay"; // NK 04-08-29

	n = n + 1;

	//_____________________________________________________

	Locations[n].filespath.models = "locations\Inside\Doubleflour_house";

	Locations[n].id = "Mrs. Mason's House";
	locations[n].id.label = "Mrs. Mason's House";
	Locations[n].image = "Inside_Doubleflour_House_Lower";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Greenford";
	//Models
	//Always
	Locations[n].filespath.models = "locations\inside\Doubleflour_house";
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
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\grlf1_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_Town";
	Locations[n].reload.l1.emerge = "reload21";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

//----------------------------------------------------------------------

// SJG <--- -------------------------------------------------

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\outside\Canyon";

	Locations[n].id = "Oxbay_Canyon";
	locations[n].id.label = "#sisland_name# canyon";
	Locations[n].image = "Outside_Canyon";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "canyon";
//	locations[n].fastreload = "Greenford";
	//Models
	//Always
	Locations[n].models.always.locators = "rift_l";
	Locations[n].models.always.rift = "rift";
	Locations[n].models.always.grassPatch = "rift_g";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";

	//Day
	Locations[n].models.day.charactersPatch = "rift_p";
	Locations[n].models.day.fonar = "rift_fd";
	//Night
	Locations[n].models.night.charactersPatch = "rift_p";
	Locations[n].models.night.fonar = "rift_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Greenford_town";
	Locations[n].reload.l1.emerge = "reload26";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload1 = 1.0;

	Locations[n].reload.l2.name = "reload6_back";
	Locations[n].reload.l2.go = "Oxbay_Lighthouse";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "#sisland_name# lighthouse."; // KK
	Locations[n].locators_radius.reload.Reload6_back = 3.0;

	Locations[n].reload.l3.name = "reload4";
	Locations[n].reload.l3.go = "Oxbay_Mine";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Mines.";

	Locations[n].reload.l4.name = "reload5";
	Locations[n].reload.l4.go = "Mines_commander_house";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Mines Office.";


	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\outside\Mayak";

	Locations[n].id = "Oxbay_Lighthouse";
	Locations[n].name = "Lighthouse";
	locations[n].id.label = "#sisland_name# lighthouse."; // KK
	locations[n].worldmap = "Lighthouse";
	Locations[n].image = "Outside_Mayak";
	//Sound
	locations[n].type = "seashore";
	//Models
	//Always
	Locations[n].models.always.locators = "mayak_l";
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
	Locations[n].reload.l1.go = "Oxbay_Canyon";
	Locations[n].reload.l1.emerge = "reload6";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Canyon. Mines.";
	Locations[n].locators_radius.reload.Reload1 = 3.0;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Oxbay_Canyon";
	Locations[n].reload.l3.emerge = "reload6";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Canyon. Mines.";
	Locations[n].locators_radius.reload.reload1_back = 3.0;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Oxbay";
	Locations[n].reload.l2.emerge = "Reload_4";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 12.0;

	Locations[n].reload.l4.name = "reload5";
	Locations[n].reload.l4.go = "Lighthouse_Inside";
	Locations[n].reload.l4.emerge = "Reload1";
	Locations[n].reload.l4.label = "Lighthouse Inside.";
//	Locations[n].reload.l4.close_for_night = 1;
	Locations[n].reload.l4.disable = 1;


	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\outside\Mayak_inside";

	Locations[n].id = "Lighthouse_Inside";
	Locations[n].name = "Lighthouse Inside";
	locations[n].id.label = "#sisland_name# lighthouse Inside";
	Locations[n].image = "Outside_Mayak_Inside";
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
	Locations[n].reload.l1.go = "Oxbay_Lighthouse";
	Locations[n].reload.l1.emerge = "reload5";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#sisland_name# lighthouse";
	Locations[n].locators_radius.reload.Reload1 = 1.5;

	Locations[n].items.randitem1 = "spyglass4";


	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

// -------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\Mine";

	Locations[n].id = "Oxbay_mine";
	locations[n].id.label = "#sisland_name# mine";
	Locations[n].image = "Inside_Mine";

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
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_Canyon";
	Locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Canyon. Mines.";

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "Oxbay_Canyon";
	Locations[n].reload.l2.emerge = "reload4";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Canyon. Mines.";


/*	Locations[n].reload.l2.name = "reload1";
	Locations[n].reload.l2.go = "Oxbay_Lighthouse";
	Locations[n].reload.l2.emerge = "locator1";*/


	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Greenford_prison";
	locations[n].id.label = "#stown_name# prison";
	Locations[n].filespath.models = "locations\inside\prison";
	Locations[n].image = "Inside_Prison";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "jail";
	LAi_LocationFantomsGen(&locations[n], true);
	//locations[n].fastreload = "Greenford";

	Locations[n].locators_radius.camdetector.camera13 = 2.5;//Mosh
	Locations[n].locators_radius.camdetector.camera12 = 0.5;//Mosh
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
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_town";
	Locations[n].reload.l1.emerge = "reload27";
	Locations[n].reload.l1.label = "#stown_name#.";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Mines_commander_house";
	locations[n].label = "House начальника рудников";
	Locations[n].filespath.models = "locations\inside\smallhome";
	Locations[n].image = "Inside_Smallhome";

	Locations[n].vcskip = true;

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
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\pifsh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_canyon";
	Locations[n].reload.l1.emerge = "reload5";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Yedam Kinne_house";
	locations[n].label = "Yedam Kinne's house";
	Locations[n].filespath.models = "locations\inside\smallhome";
	Locations[n].image = "Inside_Smallhome";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Greenford";
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
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\grsh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_town";
	Locations[n].reload.l1.emerge = "reload11";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// Greenford_church -------------------------------------------------
	Locations[n].id = "Greenford_church";
	locations[n].id.label = "#stown_name# church";
	Locations[n].image = "Inside_Church_2";
	Locations[n].filespath.models = "locations\inside\Church_2";

	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "church";
	locations[n].fastreload = "Greenford";
	//Models
	//Always
	Locations[n].models.always.city = "Church2";
	Locations[n].models.always.locators = "Church2_l";
	Locations[n].models.always.window = "church2_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
//	Locations[n].models.day.lamp = "FalaiseDeFleur05_day";
	Locations[n].models.day.charactersPatch = "Church2_p";

	//Night
//	Locations[n].models.night.lamp = "FalaiseDeFleur05_night";
	Locations[n].models.night.charactersPatch = "Church2_p";

	//Environment
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_town";
	Locations[n].reload.l1.emerge = "reload15";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";
	LAi_LocationFightDisable(&Locations[n], true);



	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// -----------------Mosh D24--------------------
	Locations[n].filespath.models = "locations\Inside\MediumHouse";
	Locations[n].id = "Greenford_house_Figuiera";
	Locations[n].image = "Inside_MediumHouse";
	locations[n].id.label = "House";
	//Town sack
	Locations[n].townsack = "Greenford";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Greenford";
	//Models
	//Always
	Locations[n].models.always.locators = "MH_l";
	Locations[n].models.always.house = "MH";
	Locations[n].models.always.window = "MH_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "MH_p";

	//Night
	Locations[n].models.night.charactersPatch = "MH_p";

	//Environment
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\grmh_";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Greenford_town";//Mosh
	Locations[n].reload.l1.emerge = "reload17";
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// -----------------Mosh D24--------------------
	Locations[n].filespath.models = "locations\Inside\Dungeon_1";
	Locations[n].id = "Dungeon 1";
	Locations[n].image = "Inside_Dungeon_1";
	Locations[n].monsters = "1";
	locations[n].id.label = "#stown_name# Dungeon";
	//Town sack
	Locations[n].townsack = "Oxbay";

	//Sound
	locations[n].type = "Dungeon";
	locations[n].fastreload = "Oxbay";
	//Models
	//Always
	Locations[n].models.always.locators = "d01_l";
	Locations[n].models.always.house = "d01";
	//Day
	Locations[n].models.day.charactersPatch = "d01_p";
	//Night
	Locations[n].models.night.charactersPatch = "d01_p";
	//Environment
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";

	LAi_LocationFantomsGen(&locations[n], true);

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_town";
	Locations[n].reload.l1.emerge = "reload19";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Oxbay_port";
	Locations[n].reload.l2.emerge = "reload3";
	Locations[n].reload.l2.autoreload = "1";

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Oxbay_port";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].locators_radius.reload.reload2_back = 1.5;

	// ccc new exit
	Locations[n].reload.l11.name = "reloadc3";
	Locations[n].reload.l11.go = "Greenford_M_crypt"; // KK
	Locations[n].reload.l11.emerge = "Reload3";
	Locations[n].reload.l11.autoreload = "1";

	Locations[n].reload.l12.name = "reloadc4";
	Locations[n].reload.l12.go = "greenford_m_undercroft";
	Locations[n].reload.l12.emerge = "reload2";

	Locations[n].items.randitem1 = "blade12";

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// -----------------Mosh D24--------------------
	Locations[n].filespath.models = "locations\Inside\Dungeon_3";
	Locations[n].id = "Oxbay_cave";
	Locations[n].image = "Inside_Dungeon_3";
//	Locations[n].monsters = "1";
	locations[n].id.label = "Abandoned mine";
	//Sound
	locations[n].type = "Dungeon";
	//Models
	Locations[n].models.back = "back\d03env_";
	//Always
	Locations[n].models.always.locators = "d03_l";
	Locations[n].models.always.house = "d03";
	//Day
	Locations[n].models.day.charactersPatch = "d03_p";
	//Night
	Locations[n].models.night.charactersPatch = "d03_p";
	//Environment
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Oxbay_cave_exit";//Mosh
	Locations[n].reload.l1.emerge = "reload1";

// ccc new exit
//	Locations[n].reload.l11.name = "randitem1";
//	Locations[n].reload.l11.go = "Greenford_M_crypt"; // KK
//	Locations[n].reload.l11.emerge = "Reload16";
//	Locations[n].reload.l11.autoreload = "1";

	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 0, 24);

	// KevAtl 08-26-2007 Added special one-of-a-kind sword in Oxbay cave
	Locations[n].items.randitem1 = "blade29";

	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\inside\Residence5";

	Locations[n].id = "Mings_Townhall";
	locations[n].id.label = "House";
	Locations[n].image = "Inside_Residence5";

	//Town sack
	Locations[n].townsack = "Oxbay";

	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Oxbay";

	//Models
	//Always
	Locations[n].models.always.locators = "Res05_l";
	Locations[n].models.always.l1 = "Res05";
	Locations[n].models.always.window = "Res05_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "Res05_p";
	//Night
	Locations[n].models.night.charactersPatch = "Res05_p";
	//Environment
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\cores5_";

	//Reload map
	Locations[n].reload.l1.name = "Reload1";
	Locations[n].reload.l1.go = "Oxbay_Town";
	Locations[n].reload.l1.emerge = "reload4";
	Locations[n].reload.l1.autoreload = "0";

	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "Oxbay"; // NK 04-08-29
	n = n + 1;
	
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Плантация Барбадоса
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Oxbay_Plantation";
	locations[n].id.label = "Plantation";
	locations[n].image = "loading\Plantation.tga";
	//Town sack
	locations[n].townsack = "Oxbay";
	locations[n].island = "Oxbay";
	//Sound
	locations[n].type = "town";
	//Models
	//Always
	locations[n].filespath.models = "locations\BarbadosPlantation";
	locations[n].models.always.BarbadosPlantation = "BarbadosPlantation";	
	locations[n].models.always.reflect = "BarbadosPlantation_reflect";
	Locations[n].models.always.reflect.sea_reflection = 1;	
	locations[n].models.always.gate = "BarbadosPlantation_gateopen";	
	locations[n].models.always.locators = "BarbadosPlantation_locators";	
	locations[n].models.always.grassPatch = "BarbadosPlantation_grass";
	Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";	
	Locations[n].models.always.Waterfall = "waterfall";
	Locations[n].models.always.Waterfall.uvslide.v0 = 0.3;
    Locations[n].models.always.Waterfall.uvslide.v1 = 0.0;
	Locations[n].models.always.Waterfall.tech = "LocationWaterFall";
	Locations[n].models.always.Waterfall.level = 99949;	
	locations[n].models.always.plan1 = "plan1";
	locations[n].models.always.plan1.level = 9;	
	locations[n].models.always.plan2 = "plan2";
	locations[n].models.always.plan2.level = 8;	
	locations[n].models.always.plan3 = "plan3";
	locations[n].models.always.plan3.level = 7;	
	locations[n].models.always.plan4 = "plan4";
	locations[n].models.always.plan4.level = 6;
	//Day
	locations[n].models.day.charactersPatch = "BarbadosPlantation_patchopen";
	locations[n].models.day.fonar = "BarbadosPlantation_fd";
	//Night
	locations[n].models.night.charactersPatch = "BarbadosPlantation_patchopen";
	locations[n].models.night.fonar = "BarbadosPlantation_fn";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "oxbay_old_fort";
	locations[n].reload.l1.emerge = "reload1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Jungle";
	locations[n].locators_radius.reload.reload1_back = 2;

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "Oxbay_Near_Plantation";
	locations[n].reload.l2.emerge = "reload1";
	locations[n].reload.l2.autoreload = "1";
	locations[n].reload.l2.label = "Oxbay Fort";
	locations[n].locators_radius.reload.reload2_back = 2;
	//дома
	locations[n].reload.l3.name = "houseSp1";
	locations[n].reload.l3.go = "Plantation_Sp1";
	locations[n].reload.l3.emerge = "reload1";
	locations[n].reload.l3.autoreload = "0";
	locations[n].reload.l3.label = "house";

	locations[n].reload.l4.name = "houseS1";
	locations[n].reload.l4.go = "Plantation_S1";
	locations[n].reload.l4.emerge = "reload1";
	locations[n].reload.l4.autoreload = "0";
	locations[n].reload.l4.label = "house";

	locations[n].reload.l5.name = "houseS2";
	locations[n].reload.l5.go = "Plantation_S2";
	locations[n].reload.l5.emerge = "reload1";
	locations[n].reload.l5.autoreload = "0";
	locations[n].reload.l5.label = "house";

	locations[n].reload.l6.name = "houseF1";
	locations[n].reload.l6.go = "Plantation_F1";
	locations[n].reload.l6.emerge = "reload1";
	locations[n].reload.l6.autoreload = "0";
	locations[n].reload.l6.label = "house";

	locations[n].reload.l7.name = "houseF2";
	locations[n].reload.l7.go = "Plantation_F2";
	locations[n].reload.l7.emerge = "reload1";
	locations[n].reload.l7.autoreload = "0";
	locations[n].reload.l7.label = "house";

    locations[n].locators_radius.quest.detector1 = 5.0; //homo
    n = n + 1;

	Locations[n].filespath.models = "locations\town_Douwesen\exit";
	Locations[n].filespath.textures = "locations\ENGLAND";

	Locations[n].id = "Oxbay_Near_Plantation";
	locations[n].id.label = "Oxbay_Near_Plantation";
	Locations[n].image = "Town_Douwesen_Exit";

	//Town sack
	Locations[n].townsack = "oxbay";

	//Sound
	locations[n].type = "jungle";
//	locations[n].fastreload = "oxbay";
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
	Locations[n].reload.l1.go = "Oxbay_Plantation";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].locators_radius.reload.reload1 = 4;
	Locations[n].reload.l1.label = "Jungle.";

	Locations[n].reload.l2.name = "Reload2";
	Locations[n].reload.l2.go = "oxbay_town_center";
	Locations[n].reload.l2.emerge = "Falaise_de_fleur_location_03_02";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "#stown_name#.";

	Locations[n].island = "oxbay"; // NK 04-08-29
	n = n + 1;

locations[n].id = "oxbay_old_fort";
locations[n].id.label = "oxbay_old_fort";
locations[n].image = "loading\towns\pearl1.tga.tx";
locations[n].citizens = true;
locations[n].soldiers = true;
//Town sack
locations[n].townsack = "oxbay";
//Sound
locations[n].type = "town";
locations[n].island = "oxbay";
//Models
//Always
	Locations[n].filespath.models = "locations\Fort_inside\White_fort";
Locations[n].models.always.locators = "fort2_locators_blood";
Locations[n].models.always.l1 = "Fort2";
Locations[n].models.always.grassPatch = "Fort2_grass";
//Day
Locations[n].models.day.charactersPatch = "Fort2_patch";
Locations[n].models.day.fonar = "Fort2_fd";
//Night
Locations[n].models.night.charactersPatch = "Fort2_patch";
Locations[n].models.night.fonar = "Fort2 _fn";
//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
//Reload map
Locations[n].reload.l1.name = "reload1";
Locations[n].reload.l1.go = "Oxbay_Plantation";
Locations[n].reload.l1.emerge = "reload1";
locations[n].locators_radius.reload.reload1 = 1.8;
n = n + 1;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Plantation_Sp1";
	locations[n].filespath.models = "locations\inside\StoneHouse";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\stonehouse.tga";
	//Town sack
	locations[n].townsack = "Oxbay";
	locations[n].island = "Oxbay";
	//Sound
	locations[n].type = "house";
	//Models
	//Always
	locations[n].models.always.tavern = "StoneHouse";
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.window = "StoneHouse_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;
	locations[n].models.day.locators = "StoneHouse_locators";
	locations[n].models.night.locators = "StoneHouse_Nlocators";

Locations[n].models.back = "..\back\inside_back_";
	locations[n].models.always.back.level = 65529;
    //Day
	locations[n].models.day.charactersPatch = "StoneHouse_patch";
	//Night
	locations[n].models.night.charactersPatch = "StoneHouse_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Oxbay_Plantation";
	locations[n].reload.l1.emerge = "houseSp1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Plantation";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Plantation_S1";
	locations[n].filespath.models = "locations\inside\Hut";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\hut.tga";
	//Town sack
	locations[n].townsack = "Oxbay";
	locations[n].island = "Oxbay";
	//Sound
	locations[n].type = "house";
	//Models
	//Always
	locations[n].models.always.locators = "Hut_locators";
	locations[n].models.always.tavern = "Hut";
	locations[n].models.always.tavern.level = 65538;
	locations[n].models.always.window = "Hut_window";
	locations[n].models.always.window.tech = "LocationWindows";
	locations[n].models.always.window.level = 65539;

Locations[n].models.back = "..\back\inside_back_";
	locations[n].models.always.back.level = 65529;
	//Day
	locations[n].models.day.charactersPatch = "Hut_patch";
	//Night
	locations[n].models.night.charactersPatch = "Hut_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Oxbay_Plantation";
	locations[n].reload.l1.emerge = "houseS1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Plantation";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Plantation_S2";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\hut.tga";
	//Town sack
	locations[n].townsack = "Oxbay";
	locations[n].island = "Oxbay";
	//Sound
	locations[n].type = "house";
	//Models
	//Always
locations[n].filespath.models = "locations\inside\Hut1";
locations[n].models.always.locators = "Hut1_locators";
locations[n].models.always.hut1 = "Hut1";
//Day
locations[n].models.day.charactersPatch = "Hut1_patch";
//Night
locations[n].models.night.charactersPatch = "Hut1_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Oxbay_Plantation";
	locations[n].reload.l1.emerge = "houseS2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Plantation";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Plantation_F1";
	locations[n].id.label = "Room";
	locations[n].image = "loading\inside\mediumhouse10.tga";
	//Town sack
	locations[n].townsack = "Oxbay";
	locations[n].island = "Oxbay";
	//Sound
	locations[n].type = "house";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\mediumhouse05";
	locations[n].models.always.mediumhouse05 = "mediumhouse05";
	locations[n].models.always.mediumhouse05.level = 65538;
	locations[n].models.day.locators = "mediumhouse05_locators";
	locations[n].models.night.locators = "mediumhouse05_Nlocators";

	Locations[n].models.always.mediumhouse05windows = "mediumhouse05_windows";
	Locations[n].models.always.mediumhouse05windows.tech = "LocationWindows";
	locations[n].models.always.mediumhouse05windows.level = 65539;

Locations[n].models.back = "..\back\inside_back_";
	locations[n].models.always.back.level = 65529;
	//Day
	Locations[n].models.day.mediumhouse05rand= "mediumhouse05_rand";
	locations[n].models.day.charactersPatch = "mediumhouse05_patch";
	//Night
	locations[n].models.night.charactersPatch = "mediumhouse05_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Oxbay_Plantation";
	locations[n].reload.l1.emerge = "houseF1";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Plantation";
	n = n + 1;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	locations[n].id = "Plantation_F2";
	locations[n].id.label = "House";
	locations[n].image = "loading\inside\mediumhouse10.tga";
	//Town sack
	locations[n].townsack = "Oxbay";
	locations[n].island = "Oxbay";
	//Sound
	locations[n].type = "house";
	//Models
	//Always
	locations[n].filespath.models = "locations\inside\mediumhouse09";
	locations[n].models.always.house = "mediumhouse09";
	locations[n].models.always.house.level = 65538;
	locations[n].models.day.locators = "mediumhouse09_locators";
	locations[n].models.night.locators = "mediumhouse09_Nlocators";

	Locations[n].models.always.mediumhouse09windows = "mediumhouse09_windows";
	Locations[n].models.always.mediumhouse09windows.tech = "LocationWindows";
	locations[n].models.always.mediumhouse09windows.level = 65539;

Locations[n].models.back = "..\back\inside_back_";
	locations[n].models.always.back.level = 65529;
	//Day
	Locations[n].models.day.mediumhouse09rand= "mediumhouse09_rand";
	locations[n].models.day.charactersPatch = "mediumhouse09_patch";
	//Night
	locations[n].models.night.charactersPatch = "mediumhouse09_patch";
	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "false";
	//Reload map
	locations[n].reload.l1.name = "reload1";
	locations[n].reload.l1.go = "Oxbay_Plantation";
	locations[n].reload.l1.emerge = "houseF2";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Plantation";
	n = n + 1;

}
