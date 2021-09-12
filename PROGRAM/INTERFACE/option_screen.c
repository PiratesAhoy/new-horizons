#define OPAGE_MAIN			0
#define OPAGE_SAILING		1
#define OPAGE_VIDEO			2
#define OPAGE_SOUNDS		3
#define OPAGE_CAMERA_MOD	4
#define OPAGE_CONTROLS_1	5
#define OPAGE_CONTROLS_2	6
#define OPAGE_CONTROLS_3	7
#define OPAGE_DIFFICULTY	8		//added by KAM
#define OPAGE_GAMEOPTION	9		//added by MAXIMUS
#define OPAGE_B_SETTINGS	10		//added by MAXIMUS

#define MAX_PAGES_QUANTITY	4

#define MAX_LANGUAGES        6
#define MAX_KEYBOARD_LAYOUTS 7
float i_fCurMusic;
float i_fCurSound;
float i_fCurDialog;

float i_fCurContrast = 0.5;
float i_fCurGamma = 0.5;
float i_fCurBright = 0.5;

float i_fCurXSens = 0.5;
float i_fCurYSens = 0.5;

int gi_nCurrentPage = -1;

bool g_bDisableControlChange = false;

string gsKeyWindowName;
string oldCurNode = "";
aref bSet;
int nCurScroll = -1;
int nCurSScrollNum = -1;
bool bScrollShow = false;

object objArrayControls;

string g_sGroupName;
int nLastTextGroupNum;
int nLastTextStringNum;
int curCntrlIdx;

int nFadeStr_AlUsed = 0;
int nFadeStr_NoStick = 0;

bool BS_changed = false;//MAXIMUS
// KK -->
int LanguageQty = 1;
int iSelectedInterfaceLanguage = GetInterfaceLanguage();
int iSelectedKeyboardLayout = GetKeyboardLayout();

ref PlayerProfile;
string current_profile;
// <-- KK

void InitInterface(string iniName)
{
	// PB: Prevent players from seeing the "stuck with all menu options" bug -->
	// Code responsible for this found and disabled below in IDoExit
	// InterfaceStates.Buttons.Resume.enable = false;
	// InterfaceStates.Buttons.Save.enable = false;
	// PB <--

// KK -->
	LanguageQty = 1;
	if (FindLocalLanguage("russian")) LanguageQty++;
	if (FindLocalLanguage("french")) LanguageQty++;
	if (FindLocalLanguage("german")) LanguageQty++;
	if (FindLocalLanguage("spanish")) LanguageQty++;
	if (FindLocalLanguage("polish")) LanguageQty++;
// <-- KK

	GameInterface.title = "titleOptions";

	if (GetTargetPlatform() == "pc") {
		g_bDisableControlChange = false;
		gsKeyWindowName = "KEYSWINDOW_PC";
	} else {
		g_bDisableControlChange = true;
		gsKeyWindowName = "KEYSWINDOW_XBOX";
	}

	// MAXIMUS -->
	//FillModelsScroll();
	//FillShipsScroll();
	// MAXIMUS <--

	ISetVariable();	// LDH moved above MSG_INTERFACE_INIT to set volume and mouse sensitivity sliders properly - 20Mar09

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

	// Screwface
	int idx = 0;
	if (CheckAttribute(&Globalsettings, "Storyline")) idx = sti(GlobalSettings.Storyline);
	CurrentStoryline = idx;
	string storyline = GetStoryline(CurrentStoryline);
	CurrentProfile = GetCurrentProfile(storyline);
	//stringlen = Globalsettings.profile.(storyline).len;
	current_profile = GetCurrentProfile(GetStoryline(FindCurrentStoryline()));
	//if (current_profile == "") {
		makeref(PlayerProfile, GlobalSettings);
	//} else {
	//	makeref(PlayerProfile, ProfileSettings);
	//}

	ISetVariable();
	StartVideoSetting();

	SetNodeUsing("KEY_CHOOSER",false);

	// MAXIMUS -->
	SetNodeUsing("CANCEL",false);
	SetNodeUsing("OPTIONS",false);
	SetFormatedText("REINITLANGUAGE",XI_ConvertString("Reinit_Language"));
	InitBuildOptions(false, true);
	makearef(bSet, PlayerProfile.BuildSettings);

	CreateString(false,"GameOptionTitle","",FONT_NORMAL,COLOR_NORMAL,320,90,SCRIPT_ALIGN_CENTER,1.3);
// KK -->
	iSelectedInterfaceLanguage = GetInterfaceLanguage();
	iSelectedKeyboardLayout = GetKeyboardLayout();
	CreateString(false, "LanguagesList", XI_ConvertString("Int" + GetInterfaceLanguageName(iSelectedInterfaceLanguage)), FONT_NORMAL, COLOR_NORMAL, 440, 250, SCRIPT_ALIGN_CENTER, 1.0);
	CreateString(false, "KeyboardLayoutList", XI_ConvertString("Int" + GetInterfaceLanguageName(iSelectedKeyboardLayout)), FONT_NORMAL, COLOR_NORMAL, 440, 300, SCRIPT_ALIGN_CENTER, 1.0);
// <-- KK
	CreateExitString();//MAXIMUS: standard exit-string for exit-button
	SetSelectable("EXIT_BUTTON",true);
//	SetSelectable("B_ADDITIONAL", false); // KK
	// MAXIMUS <--

	gi_nCurrentPage = OPAGE_MAIN;
	SetFormatedText("RESTORE_STRINGS",XI_ConvertString("Confirm default restore keys"));

	CreateString(false,"GroupName","",FONT_NORMAL,COLOR_NORMAL,320,140,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"shipModel","",FONT_NORMAL,COLOR_NORMAL,320,240,SCRIPT_ALIGN_CENTER,0.8);// MAXIMUS
	CreateString(false,"MusicScheme",GetMusicSchemeName(music_scheme),FONT_NORMAL,COLOR_NORMAL,320,210,SCRIPT_ALIGN_CENTER,1.2); // KK
	CreateString(true,"CurrentLanguage","",FONT_NORMAL,COLOR_NORMAL,305,134,SCRIPT_ALIGN_CENTER,0.8); // KK //MAXIMUS

	SetEventHandler("TitleSelect","DoTitleSelect",0);
	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);

	SetEventHandler("FormatedTextActivate","procFTActivate",0);
	SetEventHandler("evntUpdateFormtText","procFTUpdate",0);
	SetEventHandler("SetScrollerPos","procFTSetScrollPos",0);
	SetEventHandler("ScrollPosChange","ProcScrollPosChange",0);
	SetEventHandler("frame","IProcessFrame",0);
	SetEventHandler("evntKeyChoose","procKeyChoose",0);
	SetEventHandler("ScrollTopChange","ProcScrollChange",0);

	// MAXIMUS -->
	SetEventHandler("HideLanguagesButtons","AdditionalShow",0);
	SetEventHandler("LeftPress","LeftProcess",0);
	SetEventHandler("RightPress","RightProcess",0);
	SetEventHandler("UpPress","UpProcess",0);
	SetEventHandler("DownPress","DownProcess",0);
	SetEventHandler("ChangerLeft","ProcessChangeLeft",0);
	SetEventHandler("ChangerRight","ProcessChangeRight",0);
	SetEventHandler("IEvnt_MouseClick","IProcMouseClick",0);
	// MAXIMUS <--
// KK -->
	SetEventHandler("ChangeLanguageLeft", "ProcessLanguageLeft", 0);
	SetEventHandler("ChangeLanguageRight", "ProcessLanguageRight", 0);
	SetEventHandler("ChangeKeyboardLayoutLeft", "ProcessKeyboardLayoutLeft", 0);
	SetEventHandler("ChangeKeyboardLayoutRight", "ProcessKeyboardLayoutRight", 0);
// <-- KK

	aref ar; makearef(ar,objControlsState.key_codes);
	SendMessage(&GameInterface,"lsla",MSG_INTERFACE_MSG_TO_NODE,"KEY_CHOOSER", 0,ar);

	if( g_bDisableControlChange ) {
		SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"MB_CONTROLS", 0,"#"+XI_ConvertString("View Controls"));
	}

	SetNodeUsing("MB_CAMERA",g_bDisableControlChange);
// added by KAM -->
	CreateString(false,"DifficultyTitle",XI_ConvertString("Difficulty"),FONT_NORMAL,COLOR_NORMAL,320,90,SCRIPT_ALIGN_CENTER,1.3);
	CreateString(false,"NotificationTitle",XI_ConvertString("KAMNotification"),FONT_NORMAL,COLOR_NORMAL,320,310,SCRIPT_ALIGN_CENTER,1.0);

	SetSelectable("MB_DIFFICULTY",sti(InterfaceStates.Buttons.Resume.enable));
// <-- added by KAM

	SetEventHandler("evntFadeStrings","FadeStringsUpdate",0);
	PostEvent("evntFadeStrings",100);
}

void ISetVariable()
{
	// SOUNDS
	i_fCurMusic = 0.5;
	i_fCurSound = 0.5;
	i_fCurDialog = 0.5;

	SendMessage(&sound,"leee",MSG_SOUND_GET_MASTER_VOLUME,&i_fCurSound,&i_fCurMusic,&i_fCurDialog);

	GameInterface.nodes.music.value = i_fCurMusic;
	GameInterface.nodes.sound.value = i_fCurSound;
	GameInterface.nodes.dialog.value = i_fCurDialog;

	// MOUSE
	i_fCurXSens = 0.5;
	i_fCurYSens = 0.5;
	if( CheckAttribute(&InterfaceStates,"mouse.x_sens") ) {i_fCurXSens=stf(InterfaceStates.mouse.x_sens);}
	if( CheckAttribute(&InterfaceStates,"mouse.y_sens") ) {i_fCurYSens=stf(InterfaceStates.mouse.y_sens);}
	if(i_fCurXSens<0.0) i_fCurXSens = 0.0;
	if(i_fCurXSens>1.0) i_fCurXSens = 1.0;
	if(i_fCurYSens<0.0) i_fCurYSens = 0.0;
	if(i_fCurYSens>1.0) i_fCurYSens = 1.0;

	GameInterface.nodes.controls_x_sensive.value = i_fCurXSens;
	GameInterface.nodes.controls_y_sensive.value = i_fCurYSens;
}

void IProcessFrame()
{
	bool bYesChange = false;

	if(gi_nCurrentPage==OPAGE_SOUNDS)
	{
		if(i_fCurMusic!=stf(GameInterface.nodes.music.value)) {
			i_fCurMusic = stf(GameInterface.nodes.music.value);
			bYesChange = true;
		}
		if(i_fCurSound!=stf(GameInterface.nodes.sound.value)) {
			i_fCurSound = stf(GameInterface.nodes.sound.value);
			bYesChange = true;
		}
		if(i_fCurDialog!=stf(GameInterface.nodes.dialog.value)) {
			i_fCurDialog = stf(GameInterface.nodes.dialog.value);
			bYesChange = true;
		}
		if(bYesChange) {
			SendMessage(&sound,"lfff",MSG_SOUND_SET_MASTER_VOLUME,i_fCurSound,i_fCurMusic,i_fCurDialog);
		}
	}

	if(gi_nCurrentPage==OPAGE_VIDEO)
	{
		if(i_fCurContrast!=stf(GameInterface.nodes.contrast_slide.value)) {
			i_fCurContrast = stf(GameInterface.nodes.contrast_slide.value);
			bYesChange = true;
		}
		if(i_fCurGamma!=stf(GameInterface.nodes.gamma_slide.value)) {
			i_fCurGamma = stf(GameInterface.nodes.gamma_slide.value);
			bYesChange = true;
		}
		if(i_fCurBright!=stf(GameInterface.nodes.bright_slide.value)) {
			i_fCurBright = stf(GameInterface.nodes.bright_slide.value);
			bYesChange = true;
		}
		if(bYesChange) {
			XI_SetColorCorrection( ConvertContrast(i_fCurContrast,false), ConvertGamma(i_fCurGamma,false), ConvertBright(i_fCurBright,false) );
		}
	}

	if(gi_nCurrentPage==OPAGE_CONTROLS_1)
	{
		if(i_fCurXSens!=stf(GameInterface.nodes.controls_x_sensive.value)) {
			i_fCurXSens = stf(GameInterface.nodes.controls_x_sensive.value);
			bYesChange = true;
		}
		if(i_fCurYSens!=stf(GameInterface.nodes.controls_y_sensive.value)) {
			i_fCurYSens = stf(GameInterface.nodes.controls_y_sensive.value);
			bYesChange = true;
		}
		InterfaceStates.mouse.x_sens = i_fCurXSens;
		InterfaceStates.mouse.y_sens = i_fCurYSens;
		SetRealMouseSensitivity();
	}

	/*if(gi_nCurrentPage==OPAGE_B_SETTINGS)// MAXIMUS -->
	{
		if(nCurScroll!=sti(GameInterface.SETTINGSMODELSLIST.current))
		{
			nCurScroll = sti(GameInterface.SETTINGSMODELSLIST.current);
		}

		if(nCurSScrollNum!=sti(GameInterface.SETTINGSSHIPSLIST.current))
		{
			nCurSScrollNum = sti(GameInterface.SETTINGSSHIPSLIST.current);
		}
		SetNodeUsing("GLOWCURSOR",GetCurrentNode()!="VALUE_CHANGER");
	}*/
	// MAXIMUS -->
}

void ProcessCancelExit()
{
	IDoExit(RC_INTERFACE_OPTIONSCREEN_EXIT);
}

void IDoExit(int exitCode)
{
	bool isBSChanged = BS_changed; // KK

	DelEventHandler("TitleSelect","DoTitleSelect");
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcessCommandExecute");
	DelEventHandler("FormatedTextActivate","procFTActivate");
	DelEventHandler("evntUpdateFormtText","procFTUpdate");
	DelEventHandler("SetScrollerPos","procFTSetScrollPos");
	DelEventHandler("ScrollPosChange","ProcScrollPosChange");
	DelEventHandler("frame","IProcessFrame");
	DelEventHandler("evntKeyChoose","procKeyChoose");
	DelEventHandler("ScrollTopChange","ProcScrollChange");
	DelEventHandler("evntFadeStrings","FadeStringsUpdate");

	// MAXIMUS -->
	DelEventHandler("HideLanguagesButtons","AdditionalShow");
	DelEventHandler("LeftPress","LeftProcess");
	DelEventHandler("RightPress","RightProcess");
	DelEventHandler("UpPress","UpProcess");
	DelEventHandler("DownPress","DownProcess");
	DelEventHandler("ChangerLeft","ProcessChangeLeft");
	DelEventHandler("ChangerRight","ProcessChangeRight");
	DelEventHandler("IEvnt_MouseClick","IProcMouseClick");
	// MAXIMUS <--
// KK -->
	DelEventHandler("ChangeLanguageLeft", "ProcessLanguageLeft");
	DelEventHandler("ChangeLanguageRight", "ProcessLanguageRight");
	DelEventHandler("ChangeKeyboardLayoutLeft", "ProcessKeyboardLayoutLeft");
	DelEventHandler("ChangeKeyboardLayoutRight", "ProcessKeyboardLayoutRight");
// <-- KK

	ControlsMakeInvert();
	// Screwface
	string storyline = GetStoryline(CurrentStoryline);
	GlobalSettings.nomusicinterrupt = true; //MAXIMUS 02.05.2019: for preventing music interruption in main menu
	InitGlobalOptions(); // Screwface
	ref gopt; makeref(gopt, GlobalSettings);
	ReadMainOptions(&gopt);
	gopt.Storyline = CurrentStoryline;
	gopt.profile.(storyline) = CurrentProfile;
	//gopt.profile.(storyline).len = stringlen;
	WriteMainOptions(gopt);
	DeleteAttribute(GlobalSettings, "nomusicinterrupt"); //MAXIMUS 02.05.2019: for preventing music interruption in main menu
	if (isBSChanged) BS_Reinit();	// KK

//	ClearEvents();					// PB: This causes the "stuck with all menu options" bug
//	ClearPostEvents();				// PB: This prevents actions from updating properly during the game

	interfaceResultCommand = exitCode;
	if( CheckAttribute(&InterfaceStates,"InstantExit") && sti(InterfaceStates.InstantExit)==true ) {
		EndCancelInterface(true);
	} else {
		EndCancelInterface(false);
	}
}

// MAXIMUS -->
void IProcMouseClick()
{
	string nodName = GetEventData();
	int btnCode = GetEventData();

	if(nodName=="VALUE_CHANGER")
	{
		if(btnCode==0) ProcessChangeLeft();
		if(btnCode==1) ProcessChangeRight();
	}

	if (nodName == "MUSICSCHEME_CHANGER") {
		if (btnCode == 0) DoMusicSchemeChangeLeft();
		if (btnCode == 1) DoMusicSchemeChangeRight();
	}

// KK -->
	if (nodName == "LANGUAGE_CHANGER") {
		if (btnCode == 0) ProcessLanguageLeft();
		if (btnCode == 1) ProcessLanguageRight();
	}

	if (nodName == "KEYBOARDLAYOUT_CHANGER") {
		if (btnCode == 0) ProcessKeyboardLayoutLeft();
		if (btnCode == 1) ProcessKeyboardLayoutRight();
	}
// <-- KK
}
// MAXIMUS <--

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

