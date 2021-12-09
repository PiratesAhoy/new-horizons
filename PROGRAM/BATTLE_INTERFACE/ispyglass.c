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
	if(chrIdx<0) return;
//trace("SetSpyGlassData");
	string sTextureName = "battle_interface\ship_icons3.tga.tx";
	float uvLeft = 0;
	float uvTop = 0;
	float uvRight = 0.125;
	float uvBottom = 0.125;//0.25;

	int	shipHull = -1;
	int shipSail = -1;
	int shipCrew = -1;
	int shipCannons = -1;
	int shipMaxCannons = -1;
	int shipCharge = -1;
	int shipNation = -1;
	int shipClass = 1;
	float shipSpeed = -1.0;
	string shipName = "";
	string shipType = "";

	object tmpobj;
	aref arScopeItm;
	int tmpCharge;

	ref chref = GetCharacter(chrIdx);

	if( Items_FindItem( GetCharacterEquipByGroup(pchar,SPYGLASS_ITEM_TYPE), &arScopeItm)<0 )
		{	makearef(arScopeItm,tmpobj);	}

	if( !CheckAttribute(arScopeItm,"scope.show.nation") || sti(arScopeItm.scope.show.nation)!=0 )
		{	shipNation = TranslateNationCode(sti(chref.nation));	}

	int nSailState = 1;
	float fSailSt = GetSailPercent(chref);
	if( fSailSt<0.3 ) {nSailState = 0;}
	else {
		if( fSailSt<0.6 ) {nSailState = 1;}
		else {nSailState = 2;}
	}
	int nFace = sti(chref.faceID);
	string sCaptainName = GetCharacterFullName(chref.id);
	int nFencingSkill = GetCharacterSkill(chref,SKILL_DEFENCE);
	int nCannonSkill = GetCharacterSkill(chref,SKILL_GRAPPLING);
	int nAccuracySkill = GetCharacterSkill(chref,SKILL_CANNONS);
	int nNavigationSkill = GetCharacterSkill(chref,SKILL_ACCURACY);
	int nBoardingSkill = GetCharacterSkill(chref,SKILL_SAILING);
	if( !CheckAttribute(arScopeItm,"scope.show.captain_skills") || sti(arScopeItm.scope.show.captain_skills)==0) {
		nFencingSkill = -1;
		nCannonSkill = -1;
		nAccuracySkill = -1;
		nNavigationSkill = -1;
		nBoardingSkill = -1;
	}

	if(CheckAttribute(chref,"Ship.Type"))
	{
		int iShip = GetCharacterShipType(chref); //sti(chref.Ship.Type);
		if (iShip != SHIP_NOTUSED)
		{
			//iShip = sti(RealShips[iShip].basetype);
			//if(ShipsTypes[iShip].name == "fort")
			trace("iShip: " + iShip + ", SHIP_FORT: " + SHIP_FORT);
			if(iShip == SHIP_FORT)
			{
				if (CheckAttribute(arScopeItm,"scope.show.ship_type") && sti(arScopeItm.scope.show.ship_type)!=0 )
				{
					shipType = XI_ConvertString("Fort_Name");//boal fix
				}
				// boal -->
				if (CheckAttribute(arScopeItm,"scope.show.ship_name") && sti(arScopeItm.scope.show.ship_name)!=0 )
				{
					shipName = "Fort";
                    if (CheckAttribute(chref, "town")) {
                        shipName = TranslateString(FindTownName(chref.town), shipName);
                    } else {
                        shipName = TranslateString("", shipName);
                    }
                    if (CheckAttribute(chref, "Fort.Mode") == true && chref.Fort.Mode != FORT_NORMAL) shipName += " (" + XI_ConvertString("DESTROYED") + ")";
				}
				// boal <--
				if (CheckAttribute(arScopeItm,"scope.show.cannons") && sti(arScopeItm.scope.show.cannons)!=0) {
					shipCannons = Fort_GetCannonsQuantity(chref);
					if( !CheckAttribute(chref, "fort.Cannons.Quantity") ) {shipMaxCannons=0;}
					else {shipMaxCannons = sti(chref.Fort.Cannons.Quantity);}
				}
				if(CheckAttribute(arScopeItm,"scope.show.crew") && sti(arScopeItm.scope.show.crew)!=0)
					{	shipCrew = GetCrewQuantity(chref);	}
				if( !CheckAttribute(arScopeItm,"scope.show.hull") || sti(arScopeItm.scope.show.hull)!=0 ) {
					if( CheckAttribute(chref,"ship.hp") && CheckAttribute(chref,"fort.hp") && stf(chref.Fort.hp)>0.0 ) {
						shipHull = makeint( stf(chref.ship.hp)/stf(chref.Fort.hp) * 100.0 );
					} else {
						shipHull = 100;
					}
				}
				if (CheckAttribute(arScopeItm,"scope.show.charge") && sti(arScopeItm.scope.show.charge)!=0)
				{
					tmpCharge = sti(chref.Ship.Cannons.Charge.Type);
					switch(tmpCharge)
					{
					case GOOD_BALLS: shipCharge=0; break;
					case GOOD_GRAPES: shipCharge=3; break;
					case GOOD_KNIPPELS: shipCharge=2; break;
					case GOOD_BOMBS: shipCharge=1; break;
					}
				}

				sTextureName = "battle_interface\list_icon2.tga.tx";
				uvLeft = 0.375;
				uvTop = 0.75;
				uvRight = 0.5;
				uvBottom = 0.875;
				nSailState = -1;
			}
			else
			{
				GetTextureUVForShip(iShip, &uvLeft, &uvTop, &uvRight, &uvBottom);

				shipClass = GetCharacterShipClass(chref);

				if (CheckAttribute(arScopeItm,"scope.show.cannons") && sti(arScopeItm.scope.show.cannons)!=0)
				{
					//shipCannons = GetIntactCannonQuantity(chref);
					shipMaxCannons = GetCannonQuantity(chref);
					shipCannons = shipMaxCannons;
				}
				if (CheckAttribute(arScopeItm,"scope.show.ship_name") && sti(arScopeItm.scope.show.ship_name)!=0 )
				{
					shipName =  chref.Ship.Name;
				}
				if (CheckAttribute(arScopeItm,"scope.show.ship_type") && sti(arScopeItm.scope.show.ship_type)!=0 )
				{
					shipType = XI_ConvertString(GetShipTypeName(chref));
				}


				if (CheckAttribute(arScopeItm,"scope.show.hull") && sti(arScopeItm.scope.show.hull) == true)
				{
					shipHull = makeint(GetHullPercent(chref));
				}
				if (CheckAttribute(arScopeItm,"scope.show.sail") && sti(arScopeItm.scope.show.sail) == true)
				{
					shipSail = makeint(GetSailPercent(chref));
				}
				if (CheckAttribute(arScopeItm,"scope.show.crew") && sti(arScopeItm.scope.show.crew) == true)
				{
					shipCrew = GetCrewQuantity(chref);
				}
				if (CheckAttribute(arScopeItm,"scope.show.speed") && sti(arScopeItm.scope.show.speed) == true )
				{
					if (CheckAttribute(chref,"Ship.speed.z")) //bug with forts
					{
						shipSpeed = stf(chref.Ship.speed.z) * stf(BattleInterface.ShipSpeedScaler);
					} else {
						shipSpeed = 0.0;
					}
				}
				if (CheckAttribute(arScopeItm,"scope.show.charge") && sti(arScopeItm.scope.show.charge) == true)
				{
					tmpCharge = sti(chref.Ship.Cannons.Charge.Type);
					switch(tmpCharge)
					{
					case GOOD_BALLS:     shipCharge=0; break;
					case GOOD_GRAPES:    shipCharge=3; break;
					case GOOD_KNIPPELS:  shipCharge=2; break;
					case GOOD_BOMBS:     shipCharge=1; break;
					}
				}
			}
		}
	}
	if (CheckAttribute(arScopeItm,"scope.show.cannontype") && sti(arScopeItm.scope.show.cannontype)== true)
	{
		string CannonTypeName = "";

		switch (sti(chref.Ship.Cannons.Type))
		{
			case  CANNON_TYPE_CANNON_LBS12:
			     CannonTypeName = " " + xiDStr("CannonTypeName_12");
			     break;

			case  CANNON_TYPE_CANNON_LBS16:
			     CannonTypeName = " " + xiDStr("CannonTypeName_16");
			     break;

			case  CANNON_TYPE_CANNON_LBS24:
			     CannonTypeName = " " + xiDStr("CannonTypeName_24");
			     break;

			case  CANNON_TYPE_CANNON_LBS32:
			     CannonTypeName = " " + xiDStr("CannonTypeName_32");
			     break;

			case CANNON_TYPE_CULVERINE_LBS12:
			     CannonTypeName = " " + xiDStr("CulTypeName_12");
			     break;

			case CANNON_TYPE_CULVERINE_LBS16:
			     CannonTypeName = " " + xiDStr("CulTypeName_16");
			     break;

			case CANNON_TYPE_CULVERINE_LBS24:
			     CannonTypeName = " " + xiDStr("CulTypeName_24");
			     break;
		}
		sCaptainName = CannonTypeName + "       " + sCaptainName;
	}
    //sCaptainName = XI_ConvertString("Distance") + ": " + FloatToString(Ship_GetDistance2D(GetMainCharacter(), chref), 1) + "       " + sCaptainName;
    float fDistance = stf(FloatToString(Ship_GetDistance2D(GetMainCharacter(), chref), 1)); //boal
	SendMessage(&objISpyGlass,"lsslllfflllllllllllssl",MSG_ISG_UPDATE, shipName,shipType,  //boal
		shipHull,shipSail,shipCrew,	shipSpeed, fDistance,
		shipCannons,shipMaxCannons,
		shipCharge,shipNation, nSailState,nFace,
		nFencingSkill,nCannonSkill,nAccuracySkill,nNavigationSkill,nBoardingSkill,
		sCaptainName,"",shipClass);
	SendMessage(&objISpyGlass,"lsffff",MSG_ISG_SET_SHIPICON, sTextureName, uvLeft,uvTop,uvRight,uvBottom);
	SendMessage(&objISpyGlass,"ll",MSG_ISG_VISIBLE,true);
	// debug info -->
	if (false) //bBettaTestMode)
	{
		ClearAllLogStrings();
		if (CheckAttribute(chref, "SeaAI.Task"))
		{
		    Log_SetStringToLog("shipType=" + GetCharacterShipType(chref) +
		                               " SeaAI.Task=" + chref.SeaAI.Task);
			if (CheckAttribute(chref, "SeaAI.Task.Target"))
			{
		        sCaptainName = "none";
				if (sti(chref.SeaAI.Task.Target) != -1)  sCaptainName = Characters[sti(chref.SeaAI.Task.Target)].id;

				Log_Info("SeaAI.Task.Target = " + chref.SeaAI.Task.Target + " id npc = " + sCaptainName);
			}
		}
/*		if (TestRansackCaptain && !bQuestLogShow && rand(20) == 4)
		{
		    pchar.SystemInfo.OnlyShowCharacter = true;
		    LaunchCharacter(chref);
		}
		if (TestRansackCaptain && bQuestLogShow && rand(20) == 4)
		{
		    LaunchShipStateNPC(chref);
		}

		Log_SetStringToLog("Cap_id = " + chref.id +" hp= " + makeint(chref.chr_ai.hp) + " rank= "+ chref.rank +
		                           " Moral= " + chref.ship.crew.morale);
		Log_SetStringToLog("Ship.MaxCaliber=  " + RealShips[sti(chref.Ship.Type)].MaxCaliber +
		                           " Ship.Capacity =" + RealShips[sti(chref.Ship.Type)].Capacity  +
		                           " Ship.MaxCrew= " + RealShips[sti(chref.Ship.Type)].MaxCrew);

		Log_SetStringToLog("Ship.SpeedRate= " + RealShips[sti(chref.Ship.Type)].SpeedRate +
		                           " Ship.TurnRate =" + RealShips[sti(chref.Ship.Type)].TurnRate  +
		                           " Ship.HP=" + RealShips[sti(chref.Ship.Type)].HP);
		//Log_Info("CheckForSurrender = " + CheckForSurrender(pchar, chref, 1));
		Log_Info("CheckLockTask = " + CheckAttribute(chref, "ShipTaskLock"));
		Log_Info("CheckWatchFort = " + CheckAttribute(chref, "WatchFort"));
*/
		if (CheckAttribute(chref, "EncType")) Log_Info("EncType = " + chref.EncType);
		if (CheckAttribute(chref, "Ship.Mode")) Log_Info("Ship.Mode = " + chref.Ship.Mode);
		if (CheckAttribute(chref, "Ship.LastBallCharacter")) Log_Info("LastBallCharacter = " + chref.Ship.LastBallCharacter);

	}
	// boal <--
}

