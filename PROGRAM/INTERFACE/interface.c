#include "interface\messages.h"
#include "interface\utilite.c"
// KK -->
#include "interface\option_sl.c"
#include "interface\kam_generalfunctions.c"	// added after build 11 by KAM
#include "interface\kam_shipberthing_ship.c"	// added after build 11 by KAM
// <-- KK

#define FONT_NORMAL	"interface_normal"
#define FONT_SMALL	"dialog21"		//added by KAM
#define FONT_BOLD_NUMBERS	"bold_numbers"
#define FONT_TITLE	"interface_title" // added by MAXIMUS
#define FONT_QUESTBOOK	"seadogs" // KK
#define FONT_SHIPSLOG   "seadogs" // Sulan : Shipslog
#define FONT_SEADOGS	"seadogs" // KK
#define FONT_RELOAD "interface_normal" // KK

#define COLOR_DESELECT		4286611584
#define COLOR_NORMAL		4294967295
#define COLOR_MONEY			4292915296
//MAXIMUS -->
#define COLOR_YELLOW		-256
#define COLOR_YELLOW_LIGHT	-64
#define COLOR_RED			-65536
#define COLOR_RED_LIGHT		-16192
#define COLOR_GREEN			-16711936
#define COLOR_GREEN_LIGHT	-4128832
#define COLOR_BLUE			-16776961
#define COLOR_BLUE_LIGHT	-4144897
//MAXIMUS <--
#define COLOR_WHITE			-1 // KK
#define COLOR_GRAY			-931234178 // KK

#define MONEY_SIGN		""
#define MONEY_DELIVER	"," // NK

// 0xFF606060
#define minBlindColor	4281348144
// 0xFF808080
#define maxBlindColor	4288716960

#event_handler("LaunchIAfterFrame","ILaunchAfterFrame");
#event_handler("ievent_GameOver","IProcEventGameOver");
#event_handler("ievent_SetGameTime","IProcEventSetGameTime");
#event_handler("evntPreLoad","procPreLoad");

#event_handler("FaderEvent_StartFade","ProcBreakInterface");
#event_handler("FaderEvent_StartFadeIn","ProcBreakInterface");
#event_handler("FaderEvent_EndFade","ProcBreakInterface");
#event_handler("FaderEvent_EndFadeIn","ProcBreakInterface");

#event_handler("evntOptionsBreak","procOptionsBreak");

bool EnableVideoBreak = false;

int CurrentInterface;
int gStoreNum;

extern void InitBaseInterfaces();
extern void InitBaseInterfaces_main();
//extern void GetInterfaceParameters();

extern void InitInterface(string iniFile);
extern void InitInterface_BB(string iniFile, ref book); //Levis
extern void InitInterface_R(string iniFile, ref rParam);
extern void InitInterface_RR(string iniFile, ref rParam1, ref rParam2);
extern void InitInterface_S(string iniFile, string sParam1);
extern void InitInterface_RS(string iniFile, ref rParam1, string sParam2);
extern void InitInterface_I(string iniFile, int iParam1);
extern void InitInterface_B(string iniFile, bool bParam1);
extern void InitInterface_RRS(string iniFile, ref rParam1, ref rParam2, string sParam3);
extern void InitInterface_SS(string iniFile, string sParam1, string sParam2);

extern ref GetMyCharacterRef();
extern ref GetEnemyCharacterRef();

string ICurNode;
int	   nPrevInterface;

bool bGamePadChangeEnable = false;
bool bPlayVideoNow = false;
bool bMainMenuLaunchAfterVideo = false;

int	interfaceResultCommand;
object	GameInterface;
object	LanguageObject;
object  Interfaces[INTERFACE_QUANTITY];

// состояние интерфейса
object InterfaceStates;
// профиль игрока
// KK -->
object GlobalSettings;
object ProfileSettings;
// <-- KK

//MAXIMUS: -revival of quicksave->
void DoQuickLoad()
{
	// PB: Prevent CTDs while being resurrected -->
	ref PChar = GetMainCharacter();
	if(CheckAttribute(PChar, "NoSave.Resurrection"))
	{
		LogIt(TranslateString("", "You can't save or load until") + " " + GetMyFullName(ResurrectingOfficiant) + " " + TranslateString("", "leaves."));
		return;
	}
	// PB: Prevent CTDs while being resurrected <--

	// PB: Profile Check -->
	string sCurProfile = GetCurrentProfile(GetStoryline(FindCurrentStoryline()));
	if(sCurProfile == "")	sCurProfile = GetAttribute(PChar, "profile");
	if(sCurProfile == "-1")	sCurProfile = DEFAULT_PROFILE_NAME;
	// PB: Profile Check <--

	string curSave = "-=" + sCurProfile + "=- QuickSave";

	if(InterfaceStates.Launched!= 0) return;
	if(bPlayVideoNow) return;

	ResetSound();
	SendMessage(Sound,"lll",MSG_SOUND_STOP, 0, 0);

	GameInterface.SavePath = "SAVE\" + GetStorylineDir(FindCurrentStoryline()) + "\"; // KK
// KK -->
	if (FindFile(GameInterface.SavePath, "*", curSave) != "")
	{
		SetEventHandler("evntLoad","LoadGame",0);
		PostEvent("evntLoad",0,"s", GameInterface.SavePath + curSave);
	}
	else
	{
		Log_SetStringToLog(TranslateString("","You haven't the file") + " '" + curSave + "'!");
	}
// <-- KK
}

void DoQuickSave()
{
	if(bPlayVideoNow) return;
	ref PChar = GetMainCharacter();
	if(!IsEntity(PChar))
	{
		if(!IsEntity(&worldMap) && CharacterIsDead(PChar))  return;
	}
	// PB: Prevent CTDs while being resurrected -->
	if(CheckAttribute(PChar, "NoSave.Resurrection"))
	{
		LogIt(TranslateString("", "You can't save or load until") + " " + GetMyFullName(ResurrectingOfficiant) + " " + TranslateString("", "leaves."));
		return;
	}
	// PB: Prevent CTDs while being resurrected <--
	// PW -->
	if (CheckAttribute(PChar,"NoSave.CarryRelic") == true && PChar.NoSave.CarryRelic != "none") {
		LogIt(TranslateString("","You can't save while carrying a holy relic! Give it to a monk") + " " + PChar.NoSave.ReleaseMonkLocation + "."); // NK
		return;
	}
	// PW <--
	bool bEnableSave = true;
	string restrictSave = "save_now";

	aref arTmp;
	if(FindEntity(&arTmp,"fader")) bEnableSave = false;

	if(dialogRun || dialogSelf) bEnableSave = false;
	if(!CheckAttribute(&InterfaceStates, "Buttons.Save.enable") || InterfaceStates.Buttons.Save.enable!= 1) bEnableSave = false;
	if(InterfaceStates.Launched!=0) bEnableSave = false;

	aref arScrShoter;
	if(FindEntity(&arScrShoter,"scrshoter")) bEnableSave = false;

	if(bSeaActive && !bMapEnter) { bEnableSave = false; restrictSave = "save_while sailing"; }
	if(LAi_IsBoardingProcess()) { bEnableSave = false; restrictSave = "save_while boarding"; }
	if(bAbordageStarted && !ownDeckStarted()) { bEnableSave = false; restrictSave = "save_while sailing or boarding"; }
	if(bMutinyDeckStarted) { bEnableSave = false; restrictSave = "save_while sailing or boarding"; }
	if(bEnableSave && ownDeckStarted() && bSeaActive) { bEnableSave = false; restrictSave = "save_on deck"; }
	if(bEnableSave && HasSubStr(PChar.location,"Deck") && bSeaActive) { bEnableSave = false; restrictSave = "save_on deck"; }

	if(!bEnableSave) {
		Log_SetStringToLog(TranslateString("","save_You can't save")+" "+TranslateString("",restrictSave)+"!");
		return;
	}

	Set_inDialog_Attributes();//MAXIMUS: VERY strange, but it's needed

	SetEventHandler("makescrshot","ContinueQuickSave",0);
	CreateScreenShoter();
	PostEvent("makescrshot",1);
}

void ContinueQuickSave()
{
	int n = 1;
	DelEventHandler("makescrshot","ContinueQuickSave");
	GameInterface.SavePath = "SAVE\" + GetStorylineDir(FindCurrentStoryline()); // KK
// KK -->
	string curSave;
	// Screwface
	string storyline = GetStoryline(FindCurrentStoryline());
	/*if(CheckAttribute(Globalsettings,"profile."+storyline+".len")) stringlen = Globalsettings.profile.(storyline).len;
	if(stringlen != 0)
	{*/
	string sCurProfile = GetCurrentProfile(storyline);		
	/*}
	else
	{
		stmp = GetCurrentProfile(GetStoryline(FindCurrentStoryline()));
	}*/
	if (sCurProfile == "")	  sCurProfile = GetAttribute(GetMainCharacter(), "profile");	// PB: Just in case the game can't find this
	if (sCurProfile == "-1") sCurProfile = DEFAULT_PROFILE_NAME;							// PB: Just in case the game STILL can't find this
	if (sCurProfile == "" || FindProfile(storyline, sCurProfile) < 0)
	{
		Log_SetStringToLog(TranslateString("","Quicksave") + ": FAILED ! You can't save without an active Profile !");
		return;
	}
	curSave = "-=" + sCurProfile + "=- QuickSave";
// <-- KK
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_DELETE_SAVE_FILE,curSave);
	string sSaveDescriber = GetSaveDataString();

