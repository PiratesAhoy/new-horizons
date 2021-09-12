#define WINDOW_MAIN          0
#define WINDOW_CHARACTER     1
#define WINDOW_SHIP          2
#define WINDOW_NATION        3
#define WINDOW_PIRATEFLAG    4
#define WINDOW_PERSONALFLAG  5
#define WINDOW_PLAYERTYPE    6
#define WINDOW_LOCATION      7

#define OUTFITSEX_ANY   0
#define OUTFITSEX_MAN   1
#define OUTFITSEX_WOMAN 2

#define OUTFITMODEL_ANY       0
#define OUTFITMODEL_POOR      1
#define OUTFITMODEL_LOW       2
#define OUTFITMODEL_MIDDLE    3
#define OUTFITMODEL_RICH      4
#define OUTFITMODEL_SAILOR    5
#define OUTFITMODEL_OFFICER   6
#define OUTFITMODEL_NAVY      7
#define OUTFITMODEL_SOLDIER   8
#define OUTFITMODEL_LANDOFF   9
#define OUTFITMODEL_NATIVE   10
#define OUTFITMODEL_SKELETON 11

#define OUTFITNAMED_ANY        0
#define OUTFITNAMED_SPECIFIC   1
#define OUTFITNAMED_NAMED      2
#define OUTFITNAMED_UNNAMED    3

#define OUTFITOFFTYPE_ANY       0
#define OUTFITOFFTYPE_CAPTAIN   1
#define OUTFITOFFTYPE_FIRSTMATE 2
#define OUTFITOFFTYPE_BOATSWAIN 3
#define OUTFITOFFTYPE_CANNONEER 4
#define OUTFITOFFTYPE_QMASTER   5
#define OUTFITOFFTYPE_NAVIGATOR 6
#define OUTFITOFFTYPE_CARPENTER 7
#define OUTFITOFFTYPE_DOCTOR    8
#define OUTFITOFFTYPE_ABORDAGE  9

#define SHIPTYPENAME_ANY   0
#define SHIPTYPENAME_WAR   1
#define SHIPTYPENAME_TRADE 2
#define SHIPTYPENAME_BOTH  3

int slno;
int curWindow;
int curOutfit, curOutfitSex, curOutfitModel, curOutfitOffType, curOutfitNation, curOutfitNamed, tmpOutfit;
int curShip, curShipClass, curShipModel, curShipType, curShipNation, tmpShip;
int curPeriod, curLocation, curPort;
int tmpNation;
int pirateflagidx, pirateflagtex, personalflagidx, personalflagtex, tmppirateflagidx, tmppirateflagtex, tmppersonalflagidx, tmppersonalflagtex
int curPlayerType, tmpPlayerType;
int iNationsQuantity = 6;

int initialOutfit = -1;
int initialShip = -1;
int idShipDescr = -1;
int idModelDescr = -1;

int tmpCharSkills[NUM_DIFF_SKILLS];
float tmpCharBonusSkills[NUM_DIFF_SKILLS];

string ProfileName;
aref arstart;
string tmpName = ""; //MAXIMUS 17.05.2019: needed for localization

object tmpNames;
ref rShipModel;

int shipclass_max = 6;

void InitInterface(string iniName)
{
	string attr;
	ref rName; makeref(rName, tmpNames);

	GetLanguageParameters(); // MAXIMUS 30.07.2006
	GameInterface.title = "";

	GameInterface.SHIP.current = 0;
	GameInterface.SHIP.ImagesGroup.t0 = "ICONS";
	GameInterface.SHIP.ImagesGroup.t1 = "SHIPS16";
	GameInterface.SHIP.ImagesGroup.t2 = "SHIPS1";
	GameInterface.SHIP.ImagesGroup.t3 = "SHIPS2";
	GameInterface.SHIP.ImagesGroup.t4 = "SHIPS3";
	GameInterface.SHIP.ImagesGroup.t5 = "SHIPS4";
	GameInterface.SHIP.ImagesGroup.t6 = "SHIPS5";
	GameInterface.SHIP.pic1.str1 = "";
	GameInterface.SHIP.pic1.img1 = "ship back";
	GameInterface.SHIP.pic1.tex1 = 0;
	GameInterface.SHIP.pic1.str2 = "";
	GameInterface.SHIP.pic1.img2 = "";
	GameInterface.SHIP.pic1.tex2 = -1;
	GameInterface.SHIP.ListSize = 1;
	GameInterface.SHIP.NotUsed = 1;

	GameInterface.SELECTPICT.current = 0;
	if (bNewInterface)
		GameInterface.SELECTPICT.ImagesGroup.t0 = "EMPTYFACE_NEW";
	else
		GameInterface.SELECTPICT.ImagesGroup.t0 = "EMPTYFACE";
	GameInterface.SELECTPICT.ImagesGroup.t1 = "ICONS";
	GameInterface.SELECTPICT.ImagesGroup.t2 = "SHIPS16";
	GameInterface.SELECTPICT.ImagesGroup.t3 = "SHIPS1";
	GameInterface.SELECTPICT.ImagesGroup.t4 = "SHIPS2";
	GameInterface.SELECTPICT.ImagesGroup.t5 = "SHIPS3";
	GameInterface.SELECTPICT.ImagesGroup.t6 = "SHIPS4";
	GameInterface.SELECTPICT.ImagesGroup.t7 = "SHIPS5";
	GameInterface.SELECTPICT.BadTex1 = 0;
	GameInterface.SELECTPICT.BadPic1 = "emptyface";
	GameInterface.SELECTPICT.pic1.str1 = "";
	GameInterface.SELECTPICT.pic1.img1 = "";
	GameInterface.SELECTPICT.pic1.tex1 = 0;
	GameInterface.SELECTPICT.pic1.str2 = "";
	GameInterface.SELECTPICT.pic1.img2 = "";
	GameInterface.SELECTPICT.pic1.tex2 = -1;
	GameInterface.SELECTPICT.ListSize = 1;
	GameInterface.SELECTPICT.NotUsed = 1;

	for (slno = 0; slno < NUM_DIFF_SKILLS; slno++)
	{
		tmpCharSkills[slno] = 1;
		tmpCharBonusSkills[slno] = 1.0;
	}

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

	slno = FindDefaultStoryline();
	ProfileName = DEFAULT_PROFILE_NAME;

	arstart = GetStorylineStartParams(slno);

	curOutfit = GetModelIndex(arstart.model);
	tmpOutfit = curOutfit;
	curOutfitSex = OUTFITSEX_ANY;
	curOutfitModel = OUTFITMODEL_ANY;
	curOutfitOffType = OUTFITOFFTYPE_ANY;
	curOutfitNation = -1;
	curOutfitNamed = OUTFITNAMED_ANY;
	initialOutfit = -1;
	attr = arstart.model;
	rName.(attr) = "";
	//MAXIMUS 17.05.2019: ==>
	if (CheckAttribute(arstart, "name") == true && arstart.name != "") { arstart.old.name = arstart.name; rName.(attr) = GetTranslatedStoryLine(slno, arstart.name); }
	if (CheckAttribute(arstart, "middlename") == true && arstart.middlename != "") { arstart.old.middlename = arstart.middlename; rName.(attr) = rName.(attr) + " " + GetTranslatedStoryLine(slno, arstart.middlename); }
	if (CheckAttribute(arstart, "lastname") == true && arstart.lastname != "") { arstart.old.lastname = arstart.lastname; rName.(attr) = rName.(attr) + " " + GetTranslatedStoryLine(slno, arstart.lastname); }
	//MAXIMUS 17.05.2019: <==

	curShip = -1;
	if (CheckAttribute(arstart, "ship"))
		curShip = GetShipIndex(arstart.ship);
	else
		CharShipName = "";
	tmpShip = curShip;
	curShipClass = -1;
	curShipType = SHIPTYPENAME_ANY;
	curShipModel = -1;
	curShipNation = -1;
	initialShip = -1;

	CharYear = sti(arstart.date.year);
	CharMonth = sti(arstart.date.month);
	CharDay = sti(arstart.date.day);
	CharHour = sti(arstart.date.hour);
	CharMinute = sti(arstart.date.min);
	CharSecond = sti(arstart.date.sec);
	curPeriod = GetPeriodFromYear(CharYear);
	curPort = -1;
	if (CheckAttribute(arstart, "port")) curPort = FindLocation(arstart.port);
	curLocation = curPort;
	if (CheckAttribute(arstart, "location")) curLocation = FindLocation(arstart.location);
	SetSelectable("SELECTOR1", false);
	SetSelectable("SELECTOR2", false);
	SetNodeUsing("LOCATION_BUTTON", false);				// PB: Unfinished

	curPlayerType = PLAYER_TYPE_MERCHANT;
	tmpPlayerType = curPlayerType;

	makeref(rShipModel, ShipModels);

	idShipDescr = LanguageOpenFile("ShipModels_descriptions.txt");
	idModelDescr = LanguageOpenFile("models_description.txt");

	curWindow = -1;
	SetWindow(WINDOW_MAIN);

	CreateString(true, "ScreenTitle", XI_ConvertString("titleSelectStoryline"), FONT_TITLE, COLOR_NORMAL, 320, 5, SCRIPT_ALIGN_CENTER, 1.0);
	CreateString(true, "StorylineTitle", GetStorylineTitle(slno), FONT_NORMAL, COLOR_NORMAL, 320, 84, SCRIPT_ALIGN_CENTER, 1.0);
	CreateString(true, "lblProfile", TranslateString("", "Profile") + ":", FONT_NORMAL, COLOR_NORMAL, 200, 245, SCRIPT_ALIGN_LEFT, 0.7);
	//CreateString(true, "StartDate", "", FONT_NORMAL, COLOR_NORMAL, 200, 270, SCRIPT_ALIGN_LEFT, 0.7); //Levis
	CreateString(true, "StartLocation", TranslateString("", "unknown"), FONT_NORMAL, COLOR_NORMAL, 320, 308, SCRIPT_ALIGN_CENTER, 0.7); //Levis
	CreateString(true, "LblNation", TranslateString("", "Nation") + ":", FONT_NORMAL, COLOR_NORMAL, 200, 327, SCRIPT_ALIGN_LEFT, 0.7);
	CreateString(true, "LblFlags", TranslateString("", "Flags") + ":", FONT_NORMAL, COLOR_NORMAL, 320, 327, SCRIPT_ALIGN_LEFT, 0.7);
	CreateString(true, "lblPlayerType", TranslateString("", "Player type") + ":", FONT_NORMAL, COLOR_NORMAL, 200, 350, SCRIPT_ALIGN_LEFT, 0.7);
	CreateString(true, "PlayerType", TranslateString("", GetPlayerTypeName(curPlayerType)), FONT_NORMAL, COLOR_NORMAL, 395, 350, SCRIPT_ALIGN_CENTER, 0.7);
	CreateString(true, "lblDifficulty", TranslateString("", "Difficulty") + ":", FONT_NORMAL, COLOR_NORMAL, 230, 380, SCRIPT_ALIGN_LEFT, 0.7);
	CreateString(true, "Difficulty", TranslateString("", GetDifficultyName(CharDifficulty)), FONT_NORMAL, COLOR_NORMAL, 345, 380, SCRIPT_ALIGN_CENTER, 0.7);
	CreateString(true, "HelpText", XI_ConvertString("SelectStorylineCustomize"), FONT_NORMAL, COLOR_NORMAL, 320, 465, SCRIPT_ALIGN_CENTER, 1.0);
	//Levis custom startdate:
	CreateString(true, "StartYear", CharYear, FONT_NORMAL, COLOR_NORMAL, 420, 268, SCRIPT_ALIGN_CENTER, 0.7);
	CreateString(true, "StartDay", CharDay, FONT_NORMAL, COLOR_NORMAL, 368, 268, SCRIPT_ALIGN_CENTER, 0.7);
	CreateString(true, "StartMonth", GetMonthName(CharMonth), FONT_NORMAL, COLOR_NORMAL, 260, 268, SCRIPT_ALIGN_LEFT, 0.7);
	CreateString(true, "LblData", "Date:", FONT_NORMAL, COLOR_NORMAL, 200, 268, SCRIPT_ALIGN_LEFT, 0.7);
	CreateString(true, "LblPeriod", "Period:", FONT_NORMAL, COLOR_NORMAL, 200, 289, SCRIPT_ALIGN_LEFT, 0.7);
	CreateString(true, "StartPeriod", TranslateString("", GetPeriodName(curPeriod)), FONT_NORMAL, COLOR_NORMAL, 250, 289, SCRIPT_ALIGN_LEFT, 0.7);
	//Levis custom startdate end

	SetFormatedText("INFO_TEXT", GetTranslatedStoryLine(slno, GetStorylineDescription(slno))); //MAXIMUS 17.05.2019: needed for localization
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"INFO_TEXT",5);

	CreateTextbox(true, "Profile", "PROFILE_TEXTBOX", "PROFILE_BORDER", "", "", 345, 240, 1.0);
	CreateTextbox(true, "CharacterName", "CHARNAME_TEXTBOX", "BOX1", "RAMKA1", "", 124, 375, 1.0);
	CreateTextbox(true, "ShipName", "SHIPNAME_TEXTBOX", "BOX2", "RAMKA2", "", 516, 375, 1.0);
	CreateTextbox(false, "SearchText", "SEARCH_TEXTBOX", "BOX3", "RAMKA3", "", 500, 368, 0.8);

	if (GetStorylinesQuantity() == 1) {
		SetNodeUsing("STORYLINE", false);
		SetNodeUsing("RAMKA", true);
		SetNodeUsing("BOX", true);
	}

	slno = FindDefaultStoryline()+1;
	ChangeStoryline(false);

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcCommand",0);
	SetEventHandler("IEvnt_MouseClick", "IProcMouseClick", 0);
	SetEventHandler("UpStep", "DoUpStep", 0);
	SetEventHandler("DownStep", "DoDownStep", 0);
	SetEventHandler("StartGame", "GameStart", 0);
}

void ProcessCancelExit()
{
	if (curWindow != WINDOW_MAIN) {
		SetWindow(WINDOW_MAIN);
		SetCurrentNode("START_GAME_BUTTON");
		return;
	}
	IDoExit(RC_INTERFACE_SELECT_STORYLINE_EXIT, false);
	ReturnToMainMenu();
}

void IDoExit(int exitCode, bool bRelease)
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcCommand");
	DelEventHandler("IEvnt_MouseClick", "IProcMouseClick");
	DelEventHandler("UpStep", "DoUpStep");
	DelEventHandler("DownStep", "DoDownStep");
	DelEventHandler("StartGame", "GameStart");

	if (CheckAttribute(&GameInterface, "SELECTOR1")) DeleteAttribute(&GameInterface, "SELECTOR1");
	if (idShipDescr >= 0)  LanguageCloseFile(idShipDescr);
	if (idModelDescr >= 0) LanguageCloseFile(idModelDescr);

	interfaceResultCommand = exitCode;
	EndCancelInterface(bRelease);
}

