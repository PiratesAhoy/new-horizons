int nCurScrollNum;
int nCurFourNum;

string tempship; // MAXIMUS interface MOD
string tempcannon; // MAXIMUS interface MOD
int tmpLangFileID; // MAXIMUS interface MOD
int cannonqtys[4]; // KK
int cannoniqty = 0; // KK
int topay = 0; // KK

void InitInterface(string iniName)
{
	if (!LAi_IsCapturedLocation)
		GameInterface.title = "titleCannons";
	else
		GameInterface.title = "titleRansack";

// MAXIMUS cannons MOD -->
	ref xi_refCharacter = GetMainCharacter();
	ref refMyCompanions = GetCharacter(GetCompanionIndex(xi_refCharacter,nCurFourNum));
	int ourQty = 0;
	
	// TIH --> attribute check fix 7-7-06
	if (CheckAttribute(xi_refCharacter,"ship.Cannons.Borts.cannonf.qty")) {
		ourQty = sti(xi_refCharacter.ship.Cannons.Borts.cannonf.qty);
		xi_refCharacter.ship.Cannons.Borts.cannonf.curqty = ourQty;
	}
	if (CheckAttribute(xi_refCharacter,"ship.Cannons.Borts.cannonb.qty")) {
		ourQty = sti(xi_refCharacter.ship.Cannons.Borts.cannonb.qty);
		xi_refCharacter.ship.Cannons.Borts.cannonb.curqty = ourQty;
	}
	if (CheckAttribute(xi_refCharacter,"ship.Cannons.Borts.cannonl.qty")) {
		ourQty = sti(xi_refCharacter.ship.Cannons.Borts.cannonl.qty);
		xi_refCharacter.ship.Cannons.Borts.cannonl.curqty = ourQty;
	}
	if (CheckAttribute(xi_refCharacter,"ship.Cannons.Borts.cannonr.qty")) {
		ourQty = sti(xi_refCharacter.ship.Cannons.Borts.cannonr.qty);
		xi_refCharacter.ship.Cannons.Borts.cannonr.curqty = ourQty;
	}
	if (CheckAttribute(refMyCompanions,"ship.Cannons.Borts.cannonf.qty")) {
		ourQty = sti(refMyCompanions.ship.Cannons.Borts.cannonf.qty);
		refMyCompanions.ship.Cannons.Borts.cannonf.curqty = ourQty;
	}
	if (CheckAttribute(refMyCompanions,"ship.Cannons.Borts.cannonb.qty")) {
		ourQty = sti(refMyCompanions.ship.Cannons.Borts.cannonb.qty);
		refMyCompanions.ship.Cannons.Borts.cannonb.curqty = ourQty;
	}
	if (CheckAttribute(refMyCompanions,"ship.Cannons.Borts.cannonl.qty")) {
		ourQty = sti(refMyCompanions.ship.Cannons.Borts.cannonl.qty);
		refMyCompanions.ship.Cannons.Borts.cannonl.curqty = ourQty;
	}
	if (CheckAttribute(refMyCompanions,"ship.Cannons.Borts.cannonr.qty")) {
		ourQty = sti(refMyCompanions.ship.Cannons.Borts.cannonr.qty);
		refMyCompanions.ship.Cannons.Borts.cannonr.curqty = ourQty;
	}
	// TIH <-- attribute check fix

	FillFourImage();
	FillScroll();
	GameInterface.FourImage.current = 0;	nCurFourNum = -1;
// KK -->
	GameInterface.scrollcannons.current = 0;
	int cnCannonType = GetCaracterShipCannonsType(xi_refCharacter);
	if (cnCannonType != CANNON_TYPE_NONECANNON) {
		int i = 0;
		int j = 0;
		while (i < CANNON_TYPES_QUANTITY) {
			if (CheckAttribute(&cannon[i], "TradeOff") && sti(cannon[i].TradeOff) == true) {
				i++;
				continue;
			}
			string attributeName = "pic" + (i + 1);
			if (CheckAttribute(&GameInterface, "scrollcannons." + attributeName + ".spec2") == true && GameInterface.scrollcannons.(attributeName).spec2 == true) {
				i++;
				continue;
			}
			if (cnCannonType == i) {
				GameInterface.scrollcannons.current = j;
				break;
			}
			i++;
			j++;
		}
	}
	nCurScrollNum = -1;
// <-- KK
// MAXIMUS cannons MOD <--

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

	CreateExitString();
	CreateString(true,"Money",MakeMoneyShow(sti(Characters[GetMainCharacterIndex()].Money),"","."),FONT_NORMAL,COLOR_MONEY,320,385,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"ShipName","",FONT_NORMAL,COLOR_NORMAL,320,181,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"FireRange","",FONT_NORMAL,COLOR_NORMAL,400,216,SCRIPT_ALIGN_RIGHT,0.8);
	CreateString(true,"ReloadTime","",FONT_NORMAL,COLOR_NORMAL,400,241,SCRIPT_ALIGN_RIGHT,0.8);
	CreateString(true,"Gunpowder","",FONT_NORMAL,COLOR_NORMAL,400,266,SCRIPT_ALIGN_RIGHT,0.8);
	if (!CANNONPOWDER_MOD) DisableString("Gunpowder");// TIH mod toggle to hide this string of info 7-7-06
	if (!CANNONPOWDER_MOD) SetNodeUsing("CANNONPOWDER_STRINGS",false);// TIH mod toggle to hide this string of info 7-7-06
	CreateString(true,"Cost","",FONT_NORMAL,COLOR_NORMAL,400,291,SCRIPT_ALIGN_RIGHT,0.8);

	CreateString(true,"CostUnit","",FONT_NORMAL,COLOR_NORMAL,400,316,SCRIPT_ALIGN_RIGHT,0.8); // MAXIMUS cannons MOD
	// KK CreateString(true,"BuyQuantity","",FONT_NORMAL,COLOR_NORMAL,320,352,SCRIPT_ALIGN_CENTER,1.0); // MAXIMUS cannons MOD
	// KK CreateString(true,"RepairCannonsCost","",FONT_NORMAL,COLOR_NORMAL,426,282,SCRIPT_ALIGN_LEFT,1.0); // MAXIMUS cannons MOD

	CreateString(false,"HelpString","",FONT_NORMAL,COLOR_NORMAL,320,420,SCRIPT_ALIGN_CENTER,0.8); // MAXIMUS interface MOD
	CreateString(false,"Installed","",FONT_NORMAL,COLOR_NORMAL,320,455,SCRIPT_ALIGN_CENTER,0.8); // MAXIMUS interface MOD
	CreateString(false,"Installed_1","",FONT_NORMAL,COLOR_NORMAL,320,475,SCRIPT_ALIGN_CENTER,0.8); // MAXIMUS interface MOD

	ProcessFrame();
	SetNodeUsing("BOX",false);
	SetSelectable("EXIT_BUTTON",true);
	SetRepairData();
	ChangeScroll();// TIH cannon selection visual adjustment Jul12'06

// MAXIMUS cannons MOD -->
	SetNodeUsing("CONFIRM_RECTANGLE",false);
	SetNodeUsing("TEXTWINDOW",false);
	SetNodeUsing("CONFIRM_YES_BUTTON",false);
	SetNodeUsing("CONFIRM_NO_BUTTON",false);
	SetNodeUsing("REPAIR_YES_BUTTON",false);
	SetNodeUsing("REPAIR_NO_BUTTON",false);
	SetNewPicture("CAN_PIC", "interfaces\cannon.tga");
	SetNewPicture("CAN_PIC1", "interfaces\cannon.tga");
	SetNewPicture("CAN_PIC2", "interfaces\cannon.tga");
	SetNodeUsing("CAN_PIC",false);
	SetNodeUsing("CAN_PIC1",false);
	SetNodeUsing("CAN_PIC2",false);
// MAXIMUS cannons MOD <--

// KK -->
	SetNodeUsing("CANCEL_BUTTON", false);
	SetNodeUsing("BUY_BUTTON", false);
	SetNodeUsing("CANNONLOCATIONS_STRINGS", false);
	SetNodeUsing("FRONTCANNONSQTY", false);
	SetNodeUsing("LEFTARCCANNONSQTY", false);
	SetNodeUsing("RIGHTARCCANNONSQTY", false);
	SetNodeUsing("BACKCANNONSQTY", false);
	
	CreateString(false, "front_cannons_qty", "0", FONT_NORMAL, COLOR_NORMAL, 364, 218, SCRIPT_ALIGN_CENTER, 0.8);
	CreateString(false, "leftarc_cannons_qty", "0", FONT_NORMAL, COLOR_NORMAL, 299, 257, SCRIPT_ALIGN_CENTER, 0.8);
	CreateString(false, "rightarc_cannons_qty", "0", FONT_NORMAL, COLOR_NORMAL, 429, 257, SCRIPT_ALIGN_CENTER, 0.8);
	CreateString(false, "back_cannons_qty", "0", FONT_NORMAL, COLOR_NORMAL, 364, 296, SCRIPT_ALIGN_CENTER, 0.8);
	CreateString(false, "cannons_cost", "0", FONT_NORMAL, COLOR_NORMAL, 234, 345, SCRIPT_ALIGN_RIGHT, 0.8);
// <-- KK

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("frame","ProcessFrame",1);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("InstallPress","ProcessInstall",0);
//	SetEventHandler("InstallBuyPress","ProcessInstallAndBuy",0); // KK // LDH commented out as it was being called extra times - 09Feb09
	SetEventHandler("BuyPress","ProcessBuy",0); // KK 	// LDH this may need to be commented out as well if it gets called extra times
	SetEventHandler("installSelect","ProcessInstallSelect",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
// MAXIMUS cannons MOD -->
	SetEventHandler("CancelPress","ProcessCancel",0);
	SetEventHandler("RepairNo","ProcessRepair_no",0);
	SetEventHandler("RepairYes","ProcessRepair_yes",0);
	SetEventHandler("ExitPress","ProcessExit",0);
	SetEventHandler("ExitNo","ProcessExit_no",0);
	SetEventHandler("ExitYes","ProcessExit_yes",0);
// MAXIMUS cannons MOD <--
}

// MAXIMUS cannons MOD -->
void ProcessExit()
{
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn<0) return;

// KK -->
//	int Qty = GetCannonCurQuantity(GetCharacter(cn));
//	int curQty = sti(GetCannonQuantity(GetCharacter(cn))-Qty);
	bool temp = true;
	temp = temp && (cannonqtys[0] != GetCannonArcQty(GetCharacter(cn), 0));
	temp = temp && (cannonqtys[1] != GetCannonArcQty(GetCharacter(cn), 1));
	temp = temp && (cannonqtys[2] != GetCannonArcQty(GetCharacter(cn), 2));
	temp = temp && (cannonqtys[3] != GetCannonArcQty(GetCharacter(cn), 3));
// <-- KK

	if (!temp) // KK
	{
      DelEventHandler("InterfaceBreak","ProcessCancelExit");
      DelEventHandler("frame","ProcessFrame");
      DelEventHandler("exitCancel","ProcessCancelExit");
      DelEventHandler("InstallPress","ProcessInstall");
      DelEventHandler("BuyPress","ProcessBuy"); // KK
//    DelEventHandler("InstallBuyPress","ProcessInstallAndBuy"); // KK // Commented out by LDH 09Feb09
      DelEventHandler("installSelect","ProcessInstallSelect");
      DelEventHandler("ievnt_command","ProcessCommandExecute");
      DelEventHandler("CancelPress","ProcessCancel");
      DelEventHandler("RepairNo","ProcessRepair_no");
      DelEventHandler("RepairYes","ProcessRepair_yes");
      DelEventHandler("ExitPress","ProcessExit");
      DelEventHandler("ExitNo","ProcessExit_no");
      DelEventHandler("ExitYes","ProcessExit_yes");

      interfaceResultCommand = RC_INTERFACE_CANNONS_EXIT;
      EndCancelInterface(true);
	}
	else
	{
      SetNodeUsing("CONFIRM_RECTANGLE",true);
      SetNodeUsing("TEXTWINDOW",true);
      SetNodeUsing("REPAIR_YES_BUTTON",true);
      SetNodeUsing("REPAIR_NO_BUTTON",true);
      SetNodeUsing("CAN_PIC1",true);
      SetNodeUsing("CAN_PIC2",true);
      SetCurrentNode("REPAIR_NO_BUTTON");
      SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "REPAIR_NO_BUTTON");
      SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "REPAIR_YES_BUTTON");

      int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
      SetFormatedText("TEXTWINDOW",LanguageConvertString(tmpLangFileID,"Exit from cannons confirm"));
      LanguageCloseFile(tmpLangFileID);
	}
}

