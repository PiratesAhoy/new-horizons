

//************************************************************************************************************
//
// FUNCTIONS FOR INITIALISATION
//
//************************************************************************************************************


// --> Swindler 2005-10-12: corrected syntax error
//void FillInfoArrays();
void FillInfoArrays()
// fills up the info arrays (port names and companion details) for easy access
{
	int tempnumf1;
	int tempnumf2;

	PCharAndCompanions_Indexes[0] = sti(PChar.index);
	PCharAndCompanions_Names[0] = PChar.name + " " + PChar.lastname;
	for (tempnumf1=1; tempnumf1<4; tempnumf1++) // MM TODO: COMPANION_MAX
	{
		tempnumf2 = sti(GetCompanionIndex(PChar,tempnumf1));
		PCharAndCompanions_Indexes[tempnumf1] = tempnumf2;
		if (tempnumf2 >= 0)
		{
			PCharAndCompanions_Names[tempnumf1] = Characters[tempnumf2].name + " " + Characters[tempnumf2].lastname;
		}
		else
		{
			PCharAndCompanions_Names[tempnumf1] = "";
		}
	}
	for (tempnumf1=0; tempnumf1<4; tempnumf1++) // MM TODO: COMPANION_MAX
	{
		tempnumf2 = PCharAndCompanions_Indexes[tempnumf1];
		if (tempnumf2 >= 0 && GetCharacterShipType(GetCharacter(tempnumf2)) != SHIP_NOTUSED && GetCharacterShipType(GetCharacter(tempnumf2)) >= 0)
		{
			PCharAndCompanions_ShipNames[tempnumf1] = GetMyShipName(GetCharacter(tempnumf2));
			PCharAndCompanions_ShipTypes[tempnumf1] = GetCharacterShipType(GetCharacter(tempnumf2));
			PCharAndCompanions_ShipPics[tempnumf1] = GetShipPic(PCharAndCompanions_ShipTypes[tempnumf1]);
			PCharAndCompanions_ShipPicGroups[tempnumf1] = ReturnedShipPicGroup;
		}
		else
		{
			PCharAndCompanions_ShipNames[tempnumf1] = "";
			PCharAndCompanions_ShipTypes[tempnumf1] = SHIP_NOTUSED;
			PCharAndCompanions_ShipPics[tempnumf1] = "Not Used";
			PCharAndCompanions_ShipPicGroups[tempnumf1] = "BLANK_SHIP";
		}
	}
}


void FillScroll()
//fills the scrollimage with island images
{
	nCurScroll = 0;
	if (CurrentIslandNumber >= 0)
	{
		GameInterface.islandslist.current = CurrentIslandNumber;
	}
	else
	{
		GameInterface.islandslist.current = 0;
	}

	GameInterface.islandslist.ImagesGroup.t1 = "ISLANDSICON";
// KK -->
	GameInterface.islandslist.SpecTechniqueColor = argb(55,255,255,255);
	GameInterface.islandslist.SpecTechniqueName = "iSpec1";

	int i = 0;
	int n = 0;
	string pic = "";
	while (i < ISLANDS_QUANTITY) {
		string island = Islands[i].id;
		int tnum = GetIslandTownsQuantity(island);
		bool berth_enabled = false;
		for (int j = 1; j <= tnum; j++) {
			int townidx = GetTownIndex(GetTownIDFromIsland(island, j)); // Screwface	
			if (townidx>=0 && townidx < TOWNS_QUANTITY && CheckAttribute(&Towns[townidx], "shipberth")) {
				berth_enabled = true;
				break;
			}
		}
		if (berth_enabled) {
			n++;
			pic = "pic" + n;
			GameInterface.islandslist.(pic).img1 = island;
			GameInterface.islandslist.(pic).tex1 = 0;
			GameInterface.islandslist.(pic).str1 = FindIslandName(island);
		}
		i++;
	}
	//Sulan -->
	//n++;
	//pic = "pic" + n;
	//GameInterface.islandslist.(pic).img1 = "KhaelRoa";
	//GameInterface.islandslist.(pic).tex1 = 0;
	//GameInterface.islandslist.(pic).str1 = FindIslandName("Khael Roa");
	//Sulan <--

/*	GameInterface.islandslist.pic1.img1 = "FalaiseDeFleur";
	GameInterface.islandslist.pic1.tex1 = 0;
	GameInterface.islandslist.pic2.img1 = "Redmond";
	GameInterface.islandslist.pic2.tex1 = 0;
	GameInterface.islandslist.pic3.img1 = "IslaMuelle";
	GameInterface.islandslist.pic3.tex1 = 0;
	GameInterface.islandslist.pic4.img1 = "Oxbay";
	GameInterface.islandslist.pic4.tex1 = 0;
	GameInterface.islandslist.pic5.img1 = "Oxbay";
	GameInterface.islandslist.pic5.tex1 = 0;
	GameInterface.islandslist.pic6.img1 = "Conceicao";
	GameInterface.islandslist.pic6.tex1 = 0;
	GameInterface.islandslist.pic7.img1 = "Douwesen";
	GameInterface.islandslist.pic7.tex1 = 0;
	GameInterface.islandslist.pic8.img1 = "QuebradasCostillas";
	GameInterface.islandslist.pic8.tex1 = 0;
	GameInterface.islandslist.pic9.img1 = "KhaelRoa";
	GameInterface.islandslist.pic9.tex1 = 0;
	GameInterface.islandslist.pic10.img1 = "Tortuga";
	GameInterface.islandslist.pic10.tex1 = 0;
	GameInterface.islandslist.pic11.img1 = "SaintMartin";
	GameInterface.islandslist.pic11.tex1 = 0;
	GameInterface.islandslist.pic12.img1 = "Cuba";
	GameInterface.islandslist.pic12.tex1 = 0;
	GameInterface.islandslist.pic13.img1 = "Cuba";
	GameInterface.islandslist.pic13.tex1 = 0;
	GameInterface.islandslist.pic14.img1 = "Antigua";
	GameInterface.islandslist.pic14.tex1 = 0;
	GameInterface.islandslist.pic15.img1 = "Guadeloupe";
	GameInterface.islandslist.pic15.tex1 = 0;
	GameInterface.islandslist.pic16.img1 = "Hispaniola";
	GameInterface.islandslist.pic16.tex1 = 0;
	GameInterface.islandslist.pic17.img1 = "Hispaniola";
	GameInterface.islandslist.pic17.tex1 = 0;
	GameInterface.islandslist.pic18.img1 = "Tortuga";
	GameInterface.islandslist.pic18.tex1 = 0;
	GameInterface.islandslist.pic19.img1 = "Antigua";
	GameInterface.islandslist.pic19.tex1 = 0;*/

	GameInterface.islandslist.ListSize = n;
// <-- KK
}




