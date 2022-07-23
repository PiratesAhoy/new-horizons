object	Sail, Rope, Flag, Vant;
// KK -->
object Pennant, MerchantFlag, MerchantPennant, FortFlag;
object PirateFlag[PIRATEFLAGS_TEXTURES_QUANTITY], PiratePennant[PIRATEFLAGS_TEXTURES_QUANTITY];
object PersonalFlag[PERSONALFLAGS_TEXTURES_QUANTITY], PersonalPennant[PERSONALFLAGS_TEXTURES_QUANTITY];
// <-- KK

#event_handler("proc_ship_adddelayedcumxp","proc_ship_adddelayedcumxp"); //Levis

// NK 05-03-21 moved max ships, two min_distance defines, all
// ammo/morale/mast/etc defines to BS.h

bool	bAbordageShipCanBe = false;
int		iAbordageShipEnemyCharacter;

bool	bNoDamage2Us = false;
bool	bCanEnterToLand = false;
bool	bCanEnterToFort = false; // KK
aref	arIslandReload = &NullCharacter; // KK //MAXIMUS
string	sIslandLocator;
string	sIslandID;
int		iShipPriority = 31;

int		iNumShips = 0;
int		Ships[MAX_SHIPS_ON_SEA];
object	ShipStats[MAX_SHIPS_ON_SEA]; // NK for BI stats in PRS 05-04-15
object	NearShips[MAX_SHIPS_ON_SEA]; // NK for finding near ships; 05-04-22. 05-06-27 change to array.

int ShipModelrList[MAX_SHIPS_ON_SEA]; // KK

bool bShipMutiny = false; // KK

#define SHIP_DETONATE_SMALL		"ShipDetonateSmall"

// KK -->
void CreateFlagEnvironment()
{
	ref chr;
	int i, shipsqty, ntexture;
	int iPriority = iShipPriority + 4;
	string sid;
	int locidx = FindLoadedLocation();
	int iPeriod = GetCurrentPeriod();
	bool hasPennant = iPeriod >= GetPeriodFromYear(makeint(PENNANTS_MIN_YEAR));
	bool hasMerchantFlag = iPeriod >= GetPeriodFromYear(makeint(MERCHANT_FLAGS_MIN_YEAR));

	if (locidx < 0)
		shipsqty = iNumShips;
	else
		shipsqty = locNumShips;

	if (hasMerchantFlag) {
		for (i = 0; i < shipsqty; i++)
		{
			if (locidx < 0) {
				if (Ships[i] < 0) continue;
				chr = GetCharacter(Ships[i]);
			} else {
				if (iShips[i] < 0) continue;
				chr = GetCharacter(iShips[i]);
			}
			if (IsShipMerchant(chr) && !IsEntity(&MerchantFlag)) {
				CreateEntity(&MerchantFlag, "Flag");
				MerchantFlag.texture = "flags\merflg" + (iPeriod + 1) + ".tga"
				LayerAddObject(sCurrentSeaExecute, &MerchantFlag, iPriority);
				LayerAddObject(sCurrentSeaRealize, &MerchantFlag, iPriority);
				LayerAddObject(SEA_REFLECTION, &MerchantFlag, 3);
				iPriority++;

				if (hasPennant) {
					CreateEntity(&MerchantPennant, "Flag");
					MerchantPennant.texture = "flags\merpnt" + (iPeriod + 1) + ".tga"
					LayerAddObject(sCurrentSeaExecute, &MerchantPennant, iPriority);
					LayerAddObject(sCurrentSeaRealize, &MerchantPennant, iPriority);
					LayerAddObject(SEA_REFLECTION, &MerchantPennant, 3);
					iPriority++;
				}
			}
		}
	}

	for (i = 0; i < shipsqty; i++)
	{
		if (locidx < 0) {
			if (Ships[i] < 0) continue;
			chr = GetCharacter(Ships[i]);
		} else {
			if (iShips[i] < 0) continue;
			chr = GetCharacter(iShips[i]);
		}
		if (sti(chr.nation) != PIRATE) continue;
		GetPirateFlag(chr, &ntexture);
		if (!IsEntity(&PirateFlag[makeint(ntexture)])) { // PB: Add 'makeint' everywhere to avoid error logs
			CreateEntity(&PirateFlag[makeint(ntexture)], "Flag");
			PirateFlag[makeint(ntexture)].texture = "flags\pirflg" + (ntexture + 1) + ".tga"
			LayerAddObject(sCurrentSeaExecute, &PirateFlag[makeint(ntexture)], iPriority);
			LayerAddObject(sCurrentSeaRealize, &PirateFlag[makeint(ntexture)], iPriority);
			LayerAddObject(SEA_REFLECTION,   &PirateFlag[makeint(ntexture)], 3);
			iPriority++;

			if (hasPennant) {
				CreateEntity(&PiratePennant[makeint(ntexture)], "Flag");
				PiratePennant[makeint(ntexture)].texture = "flags\pirpnt" + (ntexture + 1) + ".tga"
				LayerAddObject(sCurrentSeaExecute, &PiratePennant[makeint(ntexture)], iPriority);
				LayerAddObject(sCurrentSeaRealize, &PiratePennant[makeint(ntexture)], iPriority);
				LayerAddObject(SEA_REFLECTION,   &PiratePennant[makeint(ntexture)], 3);
				iPriority++;
			}
		}
	}

	for (i = 0; i < shipsqty; i++)
	{
		if (locidx < 0) {
			if (Ships[i] < 0) continue;
			chr = GetCharacter(Ships[i]);
		} else {
			if (iShips[i] < 0) continue;
			chr = GetCharacter(iShips[i]);
		}
		if (sti(chr.nation) != PRIVATEER_NATION && sti(chr.nation) != PERSONAL_NATION) continue; // PB: Other characters might have personal nation too!
		GetPersonalFlag(chr, &ntexture);
		if (!IsEntity(&PersonalFlag[makeint(ntexture)])) {
			CreateEntity(&PersonalFlag[makeint(ntexture)], "Flag");
			PersonalFlag[makeint(ntexture)].texture = "flags\perflg" + (ntexture + 1) + ".tga"
			LayerAddObject(sCurrentSeaExecute, &PersonalFlag[makeint(ntexture)], iPriority);
			LayerAddObject(sCurrentSeaRealize, &PersonalFlag[makeint(ntexture)], iPriority);
			LayerAddObject(SEA_REFLECTION,   &PersonalFlag[makeint(ntexture)], 3);
			iPriority++;

			if (hasPennant) {
				CreateEntity(&PersonalPennant[makeint(ntexture)], "Flag");
				PersonalPennant[makeint(ntexture)].texture = "flags\perpnt" + (ntexture + 1) + ".tga"
				LayerAddObject(sCurrentSeaExecute, &PersonalPennant[makeint(ntexture)], iPriority);
				LayerAddObject(sCurrentSeaRealize, &PersonalPennant[makeint(ntexture)], iPriority);
				LayerAddObject(SEA_REFLECTION,   &PersonalPennant[makeint(ntexture)], 3);
				iPriority++;
			}
		}
	}
}

void DeleteFlagEnvironment()
{
	int i;

	DeleteClass(&Flag);
	if (IsEntity(&Pennant)) DeleteClass(&Pennant);
	DeleteClass(&MerchantFlag);
	if (IsEntity(&MerchantPennant)) DeleteClass(&MerchantPennant);
	for (i = 0; i < PIRATEFLAGS_TEXTURES_QUANTITY; i++)
	{
		if (IsEntity(&PirateFlag[i])) DeleteClass(&PirateFlag[i]);
		if (IsEntity(&PiratePennant[i])) DeleteClass(&PiratePennant[i]);
	}
	for (i = 0; i < PERSONALFLAGS_TEXTURES_QUANTITY; i++)
	{
		if (IsEntity(&PersonalFlag[i])) DeleteClass(&PersonalFlag[i]);
		if (IsEntity(&PersonalPennant[i])) DeleteClass(&PersonalPennant[i]);
	}
	DeleteClass(&FortFlag);
}

void CreateRiggingEnvironment()
{
	int ntexture;
	int iPriority = iShipPriority + 1;
	int iPeriod = GetCurrentPeriod();
	bool hasPennant = iPeriod >= GetPeriodFromYear(makeint(PENNANTS_MIN_YEAR));
	string sid;
	ref mchr = GetMainCharacter();

	CreateEntity(&Sail, "Sail");
	LayerAddObject(sCurrentSeaExecute, &Sail, iPriority);
	LayerAddObject(sCurrentSeaRealize, &Sail, iPriority);
	LayerAddObject(SAILS_TRACE, &Sail, 10);
	LayerAddObject(SEA_REFLECTION, &Sail, 3);
	Sail.MinSpeed = 0.05;
	iPriority++;

	CreateEntity(&Rope, "Rope");
	LayerAddObject(sCurrentSeaExecute, &Rope, iPriority);
	LayerAddObject(sCurrentSeaRealize, &Rope, iPriority);
	iPriority++;

	CreateEntity(&Vant, "Vant");
	LayerAddObject(sCurrentSeaExecute, &Vant, iPriority);
	LayerAddObject(sCurrentSeaRealize, &Vant, iPriority);
	iPriority++;

	CreateEntity(&Flag, "Flag");
	Flag.texture = "flags\shpflg" + (iPeriod + 1) + ".tga"
	LayerAddObject(sCurrentSeaExecute, &Flag, iPriority);
	LayerAddObject(sCurrentSeaRealize, &Flag, iPriority);
	LayerAddObject(SEA_REFLECTION, &Flag, 3);
	iPriority++;

	if (hasPennant) {
		CreateEntity(&Pennant, "Flag");
		Pennant.texture = "flags\shppnt" + (iPeriod + 1) + ".tga"
		LayerAddObject(sCurrentSeaExecute, &Pennant, iPriority);
		LayerAddObject(sCurrentSeaRealize, &Pennant, iPriority);
		LayerAddObject(SEA_REFLECTION, &Pennant, 3);
		iPriority++;
	}

	GetPirateFlag(mchr, &ntexture);
	CreateEntity(&PirateFlag[ntexture], "Flag");
	PirateFlag[ntexture].texture = "flags\pirflg" + (ntexture + 1) + ".tga"
	LayerAddObject(sCurrentSeaExecute, &PirateFlag[ntexture], iPriority);
	LayerAddObject(sCurrentSeaRealize, &PirateFlag[ntexture], iPriority);
	LayerAddObject(SEA_REFLECTION, &PirateFlag[ntexture], 3);
	iPriority++;

	if (hasPennant) {
		CreateEntity(&PiratePennant[ntexture], "Flag");
		PiratePennant[ntexture].texture = "flags\pirpnt" + (ntexture + 1) + ".tga"
		LayerAddObject(sCurrentSeaExecute, &PiratePennant[ntexture], iPriority);
		LayerAddObject(sCurrentSeaRealize, &PiratePennant[ntexture], iPriority);
		LayerAddObject(SEA_REFLECTION, &PiratePennant[ntexture], 3);
		iPriority++;
	}

	GetPersonalFlag(mchr, &ntexture);
	CreateEntity(&PersonalFlag[ntexture], "Flag");
	PersonalFlag[ntexture].texture = "flags\perflg" + (ntexture + 1) + ".tga"
	LayerAddObject(sCurrentSeaExecute, &PersonalFlag[ntexture], iPriority);
	LayerAddObject(sCurrentSeaRealize, &PersonalFlag[ntexture], iPriority);
	LayerAddObject(SEA_REFLECTION, &PersonalFlag[ntexture], 3);
	iPriority++;

	if (hasPennant) {
		CreateEntity(&PersonalPennant[ntexture], "Flag");
		PersonalPennant[ntexture].texture = "flags\perpnt" + (ntexture + 1) + ".tga"
		LayerAddObject(sCurrentSeaExecute, &PersonalPennant[ntexture], iPriority);
		LayerAddObject(sCurrentSeaRealize, &PersonalPennant[ntexture], iPriority);
		LayerAddObject(SEA_REFLECTION, &PersonalPennant[ntexture], 3);
		iPriority++;
	}

	CreateEntity(&FortFlag, "Flag");
	FortFlag.texture = "flags\frtflg" + (iPeriod + 1) + ".tga"
	LayerAddObject(sCurrentSeaExecute, &FortFlag, iPriority);
	LayerAddObject(sCurrentSeaRealize, &FortFlag, iPriority);
	LayerAddObject(SEA_REFLECTION, &FortFlag, 3);
	iPriority++;

	iNumShips = 0;
}

void DeleteRiggingEnvironment()
{
	DeleteClass(&Sail);
	DeleteClass(&Rope);
	DeleteClass(&Vant);

	DeleteFlagEnvironment();
}
// <-- KK

void DeleteShipEnvironment()
{
	DeleteRiggingEnvironment();

	DelEventHandler(SEA_GET_LAYERS, "SeaAI_GetLayers");
	DelEventHandler(SHIP_NOT_ENOUGH_BALLS, "Ship_NotEnoughBalls");
	DelEventHandler(SHIP_GET_CURRENT_BALLS_NUM, "Ship_GetCurrentBallsNum");
	DelEventHandler(SHIP_SHIP2ISLAND_COLLISION, "Ship_Ship2IslandCollision");
	DelEventHandler(SHIP_SHIP2SHIP_COLLISION, "Ship_Ship2ShipCollision");
	DelEventHandler(SHIP_SAIL_DAMAGE, "Ship_SailDamage");
	DelEventHandler(SHIP_FIRE_DAMAGE, "Ship_FireDamage");
	DelEventHandler(SHIP_CHECK_SITUATION, "Ship_CheckSituation");
	DelEventHandler(SHIP_TO_STRAND, "Ship_OnStrand");
	DelEventHandler(SHIP_TO_STRAND_NEXT, "Ship_OnStrandNext");
	DelEventHandler(SHIP_DEAD, "Ship_OnDead");
	DelEventHandler(SHIP_UPDATE_PARAMETERS, "Ship_UpdateParameters");
	DelEventHandler(SHIP_CREATE, "Ship_OnCreate");
	DelEventHandler(SHIP_CHANGE_CHARGE, "Ship_ChangeChargeEvent");
	DelEventHandler(SHIP_HULL_HIT, "Ship_HullHitEvent");
	DelEventHandler(SHIP_CHECK_RELOAD_ENABLE, "Ship_CheckMainCharacter");
	DelEventHandler(SHIP_FIRE_ACTION, "Ship_FireAction");
	DelEventHandler(SHIP_GET_BORT_FIRE_DELTA, "Ship_GetBortFireDelta");
	DelEventHandler(SHIP_DETONATE_SMALL, "Ship_DetonateSmall");
	DelEventHandler(SHIP_ACTIVATE_FIRE_PLACE, "Ship_ActivateFirePlace");
	DelEventHandler(WHR_LIGHTNING, "Ship_Lightning");
	DelEventHandler("TornadoDamage", "Ship_TornadoDamage");
	DelEventHandler(SHIP_BRANDER_DETONATE, "Ship_BranderDetonate");
	DelEventHandler(SHIP_MAST_DAMAGE, "Ship_MastDamage");
	DelEventHandler("eSwitchPerks", "Ship_UpdatePerks");

	// scan characters for delete snd id's
}

void CreateShipEnvironment()
{
	bAbordageFortCanBe = false;
	bAbordageShipCanBe = false;
	bAbordageTownCanBe = false; // KK
	bCanEnterToLand = false;
	bCanEnterToFort = false; // KK
	sIslandLocator = "";
	sIslandID = "";

// KK -->
	for (int i = 0; i < MAX_SHIPS_ON_SEA; i++)
	{
		ShipModelrList[i] = -1;
	}
// <-- KK

	CreateRiggingEnvironment();

	SetEventHandler(SEA_GET_LAYERS, "SeaAI_GetLayers", 0);
	SetEventHandler(SHIP_NOT_ENOUGH_BALLS, "Ship_NotEnoughBalls", 0);
	SetEventHandler(SHIP_GET_CURRENT_BALLS_NUM, "Ship_GetCurrentBallsNum", 0);
	SetEventHandler(SHIP_SHIP2ISLAND_COLLISION, "Ship_Ship2IslandCollision", 0);
	SetEventHandler(SHIP_SHIP2SHIP_COLLISION, "Ship_Ship2ShipCollision", 0);
	SetEventHandler(SHIP_SAIL_DAMAGE, "Ship_SailDamage", 0);
	SetEventHandler(SHIP_FIRE_DAMAGE, "Ship_FireDamage", 0);
	SetEventHandler(SHIP_CHECK_SITUATION, "Ship_CheckSituation", 0);
	SetEventHandler(SHIP_TO_STRAND, "Ship_OnStrand", 0);
	SetEventHandler(SHIP_TO_STRAND_NEXT, "Ship_OnStrandNext", 0);
	SetEventHandler(SHIP_DEAD, "Ship_OnDead", 0);
	SetEventHandler(SHIP_UPDATE_PARAMETERS, "Ship_UpdateParameters", 0);
	SetEventHandler(SHIP_CREATE, "Ship_OnCreate", 0);
	SetEventHandler(SHIP_CHANGE_CHARGE, "Ship_ChangeChargeEvent", 0);
	SetEventHandler(SHIP_HULL_HIT, "Ship_HullHitEvent", 0);
	SetEventHandler(SHIP_CHECK_RELOAD_ENABLE, "Ship_CheckMainCharacter", 0);
	SetEventHandler(SHIP_FIRE_ACTION, "Ship_FireAction", 0);
	SetEventHandler(SHIP_GET_BORT_FIRE_DELTA, "Ship_GetBortFireDelta", 0);
	SetEventHandler(SHIP_DETONATE_SMALL, "Ship_DetonateSmall", 0);
	SetEventHandler(SHIP_ACTIVATE_FIRE_PLACE, "Ship_ActivateFirePlace", 0);
	SetEventHandler(WHR_LIGHTNING, "Ship_Lightning", 0);
	SetEventHandler(SHIP_GET_RUNAWAY_POINT, "Ship_GetRunAwayPoint", 0);
	SetEventHandler("TornadoDamage", "Ship_TornadoDamage", 0);
	SetEventHandler(SHIP_BRANDER_DETONATE, "Ship_BranderDetonate", 0);
	SetEventHandler(SHIP_MAST_DAMAGE, "Ship_MastDamage", 0);
	SetEventHandler("eSwitchPerks", "Ship_UpdatePerks", 0);
}

float Ship_GetBortFireDelta()
{
	aref aCharacter = GetEventData();
	float x = GetEventData();
	float y = GetEventData();
	float z = GetEventData();
	float fDistance = GetDistance2D(x, z, stf(aCharacter.Ship.Pos.x), stf(aCharacter.Ship.Pos.z));
	float fAccuracy = 1.0 - stf(aCharacter.TmpSkill.Accuracy);
	float fRadius1 = fAccuracy * Bring2Range(0.0, 140.0, 0.0, 800.0, fDistance);	// 35 @ 200 for example
	float fRadius = abs(randnorm(100.0, fAccuracy*20.0) - 100.0); // LDH 16Sep06 additional radius calc based on normalized random number
	int Quad = GetCannonQuadrant(clampangle(atan2(stf(aCharacter.ship.pos.x) - x, stf(aCharacter.ship.pos.z) - z) - (stf(aCharacter.ship.ang.y) + PI))); // LDH 27Sep06 make chasers more accurate
	float minRadius = 3.0;
	if (Quad == 0 || Quad == 2) minRadius = 0.0;
	fRadius = fclamp(minRadius, fRadius1, fRadius);
	return fRadius;
}

string Ship_GetGroupID(ref rCharacter)
{
	if(!CheckAttribute(rCharacter,"SeaAI.group.name")) return "none"; // NK bugfix 05-04-22
	return rCharacter.SeaAI.Group.Name;
}

void Ship_FireAction()
{
	// LDH restored 23Jan09
	aref rCharacter = GetEventData();				// we attack this character
	aref rMainGroupCharacter = GetEventData();		// commander character for rCharacter - PB: This isn't actually used anymore
	ref rMainCharacter = GetMainCharacter();
	int iRelation = GetEventData();

// KK -->
	if (!TestRef(rCharacter) || !TestRef(rMainGroupCharacter)) return;
	int iCharacterIndex = sti(rCharacter.index);
	if (iCharacterIndex < 0) return;
	int iMainGroupCharacterIndex = sti(rMainGroupCharacter.index);
	if (iMainGroupCharacterIndex < 0) return;
// <-- KK

	if (iRelation != RELATION_ENEMY)
	{
		if (IsCompanion(rCharacter) && GetAttribute(rCharacter, "CompanionEnemyEnable") == true)	// If companion that can turn hostile
		{
			ChangeCharacterReputation(rMainCharacter, -20);											// Double rep loss compared to ShipMutiny() as you did not give them fair warning with a hostile flag
			SeaAI_SetCompanionEnemy(rCharacter);													// Disconnect companion from our group and set it enemy to us
		}
		else																						// If other ship
		{
			if(CheckAttribute(rCharacter,"surrendered"))											// NK: surrendered ships 05-04-20
			{
				if (sti(rCharacter.surrendered.seatime) + 20 < GetSeaTime())						// 20 second grace period
				{
					ChangeCharacterReputation(rMainCharacter, -15);									// NK: Large rep loss for firing on surrendered ships
				}
			}
			else
			{
				ChangeCharacterReputation(rMainCharacter, -15);										// NK: Large rep loss for firing on friendly ships
				SetGroupHostile(rCharacter, true);													// Have them turn hostile; as you fired first, this is a betrayal
				RefreshBattleInterface(true);														// Update relations and battle interface
			}
		}
	}
}

// Walker -->
float Ship_MastDamage()
{
	int iDamageType = GetEventData();
	int iMastNum = GetEventData();
	float x = GetEventData();
	float y = GetEventData();
	float z = GetEventData();
	float fDamage = GetEventData();
	aref rCharacter = GetEventData();
	rCharacter.seatime.lasthit = GetSeaTime(); // NK 04-09-16, to set time when last hit
	// NK -->
	float hp = GetCharacterShipHP(rCharacter);
	hp = sqrt(sqrt(pow(hp,2.5)))/82.0;
	hp = 1.0/hp;
	float collhp = sqrt(hp);
	ref rBall; makeref(rBall, AIBalls); // KK

	if(!bSeaActive) return makefloat(0);//MAXIMUS

	switch (iDamageType)
	{
		case SHIP_MAST_TOUCH_ISLAND:
			if(!IsMainCharacter(rCharacter)) return 0.0; // PB: Collision damage for player ship only
			fDamage = fDamage + MAST_ISLAND_SCL * collhp;
		break;

		case SHIP_MAST_TOUCH_SHIP:
//			if(!IsMainCharacter(rCharacter)) return 0.0; // PB: Collision damage for player ship only, GR: disabled, let NPC take damage
		//aref rCollideCharacter = GetEventData();
			fDamage = fDamage + MAST_SHIP_SCL * collhp;
		break;

		case SHIP_MAST_TOUCH_BALL:
			//Log_SetStringToLog("Captain, we hit their mast!");
			int iBallType = sti(rBall.CurrentBallType);
			float fMult = 1.0;
			int bidx = -1;
			ref rBallCharacter;
			if(CheckAttribute(rCharacter,"Ship.LastBallCharacter"))
			{
				bidx = sti(rCharacter.Ship.LastBallCharacter);
				if(bidx >= 0)
				{
					rBallCharacter = GetCharacter(bidx);
					if(sti(rBallCharacter.index) != GetMainCharacterIndex() && CheckAttribute(rCharacter,"surrendered")) return fDamage; // NK because AI doesn't respect surrender. 05-04-23
					rBallCharacter.Ship.lasttgt = sti(rCharacter.index); // NK 04-09-22 to see who AI is attacking
					ref rCannon; if(USE_REAL_CANNONS) rCannon = GetCannonByType(CANNON_TYPE_LONG_LBS4); // KNB
					else rCannon = GetCannonByType(CANNON_TYPE_CANNON_LBS12);
					if(CheckAttribute(rBallCharacter,"Ship.Cannons.Type")) {rCannon = GetCannonByType(sti(rBallCharacter.Ship.Cannons.Type)); } // NK bugfix 04-06
					fMult = stf(rCannon.DamageMultiply);
					fMult *= MAST_MULT_SCL;
				} else {
					bidx = -1;
				}
			}

/*			if(USE_REAL_CANNONS)	// Reduce effects of perks	// wasn't included in effects of original Ship Defence perks
			{
				if (sti(GetAttribute(rCharacter, "TmpPerks.Rigging")))		fMult *= 0.85; // -15%
				if (sti(GetAttribute(rCharacter, "TmpPerks.RiggingAdvance")))	fMult *= 0.75; // -25%
			}
			else
			{
				if (sti(GetAttribute(rCharacter, "TmpPerks.Rigging")))		fMult *= 0.8; // -20%
				if (sti(GetAttribute(rCharacter, "TmpPerks.RiggingAdvance")))	fMult *= 0.6; // -40%
			} */

			switch (iBallType)
			{
				case GOOD_BALLS:
					fDamage = fDamage + MAST_BALL_SCL * hp * fMult;
				break;

				case GOOD_GRAPES:
					fDamage = fDamage + MAST_GRAPE_SCL * hp * fMult;
				break;

				case GOOD_KNIPPELS:
					fDamage = fDamage + MAST_CHAIN_SCL * hp * fMult;
				break;

				case GOOD_BOMBS:
					fDamage = fDamage + MAST_BOMB_SCL * hp * fMult;
				break;
			}
// KK --> //KB - Tuning ships - Now hits at masts have a chance of critical hit, higher from chasers, even higher from gchasers. No matter calibers, but yes range
			if (bidx != -1 && iBalltype != GOOD_GRAPES) {  //Grapes can't bring down a mast... never!!!
				float endmastchance = 0.0;
				float mastchance = MASTCRIT / 100;
				if (CheckAttribute(rBall,"quad")) {
					if (rBall.quad == "cannonf") {  //KB It's a chaser
						mastchance = CMASTCRIT/100;
						if (CheckTun(bidx, "gchasers")) mastchance = GCMASTCRIT/100;
						if (CheckTun(bidx, "ltopmasts")) mastchance = mastchance + TMSAILCRIT/100;
					}
				}

				//Checking crit mast fall
				float fShotDistance = Ship_GetDistance2D(rBallCharacter, rCharacter);
				if(fShotDistance <= 0) fShotDistance = 1.0; // NK for when dist < 0 05-04-15
				float exponent = (fShotDistance/100) -1;
				endmastchance = mastchance / pow(2,exponent); // decreasing  with range
				if (iRealismMode == 0 || Ship_GetDistance2D(GetMainCharacter(), rCharacter) < GetVisibilityRange(1)) { // KK: Mast fall can be seen from LONG range
					if ( frnd() < endmastchance ) { // KB - bring down a mast
						//Trace("KB - Tuning - Critical on mast");
						PlaySound("objects\shipcharge\hurrah.wav");
						fDamage = 1.0;
					}
				}
			}
//KB - END Tuning ships // <-- KK
		break;
	}

	fDamage = Clampf(fDamage);

	// if mast fall - play sound
	if (fDamage >= 1.0)
	{
		Play3DSound("mast_fall", x, y, z);
		if(AUTO_SKILL_SYSTEM)
		{
			// LDH divide experience between cannons and accuracy - 27Dec08
			Ship_AddDelayedCumXP(rCharacter, "Cannons", makeint(fDamage*50));
			Ship_AddDelayedCumXP(rCharacter, "Accuracy", makeint(fDamage*50));
		}
	} else {
		if(AUTO_SKILL_SYSTEM)
		{
			// LDH divide experience between cannons and accuracy - 27Dec08
			Ship_AddDelayedCumXP(rCharacter, "Cannons", makeint(fDamage*25));
			Ship_AddDelayedCumXP(rCharacter, "Accuracy", makeint(fDamage*25));
		}
	}

	return fDamage;
}
// Walker <--

// KK -->
void Ship_SetSailState(int iCharacterIndex, int iSailState)
{
	if (iCharacterIndex < 0) return; // bugfix here too
	if (iSailState < 0) iSailState = 0;
	if (iSailState > 2) iSailState = 2;
// NK, Amokachi -->
	ref rCharacter = GetCharacter(iCharacterIndex);
	if (CheckAttribute(rCharacter, "Ship.Sink"))			return;
	if (CheckAttribute(rCharacter, "Ship.Sails.Delay"))		return; // PB
	if (IsMainCharacter(rCharacter)) {
		if (!CheckAttribute(rCharacter, "LastSailState")) rCharacter.LastSailState = iSailState;
		if (iSailState == sti(rCharacter.LastSailState)) return;
		if (actLoadFlag == 0) {
			switch (iSailState)
			{
				case 0:
					Log_SetStringToLog(TranslateString("", "Strike all sail!"));
				break;

				case 1:
					Log_SetStringToLog(TranslateString("", "Battle sails!"));
				break;

				case 2:
					Log_SetStringToLog(TranslateString("", "Make all sail!"));
				break;
			}
			if (ENABLE_EXTRA_SOUNDS == 1) {	// added by KAM after build 11 // KK
				if (sti(rCharacter.LastSailState) > iSailState) {
					PlayStereoSound("#sails_down");
				} else {
					PlayStereoSound("#sails_up");
				}
			}
		}
		if (SAIL_OPERATE_DELAY == 0 || iRealismMode == 0) {
			rCharacter.LastSailState = iSailState;
			DeleteAttribute(rCharacter, "Ship.Sails.Delay"); // PB: Just in case
		} else {
			int morale = MORALE_NORMAL;
			if (CheckAttribute(rCharacter, "Ship.Crew.Morale")) morale = sti(rCharacter.Ship.Crew.Morale);
			rCharacter.Ship.Sails.Delay = SAIL_OPERATE_DELAY + round(makefloat(MORALE_NORMAL - morale) / makefloat(MORALE_NORMAL));
			rCharacter.Ship.Sails.Delay.StartTime = GetSeaTime();
			rCharacter.Ship.Sails.Delay.SailsState = iSailState;
			return;
		}
	}
// NK, Amokachi <--

	float fSailState = makefloat(iSailState) / 2.0;
	fSailState = clampf(fSailState); // NK 05-04-20 bugfix
	SendMessage(&AISea, "laf", AI_MESSAGE_SHIP_SET_SAIL_STATE, rCharacter, fSailState);
}
// <-- KK

// NK add set ship task to group task 05-04-20
int Ship_SetTaskGroupTask(int iTaskPriority, int iCharacterIndex)
{
	// logit("SetTaskGroupTask");
	float x, y, z;
	string target;
	ref chr = GetCharacter(iCharacterIndex);
	ref echr;
	int closetgt, i;
	string gname = Ship_GetGroupID(&chr);
	ref rGroup = Group_FindOrCreateGroup(gname);
	float fAng;
	if(!CheckAttribute(rGroup,"task")) return -1;
	bool bdone = true;
	int task = AITASK_NONE;
	switch(sti(rGroup.task))
	{
		case AITASK_NONE: task = AITASK_NONE; Ship_SetTaskNone(iTaskPriority, iCharacterIndex); break;
		case AITASK_DRIFT: task = AITASK_DRIFT; Ship_SetTaskDrift(iTaskPriority, iCharacterIndex); break;
		case AITASK_ATTACK:
			task = AITASK_ATTACK;
			if(CheckAttribute(rGroup,"target"))
			{
				target = rGroup.target;
				closetgt = FindClosestShipOfGroup(iCharacterIndex, &x, gname);
			}
			else { closetgt = FindClosestShipofRel(iCharacterIndex, &x, RELATION_ENEMY); }

			if(closetgt != -1)
			{
				echr = GetCharacter(closetgt);
				Ship_SetTaskAttack(iTaskPriority, iCharacterIndex, closetgt);

			}
			else bdone = false;
		break;
		case AITASK_MOVE:
			task = AITASK_MOVE;
			if (CheckAttribute(rGroup,"target.pos")) Ship_SetTaskMove(iTaskPriority, iCharacterIndex, stf(rGroup.target.pos.x), stf(rGroup.target.pos.z));	// TIH attribute bug fix Jul11'06
		break;
		case AITASK_RUNAWAY:
			task = AITASK_RUNAWAY;
			Ship_SetTaskRunaway(iTaskPriority, iCharacterIndex);
		break;
		bdone = false;
	}
	if(!bdone)
	{
		task = AITASK_MOVE;
		fAng = frnd() * PIm2;
		Ship_SetTaskMove(iTaskPriority, iCharacterIndex, 10000.0 * sin(fAng) , 10000.0 * cos(fAng));
	}
	return task;
}
// NK <--

void Ship_SetTaskNone(int iTaskPriority, int iCharacterIndex)
{
	ref rCharacter = GetCharacter(iCharacterIndex);
	rCharacter.SeaAI.Task = AITASK_NONE;
}

void Ship_SetTaskBrander(int iTaskPriority, int iCharacterIndex, int iCharacterIndexBranderTo)
{
	ref rCharacter = GetCharacter(iCharacterIndex);
	if (CheckAttribute(rCharacter, "surrendered") == true && sti(rCharacter.surrendered) == 1) return; // LDH
	// PB: Prevent CTDs -->
	if (LAi_IsDead(rCharacter))
	{
		TraceAndLog("Ship_SetTaskBrander ERROR: Please post your compile.log file at piratesahoy.net!");
		Trace("Trying to give task to dead captain:");
		DumpAttributes(rCharacter);
		return;
	}
	// PB: Prevent CTDs <--
	rCharacter.SeaAI.Task = AITASK_BRANDER;
	rCharacter.SeaAI.Task.Target = iCharacterIndexBranderTo;
	SendMessage(&AISea, "lllaa", AI_MESSAGE_SHIP_SET_TASK, AITASK_BRANDER, iTaskPriority, &Characters[iCharacterIndex], &Characters[iCharacterIndexBranderTo]);
}

void Ship_SetTaskMove(int iTaskPriority, int iCharacterIndex, float x, float z)
{
	ref rCharacter = GetCharacter(iCharacterIndex);
	if (CheckAttribute(rCharacter, "surrendered") == true && sti(rCharacter.surrendered) == 1) return; // LDH
	// PB: Prevent CTDs -->
	if (LAi_IsDead(rCharacter))
	{
		TraceAndLog("Ship_SetTaskMove ERROR: Please post your compile.log file at piratesahoy.net!");
		Trace("Trying to give task to dead captain:");
		DumpAttributes(rCharacter);
		return;
	}
	// PB: Prevent CTDs <--
	rCharacter.SeaAI.Task = AITASK_MOVE;
	rCharacter.SeaAI.Task.Target = "";
	rCharacter.SeaAI.Task.Pos.x = x;
	rCharacter.SeaAI.Task.Pos.z = z;
	SendMessage(&AISea, "lllaff", AI_MESSAGE_SHIP_SET_TASK, AITASK_MOVE, iTaskPriority, &Characters[iCharacterIndex], x, z);
}

void Ship_SetTaskRunaway(int iTaskPriority, int iCharacterIndex)
{
	ref rCharacter = GetCharacter(iCharacterIndex);
	if (CheckAttribute(rCharacter, "surrendered") == true && sti(rCharacter.surrendered) == 1) return; // LDH
	// PB: Prevent CTDs -->
	if (LAi_IsDead(rCharacter))
	{
		TraceAndLog("Ship_SetTaskRunaway ERROR: Please post your compile.log file at piratesahoy.net!");
		Trace("Trying to give task to dead captain:");
		DumpAttributes(rCharacter);
		return;
	}
	// PB: Prevent CTDs <--
	rCharacter.SeaAI.Task = AITASK_RUNAWAY;
	rCharacter.SeaAI.Task.Target = "";
	SendMessage(&AISea, "llla", AI_MESSAGE_SHIP_SET_TASK, AITASK_RUNAWAY, iTaskPriority, &Characters[iCharacterIndex]);
}

void Ship_SetTaskAttack(int iTaskPriority, int iCharacterIndex, int iCharacterIndexVictim)
{
	ref rCharacter = GetCharacter(iCharacterIndex);
	if (CheckAttribute(rCharacter,  "surrendered") == true && sti(rCharacter.surrendered)  == 1) return; // LDH
	// PB: Prevent CTDs -->
	if (LAi_IsDead(rCharacter))
	{
		TraceAndLog("Ship_SetTaskAttack ERROR: Please post your compile.log file at piratesahoy.net!");
		Trace("Trying to give task to dead captain:");
		DumpAttributes(rCharacter);
		return;
	}
	// PB: Prevent CTDs <--
	ref rCharacter1 = GetCharacter(iCharacterIndexVictim);
	if (CheckAttribute(rCharacter1, "surrendered") == true && sti(rCharacter1.surrendered) == 1) return; // LDH
	// PB: Prevent CTDs -->
	if (LAi_IsDead(rCharacter))
	{
		TraceAndLog("Ship_SetTaskAttack ERROR: Please post your compile.log file at piratesahoy.net!");
		Trace("Trying to set target to dead captain:");
		DumpAttributes(rCharacter);
		return;
	}
	// PB: Prevent CTDs <--
	rCharacter.SeaAI.Task = AITASK_ATTACK;
	rCharacter.SeaAI.Task.Target = iCharacterIndexVictim;
	SendMessage(&AISea, "lllaa", AI_MESSAGE_SHIP_SET_TASK, AITASK_ATTACK, iTaskPriority, &Characters[iCharacterIndex], &Characters[iCharacterIndexVictim]);
}

