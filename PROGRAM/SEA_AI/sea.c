#include "sea_ai\Script_defines.h"
#include "sea_ai\SeaPeople.h"

#include "sea_ai\AIGroup.c"
#include "sea_ai\AIShip.c"
#include "sea_ai\AIFort.c"
#include "sea_ai\AISea.c"
#include "sea_ai\AICameras.c"
#include "sea_ai\AIAbordage.c"
#include "sea_ai\AIFantom.c"
#include "sea_ai\AICannon.c"
#include "sea_ai\AIBalls.c"
#include "sea_ai\AIIsland.c"
#include "sea_ai\AISeaGoods.c"
#include "sea_ai\AITasks\AITasks.c"

#include "sea_ai\ShipBortFire.c"
#include "sea_ai\ShipDead.c"
#include "sea_ai\ShipWalk.c"

#include "sea_ai\CoastFoam.c"

#include "sea_ai\Telescope.c"

#include "battle_interface\BattleInterface.c"

#event_handler("Sea_FirstInit", "Sea_FirstInit");

#define DEBUGCR		0		// LDH set to 1 to get coastal traffic debugging info 15Feb09

int		sCurrentSeaExecute = EXECUTE;
int		sCurrentSeaRealize = REALIZE;

int		iAITemplatesNum;
bool	bSeaActive;
bool	bSeaLoaded = false;
bool 	bSkipSeaLogin = false;
bool	bIslandLoaded = false;
bool	bSeaReloadStarted = false;
bool	bNotEnoughBalls;
bool	bStorm, bTornado;
bool	bSeaQuestGroupHere = false;

int		iStormLockSeconds = 0;

object	Island, IslandReflModel;
object	Touch, AISea;
object	SeaFader;
object	Seafoam, BallSplash, SinkEffect, PeopleOnShip, Telescope, SeaOperator, Artifact;
object	Sharks;
object	SeaLighter;

object	SeaLocatorShow;
object	LoginGroupsNow;
bool	bSeaShowLocators = true;
bool	bQuestDisableMapEnter = false;
bool	bQuestDisableSeaEnter = false; // KK
bool	bFromCoast = false;

float	SeaMapLoadX = -1570.99;
float	SeaMapLoadZ = 950.812;
float	SeaMapLoadAY = 10.54;

float	fSeaExp = 0.0;
float	fSeaExpTimer = 0.0;

int	iSeaSectionLang = -1;

bool IsSeaLoaded() {
	return bSeaLoaded;
}

void DeleteSeaEnvironment()
{
	ref rPlayer = GetMainCharacter();

	StopMusic();
	bSeaActive = false;
	sCurrentSeaExecute = EXECUTE;
	sCurrentSeaRealize = REALIZE;

	rPlayer.Ship.Stopped = true;
	// PB: Steam Ships -->
	rPlayer.Ship.Power = 0;
	DeleteAttribute(rPlayer, "Ship.PlayedEngineSound");
	// PB: Steam Ships <--
	DeleteAttribute(rPlayer, "KrakenAttack");		// PB: Kraken Attack
	DeleteAttribute(rPlayer, "ship.speedburst");	// PB: Black Pearl & Queen Anne's Revenge
	DeleteAttribute(rPlayer, "Flags.waitdelay");	// PB: Just to make sure this is gone
	DeleteAttribute(rPlayer, "false_flag_note");	// PB: Warning Note
	TreasureFleet = false;							// PB: Treasure Fleet
	DeleteBattleInterface();

	DelEventHandler(SHIP_BORT_FIRE, "Ship_BortFire");
	DelEventHandler(BALL_FLY_UPDATE, "Ball_OnFlyUpdate");

	SendMessage(&AISea, "l", AI_MESSAGE_UNLOAD);

	DeleteSea();

	DeleteClass(&Island);
	DeleteClass(&IslandReflModel);
	DeleteClass(&Touch);
	DeleteClass(&Seafoam);
	DeleteClass(&BallSplash);
	DeleteClass(&SinkEffect);
	DeleteClass(&PeopleOnShip);
	DeleteClass(&SeaLocatorShow);
	DeleteClass(&SeaOperator);
	DeleteClass(&Telescope);
	DeleteClass(&Sharks);

	DeleteClass(&SeaLighter);

	if (IsEntity(&Artifact)) DeleteClass(&Artifact);

	DeleteBallsEnvironment();
	DeleteCannonsEnvironment();
	DeleteSeaCamerasEnvironment();
	DeleteShipEnvironment();
	DeleteFortEnvironment();
	DeleteAbordageEnvironment();
	DeleteSeaGoodsEnvironment();

	DeleteWeatherEnvironment();

	DeleteAttribute(&AISea,"");

	LayerFreeze(SEA_EXECUTE, true);
	LayerFreeze(SEA_REALIZE, true);

	LayerFreeze(REALIZE, false);
	LayerFreeze(EXECUTE, false);

	DeleteClass(&AISea);

	DeleteAnimals();

	// delete masts fall modules
	DeleteEntitiesByType("mast");

	// delete particle system
	DeleteParticles();

	// delete our group
	Group_DeleteGroup(PLAYER_GROUP);

	// delete fantom and dead groups
	Group_DeleteUnusedGroup();

	//
	LanguageCloseFile(iSeaSectionLang); iSeaSectionLang = -1;

	//
	Encounter_DeleteDeadQuestMapEncounters();

	if(FCOHS && CheckAttribute(rPlayer, "FCoHS")) // PB: Don't stop the mod if it's not started yet (for example on New Game)
		FCoHS_Main_Stop(); // FCoHS
}

void CreateSeaEnvironment()
{
	if (IsEntity(&Sea)) { Trace("ERROR: CreateSeaEnvironment Sea Already Loaded!!!"); return; } //fix

	sCurrentSeaExecute = SEA_EXECUTE;
	sCurrentSeaRealize = SEA_REALIZE;

	iSeaSectionLang = LanguageOpenFile("SeaSection.txt");

	CreateParticleEntity();

	Ship_Walk_Init();

	LayerFreeze(REALIZE, true);
	LayerFreeze(EXECUTE, true);
	LayerFreeze(SEA_REFLECTION, false);

	InterfaceStates.Buttons.Resume.enable = true;

	bSeaActive = true;

	LayerFreeze(SEA_EXECUTE, false);
	LayerFreeze(SEA_REALIZE, false);

	CreateSea(SEA_EXECUTE, SEA_REALIZE);			ReloadProgressUpdate();
	CreateWeather(SEA_EXECUTE, SEA_REALIZE);		ReloadProgressUpdate();

	CreateEntity(&AISea, "sea_ai");					ReloadProgressUpdate();
	LayerAddObject(SEA_EXECUTE, &AISea, 1);
	LayerAddObject(SEA_REALIZE, &AISea, -1);

	CreateEntity(&Touch, "touch");					ReloadProgressUpdate();
	LayerAddObject(SEA_EXECUTE, &Touch, 1);
	Touch.CollisionDepth = -10.0;
	//LayerAddObject(SEA_REALIZE, &Touch, -1);		// for collision debug

	CreateEntity(&BallSplash, "BallSplash");		ReloadProgressUpdate();
	LayerAddObject(SEA_EXECUTE, &BallSplash, -1);
	LayerAddObject(SEA_REALIZE, &BallSplash, 65535);

	CreateEntity(&SinkEffect, "SINKEFFECT");		ReloadProgressUpdate();
	LayerAddObject(SEA_EXECUTE, &SinkEffect, 65531);
	LayerAddObject(SEA_REALIZE, &SinkEffect, 65531);

	// CreateEntity(&PeopleOnShip, "PEOPLE_ON_SHIP");	ReloadProgressUpdate();
	// LayerAddObject(SEA_EXECUTE, &PeopleOnShip, 100);
	// LayerAddObject(SEA_REALIZE, &PeopleOnShip, 100);

	// 1.03 - CreateEntity(&SeaLocatorShow, "SeaLocatorShow"); ReloadProgressUpdate();
	// KK LayerAddObject(SEA_REALIZE, &SeaLocatorShow, -1); // since we hadn't created entity...

	CreateSeaAnimals();								ReloadProgressUpdate();

	// create all other environment
	CreateBallsEnvironment();						ReloadProgressUpdate();
	CreateCannonsEnvironment();						ReloadProgressUpdate();
	CreateShipEnvironment();						ReloadProgressUpdate();
	CreateFortEnvironment();						ReloadProgressUpdate();
	CreateAbordageEnvironment();					ReloadProgressUpdate();
	CreateSeaGoodsEnvironment();					ReloadProgressUpdate();

	SetEventHandler(SHIP_CREATE, "Ship_Walk_Create", 0);
	SetEventHandler("MSG_TELESCOPE_REQUEST", "Telescope_Request", 0);
	SetEventHandler(SHIP_BORT_FIRE, "Ship_BortFire", 0);

	CreateSeaCamerasEnvironment();					ReloadProgressUpdate(); // KK

	bNotEnoughBalls = false;

	if (CANNONPOWDER_MOD) {// TIH --> mod toggle 7-7-06
		ref mCh = GetMainCharacter();
		int fPwdr = 0;
		int pwdrQty = GetCargoGoodsSimple(mCh, GOOD_GUNPOWDER);
		ref rCannon; makeref(rCannon,Cannon[GetCaracterShipCannonsType(mCh)]);
		if(CheckAttribute(rCannon,"gunpowder")) fPwdr = sti(rCannon.gunpowder);
		if( pwdrQty < sti( GetCannonArcCurQty(mCh, 0)) * fPwdr || pwdrQty < sti(GetCannonArcCurQty(mCh, 2)) * fPwdr )
		{
			if(mCh.Ship.Cannons.Type != CANNON_TYPE_NONECANNON)
			{
				Log_SetStringToLog(TranslateString("","Captain, we're out of gunpowder!"));
			}
		}
	}// TIH <-- mod toggle

	Sharks.execute = SEA_EXECUTE;
	Sharks.realize = SEA_REALIZE;
	Sharks.executeModels = 75;
	Sharks.realizeModels = 75;
	Sharks.executeParticles = 78;
	Sharks.realizeParticles = 100001;

	CreateEntity(&Sharks, "Sharks");				ReloadProgressUpdate();

	PeopleOnShip.isNight = Whr_IsNight();
	chrWaitReloadLocator = "";//MAXIMUS
	if(FCOHS) FCoHS_Main_Start(); // FCoHS
}

