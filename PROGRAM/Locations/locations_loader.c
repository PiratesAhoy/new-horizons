#include "Locations\particles.c"

#define EVENT_LOCATION_LOAD		"EventLoadLocation"
#define EVENT_LOCATION_UNLOAD	"EventUnloadLocation"

#define MAX_SHIPS_IN_LOCATION	32
#define BOAT_CHARACTER			0

ref loadedLocation;
object locCamera;
object locShips[MAX_SHIPS_IN_LOCATION];
int iShips[MAX_SHIPS_IN_LOCATION]; // KK
int	locNumShips = 0;

float locTmpTime = 0.0;
bool locDisableUpdateTime = false;

// NK character-style loc functions 05-07-19

int GetLocationIndex(string id)
{
	return NativeFindLocation(&locations, id);
}

ref LocationFromID(string id)
{
	int idx = GetLocationIndex(id);
	if(idx >=0 && idx < nLocationsNum) return &Locations[idx];
	return NullCharacter;
}
// NK <--

int FindLocation(string id)
{
	return NativeFindLocation(&locations, id);
	/*
	if (id=="") return -1;
	for(int n = 0; n<MAX_LOCATIONS; n++)
	{
		if(Locations[n].id == id) return n;
	}
	return -1;*/
}

bool LoadLocation(ref loc)
{
	traceif("LoadLocation(ref loc) " + loc.id);
	PostEvent(EVENT_LOCATION_LOAD,0);

	int i;
	bool res;
	ref mainCharacter = GetMainCharacter(); // KK

	for (i = 0; i < MAX_SHIPS_IN_LOCATION; i++) { iShips[i] = -1; } // KK

	//Time update==========================================================================
	// NK 04-09-21 with time now added on the fly this is unnecessary. However, with TIMEUPDATE_BLOCK_LAND we still need something.
	/*if(locTmpTime > 300)
	{
		AddTimeToCurrent(4, 0);
	}else{
		if(locTmpTime > 100)
		{
			AddTimeToCurrent(0, 30);
		}else{
			AddTimeToCurrent(0, 5);
		}
	}*/
	if(TIMEUPDATE_BLOCK_LAND)
	{
		AddTimeToCurrent(0, (locTmpTime * TIMESCALAR_LAND)/60.0);
		// WM wdmgrid section 04-10-24 -->
		// done in calendar.c now:
	}
	// NK <--
	locTmpTime = 0.0;
	//Environment==========================================================================


	//Environment==========================================================================

	if(CheckAttribute(loc, "type"))
	{
		switch(loc.type)
		{
			case "cave":			// пещера
				ExecuteTechnique("amb_cave");
				break;
			case "KhaelRoa":			// desert cave
				ExecuteTechnique("amb_cave");
				break;
			case "inca_temple":		// храм инков
				ExecuteTechnique("amb_inca_temple");
				break;
			case "house":			// дом
				ExecuteTechnique("amb_house");
				break;
			case "tavern":			// таверна
				ExecuteTechnique("amb_tavern");
				break;
			case "shop":			// магазин
				ExecuteTechnique("amb_shop");
				break;
			case "residence":		// резиденция
				ExecuteTechnique("amb_residence");
				break;
			case "church":			// церковь
				ExecuteTechnique("amb_church");
				break;
			case "jail":			// тюрьма
				ExecuteTechnique("amb_jail");
				break;
			case "dungeon":
				ExecuteTechnique("amb_dungeon");
				break;
			// default:
				ExecuteTechnique("amb_other");
		}
	}
	//
	if(CheckAttribute(loc, "lockWeather") == true)
	{
		SetNextWeather(loc.lockWeather);
	}
// KK -->
	/*bool isNoBoarding = true;
	bool isFort = false;
	if(CheckAttribute(loc, "boarding") == true)
	{
		if(loc.boarding == "true") isNoBoarding = false;
		if(loc.boarding == "fort")
		{
			isNoBoarding = false;
			isFort = true;
		}
		if (loc.boarding == "town") {
			isNoBoarding = false;
			isTown = true;
		}
	}*/
	bool isNoBoarding = !LAi_IsBoardingProcess() && !bSeaActive;
	if (isNoBoarding) {
		if (!CheckAttribute(loc,"models.back")) {
			//Sea
			if (loc.environment.sea == "true") {
				CreateSea(EXECUTE,REALIZE);//CreateEntity(&locSea, "sea");
				CreateCoastFoamEnvironment(loc.id, EXECUTE, REALIZE);
			} else {
				if (!ownDeckStarted()) DeleteSeaEnvironment();
			}
			//Weather
			if (loc.environment.weather == "true") {
				CreateWeather(EXECUTE,REALIZE);//CreateEntity(&locWeather, "weather");
			} else {
				if (!ownDeckStarted()) {
					DeleteWeatherEnvironment();
				} else {
					if (!HasSubStr(loc.id,"ShipDeck")) WhrDeleteRainEnvironment();
				}
			}
			//Ship env
			if (!ownDeckStarted()) CreateShipEnvironment();
		} else {
			if (!ownDeckStarted()) {
				DeleteSeaEnvironment();
				DeleteWeatherEnvironment();
			} else {
				if (!HasSubStr(loc.id,"ShipDeck")) WhrDeleteRainEnvironment();
			}
		}
	} else {
		if (!CheckAttribute(loc, "models.back")) {
			if(isTown || isFort) {
				//Sea
				if(loc.environment.sea == "true") {
					CreateSea(EXECUTE,REALIZE);//CreateEntity(&locSea, "sea");
					CreateCoastFoamEnvironment(loc.id, EXECUTE, REALIZE);
				}
				//Weather
				if(loc.environment.weather == "true") CreateWeather(EXECUTE,REALIZE);//CreateEntity(&locWeather, "weather");
			}
			if (isTown) CreateShipEnvironment();
		}
	}

	if (CheckAttribute(mainCharacter, "location.from_sea") == true && IsPortLandscapeEnabled(mainCharacter.location.from_sea) != "") {
		CreatePortLandscape(mainCharacter.location.from_sea);
	}
// <-- KK

// JRH -->
	if (CheckAttribute(loc, "type") && loc.type == "Rogers_mine")
	{
		if(loc.environment.sea == "true") CreateSea(EXECUTE,REALIZE);	//must be before weather!!
		if(loc.environment.weather == "true") CreateWeather(EXECUTE,REALIZE);
	}

	if (CheckAttribute(loc, "id.label") && loc.id.label == "Captain's cabin")
	{
		if (ENABLE_AMMOMOD)
    		{
			if (!CheckAttribute(loc, "weaponslocker.items.gunpowder"))
			{
				Restock_Ammo(50 + rand(20), 50 + rand(20), 50 + rand(20), 25 + rand(10));
			}
		}
	}

// <-- JRH

	ReloadProgressUpdate();

	//SendMessage(Sound,"lf",MSG_SOUND_SET_MASTER_VOLUME,0.0);

	//Create location======================================================================
	if (!CreateEntity(&loc, "location")) {
		traceif("LoadLocation: failed to create loc entity."); // KK
		return false;
	}
	//Set models path
	if(CheckAttribute(loc, "filespath.models"))
	{		
		SendMessage(loc, "ls", MSG_LOCATION_MODELSPATH, loc.filespath.models);
	}
	//Set textures path
	if(CheckAttribute(loc, "filespath.textures"))
	{
		SendMessage(loc, "ls", MSG_LOCATION_TEXTURESPATH, loc.filespath.textures);
	}
	//Set lighting path
	SendMessage(loc, "ls", MSG_LOCATION_LIGHTPATH, GetLightingPath());
	SendMessage(loc, "ls", MSG_LOCATION_SHADOWPATH, GetLmLightingPath());

	//Loading always models================================================================
	aref st, at, lit, lit1;
	string sat;
	makearef(st, loc.models.always);
	int num = GetAttributesNum(st);
	for(i = 0; i < num; i++)
	{
		at = GetAttributeN(st, i);
		sat = GetAttributeName(at);
		if(sat != "grassPatch")
		{
			sat = "models.always." + sat;
			res = LocLoadModel(loc, sat, "");
			if(res == 0)
			{
				traceif("LocationLoader: not loaded model location." + sat + ", id = " + loc.id);
				traceif("Unload location.");
				UnloadLocation(loc);
				return false;
			}
		}else{
			LocLoadGrass(loc, "models.always." + sat);
		}
	}
	//Loading background model=============================================================
	if(CheckAttribute(loc, "models.back") == true)
	{
		string hourModel = Whr_GetInsideBack();//MAXIMUS -[corrects back-models]->
		aref aCurWeather = GetCurrentWeather();
		if(CheckAttribute(aCurWeather,"InsideBack")) hourModel = Whr_GetString(aCurWeather,"InsideBack");
		if(GetHour()>22.0 || GetHour()<=6.0) hourModel = "n";
		if(GetHour()>6.0 && GetHour()<=10.0) hourModel = "m";
		if(GetHour()>10.0 && GetHour()<=17.0) hourModel = "d";
		if(GetHour()>17.0 && GetHour()<=22.0) hourModel = "e";
		if(CheckAttribute(aCurWeather,"id") && aCurWeather.id=="Day Storm") hourModel = "n";
		if(LocLoadModel(loc, "models.back", hourModel) == 0)//MAXIMUS <-[corrects back-models]-
		{
			traceif("LocationLoader: not loaded back model location." + sat + ", id = " + loc.id);
		}		
	}

	ReloadProgressUpdate();

	//Loading day/night models=============================================================
	if(Whr_IsDay() != 0)
	{
		//Day
		makearef(st, loc.models.day);
		num = GetAttributesNum(st);
		for(i = 0; i < num; i++)
		{
			at = GetAttributeN(st, i);
			sat = GetAttributeName(at);
			if((sat != "charactersPatch") && (sat != "jumpPatch") && (sat != "lights"))
			{
				sat = "models.day." + sat;
				res = LocLoadModel(loc, sat, "");
				if(res == 0)
				{
					traceif("LocationLoader: not loaded model location." + sat + ", id = " + loc.id);
					traceif("Unload location.");
					UnloadLocation(loc);
					return false;
				}
			}
		}
		//Loading patches
		if(CheckAttribute(loc, "models.day.charactersPatch") != 0)
		{
			res = SendMessage(loc, "ls", MSG_LOCATION_SET_CHRS_PATCH, loc.models.day.charactersPatch);
			if(res == 0)
			{
				traceif("");
				traceif("\\");
				traceif("Character patch not loaded!");
				traceif("/");
				traceif("");
				UnloadLocation(loc);
				return false;
			}
		}else{
			traceif("");
			traceif("\\");
			traceif("Character patch not setting for location.models.day.charactersPatch!");
			traceif("/");
			traceif("");
			UnloadLocation(loc);
			return false;
		}
		if(CheckAttribute(loc, "models.day.jumpPatch") != 0)
		{
			SendMessage(loc, "ls", MSG_LOCATION_SET_JMP_PATCH, loc.models.day.jumpPatch);
		}
	}else{
		//Night
		makearef(st, loc.models.night);
		num = GetAttributesNum(st);
		for(i = 0; i < num; i++)
		{
			at = GetAttributeN(st, i);
			sat = GetAttributeName(at);
			if((sat != "charactersPatch") && (sat != "jumpPatch") && (sat != "lights"))
			{
				sat = "models.night." + sat;
				res = LocLoadModel(loc, sat, "");
				if(res == 0)
				{
					traceif("LocationLoader: not loaded model location." + sat + ", id = " + loc.id);
					traceif("Unload location.");
					UnloadLocation(loc);
					return false;
				}
			}
		}
		
		//Loading patches
		if(CheckAttribute(loc, "models.night.charactersPatch") != 0)
		{
			res = SendMessage(loc, "ls", MSG_LOCATION_SET_CHRS_PATCH, loc.models.night.charactersPatch);
			if(res == 0)
			{
				traceif("");
				traceif("\\");
				traceif("Character patch not loaded!");
				traceif("/");
				traceif("");
				UnloadLocation(loc);
				return false;
			}
		}else{
			traceif("");
			traceif("\\");
			traceif("Character patch not setting for location.models.night.charactersPatch!");
			traceif("/");
			traceif("");
			UnloadLocation(loc);
			return false;
		}
		if(CheckAttribute(loc, "models.night.jumpPatch") != 0)
		{
			SendMessage(loc, "ls", MSG_LOCATION_SET_JMP_PATCH, loc.models.night.jumpPatch);
		}


	}
	//Entry models=========================================================================
	if(LocIsEntryLocation(loc) == true)
	{
		makearef(st, loc.models.entry);
		num = GetAttributesNum(st);
		for(i = 0; i < num; i++)
		{
			at = GetAttributeN(st, i);
			sat = "models.entry." + GetAttributeName(at);
			res = LocLoadModel(loc, sat, "");
			if(res == 0)
			{
				traceif("LocationLoader: not loaded model location." + sat + ", id = " + loc.id);
				traceif("Unload location.");
				UnloadLocation(loc);
				return false;
			}
		}
	}

	ReloadProgressUpdate();

	//Locators=============================================================================
	Sea.MaxSeaHeight = 1.15;
	if(CheckAttribute(loc,"MaxSeaHeight")) Sea.MaxSeaHeight = stf(loc.MaxSeaHeight); // screwface : limit wave height
	//Locator's radiuses
	int j, k, gnum, lnum;
	aref locator_rad;
	if(CheckAttribute(loc, "locators_radius") != 0)
	{
		makearef(locator_rad, loc.locators_radius);
		gnum = GetAttributesNum(locator_rad);
		for(j = 0; j < gnum; j++)
		{
			//Group radius
			aref rdgrp = GetAttributeN(locator_rad, j);
			string rdgname = GetAttributeName(rdgrp);			
			float rad = MakeFloat("" + rdgrp);
			SetLocatorGroupRadius(loc, rdgname, rad);
			//Some locators radius
			lnum = GetAttributesNum(rdgrp);
			for(k = 0; k < lnum; k++)
			{
				aref rdloc = GetAttributeN(rdgrp, k);
				string rdlname = GetAttributeName(rdloc);
				rad = MakeFloat("" + rdloc);
				SetLocatorRadius(loc, rdgname, rdlname, rad);
			}
		}
	}
	//Updatelocators=======================================================================
	SendMessage(loc, "l", MSG_LOCATION_UPDATELOCATORS);
	if(CheckAttribute(loc,"testing")) return false;

	if(CheckAttribute(loc,"id") && loc.id!="") { WriteAdditionalLocators(FindLocation(loc.id)); }//MAXIMUS: adding not prescribed locators [MAXIMUS_Functions.c]

	loadedLocation = loc;
	
//	DumpAttributes(loc);


	ReloadProgressUpdate();

	//Lights===============================================================================
	string lightPath;
	string lightName;
	string lightGroupName;
	if(Whr_IsLight() == 0)
	{
		lightPath = "models.day.lights";
	}else{
		lightPath = "models.night.lights";
	}
	if(CheckAttribute(loc, lightPath) != 0)
	{
		makearef(st, loc.(lightPath));
		num = GetAttributesNum(st);
		//traceif("numLights = " + num);
		for(i = 0; i < num; i++)
		{
			at = GetAttributeN(st, i);
			lightGroupName = GetAttributeName(at);
			sat = lightPath + "." + lightGroupName;
			lightName = loc.(sat);
			sat = "locators." + lightGroupName;
			if(CheckAttribute(loc, sat) != 0)
			{
				makearef(lit, loc.(sat));
				lnum = GetAttributesNum(lit);					
				for(j = 0; j < lnum; j++)
				{
					lit1 = GetAttributeN(lit, j);
					float litX = stf(lit1.x);
					float litY = stf(lit1.y);
					float litZ = stf(lit1.z);
					//traceif("     AddLight: " + lightName + " (" + litX + ", " + litY + ", " + litZ);
					SendMessage(loc, "lsfff", MSG_LOCATION_ADD_LIGHT, lightName, litX, litY, litZ);
					if(lightName == "lamp")
					{
						SendMessage(loc, "lsfff", MSG_LOCATION_EX_MSG, "AddFlys", litX, litY, litZ);
					}
				}
			}
		}
	}
	
	ReloadProgressUpdate();
	
	//Particles============================================================================
	CreateParticles(loc);
	ReloadProgressUpdate();
	//Ships================================================================================
// KK -->
	CreateFlagEnvironment();
	if (!LAi_boarding_process) {
		LocLoadShips(loc);
	} else {
		if (isTown == true && cdistrict == 1) LocLoadShips(loc);
	}
	ReloadProgressUpdate();
// <-- KK
	//Animals===========================================================================
	CreateAnimals(loc);
	ReloadProgressUpdate();
	//Characters===========================================================================
	SetCharacterPostInit(true);
	LoginCharactersInLocation(loc);
	SetCharacterPostInit(false);
	if(DEBUG_POSTINIT>1) DumpAttributes(PostInitQueue);
	//Main character options===============================================================
	if(IsEntity(mainCharacter) == 0)
	{
		traceif("Main character not loaded!");
		UnloadLocation(loc);
		return false;		
	}
	AddCharacterLocatorGroup(mainCharacter, "reload");

	// ccc Greater Oxbay
	AddCharacterLocatorGroup(mainCharacter, "rld");		// ccc to enable rld locators for exits
	AddCharacterLocatorGroup(mainCharacter, "monsters");		// ccc to enable monsters locators for exits
	AddCharacterLocatorGroup(mainCharacter, "goto");		// ccc
	// ccc Greater Oxbay end

	AddCharacterLocatorGroup(mainCharacter, "camdetector");
	AddCharacterLocatorGroup(mainCharacter, "item");
	AddCharacterLocatorGroup(mainCharacter, "randitem");
	AddCharacterLocatorGroup(mainCharacter, "box");
	AddCharacterLocatorGroup(mainCharacter, "teleport");

	ReloadProgressUpdate();

	// MAXIMUS: Isla de Muerte -->
	if (CheckCharacterItem(mainCharacter, "aztec_compass") || CheckCharacterItem(mainCharacter, "muerte_map")) // KK
		CreateIslaDeMuerte();
	else
		DeleteIslaDeMuerte();
	// MAXIMUS: Isla de Muerte <--

	// CTM -->
	if(sti(GetStorylineVar(FindCurrentStoryline(), "JACK_SPARROW")) > 0)
	{
		if(!IsOfficer(characterFromID("Ragetti")) || HasSubStr(mainCharacter.location, "tavern_upstairs") || HasSubStr(mainCharacter.location, "residence") || HasSubStr(mainCharacter.location, "townhall"))
		{
			ChangeCharacterAddress(characterFromID("Pintel"), "none", "");
		}
		else
		{
			LAi_SetOfficerType(characterFromID("Pintel"));
			SetCharacterToNearLocatorFromMe("Pintel", 3);
		}
	}
	// CTM <--
	//Camera===============================================================================
	locCameraEnableFree = ENABLE_FREE_CAMERA;				// PB: For Free Camera Mode
	DeleteAttribute(mainCharacter, "scrollchars");	// PB: For Cheatmode
	InitOpenSeaMod();								// stljeffbb Jan 15 2012
	ReloadProgressUpdate();
	CreateEntity(&locCamera, "LocationCamera");
	SetActiveCamera(LOCATION_CAMERA);
	SendMessage(&locCamera, "li", MSG_CAMERA_SETTARGET, mainCharacter);
	locCameraFollow();
	if(CheckAttribute(loc, "lockCamAngle") == true) // KK && LAi_boarding_process)
	{
		float lockCamAngle = stf(loc.lockCamAngle);
		if(lockCamAngle < -1.5) lockCamAngle = -1.5;
		if(lockCamAngle > 1.5) lockCamAngle = 1.5;
		SendMessage(&locCamera, "lf", MSG_CAMERA_MOVE, lockCamAngle);
	}

	SetEventHandler("Control Activation","locCameraSwitch",1);
	if(!LAi_boarding_process && !bDeckEnter && !bMutinyDeckStarted) SetEventHandler("Control Activation","chrCharacterKeys",1); // KK

	//changed by MAXIMUS <--
//<-- JRH

	//DumpAttributes(loc);
	//SendMessage(Sound,"lf",MSG_SOUND_SET_MASTER_VOLUME,1.0);

	if(VISIBLE_LOCATORS)    // LDH 05Dec06 added toggle instead of commenting out line
	{
	    if(WITH_BRIGHT_COLOURS)	//JRH
	    {
		VisibleLocatorsGroup("rld", 1.0, 15.0, 255, 0, 255, 0);
		VisibleLocatorsGroup("reload", 1.0, 15.0, 255, 0, 255, 0);	
		VisibleLocatorsGroup("Merchant", 1.0, 15.0, 105, 0, 255, 125);
		VisibleLocatorsGroup("camera", 1.0, 15.0, 155, 0, 255, 255);
		VisibleLocatorsGroup("characters", 1.0, 15.0, 155, 255, 0, 0);	
		VisibleLocatorsGroup("goto", 1.0, 15.0, 255, 255, 0, 0);
		VisibleLocatorsGroup("sit", 1.0, 15.0, 255, 255, 0, 0);
		VisibleLocatorsGroup("sit2", 1.0, 15.0, 255, 255, 0, 0);			//JRH added
		VisibleLocatorsGroup("item", 1.0, 15.0, 255, 255, 0, 255);
		VisibleLocatorsGroup("randitem", 1.0, 15.0, 255, 255, 0, 255);
		VisibleLocatorsGroup("treasurechests", 1.0, 15.0, 255, 255, 0, 255);
		VisibleLocatorsGroup("chests", 1.0, 15.0, 255, 255, 0, 255);
		VisibleLocatorsGroup("box", 1.0, 15.0, 255, 255, 0, 255);
		VisibleLocatorsGroup("boxes", 1.0, 15.0, 255, 255, 0, 255);
		VisibleLocatorsGroup("monsters", 1.0, 15.0, 255, 255, 0, 0);
		VisibleLocatorsGroup("officers", 1.0, 15.0, 255, 255, 0, 0);
		VisibleLocatorsGroup("smugglers", 1.0, 15.0, 255, 255, 0, 0);
		VisibleLocatorsGroup("smoke", 1.0, 15.0, 255, 255, 0, 255);
		VisibleLocatorsGroup("barmen", 1.0, 15.0, 105, 0, 255, 125);
		VisibleLocatorsGroup("waitress", 1.0, 15.0, 105, 0, 255, 125);
		VisibleLocatorsGroup("tables", 1.0, 15.0, 255, 255, 0, 0);
		VisibleLocatorsGroup("candles", 1.0, 15.0, 255, 255, 255, 55);
		VisibleLocatorsGroup("candles_p", 1.0, 15.0, 255, 255, 255, 55);
		VisibleLocatorsGroup("quest", 1.0, 15.0, 155, 0, 255, 255);
		VisibleLocatorsGroup("quest_locator", 1.0, 15.0, 155, 0, 255, 255);
		VisibleLocatorsGroup("quest_lines", 1.0, 15.0, 155, 0, 255, 255);
		VisibleLocatorsGroup("blacksmoke", 1.0, 15.0, 155, 0, 255, 255);
		VisibleLocatorsGroup("torchlightes", 1.0, 15.0, 255, 255, 255, 55);
		VisibleLocatorsGroup("torchlightes_p", 1.0, 15.0, 255, 255, 255, 55);
		VisibleLocatorsGroup("torchlightes_p14", 1.0, 15.0, 255, 255, 255, 55);
		VisibleLocatorsGroup("ships", 1.0, 300.0, 255, 255, 255, 55);
		VisibleLocatorsGroup("ships_other", 1.0, 600.0, 255, 255, 255, 55);
		VisibleLocatorsGroup("patrol", 1.0, 15.0, 155, 0, 255, 255);
		VisibleLocatorsGroup("soldiers", 1.0, 15.0, 155, 0, 255, 255);			// GR added
	    }
	    else
	    {
		VisibleLocatorsGroup("officers", 1.0, 15.0, 55, 0, 55, 0);
		VisibleLocatorsGroup("rld", 1.0, 15.0, 55, 0, 55, 0);
		VisibleLocatorsGroup("box", 1.0, 15.0, 55, 0, 55, 0);
		VisibleLocatorsGroup("reload", 1.0, 15.0, 55, 0, 55, 0);
		VisibleLocatorsGroup("Merchant", 1.0, 15.0, 105, 0, 55, 25);
		VisibleLocatorsGroup("camera", 1.0, 15.0, 155, 0, 55, 55);
		VisibleLocatorsGroup("characters", 1.0, 15.0, 55, 55, 0, 0);
		VisibleLocatorsGroup("goto", 1.0, 15.0, 55, 55, 0, 0);
		VisibleLocatorsGroup("sit", 1.0, 15.0, 55, 55, 0, 0);
		VisibleLocatorsGroup("sit2", 1.0, 15.0, 55, 55, 0, 0);				//JRH added
		VisibleLocatorsGroup("item", 1.0, 15.0, 55, 55, 0, 55);
		VisibleLocatorsGroup("randitem", 1.0, 15.0, 55, 55, 0, 55);
		VisibleLocatorsGroup("monsters", 1.0, 15.0, 55, 0, 55, 0);
		VisibleLocatorsGroup("smugglers", 1.0, 15.0, 55, 0, 55, 0);
		VisibleLocatorsGroup("barmen", 1.0, 15.0, 105, 0, 55, 25);
		VisibleLocatorsGroup("waitress", 1.0, 15.0, 105, 0, 55, 25);
		VisibleLocatorsGroup("tables", 1.0, 15.0, 55, 0, 55, 0);
		VisibleLocatorsGroup("candles", 1.0, 15.0, 55, 55, 55, 55);
		VisibleLocatorsGroup("candles_p", 1.0, 15.0, 55, 55, 55, 55);
		VisibleLocatorsGroup("quest", 1.0, 15.0, 155, 0, 55, 55);
		VisibleLocatorsGroup("torchlightes", 1.0, 15.0, 55, 55, 55, 55);
		VisibleLocatorsGroup("torchlightes_p", 1.0, 15.0, 55, 55, 55, 55);
		VisibleLocatorsGroup("torchlightes_p14", 1.0, 15.0, 55, 55, 55, 55);
		VisibleLocatorsGroup("ships", 1.0, 300.0, 55, 55, 55, 55);
		VisibleLocatorsGroup("ships_other", 1.0, 300.0, 55, 55, 55, 55);
		VisibleLocatorsGroup("patrol", 1.0, 15.0, 155, 0, 55, 55);
		VisibleLocatorsGroup("soldiers", 1.0, 15.0, 155, 0, 55, 55);			// GR added
	    }
	}

	/*
	VisibleLocatorsGroup("candles_medium", 1.0, 15.0, 255, 255, 255, 55);
	VisibleLocatorsGroup("chandeliers", 1.0, 15.0, 255, 128, 0, 128);
	VisibleLocatorsGroup("outside", 1.0, 15.0, 255, 155, 155, 255);	
	VisibleLocatorsGroup("fonar", 1.0, 15.0, 255, 155, 255, 155);
	VisibleLocatorsGroup("heaters", 1.0, 15.0, 255, 155, 255, 155);
	VisibleLocatorsGroup("incas_light", 1.0, 15.0, 255, 155, 255, 255);
	VisibleLocatorsGroup("incas_sky", 1.0, 15.0, 255, 0, 255, 255);
	*/
	
	ReloadProgressUpdate();
	
	ClearScreenShoter();//MAXIMUS: used for QuickSave
	RestoreLogInterface();

	Item_OnLoadLocation(loc.id);

	ReloadProgressUpdate();

	if(!CheckAttribute(loc, "models.back") && !LAi_boarding_process && !ownDeckStarted()) Island_Start();

	if(CheckAttribute(&mainCharacter, "lastFightMode") != 0)
	{
		if(sti(mainCharacter.lastFightMode) != 0)
		{
			SendMessage(&mainCharacter, "lsl", MSG_CHARACTER_EX_MSG, "SetFightMode", 1);
		}
	}
	LAI_group_SetRelationWithAllStock(LAI_GROUP_CORPSES, LAI_GROUP_NEUTRAL);//MAXIMUS: so we do it once
	//PostEvent("UpdateLocator", 0, "iiss", loc, mainCharacter, mainCharacter.location.group, mainCharacter.location.locator);//MAXIMUS: labels will always be shown
	if(CheckAttribute(mainCharacter,"autoreload") && CheckAttribute(mainCharacter,"location.locator.emerge"))
	{
		mainCharacter.location.locator.old.emerge = mainCharacter.location.locator.emerge;
		if(mainCharacter.location!=mainCharacter.autoreload.location && mainCharacter.location.locator!=mainCharacter.location.locator.emerge)
		{
			DeleteAttribute(mainCharacter,"autoreload.location");
		}
	}

	PostEvent("CheckTimeScale", 1000); // PB: Keep previous time scale
	if (BUILDING_COLLISION) PostEvent("StartCollideCheck", 1000); //Levis

	// MAXIMUS 20.08.2018 used for localization -->
	if(CheckAttribute(mainCharacter, "savelang"))
	{
		if(sti(mainCharacter.savelang)!=sti(GetInterfaceLanguage()))
		{
		PostEvent("ChangeLanguage", 0, "ls", sti(mainCharacter.savelang), "");
			UpdateCharactersNames();
		}
		DeleteAttribute(mainCharacter, "savelang");
	}
	// MAXIMUS 20.08.2018 used for localization <--

	//Levis moved it here for better timing
	StartPostInitChars();
	
	ReloadProgressUpdate();
	
	return true;
}

