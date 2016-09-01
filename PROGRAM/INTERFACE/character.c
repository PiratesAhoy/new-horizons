string sPlayerName;
string oldCurNode; // NK

int nPlayerMoney;
int nPlayerLand; // RM
int nNextExperience;
int nCurrentExperience;
int nFreeSkillPoints;

int nLeadership;
int nFencing;
int nSailing;
int nAccuracy;
int nCannons;
int nGrappling;
int nRepair;
int nDefence;
int nCommerce;
int nSneak;

bool bBeParty;
int curOfficer;
ref xi_refMainChar;
ref xi_refCharacter;

int oldIndex = -1;

int ListMax;						// added after build 11 by KAM
ref MainChar;						// added after build 11 by KAM
string skillAttr;

void InitInterface_R(string iniName,ref pCharacter)
{
	if(AUTO_SKILL_SYSTEM)
		skillAttr = "SkillChanger1";
	else
		skillAttr = "SkillChanger";

	int i;
//	curOfficer = 0;
	MainChar = GetMainCharacter();			// added after build 11 by KAM
	FillCharactersList(pCharacter);			// added after build 11 by KAM

// KK -->
	InitToolTip();
	ChangeDefaultToolTipNode(TOOLTIP_RECTANGLE, "TOOLTIP_RECT");
	ChangeDefaultToolTipNode(TOOLTIP_PICTURE, "TOOLTIP_PICT");
	AddToolTipNode(TOOLTIP_RECTANGLE, "TOOLTIP_RECT2");
	AddToolTipNode(TOOLTIP_PICTURE, "TOOLTIP_PICT2");
	AddToolTipNode(TOOLTIP_HEADER, "TOOLTIP_HEADER2");
	AddToolTipNode(TOOLTIP_TEXT, "TOOLTIP_TEXT2");
	AddToolTipPictureImageGroup("ICONS");
	SetToolTip();
// <-- KK

//View Enc Officer Mod: Taghmon

	xi_refMainChar = GetMainCharacter();
	xi_refCharacter = pCharacter;

	// changed after build 11 by KAM -->
	/*
	// Aconcagua: there is now an own interface for this,
	// so the attribute is not used any more...
	if (sti(pCharacter.index) != GetMainCharacterIndex())
	{
		if(CheckAttribute(MainChar,"CharacterInterface_ViewEncOfficer"))
		{
			GameInterface.View_Enc_Officer = "1";
			FillCharactersList_EncOfficerOnly(pCharacter);
		}
	}
	*/
	// <-- changed after build 11 by KAM


//View Enc Officer Mod End

	//AddCharacterExp(xi_refCharacter,0);

	//GameInterface.title = "titleCharacter";// MAXIMUS - will be displayed officertype or prison-status or something, defined in GameInterface.strings.OfficerType
    GameInterface.(skillAttr).current = 0;

    GameInterface.StatusLine.EXP.Max = CalculateExperienceFromRank(sti(xi_refCharacter.rank)+1);
    GameInterface.StatusLine.EXP.Min = CalculateExperienceFromRank(sti(xi_refCharacter.rank));
    GameInterface.StatusLine.EXP.Value = sti(xi_refCharacter.Experience);

// MAXIMUS interface MOD -->
	GameInterface.renamebox.strdata = "";
	GameInterface.renamebox.maxlen = 32;
	GameInterface.renamebox.maxwidth = 320;
// MAXIMUS interface MOD <--

	if( CheckAttribute(&InterfaceStack,"CharacterView_pos") ) GameInterface.(skillAttr).current = InterfaceStack.CharacterView_pos;
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	SetNodeUsing("LEFTCHANGE_CHARACTER",GetPassengersQuantity(GetMainCharacter())>0 || GetCompanionQuantity(GetMainCharacter())>1 || Listmax >1 ); // Screwface : For Shoreleave captains
	SetNodeUsing("RIGHTCHANGE_CHARACTER",GetPassengersQuantity(GetMainCharacter())>0 || GetCompanionQuantity(GetMainCharacter())>1 || Listmax >1 ); // Screwface : For Shoreleave captains

	bBeParty = true;
	
	// MAXIMUS interface MOD -->
	SetNodeUsing("RENAMEBOX",false);
	SetNodeUsing("B_CHARNAME",false);
	SetNodeUsing("BOX",false);
// MAXIMUS interface MOD <--

	CreateExitString();
	CreateString(true,"CurrentExperience","",FONT_NORMAL,COLOR_NORMAL,175,379,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"NextExperience","",FONT_NORMAL,COLOR_NORMAL,175,410,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"Money","",FONT_NORMAL,COLOR_MONEY,175,441,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"Land","",FONT_NORMAL,COLOR_NORMAL,175,471,SCRIPT_ALIGN_CENTER,1.0); // GreatZen
	CreateString(true,"CharacterName","",FONT_SEADOGS,COLOR_NORMAL,156,50,SCRIPT_ALIGN_CENTER,1.0); // KK
	CreateString(true,"Reputation","",FONT_NORMAL,COLOR_NORMAL,156,80,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"FreeAbilitiesPoints","",FONT_BOLD_NUMBERS,COLOR_NORMAL,444,396,SCRIPT_ALIGN_RIGHT,1.0);
	// MAXIMUS [new skill-change] -->
	CreateString(!AUTO_SKILL_SYSTEM,"FreeSkillPoints","",FONT_BOLD_NUMBERS,COLOR_NORMAL,610,396,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(!AUTO_SKILL_SYSTEM,"FreeSkill",XI_ConvertString("Free Skill Points"),FONT_NORMAL,COLOR_NORMAL,460,401,SCRIPT_ALIGN_LEFT,1.0);

	SetNodeUsing("SKILLCHANGER",!AUTO_SKILL_SYSTEM);
	SetNodeUsing("SKILLCHANGER1",AUTO_SKILL_SYSTEM);
	
	SetNodeUsing("B_SKILLUP",!AUTO_SKILL_SYSTEM);
	if(!AUTO_SKILL_SYSTEM) { CreateImage("FREESKILL","ICONS","black rectangle",454,396,616,428); }
	// MAXIMUS [new skill-change] -->

	CreateString(true,"Rank","",FONT_BOLD_NUMBERS,COLOR_NORMAL,268,324,SCRIPT_ALIGN_RIGHT,1.0);
// MAXIMUS interface MOD -->
//	CreateString(true,"Salary","",FONT_NORMAL,COLOR_MONEY,470,470,SCRIPT_ALIGN_LEFT,1.0); // NK // moved by MAXIMUS to void SetVariable()

    CreateString(true,"OfficerType","",FONT_NORMAL,COLOR_MONEY,300,470,SCRIPT_ALIGN_LEFT,1.0);
// MAXIMUS interface MOD <--

	// NK switch to using actual skill names -->
	CreateString(true,SKILL_LEADERSHIP,"",FONT_BOLD_NUMBERS,COLOR_NORMAL,517,46,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,SKILL_FENCING,"",FONT_BOLD_NUMBERS,COLOR_NORMAL,517,80,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,SKILL_SAILING,"",FONT_BOLD_NUMBERS,COLOR_NORMAL,517,114,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,SKILL_ACCURACY,"",FONT_BOLD_NUMBERS,COLOR_NORMAL,517,148,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,SKILL_CANNONS,"",FONT_BOLD_NUMBERS,COLOR_NORMAL,517,182,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,SKILL_GRAPPLING,"",FONT_BOLD_NUMBERS,COLOR_NORMAL,517,216,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,SKILL_REPAIR,"",FONT_BOLD_NUMBERS,COLOR_NORMAL,517,250,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,SKILL_DEFENCE,"",FONT_BOLD_NUMBERS,COLOR_NORMAL,517,284,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,SKILL_COMMERCE,"",FONT_BOLD_NUMBERS,COLOR_NORMAL,517,318,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,SKILL_SNEAK,"",FONT_BOLD_NUMBERS,COLOR_NORMAL,517,352,SCRIPT_ALIGN_CENTER,1.0);
	
	//Levis let's seperate the two values in different strings so we can manipulate them easier
	CreateString(true,SKILL_LEADERSHIP+"_SEP","",FONT_BOLD_NUMBERS,COLOR_NORMAL,562,46,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,SKILL_FENCING+"_SEP","",FONT_BOLD_NUMBERS,COLOR_NORMAL,562,80,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,SKILL_SAILING+"_SEP","",FONT_BOLD_NUMBERS,COLOR_NORMAL,562,114,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,SKILL_ACCURACY+"_SEP","",FONT_BOLD_NUMBERS,COLOR_NORMAL,562,148,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,SKILL_CANNONS+"_SEP","",FONT_BOLD_NUMBERS,COLOR_NORMAL,562,182,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,SKILL_GRAPPLING+"_SEP","",FONT_BOLD_NUMBERS,COLOR_NORMAL,562,216,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,SKILL_REPAIR+"_SEP","",FONT_BOLD_NUMBERS,COLOR_NORMAL,562,250,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,SKILL_DEFENCE+"_SEP","",FONT_BOLD_NUMBERS,COLOR_NORMAL,562,284,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,SKILL_COMMERCE+"_SEP","",FONT_BOLD_NUMBERS,COLOR_NORMAL,562,318,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,SKILL_SNEAK+"_SEP","",FONT_BOLD_NUMBERS,COLOR_NORMAL,562,352,SCRIPT_ALIGN_RIGHT,1.0);
	
	CreateString(true,SKILL_LEADERSHIP+"_MOD","",FONT_BOLD_NUMBERS,COLOR_NORMAL,572,46,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,SKILL_FENCING+"_MOD","",FONT_BOLD_NUMBERS,COLOR_NORMAL,572,80,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,SKILL_SAILING+"_MOD","",FONT_BOLD_NUMBERS,COLOR_NORMAL,572,114,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,SKILL_ACCURACY+"_MOD","",FONT_BOLD_NUMBERS,COLOR_NORMAL,572,148,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,SKILL_CANNONS+"_MOD","",FONT_BOLD_NUMBERS,COLOR_NORMAL,572,182,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,SKILL_GRAPPLING+"_MOD","",FONT_BOLD_NUMBERS,COLOR_NORMAL,572,216,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,SKILL_REPAIR+"_MOD","",FONT_BOLD_NUMBERS,COLOR_NORMAL,572,250,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,SKILL_DEFENCE+"_MOD","",FONT_BOLD_NUMBERS,COLOR_NORMAL,572,284,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,SKILL_COMMERCE+"_MOD","",FONT_BOLD_NUMBERS,COLOR_NORMAL,572,318,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,SKILL_SNEAK+"_MOD","",FONT_BOLD_NUMBERS,COLOR_NORMAL,572,352,SCRIPT_ALIGN_CENTER,1.0);
	// NK <--
// added by MAXIMUS [new skill-change] -->
	if(AUTO_SKILL_SYSTEM)
	{
		int curY = 54;
		for(int c = 0; c < 10; c++)
		{		
			string curSkill = GetSkillName(c);
			if(CheckAttribute(xi_refCharacter,"skill."+curSkill))
			{
				string skillPercent = curSkill+"_Percent";
				CreateString(true,skillPercent,"",FONT_NORMAL,COLOR_MONEY,475,curY,SCRIPT_ALIGN_LEFT,0.8);
				if(CheckAttribute(xi_refCharacter,"skill."+curSkill+".bonus") && stf(xi_refCharacter.skill.(curSkill).bonus)>1.0) { CreateImage("Bonus"+curSkill,"icons","complete",590,curY-10,620,curY+20); }
				curY = curY + 34;
			}
		}
		SetCurrentNode("SKILLCHANGER1");

		SetNodeUsing("ALEADERSHIP", true);
		SetNodeUsing("AFENCING", true);
		SetNodeUsing("ASAILING", true);
		SetNodeUsing("AACCURACY", true);
		SetNodeUsing("ACANNONS", true);
		SetNodeUsing("AGRAPPLING", true);
		SetNodeUsing("AREPAIR", true);
		SetNodeUsing("ADEFENCE", true);
		SetNodeUsing("ACOMMERCE", true);
		SetNodeUsing("ASNEAK", true);

	}
	else { SetCurrentNode("SKILLCHANGER"); }
// added by MAXIMUS [new skill-change] <--
// KK -->
	CreateString(true,"MaxHP","",FONT_BOLD_NUMBERS,COLOR_NORMAL,62,332,SCRIPT_ALIGN_LEFT,0.6);
	SetNodeUsing("MAXSHIPCLASSIMAGES", EnableLimitedShipClass());
	CreateString(EnableLimitedShipClass(), "MaxShipClass", "", FONT_BOLD_NUMBERS, COLOR_NORMAL, 192, 332, SCRIPT_ALIGN_LEFT, 0.6);
// <-- KK

	SetVariable();

// KK -->
	bool hasShip = false;
	for (i = 0; i < COMPANION_MAX; i++) {
		int cidx = GetCompanionIndex(MainChar, i);
		if (cidx < 0) continue;
		if (GetCharacterShipType(GetCharacter(cidx)) != SHIP_NOTUSED) {
			hasShip = true;
			break;
		}
	}
	SetSelectable("I_SHIPHOLD",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm() && hasShip);
	if (hasShip == false && GetBerthedShipsQuantityForTown(GetTownIDFromLocID(MainChar.location)) > 0) {
		hasShip = true;
		GameInterface.GoDirectToShipBerthing = true;
		SendMessage(&GameInterface, "lsls", MSG_INTERFACE_MSG_TO_NODE, "I_SHIP", 0, XI_ConvertString("Sel Berth"));
	}
// <-- KK

// MAXIMUS interface MOD -->
	SetSelectable("I_SHIP", !LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm() && hasShip); // KK
	// KK SetSelectable("I_NATIONS",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	SetSelectable("I_TRADEBOOK",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	// PB SetSelectable("I_QUESTBOOK",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	SetSelectable("I_SHIPLOG",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());	
	SetSelectable("RENAMEBOX",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	SetNodeUsing("B_CHARNAME",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	SetSelectable("B_CHARNAME",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	SetSelectable("EXIT_BUTTON",true);
// MAXIMUS interface MOD <--

// LDH change -->
	SetSelectable("EXCHANGE_ITEMS", !LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm() && !IsMainCharacter(xi_refCharacter) && !CheckAttribute(xi_refCharacter,"prisoned") && !IsTrader(xi_refCharacter)); // grey out button
	SetSelectable("CHANGE_OUTFIT", !LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm() && !CheckAttribute(MainChar, "DisableModelSelect") && !CheckAttribute(xi_refCharacter,"prisoned") && !IsTrader(xi_refCharacter) && !CheckAttribute(xi_refCharacter, "model.old")); // grey out button
// LDH <--

	if(CheckAttribute(GetMainCharacter(),"Interface.Fellow")) { DeleteAttribute(GetMainCharacter(),"Interface.Fellow"); }//MAXIMUS: identifier for items-interface [player can manually equip his officers]

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("InterfaceCancel","ProcessCancelExit",0); // MAXIMUS interface MOD
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
	SetEventHandler("frame","ProcessFrame",1);
// MAXIMUS interface MOD -->
	SetEventHandler("NodeOk","ProcessNodeOk",0);
	SetEventHandler("NodeCancel","ProcessNodeCancel",0);
	SetEventHandler("CharNameChange","ProcessCharNameChange",0);
// MAXIMUS interface MOD <--
// KK -->
	SetEventHandler("UpPress", "UpProcess", 0);
	SetEventHandler("DownPress", "DownProcess", 0);
	SetEventHandler("LeftPress", "LeftProcess", 0);
	SetEventHandler("RightPress", "RightProcess", 0);
// <-- KK

	SetEventHandler("KB_End","WriteName",0); // NK 05-07-21 keyboard
	SetEventHandler("KB_Update", "UpdateName", 0); // NK 05-07-21 keyboard

	SetEventHandler("SetB_CHARNAMEevent", "SetB_CHARNAME",0);		// LDH
}

// added after build 11 by KAM -->

void SetNextParty(bool bRight)
{
	string tempstring;
	int tempidx;

	if (bRight)
	{
		curOfficer++;
		if (curOfficer > ListMax) { curOfficer = 1; }
	}
	else
	{
		curOfficer--;
		if (curOfficer < 1) { curOfficer = ListMax; }
	}

	tempstring = "member" + curOfficer;
	tempidx = sti(MainChar.tempCharactersList.(tempstring).idx);
	xi_refCharacter = GetCharacter(tempidx);
	//AddCharacterExp(xi_refCharacter,0);

// LDH change -[changed by MAXIMUS]->
	if(IsMainCharacter(xi_refCharacter) || CheckAttribute(xi_refCharacter,"prisoned"))	// LDH When you cycle through characters
	{
		if(CheckAttribute(GetMainCharacter(),"Interface.Fellow")) { DeleteAttribute(GetMainCharacter(),"Interface.Fellow"); }//MAXIMUS: identifier for items-interface [player can manually equip his officers]
	}
	else
	{
		characters[GetMainCharacterIndex()].Interface.Fellow = xi_refCharacter.id;//MAXIMUS: identifier for items-interface [player can manually equip his officers]
	}
	SetSelectable("EXCHANGE_ITEMS", !LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm() && !IsMainCharacter(xi_refCharacter) && !CheckAttribute(xi_refCharacter,"prisoned") && !IsTrader(xi_refCharacter)); // grey out button
	SetSelectable("CHANGE_OUTFIT", !LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm() && !CheckAttribute(MainChar, "DisableModelSelect") && !CheckAttribute(xi_refCharacter,"prisoned") && !IsTrader(xi_refCharacter) && !CheckAttribute(xi_refCharacter, "model.old")); // grey out button
// LDH <-[changed by MAXIMUS]-
}

void FillCharactersList(ref ViewingCharacter)
{
	int tempnum1;
	int tempnum2;
	int tempnum3;
	int tempnum4;
	int tempnum5;
	ref tempchar;
	string tempstring1;
	string tempstring2;
	string tempstring3;

	If (CheckAttribute(MainChar,"tempCharactersList"))
	{
		DeleteAttribute(MainChar,"tempCharactersList");
		if (TRACELOG == 1) { Trace("deleted existing list"); }
	}

	ListMax = 1;



	// ******* STEP 1/5: ADD MAIN CHARACTER *******

	MainChar.tempCharactersList.member1.idx = sti(MainChar.index);
	if (TRACELOG == 1) { Trace("added mainchar"); }
	ListMax++;



	// ******* STEP 2/5: ADD OFFICERS *******

	for (tempnum1 = 1; tempnum1 < OFFICER_MAX; tempnum1++)
	{
		tempnum2 = GetOfficersIndex(MainChar,tempnum1);
		if (tempnum2 >= 0)
		{
			tempstring1 = "member" + ListMax;
			MainChar.tempCharactersList.(tempstring1).idx = tempnum2;
			if (TRACELOG == 1) { Trace("added list member " + ListMax + ": idx " + tempnum2 + " type 1"); }
			ListMax++;
		}
	}



	// ******* STEP 3/5: ADD COMPANIONS AND THEIR OFFICERS *******

	for (tempnum1 = 1; tempnum1 < COMPANION_MAX; tempnum1++)
	{
		tempnum2 = GetCompanionIndex(MainChar,tempnum1);
		if (tempnum2 >= 0)
		{
			tempstring1 = "member" + ListMax;
			MainChar.tempCharactersList.(tempstring1).idx = tempnum2;
			if (TRACELOG == 1) { Trace("added list member " + ListMax + ": idx " + tempnum2 + " type 2"); }
			ListMax++;

			tempchar = GetCharacter(tempnum2);
			for (tempnum3 = 1; tempnum3 < OFFICER_MAX; tempnum3++)
			{
				tempnum4 = GetOfficersIndex(tempchar,tempnum3);
				if (TRACELOG == 1) { Trace("checking officer " + tempnum3 + ", idx " + tempnum4 + ", of companion " + tempnum1 + ", idx " + tempnum2); }
				if (tempnum4 >= 0)
				{
					tempstring1 = "member" + ListMax;
					MainChar.tempCharactersList.(tempstring1).idx = tempnum4;
					if (TRACELOG == 1) { Trace("added list member " + ListMax + ": idx " + tempnum4 + " type 3"); }
					ListMax++;
				}
			}
		}
	}



	// ******* STEP 4/5: ADD NON-OFFICER PASSENGERS *******

	for (tempnum1 = 0; tempnum1 < GetPassengersQuantity(MainChar); tempnum1++)
	{
		tempnum2 = GetPassenger(MainChar,tempnum1);
		if (tempnum2 >= 0)
		{
			tempchar = GetCharacter(tempnum2);
			if (!IsOfficer(tempchar) && !IsCompanion(tempchar))
			{
				tempstring1 = "member" + ListMax;
				MainChar.tempCharactersList.(tempstring1).idx = tempnum2;
				if (TRACELOG == 1) { Trace("added list member " + ListMax + ": idx " + tempnum2 + " type 4"); }
				ListMax++;
			}
		}
	}



	// ******* STEP 5/5: ADD CAPTAINS ON SHORE LEAVE AND THEIR OFFICERS *******

	for (tempnum1 = 0; tempnum1 < TOWNS_QUANTITY; tempnum1++) // Screwface
	{
		tempstring1 = "port" + tempnum1;
		for (tempnum2 = 1; tempnum2 < 5; tempnum2++)
		{
			tempstring2 = "slot" + tempnum2;
			if (CheckAttribute(MainChar,"ShipBerthing."+(tempstring1)+"."+(tempstring2)) && sti(MainChar.ShipBerthing.(tempstring1).(tempstring2).status) == 2)
			{
				tempnum3 = sti(MainChar.ShipBerthing.(tempstring1).(tempstring2).captainindex);
				tempstring3 = "member" + ListMax;
				MainChar.tempCharactersList.(tempstring3).idx = tempnum3;
				if (TRACELOG == 1) { Trace("added list member " + ListMax + ": idx " + tempnum3 + " type 5"); }
				ListMax++;

				tempchar = GetCharacter(tempnum3);
				for (tempnum4 = 1; tempnum4 < OFFICER_MAX; tempnum4++)
				{
					tempnum5 = GetOfficersIndex(tempchar,tempnum4);
					if (TRACELOG == 1) { Trace("checking officer " + tempnum4 + ", idx " + tempnum5 + ", of shore leave captain idx " + tempnum3); }
					if (tempnum5 >= 0)
					{
						tempstring1 = "member" + ListMax;
						MainChar.tempCharactersList.(tempstring1).idx = tempnum5;
						if (TRACELOG == 1) { Trace("added list member " + ListMax + ": idx " + tempnum5 + " type 6"); }
						ListMax++;
					}
				}
			}
		}
	}

	ListMax--;
	if (TRACELOG == 1) { Trace("list total: " + ListMax); }
	curOfficer = 1;
	xi_refCharacter = GetMainCharacter();

	tempnum3 = sti(ViewingCharacter.index);
	for (tempnum1 = 1; tempnum1 <= ListMax; tempnum1++)
	{
		tempstring1 = "member" + tempnum1;
		tempnum2 = sti(MainChar.tempCharactersList.(tempstring1).idx);
		if (tempnum2 == tempnum3)
		{
			curOfficer = tempnum1;
			xi_refCharacter = GetCharacter(tempnum2);
		}
	}

	//AddCharacterExp(xi_refCharacter,0);
}

// <-- added after build 11 by KAM

// MAXIMUS interface MOD -->
void ProcessNodeOk()
{
	string nodName = GetEventData();
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
	if( CheckAttribute(&GameInterface,nodName+".strdata") )
	{
		string str = GameInterface.(nodName).strdata;
		SetCurrentNode("B_CHARNAME");
		SetCharacterName(xi_refCharacter, str);
		GameInterface.strings.CharacterName = xi_refCharacter.name+" "+ stringRet(CheckAttribute(xi_refCharacter,"firstname"),xi_refCharacter.firstname + " ","") + stringRet(CheckAttribute(xi_refCharacter,"middlename"),xi_refCharacter.middlename + " ","") + xi_refCharacter.lastname; // KK
	}
	DeleteAttribute(&GameInterface,nodName+".strdata");
	SetNodeUsing("RENAMEBOX",false);
}

void ProcessNodeCancel()
{
	string nodName = GetEventData();
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
	DeleteAttribute(&GameInterface,nodName+".strdata");
	SetNodeUsing("renamebox",false);
}

void ProcessCharNameChange()
{
// NK 05-07-21 keyboard -->
	if (bRMouseDown) return; // KK
	bBeParty = false; // added by MAXIMUS
	SetSelectable("LEFTCHANGE_CHARACTER",false); // added by MAXIMUS
	SetSelectable("RIGHTCHANGE_CHARACTER",false); // added by MAXIMUS
	SetNodeUsing("BOX",true); // added by MAXIMUS
	SetCurrentNode("BOX"); // added by MAXIMUS
	KB_SetKeyboardMode(true);
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "BOX");	// LDH - disable mouse clicks during name change
	KB_Prepare(GameInterface.strings.CharacterName); // KK
}

void UpdateName()
{
	GameInterface.strings.CharacterName = KeyboardDisplayString; // KK
}

void WriteName()
{
// KK -->
	string namestr = "";
	if(KeyboardString != "")
	{
		SetCharacterName(xi_refCharacter, KeyboardString);
		namestr = xi_refCharacter.name + " ";
		if(CheckAttribute(xi_refCharacter,"firstname")) namestr += xi_refCharacter.firstname + " ";
		if(CheckAttribute(xi_refCharacter,"middlename")) namestr += xi_refCharacter.middlename + " ";
		namestr += xi_refCharacter.lastname;
		GameInterface.strings.CharacterName = namestr;
	}
// added by MAXIMUS for cancel possibility without changing name -->
	else
	{
		namestr = xi_refCharacter.name + " ";
		if(CheckAttribute(xi_refCharacter,"firstname")) namestr += xi_refCharacter.firstname + " ";
		if(CheckAttribute(xi_refCharacter,"middlename")) namestr += xi_refCharacter.middlename + " ";
		namestr += xi_refCharacter.lastname;
		GameInterface.strings.CharacterName = namestr;
		ProcessNodeCancel();
	}
// added by MAXIMUS for cancel possibility without changing name <--
// <-- KK
	SetNodeUsing("BOX",false); // added by MAXIMUS
	bBeParty = true; // added by MAXIMUS
	SetSelectable("LEFTCHANGE_CHARACTER",true); // added by MAXIMUS
	SetSelectable("RIGHTCHANGE_CHARACTER",true); // added by MAXIMUS
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);	// LDH - allows mouse clicks after name change
	// LDH Note:  There are still bugs while changing a name and hitting right arrow then up arrow, but no apparent harm done.
	// LDH Note:  These changes fix a bug where the Character Screen could be exited while typing in a new name.
	PostEvent("SetB_CHARNAMEevent",200);	// LDH - Set node and prevent command from being reexecuted immediately upon exit.

	// LDH 11Feb09
	if (bSeaActive)	SetSchemeForSea();
	else			SetSchemeForLocation(&locations[GetLocationIndex(MainChar.location)]);

}
// NK 05-07-21 keyboard <--

// MAXIMUS interface MOD <--

void SetVariable()
{
    sPlayerName = xi_refCharacter.name;

	nPlayerMoney = sti(xi_refCharacter.Money);
	if(CheckAttribute(xi_refCharacter, "wealth") && sti(xi_refCharacter.wealth) > 0) nPlayerMoney = sti(xi_refCharacter.wealth); // PB: Always show wealth if available
    nPlayerLand = GetCharacterLand(xi_refCharacter); // RM
    nCurrentExperience = sti(xi_refCharacter.Experience);
    nNextExperience = CalculateExperienceFromRank(sti(xi_refCharacter.rank)+1);
    nFreeSkillPoints = sti(xi_refCharacter.Skill.FreeSkill);
	int nFreeAbilities = 0;
	if( CheckAttribute(xi_refCharacter,"perks.FreePoints") )
		nFreeAbilities = sti(xi_refCharacter.perks.FreePoints);

    nLeadership = GetCharacterSkill(xi_refCharacter, SKILL_LEADERSHIP);
    nFencing    = GetCharacterSkill(xi_refCharacter, SKILL_FENCING);
    nSailing    = GetCharacterSkill(xi_refCharacter, SKILL_SAILING);
    nAccuracy   = GetCharacterSkill(xi_refCharacter, SKILL_ACCURACY);
    nCannons    = GetCharacterSkill(xi_refCharacter, SKILL_CANNONS);
    nGrappling  = GetCharacterSkill(xi_refCharacter, SKILL_GRAPPLING);
    nRepair     = GetCharacterSkill(xi_refCharacter, SKILL_REPAIR);
    nDefence    = GetCharacterSkill(xi_refCharacter, SKILL_DEFENCE);
    nCommerce   = GetCharacterSkill(xi_refCharacter, SKILL_COMMERCE);
    nSneak      = GetCharacterSkill(xi_refCharacter, SKILL_SNEAK);

    GameInterface.StatusLine.EXP.Max = nNextExperience;
    GameInterface.StatusLine.EXP.Min = CalculateExperienceFromRank(sti(xi_refCharacter.rank));
    GameInterface.StatusLine.EXP.Value = nCurrentExperience;

// added by MAXIMUS [new skill-change] -->
	if(AUTO_SKILL_SYSTEM)
	{
		int curY = 54;
		for(int c = 0; c < 10; c++)
		{		
			string curSkill = GetSkillName(c);
			if(CheckAttribute(xi_refCharacter,"skill."+curSkill))
			{
				int skillval = GetCharacterSkill(xi_refCharacter, curSkill);
				string skillPercent = curSkill+"_Percent";
				if(skillval == MAX_CHARACTER_SKILL || xi_refCharacter.skill.(curSkill) == 0) // MM 
				{
					DisableString(skillPercent);
				}
				else
				{
					EnableString(skillPercent);
					if(CheckAttribute(xi_refCharacter,"Experience."+curSkill))
					{
						AddXPtoSkill(xi_refCharacter, curSkill, 0); //Levis: incase a level is decreased or something like that we check the skill
						GameInterface.strings.(skillPercent) = makeint(stf(xi_refCharacter.Experience.(curSkill))/CalculateSkillExperienceFromRank(sti(xi_refCharacter.skill.(curSkill))+1)*100.0)+"%";
					}
					else
					{
						GameInterface.strings.(skillPercent) = 0+"%";
					}
				}
				if(CheckAttribute(xi_refCharacter,"skill."+curSkill+".bonus") && stf(xi_refCharacter.skill.(curSkill).bonus)>1.0 && sti(xi_refCharacter.skill.(curSkill))<10) { CreateImage("Bonus"+curSkill,"icons","complete",590,curY-10,620,curY+20); }
				else { CreateImage("Bonus"+curSkill,"","",590,curY-10,620,curY+20); }
				curY = curY + 34;
			}
		}
	}
// added by MAXIMUS [new skill-change] <--

    GameInterface.strings.CurrentExperience = nCurrentExperience;
    GameInterface.strings.NextExperience = nNextExperience;
    GameInterface.strings.Money = MakeMoneyShow(nPlayerMoney,MONEY_SIGN,MONEY_DELIVER);
	GameInterface.strings.Land = MakeMoneyShow(nPlayerLand,MONEY_SIGN,MONEY_DELIVER) + " " + XI_ConvertString("acr") + "."; // GreatZen
    // Scheffnow - bfd -->
    // GameInterface.strings.CharacterName = xi_refCharacter.name+" "+ stringRet(CheckAttribute(xi_refCharacter,"firstname"),xi_refCharacter.firstname + " ","") + xi_refCharacter.lastname; // RM
    // NK clean this up 05-07-21
	string namestr = "";
	if(CheckAttribute(xi_refCharacter,"name")) namestr = xi_refCharacter.name+" ";
	else namestr = "Anonymous ";
	if(CheckAttribute(xi_refCharacter,"firstname")) namestr += xi_refCharacter.firstname + " ";
	if(CheckAttribute(xi_refCharacter, "middlename")) namestr += xi_refCharacter.middlename + " ";
	if(CheckAttribute(xi_refCharacter,"lastname")) namestr += xi_refCharacter.lastname;
	else namestr += "Coward";
	GameInterface.strings.CharacterName = namestr;
    // Scheffnow - bfd <--
	GameInterface.strings.Reputation = GetTranslatedReputationForSex(xi_refCharacter, GetReputationName(GetCharacterReputation(xi_refCharacter)));
	if(IsPrisoner(xi_refCharacter)==true && CheckAttribute(xi_refCharacter,"quest.officertype"))
	{
		GameInterface.strings.Reputation = XI_ConvertString(xi_refCharacter.quest.officertype);
	}
	GameInterface.strings.FreeAbilitiesPoints = nFreeAbilities;
    GameInterface.strings.FreeSkillPoints = nFreeSkillPoints;
	if(DEBUG_EXPERIENCE>0)	GameInterface.strings.Rank = xi_refCharacter.rank+"-"+GetTotalRank(xi_refCharacter);
	else					GameInterface.strings.Rank = GetTotalRank(xi_refCharacter);
	// NK -->

// MAXIMUS interface MOD --> // KK -->
    SetSelectable("B_SKILLUP",!CheckAttribute(xi_refCharacter,"prisoned") && !IsTrader(xi_refCharacter) && !AUTO_SKILL_SYSTEM);
    SetSelectable("B_ABILITIES",!CheckAttribute(xi_refCharacter,"prisoned") && !IsTrader(xi_refCharacter));
    SetNodeUsing("B_CHARNAME",!CheckAttribute(xi_refCharacter,"prisoned") && !IsTrader(xi_refCharacter));
// MAXIMUS interface MOD <-- // <-- KK

	if(!IsMainCharacter(xi_refCharacter) && CheckAttribute(xi_refCharacter,"quest.officerprice")) // PB: Officer price doesn't make sense for player
	{
		CreateString(true,"Salary","",FONT_NORMAL,COLOR_MONEY,605,470,SCRIPT_ALIGN_RIGHT,1.0); // added by MAXIMUS
		if(CheckAttribute(xi_refCharacter,"prisoned") == true)
		{
			GameInterface.strings.Salary
			 = XI_ConvertString("Redemption") + ": "
			 + MakeMoneyShow(sti(GetPrisonRansomCost(xi_refCharacter)),MONEY_SIGN,MONEY_DELIVER);	// added by MAXIMUS
		}
		else
		{
			float baseSalary = sti(xi_refCharacter.quest.officerprice) * PayScaleFactor();
			if(IsCompanion(xi_refCharacter))
			{
			 GameInterface.strings.Salary
				= XI_ConvertString("MonthlySalary") + ": "
				+ MakeMoneyShow(sti(baseSalary * COMP_PRICE_SCALAR), MONEY_SIGN,MONEY_DELIVER);//JA 26Nov06 used to have this * 10?? 
			}
			else
			{
				if(CheckAttribute(xi_refCharacter, "quest.officertype"))
				{
				GameInterface.strings.Salary
					= XI_ConvertString("MonthlySalary") + ": "
					+ MakeMoneyShow(sti(baseSalary * OFF_PRICE_SCALAR),MONEY_SIGN,MONEY_DELIVER);//JA 26Nov06 used to have this * 10?? 
				}
				else
				{
				GameInterface.strings.Salary
					= XI_ConvertString("Inactive") + ": " 
					+ MakeMoneyShow(sti(baseSalary * PASSENGER_PRICE_SCALAR),MONEY_SIGN,MONEY_DELIVER);//JA 27Nov06
				}
			}
		}
	} else {
		CreateString(true,"Salary","",FONT_NORMAL,COLOR_MONEY,460,470,SCRIPT_ALIGN_LEFT,1.0); // added by MAXIMUS
		if(IsPrisoner(xi_refCharacter))
			GameInterface.strings.Salary = XI_ConvertString("Redemption") + ": " + MakeMoneyShow(sti(GetPrisonRansomCost(xi_refCharacter)),MONEY_SIGN,MONEY_DELIVER);  // added by MAXIMUS
		else
			CreateString(true,"Salary",XI_ConvertString("Cashdesk") + ": " + MakeMoneyShow(sti(xi_refCharacter.money),MONEY_SIGN,MONEY_DELIVER),FONT_NORMAL,COLOR_MONEY,605,470,SCRIPT_ALIGN_RIGHT,1.0);	// LDH change
	}
	// NK <--

	// El Rapido -->
	ResetMaxHP(xi_refCharacter);
	// El Rapido <--

	GameInterface.strings.MaxHP = MakeInt(LAi_GetCharacterHP(xi_refCharacter)) + "/" + MakeInt(LAi_GetCharacterMaxHP(xi_refCharacter));

	if (EnableLimitedShipClass()) GameInterface.strings.MaxShipClass = GetShipMinClassForCharacter(xi_refCharacter); // KK

	// NK switch to using actual skill names -->
	SetSkillShow(SKILL_LEADERSHIP,nLeadership);
	SetSkillShow(SKILL_FENCING,nFencing);
	SetSkillShow(SKILL_SAILING,nSailing);
	SetSkillShow(SKILL_ACCURACY,nAccuracy);
	SetSkillShow(SKILL_CANNONS,nCannons);
	SetSkillShow(SKILL_GRAPPLING,nGrappling);
	SetSkillShow(SKILL_REPAIR,nRepair);
	SetSkillShow(SKILL_DEFENCE,nDefence);
	SetSkillShow(SKILL_COMMERCE,nCommerce);
	SetSkillShow(SKILL_SNEAK,nSneak);
	// NK <--

	SetNewPicture("FACEPICT", "interfaces\portraits\256\face_" + xi_refCharacter.FaceId + ".tga");
  // Viper - CharSheetEnh Start
	SetNewPicture("TYPEPICT", "interfaces\crew.tga");
//	SetNewPicture("TYPEPICT1", "");//MAXIMUS: SetNewPicture with "" couses many traces into log-file and slows down an interface
	SetNodeUsing("TYPEPICT", xi_refCharacter.id!=xi_refMainChar.id);
	SetNodeUsing("TYPEPICT1",CheckAttribute(xi_refCharacter,"prisoned")==true);
//	if( xi_refCharacter.id == xi_refMainChar.id ) {
//		SetNewPicture("TYPEPICT", "");
//	} else {
	if ( IsCompanion(xi_refCharacter) ) SetNewPicture("TYPEPICT", "interfaces\blank_ship.tga");			// changed after build 11 by KAM
	if ( IsOfficer(xi_refCharacter) ) //SetNewPicture("TYPEPICT", "interfaces\kam_isofficer.tga");				// changed after build 11 by KAM
	{
		if(CheckAttribute(xi_refCharacter,"quest.officertype"))
		{
			switch (xi_refCharacter.quest.officertype)
			{
				// KK -->
				case OFFIC_TYPE_BOATSWAIN: SetNewPicture("TYPEPICT", "interfaces\order.tga"); break;
				case OFFIC_TYPE_ABORDAGE: SetNewPicture("TYPEPICT", "interfaces\fighter.tga"); break;
				case OFFIC_TYPE_RANDCHAR: SetNewPicture("TYPEPICT", "interfaces\fighter.tga"); break;
				case OFFIC_TYPE_CANNONEER: SetNewPicture("TYPEPICT", "interfaces\gunner.tga"); break;
				case OFFIC_TYPE_QMASTER: SetNewPicture("TYPEPICT", "interfaces\quartermaster.tga"); break;
				case OFFIC_TYPE_NAVIGATOR: SetNewPicture("TYPEPICT", "interfaces\navigator.tga"); break;
				case OFFIC_TYPE_FIRSTMATE: SetNewPicture("TYPEPICT", "interfaces\officer.tga"); break;
				case OFFIC_TYPE_CARPENTER: SetNewPicture("TYPEPICT", "interfaces\carpenter.tga"); break;
				case OFFIC_TYPE_DOCTOR: SetNewPicture("TYPEPICT", "interfaces\doctor.tga"); break;
				// <-- KK
			}
		}
	}
	if ( IsOfficerCompanion(xi_refCharacter) ) SetNewPicture("TYPEPICT", "interfaces\kam_isofficercompanion.tga");		// changed after build 11 by KAM
	if ( IsOnShoreLeave(xi_refCharacter) ) SetNewPicture("TYPEPICT", "interfaces\kam_isonshoreleave.tga");			// added after build 11 by KAM
	if ( IsOfficerOnShoreLeave(xi_refCharacter) ) SetNewPicture("TYPEPICT", "interfaces\kam_isofficeronshoreleave.tga");	// added after build 11 by KAM
	if ( IsPrisoner(xi_refCharacter) ) // KK
	{
		SetNewPicture("TYPEPICT", "interfaces\isprisoned.tga");  // added by MAXIMUS
		if(CheckAttribute(xi_refCharacter,"quest.officertype"))  // added by MAXIMUS
		{
			switch (xi_refCharacter.quest.officertype)
			{
// KK -->
				case OFFIC_TYPE_BOATSWAIN: SetNewPicture("TYPEPICT1", "interfaces\order.tga"); break;
				case OFFIC_TYPE_ABORDAGE: SetNewPicture("TYPEPICT1", "interfaces\fighter.tga"); break;
				case OFFIC_TYPE_RANDCHAR: SetNewPicture("TYPEPICT1", "interfaces\fighter.tga"); break;
				case OFFIC_TYPE_CANNONEER: SetNewPicture("TYPEPICT1", "interfaces\gunner.tga"); break;
				case OFFIC_TYPE_QMASTER: SetNewPicture("TYPEPICT1", "interfaces\quartermaster.tga"); break;
				case OFFIC_TYPE_NAVIGATOR: SetNewPicture("TYPEPICT1", "interfaces\navigator.tga"); break;
				case OFFIC_TYPE_FIRSTMATE: SetNewPicture("TYPEPICT1", "interfaces\officer.tga"); break;
				case OFFIC_TYPE_CARPENTER: SetNewPicture("TYPEPICT1", "interfaces\carpenter.tga"); break;
				case OFFIC_TYPE_DOCTOR: SetNewPicture("TYPEPICT1", "interfaces\doctor.tga"); break;
				case OFFIC_TYPE_TRADER: SetNewPicture("TYPEPICT1", "interfaces\trader.tga"); break;
// <-- KK
			}
		}
	}
// Viper - CharSheetEnh End
	if (!CheckAttribute(GameInterface.strings,"OfficerType"))
	{
		// SUBTITLE: Officer type
		GameInterface.strings.OfficerType = XI_ConvertString(GetAttribute(xi_refCharacter, "quest.officertype"));

		// TITLE: Indicate character type/category
		if (IsMainCharacter(xi_refCharacter))
		{
			GameInterface.strings.fakeTitle 	= XI_ConvertString(GetPlayerType (xi_refCharacter));	// PB: Player Type can be overridden by titles
			GameInterface.strings.OfficerType	= XI_ConvertString(GetCaptainType(xi_refCharacter));	// PB: Indicate Captain Type as subtitle to ensure it ALWAYS displays
		}
		else
		{
			if (IsCompanion(xi_refCharacter))
			{
				if (IsTrader(xi_refCharacter))	GameInterface.strings.fakeTitle = XI_ConvertString("trader");
				else							GameInterface.strings.fakeTitle = XI_ConvertString("Companion");
			}
			else
			{
				if (IsPrisoner(xi_refCharacter)==true) { // KK
					if(xi_refCharacter.sex=="woman")
						GameInterface.strings.fakeTitle = XI_ConvertString("she_prisoned");  // added by MAXIMUS
					else
						GameInterface.strings.fakeTitle = XI_ConvertString("Captive");  // added by MAXIMUS
				} else {
					if(CheckAttribute(xi_refCharacter, "quest.officertype") && !CheckAttribute(xi_refCharacter, "quest.NoRaise"))
						GameInterface.strings.fakeTitle = XI_ConvertString("Officer");
					else
						GameInterface.strings.fakeTitle = XI_ConvertString("Passenger");
				}
			}
		}
	}

	// TITLE: Override with Rank if available
	int bestRank;
	int rankNation = GetBestRank(xi_refCharacter, &bestRank, rankNation); // add return by levis
	if (bestRank > 0 && !IsPrisoner(xi_refCharacter)) GameInterface.strings.fakeTitle = TranslateString("", GetRankNameDirect(xi_refCharacter, rankNation, bestrank)); //Fix by Levis

	CreateStringCheckCase(true,"fakeTitle",GameInterface.strings.fakeTitle,"interface_title",COLOR_NORMAL,320,5,SCRIPT_ALIGN_CENTER,1.0,true); // MAXIMUS interface MOD

	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"exp",0);
	oldIndex = -1;
}

void ProcessCancelExit()
{
	interfaceResultCommand = RC_INTERFACE_CHARACTER_EXIT;

	DeleteAttribute(MainChar,"tempCharactersList");			// added after build 11 by KAM
	// Aconcagua: own interface, see above
	//if(CheckAttribute(MainChar,"CharacterInterface_ViewEncOfficer")) { DeleteAttribute (MainChar,"CharacterInterface_ViewEncOfficer"); }
	CharInterfaceExit(true);
// MAXIMUS interface MOD <--
}

void CharInterfaceExit(bool flag)
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("InterfaceCancel","ProcessCancelExit"); // MAXIMUS interface MOD
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcessCommandExecute");
	DelEventHandler("frame","ProcessFrame");
// MAXIMUS interface MOD -->
	DelEventHandler("NodeOk","ProcessNodeOk");
	DelEventHandler("NodeCancel","ProcessNodeCancel");
	DelEventHandler("CharNameChange","ProcessCharNameChange");
// MAXIMUS interface MOD <--
// KK -->
	DelEventHandler("UpPress", "UpProcess");
	DelEventHandler("DownPress", "DownProcess");
	DelEventHandler("LeftPress", "LeftProcess");
	DelEventHandler("RightPress", "RightProcess");
// <-- KK

	DelEventHandler("KB_End","WriteName"); // NK 05-07-21 keyboard
	DelEventHandler("KB_Update", "UpdateName"); // NK 05-07-21 keyboard

	DelEventHandler("SetB_CHARNAMEevent", "SetB_CHARNAME");		// LDH

	EndCancelInterface(flag);
}

