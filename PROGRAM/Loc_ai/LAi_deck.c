//===================================| Idea of AlexusB. Totally rewritten by MAXIMUS and KK |===================================//

bool	bDeckStarted = false;
bool	bCabinStarted = false;
bool	bCrewStarted = false;
// KK -->
int iShipCaptain = -1;
bool bDeckEnter = false;
bool bToDeckFromLand = false;
bool bEmergeOnStartloc = false;
string DeckID = "";
int FromDeckIdx = -1;
int LandLocationIdx = -1;
string LandLocator = "";
string current_locator_name = "";
float Land_posx[4];
float Land_posy[4];
float Land_posz[4];
float Land_angle[4];
// <-- KK

bool ownDeckStarted()//MAXIMUS
{
	if(bDeckStarted || bCabinStarted || bCrewStarted || bMutinyDeckStarted) return true;
// KK -->
	ref mchr = GetMainCharacter();
	if (CheckAttribute(mchr, "location")) {
		if (mchr.location == "Tutorial_Deck") return true;
		if (HasSubStr(mchr.location, "Companion_Cabin_")) return true;
	}
// <-- KK
	return false;
}

void ClearDeck()
{
	bDeckEnter = false;
	bDeckStarted = false;
	bCabinStarted = false;
	bCrewStarted = false;
	DeleteAttribute(GetMainCharacter(),"IsOnDeck");
}

void Deck_ReloadStartFade()
{
	int a = GetEventData();
	boarding_fader = GetEventData();
	LayerFreeze(SEA_EXECUTE,true);
	LayerFreeze(SEA_REALIZE,true);
	LayerFreeze("sea_reflection",true);
	LayerFreeze("execute",false);
	LayerFreeze("realize",false);

	MoveWeatherToLayers("execute", "realize");
	MoveSeaToLayers("execute", "realize");

	SendMessage(&AIBalls, "l", MSG_MODEL_RELEASE);

	DelEventHandler("FaderEvent_StartFade", "Deck_ReloadStartFade");

	if (CheckAttribute(Sea, "MaxSeaHeight")) { // KK
		fOldMaxSeaHeight = stf(Sea.MaxSeaHeight);
		Sea.MaxSeaHeight = 1.15;						// set maxinum sea height for ship Deck
		ref lcn = &Locations[FindLocation(DeckID)];
		if(CheckAttribute(lcn,"MaxSeaHeight")) Sea.MaxSeaHeight = stf(lcn.MaxSeaHeight); // screwface : limit wave height
	}
}

void Return2SeaAfterDeck()
{
// KK -->
	if (bToDeckFromLand) {
		SetEventHandler("FaderEvent_StartFade", "DeckToSea_ReloadStartFadeAfter", 0);
		SetEventHandler("FaderEvent_EndFade", "DeckToSea_ReloadEndFadeAfter", 0);
	} else {
// <-- KK
		//Установить хендлеры для обработки
		SetEventHandler("FaderEvent_StartFade", "Deck_ReloadStartFadeAfter", 0);
		SetEventHandler("FaderEvent_EndFade", "Deck_ReloadEndFadeAfter", 0);
	}
	//Создаём фейдер и запускаем
	CreateEntity(&boarding_fader, "fader");
	SendMessage(&boarding_fader, "ls", FADER_PICTURE, FindReloadPicture("sea.tga")); // KK

	float fadeOutTime = RELOAD_TIME_FADE_OUT;

	SendMessage(&boarding_fader, "lfl", FADER_OUT, fadeOutTime, false);
	SendMessage(&boarding_fader, "l", FADER_STARTFRAME);
	if(CheckAttribute(GetMainCharacter(),"IsOnDeck")) { DeleteAttribute(GetMainCharacter(),"IsOnDeck"); }//MAXIMUS
}

void Deck_ReloadEndFade()
{
	// Delete current cannonballs
	AIBalls.Clear = "";

	// unload all models
	aref arModel;
	if (FindClass(&arModel, "modelr"))
	{
		SendMessage(arModel, "l", MSG_MODEL_RELEASE);
		while (FindClassNext(&arModel)) { SendMessage(arModel, "l", MSG_MODEL_RELEASE); }
	}

	PauseParticles(true);

	// start Deck location
	int a = GetEventData();
	boarding_fader = GetEventData();

	Deck_Start();

	DelEventHandler("FaderEvent_EndFade", "Deck_ReloadEndFade");
	SendMessage(&boarding_fader, "lfl", FADER_IN, RELOAD_TIME_FADE_IN, true);
}

void Sea_DeckStartNow(int chridx, string deckname)
{
	bSeaReloadStarted = true;
	bToDeckFromLand = false; // KK

	// KK object boarding_fader;
	CreateEntity(&boarding_fader, "fader");
	SetEventHandler("FaderEvent_StartFade", "Deck_ReloadStartFade", 0);
	SetEventHandler("FaderEvent_EndFade", "Deck_ReloadEndFade", 0);
	SetEventHandler("Control Activation", "TeleportToDeck", 1); // KK

	bDeckEnter = true; // KK

	if (chridx < 0) chridx = GetMainCharacterIndex(); // KK
	iShipCaptain = chridx; // KK
	DeckID = deckname; // KK

	// SCREWFACE : loading screen is different for different deck model
	if (CheckAttribute(&Locations[FindLocation(DeckID)], "image")) SendMessage(&boarding_fader, "ls", FADER_PICTURE, FindReloadPicture(Locations[FindLocation(DeckID)].image)); // KK
	// SCREWFACE : END

	SendMessage(&boarding_fader, "lfl", FADER_OUT, 1.0, false);
	SendMessage(&boarding_fader, "l", FADER_STARTFRAME);

	PauseAllSounds();
	ResetSoundScheme();

	bAbordageStarted = true;
	if(DeckID == "seadogs") bCrewStarted = true;
	bDeckStarted = !bCrewStarted;
	bCabinStarted = false;
	Sea.AbordageMode = true;
	//MAXIMUS [used for DirectSail] -->
	ref PChar = GetMainCharacter();
	PChar.IsOnDeck = true;
	//MAXIMUS [used for DirectSail] <--
}

//////////////
void Deck_Start()
{
	ResetSoundScheme();
	PauseAllSounds();
	int i, idx;
	//=астроим интерфейс
	if (LandLocationIdx == -1) DeleteBattleInterface(); // KK
	InitBattleLandInterface();
	StartBattleLandInterface();

	ref mchr = GetMainCharacter();

	// SCREWFACE : To have small different model of deck for different shipclass
	int locID = -1;
	locID = FindLocation(DeckID);
	if(locID < 0)
	{
		Trace("Boarding: ship location not found <" + DeckID + ">, set default");
		DeckID = "";
		return;
	}

	SetUpDeckReloadMap(); // KK

	//Tыставим  и запомним адреса
	boarding_adr[0].location = mchr.location;
	boarding_adr[0].group = mchr.location.group;
	boarding_adr[0].locator = mchr.location.locator;

	for(i = 1; i < OFFICER_MAX; i++)
	{
		idx = GetOfficersIndex(mchr, i);
		if(idx < 0)
		{
			boarding_adr[i].location = "";
			boarding_adr[i].group = "";
			boarding_adr[i].locator = "";
			continue;
		}
		boarding_adr[i].location = Characters[idx].location;
		boarding_adr[i].group = Characters[idx].location.group;
		boarding_adr[i].locator = Characters[idx].location.locator;
	}
	//Стартуем
	Deck_LoadLocation(DeckID); // KK //MAXIMUS
}

