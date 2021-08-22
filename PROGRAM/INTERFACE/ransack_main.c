ref refMyCharacter;
ref refEnemyCharacter;

// MAXIMUS interface MOD -->
string sPlayerName;

bool bBeParty;
int curOfficer;
ref xi_refMainChar;
ref xi_refCharacter;
ref newFriend;
ref tmpChar;

int oldIndex = -1;

int i, j, cn, on;

int ListMax;
ref MainChar;

int nMyCharacterCompanionPlace = -1;
int nCompanionIndex = -1;
// MAXIMUS interface MOD <--

void InitInterface_RRS(string iniName,ref pCharacter,ref enemyCh,string newCurNod)
{
	MainChar = GetMainCharacter();
	xi_refMainChar = GetMainCharacter();
	xi_refCharacter = pCharacter;
	refMyCharacter = xi_refCharacter;//myCh;
	refEnemyCharacter = enemyCh;

	if(CheckAttribute(xi_refCharacter,"InterfaceParam.i1"))
	{
		nMyCharacterCompanionPlace = sti(xi_refCharacter.InterfaceParam.i1);
		nCompanionIndex = GetCompanionIndex(xi_refCharacter,nMyCharacterCompanionPlace);
	}
	newFriend = &NullCharacter;
	if (nCompanionIndex == -1) {
		GameInterface.title = "titleRansack";
	} else {
		newFriend = GetCharacter(nCompanionIndex);
		GameInterface.title = "titleTransfer";
	}
	// NK fix PGMUS handling 05-04-18
	if(GetMusicScheme() == "PGMUS") // KK
	{
		ref pch = GetMainCharacter();
		if(musicName != "music_plunder")
		{
			pch.musfix.cur = musicName;
			pch.musfix.old = oldMusicName;
		}
		SetMusicNoPause("music_plunder");
	}
	// NK <--
	
// MAXIMUS interface MOD -->
	FillCharactersList(pCharacter);

	if(CheckAttribute(MainChar,"abordagesound"))//MAXIMUS -->
	{
		if(nCompanionIndex!=-1)
		{
			StopSound(sti(MainChar.abordagesound),20);
			DeleteAttribute(MainChar,"abordagesound");
		}
	}
	//if(!CheckAttribute(MainChar,"abordagesound")) SetMusic("music_spokplavanie");//MAXIMUS <--

	bBeParty = false;
	for(i=1;i<OFFICER_MAX  ;i++)	{if( GetOfficersIndex (xi_refCharacter,i)>=0 ) bBeParty = true; break;}
	for(i=1;i<COMPANION_MAX;i++)	{if( GetCompanionIndex(xi_refCharacter,i)>=0 ) bBeParty = true; break;}
// MAXIMUS interface MOD <--

    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();//MAXIMUS: standard exit-string for exit-button
	/*/ NK -->
	LAi_SetHP(GetCharacter(GetOfficersIndex(xi_refCharacter, 0)), LAI_DEFAULT_HP + sti(Characters[GetOfficersIndex(xi_refCharacter, 0)].rank) * 5, LAI_DEFAULT_HP + sti(Characters[GetOfficersIndex(xi_refCharacter, 0)].rank) * 5);
	for(i = 1; i < 4; i++)
	{
		if(GetOfficersIndex(xi_refCharacter, i) != -1)
		{
			LAi_SetHP(GetCharacter(GetOfficersIndex(xi_refCharacter, i)), LAI_DEFAULT_HP + sti(Characters[GetOfficersIndex(xi_refCharacter, i)].rank) * makeint(11-GetDifficulty()), LAI_DEFAULT_HP + sti(Characters[GetOfficersIndex(xi_refCharacter, i)].rank) * makeint(11-GetDifficulty()));
		}
	}
	for(i = 1; i < 4; i++)
	{
		if(GetCompanionIndex(xi_refCharacter, i) != -1)
		{
			LAi_SetHP(GetCharacter(GetCompanionIndex(xi_refCharacter, i)), LAI_DEFAULT_HP + sti(Characters[GetCompanionIndex(xi_refCharacter, i)].rank) * makeint(11-GetDifficulty()), LAI_DEFAULT_HP + sti(Characters[GetCompanionIndex(xi_refCharacter, i)].rank) * makeint(11-GetDifficulty()));
		}
	}*/
	for(i = 0; i < COMPANION_MAX; i++)
	{
		cn = GetCompanionIndex(&xi_refCharacter, i);
		if(cn != -1)
		{
			for(j = 0; j < OFFICER_MAX; j++)
			{
				on = GetOfficersIndex(GetCharacter(cn), j);
				if(on != -1) ResetHP(GetCharacter(on));
			}
		}
	}
	// NK <--

	if(newCurNod!="")
	{
		SetCurrentNode(newCurNod);
	}
	else
	{
		RecalculateCargoLoad( xi_refCharacter );
		RecalculateCargoLoad( refEnemyCharacter );
		DeleteAttribute(xi_refCharacter,"InterfaceParam");
		for(i=1;i<COMPANION_MAX;i++)
		{
			if(GetCompanionIndex(xi_refCharacter,i)==-1)
			{
				pCharacter.InterfaceParam.i1 = i;
				break;
			}
		}
	}

	int picCharIndex = -1;
	if(!CheckAttribute(xi_refCharacter,"InterfaceParam.i1"))
	{
		SetSelectable("CHARACTERS_BUTTON",false);
	}
	else
	{
		picCharIndex = GetCompanionIndex(xi_refCharacter,sti(xi_refCharacter.InterfaceParam.i1));
	}
	if(picCharIndex<0)
	{
		picCharIndex = sti(refEnemyCharacter.index);
		if(GetNotCaptivePassenger(xi_refCharacter,0)<0)
			SetSelectable("CHARACTERS_BUTTON",false);
	}

	ref shipRef = GetShipByType(GetCharacterShipType(xi_refCharacter)); // changed by MAXIMUS
	CreateImage("myShip",GetShipTextureName(shipRef.name),shipRef.name,32,39,160,167); // changed by MAXIMUS
//    CreateImage("myFace",GetFaceGroupName(sti(refMyCharacter.index)),GetFacePictureName(sti(refMyCharacter.index)),164,39,292,167);
    CreateString(true,"MyShipType","",FONT_NORMAL,COLOR_NORMAL,96,70,SCRIPT_ALIGN_CENTER,0.8); // changed by MAXIMUS
	CreateString(true,"MyShipClass","",FONT_BOLD_NUMBERS,COLOR_NORMAL,42,130,SCRIPT_ALIGN_LEFT,0.8); // KK
    CreateString(true,"MyShipName","",FONT_SEADOGS,COLOR_NORMAL,177,202,SCRIPT_ALIGN_CENTER,1.0); // changed by MAXIMUS
    CreateString(true,"MyName","",FONT_NORMAL,COLOR_NORMAL,166,170,SCRIPT_ALIGN_CENTER,1.0); // added by MAXIMUS

	CreateString(TRUE,"MyMaxHull",GetCharacterShipHP(&refMyCharacter),FONT_NORMAL,COLOR_NORMAL,100,232,SCRIPT_ALIGN_LEFT,1.0); // PRS3
	CreateString(TRUE,"MyHull","",FONT_NORMAL,COLOR_NORMAL,100,266,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(TRUE,"MyRig","",FONT_NORMAL,COLOR_NORMAL,100,302,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"MyShipSpeed","0",FONT_NORMAL,COLOR_NORMAL,100,336,SCRIPT_ALIGN_LEFT,1)
	CreateString(true,"MyShipManeuver","0",FONT_NORMAL,COLOR_NORMAL,100,370,SCRIPT_ALIGN_LEFT,1)
	CreateString(TRUE,"MyCannons","",FONT_NORMAL,COLOR_NORMAL,100,404,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(TRUE,"MyCrew","",FONT_NORMAL,COLOR_NORMAL,100,438,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(TRUE,"Mincrewus","",FONT_NORMAL,COLOR_NORMAL,50,480,SCRIPT_ALIGN_LEFT,0.8); // NK

	shipRef = GetShipByType(GetCharacterShipType(refEnemyCharacter)); // PS
	CreateImage("enemyShip",GetShipTextureName(shipRef.name),shipRef.name,480,39,608,167); // changed by MAXIMUS

// added by MAXIMUS -->
	string curEnemyName = XI_ConvertString("No Captain Assigned");
	bool btmp = false; // KK
	if(nCompanionIndex<0) 
	{    
		if(CheckAttribute(refEnemyCharacter,"position"))
		{
			switch(refEnemyCharacter.position)
			{
				case "loser":
					curEnemyName = refEnemyCharacter.name + " " + refEnemyCharacter.lastname + " - " + XI_ConvertString("loser");
					CreateImage("enemyFace",GetFaceGroupName(picCharIndex),GetFacePictureName(picCharIndex),348,39,476,167);
					//CreateString(true,"EnemyName",refEnemyCharacter.name + " " + refEnemyCharacter.lastname + " - " + XI_ConvertString("loser"),FONT_NORMAL,COLOR_NORMAL,478,170,SCRIPT_ALIGN_CENTER,1.0);
				break;

				case "corpse":
					curEnemyName = XI_ConvertString("Dead") + " " + XI_ConvertString("s"+"captain");
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

			/* original method
				case "officer":
					CreateImage("enemyFace",GetFaceGroupName(picCharIndex),GetFacePictureName(picCharIndex),348,39,476,167);
				    CreateString(true,"EnemyName",refEnemyCharacter.name + " " + refEnemyCharacter.lastname + " - " + XI_ConvertString("officer"),FONT_NORMAL,COLOR_NORMAL,478,170,SCRIPT_ALIGN_CENTER,1.0);
				break;

				case "companion":
					CreateImage("enemyFace",GetFaceGroupName(picCharIndex),GetFacePictureName(picCharIndex),348,39,476,167);
					CreateString(true,"EnemyName",refEnemyCharacter.name + " " + refEnemyCharacter.lastname + " - " + XI_ConvertString("s"+"companion"),FONT_NORMAL,COLOR_NORMAL,478,170,SCRIPT_ALIGN_CENTER,1.0);
				break;

				case "captive":
					CreateImage("enemyFace",GetFaceGroupName(picCharIndex),GetFacePictureName(picCharIndex),348,39,476,167);
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
			btmp = true; // KK
			curEnemyName = newFriend.name + " " + newFriend.lastname + " - " + XI_ConvertString("s"+"companion");
			//newFriend = GetCharacter(nCompanionIndex);
			CreateImage("enemyFace",GetFaceGroupName(nCompanionIndex),GetFacePictureName(nCompanionIndex),348,39,476,167);
			//CreateString(true,"EnemyName",newFriend.name + " " + newFriend.lastname + " - " + XI_ConvertString("s"+"companion"),FONT_NORMAL,COLOR_NORMAL,478,170,SCRIPT_ALIGN_CENTER,1.0); // MAXIMUS
		}
	}
	CreateString(true,"EnemyName",curEnemyName,FONT_NORMAL,COLOR_NORMAL,478,170,SCRIPT_ALIGN_CENTER,1.0); // MAXIMUS
// added by MAXIMUS <--

//	CreateImage("enemyFace",GetFaceGroupName(picCharIndex),GetFacePictureName(picCharIndex),348,39,476,167);
    CreateString(true,"EnemyShipType",XI_ConvertString(shipRef.SName),FONT_NORMAL,COLOR_NORMAL,544,70,SCRIPT_ALIGN_CENTER,0.8); // PS
	CreateString(true,"EnemyShipClass",GetCharacterShipClass(refEnemyCharacter),FONT_BOLD_NUMBERS,COLOR_NORMAL,490,130,SCRIPT_ALIGN_LEFT,0.8); // KK
    CreateString(true,"EnemyShipName",refEnemyCharacter.ship.Name,FONT_SEADOGS,COLOR_NORMAL,463,202,SCRIPT_ALIGN_CENTER,1.0);

	CreateString(TRUE,"EnemyMaxHull",GetCharacterShipHP(&refEnemyCharacter),FONT_NORMAL,COLOR_NORMAL,540,232,SCRIPT_ALIGN_RIGHT,1.0); // PRS3
	CreateString(TRUE,"EnemyHull","",FONT_NORMAL,COLOR_NORMAL,540,266,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(TRUE,"EnemyRig","",FONT_NORMAL,COLOR_NORMAL,540,302,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"EnemyShipSpeed","0",FONT_NORMAL,COLOR_NORMAL,540,336,SCRIPT_ALIGN_RIGHT,1)
	CreateString(true,"EnemyShipManeuver","0",FONT_NORMAL,COLOR_NORMAL,540,370,SCRIPT_ALIGN_RIGHT,1)
	CreateString(TRUE,"EnemyCannons","",FONT_NORMAL,COLOR_NORMAL,540,404,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(TRUE,"EnemyCrew","",FONT_NORMAL,COLOR_NORMAL,540,438,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(TRUE,"Mincrewthem","",FONT_NORMAL,COLOR_NORMAL,590,480,SCRIPT_ALIGN_RIGHT,0.8); // NK

	CreateString(true,"Mincrewwarn","",FONT_NORMAL,COLOR_NORMAL,320,445,SCRIPT_ALIGN_CENTER,0.8); // NK

// KK -->
	if (EnableLimitedShipClass()) {
		string icons = "ICONS";
		if (bNewInterface) icons = "ICONS_NEW";
		CreateImage("MyMaxShipClassIcon", icons, "ship class icon", 256, 149, 270, 163);
		CreateString(true, "MyMaxShipClass", GetShipMinClassForCharacter(refMyCharacter), FONT_BOLD_NUMBERS, COLOR_NORMAL, 276, 150, SCRIPT_ALIGN_CENTER, 0.4);
		if (btmp) {
			CreateImage("EnemyMaxShipClassIcon", icons, "ship class icon", 436, 149, 450, 163);
			CreateString(true, "EnemyMaxShipClass", GetShipMinClassForCharacter(refEnemyCharacter), FONT_BOLD_NUMBERS, COLOR_NORMAL, 456, 150, SCRIPT_ALIGN_CENTER, 0.4);
		}
	}
// <-- KK

// added by MAXIMUS-->
//	SetSelectable("LEFTCHANGE_CHARACTER",true);
//	SetSelectable("RIGHTCHANGE_CHARACTER",true);
	SetSelectable("EXIT_BUTTON",true);
	SetNodeUsing("CONFIRM_RECTANGLE",false);
	SetNodeUsing("TEXTWINDOW",false);
	SetNodeUsing("CONFIRM_YES_BUTTON",false);
	SetNodeUsing("CONFIRM_NO_BUTTON",false);
	SetNodeUsing("REL_PIC",false);
	SetNodeUsing("EN_PIC",false);
// added by MAXIMUS <--

// added by MAXIMUS [abordage MOD] -->
// TIH --> cleaner method less confusing to players Aug24'06
	if(xi_refCharacter.index == refEnemyCharacter.index)
	{
		SetSelectable("CHARACTERS_BUTTON",false);
		SetSelectable("CREW_BUTTON",false);
		SetSelectable("SWAP_BUTTON",false);
		SetSelectable("CANNONS_BUTTON",false);
	}
	else
	{
		SetSelectable("CREW_BUTTON", !IsTrader(xi_refCharacter)); // KK
		if(ProfessionalNavyNation() != UNKNOWN_NATION && GetRank(xi_refMainChar, GetServedNation()) < 7)
		{
			SetSelectable("SWAP_BUTTON", false);
		}
		else
		{
			SetSelectable("SWAP_BUTTON", !IsTrader(xi_refCharacter)); // KK
		}
		SetSelectable("CANNONS_BUTTON", !IsTrader(xi_refCharacter)); // KK
		if(CheckAttribute(refEnemyCharacter,"position"))
		{
			switch(refEnemyCharacter.position)
			{
				case "loser":
				    SetSelectable("CHARACTERS_BUTTON",false);
				    SetSelectable("CREW_BUTTON",false);
				break;
			}
		}
		// PB: Legal Prize Ships -->
		if (GetSelectable("CHARACTERS_BUTTON")) // You CAN assign a captain
		{
			int TotalMinCrew = GetMinCrewQuantity(xi_refCharacter) + GetMinCrewQuantity(refEnemyCharacter);
			int TotalCrew    = MakeInt(xi_refCharacter.ship.Crew.Quantity) + makeint(refEnemyCharacter.ship.Crew.Quantity);
			if (IsPrizeShip(refEnemyCharacter) && TotalCrew >= TotalMinCrew) // Will be a prize ship AND you have enough crew to sail both ships
			{
			/*	SetSelectable("GOODS_BUTTON", false);
				SetSelectable("CANNONS_BUTTON", false);
				SetSelectable("SWAP_BUTTON", false);
				SendMessage(&GameInterface, "lsls", MSG_INTERFACE_MSG_TO_NODE, "GOODS_BUTTON"  , 0, "Cannot plunder");*/
				SendMessage(&GameInterface, "lsls", MSG_INTERFACE_MSG_TO_NODE, "CREW_BUTTON"   , 0, TranslateString("", "Assign prize crew"));
			/*	SendMessage(&GameInterface, "lsls", MSG_INTERFACE_MSG_TO_NODE, "CANNONS_BUTTON", 0, "Cannot take cannons");
				SendMessage(&GameInterface, "lsls", MSG_INTERFACE_MSG_TO_NODE, "SWAP_BUTTON"   , 0, "Cannot take ship");*/
			}
		}
		// PB: Legal Prize Ships <--
	}
/* Unused now
	if(transferCaptain==true)
	{
		if(CheckAttribute(refEnemyCharacter,"position"))
		{
			switch(refEnemyCharacter.position)
			{
				case "loser":
				    SetSelectable("CHARACTERS_BUTTON",false);
				    SetSelectable("CREW_BUTTON",false);
				    SetSelectable("SWAP_BUTTON",true);
				break;

				case "corpse":
				    SetSelectable("CREW_BUTTON",true);
				    SetSelectable("SWAP_BUTTON",true);
				break;

				case "officer":
				    SetSelectable("CREW_BUTTON",true);
				    SetSelectable("SWAP_BUTTON",true);
				break;

				case "companion":
				    SetSelectable("CHARACTERS_BUTTON",false);
				    SetSelectable("CREW_BUTTON",true);
				    SetSelectable("SWAP_BUTTON",true);
				break;

				case "captive":
				    SetSelectable("CREW_BUTTON",true);
				    SetSelectable("SWAP_BUTTON",true);
				break;
			}
		}
	}
	else
	{
		if(xi_refCharacter.index == refEnemyCharacter.index)
		{
			SetSelectable("CREW_BUTTON",false);
			SetSelectable("SWAP_BUTTON",false);
			SetSelectable("CANNONS_BUTTON",false);
		}
		else
		{
			SetSelectable("CREW_BUTTON",true);
			SetSelectable("SWAP_BUTTON",true);
			SetSelectable("CANNONS_BUTTON",true);
		}
		if(transferCaptain==false)
		{
			SetSelectable("CREW_BUTTON",true);
			SetSelectable("SWAP_BUTTON",true);
			SetSelectable("CANNONS_BUTTON",true);
		}
	}
*/
// TIH <--
// added by MAXIMUS [abordage MOD] -->

// KK -->
	if (!CheckAttribute(xi_refMainChar, "CapturedShipData")) {
		xi_refMainChar.CapturedShipData.Type = GetCharacterShipID(refEnemyCharacter);
		xi_refMainChar.CapturedShipData.HP = GetCharacterShipHP(refEnemyCharacter);
		xi_refMainChar.CapturedShipData.Name = refEnemyCharacter.Ship.Name;
	}
// <-- KK

	WasChangeData();
	SetVariable(); // added by MAXIMUS

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
    SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("GoodsPress","GoodsProcess",0);
	SetEventHandler("CharactersPress","CharactersProcess",0);
	SetEventHandler("CrewPress","CrewProcess",0);
	SetEventHandler("SwapPress","SwapProcess",0);

	SetEventHandler("CannonsPress","CannonsProcess",0);

	SetEventHandler("UpPress","UpProcess",0);
	SetEventHandler("DownPress","DownProcess",0);
// added by MAXIMUS-->
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
	SetEventHandler("ExitPress","ProcessExit",0);
	SetEventHandler("ExitNo","ProcessExit_no",0);
	SetEventHandler("ExitYes","ProcessExit_yes",0);
// added by MAXIMUS <--
// KK -->
	SetEventHandler("MaxShipClassYes", "CheckMaxShipClassYes", 0);
	SetEventHandler("MaxShipClassNo", "CheckMaxShipClassNo", 0);
	SetEventHandler("FleetLevelYes", "CheckFleetLevelYes", 0);
	SetEventHandler("FleetLevelNo", "CheckFleetLevelNo", 0);
// <-- KK

	SetCurrentNode("GOODS_BUTTON");

	//Sulan -->
	//Record the plundered goods
	string plunder = "";
	for(i=0; i<GOODS_QUANTITY;i++)
	{
		if(GetCargoGoods(refEnemyCharacter, i) > 0)
		{
			plunder = "plunder"+i;
			refEnemyCharacter.Ship.Plunder.(plunder) = GetCargoGoods(refEnemyCharacter, i);    
		}
	}
	i=0;
	//<-- Sulan
}

// added by MAXIMUS -->
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

void SetVariable()
{
	bool bShown = true;
	if(GetCompanionQuantity(GetMainCharacter())==2)
	{
		if(GetCompanionIndex(GetMainCharacter(),1)==nCompanionIndex || GetCompanionIndex(GetMainCharacter(),1)==GetCharacterIndex("Quest trader")) bShown = false;
	}
	if(GetCompanionQuantity(GetMainCharacter())>2) // MM
	{
		if(GetCompanionIndex(GetMainCharacter(),1)==nCompanionIndex || GetCompanionIndex(GetMainCharacter(),2)==nCompanionIndex)
		{
			if(GetCompanionIndex(GetMainCharacter(),1)==GetCharacterIndex("Quest trader") || GetCompanionIndex(GetMainCharacter(),2)==GetCharacterIndex("Quest trader")) bShown = false;
		}
	}

	SetNodeUsing("LEFTCHANGE_CHARACTER", bAbordageStarted && GetCompanionQuantity(GetMainCharacter())>1 && bShown);
	SetSelectable("LEFTCHANGE_CHARACTER", bAbordageStarted && GetCompanionQuantity(GetMainCharacter())>1 && bShown);
	SetNodeUsing("RIGHTCHANGE_CHARACTER", bAbordageStarted && GetCompanionQuantity(GetMainCharacter())>1 && bShown);
	SetSelectable("RIGHTCHANGE_CHARACTER", bAbordageStarted && GetCompanionQuantity(GetMainCharacter())>1 && bShown);

	ref shipRef = GetShipByType(GetCharacterShipType(xi_refCharacter));
    sPlayerName = xi_refCharacter.name;
    GameInterface.strings.MyShipType = XI_ConvertString(shipRef.SName);
	GameInterface.strings.MyShipClass = sti(shipRef.Class); // KK
    GameInterface.strings.MyShipName = xi_refCharacter.ship.Name;

	if(IsMainCharacter(xi_refCharacter) && CheckAttribute(xi_refCharacter,"title") && xi_refCharacter.title!="") bShown = true;
	else bShown = false;
	if(bShown) GameInterface.strings.MyName = GetMyRespectfullyName(xi_refCharacter);
	else GameInterface.strings.MyName = GetMySimpleName(xi_refCharacter);

	SetNewPicture("FACEPICT", "interfaces\portraits\128\face_" + xi_refCharacter.FaceId + ".tga");
	if (EnableLimitedShipClass()) GameInterface.strings.MyMaxShipClass = GetShipMinClassForCharacter(xi_refCharacter); // KK

	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"exp",0);

	if ((GetCrewQuantity(xi_refCharacter) + GetCrewQuantity(refEnemyCharacter)) < GetMinCrewQuantity(refEnemyCharacter)) SetSelectable("SWAP_BUTTON", false); // KK

	oldIndex = -1;
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
// added by MAXIMUS <--

void WasChangeData()
{
	ref shipRef = GetShipByType(GetCharacterShipType(xi_refCharacter)); // PS
	aref arship; makearef(arship, xi_refCharacter.ship); // PRS3
	GameInterface.pictures.myShip.tex       = GetShipTextureName(sti(shipRef.index)); // PS
	GameInterface.pictures.myShip.pic       = GetShipPicName(sti(shipRef.index)); // PS
	GameInterface.strings.MyShipType        = XI_ConvertString(shipRef.Sname); // PS
	GameInterface.strings.MyShipClass       = sti(shipRef.Class); // KK
	GameInterface.strings.MyShipName        = xi_refCharacter.ship.Name;
	GameInterface.strings.MyMaxHull         = GetCharacterShipHP(&xi_refCharacter); // PRS3
	GameInterface.strings.MyHull            = MakeInt(xi_refCharacter.ship.HP);
	GameInterface.strings.MyRig             = MakeInt(xi_refCharacter.ship.SP);
	GameInterface.strings.MyShipSpeed       = FloatToString(stf(GetLocalShipAttrib(arship, &shipRef, "SpeedRate")),2); // PB
	GameInterface.strings.MyShipManeuver    = FloatToString(stf(GetLocalShipAttrib(arship, &shipRef, "TurnRate" )),2); // PB
	//GameInterface.strings.MyCrew            = MakeInt(xi_refCharacter.ship.Crew.Quantity)+"/"+GetMaxCrewQuantity(&xi_refCharacter); // PRS3
	GameInterface.strings.MyCrew            = MakeInt(xi_refCharacter.ship.Crew.Quantity); // MM
	GameInterface.strings.MyCannons         = GetLocalShipAttrib(arship, &shipRef, "CurCanQty"); //NK can qty 05-04-18 shipRef.CannonsQuantity;
	//GameInterface.strings.Mincrewus         = XI_ConvertString("Min Crew") + ": " + GetMinCrewQuantity(&xi_refCharacter); // PRS3
	GameInterface.strings.Mincrewus         = "Min/Max Crew: "+GetMinCrewQuantity(&xi_refCharacter)+" / "+GetMaxCrewQuantity(&xi_refCharacter); // MM

	shipRef = GetShipByType(GetCharacterShipType(refEnemyCharacter)); // PS
	makearef(arship, refEnemyCharacter.ship); // PRS3
	GameInterface.pictures.enemyShip.tex    = GetShipTextureName(sti(shipRef.index)); // PS
	GameInterface.pictures.enemyShip.pic    = GetShipPicName(sti(shipRef.index)); // PS
	GameInterface.strings.EnemyShipType     = XI_ConvertString(shipRef.Sname); // PS
	GameInterface.strings.EnemyShipClass    = sti(shipRef.Class); // KK
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
	GameInterface.strings.Mincrewthem       = "Min/Max Crew: "+GetMinCrewQuantity(&refEnemyCharacter)+" / "+GetMaxCrewQuantity(&refEnemyCharacter); // MM
}

// added by MAXIMUS -->
void ProcessExit()
{
	SetNodeUsing("CONFIRM_RECTANGLE",true);
	SetNodeUsing("TEXTWINDOW",true);
	SetNodeUsing("CONFIRM_YES_BUTTON",true);
	SetNodeUsing("CONFIRM_NO_BUTTON",true);
	SetNodeUsing("REL_PIC",true);
	SetNodeUsing("EN_PIC",true);
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");

	newFriend = GetCharacter(nCompanionIndex);

	if (IsCompanion(newFriend)) {
		SetNewPicture("EN_PIC", "interfaces\our_ship.tga");
	} else {
// changed by MAXIMUS [abordage MOD] -->
		if (IsOfficerCompanion(newFriend)) {
			SetNewPicture("EN_PIC", "interfaces\kam_isofficercompanion.tga");
		} else {
		  if (CheckAttribute(refEnemyCharacter, "position")) {
				switch (refEnemyCharacter.position) {
					case "loser": SetNewPicture("EN_PIC", "interfaces\our_ship.tga"); break;
					case "corpse": SetNewPicture("EN_PIC", "battle_interface\sinking.tga"); break;
					case "officer": SetNewPicture("EN_PIC", "battle_interface\sinking.tga"); break;
					case "companion": SetNewPicture("EN_PIC", "interfaces\our_ship.tga"); break;
					case "captive": SetNewPicture("EN_PIC", "battle_interface\sinking.tga"); break;
				}
		  } else {
				SetNewPicture("EN_PIC", "battle_interface\sinking.tga");
			}
		}
// changed by MAXIMUS [abordage MOD] <--
	}


	SetCurrentNode("CONFIRM_NO_BUTTON");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "CONFIRM_NO_BUTTON");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "CONFIRM_YES_BUTTON");

	SetFormatedText("TEXTWINDOW",LanguageConvertString(tmpLangFileID,"Exit from abordage confirm"));
	LanguageCloseFile(tmpLangFileID);
}

void ProcessExit_no()
{
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);

	SetNodeUsing("CONFIRM_RECTANGLE",false);
	SetNodeUsing("TEXTWINDOW",false);
	SetNodeUsing("CONFIRM_YES_BUTTON",false);
	SetNodeUsing("CONFIRM_NO_BUTTON",false);
	SetNodeUsing("REL_PIC",false);
	SetNodeUsing("EN_PIC",false);

	SetCurrentNode("GOODS_BUTTON");
}

