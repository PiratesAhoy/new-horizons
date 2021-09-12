//ref PChar;
int PCharNation;
int ListNum;
int ListMax;
string FileStr[5];
string SailDesc;

// KK -->
#define SAILSTYPE_DEFAULT    -1
#define SAILSTYPE_STANDARD    0
#define SAILSTYPE_WEATHERED   1
#define SAILSTYPE_PURE_WHITE  2
#define SAILSTYPE_SPECIAL     3

#define SAILSMODEL_WHOLE   0
#define SAILSMODEL_TORN    1

#define SAILSCOLOUR_WHITE 0
#define SAILSCOLOUR_RED   1
#define SAILSCOLOUR_BLACK 2
#define SAILSCOLOUR_TAN   3

#define SAILSDESIGN_PLAIN   0
#define SAILSDESIGN_NATION  1
#define SAILSDESIGN_PIRATE  2

bool LowClassShip = false;

int curSailType, curSailModel, curSailColor, CurSailDesign;

bool isSailTypeSpecial = false;
bool hasSailModelWhole = true;
bool hasSailModelTorn = true;
bool hasSailColorWhite = true;
bool hasSailColorRed = true;
bool hasSailColorBlack = true;
bool hasSailColorTan = true;
bool hasSailNationLogo = true;
bool HasSailPirateLogo = true;

#define SAILSTYPE_SPECIAL_COUNT 16
string SpecialSailsNormal[SAILSTYPE_SPECIAL_COUNT];
string SpecialSailsEmblem[SAILSTYPE_SPECIAL_COUNT];
string SpecialSailsDescr[SAILSTYPE_SPECIAL_COUNT];

// <-- KK