object loc;

bool UnloadLocation(aref loc)
{
	if (BUILDING_COLLISION) StopCollideCheck();  //Levis
	if(CheckAttribute(loc,"id")) traceif("UnloadLocation(aref loc) " + loc.id);
	PausePostInit(); //Levis we pause it first so all remaining events will be stored
	StopPostInitChars(); // Levis

	DialogExit();

	ref mainCharacter = GetMainCharacter();
	if(SendMessage(&mainCharacter, "ls", MSG_CHARACTER_EX_MSG, "IsFightMode") != 0)
		mainCharacter.lastFightMode = "1";
	else
		mainCharacter.lastFightMode = "0";
	SideStepControl(0, false); // NK ranged sidestep 05-07-21

// KK -->
	ClearAllLogStrings();
	if (CheckAttribute(loc, "type")) {
		if (loc.type == "own_deck" || loc.type == "ship") {
			DeletePortLandscape();
		}
	}
// <-- KK

	Event(EVENT_LOCATION_UNLOAD,"");
	DeleteAttribute(loc,"openboxes");									// NK 05-04-14
	DeleteAttribute(loc,"trapboxes");									// NK 05-04-14
	DeleteAttribute(loc,"jammed");										// PB: Lockpicks
	DeleteAttribute(mainCharacter, "Flags.waitdelay");					// PB: Just to make sure this is gone
	DeleteAttribute(mainCharacter, "directsail1.QuestCheckMapEnter");	// PB: This too
	LogoffCharactersFromLocation(loc);									// PB: Permanently erase certain characters
	int n;

	DeleteCoastFoamEnvironment();

// KK -->
	/*bool isNoBoarding = true;
	bool isFort = false;
	if(CheckAttribute(loc, "boarding") == true)
	{
		if(loc.boarding == "true") isNoBoarding = false;
		if(loc.boarding == "fort")
		{
			isNoBoarding = false;
			isFort = true;
		}
	}*/
// <-- KK
	if(!bSeaActive) // KK
	{
		DeleteParticles();
		DeleteClass(&Island);
		DeleteAnimals();
		DeleteSea();
		DeleteWeather();
		DeleteShipEnvironment(); 
		for (n = 0; n < locNumShips; n++)
		{
			DeleteClass(locShips[n]);
		}
		locNumShips = 0;
	}
	if(isFort)
	{
		DeleteSea();
		DeleteWeather();
	}
// KK -->
	if (isTown) {
		DeleteSea();
		DeleteWeather();

		DeleteShipEnvironment();
		for (n = 0; n < locNumShips; n++)
		{
			DeleteClass(locShips[n]);
		}
		locNumShips = 0;
	}
// <-- KK

	DelEventHandler("Control Activation","locCameraSwitch");
	if(!LAi_boarding_process && !bDeckEnter && !bMutinyDeckStarted) DelEventHandler("Control Activation","chrCharacterKeys"); // KK
	Item_OnUnLoadLocation();
	LocAi_Release();
	DeleteClass(&loc);
	DeleteClass(&locCamera);
	ExitFromReloadLocator(mainCharacter);//MAXIMUS
	Box_ExitFromLocator();//MAXIMUS
	Item_OnExitLocator();//MAXIMUS
	return true;
}