void ProcCommand()
{
	int i, j;
	string comName = GetEventData();
	string nodName = GetEventData();

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
				case WINDOW_NATION:
					switch (i)
					{
						case 1:
							if (j >= PIRATE) j++;
							tmpNation = j;
						break;
						case 4:
							if (j == 0) tmpNation = PIRATE;
							if (j == 1) tmpNation = PERSONAL_NATION;
						break;
					}
				break;
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

	if (strleft(nodName, 12) == "SKILL_BUTTON") {
		if (comName == "activate" || comName == "click") {
			ProcessSkillsSpeed(sti(getSymbol(nodName, 12)));
		}
		return;
	}

	switch (nodName) {
		case "STORYLINE":
			if (comName == "leftstep") {
				ChangeStoryline(false);
			}
			if (comName == "rightstep") {
				ChangeStoryline(true);
			}
		break;

		case "CHARNAME_TEXTBOX":
			if (comName == "activate" || comName == "click") {
				ActivateTextbox("CharacterName");
			}
		break;

		case "SHIPNAME_TEXTBOX":
			if (comName == "activate" || comName == "click") {
				ActivateTextbox("ShipName");
			}
		break;

		case "PROFILE_TEXTBOX":
			if (comName == "activate" || comName == "click") {
				ActivateTextbox("Profile");
			}
		break;

		case "LOCATION_BUTTON":
			if (comName == "activate" || comName == "click") {
				SetWindow(WINDOW_LOCATION);
			}
		break;

		case "NATIONFLAG_BUTTON":
			if (comName == "activate" || comName == "click") {
				GameInterface.strings.SearchText = "";
				Event("SearchText_Refresh");
				SetWindow(WINDOW_NATION);
			}
		break;

		case "PIRATEFLAG_BUTTON":
			if (comName == "activate" || comName == "click") {
				GameInterface.strings.SearchText = "";
				Event("SearchText_Refresh");
				SetWindow(WINDOW_PIRATEFLAG);
			}
		break;

		case "PERSONALFLAG_BUTTON":
			if (comName == "activate" || comName == "click") {
				GameInterface.strings.SearchText = "";
				Event("SearchText_Refresh");
				SetWindow(WINDOW_PERSONALFLAG);
			}
		break;

		case "DIFFICULTY":
			if (comName == "leftstep") {
				ChangeDifficulty(false);
			}
			if (comName == "rightstep") {
				ChangeDifficulty(true);
			}
		break;

		//Levis custom startdate -->
		case "DAY":
			if (comName == "leftstep") {
				ChangeStartDate(0,0,-1);
			}
			if (comName == "rightstep") {
				ChangeStartDate(0,0,1);
			}
		break;

		case "MONTH":
			if (comName == "leftstep") {
				ChangeStartDate(0,-1,0);
			}
			if (comName == "rightstep") {
				ChangeStartDate(0,1,0);
			}
		break;

		case "YEAR":
			if (comName == "leftstep") {
				ChangeStartDate(-1,0,0);
			}
			if (comName == "rightstep") {
				ChangeStartDate(1,0,0);
			}
		break;
		//Levis Custom Startdate <--

		case "DEFAULT_CHARACTER_BUTTON":
			if (comName == "activate" || comName == "click") {
				tmpOutfit = curOutfit;
				GameInterface.strings.SearchText = "";
				Event("SearchText_Refresh");
				SetWindow(WINDOW_CHARACTER);
			}
		break;

		case "SELECT1_SCROLLBAR":
			if (comName == "leftstep") {
				if (curWindow == WINDOW_CHARACTER) ChangeOutfitSex(false);
				if (curWindow == WINDOW_SHIP) ChangeShipClass(false);

			}
			if (comName == "rightstep") {
				if (curWindow == WINDOW_CHARACTER) ChangeOutfitSex(true);
				if (curWindow == WINDOW_SHIP) ChangeShipClass(true);
			}
		break;

		case "SELECT2_SCROLLBAR":
			if (comName == "leftstep") {
				if (curWindow == WINDOW_CHARACTER) ChangeOutfitModel(false);
				if (curWindow == WINDOW_SHIP) ChangeShipModel(false);
			}
			if (comName == "rightstep") {
				if (curWindow == WINDOW_CHARACTER) ChangeOutfitModel(true);
				if (curWindow == WINDOW_SHIP) ChangeShipModel(true);
			}
		break;

		case "SELECT3_SCROLLBAR":
			if (comName == "leftstep") {
				if (curWindow == WINDOW_CHARACTER) ChangeOutfitOffType(false);
				if (curWindow == WINDOW_SHIP) ChangeShipType(false);
			}
			if (comName == "rightstep") {
				if (curWindow == WINDOW_CHARACTER) ChangeOutfitOffType(true);
				if (curWindow == WINDOW_SHIP) ChangeShipType(true);
			}
		break;

		case "SELECT4_SCROLLBAR":
			if (comName == "leftstep") {
				if (curWindow == WINDOW_CHARACTER) ChangeOutfitNation(false);
				if (curWindow == WINDOW_SHIP) ChangeShipNation(false);
			}
			if (comName == "rightstep") {
				if (curWindow == WINDOW_CHARACTER) ChangeOutfitNation(true);
				if (curWindow == WINDOW_SHIP) ChangeShipNation(true);
			}
		break;

		case "SELECT5_SCROLLBAR":
			if (comName == "leftstep") {
				if (curWindow == WINDOW_CHARACTER) ChangeOutfitNamed(false);
			}
			if (comName == "rightstep") {
				if (curWindow == WINDOW_CHARACTER) ChangeOutfitNamed(true);
			}
		break;

		case "SEARCH_TEXTBOX":
			if (comName == "activate" || comName == "click") {
				SetEventHandler("KB_End", "SearchText_End", 0);
				SetEventHandler("KB_Esc", "SearchText_End", 0);
				SetEventHandler("KB_Update", "SearchText_Update", 0);
				ActivateTextbox("SearchText");
			}
		break;

		case "PLAYERTPYPESCROLLBAR":
			if (comName == "leftstep") {
				ChangePlayerType(false);
			}
			if (comName == "rightstep") {
				ChangePlayerType(true);
			}
		break;

		case "DIALOG_SELECT_BUTTON":
			if (comName == "activate" || comName == "click") {
				switch (curWindow)
				{
					case WINDOW_CHARACTER:
						curOutfit = tmpOutfit;
					break;
					case WINDOW_SHIP:
						curShip = tmpShip;
					break;
					case WINDOW_NATION:
						CharNation = tmpNation;
					break;
					case WINDOW_PIRATEFLAG:
						pirateflagtex = tmppirateflagtex;
						pirateflagidx = tmppirateflagidx;
					break;
					case WINDOW_PERSONALFLAG:
						personalflagtex = tmppersonalflagtex;
						personalflagidx = tmppersonalflagidx;
					break;
					case WINDOW_PLAYERTYPE:
						if (CheckAttribute(&GameInterface, "CustomSkill.Value.v1")) DeleteAttribute(&GameInterface, "CustomSkill.Value.v1");
						if (CheckAttribute(&GameInterface, "CustomSkill.Value.v2")) DeleteAttribute(&GameInterface, "CustomSkill.Value.v2");
						if (CheckAttribute(&GameInterface, "CustomSkill.Speed.s1")) DeleteAttribute(&GameInterface, "CustomSkill.Speed.s1");
						if (CheckAttribute(&GameInterface, "CustomSkill.Speed.s2")) DeleteAttribute(&GameInterface, "CustomSkill.Speed.s2");
						for (i = 0; i < NUM_DIFF_SKILLS; i++)
						{
							CharSkills[i] = tmpCharSkills[i];
							CharBonusSkills[i] = tmpCharBonusSkills[i];
							if (CharSkills[i] > 1) {
								if (!CheckAttribute(&GameInterface, "CustomSkill.Value.v1"))
									GameInterface.CustomSkill.Value.v1 = i;
								else
									GameInterface.CustomSkill.Value.v2 = i;
							}
							if (CharBonusSkills[i] > 1) {
								if (!CheckAttribute(&GameInterface, "CustomSkill.Speed.s1"))
									GameInterface.CustomSkill.Speed.s1 = i;
								else
									GameInterface.CustomSkill.Speed.s2 = i;
							}
						}
						curPlayerType = tmpPlayerType;
					break;
					case WINDOW_LOCATION:
					break;
				}
				SetWindow(WINDOW_MAIN);
				SetCurrentNode("START_GAME_BUTTON");
			}
			if (comName == "deactivate") {
				SetWindow(WINDOW_MAIN);
			}
		break;

		case "SHIP":
			if (comName == "activate" || comName == "click") {
				tmpShip = curShip;
				GameInterface.strings.SearchText = "";
				Event("SearchText_Refresh");
				SetWindow(WINDOW_SHIP);
			}
		break;

		case "MESSAGEBOX_BUTTON_YES":
			if (comName == "activate" || comName == "click") {
				ProcessStartGameConfirm_yes();
			}
			if (comName == "deactivate") {
				ProcessStartGameConfirm_no();
			}
		break;

		case "MESSAGEBOX_BUTTON_NO":
			if (comName == "activate" || comName == "click" || comName == "deactivate") {
				ProcessStartGameConfirm_no();
			}
		break;

		case "PLAYERTYPE_BUTTON":
			if (comName == "activate" || comName == "click") {
				SetWindow(WINDOW_PLAYERTYPE);
			}
		break;
	}
}

void GameStart()
{
	if (!CheckProfiles(GameInterface.strings.Profile)) {
		ProcessStartGameConfirm();
		return;
	}
	ProcessStartGame();
}

void ProcessStartGameConfirm()
{
	SetNodeUsing("MESSAGEBOX", true);
	SetNodeUsing("MESSAGEBOX_TEXT", true);
	SetNodeUsing("MESSAGEBOX_BUTTON_NO", true);
	SetNodeUsing("MESSAGEBOX_BUTTON_YES", true);
	SetFormatedText("MESSAGEBOX_TEXT", TranslateString("", "Delete profile with all saved games and create new one?"));
	SetCurrentNode("MESSAGEBOX_BUTTON_NO");
	SendMessage(&GameInterface, "lls", MSG_INTERFACE_LOCK_NODE, 1, "MESSAGEBOX_BUTTON_NO");
	SendMessage(&GameInterface, "lls", MSG_INTERFACE_LOCK_NODE, 2, "MESSAGEBOX_BUTTON_YES");
}

void ProcessStartGameConfirm_yes()
{
	ProcessStartGameConfirm_no();
	DeleteProfile(GetStoryline(slno), GameInterface.strings.Profile);
	ProcessStartGame();
}

void ProcessStartGameConfirm_no()
{
	SetNodeUsing("MESSAGEBOX", false);
	SetNodeUsing("MESSAGEBOX_TEXT", false);
	SetNodeUsing("MESSAGEBOX_BUTTON_NO", false);
	SetNodeUsing("MESSAGEBOX_BUTTON_YES", false);
	SetCurrentNode("START_GAME_BUTTON");
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
}

void ProcessStartGame()
{
	ref model;
	CreateProfile(GetStoryline(slno), GameInterface.strings.Profile);
	SetCurrentProfile(GetStoryline(slno), GameInterface.strings.Profile);

	SetCurrentStoryline(slno);
	musicName = "";
	oldMusicName = "";
	//ResetSoundScheme();
	ResetSound();
	StopSound(0,0);
	ReleaseSound(0);
	// PB: Prevent overriding this later -->
	CharFirstName = tmpName; //MAXIMUS 17.05.2019: needed for localization ==>
	if(CheckAttribute(GameInterface, "strings.CharacterName.named")==true)
	{
		characters[GetMainCharacterIndex()].named = true;
		CharFirstName = GameInterface.strings.CharacterName;
	} //MAXIMUS 17.05.2019: <==
	CharMiddleName = "";
	CharLastName = "";
	CharOldFirstName = "";
	CharOldMiddleName = "";
	CharOldLastName = "";
	// PB: Prevent overriding this later <--

	makeref(model, Models[curOutfit]);
	CharModel = model.id;
	CharSex = model.sex;
	CharAni = model.ani;
	CharStore = GetTownStoreIndex(GetTownIDFromLocID(arstart.port));
	if (curShip >= 0) {
		CharShipName = GameInterface.strings.ShipName;
		CharShipType = ShipsTypes[curShip].id;
	} else {
		CharShipType = SHIP_NOTUSED_TYPE_NAME;
	}
	CharPirateFlagTex = pirateflagtex;
	CharPirateFlag = pirateflagidx;
	CharPersonalFlagTex = personalflagtex;
	CharPersonalFlag = personalflagidx;
	CharLocation = 0;

	// PB: Apply Player Type -->
	SetupPlayerType();
	CharPlayerType = tmpPlayerType;
	for (int s = 0; s < NUM_DIFF_SKILLS; s++) {
		CharSkills[s]		= tmpCharSkills[s];
		CharBonusSkills[s]	= tmpCharBonusSkills[s];
	}
	// PB: Apply Player Type <--

	LaunchGame();
	IDoExit(RC_INTERFACE_SELECT_STORYLINE_EXIT, true);
}

void IProcMouseClick()
{
	string nodName = GetEventData();
	int btnCode = GetEventData();

	if (strleft(nodName, 13) == "SKILL_CHANGER") {
		ProcessSkillsValue(sti(getSymbol(nodName, 13)), btnCode == 1);
		return;
	}

	if (nodName == "STORYLINE") {
		ChangeStoryline(btnCode == 1);
		return;
	}

	if (nodName == "DIFFICULTY") {
		ChangeDifficulty(btnCode == 1);
		return;
	}

	if (nodName == "SELECT_CHANGER") {
		if (curWindow == WINDOW_CHARACTER) {
			ChangeOutfit(btnCode == 1);
			return;
		}
		if (curWindow == WINDOW_SHIP) {
			ChangeShip(btnCode == 1);
			return;
		}
		return;
	}
}

void ChangeStoryline(bool bRight)
{
	int idx;
	string id;

	if (bRight) {
		slno++;
		if (slno >= GetStorylinesQuantity()) slno = 0;
	}	else {
		slno--;
		if (slno < 0) slno = GetStorylinesQuantity() - 1;
	}

	GameInterface.strings.StorylineTitle = GetTranslatedStoryLine(slno, GetStorylineTitle(slno)); //MAXIMUS 17.05.2019: needed for localization
	SetFormatedText("INFO_TEXT", GetTranslatedStoryLine(slno, GetStorylineDescription(slno))); //MAXIMUS 17.05.2019: needed for localization
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"INFO_TEXT",5);

	arstart = GetStorylineStartParams(slno);

	curOutfit = GetModelIndex(arstart.model);
	curOutfitModel = OUTFITMODEL_ANY;
	curOutfitOffType = OUTFITOFFTYPE_ANY;
	curOutfitNation = -1;
	if (slno == FindStoryline("FreePlay"))
	{
		curOutfitSex = OUTFITSEX_ANY;
		curOutfitNamed = OUTFITNAMED_SPECIFIC;
	}
	else
	{
		curOutfitSex = OUTFITSEX_MAN;
		curOutfitNamed = OUTFITNAMED_NAMED;
	}
	initialOutfit = -1;

	CharNation = PERSONAL_NATION;
	if (CheckAttribute(arstart, "nation")) CharNation = sti(arstart.nation);
	pirateflagtex = 0;
	pirateflagidx = 0;
	personalflagtex = 0;
	personalflagidx = 0;
	if (CheckAttribute(arstart, "Flags")) {
		if (CheckAttribute(arstart, "Flags.Pirate")) {
			pirateflagtex = makeint(stf(arstart.Flags.Pirate) % makefloat(FLAGS_PICTURES_QUANTITY_PER_TEXTURE));
			pirateflagidx = sti(arstart.Flags.Pirate) - (pirateflagtex * makeint(FLAGS_PICTURES_QUANTITY_PER_TEXTURE));
		}
		if (CheckAttribute(arstart, "Flags.Personal")) {
			personalflagtex = makeint(stf(arstart.Flags.Personal) % makefloat(FLAGS_PICTURES_QUANTITY_PER_TEXTURE));
			personalflagidx = sti(arstart.Flags.Personal) - (personalflagtex * makeint(FLAGS_PICTURES_QUANTITY_PER_TEXTURE));
		}
	}

	switch(sti(GetAttribute(arstart, "freedom_level")))
	{
		case 0:
			CreateString(true, "HelpText", XI_ConvertString("SelectStorylineFreePlayOnly"), FONT_NORMAL, COLOR_GREEN_LIGHT, 320, 470, SCRIPT_ALIGN_CENTER, 1.0);
		break;
		case 1:
			CreateString(true, "HelpText", XI_ConvertString("SelectStorylineFreeOpening"), FONT_NORMAL, COLOR_GREEN_LIGHT, 320, 470, SCRIPT_ALIGN_CENTER, 1.0);
		break;
		case 2:
			CreateString(true, "HelpText", XI_ConvertString("SelectStorylineLocked"), FONT_NORMAL, COLOR_MONEY, 320, 470, SCRIPT_ALIGN_CENTER, 1.0);
		break;
		case 3:
			CreateString(true, "HelpText", XI_ConvertString("SelectStorylineNoFreePlay"), FONT_NORMAL, COLOR_RED_LIGHT, 320, 470, SCRIPT_ALIGN_CENTER, 1.0);
		break;
		CreateString(true, "HelpText", XI_ConvertString("SelectStorylineCustomize"), FONT_NORMAL, COLOR_NORMAL, 320, 470, SCRIPT_ALIGN_CENTER, 1.0);
	}

	shipclass_max = 5; // JRMM
	if (slno == FindDefaultStoryline()) shipclass_max = 6;
	if (ENABLE_CHEATMODE) shipclass_max = 1; // PB

	if (CheckAttribute(arstart, "date.year"))	CharYear   = sti(arstart.date.year);
	if (CheckAttribute(arstart, "date.month"))	CharMonth  = sti(arstart.date.month);
	if (CheckAttribute(arstart, "date.day"))	CharDay    = sti(arstart.date.day);
	if (CheckAttribute(arstart, "date.hour"))	CharHour   = sti(arstart.date.hour);
	if (CheckAttribute(arstart, "date.min"))	CharMinute = sti(arstart.date.min);
	if (CheckAttribute(arstart, "date.sec"))	CharSecond = sti(arstart.date.sec);

	curPeriod = GetPeriodFromYear(CharYear);
	SetCurrentPeriod(curPeriod);
	iNationsQuantity = CheckNationsQuantity(curPeriod);

	//Levis custom start date -->
	GameInterface.strings.StartYear = CharYear;
	GameInterface.strings.StartMonth = GetMonthName(CharMonth);
	GameInterface.strings.StartDay = CharDay;
	GameInterface.strings.StartPeriod = GetPeriodName(curPeriod);
	bool canchangedate = true;
	if(CheckAttribute(arstart,"date.lock")) canchangedate = false;
	SetNodeUsing("YEAR", canchangedate);
	SetNodeUsing("MONTH", canchangedate);
	SetNodeUsing("DAY", canchangedate);
	//Levis custom startdate <--

	Storylines.current = slno;

	if (CheckAttribute(arstart, "model")) {
		id = arstart.model;
		idx = GetModelIndex(id);
		if (idx < 0) {
			id = "Blaze";
			idx = GetModelIndex(id);
		}
		if (CheckAttribute(arstart, "name") && CheckAttribute(arstart, "lastname")) {
			CharFirstName = arstart.name;
			CharOldFirstName = CharFirstName;
			CharLastName = arstart.lastname;
			CharOldLastName = CharLastName;
		} else {
			CharFirstName = "Nathaniel";
			CharOldFirstName = CharFirstName;
			CharLastName = "Hawk";
			CharOldLastName = CharLastName;
		}
		if (CheckAttribute(arstart, "middlename")) {
			CharMiddleName = arstart.middlename;
			CharOldMiddleName = CharMiddleName;
		} else {
			CharMiddleName = "";
			CharOldMiddleName = "";
		}
		//MAXIMUS 17.05.2019: needed for localization ==>
		GiveHimName(&arstart);

		GameInterface.strings.CharacterName = CharFirstName + " ";
		if (CharMiddleName != "") GameInterface.strings.CharacterName = GameInterface.strings.CharacterName + CharMiddleName + " ";
		GameInterface.strings.CharacterName = GameInterface.strings.CharacterName + CharLastName;
	}

	curShip = -1;
	if (CheckAttribute(arstart, "ship"))
	{
		curShip = GetShipIndex(arstart.ship);
		if (CheckAttribute(arstart, "shipname"))	GameInterface.strings.ShipName = arstart.shipname;
		else										GameInterface.strings.ShipName = "";
	}
	else
		GameInterface.strings.ShipName = "";
	tmpShip = curShip;
	curShipClass = -1;
	curShipType = SHIPTYPENAME_ANY;
	curShipModel = -1;
	curShipNation = -1;
	initialShip = -1;

	if (CheckAttribute(&GameInterface, "CustomSkill")) DeleteAttribute(&GameInterface, "CustomSkill");
	GameInterface.CustomSkill.Value.v1 = rand(9);
	GameInterface.CustomSkill.Speed.s1 = sti(GameInterface.CustomSkill.Value.v1);
	GameInterface.CustomSkill.Value.v2 = sti(GameInterface.CustomSkill.Value.v1);
	GameInterface.CustomSkill.Speed.s2 = sti(GameInterface.CustomSkill.Speed.s1);
	while (sti(GameInterface.CustomSkill.Value.v2) == sti(GameInterface.CustomSkill.Value.v1))
	{
		GameInterface.CustomSkill.Value.v2 = rand(9);
		GameInterface.CustomSkill.Speed.s2 = sti(GameInterface.CustomSkill.Value.v2);
	}
