void DeleteCannonsEnvironment()
{
// KK -->
	ref PChar = GetMainCharacter();
	for (int arc = 0; arc < 4; arc++)
	{
		string quadstr = GetQuadName(arc);
		if (CheckAttribute(PChar, "Ship.Cannons.Borts."+ quadstr + ".fired_time")) DeleteAttribute(PChar, "Ship.Cannons.Borts."+ quadstr + ".fired_time");
		if (CheckAttribute(PChar, "Ship.Cannons.Borts."+ quadstr + ".reload_time")) DeleteAttribute(PChar, "Ship.Cannons.Borts."+ quadstr + ".reload_time");
	}
// <-- KK

	DelEventHandler(CANNON_GET_RECHARGE_TIME, "Cannon_GetRechargeTime");
	DelEventHandler(CANNON_GET_FIRE_TIME, "Cannon_GetFireTime");
	DelEventHandler(CANNON_GET_FIRE_HEIGHT, "Cannon_GetFireHeight");
	DelEventHandler(CANNON_FIRE, "Cannon_FireCannon");
	DelEventHandler(CANNON_UNLOAD, "Cannon_UnloadBall");
	DelEventHandler(CANNON_LOAD, "Cannon_LoadBall");
	DelEventHandler(CANNON_RECALCULATE_PARAMETERS, "Cannon_RecalculateParametersEvent");
}

void CreateCannonsEnvironment()
{
	SetEventHandler(CANNON_GET_RECHARGE_TIME, "Cannon_GetRechargeTime", 0);
	SetEventHandler(CANNON_GET_FIRE_TIME, "Cannon_GetFireTime", 0);
	SetEventHandler(CANNON_GET_FIRE_HEIGHT, "Cannon_GetFireHeight", 0);
	SetEventHandler(CANNON_FIRE, "Cannon_FireCannon", 0);
	SetEventHandler(CANNON_UNLOAD, "Cannon_UnloadBall", 0);
	SetEventHandler(CANNON_LOAD, "Cannon_LoadBall", 0);
	SetEventHandler(CANNON_RECALCULATE_PARAMETERS, "Cannon_RecalculateParametersEvent", 0);
}

bool Cannon_LoadBall()
{
	aref	aCharacter = GetEventData();

	int iBallType = sti(aCharacter.Ship.Cannons.Charge.Type);
	int iNumBalls = GetCargoGoodsSimple(aCharacter, iBallType);

	if (CANNONPOWDER_MOD) {// TIH --> mod toggle 7-7-06
		if (iNumBalls > 0) {
			// added by MAXIMUS [gunpowder mod] -->
			ref rCannon; makeref(rCannon,Cannon[GetCaracterShipCannonsType(aCharacter)]);
			int gunPowderNeeded = 0;
			if(CheckAttribute(rCannon,"gunpowder")) gunPowderNeeded = sti(rCannon.gunpowder);
			int gunPowderQty = GetCargoGoodsSimple(aCharacter, GOOD_GUNPOWDER);

			// TIH --> fix for global failure, only check if we have enough powder for this one ball to load 7-7-06
			if (gunPowderQty >= gunPowderNeeded) {
				AddCharacterGoodsSimple(aCharacter, GOOD_GUNPOWDER, -gunPowderNeeded);
				AddCharacterGoodsSimple(aCharacter, iBallType, -1);

				// do a one time check now for the next ball load to inform user of low gunpowder
				gunPowderQty -= gunPowderNeeded;
				if (gunPowderQty < gunPowderNeeded && aCharacter.Ship.Cannons.Type != CANNON_TYPE_NONECANNON && IsMainCharacter(aCharacter)) {
					Log_SetStringToLog(TranslateString("","Captain, we're out of gunpowder!"));
				}
				return true;
			}
			// TIH <-- fix for global failure
			// added by MAXIMUS [gunpowder mod] <--
		}
	} else {
		// normal way to handle it
		if(iNumBalls > 0)
		{
			AddCharacterGoodsSimple(aCharacter, iBallType, -1);
			return true;
		}
	}// TIH <-- mod toggle

	return false;
}

int GetCargoGoodsSimple(aref aCharacter, int iGood)
{
	string sGoodName = Goods[iGood].name;
	if(!CheckAttribute(aCharacter,"Ship.Cargo.Goods."+sGoodName)) return 0; // NK
	return sti(aCharacter.Ship.Cargo.Goods.(sGoodName));
}

