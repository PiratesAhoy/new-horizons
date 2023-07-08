ref refMyCharacter;
ref refEnemyCharacter;
ref MainChar;				// KAM
string tmp;
int nCompanionIndex = -1;//MAXIMUS

void InitInterface_RRS(string iniName,ref myCh,ref enemyCh,string newCurNod)
{
	int i;
	MainChar = GetMainCharacter();	// KAM

	refMyCharacter = myCh;
	refEnemyCharacter = enemyCh;
	nCompanionIndex = sti(enemyCh.index);
    GameInterface.title = "titleTransfer";

    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();//MAXIMUS: standard exit-string for exit-button

	if(newCurNod=="")
	{
		RecalculateCargoLoad( refMyCharacter );
		RecalculateCargoLoad( refEnemyCharacter );
		DeleteAttribute(myCh,"InterfaceParam");
		for(i=1;i<COMPANION_MAX;i++)
		{
			if( GetCompanionIndex(myCh,i) == sti(enemyCh.index) )
			{
				myCh.InterfaceParam.i1 = i;
				break;
			}
		}
	}

	int picCharIndex = -1;

	// added after build 11 by KAM -->
	// check attribute fix by dchaley sep-12-2004, used by NK 04-09-16
    // second checkattribute fix by Swindler 2005-10-13: check whole attribute!
	int tempnum = 0;
	//if ( CheckAttribute(MainChar, "shiptransferinterface") )
	if(CheckAttribute(MainChar, "shiptransferinterface.donotallowcaptainchange")) tempnum = sti(MainChar.shiptransferinterface.donotallowcaptainchange);
	// end tempnum/check attribute fix
	SetSelectable("CHARACTERS_BUTTON",tempnum!=1 && CheckAttribute(myCh,"InterfaceParam.i1"));
	if(tempnum!=1 && CheckAttribute(myCh,"InterfaceParam.i1")) picCharIndex = GetCompanionIndex(refMyCharacter,sti(myCh.InterfaceParam.i1));
	else picCharIndex = sti(refEnemyCharacter.index);
	// <-- added after build 11 by KAM

	ref shipRef = GetShipByType(GetCharacterShipType(refMyCharacter)); // PS

// MAXIMUS cannons MOD -->
	aref myship; makearef(myship, refMyCharacter.ship);
	if( GetLocalShipAttrib(myship, &shipRef, "MaxCaliber") < GetCannonCaliber(GetCaracterShipCannonsType(refEnemyCharacter)) ) SetSelectable("CANNONS_BUTTON",false);
// MAXIMUS cannons MOD <--

	// Ship speed and turn added by MM...

	CreateImage("myShip",GetShipTextureName(sti(shipRef.index)),GetShipPicName(sti(shipRef.index)),32,39,160,167); // PS
    CreateImage("myFace",GetFaceGroupName(sti(refMyCharacter.index)),GetFacePictureName(sti(refMyCharacter.index)),164,39,292,167);
    CreateString(TRUE,"MyShipType",XI_ConvertString(shipRef.SName),FONT_NORMAL,COLOR_NORMAL,96,70,SCRIPT_ALIGN_CENTER,0.8); // PS
    CreateString(TRUE,"MyShipName",refMyCharacter.ship.Name,FONT_SEADOGS,COLOR_NORMAL,177,202,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"MyName","",FONT_NORMAL,COLOR_NORMAL,166,170,SCRIPT_ALIGN_CENTER,1.0); // MAXIMUS

	CreateString(TRUE,"MyMaxHull",GetCharacterShipHP(&refMyCharacter),FONT_NORMAL,COLOR_NORMAL,100,232,SCRIPT_ALIGN_LEFT,1.0); // PRS3
	CreateString(TRUE,"MyHull","",FONT_NORMAL,COLOR_NORMAL,100,266,SCRIPT_ALIGN_LEFT,1);
	CreateString(TRUE,"MyRig","",FONT_NORMAL,COLOR_NORMAL,100,302,SCRIPT_ALIGN_LEFT,1);
	CreateString(true,"MyShipSpeed","0",FONT_NORMAL,COLOR_NORMAL,100,336,SCRIPT_ALIGN_LEFT,1)
	CreateString(true,"MyShipManeuver","0",FONT_NORMAL,COLOR_NORMAL,100,370,SCRIPT_ALIGN_LEFT,1)
	CreateString(TRUE,"MyCannons","",FONT_NORMAL,COLOR_NORMAL,100,404,SCRIPT_ALIGN_LEFT,1);
	CreateString(TRUE,"MyCrew","",FONT_NORMAL,COLOR_NORMAL,100,438,SCRIPT_ALIGN_LEFT,1);
	CreateString(TRUE,"Mincrewus","",FONT_NORMAL,COLOR_NORMAL,50,480,SCRIPT_ALIGN_LEFT,0.8); // NK

	shipRef = GetShipByType(GetCharacterShipType(refEnemyCharacter)); // PS
	CreateImage("enemyShip",GetShipTextureName(sti(shipRef.index)),GetShipPicName(sti(shipRef.index)),480,39,608,167); // PS
	CreateImage("enemyFace",GetFaceGroupName(picCharIndex),GetFacePictureName(picCharIndex),348,39,476,167);
    CreateString(TRUE,"EnemyShipType",XI_ConvertString(shipRef.SName),FONT_NORMAL,COLOR_NORMAL,544,70,SCRIPT_ALIGN_CENTER,0.8); // PS
    CreateString(TRUE,"EnemyShipName",refEnemyCharacter.ship.Name,FONT_SEADOGS,COLOR_NORMAL,463,202,SCRIPT_ALIGN_CENTER,1.0);
	//MAXIMUS -->
	string curEnemyName = refEnemyCharacter.name + " " + refEnemyCharacter.lastname;
	if(IsCompanion(refEnemyCharacter) || IsOfficerCompanion(refEnemyCharacter)) curEnemyName +=  " - " + XI_ConvertString("s"+"companion");
    CreateString(true,"EnemyName",curEnemyName,FONT_NORMAL,COLOR_NORMAL,478,170,SCRIPT_ALIGN_CENTER,1.0); // MAXIMUS <--

	CreateString(TRUE,"EnemyMaxHull",GetCharacterShipHP(&refEnemyCharacter),FONT_NORMAL,COLOR_NORMAL,540,232,SCRIPT_ALIGN_RIGHT,1.0); // PRS3
	CreateString(TRUE,"EnemyHull","",FONT_NORMAL,COLOR_NORMAL,540,266,SCRIPT_ALIGN_RIGHT,1.0)
	CreateString(TRUE,"EnemyRig","",FONT_NORMAL,COLOR_NORMAL,540,302,SCRIPT_ALIGN_RIGHT,1.0)
	CreateString(true,"EnemyShipSpeed","0",FONT_NORMAL,COLOR_NORMAL,540,336,SCRIPT_ALIGN_RIGHT,1)
	CreateString(true,"EnemyShipManeuver","0",FONT_NORMAL,COLOR_NORMAL,540,370,SCRIPT_ALIGN_RIGHT,1)
	CreateString(TRUE,"EnemyCannons","",FONT_NORMAL,COLOR_NORMAL,540,404,SCRIPT_ALIGN_RIGHT,1.0)
	CreateString(TRUE,"EnemyCrew","",FONT_NORMAL,COLOR_NORMAL,540,438,SCRIPT_ALIGN_RIGHT,1.0)
	CreateString(TRUE,"Mincrewthem","",FONT_NORMAL,COLOR_NORMAL,590,480,SCRIPT_ALIGN_RIGHT,0.8)

	CreateString(TRUE,"Mincrewwarn","",FONT_NORMAL,COLOR_NORMAL,320,445,SCRIPT_ALIGN_CENTER,0.8); // NK
/* LDH comment this out for now as it breaks ship to ship transfer. Also, set iRealismMode to 0 - 12Jan09
// KK -->
	if (EnableLimitedShipClass()) {
		string icons = "ICONS";
		if (bNewInterface) icons = "ICONS_NEW";
		CreateImage("MyMaxShipClassIcon", icons, "ship class icon", 256, 149, 270, 163);
		CreateString(true, "MyMaxShipClass", GetShipMinClassForCharacter(refMyCharacter), FONT_BOLD_NUMBERS, COLOR_NORMAL, 276, 150, SCRIPT_ALIGN_CENTER, 0.4);
		CreateImage("EnemyMaxShipClassIcon", icons, "ship class icon", 436, 149, 450, 163);
		CreateString(true, "EnemyMaxShipClass", GetShipMinClassForCharacter(refEnemyCharacter), FONT_BOLD_NUMBERS, COLOR_NORMAL, 456, 150, SCRIPT_ALIGN_CENTER, 0.4);
	}
// <-- KK
*/
	SetVariable();

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
    SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("GoodsPress","GoodsProcess",0);
	SetEventHandler("CharactersPress","CharactersProcess",0);
	SetEventHandler("CrewPress","CrewProcess",0);
	SetEventHandler("SwapPress","SwapProcess",0);

	SetEventHandler("CannonsPress","CannonsProcess",0);

	SetEventHandler("UpPress","UpProcess",0);
	SetEventHandler("DownPress","DownProcess",0);
// added by MAXIMUS -->
	SetEventHandler("ExitPress","ProcessExit",0);
// added by MAXIMUS <--
// KK -->
	SetEventHandler("MaxShipClassYes", "CheckMaxShipClassYes", 0);
	SetEventHandler("MaxShipClassNo", "CheckMaxShipClassNo", 0);
// <-- KK

	SetNodeUsing("CONFIRM_RECTANGLE",false);
	SetNodeUsing("TEXTWINDOW",false);
	SetNodeUsing("CONFIRM_YES_BUTTON",false);
	SetNodeUsing("CONFIRM_NO_BUTTON",false);
	SetNodeUsing("REL_PIC",false);
	SetNodeUsing("EN_PIC",false);

// KK -->
	SetSelectable("GOODS_BUTTON",GetRemovable(enemyCh));
	SetSelectable("CHARACTERS_BUTTON",GetRemovable(enemyCh));
	// PW: Lock character transfer if two companion ships -->
	if (!IsMainCharacter(refMyCharacter) && !IsMainCharacter(refEnemyCharacter) )
	{
		SetSelectable("CHARACTERS_BUTTON", false);
		SendMessage(&GameInterface, "lsls", MSG_INTERFACE_MSG_TO_NODE, "CHARACTERS_BUTTON"  , 0, "Two Companion Ships");
	}
	// PW: Lock character transfer if two companion ships <--
	SetSelectable("CREW_BUTTON",GetRemovable(enemyCh));
	SetSelectable("CANNONS_BUTTON",GetRemovable(enemyCh));
// <-- KK

	// added after build 11 by KAM -->
	// check attribute fix by dchaley sep-12-2004, used by NK 04-09-16
	// second check attribute fix by Swindler 2005-10-13: check whole attribute!
    int tempnum2 = 0;
	//if ( CheckAttribute(MainChar, "shiptransferinterface") )
	if(CheckAttribute(MainChar, "shiptransferinterface.involvesberthedship")) tempnum = sti(MainChar.shiptransferinterface.involvesberthedship);
	// end tempnum/check attribute fix
	if(GetShipRemovable(refMyCharacter) && GetShipRemovable(refEnemyCharacter))
	{
		if(ProfessionalNavyNation() != UNKNOWN_NATION && GetRank(MainChar, GetServedNation()) < 7)
		{
			SetSelectable("SWAP_BUTTON", false);
		}
		else
		{
			SetSelectable("SWAP_BUTTON",tempnum2!=1);
		}
	}
	else
	{
		SetSelectable("SWAP_BUTTON", false);
	}
	// <-- added after build 11 by KAM

	if(newCurNod!="") NextDown(newCurNod);
	else NextDown("GOODS_BUTTON");
}