//aref artmp;makearef(artmp, GameInterface.CustomSkill);DumpAttributes(artmp);
	if (CheckAttribute(arstart, "playertype"))
		curPlayerType = sti(arstart.playertype);
	else
		curPlayerType = PLAYER_TYPE_MERCHANT;
	if (CheckAttribute(arstart, "difficulty"))	CharDifficulty = sti(arstart.difficulty);
	else										CharDifficulty = 1;
	GameInterface.strings.PlayerType = TranslateString("", GetPlayerTypeName(curPlayerType));
	tmpPlayerType = curPlayerType;

	SetWindow(WINDOW_MAIN);
	RefreshScreen();
}

void RefreshScreen()
{
	string island, town, id;
	int idx = -1;
	int faceid = -1;
	ref model, rName;

	switch (curWindow)
	{
		case WINDOW_MAIN:
			GameInterface.strings.SearchText = "";
			Refresh_SearchText();
			SetNewPicture("DEFAULT_CHARACTER", "interfaces\empty_face.tga");
			GameInterface.strings.Profile = ProfileName;
			if(!CheckAttribute(GameInterface, "strings.CharacterName"))	GameInterface.strings.CharacterName = "";
			if(!CheckAttribute(GameInterface, "strings.ShipName"))		GameInterface.strings.ShipName = "";
			GameInterface.SHIP.pic1.str1 = "";
			GameInterface.SHIP.pic1.img1 = "ship back";
			GameInterface.SHIP.pic1.tex1 = 0;
			GameInterface.SHIP.pic1.str2 = "";
			GameInterface.SHIP.pic1.img2 = "ship back";
			GameInterface.SHIP.pic1.tex2 = 0;
			SendMessage(&GameInterface, "ls", MSG_INTERFACE_REFRESH_SCROLL, "SHIP");
			//GameInterface.strings.StartDate = TranslateString("", "unknown"); //Levis
			//GameInterface.strings.StartLocation = TranslateString("", "unknown"); //Levis

			makeref(model, Models[curOutfit]);
			faceid = model.FaceId;
			if (faceid >= 0)
				SetNewPicture("DEFAULT_CHARACTER", "interfaces\portraits\256\face_" + faceid + ".tga");
			else
				SetNewPicture("DEFAULT_CHARACTER", "interfaces\empty_face.tga");
			id = model.id;
			makeref(rName, tmpNames);
			if (CheckAttribute(rName, id) == true && rName.(id) != "" ) {	// If model DOES have a name set
				GameInterface.strings.CharacterName = rName.(id);								// Use that instead of the one already there
			}
			// PB: Model-based options -->
			if(GetAttribute(GameInterface, "character") == true)
			{
				GameInterface.character = false;
				bool IsNotLocked;
				if (slno == FindStoryline("FreePlay"))
				{
					IsNotLocked = CheckAttribute(arstart, "ship.lock") == false || sti(arstart.ship.lock) == false);
					if (CheckAttribute(model, "ship") && IsNotLocked)
					{
						curShip = GetShipIndex(model.ship);
					}
					IsNotLocked = CheckAttribute(arstart, "shipname.lock") == false || sti(arstart.shipname.lock) == false);
					if (CheckAttribute(model, "shipname") && IsNotLocked)
					{
						GameInterface.strings.ShipName = model.shipname;
					}
				}
				IsNotLocked = CheckAttribute(arstart, "Flags.Pirate.lock") == false || sti(arstart.Flags.Pirate.lock) == false);
				if (CheckAttribute(model, "Flags.Pirate") && IsNotLocked)
				{
					pirateflagtex = makeint(stf(model.Flags.Pirate) % makefloat(FLAGS_PICTURES_QUANTITY_PER_TEXTURE));
					pirateflagidx = sti(model.Flags.Pirate) - (pirateflagtex * makeint(FLAGS_PICTURES_QUANTITY_PER_TEXTURE));
				}
				IsNotLocked = CheckAttribute(arstart, "Flags.Personal.lock") == false || sti(arstart.Flags.Personal.lock) == false);
				if (CheckAttribute(model, "Flags.Personal") && IsNotLocked)
				{
					personalflagtex = makeint(stf(model.Flags.Personal) % makefloat(FLAGS_PICTURES_QUANTITY_PER_TEXTURE));
					personalflagidx = sti(model.Flags.Personal) - (personalflagtex * makeint(FLAGS_PICTURES_QUANTITY_PER_TEXTURE));
				}
				IsNotLocked = CheckAttribute(arstart, "nation.lock") == false || sti(arstart.nation.lock) == false);
				if (CheckAttribute(model, "nation") && IsNotLocked)
				{
					CharNation = sti(model.nation);
				}
				IsNotLocked = CheckAttribute(arstart, "playertype.lock") == false || sti(arstart.playertype.lock) == false);
				if (CheckAttribute(model, "playertype") && IsNotLocked)
				{
					curPlayerType = sti(model.playertype);
				}
				IsNotLocked = CheckAttribute(arstart, "difficulty.lock") == false || sti(arstart.difficulty.lock) == false);
				if (CheckAttribute(model, "difficulty") && IsNotLocked)
				{
					CharDifficulty = sti(model.difficulty);
				}
				IsNotLocked = CheckAttribute(arstart, "date.lock") == false || sti(arstart.date.lock) == false);
				if (CheckAttribute(model, "date") && IsNotLocked)
				{
					if (CheckAttribute(model, "date.year") && IsNotLocked)
					{
						if (CheckAttribute(model, "date.year"))		CharYear	= sti(model.date.year);
						if (CheckAttribute(model, "date.month"))	CharMonth	= sti(model.date.month);
						if (CheckAttribute(model, "date.day"))		CharDay		= sti(model.date.day);
						if (CheckAttribute(model, "date.hour"))		CharHour	= sti(model.date.hour);
						if (CheckAttribute(model, "date.min"))		CharMinute	= sti(model.date.min);
						if (CheckAttribute(model, "date.sec"))		CharSecond	= sti(model.date.sec);
					}

					curPeriod = GetPeriodFromYear(CharYear);
					SetCurrentPeriod(curPeriod);
					iNationsQuantity = CheckNationsQuantity(curPeriod);

					GameInterface.strings.StartYear = CharYear;
					GameInterface.strings.StartMonth = TranslateString("", GetMonthName(CharMonth)); //MAXIMUS 17.05.2019: needed for localization
					GameInterface.strings.StartDay = CharDay;
					GameInterface.strings.StartPeriod = TranslateString("", GetPeriodName(curPeriod)); //MAXIMUS 17.05.2019: needed for localization
				}
				if (slno == FindStoryline("FreePlay") && CheckAttribute(model, "storytext"))
				{
					SetFormatedText("INFO_TEXT", model.storytext);
				}
				else
				{
					SetFormatedText("INFO_TEXT", GetStorylineDescription(slno));
				}
				if (slno == FindStoryline("FreePlay") && CheckAttribute(model, "storytitle"))
				{
					GameInterface.strings.StorylineTitle = model.storytitle;
				}
				else
				{
					GameInterface.strings.StorylineTitle = GetStorylineTitle(slno);
				}
			}
			// PB: Model-based options <--
			if (curShip >= 0) {
				GameInterface.SHIP.pic1.str1 = "#" + ShipsTypes[curShip].Class;
				GameInterface.SHIP.pic1.str2 = ShipsTypes[curShip].SName;
				GameInterface.SHIP.pic1.img2 = GetShipPicName(curShip);
				GameInterface.SHIP.pic1.tex2 = 1 + GetShipTexture(curShip); // PB
				SendMessage(&GameInterface, "ls", MSG_INTERFACE_REFRESH_SCROLL, "SHIP");
				CharShipName = GameInterface.strings.ShipName;
				SetTextBoxReadOnly("ShipName", false);
			} else {
				CharShipName = "";
				SetTextBoxReadOnly("ShipName", true);
			}

			//GameInterface.strings.StartDate = TranslateString("", GetPeriodName(curPeriod)) + " - " + GetHumanDate(CharYear, CharMonth, CharDay); //Levis
			if (CheckAttribute(arstart, "location")) {
				int lidx = FindLocation(arstart.location);
				id = "";
				bool LocationOverride = false;
				if (lidx == FindLocation("Tutorial_Deck") && CheckAttribute(Locations[lidx], "id.label") == true) {
					id = TranslateString("", Locations[lidx].id.label) + ", ";
					switch(CharNation)
					{
						case PERSONAL_NATION:	lidx = FindLocation("Oxbay_port");					break; // PB: was arstart.port
						case ENGLAND:			lidx = FindLocation("Oxbay_port");					break;
						case FRANCE:			lidx = FindLocation("Falaise_de_fleur_port_01");	break;
						case SPAIN:				lidx = FindLocation("Muelle_port");					break;
						case PIRATE:			lidx = FindLocation("QC_port");						break;
						case HOLLAND:			lidx = FindLocation("Douwesen_port");				break;
						case PORTUGAL:			lidx = FindLocation("Conceicao_port");				break;
						case AMERICA:			lidx = FindLocation("Eleuthera_Port");				break;
					}
					// PB: Player Type -->
					if (slno == FindStoryline("FreePlay"))
					{
						NavyLockShipSelection(false, model);
						if (NationNoIsland(CharNation, curPeriod))
							lidx = FindLocation("QC_port");

						switch(curPlayerType)
						{
							case PLAYER_TYPE_REBEL:
								lidx = FindLocation("QC_port");										// Rebels always start at Nevis
							break;

							case PLAYER_TYPE_ROGUE:
								lidx = FindLocation("Cuba_shore_03");								// La Croix opening scene
							break;

							case PLAYER_TYPE_GAMBLER:
								lidx = FindLocation("Cuba_shore_03");								// La Croix opening scene
							break;

							case PLAYER_TYPE_AGENT:
								id += "Hostile Port";
								LocationOverride = true;
							break;

							case PLAYER_TYPE_SMUGGLER:
								id += "Friendly Port";
								LocationOverride = true;
							break;

							case PLAYER_TYPE_CURSED:
								if(HasSubStr(ShipsTypes[curShip].id, "Dutchman"))
									id += "Cozumel Waters";
								else
									id += "Random Port";
								LocationOverride = true;
							break;

							case PLAYER_TYPE_CASTAWAY:
								id += "Random Shore";
								LocationOverride = true;
								SetSelectable("SHIP", false);
								SetTextBoxReadOnly("ShipName", true);
								curShip = GetShipIndex(SHIP_LIFEBOAT);
								GameInterface.SHIP.pic1.str1 = "#" + ShipsTypes[curShip].Class;
								GameInterface.SHIP.pic1.str2 = ShipsTypes[curShip].SName;
								GameInterface.SHIP.pic1.img2 = GetShipPicName(curShip);
								GameInterface.SHIP.pic1.tex2 = 1 + GetShipTexture(curShip); // PB
								SendMessage(&GameInterface, "ls", MSG_INTERFACE_REFRESH_SCROLL, "SHIP");
								GameInterface.strings.ShipName = TranslateString("", "Lifeboat");
							break;

							case PLAYER_TYPE_CORSAIR:
								if (NationNoIsland(CharNation, curPeriod))
									lidx = FindLocation("Tortuga_Port");							// Island-less corsairs start at Tortuga, not Nevis
							break;

							case PLAYER_TYPE_NAVAL_OFFICER:
								if (CharNation != PIRATE && CharNation != PERSONAL_NATION)
								{
									if (NationNoIsland(CharNation, curPeriod))
										lidx = FindLocation("Tortuga_Port");							// Island-less naval officers start at Tortuga, not Nevis
									else
									{
										if (CharNation == ENGLAND)
											lidx = FindLocation("Redmond_port");						// Speightstown isn't much of a navy base
									}
									NavyLockShipSelection(true , model);								// Navy assignment is pre-defined
								}
							break;
						}
					}
				}
				if (!LocationOverride)
				{
					if (lidx >= 0) {
						island = XI_IslandName(lidx);
						town = XI_TownName(lidx);
						if (id == "") {
							Preprocessor_Add("island_name", island);
							Preprocessor_Add("town_name", town);
							id += PreprocessText(TranslateString("", Locations[lidx].id.label));
							Preprocessor_Remove("town_name");
							Preprocessor_Remove("island_name");
						} else {
							id += town + " (" + island + ")";
						}
						if (!HasSubStr(id, island)) id += " " + TranslateString("", "on_") + " " + island;
					}
				}
				// PB: Player Type <--
				GameInterface.strings.StartLocation = id;
			}
			SetNodeUsing("NATIONFLAG_BUTTON", true);

			GameInterface.strings.Difficulty = TranslateString("", GetDifficultyName(CharDifficulty));
			if (CheckAttribute(&GameInterface, "CustomSkill")) DeleteAttribute(&GameInterface, "CustomSkill");
			GameInterface.CustomSkill.Value.v1 = rand(9);
			GameInterface.CustomSkill.Speed.s1 = sti(GameInterface.CustomSkill.Value.v1);
			GameInterface.CustomSkill.Value.v2 = sti(GameInterface.CustomSkill.Value.v1);
			GameInterface.CustomSkill.Speed.s2 = sti(GameInterface.CustomSkill.Speed.s1);
			while (sti(GameInterface.CustomSkill.Value.v2) == sti(GameInterface.CustomSkill.Value.v1))
			{
				GameInterface.CustomSkill.Value.v2 = rand(9);
				GameInterface.CustomSkill.Speed.s2 = sti(GameInterface.CustomSkill.Value.v2);
			}
			GameInterface.strings.PlayerType = TranslateString("", GetPlayerTypeName(curPlayerType));
			tmpPlayerType = curPlayerType;

			SetNewFlagImage("nation");
			SetNewFlagImage("pirateflag");
			SetNewFlagImage("personalflag");
		break;
		case WINDOW_CHARACTER:
			SetSelectable("NATIONFLAG_BUTTON",   false);
			SetSelectable("PIRATEFLAG_BUTTON",   false);
			SetSelectable("PERSONALFLAG_BUTTON", false);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "OutfitSex", XI_ConvertString(GetOutfitSex(curOutfitSex)), FONT_SEADOGS, 245, 306, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "OutfitModel", GetOutfitModel(curOutfitModel), FONT_SEADOGS, 245, 338, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			if (curOutfitModel == OUTFITMODEL_OFFICER) {
				SetNodeUsing("SELECT3_SCROLLBAR", true);
				SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "OutfitOffType", TranslateString("", GetOutfitOffType(curOutfitOffType)), FONT_SEADOGS, 245, 370, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			} else {
				SetNodeUsing("SELECT3_SCROLLBAR", false);
				curOutfitOffType = OUTFITMODEL_ANY;
				SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "OutfitOffType", TranslateString("", GetOutfitOffType(0)), FONT_SEADOGS, 245, 370, COLOR_DESELECT, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			}
			if (curOutfitNation < 0)
				SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "OutfitNation", TranslateString("", "Any"), FONT_SEADOGS, 500, 306, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			else
				SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "OutfitNation", TranslateString("", CheckNationNameByPeriod(curOutfitNation, curPeriod, true)), FONT_SEADOGS, 500, 306, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "OutfitNamed", TranslateString("", GetOutfitNamed(curOutfitNamed)), FONT_SEADOGS, 500, 338, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);

			makeref(model, Models[tmpOutfit]);
			faceid = model.FaceId;
			if (FindFile(GetResourceDirectory() + "TEXTURES\INTERFACES\PORTRAITS\128", "*.tga.tx", "face_" + faceid + ".tga.tx") != "")
				GameInterface.SELECTPICT.ImagesGroup.t4 = "FACE128_" + faceid;
			else
				GameInterface.SELECTPICT.ImagesGroup.t4 = "";
			id = "";
			if (CheckAttribute(model, "name")) id += model.name;
			if (CheckAttribute(model, "middlename")) {
				if (id != "") id += " ";
				id += model.middlename;
			}
			if (CheckAttribute(model, "lastname")) {
				if (id != "") id += " ";
				id += model.lastname;
			}
			if (id != "")
				SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "OutfitName", id, FONT_NORMAL, 380, 130, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 1.0, 0);
			else
				SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "OutfitName", TranslateString("", model.id), FONT_NORMAL, 380, 130, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 1.0, 0);
			if (slno == FindStoryline("FreePlay") && CheckAttribute(model, "storytext"))	SetFormatedText("SELECT_DESCRIPTION", model.storytext);
			else if (CheckAttribute(model, "description")) SetFormatedText("SELECT_DESCRIPTION", LanguageConvertString(idModelDescr, model.description));
			SendMessage(&GameInterface, "lsl", MSG_INTERFACE_MSG_TO_NODE, "SELECT_DESCRIPTION", 5);
			GameInterface.SELECTPICT.pic1.img2 = "face";
			GameInterface.SELECTPICT.pic1.tex2 = 4;
			GameInterface.SELECTPICT.ListSize = 1;
			GameInterface.SELECTPICT.NotUsed = 1;
			SendMessage(&GameInterface, "ls", MSG_INTERFACE_REFRESH_SCROLL, "SELECTPICT");
			if (slno == FindStoryline("FreePlay"))
			{
				GameInterface.character = true; // PB
				SetSelectable("DIALOG_SELECT_BUTTON", true);
			}
			else											SetSelectable("DIALOG_SELECT_BUTTON", curOutfit != tmpOutfit);
		break;
		case WINDOW_SHIP:
			SetSelectable("NATIONFLAG_BUTTON",   false);
			SetSelectable("PIRATEFLAG_BUTTON",   false);
			SetSelectable("PERSONALFLAG_BUTTON", false);
			if (curShipClass < 0)
				SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "ShipClass", TranslateString("", "Any"), FONT_SEADOGS, 245, 306, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			else
				SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "ShipClass", "" + curShipClass, FONT_SEADOGS, 245, 306, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			if (curShipModel < 0)
				SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "ShipModel", TranslateString("", "Any"), FONT_SEADOGS, 245, 338, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			else
				SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "ShipModel", TranslateString("", GetModelShipName(curShipModel)), FONT_SEADOGS, 245, 338, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0); // PB: No need to translate code groups
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "ShipType", TranslateString("", GetTypeShipName(curShipType)), FONT_SEADOGS, 245, 370, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			if (curShipNation < 0)
				SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "ShipNation", TranslateString("", "Any"), FONT_SEADOGS, 500, 306, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			else
				SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "ShipNation", TranslateString("", CheckNationNameByPeriod(curShipNation, curPeriod, true)), FONT_SEADOGS, 500, 306, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);

			if (tmpShip >= 0) {
				makeref(model, ShipsTypes[tmpShip]);
				if (DEBUG)
					SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "ShipTypeName", TranslateString("", model.id), FONT_SEADOGS, 380, 130, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 1.0, 0);
				else
					SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "ShipTypeName", XI_ConvertString(model.SName), FONT_SEADOGS, 380, 130, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 1.0, 0);
				GameInterface.SELECTPICT.pic1.str1 = "#" + model.Class;
				GameInterface.SELECTPICT.pic1.str2 = TranslateString("", model.SName);
				GameInterface.SELECTPICT.pic1.img2 = GetShipPicName(tmpShip);
				GameInterface.SELECTPICT.pic1.tex2 = 2 + GetShipTexture(tmpShip);
				SendMessage(&GameInterface, "ls", MSG_INTERFACE_REFRESH_SCROLL, "SELECTPICT");
				SetFormatedText("SELECT_DESCRIPTION", LanguageConvertString(idShipDescr, model.id + "_Descr"));
				SendMessage(&GameInterface, "lsl", MSG_INTERFACE_MSG_TO_NODE, "SELECT_DESCRIPTION", 5);
				SetSelectable("DIALOG_SELECT_BUTTON", curShip != tmpShip);
			}
		break;
		case WINDOW_PLAYERTYPE:
			SetupPlayerType();
		break;
		case WINDOW_LOCATION:
			/*SetSelectable("MAP_UP_BUTTON", zoom_level > 0);
			SetSelectable("MAP_DOWN_BUTTON", zoom_level > 0);
			SetSelectable("MAP_LEFT_BUTTON", zoom_level > 0);
			SetSelectable("MAP_RIGHT_BUTTON", zoom_level > 0);
			SetSelectable("MAP_ZOOMIN_BUTTON", zoom_level < 2);
			SetSelectable("MAP_ZOOMOUT_BUTTON", zoom_level > 0);*/
		break;
	}
}

