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
int ourQty;

void InitInterface_RR(string iniName,ref pCharacter,ref enemyCh)
{
	int i;
	string cannonsTransfer;
	MainChar = GetMainCharacter();
	FillCharactersList(pCharacter, enemyCh);

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
		GameInterface.title = "titleAbordageCannons";
		cannonsTransfer = XI_ConvertString("Cannons exchange");
	} else {
		newFriend = GetCharacter(nCompanionIndex);
		GameInterface.title = "titleTransferCannons";
		cannonsTransfer = XI_ConvertString("Cannons exchange");
	}
// <-- KK KK

	bBeParty = false;
	for(i=1;i<OFFICER_MAX  ;i++)	{if( GetOfficersIndex (pCharacter,i)>=0 ) bBeParty = true; break;}
	for(i=1;i<COMPANION_MAX;i++)	{if( GetCompanionIndex(pCharacter,i)>=0 ) bBeParty = true; break;}

    if(bAnimation && bNewInterface) iniName = "RESOURCE\INI\NEW_INTERFACES\ANIMATION\transfer_cannons.ini";
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
					curEnemyName = XI_ConvertString("Dead") + " " + XI_ConvertString("s"+"captain");
					SetNewPicture("ENEMYPICT", "interfaces\portraits\128\face_skull.tga");
					//CreateString(true,"EnemyName",XI_ConvertString("Dead") + " " + XI_ConvertString("captain"),FONT_NORMAL,COLOR_NORMAL,478,170,SCRIPT_ALIGN_CENTER,1.0);
				break;

			// TIH --> changed to be less confusing Jul18'06
				// default:
				//curEnemyName = XI_ConvertString("No Captain Assigned");
// KK -->
				if (bNewInterface)
					CreateImage("enemyFace","EMPTYFACE","emptyface_new",348,39,476,167);
				else
					CreateImage("enemyFace","EMPTYFACE","emptyface",348,39,476,167);
