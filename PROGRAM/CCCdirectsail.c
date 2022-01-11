
// ccc Nov 06 directsailing without worldmap

// ----------------------- Tweaks and settings --------------------------------------

// That makes accurate navigation possible. However, due to the confined worldmap voyages are rather short, and sometimes you appear BEHIND a coast.
// To try this set this to 1, with 0 you'll use the old "islandcell" islandhopping navigation

#define MINES					1		// set to 0 to disable encounters with random mines

int DirectsailCheckFrequency = 15;		// check for new island every this many minutes - 07Jan09, also used for abort distances 12Jan09
int DIRECTENCOUNTERCHANCE;				// Set in function InitOpenSeaMod() in PROGRAM\NK.c
int DIRECTENCOUNTERDISTANCE;			// Set in function InitOpenSeaMod() in PROGRAM\NK.c
float ENCOUNTERBREAK = 1.0;				// Set in function InitOpenSeaMod() in PROGRAM\NK.c

#define DS_DEBUGINFO			0		// Set this to 1 to get on-screen debug information, 0 to get just normal information - 12Jan09


//------------------------ Initial checks and trigger -----------------------------

bool DirectsailCheck(bool ActualUpdate)  // called hourly by Whr_UpdateWeather - now also called by procUpdateTime()
// ever growing list of conditions when Directsail shall NOT run
{
	ref pchar = GetMainCharacter();

	// PB: No DirectSail during Pirate Hunting Quests to prevent breaking them -->
	// UPDATE: This appears not to be necessary; the target ship remains even on heavy DirectSailing
	if( GetAttribute(pchar, "quest.generate_kill_quest") == "begin" && !CheckAttribute(pchar, "quest.kill_pirate_refused_timer") && GetAttribute(pchar, "quest.generate_kill_quest.destination") == pchar.location)
	{
		if (ActualUpdate) LogIt(TranslateString("","Governor Ship Hunting quest active, DirectSail disabled to prevent target ship from disappearing"));
		return false;
	}
	// PB: No DirectSail during Pirate Hunting Quests to prevent breaking them <--
	if( CheckAttribute(pchar,"nodirectsail") )
	{
		if (ActualUpdate) LogIt(TranslateString("","Directsail toggled, press 0 to enable"));
		return false;
	} // ccc Jan07, Directsail can be toggled

	if(pchar.location=="") // Jan07 open sea without island
	{
		if (ActualUpdate)
		{
			Logit(TranslateString("","No island within reach"));  // Jan07, hint added
			Logit(TranslateString("","Enter the map to sail to some island"));
		}
		return false;	// aborts function if location is open sea without island
	}

	// aborts function if enemyships near, so that you aren't teleported out of an engagement
	int enemydist = 0;
	int nextenemy = 0;
	int enemyDistLimit;
	int neutralDistLimit;
	if (DirectsailCheckFrequency < 15 && CheckAttribute(worldmap, "islands."+pchar.location))
	{
		// note: by the time DirectsailCheckFrequency is set to other than default 15, pchar.directsail1 attributes will exist
		if (pchar.directsail1.closestisland != pchar.location && stf(pchar.directsail1.closestdist) < 2000.0/WDM_MAP_TO_SEA_SCALE)
		{
			// LDH 29Jan09
			// if we're very close to an island we're not logged in to,
			// we need stricter limits on how close another ship has to be to prevent island change
			enemyDistLimit   = 500; 
			neutralDistLimit = 400;
		}
		else
		{
			// if we're near the border between two islands but not particularly close a different island, need less strict limits
			enemyDistLimit   = 800; 
			neutralDistLimit = 500;
		}
	}
	else 
	{
		enemyDistLimit   = 1000;
		neutralDistLimit = 1000;
	}

	nextenemy = FindClosestShipofRel(GetMainCharacterIndex(), &enemydist, RELATION_ENEMY);
	if (ActualUpdate) DSTrace("DirectsailCheck; next enemy: "+nextenemy + " dist: "+enemydist);					// LDH changed to DSTrace 08Apr09
	if(nextenemy!= -1 && enemydist<enemyDistLimit ) 
	{
		if (ActualUpdate) DSTrace("Directsail aborted due to hostile ship, dist = " + enemydist);				// LDH - 07Jan09
		GetMapIslandZone(pchar.location); // DirectIslandCoordCheck();				// update the map
		return false;
	}

	// Jan 07, same for neutral ships
	nextenemy = FindClosestShipofRel(GetMainCharacterIndex(), &enemydist, RELATION_NEUTRAL);
	if (ActualUpdate) DSTrace("DirectsailCheck; next neutral ship: "+nextenemy + " dist: "+enemydist);			// LDH changed to DSTrace 08Apr09
	if(nextenemy!= -1 && enemydist<neutralDistLimit && Characters[nextenemy].ship.type != SHIP_FORT_NAME )	// LDH added fort check 08Jan09
	{
		if (ActualUpdate) DSTrace("Directsail aborted due to neutral ship, dist = " + enemydist);				// LDH added logit to trace - 07Jan09
		GetMapIslandZone(pchar.location); // DirectIslandCoordCheck();				// update the map
		return false;
	}

	// looks like this doesn't always work, so I added another check for being in battle
	if(!bMapEnter)
	{
		if (ActualUpdate) DSTrace("Directsail aborted in battle");												// LDH added logit to trace 07Jan09
		return false;
	}

	if(CheckAttribute(pchar, "sailtostring") )
	{
		if (ActualUpdate) Trace("Directsail aborted during sail to");
		return false;
	}
	// ccc Dec17, aborts Directsail if you use the "sail to" interfaceoption

	if(CheckAttribute(pchar,"IsOnDeck") && pchar.IsOnDeck==true)
	{
		if (ActualUpdate) Trace("Directsail aborted below decks");
		return false;
	}
	// Maximus Jan07; aborts Directsail if you are below decks 

	// once all those conditions are checked we trigger an event that runs DS some seconds later
	if (ActualUpdate)
	{
		SetEventHandler("DirectsailRun", "DirectsailRun", 0);  // Jan 07
		int delay = 12000;	// LDH always one game minute delay in sea time -30Dec08
		if(CheckAttribute(GetMainCharacter(),"mapEnter")) { delay = 500; }//MAXIMUS: check added into BattleInterface for islands search after enable MapEnter
		PostEvent("DirectsailRun", delay);  // Jan 07, calls DirectsailRun() after delay to create break
	}
	return true;
}



