

bool exitBool = true;

#define NONEFACE_TEXTURE_NAME "interfaces\empty_face.tga"

#define ISHOW_MODE_CAPTIVE		0
#define ISHOW_MODE_SUMSKILL		1
#define ISHOW_MODE_CHRSKILL		2

string oldCurNode = "";
int oldShowMode = -1;

int nCurScroll;
//ref PChar;
int CurrentPortNumber;

int SelectedCaptain1 = -1;
int SelectedCaptain1Type = -1;
int SelectedCaptain2 = -1;
int SelectedCaptain2Type = -1;

string curLocNation = "";

void InitInterface(string iniName)
{
	PChar = GetMainCharacter();

	// checks if PChar is currently docked in one of the seven ports
	string tempstring_1;
	int tempnum_1;

	CurrentPortNumber = FindCurrentPort();		//find if player is currently docked in one of the seven ports

	GameInterface.title = "titleKAMShipTransfer";
	FillScroll();
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();//MAXIMUS: standard exit-string for exit-button

	CreateString(true,"ShipName","",FONT_NORMAL,COLOR_NORMAL,320,179,SCRIPT_ALIGN_CENTER,1.0);
// KK -->
	if (bNewInterface) {
		CreateImage("SelectedCaptain1","EMPTYFACE","emptyface_new",140,250,240,350);
		CreateImage("SelectedCaptain2","EMPTYFACE","emptyface_new",510,250,610,350);
	} else {
		CreateImage("SelectedCaptain1","EMPTYFACE","emptyface",140,250,240,350);
		CreateImage("SelectedCaptain2","EMPTYFACE","emptyface",510,250,610,350);
	}
// <-- KK
	CreateImage("SelectedCaptain1Ship","BLANK_SHIP","Not used",30,250,130,350);
	SetFormatedText ("SEL1DETAILS","(" + XI_ConvertString("no captain selected") + ")");
	CreateImage("SelectedCaptain2Ship","BLANK_SHIP","Not used",400,250,500,350);
	SetFormatedText ("SEL2DETAILS","(" + XI_ConvertString("no captain selected") + ")");
	SetSelectable("I_TRANSFER",false);
	SetSelectable("EXIT_BUTTON",true);

	UpdateDisplay();

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("frame","ProcessFrame",1);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
	SetEventHandler("evntDoPostExit","DoPostExit",0);
}

void UpdateDisplay()
{
	int tempCurrentSel;
	string attributename;
	int tempcaptainindex;
	string tempstring;
	int tempnum1;
	int tempnum2;

	attributename = "pic" + (nCurScroll + 1);
	tempcaptainindex = sti(GameInterface.passengerslist.(attributename).captainindex); // KK

	CheckCaptain(tempcaptainindex); // KK

	GameInterface.strings.ShipName = GetMyShipName(&Characters[tempcaptainindex]);
	tempstring = Characters[tempcaptainindex].name + " " + Characters[tempcaptainindex].lastname;
	tempnum1 = sti(PChar.index); // KK
	if (tempcaptainindex != tempnum1)
	{
		tempnum2 = sti(GameInterface.passengerslist.(attributename).captaintype); // KK
		if (tempnum2 == 0)
		{
			if (IsTrader(GetCharacter(tempcaptainindex)))
				tempstring += ", " + XI_ConvertString("Strader");
			else
				tempstring += ", " + XI_ConvertString("Scompanion");
		}
		else
		{
			tempstring += ", " + XI_ConvertString("on shore leave");
		}
	}
	SetFormatedText("SCROLLDETAILS",tempstring);
}