// added by MAXIMUS -->
void SetVariable()
{
	bool bShown = true;
	if(GetCompanionQuantity(GetMainCharacter())==2 && nCompanionIndex==GetCompanionIndex(GetMainCharacter(),1)) bShown = false;
	if(GetCompanionQuantity(GetMainCharacter())==2 && GetCompanionIndex(GetMainCharacter(),1)==GetCharacterIndex("Quest trader")) bShown = false;

	SetNodeUsing("LEFTCHANGE_CHARACTER", bAbordageStarted && GetCompanionQuantity(GetMainCharacter())>1 && bShown);
	SetSelectable("LEFTCHANGE_CHARACTER", bAbordageStarted && GetCompanionQuantity(GetMainCharacter())>1 && bShown);
	SetNodeUsing("RIGHTCHANGE_CHARACTER", bAbordageStarted && GetCompanionQuantity(GetMainCharacter())>1 && bShown);
	SetSelectable("RIGHTCHANGE_CHARACTER", bAbordageStarted && GetCompanionQuantity(GetMainCharacter())>1 && bShown);

	if(IsMainCharacter(refMyCharacter) && CheckAttribute(refMyCharacter,"title") && refMyCharacter.title!="") bShown = true;
	else bShown = false;
	if(bShown) GameInterface.strings.MyName = GetMyRespectfullyName(refMyCharacter);
	else GameInterface.strings.MyName = GetMySimpleName(refMyCharacter);
	WasChangeData();
}