//************************************************************************************************************
//
// USEFUL ID->DISPLAYABLE STRING FUNCTIONS
//
//************************************************************************************************************


// --> Swindler 2005-10-12: corrected syntax error
//string GetShipPic(int shiptypenum);
string GetShipPic(int shiptypenum)
//returns the ship picture id and ship picture group name (from pictures.ini) when given the ship type index
{
	if(shiptypenum >= 0 && shiptypenum < SHIP_TYPES_QUANTITY)
	{
		string shippic = GetShipPicName(shiptypenum);  // Screwface
		switch(shippic)
		{
			case "boat":
				ReturnedShipPic = "tartane1";
				ReturnedShipPicGroup = "SHIPS16";
			break;
			//default:
			ReturnedShipPic = GetShipPicName(shiptypenum);  // Screwface
			ReturnedShipPicGroup = GetShipTextureName(shiptypenum); // PB
		}
	}
	else
	{	
		ReturnedShipPic = "Not Used";
		ReturnedShipPicGroup = "BLANK_SHIP";
	}
	Return ReturnedShipPic;
}


// NK now we have this function in interface\utilite.c for both ship.c and this, so this isn't necessary. Also, it was updated for KNB. 05-04-10
/*string GetCannonName(int CannonTypeNum)
//returns the display name of the cannons when given the cannon index number
{
	switch(CannonTypeNum)
	{
		case CANNON_TYPE_CULVERINE_LBS12:	return "12lbs Culverine";	break;
		case CANNON_TYPE_CULVERINE_LBS16:	return "16lbs Culverine";	break;
		case CANNON_TYPE_CULVERINE_LBS24:	return "24lbs Culverine";	break;
		case CANNON_TYPE_CANNON_LBS12:		return "12lbs Cannon";		break;
		case CANNON_TYPE_CANNON_LBS16:		return "16lbs Cannon";		break;
		case CANNON_TYPE_CANNON_LBS24:		return "24lbs Cannon";		break;
		case CANNON_TYPE_CANNON_LBS32:		return "32lbs Cannon";		break;
		case CANNON_TYPE_NONECANNON:		return "none";			break;
		//default:
			return "-";			break;
	}
}*/


string GetBerthingStatusName(int BerthingStatusNum, bool InitialCapital)
//returns "laid up" or "on shore leave", with or without initial capital)
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	switch(InitialCapital)
	{
		case true:
			switch (BerthingStatusNum)
			{
				case 1:		return LanguageConvertString(tmpLangFileID,"Laid up");		break;
				case 2:		return LanguageConvertString(tmpLangFileID,"On shore leave");	break;
			}
		break;
		case false:
			switch (BerthingStatusNum)
			{
				case 1:		return XI_ConvertString("laid up");		break;
				case 2:		return XI_ConvertString("on shore leave");	break;
			}
		break;
	}
	return -1;
}


