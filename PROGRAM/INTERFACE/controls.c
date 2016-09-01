#define SHOWMOD_CONTROLSVIEW	1
#define SHOWMOD_CONTROL_SET		2
#define SHOWMOD_CONTROL_CHANGE	3

int nShowMode = 1;

object objArrayControls;

int qntGroup;
int curGroup;
int curCntrlIdx;

int nLastTextGroupNum;
int nLastTextStringNum;

int glob_retVal;

bool g_bThatIsPC;
string gsKeyWindowName;

int nFadeStr_AlUsed = 0;
int nFadeStr_NoStick = 0;

void InitInterface(string iniName)
{
    GameInterface.title = "titleControls";
    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

	if(GetTargetPlatform()=="PC")
	{
		g_bThatIsPC = true;
		gsKeyWindowName = "KEYSWINDOW_PC";
	} else
	{
		g_bThatIsPC = false;
		gsKeyWindowName = "KEYSWINDOW_XBOX";
	}

	SetNodeUsing("CONTROLSWINDOW",false);
	SetNodeUsing(gsKeyWindowName,false);
	SetNodeUsing("CONTROLGROUP",false);
	SetNodeUsing("SCROLL",false);

	SetNodeUsing("KEY_CHOOSER",false);
	SetNodeUsing("KEYCHOOSE_RECT",false);
	SetNodeUsing("KEYCHOOSE_STRINGS",false);

	SetNodeUsing("SET_BUTTON",false);
	SetNodeUsing("DELETE_BUTTON",false);
	SetNodeUsing("INVERSE_BUTTON",false);

	SetFormatedText("RESTORE_STRINGS",XI_ConvertString("Confirm default restore keys"));
	SetNodeUsing("RESTORE_RECT",false);
	SetNodeUsing("RESTORE_STRINGS",false);
	SetNodeUsing("RESTORE_OK",false);
	SetNodeUsing("RESTORE_CANCEL",false);

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
    SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);

	SetEventHandler("FormatedTextActivate","procFTActivate",0);
	SetEventHandler("evntUpdateFormtText","procFTUpdate",0);
	SetEventHandler("SetScrollerPos","procFTSetScrollPos",0);
	SetEventHandler("evntKeyChoose","procKeyChoose",0);
	SetEventHandler("ScrollPosChange","ProcScrollPosChange",0);

	SetStartData();

	aref ar; makearef(ar,objControlsState.key_codes);
	SendMessage(&GameInterface,"lsla",MSG_INTERFACE_MSG_TO_NODE,"KEY_CHOOSER", 0,ar);

	SetEventHandler("evntFadeStrings","FadeStringsUpdate",0);
	PostEvent("evntFadeStrings",100);
}

void SetStartData()
{
	aref arGroupRoot;
	makearef(arGroupRoot,objControlsState.grouplist);

	curGroup = -1;
	qntGroup = GetAttributesNum(arGroupRoot);
}

int GetRealGroupIndex(int grNum)
{
	aref arGroupRoot;
	makearef(arGroupRoot,objControlsState.grouplist);
	if(grNum<0 || grNum>=GetAttributesNum(arGroupRoot)) return -1;

	aref arCur = GetAttributeN(arGroupRoot,grNum);
	string groupName = GetAttributeName(arCur);

	makearef(arGroupRoot,objControlsState.keygroups);
	int q = GetAttributesNum(arGroupRoot);
	for(int n=0; n<q; n++)
	{
		arCur = GetAttributeN(arGroupRoot,n);
		if(GetAttributeName(arCur)==groupName) {return n;}
	}
	return -1;
}