void ProcessExit_yes()
{
	PauseAllSounds();
	ResetSoundScheme();
	ProcessCancelExit();
}
// added by MAXIMUS <--

void ProcessCancelExit()
{
	int n = -1;
	if (CheckAttribute(xi_refCharacter,"InterfaceParam.i1")) {
		n = GetCompanionIndex(xi_refCharacter,sti(xi_refCharacter.InterfaceParam.i1));
		// boal min crew on ship --> NK
		if (n >= 0 && GetCrewQuantity(refEnemyCharacter) < GetMinCrewQuantity(refEnemyCharacter) && GetCrewQuantity(xi_refCharacter) > GetMinCrewQuantity(xi_refCharacter)) { // changed by MAXIMUS
			PlaySound("interface\knock.wav");
			GameInterface.strings.Mincrewwarn = TranslateString("", "Not enough crew assigned"); // MAXIMUS
			return;
		}
		// boal min crew on ship <-- NK
		DeleteAttribute(xi_refCharacter,"InterfaceParam");
	}
// KK -->
	int i = sti(refEnemyCharacter.curshipnum);
	DeleteAttribute(refEnemyCharacter, "curshipnum");
	Ships[i] = n;
	if (n >= 0) Characters[n].curshipnum = i;
// <-- KK
	if (n < 0) {
		// if we didn't assign anyone to this ship, we check what we should do to the enemy based on prior events
		// added by MAXIMUS [abordage MOD] -->
		if (CheckAttribute(refEnemyCharacter,"position")) {
			switch(refEnemyCharacter.position)
			{
				case "loser":
					SeaAI_SetOfficer2ShipAfterAbordage(refEnemyCharacter,refEnemyCharacter);
					//SetCharacterRelation(sti(xi_refCharacter.index),sti(refEnemyCharacter.index),RELATION_NEUTRAL);
					//UpdateRelations();
					// TIH only do the ship surrender process if they hadn't already surrendered Aug31'06
					if (CheckAttribute(refEnemyCharacter,"surrendered") && sti(refEnemyCharacter.surrendered) == true) {
						// we do nothing as its already been done
					} else {
						refEnemyCharacter.releasedfree = true;// ONLY USED in Ship_Surrender - do not use this flag anywhere else!
						Ship_Surrender(sti(refEnemyCharacter.index));
					}
				//	Character_SetAbordageEnable(refEnemyCharacter, false); // TIH re-boarding bug fix
				//	refEnemyCharacter.nation = NEUTRAL_NATION; // make sure they are in the right nation (not needed it seems?)
					refEnemyCharacter.oldnation = NEUTRAL_NATION; // make it so they are non-boardable (the safer way)
					Ship_SetTaskRunaway(PRIMARY_TASK, sti(refEnemyCharacter.index));
					Ship_SetTaskRunaway(SECONDARY_TASK, sti(refEnemyCharacter.index)); // TIH helps get them on their way
					if (frnd() > 0.7) PostEvent("Ship_BranderDetonate", 16000, "i", refEnemyCharacter); // TIH a little fun
				break;

				case "corpse":
					ShipDead(sti(refEnemyCharacter.index),KILL_BY_ABORDAGE,sti(xi_refCharacter.index));
				break;

				case "officer":
					ShipDead(sti(refEnemyCharacter.index),KILL_BY_ABORDAGE,sti(xi_refCharacter.index));
				break;

				case "captive":
					ShipDead(sti(refEnemyCharacter.index),KILL_BY_ABORDAGE,sti(xi_refCharacter.index));
				break;
				// TIH --> this must exist for any non-set captures... catchall for lack of setting - Oct30'06
				//default:
					ShipDead(sti(refEnemyCharacter.index),KILL_BY_ABORDAGE,sti(xi_refCharacter.index));
				// TIH <--
			}
			DeleteAttribute(refEnemyCharacter,"status");
			DeleteAttribute(refEnemyCharacter,"position");
		} else {
			ShipDead(sti(refEnemyCharacter.index),KILL_BY_ABORDAGE,sti(xi_refCharacter.index));
		}
		// added by MAXIMUS [abordage MOD] <--
	} else { // else we assigned an officer to this ship, so we give them the ship, and kill the enemy off
// KK -->
		bool bPirated = ShipTaken(GetCharacterIndex(refEnemyCharacter.id), KILL_BY_ABORDAGE, n); // Stone-D 19/07/2003
		SwapCabinChests(n, sti(refEnemyCharacter.index));
// <-- KK
		ISetShipAttributes(GetCharacter(n)); // copy ship from enemy to companion officer
		SeaAI_SetOfficer2ShipAfterAbordage(GetCharacter(n),refEnemyCharacter);
		LAi_SetCurHP(refEnemyCharacter, 0.0);
		refEnemyCharacter.Killer.Status = KILL_BY_ABORDAGE;
		refEnemyCharacter.Killer.Index = GetMainCharacterIndex();
		// PB: Method of acquiring ship influences sale price -->
		// Inspired by TIH's rpgstyle shipyard (Jul27'06)
		ref shipsNewOwner = GetCharacter(n);
		if (bPirated)	shipsNewOwner.ship.acquired = "pirated";
		else			shipsNewOwner.ship.acquired = "taken";
		// PB: Method of acquiring ship influences sale price <--
		refEnemyCharacter.Ship.HP = 0; // TIH kill the enemy ship (its been copied to officer by now, helps with quests) Aug27'06
		PostEvent("evntQuestsCheck",1);
	}

	DeleteAttribute(xi_refMainChar, "CapturedShipData"); // KK

	interfaceResultCommand = RC_INTERFACE_RANSACK_MAIN_EXIT;
	Exit();

	RefreshBattleInterface(true);
	if( CheckAttribute(&PeopleOnShip,"IsOnDeck") && sti(PeopleOnShip.IsOnDeck) )
	{
		PeopleOnShip.IsOnDeck = true;
	}
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
	DelEventHandler("ievnt_command","ProcessCommandExecute");
	DelEventHandler("ExitPress","ProcessExit");
	DelEventHandler("ExitNo","ProcessExit_no");
	DelEventHandler("ExitYes","ProcessExit_yes");
// added by MAXIMUS <--
// KK -->
	DelEventHandler("MaxShipClassYes", "CheckMaxShipClassYes");
	DelEventHandler("MaxShipClassNo", "CheckMaxShipClassNo");
	DelEventHandler("FleetLevelYes", "CheckFleetLevelYes");
	DelEventHandler("FleetLevelNo", "CheckFleetLevelNo");
// <-- KK

	EndCancelInterface(true);
}

