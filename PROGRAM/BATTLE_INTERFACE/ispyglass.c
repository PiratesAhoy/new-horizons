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

void IS_Frame()
{
	int chridx = -1;
	int	shipHull = -1;
	int shipSail = -1;
	int shipCrew = -1;
	int shipCannons = -1;
	int shipCharge = -1;
	int shipNation = -1;
	float shipSpeed = -1.0;
	string shipName = "";
	string shipType = "";
	ref rISpyglass; makeref(rISpyglass, objISpyGlass);

	if (CheckAttribute(rISpyglass, "chr")) chridx = sti(rISpyglass.chr);
	if (CheckAttribute(rISpyglass, "shipName")) shipName = rISpyglass.shipName;
	if (CheckAttribute(rISpyglass, "shipType")) shipType = rISpyglass.shipType;
	if (CheckAttribute(rISpyglass, "shipHull")) shipHull = sti(rISpyglass.shipHull);
	if (CheckAttribute(rISpyglass, "shipSail")) shipSail = sti(rISpyglass.shipSail);
	if (CheckAttribute(rISpyglass, "shipCrew")) shipCrew = sti(rISpyglass.shipCrew);
	if (CheckAttribute(rISpyglass, "shipSpeed")) shipSpeed = stf(rISpyglass.shipSpeed);
	if (CheckAttribute(rISpyglass, "shipCannons")) shipCannons = sti(rISpyglass.shipCannons);
	if (CheckAttribute(rISpyglass, "shipCharge")) shipCharge = sti(rISpyglass.shipCharge);
	if (CheckAttribute(rISpyglass, "shipNation")) shipNation = sti(rISpyglass.shipNation);

	SendMessage(&objISpyGlass,"lsslllflll",MSG_ISG_UPDATE, shipName, shipType, shipHull, shipSail, shipCrew, shipSpeed, shipCannons, shipCharge, shipNation);
	SendMessage(&objISpyGlass,"ll",MSG_ISG_VISIBLE, true);
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
				shipType = shipType + "    " + shipDistance + " " + XI_ConvertString("yards");
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
				shipName = XI_ConvertString(GetShipTypeName(chref)) + " : " + GetMyShipName(chref);
			}
			if( CheckAttribute(arScopeItm,"scope.show.ship_type") && sti(arScopeItm.scope.show.ship_type)!=0 )
			{
				shipType = XI_ConvertString("BClass") + " " + GetCharacterShipClass(chref);
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
				shipType = shipType + ",	  " + shipDistance + " " + XI_ConvertString("yards");
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

		// boal + NK -->
		//ClearAllLogStrings();
		//if(showmorale && CheckAttribute(chref,"Ship.Crew.Morale")) { Log_SetStringToLog("Distance " + makeint(Ship_GetDistance2D(GetMainCharacter(), chref)) + ", morale: " + GetMoraleName(sti(chref.Ship.Crew.Morale))); }
		//else { Log_SetStringToLog("Distance " + makeint(Ship_GetDistance2D(GetMainCharacter(), chref))); }
		//SendMessage(&objISpyGlass,"lsslllflll",MSG_ISG_UPDATE, shipName,shipType, shipHull,shipSail,shipCrew, shipSpeed,shipCannons,shipCharge,shipNation);
		//SendMessage(&objISpyGlass,"lssllfflll",MSG_ISG_UPDATE, shipName,shipType, shipHull,shipSail,shipCrew, shipSpeed,shipCannons,shipCharge,shipNation);
		// boal + NK <-- <--
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
				shipType = shipType + "    " + shipDistance + " " + XI_ConvertString("yards");
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
					shipType = XI_ConvertString("BClass") + " " + GetCharacterShipClass(chref);
				}
				else
				{
					shipType = XI_ConvertString("BClass") + "?";
				}
			}


			if ( CheckAttribute(arScopeItm,"scope.show.ship_name") && sti(arScopeItm.scope.show.ship_name)!=0 )
			{
				if ( rangetype >= realshipdistance + (spyglassacc - 1) * incrange )
				{
					shipName = XI_ConvertString(GetShipTypeName(chref)) + " : ";
				}
				else
				{
					shipName = " ";
				}
				
				if ( rangename >= realshipdistance + (spyglassacc - 1) * incrange )
				{
					shipName = shipName + GetMyShipName(chref);
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
				shipType = shipType + ",	  " + shipDistance + " " + XI_ConvertString("yards");
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

	// boal + NK -->
	//ClearAllLogStrings();
	//if(showmorale && CheckAttribute(chref,"Ship.Crew.Morale")) { Log_SetStringToLog("Distance " + makeint(Ship_GetDistance2D(GetMainCharacter(), chref)) + ", morale: " + GetMoraleName(sti(chref.Ship.Crew.Morale))); }
	//else { Log_SetStringToLog("Distance " + makeint(Ship_GetDistance2D(GetMainCharacter(), chref))); }
	//SendMessage(&objISpyGlass,"lsslllflll",MSG_ISG_UPDATE, shipName,shipType, shipHull,shipSail,shipCrew, shipSpeed,shipCannons,shipCharge,shipNation);
	//SendMessage(&objISpyGlass,"lssllfflll",MSG_ISG_UPDATE, shipName,shipType, shipHull,shipSail,shipCrew, shipSpeed,shipCannons,shipCharge,shipNation);
	// boal + NK <-- <--

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

	if(iRealismMode>1 || ONSEA_DATA_DISABLED) {  //Screwface : No infos in realistic mod // KK ship type and nation become quite obvious from some distances
		if (Ship_GetGroupID(chref) != PLAYER_GROUP) shipName = chref.Ship.Name;
		distance = Ship_GetDistance2D(mchref, chref);
		if (distance < GetCharVisibilityRange(mchref, 3)) // Ship type, nation AND name shown inside CLOSE range
		{
			SendMessage(&objISpyGlass,"lsslllflll",MSG_ISG_UPDATE, shipName, shipType, -1, -1, -1, -1.0, -1, -1, shipNation);
			SendMessage(&objISpyGlass,"ll",MSG_ISG_VISIBLE, true);
		}
		else
		{
			if (distance < GetCharVisibilityRange(mchref, 2)) // Ship type and nation shown inside MEDIUM range
			{
				SendMessage(&objISpyGlass,"lsslllflll",MSG_ISG_UPDATE, "", shipType, -1, -1, -1, -1.0, -1, -1, shipNation);
				SendMessage(&objISpyGlass,"ll",MSG_ISG_VISIBLE, true);
			}
			else
			{
				if (distance < GetCharVisibilityRange(mchref, 1)) // Ship type is visible inside LONG range
				{
					SendMessage(&objISpyGlass,"lsslllflll",MSG_ISG_UPDATE, "", shipType, -1, -1, -1, -1.0, -1, -1, -1);
					SendMessage(&objISpyGlass,"ll",MSG_ISG_VISIBLE, true);
				}
			}
		}
	} else {
		SendMessage(&objISpyGlass,"lsslllflll",MSG_ISG_UPDATE, shipName, shipType, shipHull, shipSail, shipCrew, shipSpeed, shipCannons, shipCharge, shipNation);
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

void FillISpyGlassParameters()
{
	// скорость фэйда
	objISpyGlass.parameters.FadeTime = 0.5;
	// имена текстурных файлов для подложки и иконок
	objISpyGlass.parameters.BackTextureName = "battle_interface\panel.tga";
	objISpyGlass.parameters.IconsTextureName = "battle_interface\spyglasses_icons.tga";
	objISpyGlass.parameters.NationsTextureName = "battle_interface\all_nations"+GetCurrentPeriod()+".tga"; // PB
	int bottomOffset = 24;
	// позиция подложки
	objISpyGlass.parameters.globalpos.left = 0;
	objISpyGlass.parameters.globalpos.top = sti(showWindow.bottom)-RecalculateVIcon(50+bottomOffset);
	objISpyGlass.parameters.globalpos.right = sti(showWindow.width);
	objISpyGlass.parameters.globalpos.bottom = sti(showWindow.bottom)-RecalculateVIcon(bottomOffset);
	// размер иконок
	objISpyGlass.parameters.iconsize.x = RecalculateHIcon(40);
	objISpyGlass.parameters.iconsize.y = RecalculateVIcon(40);
	// текст об имени корабля и его типе
	objISpyGlass.parameters.ShipText.font = "interface_normal";
	objISpyGlass.parameters.ShipText.scale = 1.0;
	objISpyGlass.parameters.ShipText.left = sti(showWindow.left)+RecalculateHIcon(10+42);
	objISpyGlass.parameters.ShipText.topName = sti(showWindow.bottom)-RecalculateVIcon(bottomOffset+80);
	objISpyGlass.parameters.ShipText.topType = sti(showWindow.bottom)-RecalculateVIcon(bottomOffset+36);
	// текст инфы об корабле
	objISpyGlass.parameters.DigitData.font = "bold_numbers";
	objISpyGlass.parameters.DigitData.scale = 0.5;
	objISpyGlass.parameters.DigitData.topOffset = sti(showWindow.bottom)-RecalculateVIcon(bottomOffset+32);
	objISpyGlass.parameters.DigitData.leftHull = makeint(205.0*stf(showWindow.sw)/640.0);
	objISpyGlass.parameters.DigitData.leftSail = makeint(297.0*stf(showWindow.sw)/640.0);
	objISpyGlass.parameters.DigitData.leftCrew = makeint(393.0*stf(showWindow.sw)/640.0);
	objISpyGlass.parameters.DigitData.leftSpeed = makeint(478.0*stf(showWindow.sw)/640.0);
	objISpyGlass.parameters.DigitData.leftCannons = makeint(562.0*stf(showWindow.sw)/640.0);
	// координаты для иконок
	objISpyGlass.parameters.Icons.topOffset = sti(showWindow.bottom)-RecalculateVIcon(bottomOffset+45);
	objISpyGlass.parameters.Icons.leftNation = sti(showWindow.left)+RecalculateHIcon(10);
	objISpyGlass.parameters.Icons.leftHull = sti(objISpyGlass.parameters.DigitData.leftHull)-RecalculateHIcon(42);
	objISpyGlass.parameters.Icons.leftSail = sti(objISpyGlass.parameters.DigitData.leftSail)-RecalculateHIcon(42);
	objISpyGlass.parameters.Icons.leftCrew = sti(objISpyGlass.parameters.DigitData.leftCrew)-RecalculateHIcon(42);
	objISpyGlass.parameters.Icons.leftSpeed = sti(objISpyGlass.parameters.DigitData.leftSpeed)-RecalculateHIcon(42);
	objISpyGlass.parameters.Icons.leftCannons = sti(objISpyGlass.parameters.DigitData.leftCannons)-RecalculateHIcon(42);
	objISpyGlass.parameters.Icons.leftCharge = sti(showWindow.right)-RecalculateHIcon(42);
	// координаты tu,tv для иконок
	objISpyGlass.parameters.IconsTexture.hull.left = 0;
	objISpyGlass.parameters.IconsTexture.hull.top = 0;
	objISpyGlass.parameters.IconsTexture.hull.right = 0.3125;
	objISpyGlass.parameters.IconsTexture.hull.bottom = 0.3125;
	//
	objISpyGlass.parameters.IconsTexture.sail.left = 0.3125;
	objISpyGlass.parameters.IconsTexture.sail.top = 0;
	objISpyGlass.parameters.IconsTexture.sail.right = 0.625;
	objISpyGlass.parameters.IconsTexture.sail.bottom = 0.3125;
	//
	objISpyGlass.parameters.IconsTexture.crew.left = 0.625;
	objISpyGlass.parameters.IconsTexture.crew.top = 0;
	objISpyGlass.parameters.IconsTexture.crew.right = 0.9375;
	objISpyGlass.parameters.IconsTexture.crew.bottom = 0.3125;
	//
	objISpyGlass.parameters.IconsTexture.speed.left = 0;
	objISpyGlass.parameters.IconsTexture.speed.top = 0.3125;
	objISpyGlass.parameters.IconsTexture.speed.right = 0.3125;
	objISpyGlass.parameters.IconsTexture.speed.bottom = 0.625;
	//
	objISpyGlass.parameters.IconsTexture.cannons.left = 0.3125;
	objISpyGlass.parameters.IconsTexture.cannons.top = 0.3125;
	objISpyGlass.parameters.IconsTexture.cannons.right = 0.625;
	objISpyGlass.parameters.IconsTexture.cannons.bottom = 0.625;
	//
	objISpyGlass.parameters.IconsTexture.charge0.left = 0.625;
	objISpyGlass.parameters.IconsTexture.charge0.top = 0.625;
	objISpyGlass.parameters.IconsTexture.charge0.right = 0.9375;
	objISpyGlass.parameters.IconsTexture.charge0.bottom = 0.9375;
	//
	objISpyGlass.parameters.IconsTexture.charge1.left = 0.625;
	objISpyGlass.parameters.IconsTexture.charge1.top = 0.3125;
	objISpyGlass.parameters.IconsTexture.charge1.right = 0.9375;
	objISpyGlass.parameters.IconsTexture.charge1.bottom = 0.625;
	//
	objISpyGlass.parameters.IconsTexture.charge2.left = 0.3125;
	objISpyGlass.parameters.IconsTexture.charge2.top = 0.625;
	objISpyGlass.parameters.IconsTexture.charge2.right = 0.625;
	objISpyGlass.parameters.IconsTexture.charge2.bottom = 0.9375;
	//
	objISpyGlass.parameters.IconsTexture.charge3.left = 0;
	objISpyGlass.parameters.IconsTexture.charge3.top = 0.625;
	objISpyGlass.parameters.IconsTexture.charge3.right = 0.3125;
	objISpyGlass.parameters.IconsTexture.charge3.bottom = 0.9375;
	//
	objISpyGlass.parameters.IconsTexture.nations.portugal.left = 0;
	objISpyGlass.parameters.IconsTexture.nations.portugal.top = 0;
	objISpyGlass.parameters.IconsTexture.nations.portugal.right = 0.08203125;	//changed by KAM
	objISpyGlass.parameters.IconsTexture.nations.portugal.bottom = 0.65625;
	//
	objISpyGlass.parameters.IconsTexture.nations.spain.left = 0.08203125;		//changed by KAM
	objISpyGlass.parameters.IconsTexture.nations.spain.top = 0;
	objISpyGlass.parameters.IconsTexture.nations.spain.right = 0.1640625;		//changed by KAM
	objISpyGlass.parameters.IconsTexture.nations.spain.bottom = 0.65625;
	//
	objISpyGlass.parameters.IconsTexture.nations.pirate.left = 0.1640625;		//changed by KAM
	objISpyGlass.parameters.IconsTexture.nations.pirate.top = 0;
	objISpyGlass.parameters.IconsTexture.nations.pirate.right = 0.24609375;		//changed by KAM
	objISpyGlass.parameters.IconsTexture.nations.pirate.bottom = 0.65625;
	//
	objISpyGlass.parameters.IconsTexture.nations.england.left = 0.24609375;		//changed by KAM
	objISpyGlass.parameters.IconsTexture.nations.england.top = 0;
	objISpyGlass.parameters.IconsTexture.nations.england.right = 0.328125;		//changed by KAM
	objISpyGlass.parameters.IconsTexture.nations.england.bottom = 0.65625;
	//
	objISpyGlass.parameters.IconsTexture.nations.holland.left = 0.328125;		//changed by KAM
	objISpyGlass.parameters.IconsTexture.nations.holland.top = 0;
	objISpyGlass.parameters.IconsTexture.nations.holland.right = 0.41015625;	//changed by KAM
	objISpyGlass.parameters.IconsTexture.nations.holland.bottom = 0.65625;
	//
	objISpyGlass.parameters.IconsTexture.nations.france.left = 0.41015625;		//changed by KAM
	objISpyGlass.parameters.IconsTexture.nations.france.top = 0;
	objISpyGlass.parameters.IconsTexture.nations.france.right = 0.4921875;		//changed by KAM
	objISpyGlass.parameters.IconsTexture.nations.france.bottom = 0.65625;
	//
	objISpyGlass.parameters.IconsTexture.nations.america.left = 0.4921875;	// KK
	objISpyGlass.parameters.IconsTexture.nations.america.top = 0;			// KK
	objISpyGlass.parameters.IconsTexture.nations.america.right = 0.57421875;	// KK
	objISpyGlass.parameters.IconsTexture.nations.america.bottom = 0.65625;	// KK
	//
	objISpyGlass.parameters.IconsTexture.nations.neutral_nation.left = 0.57421875;	//added by KAM
	objISpyGlass.parameters.IconsTexture.nations.neutral_nation.top = 0;		//added by KAM
	objISpyGlass.parameters.IconsTexture.nations.neutral_nation.right = 0.65625;	//added by KAM
	objISpyGlass.parameters.IconsTexture.nations.neutral_nation.bottom = 0.65625;	//added by KAM
	//
	objISpyGlass.parameters.IconsTexture.nations.unknown_nation.left = 0.65625;	//added by KAM
	objISpyGlass.parameters.IconsTexture.nations.unknown_nation.top = 0;		//added by KAM
	objISpyGlass.parameters.IconsTexture.nations.unknown_nation.right = 0.73828125;	//added by KAM
	objISpyGlass.parameters.IconsTexture.nations.unknown_nation.bottom = 0.65625;	//added by KAM
	//
	objISpyGlass.parameters.IconsTexture.nations.personal_nation.left = 0.73828125;	// KK
	objISpyGlass.parameters.IconsTexture.nations.personal_nation.top = 0;			// KK
	objISpyGlass.parameters.IconsTexture.nations.personal_nation.right = 0.8203125;	// KK
	objISpyGlass.parameters.IconsTexture.nations.personal_nation.bottom = 0.65625;	// KK

	objISpyGlass.chr = -1; // KK
}

void TelescopeInitParameters(ref rTelescope)
{
	object tmpobj;
	ref mchref = GetMainCharacter();
	aref arItmScope;

	if (Items_FindItem(GetCharacterEquipByGroup(mchref, SPYGLASS_ITEM_TYPE), &arItmScope) >= 0)
	setTelescopeInitParameters(rTelescope, arItmScope);
	else
	setTelescopeInitParameters(rTelescope, &tmpobj);
}

void setTelescopeInitParameters(ref rTelescope, aref arItmScope)
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

	SendMessage(rTelescope, "lsflll", MSG_TELESCOPE_SET_TYPE, texName, fZoom, nShowItm, activateTime, updateTime);
}
