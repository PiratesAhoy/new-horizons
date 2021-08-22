#define NONEFACE_TEXTURE_NAME "interfaces\empty_face.tga"

ref refMyCharacter;
ref refEnemyCharacter;
int nCompanionIndex;

ref MainChar;					// added after build 11 by KAM

int nMyCharacterCompanionPlace;

int curScrollNum;
int nFourImageNum;

string oldCurNode;

void InitInterface_RR(string iniName,ref myCh,ref enemyCh)
{
	MainChar = GetMainCharacter();		// added after build 11 by KAM

	int i;

	refMyCharacter = myCh;
	refEnemyCharacter = enemyCh;
	nMyCharacterCompanionPlace = -1;
	if(CheckAttribute(myCh,"InterfaceParam.i1")) {
		nMyCharacterCompanionPlace = sti(myCh.InterfaceParam.i1);
	} else {
		interfaceResultCommand = RC_INTERFACE_TRANSFER_MAIN_RETURN;
		EndCancelInterface(true);
		return;
	}
//    GameInterface.title = "titleTransferCharacters";
    GameInterface.title = "titleAssignOfficers";

	nCompanionIndex = GetCompanionIndex(refMyCharacter,nMyCharacterCompanionPlace);

	FillScroll();
	FillFourImages();

    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();//MAXIMUS: standard exit-string for exit-button
	oldCurNode = GetCurrentNode();

    CreateString(true,"CharacterName",XI_ConvertString("Noname"),FONT_NORMAL,COLOR_NORMAL,320,194,SCRIPT_ALIGN_CENTER,1.0);

    CreateString(true,"SkillLeadership","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,224,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"SkillFencing","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,258,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"SkillSailing","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,292,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"SkillAccuracy","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,326,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"SkillCannons","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,358,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"SkillGrappling","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,224,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"SkillRepair","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,258,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"SkillDefence","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,292,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"SkillCommerce","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,326,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(true,"SkillSneak","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,358,SCRIPT_ALIGN_RIGHT,1.0);

	CreateString(EnableLimitedShipClass(), "MaxShipClass", "", FONT_NORMAL, COLOR_NORMAL, 320, 435, SCRIPT_ALIGN_CENTER, 0.8); // KK

	WasChange();
	SetSelectable("EXIT_BUTTON",true);

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("InterfaceCancel","ProcessCancelExit",0);
	SetEventHandler("RemovePress","RemoveProcess",0);
	SetEventHandler("frame","WasChange",0);
	SetEventHandler("PressPsgDown","ToRemoveButton",0);
	SetEventHandler("SelectPassenger","SelectPassenger",0);
// KK -->
	SetEventHandler("ProceedShipAssignment", "CheckProceedShipAssignment", 0);
	SetEventHandler("MaxShipClassNo", "CheckMaxShipClassNo", 0);
// <-- KK
}

void ProcessCancelExit()
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("InterfaceCancel","ProcessCancelExit");
	DelEventHandler("RemovePress","RemoveProcess");
	DelEventHandler("frame","WasChange");
	DelEventHandler("PressPsgDown","ToRemoveButton");
// KK -->
	DelEventHandler("ProceedShipAssignment", "CheckProceedShipAssignment");
	DelEventHandler("MaxShipClassNo", "CheckMaxShipClassNo");
// <-- KK

	interfaceResultCommand = RC_INTERFACE_TRANSFER_MAIN_RETURN;
	EndCancelInterface(true);
}

// KK -->
int newCompanion  = 0;
int allowtransfer = 0;
void SelectPassenger()
{
	int i = GetCompanionIndex(refMyCharacter,nMyCharacterCompanionPlace);
	if(i>=0)
	{
		if(nFourImageNum<0) return;
		if(nFourImageNum>=OFFICER_MAX) return;
	}
	else
	{
		if(nFourImageNum!=0) return;
	}
	newCompanion = GetNotCaptivePassenger(refMyCharacter,curScrollNum);
	if (newCompanion<0) return;
	if (!GetRemovable(GetCharacter(newCompanion)) )
	{
		ShowHelpString("chelp_passengers#16");
		return;
	}

	CheckProceedShipAssignment();
}

