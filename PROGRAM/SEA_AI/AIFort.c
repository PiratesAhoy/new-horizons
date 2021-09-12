#include "sail_msg.h"

#define		MAX_FORTS						16
#define		MIN_CANNON_DAMAGE_DISTANCE		20.0

object		AIFort;
object		Forts[MAX_FORTS];
object		FortsBlots[MAX_FORTS];
int			iNumForts = 0;
//int			FortsIdx[MAX_FORTS]; // NK 05-07-19

void DeleteFortEnvironment()
{
	if (isEntity(&AIFort)) { DeleteClass(&AIFort); }
	for (int i=0; i<iNumForts; i++)
	{
		DeleteClass(&Forts[i]);
		DeleteClass(&FortsBlots[i]);
	}
	iNumForts = 0;
	for(i = 0; i < MAX_FORTS; i++) { Forts[i].fortcmdridx = -1; } // NK 05-07-20 // KK
}

void CreateFortEnvironment()
{
	iNumForts = 0;
	for(int i = 0; i < MAX_FORTS; i++) { Forts[i].fortcmdridx = -1; } // KK

	SetEventHandler(FORT_CANNON_DAMAGE, "Fort_CannonDamage", 0);
	SetEventHandler(FORT_CREATE, "Fort_CreateEvent", 0);
}

int Fort_FindCharacter(string sLocationID, string sLocationGroup, string sLocationLocator)
{
	for (int i=0; i<CHARACTERS_QUANTITY; i++) // NK 05-04-05 we assume not fantom.
	{
		if (GetMainCharacterIndex() == i) continue; // KK
		if (Characters[i].location == sLocationID)
		{
			if (Characters[i].location.group == sLocationGroup)
			{
				if (Characters[i].location.locator == sLocationLocator)
				{
					return i;
				}
			}
		}
	}
	return -1;
}

int Fort_GetDeadDays(ref rCharacter)
{
	int		iDYear = sti(rCharacter.Fort.DieTime.Year);
	int		iDMonth = sti(rCharacter.Fort.DieTime.Month);
	int		iDDay = sti(rCharacter.Fort.DieTime.Day);
	float	fTime = stf(rCharacter.Fort.DieTime.Time);

	return GetPastTime("day", iDYear, iDMonth, iDDay, fTime, GetDataYear(), GetDataMonth(), GetDataDay(), GetTime());
}

