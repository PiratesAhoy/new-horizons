#include "FCoHS\FCoHS_Settings.h"
#include "FCoHS\FCoHS_Globals.h"

// --------------
// Main Functions
// --------------

// Start Updating
void FCoHS_Main_Start()
{
	if (!bFCoHS_Enabled)
	{
		return;
	}

	Trace("FCoHS started");
	ref pchar = GetMainCharacter();
	pchar.FCoHS = true; // PB: Attribute to indicate the mod is started

	// Register event handlers
	SetEventHandler("FCoHS_Update", "FCoHS_Main_Update", 0);				// ..for periodical update
	SetEventHandler("FCoHS_BICom_HailShip", "FCoHS_Com_HailShip", 0);		// ..for BattleInterface command
	SetEventHandler("FCoHS_BICom_ContactShip", "FCoHS_Com_ContactShip", 0);	// ..for BattleInterface command

	// Init globals (just to be sure)
	bFCoHS_HailCanBe = false;
	bFCoHS_ContactCanBe = false;
	iFCoHS_ContactCanBeCharIdx = -1;

	// Start updating
	Event("FCoHS_Update");
}

// Stop Updating
void FCoHS_Main_Stop()
{
	if (!bFCoHS_Enabled)
	{
		return;
	}

	ref pchar = GetMainCharacter();
	DeleteAttribute(pchar, "FCoHS"); // PB: Remove attribute to indicate the mod is stopped

	// Unregister event handlers
	DelEventHandler("FCoHS_Update", "FCoHS_Main_Update");
	DelEventHandler("FCoHS_Hail_Ship", "FCoHS_Main_HailShip");
	DelEventHandler("FCoHS_Contact_Ship", "FCoHS_Main_ContactShip");

	// Reset globals
	bFCoHS_HailCanBe = false;
	bFCoHS_ContactCanBe = false;
	iFCoHS_ContactCanBeCharIdx = -1;

	// @CHECK (EL#1#): Cleanup of Char.FCoHS... attributes necessary?

	// Stop updating
	Trace("FCoHS stopped");
}

// Update Contact and Hail Situation
void FCoHS_Main_Update()
{
	float fDistance;
	int iCharIdx;
	bool bContactCanBe = false;
	bool bHailCanBe = false;

	ref rMainCharacter = GetMainCharacter();

	// Update every 5 seconds
	PostEvent("FCoHS_Update", 5000);

	// Check if hailing and/or contact is possible and get distance and ID of possible contact ship
	if (GetAttribute(rMainCharacter, "SeaAI.Update.Situation.MinEnemyDistance") > fFCoHS_MinAllowedEnemyDistance) // PB: Missed attribute "seaai"?
	{
		bContactCanBe = FCoHS_Util_CheckShips(&fDistance, &iCharIdx, &bHailCanBe);
	}

	// Enable/Disable hailing
	if (bHailCanBe == true)
	{
		bFCoHS_HailCanBe = true;
	}
	else
	{
		bFCoHS_HailCanBe = false;
	}

	// Enable/Disable contact
	if (bContactCanBe == true)
	{
		bFCoHS_ContactCanBe = true;
		iFCoHS_ContactCanBeCharIdx = iCharIdx;
	}
	else
	{
		bFCoHS_ContactCanBe = false;
		iFCoHS_ContactCanBeCharIdx = -1;
	}
}

// -------------------------------
// Functions after player commands
// -------------------------------

// Hail ship
void FCoHS_Com_HailShip(int iHailTarget)
{
	ref rShipCharacter = GetCharacter(iHailTarget);
	float fComplyToHailChance;

	// Calculate "Comply to hail" chance
	//fComplyToHailChance = FCoHS_Util_CalculateComplyToHailChance(rShipCharacter); // PB: Temporarily unused
	fComplyToHailChance = 100;

	// Roll the dice
	if (Rand(100) < fComplyToHailCHance)
	{
		rShipCharacter.FCoHS.CompliedToHail = true;
		rShipCharacter.FCoHS.HailingTime = GetSeaTime();
		Ship_SetTaskDrift(SECONDARY_TASK, iHailTarget);
	//	KrakenAttack(rShipCharacter, 100); // PB: Just for fun!
	}
	else
	{
		rShipCharacter.FCoHS.CompliedToHail = false;
		rShipCharacter.FCoHS.HailingTime = GetSeaTime();
	}
}