void Ship_SetTaskSailTo(int iTaskPriority, int iCharacterIndex, int iCharacterIndexSailTo)
{
	ref rCharacter = GetCharacter(iCharacterIndex);
	if (CheckAttribute(rCharacter, "surrendered") == true && sti(rCharacter.surrendered) == 1) return; // LDH
	// PB: Prevent CTDs -->
	if (LAi_IsDead(rCharacter))
	{
		TraceAndLog("Ship_SetTaskSailTo ERROR: Please post your compile.log file at piratesahoy.net!");
		Trace("Trying to give task to dead captain:");
		DumpAttributes(rCharacter);
		return;
	}
	// PB: Prevent CTDs <--
	rCharacter.SeaAI.Task = AITASK_MOVE;
	rCharacter.SeaAI.Task.Target = iCharacterIndexSailTo;
	SendMessage(&AISea, "lllaa", AI_MESSAGE_SHIP_SET_TASK, AITASK_MOVE, iTaskPriority, &Characters[iCharacterIndex], &Characters[iCharacterIndexSailTo]);
}

void Ship_SetTaskDrift(int iTaskPriority, int iCharacterIndex)
{
	ref rCharacter = GetCharacter(iCharacterIndex);
	if (CheckAttribute(rCharacter, "surrendered") == true && sti(rCharacter.surrendered) == 1) return; // LDH
	// PB: Prevent CTDs -->
	if (LAi_IsDead(rCharacter))
	{
		TraceAndLog("Ship_SetTaskDrift ERROR: Please post your compile.log file at piratesahoy.net!");
		Trace("Trying to give task to dead captain:");
		DumpAttributes(rCharacter);
		return;
	}
	// PB: Prevent CTDs <--
	rCharacter.SeaAI.Task = AITASK_DRIFT;
	rCharacter.SeaAI.Task.Target = "";
	SendMessage(&AISea, "llla", AI_MESSAGE_SHIP_SET_TASK, AITASK_DRIFT, iTaskPriority, &Characters[iCharacterIndex]);
}

void Ship_SetTaskDefendGroup(int iTaskPriority, int iCharacterIndex, string sDefendGroup)
{
	ref rCharacter = GetCharacter(iCharacterIndex);
	if (CheckAttribute(rCharacter, "surrendered") == true && sti(rCharacter.surrendered) == 1) return; // LDH
	// PB: Prevent CTDs -->
	if (LAi_IsDead(rCharacter))
	{
		TraceAndLog("Ship_SetTaskDefendGroup ERROR: Please post your compile.log file at piratesahoy.net!");
		Trace("Trying to give task to dead captain:");
		DumpAttributes(rCharacter);
		return;
	}
	// PB: Prevent CTDs <--
	SendMessage(&AISea, "lllas", AI_MESSAGE_SHIP_SET_TASK, AITASK_DEFEND_GROUP, iTaskPriority, &Characters[iCharacterIndex], sDefendGroup);
}

void Ship_SetTaskDefend(int iTaskPriority, int iCharacterIndex, int iCharacterIndex2Defend)
{
	ref rCharacter = GetCharacter(iCharacterIndex);
	if (CheckAttribute(rCharacter, "surrendered") == true && sti(rCharacter.surrendered) == 1) return; // LDH
	// PB: Prevent CTDs -->
	if (LAi_IsDead(rCharacter))
	{
		TraceAndLog("Ship_SetTaskDefend ERROR: Please post your compile.log file at piratesahoy.net!");
		Trace("Trying to give task to dead captain:");
		DumpAttributes(rCharacter);
		return;
	}
	// PB: Prevent CTDs <--
	rCharacter.SeaAI.Task = AITASK_DEFEND;
	rCharacter.SeaAI.Task.Target = iCharacterIndex2Defend;
	SendMessage(&AISea, "lllaa", AI_MESSAGE_SHIP_SET_TASK, AITASK_DEFEND, iTaskPriority, &Characters[iCharacterIndex], &Characters[iCharacterIndex2Defend]);
}

// LDH -->
// This is the original Ship_DoFire()
void Ship_DoAimedFire()
{
// KK -->
	ref PChar = GetMainCharacter();
	if(CheckAttribute(PChar, "ship.SubmergeDutchman")) return; // PB: Cannot fire while submerged
	PChar.Ship.Cannons.DoFireRequest = true;
// <-- KK

	int bCameraOutside = SeaCameras_isCameraOutside();

	SendMessage(&AISea, "lal", AI_MESSAGE_CANNON_FIRE, PChar, bCameraOutside);

	PostEvent("DoneFireRequest", 250.0); // KK
}

void Ship_DoFire()
{
// KK -->
	ref PChar = GetMainCharacter();
	if(CheckAttribute(PChar, "ship.SubmergeDutchman")) return; // PB: Cannot fire while submerged
	PChar.Ship.Cannons.DoFireRequest = true;
// <-- KK

	int bCameraOutside = SeaCameras_isCameraOutside();

	bCameraOutside = true;

	SendMessage(&AISea, "lal", AI_MESSAGE_CANNON_FIRE, PChar, bCameraOutside);

	PostEvent("DoneFireRequest", 250.0); // KK
}
// LDH <--

// KK -->
#event_handler("DoneFireRequest", "procDoneFireRequest");
void procDoneFireRequest()
{
	ref PChar = GetMainCharacter();
	if (!CheckAttribute(PChar, "Ship.Cannons.DoFireRequest")) return;
	DeleteAttribute(PChar, "Ship.Cannons.DoFireRequest");
	bool bAllGunsLoaded = true;
	if (SeaCameras_isCameraOutside()) {
		for (int arc = 0; arc < 4; arc++)
		{
			string quadstr = GetQuadName(arc);
			if (CheckAttribute(PChar, "Ship.Cannons.Borts." + quadstr + ".fired_time") && CheckAttribute(PChar, "Ship.Cannons.Borts." + quadstr + ".reload_time")) {
				bAllGunsLoaded = false;
				break;
			}
		}
		if (bAllGunsLoaded && CheckAttribute(PChar, "Ship.Cannons.fired_time") && CheckAttribute(PChar, "Ship.Cannons.reload_time")) bAllGunsLoaded = false;
	} else {
		bAllGunsLoaded = false;
	}
	if (!bAllGunsLoaded) PlayGunReadySound(-1);
}
// <-- KK

void Ship_Add2Sea(int iCharacterIndex, bool bFromCoast, string sFantomType)
{
	if (iCharacterIndex<0) return;
	ref rCharacter = GetCharacter(iCharacterIndex);
	if (CharacterIsDead(rCharacter))
	{
		TraceAndLog("Ship_Add2Sea ERROR: Please post your compile.log file at piratesahoy.net!");
		Trace("Trying to log in dead captain:");
		DumpAttributes(rCharacter);
		return;
	}
	aref arCharacter; makearef(arCharacter, Characters[sti(rCharacter.index)]);
	DeleteAttribute(arCharacter,"skillsnatmult"); // NK PRS3 04-09-15 as lookup to speed up national skill mult
	DeleteAttribute(arCharacter,"ship.changedammo"); // NK 04-09-15 clears "we already changed ammo this round" attribute
	DeleteAttribute(arCharacter,"ship.lasttgt"); // NK 04-09-16 clears "we last fired on this char idx" attribute
	DeleteAttribute(arCharacter,"ship.attackpcharset"); // NK 04-09-16 clears "we're already set to attack pchar" attribute
	DeleteAttribute(arCharacter,"seatime"); // NK 04-09-16 deletes seatime tree
	DeleteAttribute(arCharacter,"surrendered"); // NK surrender 05-04-20
	DeleteAttribute(arCharacter,"oldnation");
// KK -->
	DeleteAttribute(arCharacter, "nation.known");
	DeleteAttribute(arCharacter, "unknownShip");
// <-- KK
	if (iCharacterIndex == GetMainCharacterIndex()) { // NK 04-09-16 clears timer attribute, -21 for updatetime
		rCharacter.seatime = 0;
		rCharacter.lastupdateseatime = 0;
	}
	//trace("starting sa2s for " + rCharacter.id + " and prev numships " + iNumShips+ ", did delete attr");

	int iShipType = GetCharacterShipType(rCharacter); // PS
	if (iShipType < 0 || iShipType >= SHIP_TYPES_QUANTITY_WITH_FORT)
	{
		Trace("Character.id = " + rCharacter.id + ", have invalid ship type = " + iShipType + ", and try load to sea");
		//return; // NK 04-09-12 fix so you never crash on bad ship type. -->
		if(!LAi_IsDead(rCharacter))
		{
			if(sti(rCharacter.nation) == PIRATE) rCharacter.fantomtype = "pirate"; //SCREWFACE : PIRATE is a nation - type is "pirate";
			string ftype = "war"; if(CheckAttribute(rCharacter,"fantomtype")) ftype = rCharacter.fantomtype;
			rCharacter.ship.type = GetShipID(Force_GetShipType(GetCharacterShipClass(GetMainCharacter()) - 1, GetCharacterShipClass(GetMainCharacter()) +1, ftype, sti(rCharacter.nation)));
			iShipType = GetCharacterShipType(rCharacter);
			LAi_Create_Officer(0, rCharacter); // NK
			Fantom_SetRandomMoney(rCharacter, ftype);
			Fantom_SetCannons(rCharacter, ftype);
			Fantom_SetSails(rCharacter, ftype);
		}
		// NK <--
	}
	//trace("found ship type");

	if (iCharacterIndex >= FANTOM_CHARACTERS && !CheckAttribute(&rCharacter, "skipsetfantom")) // WM to not do this for fantoms already done.
	{
		SetBaseShipData(rCharacter);
		Ship_SetFantomData(rCharacter);

		Fantom_ClearCargo(rCharacter); // TIH clear out prior slot cargo
		Fantom_SetBalls(rCharacter, sFantomType);
		Fantom_SetGoods(rCharacter, sFantomType);
	}
	//trace("did setfantom stuff");

	rCharacter.TmpPerks.Turn = false;

	CharacterUpdateShipFromBaseShip(iCharacterIndex);
	//trace("updated ship from base");

//	rCharacter.Ship.Ang.y = 0.0;
	rCharacter.Ship.Ang.y = rand(90);
	if(CheckAttribute(rCharacter,"forceshipangle"))
	{
		rCharacter.Ship.Ang.y = rCharacter.forceshipangle;
		DeleteAttribute(rCharacter,"forceshipangle");
	} // NK 05-04-15

	Ship_ClearImpulseStrength(rCharacter);
	//trace("cleared impulse");

	rCharacter.Ship.LastBallCharacter = -1;
	rCharacter.Ship.Speed.z = 0.0;
	rCharacter.Ship.Strand = false;
	rCharacter.Ship.Strand.SndID = SOUND_INVALID_ID;
	rCharacter.Ship.Stopped = false;
	rCharacter.Ship.POS.Mode = SHIP_SAIL;
	if (bFromCoast == false) { rCharacter.Ship.Speed.z = 1.0; }

	Ship_Login(iCharacterIndex);
}

// KK -->
void Ship_Login(int iCharacterIndex)
{
	// logit("Ship_Login");
	if (iCharacterIndex < 0) return;
	ref rCharacter = GetCharacter(iCharacterIndex);
	if (CharacterIsDead(rCharacter))
	{
		TraceAndLog("Ship_Login ERROR: Please post your compile.log file at piratesahoy.net!");
		Trace("Trying to log in dead captain:");
		DumpAttributes(rCharacter);
		return;
	}
	int iShipType = GetCharacterShipType(rCharacter);
	if (iShipType < 0 || iShipType >= SHIP_TYPES_QUANTITY_WITH_FORT) return;
	//trace("set stuff");
	Event("eSwitchPerks", "l", iCharacterIndex);							// Perks
	//trace("perks start");
	Event(SHIP_UPDATE_PARAMETERS, "lf", iCharacterIndex, stf(rCharacter.Ship.Speed.z));		// Parameters
	//trace("started update params");
	ShipModelrList[iNumShips] = GetCurrentModelrNumber();
	CreateEntity(rCharacter, "Ship");
	//trace("created entity");
	SendMessage(&AISea, "liaa", AI_MESSAGE_ADD_SHIP, rCharacter, rCharacter, &ShipsTypes[iShipType]);
	//trace("added ship");
	ReloadProgressUpdate();

	Ships[iNumShips] = iCharacterIndex;
	rCharacter.curshipnum = iNumShips; // NK 05-04-15 to keep track.
	iNumShips++;
	rCharacter.Flags.DoRefresh = true;
	if(!CheckAttribute(rCharacter,"Ship.Crew.Morale")) rCharacter.Ship.Crew.Morale = 45; //MAXIMUS
	rCharacter.seatime.basecrewmorale = rCharacter.Ship.Crew.Morale; // NK 04-09-16 mod morale in combat; this sets the base
	rCharacter.seatime.basecrewquantity = GetCrewQuantity(rCharacter); // ditto but for quantity
	//trace("updated ships[], set basecrew");

	Ship_CannonsFiringCheck(rCharacter, true); // TIH run this so that it can clear any leftover firingnums Nov13'06
	
	//Update the contriblist and skill multipliers and do auto level up for NPC's
	InitAutoSkillsSystem(rCharacter, true); //Levis, the check for autoskill will happen later.
	if(CheckAttribute(rCharacter,"ContribList")) DeleteAttribute(rCharacter,"ContribList")); //Levis refresh contriblist on login
	
	ReloadProgressUpdate();
}
// <-- KK

void Ship_ChangeChargeEvent()
{
// KK -->
	ref rCharacter;
	int iCharacterIndex = GetEventData();
	string	sBallName = GetEventData();
	if (iCharacterIndex < 0) return;
	rCharacter = GetCharacter(iCharacterIndex);

	SendMessage(&AISea, "la", AI_MESSAGE_CANNON_RELOAD, rCharacter);
	rCharacter.Ship.Cannons.Charge = sBallName;
	Cannon_RecalculateParameters(iCharacterIndex);
// <-- KK
	rCharacter.seatime.lastfired = GetSeaTime(); // NK 04-09-16, to set time when last fired/reloaded
}

void Ship_ChangeCharge(ref rCharacter, int iNewChargeType)
{
	if (CANNONPOWDER_MOD) {// TIH --> mod toggle 7-7-06
		// changed by MAXIMUS [gunpowder mod] -->
		ref rCannon; makeref(rCannon,Cannon[GetCaracterShipCannonsType(rCharacter)]);
		int used = 0;
		if(CheckAttribute(rCannon,"gunpowder")) used = sti(rCannon.gunpowder);
		int gunPowderQty = GetCargoGoods(rCharacter, GOOD_GUNPOWDER);

		if( gunPowderQty >= sti(GetCannonArcCurQty(rCharacter, 0))*used ||
			gunPowderQty >= sti(GetCannonArcCurQty(rCharacter, 2))*used )// check front and rear cannons
		{
			// do nothing as powder is A O K (for at least one arc)
		}
		else
		{
			if(rCharacter.Ship.Cannons.Type != CANNON_TYPE_NONECANNON)
			{
				Log_SetStringToLog(TranslateString("","Captain, we're out of gunpowder!"));
			}
			rCharacter.ship.changedammo = false;
			return;// stop this function and return early
		}
	}// TIH <-- mod toggle
	// continue on at this point normally if it hasnt been stopped above

	if (iNewChargeType == -1) return; // KK

	SendMessage(&AISea, "la", AI_MESSAGE_CANNON_RELOAD, &rCharacter); // must be first line in this function
	rCharacter.seatime.lastfired = GetSeaTime(); // NK 04-09-16, to set time when last fired/reloaded

	ref rGood = GetGoodByType(iNewChargeType);
	rCharacter.Ship.Cannons.Charge = rGood.name;
	rCharacter.Ship.Cannons.Charge.Type = iNewChargeType;

	if(!CheckAttribute(rCharacter, "ship.SubmergeDutchman")) // PB: Flying Dutchman
	{
		// Boatswain sounds MOD - Amokachi
		if (ENABLE_EXTRA_SOUNDS == 1) {			// added by KAM after build 11 // KK
			if (IsMainCharacter(rCharacter)) {
				switch (iNewChargeType)
				{
					case GOOD_BALLS:
						PlayStereoSound("#loading_cannonballs");
					break;
					case GOOD_BOMBS:
						PlayStereoSound("#loading_bombs");
					break;
					case GOOD_GRAPES:
						PlayStereoSound("#loading_grapeshot");
					break;
					case GOOD_KNIPPELS:
						PlayStereoSound("#loading_knippels");
					break;
				}
			} else {
				float fX, fY, fZ;
				fX = 0; fY = 0; fZ = 0;
				if(CheckAttribute(rCharacter,"Ship.pos.x")) fX=stf(rCharacter.Ship.pos.x);
				if(CheckAttribute(rCharacter,"Ship.pos.y")) fY=stf(rCharacter.Ship.pos.y);
				if(CheckAttribute(rCharacter,"Ship.pos.z")) fZ=stf(rCharacter.Ship.pos.z);
				switch (iNewChargeType)
				{
					case GOOD_BALLS:
						Play3DSound("#loading_cannonballs", fX, fY, fZ);
					break;
					case GOOD_BOMBS:
						Play3DSound("#loading_bombs", fX, fY, fZ);
					break;
					case GOOD_GRAPES:
						Play3DSound("#loading_grapeshot", fX, fY, fZ);
					break;
					case GOOD_KNIPPELS:
						Play3DSound("#loading_knippels", fX, fY, fZ);
					break;
				}
			}
		}
	}

	Cannon_RecalculateParameters(sti(rCharacter.index));
	rCharacter.ship.changedammo = true; // NK 04-09-15
// KK -->
	if (ENABLE_EXTRA_SOUNDS == 1 && IsMainCharacter(rCharacter) == true) {
		CancelAllGunReadySounds();
		rCharacter.Ship.Cannons.fired_time = GetSeaTime();
		rCharacter.GetCannonsReloadTime = "";
		rCharacter.GetCannonsReloadTime.quad = "any";
		Event("CANNON_GET_RECHARGE_TIME", "i", rCharacter);
	}
// <-- KK
}

void Ship_OnCreate()
{
// KK -->
	int iCharacter = GetEventData();
	if (iCharacter < 0) return;
	if (actLoadFlag == 1) return;
	ref rCharacter = GetCharacter(iCharacter);
// <-- KK
	//Trace("Ship_OnCreate rCharacter = " + rCharacter.id);

	rCharacter.Ship.Speed.z = 0.0;
	rCharacter.Ship.Speed.y = 0.0;
	rCharacter.Ship.Speed.x = 0.0;
}

// NK ship morale
void Ship_CheckMorale(int chridx)
{
//if (chridx && DEBUGINFO) trace("Ship_Checkmorale start, chridx = " + chridx);
	ref rCharacter = GetCharacter(chridx);
//if (chridx && DEBUGINFO) trace("Ship_Checkmorale probe 1");
//if (chridx && DEBUGINFO) trace("Ship_Checkmorale rCharacter.index = " + rCharacter.index);
	if(rCharacter.ship.type == SHIP_FORT_NAME) return; // NK fort check 05-04-20
	if(CheckAttribute(rCharacter,"surrendered")) return; // NK surrender 05-04-20
	int timecheck = CHANGE_MORALE_EVERY / (1 + (chridx != GetMainCharacterIndex())*2); //if not mainchar, divide by 3, since checksit is run once per 3 seconds for other ships.
	int timesincelast = timecheck;
	if(CheckAttribute(rCharacter,"seatime.timesincelast"))
		{ timesincelast = sti(rCharacter.seatime.timesincelast); }

	if(timesincelast < timecheck)
		{ rCharacter.seatime.timesincelast = timesincelast+1; } //increment one and skip; this is to due this once every CHANGE_MORALE_EVERY seconds
	else
	{
		if(!IsCompanion(&rCharacter) && !CheckAttribute(rCharacter,"live")) // added by MAXIMUS [abordage MOD]
		{
			rCharacter.seatime.timesincelast = 0; //reset counter
			float enemydistance = DIST_NOSHIP;
			int targetidx = FindClosestShipofRel(sti(rCharacter.index), &enemydistance, RELATION_ENEMY); // finds nearest hostile ship
			int currenttime = GetSeaTime();
			int lasthit = -1; if(CheckAttribute(rCharacter,"seatime.lasthit")) lasthit = sti(rCharacter.seatime.lasthit); //last time we were hit
			int lastfired = -1; if(CheckAttribute(rCharacter,"seatime.lastfired")) lastfired = sti(rCharacter.seatime.lastfired); // last time we fired or reloaded
			if(!CheckAttribute(rCharacter,"Ship.Crew.Morale")) { rCharacter.Ship.Crew.Morale = 45; }//MAXIMUS
			float tempmorale = stf(rCharacter.ship.crew.morale); if(CheckAttribute(rCharacter,"seatime.tempmorale")) tempmorale = stf(rCharacter.seatime.tempmorale); //i.e. a float morale
			int CrewQuantity = sti(rCharacter.Ship.Crew.Quantity);
			//Logit("Checking morale for the " + rCharacter.ship.name + ", time is " + currenttime + ", current morale is " + fts(tempmorale,2) + ", lht " + lasthit + ", lft " + lastfired);
			if(CheckAttribute(rCharacter,"seatime.lastcrew")) // i.e. have crewmen been killed?
			{
				tempmorale = tempmorale - (stf(rCharacter.seatime.lastcrew) - makefloat(CrewQuantity)) / stf(rCharacter.seatime.basecrewquantity) / CREW_PCT_FOR_MORALE;
				DeleteAttribute(rCharacter,"seatime.lastcrew");
			}
			float combatlevel = COMBATLEVEL_NONE;
			if(enemydistance <= RANGE_TO_ENEMY) combatlevel = COMBATLEVEL_ENEMYHERE;
			if(lastfired != -1) { if((currenttime - lastfired) < TIME_SINCE_GUNS) combatlevel = COMBATLEVEL_GUNS; }
			if(lasthit != -1) { if((currenttime - lasthit) < TIME_SINCE_HIT) combatlevel = COMBATLEVEL_HIT; }
			if(combatlevel == COMBATLEVEL_NONE)
			{
				// return to baseline when not in combat
				if(CheckAttribute(rCharacter,"seatime.basecrewmorale"))
				{
					int basemorale = sti(rCharacter.seatime.basecrewmorale);
					if(makeint(tempmorale) != basemorale)
					{
						if(tempmorale > basemorale) tempmorale -= MORALE_AMT_COMEBACK;
						else tempmorale += MORALE_AMT_COMEBACK;
					}
				}
				else { rCharacter.seatime.basecrewmorale = makeint(tempmorale); } // NK 04-09-16 bugfix if attr not exist.
			}
			else
			{
				//tempmorale -= combatlevel;
				if(tempmorale > 5.0 / combatlevel) { tempmorale -= retmin(COMBATLEVEL_HIT*CHANGE_MORALE_EVERY, combatlevel*2.5); } // now use floors and scalar. 05-04-20
				//Logit("Current combatlevel is " + combatlevel);
			}
			if(CheckAttribute(rCharacter,"seatime.enemydead"))
			{
				tempmorale += stf(rCharacter.seatime.enemydead);
				DeleteAttribute(rCharacter,"seatime.enemydead"); // 04-09-22 fix
			}
			if(tempmorale > MORALE_MAX) tempmorale = MORALE_MAX;
			if(tempmorale < MORALE_MIN) tempmorale = MORALE_MIN;
			//Logit("Morale for " + rCharacter.ship.name + " is " + makeint(tempmorale) + ", change " + (tempmorale - makefloat(sti(rCharacter.ship.crew.morale))));
			rCharacter.ship.crew.morale = makeint(tempmorale);
			rCharacter.seatime.tempmorale = tempmorale;
			//Logit("new morale is " + tempmorale);


			// start surrender checking 05-04-20
			// below also check nosurrender 05-07-06
			if(SURR_GLOBAL_SCL >0 && !IsCompanion(&rCharacter) && targetidx != -1 && lasthit != -1 && !CheckAttribute(&rCharacter, "nosurrender")) // for now comps can't either. Makes life simpler. Also, must be an enemy nearby, and must have been hit.
			{
				float ftmult = 1.0;
				// LDH was using ship's character index as distance - 07Mar09
//				float fdist = DIST_NOSHIP; fdist = FindClosestShipofRel(chridx, &fdist, RELATION_FRIEND);
				float fdist; if (FindClosestShipofRel(chridx, &fdist, RELATION_FRIEND) == -1) fdist = DIST_NOSHIP;	// LDH 07Mar09
				if (CheckAttribute(rCharacter, "fantomtype")) {
					switch(rCharacter.fantomtype)
					{
						case "trade" : ftmult = 1.25; break;
						case "pirate": ftmult = 0.75; break;
					}
				}
				float mrlmod = Bring2Range(SURR_MRL_SCL_MAX, SURR_MRL_SCL_MIN, 0.1, 1.4, stf(rCharacter.TmpSkill.Leadership)+ AIShip_isPerksUse(rCharacter.TmpPerks.IronWill, 0.0, 0.4));
				ref pch = GetMainCharacter();
				//if(CheckAttribute(rCharacter,"lastballcharacter")) { if(sti(rCharacter.lastballcharacter) == GetMainCharacterIndex()) { if(CheckAttribute(pch,"surmult")) ftmult = 99999.9; } }
				ref rGroup = Group_FindOrCreateGroup(Ship_GetGroupID(rCharacter));
				float surmorale = SURR_MAX_MORALE * mrlmod * ftmult;
//if (chridx && DEBUGINFO) trace("Ship_Checkmorale probe 2");
				if (tempmorale > surmorale) {
					// put ship back in group and do group's task.
					if(CheckAttribute(rGroup,"task") && rGroup.task != AITASK_RUNAWAY && CheckAttribute(rCharacter,"SeaAI.task") && rCharacter.SeaAI.task != rGroup.task) { Ship_SetTaskGroupTask(SECONDARY_TASK, chridx); }
					return;
				}
// LDH fix for possible divide by zero crash -->
				float surch = 0.01;
				if (surmorale != 0.01) surch = Bring2Range(0.75, 0.01, 0.01, surmorale, tempmorale);	// original code
// LDH <--
				float HP = GetCurrentShipHP(&rCharacter);
				float HPr = HP / makefloat(GetCharacterShipHP(&rCharacter));
				// LDH HPr was tested against 20 in following lines, should have been 0.2, changed to 0.4 - 07Mar09
				if(surch > 0.25 || HPr < 0.4) Ship_SetTaskRunaway(SECONDARY_TASK, chridx);	// LDH HPr 0.2 - 07Mar09
//TraceAndLog("**** Surr: surch = " + surch + ", fdist = " + fdist + ", enemydist = " + enemydistance);	// LDH test 07Mar09
				if(HPr > 0.4 && fdist <= enemydistance) return; // if friend closer than enemy, no surrender.
				if (enemydistance > 1600.0) return;				// LDH don't surrender if enemy not on radar - 24Mar09
				if(HPr < 0.4) surch *= Bring2Range(6.0 * (1.0 + makefloat(fdist+200 < enemydistance)), 1.25 * (0.5 + makefloat(fdist+200 < enemydistance)/2.0), 0.1, sqrt(20), sqrt(HPr)); // should often surrender when low on HP, but not if a friend is nearer (to pick them up).
				//ref echr = GetCharacter(targetidx);
				float strengthrat = sqrt(FindPowerRatio(chridx));
				float SP = GetSailPercent(rCharacter);
				if(strengthrat > 1.0) { // they're stronger
					if (SP < 40)
						surch *= Bring2Range(5.0, 0.5, 0.1, sqrt(40), sqrt(SP));
					else
						surch *= 0.5;
				}
				surch *= SURR_GLOBAL_SCL; // LDH
				//Trace("SURR: for char " + rCharacter.id + " of ship " + rCharacter.ship.name + " surrender chance is " + round(surch*100.0)+"%");
				if (frnd() < surch) Ship_Surrender(chridx);
			}
		}
	}
	// NK <--
}

void Ship_Surrender(int chridx)
{
	// logit("Ship_Surrender");
	traceif("SURR: Ship_Surrender begin idx: " + chridx);
	ref chr = GetCharacter(chridx);
	string chid = chr.id;
	int i, tmpidx;
	ref pchar = GetMainCharacter();
	int pchridx = GetMainCharacterIndex();
	ref schr;
	float tmped, origed;
	string ogroup = Ship_GetGroupID(&chr);
	aref tmpattr;
	string tmpstr;

	// TIH --> code to determine if they were released from a boarding freely Aug31'06
	// set a boolean to use, and clear out the attribute so it doesn't carry anywhere later
	bool bReleasedFree = false;
	if (CheckAttribute(chr, "releasedfree") == true && sti(chr.releasedfree) == true)	{ // LDH 13Oct06 added sti()
		bReleasedFree = true;
		DeleteAttribute(chr,"releasedfree");
		traceif("SURR: " + chid + " was released free from ransack");
		// only reset the nation if they are already in the surrendered group
		if (CheckAttribute(chr, "oldnation") == true && Ship_GetGroupID(&chr) == SURR_GROUP) chr.nation = sti(chr.oldnation);
	}
	else
	{
		traceif("SURR: " + chid + " is surrendering");
	}
	// TIH <--

	traceif("SURR: ship nation: " + sti(chr.nation) );

// KK -->
	Ship_SetTaskDrift(PRIMARY_TASK, chridx);
	Ship_SetTaskDrift(SECONDARY_TASK, chridx);
// <-- KK

	int oldnat = sti(chr.nation);
	chr.oldnation = oldnat;
	chr.nation = NEUTRAL_NATION;
	chr.surrendered = true;
	chr.surrendered.seatime = GetSeaTime();

	chr.Flags.DoRefresh = true; // KK
	RefreshFlags();

	ref rGroup = Group_FindOrCreateGroup(SURR_GROUP);
	Group_SetType(SURR_GROUP, "trade");


	// TIH --> Nov5'06
	// check to see if this ship is already in the surrendered group
	bool bAlreadySurrendered = false;
	if (ogroup == SURR_GROUP)
	{
		//bAlreadySurrendered = true;
		traceif("SURR: Already Surrendered Before - setting bool to skip steps");
	}
	// if oldgroup is not set, lets set it
	if (!CheckAttribute(chr,"surrendered.oldgroup"))
	{
		chr.surrendered.oldgroup = ogroup;
	}
	traceif("SURR: ship oldgroup: " + chr.surrendered.oldgroup);
	// TIH <--

	ref rOGroup = Group_GetGroupByID(ogroup);
// KK -->
	int cmdridx = Group_GetGroupCommanderIndex(rOGroup);
	if (cmdridx < 0) return;
	ref cmdr = GetCharacter(cmdridx);
// <-- KK
	bool cmdrchange = cmdridx == chridx;
	bool firstchar = Group_GetCharacterIndexR(rOGroup, 0) == chridx;
	int og_ships = Group_GetCharactersNumR(rOGroup);

	int oldrel = -1;
	if (sti(cmdr.index) > 0) oldrel = SeaAI_GetRelation(cmdridx, pchridx); // TIH moved here so we can check relation with group commander Sep3'06
	traceif("SURR: SeaAI_GetRelation cmdr relation: " + oldrel);

	// TIH --> dont do this if already had surrendered Nov5'06
	if (!bAlreadySurrendered) {
		if (cmdrchange) {
			//Trace("SURR: fleet commander change, numships in group: " + og_ships);
			if (og_ships >= 2) {
				cmdridx = Group_GetCharacterIndexR(rOGroup, firstchar);
				cmdr = GetCharacter(cmdridx);
				Group_SetGroupCommander(ogroup, cmdr.id);
				DeleteAttribute(cmdr,"relation.UseOtherCharacter");
				traceif("SURR: commander changed to " + cmdr.id);
			} else {
				Group_DeleteGroup(ogroup); // KK
				traceif("SURR: no other ships to change commander to");
			}
		}
	}
	// TIH <--

	// TIH --> don't do any of this if ship had surrendered already Nov5'06 // KK -->
	if (bAlreadySurrendered)
	{
		// do morale boost
		int killidx = -1;

		if(CheckAttribute(chr,"ship.lastballcharacter"))
		{
			killidx = sti(chr.Ship.LastBallCharacter);
			if(killidx == pchridx) // if player shoots this ship, make this nation and player hostile. 05-09-14
			{
				if (sti(cmdr.index) > 0) SetCharacterRelationBoth(pchridx, sti(cmdr.index), RELATION_ENEMY);// TIH added index check Sep3'06
				AttackRMRelation(GetMainCharacter(), oldnat);
				oldrel = RELATION_ENEMY;
			}
			// KK tmpstr = killidx;
			// KK charsdone.(tmpstr) = true;
			ref rKillerCharacter = GetCharacter(killidx);
			tmped = 0;
			if(CheckAttribute(rKillerCharacter,"seatime.enemydead")) tmped = stf(rKillerCharacter.seatime.enemydead);
			origed = makefloat(GetCharacterShipClass(rKillerCharacter)) / makefloat(GetCharacterShipClass(chr)) * CLASS_SCALAR_FOR_MORALE;
			tmped += origed;
			rKillerCharacter.seatime.enemydead = tmped;
		}
	} else {
		traceif("SURR: done lbc boost, now cycle through ships and forts");
		for(i = 0; i < iNumShips; i++)
		{
			if(ships[i] == -1) continue;
			schr = GetCharacter(ships[i]);
			if(SeaAI_GetRelation(Ships[i], chridx) == RELATION_ENEMY && ships[i] != killidx)
			{
				origed = makefloat(GetCharacterShipClass(&schr)) / makefloat(GetCharacterShipClass(&chr)) * CLASS_SCALAR_FOR_MORALE;
				tmped = 0; if(CheckAttribute(schr,"seatime.enemydead")) tmped = stf(schr.seatime.enemydead);
				tmped += origed * CLASS_SCALAR_FOR_MORALE_ORIG_TO_OTHER + makefloat(GetCharacterShipClass(schr)) / makefloat(GetCharacterShipClass(chr)) * CLASS_SCALAR_FOR_MORALE_OTHER;
				schr.seatime.enemydead = tmped;
			}
			// KK tmpstr = Ships[i];
			// KK charsdone.(tmpstr) = true;
			//trace("did " + schr.id);
		}
		if(CheckAttribute(pchar,"seaAI.update.forts.l0"))
		{
			makearef(tmpattr, pchar.seaAI.update.forts);
			for(i = 0; i < GetAttributesNum(tmpattr); i++)
			{
				tmpstr= "l" + i;
				tmpidx = sti(tmpattr.(tmpstr).idx);
				if(tmpidx == -1) continue; // 04-12-06
				tmpstr = tmpidx;
				// KK charsdone.(tmpstr) = true;
			}
		}
	}
	// TIH <-- // <-- KK

	if (Ship_GetDistance2D(PChar, chr) > GetVisibilityRange(2)) bReleasedFree = true; // KK: Flag change can not be seen outside MEDIUM range
	// TIH --> bandaide until this whole process is handled better Jul22'06
	
	if (!bReleasedFree) {
		// DeathDaisy -->
		string PCharTitle = "Sir";
		switch(PChar.sex){
			case "woman":
				PCharTitle = "Ma'am";
			break;
		}
		// DeathDaisy <--
		if (oldrel == RELATION_ENEMY) {
			TraceAndLog(TranslateString("", PCharTitle + ", the") + " " + GetMyShipNameShow(chr) + " " + TranslateString("","has struck her colors!")); // KK
			PlaySound("interface\notebook.wav");
			PlaySound("objects\abordage\abordage_wining.wav");
		} else {
			TraceAndLog(TranslateString("", PCharTitle + ", the") + " " + GetMyShipNameShow(chr) + " " + TranslateString("","has struck her colors to the enemy!")); // KK
		}
	}
	// TIH <--

	Traceif("SURR: setting up character group");

	Group_DelCharacter(chr.SeaAI.Group.Name, chid); // KK
	SendMessage(&AISea, "laa", AI_MESSAGE_SET_OFFICER_2_SHIP, chr, chr); // KK
	Event(SHIP_UPDATE_PARAMETERS, "lf", chridx, 1.0);		// Parameters

	DeleteAttribute(chr,"relation.UseOtherCharacter");
	Group_ChangeCharacter(SURR_GROUP, chid);
	Group_SetGroupCommander(SURR_GROUP, chid);
	Group_DeleteAtEnd(SURR_GROUP);

	traceif("SURR: group change done");

	RefreshBattleInterface(true); // KK

	Traceif("SURR: Ship_Surrender complete");
}



