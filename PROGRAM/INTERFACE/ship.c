#define	SM_NONE		0
#define	SM_CANNONS	1
#define	SM_SKILLS	2
#define	SM_CREW		3
#define	SM_SAILS	4
#define	SM_HULL		5

int nShowMode;

bool bEnableInterfaceChange;
int	nCurFourNum;
string oldCurNode;

int explength = 0; // NK

// TODO: allow transfer only ship to ship???

void InitInterface_I(string iniName,int bIState)
{
	nShowMode = SM_NONE;
	bEnableInterfaceChange = bIState;
	if(bIState==false)
	{
	    GameInterface.title = "titleChooseShip";
	}
	else
	{
	    GameInterface.title = "titleShip";
	}
    GameInterface.FourImage.current = 0;

    FillFourImages();

    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();//MAXIMUS: standard exit-string for exit-button

	ref refMyCh = GetMainCharacter();
	if(CheckAttribute(refMyCh,"crewstatus.explength")) explength = sti(refMyCh.crewstatus.explength); // NK
	CreateString(true,"CharName",XI_ConvertString("Noname"),FONT_NORMAL,COLOR_NORMAL,320,198,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"Hull","100%",FONT_BOLD_NUMBERS,COLOR_NORMAL,63,154,SCRIPT_ALIGN_CENTER,0.6); // KK
	CreateString(true,"Sails","100%",FONT_BOLD_NUMBERS,COLOR_NORMAL,191,154,SCRIPT_ALIGN_CENTER,0.6); // KK
	CreateString(true,"Crew","0",FONT_BOLD_NUMBERS,COLOR_NORMAL,447,154,SCRIPT_ALIGN_CENTER,0.6); // KK
	CreateString(true,"QCannons","0",FONT_BOLD_NUMBERS,COLOR_NORMAL,575,154,SCRIPT_ALIGN_CENTER,0.6); // KK
	CreateString(true,"Money",MakeMoneyShow(sti(refMyCh.money),MONEY_SIGN,MONEY_DELIVER),FONT_NORMAL,COLOR_MONEY,320,393,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"ShipName","",FONT_SEADOGS,COLOR_NORMAL,320,234,SCRIPT_ALIGN_CENTER,1.0); // MAXIMUS interface MOD // KK

	CreateString(true,"THull",XI_ConvertString("Hull"),FONT_NORMAL,COLOR_NORMAL,63,34,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"TSails",XI_ConvertString("Sails"),FONT_NORMAL,COLOR_NORMAL,191,34,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"TCrew",XI_ConvertString("Crew"),FONT_NORMAL,COLOR_NORMAL,447,34,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"TCannons",XI_ConvertString("Cannons"),FONT_NORMAL,COLOR_NORMAL,575,34,SCRIPT_ALIGN_CENTER,1.0);

	// none strings
	CreateString(true,"ShipSpeed","0",FONT_NORMAL,COLOR_NORMAL,220,279,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"ShipManeuver","0",FONT_NORMAL,COLOR_NORMAL,220,314,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"ShipMaxCaliber","0",FONT_NORMAL,COLOR_NORMAL,220,349,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"ShipMaxCrew","0",FONT_NORMAL,COLOR_NORMAL,330,279,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"ShipMinCrew","0",FONT_NORMAL,COLOR_NORMAL,330,314,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"ShipCapacity","0",FONT_NORMAL,COLOR_NORMAL,330,349,SCRIPT_ALIGN_LEFT,1.0);
	// summary strings
	CreateString(false,"SummarySkill",XI_ConvertString("Summary Skills")+":",FONT_NORMAL,COLOR_NORMAL,320,264,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,SKILL_LEADERSHIP,"0",FONT_BOLD_NUMBERS,COLOR_NORMAL,252,294,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(false,SKILL_FENCING,"0",FONT_BOLD_NUMBERS,COLOR_NORMAL,252,326,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(false,SKILL_SAILING,"0",FONT_BOLD_NUMBERS,COLOR_NORMAL,252,358,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(false,SKILL_ACCURACY,"0",FONT_BOLD_NUMBERS,COLOR_NORMAL,252,390,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(false,SKILL_CANNONS,"0",FONT_BOLD_NUMBERS,COLOR_NORMAL,252,422,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(false,SKILL_GRAPPLING,"0",FONT_BOLD_NUMBERS,COLOR_NORMAL,416,294,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(false,SKILL_REPAIR,"0",FONT_BOLD_NUMBERS,COLOR_NORMAL,416,326,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(false,SKILL_DEFENCE,"0",FONT_BOLD_NUMBERS,COLOR_NORMAL,416,358,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(false,SKILL_COMMERCE,"0",FONT_BOLD_NUMBERS,COLOR_NORMAL,416,390,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(false,SKILL_SNEAK,"0",FONT_BOLD_NUMBERS,COLOR_NORMAL,416,422,SCRIPT_ALIGN_LEFT,1.0);
	// cannons strings
	CreateString(false,"CannonsName","",FONT_NORMAL,COLOR_NORMAL,320,270,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"FireRange","0",FONT_NORMAL,COLOR_NORMAL,416,310,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(false,"ReloadTime","0",FONT_NORMAL,COLOR_NORMAL,416,336,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(false,"Gunpowder","0",FONT_NORMAL,COLOR_NORMAL,416,362,SCRIPT_ALIGN_RIGHT,1.0);
	if (!CANNONPOWDER_MOD) DisableString("Gunpowder");// TIH mod toggle hide this string of info 7-7-06
	// crew strings
	CreateString(false,"CrewMorale","",FONT_NORMAL,COLOR_NORMAL,320,272,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"RaiseCost","",FONT_NORMAL,COLOR_NORMAL,320,352,SCRIPT_ALIGN_CENTER,1.0);
	// sail strings
	CreateString(false,"SailSpeeding","",FONT_NORMAL,COLOR_NORMAL,320,268,SCRIPT_ALIGN_CENTER,1.0);
		// can`repair of out sailcloth
	CreateString(false,"SRepCantMain",XI_ConvertString("Cannot start repair"),FONT_NORMAL,COLOR_NORMAL,320,300,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"SRepCantSailcloth",XI_ConvertString("Out of sailcloth"),FONT_NORMAL,COLOR_NORMAL,320,328,SCRIPT_ALIGN_CENTER,1.0);
		// can`repair skill not enough
	CreateString(false,"SRepCantSkill1",XI_ConvertString("Repair skill is not"),FONT_NORMAL,COLOR_NORMAL,320,328,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"SRepCantSkill2",XI_ConvertString("high enough"),FONT_NORMAL,COLOR_NORMAL,320,356,SCRIPT_ALIGN_CENTER,1.0);
		// undamaged
	CreateString(false,"SailsUndamaged1",XI_ConvertString("Sails are in"),FONT_NORMAL,COLOR_NORMAL,320,298,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"SailsUndamaged2",XI_ConvertString("a perfect condition"),FONT_NORMAL,COLOR_NORMAL,320,328,SCRIPT_ALIGN_CENTER,1.0);
		// repairing
	CreateString(false,"SRepairing1",XI_ConvertString("Repairing")+"...",FONT_NORMAL,COLOR_NORMAL,320,300,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"SRepairing2","",FONT_NORMAL,COLOR_NORMAL,320,328,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"SRepairing3","",FONT_NORMAL,COLOR_NORMAL,320,356,SCRIPT_ALIGN_CENTER,1.0);
	// hull strings
	CreateString(false,"HullSpeeding","",FONT_NORMAL,COLOR_NORMAL,320,268,SCRIPT_ALIGN_CENTER,1.0);
		// can`repair of out plank
	CreateString(false,"HRepCantMain",XI_ConvertString("Cannot start repair"),FONT_NORMAL,COLOR_NORMAL,320,300,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"HRepCantPlank",XI_ConvertString("Out of planks"),FONT_NORMAL,COLOR_NORMAL,320,328,SCRIPT_ALIGN_CENTER,1.0);
		// can`repair skill not enough
	CreateString(false,"HRepCantSkill1",XI_ConvertString("Repair skill is not"),FONT_NORMAL,COLOR_NORMAL,320,328,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"HRepCantSkill2",XI_ConvertString("high enough"),FONT_NORMAL,COLOR_NORMAL,320,356,SCRIPT_ALIGN_CENTER,1.0);
		// undamaged
	CreateString(false,"HullUndamaged1",XI_ConvertString("Hull is in"),FONT_NORMAL,COLOR_NORMAL,320,298,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"HullUndamaged2",XI_ConvertString("a perfect condition"),FONT_NORMAL,COLOR_NORMAL,320,328,SCRIPT_ALIGN_CENTER,1.0);
		// repairing
	CreateString(false,"HRepairing1",XI_ConvertString("Repairing")+"...",FONT_NORMAL,COLOR_NORMAL,320,300,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"HRepairing2","",FONT_NORMAL,COLOR_NORMAL,320,328,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"HRepairing3","",FONT_NORMAL,COLOR_NORMAL,320,356,SCRIPT_ALIGN_CENTER,1.0);

	if(bIState==false)
	{
		SetNodeUsing("RHULL",false);
		SetSelectable("RHULL",false);
		SetNodeUsing("RSAILS",false);
		SetSelectable("RSAILS",false);
		SetNodeUsing("RFACE",false);
		SetSelectable("RFACE",false);
		SetNodeUsing("RCREW",false);
		SetSelectable("RCREW",false);
		SetNodeUsing("RCANNONS",false);
		SetSelectable("RCANNONS",false);
	}

// MAXIMUS interface MOD -->
	if(GameInterface.title == "titleChooseShip")
	{
		SetNodeUsing("RHULL",false);
		SetSelectable("RHULL",false);
		SetNodeUsing("RSAILS",false);
		SetSelectable("RSAILS",false);
		SetNodeUsing("RFACE",false);
		SetSelectable("RFACE",false);
		SetNodeUsing("RCREW",false);
		SetSelectable("RCREW",false);
		SetNodeUsing("RCANNONS",false);
		SetSelectable("RCANNONS",false);
		
		SetNodeUsing("BOX",false);
		SetSelectable("BOX",false);
		SetNodeUsing("B_SHIPNAME",false);
		SetSelectable("B_SHIPNAME",false);

		SetNodeUsing("I_CHARACTER",false);
		SetSelectable("I_CHARACTER",false);
		SetNodeUsing("I_SHIPHOLD",false);
		SetSelectable("I_SHIPHOLD",false);
		SetNodeUsing("I_PASSENGER",false);
		SetSelectable("I_PASSENGER",false);
		SetNodeUsing("I_QUESTBOOK",false);
		SetSelectable("I_QUESTBOOK",false);
		SetNodeUsing("I_TRADEBOOK",false);
		SetSelectable("I_TRADEBOOK",false);
		SetNodeUsing("I_SHIPLOG",false);
		SetSelectable("I_SHIPLOG",false);
		SetNodeUsing("I_NATIONS",false);
		SetSelectable("I_NATIONS",false);
		SetNodeUsing("I_ITEMS",false);
		SetSelectable("I_ITEMS",false);
	}
// MAXIMUS interface MOD <--

	CreateImage("face","FACE128_"+refMyCh.FaceId,"face",256,42,384,170);
	CreateImage("Hull","SHIP_STATE_ICONS","Hull",0,42,128,170);
	CreateImage("Sails","SHIP_STATE_ICONS","Sails",128,42,256,170);
	CreateImage("Crew","SHIP_STATE_ICONS","Crew",384,42,512,170);
	CreateImage("Cannons","SHIP_STATE_ICONS","Cannons",512,42,640,170);

	GameInterface.renamebox.strdata = "";
	GameInterface.renamebox.maxlen = 32;
	GameInterface.renamebox.maxwidth = 320;

	SetNodeUsing("CANNONS_STRINGS",false);
	SetNodeUsing("CANNONPOWDER_STRINGS",false);// TIH mod toggle can hide this info 7-7-06
	SetNodeUsing("CANNONS_LINES",false);
	SetNodeUsing("SKILL_IMAGES",false);
	SetNodeUsing("CREW_BUTTON",false);
	SetNodeUsing("SAILS_LINES",false);
	SetNodeUsing("RENAMEBOX",false);

// MAXIMUS interface MOD -->
	SetNodeUsing("BOX",false);
	SetNodeUsing("I_KAM_RATIONS",false);
	SetNodeUsing("I_KAM_ARTICLES",false);
	SetNodeUsing("I_MONEY",false);
	SetNodeUsing("I_KAM_SHIPTRANSFER",false);
	SetNodeUsing("I_KAM_SHIPBERTHING",false);
	SetNodeUsing("I_KAM_SELECTSAILS",false);

	if(GameInterface.title == "titleChooseShip")
	{
		SetNodeUsing("I_KAM_SHIPTRANSFER",false);
		SetSelectable("I_KAM_SHIPTRANSFER",false);
	}
	else
	{
		SetNodeUsing("I_KAM_SHIPTRANSFER",true);
// KK --> // added after build 11 by KAM -->
		if(bSeaActive && bDisableMapEnter && !LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm()) {
			SetSelectable("I_KAM_SHIPTRANSFER", false); // so you can't transfer unless can enter map
		} else {
			SetSelectable("I_KAM_SHIPTRANSFER", CheckFleetShips(false));
		}
// <-- added after build 11 by KAM // <-- KK
	}

	SetSelectable("I_SHIPHOLD",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	SetSelectable("I_NATIONS",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	SetSelectable("I_TRADEBOOK",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	// PB SetSelectable("I_QUESTBOOK",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
// KK -->
	SetSelectable("I_SHIPLOG",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());	
	SetSelectable("I_KAM_RATIONS", !LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	SetSelectable("I_KAM_ARTICLES", !LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm() && ProfessionalNavyNation() == UNKNOWN_NATION);
	SetSelectable("I_MONEY", !LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	SetSelectable("I_KAM_SHIPBERTHING", !LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	SetSelectable("I_KAM_SELECTSAILS", !LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
// <-- KK
	if(GameInterface.title=="titleChooseShip")
	{
		SetCurrentNode("SHIPSLIST");
	}
	else
	{
// KK -->
		if (GetCharacterShipType(refMyCh) != SHIP_NOTUSED) {
			SetCurrentNode("RNONE");
		} else {
			SetCurrentNode("RFACE");
			SetSelectable("SHIPSLIST", false);
		}
// <-- KK
	}
	switch(oldCurNode)
	{
		case "I_KAM_SHIPTRANSFER": SetCurrentNode("RNONE"); break; // KK
		case "I_KAM_SHIPBERTHING": SetCurrentNode("RNONE"); break; // KK
		case "I_KAM_ARTICLES": SetCurrentNode("RCREW"); break;
		case "I_KAM_RATIONS": SetCurrentNode("RCREW"); break;
		case "I_MONEY": SetCurrentNode("RCREW"); break;
		case "I_KAM_SELECTSAILS": SetCurrentNode("RSAILS"); break;
	}

	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
// MAXIMUS interface MOD <--

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("frame","ProcessFrame",1);
	SetEventHandler("exitOk","ProcessOkExit",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("RaiseItPress","ProcessRaiseIt",0);
	SetEventHandler("RaiseSelectPress","ProcessRaiseSelect",0);
	SetEventHandler("NodeOk","ProcessNodeOk",0);
	SetEventHandler("NodeCancel","ProcessNodeCancel",0);
	SetEventHandler("ShipNameChange","ProcessShipNameChange",0);
	SetEventHandler("ievntGetHelpTexture","iprocGetHelpTexture",0);

	SetEventHandler("KB_End","WriteName",0); // NK 05-07-21 keyboard
	SetEventHandler("KB_Update", "UpdateName", 0);

	oldCurNode = "SHIPSLIST";
	ProcessFrame();
}

void FillFourImages()
{
	int i;
	string tmp1,tmp2,tmpStr;
	int tmpID;
	int bSelected;
	
	GameInterface.FourImage.current = 0;
	GameInterface.FourImage.BadTwoPicture = "interfaces\blank_ship.tga";
// KK -->
	if (bNewInterface)
		GameInterface.FourImage.ImagesGroup.t0 = "ICONS_NEW";
	else
		GameInterface.FourImage.ImagesGroup.t0 = "ICONS";
// <-- KK
	GameInterface.FourImage.ImagesGroup.t1 = "SHIPS16";
	GameInterface.FourImage.ImagesGroup.t2 = "SHIPS1";
	GameInterface.FourImage.ImagesGroup.t3 = "SHIPS2";
	GameInterface.FourImage.ImagesGroup.t4 = "SHIPS3";
	GameInterface.FourImage.ImagesGroup.t5 = "SHIPS4";
	ref refMainCh = GetMainCharacter();
	for(i=0; i<COMPANION_MAX; i++)
	{
		bSelected=true;
		tmpID = GetCompanionIndex(refMainCh,i);
		if(tmpID!=-1)	tmpID = GetCharacterShipType(GetCharacter(tmpID)); // PS
		else
		{
			tmpStr = "shipslot"+i;
			if(CheckAttribute(refMainCh,tmpStr+".Type"))
				tmpID = sti(refMainCh.(tmpStr).Type);
			else	tmpID = SHIP_NOTUSED;
		}
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
		tmpStr = "pic"+(i+1);
		GameInterface.FourImage.(tmpStr).selected	= bSelected;
		GameInterface.FourImage.(tmpStr).img1		= "ship back";
		if(GetShipTexture(tmpID)!=-1)	GameInterface.FourImage.(tmpStr).img2 = GetShipPicName(tmpID); // PS
		GameInterface.FourImage.(tmpStr).str1		= "#"+tmp1;
		GameInterface.FourImage.(tmpStr).str2		= GetShipString(tmpID); //PS tempfix XI_ConvertString(tmp2);
		GameInterface.FourImage.(tmpStr).tex1		= 0;
		GameInterface.FourImage.(tmpStr).tex2		= 1+GetShipTexture(tmpID); // PS
	}
	nCurFourNum = -1;
}

void ProcessFrame()
{
	float ftmp;
	if(oldCurNode!=GetCurrentNode())
	{
		switch(oldCurNode)
		{
		case "RFACE":		SetPictureBlind("face",false,0,0); break;
		case "RHULL":		SetPictureBlind("Hull",false,0,0); break;
		case "RSAILS":		SetPictureBlind("Sails",false,0,0); break;
		case "RCREW":		SetPictureBlind("Crew",false,0,0); break;
		case "RCANNONS":	SetPictureBlind("Cannons",false,0,0); break;
		case "RENAMEBOX":	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0); break;
		}
		oldCurNode=GetCurrentNode();
		switch(oldCurNode)
		{
		case "SHIPSLIST":
			SetShowMode(SM_NONE);
		break;
		case "RFACE":
			SetShowMode(SM_SKILLS);
			SetPictureBlind("face",true,minBlindColor,maxBlindColor);
		break;
		case "RHULL":
			SetShowMode(SM_HULL);
			SetPictureBlind("Hull",true,minBlindColor,maxBlindColor);
		break;
		case "RSAILS":
			SetShowMode(SM_SAILS);
			SetPictureBlind("Sails",true,minBlindColor,maxBlindColor);
		break;
		case "RCREW":
			SetShowMode(SM_CREW);
			SetPictureBlind("Crew",true,minBlindColor,maxBlindColor);
		break;
		case "RCANNONS":
			SetShowMode(SM_CANNONS);
			SetPictureBlind("Cannons",true,minBlindColor,maxBlindColor);
		break;
		}
	}
    if(sti(GameInterface.FourImage.current)!=nCurFourNum)
    {
		nCurFourNum = sti(GameInterface.FourImage.current);

		ref refMyCh = GetMainCharacter();
		int cn = GetCompanionIndex(refMyCh,nCurFourNum);
		int shipType = SHIP_NOTUSED;
		ref otherCh; // NK move this up here. 05-04-18
		if(cn==-1)
		{
			GameInterface.pictures.face.tex = "";
			string slotName = "ShipSlot"+nCurFourNum;
			if(CheckAttribute(refMyCh,slotName))	shipType = sti(refMyCh.(slotName).Type);
		}
		else
		{
			/*ref*/ otherCh = GetCharacter(cn);
			GameInterface.pictures.face.tex = "FACE128_"+otherCh.FaceId;
			shipType = GetCharacterShipType(otherCh); // PS
		}

		if(shipType!=SHIP_NOTUSED)
		{
			ref refBaseShip = GetShipByType(shipType);
			if(cn==-1)
			{
				GameInterface.strings.ShipName = refMyCh.(slotName).Name; // MAXIMUS interface MOD
//				SendMessage(&GameInterface,"lsls", MSG_INTERFACE_MSG_TO_NODE, "B_SHIPNAME", 0, refMyCh.(slotName).Name); // MAXIMUS interface MOD
				if(CheckAttribute(refMyCh,slotName+".HP"))
				{
					ftmp = GetHullPercent(refMyCh);
					if(ftmp<1.0) {
						GameInterface.strings.Hull = FloatToString(ftmp,1)+"%";
					} else {
						GameInterface.strings.Hull = MakeInt(ftmp)+"%";
					}
				} else {
					GameInterface.strings.Hull = "100%";
				}

				if(CheckAttribute(refMyCh,slotName+".SP"))
				{
					ftmp = GetSailPercent(refMyCh);
					if(ftmp<1.0) {
						GameInterface.strings.Sails = FloatToString(ftmp,1)+"%";
					} else {
						GameInterface.strings.Sails = MakeInt(ftmp)+"%";
					}
				} else {
					GameInterface.strings.Sails = "100%";
				}

				if(CheckAttribute(refMyCh,slotName+".Crew")) {
					GameInterface.strings.Crew = MakeInt(refMyCh.(slotName).Crew);
					SetSelectable("RCrew", true);
				} else {
					GameInterface.strings.Crew = 0;
					SetSelectable("RCREW", false);
				}
				GameInterface.strings.CharName = XI_ConvertString("Noname");
			}
			else
			{
				GameInterface.strings.ShipName = otherCh.Ship.Name; // MAXIMUS interface MOD
//				SendMessage(&GameInterface,"lsls", MSG_INTERFACE_MSG_TO_NODE, "B_SHIPNAME", 0, otherCh.Ship.Name); // MAXIMUS interface MOD
				ftmp = GetHullPercent(otherCh);
				if(ftmp<1.0) {
					GameInterface.strings.Hull = FloatToString(ftmp,1)+"%";
				} else {
					GameInterface.strings.Hull = MakeInt(ftmp)+"%";
				}

				ftmp = GetSailPercent(otherCh);
				if(ftmp<1.0) {
					GameInterface.strings.Sails = FloatToString(ftmp,1)+"%";
				} else {
					GameInterface.strings.Sails = MakeInt(ftmp)+"%";
				}

// KK -->
				// PB -->
				if (GetWoundedCrewQuantity(otherCh) > 0)
					GameInterface.strings.Crew = GetCrewQuantity(otherCh) + "/" + GetWoundedCrewQuantity(otherCh);
				else
					GameInterface.strings.Crew = GetCrewQuantity(otherCh);
				// PB <--
				if (GetTotalCrewQuantity(otherCh) == 0) SetSelectable("RCREW", false);
// <-- KK
				if(CheckAttribute(otherCh,"firstname")==true) GameInterface.strings.CharName = otherCh.name + " " + otherCh.firstname + " " + otherCh.lastname;
				else GameInterface.strings.CharName = otherCh.name + " " + otherCh.lastname;
			}
			aref tmpar; makearef(tmpar, otherCh.ship); // NK can qty 05-04-18
// KK -->
			GameInterface.strings.TCannons = GetCannonName(GetCaracterShipCannonsType(otherCh));
			GameInterface.strings.QCannons = GetLocalShipAttrib(&tmpar,&refBaseShip,"CurCanQty");
			if (sti(GameInterface.strings.QCannons) == 0 && GetCaracterShipCannonsType(refMyCh) == CANNON_TYPE_NONECANNON) {
				SetSelectable("RCANNONS", false);
				GameInterface.strings.QCannons = "";
			}
// <-- KK
		}
		else
		{
			GameInterface.strings.ShipName = XI_ConvertString("Not Used"); // MAXIMUS interface MOD
//			SendMessage(&GameInterface,"lsls", MSG_INTERFACE_MSG_TO_NODE, "B_SHIPNAME", 0, XI_ConvertString("Not Used")); // MAXIMUS interface MOD
			GameInterface.strings.Hull = "100%";
			GameInterface.strings.Sails = "100%";
			GameInterface.strings.Crew = 0;
			GameInterface.strings.CharName = XI_ConvertString("Noname");
// KK -->
			GameInterface.strings.TCannons = GetCannonName(CANNON_TYPE_NONECANNON);
			GameInterface.strings.Cannons = "";
			SetSelectable("RHULL", false);
			SetSelectable("RSAILS", false);
			SetSelectable("RCREW", false);
			SetSelectable("RCANNONS", false);
// <-- KK
		}

		switch(nShowMode)
		{
		case SM_NONE:		SetNoneData();		break;
		case SM_CANNONS:	SetCannonsData();	break;
		case SM_SKILLS:		SetSkillData();		break;
		case SM_CREW:		SetCrewData();		break;
		case SM_SAILS:		SetSailsData();		break;
		case SM_HULL:		SetHullsData();		break;
		}

		if( GetCurrentNode()=="CREW_BUTTON" && !GetSelectable("CREW_BUTTON") ) SetCurrentNode("RCREW");
// MAXIMUS interface MOD -->
		if( GetCurrentNode()=="I_KAM_RATIONS" && !GetSelectable("I_KAM_RATIONS") ) SetCurrentNode("RCREW");

		if( GetCurrentNode()=="I_KAM_ARTICLES" && !GetSelectable("I_KAM_ARTICLES") ) SetCurrentNode("RCREW");

		if( GetCurrentNode()=="I_MONEY" && !GetSelectable("I_MONEY") ) SetCurrentNode("RCREW");

		if( GetCurrentNode()=="I_KAM_SHIPTRANSFER" && !GetSelectable("I_KAM_SHIPTRANSFER") ) SetCurrentNode("RNONE"); // KK

		if( GetCurrentNode()=="I_KAM_SHIPBERTHING" && !GetSelectable("I_KAM_SHIPBERTHING") ) SetCurrentNode("RNONE"); // KK

		if( GetCurrentNode()=="I_KAM_SELECTSAILS" && !GetSelectable("I_KAM_SELECTSAILS") ) SetCurrentNode("RSAILS");

		if( GetCurrentNode()=="I_KAM_SHIPTRANSFER" && !GetSelectable("I_KAM_SHIPTRANSFER") ) SetCurrentNode("SHIPSLIST");

		if( GetCurrentNode()=="I_KAM_SHIPBERTHING" && !GetSelectable("I_KAM_SHIPBERTHING") ) SetCurrentNode("SHIPSLIST");
// MAXIMUS interface MOD <--
    }
}

void ProcessCancelExit()
{
	IDoExit(RC_INTERFACE_SHIPSTATE_EXIT);
}

void ProcessOkExit()
{
	if(!bEnableInterfaceChange)
	{
		if( GetRemovable(GetCharacter(GetCompanionIndex(GetMainCharacter(),nCurFourNum))) )
		{
			interfaceResultCommand = RC_INTERFACE_SHIPSTATE_OK;
			EndOkInterface();
		}
		else
		{
			ShowHelpString("chelp_store#6");
		}
	}
	else
	{
		//oldCurNode = "RFACE";
		SetCurrentNode("RFACE");
		SetShowMode(SM_SKILLS);
	}
}

void IDoExit(int exitCode)
{
// MAXIMUS interface MOD -->
	DelEventHandler("ievnt_command","ProcessCommandExecute");
// MAXIMUS interface MOD <--
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("frame","ProcessFrame");
    DelEventHandler("exitOk","ProcessOkExit");
    DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("RaiseItPress","ProcessRaiseIt");
	DelEventHandler("RaiseSelectPress","ProcessRaiseSelect");
	DelEventHandler("NodeOk","ProcessNodeOk");
	DelEventHandler("NodeCancel","ProcessNodeCancel");
	DelEventHandler("ShipNameChange","ProcessShipNameChange");
	DelEventHandler("ievntGetHelpTexture","iprocGetHelpTexture");

	DelEventHandler("KB_End","WriteName"); // NK Keyboard
	DelEventHandler("KB_Update", "UpdateName");

	interfaceResultCommand = exitCode;
// MAXIMUS interface MOD -->
/*	if(bEnableInterfaceChange)
	{
		if( CheckAttribute(&InterfaceStates,"InstantExit") && sti(InterfaceStates.InstantExit)==true )
		{
			EndCancelInterface(true);
		}
		else
		{
			PostEvent("LaunchIAfterFrame",1,"sl", "I_SELECTMENU", 1);
			EndCancelInterface(false);
		}
	}
	else
	{
		EndCancelInterface(true);
	}*/
	EndCancelInterface(true);
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	int x;ref tmpch;string tmpstr;
	if(nodName=="I_CHARACTER")
	{
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_SHIPSTATE_EXIT;
			EndCancelInterface(false);
		}
	}
	if(nodName=="I_SHIPHOLD")
	{
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_SHIPSTATE_EXIT;
			EndCancelInterface(false);
		}
	}
	if(nodName=="I_PASSENGER")
	{
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_SHIPSTATE_EXIT;
			EndCancelInterface(false);
		}
	}
	if(nodName=="I_QUESTBOOK")
	{
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_SHIPSTATE_EXIT;
			EndCancelInterface(false);
		}
	}
	if(nodName=="I_TRADEBOOK")
	{
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_SHIPSTATE_EXIT;
			EndCancelInterface(false);
		}
	}
	if(nodName=="I_SHIPLOG")
	{
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_SHIPSTATE_EXIT;
			EndCancelInterface(false);
		}
	}
	if(nodName=="I_NATIONS")
	{
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_SHIPSTATE_EXIT;
			EndCancelInterface(false);
		}
	}
	if(nodName=="I_ITEMS")
	{
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_SHIPSTATE_EXIT;
			EndCancelInterface(false);
		}
	}
        if(nodName=="I_KAM_RATIONS")
{
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_SHIPSTATE_EXIT;
		EndCancelInterface(false);

	}
}
        if(nodName=="I_KAM_ARTICLES")
{
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_SHIPSTATE_EXIT;
		EndCancelInterface(false);

	}
}
        if(nodName=="I_MONEY")
{
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_SHIPSTATE_EXIT;
		EndCancelInterface(false);

	}
}
        if(nodName=="I_KAM_SHIPTRANSFER")
{
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_SHIPSTATE_EXIT;
		EndCancelInterface(false);

	}
}
        if(nodName=="I_KAM_SHIPBERTHING")
{
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_SHIPSTATE_EXIT;
		EndCancelInterface(false);

	}
}
        if(nodName=="I_KAM_SELECTSAILS")
{
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_SHIPSTATE_EXIT;
		EndCancelInterface(false);

	}
}

}
// MAXIMUS interface MOD <--

void SetShowMode(int showMode)
{
	if(nShowMode == showMode) return;

	int i; // KK

	switch(nShowMode)
	{
	case SM_NONE:
		SetNodeUsing("I_KAM_SHIPTRANSFER",false);		// MAXIMUS Interface MOD
		SetNodeUsing("I_KAM_SHIPBERTHING",false);		// MAXIMUS Interface MOD
		SetNodeUsing("NONE_IMAGES",false);
		SetNodeUsing("NONE_LINES",false);
		DisableString("ShipSpeed");
		DisableString("ShipManeuver");
		DisableString("ShipMaxCaliber");
		DisableString("ShipMaxCrew");
		DisableString("ShipMinCrew");
		DisableString("ShipCapacity");
		SetNodeUsing("NATION", false);					// PB
// KK -->
		for (i = 0; i < SHIPUPGRADES_QUANTITY; i++) {
			CreateImage("Upgrade" + i + "_Picture", "", "", 428, 265, 458, 293);
		}
// <-- KK
		SetNodeUsing("NATIONALDESIGN",false);				// added by KAM
	break;
	case SM_CANNONS:
		SetNodeUsing("CANNONS_STRINGS",false);
		SetNodeUsing("CANNONPOWDER_STRINGS",false);// TIH mod toggle can hide this info 7-7-06
		SetNodeUsing("CANNONS_LINES",false);
		DisableString("CannonsName");
		DisableString("FireRange");
		DisableString("ReloadTime");
		DisableString("Gunpowder");
	break;
	case SM_SKILLS:
		SetNodeUsing("SKILL_IMAGES",false);
		SetNodeUsing("MONEY_IMAGES",true);
		SetNodeUsing("CONTEXTHELP",true);
		EnableString("Money");
		DisableString("SummarySkill");
		DisableString(SKILL_LEADERSHIP);
		DisableString(SKILL_FENCING);
		DisableString(SKILL_SAILING);
		DisableString(SKILL_ACCURACY);
		DisableString(SKILL_CANNONS);
		DisableString(SKILL_GRAPPLING);
		DisableString(SKILL_REPAIR);
		DisableString(SKILL_DEFENCE);
		DisableString(SKILL_COMMERCE);
		DisableString(SKILL_SNEAK);
	break;
	case SM_CREW:
		SetNodeUsing("I_KAM_RATIONS",false);      // MAXIMUS Interface MOD
		SetNodeUsing("I_KAM_ARTICLES",false);     // MAXIMUS Interface MOD
		SetNodeUsing("I_MONEY",false);            // MAXIMUS Interface MOD
		SetNodeUsing("CREW_BUTTON",false);
		DisableString("CrewMorale");
		DisableString("RaiseCost");
	break;
	case SM_SAILS:
	    SetNodeUsing("I_KAM_SELECTSAILS",false);  // MAXIMUS Interface MOD
		SetNodeUsing("SAILS_LINES",false);
		DisableString("SailSpeeding");
		DisableString("SRepCantMain");
		DisableString("SRepCantSailcloth");
		DisableString("SRepCantSkill1");
		DisableString("SRepCantSkill2");
		DisableString("SailsUndamaged1");
		DisableString("SailsUndamaged2");
		DisableString("SRepairing1");
		DisableString("SRepairing2");
		DisableString("SRepairing3");
	break;
	case SM_HULL:
	    SetNodeUsing("I_KAM_SHIPTRANSFER",false); // MAXIMUS Interface MOD
	    SetNodeUsing("I_KAM_SHIPBERTHING",false); // MAXIMUS Interface MOD
		SetNodeUsing("SAILS_LINES",false);
		DisableString("HullSpeeding");
		DisableString("HRepCantMain");
		DisableString("HRepCantPlank");
		DisableString("HRepCantSkill1");
		DisableString("HRepCantSkill2");
		DisableString("HullUndamaged1");
		DisableString("HullUndamaged2");
		DisableString("HRepairing1");
		DisableString("HRepairing2");
		DisableString("HRepairing3");
	break;
	}

	switch(showMode)
	{
	case SM_NONE:
		SetNodeUsing("I_KAM_SHIPTRANSFER",true);       // MAXIMUS Interface MOD
		SetNodeUsing("I_KAM_SHIPBERTHING",true);       // MAXIMUS Interface MOD
		if(bSeaActive) SetSelectable("I_KAM_SHIPBERTHING",false); // screwface : to avoid errors at sea
		SetNodeUsing("NONE_IMAGES",true);
		SetNodeUsing("NONE_LINES",true);
		EnableString("ShipSpeed");
		EnableString("ShipManeuver");
		EnableString("ShipMaxCaliber");
		EnableString("ShipMaxCrew");
		EnableString("ShipMinCrew");
		EnableString("ShipCapacity");
		SetNodeUsing("NATIONALDESIGN",true);		// added by KAM
		SetNoneData();
	break;
	case SM_CANNONS:
		SetNodeUsing("CANNONS_STRINGS",true);
		if (CANNONPOWDER_MOD) 	SetNodeUsing("CANNONPOWDER_STRINGS",true);// TIH mod toggle to show 7-7-06
		else					SetNodeUsing("CANNONPOWDER_STRINGS",false);// TIH mod toggle to hide 7-7-06
		SetNodeUsing("CANNONS_LINES",true);
		EnableString("CannonsName");
		EnableString("FireRange");
		EnableString("ReloadTime");
		if (CANNONPOWDER_MOD) 	EnableString("Gunpowder");// TIH mod toggle to show 7-7-06
		else 					DisableString("Gunpowder");// TIH mod toggle to hide 7-7-06
	break;
	case SM_SKILLS:
		SetNodeUsing("SKILL_IMAGES",true);
		SetNodeUsing("MONEY_IMAGES",false);
		SetNodeUsing("CONTEXTHELP",false);
		DisableString("Money");
		EnableString("SummarySkill");
		EnableString(SKILL_LEADERSHIP);
		EnableString(SKILL_FENCING);
		EnableString(SKILL_SAILING);
		EnableString(SKILL_ACCURACY);
		EnableString(SKILL_CANNONS);
		EnableString(SKILL_GRAPPLING);
		EnableString(SKILL_REPAIR);
		EnableString(SKILL_DEFENCE);
		EnableString(SKILL_COMMERCE);
		EnableString(SKILL_SNEAK);
	break;
	case SM_CREW:
		SetNodeUsing("I_KAM_RATIONS",true);       // MAXIMUS Interface MOD
		SetNodeUsing("I_KAM_ARTICLES",true);      // MAXIMUS Interface MOD
		SetNodeUsing("I_MONEY",true);             // MAXIMUS Interface MOD
		SetNodeUsing("CREW_BUTTON",true);
		SetSelectable("CREW_BUTTON",false);
		EnableString("CrewMorale");
		EnableString("RaiseCost");
	break;
	case SM_SAILS:
	    SetNodeUsing("I_KAM_SELECTSAILS",true);     // MAXIMUS Interface MOD
	break;
	case SM_HULL:
	    SetNodeUsing("I_KAM_SHIPTRANSFER",true);       // MAXIMUS Interface MOD
	    SetNodeUsing("I_KAM_SHIPBERTHING",true);       // MAXIMUS Interface MOD
		if(bSeaActive) SetSelectable("I_KAM_SHIPBERTHING",false); // screwface : to avoid errors at sea
	break;
	}

	nShowMode = showMode;
	nCurFourNum = -1;
}

void SetNoneData()
{
	ref otherCh;
	ref refMyCh = GetMainCharacter();
	int shipType = SHIP_NOTUSED;

	int cn = GetCompanionIndex(refMyCh,nCurFourNum);
	aref tempref; makearef(tempref, NullCharacter); // PRS3
	if(cn==-1)
	{
		string slotName = "ShipSlot"+nCurFourNum;
		if(CheckAttribute(refMyCh,slotName))
		{
			shipType = GetShipIndex(refMyCh.(slotName).type); // PS
			makearef(tempref, ShipsTypes[shipType]); // PRS3
		}
	}
	else
	{
		otherCh = GetCharacter(cn);
		makearef(tempref, otherCh.ship); // PRS3
		if( CheckAttribute(otherCh,"ship.Type") )	shipType = GetCharacterShipType(otherCh); // PS
	}
	ref refBaseShip;
	int i; // KK

	if(shipType!=SHIP_NOTUSED)
	{
		refBaseShip = GetShipByType(shipType);
		// PRS3 all below
		GameInterface.strings.ShipSpeed      = FloatToString(stf(GetLocalShipAttrib(tempref, refBaseShip, "SpeedRate")),2);
		GameInterface.strings.ShipManeuver   = FloatToString(stf(GetLocalShipAttrib(tempref, refBaseShip, "TurnRate")),2); // MM
		GameInterface.strings.ShipMaxCaliber = sti(GetLocalShipAttrib(tempref, refBaseShip, "MaxCaliber"));
		GameInterface.strings.ShipMaxCrew    = sti(GetLocalShipAttrib(tempref, refBaseShip, "MaxCrew"));
		GameInterface.strings.ShipMinCrew    = sti(GetLocalShipAttrib(tempref, refBaseShip, "MinCrew"));
		GameInterface.strings.ShipCapacity   = sti(GetLocalShipAttrib(tempref, refBaseShip, "Capacity"));
		// PRS3 <--
	// added by KAM -->
		int tempnation;
		if (!CheckShipAttribute(tempref, refBaseShip, "Nation")) // PRS3
		{
			tempnation = UNKNOWN_NATION;
		}
		else
		{
			tempnation = GetLocalShipAttrib(tempref, refBaseShip, "Nation"); // PRS3
		}

// KK -->
		SetNodeUsing("NATION", true); // PB
		if (tempnation >= 0 && tempnation < NATIONS_QUANTITY) {
			SetNewPicture("NATION", "interfaces\flags\Crest_" + GetNationFlagImage(tempnation) + ".tga");
			SetFormatedText("NATIONALDESIGN", XI_ConvertString("2"+Nations[tempnation].desc) + " " + XI_ConvertString("design"));
		} else {
			if(tempnation == PERSONAL_NATION)
			{
				SetNewPicture("NATION", "interfaces\flags\Crest_" + GetNationFlagImage(tempnation) + ".tga");
				SetFormatedText("NATIONALDESIGN", XI_ConvertString("Personal") + " " + XI_ConvertString("design"));
			}
			else
			{
				SetNewPicture("NATION", "interfaces\flags\Crest_Neutral.tga");
				SetFormatedText("NATIONALDESIGN", "Made in Singapore"); // PB: Was XI_ConvertString("Individual design")
			}
		}

		for (i = 0; i < SHIPUPGRADES_QUANTITY; i++) {
			string upgrade_group = "SHIP_UPGRADES";
			string upgrade = GetShipUpgradeID(i);
			if (!CheckTun(cn, upgrade)) {
				if (bNewInterface)
					upgrade_group = "ICONS_NEW";
				else
					upgrade_group = "ICONS";
				upgrade = "empty";
			}
			int shftx = 32 * makeint(2.0 * fmod(makefloat(i) * 2, 2.0));
			if (i >= (SHIPUPGRADES_QUANTITY / 2)) shftx += 32;
			int shfty = 30 * makeint(4.0 * fmod(makefloat(i), 4.0));
			CreateImage("Upgrade" + i + "_Picture", upgrade_group, upgrade, 428 + shftx, 265 + shfty, 458 + shftx, 293 + shfty);
		}
// <-- KK
	// <-- added by KAM
	}
	else
	{
		GameInterface.strings.ShipSpeed = 0;
		GameInterface.strings.ShipManeuver = 0;
		GameInterface.strings.ShipMaxCaliber = 0;
		GameInterface.strings.ShipMaxCrew = 0;
		GameInterface.strings.ShipMinCrew = 0;
		GameInterface.strings.ShipCapacity = 0;
// KK -->
		SetFormatedText("NATIONALDESIGN", "");
		for (i = 0; i < SHIPUPGRADES_QUANTITY; i++) {
			CreateImage("Upgrade" + i + "_Picture", "", "", 428, 265, 458, 293);
		}
// <-- KK
	}

// MAXIMUS interface MOD -->
	if(GameInterface.title == "titleChooseShip")
	{
		SetNodeUsing("I_KAM_SHIPBERTHING",false);
		SetSelectable("I_KAM_SHIPBERTHING",false);
	}
	else
	{
		SetNodeUsing("I_KAM_SHIPBERTHING",true);
		SetSelectable("I_KAM_SHIPBERTHING",true);
		if(bSeaActive) SetSelectable("I_KAM_SHIPBERTHING",false); // screwface : to avoid errors at sea
	}
// MAXIMUS interface MOD <--
}

void SetSkillData()
{
	ref pchar = GetMainCharacter();
	int cn = GetCompanionIndex(pchar,nCurFourNum);
	string skill;
	int n;
	if(cn==-1)
	{
		for(n = 0; n < SKILL_MAX; n++)
		{
			skill = GetSkillName(n);
			GameInterface.strings.(skill) = 0;
		}
	}
	else
	{
		ref otherCh = GetCharacter(cn);
		for(n = 0; n < SKILL_MAX; n++)
		{
			skill = GetSkillName(n);
			int skillval = GetShipSkill(otherCh,skill);
			int modval = CalcCharacterSkill(otherCh,skill);
			int color = COLOR_NORMAL;
			GameInterface.strings.(skill) = skillval;
			if(skillVal < modval)									color = COLOR_RED;
			if(skillVal > modval)									color = COLOR_GREEN;
			if(skillVal == modval && skillVal==MAX_CHARACTER_SKILL)	color = COLOR_MONEY; // PB: Only if the captain has '10'
			if(skillVal==0)         								color = COLOR_GRAY;
			ChangeStringColor(skill,color);
		}
	}
}

void SetCannonsData()
{
	ref cref;
	int ct = CANNON_TYPE_NONECANNON;
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn!=-1)	ct = GetCaracterShipCannonsType(GetCharacter(cn));

	GameInterface.strings.CannonsName = GetCannonName(ct);
	if(ct==CANNON_TYPE_NONECANNON)
	{
		GameInterface.strings.FireRange = "0";
		GameInterface.strings.ReloadTime = "0";
		GameInterface.strings.Gunpowder = "0";
	}
	else
	{
		GameInterface.strings.CannonsName = GetCannonName(ct) + ", " + XI_ConvertString("FBLR") +" " +GetCannonArcQty(GetCharacter(cn), 0)+"/"+GetCannonArcQty(GetCharacter(cn), 2)+"/"+GetCannonArcQty(GetCharacter(cn), 3)+"/"+GetCannonArcQty(GetCharacter(cn), 1);
		cref = GetCannonByType(ct);
		GameInterface.strings.FireRange = FloatToString(stf(cref.FireRange)/3.0,1);		// LDH change feet to yards
		GameInterface.strings.ReloadTime = FloatToString(stf(cref.ReloadTime),1);
		GameInterface.strings.Gunpowder = FloatToString(stf(cref.Gunpowder),1);
	}
}

void SetCrewData()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn==-1)
	{
		GameInterface.strings.CrewMorale = XI_ConvertString("Crew Morale")+": " + XI_ConvertString("NotData");
		GameInterface.strings.RaiseCost = XI_ConvertString("Cost")+": " + "0";
		return;
	}
	ref chref = GetCharacter(cn);
	if( !CheckAttribute(chref,"Ship.Crew.Morale") )
	{
		GameInterface.strings.CrewMorale = XI_ConvertString("Crew Morale")+": " + XI_ConvertString("NotData");
		GameInterface.strings.RaiseCost = XI_ConvertString("Cost")+": " + "0";
		return;
	}
	int crewQuantity = GetCrewQuantity(chref);
	int crewMorale = chref.Ship.Crew.Morale;//sti(chref.Ship.Crew.Morale);
	if( crewQuantity==0 ) crewMorale = MORALE_MAX;
	GameInterface.strings.CrewMorale = XI_ConvertString("Crew Morale")+": " + XI_ConvertString(GetMoraleName(crewMorale)) + ", " + LanguageConvertString(tmpLangFileID,"days out rus") + " " + explength + " " + LanguageConvertString(tmpLangFileID,"days out."); // NK
	if(crewMorale >= MORALE_MAX_RAISE)	GameInterface.strings.RaiseCost = ""; // PB: No value for raising morale if this is not possible
	else
	{
		GameInterface.strings.RaiseCost = XI_ConvertString("Cost")+": " + MakeMoneyShow(GetRaiseMoraleCost(chref),MONEY_SIGN,MONEY_DELIVER); // NK // KK
		if( GetRaiseMoraleCost(chref) <= sti(Characters[GetMainCharacterIndex()].money)) // NK // KK
			SetSelectable("CREW_BUTTON",true);
	}
}

void SetSailsData()
{
	SetNodeUsing("SAILS_LINES",false);
	DisableString("SailSpeeding");
	DisableString("SRepCantMain");
	DisableString("SRepCantSailcloth");
	DisableString("SRepCantSkill1");
	DisableString("SRepCantSkill2");
	DisableString("SailsUndamaged1");
	DisableString("SailsUndamaged2");
	DisableString("SRepairing1");
	DisableString("SRepairing2");
	DisableString("SRepairing3");

	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn==-1)
	{
		EnableString("SailsUndamaged1");
		EnableString("SailsUndamaged2");
		return;
	}

	ref chref = GetCharacter(cn);
	int sailsPercent = makeint(GetSailPercent(chref));

	if(sailsPercent>=100)
	{
		EnableString("SailsUndamaged1");
		EnableString("SailsUndamaged2");
		return;
	}

	SetNodeUsing("SAILS_LINES",true);
	EnableString("SailSpeeding");
	if(GetSpeedPercentDecreased(chref)>0)
		GameInterface.strings.SailSpeeding = XI_ConvertString("Ship speed decreased by")+" " + GetSpeedPercentDecreased(chref)+"%";
	else
		GameInterface.strings.SailSpeeding = XI_ConvertString("full speed");

	if( !AvalableForRepairSails(chref) )
	{
		EnableString("SRepCantMain");
		return;
	}

	if( GetCargoGoods(chref,GOOD_SAILCLOTH)<=0 )
	{
		EnableString("SRepCantMain");
		EnableString("SRepCantSailcloth");
		return;
	}

	EnableString("SRepairing1");
	EnableString("SRepairing2");
	EnableString("SRepairing3");
	GameInterface.strings.SRepairing2 = XI_ConvertString("Skill")+" ----- "+GetShipSkill(chref,SKILL_REPAIR);
	GameInterface.strings.SRepairing3 = FloatToString(GetSailRPD(chref),2)+"% " + XI_ConvertString("per day");

	SetSelectable("I_KAM_SELECTSAILS",true); // MAXIMUS interface MOD
}