// Contact ship (i.e. board ship)
void FCoHS_Com_ContactShip()
{
	ref rShipCharacter = GetCharacter(iFCoHS_ContactCanBeCharIdx);

	if (!CheckAttribute(rShipCharacter, "FCoHS.CompliedToHail")) return;
	if (rShipCharacter.FCoHS.CompliedToHail == true)
	{
	//	FCoHS_Boarding_Start(iFCoHS_ContactCanBeCharIdx); // PB: Can't get this to work yet
		Sea_DeckStartNow(iFCoHS_ContactCanBeCharIdx, GetCharacterShipQDeck(rShipCharacter)); // PB: This works to a certain extent
	}
	else
	{

	}
}

// ------------------
// Boarding functions
// ------------------

// Start boarding
void FCoHS_Boarding_Start(int iBoardingTarget)
{
	ref rMainCharacter = GetMainCharacter();
	ref rShipCaptain = GetCharacter(iBoardingTarget);

	// Global variables used outside of FCoHS >>
	bSeaReloadStarted = true;
	Sea.AbordageMode = true;
	bDeckEnter = true;
	iShipCaptain = iBoardingTarget;
	bAbordageStarted = true;

	// @CHECK (EL#2#): Boarding: Are these globals needed?
	bCrewStarted = false;
	bDeckStarted = false;
	bCabinStarted = false;
	bToDeckFromLand = false;
	// << Global variables used outside of FCoHS

	// Global variables for FCoHS
	iFCoHS_BoardingCaptain = iBoardingTarget;
	sFCoHS_DeckName = GetCharacterShipQDeck(rShipCaptain);

	// Create reload fader
	object reload_fader;
	CreateEntity(&reload_fader, "fader");

	// Handlers for reload fader events
	SetEventHandler("FaderEvent_StartFade", "FCoHS_Boarding_StartFade", 0);
	SetEventHandler("FaderEvent_EndFade", "FCoHS_Boarding_EndFade", 0);

	// Handler for control activation (using a reload hotspot, i.e. doors etc)
	// @TODO (EL#1#): Boarding: Implement Deck-to-Deck functions
	//SetEventHandler("Control Activation", "FCoHS_TeleportToDeck", 1);

	// Loading screen for friendly boarding
	// @TODO (EL#3#): Boarding: Implement loading screen
	//SendMessage(&reload_fader, "ls", FADER_PICTURE, FindReloadPicture(Locations[FindLocation(DeckID)].image));

	// Fade out
	SendMessage(&reload_fader, "lfl", FADER_OUT, RELOAD_TIME_FADE_OUT, false);
	SendMessage(&reload_fader, "l", FADER_STARTFRAME);

	// Reset sounds
	PauseAllSounds();
	//ResetSoundScheme();
	ResetSound();

	// Used by DirectSail
	rMainCharacter.IsOnDeck = true;
}

// Reload to other deck - start fade
void FCoHS_Boarding_StartFade()
{
	// Get event data from fader event
	int a = GetEventData();
	aref reload_fader = GetEventData();

	// Layers
	LayerFreeze(SEA_EXECUTE, true);
	LayerFreeze(SEA_REALIZE, true);
	LayerFreeze("sea_reflection", true);
	LayerFreeze("execute", false);
	LayerFreeze("realize", false);
	MoveWeatherToLayers("execute", "realize");
	MoveSeaToLayers("execute", "realize");

	// Delete all cannonballs (although we shouldn't be in combat)
	SendMessage(&AIBalls, "l", MSG_MODEL_RELEASE);

	// Set maxinum sea height for ship deck
	if (CheckAttribute(Sea, "MaxSeaHeight"))
	{
		fOldMaxSeaHeight = stf(Sea.MaxSeaHeight);
		Sea.MaxSeaHeight = 1.2;
	}

	// Fader event has been processed, delete handler
	DelEventHandler("FaderEvent_StartFade", "FCoHS_Boarding_StartFade");
}

