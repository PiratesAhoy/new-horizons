int GENERAL_GAME = 0;
int GRAPHICAL = 0;
int DIFFICULTY = 0;
int REALISM_CHARACTER = 0;
int REALISM_INTERFACE = 0;
int REALISM_SEA = 0;

// KK -->
void InitGlobalOptions()
{
	object opt;
	ref gopt; makeref(gopt, opt);
	PrepareDefaultOption(&gopt, true);
	GetRealOptions(&gopt, true);
	WriteMainOptions(gopt);
}

void SaveGlobalOptions()
{
	// Screwface
	int idx = FindCurrentStoryline();
	CurrentStoryline = idx;
	string storyline = GetStoryline(CurrentStoryline);
	CurrentProfile = GetCurrentProfile(storyline);
	//stringlen = Globalsettings.profile.(storyline).len; //strlen(CurrentProfile);
	LoadGlobalOptions();
	ref gopt; makeref(gopt, GlobalSettings);
	ReadMainOptions(&gopt);
	gopt.Storyline = CurrentStoryline;
	gopt.profile.(storyline) = CurrentProfile;
	//gopt.profile.(storyline).len = stringlen;
	gopt.end = 1;
	WriteMainOptions(gopt);
}

void LoadGlobalOptions()
{
	object opt;
	ref gopt; makeref(gopt, opt);
	ref rGlobal; makeref(rGlobal, GlobalSettings);
	PrepareDefaultOption(&gopt, true);
	ReadMainOptions(&gopt);
	SetCurentOptions(&gopt, true);
	DeleteAttribute(rGlobal, "");
	CopyAttributes(rGlobal, gopt);
}

void InitProfileOptions()
{
	ref rProfile; makeref(rProfile, ProfileSettings);
	ref rGlobal; makeref(rGlobal, GlobalSettings);
	DeleteAttribute(rProfile, "");
	CopyAttributes(rProfile, rGlobal);
	DeleteAttribute(rProfile, "Storyline");
	DeleteAttribute(rProfile, "profiles");
	WriteProfileOptions(rProfile);
}

void SaveProfileOptions()
{
	int slidx = FindCurrentStoryline();
	string optionsPath = "SAVE\" + GetStorylineDir(slidx);
	string optionsFile = GetCurrentProfile(GetStoryline(FindCurrentStoryline())) + "_options";
	if (FindFile(optionsPath, "*.*", optionsFile) != "") DeleteFile(optionsPath, optionsFile);
	InitProfileOptions();
}

void LoadProfileOptions()
{
	object opt;
	ref gopt; makeref(gopt, opt);
	ref rProfile; makeref(rProfile, ProfileSettings);
	PrepareDefaultOption(&gopt, false);
	ReadProfileOptions(&gopt);
	SetCurentOptions(&gopt, false);
	DeleteAttribute(rProfile, "");
	CopyAttributes(rProfile, gopt);
}

bool CheckGlobalOption(string name)
{
	ref rGlobal; makeref(rGlobal, GlobalSettings);
	return CheckAttribute(rGlobal, name);
}

string GetGlobalOption(string name)
{
	ref rGlobal; makeref(rGlobal, GlobalSettings);
	if (CheckAttribute(rGlobal, name)) return rGlobal.(name);
	return "";
}

bool CheckProfileOption(string name)
{
	ref rProfile; makeref(rProfile, ProfileSettings);
	return CheckAttribute(rProfile, name);
}

string GetProfileOption(string name)
{
	ref rProfile; makeref(rProfile, ProfileSettings);
	if (CheckAttribute(rProfile, name)) return rProfile.(name);
	return "";
}
// <-- KK