void IncreaseSkill()
{
	if(nFreeSkillPoints>0)
	{
		switch( sti(GameInterface.(skillAttr).current) )
		{
			// NK switch to using actual skill names -->
			// NK 04-09-08 added choice for whether to disable skillup if skill == 0
			case 1:
				if(nLeadership==0 && !ENABLE_SKILLUP_IFZERO)	{return;}
				if(nLeadership<MAX_CHARACTER_SKILL)
				{
					nLeadership++;
					IncreaseBaseSkill(xi_refCharacter, SKILL_LEADERSHIP, 1);
					SetSkillShow(SKILL_LEADERSHIP,nLeadership);
					SetNodeUsing("B_SKILLUP",nLeadership<MAX_CHARACTER_SKILL);
				}
				else return;
				break;

			case 2:
				if(nFencing==0 && !ENABLE_SKILLUP_IFZERO)	{return;}
				if(nFencing<MAX_CHARACTER_SKILL)
				{
					nFencing++;
					IncreaseBaseSkill(xi_refCharacter, SKILL_FENCING, 1);
					SetSkillShow(SKILL_FENCING,nFencing);
					SetNodeUsing("B_SKILLUP",nFencing<MAX_CHARACTER_SKILL);
				}
				else return;
				break;

			case 3:
				if(nSailing==0 && !ENABLE_SKILLUP_IFZERO)	{return;}
				if(nSailing<MAX_CHARACTER_SKILL)
				{
					nSailing++;
					IncreaseBaseSkill(xi_refCharacter, SKILL_SAILING, 1);
					SetSkillShow(SKILL_SAILING,nSailing);
					SetNodeUsing("B_SKILLUP",nSailing<MAX_CHARACTER_SKILL);
				}
				else return;
				break;

			case 4:
				if(nAccuracy==0 && !ENABLE_SKILLUP_IFZERO)	{return;}
				if(nAccuracy<MAX_CHARACTER_SKILL)
				{
					nAccuracy++;
					IncreaseBaseSkill(xi_refCharacter, SKILL_ACCURACY, 1);
					SetSkillShow(SKILL_ACCURACY,nAccuracy);
					SetNodeUsing("B_SKILLUP",nAccuracy<MAX_CHARACTER_SKILL);
				}
				else return;
				break;

			case 5:
				if(nCannons==0 && !ENABLE_SKILLUP_IFZERO)	{return;}
				if(nCannons<MAX_CHARACTER_SKILL)
				{
					nCannons++;
					IncreaseBaseSkill(xi_refCharacter, SKILL_CANNONS, 1);
					SetSkillShow(SKILL_CANNONS,nCannons);
					SetNodeUsing("B_SKILLUP",nCannons<MAX_CHARACTER_SKILL);
				}
				else return;
				break;

			case 6:
				if(nGrappling==0 && !ENABLE_SKILLUP_IFZERO)	{return;}
				if(nGrappling<MAX_CHARACTER_SKILL)
				{
					nGrappling++;
					IncreaseBaseSkill(xi_refCharacter, SKILL_GRAPPLING, 1);
					SetSkillShow(SKILL_GRAPPLING,nGrappling);
					SetNodeUsing("B_SKILLUP",nGrappling<MAX_CHARACTER_SKILL);
				}
				else return;
				break;

			case 7:
				if(nRepair==0 && !ENABLE_SKILLUP_IFZERO)	{return;}
				if(nRepair<MAX_CHARACTER_SKILL)
				{
					nRepair++;
					IncreaseBaseSkill(xi_refCharacter, SKILL_REPAIR, 1);
					SetSkillShow(SKILL_REPAIR,nRepair);
					SetNodeUsing("B_SKILLUP",nRepair<MAX_CHARACTER_SKILL);
				}
				else return;
				break;

			case 8:
				if(nDefence==0 && !ENABLE_SKILLUP_IFZERO)	{return;}
				if(nDefence<MAX_CHARACTER_SKILL)
				{
					nDefence++;
					IncreaseBaseSkill(xi_refCharacter, SKILL_DEFENCE, 1);
					SetSkillShow(SKILL_DEFENCE,nDefence);
					SetNodeUsing("B_SKILLUP",nDefence<MAX_CHARACTER_SKILL);
				}
				else return;
				break;

			case 9:
				if(nCommerce==0 && !ENABLE_SKILLUP_IFZERO)	{return;}
				if(nCommerce<MAX_CHARACTER_SKILL)
				{
					nCommerce++;
					IncreaseBaseSkill(xi_refCharacter, SKILL_COMMERCE, 1);
					SetSkillShow(SKILL_COMMERCE,nCommerce);
					SetNodeUsing("B_SKILLUP",nCommerce<MAX_CHARACTER_SKILL);
				}
				else return;
				break;

			case 10:
				if(nSneak==0 && !ENABLE_SKILLUP_IFZERO)	{return;}
				if(nSneak<MAX_CHARACTER_SKILL)
				{
					nSneak++;
					IncreaseBaseSkill(xi_refCharacter, SKILL_SNEAK, 1);
					SetSkillShow(SKILL_SNEAK,nSneak);
					SetNodeUsing("B_SKILLUP",nSneak<MAX_CHARACTER_SKILL);
				}
				else return;
				break;
			// NK <--
		}
		nFreeSkillPoints--;
		xi_refCharacter.Skill.FreeSkill = nFreeSkillPoints;
		GameInterface.strings.FreeSkillPoints = nFreeSkillPoints;
		ResetEffectiveSkill(xi_refCharacter, GetSkillName(sti(GameInterface.(skillAttr).current))); //Added by Levis so with no auto_skill this is also called
	}
}