void SetShowGroup(int grNum)
{
	if(grNum==curGroup)	return;
	curGroup = grNum;

	int nGrReal = GetRealGroupIndex(grNum);

	SetFormatedText("CONTROLSWINDOW","");
	if(nGrReal<0)
	{
		CreateString(true,"KeyGroupName","",FONT_NORMAL,COLOR_NORMAL,320,62,SCRIPT_ALIGN_CENTER,1.0);
		return;
	}

	int lngFile = LanguageOpenFile("ControlsNames.txt");
	if(lngFile<0) return;

	aref arGroupRoot, arGroup;
	makearef(arGroupRoot,objControlsState.keygroups);
	arGroup = GetAttributeN(arGroupRoot,nGrReal);

	// Установим название группы клавиш
	int showWidth = 480;
	string tmpStr = LanguageConvertString(lngFile,GetAttributeName(arGroup));
	int strWidth = GetStringWidth(tmpStr, FONT_NORMAL, 1.0);
	if(strWidth>showWidth)	{
		CreateString(true,"KeyGroupName",tmpStr,FONT_NORMAL,COLOR_NORMAL,320,62,SCRIPT_ALIGN_CENTER,makefloat(showWidth)/makefloat(strWidth));
	}	else	{
		CreateString(true,"KeyGroupName",tmpStr,FONT_NORMAL,COLOR_NORMAL,320,62,SCRIPT_ALIGN_CENTER,1.0);
	}

	// Прописать контроли в список
	DeleteAttribute(&objArrayControls,"");
	int i, idx, tmpcolor;
	aref arControl;
	bool bTmpBool;
	int qn = GetAttributesNum(arGroup);
	idx = 0;
	string cntrlText;
	for(i=0; i<qn; i++)
	{
		arControl = GetAttributeN(arGroup,i);
		if( CheckAttribute(arControl,"invisible") && sti(arControl.invisible)==true ) continue;
		if( CheckAttribute(arControl,"remapping") && sti(arControl.remapping)==false ) {
			bTmpBool = false;
			tmpcolor = argb(255,128,128,128);
		}
		else {
			bTmpBool = true;
			tmpcolor = argb(255,255,255,255);
		}

		if( GetTargetPlatform()!="pc" )
		{
			bTmpBool = false;
			tmpcolor = argb(255,128,128,128);
		}

		tmpstr = GetAttributeName(arControl);

		if( ControlIsStick(arControl) ) continue;

		cntrlText = LanguageConvertString(lngFile,tmpstr);
		if(cntrlText=="") continue;
		SendMessage(&GameInterface,"lsle",MSG_INTERFACE_MSG_TO_NODE,"CONTROLSWINDOW", 0,&cntrlText);
		SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"CONTROLSWINDOW", 8,-1,tmpcolor);
		SetControlNameForIdx(idx, tmpstr, bTmpBool);
		idx++;
	}

	LanguageCloseFile(lngFile);
	Event("evntUpdateFormtText","sll","CONTROLSWINDOW",0,0);
}

void ProcessCancelExit()
{
	DoIExit(RC_INTERFACE_CONTROLS_EXIT);
	if( !CheckAttribute(&InterfaceStates,"InstantExit") || sti(InterfaceStates.InstantExit)==false ) {
		ReturnToMainMenu();
	}
}

void DoIExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcessCommandExecute");
	DelEventHandler("FormatedTextActivate","procFTActivate");
	DelEventHandler("evntUpdateFormtText","procFTUpdate");
	DelEventHandler("SetScrollerPos","procFTSetScrollPos");
	DelEventHandler("evntKeyChoose","procKeyChoose");
	DelEventHandler("ScrollPosChange","ProcScrollPosChange");
	DelEventHandler("evntFadeStrings","FadeStringsUpdate");

	interfaceResultCommand = exitCode;
	if( CheckAttribute(&InterfaceStates,"InstantExit") && sti(InterfaceStates.InstantExit)==true ) {
		EndCancelInterface(true);
	} else {
		EndCancelInterface(false);
	}
}

void NextKeyGroup(int groupDelta)
{
	int newGrNum = curGroup + groupDelta;
	if(newGrNum<0)	newGrNum = qntGroup-1;
	if(newGrNum>=qntGroup) newGrNum = 0;

	SetShowGroup(newGrNum);
}

void procFTActivate()
{
	string nodName = GetEventData();
	if(nodName!="CONTROLSWINDOW") return;
	curCntrlIdx = GetEventData(); // номер текста

	if( !IsEnableRemapping(curCntrlIdx) ) return;

	SetShowMode(SHOWMOD_CONTROL_CHANGE);
}

