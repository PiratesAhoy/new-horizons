
// KK #define NONEFACE_TEXTURE_NAME "interfaces\empty_face.tga"

#define ISHOW_MODE_CAPTIVE		0
#define ISHOW_MODE_SUMSKILL		1
#define ISHOW_MODE_CHRSKILL		2

string oldCurNode = "";
int oldShowMode = -1;

int nCurScrollNum;
int nFourImageNum;
ref _refCh;

int prisonFlag;
int prisonRansomCost;

string curLocNation = "";
bool isransom = false; // NK 05-04-16

bool showPassengers = true;
bool showPrisoned = false;

void InitInterface_R(string iniName,ref _refCharacter)
{
	_refCh = _refCharacter;

	GameInterface.title = "titlePassengers";

	FillScroll();
	FillFourImages();

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();//MAXIMUS: standard exit-string for exit-button

	CreateString(true,"skillLeadership","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,232,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"skillFencing","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,266,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"skillSailing","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,300,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"skillAccuracy","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,334,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"skillCannons","",FONT_BOLD_NUMBERS,COLOR_NORMAL,300,368,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"skillGrappling","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,232,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"skillRepair","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,266,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"skillDefence","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,300,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"skillCommerce","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,334,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"skillSneak","",FONT_BOLD_NUMBERS,COLOR_NORMAL,434,368,SCRIPT_ALIGN_RIGHT,1.0);

	CreateString(false,"CharacterName","",FONT_NORMAL,COLOR_NORMAL,320,200,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"CharacterNation","",FONT_NORMAL,COLOR_NORMAL,320,234,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"RansomCost","0",FONT_NORMAL,COLOR_NORMAL,284,266,SCRIPT_ALIGN_LEFT,1.0); // was 320. NK 05-04-16

	/* BEGIN MOD : Stone-D 01/08/2003 */
	SetSelectable("RELEASE_CAPTIVE",false);
	SetSelectable("RANSOM_CAPTIVE",false); // NK 05-04-16
	SetSelectable("EXECUTE_CAPTIVE",false);
	/* END MOD : Stone-D 01/08/2003 */

	SetVariable();

// KK -->
	bool hasShip = false;
	ref MainChar = GetMainCharacter();
	for (int i = 0; i < COMPANION_MAX; i++) {
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
		SendMessage(&GameInterface, "lsls", MSG_INTERFACE_MSG_TO_NODE, "I_SHIP", 0, XI_ConvertString("Sel Berth"));
	}
// <-- KK

// MAXIMUS interface MOD -->
	SetSelectable("I_SHIP", !LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm() && hasShip); // KK
	// KK SetSelectable("I_NATIONS",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	SetSelectable("I_TRADEBOOK",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	// PB SetSelectable("I_QUESTBOOK",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	SetSelectable("I_SHIPLOG",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	SetSelectable("EXIT_BUTTON",true);
// MAXIMUS interface MOD <--

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("frame","ProcessFrame",1);
	SetEventHandler("exitCancel","ProcessCancelExit",0);

	/* BEGIN MOD : Stone-D 01/08/2003 */
	SetEventHandler("PassengerDown","PassengerDown",0);
	SetEventHandler("ReleaseCaptive","PressReleaseCaptive",0);
	SetEventHandler("RansomCaptive","PressRansomCaptive",0); // NK 05-04-16
	SetEventHandler("ExecuteCaptive","PressExecuteCaptive",0);
	SetEventHandler("RemoveOfficer","ProcessOfficerRemove",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
	/* END MOD : Stone-D 01/08/2003 */

	SetEventHandler("ChangeOfficerRole", "ProcessChangeRole" ,0);
	SetEventHandler("SelectedFirstMate", "SelectFirstMate", 0);
	SetEventHandler("SelectedNavigator", "SelectNavigator", 0);
	SetEventHandler("SelectedGunner", "SelectGunner", 0);
	SetEventHandler("SelectedBoatswain", "SelectBoatswain", 0);
	SetEventHandler("SelectedDoctor", "SelectDoctor", 0);
	SetEventHandler("SelectedCarpenter", "SelectCarpenter", 0);
	SetEventHandler("SelectedQMaster", "SelectQMaster", 0);
	SetEventHandler("SelectedRemove", "SelectRemove", 0);
	SetEventHandler("SelectAbort", "SelectAbort", 0);
}

void FillFourImages()
{
	int i,cn;
	string attrName;
	ref refCurChar;
	nFourImageNum = -1;
	GameInterface.FourImage.current = 0;
	GameInterface.FourImage.ImagesGroup.t0 = "EMPTYFACE";
	// KK GameInterface.FourImage.BadOnePicture = NONEFACE_TEXTURE_NAME;
	FillFaceList( "FourImage.ImagesGroup", _refCh, 0 ); // officers
	FillFaceList( "FourImage.ImagesGroup", _refCh, 2 ); // passengers

	for(i=0; i<OFFICER_MAX; i++)
	{
		attrName = "pic"+(i+1);
		cn = GetOfficersIndex(_refCh,i);
		GameInterface.FourImage.(attrName).selected = true;
		if(cn==-1)
		{
// KK -->
			if (bNewInterface)
				GameInterface.FourImage.(attrName).img1 = "emptyface_new";
			else
				GameInterface.FourImage.(attrName).img1 = "emptyface";
// <-- KK
			GameInterface.FourImage.(attrName).tex1 = 0;
		}
		else
		{
			GameInterface.FourImage.(attrName).img1 = GetFacePicName(GetCharacter(cn));
			GameInterface.FourImage.(attrName).tex1 = FindFaceGroupNum("FourImage.ImagesGroup","FACE128_"+Characters[cn].FaceID);
			if(DynamicInterfaceLevel() > 1) GameInterface.FourImage.(attrName).str1 = "#" + GetMySimpleName(GetCharacter(cn)); // KK: Dynamic Interfaces
		}
	}
}

void FillScroll()
{
	int i;
	string faceName;
	string attributeName;
	string PsgAttrName;
	int _curCharIdx;
	ref _refCurChar;
	aref pRef;

	nCurScrollNum = -1;
	GameInterface.passengerslist.current = 0;
	makearef(pRef,_refCh.Fellows.Passengers);
	int nListSize = GetPassengersQuantity(_refCh);
	GameInterface.passengerslist.NotUsed = 5;
	GameInterface.passengerslist.ListSize = nListSize;

	GameInterface.passengerslist.ImagesGroup.t0 = "EMPTYFACE";

	FillFaceList( "passengerslist.ImagesGroup", _refCh, 0 ); // officers
	FillFaceList( "passengerslist.ImagesGroup", _refCh, 2 ); // passengers
	FillFaceList( "passengerslist.ImagesGroup", _refCh, 3 ); // prisoners

	GameInterface.passengerslist.BadTex1 = 0;
// KK -->
	if (bNewInterface)
		GameInterface.passengerslist.BadPic1 = "emptyface_new";
	else
		GameInterface.passengerslist.BadPic1 = "emptyface";
// <-- KK

	for(i=0; i<nListSize; i++)
	{
		attributeName = "pic" + (i+1);
		PsgAttrName = "id"+(i+1);
		_curCharIdx = sti(pRef.(PsgAttrName));
		if(_curCharIdx!=-1)
		{
			ref chr = GetCharacter(_curCharIdx);
			if (IsPrisoner(chr)) continue; // KK
			if (CheckAttribute(chr, "faceID"))
			{
				GameInterface.passengerslist.(attributeName).img1 = GetFacePicName(chr);
				GameInterface.passengerslist.(attributeName).tex1 = FindFaceGroupNum("passengerslist.ImagesGroup","FACE128_"+chr.FaceID);
				if(DynamicInterfaceLevel() > 1) GameInterface.passengerslist.(attributeName).str1 = "#" + GetMySimpleName(chr); // KK: Dynamic Interfaces
			}
			else
			{
				TraceAndLog("Passengers FillScroll: Face ID missing for " + GetMySimpleName(chr));
				DumpAttributes(chr);
			}
		}
		else
		{
			GameInterface.passengerslist.(attributeName).img1 = "emptyface";
			GameInterface.passengerslist.(attributeName).tex1 = 0;
		}
	}

// KK -->
	for(i=0; i<nListSize; i++)
	{
		attributeName = "pic" + (i+1);
		PsgAttrName = "id"+(i+1);
		_curCharIdx = sti(pRef.(PsgAttrName));
		if(_curCharIdx!=-1)
		{
			if (!IsPrisoner(GetCharacter(_curCharIdx))) continue;
			GameInterface.passengerslist.(attributeName).img1 = GetFacePicName(GetCharacter(_curCharIdx));
			GameInterface.passengerslist.(attributeName).tex1 = FindFaceGroupNum("passengerslist.ImagesGroup","FACE128_"+Characters[_curCharIdx].FaceID);
			if(DynamicInterfaceLevel() > 1) GameInterface.passengerslist.(attributeName).str1 = "#" + GetMySimpleName(GetCharacter(_curCharIdx)); // PB: Dynamic Interfaces
		}
		else
		{
			GameInterface.passengerslist.(attributeName).img1 = "emptyface";
			GameInterface.passengerslist.(attributeName).tex1 = 0;
		}
	}
// <-- KK
}

void ProcessFrame()
{
	string curName = GetCurrentNode();
	if(oldCurNode!=curName)
	{
		oldCurNode = curName;
		int idx;
		if(curName=="PASSENGERSLIST")
		{
			nCurScrollNum = -1;

			bool enable = false;

			idx = sti(GameInterface.passengerslist.current);
			idx = GetPassenger(_refCh, idx);
			if(idx > 0)
			{
				ref chr = GetCharacter(idx);
				enable = !CheckAttribute(chr, "prisoned") && !CheckAttribute(chr,"quest.NoRaise");
			}

			SetSelectable("REMOVE_OFFICER", false);
			SetSelectable("CHANGE_OFFICER_ROLE", enable);
		}
		else
		{
			if(curName=="OFFICERSLIST")
			{
				nFourImageNum = -1;
			}
		}
	}

	if(sti(GameInterface.passengerslist.current)!=nCurScrollNum)
	{
		DoScrollChange();
	}

	if(sti(GameInterface.FourImage.current) != nFourImageNum)
	{
		DoFourImageChange();
		if(nFourImageNum >= 0)
		{
			SetSelectable("CHANGE_OFFICER_ROLE", nFourImageNum != 0 && GetOfficersIndex(_refCh, nFourImageNum) >= 0);
		}
	}
}

void DoScrollChange()
{
	isransom = false; // NK 05-04-16
	nCurScrollNum   = sti(GameInterface.passengerslist.current);
	bool enable = true;
	ref chPsgn;
	int psgIdx = GetPassenger(_refCh,nCurScrollNum);
	prisonFlag = false;
	if(psgIdx>=0)
	{
		chPsgn = GetCharacter(psgIdx);
		if(CheckAttribute(chPsgn,"prisoned")==true)
		{
			prisonFlag = sti(chPsgn.prisoned);
		}
		enable = !CheckAttribute(chPsgn, "prisoned") && !CheckAttribute(chPsgn,"quest.NoRaise");
		SetSelectable("CHANGE_OFFICER_ROLE", enable);
	}

	if(prisonFlag==true)
	{
		if(GetRemovable(chPsgn)) // NK added this check back again. 05-04-16
		{
			SetShowMode(ISHOW_MODE_CAPTIVE);
			if(VISIT_DECK==0)
			{
			/* BEGIN MOD : Stone-D 01/08/2003 */
			SetSelectable("EXECUTE_CAPTIVE",true);
			/* END MOD : Stone-D 01/08/2003 */
			SetSelectable("RELEASE_CAPTIVE",true); // NK alwasy can release 05-04-16
			// ccc ransom options added Oct17 04.  Based on code by Stone-D and Nathan Kell, all credit and thanks to them :)
			//ccc if(true) // NK - if(GetRemovable(chPsgn)) //if( GetRemovable(chPsgn) && CheckAttribute(chPsgn,"nation") && chPsgn.nation==curLocNation )
			// modified by NK in light of new release button. 05-04-16
			bool allsites = RANSOMSITE == "all";
			bool ransomstate = !RANSOM_AT_HOME && allsites;
			if(!ransomstate)
			{
				if(FindLoadedLocation() != -1)
				{
					ransomstate = CheckAttribute(chPsgn,"nation") && chPsgn.nation == GetCurrentLocationNation(); //ccc ransom only at homeisland of captive
					ransomstate = ransomstate || !RANSOM_AT_HOME;
					if(ransomstate && !allsites) ransomstate = CheckAttribute(loadedLocation,"type") && loadedLocation.type== RANSOMSITE; // ccc ransom only at loc as defined in Buildsettings
				}
			}
			if(RELEASE_AT_SEA) ransomstate = ransomstate && FindLoadedLocation() != -1; // NK so if release_at_sea, we can only release, not ransom, at sea.
			if(ransomstate) SetSelectable("RANSOM_CAPTIVE",true);
			else SetSelectable("RANSOM_CAPTIVE", false);
			// ccc ransom options end. Last lines are a bit crude coding but that way its more clear what I've messed up ;)
			}
		}
		SetCaptiveData(chPsgn);
		// NK <--
	}
	else
	{
		if(psgIdx<0)
		{
			SetShowMode(ISHOW_MODE_SUMSKILL);
			SetSumSkillData();
		}
		else
		{
			SetShowMode(ISHOW_MODE_CHRSKILL);
			SetChrSkillData(GetCharacter(psgIdx));
		}
	}
}

// int GetPrisonRansomCost(ref refCharacter) moved to CharacterUtilite.c

void DoFourImageChange()
{
	int cn = -1;
	nFourImageNum = sti(GameInterface.FourImage.current);
	bool selectable = false;
	if(nFourImageNum>0)
	{
		cn = GetOfficersIndex(_refCh,nFourImageNum);
		if(cn>=0)
		{
			selectable = GetRemovable(GetCharacter(cn));
		}
	}
	if(sti(GetStorylineVar(FindCurrentStoryline(), "NO_CREW_OR_OFFICERS")) < 1)
	{
		SetSelectable("PASSENGERSLIST", true);
		SetSelectable("REMOVE_OFFICER", selectable);
	}
	else
	{
		SetSelectable("PASSENGERSLIST", false);
		SetSelectable("REMOVE_OFFICER", false);
	}

	if(cn<0)
	{
		SetShowMode(ISHOW_MODE_SUMSKILL);
		SetSumSkillData();
	}
	else
	{
		SetShowMode(ISHOW_MODE_CHRSKILL);
		SetChrSkillData(GetCharacter(cn));
	}
}

void SetVariable()
{
	prisonFlag = false;
	prisonRansomCost = 0;
	curLocNation = GetCurrentLocationNation();
	SetSumSkillData();
}

void ProcessOfficerRemove()
{
	if(nFourImageNum==0)
	{
		ShowHelpString("chelp_passengers#10");
	}
	else
	{
		int cn = GetOfficersIndex(_refCh,nFourImageNum);
		if(cn==-1)
		{
			ShowHelpString("chelp_passengers#11");
		}
		else
		{
			ref _refComp = GetCharacter(cn);
			if( GetRemovable(_refComp)==false )
			{
				ShowHelpString("chelp_passengers#15");
				return;
			}

			XI_ChangeOfficer(nFourImageNum,-1);

			ShowHelpString("chelp_passengers#12");
			SetCurrentNode("OFFICERSLIST");
			SetSelectable("REMOVE_OFFICER",false);
		}
	}
}

int XI_ChangeOfficer(int OfficerNum, int idxNew)
{
	int tmpIdx = GetOfficersIndex(_refCh,OfficerNum);
	ref chref;
	if(tmpIdx!=-1)
	{
		chref = GetCharacter(tmpIdx);
		if( CheckAttribute(chref,"NonRemovable") && sti(chref.NonRemovable)==true ) return idxNew;
	}
	string attrName = "pic"+(OfficerNum+1);
	GameInterface.FourImage.(attrName).selected = true;
	int changeIdx = OfficerNum;
	if(idxNew==-1)
	{
		if(bNewInterface)	GameInterface.FourImage.(attrName).img1 = "emptyface_new"; // PB
		else				GameInterface.FourImage.(attrName).img1 = "emptyface";
		GameInterface.FourImage.(attrName).tex1 = 0;
		if(DynamicInterfaceLevel() > 1) GameInterface.FourImage.(attrName).str1 = ""; // PB

		chref = GetCharacter(tmpIdx);
		if(CheckAttribute(chref, "quest.officertype") && chref.quest.officertype == OFFIC_TYPE_ABORDAGE)
		{
			//DeleteAttribute(chref, "quest.officertype"); //Levis we give an NPC offictype now
			chref.quest.officertype = OFFIC_TYPE_RANDCHAR;
		}
	}
	else
	{
		for(int i=1;i<OFFICER_MAX;i++)
		{
			if(idxNew==GetOfficersIndex(_refCh,i))
			{
				XI_ChangeOfficer(i,-1);
			}
		}
		GameInterface.FourImage.(attrName).img1 = GetFacePicName(GetCharacter(idxNew));
		GameInterface.FourImage.(attrName).tex1 = FindFaceGroupNum("FourImage.ImagesGroup","FACE128_"+Characters[idxNew].FaceID);
		if(DynamicInterfaceLevel() > 1) GameInterface.FourImage.(attrName).str1 = "#" + GetMySimpleName(GetCharacter(idxNew)); // KK

		chref = GetCharacter(idxNew);
		if(!CheckAttribute(chref, "quest.officertype"))
		{
			chref.quest.officertype = OFFIC_TYPE_ABORDAGE;
		}
	}
	SendMessage(&GameInterface,"lsl", MSG_INTERFACE_FOURIMAGE_CHANGE, "OFFICERSLIST", changeIdx);
	nFourImageNum = -1;
	int retVal = SetOfficersIndex(_refCh,OfficerNum,idxNew);
	SetSumSkillData();
	if(idxNew<0) return retVal;//MAXIMUS
	if(!IsEntity(&Characters[idxNew])) { Log_SetStringToLog(Characters[idxNew].name+" "+Characters[idxNew].lastname+" "+XI_ConvertString("WillJoinLater")); }//MAXIMUS
	return retVal;
}

void ProcessOfficerSet()
{
	int cn;
	int oldIdx;
	ref chref;

	if(nFourImageNum==0)
	{
		ShowHelpString("chelp_passengers#13");
	}
	else
	{
		cn = GetPassenger(_refCh,nCurScrollNum);
		if(cn==-1)
		{
			ShowHelpString("chelp_passengers#14");
		}
		else
		{
			chref = GetCharacter(cn);
			if( CheckAttribute(chref,"prisoned") && sti(chref.prisoned)==true )
			{
				ShowHelpString("chelp_passengers#16");
				return;
			}
			if( GetRemovable(chref)==false )
			{
				ShowHelpString("chelp_passengers#16");
				return;
			}
			oldIdx = GetOfficersIndex(_refCh,nFourImageNum);
			if(oldIdx!=-1)
			{
				if( GetRemovable(GetCharacter(oldIdx))==false )
				{
					ShowHelpString("chelp_passengers#15");
					return;
				}
			}
			XI_ChangeOfficer(nFourImageNum,cn);
		}
	}
}
// NK release at sea 05-04-16 -->
// now use ransom function for ransom, release for release _free_.
void PressRansomCaptive()
{
	if(prisonFlag!=true) return;
	int captiveIdx = GetPassenger(_refCh,nCurScrollNum);
	if(captiveIdx==-1) return;
	ref captiveCharacter = GetCharacter(captiveIdx);
	if( !GetRemovable(captiveCharacter) ) return;
	DeleteAttribute(captiveCharacter,"prisoned"); // освободили пленника
	DelFromScroll("PASSENGERSLIST",nCurScrollNum);
	SetCurrentNode("PASSENGERSLIST");
	for(int i=1;i<OFFICER_MAX;i++)
	{
		if(captiveIdx==GetOfficersIndex(_refCh,i))
		{
			XI_ChangeOfficer(i,-1);
		}
	}
	RemovePassenger(_refCh,captiveCharacter);
	if(CheckAttribute(captiveCharacter,"ransom")) DeleteAttribute(captiveCharacter,"ransom"); // NK
	AddMoneyToCharacter(_refCh,prisonRansomCost);
	nCurScrollNum=-1;
}

// this is only for release _free_, not ransom.
void PressReleaseCaptive()
{
	if(prisonFlag!=true) return;
	int captiveIdx = GetPassenger(_refCh,nCurScrollNum);
	if(captiveIdx==-1) return;
	ref captiveCharacter = GetCharacter(captiveIdx);
	if( !GetRemovable(captiveCharacter) ) return;
	DeleteAttribute(captiveCharacter,"prisoned"); // освободили пленника
	DelFromScroll("PASSENGERSLIST",nCurScrollNum);
	SetCurrentNode("PASSENGERSLIST");
	for(int i=1;i<OFFICER_MAX;i++)
	{
		if(captiveIdx==GetOfficersIndex(_refCh,i))
		{
			XI_ChangeOfficer(i,-1);
		}
	}
	RemovePassenger(_refCh,captiveCharacter);
	if(CheckAttribute(captiveCharacter,"ransom")) DeleteAttribute(captiveCharacter,"ransom"); // NK
	// new code starts here:
	ChangeCharacterReputation(GetMainCharacter(), 5); // rep boost
	LAi_SetCurHPMax(&captiveCharacter);
	//for now this is disabled. I can't get it to work. So all you get is the boost.
	/*if(bSeaActive)
	{
		trace("sea active");
		captiveCharacter.ship.type = "Tartane1";
		Ship_CreateForCharacter(&captiveCharacter, captiveCharacter.Ship.Type, "Lifeboat")	// ccc apr03
		trace("ship created");
		string sGName = "releasedprisoner";
		ref	rGroup = Group_GetGroupByIndex(Group_CreateGroup(sGName));
		trace("group created");
		float x,z,ay;
		ref pch = GetMainCharacter();
		ay = stf(pch.Ship.Ang.y);
		ay += PId2;
		x = sin(ay) * 50 + stf(pch.Ship.Pos.x);
		z = cos(ay) * 50 + stf(pch.Ship.Pos.z);
		ay -= PId2;
		Group_SetXZ_AY(sGName, x, z, ay);
		trace("xzay");
		Group_SetType(sGName, "trade");
		trace("type set");
		Group_DeleteAtEnd(sGName);
		trace("set delete");
		Group_SetGroupCommander(sGName, captiveCharacter.id);
		trace("set cmdr");

		captiveCharacter.SeaAI.Group.Name = sGName;
		Group_AddCharacter(sGName, captiveCharacter.id);
		trace("add char");
		Ship_Add2Sea(captiveIdx, 0, "trade");
		trace("add2sea");
		Group_SetTaskRunaway(sGName);
		trace("set task");
		/*ay += PId2;
		x = 10000.0 * sin(ay);
		z = 10000.0 * cos(ay);
		Group_SetTaskMove(sGName, x, z);*/
/*
		SetCharacterRelationBoth(captiveIdx, GetMainCharacterIndex(), RELATION_NEUTRAL);
		trace("update rel");
		RefreshBattleInterface(true);
		trace("refreshed BI");

		AISea.isDone = "";
	}*/
	// NK <--
	nCurScrollNum=-1;
}

void PassengerDown()
{
	if(nFourImageNum==0) return;
	int cn = GetOfficersIndex(_refCh,nFourImageNum);
	if(cn==-1) return;
	if( GetRemovable(_refCh) ) SetCurrentNode("REMOVE_OFFICER");
}

void ProcessCancelExit()
{
	// Aconcagua: moved to here into a for loop to avoid login
	// on adding and removing a char in the same interface instance
	for(int i = 0; i < OFFICER_MAX; i++)
	{
		int idx = GetOfficersIndex(GetMainCharacter(), i);
		if(idx >= 0 && !IsEntity(&Characters[idx]))
		{
			Log_SetStringToLog(Characters[idx].name+" "+Characters[idx].lastname+" "+XI_ConvertString("WillJoinLater"));
		}
	}//MAXIMUS


	/* BEGIN MOD : Stone-D 01/08/2003 */
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("frame","ProcessFrame");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("PassengerDown","PassengerDown");
	DelEventHandler("ReleaseCaptive","PressReleaseCaptive");
	DelEventHandler("ExecuteCaptive","PressExecuteCaptive");
	DelEventHandler("RemoveOfficer","ProcessOfficerRemove");
	DelEventHandler("ievnt_command","ProcessCommandExecute");
	/* END MOD : Stone-D 01/08/2003 */

	DelEventHandler("ChangeOfficerRole", "ProcessChangeRole");
	DelEventHandler("SelectedFirstMate", "SelectFirstMate");
	DelEventHandler("SelectedNavigator", "SelectNavigator");
	DelEventHandler("SelectedGunner", "SelectGunner");
	DelEventHandler("SelectedBoatswain", "SelectBoatswain");
	DelEventHandler("SelectedDoctor", "SelectDoctor");
	DelEventHandler("SelectedCarpenter", "SelectCarpenter");
	DelEventHandler("SelectedQMaster", "SelectQMaster");
	DelEventHandler("SelectedRemove", "SelectRemove");
	DelEventHandler("SelectAbort", "SelectAbort");

	interfaceResultCommand = RC_INTERFACE_PASSENGERS_EXIT;

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
// MAXIMUS interface MOD <--
}

void SetShowMode(int sm)
{
	if(oldShowMode==sm) return;

	switch(oldShowMode)
	{

	case ISHOW_MODE_CAPTIVE:
	/* BEGIN MOD : Stone-D 01/08/2003 */
		DisableString("CharacterName");
		DisableString("CharacterNation");
		DisableString("RansomCost");
		SetNodeUsing("CAPTIVE_IMAGES",false);
		SetNodeUsing("CAPTIVE_STRINGS",false);
		SetNodeUsing("RELEASE_CAPTIVE",false);
		SetNodeUsing("RANSOM_CAPTIVE",false); // NK 05-04-16
		SetNodeUsing("EXECUTE_CAPTIVE",false);
// added by MAXIMUS [for hiring captives] -->
		SetNodeUsing("TEXTWINDOW",false);
		if(VISIT_DECK) SetNodeUsing("REMOVE_OFFICER",true);
		SetNodeUsing("CHANGE_OFFICER_ROLE",true);
// added by MAXIMUS [for hiring captives] <--
	/* END MOD : Stone-D 01/08/2003 */
	break;

	case ISHOW_MODE_SUMSKILL:
		DisableString("skillLeadership");
		DisableString("skillFencing");
		DisableString("skillSailing");
		DisableString("skillAccuracy");
		DisableString("skillCannons");
		DisableString("skillGrappling");
		DisableString("skillRepair");
		DisableString("skillDefence");
		DisableString("skillCommerce");
		DisableString("skillSneak");
		SetNodeUsing("SUMMARYSTRINGS",false);
		SetNodeUsing("SUMMARYIMAGES",false);
	break;

	case ISHOW_MODE_CHRSKILL:
		DisableString("skillLeadership");
		DisableString("skillFencing");
		DisableString("skillSailing");
		DisableString("skillAccuracy");
		DisableString("skillCannons");
		DisableString("skillGrappling");
		DisableString("skillRepair");
		DisableString("skillDefence");
		DisableString("skillCommerce");
		DisableString("skillSneak");
		DisableString("CharacterName");
		SetNodeUsing("SUMMARYIMAGES",false);
	break;

	}

	oldShowMode = sm;

	switch(sm)
	{

	case ISHOW_MODE_CAPTIVE:
	/* BEGIN MOD : Stone-D 01/08/2003 */
		EnableString("CharacterName");
		EnableString("CharacterNation");
		// NK add release at sea 05-04-16 -->
		EnableString("RansomCost");  // show ransom
		SetNodeUsing("CHANGE_OFFICER_ROLE",false);
// added by MAXIMUS [for hiring captives] -->
		if(VISIT_DECK==0)
		{
		SetNodeUsing("CAPTIVE_IMAGES",true);
		SetNodeUsing("RANSOM_CAPTIVE",true); // this replaces old releasecaptive
		SetNodeUsing("RELEASE_CAPTIVE",true);
		// NK <--
		SetNodeUsing("CAPTIVE_STRINGS",true);
		SetNodeUsing("EXECUTE_CAPTIVE",true);
		}
		else
		{
		SetNodeUsing("TEXTWINDOW",true);
		SetNodeUsing("REMOVE_OFFICER",false);
		int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
		SetFormatedText("TEXTWINDOW",LanguageConvertString(tmpLangFileID,"Prisoners"));
		LanguageCloseFile(tmpLangFileID);
		}
// added by MAXIMUS [for hiring captives] <--
	/* END MOD : Stone-D 01/08/2003 */
	break;

	case ISHOW_MODE_SUMSKILL:
		EnableString("skillLeadership");
		EnableString("skillFencing");
		EnableString("skillSailing");
		EnableString("skillAccuracy");
		EnableString("skillCannons");
		EnableString("skillGrappling");
		EnableString("skillRepair");
		EnableString("skillDefence");
		EnableString("skillCommerce");
		EnableString("skillSneak");
		SetNodeUsing("SUMMARYSTRINGS",true);
		SetNodeUsing("SUMMARYIMAGES",true);
	break;

	case ISHOW_MODE_CHRSKILL:
		EnableString("skillLeadership");
		EnableString("skillFencing");
		EnableString("skillSailing");
		EnableString("skillAccuracy");
		EnableString("skillCannons");
		EnableString("skillGrappling");
		EnableString("skillRepair");
		EnableString("skillDefence");
		EnableString("skillCommerce");
		EnableString("skillSneak");
		EnableString("CharacterName");
		SetNodeUsing("SUMMARYIMAGES",true);
	break;

	}
}

void SetSumSkillData()
{
	ref chref = _refCh;
	string skill;
	int n;
	for(n = 0; n < SKILL_MAX; n++)
	{
		skill = GetSkillName(n);
		int skillval = GetShipSkill(chref,skill);
		int modval = CalcCharacterSkill(chref,skill);
		int color = COLOR_NORMAL;
		if(skillVal < modval)									color = COLOR_RED;
		if(skillVal > modval)									color = COLOR_GREEN;
		if(skillVal == modval && skillVal==MAX_CHARACTER_SKILL)	color = COLOR_MONEY; // PB: Only if the captain has '10'
		if(skillVal==0)         								color = COLOR_GRAY;
		skill = "skill"+skill;
		GameInterface.strings.(skill) = skillval;
		ChangeStringColor(skill,color);
	}
}

void SetChrSkillData(ref chref)
{
	string skill;
	int n;
	for(n = 0; n < SKILL_MAX; n++)
	{
		skill = GetSkillName(n);
		int skillval = GetEffectiveSkill(chref,skill);
		int modval = CalcCharacterSkill(chref,skill);
		int color = COLOR_NORMAL;
		if(GetOfficerSkillFactor(chref,skill) == 2)	color = COLOR_GREEN; // PB: was if(skillVal >= modval)
		if(GetOfficerSkillFactor(chref,skill) == 1)	color = COLOR_MONEY; // PB: was if(skillVal <  modval)
		if(skillVal==0) color = COLOR_GRAY;
		skill = "skill"+skill;
		GameInterface.strings.(skill) = modval;
		ChangeStringColor(skill,color);
	}
// changed by MAXIMUS -->
	if(CheckAttribute(chref,"quest.officertype")==true) GameInterface.strings.CharacterName = chref.name + " " + chref.lastname + " - " + XI_ConvertString("S"+chref.quest.officertype); // MAXIMUS interface MOD
	else GameInterface.strings.CharacterName = chref.name + " " + chref.lastname + " - " + XI_ConvertString("SComrade-In-Arms");
//	GameInterface.strings.CharacterName = GetMyName(chref) + " - " + chref.quest.officertype;
// changed by MAXIMUS <--
}

void SetCaptiveData(ref chPsgn)
{
	GameInterface.strings.CharacterName = chPsgn.name + " " + chPsgn.lastname;
	GameInterface.strings.CharacterNation = XI_ConvertString(GetNationNameByType(sti(chPsgn.nation)));//Nations[sti(chPsgn.nation)].Name; // changed by MAXIMUS
	prisonRansomCost = GetPrisonRansomCost(chPsgn);
	GameInterface.strings.RansomCost = XI_ConvertString("Ransom") + ": " + MakeMoneyShow(prisonRansomCost,"",MONEY_DELIVER); // NK 05-04-16
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

// MAXIMUS interface MOD -->
	int x;ref tmpch;string tmpstr;
        if(nodName=="I_CHARACTER")
{ 
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_PASSENGERS_EXIT;
		EndCancelInterface(false);

	}
}
        if(nodName=="I_SHIP")
{ 
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_PASSENGERS_EXIT;
		EndCancelInterface(false);

	}
}
        if(nodName=="I_SHIPHOLD")
{ 
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_PASSENGERS_EXIT;
		EndCancelInterface(false);

	}
}
        if(nodName=="I_QUESTBOOK")
{ 
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_PASSENGERS_EXIT;
		EndCancelInterface(false);

	}
}
        if(nodName=="I_TRADEBOOK")
{ 
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_PASSENGERS_EXIT;
		EndCancelInterface(false);

	}
}
        if(nodName=="I_SHIPLOG")
{ 
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_PASSENGERS_EXIT;
		EndCancelInterface(false);

	}
}
        if(nodName=="I_NATIONS")
{ 
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_PASSENGERS_EXIT;
		EndCancelInterface(false);

	}
}
        if(nodName=="I_ITEMS")
{ 
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_PASSENGERS_EXIT;
		EndCancelInterface(false);

	}
}
// MAXIMUS interface MOD <--

	switch(nodName)
	{

	case "PASSENGERSLIST":
		if(comName=="activate")
		{
			if( GetSelectable("RELEASE_CAPTIVE") )	SetCurrentNode("RELEASE_CAPTIVE");
			else
			{
				if(prisonFlag==false)	{ProcessOfficerSet();}
			}
		}
		if(comName=="downstep")
		{
			// NK add ransom/release behavior and ransom case 05-04-16 -->
			if( GetSelectable("REMOVE_OFFICER") )	{SetCurrentNode("REMOVE_OFFICER");}
			else
			{
				if( GetSelectable("RELEASE_CAPTIVE") )	{SetCurrentNode("RELEASE_CAPTIVE");}
				else
				{
					if( GetSelectable("RANSOM_CAPTIVE") )	{SetCurrentNode("RANSOM_CAPTIVE");}
					else
					{
						if( GetSelectable("EXECUTE_CAPTIVE") )	{SetCurrentNode("EXECUTE_CAPTIVE");}
					}
				}
			}
		}
	break;

	case "RELEASE_CAPTIVE":
		if(comName=="downstep")
		{
			if( GetSelectable("REMOVE_OFFICER") )	{SetCurrentNode("REMOVE_OFFICER");}
			else
			{
				if( GetSelectable("RANSOM_CAPTIVE") )	{SetCurrentNode("RANSOM_CAPTIVE");}
				else
				{
					if( GetSelectable("EXECUTE_CAPTIVE") )	{SetCurrentNode("EXECUTE_CAPTIVE");}
				}
			}
		}
		else
		{
			if(comName=="upstep")
			{
				SetCurrentNode("PASSENGERSLIST");
			}
		}
	break;

	case "RANSOM_CAPTIVE":
		if(comName=="downstep")
		{
			if( GetSelectable("EXECUTE_CAPTIVE") )	{SetCurrentNode("EXECUTE_CAPTIVE");}
		}
		else
		{
			if(comName=="upstep")
			{
				if( GetSelectable("RELEASE_CAPTIVE") )	{SetCurrentNode("RELEASE_CAPTIVE");}
				else
				{
					SetCurrentNode("PASSENGERSLIST");
				}
			}
		}
	break;

	case "EXECUTE_CAPTIVE":
		if(comName=="upstep")
		{
			if( GetSelectable("RANSOM_CAPTIVE") )	{SetCurrentNode("RANSOM_CAPTIVE");}
			else
			{
				if( GetSelectable("RELEASE_CAPTIVE") )	{SetCurrentNode("RELEASE_CAPTIVE");}
				else
				{
					SetCurrentNode("PASSENGERSLIST");
				}
			}
		}
		// NK <--
	break;

	case "REMOVE_OFFICER":
		if(comName=="upstep")
		{
			if( GetSelectable("RELEASE_CAPTIVE") )	{SetCurrentNode("RELEASE_CAPTIVE");}
			else	{SetCurrentNode("PASSENGERSLIST");}
		}
	break;

	}
}

	/* BEGIN MOD : Stone-D 01/08/2003 */
