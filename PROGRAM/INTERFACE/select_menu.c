
// **********************************************************
//
// select_menu.c
//
// this whole thing overhauled by KAM ^_^
//
// **********************************************************


bool exitBool = true;
ref PChar;
string PCharName;

void InitInterface(string iniName)
{
	PChar = GetMainCharacter();
	if (CheckAttribute(&PChar,"firstname"))
	{
		PCharName = PChar.firstname;
	}
	else
	{
		PCharName = PChar.name;
	}

//	GameInterface.title = "titleSelect";

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();//MAXIMUS: standard exit-string for exit-button

	CreateString(true,"CharactersTitle","",FONT_NORMAL,COLOR_NORMAL,165,58,SCRIPT_ALIGN_CENTER,1.0);
	GameInterface.strings.CharactersTitle = "Characters";

	CreateString(true,"MainCharacterTitle","",FONT_NORMAL,COLOR_NORMAL,165,182,SCRIPT_ALIGN_CENTER,1.0);
	GameInterface.strings.MainCharacterTitle = PCharName;

	CreateString(true,"NationsTitle","",FONT_NORMAL,COLOR_NORMAL,165,310,SCRIPT_ALIGN_CENTER,1.0);
	GameInterface.strings.NationsTitle = "Nations";

	CreateString(true,"ShipsTitle","",FONT_NORMAL,COLOR_NORMAL,475,53,SCRIPT_ALIGN_CENTER,1.0);
	GameInterface.strings.ShipsTitle = "Ships";

	CreateString(true,"CrewTitle","",FONT_NORMAL,COLOR_NORMAL,475,279,SCRIPT_ALIGN_CENTER,1.0);
	GameInterface.strings.CrewTitle = "Crew";
	// NK add date 05-04-17
	int d, m, y; d = GetDataDay(); m = GetDataMonth(); y = GetDataYear();
	string day = GetDayName(GetWeekday(d, m, y));
	string month = GetMonthName(m);
	//CreateString(true,"GameDate","",FONT_NORMAL,COLOR_NORMAL,320,40,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"GameDate","",FONT_NORMAL,COLOR_NORMAL,32,32,SCRIPT_ALIGN_LEFT,1.0);
	GameInterface.strings.GameDate = day + " " + d + " " + month + " " + y;
	CreateString(true,"GameTime","",FONT_NORMAL,COLOR_NORMAL,608,32,SCRIPT_ALIGN_RIGHT,1.0);
	GameInterface.strings.GameTime = "Time: " + GetStringTime(GetTime());
	// NK <--

	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"BACKPICTURE",3, "interfaces\mainback");

	// NK to allow chr menu during boarding 04-09-07, fixed 04-09-09
	if(bSeaActive && bAbordageStarted && !bDeckEnter && PChar.location != "Tutorial_Deck") // FB#1 04-09-21 fixed // KK: was "!bCabinStarted" instead "!bDeckEnter"
	{
		SetSelectable("I_CHARACTER",true);
		SetSelectable("I_PASSENGER",false);
		SetSelectable("I_SHIP",false);
		SetSelectable("I_SHIPHOLD",false);
		SetSelectable("I_KAM_SHIPTRANSFER",false);
		SetSelectable("I_KAM_SHIPBERTHING",false);
		SetSelectable("I_KAM_SELECTSAILS",false);
		SetSelectable("I_KAM_RATIONS",false);
		SetSelectable("I_KAM_ARTICLES",false);
		SetSelectable("I_MONEY",false);
		SetSelectable("I_NATIONS",false);
		SetSelectable("I_TRADEBOOK",false);
		SetSelectable("I_QUESTBOOK",false);
		SetSelectable("I_ITEMS",true);
	}
	else
	{
		SetSelectable("I_CHARACTER",true);
		SetSelectable("I_PASSENGER",true);
		SetSelectable("I_SHIP",true);
		SetSelectable("I_SHIPHOLD",true);
		SetSelectable("I_KAM_SHIPTRANSFER",true);
		SetSelectable("I_KAM_SHIPBERTHING",true);
		SetSelectable("I_KAM_SELECTSAILS",true);
		SetSelectable("I_KAM_RATIONS",true);
		SetSelectable("I_KAM_ARTICLES",true);
		SetSelectable("I_MONEY",true);
		SetSelectable("I_NATIONS",true);
		SetSelectable("I_TRADEBOOK",true);
		SetSelectable("I_QUESTBOOK",true);
		SetSelectable("I_ITEMS",true);
	}
	// NK <--

// added after build 11 by KAM -->
	if (bSeaActive == false && PChar.location != "Tutorial_Deck")
	{
		SetSelectable("I_KAM_SHIPTRANSFER",true);
	}
	else
	{
		if(bSeaActive && !bDisableMapEnter) { SetSelectable("I_KAM_SHIPTRANSFER",true); } // NK so you can transfer when can enter map 04-09-16
		else { SetSelectable("I_KAM_SHIPTRANSFER",false); }
	}
// <-- added after build 11 by KAM

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
	SetEventHandler("evntDoPostExit","DoPostExit",0);
}

void ProcessCancelExit()
{
	IDoExit( RC_INTERFACE_SELECTMENU_EXIT );
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcessCommandExecute");
	DelEventHandler("evntDoPostExit","DoPostExit");

	interfaceResultCommand = exitCode;
	if( CheckAttribute(&InterfaceStates,"InstantExit") && sti(InterfaceStates.InstantExit)==true ) {
		exitBool = true;
	}
	if(exitBool)	DeleteAttribute(&InterfaceStack,"SelectMenu_node");
	EndCancelInterface(exitBool);
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	if(comName=="activate" || comName=="click")
	{
		PostEvent("evntDoPostExit",1,"l",RC_INTERFACE_SELECTMENU_EXIT);
		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
	}
}

void DoPostExit()
{
	int exitCode = GetEventData();
	exitBool = false;
	IDoExit(exitCode);
}