void ProcessExit()
{
	ProcessCancelExit();
}
// added by MAXIMUS -->

void WasChangeData()
{
	ref shipRef = GetShipByType(GetCharacterShipType(refMyCharacter)); // PS
	aref arship; makearef(arship, refMyCharacter.ship); // PRS3
	GameInterface.pictures.myShip.tex       = GetShipTextureName(sti(shipRef.index)); // PS
	GameInterface.pictures.myShip.pic       = GetShipPicName(sti(shipRef.index)); // PS
	GameInterface.strings.MyShipType        = XI_ConvertString(shipRef.Sname); // PS
	GameInterface.strings.MyShipName        = refMyCharacter.ship.Name;
	GameInterface.strings.MyMaxHull         = GetCharacterShipHP(&refMyCharacter); // PRS3
	GameInterface.strings.MyHull            = MakeInt(refMyCharacter.ship.HP);
	GameInterface.strings.MyRig             = MakeInt(refMyCharacter.ship.SP);
	GameInterface.strings.MyShipSpeed       = FloatToString(stf(GetLocalShipAttrib(arship, &shipRef, "SpeedRate")),2); // PB
	GameInterface.strings.MyShipManeuver    = FloatToString(stf(GetLocalShipAttrib(arship, &shipRef, "TurnRate" )),2); // PB
	//GameInterface.strings.MyCrew            = MakeInt(refMyCharacter.ship.Crew.Quantity)+"/"+GetMaxCrewQuantity(&refMyCharacter); // PRS3
	GameInterface.strings.MyCrew            = MakeInt(refMyCharacter.ship.Crew.Quantity); // MM
	GameInterface.strings.MyCannons         = GetLocalShipAttrib(arship, &shipRef, "CurCanQty"); //NK can qty 05-04-18 shipRef.CannonsQuantity;
	//GameInterface.strings.Mincrewus         = XI_ConvertString("Min Crew") + ": " + GetMinCrewQuantity(&refMyCharacter); // PRS3
	GameInterface.strings.Mincrewus         = TranslateString("","Min/Max Crew")+": "+GetMinCrewQuantity(&refMyCharacter)+" / "+GetMaxCrewQuantity(&refMyCharacter); // MM

	shipRef = GetShipByType(GetCharacterShipType(refEnemyCharacter)); // PS
	makearef(arship, refEnemyCharacter.ship); // PRS3
	GameInterface.pictures.enemyShip.tex    = GetShipTextureName(sti(shipRef.index)); // PS
	GameInterface.pictures.enemyShip.pic    = GetShipPicName(sti(shipRef.index)); // PS
	GameInterface.strings.EnemyShipType     = XI_ConvertString(shipRef.Sname); // PS
	GameInterface.strings.EnemyShipName     = refEnemyCharacter.ship.Name;
	GameInterface.strings.EnemyMaxHull      = GetCharacterShipHP(&refEnemyCharacter); // PRS3
	GameInterface.strings.EnemyHull         = MakeInt(refEnemyCharacter.ship.HP);
	GameInterface.strings.EnemyRig          = MakeInt(refEnemyCharacter.ship.SP);
	GameInterface.strings.EnemyShipSpeed    = FloatToString(stf(GetLocalShipAttrib(arship, &shipRef, "SpeedRate")),2); // PB
	GameInterface.strings.EnemyShipManeuver = FloatToString(stf(GetLocalShipAttrib(arship, &shipRef, "TurnRate" )),2); // PB
	//GameInterface.strings.EnemyCrew         = makeint(refEnemyCharacter.ship.Crew.Quantity)+"/"+GetMaxCrewQuantity(&refEnemyCharacter); // PRS3
	GameInterface.strings.EnemyCrew         = makeint(refEnemyCharacter.ship.Crew.Quantity); // MM
	GameInterface.strings.EnemyCannons      = GetLocalShipAttrib(arship, &shipRef, "CurCanQty"); //NK can qty 05-04-18 shipRef.CannonsQuantity;
	//GameInterface.strings.Mincrewthem       = XI_ConvertString("Min Crew") + ": " + GetMinCrewQuantity(&refEnemyCharacter); // PRS3
	GameInterface.strings.Mincrewthem       = TranslateString("","Min/Max Crew")+": "+GetMinCrewQuantity(&refEnemyCharacter)+" / "+GetMaxCrewQuantity(&refEnemyCharacter); // MM
}