//Загрузить локацию абордажа
void Deck_LoadLocation(string locID) // KK //MAXIMUS
{
	ReloadProgressStart();
	//Lщем локаци|
	int locIndex = FindLocation(locID);
	ref mchr = GetMainCharacter();
	if(locIndex >= 0)
	{
		if(!bCanEnterToLand && HasSubStr(locID,"ShipDeck")) locations[locIndex].coxswain = true;//MAXIMUS: added for placing monster near steering-wheel
		//Устанавливаем главного персонажа
		mchr.location = locID;

	// SCREWFACE : locators to load nathaniel are different for different model
// KK -->
		if (FromDeckIdx == -1) {
			if (!bEmergeOnStartloc) {
				mchr.location.group = "reload";
				mchr.location.locator = GetRandSubString("boatr,boatl");//MAXIMUS
				bEmergeOnStartloc = true;
			} else {
				mchr.location.group = "rld";
				mchr.location.locator = "startloc";
			}
		} else {
			mchr.location.group = "reload";
			mchr.location.locator = GetReloadMapAttrib(FromDeckIdx, current_locator_name, "emerge");
			// LDH fix errors on first entering ship as FromDeckIdx can be off - 01Jan09
			if (mchr.location.locator == "")
			{
				mchr.location.group = "reload";
				mchr.location.locator = GetRandSubString("boatr,boatl");
				Trace("Deck_LoadLocation: Fixed bad reload location on entering ship");
			}
			// LDH <--
		}

		//chrWaitReloadLocator = "";
		bEmergeOnStartloc = true;
		chrWaitReloadIsNoLink = false;
		FromDeckIdx = -1;
		current_locator_name = "";
		int logined = 1; // added by MAXIMUS
		int idx = -1;
		ref tmpChr;
		int i;

		string DeckTextureDir = "";
		if(!HasSubStr(locID,"ShipDeck")) // PB: Only in interior locations
		{
			DeckTextureDir = GetShipDecksTexture(mchr);
		}
		if (DeckTextureDir == "")	DeleteAttribute(&Locations[locIndex], "filespath.textures");
		else						Locations[locIndex].filespath.textures = DeckTextureDir;
// <-- KK

// MAXIMUS deck MODE -[Sets up prisoners, if we have them]->
		if(VISIT_DECK && GetPrisonerQuantity(mchr)>0)
		{//MAXIMUS: all models have a proper poor-animation
			aref locRef = &Nullcharacter;
			string prLocGroup = "goto";
			string prLocName = "goto";
			if(HasSubStr(FindCurrentDeck(),"Hold"))
			{
				logined = 1;
				int captive = 0;
				if(mchr.location=="Hold2" && GetCharacterShipCargoHoldCount(mchr)>1) { logined = 1; captive = 8; }
				for(i = captive; i < GetPrisonerQuantity(mchr); i++)
				{
					if(logined==9) break;
					idx = GetPrisoner(mchr, i);
					if(idx==-1) continue;
					tmpChr = GetCharacter(idx);

					ChangeCharacterAddressGroup(tmpChr, mchr.location, "rld", "prison" + logined);
					DisarmCharacter(tmpChr, false, false);

					if(tmpChr.sex!="woman") { LAi_SetPoorTypeNoGroup(tmpChr); }
					else { LAi_SetStayTypeNoGroup(tmpChr); }
					if(!CheckAttribute(tmpChr,"gambled"))
					{
						tmpChr.Dialog.Filename = "Prisoned_dialog.c";
						tmpChr.Dialog.CurrentNode = "First time";
						if(tmpChr.sex=="woman") tmpChr.greeting = "Gr_Pirate_f";
						else tmpChr.greeting = "Gr_Smugglers_vs_Blythe";
					}
					logined++;
				}
			}
			if(GetCharacterShipCargoHoldCount(mchr)==0)
			{//MAXIMUS: so we can meet random prisoner
				idx = GetPrisoner(mchr, Rand(GetPrisonerQuantity(mchr)-1));
				if(idx>0)
				{
					tmpChr = GetCharacter(idx);
					if(CheckAttribute(tmpChr,"prisoned.status"))
					{
						if(sti(tmpChr.prisoned.status)<=GetPrisonerQuantity(mchr))
						{
							tmpChr.prisoned.status = sti(tmpChr.prisoned.status)+1;
						}
						else DeleteAttribute(tmpChr,"prisoned.status");
					}
					int count = 1;
					while(count<GetPrisonerQuantity(mchr) && CheckAttribute(tmpChr,"prisoned.status"))
					{
						tmpChr = GetCharacter(GetPrisoner(mchr, Rand(GetPrisonerQuantity(mchr)-1)));
						count++;
					}
					if(count==GetPrisonerQuantity(mchr)) DeleteAttribute(tmpChr,"prisoned.status");

					aref refLocators; makearef(refLocators,Locations[locIndex].locators);
					if(CheckAttribute(refLocators,"goto"))
					{
						makearef(locRef,Locations[locIndex].locators.goto);
						prLocName = "goto" + Rand(GetAttributesNum(locRef)-1);
						while(!CheckAttribute(locRef, prLocName))
						{
							prLocName = "goto" + Rand(GetAttributesNum(locRef)-1);
						}

						ChangeCharacterAddressGroup(tmpChr, locID, prLocGroup, prLocName);trace("BOAL_Deck: Prisoner "+GetMySimpleName(tmpChr)+" placed onto locator "+prLocName);
						DisarmCharacter(tmpChr, false, false);
						tmpChr.prisoned.status = 1;

						if(tmpChr.sex!="woman") { LAi_SetPoorTypeNoGroup(tmpChr); }
						else { LAi_SetStayTypeNoGroup(tmpChr); }
						if(!CheckAttribute(tmpChr,"gambled"))
						{
							tmpChr.Dialog.Filename = "Prisoned_dialog.c";
							tmpChr.Dialog.CurrentNode = "First time";
							if(tmpChr.sex=="woman") tmpChr.greeting = "Gr_Pirate_f";
							else tmpChr.greeting = "Gr_Smugglers_vs_Blythe";
						}
					}
					else
					{
						if(CheckAttribute(refLocators,"rld"))
						{
							prLocGroup = "rld";
							prLocName = GetRandSubString("aloc,loc");
							makearef(locRef,Locations[locIndex].locators.rld);
							string prName = prLocName + Rand(GetAttributesNum(locRef)-1);
							while(!CheckAttribute(locRef, prName))
							{
								prName = prLocName + Rand(GetAttributesNum(locRef)-1);
							}

							ChangeCharacterAddressGroup(tmpChr, locID, prLocGroup, prName);trace("BOAL_Deck: Prisoner "+GetMySimpleName(tmpChr)+" placed onto locator "+prName);
							DisarmCharacter(tmpChr, false, false);
							tmpChr.prisoned.status = 1;

							if(tmpChr.sex!="woman") { LAi_SetPoorTypeNoGroup(tmpChr); }
							else { LAi_SetStayTypeNoGroup(tmpChr); }
							if(!CheckAttribute(tmpChr,"gambled"))
							{
								tmpChr.Dialog.Filename = "Prisoned_dialog.c";
								tmpChr.Dialog.CurrentNode = "First time";
								if(tmpChr.sex=="woman") tmpChr.greeting = "Gr_Pirate_f";
								else tmpChr.greeting = "Gr_Smugglers_vs_Blythe";
							}
						}
					}
				}
			}
		}
// MAXIMUS deck MODE <-[Sets up prisoners, if we have them]-
		//Loading character into location
		boarding_location = locIndex;
		Locations[locIndex].boarding = "true";
		if(LoadLocation(&Locations[locIndex]))
		{
			PlaceOfficersToDeck("Deck");// MAXIMUS
			BLI_UpdateOfficers();//MAXIMUS: officers-icons fixed
			dialogDisable = false;
		} else {
			Trace("Boarding: Boarding location not loaded, current loc <" + DeckID + ">"); // KK
		}
	} else {
		Trace("Boarding: Boarding location not found, current loc <" + locID + ">");
	}

	if (HasSubStr(FindCurrentDeck(), "ShipDeck")) {
		Whr_UpdateWeather(false);//JA 8DEC06 on deck so resume raining
	} else {
		WhrDeleteRainEnvironment();// otherwise, stop raining
	}

	ReloadProgressEnd();
	PostEvent("LoadSceneSound", 500);
}

/////////////
void Deck_ReloadStartFadeAfter()
{
	//Tыгружаем локаци|
	ResetSoundScheme();
	PauseAllSounds();
	DelEventHandler("FaderEvent_StartFade", "Deck_ReloadStartFadeAfter");
	DelEventHandler("Control Activation", "TeleportToDeck");//JA 6DEC06 this eventhandler was hanging around after you went from deck to sea.
	if(boarding_location >= 0) UnloadLocation(&Locations[boarding_location]);
	DeleteAttribute(GetMainCharacter(),"reloadStatus");
}

