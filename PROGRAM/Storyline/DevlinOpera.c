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
	sl.(sn).start.nation = PERSONAL_NATION;
	sl.(sn).start.nation.lock = true;
	sl.(sn).start.playertype = PLAYER_TYPE_EXPLORER;
	sl.(sn).start.playertype.lock = true;
	sl.(sn).start.difficulty = DIFFICULTY_MARINER;
	sl.(sn).start.Flags.Pirate = 20;
	sl.(sn).start.Flags.Pirate.lock = true;
	sl.(sn).start.Flags.Personal = 37;
	sl.(sn).start.Flags.Personal.lock = true;
	sl.(sn).start.ship = "FastGalleon1";
	sl.(sn).start.ship.lock = true;
	sl.(sn).start.shipname = "Discovery";
	sl.(sn).start.shipname.lock = true;
	sl.(sn).start.date.hour = 10;
	sl.(sn).start.date.min = 00;
	sl.(sn).start.date.sec = 42;
	sl.(sn).start.date.day = 1;
	sl.(sn).start.date.month = 4;
	sl.(sn).start.date.year = 1576;
	sl.(sn).start.date.lock = true;
	sl.(sn).start.freedom_level = 1; // PB: Scripted opening, but free play available

	switch (LanguageGetLanguage())
	{
		// default:
			sl.(sn).title = "Devlin Opera";
			sl.(sn).description = "A quest that leads you to find long lost family members, and a vast treasure... that is, if you can survive! Along your way through the vastness of the new world, you will encounter various rather colourful characters and adventures that put the wide spectrum of your skills to the test.";
		break;
	}
	AddStorylineVar(n, "CHANGING_RELATIONS", "1");	// PB: Changing Relations always on
	AddStorylineVar(n, "ISLA_DE_MUERTE", "-1");		// PB: No curse in effect and cannot freely visit Isla de Muerte
}
