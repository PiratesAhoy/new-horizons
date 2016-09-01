void SetStorylineRumours(ref i)
{
	int tmpLangFileID = LanguageOpenFile(GetStorylinePath(FindCurrentStoryline()) + "rumour_strings.txt");

	Rumour[i].id = "Silehard_nasty";
	Rumour[i].text = LanguageConvertString(tmpLangFileID,"I heard that the governor of Redmond ordered some merchant brought up on trumped up charges and sent to jail, just to seize the poor fellow's assets!");
	Rumour[i].state = "active";
	Rumour[i].loc = "England";
	Rumour[i].chance = 100;
	i++;

	Rumour[i].id = "Brin_here";
	Rumour[i].text = LanguageConvertString(tmpLangFileID,"I heard there's a new governor on Redmond... came all the way from Britain, on express orders of the king! And he's got orders to send back Silehard in chains!");
	Rumour[i].state = "inactive";
	Rumour[i].loc = "all";
	Rumour[i].chance = 100;
	i++;

	Rumour[i].id = "BP_Start";
	Rumour[i].text = LanguageConvertString(tmpLangFileID,"Well, I'm not one for superstition... but it's like this: you hear something once, and you ignore it; twice, and it's coincidence... but three times, and I'm beginning to believe. So I'm beginning to believe there is a ghost ship out there, after all... and I'm staying on land until she's dealt with, that's for sure!");
	Rumour[i].state = "active";
	Rumour[i].loc = "all";
	Rumour[i].chance = 100;
	i++;

	LanguageCloseFile(tmpLangFileID);
}
