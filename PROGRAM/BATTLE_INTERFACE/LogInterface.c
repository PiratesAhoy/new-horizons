#include "battle_interface\log_msg.h"
extern void CreateLandActionsEnvironment_WR(); // PB: Create external function
extern void CreateLandActionsEnvironment_BUG(); // PB: Create external function
extern void CreateLandActionsEnvironment_BART(); // PB: Create external function

#define LOG_FOR_SEA		1
#define LOG_FOR_LAND	2

object showWindow;

object IActions, ILog, IDateTimeDisplay; // KK

object IBoardingStatus;
bool   bYesBoardStatus;
string g_ActiveActionName;

//bool bEternalString = false; // KK
string sDateTimeDisplay = ""; // KK

bool bHourBellPlayed=false; // HKE
bool bAiupdated = false; // Screwface

bool bIslandChecked=false;	// LDH 07Jan09

#event_handler("blieGetMsgIconRoot","BI_GetMsgIconRoot");
#event_handler("evntUpdateTime", "procUpdateTime");

void InitLogInterface()
{
	SetEventHandler("SetWindowSize","LI_SetWindowSize",0);
	CreateEntity(&IActions,"ActionIntrface");
	CreateEntity(&ILog, "ILogAndActions"); // KK
	DelEventHandler("SetWindowSize","LI_SetWindowSize");
	DeleteAttribute(&IActions,"");
	DeleteAttribute(&ILog, ""); // KK
	CreateLogEnvironment();
// --> KK
	//SendMessage(&IActions,"lll",LOG_AND_ACTIONS_INIT,sti(InterfaceStates.BattleShow.FastCommand),sti(InterfaceStates.BattleShow.ActionLabel));
	//SendMessage(&ILog,"lll",LOG_AND_ACTIONS_INIT,sti(InterfaceStates.BattleShow.FastCommand),sti(InterfaceStates.BattleShow.LogString));
// <-- KK
	SetEventHandler(EVENT_LOCATION_LOAD,"LI_LocationLoad",0);
	SetEventHandler("BI_FastCommand","BI_FastCommand",0);
	SetEventHandler(BI_EVENT_SET_VISIBLE,"SetLogInterfaceVisible",0);
// KK -->
	LayerAddObject("execute", &ILog, -257);
	LayerAddObject("realize", &ILog, -257);
	LayerAddObject(SEA_EXECUTE, &ILog,-257);
	LayerAddObject(SEA_REALIZE, &ILog, -257);
	LayerAddObject("execute", &IActions, -257);
	LayerAddObject("realize", &IActions, -257);
	LayerAddObject(SEA_EXECUTE, &IActions, -257);
	LayerAddObject(SEA_REALIZE, &IActions, -257);
// <-- KK
	InitActivePerkShower();
}

void LI_SetWindowSize()
{
	int w = GetEventData();
	int h = GetEventData();
	int bTVused = GetEventData();
	if(bTVused)	SetShowWindowParameters(bTVused,w,h,40,24,w-40,h-24);
	else	SetShowWindowParameters(bTVused,w,h,0,0,w,h);
}

void SetLogInterfaceVisible()
{
	int visibleFlag = GetEventData();
	ILog.visible = visibleFlag; // KK
	SendMessage(&ILog,"ll",LI_SET_VISIBLE,visibleFlag);
}

// KK -->
void LogVisible(bool visibleFlag)
{
	ILog.visible = visibleFlag;
	SendMessage(&ILog, "ll", LI_SET_VISIBLE, visibleFlag);
}

void ActionsVisible(bool visibleFlag)
{
	IActions.visible = visibleFlag;
	SendMessage(&IActions, "ll", LI_SET_VISIBLE, visibleFlag);
}

void DateTimeVisible(bool visibleFlag)
{
	IDateTimeDisplay.visible = visibleFlag;
	SendMessage(&IDateTimeDisplay, "ll", LI_SET_VISIBLE, visibleFlag);
}

void LogsVisible(bool visibleFlag)
{
	ActionsVisible(visibleFlag);
	LogVisible(visibleFlag);
	if (isEntity(&IDateTimeDisplay)) DateTimeVisible(visibleFlag);
}

void SwapActionsAndLog(bool visibleFlag)
{
	ActionsVisible(visibleFlag);
	LogVisible(!visibleFlag);
}

bool IsActionsVisible()
{
	ref rtmp;
	makeref(rtmp, IActions);
	if (!CheckAttribute(rtmp, "visible")) rtmp.visible = false;
	return sti(rtmp.visible);
}

bool IsLogVisible()
{
	ref rtmp;
	makeref(rtmp, ILog);
	if (!CheckAttribute(rtmp, "visible")) rtmp.visible = false;
	return sti(rtmp.visible);
}
// <-- KK

void LI_LocationLoad()
{
	InitDateTimeDisplay(); // KK
	CreateILogAndActions(LOG_FOR_LAND);
}

void InitBattleInterfacesParameters()
{
	DeleteClass(&IBoardingStatus);
	DeleteAttribute(&IBoardingStatus,"");
	bYesBoardStatus = false;
}