// KK -->
	while (FindFile(GameInterface.SavePath, "*", curSave+" "+n) != "")
	{
		n++;
	}
// <-- KK

	SetEventHandler("evntSave","SaveGame",1);
	//PostEvent("evntSave",0,"ss", GameInterface.SavePath+"\"+curSave, sSaveDescriber);
	PostEvent("evntSave", 0, "sss", GameInterface.SavePath, curSave + " " + n, sSaveDescriber); // KK
}

void ClearScreenShoter()
{
	DeleteEntitiesByType("scrshoter");
	aref arScrShoter;
	if(FindEntity(&arScrShoter,"scrshoter")) DeleteClass(&arScrShoter));
	if(CheckAttribute(&InterfaceStates,"MakeScreenShot")) DeleteAttribute(&InterfaceStates,"MakeScreenShot");
}

string GetSaveDataString()
{
	ref PChar = GetMainCharacter();
	string locLabel = CreateLocDescribe();

	AddTimeToCurrent(0,0);
	string SystemTime = "";
	SendMessage(&GameInterface,"lse",MSG_INTERFACE_GETTIME, "", &SystemTime);
// KK -->
	// PB: Fill in missing firstnames
	string sSaveDescriber = locLabel + "@" +
		GetFacePicture(GetMainCharacterIndex()) + "@" + GetMyFormalName(PChar) + "@" +
		GetFacePicture(GetCompanionIndex(PChar, 1)) + "@" + GetMyFormalName(GetCharacter(GetCompanionIndex(PChar, 1))) + "@" +
		GetFacePicture(GetCompanionIndex(PChar, 2)) + "@" + GetMyFormalName(GetCharacter(GetCompanionIndex(PChar, 2))) + "@" +
		GetFacePicture(GetCompanionIndex(PChar, 3)) + "@" + GetMyFormalName(GetCharacter(GetCompanionIndex(PChar, 3))) + "@" +
		GetHumanDate(GetDataYear(),GetDataMonth(),GetDataDay()) + " " + SystemTime + "@" + IS_SGV;
// <-- KK

	return sSaveDescriber;
}
//MAXIMUS: <-revival of quicksave-

// KK -->
string CreateLocDescribe()
{
	ref pchar = GetMainCharacter();
	string storyline = GetStoryline(FindCurrentStoryline()); // KK

	string locLabel = pchar.location;
	int locidx = FindLocation(pchar.location);
	if (IsEntity(&worldMap)) {
		locLabel = "Open Sea";
	} else {
		if (locidx >= 0) {
			int islandidx = locidx;
			bool bOnDeck = ownDeckStarted();
			if (CheckAttribute(&Locations[locidx], "id.label")) {
				Preprocessor_Add("island_name", GetIslandNameByLocationID(Locations[locidx].id));
				if (!CheckAttribute(&Locations[locidx], "townsack")) {
					if (bOnDeck) {
						if (CheckAttribute(pchar, "location.from_sea")) islandidx = FindLocation(pchar.location.from_sea);
						if (CheckAttribute(&Locations[islandidx], "townsack"))
							Preprocessor_Add("town_name", FindTownName(Locations[islandidx].townsack));
						else
							Preprocessor_Add("town_name", "");
					} else {
						locLabel = "Open Sea";
					}
				} else {
					Preprocessor_Add("town_name", FindTownName(Locations[locidx].townsack));
				}
				locLabel = GetIslandNameByLocationID(Locations[islandidx].id) + ". " + Locations[locidx].id.label;
				if (bOnDeck) locLabel += " " + TranslateString("", "on ship in") + " " + Locations[islandidx].id.label;
				locLabel = PreprocessText(locLabel);
				Preprocessor_Remove("town_name");
				Preprocessor_Remove("island_name");
			} else {
				locLabel = "Open Sea";
			}
		} else {
			if (bSeaActive) {
				if (pchar.location == "") locLabel = "Open Sea";
				if (FindIsland(pchar.location) >= 0) {
					Preprocessor_Add("island_name", FindIslandName(pchar.location));
					locLabel = PreprocessText(TranslateString("", "#sisland_name# Waters"));
					Preprocessor_Remove("island_name");
				}
			} else {
				locLabel = "Unknown location";
			}
		}
	}
	return locLabel;
}

void DoAutoSave()
{
	if(bPlayVideoNow) return;
	ref PChar = GetMainCharacter();
	if(!IsEntity(PChar))
	{
		if(!IsEntity(&worldMap) && CharacterIsDead(PChar))  return;
	}
	bool bEnableSave = true;
	string restrictSave = "save_now";

	/*aref arTmp;
	if(FindEntity(&arTmp,"fader")) bEnableSave = false;

	if(dialogRun || dialogSelf) bEnableSave = false;
	//if(!CheckAttribute(&InterfaceStates, "Buttons.Save.enable") || InterfaceStates.Buttons.Save.enable!= 1) bEnableSave = false;
	if(InterfaceStates.Launched!=0) bEnableSave = false;

	aref arScrShoter;
	if(FindEntity(&arScrShoter,"scrshoter")) bEnableSave = false;

	if(bSeaActive) { bEnableSave = false; restrictSave = "save_while sailing"; }
	if(LAi_IsBoardingProcess()) { bEnableSave = false; restrictSave = "save_while boarding"; }
	if(bAbordageStarted && !ownDeckStarted()) { bEnableSave = false; restrictSave = "save_while sailing or boarding"; }
	if(bMutinyDeckStarted) { bEnableSave = false; restrictSave = "save_while sailing or boarding"; }
	if(bEnableSave && ownDeckStarted() && bSeaActive) { bEnableSave = false; restrictSave = "save_on deck"; }
	if(bEnableSave && HasSubStr(characters[GetMainCharacterIndex()].location,"Deck") && bSeaActive) { bEnableSave = false; restrictSave = "save_on deck"; }*/

	if(!bEnableSave)
	{
		Log_SetStringToLog(TranslateString("","save_You can't save")+" "+TranslateString("",restrictSave)+"!");
		return;
	}

	Set_inDialog_Attributes();//MAXIMUS: VERY strange, but it's needed

	SetEventHandler("makescrshot","ContinueAutoSave",0);
	CreateScreenShoter();
	PostEvent("makescrshot",1);
}

void ContinueAutoSave()
{
	DelEventHandler("makescrshot","ContinueAutoSave");
	GameInterface.SavePath = "SAVE\" + GetStorylineDir(FindCurrentStoryline()); // KK
	string curSave;
	if (FindLoadedLocation() >= 0) curSave = "location";
	if (bSeaActive) curSave = "sea";
	curSave = "-=" + GetCurrentProfile(GetStoryline(FindCurrentStoryline())) + "=- " + curSave + " Autosave";
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_DELETE_SAVE_FILE,curSave);
	string sSaveDescriber = GetSaveDataString();

	SetEventHandler("evntSave","SaveGame",1);
	PostEvent("evntSave", 0, "sss", GameInterface.SavePath, curSave, sSaveDescriber);
}
// <-- KK

void CreateExitString()//MAXIMUS: standard exit-string for exit-button
{
	CreateString(true,"Exit",XI_ConvertString("Exit"),FONT_NORMAL,COLOR_NORMAL,630,10,SCRIPT_ALIGN_RIGHT,0.8);
}

void LaunchPelagoMap()
{
	if(procInterfacePrepare(INTERFACE_A_MAP))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_A_MAP;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}

void LaunchInfoScreen()
{
	if (!bSeaActive && !bAbordageStarted) {
		Log_SetActiveAction("Nothing");
		BLI_RefreshCommandMenu();
		BLI_DisableShow();
		SetEventHandler("makescrshot","LaunchInfoScreenContinue",0);
		aref arScrShoter;
		if (!FindEntity(&arScrShoter,"scrshoter")) {
			CreateScreenShoter();
			PostEvent("makescrshot",1);
		} else {
			Event("makescrshot");
		}
	} else {
		LaunchInfoScreenContinue();
	}
}

void LaunchInfoScreenContinue()
{
	if(!bSeaActive && !bAbordageStarted) { DelEventHandler("makescrshot","LaunchInfoScreenContinue"); }
	if(procInterfacePrepare(INTERFACE_INFOBOX))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_INFOBOX;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}

void LaunchLootingScreen()
{
	if(!bSeaActive && !bAbordageStarted) {
		Log_SetActiveAction("Nothing");
		BLI_RefreshCommandMenu();
		BLI_DisableShow();
		SetEventHandler("makescrshot","LaunchLootingScreenContinue",0);
		aref arScrShoter;
		if (!FindEntity(&arScrShoter,"scrshoter")) {
			CreateScreenShoter();
			PostEvent("makescrshot",1);
		} else {
			Event("makescrshot");
		}
	} else {
		LaunchLootingScreenContinue();
	}
}

void LaunchLootingScreenContinue()
{
	if(!bSeaActive && !bAbordageStarted) DelEventHandler("makescrshot","LaunchLootingScreenContinue");
	if(procInterfacePrepare(INTERFACE_ITEMSBOX))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_ITEMSBOX;
		aref charef; makearef(charef,deadChr);
		InitInterface_RS(Interfaces[CurrentInterface].IniFile,&charef,deadChr.FaceID);
	}
}

void CreateScreenShoter()
{
	DeleteEntitiesByType("scrshoter");
	object scrshoter;
// KK -->
	int layer = REALIZE;
	if (bSeaActive && !bAbordageStarted) layer = SEA_REALIZE;
	CreateEntity(&scrshoter,"scrshoter");
	scrshoter.SavePath = "SAVE\" + GetStorylineDir(FindCurrentStoryline());
	LayerAddObject(layer, &scrshoter, -1);
// <-- KK
}

