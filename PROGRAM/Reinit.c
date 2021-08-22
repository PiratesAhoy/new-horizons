//Reinitialize
//NK -->
#include "Towns\Towntable.c"
#include "battle_interface\fast_reload_table.c"
#include "KR_Reinit.c"
//extern void InitGoods();
//extern void InitItems();
//extern void InitLocations();
extern void SL_Reinit(); // KK

void Reinit(bool start, bool show)
{
	int n,i,j,cidx;

//	ChangeName(GetMainCharacter()); // MAXIMUS interface MOD
	int oldlogs = LogsToggle; // KK
	if (show) LogsToggle = LOG_VERBOSE; // KK
	if(show && !start) Log_SetStringToLog(TranslateString("","Reinitializing..."));
	ref pc = GetMainCharacter();
	ref curchar, ch, loc;
	aref arship; // PRS3
// moved UPGRADE to bottom again, so inits are done first. 05-07-15

	// START ACTUAL REINIT *******
	// scheffnow -->
	if(DEBUG == 1)
	{
		DeleteAttribute(pc,"ResetCount");
	}
// KK -->
	TownNamesReinit();
	Preprocessor_Init();
	Trace("Gauging: preprocessor");
// <-- KK
	if(start) ReloadProgressUpdate(); // NK 05-04-06 add the spinning thingie
	Trace("Gauging: nosave");
	InitNoSaveMod();
	ch = CharacterFromID("Kanhoji Angria");
	ch.location.locator  = "goto1";
	ch = CharacterFromID("Robert Surcouf");
	ch.location.locator  = "goto1";
	ch = CharacterFromID("Yusuf Rais");
	ch.location.locator  = "goto1";
	ch = CharacterFromID("Uela de Marisco");
	ch.location.locator  = "goto1";
	ch = CharacterFromID("Victor Hugues");
	ch.location.locator  = "goto1";
	ch = CharacterFromID("Brother Nantucket"); // PB
	ch.location.locator  = "goto1";
	ch = CharacterFromID("Brother Tuck"); // PB
	ch.location.locator  = "goto1";
	// scheffnow <--

	//trace("bef init items");

	if(!start)
	{
// ccc -->
		//Levis Reinit Perks
		Trace("Gauging: perks");
		InitPerks();
		//Reinit officer types
		Trace("Gauging: officertypes");
		InitOfficerTypes();

		if(bRealBattleInterface)
		{
			BattleInterface.navigation.navigatorWidth		= RecalculateHIcon(95); // BB 192
			BattleInterface.navigation.navigatorHeight		= RecalculateVIcon(95); // BB 192
			BattleInterface.navigation.rightPos				= sti(showWindow.left)+RecalculateHIcon(95); // BB showWindow.right
			BattleInterface.navigation.topPos				= sti(showWindow.bottom)-RecalculateVIcon(180); // ccc showWindow.top
			BattleInterface.navigation.speedShowFont		= "bold_numbers";
			BattleInterface.navigation.speedOutYOffset		= RecalculateVIcon(-40); // ccc -88
			BattleInterface.navigation.shipSpeedXOffset		= RecalculateHIcon(37); // ccc 80
			BattleInterface.navigation.windSpeedXOffset		= RecalculateHIcon(-35); // ccc -80
			BattleInterface.navigation.fontScale			= 0.35; // ccc 0.75
			BattleInterface.navigation.windWidth			= 15; // ccc 30
			BattleInterface.navigation.windHeight			= 50; // ccc 120
			BattleInterface.navigation.mapRadius			= 5; // ccc 54
			BattleInterface.navigation.chargePos			= RecalculateHIcon(70)+","+RecalculateVIcon(73); //ccc 160 & 174
			BattleInterface.navigation.chargePictureSize	= "20,20"; //ccc "32,32"
			if(show) Log_SetStringToLog(XI_ConvertString("NewStatusRadar")+"...");
		}
		else
		{
			BattleInterface.navigation.navigatorWidth		= RecalculateHIcon(192);
			BattleInterface.navigation.navigatorHeight		= RecalculateVIcon(192);
			BattleInterface.navigation.rightPos				= showWindow.right;
			BattleInterface.navigation.topPos				= showWindow.top;
			BattleInterface.navigation.speedShowFont		= "bold_numbers";
			BattleInterface.navigation.speedOutYOffset		= RecalculateVIcon(-88);
			BattleInterface.navigation.shipSpeedXOffset		= RecalculateHIcon(80);
			BattleInterface.navigation.windSpeedXOffset		= RecalculateHIcon(-80);
			BattleInterface.navigation.fontScale			= 0.75;
			BattleInterface.navigation.windWidth			= 30;
			BattleInterface.navigation.windHeight			= 120;
			BattleInterface.navigation.mapRadius			= 54;
			BattleInterface.navigation.chargePos			= RecalculateHIcon(160)+","+RecalculateVIcon(174);
			BattleInterface.navigation.chargePictureSize	= "32,32";
			if(show) Log_SetStringToLog(XI_ConvertString("OldStatusRadar")+"...");
		}
// ccc <--

		if(LoadSegment("items\initItems.c"))
		{
			InitItems();
			//trace("after init items in if");
			UnloadSegment("items\initItems.c");
		}
	}
	//trace("after init items");
	// NK Prices -->
	// moved to inititems.c
	/*for(n=0; n<ITEMS_QUANTITY; n++)
	{
		if(!CheckAttribute(Items[n],"groupID")) { continue; }
		if(Items[n].groupID == BLADE_ITEM_TYPE || Items[n].groupID == GUN_ITEM_TYPE) { Items[n].price = makeint(sti(Items[n].price)/10); } // NK price tweak 04-11
		//trace(items[n].id + ", price " + Items[n].price);
	}
	// NK Prices <--
	if(show) Log_SetStringToLog("Items, some prices changed..."); // NK Prices*/
	if(!start)
	{
		if(LoadSegment("characters\Characters_tables.c"))
		{
			InitCharactersTables();
			UnloadSegment("characters\Characters_tables.c");
			if(show) Log_SetStringToLog(TranslateString("","Character Tables..."));
		}

		// KK & PB -->
		ShipsInit();
		if(!start && DEBUG)
		{
			string shiptype;
			for (i = 0; i < COMPANION_MAX; i++)
			{
				cidx = GetCompanionIndex(pc, i);
				if (cidx < 0) continue;
				ch = GetCharacter(cidx);
				if (CheckAttribute(ch, "ship.stats"))
				{
					shiptype = ch.ship.type;
					if (CheckAttribute(ch.ship.stats, "nation"))	n = sti(ch.ship.stats.nation);
					else											n = sti(ch.nation);
					makearef(arship, ch.ship);
					DeleteAttribute(arship,"stats");
					if(shiptype != SHIP_CURSED) arSetRandomStatsToShip(arship, GetShipIndex(shiptype), n);
				}
			}
		}
		// KK & PB <--

		if (LoadSegment("STORE\initGoods.c"))
		{
			InitGoods();
			UnloadSegment("STORE\initGoods.c");
		}

		if(LoadSegment("cannons\cannons_init.c"))
		{
			InitCannons();
			UnloadSegment("cannons\cannons_init.c");
			if(show) Log_SetStringToLog(TranslateString("","Cannon..."));
		}

		WeatherInit();

		if(show) Log_SetStringToLog(TranslateString("","Weather..."));

		InitLandRandomEncounters();
		if(show) Log_SetStringToLog(TranslateString("","Land Encounters..."));

		//LocationInit();
		//if(show) Log_SetStringToLog("Locations...");

		if(LoadSegment("nations\nations_init.c"))
		{
			InitNations();
			UnloadSegment("nations\nations_init.c");
			if(show) Log_SetStringToLog(TranslateString("","Nations..."));
		}
	}
	if (LoadSegment("Encounters\Encounters_init.c"))
	{
		InitEncounters();
		UnloadSegment("Encounters\Encounters_init.c");
		if(show) Log_SetStringToLog(TranslateString("","Encounters..."));
	}

	Trace("Gauging: RM mod and rumors");
//	for(n = 0; n < NATIONS_QUANTITY; n++) { SetRMRelation(GetMainCharacter(), n, GetRMRelation(GetMainCharacter(), n)); } // RM - PB: Do we need to do this?
	SetRumourDefaults(true); //states added, this will only change text, not state
	if(show) Log_SetStringToLog(TranslateString("","Rumors..."));
	if(start) ReloadProgressUpdate(); // NK 05-04-06 add the spinning thingie
	else //if(!start)
	{
		initFastReloadTable();
		if(show) Log_SetStringToLog(TranslateString("","Fast Travel..."));
	}
	// 05-07-10 do store groups
	// Dunno why this fails, but it does. OK, I'm putting the function in store.h rather than using loadsegment. 05-07-12
	//if(LoadSegment("store\store_init.c"))
	//{
		StoreInit();
		//UnloadSegment("store\store_init.c");
	//}

// added by MAXIMUS -->
		// KAM new interfaces -->
	if(bNewInterface==true)
	{
		Interfaces[INTERFACE_KAM_SELECTMODEL].SectionName = "interface\kam_selectmodel.c";
		Interfaces[INTERFACE_KAM_SELECTMODEL].IniFile = "RESOURCE\INI\NEW_INTERFACES\kam_selectmodel.ini";
		Interfaces[INTERFACE_KAM_SELECTSAILS].SectionName = "interface\kam_selectsails.c";
		Interfaces[INTERFACE_KAM_SELECTSAILS].IniFile = "RESOURCE\INI\NEW_INTERFACES\kam_selectsails.ini";
		Interfaces[INTERFACE_KAM_RATIONS].SectionName = "interface\kam_rations.c";
		Interfaces[INTERFACE_KAM_RATIONS].IniFile = "RESOURCE\INI\NEW_INTERFACES\kam_rations.ini";
		Interfaces[INTERFACE_KAM_ARTICLES].SectionName = "interface\kam_articles.c";
		Interfaces[INTERFACE_KAM_ARTICLES].IniFile = "RESOURCE\INI\NEW_INTERFACES\kam_articles.ini";
		Interfaces[INTERFACE_KAM_SHIPTRANSFER].SectionName = "interface\kam_shiptransfer.c";
		Interfaces[INTERFACE_KAM_SHIPTRANSFER].IniFile = "RESOURCE\INI\NEW_INTERFACES\kam_shiptransfer.ini";
		Interfaces[INTERFACE_KAM_SHIPBERTHING].SectionName = "interface\kam_shipberthing.c";				// added after build 11
		Interfaces[INTERFACE_KAM_SHIPBERTHING].IniFile = "RESOURCE\INI\NEW_INTERFACES\kam_shipberthing.ini";		// added after build 11
		Interfaces[INTERFACE_NEWS].SectionName = "interface\news.c";
		Interfaces[INTERFACE_NEWS].IniFile = "RESOURCE\INI\NEW_INTERFACES\news.ini";
		Interfaces[INTERFACE_MONKEY].SectionName = "interface\monkey.c";
		Interfaces[INTERFACE_MONKEY].IniFile = "RESOURCE\INI\INTERFACES\monkey.ini";
	}
	else
	{
		Interfaces[INTERFACE_KAM_SELECTMODEL].SectionName = "interface\kam_selectmodel.c";
		Interfaces[INTERFACE_KAM_SELECTMODEL].IniFile = "RESOURCE\INI\INTERFACES\kam_selectmodel.ini";
		Interfaces[INTERFACE_KAM_SELECTSAILS].SectionName = "interface\kam_selectsails.c";
		Interfaces[INTERFACE_KAM_SELECTSAILS].IniFile = "RESOURCE\INI\INTERFACES\kam_selectsails.ini";
		Interfaces[INTERFACE_KAM_RATIONS].SectionName = "interface\kam_rations.c";
		Interfaces[INTERFACE_KAM_RATIONS].IniFile = "RESOURCE\INI\INTERFACES\kam_rations.ini";
		Interfaces[INTERFACE_KAM_ARTICLES].SectionName = "interface\kam_articles.c";
		Interfaces[INTERFACE_KAM_ARTICLES].IniFile = "RESOURCE\INI\INTERFACES\kam_articles.ini";
		Interfaces[INTERFACE_KAM_SHIPTRANSFER].SectionName = "interface\kam_shiptransfer.c";
		Interfaces[INTERFACE_KAM_SHIPTRANSFER].IniFile = "RESOURCE\INI\INTERFACES\kam_shiptransfer.ini";
		Interfaces[INTERFACE_KAM_SHIPBERTHING].SectionName = "interface\kam_shipberthing.c";				// added after build 11
		Interfaces[INTERFACE_KAM_SHIPBERTHING].IniFile = "RESOURCE\INI\INTERFACES\kam_shipberthing.ini";		// added after build 11
		Interfaces[INTERFACE_NEWS].SectionName = "interface\news.c";
		Interfaces[INTERFACE_NEWS].IniFile = "RESOURCE\INI\INTERFACES\news.ini";
		Interfaces[INTERFACE_MONKEY].SectionName = "interface\monkey.c";
		Interfaces[INTERFACE_MONKEY].IniFile = "RESOURCE\INI\INTERFACES\monkey.ini";
	}
// added by MAXIMUS <--

	if (!CheckAttribute(pc,"ShipBerthing"))
	{
		Trace("Gauging: shipberthing");
		InitialiseShipBerthingData();		// added after build 11 (only runs if ship berthing data is NOT already initialised - don't wanna be deletin all the player's berthed ships...)
	}
	if(start) ReloadProgressUpdate(); // NK 05-04-06 add the spinning thingie
	// <-- KAM new interfaces

	// ccc Building Kit treasure keeper
	if(GetCharacterIndex("B_keeper") == -1)
	{
		n = FindBlankCharSlot();
		CHARACTERS_QUANTITY++; // NK 05-04-05
		if(n != -1)
		{
			makeref(ch,Characters[n]);
			ch.old.name = "Ye Keeper"; // MAXIMUS 16.10.2006
			ch.old.lastname = "o' ye Hoarde"; // MAXIMUS 16.10.2006
			ch.name 	= TranslateString("", "Ye Keeper");
			ch.lastname 	= TranslateString("", "o' ye Hoarde");
			ch.id		= "B_keeper";
			ch.model	= "admiral";
			ch.sex = "man";
			ch.act.type = "citizen";
			ch.location = "none";
			ch.location.group = "goto";
			ch.location.locator = "goto1";
			ch.dialog.filename = "B_hoardkeeper.c";
			ch.nation = ENGLAND;
			ch.rank 	= 1;
			ch.reputation = "None";
			ch.experience = "0";

			ch.skill.Leadership = 6;
			ch.skill.Fencing = 3;
			ch.skill.Sailing = 4;
			ch.skill.Accuracy = 9;
			ch.skill.Cannons = 5;
			ch.skill.Grappling = 5;
			ch.skill.Repair = 6;
			ch.skill.Defence = 8;
			ch.skill.Commerce = 7;
			ch.skill.Sneak = 8;
			ch.money = 10;
			LAi_SetStayType(ch);
			LAi_SetHP(ch, 200.0, 200.0);
			if(show) Log_SetStringToLog(TranslateString("","BK Keeper initialised."));
		}
	}

	// ccc building kit  list of buildings added upon reinitialization
	// you can add your own buildings to the list. Format:
	// Build_at(locationid, buildingid, interiorid, x coord, y, z, ay angle, aigroup);

	ref lcn = &Locations[FindLocation("Oxbay_port")];
	// TIH added toggle to this block, so that the game doesnt attempt this if its off to begin with Nov2'06
	if( ENABLE_BUILDINGSET && !CheckAttribute(lcn,"building") )
	{
		// additional buildings for Greater Oxbay locs
		// changed Feb06 : AI group "building"
		Build_at("Oxbay_suburb", "mansion", "", 64.3, 14.0, -14.4, -0.5, "building");
		Build_at("Oxbay_suburb", "mansion", "", 51.0, 14.0, 12.0, -2.9, "building");
		Build_at("Oxbay_suburb", "forest", "marketstall", 54.0, 14.0, -3.0, 1.3, "building");
		Build_at("Oxbay_suburb", "keep", "", 59.3, 15.8, -66.0, 0.1, "building");	// changed Feb06

		Build_at("Oxbay_port", "bastion", "cannon", -36.0, 4.9, 51.0, 2.8, "building");	// changed Feb06
		Build_at("Oxbay_port", "windmill", "windmillfan", -36.0, 16.0, 24.0, 1.7, "building");	// changed Feb06
		Build_at("Oxbay_port", "fence", "cannon", 21.3, 10.5, 45.4, 0.0, "building");
		Build_at("Oxbay_port", "keep", "", 59.0, 2.5, 79.5, -3.0, "building");	// changed Feb06
		Build_at("Oxbay_port", "observatory", "", 55.0, 18.0, 49.2, 1.3, "building");
		Build_at("Oxbay_port", "mansion", "", 12.3, 6.3, 25.4, 0.27, "building");
		Build_at("Oxbay_port", "workshop", "cannon", -3.5, 2.0, 52.2, 2.1, "building");

		Build_at("Greenford_suburb", "observatory", "", 1.5, 0.0, 25.7, -2.2, "building");
		Build_at("Greenford_suburb", "forest", "marketstall", -9.1, 0.1, 55.0, -2.0, "building");
 		Build_at("Greenford_suburb", "forest", "", -7.0, 0.0, 65.0, -1.5, "building");
 		Build_at("Greenford_suburb", "mansion", "", -24.8, 0.0, 55.5, 1.8, "building");
 		Build_at("Greenford_suburb", "observatory", "", 9.6, 1.15, 32.8, 1.7, "building");
 		Build_at("Greenford_suburb", "tower", "", -17.0, 1.4, 24.5, 0.1, "building");	// changed Feb06
 		Build_at("Greenford_suburb", "fence", "cannon", -20.0, 0.0, 29.0, -0.3, "building");
 		Build_at("Greenford_suburb", "fence", "", -22.0, 0.0, 28.0, -0.7, "building");
 		Build_at("Greenford_suburb", "fence", "cannon", -15.0, 0.0, 32.0, -0.4, "building");
 		Build_at("Greenford_suburb", "fence", "mine", -2.0, 0.0, 52.5, -2.5, "building");
 		Build_at("Greenford_suburb", "box", "mine", -4.1, 0.0, 56.7, -2.5, "building");
 		Build_at("Greenford_suburb", "box", "mine", 2.0, 0.0, 52.8, -2.5, "building");
// KK -->
		//Build_at("Greenford_suburb", "mansion", "", -31.19, -2.6, 28.79, 0.61, "building"); // Sulan: free Bridgetown exit
		Build_at("Greenford_suburb", "keep", "", 8.01, -0.46, 21.30, 0.61, "building");
// <-- KK

		if(show) Log_SetStringToLog(TranslateString("","Buildings for Greater Oxbay locs"));

	}
	// ccc Building Kit <-

	if(start) ReloadProgressUpdate(); // NK 05-04-06 add the spinning thingie

	// 04-12-5 this is making things worse curchar = CharacterFromID("Danielle"); curchar.alwaysload = true; LAi_LoginInCaptureTown(characterFromID("Danielle"),true); // NK 04-11-10 fix	

	if (start) {
// added by MAXIMUS -->
		GetInterfaceParameters();
		InitLocalization();
// added by MAXIMUS <--

		Trace("Gauging: fill stores");
		for(n=0; n<STORE_QUANTITY; n++)
		{
			FillStoreGoods2(&Stores[n]);
		}
		if(show) Log_SetStringToLog(TranslateString("","Stores..."));

		ReloadProgressUpdate(); // NK 05-04-06 add the spinning thingie
	}
	// MAXIMUS 20.08.2018 used for localization -->
	if(CheckAttribute(pc, "savelang"))
	{
		PostEvent("ChangeLanguage", 0, "ls", sti(pc.savelang), "");
		DeleteAttribute(pc, "savelang");
	}
	// MAXIMUS 20.08.2018 used for localization <--
	Trace("Gauging: update all towns");
	UpdateAllTowns(true);
	// NK 05-04-06 itemtrade
	Trace("Gauging: itrade update");
	UpdateAllItemTraders(IT_CLEAN_REINIT); // will clean items and itemlists from all traders. Note this will take one heck of a long time!
	
	/*SetArraySize(&Interfaces, INTERFACE_QUANTITY);
	if(LoadSegment("Interface\BaseInterface.c"))
	{
		InitBaseInterfaces_main();
		InitBaseInterfaces();
		UnloadSegment("Interface\BaseInterface.c");
		if(show) Log_SetStringToLog("Interfaces...");
	}*/

	

	// swap between USE_REAL_CANNONS 1 and 0.
	if(!start)
	{
		Trace("Gauging: KNB Cannons swap");
		i = 0; if(CheckAttribute(pc, "knbcannons")) { i = sti(pc.knbcannons); }
		if(i != USE_REAL_CANNONS)
		{
			pc.knbcannons = USE_REAL_CANNONS; // apply update
			int ocan, ocal, calattr, newcal, calidx;
			int calch;
			bool btmp;
			if(USE_REAL_CANNONS) // going to it from normal
			{
				for(i = 0; i < CHARACTERS_QUANTITY; i++)
				{
					makeref(ch, Characters[i]);
					if(!CheckAttribute(ch, "ship.stats")) continue;
					if(ch.ship.type == SHIP_NAME_NOTUSED) continue;
					makearef(arship, ch.ship);
					curchar = GetShipByID(ch.ship.type);
					calch = 0;
					btmp = false;
					if(CheckAttribute(arship,"stats.maxcaliber"))
					{
						// assume +1
						calch = 1;

						/*calattr = sti(arship.stats.maxcaliber);
						newcal = sti(curchar.maxcaliber);
						if(calattr > newcal)
						{
							calch = 1;
						}*/
					}
					ocan = sti(ch.Ship.Cannons.Type);
					newcal = sti(curchar.maxcaliber);
					calidx = GetCannonCaliberIndex(newcal);
					if(calidx + calch < CANNON_CALIBERS_MAX) { calidx += calch; arship.stats.maxcaliber = Cannon_Calibers[calidx]; }
					btmp = ocan == CANNON_TYPE_CANNON_LBS12 && sti(curchar.type.trade);
					if(!sti(curchar.type.war) || btmp) // is merchant only, or has low cannon maxcaliber and could be merch
					{
						if(calidx != -1)
						{
							if(calidx > 3) calidx = 3;
							calidx = rand(calidx);
							ch.Ship.Cannons.Type = GetCannonByTypeAndCaliber("long gun", Cannon_Calibers[calidx]);
						}
					}
					else
					{
						ch.Ship.Cannons.Type = GetCannonByTypeAndCaliber("long gun", Cannon_Calibers[calidx]);
					}
					if(!CheckAttribute(ch, "fort"))
					{
						newcal = GetCargoGoods(&ch, GOOD_BOMBS); // convert bombs to balls.
						if(newcal)
						{
							SetCharacterGoodsSimple(&ch, GOOD_BOMBS, 0);
							SetCharacterGoods(&ch, GOOD_BALLS, GetCargoGoods(&ch, GOOD_BALLS) + newcal);
						}
					}
					else
					{
						ch.Fort.Cannons.Type.1 = CANNON_TYPE_LONG_LBS42;
						ch.Fort.Cannons.Type.2 = CANNON_TYPE_CARRONADE_LBS68;
					}
				}
			}
			else // going back to normal
			{
				for(i = 0; i < CHARACTERS_QUANTITY; i++)
				{
					makeref(ch, Characters[i]);
					if(!CheckAttribute(ch, "ship.stats")) continue;
					if(ch.ship.type == SHIP_NAME_NOTUSED) continue;
					makearef(arship, ch.ship);
					curchar = GetShipByID(ch.ship.type);
					calch = 0;
					btmp = false;
					if(CheckAttribute(arship,"stats.maxcaliber")) calch = 1;
					ocan = sti(ch.Ship.Cannons.Type);
					newcal = sti(curchar.maxcaliber);
					calidx = GetCannonCaliberIndex(newcal);
					if(calidx == -1) trace("char " + ch.id + " has caliber " + ch.Ship.Cannons.Type + " with max " + newcal);
					if(calidx + calch < CANNON_CALIBERS_MAX) { calidx += calch; arship.stats.maxcaliber = Cannon_Calibers[calidx]; }
					if(!sti(curchar.type.war)) ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS12;
					else ch.Ship.Cannons.Type = GetCannonByTypeAndCaliber("culverine", Cannon_Calibers[calidx]); // this will return the normal 32 rather than nothing, because I just changed GetCann...
					if(CheckAttribute(ch, "fort"))
					{
						ch.Fort.Cannons.Type.1 = CANNON_TYPE_CULVERINE_LBS24;
						ch.Fort.Cannons.Type.2 = CANNON_TYPE_CANNON_LBS32;
					}
				}
			}
		}
	}

	// Do enc officers after all needed new chars.

	// NK now we can increase enc_officer slots if needed, kudos to Meigger for suggesting it! -->
	Trace("Gauging: Enc Officers");
	if(GetCharacterIndex("Enc_Officer_"+ (NUM_RANDOM_OFFICERS-1)) == -1)
	{
		for(int e = 0; e < NUM_RANDOM_OFFICERS; e++)
		{
			if(GetCharacterIndex("Enc_Officer_"+e) != -1) continue;
			n = FindBlankCharSlot();
			if(n == -1)
			{
				if(show) Log_SetStringToLog("Total number of officers: " + (e+1) + "; we just went over limit so that's the last one.");
				break;
			}
			CHARACTERS_QUANTITY++;
			makeref(ch,Characters[n]);
			ch.old.name = ""; // MAXIMUS 16.10.2006
			ch.old.lastname = ""; // MAXIMUS 16.10.2006
			ch.name 	= "";
			ch.lastname = "";
			ch.id		= "Enc_Officer_"+e;
			ch.model	= "";
			ch.sex = "man";
			ch.location	= "";
			ch.location.group = "";
			ch.location.locator = "";
			ch.Dialog.Filename = "";
			ch.nation = PIRATE;
			ch.rank 	= 1;
			ch.reputation = "50";
			ch.experience = "";
			ch.skill.Leadership = "";
			ch.skill.Fencing = "";
			ch.skill.Sailing = "";
			ch.skill.Accuracy = "";
			ch.skill.Cannons = "";
			ch.skill.Grappling = "";
			ch.skill.Repair = "";
			ch.skill.Defence = "";
			ch.skill.Commerce = "";
			ch.skill.Sneak = "";
		}
		if(show) Log_SetStringToLog("There are now " + (e+1) + " Encounter/Tavern Officer slots.");
	}
	// NK <--

	// TIH --> added defined slots for cabincaptains so we never run out of characters in long games
	Trace("Gauging: CabinCaptains");
	if (GetCharacterIndex("Enc_CabinCaptain_" + (CABINCAPTAINS_MAX-1)) == -1)
	{
		for(int cc = 0; cc < CABINCAPTAINS_MAX; cc++)
		{
			if(GetCharacterIndex("Enc_CabinCaptain_"+cc) != -1) continue;
			n = FindBlankCharSlot();
			if(n == -1)
			{
				if(show) Log_SetStringToLog("Total number of CabinCaptains: " + (cc+1) + "; we just went over limit so that's the last one.");
				break;
			}
			CHARACTERS_QUANTITY++;
			makeref(ch,Characters[n]);
			ch.old.name = ""; // MAXIMUS 16.10.2006
			ch.old.lastname = ""; // MAXIMUS 16.10.2006
			ch.name 	= "";
			ch.lastname = "";
			ch.id		= "Enc_CabinCaptain_" + cc;
			//ch.index = n; // TIH outcommented - this is already set when the characters array is prepopulated with empty characters Nov1'06
			ch.model	= "";
			ch.sex = "man";
			ch.location	= "";
			ch.location.group = "";
			ch.location.locator = "";
			ch.Dialog.Filename = "";
			ch.nation = PIRATE;
			ch.rank 	= 1;
			ch.reputation = "50";
			ch.experience = "";
			ch.skill.Leadership = "";
			ch.skill.Fencing = "";
			ch.skill.Sailing = "";
			ch.skill.Accuracy = "";
			ch.skill.Cannons = "";
			ch.skill.Grappling = "";
			ch.skill.Repair = "";
			ch.skill.Defence = "";
			ch.skill.Commerce = "";
			ch.skill.Sneak = "";
			Enc_Capt[cc] = n; // TIH put back as "id" is changed on these slots, so we can't find their index Nov5'06
			//Trace("Init CabinCaptain: id: " + ch.id + " index: " + ch.index);
		}
		if(show) Log_SetStringToLog("There are now " + (cc+1) + " CabinCaptains slots.");
		Last_Capt = 0;
	}
	// TIH <--

	if(start) ReloadProgressUpdate(); // NK 05-04-06 add the spinning thingie

	FindBlankCharSlot(); // to set CHARACTERS_QUANTITY correctly, just to be sure.
	FindBlankLocSlot(); // to set nLocationsNum correctly, just to be sure.
	
	/* hoboseadog section:
	ref chr;
	chr = CharacterFromID("Enc_Officer_0");
	chr.quest.officertype = OFFIC_TYPE_FIRSTMATE;
	LAi_Create_Officer(10, &chr);
	LAi_NPC_Equip(&chr, sti(chr.rank), true, 0.5);
	chr.Dialog.CurrentNode = "hired";
	chr.AbordageMode = makeint(1);
	chr.nation = PORTUGAL;
	chr.randmodel = GetModelIndex("Fanielle");
	chr.model = Models[sti(chr.randmodel)].model;
	chr.model.animation = Models[sti(chr.randmodel)].ani;
	chr.model.height = Models[sti(chr.randmodel)].height;
	chr.sex = Models[sti(chr.randmodel)].sex;
	facemaker(&chr);
	DeleteAttribute(&chr,"randmodel");
	SetRandomNameToCharacter(&chr);
	Ship_CreateForCharacter(&chr, "Frigate1", "Sea Hawk"); // KK
	SetCompanionIndex(GetMainCharacter(), -1, sti(chr.index));

	chr = CharacterFromID("Enc_Officer_1");
	chr.quest.officertype = OFFIC_TYPE_FIRSTMATE;
	LAi_Create_Officer(10, &chr);
	LAi_NPC_Equip(&chr, sti(chr.rank), true, 0.5);
	chr.Dialog.CurrentNode = "hired";
	chr.AbordageMode = makeint(1);
	chr.nation = ENGLAND;
	chr.randmodel = GetModelIndex("ladyinred");
	chr.model = Models[sti(chr.randmodel)].model;
	chr.model.animation = Models[sti(chr.randmodel)].ani;
	chr.model.height = Models[sti(chr.randmodel)].height;
	chr.sex = Models[sti(chr.randmodel)].sex;
	facemaker(&chr);
	DeleteAttribute(&chr,"randmodel");
	SetRandomNameToCharacter(&chr);
	Ship_CreateForCharacter(&chr, "Corvette2", "Sea Depredator"); // KK
	SetCompanionIndex(GetMainCharacter(), -1, sti(chr.index));*/
	LogsToggle = oldlogs;
}