void InitInterface(string iniName)
{
	PChar = GetMainCharacter();
	PCharNation = GetCurrentFlag();
	if(sti(PCharNation) == PERSONAL_NATION) PCharNation = 10; // PB: Enable Selection of Personal Emblems

	GameInterface.title = "titleKAMSelectSails";

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();//MAXIMUS: standard exit-string for exit-button

	if (GetCharacterShipClass(PChar) > 8) // Petros: Was 3, changed to allow Fleut and Caravel
	{
		LowClassShip = true;
	}

	SpecialSailsNormal[0] = "sail_petros_plain.tga";
	SpecialSailsEmblem[0] = "sail_petros_plain.tga";
	SpecialSailsDescr[0] = "Red sails with yellow stripes as used by the notorious Petros the Pirate.";
	SpecialSailsNormal[1] = "sail_petros_black_red.tga";
	SpecialSailsEmblem[1] = "sail_petros_black_red.tga";
	SpecialSailsDescr[1] = "Red sails with black stripes as used by the notorious Petros the Pirate.";
	SpecialSailsNormal[2] = "sail_petros_blue_white.tga";
	SpecialSailsEmblem[2] = "sail_petros_blue_white.tga";
	SpecialSailsDescr[2] = "White sails with blue stripes as used by the notorious Petros the Pirate.";
	SpecialSailsNormal[3] = "sail_barbarossa_plain.tga";
	SpecialSailsEmblem[3] = "sail_barbarossa_plain.tga";
	SpecialSailsDescr[3] = "White sails with blue stripes as used by the notorious pirate Barbarossa.";
	SpecialSailsNormal[4] = "sail_purewhite_plain.tga";
	SpecialSailsEmblem[4] = "sws_christian_maria.tga";
	SpecialSailsDescr[4] = "Catholic sails with a picture of the Virgin Mary.";
	SpecialSailsNormal[5] = "sail_BlackPearl_whole.tga";
	SpecialSailsEmblem[5] = "sail_BlackPearl_whole.tga";
	SpecialSailsDescr[5] = "Whole black sails characteristic to Black Pearl."
	SpecialSailsNormal[6] = "sail_BlackPearl_torn.tga";
	SpecialSailsEmblem[6] = "sail_BlackPearl_torn.tga";
	SpecialSailsDescr[6] = "Black tattered sails characteristic to Black Pearl."
	SpecialSailsNormal[7] = "sail_whole_black_patch1.tga";
	SpecialSailsEmblem[7] = "sail_whole_black_patch2.tga";
	SpecialSailsDescr[7] = "Black patched sails used on Black Pearl under Captain Jack Sparrow command."
	SpecialSailsNormal[8] = "sail_dutchman2.tga";
	SpecialSailsEmblem[8] = "sail_dutchman2.tga";
	SpecialSailsDescr[8] = "Green torn sails as seen on the Flying Dutchman under the command of captain Davy Jones.";
	SpecialSailsNormal[9] = "sail_dutchman1.tga";
	SpecialSailsEmblem[9] = "sail_dutchman1.tga";
	SpecialSailsDescr[9] = "Khaki whole sails as seen on the Flying Dutchman under the command of captain Will Turner.";
	SpecialSailsDescr[10] = "Junk sails for Empress."
	SpecialSailsNormal[10] = "sail_Empress.tga";
	SpecialSailsEmblem[10] = "sail_Empress.tga";
	SpecialSailsNormal[11] = "sail_torn_red_qar.tga";
	SpecialSailsEmblem[11] = "sail_torn_red_qar.tga";
	SpecialSailsDescr[11] = "Red torn sails with holes characteristic to Queen Anne's Revenge."
	SpecialSailsDescr[12] = "Junk sails for Empress without holes."
	SpecialSailsNormal[12] = "sail_Empres2.tga";
	SpecialSailsEmblem[12] = "sail_Empres2.tga";
	SpecialSailsDescr[13] = "Sails with the coat of arms of Castile-Leon."
	SpecialSailsNormal[13] = "sail_weathered_common.tga";
	SpecialSailsEmblem[13] = "sail_castile_leon.tga";
	SpecialSailsDescr[14] = "Sails with the coat of arms of the Holy Roman Empire."
	SpecialSailsNormal[14] = "sail_weathered_common.tga";
	SpecialSailsEmblem[14] = "sail_holy_roman_empire.tga";
	SpecialSailsNormal[15] = "sail_QAR.tga";
	SpecialSailsEmblem[15] = "sail_QAR1.tga";
	SpecialSailsDescr[15] = "Red sails with gold fringe, characteristic to Queen Anne's Revenge."

	CreateString(true, "SailTypeName", "", FONT_NORMAL, COLOR_NORMAL, 130, 55, SCRIPT_ALIGN_CENTER, 0.9);
	CreateString(true, "SailModelName", "", FONT_NORMAL, COLOR_NORMAL, 130, 105, SCRIPT_ALIGN_CENTER, 0.9);
	CreateString(true, "SailColorName", "", FONT_NORMAL, COLOR_NORMAL, 130, 155, SCRIPT_ALIGN_CENTER, 0.9);
	CreateString(true, "SailDesignName", "", FONT_NORMAL, COLOR_NORMAL, 130, 205, SCRIPT_ALIGN_CENTER, 0.9);

//	CreateString(true, "SailsFilenames", XI_ConvertString("Filenames") + ":", FONT_NORMAL, COLOR_NORMAL, 444, 334, SCRIPT_ALIGN_CENTER, 0.6);

//	CreateString(true, "SailsListStr", "", FONT_NORMAL, COLOR_NORMAL, 444, 90, SCRIPT_ALIGN_CENTER, 1.0);
//	CreateString(true, "SailsFnames", "", FONT_NORMAL, COLOR_NORMAL, 444, 350, SCRIPT_ALIGN_CENTER, 0.6);

	FirstUpdate();
	SetSelectable("EXIT_BUTTON",true);
	SetCurrentNode(NextDown("USETHESESAILS_BUTTON"));


	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
// KK -->
	SetEventHandler("IEvnt_MouseClick", "IProcMouseClick", 0);
	SetEventHandler("ChangeSailTypeLeft", "DoSailTypeChangeLeft", 0);
	SetEventHandler("ChangeSailTypeRight", "DoSailTypeChangeRight", 0);
	SetEventHandler("ChangeSailModelLeft", "DoSailModelChangeLeft", 0);
	SetEventHandler("ChangeSailModelRight", "DoSailModelChangeRight", 0);
	SetEventHandler("ChangeSailColorLeft", "DoSailColorChangeLeft", 0);
	SetEventHandler("ChangeSailColorRight", "DoSailColorChangeRight", 0);
	SetEventHandler("ChangeSailDesignLeft", "DoSailDesignChangeLeft", 0);
	SetEventHandler("ChangeSailDesignRight", "DoSailDesignChangeRight", 0);
// <-- KK
// added by MAXIMUS [for correct buttons selection] -->
	SetEventHandler("UpPress","UpProcess",0);
	SetEventHandler("DownPress","DownProcess",0);
// added by MAXIMUS [for correct buttons selection] <--
}