void CheckProceedShipAssignment()
{
	allowtransfer++;
	if (EnableLimitedShipClass())
	{
		ref Companion = GetCharacter(newCompanion);
		int compareskill = GetShipSkill(refMyCharacter,SKILL_LEADERSHIP);
		Companion.prisoned = true;							// Make it a prisoner so its skill is not calculated
		ResetPartySkill(refMyCharacter,SKILL_LEADERSHIP);	// PB: So the above updates
		ResetPartySkill(refMyCharacter,SKILL_SAILING   );	// PB: So the above updates

		switch(allowtransfer)
		{
			case 1:
				//Levis: Check if character can command this ship
				if (GetShipMinClassForCharacter(GetCharacter(newCompanion)) > GetCharacterShipClass(refEnemyCharacter)) {
					SetNodeUsing("MSC_CONFIRM_RECTANGLE", true);
					SetNodeUsing("MSC_TEXTWINDOW", true);
					SetNodeUsing("MSC_CONFIRM_YES_BUTTON", true);
					SetNodeUsing("MSC_CONFIRM_NO_BUTTON", true);
					SetNodeUsing("MSC_SKILL_PIC", true);
					SetCurrentNode("MSC_CONFIRM_NO_BUTTON");
					SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "MSC_CONFIRM_NO_BUTTON");
					SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "MSC_CONFIRM_YES_BUTTON");
					SetFormatedText("MSC_TEXTWINDOW", TranslateString("", "This officer has too low Leadership and Sailing skills to command this ship. Assign anyway?"));
				}
				else
				{
					CheckProceedShipAssignment();
				}
			break;
			case 2:
				//Levis: Check if character can still sail without officer
				if (GetShipMinClassForCharacter(refMyCharacter) > GetCharacterShipClass(refMyCharacter)) {
					SetNodeUsing("MSC_CONFIRM_RECTANGLE", true);
					SetNodeUsing("MSC_TEXTWINDOW", true);
					SetNodeUsing("MSC_CONFIRM_YES_BUTTON", true);
					SetNodeUsing("MSC_CONFIRM_NO_BUTTON", true);
					SetNodeUsing("MSC_SKILL_PIC", true);
					SetCurrentNode("MSC_CONFIRM_NO_BUTTON");
					SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "MSC_CONFIRM_NO_BUTTON");
					SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "MSC_CONFIRM_YES_BUTTON");
					SetFormatedText("MSC_TEXTWINDOW", TranslateString("", "By doing this, you won't be able to command your own ship anymore. Proceed?"));
				}
				else
				{
					CheckProceedShipAssignment();
				}
			break;
			case 3:
				//Levis: Check if character can sail a fleet
				if (GetShipSkill(refMyCharacter,SKILL_LEADERSHIP) < FLEETCOMMAND_MIN_LEVEL && CheckFleetShips(true) && GetShipSkill(refMyCharacter,SKILL_LEADERSHIP) != compareskill) {
					SetNodeUsing("MSC_CONFIRM_RECTANGLE", true);
					SetNodeUsing("MSC_TEXTWINDOW", true);
					SetNodeUsing("MSC_CONFIRM_YES_BUTTON", true);
					SetNodeUsing("MSC_CONFIRM_NO_BUTTON", true);
					SetNodeUsing("MSC_SKILL_PIC", true);
					SetCurrentNode("MSC_CONFIRM_NO_BUTTON");
					SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "MSC_CONFIRM_NO_BUTTON");
					SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "MSC_CONFIRM_YES_BUTTON");
					SetFormatedText("MSC_TEXTWINDOW", TranslateString("", "By doing this, you won't have enough leadership to command a fleet anymore. Proceed?"));
				}
				else
				{
					CheckProceedShipAssignment();
				}
			break;
			case 4:
				CheckMaxShipClassYes();
			break;
		}
		DeleteAttribute(Companion,"prisoned");				// No prisoner again
		ResetPartySkill(refMyCharacter,SKILL_LEADERSHIP);	// PB: So this is restored
		ResetPartySkill(refMyCharacter,SKILL_SAILING);		// PB: So this is restored
	}
	else
	{
		CheckMaxShipClassYes();
	}
}