// NK can qty 05-04-18
// sets char.ship.cannons.borts.(arc).curqty based on *.qty and current crew
void Ship_SetCannonQtyByCrew(ref rCharacter)
{
	//bool ismch = sti(rCharacter.index) == GetMainCharacterIndex();
	if(!GetCannonQuantity(&rCharacter)) return;
	aref arship; makearef(arship, rCharacter.ship);
	if (bRealBattleInterface == false && GetCharacterIndex(rCharacter.id) == GetMainCharacterIndex()) Event("evntUpdateCannonInfo"); // KK

//  Original code
//	int crewQuan = GetMinCrewQuantity(&rCharacter);//MAXIMUS
//	if(crewQuan==0) crewQuan = 1;
//	float crewratio = makefloat(GetCrewQuantity(&rCharacter)) / makefloat(crewQuan * 5); //yes, not max. This means multipliers on min/max crew make a difference here.
//	//if(ismch) logit("doing setcancrew, ratio " + crewratio);
//	ref rship = GetShipByType(GetCharacterShipType(&rCharacter));
//	int fullqty = GetLocalShipAttrib(&arship, rship, "MaxCanQty");
//	crewratio = crewratio * makefloat(fullqty) / makefloat(GetCannonQuantity(&rCharacter)); // so if can qty decreases, not as much crew needed.
//	float minCrewRatio = MIN_CREW_FOR_ALL_GUNS;

	// LDH set min crew ratio to number of crew actually required to load one broadside - 12May09 -->
	ref	rCannon = GetCannonByType(sti(rCharacter.Ship.Cannons.Type));
	float CrewPerGun = stf(rCannon.caliber);
	if (rCannon.type == CANNON_NAME_LONG)
		CrewPerGun /= 2.0;	// 12 pounder takes 6 crew, for example
	else
		CrewPerGun /= 6.0;	// carronades take fewer crew and are normally twice the caliber of the long guns they replace
		// Note that if the player doesn't have USE_REAL_CANNONS set, the CrewPerGun is divided by 6 as well
	CrewPerGun = fclamp(1.0, 10.0, CrewPerGun);		// gun crew no less than 1 and no more than 10

	int iCanQty = GetCannonQuantity(&rCharacter);
	float CrewRequired = CrewPerGun * iCanQty;
	CrewRequired /= 2.0;		// We're only loading one broadside at a time.
	if (CrewRequired < 1) CrewRequired = 1;

	int CrewQuantity  = GetCrewQuantity(rCharacter);
	if(iRealismMode>0)
	{
		int MinSailCrew = GetCharacterShipHP(rCharacter)/100;	// crew needed for sailing, intentionally not using mininum crew here
		if (MinSailCrew >= 100000/100) MinSailCrew = 100;		// Cursed ships are a special case
		CrewQuantity -= MinSailCrew;
	}
	if (CrewQuantity < CrewPerGun) CrewQuantity = CrewPerGun;		// detail one gun crew from the MinSailCrew

	float crewratio = 1.0;
	if (CrewRequired > CrewQuantity)
	{
		crewratio = CrewQuantity / CrewRequired;
	}
	float minCrewRatio = 1.0;
	// LDH <--

	int curqty = 0;
	if( crewratio < minCrewRatio)
	{
		float canqty = clampf(Bring2Range(0.01, 1.0, 0.01, minCrewRatio, crewratio));
		//if(ismch) logit("can qty ratio " + canqty);

		curqty = sti(rCharacter.ship.Cannons.Borts.cannonf.qty);
		if(curqty > 0) curqty = iclamp(1, curqty, makeint(canqty * curqty));
		rCharacter.ship.Cannons.Borts.cannonf.curqty = curqty;

		curqty = sti(rCharacter.ship.Cannons.Borts.cannonb.qty);
		if(curqty > 0) curqty = iclamp(1, curqty, makeint(canqty * curqty));
		rCharacter.ship.Cannons.Borts.cannonb.curqty = curqty;

		curqty = sti(rCharacter.ship.Cannons.Borts.cannonl.qty);
		if(curqty > 0) curqty = iclamp(1, curqty, makeint(canqty * curqty));
		rCharacter.ship.Cannons.Borts.cannonl.curqty = curqty;

		curqty = sti(rCharacter.ship.Cannons.Borts.cannonr.qty);
		if(curqty > 0) curqty = iclamp(1, curqty, makeint(canqty * curqty));
		rCharacter.ship.Cannons.Borts.cannonr.curqty = curqty;
	}
	else
	{
		//if(ismch) logit("reset to max canqty");
		rCharacter.ship.Cannons.Borts.cannonf.curqty = rCharacter.ship.Cannons.Borts.cannonf.qty;
		rCharacter.ship.Cannons.Borts.cannonb.curqty = rCharacter.ship.Cannons.Borts.cannonb.qty;
		rCharacter.ship.Cannons.Borts.cannonl.curqty = rCharacter.ship.Cannons.Borts.cannonl.qty;
		rCharacter.ship.Cannons.Borts.cannonr.curqty = rCharacter.ship.Cannons.Borts.cannonr.qty;
	}
}
// NK <--

// TIH --> Nov13'06
// New common function for determining if cannons are firing, and need to be reset for cannon loss restriction control.
// The 'reset' variable will allow a forced purge of attributes and reset of curqty (for adding ships to sea).
// See the detailed explanation in AIBalls.c 'Ball_AddBall' function for more.
void Ship_CannonsFiringCheck(ref rCharacter, bool reset)
{
	// logit("CannonsFiringCheck");
	string 	quadStr = "";
	bool 	isFiring = false;
	for (int quad=0; quad < 4; quad++) {
		quadStr = GetQuadName(quad);
		if(CheckAttribute(rCharacter, "Ship.Cannons.Borts."+ quadStr +".deleteme"))
		{
			isFiring = true;
			// 'numfired' will always exist if 'deleteme' exists, no need to CheckAttribute on it.
			if ( sti(rCharacter.Ship.Cannons.Borts.(quadStr).numfired) >= sti(rCharacter.Ship.Cannons.Borts.(quadStr).deleteme) || reset)
			{
				DeleteAttribute(rCharacter, "Ship.Cannons.Borts."+ quadStr +".deleteme");
				DeleteAttribute(rCharacter, "Ship.Cannons.Borts."+ quadStr +".numfired");
			}
		}
	}
	if(!isFiring || reset) { Ship_SetCannonQtyByCrew(&rCharacter); } // NK reset curqty of cannon in each arc based on crew qty.

}
// TIH <--

void Ship_CheckSituation()
{
	ref 	rShip;
	//NK 04-09-15 comment out unneeded vars.
	ref rMainCharacter = GetMainCharacter();
	aref	rCharacter = GetEventData();
	aref	rShipObject = GetEventData();

	//int RelNat = GetNationRelation2MainCharacter(sti(rCharacter.nation));

	// NK can qty 05-04-18 -->
	// this will delete the numfired attribute after the deleteme counter hits 0. deleteme is reset whenever a gun is fired.
	// so in order to not reset numfired early, we have to do this.
	// TIH --> Nov13'06
	// Unfortunately the intent was there, but the execution didn't work right. This has been rewritten to work now.
	// See the detailed explanation in AIBalls.c 'Ball_AddBall' function for more.
	Ship_CannonsFiringCheck(&rCharacter, false);
	/*
	int nfdelay;
	bool isfiring = false;
	if(CheckAttribute(rCharacter, "ship.Cannons.Borts.cannonf.deleteme"))
	{
		isfiring = true;
		nfdelay = sti(rCharacter.ship.Cannons.Borts.cannonf.deleteme);
		nfdelay--;
		rCharacter.ship.Cannons.Borts.cannonf.deleteme = nfdelay;
		if(nfdelay <= 0)
		{
			DeleteAttribute(rCharacter, "ship.Cannons.Borts.cannonf.deleteme");
			DeleteAttribute(rCharacter, "ship.Cannons.Borts.cannonf.numfired");
		}
	}
	if(CheckAttribute(rCharacter, "ship.Cannons.Borts.cannonb.deleteme"))
	{
		isfiring = true;
		nfdelay = sti(rCharacter.ship.Cannons.Borts.cannonb.deleteme);
		nfdelay--;
		rCharacter.ship.Cannons.Borts.cannonb.deleteme = nfdelay;
		if(nfdelay <= 0)
		{
			DeleteAttribute(rCharacter, "ship.Cannons.Borts.cannonb.deleteme");
			DeleteAttribute(rCharacter, "ship.Cannons.Borts.cannonb.numfired");
		}
	}
	if(CheckAttribute(rCharacter, "ship.Cannons.Borts.cannonl.deleteme"))
	{
		isfiring = true;
		nfdelay = sti(rCharacter.ship.Cannons.Borts.cannonl.deleteme);
		nfdelay--;
		rCharacter.ship.Cannons.Borts.cannonl.deleteme = nfdelay;
		if(nfdelay <= 0)
		{
			DeleteAttribute(rCharacter, "ship.Cannons.Borts.cannonl.deleteme");
			DeleteAttribute(rCharacter, "ship.Cannons.Borts.cannonl.numfired");
		}
	}
	if(CheckAttribute(rCharacter, "ship.Cannons.Borts.cannonr.deleteme"))
	{
		isfiring = true;
		nfdelay = sti(rCharacter.ship.Cannons.Borts.cannonr.deleteme);
		nfdelay--;
		rCharacter.ship.Cannons.Borts.cannonr.deleteme = nfdelay;
		if(nfdelay <= 0)
		{
			DeleteAttribute(rCharacter, "ship.Cannons.Borts.cannonr.deleteme");
			DeleteAttribute(rCharacter, "ship.Cannons.Borts.cannonr.numfired");
		}
	}
	if(!isfiring) Ship_SetCannonQtyByCrew(&rCharacter); // reset curqty of cannon in each arc based on crew qty.
	*/
	// TIH <--
	// NK <--

	if (sti(rCharacter.index) == GetMainCharacterIndex()) { return; }

	//aref	rSituation;
	//makearef(rSituation, rCharacter.SeaAI.Update.Situation);
	//trace("*****For Char " + rCharacter.id + " of ship " + rCharacter.ship.name + " update.sit = ");
	//DumpAttributes(rSituation);

	Ship_CheckMorale(sti(rCharacter.index)); // NK 04-09-16

	// NK have AI use light repair 04-09-16-->
	if(GetCharacterPerkUsing(rCharacter,"InstantRepair"))
	{	if(GetHullPercent(rCharacter)<50.0 || GetSailPercent(rCharacter)<50.0)
		{
			ActivateCharacterPerk(rCharacter,"InstantRepair");
			ActivateSpecRepair(rCharacter,1);
		}
	}
	else
	{
		if(GetCharacterPerkUsing(rCharacter,"LightRepair"))
		{	if(GetHullPercent(rCharacter)<10.0 || GetSailPercent(rCharacter)<10.0)
			{
				ActivateCharacterPerk(rCharacter,"LightRepair");
				ActivateSpecRepair(rCharacter,0);
			}
		}
	}
	// NK <--

	rShip = GetShipByType(GetCharacterShipType(rCharacter)); // PS
	// NK -->
	if(CheckAttribute(rCharacter,"surrendered")) return; // NK surrender 05-04-20
	// move these here 04-09-16 NK
	float HPPercent = stf(rCharacter.Ship.HP) / makefloat(GetCharacterShipHP(rCharacter));
	int MinCrewQuantity = GetMinCrewQuantity(rCharacter);
	int CrewQuantity = sti(rCharacter.Ship.Crew.Quantity);
	if(HPPercent < HULL_PCT_CHAIN  || CrewQuantity < MinCrewQuantity) // move this here
	{
		Ship_SetTaskRunaway(SECONDARY_TASK,sti(rCharacter.index));
	}
	// NK 05-04-24 set attack
	string sGroupID = Ship_GetGroupID(rCharacter);
	ref rGroup = Group_FindOrCreateGroup(sGroupID);
	string sGroupType = Group_GetTypeR(rGroup);
	ref cmdr = Group_GetGroupCommanderR(rGroup);
	if(CheckAttribute(cmdr,"index"))
	{
		if(cmdr.index == rCharacter.index && sti(rGroup.task) == AITASK_MOVE && sGroupType != "trade")
		{
			float tdist;
			int tmpt = FindClosestShipofRel(sti(rCharacter.index), &tdist, RELATION_ENEMY);
			if(tmpt != -1) Group_SetTaskAttack(sGroupID, Ship_GetGroupID(GetCharacter(tmpt)), false); // PB: Relations should already be hostile
		}
	}
	// NK <--

	// NK 04-09-15 redo check situation and ammo loadout
	bool setammo = !CheckAttribute(rCharacter,"ship.cannons.type");
	if(!setammo) setammo = sti(rCharacter.ship.cannons.type) == CANNON_TYPE_NONECANNON; // NK to avoid checking ammo on cannonless ships 04-09-18
	int targetidx = -1;
	bool foundtgt = false;
	// check some tasks
	if (CheckAttribute(rCharacter, "SeaAI.Task"))
	{
		switch (sti(rCharacter.SeaAI.Task))
		{
			case AITASK_BRANDER:
				ref rCharacter2Brander = GetCharacter(sti(rCharacter.SeaAI.Task.Target));
				ref rBaseShip = GetShipByType(GetCharacterShipType(rCharacter2Brander)); // PS
				float fBranderDistance = 30.0 + (8.0 - stf(rBaseShip.Class)) * 40.0;
				float fDistance = Ship_GetDistance2D(rCharacter, rCharacter2Brander);
				if (fBranderDistance > fDistance && fDistance >= 0) // NK for when dist < 0 05-04-15
				{
					// fire ship
					int iNumFirePlaces = 0;
					SendMessage(rShipObject, "le", MSG_SHIP_GET_NUM_FIRE_PLACES, &iNumFirePlaces);
					for (int i=0; i<iNumFirePlaces / 3; i++)
					{
						PostEvent(SHIP_ACTIVATE_FIRE_PLACE, rand(10000), "ialsf", rShipObject, rCharacter, i, "ship_onfire", 30.0);
					}
					rCharacter.fireplaces.brander = true; // NK 05-04-18
					PostEvent(SHIP_BRANDER_DETONATE, 10000, "l", sti(rCharacter.index));

					Ship_SetTaskNone(SECONDARY_TASK, sti(rCharacter.index));
				}
				//Trace("test1 rCharacter2Brander = " + rCharacter2Brander.index);
			break;

			// NK -->
			case AITASK_ATTACK:
				if(!setammo) // NK to avoid checking ammo on cannonless ships 04-09-18
				{
					int temptgt = sti(rCharacter.SeaAI.task.target); //do this since we're already finding target above. 04-09-16
					if(temptgt >= 0 && temptgt >= TOTAL_CHARACTERS)
					{
						if(!LAi_IsDead(GetCharacter(temptgt)))
						{
							targetidx = temptgt; //set target to what we're attacking. If not, find a new one below.
							foundtgt = true;
							if(CheckAttribute(Characters[targetidx],"surrendered"))
							{
								if(!IsCompanion(Characters[targetidx]))
								{
									targetidx = FindClosestShipofRel(sti(rCharacter.index), RELATION_ENEMY);
									if(targetidx != -1) Ship_SetTaskAttack(SECONDARY_TASK, sti(rCharacter.index), targetidx);
									else Ship_SetTaskRunaway(SECONDARY_TASK, sti(rCharacter.index));
								}
							}
						}
					}
				}
			break;
		}
	}
	if(!setammo)
	{
//================================================ new tgt if cur tgt surrendered 05-04-23 ================================================//
		if(CheckAttribute(rCharacter, "ship.lasttgt"))
		{
			if(CheckAttribute(Characters[sti(rCharacter.ship.lasttgt)],"surrendered")) DeleteAttribute(&rCharacter, "ship.lasttgt");
		}
		if(!foundtgt && !IsCompanion(rCharacter)) targetidx = FindOurTarget(sti(rCharacter.index));
//!IsCompanion(rCharacter) added by MAXIMUS [abordage MOD]
//=========================================================================================================================================//

		//called in morale section at top - targetidx = FindOurTarget(sti(rCharacter.index)); // finds ship we last fired on, or if not nearest hostile ship
		if(targetidx >= 0 && targetidx < TOTAL_CHARACTERS)
		{
			Ship_AmmoUpdate(sti(rCharacter.index), targetidx);
			setammo = true;
		}
	}
}


// NK
//finds ratio of friend power vs. foe power
float FindPowerRatio(int idx)
{
	int num = FindNearShips(idx);
	ref chr = GetCharacter(idx);
	int sidx = sti(chr.curshipnum); // change to array 05-06-27
	//if(num == 0) return 0.0;
	string tstr = "rel"+RELATION_ENEMY;
	if(!CheckAttribute(NearShips[sidx],tstr+".0")) return 0.0;
	float epower = FindPowerOfNearShips(idx, RELATION_ENEMY);
	float fpower = FindPowerOfNearShips(idx, RELATION_FRIEND);
	if(epower < 0.5) epower = 1.0;
	if(fpower < 0.5) fpower = 1.0;
	return epower / fpower;
}

float FindPowerOfNearShips(int idx, int rel)
{
	int num = FindNearShips(idx);
	ref chr = GetCharacter(idx);
	int sidx = sti(chr.curshipnum); // change to array 05-06-27
	string tstr = "rel"+rel;
	if(num <= 0 || !CheckAttribute(NearShips[sidx],tstr+".0")) return 0.0;
	float power = 0.0;
	string tstr2;
	for(int i = 0; i < sti(NearShips[sidx].(tstr).qty); i++)
	{
		if(GetCannonCurQuantity(&chr)<=0) continue;
		if(!CheckAttribute(&NearShips[sidx],tstr+"."+tstr2+".dist")) continue;

		string s1 = GetCurrentShipHP(&chr);
		string s2 = GetCannonCurQuantity(&chr);
		string s3 = 1.0 + pow2(stf(NearShips[sidx].(tstr).(tstr2).dist)/100.0, 1.5);

		tstr2 = i;
		chr = GetCharacter(sti(NearShips[sidx].(tstr).(tstr2).idx));
		power += sqrt(GetCurrentShipHP(&chr) * GetCannonCurQuantity(&chr)) / (1.0 + pow2(stf(NearShips[sidx].(tstr).(tstr2).dist)/100.0, 1.5));
	}
	if(rel == RELATION_FRIEND)
	{
		chr = GetCharacter(idx);
		tstr2 = 0;
		power += sqrt(GetCurrentShipHP(&chr) * GetCannonCurQuantity(&chr)) / (1.0 + pow2(stf(NearShips[sidx].all.(tstr2).dist)/100.0, 1.5)); // nearest ship
	}
	return power;
}
// added 05-04-20
//finds closest ship ('s captain) of specified group. returns -1 if none available
int FindClosestShipOfGroup(int idx, ref retdist, string groupid)
{
	// logit("FindClosestShipOfGroup");
	int tgt = FindNearShips(&idx);
	ref chr = GetCharacter(idx);
	int sidx = sti(chr.curshipnum); // change to array 05-06-27
	if(tgt == 0) return -1;
	string tstr = groupid+".0";
	if(!CheckAttribute(NearShips[sidx],tstr)) return -1;
	retdist = stf(NearShips[sidx].(tstr).dist);
	return sti(NearShips[sidx].(tstr).idx);
}


// finds the index of the character whom we last fired at, or, if nothing there, the closest hostile ship.
int FindOurTarget(int idx)
{
	ref chr = GetCharacter(idx);
	if(CheckAttribute(chr,"ship.lasttgt")) //try to find who ship last attacked
	{
		int lhidx = sti(chr.ship.lasttgt);
		if(lhidx != -1 && lhidx < TOTAL_CHARACTERS)
		{
			if(!LAi_IsDead(GetCharacter(lhidx)))
			{
				//retdist = Ship_GetDistance2D(GetCharacter(lhidx), chr); // so we return a distance.
				return lhidx;
			}
			else
			{
				DeleteAttribute(chr,"ship.lasttgt"); //if dead, don't check again until next tgt
			}
		}
	}
	//otherwise find closest hostile ship
	float retdist = -1;
	return FindClosestShipofRel(idx, &retdist, RELATION_ENEMY);
}

// finds the index of the character whose ship of relation rel to us (char index idx) is nearest, and returns it. -1 if none available.
int FindClosestShipofRel(int idx, ref retdist, int rel)
{
	ref chr = GetCharacter(idx);
	if(!CheckAttribute(chr,"curshipnum")) return -1; // MAXIMUS 22.12.06
	int sidx = sti(chr.curshipnum); // change to array 05-06-27
	int tgt = FindNearShips(&idx);
	if(tgt == 0) return -1;
	string tstr = "rel"+rel+".0";
	if(!CheckAttribute(NearShips[sidx],tstr)) return -1;
	retdist = stf(NearShips[sidx].(tstr).dist);
	return sti(NearShips[sidx].(tstr).idx);
}

//fills the NearShips object for use in other functions. 05-04-22
int FindNearShips(int idx)
{
	// logit("FindNearShips");
	ref chr = GetCharacter(idx);
	int sidx = sti(chr.curshipnum); // change to array 05-06-27
	aref retobj; makearef(retobj, NearShips[sidx]);
	int st = GetSeaTime();
	if(CheckAttribute(retobj,"lastchar"))
	{
		if(sti(retobj.lastchar) == idx)
		{
			int lt = sti(retobj.lasttime);
			if(st >= lt && lt > st - 2) return sti(retobj.all.qty);		// LDH added st>=lt check - 06Jan09
		}
	}

	ref achr;
	//bool checkrel = rel != -1;
	int achridx;
	//int attacker = -1;
	//float distances[1];
	int place = 0;
	string tstr;
	object tmpclose;
	tmpclose.t = "";
	aref closeobj;
	makearef(closeobj, tmpclose.t);
	float tmp;
	//bool check = false;
	if(idx == -1 || idx > TOTAL_CHARACTERS) return 0; // 04-12-06
	for(int i = 0; i < iNumShips; i++)
	{
		achridx = Ships[i];
		if(achridx == idx || achridx == -1) continue; // 04-12-06
		achr = GetCharacter(achridx);
		//below unneeded, we can just check relation...
		/*if(sti(achr.seaAI.task) == AITASK_ATTACK)
		{
			if(sti(achr.seaAI.task.target) == idx)
			{
				check = true;
			}
		}
		if(IsCompanion(achr) && !IsCompanion(chr))
		{
			if(GetRelation(idx, achridx) == RELATION_ENEMY) check = true;
		}
		if(check)
		{
			tmp = Ship_GetDistance2D(achr, chr);
			if(distance > tmp) { distance = tmp; attacker = achridx; }
		}*/
		//new code:
		if (!CheckAttribute(achr,"nation")) continue; // 04-12-06 check for nation
		// LDH We need to check surrendered nation which is greater than NATIONS_QUANTITY - 03May09 -->
		bool bSkip = false;
		if (sti(achr.nation) == -1 || sti(achr.nation) >= NATIONS_QUANTITY) bSkip = true;  // 04-12-06 check for nation bounds
		if (sti(achr.nation) == NEUTRAL_NATION) bSkip = false;		// LDH this handles surrendered ships - 03May09
		if (bSkip) continue;
		// LDH <--
		//relchk = SeaAI_GetRelation(idx, achridx) == rel || !checkrel;
		if(!LAi_IsDead(achr)) //04-12-06 stupid bug; forgot SeaAI_.
		{
			//if(place+1 < GetArraySize(&distances)) SetArraySize(&distances, place+1);
			tstr = place;
			closeobj.(tstr).idx = achridx;
			closeobj.(tstr).id = achr.id;
			closeobj.(tstr).dist = Ship_GetDistance2D(achr, chr);
			closeobj.(tstr).group = Ship_GetGroupID(&achr);
			closeobj.(tstr).rel = SeaAI_GetRelation(idx, achridx);
			if(CheckAttribute(achr,"surrendered")) closeobj.(tstr).rel = RELATION_NEUTRAL; // important fix for surrender func! 05-04-23
			place++;
			//if(distance > tmp && tmp >= 0) { distance = tmp; attacker = achridx; } // NK for when dist < 0 05-04-15
		}
	}
	// 04-09-22 check forts too
	ref pchar = GetMainCharacter();
	if(CheckAttribute(pchar,"seaAI.update.forts.l0"))
	{

		aref updforts; makearef(updforts, pchar.seaAI.update.forts);
		string tmpa;
		for(i = 0; i < GetAttributesNum(updforts); i++)
		{
			tmpa= "l" + i;
			achridx = sti(updforts.(tmpa).idx);
			if(achridx == idx || achridx == -1) continue; // 04-12-06
			achr = GetCharacter(achridx);
			if(!CheckAttribute(achr,"nation")) continue; // 04-12-06 check for nation
			else { if(sti(achr.nation) == -1 || sti(achr.nation) >= NATIONS_QUANTITY) { continue; } } // 04-12-06 check for nation bounds
			//relchk = SeaAI_GetRelation(idx, achridx) == rel || !checkrel;
			if(!LAi_IsDead(achr)) //04-12-06 stupid bug; forgot SeaAI_.
			{
				//tmp = Ship_GetDistance2D(achr, chr);
				//if(distance > tmp && tmp >=0) { distance = tmp; attacker = achridx; } // NK for when dist < 0 05-04-15
				tstr = place;
				closeobj.(tstr).idx = achridx;
				closeobj.(tstr).id = achr.id;
				closeobj.(tstr).dist = Ship_GetDistance2D(achr, chr);
				closeobj.(tstr).group = Ship_GetGroupID(&achr);
				closeobj.(tstr).rel = SeaAI_GetRelation(idx, achridx);
				place++;
			}
		}
	}
	DeleteAttribute(retobj, "");
	retobj.all.qty = place;
	retobj.lastchar = idx;
	retobj.lasttime = st;
	if(!place) { return 0; }
	//trace("******for char " + chr.id + " of ship " + chr.ship.name + " we dump presort NearShips:");
	//DumpAttributes(closeobj);
	aref tmpar; makearef(tmpar, closeobj);
	fSortArray(&tmpar, "dist", 0, place-1);

	int r, relplace[3]; relplace[0] = 0; relplace[1] = 0; relplace[2] = 0;
	object groupplaces;
	string tstr2;
	aref curplace, aref arrplace;
	for(i = 0; i < place; i++)
	{
		tstr = i;
		makearef(arrplace, closeobj.(tstr));
		retobj.all.(tstr) = "";
		makearef(curplace, retobj.all.(tstr));
		CopyAttributes(curplace, arrplace);
		r = sti(arrplace.rel);
		tstr = "rel" + r + "." + relplace[r];
		relplace[r]++;
		retobj.(tstr) = "";
		makearef(curplace,retobj.(tstr));
		CopyAttributes(curplace, arrplace);
		tstr = arrplace.group;
		r = 0;
		if(CheckAttribute(retobj,"groups."+tstr+".qty")) r = sti(retobj.groups.(tstr).qty);
		retobj.groups.(tstr).qty = r+1;
		tstr += "."+r;
		retobj.groups.(tstr) = "";
		makearef(curplace, retobj.groups.(tstr));
		CopyAttributes(curplace, arrplace);
	}
	// done above. retobj.all.qty = place;
	retobj.rel0.qty = relplace[0];
	retobj.rel1.qty = relplace[1];
	retobj.rel2.qty = relplace[2];
	//tstr = "all.0";
	//retdist = stf(retobj.(tstr).dist);
	return place;
	/*retdist = distance;
	return attacker;*/
}
// NK 05-04-22
// use scheffnow's sort code, generalized and set for attribute tree use.
// needs tree of: sortarray.X.things, where X is 0+, and things are any attributes. But all entries must have sortarray.X.sortthing, which is the thing we sort by.
// this is the float version; should work OK with ints too.
void fSortArray(aref sortarray, string sortthing, int intLowerPos, int intUpperPos)
{
	//trace("with L/U " + intLowerPos + " / " + intUpperPos + " we are sorting.");
	//dumpattributes(sortarray);
	float fCenterValue;
	int intCenterPos;
	int i;
	aref MinArr;
	aref MaxArr;
	object temp;
	temp.t = "";
	aref TmpArr; makearef(TmpArr, temp.t);
	string tstr;
	if (intLowerPos < intUpperPos)
	{
		tstr = intLowerPos
		makearef(MinArr,sortarray.(tstr));
		fCenterValue = stf(MinArr.(sortthing));
		intCenterPos   = intLowerPos;
		for(i=intLowerPos+1;i<=intUpperPos;i++)
		{
			tstr = i;
			makearef(MinArr,sortarray.(tstr));
			if (stf(MinArr.(sortthing)) < fCenterValue)
			{
				intCenterPos++;
				tstr = intCenterPos;
				makearef(MinArr,sortarray.(tstr));
				tstr = i;
				makearef(MaxArr,sortarray.(tstr));
				//makearef(TmpArr,sortarray[lastpos-1]);
				DeleteAttribute(TmpArr,""); // just in case
				CopyAttributes(TmpArr,MinArr);
				CopyAttributes(MinArr,MaxArr);
				CopyAttributes(MaxArr,TmpArr);
			}
		}
		tstr = intLowerPos;
		makearef(MinArr,sortarray.(tstr));
		tstr = intCenterPos;
		makearef(MaxArr,sortarray.(tstr));
		//makearef(TmpArr,sortarray[lastpos-1]);
		DeleteAttribute(TmpArr,"");
		CopyAttributes(TmpArr,MinArr);
		CopyAttributes(MinArr,MaxArr);
		CopyAttributes(MaxArr,TmpArr);
		fSortArray(&sortarray, sortthing, intLowerPos,intCenterPos-1);
		fSortArray(&sortarray, sortthing, intCenterPos+1,intUpperPos);
	}
}


// finds min reload percentage
float Ship_FindMinChargeRatio(ref chr)
{
	float min = 0.0;
	/*if(!CheckAttribute(chr,"ship.Cannons.Borts.cannonl.chargeratio"))
	{
		//trace("char " + chr.id + " not have chargeratio attribute!");
		return 0.0;
	}*/
	if(CheckAttribute(chr,"ship.Cannons.Borts.cannonl.chargeratio")) { if(min > stf(chr.ship.Cannons.Borts.cannonl.chargeratio)) min = stf(chr.ship.Cannons.Borts.cannonl.chargeratio); }
	if(CheckAttribute(chr,"ship.Cannons.Borts.cannonr.chargeratio")) { if(min > stf(chr.ship.Cannons.Borts.cannonr.chargeratio)) min = stf(chr.ship.Cannons.Borts.cannonr.chargeratio); }
	if(CheckAttribute(chr,"ship.Cannons.Borts.cannonf.chargeratio")) { if(min > stf(chr.ship.Cannons.Borts.cannonf.chargeratio)) min = stf(chr.ship.Cannons.Borts.cannonf.chargeratio); }
	if(CheckAttribute(chr,"ship.Cannons.Borts.cannonb.chargeratio")) { if(min > stf(chr.ship.Cannons.Borts.cannonb.chargeratio)) min = stf(chr.ship.Cannons.Borts.cannonb.chargeratio); }
	return min;
}

//will order change in charge if it's OK or if out of range, and will call find new ammo
void Ship_AmmoUpdate(int iUs, int iThem)
{
	ref rUs = GetCharacter(iUs); ref rThem = GetCharacter(iThem);
	ref rCannon = GetCannonByType(sti(rUs.Ship.Cannons.Type));
	float range = stf(rCannon.FireRange) * AIShip_isPerksUse(rUs.TmpPerks.LongRangeShoot, 1.0, 1.15);

	float distance = Ship_GetDistance2D(&rUs, &rThem);
	if(distance < 0) distance = 1000; // NK for when dist < 0 05-04-15
	bool change = false;
	if(!change) change = sti(rUs.Ship.Cannons.Charge.Type) >= GOODS_QUANTITY; //bugfix 04-09-18
	if(!change) { if(distance > range * OUTOFRANGE_SCL * stf(Goods[sti(rUs.Ship.Cannons.Charge.Type)].SpeedV0) && sti(rUs.Ship.Cannons.Charge.Type) != sti(ShipLookupTable.ammo.ship.Range.idx)) change = true; }
	if(!change && frnd() < 0.5) change = Ship_FindMinChargeRatio(rUs) <= MAX_TO_RELOAD && !CheckAttribute(rUs,"ship.changedammo");
	if(change)
	{
		int newammo = Ship_FindOtherBallType(iUs, iThem);
		if(newammo != -1 && newammo != sti(rUs.Ship.Cannons.Charge.Type))
		{
			//trace("changing ammo for " + rUs.id + " of " + rUs.ship.name + ", new charge: " + Goods[newammo].name + "; status fblr: " + rUs.ship.Cannons.Borts.cannonf.chargeratio + " " + rUs.ship.Cannons.Borts.cannonb.chargeratio + " " + rUs.ship.Cannons.Borts.cannonl.chargeratio + " " + rUs.ship.Cannons.Borts.cannonr.chargeratio);
			Ship_ChangeCharge(rUs, newammo);
			//Logit("Updating ammo for  " + rUs.name + " " + rUs.lastname + " (" + rUs.id + ") of the " + rUs.Ship.Name + " vs. " + rThem.name + " " + rThem.lastname + " (" + rThem.id + ") of the " + rThem.Ship.Name)
			//Logit("Will change ammo. New ammo " + Goods[newammo].name);
		}
	}
}

//finds new ammo for ship of Us firing on Them
int Ship_FindOtherBallType(int iUs, int iThem)
{
	ref rUs = GetCharacter(iUs);
	bool bHull, bRig, bCrew, bAll, bRange;
	string stype = "ship"; if(rUs.ship.type == SHIP_FORT_NAME) return GOOD_BOMBS; // forts use heated shot.
	int aHull, aRig, aCrew, aAll, aRange;
	aAll = sti(ShipLookupTable.ammo.(stype).All.idx);
	aRange = sti(ShipLookupTable.ammo.(stype).Range.idx);
	aHull = sti(ShipLookupTable.ammo.(stype).Hull.idx);
	aRig = sti(ShipLookupTable.ammo.(stype).Rig.idx);
	aCrew = sti(ShipLookupTable.ammo.(stype).Crew.idx);

	int iShipCannonsNum = GetCannonQuantity(rUs);
	bHull = GetCargoGoods(rUs,aHull) >= iShipCannonsNum;
	bRig = GetCargoGoods(rUs,aRig) >= iShipCannonsNum;
	bCrew = GetCargoGoods(rUs,aCrew) >= iShipCannonsNum;
	bAll = GetCargoGoods(rUs,aAll) >= iShipCannonsNum;
	bRange = GetCargoGoods(rUs,aRange) >= iShipCannonsNum;
	if(iThem == -1)
	{
		if(bRange) return aRange;
		if(bAll) return aAll;
		if(bHull) return aHull;
		if(bRig) return aRig;
		if(bCrew) return aCrew;
		return -1;
	}
	ref rThem = GetCharacter(iThem);
	ref rCannon = GetCannonByType(sti(rUs.Ship.Cannons.Type));
	//ref rShip = GetShipByType(GetCharacterShipType(&rUs));
	float range = stf(rCannon.FireRange) * AIShip_isPerksUse(rUs.TmpPerks.LongRangeShoot, 1.0, 1.15);
	//float oSP = stf(rUs.Ship.SP) / 100.0;
	float oHP = 1.0; if(GetCharacterShipHP(rUs)) oHP = makefloat(GetCurrentShipHP(rUs)) / makefloat(GetCharacterShipHP(rUs));
	//float tSP = stf(rThem.Ship.SP) / 100.0;
	float tHP = 1.0; if(GetCharacterShipHP(rThem)) tHP = makefloat(GetCurrentShipHP(rThem)) / makefloat(GetCharacterShipHP(rThem));
	int oCrewQ = GetCrewQuantity(rUs);
	int oMinCQ = GetMinCrewQuantity(rUs);
	//int tCrewQ = GetCrewQuantity(rThem);
	//int tMinCQ = GetMinCrewQuantity(rThem);
	float distance = Ship_GetDistance2D(&rUs, &rThem);
	if(distance < 0) distance = 1000; // NK for when dist < 0 05-04-15

	float rHull, rRig, rCrew, rAll, rRange;
	rHull = 0; rRig = 0; rCrew = 0; rAll = 0; rRange = 0;

	//trace(".");
	//trace("for character " + rUs.id + " determining new ammo");

	if (bRange && distance >= range * MAXRANGE) //if > max range, don't bother checking anything else. We need max range ammo.
	{
		//trace("out of range. change to maxrange");
		return aRange;
	}

	if(tHP < TARGET_HULL_MIN && bHull)
	{
		rHull = stf(ShipLookupTable.ammo.(stype).Hull.range);
		if (distance < range * rAll && frnd() < HULLCH) //if chance succeeds, and their hull is an eggshell...we'll hammer it!
		{
			//trace("tgt hull");
			return aHull;
		}
	}

	if(bCrew)
	{
		rCrew = stf(ShipLookupTable.ammo.(stype).Crew.range);
		if (distance < range * rAll && frnd() < CREWCH_ALL) //if chance succeeds, and we can hammer their crew...let's!
		{
			//trace("tgt crew");
			return aCrew;
		}
	}

	if(bRig)
	{
		rRig = stf(ShipLookupTable.ammo.(stype).Rig.range);
		if (distance < range * rRig)
		{
			if(oHP < HULL_PCT_CHAIN || oCrewQ < oMinCQ) { return aRig; } //if we're trying to run, knock out their rigging!
			if(CheckAttribute(rUs,"ship.maxpseedZ") && CheckAttribute(rThem,"ship.maxpseedZ"))
			{
				if(stf(rUs.ship.MaxSpeedZ) + CHAIN_SPEEDDIFF < stf(rThem.ship.MaxSpeedZ) && frnd() < CHAIN_SPEEDDIFF_CHANCE) //if we're at a speed disadvantage, ditto
				{
					//trace("tgt sail");
					return aRig;
				}
			}
		}
	}

	if (bAll)
	{
		rAll = stf(ShipLookupTable.ammo.(stype).All.range);
		if (distance < range * rAll)
		{
			//trace("use best-allround");
			return aAll;
		}
	}
	//trace("no checks passed, will default");
	if(bRange) return aRange;
	if(bHull) return aHull;
	if(bRig) return aRig;
	if(bAll) return aAll;
	if(bCrew) return aCrew;
	// NK & Mith<--
	// updated 04-09-15
	return -1;
}
// NK <-- 04-09-15