ref procKeyChoose()
{
	int keyIdx = GetEventData();
	int stickUp = GetEventData();

	glob_retVal = false;
	if( DoMapToOtherKey(keyIdx,stickUp) )
	{
		SetShowMode(SHOWMOD_CONTROLSVIEW);
		Event("evntUpdateFormtText","sll","CONTROLSWINDOW", nLastTextGroupNum, nLastTextStringNum);
		glob_retVal = true;
	}

	return &glob_retVal;
}

void procFTUpdate()
{
	string nodName = GetEventData();
	if(nodName!="CONTROLSWINDOW") return;
	int grNum = GetEventData(); // первая группа в изменениях
	int strNum = GetEventData(); // первая строка в изменениях

	object objPos,obj;
	DeleteAttribute(&objPos,"");
	SendMessage(&GameInterface,"lsla",MSG_INTERFACE_MSG_TO_NODE,"CONTROLSWINDOW", 3,&objPos);

	SetFormatedText(gsKeyWindowName,"");

	int i,qn,posnum;
	qn = GetAttributesNum(&objPos);
	int idx=0;
	for(i=0; i<qn; i++)
	{
		posnum = sti( GetAttributeValue(GetAttributeN(&objPos,i)) );
		if(posnum>=0)
		{
			idx = SetKeysStrings(grNum+i,posnum,idx);
		}
	}
	nLastTextGroupNum = grNum;
	nLastTextStringNum = strNum;
}

void procFTSetScrollPos()
{
	string nodName = GetEventData();
	float fpos = GetEventData();
	if(nodName=="CONTROLSWINDOW")
	{
		SendMessage(&GameInterface,"lsf",MSG_INTERFACE_SET_SCROLLER,"SCROLL",fpos);
	}
}