void DirectsailRun()  // Jan 07, taken out of DirectsailCheck() to create break
{
	DelEventHandler("DirectsailRun", "DirectsailRun");

	ref pchar = GetMainCharacter();

	// check if islandchange takes place
	bool islandswitch = DirectIslandCoordCheck(); // use Screwface's mapcoord method
       

	if(islandswitch)
	{
		// islandchange
		// some eyecandy
		CreateEntity(&SeaFader, "fader");
		SendMessage(&SeaFader, "ls", FADER_PICTURE0, FindReloadPicture("LandHo.tga")); // KK
		SendMessage(&SeaFader, "lfl", FADER_IN, 0.5, true);
		PlaySound("#land_ho"); // KK
		// LDH Only set the encounter flag if we're due for an encounter - 11Feb09
		if(stf(pchar.directsail.count) >= ENCOUNTERBREAK) 
			pchar.directsail.encounter = 1; // for new ships at new island
		// LDH 21Feb09 - Set MapEnter condition for quests, removed when MapEnter condition is checked in ProcessCondition()
		pchar.directsail1.QuestCheckMapEnter = true;

		Sea_ReloadStartDirect();	// reloads Sea with new island at horizon
	}
	else
	{
		if(CheckAttribute(GetMainCharacter(),"mapEnter")) { DeleteAttribute(GetMainCharacter(),"mapEnter"); return; }//MAXIMUS: prevents from uninterrupted encounters (check added into BattleInterface for islands search after enable MapEnter)
		// no islandchange, instead random check if an shipencounter or flotsam shall appear
    
		// Jan07 counter that allows us to set encounterfrequency independent of clockspeed/hourly weatherchange
		if(!CheckAttribute(pchar,"directsail.count")) pchar.directsail.count = 0.0;
		if(stf(pchar.directsail.count) < ENCOUNTERBREAK) 
		{ 
			DSTrace("Directsail encounter aborted, encounterbreak "+stf(pchar.directsail.count));
			return; 
		}

		// PB: Possibility to disable random encounters -->
		if(pchar.location != "")
		{
			ref CurrentIsland = GetIslandByID(pchar.location);
			if(sti(GetAttribute(CurrentIsland, "Enc_enable")) == false)
			{
				DSTrace("Directsail encounter disabled for current island");		// change to DSTrace after testing
				return;
			}
		}
		// PB: Possibility to disable random encounters <--

		// LDH abort here if too close to coast, only for encounters - 29Dec08 - added abort for too close to island transition 09Apr09
		if (CheckAttribute(pchar, "directsail1.closestdist"))
		{
			// LDH added 09Apr09
			if (CheckAttribute(pchar, "directsail1.approaching"))
			{
				DSTrace("Directsail encounter aborted, too close to island transition");	// change to DSTrace after testing
				return;
			}

			float islandDistLimit;
			if (DirectsailCheckFrequency < 15) islandDistLimit = 1500.0; else islandDistLimit = 2000.0;
			if (stf(pchar.directsail1.closestdist) < islandDistLimit/WDM_MAP_TO_SEA_SCALE)
			{
				DSTrace("Directsail encounter aborted, too close to coast of " + FindIslandName(pchar.directsail1.closestisland) + ", " + makeint(sti(pchar.directsail1.closestdist)*WDM_MAP_TO_SEA_SCALE) + " of " + makeint(islandDistLimit) + " yards");
				return;
			}
		}
		else   // jsv: Depended on ACCURATE_NAVIGATION, needs double checking
		{
			float coastzone = GetIslandSize(pchar.location)+1000;
//			if ( abs(stf(pchar.Ship.Pos.x)) < coastzone && abs(stf(pchar.Ship.Pos.z)) < coastzone )			// orig code
			float coastdistance = GetDistance2D(0.0, 0.0, stf(pchar.Ship.Pos.x), stf(pchar.Ship.Pos.z));	// LDH 06Jan09
			if (coastdistance < coastzone)		// LDH 06Jan09
			{	
				DSTrace("Directsail encounter aborted, too close to coast of " + FindIslandName(pchar.location) + ", " + makeint(coastdistance) + " of " + makeint(coastzone));
				return;
			}
		}

		if (DIRECTENCOUNTERCHANCE > rand(100)) // chance check for shipencounter
		{
			// encounter markerattribute is attached to player
			pchar.directsail.encounter = 1;

			CreateEntity(&SeaFader, "fader");
			SendMessage(&SeaFader, "ls", FADER_PICTURE0, FindReloadPicture("SailHo.tga")); // KK
			SendMessage(&SeaFader, "lfl", FADER_IN, 0.5, true);
			PlaySound("#sail_ho");
			Sea_ReloadStartDirect();	// reloads Sea with new ships at horizon
		}
	}
	else	// LDH - this appears to be an error, but executes properly after the preceeding else code if original condition is false
	{
		Randomshipevent(); 	// random shiplife events
		pchar.directsail.count = 0.0;		// LDH - 08Jan09
	}
	if(CheckAttribute(GetMainCharacter(),"mapEnter")) { DeleteAttribute(GetMainCharacter(),"mapEnter"); }//MAXIMUS: check added into BattleInterface for islands search after enable MapEnter
}

// ----------------------------- Island check using worldmap coords --------------------

bool DirectIslandCoordCheck()  // called by DirectsailCheck()
//  Jan07 , uses Screwface's new worldmap coord check
{
	ref pchar = GetMainCharacter();

	DSTrace("directsail runs at " +  FindIslandName(pchar.location));	// LDH translate name 02Jan09

	string toislandname = GetMapIslandzone(pchar.location); // the islandzone you may have sailed into

	if(toislandname != "")
	{
		pchar.directsail.toisland = toislandname; // neighbour island stored as playerattribute for Sea_ReloadDirect function
		// Sea_ReloadDirect & SeaLoginDirect will later recognize from that player attribute that you left OldIsland
		// and delete the current island from the sea environment. The neighbour island is added
    	// and you will be placed so that it looks as if you had arrived from the OldIsland.
		// LDH add bearing and direction to new island 04Mar09
		float x = stf(worldMap.playerShipX)-stf(worldMap.islands.(toislandname).position.x);
		float z = stf(worldMap.playerShipZ)-stf(worldMap.islands.(toislandname).position.z);
		if (z == 0.0) z = 0.00001;	// prevent division by zero
		float dir = atan(x/z);
		if (z > 0.0) dir += PI;
		if(iRealismMode == 0)
		{
			LogIt(TranslateString("","Captain") + ", " + FindIslandName(toislandname) + " " + TranslateString("","in sight") + " "		// LDH translate name 02Jan09
				+ GetBearingFromShip16(dir-stf(pchar.ship.ang.y))						// LDH add bearing 04Mar09
			//	+ " " + GetCompassDirFromHeading16(dir)									// LDH add direction 04Mar09
			);
		}
		else
		{
			LogIt(TranslateString("","Captain, land in sight") + " "												// jsv  remove the land name from the message  16Nov13
				+ GetBearingFromShip16(dir-stf(pchar.ship.ang.y))						// LDH add bearing 04Mar09
			//	+ " " + GetCompassDirFromHeading16(dir)									// LDH add direction 04Mar09
			);
		}
/* keep for testing for now
		dir = Radian2Degree(dir) + 180.0;
		while (dir < 0.0) dir += 360.0;
		while (dir > 360.0) dir -= 360.0;
		if (dir > 180.0) dir -= 360.0;
		LogIt("Bearing to island = " + dir);
*/
		return true;	// returns that islandchange has taken place
	}
	else
	{
		DSTrace("DirectIslandCoordCheck false ");	
		pchar.directsail.toisland = pchar.location;		// LDH used in ship encounters, should be island we're logged into - 08Jan09
		return false;	// returns that NO islandchange has taken place
	}
}