void Deck_ReloadEndFadeAfter()
{
	int i, idx;
	ReloadProgressStart(); // KK
	//Загружаем следу|щу| локаци|
	DelEventHandler("FaderEvent_EndFade", "Deck_ReloadEndFadeAfter");
	SendMessage(&boarding_fader, "lfl", FADER_IN, RELOAD_TIME_FADE_IN, true);
	boarding_location = -1;
	//=астроим интерфейс
	Log_SetActiveAction("Nothing");
	EndBattleLandInterface();
	//Tостановим адреса
	ref mchr = GetMainCharacter();
	mchr.location = boarding_adr[0].location;
	mchr.location.group = boarding_adr[0].group;
	mchr.location.locator = boarding_adr[0].locator;
	for(i = 1; i < OFFICER_MAX; i++)
	{
		idx = GetOfficersIndex(mchr, i); // KK
		if(idx < 0) continue;
		Characters[idx].location = boarding_adr[i].location;
		Characters[idx].location.group = boarding_adr[i].group;
		Characters[idx].location.locator = boarding_adr[i].locator;
	}
/////////////////////////////////////////////////////////////////////
    // load all models back to sea
	aref arModel;
	if (FindClass(&arModel, "modelr"))
	{
		SendMessage(arModel, "l", MSG_MODEL_RESTORE);
		while (FindClassNext(&arModel))
		{
			//Trace("XYZ");
			SendMessage(arModel, "l", MSG_MODEL_RESTORE);
		}
	}

	LayerFreeze("execute",true);
	LayerFreeze("realize",true);

	LayerFreeze("sea_reflection", false);
	LayerFreeze(SEA_EXECUTE,false);
	LayerFreeze(SEA_REALIZE,false);

	MoveWeatherToLayers(SEA_EXECUTE, SEA_REALIZE);
	MoveSeaToLayers(SEA_EXECUTE, SEA_REALIZE);

	Sea.MaxSeaHeight = fOldMaxSeaHeight;		// restore old MaxSeaHeight
	ClearDeck();//MAXIMUS
	bAbordageStarted = false;
	Sea.AbordageMode = false;
	chrWaitReloadLocator = "";

	InitBattleInterface();
	StartBattleInterface();
	RefreshBattleInterface(true);

	SetSchemeForSea();

	PauseParticles(false);

	bSeaReloadStarted = false;

	Whr_UpdateWeather(false); //JA 8DEC06 on deck so resume raining

	ReloadProgressEnd(); // KK
}

// Cabin ---------------------------------------------------

void Cabin_ReloadStartFade()
{
	int a = GetEventData();
	boarding_fader = GetEventData();
	LayerFreeze(SEA_EXECUTE,true);
	LayerFreeze(SEA_REALIZE,true);
	LayerFreeze("sea_reflection",true);
	LayerFreeze("execute",false);
	LayerFreeze("realize",false);

	//MoveWeatherToLayers("execute", "realize");
	//MoveSeaToLayers("execute", "realize");

	SendMessage(&AIBalls, "l", MSG_MODEL_RELEASE);

	DelEventHandler("FaderEvent_StartFade", "Cabin_ReloadStartFade");

	if (CheckAttribute(Sea, "MaxSeaHeight")) { // KK
		fOldMaxSeaHeight = stf(Sea.MaxSeaHeight);
		Sea.MaxSeaHeight = 1.15;						// set maxinum sea height for ship Cabin
	}
}

void Cabin_ReloadEndFade()
{
	// Delete current cannonballs
	AIBalls.Clear = "";

	// unload all models
	aref arModel;
	if (FindClass(&arModel, "modelr"))
	{
		SendMessage(arModel, "l", MSG_MODEL_RELEASE);
		while (FindClassNext(&arModel)) { SendMessage(arModel, "l", MSG_MODEL_RELEASE); }
	}

	PauseParticles(true);

	// start Cabin location
	int a = GetEventData();
	boarding_fader = GetEventData();

	MoveWeatherToLayers("execute", "realize");
	MoveSeaToLayers("execute", "realize");

	Cabin_Start();

	DelEventHandler("FaderEvent_EndFade", "Cabin_ReloadEndFade");
	SendMessage(&boarding_fader, "lfl", FADER_IN, RELOAD_TIME_FADE_IN, true);
}

void Sea_CabinStartNow(int chridx)
{
	bSeaReloadStarted = true;
	bToDeckFromLand = false; // KK

	if (chridx < 0) chridx = GetMainCharacterIndex(); // KK
	iShipCaptain = chridx; // KK

	// KK object boarding_fader;
	CreateEntity(&boarding_fader, "fader");
	SetEventHandler("FaderEvent_StartFade", "Cabin_ReloadStartFade", 0);
	SetEventHandler("FaderEvent_EndFade", "Cabin_ReloadEndFade", 0);
	SetEventHandler("Control Activation", "TeleportToDeck", 1); // KK

	bDeckEnter = true;

	WhrDeleteRainEnvironment(); //JA 8DEC06 Stop it raining inside

	// SCREWFACE : New loading screen for small and medium cabin model
	ref mchr = GetMainCharacter();
// KK -->
	deckID = GetCharacterShipCabin(GetCharacter(chridx));
	if (CheckAttribute(Locations[FindLocation(deckID)], "image")) SendMessage(&boarding_fader, "ls", FADER_PICTURE, FindReloadPicture(Locations[FindLocation(DeckID)].image));
// <-- KK
	// SCREWFACE : END

	SendMessage(&boarding_fader, "lfl", FADER_OUT, 1.0, false);
	SendMessage(&boarding_fader, "l", FADER_STARTFRAME);

	PauseAllSounds();
	ResetSoundScheme();

	bAbordageStarted = true;
	bCabinStarted = true;
	bCrewStarted = false;
	Sea.AbordageMode = true;
	mchr.IsOnDeck = true;
}

//////////////
void Cabin_Start()
{
	ResetSoundScheme();
	PauseAllSounds();
	int i, idx;
	//=астроим интерфейс
	if (LandLocationIdx == -1) DeleteBattleInterface(); // KK
	InitBattleLandInterface();
	StartBattleLandInterface();

// KK -->
	ref mchr = GetMainCharacter();

	if (iShipCaptain == GetMainCharacterIndex())
		deckID = "tutorial_deck";
	else
		DeckID = "Companion_Cabin_" + GetCompanionNumber(mchr, iShipCaptain);
// <-- KK

	int locID = -1;
	locID = FindLocation(deckID);

	if(locID < 0)
	{
		Trace("Boarding: ship location not found <" + deckID + ">, set default");
		deckID = "";
		return;
	}

	SetUpCabin(GetCharacter(iShipCaptain)); // KK
	SetUpDeckReloadMap(); // KK

	//Tыставим  и запомним адреса
	boarding_adr[0].location = mchr.location;
	boarding_adr[0].group = mchr.location.group;
	boarding_adr[0].locator = mchr.location.locator;
	for (i = 1; i < OFFICER_MAX; i++)
	{
		idx = GetOfficersIndex(mchr,  i); // KK
		if (idx < 0) {
			boarding_adr[i].location = "";
			boarding_adr[i].group = "";
			boarding_adr[i].locator = "";
			continue;
		}
		boarding_adr[i].location = Characters[idx].location;
		boarding_adr[i].group = Characters[idx].location.group;
		boarding_adr[i].locator = Characters[idx].location.locator;
	}
	//Стартуем
	Cabin_LoadLocation();
}

