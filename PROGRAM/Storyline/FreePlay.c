void RegisterStoryline(int n)
{
	ref storyline; makeref(storyline, Storylines);
	aref sl; makearef(sl, storyline.list);
	string sn = "sl" + (n + 1);
	sl.(sn).id = "FreePlay";
	sl.(sn).index = n;
	sl.(sn).dir = "FreePlay\";

	sl.(sn).start.location = "Tutorial_Deck";
	sl.(sn).start.port = "QC_port";	//Oxbay_port
	sl.(sn).start.model = "47_JRMMSub";
	sl.(sn).start.name = "Julian";
	sl.(sn).start.lastname = "McAllister";
	sl.(sn).start.nation = ENGLAND;
	sl.(sn).start.playertype = PLAYER_TYPE_REBEL;
	sl.(sn).start.difficulty = DIFFICULTY_SEADOG;
	sl.(sn).start.Flags.Pirate = 20;
	sl.(sn).start.Flags.Personal = 30;
	sl.(sn).start.ship = "BrigRoyal";
	sl.(sn).start.shipname = "Defiance";
	sl.(sn).start.date.hour = 13;
	sl.(sn).start.date.min = 20;
	sl.(sn).start.date.sec = 33;
	sl.(sn).start.date.day = 14;
	sl.(sn).start.date.month = 5;
	sl.(sn).start.date.year = 1682;
	sl.(sn).start.freedom_level = 1; // PB: Scripted opening, but free play available

	switch (LanguageGetLanguage())
	{
		// default:
			sl.(sn).title = "Free Play";
			sl.(sn).description = "Choose from several pre-defined characters or freely customize your own. Various background professions are available, some featuring different starting scenarios. An open-ended and dynamic game world awaits in six unique time periods! You can even choose the United States by setting the starting date after 1770.";
	}
	AddStorylineVar(n, "CHANGING_RELATIONS", "1");	// PB: Changing Relations always on
	AddStorylineVar(n, "ISLA_DE_MUERTE", "0");		// PB: Curse not in effect, but can visit Isla de Muerte
}
