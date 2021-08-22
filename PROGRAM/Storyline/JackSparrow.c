void RegisterStoryline(int n)
{
	ref storyline; makeref(storyline, Storylines);
	aref sl; makearef(sl, storyline.list);
	string sn = "sl" + (n + 1);
	sl.(sn).id = "JackSparrow";
	sl.(sn).index = n;
	sl.(sn).dir = "JackSparrow\";

	sl.(sn).start.location = "Tortuga_Port";
	sl.(sn).start.location.lock = true;
	sl.(sn).start.port = "Tortuga_Port";
	sl.(sn).start.model = "depp";
	sl.(sn).start.model.lock = true;
	sl.(sn).start.name = "Jack";
	sl.(sn).start.lastname = "Sparrow";
	sl.(sn).start.name.lock = true;
	sl.(sn).start.nation = PIRATE;
	sl.(sn).start.nation.lock = true;
	sl.(sn).start.playertype = PLAYER_TYPE_ADVENTURER;
	sl.(sn).start.playertype.lock = true;
	sl.(sn).start.difficulty = DIFFICULTY_MARINER;
	sl.(sn).start.ship = "BlackPearl";
	sl.(sn).start.ship.lock = true;
	sl.(sn).start.shipname = "Black Pearl";
	sl.(sn).start.shipname.lock = true;
	sl.(sn).start.Flags.Pirate = 6;
	sl.(sn).start.Flags.Pirate.lock = true;
	sl.(sn).start.Flags.Personal = 21;
	sl.(sn).start.Flags.Personal.lock = true;
	sl.(sn).start.date.hour = 20;
	sl.(sn).start.date.min = 24;
	sl.(sn).start.date.sec = 42;
	sl.(sn).start.date.day = 9;
	sl.(sn).start.date.month = 6;
	sl.(sn).start.date.year = 1740;
	sl.(sn).start.date.lock = true;
	sl.(sn).start.freedom_level = 2; // PB: Locked storyline opening

	switch (LanguageGetLanguage())
	{
		// default:
			sl.(sn).title = "Hoist the Colours";
			sl.(sn).description = "A lot has been speculated about the early days of Jack Sparrow and we're not even sure if this particular account is entirely accurate. It does explain some of the events that shaped this infamous pirate, but the journey can take multiple twists and turns depending on your choices, which may or may not end with you sailing into the sunset after lifting the Curse of the Black Pearl.";
	}
	AddStorylineVar(n, "HAVANA_NO_PRISONERS", "1");	// PB: Disable unwanted characters
	AddStorylineVar(n, "ISLA_DE_MUERTE", "-1");		// PB: No curse in effect and cannot freely visit Isla de Muerte
	AddStorylineVar(n, "JACK_SPARROW", "1");		// PB: Used for special storyline functions
	AddStorylineVar(n, "START_MIN_LEVEL", "1");		// PB: Start storyline at rank 1
}