// Doesn't give a rep hit yet. Don't want to deal with that until everything else is balanced ok.
// NK it does now. B12 it gave rank-based rep hit, now gives flat -5
void PressExecuteCaptive() // Sorry, no notes yet.
{
	if(prisonFlag!=true) return;
	int captiveIdx = GetPassenger(_refCh,nCurScrollNum);
	if(captiveIdx==-1) return;
	ref captiveCharacter = GetCharacter(captiveIdx);
	ref pchar = GetMainCharacter(); // KK
	// NK --> // KK -->
	ChangeCharacterReputation(pchar, -5); // NK disable this. Rep doesn't have bigger changes later, so no reason why rep chg should be level-based. makeint(-5.0 * (1.0 + (sqrt(stf(captiveCharacter.rank))-1.0)/5.0)));
	if (AUTO_SKILL_SYSTEM) {
	  AddCharacterExpChar(pchar, "Defence", sti(captiveCharacter.ransom));
	} else {
	  AddCharacterExp(pchar, sti(captiveCharacter.ransom));
	}
	// <-- KK // NK <--
	// NK - if( !GetRemovable(captiveCharacter) ) return;
	DeleteAttribute(captiveCharacter,"prisoned");
	DelFromScroll("PASSENGERSLIST",nCurScrollNum);
	SetCurrentNode("PASSENGERSLIST");
	for(int i=1;i<OFFICER_MAX;i++)
	{
		if(captiveIdx==GetOfficersIndex(_refCh,i))
		{
			XI_ChangeOfficer(i,-1);
		}
	}
	RemovePassenger(_refCh,captiveCharacter);
	if(CheckAttribute(captiveCharacter,"ransom")) DeleteAttribute(captiveCharacter,"ransom"); // NK
	LAi_KillCharacter(captiveCharacter);
	nCurScrollNum=-1;
}
	/* END MOD : Stone-D 01/08/2003 */

