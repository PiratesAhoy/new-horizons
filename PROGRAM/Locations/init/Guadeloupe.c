void LocationInitguadeloupe(ref n)
{
	// -------------------------------------------------
	Locations[n].id = "Guadeloupe_Port";
	locations[n].id.label = "#stown_name# Port.";
	locations[n].worldmap = "Pointe a Pitre";
	Locations[n].image = "Town_PointeAPitre.tga";

	//Town sack
	Locations[n].townsack = "Pointe a Pitre";

	//Sound
	locations[n].type = "port";
	locations[n].soundskip = true;//MAXIMUS: will resolve trouble with sounds [strange, but StaticSounds not works in AOP locations. I'm wondering - all was OK with these locations]
	locations[n].fastreload = "Pointe_a_Pitre";
	LAi_LocationFantomsGen(&locations[n], true);
	//Models

	Locations[n].filespath.models = "locations\Town_PointeAPitre";

	Locations[n].models.always.locators = "PointeAPitre_l";

	//upgrades
	Locations[n].upgrades = "upgrades";
	Locations[n].models.always.shipyard = "..\upgrades\shipyard1";
	Locations[n].models.always.shipyard.status = "..\upgrades\shipyard1";
	InitUpgrades(Locations[n].id);

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 1.1; // screwface

	//Always
	Locations[n].models.always.grassPatch = "PointeAPitre_g";
	Locations[n].models.always.l1 = "PointeAPitre";
	Locations[n].models.always.l1.foam = "1";
	Locations[n].models.always.l2 = "PointeAPitre_sb";
	Locations[n].models.always.l2.foam = "1";

	Locations[n].models.always.l4 = "PointeAPitre_signsA";
	Locations[n].models.always.l4.level = 9;

	//Day
	Locations[n].models.day.rinok = "PointeAPitre_e1";
	Locations[n].models.day.fonar = "PointeAPitre_fd";
	Locations[n].models.day.charactersPatch = "PointeAPitre_pd";
	//Night
	Locations[n].models.night.fonar = "PointeAPitre_fn";
	Locations[n].models.night.charactersPatch = "PointeAPitre_pn";

	//Reload map
	Locations[n].reload.l1.go = "Guadeloupe";
	Locations[n].reload.l1.emerge = "reload_2";
	Locations[n].reload.l1.name = "reload2_back";
	Locations[n].reload.l1.autoreload = "0";
// KK -->
	if (VISIT_DECK == 1)
		Locations[n].reload.l1.label = "Ship.";
	else
		Locations[n].reload.l1.label = "Sea.";
// <-- KK
	Locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].reload.l2.go = "Guadeloupe";
	Locations[n].reload.l2.emerge = "reload_2";
	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.autoreload = "0";
// KK -->
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
// <-- KK
	Locations[n].locators_radius.reload.reload2_back = 2;

	Locations[n].reload.l3.go = "Pointe_a_pitre_shipyard";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.name = "reload5_back";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Shipyard.";
	Locations[n].reload.l3.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l3.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l4.go = "Pointe_a_pitre_store";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.name = "reload6_back";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Store.";
	Locations[n].reload.l4.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l4.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l5.go = "PaP_townhall";
	Locations[n].reload.l5.emerge = "reload1";
	Locations[n].reload.l5.name = "reload3_back";
	Locations[n].reload.l5.autoreload = "0";
	Locations[n].reload.l5.label = "Residence.";
	Locations[n].reload.l5.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l5.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l6.go = "Pointe_a_pitre_tavern";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.name = "reload4_back";
	Locations[n].reload.l6.autoreload = "0";
	Locations[n].reload.l6.label = "Tavern.";
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l6.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l7.go = "StoneHouse";
	Locations[n].reload.l7.emerge = "reload1";
	Locations[n].reload.l7.label = "House.";
	Locations[n].reload.l7.name = "houseS1";
	Locations[n].reload.l7.autoreload = "0";

	Locations[n].reload.l8.go = "PaP_usurer";
	Locations[n].reload.l8.emerge = "reload1";
	Locations[n].reload.l8.name = "reload8_back";
	Locations[n].reload.l8.autoreload = "0";
	Locations[n].reload.l8.label = "Loanshark's Office.";
	Locations[n].reload.l8.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l8.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l9.go = "PaP_Church";
	Locations[n].reload.l9.emerge = "reload1";
	Locations[n].reload.l9.name = "reload7_back";
	Locations[n].reload.l9.autoreload = "0";
	Locations[n].reload.l9.label = "Church.";
	Locations[n].reload.l9.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l9.goto_disable = 1; // Screwface: Disable Go-To location

	Locations[n].reload.l10.go = "Guadeloupe_Plantation"; // Screwface : was "Pointe_a_pitre_town_01";
	Locations[n].reload.l10.emerge = "Reload1"; // Screwface : was "reload_2_jungle";
	Locations[n].reload.l10.label = "Plantation."; // was "#stown_name#.";
	Locations[n].reload.l10.name = "gate";
	Locations[n].reload.l10.autoreload = "0";

	Locations[n].reload.l11.go = "Guadeloupe_House_02";
	Locations[n].reload.l11.emerge = "reload1";
	Locations[n].reload.l11.label = "House.";
	Locations[n].reload.l11.name = "brothel";
	Locations[n].reload.l11.autoreload = "0";

	Locations[n].reload.l12.go = "";//House
	Locations[n].reload.l12.emerge = "reload1";
	Locations[n].reload.l12.label = "House.";
	Locations[n].reload.l12.disable = 1;
	Locations[n].reload.l12.name = "houseS3";
	Locations[n].reload.l12.autoreload = "0";

	Locations[n].reload.l13.go = "";//House
	Locations[n].reload.l13.emerge = "reload1";
	Locations[n].reload.l13.label = "House.";
	Locations[n].reload.l13.disable = 1;
	Locations[n].reload.l13.name = "houseH1";
	Locations[n].reload.l13.autoreload = "0";

	Locations[n].reload.l14.go = "PaP_Arsenal";
	Locations[n].reload.l14.emerge = "reload1";
	Locations[n].reload.l14.label = "Arsenal.";
	Locations[n].reload.l14.name = "barracks";
	Locations[n].reload.l14.autoreload = "0";
	Locations[n].reload.l14.close_for_night = 1;

	Locations[n].reload.l15.go = "PaP_Storehouse";
	Locations[n].reload.l15.emerge = "reload1";
	Locations[n].reload.l15.label = "Storehouse.";
	Locations[n].reload.l15.name = "storehouse";
	Locations[n].reload.l15.autoreload = "0";
	Locations[n].reload.l15.close_for_night = 1;

	Locations[n].reload.l16.go = "PaP_Academy";
	Locations[n].reload.l16.emerge = "reload1";
	Locations[n].reload.l16.label = "Academy.";
	Locations[n].reload.l16.name = "academy";
	Locations[n].reload.l16.autoreload = "0";
	Locations[n].reload.l16.close_for_night = 1;
	if(iRealismMode>0 && DISCOVER_FAST_TRAVEL) Locations[n].reload.l16.goto_disable = 1;	//JRH

