// KBSPG MOD - Realistic Spyglasses
#define ISG_CHARGE_BALLS		0
#define ISG_CHARGE_GRAPES		1
#define ISG_CHARGE_KNIPPELS		2
#define ISG_CHARGE_BOMBS		3

object objISpyGlass;

void InterfaceSpyGlassInit()
{
	FillISpyGlassParameters();
	CreateEntity(&objISpyGlass,"ispyglass");
	DeleteAttribute(&objISpyGlass,"parameters");
	TelescopeInitParameters();

	LayerAddObject(SEA_EXECUTE,&objISpyGlass,-1);
	LayerAddObject(SEA_REALIZE,&objISpyGlass,-1);
	SetEventHandler("SetTelescopeInfo","SetSpyGlassData",0);
	SetEventHandler("ReleaseTelescopeInfo","ResetSpyGlassData",0);
	SetEventHandler("BI_VISIBLE","CheckInterfaceVisible",0);
}

void InterfaceSpyGlassRelease()
{
	DelEventHandler("BI_VISIBLE","CheckInterfaceVisible");
	DelEventHandler("SetTelescopeInfo","SetSpyGlassData");
	DelEventHandler("ReleaseTelescopeInfo","ResetSpyGlassData");
	DeleteClass(&objISpyGlass);
}

void CheckInterfaceVisible()
{
	int vtype = GetEventData();
	if(vtype!=0) ResetSpyGlassData();
}