void ProcessCancelExit()
{
	ref tmpChRef;
	int n = -1;
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	if(CheckAttribute(refMyCharacter,"InterfaceParam.i1"))
	{
		n = GetCompanionIndex(refMyCharacter,sti(refMyCharacter.InterfaceParam.i1));
		// boal min crew on ship --> NK
		if(n >= 0 && GetRemovable(GetCharacter(n)))
		{
			if(GetCrewQuantity(refEnemyCharacter) < GetMinCrewQuantity(refEnemyCharacter) && GetCrewQuantity(refMyCharacter) > GetMinCrewQuantity(refMyCharacter)) // changed by MAXIMUS
			{
				PlaySound("interface\knock.wav");
				GameInterface.strings.Mincrewwarn = LanguageConvertString(tmpLangFileID,"Not enough crew assigned");
				return;
			}
		}
		// boal min crew on ship <-- NK
		DeleteAttribute(refMyCharacter,"InterfaceParam");
	}



	// added by KAM after build 11 -->
	// check attribute fix by dchaley sep-12-2004, used by NK 04-09-16
    // second check attribute fix by swindler 2005-10-13: check subattribute also!
	bool btmp2; // NK 05-04-14
	int tempnum1 = 0; int tempnum2 = 0;
	if ( CheckAttribute(MainChar, "shiptransferinterface") )
	{
        if (CheckAttribute(MainChar, "shiptransferinterface.donotallowcaptainchange"))
            tempnum1 = sti(MainChar.shiptransferinterface.donotallowcaptainchange);
		if (CheckAttribute(MainChar, "shiptransferinterface.involvesberthedship"))
            tempnum2 = sti(MainChar.shiptransferinterface.involvesberthedship);
		DeleteAttribute(MainChar,"shiptransferinterface");
	}
	// end tempnum/check attribute fix
	if (tempnum1 == 0 && tempnum2 == 0)
	{
	// <-- added by KAM after build 11


		if(n<0)
		{
			tmpChRef = Fantom_GetNextFantom();
			ISetShipAttributes(tmpChRef,refEnemyCharacter);
			SeaAI_SetOfficer2ShipAfterAbordage(tmpChRef,refEnemyCharacter);
			ShipDead(sti(tmpChRef.index),KILL_BY_OWNER,sti(refMyCharacter.index));
			DeleteAttribute(refEnemyCharacter,"ship");
			refEnemyCharacter.ship.type = SHIP_NOTUSED_TYPE_NAME; // PS
			Trace("ship sunk by n<0 in ProcessCancelExit");	// ccc jan06
		}
		else
		{
			if(n!=sti(refEnemyCharacter.index))
			{
				ISetShipAttributes(GetCharacter(n),refEnemyCharacter);
				SeaAI_SetOfficer2ShipAfterAbordage(GetCharacter(n),refEnemyCharacter);
				DeleteAttribute(refEnemyCharacter,"ship");
				refEnemyCharacter.ship.type = SHIP_NOTUSED_TYPE_NAME; // PS

				// added by KAM after build 11 -->
				// NK 05-04-14 checkattr
				btmp2 = CheckAttribute(Mainchar,"shiptransferinterface.calledfrominterface");
				if(btmp2) btmp2 = sti(Mainchar.shiptransferinterface.calledfrominterface);
				if (btmp2 == 1)
				{
					RemoveOfficersIndex(MainChar,sti(Characters[n].index));
					RemovePassenger(MainChar,GetCharacter(n));
				}
				// <-- added by KAM after build 11
				DeleteAttribute(MainChar,"shiptransferinterface");

				Trace("ship sunk by n!=sti in ProcessCancelExit");	// ccc bugsearch

			}
		}


	// added by KAM after build 11 -->
	}
	// <-- added by KAM after build 11


	if(bSeaActive==true)
	{
		interfaceResultCommand = RC_INTERFACE_TRANSFER_MAIN_EXIT;
		Exit();
	}
	else
	{
		PostEvent("LaunchIAfterFrame",1,"sl", "I_KAM_SHIPTRANSFER", 2);
		interfaceResultCommand = RC_INTERFACE_TRANSFER_MAIN_EXIT;
		EndCancelInterface(false);
	}

	// added by KAM after build 11 -->
	// NK bugfix 04-09-10 for some reason not seeing var Mainchar
	ref pc = GetMainCharacter();
	btmp2 = CheckAttribute(pc,"shiptransferinterface.calledfrominterface"); // NK 05-04-14 add checkattr
	if(btmp2) btmp2 = sti(pc.shiptransferinterface.calledfrominterface);
	if (btmp2 == 0)
	{
	// <-- added by KAM after build 11

		RefreshBattleInterface(true);
		if( CheckAttribute(&PeopleOnShip,"IsOnDeck") && sti(PeopleOnShip.IsOnDeck) )
		{
			PeopleOnShip.IsOnDeck = true;
		}

	// added by KAM after build 11 -->
	}
	// <-- added by KAM after build 11

	if(CheckAttribute(pc,"shiptransferinterface")) DeleteAttribute(pc,"shiptransferinterface");// TIH bug fix
	// NK <--

	// ccc jan06 to prevent shipsinking after swapping at sea "InterfaceParam" is being deleted here
	if(CheckAttribute(pc,"InterfaceParam")) DeleteAttribute(pc,"InterfaceParam");// TIH bug fix
	// ccc jan06 end
}

void Exit()
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("GoodsPress","GoodsProcess");
	DelEventHandler("CharactersPress","CharactersProcess");
	DelEventHandler("CrewPress","CrewProcess");
	DelEventHandler("SwapPress","SwapProcess");

	DelEventHandler("CannonsPress","CannonsProcess");

	DelEventHandler("UpPress","UpProcess");
	DelEventHandler("DownPress","DownProcess");
// added by MAXIMUS -->
	DelEventHandler("ExitPress","ProcessExit");
// added by MAXIMUS <--
// KK -->
	DelEventHandler("MaxShipClassYes", "CheckMaxShipClassYes");
	DelEventHandler("MaxShipClassNo", "CheckMaxShipClassNo");
// <-- KK

	EndCancelInterface(true);
}

void GoodsProcess()
{
	interfaceResultCommand = RC_INTERFACE_TRANSFER_START_GOODS;
	Exit();
}

void CharactersProcess()
{
	interfaceResultCommand = RC_INTERFACE_TRANSFER_START_CHARACTERS;
	Exit();
}

void CrewProcess()
{
	interfaceResultCommand = RC_INTERFACE_TRANSFER_START_CREW;
	Exit();
}

void CannonsProcess()
{
	interfaceResultCommand = RC_INTERFACE_TRANSFER_START_CANNONS;
	Exit();
}

void SwapProcess()
{
/* LDH comment this out for now as it breaks ship to ship transfer.  Also, set iRealismMode to 0 - 12Jan09
	if (EnableLimitedShipClass() && GetCharacterShipClass(refEnemyCharacter) < GetShipMinClassForCharacter(xi_refCharacter)) {
		SetNodeUsing("MSC_CONFIRM_RECTANGLE", true);
		SetNodeUsing("MSC_TEXTWINDOW", true);
		SetNodeUsing("MSC_CONFIRM_YES_BUTTON", true);
		SetNodeUsing("MSC_CONFIRM_NO_BUTTON", true);
		SetNodeUsing("MSC_SKILL_PIC", true);
		SetCurrentNode("MSC_CONFIRM_NO_BUTTON");
		SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "MSC_CONFIRM_NO_BUTTON");
		SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "MSC_CONFIRM_YES_BUTTON");
		SetFormatedText("MSC_TEXTWINDOW", TranslateString("", "This officer has too low Leadership and Sailing skills to command this ship. Assign anyway?"));
	} else { */
		CheckMaxShipClassYes();
//	}
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
		SetCurrentNode("SWAP_BUTTON");
	}
    // added after build 11 by KAM -->
	ref MainChar = GetMainCharacter();
    // --> Swindler 2005-10-13: shouldn't we test on whole attribute? And have a tempnum anyway?
	//if(CheckAttribute(MainChar,"shiptransferinterface")) int tempnum = MainChar.shiptransferinterface.calledfrominterface;
	int tempnum = 0;
	// no longer used