string GetMapIslandzone(string Island)
// Screwface Jan07, converts your Seaview coords to mapcoords and checks if you are near some island
// LDH optimizations - 13Mar09
{
	ref Pchar = GetMaincharacter();

	DSTrace("== Directsail checked island zone at " + GetStringTime(stf(Pchar.CurrentTime)));

	if (!CheckAttribute(worldmap, "islands."+Island))	// LDH so we don't try getting island after mooring - 05Jan09
	{
		DSTrace("** GetMapIslandzone tried to process " + Island);
		return "";
	}

	float psX = MakeFloat(pchar.Ship.Pos.x);
	float psZ = MakeFloat(pchar.Ship.Pos.z);
	float ix = MakeFloat(worldMap.islands.(Island).position.rx);
	float iz = MakeFloat(worldMap.islands.(Island).position.rz);

	//REAL CONVERTION OF YOUR SEAVIEW COORDS IN WORLD MAP COORDS
	worldMap.playerShipX = (psX/WDM_MAP_TO_SEA_SCALE) + ix;
	worldMap.playerShipZ = (psZ/WDM_MAP_TO_SEA_SCALE) + iz;

	float pmX = MakeFloat(worldMap.playerShipX);
	float pmZ = MakeFloat(worldMap.playerShipZ);

	// LDH 29Dec08
	float ClosestDist1 = 99999.0;	// arbitrary high value
	string ClosestIsland1 = "";
	string ClosestDir1 = "";
	float ClosestDist2 = 99999.0;
	string ClosestIsland2 = "";
	string ClosestDir2 = "";
	float ClosestDist3 = 99999.0;
	string ClosestIsland3 = "";
	string ClosestDir3 = "";
	float tempDist = 99999.0;
	string isName;

	// AFTER THAT YOU CHECK IF YOU ARE IN THE RANGE OF ANOTHER ISLAND ON THE WORLDMAP
	for(int i=0; i<ISLANDS_QUANTITY; i++)
	{
		isName = Islands[i].id;
		if(!CheckAttribute(worldMap,"islands."+isName)) continue;
		float isX = stf(worldMap.islands.(isName).position.x);
		float isZ = stf(worldMap.islands.(isName).position.z);

		// LDH - we need to find the closest island that's not the island we're already at - 29Dec08
		tempDist = GetDistance2D(pmX, pmZ, isX, isZ);
		if (tempDist < ClosestDist1)
		{
			ClosestDist3   = ClosestDist2;
			ClosestIsland3 = ClosestIsland2;
			ClosestDir3	   = ClosestDir2;
			ClosestDist2   = ClosestDist1;
			ClosestIsland2 = ClosestIsland1;
			ClosestDir2	   = ClosestDir1;
			ClosestDist1   = tempDist;
			ClosestIsland1 = isName;
			ClosestDir1    = GetCompassDirFromPoints16(pmX, pmZ, isX, isZ);
		}
		else 
		{
			if (tempDist < ClosestDist2)
			{
				ClosestDist3   = ClosestDist2;
				ClosestIsland3 = ClosestIsland2;
				ClosestDir3	   = ClosestDir2;
				ClosestDist2   = tempDist;
				ClosestIsland2 = isName;
				ClosestDir2	   = GetCompassDirFromPoints16(pmX, pmZ, isX, isZ);
			}
			else 
			{
				if (tempDist < ClosestDist3)
				{
					ClosestDist3   = tempDist;
					ClosestIsland3 = isName;
					ClosestDir3    = GetCompassDirFromPoints16(pmX, pmZ, isX, isZ);
				}
			}
		}
	}
/*
	// LDH traces for testing closest island 30Dec08
	DSTrace("=== DirectSail Closest1 " + StrLeft(FindIslandName(ClosestIsland1)+"        ",10) + " distance: " + makeint(ClosestDist1*WDM_MAP_TO_SEA_SCALE) + " yards");
	DSTrace("=== DirectSail Closest2 " + StrLeft(FindIslandName(ClosestIsland2)+"        ",10) + " distance: " + makeint(ClosestDist2*WDM_MAP_TO_SEA_SCALE) + " yards");
	DSTrace("=== DirectSail Closest3 " + StrLeft(FindIslandName(ClosestIsland3)+"        ",10) + " distance: " + makeint(ClosestDist3*WDM_MAP_TO_SEA_SCALE) + " yards");
	DSTrace("=== DirectSail");
*/
	// LDH 03Jan09
	// Now find the closest landfall on these three islands

	float ClosestLandfallDist1 = 99999.0;
	string ClosestLandfallIsland1 = "";
	string ClosestLandfallName1 = "";
	string ClosestLandfallDir1 = "";
	float ClosestLandfallDist2 = 99999.0;
	string ClosestLandfallIsland2 = "";
	string ClosestLandfallName2 = "";
	string ClosestLandfallDir2 = "";

	string LandfallIsland;
	float tempIslandDist;
	string tempLandfall = "";
	string tempLandfallDir = "";

	aref arLandfalls; 
	string sLandfallName;
	int nLandfalls;
	float LFx;
	float LFz;
	for ( int j=0 ; j<3 ; j++ )
	{
		switch(j)
		{
			case 0: LandfallIsland = ClosestIsland1; tempIslandDist = ClosestDist1; tempLandfallDir = ClosestDir1; break; // added dir 15Jan09
			case 1: LandfallIsland = ClosestIsland2; tempIslandDist = ClosestDist2; tempLandfallDir = ClosestDir2; break;
			case 2: LandfallIsland = ClosestIsland3; tempIslandDist = ClosestDist3; tempLandfallDir = ClosestDir3; break;
		}
		makearef(arLandfalls, worldMap.islands.(LandfallIsland).locations);

		tempIslandDist = 99999.0;
		tempLandfall = "";
		nLandfalls = GetAttributesNum(arLandfalls);
		for( i=0 ; i<nLandfalls ; i++)
		{
			sLandfallName = GetAttributeName(GetAttributeN(arLandfalls,i));
			LFx = stf(arLandFalls.(sLandfallName).position.x);
			LFz = stf(arLandFalls.(sLandfallName).position.z);
			tempDist = GetDistance2D(pmX, pmZ, LFx, LFz);

			if (tempDist < tempIslandDist)
			{
				tempIslandDist = tempDist;
				// Screwface : should fix the no-existing label error
				if (Checkattribute(arLandfalls,(sLandfallName) + ".label"))
				{
					if (worldMap.islands.(LandfallIsland).locations.(sLandfallName).label.text == "")
						tempLandfall = worldMap.islands.(LandfallIsland).locations.(sLandfallName).label.old.text;
					else
						tempLandfall = worldMap.islands.(LandfallIsland).locations.(sLandfallName).label.text;
				}
			}
		}
		
		// LDH add additional location checks here - 07Jan09
		for(i=0; i<ISLANDS_QUANTITY; i++)
		{
			if ( LandfallIsland == Islands[i].id) break;
		}
		makearef(arLandfalls, Islands[i].reload);
		nLandfalls = GetAttributesNum(arLandfalls);
		// for each reload, translate the location and get the name
		for( i=0 ; i<nLandfalls ; i++)
		{
			string tempattrname = GetAttributeName(GetAttributeN(arLandfalls,i));
			sLandfallName = arLandfalls.(tempattrname).label;
			if (CheckAttribute(arLandfalls, tempattrname+".x"))
			{
				LFx = stf(arLandfalls.(tempattrname).x)/WDM_MAP_TO_SEA_SCALE + stf(worldMap.islands.(LandfallIsland).position.rx);
				LFz = stf(arLandfalls.(tempattrname).z)/WDM_MAP_TO_SEA_SCALE + stf(worldMap.islands.(LandfallIsland).position.rz);
			}
			else
			{
				// this is mostly to handle battle_rocks, which doesn't have any landfalls
				LFx = stf(worldMap.islands.(isName).position.x);
				LFz = stf(worldMap.islands.(isName).position.z);
			}

			tempDist = GetDistance2D(pmX, pmZ, LFx, LFz);

			if (tempDist < tempIslandDist)
			{
				tempIslandDist  = tempDist;
				tempLandfall    = sLandfallName;
				tempLandfallDir = GetCompassDirFromPoints16(pmX, pmZ, LFx, LFz);
			}
		}
		
		if (tempIslandDist < ClosestLandfallDist1)
		{
			ClosestLandfallDist2 = ClosestLandfallDist1;
			ClosestLandfallIsland2 = ClosestLandfallIsland1;
			ClosestLandfallName2 = ClosestLandfallName1;
			ClosestLandfallDir2  = ClosestLandfallDir1;
			ClosestLandfallDist1 = tempIslandDist;
			ClosestLandfallIsland1 = LandfallIsland;
			ClosestLandfallName1 = tempLandfall;
			ClosestLandfallDir1  = tempLandfallDir;
		}
		else
		{
			if (tempIslandDist < ClosestLandfallDist2)
			{
				ClosestLandfallDist2 = tempIslandDist;
				ClosestLandfallIsland2 = LandfallIsland;
				ClosestLandfallName2 = tempLandfall;
				ClosestLandfallDir2  = tempLandfallDir;
			}
		}
	}

	string strLog;

	strLog = "=== DirectSail Closest1 ";
	strLog += StrLeft(FindIslandName(ClosestLandfallIsland1)+"        ",10) + " ";
	if (ClosestLandfallName1 == "")
	{
		strLog += "                    ";
	}
	else
	{
		strLog += StrLeft(ClosestLandfallName1+"                    ",20);
	}
	strLog += " distance: " + makeint(ClosestLandfallDist1*WDM_MAP_TO_SEA_SCALE) + " yards";
	strLog += " " + ClosestLandfallDir1;
	DSTrace(strLog);

	strLog = "=== DirectSail Closest2 ";
	strLog += StrLeft(FindIslandName(ClosestLandfallIsland2)+"        ",10) + " ";
	if (ClosestLandfallName2 == "")
	{
		strLog += "                    ";
	}
	else
	{
		strLog += StrLeft(ClosestLandfallName2+"                    ",20);
	}
	strLog += " distance: " + makeint(ClosestLandfallDist2*WDM_MAP_TO_SEA_SCALE) + " yards";
	strLog += " " + ClosestLandfallDir2;
	DSTrace(strLog);
/*
	strLog = "=== DirectSail Closest3 ";
	strLog += StrLeft(FindIslandName(ClosestLandfallIsland3)+"        ",10) + " ";
	if (ClosestLandfallName3 == "")
	{
		strLog += "                    ";
	}
	else
	{
		strLog += StrLeft(ClosestLandfallName3+"                    ",20);
	}
	strLog += " distance: " + makeint(ClosestLandfallDist3*WDM_MAP_TO_SEA_SCALE) + " yards";
	strLog += " " + ClosestLandfallDir3;
	DSTrace(strLog);
*/
	pchar.directsail1.closestdist = ClosestLandfallDist1;
	pchar.directsail1.closestisland = ClosestLandfallIsland1;

	// LDH 07Jan09
//	if ( ClosestlandfallDist1 + ClosestlandfallDist2 < 5000.0/WDM_MAP_TO_SEA_SCALE )		// under 5000 yards
	// if we're likely to cross into another island zone in less than 15 minutes - 20Jan09
	// Note: speed in knots times about 100 gives yards traveled in 15 game minutes, 180 sec real time
	float transitionDistance = (ClosestlandfallDist2 - ClosestlandfallDist1)/2.0*WDM_MAP_TO_SEA_SCALE;
	if ( stf(pchar.Ship.Speed.z) * 100.0 > transitionDistance || Island != ClosestLandfallIsland1 ) 
		DirectsailCheckFrequency = 5;		// check every 5 minutes
	else	
		DirectsailCheckFrequency = 15;		// check every 15 minutes

	strLog = "= Directsail speed = " + stf(pchar.Ship.Speed.z) +
		", Diff in distances / 2 = " + ((ClosestlandfallDist2 - ClosestlandfallDist1)/2.0*WDM_MAP_TO_SEA_SCALE) +
		", Check frequency = " + DirectsailCheckFrequency;
	DSTrace(strLog);

	// LDH 04Apr09
	// jsv 16Nov13  Do not tell the player about approching an island anymore. NB directsail1.approaching is used elsewhere 
	// to prevent random encounters near the land, so its setting and unsetting should be left intact.
	if (stf(pchar.Ship.Speed.z) * 50.0 > transitionDistance)	// if 7.5 minutes sailing can put us closer to another island
	{
		if (!CheckAttribute(pchar, "directsail1.approaching"))	// the first time this happens, tell the player
		{
			pchar.directsail1.approaching = FindIslandName(ClosestLandfallIsland2);
			if(iRealismMode == 0)
			{
				LogIt(TranslateString("","Captain, we are approaching") + " " + pchar.directsail1.approaching + ".");
				PlayStereoSound("notebook_note");
			}
		}
		else
		{
			if (pchar.directsail1.approaching != FindIslandName(ClosestLandfallIsland2) &&
				pchar.directsail1.approaching != FindIslandName(ClosestLandfallIsland1))
			{
				pchar.directsail1.approaching = FindIslandName(ClosestLandfallIsland2);		// if we approach a third island, tell the player
				if(iRealismMode == 0)
				{
					LogIt(TranslateString("","Captain, we are approaching") + " " + pchar.directsail1.approaching + "!");
					PlayStereoSound("notebook_note");
				}
			}
		}
	}
	else
	{
		DeleteAttribute(pchar, "directsail1.approaching");
	}

	if (ClosestLandfallDist1 < 6000.0/WDM_MAP_TO_SEA_SCALE && Island != ClosestLandfallIsland1)
	{
		return ClosestLandfallIsland1;
	}

	DSTrace("At mapcoords x " + pmX + " z "+pmZ+" you are in no new islandzone");

	return ""; // default
}




