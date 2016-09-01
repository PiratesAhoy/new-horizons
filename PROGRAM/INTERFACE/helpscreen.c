#define HELP_SECTION_QUANTITY	2

int	curSectionIdx;
bool ig_bUseScroller;

// show types: 0 - help section choose, 1 - help show
int nCurShowType = -1;

void InitInterface_S(string iniName, string sectionName)
{
	int sectNum;
	curSectionIdx = -1;

	GameInterface.title = "titleHelp";

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();//MAXIMUS: standard exit-string for exit-button

    CreateString(true,"HelpName","",FONT_NORMAL,COLOR_MONEY,420,59,SCRIPT_ALIGN_CENTER,1.2);

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);

	SetEventHandler("ToHelpMain","ProcToHelpMain",0);
	SetEventHandler("HelpUp","ProcHelpUp",0);
	SetEventHandler("HelpDown","ProcHelpDown",0);
	SetEventHandler("SetScrollerPos","ProcScrollerControl",0);
	SetEventHandler("DisableScroll","ProcDisableScroll",0);
	SetEventHandler("FormatedTextActivate","ProcHelpSectionActivate",0);
	SetEventHandler("ScrollTopChange","ProcScrollChange",0);
	SetEventHandler("ScrollPosChange","ProcScrollPosChange",0);

	InitHelpSectionChooser();

	SetShowType(1);
	SetShowType(0);

	sectNum = GetSectionNumFromName(sectionName);
	if(sectNum>=0)	LoadHelpSection(sectNum-curSectionIdx);
}

void ProcessCancelExit()
{
	IDoExit(RC_INTERFACE_HELPSCREEN_EXIT);
}

void IDoExit(int exitCode)
{
	if(curSectionIdx!=-1)
	{
		Event("ResetHelpSegment","s",GetSectionNameFromIndex(curSectionIdx));
		UnloadSegment(GetSegmentFromName(GetSectionNameFromIndex(curSectionIdx)));
	}

	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ToHelpMain","ProcToHelpMain");
	DelEventHandler("HelpUp","ProcHelpUp");
	DelEventHandler("HelpDown","ProcHelpDown");
	DelEventHandler("SetScrollerPos","ProcScrollerControl");
	DelEventHandler("DisableScroll","ProcDisableScroll");
	DelEventHandler("FormatedTextActivate","ProcHelpSectionActivate");
	DelEventHandler("ScrollTopChange","ProcScrollChange");
	DelEventHandler("ScrollPosChange","ProcScrollPosChange");

    interfaceResultCommand = exitCode;
    EndCancelInterface(true);
}

void LoadHelpSection(int offset)
{
	int newNum = curSectionIdx+offset;
	string newSectName = GetSectionNameFromIndex(newNum);
	if(newSectName=="") return;
	if(newNum==curSectionIdx && nCurShowType==1) return;

	if(curSectionIdx!=-1)
	{
		Event("ResetHelpSegment","s",GetSectionNameFromIndex(curSectionIdx));
		UnloadSegment(GetSegmentFromName(GetSectionNameFromIndex(curSectionIdx)));
	}

	curSectionIdx = newNum;
	if(!LoadSegment(GetSegmentFromName(newSectName)))
		curSectionIdx = -1;
	else
	{
		SetShowType(1);
		Event("InitHelpSegment","s",newSectName);
	}
}

string GetSectionNameFromIndex(int idx)
{
	switch(idx)
	{
	case 0:	return "sea_minimap"; break;
	case 1: return "ship_commands"; break;
	case 2: return "fast_commands"; break;
	case 3: return "sea_aim"; break;
	case 4: return "alarm_indicator"; break;
	case 5: return "land_commands"; break;
	case 6: return "WorldMap_Date_Clock"; break;
	case 7: return "WorldMap_Compas"; break;
	case 8: return "Dialog_window"; break;
	}
	return "";
}

int GetSectionNumFromName(string sectName)
{
	string tmpStr;
	for(int i=0; true; i++)
	{
		tmpStr = GetSectionNameFromIndex(i);
		if(tmpStr=="") return -1;
		if(tmpStr==sectName) return i;
	}
	return -1;
}