void FillSelectedScroll(string charType)
{
	int i;
	string faceName;
	string attributeName;
	string PsgAttrName;
	int _curCharIdx;
	ref _refCurChar;
	aref pRef;

	nCurScrollNum = -1;
	GameInterface.passengerslist.current = 0;
	makearef(pRef,_refCh.Fellows.Passengers);
	int nListSize;
	switch(charType)
	{
		case "prisoned":
			nListSize = sti(GetPassengersQuantity(_refCh)-GetNotCaptivePassengersQuantity(_refCh));
			showPassengers = false;
			showPrisoned = true;
		break;

		case "notprisoned":
			nListSize = GetNotCaptivePassengersQuantity(_refCh);
			showPassengers = true;
			showPrisoned = false;
		break;
	}
	nListSize = sti(GetPassengersQuantity(_refCh));
	GameInterface.passengerslist.NotUsed = 5;
	GameInterface.passengerslist.ListSize = nListSize;

	GameInterface.passengerslist.ImagesGroup.t0 = "EMPTYFACE";

	FillFaceList( "passengerslist.ImagesGroup", _refCh, 0 ); // officers
	FillFaceList( "passengerslist.ImagesGroup", _refCh, 2 ); // passengers

	GameInterface.passengerslist.BadTex1 = 0;
	GameInterface.passengerslist.BadPic1 = "emptyface";

	int logined = 0;
	for(i=0; i<nListSize; i++)
	{
		attributeName = "pic" + (i+1);
		PsgAttrName = "id" + (i+1);
		_curCharIdx = sti(pRef.(PsgAttrName));
		if(_curCharIdx!=-1)
		{
			if(showPrisoned && CheckAttribute(GetCharacter(_curCharIdx),"prisoned"))
			{
				attributeName = "pic" + (logined+1);
				PsgAttrName = "id" + (i+1);
				_curCharIdx = sti(pRef.(PsgAttrName));
				logined++;
				GameInterface.passengerslist.(attributeName).img1 = GetFacePicName(GetCharacter(_curCharIdx));
				GameInterface.passengerslist.(attributeName).tex1 = FindFaceGroupNum("passengerslist.ImagesGroup","FACE128_"+Characters[_curCharIdx].FaceID);
			}
			if(showPassengers && !CheckAttribute(GetCharacter(_curCharIdx),"prisoned"))
			{
				attributeName = "pic" + (logined+1);
				PsgAttrName = "id" + (i+1);
				_curCharIdx = sti(pRef.(PsgAttrName));
				logined++;
				GameInterface.passengerslist.(attributeName).img1 = GetFacePicName(GetCharacter(_curCharIdx));
				GameInterface.passengerslist.(attributeName).tex1 = FindFaceGroupNum("passengerslist.ImagesGroup","FACE128_"+Characters[_curCharIdx].FaceID);
			}
		}
		else
		{
			GameInterface.passengerslist.(attributeName).img1 = "emptyface";
			GameInterface.passengerslist.(attributeName).tex1 = 0;
		}
	}
}

