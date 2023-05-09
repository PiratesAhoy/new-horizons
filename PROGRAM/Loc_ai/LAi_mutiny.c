bool	bMutinyDeckStarted = false;

void MutinyDeck_ReloadStartFade()
{
	int a = GetEventData();
	boarding_fader = GetEventData();
	LayerFreeze(SEA_EXECUTE,true);
	LayerFreeze(SEA_REALIZE,true);
	LayerFreeze(SEA_REFLECTION,true);
	LayerFreeze(EXECUTE,false);
	LayerFreeze(REALIZE,false);

	MoveWeatherToLayers(EXECUTE, REALIZE);
	MoveSeaToLayers(EXECUTE, REALIZE);

	SendMessage(&AIBalls, "l", MSG_MODEL_RELEASE);

	DelEventHandler("FaderEvent_StartFade", "MutinyDeck_ReloadStartFade");

	fOldMaxSeaHeight = stf(Sea.MaxSeaHeight);
	Sea.MaxSeaHeight = 1.2;
	ref lcn = &Locations[FindLocation(DeckID)];
	if(CheckAttribute(lcn,"MaxSeaHeight")) Sea.MaxSeaHeight = stf(lcn.MaxSeaHeight); // screwface : limit wave height
}

void Return2SeaAfterMutinyDeck()
{
// KK -->
	ref PChar = GetMainCharacter();
	if (CheckAttribute(PChar, "Mutiny")) DeleteAttribute(PChar, "Mutiny");
// <-- KK
	//Установить хендлеры для обработки
	SetEventHandler("FaderEvent_StartFade", "MutinyDeck_ReloadStartFadeAfter", 0);
	SetEventHandler("FaderEvent_EndFade", "MutinyDeck_ReloadEndFadeAfter", 0);
	//Создаём фейдер и запускаем
	CreateEntity(&boarding_fader, "fader");
	SetReloadImage(&boarding_fader, "sea"); // KK

	float fadeOutTime = RELOAD_TIME_FADE_OUT;
	
	SendMessage(&boarding_fader, "lfl", FADER_OUT, fadeOutTime, false);
	SendMessage(&boarding_fader, "l", FADER_STARTFRAME);
	if (CheckAttribute(PChar, "IsOnDeck")) DeleteAttribute(PChar, "IsOnDeck"); // KK
	bDisableFastReload = false;
}

void MutinyDeck_ReloadEndFade()
{
	// Delete current cannonballs
	AIBalls.Clear = "";

	ReleaseShipModels();

	PauseParticles(true);

	// start location
	int a = GetEventData();
	boarding_fader = GetEventData();

	MutinyDeck_Start();
	
	DelEventHandler("FaderEvent_EndFade", "MutinyDeck_ReloadEndFade");
	SendMessage(&boarding_fader, "lfl", FADER_IN, RELOAD_TIME_FADE_IN, true);
}

