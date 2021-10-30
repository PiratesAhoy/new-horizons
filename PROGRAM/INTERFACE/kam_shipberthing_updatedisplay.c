

//************************************************************************************************************
//
// UPDATE DISPLAY FUNCTIONS
//
//************************************************************************************************************


void FrameProcess()
// called when scrollimage is clicked on; checks whether display needs updating
{
	if(nCurScroll!=sti(GameInterface.islandslist.current))
	{
		nCurScroll = sti(GameInterface.islandslist.current);

		string island = GetIslandName(nCurScroll);
		int tnum = GetIslandTownsQuantity(island); // screwface : display the current port
		int num = 1;
		for (int j = 1; j <= tnum; j++) {
			int townidx = GetTownIndex(GetTownIDFromIsland(island, j));	
			if (townidx>=0 && townidx < TOWNS_QUANTITY && CheckAttribute(&Towns[townidx], "shipberth") && townidx==CurrentPortNumber) {
				num = j;
				break;
			}
		} // Screwface
		nCurTown = GetTownIndex(GetTownIDFromIsland(island, num));

		UpdateBaseDisplay();
	}
}

void UpdateBaseDisplay()
{
	// KK int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	ref PChar = GetMainCharacter();
	string tempattrib = "port" + nCurTown; // Sulan
	int tempnumc1;
	int tempnumc2;
	string tempstringc1;

// KK -->
	tempnumc2 = 0; // screwface
	int tnum = GetIslandTownsQuantity(GetIslandName(nCurScroll)); // screwface
	//Trace("island : " + GetIslandName(nCurScroll) + " ");
	int BerthNum = 0;
	for (int j = 1; j <= tnum; j++) {
		int townidx = GetTownIndex(GetTownIDFromIsland(GetIslandName(nCurScroll), j));	
		if (townidx>=0 && townidx < TOWNS_QUANTITY && CheckAttribute(&Towns[townidx], "shipberth")) {
			tempnumc2++;
			BerthNum++;
		}
	} // Screwface
	tempnumc1 = 1;
	SetNodeUsing("TOWN_CHANGER", BerthNum > 1);
// <-- KK

// Sulan -->
  if (GetBerthedShipsQuantityForTown(GetPortName(nCurTown)) == 0)
	{
		GameInterface.strings.TownName = FindTownName(GetPortName(nCurTown));
		EnableString("NoBerthedShips");
		EnableString("TownName");
		GameInterface.strings.NoBerthedShips = TranslateString("", "(no ships berthed at") + " " + FindTownName(GetPortName(nCurTown)) + TranslateString("", ")");
// Sulan <--
		SetNodeUsing("SHIP1STATUSTXT",false);
		SetNodeUsing("SHIP2STATUSTXT",false);
		SetNodeUsing("SHIP3STATUSTXT",false);
		SetNodeUsing("SHIP4STATUSTXT",false);
		GameInterface.pictures.Ship1Pic.pic = -1;
		GameInterface.pictures.Ship1Pic.tex = -1;
		GameInterface.pictures.Ship2Pic.pic = -1;
		GameInterface.pictures.Ship2Pic.tex = -1;
		GameInterface.pictures.Ship3Pic.pic = -1;
		GameInterface.pictures.Ship3Pic.tex = -1;
		GameInterface.pictures.Ship4Pic.pic = -1;
		GameInterface.pictures.Ship4Pic.tex = -1;
		SetNodeUsing("SHIPSLOT1BACK",false);
		SetNodeUsing("SHIPSLOT2BACK",false);
		SetNodeUsing("SHIPSLOT3BACK",false);
		SetNodeUsing("SHIPSLOT4BACK",false);
	}
	else
	{
		// Sulan -->
		GameInterface.strings.TownName = FindTownName(GetPortName(nCurTown));
		EnableString("TownName");
		// Sulan <--
		DisableString("NoBerthedShips");


		SetNodeUsing("SHIP1STATUSTXT",true);
		SetNodeUsing("SHIPSLOT1BACK",true);
		if (!checkAttribute(PChar, "ShipBerthing." + tempattrib  + ".slot1.status") || PChar.ShipBerthing.(tempattrib).slot1.status == 0)
		{
			SetFormatedText("SHIP1STATUSTXT", TranslateString("", "(empty slot)")); // KK
			CreateImage("Ship1Pic","BLANK_SHIP","Not Used",30,230,70,270);
		}
		else
		{
			tempnumc1 = PChar.ShipBerthing.(tempattrib).slot1.shiptype;
			tempnumc2 = PChar.ShipBerthing.(tempattrib).slot1.status;
			tempstringc1 = GetBerthingStatusName(tempnumc2,false);
			SetFormatedText("SHIP1STATUSTXT",PChar.ShipBerthing.(tempattrib).slot1.shipname + GetShipTypeDisplayName(tempnumc1) + ", " + tempstringc1 + " " + TranslateString("","(CLICK TO VIEW)")); // KK
			GetShipPic(tempnumc1);
			CreateImage("Ship1Pic",ReturnedShipPicGroup,ReturnedShipPic,30,230,70,270);
		}


		SetNodeUsing("SHIP2STATUSTXT",true);
		SetNodeUsing("SHIPSLOT2BACK",true);
		
		if (!checkAttribute(PChar, "ShipBerthing." + tempattrib  + ".slot2.status") || PChar.ShipBerthing.(tempattrib).slot2.status == 0)
		{
			SetFormatedText("SHIP2STATUSTXT", TranslateString("","(empty slot)")); // KK
			CreateImage("Ship2Pic","BLANK_SHIP","Not Used",30,280,70,320);
		}
		else
		{
			tempnumc1 = PChar.ShipBerthing.(tempattrib).slot2.shiptype;
			tempnumc2 = PChar.ShipBerthing.(tempattrib).slot2.status;
			tempstringc1 = GetBerthingStatusName(tempnumc2,false);
			SetFormatedText("SHIP2STATUSTXT",PChar.ShipBerthing.(tempattrib).slot2.shipname + GetShipTypeDisplayName(tempnumc1) + ", " + tempstringc1 + " " + TranslateString("", "(CLICK TO VIEW)")); // KK
			GetShipPic(tempnumc1);
			CreateImage("Ship2Pic",ReturnedShipPicGroup,ReturnedShipPic,30,280,70,320);
		}


		SetNodeUsing("SHIP3STATUSTXT",true);
		SetNodeUsing("SHIPSLOT3BACK",true);
		if (!checkAttribute(PChar, "ShipBerthing." + tempattrib  + ".slot3.status") || PChar.ShipBerthing.(tempattrib).slot3.status == 0)
		{
			SetFormatedText("SHIP3STATUSTXT", TranslateString("", "(empty slot)")); // KK
			CreateImage("Ship3Pic","BLANK_SHIP","Not Used",30,330,70,370);
		}
		else
		{
			tempnumc1 = PChar.ShipBerthing.(tempattrib).slot3.shiptype;
			tempnumc2 = PChar.ShipBerthing.(tempattrib).slot3.status;
			tempstringc1 = GetBerthingStatusName(tempnumc2,false);
			SetFormatedText("SHIP3STATUSTXT",PChar.ShipBerthing.(tempattrib).slot3.shipname + GetShipTypeDisplayName(tempnumc1) + ", " + tempstringc1 + " " + TranslateString("", "(CLICK TO VIEW)")); // KK
			GetShipPic(tempnumc1);
			CreateImage("Ship3Pic",ReturnedShipPicGroup,ReturnedShipPic,30,330,70,370);
		}


		SetNodeUsing("SHIP4STATUSTXT",true);
		SetNodeUsing("SHIPSLOT4BACK",true);
		if (!checkAttribute(PChar, "ShipBerthing." + tempattrib  + ".slot4.status") || PChar.ShipBerthing.(tempattrib).slot4.status == 0)
		{
			SetFormatedText("SHIP4STATUSTXT", TranslateString("", "(empty slot)")); // KK
			CreateImage("Ship4Pic","BLANK_SHIP","Not Used",30,380,70,420);
		}
		else
		{
			tempnumc1 = PChar.ShipBerthing.(tempattrib).slot4.shiptype;
			tempnumc2 = PChar.ShipBerthing.(tempattrib).slot4.status;
			tempstringc1 = GetBerthingStatusName(tempnumc2,false);
			SetFormatedText("SHIP4STATUSTXT",PChar.ShipBerthing.(tempattrib).slot4.shipname + GetShipTypeDisplayName(tempnumc1) + ", " + tempstringc1 + " " + TranslateString("", "(CLICK TO VIEW)")); // KK
			GetShipPic(tempnumc1);
			CreateImage("Ship4Pic",ReturnedShipPicGroup,ReturnedShipPic,30,380,70,420);
		}
	}


	if (nCurTown == CurrentPortNumber) // Sulan
	{
		if(HasSubStr(Locations[FindLoadedLocation()].id, "shipyard") || Locations[FindLoadedLocation()].id == "Roa_Hideout")
		{
			SetSelectable("BERTHASHIPHEREBTN",true);
		}
		else
		{
			SetSelectable("BERTHASHIPHEREBTN",false);
			// Screwface : don't remove the checkattribute it is important to have no errors on ship decks
			if(CheckAttribute(&Locations[FindLoadedLocation()],"island") && Locations[FindLoadedLocation()].island == "KhaelRoa")
				GameInterface.strings.shipyard = TranslateString("", "(You can berth/relaunch ships in the Secret hideout)");
			else
				GameInterface.strings.shipyard = TranslateString("", "(You must be in the shipyard to berth or relaunch a ship)");
			EnableString("shipyard");
		}
	}
	else
	{
		SetSelectable("BERTHASHIPHEREBTN",false);
		DisableString("shipyard");
	}
}