//    if (CheckAttribute(MainChar,"shiptransferinterface.calledfrominterface")) {
////        tempnum = MainChar.shiptransferinterface.calledfrominterface;
//        tempnum = sti(MainChar.shiptransferinterface.calledfrominterface);	// LDH - seemed to work ok before - 26Jan09
//    }
    // Swindler <--

// LDH Some notes on using the full copyattributes code that's commented out below and used in SeaAI_SwapShipsAttributes() - 10May09
// We have no problems swapping ships if there is no sea, for example, if we're in the shipyard or tavern.
// We can't swap ships if called from land and the sea is active, for example if we're on the dock.
// We don't have problems swapping ships if we do it from the battle interface swap icon when we're beside the other ship.
// Swapping ships after boarding works, it uses SeaAI_SwapShipsAttributes() which has full copyattributes.
// We have the same problem doing repairs on blots.  It only works if the sea is not active.
// It's likely the engine has pointers into the data and if we change the data the engine's pointers are wrong and it crashes.
// The real problem appears to be deleting blots, although they seem to copy fine in SwapProcessAtLand().

	// bSeaActive is true only if you're sailing
	// isEntity(&Sea) is true on the dock or sailing, but not in the tavern
	tempnum = isEntity(&Sea) && !bSeaActive;
	Trace("Transfer_main: Swap ships tempnum = " + tempnum + " ************************");

    if (tempnum == 1)
	{
		// This version needs to be used only if you're on the dock

        // --> original code by KAM, commented out by Swindler
        //aref arMyChrShip, arEnChrShip;
        //makearef (arMyChrShip,refMyCharacter.ship);
        //makearef (arEnChrShip,refEnemyCharacter.ship);
        //object TempShip;
        //CopyAttributes(&TempShip,arEnChrShip);
        //DeleteAttribute(arEnChrShip,"");			// --> causes CTD, don't know why
        //CopyAttributes(arEnChrShip,arMyChrShip);	// --> causes CTD, don't know why
        //DeleteAttribute(arMyChrShip,"");
        //CopyAttributes(arMyChrShip,TempShip);		// --> causes CTD, don't know why
        //DeleteAttribute(TempShip,"");
		// end original code by KAM <--

		// --> Swindler 2005-10-13: new code, copying each attribute of the ship
		//     with explicit calls
		// generate references to both ships...
		aref arMyChrShip, arEnChrShip;
		makearef (arMyChrShip,refMyCharacter.ship);
		makearef (arEnChrShip,refEnemyCharacter.ship);
		// ...and pass to new function
		SwapProcessAtLand(arMyChrShip, arEnChrShip);
        // Swindler <--
	}
	else
	{
// <-- added after build 11 by KAM

		// NK 04-17 lay up ships bugfix
		if(!CheckAttribute(refMyCharacter,"location.from_sea"))
		{
			if( CheckAttribute(refMyCharacter,"location.old_from_sea") )
			{
				if(refMyCharacter.location.old_from_sea != "")
				{
					refMyCharacter.location.from_sea = refMyCharacter.location.old_from_sea;
					SetFleetInTown(GetTownIDFromLocID(refMyCharacter.location.from_sea), "pchar"); // NK 05-04-02 WM/IT set fleet.
				}
				DeleteAttribute(refMyCharacter,"location.old_from_sea");
			}
		}
		if(refMyCharacter.location.from_sea == "")
		{
			if( CheckAttribute(refMyCharacter,"location.old_from_sea") )
			{
				if(refMyCharacter.location.old_from_sea != "")
				{
					refMyCharacter.location.from_sea = refMyCharacter.location.old_from_sea;
					SetFleetInTown(GetTownIDFromLocID(refMyCharacter.location.from_sea), "pchar"); // NK 05-04-02 WM/IT set fleet.
				}
				DeleteAttribute(refMyCharacter,"location.old_from_sea");
			}
		}
		if(!CheckAttribute(refMyCharacter,"location.from_sea") || refMyCharacter.location.from_sea == "")
		{
			if(GetCurrentTownID() != "")
			{
				refMyCharacter.location.from_sea = GetAttribute(GetCurrentTown(), "boarding.l1");
				SetFleetInTown(GetTownIDFromLocID(refMyCharacter.location.from_sea), "pchar");
			}
		}
		// NK <--
		//string tmp;

		SeaAI_SwapShipsAttributes(refMyCharacter, refEnemyCharacter);
		SeaAI_SwapShipAfterAbordage(refMyCharacter, refEnemyCharacter);
//		ReturnMyCrew(refMyCharacter, refEnemyCharacter);		// LDH commented out 10May09

		if(CheckAttribute(refMyCharacter,"InterfaceParam.i1"))
		{
			int cn = GetCompanionIndex(refMyCharacter,sti(refMyCharacter.InterfaceParam.i1));
			if(cn>=0 && cn!=sti(refEnemyCharacter.index))
			{
				ISetShipAttributes(GetCharacter(cn),refEnemyCharacter);
			}

		// ccc jan06 to prevent shipsinking after swapping at sea "InterfaceParam" must NOT be deleted
		// ccc jan06   DeleteAttribute(refMyCharacter,"InterfaceParam");
		}

// added after build 11 by KAM -->
	}
// <-- added after build 11 by KAM

    // --> Swindler: Don't think, that should be called here, because if player
    // swaps ship more than once without leaving the screen, function would go
    // into the wrong node from 2nd time on, causing a CTD again.
	//DeleteAttribute(MainChar,"shiptransferinterface");
	WasChangeData();

	// PB: To make sure this is gone -->
	DeleteAttribute(MainChar, "Ship.Sink");
	DeleteAttribute(MainChar, "Ship.Sails.Delay");
	DeleteAttribute(MainChar, "Ship.Tack");
	// PB: To make sure this is gone <--
}