// Screwface : reassign houses entrance
	Locations[n].reload.l17.name = "houseSp1";
	Locations[n].reload.l17.go = "Guadeloupe_House_03";
	Locations[n].reload.l17.emerge = "reload1";
	Locations[n].reload.l17.autoreload = "0";
	Locations[n].reload.l17.label = "House.";

	Locations[n].reload.l18.name = "houseF1";
	Locations[n].reload.l18.go = "Guadeloupe_House_01";
	Locations[n].reload.l18.emerge = "reload1";
	Locations[n].reload.l18.autoreload = "0";
	Locations[n].reload.l18.label = "House.";
// Screwface : end

	Locations[n].island = "Guadeloupe";
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "PaP_Arsenal";
	locations[n].id.label = "Arsenal";
	//Town sack
	Locations[n].townsack = "Pointe a Pitre";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Pointe_a_Pitre";

	InitArsenal(Locations[n].id);

	//Reload map
	Locations[n].reload.l1.go = "Guadeloupe_Port";
	Locations[n].reload.l1.label = "#stown_name#";

	Locations[n].reload.l2.go = "PaP_Guardhouse";
	Locations[n].reload.l2.label = "Guardhouse";
	Locations[n].reload.l2.emerge = "reload2";

	Locations[n].island = "Guadeloupe";
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "PaP_Guardhouse";
	locations[n].id.label = "Guardhouse";
	//Town sack
	Locations[n].townsack = "Pointe a Pitre";
	//Sound
	locations[n].type = "jail";
	locations[n].fastreload = "Pointe_a_Pitre";

	InitHut(Locations[n].id);

	//Reload map
	Locations[n].reload.l1.go = "PaP_Arsenal";
	Locations[n].reload.l1.label = "Arsenal";
	Locations[n].reload.l1.emerge = "reload2";

	Locations[n].reload.l2.go = "PaP_prison";
	Locations[n].reload.l2.label = "#stown_name# prison";
	Locations[n].reload.l2.emerge = "reload1";

	Locations[n].island = "Guadeloupe";
	n = n + 1;

    //  -------------------------------------------------
	Locations[n].id = "PaP_prison";
	locations[n].id.label = "#stown_name# prison";
	Locations[n].filespath.models = "locations\inside\prison";
	Locations[n].image = "Inside_Prison.tga";

	//Town sack
	Locations[n].townsack = "Pointe a Pitre";

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
	Locations[n].reload.l1.go = "PaP_Guardhouse";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.label = "Guardhouse.";

	locations[n].reload.l2.name = "reload12";
	locations[n].reload.l2.go = "";
	locations[n].reload.l2.emerge = "reload12";
	locations[n].reload.l2.disable = 1;
	Locations[n].locators_radius.reload.reload12 = 0.5;
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Guadeloupe";
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "PaP_townhall";
	locations[n].id.label = "#stown_name# residence";
	//Town sack
	Locations[n].townsack = "Pointe a Pitre";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Pointe_a_Pitre";

	InitResidence7(Locations[n].id);

	//Reload map
	Locations[n].reload.l1.go = "Guadeloupe_Port";
	Locations[n].reload.l1.label = "#stown_name#";

	Locations[n].island = "Guadeloupe";
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "PaP_church";
	locations[n].id.label = "#stown_name# church";
	//Town sack
	Locations[n].townsack = "Pointe a Pitre";
	//Sound
	locations[n].type = "Church";
	locations[n].fastreload = "Pointe_a_Pitre";

	InitChurch1(Locations[n].id);

	//Reload map
	Locations[n].reload.l1.go = "Guadeloupe_Port";
	Locations[n].reload.l1.label = "#stown_name#";

	Locations[n].island = "Guadeloupe";
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "PaP_usurer";
	locations[n].id.label = "Loanshark's Office";
	//Town sack
	Locations[n].townsack = "Pointe a Pitre";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Pointe_a_Pitre";

	InitBank(Locations[n].id);

	//Reload map
	Locations[n].reload.l1.go = "Guadeloupe_Port";
	Locations[n].reload.l1.label = "#stown_name#";

	Locations[n].island = "Guadeloupe";
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "PaP_Storehouse";
	locations[n].id.label = "Storehouse";
	//Town sack
	Locations[n].townsack = "Pointe a Pitre";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Pointe_a_Pitre";

	InitStorehouse(Locations[n].id);

	//Reload map
	Locations[n].reload.l1.go = "Guadeloupe_Port";
	Locations[n].reload.l1.label = "#stown_name#";

	Locations[n].island = "Guadeloupe";
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "PaP_Academy";
	locations[n].id.label = "Naval academy";
	//Town sack
	Locations[n].townsack = "Pointe a Pitre";
	//Sound
	locations[n].type = "residence";
	locations[n].fastreload = "Pointe_a_Pitre";

	InitShipyard4(Locations[n].id);

	//Reload map
	Locations[n].reload.l1.go = "Guadeloupe_Port";
	Locations[n].reload.l1.emerge = "academy";
	Locations[n].reload.l1.label = "#stown_name#";

	Locations[n].island = "Guadeloupe";
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "PaP_Brothel_bedroom";
	if (IsBrothelEnabled()) {
		locations[n].id.label = "Brothel Bedroom";
		//Town sack
		Locations[n].townsack = "Pointe a Pitre";
		//Sound
		locations[n].type = "room";
		locations[n].fastreload = "Pointe_a_Pitre";
		LAi_LocationFantomsGen(&locations[n], false);

		InitBrothelRoom(Locations[n].id);

		Locations[n].island = "Guadeloupe";
	}
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].id = "PaP_Brothel_room";
	if (IsBrothelEnabled()) {
		locations[n].id.label = "#stown_name# Brothel";
		Locations[n].filespath.models = "locations\inside\den";
		Locations[n].image = "Inside_Den_Room.tga"; // PB
		//Town sack
		Locations[n].townsack = "Pointe a Pitre";
		//Sound
		locations[n].type = "room";
		locations[n].fastreload = "Pointe_a_Pitre";
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

		LAi_LocationFightDisable(&Locations[n], true);

		Locations[n].island = "Guadeloupe";
	}
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "PaP_Brothel";
	if (IsBrothelEnabled()) InitPaPBrothel(); // KK
	n = n + 1;

	//  -------------------------------------------------

	Locations[n].id = "StoneHouse";
	locations[n].id.label = "House";
	//Town sack
	Locations[n].townsack = "Pointe a Pitre";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Pointe_a_Pitre";

	InitStoneHouse(Locations[n].id);

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Guadeloupe_port";
	Locations[n].reload.l1.emerge = "houseS1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].island = "Guadeloupe";
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Pointe_a_pitre_Tavern";
	locations[n].id.label = "#stown_name# tavern";
	//Town sack
	Locations[n].townsack = "Pointe a Pitre";
	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "Pointe_a_pitre";

	InitTavern02(Locations[n].id);

	//Reload map
	Locations[n].reload.l1.go = "Guadeloupe_port";
	Locations[n].reload.l1.label = "#stown_name#";
	//fake reload_to_room

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Pointe_a_pitre_tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Room in #stown_name# tavern.";
	Locations[n].reload.l2.disable = true; // KK

	Locations[n].island = "Guadeloupe";
	n = n + 1;

	// -------------------------------------------------
	Locations[n].id = "Pointe_a_pitre_store";
	locations[n].id.label = "#stown_name# store";
	//Town sack
	Locations[n].townsack = "Pointe a Pitre";
	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Pointe_a_pitre";

	InitStore02(Locations[n].id);

	//Reload map
	Locations[n].reload.l1.go = "Guadeloupe_port";
	Locations[n].reload.l1.label = "#stown_name#.";

	Locations[n].island = "Guadeloupe";
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\outside\Plantation";

	Locations[n].id = "Guadeloupe_Plantation";
	locations[n].id.label = "Plantation";
	Locations[n].image = "Outside_Plantation.tga";

	//Town sack
	Locations[n].townsack = "Pointe a Pitre";

	//Sound
	locations[n].type = "jungle";
	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Models
	//Always
	Locations[n].models.always.locators = "Plantation_locators";
	Locations[n].models.always.jungle = "Plantation";
	Locations[n].models.always.grassPatch = "Plantation_grass";

	Locations[n].models.always.Waterfall1 = "waterfall";
	Locations[n].models.always.Waterfall1.uvslide.u0 = 0.3;
	Locations[n].models.always.Waterfall1.tech = "LocationWaterFall";
	Locations[n].models.always.Waterfall1.level = 50;

	Locations[n].models.always.l1 = "Plan1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "Plan2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "Plan3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";
	Locations[n].models.always.l4 = "Plan4";
	Locations[n].models.always.l4.level = 6;
	Locations[n].models.always.l4.tech = "LocationModelBlend";