void CheckMaxShipClassYes()
{
	if (EnableLimitedShipClass()) {
		SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
		SetNodeUsing("MSC_CONFIRM_RECTANGLE", false);
		SetNodeUsing("MSC_TEXTWINDOW", false);
		SetNodeUsing("MSC_CONFIRM_YES_BUTTON", false);
		SetNodeUsing("MSC_CONFIRM_NO_BUTTON", false);
		SetNodeUsing("MSC_SKILL_PIC", false);
		SetCurrentNode("PASSENGERS_LIST");
	}
	int i = GetCompanionIndex(refMyCharacter,nMyCharacterCompanionPlace);
	ref Companion = GetCharacter(newCompanion);
	int oldCharIdx;
	if(nFourImageNum==0)
	{
		if( CalcCharacterSkill(Companion,SKILL_LEADERSHIP)<1 ) {
			ShowHelpString( "chelp_CaptainAssign#1" );
			return;
		}
		if( CalcCharacterSkill(Companion,SKILL_SAILING)<1 ) {
			ShowHelpString( "chelp_CaptainAssign#2" );
			return;
		}
		oldCharIdx = SetCompanionIndex(refMyCharacter,nMyCharacterCompanionPlace,newCompanion);
		if(oldCharIdx==newCompanion) return;
		if(oldCharIdx>=0)
		{
			IMoveOfficers(Companion,GetCharacter(oldCharIdx));
			if(oldCharIdx!=sti(refEnemyCharacter.index))
			{
				IDeleteShipAttributes(GetCharacter(oldCharIdx));
			}
		}
		ISetShipAttributes(Companion);
		// check attribute fix by NK using dchaley's trn_crew  04-09-13
		int tempnum = 0;
		if ( CheckAttribute(MainChar, "shiptransferinterface") )
		tempnum = sti(MainChar.shiptransferinterface.calledfrominterface);
		if (tempnum != 1) { SetSelectable("REMOVE_BUTTON",true); } else { SetSelectable("REMOVE_BUTTON",false); }		// changed after build 11 by KAM
		// end tempnum/check attribute fix
	}
	// Изменим список офицеров

	else
	{
		SetSelectable("REMOVE_BUTTON",true);
		oldCharIdx = GetCompanionIndex(refMyCharacter,nMyCharacterCompanionPlace);
		if(oldCharIdx<0) return;
		oldCharIdx = SetOfficersIndex(GetCharacter(oldCharIdx),nFourImageNum,newCompanion);
	}

	// изменим список пассажиров
	if(oldCharIdx!=-1)
		ChangePassenger(refMyCharacter,GetPassengerNumber(refMyCharacter,newCompanion),oldCharIdx);
	else
		RemovePassenger(refMyCharacter,Companion);

	if(IsOfficer(Companion))
	{
		RemoveOfficersIndex(refMyCharacter, newCompanion);
	}

	RefreshScreen();
}

void CheckMaxShipClassNo()
{
	allowtransfer = 0;
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
	SetNodeUsing("MSC_CONFIRM_RECTANGLE", false);
	SetNodeUsing("MSC_TEXTWINDOW", false);
	SetNodeUsing("MSC_CONFIRM_YES_BUTTON", false);
	SetNodeUsing("MSC_CONFIRM_NO_BUTTON", false);
	SetNodeUsing("MSC_SKILL_PIC", false);
	SetCurrentNode("PASSENGERS_LIST");
}
// <-- KK

void ToRemoveButton()
{
	if(GetSelectable("REMOVE_BUTTON")==true)
	{
		SetCurrentNode("REMOVE_BUTTON");
	}
}