void Fort_Login(int iIslandIndex)
{
	// search fort's in current island
	ref rIsland = GetIslandByIndex(iIslandIndex);
	aref arReload; makearef(arReload,rIsland.reload);
	int iNumReloads = GetAttributesNum(arReload);
	for (int i=0; i<iNumReloads; i++)
	{
		aref arLocator = GetAttributeN(arReload,i);
		ReloadProgressUpdate();
		if (CheckAttribute(arLocator,"fort"))
		{
			if (!CheckAttribute(arLocator,"fort.model") || arLocator.fort.model == "")
			{
				Trace("Island.id = " + rIsland.id + ", and reload." + GetAttributeName(arLocator) + ", doesn't have fort.model value.");
				continue;
			}
			CreateEntity(&Forts[iNumForts], "MODELR");
			string sFortModel = rIsland.filespath.models + "\" + arLocator.fort.model;
			SendMessage(&Forts[iNumForts], "ls", MSG_MODEL_SET_LIGHT_PATH, GetLightingPath());
			SendMessage(&Forts[iNumForts], "ls", MSG_MODEL_LOAD_GEO, sFortModel);
			//20180715
			SendMessage(&Island, "li", MSG_ISLAND_ADD_FORT,  &Forts[iNumForts]);
			//Boyer change
			LayerAddObject(SEA_EXECUTE, &Forts[iNumForts], 10001);
			//LayerAddObject(SEA_REALIZE, &Forts[iNumForts], 10000);
			LayerAddObject("fort_cannon_trace", &Forts[iNumForts], 1);
			SendMessage(SeaLighter, "ssi", "AddModel", arLocator.fort.model, &Forts[iNumForts]);
			iNumForts++;

			int iFortCharacter = Fort_FindCharacter(rIsland.id, "reload", arLocator.name);
			if (iFortCharacter < 0)
			{
				Trace("FortLogin: Can't find character for fort: '" + arLocator.name + "', on island with id: '" + rIsland.id + "'");
				continue;
			}
			Forts[iNumForts - 1].fortcmdridx = iFortCharacter; // NK 05-07-19 // KK
			if (isEntity(&AIFort) == 0)
			{
				CreateEntity(&AIFort, "AIFort");
				LayerAddObject(SEA_EXECUTE, &AIFort, 2);
				LayerAddObject(SEA_REALIZE, &AIFort, -1);
			}
			// Add fort to AIFort
			ref rCharacter = GetCharacter(iFortCharacter);
			// NK -->
			ref PChar = GetMainCharacter();
			if(sti(rCharacter.rank) < sti(PChar.rank) || !CheckAttribute(rCharacter,"completeinit")) //Levis added this check for first setup
			{
				if(DEBUG_EXPERIENCE>0) TraceAndLog("Fort_Login: Set officer type for " + GetMySimpleName(rCharacter));
				rCharacter.quest.officertype = OFFIC_TYPE_CAPNAVY;
				LAi_Create_Officer(0, &rCharacter);
			}
			// NK <--

			int iFortMode = FORT_NORMAL;
			if (CheckAttribute(rCharacter, "Fort.Mode"))
			{
				iFortMode = sti(rCharacter.Fort.Mode);
			}

			bool	bFortRessurect = false;
			int		iDeadDays = 0;
			switch (iFortMode)
			{
				case FORT_NORMAL:
				break;
				case FORT_ABORDAGE:
					iDeadDays = Fort_GetDeadDays(rCharacter);
					if (iDeadDays >= 3) { bFortRessurect = true; }
				break;
				case FORT_DEAD:
					iDeadDays = Fort_GetDeadDays(rCharacter);
					if (iDeadDays >= 7) { bFortRessurect = true; }
				break;
			}

			/*if (iDeadDays > 0)
			{
				// NK - rCharacter.Ship.Crew.Quantity = iDeadDays * 200 + rand(100);
			}*/

			if (bFortRessurect)
			{
				SetFortCharacterCaptured(rCharacter, false);
				if(CheckAttribute(rCharacter,"town")) rCharacter.nation = GetTownNation(rCharacter.town); // KK
				DeleteAttribute(rCharacter, "Fort.Cannons.Damaged"); // KK
				iFortMode = FORT_NORMAL;
				// NK - rCharacter.Ship.Crew.Quantity = 900 + rand(600);
			}
			if(CheckAttribute(rCharacter,"town")) TownDistributeTroops(rCharacter.town); // NK 04-09-20

			rCharacter.Fort.Mode = iFortMode;
			rCharacter.Fort.PlayerDamage = 0.0;								// player damage

			Event("eSwitchPerks", "l", iFortCharacter);							// Perks
			Ship_UpdateTmpSkills(rCharacter);

			Fort_CheckAttributes(rCharacter);

			AIFort.MinCannonDamageDistance = MIN_CANNON_DAMAGE_DISTANCE;		// in meters
			rCharacter.Ship.Crew.MinRatio = 1.0;
			rCharacter.Ship.Name = arLocator.label; // KK arLocator.fortname;
			rCharacter.Ship.Type = SHIP_FORT_NAME; // PS
			SetCharacterGoods(rCharacter, GOOD_BOMBS, 34000);
			rCharacter.Ship.Cannons.Charge.Type = GOOD_BOMBS; // KK
			rCharacter.Fort.Cannons.Charge.Type = GOOD_BOMBS; // KK

			// ADDING GUNPOWDER TO THE FORT // added by MAXIMUS [gunpowder mod] -->
			if (CANNONPOWDER_MOD) {// TIH --> mod toggle 7-7-06
				int qunpowderQty = sti(34000 + rand(10000));
				SetCharacterGoods(rCharacter,GOOD_GUNPOWDER,qunpowderQty);
			}// TIH <-- mod toggle
			// ADDING GUNPOWDER TO THE FORT // added by MAXIMUS [gunpowder mod] <--

			// create fort blot
			CreateEntity(&FortsBlots[iNumForts - 1], "blots");
			SendMessage(&FortsBlots[iNumForts - 1], "lia", MSG_BLOTS_SETMODEL, &Forts[iNumForts - 1], rCharacter);
			LayerAddObject(SEA_EXECUTE, &Forts[iNumForts], 10001);
			LayerAddObject(SEA_REALIZE, &Forts[iNumForts], 10001);

			SendMessage(&AIFort, "laaaii", AI_MESSAGE_ADD_FORT, rIsland, arLocator, rCharacter, &Forts[iNumForts-1], &FortsBlots[iNumForts-1]);
			// flags
			SetFortFlag(&Forts[iNumForts - 1]); // install flag on fort // KK

			//Update the contriblist and skill multipliers and do auto level up for NPC's
			InitAutoSkillsSystem(rCharacter, true); //Levis, the check for autoskill will happen later.
			if(CheckAttribute(rCharacter,"ContribList")) DeleteAttribute(rCharacter,"ContribList")); //Levis refresh contriblist on login

			ReloadProgressUpdate();
		}
	}
}