void SetSpyGlassData()
{
	int chrIdx = GetEventData();

	int	shipHull = -1;
	int shipSail = -1;
	int shipCrew = -1;
	int shipCannons = -1;
	int shipCharge = -1;
	int shipNation = -1;
	float shipSpeed = -1.0;
	string shipName = "";
	string shipType = "";
	int shipDistance = 0; // meh
	int shipMorale = 45; // NK
	int shipClass = -1;

	// KBSPG variables
	int spyglassacc = 0; //KBSPG
	int shipCaliber = -1; //KBSPG
	string stemp = "" //KBSPG
	int vtemp = 0; //KBSPG
	float ftemp = -1.0; //KBSPG
	int realshipDistance = -1; //KBSPG
	int realshipclass= -1; // KBSPG
	// ---- KBSPG - Parameters
	int accspg1 = 4;	
	int accspg2 = 3;	
	int accspg3 = 2;	
	int accspg4 = 1;

	int rangehull = 750;
	int rangeclass = 750;
	int rangecannons = 750;
	int rangename = 750;
	int rangeload = 750;
	int rangesails = 1500;
	int rangenation = 1500;
	int rangespeed = 1500;
	int rangecrew = 350;
	int rangemorale = 350;
	int rangecaliber = 350;
	int rangetype = 350;

	int varhull = 5;
	int varcannons = 20;
	int varsails = 1;
	int varspeed = 100;
	int varcrew = 10;
	int varrange = 20;

	int incrange = 50;

	int tmpVal;

	// End KBSPG variables

	object tmpobj;
	aref arScopeItm;

	ref chref = GetCharacter(chrIdx);
	ref mchref = GetMainCharacter();
	ref commander = Group_GetGroupCommander(GetGroupIDFromCharacter(chref)); // KK
	ref rISpyglass; // KK
	float distance; // KK

	makeref(rISpyglass, objISpyGlass); // KK

	rISpyglass.chr = chridx; // KK
	if (chrIdx < 0) return;

	if (Items_FindItem(GetCharacterEquipByGroup(mchref, SPYGLASS_ITEM_TYPE), &arScopeItm) < 0) makearef(arScopeItm,tmpobj);


	//KBSPGMOD -  Evaluo KBSPG
	if (iRealismMode == 0) //KBSPG - Stock code
	{
		if( CheckAttribute(arScopeItm,"scope.show.nation") && sti(arScopeItm.scope.show.nation)!=0 )
		{	shipNation = TranslateNationCode(sti(chref.nation));	}

		// смотрим на форт
		if(GetCharacterShipType(chref)==SHIP_FORT) // PS
		{
			// KK -->
			if( CheckAttribute(arScopeItm,"scope.show.ship_name") && sti(arScopeItm.scope.show.ship_name)!=0 ) {
				shipName = "Fort";
				if (CheckAttribute(chref, "town")) {
					shipName = TranslateString(FindTownName(chref.town), shipName);
				} else {
					shipName = TranslateString("", shipName);
				}
				if (CheckAttribute(chref, "Fort.Mode") == true && chref.Fort.Mode != FORT_NORMAL) shipName += " (" + XI_ConvertString("DESTROYED") + ")";
			}
			// <-- KK
			if( CheckAttribute(arScopeItm,"scope.show.cannons") && sti(arScopeItm.scope.show.cannons)!=0 )
			{	shipCannons = Fort_GetCannonsQuantity(chref) - Fort_GetDamagedCannonsQuantity(chref);	} // KK
			if( CheckAttribute(arScopeItm,"scope.show.crew") && sti(arScopeItm.scope.show.crew)!=0 )
			{	shipCrew = GetCrewQuantity(chref);	}
			if( CheckAttribute(arScopeItm,"scope.show.hull") && sti(arScopeItm.scope.show.hull)!=0 ) {
				if( CheckAttribute(chref,"ship.hp") && CheckAttribute(chref,"fort.hp") && stf(chref.Fort.hp)>0.0 ) {
					shipHull = makeint( stf(chref.ship.hp)/stf(chref.Fort.hp) * 100.0 );
				} else {
					shipHull = 100;
				}
			}
			// KK -->
			if( CheckAttribute(arScopeItm,"scope.show.charge") && sti(arScopeItm.scope.show.charge)!=0 )
			{
				shipCharge = sti(chref.Ship.Cannons.Charge.Type);
			}

			// NK -->
			if( CheckAttribute(arScopeItm,"scope.show.morale") && sti(arScopeItm.scope.show.morale)!=0 )
			{
				if(CheckAttribute(chref,"Ship.Crew.Morale"))
				{
					shipMorale = sti(chref.Ship.Crew.Morale);
				}
				if (CheckAttribute(chref, "Fort.Mode") == false || chref.Fort.Mode == FORT_NORMAL) shipName = shipName + ", " + XI_ConvertString("Crew's Morale") + ": " + XI_ConvertString(GetMoraleName(shipMorale));
			}
			// NK <--
			// <-- KK
			// meh -->
			if( CheckAttribute(arScopeItm,"scope.show.speed") && sti(arScopeItm.scope.show.speed)!=0 )
			{
				shipDistance = ( Ship_GetDistance2D(GetMainCharacter(), chref) ) / 10;
				shipDistance *= 10;
			}
			// meh <--
		}
		// смотрим на корабль
		else
		{
			if( CheckAttribute(arScopeItm,"scope.show.cannons") && sti(arScopeItm.scope.show.cannons)!=0 )
			{
				shipCannons = GetCannonQuantity(chref);
			}
			if( CheckAttribute(arScopeItm,"scope.show.ship_name") && sti(arScopeItm.scope.show.ship_name)!=0 )
			{
				shipName = GetMyShipName(chref);
			}
			if( CheckAttribute(arScopeItm,"scope.show.ship_type") && sti(arScopeItm.scope.show.ship_type)!=0 )
			{
				shipType = XI_ConvertString(GetShipTypeName(chref));
				shipClass = GetCharacterShipClass(chref);
			}

			if( CheckAttribute(arScopeItm,"scope.show.hull") && sti(arScopeItm.scope.show.hull)!=0 )
			{
				shipHull = makeint(GetHullPercent(chref));
			}
			if( CheckAttribute(arScopeItm,"scope.show.sail") && sti(arScopeItm.scope.show.sail)!=0 )
			{
				shipSail = makeint(GetSailPercent(chref));
			}
			if( CheckAttribute(arScopeItm,"scope.show.crew") && sti(arScopeItm.scope.show.crew)!=0 )
			{
				shipCrew = GetCrewQuantity(chref);
			}
			if( CheckAttribute(arScopeItm,"scope.show.speed") && sti(arScopeItm.scope.show.speed)!=0 )
			{
				shipSpeed = stf(chref.Ship.speed.z);
				// meh -->
				shipDistance = ( Ship_GetDistance2D(GetMainCharacter(), chref) ) / 10;
				shipDistance *= 10;
				// meh <--
			}
			if( CheckAttribute(arScopeItm,"scope.show.charge") && sti(arScopeItm.scope.show.charge)!=0 )
			{
				// 0 shows balls, 1 shows grape, 2 shows knippel, 3 shows bombs.  With rations defined first, need to adjust this
				shipCharge = sti(chref.Ship.Cannons.Charge.Type) - 1;	// LDH 18Feb09
			}
			// KK -->
			if(CheckAttribute(chref,"surrendered"))
			{
				shipName = shipName + ", " + XI_ConvertString("SURRENDERED") + "!"; } // NK surrender 05-04-21
		}
		else
		{
			// NK -->
			if ( CheckAttribute(arScopeItm,"scope.show.morale") && sti(arScopeItm.scope.show.morale)!=0 )
			{
				if(CheckAttribute(chref,"Ship.Crew.Morale"))
				{
					shipMorale = sti(chref.Ship.Crew.Morale);
				}
				if (CheckAttribute(commander, "id") == true && GetCharacterIndex(commander.id) == chrIdx) shipName = shipName + " (" + XI_ConvertString("Flagship") + ")"; // KK
				shipName = shipName + ", " + XI_ConvertString("Crew's Morale") + ": " + XI_ConvertString(GetMoraleName(shipMorale));
			}
			// NK <--
		}
		// <-- KK
	}
	else 	//KBSPG - Otherwise, KBSPG code
	{
		//KBSPG - Load parameters
		accspg1 = KBSPGACCSPG1;	
		accspg2 = KBSPGACCSPG2;	
		accspg3 = KBSPGACCSPG3;	
		accspg4 = KBSPGACCSPG4;

		rangehull = KBSPGRANGEHULL;
		rangeclass = KBSPGRANGECLASS;
		rangecannons = KBSPGRANGECANNONS;
		rangename = KBSPGRANGENAME;
		rangeload = KBSPGRANGELOAD;
		rangesails = KBSPGRANGESAILS;
		rangenation = KBSPGRANGENATION;
		rangespeed = KBSPGRANGESPEED;
		rangecrew = KBSPGRANGECREW;
		rangemorale = KBSPGRANGEMORALE;
		rangecaliber = KBSPGRANGECALIBER;
		rangetype = KBSPGRANGETYPE;

		varhull = KBSPGVARHULL;
		varcannons = KBSPGVARCANNONS;
		varsails = KBSPGVARSAILS;
		varspeed = KBSPGVARSPEED;
		varcrew = KBSPGVARCREW;
		varrange = KBSPGVARRANGE;
		//KBSPG - Depending the item, will have a different accuracy - just for not to tweak with items code
		switch (arScopeItm.id) {
		case "spyglass1":
			spyglassacc = accspg1;
			break;
		case "spyglass2":
			spyglassacc = accspg2;
			break;
		case "spyglass3":
			spyglassacc = accspg3;
			break;
		case "spyglass4":
			spyglassacc = accspg4;
			break;
		}

		//KBSPG - First I get the real data needed- distance and class
		realshipDistance = ( Ship_GetDistance2D(GetMainCharacter(), chref) ) / 10 ;
		realshipDistance *= 10;
		realshipclass = sti(GetCharacterShipClass(chref));

		//KBSPG - Now I start to check item characteristics and realdistance (modified by acc * 50) to determine if u can get the info

		// NATION
		if( CheckAttribute(arScopeItm,"scope.show.nation") && sti(arScopeItm.scope.show.nation)!=0 )
		{
			if ( rangenation >= realshipdistance + (spyglassacc - 1) * incrange )
			{
				shipNation = TranslateNationCode(sti(chref.nation));	
			}
		}
		else // KBSPG report neutral flag
		{	
			shipnation = TranslateNationCode(NEUTRAL_NATION);	// NEUTRAL_NATION was hardcoded 7 - 05Feb09 
		}

		//KBSPG - Now depends if it's a Fort or a Ship
		
		if(GetCharacterShipType(chref)==SHIP_FORT) // PS
		{
			// KK -->
			if( CheckAttribute(arScopeItm,"scope.show.ship_name") && sti(arScopeItm.scope.show.ship_name)!=0 ) {
				shipName = "Fort";
				if (CheckAttribute(chref, "town")) {
					shipName = TranslateString(FindTownName(chref.town), shipName);
				} else {
					shipName = TranslateString("", shipName);
				}
				if (CheckAttribute(chref, "Fort.Mode") == true && chref.Fort.Mode != FORT_NORMAL) shipName += " (" + XI_ConvertString("DESTROYED") + ")";
			}
			// <-- KK

			if( CheckAttribute(arScopeItm,"scope.show.cannons") && sti(arScopeItm.scope.show.cannons)!=0 )
			{
				if ( rangecannons >= realshipdistance + (spyglassacc - 1) * incrange )	
				{
					vtemp = Fort_GetCannonsQuantity(chref) - Fort_GetDamagedCannonsQuantity(chref); // KK
					shipCannons = vtemp + makeint(vtemp/varcannons) * (rand( 2* spyglassacc) - spyglassacc);
					vtemp = 0;
				}
			}
			
			if( CheckAttribute(arScopeItm,"scope.show.crew") && sti(arScopeItm.scope.show.crew)!=0 )
			{
				if ( rangecrew >= realshipdistance + (spyglassacc - 1) * incrange )	
				{	
					vtemp = GetCrewQuantity(chref);
					shipCrew = vtemp + makeint(vtemp/varcrew) * (rand( 2* spyglassacc) - spyglassacc);
					vtemp = 0;
				}
			}

			if( CheckAttribute(arScopeItm,"scope.show.hull") && sti(arScopeItm.scope.show.hull)!=0 ) {
				if ( rangehull >= realshipdistance + (spyglassacc - 1) * incrange )
				{
					if( CheckAttribute(chref,"ship.hp") && CheckAttribute(chref,"fort.hp") && stf(chref.Fort.hp)>0.0 ) {
						shipHull = makeint( stf(chref.ship.hp)/stf(chref.Fort.hp) * 100.0 );
					} else {
						shipHull = 100;
					}
				}
			}
			// KK -->
			if( CheckAttribute(arScopeItm,"scope.show.charge") && sti(arScopeItm.scope.show.charge)!=0 )
			{
				shipCharge = sti(chref.Ship.Cannons.Charge.Type);
			}
			// NK -->
			if( CheckAttribute(arScopeItm,"scope.show.morale") && sti(arScopeItm.scope.show.morale)!=0 )
			{
				if(CheckAttribute(chref,"Ship.Crew.Morale"))
				{
					shipMorale = sti(chref.Ship.Crew.Morale);
				}
				if (CheckAttribute(chref, "Fort.Mode") == false || chref.Fort.Mode == FORT_NORMAL) shipName = shipName + ", " + XI_ConvertString("Crew's Morale") + ": " + XI_ConvertString(GetMoraleName(shipMorale));
			}
			// NK <--
			// <-- KK
			// meh -->
			if( CheckAttribute(arScopeItm,"scope.show.speed") && sti(arScopeItm.scope.show.speed)!=0 )
			{
				vtemp = realshipDistance;
				shipDistance = vtemp + makeint (vtemp/varrange) * (rand( 2*spyglassacc)- spyglassacc);
			}
			// meh <--
		}
		// смотрим на корабль
		else

		// KBSPG - It's a ship

		{
			

			if( CheckAttribute(arScopeItm,"scope.show.ship_type") && sti(arScopeItm.scope.show.ship_type)!=0 )
			{
				if ( rangeclass >= realshipdistance + (spyglassacc - 1) * incrange )
				{	
					shipType = XI_ConvertString(GetShipTypeName(chref));
					shipClass = GetCharacterShipClass(chref);
				}
				else
				{
					shipClass = -1;
				}
			}


			if ( CheckAttribute(arScopeItm,"scope.show.ship_name") && sti(arScopeItm.scope.show.ship_name)!=0 )
			{
				if ( rangename >= realshipdistance + (spyglassacc - 1) * incrange )
				{
					shipName = GetMyShipName(chref);
				}
			}
			

			if( CheckAttribute(arScopeItm,"scope.show.speed") && sti(arScopeItm.scope.show.speed)!=0 )
			{
				if ( rangespeed >= realshipdistance + (spyglassacc - 1) * incrange )
				{
					ftemp = stf(chref.Ship.speed.z);
					shipSpeed = ftemp + (ftemp/varspeed * ( frand (2*spyglassacc*3) - 3*spyglassacc ) );
					ftemp = 0.0;
				}
				// meh -->
				vtemp = realshipDistance;
				shipDistance = vtemp + makeint (vtemp/varrange) * (rand( 2*spyglassacc)- spyglassacc);
			}


			if( CheckAttribute(arScopeItm,"scope.show.cannons") && sti(arScopeItm.scope.show.cannons)!=0 ) 
			{
				if ( rangecannons >= realshipdistance + (spyglassacc - 1) * incrange )
				{	
					vtemp = GetCannonQuantity(chref);
					shipCannons = vtemp + makeint(vtemp/varcannons) * (rand( 2* spyglassacc) - spyglassacc);
					vtemp = 0;
				}
				
			}

			if( CheckAttribute(arScopeItm,"scope.show.hull") && sti(arScopeItm.scope.show.hull)!=0 )
			{
				if ( rangehull >= realshipdistance + (spyglassacc - 1) * incrange )
				{
					vtemp = rand(2*spyglassacc*varhull) - spyglassacc*varhull;
					shipHull = makeint(GetHullPercent(chref)) + vtemp;
					vtemp = 0;
				}
			}

			if( CheckAttribute(arScopeItm,"scope.show.sail") && sti(arScopeItm.scope.show.sail)!=0 )
			{
				if ( rangesails >= realshipdistance + (spyglassacc - 1) * incrange )
				{
					vtemp = rand(2*spyglassacc*varsails) - spyglassacc*varsails;
					shipSail = makeint(GetSailPercent(chref)) +vtemp;
					vtemp = 0;
				}
			}
			
			if( CheckAttribute(arScopeItm,"scope.show.crew") && sti(arScopeItm.scope.show.crew)!=0 )
			{
				if ( rangecrew >= realshipdistance + (spyglassacc - 1) * incrange )
				{
					switch ( realshipclass ) 
					{
					case 8:
						vtemp = GetCrewQuantity(chref);
						shipCrew = vtemp + makeint(vtemp/varcrew) * (rand( 2* spyglassacc) - spyglassacc);
						vtemp = 0;
						break;
					case 7:
						vtemp = GetCrewQuantity(chref);
						shipCrew = vtemp + makeint(vtemp/varcrew) * (rand( 2* spyglassacc) - spyglassacc);
						vtemp = 0;
						break;
					case 6:
						vtemp = GetCrewQuantity(chref);
						shipCrew = vtemp + makeint(vtemp/varcrew) * (rand( 2* spyglassacc) - spyglassacc);
						vtemp = 0;
						break;
					case 5:
						vtemp = GetCrewQuantity(chref)/1.5;
						shipCrew = vtemp + makeint(vtemp/varcrew) * (rand( 2* spyglassacc) - spyglassacc);
						vtemp = 0;
						break;
					case 4:
						vtemp = GetCrewQuantity(chref)/1.5;
						shipCrew = vtemp + makeint(vtemp/varcrew) * (rand( 2* spyglassacc) - spyglassacc);
						vtemp = 0;
						break;
					case 3:
						vtemp = GetCrewQuantity(chref)/2.5;
						shipCrew = vtemp + makeint(vtemp/varcrew) * (rand( 2* spyglassacc) - spyglassacc);
						vtemp = 0;
						break;
					case 2:
						vtemp = GetCrewQuantity(chref)/2;
						shipCrew = vtemp + makeint(vtemp/varcrew) * (rand( 2* spyglassacc) - spyglassacc);
						vtemp = 0;
						break;
					case 1:
						vtemp = GetCrewQuantity(chref)/3;
						shipCrew = vtemp + makeint(vtemp/varcrew) * (rand( 2* spyglassacc) - spyglassacc);
						vtemp = 0;
						break;
					}
				}
			}

			if( CheckAttribute(arScopeItm,"scope.show.charge") && sti(arScopeItm.scope.show.charge)!=0 )
			{
				if ( rangeload >= realshipdistance + (spyglassacc - 1) * incrange )
				{
					// 0 shows balls, 1 shows grape, 2 shows knippel, 3 shows bombs.  With rations defined first, need to adjust this
					shipCharge = sti(chref.Ship.Cannons.Charge.Type) - 1;	// LDH 18Feb09
				}
			}

			// KK -->
			if(CheckAttribute(chref,"surrendered"))
			{
				shipName = shipName + ", " + XI_ConvertString("SURRENDERED") + "!"; } // NK surrender 05-04-21
		}
		else
		{
			if ( rangemorale >= realshipdistance + (spyglassacc - 1) * incrange )
			{
				// NK -->
				if ( CheckAttribute(arScopeItm,"scope.show.morale") && sti(arScopeItm.scope.show.morale)!=0 )
				{
					if(CheckAttribute(chref,"Ship.Crew.Morale"))
					{
						shipMorale = sti(chref.Ship.Crew.Morale);
					}
					if(!CheckAttribute(chref,"surrendered")) {
						if (CheckAttribute(commander, "id") == true && GetCharacterIndex(commander.id) == chrIdx) shipName = shipName + " (" + XI_ConvertString("Flagship") + ")"; // KK
						shipName = shipName + ", " + XI_ConvertString("Crew's Morale") + ": " + XI_ConvertString(GetMoraleName(shipMorale));
					} // NK surrender 05-04-21
				}
				// NK <--
			}
		}
		// <-- KK
	}

	// PB: Prevent impossible values -->
	if(shipHull     < 0  ) shipHull     =   0;
	if(shipHull     > 100) shipHull     = 100;
	// KK -->
	if(GetCharacterShipType(chref) == SHIP_FORT)
	{
		shipSail = -1;
		shipSpeed = -1;
	}
	else
	{
		if(shipSail     < 0  ) shipSail     =   0;
		if(shipSail     > 100) shipSail     = 100;
		if(shipSpeed    < 0  ) shipSpeed    =   0;
		tmpVal = GetMaxCrewQuantity(chref);
		if(shipCrew     > tmpVal) shipCrew = tmpVal;
		tmpVal = GetCannonMaxQuantity(chref);
		if(shipCannons  > tmpVal) shipCannons = tmpVal;
	}
	if(shipCrew     < -1  ) shipCrew     =   0;
	if(shipCannons  < -1  ) shipCannons  =   0;
	// <-- KK
	if(shipDistance < 0  ) shipDistance =   0;
	// PB: Prevent impossible values <--

	int nSailState = 1;
	float fSailSt = Ship_GetSailState(chref);
	if( fSailSt<0.3 ) {nSailState = 0;}
	else {
		if( fSailSt<0.6 ) {nSailState = 1;}
		else {nSailState = 2;}
	}

	int shipMaxCannons = shipCannons;
	int nFace = sti(chref.faceID);
	string sFaceTexture = "interfaces/portraits/64/face_" + nFace + ".tga"
	int nFencingSkill = GetCharacterSkill(chref, SKILL_DEFENCE);
	int nCannonSkill = GetCharacterSkill(chref, SKILL_CANNONS);
	int nAccuracySkill = GetCharacterSkill(chref, SKILL_ACCURACY);
	int nNavigationSkill = GetCharacterSkill(chref, SKILL_SAILING);
	int nBoardingSkill = GetCharacterSkill(chref, SKILL_GRAPPLING);
	string sCaptainName = chref.name + " " + chref.lastname;

	if(iRealismMode>1 || ONSEA_DATA_DISABLED) {  //Screwface : No infos in realistic mod // KK ship type and nation become quite obvious from some distances
		if (Ship_GetGroupID(chref) != PLAYER_GROUP) shipName = chref.Ship.Name;
		distance = Ship_GetDistance2D(mchref, chref);
		if (distance < GetCharVisibilityRange(mchref, 3)) // Ship type, nation AND name shown inside CLOSE range
		{
			SendMessage(&objISpyGlass,"lsslllfflllllllllllssl",MSG_ISG_UPDATE, shipName, shipType, -1, -1, -1, -1.0, -1, -1, -1, -1, shipNation, nSailState, -1, -1, -1, -1, -1, -1, "", "", shipClass);
			SendMessage(&objISpyGlass,"ll",MSG_ISG_VISIBLE, true);
		}
		else
		{
			if (distance < GetCharVisibilityRange(mchref, 2)) // Ship type and nation shown inside MEDIUM range
			{
				SendMessage(&objISpyGlass,"lsslllfflllllllllllssl",MSG_ISG_UPDATE, "", shipType, -1, -1, -1, -1.0, -1, -1, -1, -1, shipNation, nSailState, -1, -1, -1, -1, -1, -1, "", "", shipClass);
				SendMessage(&objISpyGlass,"ll",MSG_ISG_VISIBLE, true);
			}
			else
			{
				if (distance < GetCharVisibilityRange(mchref, 1)) // Ship type is visible inside LONG range
				{
					SendMessage(&objISpyGlass,"lsslllfflllllllllllssl",MSG_ISG_UPDATE, "", shipType, -1, -1, -1, -1.0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, "", "", shipClass);
					SendMessage(&objISpyGlass,"ll",MSG_ISG_VISIBLE, true);
				}
			}
		}
	} else {
		SendMessage(&objISpyGlass,"lsslllfflllllllllllssl",MSG_ISG_UPDATE, shipName, shipType, shipHull, shipSail, shipCrew, shipSpeed, shipDistance, shipCannons, shipMaxCannons, shipCharge, shipNation, nSailState, -1, nFencingSkill, nCannonSkill, nAccuracySkill, nNavigationSkill, nBoardingSkill, sCaptainName, sFaceTexture, shipClass);
		SendMessage(&objISpyGlass,"ll",MSG_ISG_VISIBLE,true);
	}
	/*rISpyglass.shipName = shipName;
	rISpyglass.shipType = shipType;
	rISpyglass.shipHull = shipHull;
	rISpyglass.shipSail = shipSail;
	rISpyglass.shipCrew = shipCrew;
	rISpyglass.shipSpeed = shipSpeed;
	rISpyglass.shipCannons = shipCannons;
	rISpyglass.shipCharge = shipCharge;
	rISpyglass.shipNation = shipNation;*/
}