// MAXIMUS interface MOD -->
	int x;ref tmpch;string tmpstr;
        if(nodName=="OPTIONS")
{
if(comName=="activate" || comName=="click")
	{
		ShowOptionsPage(OPAGE_MAIN);
		EndCancelInterface(false);

	}
}
        if(nodName=="CANCEL")
{
if(comName=="activate" || comName=="click")
	{
		ShowOptionsPage(OPAGE_CONTROLS_2);
		SetShowGroup("General");

	}
}
// MAXIMUS interface MOD <--
	if(strleft(nodName,23)=="SETTINGS_CHECKER_BUTTON")
	{
		if(comName=="activate" || comName=="click") { SetNewOption(GameInterface.Buildsettings.tempData, GetCheckBoxIndex(23, nodName)); }
	}
	if(strleft(nodName,13)=="SCROLL_BUTTON")
	{
		if(comName=="activate" || comName=="click") { MarkBox(GameInterface.Buildsettings.tempData, GetCheckBoxIndex(13, nodName)); }
	}

	switch(nodName)
	{
	case "MB_SAILING":
		if(comName=="activate" || comName=="click") {
			ShowOptionsPage(OPAGE_SAILING);
		}
	break;

	case "MB_VIDEO":
		if(comName=="activate" || comName=="click") {
			ShowOptionsPage(OPAGE_VIDEO);
		}
	break;

	case "MB_SOUNDS":
		if(comName=="activate" || comName=="click") {
			ShowOptionsPage(OPAGE_SOUNDS);
		}
	break;

	case "MB_CAMERA":
		if(comName=="activate" || comName=="click") {
			ShowOptionsPage(OPAGE_CAMERA_MOD);
		}
	break;

	case "MB_CONTROLS":
		if(comName=="activate" || comName=="click") {
			if( g_bDisableControlChange ) {ShowOptionsPage(OPAGE_CONTROLS_2);}
			else {ShowOptionsPage(OPAGE_CONTROLS_1);}
		}
		if(comName=="downstep")
		{
			if(GetSelectable("MB_CAMERA")) {SetCurrentNode("MB_CAMERA");}
		}
	break;
// added by MAXIMUS -->
	case "MB_GAMEOPTION":
		if(comName=="activate" || comName=="click") {ShowOptionsPage(OPAGE_GAMEOPTION);}
	break;

	case "B_NEWINTERFACE":
		if(comName=="activate" || comName=="click")
		{
			bNewInterface = true;
			ReinitInterface();
			DisplayInterfaceStatus();
			SetSelectable("B_NEWINTERFACE",false);
			SetSelectable("B_OLDINTERFACE",true);
			SetCurrentNode("B_OLDINTERFACE");
		}
	break;

	case "B_OLDINTERFACE":
		if(comName=="activate" || comName=="click")
		{
			bNewInterface = false;
			ReinitInterface();
			DisplayInterfaceStatus();
			SetSelectable("B_NEWINTERFACE",true);
			SetSelectable("B_OLDINTERFACE",false);
			SetCurrentNode("B_NEWINTERFACE");
		}
	break;

	case "B_NEWICONS":
		if(comName=="activate" || comName=="click")
		{
			bNewIcons = true;
			DisplayInterfaceStatus();
			SetSelectable("B_NEWICONS",false);
			SetSelectable("B_OLDICONS",true);
			SetCurrentNode("B_OLDICONS");
		}
	break;

	case "B_OLDICONS":
		if(comName=="activate" || comName=="click")
		{
			bNewIcons = false;
			DisplayInterfaceStatus();
			SetSelectable("B_NEWICONS",true);
			SetSelectable("B_OLDICONS",false);
			SetCurrentNode("B_NEWICONS");
		}
	break;

	/*case "B_ENGLISH":
		if(comName=="activate" || comName=="click")
		{
// KK -->
			LanguageSetLanguage("English");
			SetInterfaceLanguage(ILANG_ENG);
			SetKeyboardLayout(ILANG_ENG);
// <-- KK
			AdditionalHide();
			SetSelectable("B_ENGLISH",false);
			if(GetSelectable("B_FRENCH")) SetCurrentNode("B_FRENCH");
			else
			{
				if(GetSelectable("B_GERMAN")) SetCurrentNode("B_GERMAN");
				else
				{
					if(GetSelectable("B_SPANISH")) SetCurrentNode("B_SPANISH");
					else
					{
							if(GetSelectable("B_POLISH")) SetCurrentNode("B_POLISH");
							else
							{
								if(GetSelectable("B_RUSSIAN")) SetCurrentNode("B_RUSSIAN");
								else SetCurrentNode("LANGUAGETITLE");
							}
					}
				}
			}
			InitLocalization();
			SetFormatedText("REINITLANGUAGE",XI_ConvertString("Reinit_Language"));//MAXIMUS
			SetNewLanguageView();//MAXIMUS
		}
	break;

	case "B_RUSSIAN":
		if(comName=="activate" || comName=="click")
		{
			LanguageSetLanguage("Russian");
			SetInterfaceLanguage(ILANG_RUS);
			SetKeyboardLayout(ILANG_RUS);
			AdditionalHide();
			SetSelectable("B_RUSSIAN",false);
			if(GetSelectable("B_FRENCH")) SetCurrentNode("B_FRENCH");
			else
			{
				if(GetSelectable("B_GERMAN")) SetCurrentNode("B_GERMAN");
				else
				{
					if(GetSelectable("B_SPANISH")) SetCurrentNode("B_SPANISH");
					else
					{
							if(GetSelectable("B_POLISH")) SetCurrentNode("B_POLISH"); // KK
							else
							{
								if(GetSelectable("B_ENGLISH")) SetCurrentNode("B_ENGLISH"); // KK
								else SetCurrentNode("LANGUAGETITLE");
							}
					}
				}
			}
			InitLocalization();
			SetFormatedText("REINITLANGUAGE",XI_ConvertString("Reinit_Language"));//MAXIMUS
			SetNewLanguageView();//MAXIMUS
		}
	break;

	case "B_FRENCH":
		if(comName=="activate" || comName=="click")
		{
			LanguageSetLanguage("French");
			SetInterfaceLanguage(ILANG_FRA);
			SetKeyboardLayout(ILANG_FRA);
			AdditionalHide();
			SetSelectable("B_FRENCH",false);
			if(GetSelectable("B_GERMAN")) SetCurrentNode("B_GERMAN");
			else
			{
				if(GetSelectable("B_SPANISH")) SetCurrentNode("B_SPANISH");
				else
				{
					if(GetSelectable("B_POLISH")) SetCurrentNode("B_POLISH"); // KK
					else
					{
						if(GetSelectable("B_ENGLISH")) SetCurrentNode("B_ENGLISH"); // KK
						else
						{
							if(GetSelectable("B_RUSSIAN")) SetCurrentNode("B_RUSSIAN");
							else SetCurrentNode("LANGUAGETITLE");
						}
					}
				}
			}
			InitLocalization();
			SetFormatedText("REINITLANGUAGE",XI_ConvertString("Reinit_Language"));//MAXIMUS
			SetNewLanguageView();//MAXIMUS
		}
	break;

	case "B_GERMAN":
		if(comName=="activate" || comName=="click")
		{
			LanguageSetLanguage("German");
			SetInterfaceLanguage(ILANG_GER);
			SetKeyboardLayout(ILANG_GER);
			AdditionalHide();
			SetSelectable("B_GERMAN",false);
			if(GetSelectable("B_SPANISH")) SetCurrentNode("B_SPANISH");
			else
			{
				if(GetSelectable("B_POLISH")) SetCurrentNode("B_POLISH"); // KK
				else
				{
					if(GetSelectable("B_ENGLISH")) SetCurrentNode("B_ENGLISH"); // KK
					else
					{
						if(GetSelectable("B_RUSSIAN")) SetCurrentNode("B_RUSSIAN");
						else
						{
							if(GetSelectable("B_FRENCH")) SetCurrentNode("B_FRENCH");
							else SetCurrentNode("LANGUAGETITLE");
						}
					}
				}
			}
			InitLocalization();
			SetFormatedText("REINITLANGUAGE",XI_ConvertString("Reinit_Language"));//MAXIMUS
			SetNewLanguageView();//MAXIMUS
		}
	break;

	case "B_SPANISH":
		if(comName=="activate" || comName=="click")
		{
			LanguageSetLanguage("Spanish"); // KK
			SetInterfaceLanguage(ILANG_SPA);
			SetKeyboardLayout(ILANG_SPA);
			AdditionalHide();
			SetSelectable("B_SPANISH",false);
			if(GetSelectable("B_POLISH")) SetCurrentNode("B_POLISH"); // KK
			else {
				if(GetSelectable("B_ENGLISH")) SetCurrentNode("B_ENGLISH"); // KK
				else
				{
					if(GetSelectable("B_RUSSIAN")) SetCurrentNode("B_RUSSIAN");
					else
					{
						if(GetSelectable("B_FRENCH")) SetCurrentNode("B_FRENCH");
						else
						{
							if(GetSelectable("B_GERMAN")) SetCurrentNode("B_GERMAN");
							else SetCurrentNode("LANGUAGETITLE");
						}
					}
				}
			}
			InitLocalization();
			SetFormatedText("REINITLANGUAGE",XI_ConvertString("Reinit_Language"));//MAXIMUS
			SetNewLanguageView();//MAXIMUS
		}
	break;

// KK -->
	case "B_POLISH":
		if(comName=="activate" || comName=="click")
		{
			LanguageSetLanguage("Polish");
			SetInterfaceLanguage(ILANG_POL);
			SetKeyboardLayout(ILANG_POL);
			AdditionalHide();
			SetSelectable("B_POLISH",false);
			if(GetSelectable("B_SPANISH")) SetCurrentNode("B_SPANISH");
			else {
				if(GetSelectable("B_ENGLISH")) SetCurrentNode("B_ENGLISH");
				else
				{
					if(GetSelectable("B_RUSSIAN")) SetCurrentNode("B_RUSSIAN");
					else
					{
						if(GetSelectable("B_FRENCH")) SetCurrentNode("B_FRENCH");
						else
						{
							if(GetSelectable("B_GERMAN")) SetCurrentNode("B_GERMAN");
							else SetCurrentNode("LANGUAGETITLE");
						}
					}
				}
			}
			InitLocalization();
			SetFormatedText("REINITLANGUAGE",XI_ConvertString("Reinit_Language"));//MAXIMUS
			SetNewLanguageView();//MAXIMUS
		}
	break;*/
	case "B_SELECTLANGUAGE":
		LanguageSetLanguage(GetInterfaceLanguageName(iSelectedInterfaceLanguage));
		SetInterfaceLanguage(iSelectedInterfaceLanguage);
		SetKeyboardLayout(iSelectedKeyboardLayout);
		GetLanguageParameters();
		UpdateCharactersNames();
		AdditionalShow();
	break;

	case "B_CANCELLANGUAGE":
		iSelectedInterfaceLanguage = GetInterfaceLanguage();
		iSelectedKeyboardLayout = GetKeyboardLayout();
		AdditionalShow();
	break;
// <-- KK

	case "B_ANION":
		if(comName=="activate" || comName=="click")
		{
			bAnimation = true;
			DisplayInterfaceStatus();
			SetSelectable("B_ANION",false);
			SetSelectable("B_ANIOFF",true);
			SetCurrentNode("B_ANIOFF");
		}
	break;

	case "B_ANIOFF":
		if(comName=="activate" || comName=="click")
		{
			bAnimation = false;
			DisplayInterfaceStatus();
			SetSelectable("B_ANION",true);
			SetSelectable("B_ANIOFF",false);
			SetCurrentNode("B_ANION");
		}
	break;

	case "B_LANGUAGES":
		if(comName=="activate" || comName=="click")
		{
			AdditionalHide();
// KK -->
			/*SetSelectable("B_" + GetInterfaceLanguageName(GetInterfaceLanguage()), false);
			if(!bInterfaceRus && !bInterfaceFra && !bInterfaceGer && !bInterfaceSpa && !bInterfacePol) SetSelectable("B_ENGLISH", false); // KK
			if(bInterfaceRus) SetSelectable("B_RUSSIAN",false);
			if(bInterfaceFra) SetSelectable("B_FRENCH",false);
			if(bInterfaceGer) SetSelectable("B_GERMAN",false);
			if(bInterfaceSpa) SetSelectable("B_SPANISH",false);
			if(bInterfacePol) SetSelectable("B_POLISH",false); // KK
			if(GetSelectable("B_ENGLISH")) SetCurrentNode("B_ENGLISH"); // KK
			else
			{
				if(GetSelectable("B_RUSSIAN")) SetCurrentNode("B_RUSSIAN");
				else
				{
					if(GetSelectable("B_FRENCH")) SetCurrentNode("B_FRENCH");
					else
					{
						if(GetSelectable("B_GERMAN")) SetCurrentNode("B_GERMAN");
						else
						{
							if(GetSelectable("B_SPANISH")) SetCurrentNode("B_SPANISH");
							else
							{
								if(GetSelectable("B_POLISH")) SetCurrentNode("B_POLISH"); // KK
								else SetCurrentNode("LANGUAGETITLE");
							}
						}
					}
				}
			}*/
		}
	break;

	case "MB_BUILDSETTINGS":
		if(comName=="activate" || comName=="click") { ShowOptionsPage(OPAGE_B_SETTINGS); }
	break;

	case "SETTINGS_OK_BUTTON":
		if(comName=="activate" || comName=="click") { BS_changed = true; UpdateSettings(GameInterface.Buildsettings.tempData); }
		if(comName=="rightstep") { if(GetSelectable("SETTINGS_CANCEL_BUTTON")) { SetCurrentNode("SETTINGS_CANCEL_BUTTON"); } }
		if(comName=="deactivate") { SetSettingsList(); }
	break;

	case "SETTINGS_CANCEL_BUTTON":
		if(comName=="deactivate" || comName=="activate" || comName=="click") { SetSettingsList(); }
		if(comName=="leftstep") { if(GetSelectable("SETTINGS_OK_BUTTON")) { SetCurrentNode("SETTINGS_OK_BUTTON"); } }
	break;

	case "SETTINGS_WINDOW":
		if(comName=="deactivate") { ShowOptionsPage(OPAGE_MAIN); SetCurrentNode("MB_BUILDSETTINGS"); }
	break;

	case "SETTINGS_DEFAULT_BUTTON":
		if(comName=="deactivate") { SetCurrentNode("SETTINGS_WINDOW"); }
		if(comName=="activate" || comName=="click") { ShowSettingsDescribe("SettingsDefault", -1); }
	break;
// added by MAXIMUS <--

// added by KAM -->
	case "MB_DIFFICULTY":
		if(comName=="activate" || comName=="click")
		{
			ShowOptionsPage(OPAGE_DIFFICULTY);
		}
	break;

	case "B_DIFFICULTY1":
		if(comName=="deactivate")
		{
			ShowOptionsPage(OPAGE_MAIN);
			SetCurrentNode("MB_DIFFICULTY");
		}
		if(comName=="activate" || comName=="click")
		{
			SetDifficulty(1);
			SetSelectable("B_DIFFICULTY1",false);
			SetSelectable("B_DIFFICULTY2",true);
			SetSelectable("B_DIFFICULTY3",true);
			SetSelectable("B_DIFFICULTY4",true);
			SetCurrentNode("B_DIFFICULTY2");
			KAM_DisplayDifficulty();
		}
	break;

	case "B_DIFFICULTY2":
		if(comName=="deactivate")
		{
			ShowOptionsPage(OPAGE_MAIN);
			SetCurrentNode("MB_DIFFICULTY");
		}
		if(comName=="activate" || comName=="click")
		{
			SetDifficulty(2);
			SetSelectable("B_DIFFICULTY2",false);
			SetSelectable("B_DIFFICULTY1",true);
			SetSelectable("B_DIFFICULTY3",true);
			SetSelectable("B_DIFFICULTY4",true);
			SetCurrentNode("B_DIFFICULTY3");
			KAM_DisplayDifficulty();
		}
	break;

	case "B_DIFFICULTY3":
		if(comName=="deactivate")
		{
			ShowOptionsPage(OPAGE_MAIN);
			SetCurrentNode("MB_DIFFICULTY");
		}
		if(comName=="activate" || comName=="click")
		{
			SetDifficulty(3);
			SetSelectable("B_DIFFICULTY3",false);
			SetSelectable("B_DIFFICULTY1",true);
			SetSelectable("B_DIFFICULTY2",true);
			SetSelectable("B_DIFFICULTY4",true);
			SetCurrentNode("B_DIFFICULTY4");
			KAM_DisplayDifficulty();
		}
	break;

	case "B_DIFFICULTY4":
		if(comName=="deactivate")
		{
			ShowOptionsPage(OPAGE_MAIN);
			SetCurrentNode("MB_DIFFICULTY");
		}
		if(comName=="activate" || comName=="click")
		{
			SetDifficulty(4);
			SetSelectable("B_DIFFICULTY4",false);
			SetSelectable("B_DIFFICULTY1",true);
			SetSelectable("B_DIFFICULTY2",true);
			SetSelectable("B_DIFFICULTY3",true);
			SetCurrentNode("B_DIFFICULTY1");
			KAM_DisplayDifficulty();
		}
	break;

	case "B_NOTIFICATION":
		if(comName=="deactivate")
		{
			ShowOptionsPage(OPAGE_MAIN);
			SetCurrentNode("MB_DIFFICULTY");
		}
		if(comName=="activate" || comName=="click")
		{
			KAM_ChangeNotification();
		}
	break;
// <-- added by KAM

	// PB: Realism Settings menu cleaned up and clarified -->
	case "REALISMMODE_0":
		if(comName=="activate" || comName=="click")
		{
			iRealismMode = 0;
			TmpI_ShowArcadeMode();
		}
	break;

	case "REALISMMODE_1":
		if(comName=="activate" || comName=="click")
		{
			iRealismMode = 1;
			TmpI_ShowArcadeMode();
		}
	break;

	case "REALISMMODE_2":
		if(comName=="activate" || comName=="click")
		{
			iRealismMode = 2;
			TmpI_ShowArcadeMode();
		}
	break;
	// PB: Realism Settings menu cleaned up and clarified <--

// ccc -->
	case "REALBATTLE_1":
		if(comName=="activate" || comName=="click")
		{
			bRealBattleInterface = false;
			ChangeBattleIconsSetting();
			RefreshBattleInterface(false);
		}
	break;

	case "REALBATTLE_2":
		if(comName=="activate" || comName=="click")
		{
			bRealBattleInterface = true;
			ChangeBattleIconsSetting();
			RefreshBattleInterface(false);
		}
	break;
// ccc <--

	case "CAMERAMODE_1":
		if(comName=="activate" || comName=="click")
		{
			locCameraEnableSpecialMode = true;
			TmpI_ShowCameraMode();
		}
	break;

	case "CAMERAMODE_2":
		if(comName=="activate" || comName=="click")
		{
			locCameraEnableSpecialMode = false;
			TmpI_ShowCameraMode();
		}
	break;





	case "VIDEO_DEFAULT":
		if(comName=="activate" || comName=="click") {
			ISetColorCorrection(1.0, 1.0, 0.0);
		}
	break;

	case "VIDEO_SAVE":
		if(comName=="activate" || comName=="click") {
			SaveVideoSettings();
		}
	break;





	case "CONTROLS_B_CHANGE":
		if(comName=="activate" || comName=="click") {
			ShowOptionsPage(OPAGE_CONTROLS_2);
		}
	break;
	case "CONTROLS_B_DEFAULT":
		if(comName=="activate" || comName=="click")
		{
			SetNodeUsing("RESTORE_RECT",true);
			SetNodeUsing("RESTORE_STRINGS",true);
			SetNodeUsing("RESTORE_OK",true);
			SetNodeUsing("RESTORE_CANCEL",true);
			SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "RESTORE_OK");
			SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "RESTORE_CANCEL");
			SetCurrentNode("RESTORE_OK");
		}
		if(comName=="downstep" && GetTargetPlatform()=="pc")
		{
			SetCurrentNode("CONTROLS_B_INVERT");
		}
	break;
	case "RESTORE_OK":
		if(comName=="activate" || comName=="click")
		{
			SetMouseToDefault();
			ControlsInit(GetTargetPlatform(),false);
			SetNodeUsing("RESTORE_RECT",false);
			SetNodeUsing("RESTORE_STRINGS",false);
			SetNodeUsing("RESTORE_OK",false);
			SetNodeUsing("RESTORE_CANCEL",false);
			SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
			SetCurrentNode("CONTROLS_B_DEFAULT");
		}
		if(comName=="deactivate")
		{
			SetNodeUsing("RESTORE_RECT",false);
			SetNodeUsing("RESTORE_STRINGS",false);
			SetNodeUsing("RESTORE_OK",false);
			SetNodeUsing("RESTORE_CANCEL",false);
			SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
			SetCurrentNode("CONTROLS_B_DEFAULT");
		}
	break;
	case "RESTORE_CANCEL":
		if(comName=="activate" || comName=="click" || comName=="deactivate")
		{
			SetNodeUsing("RESTORE_RECT",false);
			SetNodeUsing("RESTORE_STRINGS",false);
			SetNodeUsing("RESTORE_OK",false);
			SetNodeUsing("RESTORE_CANCEL",false);
			SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
			SetCurrentNode("CONTROLS_B_DEFAULT");
		}
	break;
	case "CONTROLS_B_INVERT":
		if(comName=="activate" || comName=="click")
		{
			MakeCamerasInvert();
			TmpI_ShowInvertMode();
		}
	break;



	case "B_SAILING1ST":
		if(comName=="deactivate")
		{
			if( g_bDisableControlChange ) {
				ShowOptionsPage(OPAGE_MAIN);
				SetCurrentNode("MB_CONTROLS");
			} else {
				ShowOptionsPage(OPAGE_CONTROLS_1);
				SetCurrentNode("CONTROLS_B_CHANGE");
			}
		}
		if(comName=="activate" || comName=="click")
		{
			ShowOptionsPage(OPAGE_CONTROLS_3);
			SetShowGroup("Sailing1Pers");
		}
	break;

	// added by KAM after build 11 -->
	case "B_GENERALCONTROLS":
		if(comName=="deactivate")
		{
			if( g_bDisableControlChange ) {
				ShowOptionsPage(OPAGE_MAIN);
				SetCurrentNode("MB_CONTROLS");
			} else {
				ShowOptionsPage(OPAGE_CONTROLS_1);
				SetCurrentNode("CONTROLS_B_CHANGE");
			 }

		}
		if(comName=="activate" || comName=="click")
		{
			ShowOptionsPage(OPAGE_CONTROLS_3);
			SetShowGroup("General");
		}
	break;
	case "B_WORLDMAPCONTROLS":
		if(comName=="deactivate")
		{
			if( g_bDisableControlChange ) {
				ShowOptionsPage(OPAGE_MAIN);
				SetCurrentNode("MB_CONTROLS");
			} else {
				ShowOptionsPage(OPAGE_CONTROLS_1);
				SetCurrentNode("CONTROLS_B_CHANGE");
			}
		}
		if(comName=="activate" || comName=="click")
		{
			ShowOptionsPage(OPAGE_CONTROLS_3);
			SetShowGroup("WorldMapControls");
		}
	break;
// <-- added by KAM after build 11

	case "B_PRIMARY_LAND":
		if(comName=="deactivate")
		{
			if( g_bDisableControlChange ) {
				ShowOptionsPage(OPAGE_MAIN);
				SetCurrentNode("MB_CONTROLS");
			} else {
				ShowOptionsPage(OPAGE_CONTROLS_1);
				SetCurrentNode("CONTROLS_B_CHANGE");
			}
		}
		if(comName=="activate" || comName=="click")
		{
			ShowOptionsPage(OPAGE_CONTROLS_3);
			SetShowGroup("PrimaryLand");
		}
	break;
	case "B_SAILING3RD":
		if(comName=="deactivate")
		{
			if( g_bDisableControlChange ) {
				ShowOptionsPage(OPAGE_MAIN);
				SetCurrentNode("MB_CONTROLS");
			} else {
				ShowOptionsPage(OPAGE_CONTROLS_1);
				SetCurrentNode("CONTROLS_B_CHANGE");
			}
		}
		if(comName=="activate" || comName=="click")
		{
			ShowOptionsPage(OPAGE_CONTROLS_3);
			SetShowGroup("Sailing3Pers");
		}
	break;
	case "B_FIGHTMODE":
		if(comName=="deactivate")
		{
			if( g_bDisableControlChange ) {
				ShowOptionsPage(OPAGE_MAIN);
				SetCurrentNode("MB_CONTROLS");
			} else {
				ShowOptionsPage(OPAGE_CONTROLS_1);
				SetCurrentNode("CONTROLS_B_CHANGE");
			}
		}
		if(comName=="activate" || comName=="click")
		{
			ShowOptionsPage(OPAGE_CONTROLS_3);
			SetShowGroup("FightModeControls");
		}
	break;

	case "CONTROLSWINDOW":
		if(comName=="deactivate") {
			ShowOptionsPage(OPAGE_CONTROLS_2);
			SetOldButton();
		}
	break;



	case "SET_BUTTON":
		if(comName=="deactivate") {
			ReturnToViewControls();
		}
		if(comName=="activate" || comName=="click") {
			ReturnToViewControls();
			SetReassignMode();
		}
		if(comName=="downstep")
		{
			if(GetSelectable("DELETE_BUTTON"))
			{	SetCurrentNode("DELETE_BUTTON");
			}
			else
			{
				if(GetSelectable("INVERSE_BUTTON"))
				{	SetCurrentNode("INVERSE_BUTTON");
				}
			}
		}
	break;

	case "DELETE_BUTTON":
		if(comName=="deactivate") {
			ReturnToViewControls();
		}
		if(comName=="activate" || comName=="click") {
			ReturnToViewControls();
			UnmapControl();
		}
		if(comName=="downstep")
		{
			if(GetSelectable("INVERSE_BUTTON"))
				{	SetCurrentNode("INVERSE_BUTTON");	}
		}
		if(comName=="upstep")
			{	SetCurrentNode("SET_BUTTON")	}
	break;

	case "INVERSE_BUTTON":
		if(comName=="deactivate") {
			ReturnToViewControls();
		}
		if(comName=="activate" || comName=="click") {
			InverseControl();
			ReturnToViewControls();
		}
		if(comName=="upstep")
		{
			if(GetSelectable("DELETE_BUTTON"))
				{	SetCurrentNode("DELETE_BUTTON");	}
			else
				{	SetCurrentNode("SET_BUTTON");	}
		}
	break;

	}
}

void TmpI_ShowArcadeMode()
{
	// PB: Realism Settings menu cleaned up and clarified -->
	int tmpLangFileID = LanguageOpenFile("SettingsDescribe.txt");
	SetFormatedText("REALISM_DESCRIPTION", LanguageConvertString(tmpLangFileID, "REALISMMODE_"+iRealismMode) );
	switch(iRealismMode)
	{
		case 0:
			CreateImage("ArcadeModeImg","icons","complete",532,138,564,170);
			SetSelectable("REALISMMODE_0",false);
			SetSelectable("REALISMMODE_1",true);
			SetSelectable("REALISMMODE_2",true);
			if(bRealBattleInterface)
			{
				if(NAVIGATION_EQUIPMENT)
				{
					GameInterface.pictures.BattlePic.pic = -1;
					GameInterface.pictures.BattlePic.tex = -1;
				}
				else CreateImage("BattlePic","icons","complete",532,424,564,456);
				SetSelectable("REALBATTLE_1", !NAVIGATION_EQUIPMENT);
				SetSelectable("REALBATTLE_2", false);
			}
			else
			{
				if(NAVIGATION_EQUIPMENT)
				{
					GameInterface.pictures.BattlePic.pic = -1;
					GameInterface.pictures.BattlePic.tex = -1;
				}
				else CreateImage("BattlePic","icons","complete",532,382,564,414);
				SetSelectable("REALBATTLE_1", false);
				SetSelectable("REALBATTLE_2", !NAVIGATION_EQUIPMENT);
			}
			SetCurrentNode("REALISMMODE_1");
		break;

		case 1:
			CreateImage("ArcadeModeImg","icons","complete",532,180,564,212);
			SetSelectable("REALISMMODE_0",true);
			SetSelectable("REALISMMODE_1",false);
			SetSelectable("REALISMMODE_2",true);
			SetSelectable("REALBATTLE_1", false);
			SetSelectable("REALBATTLE_2", false);
			GameInterface.pictures.BattlePic.pic = -1;
			GameInterface.pictures.BattlePic.tex = -1;
			SetCurrentNode("REALISMMODE_2");
		break;

		case 2:
			CreateImage("ArcadeModeImg","icons","complete",532,222,564,254);
			SetSelectable("REALISMMODE_0",true);
			SetSelectable("REALISMMODE_1",true);
			SetSelectable("REALISMMODE_2",false);
			SetSelectable("REALBATTLE_1", false);
			SetSelectable("REALBATTLE_2", false);
			GameInterface.pictures.BattlePic.pic = -1;
			GameInterface.pictures.BattlePic.tex = -1;
			SetCurrentNode("REALISMMODE_0");
		break;
	}
	LanguageCloseFile(tmpLangFileID);
	// PB: Realism Settings menu cleaned up and clarified <--
}