void UpdateFDDisplay()
// called when one of the buttons on the FD window has been pressed and the selections changed
{
	// KK int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	bool TLHasCaptain;	// true if has captain set; false if no captain set
	bool BRHasCaptain;	// true if has captain set OR if no captain needed; false if captain needed but not set

	if (SwapMethod == 0 || SwapMethod == 1)
	{
		if (SelectedCompanionSlot == 1)
		{
			SetSelectable("FD_CHOOSETLCAPTAINBTN",false);
		}
		else
		{
			SetSelectable("FD_CHOOSETLCAPTAINBTN",true);
		}

		if (RelaunchingShipCaptain == -1)
		{
			SetFormatedText("FD_TOPLEFT_NEWCAPTAIN", TranslateString("" ,"New captain") + ": " + TranslateString("", "(CHOOSE A CAPTAIN)")); // KK
			TLHasCaptain = false;
		}
		else
		{
			SetFormatedText("FD_TOPLEFT_NEWCAPTAIN", TranslateString("","New captain") + ": " + GetCaptainNameFromIndex(RelaunchingShipCaptain));
			TLHasCaptain = true;
		}
	}

	if (SwapMethod == 0 || SwapMethod == 2)
	{
		SetSelectable("FD_CHANGEBERTHINGMETHODBTN",true);
		switch(BerthingMethod)
		{
			case 0:
				SetFormatedText("FD_BTMRIGHT_NEWSTATUS", TranslateString("", "Ship is to be put on SHORE LEAVE at") + " " + FindTownName(GetPortName(SelectedPort))); // KK
				SetSelectable("FD_CHOOSEBRCAPTAINBTN",true);
				if (BerthingShipCaptain == -1)
				{
					SetFormatedText("FD_BTMRIGHT_NEWCAPTAIN", TranslateString("", "New captain") + ": " + TranslateString("", "(CHOOSE A CAPTAIN)")); // KK
					BRHasCaptain = false;
				}
				else
				{
					SetFormatedText("FD_BTMRIGHT_NEWCAPTAIN",TranslateString("", "New captain") + ": " + GetCaptainNameFromIndex(BerthingShipCaptain)); // KK
					BRHasCaptain = true;
				}
			break;
			case 1:
				SetFormatedText("FD_BTMRIGHT_NEWSTATUS", TranslateString("", "Ship is to be LAID UP at") + " " + FindTownName(GetPortName(SelectedPort))); // KK
				SetFormatedText("FD_BTMRIGHT_NEWCAPTAIN",TranslateString("", "New captain") + ": -"); // KK
				BRHasCaptain = true;
				SetSelectable("FD_CHOOSEBRCAPTAINBTN",false);
			break;
		}

		if (SwapMethod == 2)
		{
			SetSelectable("FD_CHOOSETLCAPTAINBTN",false);
			TLHasCaptain = true;
		}

	}
	else
	{
		SetSelectable("FD_CHANGEBERTHINGMETHODBTN",false);
		SetSelectable("FD_CHOOSEBRCAPTAINBTN",false);
		BRHasCaptain = true;
	}

	if (TLHasCaptain && BRHasCaptain)
	{
		SetSelectable("FD_OKBTN",true);
	}
	else
	{
		SetSelectable("FD_OKBTN",false);
	}

}