void ResetSpyGlassData()
{
	ref rISpyglass; makeref(rISpyglass, objISpyGlass);

	if (CheckAttribute(rISpyglass, "shipName")) DeleteAttribute(rISpyglass, "shipName");
	if (CheckAttribute(rISpyglass, "shipType")) DeleteAttribute(rISpyglass, "shipType");
	if (CheckAttribute(rISpyglass, "shipHull")) DeleteAttribute(rISpyglass, "shipHull");
	if (CheckAttribute(rISpyglass, "shipSail")) DeleteAttribute(rISpyglass, "shipSail");
	if (CheckAttribute(rISpyglass, "shipCrew")) DeleteAttribute(rISpyglass, "shipCrew");
	if (CheckAttribute(rISpyglass, "shipSpeed")) DeleteAttribute(rISpyglass, "shipSpeed");
	if (CheckAttribute(rISpyglass, "shipCannons")) DeleteAttribute(rISpyglass, "shipCannons");
	if (CheckAttribute(rISpyglass, "shipCharge")) DeleteAttribute(rISpyglass, "shipCharge");
	if (CheckAttribute(rISpyglass, "shipNation")) DeleteAttribute(rISpyglass, "shipNation");

	SendMessage(&objISpyGlass,"ll",MSG_ISG_VISIBLE,false);
}