void Sea_LandLoad()
{
	bSeaReloadStarted = true;
	PauseAllSounds();
	ResetSoundScheme();

	if (!bSeaActive) return;
	if (bCanEnterToLand) {
		LayerFreeze(REALIZE, false);
		LayerFreeze(EXECUTE, false);

// KK -->
		if (bDeckEnter)
		{
			AnchorDrop();
			return;
		}
// <-- KK
		ClearDeck();//MAXIMUS

		// added after build 11 by KAM -->
		ref tempMainChar = GetMainCharacter();
		tempMainChar.ShipBerthing.DoInvoice = true;
		// <-- added after build 11 by KAM

		HealSquadronWoundedCrew(); // KK
		CancelAllGunReadySounds(); // KK

// Maximus & PB: Lower sails and play sound when anchoring -->
		if (sti(tempMainChar.LastSailState) != 0) SendMessage(&AISea, "laf", AI_MESSAGE_SHIP_SET_SAIL_STATE, tempMainChar, 0.0);
// KK -->
		DeleteAttribute(tempMainChar, "LastSailState");
		tempMainChar.Anchoring = true;
		Log_SetActiveAction("Nothing");

		if (stf(tempMainChar.Ship.Speed.z) != 0.0) PlaySound("anchor"); // NK
// <-- KK
	}
}

// KK -->
void Sea_ImmediateLandLoad(bool toFort)
{
	bSeaReloadStarted = true;
	PauseAllSounds();
	ResetSoundScheme();

	if (bSeaActive == false) return;
	if (bCanEnterToLand == true)
	{
		SeaCameras_Switch();
		SeaCameras_Switch();

		LayerFreeze(REALIZE, false);
		LayerFreeze(EXECUTE, false);

		// added after build 11 by KAM -->
		ref tempMainChar = GetMainCharacter();
		tempMainChar.ShipBerthing.DoInvoice = true;
		// <-- added after build 11 by KAM

		HealSquadronWoundedCrew(); // KK
		CancelAllGunReadySounds(); // KK

// Maximus & PB: Lower sails and play sound when anchoring -->
		if (sti(tempMainChar.LastSailState) != 0) SendMessage(&AISea, "laf", AI_MESSAGE_SHIP_SET_SAIL_STATE, tempMainChar, 0.0);
// KK -->
		DeleteAttribute(tempMainChar, "LastSailState");
		tempMainChar.Anchoring = true;
		tempMainChar.Anchoring.Immediate = true;
		Log_SetActiveAction("Nothing");
		if (toFort) tempMainChar.location.Fort = true;

		if (stf(tempMainChar.Ship.Speed.z) != 0.0) PlaySound("anchor"); // NK
// <-- KK
	}
}

//#event_handler("LAi_deck", "GoToDeck");
void GoToDeck()
{
	Sea_DeckStartNow(GetMainCharacterIndex(), GetCharacterShipQDeck(GetMainCharacter()));
}
// <-- KK

//#event_handler("LAi_anchor", "AnchorDrop");
void AnchorDrop()
{
// KK -->
	ref mchr = GetMainCharacter();
	string sLocator = sIslandLocator;
	ClearDeck();//MAXIMUS
	if (CheckAttribute(mchr, "location.Fort")) {
		if (sti(mchr.location.Fort) == true) sLocator = sAbordageLocator;
		DeleteAttribute(mchr, "location.Fort");
	}
	Reload(arIslandReload, sLocator, sIslandID);
	bSeaActive = false;//MAXIMUS: used for new "Mutiny" [just to be sure]
// <-- KK
}
// Maximus & PB: Lower sails and play sound when anchoring <--

// [abordage MOD] -->
#event_handler("Ship_BranderDetonate", "Lai_ToBlowUp");
void Lai_ToBlowUp()
{
	aref blowingLoser = GetEventData();
	Ship_Detonate(blowingLoser, true, true);
}
// [abordage MOD] <--

void Sea_MapStartFade()
{
	DelEventHandler("FaderEvent_StartFade", "Sea_MapStartFade");
	DeleteSeaEnvironment();
}

void Sea_MapEndFade()
{
	DelEventHandler("FaderEvent_EndFade", "Sea_MapEndFade");

	wdmCreateMap(SeaMapLoadX, SeaMapLoadZ, SeaMapLoadAY);

	// PB: Update Changed Flag -->
//	int cc, compIdx;
	ref PChar = GetMainCharacter();
	if(CheckAttribute(PChar, "orgnation"))	// checks if you just hoisted Jolly Roger
	{
		HoistFlag(sti(PChar.orgnation));
		DeleteAttribute(PChar,"orgnation");	// so that rel resetting runs only once after flaghoisting
		LogIt(TranslateString("", "You hide the Jolly Roger and hoist your former flag again"));
	}
	// PB: Update Changed Flag <--
}

void Sea_MapLoadXZ_AY(float x, float z, float ay)
{
	bSkipSeaLogin = true; // NK fix 05-07-16 to be sure we don't hit the getseatime<3 hack.
	Sea_MapLoad();

	SeaMapLoadX = x;
	SeaMapLoadZ = z;
	SeaMapLoadAY = ay;
}

void Sea_MapLoad()
{
	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	if(GetSeaTime() < 3 && !bSkipSeaLogin) {
		LogIt(TranslateString("","Wait a sec while I get out the chart, captain!"));
		PlaySound("interface\knock.wav");
		return;
	} // NK so you must be on sea >= 3 seconds. 05-04-23
	bSeaReloadStarted = true;
	PauseAllSounds();

	ResetSoundScheme();

	SetEventHandler("FaderEvent_StartFade", "Sea_MapStartFade", 0);
	SetEventHandler("FaderEvent_EndFade", "Sea_MapEndFade", 0);

	CreateEntity(&wdm_fader, "fader");
	SendMessage(&wdm_fader, "lfl", FADER_OUT, 0.7, true);
	SendMessage(&wdm_fader, "l", FADER_STARTFRAME);
	SetReloadImage(&wdm_fader, "sea"); // KK

	bSkipSeaLogin = true;

	ref rPlayer = GetMainCharacter();

	SeaMapLoadX = stf(rPlayer.Ship.Pos.x);
	SeaMapLoadZ = stf(rPlayer.Ship.Pos.z);
	SeaMapLoadAY = stf(rPlayer.Ship.Ang.y);
	//LanguageCloseFile(tmpLangFileID);
//	ResetTimeToNormal();//MAXIMUS: removes time-acceleration and sets normal time
}

void Land_MapLoad()
{
	bSeaReloadStarted = true;
	PauseAllSounds();

	ResetSoundScheme();

	SetEventHandler("FaderEvent_StartFade", "Land_MapStartFade", 0);
	SetEventHandler("FaderEvent_EndFade", "Sea_MapEndFade", 0);

	CreateEntity(&wdm_fader, "fader");
	SendMessage(&wdm_fader, "lfl", FADER_OUT, 0.7, true);
	SendMessage(&wdm_fader, "l", FADER_STARTFRAME);
	SetReloadImage(&wdm_fader, "sea");

	bSkipSeaLogin = true;

	SeaMapLoadX = stf(characters[GetMainCharacterIndex()].Ship.Pos.x);
	SeaMapLoadZ = stf(characters[GetMainCharacterIndex()].Ship.Pos.z);
	SeaMapLoadAY = stf(characters[GetMainCharacterIndex()].Ship.Ang.y);
}

void Land_MapStartFade()
{
	DelEventHandler("FaderEvent_StartFade", "Land_MapStartFade");
	ref PChar = GetMainCharacter();
	if(CheckAttribute(PChar,"location") && PChar.location!="" && FindLocation(PChar.location)!=-1)
	{
		UnloadLocation(&locations[FindLocation(PChar.location)]);
	}
//	ResetTimeToNormal();
}

string	sTaskList[2];

void Sea_FreeTaskList()
{
	ref rMassive;
	makeref(rMassive, sTaskList);
	SetArraySize(rMassive, 2);
}

void Sea_AddGroup2TaskList(string sGroupID)
{
	ref rMassive;
	makeref(rMassive, sTaskList);
	int iSize = GetArraySize(rMassive);
	SetArraySize(rMassive, iSize + 1);
	sTaskList[iSize-2] = sGroupID;
}

void Sea_LoginGroupNow(string sGroupID)
{
	LoginGroupsNow.QuestGroups = "";
	aref arGroups; makearef(arGroups, LoginGroupsNow.QuestGroups);
	string sID = "n" + GetAttributesNum(arGroups);
	arGroups.(sID) = sGroupID;
}


