//Sailor Al, NK
//random strings for conversation

void InitConversation()
{
	int i = 0;
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	ref PChar = GetMainCharacter();

	Flirt[i] = LanguageConvertString(tmpLangFileID,"I am delighted to have the opportunity to be here with you.  Might you indulge a lonely sailor?");
	i++;
	Flirt[i] = LanguageConvertString(tmpLangFileID,"I must leave with the tide, dear one...  But until then, might we share some companionable moments?");
	i++;
	Flirt[i] = LanguageConvertString(tmpLangFileID,"The sea calls, and I must build a future.  Until the next tide, would you indulge a weary sailor?");
	i++;
	Flirt[i] = LanguageConvertString(tmpLangFileID,"There are any wondrous things at sea, from mighty ships to flying fish. But none so lovely as your smile!");
	i++;
	if (PChar.sex == "man")
	{
		Flirt[i] = LanguageConvertString(tmpLangFileID,"My dear, I'm totally enchanted!  May I spend a few moments of your precious time?");
		i++;
		Flirt[i] = LanguageConvertString(tmpLangFileID,"You take the wind right out of my sails!  Would you do me the pleasure of some conversation?");
		i++;
		Flirt[i] = LanguageConvertString(tmpLangFileID,"You are as radiant as a summer's sunset out at sea!  May I become better acquainted with you?");
		i++;
		Flirt[i] = LanguageConvertString(tmpLangFileID,"This lowly seaman is at a loss for words.  Speak, I pray, that I might know you better!");
		i++;
		Flirt[i] = LanguageConvertString(tmpLangFileID,"I would be honored and delighted to share a few moments of time with you, dear lady!");
		i++;
		Flirt[i] = LanguageConvertString(tmpLangFileID,"My dear, I'm just a master and commander.  Tell me about yourself, everything, I'd love to know!");
		i++;
	}
	else
	{
		Flirt[i] = LanguageConvertString(tmpLangFileID,"I would very much like to spend a few moments with the gentleman's company, if he is willing.");
		i++;
		Flirt[i] = LanguageConvertString(tmpLangFileID,"My lord, I must admit, you do not fail to impress. Would you care to join me for some conversation?");
		i++;
		Flirt[i] = LanguageConvertString(tmpLangFileID,"You are more thrilling than the fiercest storm of the seven seas!  May I become better acquainted with you?");
		i++;
		Flirt[i] = LanguageConvertString(tmpLangFileID,"I am enchanted by your grace and eloquence. Speak, I pray, that I might know you better!");
		i++;
		Flirt[i] = LanguageConvertString(tmpLangFileID,"I would be honoured and delighted to share a few moments of time with you, my lord.");
		i++;
		Flirt[i] = LanguageConvertString(tmpLangFileID,"My dear, I have mastered the waves and commanded the winds, but you are the one puzzle I cannot solve! Tell me more!");
		i++;
	}
	FLIRT_QUANTITY = i;

	i = 0;
	if (PChar.sex == "man")
	{
		Prop[i] = LanguageConvertString(tmpLangFileID,"I hesitate to be so bold, but I am lost without you.  Would you complete me by consenting to be my bride?");
		i++;
		Prop[i] = LanguageConvertString(tmpLangFileID,"I used to think that I was happy at sea, but I would be much happier knowing that you waited at my home port.  Would you be my wife?");
		i++;
		Prop[i] = LanguageConvertString(tmpLangFileID,"I...  I'm at a loss for words... Ha'hmmm...  I have this ring here, you see, and I...  Would you marry me?");
		i++;
		Prop[i] = LanguageConvertString(tmpLangFileID,"Dear lady, I have trod decks riddled with shot without the depth of fear I feel now.  Please ease my soul and tell me that you'll marry me!");
		i++;
	}
	else
	{
		Prop[i] = LanguageConvertString(tmpLangFileID,"I hesitate to be so bold, but I am lost without you.  Would you complete me by consenting to be my husband?");
		i++;
		Prop[i] = LanguageConvertString(tmpLangFileID,"I used to think that nothing could make me happier than the seas, but you proved otherwise, my lord. Would you be my husband?");
		i++;
		Prop[i] = LanguageConvertString(tmpLangFileID,"I...  I do not know how to ask you this, but... Words elude me, I...  Would you...marry me?");
		i++;
		Prop[i] = LanguageConvertString(tmpLangFileID,"My lord, I have trod decks riddled with shot without the depth of fear I feel now.  Please ease my soul and tell me that you'll marry me!");
		i++;
	}
	PROP_QUANTITY = i;

	LanguageCloseFile(tmpLangFileID);
}