void FirstUpdate()
{
	aref arship; makearef(arship, PChar.Ship);
	ref rship = GetShipByType(GetCharacterShipType(PChar));

	curSailType = DEFAULT_SAILS;
	curSailModel = SAILSMODEL_WHOLE;
	curSailColor = SAILSCOLOUR_WHITE;
	curSailDesign = SAILSDESIGN_PLAIN;
	ListNum = 0;

	SetListMax();
	if (ListNum >= ListMax) { ListNum = 0; }

	isSailTypeSpecial = false;
	switch (curSailType) {
		case SAILSTYPE_DEFAULT:
			switch (DEFAULT_SAILS) {
				case SAILSTYPE_STANDARD:
					hasSailModelWhole = true;
					hasSailModelTorn = true;
					hasSailColorWhite = true;
					hasSailColorRed = true;
					hasSailColorBlack = true;
					hasSailColorTan = true;
					hasSailNationLogo = true;
					hasSailPirateLogo = true;
				break;
				case SAILSTYPE_PURE_WHITE:
					hasSailModelWhole = false;
					hasSailModelTorn = false;
					hasSailColorWhite = false;
					hasSailColorRed = false;
					hasSailColorBlack = false;
					hasSailColorTan = false;
					hasSailNationLogo = true;
					hasSailPirateLogo = false;
				break;
				case SAILSTYPE_WEATHERED:
					hasSailModelWhole = false;
					hasSailModelTorn = false;
					hasSailColorWhite = false;
					hasSailColorRed = false;
					hasSailColorBlack = false;
					hasSailColorTan = false;
					hasSailNationLogo = true;
					hasSailPirateLogo = false;
				break;
				case SAILSTYPE_SPECIAL:
					isSailTypeSpecial = true;
					hasSailModelWhole = false;
					hasSailModelTorn = false;
					hasSailColorWhite = false;
					hasSailColorRed = false;
					hasSailColorBlack = false;
					hasSailColorTan = false;
					hasSailNationLogo = false;
					hasSailPirateLogo = false;
				break;
			}
		break;
		case SAILSTYPE_STANDARD:
			hasSailModelWhole = true;
			hasSailModelTorn = true;
			hasSailColorWhite = true;
			hasSailColorRed = true;
			hasSailColorBlack = true;
			hasSailColorTan = true;
			hasSailNationLogo = true;
			hasSailPirateLogo = true;
		break;
		case SAILSTYPE_PURE_WHITE:
			hasSailModelWhole = false;
			hasSailModelTorn = false;
			hasSailColorWhite = false;
			hasSailColorRed = false;
			hasSailColorBlack = false;
			hasSailColorTan = false;
			hasSailNationLogo = true;
			hasSailPirateLogo = false;
		break;
		case SAILSTYPE_WEATHERED:
			hasSailModelWhole = false;
			hasSailModelTorn = false;
			hasSailColorWhite = false;
			hasSailColorRed = false;
			hasSailColorBlack = false;
			hasSailColorTan = false;
			hasSailNationLogo = true;
			hasSailPirateLogo = false;
		break;
		case SAILSTYPE_SPECIAL:
			isSailTypeSpecial = true;
			hasSailModelWhole = false;
			hasSailModelTorn = false;
			hasSailColorWhite = false;
			hasSailColorRed = false;
			hasSailColorBlack = false;
			hasSailColorTan = false;
			hasSailNationLogo = false;
			hasSailPirateLogo = false;
		break;
	}

	SetSelectable("USETHESESAILS_BUTTON",true);
	UpdateDisplay();
}