//To save typing:
bool DebugLog(string ltext) //shamelessly ripped from Stone-D. Thanks, SD! :)
{
	if(DEBUGINFO) Log_SetStringToLog(ltext);
	return DEBUGINFO;
}

void TraceAndLog(string ltext) //to log _and_ trace info
{
	Log_SetStringToLog(ltext);
	trace(ltext);
}


bool ToggleLog(string ltext) //ditto, but based on LogsToggle
{
// KK -->
	bool ret = LogsToggle >= LOG_QUIET;
	if (ret) Log_SetStringToLog(ltext);
	return ret;
// <-- KK
}

void TraceIf(string ltext)
{
	if(TRACELOG) trace(ltext);
}


void Logit(string logstr)
{
	Log_SetStringToLog(TranslateString("", logstr));//MAXIMUS 22.04.2019: this will not slow down the messages output too much, but will provide text translation in one place, without editing hundreds of code lines
}

void DPDoFade()
{
	if (musicID)
	{
		SendMessage(Sound,"lll",MSG_SOUND_STOP, musicID, 0);
		//oldMusicID = musicID;
	}
	ResetSoundScheme();
	PauseAllSounds();
	if(sti(GetStorylineVar(FindCurrentStoryline(), "DISABLE_TIPS")) < 1) SetReloadNextTipsImage(); // JRH
	SetEventHandler("FaderEvent_StartFade", "DPStartFade", 0);
	SetEventHandler("FaderEvent_EndFade", "DPEndFade", 0);
	CreateEntity(&reload_fader, "fader");
	SendMessage(&reload_fader, "ls", FADER_PICTURE, FindReloadPicture("Ship_Repair.tga")); // KK
	SendMessage(&reload_fader, "lfl", FADER_OUT, RELOAD_TIME_FADE_OUT, false);
}

