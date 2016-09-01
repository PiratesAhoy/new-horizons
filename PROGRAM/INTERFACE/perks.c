int lngFileID = -1;
ref refUsedCharacter;
int chrPerksQ = 0;
string strPerkName;
bool ShowAssignableOnly = FALSE;

int imageQuantity = 0;
int perksIconsQ = 0;

int g_nGroup = 0;
int g_nLine = 0;

#define SHOW_NON_CONTRIB_PERK		1

ref MainChar; // MAXIMUS interface MOD

void InitInterface_R(string iniName, ref chref)
{
	GameInterface.title = "titleAbilitys";
	refUsedCharacter = chref;
	MainChar = GetMainCharacter();

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();//MAXIMUS: standard exit-string for exit-button

	string mychrname = GetMyFullName(refUsedCharacter);
	string offictype = "";
	if (IsMainCharacter(refUsedCharacter))
		offictype = + XI_ConvertString(GetCaptainType(refUsedCharacter));
	else
	{
		if(CheckAttribute(refUsedCharacter,"quest.officertype"))
			offictype = XI_ConvertString(refUsedCharacter.quest.officertype);
	}
	if (offictype != "") mychrname += " - " + offictype;
	CreateString(true,"ChrName",mychrname,FONT_NORMAL,COLOR_NORMAL,320,40,SCRIPT_ALIGN_CENTER,1.0); // Maximus
	CreateString(true,"FreeAbilities","",FONT_NORMAL,COLOR_NORMAL,120,74,SCRIPT_ALIGN_LEFT,1.0);
	lngFileID = LanguageOpenFile("AbilityDescribe.txt");

	//Create Strings for numbers
	//(int enable,string strName, string strData, string fontName, int color, int x, int y, int alignment, float scale)
	CreateString(true,"PERK_COST_0","10",FONT_BOLD_NUMBERS,COLOR_NORMAL,500,124,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"PERK_COST_1","10",FONT_BOLD_NUMBERS,COLOR_NORMAL,500,192,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"PERK_COST_2","10",FONT_BOLD_NUMBERS,COLOR_NORMAL,500,260,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"PERK_COST_3","10",FONT_BOLD_NUMBERS,COLOR_NORMAL,500,328,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"PERK_COST_4","10",FONT_BOLD_NUMBERS,COLOR_NORMAL,500,396,SCRIPT_ALIGN_RIGHT,1.0);
	
	SetNodeUsing("DESCRIBEWINDOW",false);
	SetNodeUsing("PERK_NAME",false);
	SetNodeUsing("PERK_IMAGE",false);
	SetNodeUsing("OK_BUTTON",false);
	SetNodeUsing("CANCEL_BUTTON",false);
	SetNodeUsing("DESCRIBE_RECT",false);
	SetSelectable("EXIT_BUTTON",true);
	SetNodeUsing("SHOWABILITIES", false); //Levis
	SetNodeUsing("SHOWFILTER", true); //Levis

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);

	SetEventHandler("FormatedTextActivate","procFTActivate",0);
	SetEventHandler("SetScrollerPos","procFTSetScrollPos",0);
	SetEventHandler("ScrollPosChange","ProcScrollPosChange",0);
	SetEventHandler("evntUpdateFormtText","procFTUpdate",0);
	SetEventHandler("ScrollTopChange","ProcScrollChange",0);	// added after build 11 by KAM
	
	SetEventHandler("changeshow","ChangeShowAbil",0); //added by Levis
	SetEventHandler("pressdown","GoToPerksWindow",0); //added by Levis

	SetAbilitesList();
}

void ProcessCancelExit()
{

// View Enc Officer: Taghmon

    GameInterface.AbilityChr = refUsedCharacter.index;

// View Enc Officer End
	DoIExit(RC_INTERFACE_PERKS_EXIT);
}