void ProcessExit_no()
{
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);

	SetNodeUsing("CONFIRM_RECTANGLE",false);
	SetNodeUsing("TEXTWINDOW",false);
	SetNodeUsing("REPAIR_YES_BUTTON",false);
	SetNodeUsing("REPAIR_NO_BUTTON",false);
	SetNodeUsing("CAN_PIC1",false);
	SetNodeUsing("CAN_PIC2",false);

	SetCurrentNode("CANNONSQUANTITY");
}

void ProcessExit_yes()
{
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn<0) return;

	int Qty = GetCannonCurQuantity(GetCharacter(cn));
	int curQty = sti(GetCannonQuantity(GetCharacter(cn))-Qty);

	if(curQty>0)
	{
		ref curChr = GetCharacter(cn);
		int ourQty = 0;
		
		ourQty = sti(curChr.ship.Cannons.Borts.cannonf.curqty);
		curChr.ship.Cannons.Borts.cannonf.qty = ourQty;
		
		ourQty = sti(curChr.ship.Cannons.Borts.cannonb.curqty);
		curChr.ship.Cannons.Borts.cannonb.qty = ourQty;
		
		ourQty = sti(curChr.ship.Cannons.Borts.cannonl.curqty);
		curChr.ship.Cannons.Borts.cannonl.qty = ourQty;
		
		ourQty = sti(curChr.ship.Cannons.Borts.cannonr.curqty);
		curChr.ship.Cannons.Borts.cannonr.qty = ourQty;
		
		DelEventHandler("InterfaceBreak","ProcessCancelExit");
		DelEventHandler("frame","ProcessFrame");
		DelEventHandler("exitCancel","ProcessCancelExit");
		DelEventHandler("InstallPress","ProcessInstall");
		DelEventHandler("BuyPress","ProcessBuy"); // KK
//		DelEventHandler("InstallBuyPress","ProcessInstallAndBuy"); // KK // Commented out by LDH 09Feb09
		DelEventHandler("installSelect","ProcessInstallSelect");
		DelEventHandler("ievnt_command","ProcessCommandExecute");
		DelEventHandler("CancelPress","ProcessCancel");
		DelEventHandler("RepairNo","ProcessRepair_no");
		DelEventHandler("RepairYes","ProcessRepair_yes");
		DelEventHandler("ExitPress","ProcessExit");
		DelEventHandler("ExitNo","ProcessExit_no");
		DelEventHandler("ExitYes","ProcessExit_yes");
		
		interfaceResultCommand = RC_INTERFACE_CANNONS_EXIT;
		EndCancelInterface(true);
	}
	else
	{
		DelEventHandler("InterfaceBreak","ProcessCancelExit");
		DelEventHandler("frame","ProcessFrame");
		DelEventHandler("exitCancel","ProcessCancelExit");
		DelEventHandler("InstallPress","ProcessInstall");
		DelEventHandler("BuyPress","ProcessBuy"); // KK
//		DelEventHandler("InstallBuyPress","ProcessInstallAndBuy"); // KK // Commented out by LDH 09Feb09
		DelEventHandler("installSelect","ProcessInstallSelect");
		DelEventHandler("ievnt_command","ProcessCommandExecute");
		DelEventHandler("CancelPress","ProcessCancel");
		DelEventHandler("RepairNo","ProcessRepair_no");
		DelEventHandler("RepairYes","ProcessRepair_yes");
		DelEventHandler("ExitPress","ProcessExit");
		DelEventHandler("ExitNo","ProcessExit_no");
		DelEventHandler("ExitYes","ProcessExit_yes");
		
		interfaceResultCommand = RC_INTERFACE_CANNONS_EXIT;
		EndCancelInterface(true);
	}
	if(tradeHigh==true) tradeHigh = false; // added by MAXIMUS [possibility to repair your ship by double price]
}
// MAXIMUS cannons MOD <--