void CreateILogAndActions(int loadType)
{
	DeleteAttribute(&IBoardingStatus,"ActiveActions");
	if(loadType==LOG_FOR_SEA)
	{
		CreateSeaActionsEnvironment();
	}
	if(loadType==LOG_FOR_LAND)
	{
		CreateLandActionsEnvironment();
	}
// KK -->
	ref rLog; makeref(rLog, ILog);
	DeleteAttribute(rLog, "");
	CopyAttributes(rLog, &IActions);
	IActions.Log.up = sti(showWindow.top) + RecalculateVIcon(sti(IActions.ActiveActions.height)) + RecalculateVIcon(16);
	IActions.Log.left = sti(showWindow.left) + RecalculateHIcon(16);
	IActions.Log.color = argb(0,255,255,255);	// LDH 19Jan09
	SendMessage(&IActions,"lll",LOG_AND_ACTIONS_INIT,sti(InterfaceStates.BattleShow.FastCommand),sti(InterfaceStates.BattleShow.ActionLabel));
	SendMessage(&ILog,"lll",LOG_AND_ACTIONS_INIT,false,sti(InterfaceStates.BattleShow.LogString));

	if (isEntity(&IDateTimeDisplay)) CreateDateTimeDisplay();
// <-- KK
	Log_SetActiveAction(g_ActiveActionName);
}

void Log_SetActiveAction(string actionName)
{
// KK -->
	if (actionName == "Reload" && GetReloadMapAttrib(FindLoadedLocation(), chrWaitReloadLocator, "go") == "") return;
	if (actionName == "Nothing") {
		SendMessage(&IActions, "l", LI_CLEAR_STRINGS);
		ILog.Log.up = sti(ILog.Log.org.up);
	} else {
		ILog.Log.up =  sti(showWindow.top) + RecalculateVIcon(sti(IActions.Log.up)) + 32;
	}
// <-- KK
	SendMessage(&ILog,"lll",LOG_AND_ACTIONS_INIT,sti(InterfaceStates.BattleShow.FastCommand),sti(InterfaceStates.BattleShow.LogString));
	g_ActiveActionName = actionName;
	SendMessage(&IActions,"ls",LOG_SET_ACTIVE_ACTION,actionName);
	if (TRACEALLLOGS == 1) Trace("Log - SetActiveAction: " + actionName);
}

// KK -->
void Log_SetActionLabel(string label)
{
	SendMessage(&IActions, "l", LI_CLEAR_STRINGS);
	if (label == "") return;
	SendMessage(&IActions, "lls", LOG_ADD_STRING, true, label);
}
// <-- KK

void Log_SetStringToLog(string strLog)
{
	SendMessage(&ILog,"lls",LOG_ADD_STRING, false, strLog);
	if (TRACEALLLOGS == 1)
	{
		Trace("Log - SetStringToLog: " + strLog);
	}
}

/*void Log_SetStringToLog(string strLog)
{//MAXIMUS: will store log-strings while player is on reload-locator, or speaks with NPC, or near some box. All logs will be shown later.
	aref refStrings;
	if(chrWaitReloadLocator!="" || CheckAttribute(GetMainCharacter(),"Interlocutor.update") || CheckAttribute(GetMainCharacter(),"BoxName.update"))
	{
		makearef(refStrings,IActions.storedstrings);
		string newStr = "str"+GetAttributesNum(refStrings);
		refStrings.(newStr) = strLog;
		return;
	}
	else
	{
		makearef(refStrings,IActions.storedstrings);
		if(GetAttributesNum(refStrings)>0)
		{
			int num = GetAttributesNum(refStrings);
			for(int i=0; i<num; i++)
			{
				string strData = "str"+i;
				if(CheckAttribute(refStrings,strData))
				{
					SendMessage(&IActions,"lls",LOG_ADD_STRING, false, refStrings.(strData));
					DeleteAttribute(refStrings,strData);
				}
			}
		}
		DeleteAttribute(&IActions,"storedstrings");
	}
	SendMessage(&IActions,"lls",LOG_ADD_STRING, false, strLog);
	if (TRACEALLLOGS == 1) Trace("Log - SetStringToLog: " + strLog);
}*/

void Log_SetEternalString(string strLog)
{
	SendMessage(&ILog,"lls",LOG_ADD_STRING, true, strLog);
	if (TRACEALLLOGS == 1) Trace("Log - SetEternalString: " + strLog);
}

void CreateLogEnvironment()
{
	//  CCC Make log message smaller and relocate  -->
	ILog.Log.width = sti(showWindow.left) + makeint(stf(showWindow.width) * 0.5) - 1; //KK sti(showWindow.sw)/2;
	ILog.Log.height = sti(showWindow.sh)-80;
	ILog.Log.left = sti(showWindow.left)+1; // ccc maptweak original value +88
	ILog.Log.up = sti(showWindow.top)+1; //+16
	ILog.Log.font = "interface_small"; // interface_normal
	ILog.Log.color = argb(0,255,255,255);
	ILog.Log.offsetString = 14; //24
	ILog.Log.speed = 0.1; //0.05		// LDH this is the scroll speed after the log fades - 03Jan09
	ILog.Log.color_speed = 0.01; //0.02	// LDH this is the speed at which the log fades - 03Jan09
	// NOTE: The last two lines determine how fast the message disappears and scrolls. If you want to change this: INCREASING the values makes it vanish FASTER
//  <--  CCC Make log message smaller and relocate
// KK -->
	ILog.Log.org.up = sti(ILog.Log.up);

	ref rActions;
	makeref(rActions, IActions);
	DeleteAttribute(rActions, "");
	CopyAttributes(rActions, &ILog);
// <-- KK
}

void CreateSeaActionsEnvironment()
{
	IActions.ActiveActions.TextureName = "battle_interface\cicons_command.tga";
	IActions.ActiveActions.horzQ = 8;
	IActions.ActiveActions.vertQ = 8; // FCoHS
	IActions.ActiveActions.width = RecalculateHIcon(64);
	IActions.ActiveActions.height = RecalculateVIcon(64);
	IActions.ActiveActions.left = sti(showWindow.left)+16;
	IActions.ActiveActions.top = sti(showWindow.top)+16;

	IActions.ActiveActions.Moor.IconNum		= 1;
	IActions.ActiveActions.Board.IconNum		= 2;
	IActions.ActiveActions.LandTroops.IconNum	= 8;
	IActions.ActiveActions.Map.IconNum		= 9;
	IActions.ActiveActions.Transfer.IconNum		= 10;
	IActions.ActiveActions.EnterFort.IconNum = 0; // KK
	IActions.ActiveActions.Nothing.IconNum	= -1;
}

