#define WINDOW_MAIN          0
#define WINDOW_PIRATEFLAG    1
#define WINDOW_PERSONALFLAG  2

int curWindow;
int pirateflagidx, pirateflagtex, personalflagidx, personalflagtex, tmppirateflagidx, tmppirateflagtex, tmppersonalflagidx, tmppersonalflagtex;
bool hasShip = false;
ref PChar;

void InitInterface(string iniName)
{
	int i, j, cidx;
	string nationpic, sRel;

	PChar = GetMainCharacter();
	PChar.NationsRelations_PreviousNation = GetCurrentFlag(); // PB: Store Original Nation

	InitToolTip();
	AddToolTipNode(TOOLTIP_PICTURE, "TOOLTIP_PICT1");
	AddToolTipNode(TOOLTIP_PICTURE, "TOOLTIP_PICT2");
	AddToolTipNode(TOOLTIP_PICTURE, "TOOLTIP_PICT3");
	AddToolTipNode(TOOLTIP_TEXT, "TOOLTIP_TEXT0");
	AddToolTipNode(TOOLTIP_TEXT, "TOOLTIP_TEXT1");
	AddToolTipNode(TOOLTIP_TEXT, "TOOLTIP_TEXT2");
	AddToolTipNode(TOOLTIP_TEXT, "TOOLTIP_TEXT3");
	AddToolTipPictureImageGroup("CRESTS");
	AddToolTipPictureImageGroup("NATIONS");
	AddToolTipPictureImageGroup("RELATIONS");
	AddToolTipPictureImageGroup("MORALE");
	SetToolTip();

	GameInterface.title = "titleKAMNations";

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

	CreateString(true, "lblRank", TranslateString("", "Rank"), FONT_NORMAL, COLOR_NORMAL, 360, 75, SCRIPT_ALIGN_LEFT, 0.75);
	CreateString(true, "lblPoints", TranslateString("", "Points"), FONT_NORMAL, COLOR_NORMAL, 575, 75, SCRIPT_ALIGN_RIGHT, 0.75);

	for (i = 0; i < NATIONS_QUANTITY; i++)
	{
		if (i == PIRATE)
			nationpic = "Pirate00";
		else
			nationpic = GetFlagPicName(i);
		SetNewPicture("HNATION" + i, "interfaces\flags\Crest_" + nationpic + ".tga");
		SetNodeUsing("HNATION" + i, true);
		SetNodeUsing("_HNATION" + i, true);
	}
	SetNewPicture("HNATIONP", "interfaces\flags\Crest_" + GetFlagPicName(PERSONAL_NATION) + ".tga");

	CreateImage("RelationFromFlag", "MORALE", "high morale", 578, 70, 610, 102);

	for (i = 0; i < NATIONS_QUANTITY; i++)
	{
		if (i == PIRATE)
			nationpic = "Pirate00";
		else
			nationpic = GetFlagPicName(i);
		SetNewPicture("VNATION" + i, "interfaces\flags\Crest_" + nationpic + ".tga");
		SetNodeUsing("VNATION" + i, true);
		SetNodeUsing("_VNATION" + i, true);

		sRel = "Neutral";
		for (j = 0; j < NATIONS_QUANTITY; j++)
		{
			if (j == i) continue;
			switch (GetNationRelation(i, j))
			{
				case RELATION_FRIEND:  sRel = "Friend";  break;
				case RELATION_NEUTRAL: sRel = "Neutral"; break;
				case RELATION_ENEMY:   sRel = "Enemy";   break;
			}
			CreateImage("NationRel" + i + j, "RELATIONS", sRel, 80 + (30 * j), 110 + (32 * i), 110 + (30 * j), 142 + (32 * i));
		}

		CreateImage("NationRel2Me" + i, "", "", 320, 110 + (32 * i), 350, 142 + (32 * i));

		CreateString(true, "MyRank" + i, "", FONT_NORMAL, COLOR_NORMAL, 360, 120 + (32 * i), SCRIPT_ALIGN_LEFT, 0.75);

		CreateString(true, "MyPoints" + i, "", FONT_NORMAL, COLOR_NORMAL, 575, 120 + (32 * i), SCRIPT_ALIGN_RIGHT, 0.75);

		CreateImage("RelFromFlag" + i, "", "", 578, 110 + (32 * i), 610, 142 + (32 * i));

		SetNodeUsing("CHECKBOX_NATION" + i, true);
	}

	CreateString(true, "HoistFlag", TranslateString("", "Hoist flag") + ":", FONT_NORMAL, COLOR_NORMAL, 30, 385, SCRIPT_ALIGN_LEFT, 0.75);

	for (i = 0; i < NATIONS_QUANTITY; i++)
	{
		if (IsFlagSelectable(i) == false && GetCurrentFlag() != i) {
			SetNodeUsing("CHECKBOX_NATION" + i, false);
			continue;
		}
		CreateCheckbox("CHECKBOX_NATION" + i, "", FONT_NORMAL, COLOR_NORMAL, 110 + (50 * i), 385, 1.0, CHECKBOXTYPE_TWOSELECT, CHECKBOX_OFF);

		nationpic = GetFlagPicName(i);
		SetNewPicture("HOISTNATION" + i, "interfaces\flags\Flag_" + nationpic + ".tga");
		SetNodeUsing("HOISTNATION" + i, true);
	}
	if (IsFlagSelectable(PERSONAL_NATION) == true || sti(PChar.nation) == PERSONAL_NATION) {
		CreateCheckbox("CHECKBOX_NATIONP", "", FONT_NORMAL, COLOR_NORMAL, 510, 385, 1.0, CHECKBOXTYPE_TWOSELECT, CHECKBOX_OFF);
		SetNewPicture("HOISTNATIONP", "interfaces\flags\Flag_" + GetFlagPicName(PERSONAL_NATION) + ".tga");
		SetNodeUsing("HOISTNATIONP", true);
	} else {
		SetNodeUsing("CHECKBOX_NATIONP", false);
	}
	if (IsFlagSelectable(NEUTRAL_NATION) == true || GetCurrentFlag() == NEUTRAL_NATION) {
		CreateCheckbox("CHECKBOX_NATIONN", "", FONT_NORMAL, COLOR_NORMAL, 560, 385, 1.0, CHECKBOXTYPE_TWOSELECT, CHECKBOX_OFF);
		SetNodeUsing("HOISTNATIONN", true);
	} else {
		SetNodeUsing("CHECKBOX_NATIONN", false);
	}

	CreateString(true, "KnownAs", GetMySimpleName(PChar) + " " + TranslateString("", "is known as") + ": " + TranslateString("", GetRankNameDirect(PChar, PERSONAL_NATION, GetRankFromPoints(GetScore(PChar)))), FONT_NORMAL, COLOR_NORMAL, 30, 430, SCRIPT_ALIGN_LEFT, 0.75);

// KK -->
	bool hasShip = false;
	for (i = 0; i < COMPANION_MAX; i++) {
		cidx = GetCompanionIndex(PChar, i);
		if (cidx < 0) continue;
		if (GetCharacterShipType(GetCharacter(cidx)) != SHIP_NOTUSED) {
			hasShip = true;
			break;
		}
	}
	SetSelectable("I_SHIPHOLD", !LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm() && hasShip);
	if (hasShip == false && GetBerthedShipsQuantityForTown(GetTownIDFromLocID(PChar.location)) > 0) {
		hasShip = true;
		GameInterface.GoDirectToShipBerthing = true;
		SendMessage(&GameInterface, "lsls", MSG_INTERFACE_MSG_TO_NODE, "I_SHIP", 0, XI_ConvertString("Sel Berth"));
	}
// <-- KK

// MAXIMUS interface MOD -->
	SetSelectable("I_SHIP", !LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm() && hasShip); // KK
	// KK SetSelectable("I_NATIONS",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	SetSelectable("I_TRADEBOOK",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	// PB SetSelectable("I_QUESTBOOK",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	SetSelectable("I_SHIPLOG",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());	
	SetSelectable("EXIT_BUTTON",true);
// MAXIMUS interface MOD <--

	UpdateData();

	if (!bSeaActive && !ownDeckStarted())
	{
		CreateString(true, "FlagText", XI_ConvertString("HoistHelpString"), FONT_NORMAL, COLOR_MONEY, 320, 350, SCRIPT_ALIGN_CENTER, 0.7);
	}
	else
	{
		if(CheckAttribute(PChar, "flaglegend"))		// PB: Show note on Flag-Selection functionality
		{
			CreateString(true, "FlagText", XI_ConvertString("FlagHelpString"), FONT_NORMAL, COLOR_MONEY, 320, 350, SCRIPT_ALIGN_CENTER, 0.7);
			CreateString(true, "HelpText", XI_ConvertString("NationHelpString"), FONT_NORMAL, COLOR_MONEY, 320, 485, SCRIPT_ALIGN_CENTER, 0.7);
			DeleteAttribute(PChar, "flaglegend");	// ... but only once
		}
	}

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
	SetEventHandler("frame","ProcessFrame",1);
}

