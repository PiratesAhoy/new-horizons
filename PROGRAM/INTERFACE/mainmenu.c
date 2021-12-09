#define MAINMENU_TIME_DELAY		45

void InitInterface(string iniName)
{
	GameInterface.title = "# ";

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

	SetSelectable("B_NEWGAME",sti(InterfaceStates.Buttons.New.enable));
	SetSelectable("B_RESUMEGAME",sti(InterfaceStates.Buttons.Resume.enable));
	SetSelectable("B_LOAD",sti(InterfaceStates.Buttons.Load.enable));
	SetSelectable("B_SAVE",sti(InterfaceStates.Buttons.Save.enable));
	SetSelectable("B_OPTIONS",sti(InterfaceStates.Buttons.Options.enable));
	SetSelectable("B_CONTROLS",sti(InterfaceStates.Buttons.Controls.enable));
	SetSelectable("B_CREDITS",sti(InterfaceStates.Buttons.Credits.enable));
	SetSelectable("B_QUIT",sti(InterfaceStates.Buttons.Quit.enable));

	if (bSeaActive && !bMapEnter) SetSelectable("B_SAVE",false);
	if (LAi_IsBoardingProcess() || ownDeckStarted()) SetSelectable("B_SAVE",false); // PB: No save on ship's deck to prevent errors

	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"BACKPICTURE",3, "interfaces\mainback");

	string currentversion = " - Build " + BUILDVERSION;
	CreateString(true,"Version","Pirates Ahoy! Community" + currentversion,FONT_QUESTBOOK,COLOR_GREEN_LIGHT,-20,430,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Maelstrom",MAELSTROM,FONT_QUESTBOOK,COLOR_GREEN_LIGHT,-20,450,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Info","http://"+PA_INET,FONT_QUESTBOOK,COLOR_BLUE_LIGHT,-20,470,SCRIPT_ALIGN_LEFT,0.8);

	SetEventHandler("InterfaceBreak","ProcessBreakExit",0)
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ConfirmYes","ProcessDelete_yes",0);
	SetEventHandler("ConfirmNo","ProcessDelete_no",0);
	SetEventHandler("ResumeGamePress","ResumeGamePress",0);
	SetEventHandler("QuitPress","QuitPress",0);

	SetEventHandler("evntLowStorageBreak","LowStorageNext",0);

	SetEventHandler("UpPress","UpPress",0);
	SetEventHandler("DownPress","DownPress",0);
	SetEventHandler("ievnt_command","ProcCommand",0);
	SetEventHandler("BreakExit","procBreakExit",0);

	SetSelectable("B_LOAD", CheckForSaveGames()); // KK
	SetCurrentUpNode("B_SAVE");
	if(sti(InterfaceStates.Buttons.Resume.enable)) { SetCurrentNode("B_RESUMEGAME"); }//MAXIMUS

	if(!sti(InterfaceStates.Buttons.Resume.enable))//MAXIMUS
	{
		GameInterface.mainmenu.timeclock = MAINMENU_TIME_DELAY;
		SetEventHandler("evntTimeCalculate","procTimeCalculate",0);
		PostEvent("evntTimeCalculate",1000);
		if (GetMusicScheme() != "PGMUS") SetMusic("music_main_menu"); // PG // NK 04-09-17 because it's handled now in the alias ini // KK
	}
	// fix music handling 05-04-29
	if(GetMusicScheme() == "PGMUS")  // KK
	{
		ref pch = GetMainCharacter();
		pch.musfix.old = oldMusicName;
		pch.musfix.oldid = oldMusicID;
		pch.musfix.cur = musicName;
		pch.musfix.curid = musicID;
		SetMusicNoPause("music_main_menu"); // PG // NK 04-09-17 ditto
	}
	PostEvent("DoInfoShower",1,"sl","MainMenuLaunch",false);
}

void UpPress()
{
	SetCurrentUpNode(GetCurrentNode());
}

void DownPress()
{
	SetCurrentDownNode(GetCurrentNode());
}

void SetCurrentUpNode(string curNode)
{
	string nextNode="";

	switch(curNode)
	{
	case "B_NEWGAME":		nextNode = "B_QUIT";		break;
	case "B_RESUMEGAME":	nextNode = "B_NEWGAME";		break;
	case "B_LOAD":			nextNode = "B_RESUMEGAME";	break;
	case "B_SAVE":			nextNode = "B_LOAD";		break;
	case "B_OPTIONS":		nextNode = "B_SAVE";		break;
	case "B_CONTROLS":		nextNode = "B_OPTIONS";		break;
	case "B_BUILD":			nextNode = "B_CONTROLS";	break;		// added by KAM
	case "B_CREDITS":		nextNode = "B_BUILD";		break;		// changed by KAM
	case "B_QUIT":			nextNode = "B_CREDITS";		break;
	}

	if(GetSelectable(nextNode))
	{
		SetCurrentNode(nextNode);
	}
	else
	{
		if(nextNode!=GetCurrentNode())
		{
			SetCurrentUpNode(nextNode);
		}
	}
}