int TranslateNationCode(int nationCode)
{
	switch(nationCode)
	{
	case PORTUGAL: return 0; break;
	case SPAIN: return 1; break;
	case PIRATE: return 2; break;
	case ENGLAND: return 3; break;
	case HOLLAND: return 4; break;
	case FRANCE: return 5; break;
	case AMERICA: return 6; break;
	case NEUTRAL_NATION: return 8; break;	// added by KAM
	case UNKNOWN_NATION: return 8; break;	// added by KAM
	case PERSONAL_NATION: return 9; break; // KK
	case PRIVATEER_NATION: return 9; break; // added by GR
	}

	return -1;	// added by KAM
}

string calculateNationSpyglassUv(int iNation) {
	return "" + (MakeFloat(iNation) / 12) + ", 0, " + (MakeFloat(iNation + 1) / 12) + ", 0.65625";
}

void FillISpyGlassParameters()
{
	objISpyGlass.lens.texture = "BATTLE_INTERFACE\Spyglass\spyglass3.tga";

  	int nHCenter = sti(showWindow.right)/2;
	objISpyGlass.lens.pos = (nHCenter-sti(showWindow.bottom))+","+(sti(showWindow.top)-1)+","+(nHCenter+sti(showWindow.bottom))+","+showWindow.bottom;//showWindow.left+","+showWindow.top+"," + showWindow.right+","+showWindow.bottom;
	int ntop = sti(showWindow.bottom) - 114;//sti(showWindow.bottom) - RecalculateVIconScaled(114);
	int nbottom = ntop + 128;//ntop + RecalculateVIconScaled(128);

	//==========================================================
	objISpyGlass.shipsign.ship.texture = "battle_interface\\ship_icons2.tga";//
	objISpyGlass.shipsign.ship.pos = 28+","+(ntop+20)+","+92+","+(ntop+84);//RecalculateHIconScaled(28)+","+(ntop+RecalculateVIconScaled(20)) + "," + RecalculateHIconScaled(92)+","+(ntop+RecalculateVIconScaled(84));
	objISpyGlass.shipsign.ship.uv = "0,0,0.0625,0.0625";//"0,0,0.125,0.25";
	objISpyGlass.shipsign.back.texture = "battle_interface\\shipbackicon.tga";
	objISpyGlass.shipsign.back.pos = 8+","+(ntop-2)+","+136+","+(nbottom-2);
//	objISpyGlass.shipsign.back.pos = 10+","+ntop+","+138+","+nbottom;//RecalculateHIconScaled(10)+","+ntop + "," + RecalculateHIconScaled(138)+","+nbottom;
	objISpyGlass.shipsign.hp.texture = "battle_interface\\ShipState.tga";
	objISpyGlass.shipsign.hp.pos = 10+","+(ntop+14)+","+74+","+(ntop+88);//RecalculateHIconScaled(10)+","+(ntop+RecalculateVIconScaled(14)) + "," + RecalculateHIconScaled(74)+","+(ntop+RecalculateVIconScaled(88));
	objISpyGlass.shipsign.hp.uv = "0.0,0.109,0.5,0.6875";
	objISpyGlass.shipsign.sp.texture = "battle_interface\\ShipState.tga";
	objISpyGlass.shipsign.sp.pos = 74+","+(ntop+14)+","+138+","+(ntop+88);//RecalculateHIconScaled(74)+","+(ntop+RecalculateVIconScaled(14)) + "," + RecalculateHIconScaled(138)+","+(ntop+RecalculateVIconScaled(88));
	objISpyGlass.shipsign.sp.uv = "0.5,0.109,1.0,0.6875";
	objISpyGlass.shipsign.class.texture = "battle_interface\\ShipClass.tga";
	objISpyGlass.shipsign.class.pos = 28+","+(ntop+4)+","+92+","+(ntop+20);
//	objISpyGlass.shipsign.class.pos = 30+","+(ntop+6)+","+94+","+(ntop+22);//RecalculateHIconScaled(30)+","+(ntop+RecalculateVIconScaled(6)) + "," + RecalculateHIconScaled(92)+","+(ntop+RecalculateVIconScaled(22));
	//
	objISpyGlass.info.nation.texture = "battle_interface/all_nations" + GetCurrentPeriod() + ".tga"; // PB
	objISpyGlass.info.nation.pos = 116+","+(ntop+8)+","+180+","+(ntop+40);//RecalculateHIconScaled(116)+","+(ntop+RecalculateVIconScaled(8)) + "," + RecalculateHIconScaled(180)+","+(ntop+RecalculateVIconScaled(40));
	objISpyGlass.info.nation.uv = "0,0,0.125,1.0";
	//
	objISpyGlass.info.cannon.texture = "battle_interface\\list_icons.tga";
	objISpyGlass.info.cannon.pos = (nHCenter-RecalculateHIconScaled(252)-48)+","+(ntop+42)+","+(nHCenter-RecalculateHIconScaled(252))+","+(ntop+90);//RecalculateHIconScaled(212)+","+(ntop+RecalculateVIconScaled(42)) + "," + RecalculateHIconScaled(260)+","+(ntop+RecalculateVIconScaled(90));
	objISpyGlass.info.cannon.uv = "0.625,0.375,0.6875,0.5";
	//
	objISpyGlass.info.speed.texture = "battle_interface\\list_icon2.tga";
	objISpyGlass.info.speed.pos = (nHCenter-RecalculateHIconScaled(180)-48)+","+(ntop+42)+","+(nHCenter-RecalculateHIconScaled(180))+","+(ntop+90);//RecalculateHIconScaled(284)+","+(ntop+RecalculateVIconScaled(42)) + "," + RecalculateHIconScaled(332)+","+(ntop+RecalculateVIconScaled(90));
	objISpyGlass.info.speed.uv = "0.25,0.25,0.375,0.375";

	objISpyGlass.info.sailto.texture = "battle_interface\\list_icons.tga";   // boal // Lexanni: расстояние (хз почему так называется)
	objISpyGlass.info.sailto.pos = (nHCenter-RecalculateHIconScaled(36)-48)+","+(ntop+42)+","+(nHCenter-RecalculateHIconScaled(36))+","+(ntop+90);//RecalculateHIconScaled(428)+","+(ntop+RecalculateVIconScaled(42)) + "," + RecalculateHIconScaled(476)+","+(ntop+RecalculateVIconScaled(90));
	objISpyGlass.info.sailto.uv = "0.75,0.25,0.8125,0.375";

	//
	objISpyGlass.info.charge.texture = "battle_interface\\list_icon2.tga";//тип боеприпасов
	objISpyGlass.info.charge.pos = (nHCenter-RecalculateHIconScaled(108)-48)+","+(ntop+42)+","+(nHCenter-RecalculateHIconScaled(108))+","+(ntop+90);//RecalculateHIconScaled(356)+","+(ntop+RecalculateVIconScaled(42)) + "," + RecalculateHIconScaled(404)+","+(ntop+RecalculateVIconScaled(90));
	objISpyGlass.info.charge.uv = "0.125,0.5,0.25,0.625";

	objISpyGlass.captain.back.texture = "battle_interface\\shipbackicon.tga";
	objISpyGlass.captain.back.pos = (sti(showWindow.right)-110)+","+(ntop-2)+","+(sti(showWindow.right)+14)+","+(nbottom-2);
//	objISpyGlass.captain.back.pos = (sti(showWindow.right)-112)+","+ntop+","+(sti(showWindow.right)+16)+","+nbottom;//RecalculateHIconScaled(906)+","+ntop + "," + RecalculateHIconScaled(1034)+","+nbottom;
	objISpyGlass.captain.face.texture = "interfaces/portraits/64/face_0.tga";
	objISpyGlass.captain.face.pos = (sti(showWindow.right)-94)+","+(ntop+18)+","+(sti(showWindow.right)-30)+","+(ntop+82);//RecalculateHIconScaled(924)+","+(ntop+RecalculateVIconScaled(20)) + "," + RecalculateHIconScaled(988)+","+(ntop+RecalculateVIconScaled(84));
	//

	objISpyGlass.captain.fencing.texture = "interfaces/icons.tga";
	objISpyGlass.captain.fencing.pos = (nHCenter+RecalculateHIconScaled(324))+","+(ntop+42)+","+(nHCenter+RecalculateHIconScaled(324)+48)+","+(ntop+90);//RecalculateHIconScaled(830)+","+(ntop+RecalculateVIconScaled(42)) + "," + RecalculateHIconScaled(878)+","+(ntop+RecalculateVIconScaled(90));
	objISpyGlass.captain.fencing.uv = "0.437, 0.75, 0.5, 0.875";
	objISpyGlass.captain.cannon.texture = "interfaces/icons.tga";
	objISpyGlass.captain.cannon.pos = (nHCenter+RecalculateHIconScaled(252))+","+(ntop+42)+","+(nHCenter+RecalculateHIconScaled(252)+48)+","+(ntop+90);//RecalculateHIconScaled(758)+","+(ntop+RecalculateVIconScaled(42)) + "," + RecalculateHIconScaled(806)+","+(ntop+RecalculateVIconScaled(90));
	objISpyGlass.captain.cannon.uv = "0.25, 0.75, 0.3125, 0.875";
	objISpyGlass.captain.accuracy.texture = "interfaces/icons.tga";
	objISpyGlass.captain.accuracy.pos = (nHCenter+RecalculateHIconScaled(180))+","+(ntop+42)+","+(nHCenter+RecalculateHIconScaled(180)+48)+","+(ntop+90);//RecalculateHIconScaled(686)+","+(ntop+RecalculateVIconScaled(42)) + "," + RecalculateHIconScaled(734)+","+(ntop+RecalculateVIconScaled(90));
	objISpyGlass.captain.accuracy.uv = "0.1875, 0.75, 0.25, 0.875";
	objISpyGlass.captain.navigation.texture = "interfaces/icons.tga";
	objISpyGlass.captain.navigation.pos = (nHCenter+RecalculateHIconScaled(108))+","+(ntop+42)+","+(nHCenter+RecalculateHIconScaled(108)+48)+","+(ntop+90);//RecalculateHIconScaled(614)+","+(ntop+RecalculateVIconScaled(42)) + "," + RecalculateHIconScaled(662)+","+(ntop+RecalculateVIconScaled(90));
	objISpyGlass.captain.navigation.uv = "0.125, 0.75, 0.1875, 0.875";
	objISpyGlass.captain.boarding.texture = "interfaces/icons.tga";
	objISpyGlass.captain.boarding.pos = (nHCenter+RecalculateHIconScaled(36))+","+(ntop+42)+","+(nHCenter+RecalculateHIconScaled(36)+48)+","+(ntop+90);//RecalculateHIconScaled(542)+","+(ntop+RecalculateVIconScaled(42)) + "," + RecalculateHIconScaled(590)+","+(ntop+RecalculateVIconScaled(90));
	objISpyGlass.captain.boarding.uv = "0.3125, 0.75, 0.375, 0.875";


	//==========================================================
	float fBaseScale = stf(showWindow.width) / 1310.0;
	objISpyGlass.text.shiptype.font = "interface_normal";
	objISpyGlass.text.shiptype.pos = 116+","+(ntop+46);//RecalculateHIconScaled(116)+","+(ntop+RecalculateVIconScaled(46));
	objISpyGlass.text.shiptype.color = argb(255,255,255,168);
	objISpyGlass.text.shiptype.scale = fBaseScale * 1.2;
	//
	objISpyGlass.text.shipname.font = "interface_normal";
	objISpyGlass.text.shipname.pos = 116+","+(ntop+72);//RecalculateHIconScaled(116)+","+(ntop+RecalculateVIconScaled(72));
	objISpyGlass.text.shipname.color = argb(255,255,255,168);
	objISpyGlass.text.shipname.scale = fBaseScale * 1.2;
	//
	objISpyGlass.text.cannons.font = "interface_normal";
	objISpyGlass.text.cannons.pos = (nHCenter-RecalculateHIconScaled(252)-24)+","+(ntop+24);//RecalculateHIconScaled(236)+","+(ntop+RecalculateVIconScaled(26));
	objISpyGlass.text.cannons.align = "center";
	objISpyGlass.text.cannons.color = argb(255,255,255,168);
	objISpyGlass.text.cannons.scale = fBaseScale * 1.2;
	//
	objISpyGlass.text.speed.font = "interface_normal";
	objISpyGlass.text.speed.pos = (nHCenter-RecalculateHIconScaled(180)-24)+","+(ntop+24);//RecalculateHIconScaled(308)+","+(ntop+RecalculateVIconScaled(26));
	objISpyGlass.text.speed.align = "center";
	objISpyGlass.text.speed.color = argb(255,255,255,168);
	objISpyGlass.text.speed.scale = fBaseScale * 1.2;
	// boal
	objISpyGlass.text.sailto.font = "interface_normal";
	objISpyGlass.text.sailto.pos = (nHCenter-RecalculateHIconScaled(36)-24)+","+(ntop+24);//RecalculateHIconScaled(452)+","+(ntop+RecalculateVIconScaled(26));
	objISpyGlass.text.sailto.align = "center";
	objISpyGlass.text.sailto.color = argb(255,255,255,168);
	objISpyGlass.text.sailto.scale = fBaseScale * 1.2;
	//
	objISpyGlass.text.crew.font = "interface_normal";
	objISpyGlass.text.crew.pos = 60+","+(ntop+80);//RecalculateHIconScaled(60)+","+(ntop+RecalculateVIconScaled(80));
	objISpyGlass.text.crew.align = "center";
	objISpyGlass.text.crew.color = argb(255,255,255,168);
	objISpyGlass.text.crew.scale = fBaseScale * 1.0;

	// captain text data
	objISpyGlass.captext.capname.font = "interface_normal";
	objISpyGlass.captext.capname.pos = (sti(showWindow.right)-14)+","+(ntop-20);//RecalculateHIconScaled(1000)+","+(ntop-RecalculateVIconScaled(16));
	objISpyGlass.captext.capname.align = "right";
	objISpyGlass.captext.capname.color = argb(255,255,255,168);
 	objISpyGlass.captext.capname.scale = fBaseScale * 1.2;
	//
	objISpyGlass.captext.fencing.font = "interface_normal";
	objISpyGlass.captext.fencing.pos = (nHCenter+RecalculateHIconScaled(324)+24)+","+(ntop+24);//RecalculateHIconScaled(856)+","+(ntop+RecalculateVIconScaled(26));
	objISpyGlass.captext.fencing.align = "center";
	objISpyGlass.captext.fencing.color = argb(255,255,255,168);
  	objISpyGlass.captext.fencing.scale = fBaseScale * 1.2;
	//
	objISpyGlass.captext.cannon.font = "interface_normal";
	objISpyGlass.captext.cannon.pos = (nHCenter+RecalculateHIconScaled(256)+24)+","+(ntop+24);//RecalculateHIconScaled(784)+","+(ntop+RecalculateVIconScaled(26));
	objISpyGlass.captext.cannon.align = "center";
	objISpyGlass.captext.cannon.color = argb(255,255,255,168);
  	objISpyGlass.captext.cannon.scale = fBaseScale * 1.2;
	//
	objISpyGlass.captext.accuracy.font = "interface_normal";
	objISpyGlass.captext.accuracy.pos = (nHCenter+RecalculateHIconScaled(180)+24)+","+(ntop+24);//RecalculateHIconScaled(712)+","+(ntop+RecalculateVIconScaled(26));
	objISpyGlass.captext.accuracy.align = "center";
	objISpyGlass.captext.accuracy.color = argb(255,255,255,168);
  	objISpyGlass.captext.accuracy.scale = fBaseScale * 1.2;
	//
	objISpyGlass.captext.navigation.font = "interface_normal";
	objISpyGlass.captext.navigation.pos = (nHCenter+RecalculateHIconScaled(108)+24)+","+(ntop+24);//RecalculateHIconScaled(640)+","+(ntop+RecalculateVIconScaled(26));
	objISpyGlass.captext.navigation.align = "center";
	objISpyGlass.captext.navigation.color = argb(255,255,255,168);
 	objISpyGlass.captext.navigation.scale = fBaseScale * 1.2;
	//
	objISpyGlass.captext.boarding.font = "interface_normal";
	objISpyGlass.captext.boarding.pos = (nHCenter+RecalculateHIconScaled(36)+24)+","+(ntop+24);//RecalculateHIconScaled(566)+","+(ntop+RecalculateVIconScaled(26));
	objISpyGlass.captext.boarding.align = "center";
	objISpyGlass.captext.boarding.color = argb(255,255,255,168);
  	objISpyGlass.captext.boarding.scale = fBaseScale * 1.2;
	// <-- Lexanni
	//===============================================
	objISpyGlass.nationuvarray.uv0 = calculateNationSpyglassUv(ENGLAND);
	objISpyGlass.nationuvarray.uv1 = calculateNationSpyglassUv(FRANCE);
	objISpyGlass.nationuvarray.uv2 = calculateNationSpyglassUv(SPAIN);
	objISpyGlass.nationuvarray.uv3 = calculateNationSpyglassUv(PIRATE);
	objISpyGlass.nationuvarray.uv4 = calculateNationSpyglassUv(HOLLAND);
	objISpyGlass.nationuvarray.uv5 = calculateNationSpyglassUv(PORTUGAL);
	objISpyGlass.nationuvarray.uv6 = calculateNationSpyglassUv(GUEST1_NATION);
	objISpyGlass.nationuvarray.uv7 = calculateNationSpyglassUv(GUEST2_NATION);
	objISpyGlass.nationuvarray.uv8 = calculateNationSpyglassUv(PRIVATEER_NATION);
	objISpyGlass.nationuvarray.uv9 = calculateNationSpyglassUv(NEUTRAL_NATION);
	//
	objISpyGlass.chargeuvarray.uv0 = "0.0,0.5,0.125,0.625"; // balls
	objISpyGlass.chargeuvarray.uv1 = "0.125,0.5,0.25,0.625"; // bomb
	objISpyGlass.chargeuvarray.uv2 = "0.25,0.5,0.375,0.625"; // knippels
	objISpyGlass.chargeuvarray.uv3 = "0.375,0.5,0.5,0.625"; // grapes
	//
	objISpyGlass.sailuvarray.uv0 = "0.5,0.25,0.625,0.375"; // down
	objISpyGlass.sailuvarray.uv1 = "0.375,0.25,0.5,0.375"; // middle
	objISpyGlass.sailuvarray.uv2 = "0.25,0.25,0.375,0.375"; // up
}

