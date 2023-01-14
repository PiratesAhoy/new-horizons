object	Sea;
object	ShipLights;

extern void InitShipLights();

void SeaAI_GetLayers()
{
	aref oTmp = GetEventData();
	SendMessage(oTmp, "lll", AI_MESSAGE_SET_LAYERS, sCurrentSeaExecute, sCurrentSeaRealize);
}

void DeleteSea()
{
	DeleteClass(&Sea);
	DeleteClass(&ShipLights);
}

void CreateSea(int sExecuteLayer, int sRealizeLayer)
{
//	if (IsEntity(&Sea)) DeleteSeaEnvironment(); // KK { Trace("ERROR: Sea Already Loaded!!!"); return; }
//JA 5DEC06 returned to old function as DeleteSeaEnvironment appears to delete ships models on the sea. Need to leave sea stuff there so can reload after going to deck. (I think)
 	if (IsEntity(&Sea)) { return; }


	CreateEntity(&Sea, "sea");
	MoveSeaToLayers(sExecuteLayer, sRealizeLayer);

	LayerFreeze(SEA_REFLECTION, false);

	if (LoadSegment("sea_ai\ShipLights.c"))
	{
		InitShipLights();
		UnloadSegment("sea_ai\ShipLights.c");
	}
	CreateEntity(&ShipLights, "ShipLights");
	ReloadProgressUpdate();
	LayerAddObject(sExecuteLayer, &ShipLights, 0);
	LayerAddObject(sRealizeLayer, &ShipLights, -1);
	LayerAddObject(SEA_SUNROAD, &ShipLights, -1);

	Sea.AbordageMode = false;
}

void MoveSeaToLayers(int sExecuteLayer, int sRealizeLayer)
{
	LayerDelObject(EXECUTE, &Sea);
	LayerDelObject(REALIZE, &Sea);
	LayerDelObject(SEA_EXECUTE, &Sea);
	LayerDelObject(SEA_REALIZE, &Sea);

	LayerAddObject(sExecuteLayer, &Sea, 4);
	LayerAddObject(sRealizeLayer, &Sea, 65530);
}

#define SAIL_TO_LOCATOR			0
#define SAIL_TO_CHARACTER		1

object	SailToFader;
int		iSailToType;
string	sSailToString;

void SeaAI_SailToEndFade()
{
	DelEventHandler("FaderEvent_EndFade", "SeaAI_SailToEndFade");
	SendMessage(SailToFader, "lfl", FADER_IN, 0.5, true);

	// delete current cannonballs
	AIBalls.Clear = "";

	switch (iSailToType)
	{
		case SAIL_TO_LOCATOR:
			ref rCharacter = GetMainCharacter();
			aref rIslLoc = FindIslandReloadLocator(rCharacter.Location, sSailToString);
			// Screwface : Lagoon mod : Check if the locator is in a lagoon or not to update the color
			aref aCurWeather = GetCurrentWeather();
			aref arLocator, arReload;
			ref rIsland = GetIslandByIndex(FindIsland(rCharacter.location));
			makearef(arReload, rIsland.reload);
			int iNumReload = GetAttributesNum(arReload);
			for (int i=0;i<iNumReload;i++)
			{
				arLocator = GetAttributeN(arReload, i);
				if (arLocator.Name == rIslLoc.name)
				{
					if(stf(Locations[FindLocation(arLocator.go)].type =="seashore"))
					{
						if(aCurWeather.id == "Blue Sky" && wRain < 75)
						{
							//Sea.GF3.WaterColor = argb(0,45,129,153);
							Sea.GF3.WaterColor = argb(0,124,202,215);
							Sea.GF3.SkyColor = argb(0,109,185,240);
							Sea.WaterAttenuation = 0.3;
							arLocator.inlagoon = 1;
						}
						else
						{
							Sea.GF3.WaterColor = aCurWeather.Sea.Water.Color;
							Sea.GF3.SkyColor = aCurWeather.Sea.Sky.Color;
							Sea.WaterAttenuation = aCurWeather.Sea.WaterAttenuation;
							if(Checkattribute(arLocator, "inlagoon")) Deleteattribute(arLocator, "inlagoon");
						}
						//logit("locator : " + arLocator.name);
					}
					else
					{
						Sea.GF3.WaterColor = aCurWeather.Sea.Water.Color;
						Sea.GF3.SkyColor = aCurWeather.Sea.Sky.Color;
						Sea.WaterAttenuation = aCurWeather.Sea.WaterAttenuation;
						if(Checkattribute(arLocator, "inlagoon")) Deleteattribute(arLocator, "inlagoon");
					}
				}else{if(Checkattribute(arLocator, "inlagoon")) Deleteattribute(arLocator, "inlagoon");}
			} // Screwface : end
			SendMessage(AISea,"lffff", AI_MESSAGE_SAIL_2_LOCATOR, stf(rIslLoc.x), stf(rIslLoc.y), stf(rIslLoc.z), frnd() * PIm2);
		break;
		case SAIL_TO_CHARACTER:
			SendMessage(AISea, "laff", AI_MESSAGE_SAIL_2_CHARACTER, &Characters[sti(sSailToString)], SAILTO_DISTANCE1 + frnd()*(SAILTO_DISTANCE2-SAILTO_DISTANCE1), frnd() * PIm2);    // LDH change
		break;
	}
}