void WasChange()
{
	int i,cn,n,skillval,modval,color;
	int bYesChange = false;
	string skill;
	if(curScrollNum != sti(GameInterface.passengers_list.current))
	{
		curScrollNum = sti(GameInterface.passengers_list.current);
		bYesChange = true;
	}
	if(nFourImageNum != sti(GameInterface.FourImage.current))
	{
		nFourImageNum = sti(GameInterface.FourImage.current);
		SetSelectable("REMOVE_BUTTON",false);
		i = GetCompanionIndex(refMyCharacter,nMyCharacterCompanionPlace);
		if(i>=0)
		{
			cn = GetOfficersIndex(GetCharacter(i),nFourImageNum);
			if(cn>=0)
			{	SetSelectable("REMOVE_BUTTON",GetRemovable(GetCharacter(cn)));
			}

			// added after build 11 by KAM -->
			// check attribute fix by NK using dchaley's trn_crew  04-09-13
			int tempnum = 0;
			if ( CheckAttribute(MainChar, "shiptransferinterface") )
			tempnum = sti(MainChar.shiptransferinterface.calledfrominterface);
			if (tempnum == 1)
			// end tempnum/check attribute fix
			{
				if (nFourImageNum == 0) { SetSelectable("REMOVE_BUTTON",false); }
			}
			// <-- added after build 11 by KAM

		}
		bYesChange = true;
	}

	if(oldCurNode!=GetCurrentNode())
	{
		oldCurNode = GetCurrentNode();
		bYesChange = true;
	}

	if(bYesChange == true)
	{
		// PB -->
		ref CharRef;
		if(oldCurNode=="PASSENGERS_LIST")	cn = GetNotCaptivePassenger(refMyCharacter,curScrollNum);
		else
		{
			cn = GetCompanionIndex(refMyCharacter,nMyCharacterCompanionPlace);
			cn = GetOfficersIndex(GetCharacter(cn),nFourImageNum);
		}
		if(cn>=0)
		{
			CharRef = GetCharacter(cn);
			if(CheckAttribute(CharRef,"quest.officertype")==true) GameInterface.strings.CharacterName = GetMySimpleName(CharRef) + " - " + XI_ConvertString("S"+CharRef.quest.officertype);
			else GameInterface.strings.CharacterName = GetMySimpleName(CharRef) + " - " + XI_ConvertString("SComrade-In-Arms");  // added by MAXIMUS

			if (oldCurNode=="PASSENGERS_LIST" || nFourImageNum > 0)
			{
				for(n = 0; n < NUM_DIFF_SKILLS; n++)
				{
					skill = GetSkillName(n);
					skillval = GetEffectiveSkill(CharRef,skill);
					modval = CalcCharacterSkill(CharRef,skill);
					color = COLOR_NORMAL;
					if(GetOfficerSkillFactor(CharRef,skill) == 2)	color = COLOR_GREEN; // PB: was if(skillVal >= modval)
					if(GetOfficerSkillFactor(CharRef,skill) == 1)	color = COLOR_MONEY; // PB: was if(skillVal <  modval)
					if(skillVal==0) color = COLOR_GRAY;
					skill = "Skill"+skill;
					GameInterface.strings.(skill) = modval;
					ChangeStringColor(skill,color);
				}
			}
			else
			{
				for(n = 0; n < NUM_DIFF_SKILLS; n++)
				{
					skill = GetSkillName(n);
					skillval = GetShipSkill(CharRef,skill);
					modval = CalcCharacterSkill(CharRef,skill);
					color = COLOR_NORMAL;
					skill = "Skill"+skill;
					GameInterface.strings.(skill) = skillval;
					if(skillVal < modval)									color = COLOR_RED;
					if(skillVal > modval)									color = COLOR_GREEN;
					if(skillVal == modval && skillVal==MAX_CHARACTER_SKILL)	color = COLOR_MONEY; // PB: Only if the captain has '10'
					if(skillVal==0)         								color = COLOR_GRAY;
					ChangeStringColor(skill,color);
				}
			}
			if (EnableLimitedShipClass()) GameInterface.strings.MaxShipClass = TranslateString("", "This officer can command ships up to class") + ": " + GetShipMinClassForCharacter(CharRef); // KK
		}
		else
		{
			GameInterface.strings.CharacterName = XI_ConvertString("Summary Skills");
			for(n = 0; n < NUM_DIFF_SKILLS; n++)
			{
				skill = GetSkillName(n);
				skill = "Skill"+skill;
				GameInterface.strings.(skill) = 0;
				ChangeStringColor(skill,COLOR_NORMAL);
			}
			GameInterface.strings.MaxShipClass = ""; // KK
		}
		// PB <--
	}
}

void RemoveProcess()
{
	int i,j,n;
	i = GetCompanionIndex(refMyCharacter,nMyCharacterCompanionPlace);
	if(i<0) return;

	ref rOfficer;
	ref rCompanion = GetCharacter(i);
	if(nFourImageNum>0)
	{
		j = GetOfficersIndex(rCompanion,nFourImageNum);
		if(j>0)
		{
			rOfficer = GetCharacter(j);
			RemovePassenger(rCompanion, rOfficer);
			AddPassenger(refMyCharacter,rOfficer,false);
		}
	}
	else
	{
		for(j=1; j<OFFICER_MAX; j++)
		{
			n = GetOfficersIndex(rCompanion,j);
			if(n>=0)
			{
				rOfficer = GetCharacter(n);
				RemovePassenger(rCompanion, rOfficer);
				AddPassenger(refMyCharacter,rOfficer,false);
			}
		}
		SetCompanionIndex(refMyCharacter,nMyCharacterCompanionPlace,-1);
		if(i!=sti(refEnemyCharacter.index))
		{
			IDeleteShipAttributes(rCompanion);
		}
		AddPassenger(refMyCharacter,rCompanion,false);
	}
	RefreshScreen();
	SetSelectable("REMOVE_BUTTON",false);
	if(GetNotCaptivePassenger(refMyCharacter,0)!=-1)	SetCurrentNode("PASSENGERS_LIST");
	else	SetCurrentNode("COMPAIN_LIST");
}

