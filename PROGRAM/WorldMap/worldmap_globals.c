


#define WDM_NONE_ISLAND		"open_sea"
float	WDM_MAP_TO_SEA_SCALE;					// Set in function InitOpenSeaMod() in PROGRAM\NK.c
float	WDM_MAP_TO_SEA_ENCOUNTERS_SCALE;		// Set in function InitOpenSeaMod() in PROGRAM\NK.c


#define WDM_ETYPE_MERCHANT	0
#define WDM_ETYPE_FOLLOW	1
#define WDM_ETYPE_WARRING	2


object worldMap;

string wdmCurrentIsland = WDM_NONE_ISLAND;


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
	//Boyer add
	int isTornado = rand(1);
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

bool wdmCreateMerchantShip(string islandName, float dltSpeedInPMPercents)
{
    int i1 = -1;
	int i2 = -1;
	float kSpeed = dltSpeedInPMPercents/100.0;
	if(kSpeed >= 0.0)
	{
		kSpeed = kSpeed + 1.0;
	}else{
		kSpeed = 1.0/(1.0 - kSpeed);
	}
	if(GenerateMapEncounter(WDM_ETYPE_MERCHANT, islandName, &i1, &i2) == false) return false;
	string encID = "";
	bool res = wdmCreateMerchantShipByIndex(kSpeed, i1, &encID, "", "", 5+rand(5));
	ReleaseMapEncounters();
	return res;
}

bool wdmCreateMerchantShipByIndex(float kSpeed, int index, ref encID, string from, string to, int timeOutInDays)
{
	string nationShipName = wdmEncounterModelName(index);
	ref mapEncSlotRef = GetMapEncounterRef(index);
	float daysPerSec = 24.0/stf(worldMap.date.hourPerSec);
	float timeOutInSec = daysPerSec*timeOutInDays;
	bool res = SendMessage(&worldMap, "lsssff", MSG_WORLDMAP_CREATEENC_MER, nationShipName, from, to, kSpeed, timeOutInSec);
	WdmCopyEncounterData(mapEncSlotRef, worldMap.EncounterID1);
	encID = worldMap.EncounterID1;
	return res;
}

//if islandName == "" then island finding automatically
bool wdmCreateMerchantShipTime(string islandName, float dltSpeedInPMPercents, float liveTime)
{
    int i1 = -1;
	int i2 = -1;
	float kSpeed = dltSpeedInPMPercents/100.0;
	if(kSpeed >= 0.0)
	{
		kSpeed = kSpeed + 1.0;
	}else{
		kSpeed = 1.0/(1.0 - kSpeed);
	}
	if(liveTime < 1.0) liveTime = 1.0;
	if(GenerateMapEncounter(WDM_ETYPE_MERCHANT, islandName, &i1, &i2) == false) return false;
	string encID = "";
	bool res = wdmCreateMerchantShipByIndex(kSpeed, i1, &encID, "", "", liveTime);
	ReleaseMapEncounters();
	return res;
}

bool wdmCreateFollowShip(string islandName, float dltSpeedInPMPercents)
{
    int i1 = -1;
	int i2 = -1;
	ref mc = GetMainCharacter();
	if(CheckAttribute(mc,"ship.SubmergeDutchman"))  return false;
	float kSpeed = dltSpeedInPMPercents/100.0;
	if(kSpeed >= 0.0)
	{
		kSpeed = kSpeed + 1.0;
	}else{
		kSpeed = 1.0/(1.0 - kSpeed);
	}
	if(GenerateMapEncounter(WDM_ETYPE_FOLLOW, islandName, &i1, &i2) == false) return false;
	string encID = "";
	bool res = wdmCreateFollowShipByIndex(kSpeed, i1, &encID, 5+rand(5)); //homo 07/10/06
	ReleaseMapEncounters();
	return res;
}

bool wdmCreateFollowShipByIndex(float kSpeed, int index, ref encID, int timeOutInDays)
{
	string nationShipName = wdmEncounterModelName(index);
	ref n = GetMapEncounterRef(index);
	int iNation = PIRATE;
	if(CheckAttribute(n, "nation"))
	{
		iNation = sti(n.Nation);
	}
	ref mapEncSlotRef = GetMapEncounterRef(index);
	float daysPerSec = 24.0/stf(worldMap.date.hourPerSec);
	float timeOutInSec = daysPerSec*timeOutInDays;
	bool res = false;
	if(GetNationRelation2MainCharacter(iNation) != RELATION_ENEMY)
	{
		res = SendMessage(&worldMap, "lsssff", MSG_WORLDMAP_CREATEENC_MER, nationShipName, "", "", kSpeed, timeOutInSec);
	}
	else
	{
		res = SendMessage(&worldMap, "lsff", MSG_WORLDMAP_CREATEENC_FLW, nationShipName, kSpeed, timeOutInSec);
	}
	WdmCopyEncounterData(mapEncSlotRef, worldMap.EncounterID1);
	encID = worldMap.EncounterID1;
	return res;
}