void SeaAI_SailToCreateFader()
{
	SetEventHandler("FaderEvent_EndFade", "SeaAI_SailToEndFade", 0);

	CreateEntity(&SailToFader, "fader");
	SendMessage(SailToFader, "lfl", FADER_OUT, 0.5, false);
	SendMessage(SailToFader, "l", FADER_STARTFRAME);
	SetReloadImage(&SailToFader, "Sea.tga"); // KK
	// NK sailto time 04-09-21
	AddSeaTimeToCurrent();
	ref pchar = GetMainCharacter();
	LogIt(pchar.sailtostring); DeleteAttribute(pchar, "sailtostring");
	// NK <--
}

void SeaAI_SailToLocator(string sLocName)
{
	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	iSailToType = SAIL_TO_LOCATOR;
	sSailToString = sLocName;
	// NK 04-09-21 add time to sailto
	ref pchar = GetMainCharacter();

	aref rIslLoc = FindIslandReloadLocator(pchar.location, sLocName);

	//get locator label
	aref arLocator, arReload;
	string loclabel = "";
	ref		rIsland = GetIslandByIndex(FindIsland(pchar.location));
	makearef(arReload, rIsland.reload);
	int		iNumReload = GetAttributesNum(arReload);
	for (int i=0;i<iNumReload;i++)
	{
		arLocator = GetAttributeN(arReload, i);
		if (arLocator.Name == sLocName) {loclabel = arLocator.label; break; }
	}

	float dx = stf(rIslLoc.x);
	float dz = stf(rIslLoc.z);
	float px = stf(pchar.ship.Pos.x);
	float pz = stf(pchar.ship.Pos.z);
	float dist = GetDistance2D(px, pz, dx, dz);
	aref arship; makearef(arship, pchar.ship);
	float angle = ClampAngle(atan2(pz-dz, px-dx));
	int time = GetTimeToSailDist(arship, dist, angle) * TIMESCALAR_SAILTO_LOC;
	if(dist > 0.75 * (GetDistance2D(px, pz, 0, 0) + GetDistance2D(dx, dz, 0, 0))) time *= TIMESCALAR_SAILTO_THRU/2.0; //i.e. probably through a piece of island - update 04-10-24
	if(SameSign(px * dx, pz * dz) && !SameSignPairs(px, pz, dx, dz)) time *= TIMESCALAR_SAILTO_THRU/2.0; //i.e. probably through center of island, so double again. 04-10-24
	pchar.seatime = sti(pchar.seatime) + makeint(makefloat(time) / makefloat(TIMESCALAR_SEA)); // because sailto has its own timescale above
	pchar.sailtostring = TranslateString("","Sail to") + " " + loclabel + " " + XI_ConvertString("takes") + " " + MakeTimeString(time);
	// NK <--
	SeaAI_SailToCreateFader();
	//LanguageCloseFile(tmpLangFileID);
}

