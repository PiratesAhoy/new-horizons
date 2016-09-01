#event_handler("InitHelpSegment","WorldMap_Compas_InitHelp");
#event_handler("ResetHelpSegment","WorldMap_Compas_ResetHelp");

void WorldMap_Compas_InitHelp()
{
	string sectName = GetEventData();
	if(sectName!="WorldMap_Compas") return;

	// Заполним экран содержимым
		// каринки
	SetNewPicture("HELPPICTURE","interfaces\helppictures\WM_Compas.tga");
		// строки
	int strFileID = LanguageOpenFile("helpsections\WorldMap_Compas.txt");
	SetFormatedText("TEXTWINDOW",LanguageConvertString(strFileID,"Compas_info"));
	GameInterface.strings.HelpName = LanguageConvertString(strFileID,"Compas_title");
	LanguageCloseFile(strFileID);
}

void WorldMap_Compas_ResetHelp()
{
	string sectName = GetEventData();
	if(sectName!="WorldMap_Compas_Clock") return;

	// Удалим с эрана все
	SetNewPicture("HELPPICTURE","");
	SetFormatedText("TEXTWINDOW","");
}