void SetSelectDialogUsing(bool using)
{
	SetNodeUsing("SELECT_OFFICER_TYPE", using);
	SetNodeUsing("SELECT_FIRSTMATE", using);
	SetNodeUsing("SELECT_NAVIGATOR", using);
	SetNodeUsing("SELECT_GUNNER", using);
	SetNodeUsing("SELECT_BOATSWAIN", using);
	SetNodeUsing("SELECT_DOCTOR", using);
	SetNodeUsing("SELECT_CARPENTER", using);
	SetNodeUsing("SELECT_QMASTER", using);
	SetNodeUsing("SELECT_REMOVE", using);

	SetSelectable("PASSENGERSLIST", !using);
	SetSelectable("OFFICERSLIST", !using);
	SetSelectable("LEFTSCROLLBUTTON", !using);
	SetSelectable("RIGHTSCROLLBUTTON", !using);
	SetSelectable("CHANGE_OFFICER_ROLE", !using);

	if(using)
	{
		SetCurrentNode("SELECT_FIRSTMATE");
	}
	else
	{
		SetCurrentNode("PASSENGERSLIST");
	}
}

void ProcessChangeRole()
{
	SetSelectDialogUsing(true);
}

void SelectFirstMate()
{
	SetCharacterRole(OFFIC_TYPE_FIRSTMATE);
}

