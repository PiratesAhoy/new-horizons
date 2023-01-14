bool	bAbordageStarted = false;
bool	bAbordageFortCanBe;
bool	bAbordageTownCanBe; // KK
bool	bAbordagePlaceShipNear = false;
bool	bMCAbordageInitiator = true;
string	sAbordageLocator;
int		iAbordageFortEnemyCharacter; /*, iAbordageOurCharacter*/
int		iAbordageTownEnemyCharacter; // KK
int		iAbordageCharacter;
int		iAbordageMode;
float	fOldMaxSeaHeight;

void DeleteAbordageEnvironment()
{
	// KK DelEventHandler(ABORDAGE_CAN_BE,"Abordage_CanBe");
}

void CreateAbordageEnvironment()
{
	bAbordageStarted = false;
	// KK SetEventHandler(ABORDAGE_CAN_BE,"Abordage_CanBe",0);
	bAbordageFortCanBe = false;
	bAbordageTownCanBe = false; // KK
}

/* KK -->void Abordage_CanBe()
{
	//bAbordageCanBe = GetEventData();
	//iAbordageOurCharacter = GetEventData();
	//iAbordageEnemyCharacter = GetEventData();
} <-- KK */

void Abordage_ReloadStartFade()
{
	ref lcn;
	int a = GetEventData();
	reload_fader = GetEventData();
	LayerFreeze(SEA_EXECUTE,true);
	LayerFreeze(SEA_REALIZE,true);
	LayerFreeze(SEA_REFLECTION,true);
	LayerFreeze(EXECUTE,false);
	LayerFreeze(REALIZE,false);

	MoveWeatherToLayers(EXECUTE, REALIZE);
	MoveSeaToLayers(EXECUTE, REALIZE);

	SendMessage(&AIBalls, "l", MSG_MODEL_RELEASE);

	DelEventHandler("FaderEvent_StartFade", "Abordage_ReloadStartFade");

	fOldMaxSeaHeight = stf(Sea.MaxSeaHeight);
	Sea.MaxSeaHeight = 1.15;						// set maxinum sea height for ship abordage
// KK -->
	a = FindLocation(DeckID);
	if (a >= 0) {
		makeref(lcn, Locations[a]);
		if (CheckAttribute(lcn, "MaxSeaHeight"))	Sea.MaxSeaHeight = stf(lcn.MaxSeaHeight); // screwface : limit wave height
	}
// <-- KK
}

void Go2LocationAfterAbordage()
{
	Sea.MaxSeaHeight = fOldMaxSeaHeight;		// restore old MaxSeaHeight
	// KK bAbordageStarted = false;
	bSeaReloadStarted = false;
	Sea.AbordageMode = false;

	PauseParticles(false);
	LayerFreeze(SEA_REFLECTION, false);

	Sea.MaxSeaHeight = fOldMaxSeaHeight;		// restore old MaxSeaHeight
}