void SeaLogin(ref Login)
{
	Trace("SEA: SeaLogin begin");
	int i, j, iShipType, iNumQCGroups, iNShips, iCharacterIndex;
	float x, y, z, ay;
	ref	 rCharacter, rGroup, rEncounter;
	aref rRawGroup, arQCGroups, arEncounters;
	string sGName, l;
	bool bDirectSail = CheckAttribute(Login, "DirectSail"); // KK
	bool bLoadSavedGame = CheckAttribute(Login, "LoadAtSea") && !bDirectSail; // KK

	int iRDTSC = RDTSC_B();

	// clear load groups now object
	DeleteAttribute(&LoginGroupsNow, "");

	iStormLockSeconds = 0;
	iNumFantoms = 0;
	bSkipSeaLogin = false;
	bSeaReloadStarted = false;
	bSeaQuestGroupHere = false;
	bIslandLoaded = false;

	fSeaExp = 0.0;
	fSeaExpTimer = 0.0;
	// NK 04-09-21 timeupdate
	if(TIMEUPDATE_BLOCK_LAND)
	{
		AddTimeToCurrent(0, (locTmpTime * TIMESCALAR_LAND)/60);
	}
	locTmpTime = 0.0;
	// NK <--

	Sea_FreeTaskList();
	Encounter_DeleteDeadQuestMapEncounters();

// KK -->
	if (!bDirectSail) {
		// weather parameters
		if (!bLoadSavedGame) {
			WeatherParams.Tornado = false;
			WeatherParams.Storm = false;
		}
		if (CheckAttribute(Login,"Storm")) WeatherParams.Storm = Login.Storm;
		if (CheckAttribute(Login,"Tornado")) WeatherParams.Tornado = Login.Tornado;
		bStorm = sti(WeatherParams.Storm);
		bTornado = sti(WeatherParams.Tornado);
		if (bStorm) iStormLockSeconds = 60;
	}

	// Island
	int iIslandIndex = FindIsland(Login.Island);
	//Trace("Island id = " + Login.Island + ", Island index = " + iIslandIndex);
	string sIslandID = "";
	if (iIslandIndex != -1) sIslandID = Islands[iIslandIndex].id;

	// main character
	ref rPlayer = GetMainCharacter();
	rPlayer.Ship.Stopped = false;
	//DeleteAttribute(rPlayer, "LastSailState"); // NK 05-04-20 so it doesn't say it during loading
	rPlayer.Ship.POS.Mode = SHIP_SAIL;
	rPlayer.location = Login.Island;

	for (i = 0; i < COMPANION_MAX; i++)
	{
		iCharacterIndex = GetCompanionIndex(rPlayer, i);
		if (iCharacterIndex < 0) continue;
		rCharacter = GetCharacter(iCharacterIndex);
		rCharacter.location = Login.Island;
	}

	if (bDirectSail) rPlayer.BaseCurrentTime = 0.0; //Screwface : fix to restart Sea ai update as soon as sea reload

	// clear old fantom relations in our character
	if (!bLoadSavedGame && CheckAttribute(rPlayer, "Relation")) // KK
	{
		aref	arRelations; makearef(arRelations, rPlayer.Relation);
		int		iNumRelations = GetAttributesNum(arRelations);
		for (i=0; i<iNumRelations; i++)
		{
			aref arRelation = GetAttributeN(arRelations, i);
			string sRName = GetAttributeName(arRelation);
			if (sti(sRName) >= FANTOM_CHARACTERS)
			{
				DeleteAttribute(arRelations, sRName);
				iNumRelations--;
				i--;
			}
		}
	}

	// Quest check
	if (!bLoadSavedGame) { // KK
		Event(EVENT_SEA_LOGIN, "");
		if (bSkipSeaLogin) return;
	}

	if (!bLoadSavedGame) {
		if (!IsEntity(&SeaFader)) {
			// Sea Fader start
			if (!CheckAttribute(&Login,"ImageName")) Login.ImageName = "sea";

			CreateEntity(&SeaFader, "fader");
			SendMessage(&SeaFader, "lfl", FADER_IN, 0.5, true);
			SetReloadImage(&SeaFader, Login.ImageName);
		}
	}
// <-- KK

	// create all sea modules
	CreateSeaEnvironment();

	Sea.MaxSeaHeight = 50.0;

	ReloadProgressUpdate();

	float wdmBaseX, wdmBaseZ; // WM base coords for fleets 05-05-02

	// login island if exist
	if (sIslandID != "")
	{
		trace("SEA: sealogin loading island " + sIslandID);
		CreateEntity(&Island, "Island");
		Island.LightingPath = GetLightingPath();
		Island.FogDensity = Weathers.Fog.IslandDensity;

		if (GetTargetPlatform() != "xbox")
		{
			//CreateEntity(&SeaLighter, "lighter"); // PB: Enable Loc Lighter at sea with this
			SendMessage(&SeaLighter, "ss", "ModelsPath", Islands[iIslandIndex].filespath.models);
			SendMessage(&SeaLighter, "ss", "LightPath", GetLightingPath());
		}

		SendMessage(&Island, "lsss", MSG_ISLAND_LOAD_GEO, "islands", Islands[iIslandIndex].filespath.models, Islands[iIslandIndex].model);
		LayerAddObject(SEA_REALIZE, &Island, 4);
		LayerAddObject(MAST_ISLAND_TRACE, &Island, 1);
		LayerAddObject(SUN_TRACE, &Island, 1);

		CreateEntity(&IslandReflModel, "MODELR");
		string sReflModel = Islands[iIslandIndex].filespath.models + "\" + Islands[iIslandIndex].refl_model;
		SendMessage(&IslandReflModel, "ls", MSG_MODEL_SET_LIGHT_PATH, GetLightingPath());
		SendMessage(&IslandReflModel, "ls", MSG_MODEL_LOAD_GEO, sReflModel);
		LayerAddObject(SEA_REFLECTION, &IslandReflModel, -1);
		SendMessage(SeaLighter, "ssi", "AddModel", Islands[iIslandIndex].refl_model, &IslandReflModel);

		bIslandLoaded = true;

		SendMessage(&SeaLocatorShow, "a", &Islands[iIslandIndex]);
		Fort_Login(iIslandIndex);

		if(!bstorm) Sea.MaxSeaHeight = 3.0; // screwface : allow big waves around island in storm conditions
		// WM base coords for fleets 05-05-02 -->
		// 05-05-03 get correct wdm name for island.
		string wdmisland = wdmGetIslandNameFromID(sIslandID);
		if (wdmisland != "" && CheckAttribute(worldMap,".islands."+wdmisland)) {
			wdmBaseX = MakeFloat(worldMap.islands.(wdmisland).position.rx);
			wdmBaseZ = MakeFloat(worldMap.islands.(wdmisland).position.rz);
		} else {
			wdmBaseX = makefloat(worldMap.playerShipX);
			wdmBaseZ = makefloat(worldMap.playerShipZ);
		}
	} else {
		wdmBaseX = makefloat(worldMap.playerShipX);
		wdmBaseZ = makefloat(worldMap.playerShipZ);
	} // WM base coords for fleets 05-05-02 <--
	AISea.Island = sIslandID;

// KK -->
	// clear some of group attributes
	for (i=0; i<MAX_SHIP_GROUPS; i++)
	{
		rGroup = Group_GetGroupByIndex(i);
		if (CheckAttribute(rGroup, "AlreadyLoaded")) DeleteAttribute(rGroup, "AlreadyLoaded");
	}

	ReloadProgressUpdate();

	// login main player and his friends
	int iMainCharacter = GetMainCharacterIndex();
	int iCompanionIndex = -1;
	ref rCompanion;

	// delete our group
	Group_DeleteGroup(PLAYER_GROUP);
	Group_DeleteGroup(MUTINY_GROUP);

	if(CheckAttribute(rPlayer,"fallen")) // Screwface : Need to restore the fallen mast(s) to avoid crashes with set flags
	{
		DeleteAttribute(rPlayer,"ship.sails");
		DeleteAttribute(rPlayer,"ship.masts");
		DeleteAttribute(rPlayer,"fallen");
		Trace("Player mast restored");
	}

	// from coast check (move / stop)
	if (!bLoadSavedGame) {
		bFromCoast = false;
		if (CheckAttribute(Login, "FromCoast")) bFromCoast = sti(Login.FromCoast);

		Group_AddCharacter(PLAYER_GROUP, rPlayer.id);
		// set commander to group
		Group_SetGroupCommander(PLAYER_GROUP, rPlayer.id);
		// set our group position
		Group_SetXZ_AY(PLAYER_GROUP, stf(Login.PlayerGroup.x), stf(Login.PlayerGroup.z), stf(Login.PlayerGroup.ay) );
		//Trace("Set group : " + PLAYER_GROUP + ", x = " + Login.PlayerGroup.x + ", z = " + Login.PlayerGroup.z + ", ay = " + Login.PlayerGroup.ay);
		rPlayer.SeaAI.Group.Name = PLAYER_GROUP;
		//rPlayer.Ship.Type = Characters[iMainCharacter].Ship.Type;
		rPlayer.Ship.Stopped = false;
		rPlayer.LastSailState = (!bFromCoast) * 2;
		Ship_Add2Sea(iMainCharacter, bFromCoast, "");
		trace("SEA: added pchar to sea");
		for (i = 1; i < COMPANION_MAX; i++)
		{
			iCompanionIndex = GetCompanionIndex(rPlayer, i);
			if (iCompanionIndex < 0) continue;
			if(CheckAttribute(&Characters[iCompanionIndex],"fallen")) // Screwface : Need to restore the fallen mast(s) to avoid crashes with set flags
			{
				DeleteAttribute(&Characters[iCompanionIndex],"ship.sails");
				DeleteAttribute(&Characters[iCompanionIndex],"ship.masts");
				DeleteAttribute(&Characters[iCompanionIndex],"fallen");
				Trace("Companion mast restored");
			}
			rCompanion = GetCharacter(iCompanionIndex);
			rCompanion.SeaAI.Group.Name = PLAYER_GROUP;
			Ship_Add2Sea(iCompanionIndex, bFromCoast, "");
			// add companion to player group
			Group_AddCharacter(PLAYER_GROUP, rCompanion.id);
		}
		//trace("added comps to sea");

		// login encounters
		// login quest group if island exist
		ReloadProgressUpdate();

		if (bDirectSail == false && sIslandID != "") {		// ccc CR
			if (AUTOCREATE_CR == 1) SetCoastTraffic(sIslandID);
			trace("SEA: Did CRs");
		}
		if (bDirectSail && CheckAttribute(rPlayer,"directsail.toisland")) { // if DirectsailCheck() calls islandchange coastal ships are created
			if (AUTOCREATE_CR == 1) SetCoastTraffic(sIslandID);
			trace("SEA: Did CRs");
		}

		if (sIslandID != "")
		{
			for (i=0; i<MAX_SHIP_GROUPS; i++)
			{
				rGroup = Group_GetGroupByIndex(i);
				if (!CheckAttribute(rGroup,"AlreadyLoaded")) DeleteAttribute(rGroup,"AlreadyLoaded"); // NK: Stock game code that removes an attribute that is already not there

				if (!CheckAttribute(rGroup, "id")) { continue; }
				if (!CheckAttribute(rGroup, "location")) { continue; }
				if (rGroup.location != sIslandID) { continue; }
				Sea_LoginGroup(rGroup.id);
			}
		}
		trace("SEA: Did any groups");

		// login quest groups to sea
		if (CheckAttribute(Login, "QuestGroups"))
		{
			arQCGroups; makearef(arQCGroups, Login.QuestGroups);
			iNumQCGroups = GetAttributesNum(arQCGroups);
			for (i=0; i<iNumQCGroups; i++)
			{
				Sea_LoginGroup(GetAttributeValue(GetAttributeN(arQCGroups, i)));
			}
		}

		ReloadProgressUpdate();

		// login quest groups to sea from LoginGroupsNow object
		if (CheckAttribute(&LoginGroupsNow, "QuestGroups"))
		{
			makearef(arQCGroups, LoginGroupsNow.QuestGroups);
			iNumQCGroups = GetAttributesNum(arQCGroups);
			for (i=0; i<iNumQCGroups; i++)
			{
				Sea_LoginGroup(GetAttributeValue(GetAttributeN(arQCGroups, i)));
			}
		}
	}

	ReloadProgressUpdate();

	if (!bDirectSail && !bLoadSavedGame)
	{
		// login fantom groups
		makearef(arEncounters,Login.Encounters);
		int iNumGroups = GetAttributesNum(arEncounters);

		for (i=0; i<iNumGroups; i++)
		{
			rRawGroup = GetAttributeN(arEncounters, i);
			rEncounter = GetMapEncounterRef(sti(rRawGroup.type));
			sGName = rEncounter.GroupName;

			x = stf(rRawGroup.x);
			z = stf(rRawGroup.z);
			ay = stf(rRawGroup.ay);

			ReloadProgressUpdate();

			// check for Quest fantom
			if (CheckAttribute(rEncounter, "qID"))
			{
				Trace("SEA: Login quest encounter " + rEncounter.qID);
				Group_SetAddressNone(rEncounter.qID);
				Group_SetXZ_AY(rEncounter.qID, x, z, ay);
				Sea_LoginGroup(rEncounter.qID);

				continue;
			}

			// NK disable this, it kills encounters if there are local ships -- if (bSeaQuestGroupHere) { continue; }
			Sea_AddGroup2TaskList(sGName);

			rGroup = Group_GetGroupByIndex(Group_CreateGroup(sGName));
			Group_SetXZ_AY(sGName, x, z, ay);
			Group_SetType(sGName, rEncounter.Type);
			Group_DeleteAtEnd(sGName);

			// copy task attributes from map encounter to fantom group
			if (CheckAttribute(rEncounter, "Task"))							{ rGroup.Task = rEncounter.Task; }
			if (CheckAttribute(rEncounter, "Task.Target"))					{ rGroup.Task.Target = rEncounter.Task.Target; }
			if (CheckAttribute(rEncounter, "Task.Pos"))
			{
				rGroup.Task.Target.Pos.x = rEncounter.Task.Pos.x;
				rGroup.Task.Target.Pos.z = rEncounter.Task.Pos.z;
			}
			if (CheckAttribute(rEncounter, "Lock") && sti(rEncounter.Lock)) { Group_LockTask(sGName); }

			int iEncounterType = sti(rEncounter.RealEncounterType);
			int iNation = sti(rEncounter.Nation);
			iNShips = Fantom_GenerateEncounter(sGName, iEncounterType, iNation); // NK

			Trace("SEA: Set group : " + sGName + ", x = " + x + ", z = " + z);

			// load ship to sea
			if (iNShips > 0)
			{
				int iGeraldSails = -1;
				if (CheckAttribute(rEncounter, "GeraldSails")) iGeraldSails = sti(rEncounter.GeraldSails);
				LoadShipsToSea(iNShips, sGName, iNation, iGeraldSails);
			}
		}
	}
	else
	{
		if (bDirectSail && CheckAttribute(rPlayer, "directsail.encounter"))
		{ // if set so in DirectsailCheck() random encounter ships are created
			rPlayer.ship.pos.x = stf(Login.PlayerGroup.x); // so that DirectEncounter doesn't use OLD coords
			rPlayer.ship.pos.z = stf(Login.PlayerGroup.z);
			DirectEncounter(stf(Login.PlayerGroup.ay));
			if (DS_MULTIFLEET > 0.0)
			{
				if (frand(100) <= DS_MULTIFLEET)
				{
					DirectEncounter(stf(Login.PlayerGroup.ay));					// Second group in encounter
//					if (frand(100) <= DS_MULTIFLEET) DirectEncounter(stf(Login.PlayerGroup.ay));	// Chance of a third
				}
			}
			DeleteAttribute(rPlayer,"directsail");	// clears tags from player
		}
		if (bLoadSavedGame) {
			iNShips = sti(Login.Ship.Quantity);
			for (i = 0; i < iNShips; i++)
			{
				l = "l" + i;
				// Screwface : If you saved while a ship was sinking (still dead icon in Binterface menu) the next time you loaded your save
				// the l attribute was missing and icharacterIndex was set to 0 so you had a clone of you as temporary companion !!! The line below avoid that !
				if(!CheckAttribute(&Login,"Ship."+(l))) continue; // Screwface
				iCharacterIndex = sti(Login.Ship.(l).idx);
				if (iCharacterIndex < 0) continue;
				rCharacter = GetCharacter(iCharacterIndex);
				if (CharacterIsDead(rCharacter)) continue;
				Sea_LoginShip(rCharacter);
				Ship_Login(iCharacterIndex);
			}
		}
	}
	trace("SEA: added ships");

	CreateFlagEnvironment();

	// set ship for sea camera
	SeaCameras_SetShipForSeaCamera(rPlayer);
// <-- KK

	ReloadProgressUpdate();

// KK -->
	// set tasks 2 all groups
	int c, iRelation; //NK bugfix 5-1
	string sGroupID;
	if (!bLoadSavedGame) {
		for (i=0; i<GetArraySize(&sTaskList)-2; i++)
		{
			sGroupID = sTaskList[i];
			rGroup = Group_GetGroupByID(sGroupID);

			// set task
			switch (sti(rGroup.Task))
			{
				case AITASK_RUNAWAY:
					Group_SetTaskRunAway(sGroupID);
				break;
				case AITASK_ATTACK:
					Group_SetTaskAttack(sGroupID, rGroup.Task.Target, true);
				break;
				case AITASK_MOVE:
					if (CheckAttribute(rGroup, "Task.Target.Pos"))
					{
						Group_SetTaskMove(sGroupID, stf(rGroup.Task.Target.Pos.x), stf(rGroup.Task.Target.Pos.z));
					}
					else
					{
						x = 10000.0 * sin(stf(rGroup.Pos.ay));
						z = 10000.0 * cos(stf(rGroup.Pos.ay));
						Group_SetTaskMove(sGroupID, x, z);
					}
				break;
			}
		}
	} else {
		for (i = 0; i < iNumShips; i++) {
			iCharacterIndex = Ships[i];
			if (iCharacterIndex < 0) continue;
			rCharacter = GetCharacter(iCharacterIndex);
			if (CheckAttribute(rCharacter, "SeaAI.Group.MainCharacter") == true && sti(rCharacter.SeaAI.Group.MainCharacter) == true && iCharacterIndex != iMainCharacter) {
				sGroupID = GetGroupIDFromCharacter(rCharacter);
				if (CheckAttribute(rCharacter, "SeaAI.Task")) // PB: Prevent error log
				{
					switch (sti(rCharacter.SeaAI.Task))
					{
						case AITASK_ATTACK:
							iCompanionIndex = sti(rCharacter.SeaAI.Task.Target);
							trace("attack target="+rCharacter.SeaAI.Task.Target+" -> "+GetGroupIDFromCharacter(GetCharacter(iCompanionIndex)));
							if (iCompanionIndex >= 0) Group_SetTaskAttack(sGroupID, GetGroupIDFromCharacter(GetCharacter(iCompanionIndex)), true);
						break;
						case AITASK_RUNAWAY:
							trace("runaway");
							Group_SetTaskRunAway(sGroupID);
						break;
						case AITASK_MOVE:
							trace("move to x="+rCharacter.SeaAI.Task.Pos.x+", z="+rCharacter.SeaAI.Task.Pos.z);
							Group_SetTaskMove(sGroupID, stf(rCharacter.SeaAI.Task.Pos.x), stf(rCharacter.SeaAI.Task.Pos.z));
						break;
					}
				}
			}
			if (CheckAttribute(rCharacter, "SeaAI.Group.MainCharacter")) DeleteAttribute(rCharacter, "SeaAI.Group.MainCharacter");
		}
	}
	trace("SEA: Set tasks");

	AISea.isDone = "";
	trace("updated AISea");

	if (bLoadSavedGame) {
		for (c = 0; c < iNumShips; c++)
		{
			iCharacterIndex = Ships[c];
			if (iCharacterIndex < 0) continue;
			rCharacter = GetCharacter(iCharacterIndex);
			sGroupID = GetGroupIDFromCharacter(rCharacter);
			if (hasSubStr(sGroupID, "tmpgrp_")) {
				Group_DelCharacter(sGroupID, rCharacter.id);
				Group_DeleteGroup(sGroupID);
				sGroupID = strcut(sGroupID, 7, strlen(sGroupID) - 3);
				Group_AddCharacter(sGroupID, rCharacter.id);
			}
		}
	}
// <-- KK
	// Screwface : Restored as original because of too many CTDs at sea login
	InitBattleInterface();							ReloadProgressUpdate();
	StartBattleInterface();							ReloadProgressUpdate();
	RefreshBattleInterface(false);					ReloadProgressUpdate(); // PB: Immediately load the interface
	SetAllShipsNeutral();							ReloadProgressUpdate(); // PB: But set correct relations later in Sea_FirstInit
	// Screwface : End

	CreateEntity(&Seafoam,"Seafoam");				ReloadProgressUpdate();
	LayerAddObject(SEA_EXECUTE, &Seafoam, -1);
	LayerAddObject(SEA_REALIZE, &Seafoam, -1);
	DeleteAttribute(rPlayer, "scrollchars");				// PB: For Cheatmode
	DeleteAttribute(rPlayer, "Anchoring");					// PB: Just to make sure this is gone
	DeleteAttribute(rPlayer, "ForceReload");				// PB: Just to make sure this is gone
	for (c = 0; c < COMPANION_MAX; c++)
	{
		iCharacterIndex = GetCompanionIndex(rPlayer, c);
		if (iCharacterIndex < 0) continue;
		rCharacter = GetCharacter(iCharacterIndex);
		// PB: To make sure this is gone -->
		DeleteAttribute(rCharacter, "Ship.Sink");
		DeleteAttribute(rCharacter, "Ship.Sails.Delay");
		DeleteAttribute(rCharacter, "Ship.Unstable");
		DeleteAttribute(rCharacter, "Ship.Capsize");
		DeleteAttribute(rCharacter, "Ship.Tack");
		// PB: To make sure this is gone <--
	}
	if (Whr_IsStorm())
	{
		Seafoam.storm = "true";
		rPlayer.Capsize.Warning = ROLL_ANGLE_WARNING;		// PB: Reset capsize danger
	}
	InitOpenSeaMod();										// stljeffbb Jan 15 2012
	trace("Seafoam done");

	/*CreateEntity(&SeaOperator, "SEA_OPERATOR");
	LayerAddObject(SEA_EXECUTE, &SeaOperator, -1);
	LayerAddObject(SEA_REALIZE, &SeaOperator, 3);*/

	SendMessage(&objISpyGlass, "leee", MSG_TELESCOPE_INIT_ARRAYS, &Nations, &ShipsTypes, &Goods);
	trace("Telescope initiated");

	PostEvent(SHIP_CHECK_RELOAD_ENABLE, 100);

	SetSchemeForSea();								ReloadProgressUpdate(); //Screwface : Restored and removed from Battleinterface.c because of CTD

	SetCorrectWorldMapPosition(); //Screwface

	iRDTSC = RDTSC_E(iRDTSC);
	//Trace("SeaLogin RDTSC = " + iRDTSC);
	//Trace("iNumShips = " + iNumShips);

	PostEvent("Sea_FirstInit", 100);
	StartPostInitChars();
	Trace("SEA: SeaLogin end");
}