ref GetMyCharacterRef()
{
	return refMyCharacter;
}

ref GetEnemyCharacterRef()
{
	return refEnemyCharacter;
}

void FillScroll()
{
	curScrollNum = -1;
    GameInterface.passengers_list.current = 0;
	GameInterface.passengers_list.NotUsed = 5;

	GameInterface.passengers_list.ImagesGroup.t0 = "EMPTYFACE";
	FillFaceList("passengers_list.ImagesGroup",refMyCharacter,0); // officers
	FillFaceList("passengers_list.ImagesGroup",refMyCharacter,2); // passengers
	FillFaceList("passengers_list.ImagesGroup",refMyCharacter,1); // companions
	if(nCompanionIndex>=0)	FillFaceList("passengers_list.ImagesGroup",GetCharacter(nCompanionIndex),0); // enemy officers

	GameInterface.passengers_list.BadTex1 = FindFaceGroupNum("passengers_list.ImagesGroup","EMPTYFACE");
// KK -->
	if (bNewInterface)
		GameInterface.passengers_list.BadPic1 = "emptyface_new";
	else
		GameInterface.passengers_list.BadPic1 = "emptyface";
// <-- KK

	ref charRef;
	int charQuantity=0;
	string attributeName;
	while(GetNotCaptivePassenger(refMyCharacter,charQuantity)!=-1)
	{
		charRef = GetCharacter(GetNotCaptivePassenger(refMyCharacter,charQuantity));
		attributeName = "pic" + (charQuantity+1);
		GameInterface.passengers_list.(attributeName).img1 = GetFacePicName(charRef);
		GameInterface.passengers_list.(attributeName).tex1 = FindFaceGroupNum("passengers_list.ImagesGroup","FACE128_"+charRef.FaceId);
		charQuantity++;
	}
	GameInterface.passengers_list.ListSize = charQuantity;
}

void RefillScroll()
{
	ref charRef;
	int charQuantity=0;
	string attributeName;

	// Delete old attributes
	charQuantity = sti(GameInterface.passengers_list.ListSize);
	for(int i=0; i<charQuantity; i++)
	{
		attributeName = "passengers_list.pic" + (i+1);
		DeleteAttribute(&GameInterface, attributeName);
	}
	// fill new data
	charQuantity = 0;
	while(GetNotCaptivePassenger(refMyCharacter,charQuantity)!=-1)
	{
		charRef = GetCharacter(GetNotCaptivePassenger(refMyCharacter,charQuantity));
		attributeName = "pic" + (charQuantity+1);
		GameInterface.passengers_list.(attributeName).img1 = GetFacePicName(charRef);
		GameInterface.passengers_list.(attributeName).tex1 = FindFaceGroupNum("passengers_list.ImagesGroup","FACE128_"+charRef.FaceId);
		charQuantity++;
	}
	GameInterface.passengers_list.ListSize = charQuantity;
}