// -------------------------------- Reloading of sea environment -----------------------------------------

void Sea_ReloadStartDirect()  // called by DirectsailCheck, structure like original Sea_ReloadStart
{
	if (!bSeaActive) { return; }
	DeleteSeaEnvironment();
	
	SetEventHandler("Sea_ReloadDirect", "Sea_ReloadDirect", 0);
	PostEvent("Sea_ReloadDirect", 1.0);
}



void Sea_ReloadDirect() // Jan 07, new version by Screwface that works also with worldmapcoords
// called by Sea_ReloadStartDirect(), structure like original Sea_Reload
{
	DelEventHandler("Sea_ReloadDirect", "Sea_ReloadDirect");

	ReloadProgressStart(); // KK

	ref rPlayer = GetMainCharacter();

	object Login;
	Login.PlayerGroup.ay = stf(rPlayer.Ship.Ang.y);
	Login.PlayerGroup.x = MakeFloat(rPlayer.ship.pos.x); 
	Login.PlayerGroup.y = 0.0;
	Login.PlayerGroup.z = MakeFloat(rPlayer.ship.pos.z);
	Login.Island = Characters[0].location;

	if(CheckAttribute(rPlayer,"directsail.toisland"))
	// if Directsail() calls islandchange island and playerposition are changed
	{
		Login.Island = rPlayer.directsail.toisland;
		string toislandname = rPlayer.directsail.toisland;

		// SECTION TO APPEAR IN THE NEW REAL POSITION AT THE NEW ISLAND 
		float psX = MakeFloat(worldMap.playerShipX);
		float psZ = MakeFloat(worldMap.playerShipZ);

		float ix = MakeFloat(worldMap.islands.(toislandname).position.rx);
		float iz = MakeFloat(worldMap.islands.(toislandname).position.rz);
		Login.playerGroup.x = (psX - ix)*WDM_MAP_TO_SEA_SCALE;
		Login.playerGroup.z = (psZ - iz)*WDM_MAP_TO_SEA_SCALE;

		Login.PlayerGroup.ay = stf(rPlayer.Ship.Ang.y); // your old heading
	}
	DSTrace("Sea_reloadDirect at "+ FindIslandName(Login.Island));	// LDH translate name 02Jan09

	Login.DirectSail = true;

	SeaLogin(&Login); // KK

	ReloadProgressEnd(); // KK
}