//	Locations[n].models.always.l5 = "Plantation_gateclouse"; // not necessary
	Locations[n].models.always.l6 = "Plantation_reflect";
	Locations[n].models.always.l7 = "Plantation_gateopen";

	//Day
	Locations[n].models.day.charactersPatch = "Plantation_patchopen";
	Locations[n].models.day.fonar = "Plantation_fd";
	//Night
	Locations[n].models.night.charactersPatch = "Plantation_patchopen";
	Locations[n].models.night.fonar= "Plantation_fn";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].MaxSeaHeight = 0; // screwface

	//Reload map
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Guadeloupe_port";
	Locations[n].reload.l1.emerge = "gate";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Guadeloupe_Jungle_01";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle";

	Locations[n].reload.l3.name = "HouseSp1";
	Locations[n].reload.l3.go = "Guadeloupe_Plantation_inside";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Enter.";
	Locations[n].reload.l3.close_for_night = 1;

	Locations[n].locators_radius.goto.goto25 = 3.0;//SJG

	Locations[n].island = "Guadeloupe"; // NK 04-08-29
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Jungle_5";
	Locations[n].filespath.textures = "locations\JUNGLES";

	Locations[n].id = "Guadeloupe_Jungle_01";
	locations[n].id.label = "Jungle";
	Locations[n].image = "Outside_Jungle_5.tga";
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
	Locations[n].reload.l1.go = "Guadeloupe_Jungle_03";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1 = 3.0;

	if (GetCurrentPeriod() == PERIOD_EARLY_EXPLORERS)
	{
		Locations[n].reload.l1.name = "reload1";
		Locations[n].reload.l1.go = "Guadeloupe_shore_01";
		Locations[n].reload.l1.emerge = "locator3";
		Locations[n].reload.l1.autoreload = "1";
		Locations[n].reload.l1.label = "Ensenada del Bosque Quebrado.";
		Locations[n].locators_radius.reload.Reload1 = 3.0;

		Locations[n].reload.l4.name = "reload1_back";
		Locations[n].reload.l4.go = "Guadeloupe_shore_01";
		Locations[n].reload.l4.emerge = "locator3";
		Locations[n].reload.l4.autoreload = "1";
		Locations[n].reload.l4.label = "Ensenada del Bosque Quebrado.";
		Locations[n].locators_radius.reload.Reload1_back = 2.0;

		Locations[n].reload.l2.name = "reload2";
		Locations[n].reload.l2.go = "Guadeloupe_shore_02";
		Locations[n].reload.l2.emerge = "reload2";
		Locations[n].reload.l2.autoreload = "1";
		Locations[n].reload.l2.label = "Bahía Grande.";
		Locations[n].locators_radius.reload.reload2 = 3.0;

		Locations[n].reload.l5.name = "reload2_back";
		Locations[n].reload.l5.go = "Guadeloupe_shore_02";
		Locations[n].reload.l5.emerge = "reload2";
		Locations[n].reload.l5.autoreload = "1";
		Locations[n].reload.l5.label = "Bahía Grande.";
		Locations[n].locators_radius.reload.Reload3_back = 2.0;
	}
	else
	{
		Locations[n].reload.l1.name = "reload1";
		Locations[n].reload.l1.go = "Guadeloupe_Jungle_03";
		Locations[n].reload.l1.emerge = "reload2";
		Locations[n].reload.l1.autoreload = "1";
		Locations[n].reload.l1.label = "Jungle.";
		Locations[n].locators_radius.reload.Reload1 = 3.0;

		Locations[n].reload.l4.name = "reload1_back";
		Locations[n].reload.l4.go = "Guadeloupe_Jungle_03";
		Locations[n].reload.l4.emerge = "reload2";
		Locations[n].reload.l4.autoreload = "1";
		Locations[n].reload.l4.label = "Jungle.";
		Locations[n].locators_radius.reload.Reload1_back = 2.0;

		Locations[n].reload.l2.name = "reload2";
		Locations[n].reload.l2.go = "Guadeloupe_Plantation"; // Screwface : was "Pointe_a_pitre_town_exit";
		Locations[n].reload.l2.emerge = "Reload2"; // was "reload1";
		Locations[n].reload.l2.autoreload = "1";
		Locations[n].reload.l2.label = "Exit from #stown_name#.";
		Locations[n].locators_radius.reload.Reload2 = 3.0;

		Locations[n].reload.l5.name = "reload2_back";
		Locations[n].reload.l5.go = "Guadeloupe_Plantation"; // Screwface : was "Pointe_a_pitre_town_exit";
		Locations[n].reload.l5.emerge = "Reload2"; // was "reload1";
		Locations[n].reload.l5.autoreload = "1";
		Locations[n].reload.l5.label = "Exit from #stown_name#.";
		Locations[n].locators_radius.reload.Reload2_back = 2.0;
	}

	Locations[n].reload.l3.name = "reload3";
	Locations[n].reload.l3.go = "Guadeloupe_Jungle_02";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload3 = 3.0;

	Locations[n].reload.l6.name = "reload3_back";
	Locations[n].reload.l6.go = "Guadeloupe_Jungle_02";
	Locations[n].reload.l6.emerge = "reload1";
	Locations[n].reload.l6.autoreload = "1";
	Locations[n].reload.l6.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload3_back = 2.0;

	Locations[n].island = "Guadeloupe";
	n = n + 1;

	//-------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Jungle_1";

	Locations[n].id = "Guadeloupe_Jungle_02";
	locations[n].id.label = "Jungle";
	Locations[n].image = "Outside_Jungle_1.tga";
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
	Locations[n].environment.sea = "true";
	Locations[n].environment.swamp = "true"; // PB: Swamps
	Locations[n].MaxSeaHeight = 0.2; // screwface

	LAi_LocationMonstersGen(&locations[n], true);
	LAi_LocationSetMonstersTime(&locations[n], 22, 6);

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Guadeloupe_Jungle_01";
	Locations[n].reload.l1.emerge = "reload3";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1 = 3.0;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Guadeloupe_Jungle_01";
	Locations[n].reload.l3.emerge = "reload3";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 2.0;

	if (GetCurrentPeriod() != PERIOD_EARLY_EXPLORERS)
	{
		Locations[n].reload.l2.name = "reload2";
		Locations[n].reload.l2.go = "Guadeloupe_Lighthouse";
		Locations[n].reload.l2.emerge = "reload1";
		Locations[n].reload.l2.autoreload = "1";
		Locations[n].reload.l2.label = "#sisland_name# lighthouse."; // KK
		Locations[n].locators_radius.reload.Reload2 = 3.0;

		Locations[n].reload.l4.name = "reload2_back";
		Locations[n].reload.l4.go = "Guadeloupe_Lighthouse";
		Locations[n].reload.l4.emerge = "reload1";
		Locations[n].reload.l4.autoreload = "1";
		Locations[n].reload.l4.label = "#sisland_name# lighthouse."; // KK
		Locations[n].locators_radius.reload.reload2_back = 2.0;
	}

	Locations[n].island = "Guadeloupe";
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\outside\Mayak";

	Locations[n].id = "Guadeloupe_Lighthouse";
	Locations[n].name = "Lighthouse";
	locations[n].id.label = "#sisland_name# lighthouse."; // KK
	Locations[n].image = "Outside_Mayak.tga";
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
	Locations[n].reload.l1.go = "Guadeloupe_Jungle_02";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload1 = 3.0;

	Locations[n].reload.l3.name = "reload1_back";
	Locations[n].reload.l3.go = "Guadeloupe_Jungle_02";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload1_back = 3.0;

