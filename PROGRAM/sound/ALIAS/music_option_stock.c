// ******* ORIGINAL SECTION *************

void InitOptionalMusic()
{
	ref tmpref; makeref(tmpref, Music_Alias);

	tmpref.music_main_menu.f1.name = "MUSIC\Coridor.ogg";
	tmpref.music_main_theme.f1.name = "MUSIC\Main_Theme.ogg";

	tmpref.music_eng_town.f1.name = "MUSIC\Gorod-1.ogg";
	tmpref.music_eng_town.f2.name = "MUSIC\Jungle.ogg";
	tmpref.music_eng_town.f3.name = "MUSIC\Enplavanie.ogg";

	tmpref.music_fra_town.f1.name = "MUSIC\Gorod-1.ogg";
	tmpref.music_fra_town.f2.name = "MUSIC\Jungle.ogg";
	tmpref.music_fra_town.f3.name = "MUSIC\Enplavanie.ogg";

	tmpref.music_spa_town.f1.name = "MUSIC\Gorod-1.ogg";
	tmpref.music_spa_town.f2.name = "MUSIC\Jungle.ogg";
	tmpref.music_spa_town.f3.name = "MUSIC\Enplavanie.ogg";

	tmpref.music_pir_town.f1.name = "MUSIC\Gorod-1.ogg";
	tmpref.music_pir_town.f2.name = "MUSIC\Jungle.ogg";
	tmpref.music_pir_town.f3.name = "MUSIC\Gorod-2.ogg";

	tmpref.music_hol_town.f1.name = "MUSIC\Gorod-1.ogg";
	tmpref.music_hol_town.f2.name = "MUSIC\Jungle.ogg";
	tmpref.music_hol_town.f3.name = "MUSIC\Enplavanie.ogg";

	tmpref.music_por_town.f1.name = "MUSIC\Gorod-1.ogg";
	tmpref.music_por_town.f2.name = "MUSIC\Jungle.ogg";
	tmpref.music_por_town.f3.name = "MUSIC\Enplavanie.ogg";

	tmpref.music_usa_town.f1.name = "MUSIC\Gorod-1.ogg";
	tmpref.music_usa_town.f2.name = "MUSIC\Jungle.ogg";
	tmpref.music_usa_town.f3.name = "MUSIC\Enplavanie.ogg";

	tmpref.music_swe_town.f1.name = "MUSIC\Gorod-1.ogg";
	tmpref.music_swe_town.f2.name = "MUSIC\Jungle.ogg";
	tmpref.music_swe_town.f3.name = "MUSIC\Enplavanie.ogg";

	tmpref.music_personal_town.f1.name = "MUSIC\Gorod-1.ogg";
	tmpref.music_personal_town.f2.name = "MUSIC\Jungle.ogg";
	tmpref.music_personal_town.f3.name = "MUSIC\Enplavanie.ogg";
	DeleteAttribute(tmpref, "music_personal_town.f4");
	DeleteAttribute(tmpref, "music_personal_town.f5");

	DeleteAttribute(tmpref, "music_shop.f2");

	tmpref.music_tavern.f1.name = "MUSIC\Taverna.ogg";
	tmpref.music_tavern.f2.name = "MUSIC\Town_Exploration02.ogg";

	tmpref.music_tavern_pirate.f1.name = "MUSIC\Taverna.ogg";
	tmpref.music_tavern_pirate.f2.name = "MUSIC\Town_Exploration02.ogg";

	tmpref.music_tavern_personal.f1.name = "MUSIC\Taverna.ogg";
	tmpref.music_tavern_personal.f2.name = "MUSIC\Town_Exploration02.ogg";

	tmpref.music_dungeon.f2.name = "MUSIC\Coridor.ogg";
	tmpref.inca_temple.f2.name = "MUSIC\Cave_or_Dungeon_Walking.ogg";

	tmpref.music_english_governor.f1.name = "MUSIC\Governors_Theme.ogg";
	tmpref.music_english_governor.f2.name = "MUSIC\Gubernator.ogg";

	tmpref.music_french_governor.f1.name = "MUSIC\Governors_Theme.ogg";
	tmpref.music_french_governor.f2.name = "MUSIC\Gubernator.ogg";

	tmpref.music_spanish_governor.f1.name = "MUSIC\Governors_Theme.ogg";
	tmpref.music_spanish_governor.f2.name = "MUSIC\Gubernator.ogg";

	tmpref.music_dutch_governor.f1.name = "MUSIC\Governors_Theme.ogg";
	tmpref.music_dutch_governor.f2.name = "MUSIC\Gubernator.ogg";

	tmpref.music_portugal_governor.f1.name = "MUSIC\Governors_Theme.ogg";
	tmpref.music_portugal_governor.f2.name = "MUSIC\Gubernator.ogg";

	tmpref.music_swedish_governor.f1.name = "MUSIC\Governors_Theme.ogg";
	tmpref.music_swedish_governor.f2.name = "MUSIC\Gubernator.ogg";

	tmpref.music_personal_governor.f1.name = "MUSIC\Governors_Theme.ogg";
	tmpref.music_personal_governor.f2.name = "MUSIC\Gubernator.ogg";

	tmpref.music_jungle.f1.name = "MUSIC\Jungle.ogg";
	tmpref.music_jungle.f2.name = "MUSIC\Jungle_Shore_Exploration.ogg";
	DeleteAttribute(tmpref, "music_jungle.f3");

	tmpref.music_indian.f1.name = "MUSIC\Jungle.ogg";
	tmpref.music_indian.f2.name = "MUSIC\Jungle_Shore_Exploration.ogg";

	tmpref.music_map.f1.name = "MUSIC\Spokplavanie.ogg";
	DeleteAttribute(tmpref, "music_map.f2");

	tmpref.music_day_sailing.f3.name = "MUSIC\Sailing02.ogg";
	DeleteAttribute(tmpref, "music_day_sailing.f4");

	tmpref.music_night_sailing.f1.name = "MUSIC\Spokplavanie.ogg";
	tmpref.music_night_sailing.f2.name = "MUSIC\Sailing01.ogg";
	tmpref.music_night_sailing.f3.name = "MUSIC\Sailing02.ogg";

	tmpref.music_fog_sailing.f1.name = "MUSIC\Spokplavanie.ogg";
	tmpref.music_fog_sailing.f2.name = "MUSIC\Sailing01.ogg";
	tmpref.music_fog_sailing.f3.name = "MUSIC\Sailing02.ogg";

	DeleteAttribute(tmpref, "music_storm.f2");
	DeleteAttribute(tmpref, "music_storm.f3");

	DeleteAttribute(tmpref, "music_sea_battle.f4");
	DeleteAttribute(tmpref, "music_sea_battle.f5");

	tmpref.music_ship_victory.f2.name = "MUSIC\Ship_victory03.ogg";
	DeleteAttribute(tmpref, "music_ship_victory.f3");

	trace("InitOptionalMusic: now " + GetAttributesNum(tmpref) + " entries.");
}

void RegisterOptionalMusicScheme()
{
	ref rms; makeref(rms, registered_music_schemes);
	int n = GetAttributesNum(rms);
	string lnode = "l" + n;
	rms.(lnode).id = "stock";
	rms.(lnode).resdir = "";
	switch (LanguageGetLanguage())
	{
		// default:
			rms.(lnode).name = "Stock PoTC";
	}
}