void SetCharacterGoodsSimple(aref aCharacter, int iGood, int iQuantity)
{
	string sGoodName = Goods[iGood].name;
	aCharacter.Ship.Cargo.Goods.(sGoodName) = iQuantity;

	aCharacter.Ship.Cargo.RecalculateCargoLoad = true;
}

void AddCharacterGoodsSimple(aref aCharacter, int iGood, int iQuantity)
{
	aref arGoods;
	string sGoodName = Goods[iGood].name;
	makearef(arGoods, aCharacter.Ship.Cargo.Goods);
	arGoods.(sGoodName) = sti(arGoods.(sGoodName)) + iQuantity;

	aCharacter.Ship.Cargo.RecalculateCargoLoad = true;
}

void Cannon_UnloadBall()
{
	aref aCharacter = GetEventData();

	if (CANNONPOWDER_MOD) {// TIH --> mod toggle 7-7-06
		// added by MAXIMUS [gunpowder mod] -->
		ref rCannon; makeref(rCannon,Cannon[GetCaracterShipCannonsType(aCharacter)]);
		int gunPowderUsed = 0;
		if(CheckAttribute(rCannon,"gunpowder")) gunPowderUsed = sti(rCannon.gunpowder);
		AddCharacterGoodsSimple(aCharacter, GOOD_GUNPOWDER, gunPowderUsed);
		// added by MAXIMUS [gunpowder mod] <--
	}// TIH <-- mod toggle

	AddCharacterGoodsSimple(aCharacter, sti(aCharacter.Ship.Cannons.Charge.Type), 1);
}

void Cannon_RecalculateParametersEvent()
{
	int iCharacterIndex = GetEventData();
	Cannon_RecalculateParameters(iCharacterIndex);
}

void Cannon_RecalculateParameters(int iCharacterIndex)
{
// KK -->
	if (iCharacterIndex < 0) return;
	ref	rCharacter = GetCharacter(iCharacterIndex);
	if (sti(rCharacter.Ship.Cannons.Type) == CANNON_TYPE_NONECANNON) return;
	if (sti(rCharacter.Ship.Cannons.Type) >= CANNON_TYPES_MAX) { // NK bugfix 04-06
		rCharacter.Ship.Cannons.Type = CANNON_TYPE_NONECANNON;
		return;
	}
// <-- KK

	// NK convert fireang to scalar 05-07-12 -->
	ref	rShip = GetShipByType(GetCharacterShipType(rCharacter));
	aref	arship; makearef(arship, rCharacter.ship);
	ref	rCannon = GetCannonByType(sti(rCharacter.Ship.Cannons.Type));
	ref	rBall = GetGoodByType(sti(rCharacter.Ship.Cannons.Charge.Type));

// KK -->
	float Ball_SpeedV0 = 0.0;
	if (CheckAttribute(rBall, "SpeedV0"))
		Ball_SpeedV0 = stf(rBall.SpeedV0);
	else
		Ball_SpeedV0 = stf(Goods[DEFAULT_CHARGE].SpeedV0);
// <-- KK

	rCharacter.Ship.Cannons.SpeedV0 = stf(rCannon.SpeedV0) * Ball_SpeedV0 * AIShip_isPerksUse(rCharacter.TmpPerks.LongRangeShoot, 1.0, 1.15);
	// assume forward arc, because we can't find out here. Argh.
	rCharacter.Ship.Cannons.FireAngMax = stf(rCannon.FireAngMax) * GetLocalShipAttrib(&arship, &rShip, "Cannons.Borts.cannonf.FireAngMax");
	rCharacter.Ship.Cannons.FireAngMin = stf(rCannon.FireAngMin) * GetLocalShipAttrib(&arship, &rShip, "Cannons.Borts.cannonf.FireAngMin");
	// NK <--
}