void ResetSpyGlassData()
{
	SendMessage(&objISpyGlass,"ll",MSG_ISG_VISIBLE,false);
}

int TranslateNationCode(int nationCode)
{
	switch(nationCode)
	{
	case PORTUGAL: return 6; break;
	case SPAIN: return 4; break;
	case PIRATE: return 5; break;
	case ENGLAND: return 1; break;
	case HOLLAND: return 0; break;
	case FRANCE: return 2; break;
	case SWEDEN:
	    if(SWEDEN_ALLOWED && GetDataYear() >= 1600 && GetDataYear() <= 1769)
            return 3;
        else
            return 7; //AMERICA
    break;
	case AMERICA: return 7; break;
	}
	return -1;
}

void FillISpyGlassParameters()
{
	string sTexture = "spyglass1";
	if (CheckAttribute(pchar, "equip.spyglass"))
	{
	    sTexture = pchar.equip.spyglass;
	}
	//log_info(pchar.equip.spyglass);
	objISpyGlass.lens.texture = "battle_interface\\spyglass\\" + sTexture + ".tga.tx";
	objISpyGlass.lens.pos = showWindow.left+","+showWindow.top+"," + showWindow.right+","+showWindow.bottom;

	int ntop = sti(showWindow.bottom) - RecalculateVIconScaled(70);
    int nbottom = ntop + RecalculateVIconScaled(128);
	//==========================================================
	objISpyGlass.shipsign.ship.texture = "battle_interface\\ship_icons3.tga.tx";
	objISpyGlass.shipsign.ship.pos = RecalculateHIconScaled(10)+","+(ntop+RecalculateVIconScaled(8)) + "," + RecalculateHIconScaled(72)+","+(ntop+RecalculateVIconScaled(65));
	objISpyGlass.shipsign.ship.uv = "0,0,0.125,0.125";//"0,0,0.125,0.25";
	objISpyGlass.shipsign.back.texture = "battle_interface\\blank.tga.tx";
	objISpyGlass.shipsign.back.pos = RecalculateHIconScaled(10)+","+ntop + "," + RecalculateHIconScaled(138)+","+nbottom;
	objISpyGlass.shipsign.hp.texture = "battle_interface\\ShipState.tga.tx";
	objISpyGlass.shipsign.hp.pos = RecalculateHIconScaled(-2)+","+(ntop+RecalculateVIconScaled(3)) + "," + RecalculateHIconScaled(40)+","+(ntop+RecalculateVIconScaled(65));
	objISpyGlass.shipsign.hp.uv = "0.0,0.109,0.5,0.6875";
	objISpyGlass.shipsign.sp.texture = "battle_interface\\ShipState.tga.tx";
	objISpyGlass.shipsign.sp.pos = RecalculateHIconScaled(62)+","+(ntop+RecalculateVIconScaled(3)) + "," + RecalculateHIconScaled(98)+","+(ntop+RecalculateVIconScaled(65));
	objISpyGlass.shipsign.sp.uv = "0.5,0.109,1.0,0.6875";
	objISpyGlass.shipsign.class.texture = "battle_interface\\blank.tga.tx";
	objISpyGlass.shipsign.class.pos = RecalculateHIconScaled(30)+","+(ntop+RecalculateVIconScaled(6)) + "," + RecalculateHIconScaled(92)+","+(ntop+RecalculateVIconScaled(22));
	//
	objISpyGlass.info.nation.texture = "flagall.tga.tx";
	objISpyGlass.info.nation.pos = RecalculateHIconScaled(75)+","+(ntop+RecalculateVIconScaled(8)) + "," + RecalculateHIconScaled(140)+","+(ntop+RecalculateVIconScaled(40));
	objISpyGlass.info.nation.uv = "0.0,0.0,0.125,1.0";
	//
	objISpyGlass.info.cannon.texture = "battle_interface\\list_icons.tga.tx";
	objISpyGlass.info.cannon.pos = RecalculateHIconScaled(470)+","+(ntop+RecalculateVIconScaled(16)) + "," + RecalculateHIconScaled(520)+","+(ntop+RecalculateVIconScaled(65));
	objISpyGlass.info.cannon.uv = "0.625,0.375,0.6875,0.5";
	//
	objISpyGlass.info.speed.texture = "battle_interface\\list_icon2.tga.tx";
	objISpyGlass.info.speed.pos = RecalculateHIconScaled(330)+","+(ntop+RecalculateVIconScaled(16)) + "," + RecalculateHIconScaled(380)+","+(ntop+RecalculateVIconScaled(65));
	objISpyGlass.info.speed.uv = "0.25,0.25,0.375,0.375";

	objISpyGlass.info.sailto.texture = "battle_interface\\list_icons.tga.tx";   // boal
	objISpyGlass.info.sailto.pos = RecalculateHIconScaled(400)+","+(ntop+RecalculateVIconScaled(16)) + "," + RecalculateHIconScaled(450)+","+(ntop+RecalculateVIconScaled(65));
	objISpyGlass.info.sailto.uv = "0.75,0.25,0.8125,0.375";

	//
	objISpyGlass.info.charge.texture = "battle_interface\\list_icon2.tga.tx";
	objISpyGlass.info.charge.pos = RecalculateHIconScaled(356)+","+(ntop+RecalculateVIconScaled(42)) + "," + RecalculateHIconScaled(404)+","+(ntop+RecalculateVIconScaled(90));
	objISpyGlass.info.charge.uv = "0.125,0.5,0.25,0.625";

	objISpyGlass.captain.back.texture = "battle_interface\\blank.tga.tx";
	objISpyGlass.captain.back.pos = RecalculateHIconScaled(906)+","+ntop + "," + RecalculateHIconScaled(1034)+","+nbottom;
	objISpyGlass.captain.face.texture = "battle_interface\\portraits\\blank.tx";
	objISpyGlass.captain.face.pos = RecalculateHIconScaled(948)+","+(ntop+RecalculateVIconScaled(10)) + "," + RecalculateHIconScaled(1012)+","+(ntop+RecalculateVIconScaled(65));
	//
	/* if( IsNetActive() ) {
		objISpyGlass.captain.fencing.texture = "interfaces\\skills.tga.tx";
		objISpyGlass.captain.fencing.pos = RecalculateHIcon(830)+","+(ntop+RecalculateVIcon(42)) + "," + RecalculateHIcon(878)+","+(ntop+RecalculateVIcon(90));
		objISpyGlass.captain.fencing.uv = "0.5,0.75,0.625,0.875";
		objISpyGlass.captain.cannon.texture = "interfaces\\skills.tga.tx";
		objISpyGlass.captain.cannon.pos = RecalculateHIcon(758)+","+(ntop+RecalculateVIcon(42)) + "," + RecalculateHIcon(806)+","+(ntop+RecalculateVIcon(90));
		objISpyGlass.captain.cannon.uv = "0.625,0.75,0.75,0.875";
		objISpyGlass.captain.accuracy.texture = "interfaces\\skills.tga.tx";
		objISpyGlass.captain.accuracy.pos = RecalculateHIcon(686)+","+(ntop+RecalculateVIcon(42)) + "," + RecalculateHIcon(734)+","+(ntop+RecalculateVIcon(90));
		objISpyGlass.captain.accuracy.uv = "0,0.75,0.125,0.875";
		objISpyGlass.captain.navigation.texture = "interfaces\\skills.tga.tx";
		objISpyGlass.captain.navigation.pos = RecalculateHIcon(614)+","+(ntop+RecalculateVIcon(42)) + "," + RecalculateHIcon(662)+","+(ntop+RecalculateVIcon(90));
		objISpyGlass.captain.navigation.uv = "0.875,0.875,1.0,1.0";
		objISpyGlass.captain.boarding.texture = "interfaces\\skills.tga.tx";
		objISpyGlass.captain.boarding.pos = RecalculateHIcon(542)+","+(ntop+RecalculateVIcon(42)) + "," + RecalculateHIcon(590)+","+(ntop+RecalculateVIcon(90));
		objISpyGlass.captain.boarding.uv = "0.75,0.75,0.875,0.875";
	} else */ {
		objISpyGlass.captain.fencing.texture = "interfaces\\icons_spec.tga.tx";
		objISpyGlass.captain.fencing.pos = RecalculateHIconScaled(830)+","+(ntop+RecalculateVIconScaled(42)) + "," + RecalculateHIconScaled(878)+","+(ntop+RecalculateVIconScaled(90));
		objISpyGlass.captain.fencing.uv = "0.875,0.125,1.0,0.25";
		objISpyGlass.captain.cannon.texture = "interfaces\\icons_spec.tga.tx";
		objISpyGlass.captain.cannon.pos = RecalculateHIconScaled(758)+","+(ntop+RecalculateVIconScaled(42)) + "," + RecalculateHIconScaled(806)+","+(ntop+RecalculateVIconScaled(90));
		objISpyGlass.captain.cannon.uv = "0.75,0.125,0.875,0.25";
		objISpyGlass.captain.accuracy.texture = "interfaces\\icons_spec.tga.tx";
		objISpyGlass.captain.accuracy.pos = RecalculateHIconScaled(686)+","+(ntop+RecalculateVIconScaled(42)) + "," + RecalculateHIconScaled(734)+","+(ntop+RecalculateVIconScaled(90));
		objISpyGlass.captain.accuracy.uv = "0.375,0.125,0.5,0.25";
		objISpyGlass.captain.navigation.texture = "interfaces\\icons_spec.tga.tx";
		objISpyGlass.captain.navigation.pos = RecalculateHIconScaled(614)+","+(ntop+RecalculateVIconScaled(42)) + "," + RecalculateHIconScaled(662)+","+(ntop+RecalculateVIconScaled(90));
		objISpyGlass.captain.navigation.uv = "0.25,0.125,0.375,0.25";
		objISpyGlass.captain.boarding.texture = "interfaces\\icons_spec.tga.tx";
		objISpyGlass.captain.boarding.pos = RecalculateHIconScaled(542)+","+(ntop+RecalculateVIconScaled(42)) + "," + RecalculateHIconScaled(590)+","+(ntop+RecalculateVIconScaled(90));
		objISpyGlass.captain.boarding.uv = "0.5,0.125,0.625,0.25";
	}

	//==========================================================
	float fBaseScale = stf(showWindow.width) / 1310.0;
	objISpyGlass.text.shiptype.font = "interface_normal";
	objISpyGlass.text.shiptype.pos = RecalculateHIconScaled(120)+","+(ntop+RecalculateVIconScaled(7));
	objISpyGlass.text.shiptype.color = argb(255,255,255,168);
	objISpyGlass.text.shiptype.scale = fBaseScale * 1.4;
	//
	objISpyGlass.text.shipname.font = "interface_normal";
	objISpyGlass.text.shipname.pos = RecalculateHIconScaled(120)+","+(ntop+RecalculateVIconScaled(30));
	objISpyGlass.text.shipname.color = argb(255,255,255,168);
	objISpyGlass.text.shipname.scale = fBaseScale * 1.4;
	//
	objISpyGlass.text.cannons.font = "interface_normal";
	objISpyGlass.text.cannons.pos = RecalculateHIconScaled(493)+","+(ntop+RecalculateVIconScaled(-4));
	objISpyGlass.text.cannons.align = "center";
	objISpyGlass.text.cannons.color = argb(255,255,255,168);
	objISpyGlass.text.cannons.scale = fBaseScale * 1.2;
	//
	objISpyGlass.text.speed.font = "interface_normal";
	objISpyGlass.text.speed.pos = RecalculateHIconScaled(356)+","+(ntop+RecalculateVIconScaled(-4));
	objISpyGlass.text.speed.align = "center";
	objISpyGlass.text.speed.color = argb(255,255,255,168);
	objISpyGlass.text.speed.scale = fBaseScale * 1.2;
	// boal
	objISpyGlass.text.sailto.font = "interface_normal";
	objISpyGlass.text.sailto.pos = RecalculateHIconScaled(425)+","+(ntop+RecalculateVIconScaled(-4));
	objISpyGlass.text.sailto.align = "center";
	objISpyGlass.text.sailto.color = argb(255,255,255,168);
	objISpyGlass.text.sailto.scale = fBaseScale * 1.2;
	//
	objISpyGlass.text.crew.font = "interface_normal";
	objISpyGlass.text.crew.pos = RecalculateHIconScaled(60)+","+(ntop+RecalculateVIconScaled(80));
	objISpyGlass.text.crew.align = "center";
	objISpyGlass.text.crew.color = argb(255,255,255,168);
	objISpyGlass.text.crew.scale = fBaseScale * 1.4;

	// captain text data
	objISpyGlass.captext.capname.font = "interface_normal";
	objISpyGlass.captext.capname.pos = RecalculateHIconScaled(1012)+","+(ntop-RecalculateVIconScaled(16));
	objISpyGlass.captext.capname.align = "right";
	objISpyGlass.captext.capname.color = argb(255,255,255,168);
	objISpyGlass.captext.capname.scale = fBaseScale * 1.4;
	//
	objISpyGlass.captext.fencing.font = "interface_normal";
	objISpyGlass.captext.fencing.pos = RecalculateHIconScaled(856)+","+(ntop+RecalculateVIconScaled(26));
	objISpyGlass.captext.fencing.align = "center";
	objISpyGlass.captext.fencing.color = argb(255,255,255,168);
	objISpyGlass.captext.fencing.scale = fBaseScale * 1.4;
	//
	objISpyGlass.captext.cannon.font = "interface_normal";
	objISpyGlass.captext.cannon.pos = RecalculateHIconScaled(784)+","+(ntop+RecalculateVIconScaled(26));
	objISpyGlass.captext.cannon.align = "center";
	objISpyGlass.captext.cannon.color = argb(255,255,255,168);
	objISpyGlass.captext.cannon.scale = fBaseScale * 1.4;
	//
	objISpyGlass.captext.accuracy.font = "interface_normal";
	objISpyGlass.captext.accuracy.pos = RecalculateHIconScaled(712)+","+(ntop+RecalculateVIconScaled(26));
	objISpyGlass.captext.accuracy.align = "center";
	objISpyGlass.captext.accuracy.color = argb(255,255,255,168);
	objISpyGlass.captext.accuracy.scale = fBaseScale * 1.4;
	//
	objISpyGlass.captext.navigation.font = "interface_normal";
	objISpyGlass.captext.navigation.pos = RecalculateHIconScaled(640)+","+(ntop+RecalculateVIconScaled(26));
	objISpyGlass.captext.navigation.align = "center";
	objISpyGlass.captext.navigation.color = argb(255,255,255,168);
	objISpyGlass.captext.navigation.scale = fBaseScale * 1.4;
	//
	objISpyGlass.captext.boarding.font = "interface_normal";
	objISpyGlass.captext.boarding.pos = RecalculateHIconScaled(566)+","+(ntop+RecalculateVIconScaled(26));
	objISpyGlass.captext.boarding.align = "center";
	objISpyGlass.captext.boarding.color = argb(255,255,255,168);
	objISpyGlass.captext.boarding.scale = fBaseScale * 1.4;

	//===============================================
	objISpyGlass.nationuvarray.uv0 = "0,0,0.125,1.0"; // holland
	objISpyGlass.nationuvarray.uv1 = "0.125,0,0.25,1.0"; // england
	objISpyGlass.nationuvarray.uv2 = "0.25,0,0.375,1.0"; // france
	objISpyGlass.nationuvarray.uv3 = "0.375,0,0.5,1.0"; // portugal
	objISpyGlass.nationuvarray.uv4 = "0.5,0,0.625,1.0"; // spain
	objISpyGlass.nationuvarray.uv5 = "0.625,0,0.75,1.0"; // pirate
	objISpyGlass.nationuvarray.uv6 = "0.75,0,0.875,1.0"; //
	objISpyGlass.nationuvarray.uv7 = "0.875,0,1.0,1.0"; //
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
	ref mchref = GetMainCharacter();

	aref arItmScope;
	if( Items_FindItem(GetCharacterEquipByGroup(mchref,SPYGLASS_ITEM_TYPE),&arItmScope)>=0 )
	{
	    setTelescopeInitParameters(arItmScope);
	}
	else
	{
		object tmpobj;
		setTelescopeInitParameters(&tmpobj);
	}
}

