#define	LOGENTRY_TITLE			1
#define LOGENTRY_TEXT			2
#define MAX_SHIPSLOG_LINES		14
#define FILTER_ALL				0
#define FILTER_GENERAL			1
#define FILTER_BATTLE			2
#define FILTER_SHIP				3
#define FILTER_PERSONAL			4
#define FILTER_NOTES			5

int curLogTop;
int curLogIdx;
int curShowType=LOGENTRY_TITLE;
int curFilter = FILTER_ALL;

string curNode;

void InitInterface(string iniName)
{
	GameInterface.title = "titleShipsLog";

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();

	CreateString(false, "LogEntry_Title", "", FONT_SHIPSLOG, COLOR_WHITE, 320, 62, SCRIPT_ALIGN_CENTER, 1.0);	
	CreateString(false, "LogEntry_Date", "", FONT_SHIPSLOG, COLOR_WHITE, 75, 62, SCRIPT_ALIGN_LEFT, 1.0);	
	CreateString(false, "NewLogEntry_Title_Label", XI_ConvertString("Log Title"), FONT_SHIPSLOG, COLOR_GRAY, 10, 90, SCRIPT_ALIGN_LEFT, 0.7) // MAXIMUS 27.06.2019: localization
	CreateString(false, "NewLogEntry_Entry_Label", XI_ConvertString("Log Entry"), FONT_SHIPSLOG, COLOR_GRAY, 10, 135, SCRIPT_ALIGN_LEFT, 0.7) // MAXIMUS 27.06.2019: localization
	CreateString(true, "NewLog", XI_ConvertString("Write new log entry"), FONT_SHIPSLOG, COLOR_GRAY, 140, 435, SCRIPT_ALIGN_LEFT, 1.3) // MAXIMUS 27.06.2019: localization

	CreateString(true, "Stat_Kills", GetStatistics("Kills"), FONT_SHIPSLOG, COLOR_WHITE, 657, 340, SCRIPT_ALIGN_CENTER, 0.5);	
	CreateString(true, "Stat_ShipsSunk", GetStatistics("ShipsSunk"), FONT_SHIPSLOG, COLOR_WHITE, 657, 400, SCRIPT_ALIGN_CENTER, 0.5);
	CreateString(true, "Stat_ShipsCaptured", GetStatistics("ShipsCaptured"), FONT_SHIPSLOG, COLOR_WHITE, 657, 460, SCRIPT_ALIGN_CENTER, 0.5);
  
	curLogTop = 0;
	curLogIdx = 0;
	CreateLogHeadersList();
	DisplayLogHeadersList();

	bool hasShip = false;
	ref MainChar = GetMainCharacter();
	for (int i = 0; i < 4; i++) {
		int cidx = GetCompanionIndex(MainChar, i);
		if (cidx < 0) continue;
		if (GetCharacterShipType(GetCharacter(cidx)) != SHIP_NOTUSED) {
			hasShip = true;
			break;
		}
	}
	SetSelectable("I_SHIPHOLD", !LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm() && hasShip);
	if (hasShip == false && GetBerthedShipsQuantityForTown(GetTownIDFromLocID(MainChar.location)) > 0) {
		hasShip = true;
		GameInterface.GoDirectToShipBerthing = true;
		SendMessage(&GameInterface, "lsls", MSG_INTERFACE_MSG_TO_NODE, "I_SHIP", 0, XI_ConvertString("Sel Berth"));
	}

	SetSelectable("I_SHIP", !LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm() && hasShip); // KK
	SetSelectable("I_TRADEBOOK",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	SetSelectable("I_QUESTBOOK",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	SetSelectable("EXIT_BUTTON",true);
	SetNodeUsing("BOXBACKGROUNDBIG",false);	
	SetNodeUsing("IMAGEOK",false);	
	SetNodeUsing("IMAGECANCEL",false);	
	SetNodeUsing("B_LOGTITLE",false);
	SetNodeUsing("B_LOGENTRY",false);
	SetNodeUsing("NEW_LOG_ENTRY",false);
	SetNodeUsing("NEW_LOG_TITLE",false);
	SetNodeUsing("RSAVE", false); 
	SetNodeUsing("RCANCEL", false);

	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("FormatedTextActivate", "procFTActivate", 0); // KK
	SetEventHandler("BackToTitle","BackToTitle",0);
	SetEventHandler("SetScrollerPos","SetScrollerPos",0);
	SetEventHandler("ScrollPosChange","ProcScrollPosChange",0);
	SetEventHandler("NewLog","ProcessEnterNewLog",0);
	SetEventHandler("NewLogTitle","ProcessEnterNewLogTitle",0);
	SetEventHandler("NewLogEntry","ProcessEnterNewLogEntry",0);
	SetEventHandler("KB_Update", "UpdateLog", 0);
	SetEventHandler("KB_End","WriteLog",0);
	SetEventHandler("WriteLogData","SaveNewLogEntry",0);
	SetEventHandler("PrepareSave","PrepareSaveButton",0);
	SetEventHandler("LogShowAll","ShowAll",0);
	SetEventHandler("LogShowGeneral","ShowGeneral",0);
	SetEventHandler("LogShowBattle","ShowBattle",0);
	SetEventHandler("LogShowShip","ShowShip",0);
	SetEventHandler("LogShowPersonal","ShowPersonal",0);
	SetEventHandler("LogShowNotes","ShowNotes",0);
	SetEventHandler("CancelNewLog","CancelLog",0);
}

void XI_SetLogData(bool qtitle)
{
	// set node & string using
	SetNodeUsing("LOGRECTANGLE",true);
	SetNodeUsing("LOGBOUND",true);
	SetNodeUsing("LOGSCROLL",true);
	SetNodeUsing("LOGENTRY_TITLE",qtitle);
	SetNodeUsing("LOGENTRY_TEXT",!qtitle);
}

void ProcessCancelExit()
{
	IDoExit(RC_INTERFACE_SHIPLOG_EXIT);
}

void BackToTitle()
{
	DisplayLogHeadersList();
}

void XI_LogActivate()
{
	curShowType = LOGENTRY_TEXT;
	int aq = curLogTop+GetEventData();
	ref refMyCh = GetMainCharacter();
	aref pA;
	makearef(pA,refMyCh.QuestInfo);
	XI_SetLogData(false);
	SetCurrentNode("LOGENTRY_TEXT");
}

void XI_SetScroller(float fpos)
{
	SendMessage(&GameInterface,"lsf",MSG_INTERFACE_SET_SCROLLER,"LOGSCROLL",fpos);
}

void SetScrollerPos()
{
	string nodName = GetEventData();
	if(nodName=="LOGENTRY_TEXT") return;
	float fpos = GetEventData();
	XI_SetScroller(fpos);
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("BackToTitle","BackToTitle");	
	DelEventHandler("SetScrollerPos","SetScrollerPos");
	DelEventHandler("ScrollPosChange","ProcScrollPosChange");	
	DelEventHandler("ievnt_command","ProcessCommandExecute");
	DelEventHandler("FormatedTextActivate", "procFTActivate");

	DelEventHandler("NewLog","ProcessEnterNewLog");
	DelEventHandler("NewLogEntry","ProcessEnterNewLogEntry");
	DelEventHandler("NewLogTitle","ProcessEnterNewLogTitle");
	DelEventHandler("KB_Update", "UpdateLog"); 
	DelEventHandler("KB_End","WriteLog");
	DelEventHandler("WriteLogData","SaveNewLogEntry");
	DelEventHandler("PrepareSave","PrepareSaveButton");

	DelEventHandler("LogShowAll","ShowAll");
	DelEventHandler("LogShowGeneral","ShowGeneral");
	DelEventHandler("LogShowBattle","ShowBattle");
	DelEventHandler("LogShowShip","ShowShip");
	DelEventHandler("LogShowPersonal","ShowPersonal");
	DelEventHandler("LogShowNotes","ShowNotes");
	DelEventHandler("CancelNewLog","CancelLog");

	interfaceResultCommand = exitCode;
	EndCancelInterface(true);
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	int x;ref tmpch;string tmpstr;

	if(nodName=="I_CHARACTER")
	{ 
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_SHIPLOG_EXIT;
			EndCancelInterface(false);
		}
	}
	if(nodName=="I_SHIP")
	{ 
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_SHIPLOG_EXIT;
			EndCancelInterface(false);
		}
	}
	if(nodName=="I_SHIPHOLD")
	{ 
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_SHIPLOG_EXIT;
			EndCancelInterface(false);
		}
	}
	if(nodName=="I_PASSENGER")
	{ 
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_SHIPLOG_EXIT;
			EndCancelInterface(false);
		}
	}
	if(nodName=="I_TRADEBOOK")
	{ 
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_SHIPLOG_EXIT;
			EndCancelInterface(false);
		}
	}
	if(nodName=="I_QUESTBOOK")
	{ 
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_SHIPLOG_EXIT;
			EndCancelInterface(false);
		}
	}
	if(nodName=="I_NATIONS")
	{ 
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_SHIPLOG_EXIT;
			EndCancelInterface(false);
		}
	}
	if(nodName=="I_ITEMS")
	{ 
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_SHIPLOG_EXIT;
			EndCancelInterface(false);
		}
	}
}


