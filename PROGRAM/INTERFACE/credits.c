float gCreditsProgress;

void InitInterface(string ini_name)
{
	GameInterface.title = "";
	SendMessage(&GameInterface, "ls", MSG_INTERFACE_INIT, ini_name);

	SetEventHandler("InterfaceBreak", "ProcessCancelExit", 0);
	SetEventHandler("exitCancel", "ProcessCancelExit", 0);

	SetFormatedText("INFO_TEXT", "Hello, Credits!");
}

void ProcessCancelExit()
{
	IDoExit(RC_INTERFACE_CREDITS_EXIT);
	if(!CheckAttribute(&InterfaceStates,"InstantExit") || sti(InterfaceStates.InstantExit)==false) ReturnToMainMenu();
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("exitCancel","ProcessCancelExit");

	interfaceResultCommand = exitCode;
	if(CheckAttribute(&InterfaceStates,"InstantExit") && sti(InterfaceStates.InstantExit)==true) EndCancelInterface(true);
	else EndCancelInterface(false);
}
