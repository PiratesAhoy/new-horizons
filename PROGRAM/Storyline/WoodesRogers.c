void RegisterStoryline(int n)
{
	ref storyline; makeref(storyline, Storylines);
	aref sl; makearef(sl, storyline.list);
	string sn = "sl" + (n + 1);
	sl.(sn).id = "WoodesRogers";
	sl.(sn).index = n;
	sl.(sn).dir = "WoodesRogers\";

	sl.(sn).start.location = "Redmond_Town_01";	//can ev be off
	sl.(sn).start.location.lock = true;
	sl.(sn).start.port = "Redmond_Port";		//must be on
	sl.(sn).start.model = "Howard_Pyle";
	sl.(sn).start.model.lock = true;
	sl.(sn).start.name = "Howard";
	sl.(sn).start.lastname = "Pyle";
	sl.(sn).start.name.lock = true;
	sl.(sn).start.nation = PIRATE;
	sl.(sn).start.nation.lock = true;
	sl.(sn).start.playertype = PLAYER_TYPE_CORSAIR;
	sl.(sn).start.playertype.lock = true;
	sl.(sn).start.difficulty = DIFFICULTY_MARINER;
	sl.(sn).start.difficulty.lock = true;
	sl.(sn).start.Flags.Pirate = 18;
	sl.(sn).start.Flags.Pirate.lock = true;
	sl.(sn).start.Flags.Personal = 31;
	sl.(sn).start.Flags.Personal.lock = true;
	sl.(sn).start.date.hour = 10;
	sl.(sn).start.date.min = 24;
	sl.(sn).start.date.sec = 42;
	sl.(sn).start.date.day = 26;
	sl.(sn).start.date.month = 12;
	sl.(sn).start.date.year = 1724;
	sl.(sn).start.date.lock = true;
	sl.(sn).start.freedom_level = 3; // PB: NO free play

	switch (LanguageGetLanguage())
	{
		// default:
			sl.(sn).title = "Woodes Rogers";
			sl.(sn).description = "In 1717 Rogers was appointed Royal Governor of the Bahamas where he helped suppress piracy in the Caribbean by offering caught pirates pardons. Many notorious pirates accepted this while others were hunted down and killed. The Golden Age of Piracy is about to end and Woodes Rogers, now retired, is living in Port Royale. The rumour has it that he is looking for adventurers. There is only one small problem with your crew...";
	}
	AddStorylineVar(n, "ISLA_DE_MUERTE", "-1");		// PB: No curse in effect and cannot freely visit Isla de Muerte
	AddStorylineVar(n, "WR_PUZZLES", "1");			// PB: Used for special storyline functions
	AddStorylineVar(n, "DISABLE_CHEATMODE", "1");	// PB: No cheats in this story
	AddStorylineVar(n, "RESET_HP", "1");			// PB: Character HP is not re-calculated from level at game start
	AddStorylineVar(n, "NO_CREW_OR_OFFICERS", "1");	// PB: Cannot hire officers or use shore crewmembers
	AddStorylineVar(n, "DISABLE_TIPS", "1");		// PB: No tips during reloads
	AddStorylineVar(n, "GUNFIGHTER_PERK", "1");		// PB: Gun Fighter perk enabled for 6-shot pistols
	AddStorylineVar(n, "START_MIN_LEVEL", "1");		// PB: Start storyline at rank 1
	AddStorylineVar(n, "DYNAMIC_INTERFACES", "1");	// PB: Override default "Dynamic Interfaces" behaviour
	AddStorylineVar(n, "ENABLE_BROTHEL", "1");		// PB: Brothel Mod always ON
}
