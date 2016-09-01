#event_handler("InitHelpSegment","sea_aim_InitHelp");
#event_handler("ResetHelpSegment","sea_aim_ResetHelp");

void sea_aim_InitHelp()
{
	string sectName = GetEventData();
	if(sectName!="sea_aim") return;

	// Заполним экран содержимым
		// каринки
	SetNewPicture("HELPPICTURE","interfaces\helppictures\sea_aim.tga");
		// строки
	int strFileID = LanguageOpenFile("helpsections\sea_aim.txt");
	SetFormatedText("TEXTWINDOW",LanguageConvertString(strFileID,"sea_aim_info"));
	GameInterface.strings.HelpName = LanguageConvertString(strFileID,"sea_aim_title");
	LanguageCloseFile(strFileID);
}

void sea_aim_ResetHelp()
{
	string sectName = GetEventData();
	if(sectName!="sea_aim") return;

	// Удалим с эрана все
	SetNewPicture("HELPPICTURE","");
	SetFormatedText("TEXTWINDOW","");
}