void procFTActivate()
{
	string nodName = GetEventData();
	curLogIdx = GetEventData();

	if (nodName == "SHIPSLOG_WINDOW") DisplayLogText();
}

void ProcScrollPosChange()
{
	float newPos = GetEventData();
 	if(curShowType==LOGENTRY_TITLE)
	{
		ref myCh = GetMainCharacter();
		int maxVal = GetLogEntryCount();
		int newTop = makeint(newPos*maxVal);
    
		if(newTop == curLogIdx) return;
		if(newTop >= maxVal) return;
       
		if (newTop > curLogIdx)
		{
			if (newTop - curLogTop +1 > MAX_SHIPSLOG_LINES) curLogTop = (newTop - MAX_SHIPSLOG_LINES +1);
			SendMessage(&GameInterface,"lslf",MSG_INTERFACE_MSG_TO_NODE,"SHIPSLOG_WINDOW", 2, newPos);
		}
		if (newTop < curLogIdx)
		{
			if (curLogTop > newTop) curLogTop = newTop;
			SendMessage(&GameInterface,"lslf",MSG_INTERFACE_MSG_TO_NODE,"SHIPSLOG_WINDOW", 2, newPos);
		}						
		DisplayLogHeadersList();
		curLogIdx = NewTop;
	}
	else
	{
		SendMessage(&GameInterface,"lslf",MSG_INTERFACE_MSG_TO_NODE,"LOGENTRY_TEXT", 2, newPos);
	}
}