bool LocLoadModel(aref loc, string sat, string addition)
{
	//traceif("Load model: " + loc.(sat) + " from:" + sat);

	//Пропустим пустое имя
	if(loc.(sat) == "") return true;
	//Считываем параметры модельки
	string attr, attr1;
	bool res;
	string tech = "";
	int level = 10;
	attr = sat + ".tech";
	if(CheckAttribute(loc, attr)) tech = loc.(attr);
	attr = sat + ".level";
	if(CheckAttribute(loc, attr)) level = MakeInt(loc.(attr));
	//Грузим модельку
	string realModel = loc.(sat) + addition;
	if(HasSubStr(sat,"back") && !ownDeckStarted())
	{
		if(addition!="d" && addition!="e" && addition!="m" && addition!="n")
		{
			string hourModel = Whr_GetInsideBack();
			aref aCurWeather = GetCurrentWeather();
			if(CheckAttribute(aCurWeather,"InsideBack")) hourModel = Whr_GetString(aCurWeather,"InsideBack");
			if(GetHour()>22.0 || GetHour()<=6.0) hourModel = "n";
			if(GetHour()>6.0 && GetHour()<=10.0) hourModel = "m";
			if(GetHour()>10.0 && GetHour()<=17.0) hourModel = "d";
			if(GetHour()>17.0 && GetHour()<=22.0) hourModel = "e";
			if(CheckAttribute(aCurWeather,"id") && aCurWeather.id=="Day Storm") hourModel = "n";
			trace("::locations_loader.c:: Report from LocLoadModel - wrong model's name ["+realModel+"] was changed to ["+loc.(sat)+hourModel+"]");
			realModel = loc.(sat) + hourModel;
		}
	}
	else
	{
		if(loc.(sat)!=realModel)
		{
			trace("::locations_loader.c:: Report from LocLoadModel - wrong model's name ["+realModel+"] was changed to ["+loc.(sat)+"]");
			realModel = loc.(sat);
		}
	}
	res = SendMessage(loc, "lssl", MSG_LOCATION_ADD_MODEL, realModel, tech, level);
	if(res == 0) return 0;
	//Устанавливаем флаги
	object mdl;
	if(SendMessage(loc, "le", MSG_LOCATION_GET_MODEL, &mdl) != 0)
	{
//		SetTownFlag(loc, &mdl); // KK
	}
	// Проверяем на пену
	attr = sat + ".foam";
	if(CheckAttribute(loc, attr) != 0)
	{
		if (loc.(attr) == "1")
		{
			if (!isEntity(&Island))
			{
				CreateEntity(&Island, "Island");
				LayerAddObject(REALIZE, &Island, 65529);
			}

			SendMessage(&Island, "liss", MSG_LOCATION_ADD_MODEL, &mdl, loc.id, loc.filespath.models); // KK
			//traceif("<> Model " + attr + ", have a foam!!!");
		}
	}
	//Ставим модификаторы
	//locator
	attr = sat + ".locator.group";
	//traceif("> " + attr);
	if(CheckAttribute(loc, attr) != 0)
	{
		res = 0;
		attr1 = sat + ".locator.name";
		//traceif("> " + attr1);
		if(CheckAttribute(loc, attr1) != 0)
		{
			res = SendMessage(loc, "lss", MSG_LOCATION_MODEL_SET_POS, loc.(attr), loc.(attr1));
		}
		if(res == 0) traceif("Can't set locator modifier to model: " + loc.(sat));
	}
	//rotate
	attr = sat + ".rotate";
	if(CheckAttribute(loc, attr) != 0)
	{
		float x, y, z;
		attr1 = attr + ".x";
		if(CheckAttribute(loc, attr1) != 0) x = MakeFloat(loc.(attr1));
		attr1 = attr + ".y";
		if(CheckAttribute(loc, attr1) != 0) y = MakeFloat(loc.(attr1));
		attr1 = attr + ".z";
		if(CheckAttribute(loc, attr1) != 0) z = MakeFloat(loc.(attr1));
		res = SendMessage(loc, "lfff", MSG_LOCATION_MODEL_SET_ROT, x, y, z);
		if(res == 0) traceif("Can't set rotate modifier to model: " + loc.(sat));
	}	
	//uvslide
	attr = sat + ".uvslide";
	if(CheckAttribute(loc, attr) != 0)
	{
		float u0, v0, u1, v1;
		u0 = 0; v0 = 0; u1 = 0; v1 = 0;
		attr1 = attr + ".u0";
		if(CheckAttribute(loc, attr1) != 0) u0 = MakeFloat(loc.(attr1));
		attr1 = attr + ".v0";
		if(CheckAttribute(loc, attr1) != 0) v0 = MakeFloat(loc.(attr1));
		attr1 = attr + ".u1";
		if(CheckAttribute(loc, attr1) != 0) u1 = MakeFloat(loc.(attr1));
		attr1 = attr + ".v1";
		if(CheckAttribute(loc, attr1) != 0) v1 = MakeFloat(loc.(attr1));
		res = SendMessage(loc, "lffff", MSG_LOCATION_MODEL_SET_UVS, u0, v0, u1, v1);
		if(res == 0) traceif("Can't set uvslide modifier to model: " + loc.(sat));
	}
	//rotate
	attr = sat + ".lamps";
	if(CheckAttribute(loc, attr) != 0)
	{
		if(loc.(attr) != "0")
		{
			SendMessage(loc, "l", MSG_LOCATION_MODEL_LAMPS);
		}
	}
	//reflection
	attr = sat + ".reflection";
	if(CheckAttribute(loc, attr) != 0)
	{
		SendMessage(loc, "lf", MSG_LOCATION_MODEL_REFLECTION, stf(loc.(attr)));
	}
	return 1;
}