void GoodsProcess()
{
	interfaceResultCommand = RC_INTERFACE_TRANSFER_START_GOODS;
	Exit();
}

// KK -->
void CharactersProcess()
{
	// boal min crew on ship -->
	/*if(GetCrewQuantity(refEnemyCharacter)<GetMinCrewQuantity(refEnemyCharacter))
	{
		GameInterface.strings.Mincrewwarn = TranslateString("","Not enough crew assigned");
		PlaySound("interface\knock.wav");
		return;
	}*/
	// boal min crew on ship <--
	if (EnableLimitedShipClass()
		 && IsMainCharacter(refMyCharacter) == true
		 && CheckFleetShips(true)
		 && GetShipSkill(refMyCharacter, SKILL_LEADERSHIP) < FLEETCOMMAND_MIN_LEVEL)
	{
		SetNodeUsing("MSC_CONFIRM_RECTANGLE", true);
		SetNodeUsing("MSC_TEXTWINDOW", true);
		SetNodeUsing("FLV_CONFIRM_YES_BUTTON", true);
		SetNodeUsing("FLV_CONFIRM_NO_BUTTON", true);
		SetNodeUsing("MSC_SKILL_PIC", true);
		SetCurrentNode("FLV_CONFIRM_NO_BUTTON");
		SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "FLV_CONFIRM_NO_BUTTON");
		SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "FLV_CONFIRM_YES_BUTTON");
		SetFormatedText("MSC_TEXTWINDOW", TranslateString("", "You can't command a fleet until reaching level") + " " + FLEETCOMMAND_MIN_LEVEL + " " + TranslateString("", "Leadership. Assign anyway?"));
	} else {
		CheckFleetLevelYes();
	}
}

