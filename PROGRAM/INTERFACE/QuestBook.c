#define	CST_QUESTTITLE	1
#define CST_QUESTTEXT	2

#define MAX_QUESTBOOK_LINES	11

int curShowType=CST_QUESTTITLE;
int curQuestTop;
int curQuestIdx;

void InitInterface(string iniName)
{
	int i, column, row;
	GameInterface.title = "titleQuestBook";

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();//MAXIMUS: standard exit-string for exit-button

	CreateString(true, "TIME", GetHumanDate(GetDataYear(), GetDataMonth(), GetDataDay())+ " " + GetStringTime(GetTime()), FONT_NORMAL, COLOR_NORMAL, 320, 482, SCRIPT_ALIGN_CENTER, 0.7); // KK

	CreateString(false, "QuestText_Title", "", FONT_QUESTBOOK, COLOR_WHITE, 320, 50, SCRIPT_ALIGN_CENTER, 1.2);

// KK -->
	for (i = PERSONAL_NATION; i < NATIONS_QUANTITY; i++)
	{
		column = -30;
		if(i>2) column = 600;
		row = 170+i*100;
		if(i>2) row = row - 400;
		SetNewPicture("NATION" + i, "interfaces\flags\Crest_" + GetFlagPicName(i) + ".tga");
		SetNodeUsing( "NATION" + i, true);
		CreateImage(i+"Black", "ICONS", "black rectangle", column,row,column+70,row+20);
		// PB: Indicate Served Nation -->
		if (i == GetServedNation())	CreateString(true, i+"Text", XI_ConvertString(GetNationNameByType(i)), FONT_SEADOGS, COLOR_YELLOW, column+35, row-1, SCRIPT_ALIGN_CENTER, 0.9);
		else						CreateString(true, i+"Text", XI_ConvertString(GetNationNameByType(i)), FONT_SEADOGS, COLOR_NORMAL, column+35, row+1, SCRIPT_ALIGN_CENTER, 0.7);
		// PB: Indicate Served Nation <--
	}
// <-- KK

	curQuestTop = 0;
	curQuestIdx = 0;
	CreateQHeadersList();
	DisplayQHeadersList();

// KK -->
	bool hasShip = false;
	ref MainChar = GetMainCharacter();
	for (i = 0; i < COMPANION_MAX; i++) {
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
		SendMessage(&GameInterface, "lsls", MSG_INTERFACE_MSG_TO_NODE, "I_SHIP", 0, "#"+XI_ConvertString("Sel Berth"));
	}
// <-- KK

// MAXIMUS interface MOD -->
	SetSelectable("I_SHIP", !LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm() && hasShip); // KK
	// KK SetSelectable("I_NATIONS",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	SetSelectable("I_TRADEBOOK",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	SetSelectable("I_SHIPLOG",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());	
	SetSelectable("EXIT_BUTTON",true);

	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
// MAXIMUS interface MOD <--

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);

	SetEventHandler("FormatedTextActivate", "procFTActivate", 0); // KK

	// KK SetEventHandler("QuestTopChange","QuestTopChange",0);
	SetEventHandler("BackToTitle","BackToTitle",0);
	// KK SetEventHandler("QuestActivate","XI_QuestActivate",0);

	SetEventHandler("SetScrollerPos","SetScrollerPos",0);
	SetEventHandler("SetScrollerPosUp","SetScrollerPosUp",0);
	SetEventHandler("SetScrollerPosDown","SetScrollerPosDown",0);
	SetEventHandler("ScrollPosChange","ProcScrollPosChange",0);
	// KK SetEventHandler("ScrollTopChange","ProcScrollChange",0);
}

void XI_SetQuestData(bool qtitle)
{
	// set node & string using
	SetNodeUsing("QUESTRECTANGLE",true);
	SetNodeUsing("QUESTBOUND",true);
	SetNodeUsing("QUESTSCROLL",true);
	SetNodeUsing("QUEST_TITLE",qtitle);
	SetNodeUsing("QUEST_TEXT",!qtitle);
}