void LaunchCustomization()// -[choose character mod]->
{
	if(procInterfacePrepare(INTERFACE_CUSTOMIZATION))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_CUSTOMIZATION;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}// <-[choose character mod]-

void LaunchGambling(ref refCharacter, string gameName)// -[gamble in tavern mod]->
{
	if(procInterfacePrepare(INTERFACE_GAMBLE))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_GAMBLE;
		InitInterface_RS(Interfaces[CurrentInterface].IniFile, refCharacter, gameName);
	}
}// <-[gamble in tavern mod]-

#event_handler("StartMutiny", "LaunchMutinyScreen");// -[new "Mutiny"]->
void LaunchMutinyScreen()
{
	if(CheckAttribute(GetMainCharacter(),"Mutiny")) return;
	if(procInterfacePrepare(INTERFACE_MUTINY))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_MUTINY;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}// <-[new "Mutiny"]-


void LaunchAboutBuildScreen()
{
	if(procInterfacePrepare(INTERFACE_ABOUT_BUILD))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_ABOUT_BUILD;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}

void LaunchOfficer(ref refCharacter)
{
	if( curKeyGroupName=="WorldMapControls" || curKeyGroupName=="FightModeControls" ) return;
	if( sti(InterfaceStates.Buttons.Resume.enable)==false ) return;
	bool bDisable = false;
	if( !IsEnableMenuLaunch() ) bDisable = true;
	if( bDisable )
	{
		Log_SetStringToLog(XI_ConvertString("You can`t launch menu"));
		return;
	}

	if(procInterfacePrepare(INTERFACE_OFFICER))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_OFFICER;
		InitInterface_R(Interfaces[CurrentInterface].IniFile,refCharacter);
	}
}

// KK -->
void LaunchMap(int map)
{
	if(procInterfacePrepare(INTERFACE_MAP))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_MAP;
		InitInterface_I(Interfaces[CurrentInterface].IniFile, map);
	}
}
// <-- KK
// Levis Readable Books -->
void LaunchBook(ref book)
{
	if(procInterfacePrepare(INTERFACE_BOOK))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_BOOK;
		InitInterface_BB(Interfaces[CurrentInterface].IniFile, book);
	}
}
// <-- Levis Readable Books

//MAXIMUS <--

void LaunchEndGameMenu()
{
	if(procInterfacePrepare(INTERFACE_ENDGAME))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_ENDGAME;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}

void LaunchPlayGame(ref chref)
{
	if(procInterfacePrepare(INTERFACE_PLAYGAME))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_PLAYGAME;
		InitInterface_R(Interfaces[CurrentInterface].IniFile, chref);
	}
}

#event_handler("AskingSalary", "LaunchSalaryScreen")
void LaunchSalaryScreen()
{
	ref PChar = GetMainCharacter();
	int payment = CalcSquadronPayment(PChar);
	if (payment == 0)
	{
		PChar.LastPayMonth = GetDataMonth();
		return;
	}

	if(procInterfacePrepare(INTERFACE_SALARY))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_SALARY;
		InitInterface_I(Interfaces[CurrentInterface].IniFile, payment);
	}
}
// boal -->
void LaunchBoalMapScreen()
{
	if(procInterfacePrepare(INTERFACE_BOAL_MAP))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_BOAL_MAP;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}
// boal <--
void LaunchPerksScreen(ref chref)
{
	if(procInterfacePrepare(INTERFACE_PERKS))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_PERKS;
		InitInterface_R(Interfaces[CurrentInterface].IniFile,chref);
	}
}

void LaunchControlsScreen()
{
	if(procInterfacePrepare(INTERFACE_CONTROLS))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_CONTROLS;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}

void LaunchItemsTrade(ref chref)
{
	// LDH if we've gotten this far and the trader has no itemlist, we need to add it - 16Mar09
	if (!CheckAttribute(chref, "itemtrade.itemlist"))
	{
		Trace("LaunchItemsTrade() gave new items to trader");
		GiveItemToTrader(chref);
		chref.quest.item_date = environment.date.day + " " environment.date.month;	// lastspeak date
	}
	if(procInterfacePrepare(INTERFACE_ITEMSTRADE))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_ITEMSTRADE;
		InitInterface_RR(Interfaces[CurrentInterface].IniFile,GetMainCharacter(),chref);
	}
}

void LaunchSelectMenu()
{
	if( curKeyGroupName=="WorldMapControls" || curKeyGroupName=="FightModeControls" ) return;
	if( sti(InterfaceStates.Buttons.Resume.enable)==false ) return;
	bool bDisable = false;
	if( !IsEnableMenuLaunch() ) bDisable = true;
	// boal cabin -->
	// NK enable launching menu in boarding -- if( bSeaActive && bAbordageStarted && !bCabinStarted) bDisable = true;
	// boal cabin <--
	if( bDisable )
	{
		Log_SetStringToLog(XI_ConvertString("You can`t launch menu"));
		return;
	}
	if(procInterfacePrepare(INTERFACE_SELECTMENU))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_SELECTMENU;
		InitInterface(Interfaces[CurrentInterface].IniFile);
		if(CheckAttribute(&InterfaceStack,"SelectMenu_node"))
		{
			SetCurrentNode(InterfaceStack.SelectMenu_node);
		}
	}
}

void LaunchInstallError()
{
	if(procInterfacePrepare(INTERFACE_INSTALLERROR))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_INSTALLERROR;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}

bool PlayerInterface(string nodName)//MAXIMUS: don't add any other interfaces here
{
	if(nodName=="I_CHARACTER") return true;
	if(nodName=="I_SHIP") return true;
	if(nodName=="I_SHIPHOLD") return true;
	if(nodName=="I_PASSENGER") return true;
	if(nodName=="I_TRADEBOOK") return true;
	if(nodName=="I_QUESTBOOK") return true;
	if(nodName == "I_SHIPLOG") return true; // KK
	if(nodName=="I_NATIONS") return true;
	if(nodName=="I_ITEMS") return true;
	// KK if(nodName=="I_MAP") return true;

	return false;
}

void LaunchMoneyTransfer()
{
	if(procInterfacePrepare(INTERFACE_MONEYT))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_MONEYT;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}

void LaunchShipTransfer()	// changed after build 11 by KAM to allow transfer between non-player-character ships
{

	ref MainChar=GetMainCharacter();
	int TransferCharAIdx = MainChar.shiptransferinterface.char1;
	ref TransferCharA = GetCharacter(TransferCharAIdx);
	int TransferCharBIdx = MainChar.shiptransferinterface.char2;
	ref TransferCharB = GetCharacter(TransferCharBIdx);

	if (!CheckAttribute(MainChar,"shiptransferinterface"))
	{
		MainChar.shiptransferinterface.calledfrominterface = 0;
		MainChar.shiptransferinterface.involvesberthedship = 0;
		MainChar.shiptransferinterface.donotallowcaptainchange = 0;
	}

	if(procInterfacePrepare(INTERFACE_TRANSFER_MAIN))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_TRANSFER_MAIN;
		InitInterface_RRS(Interfaces[CurrentInterface].IniFile,TransferCharA,TransferCharB,"");
	}
}



// End GreatZen Interface Mod

//added by KAM -->
void LaunchKAMSelectModel()
{
	ref pchar = GetMainCharacter();
	pchar.kammodelselecttempattrib = 0;
	if(procInterfacePrepare(INTERFACE_KAM_SELECTMODEL))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_KAM_SELECTMODEL;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
	DeleteAttribute(pchar,"kammodelselecttempattrib")
}

void LaunchKAMSelectOfficerModel(int officerid)
{
	ref pchar = GetMainCharacter();
	pchar.kammodelselecttempattrib = officerid;
	if(procInterfacePrepare(INTERFACE_KAM_SELECTMODEL))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_KAM_SELECTMODEL;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
	DeleteAttribute(pchar,"kammodelselecttempattrib")
}

void LaunchKAMSelectSails()
{
	if(procInterfacePrepare(INTERFACE_KAM_SELECTSAILS))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_KAM_SELECTSAILS;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}

void LaunchKAMShipTransfer()
{
	if(procInterfacePrepare(INTERFACE_KAM_SHIPTRANSFER))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_KAM_SHIPTRANSFER;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}

void LaunchKAMRations()
{
	if(procInterfacePrepare(INTERFACE_KAM_RATIONS))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_KAM_RATIONS;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}

void LaunchKAMArticles()
{
	if(procInterfacePrepare(INTERFACE_KAM_ARTICLES))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_KAM_ARTICLES;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}

void LaunchKAMShipBerthing()		// added after release of v11 by KAM
{
	if(procInterfacePrepare(INTERFACE_KAM_SHIPBERTHING))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_KAM_SHIPBERTHING;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}

/*NK I don't have this yet, commented out.
void LaunchBlacksmith(ref chref)
{
	if(procInterfacePrepare(INTERFACE_BLACKSMITH))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_BLACKSMITH;
		InitInterface_RR(Interfaces[CurrentInterface].IniFile,GetMainCharacter(),chref);
	}
}*/
// <-- added by KAM

void LaunchOptionScreen()
{
	if(procInterfacePrepare(INTERFACE_OPTIONSCREEN))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_OPTIONSCREEN;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}

void LaunchHelpScreen(string help_section)
{
	if(procInterfacePrepare(INTERFACE_HELPSCREEN))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_HELPSCREEN;
		InitInterface_S(Interfaces[CurrentInterface].IniFile,help_section);
	}
}