void ProcessFrame()
{
	if(sti(GameInterface.scrollcannons.current)!=nCurScrollNum)
	{
		nCurScrollNum = sti(GameInterface.scrollcannons.current);
		ref rcann = GetCannonByType(GetChoosedCannonType());
		GameInterface.strings.FireRange = sti(rcann.FireRange)/3;	// LDH change feet to yards
		GameInterface.strings.ReloadTime = sti(rcann.ReloadTime);
		GameInterface.strings.Gunpowder = sti(rcann.Gunpowder);
		nCurFourNum = -1;
		EnableString("HelpString");
		SetNodeUsing("BOX1",true);
	}

	int canbuymax = GetCanBuyQuantity();
//	trace("ProcessFrame: canbuymax="+canbuymax);	// LDH commented out 21Dec08

	if(sti(GameInterface.FourImage.current)!=nCurFourNum)
	{
		nCurFourNum = sti(GameInterface.FourImage.current);
		//ref rcn = GetCannonByType(GetChoosedCannonType());
		EnableString("Installed");
		EnableString("Installed_1");
		ref refMyCh = GetMainCharacter();
		int cn = GetCompanionIndex(refMyCh,nCurFourNum);
		if (cn==-1) {
			SetSelectable("BUY_BUTTON",false);
			GameInterface.strings.ShipName = "";
			GameInterface.strings.Cost = "0";
		} else {
// KK -->
			cannonqtys[0] = GetCannonArcQty(GetCharacter(cn), 0);
			cannonqtys[1] = GetCannonArcQty(GetCharacter(cn), 1);
			cannonqtys[2] = GetCannonArcQty(GetCharacter(cn), 2);
			cannonqtys[3] = GetCannonArcQty(GetCharacter(cn), 3);
			cannoniqty = cannonqtys[0] + cannonqtys[1] + cannonqtys[2] + cannonqtys[3];
			GameInterface.strings.ShipName = GetMyShipName(GetCharacter(cn)) + " - " + cannoniqty +" "+ XI_ConvertString("un")+".";
// <-- KK
			// changed by MAXIMUS [possibility to repair your ship by double price] -->
			int cost = canbuymax * CalcCannonExchangeCost();
			if (cost < 0) cost = 0;
			//if (tradeHigh) cost *= 2;
			//GameInterface.strings.Cost = cost;

			// LDH 09Feb09 -->
			if (GetCaracterShipCannonsType(GetCharacter(cn)) != GetChoosedCannonType()) 
			{
				cost = SellCannons(GetCharacter(cn), GetCannonQuantity(GetCharacter(cn)));
				cost += BuyCannons(GetCharacter(cn), GetChoosedCannonType(), GetMaxCannonQuantity(GetCharacter(cn)));
			}
			else
			{
				int gunsMissing = GetMaxCannonQuantity(GetCharacter(cn)) - GetCannonQuantity(GetCharacter(cn));
				if (gunsMissing)
				{
					cost = BuyCannons(GetCharacter(cn), GetChoosedCannonType(), gunsMissing);
				}
			}
			GameInterface.strings.Cost = cost;
			cost = BuyCannons(GetCharacter(cn), GetChoosedCannonType(),1);

//			GameInterface.strings.CostFull = cost;			// LDH commented out 09Feb09
//			cost = GetCannonPrice(GetChoosedCannonType());	// LDH commented out 09Feb09
			// LDH <--

			if (tradeHigh) cost *= 2;
			GameInterface.strings.CostUnit = cost;
			// changed by MAXIMUS [possibility to repair your ship by double price] <--
			DisableString("HelpString");
			SetNodeUsing("BOX1",false);
		}
		//SetSelectable("REPAIR_OK",true); // MAXIMUS cannons MOD
		//SetSelectable("CANNONSQUANTITY",true); // MAXIMUS cannons MOD
		int isSelectable = CheckInstallEnable();
		SetSelectable("INSTALL_BUTTON", isSelectable > 0);
		SetSelectable("INSTALLBUY_BUTTON", isSelectable == 2);
		//SetSelectable("INSTALL_BUTTON", true); // KK
//		SetRepairData();
		ChangeScroll();// TIH cannon selection visual adjustment Jul12'06
	}
}

void FillScroll()
{
	int i, idx;
	string attributeName;
    aref pRef;

	GameInterface.scrollcannons.ImagesGroup.t1 = "ICONS";
	idx=0;
	// KNB -->
	GameInterface.scrollcannons.ImagesGroup.t2 = "CANNONS";
	GameInterface.scrollcannons.ImagesGroup.t3 = "installedflag";	// TIH cannon selection visual adjustment Jul12'06
	GameInterface.scrollcannons.SpecTechniqueColor = argb(90,255,255,255);	// TIH cannon selection visual adjustment Jul12'06
	GameInterface.scrollcannons.SpecTechniqueName = "iSpec1";	// TIH cannon selection visual adjustment Jul12'06
	if(USE_REAL_CANNONS)
	{
		//GameInterface.scrollcannons.ImagesGroup.t2 = "KNBCANNONS";
		for(i=0; i<CANNON_TYPES_QUANTITY; i++)
		{
			if( CheckAttribute(&cannon[i],"TradeOff") && sti(cannon[i].TradeOff)==true ) continue;

			idx++;
			attributeName = "pic" + idx;
			makearef(pRef,GameInterface.scrollcannons.(attributeName));
			switch(sti(cannon[i].type))
			{
				case CANNON_NAME_LONG:
					pRef.str1 = "Long Gun";
					pRef.img2 = "long"+cannon[i].caliber;
					pRef.img1 = "culverine back";  // all three are the same!
				break;
				case CANNON_NAME_CARRONADE:
					pRef.str1 = "Carronade";
					pRef.img2 = "carronade"+cannon[i].caliber;
					pRef.img1 = "cannon back";
				break;
			}
			pRef.str2 = "caliber"+cannon[i].caliber;
			pRef.cannon = i;
			pRef.tex1 = 0;
			pRef.tex2 = 1;
		}
	}
	// KNB <--
	else
	{
		//GameInterface.scrollcannons.ImagesGroup.t2 = "CANNONS";
		for(i=0; i<CANNON_TYPES_QUANTITY; i++)
		{
		//NK -->
		//if( CheckAttribute(&cannon[i],"TradeOff") && sti(cannon[i].TradeOff)==true ) continue;
	// NK <-- 

			idx++;
			attributeName = "pic" + idx;
	        makearef(pRef,GameInterface.scrollcannons.(attributeName));
			switch(sti(cannon[i].type))
			{
			case CANNON_NAME_CULVERINE:
				pRef.str1 = "Culverine";
				pRef.img2 = "culverine"+cannon[i].caliber;
				pRef.img1 = "culverine back";
				break;
			case CANNON_NAME_CANNON:
				pRef.str1 = "Cannon";
				pRef.img2 = "cannon"+cannon[i].caliber;
				pRef.img1 = "cannon back";
				break;
			case CANNON_NAME_SPECIAL_CANNON:
				pRef.str1 = "Cannon";
				pRef.img2 = "cannon"+cannon[i].caliber;
				pRef.img1 = "special cannon back";
				break;
			}
			pRef.cannon = i;
			pRef.str2 = "caliber"+cannon[i].caliber;
			pRef.tex1 = 0;
			pRef.tex2 = 1;
		}
	}

	GameInterface.scrollcannons.ListSize = idx;
}

// TIH --> cannon selection visual adjustment Jul12'06
void ChangeScroll()
{
    int i;
	int idx = 0;
    string attributeName;
    // do all these here, so they are not done each time in the loop below
	int  cn 				= GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	int  cnCannonType 		= GetCaracterShipCannonsType(GetCharacter(cn));
	int  cnCannonMax 		= GetMaximumCaliber(GetCharacter(cn))
	bool cnCannonRemovable 	= GetRemovable(GetCharacter(cn));
	
	for(i=0; i<CANNON_TYPES_QUANTITY; i++)
	{
		// skip any that are not supposed to be visible
		if( CheckAttribute(&cannon[i],"TradeOff") && sti(cannon[i].TradeOff)==true ) continue;
		
		idx++;
		attributeName = "pic" + idx;
		
		// if currently installed, then show so
		GameInterface.scrollcannons.(attributeName).img3 = "";
		GameInterface.scrollcannons.(attributeName).tex3 = 0;
		if ( cnCannonType == i) {
			GameInterface.scrollcannons.(attributeName).img3 = "installedflag";
			GameInterface.scrollcannons.(attributeName).tex3 = 2;
		}

		// set visible by default
		GameInterface.scrollcannons.(attributeName).spec2 = false;
		// set invisible for any of the following conditions
		if ( !cnCannonRemovable ) {
			GameInterface.scrollcannons.(attributeName).spec2 = true;
		}
		if ( cnCannonMax < GetCannonCaliber(i) ) {
			GameInterface.scrollcannons.(attributeName).spec2 = true;
		}
	}
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"SCROLLCANNONS",-1);
}
// TIH <--

void FillFourImage()
{
	int i;
	string tmp1,tmp2,tmpStr;
	int tmpID;
	int bSelected;
	
	ref refMainCh = GetMainCharacter();
	GameInterface.FourImage.BadTwoPicture = "interfaces\blank_ship.tga";
	GameInterface.FourImage.ImagesGroup.t0 = "ICONS";
	GameInterface.FourImage.ImagesGroup.t1 = "SHIPS16";
	GameInterface.FourImage.ImagesGroup.t2 = "SHIPS1";
	GameInterface.FourImage.ImagesGroup.t3 = "SHIPS2";
	GameInterface.FourImage.ImagesGroup.t4 = "SHIPS3";
	GameInterface.FourImage.ImagesGroup.t5 = "SHIPS4";
	GameInterface.FourImage.ImagesGroup.t6 = "SHIPS5";
	for(i=0; i<COMPANION_MAX; i++)
	{
		bSelected=true;
		tmpID = GetCompanionIndex(refMainCh,i);
		if(tmpID!=-1) {
			tmpID = GetCharacterShipType(&Characters[tmpID]); // PS
			if(tmpID==SHIP_NOTUSED) {
				tmp1="";
				tmp2="";
				bSelected=false;
			} else {
				tmp1 = ShipsTypes[tmpID].Class;
				tmp2 = ShipsTypes[tmpID].SName; // PS
			}
		} else {
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
		GameInterface.FourImage.(tmpStr).tex2		= 1+GetShipTexture(tmpID);
	}
}

void ProcessCancelExit()// MAXIMUS cannons MOD -->
{
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn<0) return;

	int Qty = GetCannonCurQuantity(GetCharacter(cn));
	int curQty = sti(GetCannonQuantity(GetCharacter(cn))-Qty);

	if(curQty==0)
	{
      DelEventHandler("InterfaceBreak","ProcessCancelExit");
      DelEventHandler("frame","ProcessFrame");
      DelEventHandler("exitCancel","ProcessCancelExit");
      DelEventHandler("InstallPress","ProcessInstall");
      DelEventHandler("BuyPress","ProcessBuy"); // KK
//		DelEventHandler("InstallBuyPress","ProcessInstallAndBuy"); // KK // Commented out by LDH 09Feb09
      DelEventHandler("installSelect","ProcessInstallSelect");
      DelEventHandler("ievnt_command","ProcessCommandExecute");
// added by MAXIMUS -->
      DelEventHandler("CancelPress","ProcessCancel");
      DelEventHandler("RepairNo","ProcessRepair_no");
      DelEventHandler("RepairYes","ProcessRepair_yes");
      DelEventHandler("ExitPress","ProcessExit");
      DelEventHandler("ExitNo","ProcessExit_no");
      DelEventHandler("ExitYes","ProcessExit_yes");
// added by MAXIMUS <--

      interfaceResultCommand = RC_INTERFACE_CANNONS_EXIT;
      EndCancelInterface(true);
	}
	else ProcessExit();
	if(tradeHigh==true) tradeHigh = false; // added by MAXIMUS [possibility to repair your ship by double price]
}// MAXIMUS cannons MOD <--

