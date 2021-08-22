int lngFileID;
string newLine;

void InitInterface(string iniName)
{
	GameInterface.title = "titlePlayerProfiles";

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	lngFileID = LanguageOpenFile("AbilityDescribe.txt");
	newLine = LanguageConvertString(lngFileID,"newLine");

	SetNodeUsing("DESCRIBEWINDOW",false);
	SetNodeUsing("PROFILE_NAME",false);
	SetNodeUsing("OK_BUTTON",false);
	SetNodeUsing("CANCEL_BUTTON",false);
	SetNodeUsing("DESCRIBE_RECT",false);
	SetSelectable("EXIT_BUTTON",true);

	CreateExitString();

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);

	SetEventHandler("FormatedTextActivate","procFTActivate",0);
	SetEventHandler("SetScrollerPos","procFTSetScrollPos",0);
	SetEventHandler("ScrollPosChange","ProcScrollPosChange",0);
//	SetEventHandler("evntUpdateFormtText","procFTUpdate",0);
	SetEventHandler("ScrollTopChange","ProcScrollChange",0);

	SetProfilesList();
}

void ProcessCancelExit()
{
	IDoExit(RC_INTERFACE_PROFILES_EXIT);
}

void IDoExit(int exitCode)
{
	LanguageCloseFile(lngFileID);

	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcessCommandExecute");
	DelEventHandler("FormatedTextActivate","procFTActivate");
	DelEventHandler("SetScrollerPos","procFTSetScrollPos");
	DelEventHandler("ScrollPosChange","ProcScrollPosChange");
//	DelEventHandler("evntUpdateFormtText","procFTUpdate");
	DelEventHandler("ScrollTopChange","ProcScrollChange");

    interfaceResultCommand = exitCode;
	if(CheckAttribute(&InterfaceStates,"InstantExit") && sti(InterfaceStates.InstantExit)==true) EndCancelInterface(false);
	else EndCancelInterface(true);
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	switch(nodName)
	{
	case "OK_BUTTON":
		if(comName=="deactivate") {	ReturnToProfilesView(); }
		if(comName=="activate" || comName=="click") { ReturnToProfilesView(); }
	break;

	case "CANCEL_BUTTON":
		if(comName=="deactivate" || comName=="activate" || comName=="click") { ReturnToProfilesView(); }
		if(comName=="leftstep") { if(GetSelectable("OK_BUTTON")) { SetCurrentNode("OK_BUTTON"); } }
	break;
	}
}

void SetProfilesList()
{
	string tmpStr,profName;
	aref arProfilesRoot;
	if(CheckAttribute(&GameInterface,"profileslist")) DeleteAttribute(&GameInterface,"profileslist");

	GameInterface.profileslist.profile0 = DEFAULT_NAME;
	profName = DEFAULT_NAME;
	SendMessage(&GameInterface,"lsle",MSG_INTERFACE_MSG_TO_NODE,"PROFILESWINDOW", 0,&profName);

	makearef(arProfilesRoot,PlayerProfile.profiles);
	for(int i=0; i<GetAttributesNum(arProfilesRoot); i++)
	{
		profName = GetAttributeName(GetAttributeN(arProfilesRoot,i));
		if(profName==DEFAULT_NAME) continue;
		tmpStr = "profile"+sti(i+1);
		GameInterface.profileslist.(tmpStr) = profName;
		if(profName=="") { profName=" "; }
		SendMessage(&GameInterface,"lsle",MSG_INTERFACE_MSG_TO_NODE,"PROFILESWINDOW", 0,&profName);
	}

//	Event("procFTActivate","sll","PROFILESWINDOW",0,0);
}

void DoViewDescribe(string profName, int texNum)
{
	if(profName=="") return;
	string profileName = profName;
	string tmpStr = "profile"+texNum;

	SetNodeUsing("DESCRIBEWINDOW",true);
	SetNodeUsing("PROFILE_NAME",true);
	SetNodeUsing("OK_BUTTON",true);
	SetNodeUsing("CANCEL_BUTTON",true);
	SetNodeUsing("DESCRIBE_RECT",true);

	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "DESCRIBEWINDOW");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "OK_BUTTON");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "CANCEL_BUTTON");

	SendMessage(&GameInterface,"lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE,"PROFILE_NAME",0,
		"profileName", profName, FONT_NORMAL,
		384,108, argb(255,255,255,255),0, SCRIPT_ALIGN_CENTER, true, 1.5, 420);

	SetSelectable("OK_BUTTON",true);
	SetCurrentNode("CANCEL_BUTTON");

	SetFormatedText("DESCRIBEWINDOW","ЭТО ПРОВЕРКА");
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"DESCRIBEWINDOW", 5);
}

void ReturnToProfilesView()
{
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);

	SetNodeUsing("DESCRIBEWINDOW",false);
	SetNodeUsing("PROFILE_NAME",false);
	SetNodeUsing("OK_BUTTON",false);
	SetNodeUsing("CANCEL_BUTTON",false);
	SetNodeUsing("DESCRIBE_RECT",false);

	SetCurrentNode("PROFILESWINDOW");
}

void procFTActivate()
{
	string nodName = GetEventData();
	int texNum = GetEventData();
	if(nodName!="PROFILESWINDOW") return;

	DoViewDescribe(GetProfileName(texNum), texNum);
}

void procFTSetScrollPos()
{
	string nodName = GetEventData();
	float fpos = GetEventData();

	if(nodName!="PROFILESWINDOW") return;
	SendMessage(&GameInterface,"lsf",MSG_INTERFACE_SET_SCROLLER,"SCROLL",fpos);
}

void ProcScrollPosChange()
{
	float newPos = GetEventData();
	SendMessage(&GameInterface,"lslf",MSG_INTERFACE_MSG_TO_NODE,"PROFILESWINDOW",2, newPos);
}

void ProcScrollChange()
{
	int changeNum = GetEventData();
	if(changeNum==0) return;
	if(changeNum>0) {
		SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"PROFILESWINDOW",-1, 0,ACTION_DOWNSTEP);
	} else {
		SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"PROFILESWINDOW",-1, 0,ACTION_UPSTEP);
	}
}

string GetProfileName(int profNum)
{
	string tmpstr = "profile"+profNum;
	if(CheckAttribute(&GameInterface,"profileslist."+tmpstr)) { return GameInterface.profileslist.(tmpstr); }
	return "";
}