float Cannon_GetFireHeight()
{
/*-------- original function from stock game
	aref aCharacter = GetEventData();
	aref aEnemy = GetEventData();

	ref rBallType = GetGoodByType(sti(aCharacter.Ship.Cannons.Charge.Type));
	ref rEnemyShip = GetShipByID(aEnemy.Ship.Type); // PS

	string sBallName = rBallType.Name;

	float Y,DY;
	Y = stf(rEnemyShip.Height.(sBallName).Y);
	DY = stf(rEnemyShip.Height.(sBallName).DY);

	// charge/ship depend
	return (Y + (frnd()-0.5) * DY * 2);
-------------*/

	// boal -->
	aref aCharacter = GetEventData();
	aref aEnemy = GetEventData();

	if(GetCaracterShipCannonsType(aCharacter) == CANNON_TYPE_NONECANNON)// added by MAXIMUS [fix for boats and tartanes] -->
	{ return 0.0; }// TIH added this in as it still helps out

	ref rBallType = GetGoodByType(sti(aCharacter.Ship.Cannons.Charge.Type));
	int eship = GetCharacterShipType(&aEnemy); // PS
	ref rEnemyShip = GetShipByType(eship); // PS

	string sBallName = rBallType.Name;

	float Y, DY;
	Y = stf(rEnemyShip.Height.(sBallName).Y);		// we can probably remove these from ships_init as we're calculating them here
	DY = stf(rEnemyShip.Height.(sBallName).DY);

	// boal new goals -->

	float dist = Ship_GetDistance2D(aCharacter, aEnemy);
	ref   rCannon = GetCannonByType(sti(aCharacter.Ship.Cannons.Type));
	if(!CheckAttribute(rCannon,"FireRange")) return 0.8;// TIH bug fix 7-7-06
	if(dist < 0) // NK 05-04-15 for when dist <0
	{
		dist = stf(rCannon.FireRange);
		trace("AICannon: mychar " + aCharacter.id + ", name " + aCharacter.lastname + ", ship " + aCharacter.ship.type + ", has pos " + aCharacter.ship.pos.x + "::: echar " + aEnemy.id + ", name " + aEnemy.lastname + ", ship " + aCharacter.ship.type + ", has pos " + aEnemy.ship.pos.x);
	}

	// LDH --> adjust cannons firing too low 15Sep06
	string RigType = ""; if (CheckAttribute(rEnemyShip, "RigType")) RigType = rEnemyShip.RigType;
	if (CheckAttribute(aEnemy,"ship.boxsize"))
	{
		float BoxY = stf(aEnemy.ship.boxsize.y);
		switch(sBallName)
		{
			case "Knippels":
				if (HasSubStr("Xeb,", RigType+","))		// we can add additional ships, example: "Xeb,Lug,Tar," Note final comma is necessary
				{
					Y  = BoxY * 35.0 / 100.0;	// aim lower on these ships as they don't carry much sail on top
					DY = BoxY * 10.0 / 100.0;
				}
				else
				{
					Y  = BoxY * 50.0 / 100.0;	// aim halfway up the mast
					DY = BoxY * 20.0 / 100.0;	// Variation of 20% total box size  ( Y plus or minus DY)
				}
				break;

			case "Bombs":
				Y  = BoxY * 6.0 / 100.0;	// aim 6% up the box
				DY = BoxY * 2.0 / 100.0;	// Variation of 2%
				break;

			case "Grapes":
				Y  = BoxY * 5.0 / 100.0;	// aim 5% up the box
				DY = BoxY * 1.0 / 100.0;	// Variation of 1%
				break;

			case "Balls":
				if (dist > 350.0 && stf(aEnemy.ship.SP) > 15.0)		// if firing ball at long range, aim for sails - LDH unless you've shot them up 06Feb09
				{
					Y  = BoxY * 20.0 / 100.0; 	// aim 20% up the box
					DY = BoxY * 10.0 / 100.0;	// Variation of 10%
				}
				else
				{
					Y  = BoxY * 4.0 / 100.0; 	// aim 4% up the box
					DY = BoxY * 1.0 / 100.0;	// Variation of 1%
				}
				break;

			// default case, just in case
			Y  = BoxY * 4.0 / 100.0; 	// aim 4% up the box
			DY = BoxY * 1.0 / 100.0;	// Variation of 1%
		}
//		traceandlog(aCharacter.id + " firing " + sBallName + " at " + aEnemy.id + " Y: " + Y + " DY: " + DY);
//		traceandlog("Ship type " + aEnemy.ship.type + " has boxsize Y " + aEnemy.ship.boxsize.y + " (" + aEnemy.ship.boxsize.z + ")");
	}
	else
	{
		// if we remove Height.Y and Height.DY from the ship_init file, use these as a default
//		if (sBallName == "Knippels")
//		{
//			Y = 15;
//			DY = 5;
//		}
//		else
//		{
//			Y = 1;
//			DY = 1;
//		}
		traceandlog("AICannon: " + aEnemy.id + " with ship type " + aEnemy.ship.type + " has no boxsize!");
	}

	if(eship == SHIP_FORT) // PS
	{
		Y = 30;
		DY = 16;
	}

	float RY = Y + (frnd()-0.5) * DY * 2;	// Y plus or minus DY
	if (sBallName == "Knippels")
	{
		RY = Y + (-1.0 + rand(2)) * DY;		// Shoot only at middle or upper or lower limits, Y-DY, Y, or Y+DY

		float minrange;		// if we're too close, we can't aim as high with chainshot.  Accounts for rolling of ship.
		float RollAngle = GetRollAngle(aCharacter, aEnemy);

		if (USE_REAL_CANNONS)
			minrange = Y / tan(Degree2Radian(5.0) * FIRE_ANGLE_SCALAR_H + RollAngle); // rCannon.FireAngMax is not being set properly so we set it here
		else
			minrange = Y / tan(0.60 * FIRE_ANGLE_SCALAR_H * 0.5 + RollAngle);	// rCannon.FireAngMax IS set properly here, but we're resetting it anyway

		// We don't need as many shots in high range, not much sail there to hit
		if (dist > minrange && RY==Y+DY && !rand(1))
			RY = Y + 0.5*DY;	// half the time aim slightly lower, keeps from shooting over the sails	- LDH 13Feb09
//			RY = Y + (-1.0 + rand(1)) * DY;		// half the time aim medium or low instead

		if (dist < minrange) RY *= (dist / minrange);

		// debug trace, comment out when testing complete
//		string firingarea = ", Firing MEDIUM";
//		if (RY > Y ) firingarea = ", Firing HIGH";
//		if (RY <= Y-DY ) firingarea = ", Firing LOW";
//		if (RY != Y+DY && RY != Y && RY != Y-DY) firingarea += " (-)";
//		traceandlog(aCharacter.id + " target= " +rEnemyShip.rigtype + " dist = " + dist + ", minrange = " + minrange + ", Y = " + Y + " DY: " + DY  + ", RY = " + RY + firingarea);
	}

	if(RY < 0.8) RY = 0.8;

	return RY;
	// boal <--
	// LDH <--
}