int SetAlphaIntoColor(int col, int alpha)
{
	int newCol = and(col,16777215) + shl(alpha,24);
	return newCol;
}

int GetAlphaFromSkill(int nskill)
{
   return makeint(255-(MAX_CHARACTER_SKILL-nskill)*20*(10/MAX_CHARACTER_SKILL));
}

void SetSkillShow(string skillName, int skillVal)
{
	int modval = CalcCharacterSkill(&xi_refCharacter,skillName);
	int baseval = GetCharacterBaseSkill(&xi_refCharacter,skillName);
	int color = COLOR_NORMAL;
	
	//GameInterface.strings.(skillName) = skillVal + " - " + CalcCharacterSkill(&xi_refCharacter,skillName); // NK
	//Levis -->
	string stringname = skillName;
	GameInterface.strings.(stringname) = skillVal;
	if(skillVal < baseval) color = COLOR_RED;
	if(skillVal > baseval) color = COLOR_GREEN;
	if(skillVal==MAX_CHARACTER_SKILL)	color = COLOR_MONEY;
	ChangeStringColor(stringname,SetAlphaIntoColor(color,GetAlphaFromSkill(skillVal)));
	
	color = COLOR_NORMAL;
	stringname = skillName+"_SEP";
	GameInterface.strings.(stringname) = " - ";
	ChangeStringColor(stringname,SetAlphaIntoColor(COLOR_MONEY,GetAlphaFromSkill(1)));
	
	stringname = skillName+"_MOD";
	GameInterface.strings.(stringname) = modval;
	if(modval==MAX_CHARACTER_SKILL)	color = COLOR_MONEY;
	if(modval > skillVal)	color = COLOR_GREEN;
	if(modval < skillVal)	color = COLOR_RED;
	ChangeStringColor(stringname,SetAlphaIntoColor(color,GetAlphaFromSkill(modval)));
	//Levis <--
	/*int color = COLOR_NORMAL;
	if(skillVal==MAX_CHARACTER_SKILL)	color = COLOR_MONEY;
	ChangeStringColor(skillName,SetAlphaIntoColor(color,GetAlphaFromSkill(skillVal)));*/
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	if (bRMouseDown) {
		if (comName != "click") return;

		ShowInfo(nodName);
		return;
	}

	int curChanger = 11;
	if(AUTO_SKILL_SYSTEM) { curChanger = 1; }
	if(nodName=="SKILLCHANGER1") nodName = "SKILLCHANGER";
// MAXIMUS interface MOD -->
	int x;ref tmpch;string tmpstr;

	switch(nodName)
	{
	case "I_SHIP":
		if(comName=="activate" || comName=="click")
		{
			if (CheckAttribute(xi_refMainChar, "Interface.Fellow")) {
				DeleteAttribute(xi_refMainChar, "Interface.Fellow");
			}//MAXIMUS: identifier for items-interface [player can manually equip his officers]
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_CHARACTER_EXIT;
			CharInterfaceExit(false);
		}
		break;
	case "I_SHIPHOLD":
		if(comName=="activate" || comName=="click")
		{
			if(CheckAttribute(GetMainCharacter(),"Interface.Fellow")) { DeleteAttribute(GetMainCharacter(),"Interface.Fellow"); }//MAXIMUS: identifier for items-interface [player can manually equip his officers]
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_CHARACTER_EXIT;
			CharInterfaceExit(false);
		}
		break;
	case "I_PASSENGER":
		if(comName=="activate" || comName=="click")
		{
			if(CheckAttribute(GetMainCharacter(),"Interface.Fellow")) { DeleteAttribute(GetMainCharacter(),"Interface.Fellow"); }//MAXIMUS: identifier for items-interface [player can manually equip his officers]
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_CHARACTER_EXIT;
			CharInterfaceExit(false);
		}
		break;
	case "I_QUESTBOOK":
		if(comName=="activate" || comName=="click")
		{
			if(CheckAttribute(GetMainCharacter(),"Interface.Fellow")) { DeleteAttribute(GetMainCharacter(),"Interface.Fellow"); }//MAXIMUS: identifier for items-interface [player can manually equip his officers]
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_CHARACTER_EXIT;
			CharInterfaceExit(false);
		}
		break;
	case "I_TRADEBOOK":
		if(comName=="activate" || comName=="click")
		{
			if(CheckAttribute(GetMainCharacter(),"Interface.Fellow")) { DeleteAttribute(GetMainCharacter(),"Interface.Fellow"); }//MAXIMUS: identifier for items-interface [player can manually equip his officers]
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_CHARACTER_EXIT;
			CharInterfaceExit(false);
		}
		break;
	case "I_SHIPLOG":
		if(comName=="activate" || comName=="click")
		{
			if(CheckAttribute(GetMainCharacter(),"Interface.Fellow")) { DeleteAttribute(GetMainCharacter(),"Interface.Fellow"); }//MAXIMUS: identifier for items-interface [player can manually equip his officers]
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_CHARACTER_EXIT;
			CharInterfaceExit(false);
		}
		break;
	case "I_NATIONS":
		if(comName=="activate" || comName=="click")
		{
			if(CheckAttribute(GetMainCharacter(),"Interface.Fellow")) { DeleteAttribute(GetMainCharacter(),"Interface.Fellow"); }//MAXIMUS: identifier for items-interface [player can manually equip his officers]
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_CHARACTER_EXIT;
			CharInterfaceExit(false);
		}
		break;
	case "I_ITEMS":
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_CHARACTER_EXIT;
			CharInterfaceExit(false);
		}
		break;
		// MAXIMUS interface MOD <--

	case "LEFTCHANGE_CHARACTER":
		if(comName=="click")
		{
			if(bBeParty)
			{
				SetNextParty(false);
				SetVariable();
			}
		}
		break;

	case "RIGHTCHANGE_CHARACTER":
		if(comName=="click")
		{
			if(bBeParty)
			{
				SetNextParty(true);
				SetVariable();
			}
		}
		break;

	case "SKILLCHANGER":
		if (CheckAttribute(xi_refCharacter,"prisoned") || IsTrader(xi_refCharacter)) return; // KK
		if(sti(GameInterface.(skillAttr).current)==0)
		{
			if(comName=="rightstep" && bBeParty)
			{
				SetNextParty(true);
				SetVariable();
			}
			if(comName=="leftstep" && bBeParty)
			{
				SetNextParty(false);
				SetVariable();
			}
		}
		else
		{
			if(sti(GameInterface.(skillAttr).current)==curChanger)//11 - MAXIMUS [new skill-change]
			{
				if(comName=="activate")
				{
					GameInterface.AbilityChr = xi_refCharacter.index;
					PostEvent("LaunchIAfterFrame",1,"sl", "AbilityView", 1);
					interfaceResultCommand = RC_INTERFACE_CHARACTER_EXIT;
					CharInterfaceExit(false);
					return;
				}
			}
			else
			{
				if(comName=="activate")
				{
					IncreaseSkill();
				}
			}
		}
		break;

	case "B_SKILLUP":
		if(comName=="click")
		{
			// added after build 11 by KAM -->
			/*
			// Aconcagua: own interface, see above
			if(!CheckAttribute(MainChar,"CharacterInterface_ViewEncOfficer"))
			{
			*/
			// <-- added after build 11 by KAM

			if(sti(GameInterface.(skillAttr).current)<curChanger)//11 - MAXIMUS [new skill-change]
			{
				IncreaseSkill();
				oldIndex = -1;
			}
			
			// added after build 11 by KAM -->
			/*
			  }
			  // <-- added after build 11 by KAM
			  */
		}
		break;

	case "B_ABILITIES":
		if(comName=="click")
		{
			if (CheckAttribute(xi_refCharacter,"prisoned") || IsTrader(xi_refCharacter)) return; // KK
			SetCurrentNode("B_ABILITIES");
			GameInterface.AbilityChr = xi_refCharacter.index;
			PostEvent("LaunchIAfterFrame",1,"sl", "AbilityView", 1);
			interfaceResultCommand = RC_INTERFACE_CHARACTER_EXIT;
			CharInterfaceExit(false);
			return;
		}
		break;

		// added by KAM after build 11 -->
	case "CHANGE_OUTFIT":
		if(comName=="click" && !CheckAttribute(MainChar, "DisableModelSelect")) // NK to disable model select in tut 05-07-14
		{
			MainChar.ChangeOutfitFromCharacterScreen = xi_refCharacter.index;
			PostEvent("LaunchIAfterFrame",1,"sl", "ChangeOutfit", 1);
			interfaceResultCommand = RC_INTERFACE_CHARACTER_EXIT;
			CharInterfaceExit(false);
			return;
		}
		break;
		// <-- added by KAM after build 11

		// added by LDH -->
	case "EXCHANGE_ITEMS":
		if(comName=="click")
		{
			MainChar.ExchangeItemsFromCharacterScreen = xi_refCharacter.index;
			PostEvent("LaunchIAfterFrame",1,"sl", "ExchangeItems", 1);
			interfaceResultCommand = RC_INTERFACE_CHARACTER_EXIT;
			CharInterfaceExit(false);
			return;
		}
		break;

	case "B_CHARNAME":
		if(comName=="deactivate")
		{
			if(AUTO_SKILL_SYSTEM) SetCurrentNode("SKILLCHANGER1");
			else SetCurrentNode("SKILLCHANGER");
		}
		break;
		// <-- added by LDH
	}
}

