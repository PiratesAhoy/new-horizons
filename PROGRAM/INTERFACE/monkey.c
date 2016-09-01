#define	LOGENTRY_TITLE			1
#define LOGENTRY_TEXT			2
#define MAX_SHIPSLOG_LINES		14
#define FILTER_GENERAL			1

int curLogTop;
int curLogIdx;
int curShowType=LOGENTRY_TITLE;
int curFilter = FILTER_GENERAL;

string curNode;

void InitInterface(string iniName)
{
	GameInterface.title = "";

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();

	CreateString(false, "LogEntry_Title", "", FONT_SHIPSLOG, COLOR_WHITE, 320, 62, SCRIPT_ALIGN_CENTER, 1.0);	
	CreateString(false, "LogEntry_Date", "", FONT_SHIPSLOG, COLOR_WHITE, 75, 62, SCRIPT_ALIGN_LEFT, 1.0);	
 
	curLogTop = 0;
	curLogIdx = 0;
	CreateLogHeadersList();
	DisplayLogHeadersList();

	SetSelectable("EXIT_BUTTON",true);
	SetNodeUsing("BOXBACKGROUNDBIG",false);	
	SetNodeUsing("B_LOGTITLE",false);
	SetNodeUsing("B_LOGENTRY",false);
  
	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("BackToTitle","BackToTitle",0);
}

void XI_SetLogData(bool qtitle)
{
	SetNodeUsing("LOGRECTANGLE",true);
	SetNodeUsing("LOGSCROLL",true);
	SetNodeUsing("LOGENTRY_TITLE",qtitle);
	SetNodeUsing("LOGENTRY_TEXT",!qtitle);
}

void ProcessCancelExit()
{
	IDoExit(RC_INTERFACE_MONKEY_EXIT);
}

void BackToTitle()
{
	
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
}

void SetScrollerPos()
{
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("BackToTitle","BackToTitle");	  
	interfaceResultCommand = exitCode;
	EndCancelInterface(true);
}



void CreateLogHeadersList()
{
  
}


void DisplayLogHeadersList()
{
	
}