//MAXIMUS 20.06.2019: needed for localization ==>
void GiveHimName(ref char)
{
		if (CheckAttribute(char, "name")) {
			CharFirstName = char.name;
			CharOldFirstName = CharFirstName;
			tmpName = CharOldFirstName;
		}
		if (CheckAttribute(char, "middlename")) {
			CharMiddleName = char.middlename;
			CharOldMiddleName = CharMiddleName;
			tmpName = tmpName + " " + CharOldMiddleName;
		} else {
			CharMiddleName = "";
			CharOldMiddleName = "";
		}
		if (CheckAttribute(char, "lastname")) {
			CharLastName = char.lastname;
			CharOldLastName = CharLastName;
			tmpName = tmpName + " " + CharOldLastName;
		}
        //Boyer fix
		CharFirstName = GetStorylineVar(slno, CharFirstName);
		CharMiddleName = GetStorylineVar(slno, CharMiddleName);
		CharLastName = GetStorylineVar(slno, CharLastName);
}
//MAXIMUS 20.06.2019: needed for localization <==

string XI_TownName(int lidx)
{
	if (lidx < 0) return "";
	string sTown;
	ref rPeriod; makeref(rPeriod, Periods[curPeriod]);
	sTown = GetTownIDFromLocID(Locations[lidx].id);
	if (CheckAttribute(rPeriod, "Towns." + sTown + ".Name")) return TranslateString("", rPeriod.Towns.(sTown).Name);
	switch (sTown)
	{
		case "Conceicao":           sTown = "Sao Jorge";              break;
		case "Douwesen":            sTown = "Kralendijk";             break;
		case "Falaise de Fleur":    sTown = "St Pierre";              break;
		case "Isla Muelle":         sTown = "San Juan";               break;
		case "Oxbay":               sTown = "Speightstown";           break;
		case "Greenford":           sTown = "Bridgetown";             break;
		case "Redmond":             sTown = "Port Royale";            break;
		case "Quebradas Costillas": sTown = "Pirate Settlement";      break;
		case "Tortuga":				if(GetStoryline(slno) == "JackSparrow")
										sTown = "Tortuga";
									else
										sTown = "La Tortue";	      break;
		case "Eleuthera":           sTown = "Governor's Harbor";      break;
		case "Alice":               sTown = "Alice Town";             break;
		case "Khael Roa":           sTown = "Cozumel";                break;
		case "":                    sTown = Locations[lidx].id.label; break; // PB: For non-town locations
	}
	return TranslateString("", sTown);
}

string XI_IslandName(int lidx)
{
	string sIsland;
	ref rPeriod, rLoc;
	if (lidx < 0) return "";
	makeref(rPeriod, Periods[curPeriod]);
	makeref(rLoc, Locations[lidx]);
	if (!CheckAttribute(rLoc, "island")) return "";
	sIsland = rLoc.island;
	if (CheckAttribute(rPeriod, "Islands." + sIsland + ".Name")) return TranslateString("", rPeriod.Islands.(sIsland).Name);
	switch (sIsland)
	{
		case "Conceicao":           sIsland = "Grenada";      break;
		case "Douwesen":            sIsland = "Bonaire";      break;
		case "FalaiseDeFleur":      sIsland = "Martinique";   break;
		case "IslaMuelle":          sIsland = "Puerto Rico";  break;
		case "Oxbay":               sIsland = "Barbados";     break;
		case "Redmond":             sIsland = "Jamaica";      break;
		case "QuebradasCostillas":  sIsland = "Nevis";        break;
		case "SaintMartin":         sIsland = "Saint Martin"; break;
		case "KhaelRoa":            sIsland = "Cozumel";      break;
		case "Battle_Rocks":        sIsland = "Petit Tabac";  break;
		case "IslaMona":            sIsland = "Isla Mona";    break;
	}
	return TranslateString("", sIsland);
}

void SetNewFlagImage(string sWhich)
{
	switch (sWhich)
	{
		case "pirateflag":
			SetNewPicture("PIRATE_FLAG", "interfaces\flags\Flag_Pirate" + pirateflagidx + pirateflagtex + ".tga");
		break;
		case "personalflag":
			SetNewPicture("PERSONAL_FLAG", "interfaces\flags\Flag_Personal" + personalflagidx + personalflagtex + ".tga");
			if (CharNation == PERSONAL_NATION) SetNewFlagImage("nation");
		break;
		// default:
			switch (CharNation)
			{
				case PIRATE:
					SetNewPicture("NATION_FLAG", "interfaces\flags\Flag_Pirate00.tga");
				break;
				case PERSONAL_NATION:
					SetNewPicture("NATION_FLAG", "interfaces\flags\Flag_Personal" + personalflagidx + personalflagtex + ".tga");
				break;
				// default:
					SetNewPicture("NATION_FLAG", "interfaces\flags\Flag_" + GetFlagPicName(CharNation) + ".tga");
			}
	}
}

//Levis custom startdate -->

void ChangeStartDate(int year, int month, int day)
{
	int oldyear = CharYear;
	CharYear = GetAddingStartYear(year,month,day);
	if(CharYear < 1500) { CharYear = oldyear; return;}
	if(CharYear > 1830) { CharYear = oldyear; return;}
	CharMonth = GetAddingStartMonth(year,month,day);
	CharDay = GetAddingStartDay(year,month,day);
	//CharHour = sti(arstart.date.hour);
	//CharMinute = sti(arstart.date.min);
	//CharSecond = sti(arstart.date.sec);
	curPeriod = GetPeriodFromYear(CharYear);
	GameInterface.strings.StartYear = CharYear;
	GameInterface.strings.StartMonth = GetMonthName(CharMonth);
	GameInterface.strings.StartDay = CharDay;
	curPeriod = GetPeriodFromYear(CharYear);
	SetCurrentPeriod(curPeriod);
	RefreshScreen();
	iNationsQuantity = CheckNationsQuantity(curPeriod);
	GameInterface.strings.StartPeriod = GetPeriodName(curPeriod);
}

//These are copies of the function in calendar.c but they take the Char data instead of the envirioment data as current data.

int GetAddingStartYear(int addYear,int addMonth,int addDay)
{
	int nextDay = CharDay+addDay;
	int curMonth = CharMonth;
	int curYear = CharYear;
	while(GetMonthDays(curMonth, curYear)<nextDay)
	{
		nextDay = nextDay - GetMonthDays(curMonth, curYear);
		curMonth++;
		if(12<curMonth)
		{
			curMonth = curMonth - 12;
			curYear++;
		}
		if(1>curMonth)
		{
			curMonth = curMonth + 12;
			curYear--;
		}
	}
	while(1>nextDay)
	{
		nextDay = nextDay + GetMonthDays(curMonth, curYear);
		curMonth--;
		if(12<curMonth)
		{
			curMonth = curMonth - 12;
			curYear++;
		}
		if(1>curMonth)
		{
			curMonth = curMonth + 12;
			curYear--;
		}
	}
	int nextMonth = curMonth+addMonth;
	int nextYear = curYear+addYear; // KK
	while(12<nextMonth)
	{
		nextMonth = nextMonth - 12;
		nextYear++;
	}
	while(1>nextMonth)
	{
		nextMonth = nextMonth + 12;
		nextYear--;
	}
	return nextYear;
}
int GetAddingStartMonth(int addYear,int addMonth,int addDay)
{
	int nextDay = CharDay+addDay;
	int curMonth = CharMonth;
	int curYear = CharYear;
	while(GetMonthDays(curMonth, curYear)<nextDay)
	{
		nextDay = nextDay - GetMonthDays(curMonth, curYear);
		curMonth++;
		if(12<curMonth)
		{
			curMonth = curMonth - 12;
		}
		if(1>curMonth)
		{
			curMonth = curMonth + 12;
		}
	}
	while(1>nextDay)
	{
		nextDay = nextDay + GetMonthDays(curMonth, curYear);
		curMonth--;
		if(12<curMonth)
		{
			curMonth = curMonth - 12;
		}
		if(1>curMonth)
		{
			curMonth = curMonth + 12;
		}
	}
	int nextMonth = curMonth+addMonth;
	while(12<nextMonth)
	{
		nextMonth = nextMonth - 12;
	}
	while(1>nextMonth)
	{
		nextMonth = nextMonth + 12;
	}
	return nextMonth;
}
int GetAddingStartDay(int addYear,int addMonth,int addDay)
{
	int nextDay = CharDay+addDay;
	int curMonth = CharMonth;
	int curYear = CharYear;
	while(GetMonthDays(curMonth, curYear)<nextDay)
	{
		nextDay = 1;
	}
	while(1>nextDay)
	{
		nextDay = nextDay + GetMonthDays(curMonth, curYear);
	}
	return nextDay;
}

//Levis custom startdate <--

void ChangeDifficulty(bool bRight)
{
	if (bRight) {
		if (CharDifficulty < 4)
			CharDifficulty++;
		else
			CharDifficulty = 4;
	} else {
	if (CharDifficulty > 1)
		CharDifficulty--;
	else
		CharDifficulty = 1;
	}
	GameInterface.strings.Difficulty = TranslateString("", GetDifficultyName(CharDifficulty));
}

bool CheckProfiles(string curProfile)
{
	ProfileName = curProfile;

	return GetProfileSavesQuantity(GetStoryline(slno), curProfile) == 0;
}

void DoUpStep()
{
	string tmp = NextUp(GetCurrentNode());
	SetCurrentNode(tmp);
}

void DoDownStep()
{
	string tmp = NextDown(GetCurrentNode());
	SetCurrentNode(tmp);
}

string NextUp(string curNode)
{
	switch (curNode)
	{
		case "STORYLINE":
			if (GetSelectable("START_GAME_BUTTON")) return "START_GAME_BUTTON"; else return NextUp("START_GAME_BUTTON");
		break;
		case "START_GAME_BUTTON":
			if (GetSelectable("DIFFICULTY")) return "DIFFICULTY"; else return NextUp("DIFFICULTY");
		break;
		case "DIFFICULTY":
			if (GetSelectable("STORYLINE")) return "STORYLINE"; else return NextUp("STORYLINE");
		break;
	}
	return " ";
}

string NextDown(string curNode)
{
	switch (curNode)
	{
		case "STORYLINE":
			if (GetSelectable("DIFFICULTY")) return "DIFFICULTY"; else return NextDown("DIFFICULTY");
		break;
		case "DIFFICULTY":
			if (GetSelectable("START_GAME_BUTTON")) return "START_GAME_BUTTON"; else return NextDown("START_GAME_BUTTON");
		break;
		case "START_GAME_BUTTON":
			if (GetSelectable("STORYLINE")) return "STORYLINE"; else return NextDown("STORYLINE");
		break;
	}
	return " ";
}

