object	AIBalls;
aref	Grapes, Knippels, Balls, Bombs;

void DeleteBallsEnvironment()
{
	DeleteClass(&AIBalls);

	DelEventHandler(BALL_WATER_HIT,"Ball_WaterHitEvent");
	DelEventHandler(BALL_ISLAND_HIT,"Ball_IslandHit");
	DelEventHandler(BALL_FLY_UPDATE,"Ball_OnFlyUpdate");
	DelEventHandler(BALL_FORT_HIT,"Ball_FortHit");
}

void CreateBallsEnvironment()
{
	CreateEntity(&AIBalls, "AIBalls");
	LayerAddObject(SEA_EXECUTE, &AIBalls, -1);
	LayerAddObject(SEA_REALIZE, &AIBalls, 65532);
	// KNB -->
	if(USE_REAL_CANNONS)
	{
		AIBalls.SpeedMultiply = 1.0;
		AIBalls.Texture = "AllBalls.tga";
		AIBalls.SubTexX = 2;
		AIBalls.SubTexY = 2;
	
		makearef(Grapes,AIBalls.Balls.Grapes);
		makearef(Knippels,AIBalls.Balls.Knippels);
		makearef(Balls,AIBalls.Balls.Balls);
		makearef(Bombs,AIBalls.Balls.Bombs);
	//sizes reduced to more realistic scale by MM
		// Bombs
		Bombs.SubTexIndex = 0; Bombs.Size = 0.175; Bombs.GoodIndex = GOOD_BOMBS;
		//Bombs.Particle = "bomb_smoke";

		// Grapes
		Grapes.SubTexIndex = 1; Grapes.Size = 0.3; Grapes.GoodIndex = GOOD_GRAPES;

		// Balls
		Balls.SubTexIndex = 2; Balls.Size = 0.150; Balls.GoodIndex = GOOD_BALLS;

		// Knippels
		Knippels.SubTexIndex = 3; Knippels.Size = 0.4; Knippels.GoodIndex = GOOD_KNIPPELS;
	
		AIBalls.isDone = 1;
	}
	// KNB <--
	else
	{
		AIBalls.SpeedMultiply = 3.0;
		AIBalls.Texture = "AllBalls.tga";
		AIBalls.SubTexX = 2;
		AIBalls.SubTexY = 2;
	
		makearef(Grapes,AIBalls.Balls.Grapes);
		makearef(Knippels,AIBalls.Balls.Knippels);
		makearef(Balls,AIBalls.Balls.Balls);
		makearef(Bombs,AIBalls.Balls.Bombs);
	
		// Bombs
		Bombs.SubTexIndex = 0;		Bombs.Size = 0.3;		Bombs.GoodIndex = GOOD_BOMBS;
		Bombs.Particle = "bomb_smoke";
	
		// Grapes
		Grapes.SubTexIndex = 1;		Grapes.Size = 0.2;		Grapes.GoodIndex = GOOD_GRAPES;
	
		// Balls
		Balls.SubTexIndex = 2;		Balls.Size = 0.2;		Balls.GoodIndex = GOOD_BALLS;
	
		// Knippels
		Knippels.SubTexIndex = 3;	Knippels.Size = 0.2;	Knippels.GoodIndex = GOOD_KNIPPELS;
	
		AIBalls.isDone = 1;
	}

	SetEventHandler(BALL_WATER_HIT,"Ball_WaterHitEvent",0);
	SetEventHandler(BALL_ISLAND_HIT,"Ball_IslandHit",0);
	SetEventHandler(BALL_FLY_UPDATE,"Ball_OnFlyUpdate",0);
	SetEventHandler(BALL_FORT_HIT,"Ball_FortHit",0);
}

//int ballNumber;