bool wdmCreateFollowShipTime(string islandName, float dltSpeedInPMPercents, float liveTime)
{
    int i1 = -1;
	int i2 = -1;
	float kSpeed = dltSpeedInPMPercents/100.0;
	if(kSpeed >= 0.0)
	{
		kSpeed = kSpeed + 1.0;
	}else{
		kSpeed = 1.0/(1.0 - kSpeed);
	}
	if(liveTime < 1.0) liveTime = 1.0;
	if(GenerateMapEncounter(WDM_ETYPE_FOLLOW, islandName, &i1, &i2) == false) return false;
	string encID = "";
	bool res = wdmCreateFollowShipByIndex(kSpeed, i1, &encID, 5+rand(5)); //homo 07/10/06
	ReleaseMapEncounters();
	return res;
}

bool wdmCreateWarringShips(string islandName)
{
	int i1 = -1;
	int i2 = -1;
	if(GenerateMapEncounter(WDM_ETYPE_WARRING, islandName, &i1, &i2) == false)
	{
		ReleaseMapEncounters();
		return false;
	}
	string encID1 = "";
	string encID2 = "";
	bool res = wdmCreateWarringShipsByIndex(i1, i2, &encID1, &encID2, 5+rand(5));  //homo 07/10/06
	ReleaseMapEncounters();
	return res;
}

bool wdmCreateWarringShipsByIndex(int index1, int index2, ref encID1, ref encID2, int timeOutInDays)
{
	string nationShipName1 = wdmEncounterModelName(index1);
	string nationShipName2 = wdmEncounterModelName(index2);
	ref mapEncSlotRef1 = GetMapEncounterRef(index1);
	ref mapEncSlotRef2 = GetMapEncounterRef(index2);
	float daysPerSec = 24.0/stf(worldMap.date.hourPerSec);
	float timeOutInSec = daysPerSec*timeOutInDays;
	bool res = SendMessage(&worldMap, "lssf", MSG_WORLDMAP_CREATEENC_WAR, nationShipName1, nationShipName2, timeOutInSec);
	WdmCopyEncounterData(mapEncSlotRef1, worldMap.EncounterID1);
	WdmCopyEncounterData(mapEncSlotRef2, worldMap.EncounterID2);
	encID1 = worldMap.EncounterID1;
	encID2 = worldMap.EncounterID2;
	return res;
}

bool wdmCreateWarringShipsTime(string islandName, float liveTime)
{
	if(liveTime < 1.0) liveTime = 1.0;
	int i1 = -1;
	int i2 = -1;
	if(GenerateMapEncounter(WDM_ETYPE_WARRING, islandName, &i1, &i2) == false)
	{
		ReleaseMapEncounters();
		return false;
	}
	string encID1 = "";
	string encID2 = "";
	bool res = wdmCreateWarringShipsByIndex(i1, i2, &encID1, &encID2, 5+rand(5));  //homo 07/10/06
	ReleaseMapEncounters();
	return res;
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

void WdmCopyEncounterData(ref mapEncSlotRef, string encStringID)
{
	encStringID = "encounters." + encStringID + ".encdata";
	worldMap.(encStringID) = "";
	aref destRef;
	makearef(destRef, worldMap.(encStringID));
	CopyAttributes(destRef, mapEncSlotRef);
}

void  wdmEmptyAllOldEncounter()
{
    aref encs;
    string sdel,aname;
	bool isWMap = IsEntity(worldMap);

    makearef(encs, worldMap.encounters);

    int num = GetAttributesNum(encs);
    aref enc;
    int  i;

    for (i = 0; i < num; i++)
    {
        enc = GetAttributeN(encs, i);
        if (CheckAttribute(enc, "needDelete") && enc.needDelete == "wdmEncounterDelete")
        {
	        sdel  = "encounters."+GetAttributeName(enc);
			DeleteAttribute(&worldMap, sdel);
	        num--; //fix
	        i--;
	        if (CheckAttribute(enc, "quest")) pchar.worldmap.shipcounter = sti(pchar.worldmap.shipcounter) - 1;
        }
    }
}
