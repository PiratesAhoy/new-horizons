void RegisterStoryline(int n)
{
	ref storyline; makeref(storyline, Storylines);
	aref sl; makearef(sl, storyline.list);
	string sn = "sl" + (n + 1);
	sl.(sn).id = "Hornblower";
	sl.(sn).index = n;
	sl.(sn).dir = "Hornblower\";

	sl.(sn).start.location = "Antigua_port";
	sl.(sn).start.location.lock = true;
	sl.(sn).start.port = "Antigua_port";
	sl.(sn).start.model = "brtmdsH_18";
	sl.(sn).start.model.lock = true;
	sl.(sn).start.name = "Horatio";
	sl.(sn).start.lastname = "Hornblower";
	sl.(sn).start.name.lock = true;
	sl.(sn).start.nation = ENGLAND;
	sl.(sn).start.nation.lock = true;
	sl.(sn).start.playertype = PLAYER_TYPE_NAVAL_OFFICER;
	sl.(sn).start.playertype.lock = true;
	sl.(sn).start.difficulty = DIFFICULTY_MARINER;
	sl.(sn).start.Flags.Pirate = 23;
	sl.(sn).start.Flags.Personal = 25;
	sl.(sn).start.Flags.Personal.lock = true;
	sl.(sn).start.ship = "HMS_Bellona";
	sl.(sn).start.ship.lock = true;
	sl.(sn).start.shipname = "Justinian";
	sl.(sn).start.shipname.lock = true;
	sl.(sn).start.date.hour = 10;
	sl.(sn).start.date.min = 24;
	sl.(sn).start.date.sec = 42;
	sl.(sn).start.date.day = 18;
	sl.(sn).start.date.month = 6;
	sl.(sn).start.date.year = 1798;
	sl.(sn).start.date.lock = true;
	sl.(sn).start.freedom_level = 3; // PB: NO free play

	switch (LanguageGetLanguage())
	{
		// default:
			sl.(sn).title = "The Chronicles of Horatio Hornblower";
			sl.(sn).description = "As a seventeen-year-old with a touch for seasickness, young Horatio Hornblower hardly cuts a dash in His Majesty's Navy. Yet from the moment he is ordered to board the Justinian, he proves his seafaring mettle on the waves. With a character-forming duel, several chases and some strange tavern encounters, the young Hornblower is soon forged into a formidable man of the sea.";
	}
	AddStorylineVar(n, "ISLA_DE_MUERTE", "0");		// PB: Curse not in effect, but can visit Isla de Muerte
	AddStorylineVar(n, "LOCKED_CANNONS", "1");		// PB: Start game with 4lbs cannons, regardless of selected ship type
	AddStorylineVar(n, "START_MIN_LEVEL", "1");		// PB: Start storyline at rank 1
}