void UpdateDisplay()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");

	FileStr[1] = "sail_";
	FileStr[2] = "";
	FileStr[3] = ".tga";
	FileStr[4] = "sail_";
	SailDesc = "";

	string tempstring;
	ref PChar = GetMainCharacter(); // KK

	if (LowClassShip) {
		hasSailNationLogo = false;
		hasSailPirateLogo = false;
	}

	GameInterface.strings.SailTypeName = GetSailTypeNameFromListNumber(curSailType);
	if (curSailType != SAILSTYPE_SPECIAL) {
		GameInterface.strings.SailModelName = GetSailModelNameFromListNumber(curSailModel);
		GameInterface.strings.SailColorName = GetSailColorNameFromListNumber(curSailColor);
		GameInterface.strings.SailDesignName = GetSailDesignNameFromListNumber(CurSailDesign);
	} else {
		GameInterface.strings.SailModelName = LanguageConvertString(tmpLangFileID, "Special Sails");
		GameInterface.strings.SailColorName = LanguageConvertString(tmpLangFileID, "Special Sails");
		GameInterface.strings.SailDesignName = LanguageConvertString(tmpLangFileID, "Special Sails");
	}

	if (!hasSailModelTorn) {
		GameInterface.strings.SailModelName = GetSailModelNameFromListNumber(SAILSMODEL_WHOLE);
		SetNodeUsing("SAILMODEL_CHANGER", false);
	} else {
		SetNodeUsing("SAILMODEL_CHANGER", true);
	}
	if (!hasSailColorWhite && !hasSailColorRed && !hasSailColorBlack && !hasSailColorTan) {
		GameInterface.strings.SailColorName = GetSailColorNameFromListNumber(SAILSCOLOUR_WHITE);
		SetNodeUsing("SAILCOLOR_CHANGER", false);
	} else {
		SetNodeUsing("SAILCOLOR_CHANGER", true);
	}
	if (GameInterface.strings.SailColorName == GetSailColorNameFromListNumber(SAILSCOLOUR_RED) && hasSailColorRed == false) {
		GameInterface.strings.SailColorName = GetSailColorNameFromListNumber(SAILSCOLOUR_WHITE);
		curSailColor = SAILSCOLOUR_WHITE;
	}
	if (!hasSailNationLogo && !hasSailPirateLogo) {
		GameInterface.strings.SailDesignName = GetSailDesignNameFromListNumber(SAILSDESIGN_PLAIN);
		SetNodeUsing("SAILDESIGN_CHANGER", false);
	} else {
		SetNodeUsing("SAILDESIGN_CHANGER", true);
	}
	if (isSailTypeSpecial) {
		GameInterface.strings.SailModelName = GetSailModelNameFromListNumber(SAILSMODEL_WHOLE);
		SetNodeUsing("SAILMODEL_CHANGER", false);
		GameInterface.strings.SailColorName = GetSailColorNameFromListNumber(SAILSCOLOUR_WHITE);
		SetNodeUsing("SAILCOLOR_CHANGER", false);
		GameInterface.strings.SailDesignName = GetSailDesignNameFromListNumber(SAILSDESIGN_PLAIN);
		SetNodeUsing("SAILDESIGN_CHANGER", false);
	}

	if (!isSailTypeSpecial) {
		switch (curSailType) {
			case SAILSTYPE_DEFAULT:
				GameInterface.strings.SailsListStr = LanguageConvertString(tmpLangFileID,"Default Sails");
				HideScroller();
				FileStr[1] = KAM_GetDefaultEmblemedSail(PChar);
				FileStr[2] = "";
				FileStr[4] = KAM_GetDefaultNormalSail(PChar);
			break;

			case SAILSTYPE_STANDARD:
			break;

			case SAILSTYPE_PURE_WHITE:
				FileStr[1] += "purewhite_";
				FileStr[4] += "purewhite_";
				SailDesc = LanguageConvertString(tmpLangFileID,"Pure White") + " ";
			break;

			case SAILSTYPE_WEATHERED:
				FileStr[1] += "weathered_";
				FileStr[4] += "weathered_";
				SailDesc = LanguageConvertString(tmpLangFileID,"Weathered") + " ";
			break;
		}

		switch (curSailModel) {
			case SAILSMODEL_WHOLE:
				if (hasSailModelWhole) {
					FileStr[1] += "whole_";
					FileStr[4] += "whole_";
					SailDesc = LanguageConvertString(tmpLangFileID,"Whole") + " ";
				}
			break;

			case SAILSMODEL_TORN:
				if (hasSailModelTorn) {
					FileStr[1] += "torn_";
					FileStr[4] += "torn_";
					SailDesc = LanguageConvertString(tmpLangFileID,"Torn") + " ";
				}
			break;
		}

		switch (curSailColor) {
			case SAILSCOLOUR_WHITE:
				if (hasSailColorWhite) {
					FileStr[1] += "white_";
					FileStr[4] += "white_";
					SailDesc += LanguageConvertString(tmpLangFileID,"white") + " ";
				}
			break;

			case SAILSCOLOUR_RED:
				if (hasSailColorRed) {
					FileStr[1] += "red_";
					FileStr[4] += "red_";
					SailDesc += LanguageConvertString(tmpLangFileID,"crimson") + " ";
				}
			break;

			case SAILSCOLOUR_BLACK:
				if (hasSailColorBlack) {
					FileStr[1] += "black_";
					FileStr[4] += "black_";
					SailDesc += LanguageConvertString(tmpLangFileID,"black") + " ";
				}
			break;

			case SAILSCOLOUR_TAN:
				if (hasSailColorTan) {
					FileStr[1] += "tan_";
					FileStr[4] += "tan_";
					SailDesc += LanguageConvertString(tmpLangFileID,"tan") + " ";
				}
			break;
		}

		switch (curSailDesign) {
			case SAILSDESIGN_PLAIN:
				HideScroller();
				if (curSailType != SAILSTYPE_DEFAULT) {
					GameInterface.strings.SailsListStr = LanguageConvertString(tmpLangFileID,"Plain");
					if(GetCurrentPeriod() <= PERIOD_THE_SPANISH_MAIN)
						{FileStr[1] += "plain";}
					else
						{FileStr[1] += "common";}
					FileStr[2] = "";
					SailDesc += LanguageConvertString(tmpLangFileID,"Plain") + " " + LanguageConvertString(tmpLangFileID,"sails, without emblem.");
				}
			break;

			case SAILSDESIGN_NATION:
				HideScroller();
				if (hasSailNationLogo) {
					GameInterface.strings.SailsListStr = LanguageConvertString(tmpLangFileID,"National Emblem");
					FileStr[1] += "nation";
					FileStr[2] = PCharNation;
					SailDesc += LanguageConvertString(tmpLangFileID,"sails with national emblem.");
				} else {
					GameInterface.strings.SailsListStr = LanguageConvertString(tmpLangFileID,"Plain");
					FileStr[1] += "plain";
					FileStr[2] = "";
					SailDesc += LanguageConvertString(tmpLangFileID,"sails, without emblem.");
				}
			break;

			case SAILSDESIGN_PIRATE:
				SetListMax();
				if (hasSailPirateLogo) {
					ShowScroller();
					GameInterface.strings.SailsListStr = LanguageConvertString(tmpLangFileID,"Emblem") + " " + (ListNum+1) + " " + LanguageConvertString(tmpLangFileID,"of") + " " + ListMax;
					FileStr[1] += "pirate";
					FileStr[2] = ListNum;
					SailDesc += LanguageConvertString(tmpLangFileID,"sails with pirate emblem.");
				} else {
					HideScroller();
					GameInterface.strings.SailsListStr = LanguageConvertString(tmpLangFileID,"Plain");
					FileStr[1] += "plain";
					FileStr[2] = "";
					SailDesc += LanguageConvertString(tmpLangFileID,"sails, without emblem.");
				}
			break;
		}

		if (curSailType != SAILSTYPE_DEFAULT) FileStr[4] += "plain.tga";
	} else {
		aref arship; makearef(arship, PChar.Ship);
		ref rship = GetShipByType(GetCharacterShipType(PChar));
		FileStr[1] = "";
		FileStr[2] = "";
		FileStr[3] = "";
		FileStr[4] = "";
		if (CheckShipAttribute(arship, rship, "EmblemedSails.normalTex")) FileStr[4] = GetLocalShipAttrib(arship, rship, "EmblemedSails.normalTex");
		if (CheckShipAttribute(arship, rship, "EmblemedSails.nationFileName")) FileStr[1] = GetLocalShipAttrib(arship, rship, "EmblemedSails.nationFileName") + ".tga";
		if (FileStr[1] == "" && FileStr[4] != "") FileStr[1] = FileStr[4];
		if (LowClassShip) FileStr[1] = FileStr[4];
		ShowScroller();
		SetListMax();

		for (ListNum = SAILSTYPE_SPECIAL_COUNT - 1; ListNum > 0 ; ListNum--) {
			if (SpecialSailsNormal[ListNum] == FileStr[4] && SpecialSailsEmblem[ListNum] == FileStr[1]) break;
		}

		if (FileStr[1] == "") FileStr[1] = SpecialSailsEmblem[0];
		if (FileStr[4] == "") FileStr[4] = SpecialSailsNormal[0];

		GameInterface.strings.SailsListStr = LanguageConvertString(tmpLangFileID,"Special Sail") + " " + (ListNum+1) + " " + LanguageConvertString(tmpLangFileID,"of") + " " + ListMax;
		SailDesc = LanguageConvertString(tmpLangFileID, SpecialSailsDescr[ListNum]);
	}