void ProcessFrame()
{
	if (!bRMouseDown)
		HideToolTip();
	else
		return;
}

void UpdateData()
{
	int PCharNation = GetCurrentFlag();
	bool bIsSelectable = false;
	int iRel, iPoints, prColor, i;
	string attr, sRel;
	for (i = 0; i < NATIONS_QUANTITY; i++)
	{
		iRel = GetNationRelation2MainCharacter(i);
		iPoints = makeint(GetRMRelation(PChar, i));
		switch (iRel)
		{
			case RELATION_FRIEND:  sRel = "Friend";  break;
			case RELATION_NEUTRAL: sRel = "Neutral"; break;
			case RELATION_ENEMY:   sRel = "Enemy";   break;
		}
		attr = "NationRel2Me" + i;
		GameInterface.pictures.(attr).tex = "RELATIONS";
		GameInterface.pictures.(attr).pic = sRel;

		prColor = COLOR_NORMAL;
		if (HaveLetterOfMarque(i) && PromoteCanBe(PChar, i) && GetRMRelation(PChar, i) > RequiredNextRank(PChar, i)) prColor = COLOR_GREEN_LIGHT; // PB: Only show if you actually CAN be promoted

		attr = "MyRank" + i;
		GameInterface.strings.(attr) = TranslateString("", GetRMRelationName(PChar, i));
		ChangeStringColor(attr, prColor);

		attr = "MyPoints" + i;
		GameInterface.strings.(attr) = iPoints;
		ChangeStringColor(attr, prColor);

		if (PCharNation == PERSONAL_NATION) {
			iRel = GetNationRelation2MainCharacter(i);
		} else {
			iRel = GetNationRelation(PCharNation, i);
		}
		switch (iRel)
		{
			case RELATION_FRIEND:  sRel = "Friend";  break;
			case RELATION_NEUTRAL: sRel = "Neutral"; break;
			case RELATION_ENEMY:   sRel = "Enemy";   break;
		}
		attr = "RelFromFlag" + i;
		GameInterface.pictures.(attr).tex = "RELATIONS";
		GameInterface.pictures.(attr).pic = sRel;

		SetCheckBox("CHECKBOX_NATION" + i, CHECKBOX_OFF);
		bIsSelectable = IsFlagSelectable(i));
		SetCheckboxSelectable("CHECKBOX_NATION" + i, bIsSelectable);
		SetNodeUsing("CHECKBOX_NATION" + i, bIsSelectable);

		if (PCharNation == i) {
			SetCheckBox("CHECKBOX_NATION" + i, CHECKBOX_SET);
			SetCheckboxSelectable("CHECKBOX_NATION" + i, false);
		}
	}
	if (PCharNation == PERSONAL_NATION) {
		SetCheckBox("CHECKBOX_NATIONP", CHECKBOX_SET);
		SetCheckboxSelectable("CHECKBOX_NATIONP", false);
		SetNodeUsing("CHECKBOX_NATIONP", false);
	} else {
		SetCheckBox("CHECKBOX_NATIONP", CHECKBOX_OFF);
		bIsSelectable = IsFlagSelectable(PERSONAL_NATION);
		SetCheckboxSelectable("CHECKBOX_NATIONP", bIsSelectable);
		SetNodeUsing("CHECKBOX_NATIONP", bIsSelectable);
	}
	if (PCharNation == NEUTRAL_NATION) {
		SetCheckBox("CHECKBOX_NATIONN", CHECKBOX_SET);
		SetCheckboxSelectable("CHECKBOX_NATIONN", false);
		SetNodeUsing("CHECKBOX_NATIONN", false);
	} else {
		SetCheckBox("CHECKBOX_NATIONN", CHECKBOX_OFF);
		SetCheckboxSelectable("CHECKBOX_NATIONN", bChangeNation);
		SetNodeUsing("CHECKBOX_NATIONN", bChangeNation);
	}
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();
	int iNation, cn, i, j;
	string n;

	if (bRMouseDown) {
		if (comName == "click") ShowInfo(nodName);
		return;
	}

	if(nodName=="PIRATEFLAG_BUTTON")
	{
		if (comName == "activate" || comName == "click") {
			SetWindow(WINDOW_PIRATEFLAG);
		}
	}

	if(nodName=="PERSONALFLAG_BUTTON")
	{
		if (comName == "activate" || comName == "click") {
			SetWindow(WINDOW_PERSONALFLAG);
		}
	}

	if(nodName=="DIALOG_SELECT_BUTTON")
	{
		if (comName == "activate" || comName == "click") {
			switch (curWindow)
			{
				case WINDOW_PIRATEFLAG:
					pirateflagtex = tmppirateflagtex;
					pirateflagidx = tmppirateflagidx;
					PChar.Flags.Pirate = pirateflagidx;
					PChar.Flags.Pirate.texture = pirateflagtex;
					SetNewPicture("HOISTNATION3", "interfaces\flags\Flag_" + GetFlagPicName(PIRATE) + ".tga");
				break;
				case WINDOW_PERSONALFLAG:
					personalflagtex = tmppersonalflagtex;
					personalflagidx = tmppersonalflagidx;
					PChar.Flags.Personal = personalflagidx;
					PChar.Flags.Personal.texture = personalflagtex;
					SetNewPicture("HOISTNATIONP", "interfaces\flags\Flag_" + GetFlagPicName(PERSONAL_NATION) + ".tga");
				break;
			}
			SetWindow(WINDOW_MAIN);
			SetCurrentNode("I_TRADEBOOK");
		}
		if (comName == "deactivate") {
			SetWindow(WINDOW_MAIN);
		}
	}

	if (strleft(nodName, 11) == "FLAG_BUTTON") {
		if (comName == "activate" || comName == "click") {
			SetSelectable("DIALOG_SELECT_BUTTON", true);
			SetCurrentNode("DIALOG_SELECT_BUTTON");
			i = sti(GameInterface.SELECTOR.i);
			j = sti(GameInterface.SELECTOR.j);
			SetNodeUsing("FLAG_BUTTON" + i + j, true);
			i = sti(getSymbol(nodName, 11));
			j = sti(getSymbol(nodName, 12));
			GameInterface.SELECTOR.i = i;
			GameInterface.SELECTOR.j = j;
			XI_MarkFlag(i, j);
			SetNodeUsing("FLAG_BUTTON" + i + j, false);
			switch (curWindow)
			{
				case WINDOW_PIRATEFLAG:
					tmppirateflagtex = j;
					tmppirateflagidx = i;
				break;
				case WINDOW_PERSONALFLAG:
					tmppersonalflagtex = j;
					tmppersonalflagidx = i;
				break;
			}
		}
		return;
	}

	if (strleft(nodName, 15) == "CHECKBOX_NATION") {
		if (comName == "activate" || comName == "click") {
			n = strRight(nodName, 1);
			switch (n)
			{
				case "P":
					iNation = PERSONAL_NATION;
				break;
				case "N":
					iNation = NEUTRAL_NATION;
				break;
				// default:
					iNation = sti(n);
				break;
			}
			PChar.nation = iNation; // PB: Set New Nation
			UpdateData();
			return;
		}
	}