// MAXIMUS cannons MOD -->
void SetRepairData()
{
/*	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn<0) return;

// KK --> you can't buy unless able to afford it
	int ct = GetChoosedCannonType();
	int ot = GetCaracterShipCannonsType(GetCharacter(cn));
	int curQty = cannonqtys[0] + cannonqtys[1] + cannonqtys[2] + cannonqtys[3];
	int Qty = curQty - cannoniqty;
	int sell = GetCannonPrice(ot) * Qty;
	int mguns = (sti(Characters[GetMainCharacterIndex()].Money) + sell) / GetCannonPrice(ct);
	if (mguns == 0) {
		SetSelectable("INSTALL_BUTTON", false);
		EnableString("HelpString");
		SetNodeUsing("BOX1", true);
		GameInterface.strings.HelpString = LanguageConvertString(tmpLangFileID,"Nomoney");
	}
	if (curQty < mguns) {
		EnableString("HelpString");
		SetNodeUsing("BOX1", true);
		GameInterface.strings.HelpString = LanguageConvertString(tmpLangFileID,"CanBuyMax") + " " + mguns + " " + LanguageConvertString(tmpLangFileID,"guns!");
	}
// <-- KK

	//int Qty = GetCannonCurQuantity(GetCharacter(cn));
	//int curQty = sti(GetCannonQuantity(GetCharacter(cn))-Qty);
// changed by MAXIMUS [possibility to repair your ship by double price] -->
	int cost;
	if(tradeHigh==true) cost = sti(GetCannonPrice(GetChoosedCannonType()))*2;
	else cost = sti(GetCannonPrice(GetChoosedCannonType()));
// changed by MAXIMUS [possibility to repair your ship by double price] <--

	GameInterface.strings.Cannons = curQty;
	GameInterface.strings.BuyQuantity = Qty;
trace("cannons: cannoniqty="+cannoniqty+", Qty="+Qty+", GetCannonQuantity(GetCharacter(cn))="+GetCannonQuantity(GetCharacter(cn)));
	GameInterface.strings.ShipName = GetCharShipName(GetCharacter(cn)) + " - " + GetCannonQuantity(GetCharacter(cn)) + XI_ConvertString("un")+".";
    GameInterface.strings.CostUnit = MakeMoneyShow(cost,MONEY_SIGN,MONEY_DELIVER);
// changed by MAXIMUS [possibility to repair your ship by double price] -->
	if(tradeHigh==true) GameInterface.strings.RepairAllCost = MakeMoneyShow(GetCannonDeltaPrice(GetCharacter(cn),GetChoosedCannonType(), curQty)*2,MONEY_SIGN,MONEY_DELIVER);
	else GameInterface.strings.RepairAllCost = MakeMoneyShow(GetCannonDeltaPrice(GetCharacter(cn),GetChoosedCannonType(), curQty),MONEY_SIGN,MONEY_DELIVER);
// changed by MAXIMUS [possibility to repair your ship by double price] <--

	if(Qty>0)
	{
		SetSelectable("SCROLLCANNONS",false);
		SetSelectable("LEFTSCROLLBUTTON",false);
		SetSelectable("RIGHTSCROLLBUTTON",false);
	}
	else
	{
		SetSelectable("SCROLLCANNONS",true);
		SetSelectable("LEFTSCROLLBUTTON",true);
		SetSelectable("RIGHTSCROLLBUTTON",true);
	}
	SetSelectable("REPAIR_OK", Qty>0);*/
}

/*void ProcessRepair()
{
	int ct = CANNON_TYPE_NONECANNON;
	tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn==-1) return;
	ct = GetChoosedCannonType(); // KK

	ref curChr = GetCharacter(cn);
	int Qty = cannonqtys[0] + cannonqtys[1] + cannonqtys[2] + cannonqtys[3]; // KK GetCannonCurQuantity(curChr);
	int curQty = sti(Qty - cannoniqty); // KK
	int ourCaliber = sti(GetCannonCaliber(GetCaracterShipCannonsType(curChr)));
	int curCaliber = sti(GetCannonCaliber(ct));

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

	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	if(ourCaliber==curCaliber) SetFormatedText("TEXTWINDOW",LanguageConvertString(tmpLangFileID,"Buy cannons confirm1")+" "+GetCannonName(ct) + " - " + curQty + " " + XI_ConvertString("un") + ".? ");
	if(ourCaliber>curCaliber) SetFormatedText("TEXTWINDOW",LanguageConvertString(tmpLangFileID,"Buy cannons confirm1")+" "+GetCannonName(ct) + " - " + curQty + " " + XI_ConvertString("un") + ".? "+LanguageConvertString(tmpLangFileID,"Buy cannons confirm2")+ " " +curCaliber+ " " +LanguageConvertString(tmpLangFileID,"Buy cannons confirm3"));
	if(ourCaliber<curCaliber) SetFormatedText("TEXTWINDOW",LanguageConvertString(tmpLangFileID,"Buy cannons confirm1")+" "+GetCannonName(ct) + " - " + curQty + " " + XI_ConvertString("un") + ".? "+LanguageConvertString(tmpLangFileID,"Buy cannons confirm4")+ " " +curCaliber+ " " +LanguageConvertString(tmpLangFileID,"Buy cannons confirm3"));
	LanguageCloseFile(tmpLangFileID);
}*/

void ProcessRepair_no()
{
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);

	SetNodeUsing("CONFIRM_RECTANGLE",false);
	SetNodeUsing("TEXTWINDOW",false);
	SetNodeUsing("CONFIRM_YES_BUTTON",false);
	SetNodeUsing("CONFIRM_NO_BUTTON",false);
	SetNodeUsing("CAN_PIC",false);
	SetNodeUsing("CAN_PIC1",false);
	SetNodeUsing("CAN_PIC2",false);

	SetCurrentNode("CANNONSQUANTITY");
}

void ProcessRepair_yes()
{
	EnableString("Installed");
	EnableString("Installed_1");
	int ct = CANNON_TYPE_NONECANNON;
	tmpLangFileID = LanguageOpenFile("interface_strings.txt");

	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn==-1) return;
	ct = GetChoosedCannonType(); // KK

	ref curChr = GetCharacter(cn);
	int Qty = cannonqtys[0] + cannonqtys[1] + cannonqtys[2] + cannonqtys[3]; // KK GetCannonCurQuantity(curChr);
	int curQty = sti(GetCannonQuantity(curChr)-Qty);
	int newQty = sti(GetMaxCannonQuantity(curChr)-GetCannonQuantity(curChr));
// changed by MAXIMUS [possibility to repair your ship by double price] -->
	int cost;
	if(tradeHigh==true) cost = sti(GetCannonPrice(GetChoosedCannonType())*curQty)*2;
	else cost = sti(GetCannonPrice(GetChoosedCannonType())*curQty);
// changed by MAXIMUS [possibility to repair your ship by double price] <--

	AddMoneyToCharacter( GetMainCharacter(), 0 - cost );
    SetCharacterCannonType(curChr, GetChoosedCannonType());
	//MAXIMUS -->
	if(AUTO_SKILL_SYSTEM)
	{
		AddPartyExpChar(GetMainCharacter(), "Repair", makeint(cost/sti(GetCannonCaliber(GetChoosedCannonType())*2)));
	}
	//MAXIMUS <--

  // KK int ourQty = 0;
  // KK ourQty = sti(curChr.ship.Cannons.Borts.cannonf.qty);
  curChr.ship.Cannons.Borts.cannonf.curqty = cannonqtys[0]; // ourQty;

  // KK ourQty = sti(curChr.ship.Cannons.Borts.cannonb.qty);
  curChr.ship.Cannons.Borts.cannonb.curqty = cannonqtys[1]; // ourQty;

  // KK ourQty = sti(curChr.ship.Cannons.Borts.cannonl.qty);
  curChr.ship.Cannons.Borts.cannonl.curqty = cannonqtys[2]; // ourQty;

  // KK ourQty = sti(curChr.ship.Cannons.Borts.cannonr.qty);
  curChr.ship.Cannons.Borts.cannonr.curqty = cannonqtys[3]; // ourQty;

	GameInterface.strings.Money = MakeMoneyShow(sti(Characters[GetMainCharacterIndex()].Money),"",".");
	nCurScrollNum = -1;

	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);

	SetNodeUsing("CONFIRM_RECTANGLE",false);
	SetNodeUsing("TEXTWINDOW",false);
	SetNodeUsing("CONFIRM_YES_BUTTON",false);
	SetNodeUsing("CONFIRM_NO_BUTTON",false);
	SetNodeUsing("CAN_PIC",false);
	SetNodeUsing("CAN_PIC1",false);
	SetNodeUsing("CAN_PIC2",false);

	SetCurrentNode("SCROLLCANNONS");

	SetNodeUsing("BOX",true);
	SetNodeUsing("BOX1",true);

	GameInterface.strings.Installed = GetCannonName(ct) + " - " + curQty + XI_ConvertString("un") + ". " + " " + LanguageConvertString(tmpLangFileID,"have been installed");
	GameInterface.strings.Installed_1 = LanguageConvertString(tmpLangFileID,"on to the ship") + " " + GetMyShipName(GetCharacter(cn)) + "!";
	SetSelectable("INSTALL_BUTTON",false);
	SetSelectable("INSTALLBUY_BUTTON", false);
}