int SetKeysStrings(int grNum, int newpos, int oldpos)
{
	int i;
	string tmpStr;
	string keyStr = " ";
	for(i=oldpos; i<newpos; i++)
	{
		SendMessage(&GameInterface,"lsle",MSG_INTERFACE_MSG_TO_NODE,gsKeyWindowName, 0,&keyStr);
	}

	aref arGroupRoot,arKey;
	makearef(arGroupRoot,objControlsState.keygroups);
	arGroupRoot = GetAttributeN(arGroupRoot,GetRealGroupIndex(curGroup));
	tmpStr = GetControlNameFromIdx(grNum);
	if( CheckAttribute(arGroupRoot,tmpStr) )	tmpStr = arGroupRoot.(tmpStr);
	else	tmpStr = "";

	//arKey = GetAttributeN(GetAttributeN(arGroupRoot,GetRealGroupIndex(curGroup)),grNum);
	//tmpStr = GetAttributeValue(arKey);
	//tmpStr = objControlsState.keygroups.

	if(CheckAttribute(&objControlsState,"key_codes."+tmpStr+".img"))
	{
		keyStr = objControlsState.key_codes.(tmpStr).img;
	}
	if(keyStr=="")	keyStr=" ";
/*	else
	{
		if( CheckAttribute(arKey,"state") )
		{
			if( sti(arKey.state)==USE_AXIS_AS_INVERSEBUTTON || sti(arKey.state)==INVERSE_CONTROL )
			{
				keyStr = "!"+keyStr;
			}
		}
	}*/

	i += SendMessage(&GameInterface,"lsle",MSG_INTERFACE_MSG_TO_NODE,gsKeyWindowName, 0,&keyStr);
	return i;
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	switch(nodName)
	{
	case "CONTROLSWINDOW":
		if(comName=="leftstep")
		{
			NextKeyGroup(-1);
		}
		if(comName=="rightstep")
		{
			NextKeyGroup(1);
		}
	break;

	case "RESTORE_SETTING":
		if(comName=="activate" || comName=="click")
		{
			SetNodeUsing("RESTORE_RECT",true);
			SetNodeUsing("RESTORE_STRINGS",true);
			SetNodeUsing("RESTORE_OK",true);
			SetNodeUsing("RESTORE_CANCEL",true);
			SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "RESTORE_OK");
			SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "RESTORE_CANCEL");
			SetCurrentNode("RESTORE_OK");
		}
	break;

	case "RESTORE_CANCEL":
		if(comName=="activate" || comName=="click" || comName=="deactivate")
		{
			SetNodeUsing("RESTORE_RECT",false);
			SetNodeUsing("RESTORE_STRINGS",false);
			SetNodeUsing("RESTORE_OK",false);
			SetNodeUsing("RESTORE_CANCEL",false);
			SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
			SetCurrentNode("RESTORE_SETTING");
		}
	break;

	case "RESTORE_OK":
		if(comName=="activate" || comName=="click" || comName=="deactivate")
		{
			if(comName!="deactivate")
			{
				ControlsInit(GetTargetPlatform(),false);
			}
			SetNodeUsing("RESTORE_RECT",false);
			SetNodeUsing("RESTORE_STRINGS",false);
			SetNodeUsing("RESTORE_OK",false);
			SetNodeUsing("RESTORE_CANCEL",false);
			SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
			SetCurrentNode("RESTORE_SETTING");
		}
	break;

	case "CHANGE_SETTING":
		if(comName=="activate" || comName=="click")
		{
			SetNodeUsing("RESTORE_SETTING",false);
			SetNodeUsing("CHANGE_SETTING",false);
			SetNodeUsing("CONTROLSWINDOW",true);
			SetNodeUsing(gsKeyWindowName,true);
			SetNodeUsing("CONTROLGROUP",true);
			SetNodeUsing("SCROLL",true);
			SetCurrentNode("CONTROLSWINDOW");
			SetShowGroup(0);
		}
	break;

	case "SET_BUTTON":
		if(comName=="deactivate")
		{
			SetShowMode(SHOWMOD_CONTROLSVIEW);
		}
		if(comName=="downstep")
		{
			if(GetSelectable("DELETE_BUTTON"))
			{	SetCurrentNode("DELETE_BUTTON");
			}
			else
			{
				if(GetSelectable("INVERSE_BUTTON"))
				{	SetCurrentNode("INVERSE_BUTTON");
				}
			}
		}
		if(comName=="activate" || comName=="click")
		{
			SetShowMode(SHOWMOD_CONTROL_SET);
		}
	break;

	case "DELETE_BUTTON":
		if(comName=="deactivate")
		{
			SetShowMode(SHOWMOD_CONTROLSVIEW);
		}
		if(comName=="downstep")
		{
			if(GetSelectable("INVERSE_BUTTON"))
				{	SetCurrentNode("INVERSE_BUTTON");	}
		}
		if(comName=="upstep")
			{	SetCurrentNode("SET_BUTTON")	}
		if(comName=="activate" || comName=="click")
		{
			UnmapControl();
			SetShowMode(SHOWMOD_CONTROLSVIEW);
		}
	break;

	case "INVERSE_BUTTON":
		if(comName=="deactivate")
		{
			SetShowMode(SHOWMOD_CONTROLSVIEW);
		}
		if(comName=="upstep")
		{
			if(GetSelectable("DELETE_BUTTON"))
				{	SetCurrentNode("DELETE_BUTTON");	}
			else
				{	SetCurrentNode("SET_BUTTON");	}
		}
		if(comName=="activate" || comName=="click")
		{
			InverseControl();
			SetShowMode(SHOWMOD_CONTROLSVIEW);
		}
	break;
	}
}

void SetShowMode(int newShowMod)
{
	if(nShowMode==newShowMod) return;

	switch(nShowMode)
	{
	case SHOWMOD_CONTROLSVIEW:
		SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "KEY_CHOOSER");
		SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "SET_BUTTON");
		SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "DELETE_BUTTON");
		SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "INVERSE_BUTTON");
	break;

	case SHOWMOD_CONTROL_SET:
		SetNodeUsing("KEY_CHOOSER",false);
		SetNodeUsing("KEYCHOOSE_RECT",false);
		DisableString("PressKey");
	break;

	case SHOWMOD_CONTROL_CHANGE:
		SetNodeUsing("KEYCHOOSE_RECT",false);
		SetNodeUsing("SET_BUTTON",false);
		SetNodeUsing("DELETE_BUTTON",false);
		SetNodeUsing("INVERSE_BUTTON",false);
	break;
	}

	nShowMode=newShowMod;

	switch(nShowMode)
	{
	case SHOWMOD_CONTROLSVIEW:
		SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
		SetCurrentNode("CONTROLSWINDOW");
	break;

	case SHOWMOD_CONTROL_SET:
		SetNodeUsing("KEYCHOOSE_RECT",true);
		SetNodeUsing("KEY_CHOOSER",true);
		if( IsStickNow(curCntrlIdx) )
		{	CreateString(true,"PressKey",XI_ConvertString("Tilt any joystick"),FONT_NORMAL,COLOR_NORMAL,320,170,SCRIPT_ALIGN_CENTER,1.0);
		}else
		{	CreateString(true,"PressKey",XI_ConvertString("Press any key"),FONT_NORMAL,COLOR_NORMAL,320,170,SCRIPT_ALIGN_CENTER,1.0);
		}
		SetCurrentNode("KEY_CHOOSER");
	break;

	case SHOWMOD_CONTROL_CHANGE:
		SetNodeUsing("KEYCHOOSE_RECT",true);
		SetNodeUsing("SET_BUTTON",true);
		SetNodeUsing("DELETE_BUTTON",true);
		SetNodeUsing("INVERSE_BUTTON",true);
		SetCurrentNode("SET_BUTTON");
	break;
	}
}

