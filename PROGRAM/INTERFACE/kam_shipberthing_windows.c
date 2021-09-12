

//************************************************************************************************************
//
// WINDOW FUNCTIONS
//
//************************************************************************************************************

// the window name strings in use are (nb case sensitive):
//		Base
//	BSD	Berthed Ship Details
//	RBSCS	Relaunch Berthed Ship - Choose Slot
//	BSCSh	Berth Ship - Choose Ship
//	BSCSl	Berth Ship - Choose Slot
//	FD	Final Details
//	CC	Choose a Captain
//	FC	Final Confirmation
//			for which the FCControlsID strings in use are:
//				Ship Berthing
//				Lay up ship on shore leave
//				Scrap berthed ship


void ChangeWindow(string NewWindow)
{
	DisableString("CantBerthShip"); // Screwface
	string PreviousWindow = CurrentWindow;
	CurrentWindow = NewWindow;
	DoWindow(PreviousWindow,false);
	DoWindow(CurrentWindow,true);
}

void DoWindow(string ChosenWindow, bool ShowBool)
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	string tempstringa1;
	string tempstringa2;
	string tempstringa3;
	int tempnuma1;
	int tempnuma2;
	int tempnuma3;
	ref aCaptainChar;
	float tempfloata1;

	switch(ChosenWindow)
	{
		case "Base":
			if (Showbool == false)
			{
				SetNodeUsing("ISLANDSLIST",false);
				SetNodeUsing("BASE_RECTANGLE",false);
				SetNodeUsing("TITLEBOX",false);
				SetNodeUsing("SHIPSLOT1BACK",false);
				SetNodeUsing("SHIPSLOT2BACK",false);
				SetNodeUsing("SHIPSLOT3BACK",false);
				SetNodeUsing("SHIPSLOT4BACK",false);
				SetNodeUsing("BERTHASHIPHEREBTN",false);
				SetNodeUsing("CLOSEWINDOWBTN",false);
				SetNodeUsing("BASE_BOUND",false);
				SetNodeUsing("LEFTSCROLLBUTTON",false);
				SetNodeUsing("RIGHTSCROLLBUTTON",false);
				SetNodeUsing("SHIP1STATUSTXT",false);
				SetNodeUsing("SHIP2STATUSTXT",false);
				SetNodeUsing("SHIP3STATUSTXT",false);
				SetNodeUsing("SHIP4STATUSTXT",false);
				DisableString("IslandName");
				DisableString("NoBerthedShips");
				DisableString("TownName"); // Sulan
				GameInterface.pictures.Ship1Pic.pic = -1;
				GameInterface.pictures.Ship1Pic.tex = -1;
				GameInterface.pictures.Ship2Pic.pic = -1;
				GameInterface.pictures.Ship2Pic.tex = -1;
				GameInterface.pictures.Ship3Pic.pic = -1;
				GameInterface.pictures.Ship3Pic.tex = -1;
				GameInterface.pictures.Ship4Pic.pic = -1;
				GameInterface.pictures.Ship4Pic.tex = -1;
			}
			else
			{
				SetNodeUsing("ISLANDSLIST",true);
				SetNodeUsing("BASE_RECTANGLE",true);
				SetNodeUsing("TITLEBOX",true);
				SetNodeUsing("BERTHASHIPHEREBTN",true);
				SetNodeUsing("CLOSEWINDOWBTN",true);
				SetNodeUsing("BASE_BOUND",true);
				SetNodeUsing("LEFTSCROLLBUTTON",true);
				SetNodeUsing("RIGHTSCROLLBUTTON",true);
				EnableString("IslandName");
				EnableString("TownName"); // Sulan
				UpdateBaseDisplay();
				SetCurrentNode("CLOSEWINDOWBTN");
			}
		break;



		case "Berthed Ship Details":
			if (Showbool == false)
			{
				SetNodeUsing("BSD_RECTANGLE",false);
				SetNodeUsing("BSD_BOUND",false);
				SetNodeUsing("BSD_CLOSEBTN",false);
				SetNodeUsing("BSD_LAYUPSHIPBTN1",false);
				SetNodeUsing("BSD_LAYUPSHIPBTN2",false);
				SetNodeUsing("BSD_RELEASESHIPBTN",false);
				SetNodeUsing("BSD_SHIPPIC",false);
				GameInterface.pictures.BigShipPic.pic = -1;
				GameInterface.pictures.BigShipPic.tex = -1;
				DisableString("BSD_ShipNameAndType");
				DisableString("BSD_ShipStatus");
				DisableString("BSD_ShipCaptain");
				DisableString("BSD_Hull");
				DisableString("BSD_Rigging");
				DisableString("BSD_Crew");
				DisableString("BSD_DaysInBerth");
				DisableString("BSD_Guns");
				DisableString("BSD_Cargo");
				SetNodeUsing("BSD_BERTHINGCOST",false);
				SetNodeUsing("BSD_BERTHINGNOWDUE",false);
				SetNodeUsing("BSD_CREWCOST",false);
				SetNodeUsing("BSD_CREWNOWDUE",false);
			}
			else
			{
				SetNodeUsing("TOWN_CHANGER", 0);  // Screwface : To avoid towns scrolling arrows in the other screens
				SetNodeUsing("BSD_RECTANGLE",true);
				SetNodeUsing("BSD_BOUND",true);
				SetNodeUsing("BSD_SHIPPIC",true);
				tempstringa1 = "port" + SelectedPort;
				tempstringa2 = "slot" + SelectedBerthingSlot;
				tempnuma1 = PChar.ShipBerthing.(tempstringa1).(tempstringa2).shiptype;
				GetShipPic(tempnuma1);
				CreateImage("BigShipPic",ReturnedShipPicGroup,ReturnedShipPic,30,65,130,165);
				if (PChar.ShipBerthing.(tempstringa1).(tempstringa2).status == 2)
				{
					SetNodeUsing("BSD_LAYUPSHIPBTN1",true);
					SetNodeUsing("BSD_LAYUPSHIPBTN2",true);
					SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"BSD_LAYUPSHIPBTN2",0,"#"+XI_ConvertString("KAM_SB_LayUpShip"));
					EnableString("BSD_ShipCaptain");
					tempnuma2 = PChar.ShipBerthing.(tempstringa1).(tempstringa2).captainindex;
					GameInterface.strings.BSD_ShipCaptain = XI_ConvertString("Captain") + ": " + GetCaptainNameFromIndex(tempnuma2);
				}
				else
				{
					SetNodeUsing("BSD_LAYUPSHIPBTN2",true);
					SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"BSD_LAYUPSHIPBTN2",0,"#"+XI_ConvertString("KAM_SB_ScrapShip"));
				}
				SetNodeUsing("BSD_RELEASESHIPBTN",true);
				if (SelectedPort == CurrentPortNumber)
				{
					if(HasSubStr(Locations[FindLoadedLocation()].id, "shipyard") || Locations[FindLoadedLocation()].id == "Roa_Hideout")
					{
						SetSelectable("BSD_RELEASESHIPBTN",true);
						SetSelectable("BSD_LAYUPSHIPBTN2",true);
						SetSelectable("BSD_LAYUPSHIPBTN1",true);
					}
					else
					{
						SetSelectable("BSD_RELEASESHIPBTN",false);
						SetSelectable("BSD_LAYUPSHIPBTN2",false);
						SetSelectable("BSD_LAYUPSHIPBTN1",false);
					}
				}
				else
				{
					SetSelectable("BSD_RELEASESHIPBTN",false);
					SetSelectable("BSD_LAYUPSHIPBTN2",false);
					SetSelectable("BSD_LAYUPSHIPBTN1",false);
				}
				EnableString("BSD_ShipNameAndType");
				GameInterface.strings.BSD_ShipNameAndType = PChar.ShipBerthing.(tempstringa1).(tempstringa2).shipname + GetShipTypeDisplayName(tempnuma1);
				EnableString("BSD_ShipStatus");
				tempnuma2 = PChar.ShipBerthing.(tempstringa1).(tempstringa2).status;
				tempstringa3 = GetBerthingStatusName(tempnuma2,true);
				GameInterface.strings.BSD_ShipStatus = tempstringa3 + " " + XI_ConvertString("at") + " " + FindTownName(GetPortName(SelectedPort)); // KK
				SetNodeUsing("BSD_CLOSEBTN",true);
				EnableString("BSD_Hull");
				EnableString("BSD_Rigging");
				EnableString("BSD_Crew");
				EnableString("BSD_DaysInBerth");
				EnableString("BSD_Guns");
				EnableString("BSD_Cargo");
				SetNodeUsing("BSD_BERTHINGCOST",true);
				SetNodeUsing("BSD_BERTHINGNOWDUE",true);
				aref arship; // PRS3
				if (PChar.ShipBerthing.(tempstringa1).(tempstringa2).status == 2)
				{
					tempnuma1 = sti(PChar.ShipBerthing.(tempstringa1).(tempstringa2).captainindex);
					aCaptainChar = GetCharacter(tempnuma1);
					makearef(arship, aCaptainChar.ship); // PRS3
					tempnuma2 = aCaptainChar.ship.idx;
					GameInterface.strings.BSD_Hull = XI_ConvertString("Hull") + ": " + makeint(GetHullPercent(aCaptainChar)) + "%";
					GameInterface.strings.BSD_Rigging = XI_ConvertString("Rig") + ": " + makeint(GetSailPercent(aCaptainChar)) + "%";
					GameInterface.strings.BSD_Crew = XI_ConvertString("Crew") + ": " + GetCrewQuantity(aCaptainChar) + " / " + ShipsTypes[tempnuma2].maxcrew;
					GameInterface.strings.BSD_DaysInBerth = LanguageConvertString(tmpLangFileID,"Days in berth") + ": " + PChar.ShipBerthing.(tempstringa1).(tempstringa2).daysinberth;
					tempnuma3 = aCaptainChar.ship.cannons.type;
					// NK can qty 05-04-18 - GameInterface.strings.BSD_Guns = "Guns: " + ShipsTypes[tempnuma2].CannonsQuantity + ", " + GetCannonName(tempnuma3);
					GameInterface.strings.BSD_Guns = XI_ConvertString("Guns") + ": " + GetLocalShipAttrib(&arship, &ShipsTypes[tempnuma2], "CurCanQty") + ", " + GetCannonName(tempnuma3); // NK can qty 05-04-18
					GameInterface.strings.BSD_Cargo = XI_ConvertString("Cargo Hold") + ": " + GetCargoLoad(aCaptainChar) + " / " + ShipsTypes[tempnuma2].Capacity;
					tempnuma3 = PChar.ShipBerthing.(tempstringa1).(tempstringa2).dailycost;
					tempnuma2 = PChar.ShipBerthing.(tempstringa1).(tempstringa2).daysinberth;
					SetFormatedText("BSD_BERTHINGCOST",XI_ConvertString("Berthing cost") + ": " + (tempnuma3 * 30) + "/" + XI_ConvertString("mth"));
					SetFormatedText("BSD_BERTHINGNOWDUE",LanguageConvertString(tmpLangFileID,"Calculated daily (now due") + ": " + PChar.ShipBerthing.(tempstringa1).(tempstringa2).nowdue + ")");
					SetNodeUsing("BSD_CREWCOST",true);
					tempnuma3 = SBGetShoreLeavePay(tempnuma1,GetCrewQuantity(aCaptainChar));
					SetFormatedText("BSD_CREWCOST",LanguageConvertString(tmpLangFileID,"Crew & officers' pay") + ": " + tempnuma3 + "/" + XI_ConvertString("mth"));
					SetNodeUsing("BSD_CREWNOWDUE",true);
					SetFormatedText("BSD_CREWNOWDUE",LanguageConvertString(tmpLangFileID,"Calculated monthly (now due") + ": " + PChar.ShipBerthing.(tempstringa1).(tempstringa2).crewnowdue + ")");
				}
				else
				{
					tempnuma1 = sti(PChar.ShipBerthing.(tempstringa1).(tempstringa2).hull);
					tempnuma2 = PChar.ShipBerthing.(tempstringa1).(tempstringa2).shiptype;
					tempfloata1 = (stf(tempnuma1) / stf(ShipsTypes[tempnuma2].HP)) * 100;
					GameInterface.strings.BSD_Hull = XI_ConvertString("Hull") + ": " + makeint(tempfloata1) + "%";
					GameInterface.strings.BSD_Rigging = XI_ConvertString("Rig") + ": 0%";
					GameInterface.strings.BSD_Crew = XI_ConvertString("Crew") + ": 0 / " + ShipsTypes[tempnuma2].MaxCrew;
					GameInterface.strings.BSD_DaysInBerth = LanguageConvertString(tmpLangFileID,"Days in berth") + ": " + PChar.ShipBerthing.(tempstringa1).(tempstringa2).daysinberth;
					tempnuma1 = PChar.ShipBerthing.(tempstringa1).(tempstringa2).guns;
					// NK can qty 05-04-18 - GameInterface.strings.BSD_Guns = "Guns: " + ShipsTypes[tempnuma2].CannonsQuantity + ", " + GetCannonName(tempnuma1);
					GameInterface.strings.BSD_Guns = XI_ConvertString("Guns") + ": " + GetLocalShipAttrib(&arship, &ShipsTypes[tempnuma2], "CurCanQty") + ", " + GetCannonName(tempnuma1); // NK can qty 05-04-18
					GameInterface.strings.BSD_Cargo = XI_ConvertString("Cargo Hold") + ": 0 / " + ShipsTypes[tempnuma2].Capacity;
					tempnuma1 = PChar.ShipBerthing.(tempstringa1).(tempstringa2).dailycost;
					tempnuma2 = PChar.ShipBerthing.(tempstringa1).(tempstringa2).daysinberth;
					SetFormatedText("BSD_BERTHINGCOST",XI_ConvertString("Berthing cost") + ": " + (tempnuma1 * 30) + "/" + XI_ConvertString("mth"));
					SetFormatedText("BSD_BERTHINGNOWDUE",LanguageConvertString(tmpLangFileID,"Calculated daily (now due") + ": " + PChar.ShipBerthing.(tempstringa1).(tempstringa2).nowdue + ")");
				}
				SetCurrentNode("BSD_CLOSEBTN");
			}
		break;



		case "Relaunch Berthed Ship - Choose Slot":
			if (Showbool == false)
			{
				SetNodeUsing("BSD_RECTANGLE",false);
				SetNodeUsing("BSD_BOUND",false);
				SetNodeUsing("BSD_SHIPPIC",false);
				GameInterface.pictures.BigShipPic.pic = -1;
				GameInterface.pictures.BigShipPic.tex = -1;
				DisableString("BSD_ShipNameAndType");
				DisableString("BSD_ShipStatus");
				DisableString("BSD_ShipCaptain");
				SetNodeUsing("BSD_SHIPPIC",false);
				SetNodeUsing("SHIPSLOT1BACK",false);
				SetNodeUsing("SHIPSLOT2BACK",false);
				SetNodeUsing("SHIPSLOT3BACK",false);
				SetNodeUsing("SHIPSLOT4BACK",false);
				SetNodeUsing("RBSCS_CANCELBTN",false);
				DisableString("RBSCS");
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
			}
			else
			{
				SetNodeUsing("TOWN_CHANGER", 0);  // Screwface
				BeganViaBS = false;
				SetNodeUsing("BSD_RECTANGLE",true);
				SetNodeUsing("BSD_BOUND",true);
				SetNodeUsing("BSD_SHIPPIC",true);
				tempstringa1 = "port" + SelectedPort;
				tempstringa2 = "slot" + SelectedBerthingSlot;
				tempnuma1 = PChar.ShipBerthing.(tempstringa1).(tempstringa2).shiptype;
				GetShipPic(tempnuma1);
				CreateImage("BigShipPic",ReturnedShipPicGroup,ReturnedShipPic,30,65,130,165);
				if (PChar.ShipBerthing.(tempstringa1).(tempstringa2).status == 2)
				{
					EnableString("BSD_ShipCaptain");
					tempnuma2 = PChar.ShipBerthing.(tempstringa1).(tempstringa2).captainindex;
					GameInterface.strings.BSD_ShipCaptain = XI_ConvertString("Captain") + ": " + GetCaptainNameFromIndex(tempnuma2);
				}
				EnableString("BSD_ShipNameAndType");
				GameInterface.strings.BSD_ShipNameAndType = PChar.ShipBerthing.(tempstringa1).(tempstringa2).shipname + GetShipTypeDisplayName(tempnuma1);
				EnableString("BSD_ShipStatus");
				tempnuma2 = PChar.ShipBerthing.(tempstringa1).(tempstringa2).status;
				tempstringa3 = GetBerthingStatusName(tempnuma2,true);
				GameInterface.strings.BSD_ShipStatus = tempstringa3 + " " + XI_ConvertString("at") + " " + FindTownName(GetPortName(SelectedPort)); // KK
				SetNodeUsing("SHIPSLOT1BACK",true);
				SetNodeUsing("SHIPSLOT2BACK",true);
				SetNodeUsing("SHIPSLOT3BACK",true);
				SetNodeUsing("SHIPSLOT4BACK",true);
				SetNodeUsing("RBSCS_CANCELBTN",true);
				EnableString("RBSCS");
				GameInterface.strings.RBSCS = LanguageConvertString(tmpLangFileID,"Choose a companion slot in which to relaunch this ship:");

				SetNodeUsing("SHIP1STATUSTXT",true);
				if (PCharAndCompanions_ShipTypes[0] != SHIP_NOTUSED)
				{	
					tempnuma1 = PCharAndCompanions_ShipTypes[0];
					SetFormatedText("SHIP1STATUSTXT",LanguageConvertString(tmpLangFileID,"Swap with the") + " " + PCharAndCompanions_ShipNames[0] + GetShipTypeDisplayName(tempnuma1) + ", " + XI_ConvertString("cpt.") + " " + PCharAndCompanions_Names[0]);
				}
				else
				{
					SetFormatedText("SHIP1STATUSTXT",LanguageConvertString(tmpLangFileID,"Relaunch into empty companion slot") + " 1 " + LanguageConvertString(tmpLangFileID,"(flagship slot)"));
				}

				SetNodeUsing("SHIP2STATUSTXT",true);
				if (PCharAndCompanions_ShipTypes[1] != SHIP_NOTUSED)
				{
					tempnuma1 = PCharAndCompanions_ShipTypes[1];
					aCaptainChar = GetCharacter(PCharAndCompanions_Indexes[1]);
					if (GetRemovable(aCaptainChar))
					{
						SetFormatedText("SHIP2STATUSTXT",LanguageConvertString(tmpLangFileID,"Swap with the") + " " + PCharAndCompanions_ShipNames[1] + GetShipTypeDisplayName(tempnuma1) + ", " + XI_ConvertString("cpt.") + " " + PCharAndCompanions_Names[1]);
					}
					else
					{
						SetFormatedText("SHIP2STATUSTXT",LanguageConvertString(tmpLangFileID,"(You may not swap with the") + " " + PCharAndCompanions_ShipNames[1] + ", " + XI_ConvertString("cpt.") + " " + PCharAndCompanions_Names[1] + ")");
					}
				}
				else
				{
					SetFormatedText("SHIP2STATUSTXT",LanguageConvertString(tmpLangFileID,"Relaunch into empty companion slot") + " 2");
				}

				SetNodeUsing("SHIP3STATUSTXT",true);
				if (PCharAndCompanions_ShipTypes[2] != SHIP_NOTUSED)
				{
					tempnuma1 = PCharAndCompanions_ShipTypes[2];
					aCaptainChar = GetCharacter(PCharAndCompanions_Indexes[2]);
					if (GetRemovable(aCaptainChar))
					{
						SetFormatedText("SHIP3STATUSTXT",LanguageConvertString(tmpLangFileID,"Swap with the") + " " + PCharAndCompanions_ShipNames[2] + GetShipTypeDisplayName(tempnuma1) + ", " + XI_ConvertString("cpt.") + " " + PCharAndCompanions_Names[2]);
					}
					else
					{
						SetFormatedText("SHIP3STATUSTXT",LanguageConvertString(tmpLangFileID,"(You may not swap with the") + " " + PCharAndCompanions_ShipNames[2] + ", " + XI_ConvertString("cpt.") + " " + PCharAndCompanions_Names[2] + ")");
					}
				}
				else
				{
					SetFormatedText("SHIP3STATUSTXT",LanguageConvertString(tmpLangFileID,"Relaunch into empty companion slot") + " 3");
				}

				SetNodeUsing("SHIP4STATUSTXT",true);
				if (PCharAndCompanions_ShipTypes[3] != SHIP_NOTUSED)
				{
					tempnuma1 = PCharAndCompanions_ShipTypes[3];
					aCaptainChar = GetCharacter(PCharAndCompanions_Indexes[3]);
					if (GetRemovable(aCaptainChar))
					{
						SetFormatedText("SHIP4STATUSTXT",LanguageConvertString(tmpLangFileID,"Swap with the") + " " + PCharAndCompanions_ShipNames[3] + GetShipTypeDisplayName(tempnuma1) + ", " + XI_ConvertString("cpt.") + " " + PCharAndCompanions_Names[3]);
					}
					else
					{
						SetFormatedText("SHIP4STATUSTXT",LanguageConvertString(tmpLangFileID,"(You may not swap with the") + " " + PCharAndCompanions_ShipNames[3] + ", " + XI_ConvertString("cpt.") + " " + PCharAndCompanions_Names[3] + ")");
					}
				}
				else
				{
					SetFormatedText("SHIP4STATUSTXT",LanguageConvertString(tmpLangFileID,"Relaunch into empty companion slot") + " 4");
				}

				CreateImage("Ship1Pic",PCharAndCompanions_ShipPicGroups[0],PCharAndCompanions_ShipPics[0],30,230,70,270);
				CreateImage("Ship2Pic",PCharAndCompanions_ShipPicGroups[1],PCharAndCompanions_ShipPics[1],30,280,70,320);
				CreateImage("Ship3Pic",PCharAndCompanions_ShipPicGroups[2],PCharAndCompanions_ShipPics[2],30,330,70,370);
				CreateImage("Ship4Pic",PCharAndCompanions_ShipPicGroups[3],PCharAndCompanions_ShipPics[3],30,380,70,420);
				SetCurrentNode("RBSCS_CANCELBTN");
			}
		break;



		case "Berth Ship - Choose Ship":
			if (Showbool == false)
			{
				SetNodeUsing("BSD_RECTANGLE",false);
				SetNodeUsing("BSD_BOUND",false);
				SetNodeUsing("SHIPSLOT1BACK",false);
				SetNodeUsing("SHIPSLOT2BACK",false);
				SetNodeUsing("SHIPSLOT3BACK",false);
				SetNodeUsing("SHIPSLOT4BACK",false);
				SetNodeUsing("RBSCS_CANCELBTN",false);
				DisableString("RBSCS");
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
			}
			else
			{
				SetNodeUsing("TOWN_CHANGER", 0);  // Screwface
				SetNodeUsing("BSD_RECTANGLE",true);
				SetNodeUsing("BSD_BOUND",true);
				SetNodeUsing("RBSCS_CANCELBTN",true);
				EnableString("RBSCS");
				GameInterface.strings.RBSCS = LanguageConvertString(tmpLangFileID,"Choose a ship to berth at") + " " + FindTownName(GetPortName(CurrentPortNumber)) + ":"; // KK

				if (PCharAndCompanions_ShipTypes[0] != SHIP_NOTUSED)
				{
					SetNodeUsing("SHIPSLOT1BACK",true);
					SetNodeUsing("SHIP1STATUSTXT",true);
					CreateImage("Ship1Pic",PCharAndCompanions_ShipPicGroups[0],PCharAndCompanions_ShipPics[0],30,230,70,270);
					SetFormatedText("SHIP1STATUSTXT",PCharAndCompanions_ShipNames[0] + GetShipTypeDisplayName(PCharAndCompanions_ShipTypes[0]) + ", " + XI_ConvertString("cpt.") + " " + PCharAndCompanions_Names[0]);
				}

				if (PCharAndCompanions_ShipTypes[1] != SHIP_NOTUSED)
				{
					SetNodeUsing("SHIPSLOT2BACK",true);
					SetNodeUsing("SHIP2STATUSTXT",true);
					CreateImage("Ship2Pic",PCharAndCompanions_ShipPicGroups[1],PCharAndCompanions_ShipPics[1],30,280,70,320);
					aCaptainChar = GetCharacter(PCharAndCompanions_Indexes[1]);
					if (GetRemovable(aCaptainChar))
					{
						SetFormatedText("SHIP2STATUSTXT",PCharAndCompanions_ShipNames[1] + GetShipTypeDisplayName(PCharAndCompanions_ShipTypes[1]) + ", " + XI_ConvertString("cpt.") + " " + PCharAndCompanions_Names[1]);
					}
					else
					{
						SetFormatedText("SHIP2STATUSTXT",LanguageConvertString(tmpLangFileID,"(You may not berth the") + " " + PCharAndCompanions_ShipNames[1] + ", " + XI_ConvertString("cpt.") + " " + PCharAndCompanions_Names[1] + ")");
					}
				}

				if (PCharAndCompanions_ShipTypes[2] != SHIP_NOTUSED)
				{
					SetNodeUsing("SHIP3STATUSTXT",true);
					SetNodeUsing("SHIPSLOT3BACK",true);
					CreateImage("Ship3Pic",PCharAndCompanions_ShipPicGroups[2],PCharAndCompanions_ShipPics[2],30,330,70,370);
					aCaptainChar = GetCharacter(PCharAndCompanions_Indexes[2]);
					if (GetRemovable(aCaptainChar))
					{
						SetFormatedText("SHIP3STATUSTXT",PCharAndCompanions_ShipNames[2] + GetShipTypeDisplayName(PCharAndCompanions_ShipTypes[2]) + ", " + XI_ConvertString("cpt.") + " " + PCharAndCompanions_Names[2]);
					}
					else
					{
						SetFormatedText("SHIP3STATUSTXT",LanguageConvertString(tmpLangFileID,"(You may not berth the") + " " + PCharAndCompanions_ShipNames[2] + ", " + XI_ConvertString("cpt.") + " " + PCharAndCompanions_Names[2] + ")");
					}
				}

				if (PCharAndCompanions_ShipTypes[3] != SHIP_NOTUSED)
				{
					SetNodeUsing("SHIP4STATUSTXT",true);
					SetNodeUsing("SHIPSLOT4BACK",true);
					CreateImage("Ship4Pic",PCharAndCompanions_ShipPicGroups[3],PCharAndCompanions_ShipPics[3],30,380,70,420);
					aCaptainChar = GetCharacter(PCharAndCompanions_Indexes[3]);
					if (GetRemovable(aCaptainChar))
					{
						SetFormatedText("SHIP4STATUSTXT",PCharAndCompanions_ShipNames[3] + GetShipTypeDisplayName(PCharAndCompanions_ShipTypes[3]) + ", " + XI_ConvertString("cpt.") + " " + PCharAndCompanions_Names[3]);
					}
					else
					{
						SetFormatedText("SHIP4STATUSTXT",LanguageConvertString(tmpLangFileID,"(You may not berth the") + " " + PCharAndCompanions_ShipNames[3] + ", " + XI_ConvertString("cpt.") + " " + PCharAndCompanions_Names[3] + ")");
					}
				}
				SetCurrentNode("RBSCS_CANCELBTN");
			}
		break;



		case "Berth Ship - Choose Slot":
			if (Showbool == false)
			{
				SetNodeUsing("BSD_RECTANGLE",false);
				SetNodeUsing("BSD_BOUND",false);
				SetNodeUsing("BSD_SHIPPIC",false);
				GameInterface.pictures.BigShipPic.pic = -1;
				GameInterface.pictures.BigShipPic.tex = -1;
				DisableString("BSD_ShipNameAndType");
				DisableString("BSD_ShipStatus");
				DisableString("BSD_ShipCaptain");
				SetNodeUsing("SHIPSLOT1BACK",false);
				SetNodeUsing("SHIPSLOT2BACK",false);
				SetNodeUsing("SHIPSLOT3BACK",false);
				SetNodeUsing("SHIPSLOT4BACK",false);
				SetNodeUsing("RBSCS_CANCELBTN",false);
				DisableString("RBSCS");
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
			}
			else
			{
				SetNodeUsing("TOWN_CHANGER", 0);  // Screwface
				BeganViaBS = true;
				SetNodeUsing("BSD_RECTANGLE",true);
				SetNodeUsing("BSD_BOUND",true);
				SetNodeUsing("BSD_SHIPPIC",true);
				tempnuma1 = PCharAndCompanions_shiptypes[SelectedCompanionSlot-1];
				GetShipPic(tempnuma1);
				CreateImage("BigShipPic",ReturnedShipPicGroup,ReturnedShipPic,30,65,130,165);
				EnableString("BSD_ShipCaptain");
				GameInterface.strings.BSD_ShipCaptain = XI_ConvertString("Captain") + ": " + PCharAndCompanions_names[SelectedCompanionSlot-1];
				EnableString("BSD_ShipNameAndType");
				GameInterface.strings.BSD_ShipNameAndType = PCharAndCompanions_shipnames[SelectedCompanionSlot-1] + GetShipTypeDisplayName(PCharAndCompanions_shiptypes[SelectedCompanionSlot-1]);
				EnableString("BSD_ShipStatus");
				tempstringa1 = LanguageConvertString(tmpLangFileID,"Currently in companion slot") + " " + SelectedCompanionSlot;
				if (SelectedCompanionSlot == 1) { tempstringa1 += " " + LanguageConvertString(tmpLangFileID,"(flagship slot)"); }
				GameInterface.strings.BSD_ShipStatus = tempstringa1;
				SetNodeUsing("SHIPSLOT1BACK",true);
				SetNodeUsing("SHIPSLOT2BACK",true);
				SetNodeUsing("SHIPSLOT3BACK",true);
				SetNodeUsing("SHIPSLOT4BACK",true);
				SetNodeUsing("RBSCS_CANCELBTN",true);
				EnableString("RBSCS");
				GameInterface.strings.RBSCS = LanguageConvertString(tmpLangFileID,"Choose a berthing slot at") + " " + FindTownName(GetPortName(SelectedPort)) + ":"; // KK

				tempstringa1 = "port" + SelectedPort;

				SetNodeUsing("SHIP1STATUSTXT",true);
				
				if(checkAttribute(PChar, "ShipBerthing." + tempstringa1 + ".slot1.status"))	tempnuma2 = PChar.ShipBerthing.(tempstringa1).slot1.status; //JA 9Dec06 get rid of errors in error logs
				else	tempnuma2 = -1;
				
				if (tempnuma2 > 0)
				{
					tempstringa3 = GetBerthingStatusName(tempnuma2,false);
					tempnuma1 = PChar.ShipBerthing.(tempstringa1).slot1.shiptype;
					SetFormatedText("SHIP1STATUSTXT",LanguageConvertString(tmpLangFileID,"Swap with") + " " + PChar.ShipBerthing.(tempstringa1).slot1.shipname + GetShipTypeDisplayName(tempnuma1) + ", " + tempstringa3);
					GetShipPic(tempnuma1);
					CreateImage("Ship1Pic",ReturnedShipPicGroup,ReturnedShipPic,30,230,70,270);
				}
				else
				{
					SetFormatedText("SHIP1STATUSTXT",LanguageConvertString(tmpLangFileID,"Berth ship in empty slot") + " 1");
					CreateImage("Ship1Pic","BLANK_SHIP","Not Used",30,230,70,270);
				}

				SetNodeUsing("SHIP2STATUSTXT",true);
				if(checkAttribute(PChar, "ShipBerthing." + tempstringa1  + ".slot2.status"))	tempnuma2 = PChar.ShipBerthing.(tempstringa1).slot2.status; //JA 9Dec06 get rid of errors in error logs
				else	tempnuma2 = -1;
				if (tempnuma2 > 0)
				{
					tempstringa3 = GetBerthingStatusName(tempnuma2,false);
					tempnuma1 = PChar.ShipBerthing.(tempstringa1).slot2.shiptype;
					SetFormatedText("SHIP2STATUSTXT",LanguageConvertString(tmpLangFileID,"Swap with") + " " + PChar.ShipBerthing.(tempstringa1).slot2.shipname + GetShipTypeDisplayName(tempnuma1) + ", " + tempstringa3);
					GetShipPic(tempnuma1);
					CreateImage("Ship2Pic",ReturnedShipPicGroup,ReturnedShipPic,30,280,70,320);
				}
				else
				{
					SetFormatedText("SHIP2STATUSTXT",LanguageConvertString(tmpLangFileID,"Berth ship in empty slot") + " 2");
					CreateImage("Ship2Pic","BLANK_SHIP","Not Used",30,280,70,320);
				}

				SetNodeUsing("SHIP3STATUSTXT",true);
				if(checkAttribute(PChar, "ShipBerthing." + tempstringa1  + ".slot3.status"))	tempnuma2 = PChar.ShipBerthing.(tempstringa1).slot3.status; //JA 9Dec06 get rid of errors in error logs
				else	tempnuma2 = -1;
				if (tempnuma2 > 0)
				{
					tempstringa3 = GetBerthingStatusName(tempnuma2,false);
					tempnuma1 = PChar.ShipBerthing.(tempstringa1).slot3.shiptype;
					SetFormatedText("SHIP3STATUSTXT",LanguageConvertString(tmpLangFileID,"Swap with") + " " + PChar.ShipBerthing.(tempstringa1).slot3.shipname + GetShipTypeDisplayName(tempnuma1) + ", " + tempstringa3);
					GetShipPic(tempnuma1);
					CreateImage("Ship3Pic",ReturnedShipPicGroup,ReturnedShipPic,30,330,70,370);
				}
				else
				{
					SetFormatedText("SHIP3STATUSTXT",LanguageConvertString(tmpLangFileID,"Berth ship in empty slot") + " 3");
					CreateImage("Ship3Pic","BLANK_SHIP","Not Used",30,330,70,370);
				}

				SetNodeUsing("SHIP4STATUSTXT",true);
				if(checkAttribute(PChar, "ShipBerthing." + tempstringa1  + ".slot4.status"))	tempnuma2 = PChar.ShipBerthing.(tempstringa1).slot4.status; //JA 9Dec06 get rid of errors in error logs
				else	tempnuma2 = -1;
				if (tempnuma2 > 0)
				{
					tempstringa3 = GetBerthingStatusName(tempnuma2,false);
					tempnuma1 = PChar.ShipBerthing.(tempstringa1).slot4.shiptype;
					SetFormatedText("SHIP4STATUSTXT",LanguageConvertString(tmpLangFileID,"Swap with") + " " + PChar.ShipBerthing.(tempstringa1).slot4.shipname + GetShipTypeDisplayName(tempnuma1) + ", " + tempstringa3);
					GetShipPic(tempnuma1);
					CreateImage("Ship4Pic",ReturnedShipPicGroup,ReturnedShipPic,30,380,70,420);
				}
				else
				{
					SetFormatedText("SHIP4STATUSTXT",LanguageConvertString(tmpLangFileID,"Berth ship in empty slot") + " 4");
					CreateImage("Ship4Pic","BLANK_SHIP","Not Used",30,380,70,420);
				}
				SetCurrentNode("RBSCS_CANCELBTN");
			}
		break;



		case "Final Details":
			if (Showbool == false)
			{
				SetNodeUsing("BSD_RECTANGLE",false);
				SetNodeUsing("BSD_BOUND",false);
				SetNodeUsing("BSD_SHIPPIC",false);
				GameInterface.pictures.BigShipPic.pic = -1;
				GameInterface.pictures.BigShipPic.tex = -1;
				SetNodeUsing("FD_TOPLEFT_SHIPNAME",false);
				SetNodeUsing("FD_TOPLEFT_OLDSTATUS",false);
				SetNodeUsing("FD_TOPLEFT_NEWSTATUS",false);
				SetNodeUsing("FD_TOPLEFT_OLDCAPTAIN",false);
				SetNodeUsing("FD_TOPLEFT_NEWCAPTAIN",false);
				SetNodeUsing("FD_BTMRIGHT_SHIPNAME",false);
				SetNodeUsing("FD_BTMRIGHT_OLDSTATUS",false);
				SetNodeUsing("FD_BTMRIGHT_NEWSTATUS",false);
				SetNodeUsing("FD_BTMRIGHT_OLDCAPTAIN",false);
				SetNodeUsing("FD_BTMRIGHT_NEWCAPTAIN",false);
				SetNodeUsing("FD_BTMRGHTSHIPPIC",false);
				GameInterface.pictures.FD_BtmRightShipPic.pic = -1;
				GameInterface.pictures.FD_BtmRightShipPic.tex = -1;
				SetNodeUsing("FD_OKBTN",false);
				SetNodeUsing("FD_CANCELBTN",false);
				SetNodeUsing("FD_LINES",false);
				SetNodeUsing("FD_CHOOSETLCAPTAINBTN",false);
				SetNodeUsing("FD_CHANGEBERTHINGMETHODBTN",false);
				SetNodeUsing("FD_CHOOSEBRCAPTAINBTN",false);
			}
			else
			{
				LaunchFDWindow();
			}
		break;



		case "Choose a Captain":
			if (Showbool == false)
			{
				SetNodeUsing("BSD_RECTANGLE",false);
				SetNodeUsing("BSD_BOUND",false);
				SetNodeUsing("CC_LEFTSCROLLBUTTON",false);
				SetNodeUsing("CC_RIGHTSCROLLBUTTON",false);
				SetNodeUsing("CC_IMAGES",false);
				SetNodeUsing("CC_STRINGS",false);
				GameInterface.pictures.Mugshot.pic = -1;
				GameInterface.pictures.Mugshot.tex = -1;
				SetNodeUsing("FD_OKBTN",false);
				SetNodeUsing("FD_CANCELBTN",false);
				DisableString("CC_Name");
				SetNodeUsing("CC_CURRENTSTATUSTXT",false);
				SetNodeUsing("CC_CHOOSINGTXT",false);
				DisableString("CC_skillLeadership");
				DisableString("CC_skillFencing");
				DisableString("CC_skillSailing");
				DisableString("CC_skillAccuracy");
				DisableString("CC_skillCannons");
				DisableString("CC_skillGrappling");
				DisableString("CC_skillRepair");
				DisableString("CC_skillDefence");
				DisableString("CC_skillCommerce");
				DisableString("CC_skillSneak");
			}
			else
			{
				tempstringa1 = "port" + SelectedPort;
				tempstringa2 = "slot" + SelectedBerthingSlot;

				SetNodeUsing("TOWN_CHANGER", 0);  // Screwface
				SetNodeUsing("BSD_RECTANGLE",true);
				SetNodeUsing("BSD_BOUND",true);
				SetNodeUsing("CC_LEFTSCROLLBUTTON",true);
				SetNodeUsing("CC_RIGHTSCROLLBUTTON",true);
				SetNodeUsing("CC_IMAGES",true);
				SetNodeUsing("CC_STRINGS",true);
				SetNodeUsing("FD_OKBTN",true);
				SetSelectable("FD_OKBTN",true);
				SetNodeUsing("FD_CANCELBTN",true);
				EnableString("CC_Name");
				SetNodeUsing("CC_CURRENTSTATUSTXT",true);
				SetNodeUsing("CC_CHOOSINGTXT",true);
				EnableString("CC_skillLeadership");
				EnableString("CC_skillFencing");
				EnableString("CC_skillSailing");
				EnableString("CC_skillAccuracy");
				EnableString("CC_skillCannons");
				EnableString("CC_skillGrappling");
				EnableString("CC_skillRepair");
				EnableString("CC_skillDefence");
				EnableString("CC_skillCommerce");
				EnableString("CC_skillSneak");

				if (ChoosingCaptain == 1)
				{
					SetFormatedText("CC_CHOOSINGTXT",LanguageConvertString(tmpLangFileID,"Choosing captain for ship being relaunched, the") + " " + PChar.ShipBerthing.(tempstringa1).(tempstringa2).shipname + ".");
				}
				else
				{
					SetFormatedText("CC_CHOOSINGTXT",LanguageConvertString(tmpLangFileID,"Choosing captain for ship going on shore leave, the") + " " + PCharAndCompanions_ShipNames[SelectedCompanionSlot-1] + ".");
				}

				SetCurrentNode("FD_CANCELBTN");
				FillCaptainsList();
				UpdateCCDisplay();
			}
		break;



		case "Final Confirmation":
			if (Showbool == false)
			{
				SetNodeUsing("BSD_RECTANGLE",false);
				SetNodeUsing("BSD_BOUND",false);
				SetNodeUsing("FD_OKBTN",false);
				SetNodeUsing("FC_CANCELBTN",false);
				SetNodeUsing("FC_TEXT",false);
				DisableString("FC_TITLE");
			}
			else
			{
				SetNodeUsing("TOWN_CHANGER", 0);  // Screwface
				SetNodeUsing("BSD_RECTANGLE",true);
				SetNodeUsing("BSD_BOUND",true);
				SetNodeUsing("FD_OKBTN",true);
				SetSelectable("FD_OKBTN",true);
				SetNodeUsing("FC_CANCELBTN",true);
				SetNodeUsing("FC_TEXT",true);
				EnableString("FC_Title");
				SetCurrentNode("FD_OKBTN");
			}
		break;
	}
}