/*void AddCannonsToCharacter()
{
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn<0) {SetSelectable("REPAIR_OK",false);}
	else
	{
// KK --> you can't buy unless able to afford it
		int curQty = cannonqtys[0] + cannonqtys[1] + cannonqtys[2] + cannonqtys[3];
		int sell = GetCannonPrice(GetCaracterShipCannonsType(GetCharacter(cn))) * curQty;
		int mguns = (sti(Characters[GetMainCharacterIndex()].Money) + sell) / GetCannonPrice(GetChoosedCannonType());
		if (GetCaracterShipCannonsType(GetCharacter(cn)) == GetChoosedCannonType()) mguns -= curQty;
		mguns -= sti(GameInterface.strings.BuyQuantity);
		if (mguns <= 0) return;
// <-- KK
	  aref arCurShip; makearef(arCurShip, Characters[cn].ship);
	  SetSelectable("REPAIR_OK", curQty <= GetMaxCannonQuantity(GetCharacter(cn)) && GetCannonQuantity(GetCharacter(cn)) >= curQty); // KK
	  if(sti(GetCannonQuantity(GetCharacter(cn)) < GetMaxCannonQuantity(GetCharacter(cn))))
	  {
// KK -->
	  	bool leave = false;
	    if (GetCannonArcQty(GetCharacter(cn),0) != GetCannonArcMaxQty(GetCharacter(cn),0)) { cannonqtys[0]++; leave = true; }
				//SetCannonArcQty(GetCharacter(cn), 0, GetCannonArcQty(GetCharacter(cn), 0)+1);
		  if (leave == false && GetCannonArcQty(GetCharacter(cn),1) != GetCannonArcMaxQty(GetCharacter(cn),1)) { cannonqtys[1]++; leave = true; }
				//SetCannonArcQty(GetCharacter(cn), 1, GetCannonArcQty(GetCharacter(cn), 1)+1);
			if (leave == false && GetCannonArcQty(GetCharacter(cn),2) != GetCannonArcMaxQty(GetCharacter(cn),2)) { cannonqtys[2]++; leave = true; }
				//SetCannonArcQty(GetCharacter(cn), 2, GetCannonArcQty(GetCharacter(cn), 2)+1);
			if (leave == false && GetCannonArcQty(GetCharacter(cn),3) != GetCannonArcMaxQty(GetCharacter(cn),3)) cannonqtys[3]++;
				//SetCannonArcQty(GetCharacter(cn), 3, GetCannonArcQty(GetCharacter(cn), 3)+1);
			//curQty++;
	    //GameInterface.strings.ShipName = GetCharShipName(GetCharacter(cn)) + " - " + curQty + XI_ConvertString("un")+".";
	    //GameInterface.strings.BuyQuantity = sti(GameInterface.strings.BuyQuantity) + 1;
// <-- KK
	  } else {
	    // KK GameInterface.strings.ShipName = GetCharShipName(GetCharacter(cn)) + " - " + sti(GetCannonQuantity(GetCharacter(cn))) + XI_ConvertString("un")+".";
	    // KK GameInterface.strings.BuyQuantity = sti(GetMaxCannonQuantity(GetCharacter(cn)));
	  }
	  SetRepairData();
	}
}

void RemoveCannonsFromCharacter()
{
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn<0) {SetSelectable("REPAIR_OK",false);}
	else
	{
	  aref arCurShip; makearef(arCurShip, Characters[cn].ship);
	  SetSelectable("REPAIR_OK",GetCannonCurQuantity(GetCharacter(cn))<=GetMaxCannonQuantity(GetCharacter(cn)) && GetCannonQuantity(GetCharacter(cn))>=GetCannonCurQuantity(GetCharacter(cn)));
	  if(sti(GetCannonQuantity(GetCharacter(cn))-GetCannonCurQuantity(GetCharacter(cn)))>0)
	  {
// KK -->
	  	bool leave = false;
	    if (GetCannonArcQty(GetCharacter(cn), 0) > 0) { cannonqtys[0]--; leave = true; }
				//SetCannonArcQty(GetCharacter(cn), 0, GetCannonArcQty(GetCharacter(cn), 0)-1);
		  if (leave == false && GetCannonArcQty(GetCharacter(cn),1) > 0) { cannonqtys[1]--; leave = true; }
				//SetCannonArcQty(GetCharacter(cn), 1, GetCannonArcQty(GetCharacter(cn), 1)-1);
			if (leave == false && GetCannonArcQty(GetCharacter(cn),2) > 0) { cannonqtys[2]--; leave = true; }
				//SetCannonArcQty(GetCharacter(cn), 2, GetCannonArcQty(GetCharacter(cn), 2)-1);
			if (leave == false && GetCannonArcQty(GetCharacter(cn),3) > 0) cannonqtys[3]--;
				//SetCannonArcQty(GetCharacter(cn), 3, GetCannonArcQty(GetCharacter(cn), 3)-1);
	    //GameInterface.strings.ShipName = GetCharShipName(GetCharacter(cn)) + " - " + sti(GetCannonQuantity(GetCharacter(cn))-1) + XI_ConvertString("un")+".";
	    //GameInterface.strings.BuyQuantity = sti(GetCannonQuantity(GetCharacter(cn))-GetCannonCurQuantity(GetCharacter(cn)));
// <-- KK
	  }
	  else
	  {
	    // KK GameInterface.strings.ShipName = GetCharShipName(GetCharacter(cn)) + " - " + sti(GetCannonQuantity(GetCharacter(cn))) + XI_ConvertString("un")+".";
	    // KK GameInterface.strings.BuyQuantity = "0";
	  }
	  SetRepairData();
	}
}*/

void AddCannon(string arcname)
{
	int cn = GetCompanionIndex(GetMainCharacter(), nCurFourNum);
	if (cn < 0) return;

	int arc = 0;
	switch (arcname)
	{
		case "front_cannons_qty":
			arc = 0;
		break;
		case "rightarc_cannons_qty":
			arc = 1;
		break;
		case "back_cannons_qty":
			arc = 2;
		break;
		case "leftarc_cannons_qty":
			arc = 3;
		break;
	}

	int n = sti(GameInterface.strings.(arcname)) + 1;
	int total = sti(GameInterface.strings.front_cannons_qty) + sti(GameInterface.strings.rightarc_cannons_qty) + sti(GameInterface.strings.back_cannons_qty) + sti(GameInterface.strings.leftarc_cannons_qty) + 1;
	topay = (total - GetCannonCurQuantity(GetCharacter(cn))) * CalcCannonExchangeCost();
	//if (tradeHigh) topay *= 2;
	if (n <= GetCannonArcMaxQty(GetCharacter(cn), arc) && topay <= GetCharacterMoney(GetMainCharacter())) {
		GameInterface.strings.(arcname) = n;
		GameInterface.strings.ShipName = GetMyShipName(GetCharacter(cn)) + " - " + total + XI_ConvertString("un")+".";		
		GameInterface.strings.cannons_cost = MakeMoneyShow(topay, MONEY_SIGN, MONEY_DELIVER);
	}
}