void CheckFleetLevelYes()
{
	if (EnableLimitedShipClass()) {
		SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
		SetNodeUsing("MSC_CONFIRM_RECTANGLE", false);
		SetNodeUsing("MSC_TEXTWINDOW", false);
		SetNodeUsing("FLV_CONFIRM_YES_BUTTON", false);
		SetNodeUsing("FLV_CONFIRM_NO_BUTTON", false);
		SetNodeUsing("MSC_SKILL_PIC", false);
	}
	interfaceResultCommand = RC_INTERFACE_TRANSFER_START_CHARACTERS;
	Exit();
}

void CheckFleetLevelNo()
{
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
	SetNodeUsing("MSC_CONFIRM_RECTANGLE", false);
	SetNodeUsing("MSC_TEXTWINDOW", false);
	SetNodeUsing("FLV_CONFIRM_YES_BUTTON", false);
	SetNodeUsing("FLV_CONFIRM_NO_BUTTON", false);
	SetNodeUsing("MSC_SKILL_PIC", false);
	SetCurrentNode("SCROLLITEMS");
}
// <-- KK

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

// KK -->
void SwapProcess()
{
	//string tmp;
// boal min crew on ship -->
	/*if((GetCrewQuantity(xi_refCharacter) + GetCrewQuantity(refEnemyCharacter))< GetMinCrewQuantity(refEnemyCharacter))
	{
		PlaySound("interface\knock.wav");
		int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
		GameInterface.strings.Mincrewwarn = LanguageConvertString(tmpLangFileID,"Not enough crew assigned"); // MAXIMUS
		LanguageCloseFile(tmpLangFileID);
		return;
	}*/
// boal min crew on ship <--
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
	} else {
		CheckMaxShipClassYes();
	}