void ProcessFrame()
{
	if (!bRMouseDown) HideToolTip(); // KK

	if(oldCurNode!=GetCurrentNode())
	{		
// MAXIMUS interface MOD -->
		switch(oldCurNode)
		{
		case "RENAMEBOX":	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0); break;
		}
		oldCurNode=GetCurrentNode();
		SetNodeUsing("B_CHARNAME",true);
	}
// MAXIMUS interface MOD <--
	int newIndex = sti(GameInterface.(skillAttr).current);
	int curChanger = 11;
	if(AUTO_SKILL_SYSTEM) { curChanger = 1; }
	if(oldIndex!=newIndex)
	{
		bool bSetBtn = false;
		oldIndex = newIndex;
		if(newIndex>0)
		{
			if(nFreeSkillPoints>0)
			{
				// NK 04-09-08 added choice for whether to disable skillup if skill == 0 -->
				//(added this 04-09-19. Sorry I missed it before
				if(ENABLE_SKILLUP_IFZERO)
				{
					switch(newIndex)
					{
					case 1:		if(nLeadership<MAX_CHARACTER_SKILL){bSetBtn=true;}	break;
					case 2:		if(nFencing<MAX_CHARACTER_SKILL)		{bSetBtn=true;}	break;
					case 3:		if(nSailing<MAX_CHARACTER_SKILL)		{bSetBtn=true;}	break;
					case 4:		if(nAccuracy<MAX_CHARACTER_SKILL)	{bSetBtn=true;}	break;
					case 5:		if(nCannons<MAX_CHARACTER_SKILL)		{bSetBtn=true;}	break;
					case 6:		if(nGrappling<MAX_CHARACTER_SKILL)	{bSetBtn=true;}	break;
					case 7:		if(nRepair<MAX_CHARACTER_SKILL)		{bSetBtn=true;}	break;
					case 8:		if(nDefence<MAX_CHARACTER_SKILL)		{bSetBtn=true;}	break;
					case 9:		if(nCommerce<MAX_CHARACTER_SKILL)	{bSetBtn=true;}	break;
					case 10:	if(nSneak<MAX_CHARACTER_SKILL)			{bSetBtn=true;}	break;
					}
				}else {
				switch(newIndex)
					{
					case 1:		if(nLeadership>0 && nLeadership<MAX_CHARACTER_SKILL){bSetBtn=true;}	break;
					case 2:		if(nFencing>0 && nFencing<MAX_CHARACTER_SKILL)		{bSetBtn=true;}	break;
					case 3:		if(nSailing>0 && nSailing<MAX_CHARACTER_SKILL)		{bSetBtn=true;}	break;
					case 4:		if(nAccuracy>0 && nAccuracy<MAX_CHARACTER_SKILL)	{bSetBtn=true;}	break;
					case 5:		if(nCannons>0 && nCannons<MAX_CHARACTER_SKILL)		{bSetBtn=true;}	break;
					case 6:		if(nGrappling>0 && nGrappling<MAX_CHARACTER_SKILL)	{bSetBtn=true;}	break;
					case 7:		if(nRepair>0 && nRepair<MAX_CHARACTER_SKILL)		{bSetBtn=true;}	break;
					case 8:		if(nDefence>0 && nDefence<MAX_CHARACTER_SKILL)		{bSetBtn=true;}	break;
					case 9:		if(nCommerce>0 && nCommerce<MAX_CHARACTER_SKILL)	{bSetBtn=true;}	break;
					case 10:	if(nSneak>0 && nSneak<MAX_CHARACTER_SKILL)			{bSetBtn=true;}	break;
					}
				}
				// NK <--
			}
			if(bSetBtn)
			{
				int pic_top = 12 + 34*newIndex;
				int pic_bottom = 44 + 34*newIndex;
				SendMessage(&GameInterface,"lsllllll", MSG_INTERFACE_MSG_TO_NODE,"B_SKILLUP",0, 478,pic_top,510,pic_bottom, 0); // NK was 528,560
			}
		}
		SetNodeUsing("B_ABILITIES",newIndex==curChanger);//11 - MAXIMUS [new skill-change]
		SetNodeUsing("B_SKILLUP",bSetBtn && !AUTO_SKILL_SYSTEM);
	}
}

	/* BEGIN MOD : Stone-D 27/07/2003 */