void ProcessCancelExit()
{
	IDoExit(RC_INTERFACE_QUESTBOOK_EXIT);
}

/*void QuestTopChange()
{
	if(curShowType==CST_QUESTTITLE)
	{
		int newTop = curQuestTop+GetEventData();

		ref myCh = GetMainCharacter();
		aref arefTmp;
		makearef(arefTmp,myCh.QuestInfo);
		int maxVal = GetAttributesNum(arefTmp);
		if(newTop>=maxVal)
		{
			newTop=maxVal-1;
		}
		if(newTop<0)
		{
			newTop=0;
		}

		if(newTop!=curQuestTop)
		{
			curQuestTop=newTop;
			XI_SetQuestTitles("QUEST_TITLE",arefTmp,curQuestTop);
			XI_SetScroller(MakeFloat(newTop)/MakeFloat(maxVal));
		}
	}
}*/

void SetQTextShow(aref pA,int qnum)
{
	// KK SendMessage(&GameInterface,"lsal",MSG_INTERFACE_INIT_QTEXT_SHOW,"QUEST_TEXT",pA,qnum);
}

void BackToTitle()
{
// KK	curShowType = CST_QUESTTITLE;
	DisplayQHeadersList();
// KK	XI_SetQuestData(true);
// KK	SetCurrentNode("QUEST_TITLE");
}

void XI_QuestActivate()
{
	curShowType = CST_QUESTTEXT;
	int aq = curQuestTop+GetEventData();
	ref refMyCh = GetMainCharacter();
	aref pA;
	makearef(pA,refMyCh.QuestInfo);
	SetQTextShow(pA,aq);
	XI_SetQuestData(false);
	SetCurrentNode("QUEST_TEXT");
}

void XI_SetScroller(float fpos)
{
	SendMessage(&GameInterface,"lsf",MSG_INTERFACE_SET_SCROLLER,"QUESTSCROLL",fpos);
}

void SetScrollerPos()
{
	string nodName = GetEventData();
	if(nodName=="QUEST_TEXT") return;
	float fpos = GetEventData();
	XI_SetScroller(fpos);
}

void SetScrollerPosUp()
{
	string controlNode = "";
	if( GetSelectable("QUESTBOOK_WINDOW") ) controlNode = "QUESTBOOK_WINDOW";
	if( GetSelectable("QUEST_TEXT") ) controlNode = "QUEST_TEXT";
	
	if(controlNode!="")
	{
		SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,controlNode,-1, 0,ACTION_UPSTEP);
	}
}

void SetScrollerPosDown()
{
	string controlNode = "";
	if( GetSelectable("QUESTBOOK_WINDOW") ) controlNode = "QUESTBOOK_WINDOW";
	if( GetSelectable("QUEST_TEXT") ) controlNode = "QUEST_TEXT";
	
	if(controlNode!="")
	{
		SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,controlNode,-1, 0,ACTION_DOWNSTEP);
	}
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	// KK DelEventHandler("QuestTopChange","QuestTopChange");
	DelEventHandler("BackToTitle","BackToTitle");
	// KK DelEventHandler("QuestActivate","XI_QuestActivate");
	DelEventHandler("SetScrollerPos","SetScrollerPos");
	DelEventHandler("ScrollPosChange","ProcScrollPosChange");
	DelEventHandler("SetScrollerPosUp","SetScrollerPosUp");
	DelEventHandler("SetScrollerPosDown","SetScrollerPosDown");
	// KK DelEventHandler("ScrollTopChange","ProcScrollChange");
	DelEventHandler("ievnt_command","ProcessCommandExecute"); // MAXIMUS interface MOD
	DelEventHandler("FormatedTextActivate", "procFTActivate"); // KK

    interfaceResultCommand = exitCode;