void SetWindow(int iWindow)
{
	int i, j;
	string sTmp1, sTmp2;
	switch (curWindow)
	{
		case WINDOW_MAIN:
			SetSelectable("EXIT_BUTTON", false);
			SetSelectable("STORYLINE", false);
			SetSelectable("DEFAULT_CHARACTER_BUTTON", false);
			SetSelectable("CHARNAME_TEXTBOX", false);
			SetSelectable("SHIP", false);
			SetSelectable("SHIPNAME_TEXTBOX", false);
			SetSelectable("LOCATION_BUTTON", false);
			SetSelectable("NATION_FLAG", false);
			SetSelectable("PIRATE_FLAG", false);
			SetSelectable("PERSONAL_FLAG", false);
			SetNodeUsing("DIFFICULTY", false);
			SetNodeUsing("PLAYERTYPE_BUTTON", false);
			SetSelectable("PROFILE_TEXTBOX", false);
			SetSelectable("START_GAME_BUTTON", false);
		break;
		case WINDOW_CHARACTER:
			curOutfitSex = OUTFITSEX_ANY;
			curOutfitModel = OUTFITMODEL_ANY;
			curOutfitOffType = OUTFITOFFTYPE_ANY;
			curOutfitNation = -1;
		//	curOutfitNamed = OUTFITNAMED_NAMED;
			SetNodeUsing("TOOLTIP_FADER", false);
			SetNodeUsing("DIALOG_WINDOW", false);
			GameInterface.SELECTPICT.BadTex1 = 0;
			GameInterface.SELECTPICT.BadPic1 = "emptyface";
			GameInterface.SELECTPICT.pic1.str1 = "";
			GameInterface.SELECTPICT.pic1.img1 = "";
			GameInterface.SELECTPICT.pic1.tex1 = -1;
			GameInterface.SELECTPICT.pic1.str2 = "";
			GameInterface.SELECTPICT.pic1.img2 = "";
			GameInterface.SELECTPICT.pic1.tex2 = -1;
			GameInterface.SELECTPICT.ListSize = 1;
			GameInterface.SELECTPICT.NotUsed = 1;
			SendMessage(&GameInterface, "ls", MSG_INTERFACE_REFRESH_SCROLL, "SELECTPICT");
			SetNodeUsing("SELECTPICT", false);
			SetNodeUsing("SELECT_CHANGER", false);
			SetFormatedText("SELECT_DESCRIPTION", "");
			SetNodeUsing("SELECT_DESCRIPTION", false);
			SetNodeUsing("SELECT1_SCROLLBAR", false);
			SetNodeUsing("SELECT2_SCROLLBAR", false);
			SetNodeUsing("SELECT3_SCROLLBAR", false);
			SetNodeUsing("SELECT4_SCROLLBAR", false);
			SetNodeUsing("SELECT5_SCROLLBAR", false);
			DisableTextbox("SearchText");
			SetNodeUsing("WINDOWSTRINGES", false);
			SetNodeUsing("TITLE_WINDOW", false);
			SetNodeUsing("EXIT_WINDOW_BUTTON", false);
			SetNodeUsing("DIALOG_SELECT_BUTTON", false);
			SendMessage(&GameInterface, "lsl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 5); //Add
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblOutfitSex", "", FONT_NORMAL, 70, 304, COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblOutfitModel", "", FONT_NORMAL, 70, 336, COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblOutfitOfftype", "", FONT_NORMAL, 70, 368, COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblOutfitNation", "", FONT_NORMAL, 330, 304, COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblOutfitNamed", "", FONT_NORMAL, 330, 336, COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblOutfitSearchText", "", FONT_NORMAL, 330, 368, COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "Title", "", FONT_TITLE, 320, 110, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "OutfitName", "", FONT_NORMAL, 380, 160, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 1.0, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "OutfitSex", "", FONT_NORMAL, 245, 306, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "OutfitModel", "", FONT_NORMAL, 245, 338, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "OutfitOffType", "", FONT_NORMAL, 245, 370, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "OutfitNation", "", FONT_NORMAL, 500, 306, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "OutfitNamed", "", FONT_NORMAL, 500, 338, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
		break;
		case WINDOW_SHIP:
			curShipClass = -1;
			curShipType = SHIPTYPENAME_ANY;
			curShipModel = -1;
			curShipNation = -1;
			SetNodeUsing("TOOLTIP_FADER", false);
			SetNodeUsing("DIALOG_WINDOW", false);
			GameInterface.SELECTPICT.ImagesGroup.t2 = "SHIPS16";
			GameInterface.SELECTPICT.ImagesGroup.t3 = "SHIPS1";
			GameInterface.SELECTPICT.ImagesGroup.t4 = "SHIPS2";
			GameInterface.SELECTPICT.ImagesGroup.t5 = "SHIPS3";
			GameInterface.SELECTPICT.ImagesGroup.t6 = "SHIPS4";
			GameInterface.SELECTPICT.ImagesGroup.t7 = "SHIPS5";
			GameInterface.SELECTPICT.BadTex1 = 1;
			GameInterface.SELECTPICT.BadPic1 = "ship back";
			GameInterface.SELECTPICT.pic1.str1 = "";
			GameInterface.SELECTPICT.pic1.img1 = "";
			GameInterface.SELECTPICT.pic1.tex1 = -1;
			GameInterface.SELECTPICT.pic1.str2 = "";
			GameInterface.SELECTPICT.pic1.img2 = "";
			GameInterface.SELECTPICT.pic1.tex2 = -1;
			GameInterface.SELECTPICT.ListSize = 1;
			GameInterface.SELECTPICT.NotUsed = 1;
			SendMessage(&GameInterface, "ls", MSG_INTERFACE_REFRESH_SCROLL, "SELECTPICT");
			SetNodeUsing("SELECTPICT", false);
			SetNodeUsing("SELECT_CHANGER", false);
			SetFormatedText("SELECT_DESCRIPTION", "");
			SetNodeUsing("SELECT_DESCRIPTION", false);
			SetNodeUsing("SELECT1_SCROLLBAR", false);
			SetNodeUsing("SELECT2_SCROLLBAR", false);
			SetNodeUsing("SELECT3_SCROLLBAR", false);
			SetNodeUsing("SELECT4_SCROLLBAR", false);
			SetNodeUsing("SELECT5_SCROLLBAR", false);
			DisableTextbox("SearchText");
			SetNodeUsing("WINDOWSTRINGES", false);
			SetNodeUsing("TITLE_WINDOW", false);
			SetNodeUsing("EXIT_WINDOW_BUTTON", false);
			SetNodeUsing("DIALOG_SELECT_BUTTON", false);
			SendMessage(&GameInterface, "lsl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 5); //Add
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblShipClass", "", FONT_NORMAL, 70, 304, COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblShipModel", "", FONT_NORMAL, 70, 336, COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblShipType", "", FONT_NORMAL, 70, 368, COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblShipNation", "", FONT_NORMAL, 330, 304, COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblShipSearchText", "", FONT_NORMAL, 330, 368, COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "Title", "", FONT_TITLE, 320, 110, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "ShipClass", "", FONT_NORMAL, 245, 306, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "ShipModel", "", FONT_NORMAL, 245, 338, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "ShipType", "", FONT_NORMAL, 245, 370, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "ShipNation", "", FONT_NORMAL, 500, 306, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "ShipTypeName", "", FONT_NORMAL, 500, 306, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
		break;
		case WINDOW_NATION:
			SetNodeUsing("TOOLTIP_FADER", false);
			SetNodeUsing("DIALOG_WINDOW", false);
			SetNodeUsing("WINDOWSTRINGES", false);
			SetNodeUsing("TITLE_WINDOW", false);
			SetNodeUsing("EXIT_WINDOW_BUTTON", false);
			SetNodeUsing("DIALOG_SELECT_BUTTON", false);
			SetNodeUsing("SELECTOR1", false);
			SendMessage(&GameInterface, "lsl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 5); //Add
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "Title", "", FONT_TITLE, 320, 110, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			for (i = 0; i < iNationsQuantity - 1; i++)
			{
				SetNodeUsing("FLAG_BUTTON1" + i, false);
				SetNodeUsing("FLAG_PICTURE1" + i, false);
				SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblNation" + i, "", FONT_NORMAL, 140, 150 + (i * 24), COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
				j++;
			}
			SetNodeUsing("FLAG_BUTTON40", false);
			SetNodeUsing("FLAG_PICTURE40", false);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblNationPirate", "", FONT_NORMAL, 440, 150, COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
			SetNodeUsing("FLAG_BUTTON41", false);
			SetNodeUsing("FLAG_PICTURE41", false);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblNationPersonal", "", FONT_NORMAL, 440, 180, COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
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
		case WINDOW_PLAYERTYPE:
			SetNodeUsing("TOOLTIP_FADER", false);
			SetNodeUsing("DIALOG_WINDOW", false);
			SetNodeUsing("WINDOWSTRINGES", false);
			SetNodeUsing("TITLE_WINDOW", false);
			SetNodeUsing("EXIT_WINDOW_BUTTON", false);
			SetNodeUsing("DIALOG_SELECT_BUTTON", false);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "Title", "", FONT_TITLE, 320, 110, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SetNodeUsing("PLAYERTPYPESCROLLBAR", false);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "playertypename", "", FONT_NORMAL, 162, 144, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "playertypedescription1", "", FONT_NORMAL, 162, 144, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "playertypedescription2", "", FONT_NORMAL, 162, 144, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "playertypedescription3", "", FONT_NORMAL, 162, 144, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "playertypedescription4", "", FONT_NORMAL, 162, 144, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "playertypedescription5", "", FONT_NORMAL, 162, 144, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "playertypedescription6", "", FONT_NORMAL, 162, 144, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "playertypedescription7", "", FONT_NORMAL, 162, 144, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "playertypedescription8", "", FONT_NORMAL, 162, 144, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "playertypedescription9", "", FONT_NORMAL, 162, 144, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SetNodeUsing("PLAYERTYPEIMAGES", false);
			for (i = 0; i < NUM_DIFF_SKILLS; i++)
			{
				SetNodeUsing("SKILL_CHANGER" + i, false);
				SetNodeUsing("SKILL_BUTTON" + i, false);
				SetSelectable("SKILL_BUTTON" + i, false);
				SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblSkill" + i, "", FONT_NORMAL, 300, 144 + (i * 26), COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
				SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "bonus" + i, "", FONT_BOLD_NUMBERS, 500, 144 + (i * 26), COLOR_MONEY, 0, SCRIPT_ALIGN_RIGHT, true, 0.5, 0);
				SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "skill" + i, "", FONT_BOLD_NUMBERS, 485, 144 + (i * 26), COLOR_NORMAL, 0, SCRIPT_ALIGN_RIGHT, true, 0.5, 0);
			}
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblfreeskillpoints", "", FONT_NORMAL, 70, 374, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "freeskillpoints", "", FONT_BOLD_NUMBERS, 570, 144, COLOR_NORMAL, 0, SCRIPT_ALIGN_RIGHT, true, 0.5, 0);
			SetNodeUsing("SELECTOR1", false);
			SetNodeUsing("SELECTOR2", false);
			DeleteAttribute(&GameInterface, "SELECTOR");
		break;
		case WINDOW_LOCATION:
			SetNodeUsing("TOOLTIP_FADER", false);
			SetNodeUsing("DIALOG_WINDOW", false);
			SetNodeUsing("WINDOWSTRINGES", false);
			SetNodeUsing("TITLE_WINDOW", false);
			SetNodeUsing("EXIT_WINDOW_BUTTON", false);
			SetNodeUsing("DIALOG_SELECT_BUTTON", false);
			/*SetNodeUsing("MAP_UP_BUTTON", false);
			SetNodeUsing("MAP_DOWN_BUTTON", false);
			SetNodeUsing("MAP_LEFT_BUTTON", false);
			SetNodeUsing("MAP_RIGHT_BUTTON", false);
			SetNodeUsing("MAP_ZOOMIN_BUTTON", false);
			SetNodeUsing("MAP_ZOOMOUT_BUTTON", false);*/
			SetNodeUsing("MAP", false);
			for (j = 0; j < 14; j++)
			{
				if (j < 10)
					sTmp2 = "0" + j;
				else
					sTmp2 = "" + j;
				for (i = 0; i < 13; i++)
				{
					if (i < 10)
						sTmp1 = "0" + i;
					else
						sTmp1 = "" + i;
					SetNodeUsing("MAP_POS_" + sTmp2 + "_" + sTmp1 + "_BUTTON", false);
				}
			}
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "Title", "", FONT_TITLE, 320, 110, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
		break;
	}
	curWindow = iWindow;
	switch (curWindow)
	{
		case WINDOW_MAIN:
			SetSelectable("EXIT_BUTTON", true);
			SetSelectable("STORYLINE", true);
			if (CheckAttribute(arstart, "model.lock") == false || sti(arstart.model.lock) == false) SetSelectable("DEFAULT_CHARACTER_BUTTON", true);
			if (CheckAttribute(arstart, "name.lock") == false || sti(arstart.name.lock) == false) SetSelectable("CHARNAME_TEXTBOX", true);
			if (CheckAttribute(arstart, "ship")) {
				if (CheckAttribute(arstart, "ship.lock") == false || sti(arstart.ship.lock) == false) SetSelectable("SHIP", true);
			} else {
				SetSelectable("SHIP", false);
			}
			if (CheckAttribute(arstart, "shipname")) {
				if (CheckAttribute(arstart, "shipname.lock") == false || sti(arstart.shipname.lock) == false) SetSelectable("SHIPNAME_TEXTBOX", true);
			} else {
				SetSelectable("SHIPNAME_TEXTBOX", false);
			}
		//	if (CheckAttribute(arstart, "location.lock") == false || sti(arstart.location.lock) == false) SetSelectable("LOCATION_BUTTON", true);
			if (CheckAttribute(arstart, "nation.lock")) {
				SetSelectable("NATION_FLAG", sti(arstart.nation.lock) == false);
				SetSelectable("NATIONFLAG_BUTTON", sti(arstart.nation.lock) == false);
			} else {
				SetSelectable("NATION_FLAG", true);
				SetSelectable("NATIONFLAG_BUTTON", true);
			}
			if (CheckAttribute(arstart, "Flags.Pirate.lock")) {
				SetSelectable("PIRATE_FLAG", sti(arstart.Flags.Pirate.lock) == false);
				SetSelectable("PIRATEFLAG_BUTTON", sti(arstart.Flags.Pirate.lock) == false);
			} else {
				SetSelectable("PIRATE_FLAG", true);
				SetSelectable("PIRATEFLAG_BUTTON", true);
			}
			if (CheckAttribute(arstart, "Flags.Personal.lock")) {
				SetSelectable("PERSONAL_FLAG", sti(arstart.Flags.Personal.lock) == false);
				SetSelectable("PERSONALFLAG_BUTTON", sti(arstart.Flags.Personal.lock) == false);
			} else {
				SetSelectable("PERSONAL_FLAG", true);
				SetSelectable("PERSONALFLAG_BUTTON", true);
			}
			if (CheckAttribute(arstart, "Flags.Personal.lock") == false || sti(arstart.Flags.Personal.lock) == false) SetSelectable("PERSONAL_FLAG", true);
			if (CheckAttribute(arstart, "difficulty.lock") == false || sti(arstart.difficulty.lock) == false) SetNodeUsing("DIFFICULTY", true);
			if (CheckAttribute(arstart, "playertype.lock") == false || sti(arstart.playertype.lock) == false) SetNodeUsing("PLAYERTYPE_BUTTON", true);
			SetSelectable("PROFILE_TEXTBOX", true);
			SetSelectable("START_GAME_BUTTON", true);

		//	SetCurrentNode("START_GAME_BUTTON");	// PB: Don't keep jumping back to "Start New Game" when scrolling
		break;
		case WINDOW_CHARACTER:
			SetNodeUsing("TOOLTIP_FADER", true);
			SetNodeUsing("DIALOG_WINDOW", true);
			SetNodeUsing("SELECTPICT", true);
			SetNodeUsing("SELECT_CHANGER", true);
			SetNodeUsing("SELECT_DESCRIPTION", true);
			SetNodeUsing("SELECT1_SCROLLBAR", true);
			SetNodeUsing("SELECT2_SCROLLBAR", true);
			SetNodeUsing("SELECT3_SCROLLBAR", true);
			SetNodeUsing("SELECT4_SCROLLBAR", true);
			SetNodeUsing("SELECT5_SCROLLBAR", true);
			EnableTextbox("SearchText");
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblOutfitSex", TranslateString("", "Gender") + ":", FONT_NORMAL, 70, 304, COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblOutfitModel", TranslateString("", "Group") + ":", FONT_NORMAL, 70, 336, COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblOutfitOfftype", TranslateString("", "Officer Type") + ":", FONT_NORMAL, 70, 368, COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblOutfitNation", TranslateString("", "Nation") + ":", FONT_NORMAL, 330, 304, COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblOutfitNamed", TranslateString("", "Fame Level") + ":", FONT_NORMAL, 330, 336, COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblOutfitSearchText", TranslateString("", "Text") + ":", FONT_NORMAL, 330, 368, COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "Title", StringCheckCase(XI_ConvertString("select character"), FONT_TITLE, true), FONT_TITLE, 320, 95, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SetNodeUsing("WINDOWSTRINGES", true);
			SetNodeUsing("TITLE_WINDOW", true);
			SetNodeUsing("EXIT_WINDOW_BUTTON", true);
			SetNodeUsing("DIALOG_SELECT_BUTTON", true);
			SetSelectable("DIALOG_SELECT_BUTTON", true);

			SetCurrentNode("TITLE_WINDOW");
		break;
		case WINDOW_SHIP:
			SetNodeUsing("TOOLTIP_FADER", true);
			SetNodeUsing("DIALOG_WINDOW", true);
			GameInterface.SELECTPICT.ImagesGroup.t2 = "SHIPS16";
			GameInterface.SELECTPICT.ImagesGroup.t3 = "SHIPS1";
			GameInterface.SELECTPICT.ImagesGroup.t4 = "SHIPS2";
			GameInterface.SELECTPICT.ImagesGroup.t5 = "SHIPS3";
			GameInterface.SELECTPICT.ImagesGroup.t6 = "SHIPS4";
			GameInterface.SELECTPICT.ImagesGroup.t7 = "SHIPS5";
			GameInterface.SELECTPICT.BadTex1 = 1;
			GameInterface.SELECTPICT.BadPic1 = "ship back";
			GameInterface.SELECTPICT.pic1.str1 = "";
			GameInterface.SELECTPICT.pic1.img1 = "";
			GameInterface.SELECTPICT.pic1.tex1 = -1;
			GameInterface.SELECTPICT.pic1.str2 = "";
			GameInterface.SELECTPICT.pic1.img2 = "";
			GameInterface.SELECTPICT.pic1.tex2 = -1;
			GameInterface.SELECTPICT.ListSize = 1;
			GameInterface.SELECTPICT.NotUsed = 1;
			SendMessage(&GameInterface, "ls", MSG_INTERFACE_REFRESH_SCROLL, "SELECTPICT");
			SetNodeUsing("SELECTPICT", true);
			SetNodeUsing("SELECT_CHANGER", true);
			SetNodeUsing("SELECT_DESCRIPTION", true);
			SetNodeUsing("SELECT1_SCROLLBAR", true);
			SetNodeUsing("SELECT2_SCROLLBAR", true);
			SetNodeUsing("SELECT3_SCROLLBAR", true);
			SetNodeUsing("SELECT4_SCROLLBAR", true);
			//SetNodeUsing("SELECT5_SCROLLBAR", true);
			EnableTextbox("SearchText");
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblShipClass", TranslateString("", "Class") + ":", FONT_NORMAL, 70, 304, COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblShipModel", TranslateString("", "Group") + ":", FONT_NORMAL, 70, 336, COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblShipType", TranslateString("", "Type") + ":", FONT_NORMAL, 70, 368, COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblShipNation", TranslateString("", "Nation") + ":", FONT_NORMAL, 330, 304, COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblShipSearchText", TranslateString("", "Text") + ":", FONT_NORMAL, 330, 368, COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "Title", StringCheckCase(XI_ConvertString("select ship"), FONT_TITLE, true), FONT_TITLE, 320, 95, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SetNodeUsing("WINDOWSTRINGES", true);
			SetNodeUsing("TITLE_WINDOW", true);
			SetNodeUsing("EXIT_WINDOW_BUTTON", true);
			SetNodeUsing("DIALOG_SELECT_BUTTON", true);
			SetSelectable("DIALOG_SELECT_BUTTON", true);

			SetCurrentNode("TITLE_WINDOW");
		break;
		case WINDOW_NATION:
			SetNodeUsing("TOOLTIP_FADER", true);
			SetNodeUsing("DIALOG_WINDOW", true);
			SetNodeUsing("SELECTOR1", true);
			j = 0;
			for (i = 0; i < iNationsQuantity; i++)
			{
				switch (i)
				{
					case PIRATE:        continue;                                                                                                 break;
					case GUEST1_NATION: SetNewPicture("FLAG_PICTURE1" + j, "INTERFACES\Flags\Flag_Guest1" + curPeriod + ".tga");                  break;
					case GUEST2_NATION: SetNewPicture("FLAG_PICTURE1" + j, "INTERFACES\Flags\Flag_Guest2" + curPeriod + ".tga");                  break;
					/* default:      */ SetNewPicture("FLAG_PICTURE1" + j, "INTERFACES\Flags\Flag_" + GetNationIDByType(i) + curPeriod + ".tga");
				}
				if (CharNation != i)
					SetNodeUsing("FLAG_BUTTON1" + j, true);
				else
					XI_MarkFlag(1, j);
				SetNodeUsing("FLAG_PICTURE1" + j, true);
				SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblNation" + j, TranslateString("", CheckNationNameByPeriod(i, curPeriod, true)), FONT_NORMAL, 218, 150 + (j * 30), COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
				j++;
			}
			if (CharNation != PIRATE)
				SetNodeUsing("FLAG_BUTTON40", true);
			else
				XI_MarkFlag(4, 0);
			SetNewPicture("FLAG_PICTURE40", "INTERFACES\Flags\Flag_Pirate00.tga");
			SetNodeUsing("FLAG_PICTURE40", true);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblNationPirate", TranslateString("", CheckNationNameByPeriod(PIRATE, curPeriod, true)), FONT_NORMAL, 440, 150, COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
			if (CharNation != PERSONAL_NATION)
				SetNodeUsing("FLAG_BUTTON41", true);
			else
				XI_MarkFlag(4, 1);
			SetNewPicture("FLAG_PICTURE41", "INTERFACES\Flags\Flag_Personal" + personalflagidx + personalflagtex + ".tga");
			SetNodeUsing("FLAG_PICTURE41", true);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblNationPersonal", TranslateString("", CheckNationNameByPeriod(PERSONAL_NATION, curPeriod, true)), FONT_NORMAL, 440, 180, COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "Title", "NATION", FONT_TITLE, 320, 110, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SetNodeUsing("WINDOWSTRINGES", true);
			SetNodeUsing("TITLE_WINDOW", true);
			SetNodeUsing("EXIT_WINDOW_BUTTON", true);
			SetNodeUsing("DIALOG_SELECT_BUTTON", true);
			SetSelectable("DIALOG_SELECT_BUTTON", false);

			SetCurrentNode("TITLE_WINDOW");
		break;
		case WINDOW_PIRATEFLAG:
			SetNodeUsing("TOOLTIP_FADER", true);
			SetNodeUsing("DIALOG_WINDOW", true);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "Title", "PIRATE FLAG", FONT_TITLE, 320, 110, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SetNodeUsing("WINDOWSTRINGES", true);
			SetNodeUsing("TITLE_WINDOW", true);
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

			SetCurrentNode("TITLE_WINDOW");
		break;
		case WINDOW_PERSONALFLAG:
			SetNodeUsing("TOOLTIP_FADER", true);
			SetNodeUsing("DIALOG_WINDOW", true);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "Title", "PERSONAL FLAG", FONT_TITLE, 320, 110, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SetNodeUsing("WINDOWSTRINGES", true);
			SetNodeUsing("TITLE_WINDOW", true);
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

			SetCurrentNode("TITLE_WINDOW");
		break;
		case WINDOW_PLAYERTYPE:
			SetNodeUsing("TOOLTIP_FADER", true);
			SetNodeUsing("DIALOG_WINDOW", true);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "Title", "BACKGROUND PROFESSION", FONT_TITLE, 320, 110, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SetNodeUsing("WINDOWSTRINGES", true);
			SetNodeUsing("TITLE_WINDOW", true);
			SetNodeUsing("EXIT_WINDOW_BUTTON", true);
			SetNodeUsing("DIALOG_SELECT_BUTTON", true);
			SetNodeUsing("PLAYERTPYPESCROLLBAR", true);
			SetNodeUsing("PLAYERTYPEIMAGES", true);
			for (i = 0; i < NUM_DIFF_SKILLS; i++)
			{
				SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblSkill" + i, TranslateString("", GetSkillName(i)), FONT_NORMAL, 300, 144 + (i * 26), COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
				SetNodeUsing("SKILL_BUTTON" + i, true);
				if (curPlayerType == PLAYER_TYPE_CUSTOM) {
					SetSelectable("SKILL_BUTTON" + i, true);
					SetNodeUsing("SKILL_CHANGER" + i, true);
				} else {
					SetSelectable("SKILL_BUTTON" + i, false);
				}
			}

			SetCurrentNode("TITLE_WINDOW");
		break;
		case WINDOW_LOCATION:
			SetNodeUsing("TOOLTIP_FADER", true);
			SetNodeUsing("DIALOG_WINDOW", true);
			SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "Title", "STARTING LOCATION", FONT_TITLE, 320, 110, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
			SetNodeUsing("WINDOWSTRINGES", true);
			SetNodeUsing("TITLE_WINDOW", true);
			SetNodeUsing("EXIT_WINDOW_BUTTON", true);
			SetNodeUsing("DIALOG_SELECT_BUTTON", true);
			/*SetNodeUsing("MAP_UP_BUTTON", true);
			SetNodeUsing("MAP_DOWN_BUTTON", true);
			SetNodeUsing("MAP_LEFT_BUTTON", true);
			SetNodeUsing("MAP_RIGHT_BUTTON", true);
			SetNodeUsing("MAP_ZOOMIN_BUTTON", true);
			SetNodeUsing("MAP_ZOOMOUT_BUTTON", true);*/
			SetNodeUsing("MAP", true);
			for (j = 0; j < 14; j++)
			{
				if (j < 10)
					sTmp2 = "0" + j;
				else
					sTmp2 = "" + j;
				for (i = 0; i < 13; i++)
				{
					if (i < 10)
						sTmp1 = "0" + i;
					else
						sTmp1 = "" + i;
					SetNodeUsing("MAP_POS_" + sTmp2 + "_" + sTmp1 + "_BUTTON", true);
				}
			}

			SetCurrentNode("TITLE_WINDOW");
		break;
	}
	RefreshScreen();
}

void XI_MarkFlag(int i, int j)
{
	GameInterface.SELECTOR.i = i;
	GameInterface.SELECTOR.j = j;
	SendMessage(&GameInterface, "lsllllll", MSG_INTERFACE_MSG_TO_NODE, "SELECTOR1", 0, 70 + (i * 74), 150 + (j * 30), 86 + (i * 74), 166 + (j * 30), 0);
}

void SearchText_Update()
{
	PostEvent("SearchText_Refresh", 100.0);
}

#event_handler("SearchText_Refresh", "Refresh_SearchText")
void Refresh_SearchText()
{
	SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "SearchText", GameInterface.strings.SearchText, FONT_SEADOGS, 500, 368, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
}

void SearchText_End()
{
	Event("KB_Update");
	DelEventHandler("KB_End", "SearchText_End");
	DelEventHandler("KB_Esc", "SearchText_End");
	DelEventHandler("KB_Update", "SearchText_Update");
	int TextLength = strlen(GameInterface.strings.SearchText);
	if(TextLength > 1)	// PB: Removes weird character at the end of the search text
		GameInterface.strings.SearchText = strcut(GameInterface.strings.SearchText,0,TextLength-2);
	if (curWindow == WINDOW_CHARACTER)
	{
		SelectMatchingModel(true);
	}
	else
	{
		SelectMatchingShip(true);
	}
}

void ChangeOutfit(bool bRight)
{
	if (bRight) {
		tmpOutfit++;
		if (tmpOutfit > MODEL_HIGH) tmpOutfit = 0;
	} else {
		tmpOutfit--;
		if (tmpOutfit < 0) tmpOutfit = MODEL_HIGH;
	}
	SelectMatchingModel(bRight);
}

void ChangeOutfitSex(bool bRight)
{
	bool Found = false;
	while(true)
	{
		if (bRight) {
			curOutfitSex++;
			if (curOutfitSex > 2) curOutfitSex = 0;
		} else {
			curOutfitSex--;
			if (curOutfitSex < 0) curOutfitSex = 2;
		}
		Found = SelectMatchingModel(false);
		if(curOutfitSex == 0 || Found) break;
	}
}

string GetOutfitSex(int n)
{
	string ret = "";
	switch (n)
	{
		case OUTFITSEX_ANY:   ret = "Any";   break;
		case OUTFITSEX_MAN:   ret = "Man";   break;
		case OUTFITSEX_WOMAN: ret = "Woman"; break;
	}
	return ret;
}

void ChangeOutfitModel(bool bRight)
{
	bool Found = false;
	while(true)
	{
		if (bRight) {
			curOutfitModel++;
			if (curOutfitModel > 10) curOutfitModel = 0;
		} else {
			curOutfitModel--;
			if (curOutfitModel < 0) curOutfitModel = 10;
		}
		Found = SelectMatchingModel(false);
		if(curOutfitModel == 0 || Found) break;
	}
}

string GetOutfitModel(int n)
{
	string ret = "";
	switch (n)
	{
		case OUTFITMODEL_ANY:      ret = "Any";          break;
		case OUTFITMODEL_POOR:     ret = "Poor Class";   break;
		case OUTFITMODEL_LOW:      ret = "Low Class";    break;
		case OUTFITMODEL_MIDDLE:   ret = "Middle Class"; break;
		case OUTFITMODEL_RICH:     ret = "Rich Class";   break;
		case OUTFITMODEL_SAILOR:   ret = "Sailor";       break;
		case OUTFITMODEL_OFFICER:  ret = "Officer";      break;
		case OUTFITMODEL_NAVY:     ret = "Navy Officer"; break;
		case OUTFITMODEL_SOLDIER:  ret = "Soldier";      break;
		case OUTFITMODEL_LANDOFF:  ret = "Land Officer"; break;
		case OUTFITMODEL_NATIVE:   ret = "Native";       break;
		case OUTFITMODEL_SKELETON: ret = "Skeleton";     break;
	}
	return XI_ConvertString(ret);
}

void ChangeOutfitOffType(bool bRight)
{
	bool Found = false;
	while(true)
	{
		if (bRight) {
			curOutfitOffType++;
			if (curOutfitOffType > 8) curOutfitOffType = 0;
		} else {
			curOutfitOffType--;
			if (curOutfitOffType < 0) curOutfitOffType = 8;
		}
		Found = SelectMatchingModel(false);
		if(curOutfitOffType == 0 || Found) break;
	}
}

string GetOutfitOffType(int n)
{
	string ret = "";
	switch (n)
	{
		case OUTFITOFFTYPE_ANY:       ret = "Any";					break;
		case OUTFITOFFTYPE_CAPTAIN:   ret = "Captains";    			break;
		case OUTFITOFFTYPE_FIRSTMATE: ret = OFFIC_TYPE_FIRSTMATE;	break;
		case OUTFITOFFTYPE_BOATSWAIN: ret = OFFIC_TYPE_BOATSWAIN;	break;
		case OUTFITOFFTYPE_CANNONEER: ret = OFFIC_TYPE_CANNONEER;	break;
		case OUTFITOFFTYPE_QMASTER:   ret = OFFIC_TYPE_QMASTER;		break;
		case OUTFITOFFTYPE_NAVIGATOR: ret = OFFIC_TYPE_NAVIGATOR;	break;
		case OUTFITOFFTYPE_CARPENTER: ret = OFFIC_TYPE_CARPENTER;	break;
		case OUTFITOFFTYPE_DOCTOR:    ret = OFFIC_TYPE_DOCTOR;		break;
		case OUTFITOFFTYPE_ABORDAGE:  ret = OFFIC_TYPE_ABORDAGE;	break;
	}
	return ret;
}

void ChangeOutfitNation(bool bRight)
{
	bool Found = false;
	while(true)
	{
		if (bRight) {
			curOutfitNation++;
			if (curOutfitNation > iNationsQuantity - 1) curOutfitNation = -1;
		} else {
			curOutfitNation--;
			if (curOutfitNation < -1) curOutfitNation = iNationsQuantity - 1;
		}
		Found = SelectMatchingModel(false);
		if(curOutfitNation == -1 || Found) break;
	}
}

void ChangeOutfitNamed(bool bRight)
{
	bool Found = false;
	while(true)
	{
		if (bRight) {
			curOutfitNamed++;
			if (curOutfitNamed > 3) curOutfitNamed = 0;
		} else {
			curOutfitNamed--;
			if (curOutfitNamed < 0) curOutfitNamed = 3;
		}
		Found = SelectMatchingModel(false);
		if(curOutfitNamed == OUTFITNAMED_ANY || Found) break;
	}
}

string GetOutfitNamed(int n)
{
	string ret = "";
	switch (n)
	{
		case OUTFITNAMED_ANY:		ret = "Any";			break;
		case OUTFITNAMED_SPECIFIC:	ret = "Specific";		break;
		case OUTFITNAMED_NAMED: 	ret = "Named";			break;
		case OUTFITNAMED_UNNAMED:	ret = "Unnamed";		break;
	}
	return TranslateString("", ret);
}

bool CheckModelMatch()
{
	string sTmp, otype;
	bool bSex = curOutfitSex == OUTFITSEX_ANY;
	bool bModel = curOutfitModel == OUTFITMODEL_ANY;
	bool bOffType = curOutfitModel != OUTFITMODEL_OFFICER;
	bool bNation = curOutfitNation == -1;
	bool bNamed = curOutfitNamed == OUTFITNAMED_ANY;
	bool bSearchText = GameInterface.strings.SearchText == "";
	ref model;

	makeref(model, Models[tmpOutfit]);

	if(model.id		== "blank") return false;
	if(model.nation	== BROKEN ) return false;

	// Periods Mod -->
	bool bPeriod = false;
	if (CheckAttribute(model, "period") && !CheckAttribute(model, "date.year")) {
		otype = model.period;
		int l = strlen(otype);
		for (int n = 0; n < l; n++)
		{
			if (sti(GetSymbol(otype, n)) == GetCurrentPeriod())		bPeriod = true;
		}
		if(!bPeriod) return false;
	}
	// Periods Mod <--

	if (!bSex) {
		sTmp = GetOutfitSex(curOutfitSex);
		if (model.sex != sTmp) return false;
	}
	if (!bModel) {
		switch (curOutfitModel)
		{
			case OUTFITMODEL_POOR:     sTmp = "Poor_Citizens";   break;
			case OUTFITMODEL_LOW:      sTmp = "Lower_Citizens";  break;
			case OUTFITMODEL_MIDDLE:   sTmp = "Middle_Citizens"; break;
			case OUTFITMODEL_RICH:     sTmp = "Rich_Citizens";   break;
			case OUTFITMODEL_SAILOR:   sTmp = "Sailors";         break;
		//	case OUTFITMODEL_OFFICER:  sTmp = "Mates";           break;	// PB: Use REAL officer types later
			case OUTFITMODEL_NAVY:     sTmp = "navy";            break;
			case OUTFITMODEL_SOLDIER:  sTmp = "Soldiers";        break;
			case OUTFITMODEL_LANDOFF:  sTmp = "Land_Officers";   break;
			case OUTFITMODEL_NATIVE:   sTmp = "Natives";         break;
			case OUTFITMODEL_SKELETON: sTmp = "Skeletons";       break;
		}
		if (!bOffType) {
			// PB: So ANY officer type DOES work -->
			if(curOutfitOffType == OUTFITOFFTYPE_ANY)
			{
				bool TempBool = false;
				if (ModelIsType(model.id, "Captains"))				TempBool = true;
				if (ModelIsType(model.id, OFFIC_TYPE_FIRSTMATE))	TempBool = true;
				if (ModelIsType(model.id, OFFIC_TYPE_BOATSWAIN))	TempBool = true;
				if (ModelIsType(model.id, OFFIC_TYPE_CANNONEER))	TempBool = true;
				if (ModelIsType(model.id, OFFIC_TYPE_QMASTER))		TempBool = true;
				if (ModelIsType(model.id, OFFIC_TYPE_NAVIGATOR))	TempBool = true;
				if (ModelIsType(model.id, OFFIC_TYPE_CARPENTER))	TempBool = true;
				if (ModelIsType(model.id, OFFIC_TYPE_DOCTOR))		TempBool = true;
				if (ModelIsType(model.id, OFFIC_TYPE_ABORDAGE))		TempBool = true;
				if (!TempBool) return false;
			}
			// PB: So ANY officer type DOES work <--
			else
			{
				sTmp = GetOutfitOffType(curOutfitOffType);
				if (!ModelIsType(model.id, sTmp)) return false;
			}
		}
		else
		{
			bool IsType = ModelIsType(model.id, sTmp);
			if (!IsType)
			{
				if (sTmp != "navy" || GetAttribute(model, "playertype") != PLAYER_TYPE_NAVAL_OFFICER || !CheckAttribute(model, "date.year"))
				{
					 return false;
				}
			}
		}
	}
	if (!bNation) {
		if (sti(model.nation) != curOutfitNation && sti(model.nation) != ALL_NATIONS) return false;
	}
	if (!bNamed) {
		if (curOutfitNamed == OUTFITNAMED_SPECIFIC) {
			if (!CheckAttribute(model, "storytitle") || !CheckAttribute(model, "storytext")) return false;
		} else {
			if (curOutfitNamed == OUTFITNAMED_NAMED) {
				if ( CheckAttribute(model, "storytitle")) return false;
				if (!CheckAttribute(model, "name") && !CheckAttribute(model, "lastname")) return false;
			} else {
				if (CheckAttribute(model, "name") || CheckAttribute(model, "lastname")) return false;
			}
		}
	}
	if (!bSearchText) {
		sTmp = GameInterface.strings.SearchText;
		if (HasSubStr(model.id, sTmp))													return true;	// PB: No need to translate this
		if (CheckAttribute(model, "name")        && HasSubStr(model.name, sTmp))		return true;	// PB: Remove TranslateString to speed up the filtering
		if (CheckAttribute(model, "lastname")    && HasSubStr(model.lastname, sTmp))	return true;	// PB: Remove TranslateString to speed up the filtering
		if (CheckAttribute(model, "description") && HasSubStr(model.description, sTmp))	return true;	// PB: Remove TranslateString to speed up the filtering
		return false;
	}
	return true;
}

bool SelectMatchingModel(bool bNext)
{
	bool Found = false;
	string sTmp;
	bool bSex;
	ref model, rName;

	makeref(rName, tmpNames);
	while (initialOutfit != tmpOutfit)
	{
		if (initialOutfit == -1) initialOutfit = tmpOutfit;
		if (CheckModelMatch())
		{
			Found = true;
			break;
		}
		if (bNext) {
			tmpOutfit++;
			if (tmpOutfit > MODEL_HIGH) tmpOutfit = 0;
		} else {
			tmpOutfit--;
			if (tmpOutfit < 0) tmpOutfit = MODEL_HIGH;
		}
	}
	initialOutfit = -1;
	model = GetModel(tmpOutfit);
	GiveHimName(&model); //MAXIMUS 17.05.2019: needed for localization
	sTmp = model.id;
	if (!CheckAttribute(rName, sTmp)) {
		if (CheckAttribute(model, "name") || CheckAttribute(model, "lastname")) {
			rName.(sTmp) = "";
			if (CheckAttribute(model, "name")) rName.(sTmp) = GetStorylineVar(slno, model.name);
			if (CheckAttribute(model, "middlename")) {
				if (rName.(sTmp) != "") rName.(sTmp) = rName.(sTmp) + " ";
				rName.(sTmp) = rName.(sTmp) + GetStorylineVar(slno, model.middlename);
			}
			if (CheckAttribute(model, "lastname")) {
				if (rName.(sTmp) != "") rName.(sTmp) = rName.(sTmp) + " ";
				rName.(sTmp) = rName.(sTmp) + GetStorylineVar(slno, model.lastname);
			}
		}
	}
	GameInterface.character = true; // PB
	if(Found) RefreshScreen();
	return Found;
}

void ChangeShip(bool bRight)
{
	if (bRight) {
		tmpShip++;
		if (tmpShip > SHIP_TYPES_QUANTITY) tmpShip = -1;
	} else {
		tmpShip--;
		if (tmpShip < -1) tmpShip = SHIP_TYPES_QUANTITY;
	}
	SelectMatchingShip(bRight);
}

void ChangeShipClass(bool bRight)
{
	bool Found = false;
	while(true)
	{
		if (bRight) {
			if (curShipClass < 0) {
				curShipClass = MIN_CLASS;
			} else {
				curShipClass--;
				if (curShipClass < shipclass_max) curShipClass = -1;
			}
		} else {
			if (curShipClass < 0) {
				curShipClass = shipclass_max;
			} else {
				curShipClass++;
				if (curShipClass > MIN_CLASS) curShipClass = -1;
			}
		}
		Found = SelectMatchingShip(false);
		if(curShipClass == -1 || Found) break;
	}
}

void ChangeShipModel(bool bRight)
{
	bool Found = false;
	while(true)
	{
		if (bRight) {
			curShipModel++;
			if (curShipModel > GetAttributesNum(rShipModel) - 2) curShipModel = -1;
		} else {
			curShipModel--;
			if (curShipModel < -1) curShipModel = GetAttributesNum(rShipModel) - 2;
		}
		Found = SelectMatchingShip(false);
		if(curShipModel == -1 || Found) break;
	}
}

string GetModelShipName(int n)
{
	string sattr;
	n++;
	if (n == 0) return XI_ConvertString("Any");
	sattr = "m" + n;
	if (CheckAttribute(rShipModel, sattr)) return rShipModel.(sattr);
	return "";
}

void ChangeShipType(bool bRight)
{
	bool Found = false;
	while(true)
	{
		if (bRight) {
			curShipType++;
			if (curShipType > 3) curShipType = 0;
		} else {
			curShipType--;
			if (curShipType < 0) curShipType = 3;
		}
		Found = SelectMatchingShip(false);
		if(curShipType == 0 || Found) break;
	}
}

void ChangeShipNation(bool bRight)
{
	bool Found = false;
	while(true)
	{
		if (bRight) {
			curShipNation++;
			if (curShipNation > iNationsQuantity - 1) curShipNation = -1;
		} else {
			curShipNation--;
			if (curShipNation < -1) curShipNation = iNationsQuantity - 1;
		}
		Found = SelectMatchingShip(false);
		if(curShipNation == -1 || Found) break;
	}
}

string GetTypeShipName(int n)
{
	string retVal = "";
	switch (n)
	{
		case SHIPTYPENAME_ANY:   retVal = "Any";       break;
		case SHIPTYPENAME_WAR:   retVal = "Warships";  break;
		case SHIPTYPENAME_TRADE: retVal = "Merchants"; break;
		case SHIPTYPENAME_BOTH:  retVal = "Versatile"; break;
	}
	return XI_ConvertString(retVal);
}

bool CheckShipMatch()
{
	bool bClass = curShipClass == -1;
	bool bModel = curShipModel == -1;
	bool bType = curShipType == SHIPTYPENAME_ANY;
	bool bNation = curShipNation == -1;
	bool bSearchText = GameInterface.strings.SearchText == "";
	string sTmp;
	ref ship;
	float period;

	if (tmpShip < 0) return true;
	ship = GetShipByType(tmpShip);
	if (bClass && sti(ship.Class) < shipclass_max) return false;
	if (CheckAttribute(ship, "period." + curPeriod) == true && stf(ship.period.(curPeriod)) == 0.0) return false;
	if (!bClass) {
		if (sti(ship.Class) != curShipClass) return false;
	}
	if (!bModel) {
		if (CheckAttribute(ship, "Model") == false || ship.Model != GetModelShipName(curShipModel)) return false;
	}
	if (!bType) {
		switch (curShipType)
		{
			case SHIPTYPENAME_WAR:
				if (CheckAttribute(ship, "Type.Trade") == true && sti(ship.Type.Trade) == true) return false;
			break;
			case SHIPTYPENAME_TRADE:
				if (CheckAttribute(ship, "Type.War") == true && sti(ship.Type.War) == true) return false;
			break;
			case SHIPTYPENAME_BOTH:
				if (CheckAttribute(ship, "Type.Trade") && CheckAttribute(ship, "Type.War")) {
					if (sti(ship.Type.Trade) == false || sti(ship.Type.War) == false) return false;
				}
			break;
		}
	}
	if (!bNation) {
		string sNation = CheckNationNameByPeriod(curShipNation, curPeriod, false);
		if (!CheckAttribute(ship, sNation))												return false;
		if (CheckAttribute(ship, sNation) == true && stf(ship.(sNation)) == 0.0)		return false;
	}
	if (!bSearchText) {
		sTmp = GameInterface.strings.SearchText;
		if (HasSubStr(XI_ConvertString(ship.SName), sTmp))								return true;	// PB: Remove TranslateString to speed up the filtering
		if (HasSubStr(ship.name, sTmp))													return true;	// PB: Remove TranslateString to speed up the filtering
		if (HasSubStr(LanguageConvertString(idShipDescr, ship.id + "_Descr"), sTmp))	return true;
		return false;
	}
	return true;
}

bool SelectMatchingShip(bool bNext)
{
	bool Found = false;
	while (initialShip != tmpShip)
	{
		if (initialShip == -1) initialShip = tmpShip;
		if (CheckShipMatch())
		{
			Found = true;
			break;
		}
		if (bNext) {
			tmpShip++;
			if (tmpShip > SHIP_TYPES_QUANTITY) tmpShip = 0;
		} else {
			tmpShip--;
			if (tmpShip < 0) tmpShip = SHIP_TYPES_QUANTITY;
		}
	}
	initialShip = -1;
	if(Found) RefreshScreen();
	return Found;
}

// PB -->
string GetPlayerTypeDescription(int player_type, string line_type)
{
	string ret = "";
	int tmpLangFileID = LanguageOpenFile("PlayerType_descriptions.txt");
	ret = LanguageConvertString(tmpLangFileID, GetPlayerTypeName(player_type) + "_Descr_" + line_type);
	LanguageCloseFile(tmpLangFileID);
	return ret;
}
// PB <--

void ChangePlayerType(bool bRight)
{
	int i;
	if (bRight) {
		tmpPlayerType++;
		if (GetPlayerTypeName(tmpPlayerType) == OFFIC_TYPE_REGCAP)						tmpPlayerType = PLAYER_TYPE_ADVENTURER;
		if (AUTO_SKILL_SYSTEM && GetPlayerTypeName(tmpPlayerType) == PLAYERTYPE_CUSTOM)	tmpPlayerType = PLAYER_TYPE_ADVENTURER;
		if (GetPlayerTypeName(tmpPlayerType) == PLAYERTYPE_LAND_OWNER)					tmpPlayerType = PLAYER_TYPE_ADVENTURER;
	} else {
		tmpPlayerType--;
		if (GetPlayerTypeName(tmpPlayerType) == OFFIC_TYPE_REGCAP)						tmpPlayerType = PLAYER_TYPE_CUSTOM;
		if (AUTO_SKILL_SYSTEM && GetPlayerTypeName(tmpPlayerType) == PLAYERTYPE_CUSTOM)	tmpPlayerType = PLAYER_TYPE_CASTAWAY;
	}
	GameInterface.strings.CharacterType = TranslateString("", GetPlayerTypeName(tmpPlayerType));
	SetupPlayerType();
}

void SetupPlayerType()
{
	int i, curVal;
	float curSpeed;
	string curskill;

	DeleteAttribute(&GameInterface, "SELECTOR.used1");
	SetNodeUsing("SELECTOR1", false);
	SetNodeUsing("SELECTOR2", false);

	CalculateBonuses(&curVal, &curspeed);

	for (i = 0; i < NUM_DIFF_SKILLS; i++)
	{
		curskill = GetSkillName(i);
		tmpCharSkills[i] = 1;
		tmpCharBonusSkills[i] = 1.0;

		if(sti(GetStorylineVar(slno, "START_MIN_LEVEL")) > 0)
		{
			switch (tmpPlayerType)
			{
				case PLAYER_TYPE_ADVENTURER:
					if (curskill == SKILL_FENCING) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_SNEAK) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
				break;
				case PLAYER_TYPE_AGENT:
					if (curskill == SKILL_SNEAK) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_LEADERSHIP) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
				break;
				case PLAYER_TYPE_MILITARY:
					if (curskill == SKILL_LEADERSHIP) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_FENCING) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
				break;
				case PLAYER_TYPE_CORSAIR:
					if (curskill == SKILL_SAILING) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_GRAPPLING) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
				break;
				case PLAYER_TYPE_ENGINEER:
					if (curskill == SKILL_DEFENCE) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_REPAIR) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
				break;
				case PLAYER_TYPE_EXPLORER:
					if (curskill == SKILL_SAILING) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_FENCING) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
				break;
				case PLAYER_TYPE_GAMBLER:
					if (curskill == SKILL_SNEAK) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_COMMERCE) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
				break;
				case PLAYER_TYPE_GUNNER:
					if (curskill == SKILL_ACCURACY) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_CANNONS) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
				break;
				case PLAYER_TYPE_MARINE:
					if (curskill == SKILL_FENCING) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_GRAPPLING) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
				break;
				case PLAYER_TYPE_MERCHANT:
					if (curskill == SKILL_SAILING) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_COMMERCE) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
				break;
				case PLAYER_TYPE_NAVAL_OFFICER:
					if (curskill == SKILL_LEADERSHIP) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_SAILING) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
				break;
				case PLAYER_TYPE_PHYSICIAN:
					if (curskill == SKILL_DEFENCE) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_COMMERCE) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
				break;
				case PLAYER_TYPE_QUARTERMASTER:
					if (curskill == SKILL_COMMERCE) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_LEADERSHIP) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
				break;
				case PLAYER_TYPE_REBEL:
					if (curskill == SKILL_FENCING) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_SNEAK) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
				break;
				case PLAYER_TYPE_ROGUE:
					if (curskill == SKILL_FENCING) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_COMMERCE) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
				break;
				case PLAYER_TYPE_SAILOR:
					if (curskill == SKILL_SAILING) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_REPAIR) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
				break;
				case PLAYER_TYPE_SHIPWRIGHT:
					if (curskill == SKILL_REPAIR) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_COMMERCE) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
				break;
				case PLAYER_TYPE_SMUGGLER:
					if (curskill == SKILL_COMMERCE) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_FENCING) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
				break;
				case PLAYER_TYPE_SOCIAL_CLIMBER:
					if (curskill == SKILL_LEADERSHIP) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_COMMERCE) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
				break;
				case PLAYER_TYPE_SWORD_MASTER:
					if (curskill == SKILL_FENCING) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_LEADERSHIP) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
				break;
				case PLAYER_TYPE_CASTAWAY:
					if (curskill == SKILL_COMMERCE) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_SNEAK) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
				break;
				case PLAYER_TYPE_CURSED:
					if (curskill == SKILL_SAILING) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_GRAPPLING) {
						tmpCharSkills[i] = curVal;
						tmpCharBonusSkills[i] = curSpeed;
					}
				break;
			}
		}
		else
		{
			switch (tmpPlayerType)
			{
				case PLAYER_TYPE_ADVENTURER:
					if (curskill == SKILL_FENCING) {
						tmpCharSkills[i] = 5;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_SAILING) {
						tmpCharSkills[i] = 3;
					}
					if (curskill == SKILL_COMMERCE) {
						tmpCharSkills[i] = 2;
					}
					if (curskill == SKILL_SNEAK) {
						tmpCharSkills[i] = 4;
						tmpCharBonusSkills[i] = curSpeed;
					}
				break;
				case PLAYER_TYPE_AGENT:
					if (curskill == SKILL_SNEAK) {
						tmpCharSkills[i] = 5;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_LEADERSHIP) {
						tmpCharSkills[i] = 4;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_FENCING) {
						tmpCharSkills[i] = 3;
					}
					if (curskill == SKILL_COMMERCE) {
						tmpCharSkills[i] = 2;
					}
				break;
				case PLAYER_TYPE_MILITARY:
					if (curskill == SKILL_LEADERSHIP) {
						tmpCharSkills[i] = 4;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_FENCING) {
						tmpCharSkills[i] = 5;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_DEFENCE) {
						tmpCharSkills[i] = 3;
					}
					if (curskill == SKILL_SNEAK) {
						tmpCharSkills[i] = 2;
					}
				break;
				case PLAYER_TYPE_CORSAIR:
					if (curskill == SKILL_FENCING) {
						tmpCharSkills[i] = 3;
					}
					if (curskill == SKILL_SAILING) {
						tmpCharSkills[i] = 4;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_CANNONS) {
						tmpCharSkills[i] = 2;
					}
					if (curskill == SKILL_GRAPPLING) {
						tmpCharSkills[i] = 5;
						tmpCharBonusSkills[i] = curSpeed;
					}
				break;
				case PLAYER_TYPE_ENGINEER:
					if (curskill == SKILL_DEFENCE) {
						tmpCharSkills[i] = 5;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_REPAIR) {
						tmpCharSkills[i] = 4;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_GRAPPLING) {
						tmpCharSkills[i] = 3;
					}
					if (curskill == SKILL_FENCING) {
						tmpCharSkills[i] = 2;
					}
				break;
				case PLAYER_TYPE_EXPLORER:
					if (curskill == SKILL_SAILING) {
						tmpCharSkills[i] = 5;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_FENCING) {
						tmpCharSkills[i] = 4;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_REPAIR) {
						tmpCharSkills[i] = 3;
					}
					if (curskill == SKILL_SNEAK) {
						tmpCharSkills[i] = 2;
					}
				break;
				case PLAYER_TYPE_GAMBLER:
					if (curskill == SKILL_SNEAK) {
						tmpCharSkills[i] = 5;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_COMMERCE) {
						tmpCharSkills[i] = 4;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_FENCING) {
						tmpCharSkills[i] = 3;
					}
					if (curskill == SKILL_LEADERSHIP) {
						tmpCharSkills[i] = 2;
					}
				break;
				case PLAYER_TYPE_GUNNER:
					if (curskill == SKILL_ACCURACY) {
						tmpCharSkills[i] = 5;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_CANNONS) {
						tmpCharSkills[i] = 5;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_FENCING) {
						tmpCharSkills[i] = 3;
					}
				break;
				case PLAYER_TYPE_MARINE:
					if (curskill == SKILL_FENCING) {
						tmpCharSkills[i] = 5;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_GRAPPLING) {
						tmpCharSkills[i] = 4;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_LEADERSHIP) {
						tmpCharSkills[i] = 3;
					}
					if (curskill == SKILL_SAILING) {
						tmpCharSkills[i] = 2;
					}
				break;
				case PLAYER_TYPE_MERCHANT:
					if (curskill == SKILL_SAILING) {
						tmpCharSkills[i] = 4;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_COMMERCE) {
						tmpCharSkills[i] = 5;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_DEFENCE) {
						tmpCharSkills[i] = 3;
					}
					if (curskill == SKILL_SNEAK) {
						tmpCharSkills[i] = 2;
					}
				break;
				case PLAYER_TYPE_NAVAL_OFFICER:
					if (curskill == SKILL_LEADERSHIP) {
						tmpCharSkills[i] = 5;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_SAILING) {
						tmpCharSkills[i] = 4;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_FENCING) {
						tmpCharSkills[i] = 3;
					}
					if (curskill == SKILL_DEFENCE) {
						tmpCharSkills[i] = 2;
					}
				break;
				case PLAYER_TYPE_PHYSICIAN:
					if (curskill == SKILL_DEFENCE) {
						tmpCharSkills[i] = 5;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_COMMERCE) {
						tmpCharSkills[i] = 4;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_LEADERSHIP) {
						tmpCharSkills[i] = 3;
					}
					if (curskill == SKILL_SNEAK) {
						tmpCharSkills[i] = 2;
					}
				break;
				case PLAYER_TYPE_QUARTERMASTER:
					if (curskill == SKILL_COMMERCE) {
						tmpCharSkills[i] = 5;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_LEADERSHIP) {
						tmpCharSkills[i] = 4;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_FENCING) {
						tmpCharSkills[i] = 3;
					}
					if (curskill == SKILL_SAILING) {
						tmpCharSkills[i] = 2;
					}
				break;
				case PLAYER_TYPE_REBEL:
					if (curskill == SKILL_FENCING) {
						tmpCharSkills[i] = 5;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_SNEAK) {
						tmpCharSkills[i] = 4;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_LEADERSHIP) {
						tmpCharSkills[i] = 3;
					}
					if (curskill == SKILL_SAILING) {
						tmpCharSkills[i] = 2;
					}
				break;
				case PLAYER_TYPE_ROGUE:
					if (curskill == SKILL_FENCING) {
						tmpCharSkills[i] = 5;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_COMMERCE) {
						tmpCharSkills[i] = 4;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_SNEAK) {
						tmpCharSkills[i] = 3;
					}
					if (curskill == SKILL_LEADERSHIP) {
						tmpCharSkills[i] = 2;
					}
				break;
				case PLAYER_TYPE_SAILOR:
					if (curskill == SKILL_FENCING) {
						tmpCharSkills[i] = 2;
					}
					if (curskill == SKILL_SAILING) {
						tmpCharSkills[i] = 5;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_REPAIR) {
						tmpCharSkills[i] = 4;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_DEFENCE) {
						tmpCharSkills[i] = 3;
					}
				break;
				case PLAYER_TYPE_SHIPWRIGHT:
					if (curskill == SKILL_REPAIR) {
						tmpCharSkills[i] = 5;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_COMMERCE) {
						tmpCharSkills[i] = 4;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_DEFENCE) {
						tmpCharSkills[i] = 3;
					}
					if (curskill == SKILL_GRAPPLING) {
						tmpCharSkills[i] = 2;
					}
				break;
				case PLAYER_TYPE_SMUGGLER:
					if (curskill == SKILL_COMMERCE) {
						tmpCharSkills[i] = 5;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_FENCING) {
						tmpCharSkills[i] = 4;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_SNEAK) {
						tmpCharSkills[i] = 3;
					}
					if (curskill == SKILL_SAILING) {
						tmpCharSkills[i] = 2;
					}
				break;
				case PLAYER_TYPE_SOCIAL_CLIMBER:
					if (curskill == SKILL_LEADERSHIP) {
						tmpCharSkills[i] = 5;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_FENCING) {
						tmpCharSkills[i] = 3;
					}
					if (curskill == SKILL_COMMERCE) {
						tmpCharSkills[i] = 4;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_SNEAK) {
						tmpCharSkills[i] = 2;
					}
				break;
				case PLAYER_TYPE_SWORD_MASTER:
					if (curskill == SKILL_FENCING) {
						tmpCharSkills[i] = 8;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_LEADERSHIP) {
						tmpCharSkills[i] = 3;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_SNEAK) {
						tmpCharSkills[i] = 2;
					}
				break;
				case PLAYER_TYPE_CASTAWAY:
					tmpCharSkills[i] = 1;
				break;
				case PLAYER_TYPE_CURSED:
					if (curskill == SKILL_FENCING) {
						tmpCharSkills[i] = 4;
					}
					if (curskill == SKILL_SAILING) {
						tmpCharSkills[i] = 3;
						tmpCharBonusSkills[i] = curSpeed;
					}
					if (curskill == SKILL_CANNONS) {
						tmpCharSkills[i] = 3;
					}
					if (curskill == SKILL_GRAPPLING) {
						tmpCharSkills[i] = 4;
						tmpCharBonusSkills[i] = curSpeed;
					}
				break;
			}
		}

		if(!AUTO_SKILL_SYSTEM)
		{
			if(sti(GetStorylineVar(slno, "START_MIN_LEVEL")) > 0)	tmpCharSkills[i] = 1;
			if (tmpPlayerType == PLAYER_TYPE_CUSTOM)				tmpCharSkills[i] = 1;
			tmpCharBonusSkills[i] = 1.0;
		}
		SetSkillShow(i);
	}
	if (tmpPlayerType == PLAYER_TYPE_CUSTOM) {
		SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblfreeskillpoints", TranslateString("", "Available points:"), FONT_NORMAL, 80, 374, COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
		SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "freeskillpoints", "" + GetFreeSkillPoints(), FONT_BOLD_NUMBERS, 255, 374, COLOR_NORMAL, 0, SCRIPT_ALIGN_RIGHT, true, 0.5, 0);
	} else {
		SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "lblfreeskillpoints", "", FONT_NORMAL, 70, 374, COLOR_NORMAL, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 0);
		SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "freeskillpoints", "", FONT_BOLD_NUMBERS, 255, 374, COLOR_NORMAL, 0, SCRIPT_ALIGN_RIGHT, true, 0.5, 0);
	}

	SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "playertypename", TranslateString("", GetPlayerTypeName(tmpPlayerType)), FONT_NORMAL, 162, 144, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
	SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "playertypedescription1", GetPlayerTypeDescription(tmpPlayerType, "a"), FONT_SHIPSLOG, 162, 175, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
	SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "playertypedescription2", GetPlayerTypeDescription(tmpPlayerType, "b"), FONT_SHIPSLOG, 162, 200, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
	SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "playertypedescription3", GetPlayerTypeDescription(tmpPlayerType, "c"), FONT_SHIPSLOG, 162, 225, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
	SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "playertypedescription4", GetPlayerTypeDescription(tmpPlayerType, "d"), FONT_SHIPSLOG, 162, 250, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
	SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "playertypedescription5", GetPlayerTypeDescription(tmpPlayerType, "e"), FONT_SHIPSLOG, 162, 275, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
	SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "playertypedescription6", GetPlayerTypeDescription(tmpPlayerType, "f"), FONT_SHIPSLOG, 162, 300, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
	SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "playertypedescription7", GetPlayerTypeDescription(tmpPlayerType, "g"), FONT_SHIPSLOG, 162, 325, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
	SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "playertypedescription8", GetPlayerTypeDescription(tmpPlayerType, "h"), FONT_SHIPSLOG, 162, 350, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
	SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "playertypedescription9", GetPlayerTypeDescription(tmpPlayerType, "i"), FONT_SHIPSLOG, 162, 375, COLOR_NORMAL, 0, SCRIPT_ALIGN_CENTER, true, 0.8, 0);
	SetSelectable("DIALOG_SELECT_BUTTON", curPlayerType != tmpPlayerType);
}