// MAXIMUS interface MOD -->
	if(nodName=="I_CHARACTER")
	{
		if(comName=="activate" || comName=="click")
		{
			UpdateChangedFlag(); //Levis
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_NATIONRELATION_EXIT;
			EndCancelInterface(false);
		}
	}
	if(nodName=="I_SHIP")
	{
		if(comName=="activate" || comName=="click")
		{
			UpdateChangedFlag(); //Levis
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_NATIONRELATION_EXIT;
			EndCancelInterface(false);
		}
	}
	if(nodName=="I_SHIPHOLD")
	{
		if(comName=="activate" || comName=="click")
		{
			UpdateChangedFlag(); //Levis
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_NATIONRELATION_EXIT;
			EndCancelInterface(false);
		}
	}
	if(nodName=="I_PASSENGER")
	{
		if(comName=="activate" || comName=="click")
		{
			UpdateChangedFlag(); //Levis
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_NATIONRELATION_EXIT;
			EndCancelInterface(false);
		}
	}
	if(nodName=="I_QUESTBOOK")
	{
		if(comName=="activate" || comName=="click")
		{
			UpdateChangedFlag(); //Levis
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_NATIONRELATION_EXIT;
			EndCancelInterface(false);
		}
	}
	if(nodName=="I_TRADEBOOK")
	{
		if(comName=="activate" || comName=="click")
		{
			UpdateChangedFlag(); //Levis
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_NATIONRELATION_EXIT;
			EndCancelInterface(false);
		}
	}
	if(nodName=="I_SHIPLOG")
	{
		if(comName=="activate" || comName=="click")
		{
			UpdateChangedFlag(); //Levis
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_NATIONRELATION_EXIT;
			EndCancelInterface(false);
		}
	}
	if(nodName=="I_ITEMS")
	{
		if(comName=="activate" || comName=="click")
		{
			UpdateChangedFlag(); //Levis
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_NATIONRELATION_EXIT;
			EndCancelInterface(false);
		}
	}