void RemoveCannon(string arcname)
{
	int cn = GetCompanionIndex(GetMainCharacter(), nCurFourNum);
	if (cn < 0) return;

	int arc = 0;
	switch (arcname)
	{
		case "front_cannons_qty":
			arc = 0;
		break;
		case "rightarc_cannons_qty":
			arc = 1;
		break;
		case "back_cannons_qty":
			arc = 2;
		break;
		case "leftarc_cannons_qty":
			arc = 3;
		break;
	}

	int n = sti(GameInterface.strings.(arcname)) - 1;
	int total = sti(GameInterface.strings.front_cannons_qty) + sti(GameInterface.strings.rightarc_cannons_qty) + sti(GameInterface.strings.back_cannons_qty) + sti(GameInterface.strings.leftarc_cannons_qty) - 1;
	topay = (total - GetCannonCurQuantity(GetCharacter(cn))) * CalcCannonExchangeCost();
	//if (tradeHigh) topay *= 2;
	if (n >= 0) {
		GameInterface.strings.(arcname) = n;
		GameInterface.strings.ShipName = GetMyShipName(GetCharacter(cn)) + " - " + total + XI_ConvertString("un")+".";		
		GameInterface.strings.cannons_cost = MakeMoneyShow(topay, MONEY_SIGN, MONEY_DELIVER);
	}
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();
	
	switch(nodName)
	{
		case "INSTALL_BUTTON":
			if (comName=="activate" || comName=="click") {
				ProcessInstall();
			}
		break;
// KK -->
		case "INSTALLBUY_BUTTON":
			if (comName=="activate" || comName=="click") {
				ProcessInstallAndBuy();
			}
		break;
// <-- KK
		case "CANCEL_BUTTON":
			if (comName=="activate" || comName=="click") {
				ProcessCancel();
			}
		break;

		case "BUY_BUTTON":
			if (comName=="activate" || comName=="click") {
				ProcessBuy();
			}
		break;

		case "FRONTCANNONSQTY":
			switch(comName)
			{
				case "downstep":
					if (GetSelectable("FRONTCANNONSQTY")) {
						SetCurrentNode("FRONTCANNONSQTY");
					} else {
						Event("ievnt_command","ss",comName,"FRONTCANNONSQTY");
					}
				break;
				case "upstep":
					if (GetSelectable("FRONTCANNONSQTY")) {
						SetCurrentNode("FRONTCANNONSQTY");
					} else {
						Event("ievnt_command","ss",comName,"FRONTCANNONSQTY");
					}
				break;
				case "rightstep":
					AddCannon("front_cannons_qty");
				break;
				case "leftstep":
					RemoveCannon("front_cannons_qty");
				break;
			}
		break;

		case "LEFTARCCANNONSQTY":
			switch(comName)
			{
				case "downstep":
					if (GetSelectable("LEFTARCCANNONSQTY")) {
						SetCurrentNode("LEFTARCCANNONSQTY");
					} else {
						Event("ievnt_command","ss",comName,"LEFTARCCANNONSQTY");
					}
				break;
				case "upstep":
					if (GetSelectable("LEFTARCCANNONSQTY")) {
						SetCurrentNode("LEFTARCCANNONSQTY");
					} else {
						Event("ievnt_command","ss",comName,"LEFTARCCANNONSQTY");
					}
				break;
				case "rightstep":
					AddCannon("leftarc_cannons_qty");
				break;
				case "leftstep":
					RemoveCannon("leftarc_cannons_qty");
				break;
			}
		break;

		case "RIGHTARCCANNONSQTY":
			switch(comName)
			{
				case "downstep":
					if (GetSelectable("RIGHTARCCANNONSQTY")) {
						SetCurrentNode("RIGHTARCCANNONSQTY");
					} else {
						Event("ievnt_command","ss",comName,"RIGHTARCCANNONSQTY");
					}
				break;
				case "upstep":
					if (GetSelectable("RIGHTARCCANNONSQTY")) {
						SetCurrentNode("RIGHTARCCANNONSQTY");
					} else {
						Event("ievnt_command","ss",comName,"RIGHTARCCANNONSQTY");
					}
				break;
				case "rightstep":
					AddCannon("rightarc_cannons_qty");
				break;
				case "leftstep":
					RemoveCannon("rightarc_cannons_qty");
				break;
			}
		break;

		case "BACKCANNONSQTY":
			switch(comName)
			{
				case "downstep":
					if (GetSelectable("BACKCANNONSQTY")) {
						SetCurrentNode("BACKCANNONSQTY");
					} else {
						Event("ievnt_command","ss",comName,"BACKCANNONSQTY");
					}
				break;
				case "upstep":
					if (GetSelectable("BACKCANNONSQTY")) {
						SetCurrentNode("BACKCANNONSQTY");
					} else {
						Event("ievnt_command","ss",comName,"BACKCANNONSQTY");
					}
				break;
				case "rightstep":
					AddCannon("back_cannons_qty");
				break;
				case "leftstep":
					RemoveCannon("back_cannons_qty");
				break;
			}
		break;
	}
}
// MAXIMUS cannons MOD <--

// KK -->
void ProcessInstall()
{
	int cn = GetCompanionIndex(GetMainCharacter(), nCurFourNum);
	if (cn < 0) {
		SetSelectable("INSTALL_BUTTON", false);
		return;
	} else {
		SetSelectable("INSTALL_BUTTON", true);
	}

	cannonqtys[0] = GetCannonArcQty(GetCharacter(cn), 0);
	cannonqtys[1] = GetCannonArcQty(GetCharacter(cn), 1);
	cannonqtys[2] = GetCannonArcQty(GetCharacter(cn), 2);
	cannonqtys[3] = GetCannonArcQty(GetCharacter(cn), 3);
	cannoniqty = GetCannonCurQuantity(GetCharacter(cn));

	DisableString("FireRange");
	DisableString("ReloadTime");
	DisableString("Gunpowder");
	DisableString("Cost");
	DisableString("CostUnit");
	//DisableString("RepairCannonsCost");
	SetNodeUsing("STRINGES", false);
	SetNodeUsing("CANNONPOWDER_STRINGS", false);
	SetNodeUsing("REPAIRIMAGES", false);
	SetNodeUsing("INSTALLBUY_BUTTON", false);
	SetNodeUsing("INSTALL_BUTTON", false);
	SetNodeUsing("CANNONLOCATIONS_STRINGS", true);
	SetNodeUsing("FRONTCANNONSQTY", true);
	EnableString("front_cannons_qty");
	SetNodeUsing("LEFTARCCANNONSQTY", true);
	EnableString("leftarc_cannons_qty");
	SetNodeUsing("RIGHTARCCANNONSQTY", true);
	EnableString("rightarc_cannons_qty");
	SetNodeUsing("BACKCANNONSQTY", true);
	EnableString("back_cannons_qty");
	EnableString("cannons_cost");
	SetNodeUsing("CANCEL_BUTTON", true);
	SetNodeUsing("BUY_BUTTON", true);
	SetSelectable("SHIPSLIST", false);
	SetSelectable("SCROLLCANNONS", false);
	SetSelectable("LEFTSCROLLBUTTON", false);
	SetSelectable("RIGHTSCROLLBUTTON", false);

	GameInterface.strings.front_cannons_qty = GetCannonArcQty(GetCharacter(cn), 0);
	GameInterface.strings.rightarc_cannons_qty = GetCannonArcQty(GetCharacter(cn), 1);
	GameInterface.strings.back_cannons_qty = GetCannonArcQty(GetCharacter(cn), 2);
	GameInterface.strings.leftarc_cannons_qty = GetCannonArcQty(GetCharacter(cn), 3);
	GameInterface.strings.ShipName = GetMyShipName(GetCharacter(cn)) + " - " + cannoniqty + XI_ConvertString("un")+".";		
	GameInterface.strings.cannons_cost = MakeMoneyShow(0, MONEY_SIGN, MONEY_DELIVER);
}

void ProcessInstallAndBuy()
{
	ref PChar = GetMainCharacter();
	int cn = GetCompanionIndex(PChar, nCurFourNum);
	if (cn < 0) {
		SetSelectable("INSTALLBUY_BUTTON", false);
		return;
	} else {
		SetSelectable("INSTALLBUY_BUTTON", true);
	}

	cannonqtys[0] = GetCannonArcQty(GetCharacter(cn), 0);
	cannonqtys[1] = GetCannonArcQty(GetCharacter(cn), 1);
	cannonqtys[2] = GetCannonArcQty(GetCharacter(cn), 2);
	cannonqtys[3] = GetCannonArcQty(GetCharacter(cn), 3);
	cannoniqty = cannonqtys[0] + cannonqtys[1] + cannonqtys[2] + cannonqtys[3];

	int gratio[4];
	int canbuymax = GetCanBuyQuantity();
trace("Install&Buy: canbuymax="+canbuymax);
	while (canbuymax > 0) {
		int mnguns = GetCannonArcMaxQty(GetCharacter(cn), 0);
		if (mnguns > 0)
			gratio[0] = makeint(makefloat(cannonqtys[0])/makefloat(mnguns) * 100);
		else
			gratio[0] = 100;

		mnguns = GetCannonArcMaxQty(GetCharacter(cn), 1);
		if (mnguns > 0)
			gratio[1] = makeint(makefloat(cannonqtys[1])/makefloat(mnguns) * 100);
		else
			gratio[1] = 100;

		mnguns = GetCannonArcMaxQty(GetCharacter(cn), 2);
		if (mnguns > 0)
			gratio[2] = makeint(makefloat(cannonqtys[2])/makefloat(mnguns) * 100);
		else
			gratio[2] = 100;

		mnguns = GetCannonArcMaxQty(GetCharacter(cn), 3);
		if (mnguns > 0)
			gratio[3] = makeint(makefloat(cannonqtys[3])/makefloat(mnguns) * 100);
		else
			gratio[3] = 100;

		int mbort = 0;
		mnguns = gratio[mbort];
		for (int i = 1; i < 4; i++) {
			if (gratio[i] < mnguns) {
				mbort = i;
				mnguns = gratio[mbort];
			}
		}
trace("Install&Buy: mbort="+mbort+", canbuymax="+(canbuymax - 1));
		cannonqtys[mbort] = cannonqtys[mbort] + 1;
		cannoniqty++;
		canbuymax--;
	}
trace("Install&Buy: po petli: 0="+cannonqtys[0]+", 1="+cannonqtys[1]+", 2="+cannonqtys[2]+", 3="+cannonqtys[3]);

	topay = 0;
	if (GetCaracterShipCannonsType(GetCharacter(cn)) != GetChoosedCannonType()) topay = SellCannons(GetCharacter(cn), GetCannonQuantity(GetCharacter(cn)));
	topay += BuyCannons(GetCharacter(cn), GetChoosedCannonType(), cannoniqty);
	if (tradeHigh) topay *= 2;

// It's buying the cannons twice! Remove event handler for this function - LDH 09Feb09
//Trace("(GetCaracterShipCannonsType(GetCharacter(cn)) != GetChoosedCannonType()) = " + (GetCaracterShipCannonsType(GetCharacter(cn)) != GetChoosedCannonType()));
//Trace("SellCannons(GetCharacter(cn), GetCannonQuantity(GetCharacter(cn))) = " + SellCannons(GetCharacter(cn), GetCannonQuantity(GetCharacter(cn))));
//Trace("BuyCannons(GetCharacter(cn), GetChoosedCannonType(), cannoniqty)   = " + BuyCannons(GetCharacter(cn), GetChoosedCannonType(), cannoniqty));
//Trace("cannoniqty = " + cannoniqty);

trace("topay="+topay)

	SetCannonArcQty(GetCharacter(cn), 0, cannonqtys[0]);
	SetCannonArcQty(GetCharacter(cn), 1, cannonqtys[1]);
	SetCannonArcQty(GetCharacter(cn), 2, cannonqtys[2]);
	SetCannonArcQty(GetCharacter(cn), 3, cannonqtys[3]);
	if (cannoniqty == 0)
		SetCharacterCannonType(GetCharacter(cn), CANNON_TYPE_NONECANNON);
	else
		SetCharacterCannonType(GetCharacter(cn), GetChoosedCannonType());

	AddMoneyToCharacter(PChar, 0 - topay);
	GameInterface.strings.money = MakeMoneyShow(makeint(GetCharacterMoney(PChar)), MONEY_SIGN, MONEY_DELIVER);

	int isSelectable = CheckInstallEnable();
	SetSelectable("INSTALLBUY_BUTTON", isSelectable > 0);
	SetSelectable("INSTALL_BUTTON", isSelectable == 2);
	ChangeScroll();
}