// <-- KK

	SetFormatedText("TEXTWINDOW", SailDesc);
	GameInterface.Strings.SailsFnames = FileStr[1] + FileStr[2] + FileStr[3] + ".tx; " + FileStr[4] + ".tx.";
	if (FindFile(GetResourceDirectory() + "Textures\Ships\Sails", "*.tga.tx", FileStr[1] + FileStr[2] + FileStr[3] + ".tx") == "") {
		GameInterface.Strings.SailsFnames = FileStr[4] + ".tx; " + FileStr[4] + ".tx.";
		FileStr[1] = "Ships\Sails\" + FileStr[4];
		FileStr[2] = "";
		FileStr[3] = "";
		FileStr[4] = "Ships\Sails\" + FileStr[4];
	} else {
		FileStr[1] = "Ships\Sails\" + FileStr[1];
		FileStr[4] = "Ships\Sails\" + FileStr[4];
	}

	SetNewPicture("SAILIMAGE",FileStr[1] + FileStr[2] + FileStr[3]);
	SetNewPicture("DEFAULTSAILIMAGE",FileStr[4]);

	LanguageCloseFile(tmpLangFileID);
}

void SetSails()
{
	string attributename;

// KK -->
	PChar.EmblemedSails.nationFileName = FileStr[1] + FileStr[2] + FileStr[3];
	PChar.EmblemedSails.normalTex = FileStr[4];

	if (CheckAttribute(pchar, "Ship.EmblemedSails.normalTex") || CheckAttribute(pchar, "Ship.EmblemedSails.nationFileName")) DeleteAttribute(pchar, "Ship.EmblemedSails"); // KK
// <-- KK

	InterfaceStates.InstantExit = true;
	ProcessCancelExit();
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();
	if(comName=="activate" || comName=="click")
	{
		if (nodName == "USETHESESAILS_BUTTON")
		{
			SetSails();
		}
// KK -->
		if (nodName == "DEFAULTSAILS_BUTTON")
		{
			// PB: REALLY set the sails to default -->
			ref PChar = GetMainCharacter();
			DeleteAttribute(PChar, "EmblemedSails");

			InterfaceStates.InstantExit = true;
			ProcessCancelExit();
			// PB: REALLY set the sails to default <--
		}
// <-- KK
		if (nodName == "LEFTSCROLLBUTTON")
		{
			ScrollSails(false);
			SetSelectable("USETHESESAILS_BUTTON",true);
			//UpdateDisplay();
		}
		if (nodName == "RIGHTSCROLLBUTTON")
		{
			ScrollSails(true);
			SetSelectable("USETHESESAILS_BUTTON",true);
			//UpdateDisplay();
		}
	}
}

void ShowScroller()
{
	SetNodeUsing("LEFTSCROLLBUTTON",true);
	SetNodeUsing("RIGHTSCROLLBUTTON",true);
}

void HideScroller()
{
	SetNodeUsing("LEFTSCROLLBUTTON",false);
	SetNodeUsing("RIGHTSCROLLBUTTON",false);
}