void LaunchCharacterItemChange(ref chref)
{
	if(procInterfacePrepare(INTERFACE_ITEMSBOX))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_ITEMSBOX;
		aref charef; makearef(charef,chref);
		InitInterface_RS(Interfaces[CurrentInterface].IniFile,&charef,chref.FaceID);
	}
}

void LaunchItemsBox(ref boxRef)
{
	if(procInterfacePrepare(INTERFACE_ITEMSBOX))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_ITEMSBOX;
		InitInterface_RS(Interfaces[CurrentInterface].IniFile,boxRef,"");
	}
}

void LaunchFortCapture(ref chref)
{
	if(procInterfacePrepare(INTERFACE_FORTCAPTURE))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_FORTCAPTURE;
		InitInterface_R(Interfaces[CurrentInterface].IniFile,chref);
	}
}

void LaunchShipState()
{
	if(procInterfacePrepare(INTERFACE_SHIP_CHOOSE))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_SHIP_CHOOSE;
		InitInterface_I(Interfaces[CurrentInterface].IniFile,true);
	}
}

void LaunchStore(int storeNum)
{
    if(storeNum<0)	return;
    if(storeNum>STORE_QUANTITY-1)	return;
	gStoreNum=storeNum;

	// TIH --> ship chooser handler Jul17'06
	// if only one ship, no need to choose, just auto-select it and send them to the store
	// if more than one ship, then when they exit the store, they return to the ship chooser
	int numCompanions = GetCompanionQuantity(GetMainCharacter());
	if (numCompanions > 1) {
		if(procInterfacePrepare(INTERFACE_SHIP_CHOOSE))
		{
			nPrevInterface = INTERFACE_STORE;
			CurrentInterface = INTERFACE_SHIP_CHOOSE;
			InitInterface_I(Interfaces[CurrentInterface].IniFile,false);
		}
	} else {
		if(procInterfacePrepare(INTERFACE_STORE))
		{
			nPrevInterface = -1;
			CurrentInterface = INTERFACE_STORE;
			InitInterface_RR(Interfaces[CurrentInterface].IniFile,GetMainCharacter(),&stores[gStoreNum]);
		}
	}
	/* prior method
	if(procInterfacePrepare(INTERFACE_SHIP_CHOOSE))
	{
		nPrevInterface = INTERFACE_STORE;
		CurrentInterface = INTERFACE_SHIP_CHOOSE;
		InitInterface_I(Interfaces[CurrentInterface].IniFile,false);
	}
	*/
	// TIH <--
}

void LaunchShipyard(ref shipmaster)
{
	if(procInterfacePrepare(INTERFACE_SHIPYARD))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_SHIPYARD;
		InitInterface_R(Interfaces[CurrentInterface].IniFile,shipmaster);
	}
}

void LaunchCannons()
{
/*	if(procInterfacePrepare(INTERFACE_CANNONS))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_CANNONS;
		InitInterface_R(Interfaces[CurrentInterface].IniFile, shipmaster);
	}*/
}

void LaunchCharacter(ref refCharacter)
{
	if(procInterfacePrepare(INTERFACE_CHARACTER))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_CHARACTER;
		InitInterface_R(Interfaces[CurrentInterface].IniFile,refCharacter);
	}
}

void LaunchMainMenu_afterVideo()
{
	DelEventHandler(EVENT_END_VIDEO,"LaunchMainMenu_afterVideo");
	InterfaceStates.LaunchAnyway = true;
	LaunchMainMenu();
}

//->Inez
/*void LaunchBuildsetttingsMenu()
{
	if(procInterfacePrepare(INTERFACE_BUILDSETTINGS))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_BUILDSETTINGS;
        LoadSegment(Interfaces[CurrentInterface].SectionName); //???
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}*/
//<-Inez

void LaunchMainMenu()
{
	if(procEnableInterfaceLaunch(INTERFACE_MAINMENU)==false)
	{
		if( CheckAttribute(&InterfaceStates,"LaunchAnyway") && sti(InterfaceStates.LaunchAnyway)==true )
		{
			PostEvent("LaunchIAfterFrame",1,"sl","I_MAINMENU",1);
			InterfaceStates.LaunchAfterFrame = "I_MAINMENU";
		}
		return;
	}
	DeleteAttribute(&InterfaceStates,"LaunchAnyway");
	if(g_ibVideoExecuting) return;
	InterfaceStates.Launched = true;
	InterfaceStates.doUnFreeze = false;

	SetEventHandler("makescrshot","LaunchMainMenuContinue",0);
	aref arScrShoter;
	if (!GetEntity(&arScrShoter,"scrshoter")) {
		CreateScreenShoter();
		PostEvent("makescrshot",10); // Levis: was 1
	} else {
		Event("makescrshot");
	}
}

void LaunchMainMenuContinue()
{
	DelEventHandler("makescrshot","LaunchMainMenuContinue");
	DeleteAttribute(&InterfaceStates,"MakeScreenShot");
	ISetSoundEvents();
	nPrevInterface = -1;
	CurrentInterface = INTERFACE_MAINMENU;
	EngineLayersOffOn(false);

	bGamePadChangeEnable = true;
	LoadSegment(Interfaces[CurrentInterface].SectionName);
	InitInterface(Interfaces[CurrentInterface].IniFile);
}

void LaunchSaveGame()
{
	if(procInterfacePrepare(INTERFACE_SAVELOAD))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_SAVELOAD;
		InitInterface_B(Interfaces[CurrentInterface].IniFile,true);
	}
}

void LaunchLoadGame()
{
	if(procInterfacePrepare(INTERFACE_SAVELOAD))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_SAVELOAD;
		InitInterface_B(Interfaces[CurrentInterface].IniFile,false);
	}
}

void LaunchShipHold()
{
	if(procInterfacePrepare(INTERFACE_SHIPHOLD))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_SHIPHOLD;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}

// Sulan -->
void LaunchNews()
{
	if(procInterfacePrepare(INTERFACE_NEWS))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_NEWS;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}

void LaunchMonkey()
{
	if(procInterfacePrepare(INTERFACE_MONKEY))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_MONKEY;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}
// < -- Sulan

void LaunchHireCrew()
{
	if(procInterfacePrepare(INTERFACE_HIRECREW))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_HIRECREW;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}

void LaunchPassengers(ref _refCharacter)
{
	if(procInterfacePrepare(INTERFACE_PASSENGERS))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_PASSENGERS;
		InitInterface_R(Interfaces[CurrentInterface].IniFile,_refCharacter);
	}
}

void LaunchRansackJoin(ref _refMy,ref _refEnemy)
{
	if(procInterfacePrepare(INTERFACE_RANSACK_JOIN))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_RANSACK_JOIN;
		InitInterface_RR(Interfaces[CurrentInterface].IniFile,_refMy,_refEnemy);
	}
}

void LaunchRansackCrew(ref _refMy,ref _refEnemy)
{
	if(procInterfacePrepare(INTERFACE_RANSACK_CREW))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_RANSACK_CREW;
		InitInterface_RR(Interfaces[CurrentInterface].IniFile,_refMy,_refEnemy);
	}
}

void LaunchRansackCaptain(ref _refMy,ref _refEnemy)
{
	if(procInterfacePrepare(INTERFACE_RANSACK_CAPTAIN))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_RANSACK_CAPTAIN;
		InitInterface_RR(Interfaces[CurrentInterface].IniFile,_refMy,_refEnemy);
	}
}

void LaunchRansackMain(ref _refMy,ref _refEnemy,string newCurNod)
{
	if(procInterfacePrepare(INTERFACE_RANSACK_MAIN))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_RANSACK_MAIN;
		InitInterface_RRS(Interfaces[CurrentInterface].IniFile,_refMy,_refEnemy,newCurNod);
	}
}

void LaunchTransferMain(ref _refMy,ref _refEnemy,string newCurNod)
{
	if(procInterfacePrepare(INTERFACE_TRANSFER_MAIN))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_TRANSFER_MAIN;
		InitInterface_RRS(Interfaces[CurrentInterface].IniFile,_refMy,_refEnemy,newCurNod);
	}
}

void LaunchTransferGoods(ref _refMy,ref _refOther)
{
	if(procInterfacePrepare(INTERFACE_TRANSFER_GOODS))
	{
		nPrevInterface = CurrentInterface;
		CurrentInterface = INTERFACE_TRANSFER_GOODS;
		InitInterface_RR(Interfaces[CurrentInterface].IniFile,_refMy,_refOther);
	}
}

void LaunchTransferCharacter(ref _refMy,ref _refEnemy)
{
	if(procInterfacePrepare(INTERFACE_TRANSFER_CHARACTER))
	{
		nPrevInterface = CurrentInterface;
		CurrentInterface = INTERFACE_TRANSFER_CHARACTER;
		InitInterface_RR(Interfaces[CurrentInterface].IniFile,_refMy,_refEnemy);
	}
}

void LaunchTransferCrew(ref _refMy,ref _refEnemy)
{
	if(procInterfacePrepare(INTERFACE_TRANSFER_CREW))
	{
		nPrevInterface = CurrentInterface;
		CurrentInterface = INTERFACE_TRANSFER_CREW;
		InitInterface_RR(Interfaces[CurrentInterface].IniFile,_refMy,_refEnemy);
	}
}
// added by MAXIMUS -->
void LaunchTransferCannons(ref _refMy,ref _refEnemy)
{
	if(procInterfacePrepare(INTERFACE_TRANSFER_CANNONS))
	{
		nPrevInterface = CurrentInterface;
		CurrentInterface = INTERFACE_TRANSFER_CANNONS;
		InitInterface_RR(Interfaces[CurrentInterface].IniFile,_refMy,_refEnemy);
	}
}
// added by MAXIMUS <--

