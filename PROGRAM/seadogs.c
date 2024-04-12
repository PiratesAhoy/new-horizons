#include "BuildSettings.h" // scheffnow
#include "InternalSettings.h" // where the more esoteric/programmerly things from BS.h got moved. NK 05-07-17

#include "storm-engine\layers.h"

#include "events.h"
#include "sulan_shipslog.c"
#include "globals.c"
#include "animals.c"
#include "camera.c"
#include "sea_ai\sea.c"
#include "ships\ships.c"
#include "Encounters\Encounters.c"
#include "worldmap\worldmap.c"
#include "locations\locations.c"
#include "Loc_ai\LAi_init.c"
#include "store\goods.h"
#include "cannons\cannons.c"
#include "nations\nations.c"
#include "particles.c"
#include "initinterface.c"
#include "characters\characters.c"
#include "interface\interface.h"
#include "store\storeutilite.c"
#include "dialog.c"
#include "quests\quests.c"
#include "islands\islands.c"
#include "reload.c"
#include "situations.c"
#include "battle_interface\loginterface.c"
#include "calendar.c"
#include "teleport.c"
#include "utils.c"
#include "ITEMS\items.h"
#include "ITEMS\itemLogic.c"
#include "ITEMS\items_utilite.c"
#include "sound\alias.c" // KK
#include "weather\WhrWeather.c"
#include "controls\controls.c"
#include "landencounters\landencounters.c"
#include "NK.c" // 05-07-03 NK for misc functions
#include "Reinit.c" // NK
#include "models\models.c" // scheffnow
#include "models\initModels.c" //scheffnow
#include "Characters\init\monks.c" // scheffnow
#include "CCCFunctions.c" // ccc
#include "CCCdirectsail.c" // ccc Jan07, directsail code
#include "elrapido.c" // El Rapido
#include "MAXIMUS_Functions.c" // MAXIMUS
#include "KB_routines.c"  // KBlack - to accomodate functions from other mods - initially for tuning ships mod
#include "Periods.c" // KK
#include "Screwface_functions.c" // Screwface
#include "Characters\officers.c"; //ASVS
#include "FCoHS\FCoHS_Main.c"; // Friendly Contact on High Seas Mod
#include "smuggling.c";	//Everything related to smuggling moved to here -Levis
#include "Characters\Leveling.c"; //Everything related to leveling move to this -Levis
#include "MrMyt92_code.c";
#include "compatibility.c";
#include "module_loader/module_loader.c"

extern void UpdateWorldMap();
extern void InitGoods();
extern void InitStores();
// OK, I'm putting the function in store.h rather than using loadsegment. 05-07-12 - extern void StoreInit();
extern void InitItems();
extern void InitCharactersTables();
extern void InitCharactersNames();
extern void InitCharactersNamesRu(); // added by MAXIMUS
//extern void CreateCharacters();
extern void ExecuteConsole(); // NK

extern void BothQuestComplete(string sQuestName);	// KK
extern void QuestComplete(string sQuestName);		// KK
extern void StartStoryLine();						// KK

// NK  so you see the defs that are in Utils.c -->
native float Bring2RangeNoCheck(float fMin1, float fMax1, float fMin2, float fMax2, float fValue);
native float Bring2Range(float fMin1, float fMax1, float fMin2, float fMax2, float fValue);
/*float Bring2Range(float fMin1, float fMax1, float fMin2, float fMax2, float fValue)
{
	if(fValue < fMin2) { fValue = fMin2; }
	if(fValue > fMax2) { fValue = fMax2; }
	float fDelta = (fValue - fMin2) / (fMax2 - fMin2);
	return fMin1 + fDelta * (fMax1 - fMin1);
}*/
native float Degree2Radian(float fDegree);
native float Clampf(float fValue);
/*float Clampf(float fClamp)
{
	if(fClamp > 1.0) return 1.0;
	if(fClamp < 0.0) return 0.0;
	return fClamp;
}*/
// NK <--
native int RDTSC_B();
native int RDTSC_E(int iRDTSC);
//int onesec; // NK for speedtests.

native int SetTexturePath(int iLevel, string sPath);
native int SetGlowParams(float fBlurBrushSize, int Intensivity, int BlurPasses);
native int RPrint(int x, int y, string sPrint);
native int GetTexture(string fileName);
native void ReleaseTexture(int texId);

#libriary "script_libriary_test"
#libriary "dx9render_script_libriary"

#event_handler(NEW_GAME_EVENT,"NewGame");
#event_handler(GAME_OVER_EVENT,"GameOverE");
#event_handler("Control Activation","ProcessControls");
#event_handler("MainMenuKey","ProcessMainMenuKey");
#event_handler("InterfaceKey","ProcessInterfaceKey");
#event_handler("CameraPosAng","ProcessCameraPosAng");
// NK 05-07-10 for now do with normal controls. - #event_handler("Cheat","ProcessCheat");
#event_handler("Control Activation","ProcessCheat");
#event_handler("SeaDogs_ClearSaveData", "ClearLocationsSaveData");

// KK -->
ref ResurrectingOfficiant;
bool bSuppressResurrection = false;
// <-- KK

// PB: Tortuga Ladies -->
ref TortugaDame1;
ref TortugaDame2;
ref TortugaDame3;
// PB: Tortuga Ladies <--

object Render;

void ProcessCheat()
{
	string sCheatName;
	ref mc;
	int rcPassengerID;
	ref rcPassenger;
	sCheatName = GetEventData();
	if (bKeyboardEnabled) return; // KK
	mc = GetMainCharacter();
	// NK 05-07-10 switch to using normal control activation -->
	if(ENABLE_CHEATMODE && HasSubStr(sCheatName, "Cheat"))
	{
		if(sti(GetStorylineVar(FindCurrentStoryline(), "DISABLE_CHEATMODE")) > 0) return;	//JRH

		sCheatName = strcut(sCheatName, 5, strlen(sCheatName)-1);
		// NK <--
		switch(sCheatName)
		{
			case "ScrollCharactersLeft":
				if(CheckAttribute(mc, "scrollchars"))
				{
					mc.scrollchars = sti(mc.scrollchars) - 1;
					if(sti(mc.scrollchars) < 0) mc.scrollchars = OFFICER_MAX + COMPANION_MAX - 2;
				}
				else
					mc.scrollchars = OFFICER_MAX + COMPANION_MAX - 2;

				while(Cheat_GetCharacterIndex(mc.scrollchars) == -1)
				{
					mc.scrollchars = sti(mc.scrollchars) - 1;
					if(sti(mc.scrollchars) < 0) mc.scrollchars = OFFICER_MAX + COMPANION_MAX - 2;
				}
				LogIt(TranslateString("","Selected character is") + " " + Cheat_ScrollCharacterName(mc.scrollchars));
			break;

			case "ScrollCharactersMain":
				mc.scrollchars = 0
				LogIt(TranslateString("","Selected character is") + " " + Cheat_ScrollCharacterName(mc.scrollchars));
			break;

			case "ScrollCharactersRight":
				if(CheckAttribute(mc, "scrollchars"))
				{
					mc.scrollchars = sti(mc.scrollchars) + 1;
					if(sti(mc.scrollchars) > OFFICER_MAX + COMPANION_MAX - 2) mc.scrollchars = 0;
				}
				else
					mc.scrollchars = 1;

				while(Cheat_GetCharacterIndex(mc.scrollchars) == -1)
				{
					mc.scrollchars = sti(mc.scrollchars) + 1;
					if(sti(mc.scrollchars) > OFFICER_MAX + COMPANION_MAX - 2) mc.scrollchars = 0;
				}
				LogIt(TranslateString("","Selected character is") + " " + Cheat_ScrollCharacterName(mc.scrollchars));
			break;

			case "God":
				if(!CheckAttribute(mc, "scrollchars"))				mc.scrollchars = 0;
				rcPassengerID =             Cheat_GetCharacterIndex(mc.scrollchars);
				if(Cheat_GetCharacterIndex(mc.scrollchars) == -1)	rcPassenger = mc;
				else												rcPassenger = GetCharacter(rcPassengerID);

				if(LAi_IsImmortal(rcPassenger))
				{
					LAi_SetImmortal(rcPassenger, false);
					Log_SetStringToLog(TranslateString("","God mode") + " " + XI_ConvertString("OFF") + " for " + Cheat_ScrollCharacterName(mc.scrollchars));
				}else{

					LAi_SetImmortal(rcPassenger, true);
					Log_SetStringToLog(TranslateString("","God mode") + " " + XI_ConvertString( "ON") + " for " + Cheat_ScrollCharacterName(mc.scrollchars));
				}
			break;

			case "LevelUp":
				if(!CheckAttribute(mc, "scrollchars"))				mc.scrollchars = 0;
				rcPassengerID =             Cheat_GetCharacterIndex(mc.scrollchars);
				if(Cheat_GetCharacterIndex(mc.scrollchars) == -1)	rcPassenger = mc;
				else												rcPassenger = GetCharacter(rcPassengerID);

				LevelUp_Cheat(rcPassenger, 1);
			break;

			case "FakeLevelUp":
				if(!CheckAttribute(mc, "scrollchars"))				mc.scrollchars = 0;
				rcPassengerID =             Cheat_GetCharacterIndex(mc.scrollchars);
				if(Cheat_GetCharacterIndex(mc.scrollchars) == -1)	rcPassenger = mc;
				else												rcPassenger = GetCharacter(rcPassengerID);

				LevelUp_Cheat(rcPassenger, 0);
			break;

			case "Gold":
				mc.money = sti(mc.money) + 100000;
				mc.wealth = sti(mc.wealth) + 10000;
				Log_SetStringToLog("+ 100000 " + XI_ConvertString("Gold") + " " + XI_Convertstring("for") + " " + Cheat_ScrollCharacterName(0));
				Log_SetStringToLog("+ 10000 " + XI_ConvertString("Wealth") + " " + XI_Convertstring("for") + " " + Cheat_ScrollCharacterName(0));
			break;

			case "Reputation":
				if(!CheckAttribute(mc, "scrollchars"))				mc.scrollchars = 0;
				rcPassengerID =             Cheat_GetCharacterIndex(mc.scrollchars);
				if(Cheat_GetCharacterIndex(mc.scrollchars) == -1)	rcPassenger = mc;
				else												rcPassenger = GetCharacter(rcPassengerID);

				if (sti(rcPassenger.reputation) >= 0 && sti(rcPassenger.reputation) <= 10)
				{
					rcPassenger.reputation = 15;
					Log_SetStringToLog(XI_ConvertString("Reputation") + " " + XI_ConvertString("set to") + " " + GetTranslatedReputationForSex(rcPassenger, "Bloody Terror")           + " for " + Cheat_ScrollCharacterName(mc.scrollchars));
					break;
				}
				if (sti(rcPassenger.reputation) >= 11 && sti(rcPassenger.reputation) <= 20) {
					rcPassenger.reputation = 25;
					Log_SetStringToLog(XI_ConvertString("Reputation") + " " + XI_ConvertString("set to") + " " + GetTranslatedReputationForSex(rcPassenger, "Swindler")                + " for " + Cheat_ScrollCharacterName(mc.scrollchars));
					break;
				}
				if (sti(rcPassenger.reputation) >= 21 && sti(rcPassenger.reputation) <= 30) {
					rcPassenger.reputation = 35;
					Log_SetStringToLog(XI_ConvertString("Reputation") + " " + XI_ConvertString("set to") + " " + GetTranslatedReputationForSex(rcPassenger, "Rascal")                  + " for " + Cheat_ScrollCharacterName(mc.scrollchars));
					break;
				}
				if (sti(rcPassenger.reputation) >= 31 && sti(rcPassenger.reputation) <= 40) {
					rcPassenger.reputation = 45;
					Log_SetStringToLog(XI_ConvertString("Reputation") + " " + XI_ConvertString("set to") + " " + GetTranslatedReputationForSex(rcPassenger, "Neutral")                 + " for " + Cheat_ScrollCharacterName(mc.scrollchars));
					break;
				}
				if (sti(rcPassenger.reputation) >= 41 && sti(rcPassenger.reputation) <= 50) {
					rcPassenger.reputation = 55;
					Log_SetStringToLog(XI_ConvertString("Reputation") + " " + XI_ConvertString("set to") + " " + GetTranslatedReputationForSex(rcPassenger, "Bloke")                   + " for " + Cheat_ScrollCharacterName(mc.scrollchars));
					break;
				}
				if (sti(rcPassenger.reputation) >= 51 && sti(rcPassenger.reputation) <= 60) {
					rcPassenger.reputation = 65;
					Log_SetStringToLog(XI_ConvertString("Reputation") + " " + XI_ConvertString("set to") + " " + GetTranslatedReputationForSex(rcPassenger, "Matey")                   + " for " + Cheat_ScrollCharacterName(mc.scrollchars));
					break;
				}
				if (sti(rcPassenger.reputation) >= 61 && sti(rcPassenger.reputation) <= 70) {
					rcPassenger.reputation = 75;
					Log_SetStringToLog(XI_ConvertString("Reputation") + " " + XI_ConvertString("set to") + " " + GetTranslatedReputationForSex(rcPassenger, "Dashing")                 + " for " + Cheat_ScrollCharacterName(mc.scrollchars));
					break;
				}
				if (sti(rcPassenger.reputation) >= 71 && sti(rcPassenger.reputation) <= 80) {
					rcPassenger.reputation = 85;
					Log_SetStringToLog(XI_ConvertString("Reputation") + " " + XI_ConvertString("set to") + " " + GetTranslatedReputationForSex(rcPassenger, "Hero")                    + " for " + Cheat_ScrollCharacterName(mc.scrollchars));
					break;
				}
				if (sti(rcPassenger.reputation) >= 81 && sti(rcPassenger.reputation) <= 90) {
					rcPassenger.reputation = 5;
					Log_SetStringToLog(XI_ConvertString("Reputation") + " " + XI_ConvertString("set to") + " " + GetTranslatedReputationForSex(rcPassenger, "Horror of the High Seas") + " for " + Cheat_ScrollCharacterName(mc.scrollchars));
					break;
				}
			break;

			case "Worldmap":
				if(GetAttribute(mc,"worldmapencountersoff") == 1)
				{
					mc.worldmapencountersoff = "0";
					Log_SetStringToLog(TranslateString("","Worldmap encounters") + " " + XI_ConvertString("ON"));
				}
				else
				{
					mc.worldmapencountersoff = "1";
					Log_SetStringToLog(TranslateString("","Worldmap encounters") + " " + XI_ConvertString("OFF"));
				}
			break;
		}
	}
}

