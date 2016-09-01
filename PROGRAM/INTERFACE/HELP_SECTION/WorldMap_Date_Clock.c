#event_handler("InitHelpSegment","WorldMap_Date_Clock_InitHelp");
#event_handler("ResetHelpSegment","WorldMap_Date_Clock_ResetHelp");

void WorldMap_Date_Clock_InitHelp()
{
	string sectName = GetEventData();
	if(sectName!="WorldMap_Date_Clock") return;

	// Заполним экран содержимым
		// каринки
	SetNewPicture("HELPPICTURE","interfaces\helppictures\WM_DateClock.tga");
		// строки
	int strFileID = LanguageOpenFile("helpsections\WorldMap_ClockWeather.txt");
	SetFormatedText("TEXTWINDOW",LanguageConvertString(strFileID,"Clock_Weather_info"));
	GameInterface.strings.HelpName = LanguageConvertString(strFileID,"Clock_Weather_title");
	LanguageCloseFile(strFileID);
}

void WorldMap_Date_Clock_ResetHelp()
{
	string sectName = GetEventData();
	if(sectName!="WorldMap_Date_Clock") return;

	// Удалим с эрана все
	SetNewPicture("HELPPICTURE","");
	SetFormatedText("TEXTWINDOW","");
}