void CreateLandActionsEnvironment()
{
	ref PChar = GetMainCharacter();		//JRH

	IActions.ActiveActions.TextureName = "battle_interface\land_fast_commands.tga";
	IActions.ActiveActions.horzQ = 8;
	IActions.ActiveActions.vertQ = 8; // KK // MAXIMUS
	IActions.ActiveActions.width = RecalculateHIcon(64);
	IActions.ActiveActions.height = RecalculateVIcon(64);
	IActions.ActiveActions.left = sti(showWindow.left)+16;
	IActions.ActiveActions.top = sti(showWindow.top)+16;

// MAXIMUS & KK -->
	IActions.ActiveActions.Nothing.IconNum			= -1;
	IActions.ActiveActions.Closed.IconNum				= 0;
	IActions.ActiveActions.Reload.IconNum				= 1;
	IActions.ActiveActions.ToAcademy.IconNum			= 1;
	// KK IActions.ActiveActions.OpenBox.IconNum		= 2;
	IActions.ActiveActions.Action.IconNum				= 2;
	IActions.ActiveActions.Pick.IconNum				= 2;
	IActions.ActiveActions.Look.IconNum				= 3;
	IActions.ActiveActions.Talk.IconNum				= 4;
	IActions.ActiveActions.ToBoat.IconNum				= 5;
	IActions.ActiveActions.OpenWeaponsLocker.IconNum	= 6;
	IActions.ActiveActions.ToArsenal.IconNum			= 6;
	IActions.ActiveActions.OpenBarrel.IconNum			= 7;
	IActions.ActiveActions.ToStore.IconNum			= 8;
	IActions.ActiveActions.ToShipyard.IconNum			= 9;
	IActions.ActiveActions.ToTavern.IconNum			= 10;
	IActions.ActiveActions.ToResidence.IconNum		= 11;
	IActions.ActiveActions.ToUsurer.IconNum			= 12;
	IActions.ActiveActions.ToChurch.IconNum			= 13;
	IActions.ActiveActions.ToTailor.IconNum			= 14;
	IActions.ActiveActions.ToBlacksmith.IconNum		= 15;
	IActions.ActiveActions.ToPrison.IconNum			= 16;
	IActions.ActiveActions.ToFort.IconNum				= 17;
	IActions.ActiveActions.ToBrothel.IconNum			= 18;
	IActions.ActiveActions.ToShipDeck.IconNum			= 19;
	IActions.ActiveActions.ToCabin.IconNum			= 20;
	IActions.ActiveActions.ToSeaDogs.IconNum			= 21;
	IActions.ActiveActions.ToCannonsDeck.IconNum		= 22;
	IActions.ActiveActions.ToCargoHold.IconNum		= 23;
	IActions.ActiveActions.ToFightDeck.IconNum		= 24;
	IActions.ActiveActions.ToPort.IconNum				= 25;
	IActions.ActiveActions.ToSea.IconNum				= 26;
	IActions.ActiveActions.ToTown.IconNum				= 27;
	IActions.ActiveActions.ToJungle.IconNum			= 28;
	IActions.ActiveActions.OpenBox.IconNum			= 29;
	IActions.ActiveActions.Corpse.IconNum				= 30;
	IActions.ActiveActions.Idol.IconNum				= 31;
	IActions.ActiveActions.ToShore.IconNum			= 32;//MAXIMUS
	IActions.ActiveActions.TalkWith.IconNum			= 4;//MAXIMUS
	IActions.ActiveActions.ToMap.IconNum			= 33; // KK
	IActions.ActiveActions.ToGunsmith.IconNum		= 36; // JRH
	IActions.ActiveActions.ToOpium.IconNum			= 37; // JRH
	IActions.ActiveActions.ToDoctor.IconNum			= 52; // JRH
	IActions.ActiveActions.ToSailmaker.IconNum		= 54; // JRH
	IActions.ActiveActions.ToLibrary.IconNum		= 38; // JRH
	IActions.ActiveActions.ToMaltese.IconNum		= 39; // JRH
	IActions.ActiveActions.ToIndianStore.IconNum	= 40; // JRH
	IActions.ActiveActions.ToTavern2.IconNum		= 41; // JRH
	IActions.ActiveActions.ToEITC.IconNum			= 42; // JRH
	IActions.ActiveActions.ToDWIC.IconNum			= 43; // JRH
	IActions.ActiveActions.ToAcademy.IconNum		= 44; // JRH
	IActions.ActiveActions.ToCdC.IconNum			= 45; // GR
	IActions.ActiveActions.ToFWIC.IconNum			= 46; // GR

	// PB: Treasure Chest locators -->
	if(GetAttribute(Pchar, "boxname") == "treasure_box")
	{
		switch(GetAttribute(PChar, "required_item."+PChar.location))
		{
			case "Minerspick":
				IActions.ActiveActions.OpenBox.IconNum	= 35;
				break;
			case "Minerscrow":
				IActions.ActiveActions.OpenBox.IconNum	= 34;
				break;
		}
	}
	// PB: Treasure Chest locators <--

	// JRH -->
	if(Pchar.location == "Santo_Domingo_town")
	{
		if (CheckAttribute(PChar, "boxname") && Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum	= 63;
		if (CheckAttribute(PChar, "boxname") && Pchar.boxname == "box2") IActions.ActiveActions.OpenBox.IconNum	= 63;
	}

	if (Pchar.location == "Cartagena_center_facade") IActions.ActiveActions.OpenBox.IconNum	= 63;

	if(Pchar.location == "Cartagena_hotel_room1")
	{
		if (CheckAttribute(PChar, "boxname") && Pchar.boxname == "box4") IActions.ActiveActions.OpenBox.IconNum	= 63;
	}

	if(Pchar.location == "Cartagena_hotel_room2")
	{
		if (CheckAttribute(PChar, "boxname") && Pchar.boxname == "box4") IActions.ActiveActions.OpenBox.IconNum	= 63;
	}

	if(Pchar.location == "Cartagena_hotel_private")
	{
		if (CheckAttribute(PChar, "boxname") && Pchar.boxname == "box5") 
		{
			if(CheckCharacterItem(Pchar,"hotel_keys"))
			{
				IActions.ActiveActions.OpenBox.IconNum	= 2;
			}
			else IActions.ActiveActions.OpenBox.IconNum	= 0;
		}
	}

	if(Pchar.location == "Turks_church")
	{
		if (CheckAttribute(PChar, "boxname"))
		{
			if(Pchar.boxname == "box1") IActions.ActiveActions.OpenBox.IconNum	= 60;
		}
	}

	if(Pchar.location == "New_cloister_library")
	{
		if (CheckAttribute(PChar, "boxname"))
		{
			if(Pchar.boxname == "box8" || Pchar.boxname == "box9" || Pchar.boxname == "box10" || Pchar.boxname == "box11" 
			|| Pchar.boxname == "box12" || Pchar.boxname == "box14" || Pchar.boxname == "box15" 
			|| Pchar.boxname == "box18" || Pchar.boxname == "box19" || Pchar.boxname == "box20")
			{
				IActions.ActiveActions.OpenBox.IconNum	= 62;
			}
			else 
			{
				if(Pchar.boxname == "box13") 
				{
					IActions.ActiveActions.OpenBox.IconNum	= 1;
				}
				else IActions.ActiveActions.OpenBox.IconNum	= 29;
			}
		}
	}
	// <-- JRH

	if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0)
	{
		LoadStorylineFile("", "SL_utils.c");	// PB: To Prevent Errors
		CreateLandActionsEnvironment_WR();
		return;
	}
	if(sti(GetStorylineVar(FindCurrentStoryline(), "BUG_PUZZLES")) > 0)
	{
		LoadStorylineFile("", "SL_utils.c");	// PB: To Prevent Errors
		CreateLandActionsEnvironment_BUG();
		return;
	}
	if(sti(GetStorylineVar(FindCurrentStoryline(), "BART_PUZZLES")) > 0)
	{
		LoadStorylineFile("", "SL_utils.c");	// PB: To Prevent Errors
		CreateLandActionsEnvironment_BART();
		return;
	}
}

