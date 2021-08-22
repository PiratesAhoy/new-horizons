#define MAX_SAVE_GAME_LIMIT 40 //Draksen; was 20
#define PROFILE_LIST_SIZE   10

int nCurScroll;
bool bThisSave;

aref scrshot;

bool bSaveConfirm;
bool bLoadConfirm;
bool bProfileDelete; // KK
bool bEnableNewSave;
bool bNightmareMode; // KK
bool bAbortDelete;		// LDH no accidental deletes 20Mar09
bool Reactive_profile; // Screwface

int profiles_list_start; // KK

int FreeSpace;
string qsLocationStr, qsPic1, qsOffic1, qsPic2, qsOffic2, qsPic3, qsOffic3, qsPic4, qsOffic4, qsTimeStr, qsProfile, qsSgvStr; // KK
string oldCurNode = "SAVE_BUTTON";//MAXIMUS

int iCurStoryline, iShowStoryline; // KK
string sCurProfile, sShowProfile; // KK

void InitInterface_B(string iniName, bool isSave)
{
	bThisSave = isSave;
	Reactive_profile = false;	// Screwface
	sCurProfile = "";			// PB
	GameInterface.title = "";

	FindScrshotClass();
	SetEventHandler("GetInterfaceTexture","NewInterfaceTexture",0);
	SetEventHandler("DelInterfaceTexture","ReleaseInterfaceTexture",0);

	if(GetTargetPlatform()=="xbox") FreeSpace = SendMessage(&GameInterface, "l", MSG_INTERFACE_GET_FREE_SPACE);
	else FreeSpace = 50000;

	bEnableNewSave = FreeSpace>=MAX_SAVE_STORE_BLOCKS;

// KK -->
	GameInterface.FACE1.current = 0;
	GameInterface.FACE1.ImagesGroup.t0 = "EMPTYFACE";
	GameInterface.FACE1.pic1.str1 = "";
	GameInterface.FACE1.pic1.img1 = "emptyface";
	if (bNewInterface) GameInterface.FACE1.pic1.img1 = "emptyface_new";
	GameInterface.FACE1.pic1.tex1 = 0;
	GameInterface.FACE1.ListSize = 1;
	GameInterface.FACE1.NotUsed = 1;

	GameInterface.FACE2.current = 0;
	GameInterface.FACE2.ImagesGroup.t0 = "EMPTYFACE";
	GameInterface.FACE2.pic1.str1 = "";
	GameInterface.FACE2.pic1.img1 = "emptyface";
	if (bNewInterface) GameInterface.FACE2.pic1.img1 = "emptyface_new";
	GameInterface.FACE2.pic1.tex1 = 0;
	GameInterface.FACE2.ListSize = 1;
	GameInterface.FACE2.NotUsed = 1;

	GameInterface.FACE3.current = 0;
	GameInterface.FACE3.ImagesGroup.t0 = "EMPTYFACE";
	GameInterface.FACE3.pic1.str1 = "";
	GameInterface.FACE3.pic1.img1 = "emptyface";
	if (bNewInterface) GameInterface.FACE3.pic1.img1 = "emptyface_new";
	GameInterface.FACE3.pic1.tex1 = 0;
	GameInterface.FACE3.ListSize = 1;
	GameInterface.FACE3.NotUsed = 1;

	GameInterface.FACE4.current = 0;
	GameInterface.FACE4.ImagesGroup.t0 = "EMPTYFACE";
	GameInterface.FACE4.pic1.str1 = "";
	GameInterface.FACE4.pic1.img1 = "emptyface";
	if (bNewInterface) GameInterface.FACE4.pic1.img1 = "emptyface_new";
	GameInterface.FACE4.pic1.tex1 = 0;
	GameInterface.FACE4.ListSize = 1;
	GameInterface.FACE4.NotUsed = 1;

	GameInterface.PROFILEFACE.current = 0;
	GameInterface.PROFILEFACE.ImagesGroup.t0 = "EMPTYFACE";
	GameInterface.PROFILEFACE.pic1.str1 = "";
	GameInterface.PROFILEFACE.pic1.img1 = "emptyface";
	if (bNewInterface) GameInterface.PROFILEFACE.pic1.img1 = "emptyface_new";
	GameInterface.PROFILEFACE.pic1.tex1 = 0;
	GameInterface.PROFILEFACE.ListSize = 1;
	GameInterface.PROFILEFACE.NotUsed = 1;

	string stmp = GetGlobalOption("storyline");
	string storyline;
	int slqty = GetStorylinesQuantity();
	int i;
	if (stmp == "") {
		for (i = 0; i < slqty; i++) {
			storyline = GetStoryline(i);
			if (GetProfilesQuantity(storyline) > 0) {
				iCurStoryline = i;
				sCurProfile = GetProfileName(storyline, 0);
				break;
			}
		}
	} else {
		iCurStoryline = sti(stmp);
		storyline = GetStoryline(iCurStoryline);
		// Screwface : there was a strange thing here. Sometimes when you started a new game, the getglobaloption returned
		// the profile name with extra caracters added so that's why the profile can't be found and is empty in load save screen
		/*if(CheckAttribute(Globalsettings,"profile."+storyline+".len")) stringlen = Globalsettings.profile.(storyline).len;
		if(stringlen != 0) // New recent game
		{*/
			stmp = GetGlobalOption("profile." + storyline);
		/*}
		else // loaded game
		{
			stmp = GetGlobalOption("profile." + storyline);
		}*/
		if (stmp != "" && FindProfile(storyline, stmp) > 0) {
			sCurProfile = stmp;
		} else {
			if (GetProfilesQuantity(storyline) > 0) {
				sCurProfile = GetProfileName(storyline, 0);
			} else {
				for (i = 0; i < slqty; i++) {
					storyline = GetStoryline(i);
					if (GetProfilesQuantity(storyline) > 0) {
						iCurStoryline = i;
						sCurProfile = GetProfileName(storyline, 0);
						break;
					}
				}
			}
		}
	}
	if(sCurProfile == "")	sCurProfile = GetAttribute(GetMainCharacter(), "profile");	// PB: Just in case the game can't find this
	if(sCurProfile == "-1")	sCurProfile = DEFAULT_PROFILE_NAME;							// PB: Just in case the game STILL can't find this
	iShowStoryline = iCurStoryline;
	sShowProfile = sCurProfile;
// <-- KK

	FillScroll();
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

	CreateString(true,"SaveName","",FONT_NORMAL,COLOR_NORMAL,50,330,SCRIPT_ALIGN_LEFT,1.0);
// KK -->
	CreateString(false,"NoSave","",FONT_NORMAL,COLOR_NORMAL,320,360,SCRIPT_ALIGN_CENTER,0.75); // NK for nosave mod
	CreateString(true, "Storyline_Profile", TranslateString("", "Storyline") + ": " + GetStorylineTitle(iCurStoryline) + ";  " + TranslateString("", "Profile") + ": " + FirstLetterUp(sCurProfile), FONT_NORMAL, COLOR_NORMAL, 34, 384, SCRIPT_ALIGN_LEFT, 1.0);
	CreateString(true, "ScreenTitle", "", FONT_TITLE, COLOR_NORMAL, 320, 6, SCRIPT_ALIGN_CENTER, 1.0);
	CreateString(false, "Storyline_selection", TranslateString("", "Storyline") + ":", FONT_NORMAL, COLOR_NORMAL, 70, 62, SCRIPT_ALIGN_LEFT, 1.0);
	CreateString(false, "StorylineTitle", "", FONT_NORMAL, COLOR_NORMAL, 370, 62, SCRIPT_ALIGN_CENTER, 1.0);
	for (i = 0; i < PROFILE_LIST_SIZE; i++) {
		CreateString(false, "ProfileName" + (i + 1), "", FONT_NORMAL, COLOR_NORMAL, 30, 125 + (i * 33), SCRIPT_ALIGN_LEFT, 1.0);
	}
	CreateString(false, "ProfileTitle", "", FONT_NORMAL, COLOR_NORMAL, 500, 120, SCRIPT_ALIGN_CENTER, 1.0);
	CreateString(false, "ProfileSaves", "", FONT_NORMAL, COLOR_NORMAL, 240, 260, SCRIPT_ALIGN_LEFT, 1.0);
	CreateExitString();// MAXIMUS

	if (bThisSave) {
		GameInterface.strings.ScreenTitle = XI_ConvertString("titleSave");
		SetNodeUsing("LOAD_BUTTON",false);
	} else {
		GameInterface.strings.ScreenTitle = XI_ConvertString("titleLoad");
		SetNodeUsing("SAVE_BUTTON",false);
	}
// <-- KK

	if(GetTargetPlatform()=="xbox")
	{
		string sFreeSpace = "Free Space: "+FreeSpace+" blocks";
		if(FreeSpace>50000) sFreeSpace = "Free Space: 50000+ blocks";
		CreateString(true,"FreeSpace",sFreeSpace,FONT_NORMAL,COLOR_NORMAL,320,178,SCRIPT_ALIGN_CENTER,1.0);
		SetNodeUsing("FREESPACE_IMG",true);
	}

	SetNodeUsing("CONFIRM_RECTANGLE",false);
	SetNodeUsing("TEXTWINDOW",false);
	SetNodeUsing("TEXTWINDOW1",false);
	SetNodeUsing("CONFIRM_YES_BUTTON",false);
	SetNodeUsing("CONFIRM_NO_BUTTON",false);
	SetNodeUsing("DISKETS_PIC",false);
	SetSelectable("EXIT_BUTTON",true);

	SetFormatedText("LOWSTORAGE_WINDOW",TranslateString("","save game limit"));

// KK -->
	//SetNodeUsing("PROFILES_BUTTON", !bThisSave);
	SetNodeUsing("PROFILES_BUTTON", true); // Screwface

	bNightmareMode = false; // NK defaults to off, needed due to CA below
	if (bThisSave) {
		// scheffnow -->
		ref PMainCharacter = GetMainCharacter();
		if (HasSubStr(PMainCharacter.location, "church"))
		{
		if (HasSubStr(PMainCharacter.location, "Greenford_M"))
			{		
			if (CheckAttribute(PMainCharacter,"NoSave.CarryRelic") == true && PMainCharacter.NoSave.CarryRelic != "none") 
				{
				bNightmareMode = true;
				GameInterface.strings.NoSave = TranslateString("","You can't save while carrying a holy relic in this old abbey! Give it to a monk") + " " + PMainCharacter.NoSave.ReleaseMonkLocation + "."; // NK
				EnableString("NoSave");
				}
			}
		}
		else
		{
			if (CheckAttribute(PMainCharacter,"NoSave.CarryRelic") == true && PMainCharacter.NoSave.CarryRelic != "none") 
			{
				bNightmareMode = true;
				GameInterface.strings.NoSave = TranslateString("","You can't save while carrying a holy relic! Give it to a monk") + " " + PMainCharacter.NoSave.ReleaseMonkLocation + "."; // NK
				EnableString("NoSave");
			}
		}  
		// scheffnow <--
		// PB -->
		if (CheckAttribute(PMainCharacter,"NoSave.Custom")) {
			bNightmareMode = true;
			GameInterface.strings.NoSave = "You can't save " + PMainCharacter.NoSave.Custom + ".";
			EnableString("NoSave");
		}
		// PB <--
	//	if(sCurProfile=="" || FindProfile(GetStoryline(FindCurrentStoryline()), sCurProfile) < 0) // Screwface 
		if(sCurProfile=="") // PB: Simplify to allow saving
		{
			bNightmareMode = true;
			GameInterface.strings.NoSave = "You can't save without an active Profile";
			EnableString("NoSave");
		}
	}
// <-- KK

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("frame","FrameProcess",1);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("SavePress","ProcessSaveConfirm",0);
	SetEventHandler("LoadPress","ProcessLoadConfirm",0);
	SetEventHandler("DelPress","ProcessDelete",0);
	SetEventHandler("DelNo","ProcessDelete_no",0);
	SetEventHandler("DelYes","ProcessDelete_yes",0);
	SetEventHandler("slistdown","SetFirstButton",0);
// KK -->
	SetEventHandler("exitProfiles", "EndSelectProfilesScreen", 0);
	SetEventHandler("ChangeStorylineLeft", "DoChangeStorylineLeft", 0);
	SetEventHandler("ChangeStorylineRight", "DoChangeStorylineRight", 0);
	SetEventHandler("IEvnt_MouseClick", "IProcMouseClick", 0);
	SetEventHandler("ScrollPosChange", "ProcScrollPosChange", 0);
// <-- KK
// added by MAXIMUS [for correct buttons selection] -->
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
	SetEventHandler("LeftPress","LeftProcess",0);
	SetEventHandler("RightPress","RightProcess",0);
	SetEventHandler("UpPress","UpProcess",0);
	SetEventHandler("DownPress","DownProcess",0);
	NextDown("SAVE_BUTTON");
// added by MAXIMUS [for correct buttons selection] <--

	SetFirstButton(); // PB
}