// MAXIMUS interface MOD -->
	EndCancelInterface(true);/*
	if( CheckAttribute(&InterfaceStates,"InstantExit") && sti(InterfaceStates.InstantExit)==true )
	{
		EndCancelInterface(true);
	}
	else
	{
		PostEvent("LaunchIAfterFrame",1,"sl", "I_SELECTMENU", 1);
		EndCancelInterface(false);
	}*/
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
		interfaceResultCommand = RC_INTERFACE_QUESTBOOK_EXIT;
		EndCancelInterface(false);

	}
}
        if(nodName=="I_SHIP")
{
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_QUESTBOOK_EXIT;
		EndCancelInterface(false);

	}
}
        if(nodName=="I_SHIPHOLD")
{
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_QUESTBOOK_EXIT;
		EndCancelInterface(false);

	}
}
        if(nodName=="I_PASSENGER")
{
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_QUESTBOOK_EXIT;
		EndCancelInterface(false);

	}
}
        if(nodName=="I_TRADEBOOK")
{
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_QUESTBOOK_EXIT;
		EndCancelInterface(false);

	}
}
        if(nodName=="I_SHIPLOG")
{
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_QUESTBOOK_EXIT;
		EndCancelInterface(false);

	}
}
        if(nodName=="I_NATIONS")
{
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_QUESTBOOK_EXIT;
		EndCancelInterface(false);

	}
}
        if(nodName=="I_ITEMS")
{
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_QUESTBOOK_EXIT;
		EndCancelInterface(false);

	}
}
}
// MAXIMUS interface MOD <--

// KK -->
void procFTActivate()
{
	string nodName = GetEventData();
	curQuestIdx = GetEventData();

	if (nodName == "QUESTBOOK_WINDOW") DisplayQuestText();
}
// <-- KK

void ProcScrollPosChange()
{
	float newPos = GetEventData();
	if(curShowType==CST_QUESTTITLE)
	{
		ref myCh = GetMainCharacter();
		aref arefTmp;
		makearef(arefTmp,myCh.QuestInfo);
		int maxVal = GetAttributesNum(arefTmp);
		int newTop = makeint(newPos*maxVal);

		if (newTop > curQuestIdx)
		{
			if (newTop - curQuestTop + 1 > MAX_QUESTBOOK_LINES) curQuestTop = curQuestTop + (newTop - curQuestIdx);
			SendMessage(&GameInterface,"lslf",MSG_INTERFACE_MSG_TO_NODE,"QUESTBOOK_WINDOW", 2, newPos);
		}
		if (newTop < curQuestIdx)
		{
			if (newTop - curQuestTop < 0) curQuestTop--;
			SendMessage(&GameInterface,"lslf",MSG_INTERFACE_MSG_TO_NODE,"QUESTBOOK_WINDOW", 2, newPos);
		}
		curQuestIdx = newTop;
		DisplayQHeadersList();
	}
	else
	{
		SendMessage(&GameInterface,"lslf",MSG_INTERFACE_MSG_TO_NODE,"QUEST_TEXT", 2, newPos);
	}
}

void ProcScrollChange()
{
	int changeNum = GetEventData();
	if(changeNum==0) return;
	string controlNode = "";
	if( GetSelectable("QUESTBOOK_WINDOW") ) controlNode = "QUESTBOOK_WINDOW";
	if( GetSelectable("QUEST_TEXT") ) controlNode = "QUEST_TEXT";

	if(controlNode!="")
	{
		if(changeNum>0) {
			SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,controlNode,-1, 0,ACTION_DOWNSTEP);
		} else {
			SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,controlNode,-1, 0,ACTION_UPSTEP);
		}
	}
}

