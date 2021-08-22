//******************************************************************************************************
//	"PotCMovie"			New Pirates of the Caribbean Music Pack By:  Legendary_Spider
//******************************************************************************************************

void InitOptionalMusic()
{
	ref tmpref; makeref(tmpref, Music_Alias);

	//============ MAIN MENU ========================
	// added by NK so it can be done in code.
	tmpref.music_main_menu.f1.name = "MUSIC\PotCMovie\POC_Main_Theme.ogg";

	//============ MAIN THEME ========================
	tmpref.music_main_theme.f1.name = "MUSIC\PotCMovie\POC_Main_Theme.ogg";

	tmpref.music_eng_town.f1.name = "MUSIC\PotCMovie\POC_Eng_Town.ogg";
	tmpref.music_eng_town.f2.name = "MUSIC\PotCMovie\POC_Eng_Town2.ogg"; // SJG: From PotC

	tmpref.music_fra_town.f1.name = "MUSIC\PotCMovie\POC_Fra_Town.ogg";
	tmpref.music_fra_town.f2.name = "MUSIC\PotcMovie\POC_Hol_Town2.ogg";

	tmpref.music_spa_town.f1.name = "MUSIC\PotCMovie\POC_Spa_Town.ogg";
	tmpref.music_spa_town.f2.name = "MUSIC\PotCMovie\POC_Spa_Town.ogg";
	tmpref.music_spa_town.f3.name = "MUSIC\PotCMovie\POC_Spa_Town.ogg";
	
	tmpref.music_pir_town.f1.name = "MUSIC\PotCMovie\POC_Pir_Town.ogg";
	tmpref.music_pir_town.f2.name = "MUSIC\PotCMovie\POC_Pir_Town.ogg";

	tmpref.music_hol_town.f1.name = "MUSIC\PotCMovie\POC_Hol_Town.ogg";
	tmpref.music_hol_town.f2.name = "MUSIC\PotCMovie\POC_Hol_Town2.ogg";
	
	tmpref.music_por_town.f1.name = "MUSIC\PotCMovie\POC_Fra_Town.ogg";
	tmpref.music_por_town.f2.name = "MUSIC\PotCMovie\POC_Eng_Town.ogg";
	tmpref.music_por_town.f3.name = "MUSIC\PotCMovie\POC_Hol_Town.ogg";

	tmpref.music_usa_town.f1.name = "MUSIC\PotCMovie\POC_Usa_Town.ogg";
	tmpref.music_usa_town.f2.name = "MUSIC\PotCMovie\POC_Eng_Town2.ogg"; // SJG: From PotC
	tmpref.music_usa_town.f3.name = "MUSIC\PotCMovie\POC_Fra_Town.ogg";
	
	tmpref.music_swe_town.f1.name = "MUSIC\PotCMovie\POC_Eng_Town2.ogg"; // SJG: From PotC

	tmpref.music_house.f1.name = "MUSIC\PotCMovie\POC_Gorod-2.ogg";
	tmpref.music_house.f2.name = "MUSIC\PotCMovie\POC_Jungle.ogg";
	tmpref.music_house.f3.name = "MUSIC\PotCMovie\POC_Enplavanie.ogg";
	//============ SHOP, TAVERN, SHIPYARD ============

	tmpref.music_shop.f1.name = "MUSIC\PotCMovie\POC_Port-1.ogg";
	tmpref.music_shop.f2.name = "MUSIC\PotCMovie\POC_Port-1.ogg";

	tmpref.music_tavern.f1.name = "MUSIC\PotCMovie\POC_Port-1.ogg";	
	//============ CHURCH ============================
	tmpref.music_church.f1.name = "MUSIC\PotCMovie\POC_Church_Theme.ogg";
	tmpref.music_church.f2.name = "MUSIC\PotCMovie\POC_Church_Theme.ogg";
	
	tmpref.music_Turks_church.f1.name = "MUSIC\PotCMovie\POC_Enplavanie.ogg";					// JRH

	//============ CAVES, DUNGEON ====================
	tmpref.music_dungeon.f1.name = "MUSIC\PotCMovie\POC_Cave_or_Dungeon_Walking.ogg";

	//============ INCA TEMPLE, CAVES, DUNGEON, JAIL =======
	tmpref.inca_temple.f1.name = "MUSIC\PotCMovie\POC_Cave_or_Dungeon_Walking.ogg";
	
	//============= GOVERNORS =========================
	tmpref.music_english_governor.f1.name = "MUSIC\PotCMovie\POC_Eng_Town.ogg";
	tmpref.music_english_governor.f2.name = "MUSIC\PotCMovie\POC_Hol_Town.ogg";

	tmpref.music_french_governor.f1.name = "MUSIC\PotCMovie\POC_Eng_Town.ogg";
	tmpref.music_french_governor.f2.name = "MUSIC\PotCMovie\POC_Hol_Town.ogg";

	tmpref.music_spanish_governor.f1.name = "MUSIC\PotCMovie\POC_Eng_Town.ogg";

	tmpref.music_pirate_governor.f1.name = "MUSIC\PotCMovie\POC_Eng_Town.ogg";

	tmpref.music_dutch_governor.f1.name = "MUSIC\PotCMovie\POC_Eng_Town.ogg";
	tmpref.music_dutch_governor.f2.name = "MUSIC\PotCMovie\POC_Hol_Town.ogg";

	tmpref.music_portugal_governor.f1.name = "MUSIC\PotCMovie\POC_Eng_Town.ogg";
	tmpref.music_portugal_governor.f2.name = "MUSIC\PotCMovie\POC_Hol_Town.ogg";

	tmpref.music_american_governor.f1.name = "MUSIC\PotCMovie\POC_Eng_Town.ogg";
	tmpref.music_american_governor.f2.name = "MUSIC\PotCMovie\POC_Hol_Town.ogg";

	//============= JUNGLE SHORE, JUNGLE ===============
	tmpref.music_jungle.f1.name = "MUSIC\PotCMovie\POC_Jungle.ogg";
	tmpref.music_jungle.f2.name = "MUSIC\PotCMovie\POC_Jungle_Shore_Exploration.ogg";
	tmpref.music_jungle.f3.name = "MUSIC\PotCMovie\POC_Jungle_Shore_Exploration.ogg";

	tmpref.music_indian.f1.name = "MUSIC\PotCMovie\POC_Jungle_Shore_Exploration.ogg";
	tmpref.music_indian.f2.name = "MUSIC\PotCMovie\POC_Jungle.ogg";						

	//============= MAP ================================
	tmpref.music_map.f1.name = "MUSIC\PotCMovie\POC_Spokplavanie.ogg";
	tmpref.music_map.f2.name = "MUSIC\PotCMovie\POC_Enplavanie.ogg";

	//============= SEA =================================
	tmpref.music_day_sailing.f1.name = "MUSIC\PotCMovie\POC_Spokplavanie.ogg";
	tmpref.music_day_sailing.f2.name = "MUSIC\PotCMovie\POC_Enplavanie.ogg";
	tmpref.music_day_sailing.f3.name = "MUSIC\PotCMovie\POC_Spokplavanie.ogg";
	tmpref.music_day_sailing.f4.name = "MUSIC\PotCMovie\POC_Enplavanie.ogg";						

	tmpref.music_night_sailing.f1.name = "MUSIC\PotCMovie\POC_Enplavanie.ogg";
	tmpref.music_night_sailing.f2.name = "MUSIC\PotCMovie\POC_Enplavanie.ogg";
	tmpref.music_night_sailing.f3.name = "MUSIC\PotCMovie\POC_Enplavanie.ogg";

	tmpref.music_fog_sailing.f1.name = "MUSIC\PotCMovie\POC_Enplavanie.ogg";
	tmpref.music_fog_sailing.f2.name = "MUSIC\PotCMovie\POC_Spokplavanie.ogg";
	tmpref.music_fog_sailing.f3.name = "MUSIC\PotCMovie\POC_Enplavanie.ogg";

	//============= STORM ==============================
	tmpref.music_storm.f1.name = "MUSIC\PotCMovie\POC_Storm.ogg";
	tmpref.music_storm.f2.name = "MUSIC\PotCMovie\POC_Storm.ogg";								// PB: Cutthroat Island
	tmpref.music_storm.f3.name = "MUSIC\PotCMovie\POC_Storm.ogg";								// LS: PotC

	//============= END_STORM ==============================
	tmpref.music_End_storm.f1.name = "MUSIC\PotCMovie\POC_End_storm.ogg";

	//============= FIGHTING ===========================
	tmpref.music_bitva.f1.name = "MUSIC\PotCMovie\POC_Bitva1.ogg";
	tmpref.music_bitva.f2.name = "MUSIC\PotCMovie\POC_Bitva2.ogg";

	//============= ABORDAGE ============================
	tmpref.music_abordage.f1.name = "MUSIC\PotCMovie\POC_Abordage.ogg";
	tmpref.music_abordage.f2.name = "MUSIC\PotCMovie\POC_Board_&_Capture.ogg";
	tmpref.music_abordage.f3.name = "MUSIC\PotCMovie\POC_Paluba.ogg";

	//============= SEA BATTLE =========================
	tmpref.music_sea_battle.f1.name = "MUSIC\PotCMovie\POC_Sea_battle01.ogg";
	tmpref.music_sea_battle.f2.name = "MUSIC\PotCMovie\POC_Sea_battle02.ogg";
	tmpref.music_sea_battle.f3.name = "MUSIC\PotCMovie\POC_Sea_battle03.ogg";
	tmpref.music_sea_battle.f4.name = "MUSIC\PotCMovie\POC_Sea_battle01.ogg";
	tmpref.music_sea_battle.f5.name = "MUSIC\PotCMovie\POC_Sea_battle01.ogg";

	//============== SHIP_VICTORY ======================
	tmpref.music_ship_victory.f1.name = "MUSIC\PotCMovie\POC_Ship_victory01.ogg";
	tmpref.music_ship_victory.f2.name = "MUSIC\PotCMovie\POC_Ship_victory03.ogg";
	tmpref.music_ship_victory.f3.name = "MUSIC\PotCMovie\POC_Ship_victory01.ogg";

	//============== SHIP_DEAD ==========================
	tmpref.music_ship_dead.f1.name = "MUSIC\PotCMovie\POC_Ship_dead.ogg";

	//============== VICTORY ============================
	tmpref.music_victory.f1.name = "MUSIC\PotCMovie\POC_End_Storm.ogg";

	//============== DEATH ===============================
	tmpref.music_death.f1.name = "MUSIC\PotCMovie\POC_Ship_Dead.ogg";

	//============ TREASURE CAVE =======
	tmpref.music_treasure_cave.f1.name = "MUSIC\PotCMovie\POC_Cave_or_Dungeon_Walking.ogg";

	//============ ABORDAGE =======
	tmpref.music_land_abordage.f1.name = "MUSIC\PotCMovie\POC_Abordage.ogg";

	trace("InitOptionalMusic: now " + GetAttributesNum(tmpref) + " entries.");
}

void RegisterOptionalMusicScheme()
{
	ref rms; makeref(rms, registered_music_schemes);
	int n = GetAttributesNum(rms);
	string lnode = "l" + n;
	rms.(lnode).id = "potcmovie";
	rms.(lnode).resdir = "PotCMovie";
	switch (LanguageGetLanguage())
	{
		case "Polish":
			rms.(lnode).name = "Piraci z Karaibуw";
		break;
		// default:
			rms.(lnode).name = "Pirates of the Caribbean";
	}
}