void SetHullsData()
{
	SetNodeUsing("SAILS_LINES",false);
	DisableString("HullSpeeding");
	DisableString("HRepCantMain");
	DisableString("HRepCantPlank");
	DisableString("HRepCantSkill1");
	DisableString("HRepCantSkill2");
	DisableString("HullUndamaged1");
	DisableString("HullUndamaged2");
	DisableString("HRepairing1");
	DisableString("HRepairing2");
	DisableString("HRepairing3");

	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn==-1)
	{
		EnableString("HullUndamaged1");
		EnableString("HullUndamaged2");
		return;
	}

	ref chref = GetCharacter(cn);
	int hullPercent = makeint(GetHullPercent(chref));
	if(hullPercent>=100)
	{
		EnableString("HullUndamaged1");
		EnableString("HullUndamaged2");
		return;
	}

	SetNodeUsing("SAILS_LINES",true);
	EnableString("HullSpeeding");
	if(GetSpeedPercentDecreased(chref)>0)
		GameInterface.strings.HullSpeeding = XI_ConvertString("Ship speed decreased by")+" " + GetSpeedPercentDecreased(chref)+"%";
	else
		GameInterface.strings.HullSpeeding = XI_ConvertString("full speed");

	if( GetCargoGoods(chref,GOOD_PLANKS)<=0 )
	{
		EnableString("HRepCantMain");
		EnableString("HRepCantPlank");
		return;
	}

	EnableString("HRepairing1");
	EnableString("HRepairing2");
	EnableString("HRepairing3");
	GameInterface.strings.HRepairing2 = XI_ConvertString("Skill")+" ----- "+GetShipSkill(chref,SKILL_REPAIR);
	GameInterface.strings.HRepairing3 = FloatToString(GetHullRPD(chref),2)+"% " + XI_ConvertString("per day");

	SetSelectable("I_KAM_SHIPBERTHING",true); // MAXIMUS interface MOD
}