void Return2SeaAfterAbordage()
{
	// load all models back to sea
	aref arModel;
	if (FindEntity(&arModel, "modelr"))
	{
		SendMessage(arModel, "l", MSG_MODEL_RESTORE);
		while (FindEntityNext(&arModel))
		{ 
			//Trace("XYZ");
			SendMessage(arModel, "l", MSG_MODEL_RESTORE); 
		}
	}

	LayerFreeze(EXECUTE,true);
	LayerFreeze(REALIZE,true);

	LayerFreeze(SEA_REFLECTION, false);
	LayerFreeze(SEA_EXECUTE,false);
	LayerFreeze(SEA_REALIZE,false);

	MoveWeatherToLayers(SEA_EXECUTE, SEA_REALIZE);
	MoveSeaToLayers(SEA_EXECUTE, SEA_REALIZE);

	Sea.MaxSeaHeight = fOldMaxSeaHeight;		// restore old MaxSeaHeight
	bAbordageStarted = false;
	Sea.AbordageMode = false;

// LDH -->
	ref mchr = GetMainCharacter();

	// LDH - stop boarding sounds // TIH --> helps reset music schemes in battle Aug24'06
	PauseAllSounds();
	// Baste -->
	//ResetSoundScheme();
	//oldSeaAlarmed = false;
	//mchr.Ship.POS.Mode = -1; // -1 so that its refreshed next frame
	// Baste <--
	// TIH <--
	if (CheckAttribute(mchr,"abordagesound"))
	{
		StopSound(sti(mchr.abordagesound), 500);
		DeleteAttribute(mchr, "abordagesound");
	}

	//HKE -->
	if (CheckAttribute(mchr,"PlayedAbordageSound"))
	{
		DeleteAttribute(mchr,"PlayedAbordageSound");
	}
	//<-- HKE

/*
	// LDH - Reset max HP for main character and all boarding officers after boarding changes
	// This is no longer needed as we don't alter character HP during boarding
	int idx;
	int i;
//	Trace("Max HP before reset = " + mchr.chr_ai.hp_max);
	ResetMaxHP(mchr);
//	LAi_SetCurHPMax(mchr);		// set current HP to max, do this for officers as well
	for (i = 1; i < 4; i++)
	{
		idx = GetOfficersIndex(mchr, i);
		if (idx >= 0)
		{
			ResetMaxHP(&Characters[idx]);
		}
	}
//	Trace("Max HP after reset = " + mchr.chr_ai.hp_max);
*/

	//  LDH - Restore location from before we started boarding // KK -->
	/*mchr.location = mchr.preboardloc;
	mchr.location.group = mchr.preboardloc.group;
	mchr.location.locator = mchr.preboardloc.locator;
	mchr.location.from_sea = mchr.preboardloc.from_sea;
	DeleteAttribute(mchr, "preboardloc");*/ // <-- KK

	//	Trace("Dumping main character attributes"); DumpAttributes(mchr);
// LDH <--
	InitBattleInterface();
	StartBattleInterface();
	RefreshBattleInterface(true);

	SetSchemeForSea();
	SetMusic("music_sea_battle"); // Baste

	PauseParticles(false);
	Whr_UpdateWeather(false);	// LDH 24Mar09

	bSeaReloadStarted = false;
}

void Abordage_ReloadEndFade()
{
	float fHP, fHP1, fHP2;

	// Delete current cannonballs
	AIBalls.Clear = "";

	// unload all models
	aref arModel;
	if (FindEntity(&arModel, "modelr"))
	{
		SendMessage(arModel, "l", MSG_MODEL_RELEASE);
		while (FindEntityNext(&arModel)) { SendMessage(arModel, "l", MSG_MODEL_RELEASE); }
	}

	if (bAbordagePlaceShipNear)
	{
		SendMessage(AISea, "laff", AI_MESSAGE_SAIL_2_CHARACTER, &Characters[iAbordageCharacter], 40.0 + frnd() * 60.0, frnd() * PIm2);
	}

	PauseParticles(true);

	// start abordage location
	int a = GetEventData();
	reload_fader = GetEventData();
	ref pc = GetMainCharacter(); // KK
	switch (iAbordageMode)
	{
		case FORT_ABORDAGE:
			DeleteSeaEnvironment();
			pc.befboardcrew = pc.ship.crew.quantity; // NK 04-09-22
			LAi_StartBoarding(BRDLT_FORT, &Characters[iAbordageCharacter], true);
		break;
		case SHIP_ABORDAGE:
			// calc & apply abordage damage for ships
				fHP1 = stf(Characters[iAbordageCharacter].Ship.HP);
				fHP2 = stf(Characters[GetMainCharacterIndex()].Ship.HP);
				fHP = 0.1 + frnd() * 0.2;
				if (fHP1 > fHP2) { fHP = fHP * fHP2; }
				if (fHP1 < fHP2) { fHP = fHP * fHP1; }

				bSeaReloadStarted = false;
				Ship_ApplyHullHitpoints(&Characters[iAbordageCharacter], fHP * (1.05 - stf(Characters[iAbordageCharacter].TmpSkill.Sneak)), KILL_BY_TOUCH, -1);
				Ship_ApplyHullHitpoints(&Characters[GetMainCharacterIndex()], fHP * (1.05 - stf(Characters[GetMainCharacterIndex()].TmpSkill.Sneak)), KILL_BY_TOUCH, -1);
				bSeaReloadStarted = true;

			// load boarding
				LAi_StartBoarding(BRDLT_SHIP, &Characters[iAbordageCharacter], bMCAbordageInitiator);
		break;
// KK -->
		case TOWN_ABORDAGE:
			DeleteSeaEnvironment();
			LAi_StartBoarding(BRDLT_TOWN, &Characters[iAbordageCharacter], true);
		break;
// <-- KK
	}
	DelEventHandler("FaderEvent_EndFade", "Abordage_ReloadEndFade");
	SendMessage(&reload_fader, "lfl", FADER_IN, RELOAD_TIME_FADE_IN, true);
}