void LaunchQuestBook()
{
	if(procInterfacePrepare(INTERFACE_QUESTBOOK))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_QUESTBOOK;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}

void LaunchTradeBook(string town)
{
	if(procInterfacePrepare(INTERFACE_TRADEBOOK))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_TRADEBOOK;
		InitInterface_S(Interfaces[CurrentInterface].IniFile, town);
	}
}

// KK -->
void LaunchShipLog()
{
	if(procInterfacePrepare(INTERFACE_SHIPLOG))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_SHIPLOG;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}
// <-- KK

void LaunchNationRelation()
{
	if(procInterfacePrepare(INTERFACE_NATIONRELATION))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_NATIONRELATION;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}

// KK -->
void LaunchItems(int item)
{
	if(procInterfacePrepare(INTERFACE_ITEMS))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_ITEMS;
		InitInterface_I(Interfaces[CurrentInterface].IniFile, item);
	}
}

void LaunchCaptureColony(ref _refCharacter, string _sColony)
{
	if(procInterfacePrepare(INTERFACE_CAPTURE_COLONY))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_CAPTURE_COLONY;
		InitInterface_RS(Interfaces[CurrentInterface].IniFile, _refCharacter, _sColony);
	}
}

void LaunchSelectStoryline()
{
	if(procInterfacePrepare(INTERFACE_SELECT_STORYLINE))
	{
		nPrevInterface = -1;
		CurrentInterface = INTERFACE_SELECT_STORYLINE;
		InitInterface(Interfaces[CurrentInterface].IniFile);
	}
}
// <-- KK

void LaunchGame()
{
	//if(procEnableInterfaceLaunch(INTERFACE_CHARACTER_SELECT)==false) return;
	//InterfaceStates.Launched = true;
	//InterfaceStates.doUnFreeze = false;
	//EngineLayersOffOn(false);

	SetEventHandler(EVENT_END_VIDEO,"ISTART_Game",0);
	PostEvent(EVENT_END_VIDEO,0);
	//StartVideo("3Ship");
}

void ISTART_Game()
{
	DelEventHandler(EVENT_END_VIDEO,"ISTART_Game");
	//ISetSoundEvents();
	//nPrevInterface = -1;
    //CurrentInterface = INTERFACE_CHARACTER_SELECT;
    //LoadSegment(Interfaces[CurrentInterface].SectionName);
    //InitInterface(Interfaces[CurrentInterface].IniFile);
	SetMainCharacterIndex(0);
	interfaceResultCommand = RC_INTERFACE_SELECT_STORYLINE_EXIT;
	Start_InterfaceDoExit();
}

void EndOkInterface()
{
    UnloadSegment(Interfaces[CurrentInterface].SectionName);

	// TIH --> store ship chooser handler Jul17'06
	switch( nPrevInterface ) {
		case INTERFACE_STORE:
			int cn = GetCompanionIndex(GetMainCharacter(),sti(GameInterface.FourImage.current));
			if(cn!=-1)
			{
				DeleteAttribute(&GameInterface,"");
				CurrentInterface = INTERFACE_STORE;
				LoadSegment(Interfaces[CurrentInterface].SectionName);
				InitInterface_RR(Interfaces[CurrentInterface].IniFile,GetCharacter(cn),&stores[gStoreNum]);
			}
			return;
		break;
		case INTERFACE_SHIP_CHOOSE:
			DeleteAttribute(&GameInterface,"");
			nPrevInterface = INTERFACE_STORE;
			CurrentInterface = INTERFACE_SHIP_CHOOSE;
			LoadSegment(Interfaces[CurrentInterface].SectionName);
			InitInterface_I(Interfaces[CurrentInterface].IniFile,false);
			/*
			if(procInterfacePrepare(INTERFACE_SHIP_CHOOSE))
			{
				nPrevInterface = INTERFACE_STORE;
				CurrentInterface = INTERFACE_SHIP_CHOOSE;
				InitInterface_I(Interfaces[CurrentInterface].IniFile,false);
			}
			*/
			
			return;
			
		break;
	}
	// if it got this far, it does default actions
// KK -->
	EngineLayersOffOn(false);
	if (bSeaActive)
		Event("BI_EVENT_SET_VISIBLE", "l", true);
	else
		BLIVisible(true);
// <-- KK
	IDeleteSoundEvents();
	Start_InterfaceDoExit();
	/* prior method
	if(nPrevInterface == INTERFACE_STORE)
	{
		int cn = GetCompanionIndex(GetMainCharacter(),sti(GameInterface.FourImage.current));
		if(cn!=-1)
		{
			DeleteAttribute(&GameInterface,"");
			CurrentInterface = INTERFACE_STORE;
			LoadSegment(Interfaces[CurrentInterface].SectionName);
			InitInterface_RR(Interfaces[CurrentInterface].IniFile,GetCharacter(cn),&stores[gStoreNum]);
		}
		else
		{
			IDeleteSoundEvents();
			Start_InterfaceDoExit();
		}
	}
	else
	{
		IDeleteSoundEvents();
	    Start_InterfaceDoExit();
	}
	*/
	// TIH <--
}

void EndCancelInterface(bool bYesRelease)
{
	ref refObj1,refObj2;
	bGamePadChangeEnable = false;
	switch(interfaceResultCommand)
	{
	case RC_INTERFACE_RANSACK_JOIN_EXIT: refObj1 = GetMyCharacterRef(); refObj2 = GetEnemyCharacterRef(); break;
	case RC_INTERFACE_RANSACK_CREW_EXIT: refObj1 = GetMyCharacterRef(); refObj2 = GetEnemyCharacterRef(); break;
	case RC_INTERFACE_RANSACK_CAPTAIN_EXIT: refObj1 = GetMyCharacterRef(); refObj2 = GetEnemyCharacterRef(); break;
	case RC_INTERFACE_TRANSFER_START_GOODS: refObj1 = GetMyCharacterRef(); refObj2 = GetEnemyCharacterRef(); ICurNode = GetCurrentNode(); break;
	case RC_INTERFACE_TRANSFER_START_CHARACTERS: refObj1 = GetMyCharacterRef(); refObj2 = GetEnemyCharacterRef(); ICurNode = GetCurrentNode(); break;
	case RC_INTERFACE_TRANSFER_START_CREW: refObj1 = GetMyCharacterRef(); refObj2 = GetEnemyCharacterRef(); ICurNode = GetCurrentNode(); break;
	case RC_INTERFACE_TRANSFER_START_CANNONS: refObj1 = GetMyCharacterRef(); refObj2 = GetEnemyCharacterRef(); ICurNode = GetCurrentNode(); break; // added by MAXIMUS
	case RC_INTERFACE_TRANSFER_MAIN_RETURN: refObj1 = GetMyCharacterRef(); refObj2 = GetEnemyCharacterRef(); break;
	}
// KK -->
	EngineLayersOffOn(false);
	if (bSeaActive)
		Event("BI_EVENT_SET_VISIBLE", "l", true);
	else
		BLIVisible(true);
// <-- KK
	InterfaceStates.doUnFreeze = bYesRelease;
	UnloadSegment(Interfaces[CurrentInterface].SectionName);
	IDeleteSoundEvents();
	switch(interfaceResultCommand)
	{
	case RC_INTERFACE_RANSACK_JOIN_EXIT: InterfaceStates.Launched=false; LaunchRansackCrew(refObj1,refObj2); return; break;
	case RC_INTERFACE_RANSACK_CREW_EXIT: InterfaceStates.Launched=false; LaunchRansackCaptain(refObj1,refObj2); return; break;
	case RC_INTERFACE_RANSACK_CAPTAIN_EXIT: InterfaceStates.Launched=false; LaunchRansackMain(refObj1,refObj2,""); return; break;
	case RC_INTERFACE_TRANSFER_START_GOODS: InterfaceStates.Launched=false; LaunchTransferGoods(&Characters[sti(refObj1.index)],&Characters[sti(refObj2.index)]); return; break;
	case RC_INTERFACE_TRANSFER_START_CHARACTERS: InterfaceStates.Launched=false; LaunchTransferCharacter(refObj1,refObj2); return; break;
	case RC_INTERFACE_TRANSFER_START_CREW: InterfaceStates.Launched=false; LaunchTransferCrew(refObj1,refObj2); return; break;
	case RC_INTERFACE_TRANSFER_START_CANNONS: InterfaceStates.Launched=false; LaunchTransferCannons(refObj1,refObj2); return; break; // added by MAXIMUS
	case RC_INTERFACE_TRANSFER_MAIN_RETURN:
		if(nPrevInterface==INTERFACE_RANSACK_MAIN)
		{
			InterfaceStates.Launched=false; LaunchRansackMain(refObj1,refObj2,ICurNode);
		}
		else
		{
			InterfaceStates.Launched=false; LaunchTransferMain(refObj1,refObj2,ICurNode);
		}
		return;
		break;
	}
	Start_InterfaceDoExit();
	if(bYesRelease)	PostEvent("evntQuestsCheck",1);
}