#event_handler("Sea_StartMutiny", "Sea_MutinyDeckStartNow");
void Sea_MutinyDeckStartNow()
{
	if(!bMutinyDeckStarted)
	{
// KK -->
		if (isEntity(&WorldMap) != 0) {
			PrepareMutinyDeck();
		
			if(sti(GetStorylineVar(FindCurrentStoryline(), "DISABLE_TIPS")) < 1) SetReloadNextTipsImage(); // JRH
		
			//Fade out
			SetEventHandler("FaderEvent_StartFade", "MutinyDeck_WorldmapReloadStartFade", 0);
			SetEventHandler("FaderEvent_EndFade", "MutinyDeck_WorldmapReloadEndFade", 0);
			wdm_fader.thisWorldMapFader = "";
			CreateEntity(&wdm_fader, "fader");
			if(IsEntity(wdm_fader) == 0) Trace("Fader not created!!!");	
			float fadeOutTime = 0.5;
			SendMessage(&wdm_fader, "lfl", FADER_OUT, fadeOutTime, true);
			SendMessage(&wdm_fader, "l", FADER_STARTFRAME);
			SetReloadImage(&wdm_fader, "Mutiny");

			PauseAllSounds();
			ResetSoundScheme();
		} else {
			bSeaReloadStarted = true;

			// KK object boarding_fader;
			CreateEntity(&boarding_fader, "fader");
			SetEventHandler("FaderEvent_StartFade", "MutinyDeck_ReloadStartFade", 0);
			SetEventHandler("FaderEvent_EndFade", "MutinyDeck_ReloadEndFade", 0);

			SetReloadImage(&boarding_fader, "Mutiny"); // KK

			SendMessage(&boarding_fader, "lfl", FADER_OUT, 1.0, false);
			SendMessage(&boarding_fader, "l", FADER_STARTFRAME);

			PauseAllSounds();
			ResetSoundScheme();
		}
// <-- KK

		bAbordageStarted = true;
		bMutinyDeckStarted = true;
		Sea.AbordageMode = true;
		ref PChar = GetMainCharacter();
		PChar.IsOnDeck = true;
		bDisableFastReload = true;
	}
	else
	{
// KK -->
		if (bSeaActive)
			Return2SeaAfterMutinyDeck();
		else
			Return2WorldMapAfterMutinyDeck();
// <-- KK
	}
}