string GetCaptainNameFromIndex(int captainindex)
{
	if (captainindex < 0)
	{
		return "(index " + captainindex + ")";
	}
	else
	{
		return Characters[captainindex].name + " " + Characters[captainindex].lastname;
	}
}


string GetShipTypeDisplayName(string shiptypenum)
//when given a ship type index, it returns a full string with name and class in brackets, e.g. " (Manowar, class 1)"
{
	string tempstringh1 = ShipsTypes[shiptypenum].SName;
	string tempstringh2 = " (" + XI_ConvertString(tempstringh1) + ", " + XI_ConvertString("class") + " " + ShipsTypes[shiptypenum].class + ")";
	return tempstringh2;
}





//************************************************************************************************************
//
// MISC
//
//************************************************************************************************************


// --> Swindler 2005-10-12: corrected syntax error
//void FillCaptainsList();
//creates a list of potential captains for the 'choose a captain' window
void FillCaptainsList()
{
	string tempstringi1;
	string tempstringi2;
	string tempstringi3;
	int tempnumi1;
	int tempnumi2;
	int tempnumi3;
	int tempnumi4;
	int tempnumi5;
	bool tempbooli1;
	ref temprefi1;

	tempstringi1 = "port" + SelectedPort;
	tempstringi2 = "slot" + SelectedBerthingSlot;

	// creates a list of potential captains' indexes and stores it in PChar's properties
	// the 'types' are: 0 = BR (berthing) old captain; 1 = TL (relaunching) old captain; 2 = officers; 3 = passengers
	listnum = 1;

	// adds old captain of berthing ship, if there is one, unless it's PChar
	if (SwapMethod == 0 || SwapMethod == 2)
	{
		if (SelectedCompanionSlot != 1)
		{
			tempstringi3 = "member" + listnum;
			PChar.ShipBerthing.templist.(tempstringi3).type = 0;
			tempnumi1 = PCharAndCompanions_Indexes[SelectedCompanionSlot-1];
			PChar.ShipBerthing.templist.(tempstringi3).index = tempnumi1;
			listnum++;
		}
	}

	// adds old captain of relaunching ship, if there is one
	if (SwapMethod == 0 || SwapMethod == 1)
	{
		tempnumi1 = PChar.ShipBerthing.(tempstringi1).(tempstringi2).status;
		if (tempnumi1 == 2)
		{
			tempstringi3 = "member" + listnum;
			PChar.ShipBerthing.templist.(tempstringi3).type = 1;
			tempnumi2 = PChar.ShipBerthing.(tempstringi1).(tempstringi2).captainindex;
			PChar.ShipBerthing.templist.(tempstringi3).index = tempnumi2;
			listnum++;
		}
	}

	// adds any passengers there are
	tempnumi1 = GetPassengersQuantity(PChar);
	for (tempnumi3=0; tempnumi3<tempnumi1; tempnumi3++)
	{
		tempnumi4 = GetPassenger(PChar,tempnumi3);
		if (tempnumi4 >= 0)
		{
			tempstringi3 = "member" + listnum;
			temprefi1 = GetCharacter(tempnumi4);
			if(CheckAttribute(temprefi1,"prisoned") != true)					// if the passenger is not a prisoner...
			{
				tempnumi5 = CalcCharacterSkill(temprefi1,SKILL_SAILING);			// ...and the passenger has a sailing skill, then he is added
				if(tempnumi5 > 0)
				{
					if (IsOfficer(temprefi1))						// checks whether he's an officer or just a passenger
					{
						PChar.ShipBerthing.templist.(tempstringi3).type = 2;
					}
					else
					{
						PChar.ShipBerthing.templist.(tempstringi3).type = 3;
					}

					PChar.ShipBerthing.templist.(tempstringi3).index = tempnumi4;
					listnum++;
				}
			}
		}
	}

	if (listnum == 1)
	{
		listcurrent = 0;
	}
	else
	{
		listcurrent = 1;

		// checks to see which is the currently selected one and sets listcurrent to that
		for (tempnumi3=1; tempnumi3<listnum; tempnumi3++)
		{
			tempstringi3 = "member" + tempnumi3;
			tempnumi1 = PChar.ShipBerthing.templist.(tempstringi3).index;
			if (ChoosingCaptain == 1)
			{
				if (RelaunchingShipCaptain == tempnumi1)
				{
					listcurrent = tempnumi3;
				}
			}
			else
			{
				if (BerthingShipCaptain == tempnumi1)
				{
					listcurrent = tempnumi3;
				}
			}
		}
	}
	
	listnum--;
}
