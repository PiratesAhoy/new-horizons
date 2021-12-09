


bool wdmDisableRelease = true;

//=========================================================================================
//Events
//=========================================================================================

void wdmEvent_EncounterCreate()
{
	float dltTime = GetEventData();
	float playerShipX = GetEventData();
	float playerShipZ = GetEventData();
	float playerShipAY = GetEventData();
	//Save player ship position
	worldMap.playerShipX = playerShipX;
	worldMap.playerShipZ = playerShipZ;
	worldMap.playerShipAY = playerShipAY;

	// trace("Encounter Create - wdmCurrentIsland: " + wdmCurrentIsland + " Logical: " + (wdmCurrentIsland != ""));
	if(wdmCurrentIsland != WDM_NONE_ISLAND) // PB: Prevent error.log entries
	{
		wdmLoginToSea.island = worldMap.islands.(wdmCurrentIsland).name;
		float ix = MakeFloat(worldMap.islands.(wdmCurrentIsland).position.rx);
		float iz = MakeFloat(worldMap.islands.(wdmCurrentIsland).position.rz);
		worldMap.playerShipDispX = (playerShipX - ix);
		worldMap.playerShipDispZ = (playerShipZ - iz);
	}else{
		worldMap.playerShipDispX = 0.0;
		worldMap.playerShipDispZ = 0.0;
	}
	//Skip encounters
	if(CheckAttribute(worldMap, "noenc") != 0)
	{
		if(worldMap.noenc == "true") return;
	}
	//Generate encounters
	wdmStormGen(dltTime, playerShipX, playerShipZ, playerShipAY);
	wdmShipEncounter(dltTime, playerShipX, playerShipZ, playerShipAY);
	wdmQuestShipEncounter(dltTime, playerShipX, playerShipZ, playerShipAY);
}

void wdmEvent_InsideIsland()
{
	wdmDisableTornadoGen = true;
	wdmCurrentIsland = GetEventData();
	//Trace("Inside to "+wdmCurrentIsland);
	PlayLandHo(); // NK // added by KAM after build 11 // KK
}

// KK -->
void PlayLandHo()
{
	if (ENABLE_EXTRA_SOUNDS == 0) return;
	if (actLoadFlag == 1) return;
	if (!CheckAttribute(&worldMap, "outsideIsland")) return;
	DeleteAttribute(&worldMap, "outsideIsland");
	PlaySound("#land_ho");
}
// <-- KK

void wdmEvent_OutsideIsland()
{
	wdmCurrentIsland = GetEventData();
	//Trace("Outside from "+wdmCurrentIsland);
	wdmCurrentIsland = WDM_NONE_ISLAND;
	worldMap.outsideIsland = true; // KK
}

void wdmEvent_PlayerInStorm()
{
	float playerShipX = GetEventData();
	float playerShipZ = GetEventData();
	float playerShipAY = GetEventData();
	int stormIndex = GetEventData();
	wdmDisableTornadoGen = false;
	if (CheckAttribute(pchar, "stormIndex")) return; // PW storm immunity otherwise locked in storm
    	pchar.stormIndex = stormIndex;//PW set up variable for storm immunity (cleared in daily crew update)

	// if (rand(100)>20) SetNextWeather("Stormy");
	// else SetNextWeather("Heavy Storm");
	wdmReloadToSea();
}