// KK -->
void LoadShipsToSea(int iNumShips, string sGName, int iNation, int iGeraldSails)
{
	ref rPlayer = GetMainCharacter();
	ref rCommander;
	int nflag1, ntex1, nflag2, ntex2;
	nflag2 = GetPirateFlag(rPlayer, &ntex2);
	for (int j = 0; j < iNumShips; j++)
	{
		int iFantomIndex = FANTOM_CHARACTERS + iNumFantoms - iNumShips + j;
		ref rFantom; makeref(rFantom, Characters[iFantomIndex]);

		rFantom.id = "fenc_" + iFantomIndex;
		rFantom.isFantom = true; // TIH used to easily tell a generated shipchar from a stored shipchar Aug27'06

		// set commander to group
		if (j == 0) {
			Group_SetGroupCommander(sGName, rFantom.id);
			rCommander = rFantom;
		}

		// set random character and ship names, face id
		rFantom.sex = "man";
		rFantom.Nation = iNation;

		SetRandomNameToCharacter(rFantom); // KK
		SetRandomNameToShip(rFantom);
		//SetRandomFaceToCharacter(rFantom); // PB: What is this for?

		// screwface : delete the recognized attribute
		ResetCharacterMemory(rFantom);
		// Screwface : end

		rFantom.location = rPlayer.location; //Levis to make sure they are logged in at the right location
		rFantom.location.group = "";
		rFantom.location.locator = "";

		Fantom_SetRandomModel(rFantom, rFantom.fantomtype);
		/*switch(Rand(7))
		{
			case 0: rFantom.quest.officertype = OFFIC_TYPE_BOATSWAIN; break;
			case 1: rFantom.quest.officertype = OFFIC_TYPE_CANNONEER; break;
			case 2: rFantom.quest.officertype = OFFIC_TYPE_QMASTER; break;
			case 3: rFantom.quest.officertype = OFFIC_TYPE_NAVIGATOR; break;
			case 4: rFantom.quest.officertype = OFFIC_TYPE_FIRSTMATE; break;
			case 5: rFantom.quest.officertype = OFFIC_TYPE_CARPENTER; break;
			case 6: rFantom.quest.officertype = OFFIC_TYPE_DOCTOR; break;
			case 7: rFantom.quest.officertype = OFFIC_TYPE_ABORDAGE; break;
		}*/ //Levis done cause we use the set officertype now.
		//Levis determine how much to add to the characters level for this captain.
		//We start at level 10, below that any captain will have difficulties.
		//For each Class of the ship we want an extra 5 levels.
		//And to end we have an random number between -5 and 10
		//Finally we substract the mainplayer level cause this will be added afterwards.
		ref refShip = GetShipByType(sti(rFantom.ship.idx));
		/*int Levelboost = 5 + ((8-sti(refShip.Class)) * 5) + (rand(15) - 5) - sti(rPlayer.rank);
		//The player level could get very high so this will catch that and still give the captain a substantional level.
		int minlevel = 10 + ((8-sti(refShip.Class)) * 2);
		if(Levelboost < minlevel) Levelboost = 10 + ((8-sti(refShip.Class)) * 2) + (rand(7) - 2);
		LAi_Create_Officer(Levelboost, &rFantom);*/
		//rFantom.quest.officerprice = makeint((sti(rPlayer.rank) * 2 + 10)*100) - 330 + rand(40)*15 + rand(10); //Levis this should happen in create officer once the twin character is created
		LAi_NPC_Equip(rFantom, sti(rFantom.rank), true, 0.5);
// added by MAXIMUS <--
		Fantom_SetRandomMoney(rFantom, rFantom.fantomtype);
		Ship_SetFantomData(rFantom);
		Fantom_SetCannons(rFantom, rFantom.fantomtype);
		Fantom_SetSails(rFantom, rFantom.fantomtype);

		rFantom.SeaAI.Group.Name = sGName;

		rFantom.Features.GeraldSails = false;
		if (iGeraldSails > -1) rFantom.Features.GeraldSails = iGeraldSails;

		if (CheckAttribute(rFantom, "after_1st_sailto")) DeleteAttribute(rFantom, "after_1st_sailto");
		RestoreCharacter(rFantom);

		// add fantom
		Group_AddCharacter(sGName, rFantom.id);

		// add to sea
		Ship_Add2Sea(iFantomIndex, 0, rFantom.fantomtype);
	}
}