void TmpI_ShowCameraMode()
{
	if(locCameraEnableSpecialMode) {
		CreateImage("CameraModeImg","icons","complete",532,206,564,238);
	} else {
		CreateImage("CameraModeImg","icons","complete",532,262,564,294);
	}
}

void TmpI_ShowInvertMode()
{
	if( CheckAttribute(&InterfaceStates,"InvertCameras") && sti(InterfaceStates.InvertCameras)==true ) {
		CreateImage("InvertCameraImg","icons","complete",532,284,564,316);
	} else {
		CreateImage("InvertCameraImg","","",0,0,0,0);
	}
}

void ShowOptionsPage(int pageNum)
{
	if(pageNum==gi_nCurrentPage) return;

	switch(gi_nCurrentPage)
	{
	case OPAGE_MAIN:
		SetNodeUsing("CANCEL",false); // MAXIMUS interface MOD
		SetNodeUsing("OPTIONS",false); // MAXIMUS interface MOD
		SetNodeUsing("MB_SAILING",false);
		SetNodeUsing("MB_VIDEO",false);
		SetNodeUsing("MB_SOUNDS",false);
		SetNodeUsing("MB_CAMERA",false);
		SetNodeUsing("MB_CONTROLS",false);
		SetNodeUsing("MB_GAMEOPTION",false); // added by MAXIMUS
		SetNodeUsing("MB_BUILDSETTINGS",false); // added by MAXIMUS
		SetNodeUsing("MB_DIFFICULTY",false);				//added by KAM
	break;
	case OPAGE_SAILING:
		SetNodeUsing("CANCEL",false); // MAXIMUS interface MOD
		SetNodeUsing("OPTIONS",false); // MAXIMUS interface MOD
		SetNodeUsing("SUBTITLE",false);
		SetNodeUsing("STRINGS_ARCADEMODE",false);
		SetNodeUsing("REALISMMODE_0",false);
		SetNodeUsing("REALISMMODE_1",false);
		SetNodeUsing("REALISMMODE_2",false);
		SetNodeUsing("REALBATTLE_1",false);
		SetNodeUsing("REALBATTLE_2",false);
		SetNodeUsing("REALISM_DESCRIPTION", false);		// PB
		GameInterface.pictures.ArcadeModeImg.pic = -1;
		GameInterface.pictures.ArcadeModeImg.tex = -1;
		GameInterface.pictures.BattlePic.pic = -1;
		GameInterface.pictures.BattlePic.tex = -1;
		SetCurrentNode("MB_SAILING");
	break;
	case OPAGE_VIDEO:
		SetNodeUsing("CANCEL",false); // MAXIMUS interface MOD
		SetNodeUsing("OPTIONS",false); // MAXIMUS interface MOD
		SetNodeUsing("SUBTITLE",false);
		SetNodeUsing("STRINGS_VIDEO",false);
		SetNodeUsing("VIDEO_DEFAULT",false);
		SetNodeUsing("GAMMA_SLIDE",false);
		SetNodeUsing("BRIGHT_SLIDE",false);
		SetNodeUsing("CONTRAST_SLIDE",false);
		SetNodeUsing("VIDEO_SAVE",false);
		StartVideoSetting();
		SetCurrentNode("MB_VIDEO");
	break;
	case OPAGE_SOUNDS:
		SetNodeUsing("CANCEL",false); // MAXIMUS interface MOD
		SetNodeUsing("OPTIONS",false); // MAXIMUS interface MOD
		SetNodeUsing("SUBTITLE",false);
		SetNodeUsing("STRINGS_SOUNDS",false);
		DisableString("MusicScheme"); // KK
		SetNodeUsing("RAMKA1",false); // KK
		SetNodeUsing("MUSICSCHEME_RAMKA",false); // KK
		SetNodeUsing("MUSICSCHEME_CHANGER",false); // KK
		SetNodeUsing("DIALOG",false);
		SetNodeUsing("SOUND",false);
		SetNodeUsing("MUSIC",false);
		SetCurrentNode("MB_SOUNDS");
	break;
	case OPAGE_CAMERA_MOD:
		SetNodeUsing("CANCEL",false); // MAXIMUS interface MOD
		SetNodeUsing("OPTIONS",false); // MAXIMUS interface MOD
		SetNodeUsing("SUBTITLE",false);
		SetNodeUsing("STRINGS_CAMERA",false);
		SetNodeUsing("CAMERAMODE_1",false);
		SetNodeUsing("CAMERAMODE_2",false);
		GameInterface.pictures.CameraModeImg.pic = -1;
		GameInterface.pictures.CameraModeImg.tex = -1;
		SetCurrentNode("MB_CAMERA");
	break;

	case OPAGE_CONTROLS_1:
		SetNodeUsing("CANCEL",false); // MAXIMUS interface MOD
		SetNodeUsing("OPTIONS",false); // MAXIMUS interface MOD
		SetNodeUsing("SUBTITLE",false);
		SetNodeUsing("STRINGS_CONTROLS",false);
		SetNodeUsing("STRINGS_MOUSE",false);
		SetNodeUsing("CONTROLS_B_CHANGE",false);
		SetNodeUsing("CONTROLS_B_DEFAULT",false);
		SetNodeUsing("CONTROLS_B_INVERT",false);
		SetNodeUsing("CONTROLS_X_SENSIVE",false);
		SetNodeUsing("CONTROLS_Y_SENSIVE",false);
		GameInterface.pictures.InvertCameraImg.pic = -1;
		GameInterface.pictures.InvertCameraImg.tex = -1;
		SetCurrentNode("MB_CONTROLS");
	break;

	case OPAGE_CONTROLS_2:
		SetNodeUsing("CANCEL",false); // MAXIMUS interface MOD
		SetNodeUsing("OPTIONS",false); // MAXIMUS interface MOD
		SetNodeUsing("SUBTITLE",false);
		SetNodeUsing("STRINGS_CONTROLS",false);
		SetNodeUsing("B_SAILING1ST",false);
		SetNodeUsing("B_PRIMARY_LAND",false);
		SetNodeUsing("B_SAILING3RD",false);
		SetNodeUsing("B_FIGHTMODE",false);
		SetNodeUsing("B_GENERALCONTROLS",false);   // added after build 11 by KAM
		SetNodeUsing("B_WORLDMAPCONTROLS",false);   // added after build 11 by KAM
	break;


	case OPAGE_CONTROLS_3:
		SetNodeUsing("CANCEL",false); // MAXIMUS interface MOD
		SetNodeUsing("OPTIONS",false); // MAXIMUS interface MOD
		SetNodeUsing("SUBTITLE",false);
		SetNodeUsing("STRINGS_CONTROLS",false);
		SetNodeUsing("CONTROLSWINDOW",false);
		SetNodeUsing(gsKeyWindowName,false);
		SetNodeUsing("CONTROLGROUP",false);
		SetNodeUsing("SCROLL",false);
		DisableString("GroupName");
	break;

// added by KAM -->
	case OPAGE_DIFFICULTY:
		SetNodeUsing("CANCEL",false); // MAXIMUS interface MOD
		SetNodeUsing("OPTIONS",false); // MAXIMUS interface MOD
		SetNodeUsing("SUBTITLE",false);
		SetNodeUsing("B_DIFFICULTY1",false);
		SetNodeUsing("B_DIFFICULTY2",false);
		SetNodeUsing("B_DIFFICULTY3",false);
		SetNodeUsing("B_DIFFICULTY4",false);
		SetNodeUsing("B_NOTIFICATION",false);
		DisableString("DifficultyTitle");
		DisableString("NotificationTitle");
		DisableString("NotificationState");
		GameInterface.pictures.DiffLevelPic.pic = -1;
		GameInterface.pictures.DiffLevelPic.tex = -1;
	break;
// <-- added by KAM
// added by MAXIMUS -->
	case OPAGE_GAMEOPTION:
		SetNodeUsing("CANCEL",false); // MAXIMUS interface MOD
		SetNodeUsing("OPTIONS",false); // MAXIMUS interface MOD
		SetNodeUsing("SUBTITLE",false);
		SetNodeUsing("B_NEWINTERFACE",false);
		SetNodeUsing("B_OLDINTERFACE",false);
		SetNodeUsing("B_NEWICONS",false);
		SetNodeUsing("B_OLDICONS",false);
		/*SetNodeUsing("B_ENGLISH",false);
		SetNodeUsing("B_RUSSIAN",false);
		SetNodeUsing("B_FRENCH",false);
		SetNodeUsing("B_GERMAN",false);
		SetNodeUsing("B_SPANISH",false);
		SetNodeUsing("B_POLISH",false);*/
		SetNodeUsing("LANGUAGETITLE",false);
		SetNodeUsing("RAMKA2",false); // KK
		SetNodeUsing("CLANGUAGE_RAMKA", false); // KK
		DisableString("CurrentLanguage"); // KK
		SetNodeUsing("B_LANGUAGES",false);
		SetNodeUsing("B_ANION",false);
		SetNodeUsing("B_ANIOFF",false);
		SetNodeUsing("ANI_DESCRIPTION_BOX",false); // PB
		SetNodeUsing("B_ANI_DESCRIPTION", false); // PB
		SetNodeUsing("B_ADDITIONAL",false);
		DisableString("GameOptionTitle");
		SetNodeUsing("INTERFACE",false);
		SetNodeUsing("ICONS",false);
		SetNodeUsing("REINITLANGUAGE",false);//MAXIMUS
		GameInterface.pictures.AniPic.pic = -1;
		GameInterface.pictures.AniPic.tex = -1;
		GameInterface.pictures.LangPic.pic = -1;
		GameInterface.pictures.LangPic.tex = -1;
		GameInterface.pictures.InterfacePic.pic = -1;
		GameInterface.pictures.InterfacePic.tex = -1;
		GameInterface.pictures.IconPic.pic = -1;
		GameInterface.pictures.IconPic.tex = -1;
		GameInterface.pictures.igood0.pic = -1;
		GameInterface.pictures.igood0.tex = -1;
		GameInterface.pictures.igood1.pic = -1;
		GameInterface.pictures.igood1.tex = -1;
		GameInterface.pictures.igood2.pic = -1;
		GameInterface.pictures.igood2.tex = -1;
		GameInterface.pictures.igood3.pic = -1;
		GameInterface.pictures.igood3.tex = -1;
		GameInterface.pictures.igood4.pic = -1;
		GameInterface.pictures.igood4.tex = -1;
		GameInterface.pictures.igood5.pic = -1;
		GameInterface.pictures.igood5.tex = -1;
		GameInterface.pictures.igood6.pic = -1;
		GameInterface.pictures.igood6.tex = -1;
		GameInterface.pictures.igood7.pic = -1;
		GameInterface.pictures.igood7.tex = -1;
		GameInterface.pictures.igood8.pic = -1;
		GameInterface.pictures.igood8.tex = -1;
		GameInterface.pictures.igood9.pic = -1;
		GameInterface.pictures.igood9.tex = -1;
		GameInterface.pictures.igood10.pic = -1;
		GameInterface.pictures.igood10.tex = -1;
		GameInterface.pictures.igood11.pic = -1;
		GameInterface.pictures.igood11.tex = -1;
	break;

	case OPAGE_B_SETTINGS:
		SetNodeUsing("CANCEL",false);
		SetNodeUsing("OPTIONS",false);
		SetNodeUsing("SUBTITLE",false);
		SetNodeUsing("SETTINGS_DESCRIBEWINDOW",false);
		SetNodeUsing("SETTINGS_NAME",false);
		SetNodeUsing("SETTINGS_IMAGE",false);
		SetNodeUsing("SETTINGS_OK_BUTTON",false);
		SetNodeUsing("SETTINGS_CANCEL_BUTTON",false);
		SetNodeUsing("SETTINGS_DESCRIBE_RECT",false);
		SetNodeUsing("SETTINGS_DEFAULT_BUTTON",false);
		SetNodeUsing("SETTINGS_IMGGROUP",false);
		SetNodeUsing("SETTINGS_WINDOW",false);
		SetNodeUsing("SETTINGS_SCROLL",false);
		SetNodeUsing("SETTINGS_LINES",false);
		DisableString("BuildSettingsTitle");
		DisableString("BuildSettingsDescr");
		if(CheckAttribute(GameInterface,"settingslist.bShown")) DeleteAttribute(GameInterface,"settingslist.bShown");
	break;
// added by MAXIMUS <--

	}

	gi_nCurrentPage = pageNum;

	switch(pageNum)
	{
	case OPAGE_MAIN:
		SetNodeUsing("CANCEL",false); // MAXIMUS interface MOD
		SetNodeUsing("OPTIONS",false); // MAXIMUS interface MOD
		SetNodeUsing("MB_SAILING",true);
		SetNodeUsing("MB_SOUNDS",true);
		SetNodeUsing("MB_VIDEO",true);
		if(GetTargetPlatform()=="xbox")	{SetNodeUsing("MB_CAMERA",true);}
		SetNodeUsing("MB_CONTROLS",true);
		SetNodeUsing("MB_GAMEOPTION",true); // added by MAXIMUS
		SetNodeUsing("MB_BUILDSETTINGS",true); // added by MAXIMUS
		SetNodeUsing("MB_DIFFICULTY",true);				//added by KAM
	break;
	case OPAGE_SAILING:
		SetNodeUsing("CANCEL",false); // MAXIMUS interface MOD
		SetNodeUsing("OPTIONS",true); // MAXIMUS interface MOD
		SetNodeUsing("SUBTITLE",true);
		SetNodeUsing("STRINGS_ARCADEMODE",true);
		SetNodeUsing("REALISMMODE_0",true);
		SetNodeUsing("REALISMMODE_1",true);
		SetNodeUsing("REALISMMODE_2",true);
		SetNodeUsing("REALBATTLE_1",true);
		SetNodeUsing("REALBATTLE_2",true);
		SetNodeUsing("REALISM_DESCRIPTION", true);		// PB
		ChangeBattleIconsSetting();
		TmpI_ShowArcadeMode();
	break;
	case OPAGE_VIDEO:
		SetNodeUsing("CANCEL",false); // MAXIMUS interface MOD
		SetNodeUsing("OPTIONS",true); // MAXIMUS interface MOD
		SetNodeUsing("SUBTITLE",true);
		SetNodeUsing("STRINGS_VIDEO",true);
		SetNodeUsing("VIDEO_DEFAULT",true);
		SetNodeUsing("GAMMA_SLIDE",true);
		SetNodeUsing("BRIGHT_SLIDE",true);
		SetNodeUsing("CONTRAST_SLIDE",true);
		SetNodeUsing("VIDEO_SAVE",true);
		SetCurrentNode("VIDEO_DEFAULT");
	break;
	case OPAGE_SOUNDS:
		SetNodeUsing("CANCEL",false); // MAXIMUS interface MOD
		SetNodeUsing("OPTIONS",true); // MAXIMUS interface MOD
		SetNodeUsing("SUBTITLE",true);
		SetNodeUsing("STRINGS_SOUNDS",true);
		SetNodeUsing("RAMKA1",true); // KK
		SetNodeUsing("MUSICSCHEME_RAMKA",true); // KK
		SetNodeUsing("MUSICSCHEME_CHANGER",true); // KK
		EnableString("MusicScheme"); // KK
		SetNodeUsing("DIALOG",true);
		SetNodeUsing("SOUND",true);
		SetNodeUsing("MUSIC",true);
		SetCurrentNode("MUSIC");
	break;
	case OPAGE_CAMERA_MOD:
		SetNodeUsing("CANCEL",false); // MAXIMUS interface MOD
		SetNodeUsing("OPTIONS",true); // MAXIMUS interface MOD
		SetNodeUsing("SUBTITLE",true);
		SetNodeUsing("STRINGS_CAMERA",true);
		SetNodeUsing("CAMERAMODE_1",true);
		SetNodeUsing("CAMERAMODE_2",true);
		TmpI_ShowCameraMode();
		if( GetTargetPlatform()=="pc" )	{
			SetSelectable("CAMERAMODE_1",false);
			SetSelectable("CAMERAMODE_2",false);
		} else {SetCurrentNode("CAMERAMODE_1");}
	break;

	case OPAGE_CONTROLS_1:
		SetNodeUsing("CANCEL",false); // MAXIMUS interface MOD
		SetNodeUsing("OPTIONS",true); // MAXIMUS interface MOD
		SetNodeUsing("SUBTITLE",true);
		SetNodeUsing("STRINGS_CONTROLS",true);
		SetNodeUsing("STRINGS_MOUSE",true);
		SetNodeUsing("CONTROLS_B_CHANGE",true);
		SetNodeUsing("CONTROLS_B_DEFAULT",true);
		SetNodeUsing("CONTROLS_B_INVERT",true);
		SetNodeUsing("CONTROLS_X_SENSIVE",true);
		SetNodeUsing("CONTROLS_Y_SENSIVE",true);
		TmpI_ShowInvertMode();
		SetCurrentNode("CONTROLS_B_CHANGE");
	break;

	case OPAGE_CONTROLS_2:
		SetNodeUsing("CANCEL",false); // MAXIMUS interface MOD
		SetNodeUsing("OPTIONS",true); // MAXIMUS interface MOD
		SetNodeUsing("SUBTITLE",true);
		SetNodeUsing("STRINGS_CONTROLS",true);
		SetNodeUsing("B_SAILING1ST",true);
		SetNodeUsing("B_PRIMARY_LAND",true);
		SetNodeUsing("B_SAILING3RD",true);
		SetNodeUsing("B_FIGHTMODE",true);
		SetNodeUsing("B_GENERALCONTROLS",true);		// added after build 11 by KAM
		SetNodeUsing("B_WORLDMAPCONTROLS",true);   // added after build 11 by KAM
		SetCurrentNode("B_GENERALCONTROLS"); 	 // changed after build 11 by KAM
	break;


	case OPAGE_CONTROLS_3:
		SetNodeUsing("CANCEL",true); // MAXIMUS interface MOD
		SetNodeUsing("OPTIONS",false); // MAXIMUS interface MOD
		SetNodeUsing("SUBTITLE",true);
		SetNodeUsing("STRINGS_CONTROLS",true);
		SetNodeUsing("CONTROLSWINDOW",true);
		SetNodeUsing(gsKeyWindowName,true);
		SetNodeUsing("CONTROLGROUP",true);
		SetNodeUsing("SCROLL",true);
		EnableString("GroupName");
		SetCurrentNode("CONTROLSWINDOW");
	break;

// added by KAM -->
	case OPAGE_DIFFICULTY:
		SetNodeUsing("CANCEL",false); // MAXIMUS interface MOD
		SetNodeUsing("OPTIONS",true); // MAXIMUS interface MOD
		SetNodeUsing("SUBTITLE",true);
		SetNodeUsing("B_DIFFICULTY1",true);
		SetNodeUsing("B_DIFFICULTY2",true);
		SetNodeUsing("B_DIFFICULTY3",true);
		SetNodeUsing("B_DIFFICULTY4",true);
		SetNodeUsing("B_NOTIFICATION",true);
		SetCurrentNode("B_NOTIFICATION");
		EnableString("DifficultyTitle");
		EnableString("NotificationTitle");
		EnableString("NotificationState");
		KAM_DisplayNotification();
		KAM_DisplayDifficulty();
	break;
// <-- added by KAM
// added by MAXIMUS -->
	case OPAGE_GAMEOPTION:
		SetNodeUsing("CANCEL",false); // MAXIMUS interface MOD
		SetNodeUsing("OPTIONS",true); // MAXIMUS interface MOD
		SetNodeUsing("SUBTITLE",true);
		SetNodeUsing("B_NEWINTERFACE",true);
		SetNodeUsing("B_OLDINTERFACE",true);
		SetNodeUsing("B_NEWICONS",true);
		SetNodeUsing("B_OLDICONS",true);
		/*SetNodeUsing("B_ENGLISH",false); // KK
		SetNodeUsing("B_RUSSIAN",false);
		SetNodeUsing("B_FRENCH",false);
		SetNodeUsing("B_GERMAN",false);
		SetNodeUsing("B_SPANISH",false);
		SetNodeUsing("B_POLISH",false);*/ // KK
		SetNodeUsing("LANGUAGETITLE",false);
		SetNodeUsing("RAMKA2",true); // KK
		SetNodeUsing("CLANGUAGE_RAMKA",true); // KK
		EnableString("CurrentLanguage"); // KK
		SetNodeUsing("B_LANGUAGES",true);
		SetNodeUsing("B_ANION",true);
		SetNodeUsing("B_ANIOFF",true);
		SetNodeUsing("ANI_DESCRIPTION_BOX",true); // PB
		SetNodeUsing("B_ANI_DESCRIPTION", true); // PB
//		SetNodeUsing("B_ADDITIONAL",true); // PB
		EnableString("GameOptionTitle");
		SetNodeUsing("GAMEOPTIONTITLE",true);
		SetNodeUsing("INTERFACE",true);
		SetNodeUsing("ICONS",true);
		SetNodeUsing("REINITLANGUAGE",false);//MAXIMUS

		if(bAnimation==true)
		{
			SetSelectable("B_ANION",false);
			SetSelectable("B_ANIOFF",true);
		}
		else
		{
			SetSelectable("B_ANION",true);
			SetSelectable("B_ANIOFF",false);
		}

		SetSelectable("B_LANGUAGES", true); // KK

		if(bNewInterface==true)
		{
			SetSelectable("B_NEWINTERFACE",false);
			SetSelectable("B_OLDINTERFACE",true);
		}
		else
		{
			SetSelectable("B_NEWINTERFACE",true);
			SetSelectable("B_OLDINTERFACE",false);
		}

		if(bNewIcons==true)
		{
			SetSelectable("B_NEWICONS",false);
			SetSelectable("B_OLDICONS",true);
		}
		else
		{
			SetSelectable("B_NEWICONS",true);
			SetSelectable("B_OLDICONS",false);
		}

		SetCurrentNode("B_NEWINTERFACE");
		if(!GetSelectable("B_NEWINTERFACE")) DownProcess();
		SetNewLanguageView();
	break;

	case OPAGE_B_SETTINGS:
		SetNodeUsing("CANCEL",false);
		SetNodeUsing("OPTIONS",false);
		SetNodeUsing("SUBTITLE",false);
		SetNodeUsing("SETTINGS_DESCRIBEWINDOW",false);
		SetNodeUsing("SETTINGS_NAME",false);
		SetNodeUsing("SETTINGS_IMAGE",false);
		SetNodeUsing("SETTINGS_OK_BUTTON",false);
		SetNodeUsing("SETTINGS_CANCEL_BUTTON",false);
		SetNodeUsing("SETTINGS_DESCRIBE_RECT",false);
		SetNodeUsing("SETTINGS_DEFAULT_BUTTON",false);
		if(CheckAttribute(GameInterface,"settingslist.bShown")) DeleteAttribute(GameInterface,"settingslist.bShown");
		SetSettingsList();
	break;
// added by MAXIMUS <--

	}
}