// стек для вложенных интерфейсов
object InterfaceStack;
void ClearInterfaceStack()
{
	DeleteAttribute(InterfaceStack,"");
	InterfaceStack.size=0;
}
void PushInterface(int iIndex,string iTitle,string iStartNod)
{
	if(!CheckAttribute(&InterfaceStack,"size"))	InterfaceStack.size = 0;
	string StackSlot = "Slot"+InterfaceStack.size;
	InterfaceStack.(StackSlot).index = iIndex;
	InterfaceStack.(StackSlot).title = iTitle;
	InterfaceStack.(StackSlot).start = iStartNod;
	InterfaceStack.size = sti(InterfaceStack.size)+1;
}
bool PopInterface()
{
	if(!CheckAttribute(&InterfaceStack,"size"))	InterfaceStack.size = 0;
	if(sti(InterfaceStack.size)<1) return false;
	InterfaceStack.size = sti(InterfaceStack.size)-1;
	string StackSlot = "Slot"+InterfaceStack.size;
	CurrentInterface = sti(InterfaceStack.(StackSlot).index);
	switch(CurrentInterface)
	{
	case INTERFACE_STORE:
		break;
	case INTERFACE_RANSACK_MAIN:
		break;
	case INTERFACE_TRANSFER_MAIN:
		break;
	}
	DeleteAttribute(&InterfaceStack,StackSlot);
	return true;
}
void I_PushString(string str)
{
	aref arStrStack;
	makearef(arStrStack,InterfaceStack.strings);
	int q = GetAttributesNum(arStrStack);
	string stackSlotName = "s"+q;
	InterfaceStack.strings.(stackSlotName) = str;
}
string I_PopString()
{
	aref arStrStack;
	makearef(arStrStack,InterfaceStack.strings);
	int q = GetAttributesNum(arStrStack)-1;
	if(q<0) return "";
	string stackSlotName = "s"+q;
	string retStr = InterfaceStack.strings.(stackSlotName);
	DeleteAttribute(&InterfaceStack,"strings."+stackSlotName);
	return retStr;
}

void ISetSoundEvents()
{
	SetEventHandler(ISOUND_EVENT,"IDoSoundEvent",0);
}
void IDeleteSoundEvents()
{
	DelEventHandler(ISOUND_EVENT,"IDoSoundEvent");
}
void IDoSoundEvent()
{
	int comCode = GetEventData();
	if (comCode == ACTION_DEACTIVATE) // KK
	{
		PlaySound("interface\cancel.wav");
	}
	else
	{
		PlaySound("interface\ok.wav");
	}
}

//#event_handler("evntPostVideo","stPostVideo");
object aviVideoObj;
void StartPostVideo(string vidName,int n)
{
	SetEventHandler("evntPostVideo","stPostVideo",0);
	PostEvent("evntPostVideo",n,"s",vidName);
}
void stPostVideo()
{
	DelEventHandler("evntPostVideo","stPostVideo");
	string sVidName = GetEventData();
	StartVideo(sVidName);
}
void PostVideoAndQuest(string vidName,int n,string sQuestName)
{
	aviVideoObj.afterQuestName = sQuestName;
	StartPostVideo(vidName,n);
}
bool g_ibVideoExecuting = false;
void StartVideo(string vidName)
{
	if(IsEntity(&aviVideoObj))
	{
		DeleteClass(&aviVideoObj);
		StartPostVideo(vidName,1);
	}
	g_ibVideoExecuting = true;
	bool bPlay = ENABLE_VIDEOS == true; // KK
	if(bPlay)// TIH --> videos toggle 7-7-06
	{
		PauseAllSounds();
		ResetSoundScheme();
	}// TIH <-- videos toggle
	if(sti(InterfaceStates.Launched))
	{
		InterfaceStates.InstantExit = true;
		Event("exitCancel");
		DeleteAttribute(&InterfaceStates,"InstantExit");
	}
	SetEventHandler("ievntEndVideo","_Procedure_EndVideoPlay",0);
	if(bPlay)
	{
		EngineLayersOffOn(false);
		if(bSeaActive && !bAbordageStarted) aviVideoObj.layer = "sea";
		else aviVideoObj.layer = "land";
		if(GetTargetPlatform()=="pc") CreateEntity(&aviVideoObj,"CAviPlayer");
		else CreateEntity(&aviVideoObj,"WMVideoPlay");
		SendMessage(&aviVideoObj,"ls",MSG_SET_VIDEO_PLAY,GetVideoFileName(vidName));// TIH <-- videos toggle
	}
	bGamePadChangeEnable = true;
	bPlayVideoNow = true;
	bBreakVideoDisable = true;

	SetEventHandler("Control Activation","IVideoBreak",0);
	if(!IsEntity(aviVideoObj))
	{
		Trace("Can`t create video player");
		PostEvent("ievntEndVideo",0);
	}
}
bool bBreakVideoDisable = false;
void IVideoBreak()
{
	string ControlName = GetEventData();
	// NK enable break all videos
	/*bool bMakeBreak = false;
	if( ControlName=="ICancel" )	{bMakeBreak = true;}
	if( !bBreakVideoDisable )
	{
		if( ControlName=="IStartButton" || ControlName=="IAllCancel" ||
			ControlName=="IAction" ) {bMakeBreak = true;}
	} else {
		if(!EnableVideoBreak) {bMakeBreak = false;}
	}
	if(bMakeBreak)
	{*/
		DelEventHandler("Control Activation","IVideoBreak");
		Event("ievntEndVideo");
	//}
	// NK <--
}

void _Procedure_EndVideoPlay()
{
	g_ibVideoExecuting = false;
	bBreakVideoDisable = false;
	DelEventHandler("Control Activation","IVideoBreak");
	//ResumeAllSounds();
	DeleteClass(&aviVideoObj);
	if(bMainMenuLaunchAfterVideo)
	{
		bMainMenuLaunchAfterVideo = false;
		Event("DoInfoShower","sl","MainMenuLaunch",true);
	} else {InfoShowSetting();}
	bGamePadChangeEnable = false;
	bPlayVideoNow = false;
	DelEventHandler("ievntEndVideo","_Procedure_EndVideoPlay");
	if(CheckAttribute(aviVideoObj,"layer"))
	{
		if(aviVideoObj.layer == "land")
		{
			LayerFreeze(REALIZE,false);
			LayerFreeze(EXECUTE,false);
		}
		if(aviVideoObj.layer == "sea")
		{
			LayerFreeze(SEA_REALIZE,false);
			LayerFreeze(SEA_EXECUTE,false);
		}
	}
	if(sti(InterfaceStates.Launched)) EngineLayersOffOn(false);
	if(CheckAttribute(&aviVideoObj,"afterQuestName"))
	{
		DoQuestCheckDelay(aviVideoObj.afterQuestName,0.1);
		//QuestComplete(aviVideoObj.afterQuestName);
		//QuestsCheck();
		DeleteAttribute(&aviVideoObj,"afterQuestName");
	}
	PostEvent(EVENT_END_VIDEO,1);
	ResumeAllSounds();
	if(FindLoadedLocation()!=-1) SetSchemeForLocation(&locations[FindLoadedLocation()]);
}

int GetCurrentInterface()
{
	return CurrentInterface;
}

void ISetSaveData(string saveName, string saveData)
{
	SendMessage(&GameInterface,"lss",MSG_INTERFACE_DO_SAVE_DATA,saveName,saveData);
}

string Save_retStr; // LDH 26Oct16
string IGetSaveString(string saveName)
{
	SendMessage(&GameInterface,"lse",MSG_INTERFACE_GET_SAVE_DATA,saveName,&Save_retStr);
	return Save_retStr;
}

bool procEnableInterfaceLaunch(int _interfaceCode)
{
	if(sti(InterfaceStates.Launched)==true) return false;
// KK -->
	if(IsEntity(reload_fader)) return false;
	/*if(DialogRun!=0)
	{
		if(_interfaceCode!=INTERFACE_HELPSCREEN)	return false;
	}*/
// <-- KK
	return true;
}

bool bRunHelpChooser = false;
void RunHelpChooser()
{
	string chooserName = "";
	if(bSeaActive && !bAbordageStarted)	chooserName = "sea_interface";
	else if( IsEntity(worldMap) )	chooserName = "world_map";
	else if( DialogRun )	chooserName = "Dialog_window";
	else chooserName = "land_interface";

	if(chooserName=="")
	{
		LaunchHelpScreen("");
		return;
	}

	DeleteEntitiesByType("HELPCHOOSER");
	SetEventHandler("EventEndHelpChooser","ProcEndHelpChooser",0);
	object objHelpChooser;
	CreateEntity(&objHelpChooser,"HELPCHOOSER");
	if( !IsEntity(&objHelpChooser) )
	{
		Event("EventEndHelpChooser","s","");
		return;
	}
	if( !SendMessage(&objHelpChooser,"ls",MSG_HELPCHOOSER_START,chooserName) )
	{
		Event("EventEndHelpChooser","s","");
	}
	bRunHelpChooser = true;
	EngineLayersOffOn(false);
	InterfaceStates.Launched=true;
	LayerAddObject(INTERFACE_EXECUTE,&objHelpChooser,10000);
	LayerAddObject(INTERFACE_REALIZE,&objHelpChooser,10000);
}

void ProcEndHelpChooser()
{
	string HelpSectionName = GetEventData();
	DelEventHandler("EventEndHelpChooser","ProcEndHelpChooser");
	DeleteEntitiesByType("HELPCHOOSER");
	bRunHelpChooser = false;
	InterfaceStates.Launched=false;
	if(HelpSectionName!="")	LaunchHelpScreen(HelpSectionName);
	else EngineLayersOffOn(true);
}