// string GetCannonName() moved to interface\utilite.c and updated for KNB. NK 05-04-10

int GetSpeedPercentDecreased(ref chref)
{
	if( !CheckAttribute(chref,"Ship.SP") ) return 0;
	if( GetSailPercent(chref)>=100.0 ) return 0;
	aref aroot,agr,asail;
	makearef(aroot,chref.ship.sails);
	int i,j;
	float fspeed = 0.0;
	for(i=0; i<GetAttributesNum(aroot); i++)
	{
		agr = GetAttributeN(aroot,i);
		for(j=0; j<GetAttributesNum(agr); j++)
		{
			asail = GetAttributeN(agr,j);
			fspeed += funcGetSailSpeed( sti(asail.hc), sti(asail.mhc), stf(asail.sp) );
		}
	}
	return makeint(fspeed*100.0+0.5);
}

void ProcessRaiseIt()
{
	if( !GetSelectable("CREW_BUTTON") ) return;
	ref mchref = GetMainCharacter();
	int cn = GetCompanionIndex(mchref, nCurFourNum);
	if(cn==-1)	return;
	ref chref = GetCharacter(cn);
	int raiseCost = GetRaiseMoraleCost(chref);
	if (raiseCost > sti(mchref.money) ) return; // NK // KK
	if (!CheckAttribute(chref, "Ship.Crew.Morale")) return;
	AddMoneyToCharacter(mchref, -raiseCost); // KK
	int crewMorale = sti(chref.Ship.Crew.Morale) + 10; // KK
	if (crewMorale > MORALE_MAX) crewMorale = MORALE_MAX;
	chref.Ship.Crew.Morale = crewMorale;
	if (CheckAttribute(chref, "seatime.tempmorale")) chref.seatime.tempmorale = stf(chref.seatime.tempmorale) + 10.0; // NK 04-09-22 if using tempmorale
	if (CheckAttribute(chref, "seatime.basecrewmorale") && sti(chref.seatime.basecrewmorale) < MORALE_MAX_RAISE) chref.seatime.basecrewmorale = stf(chref.seatime.basecrewmorale) + 10.0; // NK 05-04-20 if using basecrewmorale
	GameInterface.strings.Money = MakeMoneyShow(sti(mchref.money), MONEY_SIGN,MONEY_DELIVER);
	nCurFourNum = -1;
	SetSelectable("CREW_BUTTON",false);
}