void CheckMaxShipClassNo()
{
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
	SetNodeUsing("MSC_CONFIRM_RECTANGLE", false);
	SetNodeUsing("MSC_TEXTWINDOW", false);
	SetNodeUsing("MSC_CONFIRM_YES_BUTTON", false);
	SetNodeUsing("MSC_CONFIRM_NO_BUTTON", false);
	SetNodeUsing("MSC_SKILL_PIC", false);
	SetCurrentNode("SWAP_BUTTON");
}
// <-- KK

void UpProcess()
{
	tmp = NextUp(GetCurrentNode());
	SetCurrentNode(tmp);
}

void DownProcess()
{
	tmp = NextDown(GetCurrentNode());
	SetCurrentNode(tmp);
}

string NextUp(string curNod)
{
	switch(curNod)
	{
	case "SWAP_BUTTON":
		if(GetSelectable("CANNONS_BUTTON")==true) return "CANNONS_BUTTON";
		else return NextUp("CANNONS_BUTTON");
		break;
	case "CANNONS_BUTTON":
		if(GetSelectable("CREW_BUTTON")==true) return "CREW_BUTTON";
		else return NextUp("CREW_BUTTON");
		break;
	case "CREW_BUTTON":
		if(GetSelectable("CHARACTERS_BUTTON")==true) return "CHARACTERS_BUTTON";
		else return NextUp("CHARACTERS_BUTTON");
		break;
	case "CHARACTERS_BUTTON":
		if(GetSelectable("GOODS_BUTTON")==true)	return "GOODS_BUTTON";
		else return NextUp("GOODS_BUTTON");
		break;
	}
	return GetCurrentNode();
}

string NextDown(string curNod)
{
	switch(curNod)
	{
	case "GOODS_BUTTON":
		if(GetSelectable("CHARACTERS_BUTTON")==true) return "CHARACTERS_BUTTON";
		else return NextDown("CHARACTERS_BUTTON");
		break;
	case "CHARACTERS_BUTTON":
		if(GetSelectable("CREW_BUTTON")==true) return "CREW_BUTTON";
		else return NextDown("CREW_BUTTON");
		break;
	case "CREW_BUTTON":
		if(GetSelectable("CANNONS_BUTTON")==true) return "CANNONS_BUTTON";
		else return NextDown("CANNONS_BUTTON");
		break;
	case "CANNONS_BUTTON":
		if(GetSelectable("SWAP_BUTTON")==true) return "SWAP_BUTTON";
		else return NextDown("SWAP_BUTTON");
		break;
	}
	return GetCurrentNode();
}

ref GetMyCharacterRef()
{
	return refMyCharacter;
}

ref GetEnemyCharacterRef()
{
	return refEnemyCharacter;
}

void ISetShipAttributes(ref chref,ref outChr)
{
	if(chref.index == outChr.index) return;
	DeleteAttribute(chref,"ship");
	aref arToChar;	makearef(arToChar,chref.ship);
	aref arFromChar;	makearef(arFromChar,outChr.ship);
	CopyAttributes(arToChar,arFromChar);
}

void ReturnMyCrew(ref rMC, ref rEC)
{
	int nMyCrew = GetCrewQuantity(rEC);
	int nMyMaxCrew = GetMaxCrewQuantity(rMC);

	int nEnemyCrew = GetCrewQuantity(rMC);
	int nEnemyMaxCrew = GetMaxCrewQuantity(rEC);

	if(nEnemyCrew>nEnemyMaxCrew) {
		nMyCrew += nEnemyCrew - nEnemyMaxCrew;
		nEnemyCrew = nEnemyMaxCrew;
	}
	if(nMyCrew>nMyMaxCrew) {
		nEnemyCrew += nMyCrew - nMyMaxCrew;
		nMyCrew = nMyMaxCrew;
	}

	if(nEnemyCrew>nEnemyMaxCrew) {
		nEnemyCrew = nEnemyMaxCrew;
	}

	rMC.ship.crew.quantity = nMyCrew;
	rEC.ship.crew.quantity = nEnemyCrew;
	// NK 04-09-16 delete lastcrew and set base crew to current crew.
	DeleteAttribute(rMC,"seatime.lastcrew");
	DeleteAttribute(rEC,"seatime.lastcrew");
	rMC.seatime.basecrewquantity = nMyCrew;
	rEC.seatime.basecrewquantity = nEnemyCrew;
	// Do we reset base morale too? If not, comment this. Easier this way though.
//	rMC.seatime.basecrewmorale = rMC.ship.crew.morale;
//	rEC.seatime.basecrewmorale = rEC.ship.crew.morale;
	// NK <--
}

