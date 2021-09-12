/////////////////////////
// GOF 1.2
/////////////////////////

#define DIRECTSAILDEBUG	0;

// #define DIRECTENCOUNTERCHANCE 50   // chance in percent that an encounter fleet appears every hour
#define DIRECTENCOUNTERDISTANCE 1000 // distance from player at which random ships appear

float wmDistanceNow = 75000.0;

//Boyer POTC change
string DiscoveredIsland(float discoveryDistance)
{
    if (DIRECTSAILDEBUG) trace("DiscoveredIsland worldMap.playerShipX = " + worldMap.playerShipX);
	string sReturn = WDM_NONE_ISLAND;
	int nextisland = getWMclosestIsland();
	if(nextisland < 0)
		return sReturn;
	if (DIRECTSAILDEBUG) trace("DiscoveredIsland distance = " + wmDistanceNow);
	if(wmDistanceNow > discoveryDistance)
		return sReturn;
	sReturn = Islands[nextisland].id;
	if (DIRECTSAILDEBUG) trace("DiscoveredIsland found: " + sReturn);
	return sReturn;
}

void CheckIslandChange()
{
	int nextisland = getRTclosestIsland();

	if (DIRECTSAILDEBUG) trace("CheckIslandChange: nextisland=" + nextisland);

	if (nextisland != FindIsland(worldMap.island))
	{
		//only switch if pretty close
		ref rIsland = GetIslandByIndex(nextisland);//makeref(rIsland, Islands[inum]);
		string sNewIslandId = rIsland.id;
		string sIslandNow = worldMap.island;

		float RTplayerShipX = getRTplayerShipX();
		float RTplayerShipZ = getRTplayerShipZ();
		float distToCurIsland;
		if (worldMap.island == WDM_NONE_ISLAND) distToCurIsland = 50000.0;
		else distToCurIsland = GetDistance2D(RTplayerShipX, RTplayerShipZ, stf(worldMap.islands.(sIslandNow).position.x), stf(worldMap.islands.(sIslandNow).position.z));
		float distToClosestIsland = GetDistance2D(RTplayerShipX, RTplayerShipZ, stf(worldMap.islands.(sNewIslandId).position.x), stf(worldMap.islands.(sNewIslandId).position.z));

		if (DIRECTSAILDEBUG) trace("CheckIslandChange: distToCurIsland=" + distToCurIsland + ", distToClosestIsland=" + distToClosestIsland);

		//only change if getting close
		if (distToClosestIsland * 2 > distToCurIsland)
		{
			return;
		}

		// aborts function if enemyships near, so that you aren't teleported out of an engagement
		int enemydist = 0;
		int nextenemy = 0;
		int enemyDistLimit   = 1000;
		int neutralDistLimit = 1000;

		nextenemy = FindClosestShipofRel(GetMainCharacterIndex(), &enemydist, RELATION_ENEMY);
		if (DIRECTSAILDEBUG) trace("DirectsailCheck; next enemy: "+nextenemy + " dist: "+enemydist);
		if(nextenemy!= -1 && enemydist<enemyDistLimit )
		{
			if (DIRECTSAILDEBUG) trace("Directsail aborted due to hostile ship, dist = " + enemydist);	// LDH - 07Jan09
			return;
		}

		// Jan 07, same for neutral ships
		nextenemy = FindClosestShipofRel(GetMainCharacterIndex(), &enemydist, RELATION_NEUTRAL);
		if (DIRECTSAILDEBUG) trace("DirectsailCheck; next neutral ship: "+nextenemy + " dist: "+enemydist);
		if(nextenemy!= -1 && enemydist<neutralDistLimit && Characters[nextenemy].ship.type != SHIP_FORT ) // LDH added fort check 08Jan09
		{
		  if (DIRECTSAILDEBUG) trace("Directsail aborted due to neutral ship, dist = " + enemydist);	// LDH added logit to trace - 07Jan09
		  return;
		}

		// looks like this doesn't always work, so I added another check for being in battle
		if(!bMapEnter) {
			if (DIRECTSAILDEBUG) trace("Directsail aborted in battle");
			return;
		}		// LDH added logit to trace 07Jan09

		ChangeSeaMapNew(sNewIslandId);

	}
 }

float getRTplayerShipX()
{
	float zeroX = MakeFloat(worldMap.zeroX);
	float SeaX = stf(pchar.Ship.Pos.x);
	int scale = WDM_MAP_TO_SEA_SCALE;

	float RTplayerShipX = (SeaX/scale) + zeroX;
	return RTplayerShipX;
}

float getRTplayerShipZ()
{
	float zeroZ = MakeFloat(worldMap.zeroZ);
	float SeaZ = stf(pchar.Ship.Pos.z);
	int scale = WDM_MAP_TO_SEA_SCALE;

	float RTplayerShipZ = (SeaZ/scale) + zeroZ;
	return RTplayerShipZ;
}