void FillFourImages()
{
	int i,cn;
	string attrName;
	ref refCurChar;

    nFourImageNum = -1;
	GameInterface.FourImage.current = 0;
	GameInterface.FourImage.ImagesGroup.t0 = "EMPTYFACE";
	GameInterface.FourImage.BadOnePicture = NONEFACE_TEXTURE_NAME;
	FillFaceList( "FourImage.ImagesGroup", refMyCharacter, 0 ); // officers
	FillFaceList( "FourImage.ImagesGroup", refMyCharacter, 2 ); // passengers
	FillFaceList( "FourImage.ImagesGroup", refMyCharacter, 1 ); // companions
	if(nCompanionIndex>=0) FillFaceList( "FourImage.ImagesGroup", GetCharacter(nCompanionIndex), 0 ); // enemy officers

	i = GetCompanionIndex(refMyCharacter,nMyCharacterCompanionPlace);
	ref baseChar;
	if(i>=0)
	{
		baseChar = GetCharacter(i);
		for(i=0; i<OFFICER_MAX; i++)
		{
			attrName = "pic"+(i+1);
			cn = GetOfficersIndex(baseChar,i);
			if(cn==-1)
			{
// KK -->
				if (bNewInterface)
					GameInterface.FourImage.(attrName).img1 = "emptyface_new";
				else
					GameInterface.FourImage.(attrName).img1 = "emptyface";
// <-- KK
				GameInterface.FourImage.(attrName).tex1 = FindFaceGroupNum("FourImage.ImagesGroup","EMPTYFACE");
			}
			else
			{
				refCurChar = GetCharacter(cn);
				GameInterface.FourImage.(attrName).img1 = GetFacePicName(refCurChar);
				GameInterface.FourImage.(attrName).tex1 = FindFaceGroupNum("FourImage.ImagesGroup","FACE128_"+refCurChar.FaceID);
			}
			GameInterface.FourImage.(attrName).selected = true;
		}
	}
	else
	{
		for(i=0; i<OFFICER_MAX; i++)
		{
			attrName = "pic"+(i+1);
// KK -->
			if (bNewInterface)
				GameInterface.FourImage.(attrName).img1 = "emptyface_new";
			else
				GameInterface.FourImage.(attrName).img1 = "emptyface";
// <-- KK
			GameInterface.FourImage.(attrName).tex1 = 0;
			GameInterface.FourImage.(attrName).selected = false;
		}
		GameInterface.FourImage.pic1.selected = true;
	}
}

void RefillFourImages()
{
	int i,cn;
	string attrName;
	ref baseChar,refCurChar;

	i = GetCompanionIndex(refMyCharacter,nMyCharacterCompanionPlace);
	if(i>=0)
	{
		baseChar = GetCharacter(i);
		for(i=0; i<OFFICER_MAX; i++)
		{
			attrName = "pic"+(i+1);
			cn = GetOfficersIndex(baseChar,i);
			if(cn==-1)
			{
// KK -->
				if (bNewInterface)
					GameInterface.FourImage.(attrName).img1 = "emptyface_new";
				else
					GameInterface.FourImage.(attrName).img1 = "emptyface";
// <-- KK
				GameInterface.FourImage.(attrName).tex1 = FindFaceGroupNum("FourImage.ImagesGroup","EMPTYFACE");
			}
			else
			{
				refCurChar = GetCharacter(cn);
				GameInterface.FourImage.(attrName).img1 = GetFacePicName(refCurChar);
				GameInterface.FourImage.(attrName).tex1 = FindFaceGroupNum("FourImage.ImagesGroup","FACE128_"+refCurChar.FaceID);
			}
			GameInterface.FourImage.(attrName).selected = true;
		}
	}
	else
	{
		for(i=0; i<OFFICER_MAX; i++)
		{
			attrName = "pic"+(i+1);
// KK -->
			if (bNewInterface)
				GameInterface.FourImage.(attrName).img1 = "emptyface_new";
			else
				GameInterface.FourImage.(attrName).img1 = "emptyface";
// <-- KK
			GameInterface.FourImage.(attrName).tex1 = 0;
			GameInterface.FourImage.(attrName).selected = false;
		}
		GameInterface.FourImage.pic1.selected = true;
	}
}

void RefreshScreen()
{
	//DeleteAttribute(&GameInterface,"passengers_list");
	//DeleteAttribute(&GameInterface,"FourImage");
	RefillScroll();//FillScroll();
	RefillFourImages();//FillFourImages();
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_REFRESH_SCROLL,"PASSENGERS_LIST");
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_FOURIMAGE_CHANGE,"COMPAIN_LIST",-1);
}

void IMoveOfficers(ref rToChar,ref rFromChar)
{
	for(int i=1; i<OFFICER_MAX ; i++)
	{
		SetOfficersIndex(rToChar,i,SetOfficersIndex(rFromChar,i,-1));
	}
}

void IDeleteShipAttributes(ref chref)
{
	DeleteAttribute(chref,"ship");
	chref.ship.type = SHIP_NOTUSED_TYPE_NAME; // PS
}

void ISetShipAttributes(ref chref)
{
	if(chref.index == refEnemyCharacter.index) return;
	DeleteAttribute(chref,"ship");
	aref arToChar;	makearef(arToChar,chref.ship);
	aref arFromChar;	makearef(arFromChar,refEnemyCharacter.ship);
	CopyAttributes(arToChar,arFromChar);
}