void ProcScrollChange()
{
	int changeNum = GetEventData();
	if(changeNum==0) return;
	string controlNode = "";
	if( GetSelectable("SHIPSLOG_WINDOW") ) controlNode = "SHIPSLOG_WINDOW";
	if( GetSelectable("LOGENTRY_TEXT") ) controlNode = "LOGENTRY_TEXT";

	if(controlNode!="")
	{
		if(changeNum>0) {
			SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,controlNode,-1, 0,ACTION_DOWNSTEP);
		} else {
			SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,controlNode,-1, 0,ACTION_UPSTEP);
		}
	}
}

void CreateLogHeadersList()
{
	ref myCh = GetMainCharacter();
	
	int i;
	int maxVal;
	string tmp;
	string tmpLogTitle;
 
	maxVal = GetLogEntryCount();

	for(i=0;i<maxVal;i++)
	{ 
		tmp = "log"+i;
		if(!CheckAttribute(&myCh, "shiplog.Date."+tmp)) break; // break in case of errors
		tmpLogTitle = myCh.shiplog.Date.(tmp) + "        " + GetTranslatedLog(myCh.shiplog.Title.(tmp)); // MAXIMUS 27.06.2019: localization  
		if( tmpLogTitle == "")
		{
			continue;   
		}
		else
		{
			if (myCh.shiplog.Visible.(tmp))
			{
				switch(curFilter)
				{
					case FILTER_ALL:
						SendMessage(&GameInterface, "lsle", MSG_INTERFACE_MSG_TO_NODE, "SHIPSLOG_WINDOW", 0, &tmpLogTitle);
					break;
					case FILTER_GENERAL:
						if(myCh.shiplog.Category.(tmp) == "General")
						{
							SendMessage(&GameInterface, "lsle", MSG_INTERFACE_MSG_TO_NODE, "SHIPSLOG_WINDOW", 0, &tmpLogTitle);
						}
					break;
					case FILTER_BATTLE:
						if(myCh.shiplog.Category.(tmp) == "Battle") 
						{
							SendMessage(&GameInterface, "lsle", MSG_INTERFACE_MSG_TO_NODE, "SHIPSLOG_WINDOW", 0, &tmpLogTitle);
						}
					break;
					case FILTER_SHIP:
						if(myCh.shiplog.Category.(tmp) == "Ship") 
						{
							SendMessage(&GameInterface, "lsle", MSG_INTERFACE_MSG_TO_NODE, "SHIPSLOG_WINDOW", 0, &tmpLogTitle);
						}
					break;
					case FILTER_PERSONAL:
						if(myCh.shiplog.Category.(tmp) == "Personal") 
						{
							SendMessage(&GameInterface, "lsle", MSG_INTERFACE_MSG_TO_NODE, "SHIPSLOG_WINDOW", 0, &tmpLogTitle);
						}
					break;
					case FILTER_NOTES:
						if(myCh.shiplog.Category.(tmp) == "Notes") 
						{
							SendMessage(&GameInterface, "lsle", MSG_INTERFACE_MSG_TO_NODE, "SHIPSLOG_WINDOW", 0, &tmpLogTitle);
						}
					break;
				}
			}
		}
	}
}