// --> Swindler 2005-10-12: corrected syntax error
//void LaunchFDWindow();
void LaunchFDWindow()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	string tempstringb1;
	string tempstringb2;
	string tempstringb3;
	int tempnumb1;
	int tempnumb2;

	SetNodeUsing("BSD_RECTANGLE",true);
	SetNodeUsing("BSD_BOUND",true);
	SetNodeUsing("BSD_SHIPPIC",true);
	SetNodeUsing("FD_BTMRGHTSHIPPIC",true);
	SetNodeUsing("FD_OKBTN",true);
	SetNodeUsing("FD_CANCELBTN",true);
	SetNodeUsing("FD_CHOOSETLCAPTAINBTN",true);
	SetNodeUsing("FD_CHANGEBERTHINGMETHODBTN",true);
	SetNodeUsing("FD_CHOOSEBRCAPTAINBTN",true);
	SetNodeUsing("FD_LINES",true);

	tempstringb1 = "port" + SelectedPort;
	tempstringb2 = "slot" + SelectedBerthingSlot;

	if (ChoosingCaptain == 0)
	{
		BerthingMethod = 0;
		RelaunchingShipCaptain = -1;
		BerthingShipCaptain = -1;
	}

	if (SwapMethod == 0)
	{
		if (SelectedCompanionSlot == 1)
		{
			tempnumb1 = PChar.ShipBerthing.(tempstringb1).(tempstringb2).shiptype;
			GetShipPic(tempnumb1);
			CreateImage("BigShipPic",ReturnedShipPicGroup,ReturnedShipPic,30,65,130,165);

			SetNodeUsing("FD_TOPLEFT_SHIPNAME",true);
			SetFormatedText("FD_TOPLEFT_SHIPNAME",PChar.ShipBerthing.(tempstringb1).(tempstringb2).shipname + GetShipTypeDisplayName(tempnumb1));

			SetNodeUsing("FD_TOPLEFT_OLDSTATUS",true);
			tempnumb2 = PChar.ShipBerthing.(tempstringb1).(tempstringb2).status;
			tempstringb3 = GetBerthingStatusName(tempnumb2,false);
			SetFormatedText("FD_TOPLEFT_OLDSTATUS",LanguageConvertString(tmpLangFileID,"Ship is currently") + " " + tempstringb3 + " " + LanguageConvertString(tmpLangFileID,"at") + " " + FindTownName(GetPortName(SelectedPort))); // KK

			SetNodeUsing("FD_TOPLEFT_NEWSTATUS",true);
			SetFormatedText("FD_TOPLEFT_NEWSTATUS",LanguageConvertString(tmpLangFileID,"Ship is to be RELAUNCHED into companion slot") + " 1 " + LanguageConvertString(tmpLangFileID,"(flagship slot)"));

			SetNodeUsing("FD_TOPLEFT_OLDCAPTAIN",true);
			if (PChar.ShipBerthing.(tempstringb1).(tempstringb2).status == 2)
			{
				tempnumb2 = PChar.ShipBerthing.(tempstringb1).(tempstringb2).captainindex;
				SetFormatedText("FD_TOPLEFT_OLDCAPTAIN",LanguageConvertString(tmpLangFileID,"Current captain") + ": " + GetCaptainNameFromIndex(tempnumb2));
			}
			else
			{
				SetFormatedText("FD_TOPLEFT_OLDCAPTAIN",LanguageConvertString(tmpLangFileID,"Current captain") + ": -");
			}

			SetNodeUsing("FD_TOPLEFT_NEWCAPTAIN",true);
			if (ChoosingCaptain == 0) { RelaunchingShipCaptain = PCharAndCompanions_Indexes[0]; }



			CreateImage("FD_BtmRightShipPic",PCharAndCompanions_ShipPicGroups[0],PCharAndCompanions_ShipPics[0],510,225,610,325);

			SetNodeUsing("FD_BTMRIGHT_SHIPNAME",true);
			SetFormatedText("FD_BTMRIGHT_SHIPNAME",PCharAndCompanions_ShipNames[0] + GetShipTypeDisplayName(PCharAndCompanions_ShipTypes[0]));

			SetNodeUsing("FD_BTMRIGHT_OLDSTATUS",true);
			SetFormatedText("FD_BTMRIGHT_OLDSTATUS",LanguageConvertString(tmpLangFileID,"Ship is currently in companion slot") + " 1 " + LanguageConvertString(tmpLangFileID,"(flagship slot)"));

			SetNodeUsing("FD_BTMRIGHT_NEWSTATUS",true);

			SetNodeUsing("FD_BTMRIGHT_OLDCAPTAIN",true);
			SetFormatedText("FD_BTMRIGHT_OLDCAPTAIN",LanguageConvertString(tmpLangFileID,"Current captain") + ": " + PCharAndCompanions_Names[0]);

			SetNodeUsing("FD_BTMRIGHT_NEWCAPTAIN",true);
			if (ChoosingCaptain == 0)
			{
				if (PChar.ShipBerthing.(tempstringb1).(tempstringb2).status == 2)
				{
					tempnumb2 = PChar.ShipBerthing.(tempstringb1).(tempstringb2).captainindex;
					BerthingShipCaptain = PChar.ShipBerthing.(tempstringb1).(tempstringb2).captainindex;
				}
				else
				{
					BerthingShipCaptain = -1;
				}
			}

		}
		else
		{

			tempnumb1 = PChar.ShipBerthing.(tempstringb1).(tempstringb2).shiptype;
			GetShipPic(tempnumb1);
			CreateImage("BigShipPic",ReturnedShipPicGroup,ReturnedShipPic,30,65,130,165);

			SetNodeUsing("FD_TOPLEFT_SHIPNAME",true);
			SetFormatedText("FD_TOPLEFT_SHIPNAME",PChar.ShipBerthing.(tempstringb1).(tempstringb2).shipname + GetShipTypeDisplayName(tempnumb1));

			SetNodeUsing("FD_TOPLEFT_OLDSTATUS",true);
			tempnumb2 = PChar.ShipBerthing.(tempstringb1).(tempstringb2).status;
			tempstringb3 = GetBerthingStatusName(tempnumb2,false);
			SetFormatedText("FD_TOPLEFT_OLDSTATUS",LanguageConvertString(tmpLangFileID,"Ship is currently") + " " + tempstringb3 + " " + LanguageConvertString(tmpLangFileID,"at") + " " + FindTownName(GetPortName(SelectedPort))); // KK

			SetNodeUsing("FD_TOPLEFT_NEWSTATUS",true);
			SetFormatedText("FD_TOPLEFT_NEWSTATUS",LanguageConvertString(tmpLangFileID,"Ship is to be RELAUNCHED into companion slot") + " " + SelectedCompanionSlot);

			SetNodeUsing("FD_TOPLEFT_OLDCAPTAIN",true);
			SetNodeUsing("FD_TOPLEFT_NEWCAPTAIN",true);
			if (PChar.ShipBerthing.(tempstringb1).(tempstringb2).status == 2)
			{
				tempnumb2 = PChar.ShipBerthing.(tempstringb1).(tempstringb2).captainindex;
				SetFormatedText("FD_TOPLEFT_OLDCAPTAIN",LanguageConvertString(tmpLangFileID,"Current captain") + ": " + GetCaptainNameFromIndex(tempnumb2));
				if (ChoosingCaptain == 0) { RelaunchingShipCaptain = PChar.ShipBerthing.(tempstringb1).(tempstringb2).captainindex; }
			}
			else
			{
				SetFormatedText("FD_TOPLEFT_OLDCAPTAIN",LanguageConvertString(tmpLangFileID,"Current captain") + ": -");
				if (ChoosingCaptain == 0) { RelaunchingShipCaptain = -1; }
			}



			CreateImage("FD_BtmRightShipPic",PCharAndCompanions_ShipPicGroups[SelectedCompanionSlot-1],PCharAndCompanions_ShipPics[SelectedCompanionSlot-1],510,225,610,325);

			SetNodeUsing("FD_BTMRIGHT_SHIPNAME",true);
			SetFormatedText("FD_BTMRIGHT_SHIPNAME",PCharAndCompanions_ShipNames[SelectedCompanionSlot-1] + GetShipTypeDisplayName(PCharAndCompanions_ShipTypes[SelectedCompanionSlot-1]));

			SetNodeUsing("FD_BTMRIGHT_OLDSTATUS",true);
			SetFormatedText("FD_BTMRIGHT_OLDSTATUS",LanguageConvertString(tmpLangFileID,"Ship is currently in companion slot") + " " + SelectedCompanionSlot);

			SetNodeUsing("FD_BTMRIGHT_NEWSTATUS",true);

			SetNodeUsing("FD_BTMRIGHT_OLDCAPTAIN",true);
			SetFormatedText("FD_BTMRIGHT_OLDCAPTAIN",LanguageConvertString(tmpLangFileID,"Current captain") + ": " + PCharAndCompanions_Names[SelectedCompanionSlot-1]);

			SetNodeUsing("FD_BTMRIGHT_NEWCAPTAIN",true);
			if (ChoosingCaptain == 0) { BerthingShipCaptain = PCharAndCompanions_indexes[SelectedCompanionSlot-1]; }

		}

	}



	if (SwapMethod == 1)
	{
		if (SelectedCompanionSlot == 1)
		{
			tempnumb1 = PChar.ShipBerthing.(tempstringb1).(tempstringb2).shiptype;
			GetShipPic(tempnumb1);
			CreateImage("BigShipPic",ReturnedShipPicGroup,ReturnedShipPic,30,65,130,165);

			SetNodeUsing("FD_TOPLEFT_SHIPNAME",true);
			SetFormatedText("FD_TOPLEFT_SHIPNAME",PChar.ShipBerthing.(tempstringb1).(tempstringb2).shipname + GetShipTypeDisplayName(tempnumb1));

			SetNodeUsing("FD_TOPLEFT_OLDSTATUS",true);
			tempnumb2 = PChar.ShipBerthing.(tempstringb1).(tempstringb2).status;
			tempstringb3 = GetBerthingStatusName(tempnumb2,false);
			SetFormatedText("FD_TOPLEFT_OLDSTATUS",LanguageConvertString(tmpLangFileID,"Ship is currently") + " " + tempstringb3 + " " + LanguageConvertString(tmpLangFileID,"at") + " " + FindTownName(GetPortName(SelectedPort))); // KK

			SetNodeUsing("FD_TOPLEFT_NEWSTATUS",true);
			SetFormatedText("FD_TOPLEFT_NEWSTATUS",LanguageConvertString(tmpLangFileID,"Ship is to be RELAUNCHED into companion slot") + " 1 " + LanguageConvertString(tmpLangFileID,"(flagship slot)"));

			SetNodeUsing("FD_TOPLEFT_OLDCAPTAIN",true);
			if (PChar.ShipBerthing.(tempstringb1).(tempstringb2).status == 2)
			{
				tempnumb2 = PChar.ShipBerthing.(tempstringb1).(tempstringb2).captainindex;
				SetFormatedText("FD_TOPLEFT_OLDCAPTAIN",LanguageConvertString(tmpLangFileID,"Current captain") + ": " + GetCaptainNameFromIndex(tempnumb2));
			}
			else
			{
				SetFormatedText("FD_TOPLEFT_OLDCAPTAIN",LanguageConvertString(tmpLangFileID,"Current captain") + ": -");
			}

			SetNodeUsing("FD_TOPLEFT_NEWCAPTAIN",true);
			if (ChoosingCaptain == 0) { RelaunchingShipCaptain = PCharAndCompanions_indexes[0]; }



			CreateImage("FD_BtmRightShipPic","BLANK_SHIP","Not Used",510,225,610,325);

			SetNodeUsing("FD_BTMRIGHT_SHIPNAME",true);
			SetFormatedText("FD_BTMRIGHT_SHIPNAME",LanguageConvertString(tmpLangFileID,"empty companion slot") + " 1 " + LanguageConvertString(tmpLangFileID,"(flagship slot)"));

			if (ChoosingCaptain == 0) { BerthingShipCaptain = -1; }

		}
		else
		{

			tempnumb1 = PChar.ShipBerthing.(tempstringb1).(tempstringb2).shiptype;
			GetShipPic(tempnumb1);
			CreateImage("BigShipPic",ReturnedShipPicGroup,ReturnedShipPic,30,65,130,165);

			SetNodeUsing("FD_TOPLEFT_SHIPNAME",true);
			SetFormatedText("FD_TOPLEFT_SHIPNAME",PChar.ShipBerthing.(tempstringb1).(tempstringb2).shipname + GetShipTypeDisplayName(tempnumb1));

			SetNodeUsing("FD_TOPLEFT_OLDSTATUS",true);
			tempnumb2 = PChar.ShipBerthing.(tempstringb1).(tempstringb2).status;
			tempstringb3 = GetBerthingStatusName(tempnumb2,false);
			SetFormatedText("FD_TOPLEFT_OLDSTATUS",LanguageConvertString(tmpLangFileID,"Ship is currently") + " " + tempstringb3 + " " + LanguageConvertString(tmpLangFileID,"at") + " " + FindTownName(GetPortName(SelectedPort))); // KK

			SetNodeUsing("FD_TOPLEFT_NEWSTATUS",true);
			SetFormatedText("FD_TOPLEFT_NEWSTATUS",LanguageConvertString(tmpLangFileID,"Ship is to be RELAUNCHED into companion slot") + " " + SelectedCompanionSlot);

			SetNodeUsing("FD_TOPLEFT_OLDCAPTAIN",true);
			SetNodeUsing("FD_TOPLEFT_NEWCAPTAIN",true);
			if (PChar.ShipBerthing.(tempstringb1).(tempstringb2).status == 2)
			{
				tempnumb2 = PChar.ShipBerthing.(tempstringb1).(tempstringb2).captainindex;
				SetFormatedText("FD_TOPLEFT_OLDCAPTAIN",LanguageConvertString(tmpLangFileID,"Current captain") + ": " + GetCaptainNameFromIndex(tempnumb2));
				if (ChoosingCaptain == 0) { RelaunchingShipCaptain = PChar.ShipBerthing.(tempstringb1).(tempstringb2).captainindex; }
			}
			else
			{
				SetFormatedText("FD_TOPLEFT_OLDCAPTAIN",LanguageConvertString(tmpLangFileID,"Current captain") + ": -");
				if (ChoosingCaptain == 0) { RelaunchingShipCaptain = -1; }
			}



			CreateImage("FD_BtmRightShipPic","BLANK_SHIP","Not Used",510,225,610,325);

			SetNodeUsing("FD_BTMRIGHT_SHIPNAME",true);
			SetFormatedText("FD_BTMRIGHT_SHIPNAME",LanguageConvertString(tmpLangFileID,"empty companion slot") + " " + SelectedCompanionSlot);

			if (ChoosingCaptain == 0) { BerthingShipCaptain = -1; }

		}

	}



	if (SwapMethod == 2)
	{
		if (SelectedCompanionSlot == 1)
		{
			CreateImage("BigShipPic","BLANK_SHIP","Not Used",30,65,130,165);

			SetNodeUsing("FD_TOPLEFT_SHIPNAME",true);
			SetFormatedText("FD_TOPLEFT_SHIPNAME",LanguageConvertString(tmpLangFileID,"empty berthing slot") + " " + SelectedBerthingSlot + " " + LanguageConvertString(tmpLangFileID,"at") + " " + FindTownName(GetPortName(SelectedPort))); // KK

			if (ChoosingCaptain == 0) { RelaunchingShipCaptain = -1; }



			SetNodeUsing("FD_BTMRGHTSHIPPIC",true);
			CreateImage("FD_BtmRightShipPic",PCharAndCompanions_ShipPicGroups[0],PCharAndCompanions_ShipPics[0],510,225,610,325);

			SetNodeUsing("FD_BTMRIGHT_SHIPNAME",true);
			SetFormatedText("FD_BTMRIGHT_SHIPNAME",PCharAndCompanions_ShipNames[0] + GetShipTypeDisplayName(PCharAndCompanions_ShipTypes[0]));

			SetNodeUsing("FD_BTMRIGHT_OLDSTATUS",true);
			SetFormatedText("FD_BTMRIGHT_OLDSTATUS",LanguageConvertString(tmpLangFileID,"Ship is currently in companion slot") + " 1 " + LanguageConvertString(tmpLangFileID,"(flagship slot)"));

			SetNodeUsing("FD_BTMRIGHT_NEWSTATUS",true);

			SetNodeUsing("FD_BTMRIGHT_OLDCAPTAIN",true);
			SetFormatedText("FD_BTMRIGHT_OLDCAPTAIN",LanguageConvertString(tmpLangFileID,"Current captain") + ": " + PCharAndCompanions_Names[0]);

			SetNodeUsing("FD_BTMRIGHT_NEWCAPTAIN",true);
			if (ChoosingCaptain == 0) { BerthingShipCaptain = -1; }

		}
		else
		{

			CreateImage("BigShipPic","BLANK_SHIP","Not Used",30,65,130,165);

			SetNodeUsing("FD_TOPLEFT_SHIPNAME",true);
			SetFormatedText("FD_TOPLEFT_SHIPNAME",LanguageConvertString(tmpLangFileID,"empty berthing slot" ) + " " + SelectedBerthingSlot + " " + LanguageConvertString(tmpLangFileID,"at") + " " + FindTownName(GetPortName(SelectedPort))); // KK

			if (ChoosingCaptain == 0) { RelaunchingShipCaptain = -1; }



			CreateImage("FD_BtmRightShipPic",PCharAndCompanions_ShipPicGroups[SelectedCompanionSlot-1],PCharAndCompanions_ShipPics[SelectedCompanionSlot-1],510,225,610,325);

			SetNodeUsing("FD_BTMRIGHT_SHIPNAME",true);
			SetFormatedText("FD_BTMRIGHT_SHIPNAME",PCharAndCompanions_ShipNames[SelectedCompanionSlot-1] + GetShipTypeDisplayName(PCharAndCompanions_ShipTypes[SelectedCompanionSlot-1]));

			SetNodeUsing("FD_BTMRIGHT_OLDSTATUS",true);
			SetFormatedText("FD_BTMRIGHT_OLDSTATUS",LanguageConvertString(tmpLangFileID,"Ship is currently in companion slot") + " " + SelectedCompanionSlot);

			SetNodeUsing("FD_BTMRIGHT_NEWSTATUS",true);

			SetNodeUsing("FD_BTMRIGHT_OLDCAPTAIN",true);
			SetFormatedText("FD_BTMRIGHT_OLDCAPTAIN",LanguageConvertString(tmpLangFileID,"Current captain") + ": " + PCharAndCompanions_Names[SelectedCompanionSlot-1]);

			SetNodeUsing("FD_BTMRIGHT_NEWCAPTAIN",true);
			if (ChoosingCaptain == 0) { BerthingShipCaptain = PCharAndCompanions_indexes[SelectedCompanionSlot-1]; }

		}

	}



	SetCurrentNode("FD_CANCELBTN");
	ChoosingCaptain = 0;
	UpdateFDDisplay();
}