void Fort_CreateEvent()
{
	int		iCannonsNum;
	aref	rCharacter;

	rCharacter = GetEventData();
	iCannonsNum = GetEventData();

	rCharacter.Fort.Cannons.Quantity = iCannonsNum;

	rCharacter.Ship.HP = iCannonsNum * 100;
	rCharacter.Fort.HP = rCharacter.Ship.HP;
}

int Fort_GetCannonsQuantity(ref rFortCharacter)
{
	if (!CheckAttribute(rFortCharacter, "Fort.Cannons.Quantity")) {
// KK -->
		int quantity = 0;
		if (CheckAttribute(rFortCharacter, "Fort.Cannons.Type.1.Quantity")) quantity += sti(rFortCharacter.Fort.Cannons.Type.1.Quantity);
		if (CheckAttribute(rFortCharacter, "Fort.Cannons.Type.2.Quantity")) quantity += sti(rFortCharacter.Fort.Cannons.Type.2.Quantity);
		if (CheckAttribute(rFortCharacter, "Fort.Cannons.Type.3.Quantity")) quantity += sti(rFortCharacter.Fort.Cannons.Type.3.Quantity);//PW added for crash in JLB engine
		return quantity;
// <-- KK
	}
	return sti(rFortCharacter.Fort.Cannons.Quantity);
}

// KK -->
int Fort_GetDamagedCannonsQuantity(ref rFortCharacter)
{
	if (!CheckAttribute(rFortCharacter, "Fort.Cannons.Damaged.Quantity")) return 0;
	return sti(rFortCharacter.Fort.Cannons.Damaged.Quantity);
}
// <-- KK

// added by MAXIMUS [gunpowder mod] -->
int Fort_GetGunpowderQuantity(ref rFortCharacter)
{
	if (CANNONPOWDER_MOD) {// TIH --> mod toggle 7-7-06
		if (!CheckAttribute(rFortCharacter, "Fort.Cannons.Quantity")) { return 0; }
		return sti(GetCargoGoods(rFortCharacter, GOOD_GUNPOWDER));
	} else {
		return 0;
	}// TIH <-- mod toggle
}
// added by MAXIMUS [gunpowder mod] <--

