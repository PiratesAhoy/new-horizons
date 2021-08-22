void RegisterStoryline(int n)
{
	ref storyline; makeref(storyline, Storylines);
	aref sl; makearef(sl, storyline.list);
	string sn = "sl" + (n + 1);
	sl.(sn).id = "DevlinOpera";
	sl.(sn).index = n;
	sl.(sn).dir = "DevlinOpera\";

	sl.(sn).start.location = "Redmond_port";
	sl.(sn).start.port = "Redmond_port";
	sl.(sn).start.model = "Beatrice";
	sl.(sn).start.model.lock = true;
	sl.(sn).start.name = "Beatrice";
	sl.(sn).start.lastname = "Devlin";
	sl.(sn).start.name.lock = true;
	sl.(sn).start.nation = SPAIN;
	sl.(sn).start.playertype = PLAYER_TYPE_EXPLORER;
	sl.(sn).start.difficulty = DIFFICULTY_MARINER;
	sl.(sn).start.Flags.Pirate = 11;
	sl.(sn).start.Flags.Personal = 4;
	sl.(sn).start.ship = "PO_CaravelR";
	sl.(sn).start.shipname = "Quicksilver";
	sl.(sn).start.date.hour = 10;
	sl.(sn).start.date.min = 24;
	sl.(sn).start.date.sec = 42;
	sl.(sn).start.date.day = 25;
	sl.(sn).start.date.month = 9;
	sl.(sn).start.date.year = 1550;
	sl.(sn).start.date.lock = true;
	sl.(sn).start.freedom_level = 1; // PB: Scripted opening, but free play available

	switch (LanguageGetLanguage())
	{
		// default:
			sl.(sn).title = "Devlin Opera";
			sl.(sn).description = "A quest that leads you to find long lost family members, and a vast treasure... that is, if you can survive! Along the way you will encounter a band of rather colourful characters who will help you on your journey. You will get the choice whose help you want, each character offering a different style in achieving your goal.";
		break;
	}
	AddStorylineVar(n, "CHANGING_RELATIONS", "1");	// PB: Changing Relations always on
	AddStorylineVar(n, "ISLA_DE_MUERTE", "1");		// PB: Curse in effect and can visit Isla de Muerte
}
