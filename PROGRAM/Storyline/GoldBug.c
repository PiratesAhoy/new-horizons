void RegisterStoryline(int n)
{
	ref storyline; makeref(storyline, Storylines);
	aref sl; makearef(sl, storyline.list);
	string sn = "sl" + (n + 1);
	sl.(sn).id = "GoldBug";
	sl.(sn).index = n;
	sl.(sn).dir = "GoldBug\";
	sl.(sn).start.screen = "Quest_GoldBug.tga";
	sl.(sn).start.location = "Charleston_Port";
	sl.(sn).start.location.lock = true;
	sl.(sn).start.port = "Charleston_Port";
	sl.(sn).start.model = "William Legrand";
	sl.(sn).start.model.lock = true;
	sl.(sn).start.name = "William";
	sl.(sn).start.lastname = "Legrand";
	sl.(sn).start.name.lock = true;
	sl.(sn).start.nation = AMERICA;
	sl.(sn).start.nation.lock = true;
	sl.(sn).start.playertype = PLAYER_TYPE_LAND_OWNER;
	sl.(sn).start.playertype.lock = true;
	sl.(sn).start.difficulty = DIFFICULTY_MARINER;
	sl.(sn).start.difficulty.lock = true;
	sl.(sn).start.Flags.Pirate = 19;
	sl.(sn).start.Flags.Pirate.lock = true;
	sl.(sn).start.Flags.Personal = 23;
	sl.(sn).start.Flags.Personal.lock = true;
	sl.(sn).start.ship = "obj_goldbug";
	sl.(sn).start.ship.lock = true;
	sl.(sn).start.shipname = "Alaus Oculatus";
	sl.(sn).start.shipname.lock = true;
	sl.(sn).start.date.hour = 10;
	sl.(sn).start.date.min = 24;
	sl.(sn).start.date.sec = 42;
	sl.(sn).start.date.day = 15;
	sl.(sn).start.date.month = 10;
	sl.(sn).start.date.year = 1830;
	sl.(sn).start.date.lock = true;
	sl.(sn).start.freedom_level = 3; // PB: NO free play

	switch (LanguageGetLanguage())
	{
		// default:
			sl.(sn).title = "The Gold-Bug";
			sl.(sn).description = "'What ho! What ho! This fellow is dancing mad! He hath been bitten by the Tarantula.'                        All in the Wrong.";
			break;
	}
	AddStorylineVar(n, "ISLA_DE_MUERTE", "-1");		// PB: No curse in effect and cannot freely visit Isla de Muerte
	AddStorylineVar(n, "BUG_PUZZLES", "1");			// PB: Used for special storyline functions
	AddStorylineVar(n, "DISABLE_CHEATMODE", "1");	// PB: No cheats in this story
	AddStorylineVar(n, "RESET_HP", "1");			// PB: Character HP is not re-calculated from level at game start
	AddStorylineVar(n, "NO_CREW_OR_OFFICERS", "1");	// PB: Cannot hire officers or use shore crewmembers
	AddStorylineVar(n, "DISABLE_TIPS", "1");		// PB: No tips during reloads
	AddStorylineVar(n, "GUNFIGHTER_PERK", "1");		// PB: Gun Fighter perk enabled for 6-shot pistols
	AddStorylineVar(n, "START_MIN_LEVEL", "1");		// PB: Start storyline at rank 1
	AddStorylineVar(n, "DYNAMIC_INTERFACES", "1");	// PB: Override default "Dynamic Interfaces" behaviour
}
