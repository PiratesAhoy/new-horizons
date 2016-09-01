
#include "locations\locations_loader.c"
#include "locations\locations_camera.c"
#include "locations\locators_test.c"
#include "locations\locations_init.c" // KK


native int NativeFindCharacter(ref charactersArray, string id);
native int NativeFindLocation(ref charactersArray, string id);
native int NativeFindLoadCharacter();
native void SetReloadProgressBackImage(string imageName);
native void ReloadProgressStart();
native void ReloadProgressUpdate();
native void ReloadProgressEnd();
native void SystemDelay(int millsec);
native void ExecuteTechnique(string techName);
native string GetNextLineString();
native void SetReloadNextTipsImage();
#libriary "ScriptLocationLibrary"


void LocationInit()
{
	locCameraInit();
	InitLocations();
	locDisableUpdateTime = false;
	locTmpTime = 0.0;
}

void LocationTestProcess()
{
	SetReloadProgressBackImage("initialization.tga.tx");
	ReloadProgressStart();
	LocationInit();
	Locations_TestAll();
	ReloadProgressEnd();
}

// MAXIMUS 09.10.2006 [will return location name for correct showing]-->
string GetCharacterShipLocationName(ref rChar)
{
	string curLocName = Locations[FindLocation(GetCharacterShipLocation(rChar))].id.label;
	string curComma = strcut(curLocName,strlen(curLocName)-1,strlen(curLocName)-1);
	if(curComma==".") curLocName = strcut(curLocName,0,strlen(curLocName)-2);
	else curLocName = curLocName;

	return curLocName;
}
// MAXIMUS <--

int FindLoadedLocation()
{
	return NativeFindLoadCharacter();
	/*
	for(int i = 0; i < MAX_LOCATIONS; i++)
	{
		if(IsEntity(Locations[i])) 
		{			
			return i;
		}
		
	}
	return -1;
	*/
}

// NK 05-05-08 -->
// please do nLocationsNum++; after finding a new slot with this function!
int FindBlankLocSlot()
{
	ref loc;
	for(int i=nLocationsNum; i<MAX_LOCATIONS; i++)
	{
		makeref(loc, Locations[i]); 
		if(loc.id != "") nLocationsNum++; // NK 05-04-05 use CHARACTERS_QUANTITY, and update it if we find nonblank slots after.
		else return i;	// NOTE!!!! We do NOT update nLocationsNum based on the slot we are returning, because we may not be _really_ using FindBlankLocSlot()
	}					// to make a new location. So when you use this to make a new loc, please also update nLocationsNum.
	return -1;			// however, I'm also adding a straight call to this to the bottom of reinit(), to make sure nLocationsNum is OK.
}
// NK <--


bool SetLocatorGroupRadius(ref loc, string grpName, float rad)
{
	return SendMessage(loc, "lsf", MSG_LOCATION_GRP_RADIUS, grpName, rad);
}

bool SetLocatorRadius(ref loc, string grpName, string locName, float rad)
{
	return SendMessage(loc, "lssf", MSG_LOCATION_LOC_RADIUS, grpName, locName, rad);
}


bool VisibleLocatorsGroup(string group, float kRadius, float viewLabelsDist, int a, int r, int g, int b)
{
	
	int i = FindLoadedLocation();
	if(i < 0) return false;
	int color = argb(a, r, g, b);
	return SendMessage(&Locations[i], "lsffl", MSG_LOCATION_VIEWLGROUP, group, kRadius, viewLabelsDist, color);
}

void HideLocatorsGroup(string group)
{
	int i = FindLoadedLocation();
	if(i < 0) return;
	SendMessage(&Locations[i], "ls", MSG_LOCATION_VIEWLGROUP, group);
}

bool WaitNight()
{
	return true;
	//return WaitNightPause(true);
}


bool WaitNightPause(bool paused)
{
	return true;
	/*
	int i = FindLoadedLocation();
	if(i < 0) return false;
	if(paused == true) SendMessage(&Locations[i], "ll", MSG_LOCATION_PAUSE, true);
	SetEventHandler("FaderEvent_EndFade", "LocationWaitNihgtEndFadeOut", 0);
	object fader;
	CreateEntity(&fader, "fader");
	SendMessage(&fader, "lfl", FADER_OUT, 1.0, false);
	return true;	
	*/
}

void LocationWaitNihgtEndFadeOut()
{
	bool isFadeIn = GetEventData();
	aref fader = GetEventData();
	if(isFadeIn == false)
	{
		SendMessage(&fader, "lfl", FADER_IN, 1.0, true);
	}
	SetEventHandler("FaderEvent_EndFadeIn", "LocationWaitNihgtEndFadeIn", 0);
	DelEventHandler("FaderEvent_EndFade", "LocationWaitNihgtEndFadeOut");
}

void LocationWaitNihgtEndFadeIn()
{
	bool isFadeIn = GetEventData();
	aref fader = GetEventData();
	if(isFadeIn != false)
	{
		DelEventHandler("FaderEvent_EndFadeIn", "LocationWaitNihgtEndFadeIn");
		int i = FindLoadedLocation();
		if(i >= 0)
		{
			SendMessage(&Locations[i], "ll", MSG_LOCATION_PAUSE, false);
		}
		PostEvent("LocationWaitNihgtEnd", 1);
	}	
}