//-------------------------------- Encounters and events -----------------------------------

void DirectEncounter(float encay)  // called by SeaLoginDirect
// creates ships that appear in the direction encay (playerheading as currently called )
{
	int i, j;
	float x, z, ay;
	ref rGroup;
	ref rPlayer = GetMainCharacter();
//	string groupname = "Directenc"+rand(100);
	// PB: Attemped CTD Fix -->
	string groupname;
	if(CheckAttribute(rPlayer, "DirectSailEncounterGroup")) rPlayer.DirectSailEncounterGroup = sti(rPlayer.DirectSailEncounterGroup) + 1;
	else rPlayer.DirectSailEncounterGroup = 1;
	if(rPlayer.DirectSailEncounterGroup > 20) rPlayer.DirectSailEncounterGroup = 1;
	groupname = "Directenc" + sti(rPlayer.DirectSailEncounterGroup);
	// PB: Attemped CTD Fix <--
	int Encnation = rand(NATIONS_QUANTITY-1); // PB: Use actual nation quantity to select RANDOM nation for encounterships
	// int Encnation = FindEnemyNation2Character(GetMainCharacterIndex()); // another choice: Only ENEMY encounters

	// ships shall appear ahead of player(aprox!), so we set coords according to player coords & heading
//	encay = encay - 1.5 + rand(3); // random deviation from playerheading, so that ships are not always dead ahead
	float bearing = randnorm(60.0, 30.0);		   // LDH better random number for bearing - 10Jan09
	if (bearing > 90.0) bearing = 180.0 - bearing;
	if (rand(1)) bearing = -bearing;
	if (bearing > 180.0) Bearing -= 360.0;
	DSTrace("Encounter - bearing to ship " + makeint(bearing));

	encay += Degree2Radian(bearing);
	z = stf(rPlayer.Ship.Pos.z) + (cos(encay)*DIRECTENCOUNTERDISTANCE); // add Z component
	x = stf(rPlayer.Ship.Pos.x) + (sin(encay)*DIRECTENCOUNTERDISTANCE); // add X component

	LogIt(TranslateString("","Strange sail") + " " + GetBearingFromShip16(Degree2Radian(bearing)));	// LDH 26Feb09
	ay = randnorm(encay + 3.2, Degree2Radian(20.0));	// LDH random heading 29Jan09
	ReloadProgressUpdate();

	Sea_AddGroup2TaskList(groupname);

	rGroup = Group_GetGroupByIndex(Group_CreateGroup(groupname));
	Group_SetXZ_AY(groupname, x, z, ay);
	Group_SetType(groupname, "war");
	Group_DeleteAtEnd(groupname);

	// encountertype
	int enctype;
	if(Encnation == PIRATE)		enctype = FindEncounter(ENCOUNTER_WAR, Encnation);	// PB: Pirates only have War encounters
	else						enctype = FindEncounter(rand(1), Encnation);		// PB: Use only valid encounter types for that nation, 0 = Trade, 1 = War
	int iNumShips = Fantom_GenerateEncounter(groupname, enctype, Encnation);

	DSTrace("Directsail encounter type: " + enctype + ", at x = " + x + ", z = " + z);

	// load ships to sea
	if (iNumShips > 0) LoadShipsToSea(iNumShips, groupname, Encnation, -1); // KK

	// task: ENEMY attacks you, others sail towards you
	if (GetRMRelationType(GetRMRelation(GetMainCharacter(),Encnation)) != RELATION_ENEMY)
	{
		// LDH 29Jan09
		x = x + 10000.0 * sin(ay);
		z = z + 10000.0 * cos(ay);
		Group_SetTaskMove(groupname, x, z);
//		Group_SetTaskMove(groupname, stf(rPlayer.ship.pos.x), stf(rPlayer.ship.pos.z));
		Trace("Directsail encounter nation: " + Encnation + ", task move ");
	} else {
		Group_SetTaskAttack(groupname, PLAYER_GROUP, false); // PB: Relations should already be hostile
		Group_LockTask(groupname);
		Trace("Directsail encounter nation: " + Encnation + ", task attack ");
		UpdateRelations();
	}

	ReloadProgressUpdate();
	Trace("Directencounter done ");
}