void SeaAI_SailToCharacter(int iCharacterIndex)
{
	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	iSailToType = SAIL_TO_CHARACTER;
	sSailToString = "" + iCharacterIndex;
	// NK 04-09-21 add time to sailto
	ref pchar = GetMainCharacter();
	ref stchar = GetCharacter(iCharacterIndex);
	float dx = stf(stchar.ship.Pos.x);
	float dz = stf(stchar.ship.Pos.z);
	float px = stf(pchar.ship.Pos.x);
	float pz = stf(pchar.ship.Pos.z);
	float dist = GetDistance2D(px, pz, dx, dz);
	if(dist < SAILTO_MIN_DISTANCE && iRealismMode>0)
	{
		Logit(TranslateString("","Too close! Can't use sail-to. You must sail manually."));
		PlaySound("interface\knock.wav");
		return;
	}
	aref arship; makearef(arship, pchar.ship);
	float angle = ClampAngle(atan2(pz-dz, px-dx));
	int time = GetTimeToSailDist(arship, dist, angle) * TIMESCALAR_SAILTO_SHIP;
	if(dist > 0.75 * (GetDistance2D(px, pz, 0, 0) + GetDistance2D(dx, dz, 0, 0))) time *= TIMESCALAR_SAILTO_THRU/2.0; //i.e. probably through a piece of island - update 04-10-24
	if(SameSign(px * dx, pz * dz) && !SameSignPairs(px, pz, dx, dz)) time *= TIMESCALAR_SAILTO_THRU/2.0; //i.e. probably through center of island, so double again. 04-10-24
	//if hostile and we have higher class ship
	if(iRealismMode>0 && SeaAI_GetRelation(GetMainCharacterIndex(), iCharacterIndex) == RELATION_ENEMY && GetCharacterShipClass(GetMainCharacter()) < GetCharacterShipClass(GetCharacter(iCharacterIndex)))
	{
		//then sailto char will flee
		aref eship; makearef(eship, Characters[iCharacterIndex].ship);
		float speedratio = GetTimeToSailDist(eship, dist, angle) / GetTimeToSailDist(arship, dist, angle); // now checks for other ship sailing same dist. was, stf(arship.speedmult) / stf(stchar.ship.speedmult);
		// NOTE: EVENTUALLY ADD ANGLE CHECK FOR RIGTYPE.
		if(speedratio < SAILTO_MIN_SPEEDRATIO && CheckAttribute(stchar, "after_1st_sailto") == true) // KK
		{
			Logit(TranslateString("","Enemy ship will outpace us! Can't use sail-to. You must sail manually."));
			PlaySound("interface\knock.wav");
			return;
		}
		if (!CheckAttribute(stchar, "after_1st_sailto")) stchar.after_1st_sailto = true; // KK
		if (speedratio != 0.0) speedratio = stf(1.0 / speedratio); else speedratio = 5.0; // 04-10-25 bugfix
		//if(speedratio < 1.0) speedratio = clampf(speedratio * 2.0);
		/*else*/ if(speedratio > 5.0) speedratio = 5.0; // caps at 5 times as long.
		time = makeint(makefloat(time) * speedratio);
	}
	pchar.seatime = sti(pchar.seatime) + makeint(makefloat(time) / makefloat(TIMESCALAR_SEA)); // because sailto has its own timescale above
	pchar.sailtostring = TranslateString("","Sail to") + " " + GetMyShipNameShow(stchar) + " " + XI_ConvertString("takes") + " " + MakeTimeString(time); // KK
	// NK <--
	SeaAI_SailToCreateFader();
	//LanguageCloseFile(tmpLangFileID);
}

void AISea_ReturnFromAbordage()
{
	MoveSeaToLayers(SEA_EXECUTE,SEA_REALIZE);
	MoveWeatherToLayers(SEA_EXECUTE,SEA_REALIZE);

	LayerFreeze(REALIZE,true);
	LayerFreeze(EXECUTE,true);

	LayerFreeze(SEA_EXECUTE,false);
	LayerFreeze(SEA_REALIZE,false);

	Sea.MaxSeaHeight = 50.0;

}

void SeaAI_SwapShipsAttributes(ref refMyCharacter, ref refEnemyCharacter)
{
	int		curshipnum;
	aref	arShipMy, arShipEnemy;
	object	oTmp;

// KK -->
	if (CheckAttribute(refMyCharacter, "curshipnum")) {
		curshipnum = sti(refMyCharacter.curshipnum);
		refMyCharacter.curshipnum = refEnemyCharacter.curshipnum;
		refEnemyCharacter.curshipnum = curshipnum;
		Ships[curshipnum] = sti(refEnemyCharacter.index);
		Ships[sti(refMyCharacter.curshipnum)] = sti(refMyCharacter.index);
	} else {
		refMyCharacter.curshipnum = sti(refEnemyCharacter.curshipnum);
		Ships[sti(refMyCharacter.curshipnum)] = sti(refMyCharacter.curshipnum);
		DeleteAttribute(refEnemyCharacter, "curshipnum");
	}
// <-- KK

	makearef(arShipMy,refMyCharacter.Ship);
	makearef(arShipEnemy,refEnemyCharacter.Ship);

	CopyAttributes(&oTmp,arShipMy);
	DeleteAttribute(arShipMy,"");
	CopyAttributes(arShipMy,arShipEnemy);
	DeleteAttribute(arShipEnemy,"");
	CopyAttributes(arShipEnemy,&oTmp);
}

bool SeaAI_SwapShipWithCompanion(ref refMyCharacter, ref refEnemyCharacter)
{
	if (!IsEntity(AISea)) return false;
	SendMessage(&AISea, "laa", AI_MESSAGE_SWAP_SHIPS, refMyCharacter, refEnemyCharacter);
	UpdateRelations();
	return true;
}

bool SeaAI_SwapShipAfterAbordage(ref refMyCharacter, ref refEnemyCharacter)
{
	if (bSeaActive)
	{
		SendMessage(&AISea, "laa", AI_MESSAGE_SWAP_SHIPS, refMyCharacter, refEnemyCharacter);
		refMyCharacter.Flags.DoRefresh = true; // KK
		UpdateRelations();
	}
	return true;
}

