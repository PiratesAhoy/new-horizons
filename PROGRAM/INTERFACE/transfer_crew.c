ref refMyCharacter;
ref refEnemyCharacter;

bool bBeParty;
int curOfficer;
ref xi_refMainChar;
ref xi_refCharacter;
ref newFriend;

int oldIndex = -1;

int ListMax;
ref MainChar;

int nMyCharacterCompanionPlace = -1;
int nCompanionIndex = -1;

void InitInterface_RR(string iniName,ref pCharacter,ref enemyCh)
{
	int i;
	string crewTransfer;
	MainChar = GetMainCharacter();
	FillCharactersList(pCharacter);
	nCompanionIndex = sti(enemyCh.index); //PW: if two companions involved
	xi_refMainChar = GetMainCharacter();
	xi_refCharacter = pCharacter;

	//refMyCharacter = myCh;
	refMyCharacter = xi_refCharacter;
	refEnemyCharacter = enemyCh;

	if(CheckAttribute(pCharacter,"InterfaceParam.i1")) {
		nMyCharacterCompanionPlace = sti(pCharacter.InterfaceParam.i1);
		nCompanionIndex = GetCompanionIndex(pCharacter,nMyCharacterCompanionPlace);
	}

// KK -->
	newFriend = &NullCharacter;
	if (nCompanionIndex == -1) {
		GameInterface.title = "titleAbordageCrew";
		crewTransfer = XI_ConvertString("Crew Capture");
	} else {
		newFriend = GetCharacter(nCompanionIndex);
		GameInterface.title = "titleTransferCrew";
		crewTransfer = XI_ConvertString("Crew Transfer");
	}
// <-- KK

	bBeParty = false;
	for(i=1;i<OFFICER_MAX  ;i++)	{if( GetOfficersIndex (pCharacter,i)>=0 ) bBeParty = true; break;}
	for(i=1;i<COMPANION_MAX;i++)	{if( GetCompanionIndex(pCharacter,i)>=0 ) bBeParty = true; break;}

    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();//MAXIMUS: standard exit-string for exit-button

	ref shipRef = GetShipByType(GetCharacterShipType(refMyCharacter)); // PS
	CreateImage("myShip",GetShipTextureName(sti(shipRef.index)),GetShipPicName(sti(shipRef.index)),32,39,160,167); // PS
    //CreateImage("myFace",GetFaceGroupName(sti(refMyCharacter.index)),GetFacePictureName(sti(refMyCharacter.index)),164,39,292,167);
    CreateString(true,"MyShipType","",FONT_NORMAL,COLOR_NORMAL,96,70,SCRIPT_ALIGN_CENTER,0.8); // PS
    CreateString(true,"MyShipName","",FONT_SEADOGS,COLOR_NORMAL,177,202,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"MyName","",FONT_NORMAL,COLOR_NORMAL,166,170,SCRIPT_ALIGN_CENTER,1.0); // MAXIMUS

	shipRef = GetShipByType(GetCharacterShipType(refEnemyCharacter)); // PS
	CreateImage("enemyShip",GetShipTextureName(sti(shipRef.index)),GetShipPicName(sti(shipRef.index)),480,39,608,167); // PS
	string curEnemyName = XI_ConvertString("No Captain Assigned");
	if(nCompanionIndex<0) 
	{    	  
		if(CheckAttribute(refEnemyCharacter,"position"))
		{
			switch(refEnemyCharacter.position)
			{
				case "loser":
					curEnemyName = refEnemyCharacter.name + " " + refEnemyCharacter.lastname + " - " + XI_ConvertString("loser");
					CreateImage("enemyFace",GetFaceGroupName(sti(refEnemyCharacter.index)),GetFacePictureName(sti(refEnemyCharacter.index)),348,39,476,167);
					//CreateString(true,"EnemyName",refEnemyCharacter.name + " " + refEnemyCharacter.lastname + " - " + XI_ConvertString("loser"),FONT_NORMAL,COLOR_NORMAL,478,170,SCRIPT_ALIGN_CENTER,1.0);
				break;

				case "corpse":
					switch (LanguageGetLanguage())
					{
						case "Spanish":
							curEnemyName = XI_ConvertString("captain") + " " + strlower(XI_ConvertString("Dead"));
						break;
						curEnemyName = XI_ConvertString("Dead") + " " + strlower(XI_ConvertString("captain"));
					}
					SetNewPicture("ENEMYPICT", "interfaces\portraits\128\face_skull.tga");
					//CreateString(true,"EnemyName",XI_ConvertString("Dead") + " " + XI_ConvertString("captain"),FONT_NORMAL,COLOR_NORMAL,478,170,SCRIPT_ALIGN_CENTER,1.0);
				break;

			// TIH --> changed to be less confusing Jul18'06
				// default:
// KK -->
				if (bNewInterface)
					CreateImage("enemyFace","EMPTYFACE","emptyface_new",348,39,476,167);
				else
					CreateImage("enemyFace","EMPTYFACE","emptyface",348,39,476,167);
// <-- KK
				//CreateString(true,"EnemyName",XI_ConvertString("No Captain Assigned"),FONT_NORMAL,COLOR_NORMAL,478,170,SCRIPT_ALIGN_CENTER,1.0);

			/* no longer assigned an used methods - do not uncomment
				case "officer":
					CreateImage("enemyFace",GetFaceGroupName(sti(refEnemyCharacter.index)),GetFacePictureName(sti(refEnemyCharacter.index)),348,39,476,167);
				    CreateString(true,"EnemyName",refEnemyCharacter.name + " " + refEnemyCharacter.lastname + " - " + XI_ConvertString("officer"),FONT_NORMAL,COLOR_NORMAL,478,170,SCRIPT_ALIGN_CENTER,1.0);
				break;

				case "companion":
					CreateImage("enemyFace",GetFaceGroupName(sti(refEnemyCharacter.index)),GetFacePictureName(sti(refEnemyCharacter.index)),348,39,476,167);
					CreateString(true,"EnemyName",refEnemyCharacter.name + " " + refEnemyCharacter.lastname + " - " + XI_ConvertString("s"+"companion"),FONT_NORMAL,COLOR_NORMAL,478,170,SCRIPT_ALIGN_CENTER,1.0);
				break;

				case "captive":
					CreateImage("enemyFace",GetFaceGroupName(sti(refEnemyCharacter.index)),GetFacePictureName(sti(refEnemyCharacter.index)),348,39,476,167);
					CreateString(true,"EnemyName",refEnemyCharacter.name + " " + refEnemyCharacter.lastname + " - " + XI_ConvertString("Scaptive"),FONT_NORMAL,COLOR_NORMAL,478,170,SCRIPT_ALIGN_CENTER,1.0);
				break;
			*/
			// TIH <--
			}
		}
		else
		{
			curEnemyName = XI_ConvertString("Dead") + " " + XI_ConvertString("s"+"captain");
			SetNewPicture("ENEMYPICT", "interfaces\portraits\128\face_skull.tga");
			//CreateString(true,"EnemyName",XI_ConvertString("Dead") + " " + XI_ConvertString("captain"),FONT_NORMAL,COLOR_NORMAL,478,170,SCRIPT_ALIGN_CENTER,1.0);
			refEnemyCharacter.position = "corpse";
			refEnemyCharacter.status = "dead";
			//transferCaptain = false; // eliminated
		}
	}
	else
	{
		if(IsCompanion(newFriend) || IsOfficerCompanion(newFriend))
		{
			curEnemyName = newFriend.name + " " + newFriend.lastname + " - " + XI_ConvertString("s"+"companion");
			CreateImage("enemyFace",GetFaceGroupName(nCompanionIndex),GetFacePictureName(nCompanionIndex),348,39,476,167);
			//CreateString(true,"EnemyName",newFriend.name + " " + newFriend.lastname + " - " + XI_ConvertString("s"+"companion"),FONT_NORMAL,COLOR_NORMAL,478,170,SCRIPT_ALIGN_CENTER,1.0); // MAXIMUS
		}
	}
	CreateString(true,"EnemyName",curEnemyName,FONT_NORMAL,COLOR_NORMAL,478,170,SCRIPT_ALIGN_CENTER,1.0); // MAXIMUS

    CreateString(true,"EnemyShipType",XI_ConvertString(shipRef.SName),FONT_NORMAL,COLOR_NORMAL,544,70,SCRIPT_ALIGN_CENTER,0.8); // PS
    CreateString(true,"EnemyShipName",refEnemyCharacter.ship.Name,FONT_SEADOGS,COLOR_NORMAL,463,202,SCRIPT_ALIGN_CENTER,1.0);

	CreateString(true,"Mincrewus","",FONT_NORMAL,COLOR_NORMAL,100,475,SCRIPT_ALIGN_LEFT,0.8); // NK

	CreateString(true,"MyHull","",FONT_NORMAL,COLOR_NORMAL,92,260,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"MyRig","",FONT_NORMAL,COLOR_NORMAL,92,298,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"MyCrew","",FONT_NORMAL,COLOR_NORMAL,92,336,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"MyCannons","",FONT_NORMAL,COLOR_NORMAL,92,374,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"EnemyHull","",FONT_NORMAL,COLOR_NORMAL,548,260,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"EnemyRig","",FONT_NORMAL,COLOR_NORMAL,548,298,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"EnemyCrew","",FONT_NORMAL,COLOR_NORMAL,548,336,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"EnemyCannons","",FONT_NORMAL,COLOR_NORMAL,548,374,SCRIPT_ALIGN_RIGHT,1.0);

	CreateString(true,"Mincrewthem","",FONT_NORMAL,COLOR_NORMAL,540,475,SCRIPT_ALIGN_RIGHT,0.8); // NK

	CreateString(true,"Mincrewwarn","",FONT_NORMAL,COLOR_NORMAL,320,445,SCRIPT_ALIGN_CENTER,0.8); // NK

	CreateString(true,"LeftCrew","",FONT_BOLD_NUMBERS,COLOR_NORMAL,280,302,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"RightCrew","",FONT_BOLD_NUMBERS,COLOR_NORMAL,360,302,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"TransferCrew",crewTransfer,FONT_NORMAL,COLOR_NORMAL,320,260,SCRIPT_ALIGN_CENTER,1.0);//MAXIMUS

// --> MAXIMUS Interface MOD
	SetSelectable("EXIT_BUTTON",true);
// <-- MAXIMUS Interface MOD

	WasChangeData();
    SetVariable();

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
    SetEventHandler("InterfaceCancel","ProcessCancelExit",0);
	SetEventHandler("ChangerLeft","ProcessChangeLeft",0);
	SetEventHandler("ChangerRight","ProcessChangeRight",0);
	SetEventHandler("IEvnt_MouseClick","IProcMouseClick",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
}

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
	AddCharacterExp(xi_refCharacter,0);
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



	// ******* STEP 3/5: ADD COMPANIONS AND THEIR OFFICERS *******

	for (tempnum1 = 1; tempnum1 < COMPANION_MAX; tempnum1++)
	{
		tempnum2 = GetCompanionIndex(MainChar,tempnum1);
		if(tempnum2>=0 && IsTrader(&characters[tempnum2]) == true) continue;//MAXIMUS: such companion will not be added // KK
		if(nCompanionIndex != -1 && CheckAttribute(newFriend,"index") && tempnum2==sti(newFriend.index)) continue;//MAXIMUS: companion will not be added, PB: Fixed error log
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

	AddCharacterExp(xi_refCharacter,0);
}

void SetVariable()
{
	bool bShown = true;
	if(GetCompanionQuantity(GetMainCharacter())<COMPANION_MAX)
	{
		for(int i=1; i<COMPANION_MAX; i++)
		{
			if(bShown && nCompanionIndex==GetCompanionIndex(GetMainCharacter(),i)) bShown = false;
			else bShown = true;
			if(bShown && GetCompanionIndex(GetMainCharacter(),i)==GetCharacterIndex("Quest trader")) bShown = false;
			else bShown = true;
		}
	}

	SetNodeUsing("LEFTCHANGE_CHARACTER", bAbordageStarted && GetCompanionQuantity(GetMainCharacter())>1 && bShown);
	SetSelectable("LEFTCHANGE_CHARACTER", bAbordageStarted && GetCompanionQuantity(GetMainCharacter())>1 && bShown);
	SetNodeUsing("RIGHTCHANGE_CHARACTER", bAbordageStarted && GetCompanionQuantity(GetMainCharacter())>1 && bShown);
	SetSelectable("RIGHTCHANGE_CHARACTER", bAbordageStarted && GetCompanionQuantity(GetMainCharacter())>1 && bShown);
	ref shipRef = GetShipByType(GetCharacterShipType(xi_refCharacter));

    GameInterface.strings.MyShipType =   XI_ConvertString(shipRef.SName);
    GameInterface.strings.MyShipName =   xi_refCharacter.ship.Name;

	if(IsMainCharacter(xi_refCharacter) && CheckAttribute(xi_refCharacter,"title") && xi_refCharacter.title!="") bShown = true;
	else bShown = false;
	if(bShown) GameInterface.strings.MyName = GetMyRespectfullyName(xi_refCharacter);
	else GameInterface.strings.MyName = GetMySimpleName(xi_refCharacter);

	SetNewPicture("FACEPICT", "interfaces\portraits\128\face_" + xi_refCharacter.FaceId + ".tga");

	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"exp",0);
	oldIndex = -1;
	WasChangeData();
}

