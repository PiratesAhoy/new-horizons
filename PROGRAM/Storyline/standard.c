void RegisterStoryline(int n)
{
	ref storyline; makeref(storyline, Storylines);
	storyline.default = n;
	aref sl; makearef(sl, storyline.list);
	string sn = "sl" + (n + 1);
	sl.(sn).id = "NewHorizons";
	sl.(sn).index = n;
	sl.(sn).dir = "standard\";

	sl.(sn).start.location = "Tutorial_Deck";
	sl.(sn).start.port = "Oxbay_port";
	sl.(sn).start.model = "Blaze";
	sl.(sn).start.name = "Nathaniel";
	sl.(sn).start.lastname = "Hawk";
	sl.(sn).start.Flags.Pirate = 15;
	sl.(sn).start.Flags.Personal = 14;
	sl.(sn).start.ship = "LuggerVML";
	sl.(sn).start.shipname = "Sea Horse";
	sl.(sn).start.date.hour = 10;
	sl.(sn).start.date.min = 24;
	sl.(sn).start.date.sec = 42;
	sl.(sn).start.date.day = 16;
	sl.(sn).start.date.month = 4;
	sl.(sn).start.date.year = 1750; // was 1690
	sl.(sn).start.date.lock = true;

	switch (LanguageGetLanguage())
	{
		case "Polish":
			sl.(sn).title = "Nowe horyzonty";
			sl.(sn).description = "Jako odwažny korsarz musisz walczyĺ ze zdradliwymi gubernatorami i niezwykle wrednym kapitanem piratów. Možesz w to wierzyĺ jeĺli tego pragniesz; možesz okłamywaĺ siebie že wielko›ĺ statku i ilo›ĺ dział jest najwažniejsza. Na pewno walczysz o bogactwo i sław×. Lecz wszystko sprowadza si× do znalezienia odpowiedzi na jedyne prawdziwe pytanie: czy Danielle wróci do Ciebie?";
		break;
		// default:
			sl.(sn).title = "Tales of a Sea Hawk";
			sl.(sn).description = "As a new face in the Caribbean, you are determined to make a name for yourself through fair means or foul. You can try to convince yourself that you fight for riches and glory alone, but you came here for another reason. Will you manage to regain the affection of Danielle and win her heart back again? Or will you simply become another tortured soul; lost amongst these wild and dangerous islands, forced to seek fame and fortune as scant, cold comfort? (Or perhaps you'd prefer to play as Danielle...)";
	}
	AddStorylineVar(n, "ISLA_DE_MUERTE", "1");		// PB: Curse in effect and can visit Isla de Muerte
	AddStorylineVar(n, "START_MIN_LEVEL", "1");		// PB: Start storyline at rank 1
}