void DoIExit(int exitCode)
{
	LanguageCloseFile(lngFileID);

	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcessCommandExecute");
	DelEventHandler("FormatedTextActivate","procFTActivate");
	DelEventHandler("SetScrollerPos","procFTSetScrollPos");
	DelEventHandler("ScrollPosChange","ProcScrollPosChange");
	DelEventHandler("evntUpdateFormtText","procFTUpdate");
	DelEventHandler("ScrollTopChange","ProcScrollChange");		// added after build 11 by KAM
	DelEventHandler("changeshow","ChangeShowAbil");				// added by Levis
	DelEventHandler("pressdown","GoToPerksWindow"); 			//added by Levis

	//Levis make sure the contriblist is updated:
	if(CheckAttribute(refUsedCharacter,"ContribList")) DeleteAttribute(refUsedCharacter,"ContribList"));
	
	interfaceResultCommand = exitCode;
// MAXIMUS interface MOD -->
	if(CheckAttribute(MainChar,"CharacterInterface_ViewEncOfficer") || CheckAttribute(MainChar,"AnyCharacterShow"))
	{
	    PostEvent("LaunchIAfterFrame",1,"sl", "I_OFFICER", 1);
	    EndCancelInterface(false);
	}
	else
	{
	    PostEvent("LaunchIAfterFrame",1,"sl", "I_CHARACTER", 1);
	    EndCancelInterface(false);
	}
	/*
	if( CheckAttribute(&InterfaceStates,"InstantExit") && sti(InterfaceStates.InstantExit)==true )
	{
		EndCancelInterface(true);
	}
	else
	{
		PostEvent("LaunchIAfterFrame",1,"sl", "I_CHARACTER", 1);
		EndCancelInterface(false);
	}*/
// MAXIMUS interface MOD <--
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	switch(nodName)
	{
	case "OK_BUTTON":
		if(comName=="deactivate")
		{	ReturnToPerksView();
		}
		if(comName=="activate" || comName=="click")
		{	SetPerkToCharacter();
			ReturnToPerksView();
		}
	break;

	case "CANCEL_BUTTON":
		if(comName=="deactivate" || comName=="activate" || comName=="click")	{ReturnToPerksView();}
		if(comName=="leftstep")
		{	if(GetSelectable("OK_BUTTON"))
			{	SetCurrentNode("OK_BUTTON");
			}
		}
	break;
	}
}