float GetAngleY(float x, float z)
{
	return atan2(x,z);
	/*float vx = x;
	float vz = z;
	float l = vx*vx + vz*vz;
	if(l > 0.0000001)
	{
		//Ищем углы
		vz = acos(vz/sqrt(l));
	}else vz = l;
	if(vx < 0) vz = -vz;
	return vz;*/
}

void LocLoadShips(ref Location)
{
	int		i, j;
	int		iShipsType[MAX_SHIPS_IN_LOCATION];
	int		iShipType, iMainCharacterShipType;
	aref	locator_ships,locator_otherships,locator_jettyships;
	aref	locator;

// KK -->
	for (i = 0; i < locNumShips; i++)
	{
		DeleteClass(locShips[i]);
	}
// <-- KK

	locNumShips = 0;

	bool bMainCharacterHere = LocIsEntryLocation(Location);

	ref rPlayer = GetMainCharacter();
	
	if (!CheckAttribute(Location, "locators")) 
	{
		if(Location.environment.sea=="true" && !bDeckEnter) traceif("LocLoadShips: Can't find Location.locators in location: " + Location.id); // MAXIMUS 28.07.2006
		return;
	}

	int iMCI = GetMainCharacterIndex();
	ref MC = GetMainCharacter(); // KK

	if (!CheckAttribute(Location, "locators.ships"))
	{
		if(Location.environment.sea=="true" && !bDeckEnter) traceif("LocLoadShips: Can't find Location.locators.ships in location: " + Location.id); // MAXIMUS 28.07.2006
		return;
	}
	if (!CheckAttribute(Location, "locators.ships_other"))
	{
		if(Location.environment.sea=="true" && !bDeckEnter) traceif("LocLoadShips: Can't find Location.locators.ships_other in location: " + Location.id); // MAXIMUS 28.07.2006
		return;
	}
	makearef(locator_ships, location.locators.ships);
	makearef(locator_otherships, location.locators.ships_other);
	makearef(locator_jettyships, location.locators.ships_jetty);

	iMainCharacterShipType = GetCharacterShipType(MC); // PS

	if(CheckAttribute(MC,"fallen")) // Screwface : Need to restore the fallen mast(s) to avoid crashes with set flags
	{
		DeleteAttribute(MC,"ship.sails");
		DeleteAttribute(MC,"ship.masts");
		DeleteAttribute(MC,"fallen");
		Trace("Player mast restored");
	}

	// create our characters ships
	if (bMainCharacterHere)
	{
		for (i=0;i<COMPANION_MAX;i++)
		{
			if (locNumShips >= MAX_SHIPS_IN_LOCATION) continue;
			int iCompanionIndex = GetCompanionIndex(MC, i);
			if (iCompanionIndex==-1) continue;
			ref rCompanion = GetCharacter(iCompanionIndex); // KK
			if(CheckAttribute(rCompanion,"fallen")) // Screwface : Need to restore the fallen mast(s) to avoid crashes with set flags
			{
				DeleteAttribute(rCompanion,"ship.sails");
				DeleteAttribute(rCompanion,"ship.masts");
				DeleteAttribute(rCompanion,"fallen");
				Trace("Companion mast restored");
			}
			iShipType = GetCharacterShipType(rCompanion); // PS
			if (iShipType == SHIP_NOTUSED) continue;
			SetCharacterShipLocation(rCompanion, Location.id); // KK
			iShips[locNumShips] = iCompanionIndex;
			iShipsType[locNumShips] = 0;
			rCompanion.curshipnum = locNumShips; // KK
			rCompanion.Flags.DoRefresh = true; // KK
			locNumShips++;
		}
	}

	int iNumShips = GetAttributesNum(locator_ships);
	int iNumOtherShips = GetAttributesNum(locator_otherships);
	int iNumJettyShips = GetAttributesNum(locator_jettyships);
	int iCurNumShips = 0;
	int iCurNumOtherShips = 0;
	int iCurNumJettyShips = 0;

	// create other quest characters ships
	int o = 0;
	int b = 0;

	// PB: Some locations neutral to pirates -->
	bool pirate_neutral = false;
	ref rPeriod;
	makeref(rPeriod, Periods[GetCurrentPeriod()]);
	string town = GetAttribute(Location, "townsack");
	if (CheckAttribute(rPeriod, "Towns." + town + ".relation_to_pirates")) pirate_neutral = true;
	// PB: Some locations neutral to pirates <--

	for (i=0;i<CHARACTERS_QUANTITY;i++) // NK 05-04-05 use CHARACTERS_QUANTITY
	{
		ref chr = &Characters[i]; // traceif("Character[" + i + "] index = " + chr.index);	// keep this around to test for bad characters
		if (i == iMCI) continue;
		if (!CheckAttribute(&Characters[i], "index")) continue;	// LDH 04Sep06 prune characters who were deleted in boarding code
		if (!Character_LocIsEntryLocation(&Characters[i],Location)) continue;

		// PB: Sailing Ships -->
		if(CheckAttribute(Location, "island"))
		{
			string islandstr = "Cr" + Location.island;
			if(HasSubStr(chr.id,islandstr))
			{
				DeleteAttribute(chr,"sailaway");
				if (!pirate_neutral || sti(chr.nation) != PIRATE)
				{
					if (GetNationRelation(sti(chr.nation), sti(GetLocationNation(location))) == RELATION_ENEMY) continue; // CTM
				}
				if (rand(2) == 0) chr.sailaway = true;
			}
		}
		// PB: Sailing Ships <--

		bool bExist = false;
		for (j=0;j<locNumShips;j++) 
		{
			if (i == iShips[j]) 
			{
				bExist = true; break;
			}
		}
		if (bExist) continue;
		iShipType = GetCharacterShipType(GetCharacter(i)); // PS
		if (iShipType == SHIP_NOTUSED) continue;
		if (LAi_IsDead(&Characters[i])) continue; // NK 04-09-12 if char is dead, skip. Needed for pruning ships of dead coast captains.
		if(CheckAttribute(&Characters[i],"surrendered")) continue; // Screwface : Avoid having surrendered ships in ports

		iShips[locNumShips] = i;
		Characters[i].curshipnum = locNumShips; // KK
		if (b < iNumJettyShips && JettyShip(Characters[i]))
		{
			iShipsType[locNumShips] = 2;
			DeleteAttribute(GetCharacter(i),"sailaway");
		//	Logit("ship #" + locNumShips + ": Ships Jetty: " + b + " character ID: " + Characters[i].id + " ship type: " + Characters[i].ship.type);
			b++
		}
		else
		{
			iShipsType[locNumShips] = 1;
		//	Logit("ship #" + locNumShips + ": Ships Other: " + o + " character ID: " + Characters[i].id + " ship type: " + Characters[i].ship.type);
			o++
		}
		if (locNumShips >= MAX_SHIPS_IN_LOCATION) continue;
		locNumShips++;
	}

//	traceif("CHARACTERS_QUANTITY = " + CHARACTERS_QUANTITY + ", locNumShips = " + locNumShips);	// 1118, 28
//	DumpAttributes(locator_ships);	// LDH test, 4 ships, I only had 2 companions
//	DumpAttributes(locator_otherships);	// LDH test, max is 8 always

	ref rCharacter; // PS
	ref rShip; // PS
	for(int n = 0; n < locNumShips; n++)
	{
		switch(iShipsType[n])
		{
			case 0:
				if (iCurNumShips >= iNumShips) 
				{ 
					traceif("LocLoadShips: need (ships): " + iCurNumShips + ", but max_num_ships: " + iNumShips);
					iCurNumShips++;		// LDH added for trace 03Sep06
					continue;
				};
				locator = GetAttributeN(locator_ships, iCurNumShips);
				iCurNumShips++;
			break;
			case 1:
				if (iCurNumOtherShips >= iNumOtherShips) 
				{ 
					traceif("LocLoadShips: need (ships_other): " + iCurNumOtherShips + ", but max_num_ships_other: " + iNumOtherShips);
					iCurNumOtherShips++;		// LDH added for trace
					continue;
				};
				locator = GetAttributeN(locator_otherships, iCurNumOtherShips);
				iCurNumOtherShips++;
			break;
			case 2:
				if (iCurNumJettyShips >= iNumJettyShips)
				{
					traceif("LocLoadShips: need (ships_jetty): " + iCurNumJettyShips + ", but max_num_ships_jetty: " + iNumJettyShips);
					iCurNumJettyShips++;		// LDH added for trace
					continue;
				};
				locator = GetAttributeN(locator_jettyships, iCurNumJettyShips);
				iCurNumJettyShips++;
			break;
		}
		ShipModelrList[n] = GetCurrentModelrNumber(); // KK
		if (CreateEntity(&locShips[n], "ship") == 0) break;
		rCharacter = GetCharacter(iShips[n]); // PS
		rShip = GetShipByType(GetCharacterShipType(rCharacter)); // PS
		// Screwface : save the sea pos of player ship to avoid be reload nowhere when we go on worldmap just after sea loading
		if(rcharacter.index == GetMainCharacterIndex() && !CheckAttribute(rCharacter,"Ship.Pos.save"))
		{
			rCharacter.Ship.Pos.save.x = GetAttribute(rCharacter, "Ship.Pos.x");
			rCharacter.Ship.Pos.save.z = GetAttribute(rCharacter, "Ship.Pos.z");
		}
		// Screwface :end
		rCharacter.Ship.Pos.x = stf(locator.x);
		rCharacter.Ship.Pos.z = stf(locator.z);
// KK -->
		if (CheckAttribute(locator, "vZ")) {
			rCharacter.Ship.Ang.y = GetAngleY(stf(locator.vZ.x),stf(locator.vZ.z));
		} else {
			rCharacter.Ship.Ang.y = stf(locator.ay);
		}
// <-- KK

		// ASVS -->
		if(CheckAttribute(rCharacter,"sailaway"))
		{
			if(!CheckAttribute(rCharacter,"Ship.Strand"))					rCharacter.Ship.Strand = false;
			if(!CheckAttribute(Scene,"camera"))								Scene.Camera = SHIP_CAMERA;
			if(!CheckAttribute(rCharacter,"ship.cannons.Charge"))			rCharacter.ship.cannons.Charge.Type = GOOD_BALLS;
			if(!CheckAttribute(rCharacter,"TmpPerks.LongRangeShoot"))		rCharacter.TmpPerks.LongRangeShoot = false;
			if(!CheckAttribute(rCharacter,"TmpPerks.shipspeedup"))			rCharacter.TmpPerks.shipspeedup = false;
			if(!CheckAttribute(rCharacter,"TmpPerks.shipturnrateup"))		rCharacter.TmpPerks.shipturnrateup = false;
			if(!CheckAttribute(rCharacter,"TmpPerks.sailingprofessional"))	rCharacter.TmpPerks.sailingprofessional = false;
			if(!CheckAttribute(rCharacter,"TmpPerks.stormprofessional"))	rCharacter.TmpPerks.stormprofessional = false;
			if(!CheckAttribute(rCharacter,"TmpPerks.turn"))					rCharacter.TmpPerks.turn = false;
			rCharacter.Ship.stopped = false;
			rCharacter.Ship.Speed.z = 1.5;
		}
		else
		{
			rCharacter.Ship.stopped = true;
			rCharacter.Ship.Speed.z = 0.0;
		}
		// ASVS <--
		Ship_SetLightsAndFlares(rCharacter);
		Ship_PrepareShipForLocation(rCharacter);
		// Screwface : section to send to setshipflag function the real number of ships who are physically in port and avoid CTD in some ports
		rPlayer.numcoastalindocks = locNumShips; // CTM

		if(CheckAttribute(rCharacter,"fallen")) // Restore the fallen mast(s) to avoid crashes
		{
			DeleteAttribute(rCharacter,"ship.sails");
			DeleteAttribute(rCharacter,"ship.masts");
			DeleteAttribute(rCharacter,"fallen");
		}
		rCharacter.Flags.DoRefresh = true; // KK
		//If(CheckAttribute(GetMainCharacter(),"avoidflagsRe")){DeleteAttribute(GetMainCharacter(),"avoidflagsRe");}
 		// Screwface : end
 		ref flag = GetCharacterFlagEntity(rCharacter);
 		SendMessage(&locShips[n], "li", MSG_SHIP_SET_CUSTOM_FLAG, &flag);
		SendMessage(&locShips[n],"laa",MSG_SHIP_CREATE,&rCharacter,&rShip);
	}

	// load boat 2 location
	if (CheckAttribute(Location, "locators.reload.boat"))
	{
		if (bMainCharacterHere && iMainCharacterShipType != SHIP_NOTUSED)
		{
			if (CreateEntity(&locShips[n], "ship"))
			{
				makearef(locator,Location.locators.reload.boat);

				rCharacter = GetCharacter(MAX_CHARACTERS+BOAT_CHARACTER);
				rShip = GetShipByType(GetCharacterShipType(&rCharacter)); // PS
				rCharacter.Ship.Pos.x = stf(locator.x);
				rCharacter.Ship.Pos.z = stf(locator.z);
				rCharacter.Ship.Ang.y = GetAngleY(stf(locator.vZ.x),stf(locator.vZ.z));
				rCharacter.Ship.stopped = true;
				rCharacter.Ship.Speed.z = 0.0;
				Ship_SetLightsAndFlares(rCharacter);
				Ship_PrepareShipForLocation(rCharacter);
				SendMessage(&locShips[n],"laa",MSG_SHIP_CREATE,&rCharacter,&rShip);
				locNumShips++;
			}
		}
	}
	else 
	{
		if (bMainCharacterHere)
		{
			traceif("LocLoadShips: Can't find boat locator in location: " + Location.id);
		}
	}
}