void DrawCharacterHP(float myHP,float enemyHP)
{
	if(bYesBoardStatus==false)
	{
		CreateEntity(&IBoardingStatus,"IBoardingStatus");
		IBoardingStatus.myLeft = sti(showWindow.left)+16;
		IBoardingStatus.myTop = sti(showWindow.bottom)-140;
		IBoardingStatus.enemyLeft = sti(showWindow.left)+16;
		IBoardingStatus.enemyTop = sti(showWindow.bottom)-128;
		IBoardingStatus.height = RecalculateVIcon(8);
		IBoardingStatus.width = RecalculateHIcon(120);
		IBoardingStatus.myColor = argb(255,0,0,128);
		IBoardingStatus.enemyColor = argb(255,128,0,0);
		SendMessage(&IBoardingStatus,"l",LOG_INIT_CHARCTER_HP);
		bYesBoardStatus = true;
	}
	if(myHP==0)
	{
		bYesBoardStatus=false;
		DeleteClass(&IBoardingStatus);
		DeleteAttribute(&IBoardingStatus,"");
	}
	if(enemyHP==0)
	{
		bYesBoardStatus=false;
		DeleteClass(&IBoardingStatus);
		DeleteAttribute(&IBoardingStatus,"");
	}
	SendMessage(&IBoardingStatus,"lff",LOG_SET_CHARCTER_HP,myHP,enemyHP);
}