// <-- KK
				//CreateString(true,"EnemyName",XI_ConvertString("No Captain Assigned"),FONT_NORMAL,COLOR_NORMAL,478,170,SCRIPT_ALIGN_CENTER,1.0);

			/* original method
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

	CreateString(true,"MaxCaliberus","",FONT_NORMAL,COLOR_NORMAL,100,450,SCRIPT_ALIGN_CENTER,0.8); // MAXIMUS
	CreateString(true,"CurCaliberus","",FONT_NORMAL,COLOR_NORMAL,100,470,SCRIPT_ALIGN_CENTER,0.8); // MAXIMUS

	CreateString(true,"MyHull","",FONT_NORMAL,COLOR_NORMAL,92,260,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"MyRig","",FONT_NORMAL,COLOR_NORMAL,92,298,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"MyCrew","",FONT_NORMAL,COLOR_NORMAL,92,336,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"MyCannons","",FONT_NORMAL,COLOR_NORMAL,92,374,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"EnemyHull","",FONT_NORMAL,COLOR_NORMAL,548,260,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"EnemyRig","",FONT_NORMAL,COLOR_NORMAL,548,298,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"EnemyCrew","",FONT_NORMAL,COLOR_NORMAL,548,336,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"EnemyCannons","",FONT_NORMAL,COLOR_NORMAL,548,374,SCRIPT_ALIGN_RIGHT,1.0);

	CreateString(true,"MaxCaliberthem","",FONT_NORMAL,COLOR_NORMAL,540,450,SCRIPT_ALIGN_CENTER,0.8); // MAXIMUS cannons MOD
	CreateString(true,"CurCaliberthem","",FONT_NORMAL,COLOR_NORMAL,540,470,SCRIPT_ALIGN_CENTER,0.8); // MAXIMUS cannons MOD

	CreateString(true,"Mincrewwarn","",FONT_NORMAL,COLOR_NORMAL,320,445,SCRIPT_ALIGN_CENTER,0.8); // NK

    CreateString(true,"HelpString","",FONT_NORMAL,COLOR_NORMAL,320,420,SCRIPT_ALIGN_CENTER,0.8); // MAXIMUS

	CreateString(true,"MyFront","",FONT_BOLD_NUMBERS,COLOR_NORMAL,250,262,SCRIPT_ALIGN_RIGHT,0.8);
	CreateString(true,"EnFront","",FONT_BOLD_NUMBERS,COLOR_NORMAL,390,262,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Front","",FONT_NORMAL,COLOR_NORMAL,320,266,SCRIPT_ALIGN_CENTER,0.8);

	CreateString(true,"MyLeftArc","",FONT_BOLD_NUMBERS,COLOR_NORMAL,250,302,SCRIPT_ALIGN_RIGHT,0.8);
	CreateString(true,"EnLeftArc","",FONT_BOLD_NUMBERS,COLOR_NORMAL,390,302,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Left","",FONT_NORMAL,COLOR_NORMAL,320,306,SCRIPT_ALIGN_CENTER,0.8);

	CreateString(true,"MyRightArc","",FONT_BOLD_NUMBERS,COLOR_NORMAL,250,342,SCRIPT_ALIGN_RIGHT,0.8);
	CreateString(true,"EnRightArc","",FONT_BOLD_NUMBERS,COLOR_NORMAL,390,342,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Right","",FONT_NORMAL,COLOR_NORMAL,320,346,SCRIPT_ALIGN_CENTER,0.8);

	CreateString(true,"MyBack","",FONT_BOLD_NUMBERS,COLOR_NORMAL,250,382,SCRIPT_ALIGN_RIGHT,0.8);
	CreateString(true,"EnBack","",FONT_BOLD_NUMBERS,COLOR_NORMAL,390,382,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Back","",FONT_NORMAL,COLOR_NORMAL,320,386,SCRIPT_ALIGN_CENTER,0.8);
	CreateString(true,"TransferCannons",cannonsTransfer,FONT_NORMAL,COLOR_NORMAL,320,235,SCRIPT_ALIGN_CENTER,1.0);//MAXIMUS

// --> MAXIMUS Interface MOD
	SetSelectable("EXIT_BUTTON",true);
	SetNodeUsing("VIDEOPIE",bAnimation && bNewInterface);
// <-- MAXIMUS Interface MOD

    SetVariable();

// MAXIMUS cannons MOD -->
	SetNodeUsing("CONFIRM_RECTANGLE",false);
	SetNodeUsing("TEXTWINDOW",false);
	SetNodeUsing("CONFIRM_YES_BUTTON",false);
	SetNodeUsing("CONFIRM_NO_BUTTON",false);
	SetNodeUsing("CHARACTER_YES_BUTTON",false);
	SetNodeUsing("CHARACTER_NO_BUTTON",false);
	SetNodeUsing("CONFIRM_YES1_BUTTON",false);
	SetNodeUsing("CONFIRM_NO1_BUTTON",false);
    SetNewPicture("CAN_PIC1", "interfaces\cannon.tga");
    SetNewPicture("CAN_PIC2", "interfaces\cannon.tga");
	SetNodeUsing("CAN_PIC1",false);
	SetNodeUsing("CAN_PIC2",false);
// MAXIMUS cannons MOD <--

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
    SetEventHandler("InterfaceCancel","ProcessCancelExit",0);
	
// MAXIMUS cannons MOD -->
	SetEventHandler("ChangerFrontLeft","ProcessChangeFrontLeft",0);
	SetEventHandler("ChangerFrontRight","ProcessChangeFrontRight",0);

	SetEventHandler("ChangerLeftArcLeft","ProcessChangeLeftArcLeft",0);
	SetEventHandler("ChangerLeftArcRight","ProcessChangeLeftArcRight",0);

	SetEventHandler("ChangerRightArcLeft","ProcessChangeRightArcLeft",0);
	SetEventHandler("ChangerRightArcRight","ProcessChangeRightArcRight",0);

	SetEventHandler("ChangerBackLeft","ProcessChangeBackLeft",0);
	SetEventHandler("ChangerBackRight","ProcessChangeBackRight",0);

	SetEventHandler("ExitPress","ProcessExit",0);
	SetEventHandler("ExitNo","ProcessExit_no",0);
	SetEventHandler("ExitYes","ProcessExit_yes",0);
// MAXIMUS cannons MOD <--

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

void FillCharactersList(ref ViewingCharacter, ref ViewingEnemy)
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
		if(CheckAttribute(newFriend,"index") && tempnum2==sti(newFriend.index)) continue;//MAXIMUS: companion will not be added
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

void CannonsYes(ref xi_refCharacter, ref tmpChar)
{
	xi_refCharacter.ship.Cannons.Borts.cannonf.curqty = sti(xi_refCharacter.ship.Cannons.Borts.cannonf.qty);
	xi_refCharacter.ship.Cannons.Borts.cannonb.curqty = sti(xi_refCharacter.ship.Cannons.Borts.cannonb.qty);
	xi_refCharacter.ship.Cannons.Borts.cannonl.curqty = sti(xi_refCharacter.ship.Cannons.Borts.cannonl.qty);
	xi_refCharacter.ship.Cannons.Borts.cannonr.curqty = sti(xi_refCharacter.ship.Cannons.Borts.cannonr.qty);

	tmpChar.ship.Cannons.Borts.cannonf.curqty = sti(tmpChar.ship.Cannons.Borts.cannonf.qty);
	tmpChar.ship.Cannons.Borts.cannonb.curqty = sti(tmpChar.ship.Cannons.Borts.cannonb.qty);
	tmpChar.ship.Cannons.Borts.cannonl.curqty = sti(tmpChar.ship.Cannons.Borts.cannonl.qty);
	tmpChar.ship.Cannons.Borts.cannonr.curqty = sti(tmpChar.ship.Cannons.Borts.cannonr.qty);
}

void CannonsNo(ref xi_refCharacter, ref tmpChar)
{
	xi_refCharacter.ship.Cannons.Borts.cannonf.qty = sti(xi_refCharacter.ship.Cannons.Borts.cannonf.curqty);
	xi_refCharacter.ship.Cannons.Borts.cannonb.qty = sti(xi_refCharacter.ship.Cannons.Borts.cannonb.curqty);
	xi_refCharacter.ship.Cannons.Borts.cannonl.qty = sti(xi_refCharacter.ship.Cannons.Borts.cannonl.curqty);
	xi_refCharacter.ship.Cannons.Borts.cannonr.qty = sti(xi_refCharacter.ship.Cannons.Borts.cannonr.curqty);

	tmpChar.ship.Cannons.Borts.cannonf.qty = sti(tmpChar.ship.Cannons.Borts.cannonf.curqty);
	tmpChar.ship.Cannons.Borts.cannonb.qty = sti(tmpChar.ship.Cannons.Borts.cannonb.curqty);
	tmpChar.ship.Cannons.Borts.cannonl.qty = sti(tmpChar.ship.Cannons.Borts.cannonl.curqty);
	tmpChar.ship.Cannons.Borts.cannonr.qty = sti(tmpChar.ship.Cannons.Borts.cannonr.curqty);
}

void SetVariable()
{
	ref tmpChar = refEnemyCharacter;
	if(nCompanionIndex!=-1) tmpChar = GetCharacter(nCompanionIndex);

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

    GameInterface.strings.MyShipType = XI_ConvertString(shipRef.SName);
    GameInterface.strings.MyShipName = xi_refCharacter.ship.Name;

	if(IsMainCharacter(xi_refCharacter) && CheckAttribute(xi_refCharacter,"title") && xi_refCharacter.title!="") bShown = true;
	else bShown = false;
	if(bShown) GameInterface.strings.MyName = GetMyRespectfullyName(xi_refCharacter);
	else GameInterface.strings.MyName = GetMySimpleName(xi_refCharacter);

	SetNewPicture("FACEPICT", "interfaces\portraits\128\face_" + xi_refCharacter.FaceId + ".tga");

	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"exp",0);
	oldIndex = -1;

	CannonsYes(xi_refCharacter, tmpChar);
	WasChangeData();
}

void WasChangeData()
{
	ref tmpChar = refEnemyCharacter;
	if(nCompanionIndex!=-1) tmpChar = GetCharacter(nCompanionIndex);

	ref shipRef = GetShipByType(GetCharacterShipType(xi_refCharacter)); // PS
	aref arship; makearef(arship, xi_refCharacter.ship); // PRS3
	GameInterface.pictures.myShip.tex = GetShipTextureName(sti(shipRef.index)); // PS
	GameInterface.pictures.myShip.pic = GetShipPicName(sti(shipRef.index)); // PS
	GameInterface.strings.MyShipType = XI_ConvertString(shipRef.Sname); // PS
	GameInterface.strings.MyHull = makeint(xi_refCharacter.ship.HP);
	GameInterface.strings.MyRig = makeint(xi_refCharacter.ship.SP);
	GameInterface.strings.MyCrew = GetCrewQuantity(xi_refCharacter)+"/"+GetMaxCrewQuantity(xi_refCharacter);
	GameInterface.strings.MyCannons = GetLocalShipAttrib(arship, &shipRef, "CurCanQty"); //NK can qty 05-04-18 shipRef.CannonsQuantity;
	GameInterface.strings.MaxCaliberus = XI_ConvertString("MaxCaliber") + ": " + GetLocalShipAttrib(arship, &shipRef, "MaxCaliber");
	GameInterface.strings.CurCaliberus = XI_ConvertString("CurCaliber") + ": " + GetCannonCaliber(GetCaracterShipCannonsType(xi_refCharacter));

	GameInterface.strings.MyFront = GetCannonArcQty(xi_refCharacter, 0);
	GameInterface.strings.MyLeftArc = GetCannonArcQty(xi_refCharacter, 3);
	GameInterface.strings.MyRightArc = GetCannonArcQty(xi_refCharacter, 1);
	GameInterface.strings.MyBack = GetCannonArcQty(xi_refCharacter, 2);

	shipRef = GetShipByType(GetCharacterShipType(tmpChar)); // PS
	makearef(arship, tmpChar.ship); // PRS3
	GameInterface.pictures.enemyShip.tex = GetShipTextureName(sti(shipRef.index)); // PS
	GameInterface.pictures.enemyShip.pic = GetShipPicName(sti(shipRef.index)); // PS
	GameInterface.strings.EnemyShipType = XI_ConvertString(shipRef.sname); // PS
	GameInterface.strings.EnemyHull = makeint(tmpChar.ship.HP);
	GameInterface.strings.EnemyRig = makeint(tmpChar.ship.SP);
	GameInterface.strings.EnemyCrew = GetCrewQuantity(tmpChar)+"/"+GetMaxCrewQuantity(tmpChar);
	GameInterface.strings.EnemyCannons = GetLocalShipAttrib(arship, &shipRef, "CurCanQty"); //NK can qty 05-04-18 shipRef.CannonsQuantity;
	GameInterface.strings.MaxCaliberthem = XI_ConvertString("MaxCaliber") + ": " + GetLocalShipAttrib(arship, &shipRef, "MaxCaliber");
	GameInterface.strings.CurCaliberthem = XI_ConvertString("CurCaliber") + ": " + GetCannonCaliber(GetCaracterShipCannonsType(tmpChar));

	GameInterface.strings.EnFront = GetCannonArcQty(tmpChar, 0);
	GameInterface.strings.EnLeftArc = GetCannonArcQty(tmpChar, 3);
	GameInterface.strings.EnRightArc = GetCannonArcQty(tmpChar, 1);
	GameInterface.strings.EnBack = GetCannonArcQty(tmpChar, 2);

	GameInterface.strings.Front = XI_ConvertString("FrontArc");
	GameInterface.strings.Left = XI_ConvertString("LeftArc");
	GameInterface.strings.Right = XI_ConvertString("RightArc");
	GameInterface.strings.Back = XI_ConvertString("BackArc");
}

// MAXIMUS cannons MOD -->
void ProcessExit()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	ref tmpChar = refEnemyCharacter;
	if(nCompanionIndex!=-1) tmpChar = GetCharacter(nCompanionIndex);

	int Qty = sti(GetCannonCurQuantity(xi_refCharacter));
	int curQty = sti(GetCannonQuantity(xi_refCharacter)-Qty);
	
	int enQty = sti(GetCannonCurQuantity(tmpChar));
	int enCurQty = sti(GetCannonQuantity(tmpChar)-enQty);

	int ourCaliber = sti(GetCannonCaliber(GetCaracterShipCannonsType(xi_refCharacter)));
	int curCaliber = sti(GetCannonCaliber(GetCaracterShipCannonsType(tmpChar)));

	if(curQty>0)
	{
	    SetNodeUsing("CONFIRM_RECTANGLE",true);
	    SetNodeUsing("TEXTWINDOW",true);
	    SetNodeUsing("CONFIRM_YES_BUTTON",true);
	    SetNodeUsing("CONFIRM_NO_BUTTON",true);
	    SetNodeUsing("CAN_PIC",true);
	    SetNodeUsing("CAN_PIC1",true);
	    SetNodeUsing("CAN_PIC2",true);
	    SetCurrentNode("CONFIRM_NO_BUTTON");
	    SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "CONFIRM_NO_BUTTON");
	    SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "CONFIRM_YES_BUTTON");

	    if(ourCaliber==curCaliber) SetFormatedText("TEXTWINDOW",LanguageConvertString(tmpLangFileID,"Transfer cannons confirm1")+" "+GetCannonName(GetCaracterShipCannonsType(refEnemyCharacter)) + " - " + curQty + " " + XI_ConvertString("un") + ". "+LanguageConvertString(tmpLangFileID,"Transfer cannons confirm2")+" "+xi_refCharacter.ship.Name+"?");
	    if(ourCaliber>curCaliber) SetFormatedText("TEXTWINDOW",LanguageConvertString(tmpLangFileID,"Transfer cannons confirm1")+" "+GetCannonName(GetCaracterShipCannonsType(refEnemyCharacter)) + " - " + curQty + " " + XI_ConvertString("un") + ". "+LanguageConvertString(tmpLangFileID,"Transfer cannons confirm2")+" "+xi_refCharacter.ship.Name+"? "+LanguageConvertString(tmpLangFileID,"Buy cannons confirm2")+ " " +curCaliber+ " " +LanguageConvertString(tmpLangFileID,"Buy cannons confirm3"));
	    if(ourCaliber<curCaliber) SetFormatedText("TEXTWINDOW",LanguageConvertString(tmpLangFileID,"Transfer cannons confirm1")+" "+GetCannonName(GetCaracterShipCannonsType(refEnemyCharacter)) + " - " + curQty + " " + XI_ConvertString("un") + ". "+LanguageConvertString(tmpLangFileID,"Transfer cannons confirm2")+" "+xi_refCharacter.ship.Name+"? "+LanguageConvertString(tmpLangFileID,"Buy cannons confirm4")+ " " +curCaliber+ " " +LanguageConvertString(tmpLangFileID,"Buy cannons confirm3"));
	}
	else
	{
	    if(enCurQty>0)
	    {
	        SetNodeUsing("CONFIRM_RECTANGLE",true);
	        SetNodeUsing("TEXTWINDOW",true);
	        SetNodeUsing("CONFIRM_YES_BUTTON",true);
	        SetNodeUsing("CONFIRM_NO_BUTTON",true);
	        SetNodeUsing("CAN_PIC",true);
	        SetNodeUsing("CAN_PIC1",true);
	        SetNodeUsing("CAN_PIC2",true);
	        SetCurrentNode("CONFIRM_NO_BUTTON");
	        SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "CONFIRM_NO_BUTTON");
	        SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "CONFIRM_YES_BUTTON");
	
	        if(ourCaliber==curCaliber) SetFormatedText("TEXTWINDOW",LanguageConvertString(tmpLangFileID,"Transfer cannons confirm1")+" "+GetCannonName(GetCaracterShipCannonsType(xi_refCharacter)) + " - " + enCurQty + " " + XI_ConvertString("un") + ". "+LanguageConvertString(tmpLangFileID,"Transfer cannons confirm2")+" "+refEnemyCharacter.ship.Name+"?");
	        if(ourCaliber<curCaliber) SetFormatedText("TEXTWINDOW",LanguageConvertString(tmpLangFileID,"Transfer cannons confirm1")+" "+GetCannonName(GetCaracterShipCannonsType(xi_refCharacter)) + " - " + enCurQty + " " + XI_ConvertString("un") + ". "+LanguageConvertString(tmpLangFileID,"Transfer cannons confirm2")+" "+refEnemyCharacter.ship.Name+"? "+LanguageConvertString(tmpLangFileID,"Buy cannons confirm2")+ " " + ourCaliber + LanguageConvertString(tmpLangFileID,"Buy cannons confirm3"));
	        if(ourCaliber>curCaliber) SetFormatedText("TEXTWINDOW",LanguageConvertString(tmpLangFileID,"Transfer cannons confirm1")+" "+GetCannonName(GetCaracterShipCannonsType(xi_refCharacter)) + " - " + enCurQty + " " + XI_ConvertString("un") + ". "+LanguageConvertString(tmpLangFileID,"Transfer cannons confirm2")+" "+refEnemyCharacter.ship.Name+"? "+LanguageConvertString(tmpLangFileID,"Buy cannons confirm4")+ " " + ourCaliber + LanguageConvertString(tmpLangFileID,"Buy cannons confirm3"));
	    }
		else ProcessExit_Exit();
	}
	LanguageCloseFile(tmpLangFileID);
}

void ProcessExit_no()
{
	ref tmpChar = refEnemyCharacter;
	if(nCompanionIndex!=-1) tmpChar = GetCharacter(nCompanionIndex);
	CannonsNo(xi_refCharacter, tmpChar);

	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);

	SetNodeUsing("CONFIRM_RECTANGLE",false);
	SetNodeUsing("TEXTWINDOW",false);
	SetNodeUsing("CONFIRM_YES_BUTTON",false);
	SetNodeUsing("CONFIRM_NO_BUTTON",false);
	SetNodeUsing("CAN_PIC",false);
	SetNodeUsing("CAN_PIC1",false);
	SetNodeUsing("CAN_PIC2",false);

	ProcessExit_Exit();
}

void ProcessExit_yes()
{
	ref tmpChar = refEnemyCharacter;
	if(nCompanionIndex!=-1) tmpChar = GetCharacter(nCompanionIndex);

	int myQty = sti(GetCannonCurQuantity(xi_refCharacter));
	int myCurQty = sti(GetCannonQuantity(xi_refCharacter)-myQty);

	int enQty = sti(GetCannonCurQuantity(tmpChar));
	int enCurQty = sti(GetCannonQuantity(tmpChar)-enQty);

	int myCaliber = sti(GetCannonCaliber(GetCaracterShipCannonsType(xi_refCharacter)));
	int enCaliber = sti(GetCannonCaliber(GetCaracterShipCannonsType(tmpChar)));

    if(myCurQty>0)
	{
		if(myCaliber>enCaliber) SetCharacterCannonType(xi_refCharacter, GetCaracterShipCannonsType(tmpChar));
		else SetCharacterCannonType(xi_refCharacter, GetCaracterShipCannonsType(xi_refCharacter));
	}

    if(enCurQty>0)
	{
		if(enCaliber>myCaliber) SetCharacterCannonType(tmpChar, GetCaracterShipCannonsType(xi_refCharacter));
		else SetCharacterCannonType(tmpChar, GetCaracterShipCannonsType(tmpChar));
	}

	CannonsYes(xi_refCharacter, tmpChar);

	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);

	SetNodeUsing("CONFIRM_RECTANGLE",false);
	SetNodeUsing("TEXTWINDOW",false);
	SetNodeUsing("CONFIRM_YES_BUTTON",false);
	SetNodeUsing("CONFIRM_NO_BUTTON",false);
	SetNodeUsing("CAN_PIC",false);
	SetNodeUsing("CAN_PIC1",false);
	SetNodeUsing("CAN_PIC2",false);

	ProcessExit_Exit();
}

void ProcessExit_Exit()
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("InterfaceCancel","ProcessCancelExit");
	
	DelEventHandler("ChangerFrontLeft","ProcessChangeFrontLeft");
	DelEventHandler("ChangerFrontRight","ProcessChangeFrontRight");

	DelEventHandler("ChangerLeftArcLeft","ProcessChangeLeftArcLeft");
	DelEventHandler("ChangerLeftArcRight","ProcessChangeLeftArcRight");

	DelEventHandler("ChangerRightArcLeft","ProcessChangeRightArcLeft");
	DelEventHandler("ChangerRightArcRight","ProcessChangeRightArcRight");

	DelEventHandler("ChangerBackLeft","ProcessChangeBackLeft");
	DelEventHandler("ChangerBackRight","ProcessChangeBackRight");

	DelEventHandler("ExitPress","ProcessExit");
	DelEventHandler("ExitNo","ProcessExit_no");
	DelEventHandler("ExitYes","ProcessExit_yes");

	DelEventHandler("IEvnt_MouseClick","IProcMouseClick");
	DelEventHandler("ievnt_command","ProcessCommandExecute");

	interfaceResultCommand = RC_INTERFACE_TRANSFER_MAIN_RETURN;
	EndCancelInterface(true);
}
// MAXIMUS cannons MOD <--

void SetCharacterCannonType(ref rCharacter,int nCannonType)
{
	rCharacter.Ship.Cannons.Type = nCannonType;
}

void ProcessCancelExit()
{
// MAXIMUS cannons MOD -->
	ref tmpChar = refEnemyCharacter;
	if(nCompanionIndex!=-1) tmpChar = GetCharacter(nCompanionIndex);

	int myQty = sti(GetCannonCurQuantity(xi_refCharacter));
	int myCurQty = sti(GetCannonQuantity(xi_refCharacter)-myQty);

	int enQty = sti(GetCannonCurQuantity(tmpChar));
	int enCurQty = sti(GetCannonQuantity(tmpChar)-enQty);

    if(myCurQty>0 && enCurQty>0) ProcessExit();
	else ProcessExit_Exit();
// MAXIMUS cannons MOD <--
}

// MAXIMUS cannons MOD -->
void ProcessChangeFrontLeft()
{	
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");

	ref MyshipRef = GetShipByType(GetCharacterShipType(xi_refCharacter));
	aref myship; makearef(myship, xi_refCharacter.ship);

	if( GetLocalShipAttrib(myship, &MyshipRef, "MaxCaliber") < GetCannonCaliber(GetCaracterShipCannonsType(refEnemyCharacter)) )
	{
		DisableString("HelpString");
		EnableString("HelpString");
		GameInterface.strings.HelpString = LanguageConvertString(tmpLangFileID,"Bigcaliber");
	}
	else
	{
		DisableString("HelpString"); 
		if(GetCannonArcQty(xi_refCharacter, 0)<GetCannonArcMaxQty(xi_refCharacter,0))
		{
			int mych, ench;
			mych = GetCannonArcQty(xi_refCharacter, 0);
			if(GetCannonArcQty(refEnemyCharacter, 0)>0)
			{
				ench = GetCannonArcQty(refEnemyCharacter, 0);
				SetCannonArcQty(xi_refCharacter, 0, mych+1)
				SetCannonArcQty(refEnemyCharacter, 0, ench-1);
				WasChangeData();
			}
			else
			{
				if(GetCannonArcQty(refEnemyCharacter, 3)>0)
				{
					ench = GetCannonArcQty(refEnemyCharacter, 3);
					SetCannonArcQty(xi_refCharacter, 0, mych+1)
					SetCannonArcQty(refEnemyCharacter, 3, ench-1);
					WasChangeData();
				}
				else
				{
					if(GetCannonArcQty(refEnemyCharacter, 1)>0)
					{
						ench = GetCannonArcQty(refEnemyCharacter, 1);
						SetCannonArcQty(xi_refCharacter, 0, mych+1)
						SetCannonArcQty(refEnemyCharacter, 1, ench-1);
						WasChangeData();
					}
					else
					{
						if(GetCannonArcQty(refEnemyCharacter, 2)>0)
						{
							ench = GetCannonArcQty(refEnemyCharacter, 2);
							SetCannonArcQty(xi_refCharacter, 0, mych+1)
							SetCannonArcQty(refEnemyCharacter, 2, ench-1);
							WasChangeData();
						}
						else { EnableString("HelpString"); GameInterface.strings.HelpString = LanguageConvertString(tmpLangFileID,"NoCannons"); }
					}
				}
			}
		}
		else
		{
		    EnableString("HelpString"); GameInterface.strings.HelpString = LanguageConvertString(tmpLangFileID,"Enough");
		}
	}
	LanguageCloseFile(tmpLangFileID);
}

void ProcessChangeLeftArcLeft()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");

	ref MyshipRef = GetShipByType(GetCharacterShipType(xi_refCharacter));
	aref myship; makearef(myship, xi_refCharacter.ship);

	if( GetLocalShipAttrib(myship, &MyshipRef, "MaxCaliber") < GetCannonCaliber(GetCaracterShipCannonsType(refEnemyCharacter)) )
	{
		DisableString("HelpString");
		EnableString("HelpString");
		GameInterface.strings.HelpString = LanguageConvertString(tmpLangFileID,"Bigcaliber");
	}
	else
	{
		DisableString("HelpString"); 
		if(GetCannonArcQty(xi_refCharacter, 3)<GetCannonArcMaxQty(xi_refCharacter,3))
		{
			int mych, ench;
			mych = GetCannonArcQty(xi_refCharacter, 3);
			if(GetCannonArcQty(refEnemyCharacter, 3)>0)
			{
				ench = GetCannonArcQty(refEnemyCharacter, 3);
				SetCannonArcQty(xi_refCharacter, 3, mych+1)
				SetCannonArcQty(refEnemyCharacter, 3, ench-1);
				WasChangeData();
			}
			else
			{
				if(GetCannonArcQty(refEnemyCharacter, 1)>0)
				{
					ench = GetCannonArcQty(refEnemyCharacter, 1);
					SetCannonArcQty(xi_refCharacter, 3, mych+1)
					SetCannonArcQty(refEnemyCharacter, 1, ench-1);
					WasChangeData();
				}
				else
				{
					if(GetCannonArcQty(refEnemyCharacter, 2)>0)
					{
						ench = GetCannonArcQty(refEnemyCharacter, 2);
						SetCannonArcQty(xi_refCharacter, 3, mych+1)
						SetCannonArcQty(refEnemyCharacter, 2, ench-1);
						WasChangeData();
					}
					else
					{
						if(GetCannonArcQty(refEnemyCharacter, 0)>0)
						{
							ench = GetCannonArcQty(refEnemyCharacter, 0);
							SetCannonArcQty(xi_refCharacter, 3, mych+1)
							SetCannonArcQty(refEnemyCharacter, 0, ench-1);
							WasChangeData();
						}
						else { EnableString("HelpString"); GameInterface.strings.HelpString = LanguageConvertString(tmpLangFileID,"NoCannons"); }
					}
				}
			}
		}
		else
		{
		    EnableString("HelpString"); GameInterface.strings.HelpString = LanguageConvertString(tmpLangFileID,"Enough");
		}
	}
	LanguageCloseFile(tmpLangFileID);
}

void ProcessChangeRightArcLeft()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");

	ref MyshipRef = GetShipByType(GetCharacterShipType(xi_refCharacter));
	aref myship; makearef(myship, xi_refCharacter.ship);

	if( GetLocalShipAttrib(myship, &MyshipRef, "MaxCaliber") < GetCannonCaliber(GetCaracterShipCannonsType(refEnemyCharacter)) )
	{
		DisableString("HelpString");
		EnableString("HelpString");
		GameInterface.strings.HelpString = LanguageConvertString(tmpLangFileID,"Bigcaliber");
	}
	else
	{
		DisableString("HelpString"); 
		if(GetCannonArcQty(xi_refCharacter, 1)<GetCannonArcMaxQty(xi_refCharacter,1))
		{
			int mych, ench;
			mych = GetCannonArcQty(xi_refCharacter, 1);
			if(GetCannonArcQty(refEnemyCharacter, 1)>0)
			{
				ench = GetCannonArcQty(refEnemyCharacter, 1);
				SetCannonArcQty(xi_refCharacter, 1, mych+1)
				SetCannonArcQty(refEnemyCharacter, 1, ench-1);
				WasChangeData();
			}
			else
			{
				if(GetCannonArcQty(refEnemyCharacter, 2)>0)
				{
					ench = GetCannonArcQty(refEnemyCharacter, 2);
					SetCannonArcQty(xi_refCharacter, 1, mych+1)
					SetCannonArcQty(refEnemyCharacter, 2, ench-1);
					WasChangeData();
				}
				else
				{
					if(GetCannonArcQty(refEnemyCharacter, 0)>0)
					{
						ench = GetCannonArcQty(refEnemyCharacter, 0);
						SetCannonArcQty(xi_refCharacter, 1, mych+1)
						SetCannonArcQty(refEnemyCharacter, 0, ench-1);
						WasChangeData();
					}
					else
					{
						if(GetCannonArcQty(refEnemyCharacter, 3)>0)
						{
							ench = GetCannonArcQty(refEnemyCharacter, 3);
							SetCannonArcQty(xi_refCharacter, 1, mych+1)
							SetCannonArcQty(refEnemyCharacter, 3, ench-1);
							WasChangeData();
						}
						else { EnableString("HelpString"); GameInterface.strings.HelpString = LanguageConvertString(tmpLangFileID,"NoCannons"); }
					}
				}
			}
		}
		else
		{
		    EnableString("HelpString"); GameInterface.strings.HelpString = LanguageConvertString(tmpLangFileID,"Enough");
		}
	}
	LanguageCloseFile(tmpLangFileID);
}

void ProcessChangeBackLeft()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");

	ref MyshipRef = GetShipByType(GetCharacterShipType(xi_refCharacter));
	aref myship; makearef(myship, xi_refCharacter.ship);

	if( GetLocalShipAttrib(myship, &MyshipRef, "MaxCaliber") < GetCannonCaliber(GetCaracterShipCannonsType(refEnemyCharacter)) )
	{
		DisableString("HelpString");
		EnableString("HelpString");
		GameInterface.strings.HelpString = LanguageConvertString(tmpLangFileID,"Bigcaliber");
	}
	else
	{
		DisableString("HelpString"); 
		if(GetCannonArcQty(xi_refCharacter, 2)<GetCannonArcMaxQty(xi_refCharacter,2))
		{
			int mych, ench;
			mych = GetCannonArcQty(xi_refCharacter, 2);
			if(GetCannonArcQty(refEnemyCharacter, 2)>0)
			{
				ench = GetCannonArcQty(refEnemyCharacter, 2);
				SetCannonArcQty(xi_refCharacter, 2, mych+1)
				SetCannonArcQty(refEnemyCharacter, 2, ench-1);
				WasChangeData();
			}
			else
			{
				if(GetCannonArcQty(refEnemyCharacter, 0)>0)
				{
					ench = GetCannonArcQty(refEnemyCharacter, 0);
					SetCannonArcQty(xi_refCharacter, 2, mych+1)
					SetCannonArcQty(refEnemyCharacter, 0, ench-1);
					WasChangeData();
				}
				else
				{
					if(GetCannonArcQty(refEnemyCharacter, 3)>0)
					{
						ench = GetCannonArcQty(refEnemyCharacter, 3);
						SetCannonArcQty(xi_refCharacter, 2, mych+1)
						SetCannonArcQty(refEnemyCharacter, 3, ench-1);
						WasChangeData();
					}
					else
					{
						if(GetCannonArcQty(refEnemyCharacter, 1)>0)
						{
							ench = GetCannonArcQty(refEnemyCharacter, 1);
							SetCannonArcQty(xi_refCharacter, 2, mych+1)
							SetCannonArcQty(refEnemyCharacter, 1, ench-1);
							WasChangeData();
						}
						else { EnableString("HelpString"); GameInterface.strings.HelpString = LanguageConvertString(tmpLangFileID,"NoCannons"); }
					}
				}
			}
		}
		else
		{
		    EnableString("HelpString"); GameInterface.strings.HelpString = LanguageConvertString(tmpLangFileID,"Enough");
		}
	}
	LanguageCloseFile(tmpLangFileID);
}

void ProcessChangeFrontRight()
{
	DisableString("HelpString");
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");

	ref EnshipRef = GetShipByType(GetCharacterShipType(refEnemyCharacter));
	aref enship; makearef(enship, refEnemyCharacter.ship);

	if(GetCannonArcQty(refEnemyCharacter, 0)<GetCannonArcMaxQty(refEnemyCharacter,0))
	{
		if(GetCannonArcQty(xi_refCharacter, 0)!=0)
		{
		    int mych, ench;
		    mych = GetCannonArcQty(xi_refCharacter, 0);
		    ench = GetCannonArcQty(refEnemyCharacter, 0);
		    SetCannonArcQty(xi_refCharacter, 0, mych-1)
		    SetCannonArcQty(refEnemyCharacter, 0, ench+1);
		    WasChangeData();
		}
		else EnableString("HelpString"); GameInterface.strings.HelpString = LanguageConvertString(tmpLangFileID,"NoCannons");
	}
	else
	{
		EnableString("HelpString"); GameInterface.strings.HelpString = LanguageConvertString(tmpLangFileID,"Enough");
	}

	LanguageCloseFile(tmpLangFileID);
}

void ProcessChangeLeftArcRight()
{
	DisableString("HelpString");
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");

	ref EnshipRef = GetShipByType(GetCharacterShipType(refEnemyCharacter));
	aref enship; makearef(enship, refEnemyCharacter.ship);

	if(GetCannonArcQty(refEnemyCharacter, 3)<GetCannonArcMaxQty(refEnemyCharacter,3))
	{
		if(GetCannonArcQty(xi_refCharacter, 3)!=0)
		{
		    int mych, ench;
		    mych = GetCannonArcQty(xi_refCharacter, 3);
		    ench = GetCannonArcQty(refEnemyCharacter, 3);
		    SetCannonArcQty(xi_refCharacter, 3, mych-1)
		    SetCannonArcQty(refEnemyCharacter, 3, ench+1);
		    WasChangeData();
		}
		else EnableString("HelpString"); GameInterface.strings.HelpString = LanguageConvertString(tmpLangFileID,"NoCannons");
	}
	else
	{
		EnableString("HelpString"); GameInterface.strings.HelpString = LanguageConvertString(tmpLangFileID,"Enough");
	}

	LanguageCloseFile(tmpLangFileID);
}

void ProcessChangeRightArcRight()
{
	DisableString("HelpString");
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");

	ref EnshipRef = GetShipByType(GetCharacterShipType(refEnemyCharacter));
	aref enship; makearef(enship, refEnemyCharacter.ship);

	if(GetCannonArcQty(refEnemyCharacter, 1)<GetCannonArcMaxQty(refEnemyCharacter,1))
	{
		if(GetCannonArcQty(xi_refCharacter, 1)!=0)
		{
		    int mych, ench;
		    mych = GetCannonArcQty(xi_refCharacter, 1);
		    ench = GetCannonArcQty(refEnemyCharacter, 1);
		    SetCannonArcQty(xi_refCharacter, 1, mych-1)
		    SetCannonArcQty(refEnemyCharacter, 1, ench+1);
		    WasChangeData();
		}
		else EnableString("HelpString"); GameInterface.strings.HelpString = LanguageConvertString(tmpLangFileID,"NoCannons");
	}
	else
	{
		EnableString("HelpString"); GameInterface.strings.HelpString = LanguageConvertString(tmpLangFileID,"Enough");
	}

	LanguageCloseFile(tmpLangFileID);
}

void ProcessChangeBackRight()
{
	DisableString("HelpString");
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");

	ref EnshipRef = GetShipByType(GetCharacterShipType(refEnemyCharacter));
	aref enship; makearef(enship, refEnemyCharacter.ship);

	if(GetCannonArcQty(refEnemyCharacter, 2)<GetCannonArcMaxQty(refEnemyCharacter,2))
	{
		if(GetCannonArcQty(xi_refCharacter, 2)!=0)
		{
		    int mych, ench;
		    mych = GetCannonArcQty(xi_refCharacter, 2);
		    ench = GetCannonArcQty(refEnemyCharacter, 2);
		    SetCannonArcQty(xi_refCharacter, 2, mych-1)
		    SetCannonArcQty(refEnemyCharacter, 2, ench+1);
		    WasChangeData();
		}
		else EnableString("HelpString"); GameInterface.strings.HelpString = LanguageConvertString(tmpLangFileID,"NoCannons");
	}
	else
	{
		EnableString("HelpString"); GameInterface.strings.HelpString = LanguageConvertString(tmpLangFileID,"Enough");
	}

	LanguageCloseFile(tmpLangFileID);
}
// MAXIMUS cannons MOD <--

void ProcessCharacterChange(bool bRight)
{
	ref tmpChar = refEnemyCharacter;
	if(nCompanionIndex!=-1) tmpChar = GetCharacter(nCompanionIndex);

	int myQty = sti(GetCannonCurQuantity(xi_refCharacter));
	int myCurQty = sti(GetCannonQuantity(xi_refCharacter)-myQty);

	int enQty = sti(GetCannonCurQuantity(tmpChar));
	int enCurQty = sti(GetCannonQuantity(tmpChar)-enQty);

    if(myCurQty>0 && enCurQty>0) CharacterChangeExit(bRight);
	else SetNextParty(bRight);
}

void CharacterChangeExit(bool bRight)
{
	SetEventHandler("CharacterYes","CharacterExit_yes",1);
	SetEventHandler("CharacterNo","CharacterExit_no",1);

	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	ref tmpChar = refEnemyCharacter;
	if(nCompanionIndex!=-1) tmpChar = GetCharacter(nCompanionIndex);

	int Qty = sti(GetCannonCurQuantity(xi_refCharacter));
	int curQty = sti(GetCannonQuantity(xi_refCharacter)-Qty);
	
	int enQty = sti(GetCannonCurQuantity(tmpChar));
	int enCurQty = sti(GetCannonQuantity(tmpChar)-enQty);

	int ourCaliber = sti(GetCannonCaliber(GetCaracterShipCannonsType(xi_refCharacter)));
	int curCaliber = sti(GetCannonCaliber(GetCaracterShipCannonsType(tmpChar)));

	if(curQty>0)
	{
	    SetNodeUsing("CONFIRM_RECTANGLE",true);
	    SetNodeUsing("TEXTWINDOW",true);
	    SetNodeUsing("CHARACTER_YES_BUTTON",true);
	    SetNodeUsing("CHARACTER_NO_BUTTON",true);
	    SetNodeUsing("CAN_PIC",true);
	    SetNodeUsing("CAN_PIC1",true);
	    SetNodeUsing("CAN_PIC2",true);
	    SetCurrentNode("CHARACTER_NO_BUTTON");
	    SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "CHARACTER_YES_BUTTON");
	    SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "CHARACTER_NO_BUTTON");

	    if(ourCaliber==curCaliber) SetFormatedText("TEXTWINDOW",LanguageConvertString(tmpLangFileID,"Transfer cannons confirm1")+" "+GetCannonName(GetCaracterShipCannonsType(refEnemyCharacter)) + " - " + curQty + " " + XI_ConvertString("un") + ". "+LanguageConvertString(tmpLangFileID,"Transfer cannons confirm2")+" "+xi_refCharacter.ship.Name+"?");
	    if(ourCaliber>curCaliber) SetFormatedText("TEXTWINDOW",LanguageConvertString(tmpLangFileID,"Transfer cannons confirm1")+" "+GetCannonName(GetCaracterShipCannonsType(refEnemyCharacter)) + " - " + curQty + " " + XI_ConvertString("un") + ". "+LanguageConvertString(tmpLangFileID,"Transfer cannons confirm2")+" "+xi_refCharacter.ship.Name+"? "+LanguageConvertString(tmpLangFileID,"Buy cannons confirm2")+ " " +curCaliber+ " " +LanguageConvertString(tmpLangFileID,"Buy cannons confirm3"));
	    if(ourCaliber<curCaliber) SetFormatedText("TEXTWINDOW",LanguageConvertString(tmpLangFileID,"Transfer cannons confirm1")+" "+GetCannonName(GetCaracterShipCannonsType(refEnemyCharacter)) + " - " + curQty + " " + XI_ConvertString("un") + ". "+LanguageConvertString(tmpLangFileID,"Transfer cannons confirm2")+" "+xi_refCharacter.ship.Name+"? "+LanguageConvertString(tmpLangFileID,"Buy cannons confirm4")+ " " +curCaliber+ " " +LanguageConvertString(tmpLangFileID,"Buy cannons confirm3"));
	}
	else
	{
	    if(enCurQty>0)
	    {
	        SetNodeUsing("CONFIRM_RECTANGLE",true);
	        SetNodeUsing("TEXTWINDOW",true);
	        SetNodeUsing("CHARACTER_YES_BUTTON",true);
	        SetNodeUsing("CHARACTER_NO_BUTTON",true);
	        SetNodeUsing("CAN_PIC",true);
	        SetNodeUsing("CAN_PIC1",true);
	        SetNodeUsing("CAN_PIC2",true);
	        SetCurrentNode("CHARACTER_NO_BUTTON");
	        SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "CHARACTER_NO_BUTTON");
	        SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "CHARACTER_YES_BUTTON");
	
	        if(ourCaliber==curCaliber) SetFormatedText("TEXTWINDOW",LanguageConvertString(tmpLangFileID,"Transfer cannons confirm1")+" "+GetCannonName(GetCaracterShipCannonsType(xi_refCharacter)) + " - " + enCurQty + " " + XI_ConvertString("un") + ". "+LanguageConvertString(tmpLangFileID,"Transfer cannons confirm2")+" "+refEnemyCharacter.ship.Name+"?");
	        if(ourCaliber<curCaliber) SetFormatedText("TEXTWINDOW",LanguageConvertString(tmpLangFileID,"Transfer cannons confirm1")+" "+GetCannonName(GetCaracterShipCannonsType(xi_refCharacter)) + " - " + enCurQty + " " + XI_ConvertString("un") + ". "+LanguageConvertString(tmpLangFileID,"Transfer cannons confirm2")+" "+refEnemyCharacter.ship.Name+"? "+LanguageConvertString(tmpLangFileID,"Buy cannons confirm2")+ " " + ourCaliber + LanguageConvertString(tmpLangFileID,"Buy cannons confirm3"));
	        if(ourCaliber>curCaliber) SetFormatedText("TEXTWINDOW",LanguageConvertString(tmpLangFileID,"Transfer cannons confirm1")+" "+GetCannonName(GetCaracterShipCannonsType(xi_refCharacter)) + " - " + enCurQty + " " + XI_ConvertString("un") + ". "+LanguageConvertString(tmpLangFileID,"Transfer cannons confirm2")+" "+refEnemyCharacter.ship.Name+"? "+LanguageConvertString(tmpLangFileID,"Buy cannons confirm4")+ " " + ourCaliber + LanguageConvertString(tmpLangFileID,"Buy cannons confirm3"));
	    }
		else
		{
			DelEventHandler("CharacterYes","CharacterExit_yes");
			DelEventHandler("CharacterNo","CharacterExit_no");

			SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);

			SetNodeUsing("CONFIRM_RECTANGLE",false);
			SetNodeUsing("TEXTWINDOW",false);
			SetNodeUsing("CHARACTER_YES_BUTTON",false);
			SetNodeUsing("CHARACTER_NO_BUTTON",false);
			SetNodeUsing("CAN_PIC",false);
			SetNodeUsing("CAN_PIC1",false);
			SetNodeUsing("CAN_PIC2",false);
	        SetCurrentNode("FRONT_CHANGER");
			SetNextParty(bRight);
			SetVariable();
		}
	}
	LanguageCloseFile(tmpLangFileID);
}

void CharacterExit_no()
{
	string Right = GetEventData();
	bool bRight = sti(Right);
	DelEventHandler("CharacterYes","CharacterExit_yes");
	DelEventHandler("CharacterNo","CharacterExit_no");

	ref tmpChar = refEnemyCharacter;
	if(nCompanionIndex!=-1) tmpChar = GetCharacter(nCompanionIndex);
	CannonsNo(xi_refCharacter, tmpChar);

	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);

	SetNodeUsing("CONFIRM_RECTANGLE",false);
	SetNodeUsing("TEXTWINDOW",false);
	SetNodeUsing("CHARACTER_YES_BUTTON",false);
	SetNodeUsing("CHARACTER_NO_BUTTON",false);
	SetNodeUsing("CAN_PIC",false);
	SetNodeUsing("CAN_PIC1",false);
	SetNodeUsing("CAN_PIC2",false);
	SetCurrentNode("FRONT_CHANGER");

	SetNextParty(bRight);
	SetVariable();
}

void CharacterExit_yes()
{
	string Right = GetEventData();
	bool bRight = sti(Right);
	DelEventHandler("CharacterYes","CharacterExit_yes");
	DelEventHandler("CharacterNo","CharacterExit_no");

	ref tmpChar = refEnemyCharacter;
	if(nCompanionIndex!=-1) tmpChar = GetCharacter(nCompanionIndex);

	int myQty = sti(GetCannonCurQuantity(xi_refCharacter));
	int myCurQty = sti(GetCannonQuantity(xi_refCharacter)-myQty);

	int enQty = sti(GetCannonCurQuantity(tmpChar));
	int enCurQty = sti(GetCannonQuantity(tmpChar)-enQty);

	int myCaliber = sti(GetCannonCaliber(GetCaracterShipCannonsType(xi_refCharacter)));
	int enCaliber = sti(GetCannonCaliber(GetCaracterShipCannonsType(tmpChar)));

    if(myCurQty>0)
	{
		if(myCaliber>enCaliber) SetCharacterCannonType(xi_refCharacter, GetCaracterShipCannonsType(tmpChar));
		else SetCharacterCannonType(xi_refCharacter, GetCaracterShipCannonsType(xi_refCharacter));
	}

    if(enCurQty>0)
	{
		if(enCaliber>myCaliber) SetCharacterCannonType(tmpChar, GetCaracterShipCannonsType(xi_refCharacter));
		else SetCharacterCannonType(tmpChar, GetCaracterShipCannonsType(tmpChar));
	}

	CannonsYes(xi_refCharacter, tmpChar);

	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);

	SetNodeUsing("CONFIRM_RECTANGLE",false);
	SetNodeUsing("TEXTWINDOW",false);
	SetNodeUsing("CHARACTER_YES_BUTTON",false);
	SetNodeUsing("CHARACTER_NO_BUTTON",false);
	SetNodeUsing("CAN_PIC",false);
	SetNodeUsing("CAN_PIC1",false);
	SetNodeUsing("CAN_PIC2",false);
	SetCurrentNode("FRONT_CHANGER");

	SetNextParty(bRight);
	SetVariable();
}

string nextChar;
void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	switch(nodName)
	{
	case "LEFTCHANGE_CHARACTER":
		if(comName=="click")
		{
			if(bBeParty) { CharacterChangeExit(false); nextChar = "false"; }
		}
	break;

	case "RIGHTCHANGE_CHARACTER":
		if(comName=="click")
		{
			if(bBeParty) { CharacterChangeExit(true); nextChar = "true"; }
		}
	break;

	case "CHARACTER_YES_BUTTON":
		if(comName=="click" || comName=="activate") { PostEvent("CharacterYes", 0, "s", nextChar); }
		if(comName=="deactivate") { PostEvent("CharacterNo", 0, "s", nextChar); }
	break;

	case "CHARACTER_NO_BUTTON":
		if(comName=="click" || comName=="activate") { PostEvent("CharacterNo", 0, "s", nextChar); }
		if(comName=="deactivate") { PostEvent("CharacterNo", 0, "s", nextChar); }
	break;
	}
}

// MAXIMUS cannons MOD -->
void IProcMouseClick()
{
	string nodName = GetEventData();
	int btnCode = GetEventData();

	if(nodName=="FRONT_CHANGER")
	{
		if(btnCode==0) ProcessChangeFrontLeft();
		if(btnCode==1) ProcessChangeFrontRight();
	}

	if(nodName=="LEFTARC_CHANGER")
	{
		if(btnCode==0) ProcessChangeLeftArcLeft();
		if(btnCode==1) ProcessChangeLeftArcRight();
	}

	if(nodName=="RIGHTARC_CHANGER")
	{
		if(btnCode==0) ProcessChangeRightArcLeft();
		if(btnCode==1) ProcessChangeRightArcRight();
	}

	if(nodName=="BACK_CHANGER")
	{
		if(btnCode==0) ProcessChangeBackLeft();
		if(btnCode==1) ProcessChangeBackRight();
	}
}
// MAXIMUS cannons MOD <--

ref GetMyCharacterRef()
{
	return refMyCharacter;
}

ref GetEnemyCharacterRef()
{
	return refEnemyCharacter;
}
