void RegisterStoryline(int n)
{
	ref storyline; makeref(storyline, Storylines);
	aref sl; makearef(sl, storyline.list);
	string sn = "sl" + (n + 1);
	sl.(sn).id = "Assassin";
	sl.(sn).index = n;
	sl.(sn).dir = "Assassin\";

	sl.(sn).start.location = "Douwesen_port";
	sl.(sn).start.port = "Douwesen_port";
	sl.(sn).start.model = "Johan_Elting";
	sl.(sn).start.model.lock = true;
	sl.(sn).start.name = "Johan";
	sl.(sn).start.lastname = "Elting";
	sl.(sn).start.name.lock = true;
	sl.(sn).start.nation = HOLLAND;
	sl.(sn).start.nation.lock = true;
	sl.(sn).start.playertype = PLAYER_TYPE_MILITARY;
	sl.(sn).start.playertype.lock = true;
	sl.(sn).start.difficulty = DIFFICULTY_SEADOG;
	sl.(sn).start.Flags.Pirate = 2;
	sl.(sn).start.Flags.Personal = 9;
	sl.(sn).start.Flags.Personal.lock = true;
	sl.(sn).start.ship = "Barque4_47";
	sl.(sn).start.ship.lock = true;
	sl.(sn).start.shipname = "Neptunis";
	sl.(sn).start.shipname.lock = true;
	sl.(sn).start.date.hour = 11;
	sl.(sn).start.date.min = 43;
	sl.(sn).start.date.sec = 12;
	sl.(sn).start.date.day = 8;
	sl.(sn).start.date.month = 10;
	sl.(sn).start.date.year = 1662;
	sl.(sn).start.date.lock = true;
	sl.(sn).start.freedom_level = 2; // PB: Locked storyline opening

	switch (LanguageGetLanguage())
	{
		// default:
			sl.(sn).title = "Assassin";
			sl.(sn).description = "As a former Dutch soldier, Johan Elting is regarded by his peers as a good fighter. Tired of the army life (and pay), he decided to become a smuggler. Little does he know that soon he will become one of the most feared mercenaries in the Spanish service. But how long will he accept this new status?";
	}
	AddStorylineVar(n, "ISLA_DE_MUERTE", "1");		// PB: Curse in effect and can visit Isla de Muerte
	AddStorylineVar(n, "ASSN_PUZZLES", "1");		// PB: Used for special storyline functions
	AddStorylineVar(n, "START_MIN_LEVEL", "1");		// PB: Start storyline at rank 1
	AddStorylineVar(n, "ENABLE_BROTHEL", "1");		// PB: Brothel Mod always ON
}