void ProcessRaiseSelect()
{
	if( GetSelectable("CREW_BUTTON") )
	{
		SetCurrentNode("CREW_BUTTON");
	}
}

bool AvalableForRepairSails(ref chref)
{
	int i,j;
	aref sroot,snod,sref;
	string tmpstr;
	bool IsAvalable = true;

	int avlCount=0;
	makearef(sroot,chref.ship.sails);
	for(i=0;i<GetAttributesNum(sroot);i++)
	{
		snod = GetAttributeN(sroot,i);
		for(j=0;j<GetAttributesNum(snod);j++)
		{
			sref = GetAttributeN(snod,j);
			if( CheckAttribute(sref,"mastFall") )
			{
				tmpstr = "ship.masts."+sref.mastFall;
				if( CheckAttribute(chref,tmpstr) && stf(chref.(tmpstr))>=1.0 )
				{
					IsAvalable = false;
					continue;
				}
			}
			return true;
		}
	}
	return IsAvalable;
}

void ProcessNodeOk()
{
	string nodName = GetEventData();
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
	if( CheckAttribute(&GameInterface,nodName+".strdata") )
	{
		string str = GameInterface.(nodName).strdata;
		SetCurrentNode("B_SHIPNAME");
		SetShipName(str);
		GameInterface.strings.ShipName = str; // MAXIMUS interface MOD
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
	SetCurrentNode("B_SHIPNAME");
}

void ProcessShipNameChange()
{
	SetNodeUsing("BOX",true); // MAXIMUS interface MOD
	SetCurrentNode("BOX"); // MAXIMUS interface MOD
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "BOX"); // KK
	KB_SetKeyboardMode(true);
	KB_Prepare(GameInterface.strings.ShipName); // KK
}