// --> Swindler 2005-10-12: corrected syntax error
//void UpdateCCDisplay();
void UpdateCCDisplay()
// called when the left or right scroll buttons are pressed and a new captain therefore selected
{
	// KKint tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	string tempstringd1;
	string tempstringd2;
	int tempnumd1;
	int tempnumd2;
	ref chref;

	if (listnum > 0)
	{
		SetSelectable("FD_OKBTN",true);

		tempstringd1 = "member" + listcurrent;
		tempnumd1 = PChar.ShipBerthing.templist.(tempstringd1).index;

		tempstringd2 = GetCaptainNameFromIndex(tempnumd1);
		GameInterface.strings.CC_Name = tempstringd2;

		chref = GetCharacter(tempnumd1);
		tempnumd2 = PChar.ShipBerthing.templist.(tempstringd1).type;
		switch(tempnumd2)
		{
			case 0:
				tempstringd2 = TranslateString("", "Currently captain of the ship going on shore leave") + ", " + GetMyShipName(chref); // KK
				SetFormatedText("CC_CURRENTSTATUSTXT",tempstringd2);
			break;
			case 1:
				tempstringd2 = TranslateString("", "Currently captain of the ship being relaunched") + ", " + GetMyShipName(chref); // KK
				SetFormatedText("CC_CURRENTSTATUSTXT",tempstringd2);
			break;
			case 2:
				SetFormatedText("CC_CURRENTSTATUSTXT", TranslateString("", "Currently an officer")); // KK
			break;
			case 3:
				SetFormatedText("CC_CURRENTSTATUSTXT", TranslateString("", "Currently a passenger")); // KK
			break;
		}
		GameInterface.strings.CC_skillLeadership = CalcCharacterSkill(chref,SKILL_LEADERSHIP);
		GameInterface.strings.CC_skillFencing    = CalcCharacterSkill(chref,SKILL_FENCING);
		GameInterface.strings.CC_skillSailing    = CalcCharacterSkill(chref,SKILL_SAILING);
		GameInterface.strings.CC_skillAccuracy   = CalcCharacterSkill(chref,SKILL_ACCURACY);
		GameInterface.strings.CC_skillCannons    = CalcCharacterSkill(chref,SKILL_CANNONS);
		GameInterface.strings.CC_skillGrappling  = CalcCharacterSkill(chref,SKILL_GRAPPLING);
		GameInterface.strings.CC_skillRepair     = CalcCharacterSkill(chref,SKILL_REPAIR);
		GameInterface.strings.CC_skillDefence    = CalcCharacterSkill(chref,SKILL_DEFENCE);
		GameInterface.strings.CC_skillCommerce   = CalcCharacterSkill(chref,SKILL_COMMERCE);
		GameInterface.strings.CC_skillSneak      = CalcCharacterSkill(chref,SKILL_SNEAK);

		tempnumd2 = GetCharacterFaceID(chref.model);
		tempstringd2 = "FACE128_" + tempnumd2;
		CreateImage("Mugshot",tempstringd2,"face",86,49,214,177);

	}
	else
	{
		SetSelectable("FD_OKBTN",false);
		GameInterface.strings.CC_Name = TranslateString("", "(no available captains)"); // KK
		SetFormatedText("CC_CURRENTSTATUSTXT","-");
		GameInterface.strings.CC_skillLeadership = "";
		GameInterface.strings.CC_skillFencing = "";
		GameInterface.strings.CC_skillSailing = "";
		GameInterface.strings.CC_skillAccuracy = "";
		GameInterface.strings.CC_skillCannons = "";
		GameInterface.strings.CC_skillGrappling = "";
		GameInterface.strings.CC_skillRepair = "";
		GameInterface.strings.CC_skillDefence = "";
		GameInterface.strings.CC_skillCommerce = "";
		GameInterface.strings.CC_skillSneak = "";
// KK -->
		if (bNewInterface)
			CreateImage("Mugshot","EMPTYFACE","emptyface_new",86,49,214,177);
		else
			CreateImage("Mugshot","EMPTYFACE","emptyface",86,49,214,177);
// <-- KK
	}
}