void SetAbilitesList()
{
	//First removed the old list:
	SendMessage(&GameInterface,"lss",MSG_INTERFACE_SET_FORMATEDTEXT,"PERKSWINDOW","");
	if(CheckAttribute(GameInterface,"perklist")) DeleteAttribute(GameInterface,"perklist");
	if(CheckAttribute(refUsedCharacter,"ContribList")) DeleteAttribute(refUsedCharacter,"ContribList"));
	
	//Make the new list
	int perksQ,i;
	string tmpStr,perkName;
	aref arPerksRoot,arChrPerk;

	chrPerksQ = 0;
	perksQ = 0;
	// perks that you can add
	makearef(arPerksRoot,ChrPerksList.list);
	perksQ = GetAttributesNum(arPerksRoot);
	bool show = true;
	int skipped = 0;
	for(i=0; i<perksQ; i++)
	{
		show = true;
		perkName = GetAttributeName(GetAttributeN(arPerksRoot,i));
		if(ShowAssignableOnly && !isPerkAssignable(refUsedCharacter, perkName, sti(refUsedCharacter.perks.FreePoints)) && !CheckPerkForSingleCharacter(refUsedCharacter, perkName))
		{
			show = false;
		}
		//Check if this perk can be selected for the officer
		if(!isOfficerPerk(refUsedCharacter, perkName))
		{
			if(SHOW_NON_CONTRIB_PERK>0)
			{
				show = false;
			}
			else
			{
				if(!IsCompanion(refUsedCharacter)) show = false;
			}
		}
		if(show && CheckPerkAvailable(perkName))
		{
			tmpStr = "perk"+chrPerksQ;
			GameInterface.perklist.(tmpStr) = perkName;
			tmpStr = LanguageConvertString(lngFileID,perkName);
			if(tmpStr!="") SendMessage(&GameInterface,"lsle",MSG_INTERFACE_MSG_TO_NODE,"PERKSWINDOW", 0,&tmpStr);
			chrPerksQ++;
		}
		else
		{
			if(CheckPerkAvailable(perkName))
			{
				skipped++;
			}
		}
	}
	
	//Show the non_contributing perks
	if(skipped>0 && SHOW_NON_CONTRIB_PERK > 0 && !ShowAssignableOnly)
	{
		SendMessage(&GameInterface,"lsle",MSG_INTERFACE_MSG_TO_NODE,"PERKSWINDOW", 0,"NON CONTRIBUTING PERKS");
		chrPerksQ++;
		
		for(i=0; i<perksQ; i++)
		{
			show = true;
			perkName = GetAttributeName(GetAttributeN(arPerksRoot,i));
			if(ShowAssignableOnly && !isPerkAssignable(refUsedCharacter, perkName, sti(refUsedCharacter.perks.FreePoints)) && !CheckPerkForSingleCharacter(refUsedCharacter, perkName))
			{
				show = false;
			}
			//Check if this perk can be selected for the officer
			if(!isOfficerPerk(refUsedCharacter, perkName))
			{
				show = false;
			}
			if(!show && CheckPerkAvailable(perkName))
			{
				tmpStr = "perk"+chrPerksQ;
				GameInterface.perklist.(tmpStr) = perkName;
				tmpStr = LanguageConvertString(lngFileID,perkName);
				if(tmpStr!="") SendMessage(&GameInterface,"lsle",MSG_INTERFACE_MSG_TO_NODE,"PERKSWINDOW", 0,&tmpStr);
				chrPerksQ++;
			}
		}
	}

	// perks that are available to us Removed by Levis because this is done differently now.
	/*makearef(arPerksRoot,refUsedCharacter.Perks.list);
	perksQ = GetAttributesNum(arPerksRoot);
	for(i=0; i<perksQ; i++)
	{
		perkName = GetAttributeName(GetAttributeN(arPerksRoot,i));
		if(CheckPerkAvailable(perkName))
		{
			tmpStr = "perk"+chrPerksQ;
			GameInterface.perklist.(tmpStr) = perkName;
			tmpStr = LanguageConvertString(lngFileID,perkName);
			if(tmpStr=="") {tmpStr=" ";}
			SendMessage(&GameInterface,"lsle",MSG_INTERFACE_MSG_TO_NODE,"PERKSWINDOW", 0,&tmpStr);
			chrPerksQ++;
		}
	}*/

	GameInterface.strings.FreeAbilities = GetFreeAbilitiesStr();

	Event("evntUpdateFormtText","sll","PERKSWINDOW",0,0);
}

void procFTActivate()
{
	string nodName = GetEventData();
	int texNum = GetEventData();

	if(nodName != "PERKSWINDOW")
		return;
	if(CheckAttribute(MainChar,"CharacterInterface_ViewEncOfficer") || CheckAttribute(MainChar,"AnyCharacterShow"))
		return;
	strPerkName = GetPerkName(texNum);
	if(strPerkName == "")
		return;
	
	DoViewDescribe(); //Levis every check happens in here now
}

void procFTSetScrollPos()
{
	string nodName = GetEventData();
	float fpos = GetEventData();

	if(nodName!="PERKSWINDOW") return;
	SendMessage(&GameInterface,"lsf",MSG_INTERFACE_SET_SCROLLER,"SCROLL",fpos);
}

void ProcScrollPosChange()
{
	float posinwindows = GetEventData();
	SendMessage(&GameInterface,"lslf",MSG_INTERFACE_MSG_TO_NODE,"PERKSWINDOW",2, posinwindows);
}

string GetPerkName(int perkNum)
{
	string tmpstr = "perk"+perkNum;
	if(CheckAttribute(&GameInterface,"perklist."+tmpstr)) {
		return GameInterface.perklist.(tmpstr);
	}
	return "";
}