// Reload to other deck - end fade
void FCoHS_Boarding_EndFade()
{
	// Get event data from fader event
	int a = GetEventData();
	aref reload_fader = GetEventData();

	// Delete current cannonballs (although we shouldn't be in combat)
	AIBalls.Clear = "";

	// Unload all models
	aref arModel;
	if (FindClass(&arModel, "modelr"))
	{
		SendMessage(arModel, "l", MSG_MODEL_RELEASE);
		while (FindClassNext(&arModel))
		{
			SendMessage(arModel, "l", MSG_MODEL_RELEASE);
		}
	}

	// Pause particles
	PauseParticles(true);

	// Load the deck
	FCoHS_Boarding_PrepareLoadDeck();

	// Fader event has been processed, delete handler
	DelEventHandler("FaderEvent_EndFade", "FCoHS_Boarding_EndFade");

	// Fade in
	SendMessage(&reload_fader, "lfl", FADER_IN, RELOAD_TIME_FADE_IN, true);
}

// Start deck loading
void FCoHS_Boarding_PrepareLoadDeck()
{
	// Reset sounds
	//ResetSoundScheme();
	ResetSound();
	PauseAllSounds();

	// Switch interface from sea to land
	DeleteBattleInterface();
	InitBattleLandInterface();
	StartBattleLandInterface();

	ref rMainCharacter = GetMainCharacter();

	// Check loaction
	int iLocID = -1;
	iLocID = FindLocation(sFCoHS_DeckName);
	if (iLocID < 0)
	{
		sFCoHS_DeckName = "";
		return;
	}

	// Setup reload map for deck
	// FCoHS_Boarding_SetUpDeckReloadMap();

	// Save current location of main character
	boarding_adr[0].location = rMainCharacter.location;
	boarding_adr[0].group = rMainCharacter.location.group;
	boarding_adr[0].locator = rMainCharacter.location.locator;

	// Load Deck
	FCoHS_Boarding_LoadDeck();

	// Create boarding fader
	CreateEntity(&boarding_fader, "fader");

	// Fade in
	SendMessage(&boarding_fader, "lfl", FADER_IN, RELOAD_TIME_FADE_IN, true);
}

// Load deck
void FCoHS_Boarding_LoadDeck()
{
	// Reload progress start
	ReloadProgressStart();
	//SetDeckPortBackground();

	int iLocID = FindLocation(sFCoHS_DeckName);
	ref rMainCharacter = GetMainCharacter();

	// Get new location and locator for main character
	if (iLocID >= 0)
	{
		if (!bCanEnterToLand && HasSubStr(DeckID, "ShipDeck"))
		{
			locations[iLocID].coxswain = true;
		}

		// New location for main character
		rMainCharacter.location = sFCoHS_DeckName;
		rMainCharacter.location.group = "rld";
		rMainCharacter.location.locator = "startloc";

//		bEmergeOnStartloc = true;
		chrWaitReloadIsNoLink = false;
//		iFCoHS_FromDeckIdx = -1;
		current_locator_name = "";

		//Loadcharacter into location
		iFCoHS_BoardingLocation = iLocID;
		Locations[iLocID].boarding = "true";
		if (LoadLocation(&Locations[iLocID]))
		{
			dialogDisable = false;
		}
		else
		{
			Trace("FCoHS - Location not loaded: " + sFCoHS_DeckName);
		}
	}
	else
	{
		Trace("FCoHS - Location not found: " + sFCoHS_DeckName);
	}

	// Weather
	if (HasSubStr(FindCurrentDeck(), "ShipDeck"))
	{
		Whr_UpdateWeather(false);
	}
	else
	{
		WhrDeleteRainEnvironment();
	}

	// Reload progress end
	ReloadProgressEnd();
	PostEvent("LoadSceneSound", 500);
}