void TelescopeInitParameters()
{
	object tmpobj;
	ref mchref = GetMainCharacter();
	aref arItmScope;

	if (Items_FindItem(GetCharacterEquipByGroup(mchref, SPYGLASS_ITEM_TYPE), &arItmScope) >= 0)
		setTelescopeInitParameters(arItmScope);
	else
		setTelescopeInitParameters(&tmpobj);
}

void setTelescopeInitParameters(aref arItmScope)
{
	string texName = "telescope.tga";
	float fZoom = 5.5;
	int nShowItm = 7;
	int activateTime = 500;
	int updateTime = 150; //KB spyglasses - orig 150. 

	if (CheckAttribute(arItmScope, "scope.texture")) texName = arItmScope.scope.texture;
	if (CheckAttribute(arItmScope, "scope.zoom")) fZoom = stf(arItmScope.scope.zoom);
	if (CheckAttribute(arItmScope, "scope.time_activate")) activateTime = sti(arItmScope.scope.time_activate);
	if (CheckAttribute(arItmScope, "scope.time_update")) updateTime = sti(arItmScope.scope.time_update);
	
	// ChezJfrey & PB: Automatic Switch -->
	string widescreen = "";
	float screen_x = stf(showWindow.width);
	float screen_y = stf(showWindow.height);
	float screen_ratio = screen_x/screen_y;
	if(screen_ratio > 1.4){ widescreen = "\\battle_interface\\widescreen\\";}
	texName = widescreen + texName;
	// ChezJfrey & PB: Automatic Switch <--

	SendMessage(objISpyGlass, "lsfll", MSG_TELESCOPE_SET_TYPE, texName, fZoom, activateTime, updateTime);
}
