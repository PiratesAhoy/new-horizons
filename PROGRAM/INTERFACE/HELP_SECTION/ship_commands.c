#event_handler("InitHelpSegment","ship_commands_InitHelp");
#event_handler("ResetHelpSegment","ship_commands_ResetHelp");

void ship_commands_InitHelp()
{
	string sectName = GetEventData();
	if(sectName!="ship_commands") return;

	// Заполним экран содержимым
		// каринки
	SetNewPicture("HELPPICTURE","interfaces\helppictures\ship_commands.tga");
		// строки
	int strFileID = LanguageOpenFile("helpsections\ships_command_menu.txt");
	SetFormatedText("TEXTWINDOW",LanguageConvertString(strFileID,"ships_command_info"));
	GameInterface.strings.HelpName = LanguageConvertString(strFileID,"ships_command_title");
	LanguageCloseFile(strFileID);
}

void ship_commands_ResetHelp()
{
	string sectName = GetEventData();
	if(sectName!="ship_commands") return;

	// Удалим с эрана все
	SetNewPicture("HELPPICTURE","");
	SetFormatedText("TEXTWINDOW","");
}