bool DoMapToOtherKey(int keyIdx,int stickUp)
{
	aref arControlRoot,arControlGroup;
	aref arKeyRoot,arKey;
	string contrlName,groupName, tmpstr;
	int keyCode;

	if( stickUp )
	{
		SetStickNotAvailable();
		return false;
	}

	makearef(arControlRoot,objControlsState.keygroups);
	arControlGroup = GetAttributeN(arControlRoot,GetRealGroupIndex(curGroup));

	groupName = GetAttributeName(arControlGroup);
	contrlName = GetControlNameFromIdx(curCntrlIdx);

	makearef(arKeyRoot,objControlsState.key_codes);
	arKey = GetAttributeN(arKeyRoot,keyIdx);
	keyCode = sti(GetAttributeValue(arKey));

	if( CheckAttribute(arKey,"stick") && sti(arKey.stick)==true ) return false;

	if( KeyAlreadyUsed(groupName, contrlName, GetAttributeName(arKey)) )
	{
		SetAlreadyUsedShow();
		return false;
	}

	tmpstr = objControlsState.keygroups.(groupName).(contrlName);
	if( CheckAttribute(arKeyRoot,tmpstr+".stick") && sti(arKeyRoot.(tmpstr).stick)==true ) return false;

	int state = 0;
	if(CheckAttribute(&objControlsState,"keygroups."+groupName+"."+contrlName+".state"))
	{	state = sti(objControlsState.keygroups.(groupName).(contrlName).state);	}

	CI_CreateAndSetControls( groupName,contrlName,keyCode, state, true );
	return true;
}

bool IsStickNow(int cntrlNum)
{
	return false;
}

void ProcScrollPosChange()
{
	float newPos = GetEventData();
	SendMessage(&GameInterface,"lslf",MSG_INTERFACE_MSG_TO_NODE,"CONTROLSWINDOW",2, newPos);
}

void UnmapControl()
{
	aref arControlRoot,arControlGroup;
	string contrlName,groupName;

	makearef(arControlRoot,objControlsState.keygroups);
	arControlGroup = GetAttributeN(arControlRoot,GetRealGroupIndex(curGroup));

	groupName = GetAttributeName(arControlGroup);
	contrlName = GetControlNameFromIdx(curCntrlIdx);

	int state = 0;
	if(CheckAttribute(&objControlsState,"keygroups."+groupName+"."+contrlName+".state"))
	{	state = sti(objControlsState.keygroups.(groupName).(contrlName).state);	}

	CI_CreateAndSetControls( groupName,contrlName, -1,state, true );

	Event("evntUpdateFormtText","sll","CONTROLSWINDOW", nLastTextGroupNum, nLastTextStringNum);
}