float Fort_CannonDamage()
{
	float x, y, z;
	aref aFortLabel;
	ref rBallCharacter, rFortCharacter, rCannon, rBall;
	int iNumAllCannons, iNumDamagedCannons, iBallCharacterIndex, iFortCharacterIndex;
	int iExp, iCompanionQuantity, iFortMode, iRelation, iCrew;
	float fDistance, fDamage, fDistanceMul, fCannonDamageMultiply;
	float fHullDamage, fDamagePiece, fCurPlayerDamage;
	bool bImmortal = false;

	iBallCharacterIndex = GetEventData();
	iFortCharacterIndex = GetEventData();
	aFortLabel = GetEventData();
	iNumAllCannons = GetEventData();
	iNumDamagedCannons = GetEventData();
	x = GetEventData();
	y = GetEventData();
	z = GetEventData();
	fDistance = GetEventData();	// distance to cannon
	fDamage = GetEventData();	// current cannon damage 0.0% .. 100.0%

	if (iBallCharacterIndex == iFortCharacterIndex) { return fDamage; }

	rBallCharacter = GetCharacter(iBallCharacterIndex);
	rFortCharacter = GetCharacter(iFortCharacterIndex);

	rFortCharacter.Fort.Cannons.Damaged.Quantity = iNumDamagedCannons; // KK

	iCompanionQuantity = GetCompanionQuantity(rBallCharacter);

	iFortMode = sti(rFortCharacter.Fort.Mode);
	if (iFortMode != FORT_NORMAL) { return fDamage; }

	fDistanceMul = pow(0.035, fDistance / MIN_CANNON_DAMAGE_DISTANCE);

	rCannon = GetCannonByType(sti(rBallCharacter.Ship.Cannons.Type));
	fCannonDamageMultiply = stf(rCannon.DamageMultiply) * fDistanceMul;

	rBall = GetGoodByType(sti(AIBalls.CurrentBallType));

	//CreateParticleSystem("blast",x,y,z,0.0,0.0,0.0,0);

// KK -->
	fHullDamage = stf(rBall.DamageHull) * fCannonDamageMultiply * 0.4;
// edited by MAXIMUS [was divide by zero] -->
	/*if (GetTownNumForts(rFortCharacter.town) > 0)
		fCrewDamage *= (0.01 * (stf(rFortCharacter.Ship.Crew.Quantity) / makefloat(GetTownSize(rFortCharacter.town) * TOWN_TROOPS_SCALAR / GetTownNumForts(rFortCharacter.town)))); // 04-09-22
	else
		fCrewDamage *= (0.01 * (stf(rFortCharacter.Ship.Crew.Quantity) / makefloat(GetTownSize(rFortCharacter.town) * TOWN_TROOPS_SCALAR)));*/ // 04-09-22
// edited by MAXIMUS [was divide by zero] <--
// <-- KK

	rFortCharacter.Ship.HP = makeint((1.0 - MakeFloat(iNumDamagedCannons) / MakeFloat(iNumAllCannons)) * stf(rFortCharacter.Fort.HP));

	fDamagePiece = fHullDamage + (frnd() - 0.5) * fHullDamage * 0.4;
	fDamage = fDamage + fDamagePiece;

	if (iBallCharacterIndex == GetMainCharacterIndex())
	{
		iRelation = SeaAI_GetRelation(iFortCharacterIndex, iBallCharacterIndex);
		if (iRelation != RELATION_ENEMY)
		{
			fCurPlayerDamage = stf(rFortCharacter.Fort.PlayerDamage);

			if (iRelation == RELATION_FRIEND)	{ fCurPlayerDamage = fCurPlayerDamage + fDamagePiece * 0.8; }
			if (iRelation == RELATION_NEUTRAL)	{ fCurPlayerDamage = fCurPlayerDamage + fDamagePiece * 0.5; }

			if (fCurPlayerDamage >= 100.0)
			{
				SetCharacterRelationBoth(iBallCharacterIndex, iFortCharacterIndex, RELATION_ENEMY);
				AttackRMRelation(GetMainCharacter(), sti(rFortCharacter.Nation)); // RM - SetNationRelation2MainCharacter(sti(rFortCharacter.Nation), RELATION_ENEMY);
				UpdateRelations();
			}

			rFortCharacter.Fort.PlayerDamage = fCurPlayerDamage;
		}
	}

	if (fDamage >= 100.0)
	{
		bImmortal = LAi_IsImmortal(rFortCharacter);

		Play3DSound("fort_cann_explode", x, y, z);
		CreateBlast(x, y, z);
		CreateParticleSystem("blast_inv", x, y, z, 0.0, 0.0, 0.0, 0);
		CreateParticleSystem("blast", x, y, z, 0.0, 0.0, 0.0, 0);

// KK -->
		if (!bImmortal) {
			iNumDamagedCannons++;
			fDamage = 100.0;

			switch (rand(1))
			{
				case 0:
					CreateParticleSystem("fort_fire", x, y, z, -1.57, 0.0, 0.0, 0);
					CreateParticleSystem("fort_smoke", x, y, z, -1.57, 0.0, 0.0, 0);
				break;
				case 1:
					CreateParticleSystem("fort_fire", x, y, z, -1.57, 0.0, 0.0, 0);
					CreateParticleSystem("fort_gray_smoke", x, y, z, -1.57, 0.0, 0.0, 0);
				break;
			}

			iCrew = makeint(CalculateTownFortCrewQuantity(rFortCharacter) * (1.0 - (MakeFloat(iNumDamagedCannons) / MakeFloat(2 * iNumAllCannons)))) + rand(10) - 5;
			if (iCrew < sti(rFortCharacter.Ship.Crew.Quantity)) rFortCharacter.Ship.Crew.Quantity = iCrew;
			if (sti(rFortCharacter.Ship.Crew.Quantity) < 10) rFortCharacter.Ship.Crew.Quantity = 10;
			//if (iBallCharacterIndex == GetMainCharacterIndex()) Log_SetStringToLog(rFortCharacter.Ship.Name + " " + LanguageConvertString(iSeaSectionLang, "Fort_cannon"));

			iExp = MakeInt(1000 / iCompanionQuantity);
			if(AUTO_SKILL_SYSTEM)
				AddCharacterExpChar(rBallCharacter, "Cannons", iExp);
			else
				AddCharacterExp(rBallCharacter, iExp);
		} else {
			fDamage = 0.0;
		}
// <-- KK
	}

	if (iNumDamagedCannons > 0.9 * iNumAllCannons) Fort_SetAbordageMode(rBallCharacter, rFortCharacter); // KK

	return fDamage;
}