void DoViewDescribe()
{
	SetNodeUsing("DESCRIBEWINDOW",true);
	SetNodeUsing("PERK_NAME",true);
	SetNodeUsing("PERK_IMAGE",true);
	SetNodeUsing("OK_BUTTON",true);
	SetNodeUsing("CANCEL_BUTTON",true);
	SetNodeUsing("DESCRIBE_RECT",true);

	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "DESCRIBEWINDOW");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "OK_BUTTON");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "CANCEL_BUTTON");

	//Levis add perk cost -->
	int cost = GetPerkCost(strPerkName);
	string namestring = LanguageConvertString(lngFileID, strPerkName);
	if (cost==1) { namestring = namestring+" ("+GetPerkCost(strPerkName)+" Point)"; } 
	else { namestring = namestring+" ("+GetPerkCost(strPerkName)+" Points)"; }
	
	//<--Levis add perk cost
	SendMessage(&GameInterface,"lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE,"PERK_NAME",0,"PerkName", namestring, FONT_NORMAL,
		384,108, argb(255,255,255,255),0, SCRIPT_ALIGN_CENTER, true, 1.5, 420);
	SetNewPicture("PERK_IMAGE","interfaces\perks\128\\" + strPerkName + ".tga");

	aref perkARef; makearef(perkARef, ChrPerksList.list.(strPerkName).condition);
	perksIconsQ = GetAttributesNum(perkARef);
	string abilName;
	for(int i = 0; i < perksIconsQ; i++)
	{
		abilName = GetAttributeName(GetAttributeN(perkARef,i));
		SetNodeUsing("CONDITION_"+i, true);
		SetNodeUsing("PLUS_"+i, true);
		if(CheckPerkSimple(refUsedCharacter, abilName))
		{
			SetNewPicture("CONDITION_"+i, "interfaces\perks\64\\" + abilName + ".tga");
		}
		else
		{
			if(CheckCharacterPerkLocked(refUsedCharacter, abilName))
			{
				SetNewPicture("CONDITION_"+i, "interfaces\perks\64Forbidden\\" + abilName + ".tga");
			}
			else
			{
				if(SHOW_NON_CONTRIB_PERK>0)
				{
					SetNewPicture("CONDITION_"+i, "interfaces\perks\64Disable\\" + abilName + ".tga");
				}
				else
				{
					if(isOfficerPerk(refUsedCharacter, abilName)) //If you are a captain everything will be shown but the perks not for you are locked.
					{
						SetNewPicture("CONDITION_"+i, "interfaces\perks\64Disable\\" + abilName + ".tga");
					}
					else
					{
						SetNewPicture("CONDITION_"+i, "interfaces\perks\64Forbidden\\" + abilName + ".tga");
					}
				}
				SetNewPicture("CONDITION_"+i, "interfaces\perks\64Disable\\" + abilName + ".tga");
			}
		}
	}

	//Levis simplified the checking:
	MainChar = GetMainCharacter();
	int freeAbilities 0;
	if(CheckAttribute(refUsedCharacter, "perks.FreePoints") ) { freeAbilities = sti(refUsedCharacter.perks.FreePoints); }
	bool enableOK = isPerkAssignable(refUsedCharacter, strPerkName, freeAbilities);
	//If you are a captain everything will be shown but the perks not for you are locked.
	if(SHOW_NON_CONTRIB_PERK == 0 && !isOfficerPerk(refUsedCharacter, strPerkName)) enableOK = false;
    SetSelectable("OK_BUTTON", enableOk);
	SetCurrentNode("CANCEL_BUTTON");
	string Description = LanguageConvertString(lngFileID,ChrPerksList.list.(strPerkName).descr);
	//Levis Locked Perks -->
	if (CheckCharacterPerkLocked(refUsedCharacter, strPerkName))
	{
		if(GetDifficulty() < DIFFICULTY_SEADOG) Description = LanguageConvertString(lngFileID,ChrPerksList.list.(strPerkName).descr+"Locked"); // Hints only on Landlubber and Mariner
		if(Description == "" || GetDifficulty() >= DIFFICULTY_SEADOG)
		{
			Description = LanguageConvertString(lngFileID,"Locked") + " | " + LanguageConvertString(lngFileID,ChrPerksList.list.(strPerkName).descr);
		}
	}
	//<-- Levis Locked Perks
	//Add min level -Levis
	if(!CheckPerkRank(refUsedCharacter, strPerkName))
	{
		Description = Description + " Min Level: " + GetPerkRank(strPerkName));
	}
	//Check for captains
	if(!isOfficerPerk(refUsedCharacter, strPerkName))
	{
		if(SHOW_NON_CONTRIB_PERK>0)
		{
			Description = "This officer won't contribute this perk to the ship. " + Description;
		}
		else
		{
			Description = "You can't select this ability for this role";
		}
	}
	SetFormatedText("DESCRIBEWINDOW",Description);
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"DESCRIBEWINDOW", 5);
}