void MutinyDeck_Start()
{
	ResetSoundScheme();
	PauseAllSounds();
	int i, idx;
	//Настроим интерфейс
	DeleteBattleInterface();
	StartBattleLandInterface();
	
	ref mchr = GetMainCharacter();
// KK -->
	int locID = FindLocation("MUTINY_Deck");
	if(locID < 0) {
		Trace("Boarding: ship location not found <MUTINY_Deck>, set default");
		return;
	}
	ref rDeck; makeref(rDeck, Locations[locID]);
	DeleteAttribute(rDeck, "");
	string QDeck = GetCharacterShipQDeck(mchr);
	ref rQDeck;
	switch (QDeck) {
		case "ShipDeck1":
			makeref(rQDeck, Locations[FindLocation("ShipDeck1")]);
			CopyAttributes(rDeck, rQDeck);
			rDeck.models.always.locators = "qdeck_l";
		break;
		// default:
			makeref(rQDeck, Locations[FindLocation("BOARDING_" + QDeck)]);
			CopyAttributes(rDeck, rQDeck);
	}
	rdeck.index = locID;
	rdeck.id = "MUTINY_Deck";
	rDeck.id.label = "Boarding deck";
// <-- KK

	//Выставим  и запомним адреса
	boarding_adr[0].location = mchr.location;
	boarding_adr[0].group = mchr.location.group;
	boarding_adr[0].locator = mchr.location.locator;
	for (i = 1; i < OFFICER_MAX; i++)
	{
		idx = GetOfficersIndex(mchr, i);
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
	MutinyDeck_LoadLocation("MUTINY_Deck");		// LDH set the correct deck for this - 09Mar09
}

//Загрузить локацию - Loading location
void MutinyDeck_LoadLocation(string locationID)
{
	ReloadProgressStart();
	//Ищем локацию - Search for location
	int locIndex = FindLocation(locationID);
	Log_SetActiveAction("Nothing");
	if(locIndex >= 0)
	{
// KK -->
		string chLocType = "rld";
		string chLocLoc = "aloc";

		//Устанавливаем главного персонажа - Sets main character
		ref mchr = GetMainCharacter();
		mchr.location = locationID;
		mchr.location.group = chLocType;
		mchr.location.locator = "aloc0";
// <-- KK

		//Перегружаемся в локацию - Reloading to location
		boarding_location = locIndex;
		Locations[locIndex].boarding = "true";
		if (LoadLocation(&Locations[locIndex])) {
// KK -->
			int i = 0;
			int pos = 1;
			int idx;
			int nPassengers = GetPassengersQuantity(mchr);
			ref chr;
			//int mutinyOfficersQuantity = 0;
			while (i < nPassengers)
			{
				idx = GetPassenger(mchr, i);
				if (idx < 0) { i++; continue; }
				chr = GetCharacter(idx);
				if (IsOfficerCompanion(chr)) { i++; continue; }
				if (GetCharacterReputation(chr) <= (REPUTATION_SWINDLER + 5)) { i++; continue; }
				ChangeCharacterAddressGroup(chr, locationID, chLocType, "aloc" + pos);
trace("Officer "+GetMySimpleName(chr)+" on "+chLocType+":"+chr.location.locator);
				//chr.location.Ship = true;
				pos++;
				i++;
			}
			BLI_UpdateOfficers();
			//Вытащим саблю - Prepares to fight
			SendMessage(&mchr, "lsl", MSG_CHARACTER_EX_MSG, "SetFightMode", 1);
			LAi_SetCurHPMax(mchr);
			//Запретим диалог - Disables dialogs
			dialogDisable = false;
			//Установим бойцов - Sets fighters
			string model, ani;
			float crewRatio = rand(10) / 10.0;
			int actTotal = GetBoardingLimit(locIndex) * makeint(stf(mchr.Ship.Crew.Quantity) / GetMaxCrewQuantity(mchr));
			int actMutiny = makeint(crewRatio * actTotal);
			int actLoyal = makeint((1.0 - crewRatio) * actTotal);
			mchr.Ship.Crew.Quantity = makeint(stf(mchr.Ship.Crew.Quantity) * (1.0 - crewRatio));
			if (sti(mchr.Ship.Crew.Quantity) < 0) mchr.Ship.Crew.Quantity = 0;
			/*int maxActors = 
			if (actTotal > maxActors) {
				actTotal = maxActors;
				actLoyal = makeint(actTotal * crewRatio);
				actMutiny = makeint(actTotal * (1.0 - crewRatio));
			}*/
			if (actLoyal <= 0) actLoyal = 0;
			if (actMutiny <= 0) actMutiny = 2;
			actTotal = actLoyal + actMutiny;
trace("crewRatio="+crewRatio+", actLoyal="+actLoyal+", actMutiny="+actMutiny+", actTotal="+actTotal);
			int money = sti(mchr.money) / actMutiny;
			float chrHP;
			while (i < actLoyal)
			{
				model = LAi_GetBoardingModel(mchr, "");
				chr = LAi_CreateFantomCharacterEx(true, 0, true, true, 0.25, model,  chLocType, chLocLoc + pos);
				if(SendMessage(chr, "lss", MSG_CHARACTER_ENTRY_TO_LOCATION, chLocType, chLocLoc + pos)==false)
				{
					DeleteCharacter(chr);
					chr = LAi_CreateFantomCharacterEx(true, 0, true, true, 0.25, model,  chLocType, chLocLoc + pos);
				}
				LAi_group_MoveCharacter(chr, LAI_GROUP_PLAYER);
				chrHP = makeint(LAi_GetCharacterMaxHP(mchr) / actLoyal);
				LAi_SetCurHP(chr, chrHP);//Sets an actual HP
				SetRandomNameToCharacter(chr);
				chr.nation = mchr.nation;

				chr.wealth = "0";
				pos++;
				i++;
			}
			chLocLoc = "loc";
			int iMutinyCommander = -1;
			i = 0;
			pos = 0;
			//if (nPassengers > actMutiny) nPassengers = actMutiny;
			while (i < nPassengers)
			{
				idx = GetPassenger(mchr, i);
				if (idx < 0) { i++; continue; }
				chr = GetCharacter(idx);
				if (IsOfficerCompanion(chr)) { i++; continue; }
				if (!CheckAttribute(chr, "quest.officertype")) { i++; continue; }
				if (GetCharacterReputation(chr) > (REPUTATION_SWINDLER + 5)) { i++; continue; }
				RemovePassenger(mchr, chr);
				nPassengers--;
				i--;
				model = chr.model;
				ani = chr.model.animation;
				string name = chr.name;
				string middlename = "";
				if (CheckAttribute(chr, "middlename")) middlename = chr.middlename;
				string lastname = chr.lastname;
				chrHP = stf(chr.chr_ai.hp);
				LAi_KillCharacter(chr);
				chr = LAi_CreateFantomCharacterEx(true, 0, true, true, 0.25, model, chLocType, chLocLoc + pos);
				if(SendMessage(chr, "lss", MSG_CHARACTER_ENTRY_TO_LOCATION, chLocType, chLocLoc + pos)==false)
				{
					DeleteCharacter(chr);
					chr = LAi_CreateFantomCharacterEx(true, 0, true, true, 0.25, model, chLocType, chLocLoc + pos);
				}
				LAi_group_MoveCharacter(chr, LAI_GROUP_BRDENEMY);
				LAi_SetCurHP(chr, chrHP);//Sets an actual HP
				chr.old.name = name;
				chr.old.lastname = lastname;
				chr.name = name;
				chr.lastname = lastname;
				if (middlename != "") {
					chr.old.middlename = middlename;
					chr.middlename = middlename;
				}
				chr.nation = PIRATE;

				// LDH give the character part of the accumulated loot - 09Mar09
				chr.money = money/2 + rand(money/2);
				AddMoneyToCharacter(mchr, -sti(chr.money));
				// LDH this is way too much and never subtracted from player who ends up with 100 times his original amount

				if (iMutinyCommander == -1) iMutinyCommander = idx;
				trace("Ex officer "+GetMySimpleName(chr)+" on "+chLocType+":"+(chLocLoc+pos));
				if (iMutinyCommander == idx) trace("... and becomes commander of the mutiny");

				pos++;
				i++;
				if (i > actMutiny) break;
			}

			while (pos < actMutiny)
			{
				model = LAi_GetBoardingModel(mchr, "");
				chr = LAi_CreateFantomCharacterEx(true, 0, true, true, 0.25, model, chLocType, chLocLoc + pos);
				if(SendMessage(chr, "lss", MSG_CHARACTER_ENTRY_TO_LOCATION, chLocType, chLocLoc + pos)==false)
				{
					DeleteCharacter(chr);
					chr = LAi_CreateFantomCharacterEx(true, 0, true, true, 0.25, model, chLocType, chLocLoc + pos);
				}
				LAi_group_MoveCharacter(chr, LAI_GROUP_BRDENEMY);
				chrHP = makeint(LAi_GetCharacterMaxHP(mchr) / actMutiny);//calculate an actual HP (from rebels amount)
				LAi_SetCurHP(chr, chrHP);//Sets an actual HP
				SetRandomNameToCharacter(chr);
				chr.nation = PIRATE;

				// LDH give the character part of the accumulated loot - 09Mar09
				chr.money = money/2 + rand(money/2);
				AddMoneyToCharacter(mchr, -sti(chr.money));
				// LDH this is way too much and never subtracted from player who ends up with 100 times his original amount

				chr.wealth = "0";
				pos++;
			}
			LAi_group_FightGroupsEx(LAI_GROUP_PLAYER, LAI_GROUP_BRDENEMY, true, GetMainCharacterIndex(), iMutinyCommander, false, false);
			LAi_QuestDelay("Abordage_Quest", 0.0); // KK was: LAi_group_SetCheckEvent(LAI_GROUP_BRDENEMY);
// <-- KK
		} else {
			Trace("LAi_mutiny.c: Location not loaded, current loc <" + locationID + ">");
		}
	} else {
		Trace("LAi_mutiny.c: Location not found, current loc <" + locationID + ">");
	}
	PlaySound("AMBIENT\UnHappy-002.wav");
	// KK TeleportCharacterFromCurLocationToLocation(mchr.location,mchr.location.group,mchr.location.locator);
	LAi_QuestDelay("Abordage_Quest", 0.0); // KK
	ReloadProgressEnd();
	PostEvent("LoadSceneSound", 500);
}

#event_handler("LAi_event_mutiny_EnableReload", "LAi_EnableReloadAfterMutiny"); // KK
void LAi_EnableReloadAfterMutiny() // KK
{
	ref mchr = GetMainCharacter();
	SetEventHandler("Control Activation","LAi_Activate_Reload",1);
	//if(FindLoadedLocation()!=-1) CheckCharacterAction();

	mchr.boardingReload = true; // KK

	SendMessage(&mchr, "lsl", MSG_CHARACTER_EX_MSG, "ChangeFightMode", 0);
}

void LAi_Activate_Reload()
{
	string controlName = GetEventData();
	if (controlName != "ChrAction") return;
	int tmpi = SendMessage(GetMainCharacter(),"ls",MSG_CHARACTER_EX_MSG,"FindDialogCharacter");
	if (tmpi>=0) {
		if (CheckAttribute(GetCharacter(tmpi), "Dialog.Filename") && !CheckAttribute(GetCharacter(tmpi), "corpse")) {
			Event("dlgReady","l",tmpi);
		} else {
			DelEventHandler("Control Activation", "LAi_Activate_Reload");
			Log_SetActiveAction("Nothing");
// KK -->
			if (bSeaActive)
				Return2SeaAfterMutinyDeck();
			else
				Return2WorldMapAfterMutinyDeck();
// <-- KK
		}
	} else {
		DelEventHandler("Control Activation", "LAi_Activate_Reload");
		Log_SetActiveAction("Nothing");
// KK -->
		if (bSeaActive)
			Return2SeaAfterMutinyDeck();
		else
			Return2WorldMapAfterMutinyDeck();
// <-- KK
	}
}

void MutinyDeck_ReloadStartFadeAfter()
{
	ResetSoundScheme();
	PauseAllSounds();
	DelEventHandler("FaderEvent_StartFade", "MutinyDeck_ReloadStartFadeAfter");
	if(boarding_location >= 0) UnloadLocation(&Locations[boarding_location]);
}

void MutinyDeck_ReloadEndFadeAfter()
{
//================================================================================//
//============================| FINALISATION PROCESS |============================//
//================================================================================//
	ReloadProgressStart();
	DelEventHandler("FaderEvent_EndFade", "MutinyDeck_ReloadEndFadeAfter");
	SendMessage(&boarding_fader, "lfl", FADER_IN, RELOAD_TIME_FADE_IN, true);
//============================| next location is not present |============================//
	boarding_location = -1;
//============================| interface prepare |============================//
	Log_SetActiveAction("Nothing");
	EndBattleLandInterface();
//============================| adresses returns |============================//
	ref mchr = GetMainCharacter();
	int i, idx;
	mchr.location = boarding_adr[0].location;
	mchr.location.group = boarding_adr[0].group;
	mchr.location.locator = boarding_adr[0].locator;
	for (i = 1; i < OFFICER_MAX; i++)
	{
		idx = GetOfficersIndex(mchr, i);
		if(idx < 0) continue;
		Characters[idx].location = boarding_adr[i].location;
		Characters[idx].location.group = boarding_adr[i].group;
		Characters[idx].location.locator = boarding_adr[i].locator;
		// KK if(CheckAttribute(Characters[idx],"location.Ship")) { DeleteAttribute(Characters[idx],"location.Ship"); }
	}
//============================| unloading to the interface |============================//
	if(CheckAttribute(mchr,"Mutiny")) { DeleteAttribute(mchr,"Mutiny"); }
	mchr.Ship.Crew.Morale = sti(mchr.Ship.Crew.Morale) + 30;

	RestoreShipModels();

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
	bSeaReloadStarted = false;
	bMutinyDeckStarted = false;
	chrWaitReloadLocator = "";

	InitBattleInterface();
	StartBattleInterface();
	RefreshBattleInterface(true);
	SetSchemeForSea();

	PauseParticles(false);
	Whr_UpdateWeather(false);

	ReloadProgressEnd();
}

#event_handler("StartFight", "FightWithCrew");
void FightWithCrew()
{
	ref mchr = GetMainCharacter();
	//Sets fighters
	string ani, curLocator;
	int actMutiny = makeint(GetCrewQuantity(mchr) / 3.0);
	curLocator = LAi_FindFirstLocationLocator(mchr.location, "reload");
	if (actMutiny > 10) {
		if (CheckAttribute(locations[FindLoadedLocation()], "models.back")) {
			actMutiny = 5;
			LAi_LocationFightDisable(&Locations[FindLoadedLocation()], false);
			mchr.mutiny.location = locations[FindLoadedLocation()].id;
		} else {
			actMutiny = 10;
		}
	}
	if(actMutiny<=0) actMutiny = 2;
	int money = sti(mchr.money) / actMutiny;

	for(int brd = 0; brd<actMutiny; brd++)
	{
		string model = LAi_GetBoardingModel(GetMainCharacter(), "");
		ref chr = LAi_CreateFantomCharacterEx(true, 0, true, true, 0.25, model, "reload", curLocator);
		LAi_group_MoveCharacter(chr, LAI_GROUP_BRDENEMY);
		int chrHP = makeint(LAi_GetCharacterMaxHP(chr));//calculate an actual HP (from rebels amount)
		LAi_SetCurHP(chr, chrHP);//Sets an actual HP
		chr.old.name = "Crewmember";
		chr.old.lastname = "";
		chr.name = XI_ConvertString("Crewmember");
		chr.lastname = "";
		chr.nation = sti(mchr.nation);

		// LDH give the character part of the accumulated loot - 09Mar09
		chr.money = money/2 + rand(money/2);
		AddMoneyToCharacter(mchr, -sti(chr.money));
		// LDH this is way too much and never subtracted from player who ends up with 100 times his original amount

		chr.wealth = "0";
	}
	PlaySound("AMBIENT\UnHappy-002.wav");
	LAi_group_FightGroupsEx(LAI_GROUP_PLAYER, LAI_GROUP_BRDENEMY, true, GetMainCharacterIndex(), -1, false, false);
	LAi_QuestDelay("Abordage_Quest", 0.0); // KK was: LAi_group_SetCheckEvent(LAI_GROUP_BRDENEMY);
	if(CheckAttribute(locations[FindLoadedLocation()],"models.back")) { PostEvent("AfterFight", 5000, "1", 0); }
}

int GetCrewMemberPayment()
{
	ref PChar = GetMainCharacter();

	int PerkIron = CheckPerkForSingleCharacter(pchar,"IronWill");
	int skillLead = CalcCharacterSkill(pchar,SKILL_LEADERSHIP);
	int skillLuck = CalcCharacterSkill(pchar,SKILL_SNEAK);
	float moralemod = ( (skillLead*2.0 + skillLuck + PerkIron*5.0)/30.0 / 4.0 * (1.0+(PerkIron/4.0)));
	float lastcsr = 1.0;
	if(CheckAttribute(pchar,"Crewstatus.lastcsr")) lastcsr = stf(pchar.CrewStatus.lastcsr);
	//unclamp lastcsr
	if(lastcsr > 1.0) lastcsr = 1/(2-lastcsr);
	int explength = 0;
	if(CheckAttribute(pchar,"CrewStatus.explength")) explength = sti(pchar.CrewStatus.explength);
	else pchar.CrewStatus.explength = 0;
	int norm_morale = 100;
	float xl_csr_scale = 1.0;
	if(explength <= (NORMAL_EXP_LENGTH * EXP_LENGTH_START_FRAC)) { xl_csr_scale += (((NORMAL_EXP_LENGTH * EXP_LENGTH_START_FRAC) - explength) / (NORMAL_EXP_LENGTH * 1/2)) * 3.0; }

	//check loot and explength and deal with it
	float  csr = ((5.0-xl_csr_scale)*GetCrewShareRatio(pchar) + xl_csr_scale * lastcsr)/5.0;
	//temp
	csr = 0.25 + explength/NORMAL_EXP_LENGTH;
	//adjust for explength
	csr *= (10*pow(2.71828182845905,-3.256 * explength / NORMAL_EXP_LENGTH)) * (1.0+(moralemod)/2);

	return makeint(sti(PChar.money)*stf(csr*0.01));
}

#event_handler("AfterFight", "CheckMutinyLocation");
void CheckMutinyLocation()
{
	ref mchr = GetMainCharacter();
	if(CheckAttribute(mchr,"mutiny.location"))
	{
		LAi_LocationFightDisable(&Locations[FindLocation(mchr.mutiny.location)], true);
		DeleteAttribute(mchr,"mutiny.location");
	}
}

// KK -->
void PrepareMutinyDeck()
{
	int i;

	ref mchr = GetMainCharacter();
// KK -->
	int locID = FindLocation("MUTINY_Deck");
	if(locID < 0) {
		Trace("Boarding: ship location not found <MUTINY_Deck>, set default");
		return;
	}
	ref rDeck; makeref(rDeck, Locations[locID]);
	DeleteAttribute(rDeck, "");
	string QDeck = GetCharacterShipQDeck(mchr);
	ref rQDeck;
	switch (QDeck) {
		case "ShipDeck1":
			makeref(rQDeck, Locations[FindLocation("ShipDeck1")]);
			CopyAttributes(rDeck, rQDeck);
			rDeck.models.always.locators = "qdeck_l";
		break;
		// default:
			makeref(rQDeck, Locations[FindLocation("BOARDING_" + QDeck)]);
			CopyAttributes(rDeck, rQDeck);
	}
	rdeck.index = locID;
	rdeck.id = "MUTINY_Deck";
	rDeck.id.label = "Boarding deck";
	rDeck.image = FindReloadPicture("Mutiny"); // PB: was "Mutiny.tga";
// <-- KK
}

void MutinyDeck_WorldmapReloadStartFade()
{
	PauseAllSounds();
// NK -->
	ref mc = GetMainCharacter();

	ResetTimeToNormal();//MAXIMUS: removes time-acceleration and sets normal time

	mc.ShipEnc = "none";

	mc.location = "MUTINY_Deck";
	mc.location.group = "rld";
	mc.location.locator = "aloc0";
	//Delete EventHandler
	DelEventHandler("FaderEvent_StartFade", "MutinyDeck_WorldmapReloadStartFade");
	//Delete entity
	worldMap.playerShipUpdate = "";
	DeleteClass(&worldMap);
	worldMap.isLoaded = "false";
}

void MutinyDeck_WorldmapReloadEndFade()
{
	int a = GetEventData();
	wdm_fader = GetEventData();

	wdmDisableRelease = true;
	//Delete EventHandler
	DelEventHandler("FaderEvent_EndFade", "MutinyDeck_WorldmapReloadEndFade");
	SendMessage(&wdm_fader, "lfl", FADER_IN, RELOAD_TIME_FADE_IN, true);

	MutinyDeck_LoadLocation("MUTINY_Deck");
	lockedReloadLocator = "";
	chrWaitReloadLocator = "";
	chrWaitReloadIsNoLink = false;
}

void Return2WorldMapAfterMutinyDeck()
{
	ref mchr = GetMainCharacter();
	if (CheckAttribute(mchr, "Mutiny")) DeleteAttribute(mchr, "Mutiny");
	if (CheckAttribute(mchr, "IsOnDeck")) DeleteAttribute(GetMainCharacter(),"IsOnDeck");
	bDisableFastReload = false;
	Sea.MaxSeaHeight = fOldMaxSeaHeight;		// restore old MaxSeaHeight
	bAbordageStarted = false;
	Sea.AbordageMode = false;
	bSeaReloadStarted = false;
	bMutinyDeckStarted = false;
	chrWaitReloadLocator = "";
	mchr.Ship.Crew.Morale = sti(mchr.Ship.Crew.Morale) + 30;
	Land_MapLoad();
}
// <-- KK