void Randomshipevent()
// jan 07 creates random shiplife events
// for the time being only flotsam
{
	ref pchar = GetMainCharacter();
	float bearing = randnorm(30.0, 30.0);		   // LDH better random number for bearing - 10Jan09
	if (bearing > 90.0) bearing = 180.0 - bearing;
	if (rand(1)) bearing = -bearing;
	if (bearing > 180.0) bearing -= 360.0;
	DSTrace("Encounter - bearing to flotsam " + makeint(bearing));
	bearing = Degree2Radian(bearing);

	int sp = 9 - stf(ShipsTypes[GetCharacterShipType(pchar)].Class); // factor that increases amount of goodies for higher ship tiers

	string sound = "objects\shipcharge\CannonReload-000.wav";
	string message = "Captain, there is something drifting in the water";

	switch(rand( 22 ) ) // 22 greater than number of cases to create blanks, increase for more
	{
		case 1:
			Direct_AddGood(pchar, "Sailcloth", "roll_of_rolls", 400.0, (rand(20)+5)*sp, 200, bearing);
		break;

		case 2:
			Direct_AddGood(pchar, "Planks", "roll_of_planks", 400.0, (rand(20)+5)*sp, 200, bearing);
		break;

		case 3:
			Direct_AddGood(pchar, "Wheat", "sack", 400.0, (rand(10)+2)*sp, 200, bearing);
		break;

		case 4:
			Direct_AddGood(pchar, "Rum", "barrel", 400.0, (rand(10)+2)*sp, 200, bearing);
		break;

		case 5:
			Direct_AddGood(pchar, "Gunpowder", "barrel", 400.0, (rand(10)+2)*sp, 200, bearing);
		break;

		case 6:
			Direct_AddGood(pchar, "Ebony", "roll_of_planks", 400.0, (rand(10)+2)*sp, 200, bearing);
		break;

		case 7:
			Direct_AddGood(pchar, "Mahogany", "roll_of_planks", 400.0, (rand(20)+5)*sp, 200, bearing);
		break;

		case 8:
			Direct_AddGood(pchar, "Silk", "roll_of_rolls", 400.0, (rand(20)+5)*sp, 200, bearing);
		break;

		case 9:
			Direct_AddGood(pchar, "Sandal", "bale", 400.0, (rand(20)+5)*sp, 200, bearing);
		break;

		case 10:
			Direct_AddGood(pchar, "Cinnamon", "bale", 400.0, (rand(20)+5)*sp, 200, bearing);
		break;

		case 11:
			bearing = 0.0;	// LDH added 02Feb09
			// SWS: Distance increased to allow evasive action on fast and slow responding ships
			Direct_AddGood(pchar, "Oil", "log", 1000.0, 102, 175, bearing); // 102 trunk, dead ahead
			sound = "objects\shipcharge\_Abandon3.wav";
			message = "Captain, something is drifting there";
		break;

		case 12:
			bearing = 0.0;	// LDH added 02Feb09
			// SWS: Distance increased to allow evasive action on fast and slow responding ships
			Direct_AddGood(pchar, "Oil", "log", 1000.0, 102, 230, bearing); // 102 trunk, repeated to increase frequency
			sound = "objects\shipcharge\_Abandon3.wav";
			message = "Captain, something is drifting there";
		break;

		case 13:
			Direct_AddGood(pchar, "Oil", "boat", 3000.0, (rand(5)+2)*sp, 500, bearing); // lifeboat with survivors
			message = "Captain, a boat has been sighted";
		break;

		case 14:
			Direct_AddGood(pchar, "Oil", "boat", 3000.0, (rand(5)+2)*sp, 500, bearing); // lifeboat with survivors
			message = "Captain, a boat has been sighted";
		break;

		case 15:
			Direct_AddGood(pchar, "Oil", "indianraft", 3000.0, 103, 800, bearing); // 103 indian raft
			message = "Captain, a native raft has been sighted";
		break;

		case 16:
			Direct_AddGood(pchar, "Oil", "hulk", 3000.0, 104, 800, bearing); // 104 abandoned hulk
			message = "Captain, a dismasted vessel has been sighted";
		break;

		case 17:
			Direct_AddGood(pchar, "Oil", "hulk", 3000.0, 104, 800, bearing); // 104 abandoned hulk
			message = "Captain, a dismasted vessel has been sighted";
		break;

		case 18:
			if (MINES && GetCurrentPeriod() >= PERIOD_REVOLUTIONS) {
				bearing = 0.0;	// LDH added 02Feb09
				// SWS: Distance increased to allow evasive action on fast and slow responding ships
				Direct_AddGood(pchar, "Oil", "mine", 1000.0, 101, 300, bearing); // 101 mine, dead ahead
				sound = "objects\shipcharge\_Abandon3.wav";
				message = "Captain, something is drifting there";
			} else {
				message = "";
			}
		break;

		// default:
		message = ""; // blank, nothing happens
	}

	if(message != "") { 
		Logit(TranslateString("",message) + " " + GetBearingFromShip16(bearing));
		PlayStereoSound(sound);

		ResetTimeToNormal(); // PB: Reset Time Scale
	}
}

void Direct_AddGood(ref rCharacter, string sGood, string sModel, float fTime, int iQuantity, float dist, float bearing)
// ccc Jan 07, mostly like AISeaGoods_AddGood, but salvage is set at a certain dist from rCharacter
// bearing is the angle to the flotsam's position from the ship heading: 0= ahead, 1.6=right, 3.2=astern, 4.8=left 
{
	if (!bSeaActive) return;

	Trace("Add good direct : " + sGood + ", rCharacter.id = " + rCharacter.id + ", iQuantity = " + iQuantity);

	// calculate position from ship according to dist and bearing
	float ay = stf(rCharacter.Ship.Ang.y) + bearing; // get angle
	float z = cos(ay)*dist; // add Z component
	float x = sin(ay)*dist; // add X component

	AISeaGoods.Good = sGood;
	AISeaGoods.Pos.x = stf(rCharacter.Ship.Pos.x) + x;
	AISeaGoods.Pos.z = stf(rCharacter.Ship.Pos.z) + z;

	AISeaGoods.CharIndex = "9"; // must NOT be rCharacter.Index, cause AISeaGoods_ShipEatGood() returns false if salvage and salvager have the same index; assume that 9 is not used for any shipcaptain

	AISeaGoods.Time = fTime;
	AISeaGoods.Quantity = iQuantity;
	AISeaGoods.Model = sModel;
	AISeaGoods.Add = "";

	// PB: Kraken Attack -->
	if(HasSubStr(sModel,"tentacle"))
	{
		PlayStereoSound("objects\shipcharge\take_prey.wav");
		CreateParticleSystemX("tentacle_appears",stf(rCharacter.Ship.Pos.x) + x, 5, stf(rCharacter.Ship.Pos.z) + z, 0, 0, 0, 0);
	}
	// PB: Kraken Attack <--
}