// Setup reload map for deck
void FCoHS_Boarding_SetUpDeckReloadMap()
{
	ref mc = GetMainCharacter();
	ref rShipCaptain = GetCharacter(iShipCaptain);
	int mcidx = GetMainCharacterIndex();
	int companion_no = GetCompanionNumber(mc, iShipCaptain);
	string deck = GetCharacterShipQDeck(rShipCaptain);
	int ncdecks = GetCharacterShipCannonsDeckCount(rShipCaptain);
	int nholds = GetCharacterShipCargoHoldCount(rShipCaptain);
	int ndecks = GetCharacterShipDeckCount(rShipCaptain);
	int ideck = FindLocation(deck);
	int icabin = -1;
	if (iShipCaptain == mcidx)
		icabin = FindLocation("Tutorial_Deck");
	else
		icabin = FindLocation("Companion_Cabin_" + companion_no);
	int iseadogs = FindLocation("Seadogs");
	int icdeck1 = FindLocation("Deck1");
	int icdeck2 = FindLocation("Deck2");
	int icdeck3 = FindLocation("Deck3");
	int ihold1 = FindLocation("Hold1");
	int ihold2 = FindLocation("Hold2");
	string tmpdeck = "";
	int itmpdeck = -1;

	if (ncdecks == 0)
	{
		Locations[iseadogs].reload.l1.go = "Hold1";
		Locations[iseadogs].reload.l1.emerge = "reload2";
		Locations[ihold1].reload.l2.go = "Seadogs";
		Locations[ihold1].reload.l2.emerge = "reload1";
	}
	else
	{
		Locations[iseadogs].reload.l1.go = "Deck1";
		Locations[iseadogs].reload.l1.emerge = "reload2";
		Locations[icdeck1].reload.l2.go = "Seadogs";
		Locations[icdeck1].reload.l2.emerge = "reload1";
	}

	if (ncdecks == 1)
	{
		Locations[icdeck1].id.label = "Main Cannons Deck";
		if (nholds == 1)
		{
			Locations[icdeck1].reload.l3.go = "Hold1";
			Locations[icdeck1].reload.l3.emerge = "reload1";
			Locations[icdeck1].reload.l4.go = "";
			Locations[icdeck1].reload.l4.emerge = "";
			Locations[ihold1].reload.l1.go = "Deck1";
			Locations[ihold1].reload.l1.emerge = "reload3";
			Locations[ihold1].reload.l2.go = "";
			Locations[ihold1].reload.l2.emerge = "";
		}
		else
		{
			Locations[icdeck1].reload.l3.go = "Hold1";
			Locations[icdeck1].reload.l3.emerge = "reload1";
			Locations[icdeck1].reload.l4.go = "";
			Locations[icdeck1].reload.l4.emerge = "";
			Locations[ihold1].reload.l1.go = "Deck1";
			Locations[ihold1].reload.l1.emerge = "reload3";
		}
	}
	else
	{
		tmpdeck = "Deck2";
		itmpdeck = icdeck2;
		if (ncdecks == 2)
		{
			tmpdeck = "Deck3";
			itmpdeck = icdeck3;
		}
		Locations[icdeck1].id.label = "Upper Cannons Deck";
		Locations[icdeck3].id.label = "Main Cannons Deck";
		Locations[icdeck1].reload.l3.go = tmpdeck;
		Locations[icdeck1].reload.l3.emerge = "reload2";
		Locations[icdeck1].reload.l4.go = tmpdeck;
		Locations[icdeck1].reload.l4.emerge = "reload1";
		Locations[itmpdeck].reload.l1.go = "Deck1";
		Locations[itmpdeck].reload.l1.emerge = "reload4";
		Locations[itmpdeck].reload.l2.go = "Deck1";
		Locations[itmpdeck].reload.l2.emerge = "reload3";
	}

	if (ncdecks == 3)
	{
		Locations[icdeck2].id.label = "Lower Cannons Deck";
		Locations[icdeck2].reload.l3.go = "Deck3";
		Locations[icdeck2].reload.l3.emerge = "reload2";
		Locations[icdeck2].reload.l4.go = "Deck3";
		Locations[icdeck2].reload.l4.emerge = "reload1";
		Locations[icdeck3].reload.l1.go = "Deck2";
		Locations[icdeck3].reload.l1.emerge = "reload4";
		Locations[icdeck3].reload.l2.go = "Deck2";
		Locations[icdeck3].reload.l2.emerge = "reload3";
	}

	if (ncdecks > 1 && nholds > 0)
	{
		Locations[icdeck3].reload.l3.go = "Hold1";
		Locations[icdeck3].reload.l3.emerge = "reload1";
		Locations[ihold1].reload.l1.go = "Deck3";
		Locations[ihold1].reload.l1.emerge = "reload3";
	}

	if (nholds == 2)
	{
		Locations[ihold1].id.label = "1st Cargo Hold";
		Locations[ihold1].reload.l2.go = "Hold2";
		Locations[ihold1].reload.l2.emerge = "reload2";
		Locations[ihold2].id.label = "2nd Cargo Hold";
		Locations[ihold2].reload.l2.go = "Hold1";
		Locations[ihold2].reload.l2.emerge = "reload2";
		Locations[ihold2].reload.l1.go = "";
		Locations[ihold2].reload.l1.emerge = "";
	}
	else
	{
		Locations[ihold1].id.label = "Cargo Hold";
	}

	Locations[icabin].reload.l1.go = deck;
	Locations[icabin].reload.l1.emerge = "reload1";
	if (iShipCaptain == mcidx)
		Locations[ideck].reload.l1.go = "Tutorial_Deck";
	else
		Locations[ideck].reload.l1.go = "Companion_Cabin_" + companion_no;
	Locations[ideck].reload.l1.emerge = "reload1";

	if (deck == "ShipDeck2" || deck == "ShipDeck4" || deck == "ShipDeck6")
	{
		if (iShipCaptain == mcidx)
			Locations[ideck].reload.l7.go = "Tutorial_Deck";
		else
			Locations[ideck].reload.l7.go = "Companion_Cabin_" + companion_no;
		Locations[ideck].reload.l7.emerge = "reload1";
	}

	if (deck != "ShipDeck6")
	{
		Locations[iseadogs].reload.l2.go = deck;
		Locations[iseadogs].reload.l2.emerge = "reload2";
		Locations[ideck].reload.l2.go = "Seadogs";
		Locations[ideck].reload.l2.emerge = "reload2";
	}

	if (ncdecks > 0)
	{
		tmpdeck = "Deck1";
		itmpdeck = icdeck1;
	}
	else
	{
		tmpdeck = "Hold1";
		itmpdeck = ihold1;
	}
	if (deck != "ShipDeck3")
	{
		Locations[itmpdeck].reload.l1.go = deck;
		Locations[itmpdeck].reload.l1.emerge = "reload3";
		Locations[ideck].reload.l3.go = tmpdeck;
		Locations[ideck].reload.l3.emerge = "reload1";
	}
	if (deck == "ShipDeck6")
	{
		Locations[ideck].reload.l8.go = tmpdeck;
		Locations[ideck].reload.l8.emerge = "reload1";
	}

	if (ndecks == 0)
	{
		Locations[ideck].reload.l1.go = "";
		Locations[ideck].reload.l1.emerge = "";
		Locations[ideck].reload.l2.go = "";
		Locations[ideck].reload.l2.emerge = "";
		Locations[ideck].reload.l3.go = "";
		Locations[ideck].reload.l3.emerge = "";
		if (deck == "ShipDeck2")
		{
			Locations[ideck].reload.l7.go = "";
			Locations[ideck].reload.l7.emerge = "";
		}
	}

	Locations[ideck].reload.l4.go = "";
	Locations[ideck].reload.l4.emerge = "";
	Locations[ideck].reload.l5.go = "";
	Locations[ideck].reload.l5.emerge = "";

	aref LocatorRef;
	if (LandLocationIdx == -1)
	{
		LocatorRef = GetReloadMapRef(arIslandReload, "name", sIslandLocator);
	}
	else
	{
		int fslocidx = FindLocation(mc.location.from_sea);
		if (fslocidx < 0) return;
		string island = Locations[fslocidx].island;
		if (island == "") return;
		ref LocationRef = LocationFromID(mc.location.from_sea);
		aref arReload;
		makearef(arReload, LocationRef.reload);
		LocatorRef = GetReloadMapRef(arReload, "go", island);
		LocationRef = GetIslandByID(island);
		if (!CheckAttribute(LocationRef, "reload")) return;
		makearef(arReload, LocationRef.reload);
		LocatorRef = GetReloadMapRef(arReload, "go", mc.location.from_sea);
	}
	if (bCanEnterToLand)
	{
		Locations[ideck].reload.l4.go = LocatorRef.go;
		Locations[ideck].reload.l4.emerge = LocatorRef.emerge;
		Locations[ideck].reload.l5.go = LocatorRef.go;
		Locations[ideck].reload.l5.emerge = LocatorRef.emerge;
	}

	Locations[ideck].reload.l6.disabled = (iShipCaptain != GetMainCharacterIndex());
}

