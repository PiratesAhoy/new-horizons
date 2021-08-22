#define	LOGENTRY_TITLE        1
#define LOGENTRY_TEXT	        2
#define MAX_SHIPSLOG_LINES	 14
#define FILTER_GENERAL        1

int curLogTop;
int curLogIdx;
int curShowType=LOGENTRY_TITLE;
int curFilter = FILTER_GENERAL;

string curNode;

void InitInterface(string iniName)
{
	GameInterface.title = "titleTavernNews";

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
	IDoExit(RC_INTERFACE_NEWS_EXIT);
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
      if(myCh.shiplog.Category.(tmp) == "General")
      {
        SendMessage(&GameInterface, "lsle", MSG_INTERFACE_MSG_TO_NODE, "SHIPSLOG_WINDOW", 0, &tmpLogTitle);
      }
    }
  }
  SetLogVisible(); //Levis: moved outside the forloop as this function takes all log entries anyways
}


void DisplayLogHeadersList()
{
	curShowType = LOGENTRY_TITLE;

	aref arefTmp;
	ref myCh = GetMainCharacter();	
	int num = GetLogEntryCount();
	int start = curLogTop;

	SetNodeUsing("SHIPSLOG_LINE", false);
	DisableString("LogEntry_Title");
	SetNodeUsing("LOGENTRY_TEXT", false);
	SetNodeUsing("SHIPSLOG_WINDOW", true);
	SetCurrentNode("LOGSCROLL");
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
        case FILTER_GENERAL:
          if(myCh.shiplog.Category.(tmp) == "General")
          {
            if(curIdx ==j) return tmp;
            j++;
          }
          break;
      } 
    }        
  }	
}