// --> Swindler 2005-10-13: attempt to debug CTD when swapping ships at land
//     Only attributes, which the original player's ship has are copied.
void SwapProcessAtLand(ref myChar, ref enChar)
{
// KK -->
	if (!CheckAttribute(myChar, "ship") || !CheckAttribute(enChar, "ship")) return;
	// generate references to both ships...
	aref myShip, enShip;
	makearef (myShip, myChar.ship);
	makearef (enShip, enChar.ship);
    // copy attributes to temporary ships
    object tempMyShip; ref rtempMyShip; makeref(rtempMyShip, tempMyShip);
    object tempEnShip; ref rtempEnShip; makeref(rtempEnShip, tempEnShip);
    CopyAttributes(rtempMyShip, enShip);
    CopyAttributes(rtempEnShip, myShip);
// <-- KK

    // Tracing for debugging, traces all attributes of both ships and most of
    // the subattributes of attributes of type object
    if (DEBUG)
	{
        TraceSwapProcessAtLand(myShip, enShip);
    }

    // copy attributes of primitive type
	myShip.type = rtempMyShip.type;
	enShip.type = rtempEnShip.type;
	myShip.name = rtempMyShip.name;
	enShip.name = rtempEnShip.name;
	myShip.idx = rtempMyShip.idx;
	enShip.idx = rtempEnShip.idx;
	myShip.hp = rtempMyShip.hp;
	enShip.hp = rtempEnShip.hp;
	myShip.sp = rtempMyShip.sp;
	enShip.sp = rtempEnShip.sp;
	//myShip.lastballcharacter = rtempMyShip.lastballcharacter; // not sure: should be -1 for own ships?
	//enShip.lastballcharacter = rtempEnShip.lastballcharacter; // not sure: should be -1 for own ships?
	//myShip.strand = rtempMyShip.strand; // not sure: should be the same for both ships at land?
	//enShip.strand = rtempEnShip.strand; // not sure: should be the same for both ships at land?
	//myShip.stopped = rtempMyShip.stopped; // not sure: should be the same for both ships at land?
	//enShip.stopped = rtempEnShip.stopped; // not sure: should be the same for both ships at land?
// KK -->
	if (CheckAttribute(rtempMyShip, "maxspeedz")) myShip.maxspeedz = rtempMyShip.maxspeedz;
	if (CheckAttribute(rtempEnShip, "maxspeedz")) enShip.maxspeedz = rtempEnShip.maxspeedz;
	if (CheckAttribute(rtempMyShip, "maxspeedy")) myShip.maxspeedy = rtempMyShip.maxspeedy;
	if (CheckAttribute(rtempEnShip, "maxspeedy")) enShip.maxspeedy = rtempEnShip.maxspeedy;
	if (CheckAttribute(rtempMyShip, "immersion")) myShip.immersion = rtempMyShip.immersion;
	if (CheckAttribute(rtempEnShip, "immersion")) enShip.immersion = rtempEnShip.immersion;
	if (CheckAttribute(rtempMyShip, "sails")) myShip.sails = rtempMyShip.sails;
	if (CheckAttribute(rtempEnShip, "sails")) enShip.sails = rtempEnShip.sails;
	if (CheckAttribute(rtempMyShip, "blots")) myShip.blots = rtempMyShip.blots;
	if (CheckAttribute(rtempEnShip, "blots")) enShip.blots = rtempEnShip.blots;
/*
	// Set the attributes anyway if for whatever reason there is no ship (wot?)...
	if (!CheckAttribute(rtempMyShip, "type"))		myShip.type			= 0;
	if (!CheckAttribute(rtempEnShip, "type"))		enShip.type			= 0;
	if (!CheckAttribute(rtempMyShip, "name"))		myShip.name			= "Ghost Ship";
	if (!CheckAttribute(rtempEnShip, "name"))		enShip.name			= "Ghost Ship";
	if (!CheckAttribute(rtempMyShip, "idx"))		myShip.idx			= 0;
	if (!CheckAttribute(rtempEnShip, "idx"))		enShip.idx			= 0;
	if (!CheckAttribute(rtempMyShip, "hp"))			myShip.hp			= 0;
	if (!CheckAttribute(rtempEnShip, "hp"))			enShip.hp			= 0;
	if (!CheckAttribute(rtempMyShip, "sp"))			myShip.sp			= 0;
	if (!CheckAttribute(rtempMyShip, "sp"))			enShip.sp			= 0;
	if (!CheckAttribute(rtempMyShip, "maxspeedz"))	myShip.maxspeedz	= 0;
	if (!CheckAttribute(rtempEnShip, "maxspeedz"))	enShip.maxspeedz	= 0;
	if (!CheckAttribute(rtempMyShip, "maxspeedy"))	myShip.maxspeedy	= 0;
	if (!CheckAttribute(rtempEnShip, "maxspeedy"))	enShip.maxspeedy	= 0;
	if (!CheckAttribute(rtempMyShip, "immersion"))	myShip.immersion	= 0;
	if (!CheckAttribute(rtempEnShip, "immersion"))	enShip.immersion	= 0;
	if (!CheckAttribute(rtempMyShip, "sails"))		myShip.sails		= 0;
	if (!CheckAttribute(rtempEnShip, "sails"))		enShip.sails		= 0;
	if (!CheckAttribute(rtempMyShip, "blots"))		myShip.blots		= 0;
	if (!CheckAttribute(rtempEnShip, "blots"))		enShip.blots		= 0;
*/

	// copy attributes of type object. don't know, why this works and
	// CopyAttributes(myShip, enShip) causes CTD
	object temp; ref rtemp; makeref(rtemp, temp);
	aref mytemp, entemp;
	makearef(mytemp, myShip.cannons);
	makearef(entemp, enShip.cannons);
	CopyAttributes(rtemp, mytemp);
	CopyAttributes(mytemp, entemp);
	CopyAttributes(entemp, rtemp);
	DeleteAttribute(rtemp, "");

	makearef(mytemp, myShip.ang);
	makearef(entemp, enShip.ang);
	CopyAttributes(rtemp, mytemp);
	CopyAttributes(mytemp, entemp);
	CopyAttributes(entemp, rtemp);
	DeleteAttribute(rtemp, "");

	makearef(mytemp, myShip.pos);
	makearef(entemp, enShip.pos);
	CopyAttributes(rtemp, mytemp);
	CopyAttributes(mytemp, entemp);
	CopyAttributes(entemp, rtemp);
	DeleteAttribute(rtemp, "");

	// not sure, if needed: speed should be 0 at land
	makearef(mytemp, myShip.speed);
	makearef(entemp, enShip.speed);
	CopyAttributes(rtemp, mytemp);
	CopyAttributes(mytemp, entemp);
	CopyAttributes(entemp, rtemp);
	DeleteAttribute(rtemp, "");

	makearef(mytemp, myShip.stats);
	makearef(entemp, enShip.stats);
	CopyAttributes(rtemp, mytemp);
	CopyAttributes(mytemp, entemp);
	CopyAttributes(entemp, rtemp);
	DeleteAttribute(rtemp, "");

	makearef(mytemp, myShip.crew);
	makearef(entemp, enShip.crew);
	CopyAttributes(rtemp, mytemp);
	CopyAttributes(mytemp, entemp);
	CopyAttributes(entemp, rtemp);
	DeleteAttribute(rtemp, "");

	makearef(mytemp, myShip.cargo);
	makearef(entemp, enShip.cargo);
	CopyAttributes(rtemp, mytemp);
	CopyAttributes(mytemp, entemp);
	CopyAttributes(entemp, rtemp);
	DeleteAttribute(rtemp, "");

	makearef(mytemp, myShip.impulse);
	makearef(entemp, enShip.impulse);
	CopyAttributes(rtemp, mytemp);
	CopyAttributes(mytemp, entemp);
	CopyAttributes(entemp, rtemp);
	DeleteAttribute(rtemp, "");

	makearef(mytemp, myShip.boxsize);
	makearef(entemp, enShip.boxsize);
	CopyAttributes(rtemp, mytemp);
	CopyAttributes(mytemp, entemp);
	CopyAttributes(entemp, rtemp);
	DeleteAttribute(rtemp, "");

	makearef(mytemp, myShip.masts);
	makearef(entemp, enShip.masts);
	CopyAttributes(rtemp, mytemp);
	CopyAttributes(mytemp, entemp);
	CopyAttributes(entemp, rtemp);
	DeleteAttribute(rtemp, "");

	if (!CheckAttribute(myShip, "tune")) InitTun(GetCharacterIndex(myChar.id));
	if (!CheckAttribute(enShip, "tune")) InitTun(GetCharacterIndex(enChar.id));
	makearef(mytemp, myShip.tune);
	makearef(entemp, enShip.tune);
	CopyAttributes(rtemp, mytemp);
	CopyAttributes(mytemp, entemp);
	CopyAttributes(entemp, rtemp);
	DeleteAttribute(rtemp, "");

	makearef(mytemp, myShip.Flags);
	makearef(entemp, enShip.Flags);
	CopyAttributes(rtemp, mytemp);
	CopyAttributes(mytemp, entemp);
	CopyAttributes(entemp, rtemp);
	DeleteAttribute(rtemp, "");
// <-- KK
}