void Ball_AddBall(aref aCharacter, float fX, float fY, float fZ, float fSpeedV0, float fDirAng, float fHeightAng, float fCannonDirAng, float fMaxFireDistance)
{
	bool BowChaserGreekFire = false; // PB: Queen Anne's Revenge's Bow Chasers
	float fTempDispersionY, fTempDispersionX, fAccuracy;
	if(CheckAttribute(aCharacter,"surrendered")) return; // surrendered chars don't fire. 05-04-20
	if(USE_REAL_CANNONS)
	{
		// NK can qty 05-04-18 -->
		float ourdir = clampangle(fDirAng);
		if (CheckAttribute(aCharacter,"ship.ang.y")) ourdir = clampangle(stf(aCharacter.Ship.Ang.y));
		//else trace("char " + aCharacter.id + " of ship " + aCharacter.ship.name + " has no angle!");
		if(aCharacter.ship.type != SHIP_FORT_NAME)
		{
			int quad = quadrantG(ourdir, clampangle(fCannonDirAng));
			int firedqty = 0;
			string quadstr = GetQuadName(quad);
			//trace("for char " + aCharacter.id + " of ship " + aCharacter.ship.name + " fire ball. Can ang " + makeint(Radian2Degree(fCannonDirAng)) + ", ship ang " + makeint(Radian2Degree(ourdir)) + " so quad " + GetQuadText(quad));
			aref arcan; makearef(arcan, aCharacter.ship.cannons.borts.(quadstr));
			/*switch(quad)
			{
				case 0: makearef(arcan, aCharacter.ship.cannons.borts.cannonf); quadstr = "cannonf"; break;
				case 1: makearef(arcan, aCharacter.ship.cannons.borts.cannonr); quadstr = "cannonr"; break;
				case 2: makearef(arcan, aCharacter.ship.cannons.borts.cannonb); quadstr = "cannonb"; break;
				case 3: makearef(arcan, aCharacter.ship.cannons.borts.cannonl); quadstr = "cannonl"; break;
			}*/
			if(CheckAttribute(arcan,"numfired"))
			{
				firedqty = sti(arcan.numfired);
				firedqty++; 
				arcan.numfired = firedqty;
				if(!CheckAttribute(arcan,"deleteme"))
				{
					if(CheckAttribute(aCharacter,"canfiretime")) arcan.deleteme = roundup(stf(aCharacter.canfiretime)+1.0);
					else arcan.deleteme = 2;
				}
			}
			else
			{
				firedqty++;
				arcan.numfired = firedqty;
				if (!CheckAttribute(arcan,"deleteme")) {
					if (CheckAttribute(aCharacter,"canfiretime"))
						arcan.deleteme = roundup(stf(aCharacter.canfiretime) + 1.0);
					else
						arcan.deleteme = 2;
				}
				// for more guns than the model supports:
				if (!CheckAttribute(arcan,"firingextra")) {
					ref rship = GetShipByType(GetCharacterShipType(&aCharacter));
					int cur, max;
					cur = sti(arcan.curqty);
					max = sti(rship.Cannons.Borts.(quadstr).qty);
					if (cur > max) {
						arcan.firingextra = true;
						for (int c = 0; c < max-cur; c++)
						{
							Ball_AddBall(&aCharacter, fX, fY, fZ, fSpeedV0, fDirAng, fHeightAng, fCannonDirAng, fMaxFireDistance);
						}
						DeleteAttribute(arcan,"firingextra");
					}
				}
			}
			//firedqty++;

			// There appeared to be a problem here... "firedqty" is being purged way too early before all cannons can
			// be fired and tallied to know if you fired too many shots for how many cannons you actually CAN fire.
			// That gets purged in "Ship_CheckSituation", which apparently occurs too quickly for the 'deleteme' number
			// to be lowered slow enough before all cannons have fired.
			// When you lost ALL cannons, 'firedqty' being '1' will always be larger than 'curqty' (being zero),
			// so it did not fire off ammo (what it should have done).
			// This fix changes the value of "deleteme" and the purge criteria in "Ship_CheckSituation". It instead
			// checks to see if you have 'fired' off the amount of cannons an arc could possibly fire. Since the game
			// engine will always activate the "Cannon_FireCannon" function for each cannon in the arc of the ship type.
			// That way, the "firedqty" accurately increases, and then the following IF block will activate when you
			// have reached your 'curqty' of cannons that you CAN actually fire. It will then return the ammo for the
			// cannons you can't fire, and end the run with the 'deleteme' reaching the same as 'numfired'.
			// A little confusing, but NK had all the code already here, it just wasn't working correctly.
			arcan.deleteme = GetCannonArcMaxQty(aCharacter,quad); // TIH override this value with max cannons to be activated Nov12'06

			//if ( sti(aCharacter.Index) == GetMainCharacterIndex() ) { Logit("Cannon Fired " + firedqty + " of " + sti(arcan.curqty) + " ("+ GetCannonArcMaxQty(aCharacter,quad) + ")" ); }
			if(firedqty > sti(arcan.curqty))
			{
				AddCharacterGoodsSimple(aCharacter, sti(aCharacter.Ship.Cannons.Charge.Type), 1); // give back the ammo
				// TIH --> give back the gunpowder used if mod is on Nov12'06
				if (CANNONPOWDER_MOD) AddCharacterGoodsSimple(aCharacter, GOOD_GUNPOWDER, sti(Cannon[GetCaracterShipCannonsType(aCharacter)].gunpowder));
				// TIH <--
				//if ( sti(aCharacter.Index) == GetMainCharacterIndex() ) { Logit("Ammo Returned "); }
				return;
			}
			//arcan.numfired = firedqty;
		}
		// NK <--
		EntityUpdate(0);
		AIBalls.x = fX;
		AIBalls.y = fY;
		AIBalls.z = fZ;
		AIBalls.CharacterIndex = aCharacter.Index;
//KB- Tuning, to allow gchasers
		AIBalls.quad = quadstr; //KB
//KB end
		float fTempDispersionV;
		ref gBall = &Goods[sti(aCharacter.Ship.Cannons.Charge.Type)];
		AIBalls.Type = gBall.name; // add extra info here!
		fTempDispersionX = Degree2Radian(stf(gBall.dispersion.X));
		fTempDispersionY = Degree2Radian(stf(gBall.dispersion.Y));
		fTempDispersionV = Degree2Radian(stf(gBall.dispersion.V));
		// KNB 04-01-16 ammo-based dispersion
		// NK read from goods table
		/*switch (AIBalls.Type)
		{
			case "Grapes":
				fTempDispersionX = Degree2Radian(5.0);
				fTempDispersionY = Degree2Radian(12.0);
				fTempDispersionV = 0.12;
			break;
			case "Knippels":
				fTempDispersionX = Degree2Radian(3.0);
				fTempDispersionY = Degree2Radian(8.0);
				fTempDispersionV = 0.08;
			break;
			case "Bombs":
				fTempDispersionX = Degree2Radian(2.0);
				fTempDispersionY = Degree2Radian(6.0);
				fTempDispersionV = 0.03;
			break;
			// for type "balls"
			fTempDispersionX = Degree2Radian(2.0);
			fTempDispersionY = Degree2Radian(6.0);
			fTempDispersionV = 0.03; // in percent
		}*/

		// KNB To make carronades less accurate
		ref rCannon = GetCannonByType(sti(aCharacter.Ship.Cannons.Type));

		if (CheckAttribute(rCannon, "HeightMultiply") ) {
			AIBalls.HeightMultiply = rCannon.HeightMultiply;
		}
		else {
			AIBalls.HeightMultiply = 1.0;
		}
		if (CheckAttribute(rCannon, "SizeMultiply") ) {
			AIBalls.SizeMultiply = rCannon.SizeMultiply;
		}
		else {
			AIBalls.SizeMultiply = 1.0;
		}
		if (CheckAttribute(rCannon, "TimeSpeedMultiply") ) {
			AIBalls.TimeSpeedMultiply = rCannon.TimeSpeedMultiply;
		}
		else {
			AIBalls.TimeSpeedMultiply = 1.0;
		}
		AIBalls.MaxFireDistance = fMaxFireDistance;

		// NK read from cannon table
		fTempDispersionX *= stf(rCannon.dispersion.X);
		fTempDispersionY *= stf(rCannon.dispersion.Y);
		fTempDispersionV *= stf(rCannon.dispersion.V);
		/*if (rCannon.type == CANNON_NAME_CARRONADE)
		{
			fTempDispersionY *= 1.2;
			fTempDispersionX *= 1.2;
			fTempDispersionV *= 1.2;
		}*/


//KB - Tuning ships - Bcannons
		fAccuracy = 1.0 - (0.5 * stf(aCharacter.TmpSkill.Accuracy));
//	fAccuracy = 1.0 - (0.5 * stf(aCharacter.TmpSkill.Accuracy)/10);

//KB if ( sti(aCharacter.index) == 0 ) { Trace("KB - Disp before " + fTempDispersionY); }
		aref temparef;
		//int testtune=0;
		makearef(temparef,aCharacter.ship);
		if (CheckAttribute(temparef,"tune")) {
			//testtune = 1;
			makearef(temparef,aCharacter.ship.tune);
			if(CheckAttribute(temparef,"bcannons")) { 
				if ( sti(aCharacter.ship.tune.bcannons.on) == 1 ) {
					fTempDispersionY = fTempDispersionY - fTempDispersionY * BCACC /100;
					fTempDispersionV = fTempDispersionV - fTempDispersionV * BCACC /100;
					fTempDispersionX = fTempDispersionX - fTempDispersionX * BCACC /100;
				}
			}
		}
//KB if ( sti(aCharacter.index) == 0 ) {Trace("KB - Disp after " + fTempDispersionY);}
//KB - Tuning ships - gchasers accuracy and range
//KB if ( sti(aCharacter.index) == 0 ) { Trace("KB - GChaseres Disp before " + fTempDispersionY); }
		float kbaddtospeedball = 1.0;
		if (AIBalls.quad == "cannonf") {  //KB It's a chaser	
			/*if (testtune == 1) {
				makearef(temparef,aCharacter.ship.tune);
				if(CheckAttribute(temparef,"gchasers")) { 
					if ( sti(aCharacter.ship.tune.gchasers.on) == 1 ) {
						fTempDispersionY = fTempDispersionY - fTempDispersionY * GCACCADD /100;
						fTempDispersionV = fTempDispersionV - fTempDispersionV * GCACCADD /100;
						fTempDispersionX = fTempDispersionX - fTempDispersionX * GCACCADD /100;
						kbaddtospeedball = kbaddtospeedball * makefloat(GCRANGEADD);				
					}
				}
			}*/
			BowChaserGreekFire = GetAttribute(aCharacter, "ship.type") == "QueenAnnesRevenge"; // PB: Queen Anne's Revenge's Bow Chasers
		}
//KB if ( sti(aCharacter.index) == 0 ) {Trace("KB - Disp after " + fTempDispersionY);}

		AIBalls.Dir = fDirAng + fAccuracy * fTempDispersionY * (frnd() - 0.5);
//KB Tuning - gchasers
		AIBalls.SpdV0 = fSpeedV0 * kbaddtospeedball + fAccuracy * (fTempDispersionV * fSpeedV0) * (frnd() - 0.5); 
		AIBalls.Ang = fHeightAng + fAccuracy * fTempDispersionX * (frnd() - 0.5);
//KB - END Tuning ships

		AIBalls.Event = "";
		/*if (sti(rCharacter.index) == GetMainCharacterIndex())
		{
		if (ballNumber == 1) { AIBalls.Event = BALL_FLY_UPDATE; }
		ballNumber++;
		}*/

		EntityUpdate(1);
		AIBalls.Add = "";

		// PB: Queen Anne's Revenge's Bow Chasers -->
		if(BowChaserGreekFire)
		{
			CreateParticleSystem("qar_fire", fX, fY, fZ, -fHeightAng, fDirAng, 0.0, 1);
			AIBalls.GreekFire = true;
			PlayStereoSound("objects\shipcharge\greek_fire.wav");
		}
		// PB: Queen Anne's Revenge's Bow Chasers <--
		else
		{
			//CreateParticleSystem("cancloud", fX, fY, fZ, -fHeightAng, fDirAng, 0.0, 12); // cannon smoke 100% redone by Merciless Mark
			// NK change the names to KNBcancloud*
			CreateParticleSystem("canfire2", fX, fY, fZ, -fHeightAng, fDirAng, 0.0, 1); // per Mehrunes's original idea, redone completely by Merciless Mark
			AIBalls.GreekFire = false;

			// Erwin Lindemann -->
			switch (USE_PARTICLES_CANNONS)	// Switch smoke quantity according to advanced options for particles
			{
				case 0: // None (Stock POTC, less smoke)
					PostEvent("CreateParticleSystemPost", 200, "sffffffl", "cancloud_stock", fX, fY, fZ, -fHeightAng, fDirAng, 0.0, 20); 
				break;
				case 1: // Full
					PostEvent("CreateParticleSystemPost", 50, "sffffffl", "MMcancloud_Light", fX, fY, fZ, -fHeightAng, fDirAng, 0.0, 20); 
					PostEvent("CreateParticleSystemPost", 60, "sffffffl", "MMcancloud2_Light", fX, fY, fZ, -fHeightAng, fDirAng, 0.0, 20); 
				break;
				case 2: // Enhanced! High-End Machine Recommended!
					PostEvent("CreateParticleSystemPost", 50, "sffffffl", "MMcancloud", fX, fY, fZ, -fHeightAng, fDirAng, 0.0, 20); // Post delay reduced to synchronize the fire and smoke better
					PostEvent("CreateParticleSystemPost", 60, "sffffffl", "MMcancloud2", fX, fY, fZ, -fHeightAng, fDirAng, 0.0, 20); // Dirty smoke
					CreateParticleSystem("cannon_embers", fX, fY, fZ, -fHeightAng, fDirAng, 0.0, 20); // Gunpowder embers
				break;
			}
			// Erwin Lindemann <--

			if(JRH_GUNSOUNDS && CheckAttribute(rCannon,"sound")) // NK 05-05-03 add toggle and check.
			{
				Play3DSound(rCannon.sound, fX, fY, fZ);
	 			if (isMainCharacter(aCharacter)) {
					Play3DSound("gunner_cough", fX, fY, fZ);
	 			}
			} else {
				Play3DSound("cannon_fire", fX, fY, fZ);
			}
		}
	} else {
		EntityUpdate(0);
		AIBalls.x = fX;
		AIBalls.y = fY;
		AIBalls.z = fZ;
		AIBalls.CharacterIndex = aCharacter.Index;
		fTempDispersionY = Degree2Radian(10.0);
		fTempDispersionX = Degree2Radian(5.0);

		fAccuracy = 1.2 - stf(aCharacter.TmpSkill.Accuracy);
		float fK = Bring2Range(0.5, 1.2, 0.2, 1.2, fAccuracy);
		AIBalls.Type = Goods[sti(aCharacter.Ship.Cannons.Charge.Type)].Name;
		AIBalls.Dir = fDirAng + fK * fTempDispersionY * (frnd() - 0.5);
		AIBalls.SpdV0 = fSpeedV0 + fAccuracy * (10.0 * fTempDispersionY) * (frnd() - 0.5);
		AIBalls.Ang = fHeightAng + fAccuracy * (fTempDispersionX) * (frnd() - 0.5);

		AIBalls.Event = "";
		/*if (sti(rCharacter.index) == GetMainCharacterIndex())
		{
			if (ballNumber == 1) { AIBalls.Event = BALL_FLY_UPDATE; }
			ballNumber++;
		}*/

		EntityUpdate(1);
		AIBalls.Add = "";

		CreateParticleSystem("canfire", fX, fY, fZ, -fHeightAng, fDirAng, 0.0, 1); // NK 04-09-21 per Mehrunes's idea
		//CreateParticleSystem("cancloud", fX, fY, fZ, -fHeightAng, fDirAng, 0.0, 12); // NK 04-09-21 make smoke last longer
		PostEvent("CreateParticleSystemPost", 300, "sffffffl", "cancloud_stock", fX, fY, fZ, -fHeightAng, fDirAng, 0.0, 20); // now done as post to not hide fire fx
		Play3DSound("cannon_fire", fX, fY, fZ);
	}
}