void ProcessCancel()
{
	SetNodeUsing("CANNONLOCATIONS_STRINGS", false);
	SetNodeUsing("FRONTCANNONSQTY", false);
	DisableString("front_cannons_qty");
	SetNodeUsing("LEFTARCCANNONSQTY", false);
	DisableString("leftarc_cannons_qty");
	SetNodeUsing("RIGHTARCCANNONSQTY", false);
	DisableString("rightarc_cannons_qty");
	SetNodeUsing("BACKCANNONSQTY", false);
	DisableString("back_cannons_qty");
	DisableString("cannons_cost");
	SetNodeUsing("CANCEL_BUTTON", false);
	SetNodeUsing("BUY_BUTTON", false);

	SetNodeUsing("STRINGES", true);
	EnableString("FireRange");
	EnableString("ReloadTime");
	EnableString("Gunpowder");
	EnableString("Cost");
	EnableString("CostUnit");
	//EnableString("RepairCannonsCost");
	if (CANNONPOWDER_MOD) SetNodeUsing("CANNONPOWDER_STRINGS", true);
	SetNodeUsing("REPAIRIMAGES", true);
	SetNodeUsing("INSTALLBUY_BUTTON", true);
	SetNodeUsing("INSTALL_BUTTON", true);
	SetCurrentNode("INSTALLBUY_BUTTON");

	SetSelectable("SHIPSLIST", true);
	SetSelectable("SCROLLCANNONS", true);
	SetSelectable("LEFTSCROLLBUTTON", true);
	SetSelectable("RIGHTSCROLLBUTTON", true);

	int cn = GetCompanionIndex(GetMainCharacter(), nCurFourNum);
	if (cn < 0) return;

	GameInterface.strings.ShipName = GetMyShipName(GetCharacter(cn)) + " - " + cannoniqty + XI_ConvertString("un")+".";		
}

void ProcessBuy()
{
	SetNodeUsing("CANNONLOCATIONS_STRINGS", false);
	SetNodeUsing("FRONTCANNONSQTY", false);
	DisableString("front_cannons_qty");
	SetNodeUsing("LEFTARCCANNONSQTY", false);
	DisableString("leftarc_cannons_qty");
	SetNodeUsing("RIGHTARCCANNONSQTY", false);
	DisableString("rightarc_cannons_qty");
	SetNodeUsing("BACKCANNONSQTY", false);
	DisableString("back_cannons_qty");
	DisableString("cannons_cost");
	SetNodeUsing("CANCEL_BUTTON", false);
	SetNodeUsing("BUY_BUTTON", false);

	SetNodeUsing("STRINGES", true);
	EnableString("FireRange");
	EnableString("ReloadTime");
	EnableString("Gunpowder");
	EnableString("Cost");
	EnableString("CostUnit");
	//EnableString("RepairCannonsCost");
	if (CANNONPOWDER_MOD) SetNodeUsing("CANNONPOWDER_STRINGS", true);
	SetNodeUsing("REPAIRIMAGES", true);
	SetNodeUsing("INSTALLBUY_BUTTON", true);
	SetNodeUsing("INSTALL_BUTTON", true);
	SetCurrentNode("SCROLLCANNONS");

	SetSelectable("SHIPSLIST", true);
	SetSelectable("SCROLLCANNONS", true);
	SetSelectable("LEFTSCROLLBUTTON", true);
	SetSelectable("RIGHTSCROLLBUTTON", true);

	ref PChar = GetMainCharacter();
	int cn = GetCompanionIndex(PChar, nCurFourNum);
	if (cn < 0) return;

	SetCharacterCannonType(GetCharacter(cn), GetChoosedCannonType());
	cannonqtys[0] = sti(GameInterface.strings.front_cannons_qty);
	cannonqtys[1] = sti(GameInterface.strings.rightarc_cannons_qty);
	cannonqtys[2] = sti(GameInterface.strings.back_cannons_qty);
	cannonqtys[3] = sti(GameInterface.strings.leftarc_cannons_qty);
	//cannoniqty = GetCannonQuantity(GetCharacter(cn));

	SetCannonArcQty(GetCharacter(cn), 0, cannonqtys[0]);
	SetCannonArcQty(GetCharacter(cn), 1, cannonqtys[1]);
	SetCannonArcQty(GetCharacter(cn), 2, cannonqtys[2]);
	SetCannonArcQty(GetCharacter(cn), 3, cannonqtys[3]);
	cannoniqty=cannonqtys[0] + cannonqtys[1] + cannonqtys[2] + cannonqtys[3];
	if (cannoniqty == 0) SetCharacterCannonType(GetCharacter(cn), CANNON_TYPE_NONECANNON);

	AddMoneyToCharacter(PChar, 0 - topay);
	GameInterface.strings.money = MakeMoneyShow(makeint(GetCharacterMoney(PChar)), MONEY_SIGN, MONEY_DELIVER);

// LDH if you see this getting called more than it should, remove the event handler for this function - 09Feb09
// I saw it once but couldn't duplicate it, so I'm leaving the event handler alone
Trace("ProcessBuy() - topay: " + topay);

	int isSelectable = CheckInstallEnable();
	SetSelectable("INSTALLBUY_BUTTON", isSelectable == 2);
	SetSelectable("INSTALL_BUTTON", isSelectable > 0);
	ChangeScroll();
}


/*void ProcessInstall()
{
// MAXIMUS interface MOD -->
	EnableString("Installed");
	EnableString("Installed_1");
	int ct = CANNON_TYPE_NONECANNON;
	tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	if(cn!=-1)	ct = GetChoosedCannonType();
// MAXIMUS interface MOD <--

	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn==-1) return;
	tempship = GetCharShipName(GetCharacter(cn));
	if( !CheckInstallEnable() ) return;
	AddMoneyToCharacter( GetMainCharacter(), 0 - GetCannonDeltaPrice(GetCharacter(cn),GetChoosedCannonType()) );
	//MAXIMUS -->
	if(AUTO_SKILL_SYSTEM)
	{
		AddPartyExpChar(GetMainCharacter(), "Repair", makeint(GetCannonDeltaPrice(GetCharacter(cn),GetChoosedCannonType())/sti(GetCannonCaliber(GetChoosedCannonType())*2)));
	}
	//MAXIMUS <--
	SetCharacterCannonType( GetCharacter(cn), GetChoosedCannonType() );
// MAXIMUS cannons MOD -->
	int newQty = 0;
	ref Chr = GetCharacter(cn);

	newQty = sti(GetCannonArcMaxQty(Chr, 0));
	Chr.ship.Cannons.Borts.cannonf.curqty = newQty;

	newQty = sti(GetCannonArcMaxQty(Chr, 2));
	Chr.ship.Cannons.Borts.cannonb.curqty = newQty;
	
	newQty = sti(GetCannonArcMaxQty(Chr, 3));
	Chr.ship.Cannons.Borts.cannonl.curqty = newQty;
	
	newQty = sti(GetCannonArcMaxQty(Chr, 1));
	Chr.ship.Cannons.Borts.cannonr.curqty = newQty;
// MAXIMUS cannons MOD <--

	ResetCannons(GetCharacter(cn)); // NK can qty 05-04-19
	GameInterface.strings.Money = MakeMoneyShow(sti(Characters[GetMainCharacterIndex()].Money),"",".");
	nCurScrollNum = -1;

// MAXIMUS interface MOD -->
	SetNodeUsing("BOX",true);
	SetNodeUsing("BOX1",true);
	
	ref tmpChar = GetCharacter(cn);
	ref shipRef = GetShipByType(GetCharacterShipType(&tmpChar)); // PS
	aref arship; makearef(arship, tmpChar.ship); // PRS3

	string tmpcannon = (shipRef.CannonsQuantity - GetLocalShipAttrib(arship, &shipRef, "CurCanQty"));

	GameInterface.strings.Installed = GetCannonName(ct) + " - " + tmpcannon + XI_ConvertString("un") + ". " + " " + LanguageConvertString(tmpLangFileID,"have been installed");
	GameInterface.strings.Installed_1 = LanguageConvertString(tmpLangFileID,"on to the ship") + " " + tempship + "!";
	SetSelectable("INSTALL_BUTTON",false);

//	ShowHelpString("chelp_cannons#13");
// MAXIMUS interface MOD <--
}*/
// <-- KK

