// ******* ORIGINAL SECTION *************

void InitOptionalMusic()
{
	ref tmpref; makeref(tmpref, Music_Alias);

	tmpref.music_eng_town.f3.name = "MUSIC\Hearts_Of_Oak\The_Dock.ogg";			// TNP: Hearts of Oak (Jose Cava: The Dock)
	tmpref.music_spa_town.f4.name = "MUSIC\Hearts_Of_Oak\Spanish_Gold.ogg";			// TNP: Hearts of Oak (Jose Cava: Spanish Gold)
	tmpref.music_pir_town.f3.name = "MUSIC\Hearts_Of_Oak\Porto_Pirata.ogg";			// TNP: Hearts of Oak (Franco Tempesta: Porto Pirata)
	tmpref.music_tavern_pirate.f3.name = "MUSIC\Hearts_Of_Oak\Pirate_Tavern.ogg";		// TNP: Hearts of Oak (Jose Cava: Pirate Tavern)
	tmpref.music_abordage.f4.name = "MUSIC\Hearts_Of_Oak\Quest_for_Treasure.ogg";		// TNP: Hearts of Oak (Franco Tempesta: Quest for Treasure)
	tmpref.music_sea_battle.f6.name = "MUSIC\Hearts_Of_Oak\Conquest_of_the_Seas.ogg";	// TNP: Hearts of Oak (Franco Tempesta: Conquest of the Seas)
	tmpref.music_land_abordage.f2.name = "MUSIC\Hearts_Of_Oak\Quest_for_Treasure.ogg";	// TNP: Hearts of Oak (Franco Tempesta: Quest for Treasure)
	tmpref.Dawn_at_the_Bay.f1.name = "MUSIC\Hearts_Of_Oak\Dawn_at_the_Bay.ogg";		// TNP: Hearts of Oak (Franco Tempesta: Dawn at the Bay). GR: used at end of "Strange Things Going On" quest when women go to get their children

	trace("InitOptionalMusic: now " + GetAttributesNum(tmpref) + " entries.");
}

void RegisterOptionalMusicScheme()
{
	ref rms; makeref(rms, registered_music_schemes);
	int n = GetAttributesNum(rms);
	string lnode = "l" + n;
	rms.(lnode).id = "Hearts";
	rms.(lnode).resdir = "Hearts_Of_Oak";
	switch (LanguageGetLanguage())
	{
		// default:
			rms.(lnode).name = "Hearts of Oak";
	}
}