void ScrollSails(bool ScrollRight)
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	if (ScrollRight) ListNum++; else ListNum--;

	if (ListNum >= ListMax) ListNum = 0;
	if (ListNum < 0) ListNum = ListMax - 1;

	// PB: Fix scrolling through sails appending the folder names ad infinitum -->
	FileStr[1] = strreplace(FileStr[1], "Ships\Sails\", "");
	FileStr[4] = strreplace(FileStr[4], "Ships\Sails\", "");
	// PB: Fix scrolling through sails appending the folder names ad infinitum <--

	string tempstring;
	switch(curSailType)
	{
		case SAILSTYPE_SPECIAL:
			tempstring = LanguageConvertString(tmpLangFileID, "Special Sail") + " ";
			FileStr[1] = SpecialSailsEmblem[ListNum];
			FileStr[2] = "";
			FileStr[3] = "";
			FileStr[4] = SpecialSailsNormal[ListNum];
			SailDesc = LanguageConvertString(tmpLangFileID, SpecialSailsDescr[ListNum]);
		break;

// KK	default:
		FileStr[2] = ListNum;		tempstring = LanguageConvertString(tmpLangFileID,"Emblem") + " ";
	}

	if (LowClassShip) FileStr[1] = FileStr[4];
	SetFormatedText("TEXTWINDOW",SailDesc);
	GameInterface.Strings.SailsFnames = FileStr[1] + FileStr[2] + FileStr[3] + ".tx; " + FileStr[4] + ".tx.";
	if (FindFile(GetResourceDirectory() + "Textures\Ships\Sails", "*.tga.tx", FileStr[1] + FileStr[2] + FileStr[3] + ".tx") == "") {
		GameInterface.Strings.SailsFnames = FileStr[4] + ".tx; " + FileStr[4] + ".tx.";
		FileStr[1] = "Ships\Sails\" + FileStr[4];
		FileStr[2] = "";
		FileStr[3] = "";
		FileStr[4] = "Ships\Sails\" + FileStr[4];
	} else {
		FileStr[1] = "Ships\Sails\" + FileStr[1];
		FileStr[4] = "Ships\Sails\" + FileStr[4];
	}

	SetNewPicture("SAILIMAGE",FileStr[1] + FileStr[2] + FileStr[3]);
	SetNewPicture("DEFAULTSAILIMAGE",FileStr[4]);

	GameInterface.strings.SailsListStr = tempstring + (ListNum+1) + " " + LanguageConvertString(tmpLangFileID,"of") + " " + ListMax;
	SetNewPicture("SAILIMAGE",FileStr[1] + FileStr[2] + FileStr[3]);
	LanguageCloseFile(tmpLangFileID);
}

void SetListMax()
{
	switch(curSailType)
	{
		case SAILSTYPE_SPECIAL:
			ListMax = SAILSTYPE_SPECIAL_COUNT;
		break;

// KK	default:
			switch(curSailDesign)
			{
				case SAILSDESIGN_PIRATE:
					ListMax = 18;
					switch (curSailModel) {
						case SAILSMODEL_WHOLE:
							switch (curSailColor) {
								case SAILSCOLOUR_WHITE:		ListMax = QTY_LOGOSAILS_WHOLE_WHITE;	break;
								case SAILSCOLOUR_RED:		ListMax = QTY_LOGOSAILS_WHOLE_RED;	break;
								case SAILSCOLOUR_BLACK:		ListMax = QTY_LOGOSAILS_WHOLE_BLACK;	break;
								case SAILSCOLOUR_TAN:		ListMax = QTY_LOGOSAILS_WHOLE_TAN;	break;
							}
						break;

						case SAILSMODEL_TORN:
							switch (curSailColor) {
								case SAILSCOLOUR_WHITE:		ListMax = QTY_LOGOSAILS_TORN_WHITE;	break;
								case SAILSCOLOUR_RED:		ListMax = QTY_LOGOSAILS_TORN_RED;	break;
								case SAILSCOLOUR_BLACK:		ListMax = QTY_LOGOSAILS_TORN_BLACK;	break;
								case SAILSCOLOUR_TAN:		ListMax = QTY_LOGOSAILS_TORN_TAN;	break;
							}
						break;
					}
				break;
			}
		break;
	}
}

// KK -->
void IProcMouseClick()
{
	string nodName = GetEventData();
	int btnCode = GetEventData();

	if (nodName == "SAILTYPE_CHANGER") {
		if (btnCode == 0) DoSailTypeChangeLeft();
		if (btnCode == 1) DoSailTypeChangeRight();
	}

	if (nodName == "SAILMODEL_CHANGER") {
		if (btnCode == 0) DoSailModelChangeLeft();
		if (btnCode == 1) DoSailModelChangeRight();
	}

	if (nodName == "SAILCOLOR_CHANGER") {
		if (btnCode == 0) DoSailColorChangeLeft();
		if (btnCode == 1) DoSailColorChangeRight();
	}

	if (nodName == "SAILDESIGN_CHANGER") {
		if (btnCode == 0) DoSailDesignChangeLeft();
		if (btnCode == 1) DoSailDesignChangeRight();
	}

	isSailTypeSpecial = false;
	switch (curSailType) {
		case SAILSTYPE_STANDARD:
			hasSailModelWhole = true;
			hasSailModelTorn = true;
			hasSailColorWhite = true;
			hasSailColorRed = true;
			hasSailColorBlack = true;
			hasSailColorTan = true;
			hasSailNationLogo = true;
			hasSailPirateLogo = true;
		break;
		case SAILSTYPE_PURE_WHITE:
			hasSailModelWhole = false;
			hasSailModelTorn = false;
			hasSailColorWhite = false;
			hasSailColorRed = false;
			hasSailColorBlack = false;
			hasSailColorTan = false;
			hasSailNationLogo = true;
			hasSailPirateLogo = false;
		break;
		case SAILSTYPE_WEATHERED:
			hasSailModelWhole = false;
			hasSailModelTorn = false;
			hasSailColorWhite = false;
			hasSailColorRed = false;
			hasSailColorBlack = false;
			hasSailColorTan = false;
			hasSailNationLogo = true;
			hasSailPirateLogo = false;
		break;
		case SAILSTYPE_SPECIAL:
			isSailTypeSpecial = true;
			hasSailModelWhole = false;
			hasSailModelTorn = false;
			hasSailColorWhite = false;
			hasSailColorRed = false;
			hasSailColorBlack = false;
			hasSailColorTan = false;
			hasSailNationLogo = false;
			hasSailPirateLogo = false;
		break;
	}

	UpdateDisplay();
}

void DoSailTypeChangeLeft()
{
	curSailType--;
	if (curSailType < 0) curSailType = 3;
	curSailModel = SAILSMODEL_WHOLE;
	curSailColor = SAILSCOLOUR_WHITE;
	CurSailDesign = SAILSDESIGN_PLAIN;
	GameInterface.strings.SailTypeName = GetSailTypeNameFromListNumber(curSailType);
}

void DoSailTypeChangeRight()
{
	curSailType++;
	if (curSailType > 3) curSailType = 0;
	curSailModel = SAILSMODEL_WHOLE;
	curSailColor = SAILSCOLOUR_WHITE;
	CurSailDesign = SAILSDESIGN_PLAIN;
	GameInterface.strings.SailTypeName = GetSailTypeNameFromListNumber(curSailType);
}

void DoSailModelChangeLeft()
{
	curSailModel--;
	if (curSailModel < 0) curSailModel = 1;
	if (curSailModel == SAILSMODEL_TORN && hasSailModelTorn == false) { DoSailModelChangeLeft(); return; }
	GameInterface.strings.SailColorName = GetSailModelNameFromListNumber(curSailModel);
}

void DoSailModelChangeRight()
{
	curSailModel++;
	if (curSailModel > 1) curSailModel = 0;
	if (curSailModel == SAILSMODEL_TORN && hasSailModelTorn == false) { curSailModel = SAILSMODEL_WHOLE - 1; DoSailModelChangeRight(); return; }
	GameInterface.strings.SailColorName = GetSailColorNameFromListNumber(curSailColor);
}

void DoSailColorChangeLeft()
{
	curSailColor--;
	if (curSailColor < 0) curSailColor = 3;
	switch (curSailColor) {
		case SAILSCOLOUR_TAN:
			if (!hasSailColorTan) { DoSailColorChangeLeft(); return; }
		break;
		case SAILSCOLOUR_RED:
			if (!hasSailColorRed) { DoSailColorChangeLeft(); return; }
		break;
		case SAILSCOLOUR_BLACK:
			if (!hasSailColorBlack) { DoSailColorChangeLeft(); return; }
		break;
	}
	GameInterface.strings.SailColorName = GetSailColorNameFromListNumber(curSailColor);
}

void DoSailColorChangeRight()
{
	curSailColor++;
	if (curSailColor > 3) curSailColor = 0;
	switch (curSailColor) {
		case SAILSCOLOUR_TAN:
			if (!hasSailColorTan) { DoSailColorChangeRight(); return; }
		break;
		case SAILSCOLOUR_RED:
			if (!hasSailColorRed) { DoSailColorChangeRight(); return; }
		break;
		case SAILSCOLOUR_BLACK:
			if (!hasSailColorBlack) { curSailColor = SAILSCOLOUR_WHITE - 1; DoSailColorChangeRight(); return; }
		break;
	}
	GameInterface.strings.SailColorName = GetSailColorNameFromListNumber(curSailColor);
}

void DoSailDesignChangeLeft()
{
	curSailDesign--;
	if (curSailDesign < 0) curSailDesign = 2;
	switch (CurSailDesign) {
		case SAILSDESIGN_NATION:
			if (!hasSailNationLogo) { DoSailDesignChangeLeft(); return; }
		break;
		case SAILSDESIGN_PIRATE:
			SetListMax();
			if (!hasSailPirateLogo || ListMax == 0) { DoSailDesignChangeLeft(); return; }
		break;
	}
	GameInterface.strings.SailDesignName = GetSailDesignNameFromListNumber(curSailDesign);
}

void DoSailDesignChangeRight()
{
	curSailDesign++;
	if (curSailDesign > 2) curSailDesign = 0;
	switch (CurSailDesign) {
		case SAILSDESIGN_NATION:
			if (!hasSailNationLogo) { DoSailDesignChangeRight(); return; }
		break;
		case SAILSDESIGN_PIRATE:
			SetListMax();
			if (!hasSailPirateLogo || ListMax == 0) { curSailDesign = SAILSDESIGN_PLAIN - 1; DoSailDesignChangeRight(); return; }
		break;
	}
	GameInterface.strings.SailDesignName = GetSailDesignNameFromListNumber(curSailDesign);
}

string GetSailTypeNameFromListNumber(int number)
{
	string tmpstr = "";
	if (number < 0 || number > 3) number = 0;
	switch (number) {
		case SAILSTYPE_STANDARD: tmpstr = "Standard Sails"; break;
		case SAILSTYPE_PURE_WHITE: tmpstr = "Pure White Sails"; break;
		case SAILSTYPE_WEATHERED: tmpstr = "Weathered Sails"; break;
		case SAILSTYPE_SPECIAL: tmpstr = "Special Sails"; break;
	}
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	tmpstr = LanguageConvertString(tmpLangFileID, tmpstr);
	LanguageCloseFile(tmpLangFileID);
	return tmpstr;
}

string GetSailModelNameFromListNumber(int number)
{
	string tmpstr = "";
	if (number < 0 || number > 1) number = 0;
	switch (number) {
		case SAILSMODEL_WHOLE: tmpstr = "Whole Sails"; break;
		case SAILSMODEL_TORN: tmpstr = "Torn Sails"; break;
	}
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	tmpstr = LanguageConvertString(tmpLangFileID, tmpstr);
	LanguageCloseFile(tmpLangFileID);
	return tmpstr;
}

string GetSailColorNameFromListNumber(int number)
{
	string tmpstr = "";
	if (number < 0 || number > 3) number = 0;
	switch (number) {
		case SAILSCOLOUR_WHITE: tmpstr = "White Sails"; break;
		case SAILSCOLOUR_RED: tmpstr = "Crimson Sails"; break;
		case SAILSCOLOUR_BLACK: tmpstr = "Black Sails"; break;
		case SAILSCOLOUR_TAN: tmpstr =     "Tan Sails"; break;
	}
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	tmpstr = LanguageConvertString(tmpLangFileID, tmpstr);
	LanguageCloseFile(tmpLangFileID);
	return tmpstr;
}

string GetSailDesignNameFromListNumber(int number)
{
	string tmpstr = "";
	if (number < 0 || number > 2) number = 0;
	switch (number) {
		case SAILSDESIGN_PLAIN: tmpstr = "Plain"; break;
		case SAILSDESIGN_NATION: tmpstr = "National Emblem"; break;
		case SAILSDESIGN_PIRATE: tmpstr = "Pirate Emblem"; break;
	}
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	tmpstr = LanguageConvertString(tmpLangFileID, tmpstr);
	LanguageCloseFile(tmpLangFileID);
	return tmpstr;
}
// <-- KK

void ProcessCancelExit()
{
	IDoExit(RC_INTERFACE_KAM_SELECTSAILS_EXIT);
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
// KK -->
	DelEventHandler("IEvnt_MouseClick", "IProcMouseClick");
	DelEventHandler("ChangeSailTypeLeft", "DoSailTypeChangeLeft");
	DelEventHandler("ChangeSailTypeRight", "DoSailTypeChangeRight");
	DelEventHandler("ChangeSailModelLeft", "DoSailModelChangeLeft");
	DelEventHandler("ChangeSailModelRight", "DoSailModelChangeRight");
	DelEventHandler("ChangeSailColorLeft", "DoSailColorChangeLeft");
	DelEventHandler("ChangeSailColorRight", "DoSailColorChangeRight");
	DelEventHandler("ChangeSailDesignLeft", "DoSailDesignChangeLeft");
	DelEventHandler("ChangeSailDesignRight", "DoSailDesignChangeRight");
// <-- KK
// added by MAXIMUS [for correct buttons selection] -->
	DelEventHandler("UpPress","UpProcess");
	DelEventHandler("DownPress","DownProcess");
// added by MAXIMUS [for correct buttons selection] <--

    interfaceResultCommand = exitCode;
// MAXIMUS interface MOD -->
/*	if( CheckAttribute(&InterfaceStates,"InstantExit") && sti(InterfaceStates.InstantExit)==true )
	{
		EndCancelInterface(true);
	}
	else
	{
		PostEvent("LaunchIAfterFrame",1,"sl", "I_SELECTMENU", 1);
		EndCancelInterface(false);
	}*/
	    PostEvent("LaunchIAfterFrame",1,"sl", "I_SHIP",1);
	    EndCancelInterface(false);
// MAXIMUS interface MOD <--
}

// added by MAXIMUS [for correct buttons selection] -->
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
		case "DEFAULTSAILS_BUTTON":
			if(GetSelectable("USETHESESAILS_BUTTON")==true) return "USETHESESAILS_BUTTON"; else return NextUp("USETHESESAILS_BUTTON");
		break;
		case "USETHESESAILS_BUTTON":
			if(GetSelectable("DEFAULTSAILS_BUTTON")==true) return "DEFAULTSAILS_BUTTON"; else return NextUp("DEFAULTSAILS_BUTTON");
		break;
	}
	return " ";
}

string NextDown(string curNod)
{
	switch(curNod)
	{
		case "DEFAULTSAILS_BUTTON":
			if(GetSelectable("USETHESESAILS_BUTTON")==true) return "USETHESESAILS_BUTTON"; else return NextDown("USETHESESAILS_BUTTON");
		break;
		case "USETHESESAILS_BUTTON":
			if(GetSelectable("DEFAULTSAILS_BUTTON")==true) return "DEFAULTSAILS_BUTTON"; else return NextDown("DEFAULTSAILS_BUTTON");
		break;
	}
	return " ";
}
// added by MAXIMUS [for correct buttons selection] <--