void DoTitleSelect()
{
	ShowOptionsPage(OPAGE_MAIN);
}

void SetShowGroup(string groupName)
{
	g_sGroupName = groupName;
	switch(groupName)
	{
	case "Sailing1Pers":
		GameInterface.strings.GroupName = XI_ConvertString("Sailing 1St Person");
	break;
	// added by KAM after build 11 -->
	case "General":
		GameInterface.strings.GroupName = XI_ConvertString("KAMGeneralControls");
	break;
	case "WorldMapControls":
		GameInterface.strings.GroupName = XI_ConvertString("KAMWorldmapControls");
	break;
	// <-- added by KAM after build 11
	case "PrimaryLand":
		GameInterface.strings.GroupName = XI_ConvertString("Primary Land");
	break;
	case "Sailing3Pers":
		GameInterface.strings.GroupName = XI_ConvertString("Sailing 3rd Person");
	break;
	case "FightModeControls":
		GameInterface.strings.GroupName = XI_ConvertString("Fight Mode");
	break;
	}

	SetFormatedText("CONTROLSWINDOW","");

	int lngFile = LanguageOpenFile("ControlsNames.txt");
	if(lngFile<0) return;

	aref arGroup;
	makearef(arGroup,objControlsState.keygroups.(groupName));

	// ѕрописать контроли в список
	DeleteAttribute(&objArrayControls,"");
	int i, idx, tmpcolor;
	aref arControl;
	bool bTmpBool;
	int qn = GetAttributesNum(arGroup);
	string cntrlText,tmpstr;
	idx = 0;
	for(i=0; i<qn; i++)
	{
		arControl = GetAttributeN(arGroup,i);
		if( DisableShowControl(arControl) ) continue;
		//if( ControlIsStick(arControl) ) continue;
		if( CheckAttribute(arControl,"invisible") && sti(arControl.invisible)==true ) continue;
		if( CheckAttribute(arControl,"remapping") && sti(arControl.remapping)==false ) {
			bTmpBool = false;
			tmpcolor = argb(255,128,128,128);
		}
		else {
			bTmpBool = true;
			tmpcolor = argb(255,255,255,255);
		}

		if( g_bDisableControlChange )
		{
			bTmpBool = false;
			tmpcolor = argb(255,128,128,128);
		}

		tmpstr = GetAttributeName(arControl);

		cntrlText = LanguageConvertString(lngFile,tmpstr);
		if(cntrlText=="") continue;
		SendMessage(&GameInterface,"lsle",MSG_INTERFACE_MSG_TO_NODE,"CONTROLSWINDOW", 0,&cntrlText);
		SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"CONTROLSWINDOW", 8,-1,tmpcolor);
		SetControlNameForIdx(idx, tmpstr, bTmpBool);
		idx++;
	}

	LanguageCloseFile(lngFile);
	Event("evntUpdateFormtText","sll","CONTROLSWINDOW",0,0);
}

void SetControlNameForIdx(int idx, string controlName, bool bRemapEnable)
{
	string attrName = "i"+idx;
	objArrayControls.(attrName) = controlName;
	objArrayControls.(attrName).enable = bRemapEnable;
}

void procFTUpdate()
{
	string nodName = GetEventData();
	if(nodName!="CONTROLSWINDOW") return;
	int grNum = GetEventData(); // перва€ группа в изменени€х
	int strNum = GetEventData(); // перва€ строка в изменени€х

	object objPos,obj;
	DeleteAttribute(&objPos,"");
	SendMessage(&GameInterface,"lsla",MSG_INTERFACE_MSG_TO_NODE,"CONTROLSWINDOW", 3,&objPos);

	SetFormatedText(gsKeyWindowName,"");

	int i,qn,posnum;
	qn = GetAttributesNum(&objPos);
	int idx=0;
	for(i=0; i<qn; i++)
	{
		posnum = sti( GetAttributeValue(GetAttributeN(&objPos,i)) );
		if(posnum>=0)
		{
			idx = SetKeysStrings(grNum+i,posnum,idx);
		}
	}
	nLastTextGroupNum = grNum;
	nLastTextStringNum = strNum;
}

void procFTSetScrollPos()
{
	string nodName = GetEventData();
	float fpos = GetEventData();
	if(nodName=="CONTROLSWINDOW" || nodName=="SCROLL")
	{
		SendMessage(&GameInterface,"lsf",MSG_INTERFACE_SET_SCROLLER,"SCROLL",fpos);
	}
	if(nodName=="SETTINGS_WINDOW" || nodName=="SETTINGS_SCROLL")
	{
		SendMessage(&GameInterface,"lsf",MSG_INTERFACE_SET_SCROLLER,"SETTINGS_SCROLL",fpos);
	}
	oldCurNode = GetCurrentNode();
}

void ProcScrollPosChange()
{
	float newPos = GetEventData();
	if(oldCurNode!="") SendMessage(&GameInterface,"lslf",MSG_INTERFACE_MSG_TO_NODE,oldCurNode,2, newPos);
}

int SetKeysStrings(int grNum, int newpos, int oldpos)
{
	int i;
	string tmpStr;
	string keyStr = " ";
	for(i=oldpos; i<newpos; i++)
	{
		SendMessage(&GameInterface,"lsle",MSG_INTERFACE_MSG_TO_NODE,gsKeyWindowName, 0,&keyStr);
	}

	aref arGroupRoot,arKey;
	makearef(arGroupRoot,objControlsState.keygroups.(g_sGroupName));
	tmpStr = GetControlNameFromIdx(grNum);
	if( CheckAttribute(arGroupRoot,tmpStr) )	tmpStr = arGroupRoot.(tmpStr);
	else	tmpStr = "";

	if(CheckAttribute(&objControlsState,"key_codes."+tmpStr+".img"))
	{
		keyStr = objControlsState.key_codes.(tmpStr).img;
	}
	if(keyStr=="")	keyStr=" ";

	i += SendMessage(&GameInterface,"lsle",MSG_INTERFACE_MSG_TO_NODE,gsKeyWindowName, 0,&keyStr);
	return i;
}

string GetControlNameFromIdx(int idx)
{
	string attrName = "i"+idx;
	if( CheckAttribute(&objArrayControls,attrName) ) return objArrayControls.(attrName);
	return "";
}

void procFTActivate()
{
	string nodName = GetEventData();
	curCntrlIdx = GetEventData(); // номер текста
	if(nodName!="CONTROLSWINDOW" && nodName!="SETTINGS_WINDOW") return;
	if(nodName=="SETTINGS_WINDOW") { ShowSettingsDescribe(GetSettingsName(curCntrlIdx), curCntrlIdx); return; }

	if( !IsEnableRemapping(curCntrlIdx) ) return;

	SetSelectable("EXIT_BUTTON",false);
	SetNodeUsing("KEYCHOOSE_RECT",true);
	SetNodeUsing("SET_BUTTON",true);
	SetNodeUsing("DELETE_BUTTON",true);
	SetNodeUsing("INVERSE_BUTTON",true);
	SetCurrentNode("SET_BUTTON");

	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "SET_BUTTON");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "DELETE_BUTTON");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "INVERSE_BUTTON");
}

bool IsEnableRemapping(int nControl)
{
	aref arControl;
	arControl = GetAttributeN(&objArrayControls,nControl);
	return sti(arControl.enable);
}

void ReturnToViewControls()
{
	SetSelectable("EXIT_BUTTON",true);
	SetNodeUsing("KEYCHOOSE_RECT",false);
	SetNodeUsing("SET_BUTTON",false);
	SetNodeUsing("DELETE_BUTTON",false);
	SetNodeUsing("INVERSE_BUTTON",false);
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
	SetCurrentNode("CONTROLSWINDOW");
}

void SetReassignMode()
{
	SetNodeUsing("KEYCHOOSE_RECT",true);
	SetNodeUsing("KEY_CHOOSER",true);
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "KEY_CHOOSER");
	SetCurrentNode("KEY_CHOOSER");
}

void ReturnFromReassign()
{
	SetNodeUsing("KEYCHOOSE_RECT",false);
	SetNodeUsing("KEY_CHOOSER",false);
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
	SetCurrentNode("CONTROLSWINDOW");
}

void UnmapControl()
{
	aref arControlGroup;
	string contrlName,groupName;

	makearef(arControlGroup,objControlsState.keygroups.(g_sGroupName));

	contrlName = GetControlNameFromIdx(curCntrlIdx);

	int state = 0;
	if(CheckAttribute(&arControlGroup,contrlName+".state"))
	{	state = sti(arControlGroup.(contrlName).state);	}

	CI_CreateAndSetControls( g_sGroupName,contrlName, -1,state, true );

	Event("evntUpdateFormtText","sll","CONTROLSWINDOW", nLastTextGroupNum, nLastTextStringNum);
}

void InverseControl()
{
	if(curCntrlIdx<0)	return;
	aref arControlGroup;
	string contrlName;

	makearef(arControlGroup, objControlsState.keygroups.(g_sGroupName));
	contrlName = GetAttributeValue(GetAttributeN(&objArrayControls,curCntrlIdx));

	int state = 0;
	if(CheckAttribute(arControlGroup,contrlName+".state")) {
		state = sti(arControlGroup.(contrlName).state);
	}

	switch(state)
	{
	case USE_AXIS_AS_BUTTON:		state=USE_AXIS_AS_INVERSEBUTTON;	break;
	case USE_AXIS_AS_INVERSEBUTTON:	state=USE_AXIS_AS_BUTTON;	break;
	case INVERSE_CONTROL:			state=0;	break;
	case 0:							state=INVERSE_CONTROL;	break;
	}

	arControlGroup.(contrlName).state = state;
	CI_CreateAndSetControls( g_sGroupName, contrlName, CI_GetKeyCode(arControlGroup.(contrlName)), state, true );

	Event("evntUpdateFormtText","sll","CONTROLSWINDOW", nLastTextGroupNum, nLastTextStringNum);
}

int glob_retVal;
ref procKeyChoose()
{
	int keyIdx = GetEventData();
	int stickUp = GetEventData();

	glob_retVal = false;
	if( DoMapToOtherKey(keyIdx,stickUp) )
	{
		ReturnFromReassign();
		Event("evntUpdateFormtText","sll","CONTROLSWINDOW", nLastTextGroupNum, nLastTextStringNum);
		glob_retVal = true;
	}

	return &glob_retVal;
}

bool DoMapToOtherKey(int keyIdx,int stickUp)
{
	aref arControlGroup;
	aref arKeyRoot,arKey;
	string contrlName, tmpstr;
	int keyCode;

	if( stickUp )
	{
		SetStickNotAvailable();
		return false;
	}

	makearef(arControlGroup,objControlsState.keygroups.(g_sGroupName));

	contrlName = GetControlNameFromIdx(curCntrlIdx);

	makearef(arKeyRoot,objControlsState.key_codes);
	arKey = GetAttributeN(arKeyRoot,keyIdx);
	keyCode = sti(GetAttributeValue(arKey));

	if( CheckAttribute(arKey,"stick") && sti(arKey.stick)==true ) return false;

	if( KeyAlreadyUsed(g_sGroupName, contrlName, GetAttributeName(arKey)) )
	{
		SetAlreadyUsedShow();
		return false;
	}

	tmpstr = arControlGroup.(contrlName);
	if( CheckAttribute(arKeyRoot,tmpstr+".stick") && sti(arKeyRoot.(tmpstr).stick)==true ) return false;

	int state = 0;
	if(CheckAttribute(arControlGroup,contrlName+".state"))
	{	state = sti(arControlGroup.(contrlName).state);	}

	CI_CreateAndSetControls( g_sGroupName,contrlName,keyCode, state, true );

	// TIH --> controls setting fixer for sidestep and spyglass 7-7-06
	switch (contrlName) {
		case "TelescopeIn":
			CI_CreateAndSetControls( g_sGroupName, "TelescopeOut", keyCode, INVERSE_CONTROL, true );
			break;
		case "Sidestep_left_on":
			CI_CreateAndSetControls( g_sGroupName, "Sidestep_left_off", keyCode, INVERSE_CONTROL, true );
			break;
		case "Sidestep_right_on":
			CI_CreateAndSetControls( g_sGroupName, "Sidestep_right_off", keyCode, INVERSE_CONTROL, true );
			break;
	}
	// TIH <-- end controls setting fixer

	return true;
}

void SetAlreadyUsedShow()
{
	nFadeStr_NoStick = 0;
	nFadeStr_AlUsed = 15;
}
void SetStickNotAvailable()
{
	nFadeStr_AlUsed = 0;
	nFadeStr_NoStick = 15;
}

void ProcScrollChange()
{
	int changeNum = GetEventData();
	if(changeNum==0) return;
	if(changeNum>0) {
		SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"CONTROLSWINDOW",-1, 0,ACTION_DOWNSTEP);
	} else {
		SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"CONTROLSWINDOW",-1, 0,ACTION_UPSTEP);
	}
}

void FadeStringsUpdate()
{
	int color;
	if( nFadeStr_AlUsed>0 )
	{
		nFadeStr_AlUsed--;
		if(nFadeStr_AlUsed==0)
		{
			GameInterface.strings.AlreadyUsed = "";
		}
		else
		{
			color = argb(GetAlphaFromFade(nFadeStr_AlUsed),255,255,255);
			CreateString(true,"AlreadyUsed",XI_ConvertString("Button Already Used"),FONT_NORMAL,color,320,258,SCRIPT_ALIGN_CENTER,1.0);
		}
	}

	if( nFadeStr_NoStick>0 )
	{
		nFadeStr_NoStick--;
		if(nFadeStr_NoStick==0)
		{
			GameInterface.strings.AlreadyUsed = "";
		}
		else
		{
			color = argb(GetAlphaFromFade(nFadeStr_NoStick),255,255,255);
			CreateString(true,"AlreadyUsed",XI_ConvertString("thumbstick cannot be used"),FONT_NORMAL,color,320,258,SCRIPT_ALIGN_CENTER,1.0);
		}
	}

	PostEvent("evntFadeStrings",100);
}

bool KeyAlreadyUsed(string groupName, string controlName, string keyName)
{
	int n, q;
	aref arRoot, arCntrl;
	makearef( arRoot, objControlsState.keygroups.(groupName) );
	q = GetAttributesNum(arRoot);

	for(n=0; n<q; n++)
	{
		arCntrl = GetAttributeN(arRoot,n);
		if( GetAttributeName(arCntrl)==controlName ) continue;
		if( GetAttributeValue(arCntrl)==keyName) return true;
	}

	return false;
}

int GetAlphaFromFade(int n)
{
	int alpha = n*20;
	if(alpha>255) alpha = 255;
	if(alpha<0) alpha = 0;
	return alpha;
}

void SetOldButton()
{
	switch(g_sGroupName)
	{
	case "Sailing1Pers":		SetCurrentNode("B_SAILING1ST"); break;
	case "PrimaryLand":			SetCurrentNode("B_PRIMARY_LAND"); break;
	case "Sailing3Pers":		SetCurrentNode("B_SAILING3RD"); break;
	case "FightModeControls":	SetCurrentNode("B_FIGHTMODE"); break;
	}
}

bool ControlIsStick(aref arControl)
{
	string sKeyName = GetAttributeValue(arControl);
	if( CheckAttribute(&objControlsState,"key_codes."+sKeyName+".stick") &&
		sti(objControlsState.key_codes.(sKeyName).stick)==true )
	{
		return true;
	}
	return false;
}

bool DisableShowControl(aref arControl)
{
	if( ControlIsStick(arControl) ) return true;
	switch( GetAttributeValue(arControl) )
	{
	case "DPAD_UP": return true; break;
	case "DPAD_DOWN": return true; break;
	case "DPAD_RIGHT": return true; break;
	case "DPAD_LEFT": return true; break;
	}
	return false;
}

void ISetColorCorrection(float fContrast, float fGamma, float fBright)
{
	i_fCurContrast = ConvertContrast(fContrast,true);
	i_fCurGamma = ConvertGamma(fGamma,true);
	i_fCurBright = ConvertBright(fBright,true);

	if(i_fCurContrast>1.0) i_fCurContrast=1.0;
	if(i_fCurContrast<0.0) i_fCurContrast=0.0;
	if(i_fCurGamma>1.0) i_fCurGamma=1.0;
	if(i_fCurGamma<0.0) i_fCurGamma=0.0;
	if(i_fCurBright>1.0) i_fCurBright=1.0;
	if(i_fCurBright<0.0) i_fCurBright=0.0;

	GameInterface.nodes.contrast_slide.value = i_fCurContrast;
	GameInterface.nodes.gamma_slide.value = i_fCurGamma;
	GameInterface.nodes.bright_slide.value = i_fCurBright;

	SendMessage(&GameInterface,"lslf",MSG_INTERFACE_MSG_TO_NODE,"CONTRAST_SLIDE", 0,i_fCurContrast);
	SendMessage(&GameInterface,"lslf",MSG_INTERFACE_MSG_TO_NODE,"GAMMA_SLIDE", 0,i_fCurGamma);
	SendMessage(&GameInterface,"lslf",MSG_INTERFACE_MSG_TO_NODE,"BRIGHT_SLIDE", 0,i_fCurBright);

	XI_SetColorCorrection(fContrast,fGamma,fBright);
}

void StartVideoSetting()
{
	float fC = 1.0;
	float fG = 1.0;
	float fB = 0.0;

	if( CheckAttribute(&InterfaceStates,"video.contrast") ) {
		fC = stf(InterfaceStates.video.contrast);
	}
	if( CheckAttribute(&InterfaceStates,"video.gamma") ) {
		fG = stf(InterfaceStates.video.gamma);
	}
	if( CheckAttribute(&InterfaceStates,"video.brightness") ) {
		fB = stf(InterfaceStates.video.brightness);
	}

	ISetColorCorrection( fC, fG, fB );
}

float ConvertContrast(float fContrast, bool Real2Slider)
{
	if(Real2Slider)
	{
		if(fContrast<=1.0) {return fContrast-0.5;}
		return fContrast/2.0;
	}
	if(fContrast<=0.5) {return fContrast+0.5;}
	return fContrast*2.0;
}
float ConvertGamma(float fGamma, bool Real2Slider)
{
	if(Real2Slider)
	{
		if(fGamma<=1.0) {return fGamma-0.5;}
		return (fGamma+1.5)/5.0;
	}
	if(fGamma<=0.5) {return fGamma+0.5;}
	return fGamma*5.0-1.5;
}
float ConvertBright(float fBright, bool Real2Slider)
{
	if(Real2Slider)
	{
		return (fBright+100.0)/200.0;
	}
	return fBright*200-100;
}

void SaveVideoSettings()
{
	InterfaceStates.video.contrast = ConvertContrast(i_fCurContrast,false);
	InterfaceStates.video.gamma = ConvertGamma(i_fCurGamma,false);
	InterfaceStates.video.brightness = ConvertBright(i_fCurBright,false);
}

void SetMouseToDefault()
{
	GameInterface.pictures.InvertCameraImg.pic = -1;
	GameInterface.pictures.InvertCameraImg.tex = -1;
	InterfaceStates.InvertCameras = false;
	XI_SetMouseSensitivity( 1.0, 1.0 );
	i_fCurXSens = 0.5;
	i_fCurYSens = 0.5;
	InterfaceStates.mouse.x_sens = i_fCurXSens;
	InterfaceStates.mouse.y_sens = i_fCurYSens;
	GameInterface.nodes.controls_x_sensive.value = i_fCurXSens;
	GameInterface.nodes.controls_y_sensive.value = i_fCurYSens;
	SendMessage(&GameInterface,"lslf",MSG_INTERFACE_MSG_TO_NODE,"CONTROLS_X_SENSIVE", 0,i_fCurXSens);
	SendMessage(&GameInterface,"lslf",MSG_INTERFACE_MSG_TO_NODE,"CONTROLS_Y_SENSIVE", 0,i_fCurYSens);
}

void MakeCamerasInvert()
{
	bool bCamInvert = true;
	if( CheckAttribute(&InterfaceStates,"InvertCameras") && sti(InterfaceStates.InvertCameras)==true) {
		bCamInvert = false;
	}
	InterfaceStates.InvertCameras = bCamInvert;
}

// ccc
void ChangeBattleIconsSetting()
{
	if(bRealBattleInterface)
	{
		CreateImage("BattlePic","icons","complete",532,424,564,456);
		SetSelectable("REALBATTLE_1",true);
		SetSelectable("REALBATTLE_2",false);
		SetCurrentNode("REALBATTLE_1");
	}
	else
	{
		CreateImage("BattlePic","icons","complete",532,382,564,414);
		SetSelectable("REALBATTLE_1",false);
		SetSelectable("REALBATTLE_2",true);
		SetCurrentNode("REALBATTLE_2");
	}
}
// ccc

// added by MAXIMUS -->
// KK bool FindLocalLanguage(string lang) rewritten and moved to MAXIMUS_Functions.c