void FrameProcess()
{
	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	if(nCurScroll!=sti(GameInterface.saveslist.current) )
	{
		nCurScroll = sti(GameInterface.saveslist.current);
		string attrName = "pic" + (nCurScroll+1);
		string filename; // KK
		bool bFilePresent = false;
		bool bCorrupted = false;

		if(CheckAttribute(&GameInterface,"saveslist."+attrName+".descr") && GameInterface.saveslist.(attrName).descr != "")
		{
			bFilePresent = true;
			string qsFileName = "-=" + FirstLetterUp(sCurProfile) + "=- QuickSave"; // KK
			if(GameInterface.saveslist.(attrName).savestr=="" && GameInterface.saveslist.(attrName).name1!=qsFileName) // allow loading quicksave. NK 05-04-14 // KK
			{
				bCorrupted = true; /*aref artmp; makearef(artmp, GameInterface.saveslist.(attrName)); dumpattributes(artmp);*/
			}
			filename = GameInterface.saveslist.(attrName).name1; // KK
		}

		SetSelectable("SAVE_BUTTON", !bNightmareMode); // KK
		SetSelectable("DEL_BUTTON",bFilePresent);
		
		if (bFilePresent) {
			if (!bThisSave) SetSelectable("LOAD_BUTTON", !bCorrupted);
		} else {
			SetSelectable("SAVE_BUTTON", bEnableNewSave && !bNightmareMode); // KK
		}

		if(bFilePresent)
		{
			if(bCorrupted) SettingDataForSave("");
			else SettingDataForSave(GameInterface.saveslist.(attrName).descr);
		}
		else
		{
			if(bThisSave) SettingDataForSave("NewSave");
			else
			{
				SetSelectable("LOAD_BUTTON",false);
				SettingDataForSave("");
			}
		}

		ShowLowStorage( !CheckAvailablePlace() );

		if(CheckLimited()) SetNodeUsing("LOWSTORAGE_WINDOW",false);
		else
		{
			SetNodeUsing("LOWSTORAGE_WINDOW",true);
			DisableString("SaveName");
			SetSelectable("SAVE_BUTTON",false);
		}

		if (!bThisSave) CheckButtonStatus(filename); // KK

		//SetFirstButton(); // PB: Why do I need to do this? // MM: Good question - nuked
		if(!GetSelectable(GetCurrentNode())) SetCurrentNode("SAVESLIST");
	}
}

// KK -->
void CheckButtonStatus(string saveName)
{
	if (saveName == "") {
		SetSelectable("LOAD_BUTTON", false);
		return;
	}
	string sdir = "SAVE\" + GetStorylineDir(iCurStoryline);
	string saveString = "";
	bool bCorrupted = true;
	bool bIncompatible = true;
	bool bFilePresent = FindFile(sdir, "*", saveName) != "";
	if (bFilePresent) {
		saveString = IGetSaveString(sdir + saveName);
		bCorrupted = saveString == "";
		bIncompatible = GetSaveVersion(saveString) != makefloat(IS_SGV);
		if (bIncompatible) trace("INCOMPATIBLE SAVE: " + saveName + " is compatible with " + GetSaveVersion(saveString)); // PB
	}
	SetSelectable("LOAD_BUTTON", bFilePresent && !bCorrupted && !bIncompatible && !bThisSave);
}
// <-- KK