void setTelescopeInitParameters(aref arItmScope)
{
	string texName = "telescope.tga.tx";
	float fZoom = 5.5;
	int nShowItm = 7;
	int activateTime = 500;
	int updateTime = 150;

	if( CheckAttribute(arItmScope,"scope.texture") )
	{	texName = arItmScope.scope.texture;
	}
	if( CheckAttribute(arItmScope,"scope.zoom") )
	{
	    fZoom = stf(arItmScope.scope.zoom);
	}
	if( CheckAttribute(arItmScope,"scope.time_activate") )
	{	activateTime = sti(arItmScope.scope.time_activate);
	}
	if( CheckAttribute(arItmScope,"scope.time_update") )
	{	updateTime = sti(arItmScope.scope.time_update);
	}

	SendMessage(&objISpyGlass, "lsflll", MSG_TELESCOPE_SET_TYPE, texName, fZoom, nShowItm, activateTime, updateTime);
}

void GetTextureUVForShip(int nShipType, ref rLeft, ref rTop, ref rRight, ref rBottom)
{
	float fLeft = 0.0;
	float fTop = 0.0;
	float fRight = 0.125;
	float fBottom = 0.125;//0.25;

	if( nShipType>0 && nShipType<SHIP_TYPES_QUANTITY_WITH_FORT )
	{
		ref rBaseShip = &ShipsTypes[nShipType];
		SetShipPictureDataByShipTypeName( rBaseShip.name );
		int nV = BI_intNRetValue[0] / 8;
		int nH = BI_intNRetValue[0] - nV * 8;
		fLeft = stf(nH) * 0.125;
		fTop = stf(nV) * 0.125;//0.25;
		fRight = fLeft + 0.125;
		fBottom = fTop + 0.125;//0.25;
	}

	rLeft = fLeft;
	rTop = fTop;
	rRight = fRight;
	rBottom = fBottom;
}