void Sea_LoginShip(ref chr)
{
	string chrid = chr.id;
	if (!isEntity(&Sea)) {
		trace("SEA: Error: Sea_LoginShip chrid = " + chrid + ", but Sea is not active!");
		return;
	}
	if (!CheckAttribute(chr, "Ship.Pos.x") || !CheckAttribute(chr, "Ship.Pos.z")) {
		trace("Sea_LoginShip: missing position attributes");
		return;
	}
	if (!CheckAttribute(chr, "SeaAI.Group.name")) {
		trace("Sea_LoginShip: missing group name");
		return;
	}

	float x, z, ay;
	x = stf(chr.Ship.Pos.x);
	z = stf(chr.Ship.Pos.z);
	ay = stf(chr.Ship.Ang.y);
	string group = Ship_GetGroupID(chr);
	if (isMainCharacter(CharacterFromID(chrid))) group = PLAYER_GROUP;
	string tmpgrp = group;
	if (CheckAttribute(chr, "SeaAI.Group.MainCharacter") == false || sti(chr.SeaAI.Group.MainCharacter) == false) {
		int i = 1;
		tmpgrp = "tmpgrp_" + group + "_" + i;
		while (Group_FindGroup(tmpgrp) >= 0) {
			i++;
			tmpgrp = "tmpgrp_" + group + "_" + i;
		}
	}

	if (Group_FindGroup(tmpgrp) >= 0) Group_DeleteGroup(tmpgrp);
	Group_CreateGroup(tmpgrp);
	Group_AddCharacter(tmpgrp, chrid);
	Group_SetXZ_AY(tmpgrp, x, z, ay);
	Group_SetGroupCommander(tmpgrp, chrid);
	// Screwface : This section restore necessary attributes for the Sea AI update mod
	Group_DeleteAtEnd(tmpgrp); // Important to avoid a CTD with DirectEncounters & Sea Ai Update
	ref rGroup = Group_GetGroupByID(tmpgrp);
	if(CheckAttribute(rGroup, "id") && !HasSubStr(rGroup.id, "Directenc"))
	{
		rGroup.AlreadyLoaded = "";
		ref Pchar = GetMainCharacter();
		//trace ("ile : " + Pchar.location);
		if(Pchar.location != "" && Pchar.location != "error") rGroup.location = Pchar.location;
	}
	RecalculateCargoLoad(chr); // PB: Check if ship is overweight
	if(CheckAttribute(chr,"fallen")) // Screwface : Need to restore the fallen mast(s) to avoid crashes with set flags
	{
		DeleteAttribute(chr,"ship.sails");
		DeleteAttribute(chr,"ship.masts");
		DeleteAttribute(chr,"fallen");
		Trace("Ship mast restored");
	}
	// Screwface : end
//trace("Set temporary group " + tmpgrp + " coords: x="+x+", z="+z+", ay="+ay);
}
// <-- KK