object Camera;

void ProcessCameraPosAng()
{
	Camera.Pos.x = GetEventData();
	Camera.Pos.y = GetEventData();
	Camera.Pos.z = GetEventData();

	Camera.Ang.x = GetEventData();
	Camera.Ang.y = GetEventData();
	Camera.Ang.z = GetEventData();
}

void proc_break_video()
{
//	trace("proc_break_video()");
	InterfaceStates.videoIdx = -1;
	Event("ievntEndVideo");
}

void Main()
{
	InterfaceStates.Launched = false;
//	LocationTestProcess();
//	return;

	ReloadProgressStart();

	LoadModules();
	ReloadProgressUpdate();

	// PB: Log Build Version to File -->
	trace("----------------------------------------");
	trace("Build " + Modules.core.version);
	trace("Savegame Compatibility: " + IS_SGV);
	trace("----------------------------------------");
	trace("");
	// PB: Log Build Version to File <--

	Trace("Gauging: StartGauging");
	// NK speedtest calculate number of ticks in one second: 05-05-02
	/*int iRDTSC_main = RDTSC_B();
	SystemDelay(1000);
	onesec = RDTSC_E(iRDTSC_main);*/
	// NK <--

	ControlsInit(GetTargetPlatform(),true);
	nTeleportLocation = 1;
	sTeleportLocName = "Oxbay_port";

// KK -->
	LogsToggle = LOG_NORMAL;

	trace("Gauging: starting init");

	if (!IsEntity(GameInterface)) {
		if(LoadSegment("Interface\BaseInterface.c"))
		{
			InitBaseInterfaces_main();
			InitBaseInterfaces();
			UnloadSegment("Interface\BaseInterface.c");
			trace("Gauging: interface");
		}
	}

	InitProfiles();
	trace("Gauging: Profiles");

	BS_Reinit();
// <-- KK

	SetEventHandler("Control Activation","proc_break_video",0);
	SetEventHandler(EVENT_END_VIDEO,"Main_LogoVideo",0);
	InterfaceStates.videoIdx = 0;
	PostEvent(EVENT_END_VIDEO, 1);
	ReloadProgressEnd();
}

void Main_LogoVideo()
{

	int i = sti(InterfaceStates.videoIdx);
	trace("Main_LogoVideo() " + i);
	switch(i)
	{
//	case 0:
//		{
//			InterfaceStates.videoIdx = 1;
//			StartPostVideo("PiratesAhoyLogo",1);
//			return;
//		}
//	break;

//	case 1:
//		{
//			InterfaceStates.videoIdx = 2;
//			StartPostVideo("WaltDisneyLogo",1);
//			return;
//		}
//	break;
//
//	case 2:
//		{
//			InterfaceStates.videoIdx = 3;
//			StartPostVideo("AkellaLogo",1);
//			return;
//		}
//	break;
//
//	case 3:
//		{
//			InterfaceStates.videoIdx = 4;
//			StartPostVideo("BethesdaLogo",1);
//			return;
//		}
//	break;
	}

	DelEventHandler(EVENT_END_VIDEO,"Main_LogoVideo");
	DeleteClass(&aviVideoObj);
	Event("DoInfoShower","sl","game prepare",true);
	SetEventHandler("frame","Main_Start",1);
}
//*/

void Main_Start()
//void Main()
{
	ReloadProgressStart();

	DelEventHandler("frame","Main_Start");

	if( GetTargetPlatform()=="pc" )	ControlsInit(GetTargetPlatform(),false);
/*
	ControlsInit(GetTargetPlatform(),false);

	nTeleportLocation = 1;
	sTeleportLocName = "Falaise_de_fleur_port_01";
	sTeleportLocName = "Oxbay_port";

	NationsInit();
	EncountersInit();
	CannonsInit();
	ShipsInit();
	IslandsInit();
	WeatherInit();
	InitPerks();

	if(LoadSegment("store\initGoods.c"))
	{
		InitGoods();
		UnloadSegment("store\initGoods.c");
	}

	if(LoadSegment("Interface\BaseInterface.c"))
	{
		InitBaseInterfaces_main();
		InitBaseInterfaces();
		UnloadSegment("Interface\BaseInterface.c");
	}

	if(LoadSegment("Characters\Characters_names.c"))
	{
		InitCharactersNames();
		UnloadSegment("Characters\Characters_names.c");
	}

*/

	ReloadProgressUpdate();

	SetCurrentTime(CharHour, CharMinute);
	SetCurrentDate(CharDay, CharMonth, CharYear);

	Trace("Gauging: initgame start");
	InitGame();
	Trace("Gauging: initgame done");
	ReloadProgressUpdate();

	CheckStorylines(); // KK

	InterfaceStates.Buttons.Load.enable = true;

	Event("DoInfoShower","sl","game prepare",false);

	GetInterfaceParameters(); // added by MAXIMUS
	GetLanguageParameters(); // added by MAXIMUS

	// PB: Catch Erroneous Install -->
	if (FindFile("RESOURCE", "*", "build14_beta4_final") == "")
	{
		LaunchInstallError();
	}
	else
	{
		LaunchMainMenu();
	}
	// PB: Catch Erroneous Install <--

	//LaunchLoadGame();

	//SetMainCharacterIndex(1);
	//LoadMainCharacterInFirstLocation("Oxbay_town", "", "");

	ReloadProgressEnd();
}

void SaveGame()
{
	string savePath = GetEventData(); // KK
	string saveName = GetEventData();//MAXIMUS: looks like these changes are resolving troubles with save -[partially stolen from AOP]->
	string saveData = GetEventData();
	//Levis made this function so the postinit is paused when saving. After that, a small delay is taken so all currently running post init processes can finish up. Then the game is saved.
	PausePostInit();
	SetEventHandler("delay_save","SaveGame_continue",0);
	PostEvent("delay_save",20,"sss",savePath,saveName,saveData);
}

void SaveGame_continue()
{
	ref PChar = GetMainCharacter();
	DelEventHandler("evntSave","SaveGame");
	DelEventHandler("delay_save","SaveGame_continue"); //Levis
	string savePath = GetEventData(); // KK
	string saveName = GetEventData();//MAXIMUS: looks like these changes are resolving troubles with save -[partially stolen from AOP]->
	string saveData = GetEventData();
// KK -->
	string saveFullName = savePath + "\" + saveName;
	string storyline = GetStoryline(FindCurrentStoryline());

	// PB: Profile Check -->
	string sCurProfile = GetCurrentProfile(storyline);
	if(sCurProfile == "")	sCurProfile = GetAttribute(PChar, "profile");
	if(sCurProfile == "-1")	sCurProfile = DEFAULT_PROFILE_NAME;
	// PB: Profile Check <--

	string qsFileName = "-=" + sCurProfile + "=- QuickSave";
	string saveQSFullName = savePath + "\" + qsFileName;
// <-- KK
	PChar.savelang = GetInterfaceLanguage(); // MAXIMUS 20.08.2018 used for localization

	SaveEngineState(saveFullName);
	ISetSaveData(saveFullName, saveData);

// KK -->
	SaveEngineState(saveQSFullName);
	ISetSaveData(saveQSFullName, saveData);
// <-- KK

	PostEvent("DoInfoShower",1,"sl","save game",false);
	ClearScreenShoter();//MAXIMUS: looks like these changes are resolving troubles with save <-[partially stolen from AOP]-
// KK -->
	// Screwface
	if (HasSubStr(saveName, qsFileName))
	{
		if (FindFile(GameInterface.SavePath, "*", saveName) == "")
		{
			Log_SetStringToLog(TranslateString("","Quicksave") + ": " + TranslateString("","FAILED") + "!");
		}
		else
		{
			Log_SetStringToLog(TranslateString("","Quicksave") + ": " + TranslateString("","OK"));
		}
	}
	DeleteAttribute(PChar, "KrakenAttack");		// PB: Kraken Attack
	DeleteAttribute(PChar, "ship.speedburst");	// PB: Black Pearl & Queen Anne's Revenge
	DeleteAttribute(PChar, "savelang"); // MAXIMUS 20.08.2018 used for localization
// <-- KK
	ResumePostInit(); //Levis
}

void LoadGame()
{
	string saveName = GetEventData();

	DeleteEntities();
	ClearEvents();
	ClearPostEvents();

	CreateEntity(&LanguageObject,"obj_strservice");
	CreateEntity(&reload_fader, "fader");
	SetReloadImage(&reload_fader, "loading_game"); // KK
	SendMessage(&reload_fader, "lfl", FADER_IN, RELOAD_TIME_FADE_IN, true);
	ReloadProgressStart();
	ref pchar = GetMainCharacter(); // KK
	pchar.savegamename = saveName;
	SetEventHandler("frame","LoadGame_continue",1);
}

void LoadGame_continue()
{
// KK -->
	ref pchar = GetMainCharacter();
	DelEventHandler("frame","LoadGame_continue");
	LoadEngineState(PChar.savegamename);
	DeleteAttribute(PChar, "savegamename");
// <-- KK
	trace("Done loading");
}