void UpdateSelectedCaptain1()
{
	string attributename;
	string tempstring1;
	string tempstring2;
	int tempnum1;
	int tempnum2;
	ref tempChRef;

	attributename = "pic" + (nCurScroll + 1);
	tempnum1 = GameInterface.passengerslist.(attributename).captainindex;
	SelectedCaptain1 = tempnum1;

	tempnum1 = GameInterface.passengerslist.(attributename).captaintype;
	SelectedCaptain1Type = tempnum1;

	tempChRef = GetCharacter(SelectedCaptain1);
	tempnum1 = GetCharacterFaceID(tempChRef.model);
	tempstring1 = "FACE128_" + tempnum1;
	CreateImage("SelectedCaptain1",tempstring1,"face",140,250,240,350);

	tempstring1 = GameInterface.passengerslist.(attributename).img2;
	tempnum1 = GameInterface.passengerslist.(attributename).tex2;
	switch(tempnum1)
	{
		case 0:		tempstring2 = "BLANK_SHIP";	break;
		case 1:		tempstring2 = "SHIPS16";	break;
		case 2:		tempstring2 = "SHIPS1";		break;
		case 3:		tempstring2 = "SHIPS2";		break;
		case 4:		tempstring2 = "SHIPS3";		break;
		case 5:		tempstring2 = "SHIPS4";		break;
		case 6:		tempstring2 = "SHIPS5";		break;
		case 7:		tempstring2 = "ICONS";		break;
	}
	CreateImage("SelectedCaptain1Ship",tempstring2,tempstring1,30,250,130,350);

	tempstring1 = Characters[SelectedCaptain1].ship.name + ", " + Characters[SelectedCaptain1].name + " " + Characters[SelectedCaptain1].lastname;
	SetFormatedText("SEL1DETAILS",tempstring1);

	if (SelectedCaptain2 == SelectedCaptain1)
	{
		RemoveCaptain2();
	}

	if (SelectedCaptain2 >= 0)
	{
		SetSelectable("I_TRANSFER",true);
	}

	SetCurrentNode("PASSENGERSLIST"); // KK
	UpdateDisplay(); // KK
}

void RemoveCaptain1()
{
	SelectedCaptain1 = -1;
	SelectedCaptain1Type = -1;
// KK -->
	if (bNewInterface)
		CreateImage("SelectedCaptain1","EMPTYFACE","emptyface_new",140,250,240,350);
	else
		CreateImage("SelectedCaptain1","EMPTYFACE","emptyface",140,250,240,350);
// <-- KK
	CreateImage("SelectedCaptain1Ship","BLANK_SHIP","Not used",30,250,130,350);
	SetFormatedText ("SEL1DETAILS","(no captain selected)");
	SetSelectable("SELECTBTN1", true); // KK
	SetSelectable("I_TRANSFER",false);
}

void UpdateSelectedCaptain2()
{
	string attributename;
	string tempstring1;
	string tempstring2;
	int tempnum1;
	int tempnum2;
	ref tempChRef;

	attributename = "pic" + (nCurScroll + 1);
	tempnum1 = GameInterface.passengerslist.(attributename).captainindex;
	SelectedCaptain2 = tempnum1;

	tempnum1 = GameInterface.passengerslist.(attributename).captaintype;
	SelectedCaptain2Type = tempnum1;

	tempChRef = GetCharacter(SelectedCaptain2);
	tempnum1 = GetCharacterFaceID(tempChRef.model);
	tempstring1 = "FACE128_" + tempnum1;
	CreateImage("SelectedCaptain2",tempstring1,"face",510,250,610,350);

	tempstring1 = GameInterface.passengerslist.(attributename).img2;
	tempnum1 = GameInterface.passengerslist.(attributename).tex2;
	switch(tempnum1)
	{
		case 0:		tempstring2 = "BLANK_SHIP";	break;
		case 1:		tempstring2 = "SHIPS16";	break;
		case 2:		tempstring2 = "SHIPS1";		break;
		case 3:		tempstring2 = "SHIPS2";		break;
		case 4:		tempstring2 = "SHIPS3";		break;
		case 5:		tempstring2 = "SHIPS4";		break;
		case 6:		tempstring2 = "SHIPS5";		break;
		case 7:		tempstring2 = "ICONS";		break;
	}
	CreateImage("SelectedCaptain2Ship",tempstring2,tempstring1,400,250,500,350);

	tempstring1 = GetMyShipName(&Characters[SelectedCaptain2]) + ", " + Characters[SelectedCaptain2].name + " " + Characters[SelectedCaptain2].lastname;
	SetFormatedText("SEL2DETAILS",tempstring1);

	if (SelectedCaptain1 == SelectedCaptain2)
	{
		RemoveCaptain1();
	}

	if (SelectedCaptain1 >= 0)
	{
		SetSelectable("I_TRANSFER",true);
	}
	SetCurrentNode("PASSENGERSLIST"); // KK
	UpdateDisplay(); // KK
}