void LaunchMine(ref rCharacter)
// ccc Jan 07, places mine "good" behind ship of rCharacter.
// a new check in AISeaGoods_ShipEatGood() explodes any ship that sails onto that mine
{
	if (!bSeaActive) return;

	if(GetCargoGoods(rCharacter, GOOD_GUNPOWDER)>300 ) // you need gunpowder for a mine
	{
		AddCharacterGoods(rCharacter, GOOD_GUNPOWDER, -300 );
		float dist = 51.0-(stf(ShipsTypes[GetCharacterShipType(rCharacter)].Class)*4); // drop distance from shipcenter, depending on shipsize

		// calculate dropping position astern of ship
		float ay = stf(rCharacter.Ship.Ang.y) + 3.0; // get angle astern
		float z = cos(ay)*dist + stf(rCharacter.Ship.Pos.z); // Z coord
		float x = sin(ay)*dist + stf(rCharacter.Ship.Pos.x); // X coord

		// place mine "good" behind ship
		AISeaGoods.Good = "oil";
		AISeaGoods.Pos.x = x;
		AISeaGoods.Pos.z = z;

		AISeaGoods.CharIndex = "9"; // must NOT be rCharacter.Index, cause AISeaGoods_ShipEatGood() returns false if salvage and salvager have the same index; assume that 9 is not used for any shipcaptain

		AISeaGoods.Time = 5000;
		AISeaGoods.Quantity = 101;
		AISeaGoods.Model = "mine";
		AISeaGoods.Add = "";

		// launch effects
		PlayStereoSound("objects\shipcharge\ball_splash1.wav");
		Logit(TranslateString("","Mine launched"));
		CreateParticleSystemX("ball_splash", x, 1.0, z, 0.0, 3.0, 0.0, 2);
	} else {
		Log_SetStringToLog(TranslateString("", "You don't have enough gunpowder for a mine") + "!");
	}
}


void SwimGoodEvent(ref rCharacter, int iQuantity)
// ccc Jan 07, special events that happen if you sail over flotsam of a certain kind
// called by AISeaGoods_ShipEatGood() if you sail over "swim goods" of the oil type
{
	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");//MAXIMUS: moved here
	int n;
	ref pchar = GetMainCharacter();
	int sp = 9 - stf(ShipsTypes[GetCharacterShipType(pchar)].Class); // factor that increases amount of goodies for bigger shipclasses

// KK -->
	switch(iQuantity) // Direct_AddGood calls with certain quantities of oil determine encountertype
	// rest ensured, that is a safe method: the game will never ever create more that 100 "swim goods" of oil
	{
		case 101: // 101 mine
			if (!IsMainCharacter(rCharacter)) {
				AddPartyExp(PChar, 1000*sp);
				Log_SetStringToLog(XI_ConvertString(GetShipTypeName(rCharacter)) + " " + GetMyShipNameShow(rCharacter) + " " +TranslateString("","damaged on mine") + "!");   //screenmessage
			} else {
				AddPartyExp(PChar, 100 * sp);
				Log_SetStringToLog(TranslateString("","We have hit a mine!"));   //screenmessage
			}
			Ship_Detonate(rCharacter, true, true);
		break;

		case 102: // 102 floating trunk
			rCharacter.ship.hp = makeint(sti(rCharacter.ship.hp) * (70+ rand(20)) / 100 ); // ship hp reduced to 70 - 90%
			if (IsMainCharacter(rCharacter)) {
				Logit(TranslateString("","We have collided with a drifting trunk!"));   //screenmessage
				if (ENABLE_EXTRA_SOUNDS == 1) PlaySound("objects\shipcharge\hit_torock.wav");
			}
		break;

		case 103: // 103 indian raft
			if (!IsMainCharacter(rCharacter)) break;  //runs only for the player
			if (ENABLE_EXTRA_SOUNDS == 1) PlaySound("#cargo_aboard");

			switch(rand(4) )
			{
				case 1:
					for (n = 1; n < 17; n++)
					{
						TakenItems(rCharacter, "indian" + n, rand(1) * sp);
					}
					Logit(TranslateString("","You find some votive items on an Indian ceremonial raft"));
				break;

				case 2:
					for (n = 1; n < 5; n++)
					{
						TakenItems(rCharacter, "potion" + n, rand(4) * sp);
					}
					Logit(TranslateString("","You find some burial objects on a witch doctor's funeral raft"));
				break;

				case 3:
					for (n = 1; n < 10; n++)
					{
						if (n > 3 && n < 7) continue;
						TakenItems(rCharacter, "mineral" + n, rand(1) * sp );
					}
					Logit(TranslateString("","You find some burial objects on a voodoo priest's funeral raft"));
				break;

				Logit(TranslateString("","This Indian funeral raft has already been plundered...")); // default, bad luck event
			}
		break; // 103

		case 104: // 104 abandoned hulk
			if (!IsMainCharacter(rCharacter)) break;  //runs only for the player
			if (ENABLE_EXTRA_SOUNDS == 1) PlaySound("#cargo_aboard");

			switch(rand(4) )
			{
				case 1:
					for (n = 1; n < 17; n++)
					{
						TakenItems(rCharacter, "jewelry" + n, rand(1) * sp);
					}
					Logit(TranslateString("","You find some jewels on an abandoned packet boat"));
				break;

				case 2:
					AddMoneyToCharacter(rCharacter, (rand(10000) + 1000) * sp);
					Logit(TranslateString("","You find some money on an abandoned packet boat"));
				break;

				case 3:
					AddCharacterGoods(rCharacter, GOOD_BOMBS, rand(200) * sp);
					AddCharacterGoods(rCharacter, GOOD_GUNPOWDER, rand(5000) * sp);
					TakenItems(rCharacter, "pistolgrenade", rand(20) * sp);
					Logit(TranslateString("","You find some ordinance on an abandoned ammo tender"));
				break;

				Logit(TranslateString("","Someone has already emptied this abandoned hulk") + "..."); // default, bad luck event
			}
		break; // 104

		case 105: // KRAKEN ATTACK
		//	/*
			float fX = stf(rCharacter.Ship.pos.x);
			float fY = stf(rCharacter.Ship.pos.y);
			float fZ = stf(rCharacter.Ship.pos.z);
			if(rand(1) == 0) CreateParticleSystem("flyers",      fX+4-rand(8), fY+4-rand(8), fZ+4-rand(8), 0.0, 0.0, 0.0, 0);		// Petros adds one crew flying overboard
			if(rand(1) == 0) CreateParticleSystem("flyers2",     fX+4-rand(8), fY+4-rand(8), fZ+4-rand(8), 0.0, 0.0, 0.0, 0);
			if(rand(1) == 0) CreateParticleSystemX("ball_splash",fX+4-rand(8), fY+4-rand(8), fZ+4-rand(8), 3.0, 7.0, 0.0, 0);
			if(rand(1) == 0) CreateParticleSystemX("ball_splash",fX+4-rand(8), fY+4-rand(8), fZ+4-rand(8), 0.0, 7.0, 3.0, 0);
			if(rand(1) == 0) CreateParticleSystemX("ball_splash",fX+4-rand(8), fY+4-rand(8), fZ+4-rand(8), -2.0, 8.0, 0.0, 0);
			if(rand(1) == 0) CreateParticleSystemX("ball_splash",fX+4-rand(8), fY+4-rand(8), fZ+4-rand(8), 0.0, 9.0, -3.0, 0);
			if(rand(1) == 0) CreateParticleSystemX("gunfire",    fX+4-rand(8), fY+4-rand(8), fZ+4-rand(8), 6.0, 4.0, 0.0, 0);
			if(rand(1) == 0) CreateParticleSystemX("gunfire",    fX+4-rand(8), fY+4-rand(8), fZ+4-rand(8), 0.0, 4.0, 7.0, 0);
			if(rand(1) == 0) CreateParticleSystemX("gunfire",    fX+4-rand(8), fY+4-rand(8), fZ+4-rand(8), -6.0, 5.0, 0.0, 0);
			if(rand(1) == 0) CreateParticleSystemX("gunfire",    fX+4-rand(8), fY+4-rand(8), fZ+4-rand(8), 0.0, 5.0, -7.0, 0);
			if(rand(3) == 0) 
		//	*/
				Ship_Detonate(rCharacter, false, false);						// create graphics
			Ship_ApplyHullHitpoints(rCharacter, 200.0, KILL_BY_TOUCH, -1);	// do damage
		break;

  // more events will be added in the future

		// Default: original rescue survivors code from AISeaGoods.c
			n = GetFreeCrewQuantity(rCharacter);
			if (iQuantity > n) iQuantity = n;
			if (iQuantity > 0) {
				AddCharacterCrew(rCharacter, iQuantity);   //adds crew
				if (IsMainCharacter(rCharacter)) { //runs only for the player
					Log_SetStringToLog("" + iQuantity + " " + TranslateString("","survivors rescued"));   //screenmessage
					if (ENABLE_EXTRA_SOUNDS == 1) PlaySound("objects\abordage\abordage_loosing.wav");   //soundeffect
				}
				ChangeCharacterReputation(rCharacter, 1);   //rescuer deserves praise :)
			}
// <-- KK
		// ccc rescue survivors end

	}
	//LanguageCloseFile(tmpLangFileID);//MAXIMUS: moved here
}