//	Locations[n].reload.l4.name = "reload5";
//	Locations[n].reload.l4.go = "Lighthouse_Inside";
//	Locations[n].reload.l4.emerge = "Reload1";
//	Locations[n].reload.l4.label = "Lighthouse Inside.";
//	Locations[n].reload.l4.close_for_night = 1;
//	Locations[n].reload.l4.disable = 1;

	Locations[n].island = "Guadeloupe"; // PB Fix
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\town_QC\exit";	
	Locations[n].id = "Guadeloupe_Jungle_03";
	locations[n].id.label = "Jungle";
	Locations[n].image = "Town_QC_Exit.tga";
	//Town sack
	Locations[n].townsack = "Pointe a Pitre"; // KK
	//Sound
	locations[n].type = "jungle";
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
	Locations[n].reload.l1.go = "Guadeloupe_fakefort1"; // Screwface : was "Guadeloupe_Plantation";
	Locations[n].reload.l1.emerge = "Reloadc2"; // was "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Fort."; // was "Plantation.";

	Locations[n].reload.l2.name = "Reload2";
	Locations[n].reload.l2.go = "Guadeloupe_Jungle_01";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 3.0;

	Locations[n].reload.l3.name = "Reload3";
	Locations[n].reload.l3.go = "Guadeloupe_shore_01";
	Locations[n].reload.l3.emerge = "locator3";
	Locations[n].reload.l3.autoreload = "1";
	if(GetCurrentPeriod() == PERIOD_EARLY_EXPLORERS) Locations[n].reload.l3.label = "Ensenada del Bosque Quebrado.";
	else Locations[n].reload.l3.label = "Anse Casse-Bois.";		//spell-checked by KAM // KK
	Locations[n].locators_radius.reload.reload3 = 3.0;

	Locations[n].reload.l4.name = "Reload2_back";
	Locations[n].reload.l4.go = "Guadeloupe_Jungle_01";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Jungle.";
	Locations[n].locators_radius.reload.Reload2_back = 2.0;

	Locations[n].reload.l5.name = "Reload3_back";
	Locations[n].reload.l5.go = "Guadeloupe_shore_01";
	Locations[n].reload.l5.emerge = "locator3";
	Locations[n].reload.l5.autoreload = "1";
	if(GetCurrentPeriod() == PERIOD_EARLY_EXPLORERS) Locations[n].reload.l5.label = "Ensenada del Bosque Quebrado.";
	else Locations[n].reload.l5.label = "Anse Casse-Bois.";		//spell-checked by KAM // KK
	Locations[n].locators_radius.reload.Reload3_back = 2.0;

	Locations[n].island = "Guadeloupe";
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Residence3";

	Locations[n].id = "Guadeloupe_Plantation_inside";
	locations[n].id.label = "#sisland_name# Plantation Residence";
	Locations[n].image = "Inside_Residence3.tga";

	//Town sack
	Locations[n].townsack = "Pointe a Pitre";

	//Sound
	locations[n].type = "Residence";
	locations[n].fastreload = "Pointe_a_Pitre";
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
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Guadeloupe_Plantation";
	Locations[n].reload.l1.emerge = "HouseSp1"; // Screwface : was "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Plantation."; // was "Jungle.";

	Locations[n].reload.l2.name = "reload2";
	Locations[n].reload.l2.go = "Guadeloupe_Plantation_bedroom"; 
	Locations[n].reload.l2.emerge = "reload1"; 
	Locations[n].reload.l2.autoreload = "0"; 
	Locations[n].reload.l2.label = "Bedroom.";

	Locations[n].island = "Guadeloupe";
	n = n + 1;

	//-------------------------------------------------
	Locations[n].id = "Guadeloupe_Plantation_bedroom";
	locations[n].id.label = "Bedroom";
	Locations[n].filespath.models = "locations\inside\ResBedRoom";
	Locations[n].image = "Inside_ResBedRoom.tga";
	//Sound
	locations[n].type = "Residence";
	locations[n].fastreload = "Pointe_a_Pitre";
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
	Locations[n].reload.l1.go = "Guadeloupe_Plantation_inside";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Hall.";

	Locations[n].island = "Guadeloupe";
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Shore_4";

	Locations[n].id = "Guadeloupe_shore_01";
	locations[n].worldmap = "GuadShore 1";
	Locations[n].image = "Outside_Shore_4.tga";
	if(GetCurrentPeriod() == PERIOD_EARLY_EXPLORERS)
	{
		locations[n].id.label = "Ensenada del Bosque Quebrado.";
		Locations[n].name = "Ensenada del Bosque Quebrado";
	}
	else
	{
		locations[n].id.label = "Anse Casse-Bois.";		//spell-checked by KAM // KK
		Locations[n].name = "Anse Casse-Bois";
	}
	//Sound
	locations[n].type = "seashore";

	//Models
	//Always
	Locations[n].models.always.locators = "Shore04_l";
	Locations[n].models.always.shore = "Shore04";
	Locations[n].models.always.shore.foam = "1";
	Locations[n].models.always.seabed = "Shore04_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "Shore04_g";
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
	Locations[n].models.day.charactersPatch = "Shore04_p";
	//Night
	Locations[n].models.night.charactersPatch = "Shore04_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map

	if (GetCurrentPeriod() == PERIOD_EARLY_EXPLORERS)
	{
		Locations[n].reload.l1.name = "locator3";
		Locations[n].reload.l1.go = "Guadeloupe_Jungle_01";
		Locations[n].reload.l1.emerge = "reload1";
		Locations[n].reload.l1.autoreload = "1";
		Locations[n].reload.l1.label = "Jungle.";
		Locations[n].locators_radius.reload.locator3 = 3.0;

		Locations[n].reload.l3.name = "locator3_back";
		Locations[n].reload.l3.go = "Guadeloupe_Jungle_01";
		Locations[n].reload.l3.emerge = "reload1";
		Locations[n].reload.l3.autoreload = "1";
		Locations[n].reload.l3.label = "Jungle.";
		Locations[n].locators_radius.reload.locator3_back = 1;
	}
	else
	{
		Locations[n].reload.l1.name = "locator3";
		Locations[n].reload.l1.go = "Guadeloupe_Jungle_03";
		Locations[n].reload.l1.emerge = "reload3";
		Locations[n].reload.l1.autoreload = "1";
		Locations[n].locators_radius.reload.locator3 = 3;
		Locations[n].reload.l1.label = "Jungle.";

		Locations[n].reload.l3.name = "locator3_back";
		Locations[n].reload.l3.go = "Guadeloupe_Jungle_03";
		Locations[n].reload.l3.emerge = "reload3";
		Locations[n].reload.l3.autoreload = "1";
		Locations[n].locators_radius.reload.locator3_back = 1;
		Locations[n].reload.l3.label = "Jungle.";
	}

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Guadeloupe";
	Locations[n].reload.l2.emerge = "reload_3";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].locators_radius.reload.boat = 9.0;
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";

	Locations[n].island = "Guadeloupe";
	n = n + 1;

	// ccc fake forts--------------------------------------
	//ID
	Locations[n].id = "Guadeloupe_fakefort1";		//new ID
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";	//A warning sign at the gate :)
	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_1";
	Locations[n].image = "Fort_Inside_Fort_1.tga";

	//Town sack
	Locations[n].townsack = "Pointe a Pitre";		//change
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
	Locations[n].reload.l1.go = "Guadeloupe_Jungle_03"; // was "Pointe_a_pitre_town_02";
	Locations[n].reload.l1.emerge = "reload1"; // "Falaise_de_fleur_location_04_05";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reloadC4";
	Locations[n].reload.l2.go = "Guadeloupe_fakefort2";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l3.name = "reloadc5";
	Locations[n].reload.l3.go = "Guadeloupe_armory";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].reload.l4.name = "reloadc1";
	Locations[n].reload.l4.go = "Guadeloupe_fakefort3";
	Locations[n].reload.l4.emerge = "reloadc1";
	Locations[n].reload.l4.autoreload = "0";

	Locations[n].island = "Guadeloupe";
	n = n + 1;

	// ccc oxbay fake fort 2----------------------------------
	//ID
	Locations[n].id = "Guadeloupe_fakefort2";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";

	//Town sack
	Locations[n].townsack = "Pointe a Pitre";

	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_2";
	Locations[n].image = "Fort_Inside_Fort_1.tga";
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
	Locations[n].reload.l1.go = "Guadeloupe_fakefort1";
	Locations[n].reload.l1.emerge = "reloadc4";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reloadc1";
	Locations[n].reload.l2.go = "Guadeloupe_fakefort3";
	Locations[n].reload.l2.emerge = "reloadc2";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].island = "Guadeloupe";
	n = n + 1;
	
	// ccc oxbay fake fort 3----------------------------------
	//ID
	Locations[n].id = "Guadeloupe_fakefort3";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";

	//Town sack
	Locations[n].townsack = "Pointe a Pitre";

	//Info
	Locations[n].filespath.models = "locations\Fort_inside\Fort_3";
	Locations[n].image = "Fort_Inside_Fort_1.tga";
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
	Locations[n].reload.l1.go = "Guadeloupe_fakefort1";
	Locations[n].reload.l1.emerge = "reloadc1";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l2.name = "reloadc2";
	Locations[n].reload.l2.go = "Guadeloupe_fakefort2";
	Locations[n].reload.l2.emerge = "reloadc1";
	Locations[n].reload.l2.autoreload = "0";

	Locations[n].reload.l3.name = "reload1";
	Locations[n].reload.l3.go = "Guadeloupe_armory";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].island = "Guadeloupe";
	n = n + 1;

	// ccc oxbay armory-------------------------------------------------

	Locations[n].filespath.models = "locations\Inside\LargeStore";
	Locations[n].id = "Guadeloupe_armory";
	locations[n].id.label = "MILITARY AREA. NO TRESPASSING!";
	Locations[n].image = "Fort_Inside_Fort_2.tga";

	//Town sack
	Locations[n].townsack = "Pointe a Pitre";
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
	Locations[n].reload.l1.go = "Guadeloupe_fakefort1";
	Locations[n].reload.l1.emerge = "reloadc5";
	Locations[n].reload.l1.autoreload = "0";

	Locations[n].reload.l3.name = "reload2";
	Locations[n].reload.l3.go = "Guadeloupe_fakefort3";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";

	Locations[n].island = "Guadeloupe"; // NK 04-08-29
	n = n + 1;
