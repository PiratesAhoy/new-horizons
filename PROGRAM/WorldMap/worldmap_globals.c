


#define WDM_NONE_ISLAND		""
float	WDM_MAP_TO_SEA_SCALE;					// Set in function InitOpenSeaMod() in PROGRAM\NK.c
float	WDM_MAP_TO_SEA_ENCOUNTERS_SCALE;		// Set in function InitOpenSeaMod() in PROGRAM\NK.c


#define WDM_ETYPE_MERCHANT	0
#define WDM_ETYPE_FOLLOW	1
#define WDM_ETYPE_WARRING	2


object worldMap;


//=========================================================================================
//Util functions
//=========================================================================================

//Storm functions

int wdmGetNumberStorms()
{
	return MakeInt(worldMap.storm.num);
}

void wdmCreateStorm()
{
	int isTornado = 0;
	SendMessage(&worldMap, "ll", MSG_WORLDMAP_CREATESTORM, isTornado);
}

//Ship encounter functions

int wdmGetNumberShipEncounters()
{
	return MakeInt(worldMap.encounter.num);
}

bool wdmSetCurrentShipData(int shipIndex)
{
	worldMap.encounter.cur = shipIndex;
	int i = MakeInt(worldMap.encounter.cur);
	if(i < 0 || i != shipIndex) return 0;
	return 1;
}

void wdmStoreNewEncounterData(int type) {
	string encId = worldMap.EncounterID1;
	aref encData;
	makearef(encData, worldMap.encounters.(encId).encdata);
	encData.type = type;
}

void wdmStoreNewEncounterData2(int type) {
	string encId = worldMap.EncounterID2;
	aref encData;
	makearef(encData, worldMap.encounters.(encId).encdata);
	encData.type = type;
}

bool wdmCreateMerchantShip(int type, string islandName, float dltSpeedInPMPercents)
{
	float kSpeed = dltSpeedInPMPercents/100.0;
	if(kSpeed >= 0.0)
	{
		kSpeed = kSpeed + 1.0;
	}else{
		kSpeed = 1.0/(1.0 - kSpeed);
	}

	int timeOutInDays = 5+rand(5);
	float daysPerSec = 24.0/stf(worldMap.date.hourPerSec);
	float timeOutInSec = daysPerSec*timeOutInDays;

	string nationShipName = wdmEncounterModelName(type);
	bool success = SendMessage(&worldMap, "lsssff", MSG_WORLDMAP_CREATEENC_MER, nationShipName, "", "", kSpeed, timeOutInSec);
	if (success) {
		wdmStoreNewEncounterData(type);
	}
	return success;
}

bool wdmCreateFollowShip(int type, float dltSpeedInPMPercents)
{
	ref mc = GetMainCharacter();
	if(CheckAttribute(mc,"ship.SubmergeDutchman"))  return false;
	float kSpeed = dltSpeedInPMPercents/100.0;
	if(kSpeed >= 0.0)
	{
		kSpeed = kSpeed + 1.0;
	}else{
		kSpeed = 1.0/(1.0 - kSpeed);
	}
	string nationShipName = wdmEncounterModelName(type);

	int timeOutInDays = 5+rand(5);
	float daysPerSec = 24.0/stf(worldMap.date.hourPerSec);
	float timeOutInSec = daysPerSec*timeOutInDays;

	bool success = SendMessage(&worldMap, "lsff", MSG_WORLDMAP_CREATEENC_FLW, nationShipName, kSpeed, timeOutInSec);
	if (success) {
		wdmStoreNewEncounterData(type);
	}
	return success;
}

bool wdmCreateWarringShips(int type1, int type2)
{
	string nationShipName1 = wdmEncounterModelName(type1);
	string nationShipName2 = wdmEncounterModelName(type2);

	int timeOutInDays = 5+rand(5);
	float daysPerSec = 24.0/stf(worldMap.date.hourPerSec);
	float timeOutInSec = daysPerSec*timeOutInDays;

	bool success SendMessage(&worldMap, "lssf", MSG_WORLDMAP_CREATEENC_WAR, nationShipName1, nationShipName2, timeOutInSec);
	if (success) {
		wdmStoreNewEncounterData(type1);
		wdmStoreNewEncounterData2(type2);
	}
	return success;
}

void wdmReleaseEncounters()
{
	SendMessage(&worldMap, "l", MSG_WORLDMAP_CREATEENC_RELEASE);
}

//Interface

void wdmMessage(string text, string yes, string no)
{
	worldMap.eventWindow.text = text;
	worldMap.eventWindow.yes = yes;
	worldMap.eventWindow.no = no;
	worldMap.eventWindow.update = "";
}

void wdmWaitMenu()
{
	worldMap.waitMenu.update = "";
}

string wdmEncounterModelName(int encIndex)
{
	ref n = GetMapEncounterNationRef(encIndex);
	if(CheckAttribute(n, "worldMapShip") != 0)
	{
		string shipname = n.worldMapShip;
		// NK 05-03-23 add wdm ship model setting -->
		switch(WDMAP_SHIP_SHOW_MODE)
		{
			case 1: if(sti(n.index) != PIRATE) shipname = "ship"; break;
			case 2: shipname = "ship"; break;
			case 3: shipname = "nomodel"; break;
		}
		return shipname;
		// NK <--
	}
	return "ship";	
}