void wdmEvent_ShipEncounter()
{
	wdmDisableTornadoGen = true;
	float playerShipX = GetEventData();
	float playerShipZ = GetEventData();
	float playerShipAY = GetEventData();
	int eshipIndex = GetEventData();
	//Trace("Player ship hit in ship encounter with index " + eshipIndex);

	//Boyer add
	if (CheckAttribute(pchar, "SkipEshipIndex") && pchar.SkipEshipIndex == eshipIndex) return; // boal
	pchar.SkipEshipIndex = eshipIndex;
	if(CheckAttribute(worldMap, "evwin") != 0)
	{
		if(worldMap.evwin == "true")
		{
			wdmMessage("Sails on horizon!# Pirate ships ahead.", "Engage", "Skip");
			return;
		}
	}
	// boal -->
//changed by MAXIMUS: for new "Sail Ho" and DirectSail-Mod -->
    CalculateEncInfoData();
/*	ref messenger = DirectSailMessenger("sail_ho");
	messenger.SailHo = true;
	messenger.Dialog.Filename = "Enc_WorldMap_dialog.c";
	Log_SetActiveAction("Nothing");
	BLI_RefreshCommandMenu();
	BLI_DisableShow();
	SelfDialog(messenger);*/
	LaunchBoalMapScreen();
//changed by MAXIMUS: for new "Sail Ho" and DirectSail-Mod <--
	//wdmReloadToSea();
	// boal <--

}

void wdmEvent_DeleteShipEncounter()
{
	if(wdmDisableRelease == true)
	{
		int type = GetEventData();
		if(type >= 0) ReleaseMapEncounter(type);
	}
}

void wdmEvent_EventWindowChangeSelectoin()
{
	int select = GetEventData();
}

void wdmEvent_EventWindowSelect()
{
	int result = GetEventData();

	//Trace("Event window select is " + result);
	if(result == 0) wdmReloadToSea();
}

void wdmEvent_WaitMenuChangeSelectoin()
{
	int selectItem = GetEventData();
}

void wdmEvent_WaitMenuSelect()
{
	int selectItem = GetEventData();

	//Trace("Wait menu select is " + selectItem);
}

void wdmEvent_UpdateDate()
{
	Environment.date.day = worldMap.date.day;
	Environment.date.month = worldMap.date.month;
	Environment.date.year = worldMap.date.year;
	Environment.date.hour = worldMap.date.hour;
	Environment.date.min = worldMap.date.min;
	Environment.date.sec = worldMap.date.sec;
	Environment.time = GetEventData();
}



#event_handler("NextDay", "wdmNextDayUpdate");
void wdmNextDayUpdate()
{
	// NK -->
	ref PChar = GetMainCharacter();
	if(!CheckAttribute(PChar,"articles")) {PChar.articles = 0;}
	if(!CheckAttribute(PChar,"LastPayMonth")) {PChar.LastPayMonth = GetDataMonth();} // PB: NOT at the beginning of the game
	/*if( sti(PChar.LastPayMonth) != GetDataMonth() )
	{
		if( GetDataDay() >= 7 && !sti(PChar.articles) )
		{
			wdmLockReload = true;
			PChar.LastPayMonth = GetDataMonth();
			PostEvent("Event_CheckMoneyData", 0);
		}
	}*/ //This is in daily updates already
	/*DailyCrewUpdate();
	// NK <--
	UpdateAllTowns(false); // NK
	DailyShipBerthingUpdate(); 		// added after build 11 by KAM
	UpdateAllItemTraders(false); // NK itemtrade 05-04-02 do all trader update.
	UpdateMoonInfo(LogsToggle == LOG_VERBOSE); // added by Levis*/
	DoDailyUpdates("all"); //Changed to this by levis to take everything in account
}


/*#event_handler("Event_CheckMoneyData", "wdmCheckMoneyData");
void wdmCheckMoneyData()
{
	trace("wdmCheckMoneyData on day: "+ worldMap.date.day);
	LaunchSalaryScreen();
	wdmLockReload = false;
}*/ //in daily updates already

#event_handler("WorldMap_IsSkipEnable", "wdmIsSkipEnable");
bool wdmSkipReturnBool = false;
bool wdmIsSkipEnable()
{
	wdmSkipReturnBool = false;
	if(IsCharacterPerkOn(GetMainCharacter(), "SailingProfessional"))
	{
		if(rand(100) <= 50)
		{
			wdmSkipReturnBool = true;
		}
	}
	return wdmSkipReturnBool;
}