//Загрузить локаци| абордажа
void Cabin_LoadLocation()
{
	ReloadProgressStart();
	//Lщем локаци|
	int locIndex = FindLocation(DeckID);
	if(locIndex >= 0)
	{
// KK -->
		//Устанавливаем главного персонажа
		ref mchr = GetMainCharacter();
		mchr.location = DeckID;
		if (FromDeckIdx == -1) {
			if (iShipCaptain == GetMainCharacterIndex()) {
				mchr.location.group = "rld";
				mchr.location.locator = "startloc";
			} else {
				mchr.location.group = "reload";
				mchr.location.locator = "reload1";
			}
		} else {
			mchr.location.group = "reload";
			mchr.location.locator = GetReloadMapAttrib(FromDeckIdx, current_locator_name, "emerge");
		}

		//chrWaitReloadLocator = "";
		chrWaitReloadIsNoLink = false;
		FromDeckIdx = -1;
		current_locator_name = "";
// <-- KK

		//Перегружаемся в локаци|
		boarding_location = locIndex;
		Locations[locIndex].boarding = "true";
		if(LoadLocation(&Locations[locIndex]))
		{
			PlaceOfficersToDeck("Cabin");// MAXIMUS
			BLI_UpdateOfficers();//MAXIMUS: officers-icons fixed
			//Расставляем персонажей
			//SetEventHandler(EVENT_LOCATION_LOAD,"qprocEndReload",0);
			//Запретим диалог
			dialogDisable = false;
		}else{
			Trace("Boarding: Boarding location not loaded, current loc <" + DeckID + ">");
		}
	}else{
		Trace("Boarding: Boarding location not found, current loc <" + DeckID + ">");
	}

	WhrDeleteRainEnvironment(); // JA 8dec06 stop raining

	ReloadProgressEnd();
	PostEvent("LoadSceneSound", 500);
}

// KK -->
aref GetReloadMapRef(ref ReloadRef, string attrib, string value)
{
	int i = 0;
	int num = GetAttributesNum(ReloadRef);
	aref LocatorRef;
	for (i = 0; i < num; i++) {
		LocatorRef = GetAttributeN(ReloadRef, i);
		if (LocatorRef.(attrib) == value) return LocatorRef;
	}
	makearef(LocatorRef, NullCharacter);
	return LocatorRef;
}

string GetReloadMapAttrib(int locidx, string locator_name, string attrib)
{
	int i = 0;
	if (locidx == -1) return "";
	aref ReloadRef; makearef(ReloadRef, Locations[locidx].reload);
	int num = GetAttributesNum(ReloadRef);
	aref LocatorRef;
	for (i = 0; i < num; i++) {
		LocatorRef = GetAttributeN(ReloadRef, i);
		if (CheckAttribute(LocatorRef, "name") == true && LocatorRef.name == locator_name) break;//MAXIMUS
	}
	if (i == num) return "";
	if (!CheckAttribute(LocatorRef, attrib)) return "";
	return LocatorRef.(attrib);
}

string FindCurrentDeck()
{
	ref mchr = GetMainCharacter();
	if (!CheckAttribute(mchr, "location")) return "";
	if (HasSubStr(mchr.location, "ShipDeck")) return "ShipDeck";
	if (mchr.location == "Tutorial_Deck") return "Cabin";
	if (HasSubStr(mchr.location, "Companion_Cabin_")) return "Cabin";
	if (mchr.location == "seadogs") return mchr.location;
	if (HasSubStr(mchr.location, "Deck")) return "CannonsDeck";
	if (HasSubStr(mchr.location, "Hold")) return "Hold";
	return "";
}