void PrintLogIcon(string sCategory, int i)
{
	switch(sCategory)
	{
		case "General":
			CreateImage("LogMarker"+i, "RELATIONS", "Neutral", 540, 58 + i * 25, 565, 58 + (i + 1) * 25);
		break;
		case "Battle":
			CreateImage("LogMarker"+i, "RELATIONS", "Enemy", 540, 58 + i * 25, 565, 58 + (i + 1) * 25);
		break;
		case "Ship":
			CreateImage("LogMarker"+i, "ships16", "BlackPearl", 540, 58 + i * 25, 565, 58 + (i + 1) * 25);
		break;
		case "Personal":
			CreateImage("LogMarker"+i, "icons", "money icon", 535, 58 + i * 25, 560, 58 + (i + 1) * 25);
			CreateImage("LogMarkera"+i, "icons", "sneak skill icon", 545, 58 + i * 25, 570, 58 + (i + 1) * 25);        
		break;
		case "Notes":
			CreateImage("LogMarker"+i, "NOTES", "feather", 540, 58 + i * 25, 565, 58 + (i + 1) * 25);
		break;
	}
}

void DisplayLogHeadersList()
{
	curShowType = LOGENTRY_TITLE;

	aref arefTmp;
	ref myCh = GetMainCharacter();	
	int num = GetLogEntryCount();
	int start = curLogTop;
	int i,j;
	string tmp;

	//if (num > MAX_SHIPSLOG_LINES && start +  MAX_SHIPSLOG_LINES > num) start = num - MAX_SHIPSLOG_LINES;

	// Create the placeholders for the icons -->	
	for (i = 0; i < GetLogEntryCount(); i++) 
	{
		if(i>= MAX_SHIPSLOG_LINES) break;
		CreateImage("LogMarker" + i, "", "",  548, 58 + i * 32, 580, 58 + (i + 1) * 32);
	}
	for (i = 0; i < GetLogEntryCount(); i++) 
	{
		if(i>= MAX_SHIPSLOG_LINES) break;
		CreateImage("LogMarkera" + i, "", "",  548, 58 + i * 32, 580, 58 + (i + 1) * 32);
	}
	// Create the placeholders for the icons <--

	j = 0;
	for (i = 0; i < num; i++) {  	
    if ((j-start) >= MAX_SHIPSLOG_LINES) break;
  	tmp = "log"+i;
  	if(!CheckAttribute(&myCh, "shiplog.Date."+tmp)) break; // break in case of errors
		if (myCh.shiplog.Visible.(tmp))
		{
			switch(curFilter)
			{
				case FILTER_ALL:
					if(j>=start) PrintLogIcon(myCh.shiplog.Category.(tmp), j-start);
					//PrintLogIcon(myCh.shiplog.Category.(tmp), j);
					j++;
				break;
				case FILTER_GENERAL:
					if(myCh.shiplog.Category.(tmp) == "General")
					{
						PrintLogIcon(myCh.shiplog.Category.(tmp), j);
						j++;
					}
				break;
				case FILTER_BATTLE:
					if(myCh.shiplog.Category.(tmp) == "Battle")
					{
						PrintLogIcon(myCh.shiplog.Category.(tmp), j);
						j++;
					}
				break;
				case FILTER_SHIP:
					if(myCh.shiplog.Category.(tmp) == "Ship")
					{
						PrintLogIcon(myCh.shiplog.Category.(tmp), j);
						j++;
					}
				break;
				case FILTER_PERSONAL:
					if(myCh.shiplog.Category.(tmp) == "Personal")
					{
						PrintLogIcon(myCh.shiplog.Category.(tmp), j);
						j++;
					}
				break;
				case FILTER_NOTES:
					if(myCh.shiplog.Category.(tmp) == "Notes")
					{
						PrintLogIcon(myCh.shiplog.Category.(tmp), j);
						j++;
					}
				break;
			}
		}
	}
	SetNodeUsing("SHIPSLOG_LINE", false);
	DisableString("LogEntry_Title");
	DisableString("LogEntry_Date"); // PB: Erase this
	SetNodeUsing("LOGENTRY_TEXT", false);
	SetNodeUsing("SHIPSLOG_WINDOW", true);
	SetCurrentNode("LOGSCROLL");
//	CreateLogHeadersList();
}