void SetCurrentDownNode(string curNode)
{
	string nextNod;

	switch(curNode)
	{
	case "B_NEWGAME":		nextNod = "B_RESUMEGAME";	break;
	case "B_RESUMEGAME":	nextNod = "B_LOAD";			break;
	case "B_LOAD":			nextNod = "B_SAVE";			break;
	case "B_SAVE":			nextNod = "B_OPTIONS";		break;
	case "B_OPTIONS":		nextNod = "B_CONTROLS";		break;
	case "B_CONTROLS":		nextNod = "B_BUILD";		break;		//changed by KAM
	case "B_BUILD":			nextNod = "B_CREDITS";		break;		//added by KAM
	case "B_CREDITS":		nextNod = "B_QUIT";			break;
	case "B_QUIT":			nextNod = "B_NEWGAME";		break;
	}

	if(GetSelectable(nextNod))
	{
		SetCurrentNode(nextNod);
	}
	else
	{
		if(nextNod!=GetCurrentNode())
		{
			SetCurrentDownNode(nextNod);
		}
	}
}

void ProcessCancelExit()
{
	IDoExit( RC_INTERFACE_MAIN_MENU_EXIT, true );
	if(!sti(InterfaceStates.Buttons.Resume.enable))
	{
		ResetSound();
	}
}

void ProcessBreakExit()
{
	if( GetSelectable("B_RESUMEGAME") )	IDoExit( RC_INTERFACE_MAIN_MENU_EXIT, true );
}

void NewGamePress()
{
	IDoExit( RC_INTERFACE_DO_START, false ); // added by MAXIMUS [choose character MOD]
}

void NewGameConfirm()
{
	if( sti(InterfaceStates.Buttons.Resume.enable) )
	{
		SetNodeUsing("CONFIRM_RECTANGLE",true);
		SetNodeUsing("TEXTWINDOW",true);
		SetNodeUsing("CONFIRM_YES_BUTTON",true);
		SetNodeUsing("CONFIRM_NO_BUTTON",true);
		SetNodeUsing("EN_PIC",true);
		SetCurrentNode("CONFIRM_NO_BUTTON");
		SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "CONFIRM_NO_BUTTON");
		SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "CONFIRM_YES_BUTTON");
	}
	else NewGamePress();
}

void ProcessDelete_no()
{
	SetNodeUsing("CONFIRM_RECTANGLE",false);
	SetNodeUsing("TEXTWINDOW",false);
	SetNodeUsing("CONFIRM_YES_BUTTON",false);
	SetNodeUsing("CONFIRM_NO_BUTTON",false);
	SetNodeUsing("EN_PIC",false);
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);

	SetCurrentNode("B_RESUMEGAME");
}

void ProcessDelete_yes()
{
	SetNodeUsing("CONFIRM_RECTANGLE",false);
	SetNodeUsing("TEXTWINDOW",false);
	SetNodeUsing("CONFIRM_YES_BUTTON",false);
	SetNodeUsing("CONFIRM_NO_BUTTON",false);
	SetNodeUsing("EN_PIC",false);
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);

	InterfaceStates.Buttons.Resume.enable = false;	// PB: Select Storyline reinitializes all sorts
	InterfaceStates.Buttons.Save.enable = false;	// PB: Select Storyline reinitializes all sorts

	NewGamePress();
}

void LoadPress()
{
	IDoExit( RC_INTERFACE_DO_LOAD_GAME, false );
}

void SavePress()
{
	IDoExit( RC_INTERFACE_DO_SAVE_GAME, false );
}

void OptionsPress()
{
	IDoExit( RC_INTERFACE_DO_OPTIONS, false );
}

void ControlsPress()
{
	IDoExit( RC_INTERFACE_DO_CONTROLS, false );
}

// added by MAXIMUS -->
void AboutBuildPress()
{
	IDoExit( RC_INTERFACE_DO_ABOUT_BUILD, false );
}
// added by MAXIMUS <--

void CreditsPress()
{
	SetEventHandler(EVENT_END_VIDEO,"LaunchMainMenu_afterVideo",0);
	bMainMenuLaunchAfterVideo = true;
	StartPostVideo("credits",1);
}

void QuitPress()
{
	ClearEvents();
	ClearPostEvents();

	ExitProgram();
}

void ResumeGamePress()
{
	IDoExit( RC_INTERFACE_DO_RESUME_GAME, true );
}

