void SetStorylineRumours(ref i)
{
	int tmpLangFileID = LanguageOpenFile(GetStorylinePath(FindCurrentStoryline()) + "rumour_strings.txt");

	Rumour[i].id = "Sao_Feng_start";
	Rumour[i].text = LanguageConvertString(tmpLangFileID,"The latest news? Why, everyone in town is talking about it! The bodyguards of the great lord Sao Feng are missing and he is offering a reward to whoever can find them! A giant black ship more terrible than the devil himself sinking everything it meets... and even the priests in Redmond have heard about it!");
	Rumour[i].state = "inactive";
	Rumour[i].loc = "Pirate";
	Rumour[i].chance = 100;
	i++;

	LanguageCloseFile(tmpLangFileID);
}
