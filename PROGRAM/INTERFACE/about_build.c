//=====| INTERFACE FOR SHOWING INFORMATION ABOUT BUILD (written by MAXIMUS) |=====//
int lngFileID;

void InitInterface(string iniName)
{
    GameInterface.title = "titleAboutBuild";

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	lngFileID = LanguageOpenFile("about_build.txt");

	CreateExitString();
	ProcessShowMain();

	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);

	SetEventHandler("SetScrollerPos","procFTSetScrollPos",0);
	SetEventHandler("ScrollPosChange","ProcScrollPosChange",0);
	SetEventHandler("ScrollTopChange","ProcScrollChange",0);
}

void ProcessShowMain()
{
	int curPos = 60;
	for(int i=1; i<10; i++)
	{
		string nodes = "B_"+i;
		SendMessage(&GameInterface,"lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE,nodes,0,
			"DescName", LanguageConvertString(lngFileID,nodes), FONT_NORMAL,
			0,curPos, COLOR_RED_LIGHT,0, SCRIPT_ALIGN_LEFT, true, 1.0, 420);
		curPos = curPos + 40;
	}
	ReturnToMainView();
}

void ReturnToMainView()
{
	CreateString(true,"DescribeName","Build "+BUILDVERSION,FONT_NORMAL,COLOR_MONEY,385,50,SCRIPT_ALIGN_CENTER,0.7);
	CreateString(true,"Info_0",LanguageConvertString(lngFileID,"B_10"),FONT_NORMAL,COLOR_MONEY,385,374,SCRIPT_ALIGN_CENTER,0.7);
	CreateString(true,"Info_1",LanguageConvertString(lngFileID,"About_Build_10_1"),FONT_NORMAL,COLOR_NORMAL,300,396,SCRIPT_ALIGN_RIGHT,0.7);
	CreateString(true,"Info_2",LanguageConvertString(lngFileID,"About_Build_10_2"),FONT_NORMAL,COLOR_NORMAL,300,418,SCRIPT_ALIGN_RIGHT,0.7);
	CreateString(true,"Info_3",LanguageConvertString(lngFileID,"About_Build_10_3"),FONT_NORMAL,COLOR_NORMAL,300,440,SCRIPT_ALIGN_RIGHT,0.7);
	CreateString(true,"Info_1_1"," http://"+PA_INET,FONT_NORMAL,COLOR_BLUE_LIGHT,300,396,SCRIPT_ALIGN_LEFT,0.7);
	CreateString(true,"Info_2_1"," http://"+PA_DOWN,FONT_NORMAL,COLOR_BLUE_LIGHT,300,418,SCRIPT_ALIGN_LEFT,0.7);
	CreateString(true,"Info_3_1"," http://"+PA_WALK,FONT_NORMAL,COLOR_BLUE_LIGHT,300,440,SCRIPT_ALIGN_LEFT,0.7);
	CreateString(true,"Maelstrom",MAELSTROM,FONT_NORMAL,COLOR_BLUE_LIGHT,300,440,SCRIPT_ALIGN_LEFT,0.7);

	string infoText = LanguageConvertString(lngFileID,"About_Build");
	SetFormatedText("BUILD_DESCRIBE",infoText);
	SetNodeUsing("TEXTTSCROLL",false);
	SetCurrentNode("TITLE");
}

void DoBuildDescribe(int numAbout)
{
	GameInterface.strings.DescribeName = LanguageConvertString(lngFileID,"About_Build_" + numAbout + "_d");
	string infoText = LanguageConvertString(lngFileID,"About_Build_" + numAbout);
	SetFormatedText("BUILD_DESCRIBE",infoText);
	SetNodeUsing("TEXTTSCROLL",true);
	SetCurrentNode("BUILD_DESCRIBE");
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	if(strleft(nodName,2)=="B_")
	{
		if(GetNodeIdx(nodName, "B_", 2)!=-1)
		{
			if(comName=="click") DoBuildDescribe(GetNodeIdx(nodName, "B_", 2));
		}
	}

	switch(nodName)
	{
		case "TEXTTSCROLL":
			if(comName=="activate" || comName=="click") { SetCurrentNode("BUILD_DESCRIBE"); }
		break;

		case "BUILD_DESCRIBE":
			if(comName=="deactivate") { ReturnToMainView(); }
		break;
	}
}

int GetNodeIdx(string nName, string cutStr, int cutSymbols)
{
	if(nName=="" || strleft(nName, cutSymbols)!=cutStr) return -1;
	return sti(strcut(nName, cutSymbols, strlen(nName)-1));
}

void procFTSetScrollPos()
{
	string nodName = GetEventData();
	float fpos = GetEventData();
	if(nodName=="BUILD_DESCRIBE" || nodName=="TEXTTSCROLL")
	{
		SendMessage(&GameInterface,"lsf",MSG_INTERFACE_SET_SCROLLER,"TEXTTSCROLL",fpos);
	}
}

void ProcScrollPosChange()
{
	float newPos = GetEventData();
	SendMessage(&GameInterface, "lslf", MSG_INTERFACE_MSG_TO_NODE, "BUILD_DESCRIBE", 2, newPos);
}

void ProcScrollChange()
{
	int changeNum = GetEventData();
	if(changeNum==0) return;
	if(!GetSelectable("BUILD_DESCRIBE") && !GetSelectable("TEXTTSCROLL")) return;

	if(changeNum>0) SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"BUILD_DESCRIBE",-1, 0,ACTION_DOWNSTEP);
	else SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"BUILD_DESCRIBE",-1, 0,ACTION_UPSTEP);
}

void ProcessCancelExit()
{
	IDoExit(RC_INTERFACE_ABOUT_BUILD_EXIT);
	if(!CheckAttribute(&InterfaceStates,"InstantExit") || sti(InterfaceStates.InstantExit)==false) ReturnToMainMenu();
}

void IDoExit(int exitCode)
{
	LanguageCloseFile(lngFileID);
	DelEventHandler("ievnt_command","ProcessCommandExecute");
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("exitCancel","ProcessCancelExit");

	DelEventHandler("SetScrollerPos","procFTSetScrollPos");
	DelEventHandler("ScrollPosChange","ProcScrollPosChange");
	DelEventHandler("ScrollTopChange","ProcScrollChange");

	interfaceResultCommand = exitCode;
	if(CheckAttribute(&InterfaceStates,"InstantExit") && sti(InterfaceStates.InstantExit)==true) EndCancelInterface(true);
	else EndCancelInterface(false);
}