void BI_FastCommand()
{
	int tmpi;
	string FComName = GetEventData();

	if( LAi_IsDead(GetMainCharacter()) ) return;

	if(bSeaActive && !bAbordageStarted)
	{
		switch(FComName)
		{
			case "Moor":
				bDisableAllCommands = true; // KK
				PostEvent("BI_SetPossibleCommands", 0.0, "l", -1); // KK
				Sea_LandLoad();
			break;
			case "Board":		Sea_AbordageLoad(SHIP_ABORDAGE,true);	break;
			case "LandTroops":	Sea_AbordageLoad(FORT_ABORDAGE,true);	break;
			case "Map":			Sea_MapLoad();	break;
// KK -->
			case "Transfer":
				if(bi_nReloadTarget!=-1)
				{
					LaunchTransferMain(GetMainCharacter(),GetCharacter(bi_nReloadTarget),"");
				}
			break;
			case "EnterFort":
				bDisableAllCommands = true;
				PostEvent("BI_SetPossibleCommands", 0.0, "l", -1);
				Sea_LandLoad();
			break;
// <-- KK
		}
	}
	else
	{
		if(CheckAttribute(GetMainCharacter(),"Quests.quest_act"))
		{
			Event("evntQuestComplete","s",Characters[GetMainCharacterIndex()].Quests.quest_act);
			return;
		}
		switch(FComName)
		{
			case "OpenBox":	OpenBoxProcedure();	break;
			case "OpenWeaponsLocker": OpenBoxProcedure();	break; // KK
			case "OpenBarrel": OpenBoxProcedure();	break; // KK
			case "Pick": Item_OnPickItem(); break;
			case "Action": Item_OnUseItem(); break;
			case "Talk":
				tmpi = SendMessage(GetMainCharacter(),"ls",MSG_CHARACTER_EX_MSG,"FindDialogCharacter");
				if(tmpi>=0) Event("dlgReady","l",tmpi);
			break;
			case "Reload": Event("Control Activation","s","ChrAction"); break;
			//case "Closed": break;
			//case "Look": break;
			case "ToSea": Event("Control Activation","s","ChrAction"); break;
			//MAXIMUS -->
			case "TalkWith"://added for showing additional icons
				tmpi = SendMessage(GetMainCharacter(),"ls",MSG_CHARACTER_EX_MSG,"FindDialogCharacter");
				if(tmpi>=0) Event("dlgReady","l",tmpi);
			break;
			case "ToBrothel": Event("Control Activation","s","ChrAction"); break;
			case "ToTavern": Event("Control Activation","s","ChrAction"); break;
			case "ToResidence": Event("Control Activation","s","ChrAction"); break;
			case "ToShipyard": Event("Control Activation","s","ChrAction"); break;
			case "ToStore": Event("Control Activation","s","ChrAction"); break;
			case "ToUsurer": Event("Control Activation","s","ChrAction"); break;
			case "ToChurch": Event("Control Activation","s","ChrAction"); break;
			case "ToAcademy": Event("Control Activation","s","ChrAction"); break;
			case "ToArsenal": Event("Control Activation","s","ChrAction"); break;
			case "ToFightDeck": Event("Control Activation","s","ChrAction"); break;
			//MAXIMUS <--
// KK -->
			case "ToTailor": Event("Control Activation", "s", "ChrAction"); break;
			case "ToBlacksmith": Event("Control Activation", "s", "ChrAction"); break;
			case "ToPrison": Event("Control Activation", "s", "ChrAction"); break;
			case "ToFort": Event("Control Activation", "s", "ChrAction"); break;
			case "ToPort": Event("Control Activation", "s", "ChrAction"); break;
			case "ToShore": Event("Control Activation", "s", "ChrAction"); break;//MAXIMUS
			case "ToBoat": Event("Control Activation", "s", "ChrAction"); break;
			case "ToShipDeck": Event("Control Activation", "s", "ChrAction"); break;
			case "ToCabin": Event("Control Activation", "s", "ChrAction"); break;
			case "ToCannonsDeck": Event("Control Activation", "s", "ChrAction"); break;
			case "ToCargoHold": Event("Control Activation", "s", "ChrAction"); break;
			case "ToSeaDogs": Event("Control Activation", "s", "ChrAction"); break;
			case "ToTown": Event("Control Activation", "s", "ChrAction"); break;
			case "ToJungle": Event("Control Activation", "s", "ChrAction"); break;
			case "ToMap": Event("Control Activation", "s", "ChrAction"); break;
			case "Corpse": OpenBoxProcedure(); break;
			case "Idol": Item_OnUseItem(); break;
// <-- KK
		}
	}
}

void ClearAllLogStrings()
{
	SendMessage(&ILog,"l",LI_CLEAR_STRINGS);
}

// KK -->
void ClearEternalString()
{
	SendMessage(&ILog,"lls",LOG_ADD_STRING, true, "");
}
// <-- KK

void BI_GetMsgIconRoot()
{
	aref arTmp;
	aref pARef[4];
	int i,idx,cn;
	ref mchr = GetMainCharacter();

 	idx = 0;
	 // This was being triggered during boarding, clause added to fix it...
	if(bSeaActive && !bAbordageStarted && !LAi_IsBoardingProcess())
	{
		for (i = 0; i < COMPANION_MAX; i++)
		{
			cn = GetCompanionIndex(mchr, i);
			if(cn<0) {continue;}
			Characters[cn].MessageIcons = true;
			makearef(arTmp,Characters[cn].MessageIcons);
			pARef[idx] = arTmp;
			idx++;
		}
		SendMessage(&BattleInterface,"le", BI_MSG_SET_MSG_ICONS, &pARef);
	}
	else
	{
		for (i = 0; i < OFFICER_MAX; i++)
		{
			cn = GetOfficersIndex(mchr, i);
			if(cn<0) {continue;}
			Characters[cn].MessageIcons = true;
			makearef(arTmp,Characters[cn].MessageIcons);
			pARef[idx] = arTmp;
			idx++;
		}
		SendMessage(&objLandInterface,"le", MSG_BATTLE_LAND_SET_MSGICONS, &pARef);
	}
}

void LoadLIStates()
{
	if(GetMainCharacterIndex()<0) return;
	int i,cn;
	ref mc = GetMainCharacter();
	ref chref;

	DeleteAttribute(mc,"MessageIcons");
	for (i = 1; i < OFFICER_MAX; i++)
	{
		cn = GetOfficersIndex(mc,i);
		if(cn>=0)
		{
			chref = GetCharacter(cn);
			DeleteAttribute(chref,"MessageIcons");
		}
	}
	for (i = 1; i < COMPANION_MAX; i++)
	{
		cn = GetCompanionIndex(mc,i);
		if(cn>=0)
		{
			chref = GetCharacter(cn);
			DeleteAttribute(chref,"MessageIcons");
		}
	}
}

// KK -->
void InitDateTimeDisplay()
{
	CreateEntity(&IDateTimeDisplay, "IDateTime_Show");
	DeleteAttribute(&IDateTimeDisplay, "");
	LayerAddObject("execute", &IDateTimeDisplay, -257);
	LayerAddObject("realize", &IDateTimeDisplay, -257);
	LayerAddObject(SEA_EXECUTE, &IDateTimeDisplay, -257);
	LayerAddObject(SEA_REALIZE, &IDateTimeDisplay, -257);
}