void CalculateBonuses(ref curVal, ref curSpeed)
{
	int v = 2;
	float s;
	curVal = v;

	if (SKILLS_UP_BONUS < 10) SKILLS_UP_BONUS = 10;
	if (SKILLS_UP_BONUS > 99) SKILLS_UP_BONUS = 99;
	s = makefloat(stf(SKILLS_UP_BONUS + 100) / 100.0);
	curSpeed = s;
}

void SetSkillShow(int iSkill)
{
	int idum;
	float bonusVal = tmpCharBonusSkills[iSkill];
	string sBonus = "" + bonusVal;
	string selector = "SELECTOR1";
	string sDispVal = "" + tmpCharSkills[iSkill];
	bool bCustom = tmpPlayerType == PLAYER_TYPE_CUSTOM;
	SetNodeUsing("SKILL_CHANGER" + iSkill, bCustom && AUTO_SKILL_SYSTEM);
	SetNodeUsing("SKILL_BUTTON"  + iSkill, bCustom && AUTO_SKILL_SYSTEM);
	if (bonusVal > 1.0) {
		SetSelectable("SKILL_BUTTON" + iSkill, bCustom);
		if (CheckAttribute(&GameInterface, "SELECTOR.used1"))
			selector = "SELECTOR2";
		else
			GameInterface.SELECTOR.used1 = true;
		SendMessage(&GameInterface, "lsllllll", MSG_INTERFACE_MSG_TO_NODE, selector, 0, 554, 144 + (iSkill * 26), 570, 160 + (iSkill * 26), 0);
		SetNodeUsing(selector, true);
	}
	else
	{
		SetSelectable("SKILL_BUTTON" + iSkill, false);
	}
	if (fmod(bonusVal, 1.0) == 0.0)
		sBonus = bonusVal + "00";
	else
		sBonus = strleft(sBonus, 4);
	if(AUTO_SKILL_SYSTEM)
	{
		SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "bonus" + iSkill, "x" + sBonus, FONT_NORMAL, 480, 149 + (iSkill * 26), COLOR_MONEY, 0, SCRIPT_ALIGN_RIGHT, true, 0.5, 0);
	}
	SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "skill" + iSkill, sDispVal, FONT_BOLD_NUMBERS, 525, 144 + (iSkill * 26), COLOR_NORMAL, 0, SCRIPT_ALIGN_RIGHT, true, 0.5, 0);
}