// NK --> 04-09-16
//gets the current time in seconds (roughly!) since loaded sea.
int GetSeaTime()
{
	ref pchar = GetMainCharacter();
	if(!CheckAttribute(pchar,"seatime")) return 0;
	return sti(pchar.seatime);
}
// 04-09-21
int AddSeaTimeToCurrent()
{
	// logit("AddSeaTimeToCurrent");
	ref pchar = GetMainCharacter();
	int st = GetSeaTime();
	int minutes = 0;
	if(!CheckAttribute(pchar,"lastupdateseatime")) pchar.lastupdateseatime = 0;
	if(sti(pchar.lastupdateseatime) + 1 <= st/60)
	{
		int oldhour = GetHour();
		minutes = TIMESCALAR_SEA * (st/60 - sti(pchar.lastupdateseatime));
		AddTimeToCurrent(0, minutes);
		pchar.lastupdateseatime = (st/60);
// KK -->
		if (CheckAttribute(PChar, "Ship.Cannons.fired_time") && CheckAttribute(PChar, "Ship.Cannons.reload_time")) {
			PChar.Ship.Cannons.fired_time = stf(PChar.Ship.Cannons.fired_time) + makefloat(minutes * 60);
		} else {
			for (int arc = 0; arc < 4; arc++)
			{
				string quadstr = GetQuadName(arc);
				if (CheckAttribute(PChar, "Ship.Cannons.Borts."+ quadstr + ".fired_time") && CheckAttribute(PChar, "Ship.Cannons.Borts." + quadstr + ".reload_time")) {
					PChar.Ship.Cannons.Borts.(quadstr).fired_time = stf(PChar.Ship.Cannons.Borts.(quadstr).fired_time) + makefloat(minutes * 60);
				}
			}
		}
// <-- KK
		if(oldhour != GetHour())
		{
			sNewExecuteLayer = SEA_EXECUTE;
			sNewRealizeLayer = SEA_REALIZE;
			// LDH this is where the weather is updated when on ship - 04Jan09
			bool oldIsNight = Whr_IsNight();
			bool oldIsRain = Whr_IsRain();		// LDH 20Feb09
			Whr_UpdateWeather(false);
			// LDH update the music if day/night changes - 20Jan09
			// turn off the rain sounds if it's no longer raining - 20Feb09
			if (Whr_IsNight() != oldIsNight || Whr_IsRain() != oldIsRain)
				SetSchemeForSea();
		}
	}
	return minutes;
}
// NK <--

void Ship_ActivateFirePlace()
{
	if(LAi_IsBoardingProcess() || ownDeckStarted()) return; // NK bugfix for boarding
	aref	arShipObject = GetEventData();
	aref	arCharacter = GetEventData();
	if(GetCharacterShipType(&arCharacter)==SHIP_BOAT || GetCharacterShipType(&arCharacter)==SHIP_NOTUSED) return;//MAXIMUS
	int		iFirePlaceIndex = GetEventData();
	string	sSoundName = GetEventData();
	float	fFireTime = GetEventData();

	aref	arPos; makearef(arPos, arCharacter.Ship.Pos);

	// LDH iSoundID will almost always be zero, probably because it's too far away to hear if on another ship - 25Mar09
	int iSoundID = Play3DSoundComplex(sSoundName, stf(arPos.x), 0.0, stf(arPos.z), true, false);
	string tmpstr = iFirePlaceIndex; arCharacter.fireplaces.(tmpstr) = iSoundID; // NK 05-04-19
	SendMessage(arShipObject, "llsslf", MSG_SHIP_ACTIVATE_FIRE_PLACE, iFirePlaceIndex, "ship_smoke", "ship_fire", iSoundID, fFireTime);

	// ccc firedrill
	if(IsMainCharacter(arCharacter) && !CheckAttribute(arCharacter, "Ship.Sink")) { // so this runs only for the player // KK
		DeleteAttribute(arCharacter,"firedrill"); // deletes the markerattribute that starts firedrill
		if (FIREDAMAGE > 1) {
			AddPerkToActiveList("FireOnShip"); // KK
			Log_SetStringToLog(TranslateString("","Fire! Execute firedrill procedure!")); // infomessage MAR18 // KK
			PlaySound("interface\notebook.wav"); // soundeffect MAR18
		}
	}
	// ccc firedrill end
}

void Ship_BranderDetonate()
{
	ref		rCharacter = GetCharacter(GetEventData());

	ref		rBranderBaseShip = GetShipByID(rCharacter.Ship.Type); // PS
	float	fBranderDistance = 2.5 * (30.0 + (8.0 - stf(rBranderBaseShip.Class)) * 40.0);
	float	fMaxDamage = 1000.0 + (8.0 - stf(rBranderBaseShip.Class)) * 1000.0;

	aref	arShipObjects[64];
	int		iNumShips = 1;

	if (!FindEntity(&arShipObjects[0], "ship")) { return; }// can't be
	while (FindEntityNext(&arShipObjects[iNumShips])) { iNumShips++; }

	// enumerate ship and do damage
	for (int i=0; i<iNumShips; i++)
	{
		if(i==SHIP_BOAT || i==SHIP_NOTUSED) continue;//MAXIMUS
		int iCharacterIndex = -1;
		SendMessage(arShipObjects[i], "le", MSG_SHIP_GET_CHARACTER_INDEX, &iCharacterIndex);
		if (iCharacterIndex == sti(rCharacter.index)) { continue; }
		ref rOtherCharacter = GetCharacter(iCharacterIndex);
		ref	rOtherBaseShip = GetShipByID(rOtherCharacter.Ship.Type); // PS
		float fDistance = Ship_GetDistance2D(rCharacter, rOtherCharacter);
		if (fDistance > fBranderDistance || fDistance < 0) { continue; } // NK for when dist < 0 05-04-15
		float fDamageMultiply = Bring2Range(1.0, 0.0, 10.0, fBranderDistance, fDistance);
		Ship_ApplyHullHitpoints(rOtherCharacter, fMaxDamage * fDamageMultiply, KILL_BY_SPY, sti(rBranderBaseShip.index));

		// fire random fire places
		int iNumFirePlaces = 0;
		SendMessage(&arShipObjects[i], "le", MSG_SHIP_GET_NUM_FIRE_PLACES, &iNumFirePlaces);

		// add move impulse to ship
		float x = stf(rOtherCharacter.Ship.Pos.x) - stf(rCharacter.Ship.Pos.x);
		float z = stf(rOtherCharacter.Ship.Pos.z) - stf(rCharacter.Ship.Pos.z);
		float fLen = stf(rOtherBaseShip.Class) * fDamageMultiply * (1.0 / sqrt(x * x + z * z));
		SendMessage(&arShipObjects[i], "llffffff", MSG_SHIP_ADD_MOVE_IMPULSE, false, x * fLen, 0.0, z * fLen, 0.0, 0.0, 0.0);
	}

	Ship_Detonate(rCharacter, true, true);
}

float Ship_GetDistance2D(ref rCharacter1, ref rCharacter2)
{
	//Levis trying to get the dutchman out of reach when submerged -->
	if(CheckAttribute(rCharacter1, "ship.SubmergeDutchman") || CheckAttribute(rCharacter2, "ship.SubmergeDutchman")) return DIST_NOSHIP;
	//Levis trying to get the dutchman out of reach when submerged <--
	// NK temp bugfix
	/*if(!CheckAttribute(rCharacter1,"pos")) trace("Char " + rCharacter1 + " has no ship.pos!");
	if(!CheckAttribute(rCharacter2,"pos")) trace("Char " + rCharacter2 + " has no ship.pos!");*/
	if(!CheckAttribute(rCharacter1,"ship.pos") || !CheckAttribute(rCharacter2,"ship.pos")) return -1.0; // NK 05-04-15
	return GetDistance2D(stf(GetAttribute(rCharacter1, "Ship.Pos.x")), stf(GetAttribute(rCharacter1, "Ship.Pos.z")), stf(GetAttribute(rCharacter2, "Ship.Pos.x")), stf(GetAttribute(rCharacter2, "Ship.Pos.z")));
}
// NK Ship_FindOtherBallType moved up to be near what calls it. 04-09-15

// event: indicate that ball is not enough for fire for main character
void Ship_NotEnoughBalls()
{
	bNotEnoughBalls = GetEventData();
}

int Ship_GetCurrentBallsNum()
{
	aref aCharacter = GetEventData();
	return GetCargoGoods(aCharacter,sti(aCharacter.Ship.Cannons.Charge.Type));
}

void Ship_SailDamage()
{
	float x, y, z;
	int iCharacterIndex = GetEventData();
	x = GetEventData();
	y = GetEventData();
	z = GetEventData();
	Play3DSound("sail_damage", x, y, z);
	Characters[iCharacterIndex].seatime.lasthit = GetSeaTime(); // NK 04-09-16, to set time when last hit
	if(CheckAttribute(Characters[iCharacterIndex], ".ship.LastBallCharacter") && sti(Characters[iCharacterIndex].ship.LastBallCharacter) != -1) Characters[sti(Characters[iCharacterIndex].ship.LastBallCharacter)].Ship.lasttgt = iCharacterIndex; // NK 04-09-22 to see who AI is attacking
}

void Ship_Ship2IslandCollision()
{
	float	fPower, fSlide, x, y, z;
	int		iOurCharacterIndex, iEnemyCharacterIndex, iTouchPoint;

	iOurCharacterIndex = GetEventData();
	iEnemyCharacterIndex = GetEventData();
	fPower = abs(GetEventData());
	fSlide = abs(GetEventData());
	iTouchPoint = GetEventData();
	x = GetEventData();
	y = GetEventData();
	z = GetEventData();

	ref rOurCharacter = GetCharacter(iOurCharacterIndex);
	if(!IsMainCharacter(rOurCharacter)) return; // PB: Collision damage for player ship only

	float fHP = (1.0 - fSlide) * fPower * 3.0;
	//Trace("Ship->Island touch: fpower = " + fPower + ", fHP = " + fHP + ", fSlide = " + fSlide);
	Ship_ApplyHullHitpoints(rOurCharacter, fHP, KILL_BY_ISLAND, -1);

	if (fPower > 1.0) { Play3DSound("coll_ship2rock", x, y, z); }
}

float Ship_GetAttackHP(int iCharacterIndex, float fDistance)
{
	float fAttackHP = 0.0;
	if (bSeaActive)
	{
		SendMessage(&AISea, "lafe", AI_MESSAGE_SHIP_GET_ATTACK_HP, &Characters[iCharacterIndex], fDistance, &fAttackHP);
	}
	return fAttackHP;
}

float Ship_GetHP(ref rCharacter) { return stf(rCharacter.Ship.HP); }

void Ship_Ship2ShipCollision()
{
	int		iOurCharacterIndex, iEnemyCharacterIndex, iTouchPoint;
	float	fPower, fSlide, x, y, z;

	iOurCharacterIndex = GetEventData();
	iEnemyCharacterIndex = GetEventData();
	fPower = abs(GetEventData());
	fSlide = abs(GetEventData());
	iTouchPoint = GetEventData();
	x = GetEventData();
	y = GetEventData();
	z = GetEventData();

	ref rOurCharacter = GetCharacter(iOurCharacterIndex);
//	if(!IsMainCharacter(rOurCharacter)) return; // PB: Collision damage for player ship only, GR: let NPC ships take damage

	float fHP = (1.0 - fSlide) * fPower * 20.0;
	//Trace("Ship->Ship touch: idx = " + iOurCharacterIndex + ", fpower = " + fPower + ", fHP = " + fHP + ", fSlide = " + fSlide);
	Ship_ApplyHullHitpoints(rOurCharacter, fHP, KILL_BY_TOUCH, iEnemyCharacterIndex);
	if (fPower>1.0) { Play3DSound("coll_ship2ship", x, y, z); }
}

void Ship_ApplyCrewHitpoints(ref rOurCharacter, float fCrewHP)
{
	// logit("Ship_ApplyCrewHitpoints");
	// PB: Cursed Coins -->
	ref ch;
	float damagescale = 1.0

	int CursedCrew = 0;
	if(Whr_IsNight() && GetCursedCoinCount()>0)
	{
		int crewQ = GetTotalCrewQuantity(rOurCharacter);
		ref loc = &locations[FindLocation("Tutorial_Deck")];
		if(bAllies(rOurCharacter))
		{
			for (int i = 1; i < COMPANION_MAX; i++)
			{
				if (GetCompanionIndex(GetMainCharacter(), i) < 0) continue;
				ch = GetCharacter(GetCompanionIndex(GetMainCharacter(), i));
				if(rOurCharacter.index == ch.index)
				{
					loc = &locations[FindLocation("Companion_Cabin_"+i)];
				}
			}
		}

		if(CheckAttribute(loc, "WeaponsLocker.items.cursedcoin"))
		{
			CursedCrew = loc.WeaponsLocker.items.cursedcoin;
			if(CursedCrew>crewQ)	CursedCrew = crewQ;
		}

		damagescale = (crewQ-stf(CursedCrew))/crewQ;
	}
	// PB: Cursed Coins <--

	// KK if(!CheckAttribute(rOurCharacter,"seatime.basecrewquantity")) rOurCharacter.ship.crew.quantity; // NK need to check 05-04-09
	rOurCharacter.seatime.lasthit = GetSeaTime(); // NK 04-09-16, to set time when last hit
	if(!CheckAttribute(rOurCharacter,"seatime.lastcrew")) rOurCharacter.seatime.lastcrew = rOurCharacter.ship.crew.quantity; // ditto, to set what crew was before loss
	//ref rBaseShip = GetShipByType(GetCharacterShipType(&rOurCharacter));
	float fMultiply;
	float fskillDefence = stf(rOurCharacter.TmpSkill.Defence); // KK
	int iskillDefence = GetShipSkill(rOurCharacter, SKILL_DEFENCE); // PB
	float fFirstAid = 1.0;
	if (USE_REAL_CANNONS)
	{
		fMultiply = Bring2Range(1.0, 0.5, 0.0, 1.0, fskillDefence); // KNB was from 1.0x to 0.2x damage
		if (sti(GetAttribute(rOurCharacter, "TmpPerks.BasicFirstAid")))			fFirstAid = 0.85;	// 15%
		if (sti(GetAttribute(rOurCharacter, "TmpPerks.AdvancedFirstAid")))	  	fFirstAid = 0.7;	// 30%
	}
	else
	{
		fMultiply = Bring2Range(1.0, 0.2, 0.0, 1.0, fskillDefence);
		if (sti(GetAttribute(rOurCharacter, "TmpPerks.BasicFirstAid")))			fFirstAid = 0.80;	// 20%
		if (sti(GetAttribute(rOurCharacter, "TmpPerks.AdvancedFirstAid")))	  	fFirstAid = 0.65;	// 35%
	}
	fMultiply = fMultiply * fFirstAid;
//NK -->
	//aref arship; makearef(arship, rOurCharacter.ship); // PRS3
	fMultiply *= (0.25 * (stf(rOurCharacter.Ship.Crew.Quantity) / makefloat(GetMinCrewQuantity(rOurCharacter)))); // PRS3
	fMultiply *= damagescale; // PB: Cursed Coins
// NK <--
	int casualties = makeint(fCrewHP * fMultiply); // PB
	float fNewCrewQuantity = stf(rOurCharacter.Ship.Crew.Quantity) - casualties;
	float f5Percent = makefloat(GetMinCrewQuantity(rOurCharacter)) * 0.05; // PRS3
	if (fNewCrewQuantity < f5Percent) fNewCrewQuantity = f5Percent;
	if (fNewCrewQuantity < 1.0) fNewCrewQuantity = 1.0;
// KK & PB -->
	if (IsMainCharacter(rOurCharacter) || IsCompanion(rOurCharacter)) {
		int wounded = casualties - randnorm(casualties, iskillDefence);
		if (sti(GetAttribute(rOurCharacter, "TmpPerks.AdvancedFirstAid"))) 		{wounded += 2.0;}	// 2 more wounded instead of dead
		else {if (sti(GetAttribute(rOurCharacter, "TmpPerks.BasicFirstAid")))		 wounded += 1.0;}	// 1
		wounded = makeint(wounded + 0.5);	// round appropriately after FirstAid perks have added a fraction
		if (wounded > casualties) wounded = casualties;
		if (wounded > 0) AddCharacterWoundedCrew(rOurCharacter, wounded);
		else wounded = 0;
//trace("Ship_ApplyCrewHitpoints: casualties="+casualties+", iskillDefence="+iskillDefence +", wounded="+wounded);
	}
	SetCrewQuantity(rOurCharacter, fNewCrewQuantity);
// <-- KK & PB
}

void Ship_ApplyHullHitpoints(ref rOurCharacter, float fHP, int iKillStatus, int iKillerCharacterIndex)
{
	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	float fCurHP;
	float fMinus = 0.0;
	float fPlus = 0.0;

	if (bSeaReloadStarted) { return; }
	if (fHP <= 0.0) { return; }

	if (bNoDamage2Us)
	{
		ref rMainCharacter = GetMainCharacter();
		if (sti(rOurCharacter.index) == GetMainCharacterIndex()) { return; }
		if (FindFellowTravellers(rMainCharacter, rOurCharacter) == FELLOWTRAVEL_COMPANION) { return; }
	}

	if (LAi_IsImmortal(rOurCharacter)) { return; }
	rOurCharacter.seatime.lasthit = GetSeaTime(); // NK 04-09-16, to set time when last hit
	// KNB -- reduced perk effect on hull damage
	if(USE_REAL_CANNONS)
	{
		if (iKillerCharacterIndex >= 0)
		{
			if (sti(Characters[iKillerCharacterIndex].TmpPerks.HullDamageUp)) fPlus = 0.1; //0.15
			if (sti(Characters[iKillerCharacterIndex].TmpPerks.CannonProfessional)) fPlus = 0.2; //0.3
		}

		if (sti(GetAttribute(rOurCharacter, "TmpPerks.BasicDamageControl"))) 		fMinus = 0.08; //0.15
		if (sti(GetAttribute(rOurCharacter, "TmpPerks.AdvancedDamageControl")))	  	fMinus = 0.15; //0.25
		if (sti(GetAttribute(rOurCharacter, "TmpPerks.ProfessionalDamageControl")))	fMinus = 0.25; //0.40
	}
	// KNB <--
	else
	{
		if (iKillerCharacterIndex >= 0)
		{
			if (sti(Characters[iKillerCharacterIndex].TmpPerks.HullDamageUp)) fPlus = 0.15;
			if (sti(Characters[iKillerCharacterIndex].TmpPerks.CannonProfessional)) fPlus = 0.3;
		}

		if (sti(rOurCharacter.TmpPerks.BasicDamageControl))		fMinus = 0.15;
		if (sti(rOurCharacter.TmpPerks.AdvancedDamageControl))		fMinus = 0.25;
		if (sti(rOurCharacter.TmpPerks.ProfessionalDamageControl))	fMinus = 0.40;
	}

	if (LAi_IsDead(rOurCharacter)) { return; }
	// NK can qty 05-04-18 -->
	fCurHP = stf(rOurCharacter.Ship.HP) //- fHP * (1.0 + fPlus - fMinus);
	//Trace("idx = " + rOurCharacter.index + ", fCurHP = " + fCurHP);
	fHP = fHP * (1.0 + fPlus - fMinus);

	if(iKillStatus == KILL_BY_BALL) // cannons are only destroyed by incoming projectiles, not ramming
	{
		float chance = CAN_DESTROY_CHANCE / 0.008 * fHP / GetCharacterShipHP(&rOurCharacter) * pow2(makefloat(8-GetCharacterShipClass(&rOurCharacter)),1.5) / 5;
		float fOurAngle = stf(rOurCharacter.Ship.Ang.y);
		float fBallAngle;
		if(CheckAttribute(AIBalls,"Dir")) fBallAngle = clampangle(stf(AIBalls.Dir)+PI); // inverse of ball angle because ball is incoming
		else fBallAngle = clampangle(fOurAngle+(1.0-rand(1)*2.0) * PId2); // default to broadside on
		int quad = quadrantG(fOurAngle, fBallAngle);
		bool israke = quad == 0 || quad == 2;
		chance *= 1.0 + makefloat(israke) * 0.25; // extra 25% chance if raking

//KB - Tuning Ships - effect of Bronze cannons
//if ( sti(rOurCharacter.index) == 0 ) {Trace("KB - chance before " + chance);}
		aref temparef;
		int testtune=0;
		makearef(temparef,rOurCharacter.ship);
		if (CheckAttribute(temparef,"tune")) {
			testtune = 1;
			makearef(temparef,rOurCharacter.ship.tune);
			if(CheckAttribute(temparef,"bcannons")) {
				if ( sti(rOurCharacter.ship.tune.bcannons.on) == 1 ) {
//Trace("KB Tuning - Critical because bcannons");
					chance = chance * makefloat(BCCRITICALCANNON);
				}

			}
		}
//if ( sti(rOurCharacter.index) == 0 ) {Trace("KB - chance after " + chance);}
//KB - END Tuning Ships - effect of Bronze cannons

		string qdstr = GetQuadName(quad);
		int fix;

		bool dest = frnd() < chance;
		if(CheckAttribute(rOurCharacter,"cannonhit.critchance")) { if(!dest) { dest = frnd() < CAN_DESTROY_ON_CRIT; } } // higher chance for crits. // TIH attribute renamed to critchance, and IS.h setting typo fixed Nov13'06

		if(dest)
		{
			aref arcan; makearef(arcan, rOurCharacter.ship.cannons.borts.(qdstr));
			int curnum = sti(arcan.qty);
			if(!curnum)
			{
				if(frnd() < CAN_DESTROY_OTHERARC || israke)
				{
					quad += 2; if(quad >= 4) quad -= 4; // get opposite arc
					qdstr = GetQuadName(quad);
					makearef(arcan, rOurCharacter.ship.cannons.borts.(qdstr));
					curnum = sti(arcan.qty);
				}
				if(!curnum && israke) // if raking, can damage any arc if not first, rather than just first or opposite
				{
					for(quad = 0; quad < 4; quad++)
					{
						qdstr = GetQuadName(quad);
						makearef(arcan, rOurCharacter.ship.cannons.borts.(qdstr));
						curnum = sti(arcan.qty);
						if(curnum) break;
					}
				}
			}
			if(curnum)
			{
				arcan.qty = curnum - 1;
				fix = 0;
				if(frnd() < Bring2Range(CAN_FIXABLE_MIN, CAN_FIXABLE_MAX, 0.0, 1.2, stf(rOurCharacter.TmpSkill.Repair) + (fMinus/2.0)))
				{
					if(CheckAttribute(arcan,"fix")) fix = sti(arcan.fix);
					fix++;
					arcan.fix = fix;
				}
				Ship_SetCannonQtyByCrew(&rOurCharacter);
				traceif("Canloss: char " + rOurCharacter.id + " of ship " + rOurCharacter.ship.name + " has lost a gun from arc " + quad+ " (" + GetQuadText(quad) + "). Fix: " + fix);
				// FX and logging section
				float x,y,z;
				if(CheckAttribute(rOurCharacter,"cannonhit"))
				{
					x = stf(rOurCharacter.cannonhit.x);
					y = stf(rOurCharacter.cannonhit.y);
					z = stf(rOurCharacter.cannonhit.z);
				}
				else
				{
					x = stf(rOurCharacter.ship.pos.x);
					y = stf(rOurCharacter.ship.pos.y);
					z = stf(rOurCharacter.ship.pos.z);
				}
				if(IsMainCharacter(rOurCharacter)) { // KK
					PlaySound("interface\notebook.wav"); // like CCC's firedrill
					logit(TranslateString("","We lost a cannon! From the") + " " + TranslateString("",GetQuadText(quad)) + " " + XI_ConvertString("arc") + "!" + stringret(fix," " + TranslateString("","We think we can fix it, captain."), ""));
				}
				else
				{
					if(iKillerCharacterIndex == GetMainCharacterIndex())
					{
						logit(TranslateString("","We knocked out one of") + " " + GetMyShipNameShow(rOurCharacter) + TranslateString("","'s") + " " + XI_ConvertString(GetQuadText(quad)) + " " + TranslateString("","guns!")); // KK
						PlaySound("objects\shipcharge\hurrah.wav");
					}
				}
				Play3DSound("cannon_explosion", x, y, z); // KK
				if(AUTO_SKILL_SYSTEM)
				{
				// LDH divide experience between cannons and accuracy - 27Dec08
					Ship_AddDelayedCumXP(GetCharacter(iKillerCharacterIndex), "Cannons", 750);
					Ship_AddDelayedCumXP(GetCharacter(iKillerCharacterIndex), "Accuracy", 750);
					Ship_AddDelayedCumXP(rOurCharacter, "Defence", 500);
					Ship_AddDelayedCumXP(rOurCharacter, "Cannons", 250);
					Ship_AddDelayedCumXP(rOurCharacter, "Accuracy", 250);
				}
				Ship_Serious_Boom(x, y, z);
			}
		}
		// multiplier
		fHP *= CANNON_DAMAGE_SCALAR;
	}
	fCurHP -= fHP;
	// NK <--
	if (fCurHP <= 0.0)
	{
		fCurHP = 0.0;
		//Trace("Player dead = " + rOurCharacter.index + ", id = " + rOurCharacter.id);
		ShipDead(sti(rOurCharacter.index), iKillStatus, iKillerCharacterIndex);
	}

	//LanguageCloseFile(tmpLangFileID);
	rOurCharacter.Ship.HP = fCurHP;
}

void Ship_AddDelayedCumXP(ref rCharacter, string ExpName, int iExp)
{
	if(!CheckAttribute(rCharacter,"delayedxp."+ExpName))
	{
		PostEvent("proc_ship_adddelayedcumxp",2000,"ls",sti(rCharacter.index),ExpName);
	}
	int xp = iExp;
	if(CheckAttribute(rCharacter,"delayedxp."+ExpName)) xp += sti(rCharacter.delayedxp.(ExpName));
	rCharacter.delayedxp.(ExpName) = xp;
}

void proc_ship_adddelayedcumxp()
{
	int cidx = GetEventData();
	string ExpName = GetEventData();
	ref chref = GetCharacter(cidx);
	Ship_AddCharacterExpChar(chref, ExpName, sti(chref.delayedxp.(ExpName)));
	DeleteAttribute(chref,"delayedxp."+ExpName);
}

void Ship_AddCharacterExp(ref rCharacter, int iExpQuantity)
{
	// NK -->
	bool t = IsCompanion(rCharacter);
	bool ns;
	if(!t)
	{
		ns = CheckAttribute(rCharacter,"donotshowXP");
		if(!ns) { rCharacter.donotshowXP = true; }
	}
	// NK <--
	AddCharacterExp(rCharacter, iExpQuantity);
	if(!t){ if(!ns) { DeleteAttribute(rCharacter,"donotshowXP"); } } // NK

	if (sti(rCharacter.index) == GetMainCharacterIndex())
	{
		fSeaExp = fSeaExp + iExpQuantity;
	}
}

