#event_handler("InitHelpSegment","Dialog_window_InitHelp");
#event_handler("ResetHelpSegment","Dialog_window_ResetHelp");

void Dialog_window_InitHelp()
{
	string sectName = GetEventData();
	if(sectName!="Dialog_window") return;

	// Заполним экран содержимым
		// каринки
	SetNewPicture("HELPPICTURE","interfaces\helppictures\Dialog_window.tga");
		// строки
	int strFileID = LanguageOpenFile("helpsections\dialog_window.txt");
	SetFormatedText("TEXTWINDOW",LanguageConvertString(strFileID,"dialog_window_info"));
	GameInterface.strings.HelpName = LanguageConvertString(strFileID,"dialog_window_title");
	LanguageCloseFile(strFileID);
}

void Dialog_window_ResetHelp()
{
	string sectName = GetEventData();
	if(sectName!="Dialog_window") return;

	// Удалим с эрана все
	SetNewPicture("HELPPICTURE","");
	SetFormatedText("TEXTWINDOW","");
}