void SetUpDeckReloadMap()
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

	if (ncdecks == 0) {
		Locations[iseadogs].reload.l1.go = "Hold1";
		Locations[iseadogs].reload.l1.emerge = "reload2";
		Locations[ihold1].reload.l2.go = "Seadogs";
		Locations[ihold1].reload.l2.emerge = "reload1";
	} else {
		Locations[iseadogs].reload.l1.go = "Deck1";
		Locations[iseadogs].reload.l1.emerge = "reload2";
		Locations[icdeck1].reload.l2.go = "Seadogs";
		Locations[icdeck1].reload.l2.emerge = "reload1";
	}

	if (ncdecks == 1) {
		Locations[icdeck1].id.label = "Main Cannons Deck";
		if (nholds == 1) {
			Locations[icdeck1].reload.l3.go = "Hold1";
			Locations[icdeck1].reload.l3.emerge = "reload1";
			Locations[icdeck1].reload.l4.go = "";
			Locations[icdeck1].reload.l4.emerge = "";
			Locations[ihold1].reload.l1.go = "Deck1";
			Locations[ihold1].reload.l1.emerge = "reload3";
			Locations[ihold1].reload.l2.go = "";
			Locations[ihold1].reload.l2.emerge = "";
		} else {
			Locations[icdeck1].reload.l3.go = "Hold1";
			Locations[icdeck1].reload.l3.emerge = "reload1";
			Locations[icdeck1].reload.l4.go = "";
			Locations[icdeck1].reload.l4.emerge = "";
			Locations[ihold1].reload.l1.go = "Deck1";
			Locations[ihold1].reload.l1.emerge = "reload3";
		}
	} else {
		tmpdeck = "Deck2";
		itmpdeck = icdeck2;
		if (ncdecks == 2) {
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

	if (ncdecks == 3) {
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

	if (ncdecks > 1 && nholds > 0) {
		Locations[icdeck3].reload.l3.go = "Hold1";
		Locations[icdeck3].reload.l3.emerge = "reload1";
		Locations[ihold1].reload.l1.go = "Deck3";
		Locations[ihold1].reload.l1.emerge = "reload3";
	}

	if (nholds == 2) {
		Locations[ihold1].id.label = "1st Cargo Hold";
		Locations[ihold1].reload.l2.go = "Hold2";
		Locations[ihold1].reload.l2.emerge = "reload2";
		Locations[ihold2].id.label = "2nd Cargo Hold";
		Locations[ihold2].reload.l2.go = "Hold1";
		Locations[ihold2].reload.l2.emerge = "reload2";
		Locations[ihold2].reload.l1.go = "";
		Locations[ihold2].reload.l1.emerge = "";
	} else {
		Locations[ihold1].id.label = "Cargo Hold";
	}

	Locations[icabin].reload.l1.go = deck;
	Locations[icabin].reload.l1.emerge = "reload1";
	if (iShipCaptain == mcidx)
		Locations[ideck].reload.l1.go = "Tutorial_Deck";
	else
		Locations[ideck].reload.l1.go = "Companion_Cabin_" + companion_no;
	Locations[ideck].reload.l1.emerge = "reload1";

	if (deck == "ShipDeck2" || deck == "ShipDeck4" || deck == "ShipDeck6") {
		if (iShipCaptain == mcidx)
			Locations[ideck].reload.l7.go = "Tutorial_Deck";
		else
			Locations[ideck].reload.l7.go = "Companion_Cabin_" + companion_no;
		Locations[ideck].reload.l7.emerge = "reload1";
	}

	if (deck != "ShipDeck6" || deck != "ShipDeck7") {
		Locations[iseadogs].reload.l2.go = deck;
		Locations[iseadogs].reload.l2.emerge = "reload2";
		Locations[ideck].reload.l2.go = "Seadogs";
		Locations[ideck].reload.l2.emerge = "reload2";
	}

	if(ncdecks > 0) {
		tmpdeck = "Deck1";
		itmpdeck = icdeck1;
	} else {
		tmpdeck = "Hold1";
		itmpdeck = ihold1;
	}
	if (deck != "ShipDeck3") {
		Locations[itmpdeck].reload.l1.go = deck;
		Locations[itmpdeck].reload.l1.emerge = "reload3";
		Locations[ideck].reload.l3.go = tmpdeck;
		Locations[ideck].reload.l3.emerge = "reload1";
	}
	if (deck == "ShipDeck6" || deck == "ShipDeck7") {
		Locations[ideck].reload.l8.go = tmpdeck;
		Locations[ideck].reload.l8.emerge = "reload1";
	}

	if (ndecks == 0) {
		Locations[ideck].reload.l1.go = "";
		Locations[ideck].reload.l1.emerge = "";
		Locations[ideck].reload.l2.go = "";
		Locations[ideck].reload.l2.emerge = "";
		Locations[ideck].reload.l3.go = "";
		Locations[ideck].reload.l3.emerge = "";
		if (deck == "ShipDeck2") {
			Locations[ideck].reload.l7.go = "";
			Locations[ideck].reload.l7.emerge = "";
		}
	}

	Locations[ideck].reload.l4.go = "";
	Locations[ideck].reload.l4.emerge = "";
	Locations[ideck].reload.l5.go = "";
	Locations[ideck].reload.l5.emerge = "";

	aref LocatorRef;
	if (LandLocationIdx == -1) {
		LocatorRef = GetReloadMapRef(arIslandReload, "name", sIslandLocator);
	} else {
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
	if(bCanEnterToLand) {
		Locations[ideck].reload.l4.go = LocatorRef.go;
		Locations[ideck].reload.l4.emerge = LocatorRef.emerge;
		Locations[ideck].reload.l5.go = LocatorRef.go;
		Locations[ideck].reload.l5.emerge = LocatorRef.emerge;
	}

	Locations[ideck].reload.l6.disabled = iShipCaptain != GetMainCharacterIndex() || bQuestDisableSeaEnter == true;
}

void DeckToSea_ReloadStartFadeAfter()
{
	ResetSoundScheme();
	PauseAllSounds();
	DelEventHandler("FaderEvent_StartFade", "DeckToSea_ReloadStartFadeAfter");

	UnloadDeck();
	Sea.MaxSeaHeight = fOldMaxSeaHeight;
}

void DeckToSea_ReloadEndFadeAfter()
{
	ReloadProgressStart();

	DelEventHandler("FaderEvent_EndFade", "DeckToSea_ReloadEndFadeAfter");
	SendMessage(&boarding_fader, "lfl", FADER_IN, RELOAD_TIME_FADE_IN, true);

	ref mchr = GetMainCharacter();
	if(!CheckAttribute(mchr,"location.from_sea")) return;
	int fslocidx = FindLocation(mchr.location.from_sea);
	if (fslocidx < 0) return;
	string island = Locations[fslocidx].island;
	if (!CheckAttribute(Locations[fslocidx], "reload")) return;
	aref PortReload; makearef(PortReload, Locations[fslocidx].reload);
	chrWaitReloadRef = GetReloadMapRef(PortReload, "go", island);
	chrWaitReloadLocator = chrWaitReloadRef.name;
	lockedReloadLocator = "";
	chrWaitReloadLocator = "";
	chrWaitReloadIsNoLink = false;
	ReloadToSea(FindIsland(island), chrWaitReloadRef);
	DirectsailCheck(true);

	bDeckEnter = false;
	LandLocationIdx = -1;
	iShipCaptain = -1;

	Log_SetActiveAction("Nothing");
	BLI_RefreshCommandMenu();

	SendMessage(&boarding_fader, "lfl", FADER_IN, RELOAD_TIME_FADE_IN, true);
	PostEvent("LoadSceneSound", 500);

	Whr_UpdateWeather(false); //JA 8DEC06 on deck so resume raining

	ReloadProgressEnd();
}

void UnloadDeck()
{
	int i, idx;
	bDeckStarted = false;
	bCabinStarted = false;
	bCrewStarted = false;
	Sea.AbordageMode = false;
	bAbordageStarted = false;
	DelEventHandler("Control Activation", "TeleportToDeck");
	ref mchr = GetMainCharacter();
	EndBattleLandInterface();
	Log_SetActiveAction("Nothing");
	mchr.activeItem = "";
	BLI_RefreshCommandMenu();
	if (FindLoadedLocation() >= 0) UnloadLocation(&Locations[FindLoadedLocation()]);
	if (boarding_location >= 0) DeleteAttribute(Locations[boarding_location], "boarding");
	boarding_location = -1;
	if (!CheckAttribute(boarding_adr[0], "location")) return;
	mchr.location = boarding_adr[0].location;
	mchr.location.group = boarding_adr[0].group;
	mchr.location.locator = boarding_adr[0].locator;
	for (i = 1; i < OFFICER_MAX; i++) {
		idx = GetOfficersIndex(mchr, i);
		if (idx < 0) continue;
		Characters[idx].location = boarding_adr[i].location;
		Characters[idx].location.group = boarding_adr[i].group;
		Characters[idx].location.locator = boarding_adr[i].locator;
		LAi_SetOfficerType(GetCharacter(idx));	// LDH 29Dec08
	}
}

void Deck_GoBack()
{
	if(dialogRun || dialogSelf)//MAXIMUS -->
	{
		traceif("Can't reload...");
		traceif("BOAL_Deck: character is in dialog");
		return;
	}//MAXIMUS <--
	ref mchr = GetMainCharacter();
	if(CheckAttribute(mchr, "lastlocation")) {
		LandLocationIdx = sti(mchr.lastlocation);
		DeleteAttribute(mchr, "lastlocation");
	}
	if (LandLocationIdx == -1) {
		Land_ToPort();
		return;
	}

	SetEventHandler("FaderEvent_StartFade", "DeckBack_ReloadStartFadeAfter", 0);
	SetEventHandler("FaderEvent_EndFade", "DeckBack_ReloadEndFadeAfter", 0);

	CreateEntity(&boarding_fader, "fader");
	if (CheckAttribute(&Locations[LandLocationIdx], "image")) SendMessage(&boarding_fader, "ls", FADER_PICTURE, FindReloadPicture(Locations[LandLocationIdx].image));

	float fadeOutTime = RELOAD_TIME_FADE_OUT;

	SendMessage(&boarding_fader, "lfl", FADER_OUT, fadeOutTime, false);
	SendMessage(&boarding_fader, "l", FADER_STARTFRAME);
	if(CheckAttribute(GetMainCharacter(),"IsOnDeck")) DeleteAttribute(GetMainCharacter(),"IsOnDeck");
}

void DeckBack_ReloadStartFadeAfter()
{
	ResetSoundScheme();
	PauseAllSounds();
	DelEventHandler("FaderEvent_StartFade", "DeckBack_ReloadStartFadeAfter");

	UnloadDeck();
	Sea.MaxSeaHeight = fOldMaxSeaHeight;
}

void DeckBack_ReloadEndFadeAfter()
{
	int i, idx;
	ReloadProgressStart();

	DelEventHandler("FaderEvent_EndFade", "DeckBack_ReloadEndFadeAfter");
	SendMessage(&boarding_fader, "lfl", FADER_IN, RELOAD_TIME_FADE_IN, true);

	ref mchr = GetMainCharacter();
	mchr.location = Locations[LandLocationIdx].id;
	mchr.location.group = "reload";
	mchr.location.locator = LandLocator;
	if(!CheckAttribute(&Locations[LandLocationIdx],"environment.sea") || Locations[LandLocationIdx].environment.sea!="true") DeleteSeaEnvironment();//MAXIMUS
	if(!CheckAttribute(&Locations[LandLocationIdx],"environment.weather") || Locations[LandLocationIdx].environment.weather!="true") DeleteWeatherEnvironment();//MAXIMUS
	if (LoadLocation(&Locations[LandLocationIdx]))
		dialogDisable = false;
	else
		Trace("ReturnFromShip: location not loaded, current loc <" + mchr.location + ">");
	lockedReloadLocator = "";
	chrWaitReloadLocator = "";
	chrWaitReloadIsNoLink = false;
	for (i = 0; i < OFFICER_MAX; i++) {
		idx = GetOfficersIndex(mchr, i);
		if (idx == -1) continue;
		TeleportCharacterToPosAy(GetCharacter(idx), Land_posx[i], Land_posy[i], Land_posz[i], Land_angle[i]);
	}

	ClearDeck();//MAXIMUS
	bAbordageStarted = false;
	Sea.AbordageMode = false;
	LandLocationIdx = -1;
	iShipCaptain = -1;

	Log_SetActiveAction("Nothing");
	BLI_RefreshCommandMenu();

	PauseAllSounds();
	ResetSoundScheme();

	ReloadProgressEnd();
}

void TeleportToDeck()
{
	if(dialogRun || dialogSelf)//MAXIMUS -->
	{
		traceif("Can't reload...");
		traceif("BOAL_Deck: character is in dialog");
		return;
	}//MAXIMUS <--
	if (chrWaitReloadLocator == "") return;
	string controlName = GetEventData();
	if (controlName != "ChrAction") return;
	FromDeckIdx = FindLoadedLocation();
	current_locator_name = chrWaitReloadLocator;
	if (HasSubStr(chrWaitReloadLocator, "boat")) {
		Land_ToPort();
		Log_SetActiveAction("Nothing");
		BLI_RefreshCommandMenu();
		return;
	}
	string target = GetReloadMapAttrib(FromDeckIdx, chrWaitReloadLocator, "go");
	if (target == "") return;
	if (target == "Sea" && bQuestDisableSeaEnter) return; // PB
	UnloadDeck();
	if (bToDeckFromLand) {
		switch (target) {
			case "Tutorial_Deck":
				Land_CabinStartNow(iShipCaptain);
			break;
			case "Sea":
				Return2SeaAfterDeck();
			break;
			// default:
				if (HasSubStr(target, "Companion_Cabin_")) {
					Land_CabinStartNow(iShipCaptain);
				} else {
					Land_DeckStartNow(iShipCaptain, target);
				}
		}
	} else {
		switch (target) {
			case "Tutorial_Deck":
				Sea_CabinStartNow(iShipCaptain);
			break;
			case "Sea":
				Return2SeaAfterDeck();
			break;
			// default:
				if (HasSubStr(target, "Companion_Cabin_")) {
					Sea_CabinStartNow(iShipCaptain);
				} else {
					Sea_DeckStartNow(iShipCaptain, target);
				}
		}
	}
	Log_SetActiveAction("Nothing");
	BLI_RefreshCommandMenu();
}

void TransferToDeck(string finishLocName)
{
	if(dialogRun || dialogSelf)//MAXIMUS -->
	{
		traceif("Can't reload...");
		traceif("BOAL_Deck: character is in dialog");
		return;
	}//MAXIMUS <--
	if (finishLocName == "") return;

	if (iShipCaptain < 0) iShipCaptain = GetMainCharacterIndex(); // KK
	ref rShipCaptain = GetCharacter(iShipCaptain); // KK
	UnloadDeck();
	if (bToDeckFromLand) {
		switch (finishLocName) {
			case "Cabin":
				Land_CabinStartNow(iShipCaptain);
			break;
			case "ShipDeck":
				Land_DeckStartNow(iShipCaptain, GetCharacterShipQDeck(rShipCaptain));
			break;
			case "Port":
				Land_ToPort();
			break;
			// default:
				Land_DeckStartNow(iShipCaptain, finishLocName);
		}
	} else {
		switch (finishLocName) {
			case "Cabin":
				Sea_CabinStartNow(iShipCaptain);
			break;
			case "ShipDeck":
				Sea_DeckStartNow(iShipCaptain, GetCharacterShipQDeck(rShipCaptain));
			break;
			case "Port":
				Land_ToPort();
			break;
			// default:
				Sea_DeckStartNow(iShipCaptain, finishLocName);
		}
	}
	Log_SetActiveAction("Nothing");
	BLI_RefreshCommandMenu();
}

void Land_DeckStartNow(int chridx, string deckname)
{
	int i, idx;
	bToDeckFromLand = true;
	if (chridx < 0) chridx = GetMainCharacterIndex(); // KK
	iShipCaptain = chridx; // KK

	ref mchr = GetMainCharacter();
	if (LandLocationIdx == -1) {
		LandLocationIdx = FindLoadedLocation();
		mchr.lastlocation = LandLocationIdx;
		for (i = 0; i < OFFICER_MAX; i++) {
			idx = GetOfficersIndex(mchr, i);
			if (idx == -1) continue;
			GetCharacterPos(GetCharacter(idx), &Land_posx[i], &Land_posy[i], &Land_posz[i]);
			GetCharacterAy(GetCharacter(idx), &Land_angle[i]);
		}
		LandLocator = LAi_FindRandomLocator("reload");
		bCanEnterToLand = true;
	}

	bSeaReloadStarted = true;

	// KK object boarding_fader;
	CreateEntity(&boarding_fader, "fader");
	SetEventHandler("FaderEvent_StartFade", "LandDeck_ReloadStartFade", 0);
	SetEventHandler("FaderEvent_EndFade", "LandDeck_ReloadEndFade", 0);
	SetEventHandler("Control Activation", "TeleportToDeck", 1);

	bDeckEnter = true;

	deckID = deckname;
	if (!bEmergeOnStartloc && HasSubStr(deckname, "ShipDeck")) 
	{
		LAi_QuestDelay("gunner_ammo", 1.0);

		SendMessage(&boarding_fader, "ls", FADER_PICTURE, FindReloadPicture("Landing.tga"));
	} else {
		if (CheckAttribute(Locations[FindLocation(deckID)], "image")) SendMessage(&boarding_fader, "ls", FADER_PICTURE, FindReloadPicture(Locations[FindLocation(DeckID)].image));
	}

	SendMessage(&boarding_fader, "lfl", FADER_OUT, 1.0, false);
	SendMessage(&boarding_fader, "l", FADER_STARTFRAME);

	PauseAllSounds();
	ResetSoundScheme();

	bAbordageStarted = true;
	bDeckStarted = true;
	if (deckID == "seadogs") bCrewStarted = true;
	Sea.AbordageMode = true;
	mchr.IsOnDeck = true;
}

void LandDeck_ReloadStartFade()
{
	ref mchr = GetMainCharacter();
	if (FindLocation(mchr.location) >= 0) UnloadLocation(&Locations[FindLocation(mchr.location)]);

	DelEventHandler("FaderEvent_StartFade", "LandDeck_ReloadStartFade");
}

void LandDeck_ReloadEndFade()
{
	int a = GetEventData();
	boarding_fader = GetEventData();

	Deck_Start();

	if (CheckAttribute(Sea, "MaxSeaHeight")) {
		fOldMaxSeaHeight = stf(Sea.MaxSeaHeight);
		Sea.MaxSeaHeight = 1.15;
		ref lcn = &Locations[FindLocation(DeckID)];
		if(CheckAttribute(lcn,"MaxSeaHeight")) Sea.MaxSeaHeight = stf(lcn.MaxSeaHeight); // screwface : limit wave height
	}

	DelEventHandler("FaderEvent_EndFade", "LandDeck_ReloadEndFade");
	SendMessage(&boarding_fader, "lfl", FADER_IN, RELOAD_TIME_FADE_IN, true);
}

void Land_ToPort()
{
	DeckID = "";
	FromDeckIdx = -1;
	bEmergeOnStartloc = false;	// LDH 14Feb09
	DelEventHandler("Control Activation", "TeleportToDeck");

	Whr_UpdateWeather(false); //JA 8DEC06 Resume weather if leaving cabin/deck

	if(CheckAttribute(GetMainCharacter(),"IsOnDeck")) DeleteAttribute(GetMainCharacter(),"IsOnDeck");

	if (LandLocationIdx == -1) {
		UnloadDeck();
		DeleteShipEnvironment();
		Sea_LandLoad();
	} else {
		SetEventHandler("FaderEvent_StartFade", "LandToPort_ReloadStartFadeAfter", 0);
		SetEventHandler("FaderEvent_EndFade", "LandToPort_ReloadEndFadeAfter", 0);

		ref mchr = GetMainCharacter();
		CreateEntity(&boarding_fader, "fader");
		if (CheckAttribute(&Locations[FindLocation(mchr.location.from_sea)], "image")) SendMessage(&boarding_fader, "ls", FADER_PICTURE, FindReloadPicture(Locations[FindLocation(mchr.location.from_sea)].image));

		float fadeOutTime = RELOAD_TIME_FADE_OUT;

		SendMessage(&boarding_fader, "lfl", FADER_OUT, fadeOutTime, false);
		SendMessage(&boarding_fader, "l", FADER_STARTFRAME);
	}
}

void LandToPort_ReloadStartFadeAfter()
{
	ResetSoundScheme();
	PauseAllSounds();
	DelEventHandler("FaderEvent_StartFade", "LandToPort_ReloadStartFadeAfter");

	UnloadDeck();

	Sea.MaxSeaHeight = fOldMaxSeaHeight;
}

void LandToPort_ReloadEndFadeAfter()
{
	ReloadProgressStart();

	DelEventHandler("FaderEvent_EndFade", "LandToPort_ReloadEndFadeAfter");
	SendMessage(&boarding_fader, "lfl", FADER_IN, RELOAD_TIME_FADE_IN, true);

	ref mchr = GetMainCharacter();
	int fslocidx = FindLocation(mchr.location.from_sea);
	if (fslocidx < 0) return;
	string island = Locations[fslocidx].island;
	ref IslandRef = GetIslandByID(island);
	if (!CheckAttribute(IslandRef, "reload")) return;
	aref IslandReload; makearef(IslandReload, IslandRef.reload);
	aref TownReload = GetReloadMapRef(IslandReload, "go", mchr.location.from_sea)
	mchr.location = TownReload.go;
	mchr.location.group = "reload";
	mchr.location.locator = TownReload.emerge;
	if (LoadLocation(&Locations[FindLocation(mchr.location)]))
		dialogDisable = false;
	else
		Trace("ReturnFromShip: location not loaded, current loc <" + mchr.location + ">");
	lockedReloadLocator = "";
	chrWaitReloadLocator = "";
	chrWaitReloadIsNoLink = false;

	ClearDeck();//MAXIMUS
	bAbordageStarted = false;
	Sea.AbordageMode = false;
	LandLocationIdx = -1;
	iShipCaptain = -1;

	Log_SetActiveAction("Nothing");
	BLI_RefreshCommandMenu();

	PauseAllSounds();
	PostEvent("LoadSceneSound", 500);       // LDH 14Feb09

	ReloadProgressEnd();
}

void SetUpCabin(ref chr)
{
	ref mchr = GetMainCharacter();
	int locID = -1;
	int cabinloc = -1;
	if (iShipCaptain == GetMainCharacterIndex() || iShipCaptain == GetCharacterIndex("Malcolm Hatcher")) // PB: For tutorial on cabin-less ship
		locID = FindLocation("Tutorial_Deck");
	else
		locID = FindLocation("Companion_Cabin_" + GetCompanionNumber(mchr, iShipCaptain));

	// SCREWFACE : To have small and medium model of Cabin when for different shipclass
	// Keep the same location and only change the model is very important to have weapons locker
	string cabinID = GetCharacterShipCabin(chr);
	if (cabinID == "Cabin_none") return;
	if (cabinID != "Tutorial_Deck") {
		cabinloc = FindLocation(cabinID);
		Locations[locID].filespath.models = Locations[cabinloc].filespath.models;
		Locations[locID].image = Locations[cabinloc].image;
		Locations[locID].models.always.locators = Locations[cabinloc].models.always.locators;
		Locations[locID].models.always.l1 = Locations[cabinloc].models.always.l1;
		Locations[locID].models.day.charactersPatch = Locations[cabinloc].models.day.charactersPatch;
		Locations[locID].models.day.fonar = Locations[cabinloc].models.day.fonar;
		Locations[locID].models.night.charactersPatch = Locations[cabinloc].models.night.charactersPatch;
		Locations[locID].models.night.fonar = Locations[cabinloc].models.night.fonar;
		if (CheckAttribute(Locations[cabinloc], "models.always.window"))
			Locations[locID].models.always.window = Locations[cabinloc].models.always.window;
		else
			Locations[locID].models.always.window = "";
	} else {
		Locations[locID].filespath.models = "locations\decks\cabin\tut_deck";
		Locations[locID].image = "Cabin.tga";
		Locations[locID].models.always.locators = "tut_Deck_ld";
		Locations[locID].models.always.l1 = "tut_Deck";
		Locations[locID].models.always.l2 = "cabinchest";		//JRH
		Locations[locID].models.always.l3 = "trunk";			//JRH
		Locations[locID].models.day.charactersPatch = "tut_Deck_p";
		Locations[locID].models.day.fonar = "tut_Deck_fd";
		Locations[locID].models.night.charactersPatch = "tut_Deck_p";
		Locations[locID].models.night.fonar = "tut_Deck_fn";
		Locations[locID].models.always.window = "tut_deck_w";
	}
}

void Land_CabinStartNow(int chridx)
{
	int i, idx;
	bToDeckFromLand = true;
	if (chridx < 0) chridx = GetMainCharacterIndex(); // KK
	iShipCaptain = chridx; // KK

	ref mchr = GetMainCharacter();
	if (LandLocationIdx == -1) {
		LandLocationIdx = FindLoadedLocation();
		for (i = 0; i < OFFICER_MAX; i++) {
			idx = GetOfficersIndex(mchr, i);
			if (idx == -1) continue;
			GetCharacterPos(GetCharacter(idx), &Land_posx[i], &Land_posy[i], &Land_posz[i]);
			GetCharacterAy(GetCharacter(idx), &Land_angle[i]);
		}
		LandLocator = LAi_FindRandomLocator("reload");
		bCanEnterToLand = true;
	}

	bSeaReloadStarted = true;

	// KK object boarding_fader;
	CreateEntity(&boarding_fader, "fader");
	SetEventHandler("FaderEvent_StartFade", "LandCabin_ReloadStartFade", 0);
	SetEventHandler("FaderEvent_EndFade", "LandCabin_ReloadEndFade", 0);
	SetEventHandler("Control Activation", "TeleportToDeck", 1);

	bDeckEnter = true;

	deckID = GetCharacterShipCabin(GetCharacter(iShipCaptain));
	if (CheckAttribute(Locations[FindLocation(deckID)], "image")) SendMessage(&boarding_fader, "ls", FADER_PICTURE, FindReloadPicture(Locations[FindLocation(DeckID)].image));
	SendMessage(&boarding_fader, "lfl", FADER_OUT, 1.0, false);
	SendMessage(&boarding_fader, "l", FADER_STARTFRAME);

	PauseAllSounds();
	ResetSoundScheme();

	bAbordageStarted = true;
	bCabinStarted = true;
	bCrewStarted = false;
	bDeckStarted = false;
	Sea.AbordageMode = true;
	mchr.IsOnDeck = true;
}

void LandCabin_ReloadStartFade()
{
	ref mchr = GetMainCharacter();
	if (FindLocation(mchr.location) >= 0) UnloadLocation(&Locations[FindLocation(mchr.location)]);

	DelEventHandler("FaderEvent_StartFade", "LandCabin_ReloadStartFade");
}

void LandCabin_ReloadEndFade()
{
	int a = GetEventData();
	boarding_fader = GetEventData();

	Cabin_Start();

	if (CheckAttribute(Sea, "MaxSeaHeight")) {
		fOldMaxSeaHeight = stf(Sea.MaxSeaHeight);
		Sea.MaxSeaHeight = 1.15;
	}

	DelEventHandler("FaderEvent_EndFade", "LandCabin_ReloadEndFade");
	SendMessage(&boarding_fader, "lfl", FADER_IN, RELOAD_TIME_FADE_IN, true);
}
// <-- KK

//MAXIMUS -->
void PlaceOfficersToDeck(string deckType)
{
	ref mchr = GetMainCharacter();
	ref tmpChr;
	int i, _curCharIdx, logined;
	aref pRef; makearef(pRef,mchr.Fellows.Passengers);
	string PsgAttrName;
	ref rShipCaptain = GetCharacter(iShipCaptain); // KK

	switch(deckType)
	{
		case "Deck":
			logined = 1;
// KK -->
			if (iShipCaptain == GetMainCharacterIndex()) {
				for (i = 1; i <= GetPassengersQuantity(mchr); i++)
				{
					PsgAttrName = "id"+i;
					_curCharIdx = sti(pRef.(PsgAttrName));
					tmpChr = GetCharacter(_curCharIdx);
					if(!CheckAttribute(tmpChr,"prisoned") && CheckAttribute(tmpChr,"quest.officertype"))
					{
						switch(FindCurrentDeck())
						{
							case "CannonsDeck":
								if(tmpChr.quest.officertype==OFFIC_TYPE_CANNONEER)
								{
									CharacterIntoLocationLocator(_curCharIdx, mchr.location);
									LAi_SetCivilianPatrolType(tmpChr);
								}
							break;
							case "Hold":
								if(tmpChr.quest.officertype==OFFIC_TYPE_CARPENTER)
								{
									CharacterIntoLocationLocator(_curCharIdx, mchr.location);
									LAi_SetCivilianPatrolType(tmpChr);
								}
							break;
							case "ShipDeck":
								if(GetCharacterShipCabin(mchr)=="Cabin_none")
								{
									CharacterIntoLocationLocator(_curCharIdx, mchr.location);
									LAi_SetCivilianPatrolType(tmpChr);
								}
								else
								{
									if(tmpChr.quest.officertype==OFFIC_TYPE_ABORDAGE || tmpChr.quest.officertype==OFFIC_TYPE_CANNONEER || tmpChr.quest.officertype==OFFIC_TYPE_CAPNAVY || tmpChr.quest.officertype==OFFIC_TYPE_QMASTER) // KK - PW added QM
									{
										CharacterIntoLocationLocator(_curCharIdx, mchr.location);
										LAi_SetCivilianPatrolType(tmpChr);
									}
								}
							break;
							case "Seadogs":
								if(tmpChr.quest.officertype==OFFIC_TYPE_BOATSWAIN || tmpChr.quest.officertype==OFFIC_TYPE_DOCTOR || tmpChr.quest.officertype==OFFIC_TYPE_QMASTER || tmpChr.quest.officertype==OFFIC_TYPE_ABORDAGE)
								{
									CharacterIntoLocationLocator(_curCharIdx, mchr.location);
									LAi_SetCivilianPatrolType(tmpChr);
								}
							break;
						}
					}
				}
			} else {
				for (i = 1; i < 7; i++)
				{
					if (i < OFFICER_MAX)
						_curCharIdx = GetOfficersIndex(rShipCaptain, i);
					else
						_curCharIdx = GetOfficersIndex(mchr, i - OFFICER_MAX+1);
					if (_curCharIdx < 0) continue;
					tmpChr = GetCharacter(_curCharIdx);
					if(!CheckAttribute(tmpChr,"prisoned") && CheckAttribute(tmpChr,"quest.officertype"))
					{
						switch(FindCurrentDeck())
						{
							case "CannonsDeck":
								if(tmpChr.quest.officertype==OFFIC_TYPE_CANNONEER)
								{
									CharacterIntoLocationLocator(_curCharIdx, mchr.location);
									LAi_SetCivilianPatrolType(tmpChr);
								}
							break;
							case "Hold":
								if(tmpChr.quest.officertype==OFFIC_TYPE_CARPENTER)
								{
									CharacterIntoLocationLocator(_curCharIdx, mchr.location);
									LAi_SetCivilianPatrolType(tmpChr);
								}
							break;
							case "ShipDeck":
								if(GetCharacterShipCabin(rShipCaptain)=="Cabin_none")
								{
									CharacterIntoLocationLocator(_curCharIdx, mchr.location);
									LAi_SetCivilianPatrolType(tmpChr);
								}
								else
								{
									if(tmpChr.quest.officertype==OFFIC_TYPE_ABORDAGE || tmpChr.quest.officertype==OFFIC_TYPE_CANNONEER || tmpChr.quest.officertype==OFFIC_TYPE_CAPNAVY || tmpChr.quest.officertype==OFFIC_TYPE_QMASTER) // KK - PW added QM
									{
										CharacterIntoLocationLocator(_curCharIdx, mchr.location);
										LAi_SetCivilianPatrolType(tmpChr);
									}
								}
							break;
							case "Seadogs":
								if(tmpChr.quest.officertype==OFFIC_TYPE_BOATSWAIN || tmpChr.quest.officertype==OFFIC_TYPE_DOCTOR || tmpChr.quest.officertype==OFFIC_TYPE_QMASTER || tmpChr.quest.officertype==OFFIC_TYPE_ABORDAGE)
								{
									CharacterIntoLocationLocator(_curCharIdx, mchr.location);
									LAi_SetCivilianPatrolType(tmpChr);
								}
							break;
						}
					}
				}
			}
// <-- KK
			PostEvent("SetAnotherType", 2500 , "i", mchr);
		break;

		case "Cabin":
			logined = 1;
// KK -->
			for (i = 1; i < COMPANION_MAX; i++) {
				_curCharIdx = GetCompanionIndex(mchr, i);
				if (_curCharIdx < 0) continue;
				ChangeCharacterAddressGroup(GetCharacter(_curCharIdx), "None", "", "");
			}

			bool bPlace = false;
			if (iShipCaptain != GetMainCharacterIndex()) {
				CharacterIntoLocationLocator(iShipCaptain, mchr.location);
				ChangeCharacterAddressGroup(rShipCaptain, mchr.location, "rld", "startloc");
				LAi_SetStayTypeNoGroup(rShipCaptain);
				logined++;
				for (i = 1; i < OFFICER_MAX; i++) {
					_curCharIdx = GetOfficersIndex(rShipCaptain, i);
					if (_curCharIdx < 0) continue;
					tmpChr = GetCharacter(_curCharIdx);
					ChangeCharacterAddressGroup(tmpChr, "None", "", "");
					CharacterIntoLocationLocator(_curCharIdx, mchr.location);
					logined++;
				}
			}
			if (mchr.location == "Cabin_small" && logined > 2) break;
// <-- KK
			for(i = 1; i < OFFICER_MAX; i++)
			{
				_curCharIdx = GetOfficersIndex(mchr, i);
				if(_curCharIdx < 0) continue;
				tmpChr = GetCharacter(_curCharIdx);
				if(CheckAttribute(tmpChr,"quest.officertype"))
				{
					bPlace = false;
					switch(Rand(4))
					{
						case 0: bPlace = tmpChr.quest.officertype==OFFIC_TYPE_FIRSTMATE; break;
						case 1: bPlace = tmpChr.quest.officertype==OFFIC_TYPE_NAVIGATOR; break;
						case 2: bPlace = tmpChr.quest.officertype==OFFIC_TYPE_BOATSWAIN; break;
						case 3: bPlace = tmpChr.quest.officertype==OFFIC_TYPE_QMASTER; break;
						case 4: bPlace = tmpChr.quest.officertype==OFFIC_TYPE_DOCTOR; break;
						// Aconcagua: TODO: whatabout the other officertypes???
						// PB: They are placed at different deck locations as defined above in this file
					}
					if(DEBUG_EXPERIENCE>0) TraceAndLog("PlaceOfficersToDeck: Set officer type for " + GetMySimpleName(tmpChr));
				//	tmpChr.quest.officertype = GetRandomOfficerType(); //Levis let's use a global function so we can easily add types later. - PB: Don't do this here
					if(bPlace)
					{
						ChangeCharacterAddressGroup(tmpChr, "None", "", "");
						CharacterIntoLocationLocator(_curCharIdx, mchr.location);
						logined++;
					}
// KK -->
					if (mchr.location == "Cabin_small" && logined > 2) break;
					if(!IsOfficer(tmpChr)) continue;
					CharacterIntoLocationLocator(_curCharIdx, mchr.location);
// <-- KK
				}
			}
		break;
	}
	for(i=1; i<GetPassengersQuantity(mchr); i++)
	{
		PsgAttrName = "id"+(i+1);
		_curCharIdx = sti(pRef.(PsgAttrName));
		tmpChr = GetCharacter(_curCharIdx);
		if(IsOfficer(tmpChr)) continue;
		if(!CheckAttribute(tmpChr,"prisoned") && CheckAttribute(tmpChr,"quest.officertype"))
		{
			LAi_ClearIndexedLocators(mchr.location, tmpChr.location.group);
		}
	}
}

#event_handler("SetAnotherType", "AnotherType");
void AnotherType()
{
	ref mchr = GetMainCharacter();
	for(int i=1; i<GetPassengersQuantity(mchr); i++)
	{
		aref pRef; makearef(pRef,mchr.Fellows.Passengers);
		string PsgAttrName = "id"+(i+1);
		int _curCharIdx = sti(pRef.(PsgAttrName));
		ref tmpChr = GetCharacter(_curCharIdx);
		if(IsOfficer(tmpChr)) continue;
		if(!CheckAttribute(tmpChr,"prisoned") && CheckAttribute(tmpChr,"quest.officertype"))
		{
			LAi_SetCitizenType(tmpChr);
		}
	}
}
//MAXIMUS <--

void KAM_Mutiny()
{
//MAXIMUS: new "Mutiny" -->
	if (GetCrewQuantity(GetMainCharacter()) > 0) {
		Log_SetStringToLog(XI_ConvertString("MUTINY") + "!");
		if (bSeaActive && IsEntity(&worldMap))
			LaunchMutinyScreen();
		else
			PostEvent("StartMutiny", 2500, "1", 0);
	}
//MAXIMUS: new "Mutiny" <--
}
