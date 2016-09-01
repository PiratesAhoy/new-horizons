void InitInterface(string iniName)
{
	if (bSeaActive)
		Event("BI_EVENT_SET_VISIBLE", "l", false);
	else
		BLIVisible(false);

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

	CreateStringCheckCase(true,"Message",XI_ConvertString("INSTALL_ERROR"),"interface_title",COLOR_NORMAL,320,160,SCRIPT_ALIGN_CENTER,0.9,true);
	CreateString(true,"line1","You MUST install using the Installer EXE!",FONT_NORMAL,COLOR_NORMAL,320,210,SCRIPT_ALIGN_CENTER,0.8);
	CreateString(true,"line2","Do *not* use the default Program Files folder",FONT_NORMAL,COLOR_NORMAL,320,240,SCRIPT_ALIGN_CENTER,0.8);

	SetEventHandler("QuitPress","QuitPress",0);
}

void QuitPress()
{
	ClearEvents();
	ClearPostEvents();

	ExitProgram();
}