void ReturnToMainMenu()
{
	/*if(sti(InterfaceStates.Buttons.Resume.enable)==true)
	{
		if(bSeaActive) return;
		if(IsEntity(&worldMap)) return;
		if(FindLoadedLocation()!=-1) return;
	}*/
	DelEventHandler("frame","InterfaceDoExit");
	EngineLayersOffOn(false);
	InterfaceStates.Launched = false;
	InterfaceStates.MakeScreenShot = false;
	LaunchMainMenu();
}

void ILaunchAfterFrame()
{
	ref PChar = GetMainCharacter(); // added after build 11 by KAM

	string nodName = GetEventData();
	int n = GetEventData();
	if( CheckAttribute(&InterfaceStates,"LaunchAfterFrame") && InterfaceStates.LaunchAfterFrame!=nodName ) {
		return;
	}
	if(n>0 || sti(InterfaceStates.Launched))
	{
		PostEvent("LaunchIAfterFrame",1,"sl", nodName, n-1);
		return;
	}

	switch(nodName)
	{
	case "I_SELECTMENU":	LaunchSelectMenu();	return; break;

//View Enc Officer: Taghmon

	//case "I_CHARACTER":		LaunchCharacter(GetMainCharacter());	return; break;

// changed by KAM after build 11 -->
	case "I_CHARACTER":
		if (CheckAttribute(PChar,"ChangeOutfitFromCharacterScreen"))
		{
			LaunchCharacter(GetCharacter(sti(PChar.ChangeOutfitFromCharacterScreen)));
			DeleteAttribute(PChar,"ChangeOutfitFromCharacterScreen");
			return;
		}

		// LDH added -->
		if (CheckAttribute(PChar,"ExchangeItemsFromCharacterScreen"))
		{
			LaunchCharacter(GetCharacter(sti(PChar.ExchangeItemsFromCharacterScreen)));
			DeleteAttribute(PChar,"ExchangeItemsFromCharacterScreen");
			return;
		}
		// LDH <--

		if(CheckAttribute(&GameInterface,"AbilityChr"))
		{
			LaunchCharacter(GetCharacter(sti(GameInterface.AbilityChr)));
		}
		else
		{
			LaunchCharacter(PChar);
		}
		return;
	break;
// <-- changed by KAM after buid 11

//View Enc Officer End

//MAXIMUS Interface MOD
	case "I_OFFICER":
			if(CheckAttribute(&GameInterface,"AbilityChr"))
			{	       
				LaunchOfficer(GetCharacter(sti(GameInterface.AbilityChr)));
			}
		return;
	break;

	case "I_MAP":			LaunchMap(sti(GameInterface.ItemIdx));	return; break; // KK
	case "A_MAP":			LaunchPelagoMap();						return; break; // PB
//MAXIMUS Interface MOD
	
	case "I_BOOK":			LaunchBook(&Items[sti(GameInterface.ItemIdx)]);	return; break; // Levis Readable Books
	
	case "I_SHIP":
// KK -->
		if (CheckAttribute(GameInterface, "GoDirectToShipBerthing") == true && sti(GameInterface.GoDirectToShipBerthing) == true) {
			DeleteAttribute(GameInterface, "GoDirectToShipBerthing");
			LaunchKAMShipBerthing();
		} else {
			LaunchShipState();
		}
		return;
	break;
// <-- KK
	case "I_SHIPHOLD":		LaunchShipHold();	return; break;
	case "I_PASSENGER":		LaunchPassengers(GetMainCharacter());	return; break;
	case "I_QUESTBOOK":		LaunchQuestBook();	return; break;
// KK -->
	case "I_TRADEBOOK":
		if (CheckAttribute(PChar, "ManageFromColoniesScreen")) {
			LaunchTradeBook(PChar.ManageFromColoniesScreen);
			DeleteAttribute(PChar, "ManageFromColoniesScreen");
		} else {
			LaunchTradeBook("");
		}
		return;
	break;
// <-- KK
	case "I_SHIPLOG":		LaunchShipLog();	return; break; // KK
	case "I_NATIONS":		LaunchNationRelation();	return; break;
	case "I_ITEMS":			if (!CheckAttribute(GameInterface, "ItemIdx")) { LaunchItems(-1); } else { LaunchItems(sti(GameInterface.ItemIdx)); }	return; break; // KK
	case "I_MAINMENU":		LaunchMainMenu(); return; break;
	case "I_TRANSFER": 		LaunchShipTransfer();return;break; //GreatZen
	case "I_MONEY":			LaunchMoneyTransfer();return;break; //GreatZen Interface Mod
	case "I_KAM_SELECTMODEL":	LaunchKAMSelectModel(); return; break;		//added by KAM
	case "I_KAM_SELECTSAILS":	LaunchKAMSelectSails(); return; break;		//added by KAM
	case "I_KAM_SHIPTRANSFER":	LaunchKAMShipTransfer(); return; break;		//added by KAM
	case "I_KAM_ARTICLES":		LaunchKAMArticles(); return; break;		//added by KAM
	case "I_KAM_RATIONS":		LaunchKAMRations(); return; break;		//added by KAM
	case "I_KAM_SHIPBERTHING":	LaunchKAMShipBerthing(); return; break;		// added after release of v11 by KAM

	case "AbilityView":
		if(CheckAttribute(&GameInterface,"AbilityChr"))
		{
			LaunchPerksScreen(GetCharacter(sti(GameInterface.AbilityChr)));
		}
		return;
	break;

	// added by KAM after build 11 -->
	case "ChangeOutfit":
		LaunchKAMSelectOfficerModel(sti(PChar.ChangeOutfitFromCharacterScreen));
		return;
	break;
	// <-- added by KAM after build 11

	// LDH added -->
	case "ExchangeItems":
		LaunchCharacterItemChange(GetCharacter(sti(PChar.ExchangeItemsFromCharacterScreen)));
		return;
	break;
	// LDH <--

// KK -->
	case "ManageColony":
		if (CheckAttribute(PChar, "ManageFromColoniesScreen")) LaunchCaptureColony(PChar, PChar.ManageFromColoniesScreen);
		return;
	break;
// <-- KK
	}
}

bool procInterfacePrepare(int interfaceCode)
{
	if(procEnableInterfaceLaunch(interfaceCode)==false) return false;
	if(g_ibVideoExecuting) return false;
	if( LoadSegment(Interfaces[interfaceCode].SectionName) )
	{
		InterfaceStates.Launched = true;
		InterfaceStates.doUnFreeze = false;
		Log_SetActiveAction("Nothing");
		if (bSeaActive)
			Event("BI_EVENT_SET_VISIBLE", "l", true);
		else
			BLIVisible(true);
		EngineLayersOffOn(false);
		ISetSoundEvents();
		DeleteAttribute(&GameInterface,"");
		return true;
	}
	else
	{
		interfaceResultCommand = RC_INTERFACE_ERROR;
		Start_InterfaceDoExit();
		return false;
	}
}

void Start_InterfaceDoExit()
{
	SetEventHandler("frame","InterfaceDoExit",1);
 	tradeLow = false; //PW reset on exit shop interface after low trade deal

}

void ReloadAfterFortCapture()
{
	ref mchref = GetMainCharacter();
	int fortChr = sti(mchref.from_interface.fortCharacterIdx);
	DeleteAttribute(mchref,"from_interface");
	ref chref = GetCharacter(fortChr);

	string sToLocation = "";
	string sToLocator = "";
	aref ar_FindLoc = FindIslandReloadLocator(chref.location,chref.location.locator);
	if(CheckAttribute(ar_FindLoc,"GoAfterBoard.location"))
	{
		ar_FindLoc = FindIslandReloadLocator(chref.location,ar_FindLoc.GoAfterBoard.location);
		if( CheckAttribute(ar_FindLoc,"go") )
		{	sToLocation = ar_FindLoc.go;
		}
		if( CheckAttribute(ar_FindLoc,"emerge") )
		{	sToLocator = ar_FindLoc.emerge;
		}
	}

	chref.Fort.Mode = FORT_DEAD;
	// data of fort die
	chref.Fort.DieTime.Year = GetDataYear();
	chref.Fort.DieTime.Month = GetDataMonth();
	chref.Fort.DieTime.Day = GetDataDay();
	chref.Fort.DieTime.Time = GetTime();

	SetLocationCapturedState(sToLocation,true);
	Go2LocationAfterAbordage();
	mchref.location.from_sea = sToLocation;
	SetFleetInTown(GetTownIDFromLocID(mchref.location.from_sea), "pchar"); // NK WM/IT 05-04-02
	DoQuestReloadToLocation(sToLocation,"reload",sToLocator,"_");
}

void IProcEventGameOver()
{
	string str = GetEventData();
	if( sti(InterfaceStates.Launched) )
	{
		InterfaceStates.InstantExit = true;
		Event("exitCancel");
		DeleteAttribute(&InterfaceStates,"InstantExit");
	}
	GameOver(str);
}

void IProcEventSetGameTime()
{
	int itmp = GetEventData();
	InterfaceStates.GameTime.hour = itmp;

	itmp = GetEventData();
	InterfaceStates.GameTime.min = itmp;

	itmp = GetEventData();
	InterfaceStates.GameTime.sec = itmp;
}

//==============================================================
//	Секция Показывающая какую либо инфо на экране
//==============================================================
#event_handler("DoInfoShower", "procInfoShow");
object objInfoList[10];