void DisplayLogText()
{
	curShowType = LOGENTRY_TEXT;
	 
	ref myCh = GetMainCharacter();	
	int i;
	string tmp;
	string tmpLogDate;
	string tmpLogTitle;
	string tmpLogEntry;

	tmp = GetLogEntry(curLogIdx);
	if(CheckAttribute(myCh, "shiplog.Title."+tmp))
	{
		tmpLogDate = myCh.shiplog.Date.(tmp);
		tmpLogTitle = myCh.shiplog.Title.(tmp);
		tmpLogEntry = myCh.shiplog.Entry.(tmp);       
	}
	else
	{
		tmpLogDate  = "";
		tmpLogTitle = "Unreadable page";
		tmpLogEntry = "This page of the ship's log is drenched in rum. It's no longer readable. [ the code has an error :) ]";
	}

	GameInterface.strings.LogEntry_Date = tmpLogDate;
	GameInterface.strings.LogEntry_Title = GetTranslatedLog(tmpLogTitle); // MAXIMUS 27.06.2019: localization
	EnableString("LogEntry_Date");
	EnableString("LogEntry_Title");


	SendMessage(&GameInterface,"lss",MSG_INTERFACE_SET_FORMATEDTEXT,"LOGENTRY_TEXT",""); // MAXIMUS 12.08.2019: fix - after reopen log, the log text was doubled
	SetFormatedLogText("LOGENTRY_TEXT", GetTranslatedLog(tmpLogEntry)); // MAXIMUS 27.06.2019: localization
	SetFormatedLogText("LOGENTRY_TEXT", " ");			// PB

	// Hide the icons
	for (i = 0; i < GetLogEntryCount(); i++) CreateImage("LogMarker" + i, "", "",  548, 58 + i * 32, 580, 58 + (i + 1) * 32);
	for (i = 0; i < GetLogEntryCount(); i++) CreateImage("LogMarkera" + i, "", "",  548, 58 + i * 32, 580, 58 + (i + 1) * 32);

	SetNodeUsing("SHIPSLOG_WINDOW", false);
	SetNodeUsing("SHIPSLOG_LINE", true);
	SetNodeUsing("LOGENTRY_TEXT", true);
	SetCurrentNode("LOGENTRY_TEXT");
}