float getRTplayerShipAY()
{
	float RTplayerShipAY = stf(pchar.Ship.Ang.y);
	return RTplayerShipAY;
}

//Boyer add
int getWMclosestIsland()
{
	if(DIRECTSAILDEBUG) trace("getWMclosestIsland. curr island: " + worldMap.island);

	float RTplayerShipX = worldMap.playerShipX;
	float RTplayerShipZ = worldMap.playerShipZ:

	float distance;

	int nextisland = -1;
	ref rIsland;
	string islandTemp;
	float scale = 1 / WDM_MAP_TO_SEA_SCALE;

	wmDistanceNow = 75000.0;

	for (int inum=0; inum<MAX_ISLANDS; inum++)
	{
		rIsland = GetIslandByIndex(inum);//makeref(rIsland, Islands[inum]);
		if(!CheckAttribute(rIsland, "id")) {
            //trace("Islands_loader.c no id: " + inum);
            continue;
		}
		islandTemp = rIsland.id;

		if(!CheckAttribute(&worldMap, "islands." + islandTemp)) continue;
		distance = GetDistance2D(RTplayerShipX, RTplayerShipZ, stf(worldMap.islands.(islandTemp).position.x), stf(worldMap.islands.(islandTemp).position.z));
		distance = distance / scale;
		if(DIRECTSAILDEBUG) trace("getWMclosestIsland. islandTemp=" + islandTemp + ", distance=" + distance + ", wmDistanceNow=" + wmDistanceNow);

		if (distance < wmDistanceNow)
		{
			wmDistanceNow = distance
			nextisland = inum;
		}
	}

	if(DIRECTSAILDEBUG) trace("getWMclosestIsland. closest island: " + Islands[nextisland].id + ", idx=" + nextisland);

	return nextisland;
}

int getRTclosestIsland()
{
	if(DIRECTSAILDEBUG) trace("getRTclosestIsland. curr island: " + worldMap.island);

	float RTplayerShipX = getRTplayerShipX();
	float RTplayerShipZ = getRTplayerShipZ();

	float distance;
	float iDistanceNow = 50000.0;

	int nextisland = -1;
	ref rIsland;
	string islandTemp;

	for (int inum=0; inum<MAX_ISLANDS; inum++)
	{
		rIsland = GetIslandByIndex(inum);//makeref(rIsland, Islands[inum]);
		if(!CheckAttribute(rIsland, "id")) continue;
		islandTemp = rIsland.id;

		if(!CheckAttribute(&worldMap, "islands." + islandTemp)) continue;
		distance = GetDistance2D(RTplayerShipX, RTplayerShipZ, stf(worldMap.islands.(islandTemp).position.x), stf(worldMap.islands.(islandTemp).position.z));

		if(DIRECTSAILDEBUG) trace("getRTclosestIsland. islandTemp=" + islandTemp + ", distance=" + distance + ", iDistanceNow=" + iDistanceNow);

		if (distance < iDistanceNow)
		{
			iDistanceNow = distance
			nextisland = inum;
		}
	}

	if(DIRECTSAILDEBUG) trace("getRTclosestIsland. closest island: " + Islands[nextisland].id + ", idx=" + nextisland);

	return nextisland;
}

void ChangeSeaMapNew(string sNewIslandId)
{
	//ShipsInit();
	DeleteSeaEnvironment();
	SetEventHandler("Sea2Sea_Reload", "Sea2Sea_Reload", 0);
	PostEvent("Sea2Sea_Reload", 1);

}

void Sea2Sea_Reload()
{
	DelEventHandler("Sea2Sea_Reload", "Sea2Sea_Reload");

	object seaLoginToSea;

	float CX = getRTplayerShipX();
	float CZ = getRTplayerShipZ();
	float CAY = getRTplayerShipAY();
	int nextisland = getRTclosestIsland();
	ref rIsland = GetIslandByIndex(nextisland);
	string CIsland = rIsland.id;

	float psX = MakeFloat(CX);
	float psZ = MakeFloat(CZ);
	float ix = MakeFloat(worldMap.islands.(CIsland).position.x);
	float iz = MakeFloat(worldMap.islands.(CIsland).position.z);
	int scale = WDM_MAP_TO_SEA_SCALE;

	seaLoginToSea.playerGroup.x = (psX - ix)*scale;
	seaLoginToSea.playerGroup.z = (psZ - iz)*scale;
	seaLoginToSea.playerGroup.ay = CAY;
	seaLoginToSea.island = CIsland;

	string imageName = "loading\sea.tga.tx";
	seaLoginToSea.imageName = imageName;

	SeaLogin(&seaLoginToSea);

	worldMap.playerShipX = getRTplayerShipX();
	worldMap.playerShipZ = getRTplayerShipZ();
	worldMap.playerShipAY = getRTplayerShipAY();
	worldMap.island = rIsland.id;
	worldMap.zeroX = ix;
	worldMap.zeroZ = iz;

}