void procInfoShow()
{
	string sInfoID = GetEventData();
	int nInfoSet = false;
	if( sInfoID=="" ) {
		sInfoID = "MainMenuLaunch";
	} else {
		nInfoSet = GetEventData();
	}

	int nInfoIdx = 0;
	switch(sInfoID)
	{
	case "MainMenuLaunch":	nInfoIdx = 0; break;
	case "save game":		nInfoIdx = 1; break;
	case "Low Storage":		nInfoIdx = 2; break;
	case "game prepare":	nInfoIdx = 3; break;
	case "OptionsBreak":	nInfoIdx = 4; break;
	case "lost controller":	nInfoIdx = 5; break;
	}

	int prevQ = 0;
	if( CheckAttribute(&objInfoList[nInfoIdx],"refr") && IsEntity(&objInfoList[nInfoIdx]) ) {
		prevQ = sti(objInfoList[nInfoIdx].refr);
	}

	if( nInfoSet!=0 ) prevQ++;
	else prevQ--;
	if(prevQ<0) prevQ=0;
	objInfoList[nInfoIdx].refr = prevQ;

	if( prevQ>0 )
	{
		if( !IsEntity(&objInfoList[nInfoIdx]) )
		{
			objInfoList[nInfoIdx].backColor = 0;
			objInfoList[nInfoIdx].foreColor = 0;
			objInfoList[nInfoIdx].borderWidth = 32;
			objInfoList[nInfoIdx].scale = 1.0;
			objInfoList[nInfoIdx].offset = 30;

			switch(sInfoID)
			{
			case "save game":
				objInfoList[nInfoIdx].picfilename = "Loading\save_game.tga";
			break;

			case "lost controller":
				objInfoList[nInfoIdx].picfilename = "Loading\lost_controller.tga";
			break;

			case "Low Storage":
				objInfoList[nInfoIdx].picfilename = "Loading\low_storage.tga";
			break;

			case "game prepare":
				objInfoList[nInfoIdx].picfilename = "Loading\loading.tga";
			break;

			case "MainMenuLaunch":
				objInfoList[nInfoIdx].picfilename = "INTERFACES\mainmenu_ss.tga";
			break;

			case "OptionsBreak":
				objInfoList[nInfoIdx].picfilename = "Loading\options.tga";
			break;
			}

			CreateEntity(&objInfoList[nInfoIdx],"InfoHandler");
		}
	}
	else
	{
		if( IsEntity(&objInfoList[nInfoIdx]) )
		{
			DeleteClass(&objInfoList[nInfoIdx]);
		}
	}

	InfoShowSetting();
}

void InfoShowSetting()
{
	bool bAlreadySet = false;
	bool bMakeSet;
	for(int i=5; i>=0; i--)
	{
		bMakeSet = false;
		if( IsEntity(&objInfoList[i]) )
		{
			if(!bAlreadySet) {
				bMakeSet = true;
				if( i==5 )
				{
					if( g_ibVideoExecuting || !CheckAttribute(&InterfaceStates,"Buttons.Resume.enable") ||
						sti(InterfaceStates.Buttons.Resume.enable)==false )
					{
						bMakeSet = false;
					}
				}
			}
		}

		if( bMakeSet ) {
			LayerAddObject(INFO_REALIZE,&objInfoList[i],-1);
			bAlreadySet = true;
		} else {
			LayerDelObject(INFO_REALIZE,&objInfoList[i]);
		}

		if(i==2) {
			if(bMakeSet) {
				SetEventHandler("Control Activation","InfoShow_Control",0);
			} else {
				DelEventHandler("Control Activation","InfoShow_Control");
			}
		}
		if(i==4) {
			if(bMakeSet) {
				SetEventHandler("Control Activation","InfoShow_Control2",0);
			} else {
				DelEventHandler("Control Activation","InfoShow_Control2");
			}
		}
		if(i==5) {
			if(bMakeSet) {
				SetTimeScale(0.0);
			}
		}
	}

	if(bAlreadySet) {
		LayerFreeze(INTERFACE_REALIZE,true);
		LayerFreeze(INTERFACE_EXECUTE,true);
	} else {
		LayerFreeze(INTERFACE_REALIZE,false);
		LayerFreeze(INTERFACE_EXECUTE,false);
	}
}


void InfoShow_Control()
{
	string ControlName = GetEventData();

	if(ControlName=="IAction" || ControlName=="ICancel")
	{
		PostEvent("DoInfoShower",0,"sl","Low Storage",false);
		if(ControlName=="ICancel")
		{
			SendMessage(&GameInterface,"l",MSG_INTERFACE_LAUNCH_DASHBOARD);
		}
		else Event("evntLowStorageBreak");
		LayerFreeze(INTERFACE_REALIZE,false);
		LayerFreeze(INTERFACE_EXECUTE,false);
	}
}

void InfoShow_Control2()
{
	string ControlName = GetEventData();

	if(ControlName=="IAction" || ControlName=="IStartButton")
	{
		PostEvent("DoInfoShower",0,"sl","OptionsBreak",false);
		Event("evntOptionsBreak");
		LayerFreeze(INTERFACE_REALIZE,false);
		LayerFreeze(INTERFACE_EXECUTE,false);
	}
}

void procAttractExit()
{
	PostEvent("ievntEndVideo",1);
	DelEventHandler("Control Activation","procAttractExit");
}

float GetSeaTimeScale()
{
	if(iRealismMode == 0) return 2.0;
	return 3.0;
}

void SetShowWindowParameters(bool TVused, int w,int h, int l,int t,int r,int b)
{
	showWindow.TVused = TVused;
	showWindow.width = w;
	showWindow.height = h;
	showWindow.aspectRatio = 1.0; // KK (h*4.0)/(w*3.0);
	showWindow.left = RecalculateHIcon(l);
	showWindow.top = RecalculateVIcon(t);
	showWindow.right = w - RecalculateHIcon(w-r);
	showWindow.bottom = h - RecalculateVIcon(h-b);
	showWindow.sw = r-l;
	showWindow.sh = b-t;
}

int RecalculateHIcon(int curHSize)
{
	return makeint(curHSize); // LDH 27Oct16, would return a float if passed one
}

int RecalculateVIcon(int curVSize)
{
	return makeint(stf(showWindow.aspectRatio)*curVSize);
}

string GetVideoFileName(string baseName)
{
	int sidx;
	string language, default_language, sldir;
	if(GetTargetPlatform()=="pc")
	{
// KK -->
		if (baseName == "") return "";
		sidx = strlen(baseName) - 1;
		if (strcut(baseName, sidx - 3, sidx) == ".wmv") return baseName;
		language = LanguageGetLanguage();
		default_language = "ENGLISH";
		sldir = "common";
		sidx = FindCurrentStoryline();
		if (sidx >= 0) {
			sldir = GetStorylineDir(sidx);
			if (FindFile("RESOURCE\VIDEOS\" + sldir + language, "*.wmv", baseName + ".wmv") != "") return sldir + language + "\" + baseName + ".wmv";
			if (FindFile("RESOURCE\VIDEOS\" + sldir + default_language, "*.wmv", baseName + ".wmv") != "") return sldir + default_language + "\" + baseName + ".wmv";
			if (FindFile("RESOURCE\VIDEOS\" + sldir, "*.wmv", baseName + ".wmv") != "") return sldir + "\" + baseName + ".wmv";
		}
		if (FindFile("RESOURCE\VIDEOS\common\" + language, "*.wmv", baseName + ".wmv") != "") return "common\" + language + "\" + baseName + ".wmv";
		if (FindFile("RESOURCE\VIDEOS\common\" + default_language, "*.wmv", baseName + ".wmv") != "") return "common\" + default_language + "\" + baseName + ".wmv";
		if (FindFile("RESOURCE\VIDEOS\common", "*.wmv", baseName + ".wmv") != "") return "common\" + baseName + ".wmv";
// <-- KK
		return baseName + ".wmv";
	}
	return baseName+".xmv";
}

void DisableMenuLaunch(bool bDisable)
{
	if(bDisable) {
		InterfaceStates.LaunchDisable = true;
	} else {
		DeleteAttribute(&InterfaceStates,"LaunchDisable");
	}
}
bool IsEnableMenuLaunch()
{
	if( CheckAttribute(&InterfaceStates,"LaunchDisable") ) {
		return !sti(InterfaceStates.LaunchDisable);
	}
	return true;
}

void DisableFastTravel(bool bDisable)
{
	if(bDisable) {
		InterfaceStates.DisFastTravel = true;
	} else {
		DeleteAttribute(&InterfaceStates,"DisFastTravel");
	}
}
bool IsEnableFastTravel()
{
	if( CheckAttribute(&InterfaceStates,"DisFastTravel") ) {
		return !sti(InterfaceStates.DisFastTravel);
	}
	//Levis: Added for smuggling cases so it won't interfere with other things
	if(!AllowFastTravelForSmuggling()) return false;
	return true;
}

void procPreLoad()
{
	DeleteAttribute(&objActivePerkShower,"PerkList");
}

void ProcBreakInterface()
{
	if( CheckAttribute(&InterfaceStates,"Launched") &&
		sti(InterfaceStates.Launched)==true )
	{
		if( CurrentInterface==INTERFACE_RANSACK_MAIN ||
			CurrentInterface==INTERFACE_FORTCAPTURE ||
			CurrentInterface==INTERFACE_TRANSFER_GOODS ||
			CurrentInterface==INTERFACE_TRANSFER_CHARACTER ||
			CurrentInterface==INTERFACE_TRANSFER_CREW )
		{
			return;
		}
	}
	InterfaceStates.InstantExit = true;
	Event("exitCancel");
	DeleteAttribute(&InterfaceStates,"InstantExit");
}

bool g_bOptionsBreak = false;
void procOptionsBreak()
{
	g_bOptionsBreak = true;
}