void WasChangeData()
{
	
	ref shipRef = GetShipByType(GetCharacterShipType(xi_refCharacter)); // PS
	aref arship; makearef(arship, xi_refCharacter.ship); // PRS3
	GameInterface.pictures.myShip.tex = GetShipTextureName(sti(shipRef.index)); // PS
	GameInterface.pictures.myShip.pic = GetShipPicName(sti(shipRef.index)); // PS
	GameInterface.strings.MyShipType = XI_ConvertString(shipRef.Sname); // PS
	GameInterface.strings.MyHull = makeint(xi_refCharacter.ship.HP);
	GameInterface.strings.MyRig = makeint(xi_refCharacter.ship.SP);
	GameInterface.strings.MyCrew = GetCrewQuantity(xi_refCharacter)+"/"+GetMaxCrewQuantity(xi_refCharacter);
	GameInterface.strings.MyCannons = GetLocalShipAttrib(arship, &shipRef, "CurCanQty"); //NK can qty 05-04-18 shipRef.CannonsQuantity;
	GameInterface.strings.Mincrewus= XI_ConvertString("Min Crew") + ": " + GetMinCrewQuantity(xi_refCharacter); // PRS3

	shipRef = GetShipByType(GetCharacterShipType(refEnemyCharacter)); // PS
	makearef(arship, refEnemyCharacter.ship); // PRS3
	GameInterface.pictures.enemyShip.tex = GetShipTextureName(sti(shipRef.index)); // PS
	GameInterface.pictures.enemyShip.pic = GetShipPicName(sti(shipRef.index)); // PS
	GameInterface.strings.EnemyShipType = XI_ConvertString(shipRef.sname); // PS
	GameInterface.strings.EnemyHull = makeint(refEnemyCharacter.ship.HP);
	GameInterface.strings.EnemyRig = makeint(refEnemyCharacter.ship.SP);
	GameInterface.strings.EnemyCrew = GetCrewQuantity(refEnemyCharacter)+"/"+GetMaxCrewQuantity(refEnemyCharacter);
	GameInterface.strings.EnemyCannons = GetLocalShipAttrib(arship, &shipRef, "CurCanQty"); //NK can qty 05-04-18 shipRef.CannonsQuantity;
	GameInterface.strings.Mincrewthem = XI_ConvertString("Min Crew") + ": " + GetMinCrewQuantity(refEnemyCharacter); // PRS3

	GameInterface.strings.LeftCrew = GetCrewQuantity(xi_refCharacter);
	GameInterface.strings.RightCrew = GetCrewQuantity(refEnemyCharacter);
}