void SetNewLanguageView()
{
	if(GetSelectable("B_LANGUAGES")) GameInterface.strings.GameOptionTitle = XI_ConvertString("Changeinterface");
	else GameInterface.strings.GameOptionTitle = XI_ConvertString("Available Languages");//MAXIMUS
	CreateExitString(); // KK//MAXIMUS
	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"MB_VIDEO",0,"#"+XI_ConvertString("Video Settings"));
	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"MB_SAILING",0,"#"+XI_ConvertString("Sailing Mode"));
	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"MB_SOUNDS",0,"#"+XI_ConvertString("Sounds"));
	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"MB_CAMERA",0,"#"+XI_ConvertString("Camera Mode"));
	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"MB_CONTROLS",0,"#"+XI_ConvertString("Controls"));
	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"MB_DIFFICULTY",0,"#"+XI_ConvertString("Difficulty"));
	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"MB_GAMEOPTION",0,"#"+XI_ConvertString("Changeinterface"));
	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"MB_BUILDSETTINGS",0,"#"+XI_ConvertString("BuildSettings"));
	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"B_NEWINTERFACE",0,"#"+XI_ConvertString("Newlook"));
	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"B_OLDINTERFACE",0,"#"+XI_ConvertString("Oldlook"));
	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"B_NEWICONS",0,"#"+XI_ConvertString("NewIcons"));
	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"B_OLDICONS",0,"#"+XI_ConvertString("OldIcons"));
	/*SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"B_ENGLISH",0,"#"+XI_ConvertString("IntEnglish"));
	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"B_RUSSIAN",0,"#"+XI_ConvertString("IntRussian"));//MAXIMUS
	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"B_FRENCH",0,"#"+XI_ConvertString("IntFrench"));//MAXIMUS
	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"B_SPANISH",0,"#"+XI_ConvertString("IntSpanish"));//MAXIMUS
	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"B_POLISH",0,"#"+XI_ConvertString("IntPolish"));*///MAXIMUS
	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"B_LANGUAGES",0,"#"+XI_ConvertString("IntLanguages"));
	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"B_ANION",0,"#"+XI_ConvertString("AniOn"));
	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"B_ANIOFF",0,"#"+XI_ConvertString("AniOff"));
//	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"B_ADDITIONAL",0,"#"+XI_ConvertString("IntAdditional")); // PB
	GameInterface.strings.CurrentLanguage = XI_ConvertString("Int" + GetInterfaceLanguageName(iSelectedInterfaceLanguage)) + " | " + XI_ConvertString("Int" + GetInterfaceLanguageName(iSelectedKeyboardLayout)); // KK
	DisplayInterfaceStatus();
}

void AdditionalHide()
{
	CreateExitString(); // KK//MAXIMUS
	SetNodeUsing("CANCEL",false);
	SetNodeUsing("OPTIONS",false);
	SetNodeUsing("SUBTITLE",false);
	SetNodeUsing("B_NEWINTERFACE",false);
	SetNodeUsing("B_OLDINTERFACE",false);
	SetNodeUsing("B_NEWICONS",false);
	SetNodeUsing("B_OLDICONS",false);
	SetNodeUsing("RAMKA2",false); // KK
	SetNodeUsing("CLANGUAGE_RAMKA",false); // KK
	DisableString("CurrentLanguage"); // KK
	SetNodeUsing("B_LANGUAGES",false);
	//SetNodeUsing("B_ENGLISH",false);
	SetNodeUsing("B_ANION",false);
	SetNodeUsing("B_ANIOFF",false);
	SetNodeUsing("ANI_DESCRIPTION_BOX",false); // PB
	SetNodeUsing("B_ANI_DESCRIPTION", false); // PB
	SetNodeUsing("B_ADDITIONAL",false);
	SetNodeUsing("INTERFACE",false);
	SetNodeUsing("ICONS",false);
	SetSelectable("EXIT_BUTTON",false);
	GameInterface.pictures.AniPic.pic = -1;
	GameInterface.pictures.AniPic.tex = -1;
	GameInterface.pictures.LangPic.pic = -1;
	GameInterface.pictures.LangPic.tex = -1;
	GameInterface.pictures.InterfacePic.pic = -1;
	GameInterface.pictures.InterfacePic.tex = -1;
	GameInterface.pictures.IconPic.pic = -1;
	GameInterface.pictures.IconPic.tex = -1;
	GameInterface.pictures.igood0.pic = -1;
	GameInterface.pictures.igood0.tex = -1;
	GameInterface.pictures.igood1.pic = -1;
	GameInterface.pictures.igood1.tex = -1;
	GameInterface.pictures.igood2.pic = -1;
	GameInterface.pictures.igood2.tex = -1;
	GameInterface.pictures.igood3.pic = -1;
	GameInterface.pictures.igood3.tex = -1;
	GameInterface.pictures.igood4.pic = -1;
	GameInterface.pictures.igood4.tex = -1;
	GameInterface.pictures.igood5.pic = -1;
	GameInterface.pictures.igood5.tex = -1;
	GameInterface.pictures.igood6.pic = -1;
	GameInterface.pictures.igood6.tex = -1;
	GameInterface.pictures.igood7.pic = -1;
	GameInterface.pictures.igood7.tex = -1;
	GameInterface.pictures.igood8.pic = -1;
	GameInterface.pictures.igood8.tex = -1;
	GameInterface.pictures.igood9.pic = -1;
	GameInterface.pictures.igood9.tex = -1;
	GameInterface.pictures.igood10.pic = -1;
	GameInterface.pictures.igood10.tex = -1;
	GameInterface.pictures.igood11.pic = -1;
	GameInterface.pictures.igood11.tex = -1;

//	CreateString(true,"Languages",XI_ConvertString("Available Languages"),FONT_NORMAL,COLOR_NORMAL,320,150,SCRIPT_ALIGN_CENTER,1.3);
	GameInterface.strings.GameOptionTitle = XI_ConvertString("Available Languages");
	SetNodeUsing("ADDITIONAL_RECT",true);
	SetNodeUsing("LANGUAGETITLE",true);
	SetSelectable("LANGUAGETITLE",true);
	SetNodeUsing("STRINGS_LANGUAGES", true);
	SetNodeUsing("LANGUAGE_RAMKA", true);
	SetNodeUsing("LANGUAGE_CHANGER", true);
	EnableString("LanguagesList");
	SetNodeUsing("KEYBOARDLAYOUT_RAMKA", true);
	SetNodeUsing("KEYBOARDLAYOUT_CHANGER", true);
	EnableString("KeyboardLayoutList");
	SetNodeUsing("B_SELECTLANGUAGE", true);
	SetNodeUsing("B_CANCELLANGUAGE", true);
	SetCurrentNode("LANGUAGE_CHANGER");
	/*SetNodeUsing("B_ENGLISH",true); // KK
	SetNodeUsing("B_RUSSIAN",true);
	SetNodeUsing("B_FRENCH",true);
	SetNodeUsing("B_GERMAN",true);
	SetNodeUsing("B_SPANISH",true);
	SetNodeUsing("B_POLISH",true); // KK
	SetSelectable("B_" + GetInterfaceLanguageName(GetInterfaceLanguage()), FindLocalLanguage(GetInterfaceLanguageName(GetInterfaceLanguage())));
	SetSelectable("B_ENGLISH",FindLocalLanguage("english")); // KK
	if(!bInterfaceRus) SetSelectable("B_RUSSIAN",FindLocalLanguage("russian"));
	if(!bInterfaceFra) SetSelectable("B_FRENCH",FindLocalLanguage("french"));
	if(!bInterfaceGer) SetSelectable("B_GERMAN",FindLocalLanguage("german"));
	if(!bInterfaceSpa) SetSelectable("B_SPANISH",FindLocalLanguage("spanish"));
	if(!bInterfacePol) SetSelectable("B_POLISH",FindLocalLanguage("polish"));*/ // KK
	SetNodeUsing("REINITLANGUAGE",true);//MAXIMUS
	/*SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"B_ENGLISH",0,"#"+XI_ConvertString("IntEnglish")); // KK
	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"B_RUSSIAN",0,"#"+XI_ConvertString("IntRussian"));
	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"B_FRENCH",0,"#"+XI_ConvertString("IntFrench"));
	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"B_GERMAN",0,"#"+XI_ConvertString("IntGerman"));
	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"B_SPANISH",0,"#"+XI_ConvertString("IntSpanish"));
	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"B_POLISH",0,"#"+XI_ConvertString("IntPolish"));*/ // KK
	//DisplayInterfaceStatus();
}

void AdditionalShow()
{
	DisableString("Languages");
	SetNodeUsing("ADDITIONAL_RECT",true);
	SetNodeUsing("LANGUAGETITLE",true);
	SetSelectable("LANGUAGETITLE",false);
	SetNodeUsing("STRINGS_LANGUAGES", false);
	SetNodeUsing("LANGUAGE_RAMKA", false);
	SetNodeUsing("LANGUAGE_CHANGER", false);
	DisableString("LanguagesList");
	SetNodeUsing("KEYBOARDLAYOUT_RAMKA", false);
	SetNodeUsing("KEYBOARDLAYOUT_CHANGER", false);
	DisableString("KeyboardLayoutList");
	SetNodeUsing("B_SELECTLANGUAGE", false);
	SetNodeUsing("B_CANCELLANGUAGE", false);
	/*SetNodeUsing("B_ENGLISH",false); // KK
	SetNodeUsing("B_RUSSIAN",false);
	SetNodeUsing("B_FRENCH",false);
	SetNodeUsing("B_GERMAN",false);
	SetNodeUsing("B_SPANISH",false);
	SetNodeUsing("B_POLISH",false);*/ // KK
	SetNodeUsing("LANGUAGETITLE",false);
	SetNodeUsing("ADDITIONAL_RECT",false);
	SetNodeUsing("CANCEL",false);
	SetNodeUsing("OPTIONS",true);
	SetNodeUsing("SUBTITLE",true);
	SetNodeUsing("B_NEWINTERFACE",true);
	SetNodeUsing("B_OLDINTERFACE",true);
	SetNodeUsing("B_NEWICONS",true);
	SetNodeUsing("B_OLDICONS",true);
	SetNodeUsing("RAMKA2",true); // KK
	SetNodeUsing("CLANGUAGE_RAMKA",true); // KK
	EnableString("CurrentLanguage"); // KK
	SetNodeUsing("B_LANGUAGES",true);
	SetNodeUsing("B_ANION",true);
	SetNodeUsing("B_ANIOFF",true);
	SetNodeUsing("ANI_DESCRIPTION_BOX",true); // PB
	SetNodeUsing("B_ANI_DESCRIPTION",true); // PB
//	SetNodeUsing("B_ADDITIONAL",true); // PB
	EnableString("GameOptionTitle");
	SetNodeUsing("GAMEOPTIONTITLE",true);
	SetNodeUsing("INTERFACE",true);
	SetNodeUsing("ICONS",true);
	SetNodeUsing("REINITLANGUAGE",false);//MAXIMUS
	SetSelectable("EXIT_BUTTON",true);//MAXIMUS
	GameInterface.strings.GameOptionTitle = XI_ConvertString("Changeinterface");//MAXIMUS

	if(bAnimation==true)
	{
		SetSelectable("B_ANION",false);
		SetSelectable("B_ANIOFF",true);
	}
	else
	{
		SetSelectable("B_ANION",true);
		SetSelectable("B_ANIOFF",false);
	}

	SetSelectable("B_LANGUAGES", true); // KK

	if(bNewInterface==true)
	{
		SetSelectable("B_NEWINTERFACE",false);
		SetSelectable("B_OLDINTERFACE",true);
	}
	else
	{
		SetSelectable("B_NEWINTERFACE",true);
		SetSelectable("B_OLDINTERFACE",false);
	}

	if(bNewIcons==true)
	{
		SetSelectable("B_NEWICONS",false);
		SetSelectable("B_OLDICONS",true);
	}
	else
	{
		SetSelectable("B_NEWICONS",true);
		SetSelectable("B_OLDICONS",false);
	}

	if(!GetSelectable("B_LANGUAGES")) DownProcess();
	else SetCurrentNode("B_LANGUAGES");
	SetNewLanguageView();
}

void DisplayInterfaceStatus()
{
	string languagestatus, iconstatus, interfacestatus, animationstatus;
	/*if(bInterfaceRus==true) languagestatus = 1;
	else
	{
		if(bInterfaceFra==true) languagestatus = 3;
		else
		{
			if(bInterfaceGer==true) languagestatus = 4;
			else
			{
				if(bInterfaceSpa==true) languagestatus = 5;
				else
				{
					if(bInterfacePol==true) languagestatus = 6; // KK
					else languagestatus = 2;
				}
			}
		}
	}
	switch(GetInterfaceLanguage())
	{
	case ILANG_RUS:
		if(GetSelectable("B_LANGUAGES")) CreateImage("LangPic","","",390,235,420,262);//MAXIMUS: picture was inverted
		else CreateImage("LangPic","icons","complete",390,235,420,262);//MAXIMUS
	break;
	case ILANG_ENG:
		if(GetSelectable("B_LANGUAGES")) CreateImage("LangPic","","",390,200,420,227);
		else CreateImage("LangPic","icons","complete",390,200,420,227);
	break;
	case ILANG_FRA:
		if(GetSelectable("B_LANGUAGES")) CreateImage("LangPic","","",390,270,420,297);
		else CreateImage("LangPic","icons","complete",390,270,420,297);
	break;
	case ILANG_GER:
		if(GetSelectable("B_LANGUAGES")) CreateImage("LangPic","","",390,305,420,332);
		else CreateImage("LangPic","icons","complete",390,305,420,332);
	break;
	case ILANG_SPA:
		if(GetSelectable("B_LANGUAGES")) CreateImage("LangPic","","",260,340,380,367);
		else CreateImage("LangPic","icons","complete",390,340,420,367);
	break;
	case ILANG_POL: // KK
		if(GetSelectable("B_LANGUAGES")) CreateImage("LangPic","","",260,375,380,402);
		else CreateImage("LangPic","icons","complete",390,375,420,402);
	break;
	}*/

	//if(!GetSelectable("B_LANGUAGES")) return; // KK
	if(bNewInterface==true) interfacestatus = 1;
	else interfacestatus = 2;
	switch(interfacestatus)
	{
		case "1":
			CreateImage("InterfacePic","icons","complete",194,130,221,157);
			SetNewPicture("INTERFACE", "interfaces\background\brown.tga");
		break;
		case "2":
			CreateImage("InterfacePic","icons","complete",194,165,224,192);
			SetNewPicture("INTERFACE", "interfaces\background\blue.tga");
		break;
	}

	if(bNewIcons==true) iconstatus = 1;
	else iconstatus = 2;
	switch(iconstatus)
	{
		case "1":
			CreateImage("IconPic","icons","complete",554,130,581,157);

			CreateImage("igood0","GOODS_NEW","Bombs",387,201,447,261);
			CreateImage("igood1","GOODS_NEW","Knippels",387,265,447,325);

			CreateImage("igood2","GOODS_NEW","Planks",452,201,512,261);
			CreateImage("igood3","GOODS_NEW","Sailcloth",452,265,512,325);

			CreateImage("igood4","GOODS_NEW","Leather",517,201,577,261);
			CreateImage("igood5","GOODS_NEW","Oil",517,265,577,325);

			CreateImage("igood6","GOODS_NEW","Wine",387,329,447,389);
			CreateImage("igood7","GOODS_NEW","Wheat",387,393,447,453);

			CreateImage("igood8","GOODS_NEW","Rum",452,329,512,389);
			CreateImage("igood9","GOODS_NEW","Tobacco",452,393,512,453);

			CreateImage("igood10","GOODS_NEW","Mahogany",517,329,577,389);
			CreateImage("igood11","GOODS_NEW","Silk",517,393,577,453);
		break;
		case "2":
			CreateImage("IconPic","icons","complete",554,165,584,192);

			CreateImage("igood0","GOODS","Bombs",387,201,447,261);
			CreateImage("igood1","GOODS","Knippels",387,265,447,325);

			CreateImage("igood2","GOODS","Planks",452,201,512,261);
			CreateImage("igood3","GOODS","Sailcloth",452,265,512,325);

			CreateImage("igood4","GOODS","Leather",517,201,577,261);
			CreateImage("igood5","GOODS","Oil",517,265,577,325);

			CreateImage("igood6","GOODS","Wine",387,329,447,389);
			CreateImage("igood7","GOODS","Wheat",387,393,447,453);

			CreateImage("igood8","GOODS","Rum",452,329,512,389);
			CreateImage("igood9","GOODS","Tobacco",452,393,512,453);

			CreateImage("igood10","GOODS","Mahogany",517,329,577,389);
			CreateImage("igood11","GOODS","Silk",517,393,577,453);
		break;
	}

	// PB: Interface Settings menu cleaned up and clarified -->
	int tmpLangFileID = LanguageOpenFile("SettingsDescribe.txt");
	if (bAnimation) {
		animationstatus = 1;
		SetFormatedText("B_ANI_DESCRIPTION", LanguageConvertString(tmpLangFileID, "AniOn") );
		CreateImage("AniPic","icons","complete",550,460,577,487);
	} else {
		animationstatus = 2;
		SetFormatedText("B_ANI_DESCRIPTION", LanguageConvertString(tmpLangFileID, "AniOff") );
		CreateImage("AniPic","icons","complete",190,460,217,487);
	}
	LanguageCloseFile(tmpLangFileID);
	// PB: Interface Settings menu cleaned up and clarified <--
}
//==========================================| BuildSetting Section start |==========================================//
void SetSettingsList()
{
	int tmpLangFileID = LanguageOpenFile("SettingsDescribe.txt");
	int i;

	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
	CreateString(false,"BuildSettingsTitle",XI_ConvertString("BuildSettingsTitle"),FONT_NORMAL,COLOR_YELLOW_LIGHT,320,37,SCRIPT_ALIGN_CENTER,1.3);
	CreateString(false,"BuildSettingsDescr",XI_ConvertString("BuildSettingsDescr"),FONT_NORMAL,COLOR_RED_LIGHT,320,74,SCRIPT_ALIGN_CENTER,1.0);
	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"SETTINGS_OK_BUTTON",0,"#"+XI_ConvertString("Ok"));
	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"SETTINGS_CANCEL_BUTTON",0,"#"+XI_ConvertString("Cancel"));
	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"SETTINGS_DEFAULT_BUTTON",0,"#"+XI_ConvertString("Restore Default"));
	bKeyboardEnabled = false;

	SetNodeUsing("SETTINGS_DESCRIBEWINDOW",false);
	SetNodeUsing("SETTINGS_DESCRIBEWINDOW1",false);
	SetNodeUsing("SETTINGS_DESCRIBEWINDOW2",false);
	SetNodeUsing("SETTINGS_DESCRIBEWINDOW3",false);
	SetNodeUsing("VALUE_CHANGER",false);
	SetNodeUsing("VALUE_RECT",false);
	SetNodeUsing("SETTINGS_NUMCHANGE",false);
	SetNodeUsing("WINDOW_FADER",false);
	SetNodeUsing("SETTINGS_NAME",false);
	SetNodeUsing("SETTINGS_IMAGE",false);
	SetNodeUsing("SETTINGS_OK_BUTTON",false);
	SetNodeUsing("SETTINGS_CANCEL_BUTTON",false);
	SetNodeUsing("SETTINGS_DESCRIBE_RECT",false);
	SetNodeUsing("SETTINGS_DEFAULT_BUTTON",true);
	SetNodeUsing("SETTINGS_IMGGROUP",true);
	SetNodeUsing("SETTINGS_WINDOW",true);
	SetNodeUsing("SETTINGS_SCROLL",true);
	SetNodeUsing("SETTINGS_LINES",true);
	EnableString("BuildSettingsTitle");
	EnableString("BuildSettingsDescr");
	DisableString("shipModel");
	SetSelectable("EXIT_BUTTON",true);
	SetSelectable("SETTINGS_WINDOW",true);
	SetSelectable("SETTINGS_SCROLL",true);
	SetSelectable("SETTINGS_DEFAULT_BUTTON",true);
	HideCheckBoxes(10);
	HideScroll();
	KB_SetKeyboardMode(false);
	UpdateTempData();
	bool bShown = false;
	if(CheckAttribute(GameInterface,"settingslist.bShown")) bShown = sti(GameInterface.settingslist.bShown);

	int optCount = 0;
	for(i=0; i<GetAttributesNum(bSet); i++)
	{
		aref curItem = GetAttributeN(bSet, i);
		string attrName = GetAttributeName(curItem);
		string tmpStr = "setting"+optCount;// MAXIMUS: for some settings, which will not be added into list
		bool addOption = true;
		if(HasSubStr(attrName, "NEW_MODEL_")) { addOption = false; optCount--; }// MAXIMUS: excluding models list
		if(HasSubStr(attrName, "NEW_SHIP_")) { addOption = false; optCount--; }// MAXIMUS: excluding ships list

		if(addOption)
		{
			GameInterface.settingslist.(tmpStr) = attrName;
			tmpStr = LanguageConvertString(tmpLangFileID, attrName);
			if(tmpStr=="") { tmpStr=" "; }
			if(!bShown)
			{
				SendMessage(&GameInterface,"lsle",MSG_INTERFACE_MSG_TO_NODE,"SETTINGS_WINDOW", 0,&tmpStr);
				GameInterface.settingslist.bShown = true;
			}
		}
		optCount++;

	}
	for(i=1; i<7; i++)
	{
		string nName = "SETTINGS_DESCR"+i;
		SetNodeUsing(nName,false);
	}

	SetCurrentNode("SETTINGS_WINDOW");
	LanguageCloseFile(tmpLangFileID);
}

