#define SHOW_HIRE	0
#define SHOW_FIRE	1

int nShowType;

int nCurFourNum;

int idShipType;
int nPlayerMoney;
int nPlayerID;
string sPlayerName;
aref refMyCrew;

int nMaxCrew;
int nMinCrew;
int nCurCrew;
float nMyMorale;

int nCrewCost;
float nCrewMorale;
int nCrewQuantity;

int nAllCrewCost;
int nHireQuantity;
int nHireMax;
float nSumMorale;

string current_date;

void InitInterface(string iniName)
{
	GetHireCrewInfo();

	GameInterface.title = "titleHireCrew";
	GameInterface.FourImage.current = 0;

	FillFourImage();

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();//MAXIMUS: standard exit-string for exit-button

	CreateString(true,"Money","",FONT_NORMAL,COLOR_MONEY,320,393,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"Onboard","",FONT_NORMAL,COLOR_NORMAL,210,148,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"MyMorale","",FONT_NORMAL,COLOR_NORMAL,430,148,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"ShipName","",FONT_NORMAL,COLOR_NORMAL,320,199,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"Available","",FONT_NORMAL,COLOR_NORMAL,410,234,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(false,"Cost","",FONT_NORMAL,COLOR_NORMAL,330,300,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(false,"BuyMorale",XI_ConvertString(GetMoraleName(nCrewMorale)),FONT_NORMAL,COLOR_NORMAL,330,321,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(false,"HireQuantity","",FONT_NORMAL,COLOR_NORMAL,320,271,SCRIPT_ALIGN_CENTER,1.0);

	CreateImage("CrewPicture","SHIP_STATE_ICONS","Crew",146,34,274,162);
	CreateImage("MoralePicture","MORALE","medium morale",366,34,494,162);

	SetNodeUsing("HIRE_OK",false);
	SetNodeUsing("HIRE_CANCEL",false);
	SetNodeUsing("HIRE_COUNTER",false);
	SetNodeUsing("HIRESTRINGS",false);
	SetSelectable("EXIT_BUTTON",true);

	SetVariable();
	ProcessFrame();

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("frame","ProcessFrame",1);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("HirePress","HireProcess",0);
	SetEventHandler("FirePress","FireProcess",0);
	SetEventHandler("HireOk","HireOk",0);
	SetEventHandler("HireCancel","HireCancel",0);
	SetEventHandler("DecreaseHire","DecreaseHire",0);
	SetEventHandler("IncreaseHire","IncreaseHire",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
}

void ProcessFrame()
{
	if(MakeInt(GameInterface.FourImage.current)!=nCurFourNum)
	{
		aref refMyShip;
		HireCancel(); //boal crew hire (thx to Gray Angel)

		nCurFourNum = MakeInt(GameInterface.FourImage.current);
		nPlayerID = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
		if(nPlayerID<0)
		{
			trace("WARNING!!! Choose not used companion");
			return;
		}

		SetSelectable( "FIRE_BUTTON", GetRemovable(&Characters[nPlayerID]) );
		sPlayerName = Characters[nPlayerID].name;
		makearef(refMyShip,Characters[nPlayerID].Ship);
		makearef(refMyCrew,refMyShip.Crew);
		nMyMorale = sti(refMyCrew.Morale);
		idShipType = GetCharacterShipType(GetCharacter(nPlayerID)); // PS
		if(idShipType!=SHIP_NOTUSED)
		{
			nMaxCrew = MakeInt(GetLocalShipAttrib(refMyShip, ShipsTypes[idShipType],"MaxCrew")); // PRS3
			nMinCrew = MakeInt(GetLocalShipAttrib(refMyShip, ShipsTypes[idShipType],"MinCrew")); // PRS3
		}
		else
		{
			nMaxCrew = 0;
			nMinCrew = 0;
		}
		nCurCrew = MakeInt(refMyCrew.Quantity);

		GameInterface.strings.Onboard = nCurCrew+"/"+nMaxCrew;
		GameInterface.strings.ShipName = GetMyShipName(&Characters[nPlayerID]);
		GameInterface.strings.MyMorale = XI_ConvertString(GetMoraleName(nMyMorale));
		GameInterface.pictures.morale.MoralePicture = GetMoralePicture(nMyMorale);
	}
}

void SetVariable()
{
	ref tmpref = GetMainCharacter();
	nPlayerMoney = MakeInt(tmpref.Money);
	GameInterface.strings.Money = MakeMoneyShow(nPlayerMoney,MONEY_SIGN,MONEY_DELIVER);
	nCurFourNum = -1;
	GameInterface.strings.Available = nCrewQuantity;
}

void FillFourImage()
{
	int i;
	string tmp1,tmp2,tmpStr;
	int tmpID;
	int bSelected;

	GameInterface.FourImage.current = 0;
	GameInterface.FourImage.BadTwoPicture = "interfaces\blank_ship.tga";
	GameInterface.FourImage.ImagesGroup.t0 = "ICONS";
	GameInterface.FourImage.ImagesGroup.t1 = "SHIPS16";
	GameInterface.FourImage.ImagesGroup.t2 = "SHIPS1";
	GameInterface.FourImage.ImagesGroup.t3 = "SHIPS2";
	GameInterface.FourImage.ImagesGroup.t4 = "SHIPS3";
	GameInterface.FourImage.ImagesGroup.t5 = "SHIPS4";
	GameInterface.FourImage.ImagesGroup.t6 = "SHIPS5";
	ref refMainCh = GetMainCharacter();
	for(i=0; i<COMPANION_MAX; i++)
	{
		bSelected=true;
		tmpID = GetCompanionIndex(refMainCh,i);
		if(tmpID!=-1)
		{
			tmpID = GetCharacterShipType(GetCharacter(tmpID)); // PS
			if(tmpID==SHIP_NOTUSED)
			{
				tmp1="";
				tmp2="";
				bSelected=false;
			}
			else
			{
				tmp1 = ShipsTypes[tmpID].Class;
				tmp2 = ShipsTypes[tmpID].SName; // PS
			}
		}
		else
		{
			tmp1="";
			tmp2="";
			bSelected=false;
		}
		tmpStr = "pic"+(i+1);
		GameInterface.FourImage.(tmpStr).selected	= bSelected;
		GameInterface.FourImage.(tmpStr).img1		= "ship back";
		if(GetShipTexture(tmpID)!=-1)	GameInterface.FourImage.(tmpStr).img2 = GetShipPicName(tmpID); // PS
		GameInterface.FourImage.(tmpStr).str1		= "#"+tmp1;
		GameInterface.FourImage.(tmpStr).str2		= GetShipString(tmpID); //PS tempfix XI_ConvertString(tmp2);
		GameInterface.FourImage.(tmpStr).tex1		= 0;
		GameInterface.FourImage.(tmpStr).tex2		= 1+GetShipTexture(tmpID); // PS
	}
}

void ProcessCancelExit()
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("frame","ProcessFrame");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("HirePress","HireProcess");
	DelEventHandler("FirePress","FireProcess");
	DelEventHandler("HireOk","HireOk");
	DelEventHandler("HireCancel","HireCancel");
	DelEventHandler("DecreaseHire","DecreaseHire");
	DelEventHandler("IncreaseHire","IncreaseHire");
	DelEventHandler("ievnt_command","ProcessCommandExecute");

	SetHireCrewInfo();

	interfaceResultCommand = RC_INTERFACE_HIRECREW_EXIT;
	EndCancelInterface(true);
}

void HireProcess()
{
	nShowType = SHOW_HIRE;
	SetQuantityProcess();
	ChangeHireQuantity(); // PB: Update ship morale
}

void FireProcess()
{
	nShowType = SHOW_FIRE;
	SetQuantityProcess();
}

void SetQuantityProcess()
{
	nAllCrewCost = 0;
	nHireQuantity = 0;
	if(nShowType==SHOW_HIRE)
	{
// KK
		nHireMax = nMaxCrew-nCurCrew;
		nAllCrewCost = nCrewCost * nHireMax;
		while (nAllCrewCost > nPlayerMoney)
		{
			nHireMax--;
			nAllCrewCost -= nCrewCost;
		}
		nHireQuantity = nHireMax;
		if(nHireQuantity > nCrewQuantity) nHireQuantity = nCrewQuantity; // PB: Prevent hiring more crew than is actually there
// <-- KK
	}
	else
	{
		// Aconcagua: use nMinCrew instead of -1 for not being
		// able to fire more than min crew does allow
		nHireMax = nCurCrew-nMinCrew;
	}

	GameInterface.strings.HireQuantity = nHireQuantity; // KK
	GameInterface.strings.Cost = nAllCrewCost;

	SetNodeUsing("HIRE_BUTTON",false);
	SetNodeUsing("FIRE_BUTTON",false);
	SetNodeUsing("HIRE_COUNTER",true);
	SetNodeUsing("HIRE_OK",true);
	SetNodeUsing("HIRE_CANCEL",true);

	EnableString("HireQuantity");

	if(nShowType==SHOW_HIRE)
	{
		EnableString("Cost");
		EnableString("BuyMorale");
		SetNodeUsing("HIRESTRINGS",true);
		SetCurrentNode("HIRE_OK"); // KK
	}
}

void StopQuantityProcess()
{
	SetNodeUsing("HIRE_BUTTON",true);
	SetNodeUsing("FIRE_BUTTON",true);
	SetNodeUsing("HIRE_OK",false);
	SetNodeUsing("HIRE_CANCEL",false);
	SetNodeUsing("HIRE_COUNTER",false);
	if(nShowType==SHOW_HIRE)
	{
		DisableString("Cost");
		DisableString("BuyMorale");
		SetNodeUsing("HIRESTRINGS",false);
	}
	DisableString("HireQuantity");
	SetCurrentNode("HIRE_BUTTON");
}

void HireOk()
{
	ref tmpref = GetMainCharacter();
	if(nShowType==SHOW_HIRE)
	{
		nCrewQuantity = nCrewQuantity - nHireQuantity;
		nCurCrew = nCurCrew + nHireQuantity;
		nMyMorale = nSumMorale;
		nPlayerMoney = nPlayerMoney - nAllCrewCost;

		refMyCrew.Quantity = nCurCrew;
		refMyCrew.Morale = nMyMorale;

		tmpref.Money = nPlayerMoney;
	}
	else
	{
		nCrewQuantity = nCrewQuantity + nHireQuantity;
		nCurCrew = nCurCrew - nHireQuantity;

		refMyCrew.Quantity = nCurCrew;
	}
	StopQuantityProcess();

	GameInterface.strings.Onboard = nCurCrew+"/"+nMaxCrew; // KK

	tmpref.lasthiredate = current_date; // PB: Sets the last hire date
}

void HireCancel()
{
	GameInterface.strings.MyMorale = XI_ConvertString(GetMoraleName(nMyMorale));
	GameInterface.strings.Onboard = nCurCrew+"/"+nMaxCrew;
	GameInterface.strings.Available = nCrewQuantity;
	GameInterface.strings.Money = MakeMoneyShow(nPlayerMoney,MONEY_SIGN,MONEY_DELIVER);
	StopQuantityProcess();
}

void DecreaseHire()
{
	if(nHireQuantity>0)
	{
		nHireQuantity--;
		ChangeHireQuantity();
	}
}

void IncreaseHire()
{
	if(nHireQuantity<nHireMax)
	{
		if(nShowType==SHOW_HIRE)
		{
			if(nPlayerMoney<nAllCrewCost+nCrewCost)
			{
				ShowHelpString("chelp_hirecrew#10");
				return;
			}
			if(nHireQuantity>nCrewQuantity-1)
			{
				ShowHelpString("chelp_hirecrew#11");
				return;
			}
		}
		nHireQuantity++;
		ChangeHireQuantity();
	}
}

void ChangeHireQuantity()
{
	int tmpcrew;
	nAllCrewCost = nCrewCost*nHireQuantity;
	GameInterface.strings.HireQuantity = nHireQuantity;
	GameInterface.strings.Cost = nAllCrewCost;
	if(nShowType==SHOW_HIRE)
	{
		tmpcrew = nCurCrew+nHireQuantity;
		nSumMorale = ((nMyMorale*nCurCrew)+(nCrewMorale*nHireQuantity))/tmpcrew;
		GameInterface.strings.MyMorale = XI_ConvertString(GetMoraleName(nSumMorale));
//		GameInterface.strings.Onboard = tmpcrew+"/"+nMaxCrew;
		GameInterface.strings.Available = nCrewQuantity-nHireQuantity;
		GameInterface.strings.Money = MakeMoneyShow(nPlayerMoney - nAllCrewCost,MONEY_SIGN,MONEY_DELIVER);
	}
	else
	{
		tmpcrew = nCurCrew-nHireQuantity;
//		GameInterface.strings.Onboard = tmpcrew+"/"+nMaxCrew;
		GameInterface.strings.Available = nCrewQuantity+nHireQuantity;
	}
}

string GetMoralePicture(int moraleValue)
{
	if(moraleValue<33) return "low morale";
	if(moraleValue<66) return "medium morale";
	return "high morale";
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	switch(nodName)
	{
	case "HIRE_BUTTON":
		if(comName=="downstep" || comName=="speeddown")
		{
			if(GetSelectable("FIRE_BUTTON"))
			{
				SetCurrentNode("FIRE_BUTTON");
			}
		}
	break;
	}
}

void GetHireCrewInfo()
{
	ref PChar = GetMainCharacter();
	if(ProfessionalNavyNation() == GetCurrentLocationNation())
	{
		nCrewCost = 0;
	}
	else
	{
		nCrewCost = GetCrewHireCost(PChar); // NK 05-04-18 use func in ch ut. 16 - GetShipSkill(GetMainCharacter(),SKILL_LEADERSHIP);
	}
	nCrewMorale = MORALE_NORMAL;
	nCrewQuantity = 0;

	int locIdx = FindLoadedLocation();
	if(locIdx<0) return;

	if( !CheckAttribute(&Locations[locIdx],"townsack") ) return;
	string townName = Locations[locIdx].townsack;

	/*aref arTown,arTownsList;
	makearef(arTownsList,objTownStateTable.towns);
	int i,q;
	q = GetAttributesNum(arTownsList);

	for(i=0; i<q; i++)
	{
		arTown = GetAttributeN(arTownsList,i);
		if(arTown.name == townName)
		{
			break;
		}
	}

	if(i>=q) return;*/
	// NK 05-04-23 switch to towns[]
	ref rTown = GetTownFromID(townName);

	if( CheckAttribute(rTown,"crew.quantity") ) nCrewQuantity = sti(rTown.crew.quantity);
	if( CheckAttribute(rTown,"crew.morale") ) nCrewMorale = sti(rTown.crew.morale);

	// ccc Feb06 minimum crew for hire
	// Changed by PB: The player is no longer forced to wait until the evening

	current_date = environment.date.day + " " + environment.date.month;
	if(!CheckAttribute(PChar, "lasthiredate")) PChar.lasthiredate = "";

	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	if(nCrewQuantity < GetCharacterReputation(PChar) && PChar.lasthiredate != current_date)	// PB: So that the number of crew is not increased the same day
	{nCrewQuantity = 0.75 * GetCharacterReputation(PChar) + 0.5 * rand(GetCharacterReputation(PChar));}	// PB: Add some randomness

/*	PB: Commented out, because we now have a different way of preventing cheating
	if(!CheckAttribute(PChar, "disable_hiring")) // PB: Fix a little bug in the tutorial
	{
		environment.time = 23.0;	// to prevent cheating you can hire only once a day
		Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Mustering those drunken tars takes till nightfall..."));
	}
	LanguageCloseFile(tmpLangFileID); */
//	PlaySound("OBJECTS\abordage\abordage_wining.wav");
//	PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_017.wav");
}

void SetHireCrewInfo()
{
	int locIdx = FindLoadedLocation();
	if(locIdx<0) return;

	if( !CheckAttribute(&Locations[locIdx],"townsack") ) return;
	string townName = Locations[locIdx].townsack;

	/*aref arTown,arTownsList;
	makearef(arTownsList,objTownStateTable.towns);
	int i,q;
	q = GetAttributesNum(arTownsList);

	for(i=0; i<q; i++)
	{
		arTown = GetAttributeN(arTownsList,i);
		if(arTown.name == townName)
		{
			break;
		}
	}

	if(i>=q) return;*/
	// NK 05-04-23 switch to towns[]
	ref rTown = GetTownFromID(townName);

	rTown.crew.quantity = nCrewQuantity;
	rTown.crew.morale = nCrewMorale;
}
