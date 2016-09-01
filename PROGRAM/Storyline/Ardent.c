void RegisterStoryline(int n)
{
	ref storyline; makeref(storyline, Storylines);
	aref sl; makearef(sl, storyline.list);
	string sn = "sl" + (n + 1);
	sl.(sn).id = "Ardent";
	sl.(sn).index = n;
	sl.(sn).dir = "Ardent\";
	sl.(sn).start.location = "Tutorial_Deck";
	sl.(sn).start.port = "Cuba_port";
//	sl.(sn).start.port = "QC_port";	//Oxbay_port
	sl.(sn).start.model = "Ardent";
	sl.(sn).start.model.lock = true;
	sl.(sn).start.name = "Charles";
	sl.(sn).start.lastname = "Ardent";
	sl.(sn).start.name.lock = true;
	sl.(sn).start.nation = PIRATE;
	sl.(sn).start.nation.lock = true;
	sl.(sn).start.playertype = PLAYER_TYPE_CORSAIR;
	sl.(sn).start.playertype.lock = true;
	sl.(sn).start.difficulty = DIFFICULTY_SEADOG;
	sl.(sn).start.Flags.Pirate = 1;
	sl.(sn).start.Flags.Personal = 15;
	sl.(sn).start.ship = "Cutter1";
	sl.(sn).start.ship.lock = true;
	sl.(sn).start.shipname = "Fortune";
	sl.(sn).start.shipname.lock = true;
	sl.(sn).start.date.hour = 10;
	sl.(sn).start.date.min = 21;
	sl.(sn).start.date.sec = 32;
	sl.(sn).start.date.day = 31;
	sl.(sn).start.date.month = 7;
	sl.(sn).start.date.year = 1691;
	sl.(sn).start.date.lock = true;
	sl.(sn).start.freedom_level = 2; // PB: Locked storyline opening

	switch (LanguageGetLanguage())
	{
		// default:
			sl.(sn).title = "Ardent";
			sl.(sn).description = "Time to put the 'gold' and 'piracy' into the Golden Age of Piracy! Kidnap, burglary and outright piracy - Charles Ardent does it all! (Though there are those that say Ardent was actually a woman, Helen.)";
	}
	AddStorylineVar(n, "ISLA_DE_MUERTE", "0");		// PB: Curse not in effect, but can visit Isla de Muerte
	AddStorylineVar(n, "START_MIN_LEVEL", "1");		// PB: Start storyline at rank 1
//	AddStorylineVar(n, "START_MIN_LEVEL", "0");		// PB: Start storyline at rank 5
}