void ProcessCancelExit()
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("InterfaceCancel","ProcessCancelExit");
	DelEventHandler("ChangerLeft","ProcessChangeLeft");
	DelEventHandler("ChangerRight","ProcessChangeRight");
	DelEventHandler("IEvnt_MouseClick","IProcMouseClick");
	DelEventHandler("ievnt_command","ProcessCommandExecute");
//    DelEventHandler("frame","ProcessFrame");

	interfaceResultCommand = RC_INTERFACE_TRANSFER_MAIN_RETURN;
	EndCancelInterface(true);
//	Exit();
}
/*
void Exit()
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("InterfaceCancel","ProcessCancelExit");
	DelEventHandler("ChangerLeft","ProcessChangeLeft");
	DelEventHandler("ChangerRight","ProcessChangeRight");
	DelEventHandler("IEvnt_MouseClick","IProcMouseClick");
	DelEventHandler("ievnt_command","ProcessCommandExecute");
    DelEventHandler("frame","ProcessFrame");

	EndCancelInterface(true);
}*/

void ProcessChangeLeft()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	if(GetCrewQuantity(refEnemyCharacter)<=0) return;
	if(GetMaxCrewQuantity(xi_refCharacter)<=GetCrewQuantity(xi_refCharacter)) return;
	// boal min crew on ship --> NK