void ShipDead(int iDeadCharacterIndex, int iKillStatus, int iKillerCharacterIndex)
{
	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	ref rDead, rKillerCharacter, rMainCharacter, rBaseShip, rKillerBaseShip;

	string sLogEntry; // Sulan
	string sLogTitle; // Sulan
	string sSunkShipType;
	string sSunkString;

	// LDH added trace for problems here 29AUG06
//	trace("ShipDead: iDeadCharacterIndex = " + iDeadCharacterIndex + ", iKillStatus = " + iKillStatus + ", iKillerCharacterIndex = " + iKillerCharacterIndex);

	rDead = GetCharacter(iDeadCharacterIndex);
	rBaseShip = GetShipByID(rDead.Ship.Type); // PS
	sSunkShipType = XI_ConvertString(rBaseShip.SName);
	aref arship; makearef(arship, rDead.ship); // PRS3
	aref arkship;

	if (iKillerCharacterIndex != -1)
	{
		rKillerCharacter = GetCharacter(iKillerCharacterIndex);
		rKillerBaseShip = GetShipByID(rKillerCharacter.Ship.Type); // PS
		makearef(arkship, rKillerCharacter.ship); // PRS3
	}

	rMainCharacter = GetMainCharacter();
	int iQuantity = GetCompanionQuantity(rMainCharacter);

	float fX = stf(rDead.Ship.Pos.x);
	float fY = stf(rDead.Ship.Pos.y);
	float fZ = stf(rDead.Ship.Pos.z);

	rDead.Ship.HP = 0;
	rDead.Killer.Status = iKillStatus;
	rDead.Killer.Index = iKillerCharacterIndex;

	LAi_SetCurHP(rDead, 0.0);
	//LAi_KillCharacter(rDead);

// KK -->
	if (CheckAttribute(rDead, "curshipnum")) {
		Ships[sti(rDead.curshipnum)] = -1;
		DeleteAttribute(rDead, "curshipnum");
	}
// <-- KK

	bool bDeadCompanion = IsCompanion(rDead);

	int iExp = 0;
	if (iKillStatus != KILL_BY_OWNER && iKillerCharacterIndex != -1) { iExp = 2 * MakeInt(makefloat(GetCharacterShipHP(rDead)) * makefloat(GetCharacterShipClass(rKillerCharacter)) / makefloat(GetCharacterShipClass(rDead))); } // PRS3 // KK
	// NK 04-09-16 -->
	if(iExp>0)
	// mod 04-09-22 to apply to other ships too
	{
		ref schr;
		float tmped = 0; if(CheckAttribute(rKillerCharacter,"seatime.enemydead")) tmped = stf(rKillerCharacter.seatime.enemydead);
		float origed = makefloat(GetCharacterShipClass(rKillerCharacter)) / makefloat(GetCharacterShipClass(rDead)) * CLASS_SCALAR_FOR_MORALE;
		tmped += origed;
		rKillerCharacter.seatime.enemydead = tmped;
		for(int s = 0; s < iNumShips; s++)
		{
			if(Ships[s] < 0 || Ships[s] == iDeadCharacterIndex) continue; // KK
			schr = GetCharacter(Ships[s]);
			if(SeaAI_GetRelation(iDeadCharacterIndex, Ships[s]) == RELATION_ENEMY)
			{
				tmped = 0;
				if(CheckAttribute(schr,"seatime.enemydead")) tmped = stf(schr.seatime.enemydead);
				tmped += origed * CLASS_SCALAR_FOR_MORALE_ORIG_TO_OTHER + makefloat(GetCharacterShipClass(schr)) / makefloat(GetCharacterShipClass(rDead)) * CLASS_SCALAR_FOR_MORALE_OTHER;
				schr.seatime.enemydead = tmped;
			}
		}
	}
	// NK <--

	bool bCompanion = false;
	if (iKillerCharacterIndex != -1) { bCompanion = IsCompanion(rKillerCharacter); }

	if (bCompanion && bDeadCompanion) { iExp = 0; }

	int iNation = sti(rDead.nation);
	// LDH -->
	if(iNation == NEUTRAL_NATION && CheckAttribute(rDead, "oldnation"))
	{
		iNation = sti(rDead.oldnation); // NK surrender 05-04-20
	}
	// LDH <--
	bool bRealKill	= false;
	bool bHandofGod	= false;
	switch (iKillStatus)
	{
		case KILL_BY_TOUCH:
			if (iKillerCharacterIndex != -1) { bRealKill = true; }
		break;
		case KILL_BY_BALL:
			bRealKill = true;
		break;
		case KILL_BY_ABORDAGE:
			bRealKill = true;
		break;
	}

	// Ship sunk log
	if (iDeadCharacterIndex != GetMainCharacterIndex())
	{
		// TIH --> to prevent errors when ship is killed by rocks
		string sKillShipType = ""; // PS
		string sKillShipName = "";

		Group_UpdateGroup(rDead); // KK	// LDH moved from below

		// LDH It is possible to get bRealKill true when iKillerCharacterIndex is -1 - 24Mar09
		if (bRealKill == true && iKillerCharacterIndex > -1 && CheckAttribute(rKillerCharacter, "Ship.Type") == true) { // LDH added iKillerCharacterIndex - 24Mar09 // KK
			rKillerBaseShip = GetShipByID(rKillerCharacter.Ship.Type);
			sKillShipType = XI_ConvertString(rKillerBaseShip.SName); // PS
// KK -->
			if (rKillerCharacter.ship.type == SHIP_FORT_NAME)
				sKillShipName = GetMySimpleName(rKillerCharacter) + " (" + TranslateString("",FindTownName(rKillerCharacter.town)) + " " + TranslateString("","Fort Commandant") + ")";
			else
				sKillShipName = GetMySimpleName(rKillerCharacter) + " (" + TranslateString("", "captain") + " " + TranslateString("", "of") + " " + sKillShipType + " " + GetMyShipNameShow(rKillerCharacter) + ")";
// <-- KK
		} else {
			sKillShipName = "" + TranslateString("","hand of god");
			bHandofGod = true;
		}
		// TIH <--

		if (bCompanion && !bDeadCompanion && bRealKill)
		{
			sSunkString = sSunkShipType + " " + GetMyShipNameShow(rDead) + " " + TranslateString("","has been sunk by") + " " + sKillShipName + "."; // KK
			if (iExp > 0) sSunkString = sSunkString + " " + TranslateString("","Gained") + " " + iExp + " " + TranslateString("","Total XP") + "."; // KK
		} else {
			if ( bHandofGod && rand(100)>95 ) { // TIH easteregg
				sSunkString = sSunkShipType + " " + GetMyShipNameShow(rDead) + " " + TranslateString("","has been sunk by the") + " " + TranslateString("","hand of god") + TranslateString("", ". God gained") + " " + (1000+rand(2000)) + " " + TranslateString("","Total XP") + ".";
			} else {
				sSunkString = sSunkShipType + " " + GetMyShipNameShow(rDead) + " " + TranslateString("","has been sunk by") + " " + sKillShipName + "."; // KK
			}
		}
		if (iRealismMode == 0 || Ship_GetDistance2D(rMainCharacter, rDead) < GetVisibilityRange(1)) { // KK: Ship sinking can be seen from LONG range
			Log_SetStringToLog(sSunkString);
			if (SeaAI_GetRelation(iDeadCharacterIndex, rMainCharacter) == RELATION_ENEMY) PlaySound("objects\abordage\abordage_wining.wav"); // NK cheers
		}
		if(!CheckAttribute(rDead,"ShipMoney")) rDead.ShipMoney = 0; // NK 04-11
		if (iKillStatus == KILL_BY_ABORDAGE) {
			AddMoneyToCharacter(rKillerCharacter, sti(rDead.ShipMoney));
			//Log_SetStringToLog(XI_ConvertString("Gained") + " " + rDead.ShipMoney + " " + XI_ConvertString("gold!"));
		} // NK
		if (bHandofGod && IsTrader(rDead)) // KK
		{
			rMainCharacter.quest.generate_convoy_quest.storm = true;
		}
	}

	if (bRealKill && iKillerCharacterIndex != -1)
	{
		// PB: Corrected so you get points for surrendered ships too -->
		bool bGetPoints = false;
		if (SeaAI_GetRelation(iDeadCharacterIndex, iKillerCharacterIndex) == RELATION_ENEMY)	bGetPoints = true;
		if (CheckAttribute(rDead, "surrendered") == true && sti(rDead.surrendered) == 1)		bGetPoints = true;
		// PB: Corrected so you get points for surrendered ships too <--
		if (bGetPoints)
		{
			if (bCompanion)
			{
				for (int i=0; i<COMPANION_MAX; i++)
				{
					int iIndex = GetCompanionIndex(rMainCharacter, i);
					if (iIndex >= 0)
					{
						if(AUTO_SKILL_SYSTEM)
						{
							// LDH divide experience between cannons and accuracy - 27Dec08
							int curAdd = makeint(makeint(iExp / iQuantity)/2);
							AddPartyExpChar(&Characters[iIndex], "Sailing" , curAdd); // KK was "&Characters[i]" (???)
							AddPartyExpChar(&Characters[iIndex], "Cannons" , curAdd/2); // KK
							AddPartyExpChar(&Characters[iIndex], "Accuracy", curAdd/2); // KK
						}
						else
						{
							AddPartyExp(&Characters[iIndex], iExp / iQuantity); // KK
						}
					}
				}
				// RM -->
				bool bPirated = false;
				if (CheckAttribute(rDead, "skipRM"))
				{
					DeleteAttribute(rDead, "skipRM");
					DeleteAttribute(rDead, "betrayed");
				}
				else
				{
					float points  = 1.0;
					if(CheckAttribute(rDead,"Points")) points = stf(rDead.Points);
					string ship_type = "";
					if (CheckAttribute(rDead,"FantomType")) ship_type = TranslateString("",rDead.FantomType + "_ship");
					TraceAndLog(TranslateString("","Type") + ": " + ship_type + ". " + TranslateString("","Points") + ": " + points);	// LDH 31Jan09
					if (CheckAttribute(rDead, "betrayed"))	rMainCharacter.traitor = true; // PB: Temporary attribute, will be deleted in the next function
					bPirated = UpdateRMRelation(rMainCharacter, iNation, points);
				}
				// RM <--
				
				// Sulan : Ship's log -->
				sLogTitle="Sunk a "+sSunkShipType;
				switch (iKillStatus)
				{
					case KILL_BY_TOUCH:
						sLogEntry = GetLogTime()+" we encountered the "+GetMyShipNameShow(rDead)+", a "+sSunkShipType+" flying "+GetNationDescByType(iNation)+" colours while under "+GetNationDescByType(GetCurrentFlag())+" flag ourselves.\nWe closed in on the ship and fired a broadside. In the following battle their captain tried to evade our cannonfire and almost escaped with a risky maneuver. The battle was ended by the "+GetMyShipNameShow(rKillerCharacter)+" ramming their ship. The hull shattered and the "+GetMyShipNameShow(rDead)+" sank like a stone within minutes.";
						if (bPirated) sLogEntry +=" This was not considered to be a legal attack.";
						if (abs(sti(rDead.Ship.Crew.Quantity))>0) sLogEntry +="\nAbout "+abs(sti(rDead.Ship.Crew.Quantity))+" sailors followed her to Davy Jones.";
					break;
					case KILL_BY_BALL:
						sLogEntry = GetLogTime()+" we encountered the "+GetMyShipNameShow(rDead)+", a "+sSunkShipType+" flying "+GetNationDescByType(iNation)+" colours while under "+GetNationDescByType(GetCurrentFlag())+" flag ourselves.\nWhen they were in reach of our cannons, we opened fire. Our cannons tore their sails to tatters and shattered their hull. After a ferocious battle, the "+GetMyShipNameShow(rKillerCharacter)+" fired her cannons a last time at the "+sSunkShipType+". Its hull was already heavily damaged from a previous broadside and the ship sank like a stone.";      
						if (bPirated) sLogEntry +=" This was not considered to be a legal attack.";
						if (abs(sti(rDead.Ship.Crew.Quantity))>0) sLogEntry += "\nAbout "+abs(sti(rDead.Ship.Crew.Quantity))+" sailors went down with her to Davy Jones.";
					break;
					case KILL_BY_ABORDAGE:
						sLogEntry = GetLogTime()+" we encountered the "+GetMyShipNameShow(rDead)+", a "+sSunkShipType+" flying "+GetNationDescByType(iNation)+" colours while under "+GetNationDescByType(GetCurrentFlag())+" flag ourselves.\n";
						if (CheckAttribute(rDead, "surrendered") == true && sti(rDead.surrendered) == 1)
						{
							sLogEntry += "When we opened fire, they tried to escape, but we chased them and finally were in reach for boarding, when the cowards raised the white flag and surrendered the ship. We brought our ship alongside and boarded.";
						}
						else
						{
							sLogEntry += "Our cannons gave them a warm and hearty welcome when we closed for battle. Once they were in reach of our grappling hooks, we boarded the ship and I defeated the captain.";
						}
						if (bPirated) sLogEntry +=" This was not considered to be a legal attack.";
						sLogEntry += "\nWe plundered her";
						if (CheckAttribute(rDead,"ShipMoney")) sLogEntry += ", moved the "+rDead.ShipMoney+" gold from their ship's chest to ours";
						sLogEntry += " and sent the "+GetMyShipNameShow(rDead)+" down to Davy Jones.";
						if (abs(sti(rDead.Ship.Crew.Quantity))>0) sLogEntry += "\nAbout "+abs(sti(rDead.Ship.Crew.Quantity))+" sailors accompanied her on her journey.";
						sLogEntry += "\n \nThe "+GetMyShipNameShow(rDead)+" was loaded with the following cargo:\n"+GetCargoList(rDead);
					break;
				}
				WriteNewLogEntry(sLogTitle,sLogEntry, "Battle", true);
				UpdateStatistics("ShipsSunk",1);
				// Sulan : Ship's log <--
			}
			else
			{
				if(AUTO_SKILL_SYSTEM)
				{
					// LDH divide experience between cannons and accuracy - 27Dec08
					AddPartyExpChar(rKillerCharacter, "Sailing" , makeint(iExp/2));
					AddPartyExpChar(rKillerCharacter, "Cannons" , makeint(iExp/4));
					AddPartyExpChar(rKillerCharacter, "Accuracy", makeint(iExp/4));
				}
				else
				{
					AddCharacterExp(rKillerCharacter, iExp);
				}
			}
		}
	}

	if (rand(10) >= 6 && GetCharacterShipClass(&rDead) <= 6) // PRS3
	{
		bool bDetonate = false;
		switch (iKillStatus)
		{
			case KILL_BY_BALL:	bDetonate = true; break;
			case KILL_BY_SPY:	bDetonate = true; break;
		}
		bool bdosmall = false; if(CheckAttribute(rDead,"explosion")) { bdosmall = true; DeleteAttribute(&rDead,"explosion"); } // NK for death from fire explosion 05-04-19
		if (bDetonate) { Ship_Detonate(rDead, true, bdosmall); } // NK ditto
	}

	// set attributes for sinking effect
	rDead.Ship.Sink = "";
	aref aSink; makearef(aSink, rDead.Ship.Sink);
	// PB: Capsizing -->
	if(!CheckAttribute(rDead, "Capsize.Angle"))
	{
		// Halfman -->
		aSink.Speed.y = 0.25  + (frnd() * 0.05 ); // speed of sink y
		aSink.Speed.x = 0.021 * (frnd() * 2.0 - 1.0); // speed sink angle rotate around x
		aSink.Speed.z = 0.04  * (frnd() * 2.0 - 1.0); // speed sink angle rotate around z
		// Halfman <--
	}
	else
	{
		if(rDead.Capsize.Angle > 0) // Capsizing to Starboard
		{
			aSink.Speed.y =  0.25  + (frnd() * 0.05 ); // speed of sink y
			aSink.Speed.x =  0.025 - 0.05 * frnd(); // speed sink angle rotate around x
			aSink.Speed.z = -0.15; // speed sink angle rotate around z
		}
		else // Capsizing to Port
		{
			aSink.Speed.y = 0.25 + (frnd() * 0.05 ); // speed of sink y
			aSink.Speed.x =  0.025 - 0.05 * frnd(); // speed sink angle rotate around x
			aSink.Speed.z =  0.15; // speed sink angle rotate around z
		}
		DeleteAttribute(rDead, "Capsize");
	}
	// PB: Capsizing <--

	if (iDeadCharacterIndex == GetMainCharacterIndex())
	{
		SeaCameras_SetDieCamera();
		FadeOutMusic(2000);
		PlayStereoOGG("music_ship_dead");
		PostEvent(GAME_OVER_EVENT, 15000);
	}
	if(!bHandofGod && GetCharacterIndex(rKillerCharacter.id)!=GetMainCharacterIndex() && CheckAttribute(&characters[iDeadCharacterIndex],"id") && characters[iDeadCharacterIndex].id=="Quest trader")
	{
		string Add = "d_";
		if(Rand(10)<Rand(10)) Add = "d_sw_";
		rMainCharacter.quest.generate_convoy_quest.attack = XI_ConvertString(Add+GetNationDescByType(sti(rKillerCharacter.nation)));
	}

	// Boatswain sounds MOD - Amokachi // KK -->
	/*if(ENABLE_EXTRA_SOUNDS == 1 && iDeadCharacterIndex != GetMainCharacterIndex()) { // added by KAM after build 11 - LDH index 21Mar09
		// LDH this sound will be played later in Ship_UpdateParameters() if necessary for player ship
		Play3DSound("#ship_sinking", fX, fY, fZ);
	}*/						// added by KAM after build 11 // <-- KK

	Play3DSound("ship_sink", fX, fY, fZ);

	// Message to AI
	SendMessage(AISea, "la", AI_MESSAGE_CHARACTER_DEAD, rDead);

	// Event
	Event(SHIP_DEAD, "l", iDeadCharacterIndex);
	//LanguageCloseFile(tmpLangFileID);
}

// START MOD Code by Stone-D : 22/07/2003
bool ShipTaken(int iDeadCharacterIndex, int iKillStatus, int iKillerCharacterIndex)
{
// KK -->
	if (iDeadCharacterIndex   < 0) return false;
	if (iKillerCharacterIndex < 0) return false;

	ref rKillerCharacter, rKillerBaseShip;
	ref rDead = GetCharacter(iDeadCharacterIndex);
	rDead.Killer.Index = iKillerCharacterIndex;
	ref rBaseShip = GetShipByID(rDead.Ship.Type); // PS
	ref rMainCharacter = GetMainCharacter();

	int iExp = 0;
	bool bCompanion = false;
	bool bPirated = false;
	bool bDeadCompanion = IsCompanion(rDead);
	int HP = 0;
	int class1 = 0;
	int class2 = 0;
	ref mainchar = GetMainCharacter();
	ref rCapturedShip = GetShipByID(mainchar.CapturedShipData.Type);
// <-- KK

	if (iKillerCharacterIndex != -1)
	{
		rKillerCharacter = GetCharacter(iKillerCharacterIndex);
// KK -->
		rKillerBaseShip = GetShipByID(rKillerCharacter.Ship.Type); // PS
		HP = sti(mainchar.CapturedShipData.HP);
		class1 = GetCharacterShipClass(rKillerCharacter)
		class2 = sti(rCapturedShip.Class);
		iExp = makeint((makefloat(HP * class1)) / (makefloat(class2) / 2.0)); // PRS3
// <-- KK
		bCompanion = IsCompanion(rKillerCharacter);
		if (CheckAttribute(rDead,"ShipMoney")) AddMoneyToCharacter(rKillerCharacter, sti(rDead.ShipMoney)); // NK
	}

	if (bCompanion && bDeadCompanion) { iExp = 0; }

	if (iDeadCharacterIndex != GetMainCharacterIndex())
	{
// KK -->
		string sSunkShipName = GetMyShipNameShow(rDead); // PB: was "mainchar.CapturedShipData.Name"
		string sSunkShipType = XI_ConvertString(rCapturedShip.SName); // PS
		string sKillShipType = XI_ConvertString(rKillerBaseShip.SName); // PS
		string sLogTitle; // Sulan
		string sLogEntry; // Sulan
		if(IsTrader(rDead))
		{
			rMainCharacter.quest.generate_convoy_quest.board = true;
		}
// <-- KK

		if(bCompanion && !bDeadCompanion)
		{
			// RM -->
			int iNation = sti(rDead.nation);
			if (iNation == NEUTRAL_NATION) iNation = sti(rDead.oldnation); // NK surrender 05-04-20
			if (CheckAttribute(rDead, "skipRM"))
			{
				DeleteAttribute(rDead, "skipRM");
				DeleteAttribute(rDead, "betrayed");
			}
			else
			{
				float points  = 1.0;
				if (CheckAttribute(rDead,"Points")) points = stf(rDead.Points);
				string ship_type = "";
				if (CheckAttribute(rDead,"FantomType")) ship_type = TranslateString("",rDead.FantomType + "_ship");
				TraceAndLog(TranslateString("","Type") + ": " + ship_type + ". " + TranslateString("","Points") + ": " + points);	// LDH 31Jan09
				if (CheckAttribute(rDead, "betrayed"))	rMainCharacter.traitor = true; // PB: Temporary attribute, will be deleted in the next function
				bPirated = UpdateRMRelation(rMainCharacter, iNation, points);
			}
			// RM <--
			
			// Sulan: Ship's log -->
			sLogTitle = "Captured a "+sSunkShipType;
			sLogEntry = GetLogTime()+" we encountered the "+GetMyShipNameShow(rDead)+", a "+sSunkShipType+" flying "+GetNationDescByType(iNation)+" colours while under "+GetNationDescByType(GetCurrentFlag())+" flag ourselves.\n";
			if(CheckAttribute(rDead, "surrendered") == true && sti(rDead.surrendered) == 1)
			{
				sLogEntry += "When we opened fire, they tried to escape, but we chased them and finally were in reach for boarding, when the cowards raised the white flag and surrendered the ship. We brought our ship alongside and boarded.";
			}
			else
			{
				sLogEntry += "When they were in reach of our cannons, we fired and a ferocious sea battle began. Finally we brought our ship alongside and boarded. After a bloody deckfight I defeated the enemy captain in a duel, thus capturing the ship.";      
			}
			if (bPirated) sLogEntry +=" This was not considered to be a legal attack.";
			sLogEntry += "\n"+GetSailStatus(rDead)+" "+GetHullStatus(rDead)+"\n \n";
			sLogEntry += "The "+sSunkShipName+" was loaded with the following cargo:\n"+GetCargoList(rDead);
			if (CheckAttribute(rDead,"ShipMoney")) sLogEntry += "Additionally we found "+rDead.ShipMoney+" gold in the ship's chest.";
			WriteNewLogEntry(sLogTitle,sLogEntry, "Battle", true);)
			UpdateStatistics("ShipsCaptured",1);
			// <-- Sulan
		} // NK
	}
	return bPirated;
}
// END MOD Code by Stone-D : 22/07/2003

void Ship_SailHitEvent()
{
}

string GetSailStatus(ref rShip)
{
	string sRet = "";
	if(GetSailPercent(rShip)>=90) sRet = "The sails were in nearly perfect condition. Sometimes not using cannons pays off."; 
	if(GetSailPercent(rShip)<90) sRet = "The sails were in a quite good condition for a ship captured in a seafight."; 
	if(GetSailPercent(rShip)<75) sRet = "Compared to the amount of balls we shot at the ship the sails were in acceptable condition. Nevertheless, repairing the damage will cost quite some sailcloth.";
	if(GetSailPercent(rShip)<50) sRet = "The sails were badly damaged, but at least allowed the ship basic maneuvers.";
	if(GetSailPercent(rShip)<25) sRet = "The sails were almost completely in tatters. We'll need quite a lot of sailcloth to repair that.";  
	if(GetSailPercent(rShip)<=10) sRet = "Our cannons did their job. The sails and the rigging were in tatters, there was barely a squarefeet of sails left intact.";

	return sRet;
}

string GetHullStatus(ref rShip)
{
	string sRet = "";
	if(GetHullPercent(rShip)>=90) sRet = "The hull was in very good order. It almost took no damage at all from the battle."; 
	if(GetHullPercent(rShip)<90) sRet = "The hull was in good condition. Our balls did some damage but nothing serious."; 
	if(GetHullPercent(rShip)<75) sRet = "The hull had a few holes and the deck was quite a mess, but it seems the damage can be repaired.";
	if(GetHullPercent(rShip)<50) sRet = "The hull was leaking, the deck full of splinters and overall the ship was in a bad condition.";
	if(GetHullPercent(rShip)<25) sRet = "The ship has spung a large leak in the hull and water was pouring in, but we were able to close it. In summary the ship's hull was as full of holes as a Swiss cheese.";  
	if(GetHullPercent(rShip)<=10) sRet = "The ship was about to sink when we captured her. We spotted three leaks in the hull and did some quick repairs. The ship is badly in need of a shipyard.";

	return sRet;
}

string GetCargoList(ref rShip)
{
	int i;
	int len;
	string sRet ="";
	string plunder = "";
	for(i=0; i<GOODS_QUANTITY;i++)
	{
		plunder = "plunder"+i;
		if(CheckAttribute(rShip,"Ship.Plunder."+plunder)){
			if(sti(rShip.Ship.Plunder.(plunder)) > 0)
			{
				sRet += "     "+XI_ConvertString(Goods[i].name)+": "+rShip.Ship.Plunder.(plunder)+"\n";    
			}
		}
	}
	len = strlen(sRet);
	if(len >2) strcut(sRet, 0, len-2);
	return sRet;
}

void Ship_HullHitEvent()
{
	float	fHP;

	int		iBallType = sti(AIBalls.CurrentBallType);

	aref	rShipObject = GetEventData();

	int		iBallCharacterIndex = GetEventData();
	int		iOurCharacterIndex = GetEventData();

	ref		rBallCharacter = GetCharacter(iBallCharacterIndex);
	ref		rOurCharacter = GetCharacter(iOurCharacterIndex);

	rOurCharacter.Ship.LastBallCharacter = iBallCharacterIndex;
	rBallCharacter.Ship.lasttgt = iOurCharacterIndex; // NK 04-09-16 to see who AI is attacking

	int		iCompanion = GetCompanionNumber(rBallCharacter, iOurCharacterIndex);

	float	x = GetEventData();
	float	y = GetEventData();
	float	z = GetEventData();

	int		iFirePlaceIndex = GetEventData();
	float	fFirePlaceDistance = GetEventData();

	bool	bDead = LAi_IsDead(rOurCharacter);

	bool	bSeriousBoom = false;
	bool	bInflame = false;

	// NK 05-04-18 to handle relation change for REAL_CANNONS
	if(iBallCharacterIndex == GetMainCharacterIndex() && USE_REAL_CANNONS && EXTRA_HIT_CHECK && rOurCharacter.ship.type != SHIP_FORT_NAME)
	{
		int currel = SeaAI_GetRelation(iOurCharacterIndex, iBallCharacterIndex) ;
		if(currel != RELATION_ENEMY && !CheckAttribute(rOurCharacter,"surrendered")) // NK surrender 05-04-20
		{
			aref aShips; makearef(aShips, rBallCharacter.SeaAI.Update.Ships);
			int iShipsNum = GetAttributesNum(aShips);
			int s;
			bool enemy = false;
			for (s=0; s<iShipsNum; s++)
			{
				aref aShip = GetAttributeN(aShips, s);
				if (sti(aShip.relation) == RELATION_ENEMY) { enemy = true; break; }
			}
			ref cmdr = Group_GetGroupCommander(GetGroupIDFromCharacter(&rOurCharacter));
			if (!enemy) {
				Event(SHIP_FIRE_ACTION, "iil", &rOurCharacter, &cmdr, currel); // if there's no enemy, then you have no excuse.
			} else {
				if (!CheckAttribute(rOurCharacter, "numhits")) {
					rOurCharacter.numhits = 1;
				} else {
					int curhits = sti(rOurCharacter.numhits); // max of cqty / 2 hits.
					if (curhits > GetCannonMaxQuantity(&rBallCharacter) / 2) {
						Event(SHIP_FIRE_ACTION, "iil", &rOurCharacter, &cmdr, currel);
					} else {
						curhits++;
						rOurCharacter.numhits = curhits;
					}
				}
			}
		}
	}
	if(iBallCharacterIndex != GetMainCharacterIndex() && CheckAttribute(rOurCharacter,"surrendered")) return; // NK because AI doesn't respect surrender. 05-04-23
	// NK <--

	// Cannon damage multiply
	ref rCannon = GetCannonByType(sti(rBallCharacter.Ship.Cannons.Type));
	float maxqty, fCannonDamageMultiply;
	// THIS IS NOT NEEDED ANY MORE. But the comment is left and the code commented. NK 04-09-15 to simulate fewer crew manning fewer guns. Hence reload rate will now go back to constant.
	// KNB 05-02-04 changed this a bit: there is no penalty for >60% crew and the minimum damage is 10%
	// now use cannon qty rather than crew mult. 05-04-18
// KK -->
	fCannonDamageMultiply = stf(rCannon.DamageMultiply);
	if(USE_REAL_CANNONS)
	{
		// KNB 04-01-17 distance/aspect based damage multipliers -->
		float fShotDistance = Ship_GetDistance2D(rBallCharacter, rOurCharacter);
		if(fShotDistance < 0) fShotDistance = 500; // NK for when dist < 0 05-04-15
		if (rOurCharacter.Ship.Type != SHIP_FORT_NAME && rBallCharacter.Ship.Type != SHIP_FORT_NAME)
		{
			float fShotSpeed = rCannon.SpeedV0 * stf(Goods[iBallType].SpeedV0);
			float fBallAngle = 0;
			float fOurAngle = 0;

			fCannonDamageMultiply *= 2 * pow(1-1/(2.25*fShotSpeed),fShotDistance); // 2x at point blank, decreasing exponentially with range

			if (iBallType != GOOD_GRAPES)
			{
				if(CheckAttribute(rOurCharacter,"ship.ang.y")) // NK for checking atttributes first before we need CheckAttribute(rBallCharacter,"ship.ang.y") &&  to
				{
					// NK now get angle from AIBalls, this requires reversing of the B2R.
					fBallAngle = clampangle(stf(AIBalls.Dir)+PI); fOurAngle = stf(rOurCharacter.Ship.Ang.y);
					fCannonDamageMultiply *= Bring2Range(0.50, 2.0, 0.0, 1.0, abs(GetDotProduct(fBallAngle,fOurAngle))); //50%-200% depending on angle
				}
			}
		}
	}
	// <-- KNB
// <-- KK

	if (sti(rBallCharacter.TmpPerks.CriticalShoot) && rand(19)==10) { bSeriousBoom = true; }		// +5%
	if (sti(rBallCharacter.TmpPerks.CannonProfessional) && rand(9)==4) { bSeriousBoom = true; }		// +10%

	ref rBall = GetGoodByType(iBallType);
	switch (iBallType)
	{
// TIH --> this section adjusted to be a bit more understandable in setting, and reasonable in graphics Nov13'06
// Removal of "CreateBlastM()" function due to that function causing a CTD in battles Nov12'06
	// NK add USE_PARTICLES switch // TIH changed to own switch SHIPHIT_PARTICLES 7-7-06
	// Ball_impact and splinters by MM
	// By MM, Flames and Critical hits only present on bombs now. // changed to add a rare chance (otherwise what's the POINT of the PERKS?)
		case GOOD_BALLS:
			if (rand(1)) { bSeriousBoom = false; }// pref toggle and 50% chance a possible critical hit is allowed
			if (rand(32) == 1) { bInflame = true; }// pref toggle and 3% chance ship catches on fire from hit
			Play3DSound("ball2bort", x, y, z);
			switch(SHIPHIT_PARTICLES)
			{
				case 0: CreateParticleSystem("blast", x, y, z, 0.0, 0.0, 0.0, 0); break; // one orange puff // stock behavior
				case 1:
						CreateParticleSystem("ball_impact", x, y, z, 0.0, 0.0, 0.0, 0); // two small gray puffs
				break;
				case 2:
						CreateParticleSystem("ball_impact_enhanced", x, y, z, 0.0, 0.0, 0.0, 0);  // wood dust
						CreateParticleSystem("splinters_enhanced", x, y, z, 0.0, 0.0, 0.0, 0);	// twenty-four small splinters
						CreateParticleSystem("splinters2_enhanced", x, y, z, 0.0, 0.0, 0.0, 0);	// twenty-four medium splinters
				break;
				case 3:
						CreateBlast(x,y,z); // excessive plume of planks and barrels, causing big water splashes
						CreateParticleSystem("ball_impact", x, y, z, 0.0, 0.0, 0.0, 0);	// two small gray puffs
						CreateParticleSystem("splinters2", x, y, z, 0.0, 0.0, 0.0, 0);	// six medium splinters
						CreateParticleSystem("splinters3", x, y, z, 0.0, 0.0, 0.0, 0);	// five large splinters
						CreateParticleSystem("flyers", x, y, z, 0.0, 0.0, 0.0, 0);
						CreateParticleSystem("flyers2", x, y, z, 0.0, 0.0, 0.0, 0);
				break;
			}
		break;
		case GOOD_GRAPES:
			bSeriousBoom = false;
			bInflame = false;
			Play3DSound("grapes2bort", x, y, z);
			switch(SHIPHIT_PARTICLES)
			{
				case 0: CreateParticleSystem("blast", x, y, z, 0.0, 0.0, 0.0, 0); break; // one orange puff // stock behavior
				case 1:
					CreateParticleSystem("ball_impact", x, y, z, 0.0, 0.0, 0.0, 0);
				break;
				case 2:
					CreateParticleSystem("ball_impact", x, y, z, 0.0, 0.0, 0.0, 0);
					CreateParticleSystem("splinters", x, y, z, 0.0, 0.0, 0.0, 0);
				break;
				case 3:
					CreateBlast(x,y,z);
					CreateParticleSystem("ball_impact", x, y, z, 0.0, 0.0, 0.0, 0);
				break;
			}
		break;
		case GOOD_KNIPPELS:
			bSeriousBoom = false;
			bInflame = false;
			Play3DSound("knippel2bort", x, y, z);
			switch(SHIPHIT_PARTICLES)
			{
				case 0: CreateParticleSystem("blast", x, y, z, 0.0, 0.0, 0.0, 0); break; // one orange puff // stock behavior
				case 1:
					CreateParticleSystem("ball_impact", x, y, z, 0.0, 0.0, 0.0, 0);
				break;
				case 2:
					CreateParticleSystem("ball_impact", x, y, z, 0.0, 0.0, 0.0, 0);
					CreateParticleSystem("splinters", x, y, z, 0.0, 0.0, 0.0, 0);
					CreateParticleSystem("splinters2", x, y, z, 0.0, 0.0, 0.0, 0);
				break;
				case 3:
					CreateBlast(x,y,z);
					CreateParticleSystem("ball_impact", x, y, z, 0.0, 0.0, 0.0, 0);
					CreateParticleSystem("flyers", x, y, z, 0.0, 0.0, 0.0, 0);
					CreateParticleSystem("flyers2", x, y, z, 0.0, 0.0, 0.0, 0);
				break;
			}
		break;
		case GOOD_BOMBS:
			if (rand(20) == 10) { bSeriousBoom = true; }
			if (rand(2) == 1) { bInflame = true; }
			Play3DSound("bomb2bort", x, y, z);
			switch(SHIPHIT_PARTICLES)
			{
				case 0: CreateParticleSystem("blast", x, y, z, 0.0, 0.0, 0.0, 0); break; // one orange puff // stock behavior
				case 1:
					CreateParticleSystem("blast", x, y, z, 0.0, 0.0, 0.0, 0);
				break;
				case 2:
					CreateBlast(x,y,z);
					CreateParticleSystem("blast", x, y, z, 0.0, 0.0, 0.0, 0);
					CreateParticleSystem("flyers", x, y, z, 0.0, 0.0, 0.0, 0);
					CreateParticleSystem("flyers2", x, y, z, 0.0, 0.0, 0.0, 0);
				break;
				case 3:
					CreateBlast(x,y,z);
					CreateParticleSystem("blast", x, y, z, 0.0, 0.0, 0.0, 0);
					CreateParticleSystem("blast_inv", x, y, z, 0.0, 0.0, 0.0, 0);
					CreateParticleSystem("splinters2", x, y, z, 0.0, 0.0, 0.0, 0);
					CreateParticleSystem("splinters3", x, y, z, 0.0, 0.0, 0.0, 0);
					CreateParticleSystem("flyers", x, y, z, 0.0, 0.0, 0.0, 0);
					CreateParticleSystem("flyers2", x, y, z, 0.0, 0.0, 0.0, 0);
				break;
			}
		break;
// TIH <-- end adjustment
	}

	// PB: Queen Anne's Revenge -->
	if(sti(GetAttribute(AIBalls, "GreekFire")))
	{
		bInflame = true;
		LogIt("Greek Fire hits the " + rOurCharacter.ship.name + "!")
	}
	// PB: Queen Anne's Revenge <--

	if (sti(rOurCharacter.TmpPerks.ProfessionalDamageControl) && frnd() < PROSHIPDEF_NOCRITCH) { bSeriousBoom = false; }				// no seriouse boom, NK 05-04-19 add setting

	if (!bDead)
	{
		float fCrewDamage;
		if (USE_REAL_CANNONS)
			fCrewDamage = stf(rBall.DamageCrew) * fCannonDamageMultiply * AIShip_isPerksUse(rBallCharacter.TmpPerks.CrewDamageUp, 1.0, 1.10); // 1.15  KNB;
		else
			fCrewDamage = stf(rBall.DamageCrew) * fCannonDamageMultiply * AIShip_isPerksUse(rBallCharacter.TmpPerks.CrewDamageUp, 1.0, 1.15);
// KK -->
//		fCrewDamage = FRAND(fCrewDamage);						// GR: this sets the damage to a random amount between 0 and calculated damage
//		fCrewDamage = 0.5*fCrewDamage+frand(0.5*fCrewDamage)+frand(0.5*fCrewDamage);	// this sets the damage to a random amount between 0.5* and 1.5* calculated damage - reported as being excessive
		fCrewDamage = 0.1*fCrewDamage+frand(0.5*fCrewDamage)+frand(0.5*fCrewDamage);	// this sets the damage to a random amount between 0.1* and 1.1* calculated damage
//trace("fCrewDamage="+fCrewDamage);
		int iRelation = SeaAI_GetRelation(iOurCharacterIndex, GetMainCharacterIndex());
		if (IsMainCharacter(rBallCharacter))
		{
			// PB: Warning Note -->
			if (iRelation == RELATION_ENEMY && GetFlagRMRelation(sti(rOurCharacter.nation)) != RELATION_ENEMY)
			{
				if (sti(rOurCharacter.nation) != PIRATE && !CheckAttribute(rBallCharacter, "false_flag_note") && !CheckAttribute(rOurCharacter, "skipRM"))
				{
					LogIt("Captain, we are under a flag friendly to the ship we're attacking. We may be branded a pirate if we don't hoist our true colours!");
					PlaySound("INTERFACE\notebook.wav");
					rBallCharacter.false_flag_note = true;
				}
			}
			// PB: Warning Note <--
		}

		if (LAi_IsImmortal(rOurCharacter) || LAi_IsCrewImmortal(rOurCharacter)) fCrewDamage = 0.0; // KK

		rOurCharacter.cannonhit = true; rOurCharacter.cannonhit.x = x; rOurCharacter.cannonhit.y = y; rOurCharacter.cannonhit.z = z; // NK 05-04-20 so cannon losing has pos for FX

		if (bSeriousBoom)
		{
			//fCrewDamage = fCrewDamage * 2.0; // stock
			//fHP = fCannonDamageMultiply * stf(rBall.DamageHull) * (4.0 + frnd() * 2.0); // stock
			//fCrewDamage = fCrewDamage * 5.0; // excessive
			//fHP = fCannonDamageMultiply * stf(rBall.DamageHull) * (80.0 + frnd() * 40.0); // excessive
			fHP = fCannonDamageMultiply * stf(rBall.DamageHull) * (2.0 + frnd());
			rOurCharacter.cannonhit.critchance = true; // NK 05-04-20 higher chance for loss of cannon on crit // TIH attribute renamed to critchance Nov13'06
			if (!LAi_IsImmortal(rOurCharacter)) Ship_ApplyHullHitpoints(rOurCharacter, fHP, KILL_BY_BALL, iBallCharacterIndex); // KK
			if (!LAi_IsImmortal(rOurCharacter) && !LAi_IsCrewImmortal(rOurCharacter)) Ship_ApplyCrewHitpoints(rOurCharacter, fCrewDamage  * (2.0 + frnd()) ); // KK
			//Ship_ApplyCrewHitpoints(rOurCharacter, fCrewDamage * 1.5); // stock

			if (iBallCharacterIndex == GetMainCharacterIndex())
			{
				Log_SetStringToLog(LanguageConvertString(iSeaSectionLang, "Ship_critical"));
			}
			// LDH divide experience between cannons and accuracy - 27Dec08
			Ship_AddDelayedCumXP(GetCharacter(iBallCharacterIndex), "Cannons" , 500);
			Ship_AddDelayedCumXP(GetCharacter(iBallCharacterIndex), "Accuracy", 500);
		}
		else
		{
			fHP = fCannonDamageMultiply * stf(rBall.DamageHull);
			if (!LAi_IsImmortal(rOurCharacter))											Ship_ApplyHullHitpoints(rOurCharacter, fHP, KILL_BY_BALL, iBallCharacterIndex); // KK 
			if (!LAi_IsImmortal(rOurCharacter) && !LAi_IsCrewImmortal(rOurCharacter))	Ship_ApplyCrewHitpoints(rOurCharacter, fCrewDamage); // moved from below, so not applied twice during crits // KK
			// LDH divide experience between cannons and accuracy - 27Dec08
			Ship_AddDelayedCumXP(GetCharacter(iBallCharacterIndex), "Cannons" , 100);
			Ship_AddDelayedCumXP(GetCharacter(iBallCharacterIndex), "Accuracy", 100);
		}
		DeleteAttribute(&rOurCharacter, "cannonhit"); // NK 05-04-20 cannon lost FX

		//Ship_ApplyCrewHitpoints(rOurCharacter, fCrewDamage); // moved up, so not applied twice during crits
	}

	if (bInflame == true && fFirePlaceDistance < 4.0 && iFirePlaceIndex >= 0)
	{
		int iRandStartTime = rand(1000);
		float fTotalFireTime = Ship_GetTotalFireTime(rOurCharacter);

		PostEvent(SHIP_ACTIVATE_FIRE_PLACE, iRandStartTime, "ialsf", rShipObject, rOurCharacter, iFirePlaceIndex, "ship_onfire", fTotalFireTime);
		PostEvent(SHIP_FIRE_DAMAGE, iRandStartTime, "lllf", iOurCharacterIndex, iBallCharacterIndex, iFirePlaceIndex, fTotalFireTime);
	}

	if (bSeriousBoom == true) //{ Ship_Serious_Boom(x, y, z); } // NK modify coords some 05-04-18 -->
	{
		if(SHIPHIT_PARTICLES==3) { Ship_Detonate(rOurCharacter, false, false); }//{ Ship_Serious_Boom(x-1+frnd()*2, y-1+frnd()*2, z-1+frnd()*2); }
		else { Ship_Serious_Boom(x, y, z); }
	}
}

float Ship_GetTotalFireTime(ref rCharacter)
{
	int iRepairSkill = MakeInt(stf(rCharacter.TmpSkill.Repair) * 10.0);
// KK -->
	float TotalFireTime = MakeFloat(5 + 3 * (10 - iRepairSkill));
	TotalFireTime = TotalFireTime * FIRETIME;	// ccc firedrill
	return TotalFireTime;
// <-- KK
}

