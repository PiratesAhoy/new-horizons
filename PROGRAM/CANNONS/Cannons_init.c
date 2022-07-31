void InitBaseCannons_CalcSpeedV0(ref rCannon, float fFireRange)
{
	rCannon.FireRange = fFireRange;
	rCannon.SpeedV0 = sqrt(fFireRange * 9.81 / sin( 2.0 * MakeFloat(rCannon.FireAngMax)) );
	//rCannon.ReloadTime = sti(rCannon.ReloadTime) / 6;
	//Trace("Fire range = " + rCannon.FireRange + ", SpeedV0 = " + rCannon.SpeedV0);
}

void InitCannons()
{
	// NK -->
	ref rCannon;
	int n;
	for(n = 0; n < CANNON_TYPES_MAX; n++)
	{
		makeref(rCannon, Cannon[n]);
		DeleteAttribute(rCannon,"");
		rCannon.Dispersion.X = 1.0;
		rCannon.Dispersion.Y = 1.0;
		rCannon.Dispersion.V = 1.0;

		rCannon.HeightMultiply = 1.0;
		rCannon.SizeMultiply = 1.0;
		rCannon.TimeSpeedMultiply = 1.0;
	}
	n = 0;
	// NK switch fireangMin/Max to scalars, not the actual arcsize. For use so ships can have varying arcs (esp. forts!)
	if(USE_REAL_CANNONS)
	{
		// KNB realistic cannons
		makeref(rCannon,Cannon[CANNON_TYPE_LONG_LBS4]);
		rCannon.type = CANNON_NAME_LONG;
		rCannon.caliber = 4;
		rCannon.ReloadTime = 40;
		rCannon.Cost = 800;
		rCannon.Weight = 13;
 		rCannon.sound = ("cannon_fire_LG4");//JRH
 		rCannon.gunpowder = 2;// added by MAXIMUS [gunpowder mod]
		rCannon.FireAngMax = 1.0;
		rCannon.FireAngMin = 1.0;
		rCannon.DamageMultiply = 0.35;
		InitBaseCannons_CalcSpeedV0(&rCannon,1350.0*CANNON_RANGE_SCALAR);
		n++;

		makeref(rCannon,Cannon[CANNON_TYPE_LONG_LBS6]);
		rCannon.type = CANNON_NAME_LONG;
		rCannon.caliber = 6;
		rCannon.ReloadTime = 50;
		rCannon.Cost = 1000;
		rCannon.Weight = 26;
		rCannon.sound = ("cannon_fire_LG6");//JRH
 		rCannon.gunpowder = 3;// added by MAXIMUS [gunpowder mod]
		rCannon.FireAngMax = 1.0;
		rCannon.FireAngMin = 1.0;
		rCannon.DamageMultiply = 0.60;
		InitBaseCannons_CalcSpeedV0(&rCannon,1450.0*CANNON_RANGE_SCALAR);
		n++;

		makeref(rCannon,Cannon[CANNON_TYPE_LONG_LBS9]);
		rCannon.type = CANNON_NAME_LONG;
		rCannon.caliber = 9;
		rCannon.ReloadTime = 60;
		rCannon.Cost = 1300;
		rCannon.Weight = 33;
 		rCannon.sound = ("cannon_fire_LG9");//JRH
 		rCannon.gunpowder = 4;// added by MAXIMUS [gunpowder mod]
		rCannon.FireAngMax = 1.0;
		rCannon.FireAngMin = 1.0;
		rCannon.DamageMultiply = 1.0; // calculated as m*v^2, normalized
		InitBaseCannons_CalcSpeedV0(&rCannon,1620.0*CANNON_RANGE_SCALAR);
		n++;

		makeref(rCannon,Cannon[CANNON_TYPE_LONG_LBS12]);
		rCannon.type = CANNON_NAME_LONG;
		rCannon.caliber = 12;
		rCannon.ReloadTime = 70;
		rCannon.Cost = 1650;
		rCannon.Weight = 38;
		rCannon.sound = ("cannon_fire_LG12");//JRH
 		rCannon.gunpowder = 5;// added by MAXIMUS [gunpowder mod]
		rCannon.FireAngMax = 1.0;
		rCannon.FireAngMin = 1.0;
		rCannon.DamageMultiply = 1.4;
		InitBaseCannons_CalcSpeedV0(&rCannon,1680.0*CANNON_RANGE_SCALAR);
		n++;

		makeref(rCannon,Cannon[CANNON_TYPE_LONG_LBS18]);
		rCannon.type = CANNON_NAME_LONG;
		rCannon.caliber = 18;
		rCannon.ReloadTime = 85;
		rCannon.Cost = 2200;
		rCannon.Weight = 47;
		rCannon.sound = ("cannon_fire_LG18");//JRH
 		rCannon.gunpowder = 6;// added by MAXIMUS [gunpowder mod]
		rCannon.FireAngMax = 1.0;
		rCannon.FireAngMin = 1.0;
		rCannon.DamageMultiply = 2.2;
		InitBaseCannons_CalcSpeedV0(&rCannon,1800.0*CANNON_RANGE_SCALAR);
		n++;

		// Used to represent mix of 18 and 24 pound guns.
		makeref(rCannon,Cannon[CANNON_TYPE_LONG_LBS24]);
		rCannon.type = CANNON_NAME_LONG;
		rCannon.caliber = 24;
		rCannon.ReloadTime = 100;
		rCannon.Cost = 3000;
		rCannon.Weight = 58; //50
		rCannon.sound = ("cannon_fire_LG24");//JRH
 		rCannon.gunpowder = 7;// added by MAXIMUS [gunpowder mod]
		rCannon.FireAngMax = 1.0;
		rCannon.FireAngMin = 1.0;
		rCannon.DamageMultiply = 3.0;
		InitBaseCannons_CalcSpeedV0(&rCannon,1800.0*CANNON_RANGE_SCALAR);
		n++;

		// Used to represent mix of 24 and 32 pound guns.
		makeref(rCannon,Cannon[CANNON_TYPE_LONG_LBS32]);
		rCannon.type = CANNON_NAME_LONG;
		rCannon.caliber = 32;
		rCannon.ReloadTime = 120;
		rCannon.Cost = 4000;
		rCannon.Weight = 70; //56
		rCannon.sound = ("cannon_fire_LG32");//JRH
 		rCannon.gunpowder = 8;// added by MAXIMUS [gunpowder mod]
		rCannon.FireAngMax = 1.0;
		rCannon.FireAngMin = 1.0;
		rCannon.DamageMultiply = 4.0;
		InitBaseCannons_CalcSpeedV0(&rCannon,2080.0*CANNON_RANGE_SCALAR);
		n++;

		// Big, scary fort guns
		makeref(rCannon,Cannon[CANNON_TYPE_LONG_LBS42]);
		rCannon.type = CANNON_NAME_LONG;
		rCannon.caliber = 42;
		rCannon.ReloadTime = 150;		// LDH was 240
		rCannon.Cost = 5000;
		rCannon.Weight = 75;
		rCannon.sound = ("cannon_fire_LG42");//JRH
 		rCannon.gunpowder = 9;// added by MAXIMUS [gunpowder mod]
		rCannon.FireAngMax = 1.0;
		rCannon.FireAngMin = 1.0;
		rCannon.DamageMultiply = 5.5;
		rCannon.TradeOff = true;
		InitBaseCannons_CalcSpeedV0(&rCannon,1940.0*FORT_RANGE_SCALAR); // PB: Different value for forts
		n++;

		makeref(rCannon,Cannon[CANNON_TYPE_CARRONADE_LBS12]);
		rCannon.type = CANNON_NAME_CARRONADE;
		rCannon.caliber = 12;
		rCannon.ReloadTime = 50;
		rCannon.Cost = 1200;
		rCannon.Weight = 6;
		rCannon.sound = ("cannon_fire_CR12");//JRH
 		rCannon.gunpowder = 6;// added by MAXIMUS [gunpowder mod]
		rCannon.FireAngMax = 1.0;
		rCannon.FireAngMin = 1.0;
		rCannon.DamageMultiply = 0.8;
		InitBaseCannons_CalcSpeedV0(&rCannon,950.0*CANNON_RANGE_SCALAR);
		rCannon.Dispersion.X = CARRONADE_DISPERSION_MULT;
		rCannon.Dispersion.Y = CARRONADE_DISPERSION_MULT;
		rCannon.Dispersion.V = CARRONADE_DISPERSION_MULT;
		n++;

		makeref(rCannon,Cannon[CANNON_TYPE_CARRONADE_LBS18]);
		rCannon.type = CANNON_NAME_CARRONADE;
		rCannon.caliber = 18;
		rCannon.ReloadTime = 60;
		rCannon.Cost = 1500;
		rCannon.Weight = 10;
		rCannon.sound = ("cannon_fire_CR18");//JRH
 		rCannon.gunpowder = 7;// added by MAXIMUS [gunpowder mod]
		rCannon.FireAngMax = 1.0;
		rCannon.FireAngMin = 1.0;
		rCannon.DamageMultiply = 1.2;
		InitBaseCannons_CalcSpeedV0(&rCannon,1000.0*CANNON_RANGE_SCALAR);
		rCannon.Dispersion.X = CARRONADE_DISPERSION_MULT;
		rCannon.Dispersion.Y = CARRONADE_DISPERSION_MULT;
		rCannon.Dispersion.V = CARRONADE_DISPERSION_MULT;
		n++;

		makeref(rCannon,Cannon[CANNON_TYPE_CARRONADE_LBS24]);
		rCannon.type = CANNON_NAME_CARRONADE;
		rCannon.caliber = 24;
		rCannon.ReloadTime = 70;
		rCannon.Weight = 14;
		rCannon.Cost = 2000;
		rCannon.sound = ("cannon_fire_CR24");//JRH
 		rCannon.gunpowder = 8;// added by MAXIMUS [gunpowder mod]
		rCannon.FireAngMax = 1.0;
		rCannon.FireAngMin = 1.0;
		rCannon.DamageMultiply = 1.7;
		InitBaseCannons_CalcSpeedV0(&rCannon,1050.0*CANNON_RANGE_SCALAR);
		rCannon.Dispersion.X = CARRONADE_DISPERSION_MULT;
		rCannon.Dispersion.Y = CARRONADE_DISPERSION_MULT;
		rCannon.Dispersion.V = CARRONADE_DISPERSION_MULT;
		n++;

		// Not very useful, but here nontheless
		makeref(rCannon,Cannon[CANNON_TYPE_CARRONADE_LBS32]);
		rCannon.type = CANNON_NAME_CARRONADE;
		rCannon.caliber = 32;
		rCannon.ReloadTime = 85;
		rCannon.Weight = 20;
		rCannon.Cost = 3000;
		rCannon.sound = ("cannon_fire_CR32");//JRH
 		rCannon.gunpowder = 9;// added by MAXIMUS [gunpowder mod]
		rCannon.FireAngMax = 1.0;
		rCannon.FireAngMin = 1.0;
		rCannon.DamageMultiply = 2.4;
		InitBaseCannons_CalcSpeedV0(&rCannon,1080.0*CANNON_RANGE_SCALAR);
		rCannon.Dispersion.X = CARRONADE_DISPERSION_MULT;
		rCannon.Dispersion.Y = CARRONADE_DISPERSION_MULT;
		rCannon.Dispersion.V = CARRONADE_DISPERSION_MULT;
		n++;

		// More big, scary fort guns
		makeref(rCannon,Cannon[CANNON_TYPE_CARRONADE_LBS42]);
		rCannon.type = CANNON_NAME_CARRONADE;
		rCannon.caliber = 42;
		rCannon.ReloadTime = 100;		// LDH was 180
		rCannon.Weight = 24;
		rCannon.Cost = 4000;
		rCannon.sound = ("cannon_fire_CR42");//JRH
 		rCannon.gunpowder = 10;// added by MAXIMUS [gunpowder mod]
		rCannon.FireAngMax = 1.0;
		rCannon.FireAngMin = 1.0;
		rCannon.DamageMultiply = 3.5;
		rCannon.TradeOff = true;
		InitBaseCannons_CalcSpeedV0(&rCannon,1170.0*FORT_RANGE_SCALAR); // PB: Different value for forts
		rCannon.Dispersion.X = CARRONADE_DISPERSION_MULT;
		rCannon.Dispersion.Y = CARRONADE_DISPERSION_MULT;
		rCannon.Dispersion.V = CARRONADE_DISPERSION_MULT;
		n++;

		// Even bigger, even scarier fort guns
		makeref(rCannon,Cannon[CANNON_TYPE_CARRONADE_LBS68]);
		rCannon.type = CANNON_NAME_CARRONADE;
		rCannon.caliber = 68;
		rCannon.ReloadTime = 125;		// LDH was 240
		rCannon.Weight = 40;
		rCannon.Cost = 5000;
		rCannon.sound = ("cannon_fire_CR68");//JRH
 		rCannon.gunpowder = 6;// added by MAXIMUS [gunpowder mod]
		rCannon.FireAngMax = 1.0;
		rCannon.FireAngMin = 1.0;
		rCannon.DamageMultiply = 6.0;
		rCannon.TradeOff = true;
		InitBaseCannons_CalcSpeedV0(&rCannon,1280.0*FORT_RANGE_SCALAR); // PB: Different value for forts
		rCannon.Dispersion.X = CARRONADE_DISPERSION_MULT;
		rCannon.Dispersion.Y = CARRONADE_DISPERSION_MULT;
		rCannon.Dispersion.V = CARRONADE_DISPERSION_MULT;
		n++;

		makeref(rCannon,Cannon[CANNON_TYPE_CARRONADE_LBS68I]);
		rCannon.type = CANNON_NAME_CARRONADE;
		rCannon.caliber = 68;
		rCannon.ReloadTime = 100;		// LDH was 240
		rCannon.Weight = 40;
		rCannon.Cost = 5000;
		rCannon.sound = ("cannon_fire_CR68");//JRH
		rCannon.gunpowder = 5;// added by MAXIMUS [gunpowder mod]
		rCannon.FireAngMax = 1.0;
		rCannon.FireAngMin = 1.0;
		rCannon.DamageMultiply = 5.1;
		rCannon.TradeOff = true;
		InitBaseCannons_CalcSpeedV0(&rCannon,1080.0*CANNON_RANGE_SCALAR);
		rCannon.Dispersion.X = CARRONADE_DISPERSION_MULT;
		rCannon.Dispersion.Y = CARRONADE_DISPERSION_MULT;
		rCannon.Dispersion.V = CARRONADE_DISPERSION_MULT;
		n++;
		
		makeref(rCannon,Cannon[CANNON_TYPE_CARRONADE_LBS42I]);
		rCannon.type = CANNON_NAME_CARRONADE;
		rCannon.caliber = 42;
		rCannon.ReloadTime = 85;		// LDH was 180
		rCannon.Weight = 24;
		rCannon.Cost = 4000;
		rCannon.sound = ("cannon_fire_CR42");//JRH
		rCannon.gunpowder = 4;// added by MAXIMUS [gunpowder mod]
		rCannon.FireAngMax = 1.0;
		rCannon.FireAngMin = 1.0;
		rCannon.DamageMultiply = 3.0;
		rCannon.TradeOff = true;
		InitBaseCannons_CalcSpeedV0(&rCannon,970.0*CANNON_RANGE_SCALAR);
		rCannon.Dispersion.X = CARRONADE_DISPERSION_MULT;
		rCannon.Dispersion.Y = CARRONADE_DISPERSION_MULT;
		rCannon.Dispersion.V = CARRONADE_DISPERSION_MULT;
		n++;
		
		makeref(rCannon,Cannon[CANNON_TYPE_CARRONADE_LBS68SPEC]);
		rCannon.type = CANNON_NAME_CARRONADE;
		rCannon.caliber = 68;
		rCannon.ReloadTime = 90;		// LDH was 240
		rCannon.Weight = 40;
		rCannon.Cost = 5000;
		rCannon.sound = ("cannon_fire_CR68");//JRH
		rCannon.gunpowder = 5;// added by MAXIMUS [gunpowder mod]
		rCannon.FireAngMax = 1.0;
		rCannon.FireAngMin = 1.0;
		rCannon.DamageMultiply = 7.8;
		rCannon.TradeOff = true;
		InitBaseCannons_CalcSpeedV0(&rCannon,1480.0*CANNON_RANGE_SCALAR);
		rCannon.Dispersion.X = CARRONADE_DISPERSION_MULT;
		rCannon.Dispersion.Y = CARRONADE_DISPERSION_MULT;
		rCannon.Dispersion.V = CARRONADE_DISPERSION_MULT;
		n++;
		
		makeref(rCannon,Cannon[CANNON_TYPE_CARRONADE_DUTCHMAN]);
		rCannon.type = CANNON_NAME_CARRONADE;
		rCannon.caliber = 128;
		rCannon.ReloadTime = 100;		// LDH was 240
		rCannon.Weight = 72;
		rCannon.Cost = 10000;
		rCannon.sound = ("cannon_fire_DUTCHMAN");//JRH
		rCannon.gunpowder = 5;// added by MAXIMUS [gunpowder mod]
		rCannon.FireAngMax = 1.0;
		rCannon.FireAngMin = 1.0;
		rCannon.DamageMultiply = 9.1;
		rCannon.TradeOff = true;
		InitBaseCannons_CalcSpeedV0(&rCannon,1680.0*CANNON_RANGE_SCALAR);
		rCannon.Dispersion.X = CARRONADE_DISPERSION_MULT;
		rCannon.Dispersion.Y = CARRONADE_DISPERSION_MULT;
		rCannon.Dispersion.V = CARRONADE_DISPERSION_MULT;
		n++;

		CANNON_CALIBERS_MAX = 10;
		Cannon_Calibers[0] = 4;
		Cannon_Calibers[1] = 6;
		Cannon_Calibers[2] = 9;
		Cannon_Calibers[3] = 12;
		Cannon_Calibers[4] = 18;
		Cannon_Calibers[5] = 24;
		Cannon_Calibers[6] = 32;
		Cannon_Calibers[7] = 42;
		Cannon_Calibers[8] = 68;
		Cannon_Calibers[9] = 128;
	}
	// KNB <--
	else
	{
		makeref(rCannon,Cannon[CANNON_TYPE_CULVERINE_LBS12]);
		rCannon.type = CANNON_NAME_CULVERINE;
		rCannon.caliber = 12;
		rCannon.ReloadTime = 28; //20;
		rCannon.Cost = 1200;
		rCannon.Weight = 27;
		rCannon.sound = ("cannon_fire_LG12");//JRH
 		rCannon.gunpowder = 3;// added by MAXIMUS [gunpowder mod]
		rCannon.FireAngMax = 0.60 * FIRE_ANGLE_SCALAR_H*0.5; // NK 04-09-09
		rCannon.FireAngMin = -0.35 * FIRE_ANGLE_SCALAR_H*0.5; // NK 04-09-09
		rCannon.DamageMultiply = 0.6;
		InitBaseCannons_CalcSpeedV0(&rCannon,800.0*CANNON_RANGE_SCALAR*0.5);
		n++;

		makeref(rCannon,Cannon[CANNON_TYPE_CULVERINE_LBS16]);
		rCannon.type = CANNON_NAME_CULVERINE;
		rCannon.caliber = 16;
		rCannon.ReloadTime = 42; //24;
		rCannon.Cost = 1600;
		rCannon.Weight = 42;
		rCannon.sound = ("cannon_fire_LG18");//JRH
 		rCannon.gunpowder = 5;// added by MAXIMUS [gunpowder mod]
		rCannon.FireAngMax = 0.60 * FIRE_ANGLE_SCALAR_H*0.5; // NK 04-09-09
		rCannon.FireAngMin = -0.35 * FIRE_ANGLE_SCALAR_H*0.5; // NK 04-09-09
		rCannon.DamageMultiply = 1.0;
		InitBaseCannons_CalcSpeedV0(&rCannon,970.0*CANNON_RANGE_SCALAR*0.5);
		n++;

		makeref(rCannon,Cannon[CANNON_TYPE_CULVERINE_LBS24]);
		rCannon.type = CANNON_NAME_CULVERINE;
		rCannon.caliber = 24;
		rCannon.ReloadTime = 56; //30;
		rCannon.Cost = 2000;
		rCannon.Weight = 48;
		rCannon.sound = ("cannon_fire_LG24");//JRH
 		rCannon.gunpowder = 8;// added by MAXIMUS [gunpowder mod]
		rCannon.FireAngMax = 0.60 * FIRE_ANGLE_SCALAR_H*0.5; // NK 04-09-09
		rCannon.FireAngMin = -0.35 * FIRE_ANGLE_SCALAR_H*0.5; // NK 04-09-09
		rCannon.DamageMultiply = 1.5;
		InitBaseCannons_CalcSpeedV0(&rCannon,1150.0*CANNON_RANGE_SCALAR*0.5);
		n++;

		makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS12]);
		rCannon.type = CANNON_NAME_CANNON;
		rCannon.caliber = 12;
		rCannon.ReloadTime = 24; //12;
		rCannon.Cost = 1000;
		rCannon.Weight = 38;
		rCannon.sound = ("cannon_fire_CR12");//JRH
 		rCannon.gunpowder = 2;// added by MAXIMUS [gunpowder mod]
		rCannon.FireAngMax = 0.60 * FIRE_ANGLE_SCALAR_H*0.5; // NK 04-09-09
		rCannon.FireAngMin = -0.35 * FIRE_ANGLE_SCALAR_H*0.5; // NK 04-09-09
		rCannon.DamageMultiply = 0.6;
		InitBaseCannons_CalcSpeedV0(&rCannon,640.0*CANNON_RANGE_SCALAR*0.5);
		n++;

		makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS16]);
		rCannon.type = CANNON_NAME_CANNON;
		rCannon.caliber = 16;
		rCannon.ReloadTime = 36; //20;
		rCannon.Cost = 1300;
		rCannon.Weight = 42;
		rCannon.sound = ("cannon_fire_CR18");//JRH
 		rCannon.gunpowder = 3;// added by MAXIMUS [gunpowder mod]
		rCannon.FireAngMax = 0.60 * FIRE_ANGLE_SCALAR_H*0.5; // NK 04-09-09
		rCannon.FireAngMin = -0.35 * FIRE_ANGLE_SCALAR_H*0.5; // NK 04-09-09
		rCannon.DamageMultiply = 1.0;
		InitBaseCannons_CalcSpeedV0(&rCannon,775.0*CANNON_RANGE_SCALAR*0.5);
		n++;

		makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS24]);
		rCannon.type = CANNON_NAME_CANNON;
		rCannon.caliber = 24;
		rCannon.ReloadTime = 48; //24;
		rCannon.Weight = 58;
		rCannon.Cost = 1650;
		rCannon.sound = ("cannon_fire_CR24");//JRH
 		rCannon.gunpowder = 5;// added by MAXIMUS [gunpowder mod]
		rCannon.FireAngMax = 0.60 * FIRE_ANGLE_SCALAR_H*0.5; // NK 04-09-09
		rCannon.FireAngMin = -0.35 * FIRE_ANGLE_SCALAR_H*0.5; // NK 04-09-09
		rCannon.DamageMultiply = 1.5;
		InitBaseCannons_CalcSpeedV0(&rCannon,920.0*CANNON_RANGE_SCALAR*0.5);
		n++;

		makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS32]);
		rCannon.type = CANNON_NAME_SPECIAL_CANNON;
		rCannon.caliber = 32;
		rCannon.ReloadTime = 60; //40;
		rCannon.Cost = 3500;
		rCannon.Weight = 70;
		rCannon.sound = ("cannon_fire_CR32");//JRH
 		rCannon.gunpowder = 9;// added by MAXIMUS [gunpowder mod]
		rCannon.FireAngMax = 0.60 * FIRE_ANGLE_SCALAR_H*0.5; // NK 04-09-09
		rCannon.FireAngMin = -0.35 * FIRE_ANGLE_SCALAR_H*0.5; // NK 04-09-09
		rCannon.DamageMultiply = 2.25;
		rCannon.TradeOff = false;
		InitBaseCannons_CalcSpeedV0(&rCannon,1100.0*CANNON_RANGE_SCALAR*0.5);
		n++;

		CANNON_CALIBERS_MAX = 4;
		Cannon_Calibers[0] = 12;
		Cannon_Calibers[1] = 16;
		Cannon_Calibers[2] = 24;
		Cannon_Calibers[3] = 32;
	}

	//end cannon inits
	CANNON_TYPES_QUANTITY = n;
	// NK <--
}