void ProcessSkillsValue(int iSkill, bool bRight)
{
	int i;
	if (tmpPlayerType != PLAYER_TYPE_CUSTOM) return;
	int freepoints = GetFreeSkillPoints();
	if (bRight) {
		if (freepoints <= 0 || tmpCharSkills[iSkill] > 1) return;
		tmpCharSkills[iSkill]++;
		freepoints--;
	} else {
		if (tmpCharSkills[iSkill] <= 1) return;
		tmpCharSkills[iSkill]--;
		freepoints++;
	}
	if (tmpCharSkills[iSkill] > 1) {
		if (!CheckAttribute(&GameInterface, "CustomSkill.Value.v1")) {
			GameInterface.CustomSkill.Value.v1 = iSkill;
		} else {
			if (!CheckAttribute(&GameInterface, "CustomSkill.Value.v2")) GameInterface.CustomSkill.Value.v2 = iSkill;
		}
	} else {
		if (CheckAttribute(&GameInterface, "CustomSkill.Value.v1") == true && sti(GameInterface.CustomSkill.Value.v1) == iSkill) DeleteAttribute(&GameInterface, "CustomSkill.Value.v1");
		if (CheckAttribute(&GameInterface, "CustomSkill.Value.v2") == true && sti(GameInterface.CustomSkill.Value.v2) == iSkill) DeleteAttribute(&GameInterface, "CustomSkill.Value.v2");
	}
	for (i = 0; i < NUM_DIFF_SKILLS; i++)
	{
		SetSkillShow(i);
	}
	SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "skill" + iSkill, "" + tmpCharSkills[iSkill], FONT_BOLD_NUMBERS, 525, 144 + (iSkill * 26), COLOR_NORMAL, 0, SCRIPT_ALIGN_RIGHT, true, 0.5, 0);
	SendMessage(&GameInterface, "lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, "WINDOWSTRINGES", 0, "freeskillpoints", "" + freepoints, FONT_BOLD_NUMBERS, 255, 374, COLOR_NORMAL, 0, SCRIPT_ALIGN_RIGHT, true, 0.5, 0);
	SetSelectable("DIALOG_SELECT_BUTTON", freepoints == 0);
}