void Sea_LoginGroup(string sGroupID)
{
	int iNumShips, i, iNumDeadCharacters, iCharacterIndex;
	float x, z, ay;
	bool bSailsState;
	string sLocationGroup, sLocationLocator, sTst;
	ref rGroup, rIsland, rCharacter, rGroupCommander;
	aref arQuestShips, arShip;

	if (!isEntity(&Sea)) {
    trace("SEA: Error: Sea_LoginGroup sGroupID = " + sGroupID + ", but Sea is not active!");
    return;
  }

	if (Group_FindGroup(sGroupID) < 0) {
		trace("SEA: Not find group '" + sGroupID + "' in groups massive, but login try spotted");
		return;
	}

	rGroup = Group_GetGroupByID(sGroupID);
	if (!CheckAttribute(rGroup, "Quest"))
	{
		trace("SEA: Error: Sea_LoginGroup sGroupID = " + sGroupID + ", but group doesn't contain any quest ships!");
		trace("SEA: I am deleting empty group '" + sGroupID +"'");	// LDH keep from having CTD for tasks 15Feb09
		Group_DeleteAtEnd(sGroupID);
		return;
	}
	if (CheckAttribute(rGroup, "AlreadyLoaded")) {
    trace("SEA: Error: Group sGroupID = " + sGroupID + ", already loaded... check for duplicate group login");
    return;
  }

	makearef(arQuestShips, rGroup.Quest);

	iNumShips = GetAttributesNum(arQuestShips);
	if (iNumShips == 0) return;

	x = 0.0;
	z = 0.0;
	ay = 0.0;

	// find group position
	if (CheckAttribute(rGroup, "location") && CheckAttribute(rGroup, "location.group") && rGroup.location != "none") {
		sLocationGroup = rGroup.location.group;
		sLocationLocator = rGroup.location.locator;

		rIsland = GetIslandByID(rGroup.location);

		sTst = sLocationGroup + "." + sLocationLocator + ".x";
		if (CheckAttribute(rIsland, sTst)) {
			x = stf(rIsland.(sLocationGroup).(sLocationLocator).x);
			z = stf(rIsland.(sLocationGroup).(sLocationLocator).z);
			ay = stf(rIsland.(sLocationGroup).(sLocationLocator).ay);
		} else {
			x = 0.0; z = 0.0; ay = 0.0;
			Trace("SEA: Error: Group " + sGroupID + ", Island " + rGroup.location);
			Trace("SEA: Error: Find locators Group " + sLocationGroup + ", Locator " + sLocationLocator);
		}
	} else {
		if (CheckAttribute(rGroup, "Pos")) {
			x = stf(rGroup.Pos.x);
			z = stf(rGroup.Pos.z);
			ay = stf(rGroup.Pos.ay);
		} else {
			Trace("SEA: Error: Sea_LoginGroup sGroupID = " + sGroupID + ", I can't find any locators or position for this group, maybe you can check this???");
		}
	}

	// set group position
	Group_SetXZ_AY(sGroupID, x, z, ay);

	// set group commander
	rGroupCommander = Group_GetGroupCommander(sGroupID);
	// update commander for SEA AI
	Group_SetGroupCommander(sGroupID, rGroupCommander.id);

// KK -->
	bSailsState = Group_GetSailsUp(sGroupID);
	bSailsState = !bSailsState;
// <-- KK

	// set location near
	if (CheckAttribute(rGroup, "location.neargroup"))
	{
		Group_SetPursuitGroup(sGroupID, rGroup.location.neargroup);
	}

	// load group ships
	iNumDeadCharacters = 0;
	for (i=0; i<iNumShips; i++)
	{
		if(iNumShips >= MAX_SHIPS_ON_SEA)
		{
			Trace("SEA: Sea_LoginGroup iNumShips over MAX: "+ iNumShips);
			return; // NK bugfix
		}

		arShip = GetAttributeN(arQuestShips, i);
		rCharacter = GetCharacter(GetCharacterIndex(GetAttributeValue(arShip)));
		iCharacterIndex = sti(rCharacter.index);

		if (CharacterIsDead(rCharacter)) { iNumDeadCharacters++; continue; }
		// LDH added corpses 15Feb09, added checkattribute 20Feb09
		if (CheckAttribute(rCharacter, "chr_ai.group") &&  rCharacter.chr_ai.group == LAI_GROUP_CORPSES)  { iNumDeadCharacters++; continue; }
		if (CheckAttribute(rCharacter, "surrendered") == true && sti(rCharacter.surrendered) == true) { iNumDeadCharacters++; continue; } // KK
		if (bAllies(rCharacter)) { Trace("SEA: Error: You assigned allied character " + GetMySimpleName(rCharacter) + " with ID " + rCharacter.id + " to quest group... This is an error!"); iNumDeadCharacters++; continue; } // PB: Attempted fix for CTDs due to allied characters being assigned to Sea AI groups

		rCharacter.SeaAI.Group.Name = sGroupID;
		Group_AddCharacter(sGroupID, rCharacter.id); // KK

		if(CheckAttribute(rCharacter,"fallen")) // Screwface : Need to restore the fallen mast(s) to avoid crashes with set flags
		{
			DeleteAttribute(rCharacter,"ship.sails");
			DeleteAttribute(rCharacter,"ship.masts");
			DeleteAttribute(rCharacter,"fallen");
			Trace("Ship mast restored");
		}

		Ship_Add2Sea(iCharacterIndex, bSailsState, "");

		ReloadProgressUpdate();
	}

	rGroup.AlreadyLoaded = "";

	if (iNumDeadCharacters == iNumShips)
	{
		Trace("SEA: Warn: I am automatically deleting group '" + sGroupID +"', because it's empty");
		Group_DeleteAtEnd(sGroupID);
		//Group_DeleteGroup(sGroupID);
		return;
	}

	bSeaQuestGroupHere = true;

	Sea_AddGroup2TaskList(sGroupID);
}

void Sea_FirstInit()
{
	bSeaLoaded = true;

	trace("Sea_FirstInit");
	RefreshBattleInterface(true); // PB: Set CORRECT relations after reload has finished

	QuestsCheck(); // PB: For quests executing upon reloading to sea

	// KK: Companion Mutiny -->
	ref rPlayer = GetMainCharacter();
	if (bShipMutiny) {
		for (int i = 1; i < COMPANION_MAX; i++)
		{
			int iCompanionIndex = GetCompanionIndex(rPlayer, i);
			if (iCompanionIndex < 0) continue;
			ref rCompanion = GetCharacter(iCompanionIndex);
			if (!IsMutineer(rCompanion)) continue;
			SeaAI_SetCompanionEnemy(rCompanion);	// PB: Use generic function
		}
		RefreshFlags();
		bShipMutiny = false;						// PB: Once is enough
	}
	// KK: Companion Mutiny <--

	ResetTimeToNormal(); // PB: Reset Time Scale

	trace("Sea_FirstInit done");
}

void Sea_Reload()
{
	DelEventHandler("Sea_Reload", "Sea_Reload");

	object Login;
	Login.PlayerGroup.ay = 0.0;
	Login.PlayerGroup.x = 0.0;
	Login.PlayerGroup.y = 0.0;
	Login.PlayerGroup.z = 0.0;
	Login.Island = Characters[0].location;

	ref rPlayer = GetMainCharacter();							// ccc Survival, NK 05-04-16 bugfix didn't have = GetMainCharacter();
//TIH -->
	if (CheckAttribute(rPlayer, "lifeboatlaunch")) {
		int testIsleIdx = FindIsland(Login.Island);
		if (testIsleIdx != -1) {
			Ship_SetSailState(GetMainCharacterIndex(), 0);//TIH - lowers the sails // KK
			Login.FromCoast = true; //TIH - makes the lifeboat not run into the islands at full speed!
		}
		DeleteAttribute(rPlayer, "lifeboatlaunch");
	}
//TIH <--
	SeaLogin(&Login);
}