void Sea_AbordageLoad(int _iAbordageMode, bool _bMCAbordageInitiator)
{
	// KK int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	if (bSeaActive == false) { return; }

	if (_iAbordageMode == FORT_ABORDAGE && !bAbordageFortCanBe) { return; }
	if (_iAbordageMode == SHIP_ABORDAGE && !bAbordageShipCanBe) { return; }
	if (_iAbordageMode == TOWN_ABORDAGE && !bAbordageTownCanBe) { return; } // KK

	int _iAbordageCharacter = iAbordageShipEnemyCharacter;
	if (_iAbordageMode == FORT_ABORDAGE) { _iAbordageCharacter = iAbordageFortEnemyCharacter; }
	if (_iAbordageMode == TOWN_ABORDAGE) { _iAbordageCharacter = iAbordageTownEnemyCharacter; } // KK

	// 1.03 -->
//	if (!CheckQuestAttribute("abordage", _iAbordageCharacter))
//	{
		Sea_AbordageStartNow(_iAbordageMode, _iAbordageCharacter, false, _bMCAbordageInitiator);
//	}
//	else
//	{
//		Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Already boarded this ship!"));
//		DoQuestCheckDelay("reset_abordage", 1.0);
//	}
//	characters[0].quest.reset_abordage.win_condition.l1 = "MapEnter";
//	characters[0].quest.reset_abordage.win_condition = "reset_abordage";
	// <--
	// KK LanguageCloseFile(tmpLangFileID);
}