void PrepareDefaultOption(ref optref, bool bGlobal)
{
	optref.volume.music = 0.5;
	optref.volume.sound = 0.5;
	optref.volume.dialog = 0.5;
	optref.gameoption.musicscheme = 0; // KK
	optref.cameramode.follow_on = true;
	optref.arcademode.realism_mode = 1; // SWS: On by default for Willemstad Builder's Trials
// added by MAXIMUS -->
	optref.gameoption.newinterface_on = true; // PB: Brown interface as Build 14 Default
	optref.gameoption.newicons_on = true;

// KK -->
	optref.gameoption.langinterface = ILANG_ENG;
	optref.gameoption.keyboardlayout = ILANG_ENG;
	/*optref.gameoption.interfacerus_on = false;
	optref.gameoption.interfacefra_on = false;
	optref.gameoption.interfaceger_on = false;
	optref.gameoption.interfacespa_on = false;
	optref.gameoption.interfacepol_on = false;*/
// <-- KK

	optref.gameoption.animation_on = true;
	optref.gameoption.btlinterface_on = false;// ccc
	GetBuildSettingsData(optref, bGlobal);
// added by MAXIMUS <--
}

void GetRealOptions(ref optref, bool bGlobal)
{
	float ftmp1,ftmp2,ftmp3;

	ftmp1 = stf(optref.volume.sound);
	ftmp2 = stf(optref.volume.music);
	ftmp3 = stf(optref.volume.dialog);
	SendMessage(&sound,"leee", MSG_SOUND_GET_MASTER_VOLUME, &ftmp1, &ftmp2,	&ftmp3 );
	optref.volume.sound = ftmp1;
	optref.volume.music = ftmp2;
	optref.volume.dialog = ftmp3;
	optref.gameoption.musicscheme = music_scheme; // KK
	UpdateSound(); // KK

// added by MAXIMUS -->
	optref.gameoption.newinterface_on = bNewInterface;
	optref.gameoption.newicons_on = bNewIcons;

// KK -->
	optref.gameoption.langinterface = GetInterfaceLanguage();
	optref.gameoption.keyboardlayout = GetKeyboardLayout();
	/*optref.gameoption.interfacerus_on = bInterfaceRus;
	optref.gameoption.interfacefra_on = bInterfaceFra;
	optref.gameoption.interfaceger_on = bInterfaceGer;
	optref.gameoption.interfacespa_on = bInterfaceSpa;
	optref.gameoption.interfacepol_on = bInterfacePol;*/
// <-- KK

	optref.gameoption.animation_on = bAnimation;
	GetBuildSettingsData(optref, bGlobal);
// added by MAXIMUS <--
	optref.gameoption.btlinterface_on = bRealBattleInterface;// ccc

	optref.arcademode.realism_mode = iRealismMode;

	optref.cameramode.follow_on = !locCameraEnableSpecialMode;

	if( CheckAttribute(&InterfaceStates,"InvertCameras") ) {
		optref.cameramode.InvertCameras = sti(InterfaceStates.InvertCameras);
	} else {
		optref.cameramode.InvertCameras = false;
	}

	GetControlsOptions(optref);

	// mouse
	if( CheckAttribute(&InterfaceStates,"mouse.x_sens") ) {
		optref.mouse.x_sensitivity = InterfaceStates.mouse.x_sens;
	} else {
		optref.mouse.x_sensitivity = 0.5;
	}
	if( CheckAttribute(&InterfaceStates,"mouse.y_sens") ) {
		optref.mouse.y_sensitivity = InterfaceStates.mouse.y_sens;
	} else {
		optref.mouse.y_sensitivity = 0.5;
	}
	// video colors
	if( CheckAttribute(&InterfaceStates,"video.contrast") ) {
		optref.video.contrast = InterfaceStates.video.contrast;
	} else {
		optref.video.contrast = 1.0;
	}
	if( CheckAttribute(&InterfaceStates,"video.gamma") ) {
		optref.video.gamma = InterfaceStates.video.gamma;
	} else {
		optref.video.gamma = 1.0;
	}
	if( CheckAttribute(&InterfaceStates,"video.brightness") ) {
		optref.video.brightness = stf(InterfaceStates.video.brightness); // LDH - eliminate garbage at end of options file
	} else {
		optref.video.brightness = 0.0;
	}
}