void Sea_ReloadStart()
{
	if (!bSeaActive) { return; }
	DeleteSeaEnvironment();
	SetEventHandler("Sea_Reload", "Sea_Reload", 0);
	PostEvent("Sea_Reload", 1);
}
// ccc CR ->
void SetCoastTraffic(string islandstr)
{
	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	// no longer needed if(islandstr == "KhaelRoa") return; // NK tempfix 04-09-09
	if(GetCharacterIndex("Cr" + islandstr+"1") == -1) return; //if no CR chars, return
	if(CheckAttribute(Islands[FindIsland(islandstr)],"skipCR")) { if(sti(Islands[FindIsland(islandstr)].skipCR)) return; } // NK 04-09-14
	ref Pchar = GetMainCharacter();
	ref CurIsland = GetIslandByIndex(FindIsland(islandstr));
	string chrstr = "Cr" + islandstr;
	string sFantomType;
	int crnation, grpidx, j, nflag1, ntex1, nflag2, ntex2, crship;
	int i = 1;

	while(i < 6-((sti(CurIsland.smuggling_nation) == PIRATE)*2))		// 1st loop to create 3 groups for 2 ships each, NK to reduce at pirate islands
	{
		string crg = chrstr + i;
		grpidx = Group_FindGroup(crg); // NK bugfix to not delete not-existing group 05-05-02
		if(grpidx != -1) Group_DeleteGroup(crg);				//to clear for SeaLogin

		string pos = GetRandomQuestShipLocator(islandstr); // PB: Use all available quest ship locators
		Group_CreateGroup(crg);
		Group_SetGroupCommander(crg, crg);
		Group_SetAddress(crg, islandstr, "Quest_Ships", pos);
		if (frnd() < COASTRAIDER_CHANCE)
		{
			// NK 04-08-27 -->
			if(frnd() < NAVYRAIDER_CHANCE)
			{
				crnation = FindEnemyNation2Nation(sti(CurIsland.smuggling_nation));
				if(crnation != PIRATE) sFantomType = "war"; //have to check, because PIRATE is a nation
				else sFantomType = "pirate";
			}
			else
			{
				crnation= PIRATE;
				sFantomType = "pirate";
			}
		}
		else
		{
			// NK 04-09-09 add coastguard and other trade nation cases
			if(frnd() < COASTGUARD_CHANCE)
			{
				sFantomType = "war"; //NK now that PRS3 uses Fantom_GetShip call, must also choose whether trade or war
				crnation =  sti(CurIsland.smuggling_nation);
			}
			else
			{
				sFantomType = "trade";
				crnation = FindFriendlyNation2Nation(sti(CurIsland.smuggling_nation));
				if(frnd() < TRADE_OTHERNATIONCHANCE && crnation != -1)
				{
					//nothing
				}
				else { crnation = sti(CurIsland.smuggling_nation); }
			/*	if (GetRMRelationType(GetRMRelation(PChar,crnation)) == RELATION_ENEMY) // NK change to use RM
				{
					Group_SetTaskRunAway(crg);
					Group_LockTask(crg);
				}
				else
				{
					Group_SetTaskMove(crg, 10000.0, 10000.0);
				}*/
			}
			// NK 04-09-09 <--

			// NK 04-08-27 <--
			// crg is string, not object - crg.nation = crnation;						//nation for group
		}

		nflag2 = GetPirateFlag(Pchar, &ntex2);
		for( j = 0; j <2 ; j++)	// 2nd loop to create 2 ships for each group
		{
			ref cr = CharacterFromID(chrstr + (i+j));
			//trace(".");
			string trstr = "SetCoastTraffic: Char " + cr.id + " of type " + sFantomType + " and nation " + GetNationNameByType(sti(cr.nation));
			// NK to reuse existing if within a week 04-09-09
			bool bDead = CharacterIsDead(cr); // KK
			if (sti(cr.nation) == NEUTRAL_NATION)
			{
				trstr += " was neutral nation,";
				bDead = true; // KK
			}

			if (CheckAttribute(cr, "surrendered"))
			{
				trstr += " was surrendered,";
				bDead = true;	// LDH - 05Feb09
			}

			if (cr.chr_ai.group == LAI_GROUP_CORPSES) 	// LDH - 14Feb09
			{
				trstr += " was a corpse,";
				bDead = true;
			}

			if(bDead) trstr += " is dead";
			// KK if(bDead) SetCharacterShipLocation(cr, "");
			bool bgennew = bDead && frnd() < DEAD_GENNEW_CR;
			if(bgennew) trstr += " and will be regen'd from dead.";
			if(!bgennew)
			{
				trstr += " and we'll check to see if we regen";
				bgennew = true;
				if(CheckAttribute(cr, "crmonth") && CheckAttribute(cr, "crday"))
				{
					// LDH changed to use GetPastTime() 14Feb09
					// days pass quicker with directsail, so CR_PERSIST will need to be longer.  GetPastTime() makes calcs more accurate
					int oldyear = GetDataYear();  if (sti(cr.crmonth) > GetDataMonth()) oldyear -= 1;
					int days = GetPastTime("day", oldyear, sti(cr.crmonth), sti(cr.crday), 0.0, GetDataYear(), GetDataMonth(), GetDataDay(), 0.0);
					// LDH faster calculation 20Feb09
//					int days = GetDayOfYear(GetDataYear(), GetDataMonth(), GetDataDay()) - GetDayOfYear(oldyear, sti(cr.crmonth), sti(cr.crday);
//					if (days < 0) days += 365;	// Ignoring leap year here.  It's close enough.
					if(days < CR_PERSIST)
					{
						bgennew = false;
					}
				}
				if(bgennew) trstr += ": yes.";
				else trstr += ": no.";
			}

			CRTrace(trstr);
			trstr = "";

			if(GetCharacterShipType(&cr) == SHIP_NOTUSED && !bDead)
			{
				CRTrace("bgennew set to true anyway");		// LDH 15Feb09
				bgennew = true;
			}
			if(bgennew)
			{
				ClearCharacter(cr); // PB: Clear ALL attributes from previous character

				cr.crmonth	= environment.date.month;
				cr.crday	= environment.date.day;
				cr.nation	= crnation;						//nation for character
// KK -->
				if (crnation == PIRATE) {
					sFantomType = "pirate"; // NK 04-09-12 because for QC pirates are coastguard!
				}
				//trstr = "New dates!m" + cr.crmonth + " d" + cr.crday + ".";
				// NK <--

				cr.location = PChar.location; //Levis so they are logged in at the right location
				cr.location.group = "";
				cr.location.locator = "";
// <-- KK

				cr.quest.officertype = GetCaptainType(cr); // NK 04-08-27
				cr.FantomType = sFantomType;

				// PRS3 new get ship call
				int minclass = MIN_CLASS;
				//scale minclass between 7 and CR_MAX_MINCLASS based on PChar level
				if(GetLevel(&Pchar) < (MIN_CLASS-CR_MAX_MINCLASS)*CR_MINCLASS_PERLEVEL) minclass = (MIN_CLASS - makeint(makefloat(GetLevel(&Pchar)) / CR_MINCLASS_PERLEVEL));
				int maxclass = MAX_CLASS;

				switch(sFantomType)
				{
					case "pirate": maxclass = CR_MAXPIRATECLASS; break;
					case "trade": maxclass = MAXMERCHANTCLASS; break;
					case "war": if(crnation == sti(CurIsland.smuggling_nation)) { maxclass = MAXCOASTGUARDCLASS; } break;
				}
				// cap if GetShipCap()
				if(GetShipCap() && maxclass < GetCharacterShipClass(Pchar) - CR_CLASS_ABOVE_PCHAR) maxclass = GetCharacterShipClass(Pchar) - CR_CLASS_ABOVE_PCHAR;
				if(GetShipCap() && maxclass < (MIN_CLASS+1)-GetLevel(Pchar) - CR_CLASS_ABOVE_PCHAR) maxclass = (MIN_CLASS+1) - GetLevel(Pchar) - CR_CLASS_ABOVE_PCHAR;
				if(maxclass < MAX_CLASS) maxclass = MAX_CLASS;
				//trstr += " Maxclass " + maxclass + ", minclass " + minclass;
				crship = Force_GetShipType(maxclass, minclass, sFantomType, crnation);
				//trstr += ". Ship ID " + GetShipID(crship);
// KK -->
				Ship_CreateForCharacter(cr, GetShipID(crship), "Coaster");

				string sFantomTypeTmp = sFantomType;
				if (GetCharacterShipClass(cr) <= 3 && sti(ShipsTypes[crship].type.war) == true && sti(cr.nation) != PIRATE) sFantomTypeTmp = "war";
				Fantom_SetRandomModel(cr, sFantomTypeTmp);
				SetRandomNameToCharacter(cr);
// <-- KK
				// NK PRS3 getshiptype <--

				//equip ship
				cr.rank = GetCaptainRank(cr); //Levis
				LAi_NPC_Equip(cr, sti(cr.rank), true, 0.5); // PB: Weapons needed
				Ship_SetFantomData(cr);
				Fantom_SetCannons(cr, sFantomType);
				Fantom_SetSails(cr, sFantomType);
				Fantom_ClearCargo(cr); // TIH clear out prior slot cargo
				Fantom_SetBalls(cr, sFantomType);
				Fantom_SetGoods(cr, sFantomType);
				Fantom_SetRandomMoney(cr, sFantomType);

				SetRandomNameToShip(cr);

				if (crnation == PIRATE)
				{
					cr.perks.list.ShipSpeedUp = true;
					cr.Ship.crew.quantity = GetMaxCrewQuantity(cr);
				}
				
				InitAutoSkillsSystem(cr,false); //Levis
				// move down - SetCharacterRelationBoth(sti(cr.index), GetMainCharacterIndex(), GetRMRelationType(GetRMRelation(PChar, sti(cr.nation)))); // NK set base relation to avoid gray icon
				//trace(trstr);
			}
			else {
				crship = GetCharacterShipType(cr);
				/*trace("resuming old ship type, " + cr.ship.type);*/
			}

			if(bDead && !bgennew) // 04-09-15 remove from group if dead. Seems to work OK without, but let's be sure. // LDH added !bgennew - 14Feb09
			{
				CRTrace("The " + cr.ship.name + " was deleted from the group");	// LDH 15Feb09
				Group_DelCharacter(crg, cr.id);
				// if this group is empty it will be deleted in Sea_LoginGroup() LDH 15Feb09
			}
			else
			{
				CRTrace(cr.id + " is not dead, adding.");
				// NK 04-09-20 if group cmdr is not same nation
				ref gcmdr = CharacterFromID(crg);
				if(sti(gcmdr.index) != sti(cr.index))
				{
					CRTrace("cr is not group commander");
					if(CharacterIsDead(gcmdr) ||
						CheckAttribute(gcmdr, "surrendered") ||		// LDH added surendered - 14Feb09
						gcmdr.chr_ai.group == LAI_GROUP_CORPSES ||	// LDH added corpses - 15Feb09
						gcmdr.nation != cr.nation) // KK
					{
						CRTrace("create new grp");
						Group_DelCharacter(crg, cr.id);
						Group_AddCharacter(crg + "_1", cr.id);
						Group_SetGroupCommander(crg + "_1", cr.id);
						Group_SetType(crg + "_1", sFantomType);
						Group_SetAddress(crg + "_1", islandstr, "Quest_Ships", pos);
					}
					else
					{
						CRTrace("do not need to create new group")
						Group_ChangeCharacter(crg, cr.id);
						//Group_SetGroupCommander(crg, cr.id);
						bool t2 = Group_GetType(crg) != "war" || sFantomType == "war"; // KK
						if(!t2) t2 = Group_GetType(crg) != "pirate" || sFantomType == "pirate"; // KK
						if(t2) Group_SetType(crg, sFantomType);
					}
				}
				else
				{
					CRTrace("cr is group commander");
					Group_ChangeCharacter(crg, cr.id);
					Group_SetGroupCommander(crg, cr.id);
					Group_SetType(crg, sFantomType);
				}
				// NK 04-09-20 <--
				if(sti(cr.Ship.Cannons.Type) != CANNON_TYPE_NONECANNON) cr.ship.cannons.charge.type = GOOD_BALLS; // NK 04-09-20 for ammo bugfix, KNB

				// NK to convert shipname to nice string
				if(LogsToggle >= LOG_NORMAL && iRealismMode == 0) { // Screwface
					Log_SetStringToLog(XI_ConvertString("BA") + " " + XI_ConvertString(ShipsTypes[crship].sname) + " " + XI_ConvertString("flying") + " " + XI_ConvertString("1"+GetNationDescByType(sti(cr.nation))) + " " + TranslateString("","colors sighted at") + " " +  FindIslandName(islandstr));  // KK
					//Log_SetStringToLog("-");
				}

				if(bgennew)
				{
					// NK fix this to only do correct one. 05-07-11
					switch(islandstr)
					{
						case "QuebradasCostillas": setCharacterShipLocation(cr,"QC_port"); break;
						case "IslaMuelle": setCharacterShipLocation(cr,"Muelle_port"); break;
						case "FalaiseDeFleur": setCharacterShipLocation(cr, "Falaise_de_fleur_port_01"); break;
						case "Curacao": SetCharacterShipLocation(cr, "Willemstad_port"); break; // KK
						case "Aruba": SetCharacterShipLocation(cr, "Oranjestad_port"); break; // KK
						setCharacterShipLocation(cr, islandstr + "_port"); // default case
					}
					// NK <--
				}
// KK -->
				if (CheckAttribute(cr, "after_1st_sailto")) DeleteAttribute(cr, "after_1st_sailto");
// <-- KK
			}
			// NK <--
		}
		//if (Group_GetCharactersNum(crg) == 0 && Group_FindGroup(crg) != -1) Group_DeleteGroup(crg); // KK

		i=i+2		//doublestep for grouploop
	}
	//LanguageCloseFile(tmpLangFileID);
}
// ccc CR <-