void SelectNavigator()
{
	SetCharacterRole(OFFIC_TYPE_NAVIGATOR);
}

void SelectGunner()
{
	SetCharacterRole(OFFIC_TYPE_CANNONEER);
}

void SelectBoatswain()
{
	SetCharacterRole(OFFIC_TYPE_BOATSWAIN);
}

void SelectDoctor()
{
	SetCharacterRole(OFFIC_TYPE_DOCTOR);
}

void SelectCarpenter()
{
	SetCharacterRole(OFFIC_TYPE_CARPENTER);
}

void SelectQMaster()
{
	SetCharacterRole(OFFIC_TYPE_QMASTER);
}

void SelectRemove()
{
	SetCharacterRole(OFFIC_TYPE_ABORDAGE);
}

void SelectAbort()
{
	SetSelectDialogUsing(false);
}

void SetCharacterRole(string officerType)
{
	string curName = GetCurrentNode();

	int idx = -1;
	if(nCurScrollNum >= 0)
	{
		idx = GetPassenger(_refCh, nCurScrollNum);
	}
	else
	{
		if(nFourImageNum >= 0)
		{
			idx = GetOfficersIndex(_refCh, nFourImageNum);
		}
	}

	if(idx >= 0)
	{
		ref chr = GetCharacter(idx);

		if(officerType == OFFIC_TYPE_ABORDAGE)
		{
			bool del = true;
			for(int i = 0; i < OFFICER_MAX; i++)
			{
				if(idx == GetOfficersIndex(_refCh, i))
				{
					chr.quest.officertype = OFFIC_TYPE_ABORDAGE;
					del = false;
					break;
				}
			}

			if(del && CheckAttribute(chr, "quest.officertype"))
			{
				DeleteAttribute(chr, "quest.officertype");
			}
		}
		else
		{
			chr.quest.officertype = officerType;
		}

		SetChrSkillData(chr);
	}

	SetSelectDialogUsing(false);
}