void SetCurentOptions(ref optref, bool bGlobal)
{
// changed by MAXIMUS -->
	float ftmp1,ftmp2,ftmp3;

	ftmp1 = stf(optref.volume.sound);
	ftmp2 = stf(optref.volume.music);
	ftmp3 = stf(optref.volume.dialog);
	SendMessage(&sound,"lfff", MSG_SOUND_SET_MASTER_VOLUME,	&ftmp1, &ftmp2, &ftmp3);
// changed by MAXIMUS <--
// KK -->
	music_scheme = sti(optref.gameoption.musicscheme);
	if (music_scheme > 0 && CheckDirectory("RESOURCE\Sounds\MUSIC\" + GetMusicSchemeResDir(), "*.ogg") == 0) {
		music_scheme = 0;
		optref.gameoption.musicscheme = music_scheme;
		//SaveMainOptions(optref);
	}
// <-- KK

// added by MAXIMUS -->
	bNewInterface = sti(optref.gameoption.newinterface_on);
	bNewIcons = sti(optref.gameoption.newicons_on);

// KK -->
	/*bInterfaceRus = sti(optref.gameoption.interfacerus_on);
	bInterfaceFra = sti(optref.gameoption.interfacefra_on);
	bInterfaceGer = sti(optref.gameoption.interfaceger_on);
	bInterfaceSpa = sti(optref.gameoption.interfacespa_on);
	bInterfacePol = sti(optref.gameoption.interfacepol_on);*/
	SetInterfaceLanguage(sti(optref.gameoption.langinterface));
	string slname = GetInterfaceLanguageName(GetInterfaceLanguage());
	if (FindLocalLanguage(slname)) {
		LanguageSetLanguage(slname);
	} else {
		LanguageSetLanguage("English");
		iLangInterface = ILANG_ENG;
		optref.gameoption.langinterface = iLangInterface;
		//SaveMainOptions(optref);
	}
	SetKeyboardLayout(sti(optref.gameoption.keyboardlayout));
// <-- KK

	bAnimation = sti(optref.gameoption.animation_on);
	UpdateBuildSettingsData(&optref, bGlobal);
// added by MAXIMUS <--
	bRealBattleInterface = sti(optref.gameoption.btlinterface_on);// ccc

	iRealismMode = sti(optref.arcademode.realism_mode);
	locCameraEnableSpecialMode = !sti(optref.cameramode.follow_on);

	// mouse
	if( CheckAttribute(optref,"cameramode.InvertCameras") ) {
		InterfaceStates.InvertCameras = optref.cameramode.InvertCameras;
	} else {
		InterfaceStates.InvertCameras = false;
	}
	if( CheckAttribute(optref,"mouse.x_sensitivity") ) {
		InterfaceStates.mouse.x_sens = optref.mouse.x_sensitivity;
	} else {
		InterfaceStates.mouse.x_sens = 0.5;
	}
	if( CheckAttribute(optref,"mouse.y_sensitivity") ) {
		InterfaceStates.mouse.y_sens = optref.mouse.y_sensitivity;
	} else {
		InterfaceStates.mouse.y_sens = 0.5;
	}
	// video colors
	if( CheckAttribute(optref,"video.contrast") ) {
		InterfaceStates.video.contrast = optref.video.contrast;
	} else {
		InterfaceStates.video.contrast = 1.0;
	}
	if( CheckAttribute(optref,"video.gamma") ) {
		InterfaceStates.video.gamma = optref.video.gamma;
	} else {
		InterfaceStates.video.gamma = 1.0;
	}
	if( CheckAttribute(optref,"video.brightness") ) {
		InterfaceStates.video.brightness = stf(optref.video.brightness);	// LDH eliminate garbage at end of options file - 22Jan09
	} else {
		InterfaceStates.video.brightness = 0.0;
	}
	XI_SetColorCorrection(stf(InterfaceStates.video.contrast),stf(InterfaceStates.video.gamma),stf(InterfaceStates.video.brightness));

	aref arControls;
	makearef(arControls,optref.controls);
	RestoreKeysFromOptions(arControls);

	if( GetTargetPlatform()=="pc" )
	{
		ControlsMakeInvert();
		SetRealMouseSensitivity();
	}
}

// KK -->
void ReadProfileOptions(ref gopt)
{
	string optionsFile = "options";
	if (FindCurrentStoryline() != -1) {
		string optionsPath = "SAVE\" + GetStorylineDir(FindCurrentStoryline());
		if (FindFile(optionsPath, "*" , optionsFile) != "") {
			optionsFile = optionsPath + GetCurrentProfile(GetStoryline(FindCurrentStoryline())) + "_options";
		}
		SendMessage(&GameInterface, "lsa", MSG_INTERFACE_LOADOPTIONS, optionsFile, gopt);
	}
}

void ReadMainOptions(ref gopt)
{
	if (FindFile("", "*", "options") != "") SendMessage(&GameInterface, "lsa", MSG_INTERFACE_LOADOPTIONS, "options", gopt);
}

void WriteProfileOptions(ref gopt)
{
	if (FindCurrentStoryline() != -1) {
		string optionsFile = "SAVE\" + GetStorylineDir(FindCurrentStoryline()) + GetCurrentProfile(GetStoryline(FindCurrentStoryline())) + "_options";
		SendMessage(&GameInterface, "lsa", MSG_INTERFACE_SAVEOPTIONS, optionsFile, gopt);
	}
}
// <-- KK

void WriteMainOptions(ref gopt)
{
	SendMessage(&GameInterface, "lsa", MSG_INTERFACE_SAVEOPTIONS, "options", gopt);//default
}

void GetControlsOptions(ref optref)
{
	int ng,qg, nc,qc;
	aref arIn, arOut, arGrp, arCntrl;
	string grName, cntrlName;

	makearef(arOut,objControlsState.keygroups);
	optref.controls = true;
	makearef(arIn,optref.controls);

	qg = GetAttributesNum(arOut);
	for(ng=0; ng<qg; ng++)
	{
		arGrp = GetAttributeN(arOut,ng);
		grName = GetAttributeName(arGrp);
		if( CheckAttribute(&objControlsState,"grouplist."+grName) && sti(objControlsState.grouplist.(grName))==true )
		{
			qc = GetAttributesNum(arGrp);
			for(nc=0; nc<qc; nc++)
			{
				arCntrl = GetAttributeN(arGrp,nc);
				if( CheckAttribute(arCntrl,"remapping") && sti(arCntrl.remapping)==true )
				{
					cntrlName = GetAttributeName(arCntrl);
					arIn.(grName).(cntrlName) = GetAttributeValue(arCntrl);
					arIn.(grName).(cntrlName).state = arCntrl.state;
				}
			}
		}
	}
}

// MAXIMUS -->
void InitBuildOptions(bool bDefault, bool bGlobal)
{
// KK -->
	object otmp;
	ref Settings; makeref(Settings, otmp);
	if (bGlobal)
		makeref(Settings, GlobalSettings);
	else
		makeref(Settings, ProfileSettings);
// <-- KK
	if(!CheckAttribute(Settings,"BuildSettings") || bDefault)
	{
		/////////////////////////////////////////////////////////////////////
		Settings.BuildSettings.GENERAL_GAME = GENERAL_GAME;
		/////////////////////////////////////////////////////////////////////
				Settings.BuildSettings.VISIT_DECK = VISIT_DECK;
				Settings.BuildSettings.ENABLE_BUILDINGSET = ENABLE_BUILDINGSET;
				Settings.BuildSettings.ENABLE_BROTHEL = ENABLE_BROTHEL;
				Settings.BuildSettings.CORPSEMODE = 3; //MAXIMUS: by this way CORPSEMODE 3 will hidden from options-interface
				Settings.BuildSettings.AUTOLOOT_ON = AUTOLOOT_ON;


		/////////////////////////////////////////////////////////////////////
		Settings.BuildSettings.GRAPHICAL = GRAPHICAL;
		/////////////////////////////////////////////////////////////////////
				Settings.BuildSettings.LOC_CAMERA = LOC_CAMERA;
				Settings.BuildSettings.DIALOG_CAMERA = DIALOG_CAMERA;
				Settings.BuildSettings.ONSEA_COMPASS = ONSEA_COMPASS;
				Settings.BuildSettings.DEFAULT_SAILS = DEFAULT_SAILS;
				Settings.BuildSettings.PIRATES_BLACK_SAILS = PIRATES_BLACK_SAILS;


		/////////////////////////////////////////////////////////////////////
		Settings.BuildSettings.DIFFICULTY = DIFFICULTY;
		/////////////////////////////////////////////////////////////////////
				Settings.BuildSettings.DEATHRATE = DEATHRATE;
				Settings.BuildSettings.SALARY_MULTIPLIER = SALARY_MULTIPLIER;
				Settings.BuildSettings.NO_THEFT = NO_THEFT;
				Settings.BuildSettings.LOCK_OPEN = LOCK_OPEN;


		/////////////////////////////////////////////////////////////////////
		Settings.BuildSettings.REALISM_CHARACTER = REALISM_CHARACTER;
		/////////////////////////////////////////////////////////////////////
				Settings.BuildSettings.AUTO_SKILL_SYSTEM = AUTO_SKILL_SYSTEM;
				Settings.BuildSettings.ENABLE_WEAPONSMOD = ENABLE_WEAPONSMOD;
				Settings.BuildSettings.ENABLE_AMMOMOD = ENABLE_AMMOMOD;
				Settings.BuildSettings.SWEDEN_ALLOWED = SWEDEN_ALLOWED;


		/////////////////////////////////////////////////////////////////////
		Settings.BuildSettings.REALISM_INTERFACE = REALISM_INTERFACE;
		/////////////////////////////////////////////////////////////////////
				Settings.BuildSettings.IT_RPG_STYLE = IT_RPG_STYLE;
				Settings.BuildSettings.SY_RPG_STYLE = SY_RPG_STYLE;
				Settings.BuildSettings.REALISTIC_SHIP_PURCHASE = REALISTIC_SHIP_PURCHASE;
				Settings.BuildSettings.PERSUASION_TAGS = PERSUASION_TAGS;


		/////////////////////////////////////////////////////////////////////
		Settings.BuildSettings.REALISM_SEA = REALISM_SEA;
		/////////////////////////////////////////////////////////////////////
				Settings.BuildSettings.CANNONPOWDER_MOD = CANNONPOWDER_MOD;
				Settings.BuildSettings.FOOD_ON = FOOD_ON;
				Settings.BuildSettings.WDMAP_SHIP_SHOW_MODE = WDMAP_SHIP_SHOW_MODE;
				Settings.BuildSettings.NATIONAL_PAINT_SCHEMES = NATIONAL_PAINT_SCHEMES;
				Settings.BuildSettings.SAILHO_INFOLEVEL = SAILHO_INFOLEVEL;
				Settings.BuildSettings.RELATION_IGNORE_FRIENDLY = RELATION_IGNORE_FRIENDLY;

		trace("==> BuildSettings: Sets to default");
	}
	else
	{
		/////////////////////////////////////////////////////////////////////
		GENERAL_GAME = Settings.BuildSettings.GENERAL_GAME;
		/////////////////////////////////////////////////////////////////////
				VISIT_DECK = Settings.BuildSettings.VISIT_DECK;
				ENABLE_BUILDINGSET = Settings.BuildSettings.ENABLE_BUILDINGSET;
				ENABLE_BROTHEL = Settings.BuildSettings.ENABLE_BROTHEL;
				//MAXIMUS: by this way CORPSEMODE 3 is hidden from options-interface -->
				CORPSEMODE = sti(Settings.BuildSettings.CORPSEMODE);
				switch(CORPSEMODE)
				{
					case 3: CORPSEMODE = 4; break;
					case 4: CORPSEMODE = 3; break;
				}
				//MAXIMUS: by this way CORPSEMODE 3 is hidden from options-interface <--
				//=======================| ON/OFF SHOW IN CONTROLS-INTERFACE |=======================//
				objControlsState.keygroups.General.NK_DialogStart.invisible = CORPSEMODE!=2;
				objControlsState.keygroups.PrimaryLand.NK_DialogStart.invisible = CORPSEMODE!=2;
				objControlsState.keygroups.FightModeControls.NK_DialogStart.invisible = CORPSEMODE!=2;
				//=======================| ON/OFF SHOW IN CONTROLS-INTERFACE |=======================//
				AUTOLOOT_ON = Settings.BuildSettings.AUTOLOOT_ON;


		/////////////////////////////////////////////////////////////////////
		GRAPHICAL = Settings.BuildSettings.GRAPHICAL;
		/////////////////////////////////////////////////////////////////////
				LOC_CAMERA = Settings.BuildSettings.LOC_CAMERA;
				DIALOG_CAMERA = Settings.BuildSettings.DIALOG_CAMERA;
				ONSEA_COMPASS = Settings.BuildSettings.ONSEA_COMPASS;
				DEFAULT_SAILS = Settings.BuildSettings.DEFAULT_SAILS;
				PIRATES_BLACK_SAILS = Settings.BuildSettings.PIRATES_BLACK_SAILS;


		/////////////////////////////////////////////////////////////////////
		DIFFICULTY = Settings.BuildSettings.DIFFICULTY;
		/////////////////////////////////////////////////////////////////////
				DEATHRATE = Settings.BuildSettings.DEATHRATE;
				SALARY_MULTIPLIER = Settings.BuildSettings.SALARY_MULTIPLIER;
				NO_THEFT = Settings.BuildSettings.NO_THEFT;
				LOCK_OPEN = Settings.BuildSettings.LOCK_OPEN;


		/////////////////////////////////////////////////////////////////////
		REALISM_CHARACTER = Settings.BuildSettings.REALISM_CHARACTER;
		/////////////////////////////////////////////////////////////////////
				AUTO_SKILL_SYSTEM = Settings.BuildSettings.AUTO_SKILL_SYSTEM;
				ENABLE_WEAPONSMOD = Settings.BuildSettings.ENABLE_WEAPONSMOD;
				ENABLE_AMMOMOD = Settings.BuildSettings.ENABLE_AMMOMOD;
				SWEDEN_ALLOWED = Settings.BuildSettings.SWEDEN_ALLOWED;


		/////////////////////////////////////////////////////////////////////
		REALISM_INTERFACE = Settings.BuildSettings.REALISM_INTERFACE;
		/////////////////////////////////////////////////////////////////////
				IT_RPG_STYLE = Settings.BuildSettings.IT_RPG_STYLE;
				SY_RPG_STYLE = Settings.BuildSettings.SY_RPG_STYLE;
				REALISTIC_SHIP_PURCHASE = Settings.BuildSettings.REALISTIC_SHIP_PURCHASE;
				PERSUASION_TAGS = Settings.BuildSettings.PERSUASION_TAGS;


		/////////////////////////////////////////////////////////////////////
		REALISM_SEA = Settings.BuildSettings.REALISM_SEA;
		/////////////////////////////////////////////////////////////////////
				CANNONPOWDER_MOD = Settings.BuildSettings.CANNONPOWDER_MOD;
				FOOD_ON = Settings.BuildSettings.FOOD_ON;
				WDMAP_SHIP_SHOW_MODE = Settings.BuildSettings.WDMAP_SHIP_SHOW_MODE;
				NATIONAL_PAINT_SCHEMES = Settings.BuildSettings.NATIONAL_PAINT_SCHEMES;
				SAILHO_INFOLEVEL = Settings.BuildSettings.SAILHO_INFOLEVEL;
				RELATION_IGNORE_FRIENDLY = Settings.BuildSettings.RELATION_IGNORE_FRIENDLY;

		trace("==> BuildSettings: New settings applied");
	}
}

void GetBuildSettings()
{
// KK -->
	bool bGlobal = (FindCurrentStoryline() == -1);
	object otmp;
	ref Settings; makeref(Settings, otmp);
	if (bGlobal)
		makeref(Settings, GlobalSettings);
	else
		makeref(Settings, ProfileSettings);
// <-- KK
	object bopt;
	string optionsPath = "options";
	GameInterface.SavePath = "";
// KK -->
	string ProfileName = "";
	string StorylineDir = "";
	if (!bGlobal) {
		ProfileName = GetCurrentProfile(GetStoryline(FindCurrentStoryline()));
		StorylineDir = GetStorylineDir(FindCurrentStoryline());
		if (ProfileName != DEFAULT_PROFILE_NAME && FindFile("SAVE\" + StorylineDir, "*", ProfileName + "_options") != "")
		{
			GameInterface.SavePath = "SAVE\" + StorylineDir;
			optionsPath = ProfileName + "_options";
		}
	}
// <-- KK
	GetBuildSettingsData(&bopt, bGlobal);
	SendMessage(&GameInterface, "lsa", MSG_INTERFACE_LOADOPTIONS, optionsPath, &bopt);
	UpdateBuildSettingsData(&bopt, bGlobal);
}

void GetBuildSettingsData(ref optref, bool bGlobal)
{
	InitBuildOptions(false, bGlobal);
// KK -->
	object otmp;
	ref Settings; makeref(Settings, otmp);
	if (bGlobal)
		makeref(Settings, GlobalSettings);
	else
		makeref(Settings, ProfileSettings);
// <-- KK
	aref bSet; makearef(bSet, Settings.BuildSettings);
	if(CheckAttribute(optref,"Buildsettings")) DeleteAttribute(optref,"Buildsettings");
	if (CheckAttribute(optref, "Storyline")) DeleteAttribute(optref, "Storyline"); // KK
	if(CheckAttribute(optref,"Profiles")) DeleteAttribute(optref,"Profiles");

	int i; // KK
	for(i=0; i<GetAttributesNum(bSet); i++)
	{
		aref curItem = GetAttributeN(bSet, i);
		string attrName = GetAttributeName(curItem);
		optref.Buildsettings.(attrName) = Settings.Buildsettings.(attrName);
	}

// KK -->
	if (!bGlobal) return;

	if (CheckAttribute(Settings, "Storyline")) optref.Storyline = Settings.Storyline;
	int SLNum = GetStorylinesQuantity();
	for (i = 0; i < SLNum; i++)
	{
		string storyline = GetStoryline(i);
		if (CheckAttribute(Settings, storyline)) optref.Profiles.(storyline) = Settings.(storyline);
	}
// <-- KK
}

void UpdateBuildSettingsData(ref optref, bool bGlobal)
{
// KK -->
	object otmp;
	ref Settings; makeref(Settings, otmp);
	if (bGlobal)
		makeref(Settings, GlobalSettings);
	else
		makeref(Settings, ProfileSettings);
// <-- KK
	aref bSet; makearef(bSet, Settings.BuildSettings);

	for(int i=0; i<GetAttributesNum(bSet); i++)
	{
		aref curItem = GetAttributeN(bSet, i);
		string attrName = GetAttributeName(curItem);
		if(CheckAttribute(optref,"Buildsettings."+attrName)) Settings.Buildsettings.(attrName) = optref.Buildsettings.(attrName);
	}

	InitBuildOptions(false, bGlobal);
// KK -->
	if (!bGlobal) return;

	if (CheckAttribute(optref, "Storyline")) Settings.Storyline = optref.Storyline;
	int SLNum = GetStorylinesQuantity();
	for (i = 0; i < SLNum; i++)
	{
		string storyline = GetStoryline(i);
		if (CheckAttribute(optref, "profiles." + storyline)) Settings.(storyline) = optref.Profiles.(storyline);
	}
// <-- KK
}
// <-- MAXIMUS