void RemoveCaptain2()
{
	SelectedCaptain2 = -1;
	SelectedCaptain2Type = -1;
// KK -->
	if (bNewInterface)
		CreateImage("SelectedCaptain2","EMPTYFACE","emptyface_new",510,250,610,350);
	else
		CreateImage("SelectedCaptain2","EMPTYFACE","emptyface",510,250,610,350);
// <-- KK
	CreateImage("SelectedCaptain2Ship","BLANK_SHIP","Not used",400,250,500,350);
	SetFormatedText ("SEL2DETAILS","(no captain selected)");
	SetSelectable("SELECTBTN2", true); // KK
	SetSelectable("I_TRANSFER",false);
}

void ProcessCancelExit()
{
	IDoExit( RC_INTERFACE_KAM_SHIPTRANSFER_EXIT );
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcessCommandExecute");
	DelEventHandler("evntDoPostExit","DoPostExit");

	interfaceResultCommand = exitCode;
// MAXIMUS interface MOD -->
    PostEvent("LaunchIAfterFrame",1,"sl", "I_SHIP", 1);
    EndCancelInterface(false);
/*
	if( CheckAttribute(&InterfaceStates,"InstantExit") && sti(InterfaceStates.InstantExit)==true )
	{
		exitBool = true;
	}
	if(exitBool)
	{
		DeleteAttribute(&InterfaceStack,"SelectMenu_node");
	}
	EndCancelInterface(exitBool);*/
// MAXIMUS interface MOD <--
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();
	ref tmpch;
	string tmpstr;
	
	if (nodName == "CANCELBTN")
	{
		if (comName=="activate" || comName=="click")
		{
		    PostEvent("LaunchIAfterFrame",1,"sl", "I_SHIP", 1);
			EndCancelInterface(false);
		}
	}

	if (nodName == "I_TRANSFER")
	{
		if (comName=="activate" || comName=="click")
		{
			ref MainChar = GetMainCharacter();
			MainChar.shiptransferinterface.char1 = SelectedCaptain1;
			MainChar.shiptransferinterface.char2 = SelectedCaptain2;
			MainChar.shiptransferinterface.calledfrominterface = 1;

			if (sti(MainChar.shiptransferinterface.char1) != sti(MainChar.index))
			{
				MainChar.shiptransferinterface.donotallowcaptainchange = 1;
			}
			else
			{
				MainChar.shiptransferinterface.donotallowcaptainchange = 0;
			}

			if (SelectedCaptain1Type == 1 || SelectedCaptain2Type == 1)
			{
				MainChar.shiptransferinterface.involvesberthedship = 1;
				MainChar.shiptransferinterface.donotallowcaptainchange = 1;
			}
			else
			{
				MainChar.shiptransferinterface.involvesberthedship = 0;
			}

			PostEvent("evntDoPostExit",1,"l",RC_INTERFACE_KAM_SHIPTRANSFER_EXIT);
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			EndCancelInterface(false);
		}
	}

	if (nodName == "SELECTBTN1")
	{
		if (comName=="activate" || comName=="click")
		{
			UpdateSelectedCaptain1();
		}
	}

	if (nodName == "SELECTBTN2")
	{
		if (comName=="activate" || comName=="click")
		{
			UpdateSelectedCaptain2();
		}
	}
}

void DoPostExit()
{
	int exitCode2 = GetEventData();
	exitBool = false;
	IDoExit(exitCode2);
}