// ------------------- Utilities ---------------------------------------------

float GetIslandSize(string island)   // ccc Jan07 returns the aprox radius of an islands coastline
{
	switch(island)
	{
		case "Redmond": return 2000.0; break;
		case "IslaMuelle": return 2000.0; break;
		case "Oxbay": return 2000.0; break;
		case "Conceicao": return 2000.0; break;
		case "Hispaniola": return 7000.0; break;
		case "Cuba": return 8000.0; break;
		case "IslaDeMuerte": return 100.0; break; // KK

		return 1000.0;  // default size for average island
	}
}


string GetCompassDirFromAY(float ay)
{
	// TraceAndLog("Compass Ay before " + ay );
	while(ay < 0) {ay += 6.3;}
	while(ay > 6.3) {ay -= 6.3;}
	// TraceAndLog("Ay corrected " + ay );

	if(ay < 0.4) return "south";
	if(ay < 1.2) return "southwest";
	if(ay < 2.0) return "west";
	if(ay < 2.8) return "northwest";
	if(ay < 3.55) return "north";
	if(ay < 4.35) return "northeast";
	if(ay < 5.15) return "east";
	if(ay < 5.9) return "southeast";
	if(ay < 6.31) return "south";
	return "somewhere"; // just in case :)
}


void ProcessCCCkeys(string ControlName) // Jan07, called by Seadogs.c. Put the code here so that I don't have to mess with seadogs.c for every control change
{
 	if(bSeaActive && !bAbordageStarted) // checks if you are in sailing mode
	{
		switch(ControlName)
		{
			 case "BI_ChargeKey9": //"Minedrop":
				if(GetCurrentPeriod() >= PERIOD_REVOLUTIONS) LaunchMine(GetMainCharacter());
			 break;

			 case "BI_ChargeKey0": //Toggle directsail
				if(CheckAttribute(GetMainCharacter(),"nodirectsail"))
				{
					DeleteAttribute(GetMainCharacter(),"nodirectsail");
					Logit(TranslateString("","Directsail mod active"));
				}
				else
				{
					characters[GetMainCharacterIndex()].nodirectsail = 1;
					Logit(TranslateString("","Directsail mod deactivated"));
				}
			 break;

			 case "BI_ChargeKey8": //"Seaview position":
				 DisplaySeaviewCoords();
			 break;
		}
	}
}


void DisplaySeaviewCoords()
{
	if(bSeaActive && !bAbordageStarted)
	{
		string xtext, ztext;
		int pX = MakeInt(characters[GetMainCharacterIndex()].ship.pos.x);
		int pZ = MakeInt(characters[GetMainCharacterIndex()].ship.pos.Z);
		if(pX<0){xtext = "(east)";}else{xtext = "(west)";}
		if(pZ<0){ztext = "(north)";}else{ztext = "(south)";}
		LogIt(TranslateString("","Our position from") + " "+characters[GetMainCharacterIndex()].location+": "+pZ+" "+ztext+", "+pX+" "+xtext);
	}
}

void DSTrace(string logtext)
{
return;		// LDH 26Mar09
	if (DS_DEBUGINFO)
	{
		LogIt(logtext);
	}
	Trace("DS: " + logtext);
	return;
}

// LDH 14Jan09
string Directions[16] = {"Dir_N","Dir_NNE","Dir_NE","Dir_ENE","Dir_E","Dir_ESE","Dir_SE","Dir_SSE","Dir_S","Dir_SSW","Dir_SW","Dir_WSW","Dir_W","Dir_WNW","Dir_NW","Dir_NNW",};
string GetCompassDirFromHeading16(float ay)
{

	float dir = Radian2Degree(ay) + 180.0;

	while (dir < 0.0) dir += 360.0;
	while (dir > 360) dir -= 360.0;

	int index = makeint((dir / 22.5) + 0.5);
	if (index >= 16) index = 0;

	return Directions[index];
}

string GetCompassDirFromPoints16(float fromX, float fromZ, float toX, float toZ)
{
	float angle;
	if (toZ == fromZ) toZ += 0.0001;	// unlikely possibility of divide by zero
	angle = atan((fromX-toX)/(fromZ-toZ));
	if (toZ < fromZ) angle = angle - PI;

	return GetCompassDirFromHeading16(angle);
}

string GetBearingFromShip16(float ay)
{
	if (ay == -99.0) return "";		// LDH keep directing from displaying - 04Mar09

	float dir = Radian2Degree(ay);

	while (dir < 0.0) dir += 360.0;
	while (dir > 360) dir -= 360.0;

	int index = makeint((dir / 22.5) + 0.5);
	if (index >= 16) index = 0;

	switch (index)
	{
	case  0: return "dead ahead"; break;
	case  1: return "fine on the starboard bow"; break;
	case  2: return "on the starboard bow";	break;
	case  3: return "broad on the starboard bow"; break;
	case  4: return "on the starboard beam"; break;
	case  5: return "broad on the starboard quarter"; break;
	case  6: return "on the starboard quarter"; break;
	case  7: return "fine on the starboard quarter"; break;
	case  8: return "astern"; break;
	case  9: return "fine on the port quarter"; break;
	case 10: return "on the port quarter"; break;
	case 11: return "broad on the port quarter"; break;
	case 12: return "on the port beam"; break;
	case 13: return "broad on the port bow"; break;
	case 14: return "on the port bow"; break;
	case 15: return "fine on the port bow"; break;
	}
}