void DeleteDateTimeDisplay()
{
	if (isEntity(&IDateTimeDisplay)) {
		ref PChar = GetMainCharacter();
		// LDH keep the hour bells from updating again when changing islands - 11Jan09
		if (CheckAttribute(PChar, "DisplayTime")) DeleteAttribute(PChar, "DisplayTime");	// LDH 15Jan09

		bHourBellPlayed = false;		// LDH added 20Dec08
		bIslandChecked  = false;		// LDH added 07Jan09
		bAiUpdated      = false;		// Screwface
		// LDH - Moved to reload.c - 12Feb09
//		PChar.directsail.count = 0.0;	// LDH reset encounter frequency count every time we leave the 3d sea environment - 14Jan09

		DeleteClass(&IDateTimeDisplay);
	}
}

void CreateDateTimeDisplay()
{
	ref rtmp;
	makeref(rtmp, IDateTimeDisplay);
	DeleteAttribute(rtmp, "");
	CopyAttributes(rtmp, &ILog);
	IDateTimeDisplay.Log.width = RecalculateHIcon(makeint(stf(showWindow.width) * 0.5));
	IDateTimeDisplay.Log.height = RecalculateVIcon(10);
	IDateTimeDisplay.Log.left = sti(showWindow.left) + makeint(stf(showWindow.width) * 0.475);
	IDateTimeDisplay.Log.up = sti(showWindow.top) + RecalculateVIcon(10);
	IDateTimeDisplay.Log.font = "interface_normal";
	IDateTimeDisplay.Log.color = argb(0,255,255,255);
	IDateTimeDisplay.Log.offsetString = 24;
	IDateTimeDisplay.Log.speed = 1.0;
	IDateTimeDisplay.Log.color_speed = 0.0;
	SendMessage(&IDateTimeDisplay, "lll", LOG_AND_ACTIONS_INIT, false, true);

	int iyear = GetDataYear();
	int imonth = GetDataMonth();
	int iday = GetDataDay();
	sDateTimeDisplay = XI_ConvertString(GetDayName(GetWeekday(iday, imonth, iyear))) + ", " + GetHumanDate(iyear, imonth, iday);

	ref chMain = GetMainCharacter();
	bool btmp = true;
	if (iRealismMode>0 || NAVIGATION_EQUIPMENT) btmp = (CheckCharacterEquipByGroup(chMain, CLOCK_ITEM_TYPE) != "");
	if (btmp) {
		// LDH keep the hour bells from updating again when changing islands - 11Jan09
		chMain.HasClock = true;		// LDH added 15Jan09
	} else {
		chMain.HasClock = false;
		SendMessage(&IDateTimeDisplay, "lls", LOG_ADD_STRING, true, sDateTimeDisplay);
	}

	if (!CheckAttribute(chMain, "BaseCurrentTime")) chMain.BaseCurrentTime = 0.0;
	chMain.DisplayTime = true;	// LDH - causes datetime to display, added 15jan09
	bHourBellPlayed  = false;	// LDH added 20Dec08
	bIslandChecked   = false;	// LDH added 07Jan09
	bAiUpdated	= false;	// Screwface
	PostEvent("evntUpdateTime", 250.0);
}

// LDH accumulate sailing experience - 21Dec08
void AccumSailTime()
{
	ref mchr = GetMainCharacter();

//  PB: No need to limit this
//	if ( ! IsPerkIntoList("TimeSpeed"))		// not in compressed time
//	{
		if (!CheckAttribute(mchr, "SailingMinutes")) mchr.SailingMinutes = 0;
		mchr.SailingMinutes = sti(mchr.SailingMinutes) + 1;		// Note: do we want to add more if in battle?
//	}
}