// Return to own deck (sea)
void FCoHS_Boarding_ReturnToOwnDeck()
{
	// Handlers for reload fader events
	SetEventHandler("FaderEvent_StartFade", "FCoHS_Boarding_ReturnStartFade", 0);
	SetEventHandler("FaderEvent_EndFade", "FCoHS_Boarding_ReturnEndFade", 0);

	// Create reload fader
	CreateEntity(&boarding_fader, "fader");
	// @TODO (EL#3#): Boarding: Implement loading screen
	//SendMessage(&boarding_fader, "ls", FADER_PICTURE, FindReloadPicture("sea.tga"));

	// Fade out
	SendMessage(&boarding_fader, "lfl", FADER_OUT, RELOAD_TIME_FADE_OUT, false);
	SendMessage(&boarding_fader, "l", FADER_STARTFRAME);

	// Reset sounds
	PauseAllSounds();
	//ResetSoundScheme();
	ResetSound();

	// Used by DirectSail
	if(CheckAttribute(GetMainCharacter(),"IsOnDeck")) { DeleteAttribute(GetMainCharacter(),"IsOnDeck"); }
}

// Reload to sea - start fade
void FCoHS_Boarding_ReturnStartFade()
{
	// Unload boarding location
	if(iFCoHS_BoardingLocation >= 0)
	{
		UnloadLocation(&Locations[iFCoHS_BoardingLocation]);
	}
	DeleteAttribute(GetMainCharacter(),"reloadStatus");

	// Fader event has been processed, delete handler
	DelEventHandler("FaderEvent_StartFade", "FCoHS_Boarding_ReturnStartFade");
}