void TraceSwapProcessAtLand(aref myShip, aref enShip) {
    // trace all attributes of both ships
    int i;
    aref att;
    string attName;
    string attValue;
    for (i = 0; i < GetAttributesNum(myShip); i++) {
        att = GetAttributeN(myShip, i);
        attName = GetAttributeName(att);
        attValue = GetAttributeValue(att);
        Trace("Trace: My ship's Attribute " + i + ": " + attName + " is " + attValue);
    }

    for (i = 0; i < GetAttributesNum(enShip); i++) {
        att = GetAttributeN(enShip, i);
        attName = GetAttributeName(att);
        attValue = GetAttributeValue(att);
        Trace("Trace: Other ship's Attribute " + i + ": " + attName + " is " + attValue);
    }

    // trace ai attribute of enemy ship. I think, that should be deleted. Or
    // at least, it shouldn't be moved to PChars ship.
    aref ai;
    makearef(ai, enShip.ai);
    for (i = 0; i < GetAttributesNum(ai); i++) {
        att = GetAttributeN(ai, i);
        attName = GetAttributeName(att);
        attValue = GetAttributeValue(att);

        Trace("Trace: Other ship's AI " + i + ": " + attName + " is " + attValue);
    }

    // trace subattributes of cannons
    aref cannons;
    makearef(cannons, myShip.cannons);
    for (i = 0; i < GetAttributesNum(cannons); i++) {
        att = GetAttributeN(cannons, i);
        attName = GetAttributeName(att);
        attValue = GetAttributeValue(att);

        Trace("Trace: My ship's cannons " + i + ": " + attName + " is " + attValue);
    }

    makearef(cannons, enShip.cannons);
    for (i = 0; i < GetAttributesNum(cannons); i++) {
        att = GetAttributeN(cannons, i);
        attName = GetAttributeName(att);
        attValue = GetAttributeValue(att);

        Trace("Trace: Other ship's cannons " + i + ": " + attName + " is " + attValue);
    }

    // trace subattributes of cannons.borts
    aref borts;
    aref bortsAtt;
    int j;
    makearef(borts, myShip.cannons.borts);
    for (i = 0; i < GetAttributesNum(borts); i++) {
        att = GetAttributeN(borts, i);
        attName = GetAttributeName(att);
        attValue = GetAttributeValue(att);

        Trace("Trace: My ship's cannon's borts " + i + ": " + attName + " is " + attValue);

        for (j = 0; j < GetAttributesNum(att); j++) {
            bortsAtt = GetAttributeN(att, j);
            attName = GetAttributeName(bortsAtt);
            attValue = GetAttributeValue(bortsAtt);
            Trace("Trace: My ship's cannon's borts " + GetAttributeName(att) + " " + j + ": " + attName + " is " + attValue);
        }
    }

    makearef(borts, enShip.cannons.borts);
    for (i = 0; i < GetAttributesNum(borts); i++) {
        att = GetAttributeN(borts, i);
        attName = GetAttributeName(att);
        attValue = GetAttributeValue(att);

        Trace("Trace: Other ship's cannon's borts " + j + ": " + attName + " is " + attValue);

        for (j = 0; j < GetAttributesNum(att); j++) {
            bortsAtt = GetAttributeN(att, j);
            attName = GetAttributeName(bortsAtt);
            attValue = GetAttributeValue(bortsAtt);
            Trace("Trace: Other ship's cannon's borts " + GetAttributeName(att) + " " + j + ": " + attName + " is " + attValue);
        }
    }

    // trace ship.ang
    aref ang;
    makearef(ang, myShip.ang);
    for (i = 0; i < GetAttributesNum(ang); i++) {
        att = GetAttributeN(ang, i);
        attName = GetAttributeName(att);
        attValue = GetAttributeValue(att);

        Trace("Trace: My ship's ang " + i + ": " + attName + " is " + attValue);
    }

    makearef(ang, enShip.ang);
    for (i = 0; i < GetAttributesNum(ang); i++) {
        att = GetAttributeN(ang, i);
        attName = GetAttributeName(att);
        attValue = GetAttributeValue(att);

        Trace("Trace: Other ship's ang " + i + ": " + attName + " is " + attValue);
    }

    // trace ship.pos
    aref pos;
    makearef(pos, myShip.pos);
    for (i = 0; i < GetAttributesNum(pos); i++) {
        att = GetAttributeN(pos, i);
        attName = GetAttributeName(att);
        attValue = GetAttributeValue(att);

        Trace("Trace: My ship's pos " + i + ": " + attName + " is " + attValue);
    }

    makearef(pos, enShip.pos);
    for (i = 0; i < GetAttributesNum(pos); i++) {
        att = GetAttributeN(pos, i);
        attName = GetAttributeName(att);
        attValue = GetAttributeValue(att);

        Trace("Trace: Other ship's pos " + i + ": " + attName + " is " + attValue);
    }
}