void SeaAI_SetCompanionEnemy(ref rCharacter)
{
	ref mchref = GetMainCharacter();
	int		iCharacterIndex = sti(rCharacter.index);
	string	sGroupName = "cmpenemy_" + rCharacter.index;

	// KK: Companion Mutiny -->
	bool bPlayerCompanion;
	int iNation = LotHostileNation(PERSONAL_NATION);
	int nflag, ntex;
	if (bShipMutiny)
	{
		sGroupName = MUTINY_GROUP;

		bPlayerCompanion = true;
		if (!GetRemovable   (rCharacter))									bPlayerCompanion = false;
		if (sti(GetAttribute(rCharacter, "CompanionEnemyEnable")) == true)	bPlayerCompanion = false;
		if (bPlayerCompanion || GetNationRelation(sti(mchref.nation), sti(rCharacter.nation)) != RELATION_ENEMY)
		{
			rCharacter.recognized = true; // PB: Have these ships always hostile, regardless of flag
			rCharacter.nation = iNation;  // PB: Maintain original allegiance if possible
			// PB: Simplied flags use -->
			nflag = GetPirateFlag(mchref, &ntex);
			if (nflag < 3) // To prevent Jack Sparrow flag in random encounters
			{
				rCharacter.Flags.Pirate = nflag + 1;
				rCharacter.Flags.Pirate.texture = ntex;
			}
			else
			{
				rCharacter.Flags.Pirate = nflag - 1;
				rCharacter.Flags.Pirate.texture = ntex;
			}
			// PB: Simplied flags use <--
			rCharacter.Flags.DoRefresh = true;
		}
		if (IsPassenger(rCharacter)) RemovePassenger(mchref, rCharacter);
	}
	// KK: Companion Mutiny <--

	RemoveCharacterCompanion(GetMainCharacter(), rCharacter);
	LAi_SetImmortal(rCharacter, false); // PB: Ensure your enemy isn't immortal!

	Group_DelCharacter(rCharacter.SeaAI.Group.Name, rCharacter.id);

	rCharacter.SeaAI.Group.Name = sGroupName;
	Group_AddCharacter(sGroupName, rCharacter.id);
	if (bShipMutiny == false || Group_GetCharactersNum(sGroupName) == 1) Group_SetGroupCommander(sGroupName, rCharacter.id); // KK

	SendMessage(&AISea, "la", AI_MESSAGE_SET_COMPANION_ENEMY, rCharacter);

	Group_SetTaskAttack(sGroupName, PLAYER_GROUP, true);
	Group_DeleteAtEnd(sGroupName);

//	SetCharacterRelationBoth(iCharacterIndex, GetMainCharacterIndex(), RELATION_ENEMY); // PB: Is already done by Group_SetTaskAttack

	Event("eSwitchPerks", "l", iCharacterIndex);
	Event("eSwitchPerks", "l", GetMainCharacterIndex());

	Event(SHIP_UPDATE_PARAMETERS, "lf", iCharacterIndex, 1.0);				// Parameters
	Event(SHIP_UPDATE_PARAMETERS, "lf", GetMainCharacterIndex(), 1.0);		// Parameters

	RefreshBattleInterface(true);
}

bool SeaAI_SetOfficer2ShipAfterAbordage(ref refMyCharacter, ref refEnemyCharacter)
{
	int iMyCharacterIndex = sti(refMyCharacter.index);
	if (bSeaActive)
	{
		Group_DelCharacter(refEnemyCharacter.SeaAI.Group.Name, refEnemyCharacter.id);
		SendMessage(&AISea, "laa", AI_MESSAGE_SET_OFFICER_2_SHIP, refMyCharacter, refEnemyCharacter);
		Event("eSwitchPerks", "l", iMyCharacterIndex);
		Event(SHIP_UPDATE_PARAMETERS, "lf", iMyCharacterIndex, 1.0);		// Parameters
		refMyCharacter.Flags.DoRefresh = true; // KK
		Group_AddCharacter(PLAYER_GROUP, refMyCharacter.id); // KK
		UpdateRelations();
	}
	return true;
}

int SeaAI_GetRelation(int iCharacterIndex1, int iCharacterIndex2)
{
	int iRelation = RELATION_NEUTRAL;
	if (bSeaActive)
	{
		SendMessage(&AISea, "laae", AI_MESSAGE_GET_RELATION, &Characters[iCharacterIndex1], &Characters[iCharacterIndex2], &iRelation);
		return iRelation;
	}
	return GetRelation(iCharacterIndex1, iCharacterIndex2);
}

void UpdateRelations()
{
	if (bSeaActive)
	{
		SendMessage(&AISea, "l", AI_MESSAGE_UPDATE_RELATIONS);
	}
}