void CRTrace(string str)
{
	if (DEBUGCR) Trace(str);
}

// KK -->
void LoadAtSea()
{
	int i, iNum;
	aref artmp, arnode, arenc;
	ref rtmp;
	ref mc = GetMainCharacter();
	float x, z;
	object SLogin;
	ref sl; makeref(sl, SLogin);

	sl.location = mc.location;
	sl.location.group = mc.location.group;
	sl.location.locator = mc.location.locator;
	sl.Island = mc.location;
	rtmp = Group_FindOrCreateGroup(PLAYER_GROUP);
	sl.PlayerGroup.x = rtmp.Pos.x;
	sl.PlayerGroup.z = rtmp.Pos.z;
	sl.PlayerGroup.ay = rtmp.Pos.ay;

	for (i = 0; i < iNumShips; i++)
	{
		if (Ships[i] < 0) continue;
		rtmp = GetCharacter(Ships[i]);
		string l = "l" + i;
		if (CharacterIsDead(rtmp)) {
			sl.Ship.(l).idx = -1;
			continue;
		}
		sl.Ship.(l).idx = Ships[i];
		/*sl.Ship.(l).Pos.x = rtmp.Ship.Pos.x;
		sl.Ship.(l).Pos.y = rtmp.Ship.Pos.y;
		sl.Ship.(l).Pos.z = rtmp.Ship.Pos.z;
		sl.Ship.(l).Pos.ay = GetAngleY(stf(rtmp.Ship.Pos.x), stf(rtmp.Ship.Pos.z));*/
		sl.Ship.(l).Group = Ship_GetGroupID(rtmp);
		if (GetCharacterIndex(rtmp.id) == Group_GetGroupCommanderIndex(Group_GetGroupByID(Ship_GetGroupID(rtmp)))) {
			rtmp.SeaAI.Group.MainCharacter = true;
			/*rtmp.SeaAI.Group.MainCharacter.Task = Group_GetTask(rtmp.SeaAI.Group.name);
			rtmp.SeaAI.Group.MainCharacter.Target = Group_GetGroupTarget(rtmp.SeaAI.Group.name);
			Group_GetGroupTargetPos(rtmp.SeaAI.Group.name, &x, &z);
			rtmp.SeaAI.Group.MainCharacter.Target.Pos.x = x;
			rtmp.SeaAI.Group.MainCharacter.Target.Pos.z = z;
Trace("LoadAtSea: chr.id="+rtmp.id+": task: "+rtmp.SeaAI.Group.MainCharacter.Task+", target: "+rtmp.SeaAI.Group.MainCharacter.Target+", pos: "+x+";"+z);*/
		}
		if (CheckAttribute(rtmp, "Ship.old.Masts")) {
			if (CheckAttribute(rtmp, "Ship.Masts")) DeleteAttribute(rtmp, "Ship.Masts");
			aref arOldMasts; makearef(arOldMasts, rtmp.Ship.old.Masts);
			rtmp.Ship.Masts.Mast1 = 0;
			aref arMasts; makearef(arMasts, rtmp.Ship.Masts);
			DeleteAttribute(arMasts, "Mast1");
			CopyAttributes(arMasts, arOldMasts);
			DeleteAttribute(rtmp, "Ship.old");
		}
	}
	sl.Ship.Quantity = iNumShips;

	sl.LoadAtSea = true;

	//DeleteAttribute(mc, "SaveData");
	SendMessage(&AIBalls, "l", MSG_MODEL_RESTORE);

	// Screwface : We restore the current load attributes to not loose balls & gunpowder
	if(CheckAttribute(mc,"save"))
	{
		if(CANNONPOWDER_MOD)
		{
			AddCharacterGoods(mc,GOOD_GUNPOWDER,sti(mc.save.gunpowder));
		}
		AddCharacterGoods(mc,sti(mc.save.currentcharge),sti(mc.save.currentchargeqty));
		DeleteAttribute(mc, "Save");
	}
	// Screwface : end

	SeaLogin(sl);

	//Fader
	PostEvent("LoadSceneSound", 500);
}

void RestoreEncounters(ref Encounters)
{
	int i, iNum;

	iNumShips = 0;

	iNum = GetAttributesNum(Encounters);
	for (i = 0; i < iNum; i++)
	{
		aref arEncounter = GetAttributeN(Encounters, i);
		int iFantomIndex = sti(arEncounter.index);
		if (iFantomIndex < 0) continue;
		ref rFantom = GetCharacter(iFantomIndex);
		string FantomID = rFantom.id;
		DeleteAttribute(rFantom, "");
		CopyAttributes(rFantom, arEncounter);
		rFantom.index = iFantomIndex;
		rFantom.id = FantomID;
		string sGroupID = Ship_GetGroupID(rFantom);
		ref rGroup = Group_FindOrCreateGroup(sGroupID);
		Group_AddCharacter(sGroupID, FantomID);
		if (Group_GetGroupCommanderIndex(rGroup) == iFantomIndex) Group_SetGroupCommander(sGroupID, FantomID);
		Ship_Login(iFantomIndex);
	}
}

float GetVisibilityRange(int iRange)
{
	float visibility_range;
	switch (iRange)
	{
		case 1:
			visibility_range = 2000.0;
		break;
		case 2:
			visibility_range = 1000.0;
		break;
		case 3:
			visibility_range = 500.0;
		break;
		// default:
			visibility_range = 3000.0;
			
	}
	visibility_range -= (stf(Weathers.Fog.SeaDensity) * 130 * visibility_range);
	if (Whr_IsNight()) visibility_range /= 2.0;
	return visibility_range;
}

float GetCharVisibilityRange(ref chr, int iRange)
{
	// higher leadership and sailing skills result in better vision
	float visibility_range = GetVisibilityRange(iRange);
	visibility_range += makefloat(GetShipSkill(chr, SKILL_LEADERSHIP) * GetShipSkill(chr, SKILL_SAILING) * 5); // KK
	return visibility_range;
}
// <-- KK

// Screwface
void SetCorrectWorldMapPosition()
{
	ref Pchar = GetMaincharacter();

	if(Pchar.location != "" && Pchar.location != "error")
	{
		string island = Pchar.location;
		float psX = MakeFloat(pchar.Ship.Pos.x);
		float psZ = MakeFloat(pchar.Ship.Pos.z);
		float ix = MakeFloat(worldMap.islands.(Island).position.rx);
		float iz = MakeFloat(worldMap.islands.(Island).position.rz);

		//REAL CONVERTION OF YOUR SEAVIEW COORDS IN WORLD MAP COORDS
		worldMap.playerShipX = (psX/WDM_MAP_TO_SEA_SCALE) + ix;
		worldMap.playerShipZ = (psZ/WDM_MAP_TO_SEA_SCALE) + iz;
	}
}