void EnhancedSetNextParty(bool bRight)
{
	int i,cn;
	int CmpQ = GetCompanionQuantity(xi_refMainChar)-1;
	int PsgQ = GetPassengersQuantity(xi_refMainChar);
	int PrtQ = makeint(CmpQ+PsgQ);

	if(bRight) { curOfficer++; }
	else { curOfficer--; }

	if(curOfficer>PrtQ) curOfficer=0;
	if(curOfficer<0) curOfficer=PrtQ;

	if(curOfficer<=CmpQ) { cn = GetCompanionIndex(xi_refMainChar,curOfficer); } // Captains & Quest characters
	else { cn = GetPassenger(xi_refMainChar,curOfficer-(CmpQ+1)); } // Officers & Passengers

	if(curOfficer!=0) { xi_refCharacter = GetCharacter(cn); }
	else { xi_refCharacter = xi_refMainChar; }
	//AddCharacterExp(xi_refCharacter,0);
}
	/* END MOD : Stone-D 27/07/2003 */

// LDH added event handler to fix timing problems on setting this node.
void SetB_CHARNAME()
{
	SetCurrentNode("B_CHARNAME");
}

// KK -->
void UpProcess()
{
	string tmp = NextUp(GetCurrentNode());
	SetCurrentNode(tmp);
}