void UpdateName()
{
	GameInterface.strings.ShipName = KeyboardDisplayString; // MAXIMUS interface MOD // KK
}

void WriteName()
{
	if(KeyboardString != "")
	{
		SetShipName(KeyboardString);
		GameInterface.strings.ShipName = KeyboardString; // MAXIMUS interface MOD
	}
// added by MAXIMUS for cancel possibility without changing name -->
	else
	{
	  int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);	// TIH runtime error bug fix Jul10'06
	  if(cn!=-1)
	  {
		ref chref = GetCharacter(cn);
		GameInterface.strings.ShipName = chref.ship.name;
	  }
		ProcessNodeCancel();
	}
// added by MAXIMUS for cancel possibility without changing name <--
	SetNodeUsing("BOX",false); // MAXIMUS interface MOD
}

void SetShipName(string newName)
{
	ref chref = GetMainCharacter();
	int cn = GetCompanionIndex(chref,nCurFourNum);
	if(cn!=-1)
	{
		chref = GetCharacter(cn);
		chref.ship.name = newName;
	}
	CharShipName = chref.ship.name; // added by MAXIMUS
}

string I_strRetVal;
ref iprocGetHelpTexture()
{
	string nodName = GetEventData();

	I_strRetVal = "";

	if(!bEnableInterfaceChange)
	{
		I_strRetVal = "interfaces\help\store\store_prepare.tga";
	}

	return &I_strRetVal;
}