void Ship_FireDamage()
{
	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	int iOurCharacterIndex = GetEventData();
	int iBallCharacterIndex = GetEventData();

	int iFirePlaceIndex = GetEventData();
	float fTotalFireTime = GetEventData();

	ref rOurCharacter = GetCharacter(iOurCharacterIndex);
	ref rBallCharacter = GetCharacter(iBallCharacterIndex);

	int iSClass = GetCharacterShipClass(rOurCharacter);

	float fHP = (8 - iSClass) * (0.5 + frnd() * 0.5); // KK

	int iTime = 1000 + rand(500);

	fHP = fHP * FIREDAMAGE; // ccc firedrill MAR18 // KK
	float fFirstAid = 1.0;

	// if abordage or interface launched
	if (!bAbordageStarted && !sti(InterfaceStates.Launched))
	{
		// NK add super-crit 05-04-19
		float hpratio = GetHullPercent(&rOurCharacter)/100.0;
		if(hpratio <= FIREKILLCH_HP_MIN) // add fire can kill via super-crit
		{
			if(frnd() < FIREKILLCH_BASE * Bring2Range(FIREKILLCH_MAXCH, FIREKILLCH_MINCH, 0.0, pow2(FIREKILLCH_HP_MIN, FIREKILLCH_HP_RAT_PWR), pow2(hpratio, FIREKILLCH_HP_RAT_PWR)))
			{
				fHP = 1000000;
				rOurCharacter.explosion = true;
				if (iRealismMode == 0 || Ship_GetDistance2D(GetMainCharacter(), rOurCharacter) < GetVisibilityRange(1)) { // KK: Explosion can be seen from LONG range
					Log_SetStringToLog(TranslateString("","Fire has reached the") + " " + GetMyShipNameShow(rOurCharacter) + TranslateString("","'s powder magazine!")); // KK
					PlaySound("interface\notebook.wav"); // sound so you notice
				}
				if (CANNONPOWDER_MOD) {// TIH --> mod toggle 7-7-06
					// added by MAXIMUS [gunpowder mod] -->
					int newQty;
					if(sti(GetCargoGoods(rOurCharacter, GOOD_GUNPOWDER))>0) newQty = sti(GetCargoGoods(rOurCharacter, GOOD_GUNPOWDER)) / 100 * rand(50);
					else newQty = 0;
					SetCharacterGoods(rOurCharacter, GOOD_GUNPOWDER, newQty);
					// added by MAXIMUS [gunpowder mod] <--
				}// TIH <-- mod toggle
			}
		}
		// NK <--
		Ship_ApplyHullHitpoints(rOurCharacter, fHP, KILL_BY_BALL, iBallCharacterIndex);

		fTotalFireTime = fTotalFireTime - MakeFloat(iTime) / 1000.0;
	}
	bool needstopall = false;
	float fX, fY, fZ;
	if(!LAi_IsBoardingProcess() && !ownDeckStarted())
	{
	// ccc firedrill
		//get ship coords for graphic effects
		fX = 0; fY = 0; fZ = 0;
		fX=stf(GetAttribute(rOurCharacter, "Ship.pos.x"));
		fY=stf(GetAttribute(rOurCharacter, "Ship.pos.y"));
		fZ=stf(GetAttribute(rOurCharacter, "Ship.pos.z"));
		// NK add AI firedrill 05-04-19
		bool dofiredrill = CheckAttribute(rOurCharacter,"firedrill");
		bool ismc = true;
		if(iOurCharacterIndex != GetMainCharacterIndex())
		{
			ismc = false;
			float stopch = stf(GetAttribute(rOurCharacter, "TmpPerks.BasicDamageControl")) * AI_FIREDRILL_CHANCE * bring2Range(0.1, 2.0, 0.0, 1.0, stf(rOurCharacter.TmpSkill.Leadership)); // yes, leadership. Persuading men to brave the fire.
			//trace("Firedrill: char " + rOurCharacter.id + " of " + rOurCharacter.ship.name + " has a fire. Chance to stop is " + stopch);
			if(frnd() < stopch) { dofiredrill = true; }
		}
		// NK add AI <--
		if (dofiredrill == true && fTotalFireTime > 0.0) 	//checks marker if "C" was hit & fire burning MAR18 // KK
		// NK <--
		{
// KK -->
			int casualties = 0;
			casualties = makeint(sti(rOurCharacter.Ship.Crew.Quantity)* rand(3)/100 );	// a few firefighters may die
			if (sti(GetAttribute(rOurCharacter, "TmpPerks.BasicFirstAid")))		fFirstAid = 0.85;	// 15%
			if (sti(GetAttribute(rOurCharacter, "TmpPerks.AdvancedFirstAid")))	fFirstAid = 0.7;	// 30%
			casualties = makeint(casualties*fFirstAid + 0.5);
			RemoveCharacterCrew(rOurCharacter,casualties);
// <-- KK

			fTotalFireTime = 0.0;	// for code below
			// NK stop particles:
			string tmpstr;

			int id;
			aref arShipObject = GetCharacter(iOurCharacterIndex);
			int maxplaces; SendMessage(arShipObject, "le", MSG_SHIP_GET_NUM_FIRE_PLACES, &maxplaces);
			for(int p = 0; p < maxplaces; p++)
			{
				tmpstr = p;
				if(CheckAttribute(rOurCharacter,"fireplaces."+tmpstr)) // should always be true
				{
					id = sti(rOurCharacter.fireplaces.(tmpstr));
					if (id != 0) StopSound(id, 500);	// LDH added test, zero will stop ALL sounds - 25Mar09
					DeleteAttribute(rOurCharacter, "fireplaces."+tmpstr);
					//trace("stopped sound, deleting fire");
					//SendMessage(arShipObject, "llsslf", MSG_SHIP_ACTIVATE_FIRE_PLACE, iFirePlaceIndex, "ship_smoke", "ship_fire", id, 0.5); // should disable fire, I hope. Seems not to work as of 05-04-22
					//trace("deleted fire")
				}
				//else needstopall = true;
			}
			tmpstr = iFirePlaceIndex;
			if(ismc) // NK for AI
			{
				PlaySound("objects\shipcharge\ship_bow.wav");
				PlaySound("ambient\shipyard\axe.wav");
			}
			else
			{
				// KK Play3DSound("clear_for_action", fX, fY, fZ);
				Play3DSound("objects\abordage\abordage_loosing.wav", fX, fY, fZ);
				Play3DSound("objects\shipcharge\ship_bow.wav", fX, fY, fZ);
				Play3DSound("ambient\shipyard\axe.wav", fX, fY, fZ);
				//Ship_SetSailState(iOurCharacterIndex, 0.0);
				//if(GUN_DOUSING==1) Ship_ChangeCharge(&rOurCharacter, sti(rOurCharacter.Ship.Cannons.Charge.Type));
				//trace("fire doused!");
			}

			CreateParticleSystemX("ball_splash",fX-2, fY+5, fZ, 3.0, 7.0, 0.0, 0);
			CreateParticleSystemX("ball_splash",fX+2, fY+6, fZ, 0.0, 7.0, 3.0, 0);
			CreateParticleSystemX("ball_splash",fX, fY+7, fZ+2, -2.0, 8.0, 0.0, 0);
			CreateParticleSystemX("ball_splash",fX, fY+5, fZ-2, 0.0, 9.0, -3.0, 0);
			CreateParticleSystemX("gunfire",fX-3, fY+3, fZ-1, 6.0, 4.0, 0.0, 0);
			CreateParticleSystemX("gunfire",fX+3, fY+4, fZ+1, 0.0, 4.0, 7.0, 0);
			CreateParticleSystemX("gunfire",fX-1, fY+5, fZ+3, -6.0, 5.0, 0.0, 0);
			CreateParticleSystemX("gunfire",fX+1, fY+3, fZ-3, 0.0, 5.0, -7.0, 0);

			if(ismc) Log_SetStringToLog(TranslateString("", "One fire doused!") + " " + casualties + " " + TranslateString("", "men burnt") + "..."); // KK
			SetMusic(musicName); // KK
		}
	// ccc firedrill end
	}


	if (fTotalFireTime > 0.0) // KK
	{
		PostEvent(SHIP_FIRE_DAMAGE, iTime, "lllf", iOurCharacterIndex, iBallCharacterIndex, iFirePlaceIndex, fTotalFireTime);
		if(!bAbordageStarted && LogsToggle > LOG_NORMAL)
		{
			if (sti(GetAttribute(rOurCharacter, "Index")) == GetMainCharacterIndex() && CheckAttribute(rOurCharacter, "Ship.Sink") == false && FIREDAMAGE > 1) { // KK
				Log_SetStringToLog(TranslateString("","Fire still burning! Execute firedrill procedure immediately!"));
			}	//ccc firedrill MAR18 // KK
			if (needstopall) CreateParticleSystem("ball_impact", fX, fY, fZ, 0.0, 0.0, 0.0, 0); // ccc some smoke if fireparticle was deleted above, NK do only if needed
		}
	}
	//LanguageCloseFile(tmpLangFileID);
}

void Ship_Serious_Boom(float x, float y, float z)
{
	CreateBlast(x,y,z);
	CreateParticleSystem("blast_inv", x, y, z, 0.0, 0.0, 0.0, 0);
	Play3DSound("ship_explosion", x, y, z);
}

void Ship_SetFantomData(ref rFantom)
{
	ref		rCannon, rBaseShip;

	rBaseShip = GetShipByID(rFantom.Ship.Type); // PS
	aref arship; makearef(arship, rFantom.ship); // PRS3

	int iMinCrew = sti(GetLocalShipAttrib(arship, rBaseShip, "MinCrew"));
	int iMaxCrew = sti(GetLocalShipAttrib(arship, rBaseShip, "MaxCrew"));

	int iBaseHP = sti(GetLocalShipAttrib(arship, rBaseShip, "HP"));
	int iBaseSP = sti(GetLocalShipAttrib(arship, rBaseShip, "SP"));

	int iCapacity = sti(GetLocalShipAttrib(arship, rBaseShip, "Capacity"));

// START MOD Code by Stone-D : 30/07/2003
//	rFantom.Ship.Crew.Quantity = iMinCrew + rand(iMaxCrew - iMinCrew - 1);
	rFantom.Ship.Crew.Quantity = iMaxCrew - makeint(rand(makeint(iMaxCrew/5)));
	if(!CheckAttribute(rFantom, "skill.Leadership")) rFantom.skill.Leadership = 1; // Fixed by LDH 14Dec08
	rFantom.Ship.Crew.morale = makeint((rand(sti(rFantom.skill.Leadership))+1)*10);
	rFantom.Ship.Crew.morale = makeint(rand(sti(rFantom.Ship.Crew.morale))+rand(50)+25); // Gotcha ya bast!
	if (CheckAttribute(rFantom, "Ship.Masts")) { DeleteAttribute(rFantom, "Ship.Masts"); }
	if (CheckAttribute(rFantom, "Ship.Blots")) { DeleteAttribute(rFantom, "Ship.Blots"); }
	if (CheckAttribute(rFantom, "Ship.Sails")) { DeleteAttribute(rFantom, "Ship.Sails"); }

// Next part unnecessary, but entertaining.
// The following code only takes effect if rFantom does not have FantomType of trade, war or pirate, see CheckAttribute() below
	if (rand(3) > 1)	// 50% of the time
	{
		rFantom.Ship.HP = iBaseHP - rand(iBaseHP / 2);		// remove up to half the ship's HP
		rFantom.Ship.SP = iBaseSP - rand( (iBaseSP*((sti(rFantom.Ship.HP)/iBaseHP)*2)) ); // this does nothing: sti("50")/100 = 0
//		Whack_Ship(rFantom); // Stone-D : Not working 27/07/2003
	}
	if (sti(GetLocalShipAttrib(arship, rBaseShip, "HP")) == iBaseHP && rand(3) > 1)		// if HP hasn't been changed, then 50% of the time // KK
	{
		rFantom.Ship.SP = iBaseSP - rand(iBaseSP / 2);		// remove up to half of the ship's SP
	}
//	MakeSailDmg(sti(rFantom.index), iBaseSP - rFantom.Ship.SP); // Stone-D : Not working // LDH, moved to BattleInterface
// END MOD Code by Stone-D : 30/07/2003
	//NK -->
	//MSM switch based on fantomtype.
	float hulldmg = 1.0;
	float saildmg = 1.0;
	if(CheckAttribute(rFantom,"FantomType"))
	{
		switch(rFantom.FantomType)
		{
			case "trade":
				rFantom.Ship.Crew.morale = makeint(25.0 * (1.0 + makefloat(rand(GetShipSkill(rFantom,SKILL_LEADERSHIP)/5)+1)/2.0));
				rFantom.Ship.Crew.Quantity = makeint( iMinCrew + 0.55*(iMaxCrew-iMinCrew) + 0.40*rand(iMaxCrew-iMinCrew) ); // PB: Min crew + anywhere between 55% to 95% of remaining crew
				hulldmg = 0.5;
				saildmg = 0.3;
			break;

			case "war":
				rFantom.Ship.Crew.morale = makeint(40.0 * (1.0 + makefloat(rand(GetShipSkill(rFantom,SKILL_LEADERSHIP)/5)+1)/2.0));
				rFantom.Ship.Crew.Quantity = makeint( iMinCrew + 0.80*(iMaxCrew-iMinCrew) + 0.20*rand(iMaxCrew-iMinCrew) ); // PB: Min crew + anywhere between 80% to 100% of remaining crew
				hulldmg = 0.25;
				saildmg = 0.25;
			break;

			case "pirate":
				rFantom.Ship.Crew.morale = makeint(50.0 * (1.0 + makefloat(rand(GetShipSkill(rFantom,SKILL_LEADERSHIP)/2)+1)/5.0));
				rFantom.Ship.Crew.Quantity = makeint( iMinCrew + 0.90*(iMaxCrew-iMinCrew) + 0.10*rand(iMaxCrew-iMinCrew) ); // PB: Min crew + anywhere between 90% to 100% of remaining crew
				hulldmg = 0.5;
				saildmg = 0.2;
			break;
		}
		hulldmg *= (1.5 - 0.2 * makefloat(GetDifficulty()));
		saildmg *= (1.5 - 0.2 * makefloat(GetDifficulty()));
		rFantom.Ship.HP = iBaseHP - makeint(makefloat(iBaseHP) * frand(hulldmg));
		rFantom.Ship.SP = iBaseSP - makeint(makefloat(iBaseSP) * frand(saildmg));
	}
	if (sti(rFantom.Ship.Crew.morale)>MORALE_MAX) rFantom.Ship.Crew.morale=MORALE_MAX;
	if (sti(rFantom.Ship.Crew.morale)<MORALE_MIN) rFantom.Ship.Crew.morale=MORALE_MIN;
	//Log_SetStringToLog("Type " + rFantom.FantomType);
	// NK <--

	// LDH prevent overup crews and black crew bars on ship icons - 17Jan09
	if (sti(rFantom.Ship.Crew.Quantity) > iMaxCrew)
	{
		Trace("Ship_SetFantomData tried to set crew quantity above max for ship, " + rFantom.Ship.Crew.Quantity + " of " + iMaxCrew);
		rFantom.Ship.Crew.Quantity = iMaxCrew;
	}
/*
	if (GetCrewQuantity(rFantom) > GetMaxCrewQuantity(rFantom))
	{
		Trace("WARNING: Ship_SetFantomData tried to set crew quantity above max");
		SetCrewQuantity(rFantom, GetMaxCrewQuantity(rFantom));
	}
*/
	// LDH make sure sail damage gets applied properly -->
	float tempDamage = iBaseSP - stf(rFantom.Ship.SP);
	rFantom.Ship.SP = iBaseSP;			// damage will be applied later in BattleInterface
	rFantom.NeedSailDmg = tempDamage;
	// LDH <--
}

void CharacterUpdateShipFromBaseShip(int iCharacterIndex)
{
	// logit("CharacterUpdateShipFromBaseShip");
	ref rCharacter, rCannon, rBaseShip;

	rCharacter = GetCharacter(iCharacterIndex);
	rBaseShip = GetShipByID(rCharacter.Ship.Type); // PS
	aref arship; makearef(arship, rCharacter.ship); // PRS3

	int iMinCrew = sti(GetLocalShipAttrib(arship, rBaseShip, "MinCrew")); // PRS3
	int iMaxCrew = sti(GetLocalShipAttrib(arship, rBaseShip, "MaxCrew")); // PRS3

	if (!CheckAttribute(rCharacter,"Ship.Crew.Quantity")) { rCharacter.Ship.Crew.Quantity = iMinCrew + rand(iMaxCrew - iMinCrew - 1); }
	if (!CheckAttribute(rCharacter,"Ship.HP")) { rCharacter.Ship.HP = GetCharacterShipHP(rCharacter); } // PRS3
	if (!CheckAttribute(rCharacter,"Ship.SP")) { rCharacter.Ship.SP = rBaseShip.SP; }

	if (!CheckAttribute(rCharacter,"Ship.Cannons.Charge.Type"))
	{
		if(iCharacterIndex == GetMainCharacterIndex()) { rCharacter.Ship.Cannons.Charge.Type = DEFAULT_CHARGE; } // NK 04-09-16 so player can set default charge
		else { rCharacter.Ship.Cannons.Charge.Type = GOOD_BOMBS; }
	}

	//Trace("Init cindex = " + iCharacterIndex + ", ship HP = " + rCharacter.Ship.HP + ", id = " + rCharacter.id + ", idx = " + rCharacter.index);
	if (!CheckAttribute(rCharacter,"Ship.Cannons.Type"))
	{
		if(USE_REAL_CANNONS) { rCharacter.Ship.Cannons.Type = CANNON_TYPE_LONG_LBS9; }; // KNB
		else { rCharacter.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS12; };
	}

	rCharacter.Ship.Cannons.Borts = "";
	// NK cannon qty 05-04-18 -->
	//if(USE_REAL_CANNONS)
	//{
		if(!CheckAttribute(rCharacter,"ship.Cannons.Borts.cannonf.qty")) rCharacter.ship.Cannons.Borts.cannonf.qty = rBaseShip.Cannons.Borts.cannonf.qty;
		if(!CheckAttribute(rCharacter,"ship.Cannons.Borts.cannonb.qty")) rCharacter.ship.Cannons.Borts.cannonb.qty = rBaseShip.Cannons.Borts.cannonb.qty;
		if(!CheckAttribute(rCharacter,"ship.Cannons.Borts.cannonl.qty")) rCharacter.ship.Cannons.Borts.cannonl.qty = rBaseShip.Cannons.Borts.cannonl.qty;
		if(!CheckAttribute(rCharacter,"ship.Cannons.Borts.cannonr.qty")) rCharacter.ship.Cannons.Borts.cannonr.qty = rBaseShip.Cannons.Borts.cannonr.qty;
		//crew based:
		Ship_SetCannonQtyByCrew(&rCharacter);
	//}
	// NK <--
}

void Ship_CheckMainCharacter()
{
	// logit("CheckMainCharacter");
	aref	arUpdate;
	ref		rIsland;
	int		i, iRelation;
	float	x, z, fBestDistance, fDistance;
	float	fMinEnemyDistance = 1000000.0;
	bool	bAbordageStartNow = false;

	PostEvent(SHIP_CHECK_RELOAD_ENABLE, 1000);

	ref rCharacter = GetMainCharacter();

	// if abordage launched, return
	if (bAbordageStarted) { return; }

	// if interface launched, return
	if (sti(InterfaceStates.Launched)) { return; }

	// if main character is dead - skip
	if (LAi_IsDead(rCharacter)) { return; };

	iStormLockSeconds = iStormLockSeconds - 1;
	if(iStormLockSeconds == 1)  // screwface
	{
		WeatherParams.update = true;
		Whr_UpdateWeather(false);
		if(Whr_IsStorm())
		{
			iStormLockSeconds = 60;
			SetSchemeForSea();
		}
	} // screwface : end
	if (iStormLockSeconds < 0) { iStormLockSeconds = 0; }
	// NK 04-09-16 implement rough timer function
	// LDH see if we can improve this 04Jan09
	int temptime = 1;
	if(CheckAttribute(rCharacter,"seatime"))
	{
		temptime += sti(rCharacter.seatime);
	}
	rCharacter.seatime = temptime;

	//locTmpTime = temptime; // also update loc tmp time.
	AddSeaTimeToCurrent();

	Ship_CheckMorale(GetMainCharacterIndex()); // NK for morale check 04-09-16 <--

	bAbordageFortCanBe = false;
	bAbordageShipCanBe = false;
	bAbordageTownCanBe = false; // KK
	bCanEnterToLand = false;
	bCanEnterToFort = false; // KK
	bDisableSailTo = false;
	if(!CheckAttribute(rCharacter, "ForceReload")) // PB: Don't override this if a reload is already in progress!
	{
		sIslandLocator = "";
		sIslandID      = "";
	}

	makearef(arUpdate, rCharacter.SeaAI.Update);

	if (!CheckAttribute(arUpdate, "Ships")) { return; }
	if (!CheckAttribute(arUpdate, "Forts")) { return; }

	x = stf(rCharacter.Ship.Pos.x);
	z = stf(rCharacter.Ship.Pos.z);

	float fOurHP = Ship_GetHP(rCharacter);
	float fOurFencing = pow2(stf(rCharacter.TmpSkill.Fencing),FENCING_BOARD_PWR); // NK scale by fencingpwr 05-04-20
	float fOurGrappling = stf(rCharacter.TmpSkill.Grappling);
	float fOurCrewFencing = (0.1 + fOurFencing * stf(rCharacter.Ship.Crew.Quantity) * (1.0 - ((1.0 - fclamp(0.1, 10.0, stf(rCharacter.ship.crew.morale)/(MORALE_MAX-MORALE_MIN) * 2))/2.0))); // NK 05-04-20 add morale

	float fOurBoxSizeX = stf(rCharacter.Ship.BoxSize.x) / 2.0;

	bool bGrapplingProfessional = sti(rCharacter.TmpPerks.GrapplingProfessional);

	// max abordage parameters for our player
		float fGrapplingPerk = AIShip_isPerksUse(rCharacter.TmpPerks.LongRangeGrappling, 1.0, 1.15);
		fGrapplingPerk = AIShip_isPerksUse(rCharacter.TmpPerks.GrapplingProfessional, fGrapplingPerk, 1.25);
		float fOurMaxAbordageDistance, fOurMaxAbordageAngle, fOurMaxAbordageSpeed; // KNB -->
		if(USE_REAL_SAILING)
		{
			fOurMaxAbordageDistance = fGrapplingPerk * Bring2Range(8.0, 25.0, 0.0, 1.0, fOurGrappling); // was 15.0, 40.0
			fOurMaxAbordageAngle = Bring2Range(0.80-makefloat(bGrapplingProfessional)*0.1, 0.60-makefloat(bGrapplingProfessional)*0.1, 0.0, 1.0, fOurGrappling);// was 0.70, 0.45. NK add Grapp Prof, because it's not used lower.
			fOurMaxAbordageSpeed = Bring2Range(2.0, 4.0, 0.0, 1.0, fOurGrappling); // was 3.0, 5.0
		}
		// KNB <--
		else
		{
			fOurMaxAbordageDistance = fGrapplingPerk * Bring2Range(15.0, 40.0, 0.0, 1.0, fOurGrappling);
			fOurMaxAbordageAngle = Bring2Range(0.70, 0.45, 0.0, 1.0, fOurGrappling);
			fOurMaxAbordageSpeed = Bring2Range(3.0, 5.0, 0.0, 1.0, fOurGrappling);
		}

	string sPlayerLocation = rCharacter.location;
	string sPlayerLocator = rCharacter.location.locator;

	// find island
	int iIslandIndex = FindIsland(sPlayerLocation);
	if (iIslandIndex >= 0)
	{
		rIsland = GetIslandByIndex(iIslandIndex);
	}

	aref aShips, aForts;
	makearef(aShips, arUpdate.Ships);
	makearef(aForts, arUpdate.Forts);

	// check forts for abordage
	int iFortsNum = GetAttributesNum(aForts);
	fBestDistance = 10000000.0;
	for (i=0; i<iFortsNum; i++)
	{
		aref aFort = GetAttributeN(aForts, i);
		iRelation = sti(aFort.relation);
		if (iRelation == RELATION_FRIEND) { continue; }
		ref rFortCharacter = GetCharacter(sti(aFort.idx));
		if (LAi_IsDead(rFortCharacter)) { continue; }
		aref aRLoc = FindIslandReloadLocator(sPlayerLocation, rFortCharacter.location.locator);
		float fRadius = stf(aRLoc.Radius);
		fDistance = stf(aFort.Distance);
		if(CheckAttribute(rCharacter, "ship.SubmergeDutchman")) fDistance = DIST_NOSHIP; //Levis no shooting at submerged dutchman
		int iFortMode = sti(rFortCharacter.Fort.Mode);

		switch (iFortMode)
		{
			case FORT_NORMAL:
				if (iRelation == RELATION_ENEMY)
				{
					if (fMinEnemyDistance > fDistance) { fMinEnemyDistance = fDistance; }
				}
// KK -->
				if (sti(rFortCharacter.nation) == PERSONAL_NATION) {
					if (!bMapEnter) continue;
					if (fDistance > fRadius) continue;
					//if (!Character_IsAbordageEnable(rFortCharacter)) { continue; }

					if (fBestDistance > fDistance)
					{
						fBestDistance = fDistance;

						bCanEnterToFort = true;
						sAbordageLocator = rFortCharacter.location.locator;
						iAbordageFortEnemyCharacter = sti(rFortCharacter.index);
					}
				}
// <-- KK
			break;
			case FORT_DEAD:
				if (fDistance > fRadius) { continue; }
				if (fBestDistance > fDistance)
				{
					fBestDistance = fDistance;

					bCanEnterToLand = true;

					sIslandID = rIsland.id;
					makearef(arIslandReload, rIsland.reload);
					sIslandLocator = aRLoc.GoAfterBoard.location;
				}
			break;
			case FORT_ABORDAGE:
				if (iRelation == RELATION_ENEMY)
				{
					if (fMinEnemyDistance > fDistance) { fMinEnemyDistance = fDistance; }
				}
				if (fDistance > fRadius) { continue; }
				if (!Character_IsAbordageEnable(rFortCharacter)) { continue; }

				if (fBestDistance > fDistance)
				{
					fBestDistance = fDistance;

					bAbordageFortCanBe = true;
					sAbordageLocator = rFortCharacter.location.locator;
					iAbordageFortEnemyCharacter = sti(rFortCharacter.index);
				}
			break;
		}
	}

// check ships for abordage
	int iShipsNum = GetAttributesNum(aShips);
	fBestDistance = 10000000.0;
	aref aShip; // KK
	ref rShipCharacter; // KK
	for (i=0; i<iShipsNum; i++)
	{
		aShip = GetAttributeN(aShips, i);

		rShipCharacter = GetCharacter(sti(aShip.idx));

		if (LAi_IsDead(rShipCharacter)) { continue; } // TIH moved up here for program speed Aug24'06
		if (!Character_IsAbordageEnable(rShipCharacter)) { continue; } // TIH moved up here for program speed Aug24'06
		if (IsCompanion(rShipCharacter)) { continue; } // TIH don't even do this stuff with companion ships Aug24'06

		fDistance = stf(aShip.Distance);		// distance between player ship and this ship
		if(CheckAttribute(rCharacter, "ship.SubmergeDutchman")) fDistance = DIST_NOSHIP; //Levis trying to get the Dutchman out of reach when submerged
		iRelation = sti(aShip.relation);

		// NK surrender 05-04-20 -->
		if (iRelation == RELATION_ENEMY && fMinEnemyDistance > fDistance) { fMinEnemyDistance = fDistance; }
		if (iRelation != RELATION_ENEMY && !CheckAttribute(rShipCharacter,"surrendered")) { continue; }
		//if (fMinEnemyDistance > fDistance) { fMinEnemyDistance = fDistance; }
		// NK <--

		float fAng = stf(aShip.d_ay);						// it's dot.ay between ships
		float fRelativeSpeed = stf(aShip.RelativeSpeed);	// it's relative speed about player ship
		float fEnemyBoxSizeX = stf(rShipCharacter.Ship.BoxSize.x) / 2.0 * (1.0 + makefloat(CheckAttribute(rShipCharacter,"surrendered"))*BOARD_SURR_DISTANCE_MULT); //so you can board surrednered ships from afar. NK 05-04-23 //KB - corrected
		bool bAngleTest = abs(fAng) > fOurMaxAbordageAngle && fRelativeSpeed < fOurMaxAbordageSpeed;
		if(!USE_REAL_SAILING) bAngleTest = bAngleTest || bGrapplingProfessional; // KNB
		//if (abs(fAng) > fOurMaxAbordageAngle && fRelativeSpeed < fOurMaxAbordageSpeed)
		float fAbordageDistance = fDistance - fEnemyBoxSizeX - fOurBoxSizeX;
		// NK check for surrender 05-04-21 (reorganize this so dist checked first, angle second)
		if (fAbordageDistance < fOurMaxAbordageDistance && fBestDistance > fDistance)
		{
			if(CheckAttribute(rShipCharacter,"surrendered"))
			{
				/*string sGroupID = rShipCharacter.surrendered.oldgroup;
				bool alive = true;
				int gidx = Group_FindGroup(sGroupID);
				if(gidx == -1) alive = false;
				if(alive) alive = Group_isDead(sGroupID);
				if(alive)
				{
					ref gcmdr = Group_GetGroupCommander(sGroupID);
					if(SeaAI_GetRelation(sti(gcmdr.index), GetMainCharacterIndex()) != RELATION_ENEMY) { continue; }
				}
				else { */
					// TIH --> use a better function for relation checking to determine if you can board a surrendered ship Aug24'06
					//Trace("BDCHK: surrendered ship boarding check: " + rShipCharacter.id + " oldnation: " + rShipCharacter.oldnation + " curnation: " + rShipCharacter.nation );

					// attempt 7: (couldn't seem to board ANYONE who surrendered)
					//int tmpNation = sti(rShipCharacter.nation);
					//rShipCharacter.nation = rShipCharacter.oldnation;
					//int tmpRelation = SeaAI_GetRelation(sti(rShipCharacter.index), GetMainCharacterIndex());
					//rShipCharacter.nation = tmpNation;
					//if (tmpRelation != RELATION_ENEMY) continue;

					// LDH unable to board surrendered ship test
					// Relations 0=friend, 1=neutral, 2=enemy
					// Flags 0=England, 1=France, 5=Portugal
					// 5, 1, 0,
					//logit("Surrendered ship: flag = " + GetCurrentFlag() + ", oldnation = " + rShipCharacter.oldnation);
					// 0 with English (Portugese!!) flag, 1 with personal flag
					//logit("NationRelation = " + GetNationRelation(GetCurrentFlag(),sti(rShipCharacter.oldnation)));
					// 2
					//logit("ActualRelation = " + GetNationRelation2MainCharacter(sti(rShipCharacter.oldnation)));

					// attempt 6: (seems to work except for one damned french ship - but he is set to never surrender now, so who cares?)

				/*	int tmpRelation = "";
					if ( GetCurrentFlag() != PERSONAL_NATION )
					{
						tmpRelation = GetNationRelation(GetCurrentFlag(),sti(rShipCharacter.oldnation));
					//	Trace("BDCHK: GetNationRelation: " + tmpRelation + "  (" + RELATION_ENEMY + ")" );
					}
					else
					{
						tmpRelation = GetNationRelation2MainCharacter(sti(rShipCharacter.oldnation));
					//	Trace("BDCHK: GetNationRelation2MainCharacter: " + tmpRelation + "  (" + RELATION_ENEMY + ")" );
					}
				*/
					int tmpRelation = GetNationRelation(GetCurrentFlag(), sti(rShipCharacter.oldnation)); // PB
					if (tmpRelation != RELATION_ENEMY) continue;

					// attempt 5:
					//int tmpnation = sti(rShipCharacter.nation);
					//rShipCharacter.nation = rShipCharacter.oldnation;
					//if(GetRelation(rCharacter.index,rShipCharacter.index) != RELATION_ENEMY) { rShipCharacter.nation = tmpnation; continue; }
					//rShipCharacter.nation = tmpnation;
					// attempt 4:
					//if(SeaAI_GetRelation(sti(rShipCharacter.index), GetMainCharacterIndex()) != RELATION_ENEMY) { continue; }
					// attempt 3:
					//if(GetRMRelationType(GetRMRelation(rCharacter, sti(rShipCharacter.oldnation))) != RELATION_ENEMY) { continue; }
					// attempt 2:
					//if(GetNationRelation2MainCharacter(sti(rShipCharacter.oldnation)) != RELATION_ENEMY) { continue; }
					// attempt 1:
					//if(GetNationRelation2MainCharacter(sti(rShipCharacter.oldnation)) != RELATION_ENEMY) { continue; }
					// TIH <--
				//}
				//HKE -->
				if (!CheckAttribute(rCharacter, "PlayedAbordageSound"))
				{
					PlayStereoSound("INTERFACE\prepare_for_boarding.wav");
					rCharacter.PlayedAbordageSound = true;
				}
				//<-- HKE
				bAbordageShipCanBe = true;
				iAbordageShipEnemyCharacter = sti(rShipCharacter.index);
				fBestDistance = fDistance;
				continue;
			}
			if (bAngleTest)
			{
				// NK surrender 05-04-20 <--
				//HKE -->
				if (!CheckAttribute(rCharacter, "PlayedAbordageSound"))
				{
					PlayStereoSound("INTERFACE\prepare_for_boarding.wav");
					rCharacter.PlayedAbordageSound = true;
				}
				//<-- HKE
				// abordage enable
				fBestDistance = fDistance;
				bAbordageShipCanBe = true;
				iAbordageShipEnemyCharacter = sti(rShipCharacter.index);

				// maybe other character want abordage us?
				float fEnemyFencing = pow2(stf(rShipCharacter.TmpSkill.Fencing),FENCING_BOARD_PWR); // NK scale by fencingpwr 05-04-20
				float fEnemyCrewFencing = (0.1 + fEnemyFencing * stf(rShipCharacter.Ship.Crew.Quantity) * (1.0 - ((1.0 - fclamp(0.1, 10.0, stf(rShipCharacter.ship.crew.morale)/(MORALE_MAX-MORALE_MIN) * 2))/2.0))); // NK add morale 05-04-20
				float fRatio = fEnemyCrewFencing / fOurCrewFencing;
				if (sti(rShipCharacter.nation) == PIRATE) { fRatio = fRatio * 1.4; }
				if (fRatio > 1.2)
				{
					bAbordageStartNow = true;
					break;
				}
			}
			continue;
		}
	}

// check reload to locations possibility
	bool bDoReload = iIslandIndex >= 0 && fMinEnemyDistance > MIN_ENEMY_DISTANCE_TO_DISABLE_ENTER_2_LOCATION;
	if (bDoReload || CheckAttribute(rCharacter, "ForceReload")) // PW: Continue anchoring process if already started
	{
		if (Island_isReloadEnableGlobal(sPlayerLocation))
		{
			aref arReload;
			makearef(arReload, rIsland.Reload);

			int iNumLocators = GetAttributesNum(arReload);
			for (int j=0; j<iNumLocators; j++)
			{
				aref arLocator;
				arLocator = GetAttributeN(arReload, j);
				string sLocatorName = GetAttributeName(arLocator);
				if (Island_isReloadFort(sPlayerLocation, arLocator.name)) { continue; }
				if (!Island_isReloadEnableLocal(sPlayerLocation, arLocator.name)) { continue; }
				float x1 = stf(rIsland.reload.(sLocatorName).x);
				float z1 = stf(rIsland.reload.(sLocatorName).z);
				float r = stf(rIsland.reload.(sLocatorName).radius);
				if (sqrt(sqr(x1 - x) + sqr(z1 - z)) < r)
				{
					bCanEnterToLand = bMapEnter; // KK
					sIslandID = rIsland.id;
					makearef(arIslandReload, rIsland.reload);
					sIslandLocator = rIsland.reload.(sLocatorName).name;
// KK -->
					string bLoc = rIsland.reload.(sLocatorName).go;
					int towns_quantity = GetIslandTownsQuantity(sIslandID);
					for (int k = 1; k <= towns_quantity; k++) {
						ref rTown = GetTownfromIsland(sIslandID, k);
						if (CheckAttribute(rTown, "boarding.l1") == true && rTown.boarding.l1 == bLoc) {
							string town = rTown.id;
							iFortsNum = GetTownNumForts(town);
							if (iFortsNum == 0) {
								int iNation = sti(rCharacter.nation);
								int tNation = GetTownNation(town);
								if (GetNationRelation(iNation, tNation) == RELATION_ENEMY && CheckOfficersPerk(rCharacter,"Troopers")) { // PB: Need the "Land Toops" ability to assault towns directly
									bAbordageTownCanBe = true;
									for (i = 0; i < iShipsNum; i++) {
										aShip = GetAttributeN(aShips, i);

										rShipCharacter = GetCharacter(sti(aShip.idx));

										if (LAi_IsDead(rShipCharacter)) continue;
										if (!Character_IsAbordageEnable(rShipCharacter)) continue;
										if (IsCompanion(rShipCharacter)) continue;
										if (sti(rShipCharacter.nation) == tNation) {
											bAbordageTownCanBe = false;
											break;
										}
									}
									if (bAbordageTownCanBe) {
										iAbordageTownEnemyCharacter = GetTownGovernorIndex(town);
										if (iAbordageTownEnemyCharacter < 0) iAbordageTownEnemyCharacter = GetCharacterIndex("Captured governor");
										characters[iAbordageTownEnemyCharacter].town = town;
									}
								}
							}
							break;
						}
					}
// <-- KK
					break;
				}
			}
		}
	}

// disable any abordage if storm
	if (Whr_IsStorm())
	{
		bAbordageStartNow = false;
		bAbordageFortCanBe = false;
		bAbordageShipCanBe = false;
		bAbordageTownCanBe = false; // KK
	}

// Enter 2 map enable/disable
// Peoples on ship mode update
	int iPrevShipPOSMode = sti(rCharacter.Ship.POS.Mode);
	rCharacter.Ship.POS.Mode = SHIP_SAIL;

	bDisableMapEnter = false;
	if (fMinEnemyDistance < MIN_ENEMY_DISTANCE_TO_DISABLE_MAP_ENTER && !CheckAttribute(rCharacter, "ForceReload")) // PW: Continue anchoring process if already started
	{
		bCanEnterToLand = false;
		bDisableMapEnter = true;

		rCharacter.Ship.POS.Mode = SHIP_WAR;
	}

	if (iStormLockSeconds)
	{
		bDisableMapEnter = true;
		bCanEnterToLand = false;
		bDisableSailTo = true;

		rCharacter.Ship.POS.Mode = SHIP_STORM;
	}

	// new music
	// NK PGMus handling 05-04-18 -->
	// make general 05-04-29
	if(CheckAttribute(rCharacter,"musfix"))
	{
		/*SetMusicNoPause(rCharacter.pgmus.cur);
		oldMusicName = rCharacter.pgmus.old;
		DeleteAttribute(&rCharacter,"pgmus")*/
		SetSchemeForSea();
		iPrevShipPOSMode = SHIP_SAIL;
		DeleteAttribute(rCharacter,"musfix");
	}
	// NK <--
	if (sti(rCharacter.Ship.POS.Mode) != iPrevShipPOSMode)
	{
		switch (sti(rCharacter.Ship.POS.Mode))
		{
			case SHIP_SAIL:
				SetMusic("music_spokplavanie"); // Baste
				if (!Whr_IsStorm()) { Sound_OnSeaAlarm(false); }
				if (iPrevShipPOSMode == SHIP_WAR)
				{
					PlayStereoOGG("music_ship_victory");
				}
				if (iPrevShipPOSMode == SHIP_STORM)
				{
					FadeOutMusic(3000);
					PlayStereoOGG("music_End_storm");
				}
			break;
			case SHIP_WAR:
				Sound_OnSeaAlarm(true);
			break;
		}
	}

// if quest disable enter 2 map
	if (bQuestDisableMapEnter) { bDisableMapEnter = true; }

// Start abordage automatically
	if (bAbordageStartNow) { Sea_AbordageLoad(SHIP_ABORDAGE, false); }
}

