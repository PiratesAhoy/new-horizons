//Sailor Al, NK
//random strings for conversation

void InitConversation()
{
	int i = 0;
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");

	Flirt[i] = LanguageConvertString(tmpLangFileID,"My dear, I'm totally enchanted!  May I spend a few moments of your precious time?");
	i++;
	Flirt[i] = LanguageConvertString(tmpLangFileID,"You take the wind right out of my sails!  Would you do me the pleasure of some conversation?");
	i++;
	Flirt[i] = LanguageConvertString(tmpLangFileID,"I am delighted to have the opportunity to be here with you.  Might you indulge a lonely sailor?");
	i++;
	Flirt[i] = LanguageConvertString(tmpLangFileID,"You are as radiant as a summer's sunset out at sea!  May I become better acquainted with you?");
	i++;
	Flirt[i] = LanguageConvertString(tmpLangFileID,"This lowly seaman is at a loss for words.  Speak, I pray, that I might know you better!");
	i++;
	Flirt[i] = LanguageConvertString(tmpLangFileID,"I would be honored and delighted to share a few moments of time with you, dear lady!");
	i++;
	Flirt[i] = LanguageConvertString(tmpLangFileID,"I must leave with the tide, dear one...  But until then, might we share some companionable moments?");
	i++;
	Flirt[i] = LanguageConvertString(tmpLangFileID,"The sea calls, and I must build a future.  Until the next tide, would you indulge a weary sailor?");
	i++;
	Flirt[i] = LanguageConvertString(tmpLangFileID,"My dear, I'm just a master and commander.  Tell me about yourself, everything, I'd love to know!");
	i++;
	Flirt[i] = LanguageConvertString(tmpLangFileID,"There are any wondrous things at sea, from mighty ships to flying fish. But none so lovely as your smile!");
	i++;
	FLIRT_QUANTITY = i;

	i = 0;
	Prop[i] = LanguageConvertString(tmpLangFileID,"I hesitate to be so bold, but I am lost without you.  Would you complete me by consenting to be my bride?");
	i++;
	Prop[i] = LanguageConvertString(tmpLangFileID,"I used to think that I was happy at sea, but I would be much happier knowing that you waited at my home port.  Would you be my wife?");
	i++;
	Prop[i] = LanguageConvertString(tmpLangFileID,"I...  I'm at a loss for words... Ha'hmmm...  I have this ring here, you see, and I...  Would you marry me?");
	i++;
	Prop[i] = LanguageConvertString(tmpLangFileID,"Dear lady, I have trod decks riddled with shot without the depth of fear I feel now.  Please ease my soul and tell me that you'll marry me!");
	i++;
	PROP_QUANTITY = i;

	LanguageCloseFile(tmpLangFileID);
}