// MAXIMUS interface MOD <--

}

void ProcessCancelExit()
{
	if (curWindow != WINDOW_MAIN) {
		SetWindow(WINDOW_MAIN);
		SetCurrentNode("I_TRADEBOOK");
		return;
	}
	IDoExit(RC_INTERFACE_NATIONRELATION_EXIT);
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcessCommandExecute");
	DelEventHandler("frame","ProcessFrame");

	//Levis moved to function so it can be called at multiple places
	UpdateChangedFlag(); //Levis

    interfaceResultCommand = exitCode;
// MAXIMUS interface MOD -->
	EndCancelInterface(true);
// MAXIMUS interface MOD <--
	if (bSeaActive) RefreshBattleInterface(true); // TIH helps to refresh minimap colours if relation changed Aug27'06
}

void UpdateChangedFlag()
{
	// PB: Update Changed Flag -->
	ref PChar = GetMainCharacter();
	if (PChar.nation != PChar.NationsRelations_PreviousNation)
	{
		HoistFlag(PChar.nation);
	}
	else
	{
		DeleteAttribute(PChar, "NationsRelations_PreviousNation");
	}
	// PB: Update Changed Flag <--
}

bool IsFlagSelectable(int iNation)
{
	// PB: ALWAYS allow changing flag, though which flag you fly may affect the consequences of your actions
/*	if (bSeaActive) {
		if (bMapEnter)
			return bChangeNation;
		else
			return false;
	}*/
	if (!bSeaActive && !ownDeckStarted()) return false; // PB: Allow only on deck or at sea
	if (iNation == NEUTRAL_NATION) return false; // PB: Unfinished feature, better disable for now
	return bChangeNation;
}