// <-- KK
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
	SeaAI_SwapShipsAttributes(xi_refCharacter, refEnemyCharacter);
	SeaAI_SwapShipAfterAbordage(xi_refCharacter, refEnemyCharacter);
	ReturnMyCrew(xi_refCharacter, refEnemyCharacter);

	if(CheckAttribute(xi_refCharacter,"InterfaceParam.i1"))
	{
		int cn = GetCompanionIndex(xi_refCharacter,sti(xi_refCharacter.InterfaceParam.i1));
		if(cn>=0 && cn!=sti(refEnemyCharacter.index))
		{
			ISetShipAttributes(GetCharacter(cn));
		}
	}

	WasChangeData();
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
	string tmp = NextUp(GetCurrentNode());
	SetCurrentNode(tmp);
}

void DownProcess()
{
	string tmp = NextDown(GetCurrentNode());
	SetCurrentNode(tmp);
}

string NextUp(string curNod)
{
	switch(curNod)
	{
	case "GOODS_BUTTON":
		if(GetSelectable("SWAP_BUTTON")==true)	return "SWAP_BUTTON";
		else return NextUp("SWAP_BUTTON");
		break;
	case "CHARACTERS_BUTTON":
		if(GetSelectable("GOODS_BUTTON")==true)	return "GOODS_BUTTON";
		else return NextUp("GOODS_BUTTON");
		break;
	case "CREW_BUTTON":
		if(GetSelectable("CHARACTERS_BUTTON")==true) return "CHARACTERS_BUTTON";
		else return NextUp("CHARACTERS_BUTTON");
		break;
	case "CANNONS_BUTTON":
		if(GetSelectable("CREW_BUTTON")==true) return "CREW_BUTTON";
		else return NextUp("CREW_BUTTON");
		break;
	case "SWAP_BUTTON":
		if(GetSelectable("CANNONS_BUTTON")==true) return "CANNONS_BUTTON";
		else return NextUp("CANNONS_BUTTON");
		break;
	}
	return " ";
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
		else return "CANNONS_BUTTON";
		break;
	case "CANNONS_BUTTON":
		if(GetSelectable("SWAP_BUTTON")==true) return "SWAP_BUTTON";
		else return NextDown("SWAP_BUTTON");
		break;
	case "SWAP_BUTTON":
		if(GetSelectable("GOODS_BUTTON")==true) return "GOODS_BUTTON";
		else return NextDown("GOODS_BUTTON");
		break;
	}
	return " ";
}

ref GetMyCharacterRef()
{
	return refMyCharacter;
}

ref GetEnemyCharacterRef()
{
	return refEnemyCharacter;
}

void ISetShipAttributes(ref chref)
{
	DeleteAttribute(chref,"ship");
	aref arToChar;	makearef(arToChar,chref.ship);
	aref arFromChar;	makearef(arFromChar,refEnemyCharacter.ship);
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
}