void FillScroll()
{
	int i;
	int cn;
	int tempShipType;
	string tempShipPic, tempShipClass, tempShipName; // KK
	int tempShipTex;
	string attributename1;
	string attributename2;
	string attributename3;
	int templistsize;
	int tmpint;
	ref temprchr;

 	nCurScroll = 0;
	GameInterface.passengerslist.current = 0;
	GameInterface.passengerslist.NotUsed = 10;
	GameInterface.passengerslist.ImagesGroup.t0 = "BLANK_SHIP";
	GameInterface.passengerslist.ImagesGroup.t1 = "SHIPS16";
	GameInterface.passengerslist.ImagesGroup.t2 = "SHIPS1";
	GameInterface.passengerslist.ImagesGroup.t3 = "SHIPS2";
	GameInterface.passengerslist.ImagesGroup.t4 = "SHIPS3";
	GameInterface.passengerslist.ImagesGroup.t5 = "SHIPS4";
	GameInterface.passengerslist.ImagesGroup.t6 = "SHIPS5";
	GameInterface.passengerslist.ImagesGroup.t7 = "ICONS";

	templistsize = 1;

	for (i=0; i<COMPANION_MAX; i++)
	{
		attributename1 = "pic" + templistsize;
		cn = GetCompanionIndex(PChar,i);
		if (cn >= 0)
		{
// KK -->
			temprchr = GetCharacter(cn);
			tempShipType = GetCharacterShipType(temprchr);
			if(tempShipType >= 0 && tempShipType < SHIP_TYPES_QUANTITY)
			{
				tempShipPic = GetShipPicName(tempShipType);
				tempShipTex = 1 + GetShipTexture(tempShipType);
				tempShipClass = "#" + GetLocalShipAttrib(temprchr.ship, ShipsTypes[tempShipType], "Class");
				tempShipName = GetLocalShipAttrib(temprchr.ship, ShipsTypes[tempShipType], "SName");
			}
			else
			{
				tempShipPic = "Not Used";
				tempShipTex = 0;
				tempShipClass = "";
				tempShipName = "";
			}
			GameInterface.passengerslist.(attributename1).str1 = tempShipClass;
			GameInterface.passengerslist.(attributename1).str2 = tempShipName;
			GameInterface.passengerslist.(attributename1).img1 = "ship back";
			GameInterface.passengerslist.(attributename1).tex1 = 3;
			GameInterface.passengerslist.(attributename1).img2 = tempShipPic;
			GameInterface.passengerslist.(attributename1).tex2 = tempShipTex;
			GameInterface.passengerslist.(attributename1).captainindex = cn;
			GameInterface.passengerslist.(attributename1).captaintype = 0;
			templistsize++;
// <-- KK
		}
	}

	if (CurrentPortNumber >= 0)
	{
		// KK trace("in port " + currentportnumber);
		for (i=1; i<5; i++)
		{
			attributename1 = "port" + CurrentPortNumber;
			attributename2 = "slot" + i;
			if(!CheckAttribute(PChar,"ShipBerthing."+attributename1+"."+attributename2+".status")) continue;
			tmpint = sti(PChar.ShipBerthing.(attributename1).(attributename2).status);
			if (tmpint == 2)
			{
// KK -->
				//trace("ship in slot " + i + " is on shore leave");
				cn = sti(PChar.ShipBerthing.(attributename1).(attributename2).captainindex);
				if (cn < 0) continue;
				attributename3 = "pic" + templistsize;
				temprchr = GetCharacter(cn);
				tempShipType = GetCharacterShipType(temprchr);
				if(tempShipType >= 0 && tempShipType < SHIP_TYPES_QUANTITY)
				{
					tempShipPic = GetShipPicName(tempShipType);
					tempShipTex = 1 + GetShipTexture(tempShipType);
					tempShipClass = "#" + GetLocalShipAttrib(temprchr.ship, ShipsTypes[tempShipType], "Class");
					tempShipName = GetLocalShipAttrib(temprchr.ship, ShipsTypes[tempShipType], "SName");
				}
				else
				{
					tempShipPic = "Not Used";
					tempShipTex = 0;
					tempShipClass = "";
					tempShipName = "";
				}
				GameInterface.passengerslist.(attributename3).str1 = tempShipClass;
				GameInterface.passengerslist.(attributename3).str2 = tempShipName;
				GameInterface.passengerslist.(attributename3).img1 = "ship back";
				GameInterface.passengerslist.(attributename3).tex1 = 3;
				GameInterface.passengerslist.(attributename3).img2 = tempShipPic;
				GameInterface.passengerslist.(attributename3).tex2 = tempShipTex;
				GameInterface.passengerslist.(attributename3).captainindex = cn;
				GameInterface.passengerslist.(attributename3).captaintype = 0;
				templistsize++;
// <-- KK
			}
		}
	}

	templistsize--;

	GameInterface.passengerslist.ListSize = templistsize;
}

void ProcessFrame()
{
	if(nCurScroll!=sti(GameInterface.passengerslist.current))
	{
		nCurScroll = sti(GameInterface.passengerslist.current);
		UpdateDisplay();
	}
}

// KK -->
void CheckCaptain(int SelectedCaptain)
{
	if (SelectedCaptain < 0) {
		SetSelectable("SELECTBTN1", false);
		SetSelectable("SELECTBTN2", false);
	}
	SetSelectable("SELECTBTN1", GetRemovable(GetCharacter(SelectedCaptain)));
	SetSelectable("SELECTBTN2", SelectedCaptain != GetMainCharacterIndex() && GetRemovable(GetCharacter(SelectedCaptain)));
}
// <-- KK