bool Character_LocIsEntryLocation(ref rCharacter, ref rLocation)
{
	if (CheckAttribute(rCharacter,"location.from_sea"))
	{
		if (rCharacter.location.from_sea == rLocation.id) return true;
	}
	return false;
}

bool LocIsEntryLocation(ref Location)
{
	ref rPlayer = GetMainCharacter();
	if (CheckAttribute(rPlayer,"location.from_sea")) // PB: Prevent error logs
	{
		//traceif("LocIsEntryLocation = " + rPlayer.location.from_sea);
		if (rPlayer.location.from_sea != Location.id) return false;
	}
	return true;
}

bool LocLoadGrass(aref loc, string sat)
{
	string grs = loc.(sat);
	string tex = "";
	sat = sat + ".texture";
	if(CheckAttribute(loc, sat) != 0)
	{
		tex = loc.(sat);
	}
	return SendMessage(loc, "lss", MSG_LOCATION_SET_GRS_PATCH, grs, tex);
}


#event_handler("LocationTimeUpdate", "LocationTimeUpdateFunc");
void LocationTimeUpdateFunc()
{
	float dltTime = GetEventData();
	if(locDisableUpdateTime) return;
	locTmpTime = locTmpTime + dltTime;
	// NK 04-09-21 time takes effect immediately if !TIMEUPDATE_BLOCK_LAND
	if(!TIMEUPDATE_BLOCK_LAND)
	{
		if(locTmpTime > 60)
		{
			locTmpTime -= 60;
			int oldhour = GetHour();
			AddTimeToCurrent(0, TIMESCALAR_LAND);
			if(oldhour != GetHour())
			{
				/*Dealing with weather is too complex for locations because of nightmodel etc.
				sNewExecuteLayer = EXECUTE;
				sNewRealizeLayer = REALIZE;
				Whr_UpdateWeather(false);*/
			}
		}
	}
	// 04-09-21 unclamp time - if(locTmpTime > 100000.0) locTmpTime = 100000.0;
	// NK <--
}