// calculate recharge time for cannon
// LDH --> 10Sep06 considerable rewrite for crew losses, the rest is original code, added RELOAD_TIME_MULTIPLIER
float Cannon_GetRechargeTime()
{
	aref	aCharacter = GetEventData();
// KK -->
	string quadstr = "";
	if (IsMainCharacter(aCharacter) == true && CheckAttribute(aCharacter, "GetCannonsReloadTime") ==  true && aCharacter.GetCannonsReloadTime == "") {
		if (CheckAttribute(aCharacter, "GetCannonsReloadTime.quad")) quadstr = aCharacter.GetCannonsReloadTime.quad;
	}
// <-- KK
	ref		rCannon = GetCannonByType(sti(aCharacter.Ship.Cannons.Type));
	float	fCannonSkill = stf(aCharacter.TmpSkill.Cannons);	// 0.1 to 1.0
	if (!CheckAttribute(rCannon, "ReloadTime"))
	{
		string CannonType = GetCannonName(sti(aCharacter.Ship.Cannons.Type));
		if (CannonType != "No Cannons")	trace("Cannon " + CannonType + " has no reloadTime!");	// LDH - don't need trace if no cannons
		return 20.0;	// LDH - changed from 1.0 so a real cannon will have a reasonable reload time, just in case
	} // NK 05-07-18 fix for "No Cannons"

	// Get standard reload time
	// LDH longer reload times 10Sep06
	float	fReloadTime = sti(rCannon.ReloadTime) * RELOAD_TIME_MULTIPLIER;	// reload time in seconds

	// Adjust for perks
	float fMultiply = AIShip_isPerksUse(aCharacter.TmpPerks.FastReload, 1.0, 0.8);		// 20% faster for fast reload perk OR...
	fMultiply = AIShip_isPerksUse(aCharacter.TmpPerks.ImmediateReload, fMultiply, 0.5);	// 50% faster for immediate reload perk

	// Adjust for cannon skill
	fMultiply *= (1.0 - fCannonSkill * 0.5);	// 5% faster for each cannon skill level

	if (aCharacter.ship.type == SHIP_FORT_NAME)	// Forts don't need crew restrictions or morale, just perks and cannon skill
	{
		return fMultiply * fReloadTime;
	}

	// Adjust for morale
	float CrewMorale = MORALE_NORMAL;
	if(CheckAttribute(aCharacter,"Ship.Crew.Morale")) CrewMorale = sti(aCharacter.Ship.Crew.Morale);
	fMultiply *= (1.0 + (1.0 - CrewMorale / MORALE_NORMAL) / 5.0);	 		// +/- 20% based on morale

	// Adjust for crew losses
	float CrewPerGun = stf(rCannon.caliber);
	if (rCannon.type == CANNON_NAME_LONG)
		CrewPerGun = CrewPerGun / 2.0;	// 12 pounder takes 6 crew, for example
	else
		CrewPerGun = CrewPerGun / 6.0;	// carronades take fewer crew and are normally twice the caliber of the long guns they replace
		// Note that if the player doesn't have USE_REAL_CANNONS set, the CrewPerGun is divided by 6 as well
	CrewPerGun = fclamp(1.0, 10.0, CrewPerGun);		// gun crew no less than 1 and no more than 10

	int CanQty = GetCannonCurQuantity(&aCharacter);		// LDH crew adjusted cannon quantity, not all cannons will fire - 12May09
	float CrewRequired = CrewPerGun * CanQty;
	CrewRequired = CrewRequired / 2.0;		// We're only loading one broadside at a time.  We can adjust this later if needed.

	int CrewQuantity  = GetCrewQuantity(aCharacter);
	if(iRealismMode>0)
	{
		int MinSailCrew = GetCharacterShipHP(aCharacter)/100;	// crew needed for sailing, intentionally not using mininum crew here
		if (MinSailCrew >= 100000/100) MinSailCrew = 100;		// Cursed ships are a special case
		CrewQuantity -= MinSailCrew;
	}
	if (CrewQuantity < CrewPerGun) CrewQuantity = CrewPerGun;		// detail one gun crew from the MinSailCrew

	if (CrewRequired > CrewQuantity)
	{
//		if (CrewQuantity > CrewPerGun)		// avoids division by zero as well
//		{
			fReloadTime *= (CrewRequired / CrewQuantity);	// half the required crew takes twice as long to load
//		}
//		else
//		{
//			fReloadTime *= (CrewRequired / CrewPerGun);		// detail one gun crew from the MinSailCrew
//		}
	}
	if (fReloadTime > 600.0) fReloadTime = 600.0;	// cap it at 10 minutes, will be adjusted below

//KB - Tuning Ships - Bronze cannons
	// Factor in cannon skill, perks and morale calculated above
	float  kbreturnvalue = fMultiply * fReloadTime;
	// LDH skill is already factored in.  If you want to make it faster, make the skill multiplier higher in original adujstment - 12Mayh09
//	float kbreturnvalue = fMultiply * (fReloadTime - fCannonSkill * (fReloadTime / 2.0));	// skill already factored in - 12May09
//KB if ( sti(aCharacter.index) == 0 ) {Trace("KB - Reload before " + kbreturnvalue);}

	aref temparef;
	int testtune=0;
	makearef(temparef,aCharacter.ship);
	if (CheckAttribute(temparef,"tune")) {
		testtune = 1;
		makearef(temparef,aCharacter.ship.tune);
		if(CheckAttribute(temparef,"bcannons")) {
			if (sti(aCharacter.ship.tune.bcannons.on) == 1 ) {
				kbreturnvalue = kbreturnvalue - kbreturnvalue * makefloat(BCRELOAD) / 100.0;
			}
		}
	}
//KB if ( sti(aCharacter.index) == 0 ) {Trace("KB - Reload after " + kbreturnvalue);}
// KK -->
	if (quadstr != "") {
		float reload_time = 2.0 + ((1.0 - fCannonSkill) * 2.0) + kbreturnvalue;
		if (quadstr == "any")
			aCharacter.Ship.Cannons.reload_time = reload_time;
		else
			aCharacter.Ship.Cannons.Borts.(quadstr).reload_time = reload_time;
		DeleteAttribute(aCharacter, "GetCannonsReloadTime");
	}
// <-- KK
	return  kbreturnvalue;
}
// LDH <--

