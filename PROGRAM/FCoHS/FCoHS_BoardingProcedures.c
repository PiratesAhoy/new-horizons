// -----------------------
// Start friendly boarding
// -----------------------
void FCoHS_Boarding_Start(int iBoardingTarget)
{
	// Global variables use outside of FCoHS >>
	bSeaReloadStarted = true;
	Sea.AbordageMode = true;
	bDeckEnter = true;
	iShipCaptain = iBoardingTarget;
	bAbordageStarted = true;

	// @CHECK (EL#2#): Boarding: Are the globals needed?
	bCrewStarted = false;
	bDeckStarted = false;
	bCabinStarted = false;
	bToDeckFromLand = false;

	rMainCharacter.IsOnDeck = true;		// Used by DirectSail
	// << Global variables use outside of FCoHS

	ref rMainCharacter = GetMainCharacter();
	ref rShipCaptain = GetCharacter(iBoardingTarget);

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
	//SendMessage(&reload_fader, "ls", FADER_PICTURE0, FindReloadPicture(Locations[FindLocation(DeckID)].image));

	// Fade out
	SendMessage(&reload_fader, "lfl", FADER_OUT, 1.0, false);
	SendMessage(&reload_fader, "l", FADER_STARTFRAME);

	// Reset sounds
	PauseAllSounds();
	ResetSoundScheme();
}

// ---------------------
// Reload fading started
// ---------------------
void FCoHS_Boarding_StartFade()
{
	// Get event data from fader event
	int a = GetEventData();
	aref reload_fader = GetEventData();

	// Freeze layers
	LayerFreeze(SEA_EXECUTE, true);
	LayerFreeze(SEA_REALIZE, true);
	LayerFreeze(SEA_REFLECTION, true);
	LayerFreeze(EXECUTE, false);
	LayerFreeze(REALIZE, false);
	MoveWeatherToLayers(EXECUTE, REALIZE);
	MoveSeaToLayers(EXECUTE, REALIZE);

	// Delete all cannonballs (although we shouldn't be in combat)
	SendMessage(&AIBalls, "l", MSG_MODEL_RELEASE);

	// Set maxinum sea height for ship deck
	if (CheckAttribute(Sea, "MaxSeaHeight"))
	{
		fOldMaxSeaHeight = stf(Sea.MaxSeaHeight);
		Sea.MaxSeaHeight = 1.2;
	}

	// Fader event has been processed, delete handler
	DelEventHandler("FaderEvent_StartFade", "FCoHS_BoardingStartFade");
}

// -------------------
// Reload fading ended
// -------------------
void FCoHS_Boarding_EndFade()
{
	// Get event data from fader event
	int a = GetEventData();
	aref reload_fader = GetEventData();

	// Delete current cannonballs (although we shouldn't be in combat)
	AIBalls.Clear = "";

	ReleaseShipModels();

	// Pause particles
	PauseParticles(true);

	// Load the deck
	FCoHS_Boarding_PrepareLoadDeck();

	// Fader event has been processed, delete handler
	DelEventHandler("FaderEvent_EndFade", "FCoHS_BoardingEndFade");

	// Fade in
	SendMessage(&reload_fader, "lfl", FADER_IN, RELOAD_TIME_FADE_IN, true);
}

// ----------
// Start deck
// ----------
void FCoHS_Boarding_PrepareLoadDeck()
{
	// Reset sounds
	ResetSoundScheme();
	PauseAllSounds();

	// Switch interface
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
	FCoHS_Boarding_LoadDeck(sFCoHS_DeckName);

	// Create boarding fader
	CreateEntity(&boarding_fader, "fader");

	// Fade in
	SendMessage(&boarding_fader, "lfl", FADER_IN, RELOAD_TIME_FADE_IN, true);
}

// ---------
// Load deck
// ---------
void FCoHS_Boarding_LoadDeck(string sDeckName)
{
	// Reload progress start
	ReloadProgressStart();
	SetDeckPortBackground();

	int iLocID = FindLocation(sDeckName);
	ref rMainCharacter = GetMainCharacter();

	// Get new location and locator for main character
	if (iLocID >= 0)
	{
		if (!bCanEnterToLand && HasSubStr(DeckID, "ShipDeck"))
		{
			locations[iLocID].coxswain = true;
		}

		// New location for main character
		rMainCharacter.location = sDeckName;

		// New locator for main character
//		if (iFCoHS_FromDeckIdx == -1)
//		{
//			if (!bEmergeOnStartloc)
//			{
//				rMainCharacter.location.group = "reload";
//				rMainCharacter.location.locator = GetRandSubString("boatr,boatl");
//			}
//			else
//			{
				rMainCharacter.location.group = "rld";
				rMainCharacter.location.locator = "startloc";
//			}
//		}
//		else
//		{
//			rMainCharacter.location.group = "reload";
//			rMainCharacter.location.locator = GetReloadMapAttrib(iFCoHS_FromDeckIdx, current_locator_name, "emerge");
//			if (rMainCharacter.location.locator == "")
//			{
//				rMainCharacter.location.group = "rld";
//				rMainCharacter.location.locator = "startloc";
//			}
//		}

//		bEmergeOnStartloc = true;
		chrWaitReloadIsNoLink = false;
//		iFCoHS_FromDeckIdx = -1;
		current_locator_name = "";

		//Loadcharacter into location
		boarding_location = iLocID;
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

// -------------------------
// Setup reload map for deck
// -------------------------
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