void ProcessSkillsSpeed(int iSkill)
{
	if (tmpPlayerType != PLAYER_TYPE_CUSTOM) return;
	int i;
	float bonusVal = tmpCharBonusSkills[iSkill];
	string sBonus = "" + bonusVal;
	string selector = "SELECTOR1";
	string sSpeedAttr = "s1";
	if (fmod(bonusVal, 1.0) == 0.0)
		sBonus = bonusVal + "00";
	else
		sBonus = strleft(sBonus, 4);
	if (!CheckAttribute(&GameInterface, "SkillsSpeed")) {
		GameInterface.SkillsSpeed2Change = iSkill;
		GameInterface.SkillsSpeed = 1;
		for (i = 0; i < iSkill; i++)
		{
			if (tmpCharBonusSkills[i] > 1.0) {
				GameInterface.SkillsSpeed = 2;
				selector = "SELECTOR2";
				break;
			}
		}
	} else {
		selector = "SELECTOR" + GameInterface.SkillsSpeed;
	}
	if (iSkill == sti(GameInterface.SkillsSpeed2Change)) {
		tmpCharBonusSkills[iSkill] = 1.0;
		if (CheckAttribute(&GameInterface, "CustomSkill.Speed.s1") == true && sti(GameInterface.CustomSkill.Speed.s1) == iSkill) DeleteAttribute(&GameInterface, "CustomSkill.Speed.s1");
		if (CheckAttribute(&GameInterface, "CustomSkill.Speed.s2") == true && sti(GameInterface.CustomSkill.Speed.s2) == iSkill) DeleteAttribute(&GameInterface, "CustomSkill.Speed.s2");
		SetSkillShow(iSkill);
		SetNodeUsing(selector, false);
		for (i = 0; i < NUM_DIFF_SKILLS; i++)
		{
			SetSelectable("SKILL_BUTTON" + i, tmpCharBonusSkills[i] == 1.0);
		}
		SetSelectable("DIALOG_SELECT_BUTTON", false);
	} else {
		CalculateBonuses(&i, &bonusVal);
		tmpCharBonusSkills[iSkill] = bonusVal;
		if (CheckAttribute(&GameInterface, "SELECTOR.used1")) DeleteAttribute(&GameInterface, "SELECTOR.used1");
		if (CheckAttribute(&GameInterface, "CustomSkill.used1")) DeleteAttribute(&GameInterface, "CustomSkill.used1");
		for (i = 0; i < NUM_DIFF_SKILLS; i++)
		{
			if (tmpCharBonusSkills[i] > 1.0) {
				SetSelectable("SKILL_BUTTON" + i, true);
				if (CheckAttribute(&GameInterface, "CustomSkill.used1")) sSpeedAttr = "s2";
				GameInterface.CustomSkill.Speed.(sSpeedAttr) = iSkill;
				GameInterface.CustomSkill.used1 = true;
			}
			SetSkillShow(i);
		}
		DeleteAttribute(&GameInterface, "CustomSkill.used1");
		DeleteAttribute(&GameInterface, "SkillsSpeed2Change");
		DeleteAttribute(&GameInterface, "SkillsSpeed");
		SetSelectable("DIALOG_SELECT_BUTTON", GetFreeSkillPoints() == 0);
	}
}

int GetFreeSkillPoints()
{
	int i;
	int ret = 10+ADD_SKILLPOINTS_PERLEVEL*1;
	if (slno != FindDefaultStoryline()) ret = 10+ADD_SKILLPOINTS_PERLEVEL*5;
	for (i = 0; i < NUM_DIFF_SKILLS; i++)
	{
		ret -= tmpCharSkills[i];
	}
	return ret;
}

void NavyLockShipSelection(bool LockShip, ref model)
{
	bool canchangedate = true;
	if(CheckAttribute(arstart,"date.lock")) canchangedate = false;

	if (LockShip)
	{
		SetSelectable("SHIP", false);
		SetTextBoxReadOnly("ShipName", true);
		if (CheckAttribute(model, "ship") && GetAttribute(model, "playertype") == PLAYER_TYPE_NAVAL_OFFICER)
		{
			SetNodeUsing ("YEAR", false);
		}
		else
		{
			SetNodeUsing ("YEAR", canchangedate);
			curShip = -1;
			GameInterface.SHIP.pic1.str1 = "";
			GameInterface.SHIP.pic1.str2 = "";
			GameInterface.SHIP.pic1.img2 = "";
			GameInterface.SHIP.pic1.tex2 = -1;
			SendMessage(&GameInterface, "ls", MSG_INTERFACE_REFRESH_SCROLL, "SHIP");
			GameInterface.strings.ShipName = TranslateString("", "Navy Assignment");
		}
		if (GetAttribute(model, "playertype") == PLAYER_TYPE_NAVAL_OFFICER)
		{
			SetSelectable("NATIONFLAG_BUTTON", false);
		}
	}
	else
	{
		SetSelectable("SHIP", true);
		SetTextBoxReadOnly("ShipName", false);
		SetSelectable("NATIONFLAG_BUTTON", true);
		SetNodeUsing ("YEAR", canchangedate);
		if (curShip == -1)
		{
			curShip = GetShipIndex(arstart.ship);
			GameInterface.SHIP.pic1.str1 = "#" + ShipsTypes[curShip].Class;
			GameInterface.SHIP.pic1.str2 = ShipsTypes[curShip].SName;
			GameInterface.SHIP.pic1.img2 = GetShipPicName(curShip);
			GameInterface.SHIP.pic1.tex2 = 1 + GetShipTexture(curShip); // PB
			SendMessage(&GameInterface, "ls", MSG_INTERFACE_REFRESH_SCROLL, "SHIP");
			GameInterface.strings.ShipName = GetStorylineVar(slno, arstart.shipname);
		}
	}
}