// calculate delay before fire
float Cannon_GetFireTime()
{
	aref aCharacter = GetEventData();

	float fCannonSkill = stf(aCharacter.TmpSkill.Cannons);
	float fFireTime = 1.3 - fCannonSkill;
	fFireTime = fFireTime * Bring2RangeNoCheck(3.0, 1.0, 0.0, 1.0, stf(aCharacter.Ship.Crew.MinRatio));
	fFireTime = frnd() * fFireTime * 6.0;
	if(iRealismMode == 0) { fFireTime = fFireTime * ARCADE_MULT_CANNONS; } // NK
	aCharacter.canfiretime = fFireTime; // NK 05-04-18
	return fFireTime;
}

void Cannon_FireCannon()
{
	float fX, fY, fZ, fSpeedV0, fDirAng, fHeightAng, fCannonDirAng;

	aref aCharacter = GetEventData();
	fX = GetEventData();
	fY = GetEventData();
	fZ = GetEventData();
	fSpeedV0 = GetEventData();
	fDirAng = GetEventData();
	fHeightAng = GetEventData();
	fCannonDirAng = GetEventData();

	Ball_AddBall(aCharacter, fX, fY, fZ, fSpeedV0, fDirAng, fHeightAng, fCannonDirAng);
	DeleteAttribute(aCharacter,"ship.changedammo"); // NK 04-09-15
	aCharacter.seatime.lastfired = GetSeaTime(); // NK 04-09-16, to set time when last fired/reloaded
}