/*
	// -------------------------------------------------
	Locations[n].id = "Pointe_a_pitre_store";
	locations[n].id.label = "Store";
	Locations[n].filespath.models = "locations\inside\LargeStore";
	Locations[n].image = "Inside_LargeStore.tga";

	//Town sack
	Locations[n].townsack = "Pointe a Pitre";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Pointe_a_pitre";
	//Models
	//Always
	Locations[n].models.always.locators = "LS_l";
	Locations[n].models.always.tavern = "LS";
	Locations[n].models.always.window = "LS_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	Locations[n].models.always.fonar = "LS_fn";
	//Day
	Locations[n].models.day.charactersPatch = "LS_p";

	//Night
	Locations[n].models.night.charactersPatch = "LS_p";

	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\ffls_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Pointe_a_pitre_town_01";
	Locations[n].reload.l1.emerge = "Door_8";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Pointe a Pitre.";
	Locations[n].locators_radius.reload.reload1 = 0.8;
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Guadeloupe"; // NK 04-08-29
	n = n + 1;
*/
	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\shipyard";

	Locations[n].id = "Pointe_a_pitre_shipyard";
	locations[n].id.label = "#stown_name# shipyard";
	Locations[n].image = "Inside_Shipyard1.tga";

	//Town sack
	Locations[n].townsack = "Pointe a Pitre";

	//Sound
	locations[n].type = "shop";
	locations[n].fastreload = "Pointe_a_pitre";
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
	Locations[n].reload.l1.go = "Guadeloupe_port";
	Locations[n].reload.l1.emerge = "reload5_back";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Guadeloupe";
	n = n + 1;