void Fort_SetAbordageMode(ref rKillerCharacter, ref rFortCharacter)
{
	// open for abordage
	rFortCharacter.Fort.Mode = FORT_ABORDAGE;

	// data of frot die
	rFortCharacter.Fort.DieTime.Year = GetDataYear();
	rFortCharacter.Fort.DieTime.Month = GetDataMonth();
	rFortCharacter.Fort.DieTime.Day = GetDataDay();
	rFortCharacter.Fort.DieTime.Time = GetTime();

	Event(FORT_DESTROYED, "l", sti(rFortCharacter.index));
	int iExp = 20000;
	// NK -->
	if (CheckAttribute(rFortCharacter,"rank")) iExp = makeint(sqrt(sti(rFortCharacter.rank)) * 60.0) * 100;
	if(AUTO_SKILL_SYSTEM) {
		AddPartyExpChar(rKillerCharacter, "Leadership", makeint(iExp/4));
		AddPartyExpChar(rKillerCharacter, "Cannons", makeint(iExp/4));
		AddPartyExpChar(rKillerCharacter, "Grappling", makeint(iExp/4));
		AddPartyExpChar(rKillerCharacter, "Sneak", makeint(iExp/4));
	} else {
		AddPartyExp(rKillerCharacter, iExp);
	}
	// NK <--

	// Fort destroy log
	Log_SetStringToLog(rFortCharacter.Ship.Name + " " + LanguageConvertString(iSeaSectionLang, "Fort_destroy"));
}

void Fort_SetCharacter(ref rCharacter, string sIslandID, string sLocationGroup, string sLocationLocator)
{
	int iCharacterIndex = Fort_FindCharacter(sIslandID, sLocationGroup, sLocationLocator);
	if (iCharacterIndex != -1)
	{
		ChangeCharacterAddress(&Characters[iCharacterIndex], "None", "");
	}

	ChangeCharacterAddressGroup(rCharacter, sIslandID, sLocationGroup, sLocationLocator);

	rCharacter.Ship.Type = SHIP_FORT_NAME;

	Fort_CheckAttributes(rCharacter);
}

void Fort_CheckAttributes(ref rCharacter)
{
	// KNB -->
	if(USE_REAL_CANNONS)
	{
		if (!CheckAttribute(rCharacter, "Ship.Cannons.Type")) { rCharacter.Ship.Cannons.Type = CANNON_TYPE_LONG_LBS42; }

		if (!CheckAttribute(rCharacter, "Ship.Cannons.Charge.Type")) { rCharacter.Ship.Cannons.Charge.Type = GOOD_BOMBS; }
		if (!CheckAttribute(rCharacter, "Fort.Cannons.Type.1")) { rCharacter.Fort.Cannons.Type.1 = CANNON_TYPE_LONG_LBS42; }
		if (!CheckAttribute(rCharacter, "Fort.Cannons.Type.2")) { rCharacter.Fort.Cannons.Type.2 = CANNON_TYPE_CARRONADE_LBS68; }
		if (!CheckAttribute(rCharacter, "Fort.Cannons.Type.3")) { rCharacter.Fort.Cannons.Type.3 = CANNON_TYPE_CARRONADE_LBS68; }//PW added for crash in JLB engine
	}
	// KNB <--
	else
	{
		if (!CheckAttribute(rCharacter, "Ship.Cannons.Type")) { rCharacter.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS24; }

		if (!CheckAttribute(rCharacter, "Ship.Cannons.Charge.Type")) { rCharacter.Ship.Cannons.Charge.Type = GOOD_BOMBS; }
		if (!CheckAttribute(rCharacter, "Fort.Cannons.Type.1")) { rCharacter.Fort.Cannons.Type.1 = CANNON_TYPE_CULVERINE_LBS24; }
		if (!CheckAttribute(rCharacter, "Fort.Cannons.Type.2")) { rCharacter.Fort.Cannons.Type.2 = CANNON_TYPE_CANNON_LBS32; }
		if (!CheckAttribute(rCharacter, "Fort.Cannons.Type.3")) { rCharacter.Fort.Cannons.Type.3 = CANNON_TYPE_CANNON_LBS32; }//PW added for crash in JLB engine
	}
}