void FillScroll()
{
    int i=0;
    string attributeName;
	if(CheckAttribute(&GameInterface,"saveslist")) DeleteAttribute(&GameInterface,"saveslist");
	string savepath = "SAVE\" + GetStorylineDir(iCurStoryline); // KK

	nCurScroll = -1;
	GameInterface.SavePath = savepath;
	GameInterface.saveslist.current = 0;
// KK -->
	if (bNewInterface)
		GameInterface.saveslist.BadPicture1 = "interfaces\Disketa_Empty_new.tga";
	else
		GameInterface.saveslist.BadPicture1 = "interfaces\Disketa_Empty.tga";
	GameInterface.saveslist.ImagesGroup.t0 = "CORRUPTSAVE";
// <-- KK
	GameInterface.saveslist.NotUsed = 5;
	
	if(bThisSave && !bNightmareMode)
	{
		GameInterface.saveslist.pic1.name1 = "newsave";
// KK -->
		if (bEnableNewSave)
			GameInterface.saveslist.pic1.str1 = "NewSave";
		else
			GameInterface.saveslist.pic1.str2 = "Low Storage";
// <-- KK
		GameInterface.saveslist.pic1.saveSize = 0;
		i++;
	}
	
	string saveName;
	string saveString;
	int nSaveSize;
// KK -->
	bool bQuickSave, bCorrupted, bIncompatible;
	string InfoStr1, InfoStr2;
	/*string qsName = "";

	string qsFileName = "-=" + FirstLetterUp(sCurProfile) + "=- QuickSave"; // KK
	string qsDescr = "QuickSave"; // KK

	if(FindFile(GameInterface.SavePath, "*", qsFileName) != "") // KK
	{
		qsName = "pic"+(i+1);
		if (bNewInterface)
			GameInterface.saveslist.(qsName).img1 = "corruptsave_new";
		else
			GameInterface.saveslist.(qsName).img1 = "corruptsave";
		GameInterface.saveslist.(qsName).tex1 = 0;
		GameInterface.saveslist.(qsName).name1 = qsFileName;
		GameInterface.saveslist.(qsName).descr = qsDescr;
		GameInterface.saveslist.(qsName).savestr = "";
		GameInterface.saveslist.(qsName).saveSize = 0;
		i++;
	}*/

	/*DeleteAttribute(&LocationDirectory, "");

	LocationDirectory.dir = savepath;
	LocationDirectory.mask = "*";
	CreateEntity(&LocationDirectory,"FINDFILESINTODIRECTORY");
	DeleteClass(&LocationDirectory);
	aref arList; makearef(arList, LocationDirectory.filelist);*/
	int j = 0;
	//for(int j=0; j<GetAttributesNum(arList); j++)
	//{
	while (SendMessage(&GameInterface, "llee", MSG_INTERFACE_SAVE_FILE_FIND, j, &saveName, &nSaveSize) != 0) {
		if (!CheckSavedFile(saveName, GetStoryline(iCurStoryline), sCurProfile)) {
			j++;
			continue;
		}

		bQuickSave = HasSubStr(saveName, "QuickSave");
		saveString = IGetSaveString("SAVE\" + GetStorylineDir(iCurStoryline) + saveName);
		bCorrupted = saveString == "";
		bIncompatible = GetSaveVersion(saveString) != makefloat(IS_SGV);
		InfoStr1 = "";
		InfoStr2 = "";
		if (bQuickSave) InfoStr1 = "QuickSave";
		if (bCorrupted) {
			InfoStr1 = "";
			InfoStr2 = "BadSave";
		}
		if (bIncompatible && !bCorrupted) {
			InfoStr1 = "";
			InfoStr2 = "IncompatibleSave";
		}
		/*if (saveName == qsFileName) {
			if (qsName != "") GameInterface.saveslist.(qsName).saveSize = nSaveSize;
		}
		else
		{*/
			attributeName = "pic" + (i+1);
			GameInterface.saveslist.(attributeName).str1 = InfoStr1;
			GameInterface.saveslist.(attributeName).str2 = InfoStr2;
			if (bNewInterface)
				GameInterface.saveslist.(attributeName).img1 = "corruptsave_new";
			else
				GameInterface.saveslist.(attributeName).img1 = "corruptsave";
			GameInterface.saveslist.(attributeName).tex1 = 0;
			GameInterface.saveslist.(attributeName).name1 = saveName;
			GameInterface.saveslist.(attributeName).descr = saveName;
			GameInterface.saveslist.(attributeName).savestr = saveString;
			GameInterface.saveslist.(attributeName).saveSize = nSaveSize;
			i++;
		//}
		j++;
	}
// <-- KK

	GameInterface.saveslist.ListSize = i;
}

// KK -->
bool CheckSavedFile(string saveName, string storyline, string profile)
{
	int slidx = FindStoryline(storyline);
	int pidx = FindProfile(storyline, profile);
	if(saveName=="" || saveName=="." || saveName==".." || HasSubStr(saveName,"options") || slidx < 0 || pidx < 0) return false;
	string savepath = "SAVE\" + GetStorylineDir(slidx);
	bool bExists = FindFile(savepath, "*", saveName) != "";
	if (bExists)
	{
		if (saveName == "-=" + profile + "=- QuickSave") return false;
		return HasSubStr(saveName, "-=" + profile + "=-");
	}
	return false;
}
// <-- KK

void ProcessCancelExit()
{
	InterfaceStates.InstantExit = true;//MAXIMUS
	IDoExit(RC_INTERFACE_SAVELOAD_EXIT);
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("frame","FrameProcess");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("SavePress","ProcessSaveConfirm");
	DelEventHandler("LoadPress","ProcessLoadConfirm");
	DelEventHandler("DelPress","ProcessDelete");
	DelEventHandler("DelNo","ProcessDelete_no");
	DelEventHandler("DelYes","ProcessDelete_yes");
	DelEventHandler("GetInterfaceTexture","NewInterfaceTexture");
	DelEventHandler("DelInterfaceTexture","ReleaseInterfaceTexture");
	DelEventHandler("slistdown","SetFirstButton");
// KK -->
	DelEventHandler("exitProfiles", "EndSelectProfilesScreen");
	DelEventHandler("ChangeStorylineLeft", "DoChangeStorylineLeft");
	DelEventHandler("ChangeStorylineRight", "DoChangeStorylineRight");
	DelEventHandler("IEvnt_MouseClick", "IProcMouseClick");
	DelEventHandler("ScrollPosChange", "ProcScrollPosChange");
// <-- KK
// added by MAXIMUS [for correct buttons selection] -->
	DelEventHandler("ievnt_command","ProcessCommandExecute");
	DelEventHandler("LeftPress","LeftProcess");
	DelEventHandler("RightPress","RightProcess");
	DelEventHandler("UpPress","UpProcess");
	DelEventHandler("DownPress","DownProcess");
// added by MAXIMUS [for correct buttons selection] <--

	//SetNodeUsing("SAVESLIST",false);
	EndCancelInterface(true);

    interfaceResultCommand = exitCode;
	if(!CheckAttribute(&InterfaceStates,"InstantExit") || sti(InterfaceStates.InstantExit)==true) { ReturnToMainMenu(); }
	InterfaceStates.InstantExit = false;//MAXIMUS
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	int x;ref tmpch;string tmpstr;
// KK -->
	if (HasSubStr(nodName, "B_PROFILE")) {
		if (comName == "activate" || comName == "click") {
			ShowProfile(sti(strcut(nodName, 9, strlen(nodName) - 1)));
			if(bThisSave) SetSelectable("PROFILELOAD_BUTTON",  true); // Screwface
		}
	}
	if (nodName == "PROFILELOAD_BUTTON") {
		if (comName == "activate" || comName == "click") {
			UpdateLoadScreen(iShowStoryline, sShowProfile);
		}
	}
	if (nodName == "PROFILEDELETE_BUTTON") {
		if (comName == "activate" || comName == "click") {
			ProcessProfileDelete();
		}
	}
// <-- KK
	if(nodName=="PROFILES_BUTTON")
	{
			if(comName=="activate" || comName=="click")
			{
				if(!bThisSave) // Screwface
					StartSelectProfileScreen(); // KK
				else
					StartActiveProfileScreen();
				/*PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
				InterfaceStack.SelectMenu_node = nodName;
				interfaceResultCommand = RC_INTERFACE_SAVELOAD_EXIT;
				EndCancelInterface(false);*/
			}
	}

// LDH No accidental deletes by pressing the space bar rapidly to load a game.
	// This can happen if you're used to hitting space bar 3 times at the main menu 
	// to load your last save without using the mouse.  If the mouse moves, you can accidentally get the delete button instead.
	// You can only confirm a delete by clicking on the YES button in the confirmation screen, not with the space bar.
	if (nodName == "CONFIRM_YES_BUTTON" && !bLoadConfirm && !bSaveConfirm)
	{
		if (comName != "click") 
		{
			bAbortDelete = true;		// LDH no accidental deletes 20Mar09
		}
	}
// LDH <--}
}

// KK -->
void IProcMouseClick()
{
	string nodName = GetEventData();
	int btnCode = GetEventData();

	if (nodName == "STORYLINES") {
		if (btnCode == 0) Event("ChangeStorylineLeft");
		if (btnCode == 1) Event("ChangeStorylineRight");
	}
}
// <-- KK

void ProcessSaveConfirm()
{
	// Screwface
	if(reactive_profile)
	{
		CurrentStoryline = FindCurrentStoryline();
		string storyline = GetStoryline(CurrentStoryline);
		CurrentProfile = sCurProfile;
		//stringlen = strlen(sCurProfile);
		//LoadGlobalOptions();
		ref gopt; makeref(gopt, GlobalSettings);
		ReadMainOptions(&gopt);
		gopt.Storyline = CurrentStoryline;
		gopt.profile.(storyline) = CurrentProfile;
		//gopt.profile.(storyline).len = stringlen;
		gopt.end = 1;
		WriteMainOptions(gopt);
		reactive_profile = false;
	}
	string attributeName = "saveslist.pic" + (nCurScroll+1);
	if( CheckAttribute(&GameInterface,attributeName+".descr") )
	{
		bSaveConfirm = true;
		bLoadConfirm = false;
		bProfileDelete = false; // KK

		SetNodeUsing("CONFIRM_RECTANGLE",true);
		SetNodeUsing("TEXTWINDOW",true);
		SetNodeUsing("TEXTWINDOW1",true); //added by MAXIMUS
		SetNodeUsing("CONFIRM_YES_BUTTON",true);
		SetNodeUsing("CONFIRM_NO_BUTTON",true);
		SetNodeUsing("DISKETS_PIC",true); //added by MAXIMUS
		SetCurrentNode("CONFIRM_YES_BUTTON"); // NK
		SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "CONFIRM_NO_BUTTON");
		SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "CONFIRM_YES_BUTTON");

		SetFormatedText("TEXTWINDOW",TranslateString("","Overwrite savefile confirm"));
		SetFormatedText("TEXTWINDOW1",GameInterface.strings.SaveNameConfirm); //added by MAXIMUS
	}
	else
	{
		ProcessSave();
	}
}