string GetSegmentFromName(string segName)
{
	return "interface\help_section\\"+segName+".c";
}

void ProcToHelpMain()
{
	if(curSectionIdx>=0)
	{
		UnloadSegment(GetSegmentFromName(GetSectionNameFromIndex(curSectionIdx)));
	}
	SetShowType(0);
	//ProcessCancelExit();
}

void ProcHelpUp()
{
	LoadHelpSection(-1);
}

void ProcHelpDown()
{
	LoadHelpSection(1);
}

void ProcScrollerControl()
{
	string nodName = GetEventData();
	float fpos = GetEventData();
	SendMessage(&GameInterface,"lsf",MSG_INTERFACE_SET_SCROLLER,"SCROLL",fpos);
}

void ProcDisableScroll()
{
	bool bDisableScroll = GetEventData();
	SetNodeUsing("SCROLL",!bDisableScroll);
}

void SetShowType(int newShowType)
{
	if(nCurShowType==newShowType) return;

	switch(nCurShowType)
	{
	case 0:
		{
			SetNodeUsing("TITLEWINDOW",false);
		}
		break;
	case 1:
		{
			SetNodeUsing("STATICIMAGES",false);
			SetNodeUsing("TEXTWINDOW",false);
			SetNodeUsing("HELPPICTURE",false);
			DisableString("HelpName");
		}
		break;
	}

	nCurShowType = newShowType;
	switch(nCurShowType)
	{
	case 0:
		{
			SetNodeUsing("TITLEWINDOW",true);
			SetCurrentNode("TITLEWINDOW");
			SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE,"TITLEWINDOW",1, curSectionIdx);
			SetNodeUsing("SCROLL",ig_bUseScroller);
		}
		break;
	case 1:
		{
			SetNodeUsing("STATICIMAGES",true);
			SetNodeUsing("TEXTWINDOW",true);
			SetNodeUsing("HELPPICTURE",true);
			EnableString("HelpName");
			SetCurrentNode("TEXTWINDOW");
		}
		break;
	}
}

void InitHelpSectionChooser()
{
	int i;
	string tmpStr, sectName;

	int strFileID = LanguageOpenFile("HelpSectionTitles.txt");
	if(strFileID<0) return;

	for(i=0;true;i++)
	{
		sectName = GetSectionNameFromIndex(i);
		if(sectName=="") break;
		tmpStr = LanguageConvertString(strFileID,sectName);
		SendMessage(&GameInterface,"lsle",MSG_INTERFACE_MSG_TO_NODE,"TITLEWINDOW", 0,&tmpStr);
	}
	LanguageCloseFile(strFileID);

	ig_bUseScroller = GetSelectable("SCROLL");
}

void ProcHelpSectionActivate()
{
	int hsNum = GetEventData();
	if(hsNum>=0)	LoadHelpSection(hsNum-curSectionIdx);
}

void ProcScrollChange()
{
	int changeNum = GetEventData();
	if(changeNum==0) return;
	if(nCurShowType==0)
	{
		if(changeNum==-1)
			SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"TITLEWINDOW",-1, 0,ACTION_UPSTEP);
		if(changeNum==1)
			SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"TITLEWINDOW",-1, 0,ACTION_DOWNSTEP);
	}
	else
	{
		if(changeNum==-1)
			SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"TEXTWINDOW",-1, 0,ACTION_UPSTEP);
		if(changeNum==1)
			SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"TEXTWINDOW",-1, 0,ACTION_DOWNSTEP);
	}
}

void ProcScrollPosChange()
{
	float newPos = GetEventData();
	if(nCurShowType==0)
		SendMessage(&GameInterface,"lslf",MSG_INTERFACE_MSG_TO_NODE,"TITLEWINDOW",2, newPos);
	else
		SendMessage(&GameInterface,"lslf",MSG_INTERFACE_MSG_TO_NODE,"TEXTWINDOW",2, newPos);
}