void DownProcess()
{
	string tmp = NextDown(GetCurrentNode());
	SetCurrentNode(tmp);
}

void LeftProcess()
{
	string tmp = NextLeft(GetCurrentNode());
	SetCurrentNode(tmp);
}

void RightProcess()
{
	string tmp = NextRight(GetCurrentNode());
	SetCurrentNode(tmp);
}

string NextDown(string curNod)
{
	if (CheckAttribute(xi_refCharacter,"prisoned") || IsTrader(xi_refCharacter)) return " "; // KK
	switch(curNod)
	{
		case "I_SHIP":
			if (GetSelectable("B_CHARNAME")) return "B_CHARNAME"; else return NextDown("B_CHARNAME");
		break;
		case "I_SHIPHOLD":
			if (GetSelectable("B_CHARNAME")) return "B_CHARNAME"; else return NextDown("B_CHARNAME");
		break;
		case "I_PASSENGER":
			if (GetSelectable("B_CHARNAME")) return "B_CHARNAME"; else return NextDown("B_CHARNAME");
		break;
		case "I_QUESTBOOK":
			if (GetSelectable("B_CHARNAME")) return "B_CHARNAME"; else return NextDown("B_CHARNAME");
		break;
		case "I_TRADEBOOK":
			if (GetSelectable("B_CHARNAME")) return "B_CHARNAME"; else return NextDown("B_CHARNAME");
		break;
		case "I_SHIPLOG":
			if (GetSelectable("B_CHARNAME")) return "B_CHARNAME"; else return NextDown("B_CHARNAME");
		break;
		case "I_NATIONS":
			if (GetSelectable("B_CHARNAME")) return "B_CHARNAME"; else return NextDown("B_CHARNAME");
		break;
		case "I_ITEMS":
			if (GetSelectable("B_CHARNAME")) return "B_CHARNAME"; else return NextDown("B_CHARNAME");
		break;
		case "B_CHARNAME":
			if (GetSelectable("B_ABILITIES")) return "B_ABILITIES"; else return NextDown("B_ABILITIES");
		break;
		case "B_ABILITIES":
			if (GetSelectable("CHANGE_OUTFIT")) return "CHANGE_OUTFIT"; else return NextDown("CHANGE_OUTFIT");
		break;
		case "CHANGE_OUTFIT":
			if (GetSelectable("B_CHARNAME")) return "B_CHARNAME"; else return NextDown("B_CHARNAME");
		break;
	}
	return " ";
}

