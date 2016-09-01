#define LEFT_CHARACTER	0
#define RIGHT_CHARACTER	1

void InitInterface(string iniName)
{
	GameInterface.title = "titleCharacterSelect";
	GameInterface.faces.current = 0;
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();//MAXIMUS: standard exit-string for exit-button
	//SetEventHandler("InterfaceBreak","DoSelect",0);
	SetEventHandler("DoSelect","DoSelect",0);
}

void DoSelect()
{
	int newPersNum=0;
	newPersNum = sti(GameInterface.faces.current);

	switch(newPersNum)
	{
	case LEFT_CHARACTER:
		SetMainCharacterIndex(1);
		break;
	case RIGHT_CHARACTER:
		SetMainCharacterIndex(0);
		break;
	}
	//DelEventHandler("InterfaceBreak","DoSelect");
	DelEventHandler("DoSelect","DoSelect");
    interfaceResultCommand = RC_INTERFACE_CHARACTER_SELECT_EXIT;
    EndCancelInterface(true);
}