// Reload to sea - end fade
void FCoHS_Boarding_ReturnEndFade()
{
	ref MainCharacter = GetMainCharacter();

	// Reload progress start
	ReloadProgressStart();

	// Fader event has been processed, delete handler
	DelEventHandler("FaderEvent_EndFade", "FCoHS_Boarding_ReturnEndFade");

	// Fade in
	SendMessage(&boarding_fader, "lfl", FADER_IN, RELOAD_TIME_FADE_IN, true);

	iFCoHS_BoardingLocation = -1;

	Log_SetActiveAction("Nothing");
	EndBattleLandInterface();

	// Get original location of main character
	MainCharacter.location = boarding_adr[0].location;
	MainCharacter.location.group = boarding_adr[0].group;
	MainCharacter.location.locator = boarding_adr[0].locator;

    // Load all models back to sea
	aref arModel;
	if (FindClass(&arModel, "modelr"))
	{
		SendMessage(arModel, "l", MSG_MODEL_RESTORE);
		while (FindClassNext(&arModel))
		{
			SendMessage(arModel, "l", MSG_MODEL_RESTORE);
		}
	}

	// Layers
	LayerFreeze("execute",true);
	LayerFreeze("realize",true);
	LayerFreeze("sea_reflection", false);
	LayerFreeze(SEA_EXECUTE,false);
	LayerFreeze(SEA_REALIZE,false);
	MoveWeatherToLayers(SEA_EXECUTE, SEA_REALIZE);
	MoveSeaToLayers(SEA_EXECUTE, SEA_REALIZE);

	// Restore old max sea height
	Sea.MaxSeaHeight = fOldMaxSeaHeight;

	// Global variables used outside of FCoHS >>
	bSeaReloadStarted = false;
	bDeckEnter = false;
	bAbordageStarted = false;
	Sea.AbordageMode = false;
	chrWaitReloadLocator = "";

	// @CHECK (EL#2#): Boarding: Are these globals needed?
	bCrewStarted = false;
	bDeckStarted = false;
	bCabinStarted = false;
	// << Global variables used outside of FCoHS

	// Switch interface
	InitBattleInterface();
	StartBattleInterface();
	RefreshBattleInterface(true);

	// Reload progress end
	SetSchemeForSea();
	PauseParticles(false);
	Whr_UpdateWeather(false);
	ReloadProgressEnd();
}