void CreateQHeadersList()
{
	aref arefTmp;
	ref myCh = GetMainCharacter();
	makearef(arefTmp,myCh.QuestInfo);
	int num = GetAttributesNum(arefTmp);
	int l = 0;
	for (int i = 0; i < num; i++) {
		aref arefQ = GetAttributeN(arefTmp, i);
		string title = arefQ.Title;
		if (title == "" || arefQ.Text == "") continue;
		bool complete = sti(arefQ.Complete);
		SendMessage(&GameInterface, "lsle", MSG_INTERFACE_MSG_TO_NODE, "QUESTBOOK_WINDOW", 0, &title);
		if (complete)
			SendMessage(&GameInterface, "lslll", MSG_INTERFACE_MSG_TO_NODE, "QUESTBOOK_WINDOW", 8, -1, COLOR_GRAY);
		else
			SendMessage(&GameInterface, "lslll", MSG_INTERFACE_MSG_TO_NODE, "QUESTBOOK_WINDOW", 8, -1, COLOR_WHITE);
		l++;
	}
}

void DisplayQHeadersList()
{
	curShowType = CST_QUESTTITLE;

	aref arefTmp;
	ref myCh = GetMainCharacter();
	makearef(arefTmp,myCh.QuestInfo);
	int num = GetAttributesNum(arefTmp);
	int start = curQuestTop;
	if (num > MAX_QUESTBOOK_LINES && start +  MAX_QUESTBOOK_LINES > num) start = num - MAX_QUESTBOOK_LINES;
	for (int l = 0; l < MAX_QUESTBOOK_LINES; l++) {
		if (l + start >= num) break;
		aref arefQ = GetAttributeN(arefTmp, l + start);
		if (arefQ.Text == "") continue;
		bool complete = sti(arefQ.Complete);
		CreateImage("QuestMarker" + l, "", "", 548, 58 + l * 32, 580, 58 + (l + 1) * 32);
		if (complete)
			CreateImage("QuestMarker" + l, "icons", "complete", 548, 58 + l * 32, 580, 58 + (l + 1) * 32);
		else
			CreateImage("QuestMarker" + l, "icons", "noncomplete", 548, 58 + l * 32, 580, 58 + (l + 1) * 32);
	}
	SetNodeUsing("QUESTTEXT_LINE", false);
	DisableString("QuestText_Title");
	SetNodeUsing("QUEST_TEXT", false);
	SetNodeUsing("QUESTBOOK_WINDOW", true);
	SetCurrentNode("QUESTSCROLL");
}

void DisplayQuestText()
{
	curShowType = CST_QUESTTEXT;

	aref arefTmp;
	ref myCh = GetMainCharacter();
	makearef(arefTmp,myCh.QuestInfo);
	int num = GetAttributesNum(arefTmp);
	if (num < curQuestIdx) return;

	aref arefQ = GetAttributeN(arefTmp, curQuestIdx);
	string idQuest = GetAttributeName(arefQ);

	if (sti(arefQ.Complete) == true)
		ChangeStringColor("QuestText_Title", COLOR_GRAY);
	else
		ChangeStringColor("QuestText_Title", COLOR_WHITE);
	GameInterface.strings.QuestText_Title = arefQ.Title;
	EnableString("QuestText_Title");

	string text = "";
	SetFormatedText("QUEST_TEXT", text);
	int nrecord = GetQuestRecord(idQuest, 1);
	int i = 1;
	while (nrecord > 0) {
		text = GetQuestBookText(idQuest, nrecord);
		SendMessage(&GameInterface, "lsle", MSG_INTERFACE_MSG_TO_NODE, "QUEST_TEXT", 0, &text);
		text = " ";
		SendMessage(&GameInterface, "lsle", MSG_INTERFACE_MSG_TO_NODE, "QUEST_TEXT", 0, &text);
		i++;
		nrecord = GetQuestRecord(idQuest, i);
	}

	if (num > MAX_QUESTBOOK_LINES) num = MAX_QUESTBOOK_LINES;

	for (i = 0; i < num; i++) CreateImage("QuestMarker" + i, "", "",  548, 58 + i * 32, 580, 58 + (i + 1) * 32);
	SetNodeUsing("QUESTBOOK_WINDOW", false);
	SetNodeUsing("QUESTTEXT_LINE", true);
	SetNodeUsing("QUEST_TEXT", true);
	SetCurrentNode("QUEST_TEXT");
}