/*
	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\MediumTavern";

	Locations[n].id = "Pointe_a_pitre_Tavern";
	locations[n].id.label = "Tavern";
	Locations[n].image = "Inside_MediumTavern.tga";

	//Town sack
	Locations[n].townsack = "Pointe a Pitre"; // NK 04-08-29

	//Sound
	locations[n].type = "tavern";
	locations[n].fastreload = "Pointe_a_pitre";

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
	Locations[n].reload.l1.go = "Guadeloupe_PORT";
	Locations[n].reload.l1.emerge = "Door_2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Sea port.";

	//fake reload_to_room
	Locations[n].reload.l2.name = "reload2";//MAXIMUS: was "to_room"
	Locations[n].reload.l2.go = "Pointe_a_pitre_tavern_upstairs";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "0";
	Locations[n].reload.l2.label = "Room.";

	//fake reload_back_to_tavern
	Locations[n].reload.l3.name = "reload3";//MAXIMUS: was "back_to_tavern"
	Locations[n].reload.l3.go = "Pointe_a_pitre_Tavern";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Tavern.";
	Locations[n].reload.l3.disable = "1";
	LAi_LocationFightDisable(&Locations[n], true);

	Locations[n].island = "Guadeloupe";
	n = n + 1;
*/
	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\SmallHome";
	Locations[n].id = "Pointe_a_pitre_tavern_upstairs";
	locations[n].id.label = "Room in #stown_name# tavern";
	Locations[n].image = "Inside_Doubleflour_House_Room.tga";
	//Town sack
	Locations[n].townsack = "Pointe a Pitre";
	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Pointe_a_Pitre";
	//Models
	//Always
	Locations[n].models.always.locators = "SH_l";
	Locations[n].models.always.house = "SH";
	Locations[n].models.always.window = "Sh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "Sh_p";
	//Night
	Locations[n].models.night.charactersPatch = "Sh_p";
	//Environment
	Locations[n].environment.weather = "false";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\smush_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Pointe_a_pitre_Tavern";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# tavern."; // KK

	Locations[n].island = "Guadeloupe";
	n = n + 1;

	// -------------------------------------------------
	// HOUSES
	// -------------------------------------------------

	Locations[n].id = "Guadeloupe_House_01";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\Doubleflour_house";
	Locations[n].image = "Inside_Doubleflour_House_Lower.tga";

	//Town sack
	Locations[n].townsack = "Pointe a Pitre";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Pointe_a_pitre";
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
	Locations[n].reload.l1.go = "Guadeloupe_Port"; //Screwface : was "Pointe_a_pitre_town_03";
	Locations[n].reload.l1.emerge = "houseF1"; // Screwface : was "locator6";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#"; // Screwface: was "Town.";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].island = "Guadeloupe";
	n = n + 1;

	// -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\MediumHouse";
	Locations[n].id = "Guadeloupe_House_02";
	locations[n].id.label = "House";
	Locations[n].image = "Inside_MediumHouse.tga";

	//Town sack
	Locations[n].townsack = "Pointe a Pitre";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Pointe_a_pitre";
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
	Locations[n].reload.l1.go = "Guadeloupe_Port";
	Locations[n].reload.l1.emerge = Locations[FindLocation(Locations[n].reload.l1.go)].reload.l11.name;
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";

	Locations[n].island = "Guadeloupe";
	n = n + 1;

	//----------------------------------------------------
	Locations[n].id = "Guadeloupe_House_03";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\mh9";
	Locations[n].image = "Inside_mh9.tga";

	//Town sack
	Locations[n].townsack = "Pointe a Pitre";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Pointe_a_pitre";
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
	Locations[n].reload.l1.go = "Guadeloupe_port"; // Screwface : was "Pointe_a_pitre_town_01";
	Locations[n].reload.l1.emerge = "houseSp1"; // Screwface : was "door_4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#";

	Locations[n].island = "Guadeloupe";
	n = n + 1;

