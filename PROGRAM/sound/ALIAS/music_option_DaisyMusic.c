п»ї// ******* ORIGINAL SECTION *************

void InitOptionalMusic()
{
	ref tmpref; makeref(tmpref, Music_Alias);

	//============ MAIN MENU ========================
	// added by NK so it can be done in code.
	tmpref.music_main_menu.f1.name = "MUSIC\DaisyMusic\AC Black Flag Main Theme.ogg" //PB: AC Black Flag

	//============ MAIN THEME ========================
	tmpref.music_main_theme.f1.name = "MUSIC\DaisyMusic\AC Black Flag Main Theme.ogg";

	tmpref.music_eng_town.f1.name = "MUSIC\DaisyMusic\The British Empire.ogg";		// Daisy: AC Black Flag
	tmpref.music_eng_town.f2.name = "MUSIC\DaisyMusic\Celtic Ballade.ogg";			// Daisy: Lana Ross, Anne Moor & Andrei Krylov
	tmpref.music_eng_town.f3.name = "MUSIC\DaisyMusic\Nightingale.ogg";				// Daisy: Witcher 3
	tmpref.music_eng_town.f4.name = "MUSIC\DaisyMusic\Musty Scent.ogg";				// Daisy: Witcher 3
	tmpref.music_eng_town.f5.name = "MUSIC\DaisyMusic\Lay of the Free Peoples.ogg";	// Daisy: LotRO	
	tmpref.music_eng_town.f6.name = "MUSIC\DaisyMusic\Bree-land Jig.ogg";			// Daisy: LotRO
	

	tmpref.music_fra_town.f1.name = "MUSIC\DaisyMusic\Fra_Town01.ogg";				// Daisy: Sims Medieval
	tmpref.music_fra_town.f2.name = "MUSIC\DaisyMusic\Fra_Town02.ogg";				// Daisy: Sims Medieval
	tmpref.music_fra_town.f3.name = "MUSIC\DaisyMusic\Fra_Town03.ogg";				// Daisy: Sims Medieval
	tmpref.music_fra_town.f4.name = "MUSIC\DaisyMusic\Fra_Town04.ogg";				// Daisy: Sims Medieval
	tmpref.music_fra_town.f5.name = "MUSIC\DaisyMusic\Florence.ogg";				// Daisy: CK2

	tmpref.music_spa_town.f1.name = "MUSIC\DaisyMusic\Monkey Island Spanish.ogg";	// Daisy: Monkey Island Spanish Guitar
	tmpref.music_spa_town.f2.name = "MUSIC\DaisyMusic\Entre dos aguas.ogg";			// Daisy: Paco de Lucia
	tmpref.music_spa_town.f3.name = "MUSIC\DaisyMusic\Beyond the Mirage.ogg";		// Daisy: Paco de Lucia
	tmpref.music_spa_town.f4.name = "MUSIC\DaisyMusic\La Havana.ogg";				// Daisy: AC Black Flag

	tmpref.music_pir_town.f2.name = "MUSIC\DaisyMusic\A Merry Life.ogg";			// Daisy: AC Black Flag
	tmpref.music_pir_town.f3.name = "MUSIC\DaisyMusic\Meet the Sage.ogg";			// Daisy: AC Black Flag
	tmpref.music_pir_town.f4.name = "MUSIC\DaisyMusic\Nightingale.ogg";				// Daisy: Witcher 3
	tmpref.music_pir_town.f5.name = "MUSIC\DaisyMusic\Pirate That Should Not Be.ogg";	// Daisy: PotC
	tmpref.music_pir_town.f6.name = "MUSIC\DaisyMusic\Spanish Empire.ogg";			// Daisy: AC Black Flag

	tmpref.music_hol_town.f1.name = "MUSIC\DaisyMusic\Tristram.ogg";				// Daisy: Diablo Super Guitar Brothers
	tmpref.music_hol_town.f2.name = "MUSIC\DaisyMusic\Rogue Encampment.ogg";		// Daisy: Diablo Jonas Lefvert
	tmpref.music_hol_town.f3.name = "MUSIC\DaisyMusic\Home from the Hunt.ogg";		// Daisy: LotRO
	tmpref.music_hol_town.f4.name = "MUSIC\DaisyMusic\Geralt of Rivia Guitar.off";	// Daisy: Witcher 3 Jonas Lefvert
	
	tmpref.music_por_town.f1.name = "MUSIC\DaisyMusic\Seville Fantasy.ogg";			// Daisy: Andrei Krylov & Lana Ross
	tmpref.music_por_town.f2.name = "MUSIC\Por_Town2.ogg";							// PB: No Man's Land
	tmpref.music_por_town.f3.name = "MUSIC\Por_Town3.ogg";							// PB: No Man's Land
	tmpref.music_por_town.f4.name = "MUSIC\DaisyMusic\Latin Dance.ogg";				// Daisy: Andrei Krylov & Lana Ross

	tmpref.music_usa_town.f1.name = "MUSIC\DaisyMusic\USA_town-01.ogg";				// Daisy: Civ VI
	tmpref.music_usa_town.f2.name = "MUSIC\DaisyMusic\USA_town-02.ogg";				// Daisy: Civ VI
	tmpref.music_usa_town.f3.name = "MUSIC\DaisyMusic\USA_town-03.ogg";				// Daisy: Civ VI
	tmpref.music_usa_town.f4.name = "MUSIC\DaisyMusic\USA_town-04.ogg";				// Daisy: Civ VI
	tmpref.music_usa_town.f5.name = "MUSIC\DaisyMusic\USA_town-05.ogg";				// Daisy: Civ VI

	tmpref.music_house.f1.name = "MUSIC\DaisyMusic\Florence.ogg";					// Daisy: Crusader Kings 2
	tmpref.music_house.f2.name = "MUSIC\DaisyMusic\Curse of Monkey Island.ogg";		// Daisy: Monkey Island
	tmpref.music_house.f4.name = "MUSIC\DaisyMusic\The Brigands Tale.ogg";			// Daisy: LotRO

	//============ SHOP, TAVERN, SHIPYARD ============
	tmpref.music_shop.f3.name = "MUSIC\DaisyMusic\Shop Theme.ogg";				// Daisy: Zelda OoT
	tmpref.music_shop.f4.name = "MUSIC\DaisyMusic\Wares to Sell.ogg";			// Daisy: Lego Worlds
	tmpref.music_shop.f5.name = "MUSIC\DaisyMusic\Outset Island Guitar.ogg";		// Daisy: Zelda WW

	tmpref.music_tavern.f2.name = "MUSIC\DaisyMusic\Drink Up.ogg";					// Daisy: Witcher 3
	tmpref.music_tavern.f3.name = "MUSIC\DaisyMusic\Who in the What.ogg";			// Daisy: Solas
	tmpref.music_tavern.f4.name = "MUSIC\DaisyMusic\Lion's Pride.ogg";			// Daisy: WoW
	tmpref.music_tavern.f5.name = "MUSIC\DaisyMusic\Autumn Ale.ogg";			// Daisy: LotRO

	tmpref.music_tavern_pirate.f3.name = "MUSIC\DaisyMusic\All for me Grogg.ogg";		// Daisy: AC Black Flag
	tmpref.music_tavern_pirate.f4.name = "MUSIC\DaisyMusic\Pirate Bar.ogg";			// Daisy: Risen 2	
	tmpref.music_tavern_pirate.f5.name = "MUSIC\DaisyMusic\Salty Sailor.ogg";		// Daisy: WoW
	tmpref.music_tavern_pirate.f6.name = "MUSIC\DaisyMusic\Fifteen Men.ogg";		// Daisy: Sea Shanty
	tmpref.music_tavern_pirate.f7.name = "MUSIC\DaisyMusic\Teodor.ogg";			// Daisy: Pippi
	tmpref.music_tavern_pirate.f8.name = "MUSIC\DaisyMusic\Pirate Fabbe.ogg";		// Daisy: Pippi

	//============ CHURCH ============================
	tmpref.music_church.f1.name = "MUSIC\DaisyMusic\andthelordsaid.ogg";			// Daisy: CK2
	tmpref.music_church.f2.name = "MUSIC\DaisyMusic\Laetabandus.ogg";			// Daisy: Missa de Angelis

	//============ CAVES, DUNGEON ====================
	tmpref.music_dungeon.f1.name = "MUSIC\DaisyMusic\Golden Axe.ogg";			// Daisy: Conan
	tmpref.music_dungeon.f2.name = "MUSIC\DaisyMusic\Secrets of the Maya.ogg";		// Daisy: AC Black Flag
	tmpref.music_dungeon.f3.name = "MUSIC\DaisyMusic\What Lies Unseen.ogg";			// Daisy: Witcher 3

	//============= GOVERNORS =========================
	tmpref.music_english_governor.f1.name = "MUSIC\DaisyMusic\Earl of Essex.ogg";		// Daisy: John Dowland
	tmpref.music_english_governor.f2.name = "MUSIC\DaisyMusic\Lachrimae.ogg";		// Daisy: John Dowland

	tmpref.music_spanish_governor.f1.name = "MUSIC\DaisyMusic\SpanishGovernor.ogg";		// Daisy: Krylov & Ross

	tmpref.music_pirate_governor.f1.name = "MUSIC\DaisyMusic\Musty Scent.ogg";		// Daisy: Witcher 3
	tmpref.music_pirate_governor.f2.name = "MUSIC\DaisyMusic\Pirate Bar.ogg";		// Daisy: Risen 2

	tmpref.music_dutch_governor.f1.name = "MUSIC\DaisyMusic\Home from the Hunt.ogg";// Daisy: LotRO
	tmpref.music_dutch_governor.f2.name = "MUSIC\DaisyMusic\Tristam.ogg";			// Daisy: Diablo

	tmpref.music_portugal_governor.f1.name = "MUSIC\DaisyMusic\Florence.ogg";		// Daisy: CK2
	tmpref.music_portugal_governor.f2.name = "MUSIC\DaisyMusic\Fra_town03.ogg";		// Daisy: Sims Medieval

	//============= JUNGLE SHORE, JUNGLE ===============
	tmpref.music_jungle.f1.name = "MUSIC\DaisyMusic\Curse Of Monkey Island.ogg";		// Daisy: Curse of Monkey Island
	tmpref.music_jungle.f2.name = "MUSIC\DaisyMusic\Stone Fire.ogg";			// Daisy: WoW
	tmpref.music_jungle.f3.name = "MUSIC\DaisyMusic\Curse Of Monkey Island.ogg";		// Daisy: Curse of Monkey Island
	tmpref.music_jungle.f4.name = "MUSIC\DaisyMusic\Elders Hearth.ogg";			// Daisy: WoW

	tmpref.music_indian.f1.name = "MUSIC\DaisyMusic\Saltatio Vita.ogg";			// Daisy: Omnia

	//============= MAP ================================
	tmpref.music_map.f1.name = "MUSIC\DaisyMusic\Cloak and Dagger.ogg";			// Daisy: Witcher 3
	tmpref.music_map.f2.name = "MUSIC\DaisyMusic\Arise Watcher.ogg";			// Daisy: Sims Medieval

	//============= SEA =================================
	tmpref.music_day_sailing.f1.name = "MUSIC\DaisyMusic\Life at Sea.ogg";			// Daisy: AC Black Flag
	tmpref.music_day_sailing.f2.name = "MUSIC\DaisyMusic\Sea Theme.ogg";			// Daisy: Heroes of Might and Magic IV
	tmpref.music_day_sailing.f3.name = "MUSIC\DaisyMusic\Cloak and Dagger.ogg";		// Daisy: Witcher 3
	tmpref.music_day_sailing.f5.name = "MUSIC\DaisyMusic\MMExploreDay25.ogg";		// Daisy: Skyrim Mod
	tmpref.music_day_sailing.f6.name = "MUSIC\DaisyMusic\Dire Docks.ogg";			// Daisy: SM64 Tom Winter

	tmpref.music_night_sailing.f1.name = "MUSIC\DaisyMusic\The Buccaneers.ogg";		// Daisy: AC Black Flag
	tmpref.music_night_sailing.f2.name = "MUSIC\DaisyMusic\A Tuscan Night.ogg";		// Daisy: CK2
	tmpref.music_night_sailing.f3.name = "MUSIC\DaisyMusic\The Beach.ogg";			// Daisy: Risen 2
	tmpref.music_night_sailing.f4.name = "MUSIC\DaisyMusic\Vagabond.ogg";			// Daisy: Witcher 3

	tmpref.music_fog_sailing.f1.name = "MUSIC\DaisyMusic\Marked for Death.ogg";		// Daisy: AC Black Flag
	tmpref.music_fog_sailing.f2.name = "MUSIC\DaisyMusic\Islands of the West Indies.ogg";	// Daisy: AC Black Flag
	tmpref.music_fog_sailing.f3.name = "MUSIC\DaisyMusic\Outdoor.ogg";			// Daisy: Risen 2
	tmpref.music_fog_sailing.f4.name = "MUSIC\DaisyMusic\Queen Anne-calmer.ogg";		// Daisy: AC Black Flag

	//============= STORM ==============================
	tmpref.music_storm.f1.name = "MUSIC\DaisyMusic\The High Seas.ogg";			// Daisy: AC Black Flag 
	tmpref.music_storm.f3.name = "MUSIC\DaisyMusic\Storm2.ogg";				// Daisy: Risen 2

	//============= FIGHTING ===========================
	tmpref.music_bitva.f1.name = "MUSIC\DaisyMusic\AC prison fight.ogg";			// Daisy: AC Black Flag
	tmpref.music_bitva.f2.name = "MUSIC\DaisyMusic\For Toussaint.ogg";			// Daisy: Witcher 3
	tmpref.music_bitva.f3.name = "MUSIC\DaisyMusic\Under the Black Flag.ogg";		// Daisy: AC Black Flag
	tmpref.music_bitva.f4.name = "MUSIC\DaisyMusic\Silver for Monsters.ogg";		// Daisy: Witcher 3
	tmpref.music_bitva.f5.name = "MUSIC\DaisyMusic\Steel for Humans.ogg";			// Daisy: Witcher 3
	tmpref.music_bitva.f6.name = "MUSIC\DaisyMusic\War Pipes.ogg";				// Daisy: LotRO

	//============= ABORDAGE ============================
	tmpref.music_abordage.f1.name = "MUSIC\DaisyMusic\boarding01.ogg";			// Daisy: AC Black Flag
	tmpref.music_abordage.f2.name = "MUSIC\Board_&_Capture.ogg";
	tmpref.music_abordage.f3.name = "MUSIC\DaisyMusic\Pyrates Beware.ogg";			// Daisy: AC Black Flag

	//============= SEA BATTLE =========================
	tmpref.music_sea_battle.f1.name = "MUSIC\DaisyMusic\Pyrates Beware.ogg";		// Daisy: AC Black Flag
	tmpref.music_sea_battle.f2.name = "MUSIC\DaisyMusic\Order of the Assassin.ogg";		// Daisy: AC Black Flag
	tmpref.music_sea_battle.f3.name = "MUSIC\DaisyMusic\Ships of Legend.ogg";		// Daisy: AC Black Flag
	tmpref.music_sea_battle.f4.name = "MUSIC\DaisyMusic\Queen Anne-battle.ogg";		// Daisy: AC Black Flag
	tmpref.music_sea_battle.f6.name = "MUSIC\DaisyMusic\Fortune of Edward.ogg";		// Daisy: AC Black Flag
	tmpref.music_sea_battle.f7.name = "MUSIC\DaisyMusic\Fight On.ogg";			// Daisy: Lego Worlds
	tmpref.music_sea_battle.f8.name = "MUSIC\DaisyMusic\boarding01.ogg";			// Daisy: AC Black Flag

	//============== SHIP_VICTORY ======================
	tmpref.music_ship_victory.f1.name = "MUSIC\DaisyMusic\AC Victory.ogg";			// Daisy: AC Black Flag
	tmpref.music_ship_victory.f2.name = "MUSIC\DaisyMusic\victorious_neutral_3.ogg";	// Daisy: M&B
	tmpref.music_ship_victory.f4.name = "MUSIC\DaisyMusic\victorious_neutral_1.ogg";	// Daisy: M&B

	//============== SHIP_DEAD ==========================
	tmpref.music_ship_dead.f1.name = "MUSIC\DaisyMusic\Death.ogg";

	//============== DEATH ===============================
	tmpref.music_death.f1.name = "MUSIC\DaisyMusic\Death.ogg";				// Daisy: VГ li

	//============ ABORDAGE =======
	tmpref.music_land_abordage.f1.name = "MUSIC\DaisyMusic\Pyrates Beware.ogg";		// Daisy: AC Black Flag 

	trace("InitMusic: created " + GetAttributesNum(tmpref) + " entries.");
}

void RegisterOptionalMusicScheme()
{
	ref rms; makeref(rms, registered_music_schemes);
	int n = GetAttributesNum(rms);
	string lnode = "l" + n;
	rms.(lnode).id = "daisymusic";
	rms.(lnode).resdir = "DaisyMusic";
	switch (LanguageGetLanguage())
	{
		// default:
			rms.(lnode).name = "Daisy's Alt Music";
	}
}
