// ******* ORIGINAL SECTION *************

void InitMusic()
{
	ref tmpref; makeref(tmpref, Music_Alias);
	DeleteAttribute(tmpref, "");

	//============ MAIN MENU ========================
	// added by NK so it can be done in code.
	tmpref.music_main_menu.f1.name = "MUSIC\Main_Title.ogg";						// PB: Cutthroat Island

	//============ MAIN THEME ========================
	tmpref.music_main_theme.f1.name = "MUSIC\Main_Theme.ogg";

	//============ BARTOLOMEU MAIN THEME ==============
	tmpref.music_Bart_main_theme.f1.name = "MUSIC\Hispaniola.ogg";

	//=========================| WOODES ROGERS QUEST |========================//JRH -->
	tmpref.silence.f1.name = "MUSIC\silence.ogg";

	tmpref.music_brothel_QC.f1.name = "MUSIC\brothel_castanets.ogg";

	tmpref.music_brothel_room_QC.f1.name = "MUSIC\brothel_guitar.ogg";

	tmpref.music_brothel_shop.f1.name = "MUSIC\brothel_harpsichord.ogg";

	tmpref.music_blues.f1.name = "MUSIC\blues.ogg";

	tmpref.Rogers_residence.f1.name = "MUSIC\wr_residence.ogg";

	tmpref.Rogers_private.f1.name = "MUSIC\wr_private.ogg";

	tmpref.Rogers_study.f1.name = "MUSIC\wr_study.ogg";

	tmpref.Rogers_shop.f1.name = "MUSIC\wr_shop.ogg";

	tmpref.Rogers_cellar.f1.name = "MUSIC\wr_cellar.ogg";

	tmpref.Rogers_crew.f1.name = "MUSIC\wr_crew1.ogg";
	tmpref.Rogers_crew.f2.name = "MUSIC\wr_crew2.ogg";
	tmpref.Rogers_crew.f3.name = "MUSIC\wr_crew3.ogg";
	tmpref.Rogers_crew.f4.name = "MUSIC\wr_crew4.ogg";

	tmpref.Rogers_gunroom.f1.name = "MUSIC\wr_gunroom.ogg";

	tmpref.Rogers_neutral.f1.name = "MUSIC\Spokplavanie.ogg";

	tmpref.prison_ships.f1.name = "MUSIC\prison_ships.ogg";

	tmpref.Blackbeard_scene.f1.name = "MUSIC\Blackbeard.ogg";

	tmpref.San_Felipe_scene.f1.name = "MUSIC\San_Felipe.ogg";

	tmpref.blue_cavern.f1.name = "MUSIC\blue_cavern.ogg";

	tmpref.Rogers_mine.f1.name = "MUSIC\wr_mine.ogg";

	tmpref.Vane_outside.f1.name = "MUSIC\Vane_outside.ogg";

	tmpref.Vane_church.f1.name = "MUSIC\Vane_church.ogg";

	tmpref.Vane_chapel.f1.name = "MUSIC\Vane_chapel.ogg";

	tmpref.Vane_temple.f1.name = "MUSIC\Vane_temple.ogg";

	tmpref.Vane_towers.f1.name = "MUSIC\Vane_towers.ogg";

	tmpref.Claire_theme.f1.name = "MUSIC\Claire_theme.ogg";

	tmpref.Defoe_theme.f1.name = "MUSIC\Defoe_theme.ogg";

	tmpref.military.f1.name = "MUSIC\drums.ogg";

	tmpref.indian_theme.f1.name = "MUSIC\indian_theme.ogg";

	tmpref.Rogers_ships.f1.name = "MUSIC\Rogers_ships.ogg";

	tmpref.Rogers_corvette.f1.name = "MUSIC\Rogers_corvette.ogg";

	tmpref.Rogers_galleon.f1.name = "MUSIC\Rogers_galleon.ogg";

	tmpref.choir.f1.name = "MUSIC\choir.ogg";

	tmpref.Swe_inside.f1.name = "MUSIC\Swe_inside.ogg";

	tmpref.burning_cave.f1.name = "MUSIC\burning_cave.ogg";

	tmpref.rush_seashore.f1.name = "MUSIC\Bitva2.ogg";

	tmpref.attack_seashore.f1.name = "MUSIC\cutthroats.ogg";

	//=========================| WOODES ROGERS QUEST |========================//<-- JRH

	//============================| GOLDBUG QUEST |===========================//JRH -->
	tmpref.Charleston_port.f1.name = "MUSIC\Coridor.ogg";

	tmpref.Sullivan_seashore.f1.name = "MUSIC\Sullivan_seashore.ogg";

	tmpref.Sullivan_jungle.f1.name = "MUSIC\Sullivan_jungle.ogg";

	tmpref.Legrands_house.f1.name = "MUSIC\Legrands_house.ogg";

	tmpref.Fort_Moultrie.f1.name = "MUSIC\Fort_Moultrie.ogg";

	tmpref.Fort_Moultrie_village.f1.name = "MUSIC\Fort_Moultrie_village.ogg";

	tmpref.Fort_Moultrie_barracks.f1.name = "MUSIC\Two_Hornpipes_(Tortuga).ogg";

	tmpref.Charleston_town.f1.name = "MUSIC\Charleston_town.ogg";

	tmpref.Charleston_brothel.f1.name = "MUSIC\Charleston_brothel.ogg";

	tmpref.Plantation.f1.name = "MUSIC\Plantation.ogg";
	
	tmpref.night_sneaking.f1.name = "MUSIC\night_sneaking.ogg";

	tmpref.Chinatown.f1.name = "MUSIC\Chinatown.ogg";

	tmpref.Chinese_restaurant.f1.name = "MUSIC\Chinese_restaurant.ogg";

	tmpref.Poe_home.f1.name = "MUSIC\Poe_home.ogg";

	//============================| GOLDBUG QUEST |===========================//<-- JRH

	//============================| DEVLIN QUEST |===========================//BTP -->
	tmpref.OP_celtic.f1.name = "MUSIC\op_celtictheme.ogg";

	tmpref.OP_road.f1.name = "MUSIC\op_roadtheme.ogg";

	tmpref.OP_village.f1.name = "MUSIC\op_villagetheme.ogg";

	tmpref.OP_wood.f1.name = "MUSIC\op_woodtheme.ogg";


	//============================| DEVLIN QUEST |===========================//<-- BTP

	//===========================| Hornblower Quest |===========================// Grey Roger -->
	if (FindCurrentStoryline() == FindStoryline("Hornblower"))
	{
		trace("Adding Hornblower tracks");
		tmpref.Hornblower_start.f1.name = "MUSIC\Hornblower_start.ogg";
		tmpref.Hornblower_end.f1.name = "MUSIC\Hornblower_end.ogg";

		tmpref.Sharpe_verse1.f1.name = "MUSIC\sharpe_verse_1.ogg";
		tmpref.Sharpe_verse8.f1.name = "MUSIC\sharpe_verse_8.ogg";
	}

	tmpref.wedding.f1.name = "MUSIC\prince_of_denmark_march.ogg";

	//===========================| Hornblower Quest |===========================//<-- Grey Roger

	//=============================| Ardent Quest |=============================// Grey Roger -->
	if (FindCurrentStoryline() == FindStoryline("Ardent"))
	{
		trace("Adding Ardent tracks");
		tmpref.Ardent_start.f1.name = "MUSIC\The Song Of The High Seas.ogg";			// GR: Victory at Sea
		tmpref.Ardent_end.f1.name = "MUSIC\Victory At Sea.ogg";					// GR: Victory at Sea

		tmpref.music_map.f3.name = "MUSIC\Beneath The Southern Cross.ogg";			// GR: Victory at Sea
		tmpref.music_day_sailing.f5.name = "MUSIC\Mare Nostrum.ogg";				// GR: Victory at Sea
	}

	tmpref.wedding2.f1.name = "MUSIC\Pachelbel_Canon.ogg";

	//=============================| Ardent Quest |=============================// Grey Roger <--
	//=============================| Jack Sparrow |=============================// Grey Roger -->

	tmpref.Black_Pearl.f1.name = "MUSIC\Barbossa Is Hungry.ogg";						// GR: Pirates of the Caribbean

	//=============================| Jack Sparrow |=============================// Grey Roger <--

	tmpref.music_eng_town.f1.name = "MUSIC\Eng_Town.ogg";							// PB: Sea Dogs
	tmpref.music_eng_town.f2.name = "MUSIC\Eng_Town2.ogg";							// PB: Sea Dogs

	tmpref.music_fra_town.f1.name = "MUSIC\Fra_Town.ogg";							// PB: Sea Dogs
	tmpref.music_fra_town.f2.name = "MUSIC\Fra_Town2.ogg";							// Pillat: Port Royale

	tmpref.music_spa_town.f1.name = "MUSIC\Spa_Town.ogg";							// PB: Sea Dogs
	tmpref.music_spa_town.f2.name = "MUSIC\Spa_Town2.ogg";							// PB: Sea Dogs
//	tmpref.music_spa_town.f3.name = "MUSIC\Spa_Town3.ogg";							// PB: Sea Dogs
	tmpref.music_spa_town.f3.name = "MUSIC\36-BF-Townspain.ogg";						// GR: AoP Supermod

	tmpref.music_pir_town.f1.name = "MUSIC\Pir_Town.ogg";							// ASVS: Sea Dogs
	tmpref.music_pir_town.f2.name = "MUSIC\Pir_Town2.ogg";							// SJG: PotC

	tmpref.music_hol_town.f1.name = "MUSIC\Hol_Town.ogg";							// Thomas the Terror: From Efteling
	tmpref.music_hol_town.f2.name = "MUSIC\Hol_Town2.ogg";							// Thomas the Terror: From Efteling

	tmpref.music_por_town.f1.name = "MUSIC\Por_Town.ogg";							// PB: No Man's Land
	tmpref.music_por_town.f2.name = "MUSIC\Por_Town2.ogg";							// PB: No Man's Land
	tmpref.music_por_town.f3.name = "MUSIC\Por_Town3.ogg";							// PB: No Man's Land

	tmpref.music_usa_town.f1.name = "MUSIC\USA_Town.ogg";							// PB: No Man's Land
	tmpref.music_usa_town.f2.name = "MUSIC\USA_Town2.ogg";							// PB: No Man's Land
	tmpref.music_usa_town.f3.name = "MUSIC\USA_Town3.ogg";							// PB: No Man's Land

	tmpref.music_swe_town.f1.name = "MUSIC\Swe_Town.ogg";							// JRH
	
	tmpref.music_personal_town.f1.name = "MUSIC\PersonalNation\personal_town1.ogg";	// DeathDaisy: added music for personal colonies, music by Adrian von Ziegler provided by Cassadar
	tmpref.music_personal_town.f2.name = "MUSIC\PersonalNation\personal_town2.ogg";	// DeathDaisy: Andrei Kyrlov
	tmpref.music_personal_town.f3.name = "MUSIC\PersonalNation\personal_town3.ogg";	// DeathDaisy:	Derek Fiechter, provided by Cassadar
	tmpref.music_personal_town.f4.name = "MUSIC\PersonalNation\personal_town4.ogg";	// DeathDaisy: Crusader Kings 2
	tmpref.music_personal_town.f5.name = "MUSIC\PersonalNation\personal_town5.ogg";	// DeathDaisy: Witcher 3

	tmpref.music_house.f1.name = "MUSIC\Gorod-1.ogg";
	tmpref.music_house.f2.name = "MUSIC\Jungle.ogg";
	tmpref.music_house.f3.name = "MUSIC\Enplavanie.ogg";

	//=============================| Santiago Story Teller |=============================// Levis
	
	tmpref.storyteller_sad.f1.name = "MUSIC\bensound-tomorrow.ogg";
	tmpref.storyteller_fun.f1.name = "MUSIC\bensound-smile.ogg";


	//============ SHOP, TAVERN, SHIPYARD ============
	tmpref.music_shop.f1.name = "MUSIC\Taverna.ogg";
	tmpref.music_shop.f2.name = "MUSIC\Taverna2.ogg";								// Pillat: Port Royale

	tmpref.music_tavern.f1.name = "MUSIC\Town_Exploration02.ogg";
	tmpref.music_tavern.f2.name = "MUSIC\Two_Hornpipes_(Tortuga).ogg";				// PB: PotC

	tmpref.music_tavern_pirate.f1.name = "MUSIC\YoHo_instrumental.ogg";				// PB: PotC
	tmpref.music_tavern_pirate.f2.name = "MUSIC\YoHo_With_Vocals.ogg";				// PB: PotC
	tmpref.music_tavern_pirate.f2.name = "MUSIC\YoHo2.ogg";
	
	// DeathDaisy: copies of the regular tavern music, so you can add your own
	tmpref.music_tavern_personal.f1.name = "MUSIC\PersonalNation\personal_tavern1.ogg";
	tmpref.music_tavern_personal.f2.name = "MUSIC\PersonalNation\personal_tavern2.ogg";	
	
	//============ CASINO ============
	tmpref.music_casino.f1.name = "MUSIC\bensound-jazzcomedy.ogg";

	//============ CHURCH ============================
	tmpref.music_church.f1.name = "MUSIC\Church_Theme.ogg";
	tmpref.music_church.f2.name = "MUSIC\Sobor.ogg";

	tmpref.music_Turks_church.f1.name = "MUSIC\Turks_church.ogg";					// JRH

	//============ CAVES, DUNGEON ====================
	tmpref.music_dungeon.f1.name = "MUSIC\Cave_or_Dungeon_Walking.ogg";

	//============ INCA TEMPLE, CAVES, DUNGEON, JAIL =======
	tmpref.inca_temple.f1.name = "MUSIC\Coridor.ogg";

	//============= GOVERNORS =========================
	tmpref.music_english_governor.f1.name = "MUSIC\TownGovMansion-002.ogg";			// MAXIMUS: Sid Meier's Pirates
	tmpref.music_english_governor.f2.name = "MUSIC\TownGovMansion-006.ogg";			// MAXIMUS: Sid Meier's Pirates

	tmpref.music_french_governor.f1.name = "MUSIC\French_Governor.ogg";
	tmpref.music_french_governor.f2.name = "MUSIC\French_Governor2.ogg";			// PB: Cutthroat Island

	tmpref.music_spanish_governor.f1.name = "MUSIC\TownGovMansion-005.ogg";			// MAXIMUS: Sid Meier's Pirates

	tmpref.music_pirate_governor.f1.name = "MUSIC\Gorod-2.ogg";

	tmpref.music_dutch_governor.f1.name = "MUSIC\TownGovMansion-001.ogg";			// MAXIMUS: Sid Meier's Pirates
	tmpref.music_dutch_governor.f2.name = "MUSIC\TownGovMansion-007.ogg";			// MAXIMUS: Sid Meier's Pirates

	tmpref.music_portugal_governor.f1.name = "MUSIC\TownGovMansion-003.ogg";		// MAXIMUS: Sid Meier's Pirates
	tmpref.music_portugal_governor.f2.name = "MUSIC\TownGovMansion-004.ogg";		// MAXIMUS: Sid Meier's Pirates

	tmpref.music_american_governor.f1.name = "MUSIC\Governors_Theme.ogg";
	tmpref.music_american_governor.f2.name = "MUSIC\Gubernator.ogg";
	
	tmpref.music_swedish_governor.f1.name = "MUSIC\Swe_Town.ogg";						// DeathDaisy: added special music for swedish gov. using JRH swe town music
	
	tmpref.music_personal_governor.f1.name = "MUSIC\PersonalNation\personal_governor1.ogg";	// DeathDaisy: added music for personal colonies. music by Derek Fiechter
	tmpref.music_personal_governor.f2.name = "MUSIC\PersonalNation\personal_governor2.ogg";	// DeathDaisy: Derek Fiechter

	//============= JUNGLE SHORE, JUNGLE ===============
	tmpref.music_jungle.f1.name = "MUSIC\Jungle.ogg";
	tmpref.music_jungle.f2.name = "MUSIC\Jungle2.ogg";								// PB: No Man's Land
	tmpref.music_jungle.f3.name = "MUSIC\Jungle_Shore_Exploration.ogg";

	tmpref.music_indian.f1.name = "MUSIC\Jungle_Indian.ogg";						// PB: No Man's Land
	tmpref.music_indian.f2.name = "MUSIC\Jungle_Indian2.ogg";						// PB: No Man's Land

	//============= MAP ================================
	tmpref.music_map.f1.name = "MUSIC\WorldMap.ogg";								// MAXIMUS: AoP
	tmpref.music_map.f2.name = "MUSIC\WorldMap2.ogg";								// MAXIMUS: AoP

	//============= SEA =================================
	tmpref.music_day_sailing.f1.name = "MUSIC\Spokplavanie.ogg";
	tmpref.music_day_sailing.f2.name = "MUSIC\Sailing01.ogg";
	tmpref.music_day_sailing.f3.name = "MUSIC\Sailing02.ogg";
	tmpref.music_day_sailing.f4.name = "MUSIC\Sailing03.ogg";					// PB: Cutthroat Island

	tmpref.music_night_sailing.f1.name = "MUSIC\Sailing_Night.ogg";					// MAXIMUS: AoP
	tmpref.music_night_sailing.f2.name = "MUSIC\Sailing_Night2.ogg";				// PB: Sea Dogs
	tmpref.music_night_sailing.f3.name = "MUSIC\Sailing_Night3.ogg";				// PB: Sea Dogs

	tmpref.music_fog_sailing.f1.name = "MUSIC\Sailing_Fog.ogg";						// PB: Sea Dogs
	tmpref.music_fog_sailing.f2.name = "MUSIC\Sailing_Sunrise.ogg";					// PB: Sea Dogs
	tmpref.music_fog_sailing.f3.name = "MUSIC\Sailing_Storm.ogg";					// PB: Sea Dogs

	//============= STORM ==============================
	tmpref.music_storm.f1.name = "MUSIC\Storm.ogg";
	tmpref.music_storm.f2.name = "MUSIC\Storm2.ogg";								// PB: Cutthroat Island
	tmpref.music_storm.f3.name = "MUSIC\Storm3.ogg";								// LS: PotC

	//============= END_STORM ==============================
	tmpref.music_End_storm.f1.name = "MUSIC\End_storm.ogg";

	//============= FIGHTING ===========================
	tmpref.music_bitva.f1.name = "MUSIC\Bitva1.ogg";
	tmpref.music_bitva.f2.name = "MUSIC\Bitva2.ogg";

	//============= ABORDAGE ============================
	tmpref.music_abordage.f1.name = "MUSIC\Abordage.ogg";
	tmpref.music_abordage.f2.name = "MUSIC\Board_&_Capture.ogg";
	tmpref.music_abordage.f3.name = "MUSIC\Paluba.ogg";

	//============= SEA BATTLE =========================
	tmpref.music_sea_battle.f1.name = "MUSIC\Sea_battle01.ogg";
	tmpref.music_sea_battle.f2.name = "MUSIC\Sea_battle02.ogg";
	tmpref.music_sea_battle.f3.name = "MUSIC\Sea_battle03.ogg";
	tmpref.music_sea_battle.f4.name = "MUSIC\Sea_battle04.ogg";						// PB: Sea Dogs
	tmpref.music_sea_battle.f5.name = "MUSIC\Sea_battle05.ogg";						// PB: Cutthroat Island

	//============== SHIP_VICTORY ======================
	tmpref.music_ship_victory.f1.name = "MUSIC\Ship_victory01.ogg";
	tmpref.music_ship_victory.f2.name = "MUSIC\Ship_victory02.ogg";					// PB: Sea Dogs
	tmpref.music_ship_victory.f3.name = "MUSIC\Ship_victory03.ogg";

	//============== SHIP_DEAD ==========================
	tmpref.music_ship_dead.f1.name = "MUSIC\Ship_dead.ogg";

	//============== VICTORY ============================
	tmpref.music_victory.f1.name = "MUSIC\Victori.ogg";

	//============== DEATH ===============================
	tmpref.music_death.f1.name = "MUSIC\Death.ogg";

	//============ TREASURE CAVE =======
	tmpref.music_treasure_cave.f1.name = "MUSIC\Treasure_Cave.ogg";					// PB: Cutthroat Island

	//============ ABORDAGE =======
	tmpref.music_land_abordage.f1.name = "MUSIC\Abordage.ogg";

	//============ DUTCHMAN EMERGE =======
	tmpref.music_emerge_dutchman.f1.name = "MUSIC\dutchemerge.ogg";					// Pillat: PotC
	tmpref.music_emerge_dutchman.f2.name = "MUSIC\dutchemerge2.ogg";				// Pillat: PotC

	trace("InitMusic: created " + GetAttributesNum(tmpref) + " entries.");
}

void RegisterMusicScheme()
{
	ref rms; makeref(rms, registered_music_schemes);
	DeleteAttribute(rms, "");
	string lnode = "l0";
	rms.(lnode).id = "standard";
	rms.(lnode).resdir = "";
	switch (LanguageGetLanguage())
	{
		// default:
			rms.(lnode).name = "Standard";
	}
}