void SetCharacterCannonType(ref rCharacter,int nCannonType)
{
	rCharacter.Ship.Cannons.Type = nCannonType;
}

// KK -->
int CheckInstallEnable()
{
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if (cn == -1) return 0;
	tmpLangFileID = LanguageOpenFile("interface_strings.txt");

	// changed by MAXIMUS [possibility to repair your ship by double price] -->
	/*if(tradeHigh==true) GameInterface.strings.RepairAllCost = MakeMoneyShow(GetCannonDeltaPrice(GetCharacter(cn),GetChoosedCannonType())*2,MONEY_SIGN,MONEY_DELIVER);
	else GameInterface.strings.RepairAllCost = MakeMoneyShow(GetCannonDeltaPrice(GetCharacter(cn),GetChoosedCannonType()),MONEY_SIGN,MONEY_DELIVER);*/
	// changed by MAXIMUS [possibility to repair your ship by double price] <--
	if (GetRemovable(GetCharacter(cn)) == false) {
		// MAXIMUS interface MOD -->
		EnableString("HelpString");
		SetNodeUsing("BOX1",true);
		GameInterface.strings.HelpString = LanguageConvertString(tmpLangFileID,"Notown");
		//		ShowHelpString("chelp_shipyard#12");
		// MAXIMUS interface MOD <--
		LanguageCloseFile(tmpLangFileID);
		return 0;
	}
	// changed by MAXIMUS [possibility to repair your ship by double price] -->
	//int curDelta = GetCannonDeltaPrice(GetCharacter(cn), GetChoosedCannonType(), cannoniqty, cannoniqty+1);
	int curDelta = 0;

	// LDH 09Feb09 -->
	if (GetCaracterShipCannonsType(GetCharacter(cn)) != GetChoosedCannonType()) 
	{
		curDelta = SellCannons(GetCharacter(cn), GetCannonQuantity(GetCharacter(cn)));
		curDelta += BuyCannons(GetCharacter(cn), GetChoosedCannonType(), GetMaxCannonQuantity(GetCharacter(cn)));
	}
	else
	{
		int gunsMissing = GetMaxCannonQuantity(GetCharacter(cn)) - GetCannonQuantity(GetCharacter(cn));
		if (gunsMissing)
		{
			curDelta = BuyCannons(GetCharacter(cn), GetChoosedCannonType(), gunsMissing);
		}
	}
	if (GetMaximumCaliber(GetCharacter(cn)) < GetCannonCaliber(GetChoosedCannonType())) curDelta = 0; // to get the right HelpString
	// Commenting this out will probably mess up buying special cannons for different arcs
	// I'm declaring that Someone Else's Problem.  Put it in an IF statement if you need it.  At least replacing all guns works again.
//	curDelta += BuyCannons(GetCharacter(cn), GetChoosedCannonType(), 1);	// LDH commented out 09Feb09
	// LDH <--

	if (tradeHigh) curDelta *= 2;
	int canbuymax = GetCanBuyQuantity();
	if (GetCharacterMoney(GetMainCharacter()) < curDelta)
	// changed by MAXIMUS [possibility to repair your ship by double price] <--
	{
		// MAXIMUS interface MOD -->
		if (!EnableString("Installed")) {
			LanguageCloseFile(tmpLangFileID);
			return 1;
		} else {
			EnableString("HelpString");
			SetNodeUsing("BOX1",true);
			GameInterface.strings.HelpString = LanguageConvertString(tmpLangFileID,"Nomoney");
		}
		//		ShowHelpString("chelp_cannons#12");
		// MAXIMUS interface MOD <--
		LanguageCloseFile(tmpLangFileID);
		return 1;
	}
	// MAXIMUS cannons MOD -->
	if(GetChoosedCannonType() == GetCaracterShipCannonsType(GetCharacter(cn)))
	{
		if(GetCannonQuantity(GetCharacter(cn))<GetCannonMaxQuantity(GetCharacter(cn)))
		{/*
			if(!EnableString("Installed"))
			{
				LanguageCloseFile(tmpLangFileID);
				return 1;
			}
			else
			{*/
				EnableString("HelpString");
				SetNodeUsing("BOX1",true);
				GameInterface.strings.HelpString = LanguageConvertString(tmpLangFileID,"Adding");
				return 1;
//			}
		}
		else
		{
			EnableString("HelpString");
			SetNodeUsing("BOX1",true);
			GameInterface.strings.HelpString = LanguageConvertString(tmpLangFileID,"Installed");
			LanguageCloseFile(tmpLangFileID);
			return 0;
		}
	}
	if (GetMaximumCaliber(GetCharacter(cn)) < GetCannonCaliber(GetChoosedCannonType())) {
		// MAXIMUS interface MOD -->
		if (!EnableString("Installed")) {
			LanguageCloseFile(tmpLangFileID);
			return 1;
		} else {
			EnableString("HelpString");
			SetNodeUsing("BOX1",true);
			GameInterface.strings.HelpString = LanguageConvertString(tmpLangFileID,"Bigcaliber");
		}
		//		ShowHelpString("chelp_cannons#10");
		// MAXIMUS interface MOD <--
		LanguageCloseFile(tmpLangFileID);
		return 0;
	}
	if (GetCannonMaxQuantity(GetCharacter(cn)) - GetCannonQuantity(GetCharacter(cn)) > canbuymax) {
		if (!EnableString("Installed")) {
			LanguageCloseFile(tmpLangFileID);
			return 1;
		} else {
			EnableString("HelpString");
			SetNodeUsing("BOX1",true);
			GameInterface.strings.HelpString = LanguageConvertString(tmpLangFileID, "CanBuyMax") + " " + canbuymax + " " + LanguageConvertString(tmpLangFileID, "cannons.");
		}
	}
	//	ShowHelpString("chelp_cannons#2"); // MAXIMUS interface MOD
	LanguageCloseFile(tmpLangFileID);
	return 2;
}
// <-- KK

void ProcessInstallSelect()
{
	if( GetSelectable("INSTALL_BUTTON") ) SetCurrentNode("INSTALL_BUTTON");
}

int GetChoosedCannonType()
{
	string attributeName = "pic" + (nCurScrollNum+1);
	if( !CheckAttribute(&GameInterface,"scrollcannons."+attributeName) ) return 0;
	return sti(GameInterface.scrollcannons.(attributeName).cannon);
}

// NK -- int GetCharacterMoney(ref rChr) moved to char_utilite and fixed.

// KK -->
int CalcCannonExchangeCost()
{
	int cn = GetCompanionIndex(GetMainCharacter(),nCurFourNum);
	if(cn==-1) return 0;

	int excost = 0;
	if (GetCaracterShipCannonsType(GetCharacter(cn)) != GetChoosedCannonType()) excost = SellCannons(GetCharacter(cn), 1);
	excost += BuyCannons(GetCharacter(cn), GetChoosedCannonType(), 1);
	if (tradeHigh) excost *= 2;
	return excost;
}

int GetCanBuyQuantity()
{
	ref PChar = GetMainCharacter();
	int cn = GetCompanionIndex(PChar, nCurFourNum);
	if(cn==-1) return 0;

	int cannon_exchange_cost = CalcCannonExchangeCost();
	if (cannon_exchange_cost < 0) cannon_exchange_cost = 0 - cannon_exchange_cost;
	int maxcannons = GetMaxCannonQuantity(GetCharacter(cn)) - GetCannonQuantity(GetCharacter(cn));
//trace("1: GetMaxCannonQuantity="+GetMaxCannonQuantity(GetCharacter(cn))+", GetCannonQuantity="+GetCannonQuantity(GetCharacter(cn)));
	if (maxcannons == 0) return 0;
	int mcannons = maxcannons;
	if (cannon_exchange_cost != 0) mcannons = GetCharacterMoney(PChar) / cannon_exchange_cost;
	if (mcannons > maxcannons) mcannons = maxcannons;
	if (mcannons < 0) mcannons = 0;
//trace("GetCanBuyQuantity: mcannons="+mcannons+",maxcannons="+maxcannons+",cannon_exchange_cost="+cannon_exchange_cost);
	return mcannons;
}
// <-- KK
