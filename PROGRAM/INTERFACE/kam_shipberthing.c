
/*
************************************************************************************************************
************************************************************************************************************

 the interface
 for the the all-new
 SHIP BERTHING SYSTEM!!!!!
 by Kieron (KAM)

************************************************************************************************************
************************************************************************************************************


the files kam_shipberthing.c (this one), kam_shipberthing_windows.c, kam_shipberthing_updatedisplay.c,
kam_shipberthing_miscfunctions.c and kam_shipberthing.ini make up the ship berthing *interface*, but do not
carry out any of the actual operations on the characters' ship data.

the actual ship-berthing function is in the file ..\kam_shipberthing_ship.c, which is #included from
..\seadogs.c.
*/





//************************************************************************************************************
//
// INCLUDES
//
//************************************************************************************************************


#include "interface\kam_shipberthing_windows.c"			// functions to do with changing windows in the interface
#include "interface\kam_shipberthing_updatedisplay.c"		// functions that update the changeable displays of the interface
#include "interface\kam_shipberthing_miscfunctions.c"		// other functions to do with the interface




//************************************************************************************************************
//
// VARIABLES
//
//************************************************************************************************************


// general
ref PChar;
int CurrentIslandNumber; // KK
int CurrentPortNumber;
string CurrentWindow;
int PCharAndCompanions_Indexes[4];
string PCharAndCompanions_Names[4];
string PCharAndCompanions_ShipNames[4];
int PCharAndCompanions_ShipTypes[4];
string PCharAndCompanions_ShipPics[4];
string PCharAndCompanions_ShipPicGroups[4];

// for base window
int nCurScroll;
int nCurTown = 0; // KK

// for selecting/viewing ships to swap/relaunch/berth (windows BSD, RBSCS, BSCSh, BSCSl, FD and CC)
bool BeganViaBS;		// true = cancelling FD window leads back to base window; false = cancelling FD window leads back to BSD window
int SelectedBerthingSlot;
int SelectedPort;
int SelectedCompanionSlot;
int SwapMethod;			// 0 = relaunch by swapping with an existing companion; 1 = relaunch into an empty companion slot; 2 = berth into an empty berthing slot
int BerthingMethod;		// 0 = shore leave; 1 = lay up
int RelaunchingShipCaptain;	// index of the captain-to-be of the relaunching ship; -1 means no captain is selected; -2 to be used where features are not yet implemented
int BerthingShipCaptain;	// index of the captain-to-be of the berthing ship
ref ORC, NRC, OBC, NBC;
aref arORCShip, arOBCShip, arNRCShip, arNBCShip;

// for choosing a captain (windows FD and CC)
int ChoosingCaptain = 0;	// 0 = not choosing a captain, entering FD window initialises selections; 1 = captain-choosing window is up for relaunching (TL) ship; 2 = captain-choosing window is up for berthing (BR) ship
int listnum;
int listcurrent;

// returns from function GetShipPic()
string ReturnedShipPic;
string ReturnedShipPicGroup;

// for confirmation window
string FCControlsID;

string tempstring3;
string tempstring4;
int tempnum1;

string LandLocation;



//************************************************************************************************************
//
// INITIALISATION
//
//************************************************************************************************************