void ProcessSave()
{
	string curSave = GetCurSaveName();
	if(nCurScroll>0)
	{
		SendMessage(&GameInterface,"ls",MSG_INTERFACE_DELETE_SAVE_FILE,curSave);
		nCurScroll = 0;
		curSave = GetCurSaveName();
	}

	ref PChar = GetMainCharacter();
	if(CheckAttribute(PChar,"systemStatus")) DeleteAttribute(PChar,"systemStatus");//MAXIMUS

	string sSaveDescriber = GetSaveDataString();

	SetEventHandler("evntSave","SaveGame",1);

	GameInterface.SavePath = "SAVE\" + GetStorylineDir(iCurStoryline); // KK

	if(GetTargetPlatform()=="pc") {
		PostEvent("evntSave",0,"sss", GameInterface.SavePath, curSave, sSaveDescriber);
	} else {
		PostEvent("evntSave",0,"ss", curSave, sSaveDescriber);
		Event("DoInfoShower","sl","save game",true);
	}

	InterfaceStates.InstantExit = false;//MAXIMUS
	IDoExit(RC_INTERFACE_SAVELOAD_EXIT);
}

void SetFirstButton()
{
	if( bThisSave )
	{
		if( GetSelectable("SAVE_BUTTON") ) {
			SetCurrentNode("SAVE_BUTTON");
			return;
		}
	}
	else
	{
		if( GetSelectable("LOAD_BUTTON") ) {
			SetCurrentNode("LOAD_BUTTON");
			return;
		}
	}
	if( GetSelectable("DEL_BUTTON") ) SetCurrentNode("DEL_BUTTON");
	else SetCurrentNode("CANCEL_BUTTON");
}

void ProcessLoadConfirm()
{
	bLoadConfirm = true;
	bSaveConfirm = false;
	bProfileDelete = false; // KK

	SetNodeUsing("CONFIRM_RECTANGLE",true);
	SetNodeUsing("TEXTWINDOW",true);
	SetNodeUsing("TEXTWINDOW1",true); //added by MAXIMUS
	SetNodeUsing("CONFIRM_YES_BUTTON",true);
	SetNodeUsing("CONFIRM_NO_BUTTON",true);
	SetNodeUsing("DISKETS_PIC",true); //added by MAXIMUS
	SetCurrentNode("CONFIRM_YES_BUTTON"); // NK
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "CONFIRM_NO_BUTTON");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "CONFIRM_YES_BUTTON");

	SetFormatedText("TEXTWINDOW",TranslateString("","Load game confirm"));
	SetFormatedText("TEXTWINDOW1",GameInterface.strings.SaveNameConfirm); //added by MAXIMUS
}

void ProcessLoad()
{
	string sCurSave = GetCurSaveName();
	string sldir = GetStorylineDir(iCurStoryline); // KK

	InterfaceStates.InstantExit = false;//MAXIMUS
	IDoExit(RC_INTERFACE_SAVELOAD_EXIT);
	ResetSound();

	SetEventHandler("evntLoad","LoadGame",1);

	GameInterface.SavePath = "SAVE\" + sldir; // KK

	if(GetTargetPlatform()=="pc") {
		PostEvent("evntLoad",0,"s",GameInterface.SavePath + sCurSave);
	} else {
		PostEvent("evntLoad",0,"s",sCurSave);
	}
	Event("evntPreLoad");
}

void ProcessDelete()
{
	bAbortDelete = false;		// LDH no accidental deletes 20Mar09

	bSaveConfirm = false;
	bLoadConfirm = false;
	bProfileDelete = false; // KK

	SetNodeUsing("CONFIRM_RECTANGLE",true);
	SetNodeUsing("TEXTWINDOW",true);
	SetNodeUsing("TEXTWINDOW1", true); // KK
	SetNodeUsing("CONFIRM_YES_BUTTON",true);
	SetNodeUsing("CONFIRM_NO_BUTTON",true);
	SetNodeUsing("DISKETS_PIC",true); //added by MAXIMUS
	SetCurrentNode("CONFIRM_NO_BUTTON");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "CONFIRM_NO_BUTTON");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "CONFIRM_YES_BUTTON");

	SetFormatedText("TEXTWINDOW",TranslateString("","Delete savefile confirm"));
	if(CheckAttribute(GameInterface,"strings.SaveNameConfirm")) SetFormatedText("TEXTWINDOW1",GameInterface.strings.SaveNameConfirm); //added by MAXIMUS
}

void ProcessDelete_no()
{
	SetNodeUsing("CONFIRM_RECTANGLE",false);
	SetNodeUsing("TEXTWINDOW",false);
	SetNodeUsing("TEXTWINDOW1",false);
	SetNodeUsing("CONFIRM_YES_BUTTON",false);
	SetNodeUsing("CONFIRM_NO_BUTTON",false);
	SetNodeUsing("DISKETS_PIC",false);
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);

	if(	bSaveConfirm )	{SetCurrentNode("SAVE_BUTTON");}
	else {
		if(bLoadConfirm) {SetCurrentNode("LOAD_BUTTON");}
		else {
			if(bProfileDelete) {SetCurrentNode("PROFILELOAD_BUTTON");} // KK
			else {SetCurrentNode("DEL_BUTTON");}
		}
	}
}

void ProcessDelete_yes()
{
	SetNodeUsing("CONFIRM_RECTANGLE",false);
	SetNodeUsing("TEXTWINDOW",false);
	SetNodeUsing("TEXTWINDOW1",false);
	SetNodeUsing("CONFIRM_YES_BUTTON",false);
	SetNodeUsing("CONFIRM_NO_BUTTON",false);
	SetNodeUsing("DISKETS_PIC",false);
	SetCurrentNode("DEL_BUTTON");
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);

	if(	bSaveConfirm )
	{
		ProcessSave();
		return;
	}
	if( bLoadConfirm )
	{
		ProcessLoad();
		return;
	}

	if (bAbortDelete) return;		// LDH no accidental deletes 20Mar09

// KK -->
	if (bProfileDelete)
	{
		string storyline = GetStoryline(iShowStoryline);
		DeleteProfile(storyline, sShowProfile);
		if (GetProfilesQuantity(storyline) == 0) {
			int pq = GetStorylinesQuantity();
			for (int i = 0; i < pq; i++) {
				storyline = GetStoryline(i);
				if (GetProfilesQuantity(storyline) > 0) {
					iShowStoryline = i;
					sShowProfile = GetProfileName(storyline, 1);
					StartSelectProfileScreen();
					return;
				}
			}
			Event("exitCancel");
		}
		return;
	}
// <-- KK

	string curSave = GetCurSaveName();
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_DELETE_SAVE_FILE,curSave);
	DelFromScroll("SAVESLIST",nCurScroll);

	if( GetTargetPlatform()!="pc" )
	{
		FreeSpace = SendMessage(&GameInterface, "l", MSG_INTERFACE_GET_FREE_SPACE);
		string sFreeSpace = "Free Space: "+FreeSpace+" blocks";
		if(FreeSpace>50000) sFreeSpace = "Free Space: 50000+ blocks";
		GameInterface.strings.FreeSpace = sFreeSpace;
	}
	if( bThisSave && !bEnableNewSave && FreeSpace>=MAX_SAVE_STORE_BLOCKS )
	{
		bEnableNewSave = true;
		DeleteAttribute( &GameInterface,"saveslist.pic1.str1" );
		SendMessage(&GameInterface,"lsl", MSG_INTERFACE_SCROLL_CHANGE, "SAVESLIST", 0);
	}
	nCurScroll = -1;
	SettingDataForSave(curSave);//MAXIMUS
}

string GetCurSaveName()
{
	string attrName = "pic"+(nCurScroll+1);
// KK -->
	if( CheckAttribute(&GameInterface,"saveslist."+attrName+".name1") && GameInterface.saveslist.(attrName).name1 != ""  && GameInterface.saveslist.(attrName).name1 != "newsave")
		return GameInterface.saveslist.(attrName).name1;
// <-- KK

	string curLocName = "-=" + sCurProfile + "=- " + GetCurLocationName(); // KK
	string saveName = GetClampedSaveName(curLocName,0);

	int idx = 0;
	while( SendMessage(&GameInterface,"ls", MSG_INTERFACE_NEW_SAVE_FILE_NAME, saveName)==1 )
	{
		saveName = GetClampedSaveName(curLocName,idx+1);
		idx++;
	}

	return saveName;
}