void IDoExit(int exitCode, bool bClear)
{
	if(bClear==true && GetSelectable("B_RESUMEGAME")) ClearScreenShoter();//MAXIMUS: used for QuickSave
	// if(PGMUS) SetMusic(oldMusicName); // PG
	// fix music handling 05-04-29
	ref pch = GetMainCharacter();
	if(CheckAttribute(pch,"musfix"))
	{
		SetMusicNoPause(pch.musfix.cur);
		oldMusicName = pch.musfix.old;
		//oldMusicID = pch.musfix.old.id;
		DeleteAttribute(pch,"musfix");
	}
	// NK <--
	DelEventHandler("InterfaceBreak","ProcessBreakExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ConfirmYes","ProcessDelete_yes");
	DelEventHandler("ConfirmNo","ProcessDelete_no");
	DelEventHandler("ResumeGamePress","ResumeGamePress");
	DelEventHandler("QuitPress","QuitPress");
	DelEventHandler("evntLowStorageBreak","LowStorageNext");
	DelEventHandler("UpPress","UpPress");
	DelEventHandler("DownPress","DownPress");
	DelEventHandler("ievnt_command","ProcCommand");
	DelEventHandler("evntTimeCalculate","procTimeCalculate");
	DelEventHandler("BreakExit","procBreakExit");
	DelEventHandler("evntTime","TimeCalculate");//MAXIMUS

	interfaceResultCommand = exitCode;
	EndCancelInterface(bClear);
}

void procTimeCalculate()
{
	int n = sti(GameInterface.mainmenu.timeclock) - 1;

	if(n>0)
	{
		GameInterface.mainmenu.timeclock = n;
		PostEvent("evntTimeCalculate",1000);
		return;
	}

	SetEventHandler(EVENT_END_VIDEO,"LaunchMainMenu_afterVideo",0);
	StartPostVideo("trailer",1);
	SetEventHandler("Control Activation","procAttractExit",1);
}

void TimeCalculate()
{
	int n = sti(GameInterface.mainmenu.timeclock1) - 1;

	if(n>0)
	{
		GameInterface.mainmenu.timeclock1 = n;
		PostEvent("evntTime",500);
		return;
	}
}

void ProcCommand()
{
	GameInterface.mainmenu.timeclock = MAINMENU_TIME_DELAY;

	string comName = GetEventData();
	string nodName = GetEventData();
	if(comName=="activate" || comName=="click")
	{
		switch(nodName)
		{
		case "B_NEWGAME":	CheckStorageSpace("newgame"); break;
		case "B_LOAD":		CheckStorageSpace("load"); break;
		case "B_SAVE":		CheckStorageSpace("save"); break;
		case "B_OPTIONS":	CheckStorageSpace("options"); break;
		case "B_CONTROLS":	CheckStorageSpace("controls"); break;
		case "B_BUILD":		CheckStorageSpace("build"); break;
		case "B_CREDITS":	CheckStorageSpace("credits"); break;
		}
	}
}

void procBreakExit()
{
	if( GetSelectable("B_RESUMEGAME") ) ProcessCancelExit();
}

string confirmAction="";
void CheckStorageSpace(string action)
{
	confirmAction = action;
	if( g_bOptionsBreak )
	{
		SetEventHandler("evntOptionsBreak","OptionsBreakOk",0);
		PostEvent("DoInfoShower",1,"sl","OptionsBreak",true);
		return;
	}
	if( GetTargetPlatform()=="xbox" )
	{
		int nFreeBlocks = SendMessage(&GameInterface, "l", MSG_INTERFACE_GET_FREE_SPACE);
		if( nFreeBlocks < MAX_SAVE_STORE_BLOCKS ) {
			PostEvent("DoInfoShower",1,"sl","Low Storage",true);
			return;
		}
	}
	PostEvent("evntLowStorageBreak",1);
}
void LowStorageNext()
{
	switch(confirmAction)
	{
	case "newgame":		NewGameConfirm(); break;
	case "load":		LoadPress(); break;
	case "save":		SavePress(); break;
	case "options":		OptionsPress(); break;
	case "controls":	ControlsPress(); break;
	case "build":		AboutBuildPress(); break;
	case "credits":		CreditsPress(); break;
	}
}

void OptionsBreakOk()
{
	DelEventHandler("evntOptionsBreak","OptionsBreakOk");
	//SaveGameOptions();
	g_bOptionsBreak = false;
	CheckStorageSpace(confirmAction);
	//LoadGameOptions();
}

// KK -->
bool CheckForSaveGames()
{
	ref rSP; makeref(rSP, SaveProfiles);
	int iNum = GetStorylinesQuantity();
	for (int i = 0; i < iNum; i++)
	{
		string storyline = GetStoryline(i);
		if (GetAnyProfileSavesQuantity(storyline) > 0) return true;
	}
	return false;
}
// <-- KK