// Additional Buildings, works only if Buildingset is installed -----------------------
	Build_at("Guadeloupe_Jungle_03", "jungle2", "", 7.02, 0.42, -9.58, -1.16, "wild_jungles");
	Build_at("Guadeloupe_Jungle_03", "jungle2", "", 1.74, 0.67, 14.59, -2.05, "wild_jungles");
//	Build_at("Pointe_a_pitre_town_exit", "jungle2", "", 27.78, -0.40, 92.18, -2.00, "wild_jungles");
//	Build_at("Pointe_a_pitre_town_exit", "jungle2", "", 32.65, -0.22, 81.62, -2.12, "wild_jungles");
//	Build_at("Pointe_a_pitre_town_exit", "warehouse", "", 23.88, -0.36, 68.51, -1.84, "building");
//	Build_at("Pointe_a_pitre_town_exit", "farm", "", 20.78, -0.72, 86.73, -1.96, "building");
//	Build_at("Pointe_a_pitre_town_exit", "farm", "", 9.39, -0.92, 91.49, -2.68, "building");
//	Build_at("Pointe_a_pitre_town_exit", "jungle", "", 21.01, 1.72, 155.1, 0.93, "wild_jungles");
//	Build_at("Pointe_a_pitre_town_exit", "jungle", "", 24.68, 0.50, 141.78, -0.64, "wild_jungles");
	Build_at("Guadeloupe_Jungle_01", "jungle", "", 7.16, 0.12, -17.65, -0.08, "wild_jungles");
	Build_at("Guadeloupe_Jungle_01", "jungle", "", -0.11, 0.32, 8.45, -0.01, "wild_jungles");
	Build_at("Guadeloupe_Jungle_01", "jungle", "", 2.57, 0.09, -7.64, 1.45, "wild_jungles");
	Build_at("Guadeloupe_Jungle_01", "jungle", "", 0.47, 0.50, -13.45, -3.10, "wild_jungles");

	// -------------------------------------------------

	Locations[n].filespath.models = "locations\Outside\Shore_5";

	Locations[n].id = "Guadeloupe_shore_02";
	locations[n].id.label = "Bahía Grande"; // KK
	Locations[n].image = "Outside_Shore_5.tga";
	Locations[n].name = "Bahía Grande";
	locations[n].worldmap = "GuadShore 2";

	//Sound
	locations[n].type = "seashore";

	Locations[n].townsack = "Falaise de Fleur"; // KK
	//Models
	//Always
	Locations[n].models.always.jungle = "Shore05";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.locators = "Shore05_l";
	Locations[n].models.always.grassPatch = "Shore05_g";
	Locations[n].models.always.seabed = "Shore05_sb";
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
	Locations[n].models.day.charactersPatch = "Shore05_p";
	//Night
	Locations[n].models.night.charactersPatch = "Shore05_p";
	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "Guadeloupe_Jungle_01";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2 = 3;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "Guadeloupe_Jungle_01";
	Locations[n].reload.l3.emerge = "reload2";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Jungle.";
	Locations[n].locators_radius.reload.reload2_back = 3;

	Locations[n].reload.l2.name = "boat";
	Locations[n].reload.l2.go = "Guadeloupe";
	Locations[n].reload.l2.emerge = "reload_2";
	Locations[n].reload.l2.autoreload = "0";
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
	Locations[n].locators_radius.reload.boat = 9.0;


	Locations[n].island = "Guadeloupe"; // NK 04-08-29
	n = n + 1;
}