void ShowSettingsDescribe(string settingName, int textNum)
{
	if(settingName=="") return;
	int tmpLangFileID = LanguageOpenFile("SettingsDescribe.txt");
	int i, posY, chkCount;
	ChangeStringColor("BuildSettingsTitle", COLOR_DESELECT);
	ChangeStringColor("BuildSettingsDescr", COLOR_DESELECT);

	SetNodeUsing("WINDOW_FADER",true);
	SetNodeUsing("SETTINGS_NAME",true);
	SetNodeUsing("SETTINGS_IMAGE",true);
	SetNodeUsing("SETTINGS_OK_BUTTON",true);
	SetNodeUsing("SETTINGS_CANCEL_BUTTON",true);
	SetNodeUsing("SETTINGS_DESCRIBE_RECT",true);
	SetNodeUsing("SETTINGS_LINES",true);
	SetNodeUsing("VALUE_CHANGER",false);
	SetSelectable("EXIT_BUTTON",false);
	SetSelectable("SETTINGS_WINDOW",false);
	SetSelectable("SETTINGS_SCROLL",false);
	SetSelectable("SETTINGS_DEFAULT_BUTTON",false);

	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "SETTINGS_DESCRIBEWINDOW");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "SETTINGS_DESCRIBEWINDOW1");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "SETTINGS_DESCRIBEWINDOW2");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "SETTINGS_DESCRIBEWINDOW3");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "SETTINGS_OK_BUTTON");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "SETTINGS_CANCEL_BUTTON");

	if(settingName=="SettingsDefault")
	{
		GameInterface.Buildsettings.tempData = settingName;

		SendMessage(&GameInterface,"lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE,"SETTINGS_NAME",0,
			"SettingName", LanguageConvertString(tmpLangFileID,settingName), FONT_NORMAL,
			320,108, COLOR_NORMAL,0, SCRIPT_ALIGN_CENTER, true, 1.5, 420);

		SetNodeUsing("SETTINGS_DESCRIBEWINDOW2",true);
		SetFormatedText("SETTINGS_DESCRIBEWINDOW2",LanguageConvertString(tmpLangFileID,settingName+"info"));
		SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"SETTINGS_DESCRIBEWINDOW2", 5);

		SetCurrentNode("SETTINGS_CANCEL_BUTTON");

		LanguageCloseFile(tmpLangFileID);
		return;
	}

	SendMessage(&GameInterface,"lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE,"SETTINGS_NAME",0,
		"SettingName", LanguageConvertString(tmpLangFileID,settingName), FONT_NORMAL,
		320,108, COLOR_NORMAL,0, SCRIPT_ALIGN_CENTER, true, 1.5, 420);

	posY = 0;
	chkCount = 0;
	string fText = "";
	string fullText = "";
	for(i=1; i<7; i++)
	{
		string nName = "SETTINGS_DESCR"+i;
		string sName = "SettingDescr"+i;
		string iName = "setting"+settingName+i;
		if(LanguageConvertString(tmpLangFileID,iName)!="")
		{
			if(!CheckForNum(settingName))
			{
				SetNodeUsing("SETTINGS_DESCRIBEWINDOW",false);
				SetNodeUsing(nName,true);
				string translString = LanguageConvertString(tmpLangFileID,iName);
				if(HasSubStr(translString,"#")) translString = strcut(translString,1,strlen(translString)-1);

				if(strlen(LanguageConvertString(tmpLangFileID,iName))<=85 && !HasSubStr(LanguageConvertString(tmpLangFileID,iName),"#"))
				{
					SendMessage(&GameInterface,"lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE,nName,0,sName, translString, FONT_NORMAL,93,sti(258+posY)+2, COLOR_NORMAL,0, SCRIPT_ALIGN_LEFT, true, 0.8, 480);
					//SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,nName, 5);
				}
				else
				{
					SetNodeUsing(nName,false);
					if(HasSubStr(LanguageConvertString(tmpLangFileID,iName),"#"))
					{
						SetNodeUsing("SETTINGS_DESCRIBEWINDOW2",true);
						SetFormatedText("SETTINGS_DESCRIBEWINDOW2",translString);
						SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"SETTINGS_DESCRIBEWINDOW2", 5);
					}
					else
					{
						SetNodeUsing("SETTINGS_DESCRIBEWINDOW1",true);
						SetFormatedText("SETTINGS_DESCRIBEWINDOW1",translString);
						SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"SETTINGS_DESCRIBEWINDOW1", 5);
					}
				}
				if(!HasSubStr(LanguageConvertString(tmpLangFileID,iName),"#"))
				{
					posY = sti(posY)+30;
					chkCount++;
				}
			}
			else
			{
				SetNodeUsing("SETTINGS_DESCRIBEWINDOW",true);
				SetNodeUsing(nName,false);
				fText += LanguageConvertString(tmpLangFileID,iName)+" ";
			}
			fullText += LanguageConvertString(tmpLangFileID,iName)+" ";
		}
	}
	if(CheckForNum(settingName))
	{
		SetFormatedText("SETTINGS_DESCRIBEWINDOW",fText);
		SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"SETTINGS_DESCRIBEWINDOW", 5);
	}
	posY = 0;
	string tmpStr = "setting"+textNum;
	if(CheckAttribute(GameInterface,"settingslist."+tmpStr) && GetOptionType(GameInterface.settingslist.(tmpStr))!="")
	{
		string optName = GameInterface.settingslist.(tmpStr);
		int curInt = sti(PlayerProfile.Buildsettings.(optName));
		float curFloat = stf(PlayerProfile.Buildsettings.(optName));
		if(CheckForNum(optName))
		{
			CreateIntChanger(optName, 1, CheckPercent(fullText));
			AddHelpString("SETTINGS_DESCRIBEWINDOW3", "int");
		}
		else
		{
			switch(GetOptionType(optName))
			{
				case "int": CreateCheckBoxes(optName, chkCount, sti(GameInterface.Buildsettings.(optName))); break;
				case "float": CreateFloatChanger(optName, 0.01, CheckPercent(fullText)); AddHelpString("SETTINGS_DESCRIBEWINDOW3", "float"); break;
				case "string":
					if(HasSubStr(optName,"new_model") || HasSubStr(optName,"new_ship"))
					{
						CreateScrollChanger(optName);
						SendMessage(&GameInterface,"lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE,"SETTINGS_DESCR1",0,"SettingDescr1", LanguageConvertString(tmpLangFileID,"setting"+settingName+"1"), FONT_NORMAL,320,sti(258+posY)+2, argb(255,255,255,0),0, SCRIPT_ALIGN_CENTER, true, 0.8, 480);
						SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"SETTINGS_DESCR1", 5);
					}
					else { CreateStringChanger(optName); }
				break;
			}
		}
	}

	SetCurrentNode("SETTINGS_CANCEL_BUTTON");

	LanguageCloseFile(tmpLangFileID);
}

void AddHelpString(string nName, string vName)
{
	int tmpLangFileID = LanguageOpenFile("SettingsDescribe.txt");
	string vType = "+";
	switch(vName)
	{
		case "int": vType += "10"; break;
		case "float": vType += "0.1"; break;
	}
	string fText = LanguageConvertString(tmpLangFileID,"CtrlPress")+" "+vType;
	if(vName=="int")
	{
		vType = "+100";
		fText += ", "+LanguageConvertString(tmpLangFileID,"AltPress")+" "+vType+" ";
		vType = "+500";
		fText += ", "+LanguageConvertString(tmpLangFileID,"ShiftPress")+" "+vType;
	}

	SetNodeUsing(nName,true);
	SetFormatedText(nName,fText);
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,nName, 5);

	LanguageCloseFile(tmpLangFileID);
}

bool CheckPercent(string fullText)
{
	for(int n=0; n<strlen(fullText); n++)
	{
		string pSymbol = GetSymbol(&fullText,n);
		if(pSymbol=="%") { return true; }
	}
	return false;
}

bool bBeParty = true;

void UpdateSettings(string optName)
{
	if(optName=="SettingsDefault")
	{
		InitBuildOptions(true, true);
		InitBuildOptions(false, true);
		SetSettingsList();
		SetCurrentNode("SETTINGS_DEFAULT_BUTTON");
		return;
	}
	PlayerProfile.Buildsettings.(optName) = GameInterface.Buildsettings.(optName);
	UpdateScrollSettings(optName);
	SetSettingsList();
}

void UpdateScrollSettings(string optName)
{
	int i = -1;
	string attrName = "";

	switch(optName)
	{
		case "NEW_MODEL":
			for(i=0; i<CheckForStringsCount(optName); i++)
			{
				attrName = optName + "_" + sti(i+1);
				PlayerProfile.Buildsettings.(attrName) = GameInterface.Buildsettings.(attrName);
			}
		break;

		case "NEW_SHIP":
			for(i=0; i<CheckForStringsCount(optName); i++)
			{
				attrName = optName + "_" + sti(i+1);
				PlayerProfile.Buildsettings.(attrName) = GameInterface.Buildsettings.(attrName);
			}
		break;
	}
}

void UpdateTempData()
{
	if(CheckAttribute(GameInterface,"Buildsettings")) DeleteAttribute(GameInterface,"Buildsettings");

	GameInterface.Buildsettings.tempData = "";
	GameInterface.Buildsettings.tempModel = "";
	GameInterface.Buildsettings.tempModel.description = "";
	GameInterface.Buildsettings.flStep = 0.0;
	GameInterface.Buildsettings.inStep = 0;
	GameInterface.Buildsettings.boxCount = 0;
	GameInterface.Buildsettings.bPersent = false;
	GameInterface.Buildsettings.mCount = 0;

	string attrName;
	aref curItem;
	int i;

	for(i=0; i<GetAttributesNum(bSet); i++)
	{
		curItem = GetAttributeN(bSet, i);
		attrName = GetAttributeName(curItem);
		GameInterface.Buildsettings.(attrName) = PlayerProfile.Buildsettings.(attrName);
	}
}

void CreateCheckBoxes(string optName, int chkCount, int startBox)
{
	string tmpStr = GameInterface.Buildsettings.(optName);

	GameInterface.Buildsettings.tempData = optName;
	GameInterface.Buildsettings.tempModel = "";
	GameInterface.Buildsettings.flStep = 0.0;
	GameInterface.Buildsettings.inStep = 0;
	GameInterface.Buildsettings.boxCount = chkCount;
	GameInterface.Buildsettings.bPersent = false;
	GameInterface.Buildsettings.mCount = 0;

	int startX = 58; int endX = 80; int startY = 259; int endY = 281;
	for(int i=0; i<chkCount; i++)
	{
		bool bComplete = false;
		if(i==startBox) bComplete = true;
		CreateChecker("", "SETTINGS_CHECKER_BUTTON"+i, "CheckerName"+sti(i+1), "", "CHECKBOX_"+sti(i+1), COLOR_NORMAL, startX, startY, endX, endY, bComplete);
		startY = endY+8;
		endY = endY+30;
	}
	UpdateString(GameInterface.Buildsettings.(optName));
}

void SetNewOption(string optName, int boxIndex)
{
	CreateCheckBoxes(optName, sti(GameInterface.Buildsettings.boxCount), boxIndex);
	GameInterface.Buildsettings.(optName) = boxIndex;

	UpdateString(GameInterface.Buildsettings.(optName));
}

int GetCheckBoxIndex(int sCut, string boxName)
{
	return sti(strcut(boxName, sCut, strlen(boxName)-1));
}

void HideCheckBoxes(int boxCount)
{
	for(int i=0; i<boxCount; i++)
	{
		SetNodeUsing("SETTINGS_CHECKER_BUTTON"+i,false);
		string attrName = "CHECKBOX_"+sti(i+1);

		GameInterface.pictures.(attrName).pic = -1;
		GameInterface.pictures.(attrName).tex = -1;
	}
}

void CreateStringChanger(string optName)
{
	string tmpStr = GameInterface.Buildsettings.(optName);

	SetNodeUsing("SETTINGS_NUMCHANGE",true);
	SetNodeUsing("VALUE_CHANGER",true);
	SetNodeUsing("VALUE_RECT",true);
	SetSelectable("VALUE_CHANGER",true);

	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "VALUE_CHANGER");

	GameInterface.Buildsettings.tempData = optName;
	GameInterface.Buildsettings.tempModel = tmpStr;
	GameInterface.Buildsettings.flStep = 0.0;
	GameInterface.Buildsettings.inStep = 0;
	GameInterface.Buildsettings.boxCount = 0;
	GameInterface.Buildsettings.bPersent = false;
	GameInterface.Buildsettings.mCount = CheckForCurrentString(optName, tmpStr);

	UpdateString(GameInterface.Buildsettings.(optName));
}

void CreateIntChanger(string optName, int iStep, bool showPercent)
{
	string tmpStr = GameInterface.Buildsettings.(optName);
	if(showPercent) tmpStr += "%";

	SetNodeUsing("SETTINGS_NUMCHANGE",true);
	SetNodeUsing("VALUE_RECT",true);
	SetNodeUsing("VALUE_CHANGER",true);
	SetSelectable("VALUE_CHANGER",true);
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "VALUE_CHANGER");

	GameInterface.Buildsettings.tempData = optName;
	GameInterface.Buildsettings.tempModel = "";
	GameInterface.Buildsettings.flStep = 0.0;
	GameInterface.Buildsettings.inStep = iStep;
	GameInterface.Buildsettings.boxCount = 0;
	GameInterface.Buildsettings.bPersent = showPercent;
	GameInterface.Buildsettings.mCount = 0;

	EnableQuickControls();
	UpdateString(GameInterface.Buildsettings.(optName));
}

void CreateFloatChanger(string optName, float fStep, bool showPercent)
{
	string tmpStr = GameInterface.Buildsettings.(optName);
	if(showPercent) tmpStr += "%";

	SetNodeUsing("SETTINGS_NUMCHANGE",true);
	SetNodeUsing("VALUE_RECT",true);
	SetNodeUsing("VALUE_CHANGER",true);
	SetSelectable("VALUE_CHANGER",true);
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "VALUE_CHANGER");

	GameInterface.Buildsettings.tempData = optName;
	GameInterface.Buildsettings.tempModel = "";
	GameInterface.Buildsettings.flStep = fStep;
	GameInterface.Buildsettings.inStep = 0;
	GameInterface.Buildsettings.boxCount = 0;
	GameInterface.Buildsettings.bPersent = showPercent;
	GameInterface.Buildsettings.mCount = 0;

	EnableQuickControls();
	UpdateString(strcut(GameInterface.Buildsettings.(optName),0,2));
}

void HideScroll()
{
	bScrollShow = false;
	//SetNodeUsing("SETTINGSMODELSLIST",false);
	SetNodeUsing("MODELSLEFTSCROLLBUTTON",false);
	SetNodeUsing("MODELSRIGHTSCROLLBUTTON",false);
	SetNodeUsing("SETTINGSSHIPSLIST",false);
	SetNodeUsing("SHIPSLEFTSCROLLBUTTON",false);
	SetNodeUsing("SHIPSRIGHTSCROLLBUTTON",false);
	//DelEventHandler("IEvnt_CheckNames","CheckNames");

	for(int i=0; i<16; i++)
	{
		string attrName = "ScrollCheckerPic"+sti(i+1);

		GameInterface.pictures.(attrName).pic = -1;
		GameInterface.pictures.(attrName).tex = -1;

		SetNodeUsing("CHECKER_NAME"+sti(i+1),false);
		SetNodeUsing("SCROLL_BUTTON"+sti(i+1),false);
	}
}

void CreateScrollCheckers(string optName, string iName, int chkCount, string mId, int nameColor, bool bShow)
{
	string attrName1, curNodeName, curButton, curModel;
	int i;

	int startBox = CheckForCurrentString(optName, GameInterface.Buildsettings.(optName));
	if(chkCount!=-1) startBox = chkCount;
	int startX = 68; int endX = 90; int startY = 297; int endY = 319;
	int curSy = startY; int curEy = endY;
	bool bComplete; bool b1 = false; bool b2 = false; bool b3 = false;
	int curColor = COLOR_NORMAL;

	for(i=0; i<CheckForStringsCount(optName); i++)
	{
		bComplete = false;
		attrName1 = iName+sti(i+1);
		int curSx = startX; int curEx = endX;
		curModel = CheckForStringValue(optName, sti(i+1));
		string newOption = optName + "_" + sti(i+1);
		if(i==startBox)
		{
			curColor = COLOR_NORMAL;
			bComplete = true;
			if(mId!="")
			{
				curModel = mId;
				GameInterface.Buildsettings.(newOption) = curModel;
				if(GameInterface.Buildsettings.(newOption)!=PlayerProfile.Buildsettings.(newOption)) curColor = nameColor;
			}
		}
		else
		{
			curColor = COLOR_NORMAL;
			if(CheckAttribute(GameInterface,"Buildsettings."+newOption))
			{
				curModel = GameInterface.Buildsettings.(newOption);
				if(GameInterface.Buildsettings.(newOption)!=PlayerProfile.Buildsettings.(newOption)) curColor = nameColor;
			}
		}

		if(i>=3 && i<6) { curSx = startX+130; curEx = endX+130; if(!b1) { b1 = true; curSy = startY; curEy = endY; } }
		if(i>=6 && i<9) { curSx = startX+260; curEx = endX+260; if(!b2) { b2 = true; curSy = startY; curEy = endY; } }
		if(i>=9 && i<12) { curSx = startX+390; curEx = endX+390; if(!b3) { b3 = true; curSy = startY; curEy = endY; } }
		if(optName=="new_ship") curModel = XI_ConvertString(curModel);
		CreateChecker("CHECKER_NAME"+sti(i+1), "SCROLL_BUTTON"+sti(i+1),
			"CheckerName"+sti(i+1), curModel, attrName1, curColor, curSx, curSy, curEx, curEy, bComplete);
		curSy = curEy+8;
		curEy = curEy+30;
	}
}

void CreateChecker(string nName, string btName, string sName, string sData, string bName, int nameColor, int startX, int startY, int endX, int endY, bool bComplete)
{
// KK -->
	string ni = "";
	if (bNewInterface) ni = "_new";
	if(bComplete)
		CreateImage(bName, "CHECKBOX", "check_complete" + ni, startX, startY, endX, endY);
	else
		CreateImage(bName, "CHECKBOX", "check_noncomplete" + ni, startX, startY, endX, endY);
// <-- KK

	if(nName!="")
	{
		SetNodeUsing(nName,true);
		SendMessage(&GameInterface,"lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE, nName, 0, sName, sData,
			FONT_NORMAL, sti(startX+32), sti(startY+5), nameColor, 0, SCRIPT_ALIGN_LEFT, true, 0.8, 420);
	}

	SetNodeUsing(btName,true);
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, btName);
}

void MarkBox(string optName, int boxIndex)
{
	/*for(int i=0; i<CheckForStringsCount(optName); i++)
	{
		if(sti(i+1)==boxIndex)
		{
			CreateScrollCheckers(optName,"ScrollCheckerPic",i,GetNameFromScroll(optName, -1),COLOR_RED,true);
		}
	}*/
}

void CreateScrollChanger(string optName)
{
	bScrollShow = true;
	string tmpStr = GameInterface.Buildsettings.(optName);
	string list, left, right;

	/*switch(optName)
	{
		case "new_model": list = "SETTINGSMODELSLIST"; left = "MODELSLEFTSCROLLBUTTON"; right = "MODELSRIGHTSCROLLBUTTON"; break;
		case "new_ship": list = "SETTINGSSHIPSLIST"; left = "SHIPSLEFTSCROLLBUTTON"; right = "SHIPSRIGHTSCROLLBUTTON"; break;
	}*/

	SetNodeUsing(list,true);
	SetNodeUsing(left,true);
	SetNodeUsing(right,true);
	SetCurrentNode(list);

	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, list);
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, left);
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, right);

	CreateScrollCheckers(optName,"ScrollCheckerPic",-1,"",COLOR_NORMAL,true);
	/*if(optName=="new_ship")
	{
		SetEventHandler("IEvnt_CheckNames","CheckNames",0);
		Event("IEvnt_CheckNames");
		EnableString("shipModel");
	}*/

	GameInterface.Buildsettings.tempData = optName;
	GameInterface.Buildsettings.tempModel = tmpStr;
	GameInterface.Buildsettings.flStep = 0.0;
	GameInterface.Buildsettings.inStep = 0;
	GameInterface.Buildsettings.boxCount = 0;
	GameInterface.Buildsettings.bPersent = false;
	GameInterface.Buildsettings.mCount = 0;
}