void ReturnToPerksView()
{
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);

	string tmpstr;
	for(int i=0; i<perksIconsQ; i++)
	{
		SetNodeUsing("CONDITION_"+i,false);
		SetNodeUsing("PLUS_"+i,false);
	}
	perksIconsQ = 0;

	SetNodeUsing("DESCRIBEWINDOW",false);
	SetNodeUsing("PERK_NAME",false);
	SetNodeUsing("PERK_IMAGE",false);
	SetNodeUsing("OK_BUTTON",false);
	SetNodeUsing("CANCEL_BUTTON",false);
	SetNodeUsing("DESCRIBE_RECT",false);

	SetCurrentNode("PERKSWINDOW");
}

void SetPerkToCharacter()
{
	if(strPerkName=="") return;
	refUsedCharacter.perks.list.(strPerkName) = true;
	refUsedCharacter.perks.FreePoints = sti(refUsedCharacter.perks.FreePoints) - GetPerkCost(strPerkName);
	Event("eSwitchPerks","l",sti(refUsedCharacter.index));
	DeleteAttribute(refUsedCharacter,"ContribList"); //added by Levis so the contriblist is updated.
	GameInterface.strings.FreeAbilities = GetFreeAbilitiesStr();
	Event("evntUpdateFormtText","sll","PERKSWINDOW",g_nGroup,g_nLine); //we use the function now to refresh it
	//Levis refresh if filter is on
	if(ShowAssignableOnly)
	{
		SetAbilitesList();
	}
	//Levis <--
}