void InterfaceDoExit()
{
	string segName = ""; // KK
	ref mchr = GetMainCharacter();
	DelEventHandler("frame","InterfaceDoExit");
	InterfaceStates.Launched=false;
	if(sti(InterfaceStates.doUnFreeze)==true)
	{
		SendMessage(&GameInterface,"l",MSG_INTERFACE_RELEASE);
		if(!IsEntity(&aviVideoObj))
		{
			if( bSeaActive && !bAbordageStarted )
			{
				LayerFreeze(SEA_REALIZE,false);
				LayerFreeze(SEA_EXECUTE,false);
			}
			else
			{
				LayerFreeze(REALIZE, false);
				LayerFreeze(EXECUTE, false);
			}
// KK -->
			if (CheckAttribute(mchr, "NationsRelations_PreviousNation")) {
				DeleteAttribute(mchr, "NationsRelations_PreviousNation");
				RefreshFlags();
			}
			CheckReloadAction(mchr, "");
			if (CheckAttribute(mchr, "BoxName")) DeleteAttribute(mchr, "BoxName.update");
			if (CheckAttribute(mchr, "activeItem")) DeleteAttribute(mchr, "activeItem.update");
			CheckCharacterAction();
// <-- KK
		}
		DeleteAttribute(&GameInterface,"");
	}
	switch(interfaceResultCommand)
	{
		case RC_INTERFACE_FORTCAPTURE_EXIT:
			ReloadAfterFortCapture();
			break;

		case RC_INTERFACE_DO_NOTHING:
			break;
		case RC_INTERFACE_MAIN_MENU_EXIT:
			break;
		case RC_INTERFACE_DO_LOAD_GAME:
			// PB: To Prevent Errors -->
			UnloadStorylineFile("", "SL_utils.c");
			UnloadStorylineFile("quests\", "both_reaction.c");
			UnloadStorylineFile("quests\", "quests_reaction.c");
			// PB: To Prevent Errors <--
			LaunchLoadGame();
			break;
		case RC_INTERFACE_DO_SAVE_GAME:
			LaunchSaveGame();
			break;

		case RC_INTERFACE_DO_OPTIONS:
			LaunchOptionScreen();
			break;
		case RC_INTERFACE_DO_CONTROLS:
			LaunchControlsScreen();
			break;
// added by MAXIMUS -->
		case RC_INTERFACE_DO_ABOUT_BUILD:
			LaunchAboutBuildScreen();
			break;
// added by MAXIMUS <--
		case RC_INTERFACE_DO_CREDITS:
			break;
		case RC_INTERFACE_DO_RESUME_GAME:
			break;
		case RC_INTERFACE_RANSACK_MAIN_EXIT:
			Return2SeaAfterAbordage();
			break;
		// boal Cabin 09.09.03 -->
		case RC_INTERFACE_CABIN_MAIN_EXIT:
			Return2SeaAfterDeck(); // KK
			break;
		// boal Cabin 09.09.03 <--

		// MAXIMUS deck -->
		case RC_INTERFACE_DECK_MAIN_EXIT:
			Return2SeaAfterDeck();
			break;
		case RC_INTERFACE_CREW_MAIN_EXIT:
			Return2SeaAfterDeck(); // KK
			break;
		// MAXIMUS deck <--

		case RC_INTERFACE_SELECT_STORYLINE_EXIT:
			DeleteEntities();
			ClearEvents();
			SetEventHandler("frame","NewGame",1);
			InterfaceStates.doUnFreeze = false;
			break;
// KK -->
		case RC_INTERFACE_DO_START:
			// PB: To Prevent Errors -->
			UnloadStorylineFile("", "SL_utils.c");
			UnloadStorylineFile("quests\", "both_reaction.c");
			UnloadStorylineFile("quests\", "quests_reaction.c");
			// PB: To Prevent Errors <--
			RefreshStorylines();
			LaunchSelectStoryline();
			break;

		case RC_INTERFACE_OPTIONSCREEN_EXIT:
			Event("DoInfoShower","sl","MainMenuLaunch",true);
			LaunchMainMenu();
			break;
// <-- KK
	}
}

void EngineLayersOffOn(bool on)
{
	on = !on;
	LayerFreeze(REALIZE,on);
	LayerFreeze(EXECUTE,on);
	if(!bAbordageStarted) { // KK
		LayerFreeze(SEA_REALIZE,on);
		LayerFreeze(SEA_EXECUTE,on);
	}
	//LayerFreeze(SUN_TRACE,on);
	//LayerFreeze(SEA_REFLECTION,on);
	//LayerFreeze(SHADOW,on);
	//LayerFreeze(SHIP_CANNON_TRACE,on);
	//LayerFreeze(HULL_TRACE,on);
	//LayerFreeze(MAST_SHIP_TRACE,on);
	//LayerFreeze(SAILS_TRACE,on);
}

string seadogs_saveFrom = "";

// KK -->
void OnSave()
{
	Set_inDialog_Attributes();//MAXIMUS: VERY strange, but it's needed
	seadogs_saveFrom = "";
	if (IsEntity(&worldMap)) {
		seadogs_saveFrom = "world map";		//Was "seadogs_sav From"  ccc mar20
		return;
	}
	if (bSeaActive) {
		seadogs_saveFrom = "sea";
		SaveAtSea();
		return;
	}
	int ldLoc = FindLoadedLocation();
	if (ldLoc < 0 || ldLoc >= nLocationsNum) {
		trace("OnSave() -> unknown character location");
		return;
	}
	seadogs_saveFrom = "location";
	SendMessage(&Locations[ldLoc], "l", MSG_LOCATION_SETCHRPOSITIONS);
	LAi_group_SaveInfo();
	PostEvent("SeaDogs_ClearSaveData", 200, "a", &Locations[ldLoc]);
}

void SaveAtSea()
{
	// Screwface : It seems that if we do a save at sea and a reload, we lost the current load of balls & gunpowder
	// This code save this charge to re-add it at the load at sea
	ref Pchar = GetMainCharacter();
	ref rCannon; makeref(rCannon,Cannon[GetCaracterShipCannonsType(Pchar)]);
	if(CANNONPOWDER_MOD)
	{
		int fireGunpowder = 0;
		if(CheckAttribute(rCannon,"gunpowder")) fireGunpowder = sti(rCannon.gunpowder)*sti(GetCannonCurQuantity(Pchar));
		Pchar.save.gunpowder = fireGunpowder;
	}
	Pchar.save.currentcharge = Pchar.Ship.Cannons.Charge.Type;
	Pchar.save.currentchargeqty = sti(GetCannonCurQuantity(Pchar));
	// Screwface : end

	SendMessage(&AIBalls, "l", MSG_MODEL_RELEASE);
	for (int i = 0; i < iNumShips; i++)
	{
		if (Ships[i] < 0) continue;
		ref rCharacter = GetCharacter(Ships[i]);
		if (!CheckAttribute(rCharacter, "Ship")) continue;
		ref rShip = GetShipByType(GetCharacterShipType(rCharacter));
		if (!CheckAttribute(rCharacter, "Ship.Masts")) continue;
		aref arMasts; makearef(arMasts, rCharacter.Ship.Masts);
		rCharacter.Ship.old.Masts = "";
		aref arOldMasts; makearef(arOldMasts, rCharacter.Ship.old.Masts);
		CopyAttributes(arOldMasts, arMasts);
	}
}
// <-- KK

void ClearLocationsSaveData()
{
	aref loc = GetEventData();
	if (!IsEntity(loc)) return; // Levis
	SendMessage(loc, "l", MSG_LOCATION_CLRCHRPOSITIONS);
}

int actLoadFlag = 0;
void OnLoad()
{
	actLoadFlag = 1;


	//NationsInit();
	ResetSound();

	//CreateClass("dummy");

	if(LoadSegment("Interface\BaseInterface.c"))
	{
		//InitBaseInterfaces_main();
		InitBaseInterfaces();
		UnloadSegment("Interface\BaseInterface.c");
	}

	ReloadProgressUpdate();

// KK -->
	//LoadProfileOptions();

	// PB: To Prevent Errors -->
	LoadStorylineFile("", "SL_utils.c");
	LoadStorylineFile("quests\", "both_reaction.c");
	LoadStorylineFile("quests\", "quests_reaction.c");
	// PB: To Prevent Errors <--

	ReloadProgressUpdate();
// <-- KK

	DialogsInit();
	//IslandsInit();
	//LocationInit();

	ReloadProgressUpdate();

	InitCharacterEvents();
	ReloadProgressUpdate();
	QuestsInit();
	ReloadProgressUpdate();
	InitTeleport();
	ReloadProgressUpdate();
	InitParticles();
	ReloadProgressUpdate();
	//ImportFuncTest();

// PB: Reinstated - Code responsible for randomizing character names found and disabled in MAXIMUS_functions.c function UpdateCharactersNames()
//	InterfaceStates.Buttons.New.enable = false;		// LDH can only start new game if you restart the program - 19Apr09
// (this is because initialization of a new game does not work correctly after having loaded a game!!!)

	InterfaceStates.Buttons.Resume.enable = true;
	InterfaceStates.Buttons.Save.enable = true;
	InterfaceStates.Buttons.Load.enable = true;

	// Reset active control group
	ResetActiveControls();

// KK -->
	switch (seadogs_saveFrom)
	{
		case "location":
			ref mainchar = GetMainCharacter();
			LoadMainCharacterInFirstLocation(mainchar.location, "reload", "", mainchar.location.from_sea); // KK
			int ldLoc = FindLoadedLocation();
			if(ldLoc >= 0)
			{
				SendMessage(&Locations[ldLoc], "l", MSG_LOCATION_TLPCHRPOSITIONS);
			}
		break;
		case "world map":
			wdmLoadSavedMap();
		break;
		case "sea":
			LoadAtSea();
		break;
		// default:
			Trace("Unknow seadogs_saveFrom == " + seadogs_saveFrom);
	}
// <-- KK

	//ReloadEndFade();
	EngineLayersOffOn(true);
	//NewGame();
	DialogRun = false;
	InterfaceStates.Launched = false;

	ReloadProgressUpdate();

	PerkLoad();

	ReloadProgressUpdate();

	// Screwface
	SaveGlobalOptions();
	InitProfiles(); // To avoid profiles which were created after the one we load, are not present in the load profile screen !
	// Screwface : end

	ReloadProgressEnd();

	ResetTimeToNormal(); // PB

	actLoadFlag = 0;
}

void NewGame()
{
	GetLanguageParameters();
	Trace("Gauging: start new game");
	bChangeNation = true;
	trace("bChangeNation set to 'true'");
	DeleteEntities();
	DelEventHandler("frame","NewGame");

	// PB: Storyline Specific Start New Game Screens -->
	string LoadingScreen = "Quest_"+GetStoryline(FindCurrentStoryline());
	string TextureFolder = "RESOURCE\Textures\Loading\"+ LanguageGetLanguage() +"\";
	ref model = ModelFromID(CharModel);
	if (CheckAttribute(model, "loadingScreen"))	LoadingScreen = model.loadingScreen;
	if(FindReloadPicture(LoadingScreen) == "") LoadingScreen = "new_game";//MAXIMUS 25.04.2019: method FindFile not works with localization
	// PB: Storyline Specific Start New Game Screens <--

	CreateEntity(&LanguageObject,"obj_strservice");
	CreateEntity(&reload_fader, "fader");
	SetReloadImage(&reload_fader, LoadingScreen); // KK
	SendMessage(&reload_fader, "lfl", FADER_IN, RELOAD_TIME_FADE_IN, true);

	SetEventHandler("frame","NewGame_continue",1);
}

void NewGame_continue()
{
	ReloadProgressStart();

	// NK only fully create characters _here_  05-04-07 to speed game start
	/*bool tmpbool = LogsToggle;
	LogsToggle = true;*/
	// PB CharactersInit();
	/*LogsToggle = tmpbool*/
	/*if(LoadSegment("characters\characters_init.c"))
	{
		bool tmpbool = LogsToggle;
		LogsToggle = true;
		CreateCharacters(); // NK add bool 05-04-07 to speed game start
		LogsToggle = tmpbool
		UnloadSegment("characters\characters_init.c");
	}*/
	// NK <--

	DelEventHandler("frame","NewGame_continue");

	if(LoadSegment("Interface\BaseInterface.c"))
	{
		InitBaseInterfaces();
		Trace("Gauging: ng iface");
		UnloadSegment("Interface\BaseInterface.c");
	}
	ReloadProgressUpdate();
// KK -->
	SetCurrentTime(CharHour, CharMinute);
	SetCurrentDate(CharDay, CharMonth, CharYear);

	//Levis Reinit Perks
	Trace("Gauging: perks");
	InitPerks();
	ReloadProgressUpdate();
	//Reinit officer types
	Trace("Gauging: officertypes");
	InitOfficerTypes();
	ReloadProgressUpdate();

	InitPeriods();
	SetCurrentPeriod(GetPeriodFromYear(CharYear));
	trace("Gauging: periods");
	ReloadProgressUpdate();

	SaveGlobalOptions();
// <-- KK

// PB -->
	trace("Gauging: nations");
	NationsInit();
	ReloadProgressUpdate();
	CharactersInit();
	trace("Gauging: characters");
	ReloadProgressUpdate();
// <-- PB
// KK -->
	ShipsInit();
	trace("Gauging: ships");
	ReloadProgressUpdate();
// <-- KK

	Trace("Gauging: ng initgame start");
	InitGame();
	ReloadProgressUpdate();
	Trace("Gauging: ng initgame stop");

	InterfaceStates.Buttons.Resume.enable = true;
	InterfaceStates.Buttons.Save.enable = true;
	InterfaceStates.Buttons.Load.enable = true;

// KK -->
	ref PChar = GetMainCharacter();

	// PB: To Prevent Errors -->
	LoadStorylineFile("", "SL_utils.c");
	LoadStorylineFile("quests\", "both_reaction.c");
	LoadStorylineFile("quests\", "quests_reaction.c");
	// PB: To Prevent Errors <--
	ReloadProgressUpdate();

	// do reinit up here 05-04-24
	Trace("Gauging: start reinit");
	Reinit(true, false); // 05-04-06 now do while still loading so we get nice reloadprogress update stuff...
	Trace("Gauging: reinit stop");
	if(sti(GetStorylineVar(FindCurrentStoryline(), "JACK_SPARROW")) < 1) GiveModel2Player(PChar.model, true); // PB: Ensure that you have your starting outfit available

	ReloadProgressUpdate();

	InitTownNationalities(); // PB
	InitRelations();
	trace("Gauging: initial relations");
	ReloadProgressUpdate();
	InitGroups();
	trace("Gauging: characters groups");
	ReloadProgressUpdate();
	InitIslandSmuggling();
	Trace("Gauging: smuggling");
	ReloadProgressUpdate();
	initCargos(5);
	Trace("Gauging: cargos");
	ReloadProgressUpdate();
	Trace("Gauging: load mch in first");

	if (LoadSegment(GetStorylinePath(FindCurrentStoryline()) + "StartStoryline.c")) {
		StartStoryLine();
		UnloadSegment(GetStorylinePath(FindCurrentStoryline()) + "StartStoryline.c");
	}
// <-- KK

	ResetSkillModifierAll(PChar); // PB
	Trace("Gauging: done load mch in first");
	ReloadProgressUpdate(); // NK

	CleanStorylineObject(); // KK

	ReloadProgressEnd();

// PB: Reinstated - Code responsible for randomizing character names found and disabled in MAXIMUS_functions.c function UpdateCharactersNames()
//	InterfaceStates.Buttons.New.enable = false; // Aconcagua, 2009-08-15: same as for loading, see LDH's change above
}

void InitGame()
{
	Trace("Gauging: createlayers");
	if(LoadSegment("store\initStore.c"))
	{
		InitStores();
		Trace("Gauging: stores");
		UnloadSegment("store\initStore.c");
	}
	InitSound();
	Trace("Gauging: sound");
	ReloadProgressUpdate();
	DeleteSeaEnvironment();
	Trace("Gauging: delete sea env");
// KK -->
	InitTownTable(true);
	trace("Gauging: towns");
	ReloadProgressUpdate();
	LocationInit();
	Trace("Gauging: locations");
	ReloadProgressUpdate();
	IslandsInit();
	Trace("Gauging: islands");
	ReloadProgressUpdate();
	wdmInit();
	trace("Gauging: wdmap");
	ReloadProgressUpdate();
// <-- KK
	//return;
	DialogsInit();
	Trace("Gauging: dialogs");
	ReloadProgressUpdate();
	InitTeleport();
	Trace("Gauging: teleport");
	ReloadProgressUpdate();
	InitParticles();
	Trace("Gauging: particles");
	ReloadProgressUpdate();

	if(LoadSegment("items\initItems.c"))
	{
		InitItems();
		Trace("Gauging: items");
		UnloadSegment("items\initItems.c");
	}

	ReloadProgressUpdate();
	/*bool tmp = LogsToggle;
	LogsToggle = false;
	CharactersInit(false);
	LogsToggle = tmp;
	Trace("Gauging: char");
	ReloadProgressUpdate();*/
	QuestsInit();
	Trace("Gauging: quests");
	ReloadProgressUpdate();
	SeaAIGroupsInit();
	Trace("Gauging: sea ai groups");
	ReloadProgressUpdate();
	InitQuestMapEncounters();
	Trace("Gauging: questmapenc");
	ReloadProgressUpdate();
	InitLandRandomEncounters();
	Trace("Gauging: landenc");
	ReloadProgressUpdate();
	// KK SetNextWeather("Blue Sky");
	//SetNextWeather("Violet Sky");
	ResetQuestMovie();
	ReloadProgressUpdate();
	LoadGlobalOptions();
	Trace("Gauging: load options");
// KK -->
	ReloadProgressUpdate();
	InitModels(true);
	trace("Gauging: models - Total number of models: " + MODEL_HIGH);
	ReloadProgressUpdate();
	Alias_Init();
	trace("Gauging: Aliases");
	ReloadProgressUpdate();
// <-- KK
	InfoShowSetting();
	Trace("Gauging: infoshow");
}

// NK make ranged sidestep 05-07-21 -->
#event_handler("sidestep_event", "SideStep_Proc");
void SideStepControl(float mag, bool onoff)
{
	//trace("Sidestep control, mag " + mag + ", onoff is " + onoff);
	ref pchar = GetMainCharacter();
	if(onoff)
	{
		if(!CheckAttribute(pchar, "sidestep"))
		{
			//trace("no sidestep yet");
			pchar.sidestep = mag;
			event("sidestep_event", "l", GetMainCharacterIndex());
		}
	}
	else
	{
		//trace("deleting sidestep");
		DeleteAttribute(&pchar, "sidestep");
	}
}

void SideStep_Proc()
{
	int idx = GetEventData();
	ref chr = GetCharacter(idx);
	if(sti(InterfaceStates.Launched) || dialogRun)
	{
		DeleteAttribute(&chr, "sidestep")
	}
	else
	{
		if(CheckAttribute(chr, "sidestep"))
		{
			Sidestep(&chr, stf(chr.sidestep), SIDESTEP_CHECK);
			postevent("sidestep_event", SIDESTEP_DELAY, "l", idx);
		}
	}
}
// NK <--

int counter = 0;
// KK -->
string key_cpcode = "";
// <-- KK

void ProcessControls()
{
	string ControlName = GetEventData();
	float basetime = 1.0;
	//trace("ProcessControls() : " + ControlName);
	//if(ControlName == "WhrPrevWeather")	{ Whr_LoadNextWeather(-1); }
	//if(ControlName == "WhrNextWeather")	{ Whr_LoadNextWeather(1); }
	//if(ControlName == "WhrUpdateWeather")	{ Whr_UpdateWeather(true); } // NK 04-09-21 add bool to Whr_UpdateWeather

	if (ControlName == "NK_Key_") return; // KK
	if (bDisableAllCommands) return; // KK

	if(ControlName == "Help") RunHelpChooser();

	ref PChar = GetMainCharacter(); // NK moved here
	if(bKeyboardEnabled) // NK keyboard 05-07-21
	{
		//trace("KB enabled, control is " + ControlName);
		bool keydone = false;
		bool update = true;
		string key = getsymbol(ControlName, strlen(ControlName)-1);
		if(hassubstr(ControlName, "NK_Key_"))
		{
			if (ControlName == "NK_KEY_DOT") key = "."; // KK
			KB_AddCharacter(key);
			keydone = true;
		}
// KK -->
		if (HasSubStr(ControlName, "NK_NP_")) {
			if (bKeyboardAlt == false) {
				KB_AddCharacter(key);
			} else {
				key_cpcode = key_cpcode + key;
			}
			keydone = true;
		}
// <-- KK
		if(!keydone)
		{
			switch(ControlName)
			{
// KK -->
				case "NK_KB_Shift_on": bKeyboardShift = !bKeyboardShift; keydone = true; break;
				case "NK_KB_Shift_off": bKeyboardShift = !bKeyboardShift; keydone = true; break;
				case "NK_KB_caps": bKeyboardShift = !bKeyboardShift; keydone = true; break;
				case "NK_KB_Control_on": bKeyboardControl = true; keydone = true; break;// MAXIMUS
				case "NK_KB_Control_off": bKeyboardControl = false; keydone = true; break;// MAXIMUS
				case "NK_KB_Alt_on":
					bKeyboardAlt = true;
					keydone = true;
				break;
				case "NK_KB_Alt_off":
					bKeyboardAlt = false;
					if (key_cpcode != "") {
						if (strlen(key_cpcode) > 3) key_cpcode = strcut(key_cpcode, strlen(key_cpcode) - 4, strlen(key_cpcode) - 1);
						int cpcode = sti(key_cpcode);
						Event("Control Activation", "s", "NK_Key_" + ChrFromCode(cpcode));
						key_cpcode = "";
					}
					keydone = true;
				break;
				case "NK_KB_left": KB_CursorLeft(); keydone = true; break;
				case "NK_KB_right": KB_CursorRight(); keydone = true; break;
				case "NK_KB_del": KB_DeleteCharacter(); keydone = true; break;
				case "NK_KB_ins": bKeyboardOverwriteMode = !bKeyboardOverwriteMode; KB_AddCharacter(""); keydone = true; break;
				case "NK_KB_home": KB_CursorHome(); keydone = true; break;
				case "NK_KB_end": KB_CursorEnd(); keydone = true; break;
// <-- KK
				case "NK_KB_back": KB_RemoveCharacter(); keydone = true; break;
				case "NK_KB_esc": Event("KB_Esc"); update = false; break;
				case "NK_KB_enter": Event("KB_End"); update = false; break;
			}
		}
		if(update) Event("KB_update");
		return;
	}

	string newitm, logstr; // KK
	bool interfaceNotLaunched = !CheckAttribute(InterfaceStates, "Launched") || sti(InterfaceStates.Launched) == false;
	if (dialogRun == false && dialogSelf == false && interfaceNotLaunched) {
		switch(ControlName)
		{
			// Scheffnow -->
			case "SCHEFFNOW_RUSH":
				if(CheckCharacterPerk(PChar,"Rush"))
				{
					ActivateCharacterPerk(PChar,"Rush");
				}
			break;
			// scheffnow <--

			// NK -->
			// 05-07-13 separate dialog key
			case "NK_DialogStart":
				if(CORPSEMODE!=2) break;//MAXIMUS: only CORPSEMODE = 2 makes a lootable corpses

				// if(bSeaActive && !bAbordageStarted) use that?
				if(FindLoadedLocation() != -1 && !sti(Interfacestates.Launched))
				{
					int tmpi = SendMessage(PChar,"ls",MSG_CHARACTER_EX_MSG,"FindDialogCharacter");
	// changed by MAXIMUS [now we are looting corpses without dialog file] -->
					ref chCorpse, lcn;
					//aref chCorpse;
	// added by MAXIMUS 21.07.2006 [corpses without any items and money will not be looted] -->
					aref testItems;
					string itmName = "";
					int it;
	// added by MAXIMUS 21.07.2006 [corpses without any items and money will not be looted] <--
					// TIH: Do once, not copy/pasted many times Sep3'06
					if(tmpi<0) { tmpi = LAi_FindNearestVisCharacter(PChar, 20); }
					if(tmpi>=0)
					{
						chCorpse = GetCharacter(tmpi);
						if(CheckAttribute(chCorpse,"corpse")==true)
						{
							if(chCorpse.dialog.filename == "corpse_dialog.c")
							// PB: To enable talking to corpses that don't have corpse_dialog.c set
							{
								// changed by MAXIMUS 21.07.2006 [corpses without any items and money will not be looted] -->
								if(!CheckAttribute(chCorpse,"Money")) chCorpse.Money = 0;
								DeleteAttribute(chCorpse,"Items.bladeX4");
								makearef(testItems,chCorpse.items);
								for(it=0; it<GetAttributesNum(testItems); it++)
								{
									itmName = GetAttributeName(GetAttributeN(testItems,it));
									if(GetCharacterItem(chCorpse,itmName)==0) DeleteAttribute(chCorpse,"Items."+itmName);
								}
								if(GetAttributesNum(testItems)==0 && sti(chCorpse.Money)==0) Log_SetStringToLog(TranslateString("","NoItems"));
								else
								{
									PlaySound("OBJECTS\shipcharge\sail_damage1.wav");
									bDeadExchange = true;
									LaunchCharacterItemChange(chCorpse);
								}
								// changed by MAXIMUS 21.07.2006 [corpses without any items will not be looted] <--
								lcn = &Locations[FindLocation(chCorpse.location)];
							//	if(CheckAttribute(lcn,"building") || CORPSEMODE < 2)
								if(CheckAttribute(lcn,"building") || CORPSEMODE < 3) // TIH lootable corpses adjustment Sep2'06
								{
									LAi_SetImmortal(chCorpse, false);
									ChangeCharacterAddressGroup(chCorpse, "None", "", "");
									PostEvent("RemoveCorpse", 100, "i", chCorpse);
								}
							}
							else
							{
								PChar.forcedlg = true;
								Event("dlgReady","l",tmpi);
							}
						}
					}
					// TIH <--
// changed by MAXIMUS [now we are looting corpses without dialog file] <--
				}
			break;

			case "ScreenCleaning":
// KK -->
				if (bSeaActive && !bAbordageStarted)
					BIVisible(!sti(InterfaceStates.BIVisible));
				else
					BLIVisible(!sti(InterfaceStates.BIVisible));
// <-- KK
			break;

			case "NK_Re-init": Reinit(false, true); break;

			case "NK_AlwaysRunToggle":
				if (!bSeaActive || bAbordageStarted)
				{
					SetAlwaysRun(!AlwaysRunToggle);
					if(AlwaysRunToggle) Log_SetStringToLog(TranslateString("","Always run is now on"));
					else Log_SetStringToLog(TranslateString("","Always run is now off"));
				}
				else
				{
					if(sti(GetAttribute(GetMainCharacter(), "clubhauling")) == 1 )
					{
						Characters[GetMaincharacterIndex()].clubhauling = -1;
						LogIt(TranslateString("","Clubhauling default direction set to PORT"));
					}
					else
					{
						Characters[GetMaincharacterIndex()].clubhauling = 1;
						LogIt(TranslateString("","Clubhauling default direction set to STARBOARD"));
					}
				}
			break;

			case "NK_LogsToggle":
// KK -->
				LogsToggle++;
				if (LogsToggle > LOG_VERBOSE) LogsToggle = LOG_QUIET;
				Log_SetStringToLog(TranslateString("", "Log level is now set to") + " " + LogsToggle + ", " + LogsToggleDescription());
				/*LogsToggle = !LogsToggle;
				if(LogsToggle) Log_SetStringToLog(TranslateString("","Various logs are now on")); //bugfix 04-08-28
				else Log_SetStringToLog(TranslateString("","Various logs are now off"));*/
// <-- KK
			break;

			case "executeconsole":
				if(LoadSegment("console.c"))
				{
					ExecuteConsole();
					UnloadSegment("console.c");
				}
			break;

			case "ShowDebugMenu":
				LaunchDebugMenu();
			break;

// added by MAXIMUS [for new C-III models, which have an animated sidestep] -->
			case "Sidestep_left_on":
				if(bSeaActive && !bAbordageStarted) break; // PB: Don't do this while sailing, but don't prevent it during boarding
				if(CheckAttribute(worldMap, "isLoaded") == true && worldMap.isLoaded == "true") break; // KK The same for Worldmap
				if(SIDESTEP_ENABLED)
				{
					SetEventHandler("DoStraif", "CharacterDoStraif", 0);
					Event("DoStraif", "il", pchar, -1);
				}
			break;
			case "Sidestep_right_on":
				if(bSeaActive && !bAbordageStarted) break; // PB: Don't do this while sailing, but don't prevent it during boarding
				if(CheckAttribute(worldMap, "isLoaded") == true && worldMap.isLoaded == "true") break; // KK The same for Worldmap
				if(SIDESTEP_ENABLED)
				{
					SetEventHandler("DoStraif", "CharacterDoStraif", 0);
					Event("DoStraif", "il", pchar, 1);
				}
			break;
			case "Sidestep_left_off":
				if(!StraifCharacter(PChar)) SideStepControl(SIDESTEP_DIST_LEFT, false);
			break;
			case "Sidestep_right_off":
				if(!StraifCharacter(PChar)) SideStepControl(SIDESTEP_DIST_RIGHT, false);
			break;
// added by MAXIMUS [for new C-III models, which have an animated sidestep] -->
	
			// JRH -->
			case "ChrFightMode":
				if(bSeaActive && !bAbordageStarted) break; // PB: Don't do this while sailing, but don't prevent it during boarding
				if(CheckAttribute( &Locations[FindLocation(GetAttribute(Pchar, "location"))],"noFight" ))
				{
					//do nothing of this
				}
				else
				{
					string weaponID = GetCharacterEquipByGroup(Pchar,GUN_ITEM_TYPE);
					aref weapon;
					Items_FindItem(weaponID, &weapon);

					float charge = stf(Pchar.chr_ai.charge);

					if(LAi_IsFightMode(PChar))
					{
						if(IsEquipCharacterByItem(PChar, "pistolmket"))
						{
							PostEvent("mket_on_back", 1000, "i", PChar);
						}

						if(IsEquipCharacterByItem(PChar, "blademketK"))
						{
							PostEvent("blademketK_as_gun", 1000, "i", PChar);
							PostEvent("mket_on_back", 1500, "i", PChar);	//if musket on hip
						}

						if(IsEquipCharacterByItem(PChar, "pistolmtoon"))
						{
							PostEvent("mtoon_on_back", 1000, "i", PChar);
						}

						if(IsEquipCharacterByItem(PChar, "pistolmketB"))
						{
							PostEvent("mketB_on_back", 1000, "i", PChar);
						}

						if(IsEquipCharacterByItem(PChar, "blademketB"))
						{
							PostEvent("blademketB_as_gun", 1000, "i", PChar);
							PostEvent("mketB_on_back", 1500, "i", PChar);	//if musket on hip
						}

						if(IsEquipCharacterByItem(PChar, "Arguebuse"))
						{
							PostEvent("Arguebuse_on_back", 1000, "i", PChar);
						}

						if(IsEquipCharacterByItem(PChar, "pistolbbuss"))
						{
							PostEvent("bbuss_on_back", 1000, "i", PChar);
						}

						if(IsEquipCharacterByItem(PChar, "pistol13"))
						{
							PostEvent("pistol13_on_back", 1000, "i", PChar);
						}

						if(IsEquipCharacterByItem(PChar, "Longrifle_C"))
						{
							PostEvent("Longrifle_C_on_back", 1000, "i", PChar);
						}
						
						if(IsEquipCharacterByItem(PChar, "Longrifle_H"))
						{
							PostEvent("Longrifle_H_on_back", 1000, "i", PChar);
						}

						if(IsEquipCharacterByItem(PChar, "Longrifle_W"))
						{
							PostEvent("Longrifle_W_on_back", 1000, "i", PChar);
						}

						if(IsEquipCharacterByItem(PChar, "portugize"))
						{
							PostEvent("portugize_on_back", 1000, "i", PChar);
						}

						if(IsEquipCharacterByItem(Pchar, "shield_hand"))
						{
							RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE );
							TakeItemFromCharacter(Pchar, "shield_hand");
							GiveItem2Character(Pchar, "shield_back");
							EquipCharacterByItem(Pchar, "shield_back");								
						}

						if(IsEquipCharacterByItem(PChar, "battleax"))
						{
							PostEvent("bax_on_back", 1000, "i", PChar);
						}
			
						if(IsEquipCharacterByItem(PChar, "witcher_steel-2") || IsEquipCharacterByItem(PChar, "witcher_steel-1") 
						|| IsEquipCharacterByItem(PChar, "witcher_steel") || IsEquipCharacterByItem(PChar, "witcher_steel+1") 
						|| IsEquipCharacterByItem(PChar, "witcher_steel+2") || IsEquipCharacterByItem(PChar, "witcher_steel+3"))
						{
							PostEvent("witcher_steel_on_back", 1000, "i", PChar);
						}

						PostEvent("mguns_reset_check", 1000, "i", PChar);	//JRH: shouldn't matter what kind of gun pchar is equipped with
					}
					else
					{
						if(IsEquipCharacterByItem(Pchar, "pistolmket"))
						{
							if(charge == 1.0)
							{
								PostEvent("mket_on_hip", 1000, "i", Pchar);
							}
							else
							{
								if(CheckCharacterItem(Pchar, "blade_mKnife"))
								{
									PostEvent("mketK_as_blade", 1000, "i", Pchar);
								}
							}
						}

						if(IsEquipCharacterByItem(Pchar, "pistolmtoon"))
						{
							if(charge == 1.0) PostEvent("mtoon_on_hip", 1000, "i", Pchar);	
						}

						if(IsEquipCharacterByItem(Pchar, "pistolmketB"))
						{
							if(charge == 1.0)
							{
								PostEvent("mketB_on_hip", 1000, "i", Pchar);
							}
							else PostEvent("mketB_as_blade", 1000, "i", Pchar);
						}

						if(IsEquipCharacterByItem(Pchar, "Arguebuse"))
						{
							if(charge == 1.0) PostEvent("Arguebuse_on_hip", 1000, "i", Pchar);
						}

						if(IsEquipCharacterByItem(Pchar, "pistolbbuss"))
						{
							if(charge == 1.0) PostEvent("bbuss_on_hip", 1000, "i", Pchar);
						}

						if(IsEquipCharacterByItem(Pchar, "pistol13"))
						{
							if(charge == 1.0) PostEvent("pistol13_on_hip", 1000, "i", Pchar);
						}

						if(IsEquipCharacterByItem(Pchar, "Longrifle_C"))
						{
							if(charge == 1.0) PostEvent("Longrifle_C_on_hip", 1000, "i", Pchar);
						}
						
						if(IsEquipCharacterByItem(Pchar, "Longrifle_H"))
						{
							if(charge == 1.0) PostEvent("Longrifle_H_on_hip", 1000, "i", Pchar);
						}

						if(IsEquipCharacterByItem(Pchar, "Longrifle_W"))
						{
							if(charge == 1.0) PostEvent("Longrifle_W_on_hip", 1000, "i", Pchar);
						}

						if(IsEquipCharacterByItem(Pchar, "portugize"))
						{
							if(charge >= 1.0) PostEvent("portugize_on_hip", 1000, "i", Pchar);
						}

						if(IsEquipCharacterByItem(Pchar, "pistolbow"))
						{
							int ar = GetCharacterItem(Pchar, "bladearrows");
							if(ar >= 1)
							{						
								if(!IsEquipCharacterByItem(Pchar, "bladearrows"))
								{
									RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE );
									EquipCharacterByItem(Pchar, "bladearrows");
								}
							}
						}

						if(IsEquipCharacterByItem(Pchar, "shield_back"))
						{
							RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE );
							TakeItemFromCharacter(Pchar, "shield_back");
							GiveItem2Character(Pchar, "shield_hand");
							EquipCharacterByItem(Pchar, "shield_hand");								
						}

						if(IsEquipCharacterByItem(PChar, "battleax"))
						{
							PostEvent("bax_on_hip", 10, "i", PChar);
						}
				
						if(IsEquipCharacterByItem(PChar, "witcher_steel-2") || IsEquipCharacterByItem(PChar, "witcher_steel-1") 
						|| IsEquipCharacterByItem(PChar, "witcher_steel") || IsEquipCharacterByItem(PChar, "witcher_steel+1") 
						|| IsEquipCharacterByItem(PChar, "witcher_steel+2") || IsEquipCharacterByItem(PChar, "witcher_steel+3"))
						{
							PostEvent("witcher_steel_on_hip", 10, "i", PChar);
						}
					}

					if(IsEquipCharacterByItem(Pchar, "LongRifle_BT"))
					{
						if(globalSGMode) // PB: Quest Gun can shoot infinitely
						{
							if(LAi_IsFightMode(PChar))
							{
								globalSGMode = false;
								LAi_SetFightMode(PChar, false);
							}
						}
						else
						{
							LAi_SetFightMode(PChar, true);
							globalSGMode = true;
							if(ENABLE_FREE_CAMERA)		locCameraCurMode = LOCCAMERA_TRANS; // Needed to return properly
							PlaySound("OBJECTS\duel\reload1.wav");
						}
					}

					if(IsEquipCharacterByItem(Pchar, "LongRifle_CT") || IsEquipCharacterByItem(Pchar, "LongRifle_WT"))
					{
						if(0 < LAi_GetCharacterChargeCur(Pchar)) // PB: Ammo Required
						{
							if(globalSGMode || LAi_IsFightMode(PChar))
							{
								globalSGMode = false;
								LAi_SetFightMode(PChar, false);
							}
							else
							{
								LAi_SetFightMode(PChar, true);
								globalSGMode = true;
								if(ENABLE_FREE_CAMERA)		locCameraCurMode = LOCCAMERA_TRANS; // Needed to return properly
								PlaySound("OBJECTS\duel\reload1.wav");
							}
						}
						else
						{
							if(LAi_IsFightMode(PChar))
							{
								if(IsEquipCharacterByItem(Pchar, "LongRifle_WT"))
								{
									LAi_QuestDelay("place_LR_WT_on_back", 1.0);
								}
								else
								{
									LAi_QuestDelay("place_LR_CT_on_back", 1.0);
								}
							}
							else
							{
								float GunCurCharge = LAi_GetCharacterRelCharge(Pchar); // Levis
								RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE );
								if(IsEquipCharacterByItem(Pchar, "LongRifle_WT"))
								{
									weapon.model = "LongRifle_WT";
									EquipCharacterByItem(Pchar, "LongRifle_WT");
								}
								else
								{
									weapon.model = "LongRifle_CT";
									EquipCharacterByItem(Pchar, "LongRifle_CT");
								}
								Pchar.chr_ai.charge = GunCurCharge; // Levis
								PlaySound("PEOPLE\clothes1.wav");
							}
						}
					}
				/*
					if(IsEquipCharacterByItem(Pchar, "LongRifle_C"))
					{
						if(LAi_IsFightMode(PChar))
						{
							LAi_QuestDelay("place_LR_C_on_back", 1.0);
						}
						else
						{
							LAi_QuestDelay("place_LR_C_on_hip", 1.0);
						}
					}
				*/
				/*
					if(IsEquipCharacterByItem(Pchar, "LongRifle_W"))
					{
						if(LAi_IsFightMode(PChar))
						{
							LAi_QuestDelay("place_LR_W_on_back", 1.0);
						}
						else
						{
							LAi_QuestDelay("place_LR_W_on_hip", 1.0);
						}
					}
				*/
				}
			break;
			// <-- JRH

			// PB: Control Camera Behaviour -->
			case "ChrCamCameraSwitch":
				if(bSeaActive && !bAbordageStarted)					break;				// PB: Don't do this while sailing, but don't prevent it during boarding

				if(LAi_IsFightMode(PChar) || globalSGMode)
				{
					weaponID = GetCharacterEquipByGroup(Pchar,GUN_ITEM_TYPE);
					if(HasSubStr(weaponID, "LongRifle"))			break;				// PB: Don't switch camera if using Long Rifle!
					if(CheckCharacterPerk(PChar, "ImproveAiming"))						// Levis: Enable first person shooting for every gun with the right perk
					{
						//Levis added check for loaded gun
						if(!globalSGMode && 0 < LAi_GetCharacterChargeCur(Pchar))
						{
							LAi_SetFightMode(PChar, false);
							LAi_QuestDelay("get_shot_gun_mode", 1.0);
						}else{
							globalSGMode = false;
							LAi_QuestDelay("get_sword_ready", 1.0);
						}
					}
				}
				else
				{
					if(ENABLE_FREE_CAMERA)														// Levis: We don't want to go in here if we are in shotgun mode or in fightmode
					{
						if(locCameraCurMode == LOCCAMERA_FOLLOW)	locCameraFree();
						else										locCameraFollow();
					}
				}
			break;
			// PB: Control Camera Behaviour <--

			// PB: Equip button -->
			case "Equip":
				if(bSeaActive && !bAbordageStarted) break; // PB: Don't do this while sailing, but don't prevent it during boarding
				// NK last edit 28-05-06; PB last edit 05-10-06
				// set up strings
				logstr = "";
				string errstr = "";

				// blade
				string olditm = GetCharacterEquipByGroup(&PChar, BLADE_ITEM_TYPE);
				newitm = FindCharacterItemByGroup(&PChar, BLADE_ITEM_TYPE);

				// TIH --> fixed equipping of swords for NON blade damage mod toggle Aug29'06
				// using quality is not needed, and gets in the way if you had a higher quality low sword equipped
				// even though you had a low quality higher sword in your inventory
				// if BLADEDAMAGE_ENABLED is ON, then it uses quality checks

				//int olditmqual = GetItemQualityByID(olditm); // TIH quality now checked when finding a valid new item
				//int newitmqual = GetItemQualityByID(newitm);
				if(newitm != olditm && newitm != "")
				{
					switch(GetItemQualityByID(newitm))
					{
						case 0: logstr += TranslateString("","a badly worn") + " "; break;
						case 1: logstr += TranslateString("","a worn") + " "; break;
						case 2: logstr += TranslateString("","an average") + " "; break;
						case 3: logstr += TranslateString("","a good") + " "; break;
						case 4: logstr += TranslateString("","a fine") + " "; break;
						case 5: logstr += TranslateString("","an excellent") + " "; break;
						// default:
						logstr += TranslateString("","a") + " ";
					}
					logstr += GetItemNameByID(newitm);
					EquipCharacterByItem(&PChar, newitm);
				}
				if(newitm == "" || newitm == "bladeX4")
				{
					errstr = XI_ConvertString("a sword");
				}

				/* older method
				int olditmqual = GetItemQualityByID(olditm);
				int newitmqual = GetItemQualityByID(newitm);
				bool shownoqual = false;
				if(newitmqual == -1)
				{
					newitmqual = 5;
					shownoqual = true;
				}
				if(newitm != olditm && newitmqual >= olditmqual && newitmqual != 0) // PB: Don't ever auto-equip broken blades
				{
					if(shownoqual)
					{
						if(newitm != "bladeX4") {logstr += XI_ConvertString("a")+" ";}
						shownoqual = false;
					}
					else
					{
						switch(newitmqual)
						{
							case 0: logstr += TranslateString("","a broken") + " "; break; // This line should never be used
							case 1: logstr += TranslateString("","a worn") + " "; break;
							case 2: logstr += TranslateString("","an average") + " "; break;
							case 3: logstr += TranslateString("","a good") + " "; break;
							case 4: logstr += TranslateString("","a fine") + " "; break;
							case 5: logstr += TranslateString("","an excellent") + " "; break;
						}
					}
					logstr += GetItemNameByID(newitm);
					EquipCharacterByItem(&PChar, newitm);
				}
				if(newitm == "" || newitm == "bladeX4") { errstr = XI_ConvertString("a sword"); }
				*/
				// TIH <--

				// gun
				olditm = GetCharacterEquipByGroup(&PChar, GUN_ITEM_TYPE);
				newitm = FindCharacterItemByGroup(&PChar, GUN_ITEM_TYPE);

				// TIH --> fixed equipping of guns Aug24'06
				// using quality is not needed, and gets in the way if you had a higher quality low gun equipped
				// even though you had a low quality higher gun in your inventory
				if(newitm != olditm && newitm != "")
				{
					if(logstr != "") logstr += " " + XI_ConvertString("and") + " ";
					switch(GetItemQualityByID(newitm))
					{
						case 0: logstr += TranslateString("","a badly worn") + " "; break;
						case 1: logstr += TranslateString("","a worn") + " "; break;
						case 2: logstr += TranslateString("","an average") + " "; break;
						case 3: logstr += TranslateString("","a good") + " "; break;
						case 4: logstr += TranslateString("","a fine") + " "; break;
						case 5: logstr += TranslateString("","an excellent") + " "; break;
						// default:
						logstr += TranslateString("","a") + " ";
					}
					logstr += GetItemNameByID(newitm);
					EquipCharacterByItem(&PChar, newitm);
				}
				if(newitm == "")
				{
					if(errstr != "") errstr += " " + XI_ConvertString("or") + " ";
					errstr += XI_ConvertString("a gun");
				}
				// TIH <--
				/* older method, which sort of broke a bit
				olditmqual = GetItemQualityByID(olditm);
				newitmqual = GetItemQualityByID(newitm);

				if(newitmqual == -1)
				{
					newitmqual = 5;
					shownoqual = true;
				}

				if(newitm != olditm && newitmqual >= olditmqual)
				{
					if(logstr != "") logstr += " " + XI_ConvertString("and") + " ";

					if(shownoqual)
					{logstr += XI_ConvertString("a")+" ";}
					else
					{
						switch(newitmqual)
						{
							case 0: logstr += TranslateString("","a badly worn") + " "; break;
							case 1: logstr += TranslateString("","a worn") + " "; break;
							case 2: logstr += TranslateString("","an average") + " "; break;
							case 3: logstr += TranslateString("","a good") + " "; break;
							case 4: logstr += TranslateString("","a fine") + " "; break;
							case 5: logstr += TranslateString("","an excellent") + " "; break;
						}
					}

					logstr += GetItemNameByID(newitm);
					EquipCharacterByItem(&PChar, newitm);
				}
				else
				{
					if(newitm == "")
					{
						if(errstr != "") errstr += " " + XI_ConvertString("or") + " ";
						errstr += XI_ConvertString("a gun");
					}
				}
				*/

				// glass
				olditm = GetCharacterEquipByGroup(&PChar, SPYGLASS_ITEM_TYPE);
				newitm = FindCharacterItemByGroup(&PChar, SPYGLASS_ITEM_TYPE);

				if(newitm != olditm && newitm != "")
				{
					if(logstr != "") logstr += " " + XI_ConvertString("and") + " ";
					logstr += XI_ConvertString("a")+" " + GetItemNameByID(newitm);
					EquipCharacterByItem(&PChar, newitm);
				}
				if(newitm == "")
				{
					if(errstr != "") errstr += " " + XI_ConvertString("or") + " ";
					errstr += XI_ConvertString("a spyglass");
				}

				// armor
				olditm = GetCharacterEquipByGroup(&PChar, ARMOR_ITEM_TYPE);
				newitm = FindCharacterItemByGroup(&PChar, ARMOR_ITEM_TYPE);
				if(olditm != newitm && newitm != "" && newitm != "cheaparmor")
				{
					if(logstr != "") logstr += " " + XI_ConvertString("and") + " ";
					logstr += GetItemNameByID(newitm);
					EquipCharacterByItem(&PChar, newitm);
				}
				if(newitm == "")
				{
					if(errstr != "") errstr += " " + XI_ConvertString("or") + " ";
					errstr += XI_ConvertString("any armor");
				}

				if (ENABLE_AMMOMOD)
				{// TIH --> mod toggle Jul15'06
				//JRH ammo mod start
					// powderflask
					olditm = GetCharacterEquipByGroup(&PChar, FLASK_ITEM_TYPE);
					newitm = FindCharacterItemByGroup(&PChar, FLASK_ITEM_TYPE);

					if(newitm != olditm && newitm != "")
					{
						if(logstr != "") logstr += " " + XI_ConvertString("and") + " ";
						logstr += XI_ConvertString("a Powder Flask");
						EquipCharacterByItem(&PChar, newitm);
					}
					if(newitm == "")
					{
						if(errstr != "") errstr += " " + XI_ConvertString("or") + " ";
						errstr += XI_ConvertString("s"+"a powder flask");
					}

					// ammopouch
					olditm = GetCharacterEquipByGroup(&PChar, POUCH_ITEM_TYPE);
					newitm = FindCharacterItemByGroup(&PChar, POUCH_ITEM_TYPE);

					if(newitm != olditm && newitm != "")
					{
						if(logstr != "") logstr += " " + XI_ConvertString("and") + " ";
						logstr += XI_ConvertString("an Ammunition Pouch");
						EquipCharacterByItem(&PChar, newitm);
					}
					if(newitm == "")
					{
						if(errstr != "") errstr += " " + XI_ConvertString("or") + " ";
						errstr += XI_ConvertString("s"+"an ammunition pouch");
					}
				// JRH -->
					int gp = GetCharacterItem(Pchar, "gunpowder");
					int pb = GetCharacterItem(Pchar, "pistolbullets");
					if(gp == 0)
					{
						//TakenItems(Pchar, "gunpowder", 1); //TakenItems(Pchar, "gunpowder", -1);
						DeleteAttribute(Pchar,"Items.gunpowder");
					}
					if(pb == 0)
					{
						//TakenItems(Pchar, "pistolbullets", 1); //TakenItems(Pchar, "pistolbullets", -1);
						DeleteAttribute(Pchar,"Items.pistolbullets");
					}
				// <-- JRH
				//JRH ammo mod end
				}// TIH <-- mod toggle

				// output
				if(logstr != "") { Logit(TranslateString("","You equipped") + " " + logstr + "."); }
				if(errstr != "") { Logit(TranslateString("","You don't have") + " " + errstr + " " + TranslateString("","to equip") + "."); }
			break;
			// PB: Equip button <--

			// PB: Steam Ships -->
			case "Ship_PowerUp":
				if(SteamShip(PChar) && bSeaActive && !bAbordageStarted)
				{
					PChar.Ship.Power = sti(GetAttribute(PChar,"Ship.Power")) + 25;
					if(sti(PChar.Ship.Power) > 100) PChar.Ship.Power = 100;
				}
			break

			case "Ship_PowerDown":
				if(SteamShip(PChar) && bSeaActive && !bAbordageStarted)
				{
					PChar.Ship.Power = sti(GetAttribute(PChar,"Ship.Power")) - 25;
					if(sti(PChar.Ship.Power) < -100) PChar.Ship.Power = -100;
				}
			break

			case "Ship_PowerZero":
				if(SteamShip(PChar) && bSeaActive && !bAbordageStarted)
				{
					PChar.Ship.Power = 0;
				}
			break
			// PB: Steam Ships <--

			// El Rapido Rapid Raid -->
			case "Rapid_Raid":
				if (ENABLE_CHEATMODE)
				{
					Promote_Cheat(PChar, GetServedNation());
				}
				else
				{
					PlaySound("OBJECTS\raid.wav");
					if(GetServedNation() != FRANCE)
						Rapid_Raid("Soldiers", 10, FRANCE, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "A French infantry unit suddenly appears and attacks you!", "French Musketeer", OFFIC_TYPE_GUARD, 0, true, "", "");
					else
						Rapid_Raid("Soldiers", 10, SPAIN, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "Several Conquistadores attack you!", "Conquistador", OFFIC_TYPE_GUARD, 0, true, "", "");
				}
			break;
			// El Rapido Rapid Raid <--

			// NK <--
			// TIH -->
			case "TIH_FireDrill":
				// ccc firedrill properly added under its own key now -tih
				if (!IsPerkIntoList("FireOnShip")) break; // KK

				// ccc firedrill
				if(bSeaActive == true && bAbordageStarted == false && FIREDAMAGE > 1) { // checks if you are in sailing mode MAR18
					Log_SetStringToLog(TranslateString("","All hands execute fire drill ! NOW !!")); // just a screenmessage
					if (FD_REQUIRE_DEFENCE == 0 || CheckOfficersPerk(PChar,"BasicDamageControl")) {
						// starts firedrill only if you have damage control ability
						// or this check is turned off in BS.h -tih
						PChar.firedrill = 1; // adds attribute to player as "marker" that firedrill is ordered
						if (IsPerkIntoList("FireOnShip")) DelPerkFromActiveList("FireOnShip"); // KK
						PlaySound("#clear_for_action"); // just soundeffect // KK
						PlaySound("objects\abordage\abordage_loosing.wav");
						Ship_SetSailState(GetMainCharacterIndex(), 0); // smoldering sails jettisoned MAR18 NK uses index not ref. 05-04-20
						if (GUN_DOUSING == 1) {
							Ship_ChangeCharge(PChar, sti(PChar.Ship.Cannons.Charge.Type)); // cartridges jettisoned MAR18
							Log_SetStringToLog(TranslateString("","Sails and cartridges jettisoned.")); // MAR18
						}
					} else {
						Log_SetStringToLog(TranslateString("","Captain, what's a firedrawl?"));	// just a screenmessage
						Log_SetStringToLog(TranslateString("","Your crew seems to lack the SHIP DEFENCE ability..."));	// just a screenmessage
						PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_b_079.wav");	// just soundeffect
					}
				}
				// ccc firedrill end, original potion-use mod put with its original key -tih
			break;
			// TIH <--

			// boal -->
			case "BOAL_UsePotion":
				if (LAi_GetCharacterHP(PChar) >= LAi_GetCharacterMaxHP(PChar)) break; // KK
				int idx = -1;
				if(USEMAXPOTION_ONKEYPRESS)
					MaxHealthPotionForCharacter(PChar, &idx);
				else
					MinHealthPotionForCharacter(PChar, &idx);
				if(idx != -1)
				{
					DoCharacterUsedItem(PChar, Items[idx].id);
					Log_SetStringToLog(TranslateString("","Used potion"));
				}
				// NK <--
			break;

			// PB: Simplified Time Compression Controls -->
			case "BOAL_Control":
				switch(GetTimeScale())
				{
					case  0: PChar.basetime =  1; break;		// New values by El Rapido
					case  1: PChar.basetime =  3; break;
					case  3: PChar.basetime =  5; break;
					case  5: PChar.basetime = 10; break;
					case 10: PChar.basetime = 20; break;
				}
				UpdateTimeScale();
				LogIt(XI_ConvertString("Time") + " x" + makeint(GetTimeScale()));
			break;

			case "BOAL_Control0":
				switch(GetTimeScale())
				{
					case 20: PChar.basetime = 10; break;		// New values by El Rapido
					case 10: PChar.basetime =  5; break;
					case  5: PChar.basetime =  3; break;
					case  3: PChar.basetime =  1; break;
				}
				UpdateTimeScale();
				LogIt(XI_ConvertString("Time") + " x" + makeint(GetTimeScale()));
			break;
			// PB: Simplified Time Compression Controls <--

			case "BOAL_Control2":
// changed by MAXIMUS [just for fun] -->
				int res = SendMessage(PChar,"ls",MSG_CHARACTER_EX_MSG,"FindDialogCharacter");//LAi_FindNearestVisCharacter(PChar, 20);
				ref findCh;
				if (res>0)//if(res != -1)
				{
					findCh = GetCharacter(res);
					if(!CheckAttribute(findCh, "corpse"))
					{
						//res = findCh.chr_ai.hp;
						LaunchOfficer(findCh);
					//Log_SetStringToLog(XI_ConvertString("You see") + " " + findCh.name + " " + findCh.lastname + " " + XI_ConvertString("Fencing") + " " + findCh.skill.Fencing + " " + XI_ConvertString("HP") + " " + res );
// changed by MAXIMUS [just for fun] <--
					}
				}
			break;

// dchaley -->
			case "DCH_Quicksave":
				DoQuickSave();
			break;

			case "DCH_Quickload":
				DoQuickLoad();
			break;

			case "Sulan_ArchipelagoMap":
				if(CheckCharacterItem(PChar,"map"))
				{
					LaunchPelagoMap();
				}
				else
				{
					LogIt(TranslateString("","You don't have a map of the archipelago."));
				}
			break;
// dchaley <--
		}
// boal <--
	}
// ccc special weapons, equip by hotkey

	if(!bSeaActive || bAbordageStarted)
	{
		switch(ControlName)
		{
		case "BI_ChargeCannonballs":
		// PB: Equip [Regular Blade]
			if(CheckCharacterItem(Pchar,FindCharacterItemByGroup(&PChar, BLADE_ITEM_TYPE)))
			{
// KK -->
				newitm = FindCharacterItemByGroup(PChar, BLADE_ITEM_TYPE);
				EquipCharacterByItem(&PChar, newitm);
				logstr = GetItemQualityName(GetItemQualityByID(newitm));
				if (logstr == "")
					logstr = " ";
				else
					logstr = " " + logstr + " ";
				Logit(TranslateString("","You equipped") + logstr + GetItemNameByID(newitm) + ".");
// <-- KK
			} else {
				Logit(TranslateString("","You don't have a regular blade to equip."));
			}
			break;

		case "BI_ChargeGrapes":
		// PB: Equip [Regular Gun]
			if(CheckCharacterItem(Pchar,FindCharacterItemByGroup(&PChar, GUN_ITEM_TYPE)))
			{
// KK -->
				newitm = FindCharacterItemByGroup(PChar, GUN_ITEM_TYPE);
				EquipCharacterByItem(&PChar, newitm);
				logstr = GetItemQualityName(GetItemQualityByID(newitm));
				if (logstr == "")
					logstr = " ";
				else
					logstr = " " + logstr + " ";
				Logit(TranslateString("","You equipped") + logstr + GetItemNameByID(newitm) + ".");
// <-- KK
			} else {
				Logit(TranslateString("","You don't have a regular gun to equip."));
			}
			break;

		case "BI_ChargeKnippels":
		// PB: Equip [Cobblestone]
			if(CheckCharacterItem(Pchar,"pistolrock"))
			{
				EquipCharacterByItem(&PChar, "pistolrock");
				Logit(TranslateString("","You equipped a cobblestone."));
			}
			else
			{Logit(TranslateString("","You don't have a cobblestone to equip."));}
			break;

		case "BI_ChargeBombs":
		// PB: Equip [Sandbag]
			if(CheckCharacterItem(Pchar,"bladeX2"))
			{
				EquipCharacterByItem(&PChar, "bladeX2");
				Logit(TranslateString("","You equipped a sandbag."));
			}
			else
			{Logit(TranslateString("","You don't have a sandbag to equip."));}
			break;

		// PB: More fast equip keys -->
		case "BI_ChargeKey5":
		// PB: Equip [Etherbottle]
			if(CheckCharacterItem(Pchar,"pistolgas"))
			{
				EquipCharacterByItem(&PChar, "pistolgas");
				Logit(TranslateString("","You equipped an etherbottle."));
			}
			else
			{Logit(TranslateString("","You don't have an etherbottle to equip."));}
			break;

		case "BI_ChargeKey6":
		// PB: Equip [Thief's Knife]
			if(CheckCharacterItem(Pchar,"bladeX3"))
			{
				EquipCharacterByItem(&PChar, "bladeX3");
				Logit(TranslateString("","You equipped a thief's knife."));
			}
			else
			{Logit(TranslateString("","You don't have a thief's knife to equip."));}
			break;

		case "BI_ChargeKey7":
		// PB: Equip [Poisoned Throwingknife]
			if(CheckCharacterItem(Pchar,"pistolpdart"))
			{
				EquipCharacterByItem(&PChar, "pistolpdart");
				Logit(TranslateString("","You equipped a poisoned throwingknife."));
			}
			else
			{Logit(TranslateString("","You don't have a poisoned throwingknife to equip."));}
			break;

		case "BI_ChargeKey8":
		// PB: Equip [Stinkpot]
			if(CheckCharacterItem(Pchar,"pistolstink"))
			{
				EquipCharacterByItem(&PChar, "pistolstink");
				Logit(TranslateString("","You equipped a stinkpot."));
			}
			else
			{Logit(TranslateString("","You don't have a stinkpot to equip."));}
			break;

		case "BI_ChargeKey9":
		// PB: Equip [Grenade]
			if(CheckCharacterItem(Pchar,"pistolgrenade"))
			{
				EquipCharacterByItem(&PChar, "pistolgrenade");
				Logit(TranslateString("","You equipped a grenade."));
			}
			else
			{Logit(TranslateString("","You don't have a grenade to equip."));}
			break;

		case "BI_ChargeKey0":
		// PB: Equip [Your Trusty Fists]
			if(CheckCharacterItem(Pchar,"bladeX4"))
			{
				EquipCharacterByItem(&PChar, "bladeX4");
				Logit(TranslateString("","You equipped your trusty fists."));
			}
			else
			{Logit(TranslateString("","What the heck? You don't have your trusty fists???"));}
			break;
		// PB <--
// KK -->
		case "ChrActionAlt":
			int dlgchk = SendMessage(PChar, "ls", MSG_CHARACTER_EX_MSG, "FindDialogCharacter");
			if (dlgchk >= 0) {
				Event("dlgReady", "l", dlgchk);
			} else {
				if (g_ActiveActionName != "Nothing") {
					Event("BI_FastCommand", "s", g_ActiveActionName);
				} else {
					if (bAbordageStarted) {
						Event("Control Activation", "s", "ChrAction");
					}
				}
			}
			break;

		case "DlgActionAlt":
			SwitchDialogControls();
			break;

		case "DlgUpAlt":
			SwitchDialogControls();
			break;

		case "DlgDownAlt":
			SwitchDialogControls();
			break;
// <-- KK
		}
	}
	ProcessCCCkeys(ControlName);  // ccc Jan07, for Directsail and mines
// ccc end

// KK -->
	if (CheckAttribute(InterfaceStates, "Launched") && sti(InterfaceStates.Launched) == true) {
		int clicktimedlt = 0;
		switch (ControlName) {
			case "ILClick":
				bLMouseDown = true;
			break;
			case "ILClick_Up":
				bLMouseDown = false;
			break;
			case "IRClick":
				bRMouseDown = true;
			break;
			case "IRClick_Up":
				bRMouseDown = false;
			break;
			case "ILeftAlt":
				bKeyboardAlt = true;
			break;
			case "ILeftAltUp":
				bKeyboardAlt = false;
			break;
			case "IRightAlt":
				bKeyboardAlt = true;
			break;
			case "IRightAltUp":
				bKeyboardAlt = false;
			break;
			case "ILeftControl":
				bKeyboardControl = true;
			break;
			case "ILeftControlUp":
				bKeyboardControl = false;
			break;
			case "IRightControl":
				bKeyboardControl = true;
			break;
			case "IRightControlUp":
				bKeyboardControl = false;
			break;
			case "ILeftShift":
				bKeyboardShift = true;
			break;
			case "ILeftShiftUp":
				bKeyboardShift = false;
			break;
			case "IRightShift":
				bKeyboardShift = true;
			break;
			case "IRightShiftUp":
				bKeyboardShift = false;
			break;
		}
	}
// <-- KK


	if(bSeaActive && !bAbordageStarted)
	{
		switch(ControlName)
		{
			case "MainMenu": ProcessMainMenuKey();	break;
			case "MainMenuDouble": ProcessMainMenuKey(); break;
			case "Interface": ProcessInterfaceKey();break;

			case "Sea_CameraSwitch": SeaCameras_Switch(); break;
			case "Ship_Fire": Ship_DoFire(); break;

			case "Aimed_Ship_Fire": Ship_DoAimedFire(); break;	// LDH - allows manual aiming
			//case "Tele": Sea_ReloadStart(); break;

// KK -->
			case "Ship_RaiseSails": Ship_DoRaiseSails(); break;
			case "Ship_LowerSails": Ship_DoLowerSails(); break;

			case "ILeft":
				if (bKeyboardControl && iRealismMode<2 && !ONSEA_DATA_DISABLED) SeaCameras_SetPreviousShip();
			break;
			case "IRight":
				if (bKeyboardControl && iRealismMode<2 && !ONSEA_DATA_DISABLED) SeaCameras_SetNextShip();
			break;
			case "IDown":
				if (bKeyboardControl && iRealismMode<2 && !ONSEA_DATA_DISABLED) SeaCameras_SetMyShip();
			break;
			case "ControlDown": bKeyboardControl = true; break;
			case "ControlUp": bKeyboardControl = false; break;
// <-- KK
		}
	}
	else
	{
		switch(ControlName)
		{
			case "MainMenu": ProcessMainMenuKey();	break;
			case "MainMenuDouble": ProcessMainMenuKey(); break;
			case "Interface": ProcessInterfaceKey();break;
			case "Tele":
				StartQuickTeleport();
				break;
			case "TeleBack": Teleport(-1); break;
			case "Action":
				//DumpAttributes(loadedLocation/*loadedLocation.reload.reload1.x*/);
				//trace("Y: " + loadedLocation.reload.reload1.y);
				//trace("Z: " + loadedLocation.reload.reload1.z);
			break;
		}
	}


	/*switch(ControlName)
	{
		counter++;
		if(counter > 3) counter = 0;
		case "CameraSwitch":
			switch(counter)
			{
			case 0: SetDayTime(DAY_TIME_NIGHT); break;
			case 1: SetDayTime(DAY_TIME_MORNING); break;
			case 2: SetDayTime(DAY_TIME_DAY); break;
			case 3: SetDayTime(DAY_TIME_EVENING); break;
			}
		break;
	}*/
}

// added by MAXIMUS -->
bool StraifCharacter(ref chr)
{
	aref ourModel;
	if (CheckAttribute(chr,"model") == false || GetModelIndex(chr.model) < 0) return false;
	makearef(ourModel, Models[GetModelIndex(chr.model)]);
	if (CheckAttribute(ourModel, "status") == true && ourModel.status == "C_III") return true;
	return false;
}

#event_handler("Lai_EndAction", "Lai_ReturnNormal");
void Lai_ReturnNormal()
{
	aref chr = GetEventData();
	CharacterPlayAction(chr, "");
	SideStepControl(-SIDESTEP_DIST_LEFT, false);
	SideStepControl(SIDESTEP_DIST_RIGHT, false);
}
#event_handler("RemoveCorpse", "Lai_KillCorpse");
void Lai_KillCorpse()
{
	aref chCorpse = GetEventData();
	Lai_KillCharacter(chCorpse);
}
// added by MAXIMUS <--

void Teleport(int step)
{
	nTeleportLocation = nTeleportLocation + step;
	if(nTeleportLocation >=	nLocationsNum) nTeleportLocation = 1;
	if(nTeleportLocation <=	0) nTeleportLocation = nLocationsNum - 1;

	sTeleportLocName = Locations[nTeleportLocation].id;
	Trace("Teleport to '" + sTeleportLocName + "'");

	ReleaseSound(0);
	ClearEvents();
	ClearPostEvents();
	DeleteEntities();
	SetEventHandler("frame","NewGame",1);
}

void ProcessMainMenuKey()
{
	// PB: Prevent CTDs while being resurrected -->
	if(CheckAttribute(GetMainCharacter(), "NoSave.Resurrection"))
	{
		LogIt(TranslateString("", "You can't save or load until") + " " + GetMyFullName(ResurrectingOfficiant) + " " + TranslateString("", "leaves."));
		return;
	}
	// PB: Prevent CTDs while being resurrected <--
	LaunchMainMenu();
}

void ProcessInterfaceKey()
{
	if(bSeaActive && !bAbordageStarted)
	{
		if( CheckAttribute(&BattleInterface,"ComState") && sti(BattleInterface.ComState) != 0 )
			{return;}
	}
	else
	{
		if( SendMessage(GetMainCharacter(),"ls",MSG_CHARACTER_EX_MSG,"IsFightMode") != 0 )
			{return;}
		if( CheckAttribute(&objLandInterface,"ComState") && sti(objLandInterface.ComState) != 0 )
			{return;}
	}
	if( IsEntity(&worldMap) ) return;
//	LaunchSelectMenu(); // MAXIMUS interface MOD
	LaunchCharacter(GetMainCharacter()); // MAXIMUS interface MOD
}

//ccc survival ->
void GameOverE()
{
	ref mc = GetMainCharacter();
	if(rand(100) + (sti(mc.skill.Sneak)*3) > DEATHRATE)	// BF mar05
	{	//ccc new survival section
// KK
		if (HasSubStr(mc.ship.type, "Tartane") == true || mc.ship.type == "Gunboat") {
			GameOverOrg("sea");
			DeleteSeaEnvironment();
			return;
		}
// <-- KK
		Event("DoInfoShower","sl","MainMenuLaunch",true);	//TIH - black out the screen to hide uglyjunk
		LAi_SetCurHPMax(mc);
		mc.lost.ship.type = GetCharacterShipID(mc); // PB: So you can get her back if necessary
		GiveShip2Character(mc,SHIP_LIFEBOAT,"Lifeboat",-1,GetServedNation(),false,false);
// KK -->
		SetCharacterGoods(mc, GOOD_BALLS   , 0);
		SetCharacterGoods(mc, GOOD_GRAPES  , 0);
		SetCharacterGoods(mc, GOOD_KNIPPELS, 0);
		SetCharacterGoods(mc, GOOD_BOMBS   , 0);
		AddCharacterGoods(mc, GOOD_WHEAT   , 2);
		AddCharacterGoods(mc, GOOD_RUM     , 2);
// <-- KK
		mc.lifeboatlaunch = true;	//TIH - better check for when they sank
		Sea_ReloadStart();
		PostEvent("DoInfoShower",100,"s","");	//TIH - clears black screen
		PlaySound("#ship_sinking");		//ccc mar20 // KK
		Log_SetStringToLog(TranslateString("","You manage to launch a boat in the last moment."));	//ccc mar20
		Log_SetStringToLog(TranslateString("","With a few mates you escape from disaster."));	//ccc mar20
	} else {	//ccc call original GameOver function
		GameOverOrg("sea");
		DeleteSeaEnvironment();
	}
}

void GameOver(string sName)
{
	if (bSuppressResurrection) return; // KK

	ref mc = GetMainCharacter(); // KK

// TIH --> process cleanup 7-7-06

	//ccc call original GameOver function / BF mar05
	if (!CheckAttribute(mc, "NoSave.Resurrection")) { // PB: Check resurrection chance earlier in LAi_events.c
		GameOverOrg(sName);
		return;
	}

	// TIH if die during boarding, you are DEAD
	if (sName == "boarding") {
		GameOverOrg(sName);
		return;
	}

	// TIH if mutiny, you are put to sea
	if (sName == "mutiny") {
		PlaySound("VOICE\"+LanguageGetLanguage()+"\Dut_m_a_054.wav");		//ccc mar20
		Log_SetStringToLog(XI_ConvertString("MUTINY") + "!");		//ccc mar20
		Log_SetStringToLog(TranslateString("","'Cap'n, we are giving you and your cronies this boat."));		//ccc mar20
		Log_SetStringToLog(TranslateString("","If you're careful, you just might make it."));		//ccc mar20
		Log_SetStringToLog(TranslateString("","But given your past performance you'll all starve!'"));		//ccc mar20
		GameOverE();
		return;
	}

	//MAXIMUS - if you die during fight with your crew
	if(CheckAttribute(mc,"mutiny"))
	{
		GameOverOrg("mutiny");
		DeleteAttribute(mc,"mutiny");
		return;
	}

	// Levis: Disable shotgun mode if you die
	globalSGMode = false;

	// TIH died in land fight, so you are resurrected somewhere
	Lai_SetActorType(mc);
	LAi_type_actor_Reset(mc);
	Lai_SetPlayerType(mc);

	string gun = GetCharacterEquipByGroup(&mc, GUN_ITEM_TYPE);

	if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0)
	{
		if(CheckAttribute(mc,"quest.WR_part1") && mc.quest.WR_part1 == "finished")
		{
			//WoodesRogers quest part1 is finished and you CAN loose also quest guns when reincarnated

			//JRH: belt with or without any pistols (201-206) is lost too... -->
			mc.quest.reduce_ammo = "off";		//start mode

			//1
			if(IsEquipCharacterByItem(mc, "ammobag2")) RemoveCharacterEquip(mc, POUCH_ITEM_TYPE);

			if(CheckCharacterItem(mc, "ammobag2") || CheckCharacterItem(mc, "ammobag1"))
			{
				TakeItemFromCharacter(mc, "ammobag2");
				TakeItemFromCharacter(mc, "ammobag1");

				if(CheckAttribute(mc,"quest.reduce_ammo") && mc.quest.reduce_ammo == "off")
				{
					mc.quest.reduce_ammo = "on";
					if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0) LAi_QuestDelay("pistol_ranking_list", 0.1);
				}
			}

			//2
			if(IsEquipCharacterByItem(mc, "pistol20"))
				{
				RemoveCharacterEquip(mc, GUN_ITEM_TYPE);
				TakeItemFromCharacter(mc, "pistol20");
				GiveItem2Character(mc, "pistol201"); GiveItem2Character(mc, "pistol202"); GiveItem2Character(mc, "pistol203");
				GiveItem2Character(mc, "pistol204"); GiveItem2Character(mc, "pistol205");//one is lost
			}

			//3
			if(IsEquipCharacterByItem(mc, "pistolthrow5"))
				{
				RemoveCharacterEquip(mc, GUN_ITEM_TYPE);
				TakeItemFromCharacter(mc, "pistolthrow5");
				GiveItem2Character(mc, "pistolthrow4");
			}

			if(IsEquipCharacterByItem(mc, "pistolthrow4"))
				{
				RemoveCharacterEquip(mc, GUN_ITEM_TYPE);
				TakeItemFromCharacter(mc, "pistolthrow4");
				GiveItem2Character(mc, "pistolthrow3");
			}

			if(IsEquipCharacterByItem(mc, "pistolthrow3"))
				{
				RemoveCharacterEquip(mc, GUN_ITEM_TYPE);
				TakeItemFromCharacter(mc, "pistolthrow3");
				GiveItem2Character(mc, "pistolthrow2");
			}

			if(IsEquipCharacterByItem(mc, "pistolthrow2"))
				{
				RemoveCharacterEquip(mc, GUN_ITEM_TYPE);
				TakeItemFromCharacter(mc, "pistolthrow2");
				GiveItem2Character(mc, "pistolthrow1");
			}

			if(IsEquipCharacterByItem(mc, "pistolthrow1"))
				{
				RemoveCharacterEquip(mc, GUN_ITEM_TYPE);
				TakeItemFromCharacter(mc, "pistolthrow1");
			}

			if(IsEquipCharacterByItem(mc, "pistolbelt")) RemoveCharacterEquip(mc, BELT_ITEM_TYPE);
			TakeItemFromCharacter(mc, "pistolbelt");

			//4
			if(IsEquipCharacterByItem(mc, "pistol203") || IsEquipCharacterByItem(mc, "pistol202") || IsEquipCharacterByItem(mc, "pistol201"))
			{
				RemoveCharacterEquip(mc, GUN_ITEM_TYPE);
				TakeItemFromCharacter(mc, gun);
				
				if(!IsEquipCharacterByItem(mc, "bladepclub203"))
				{
					TakeItemFromCharacter(mc, "bladepclub203");	//unequipped
					if(!CheckCharacterItem(mc, "bladeX4"))
					{
						GiveItem2Character(mc, "bladeX4");//if bladepclub203 instead
					}
				}
			}

			if(IsEquipCharacterByItem(mc, "pistol204") || IsEquipCharacterByItem(mc, "pistol205") || IsEquipCharacterByItem(mc, "pistol206"))
			{
				RemoveCharacterEquip(mc, GUN_ITEM_TYPE);
				TakeItemFromCharacter(mc, gun);
			}

			//5
			if(!CheckCharacterItem(mc, "pistol20") || !CheckCharacterItem(mc, "pistol201") || !CheckCharacterItem(mc, "pistol202")
			|| !CheckCharacterItem(mc, "pistol203") || !CheckCharacterItem(mc, "pistol204") || !CheckCharacterItem(mc, "pistol205")
			|| !CheckCharacterItem(mc, "pistol206") || !CheckCharacterItem(mc, "pistolthrow5") || !CheckCharacterItem(mc, "pistolthrow4")
			|| !CheckCharacterItem(mc, "pistolthrow3") || !CheckCharacterItem(mc, "pistolthrow2") || !CheckCharacterItem(mc, "pistolthrow1"))
			{
				if(!IsEquipCharacterByItem(mc, "bladepclub203"))
				{
					TakeItemFromCharacter(mc, "bladepclub203");	//unequipped
					if(!CheckCharacterItem(mc, "bladeX4"))
					{
						GiveItem2Character(mc, "bladeX4");//if bladepclub203 instead
					}
				}
			}

			//6
			if(CheckAttribute(mc,"model"))
			{
				//Only when quest is finished => dressed in red uniform + hat!
				if(mc.model == "ShkiperM_UH_b" || mc.model == "ShkiperM_UH_a")
				{
					SetModel(mc, "ShkiperM_UH", mc.model.animation, mc.sex, stf(mc.model.height), true);
				}
			}
		}
	}
	else
	{
		RemoveCharacterEquip(mc, GUN_ITEM_TYPE);
		TakeItemFromCharacter(mc, gun);
	}

	//JRH loose pf, ap, pb or ab
	if(IsEquipCharacterByItem(mc, "ammopouch") || IsEquipCharacterByItem(mc, "ammobag"))
	{
		RemoveCharacterEquip(mc, POUCH_ITEM_TYPE);
		TakeItemFromCharacter(mc, "ammopouch"); TakeItemFromCharacter(mc, "ammobag");

		if(CheckCharacterItem(mc, "ammopouch") || CheckCharacterItem(mc, "ammobag1") || CheckCharacterItem(mc, "ammobag2") || CheckCharacterItem(mc, "ammobag"))
		{
			//fine
		}
		else
		{
			if(CheckAttribute(mc,"quest.reduce_ammo") && mc.quest.reduce_ammo == "off")
			{
				mc.quest.reduce_ammo = "on";
				if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0) LAi_QuestDelay("pistol_ranking_list", 0.1);
			}
		}
	}

	if(IsEquipCharacterByItem(mc, "powderflask") || IsEquipCharacterByItem(mc, "powderbarrel"))
	{
		RemoveCharacterEquip(mc, FLASK_ITEM_TYPE);
		TakeItemFromCharacter(mc, "powderflask"); TakeItemFromCharacter(mc, "powderbarrel");

		if(CheckCharacterItem(mc, "powderflask") || CheckCharacterItem(mc, "ammobag1") || CheckCharacterItem(mc, "ammobag2"))
		{
			//fine
		}
		else
		{
			if(CheckAttribute(mc,"quest.reduce_ammo") && mc.quest.reduce_ammo == "off")
			{
				mc.quest.reduce_ammo = "on";
				if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0) LAi_QuestDelay("pistol_ranking_list", 0.1);
			}
		}
	}
	//JRH

	// PB: Keep your fists when you die -->
	if(GetCharacterEquipByGroup(&mc, BLADE_ITEM_TYPE) !="bladeX4")
	{
		RemoveCharacterEquip(mc, BLADE_ITEM_TYPE);
		TakeItemFromCharacter(mc, GetCharacterEquipByGroup(mc, BLADE_ITEM_TYPE));
	}
	string blade = FindCharacterItemByGroup(mc,BLADE_ITEM_TYPE);
	if (blade == "") blade = "bladeX4";
	EquipCharacterByItem(mc, blade);
	EquipCharacterByItem(mc, FindCharacterItemByGroup(mc,GUN_ITEM_TYPE));
	// PB: Keep your fists when you die <--

	// TIH --> slight reordering of process - Jul10'06
	// lose crew and money first before the time span
	mc.Ship.crew.quantity = makeint(sti(mc.Ship.crew.quantity) * (5 + rand(3))/10);// 20-50% loss
	mc.money = makeint(sti(mc.money) * (4 + rand(5))/10);// 10-60% loss

	// figure their dmgs here, before the time span, then we adjust dmgs AFTER the time span
	int degradedHP = makeint(sti(mc.ship.hp) * (5 + rand(3))/10);// 20-50% loss
	int degradedSP = makeint(sti(mc.ship.sp) * (5 + rand(3))/10);// 20-50% loss

	// time span moved here as to apply to both tavern girl and NO tavern girl
	WaitDate("", 0,0,4,0,0);// 4 days

	// damage is applied after time span so hull and sails dont get auto-repaired during 4 days
	mc.ship.hp = degradedHP;// 20-50% loss
	mc.ship.sp = degradedSP;// 20-50% loss
	// TIH <--

// KK -->
	//start bedroomscene
	WaitDate("", 0,0,4,0,0);

	ResurrectingOfficiant.isResurrecting = true;
	PostVideoAndQuest("Blaze_land_dead", 0.0, "PreResurrection");
// <-- KK
// TIH <-- process cleaning
}

void GameOverOrg(string sName)	//ccc original GameOver function
{
	ref mc;
	int nSelect;
	string sFileName;
	//ResetSoundScheme();
	//PauseAllSounds();
	ResetSound();
	EngineLayersOffOn(false);

	mc = GetMainCharacter();

	ClearEvents();
	ClearPostEvents();
	DeleteEntities();

	if(sti(InterfaceStates.Launched)) {
		UnloadSegment(Interfaces[CurrentInterface].SectionName);
	}

	if(LoadSegment("Interface\BaseInterface.c"))
	{
		InitBaseInterfaces();
		UnloadSegment("Interface\BaseInterface.c");
	}
	InitSound();

	SetEventHandler(EVENT_END_VIDEO,"LaunchMainMenu_afterVideo",0);

	switch(sName)
	{
		case "sea":
			nSelect = rand(2);
			sFileName = "skeleton_on_beach";
			switch(nSelect)
			{
				case 0: sFileName = "skeleton_on_beach"; break;
				case 1: sFileName = "undersea"; break;
				case 2: sFileName = "Sharks_attack"; break;
			}
			StartPostVideo(sFileName,1);
		break;

		case "kraken":
			StartPostVideo("undersea",1);
		break;

		case "boarding":
			StartPostVideo("skeleton_on_beach",1);
		break;

		case "land":
			StartPostVideo("blaze_land_dead",1);
		break;

		case "mutiny":
			StartPostVideo("blaze_mutiny_dead",1);
		break;
		
		case "surrender":
			StartPostVideo("surrender_bart",1);
		break;		
	}
	InterfaceStates.Buttons.Resume.enable = false;
	InterfaceStates.Buttons.Save.enable = false;
}
//ccc survival <-
