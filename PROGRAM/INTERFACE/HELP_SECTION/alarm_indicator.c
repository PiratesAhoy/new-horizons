#event_handler("InitHelpSegment","alarm_indicator_InitHelp");
#event_handler("ResetHelpSegment","alarm_indicator_ResetHelp");

void alarm_indicator_InitHelp()
{
	string sectName = GetEventData();
	if(sectName!="alarm_indicator") return;

	// Заполним экран содержимым
		// каринки
	SetNewPicture("HELPPICTURE","interfaces\helppictures\alarm_indicator.tga");
		// строки
	int strFileID = LanguageOpenFile("helpsections\alarm_indicator.txt");
	SetFormatedText("TEXTWINDOW",LanguageConvertString(strFileID,"alarm_indicator_info"));
	GameInterface.strings.HelpName = LanguageConvertString(strFileID,"alarm_indicator_title");
	LanguageCloseFile(strFileID);
}

void alarm_indicator_ResetHelp()
{
	string sectName = GetEventData();
	if(sectName!="alarm_indicator") return;

	// Удалим с эрана все
	SetNewPicture("HELPPICTURE","");
	SetFormatedText("TEXTWINDOW","");
}