void InitInterface(string iniName)
{
	PChar = GetMainCharacter();

	if (!CheckAttribute(PChar,"ShipBerthing"))
	{
		InitialiseShipBerthingData();
	}
	FillInfoArrays();
	CurrentIslandNumber = FindCurrentIsland();
	CurrentPortNumber = FindCurrentPort();
	nCurTown = CurrentPortNumber;

//	InitialiseShipBerthingData();	// for testing only! if this line is uncommented then the interface wipes clean the berthing record each time it is launched

	GameInterface.title = "titleKAMShipBerthing";

	CurrentWindow = "Base";
	FillScroll();
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();//MAXIMUS: standard exit-string for exit-button

	CreateString(true,"TownName","",FONT_NORMAL,COLOR_NORMAL,320,193,SCRIPT_ALIGN_CENTER,1.0); // KK
	CreateString(false,"NoBerthedShips","",FONT_NORMAL,COLOR_NORMAL,320,285,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"CantBerthShip","",FONT_NORMAL,COLOR_NORMAL,325,450,SCRIPT_ALIGN_CENTER,1.0); // Screwface
	CreateString(false,"Shipyard","",FONT_NORMAL,COLOR_NORMAL,320,462,SCRIPT_ALIGN_CENTER,1.0); // Screwface

	CreateString(false,"BSD_ShipNameAndType","",FONT_NORMAL,COLOR_NORMAL,150,68,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(false,"BSD_ShipStatus","",FONT_NORMAL,COLOR_NORMAL,150,98,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(false,"BSD_ShipCaptain","",FONT_NORMAL,COLOR_NORMAL,150,128,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(false,"BSD_Hull","",FONT_NORMAL,COLOR_NORMAL,30,185,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(false,"BSD_Rigging","",FONT_NORMAL,COLOR_NORMAL,30,215,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(false,"BSD_Crew","",FONT_NORMAL,COLOR_NORMAL,30,245,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(false,"BSD_DaysInBerth","Monthly Cost:",FONT_NORMAL,COLOR_NORMAL,300,185,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(false,"BSD_Guns","",FONT_NORMAL,COLOR_NORMAL,300,215,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(false,"BSD_Cargo","",FONT_NORMAL,COLOR_NORMAL,300,245,SCRIPT_ALIGN_LEFT,1.0);
//	CreateString(false,"BSD_Cost_Berthing","",FONT_NORMAL,COLOR_NORMAL,30,305,SCRIPT_ALIGN_LEFT,1.0);
//	CreateString(false,"BSD_Cost_BerthingNowDue","",FONT_SMALL,COLOR_NORMAL,60,335,SCRIPT_ALIGN_LEFT,1.0);
//	CreateString(false,"BSD_Cost_Crew","",FONT_NORMAL,COLOR_NORMAL,30,375,SCRIPT_ALIGN_LEFT,1.0);
//	CreateString(false,"BSD_Cost_CrewNowDue","",FONT_SMALL,COLOR_NORMAL,60,405,SCRIPT_ALIGN_LEFT,1.0);

	CreateString(false,"RBSCS","",FONT_NORMAL,COLOR_NORMAL,30,185,SCRIPT_ALIGN_LEFT,1.0);

	CreateString(false,"CC_Name","",FONT_NORMAL,COLOR_NORMAL,320,68,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(false,"CC_skillLeadership","",FONT_BOLD_NUMBERS,COLOR_NORMAL,130,242,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(false,"CC_skillFencing","",FONT_BOLD_NUMBERS,COLOR_NORMAL,130,276,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(false,"CC_skillSailing","",FONT_BOLD_NUMBERS,COLOR_NORMAL,130,310,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(false,"CC_skillAccuracy","",FONT_BOLD_NUMBERS,COLOR_NORMAL,130,344,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(false,"CC_skillCannons","",FONT_BOLD_NUMBERS,COLOR_NORMAL,130,378,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(false,"CC_skillGrappling","",FONT_BOLD_NUMBERS,COLOR_NORMAL,264,242,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(false,"CC_skillRepair","",FONT_BOLD_NUMBERS,COLOR_NORMAL,264,276,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(false,"CC_skillDefence","",FONT_BOLD_NUMBERS,COLOR_NORMAL,264,310,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(false,"CC_skillCommerce","",FONT_BOLD_NUMBERS,COLOR_NORMAL,264,344,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(false,"CC_skillSneak","",FONT_BOLD_NUMBERS,COLOR_NORMAL,264,378,SCRIPT_ALIGN_RIGHT,1.0);

	CreateString(false,"FC_Title","",FONT_NORMAL,COLOR_NORMAL,320,75,SCRIPT_ALIGN_CENTER,1.0);

	UpdateBaseDisplay();
	SetSelectable("EXIT_BUTTON",true);

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("frame","FrameProcess",1);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
// KK -->
	SetEventHandler("SelectPrevTown", "DoSelectPrevTown", 0);
	SetEventHandler("SelectNextTown", "DoSelectNextTown", 0);
// <-- KK
}




//************************************************************************************************************
//
// COMMAND RESPONSE FUNCTIONS
//
//************************************************************************************************************


void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	string tempstring1 = "port" + nCurTown; // Sulan
//	string tempstring1 = "port" + SelectedPort;
	string tempstring2 = "slot" + SelectedBerthingSlot;
//	string tempstring3;
//	string tempstring4;

//	int tempnum1;

	switch(Currentwindow)
	{
		case "Base":
			// Screwface
			if (NodName == "TOWN_CHANGER")
			{
				if (comName == "activate" || comName == "click")
				{
					DoSelectNextTown();
					SetCurrentNode("EXIT_BUTTON");
				}
			} // Screwface : end
			if (nodName == "BERTHASHIPHEREBTN")
			{
				if (comName == "activate" || comName == "click")
				{
					SelectedPort = CurrentPortNumber;
					ChangeWindow("Berth Ship - Choose Ship");
				    SetCurrentNode("EXIT_BUTTON");
				}
			}

			if (nodName == "CLOSEWINDOWBTN")
			{
				if (comName == "activate" || comName == "click")
				{
					ProcessCancelExit();
				    SetCurrentNode("EXIT_BUTTON");
				}
			}

			if (nodName == "SHIP1STATUSTXT" && comName == "click" && PChar.ShipBerthing.(tempstring1).slot1.status > 0)
			{
				SelectedBerthingSlot = 1;
				SelectedPort = nCurTown; // Sulan
				ChangeWindow("Berthed Ship Details");
				SetCurrentNode("EXIT_BUTTON");
			}

			if (nodName == "SHIP2STATUSTXT" && comName == "click" && PChar.ShipBerthing.(tempstring1).slot2.status > 0)
			{
				SelectedBerthingSlot = 2;
				SelectedPort = nCurTown; // Sulan
				ChangeWindow("Berthed Ship Details");
				SetCurrentNode("EXIT_BUTTON");
			}

			if (nodName == "SHIP3STATUSTXT" && comName == "click" && PChar.ShipBerthing.(tempstring1).slot3.status > 0)
			{
				SelectedBerthingSlot = 3;
				SelectedPort = nCurTown; // Sulan
				ChangeWindow("Berthed Ship Details");
				SetCurrentNode("EXIT_BUTTON");
			}

			if (nodName == "SHIP4STATUSTXT" && comName == "click" && PChar.ShipBerthing.(tempstring1).slot4.status > 0)
			{
				SelectedBerthingSlot = 4;
				SelectedPort = nCurTown; // Sulan
				ChangeWindow("Berthed Ship Details");
				SetCurrentNode("EXIT_BUTTON");
			}

		break;



		case "Berthed Ship Details":
			if (nodName == "BSD_CLOSEBTN")
			{
				if (comName == "activate" || comName == "click")
				{
					SelectedBerthingSlot = 1;
					SelectedPort = nCurTown; // Sulan
					ChangeWindow("Base");
				    SetCurrentNode("BERTHASHIPHEREBTN");
				}
			}

			if (nodName == "BSD_RELEASESHIPBTN")
			{
				if (comName == "activate" || comName == "click")
				{
					ChangeWindow("Relaunch Berthed Ship - Choose Slot");
				    SetCurrentNode("EXIT_BUTTON");
				}
			}

			if (nodName == "BSD_LAYUPSHIPBTN1")
			{
				if (comName == "activate" || comName == "click")
				{
					ConfirmationWindow("Scrap berthed ship");
				    SetCurrentNode("EXIT_BUTTON");
				}
			}

			if (nodName == "BSD_LAYUPSHIPBTN2")
			{
				if (comName == "activate" || comName == "click")
				{
					if (PChar.ShipBerthing.(tempstring1).(tempstring2).status == 2)
					{
						ConfirmationWindow("Lay up ship on shore leave");
					}
					else
					{
						ConfirmationWindow("Scrap berthed ship");
					}
				    SetCurrentNode("EXIT_BUTTON");
				}
			}

		break;



		case "Relaunch Berthed Ship - Choose Slot":
			if (nodName == "SHIP1STATUSTXT" && comName == "click")
			{
				SelectedCompanionSlot = 1;
				if (PCharAndCompanions_ShipTypes[0] != SHIP_NOTUSED)
				{
					SwapMethod = 0;
				}
				else
				{
					SwapMethod = 1;
				}
				ChangeWindow("Final Details");
				SetCurrentNode("EXIT_BUTTON");
			}

			if (nodName == "SHIP2STATUSTXT" && comName == "click")
			{
				// Screwface : If player has no ship, you can't relaunch a ship to a companion
				if (PCharAndCompanions_ShipTypes[0] != SHIP_NOTUSED)
				{
					if (GetRemovable(GetCharacter(PCharAndCompanions_Indexes[1])))
					{
						SelectedCompanionSlot = 2;
						if (PCharAndCompanions_ShipTypes[1] != SHIP_NOTUSED)
						{
							SwapMethod = 0;
						}
						else
						{
							SwapMethod = 1;
						}
						ChangeWindow("Final Details");
					    SetCurrentNode("EXIT_BUTTON");
					}
				}
				else
				{
					EnableString("CantBerthShip");
					GameInterface.strings.CantBerthShip = "You can't assign a ship to a companion if you have no ship !";
				}
			}

			if (nodName == "SHIP3STATUSTXT" && comName == "click")
			{
				// Screwface : If player has no ship, you can't relaunch a ship to a companion
				if (PCharAndCompanions_ShipTypes[0] != SHIP_NOTUSED)
				{
					if (GetRemovable(GetCharacter(PCharAndCompanions_Indexes[2])))
					{
						SelectedCompanionSlot = 3;
						if (PCharAndCompanions_ShipTypes[2] != SHIP_NOTUSED)
						{
							SwapMethod = 0;
						}
						else
						{
							SwapMethod = 1;
						}
						ChangeWindow("Final Details");
					    SetCurrentNode("EXIT_BUTTON");
					}
				}
				else
				{
					EnableString("CantBerthShip");
					GameInterface.strings.CantBerthShip = "You can't assign a ship to a companion if you have no ship !";
				}
			}

			if (nodName == "SHIP4STATUSTXT" && comName == "click")
			{
				// Screwface : If player has no ship, you can't relaunch a ship to a companion
				if (PCharAndCompanions_ShipTypes[0] != SHIP_NOTUSED)
				{
					if (GetRemovable(GetCharacter(PCharAndCompanions_Indexes[3])))
					{
						SelectedCompanionSlot = 4;
						if (PCharAndCompanions_ShipTypes[3] != SHIP_NOTUSED)
						{
							SwapMethod = 0;
						}
						else
						{
							SwapMethod = 1;
						}
						ChangeWindow("Final Details");
					    SetCurrentNode("EXIT_BUTTON");
					}
				}
				else
				{
					EnableString("CantBerthShip");
					GameInterface.strings.CantBerthShip = "You can't assign a ship to a companion if you have no ship !";
				}
			}

			if (nodName == "RBSCS_CANCELBTN")
			{
				if (comName == "activate" || comName == "click")
				{
					ChangeWindow("Berthed Ship Details");
				    SetCurrentNode("EXIT_BUTTON");
				}
			}

		break;


		case "Berth Ship - Choose Ship":

			if (nodName == "SHIP1STATUSTXT" && comName == "click")
			{
				// Screwface : you can berth your own ship only if you have not companions with ships
				If(PCharAndCompanions_ShipTypes[1] == SHIP_NOTUSED && PCharAndCompanions_ShipTypes[2] == SHIP_NOTUSED && PCharAndCompanions_ShipTypes[3] == SHIP_NOTUSED)
				{
					SelectedCompanionSlot = 1;
					ChangeWindow("Berth Ship - Choose Slot");
					SetCurrentNode("EXIT_BUTTON");
				}
				else
				{
					EnableString("CantBerthShip");
					GameInterface.strings.CantBerthShip = "You can't berth your own ship if your companions have ships !";
				}
			}

			if (nodName == "SHIP2STATUSTXT" && comName == "click")
			{
				if (GetRemovable(GetCharacter(PCharAndCompanions_Indexes[1])))
				{
					SelectedCompanionSlot = 2;
					ChangeWindow("Berth Ship - Choose Slot");
				}
				SetCurrentNode("EXIT_BUTTON");
			}

			if (nodName == "SHIP3STATUSTXT" && comName == "click")
			{
				if (GetRemovable(GetCharacter(PCharAndCompanions_Indexes[2])))
				{
					SelectedCompanionSlot = 3;
					ChangeWindow("Berth Ship - Choose Slot");
				}
				SetCurrentNode("EXIT_BUTTON");
			}

			if (nodName == "SHIP4STATUSTXT" && comName == "click")
			{
				if (GetRemovable(GetCharacter(PCharAndCompanions_Indexes[3])))
				{
					SelectedCompanionSlot = 4;
					ChangeWindow("Berth Ship - Choose Slot");
				}
				SetCurrentNode("EXIT_BUTTON");
			}

			if (nodName == "RBSCS_CANCELBTN")
			{
				if (comName == "activate" || comName == "click")
				{
					ChangeWindow("Base");
					SetCurrentNode("BERTHASHIPHEREBTN");
				}
			}
		break;



		case "Berth Ship - Choose Slot":
			bool bBerthShipSlot = false;
			if (nodName == "SHIP1STATUSTXT" && comName == "click")
			{
				SelectedBerthingSlot = 1;
				tempstring2 = "slot" + SelectedBerthingSlot;
				bBerthShipSlot = true;
			}

			if (nodName == "SHIP2STATUSTXT" && comName == "click")
			{
				SelectedBerthingSlot = 2;
				tempstring2 = "slot" + SelectedBerthingSlot;
				bBerthShipSlot = true;
			}

			if (nodName == "SHIP3STATUSTXT" && comName == "click")
			{
				SelectedBerthingSlot = 3;
				tempstring2 = "slot" + SelectedBerthingSlot;
				bBerthShipSlot = true;
			}

			if (nodName == "SHIP4STATUSTXT" && comName == "click")
			{
				SelectedBerthingSlot = 4;
				tempstring2 = "slot" + SelectedBerthingSlot;
				bBerthShipSlot = true;
			}

			if(bBerthShipSlot) //JA 9Dec06 Moved repeated code to this function:
			{
				if (checkAttribute(PChar, "ShipBerthing." + tempstring1  + "." + tempstring2 + ".status") && PChar.ShipBerthing.(tempstring1).(tempstring2).status > 0)
				{
					SwapMethod = 0;
					ChangeWindow("Final Details");
				}
				else
				{
					SwapMethod = 2;
					ChangeWindow("Final Details");
				}
				SetCurrentNode("EXIT_BUTTON");
			}

			if (nodName == "RBSCS_CANCELBTN")
			{
				if (comName == "activate" || comName == "click")
				{
					ChangeWindow("Berth Ship - Choose Ship");
					SetCurrentNode("EXIT_BUTTON");
				}
			}

		break;



		case "Final Details":

			if (nodName == "FD_CHOOSETLCAPTAINBTN")
			{
				if (comName == "activate" || comName == "click")
				{
					ChoosingCaptain = 1;
					ChangeWindow("Choose a Captain");
					SetCurrentNode("EXIT_BUTTON");
				}
			}

			if (nodName == "FD_CHOOSEBRCAPTAINBTN")
			{
				if (comName == "activate" || comName == "click")
				{
					ChoosingCaptain = 2;
					ChangeWindow("Choose a Captain");
					SetCurrentNode("EXIT_BUTTON");
				}
			}

			if (nodName == "FD_CHANGEBERTHINGMETHODBTN")
			{
				if (comName == "activate" || comName == "click")
				{
					BerthingMethod++;
					if (BerthingMethod == 2) { BerthingMethod = 0; }
					UpdateFDDisplay();
					SetCurrentNode("EXIT_BUTTON");
				}
			}

			if (nodName == "FD_CANCELBTN")
			{
				if (comName == "activate" || comName == "click")
				{
					if (BeganViaBS == true)
					{
						ChangeWindow("Berth Ship - Choose Slot");
					}
					else
					{
						ChangeWindow("Relaunch Berthed Ship - Choose Slot");
					}
					SetCurrentNode("EXIT_BUTTON");
				}
			}

			if (nodName == "FD_OKBTN")
			{
				if (comName == "activate" || comName == "click")
				{
					ChoosingCaptain = 1;
					ConfirmationWindow("Ship Berthing");
					SetCurrentNode("EXIT_BUTTON");
				}
			}

		break;



		case "Choose a Captain":

			if (nodName == "CC_LEFTSCROLLBUTTON")
			{
				if (comName == "activate" || comName == "click")
				{
					if (listnum > 0)
					{
						listcurrent--;
						if (listcurrent == 0) { listcurrent = listnum; }
						UpdateCCDisplay();
					}
					SetCurrentNode("EXIT_BUTTON");
				}
			}

			if (nodName == "CC_RIGHTSCROLLBUTTON")
			{
				if (comName == "activate" || comName == "click")
				{
					if (listnum > 0)
					{
						listcurrent++;
						if (listcurrent > listnum) { listcurrent = 1; }
						UpdateCCDisplay();
					}
					SetCurrentNode("EXIT_BUTTON");
				}
			}

			if (nodName == "FD_CANCELBTN")
			{
				if (comName == "activate" || comName == "click")
				{
					DeleteAttribute(PChar,"ShipBerthing.templist");
					ChangeWindow("Final Details");
					SetCurrentNode("EXIT_BUTTON");
				}
			}

			if (nodName == "FD_OKBTN")
			{
				if (comName == "activate" || comName == "click")
				{
					if (ChoosingCaptain == 1)
					{
						tempstring3 = "member" + listcurrent;
						RelaunchingShipCaptain = PChar.ShipBerthing.templist.(tempstring3).index;
						if (BerthingShipCaptain == RelaunchingShipCaptain) { BerthingShipCaptain = -1; }
					}
					else
					{
						tempstring3 = "member" + listcurrent;
						BerthingShipCaptain = PChar.ShipBerthing.templist.(tempstring3).index;
						if (RelaunchingShipCaptain == BerthingShipCaptain) { RelaunchingShipCaptain = -1; }
					}
					DeleteAttribute(PChar,"ShipBerthing.templist");
					ChangeWindow("Final Details");
					ChoosingCaptain = 0;
					SetCurrentNode("EXIT_BUTTON");
				}
			}

		break;



		//default:
			switch (FCControlsID)
			{

				case "Ship Berthing":

					if (nodName == "FC_CANCELBTN")
					{
						if (comName == "activate" || comName == "click")
						{
							ChangeWindow("Final Details");
							FCControlsID = "";
							ChoosingCaptain = 0;
							SetCurrentNode("EXIT_BUTTON");
						}
					}

					if (nodName == "FD_OKBTN")
					{
						if (comName == "activate" || comName == "click")
						{/* moved by MAXIMUS to the void IDoExit(int exitCode)
							tempnum1 = FindCurrentPort();
							switch (tempnum1)
							{
								case 0:		tempstring3 = "Falaise_de_fleur_port_01";	tempstring4 = "sea";		break;
								case 1:		tempstring3 = "REDMOND_PORT";				tempstring4 = "sea_1";		break;
								case 2:		tempstring3 = "Muelle_port";				tempstring4 = "Reload3";	break;
								case 3:		tempstring3 = "Oxbay_port";			        tempstring4 = "Reload2";	break;
								case 4:		tempstring3 = "Greenford_port";				tempstring4 = "Reload1";	break;
								case 5:		tempstring3 = "Conceicao_port";				tempstring4 = "Reload2";	break;
								case 6:		tempstring3 = "Douwesen_port";				tempstring4 = "Reload2";	break;
								case 7:		tempstring3 = "QC_port";			        tempstring4 = "Reload1";	break;
							}
							if (PChar.location == tempstring3)
							{
								ReloadProgressStart();
								UnloadLocation(FindLoadedLocation());
								DoReloadCharacterToLocation(tempstring3,"Reload",tempstring4);
								ReloadProgressEnd();
							}*/
							ShipBerthing(SelectedCompanionSlot, SelectedPort, SelectedBerthingSlot, BerthingMethod, RelaunchingShipCaptain, BerthingShipCaptain);
							FillInfoArrays();
							ChangeWindow("Base");
							FCControlsID = "";
							ChoosingCaptain = 0;
						}
					}

				break;



				case "Lay up ship on shore leave":

					if (nodName == "FC_CANCELBTN")
					{
						if (comName == "activate" || comName == "click")
						{
							ChangeWindow("Berthed Ship Details");
							FCControlsID = "";
							SetCurrentNode("EXIT_BUTTON");
						}
					}

					if (nodName == "FD_OKBTN")
					{
						if (comName == "activate" || comName == "click")
						{
							ShipLUFromSO(SelectedPort,SelectedBerthingSlot);
							ChangeWindow("Base");
							FCControlsID = "";
							SetCurrentNode("EXIT_BUTTON");
						}
					}

				break;



				case "Scrap berthed ship":

					if (nodName == "FC_CANCELBTN")
					{
						if (comName == "activate" || comName == "click")
						{
							ChangeWindow("Berthed Ship Details");
							FCControlsID = "";
							SetCurrentNode("EXIT_BUTTON");
						}
					}

					if (nodName == "FD_OKBTN")
					{
						if (comName == "activate" || comName == "click")
						{
							ShipScrapping(SelectedPort,SelectedBerthingSlot);
							ChangeWindow("Base");
							FCControlsID = "";
							SetCurrentNode("EXIT_BUTTON");
						}
					}

				break;
			}
		break;
	}
}




//************************************************************************************************************
//
// EXIT FUNCTIONS
//
//************************************************************************************************************


void ProcessCancelExit()
{
	switch(Currentwindow)
	{
		case "Base":
			IDoExit(RC_INTERFACE_KAM_SHIPBERTHING_EXIT);
			SetCurrentNode("EXIT_BUTTON");
		break;

		case "Berthed Ship Details":
			SelectedBerthingSlot = 1;
			SelectedPort = nCurTown; // Sulan
			ChangeWindow("Base");
			SetCurrentNode("BERTHASHIPHEREBTN");
		break;

		case "Relaunch Berthed Ship - Choose Slot":
			ChangeWindow("Berthed Ship Details");
			SetCurrentNode("EXIT_BUTTON");
		break;

		case "Berth Ship - Choose Ship":
			ChangeWindow("Base");
			SetCurrentNode("BERTHASHIPHEREBTN");
		break;

		case "Berth Ship - Choose Slot":
			ChangeWindow("Berth Ship - Choose Ship");
			SetCurrentNode("EXIT_BUTTON");
		break;

		case "Final Details":
			if (BeganViaBS == true)
			{
				ChangeWindow("Berth Ship - Choose Slot");
			}
			else
			{
				ChangeWindow("Relaunch Berthed Ship - Choose Slot");
			}
			SetCurrentNode("EXIT_BUTTON");
		break;

		case "Choose a Captain":
			DeleteAttribute(PChar,"ShipBerthing.templist");
			ChangeWindow("Final Details");
			SetCurrentNode("EXIT_BUTTON");
		break;

		//default:
			switch (FCControlsID)
			{
				case "Ship Berthing":
					ChangeWindow("Final Details");
					FCControlsID = "";
					ChoosingCaptain = 0;
					SetCurrentNode("EXIT_BUTTON");
				break;

				case "Lay up ship on shore leave":
					ChangeWindow("Berthed Ship Details");
					FCControlsID = "";
					SetCurrentNode("EXIT_BUTTON");
				break;

				case "Scrap berthed ship":
					ChangeWindow("Berthed Ship Details");
					FCControlsID = "";
					SetCurrentNode("EXIT_BUTTON");
				break;
			}
		break;
	}
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("frame","FrameProcess");
	DelEventHandler("exitCancel","ProcessCancelExit");
// KK -->
	DelEventHandler("SelectPrevTown", "DoSelectPrevTown");
	DelEventHandler("SelectNextTown", "DoSelectNextTown");

	interfaceResultCommand = exitCode;

	int i = 0;
	ref mchr = Getmaincharacter();

	bool hasShip = false;
	for (i = 0; i < 4; i++) { // MM TODO: COMPANION_MAX
		int cidx = GetCompanionIndex(mchr, i);
		if (cidx < 0) continue;
		if (GetCharacterShipType(GetCharacter(cidx)) != SHIP_NOTUSED) {
			hasShip = true;
			break;
		}
	}
	if (hasShip)
		PostEvent("LaunchIAfterFrame",1,"sl", "I_SHIP", 1);
	else
		PostEvent("LaunchIAfterFrame",1,"sl", "I_CHARACTER", 1);
	EndCancelInterface(false);
// <-- KK
}

// KK -->
void DoSelectNextTown()
{
	// Screwface
	int tnum = GetIslandTownsQuantity(GetIslandName(nCurScroll));
	for (int j = 1; j <= tnum; j++)
	{
		int townidx = GetTownIndex(GetTownIDFromIsland(GetIslandName(nCurScroll), j));	
		if(townidx>=0 && townidx < TOWNS_QUANTITY && townidx==ncurtown)
		{
			j++;
			if(j>tnum) j = 1;
			break;
		}
	}
	townidx = GetTownIndex(GetTownIDFromIsland(GetIslandName(nCurScroll), j));
	if (townidx>=0 && townidx < TOWNS_QUANTITY && CheckAttribute(&Towns[townidx], "shipberth"))
	{
		ncurtown = townidx;
		UpdateBaseDisplay();
	}
	// Screwface
}

void DoSelectPrevTown()
{
}
// <-- KK