int GetLogEntryCount()
{
	ref pchar = GetMainCharacter();
	int i;
	aref arLog;
	makearef(arLog, pchar.shiplog.Date);

	i = GetAttributesNum(arLog);

	if (i >0) return i;
	else return 0;
}

string GetLogEntry(int curIdx)
{
	ref myCh = GetMainCharacter();

	int i,j;
	int maxVal;
	string tmp;
  
	maxVal = GetLogEntryCount();	
	j = 0;
	for(i=0;i<maxVal;i++)
	{ 
		tmp = "log"+i;

		if (myCh.shiplog.Visible.(tmp))
		{
			switch(curFilter)
			{
				case FILTER_ALL:
					if(curIdx ==j ) return tmp;
					j++;
				break;
				case FILTER_GENERAL:
					if(myCh.shiplog.Category.(tmp) == "General")
					{
						if(curIdx ==j) return tmp;
						j++;
					}
				break;
				case FILTER_BATTLE:
					if(myCh.shiplog.Category.(tmp) == "Battle")
					{
						if(curIdx ==j) return tmp;
						j++;
					}
				break;
				case FILTER_SHIP:
					if(myCh.shiplog.Category.(tmp) == "Ship")
					{
						if(curIdx ==j) return tmp;
						j++;
					}
				break;
				case FILTER_PERSONAL:
					if(myCh.shiplog.Category.(tmp) == "Personal")
					{
						if(curIdx ==j) return tmp;
						j++;
					}
				break;
				case FILTER_NOTES:
					if(myCh.shiplog.Category.(tmp) == "Notes")
					{
						if(curIdx ==j) return tmp;
						j++;
					}
				break;
			}
		}
	}
}

void ProcessEnterNewLog()
{
	SetNodeUsing("BOXBACKGROUNDBIG",true);	
	SetNodeUsing("RSAVE", true); 
	SetNodeUsing("RCANCEL", true);
	SetNodeUsing("B_LOGTITLE",true);
	SetNodeUsing("B_LOGENTRY",true);
	SetNodeUsing("NEW_LOG_ENTRY",true);
	SetNodeUsing("NEW_LOG_TITLE",true);
	SetNodeUsing("IMAGEOK",true);	
	SetNodeUsing("IMAGECANCEL",true);	
	EnableString("NewLogEntry_Title_Label");
	EnableString("NewLogEntry_Entry_Label");
	DisableString("NewLog");
	DisableString("LogEntry_Date");
	DisableString("LogEntry_Title");
	ProcessEnterNewLogTitle();
}

void CancelLog()
{
	SetNodeUsing("BOXBACKGROUNDBIG",false);	
	SetNodeUsing("RSAVE", false); 
	SetNodeUsing("RCANCEL", false);
	SetNodeUsing("B_LOGTITLE",false);
	SetNodeUsing("B_LOGENTRY",false);
	SetFormatedText("NEW_LOG_ENTRY","");
	SetFormatedText("NEW_LOG_TITLE","");
	SetNodeUsing("NEW_LOG_ENTRY",false);
	SetNodeUsing("NEW_LOG_TITLE",false);
	SetNodeUsing("IMAGEOK",false);	
	SetNodeUsing("IMAGECANCEL",false);	
	DisableString("NewLogEntry_Title_Label");
	DisableString("NewLogEntry_Entry_Label");
	EnableString("NewLog");
	EnableString("LogEntry_Date");
	EnableString("LogEntry_Title");
	GameInterface.strings.NewLogEntry_Title = "";
	GameInterface.strings.NewLogEntry_Entry = "";		
}

void ProcessEnterNewLogTitle()
{
	string tmp = "";
	if(CheckAttribute(&GameInterface,"strings.NewLogEntry_Title")) tmp = GameInterface.strings.NewLogEntry_Title;
	else tmp = "";
	curNode = "NEW_LOG_TITLE";
	SetNodeUsing("NEW_LOG_TITLE",true);
	SetSelectable("NEW_LOG_TITLE",true); 
	SetCurrentNode("NEW_LOG_TITLE"); 
	KB_SetKeyboardMode(true);
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "NEW_LOG_TITLE");
	KB_Prepare(tmp);
}