void SetWindow(int iWindow)
{
	int i, j;
	switch (curWindow)
	{	
		case WINDOW_MAIN:
			SetSelectable("EXIT_BUTTON", false);
			SetSelectable("I_CHARACTER", false);
			SetSelectable("I_SHIP", false);
			SetSelectable("I_PASSENGER", false);
			SetSelectable("I_QUESTBOOK", false);
			SetSelectable("I_SHIPLOG", false);
			SetSelectable("I_TRADEBOOK", false);
			SetSelectable("I_NATIONS", false);
			SetSelectable("I_ITEMS", false);
			for (i = 0; i < NATIONS_QUANTITY; i++)
			{
				SetSelectable("CHECKBOX_NATION" + i, false);
				SetSelectable("_HNATION" + i, false);
				SetSelectable("_VNATION" + i, false);
			}
			SetSelectable("CHECKBOX_NATIONP", false);
			SetSelectable("CHECKBOX_NATIONN", false);
			SetSelectable("PIRATE_FLAG_BUTTON", false);
			SetSelectable("PERSONAL_FLAG_BUTTON", false);
			SetSelectable("_RELATIONS", false);
			SetSelectable("_ATTITUDE", false);
			SetSelectable("_RANKS", false);
			SetSelectable("_RELFLAG", false);
		break;
		case WINDOW_PIRATEFLAG:
			SetNodeUsing("TOOLTIP_FADER", false);
			SetNodeUsing("DIALOG_WINDOW", false);
			SetNodeUsing("WINDOWSTRINGES", false);
			SetNodeUsing("TITLE_WINDOW", false);
			SetNodeUsing("EXIT_WINDOW_BUTTON", false);
			SetNodeUsing("DIALOG_SELECT_BUTTON", false);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "Title", "", FONT_TITLE, 320, 110, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SetNodeUsing("SELECTOR1", false);
			for (j = 0; j < PIRATEFLAGS_TEXTURES_QUANTITY; j++)
			{
				for (i = 0; i < FLAGS_PICTURES_QUANTITY_PER_TEXTURE; i++)
				{
					SetNodeUsing("FLAG_BUTTON" + i + j, false);
					SetNodeUsing("FLAG_PICTURE" + i + j, false);
				}
			}
		break;
		case WINDOW_PERSONALFLAG:
			SetNodeUsing("TOOLTIP_FADER", false);
			SetNodeUsing("DIALOG_WINDOW", false);
			SetNodeUsing("WINDOWSTRINGES", false);
			SetNodeUsing("TITLE_WINDOW", false);
			SetNodeUsing("EXIT_WINDOW_BUTTON", false);
			SetNodeUsing("DIALOG_SELECT_BUTTON", false);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "Title", "", FONT_TITLE, 320, 110, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SetNodeUsing("SELECTOR1", false);
			for (j = 0; j < PERSONALFLAGS_TEXTURES_QUANTITY; j++)
			{
				for (i = 0; i < FLAGS_PICTURES_QUANTITY_PER_TEXTURE; i++)
				{
					SetNodeUsing("FLAG_BUTTON" + i + j, false);
					SetNodeUsing("FLAG_PICTURE" + i + j, false);
				}
			}
		break;
	}
	curWindow = iWindow;
	switch (curWindow)
	{	
		case WINDOW_MAIN:
			SetSelectable("EXIT_BUTTON", true);
			SetSelectable("I_CHARACTER", true);
			SetSelectable("I_SHIP", true);
			SetSelectable("I_PASSENGER", true);
			SetSelectable("I_QUESTBOOK", true);
			SetSelectable("I_SHIPLOG", true);
			SetSelectable("I_TRADEBOOK", true);
			SetSelectable("I_NATIONS", true);
			SetSelectable("I_ITEMS", true);
			for (i = 0; i < NATIONS_QUANTITY; i++)
			{
				SetSelectable("CHECKBOX_NATION" + i, true);
				SetSelectable("_HNATION" + i, true);
				SetSelectable("_VNATION" + i, true);
			}
			SetSelectable("CHECKBOX_NATIONP", true);
			SetSelectable("CHECKBOX_NATIONN", true);
			SetSelectable("PIRATE_FLAG_BUTTON", true);
			SetSelectable("PERSONAL_FLAG_BUTTON", true);
			SetSelectable("_RELATIONS", true);
			SetSelectable("_ATTITUDE", true);
			SetSelectable("_RANKS", true);
			SetSelectable("_RELFLAG", true);
		break;
		case WINDOW_PIRATEFLAG:
			pirateflagtex = PChar.Flags.Pirate.texture;
			pirateflagidx = PChar.Flags.Pirate;
			SetNodeUsing("TOOLTIP_FADER", true);
			SetNodeUsing("DIALOG_WINDOW", true);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "Title", "PIRATE FLAG", FONT_TITLE, 320, 110, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SetNodeUsing("WINDOWSTRINGES", true);
			SetNodeUsing("EXIT_WINDOW_BUTTON", true);
			SetNodeUsing("DIALOG_SELECT_BUTTON", true);
			SetSelectable("DIALOG_SELECT_BUTTON", false);
			SetNodeUsing("SELECTOR1", true);
			for (j = 0; j < PIRATEFLAGS_TEXTURES_QUANTITY; j++)
			{
				for (i = 0; i < FLAGS_PICTURES_QUANTITY_PER_TEXTURE; i++)
				{
					if (i != pirateflagidx || j != pirateflagtex)
						SetNodeUsing("FLAG_BUTTON" + i + j, true);
					else
						XI_MarkFlag(i, j);
					SetNewPicture("FLAG_PICTURE" + i + j, "INTERFACES\Flags\Flag_Pirate" + i + j + ".tga");
					SetNodeUsing("FLAG_PICTURE" + i + j, true);
				}
			}
		break;
		case WINDOW_PERSONALFLAG:
			personalflagtex = PChar.Flags.Personal.texture;
			personalflagidx = PChar.Flags.Personal;
			SetNodeUsing("TOOLTIP_FADER", true);
			SetNodeUsing("DIALOG_WINDOW", true);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "Title", "PERSONAL FLAG", FONT_TITLE, 320, 110, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SetNodeUsing("WINDOWSTRINGES", true);
			SetNodeUsing("EXIT_WINDOW_BUTTON", true);
			SetNodeUsing("DIALOG_SELECT_BUTTON", true);
			SetSelectable("DIALOG_SELECT_BUTTON", false);
			SetNodeUsing("SELECTOR1", true);
			for (j = 0; j < PERSONALFLAGS_TEXTURES_QUANTITY; j++)
			{
				for (i = 0; i < FLAGS_PICTURES_QUANTITY_PER_TEXTURE; i++)
				{
					if (i != personalflagidx || j != personalflagtex)
						SetNodeUsing("FLAG_BUTTON" + i + j, true);
					else
						XI_MarkFlag(i, j);
					SetNewPicture("FLAG_PICTURE" + i + j, "INTERFACES\Flags\Flag_Personal" + i + j + ".tga");
					SetNodeUsing("FLAG_PICTURE" + i + j, true);
				}
			}
		break;
	}
	UpdateData();
}