/* ----> PW just transfer until no crew or max on left ship reached
// so block out all this checking below PW
	// added after build 11 by KAM -->
	ref MainChar = GetMainCharacter();
	
	// check attribute fix by dchaley sep-12-2004
	int tempnum = 0;
	if ( CheckAttribute(MainChar, "shiptransferinterface") )
		tempnum = MainChar.shiptransferinterface.calledfrominterface;
	// end tempnum/check attribute fix
	
	if (tempnum == 1 || IsCompanion(refEnemyCharacter))
	{
		if(GetCrewQuantity(refEnemyCharacter) <= GetMinCrewQuantity(refEnemyCharacter))
		{
			PlaySound("interface\knock.wav");
			GameInterface.strings.Mincrewwarn = LanguageConvertString(tmpLangFileID,"Not enough crew assigned"); // MAXIMUS
			return;
		}
	}
	else
	{	
		// <-- added after build 11 by KAM

		if(nCompanionIndex >= 0 || IsCompanion(refEnemyCharacter))
		{
			if(GetCrewQuantity(refEnemyCharacter) <= GetMinCrewQuantity(refEnemyCharacter)
					&& GetCrewQuantity(refEnemyCharacter) + GetCrewQuantity(xi_refCharacter) >
					  GetMinCrewQuantity(xi_refCharacter) + GetMinCrewQuantity(refEnemyCharacter)
				)
			{
//				PlaySound("interface\knock.wav");		// LDH 29Sep06 removed this awful noise
				GameInterface.strings.Mincrewwarn = LanguageConvertString(tmpLangFileID,"Min crew reached"); // MAXIMUS
				return;
			}

		}

		// added after build 11 by KAM -->
	}
	// <-- added after build 11 by KAM
*/ //<---- end of blocked out code
// PW then do the transfer - leaving the interface exit checks for minimum if you are keeping the ship
	GameInterface.strings.Mincrewwarn = ""; // NK
	// boal min crew on ship <-- NK
	AddCharacterCrew(xi_refCharacter,1);
	RemoveCharacterCrew(refEnemyCharacter,1);
	//SetVariable();
	WasChangeData();
}