void FCoHS_Boarding_PlaceCaptain()
{
	ref rCaptain = GetCharacter(iFCoHS_BoardingCaptain);
	ref rMainCharacter = GetMainCharacter();

	// Place captain
	PlaceCharacter(rCaptain, "rld");

	// Make captain an actor
	LAi_SetActorType(rCaptain);

	// Engage main character
	LAi_ActorTurnToCharacter(rCaptain, rMainCharacter);
	LAi_ActorFollow(rCaptain, rMainCharacter, "First Contact", 3.0);
}

// ---------------------------
// Utility/secondary functions
// ---------------------------

// Calculate "Comply to hail" chance
int FCoHS_Util_CalculateComplyToHailChance(ref rShipCharacter) // PB: Using a 0-100% chance scale sounds like int to me
{
	ref rMainCharacter = GetMainCharacter();
	// @CHECK (EL#1#): What to do if the ship doesn't have a FantomType
	if (!CheckAttribute(rShipCharacter, "FantomType")) return;

	float fBaseChance = sqr(stf(rMainCharacter.Reputation) / stf(REPUTATION_MAX));

	// @TODO (EL#1#): Implement further "Willingness to Comply" modifiers
	switch (rShipCharacter.FantomType)
	{
		case "trade":

			break;
		case "war":

			break;
		case "pirate":

			break;
	}
	return fBaseChance; // PB: Have to return something
}

// Update the tradebook
void FCoHS_Util_UpdateTradebookAway(int iStore)
{
	// @TODO (EL#3#): Find way to work with Storeref?
	ref refStore = &Stores[iStore];

	refStore.STORE_CURDATE = GetStringDate(GetDataYear(), GetDataMonth(), GetDataDay()) + " " + GetStringTime(GetTime());
	for (int g = 0; g < GOODS_QUANTITY; g++)
	{
		for (int i = 0; i < 7; i++)
		{
			string impAttr1, expAttr1, conAttr1, impAttr2, expAttr2, conAttr2, tradeAttr;
			int sellPrice, buyPrice;
			impAttr1 = "importsell" + i;
			expAttr1 = "exportsell" + i;
			conAttr1 = "contrasell" + i;
			impAttr2 = "importbuy" + i;
			expAttr2 = "exportbuy" + i;
			conAttr2 = "contrabuy" + i;
			tradeAttr = "id" + (i + 1);
			aref curIsland;
			makearef(curIsland, Islands[FindIsland(Stores[iStore].island)]);

			// LDH moved price calculations inside if statements for speed 04Mar09
			if (CheckAttribute(curIsland, "Trade.Import.id" + (i + 1)))
			{
				if (curIsland.Trade.Import.(tradeAttr) == g)
				{
					sellPrice = GetStoreGoodsPrice(refStore, FindGood(Goods[g].Name), PRICE_TYPE_SELL, GetMainCharacter(), 0);
					buyPrice  = GetStoreGoodsPrice(refStore, FindGood(Goods[g].Name), PRICE_TYPE_BUY, GetMainCharacter(), 0);
					refStore.(impAttr1) = sellPrice;
					refStore.(impAttr2) = buyPrice;
				}
			}
			if (CheckAttribute(curIsland, "Trade.Export.id" + (i + 1)))
			{
				if (curIsland.Trade.Export.(tradeAttr) == g)
				{
					sellPrice = GetStoreGoodsPrice(refStore, FindGood(Goods[g].Name), PRICE_TYPE_SELL, GetMainCharacter(), 0);
					buyPrice  = GetStoreGoodsPrice(refStore, FindGood(Goods[g].Name), PRICE_TYPE_BUY, GetMainCharacter(), 0);
					refStore.(expAttr1) = sellPrice;
					refStore.(expAttr2) = buyPrice;
				}
			}
			if (CheckAttribute(curIsland, "Trade.Contraband.id" + (i + 1)))
			{
				if (curIsland.Trade.Contraband.(tradeAttr) == g)
				{
					sellPrice = GetStoreGoodsPrice(refStore, FindGood(Goods[g].Name), PRICE_TYPE_SELL, GetMainCharacter(), 0);
					buyPrice  = GetStoreGoodsPrice(refStore, FindGood(Goods[g].Name), PRICE_TYPE_BUY, GetMainCharacter(), 0);
					refStore.(conAttr1) = sellPrice;
					refStore.(conAttr2) = buyPrice;
				}
			}
		}
	}
}