/*void FillShipsScroll()
{
	ref ship;
	string attributeName, shipName;
	int shipsCount = 0;
	string sNamesCount = "";
	int bFirst = -1;

	GameInterface.SETTINGSSHIPSLIST.BadPicture2 = "interfaces\blank_ship.tga";
	GameInterface.SETTINGSSHIPSLIST.ImagesGroup.t0 = "ICONS";
	GameInterface.SETTINGSSHIPSLIST.ImagesGroup.t1 = "SHIPS16";
	GameInterface.SETTINGSSHIPSLIST.ImagesGroup.t2 = "SHIPS1";
	GameInterface.SETTINGSSHIPSLIST.ImagesGroup.t3 = "SHIPS2";
	GameInterface.SETTINGSSHIPSLIST.ImagesGroup.t4 = "SHIPS3";
	GameInterface.SETTINGSSHIPSLIST.ImagesGroup.t5 = "SHIPS4";
	GameInterface.SETTINGSSHIPSLIST.ImagesGroup.t6 = "SHIPS5";

	for(int i=0; i<CheckForStringsCount("NEW_SHIP")+1; i++)
	{
		string defModel = CheckForStringValue("NEW_SHIP", i);
		if(GetShipIndex(defModel)==-1) continue;
		if(HasSubStr(sNamesCount,defModel)) continue;
		sNamesCount = StoreString(sNamesCount,defModel);

		attributeName = "pic" + sti(shipsCount+1);

		GameInterface.SETTINGSSHIPSLIST.(attributeName).str1 = "#"+sti(shipsCount+1);
		GameInterface.SETTINGSSHIPSLIST.(attributeName).str2 = ShipsTypes[GetShipIndex(defModel)].SName;
		GameInterface.SETTINGSSHIPSLIST.(attributeName).img1 = "ship back";
		GameInterface.SETTINGSSHIPSLIST.(attributeName).img2 = GetShipPicName(GetShipIndex(defModel));
		GameInterface.SETTINGSSHIPSLIST.(attributeName).tex1 = 0;
		GameInterface.SETTINGSSHIPSLIST.(attributeName).tex2 = 1+GetShipTexture(GetShipIndex(defModel));
		GameInterface.SETTINGSSHIPSLIST.(attributeName).mod1 = "";
		GameInterface.SETTINGSSHIPSLIST.(attributeName).mod2 = defModel;

		if(defModel==PlayerProfile.BuildSettings.NEW_SHIP || defModel==NEW_SHIP_1) bFirst = shipsCount;
		shipsCount++;
	}

	for(int n=0; n<SHIP_TYPES_QUANTITY_WITH_FORT-2; n++)
	{
		if(n==SHIP_FORT || n==SHIP_BOAT || n==SHIP_NOTUSED) continue;
		if(!CheckAttribute(&ShipsTypes[n],"Class")) continue;
		if(!CheckAttribute(&ShipsTypes[n],"Sname")) continue;
		if(CheckAttribute(&ShipsTypes[n],"id"))
		{
			if(sti(ShipsTypes[n].Class)>=6 && !ENABLE_CHEATMODE) // PB
			{
				attributeName = "pic" + sti(shipsCount+1);
				shipName = ShipsTypes[n].SName;
				if(HasSubStr(sNamesCount,shipName)) continue;
				sNamesCount = StoreString(sNamesCount,shipName);

				int iShipType = GetShipIndex(ShipsTypes[n].id);

				GameInterface.SETTINGSSHIPSLIST.(attributeName).str1 = "#"+sti(shipsCount+1);
				GameInterface.SETTINGSSHIPSLIST.(attributeName).str2 = shipName;
				GameInterface.SETTINGSSHIPSLIST.(attributeName).img1 = "ship back";
				GameInterface.SETTINGSSHIPSLIST.(attributeName).img2 = GetShipPicName(iShipType);
				GameInterface.SETTINGSSHIPSLIST.(attributeName).tex1 = 0;
				GameInterface.SETTINGSSHIPSLIST.(attributeName).tex2 = 1+GetShipTexture(iShipType);
				GameInterface.SETTINGSSHIPSLIST.(attributeName).mod1 = "";
				GameInterface.SETTINGSSHIPSLIST.(attributeName).mod2 = ShipsTypes[n].id;

				if(ShipsTypes[n].id==PlayerProfile.BuildSettings.NEW_SHIP || ShipsTypes[n].id==NEW_SHIP_1) bFirst = shipsCount;
				shipsCount++;
			}
		}

	}

	if(bFirst!=-1) { nCurSScrollNum = bFirst; }
	else nCurSScrollNum = 0;

	GameInterface.SETTINGSSHIPSLIST.ListSize = shipsCount;

	if (nCurSScrollNum < 0 || nCurSScrollNum >= sti(GameInterface.SETTINGSSHIPSLIST.ListSize)) { nCurSScrollNum = 0; }
	GameInterface.SETTINGSSHIPSLIST.current = nCurSScrollNum;
}

void FillModelsScroll()
{
	ref model;
	GameInterface.Buildsettings.tempModel.idx = -1;
	int modelsCount = 0;
	string mNamesCount = "";
	string NamesCount = "";
	string attributename1, attributename2;
	int bFirst = -1;

	for(int i=0; i<CheckForStringsCount("NEW_MODEL")+1; i++)
	{
		string defModel = CheckForStringValue("NEW_MODEL", i);
		if(GetModelIndex(defModel)==-1) continue;
		if(HasSubStr(NamesCount,defModel)) continue;
		NamesCount = StoreString(NamesCount,defModel);

		attributename1 = "t" + sti(modelsCount+1);
		attributename2 = "pic" + sti(modelsCount+1);

		GameInterface.SETTINGSMODELSLIST.ImagesGroup.(attributename1) = "FACE128_" + GetModelFaceId(defModel);
		GameInterface.SETTINGSMODELSLIST.(attributename2).img1 = "face";
		GameInterface.SETTINGSMODELSLIST.(attributename2).tex1 = modelsCount;
		GameInterface.SETTINGSMODELSLIST.(attributename2).str1 = "#"+sti(modelsCount+1);
		GameInterface.SETTINGSMODELSLIST.(attributename2).str2 = "#"+defModel;

		if(FindFile("RESOURCE\Textures\INTERFACES\PORTRAITS\128", "*.tga.tx", "face_"+Models[GetModelIndex(defModel)].FaceId+".tga.tx")=="")
		{
			GameInterface.SETTINGSMODELSLIST.ImagesGroup.(attributename1) = "EMPTYFACE";
			GameInterface.SETTINGSMODELSLIST.(attributename2).img1 = "emptyface";
		}

		if(defModel==PlayerProfile.BuildSettings.NEW_MODEL || defModel==NEW_MODEL_1) bFirst = modelsCount;
		modelsCount++;
	}

	for(int n=0; n<MODEL_HIGH ; n++)
	{
		if(CheckAttribute(&Models[n],"id") && !HasSubStr(Models[n].id,"monkey") && IsAlefBet(Models[n].id))
		{
			if(CheckAttribute(&Models[n],"FaceId") && !HasSubStr(mNamesCount,"FACE128_" + Models[n].FaceId))
			{
				if(CheckAttribute(&Models[n],"description") && Models[n].description!="" && !HasSubStr(Models[n].description,"soldier"))
				{
					if(HasSubStr(NamesCount,Models[n].id)) continue;

					attributename1 = "t" + sti(modelsCount+1);
					attributename2 = "pic" + sti(modelsCount+1);

					mNamesCount = StoreString(mNamesCount,"FACE128_" + Models[n].FaceId);
					NamesCount = StoreString(NamesCount,Models[n].id);

					GameInterface.SETTINGSMODELSLIST.ImagesGroup.(attributename1) = "FACE128_" + Models[n].FaceId;
					GameInterface.SETTINGSMODELSLIST.(attributename2).img1 = "face";
					GameInterface.SETTINGSMODELSLIST.(attributename2).tex1 = modelsCount;
					GameInterface.SETTINGSMODELSLIST.(attributename2).str1 = "#"+sti(modelsCount+1);
					GameInterface.SETTINGSMODELSLIST.(attributename2).str2 = "#"+Models[n].id;

					if(FindFile("RESOURCE\Textures\INTERFACES\PORTRAITS\128", "*.tga.tx", "face_"+Models[n].FaceId+".tga.tx")=="")
					{
						GameInterface.SETTINGSMODELSLIST.ImagesGroup.(attributename1) = "EMPTYFACE";
						GameInterface.SETTINGSMODELSLIST.(attributename2).img1 = "emptyface";
					}

					if(Models[n].id==PlayerProfile.BuildSettings.NEW_MODEL || Models[n].id==NEW_MODEL_1) bFirst = modelsCount;
					modelsCount++;
				}
			}
		}
	}

	if(bFirst!=-1) { nCurScroll = bFirst; }
	else nCurScroll = 0;

	GameInterface.SETTINGSMODELSLIST.ListSize = modelsCount;

	if(nCurScroll<0 || nCurScroll>=sti(GameInterface.SETTINGSMODELSLIST.ListSize)) { nCurScroll = 0; }
	GameInterface.SETTINGSMODELSLIST.current = nCurScroll;
}

void CheckNames()
{
	GameInterface.strings.shipModel = GetNameFromScroll("new_ship_model", nCurSScrollNum);
	PostEvent("IEvnt_CheckNames", 1);
}

string GetNameFromScroll(string optName, int scrollNum)
{
	string attributeName;
	switch(optName)
	{
		case "new_model":
			if(scrollNum==-1) scrollNum = nCurScroll;
			attributeName = "pic" + (scrollNum+1);
			if(CheckAttribute(&GameInterface,"SETTINGSMODELSLIST."+attributeName))
			return strcut(GameInterface.SETTINGSMODELSLIST.(attributeName).str2, 1, strlen(GameInterface.SETTINGSMODELSLIST.(attributeName).str2)-1);
		break;

		case "new_ship":
			if(scrollNum==-1) scrollNum = nCurSScrollNum;
			attributeName = "pic" + (scrollNum+1);
			if(CheckAttribute(&GameInterface,"SETTINGSSHIPSLIST."+attributeName))
			return GameInterface.SETTINGSSHIPSLIST.(attributeName).str2;
		break;

		case "new_ship_model":
			if(scrollNum==-1) scrollNum = nCurSScrollNum;
			attributeName = "pic" + (scrollNum+1);
			if(CheckAttribute(&GameInterface,"SETTINGSSHIPSLIST."+attributeName))
			return GameInterface.SETTINGSSHIPSLIST.(attributeName).mod2;
		break;
	}
	return "";
}

int GetModelFaceId(string curModel)
{
	ref model;
	for(int i=0; i<MODEL_HIGH; i++)
	{
		makeref(model,Models[i]);
		if(CheckAttribute(model,"id") && model.id==curModel)
		{
			if(CheckAttribute(model,"FaceId") && sti(model.FaceId)>=0)
			{
				return sti(model.FaceId);
			}
		}
	}
	return -1;
}*/

void UpdateString(string tmpStr)
{
	if(sti(GameInterface.Buildsettings.bPersent)) tmpStr += "%";
	SendMessage(&GameInterface,"lslsssllllllfl", MSG_INTERFACE_MSG_TO_NODE,"SETTINGS_NUMCHANGE",0,"OptionValue", tmpStr, FONT_NORMAL,320,203, COLOR_MONEY,0, SCRIPT_ALIGN_CENTER, true, 1.2, 480);
	//SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"SETTINGS_NUMCHANGE", 5);
}

void ProcessChangeLeft()
{
	if(bBeParty)
	{
		SetNextParty(false);
	}
}

void ProcessChangeRight()
{
	if(bBeParty)
	{
		SetNextParty(true);
	}
}

void SetNextParty(bool bRight)
{
	int keyAdd = 1;
	string tempData = GameInterface.Buildsettings.tempData;
	string tempModel = GameInterface.Buildsettings.tempModel;
	float flStep = stf(GameInterface.Buildsettings.flStep);
	int inStep = sti(GameInterface.Buildsettings.inStep);
	int boxCount = sti(GameInterface.Buildsettings.boxCount);
	bool bPersent = sti(GameInterface.Buildsettings.bPersent);
	int mCount = sti(GameInterface.Buildsettings.mCount);
	string showData = GameInterface.Buildsettings.(tempData);

	if(bRight)
	{
		if(flStep!=0.0)
		{
			if(GetQuickControl("control")) keyAdd = 10;
			GameInterface.Buildsettings.(tempData) = fClamp(CheckForMinFloatValue(tempData), CheckForMaxFloatValue(tempData), stf(GameInterface.Buildsettings.(tempData))+stf(flStep*makefloat(keyAdd)));
			showData = strcut(GameInterface.Buildsettings.(tempData),0,3);
			if(stf(GameInterface.Buildsettings.(tempData))==0.0) showData = strcut(GameInterface.Buildsettings.(tempData),0,2);
		}
		if(inStep!=0)
		{
			if(GetQuickControl("control")) keyAdd = 10;
			if(GetQuickControl("alt")) keyAdd = 100;
			if(GetQuickControl("shift")) keyAdd = 500;
			GameInterface.Buildsettings.(tempData) = iClamp(CheckForMinIntValue(tempData), CheckForMaxIntValue(tempData), sti(GameInterface.Buildsettings.(tempData))+sti(inStep*keyAdd));
			showData = GameInterface.Buildsettings.(tempData);
		}
		if(mCount<=CheckForStringsCount(tempData) && tempModel!="")
		{
			if(mCount<CheckForStringsCount(tempData)) mCount++;
			else mCount=CheckForStringsCount(tempData);
			GameInterface.Buildsettings.(tempData) = CheckForStringValue(tempData, mCount);
			showData = GameInterface.Buildsettings.(tempData);
			GameInterface.Buildsettings.mCount = mCount;
		}
	}
	else
	{
		if(flStep!=0.0)
		{
			if(GetQuickControl("control")) keyAdd = 10;
			GameInterface.Buildsettings.(tempData) = fClamp(CheckForMinFloatValue(tempData), CheckForMaxFloatValue(tempData), stf(GameInterface.Buildsettings.(tempData))-stf(flStep*makefloat(keyAdd)));
			showData = strcut(GameInterface.Buildsettings.(tempData),0,3);
			if(stf(GameInterface.Buildsettings.(tempData))==0.0) showData = strcut(GameInterface.Buildsettings.(tempData),0,2);
		}
		if(inStep!=0)
		{
			if(GetQuickControl("control")) keyAdd = 10;
			if(GetQuickControl("alt")) keyAdd = 100;
			if(GetQuickControl("shift")) keyAdd = 500;
			GameInterface.Buildsettings.(tempData) = iClamp(CheckForMinIntValue(tempData), CheckForMaxIntValue(tempData), sti(GameInterface.Buildsettings.(tempData))-sti(inStep*keyAdd));
			showData = GameInterface.Buildsettings.(tempData);
		}
		if(mCount>=0 && tempModel!="")
		{
			if(mCount>0) mCount--;
			else mCount = 0;
			GameInterface.Buildsettings.(tempData) = CheckForStringValue(tempData, mCount);
			showData = GameInterface.Buildsettings.(tempData);
			GameInterface.Buildsettings.mCount = mCount;
		}
	}

	UpdateString(showData);
}

int CheckForStringsCount(string settingName)
{
	if(settingName=="NEW_MODEL") return 12;
	if(settingName=="NEW_SHIP") return 8;

	return 0;
}

int CheckForCurrentString(string settingName, string curModel)
{
	int tmpStr = 0;
	switch(settingName)
	{
		case "NEW_MODEL":
			switch(curModel)
			{
				case NEW_MODEL_1: tmpStr = 1; break;
				case NEW_MODEL_2: tmpStr = 2; break;
				case NEW_MODEL_3: tmpStr = 3; break;
				case NEW_MODEL_4: tmpStr = 4; break;
				case NEW_MODEL_5: tmpStr = 5; break;
				case NEW_MODEL_6: tmpStr = 6; break;
				case NEW_MODEL_7: tmpStr = 7; break;
				case NEW_MODEL_8: tmpStr = 8; break;
				case NEW_MODEL_9: tmpStr = 9; break;
				case NEW_MODEL_10: tmpStr = 10; break;
				case NEW_MODEL_11: tmpStr = 11; break;
				case NEW_MODEL_12: tmpStr = 12; break;
			}
		break;

		case "NEW_SHIP":
			switch(curModel)
			{
				case NEW_SHIP_1: tmpStr = 1; break;
				case NEW_SHIP_2: tmpStr = 2; break;
				case NEW_SHIP_3: tmpStr = 3; break;
				case NEW_SHIP_4: tmpStr = 4; break;
				case NEW_SHIP_5: tmpStr = 5; break;
				case NEW_SHIP_6: tmpStr = 6; break;
				case NEW_SHIP_7: tmpStr = 7; break;
				case NEW_SHIP_8: tmpStr = 8; break;
			}
		break;
	}

	return tmpStr;
}

string CheckForStringValue(string settingName, int step)
{
	string tmpStr = "";
	switch(settingName)
	{
		case "NEW_MODEL":
// KK -->
			switch (step) {
				case 0: tmpStr = NEW_MODEL_1; break;
				case 1: tmpStr = NEW_MODEL_2; break;
				case 2: tmpStr = NEW_MODEL_3; break;
				case 3: tmpStr = NEW_MODEL_4; break;
				case 4: tmpStr = NEW_MODEL_5; break;
				case 5: tmpStr = NEW_MODEL_6; break;
				case 6: tmpStr = NEW_MODEL_7; break;
				case 7: tmpStr = NEW_MODEL_8; break;
				case 8: tmpStr = NEW_MODEL_9; break;
				case 9: tmpStr = NEW_MODEL_10; break;
				case 10: tmpStr = NEW_MODEL_11; break;
				case 11: tmpStr = NEW_MODEL_12; break;
			}
// <-- KK
		break;

		case "NEW_SHIP":
// KK -->
			switch (step) {
				case 0: tmpStr = NEW_SHIP_1; break;
				case 1: tmpStr = NEW_SHIP_2; break;
				case 2: tmpStr = NEW_SHIP_3; break;
				case 3: tmpStr = NEW_SHIP_4; break;
				case 4: tmpStr = NEW_SHIP_5; break;
				case 5: tmpStr = NEW_SHIP_6; break;
				case 6: tmpStr = NEW_SHIP_7; break;
				case 7: tmpStr = NEW_SHIP_8; break;
			}
// <-- KK
		break;
	}

	return tmpStr;
}

bool CheckForNum(string settingName)
{
	if(settingName=="DEATHRATE") return true;
	if(settingName=="SALARY_MULTIPLIER") return true;
	if(settingName=="NO_THEFT") return true;
	if(settingName=="LOCK_OPEN") return true;
	if(settingName=="BLOCKDAMAGE") return true;

	return false;
}

float CheckForMaxFloatValue(string settingName)
{
	if(settingName=="SURR_GLOBAL_SCL") return 0.5;
	if(settingName=="DIALOG_CAMERA") return 1.0;

	return 0.0;
}

float CheckForMinFloatValue(string settingName)
{
	if(settingName=="SURR_GLOBAL_SCL") return 0.0;
	if(settingName=="DIALOG_CAMERA") return 0.0;

	return 0.0;
}

int CheckForMaxIntValue(string settingName)
{
	if(settingName=="DEATHRATE") return 130;
	if(settingName=="SALARY_MULTIPLIER") return 30;		// LDH up from 15 - 16Apr09
	if(settingName=="NO_THEFT") return 60;
	if(settingName=="LOCK_OPEN") return 70;
	if(settingName=="BLOCKDAMAGE") return 100;//MAXIMUS: 100 is a temporal value, because I don't know a real max. value for it. Maybe we can use it something like: damage+makeint(BLOCKDAMAGE*sti(npchar.luck)*RandMult(1.0))?

	return 0;
}

int CheckForMinIntValue(string settingName)
{
	if(settingName=="DEATHRATE") return 1;
	if(settingName=="SALARY_MULTIPLIER") return 1;
	if(settingName=="NO_THEFT") return 0;
	if(settingName=="LOCK_OPEN") return 0;
	if(settingName=="BLOCKDAMAGE") return 0;

	return 0;
}

string GetOptionType(string settingName)
{
	if(CheckAttribute(PlayerProfile,"BuildSettings."+settingName))
	{
		string tmpStr = GameInterface.BuildSettings.(settingName);
		if(HasSubStr(tmpStr,".") && !IsAlefBet(tmpStr)) return "float";
		if(IsAlefBet(tmpStr)) return "string";
		if(!IsAlefBet(tmpStr)) return "int";
	}
	return "";
}

bool IsAlefBet(string settingName)
{
	if(GetModelIndex(settingName)!=-1)
	{
		if(CheckAttribute(&Models[GetModelIndex(settingName)],"skipcheck") && Models[GetModelIndex(settingName)].skipcheck==true) { return true; }
	}
	int n,nLen;
	string str;

	nLen = strlen(settingName);
	if(nLen==0) { return true; }

	for(n=0; n<nLen; n++)
	{
		str = GetSymbol(&settingName,n);
		if(str=="0") { return false; }
		if(str=="1") { return false; }
		if(str=="2") { return false; }
		if(str=="3") { return false; }
		if(str=="4") { return false; }
		if(str=="5") { return false; }
		if(str=="6") { return false; }
		if(str=="7") { return false; }
		if(str=="8") { return false; }
		if(str=="9") { return false; }
	}
	return true;
}

string GetSettingsName(int settingNum)
{
	string tmpstr = "setting"+settingNum;
	if(CheckAttribute(&GameInterface,"settingslist."+tmpstr))
	{
		return GameInterface.settingslist.(tmpstr);
	}
	return "";
}
//==========================================| BuildSetting Section end |==========================================//
// added by MAXIMUS <--

// added by KAM -->
void KAM_DisplayDifficulty()
{
	switch(GetDifficulty())
	{
	case 1:		CreateImage("DiffLevelPic","icons","complete",532,155,564,185);		SetSelectable("B_DIFFICULTY1",false);		break;
	case 2:		CreateImage("DiffLevelPic","icons","complete",532,189,564,219);		SetSelectable("B_DIFFICULTY2",false);		break;
	case 3:		CreateImage("DiffLevelPic","icons","complete",532,223,564,253);		SetSelectable("B_DIFFICULTY3",false);		break;
	case 4:		CreateImage("DiffLevelPic","icons","complete",532,257,564,287);		SetSelectable("B_DIFFICULTY4",false);		break;
	}
}

void KAM_ChangeNotification()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	ref PChar = GetMainCharacter();
	string PCharName;
	if (CheckAttribute(&PChar,"firstname"))
	{
		if(CheckAttribute(PChar,"firstname")) PCharName = PChar.firstname;
		else PCharName = XI_ConvertString("Player");
	}
	else
	{
		if(CheckAttribute(PChar,"name")) PCharName = PChar.name;
		else PCharName = XI_ConvertString("Player");
	}

	if (GetShipCap() == true)
	{
		SetShipCap(false);
		GameInterface.strings.NotificationState = PCharName + " " + LanguageConvertString(tmpLangFileID,"will be notified of all sightings") + ".";
		SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"B_NOTIFICATION",0,"#"+GameInterface.strings.NotificationState);
	}
	else
	{
		SetShipCap(true);
		GameInterface.strings.NotificationState = PCharName + " " + LanguageConvertString(tmpLangFileID,"won't be notified of too-powerful sightings") + ".";
		SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"B_NOTIFICATION",0,"#"+GameInterface.strings.NotificationState);
	}
	LanguageCloseFile(tmpLangFileID);
}

void KAM_DisplayNotification()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	ref PChar = GetMainCharacter();
	string PCharName;
	if (CheckAttribute(&PChar,"firstname"))
	{
		if(CheckAttribute(PChar,"firstname")) PCharName = PChar.firstname;
		else PCharName = XI_ConvertString("Player");
	}
	else
	{
		if(CheckAttribute(PChar,"name")) PCharName = PChar.name;
		else PCharName = XI_ConvertString("Player");
	}

	if (GetShipCap() == true)
	{
		GameInterface.strings.NotificationState = PCharName + " " + LanguageConvertString(tmpLangFileID,"won't be notified of too-powerful sightings") + ".";
		SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"B_NOTIFICATION",0,"#"+GameInterface.strings.NotificationState);
	}
	else
	{
		GameInterface.strings.NotificationState = PCharName + " " + LanguageConvertString(tmpLangFileID,"will be notified of all sightings") + ".";
		SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"B_NOTIFICATION",0,"#"+GameInterface.strings.NotificationState);
	}
	LanguageCloseFile(tmpLangFileID);
}

void KAM_ChangeSailingIconsSetting()
{
	KAM_SetSailingIconsState(!KAM_GetSailingIconsState());
	KAM_DisplaySailingIconsSetting();
}