void Sea_AbordageStartNow(int _iAbordageMode, int _iAbordageCharacter, bool _bPlaceOurShipNear, bool _bMCAbordageInitiator)
{
	// TIH --> help prevent reboarding the same ships through instant boarding Aug24'06
//	if (CheckQuestAttribute("abordage", _iAbordageCharacter))
//	{
//		int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
//		Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Already boarded this ship!"));
//		DoQuestCheckDelay("reset_abordage", 1.0);
//		LanguageCloseFile(tmpLangFileID);
//		return;
//	}
	// TIH <--
	bSeaReloadStarted = true;

	iAbordageCharacter = _iAbordageCharacter;
	iAbordageMode = _iAbordageMode;
	bAbordagePlaceShipNear = _bPlaceOurShipNear;
	bMCAbordageInitiator = _bMCAbordageInitiator;

	// KK object reload_fader;
	CreateEntity(&reload_fader, "fader");
	SetEventHandler("FaderEvent_StartFade", "Abordage_ReloadStartFade", 0);
	SetEventHandler("FaderEvent_EndFade", "Abordage_ReloadEndFade", 0);

// KK -->
	ref pc = GetMainCharacter();
	int boarding_deck = -1;
	if (bMCAbordageInitiator)
		boarding_deck = FindLocation("BOARDING_" + GetCharacterShipQDeck(GetCharacter(iAbordageCharacter)));
	else
		boarding_deck = FindLocation("BOARDING_" + GetCharacterShipQDeck(pc));
	if (_iAbordageMode == FORT_ABORDAGE) {
		boarding_deck = FindLocation("BOARDING_Fort");
		Locations[boarding_deck].image = "Fort_Inside_Fort_1";
	}
	if (_iAbordageMode == TOWN_ABORDAGE) boarding_deck = FindLocation(Towns[GetTownIndex(characters[_iAbordageCharacter].town)].boarding.l1);
	if (boarding_deck < 0) boarding_deck = FindLocation("BOARDING_ShipDeck1");
	DeckID = Locations[boarding_deck].id;
	if (CheckAttribute(Locations[boarding_deck], "image"))
		SetReloadImage(&reload_fader, Locations[boarding_deck].image);
	else
		SetReloadImage(&reload_fader, "Boarding.tga");
// <-- KK
	SendMessage(&reload_fader, "lfl", FADER_OUT, 1.0, false);
	SendMessage(&reload_fader, "l", FADER_STARTFRAME);

	SetMusic("music_abordage"); // Baste
	PauseAllSounds();
	ResetSoundScheme();

	// NK -->
	if(ENABLE_EXTRA_SOUNDS == 1) {			// added by KAM after build 11
// KK -->
		if (GetGroupIDFromCharacter(&characters[iAbordageCharacter]) != SURR_GROUP) {
			if (_iAbordageMode == SHIP_ABORDAGE) {
				PlaySound("#boarding");
			} else {
				if (FindFile("RESOURCE\Sounds\INTERFACE\"+LanguageGetLanguage(), "*.wav", "_GTBoard3.wav") != "")
					PlaySound("INTERFACE\"+LanguageGetLanguage()+"\_GTBoard3.wav");
				else
					PlaySound("INTERFACE\_GTBoard3.wav");
			}
		} else {
			if (FindFile("RESOURCE\Sounds\INTERFACE\"+LanguageGetLanguage(), "*.wav", "_GTBoard2.wav") != "") {
				PlaySound("INTERFACE\"+LanguageGetLanguage()+"\_GTBoard2.wav");
			} else {
				if (FindFile("RESOURCE\Sounds\INTERFACE\"+LanguageGetLanguage(), "*.wav", "_GTBoard3.wav") != "")
					PlaySound("INTERFACE\"+LanguageGetLanguage()+"\_GTBoard3.wav");
				else
					PlaySound("INTERFACE\_GTBoard3.wav");
			}
		}
		else
		{
			if(FindFile("RESOURCE\Sounds\INTERFACE\"+LanguageGetLanguage(), "*.wav", "_GTBoard2.wav")!="") PlaySound("INTERFACE\"+LanguageGetLanguage()+"\_GTBoard2.wav");
			else PlaySound("INTERFACE\_GTBoard2.wav");
		}
// <-- KK
	}						// added by KAM after build 11
	pc.soundplaying = true;
	// NK <--
	// Morgan/NK --> // KK -->
	if (_iAbordageMode == SHIP_ABORDAGE) {
		if (GetOfficersPerkUsing(GetMainCharacter(),"MusketsShoot")) pc.musket = true;
		if (GetOfficersPerkUsing(GetCharacter(iAbordageCharacter), "MusketsShoot")) characters[iAbordageCharacter].musket = true;
	}
	// Morgan/NK <-- // <-- KK
	Event(ABORDAGE_START_EVENT, "ll", GetMainCharacterIndex(), iAbordageCharacter);
	bAbordageStarted = true;
	Sea.AbordageMode = true;
//	Characters[0].quest.abordage = iAbordageShipEnemyCharacter;
//	Characters[0].quest.reset_abordage.win_condition.l1 = "MapEnter"; // TIH better safe than sorry Aug24'06
//	Characters[0].quest.reset_abordage.win_condition = "reset_abordage"; // TIH better safe than sorry Aug24'06
	pc.directsail.count = 0.0;		// LDH reset encounter frequency count when boarding - 13Feb09
}