void ProcessChangeRight()
{
	// boal min crew on ship -->
	//if(GetCrewQuantity(refMyCharacter)<=0) return;
	if(GetCrewQuantity(xi_refCharacter) <= GetMinCrewQuantity(xi_refCharacter))
	{
	    int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
//		PlaySound("interface\knock.wav");		// LDH 29Sep06 removed this awful noise
		GameInterface.strings.Mincrewwarn = LanguageConvertString(tmpLangFileID,"Min crew reached"); // MAXIMUS
		return;
	}
	GameInterface.strings.Mincrewwarn = ""; // NK
	// boal min crew on ship <--
	if(GetMaxCrewQuantity(refEnemyCharacter)<=GetCrewQuantity(refEnemyCharacter)) return;
	AddCharacterCrew(refEnemyCharacter,1);
	RemoveCharacterCrew(xi_refCharacter,1);
	//SetVariable();
	WasChangeData();
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	switch(nodName)
	{
	case "LEFTCHANGE_CHARACTER":
		if(comName=="click")
		{
			if(bBeParty)
			{
				WasChangeData();
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
				WasChangeData();
				SetNextParty(true);
				SetVariable();
			}
		}
	break;
	}
}

void IProcMouseClick()
{
	string nodName = GetEventData();
	int btnCode = GetEventData();

	if(nodName=="CREW_CHANGER")
	{
		if(btnCode==0) ProcessChangeLeft();
		if(btnCode==1) ProcessChangeRight();
	}
}

ref GetMyCharacterRef()
{
	return refMyCharacter;
}

ref GetEnemyCharacterRef()
{
	return refEnemyCharacter;
}