void ConfirmationWindow(string WhichWindow)
{
	string gPortAttrib;
	string gSlotAttrib;
	string tempstringg1;
	string tempstringg2;
	string tempstringg3;
	int tempnumg1;
	int tempnumg2;
	int tempnumg3;
	int tempnumg4;
	ref gCaptainChar;

	gPortAttrib = "port" + SelectedPort;
	gSlotAttrib = "slot" + SelectedBerthingSlot;

	ChangeWindow("Final Confirmation");
	FCControlsID = WhichWindow;
	switch(WhichWindow)
	{
		case "Ship Berthing":
			switch(SwapMethod)
			{
				case 0:

					tempstringg2 = PChar.ShipBerthing.(gPortAttrib).(gSlotAttrib).shipname;
					tempstringg3 = PCharAndCompanions_ShipNames[SelectedCompanionSlot-1];
					tempnumg1 = PCharAndCompanions_ShipTypes[SelectedCompanionSlot-1];
					tempnumg2 = SBCalculateDailyCost(0,tempnumg1,SelectedPort) * 30;
					tempnumg3 = SBCalculateDailyCost(1,tempnumg1,SelectedPort) * 30;
					tempnumg4 = SBGetShoreLeavePay(BerthingShipCaptain, GetCrewQuantity(GetCharacter(PCharAndCompanions_Indexes[SelectedCompanionSlot-1])));
					GameInterface.strings.FC_Title = "Confirm - Swap Ships";
					if(BerthingMethod == 0)
					{
						tempnumg1 = PChar.ShipBerthing.(gPortAttrib).(gSlotAttrib).status;
						if (tempnumg1 == 2)
						{
							tempstringg1 = "You have selected to put the " + tempstringg3 + " (currently active) on shore leave, and relaunch the " + tempstringg2 + " (currently on shore leave). This action is completely reversible; nothing will be lost or stripped from either ship. Note however that berthing charges for the " + tempstringg3 + " will be high (" + tempnumg2 + " / month) and you will continue to have to pay the crew, captain and any officers that captain has, albeit at a reduced rate (" + tempnumg4 + " / month). Click OK to go ahead with this.";
						}
						else
						{
							tempstringg1 = "You have selected to put the " + tempstringg3 + " (currently active) on shore leave, and relaunch the " + tempstringg2 + " (currently laid up). If the " + tempstringg3 + " goes on shore leave, nothing will be lost or stripped from her, but note that berthing charges will be high (" + tempnumg2 + " / month) and you will continue to have to pay the crew, captain and any officers that captain has, albeit at a reduced rate (" + tempnumg4 + " / month). If the " + tempstringg2 + " is relaunched, you will have to replace, her rigging, her supplies and her crew. Click OK to go ahead with this.";
						}
					}
					else
					{
						tempstringg1 = "You have selected to lay up the " + tempstringg3 + " (currently active), and relaunch the " + tempstringg2 + " (currently on shore leave). If the " + tempstringg3 + " is laid up, she will be stripped of everything except her guns (this includes crew, rigging and upgrades - you will have to replace these when you relaunch the ship), and her captain will return to the passengers list. ";
						gCaptainChar = GetCharacter(PCharAndCompanions_Indexes[SelectedCompanionSlot-1]);
						if (GetCargoLoad(gCaptainChar) > 0)
						{
							tempnumg1 = SBGetGoodsPrice(PCharAndCompanions_Indexes[SelectedCompanionSlot-1],SelectedPort);
							tempstringg1 += "You will receive " + tempnumg1 + " for the value of the cargo in the hold at local prices. ";
						}
						tempstringg1 += "You will no longer have to pay the crew, and the berthing charge will be low (" + tempnumg3 + " / month). ";
						tempnumg1 = PChar.ShipBerthing.(gPortAttrib).(gSlotAttrib).status;
						if (tempnumg1 == 1)
						{
							tempstringg1 += "If the " + tempstringg2 + " is relaunched, you will have to replace, her rigging, her supplies and her crew. ";
						}
						tempstringg1 += "Click OK to go ahead with this.";
					}
				break;
				case 1:
					GameInterface.strings.FC_Title = "Confirm - Relaunch Ship";
					tempstringg2 = PChar.ShipBerthing.(gPortAttrib).(gSlotAttrib).shipname;
					tempstringg1 = "Click OK to confirm that you want to relaunch the " + tempstringg2 + ".";
					tempnumg1 = PChar.ShipBerthing.(gPortAttrib).(gSlotAttrib).status;
					if (tempnumg1 == 1)
					{
						tempstringg1 += " You will have to replace, her rigging, her supplies and her crew.";
					}
				break;
				case 2:
					GameInterface.strings.FC_Title = "Confirm - Berth Ship";
					tempnumg1 = PCharAndCompanions_ShipTypes[SelectedCompanionSlot-1];
					tempnumg2 = SBCalculateDailyCost(0,tempnumg1,SelectedPort) * 30;
					tempnumg3 = SBCalculateDailyCost(1,tempnumg1,SelectedPort) * 30;
					tempnumg4 = SBGetShoreLeavePay(BerthingShipCaptain, GetCrewQuantity(GetCharacter(PCharAndCompanions_Indexes[SelectedCompanionSlot-1])));
					tempstringg3 = PCharAndCompanions_ShipNames[SelectedCompanionSlot-1];
					if(BerthingMethod == 0)
					{
						tempstringg1 = "You have selected to put the " + tempstringg3 + " (currently active) on shore leave. This action is completely reversible; nothing will be lost or stripped from her. Note however that berthing charges will be high (" + tempnumg2 + " / month) and you will continue to have to pay the crew, captain and any officers that captain has, albeit at a reduced rate (" + tempnumg4 + " / month). Click OK to go ahead with this.";
					}
					else
					{
						tempstringg1 = "You have selected to lay up the " + tempstringg3 + " (currently active). She will be stripped of everything except her guns (this includes crew, rigging and upgrades - you will have to replace these when you relaunch the ship), and her captain will return to the passengers list. ";
						gCaptainChar = GetCharacter(PCharAndCompanions_Indexes[SelectedCompanionSlot-1]);
						if (GetCargoLoad(gCaptainChar) > 0)
						{
							tempnumg1 = SBGetGoodsPrice(PCharAndCompanions_Indexes[SelectedCompanionSlot-1],SelectedPort);
							tempstringg1 += "You will receive " + tempnumg1 + " for the value of the cargo in the hold at local prices. ";
						}
						tempstringg1 += "You will no longer have to pay the crew, and the berthing charge will be low (" + tempnumg3 + " / month). Click OK to go ahead with this.";
					}
				break;
			}
			SetFormatedText("FC_TEXT",tempstringg1);
		break;



		case "Lay up ship on shore leave":
			GameInterface.strings.FC_Title = "Confirm - Lay Up Ship";
			tempstringg2 = PChar.ShipBerthing.(gPortAttrib).(gSlotAttrib).shipname;
			tempnumg1 = PChar.ShipBerthing.(gPortAttrib).(gSlotAttrib).shiptype;
			tempnumg2 = SBCalculateDailyCost(0,tempnumg1,SelectedPort) * 30;
			tempnumg3 = SBCalculateDailyCost(1,tempnumg1,SelectedPort) * 30;
			tempstringg1 = "Note that if you lay up the " + tempstringg2 + ", she will be stripped of everything except her guns (this includes crew, rigging and upgrades - you will have to replace these when you relaunch the ship), and her captain will return to the passengers list. ";
			gCaptainChar = GetCharacter(sti(PChar.ShipBerthing.(gPortAttrib).(gSlotAttrib).captainindex));
			if (GetCargoLoad(gCaptainChar) > 0)
			{
				tempnumg1 = SBGetGoodsPrice(sti(PChar.ShipBerthing.(gPortAttrib).(gSlotAttrib).captainindex),SelectedPort);
				tempstringg1 += "You will receive " + tempnumg1 + " for the value of the cargo in the hold at local prices. ";
			}
			tempstringg1 += "You will no longer have to pay the crew, and the monthly berthing charge will decrease from " + tempnumg2 + " to " + tempnumg3 + ". Click OK to go ahead with this.";
			SetFormatedText("FC_TEXT",tempstringg1);
		break;



		case "Scrap berthed ship":
			GameInterface.strings.FC_Title = "Confirm - Scrap Ship";
			tempstringg2 = PChar.ShipBerthing.(gPortAttrib).(gSlotAttrib).shipname;
			if (PChar.ShipBerthing.(gPortAttrib).(gSlotAttrib).status == 2)
			{
				tempstringg1 = "Click OK to confirm that you want to scrap the " + tempstringg2 + ". ";
				gCaptainChar = GetCharacter(sti(PChar.ShipBerthing.(gPortAttrib).(gSlotAttrib).captainindex));
				if (GetCargoLoad(gCaptainChar) > 0)
				{
					tempnumg1 = SBGetGoodsPrice(sti(PChar.ShipBerthing.(gPortAttrib).(gSlotAttrib).captainindex),SelectedPort);
					tempstringg1 += "You will receive " + tempnumg1 + " for the value of the cargo in the hold at local prices. ";
				}
				tempstringg1 += "The ship's captain will return to the passengers list.";
			}
			else
			{
				tempstringg1 = "Click OK to confirm that you want to Scrap the " + tempstringg2 + ".";
			}
			SetFormatedText("FC_TEXT",tempstringg1);
		break;
	}
}