void Ship_OnStrandNext()
{
	ref	rCharacter = GetCharacter(GetEventData());
	if (LAi_IsDead(rCharacter)) { return; }

	bool bOnStrand = sti(rCharacter.Ship.Strand);
	if (!bOnStrand)
	{
		int iSoundID = sti(rCharacter.Ship.Strand.SndID);
		if (iSoundID != 0) { StopSound(sti(rCharacter.Ship.Strand.SndID), 3000); }
		rCharacter.Ship.Strand.SndID = SOUND_INVALID_ID;
		return;
	}

	if (!sti(rCharacter.TmpPerks.SandbankManeuver))
	{
		float fCurrentSpeedZ = stf(rCharacter.Ship.Speed.z);

		float fHP = 4.0 * fCurrentSpeedZ / 7.0;
		Ship_ApplyHullHitpoints(rCharacter, fHP, KILL_BY_ISLAND, -1);
	}
	PostEvent(SHIP_TO_STRAND_NEXT, 100 + rand(100), "l", sti(rCharacter.index));
}

void Ship_OnStrand()
{
	ref rCharacter = GetCharacter(GetEventData());
	bool bNewStrand = GetEventData();

	bool bPrevStrand = sti(rCharacter.Ship.Strand);

	rCharacter.Ship.Strand = bNewStrand;

	float x = stf(rCharacter.Ship.Pos.x);
	float y = stf(rCharacter.Ship.Pos.y);
	float z = stf(rCharacter.Ship.Pos.z);

	if (bPrevStrand == 0 && bNewStrand == 1)
	{
		PostEvent(SHIP_TO_STRAND_NEXT, 100, "l", sti(rCharacter.index));
		rCharacter.Ship.Strand.SndID = Play3DSoundComplex("ship_aground", x, y, z, true, false);
	}
}

// Small boom
void Ship_DetonateSmall()
{
	ref		rCharacter = GetCharacter(GetEventData());
	// NK allow this to not repeat forever 05-04-18
	if(CheckAttribute(rCharacter,"maxsmallboomtimes"))
	{
		int bt = sti(rCharacter.maxsmallboomtimes);
		if(bt) { bt--; rCharacter.maxsmallboomtimes = bt; }
		else { DeleteAttribute(rCharacter,"maxsmallboomtimes"); return; }
	}
	// NK <--
	aref	arCharShip; makearef(arCharShip, rCharacter.Ship);

	float x = stf(arCharShip.Pos.x);
	float y = stf(arCharShip.Pos.y);
	float z = stf(arCharShip.Pos.z);

	if (y > -3.0)
	{
		int iSClass = GetCharacterShipClass(rCharacter);
		PostEvent(SHIP_DETONATE_SMALL, 200 + iSClass * 300 + rand(900), "l", sti(rCharacter.index));
	}

	if (bAbordageStarted) { return; }
	if (sti(InterfaceStates.Launched)) { return; }

	float bx = arCharShip.BoxSize.x;
	float by = arCharShip.BoxSize.y;
	float bz = arCharShip.BoxSize.z;

	float fCos = cos(stf(arCharShip.Ang.y));
	float fSin = sin(stf(arCharShip.Ang.y));

	int iTemp = 1 + rand(1);	// LDH moved outside for loop test, just in case - 25Mar09
	for (int i=0; i < iTemp; i++)
	{
		float x1, y1, z1;
		x1 = (frnd() - 0.5) * bx;
		z1 = (frnd() - 0.5) * bz;

		RotateAroundY(&x1, &z1, fCos, fSin);

		y1 = 1.0 + y + frnd() * 3.0;
		Ship_Serious_Boom(x1 + x, y1, z1 + z);
		CreateParticleSystem("blast", x1 + x, y1, z1 + z, 0.0, 0.0, 0.0, 0);
	}
}

void Ship_Turn180(ref rCharacter)
{
	rCharacter.TmpPerks.Turn = true;
	rCharacter.TmpPerks.Turn.Angle = PI/3; //Armada: Changed to represent 'club hauling' manoeuvre. 
	//Uses 60 degree turn to compensate for continued turning speed after manoeuvre, to make a near-90 degree turn overall.
	rCharacter.TmpPerks.Turn.Angle = sti(rCharacter.TmpPerks.Turn.Angle) * sti(GetAttribute(GetMainCharacter(), "clubhauling")); // PB: Choose which side to turn to
}

// Big Boom on ship
void Ship_Detonate(ref rCharacter, bool bMakeSmallBoom, bool bMakeDead)
{
	if (!CheckAttribute(rCharacter, "Ship.Pos.x"))
	{
		Traceif("Ship_Detonate: Can't find Ship.Pos in character with id: " + rCharacter.id);
		return;
	}
	//trace("for char " + rCharacter.id + " of ship " + rCharacter.ship.name + " do Ship_Detonate");

	aref	arCharShip; makearef(arCharShip, rCharacter.Ship);

	float x = stf(arCharShip.Pos.x);
	float y = stf(arCharShip.Pos.y);
	float z = stf(arCharShip.Pos.z);

	int iMinBoom = MakeInt(Bring2Range(6.0, 2.0, 1.0, 7.0, stf(GetCharacterShipClass(rCharacter))));

	float bx = arCharShip.BoxSize.x;
	float by = arCharShip.BoxSize.y;
	float bz = arCharShip.BoxSize.z;

	float fCos = cos(stf(arCharShip.Ang.y));
	float fSin = sin(stf(arCharShip.Ang.y));

	iMinBoom += rand(2);	// LDH moved outside for loop test, just in case - 25Mar09
	for (int i=0; i<iMinBoom; i++)
	{
		float x1, y1, z1;
		x1 = (frnd() - 0.5) * bx;
		z1 = (frnd() - 0.5) * bz;

		RotateAroundY(&x1, &z1, fCos, fSin);

		y1 = 1.0 + y + frnd() * 3.0;
		Ship_Serious_Boom(x1 + x, y1, z1 + z);
		CreateParticleSystem("blast", x1 + x, y1, z1 + z, 0.0, 0.0, 0.0, 0);
	}
	if (bMakeDead) { ShipDead(sti(rCharacter.Index), KILL_BY_SPY, -1); }

	if (bMakeSmallBoom) { PostEvent(SHIP_DETONATE_SMALL, 600 + rand(1000), "l", sti(rCharacter.index)); }
}

float AIShip_isPerksUse(string sPerk, float fOff, float fOn)
{
	if (sti(sPerk)) { return fOn; }
	return fOff;
}

// EVENT, calculate dynamic parameters for ship, one per second
void Ship_UpdateParameters()
{
	// logit("UpdateParameters");
	int i;
	float fX, fY, fZ, fAY; // PB
	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	int iCharacterIndex = GetEventData();
	if (iCharacterIndex < 0) return;
	ref rCharacter = GetCharacter(iCharacterIndex);
	if (CharacterIsDead(rCharacter)) return;
	float fSailState = GetEventData();
	if(!CheckAttribute(rCharacter,"LastSailState")) rCharacter.LastSailState = makeint(fSailState * 2); // NK, Amokachi

	// PB: Steam Ships -->
	if(SteamShip(rCharacter))
	{
		if(!IsMainCharacter(rCharacter))
		{
			switch(sti(fSailState * 2))
			{
				case 0:
					rCharacter.Ship.Power = 0;
				break;
				case 1:
					rCharacter.Ship.Power = 50;
				break;
				case 2:
					rCharacter.Ship.Power = 100;
				break;
			}
		}
		if(GetCargoGoods(rCharacter, GOOD_PLANKS) > 0 || !IsMainCharacter(rCharacter))
		{
			ref MyShipType = GetShipByType(GetCharacterShipType(rCharacter));
			aref arship; makearef(arship, rCharacter.ship);
			float PowerScalar = stf(GetAttribute(rCharacter,"Ship.Power"))/100;
			float SpeedRateScalar = stf(GetLocalShipAttrib(arship, MyShipType, "SpeedRate"))/10
			float DamageScalar = makefloat(GetCurrentShipHP(rCharacter)) / makefloat(GetCharacterShipHP(rCharacter));
			float SailCompensation = 1.0;
			if(sti(rCharacter.LastSailState) == 0)	SailCompensation = 0.5;
			rCharacter.Ship.Impulse.Rotate.z = 0.2 * PowerScalar * SpeedRateScalar * DamageScalar * SailCompensation;

			fX = 0; fY = 0; fZ = 0;
			if(CheckAttribute(rCharacter,"Ship.pos.x")) fX=stf(rCharacter.Ship.pos.x);
			if(CheckAttribute(rCharacter,"Ship.pos.y")) fY=stf(rCharacter.Ship.pos.y);
			if(CheckAttribute(rCharacter,"Ship.pos.z")) fZ=stf(rCharacter.Ship.pos.z);

			if(fX != 0 && fY != 0 && fZ != 0)	StackSteam(rCharacter, makeint(abs(stf(GetAttribute(rCharacter,"Ship.Power")))/7.5));
		}
	}
	// PB: Steam Ships <--

	bool	bStrand = sti(rCharacter.Ship.Strand);

	bool	bDead = LAi_IsDead(rCharacter);

	aref	arTmpPerks; makearef(arTmpPerks, rCharacter.TmpPerks);

	// update temporary skill storage
	Ship_UpdateTmpSkills(rCharacter);

	Cannon_RecalculateParameters(sti(rCharacter.index));

	// some of ship parameters
	aref	arCharShip; makearef(arCharShip, rCharacter.Ship);
	ref		rShip = GetShipByType(GetCharacterShipType(rCharacter)); // PS

// NK -->
	if (IsMainCharacter(rCharacter)) {
		bool bSinking = false;
		if (!CheckAttribute(rCharacter,"SinkState")) rCharacter.SinkState = bSinking;
		if (Ship_GetHP(rCharacter) < GetCharacterShipHP(rCharacter) * 0.1) bSinking = true; // PRS3
		if (bSinking != sti(rCharacter.SinkState)) {
			if (bSinking) {
				Log_SetStringToLog(TranslateString("","We're sinking!"));
				if(ENABLE_EXTRA_SOUNDS == 1) PlayStereoSound("#ship_sinking"); // added by KAM after build 11
			}
			rCharacter.SinkState = bSinking;
		}
		if (CheckAttribute(rCharacter, "Ship.Sink")) return; // KK
	}
// NK <--

	float	fMaxSpeedZ = stf(GetLocalShipAttrib(arCharShip, &rShip, "SpeedRate")); // PRS3
	float	fMaxSpeedY = stf(GetLocalShipAttrib(arCharShip, &rShip, "TurnRate")) / 444.444;	// cool magic number :)) //PRS3
	float	fCurrentSpeedZ = stf(arCharShip.Speed.z);
	if(!CheckAttribute(arCharShip,"Cargo.load")) RecalculateCargoLoad(rCharacter); // NK 04-16 bugfix
	float	fLoad = Clampf(stf(arCharShip.Cargo.Load) / stf(GetLocalShipAttrib(arCharShip, &rShip, "Capacity"))); // PRS3

// Calc min crew ratio
	float fCrewMin = makefloat(GetMinCrewQuantity(&rCharacter)); // PRS3 - stf(rShip.MinCrew);
	float fCrewCur = makefloat(GetCrewQuantity(&rCharacter));//stf(rCharacter.Ship.Crew.Quantity);//MAXIMUS
	float fCrewMin25Percent = fCrewMin* 0.25; // NK no need to check attr _twice_...
	arCharShip.Crew.MinRatio = Bring2Range(0.0, 1.0, fCrewMin25Percent, fCrewMin, fCrewCur);

// wind power
	float	fWindPower = Whr_GetWindSpeed() / WIND_NORMAL_POWER;
	float	fWindDotShip = GetDotProduct(Whr_GetWindAngle(), stf(arCharShip.Ang.y));		// Wind.ay | Ship.ay

// calculate MaxSpeedZ
	float fSpeedPerk = AIShip_isPerksUse(arTmpPerks.ShipSpeedUp, 1.0, 1.15);
	fSpeedPerk = AIShip_isPerksUse(arTmpPerks.SailingProfessional, fSpeedPerk, 1.20);

	float	fK = Clampf(1.0 - stf(GetLocalShipAttrib(arCharShip, rShip, "SpeedDependWeight")) * fLoad);
//NK -->
	if(iRealismMode == 0) {
		arCharShip.MaxSpeedZ = (fMaxSpeedZ * fWindPower * fK) * fSpeedPerk;
	} else {
// KK -->
		float	fClosestPoint = DEFAULT_CLOSESTPOINT;
		if (CheckShipAttribute(arCharShip, rShip, "ClosestPoint")) fClosestPoint = stf(GetLocalShipAttrib(arCharShip, rShip, "ClosestPoint")); //Closest point of sail

//KB - Tuning ships - Tack
//KB if ( sti(rCharacter.index) == 0 ) {Trace("KB - Tack before " + fClosestPoint);}
		aref temparef;
		int testtune=0;
		makearef(temparef,rCharacter.ship);
		if (CheckAttribute(temparef,"tune")) {
			testtune = 1;
			makearef(temparef,rCharacter.ship.tune);
			if(CheckAttribute(temparef,"tack")) {
				if ( sti(rCharacter.ship.tune.tack) > 0 ) {
					fClosestPoint = fClosestPoint + stf(rCharacter.ship.tune.tackmod);
					//Log_SetStringToLog(TranslateString("","Closest point changed! New = "+fClosestPoint));

					if ( fClosestPoint < 0.01 ) { fClosestPoint = 0.01; } // PB: Don't decrease this too far! Mainly applies to Flying Dutchman
					if ( fClosestPoint > 1    ) { fClosestPoint = 1   ; }
				}
			}
		}
//KB if ( sti(rCharacter.index) == 0 ) {Trace("KB - Tack after " + fClosestPoint);}
//KB - END Tuning ships - Tack

		float	fBestPoint = DEFAULT_BESTPOINT;
		if (CheckShipAttribute(arCharShip, rShip, "BestPoint")) fBestPoint = stf(GetLocalShipAttrib(arCharShip, rShip, "BestPoint")); //Best point of sail

		string rigtype = "Fri";
		if (CheckShipAttribute(arCharShip, rShip, "RigType")) rigtype = GetLocalShipAttrib(arCharShip, rShip, "RigType");
// <-- KK

//move some code to their own funcs at bottom 04-09-19


//get angles
		float	fWindAngle = Whr_GetWindAngle();
		float	fShipAngle = stf(arCharShip.Ang.y);

		float fOffWind = RS_CalcOffwind(fWindAngle, fShipAngle);

// LDH --> sail luffing sounds
		if(iCharacterIndex == GetMainCharacterIndex())
		{
			if(fOffWind <= fClosestPoint + RS_CP_OFFSET)
			{
				if (fSailState > 0.1)		// don't play if sails are furled
				{
					// PB: Slow down game to normal speed when you are caught in irons -->
					if(CheckAttribute(rCharacter, "timescale_reset"))
					{
						ResetTimeToNormal();
					}
					// PB: Slow down game to normal speed when you are caught in irons <--
					if (SAIL_LUFFING_SOUNDS)
					{
						for (i=0 ; i<SAIL_LUFFING_SOUNDS; i++ )
						{
							PostEvent("luffing_event",Rand(999));
						}
					}
				}
			}
			DeleteAttribute(rCharacter, "timescale_reset"); // But only ONCE after the weather change and not ALL the time
		}
// LDH <--

//TM --> Detect when non player ship is sailing into wind and use rotate function to turn it out of wind
		if (iCharacterIndex != GetMainCharacterIndex()) {
			if (fSeaExpTimer > 5) {
				// PB: Rewritten Tacking -->
				if(!CheckAttribute(rCharacter, "Ship.Tack"))														// Ship is not tacking
				{
					if (fOffWind <= fClosestPoint - RS_CP_OFFSET)													// Ship loses ALL speed and needs to tack
					{
						rCharacter.Ship.Tack = true;																// Indicate that the ship is tacking
						Ship_SetSailState(iCharacterIndex, 0.001);													// Lower all sails
						float fTacking = stf(arCharShip.Speed.y);													// Check which way the ship is going
						if(fTacking <= 0.0)		arCharShip.Impulse.Rotate.y = -0.0018;								// Make the ship rotate to port
						else					arCharShip.Impulse.Rotate.y =  0.0018;								// Make the ship rotate to starboard
					//	if (IsCompanion(rCharacter)) LogIt("The " + GetMyShipNameShow(rCharacter) + " is tacking");
					}
				}
				else																								// Tack in progress
				{
					if (fOffWind > fClosestPoint)																	// Ship is outside the "luffing area" again
					{
						DeleteAttribute(rCharacter, "Ship.Tack");													// Mark the tack as completed
						Ship_SetSailState(iCharacterIndex, 1.00);													// Make sail
						arCharShip.Impulse.Rotate.y = 0.0;															// Stop rotating
					//	if (IsCompanion(rCharacter)) LogIt("The " + GetMyShipNameShow(rCharacter) + " has completed her tack");
					}
					else
					{
						Ship_SetSailState(iCharacterIndex, 0.001);													// Keep sails lowered
					}
				}
				// PB: Rewritten Tacking <--
			}
		}
// <-- TM

//	Log_SetStringToLog("Angle1: " + fOffWind*100);
		arCharShip.MaxSpeedZ = fMaxSpeedZ * RS_CalcSpeedScalar(fClosestPoint, fBestPoint, rigtype, fOffWind, fWindPower) * fK * fSpeedPerk; // 04-09-19 now a function
		arCharShip.speedmult = fMaxSpeedZ * fK * fSpeedPerk * GetSailPercent(rCharacter) / 100.0; // NK 04-09-21
//	Log_SetStringToLog("Trgt: " + arCharShip.MaxSpeedZ);

	}
// NK <--

// calculate MaxSpeedY
	float	fTRFromWeight = Clampf(1.0 - stf(GetLocalShipAttrib(arCharShip, rShip, "TurnDependWeight")) * fLoad);
// NK -->
	float	fTRFromSpeed = (1.0 - stf(GetLocalShipAttrib(arCharShip, rShip, "TurnDependSpeed"))) + stf(GetLocalShipAttrib(arCharShip, rShip, "TurnDependSpeed")) * (Clampf((abs(fCurrentSpeedZ) / fMaxSpeedZ))); // fixed 05-04-10 NK
// NK <--
	float	fTRFromSkill, fTRFromPeople;
	if(USE_REAL_SAILING)
	{
		// KNB -->
		fTRFromSkill = Bring2Range(0.4, 1.0, 0.0, 2.0, 2.0 * stf(rCharacter.TmpSkill.Sailing));  // was min 0.2
		fTRFromPeople = Bring2Range(0.3, 1.0, 0.0, 1.0, stf(arCharShip.Crew.MinRatio));  // was min 0.2
		// <--KNB
	}
	else
	{
		fTRFromSkill = Bring2Range(0.2, 1.0, 0.0, 2.0, 2.0 * stf(rCharacter.TmpSkill.Sailing));
		fTRFromPeople = Bring2Range(0.2, 1.0, 0.0, 1.0, stf(arCharShip.Crew.MinRatio));
	}

	float	fTRFromSailDamage = 1.0;	// LDH - note that this is not changed from 1.0

// Turn rate depend from sail State
	float	fTRFromSailState = 1.0;
	switch (MakeInt(fSailState * 2.0))
	{
		case 0:
			if(USE_REAL_SAILING) fTRFromSailState = 0.001; // NK 05-04-10
			else fTRFromSailState = 0.3;
		break;
		case 1: fTRFromSailState = 1.0; break;
		case 2: fTRFromSailState = 0.6; break;
	}

	float	fTRResult; if(USE_REAL_SAILING) fTRResult = Bring2Range(0.10, 0.85, 0.00001, 1.0, fTRFromWeight * fTRFromSpeed * fTRFromSkill * fTRFromPeople * fTRFromSailDamage * fTRFromSailState); // KNB  reduced min turn speed from 20% to 10%
	else fTRResult = Bring2Range(0.2, 0.85, 0.00001, 1.0, fTRFromWeight * fTRFromSpeed * fTRFromSkill * fTRFromPeople * fTRFromSailDamage * fTRFromSailState);

	float fTurnPerk = AIShip_isPerksUse(arTmpPerks.ShipTurnRateUp, 1.0, 1.15);
	fTurnPerk = AIShip_isPerksUse(arTmpPerks.SailingProfessional, fTurnPerk, 1.20);

	// fast turn 180
	if (sti(arTmpPerks.Turn) == -1)
	{
		CharacterPerkOff(rCharacter, "Turn180");
		arTmpPerks.Turn = false;
	}
	float fFastTurn180 = AIShip_isPerksUse(arTmpPerks.Turn, 1.0, 8.0);

	fTRResult = fTRResult * fMaxSpeedY * fTurnPerk * fFastTurn180 * floatRet(iRealismMode == 0, 1.0, 1.5);	// LDH 04Oct06

// LDH --> change for turn rate, added sail damage 08Sep06
	float fSailPercent = GetSailPercent(rCharacter);	// current percentage of sails left, 0.0 to 100.0
	if(iRealismMode>0)
	{
		// for atmin=7.5 and atmax=85.0 - Below 7.5% ship cannot turn.  Above 85% ship turns normally.
		//At 10% sails ship turns 10% normal. At 20% turns 37%. At 50% turns 76%.  At 70% turns 90%.  At 80% turns 97%.

		// Below 7.5% ship cannot turn.
		// At 10% sails ship turns 10% normal. At 20% turns 35%. At 50% turns 71%.  At 70% turns 82%.  At 80% turns 88%.
		float atmin = 7.5;		// percent of sail below which ship can no longer turn
		float atmax = 100.0;	// percent of sail above which ship turning is not affected
		if (fSailPercent <= atmin)
		{
			fTRResult = 0.0;
		}
		else
		{
			if (fSailPercent < atmax)
			{
				atmin /= 10.0; atmax /= 10.0; fSailPercent /= 10.0;		// numbers need to be in range 0 to 10
				float athalf = (atmax+atmin)/2.0;
//				athalf = -1.0;		// uncomment to test using logN function throughout the range
				if (fSailPercent > athalf)	// function is mostly linear in this range, avoid time consuming calc
				{
					fTRResult = fTRResult * fclamp(0.0, 1.0, (0.73 + (fSailPercent-athalf)*0.27/(atmax-athalf)));
				}
				else
				{
	  				fSailPercent = fclamp(atmin, atmax, fSailPercent);
	  				fTRResult = fTRResult * fclamp(0.0, 1.0, logN(fSailPercent+(1.0-atmin)) / logN(1.0-atmin+atmax));
				}
			}
		}
	}
// LDH <--

	arCharShip.MaxSpeedY =	fTRResult;

	arCharShip.CorrectImmersion = (stf(GetLocalShipAttrib(arCharShip, rShip, "SubSeaDependWeight")) * fLoad);	// calculate immersion

	// PB: Flying Dutchman -->
	if(HasSubStr(GetAttribute(rCharacter, "ship.type"), "Dutchman") && CheckAttribute(arCharShip, "SubmergeDutchman"))	// Submerging Ability
	{
		int delay = 0;
		for (i=0; i < 40; i++)
		{
			PostEvent("UpdateDutchmanSubmersion", delay, "i", rCharacter);
			delay = delay + 25;
		}
	}
	else
		arCharShip.immersion = arCharShip.CorrectImmersion;

	if(HasSubStr(GetAttribute(rCharacter, "ship.type"), "Dutchman"))		// Sailing Against the Wind
	{
		switch(sti(rCharacter.LastSailState))
		{
			case 0:
				rCharacter.Ship.Impulse.Rotate.z = 0.0;
			break;
			case 1:
				rCharacter.Ship.Impulse.Rotate.z = 1/10 * 0.2;
			break;
			case 2:
				rCharacter.Ship.Impulse.Rotate.z = 2/10 * 0.2;
			break;
		}
	}
	// PB: Flying Dutchman <--

	// PB: Black Pearl -->
	bool IsCursed = false;
	if(CheckCharacterItem(rCharacter,"cursedcoin") && GetCursedCoinCount()>0 && sti(GetAttribute(rCharacter, "curseddays")) > 30)
	{
		IsCursed = true;
	}
	if(HasCharacterShipAttribute(rCharacter, "fog_trail") || IsCursed)
	{
		int puffs_per_second = 10;
		if(SeaCameras.Camera == "SeaDeckCamera")	puffs_per_second = 1;
		for (i=0; i < puffs_per_second; i++)
		{
			PostEvent("CreateCursedPearlFog", delay, "i", rCharacter);
			delay = delay + 1000/puffs_per_second;
		}
	}
	// PB: Black Pearl <--

	// PB: Devils Ship -->
	if(HasCharacterShipAttribute(rCharacter, "devil_trail"))
	{
		int (puffs_per_second = 10);
		if(SeaCameras.Camera == "SeaDeckCamera")	puffs_per_second = 1;
		for (i=0; i < puffs_per_second; i++)
		{
			PostEvent("CreateCursedDevilFog", delay, "i", rCharacter);
			delay = delay + 1000/puffs_per_second;
		}
	}
	// PB: Devils Ship <--

// do damage if ship hull < 10%, sinking
	float fBaseSailHP = stf(rShip.SP);
	float fBaseShipHP = stf(rShip.HP); // PRS3 // KK
	float fCurHP = stf(arCharShip.HP);
	if (bSeaActive && (fCurHP / fBaseShipHP) < 0.1)
	{
		float fLightRepair = AIShip_isPerksUse(arTmpPerks.LightRepair, 1.0, 0.0);
		if (CheckAttribute(rCharacter, "SinkTenPercent") && !sti(rCharacter.SinkTenPercent)) { fLightRepair = 0.0; }
		float fSinkDamage = fLightRepair * (fBaseShipHP / 100.0) * 0.08;
		if (CheckAttribute(rCharacter, "Ship.LastBallCharacter"))
		{
			Ship_ApplyHullHitpoints(rCharacter, fSinkDamage, KILL_BY_BALL, sti(rCharacter.Ship.LastBallCharacter));
		}
		else
		{
			Ship_ApplyHullHitpoints(rCharacter, fSinkDamage, KILL_BY_TOUCH, -1);
		}
		if (iCharacterIndex == GetMainCharacterIndex()) { AddPerkToActiveList("sink"); }
	}
	else
	{
		if (iCharacterIndex == GetMainCharacterIndex()) { DelPerkFromActiveList("sink"); }
	}

	float fStormProfessional = AIShip_isPerksUse(arTmpPerks.StormProfessional, 1.0, 0.6);

// NK -->

// do damage if storm or tornado
//placed here by MAXIMUS -->
	float fExp;
	float fWindAttack;
	float fDamageMultiply;
	float fDamageHP;
//placed here by MAXIMUS <--
	if (bStorm && bSeaActive)
	{
		fWindAttack = 1.0 - abs(fWindDotShip);

		fDamageMultiply = fStormProfessional * Bring2Range(0.25, 1.0, 0.0, 1.0, fWindAttack);

		// hull damage
// NK -->
		fDamageHP = (sqrt(fBaseShipHP) / 15);
// NK <--
		Ship_ApplyHullHitpoints(rCharacter, fDamageMultiply * fDamageHP, KILL_BY_TOUCH, -1);

		// sails damage
		switch (MakeInt(fSailState * 2.0))
		{
			case 0: MakeSailDmg(iCharacterIndex, fDamageMultiply * (fBaseSailHP / 100.0) * 0.05); break;
			case 1: MakeSailDmg(iCharacterIndex, fDamageMultiply * (fBaseSailHP / 100.0) * 0.15); break;
			case 2: MakeSailDmg(iCharacterIndex, fDamageMultiply * (fBaseSailHP / 100.0) * 0.25); break;
		}

		// experience
// NK -- first part of next line. The skill bit is from Stone-D; it makes exp from storms based on 0-sailing skill.
		fExp = (rand((GetShipSkill(rCharacter,SKILL_SAILING)-1))+1) * (5.0 - fWindAttack) * fDamageHP;
		if (!bDead)
		{
			if(AUTO_SKILL_SYSTEM)
			{
				Ship_AddDelayedCumXP(rCharacter, "Sailing", MakeInt(fExp));
			}
			else
			{
				Ship_AddCharacterExp(rCharacter, MakeInt(fExp));
			}
		}

// PB: Rewritten Storm Rotate Impulse -->
		float fRotate = stf(arCharShip.Impulse.Rotate.y);							// Read the rotate impulse the ship already has
		if(!CheckAttribute(arCharShip,"stormimp"))	arCharShip.stormimp = fRotate;	// If not being pushed, store the rotate impulse before the push
																					// Else the ship is already being pushed
		switch(rand(9))																// 2-in-10 chance the any of the first two actions happens
		{
			case 0: fRotate -= 0.01; break;											// Take the original rotate impulse and push a bit either way
			case 1: fRotate += 0.01; break;											// Not just to port
			fRotate = arCharShip.stormimp;											// Else set the impulse to what it was before the storm push
			DeleteAttribute(arCharShip,"stormimp");									// Remove it because the ship is not being pushed either way by the storm anymore
		}
		arCharShip.Impulse.Rotate.y = fRotate;										// Apply the new rotate impulse to the ship, which may include a storm push
	}
	else																			// If the storm has ended
	{
		if(CheckAttribute(arCharShip, "stormimp"))									// And if the ship is still having a storm push, eg. there is a stored rotate impulse
		{
			arCharShip.Impulse.Rotate.y = arCharShip.stormimp;						// Set the impulse to what it was before the storm push, eg. stop her turning
			DeleteAttribute(arCharShip,"stormimp");									// Remove it because the ship is no longer in the storm
		}
	}
// PB: Rewritten Storm Rotate Impulse <--

	if (bTornado && bSeaActive)
	{
//placed here by MAXIMUS -->
		fWindAttack = 1.0 - abs(fWindDotShip);

		fDamageMultiply = fStormProfessional * Bring2Range(0.25, 1.0, 0.0, 1.0, fWindAttack);

		// hull damage
// NK -->
		fDamageHP = (sqrt(fBaseShipHP) / 10);
// NK <--
//placed here by MAXIMUS <--
		float fTornadoDistance = GetDistance2D(stf(Tornado.x), stf(Tornado.z), stf(arCharShip.Pos.x), stf(arCharShip.Pos.z));
		float fTornadoDamageMultiply = fStormProfessional * Bring2Range(1.0, 0.0, 0.0, 100.0, fTornadoDistance);

		// hull damage
		Ship_ApplyHullHitpoints(rCharacter, fTornadoDamageMultiply * (fBaseShipHP / 100.0) * 8.5, KILL_BY_TOUCH, -1);

		// sails damage
		switch (MakeInt(fSailState * 2.0))
		{
			case 0: MakeSailDmg(iCharacterIndex, fTornadoDamageMultiply * (fBaseSailHP / 100.0) * 1.5); break;
			case 1: MakeSailDmg(iCharacterIndex, fTornadoDamageMultiply * (fBaseSailHP / 100.0) * 4.5); break;
			case 2: MakeSailDmg(iCharacterIndex, fTornadoDamageMultiply * (fBaseSailHP / 100.0) * 8.5); break;
		}
//placed here by MAXIMUS -->
		fExp = (rand((GetShipSkill(rCharacter,SKILL_SAILING)-1))+1) * (5.0 - fWindAttack) * fDamageHP;
		if (!bDead)
		{
			if(AUTO_SKILL_SYSTEM)
			{
				Ship_AddDelayedCumXP(rCharacter, "Sailing", MakeInt(fExp));
			}
			else
			{
				Ship_AddCharacterExp(rCharacter, MakeInt(fExp));
			}
		}
//placed here by MAXIMUS <--
	}

// Expirience log section
	if (iCharacterIndex == GetMainCharacterIndex() && bSeaActive)
	{
		fSeaExpTimer = fSeaExpTimer + 1.0;
		if (fSeaExpTimer >= 15.0 && bStorm)
		{
			fSeaExpTimer = 0.0;
			fSeaExp = 0.0;
		}
	}

// Apply arcade mode
// NK switch to using defines -->
	if (iRealismMode == 0 && !REALISTIC_SHIP_INERTIA)
	{
		arCharShip.MaxSpeedZ = ARCADE_MULT_SPEED * stf(arCharShip.MaxSpeedZ);
		arCharShip.MaxSpeedY =	ARCADE_MULT_TURN* stf(arCharShip.MaxSpeedY);
	}
// NK <--

	// Recalculate Cargo Load if need
	if (CheckAttribute(rCharacter, "Ship.Cargo.RecalculateCargoLoad") && sti(rCharacter.Ship.Cargo.RecalculateCargoLoad))
	{
		RecalculateCargoLoad(rCharacter);
		rCharacter.Ship.Cargo.RecalculateCargoLoad = 0;
	}
	//LanguageCloseFile(tmpLangFileID);
}

void Ship_TornadoDamage()
{
	float fTime = GetEventData();

	Tornado.x = GetEventData();
	Tornado.z = GetEventData();
}