void ProcessEnterNewLogEntry()
{
	string tmp;
	if(CheckAttribute(&GameInterface,"strings.NewLogEntry_Entry")) tmp = GameInterface.strings.NewLogEntry_Entry;
	else tmp = "";
	curNode = "NEW_LOG_ENTRY";
	SetNodeUsing("NEW_LOG_ENTRY",true); 
	SetSelectable("NEW_LOG_ENTRY",true);
	SetCurrentNode("NEW_LOG_ENTRY"); 
	KB_SetKeyboardMode(true);	
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "NEW_LOG_ENTRY");
	KB_Prepare(tmp);
}


void UpdateLog()
{
	string tmp; 

	if(curNode=="NEW_LOG_ENTRY")
	{
		//DisableString("NewLogEntry_Entry");
		GameInterface.strings.NewLogEntry_Entry = KeyboardDisplayString; 
		tmp = GameInterface.strings.NewLogEntry_Entry;
		SetFormatedText("NEW_LOG_ENTRY",tmp);
	}
	if(curNode=="NEW_LOG_TITLE")
	{    
		if(strlen(KeyboardString) >30)
		{
			KB_RemoveCharacter();
		}
		else
		{
			//DisableString("NewLogEntry_Title");
			GameInterface.strings.NewLogEntry_Title = KeyboardDisplayString; 
			tmp = GameInterface.strings.NewLogEntry_Title;
			SetFormatedText("NEW_LOG_TITLE",tmp);    
		}
	}
}

void WriteLog()
{
	string tmp;

	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
	if(curNode=="NEW_LOG_TITLE")
	{
		GameInterface.strings.NewLogEntry_Title = KeyboardString; // remove the cursor character    
		tmp = GameInterface.strings.NewLogEntry_Title;         
		SetFormatedText("NEW_LOG_TITLE",tmp);
		SetCurrentNode("NEW_LOG_ENTRY");
	}
	if(curNode=="NEW_LOG_ENTRY")
	{
		GameInterface.strings.NewLogEntry_Entry = KeyboardString;
		tmp = GameInterface.strings.NewLogEntry_Entry;
		SetFormatedText("NEW_LOG_ENTRY",tmp);
		SetCurrentNode("NEW_LOG_ENTRY");
		//PostEvent("PrepareSave",200);       // avoid reposting the same command immediately on exit
	}
}

void PrepareSaveButton()
{
 SetCurrentNode("RSAVE"); 
}

void SaveNewLogEntry()
{
	if(CheckAttribute(&GameInterface,"strings.NewLogEntry_Entry") && CheckAttribute(&GameInterface,"strings.NewLogEntry_Entry"))
	{
		if(GameInterface.strings.NewLogEntry_Title !="" && GameInterface.strings.NewLogEntry_Entry !="")
		{
			WriteNewLogEntry(GameInterface.strings.NewLogEntry_Title,GameInterface.strings.NewLogEntry_Entry,"Notes",true);
			GameInterface.strings.NewLogEntry_Title = "";
			GameInterface.strings.NewLogEntry_Entry = "";	
			SetFormatedText("NEW_LOG_TITLE","");
			SetFormatedText("NEW_LOG_ENTRY","");
			InitInterface(Interfaces[CurrentInterface].IniFile);
		}
	}
}    

// Filters
void ShowAll()
{
	curFilter = FILTER_ALL;
	InitInterface(Interfaces[CurrentInterface].IniFile);
}
void ShowGeneral()
{
	curFilter = FILTER_GENERAL;
	InitInterface(Interfaces[CurrentInterface].IniFile);
}
void ShowBattle()
{
	curFilter = FILTER_BATTLE;
	InitInterface(Interfaces[CurrentInterface].IniFile);
}
void ShowShip()
{
	curFilter = FILTER_SHIP;
	InitInterface(Interfaces[CurrentInterface].IniFile);
}
void ShowPersonal()
{
	curFilter = FILTER_PERSONAL;
	InitInterface(Interfaces[CurrentInterface].IniFile);
}
void ShowNotes()
{
	curFilter = FILTER_NOTES;
	InitInterface(Interfaces[CurrentInterface].IniFile);
}