string NextUp(string curNod)
{
	if (CheckAttribute(xi_refCharacter,"prisoned") || IsTrader(xi_refCharacter)) return " "; // KK
	switch(curNod)
	{
		case "I_SHIP":
			if (GetSelectable("CHANGE_OUTFIT")) return "CHANGE_OUTFIT"; else return NextUp("CHANGE_OUTFIT");
		break;
		case "I_SHIPHOLD":
			if (GetSelectable("CHANGE_OUTFIT")) return "CHANGE_OUTFIT"; else return NextUp("CHANGE_OUTFIT");
		break;
		case "I_PASSENGER":
			if (GetSelectable("CHANGE_OUTFIT")) return "CHANGE_OUTFIT"; else return NextUp("CHANGE_OUTFIT");
		break;
		case "I_QUESTBOOK":
			if (GetSelectable("CHANGE_OUTFIT")) return "CHANGE_OUTFIT"; else return NextUp("CHANGE_OUTFIT");
		break;
		case "I_TRADEBOOK":
			if (GetSelectable("CHANGE_OUTFIT")) return "CHANGE_OUTFIT"; else return NextUp("CHANGE_OUTFIT");
		break;
		case "I_SHIPLOG":
			if (GetSelectable("CHANGE_OUTFIT")) return "CHANGE_OUTFIT"; else return NextUp("CHANGE_OUTFIT");
		break;
		case "I_NATIONS":
			if (GetSelectable("CHANGE_OUTFIT")) return "CHANGE_OUTFIT"; else return NextUp("CHANGE_OUTFIT");
		break;
		case "I_ITEMS":
			if (GetSelectable("CHANGE_OUTFIT")) return "CHANGE_OUTFIT"; else return NextUp("CHANGE_OUTFIT");
		break;
		case "B_CHARNAME":
			if (GetSelectable("CHANGE_OUTFIT")) return "CHANGE_OUTFIT"; else return NextUp("CHANGE_OUTFIT");
		break;
		case "B_ABILITIES":
			if (GetSelectable("B_CHARNAME")) return "B_CHARNAME"; else return NextUp("B_CHARNAME");
		break;
		case "CHANGE_OUTFIT":
			if (GetSelectable("B_ABILITIES")) return "B_ABILITIES"; else return NextUp("B_ABILITIES");
		break;
	}
	return " ";
}