// LDH time display 17Sep06
void procUpdateTime()
{
	ref mchr = GetMainCharacter();
	bool bCheckForBells = false;
	bool bCheckForIslandChange = false;		// LDH 07Jan09
	bool bCheckForAiupdate = false;			// screwface
	string timeString;
	int theHour;
	int theMinute;
	bool AddHour = true;

	if (CheckAttribute(mchr, "DisplayTime"))		// LDH changed from BaseCurrentTime - 15Jan09
	{
		float fGetTime = GetTime();					// GetTime() updates every 5 game minutes
		int iSeaTime = GetSeaTime();				// GetSeaTime() returns approx number of seconds since sea started
		if (stf(mchr.BaseCurrentTime) != fGetTime)
		{
			mchr.CurrentTime = fGetTime;
			mchr.BaseCurrentTime = fGetTime;
			mchr.TimeSeconds = iSeaTime;
			if (bSeaActive && !bAbordageStarted)					// PB: Not while on a ship deck!
			{
				AccumSailTime();	// LDH accumulate sailing experience - 21Dec08
				bCheckForBells = true;
				bCheckForIslandChange = true;
				bCheckForAiupdate = true;
			}
		}
		if (iSeaTime >= sti(mchr.TimeSeconds)+60/TIMESCALAR_SEA)	// 12 seconds, this is approximate, but works
		{
			mchr.TimeSeconds = iSeaTime;
			float CurrentTime = stf(mchr.CurrentTime);
			CurrentTime += (1.0/60.0);								// add one minute to current time
			if (CurrentTime >= 24.0) CurrentTime -= 24.0;			// LDH 16Oct06 - 24:01 should be 00:01 for example
			mchr.CurrentTime = CurrentTime;
			AccumSailTime();	// LDH accumulate sailing experience - 21Dec08
			if (bSeaActive && !bAbordageStarted)					// PB: Not while on a ship deck!
			{
				bCheckForBells = true;
				bCheckForIslandChange = true;
				bCheckForAiupdate = true;
			}
		}

		if (bCheckForBells)
		{
			//HKE -->
			// LDH simplify code - 20Dec08
			timeString = GetStringTime(stf(mchr.CurrentTime));
			theMinute = sti(strRight(timeString,2));
			if (theMinute == 0 || theMinute == 30)
			{
				if ( ! bHourBellPlayed )
				{
//TraceAndLog("TIME at hour bell: " + makeint(GetHour()) + ":" + stringRet(GetMinute()<10,"0","") + makeint(GetMinute()) );	// LDH 04Jan09
					theHour = sti(timeString);
					int numBells = (theHour % 4) * 2;
					if (theMinute == 30) numBells += 1;
					if (numBells == 0) numBells = 8;
					switch (numBells)
					{
						case 1:	PlaySound("AMBIENT\SEA\bell1_0030_0430_0830.wav"); break;
						case 2:	PlaySound("AMBIENT\SEA\bell2_0100_0500_0900.wav"); break;
						case 3:	PlaySound("AMBIENT\SEA\bell3_0130_0530_0930.wav"); break;
						case 4:	PlaySound("AMBIENT\SEA\bell4_0200_0600_1000.wav"); break;
						case 5:	PlaySound("AMBIENT\SEA\bell5_0230_0630_1030.wav"); break;
						case 6:	PlaySound("AMBIENT\SEA\bell6_0300_0700_1100.wav"); break;
						case 7:	PlaySound("AMBIENT\SEA\bell7_0330_0730_1130.wav"); break;
						case 8:	PlaySound("AMBIENT\SEA\bell8_0400_0800_1200.wav"); break;
					}
					bHourBellPlayed = true;

					// LDH get experience for manual sailing - 21Dec08
					int Exp = 0;
					if (AUTO_SKILL_SYSTEM)
					{
						if(iRealismMode>1 || OPEN_SEA_MOD){
							if (CheckAttribute(mchr, "SailingMinutes")) Exp = sti(mchr.SailingMinutes) * 0.8; // was 35 stljeffbb Jan 15 2012
						}else{
							if (CheckAttribute(mchr, "SailingMinutes")) Exp = sti(mchr.SailingMinutes) * 35;
						}
						AddPartyExpChar(mchr, "Sailing", Exp);
					}
					else
					{
						//BB was * 35, now * 15 (Aim of this section of tweaks: reduction in XP given out during Direct Sailing) - 15July2011
						if(iRealismMode>1 || OPEN_SEA_MOD){
							if (CheckAttribute(mchr, "SailingMinutes")) Exp = sti(mchr.SailingMinutes) * 0.8; // was 35 stljeffbb Jan 15 2012
							AddPartyExp(mchr, Exp * 0.2); //orig 0.5 so BB added * 0.5
						}else{
							if (CheckAttribute(mchr, "SailingMinutes")) Exp = sti(mchr.SailingMinutes) * 15;
							AddPartyExp(mchr, Exp * 0.5); //BB added * 0.5
						}
					}
					mchr.SailingMinutes = 0;

					// LDH added for direct sailing - 02Jan09
					if (theMinute == 0 && theHour != 0)
					{
						// Do daily update
						if (OPEN_SEA_MOD) 							AddHour = false;	// Turned off for open sea mod stljeffbb Jan 15 2012
						if (iRealismMode>1) 						AddHour = false;	// PB: Turned off for Iron Man Mode
						if (!DirectsailCheck(false)) 				AddHour = false;	// PB: But not if DirectSail isn't active
						if (AddHour)	// LDH added 27Jan09
						{
							Trace("== Directsail added a day to sailing time");
							WaitDate("", 0, 0, 1, 0, 0); // "", years, months, days, hours, minutes
						}
					}
				}
			}
			else
			{
				bHourBellPlayed = false;
			}
			//<-- HKE
		}

		// LDH check for island changes more often - 07Jan09
		if (bCheckForIslandChange )
		{
			timeString = GetStringTime(stf(mchr.CurrentTime));
			theMinute = sti(strRight(timeString,2));
			if (theMinute != 0 && theMinute+1 != 60 && ((theMinute+1) % DirectsailCheckFrequency) == 0)	// check every DirectsailCheckFrequency minutes
			{
				if ( ! bIslandChecked )
				{
					Trace("== Directsail called at " + timestring);
					mchr.directsail.count = stf(mchr.directsail.count) + DirectsailCheckFrequency/60.0; // update encounter frequency count
//TraceAndLog("Directsail encounter check = " + stf(mchr.directsail.count));
					DirectSailCheck(true);
					bIslandChecked = true;
				}
			}
			else
			{
				bIslandChecked = false;
			}
		}

		// SCREWFACE : UPDATE AI
		int i, num;
		if(bCheckForAiupdate && GetSeaTime() > 2) // This is true once every game second - PB: Skip AI updates and false flag detection for the first two seconds
		{
			timeString = GetStringTime(stf(mchr.CurrentTime));
			theMinute = sti(strRight(timeString,2));
			int frequency = UPDATE_AI_FREQUENCY;
			if( ( (theMinute+1)%frequency) == 0) // This is true every 'frequency' minutes
			{
				if (!bAiUpdated) // To ensure the update is performed only ONCE!
				{
					int fortidx;
					ref chr;
					aref fortattr;
					string groupe, fortstr;
					ref rGroup;

					// Check AI Tasks
					for (i=0; i<MAX_SHIP_GROUPS; i++)
					{
						rGroup = Group_GetGroupByIndex(i);
					
						groupe = GetAttribute(rGroup, "id");
						if (groupe == "-1") continue; // Skip any groups that aren't used
						if (groupe == "OurGroup") continue; // Skip player group

						if (!HasSubStr(groupe, "Directenc") && !HasSubStr(groupe, "egroup")) // DirectSail encounter don't have a location set
						{
							if (!CheckAttribute(rGroup,"AlreadyLoaded")) continue;
							if (GetAttribute(rGroup, "location") != mchr.location)	continue; // Skip any groups that aren't where the player is
						}

						//TraceAndLog("Improve AI for " + groupe);
						Improve_SeaAi(groupe); // Improve AI for this group
					}

					// PB: Check False Flags
					bool Recognized = false;
					Recognized = Recognized || CheckAllShips("forts", false);
					Recognized = Recognized || CheckAllShips("ships", false);
					if (Recognized)
					{
						if(iRealismMode<2) 
							LogIt(TranslateString("", "We are recognized, captain!"));
						RefreshBattleInterface(true);
					}

					bAiUpdated = true;
					if (CheckAttribute(mchr, "QuestsCheck")) QuestsCheck(); // PB: Check the quests every minute, but only if required
				}
				else
				{
					bAiUpdated = false;
				}
			}

			// Screwface : lagoon colour mod close to seashore reload locator
			if(mchr.location !="")
			{
				string island = mchr.location;
				int li = Findisland(island);
				//logit("island : " + island);
				if(li >= 0)
				{
					aref aCurWeather = GetCurrentWeather();
					float psX = MakeFloat(mchr.Ship.Pos.x);
					float psZ = MakeFloat(mchr.Ship.Pos.z);
					float isR = 450.0;
					//logit("ship pos x : " + psx);
					//logit("ship pos z : " + psz);
					aref rl;
					makearef(rl, Islands[li].reload);
					num = GetAttributesNum(rl);
					for(int j = 0; j < num; j++)
					{
						string tempattrname = GetAttributeName(GetAttributeN(rl,j));
						//sLandfallName = rl.(tempattrname).label;
						if (CheckAttribute(rl, tempattrname+".x"))
						{
							float ix = stf(rl.(tempattrname).x);
							float iz = stf(rl.(tempattrname).z);
							if(aCurWeather.id == "Blue Sky")
							{
								if(wRain < 75)
								{
									if(GetDistance2D(psX, psZ, ix, iz) <= isR && Locations[FindLocation(rl.(tempattrname).go)].type =="seashore")
									{
										//logit("loc pos x : " + ix);
										//logit("loc pos z : " + iz);
										if(!Checkattribute(rl, tempattrname+".inlagoon"))
										{
											//Logit("i'm in a lagoon !");
											//Sea.GF3.WaterColor = argb(0,45,129,153);
											Refreshseacolor_in();
											rl.(tempattrname).inlagoon = 1;
											break;
										}
									}
									else
									{
										if(CheckAttribute(rl, tempattrname+".inlagoon"))
										{
											//Logit("i'm not in a lagoon !");
											aCurWeather.Sea.inlagoon = 0;
											Refreshseacolor_out();
											//Sea.GF3.WaterColor = argb(0,30,55,100);
											DeleteAttribute(rl, tempattrname+".inlagoon");
										}
									}
								}
								else
								{
									Sea.GF3.WaterColor = aCurWeather.Sea.Water.Color;
									Sea.GF3.SkyColor = aCurWeather.Sea.Sky.Color;
									Sea.WaterAttenuation = aCurWeather.Sea.WaterAttenuation;
								}
							}
						}
					}
				}
			} // Screwface : Lagoon colour mod end
		}
		// SCREWFACE : END


		int iyear = GetDataYear();
		int imonth = GetDataMonth();
		int iday = GetDataDay();
		sDateTimeDisplay = XI_ConvertString(GetDayName(GetWeekday(iday, imonth, iyear))) + ", " + GetHumanDate(iyear, imonth, iday);
		if (sti(mchr.HasClock)) sDateTimeDisplay += " " + GetStringTime(stf(mchr.CurrentTime));
		// DeathDaisy: approximate time of day when not having a clock
		else{ 
			string TimeOfDay;
			if(GetTime() >= 22 || GetTime() < 3) TimeOfDay = XI_ConvertString("Night");
			if(GetTime() >= 3 && GetTime() < 6) TimeOfDay = XI_ConvertString("Small Hours");
			if(GetTime() >= 6 && GetTime() < 7) TimeOfDay = XI_ConvertString("Dawn");
			if(GetTime() >= 7 && GetTime() < 10) TimeOfDay = XI_ConvertString("Morning");
			if(GetTime() >= 10 && GetTime() < 14) TimeOfDay = XI_ConvertString("Midday");
			if(GetTime() >= 14 && GetTime() < 18) TimeOfDay = XI_ConvertString("Afternoon");
			if(GetTime() >= 18 && GetTime() < 21) TimeOfDay = XI_ConvertString("Evening");
			if(GetTime() >= 21 && GetTime() < 22) TimeOfDay = XI_ConvertString("Dusk");
			sDateTimeDisplay += ", " + FirstLetterUp(TimeOfDay);
		}
		// PB: Only show this if Various Logs are enabled -->
		if(LogsToggle >= LOG_LACONIC) SendMessage(&IDateTimeDisplay, "lls", LOG_ADD_STRING, true, sDateTimeDisplay);
		else SendMessage(&IDateTimeDisplay, "lls", LOG_ADD_STRING, true, "");
		// PB: Only show this if Various Logs are enabled <--

		PostEvent("evntUpdateTime", 250.0);	// when DisplayTime attribute is deleted, this will stop calling itself
	}
}
// <-- KK
