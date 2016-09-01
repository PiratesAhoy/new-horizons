#event_handler("InitHelpSegment","sea_minimap_InitHelp");
#event_handler("ResetHelpSegment","sea_minimap_ResetHelp");

void sea_minimap_InitHelp()
{
	string sectName = GetEventData();
	if(sectName!="sea_minimap") return;

	// Заполним экран содержимым
		// каринки
	SetNewPicture("HELPPICTURE","interfaces\helppictures\minimap.tga");
		// строки
	int strFileID = LanguageOpenFile("helpsections\navigator_minimap.txt");
	SetFormatedText("TEXTWINDOW",LanguageConvertString(strFileID,"minimap_info"));
	GameInterface.strings.HelpName = LanguageConvertString(strFileID,"minimap_title");
	LanguageCloseFile(strFileID);
}

void sea_minimap_ResetHelp()
{
	string sectName = GetEventData();
	if(sectName!="sea_minimap") return;

	// Удалим с эрана все
	SetNewPicture("HELPPICTURE","");
	SetFormatedText("TEXTWINDOW","");
}