void procFTUpdate()
{
	string nodName = GetEventData();
	if(nodName != "PERKSWINDOW") return;
	int grNum = GetEventData();
	int strNum = GetEventData();
	g_nGroup = grNum;
	g_nLine = strNum;

	object objPos;
	DeleteAttribute(&objPos, "");
	SendMessage(&GameInterface,"lsla",MSG_INTERFACE_MSG_TO_NODE,"PERKSWINDOW", 4, &objPos);

	string tmpstr;
	int imgQ = 0;
	int i,qn,topVal;
	int argbColor;
	int nPerkState; //0 is not chosen, 1 is chosen, 2 is locked 
	qn = GetAttributesNum(&objPos);
	
	//Levis add perk cost -->
	int freeAbilities = 0;
	if(CheckAttribute(refUsedCharacter,"perks.FreePoints") )
		freeAbilities = sti(refUsedCharacter.perks.FreePoints);
	// <-- Levis add perk cost
	
	for(i = 0; i < qn; i++)
	{
		nPerkState = 0;
		topVal = sti(GetAttributeValue(GetAttributeN(&objPos, i)) );
		if(topVal >= 0)
		{
			tmpstr = GetPerkName(grNum);
			SetNodeUsing("PERK_STATE_"+imgQ, false);
			if(CheckPerkForGroup(refUsedCharacter, tmpstr))
			{
				SetNodeUsing("PERK_STATE_"+imgQ, true);
			}
            if(CheckPerkSimple(refUsedCharacter, tmpstr))
			{
				argbColor = argb(255,128,128,128);
				tmpstr = "64\\"+tmpstr;
				nPerkState = 1;
				//SetNodeUsing("PERK_STATE_"+imgQ, true);
			}
			//Levis Locked Perks -->
			else 
			{
				//SetNodeUsing("PERK_STATE_"+imgQ, false);
				if(CheckCharacterPerkLocked(refUsedCharacter, tmpstr))
				{
					argbColor = argb(255,128,128,128);
					tmpstr = "64Forbidden\\"+tmpstr; //Levis Disable Perks
					nPerkState = 2;
				}
				//<-- Levis Locked Perks
				else 
				{
					if(SHOW_NON_CONTRIB_PERK>0)
					{
						argbColor = argb(255,128,128,128);
						tmpstr = "64Disable\\"+tmpstr;
						nPerkState = 0;
					}
					else
					{
						if(isOfficerPerk(refUsedCharacter, tmpstr)) //If you are a captain everything will be shown but the perks not for you are locked.
						{
							argbColor = argb(255,128,128,128);
							tmpstr = "64Disable\\"+tmpstr;
							nPerkState = 0;
						}
						else
						{
							argbColor = argb(255,128,128,128);
							tmpstr = "64Forbidden\\"+tmpstr; //Levis Disable Perks
							nPerkState = 2;
						}
					}
				}
			}
			//Levis add Perk Cost -->
			string costname = "PERK_COST_"+imgQ;
			int cost = GetPerkCost(GetPerkName(grNum));
			int color = COLOR_NORMAL;
			//if(freeAbilities>=cost && CheckCharacterPerkLocked(GetPerkName(grNum)) == false)
			if(isPerkAssignable(refUsedCharacter, GetPerkName(grNum), freeAbilities) && isOfficerPerk(refUsedCharacter, GetPerkName(grNum))) //Check for everything -Levis
			{
				color = COLOR_MONEY;
			}
			//Levis remove cost for obtained perks
			if(nPerkState == 1)
			{
				GameInterface.strings.(costname) = "";
			}
			else
			{
				GameInterface.strings.(costname) = cost;
				ChangeStringColor(costname,color);
			}
			//<-- Levis add Perk Cost
			//Set the image
			SetNodeUsing("PERK_ICON_"+imgQ,true);
			//SetNodeUsing("PERK_STATE_"+imgQ, nPerkState==0); //Changed by Levis for Locked Perks
			SetNewPicture("PERK_ICON_"+imgQ,"interfaces\perks\\" + tmpstr + ".tga");
			SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE,"PERK_ICON_"+imgQ, 4,argbColor);
			imgQ++;
		}
		grNum++;
	}

	for(i=imgQ; i<imageQuantity; i++)
	{
		SetNodeUsing("PERK_ICON_"+i,false);
		string attrname = "PERK_COST_"+i;
		GameInterface.strings.(attrname) = ""; //Added by Levis
		SetNodeUsing("PERK_STATE_"+i,false);
	}
	imageQuantity = imgQ;
}

string GetFreeAbilitiesStr()
{
	int freeAbilities = 0;
	string text = "";
	if( CheckAttribute(refUsedCharacter,"perks.FreePoints") ) freeAbilities = sti(refUsedCharacter.perks.FreePoints);
	text = XI_ConvertString("Free points for abilitys") + ": " + freeAbilities;
	return text;
}

//added after build 11 by KAM -->
void ProcScrollChange()
{
	int changeNum = GetEventData();
	if(changeNum==0) return;
	if(changeNum>0) {
		SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"PERKSWINDOW",-1, 0,ACTION_DOWNSTEP);
	} else {
		SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"PERKSWINDOW",-1, 0,ACTION_UPSTEP);
	}
}
//<-- added after build 11 by KAM

//Added by Levis:
void ChangeShowAbil()
{
	if(ShowAssignableOnly)
	{
		ShowAssignableOnly = false;
		SetNodeUsing("SHOWFILTER", true); //Levis
		SetNodeUsing("SHOWABILITIES", false); //Levis
	}
	else
	{
		ShowAssignableOnly = true;
		SetNodeUsing("SHOWFILTER", false); //Levis
		SetNodeUsing("SHOWABILITIES", true); //Levis
	}
	SetAbilitesList();
	SetCurrentNode("PERKSWINDOW");
}

void GoToPerksWindow()
{
	SetCurrentNode("PERKSWINDOW");
}