void XI_MarkFlag(int i, int j)
{
	GameInterface.SELECTOR.i = i;
	GameInterface.SELECTOR.j = j;
	SendMessage(&GameInterface, "lsllllll", MSG_INTERFACE_MSG_TO_NODE, "SELECTOR1", 0, 70 + (i * 74), 150 + (j * 30), 86 + (i * 74), 166 + (j * 30), 0);
}

void ShowInfo(string nodName)
{
	string header = "";
	string text = "";
	string img = "";
	string sNation;
	int iNation;
	int ilngid = LanguageOpenFile("InterfaceDescribe.txt");
	if (getSymbol(nodName, 0) == "_") {
		switch (nodName)
		{
			case "_RELATIONS":
				header = LanguageConvertString(ilngid, "Relations_Header");
				text = LanguageConvertString(ilngid, "Relations_Descr");
				SetToolTipRectangle("");
				SetToolTipHeader("", header);
				SetToolTipText("TOOLTIP_TEXT0", text);
				SetToolTipPicture("TOOLTIP_PICT1", "RELATIONS", "enemy");
				SetToolTipText("TOOLTIP_TEXT1", "- " + XI_ConvertString("Hostile"));
				SetToolTipPicture("TOOLTIP_PICT2", "RELATIONS", "neutral");
				SetToolTipText("TOOLTIP_TEXT2", "- " + XI_ConvertString("Neutral"));
				SetToolTipPicture("TOOLTIP_PICT3", "RELATIONS", "friend");
				SetToolTipText("TOOLTIP_TEXT3", "- " + XI_ConvertString("Alliance"));
			break;
			case "_ATTITUDE":
				header = LanguageConvertString(ilngid, "Attitude_Header");
				Preprocessor_Add("PChar", GetMySimpleName(PChar));
				text = PreprocessText(LanguageConvertString(ilngid, "Attitude_Descr"));
				SetToolTipRectangle("");
				SetToolTipHeader("", header);
				SetToolTipText("TOOLTIP_TEXT0", text);
				SetToolTipPicture("", "CRESTS", GetFlagPicName(PERSONAL_NATION));
				SetToolTipPicture("TOOLTIP_PICT1", "RELATIONS", "enemy");
				SetToolTipText("TOOLTIP_TEXT1", "- " + XI_ConvertString("Hostile"));
				SetToolTipPicture("TOOLTIP_PICT2", "RELATIONS", "neutral");
				SetToolTipText("TOOLTIP_TEXT2", "- " + XI_ConvertString("Neutral"));
				SetToolTipPicture("TOOLTIP_PICT3", "RELATIONS", "friend");
				SetToolTipText("TOOLTIP_TEXT3", "- " + XI_ConvertString("Alliance"));
				Preprocessor_Remove("PChar");
			break;
			case "_RANKS":
				header = LanguageConvertString(ilngid, "Ranks_Header");
				Preprocessor_Add("PChar", GetMySimpleName(PChar));
				text = PreprocessText(LanguageConvertString(ilngid, "Ranks_Descr"));
				SetToolTipRectangle("");
				SetToolTipHeader("", header);
				SetToolTipText("TOOLTIP_TEXT0", text);
				Preprocessor_Remove("PChar");
			break;
			case "_RELFLAG":
				header = LanguageConvertString(ilngid, "RelFlag_Header");
				Preprocessor_Add("PChar", GetMySimpleName(PChar));
				text = PreprocessText(LanguageConvertString(ilngid, "RelFlag_Descr"));
				SetToolTipRectangle("");
				SetToolTipHeader("", header);
				SetToolTipText("TOOLTIP_TEXT0", text);
				SetToolTipPicture("TOOLTIP_PICT1", "RELATIONS", "enemy");
				SetToolTipText("TOOLTIP_TEXT1", "- " + XI_ConvertString("Hostile"));
				SetToolTipPicture("TOOLTIP_PICT2", "RELATIONS", "neutral");
				SetToolTipText("TOOLTIP_TEXT2", "- " + XI_ConvertString("Neutral"));
				SetToolTipPicture("TOOLTIP_PICT3", "RELATIONS", "friend");
				SetToolTipText("TOOLTIP_TEXT3", "- " + XI_ConvertString("Alliance"));
				SetToolTipPicture("", "MORALE", "high morale");
				Preprocessor_Remove("PChar");
			break;
			// default:
				if (strcut(nodName, 1, strlen(nodName) - 2) == "HNATION" || strcut(nodName, 1, strlen(nodName) - 2) == "VNATION") {
					sNation = getSymbol(nodName, strlen(nodName) - 1);
					iNation = sti(sNation);
					header = XI_ConvertString(GetNationOfficialNameByType(iNation));
					if (getSymbol(nodName, 1) == "H")
						Preprocessor_Add("Column_Row", TranslateString("", "column"));
					else
						Preprocessor_Add("Column_Row", TranslateString("", "row"));
					Preprocessor_Add("NationOf", XI_ConvertString(GetNationDescByType(iNation)));
					if (iNation == PIRATE)
						img = "Pirate00";
					else
						img = GetFlagPicName(iNation);
					text = PreprocessText(LanguageConvertString(ilngid, "Nation_Descr"));
					SetToolTipRectangle("");
					SetToolTipHeader("", header);
					SetToolTipText("", text);
					SetToolTipImage("", "interfaces\flags\Crest_" + img + ".tga");
					Preprocessor_Remove("Column_Row");
					Preprocessor_Remove("FlagOf");
				}
			break;
		}
	}
	if (strLeft(nodName, 15) == "CHECKBOX_NATION") {
		header = LanguageConvertString(ilngid, "Checkbox_Nation_Header");
		sNation = getSymbol(nodName, strlen(nodName) - 1);
		switch (sNation)
		{
			case "P":
				Preprocessor_Add("FlagOf", TranslateString("", "your own"));
				img = GetFlagPicName(PERSONAL_NATION);
			break;
			case "N":
				Preprocessor_Add("FlagOf", TranslateString("", "neutral"));
				img = "Neutral";
			break;
			// default:
			iNation = sti(sNation);
			Preprocessor_Add("FlagOf", XI_ConvertString(GetNationDescByType(iNation)));
			img = GetFlagPicName(iNation);
		}
		text = PreprocessText(LanguageConvertString(ilngid, "Checkbox_Nation_Descr"));
		SetToolTipRectangle("");
		SetToolTipHeader("", header);
		SetToolTipText("", text);
		SetToolTipImage("", "interfaces\flags\Flag_" + img + ".tga");
		Preprocessor_Remove("FlagOf");
	}
	if (nodName == "PIRATEFLAG_BUTTON" || nodName == "PERSONALFLAG_BUTTON") {
		header = LanguageConvertString(ilngid, "Change_Flag_Header");
		sNation = getSymbol(nodName, strlen(nodName) - 1);
		switch (nodName)
		{
			case "PIRATEFLAG_BUTTON":
				Preprocessor_Add("FlagOf", TranslateString("", "pirate"));
				img = GetFlagPicName(PIRATE);
			break;
			case "PERSONALFLAG_BUTTON":
				Preprocessor_Add("FlagOf", TranslateString("", "personal"));
				img = GetFlagPicName(PERSONAL_NATION);
			break;
		}
		text = PreprocessText(LanguageConvertString(ilngid, "Change_Flag_Descr"));
		SetToolTipRectangle("");
		SetToolTipHeader("", header);
		SetToolTipText("", text);
		SetToolTipImage("", "interfaces\flags\Flag_" + img + ".tga");
		Preprocessor_Remove("FlagOf");
	}
	LanguageCloseFile(ilngid);
	ShowToolTip();
}
