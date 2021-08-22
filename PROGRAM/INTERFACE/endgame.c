void InitInterface(string iniName)
{
	ref mchref = GetMainCharacter();

	if(bAnimation) iniName = "RESOURCE\INI\NEW_INTERFACES\ANIMATION\endgame.ini";
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	SetNodeUsing("VIDEOPIE",bAnimation);

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
    SetEventHandler("exitCancel","ProcessCancelExit",0);
}

void ProcessCancelExit()
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("exitCancel","ProcessCancelExit");
	interfaceResultCommand = RC_INTERFACE_ENDGAME_EXIT;
    EndCancelInterface(true);
}