void KAM_DisplaySailingIconsSetting()
{
	if (KAM_GetSailingIconsState())
	{
		CreateImage("SailingIconsSettingPic","icons","complete",532,324,564,356);
	}
	else
	{
		GameInterface.pictures.SailingIconsSettingPic.pic = -1;
		GameInterface.pictures.SailingIconsSettingPic.tex = -1;
	}
}
// <-- added by KAM
void DoMusicSchemeChangeLeft()
{
	while (true)
	{
		music_scheme--;
		if (music_scheme < 0) music_scheme = 5;
		if (music_scheme < 0) music_scheme = GetMusicSchemeCount()-1;
		if (music_scheme == 0 || CheckDirectory(GetResourceDirectory() + "Sounds\MUSIC\" + GetMusicSchemeResDir(), "*.ogg") > 0) break;
	}
	GameInterface.Strings.MusicScheme = GetMusicSchemeName(music_scheme);
}

void DoMusicSchemeChangeRight()
{
	while (true)
	{
		music_scheme++;
		if (music_scheme > 5) music_scheme = 0;
		if (music_scheme >= GetMusicSchemeCount()) music_scheme = 0;
		if (music_scheme == 0 || CheckDirectory(GetResourceDirectory() + "Sounds\MUSIC\" + GetMusicSchemeResDir(), "*.ogg") > 0) break;
	}
	GameInterface.Strings.MusicScheme = GetMusicSchemeName(music_scheme);
}

void ProcessLanguageLeft()
{
	while (true) {
		iSelectedInterfaceLanguage--;
		if (iSelectedInterfaceLanguage < 0) {
			iSelectedInterfaceLanguage = MAX_LANGUAGES - 1;
			break;
		}
		if (FindLocalLanguage(GetInterfaceLanguageName(iSelectedInterfaceLanguage))) break;
	}
	GameInterface.strings.LanguagesList = XI_ConvertString("Int" + GetInterfaceLanguageName(iSelectedInterfaceLanguage));
}

void ProcessLanguageRight()
{
// KK -->
	// We _need_ to cycle through even unavailable languages; otherwise we won't be able to select an existing one if they're translated in "correct" order - a "gap" in translated texts.
	while (GetInterfaceLanguageName(iSelectedInterfaceLanguage + 1) != "English")
	{
		/*if (GetInterfaceLanguageName(iSelectedInterfaceLanguage) == "English")
			iSelectedInterfaceLanguage++;*/
		iSelectedInterfaceLanguage++;
		if (iSelectedInterfaceLanguage >= MAX_LANGUAGES)
		{
			iSelectedInterfaceLanguage = 0;
			break;
		}
		if (FindLocalLanguage(GetInterfaceLanguageName(iSelectedInterfaceLanguage)))
		{
			break;
		}
	}
	// MAXIMUS: changed it, because we don't need changer for nonexistent translation and interfaces. Only presented languages will be shown
	/*if (LanguageQty == 0 || GetInterfaceLanguageName(iSelectedInterfaceLanguage + 1) != "English") if(FindLocalLanguage(GetInterfaceLanguageName(iSelectedInterfaceLanguage + 1))) { iSelectedInterfaceLanguage++; }*/
// <-- KK
	GameInterface.strings.LanguagesList = XI_ConvertString("Int" + GetInterfaceLanguageName(iSelectedInterfaceLanguage));
}

void ProcessKeyboardLayoutLeft()
{
	iSelectedKeyboardLayout--;
	if (iSelectedKeyboardLayout < 0) iSelectedKeyboardLayout = 0;
	GameInterface.strings.KeyboardLayoutList = XI_ConvertString("Int" + GetInterfaceLanguageName(iSelectedKeyboardLayout));
}

void ProcessKeyboardLayoutRight()
{
	if (GetInterfaceLanguageName(iSelectedKeyboardLayout + 1) != "English" && iSelectedKeyboardLayout < MAX_KEYBOARD_LAYOUTS) iSelectedKeyboardLayout++;
	GameInterface.strings.KeyboardLayoutList = XI_ConvertString("Int" + GetInterfaceLanguageName(iSelectedKeyboardLayout));
}
// <-- KK

// added by MAXIMUS [for correct buttons selection] -->
void LeftProcess()
{
	string tmp = NextLeft(GetCurrentNode());
	SetCurrentNode(tmp);
}

void RightProcess()
{
	string tmp = NextRight(GetCurrentNode());
	SetCurrentNode(tmp);
}

string NextLeft(string curNod)
{
	switch(curNod)
	{
	case "B_NEWINTERFACE":
		if(GetSelectable("B_ADDITIONAL")==true)	return "B_ADDITIONAL";
		else return NextLeft("B_ADDITIONAL");
		break;
	case "B_NEWICONS":
		if(GetSelectable("B_NEWINTERFACE")==true) return "B_NEWINTERFACE";
		else return NextLeft("B_NEWINTERFACE");
		break;
	case "B_OLDINTERFACE":
		if(GetSelectable("B_NEWICONS")==true)	return "B_NEWICONS";
		else return NextLeft("B_NEWICONS");
		break;
	case "B_OLDICONS":
		if(GetSelectable("B_OLDINTERFACE")==true) return "B_OLDINTERFACE";
		else return NextLeft("B_OLDINTERFACE");
		break;
	case "B_LANGUAGES":
		if(GetSelectable("B_OLDICONS")==true) return "B_OLDICONS";
		else return NextLeft("B_OLDICONS");
		break;
	case "B_ANION":
		if(GetSelectable("B_LANGUAGES")==true)	return "B_LANGUAGES";
		else return NextLeft("B_LANGUAGES");
		break;
	case "B_ANIOFF":
		if(GetSelectable("B_ANION")==true) return "B_ANION";
		else return NextLeft("B_ANION");
		break;
	case "B_ADDITIONAL":
		if(GetSelectable("B_ANIOFF")==true) return "B_ANIOFF";
		else return NextLeft("B_ANIOFF");
		break;
	}
	return " ";
}

string NextRight(string curNod)
{
	switch(curNod)
	{
	case "B_NEWINTERFACE":
		if(GetSelectable("B_NEWICONS")==true) return "B_NEWICONS";
		else return NextRight("B_NEWICONS");
		break;
	case "B_NEWICONS":
		if(GetSelectable("B_OLDINTERFACE")==true) return "B_OLDINTERFACE";
		else return NextRight("B_OLDINTERFACE");
		break;
	case "B_OLDINTERFACE":
		if(GetSelectable("B_OLDICONS")==true) return "B_OLDICONS";
		else return NextRight("B_OLDICONS");
		break;
	case "B_OLDICONS":
		if(GetSelectable("B_LANGUAGES")==true) return "B_LANGUAGES";
		else return NextRight("B_LANGUAGES");
		break;
	case "B_LANGUAGES":
		if(GetSelectable("B_ANION")==true) return "B_ANION";
		else return NextRight("B_ANION");
		break;
	case "B_ANION":
		if(GetSelectable("B_ANIOFF")==true)	return "B_ANIOFF";
		else return NextRight("B_ANIOFF");
		break;
	case "B_ANIOFF":
		if(GetSelectable("B_ADDITIONAL")==true) return "B_ADDITIONAL";
		else return NextRight("B_ADDITIONAL");
		break;
	case "B_ADDITIONAL":
		if(GetSelectable("B_NEWINTERFACE")==true) return "B_NEWINTERFACE";
		else return NextRight("B_NEWINTERFACE");
		break;
	}
	return " ";
}

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
	case "B_NEWINTERFACE":
		if(GetSelectable("B_ADDITIONAL")==true) return "B_ADDITIONAL";
		else return NextUp("B_ADDITIONAL");
		break;
	case "B_OLDINTERFACE":
		if(GetSelectable("B_NEWINTERFACE")==true)	return "B_NEWINTERFACE";
		else return NextUp("B_NEWINTERFACE");
		break;
	case "B_ANION":
		if(GetSelectable("B_OLDINTERFACE")==true)	return "B_OLDINTERFACE";
		else return NextUp("B_OLDINTERFACE");
		break;
	case "B_LANGUAGES":
		if(GetSelectable("B_ANION")==true) return "B_ANION";
		else return NextUp("B_ANION");
		break;
	case "B_ANIOFF":
		if(GetSelectable("B_LANGUAGES")==true) return "B_LANGUAGES";
		else return NextUp("B_LANGUAGES");
		break;
	case "B_NEWICONS":
		if(GetSelectable("B_ANIOFF")==true) return "B_ANIOFF";
		else return NextUp("B_ANIOFF");
		break;
	case "B_OLDICONS":
		if(GetSelectable("B_NEWICONS")==true) return "B_NEWICONS";
		else return NextUp("B_NEWICONS");
		break;
	case "B_ADDITIONAL":
		if(GetSelectable("B_OLDICONS")==true) return "B_OLDICONS";
		else return NextUp("B_OLDICONS");
		break;
	// PB: Realism Settings menu cleaned up and clarified -->
	case "REALISMMODE_0":
		if(GetSelectable("REALBATTLE_2")==true) return "REALBATTLE_2";
		else return NextUp("REALBATTLE_2");
		break;
	case "REALISMMODE_1":
		if(GetSelectable("REALISMMODE_0")==true) return "REALISMMODE_0";
		else return NextUp("REALISMMODE_0");
		break;
	case "REALISMMODE_2":
		if(GetSelectable("REALISMMODE_1")==true) return "REALISMMODE_1";
		else return NextUp("REALISMMODE_1");
		break;
	case "REALBATTLE_1":
		if(GetSelectable("REALISMMODE_2")==true) return "REALISMMODE_2";
		else return NextUp("REALISMMODE_2");
		break;
	case "REALBATTLE_2":
		if(GetSelectable("REALBATTLE_1")==true) return "REALBATTLE_1";
		else return NextUp("REALBATTLE_1");
		break;
	// PB: Realism Settings menu cleaned up and clarified <--
	/*case "B_ENGLISH":
		if(GetSelectable("B_POLISH")==true) return "B_POLISH"; // KK
		else return NextUp("B_POLISH");
		break;
	case "B_RUSSIAN":
		if(GetSelectable("B_ENGLISH")==true) return "B_ENGLISH"; // KK
		else return NextUp("B_ENGLISH");
		break;
	case "B_FRENCH":
		if(GetSelectable("B_RUSSIAN")==true) return "B_RUSSIAN";
		else return NextUp("B_RUSSIAN");
		break;
	case "B_GERMAN":
		if(GetSelectable("B_FRENCH")==true) return "B_FRENCH";
		else return NextUp("B_FRENCH");
		break;
	case "B_SPANISH":
		if(GetSelectable("B_GERMAN")==true) return "B_GERMAN";
		else return NextUp("B_GERMAN");
		break;
	case "B_POLISH": // KK
		if(GetSelectable("B_SPANISH")==true) return "B_SPANISH";
		else return NextUp("B_SPANISH");
		break;*/
	case "MB_VIDEO":
		if(GetSelectable("MB_BUILDSETTINGS")==true) return "MB_BUILDSETTINGS";
		else return NextUp("MB_BUILDSETTINGS");
		break;
	case "MB_SAILING":
		if(GetSelectable("MB_VIDEO")==true) return "MB_VIDEO";
		else return NextUp("MB_VIDEO");
		break;
	case "MB_SOUNDS":
		if(GetSelectable("MB_SAILING")==true) return "MB_SAILING";
		else return NextUp("MB_SAILING");
		break;
	case "MB_CAMERA":
		if(GetSelectable("MB_SOUNDS")==true) return "MB_SOUNDS";
		else return NextUp("MB_SOUNDS");
		break;
	case "MB_CONTROLS":
		if(GetSelectable("MB_CAMERA")==true) return "MB_CAMERA";
		else return NextUp("MB_CAMERA");
		break;
	case "MB_GAMEOPTION":
		if(GetSelectable("MB_CONTROLS")==true) return "MB_CONTROLS";
		else return NextUp("MB_CONTROLS");
		break;
	case "MB_DIFFICULTY":
		if(GetSelectable("MB_GAMEOPTION")==true) return "MB_GAMEOPTION";
		else return NextUp("MB_GAMEOPTION");
		break;
	case "MB_BUILDSETTINGS":
		if(GetSelectable("MB_DIFFICULTY")==true) return "MB_DIFFICULTY";
		else return NextUp("MB_DIFFICULTY");
		break;
	case "SETTINGS_WINDOW":
		if(GetSelectable("SETTINGS_WINDOW")==true) return "SETTINGS_WINDOW";
		else return NextUp("SETTINGS_WINDOW");
		break;
	case "SETTINGS_DEFAULT_BUTTON":
		if(GetSelectable("SETTINGS_WINDOW")==true) return "SETTINGS_WINDOW";
		else return NextUp("SETTINGS_WINDOW");
		break;
	case "SETTINGSMODELSLIST":
		if(GetSelectable(oldCurNode)==true) return oldCurNode;
		else return NextUp(oldCurNode);
		break;
	case "SETTINGSSHIPSLIST":
		if(GetSelectable(oldCurNode)==true) return oldCurNode;
		else return NextUp(oldCurNode);
		break;
	case "SETTINGS_CANCEL_BUTTON":
		oldCurNode = GetCurrentNode();
		switch(GameInterface.Buildsettings.tempData)
		{
			case "new_model":
				if(GetSelectable("SETTINGSMODELSLIST")==true) return "SETTINGSMODELSLIST";
				else return NextUp("SETTINGSMODELSLIST");
			break;

			case "new_ship":
				if(GetSelectable("SETTINGSSHIPSLIST")==true) return "SETTINGSSHIPSLIST";
				else return NextUp("SETTINGSSHIPSLIST");
			break;
		}
		if(GetSelectable("VALUE_CHANGER")) return "VALUE_CHANGER";
		else return NextUp("VALUE_CHANGER");
		break;
	case "SETTINGS_OK_BUTTON":
		oldCurNode = GetCurrentNode();
		switch(GameInterface.Buildsettings.tempData)
		{
			case "new_model":
				if(GetSelectable("SETTINGSMODELSLIST")==true) return "SETTINGSMODELSLIST";
				else return NextUp("SETTINGSMODELSLIST");
			break;

			case "new_ship":
				if(GetSelectable("SETTINGSSHIPSLIST")==true) return "SETTINGSSHIPSLIST";
				else return NextUp("SETTINGSSHIPSLIST");
			break;
		}
		if(GetSelectable("VALUE_CHANGER")) return "VALUE_CHANGER";
		else return NextUp("VALUE_CHANGER");
		break;
	case "VALUE_CHANGER":
		if(GetSelectable(oldCurNode)==true) return oldCurNode;
		else return NextUp(oldCurNode);
		break;
	case "B_DIFFICULTY1":
		if(GetSelectable("B_NOTIFICATION")==true) return "B_NOTIFICATION";
		else return NextUp("B_NOTIFICATION");
		break;
	case "B_DIFFICULTY2":
		if(GetSelectable("B_DIFFICULTY1")==true) return "B_DIFFICULTY1";
		else return NextUp("B_DIFFICULTY1");
		break;
	case "B_DIFFICULTY3":
		if(GetSelectable("B_DIFFICULTY2")==true) return "B_DIFFICULTY2";
		else return NextUp("B_DIFFICULTY2");
		break;
	case "B_DIFFICULTY4":
		if(GetSelectable("B_DIFFICULTY3")==true) return "B_DIFFICULTY3";
		else return NextUp("B_DIFFICULTY3");
		break;
	case "B_NOTIFICATION":
		if(GetSelectable("B_DIFFICULTY4")==true) return "B_DIFFICULTY4";
		else return NextUp("B_DIFFICULTY4");
		break;
	}
	return " ";
}

string NextDown(string curNod)
{
	switch(curNod)
	{
	case "B_NEWINTERFACE":
		if(GetSelectable("B_OLDINTERFACE")==true) return "B_OLDINTERFACE";
		else return NextDown("B_OLDINTERFACE");
		break;
	case "B_OLDINTERFACE":
		if(GetSelectable("B_ANION")==true)	return "B_ANION";
		else return NextDown("B_ANION");
		break;
	case "B_ANION":
		if(GetSelectable("B_LANGUAGES")==true)	return "B_LANGUAGES";
		else return NextDown("B_LANGUAGES");
		break;
	case "B_LANGUAGES":
		if(GetSelectable("B_ANIOFF")==true) return "B_ANIOFF";
		else return NextDown("B_ANIOFF");
		break;
	case "B_ANIOFF":
		if(GetSelectable("B_NEWICONS")==true) return "B_NEWICONS";
		else return NextDown("B_NEWICONS");
		break;
	case "B_NEWICONS":
		if(GetSelectable("B_OLDICONS")==true) return "B_OLDICONS";
		else return NextDown("B_OLDICONS");
		break;
	case "B_OLDICONS":
		if(GetSelectable("B_ADDITIONAL")==true) return "B_ADDITIONAL";
		else return NextDown("B_ADDITIONAL");
		break;
	case "B_ADDITIONAL":
		if(GetSelectable("B_NEWINTERFACE")==true) return "B_NEWINTERFACE";
		else return NextDown("B_NEWINTERFACE");
		break;
	// PB: Realism Settings menu cleaned up and clarified -->
	case "REALISMMODE_0":
		if(GetSelectable("REALISMMODE_1")==true) return "REALISMMODE_1";
		else return NextDown("REALISMMODE_1");
		break;
	case "REALISMMODE_1":
		if(GetSelectable("REALISMMODE_2")==true) return "REALISMMODE_2";
		else return NextDown("REALISMMODE_2");
		break;
	case "REALISMMODE_2":
		if(GetSelectable("REALBATTLE_1")==true) return "REALBATTLE_1";
		else return NextDown("REALBATTLE_1");
		break;
	case "REALBATTLE_1":
		if(GetSelectable("REALBATTLE_2")==true) return "REALBATTLE_2";
		else return NextDown("REALBATTLE_2");
		break;
	case "REALBATTLE_2":
		if(GetSelectable("REALISMMODE_0")==true) return "REALISMMODE_0";
		else return NextDown("REALISMMODE_0");
		break;
	// PB: Realism Settings menu cleaned up and clarified <--
	/*case "B_ENGLISH":
		if(GetSelectable("B_RUSSIAN")==true) return "B_RUSSIAN";
		else return NextDown("B_RUSSIAN");
		break;
	case "B_RUSSIAN":
		if(GetSelectable("B_FRENCH")==true) return "B_FRENCH";
		else return NextDown("B_FRENCH");
		break;
	case "B_FRENCH":
		if(GetSelectable("B_GERMAN")==true) return "B_GERMAN";
		else return NextDown("B_GERMAN");
		break;
	case "B_GERMAN":
		if(GetSelectable("B_SPANISH")==true) return "B_SPANISH";
		else return NextDown("B_SPANISH");
		break;
	case "B_SPANISH":
		if(GetSelectable("B_POLISH")==true) return "B_POLISH";
		else return NextDown("B_POLISH");
		break;
	case "B_POLISH": // KK
		if(GetSelectable("B_ENGLISH")==true) return "B_ENGLISH";
		else return NextDown("B_ENGLISH");
		break;*/
	case "MB_VIDEO":
		if(GetSelectable("MB_SAILING")==true) return "MB_SAILING";
		else return NextDown("MB_SAILING");
		break;
	case "MB_SAILING":
		if(GetSelectable("MB_SOUNDS")==true) return "MB_SOUNDS";
		else return NextDown("MB_SOUNDS");
		break;
	case "MB_SOUNDS":
		if(GetSelectable("MB_CAMERA")==true) return "MB_CAMERA";
		else return NextDown("MB_CAMERA");
		break;
	case "MB_CAMERA":
		if(GetSelectable("MB_CONTROLS")==true) return "MB_CONTROLS";
		else return NextDown("MB_CONTROLS");
		break;
	case "MB_CONTROLS":
		if(GetSelectable("MB_GAMEOPTION")==true) return "MB_GAMEOPTION";
		else return NextDown("MB_GAMEOPTION");
		break;
	case "MB_GAMEOPTION":
		if(GetSelectable("MB_DIFFICULTY")==true) return "MB_DIFFICULTY";
		else return NextDown("MB_DIFFICULTY");
		break;
	case "MB_DIFFICULTY":
		if(GetSelectable("MB_BUILDSETTINGS")==true) return "MB_BUILDSETTINGS";
		else return NextDown("MB_BUILDSETTINGS");
		break;
	case "MB_BUILDSETTINGS":
		if(GetSelectable("MB_VIDEO")==true) return "MB_VIDEO";
		else return NextDown("MB_VIDEO");
		break;
	case "SETTINGS_WINDOW":
		if(GetSelectable("SETTINGS_WINDOW")==true) return "SETTINGS_WINDOW";
		else return NextDown("SETTINGS_WINDOW");
		break;
	case "SETTINGS_DEFAULT_BUTTON":
		if(GetSelectable("SETTINGS_WINDOW")==true) return "SETTINGS_WINDOW";
		else return NextDown("SETTINGS_WINDOW");
		break;
	case "SETTINGSMODELSLIST":
		if(GetSelectable(oldCurNode)==true) return oldCurNode;
		else return NextDown(oldCurNode);
		break;
	case "SETTINGSSHIPSLIST":
		if(GetSelectable(oldCurNode)==true) return oldCurNode;
		else return NextDown(oldCurNode);
		break;
	case "SETTINGS_CANCEL_BUTTON":
		oldCurNode = GetCurrentNode();
		switch(GameInterface.Buildsettings.tempData)
		{
			case "new_model":
				if(GetSelectable("SETTINGSMODELSLIST")==true) return "SETTINGSMODELSLIST";
				else return NextDown("SETTINGSMODELSLIST");
			break;

			case "new_ship":
				if(GetSelectable("SETTINGSSHIPSLIST")==true) return "SETTINGSSHIPSLIST";
				else return NextDown("SETTINGSSHIPSLIST");
			break;
		}
		if(GetSelectable("VALUE_CHANGER")) return "VALUE_CHANGER";
		else return NextDown("VALUE_CHANGER");
		break;
	case "SETTINGS_OK_BUTTON":
		oldCurNode = GetCurrentNode();
		switch(GameInterface.Buildsettings.tempData)
		{
			case "new_model":
				if(GetSelectable("SETTINGSMODELSLIST")==true) return "SETTINGSMODELSLIST";
				else return NextDown("SETTINGSMODELSLIST");
			break;

			case "new_ship":
				if(GetSelectable("SETTINGSSHIPSLIST")==true) return "SETTINGSSHIPSLIST";
				else return NextDown("SETTINGSSHIPSLIST");
			break;
		}
		if(GetSelectable("VALUE_CHANGER")) return "VALUE_CHANGER";
		else return NextDown("VALUE_CHANGER");
		break;
	case "VALUE_CHANGER":
		if(GetSelectable(oldCurNode)==true) return oldCurNode;
		else return NextDown(oldCurNode);
		break;
	case "B_DIFFICULTY1":
		if(GetSelectable("B_DIFFICULTY2")) return "B_DIFFICULTY2";
		else return NextDown("B_DIFFICULTY2");
		break;
	case "B_DIFFICULTY2":
		if(GetSelectable("B_DIFFICULTY3")) return "B_DIFFICULTY3";
		else return NextDown("B_DIFFICULTY3");
		break;
	case "B_DIFFICULTY3":
		if(GetSelectable("B_DIFFICULTY4")) return "B_DIFFICULTY4";
		else return NextDown("B_DIFFICULTY4");
		break;
	case "B_DIFFICULTY4":
		if(GetSelectable("B_NOTIFICATION")) return "B_NOTIFICATION";
		else return NextDown("B_NOTIFICATION");
		break;
	case "B_NOTIFICATION":
		if(GetSelectable("B_DIFFICULTY1")) return "B_DIFFICULTY1";
		else return NextDown("B_DIFFICULTY1");
		break;
	}
	return " ";
}
// added by MAXIMUS [for correct buttons selection] <--
