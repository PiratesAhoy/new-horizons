void RegisterStoryline(int n)
{
	ref storyline; makeref(storyline, Storylines);
	aref sl; makearef(sl, storyline.list);
	string sn = "sl" + (n + 1);
	sl.(sn).id = "Bartolomeu";
	sl.(sn).index = n;
	sl.(sn).dir = "Bartolomeu\";

	sl.(sn).start.location = "PoPrince_Port";
	sl.(sn).start.location.lock = true;
	sl.(sn).start.port = "PoPrince_Port";
	sl.(sn).start.model = "GypsyCaptn_2";
	sl.(sn).start.model.lock = true;
	sl.(sn).start.name = "Bartolomeu";
	sl.(sn).start.lastname = "o Portugues";
	sl.(sn).start.name.lock = true;
	sl.(sn).start.nation = PORTUGAL;
	sl.(sn).start.nation.lock = true;
	sl.(sn).start.playertype = PLAYER_TYPE_SOCIAL_CLIMBER;
	sl.(sn).start.playertype.lock = true;
	sl.(sn).start.difficulty = DIFFICULTY_SEADOG;
	sl.(sn).start.Flags.Pirate = 4;
	sl.(sn).start.Flags.Personal = 8;
	sl.(sn).start.date.hour = 9;
	sl.(sn).start.date.min = 17;
	sl.(sn).start.date.sec = 42;
	sl.(sn).start.date.day = 22;
	sl.(sn).start.date.month = 7;
	sl.(sn).start.date.year = 1660;
	sl.(sn).start.date.lock = true;
	sl.(sn).start.freedom_level = 2; // PB: Locked storyline opening

	switch (LanguageGetLanguage())
	{
		// default:
			sl.(sn).title = "Bartolomeu o Portugues";
			sl.(sn).description = "In the year 1660, Portugal had been at war with Spain for over twenty years. Once one of the main superpowers on the high seas, Portugal was now a part of the Spanish Empire. Struggling for independance, the Portuguese government handed out many letters of marque in an attempt to turn the tide. It is in this world in turmoil that Bartolomeu decided to leave his beloved country and take his chances in the New World. Little did he know that he would soon become the most famous Portuguese pirate in history, feared by the Spanish and hailed by his countrymen.";
	}
	AddStorylineVar(n, "ISLA_DE_MUERTE", "-1");		// PB: No curse in effect and cannot freely visit Isla de Muerte
	AddStorylineVar(n, "BART_PUZZLES", "1");		// PB: Used for special storyline functions
	AddStorylineVar(n, "START_MIN_LEVEL", "1");		// PB: Start storyline at rank 1
}