void DPStartFade()
{
	DelEventHandler("FaderEvent_StartFade", "DPStartFade");
	ReloadProgressStart();
//	QuestComplete("updatedays");		// GR: this is specifically for storyline quests and is defined in each storyline's "quests_reaction.c"
	CompleteQuestName("updatedays");	// GR: this is defined in "quests.c" and tries to complete the quest as common, storyline or side
}

void DPEndFade()
{
	//ReloadProgressStart();
	DelEventHandler("FaderEvent_EndFade", "DPEndFade");
	ReloadProgressUpdate();
	SendMessage(&reload_fader, "lfl", FADER_IN, RELOAD_TIME_FADE_IN, true);
	ReloadProgressEnd();
	ResumeAllSounds();
	SendMessage(Sound,"lll",MSG_SOUND_RESUME, musicID, MUSIC_CHANGE_TIME);
	PostEvent("LoadSceneSound", 500);
}

// MAXIMUS & KK -->
void BS_Reinit()
{
	if (IsEntity(GetMainCharacter())) {
		Reinit(false, false);
	} else {
		trace("Gauging: starting init");

		if (!IsEntity(GameInterface)) {
			if(LoadSegment("Interface\BaseInterface.c"))
			{
				InitBaseInterfaces_main();
				InitBaseInterfaces();
				UnloadSegment("Interface\BaseInterface.c");
				trace("Gauging: interface");
			}
		}

		GetBuildSettings();
		trace("Gauging: load build settings");
		InitPeriods();
		trace("Gauging: periods");
		NationsInit();
		trace("Gauging: nations");
		TownNamesReinit();
		Preprocessor_Init();
		trace("Gauging: preprocessor");
		EncountersInit();
		trace("Gauging: enc");
		CannonsInit();
		trace("Gauging: cann");
		if(LoadSegment("store\initGoods.c"))
		{
			InitGoods();
			UnloadSegment("store\initGoods.c");
			trace("Gauging: goods");
		}
		ShipsInit();
		trace("Gauging: ships");
		IslandsInit();
		trace("Gauging: islands");
		WeatherInit();
		trace("Gauging: weather");
		Alias_Init();
		trace("Gauging: Aliases");
		InitSound();
		Trace("Gauging: sound");
	}
}
// <-- MAXIMUS & KK

// KK -->
void TownNamesReinit()
{
	int i = 0;
	for (i = 0; i < TOWNS_QUANTITY; i++) {
		if (XI_ConvertString(Towns[i].id) == Towns[i].name) Towns[i].name = FindTownName(Towns[i].id);
	}
}
// <-- KK