void SettingDataForSave(string saveFileName)
{
	string pic1,pic2,pic3,pic4;
	string offic1, offic2, offic3, offic4; // KK
	string locationStr, timeStr, tmpStr, tmpStr2;
	string sgvStr = -1; // TIH Aug24'06
	int locidx;
	ref PChar = GetMainCharacter();

	EnableString("SaveName");
	if( saveFileName=="" )
	{
		tmpStr2 = GetCurSaveName();
		SendMessage(&GameInterface, "lse", MSG_INTERFACE_FILENAME2DATASTR, GetCurSaveName(), &tmpStr2);
		GameInterface.strings.SaveName = XI_ConvertString("Unable to load") + " " + tmpStr2;
		pic1 = -1;
		pic2 = -1;
		pic3 = -1;
		pic4 = -1;
		SetCurrentNode("CANCEL_BUTTON"); // KK
		return;
	}

	tmpStr = "";
	if( saveFileName=="NewSave" )
	{
		if(GetMainCharacterIndex()>=0)
		{
// KK -->
			locationStr = CreateLocDescribe();
			pic1 = GetFacePicture(GetCompanionIndex(PChar, 0)); // NK
			offic1 = GetMyFormalName(GetCharacter(GetCompanionIndex(PChar, 0))); // PB: Fill in missing firstnames
			pic2 = GetFacePicture(GetCompanionIndex(PChar, 1)); // NK
			offic2 = GetMyFormalName(GetCharacter(GetCompanionIndex(PChar, 1))); // PB: Fill in missing firstnames
			pic3 = GetFacePicture(GetCompanionIndex(PChar,2)); // NK
			offic3 = GetMyFormalName(GetCharacter(GetCompanionIndex(PChar, 2))); // PB: Fill in missing firstnames
			pic4 = GetFacePicture(GetCompanionIndex(PChar, 3)); // NK
			offic4 = GetMyFormalName(GetCharacter(GetCompanionIndex(PChar, 3))); // PB: Fill in missing firstnames
			timeStr = GetHumanDate(GetDataYear(),GetDataMonth(),GetDataDay()) + " " + GetStringTime(GetTime());
// <-- KK
		}
		else
		{
			locationStr = "none";
			pic1 = -1; offic1 = "";
			pic2 = -1; offic2 = "";
			pic3 = -1; offic3 = "";
			pic4 = -1; offic4 = "";
		}
		tmpStr2 = GetCurSaveName();
		SendMessage(&GameInterface, "lse", MSG_INTERFACE_FILENAME2DATASTR, TranslateString("","NewSave") + " - " + GetCurSaveName(), &tmpStr2);
		SendMessage(&GameInterface, "lse", MSG_INTERFACE_GETTIME, "", &tmpStr);
	}
	else
	{
		if(!ParseSaveData(IGetSaveStringFromScroll(), &pic1, &offic1, &pic2, &offic2, &pic3, &offic3, &pic4, &offic4, &locationStr, &timeStr, &sgvStr)) // TIH Aug24'06
			ParseSaveData("none@-1@-1@-1@-1@not implemented@-1", &pic1, &offic1, &pic2, &offic2, &pic3, &offic3, &pic4, &offic4, &locationStr, &timeStr, &sgvStr); // TIH Aug24'06
		tmpStr2 = saveFileName;
		SendMessage(&GameInterface, "lse", MSG_INTERFACE_FILENAME2DATASTR, saveFileName, &tmpStr2);
		if(GetTargetPlatform()=="xbox") {
			SendMessage(&GameInterface, "lse", MSG_INTERFACE_GETTIME, saveFileName, &tmpStr);
		} else {
			SendMessage(&GameInterface, "lse", MSG_INTERFACE_GETTIME, "SAVE\" + GetStorylineDir(iCurStoryline) + "\" + saveFileName, &tmpStr);
		}
	}

	// TIH --> Aug24'06
	if ( saveFileName != "" && stf(sgvStr) < stf(IS_SGV) && !bThisSave)
	{
		SetSelectable("LOAD_BUTTON",false);
		/*SetNodeUsing("VERSIONMISMATCHBOX",true);
		SetNodeUsing("VERSIONMISMATCH",true);
		SetSelectable("VERSIONMISMATCH",true);*/
		
	}
	// TIH <--
	string ProfileName = FirstLetterUp(sCurProfile);
	if (saveFileName != "" && HasSubStr(IGetSaveStringFromScroll(), ProfileName) == true && bThisSave == false) // KK
	{
		SetSelectable("LOAD_BUTTON",true);
	}
// KK -->
	GameInterface.strings.SaveName = "";
	string tempString = strcut(tmpStr2, findSubStr(tmpStr2, "=-", 0) + 3, strlen(tmpStr2) - 1);
	if (!HasSubStr(tmpStr2, "QuickSave")) tempString = timeStr + " " + tmpStr;
	GameInterface.strings.SaveName = GameInterface.strings.SaveName + locationStr + " " + timeStr; // KK tempString; // changed by MAXIMUS <--
	GameInterface.strings.SaveNameConfirm = GameInterface.strings.SaveName;

	if (pic1 >= 0) {
		GameInterface.FACE1.pic1.str2 = "#" + offic1;
		GameInterface.FACE1.pic1.img1 = "face";
		AddFaceGroup("FACE1.ImagesGroup", "FACE128_" + pic1);
		GameInterface.FACE1.pic1.tex1 = FindFaceGroupNum("FACE1.ImagesGroup", "FACE128_" + pic1);
	} else {
		GameInterface.FACE1.pic1.str2 = "";
		GameInterface.FACE1.pic1.img1 = "emptyface";
		if (bNewInterface) GameInterface.FACE1.pic1.img1 = "emptyface_new";
		GameInterface.FACE1.pic1.tex1 = 0;
	}
	SendMessage(&GameInterface, "ls", MSG_INTERFACE_REFRESH_SCROLL, "FACE1");

	if (pic2 >= 0) {
		GameInterface.FACE2.pic1.str2 = "#" + offic2;
		GameInterface.FACE2.pic1.img1 = "face";
		AddFaceGroup("FACE2.ImagesGroup", "FACE128_" + pic2);
		GameInterface.FACE2.pic1.tex1 = FindFaceGroupNum("FACE2.ImagesGroup", "FACE128_" + pic2);
	} else {
		GameInterface.FACE2.pic1.str2 = "";
		GameInterface.FACE2.pic1.img1 = "emptyface";
		if (bNewInterface) GameInterface.FACE2.pic1.img1 = "emptyface_new";
		GameInterface.FACE2.pic1.tex1 = 0;
	}
	SendMessage(&GameInterface, "ls", MSG_INTERFACE_REFRESH_SCROLL, "FACE2");

	if (pic3 >= 0) {
		GameInterface.FACE3.pic1.str2 = "#" + offic3;
		GameInterface.FACE3.pic1.img1 = "face";
		AddFaceGroup("FACE3.ImagesGroup", "FACE128_" + pic3);
		GameInterface.FACE3.pic1.tex1 = FindFaceGroupNum("FACE3.ImagesGroup", "FACE128_" + pic3);
	} else {
		GameInterface.FACE3.pic1.str2 = "";
		GameInterface.FACE3.pic1.img1 = "emptyface";
		if (bNewInterface) GameInterface.FACE3.pic1.img1 = "emptyface_new";
		GameInterface.FACE3.pic1.tex1 = 0;
	}
	SendMessage(&GameInterface, "ls", MSG_INTERFACE_REFRESH_SCROLL, "FACE3");

	if (pic4 >= 0) {
		GameInterface.FACE4.pic1.str2 = "#" + offic4;
		GameInterface.FACE4.pic1.img1 = "face";
		AddFaceGroup("FACE4.ImagesGroup", "FACE128_" + pic4);
		GameInterface.FACE4.pic1.tex1 = FindFaceGroupNum("FACE4.ImagesGroup", "FACE128_" + pic4);
	} else {
		GameInterface.FACE4.pic1.str2 = "";
		GameInterface.FACE4.pic1.img1 = "emptyface";
		if (bNewInterface) GameInterface.FACE4.pic1.img1 = "emptyface_new";
		GameInterface.FACE4.pic1.tex1 = 0;
	}
	SendMessage(&GameInterface, "ls", MSG_INTERFACE_REFRESH_SCROLL, "FACE4");
// <-- KK
}

//MAXIMUS: --> // KK -->
float GetSaveVersion(string saveData)
{
	float fver = 0.0;
	if (saveData == "") return 0.0;
	string stmp, sver;
	stmp = "";
	sver = "";
	if (ParseSaveData(saveData, &stmp, &stmp, &stmp, &stmp, &stmp, &stmp, &stmp, &stmp, &stmp, &stmp, &sver)) {
		fver = stf(sver);
	}
	return fver;
}
//MAXIMUS: <-- // <-- KK

bool ParseSaveData(string fullSaveData, ref pic1, ref offic1, ref pic2, ref offic2, ref pic3, ref offic3, ref pic4, ref offic4,
                   ref locationStr, ref timeStr, ref sgvStr) // TIH Aug24'06
{
//	Trace("SAVEGAME - parse: "+ fullSaveData);
	string lastStr;
	if( !GetNextSubStr(fullSaveData, locationStr, &lastStr) ) return false;
	if( !GetNextSubStr(lastStr, pic1, &lastStr) ) return false;
	if( !GetNextSubStr(lastStr, offic1, &lastStr) ) return false;
	if( !GetNextSubStr(lastStr, pic2, &lastStr) ) return false;
	if( !GetNextSubStr(lastStr, offic2, &lastStr) ) return false;
	if( !GetNextSubStr(lastStr, pic3, &lastStr) ) return false;
	if( !GetNextSubStr(lastStr, offic3, &lastStr) ) return false;
	if( !GetNextSubStr(lastStr, pic4, &lastStr) ) return false;
	if( !GetNextSubStr(lastStr, offic4, &lastStr) ) return false;
	if( !GetNextSubStr(lastStr, timeStr, &lastStr) ) return false;
	if( !GetNextSubStr(lastStr, sgvStr, &lastStr) ) return false; // TIH Aug24'06
	return true;
}

bool GetNextSubStr(string inStr, ref outStr, ref lastStr)
{
	if(inStr=="")
	{
		outStr="";
		lastStr="";
		return false;
	}
	int strSize = strlen(inStr)-1;
	if(strSize<=0)
	{
		outStr="";
		lastStr="";
		return false;
	}
	int sympos = findsubstr(inStr,"@",0);
	if(sympos==-1)
	{
		outStr = inStr;
		lastStr = "";
		return true;
	}
	if(sympos>0)	outStr = strcut(inStr,0,sympos-1);
	else	outStr = "";
	if(strSize>sympos+1) lastStr = strcut(inStr,sympos+1,strSize);
	else lastStr = "";
	return true;
}

int sl_tmp_var;
ref NewInterfaceTexture()
{
	string str = GetEventData();
	string strSaveData = ""; // TIH initialize it Aug24'06
//	if(str!="quicksave")) // NK 05-04-14 fix quicksave "out of memory" error //MAXIMUS
//	{
	if (GetTargetPlatform()=="pc") {
		sl_tmp_var = SendMessage(&scrshot,"lsse", MSG_SCRSHOT_READ, "SAVE\" + GetStorylineDir(iCurStoryline), str, &strSaveData);
	} else {
		sl_tmp_var = SendMessage(&scrshot,"lsse", MSG_SCRSHOT_READ,"", str, &strSaveData);
	}
//	}
//	else { sl_tmp_var = 0; }
	SetDataIntoList(str,strSaveData);
	return &sl_tmp_var;
}

void ReleaseInterfaceTexture()
{
	string str = GetEventData();
	sl_tmp_var = SendMessage(&scrshot,"ls",MSG_SCRSHOT_RELEASE,str);
}

void FindScrshotClass()
{
// KK -->
	string layerName = "realize";
	if (bSeaActive && !bAbordageStarted) layerName = SEA_REALIZE;
// <-- KK
	aref refObj;
	if(GetEntity(layerName,&refObj))
	{
		while(true)
		{
			if(GetEntityName(&refObj)=="scrshoter")
			{
				scrshot = refObj;
				break;
			}
			if(!GetEntityNext(&refObj)) break;
		}
	}
}

string _IGetSaveString(string saveName)
{
	if(GetTargetPlatform()=="pc") {
		return IGetSaveString("SAVE\" + GetStorylineDir(iCurStoryline) + "\" + saveName);
	} else {
		return IGetSaveString(saveName);
	}
}

string IGetSaveStringFromScroll()
{
	string attributeName = "pic" + (nCurScroll+1);
	if(CheckAttribute(&GameInterface,"saveslist."+attributeName)) return GameInterface.saveslist.(attributeName).savestr;
	return "";
}

bool CheckAvailablePlace()
{
	if(GetTargetPlatform()=="pc") return true;
	string attributeName = "pic" + (nCurScroll+1);
	int nOldBlocks = 0;
	if(CheckAttribute(&GameInterface,"saveslist."+attributeName+".saveSize"))
	{
		nOldBlocks = sti( GameInterface.saveslist.(attributeName).saveSize );
	}
	int availableBlocks = FreeSpace + nOldBlocks;
	if(availableBlocks>=MAX_SAVE_STORE_BLOCKS) return true;
	return false;
}

void ShowLowStorage(bool bStartShow)
{
	if(bStartShow)	DisableString("SaveName");
}

void SetDataIntoList(string saveName, string strSaveData)
{
	aref aRoot;
	makearef(aRoot,GameInterface.saveslist);

	int n=1;
	string attributeName = "pic1";
	while(CheckAttribute(aRoot,attributeName))
	{
		if(aRoot.(attributeName).name1 == saveName)
		{
			aRoot.(attributeName).savestr = strSaveData;
			return;
		}
		n++;
		attributeName = "pic"+n;
	}
}

string GetCurLocationName()
{
	if(GetMainCharacterIndex()<0) return "";
	ref PChar = GetMainCharacter();
	if(!CheckAttribute(PChar,"location")) return "";

// rewritten by MAXIMUS 09.10.2006 [for correct location name showing]-->
	string locLabel, curIsland, curComma;
	locLabel = PChar.location;
// rewritten by MAXIMUS 09.10.2006 [for correct location name showing]<--

	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");

	int locidx = FindLocation(PChar.location);
	if( locidx>=0 )
	{
		if( CheckAttribute(&Locations[locidx],"id.label") ) {
// rewritten by MAXIMUS 09.10.2006 [for correct location name showing]--> // KK -->
			if (CheckAttribute(&Locations[locidx], "townsack")) Preprocessor_Add("town_name", FindTownName(Locations[locidx].townsack));
			if (CheckAttribute(&Locations[locidx], "island"))
				curIsland = FindIslandName(Locations[locidx].island);
			else
				curIsland = FindIslandName(Islands[FindIslandBySeaLocation(GetCharacterShipLocation(PChar))].id);
			Preprocessor_Add("island_name", curIsland);
			curComma = GetSymbol(locLabel, strlen(locLabel)-1);
			if(curComma==".")
				locLabel = TranslateString("",strcut(locLabel,0,strlen(locLabel)-2));
			else
				locLabel = TranslateString("",locLabel);
			locLabel = curIsland + ". " + PreprocessText(Locations[FindLocation(PChar.location)].id.label);
			Preprocessor_Remove("town_name");
			Preprocessor_Remove("island_name");
// rewritten by MAXIMUS 09.10.2006 [for correct location name showing]<-- // <-- KK
		}
	}
	else
	{
		locLabel = TranslateString("","Open Sea");
	}
	// boal -->
	//for(int i = 0; i < 4; i++) { if(GetOfficersIndex(PChar,i) != -1) locLabel += " " + Characters[GetOfficersIndex(PChar,i)].faceID; }
	//LanguageCloseFile(tmpLangFileID);
	return locLabel +" "+ GetHumanDate(GetDataYear(),GetDataMonth(),GetDataDay());
	// boal <--
}

string GetClampedSaveName(string sInName, int nNumber)
{
	if(GetTargetPlatform()!="xbox")
	{
		if(nNumber>0) {return sInName + " " + nNumber;}
		else {return sInName;}
	}

	string retStr = sInName;
	int nLen = strlen(sInName)+1;
	int n = nNumber;
	int nAdd = 0;
	if(n>0) nAdd=1;
	while(n>0)
	{
		nAdd++;
		n = n/10;
	}
	if(nLen+nAdd>30)
	{
		int lastNum = nLen - sInName
		retStr = strcut(sInName,0,30-nAdd);
	}

	if(nNumber>0) retStr += " " + nNumber;
	return retStr;
}

bool CheckLimited()
{
	if(nCurScroll>0) return true;
	if(!CheckAttribute(&GameInterface,"saveslist.pic1.descr") || GameInterface.saveslist.pic1.descr!="")
	{
		if(sti(GameInterface.saveslist.ListSize)>MAX_SAVE_GAME_LIMIT)
		{
			SetNodeUsing("LOWSTORAGE_WINDOW",true);
			return false;
		}
		else { return true; }
	}

	return true;
}

// KK -->
void StartSelectProfileScreen()
{
	SetNodeUsing("SAVESLIST", false);
	SetNodeUsing("LEFTSCROLLBUTTON", false);
	SetNodeUsing("RIGHTSCROLLBUTTON", false);
	SetNodeUsing("CENTERRECTANGLE", false);
	SetNodeUsing("CENTERBOUND", false);
	SetNodeUsing("FACE1", false);
	SetNodeUsing("FACE2", false);
	SetNodeUsing("FACE3", false);
	SetNodeUsing("FACE4", false);
	SetNodeUsing("PROFILES_BUTTON", false);
	SetNodeUsing("LOAD_BUTTON", false);
	SetNodeUsing("DEL_BUTTON", false);
	SetNodeUsing("CANCEL_BUTTON", false);
	DisableString("SaveName");
	DisableString("Storyline_Profile");

	bool btmp = false;
	int i;
	int q = 0;
	int slqty = GetStorylinesQuantity();
	for (i = 0; i < slqty; i++)
	{
		if (GetProfilesQuantity(GetStoryline(i)) > 0) q++;
		if (q > 1) {
			btmp = true;
			break;
		}
	}

	GameInterface.strings.ScreenTitle = XI_ConvertString("titleGameProfile");
	SetNodeUsing("PROFILESRECTANGLE", true);
	SetNodeUsing("PROFILESBOUND", true);
	EnableString("Storyline_selection");
	GameInterface.strings.StorylineTitle = GetStorylineTitle(iShowStoryline);
	EnableString("StorylineTitle");
	SetNodeUsing("STORYLINES_BACKGROUND", true);
	SetNodeUsing("STORYLINES_RAMKA", true);
	SetNodeUsing("STORYLINES", btmp);
	string storyline = GetStoryline(iShowStoryline);
	int pq = GetProfilesQuantity(storyline) + 1;
	int curprofile = 1;
	profiles_list_start = 1;
	for (i = 1; i <= PROFILE_LIST_SIZE; i++)
	{
		string nodes = "B_PROFILE" + i;
		if (i < pq) {
			string profile = GetProfileName(storyline, i);
			if (profile == sCurProfile) curprofile = i;
			string lbl = FirstLetterUp(profile);
			SetNodeUsing(nodes, true);
			nodes = "ProfileName" + i;
			GameInterface.strings.(nodes) = lbl;
			EnableString(nodes);
		} else {
			SetNodeUsing(nodes, false);
			nodes = "ProfileName" + i;
			DisableString(nodes);
		}
	}
	SetNodeUsing("PROFILESCROLL", pq > PROFILE_LIST_SIZE);
	if (GetSelectable("PROFILESCROLL")) SendMessage(&GameInterface, "lsf", MSG_INTERFACE_SET_SCROLLER, "PROFILESCROLL", 0.0);
	ShowProfile(curprofile);
	SetNodeUsing("PROFILELOAD_BUTTON", true);
	SetNodeUsing("PROFILEDELETE_BUTTON", true);
	SetNodeUsing("PROFILECANCEL_BUTTON", true);
	SetCurrentNode("PROFILELOAD_BUTTON");
}

void StartActiveProfileScreen()
{
	SetNodeUsing("SAVESLIST", false);
	SetNodeUsing("LEFTSCROLLBUTTON", false);
	SetNodeUsing("RIGHTSCROLLBUTTON", false);
	SetNodeUsing("CENTERRECTANGLE", false);
	SetNodeUsing("CENTERBOUND", false);
	SetNodeUsing("FACE1", false);
	SetNodeUsing("FACE2", false);
	SetNodeUsing("FACE3", false);
	SetNodeUsing("FACE4", false);
	SetNodeUsing("PROFILES_BUTTON", false);
	SetNodeUsing("LOAD_BUTTON", false);
	SetNodeUsing("SAVE_BUTTON", false);
	SetNodeUsing("DEL_BUTTON", false);
	SetNodeUsing("CANCEL_BUTTON", false);
	DisableString("SaveName");
	DisableString("Storyline_Profile");

	bool btmp = false;
	int i;
	int q = 0;
	if (GetProfilesQuantity(GetStoryline(FindCurrentStoryline())) > 0) q++;
	if (q > 1) btmp = true;

	GameInterface.strings.ScreenTitle = XI_ConvertString("titleGameProfile");
	SetNodeUsing("PROFILESRECTANGLE", true);
	SetNodeUsing("PROFILESBOUND", true);
	EnableString("Storyline_selection");
	GameInterface.strings.StorylineTitle = GetStorylineTitle(FindCurrentStoryline());
	EnableString("StorylineTitle");
	SetNodeUsing("STORYLINES_BACKGROUND", true);
	SetNodeUsing("STORYLINES_RAMKA", true);
	SetNodeUsing("STORYLINES", btmp);
	string storyline = GetStoryline(FindCurrentStoryline());
	int pq = GetProfilesQuantity(storyline) + 1;
	int curprofile = 1;
	profiles_list_start = 1;
	for (i = 1; i <= PROFILE_LIST_SIZE; i++)
	{
		string nodes = "B_PROFILE" + i;
		if (i < pq) {
			string profile = GetProfileName(storyline, i);
			if (profile == sCurProfile) curprofile = i;
			string lbl = FirstLetterUp(profile);
			SetNodeUsing(nodes, true);
			nodes = "ProfileName" + i;
			GameInterface.strings.(nodes) = lbl;
			EnableString(nodes);
		} else {
			SetNodeUsing(nodes, false);
			nodes = "ProfileName" + i;
			DisableString(nodes);
		}
	}
	SetNodeUsing("PROFILESCROLL", pq > PROFILE_LIST_SIZE);
	if (GetSelectable("PROFILESCROLL")) SendMessage(&GameInterface, "lsf", MSG_INTERFACE_SET_SCROLLER, "PROFILESCROLL", 0.0);
	ShowProfile(curprofile);
	SetNodeUsing("PROFILELOAD_BUTTON", true);
	SetNodeUsing("PROFILEDELETE_BUTTON", false);
	SetNodeUsing("PROFILECANCEL_BUTTON", true);
	SetSelectable("PROFILELOAD_BUTTON",  true);
	SetCurrentNode("PROFILELOAD_BUTTON");
}

void ShowProfile(int btnidx)
{
	string storyline = GetStoryline(iShowStoryline);
	int pq = GetProfilesQuantity(storyline) + 1;
trace("ShowProfile: orig btnidx="+btnidx);
	btnidx = btnidx + (profiles_list_start - 1);
trace("ShowProfile: prop btnidx="+btnidx);
	string profile = GetProfileName(storyline, btnidx);
	sShowProfile = profile;
	for (int i = 1; i <= PROFILE_LIST_SIZE; i++) {
		if (i + (profiles_list_start - 1) < pq && i + (profiles_list_start - 1) != btnidx) {
			SetNodeUsing("B_PROFILE" + i, true);
			ChangeStringColor("ProfileName" + i, COLOR_NORMAL);
		} else {
			SetNodeUsing("B_PROFILE" + i, false);
			ChangeStringColor("ProfileName" + i, COLOR_DESELECT);
		}
	}
	SetNodeUsing("PROFILEFACE", true);
	int pic = -1;
	string offic = "";
	FindProfileMainChar(storyline, profile, &pic, &offic);
	if (pic >= 0) {
		GameInterface.PROFILEFACE.pic1.str2 = "#" + offic;
		GameInterface.PROFILEFACE.pic1.img1 = "face";
		AddFaceGroup("PROFILEFACE.ImagesGroup", "FACE128_" + pic);
		GameInterface.PROFILEFACE.pic1.tex1 = FindFaceGroupNum("PROFILEFACE.ImagesGroup", "FACE128_" + pic);
	} else {
		GameInterface.PROFILEFACE.pic1.str2 = "";
		GameInterface.PROFILEFACE.pic1.img1 = "emptyface";
		if (bNewInterface) GameInterface.PROFILEFACE.pic1.img1 = "emptyface_new";
		GameInterface.PROFILEFACE.pic1.tex1 = 0;
	}
	SendMessage(&GameInterface, "ls", MSG_INTERFACE_REFRESH_SCROLL, "PROFILEFACE");
	string lbl = FirstLetterUp(profile);
	GameInterface.strings.ProfileTitle = lbl;
	EnableString("ProfileTitle");
	lbl = TranslateString("", "Number of saved games") + ": " + GetProfileSavesQuantity(storyline, profile);
	GameInterface.strings.ProfileSaves = lbl;
	EnableString("ProfileSaves");
	if (iShowStoryline == iCurStoryline)
		SetSelectable("PROFILELOAD_BUTTON",  sShowProfile != sCurProfile);
	else
		SetSelectable("PROFILELOAD_BUTTON",  true);
}

void EndSelectProfilesScreen()
{
	SetNodeUsing("PROFILESRECTANGLE", false);
	SetNodeUsing("PROFILESBOUND", false);
	DisableString("Storyline_selection");
	DisableString("StorylineTitle");
	SetNodeUsing("STORYLINES_BACKGROUND", false);
	SetNodeUsing("STORYLINES_RAMKA", false);
	SetNodeUsing("STORYLINES", false);
	for (int i = 1; i <= PROFILE_LIST_SIZE; i++)
	{
		string nodes = "B_PROFILE" + i;
		SetNodeUsing(nodes, false);
		nodes = "ProfileName" + i;
		DisableString(nodes);
	}
	SetNodeUsing("PROFILESCROLL", false);
	SetNodeUsing("PROFILEFACE", false);
	DisableString("ProfileTitle");
	DisableString("ProfileSaves");
	SetNodeUsing("PROFILELOAD_BUTTON", false);
	SetNodeUsing("PROFILEDELETE_BUTTON", false);
	SetNodeUsing("PROFILECANCEL_BUTTON", false);

	if (bThisSave) // SCREWFACE
		GameInterface.strings.ScreenTitle = XI_ConvertString("titleSave");
	else
		GameInterface.strings.ScreenTitle = XI_ConvertString("titleLoad");

	SetNodeUsing("SAVESLIST", true);
	SetNodeUsing("LEFTSCROLLBUTTON", true);
	SetNodeUsing("RIGHTSCROLLBUTTON", true);
	SetNodeUsing("CENTERRECTANGLE", true);
	SetNodeUsing("CENTERBOUND", true);
	SetNodeUsing("FACE1", true);
	SetNodeUsing("FACE2", true);
	SetNodeUsing("FACE3", true);
	SetNodeUsing("FACE4", true);
	SetNodeUsing("PROFILES_BUTTON", true);
	if(!bThisSave) // Screwface
		SetNodeUsing("LOAD_BUTTON", true);
	else
		SetNodeUsing("SAVE_BUTTON", true);
	SetNodeUsing("DEL_BUTTON", true);
	SetNodeUsing("CANCEL_BUTTON", true);
	EnableString("SaveName");
	EnableString("Storyline_Profile");	
	SetCurrentNode("SAVESLIST");
	SetFirstButton(); // PB
}

void FindProfileMainChar(string storyline, string profile, ref pic, ref chname)
{
	int i = 0;
	int j = 0;
	string saveName;
	int nSaveSize;
	string saveString = "";
	string stmp;
	GameInterface.SavePath = "SAVE\" + GetStorylineDir(FindStoryline(storyline));
	pic = -1;
	chname = "";
	while (SendMessage(&GameInterface, "llee", MSG_INTERFACE_SAVE_FILE_FIND, j, &saveName, &nSaveSize) != 0) {
		if(!CheckSavedFile(saveName, storyline, profile)) {
			j++;
			continue;
		}
		saveString = IGetSaveString(GameInterface.SavePath + saveName);
		break;
	}
	if (!ParseSaveData(saveString, &pic, &chname, &stmp, &stmp, &stmp, &stmp, &stmp, &stmp, &stmp, &stmp, &stmp)) {
		pic = -1;
		chname = "";
	}
}

void UpdateLoadScreen(int slidx, string profile)
{
	if (slidx < 0) return;
	string storyline = GetStoryline(slidx);
	int pidx = FindProfile(storyline, profile);
	if (pidx < 0) return;
	iCurStoryline = slidx;
	sCurProfile = profile;
	if(bThisSave) // Screwface
	{
		reactive_profile = true;
		bNightmareMode = false;
		DisableString("NoSave");
	}
	DeleteAttribute(&GameInterface, "SAVESLIST");
	FillScroll();
	SendMessage(&GameInterface, "ls", MSG_INTERFACE_REFRESH_SCROLL, "SAVESLIST");
	GameInterface.strings.Storyline_Profile = TranslateString("", "Storyline") + ": " + GetStorylineTitle(iCurStoryline) + ";  " + TranslateString("", "Profile") + ": " + FirstLetterUp(sCurProfile);
	Event("exitProfiles");
}

void DoChangeStorylineLeft()
{
	int sq = 0;
	while (sq == 0) {
		iShowStoryline--;
		if (iShowStoryline < 0) {
			iShowStoryline = GetStorylinesQuantity();
			continue;
		}
		sq = GetAnyProfileSavesQuantity(GetStoryline(iShowStoryline));
	}
	StartSelectProfileScreen();
}

void DoChangeStorylineRight()
{
	int slidx_max = GetStorylinesQuantity();
	int sq = 0;
	while (sq == 0) {
		iShowStoryline++;
		if (iShowStoryline >= slidx_max) {
			iShowStoryline = -1;
			continue;
		}
		sq = GetAnyProfileSavesQuantity(GetStoryline(iShowStoryline));
	}
	StartSelectProfileScreen();
}

void ProcessProfileDelete()
{
	bProfileDelete = true;
	bSaveConfirm = false;
	bLoadConfirm = false;

	SetNodeUsing("CONFIRM_RECTANGLE",true);
	SetNodeUsing("TEXTWINDOW",true);
	SetNodeUsing("TEXTWINDOW1", true);
	SetNodeUsing("CONFIRM_YES_BUTTON",true);
	SetNodeUsing("CONFIRM_NO_BUTTON",true);
	SetNodeUsing("DISKETS_PIC",true); //added by MAXIMUS
	SetCurrentNode("CONFIRM_NO_BUTTON");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "CONFIRM_NO_BUTTON");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "CONFIRM_YES_BUTTON");

	SetFormatedText("TEXTWINDOW", TranslateString("","Delete profile confirm"));
	if (iShowStoryline == iCurStoryline && sCurProfile == sShowProfile)
		SetFormatedText("TEXTWINDOW1", TranslateString("", "Storyline") + ": " + GetStorylineTitle(iShowStoryline) + ", " + TranslateString("", "Profile") + ": " + sShowProfile + GlobalStringConvert("newline") + TranslateString("", "Warning: this profile is currently active!"));
	else
		SetFormatedText("TEXTWINDOW1", TranslateString("", "Storyline") + ": " + GetStorylineTitle(iShowStoryline) + ", " + TranslateString("", "Profile") + ": " + sShowProfile);
	
}

void ProcScrollPosChange()
{
	float newPos = GetEventData();
	string storyline = GetStoryline(iShowStoryline);
	int pq = GetProfilesQuantity(storyline) + 1;
	profiles_list_start = makeint(makefloat(pq) * newPos) + 1;
	int max_profile = profiles_list_start + PROFILE_LIST_SIZE;
	if (max_profile > pq) {
		profiles_list_start = pq - PROFILE_LIST_SIZE;
		max_profile = pq;
	}
	int curprofile = 1;
	for (int i = 1; i <= PROFILE_LIST_SIZE; i++)
	{
		string nodes = "B_PROFILE" + i;
		string profile = GetProfileName(storyline, i + (profiles_list_start - 1));
		if (profile == sCurProfile) curprofile = i;
		string lbl = FirstLetterUp(profile);
		SetNodeUsing(nodes, true);
		nodes = "ProfileName" + i;
		GameInterface.strings.(nodes) = lbl;
		EnableString(nodes);

		int btnidx = FindProfile(storyline, sShowProfile);
		if (i + (profiles_list_start - 1) < pq && i + (profiles_list_start - 1) != btnidx) {
			SetNodeUsing("B_PROFILE" + i, true);
			ChangeStringColor("ProfileName" + i, COLOR_NORMAL);
		} else {
			SetNodeUsing("B_PROFILE" + i, false);
			ChangeStringColor("ProfileName" + i, COLOR_DESELECT);
		}
	}

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

string NextLeft(string curNod)
{
	switch(curNod)
	{
		case "SAVE_BUTTON":
			if(GetSelectable("CANCEL_BUTTON")) return "CANCEL_BUTTON";
			else return NextLeft("CANCEL_BUTTON");
		break;
		case "LOAD_BUTTON":
			if(GetSelectable("SAVE_BUTTON")) return "SAVE_BUTTON";
			else return NextLeft("SAVE_BUTTON");
		break;
		case "DEL_BUTTON":
			if(GetSelectable("LOAD_BUTTON")) return "LOAD_BUTTON";
			else return NextLeft("LOAD_BUTTON");
		break;
		case "CANCEL_BUTTON":
			if(GetSelectable("DEL_BUTTON")) return "DEL_BUTTON";
			else return NextLeft("DEL_BUTTON");
		break;
		case "PROFILES_BUTTON":
			if(GetSelectable("SAVE_BUTTON")) return "SAVE_BUTTON";
			else
			{
				if(GetSelectable("LOAD_BUTTON")) return "LOAD_BUTTON";
				else
				{
					if(GetSelectable("CANCEL_BUTTON")) return "CANCEL_BUTTON";
					else
					{
						if(GetSelectable("DEL_BUTTON")) return "DEL_BUTTON";
						else
						{
							if(GetSelectable("CANCEL_BUTTON")) return "CANCEL_BUTTON";
							else return NextDown("SAVE_BUTTON");
						}
					}
				}
			}
		break;
	}
	return " ";
}

string NextRight(string curNod)
{
	switch(curNod)
	{
		case "SAVE_BUTTON":
			if(GetSelectable("LOAD_BUTTON")) return "LOAD_BUTTON";
			else return NextRight("LOAD_BUTTON");
		break;
		case "LOAD_BUTTON":
			if(GetSelectable("DEL_BUTTON")) return "DEL_BUTTON";
			else return NextRight("DEL_BUTTON");
		break;
		case "DEL_BUTTON":
			if(GetSelectable("CANCEL_BUTTON")) return "CANCEL_BUTTON";
			else return NextRight("CANCEL_BUTTON");
		break;
		case "CANCEL_BUTTON":
			if(GetSelectable("SAVE_BUTTON")) return "SAVE_BUTTON";
			else return NextRight("SAVE_BUTTON");
		break;
		case "PROFILES_BUTTON":
			if(GetSelectable("SAVE_BUTTON")) return "SAVE_BUTTON";
			else
			{
				if(GetSelectable("LOAD_BUTTON")) return "LOAD_BUTTON";
				else
				{
					if(GetSelectable("CANCEL_BUTTON")) return "CANCEL_BUTTON";
					else
					{
						if(GetSelectable("DEL_BUTTON")) return "DEL_BUTTON";
						else
						{
							if(GetSelectable("CANCEL_BUTTON")) return "CANCEL_BUTTON";
							else return NextDown("SAVE_BUTTON");
						}
					}
				}
			}
		break;
		
	}
	return " ";
}

string NextDown(string curNod)
{
	switch(curNod)
	{
		case "SAVESLIST":
			if(GetSelectable("SAVE_BUTTON")) return "SAVE_BUTTON";
			else
			{
				if(GetSelectable("LOAD_BUTTON")) return "LOAD_BUTTON";
				else return NextDown("SAVE_BUTTON");
			}
		break;
		case "PROFILES_BUTTON":
			if(GetSelectable("CANCEL_BUTTON")) return "CANCEL_BUTTON";
			else
			{
				if(GetSelectable("SAVE_BUTTON")) return "SAVE_BUTTON";
				else
				{
					if(GetSelectable("LOAD_BUTTON")) return "LOAD_BUTTON";
					else
					{
						if(GetSelectable("CANCEL_BUTTON")) return "CANCEL_BUTTON";
						else return NextDown("DEL_BUTTON");
					}
				}
			}
		break;
	}
	return " ";
}

string NextUp(string curNod)
{
	switch(curNod)
	{
		case "PROFILES_BUTTON":
			if(GetSelectable("SAVESLIST")) return "SAVESLIST";
			else return NextUp("SAVESLIST");
		break;
		case "SAVE_BUTTON":
			if(GetSelectable("SAVESLIST")) return "SAVESLIST";
			else return NextUp("SAVESLIST");
		break;
		case "LOAD_BUTTON":
			if(GetSelectable("SAVESLIST")) return "SAVESLIST";
			else return NextUp("SAVESLIST");
		break;
		case "DEL_BUTTON":
			if(GetSelectable("PROFILES_BUTTON")) return "PROFILES_BUTTON";
			else return NextUp("PROFILES_BUTTON");
		break;
		case "CANCEL_BUTTON":
			if(GetSelectable("PROFILES_BUTTON")) return "PROFILES_BUTTON";
			else return NextUp("PROFILES_BUTTON");
		break;
	}
	return " ";
}
// added by MAXIMUS [for correct buttons selection] <--