// Check ships for contact and hailing possibility
bool FCoHS_Util_CheckShips(ref retDistance, ref retCharIdx, ref retHailCanBe)
{
	ref rShipCharacter, rClosestShipCharacter;
	aref aShips, aShip;
	float fClosestDistance;
	int rClosestShipIdx;

	// @CHECK (EL#3#): Maybe use the FindClosest..() function or get the NearShips[] instead of looping
	//      	over "rChar.SeaAI.Update.Ships"? This way here only works for the MainChar. However, I
	//      	guess the other methods take longer.

	// Get ships from MainChar attributes
	ref rMainCharacter = GetMainCharacter();
	makearef(aShips, rMainCharacter.SeaAI.Update.Ships);
	int iShipsNum = GetAttributesNum(aShips);

	// Check ships
	bool bFoundShip = false;
	for (int i = 0; i < iShipsNum; i++)
	{
		aShip = GetAttributeN(aShips, i);
		rShipCharacter = GetCharacter(sti(aShip.idx));
		float fDistance = stf(aShip.Distance);
		int iRelation = sti(aShip.Relation);

		// Is this one closer than the last one we found (or haven't we found one at all yet)?
		if (fDistance < fClosestDistance || bFoundShip == false)
		{
			// Checks for hailing and contact
			if (LAi_IsDead(rShipCharacter)) continue;   // Is dead
			if (iRelation == RELATION_ENEMY) continue;  // Is hostile
			if (IsCompanion(rShipCharacter)) continue;  // Is companion

			// Found a ship valid for hailing
			if (fDistance < fFCoHS_HailCanBeDistance) { retHailCanBe = true; }

			// Checks for contact
			if (!CheckAttribute(rShipCharacter, "FCoHS.CompliedToHail")) continue; 					// Complied to Hail?
			if (rShipCharacter.FCoHS.CompliedToHail != true) continue;
			if (abs(stf(aShip.RelativeSpeed)) > fFCoHS_MaxContactSpeed) continue; 					// Speed
			if (abs(stf(aShip.d_ay)) < abs(sin(Degree2Radian(fFCoHS_MaxContactAngle)))) continue; 	// Angle
			float fShipBoxSizeX = stf(rShipCharacter.Ship.BoxSize.x) / 2.0;
			float fCharBoxSizeX = stf(rMainCharacter.Ship.BoxSize.x) / 2.0;
			if (fDistance - fShipBoxSizeX - fCharBoxSizeX > fFCoHS_ContactCanBeDistance) continue; 	// Distance

			// Found a ship valid for contact
			fClosestDistance = fDistance;
			rClosestShipIdx = sti(aShip.idx);
			bFoundShip = true;
		}
	}

	// Set return parameters for closest contact
	if (bFoundShip == true)
	{
		retDistance = fClosestDistance;
		retCharIdx = rClosestShipIdx;
		return true;
	}
	else
	{
		return false;
	}
}