float GetRollAngle(ref mchr, ref echr)
{
	float X = stf(mchr.ship.pos.x) - stf(echr.ship.pos.x);
	float Y = stf(mchr.ship.pos.z) - stf(echr.ship.pos.z);
	float Pitch = stf(mchr.ship.ang.x);
	float Roll = stf(mchr.ship.ang.z);
	int Quad = GetCannonQuadrant(clampangle(atan2(X, Y) - (stf(mchr.ship.ang.y) + PI)));
	float RollAngle = 0.0;
	switch(Quad)
	{
	case 0:		// front
		RollAngle = -Pitch;		// Pitch increases rolling to front
		break;
	case 1:		// right
		RollAngle = Roll;		// Roll increases rolling to left
		break;
	case 2:		// back
		RollAngle = Pitch;
		break;
	case 3:		// left
		RollAngle = -Roll;
		break;
	}
//	float Angle1 = Radian2Degree(RollAngle); if (Angle1 > 180.0) Angle1 -= 360;				// testing only
//	if (mchr.id == "Blaze") traceandlog("Quadrant " + Quad + ", Roll Angle = " + Angle1);	// testing only
	return RollAngle;
}

int GetCannonQuadrant(float Dir)
{
	int rc = makeint(clampangle(Dir)/PId2+0.5);	// round to the nearest 90 degrees
	if (rc < 4) return rc;
	return 0;
}

// KK -->
void PlayGunReadySound(int arc)
{
	switch (arc)
	{
		case 0: PlaySound("#GunReadyF");   break;
		case 1: PlaySound("#GunReadyR");   break;
		case 2: PlaySound("#GunReadyB");   break;
		case 3: PlaySound("#GunReadyL");   break;
		case 4: PlaySound("#GunReady");    break;
//		        PlaySound("#GunNotReady"); break;	// PB: Temporary solution to prevent this from playing ALL the time
	}
}

void CancelAllGunReadySounds()
{
	ref pchar = GetMainCharacter();
	if (CheckAttribute(pchar, "Ship.Cannons.fired_time")) DeleteAttribute(pchar, "Ship.Cannons.fired_time");
	if (CheckAttribute(pchar, "Ship.Cannons.reload_time")) DeleteAttribute(pchar, "Ship.Cannons.reload_time");
	if (CheckAttribute(pchar, "Ship.Cannons.DoFireRequest")) DeleteAttribute(pchar, "Ship.Cannons.DoFireRequest");
	for (int arc = 0; arc < 4; arc++)
	{
		string quadstr = GetQuadName(arc);
		if (CheckAttribute(pchar, "Ship.Cannons.Borts." + quadstr + ".fired_time")) DeleteAttribute(pchar, "Ship.Cannons.Borts."+ quadstr + ".fired_time");
		if (CheckAttribute(pchar, "Ship.Cannons.Borts." + quadstr + ".reload_time")) DeleteAttribute(pchar, "Ship.Cannons.Borts."+ quadstr + ".reload_time");
	}
}
// <-- KK