void InverseControl()
{
	if(curGroup<0 || curCntrlIdx<0)	{return;}
	aref arControlRoot,arControlGroup;
	string contrlName,groupName;

	makearef(arControlRoot,objControlsState.keygroups);
	arControlGroup = GetAttributeN(arControlRoot,GetRealGroupIndex(curGroup));

	groupName = GetAttributeName(arControlGroup);
	contrlName = GetAttributeName(GetAttributeN(&objArrayControls,curCntrlIdx));

	int state = 0;
	if(CheckAttribute(&objControlsState,"keygroups."+groupName+"."+contrlName+".state"))
	{	state = sti(objControlsState.keygroups.(groupName).(contrlName).state);	}

	switch(state)
	{
	case USE_AXIS_AS_BUTTON:		state=USE_AXIS_AS_INVERSEBUTTON;	break;
	case USE_AXIS_AS_INVERSEBUTTON:	state=USE_AXIS_AS_BUTTON;	break;
	case INVERSE_CONTROL:			state=0;	break;
	case 0:							state=INVERSE_CONTROL;	break;
	}

	objControlsState.keygroups.(groupName).(contrlName).state = state;
	CI_CreateAndSetControls( groupName,contrlName, CI_GetKeyCode(objControlsState.keygroups.(groupName).(contrlName)), state, true );

	Event("evntUpdateFormtText","sll","CONTROLSWINDOW", nLastTextGroupNum, nLastTextStringNum);
}

bool IsEnableRemapping(int nControl)
{
	aref arControl;
	arControl = GetAttributeN(&objArrayControls,nControl);
	return sti(arControl.enable);
}

string GetControlNameFromIdx(int idx)
{
	string attrName = "i"+idx;
	if( CheckAttribute(&objArrayControls,attrName) ) return objArrayControls.(attrName);
	return "";
}

void SetControlNameForIdx(int idx, string controlName, bool bRemapEnable)
{
	string attrName = "i"+idx;
	objArrayControls.(attrName) = controlName;
	objArrayControls.(attrName).enable = bRemapEnable;
}

bool ControlIsStick(aref arControl)
{
	string sKeyName = GetAttributeValue(arControl);

	if( CheckAttribute(&objControlsState,"key_codes."+sKeyName+".stick") &&
		sti(objControlsState.key_codes.(sKeyName).stick)==true )
	{
		//if( sti(arControl.state)==USE_AXIS_AS_INVERSEBUTTON ) return false;
		//if( sti(arControl.state)==INVERSE_CONTROL ) return false;
		return true;
	}

	return false;
}

bool KeyAlreadyUsed(string groupName, string controlName, string keyName)
{
	int n, q;
	aref arRoot, arCntrl;
	makearef( arRoot, objControlsState.keygroups.(groupName) );
	q = GetAttributesNum(arRoot);

	for(n=0; n<q; n++)
	{
		arCntrl = GetAttributeN(arRoot,n);
		if( GetAttributeName(arCntrl)==controlName ) continue;
		if( GetAttributeValue(arCntrl)==keyName) return true;
	}

	return false;
}

void SetAlreadyUsedShow()
{
	nFadeStr_NoStick = 0;
	nFadeStr_AlUsed = 15;
}
void SetStickNotAvailable()
{
	nFadeStr_AlUsed = 0;
	nFadeStr_NoStick = 15;
}

void FadeStringsUpdate()
{
	int color;
	if( nFadeStr_AlUsed>0 )
	{
		nFadeStr_AlUsed--;
		if(nFadeStr_AlUsed==0)
		{
			GameInterface.strings.AlreadyUsed = "";
		}
		else
		{
			color = argb(GetAlphaFromFade(nFadeStr_AlUsed),255,255,255);
			CreateString(true,"AlreadyUsed",XI_ConvertString("Button Already Used"),FONT_NORMAL,color,320,258,SCRIPT_ALIGN_CENTER,1.0);
		}
	}

	if( nFadeStr_NoStick>0 )
	{
		nFadeStr_NoStick--;
		if(nFadeStr_NoStick==0)
		{
			GameInterface.strings.AlreadyUsed = "";
		}
		else
		{
			color = argb(GetAlphaFromFade(nFadeStr_NoStick),255,255,255);
			CreateString(true,"AlreadyUsed",XI_ConvertString("thumbstick cannot be used"),FONT_NORMAL,color,320,258,SCRIPT_ALIGN_CENTER,1.0);
		}
	}

	PostEvent("evntFadeStrings",100);
}

int GetAlphaFromFade(int n)
{
	int alpha = n*20;
	if(alpha>255) alpha = 255;
	if(alpha<0) alpha = 0;
	return alpha;
}