string NextLeft(string curNod)
{
	switch (curNod)
	{
		case "I_SHIP":
			if (GetSelectable("I_ITEMS")) return "I_ITEMS"; else return NextLeft("I_ITEMS");
		break;
		case "I_SHIPHOLD":
			if (GetSelectable("I_SHIP")) return "I_SHIP"; else return NextLeft("I_SHIP");
		break;
		case "I_PASSENGER":
			if (GetSelectable("I_SHIPHOLD")) return "I_SHIPHOLD"; else return NextLeft("I_SHIPHOLD");
		break;
		case "I_QUESTBOOK":
			if (GetSelectable("I_PASSENGER")) return "I_PASSENGER"; else return NextLeft("I_PASSENGER");
		break;
		case "I_TRADEBOOK":
			if (GetSelectable("I_QUESTBOOK")) return "I_QUESTBOOK"; else return NextLeft("I_QUESTBOOK");
		break;
		case "I_SHIPLOG":
			if (GetSelectable("I_TRADEBOOK")) return "I_TRADEBOOK"; else return NextLeft("I_TRADEBOOK");
		break;
		case "I_NATIONS":
			if (GetSelectable("I_SHIPLOG")) return "I_SHIPLOG"; else return NextLeft("I_SHIPLOG");
		break;
		case "I_ITEMS":
			if (GetSelectable("I_NATIONS")) return "I_NATIONS"; else return NextLeft("I_NATIONS");
		break;
		case "CHANGE_OUTFIT":
			if (GetSelectable("EXCHANGE_ITEMS")) return "EXCHANGE_ITEMS"; else return NextLeft("EXCHANGE_ITEMS");
		break;
		case "EXCHANGE_ITEMS":
			if (GetSelectable("CHANGE_OUTFIT")) return "CHANGE_OUTFIT"; else return NextLeft("CHANGE_OUTFIT");
		break;
	}
	return " ";
}

string NextRight(string curNod)
{
	switch (curNod)
	{
		case "I_SHIP":
			if (GetSelectable("I_SHIPHOLD")) return "I_SHIPHOLD"; else return NextLeft("I_SHIPHOLD");
		break;
		case "I_SHIPHOLD":
			if (GetSelectable("I_PASSENGER")) return "I_PASSENGER"; else return NextLeft("I_PASSENGER");
		break;
		case "I_PASSENGER":
			if (GetSelectable("I_QUESTBOOK")) return "I_QUESTBOOK"; else return NextLeft("I_QUESTBOOK");
		break;
		case "I_QUESTBOOK":
			if (GetSelectable("I_TRADEBOOK")) return "I_TRADEBOOK"; else return NextLeft("I_TRADEBOOK");
		break;
		case "I_TRADEBOOK":
			if (GetSelectable("I_SHIPLOG")) return "I_SHIPLOG"; else return NextLeft("I_SHIPLOG");
		break;
		case "I_SHIPLOG":
			if (GetSelectable("I_NATIONS")) return "I_NATIONS"; else return NextLeft("I_NATIONS");
		break;
		case "I_NATIONS":
			if (GetSelectable("I_ITEMS")) return "I_ITEMS"; else return NextLeft("I_ITEMS");
		break;
		case "I_ITEMS":
			if (GetSelectable("I_SHIP")) return "I_SHIP"; else return NextLeft("I_SHIP");
		break;
		case "CHANGE_OUTFIT":
			if (GetSelectable("EXCHANGE_ITEMS")) return "EXCHANGE_ITEMS"; else return NextRight("EXCHANGE_ITEMS");
		break;
		case "EXCHANGE_ITEMS":
			if (GetSelectable("CHANGE_OUTFIT")) return "CHANGE_OUTFIT"; else return NextRight("CHANGE_OUTFIT");
		break;
	}
	return " ";
}

void ShowInfo(string nodeName)
{
	if(nodeName == "SKILLCHANGER")
	{
		bool isBreak = true;
		switch(sti(GameInterface.(skillAttr).current))
		{
		case 1:
			nodeName = "ALEADERSHIP";
			isBreak = false;
			break;
		case 2:
			nodeName = "AFENCING";
			isBreak = false;
			break;
		case 3:
			nodeName = "ASAILING";
			isBreak = false;
			break;
		case 4:
			nodeName = "AACCURACY";
			isBreak = false;
			break;
		case 5:
			nodeName = "ACANNONS";
			isBreak = false;
			break;
		case 6:
			nodeName = "AGRAPPLING";
			isBreak = false;
			break;
		case 7:
			nodeName = "AREPAIR";
			isBreak = false;
			break;
		case 8:
			nodeName = "ADEFENCE";
			isBreak = false;
			break;
		case 9:
			nodeName = "ACOMMERCE";
			isBreak = false;
			break;
		case 10:
			nodeName = "ASNEAK";
			isBreak = false;
			break;
		}
	}
	string header = "";
	string text = "";
	string img = "";
	int ilngid = LanguageOpenFile("InterfaceDescribe.txt");
	header = LanguageConvertString(ilngid, nodeName + "_Header");
	text = LanguageConvertString(ilngid, nodeName + "_Descr");
	img = LanguageConvertString(ilngid, nodeName + "_Img");
	LanguageCloseFile(ilngid);
	if (header == "" && text == "") return;
	switch (nodeName) {
		case "AFACEPICT":
			SetToolTipRectangle("TOOLTIP_RECT2");
			SetToolTipHeader("TOOLTIP_HEADER2", GetMyFullName(xi_refCharacter));
			Preprocessor_Add("name", GetMyFullName(xi_refCharacter));
			SetToolTipText("TOOLTIP_TEXT2", PreprocessText(text));
			Preprocessor_Remove("name");
			SetToolTipImage("TOOLTIP_PICT2", "interfaces\portraits\256\face_" + xi_refCharacter.FaceId + ".tga");
		break;
		// default:
			SetToolTipRectangle("");
			SetToolTipHeader("", header);
			SetToolTipText("", text);
			SetToolTipPicture("", "ICONS", img);
	}
	ShowToolTip();
}
// <-- KK