void Ship_UpdateTmpSkills(ref rCharacter)
{
	rCharacter.TmpSkill = "";

	aref aTmpSkill; makearef(aTmpSkill, rCharacter.TmpSkill);

	// NK -->
	//float mult = 1.0;
	//bool bcomp = true;
	//string tmp; // 04-09-15
	/*if(!IsCompanion(rCharacter))
	{
		bcomp = false;
		//Seeing the randofficers attribute was never removed this was set the first time you went to sea and after that it wasn't changed anymore
		//So effectivly this never worked so for now I remove it to see how it goes -Levis
		/*if(CheckAttribute(rCharacter, "randofficers"))
		{
			mult = stf(rCharacter.randofficers);
			//unneeded, already clamped. 04-09-15
			/*if(mult < 1.0) mult = 1.0;
			if(mult > 4.0) mult = 4.0;*/
		/*}
		else
		{
			int sclass = GetCharacterShipClass(rCharacter);
			sclass = 8-sclass;
			mult += (fRand(GetOfficersQuantity(GetMainCharacter()))/3.0 + sclass/6.0 + fRand(sclass/6.0)) * (0.5 + makefloat(GetDifficulty()-1.0)/3.0);
			if(mult < 1.0) mult = 1.0;
			if(mult > 4.0) mult = 4.0;
			rCharacter.randofficers = mult;
			//Log_SetStringToLog("Fantom " + rCharacter.id + ", (" + rCharacter.name + " " + rCharacter.lastname + ") has mult " + mult);
		}*/
		//Every call too this goes trough the shipstatsmult object so why save it for the character? - Levis
		/*if(!CheckAttribute(rCharacter,"skillnatmult")) // lookup to speed up national skill mults. 04-09-15
		{
			for(int i = 0; i < 10; i++)
			{ tmp = GetSkillName(i); rCharacter.skillnatmult.(tmp) = GetSkillMultByNation(tmp, sti(rCharacter.nation)); }
			/*rCharacter.skillnatmult.(SKILL_COMMERCE) = GetSkillMultByNation(SKILL_COMMERCE, sti(rCharacter.nation));
			rCharacter.skillnatmult.(SKILL_LEADERSHIP) = GetSkillMultByNation(SKILL_LEADERSHIP, sti(rCharacter.nation));
			rCharacter.skillnatmult.(SKILL_SNEAK) = GetSkillMultByNation(SKILL_SNEAK, sti(rCharacter.nation));
			rCharacter.skillnatmult.(SKILL_DEFENCE) = GetSkillMultByNation(SKILL_DEFENCE, sti(rCharacter.nation));
			rCharacter.skillnatmult.(SKILL_GRAPPLING) = GetSkillMultByNation(SKILL_GRAPPLING, sti(rCharacter.nation));
			rCharacter.skillnatmult.(SKILL_SAILING) = GetSkillMultByNation(SKILL_SAILING, sti(rCharacter.nation));
			rCharacter.skillnatmult.(SKILL_REPAIR) = GetSkillMultByNation(SKILL_REPAIR, sti(rCharacter.nation));
			rCharacter.skillnatmult.(SKILL_FENCING) = GetSkillMultByNation(SKILL_FENCING, sti(rCharacter.nation));
			rCharacter.skillnatmult.(SKILL_ACCURACY) = GetSkillMultByNation(SKILL_ACCURACY, sti(rCharacter.nation));
			rCharacter.skillnatmult.(SKILL_CANNONS) = GetSkillMultByNation(SKILL_CANNONS, sti(rCharacter.nation));*/
		//}
	//}
	// calc skills for speed optimization
	// NK uncommented commerce and leadership 04-09-10, you never know when they'd be needed, esp. leadership.
	// NK PRS3 04-09-10 added mult by shipstatsmult for nation
	// 04-09-15 switched to attribute.
	//if(IsCompanion(rCharacter))
	//{
	//There is no difference anymore between if character is a companion or not so this makes the function easier. -Levis
		aTmpSkill.Commerce   = Clampf(MakeFloat(GetShipSkill(rCharacter, SKILL_COMMERCE  )) / MAX_CHARACTER_SKILL);
		aTmpSkill.Leadership = Clampf(MakeFloat(GetShipSkill(rCharacter, SKILL_LEADERSHIP)) / MAX_CHARACTER_SKILL);
		aTmpSkill.Sneak      = Clampf(MakeFloat(GetShipSkill(rCharacter, SKILL_SNEAK     )) / MAX_CHARACTER_SKILL);
		aTmpSkill.Defence    = Clampf(MakeFloat(GetShipSkill(rCharacter, SKILL_DEFENCE   )) / MAX_CHARACTER_SKILL);
		aTmpSkill.Grappling  = Clampf(MakeFloat(GetShipSkill(rCharacter, SKILL_GRAPPLING )) / MAX_CHARACTER_SKILL);
		aTmpSkill.Sailing    = Clampf(MakeFloat(GetShipSkill(rCharacter, SKILL_SAILING   )) / MAX_CHARACTER_SKILL);
		aTmpSkill.Repair     = Clampf(MakeFloat(GetShipSkill(rCharacter, SKILL_REPAIR    )) / MAX_CHARACTER_SKILL);
		aTmpSkill.Fencing    = Clampf(MakeFloat(GetShipSkill(rCharacter, SKILL_FENCING   )) / MAX_CHARACTER_SKILL);
		aTmpSkill.Accuracy   = Clampf(MakeFloat(GetShipSkill(rCharacter, SKILL_ACCURACY  )) / MAX_CHARACTER_SKILL);
		aTmpSkill.Cannons    = Clampf(MakeFloat(GetShipSkill(rCharacter, SKILL_CANNONS   )) / MAX_CHARACTER_SKILL);
	/*{
	else
	{
		aTmpSkill.Commerce   = Clampf(mult * MakeFloat(GetShipSkill(rCharacter, SKILL_COMMERCE  ))) / MAX_CHARACTER_SKILL);
		aTmpSkill.Leadership = Clampf(mult * MakeFloat(GetShipSkill(rCharacter, SKILL_LEADERSHIP))) / MAX_CHARACTER_SKILL);
		aTmpSkill.Sneak      = Clampf(mult * MakeFloat(GetShipSkill(rCharacter, SKILL_SNEAK     ))) / MAX_CHARACTER_SKILL);
		aTmpSkill.Defence    = Clampf(mult * MakeFloat(GetShipSkill(rCharacter, SKILL_DEFENCE   ))) / MAX_CHARACTER_SKILL);
		aTmpSkill.Grappling  = Clampf(mult * MakeFloat(GetShipSkill(rCharacter, SKILL_GRAPPLING ))) / MAX_CHARACTER_SKILL);
		aTmpSkill.Sailing    = Clampf(mult * MakeFloat(GetShipSkill(rCharacter, SKILL_SAILING   ))) / MAX_CHARACTER_SKILL);
		aTmpSkill.Repair     = Clampf(mult * MakeFloat(GetShipSkill(rCharacter, SKILL_REPAIR    ))) / MAX_CHARACTER_SKILL);
		aTmpSkill.Fencing    = Clampf(mult * MakeFloat(GetShipSkill(rCharacter, SKILL_FENCING   ))) / MAX_CHARACTER_SKILL);
		aTmpSkill.Accuracy   = Clampf(mult * MakeFloat(GetShipSkill(rCharacter, SKILL_ACCURACY  ))) / MAX_CHARACTER_SKILL);
		aTmpSkill.Cannons    = Clampf(mult * MakeFloat(GetShipSkill(rCharacter, SKILL_CANNONS   ))) / MAX_CHARACTER_SKILL);
	}*/
	// NK <--
	//Seriously why ... -Levis
	/*
	if (SeaCameras.Camera == "SeaDeckCamera" && sti(rCharacter.index) == GetMainCharacterIndex())
	{
		switch (GetTargetPlatform())
		{
			case "xbox":
				aTmpSkill.Accuracy = 1.0;
			break;
			case "pc":
				if(iRealismMode == 0) // 1.03
				{
					aTmpSkill.Accuracy = Clampf(stf(aTmpSkill.Accuracy) + 0.4);
				}
			break;
		}
	}*/
}

void Ship_UpdatePerks()
{
	int iCharacterIndex = GetEventData();
	ref rCharacter = GetCharacter(iCharacterIndex);

	//Trace("Ship_UpdatePerks: rCharacter.id = " + rCharacter.id);

	rCharacter.TmpPerks = "";
	aref aTmpPerks; makearef(aTmpPerks, rCharacter.TmpPerks);

	// calc perks for speed optimization
	if (!CheckAttribute(rCharacter, "TmpPerks.Turn")) {	rCharacter.TmpPerks.Turn = 0; }

	/*aTmpPerks.FastReload				= CheckOfficersPerk(rCharacter, "FastReload");
	aTmpPerks.ImmediateReload			= CheckOfficersPerk(rCharacter, "ImmediateReload");
	aTmpPerks.HullDamageUp			 	= CheckOfficersPerk(rCharacter, "HullDamageUp");
	aTmpPerks.CrewDamageUp				= CheckOfficersPerk(rCharacter, "CrewDamageUp");
	aTmpPerks.CriticalShoot				= CheckOfficersPerk(rCharacter, "CriticalShoot");
	aTmpPerks.LongRangeShoot			= CheckOfficersPerk(rCharacter, "LongRangeShoot");
	aTmpPerks.CannonProfessional		= CheckOfficersPerk(rCharacter, "CannonProfessional");
	aTmpPerks.LongRangeGrappling		= CheckOfficersPerk(rCharacter, "LongRangeGrappling");
	aTmpPerks.MusketsShoot				= CheckOfficersPerk(rCharacter, "MusketsShoot");				// !!!!
	aTmpPerks.GrapplingProfessional		= CheckOfficersPerk(rCharacter, "GrapplingProfessional");
	aTmpPerks.BasicDamageControl			= CheckOfficersPerk(rCharacter, "BasicDamageControl");
	aTmpPerks.AdvancedDamageControl			= CheckOfficersPerk(rCharacter, "AdvancedDamageControl");
	aTmpPerks.ProfessionalDamageControl		= CheckOfficersPerk(rCharacter, "ProfessionalDamageControl");
	aTmpPerks.BasicFirstAid				= CheckOfficersPerk(rCharacter, "BasicFirstAid");
	aTmpPerks.AdvancedFirstAid			= CheckOfficersPerk(rCharacter, "AdvancedFirstAid");
	aTmpPerks.Rigging				= CheckOfficersPerk(rCharacter, "Rigging");
	aTmpPerks.RiggingAdvance			= CheckOfficersPerk(rCharacter, "RiggingAdvance");
	aTmpPerks.ShipSpeedUp				= CheckOfficersPerk(rCharacter, "ShipSpeedUp");
	aTmpPerks.ShipTurnRateUp			= CheckOfficersPerk(rCharacter, "ShipTurnRateUp");
	aTmpPerks.StormProfessional			= CheckOfficersPerk(rCharacter, "StormProfessional");			// !!!!
	aTmpPerks.SandbankManeuver			= CheckOfficersPerk(rCharacter, "SandbankManeuver");
	aTmpPerks.SailingProfessional		= CheckOfficersPerk(rCharacter, "SailingProfessional");
	aTmpPerks.IronWill				= CheckOfficersPerk(rCharacter, "IronWill"); // NK 05-04-20

	aTmpPerks.LightRepair				= CheckOfficersPerk(rCharacter, "LightRepair");*/
	
	//Levis make sure all perks are checked -->
	//Let check if something is changed in the meantime, if not we shouldn't bother changing it.
	aref PerkList,CurPerk;
	string PerkName;
	makearef(PerkList,ChrPerksList.list);
	int dn = GetAttributesNum(PerkList);
	
	for(int i=0; i<dn; i++)
	{
		CurPerk = GetAttributeN(PerkList,i);
		PerkName = GetAttributeName(CurPerk);
		aTmpPerks.(PerkName) = CheckOfficersPerk(rCharacter, PerkName);
	}
	//Levis make sure all perks are checked <--
	
	// update main character if rCharacter is companion
	/*if (iCharacterIndex != GetMainCharacterIndex() && IsCompanion(rCharacter))
	{
		Event("eSwitchPerks", "l", GetMainCharacterIndex());
	}*/
	//Levis this is handled in the perk check already
}

void Ship_Lightning()
{
	if (!bSeaActive) { return; }

	float x = GetEventData();
	float y = GetEventData();
	float z = GetEventData();

	for (int i=0; i<iNumShips; i++)
	{
		if(i==SHIP_BOAT || i==SHIP_NOTUSED || Ships[i] < 0) continue;//MAXIMUS // KK
		ref rCharacter = GetCharacter(Ships[i]);
		aref arShipChar; makearef(arShipChar, rCharacter.Ship);

		float sx = stf(arShipChar.Pos.x);
		float sy = stf(arShipChar.Pos.y);
		float sz = stf(arShipChar.Pos.z);
		float bx = stf(arShipChar.BoxSize.x);
		float by = stf(arShipChar.BoxSize.y);
		float bz = stf(arShipChar.BoxSize.z);
		float fDist = GetDistance2D(x, z, sx, sz);
		float fMinLightningDist = 20.0 + bz / 1.5;
		if (fDist < fMinLightningDist)
		{
			int iMinBoom = MakeInt(Bring2Range(5.0, 2.0, 1.0, 7.0, stf(GetCharacterShipClass(rCharacter))));
			float fCos = cos(stf(arShipChar.Ang.y));
			float fSin = sin(stf(arShipChar.Ang.y));
			iMinBoom += rand(2);	// LDH moved outside for loop test, just in case - 25Mar09
			for (int k=0; k<iMinBoom; k++)
			{
				float dx = 0.6 * bx * (frnd() - 0.5);
				float dz = 0.7 * bz * (frnd() - 0.5);
				RotateAroundY(&dx, &dz, fCos, fSin);
				Ship_Serious_Boom(sx + dx, sy + 0.1 * by * frnd(), sz + dz);
			}

			if (!LAi_IsImmortal(rCharacter)) 									Ship_ApplyHullHitpoints(rCharacter, iMinBoom * 40.0, KILL_BY_TOUCH, -1); // KK
			if (!LAi_IsImmortal(rCharacter) && !LAi_IsCrewImmortal(rCharacter))	Ship_ApplyCrewHitpoints(rCharacter, MakeFloat(rand(3))); // KK

			int iNumFirePlaces = 0;
			SendMessage(rCharacter, "le", MSG_SHIP_GET_NUM_FIRE_PLACES, &iNumFirePlaces);

			float fFirePlaces = Bring2Range(1.0, 0.1, 0.0, fMinLightningDist, fDist);

			float fCurr = 0.0;
			float fTest = (1.0 - fFirePlaces) * iNumFirePlaces;
			for (int j=0; j<iNumFirePlaces; j++)
			{
				fCurr = fCurr + 1.0;
				if (fCurr < fTest) { continue; }

				fCurr = 0.0;
				int iRandStartTime = rand(10000);
				float fTotalFireTime = Ship_GetTotalFireTime(rCharacter);

				PostEvent(SHIP_ACTIVATE_FIRE_PLACE, iRandStartTime, "ialsf", rCharacter, rCharacter, j, "ship_onfire", fTotalFireTime);
				PostEvent(SHIP_FIRE_DAMAGE, iRandStartTime, "lllf", Ships[i], -1, j, fTotalFireTime);
			}
		}
	}
}

int Ship_GetRunAwayPoint()
{
	aref arChar = GetEventData();
	float fX = GetEventData();
	float fZ = GetEventData();

	float fRadius = 10000.0;
	float fWindAngle = Whr_GetWindAngle();

	arChar.SeaAI.WindAngle = fWindAngle;
	arChar.SeaAI.RunAwayPnt.x = stf(arChar.Ship.Pos.x) + fRadius * sin(fWindAngle);
	arChar.SeaAI.RunAwayPnt.z = stf(arChar.Ship.Pos.z) + fRadius * cos(fWindAngle);

	return 0;
}

// Create a new ship for character
void Ship_CreateForCharacter(ref rCharacter, string sShipType, string sShipName) // KK
{
	int iShipType = GetShipIndex(sShipType); // KK
	if (iShipType < 0 || iShipType == SHIP_NOTUSED) return; // KK
	DeleteAttribute(rCharacter, "Ship");

	rCharacter.Ship.Type = sShipType; // PS // KK
	rCharacter.Ship.Name = sShipName;

	if (CANNONPOWDER_MOD) {// TIH --> mod toggle 7-7-06
		//rCharacter.Ship.Gunpowder = GetCargoGoods(rCharacter, GOOD_GUNPOWDER); // added by MAXIMUS [gunpowder mod]
		// added by MAXIMUS [gunpowder mod] -->
		int fireGunpowder = 0;
		ref rCannon; makeref(rCannon,Cannon[GetCaracterShipCannonsType(rCharacter)]);
		if(CheckAttribute(rCannon,"gunpowder")) fireGunpowder = sti(rCannon.gunpowder)*sti(GetCannonCurQuantity(rCharacter));
		if(fireGunpowder<GetCargoGoods(rCharacter, GOOD_GUNPOWDER))
		{
			rCharacter.Ship.Cannons.Charge.Type = GOOD_BALLS; // KNB
		}
		// added by MAXIMUS [gunpowder mod] <--
	}// TIH <-- mod toggle

	rCharacter.Ship.Cannons.Borts = "";
//	rCharacter.Ship.Cannons.Charge.Type = GOOD_BALLS; // KNB
	rCharacter.Ship.Ang.y = 0.0;
	if (iShipType != SHIP_FORT) // PB: Don't overwrite this for forts
	{
		rCharacter.Ship.Pos.x = 0.0;
		rCharacter.Ship.Pos.z = 0.0;
	}
	rCharacter.Ship.Speed.z = 0.0;

	SetBaseShipData(rCharacter);
}

void Ship_ClearImpulseStrength(ref rCharacter)
{
	aref arImpulse; makearef(arImpulse, rCharacter.Ship.Impulse);
	arImpulse.Rotate.x = 0.0;
	arImpulse.Rotate.y = 0.0;
	arImpulse.Rotate.z = 0.0;
	arImpulse.Speed.x = 0.0;
	arImpulse.Speed.y = 0.0;
	arImpulse.Speed.z = 0.0;
}

void Ship_PrepareShipForLocation(ref rCharacter)
{
	Ship_ClearImpulseStrength(rCharacter);
}

// START MOD Code by Stone-D : 01/08/2003
void Whack_Ship(ref rCharacter) // Stone-D : Not working. Only eye candy, put on hold.
{
/*
	aref arShipChar;
	int iRandStartTime = 0;
	int iNumFirePlaces = 0;
	float fFirePlaces = 0.0;
	float fTotalFireTime = 0.0;
	float fCurr = 0.0;
	float fTest = 0.0;


	makearef(arShipChar, rCharacter.Ship);

	SendMessage(rCharacter, "le", MSG_SHIP_GET_NUM_FIRE_PLACES, &iNumFirePlaces);

//	fFirePlaces = Bring2Range(1.0, 0.1, 0.0, 0.1, 1.0);
	fFirePlaces = rand(iNumFirePlaces);
	fTest = (1.0 - fFirePlaces) * iNumFirePlaces;

	for (int j=0; j<iNumFirePlaces; j++)
	{
		fCurr = fCurr + 1.0;
		if (fCurr < fTest) { continue; }

		fCurr = 0.0;
//		int iRandStartTime = rand(10);
//		fTotalFireTime = rand(30);

		PostEvent(SHIP_ACTIVATE_FIRE_PLACE, 1, "ialsf", arShipChar, rCharacter, j, "ship_onfire", rand(30));
//		PostEvent(SHIP_FIRE_DAMAGE, 0, "lllf", iOurCharacterIndex, iBallCharacterIndex, iFirePlaceIndex, rand(30));
//		PostEvent(SHIP_FIRE_DAMAGE, 0, "lllf", Ships[i], -1, j, fTotalFireTime);
	}
*/
}
// END MOD Code by Stone-D : 01/07/2003

// NK realistic sailing -->
float RS_GetRigTypeDivisor(string sDet, float fOffWind)
{
	float fDivisor = 1.0;
	switch(sDet)
	{
		case "Fsc": return(RS_GetRigTypeDivisor("Gat", fOffWind) + RS_GetRigTypeDivisor("Slo", fOffWind))/2; break; // NK new div for JMV's fast sch.
		case "shn": return RS_GetRigTypeDivisor("bri", fOffWind); break; //return(RS_GetRigTypeDivisor("Gat", fOffWind) + RS_GetRigTypeDivisor("Slo", fOffWind))/2; break; // NK new div for AM shnyava
		case "btn": return(RS_GetRigTypeDivisor("bri", fOffWind) + RS_GetRigTypeDivisor("Slo", fOffWind))/2; break; // NK new div for AM brigantine
		case "Xeb":
			if(fOffWind > 0.01) { fDivisor = sqrt(sqrt(sqrt(sqrt((fOffWind * 0.9) ^ 3)))) * 0.9785; }
			else { fDivisor = 0.25; }
			break;

		case "Tar":
			if(fOffWind > 0.01) { fDivisor = sqrt(sqrt(sqrt(sqrt((fOffWind * 0.9) ^ 3)))) * 0.9785; }
			else { fDivisor = 0.25; }
			break;

		case "Sch":
			if(fOffWind > 0.01) { fDivisor = sqrt(sqrt(sqrt(sqrt((fOffWind * 0.9) ^ 3)))) * 0.9785; }
			else { fDivisor = 0.25; }
			break;

		case "Lug":
			if(fOffWind > 0.01) { fDivisor = 1.2433*fOffWind ^ 3 - 2.7092*fOffWind ^ 2 + 2.0879*fOffWind + 0.3779; }
			else { fDivisor = 0.38; }
			break;

		case "Gal":
			if(fOffWind > 0.01) { fDivisor = 0.7467 * fOffWind ^ 3 - 1.9657*fOffWind ^ 2 + 1.839*fOffWind + 0.3803; }
			else { fDivisor = 0.38; }
			break;

		case "Gat":
			if(fOffWind > 0.01) { fDivisor = 1.2433*fOffWind ^ 3 - 2.7092*fOffWind ^ 2 + 2.0879*fOffWind + 0.3779; }
			else { fDivisor = 0.38; }
			break;

		case "Cor":
			if(fOffWind > 0.01) { fDivisor = 1.2433*fOffWind ^ 3 - 2.7092*fOffWind ^ 2 + 2.0879*fOffWind + 0.3779; }
			else { fDivisor = 0.39; }
			break;

		case "Car":
			if(fOffWind > 0.01) { fDivisor = 1.2433*fOffWind ^ 3 - 2.7092*fOffWind ^ 2 + 2.0879*fOffWind + 0.3779; }
			else { fDivisor = 0.39; }
			break;

		case "Bar":
			if(fOffWind > 0.01) { fDivisor = 1.2433*fOffWind ^ 3 - 2.7092*fOffWind ^ 2 + 2.0879*fOffWind + 0.3779; }
			else { fDivisor = 0.39; }
			break;

		case "Yac":
			if(fOffWind > 0.01) { fDivisor = 1.2433*fOffWind ^ 3 - 2.7092*fOffWind ^ 2 + 2.0879*fOffWind + 0.3779; }
			else { fDivisor = 0.39; }
			break;

		//default:  // scheffnow - bfd
			if(fOffWind > 0.01) { fDivisor = 0.7467 * fOffWind ^ 3 - 1.9657*fOffWind ^ 2 + 1.839*fOffWind + 0.3803; }
			else { fDivisor = 0.38; }
	}
	return fDivisor;
}

// NK 04-09-19 move some RS funcs here instead of as part of UpdateParams.
#define RS_SCALAR		1.0 //scales all speeds
#define RS_BACKWIND	-0.25 //speed backwinded
#define RS_CP_OFFSET	0.02 // fudge on either side of Closest Point

float RS_CalcOffwind(float fWindAngle, float fShipAngle)
{
	// logit("CalcOffwind");
	float fOffWind = 0; // = AngleOffAngle(fWindAngle, fShipAngle); // use generic function 05-04-18 NOT DONE YET!
	fWindAngle = ClampAngle(fWindAngle);
	fShipAngle = ClampAngle(fShipAngle);
	//find difference Mith

	if(fShipAngle >= fWindAngle && fShipAngle - fWindAngle <= PI) fOffWind = abs(fShipAngle - fWindAngle);
	else
	{
		if(fShipAngle < fWindAngle && fWindAngle - fShipAngle <= PI) fOffWind = abs(fShipAngle - fWindAngle);
		else
		{
			if(fShipAngle >= fWindAngle && fShipAngle - fWindAngle > PI) fOffWind = PIm2 - abs(fShipAngle - fWindAngle);
			else
			{
				if(fShipAngle < fWindAngle && fWindAngle - fShipAngle > PI) fOffWind = PIm2 - abs(fShipAngle - fWindAngle);
			}
		}
	}
	fOffWind = 1 - (fOffWind / PI);
	return fOffWind;
}

float RS_CalcSpeedScalar(float fClosestPoint, float fBestPoint, string rigtype, float fOffWind, float fWindPower)
{
	// logit("CalcSpeedScalar");
	float	fRBWMax = sqrt(sqrt(sqrt(fClosestPoint))) +0.02; //Max speedscalar running before the wind, as ratio of max speed. Constant.
	float	fBeam = 1 / (20 * sqrt(fClosestPoint ^ 3)) +0.3; //Max speedscalar on a beam reach. Derived from fClosestPoint for now. Constant.
	float	fTackSpeed = 1 / (sqrt(fClosestPoint) * 4); //minimum speed on a tack, i.e. speed at fOffWind = closestpoint - RS_CP_OFFSET. Constant.

	//begin speedscalar calcs
	float fTempSpeedZ = 1.0; // PRS3 and below
	//reorganized we only do one b2r calc.
	if (fOffWind > fBestPoint) {
		fTempSpeedZ = Bring2Range(1.0, fRBWMax, fBestPoint, 1.0, fOffWind); //scale speedscalar between best point of sail and running before the wind
	} else {
		if (fOffWind > 0.5) {
			fTempSpeedZ = Bring2Range(fBeam, 1.0, 0.5, fBestPoint, fOffWind); //scale speedscalar between beam reach and best point of sail
		} else {
			if (fOffWind > fClosestPoint + RS_CP_OFFSET) {
				fTempSpeedZ = Bring2Range(fTackSpeed, fBeam, fClosestPoint + RS_CP_OFFSET, 0.5, fOffWind); //fixed by Hook
			} else {
				if (fOffWind > fClosestPoint - RS_CP_OFFSET) {
					fTempSpeedZ = Bring2Range(0.0, fTackSpeed, fClosestPoint - RS_CP_OFFSET, fClosestPoint + RS_CP_OFFSET, fOffWind); //ramp quickly from 0 to min speed with wind
				} else {
					if (fClosestPoint > 0.24)
						fTempSpeedZ = Bring2Range(RS_BACKWIND, 0.0, 0.0, fClosestPoint - RS_CP_OFFSET, fOffWind); //allow backwards travel
					else
						fTempSpeedZ = 0.0; //if not square rigged, can't be pushed back
				}
			}
		}
	}
    
    if (fTempSpeedZ > 1.0) //FlayedOne
    {
        fTempSpeedZ = 1.0
    }
	//end speedscalar calcs

	//begin calcs for fudge to offset EXE's speed scaling.
	float	fDivisor = RS_GetRigTypeDivisor(rigtype, fOffWind); // PRS3 yipes big typo 04-09-12
	//end fudge calcs

	//calc wind modifier based on ship weight--big ships can ride out storms and carry more canvas in them
	float fWindMod = fWindPower;
	/*if(fWindPower >= 1.0)
	{
		fWindMod -= (1 - fWindPower / sqrt(sqrt(arCharShip.Weight)) * 10);
		if(fWindMod < 0.25) fWindMod = 0.25;
	}*/

	//fudge deceleration -- seems to be not needed, but I'm not sure. So right now the implementation is commented out.
	//float fPreDecel = fTempScalar * fTempSpeedZ * fWindMod / fDivisor;
//	Log_SetStringToLog("PreD: " + arCharShip.MaxSpeedZ);
//	Log_SetStringToLog("Brk1: " + stf(rShip.InertiaBrakingZ));
//	rShip.InertiaBrakingZ = 0.75
//	Log_SetStringToLog("Brk2: " + stf(rShip.InertiaBrakingZ));
//	Log_SetStringToLog("AccBot: " + stf(rShip.InertiaAccelerationZ));
//	Log_SetStringToLog("SpdRt: " + fMaxSpeedZ);
	/*if(fPreDecel < arCharShip.MaxSpeedZ - stf(rShip.InertiaBrakingZ) && arCharShip.MaxSpeedZ - stf(rShip.InertiaBrakingZ) > 0 && arCharShip.MaxSpeedZ > 1.5) arCharShip.MaxSpeedZ = arCharShip.MaxSpeedZ - stf(rShip.InertiaBrakingZ);
	else*/
	return (RS_SCALAR* fTempSpeedZ * fWindMod / fDivisor);

}

//returns time in seconds for arship (char.ship) to travel dist units at given angle.
int GetTimeToSailDist(aref arship, float dist, float angle)
{
	ref rShip = GetShipByID(arship.type);
// KK -->
	float	fClosestPoint = DEFAULT_CLOSESTPOINT;
	if (CheckShipAttribute(arship, rShip, "ClosestPoint")) fClosestPoint = stf(GetLocalShipAttrib(arship, rShip, "ClosestPoint")); //Closest point of sail

	float	fBestPoint = DEFAULT_BESTPOINT;
	if (CheckShipAttribute(arship, rShip, "BestPoint")) fBestPoint = stf(GetLocalShipAttrib(arship, rShip, "BestPoint")); //Best point of sail

	string rigtype = "Fri";
	if (CheckShipAttribute(arship, rShip, "RigType")) rigtype = GetLocalShipAttrib(arship, rShip, "RigType");
// <-- KK

	//get angles
	float	fWindAngle = Whr_GetWindAngle();
	float fWindPower = Whr_GetWindSpeed() / WIND_NORMAL_POWER;
	float fOffWind = RS_CalcOffWind(angle,fWindAngle);
	float speed = stf(GetLocalShipAttrib(arship, rShip, "speedrate")); if(CheckAttribute(arship,"speedmult")) speed = stf(arship.speedmult); // get sail state, load, speedperk, and mult by speedrate
	if(iRealismMode == 0) return makeint(dist/(fWindPower * speed * (0.5+fOffWind/2.0)));
	if(fOffWind < fClosestPoint) { fOffWind = fClosestPoint; speed *= 0.5; } //assume tacking takes twice as long.

	speed *= RS_CalcSpeedScalar(fClosestPoint, fBestPoint, rigtype, fOffWind, fWindPower); // apply RS scaling
	if (speed < 1.0) speed = 1.0;		// LDH prevent zero speeds causing infinite loop 9Feb09
	//we know that at 1 knot we cover 0.5 units per second
	return makeint(dist/(speed/2.0));
}
// NK <--

// LDH -- making luffing sounds more random
#event_handler("luffing_event", "PlayLuffSound");
void PlayLuffSound()
{
	switch (Rand(2))
	{
	case 0:
		PlaySound("AMBIENT\SEA\sails1.wav");
		break;
	case 1:
		PlaySound("AMBIENT\SEA\sails2.wav");
		break;
	case 2:
 		PlaySound("AMBIENT\SEA\sails3.wav");
		break;
	}
}

// KK -->
void RemoveShipFromSea(int idx)
{
	if (idx < 0) return;
	ref shipchar = GetCharacter(idx);
	// Message to AI
	SendMessage(AISea, "la", AI_MESSAGE_CHARACTER_DEAD, shipchar);
	// Event
	Event(SHIP_DEAD, "l", idx);
}

void SwapCabinChests(int cidx, int eidx)
{
	if (cidx < 0 || eidx < 0) return;
	ref rCompanion = GetCharacter(cidx);
	ref rEnemy = GetCharacter(eidx);
	ref mchr = GetMainCharacter();
	int cn1 = GetCompanionNumber(mchr, cidx);
	string ccabin = "Tutorial_Deck";
	if (cn1 > 0) ccabin = "Companion_Cabin_" + cn1;
	int cn2 = GetCompanionNumber(mchr, eidx);
	string ecabin = "Boarding_" + GetCharacterShipCabin(rEnemy);
	//if (cn2 > 0) ecabin = "Companion_Cabin_" + cn2;
	aref cweaponslocker; makearef(cweaponslocker, Locations[FindLocation(ccabin)].WeaponsLocker.items);
	aref eweaponslocker; makearef(eweaponslocker, Locations[FindLocation(ecabin)].WeaponsLocker.items);
	object otmp;
	ref rtmp; makeref(rtmp, otmp);
	CopyAttributes(rtmp, cweaponslocker);
	DeleteAttribute(cweaponslocker, "");
	CopyAttributes(cweaponslocker, eweaponslocker);
	CopyAttributes(eweaponslocker, rtmp);
}

void ShipMutiny()
{
	int cn, i, j, inum;
	ref chref, rOfficer;
	string ship_types[3];
	string ship_names[3];
	string char_names[3];
	ref mchref = GetMainCharacter();
	int mutineersqty = 0;
	bool bPlayerCompanion;
	for (i = 1; i < COMPANION_MAX; i++)
	{
		cn = GetCompanionIndex(mchref, i);
		if (cn < 0) continue;
		chref = GetCharacter(cn);
		if (IsMutineer(chref))
		{
			bPlayerCompanion = true;
			if (!GetRemovable   (chref))									bPlayerCompanion = false;
			if (sti(GetAttribute(chref, "CompanionEnemyEnable")) == true)	bPlayerCompanion = false;
			if (CheckAttribute(chref, "cancel_mutiny")) // PB: Cancel mutiny for pre-warned escort ships
			{
				SetMutineer(chref, false);
				continue;
			}
			if (bPlayerCompanion) // PB: Escort ships have no loyalty to you
			{
				if (rand(100) > 50)
				{
					RemoveCharacterCrew(chref, makeint(makefloat(GetCrewQuantity(chref)) / (1.0 + rand(4))));
					chref.Ship.Crew.Morale = MORALE_NORMAL - rand(makeint(10.0 * makefloat(MORALE_NORMAL) / (MORALE_MAX - MORALE_MIN)));
					SetMutineer(chref, false);
					LogIt(TranslateString("", "The crew of your") + " " + XI_ConvertString(GetShipString(GetCharacterShipType(chref))) + " " + GetMyShipNameShow(chref) + " " + TranslateString("", "commanded by") + " " + GetMySimpleName(chref) + " " + TranslateString("", "revolted, but the mutiny was successfully scotched") + ".");
					continue;
				}
				else
				{
					chref.skipRM     = true   ; // PB: Don't gain/lose points for this
					chref.FantomType = "trade"; // PB: No soldiers on companion ship
				}
			}
			bShipMutiny = true;			// PB: This is turned OFF again in the Sea_FirstInit function
			if (bSeaActive && !bAbordageStarted) SeaAI_SetCompanionEnemy(chref);

			// PB: Above neutral captains are loyal to above neutral commanders and would rather die, but escort ships have no loyalty to you
			if(GetCharacterReputation(chref) > REPUTATION_NEUTRAL && GetCharacterReputation(mchref) > REPUTATION_NEUTRAL && bPlayerCompanion)
			{
				Fantom_SetRandomModel(chref, "pirate");
				SetRandomNameToCharacter(chref);
			}

			// PB: For explanatory notes
			if (!IsEntity(&worldMap))
			{
				if (bPlayerCompanion)
				{
					LogIt(TranslateString("", "The crew of your") + " " + XI_ConvertString(GetShipString(GetCharacterShipType(chref))) + " " + GetMyShipNameShow(chref) + " " + TranslateString("", "commanded by") + " " + GetMySimpleName(chref) + " " + TranslateString("", "mutinied and turned against you") + ".");
				}
				else
				{
					LogIt(TranslateString("", "Captain") + " " + GetMySimpleName(chref) + " " + TranslateString("", "of the") + " " + XI_ConvertString(GetShipString(GetCharacterShipType(chref))) + " " + GetMyShipNameShow(chref) + " " + TranslateString("", "does not approve of your actions and turned against you") + ".");
					if(IsTrader(chref))
					{
						LAi_SetStayType(chref);
						chref.Dialog.Filename = "Cabinfight_dialog.c";
						mchref.quest.generate_convoy_quest.board = true;
						ChangeCharacterReputation(mchref, -10);
						DoQuestCheckDelay("convoy_failed", 0.0);
					}
				}
			}
			else
			{
				ship_types[mutineersqty] = XI_ConvertString(GetShipString(GetCharacterShipType(chref)));
				ship_names[mutineersqty] = GetMyShipNameShow(chref);
				char_names[mutineersqty] = GetMySimpleName(chref);
			}
			mutineersqty++;
		}
	}
	if (bSeaActive && !bAbordageStarted)
	{
		RefreshFlags();
		bShipMutiny = false;			// PB: Once is enough
	}
	if (IsEntity(&worldMap) && mutineersqty > 0) // PB: Not if mutiny has already been sorted
	{
		mchref.ShipEnc = "enemy";
		string totalInfo = TranslateString("", "The crew of your") + " ";
		if (mutineersqty > 1)
		{
			totalInfo = totalInfo + TranslateString("", "ships") + ": ";
			totalInfo = totalInfo + ship_types[0] + " " + ship_names[0] + " " + TranslateString("", "commanded by") + " " + char_names[0];
			if (mutineersqty == 2)
				totalInfo = totalInfo + " " + TranslateString("", "and") + " ";
			else
				totalInfo = totalInfo + ", ";
			totalInfo = totalInfo + ship_types[1] + " " + ship_names[1] + " " + TranslateString("", "commanded by") + " " + char_names[1];
			if (mutineersqty == 3) totalInfo = totalInfo + " " + TranslateString("", "and") + " " + ship_types[2] + " " + ship_names[2] + " " + TranslateString("", "commanded by") + " " + char_names[2];
		}
		else
		{
			totalInfo = totalInfo + ship_types[0] + " " + ship_names[0] + " " + TranslateString("", "commanded by") + " " + char_names[0];
		}
		totalInfo = totalInfo + " " + TranslateString("", "mutinied and turned against you") + "!";
		mchref.EncInfo = totalInfo;
		mchref.CanEscape = false;
		LaunchBoalMapScreen();
	}
}

void Ship_DoRaiseSails()
{
	ref mchr = GetMainCharacter();
	int iSailState = sti(mchr.LastSailState) + 1;
	if (iSailState > 2) return;
	Ship_SetSailState(GetMainCharacterIndex(), iSailState);
}

void Ship_DoLowerSails()
{
	ref mchr = GetMainCharacter();
	int iSailState = sti(mchr.LastSailState) - 1;
	if (iSailState < 0) return;
	Ship_SetSailState(GetMainCharacterIndex(), iSailState);
}
// <-- KK