void Ball_WaterHitEvent()
{
	int		iCharacterIndex;
	float	x, y, z;

	iCharacterIndex = GetEventData();
	x = GetEventData();
	y = GetEventData();
	z = GetEventData();
	//if(iCharacterIndex != -1) trace("for char " + Characters[iCharacterIndex].id + " and ship " + Characters[iCharacterIndex].ship.name + " waterhit at " + x +","+y+","+z);

	SendMessage(&BallSplash, "lfff", MSG_BALLSPLASH_ADD, x, y, z);
	Play3DSound("ball_splash", x, y, z);
}
//new Fort hit effect by MM
void Ball_FortHit()
{
	int		iCharacterIndex;
	float	x, y, z;

	iCharacterIndex = GetEventData();

	x = GetEventData();
	y = GetEventData();
	z = GetEventData();

	CreateParticleSystem("blast_newsmoke", x, y, z, 0.0, 0.0, 0.0, 0);
	SendMessage(&AIFort, "llfff", AI_MESSAGE_FORT_HIT, iCharacterIndex, x, y, z);
}
//new hit effect for island by MM
void Ball_IslandHit()
{
	int		iCharacterIndex;
	float	x, y, z;

	iCharacterIndex = GetEventData();

	x = GetEventData();
	y = GetEventData();
	z = GetEventData();

	// CreateBlast(x,y,z);
	// CreateParticleSystem("blast_newsmoke",x,y,z,0.0,0.0,0.0,0);
	CreateParticleSystem("blast_newsmoke", x, y, z, 0.0, 0.0, 0.0, 0);
	CreateParticleSystem("blast_dirt", x, y, z, 0.0, 0.0, 0.0, 0);
	//SendMessage(&AIFort,"llfff",AI_MESSAGE_FORT_HIT,iCharacterIndex,x,y,z);
}

void Ball_OnFlyUpdate()
{
	int charIndex = GetEventData();
	int ballAlive = GetEventData();
	float x = GetEventData();
	float y = GetEventData();
	float z = GetEventData();
	float lx = GetEventData();
	float ly = GetEventData();
	float lz = GetEventData();
	SendMessage(&SeaOperator, "lalffffff", MSG_SEA_OPERATOR_BALL_UPDATE, &Characters[charIndex], ballAlive, x, y, z, lx, ly, lz);
}
