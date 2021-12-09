#define SHIP_INTERFACE_SCREENSHOTS	1
#define PERIOD_ACCURACY_LEVEL		2	// PB: 1 = Simplified 0% or 100% Period+Nation chance, 0 = Period chance ignored

// NOTE: All ship prices are being doubled compared to the ones listed here
//       This happens in PROGRAM\KB_routines.c by function GetShipPriceByType

void InitShips()
{
	int idx, i, n, si, m, MinCapacity;
	float CrewPerGun;
	string sDet, cp, bp;
	ref refShip, rship2, rTypeList, rCannon;
	aref arship, cannonl, cannonr, cannonb, cannonf;
	bool bNoPennants = GetCurrentPeriod() < GetPeriodFromYear(makeint(PENNANTS_MIN_YEAR)); // KK

	// PRS3 -->
	//Default
	shipstatsmult.n.MaxCaliber	=	1.00;
	shipstatsmult.n.Weight		=	1.00;
	shipstatsmult.n.Capacity	=	1.00;
	shipstatsmult.n.MaxCrew		=	1.00;
	shipstatsmult.n.MinCrew		=	1.00;
	shipstatsmult.n.SpeedRate	=	1.00;
	shipstatsmult.n.TurnRate	=	1.00;
	shipstatsmult.n.Price		=	1.00;
	shipstatsmult.n.HP			=	1.00;

	//English
	shipstatsmult.n0.MaxCaliber	=	1.00;
	shipstatsmult.n0.Weight		=	0.95;
	shipstatsmult.n0.Capacity	=	1.20;
	shipstatsmult.n0.MaxCrew	=	0.95;
	shipstatsmult.n0.MinCrew	=	1.05;
	shipstatsmult.n0.SpeedRate	=	1.05;
	shipstatsmult.n0.TurnRate	=	1.00;
	shipstatsmult.n0.Price		=	1.10;
	shipstatsmult.n0.HP			=	1.15;

	//French
	shipstatsmult.n1.MaxCaliber	=	1.00;
	shipstatsmult.n1.Weight		=	1.00;
	shipstatsmult.n1.Capacity	=	1.05;
	shipstatsmult.n1.MaxCrew	=	1.15;
	shipstatsmult.n1.MinCrew	=	1.00;
	shipstatsmult.n1.SpeedRate	=	1.05;
	shipstatsmult.n1.TurnRate	=	1.00;
	shipstatsmult.n1.Price		=	1.05;
	shipstatsmult.n1.HP			=	1.05;

	//Spanish
	shipstatsmult.n2.MaxCaliber	=	1.00;
	shipstatsmult.n2.Weight		=	1.15;
	shipstatsmult.n2.Capacity	=	1.35;
	shipstatsmult.n2.MaxCrew	=	1.05;
	shipstatsmult.n2.MinCrew	=	1.00;
	shipstatsmult.n2.SpeedRate	=	0.95;
	shipstatsmult.n2.TurnRate	=	1.00;
	shipstatsmult.n2.Price		=	1.05;
	shipstatsmult.n2.HP			=	1.10;

	//Pirate
	shipstatsmult.n3.MaxCaliber	=	1.00;
	shipstatsmult.n3.Weight		=	0.90;
	shipstatsmult.n3.Capacity	=	1.00;
	shipstatsmult.n3.MaxCrew	=	1.05;
	shipstatsmult.n3.MinCrew	=	1.10;
	shipstatsmult.n3.SpeedRate	=	1.10;
	shipstatsmult.n3.TurnRate	=	1.10;
	shipstatsmult.n3.Price		=	0.95;
	shipstatsmult.n3.HP			=	0.80;

	//Dutch
	shipstatsmult.n4.MaxCaliber	=	1.00;
	shipstatsmult.n4.Weight		=	1.00;
	shipstatsmult.n4.Capacity	=	1.30;
	shipstatsmult.n4.MaxCrew	=	0.90;
	shipstatsmult.n4.MinCrew	=	1.00;
	shipstatsmult.n4.SpeedRate	=	1.05;
	shipstatsmult.n4.TurnRate	=	0.95;
	shipstatsmult.n4.Price		=	1.00;
	shipstatsmult.n4.HP			=	1.00;

	//Portuguese
	shipstatsmult.n5.MaxCaliber	=	1.00;
	shipstatsmult.n5.Weight		=	1.05;
	shipstatsmult.n5.Capacity	=	1.20;
	shipstatsmult.n5.MaxCrew	=	1.05;
	shipstatsmult.n5.MinCrew	=	1.00;
	shipstatsmult.n5.SpeedRate	=	1.00;
	shipstatsmult.n5.TurnRate	=	1.15;
	shipstatsmult.n5.Price		=	1.00;
	shipstatsmult.n5.HP			=	0.95;

	//United States
	shipstatsmult.n6.MaxCaliber	=	1.00;
	shipstatsmult.n6.Weight		=	1.00;
	shipstatsmult.n6.Capacity	=	1.10;
	shipstatsmult.n6.MaxCrew	=	1.00;
	shipstatsmult.n6.MinCrew	=	1.05;
	shipstatsmult.n6.SpeedRate	=	1.15;
	shipstatsmult.n6.TurnRate	=	1.00;
	shipstatsmult.n6.Price		=	1.05;
	shipstatsmult.n6.HP			=	1.10;
	// PRS3 <--

	DeleteAttribute(&ShipLookupTable,"id"); // NK 04-09-09 now using native NFC call; no longer needed. All references commented out below.
	SHIP_TYPES_QUANTITY = SHIP_TYPES_QUANTITY_WITH_FORT; // NK reset stq for reinit.
	for (idx=0;idx<SHIP_TYPES_QUANTITY;idx++)
	{
		makeref(refShip,ShipsTypes[idx]);
		makearef(arship, ShipsTypes[idx]); // PRS3
		for (i = 0; i < GetAttributesNum(arship); i++) {
			DeleteAttribute(arship, GetAttributeName(GetAttributeN(arship, i))); // NK delete old attribs
		}
		DeleteAttribute(arship,"");

		refShip.index = idx;
		refShip.id = "blank"; // PS
		refShip.chance = 10;

		refShip.InertiaAccelerationX = 0.2;		refShip.InertiaBrakingX = 0.7;
		refShip.InertiaAccelerationY = 0.4;		refShip.InertiaBrakingY = 0.4;
		refShip.InertiaAccelerationZ = 1.0;		refShip.InertiaBrakingZ = 1.0;

		refShip.WaterLine = 0.0;
		refShip.SpeedDependWeight = 0.0;
		refShip.SubSeaDependWeight = 0.0;
		refShip.TurnDependWeight = 0.5; //KNB was 0.0 but all were then each set 0.8
		if(USE_REAL_SAILING) refShip.TurnDependSpeed = 0.95; //NK, 0.8  KNB
		else refShip.TurnDependSpeed = 0.6; // was 0.4

		refShip.Height.Bombs.Y		= 3.0;		refShip.Height.Bombs.DY		= 1.0;
		//refShip.Height.Grapes.Y		= 4.0;		refShip.Height.Grapes.DY	= 1.0;
		refShip.Height.Knippels.Y	= 25.0;		refShip.Height.Knippels.DY	= 15.0;
		refShip.Height.Balls.Y		= 3.0;		refShip.Height.Balls.DY		= 1.0;
		if(USE_REAL_CANNONS)
		{
			refShip.Height.Grapes.Y   = 5.0;    refShip.Height.Grapes.DY  = 1.0;
			refShip.MaxCaliber   = 4;
			refShip.Cannon    = CANNON_TYPE_LONG_LBS4;
		}
		else
		{
			refShip.Height.Grapes.Y		= 4.0;		refShip.Height.Grapes.DY	= 1.0;
			refShip.MaxCaliber	= 12;
			refShip.Cannon		= CANNON_TYPE_CANNON_LBS12;
		}

		refShip.CanEncounter = true;
		// whoops this should be left blank as default refShip.CanBuy = true;
		refShip.Type.Trade = true;
		refShip.Type.War = true;

		// PS -->
		/*these override refShip.name for each case
		-Walk is for the big walktype switch in shipwalk.c. Case for this must exist there.
		*This is autogenerated (= *.name) on final loop if it does not already exist.

		-BI.Pic is the little pic in Battle Interface (i.e. when sailing). Case for this must exist in BI.c
		*This is autogenerated (= *.name) on final loop if it does not already exist.

		-BigPic is the big pic name (in Ships, hold, shipyard, etc.) Must have matching entry in pictures.ini
		*This is autogenerated (= *.name) on final loop if it does not already exist.

		-BigPicTex is for GetShipTexture() and is -1 for unused, 1 for Galeoths (and BP/Warship)
			and 0 for else.
		*This is autogenerated (= 0) on final loop if it does not already exist.

		-BigPicTexName is for GetShipTextureName() and is "", "SHIPS1", and "SHIPS16" respectively as above.
		*This is autogenerated (= SHIPS16) on final loop if it does not already exist.

		-SName is for the ship's type name (this is displayed by spyglass, and by BigPic in interfaces),
			so you can have the same model but a different name. :) This is NOT directly displayed;
			it is run through XI_ConvertString, so you must have an entry for this in lang\common.ini
		*This is autogenerated (= *.name) on final loop if it does not already exist.

		-All is for all the above properties, as a shortcut. If this exists, at final loop all above are
			set equal to this. For properties != name, the appropriate property is found from that ship.
			If some properties are already set, they will not be overwritten (i.e. set all to one but
			define walk, all but walk will be overwritten by all's link).
		*THE SHIP LINKED TO MUST ALREADY HAVE BEEN PROCESSED!*/

		/*if(CheckAttribute(refShip,"Walk")) { DeleteAttribute(refShip,"Walk"); }
		if(CheckAttribute(refShip,"BI.Pic")) { DeleteAttribute(refShip,"BI.Pic"); }
		if(CheckAttribute(refShip,"BigPic")) { DeleteAttribute(refShip,"BigPic"); }
		if(CheckAttribute(refShip,"BigPicTex")) { DeleteAttribute(refShip,"BigPicTex"); }
		if(CheckAttribute(refShip,"BigPicName")) { DeleteAttribute(refShip,"BigPicTexName"); }
		if(CheckAttribute(refShip,"SName")) { DeleteAttribute(refShip,"SName"); }
		if(CheckAttribute(refShip,"All")) { DeleteAttribute(refShip,"All"); }*/
		// PS <--

		refShip.FireHeight = 3.0;
		// NK declare cannon
		ShipsTypes[idx].Cannons.Borts.cannonl = "";
		ShipsTypes[idx].Cannons.Borts.cannonr = "";
		ShipsTypes[idx].Cannons.Borts.cannonf = "";
		ShipsTypes[idx].Cannons.Borts.cannonb = "";
		makearef(cannonl,ShipsTypes[idx].Cannons.Borts.cannonl);
		makearef(cannonr,ShipsTypes[idx].Cannons.Borts.cannonr);
		makearef(cannonf,ShipsTypes[idx].Cannons.Borts.cannonf);
		makearef(cannonb,ShipsTypes[idx].Cannons.Borts.cannonb);
		// NK add qtys 05-04-18 -->
		cannonf.qty = -1;
		cannonr.qty = -1;
		cannonb.qty = -1;
		cannonl.qty = -1;
		// NK <--
		if(USE_REAL_CANNONS)
		{
			cannonf.FireZone  = Degree2Radian(20.0) * FIRE_ANGLE_SCALAR_W;
			cannonf.FireDir   = Degree2Radian(0.0);
			cannonf.FireAngMin  = Degree2Radian(-2.5) * FIRE_ANGLE_SCALAR_H;
			cannonf.FireAngMax  = Degree2Radian(5.0) * FIRE_ANGLE_SCALAR_H;

			cannonr.FireZone  = Degree2Radian(30.0) * FIRE_ANGLE_SCALAR_W;
			cannonr.FireDir   = Degree2Radian(90.0);
			cannonr.FireAngMin  = Degree2Radian(-2.5) * FIRE_ANGLE_SCALAR_H;
			cannonr.FireAngMax  = Degree2Radian(5.0) * FIRE_ANGLE_SCALAR_H;

			cannonb.FireZone  = Degree2Radian(20.0) * FIRE_ANGLE_SCALAR_W;
			cannonb.FireDir   = Degree2Radian(180.0);
			cannonb.FireAngMin  = Degree2Radian(-2.5) * FIRE_ANGLE_SCALAR_H;
			cannonb.FireAngMax  = Degree2Radian(5.0) * FIRE_ANGLE_SCALAR_H;

			cannonl.FireZone  = Degree2Radian(30.0) * FIRE_ANGLE_SCALAR_W;
			cannonl.FireDir   = Degree2Radian(270.0);
			cannonl.FireAngMin  = Degree2Radian(-2.5) * FIRE_ANGLE_SCALAR_H;
			cannonl.FireAngMax  = Degree2Radian(5.0) * FIRE_ANGLE_SCALAR_H;
		}
		else
		{
			cannonf.FireZone	= Degree2Radian(30.0) * FIRE_ANGLE_SCALAR_W;
			cannonf.FireDir		= Degree2Radian(0.0);
			cannonf.FireAngMin	= -0.35 * FIRE_ANGLE_SCALAR_H*0.5; // NK 04-09-09
			cannonf.FireAngMax	= 0.60 * FIRE_ANGLE_SCALAR_H*0.5; // NK 04-09-09

			cannonr.FireZone	= Degree2Radian(80.0) * FIRE_ANGLE_SCALAR_W;
			cannonr.FireDir		= Degree2Radian(90.0);
			cannonr.FireAngMin	= -0.35 * FIRE_ANGLE_SCALAR_H*0.5; // NK 04-09-09
			cannonr.FireAngMax	= 0.60 * FIRE_ANGLE_SCALAR_H*0.5; // NK 04-09-09

			cannonb.FireZone	= Degree2Radian(30.0) * FIRE_ANGLE_SCALAR_W;
			cannonb.FireDir		= Degree2Radian(180.0);
			cannonb.FireAngMin	= -0.35 * FIRE_ANGLE_SCALAR_H*0.5; // NK 04-09-09
			cannonb.FireAngMax	= 0.60 * FIRE_ANGLE_SCALAR_H*0.5; // NK 04-09-09

			cannonl.FireZone	= Degree2Radian(80.0) * FIRE_ANGLE_SCALAR_W;
			cannonl.FireDir		= Degree2Radian(270.0);
			cannonl.FireAngMin	= -0.35 * FIRE_ANGLE_SCALAR_H*0.5; // NK 04-09-09
			cannonl.FireAngMax	= 0.60 * FIRE_ANGLE_SCALAR_H*0.5; // NK 04-09-09
		}
	}
	// PS -->
	// PRS2 holdover... if(CheckAttribute(ShipLookupTable,"id")) DeleteAttribute(ShipLookupTable,"id");
	n = 0; // first ship
	// PS <--

//  WARNING
//	SWS/WBT implemented for ALL ships; copy and paste handling templates for new ships.


//-------------------------------------------------------------------------
// Caravel1 (Changed to Caravela Latina / FastCaravel by SWS, for reasons of historical accuracy)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 003> (WBT1 L mod 2)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Caravel1";
	if(iRealismMode>0)	refShip.SName = "Caravel1_real";
	else				refShip.SName = "Caravel1";
	refShip.id				= refShip.Name;
	refShip.Class		   = 6;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS4;
	refShip.MaxCaliber		= 4;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity		= 2000;
	refShip.CannonsQuantity = 32;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	// NK <--
	refShip.MaxCrew		 = 78;
	refShip.MinCrew		 = 13;
	refShip.Price		   = 30600;
	refShip.HP			  = 1250;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 82;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 1.0; //
	refShip.period.1 = 0.6; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.2; //
	refShip.france = 0.2; //
	refShip.holland = 0.2; //
	refShip.portugal = 0.6; //
	refShip.pirate = 0.2; //
	refShip.spain = 0.6; //
	refShip.america = 0.0; //
	refShip.sweden = 0.2; //

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
//	refShip.Model = "Caravel"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = false;

	refShip.WaterLine = -0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.5;
	
	refShip.GeraldSails.rey_a2	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.3;
		refShip.TurnRate		= 65;
        refShip.InertiaAccelerationX    = 6;    refShip.InertiaBrakingX         = 0.4;
        refShip.InertiaAccelerationY    = 2.5;  refShip.InertiaBrakingY         = 0.5;
        refShip.InertiaAccelerationZ    = 2.5;  refShip.InertiaBrakingZ         = 2.0;
	}else{
		refShip.SpeedRate		= 11.8;
		refShip.TurnRate		= 40;
        refShip.InertiaAccelerationX    = 0.2;  refShip.InertiaBrakingX         = 2.0;
        refShip.InertiaAccelerationY    = 6;    refShip.InertiaBrakingY         = 4;
        refShip.InertiaAccelerationZ    = 3.0;  refShip.InertiaBrakingZ         = 3.0;
	}

	refShip.ClosestPoint = 0.20;
	refShip.BestPoint = 0.65;
	refShip.RigType = "Xeb";

// SWS - REFERENCE WBT1 - Fast Galleon
//	refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
//	refShip.InertiaAccelerationY	= 2;	refShip.InertiaBrakingY		= 0.5;
//	refShip.InertiaAccelerationZ	= 2.0;	refShip.InertiaBrakingZ		= 0.3;
//	refShip.TurnRate		= 80;

// Review: Vessel configured as: "WBT1 Light mod 2" - Caravela Latina (lateen rig, Portuguese 4 masted caravel used throughout the Colonial period)
// small high seas cruiser, deep draft V-hull, moderate turn circle (WBT1); despite smaller displacement from WBT1, turning radii is larger than other small vessels due to deep draft V // (oceanic) hull
// she has a weak rudder response due to small hydroplane area making it challenging to judge her yaw axis momentum
// Lateen rig, vastly improved upwind capability, slightly reduced running performance. Identical maneuverability to Hybrid (bonus for lateens already given)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 003> is henceforth complete
// on this day and date Sunday Dec 20 2009, 1450h


//-------------------------------------------------------------------------
// Caravel2 (Caravela Redonda)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 006> (WBT1 L)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Caravel2";
	if(iRealismMode>0)	refShip.SName = "Caravel2_real";
	else				refShip.SName = "Caravel2";
	refShip.all				= "Caravel1";
	refShip.id				= refShip.Name;
	refShip.Class		   = 6;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS4;
	refShip.MaxCaliber		= 4;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity		= 2000;
	refShip.CannonsQuantity = 32;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	// NK <--
	refShip.MaxCrew		 = 78;
	refShip.MinCrew		 = 13;
	refShip.Price		   = 30900;//BB was 30600 - faster than Latina above.
	refShip.HP			  = 1250;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 82;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 1.0; //
	refShip.period.1 = 0.6; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.2; //
	refShip.france = 0.2; //
	refShip.holland = 0.2; //
	refShip.portugal = 0.6; //
	refShip.pirate = 0.2; //
	refShip.spain = 0.6; //
	refShip.america = 0.0; //
	refShip.sweden = 0.2; //

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
//	refShip.Model = "Caravel"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = false;

	refShip.WaterLine = -0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.5;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.6;
		refShip.TurnRate		= 60;
        refShip.InertiaAccelerationX    = 6;    refShip.InertiaBrakingX         = 0.4;
        refShip.InertiaAccelerationY    = 2.25;  refShip.InertiaBrakingY         = 0.5;
        refShip.InertiaAccelerationZ    = 2.5;  refShip.InertiaBrakingZ         = 2.0;
	}else{
		refShip.SpeedRate		= 12.0;
		refShip.TurnRate		= 30;
        refShip.InertiaAccelerationX    = 0.2;  refShip.InertiaBrakingX         = 2.0;
        refShip.InertiaAccelerationY    = 6;    refShip.InertiaBrakingY         = 4;
        refShip.InertiaAccelerationZ    = 3.0;  refShip.InertiaBrakingZ         = 3.0;
	}

	refShip.ClosestPoint = 0.325;
	refShip.BestPoint = 0.8;
	refShip.RigType = "Gal";

// Review: Vessel configured as: "WBT1 Light"
// small high seas cruiser, deep draft V-hull, moderate turn circle (WBT1); despite smaller displacement from WBT1, turning radii is larger than other small vessels due to deep draft V (oceanic) hull
// she has a weak rudder response due to small hydroplane area making it challenging to judge her yaw axis momentum
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 006> is henceforth complete
// on this day and date Sunday Dec 20 2009, 1450h

//-------------------------------------------------------------------------
// AOP Caravel1 - Retextured by Seb (Caravela Redonda)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 004> (WBT1 L)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Carrack";
	refShip.id				= refShip.Name;
	refShip.All				= "Caravel1";
	refShip.walk			= "Carrack"; // PB & back84
	refShip.SName			= "Carrack1";
	refShip.Class		    = 5;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS6;
	refShip.MaxCaliber		= 6;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity		= 2200;
	refShip.CannonsQuantity = 30;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	refShip.MaxCrew		 = 110;
	refShip.MinCrew		 = 20;

	refShip.Price		   = 44000;
	refShip.HP			  = 2000;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 116;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 1.0; //
	refShip.period.1 = 0.5; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.2; //
	refShip.france = 0.2; //
	refShip.holland = 0.2; //
	refShip.portugal = 0.6; //
	refShip.pirate = 0.2; //
	refShip.spain = 0.6; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
	refShip.Type.Trade = true;
	refShip.Type.War = false;

	refShip.WaterLine = 0.4;
	refShip.SpeedDependWeight = 0.5;
	refShip.SubSeaDependWeight = 0.6;

	refShip.GeraldSails.rey_b2	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.6;
		refShip.TurnRate		= 60;
        refShip.InertiaAccelerationX    = 6;    refShip.InertiaBrakingX         = 0.4;
        refShip.InertiaAccelerationY    = 2.25;  refShip.InertiaBrakingY         = 0.5;
        refShip.InertiaAccelerationZ    = 2.5;  refShip.InertiaBrakingZ         = 2.0;
	}else{
		refShip.SpeedRate		= 12.0;
		refShip.TurnRate		= 30;
        refShip.InertiaAccelerationX    = 0.2;  refShip.InertiaBrakingX         = 2.0;
        refShip.InertiaAccelerationY    = 6;    refShip.InertiaBrakingY         = 4;
        refShip.InertiaAccelerationZ    = 3.0;  refShip.InertiaBrakingZ         = 3.0;
	}

	refShip.ClosestPoint = 0.325;
	refShip.BestPoint = 0.8;
	refShip.RigType = "Gal";


// Review: Vessel configured as: "WBT1 Light"
// small high seas cruiser, deep draft V-hull, moderate turn circle (WBT1); despite smaller displacement from WBT1, turning radii is larger than other small vessels due to deep draft V (oceanic) hull
// she has a weak rudder response due to small hydroplane area making it challenging to judge her yaw axis momentum
// This variant of small caravel should handle like WBT1L (caravel2)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 004> is henceforth complete
// on this day and date Sunday Dec 20 2009, 1450h

//-------------------------------------------------------------------------
// Light Caravel (PO_Caravel50) by Petros (Caravela Hermafrodita - hybrid F&A aft / square main rig)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 007> (WBT1 L mod1)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "PO_Caravel50";
	refShip.Nation  	= PORTUGAL;
	refShip.All 			= "Caravel1";
	if(iRealismMode>0)	refShip.SName = "Caravel3_real";
	else				refShip.SName = "Caravel3";
	refShip.id				= refShip.Name;
	refShip.Class		   = 6;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS4;
	refShip.MaxCaliber		= 4;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity		= 1800;//BB was 2000
	refShip.CannonsQuantity 	= 32;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	// NK <--
	refShip.MaxCrew		 = 78;
	refShip.MinCrew		 = 13;

	refShip.Price		   = 29000;//BB was 30600
	refShip.HP			  = 1200;//BB was 1250
	refShip.SP			  = 200;
// Petros -->
	refShip.EmblemedSails.normalTex = "sail_petros_blue_white.tga";
	refShip.EmblemedSails.nationFileName = "sail_petros_blue_white.tga";
// <-- Petros

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 82;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast5.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 1.0; //
	refShip.period.1 = 0.6; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.2; //
	refShip.portugal = 0.6; //
	refShip.pirate = 0.2; //
	refShip.spain = 0.6; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
	refShip.Type.Trade 		= true;
	refShip.Type.War		= false;

	refShip.WaterLine = -0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.5;

	refShip.GeraldSails.rey_b2  = 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.3;
		refShip.TurnRate		= 68;//BB was 65
        refShip.InertiaAccelerationX    = 6;    refShip.InertiaBrakingX         = 0.4;
        refShip.InertiaAccelerationY    = 2.45;  refShip.InertiaBrakingY         = 0.5;
        refShip.InertiaAccelerationZ    = 2.5;  refShip.InertiaBrakingZ         = 2.0;
	}else{
		refShip.SpeedRate		= 11.8;
		refShip.TurnRate		= 35;
        refShip.InertiaAccelerationX    = 0.2;  refShip.InertiaBrakingX         = 2.0;
        refShip.InertiaAccelerationY    = 6;    refShip.InertiaBrakingY         = 4;
        refShip.InertiaAccelerationZ    = 3.0;  refShip.InertiaBrakingZ         = 3.0;
	}

	refShip.ClosestPoint = 0.25;
	refShip.BestPoint = 0.8;
	refShip.RigType = "Xeb";

// Review: Vessel configured as: "WBT1 Light mod 1" - Caravela Latina / Redonda Hybrid / "Hermaphrodite" (2 lateens)
// small high seas cruiser, deep draft V-hull, moderate turn circle (WBT1); despite smaller displacement from WBT1, turning radii is larger than other small vessels due to deep draft V (oceanic) hull
// she has a weak rudder response due to small hydroplane area making it challenging to judge her yaw axis momentum
// This Light Caravel's reduced displacement should help with the rudder issue! Handling modified accordingly.
// "Half Latina" hybrid rig - improved upwind performance, and maneuverability
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 007> is henceforth complete
// on this day and date Sunday Dec 20 2009, 2150h


//-------------------------------------------------------------------------
//	Polacca by De Zeeroovers
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 076> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name		= "Polacca";
	refShip.SName		= "Polacca";
	refShip.id			= refShip.Name;
	refShip.Class		= 6;
	refShip.Weight		= Tonnes2CWT(400);
	refShip.Capacity	= 1850;
	refShip.Cannon		= CANNON_TYPE_LONG_LBS6;
	refShip.MaxCaliber	= 6;

	refShip.CannonsQuantity = 14;
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;

	refShip.MaxCrew		= 65;
	refShip.MinCrew		= 12;

	refShip.Price	= 26000;
	refShip.HP 		= 1250;
	refShip.SP 		= 200;
	refShip.Jetty	= false; // PB

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 70;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.8; //
	refShip.period.1 = 0.9; //
	refShip.period.2 = 0.6; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.5; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.5; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.5; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CannonsDeck	= 1;
	refShip.CargoHold		= 1;

	refShip.Model = "Polacca"; // KK
	refShip.Type.Trade	= true;
	refShip.Type.War		= false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refship.WaterLine				= -0.7;
	refship.SpeedDependWeight			= 0.35;
	refship.SubSeaDependWeight			= 0.8;
	refship.TurnDependWeight			= 0.35;
	
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;

	refShip.EmblemedSails.normalTex = "sail_whole_tan_plain.tga";
	refShip.EmblemedSails.nationFileName = "sail_whole_tan_plain.tga";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.1;
		refShip.TurnRate		= 75;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.8;
		refShip.TurnRate		= 38;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 1.0;
		refShip.InertiaAccelerationY	= 8;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

	refShip.RigType = "Pol";

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 076> is henceforth complete
// on this day and date Dec 31 2009, 2307h


//-------------------------------------------------------------------------
//	Polacca_N by De Zeeroovers
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 076> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name		= "Polacca_N";
	refship.All         = "Polacca";
	refShip.SName		= "Polacca";
	refShip.id			= refShip.Name;
	refShip.Class		= 6;
	refShip.Weight		= Tonnes2CWT(400);
	refShip.Capacity	= 1850;
	refShip.Cannon		= CANNON_TYPE_LONG_LBS6;
	refShip.MaxCaliber	= 6;

	refShip.CannonsQuantity = 14;
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;

	refShip.MaxCrew		= 65;
	refShip.MinCrew		= 12;

	refShip.Price	= 26000;
	refShip.HP 		= 1250;
	refShip.SP 		= 200;
	refShip.Jetty	= false; // PB

	refShip.BigPicTexName	= "SHIPS4"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 70;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.8; //
	refShip.period.1 = 0.9; //
	refShip.period.2 = 0.6; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.5; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.5; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.5; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CannonsDeck	= 1;
	refShip.CargoHold		= 1;

	refShip.Model = "Polacca"; // KK
	refShip.Type.Trade	= true;
	refShip.Type.War		= false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refship.WaterLine				= -0.7;
	refship.SpeedDependWeight			= 0.35;
	refship.SubSeaDependWeight			= 0.8;
	refship.TurnDependWeight			= 0.35;
	
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.1;
		refShip.TurnRate		= 75;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.8;
		refShip.TurnRate		= 38;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 1.0;
		refShip.InertiaAccelerationY	= 8;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

	refShip.RigType = "Pol";

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 076> is henceforth complete
// on this day and date Dec 31 2009, 2307h

//-------------------------------------------------------------------------
//	Castell Friedrichsburg by Rider88, French version
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 076> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name		= "FR_CastelF";
	refship.walk        = "CastelF";
	refShip.SName		= "Brig1T";
	refShip.id			= refShip.Name;
	refShip.Class		= 6;
	refShip.Weight		= Tonnes2CWT(400);
	refShip.Capacity	= 1550;
	refShip.Cannon		= CANNON_TYPE_LONG_LBS9;
	refShip.MaxCaliber	= 9;

	refShip.CannonsQuantity = 16;
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 2;

	refShip.MaxCrew		= 85;
	refShip.MinCrew		= 20;

	refShip.Price	= 36000;
	refShip.HP 		= 1500;
	refShip.SP 		= 200;
	refShip.Jetty	= false; // PB

	refShip.BigPicTexName	= "SHIPS3"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 70;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag2 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.5; //
	refShip.period.2 = 0.9; //
	refShip.period.3 = 0.5; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.5; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.5; //

	refShip.CannonsDeck	= 1;
	refShip.CargoHold		= 1;

	refShip.Model = "CastelF"; // KK
	refShip.Type.Trade	= true;
	refShip.Type.War		= true;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refship.WaterLine				= -0.2;
	refship.SpeedDependWeight			= 0.35;
	refship.SubSeaDependWeight			= 0.8;
	refship.TurnDependWeight			= 0.35;

	refShip.GeraldSails.rey_a2	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.9;
		refShip.TurnRate		= 70;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.8;
		refShip.TurnRate		= 38;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 1.0;
		refShip.InertiaAccelerationY	= 8;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

	refShip.ClosestPoint = 0.275;
	refShip.BestPoint = 0.75;
	refShip.RigType = "Btn";

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 076> is henceforth complete
// on this day and date Dec 31 2009, 2307h

//-------------------------------------------------------------------------
//	Castell Friedrichsburg by Rider88, Dutch version
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 076> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name		= "NL_CastelF";
	refship.walk        = "CastelF";
	refShip.SName		= "Brig1T";
	refShip.id			= refShip.Name;
	refShip.Class		= 6;
	refShip.Weight		= Tonnes2CWT(400);
	refShip.Capacity	= 1550;
	refShip.Cannon		= CANNON_TYPE_LONG_LBS9;
	refShip.MaxCaliber	= 9;

	refShip.CannonsQuantity = 16;
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 2;

	refShip.MaxCrew		= 85;
	refShip.MinCrew		= 20;

	refShip.Price	= 36000;
	refShip.HP 		= 1500;
	refShip.SP 		= 200;
	refShip.Jetty	= false; // PB

	refShip.BigPicTexName	= "SHIPS3"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 70;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag2 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.5; //
	refShip.period.2 = 0.9; //
	refShip.period.3 = 0.5; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.5; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CannonsDeck	= 1;
	refShip.CargoHold		= 1;

	refShip.Model = "CastelF"; // KK
	refShip.Type.Trade	= true;
	refShip.Type.War		= true;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refship.WaterLine				= -0.2;
	refship.SpeedDependWeight			= 0.35;
	refship.SubSeaDependWeight			= 0.8;
	refship.TurnDependWeight			= 0.35;
	
	refShip.GeraldSails.rey_a2	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.9;
		refShip.TurnRate		= 70;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.8;
		refShip.TurnRate		= 38;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 1.0;
		refShip.InertiaAccelerationY	= 8;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

	refShip.ClosestPoint = 0.275;
	refShip.BestPoint = 0.75;
	refShip.RigType = "Btn";

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 076> is henceforth complete
// on this day and date Dec 31 2009, 2307h

//-------------------------------------------------------------------------
//	Castell Friedrichsburg by Rider88, Spanish version
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 076> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name		= "SP_CastelF";
	refship.walk        = "CastelF";
	refShip.SName		= "Brig1T";
	refShip.id			= refShip.Name;
	refShip.Class		= 6;
	refShip.Weight		= Tonnes2CWT(400);
	refShip.Capacity	= 1550;
	refShip.Cannon		= CANNON_TYPE_LONG_LBS9;
	refShip.MaxCaliber	= 9;

	refShip.CannonsQuantity = 16;
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 2;

	refShip.MaxCrew		= 85;
	refShip.MinCrew		= 20;

	refShip.Price	= 36000;
	refShip.HP 		= 1500;
	refShip.SP 		= 200;
	refShip.Jetty	= false; // PB

	refShip.BigPicTexName	= "SHIPS3"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 70;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag2 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.5; //
	refShip.period.2 = 0.9; //
	refShip.period.3 = 0.5; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.5; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CannonsDeck	= 1;
	refShip.CargoHold		= 1;

	refShip.Model = "CastelF"; // KK
	refShip.Type.Trade	= true;
	refShip.Type.War		= true;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refship.WaterLine				= -0.2;
	refship.SpeedDependWeight			= 0.35;
	refship.SubSeaDependWeight			= 0.8;
	refship.TurnDependWeight			= 0.35;
	
	refShip.GeraldSails.rey_a2	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.9;
		refShip.TurnRate		= 70;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.8;
		refShip.TurnRate		= 38;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 1.0;
		refShip.InertiaAccelerationY	= 8;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

	refShip.ClosestPoint = 0.275;
	refShip.BestPoint = 0.75;
	refShip.RigType = "Btn";

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 076> is henceforth complete
// on this day and date Dec 31 2009, 2307h

//-------------------------------------------------------------------------
// Merchant Pinnace by De Zeeroovers
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 087> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "PinnaceMerchant";
	refShip.SName	 		= "PinnaceMerchant";
	refShip.id				= refShip.Name;
	refShip.walk			= "PinnaceMerchant"; // Hylie Pistof
	refShip.Class		   = 4;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS9;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(750);
	refShip.Capacity		= 5000;
	refShip.CannonsQuantity = 26;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 120;
	refShip.MinCrew		 = 40;
	refShip.Price		   = 51200;
	refShip.HP			  = 3500;
	refShip.SP			  = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName = "SHIPS1"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 116;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast0.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.7; //
	refShip.period.2 = 0.8; //
	refShip.period.3 = 0.5; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.6; //
	refShip.france = 0.4; //
	refShip.holland = 0.5; //
	refShip.portugal = 0.46; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.2; //

	refShip.Model = "Merchant Pinnace"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = -0.6;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.8;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 8.5;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.6;
		refShip.TurnRate		= 29;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 3.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 087> is henceforth complete
// on this day and date Jan 1 2010, 1046h


//-------------------------------------------------------------------------
// Medium Pinnace by De Zeeroovers
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 090> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "PinnaceMedium";
	refShip.sname      		= "PinnaceMedium";
	refShip.All				= "Pinnace1";
	refShip.id				= refShip.Name;
	refShip.walk			= "PinnaceMedium"; // Hylie Pistof
	refShip.Class		   = 5;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS9;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(600);//BB was 800, reduced for better match vs other Pinnace
	refShip.Capacity		= 3500;
	refShip.CannonsQuantity = 18;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	refShip.MaxCrew		 = 117;
	refShip.MinCrew		 = 23;
	refShip.Price		   = 54800;
	refShip.HP			  = 2300;//BB was 2000, increased due to extra weight vs other Pinnace
	refShip.SP			  = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName = "SHIPS1"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 116;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.6; //
	refShip.period.2 = 0.7; //
	refShip.period.3 = 0.4; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.37; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Medium Pinnace"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine          = -0.7;       
	refShip.SpeedDependWeight  = 0.3;
	refShip.SubSeaDependWeight = 1.3;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 9.5;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.6;
		refShip.TurnRate		= 29;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 3.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 090> is henceforth complete
// on this day and date Jan 1 2010, 1046h


//-------------------------------------------------------------------------
// Schooner1
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 008> (WBT2)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Schooner1";
	refShip.SName	 		= "Schooner1";
	refShip.id				= refShip.Name;
	refShip.Class		   = 6;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS6;
	refShip.MaxCaliber		= 6;
	refShip.Weight			= Tonnes2CWT(200);
	refShip.Capacity		= 1250;
	refShip.CannonsQuantity = 20;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 90;
	refShip.MinCrew		 = 18;
	refShip.Price		   = 46000;
	refShip.HP			  = 1250;
	refShip.SP			  = 200;

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 114;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.2; //
	refShip.period.3 = 0.3; //
	refShip.period.4 = 0.3; //
	refShip.period.5 = 0.5; //
	//Nation
	refShip.england = 0.2; //
	refShip.france = 0.2; //
	refShip.holland = 0.3; //
	refShip.portugal = 0.2; //
	refShip.pirate = 0.3; //
	refShip.spain = 0.2; //
	refShip.america = 0.3; //
	refShip.sweden = 0.2; //

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
//	refShip.Model = "Schooner"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.2;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 14.0;
		refShip.TurnRate		= 100;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.35;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 16.0;
		refShip.TurnRate		= 45;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

//	Reference: default schooner rig
	refShip.ClosestPoint = 0.15;
	refShip.BestPoint = 0.675;
	// KK refShip.RigType = sDet;

// Review: Vessel configured as:
// gaff rig schooner, V-hull, moderate turn circle (WBT2) - penalty to turning circle from V hull, relatively easy to handle otherwise
// no squaresail, reduced max speed to 13kts (fore and aft rigs not optimal for running)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 008> is henceforth complete
// on this day and date Sunday Dec 20 2009, 2246h

//-------------------------------------------------------------------------
// Schooner2
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 009> (WBT2)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Schooner2";//BB 'trade' varient
	refShip.All				= "Schooner1";
	refShip.SName	 		= "Schooner1";
	refShip.id				= refShip.Name;
	refShip.Class		   = 6;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS6;//BB was LBS_9
	refShip.MaxCaliber		= 6;//BB was 9
	refShip.Weight			= Tonnes2CWT(250);//BB was 200
	refShip.Capacity		= 1500;//BB was 1250
	refShip.CannonsQuantity = 20;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 90;
	refShip.MinCrew		 = 18;
	refShip.Price		   = 48000;//BB was 46000
	refShip.HP			  = 1250;
	refShip.SP			  = 200;

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 114;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.2; //
	refShip.period.3 = 0.3; //
	refShip.period.4 = 0.3; //
	refShip.period.5 = 0.5; //
	//Nation
	refShip.england = 0.2; //
	refShip.france = 0.2; //
	refShip.holland = 0.3; //
	refShip.portugal = 0.2; //
	refShip.pirate = 0.3; //
	refShip.spain = 0.2; //
	refShip.america = 0.3; //
	refShip.sweden = 0.2; //

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
//	refShip.Model = "Schooner"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.2;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;//BB was 14.0
		refShip.TurnRate		= 100;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.35;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 16.0;
		refShip.TurnRate		= 45;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

//	Reference: default schooner rig
	refShip.ClosestPoint = 0.15;
	refShip.BestPoint = 0.675;
	// KK refShip.RigType = sDet;

// Review: Vessel configured as:
// gaff rig schooner, V-hull, moderate turn circle (WBT2) - penalty to turning circle from V hull, relatively easy to handle otherwise
// no squaresail, reduced max speed to 13kts (fore and aft rigs not optimal for running)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 009> is henceforth complete
// on this day and date Sunday Dec 20 2009, 2246h

//-------------------------------------------------------------------------
// War Schooner by JMV575 8/25/04, Skin by Rafe Bligh
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 010> (WBT2T)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name	 = "SchoonerWar";
	refShip.All	  = "Schooner1";
	refShip.SName	 = "SchoonerModN";
	refShip.id 	 = refShip.Name;
	refShip.Class		= 6;
	refShip.Cannon		= CANNON_TYPE_CARRONADE_LBS18;
	refShip.MaxCaliber	= 9; // GR: was 6, doesn't fit with 18lb carronade, naval ship
	refShip.Weight		= Tonnes2CWT(200);
	refShip.Capacity	= 1000;
	refShip.CannonsQuantity = 20;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew	  = 120;
	refShip.MinCrew	  = 24;
	refShip.Price			= 75000;//BB was 69000
	refShip.HP 		   = 1750;
	refShip.SP 		   = 200;

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 114;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
 	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.2; //
	refShip.period.3 = 0.3; //
	refShip.period.4 = 0.3; //
	refShip.period.5 = 0.5; //
	//Nation
	refShip.england = 0.2; //
	refShip.france = 0.2; //
	refShip.holland = 0.3; //
	refShip.portugal = 0.2; //
	refShip.pirate = 0.3; //
	refShip.spain = 0.2; //
	refShip.america = 0.3; //
	refShip.sweden = 0.2; //
	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.2;

	refShip.GeraldSails.rey_b2	= 1;

	refShip.Height.Bombs.Y 	 = 1.0; 	 refShip.Height.Bombs.DY	 = 1.0;
	refShip.Height.Grapes.Y	 = 2.0; 	 refShip.Height.Grapes.DY	 = 1.0;
	refShip.Height.Knippels.Y	 = 15.0;	 refShip.Height.Knippels.DY  = 10.0;
	refShip.Height.Balls.Y 	 = 1.0; 	 refShip.Height.Balls.DY	 = 1.0;


	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 14.5;
		refShip.TurnRate		= 85;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.25;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 16.3;
		refShip.TurnRate		= 46.55;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

//	Topsail schooner - better running performance, reduced upwind capability, war schooner has significantly smaller // gaffs, ie, a compromise
	refShip.ClosestPoint = 0.27;
	refShip.BestPoint = 0.75;
	// KK refShip.RigType = sDet;

// Review: Vessel configured as:
// topsail schooner, V-hull, moderate turn circle (WBT2T) - penalty to turning circle from V hull, relatively easy to handle otherwise
// square topsail, bonus to max speed  15kts, expense of reduced maneuverability
// jury rig topsail schooner config - reduced upwind capability, better at running, but rather ponderous
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 010> is henceforth complete
// on this day and date Sunday Dec 20 2009, 2307h



//-------------------------------------------------------------------------
// Rum Runner (Schooner50)		By Petros
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 011> (WBT2 T)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Schooner50";
	refShip.All				= "Schooner1";
	refShip.SName			= "SchoonerMod";
	refShip.id				= refShip.Name;
	refShip.Nation			= Portugal;
	refShip.Class			= 6;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS6;
	refShip.MaxCaliber		= 6;
	refShip.Weight			= Tonnes2CWT(200);
	refShip.Capacity		= 1250;
	refShip.CannonsQuantity = 20;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 90;
	refShip.MinCrew		 = 18;
	refShip.Price		   = 50000;//BB was 46000
	refShip.HP			  = 1250;
	refShip.SP			  = 200;
// Petros -->
	refShip.EmblemedSails.normalTex = "sail_petros_blue_white.tga";
	refShip.EmblemedSails.nationFileName = "sail_petros_blue_white.tga";
// <-- Petros

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 114;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.2; //
	refShip.period.3 = 0.3; //
	refShip.period.4 = 0.3; //
	refShip.period.5 = 0.5; //
	//Nation
	refShip.england = 0.2; //
	refShip.france = 0.2; //
	refShip.holland = 0.3; //
	refShip.portugal = 0.2; //
	refShip.pirate = 0.3; //
	refShip.spain = 0.2; //
	refShip.america = 0.3; //
	refShip.sweden = 0.2; //


	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
	refShip.Type.Trade = true;
	refShip.Type.War = true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.2;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 14.5;
		refShip.TurnRate		= 85;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.25;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 16.3;
		refShip.TurnRate		= 46.55;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

//	Topsail schooner - better running performance, reduced upwind capability, war schooner has significantly smaller gaffs, ie, a compromise
	refShip.ClosestPoint = 0.27;
	refShip.BestPoint = 0.75;
	// KK refShip.RigType = sDet;

// Review: Vessel configured as:
// topsail schooner, V-hull, moderate turn circle (WBT2T) - penalty to turning circle from V hull, relatively easy to handle otherwise
// square topsail, bonus to max speed  15kts, expense of reduced maneuverability
// jury rig topsail schooner config - reduced upwind capability, better at running, but rather ponderous
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 011> is henceforth complete
// on this day and date Monday Dec 20 2009, 0037h


//-------------------------------------------------------------------------
//	Colonial Fast Schooner by Thomas the Terror
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 013> (WBT2TN)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name	 = "US_Schooner47";
	refShip.All	  = "Schooner1";
	refShip.SName	 = "SchoonerModAdv";
	refShip.id 	 = refShip.Name;
	refShip.Class			= 6;
	refShip.Walk		 = "schooner1";
	refShip.Cannon		 = CANNON_TYPE_LONG_LBS6;
	refShip.MaxCaliber		= 6;
	refShip.Weight 		 = Tonnes2CWT(115);
	refShip.Capacity		 = 1250;
	refShip.CannonsQuantity = 20;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew	  = 90;
	refShip.MinCrew	  = 18;
	refShip.Price			= 55000;//BB was 46000
	refShip.HP 		   = 1250;
	refShip.SP 		   = 200;

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 114;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.8; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.4; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
	refShip.Type.Trade = true;
	refShip.Type.War = true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.4;

	refShip.Height.Bombs.Y 	 = 1.0; 	 refShip.Height.Bombs.DY	 = 1.0;
	refShip.Height.Grapes.Y	 = 2.0; 	 refShip.Height.Grapes.DY	 = 1.0;
	refShip.Height.Knippels.Y	 = 15.0;	 refShip.Height.Knippels.DY  = 10.0;
	refShip.Height.Balls.Y 	 = 1.0; 	 refShip.Height.Balls.DY	 = 1.0;

	refShip.GeraldSails.rey_b2  = 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 16.4;
		refShip.TurnRate		= 90;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.25;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 16.4;
		refShip.TurnRate		= 46.7;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

//	Reference: default schooner rig
	refShip.ClosestPoint = 0.15;
	refShip.BestPoint = 0.625;
	// KK refShip.RigType = sDet;


// Review: Vessel configured as:
// advanced topsail schooner, V-hull, moderate turn circle (WBT2TN) - penalty to turning circle from V hull, relatively easy to handle otherwise
//  (Early Baltimore Clipper?)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 013> is henceforth complete
// on this day and date Monday Dec 21 2009, 0057h


//-------------------------------------------------------------------------
// Hooker by Seb - "Large Square-Topsail Schooner"
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 015> (WBT2TN)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Hooker";
	refShip.id				= refShip.Name;
	refShip.All	  = "Schooner1";
	refShip.SName			= "SchoonerSqN";
	refShip.Walk			= "Hooker"; // PB & back84
	refShip.Class		   = 6;
	refShip.Cannon			= CANNON_TYPE_CARRONADE_LBS18;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(200);
	refShip.Capacity		= 1000;
	refShip.CannonsQuantity = 20;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 120;
	refShip.MinCrew		 = 24;
	refShip.Price		   = 69000;
	refShip.HP			  = 1750;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 114;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.4; //
	refShip.period.5 = 0.7; //
	//Nation
	refShip.england = 0.2; //
	refShip.france = 0.2; //
	refShip.holland = 0.3; //
	refShip.portugal = 0.2; //
	refShip.pirate = 0.3; //
	refShip.spain = 0.2; //
	refShip.america = 0.3; //
	refShip.sweden = 0.0; //

// <-- KK

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.2;
	
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_b2	= 1;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 14.3;
		refShip.TurnRate		= 75;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.25;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 15.5;
		refShip.TurnRate		= 46;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

//	Square Topsail schooner - optimal sail angle is downwind in broad reach
	refShip.ClosestPoint = 0.24;
	refShip.BestPoint = 0.75;
	// KK refShip.RigType = sDet;

// Review: Vessel configured as:
//  topsail schooner with additional main squaresail, V-hull, moderate turn circle (WBT2T2) - penalty to turning circle from V hull, relatively easy to handle otherwise
//  Heavy Schooner - does not turn as well, but fast downwind
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 015> is henceforth complete
// on this day and date Dec 22 2009, 2142h

//-------------------------------------------------------------------------
// Brig1
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 028> (WBT2T) -
// Renamed to Sloop of War, 22 guns, to match LiB reskin
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Brig1";
	refShip.SName	 		= "Brig1H";
	refShip.id				= refShip.Name;
	refShip.Class		   = 6;
	refShip.Cannon			= CANNON_TYPE_CARRONADE_LBS12;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity		= 1000;
	refShip.CannonsQuantity = 22;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 132;
	refShip.MinCrew		 = 26;
	refShip.Price		   = 76800;
	refShip.HP			  = 2000;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 84;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.2; //
	refShip.period.2 = 0.6; //
	refShip.period.3 = 0.9; //
	refShip.period.4 = 1.0; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.5; //
	refShip.holland = 0.5; //
	refShip.portugal = 0.5; //
	refShip.pirate = 0.2; //
	refShip.spain = 0.5; //
	refShip.america = 0.6; //
	refShip.sweden = 0.2; //

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;
	refShip.Model = "Brig"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = 0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.4;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 90;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.1;
		refShip.TurnRate		= 47;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2) - no penalty to turning circle due to not-so-fine hull shape
// square rigger - does not handle as well upwind, compensate with stays and spanker
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 028> is henceforth complete
// on this day and date Sunday Dec 24 2009, 2146h

//-------------------------------------------------------------------------
// Shnyava1 - "Snow-Brig - looks like a barque-rigged schooner hull! by Cpt.Daniel Wolf -2007 june
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 020> (WBT2T)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			 = "Shnyava1";
	refShip.id 			 = refShip.Name;
	refShip.Walk		 = "schooner1";
	refShip.sname			= "Snow1";
	refShip.All			 = "Brig1";
	refShip.Class			= 6;
	refShip.Cannon		 = CANNON_TYPE_LONG_LBS9;	// was LBS6
	refShip.MaxCaliber		= 9;			// was 6
	refShip.Weight 		 = Tonnes2CWT(200);
	refShip.Capacity		 = 1250;
	refShip.CannonsQuantity = 20;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew	  = 90;
	refShip.MinCrew	  = 18;
	refShip.Price			= 42000;//BB was 46000
	refShip.HP 		   = 1250;
	refShip.SP 		   = 200;

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 8;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag2 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.3; //
	refShip.period.3 = 0.3; //
	refShip.period.4 = 0.4; //
	refShip.period.5 = 0.5; //
	//Nation
	refShip.england = 0.3; //
	refShip.france = 0.2; //
	refShip.holland = 0.2; //
	refShip.portugal = 0.2; //
	refShip.pirate = 0.3; //
	refShip.spain = 0.2; //
	refShip.america = 0.3; //
	refShip.sweden = 0.2; //

//	refShip.Model = "Shnyava"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = true;

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
	refShip.WaterLine = 0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.2;

	refShip.Height.Bombs.Y 	 = 1.0; 	 refShip.Height.Bombs.DY	 = 1.0;
	refShip.Height.Grapes.Y	 = 2.0; 	 refShip.Height.Grapes.DY	 = 1.0;
	refShip.Height.Knippels.Y	 = 15.0;	 refShip.Height.Knippels.DY  = 10.0;
	refShip.Height.Balls.Y 	 = 1.0; 	 refShip.Height.Balls.DY	 = 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//	refShip.ClosestPoint = 0.3;
//	refShip.BestPoint = 0.8;
//	refShip.RigType = "Shn";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 95;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.5;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.0;
		refShip.TurnRate		= 45;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2) - penalty to turning circle from V hull, relatively easy to handle otherwise
// square rigger - does not handle as well upwind
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 020> is henceforth complete
// on this day and date Sunday Dec 24 2009, 1958h


 //-------------------------------------------------------------------------
 // Shnyava2
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 021> (WBT2T)
 //-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			 = "Shnyava2";//BB 'trade' variety
	refShip.id 			 = refShip.Name;
	refShip.All				= "Shnyava1";
	refShip.Walk		 = "schooner2";
	refShip.sname			= "Snow1";
	refShip.Class			= 6;
	refShip.Cannon		 = CANNON_TYPE_LONG_LBS6;	// was LBS9
	refShip.MaxCaliber		= 6;			// was 9
	refShip.Weight 		 = Tonnes2CWT(220);//BB was 200
	refShip.Capacity		 = 1450;//BB was 1250
	refShip.CannonsQuantity = 20;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew	  = 90;
	refShip.MinCrew	  = 18;
	refShip.Price			= 44000;//BB was 46000
	refShip.HP 		   = 1250;
	refShip.SP 		   = 200;

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 8;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag2 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.3; //
	refShip.period.3 = 0.3; //
	refShip.period.4 = 0.4; //
	refShip.period.5 = 0.5; //
	//Nation
	refShip.england = 0.3; //
	refShip.france = 0.2; //
	refShip.holland = 0.2; //
	refShip.portugal = 0.2; //
	refShip.pirate = 0.3; //
	refShip.spain = 0.2; //
	refShip.america = 0.3; //
	refShip.sweden = 0.2; //

	refShip.CanEncounter	 = true;
	refShip.CanBuy		= true;
//	refShip.Model = "Shnyava"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = true;

	refShip.WaterLine = 0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.2;

	refShip.Height.Bombs.Y 	 = 1.0; 	 refShip.Height.Bombs.DY	 = 1.0;
	refShip.Height.Grapes.Y	 = 2.0; 	 refShip.Height.Grapes.DY	 = 1.0;
	refShip.Height.Knippels.Y	 = 15.0;	 refShip.Height.Knippels.DY  = 10.0;
	refShip.Height.Balls.Y 	 = 1.0; 	 refShip.Height.Balls.DY	 = 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//	refShip.ClosestPoint = 0.3;
//	refShip.BestPoint = 0.8;
//	refShip.RigType = "Shn";

// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 90;//BB was 95
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.5;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.0;
		refShip.TurnRate		= 45;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2) - penalty to turning circle from V hull, relatively easy to handle otherwise
// square rigger - does not handle as well upwind
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 021> is henceforth complete
// on this day and date Sunday Dec 24 2009, 1958h

//-------------------------------------------------------------------------
// HMS Bounty - By ZarethPL
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 052> (WBT2T)  - small ship rigged courier
//-------------------------------------------------------------------------
	// PS -->
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "HMS_Bounty";
	refShip.SName			= "Merchant2";
	refShip.all				= "Brig1";
	refShip.id				= refShip.Name;
	refShip.Class			= 7;
	refShip.Walk			= "Bounty"; // PB & back84
	refShip.Cannon			= CANNON_TYPE_LONG_LBS4;
	refShip.MaxCaliber		= 4;
	refShip.Weight			= Tonnes2CWT(350);
	refShip.Capacity		= 1250;
	refShip.CannonsQuantity	= 14;
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;
	refShip.MaxCrew			= 44;
	refShip.MinCrew			= 6;
	refShip.Price			= 19200;//BB was 15200
	refShip.HP				= 1000;
	refShip.SP				= 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 88;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.9; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 0.6; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;
	refShip.Type.Trade 			= true;
	refShip.Type.War 			= false;

	refShip.WaterLine			= 0.0;
	refShip.SpeedDependWeight	= 0.3;
	refShip.SubSeaDependWeight	= 0.3;
	
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;	

// Brigs were difficult to sail upwind. But this one has an immense number of stays
	refShip.ClosestPoint = 0.265;
	refShip.BestPoint = 0.75;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.5;
		refShip.TurnRate		= 105;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.4;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.8;
		refShip.TurnRate		= 37;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2) - no penalty to turning circle due to not-so-fine hull shape
// square rigger - does not handle as well upwind, compensate with stays and spanker
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 052> is henceforth complete
// on this day and date Sunday Dec 25 2009, 1144h

//-------------------------------------------------------------------------
// Royal Brig by Yo Ho Ho
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 022> (WBT2T)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "BrigRoyal";
	refShip.All				= "HMS_Bounty";
	refShip.SName			= "LightBrigN";
	refShip.all				= "Brig1";
	refShip.walk			= "";
	refShip.id				= refShip.Name;
	refShip.Class			= 7;
	refShip.Cannon			= CANNON_TYPE_CARRONADE_LBS12;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity		= 750;
	refShip.CannonsQuantity = 16;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	refShip.MaxCrew		 = 72;
	refShip.MinCrew		 = 14;
	refShip.Price		   = 46800;
	refShip.HP			  = 1500;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 88;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.2; //
	refShip.period.2 = 0.6; //
	refShip.period.3 = 0.8; //
	refShip.period.4 = 0.2; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.4; //
	refShip.france = 0.5; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.4; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.4; //
	refShip.america = 0.0; //
	refShip.sweden = 0.4; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;

	refShip.WaterLine = 1.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.3;
	
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.5;
		refShip.TurnRate		= 105;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.4;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.0;
		refShip.TurnRate		= 45;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2) - no penalty to turning circle due to not-so-fine hull shape
// square rigger - does not handle as well upwind, compensate with stays and spanker
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 022> is henceforth complete
// on this day and date Sunday Dec 24 2009, 2020h

//-------------------------------------------------------------------------
// HMS Interceptor by Kazeite
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 027> (WBT2T)
//-------------------------------------------------------------------------
	// PS -->
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "HMS_Interceptor";
	refShip.All				= "Brig1";
	refShip.SName			= "Sloop2";
	refShip.walk			= "Interceptor";
	refShip.id				= refShip.Name;
	refShip.nation			= ENGLAND;
	refShip.Class			= 7;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS4;
	refShip.MaxCaliber		= 4;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity		= 1000;
	refShip.CannonsQuantity = 18;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 44;
	refShip.MinCrew		 = 20; //BB restored from 2
	refShip.Price		   = 52000;//BB was 32000
	refShip.HP			  = 2000;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada

// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 6;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag2 = FLAG_ENSIGN;
	refShip.Flags.UseNavalFlag = true;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.4; //
	refShip.period.2 = 0.6; //
	refShip.period.3 = 0.8; //
	refShip.period.4 = 1.0; //
	refShip.period.5 = 0.9; //
	//Nation
	refShip.england = 1.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.CanBuy				= false;
	refShip.CanEncounter		= false;

	refShip.WaterLine = 1.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.3;
	
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 14.5;//BB was 15.0, too fast even for a fast brig? GR: was 14.0, schooners are faster!
		refShip.TurnRate		= 105;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.4;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 15.5;
		refShip.TurnRate		= 40;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2) - no penalty to turning circle due to not-so-fine hull shape
// square rigger - does not handle as well upwind, compensate with stays and spanker
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 027> is henceforth complete
// on this day and date Sunday Dec 24 2009, 2137h

//-------------------------------------------------------------------------
// Fast Brig, based on HMS Interceptor by Kazeite, retextured by Grey Roger
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 027> (WBT2T)
//-------------------------------------------------------------------------
	// PS -->
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "RN_Interceptor";
	refShip.All			= "Brig1";
	refShip.SName			= "Brig1N";
	refShip.walk			= "Interceptor";
	refShip.id			= refShip.Name;
	refShip.nation			= ENGLAND;
	refShip.Class			= 7;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS4;
	refShip.MaxCaliber		= 4;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity		= 1000;
	refShip.CannonsQuantity = 18;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 57;
	refShip.MinCrew		 = 12;
	refShip.Price		   = 40800;
	refShip.HP			  = 2000;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS3"; // Armada

// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 6;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag2 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.5; //
	refShip.period.5 = 0.3; //
	//Nation
	refShip.england = 0.3; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;
	refShip.Model = "Fastbrig";

	refShip.WaterLine = 1.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.3;
	
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.5;
		refShip.TurnRate		= 105;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.4;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.5;
		refShip.TurnRate		= 37;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2) - no penalty to turning circle due to not-so-fine hull shape
// square rigger - does not handle as well upwind, compensate with stays and spanker
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 027> is henceforth complete
// on this day and date Sunday Dec 24 2009, 2137h

//-------------------------------------------------------------------------
// Fast Brig, based on HMS Interceptor by Kazeite, retextured by Grey Roger
// This is "Lady Washington", the ship which played several different ships
// in various films and TV shows, including "HMS Interceptor".
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 027> (WBT2T)
//-------------------------------------------------------------------------
	// PS -->
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "US_Interceptor";
	refShip.All			= "Brig1";
	refShip.SName			= "SloopUS";
	refShip.walk			= "Interceptor";
	refShip.id			= refShip.Name;
	refShip.nation			= AMERICA;
	refShip.Class			= 7;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS4;
	refShip.MaxCaliber		= 4;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity		= 1000;
	refShip.CannonsQuantity = 18;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--

	refShip.MaxCrew		 = 57;		// GR: Taken from real "Lady Washington", which has 12 crew
	refShip.MinCrew		 = 12;		// and 45 passengers
	refShip.Price		   = 40800;
	refShip.HP			  = 2000;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS3"; // Armada

// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 6;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag2 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.5; //
	refShip.period.5 = 0.3; //
	//Nation
	refShip.england = 0.1; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.3; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = true;
	refShip.Type.War = true;

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;
	refShip.Model = "Fastbrig";

	refShip.WaterLine = 1.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.3;
	
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.5;
		refShip.TurnRate		= 105;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.4;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.5;
		refShip.TurnRate		= 37;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2) - no penalty to turning circle due to not-so-fine hull shape
// square rigger - does not handle as well upwind, compensate with stays and spanker
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 027> is henceforth complete
// on this day and date Sunday Dec 24 2009, 2137h

//-------------------------------------------------------------------------
// Yacht1
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 031> (WBT2T)  - "English Bark"
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Yacht1";
	refShip.SName	 		= "Yacht1";
	refShip.id				= refShip.Name;
	refShip.Class		   = 7;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS4;
	refShip.MaxCaliber		= 4;
	refShip.Weight			= Tonnes2CWT(200);
	refShip.Capacity		= 1250;
	refShip.CannonsQuantity = 16;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 32;
	refShip.MinCrew		 = 7;
	refShip.Price		   = 16800;
	refShip.HP			  = 1000;
	refShip.SP			  = 200;

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 100;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.9; //
	refShip.period.2 = 1.0; //
	refShip.period.3 = 0.9; //
	refShip.period.4 = 0.8; //
	refShip.period.5 = 0.7; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.3; //
	refShip.holland = 0.3; //
	refShip.portugal = 0.3; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.3; //
	refShip.america = 0.3; //
	refShip.sweden = 0.3; //

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;
	refShip.Model = "Bark"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = false;

	refShip.WaterLine = 0.03;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.3;
	
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.0;
		refShip.TurnRate		= 85;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.4;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.7;
		refShip.TurnRate		= 42;
		refShip.InertiaAccelerationX	= 2.0;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 8;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2)
// square rigger - does not handle as well upwind, compensate with stays and spanker
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 031> is henceforth complete
// on this day and date Sunday Dec 25 2009, 0956h

//-------------------------------------------------------------------------
// Yacht2
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 032> (WBT2T) - "English Bark"
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Yacht2";
	refShip.All				= "Yacht1";
	refShip.SName	 		= "Yacht1";
	refShip.id				= refShip.Name;
	refShip.Class		   = 7;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS4;
	refShip.MaxCaliber		= 4;
	refShip.Weight			= Tonnes2CWT(200);
	refShip.Capacity		= 1250;
	refShip.CannonsQuantity = 16;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 32;
	refShip.MinCrew		 = 7;
	refShip.Price		   = 16800;
	refShip.HP			  = 1000;
	refShip.SP			  = 200;

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 100;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.9; //
	refShip.period.2 = 1.0; //
	refShip.period.3 = 0.9; //
	refShip.period.4 = 0.8; //
	refShip.period.5 = 0.7; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.3; //
	refShip.holland = 0.3; //
	refShip.portugal = 0.3; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.3; //
	refShip.america = 0.3; //
	refShip.sweden = 0.3; //

	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;
	refShip.Model = "Bark"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = false;

	refShip.WaterLine = -0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.3;
	
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;	

// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.0;
		refShip.TurnRate		= 85;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.4;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.7;
		refShip.TurnRate		= 42;
		refShip.InertiaAccelerationX	= 2.0;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 8;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2)
// square rigger - does not handle as well upwind, compensate with stays and spanker
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 032> is henceforth complete
// on this day and date Sunday Dec 24 2009, 2152h

//-------------------------------------------------------------------------
// Barque1
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 033> (WBT2T)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Barque1";
	refShip.SName	 		= "Barque1";
	refShip.id				= refShip.Name;
	refShip.Class		   = 7;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS4;
	refShip.MaxCaliber		= 4;
	refShip.Weight			= Tonnes2CWT(350);
	refShip.Capacity		= 1250;
	refShip.CannonsQuantity = 16;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 32;
	refShip.MinCrew		 = 7;
	refShip.Price		   = 16800;
	refShip.HP			  = 1000;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 88;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.7; //
	refShip.period.3 = 0.8; //
	refShip.period.4 = 0.8; //
	refShip.period.5 = 0.9; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.5; //
	refShip.holland = 0.5; //
	refShip.portugal = 0.5; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.5; //
	refShip.america = 0.5; //
	refShip.sweden = 0.5; //

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;
	refShip.Model = "Barque"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = false;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.3;
	
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.0;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.9;
		refShip.TurnRate		= 42;
		refShip.InertiaAccelerationX	= 1.0;	refShip.InertiaBrakingX		= 1.0;
		refShip.InertiaAccelerationY	= 6;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 2.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2)
// square rigger - does not handle as well upwind, compensate with stays and spanker
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 033> is henceforth complete
// on this day and date Sunday Dec 25 2009, 1419h

//-------------------------------------------------------------------------
// Fast Barque (Barque3_50) by Petros - SWS / This is a "Jackass Bark" with 2 lateens and square main
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 034> (WBT2J)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Barque3_50";
	refShip.All				= "Barque1";
	refShip.SName			= "BarqueHybrid";
	refShip.id				= refShip.Name;
	refShip.walk			= "Yacht2"; // PB
	refShip.Class			= 7;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS6;
	refShip.MaxCaliber		= 6;
	refShip.Weight			= Tonnes2CWT(250);
	refShip.Capacity		= 1250; // Armada: Adjusted for Bartolomeu storyline
	refShip.CannonsQuantity 	= 16;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 	= 48;
	refShip.MinCrew		 	= 10;
	refShip.Price		   	= 27200;
	refShip.HP			 	= 1000;
	refShip.SP				= 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 88;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.4; //
	refShip.period.2 = 0.6; //
	refShip.period.3 = 0.6; //
	refShip.period.4 = 0.2; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.5; //
	refShip.holland = 0.5; //
	refShip.portugal = 0.5; //
	refShip.pirate = 0.5; //
	refShip.spain = 0.5; //
	refShip.america = 0.5; //
	refShip.sweden = 0.5; //

	refShip.Type.Trade	= true;
	refShip.Type.War		= true;

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;

	refShip.WaterLine = -0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.2;
	
	refShip.GeraldSails.rey_a2	= 1;	

	refShip.EmblemedSails.normalTex = "sail_Petros_black_red.tga";
	refShip.EmblemedSails.nationFileName = "sail_Petros_black_red.tga";

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

// Standard ship rig
//	refShip.ClosestPoint = 0.295;
//	refShip.BestPoint = 0.9;
//	// KK refShip.RigType = sDet;

// lateen x2 aft and square main
	refShip.ClosestPoint = 0.20;
	refShip.BestPoint = 0.65;
	refShip.RigType = "Xeb";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.5;
		refShip.TurnRate		= 100;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.4;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 15.3;
		refShip.TurnRate		= 45;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// Jackass barque, V-hull, moderate turn circle (WBT2)
// Trades top speed for agility and upwind ability
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 034> is henceforth complete
// on this day and date Sunday Dec 25 2009, 1924h

//-------------------------------------------------------------------------
// Bootschip (Barque4_47) by Thomas the Terror, based on original texture by Petros
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 035> (WBT2T)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Barque4_47";
	refShip.All			= "Barque1";
	refShip.SName			= "Yacht1";
	refShip.id			= refShip.Name;
	refShip.walk			= "Yacht2"; // PB
	refShip.Class			= 7;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS6;
	refShip.MaxCaliber		= 6;
	refShip.Weight			= Tonnes2CWT(250);
	refShip.Capacity		= 1250; // Armada: adjusted for Assassin storyline
	refShip.CannonsQuantity 	= 16;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 	= 48;
	refShip.MinCrew		 	= 10;
	refShip.Price		   	= 27200;
	refShip.HP			= 1000;
	refShip.SP			= 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 88;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.4; //
	refShip.period.2 = 0.6; //
	refShip.period.3 = 0.7; //
	refShip.period.4 = 0.2; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.5; //
	refShip.holland = 0.5; //
	refShip.portugal = 0.5; //
	refShip.pirate = 0.5; //
	refShip.spain = 0.5; //
	refShip.america = 0.5; //
	refShip.sweden = 0.5; //

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;
	refShip.Type.Trade = true;
	refShip.Type.War = true;

	refShip.WaterLine = -0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.2;
	
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.0;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.9;
		refShip.TurnRate		= 45;
		refShip.InertiaAccelerationX	= 2.0;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 8;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2)
// square rigger - does not handle as well upwind, compensate with stays and spanker
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 035> is henceforth complete
// on this day and date Sunday Dec 25 2009, 1419h

//-------------------------------------------------------------------------
// Barque2
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 036> (WBT2T)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Barque2";
	refShip.All				= "Barque1"
	refShip.SName	 		= "Barque1";
	refShip.id				= refShip.Name;
	refShip.Class		   = 7;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS4;
	refShip.MaxCaliber		= 4;
	refShip.Weight			= Tonnes2CWT(350);
	refShip.Capacity		= 1250;
	refShip.CannonsQuantity = 16;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 32;
	refShip.MinCrew		 = 7;
	refShip.Price		   = 16800;
	refShip.HP			  = 1000;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 88;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.7; //
	refShip.period.3 = 0.8; //
	refShip.period.4 = 0.8; //
	refShip.period.5 = 0.9; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.5; //
	refShip.holland = 0.5; //
	refShip.portugal = 0.5; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.5; //
	refShip.america = 0.5; //
	refShip.sweden = 0.5; //

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;
	refShip.Model = "Barque"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = false;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.3;
	
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;	

// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.0;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.9;
		refShip.TurnRate		= 42;
		refShip.InertiaAccelerationX	= 1.0;	refShip.InertiaBrakingX		= 1.0;
		refShip.InertiaAccelerationY	= 6;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 2.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2)
// square rigger - does not handle as well upwind, compensate with stays and spanker
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 036> is henceforth complete
// on this day and date Sunday Dec 25 2009, 1419h

//-------------------------------------------------------------------------
// AOP Barque 1 - Retextured by Seb
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 037> (WBT2T) - "Barque Longue"
//-------------------------------------------------------------------------
	// PS -->
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "BarqueHeavy";
	refShip.id				= refShip.Name;
	refShip.All				= "Barque1";
	refShip.walk			= "BarqueHeavy"; // PB & back84
	refShip.SName	 		= "BarqueHeavy";
	refShip.Class		    = 7;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS4;
	refShip.MaxCaliber		= 4;
	refShip.Weight			= Tonnes2CWT(350);
	refShip.Capacity		= 1500;
	refShip.CannonsQuantity = 16;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	refShip.MaxCrew		 = 32;
	refShip.MinCrew		 = 7;
	refShip.Price		   = 16800;
	refShip.HP			  = 1000;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 88;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.4; //
	refShip.period.2 = 0.7; //
	refShip.period.3 = 0.8; //
	refShip.period.4 = 0.8; //
	refShip.period.5 = 0.9; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.5; //
	refShip.holland = 0.5; //
	refShip.portugal = 0.5; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.5; //
	refShip.america = 0.5; //
	refShip.sweden = 0.5; //

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;
	refShip.Type.Trade = true;
	refShip.Type.War = false;

	refShip.WaterLine = 0.7;
	refShip.SpeedDependWeight = 0.4;
	refShip.SubSeaDependWeight = 0.8;
	
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// has significant amount of stays, but reduced draft, minimal benefit upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.25;
		refShip.TurnRate		= 100;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.4;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 15.6;
		refShip.TurnRate		= 44;
		refShip.InertiaAccelerationX	= 1.0;	refShip.InertiaBrakingX		= 1.0;
		refShip.InertiaAccelerationY	= 6;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 2.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// Review: Vessel configured as:
// Heavy barque, U-hull, reduced turn circle due to lower draft/wider hull (WBT2X)
// Improved ship rig with stays
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 036> is henceforth complete
// on this day and date Sunday Dec 25 2009, 1918h

//-------------------------------------------------------------------------
// Brig2 "Sloop of War 22"
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 038> (WBT2)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Brig2";
	refShip.SName	 		= "Brig1H";
	refShip.All				= "Brig1";
	refShip.id				= refShip.Name;
	refShip.Class		   = 6;
	refShip.Cannon			= CANNON_TYPE_CARRONADE_LBS12;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity		= 1000;
	refShip.CannonsQuantity = 22;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 132;
	refShip.MinCrew		 = 26;
	refShip.Price		   = 76800;
	refShip.HP			  = 2000;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 84;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.2; //
	refShip.period.2 = 0.6; //
	refShip.period.3 = 0.9; //
	refShip.period.4 = 1.0; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.5; //
	refShip.holland = 0.5; //
	refShip.portugal = 0.5; //
	refShip.pirate = 0.2; //
	refShip.spain = 0.5; //
	refShip.america = 0.6; //
	refShip.sweden = 0.5; //

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;
	refShip.Model = "Brig"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = 0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.4;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 90;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.1;
		refShip.TurnRate		= 47;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2) - no penalty to turning circle due to not-so-fine hull shape
// square rigger - does not handle as well upwind, compensate with stays and spanker
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 038> is henceforth complete
// on this day and date Sunday Dec 25 2009, 2009h

//-------------------------------------------------------------------------
//	Colonial Sloop of War Thomas the Terror
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 040> (WBT2)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         	= "US_Brig47";
	refShip.All            	= "Brig1";
	refShip.SName			= "Brig1H";
	refShip.id            	= refShip.Name;
	refShip.Class		   	= 6;
	refShip.Cannon			= CANNON_TYPE_CARRONADE_LBS12;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity		= 1000;
	refShip.CannonsQuantity = 22;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 132;
	refShip.MinCrew		 = 26;
	refShip.Price		   = 76800;
	refShip.HP			  = 2000;
	refShip.SP			  = 200;

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 6;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag2 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.9; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 0.2; //
	refShip.france = 0.2; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.5; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
	refShip.Model = "Brig"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = 0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.4;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY		= 1.0;
	refShip.Height.Knippels.Y		= 15.0;		refShip.Height.Knippels.DY		= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.5;//BB also known as 'Heavy Brig' should be around 11.5(was 13.0)
		refShip.TurnRate		= 105;//BB was 90
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.4;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.1;
		refShip.TurnRate		= 47;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2) - no penalty to turning circle due to not-so-fine hull shape
// square rigger - does not handle as well upwind, compensate with stays and spanker
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 040> is henceforth complete
// on this day and date Sunday Dec 25 2009, 2052h

//-------------------------------------------------------------------------
// Brigantina1
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 041> (WBT2)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Brigantina1";
	refShip.id				= refShip.Name;
	refShip.All				= "Brig1";
	refShip.sname			= "Brig1T";
	refShip.Walk			= "Brig1";
	refShip.Class		   = 6;
	refShip.Cannon			= CANNON_TYPE_CARRONADE_LBS12;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity		= 1000;
	refShip.CannonsQuantity = 22;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 132;
	refShip.MinCrew		 = 26;
	refShip.Price		   = 73800;
	refShip.HP			  = 1750;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 4;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.75; //
	refShip.period.3 = 0.7; //
	refShip.period.4 = 0.5; //
	refShip.period.5 = 0.4; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.5; //
	refShip.holland = 0.5; //
	refShip.portugal = 0.5; //
	refShip.pirate = 0.5; //
	refShip.spain = 0.5; //
	refShip.america = 0.5; //
	refShip.sweden = 0.5; //

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.Model = "Brigantina";

	refShip.WaterLine = 0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.4;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_b2	= 1;

	refShip.ClosestPoint = 0.25;
	refShip.BestPoint = 0.7;
	refShip.RigType = "Btn";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.0;
		refShip.TurnRate		= 100;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.45;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.1;
		refShip.TurnRate		= 47;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// hybrid ship, V-hull, moderate turn circle (WBT2) - no penalty to turning circle due to not-so-fine hull
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 041> is henceforth complete
// on this day and date Sunday Dec 25 2009, 2055h

//-------------------------------------------------------------------------
// Brigantina2
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 041> (WBT2)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Brigantina2";
	refShip.id				= refShip.Name;
	refShip.All				= "Brig1";
	refShip.sname			= "Brig1T";
	refShip.Walk			= "Brig1";
	refShip.Class		   = 6;
	refShip.Cannon			= CANNON_TYPE_CARRONADE_LBS12;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity		= 1000;
	refShip.CannonsQuantity = 22;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 132;
	refShip.MinCrew		 = 26;
	refShip.Price		   = 73800;
	refShip.HP			  = 1750;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 4;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.75; //
	refShip.period.3 = 0.7; //
	refShip.period.4 = 0.5; //
	refShip.period.5 = 0.4; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.5; //
	refShip.holland = 0.5; //
	refShip.portugal = 0.5; //
	refShip.pirate = 0.5; //
	refShip.spain = 0.5; //
	refShip.america = 0.5; //
	refShip.sweden = 0.5; //

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.Model = "Brigantina";

	refShip.WaterLine = 0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.4;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_b2	= 1;

	refShip.ClosestPoint = 0.25;
	refShip.BestPoint = 0.7;
	refShip.RigType = "Btn";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.0;
		refShip.TurnRate		= 100;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.45;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.1;
		refShip.TurnRate		= 47;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// hybrid ship, V-hull, moderate turn circle (WBT2) - no penalty to turning circle due to not-so-fine hull
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 041> is henceforth complete
// on this day and date Sunday Dec 25 2009, 2055h

//-------------------------------------------------------------------------
//      Privateer (PiratBrig50) by Petros / Captain Hawk - 3 masted brig
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 43> (WBT2)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         	= "PiratBrig50";
	refShip.All				= "Brig1";
	refShip.SName			= "SloopWar";
	refShip.id            	= refShip.Name;
	refShip.Class		   	= 6;
	refShip.Cannon			= CANNON_TYPE_CARRONADE_LBS12;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(350);
	refShip.Capacity		= 1000;
	refShip.CannonsQuantity 	= 22;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew			= 144;
	refShip.MinCrew			= 26;
	refShip.Price		   	= 81600;
	refShip.HP			= 2000;
	refShip.SP			= 200;

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 24;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag2 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.2; //
	refShip.period.2 = 0.6; //
	refShip.period.3 = 0.9; //
	refShip.period.4 = 1.0; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.6; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade		= false;
	refShip.Type.War		= true;

	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine		= 0.1;
	refShip.SpeedDependWeight	= 0.3;
	refShip.SubSeaDependWeight	= 0.4;

	refShip.Height.Bombs.Y		= 1.0;	refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;	refShip.Height.Grapes.DY		= 1.0;
	refShip.Height.Knippels.Y		= 15.0;	refShip.Height.Knippels.DY		= 10.0;
	refShip.Height.Balls.Y		= 1.0;	refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;

//	refShip.rigtype = "Bri";
// LDH 03May09

// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 90;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.4;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.1;
		refShip.TurnRate		= 47;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2) - no penalty to turning circle due to not-so-fine hull shape
// square rigger - does not handle as well upwind, compensate with stays and spanker
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 043> is henceforth complete
// on this day and date Sunday Dec 25 2009, 2055h

//----------------------iamthejarha---------------------------------------------------
// Weathered Brig 2, Skin by Rafe Bligh       Code by Muddymonkey/iamthejarha
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 044> (WBT2)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         = "RN_Brig";
	refShip.All            = "Brig1";
	refShip.SName            = "Brig1H";
	refShip.id            = refShip.Name;
	refShip.Class		   = 6;
	refShip.Cannon			= CANNON_TYPE_CARRONADE_LBS12;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity		= 1000;
	refShip.CannonsQuantity = 22;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 132;
	refShip.MinCrew		 = 26;
	refShip.Price		   = 76800;
	refShip.HP			  = 2000;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 6;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.2; //
	refShip.period.2 = 0.7; //
	refShip.period.3 = 0.9; //
	refShip.period.4 = 1.0; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.5; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.5; //
	refShip.america = 0.2; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
	refShip.Model = "Brig"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = 0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.4;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY		= 1.0;
	refShip.Height.Knippels.Y		= 15.0;		refShip.Height.Knippels.DY		= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.5;//BB also known as 'Heavy Brig' should be around 11.5(was 13.0)
		refShip.TurnRate		= 105;//BB was 90
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.4;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.1;
		refShip.TurnRate		= 47;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2) - no penalty to turning circle due to not-so-fine hull shape
// square rigger - does not handle as well upwind, compensate with stays and spanker
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 044> is henceforth complete
// on this day and date Sunday Dec 25 2009, 2055h


//-------------------------------------------------------------------------
// Brig_20_Gun1_181
// Imported from CoAS GoF by Grey Roger
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Brig_20_Gun1_181";
	refShip.id			= refShip.Name;
	refShip.All			= "Shnyava1";
	refShip.Walk			= "Brig_20_Gun1_18";
	refShip.sname			= "Brig1L";
	refShip.Class			= 6;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS6;
	refShip.MaxCaliber		= 6;
	refShip.Weight			= Tonnes2CWT(210);
	refShip.Capacity		= 1350;
	refShip.CannonsQuantity		= 16;	// Yes, it's called "20_Gun", but the model only has 16!
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew			= 90;
	refShip.MinCrew			= 15;
	refShip.Price			= 46000;
	refShip.HP			= 1500;
	refShip.SP			= 200;

	refShip.BigPicTexName = "SHIPS1"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 8;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.4; //
	refShip.period.3 = 0.4; //
	refShip.period.4 = 0.2; //
	refShip.period.5 = 0.1; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.3; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter	 = true;
	refShip.CanBuy		= true;
	refShip.Model = "BrigLight";
	refShip.Type.Trade = true;
	refShip.Type.War = true;

	refShip.WaterLine = 0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.2;

	refShip.Height.Bombs.Y 	 = 1.0; 	 refShip.Height.Bombs.DY	 = 1.0;
	refShip.Height.Grapes.Y	 = 2.0; 	 refShip.Height.Grapes.DY	 = 1.0;
	refShip.Height.Knippels.Y	 = 15.0;	 refShip.Height.Knippels.DY  = 10.0;
	refShip.Height.Balls.Y 	 = 1.0; 	 refShip.Height.Balls.DY	 = 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;


// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.0;
		refShip.TurnRate		= 95;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.5;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.0;
		refShip.TurnRate		= 45;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

//-------------------------------------------------------------------------
// BrigQeen1
// Imported from CoAS GoF by Grey Roger
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "BrigQeen1";
	refShip.All			= "Brig1";
	refShip.SName	 		= "Brig1H";
	refShip.Walk			= "BrigQeen";
	refShip.id				= refShip.Name;
	refShip.Class		   = 6;
	refShip.Cannon			= CANNON_TYPE_CARRONADE_LBS12;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(400);
	refShip.Capacity		= 1500;
	refShip.CannonsQuantity = 22;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 140;
	refShip.MinCrew		 = 30;
	refShip.Price		   = 67500;
	refShip.HP			  = 3500;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 84;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag2 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.3; //
	refShip.period.3 = 0.3; //
	refShip.period.4 = 0.4; //
	refShip.period.5 = 0.4; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.25; //
	refShip.portugal = 0.25; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;
	refShip.Model = "Brigqeen"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = 0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.6;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.2;
		refShip.TurnRate		= 90;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.3;
		refShip.TurnRate		= 47;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

//-------------------------------------------------------------------------
// BrigSW1
// Imported from CoAS GoF by Grey Roger
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "BrigSW1";
	refShip.All			= "Brig1";
	refShip.SName	 		= "Brig1H";
	refShip.Walk			= "BrigQeen";
	refShip.id			= refShip.Name;
	refShip.Class		   	= 6;
	refShip.Cannon			= CANNON_TYPE_CARRONADE_LBS12;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(400);
	refShip.Capacity		= 1500;
	refShip.CannonsQuantity = 22;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 140;
	refShip.MinCrew		 = 30;
	refShip.Price		   = 67500;
	refShip.HP			  = 3500;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 84;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag2 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.3; //
	refShip.period.3 = 0.3; //
	refShip.period.4 = 0.4; //
	refShip.period.5 = 0.4; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.25; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;
	refShip.Model = "Brigqeen"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = 0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.6;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.2;
		refShip.TurnRate		= 90;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.3;
		refShip.TurnRate		= 47;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

//-------------------------------------------------------------------------
// Brig3
// Imported from AoP "Brig1" by Grey Roger
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Brig3";
	refShip.id			= refShip.Name;
	refShip.All			= "Shnyava1";
	refShip.Walk			= "Brig_20_Gun1_18";
	refShip.sname			= "Brig1L";
	refShip.Class			= 6;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS6;
	refShip.MaxCaliber		= 6;
	refShip.Weight			= Tonnes2CWT(210);
	refShip.Capacity		= 1350;
	refShip.CannonsQuantity		= 16;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew			= 90;
	refShip.MinCrew			= 15;
	refShip.Price			= 46000;
	refShip.HP			= 1500;
	refShip.SP			= 200;

	refShip.BigPicTexName = "SHIPS2"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 8;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.4; //
	refShip.period.3 = 0.4; //
	refShip.period.4 = 0.2; //
	refShip.period.5 = 0.1; //
	//Nation
	refShip.england = 0.3; //
	refShip.france = 0.3; //
	refShip.holland = 0.3; //
	refShip.portugal = 0.3; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.3; //
	refShip.america = 0.3; //
	refShip.sweden = 0.3; //

	refShip.CanEncounter	 = true;
	refShip.CanBuy		= true;
	refShip.Model = "BrigLight";
	refShip.Type.Trade = true;
	refShip.Type.War = true;

	refShip.WaterLine = 0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.2;

	refShip.Height.Bombs.Y 	 = 1.0; 	 refShip.Height.Bombs.DY	 = 1.0;
	refShip.Height.Grapes.Y	 = 2.0; 	 refShip.Height.Grapes.DY	 = 1.0;
	refShip.Height.Knippels.Y	 = 15.0;	 refShip.Height.Knippels.DY  = 10.0;
	refShip.Height.Balls.Y 	 = 1.0; 	 refShip.Height.Balls.DY	 = 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;


// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.0;
		refShip.TurnRate		= 95;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.5;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.0;
		refShip.TurnRate		= 45;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

//-------------------------------------------------------------------------
// Older brigantine
// Imported from GoF "Brigantine1" by Grey Roger
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "BrigantineOld";
	refShip.id			= refShip.Name;
	refShip.All			= "Brig1";
	refShip.Walk			= "Brig_20_Gun1_18";
	refShip.sname			= "Brig1T";
	refShip.Class			= 6;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS9;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(350);
	refShip.Capacity		= 1000;
	refShip.CannonsQuantity		= 16;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew			= 100;
	refShip.MinCrew			= 12;
	refShip.Price			= 36000;
	refShip.HP			= 1800;
	refShip.SP			= 200;

	refShip.BigPicTexName = "SHIPS5"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 8;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.8; //
	refShip.period.2 = 0.25; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.5; //
	refShip.holland = 0.5; //
	refShip.portugal = 0.5; //
	refShip.pirate = 0.5; //
	refShip.spain = 0.5; //
	refShip.america = 0.5; //
	refShip.sweden = 0.5; //

	refShip.CanEncounter	 = true;
	refShip.CanBuy		= true;
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refship.WaterLine				= 0.0;
	refship.SpeedDependWeight			= 0.27;
	refship.SubSeaDependWeight			= 0.16;

	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_b2	= 1;


	refShip.ClosestPoint = 0.25;
	refShip.BestPoint = 0.7;
	refShip.RigType = "Btn";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA)
	{
		refShip.SpeedRate		= 10.8;	// Slightly lower performance than standard brigantines
		refShip.TurnRate		= 85;	// Between standard brigantine and CastelF
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.45;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}
	else
	{
		refShip.SpeedRate		= 14.1;
		refShip.TurnRate		= 47;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;
	}

//-------------------------------------------------------------------------
// Tartane
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 046> (WBT3)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Tartane1";
	refShip.id				= "Tartane1";
	refShip.sname			= "Tartane1";
	refShip.Class			= 8;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 200;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 5;
	refShip.MinCrew		 = 2;
	refShip.Price			= 2600;
	refShip.HP			  = 300;
	refShip.SP			  = 100;

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 104;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 0;
	refShip.Cabin = "Cabin_none";
// <-- KK

	//Period
	refShip.period.0 = 0.1; //
	refShip.period.1 = 0.2; //
	refShip.period.2 = 0.3; //
	refShip.period.3 = 0.6; //
	refShip.period.4 = 1.0; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 0.1; //
	refShip.france = 0.1; //
	refShip.holland = 0.1; //
	refShip.portugal = 0.1; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.1; //
	refShip.america = 0.1; //
	refShip.sweden = 0.1; //

	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;
	refShip.Model = "Tartane"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = false;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 7.0;
		refShip.TurnRate		= 135;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 4.5;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 3.0;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 14;	refShip.InertiaBrakingY		= 5;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 3.0;

	}

//	refShip.ClosestPoint = 0.20;
//	refShip.BestPoint = 0.65;
//	refShip.RigType = "Xeb";

// cute lil lateen boat
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 046> is henceforth complete
// on this day and date Sunday Dec 26 2009, 1026h

//-------------------------------------------------------------------------
// Tartane2
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 047> (WBT3)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Tartane2";
	refShip.All				= "Tartane1";
	refShip.id				= refShip.Name
	refShip.sname			= "Tartane1";
	refShip.Class			= 8;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 200;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 5;
	refShip.MinCrew		 = 2;
	refShip.Price			= 2600;

	refShip.HP			  = 300;
	refShip.SP			  = 100;

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 104;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 0;
	refShip.Cabin = "Cabin_none";
// <-- KK

	//Period
	refShip.period.0 = 0.1; //
	refShip.period.1 = 0.2; //
	refShip.period.2 = 0.3; //
	refShip.period.3 = 0.6; //
	refShip.period.4 = 1.0; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 0.1; //
	refShip.france = 0.1; //
	refShip.holland = 0.1; //
	refShip.portugal = 0.1; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.1; //
	refShip.america = 0.1; //
	refShip.sweden = 0.1; //

	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;
	refShip.Model = "Tartane"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = false;

	refShip.EmblemedSails.normalTex = "sail_whole_tan_plain.tga";
	refShip.EmblemedSails.nationFileName = "sail_whole_tan_plain.tga";

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 7.0;
		refShip.TurnRate		= 135;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 4.5;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 3.0;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 14;	refShip.InertiaBrakingY		= 5;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 3.0;

	}

// cute lil lateen boat
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 047> is henceforth complete
// on this day and date Sunday Dec 26 2009, 1026h

//-------------------------------------------------------------------------
// Jolly Mon  (Tartane50)		Petros
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 048> (WBT3)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name		= "Tartane50";
	refShip.All		= "Tartane1";
	refShip.sname		= "Dinghy";
	refShip.id 		= refShip.Name;
	refShip.Class			= 8;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.CannonsQuantity   = 0;
	refShip.MaxCrew		 = 3;
	refShip.MinCrew		 = 1;
	refShip.Weight 		 = Tonnes2CWT(15);
	refShip.Capacity		 = 100;
	refShip.Price			= 2000;
	refShip.HP 		   = 200;
	refShip.SP 		   = 100;

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 104;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 0;
	refShip.Cabin = "Cabin_none";
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.1; //
	refShip.period.1 = 0.2; //
	refShip.period.2 = 0.3; //
	refShip.period.3 = 0.6; //
	refShip.period.4 = 1.0; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 0.1; //
	refShip.france = 0.1; //
	refShip.holland = 0.1; //
	refShip.portugal = 0.1; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.1; //
	refShip.america = 0.1; //
	refShip.sweden = 0.1; //

	refShip.Type.Trade = true;
	refShip.Type.War = false;
	refShip.CanEncounter = true;
	refShip.CanBuy	= true;

	refShip.WaterLine = 0.0;//BB was -0.05
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.3;

	refShip.ClosestPoint = 0.15;
	refShip.BestPoint = 0.6;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 7.0;
		refShip.TurnRate		= 135;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 4.5;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 3.0;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 14;	refShip.InertiaBrakingY		= 5;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 3.0;

	}

// cute lil lateen boat
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 048> is henceforth complete
// on this day and date Sunday Dec 26 2009, 1026h

//-------------------------------------------------------------------------
// Gunboat  --  Skeleton Bob & Fred Bob  --  05/16/2004
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 049> (WBT3)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name		= "Gunboat";
	refShip.All		= "Tartane1";
	refShip.sname		= "Gunboat";
	refShip.rigtype = "tar";
	refShip.ClosestPoint = 0.15;
	refShip.BestPoint = 0.6;
	refShip.id 		= refShip.Name; // PSX
	refShip.Class			= 8;
	refShip.Cannon		 = CANNON_TYPE_CARRONADE_LBS12;
	refShip.MaxCaliber		= 6;
	refShip.Weight 		 = Tonnes2CWT(15);
	if(SHIPS_WEIGHT) refShip.Capacity		 =  100;
	else             refShip.Capacity		 = 4000;	// PB: Just enough to allow installing Navarone Carronades
	refShip.SupplyScalar = 1.0;
	refShip.CannonsQuantity = 5;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 1;
	refShip.Cannons.Borts.cannonb.qty = 0;
	// NK <--
	refShip.MaxCrew	 = 20; // PB: was 10
	refShip.MinCrew	 = 7; // PB: was 3
	refShip.Price			= 7000;//BB was 9000

	refShip.HP 		   = 250;
	refShip.SP 		   = 100;

	//Period
	refShip.period.0 = 0.1; //
	refShip.period.1 = 0.2; //
	refShip.period.2 = 0.3; //
	refShip.period.3 = 0.6; //
	refShip.period.4 = 1.0; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 0.1; //
	refShip.france = 0.1; //
	refShip.holland = 0.1; //
	refShip.portugal = 0.1; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.1; //
	refShip.america = 0.1; //
	refShip.sweden = 0.1; //

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.3;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 104;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 0;
	refShip.Cabin = "Cabin_none";
// <-- KK

	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	// LDH changed 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;
	if(USE_REAL_CANNONS)
	{
		refShip.Cannons.Borts.cannonf.FireZone	= Degree2Radian(10.0);
		refShip.Cannons.Borts.cannonf.FireDir	 = Degree2Radian(0.0);
		refShip.Cannons.Borts.cannonf.FireAngMin	= Degree2Radian(-2.5) * FIRE_ANGLE_SCALAR_H;
		refShip.Cannons.Borts.cannonf.FireAngMax	= Degree2Radian(5.0) * FIRE_ANGLE_SCALAR_H;

		refShip.Cannons.Borts.cannonr.FireZone	= Degree2Radian(90.0);
		refShip.Cannons.Borts.cannonr.FireDir	 = Degree2Radian(90.0);
		refShip.Cannons.Borts.cannonr.FireAngMin	= Degree2Radian(-5.0) * FIRE_ANGLE_SCALAR_H;
		refShip.Cannons.Borts.cannonr.FireAngMax	= Degree2Radian(10.0) * FIRE_ANGLE_SCALAR_H;

		refShip.Cannons.Borts.cannonb.FireZone	= Degree2Radian(90.0);
		refShip.Cannons.Borts.cannonb.FireDir	 = Degree2Radian(180.0);
		refShip.Cannons.Borts.cannonb.FireAngMin	= Degree2Radian(-5.0) * FIRE_ANGLE_SCALAR_H;
		refShip.Cannons.Borts.cannonb.FireAngMax	= Degree2Radian(10.0) * FIRE_ANGLE_SCALAR_H;

		refShip.Cannons.Borts.cannonl.FireZone	= Degree2Radian(90.0);
		refShip.Cannons.Borts.cannonl.FireDir	 = Degree2Radian(270.0);
		refShip.Cannons.Borts.cannonl.FireAngMin	= Degree2Radian(-5.0) * FIRE_ANGLE_SCALAR_H;
		refShip.Cannons.Borts.cannonl.FireAngMax	= Degree2Radian(10.0) * FIRE_ANGLE_SCALAR_H;
	}

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 7.0;
		refShip.TurnRate		= 135;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 4.5;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 3.0;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 14;	refShip.InertiaBrakingY		= 5;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 3.0;

	}

// cute lil lateen boat
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 049> is henceforth complete
// on this day and date Sunday Dec 26 2009, 1030h

//-------------------------------------------------------------------------
// War Tartane from AOP added by MAXIMUS
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 050> (WBT3)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "TartaneWar";
	refShip.All				= "Tartane1";
	refShip.sname			= "TartaneWar";
	refShip.walk			= "";
	refShip.id			    = refShip.Name;
	refShip.Class			= 8;
	refShip.Cannon			= CANNON_TYPE_CARRONADE_LBS12;
	refShip.MaxCaliber		= 4;
	refShip.Weight			= Tonnes2CWT(40);//BB compared to other Tartanes, 100 seems too large a diference?(was 100)
	refShip.Capacity		= 150;
	refShip.CannonsQuantity = 8;
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;
	refShip.MaxCrew			= 16;
	refShip.MinCrew			= 5;
	refShip.Price			= 9600;//BB was 15600

	refShip.HP				= 500;
	refShip.SP				= 100;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.3;

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 104;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 0;
	refShip.Cabin = "Cabin_none";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.1; //
	refShip.period.1 = 0.4; //
	refShip.period.2 = 0.6; //
	refShip.period.3 = 1.0; //
	refShip.period.4 = 1.0; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 0.1; //
	refShip.france = 0.1; //
	refShip.holland = 0.1; //
	refShip.portugal = 0.1; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.1; //
	refShip.america = 0.1; //
	refShip.sweden = 0.1; //

	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;
	refShip.Type.Trade = false;
	refShip.Type.War = true;

//	refShip.InertiaAccelerationX	= 3.0;	refShip.InertiaBrakingX		= 2.0;
//	refShip.InertiaAccelerationY	= 14;	refShip.InertiaBrakingY		= 5;
//	refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

	if(USE_REAL_CANNONS)
	{
		refShip.Cannons.Borts.cannonf.FireZone	= Degree2Radian(10.0);
		refShip.Cannons.Borts.cannonf.FireDir	 = Degree2Radian(0.0);
		refShip.Cannons.Borts.cannonf.FireAngMin	= Degree2Radian(-2.5) * FIRE_ANGLE_SCALAR_H;
		refShip.Cannons.Borts.cannonf.FireAngMax	= Degree2Radian(5.0) * FIRE_ANGLE_SCALAR_H;

		refShip.Cannons.Borts.cannonr.FireZone	= Degree2Radian(90.0);
		refShip.Cannons.Borts.cannonr.FireDir	 = Degree2Radian(90.0);
		refShip.Cannons.Borts.cannonr.FireAngMin	= Degree2Radian(-5.0) * FIRE_ANGLE_SCALAR_H;
		refShip.Cannons.Borts.cannonr.FireAngMax	= Degree2Radian(10.0) * FIRE_ANGLE_SCALAR_H;

		refShip.Cannons.Borts.cannonb.FireZone	= Degree2Radian(90.0);
		refShip.Cannons.Borts.cannonb.FireDir	 = Degree2Radian(180.0);
		refShip.Cannons.Borts.cannonb.FireAngMin	= Degree2Radian(-5.0) * FIRE_ANGLE_SCALAR_H;
		refShip.Cannons.Borts.cannonb.FireAngMax	= Degree2Radian(10.0) * FIRE_ANGLE_SCALAR_H;

		refShip.Cannons.Borts.cannonl.FireZone	= Degree2Radian(90.0);
		refShip.Cannons.Borts.cannonl.FireDir	 = Degree2Radian(270.0);
		refShip.Cannons.Borts.cannonl.FireAngMin	= Degree2Radian(-5.0) * FIRE_ANGLE_SCALAR_H;
		refShip.Cannons.Borts.cannonl.FireAngMax	= Degree2Radian(10.0) * FIRE_ANGLE_SCALAR_H;
	}

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 9.0;//BB was 7.0
		refShip.TurnRate		= 135;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 4.5;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 3.0;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 14;	refShip.InertiaBrakingY		= 5;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 3.0;

	}

// cute lil lateen boat
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 050> is henceforth complete
// on this day and date Sunday Dec 26 2009, 1030h

//-------------------------------------------------------------------------
// Galeoth1
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 051> (WBT2T)  - "Espadina" gunship
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Galeoth1";
	if(iRealismMode>0)	refShip.SName = "Galeoth1_real";
	else				refShip.SName = "Galeoth1";
	refShip.id				= refShip.Name;
	refShip.Class		   = 7;
	refShip.Cannon			= CANNON_TYPE_CARRONADE_LBS18;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(150);
	refShip.Capacity		= 700;
	refShip.CannonsQuantity = 16;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 72;
	refShip.MinCrew		 = 14;
	refShip.Price		   = 41800;//BB was 43800
	refShip.HP			  = 1250;
	refShip.SP			  = 200;

	refShip.BigPicTexName = "SHIPS1"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 0;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.1; //
	refShip.period.1 = 1.0; //
	refShip.period.2 = 0.9; //
	refShip.period.3 = 0.8; //
	refShip.period.4 = 0.6; //
	refShip.period.5 = 0.3; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.5; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.5; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;
	refShip.Model = "Gunship"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = -0.5;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;
	
	refShip.GeraldSails.rey_b2	= 1;

// lateen x2 aft and square main
	refShip.ClosestPoint = 0.20;
	refShip.BestPoint = 0.65;
	refShip.RigType = "Sch";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 105;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.2;
		refShip.TurnRate		= 45;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 9;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 3.0;

	}

// Hybrid rig ship - square main, aft F&A. Short hull, large rudder. Maneuverability at the expense of top speed.
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 051> is henceforth complete
// on this day and date Sunday Dec 26 2009, 1044h

//-------------------------------------------------------------------------
// Galeoth2
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 052> (WBT2T) - "Espadina" gunship
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Galeoth2";
	if(iRealismMode>0)	refShip.SName = "Galeoth1_real";
	else				refShip.SName = "Galeoth1";
	refShip.All				= "Galeoth1";
	refShip.id				= refShip.Name;
	refShip.Class		   = 7;
	refShip.Cannon			= CANNON_TYPE_CARRONADE_LBS18;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(150);
	refShip.Capacity		= 700;
	refShip.CannonsQuantity = 16;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 72;
	refShip.MinCrew		 = 14;
	refShip.Price		   = 41800;
	refShip.HP			  = 1250;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 0;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.1; //
	refShip.period.1 = 1.0; //
	refShip.period.2 = 0.9; //
	refShip.period.3 = 0.8; //
	refShip.period.4 = 0.6; //
	refShip.period.5 = 0.3; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.5; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.5; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;
	refShip.Model = "Gunship"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = -0.5;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.8;

	refShip.GeraldSails.rey_b2	= 1;	

// lateen x2 aft and square main
	refShip.ClosestPoint = 0.20;
	refShip.BestPoint = 0.65;
	refShip.RigType = "Sch";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 105;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.2;
		refShip.TurnRate		= 45;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 9;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 3.0;

	}

// Hybrid rig ship - square main, aft F&A. Short hull, large rudder. Maneuverability at the expense of top speed.
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 051> is henceforth complete
// on this day and date Sunday Dec 26 2009, 1044h

//-------------------------------------------------------------------------
// Sloop1
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 054> (WBT3H)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Sloop1";
	refShip.SName	 		= "Sloop1";
	refShip.id				= refShip.Name;
	refShip.Class		   = 7;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS6;
	refShip.MaxCaliber		= 6;
	refShip.Weight			= Tonnes2CWT(170);
	refShip.Capacity		= 700;
	refShip.CannonsQuantity = 16;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 48;
	refShip.MinCrew		 = 12;//BB was 10(sloops hard to sail)
	refShip.Price		   = 27200;
	refShip.HP			  = 1000;
	refShip.SP			  = 200;

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 98;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
// <- KK

	//Period
	refShip.period.0 = 0.5; //
	refShip.period.1 = 1.0; //
	refShip.period.2 = 0.9; //
	refShip.period.3 = 0.9; //
	refShip.period.4 = 0.8; //
	refShip.period.5 = 0.7; //
	//Nation
	refShip.england = 0.4; //
	refShip.france = 0.4; //
	refShip.holland = 0.4; //
	refShip.portugal = 0.4; //
	refShip.pirate = 0.4; //
	refShip.spain = 0.4; //
	refShip.america = 0.4; //
	refShip.sweden = 0.4; //

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;
	refShip.Model = "Sloop"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = true;

	refShip.WaterLine = 0.0;//BB was 0.1 - lower in the water now?
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.5;

	// LDH changed 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.1;//BB was 10.0 - sloops were fast transport craft
		refShip.TurnRate		= 95;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 15.3;
		refShip.TurnRate		= 55;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 3.0;

	}

// cute lil ship - loves sailing against the wind. Very agile but slower than a square rigger downwind.
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 054> is henceforth complete
// on this day and date Sunday Dec 26 2009, 1030h

//-------------------------------------------------------------------------
// FR_Sloop by Seb
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 057> (WBT3H)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "FR_Sloop";
	refShip.id				= refShip.Name;
	refShip.All				= "Sloop1";
	refShip.SName			= "Sloop1N";
	refShip.Walk			= "Sloop3"; // PB & back84
	refShip.Class		   = 7;
	refShip.Cannon			= CANNON_TYPE_CARRONADE_LBS18;
	refShip.MaxCaliber		= 6;
	refShip.Weight			= Tonnes2CWT(200);
	refShip.Capacity		= 800;
	refShip.CannonsQuantity = 14;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 72;
	refShip.MinCrew		 = 14;
	refShip.Price		   = 46800;
	refShip.HP			  = 1500;
	refShip.SP			  = 200;

	refShip.BigPicTexName = "SHIPS1"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 98;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast1.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag2 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.5; //
	refShip.period.1 = 1.0; //
	refShip.period.2 = 0.9; //
	refShip.period.3 = 0.9; //
	refShip.period.4 = 0.8; //
	refShip.period.5 = 0.7; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.5; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //
// <-- KK

	refShip.Model = "Sloop3";
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = 0.0;//BB was 0.1
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.5;
	
	refShip.GeraldSails.rey_a2	= 1;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.5;//BB was 10.0 - sloops were fast transport craft
		refShip.TurnRate		= 95;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 15.3;
		refShip.TurnRate		= 55;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 3.0;

	}

// cute lil ship - loves sailing against the wind. Very agile but slower than a square rigger downwind.
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 057> is henceforth complete
// on this day and date Sunday Dec 26 2009, 1256h

//-------------------------------------------------------------------------
// Sloop2
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 056> (WBT3H)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Sloop2";
	refShip.All				= "Sloop1";
	refShip.SName	 		= "Sloop1";
	refShip.id				= refShip.Name;
	refShip.Class		   = 7;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS6;
	refShip.MaxCaliber		= 6;
	refShip.Weight			= Tonnes2CWT(170);
	refShip.Capacity		= 700;
	refShip.CannonsQuantity = 16;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 48;
	refShip.MinCrew		 = 12;//BB was 10(sloops hard to sail)
	refShip.Price		   = 27200;
	refShip.HP			  = 1000;
	refShip.SP			  = 200;

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 98;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.5; //
	refShip.period.1 = 1.0; //
	refShip.period.2 = 0.9; //
	refShip.period.3 = 0.9; //
	refShip.period.4 = 0.8; //
	refShip.period.5 = 0.7; //
	//Nation
	refShip.england = 0.4; //
	refShip.france = 0.4; //
	refShip.holland = 0.4; //
	refShip.portugal = 0.4; //
	refShip.pirate = 0.4; //
	refShip.spain = 0.4; //
	refShip.america = 0.4; //
	refShip.sweden = 0.4; //

	refShip.Model = "Sloop"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = true;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = 0.0;//BB was 0.1
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.5;

	// LDH changed 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.3;//BB was 10.0 - sloops were fast transport craft
		refShip.TurnRate		= 95;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 15.3;
		refShip.TurnRate		= 55;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 3.0;

	}

// cute lil ship - loves sailing against the wind. Very agile but slower than a square rigger downwind.
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 056> is henceforth complete
// on this day and date Sunday Dec 26 2009, 1030h

//---------------------------------------------------------------------------
// Sloop 4 - new texture for "FR_Sloop" model imported from GoF by Grey Roger
//---------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Sloop4";
	refShip.id			= refShip.Name;
	refShip.All			= "Sloop4";
	refShip.SName			= "Sloop1";
	refShip.Walk			= "Sloop3"; // PB & back84
	refShip.Class		   = 7;
	refShip.Cannon			= CANNON_TYPE_CARRONADE_LBS12;
	refShip.MaxCaliber		= 6;
	refShip.Weight			= Tonnes2CWT(200);
	refShip.Capacity		= 800;
	refShip.CannonsQuantity = 14;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 72;
	refShip.MinCrew		 = 14;
	refShip.Price		   = 31000;
	refShip.HP			  = 1500;
	refShip.SP			  = 200;

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 98;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast1.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag2 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.5; //
	refShip.period.1 = 1.0; //
	refShip.period.2 = 0.9; //
	refShip.period.3 = 0.9; //
	refShip.period.4 = 0.8; //
	refShip.period.5 = 0.7; //
	//Nation
	refShip.england = 0.2; //
	refShip.france = 0.2; //
	refShip.holland = 0.2; //
	refShip.portugal = 0.2; //
	refShip.pirate = 0.2; //
	refShip.spain = 0.2; //
	refShip.america = 0.2; //
	refShip.sweden = 0.2; //
// <-- KK

	refShip.Model = "Sloop3";
	refShip.Type.Trade = true;
	refShip.Type.War = true;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = 0.0;//BB was 0.1
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.5;
	
	refShip.GeraldSails.rey_a2	= 1;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.5;//BB was 10.0 - sloops were fast transport craft
		refShip.TurnRate		= 95;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 15.3;
		refShip.TurnRate		= 55;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 3.0;

	}

// cute lil ship - loves sailing against the wind. Very agile but slower than a square rigger downwind.
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 057> is henceforth complete
// on this day and date Sunday Dec 26 2009, 1256h

//-------------------------------------------------------------------------
// Bermuda Sloop By: Captain Augast, July 2006
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 058> (WBT3H)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name		= "SloopBermuda";
	refShip.SName		= "SloopBermuda";
	refShip.id		= refShip.Name;
	refShip.Class		= 7;
	refShip.Walk		= "SloopBermuda";
	refShip.All			= "Sloop1";
	refShip.Cannon		= CANNON_TYPE_LONG_LBS6;
	refShip.MaxCaliber	= 6;
	refShip.Weight		= Tonnes2CWT(250);//BB ? weight seems large compared to normal sloop?(was 390)
	refShip.Capacity	= 1100;//BB these were trade ships too(was 500). Increased to better match weight and reduced guns
	refShip.CannonsQuantity	= 10;

	refShip.Cannons.Borts.cannonf.qty = 1;
	refShip.Cannons.Borts.cannonb.qty = 1;

	refShip.MaxCrew		= 38;//BB crew seem too few for size(see weight), was 30
	refShip.MinCrew		= 12;//BB was 6(sloops were hard to sail)
	refShip.Price		= 29000;//BB was 20000
	refShip.HP		= 1100;//BB was 1000(used cedar wood for greater strength)
	refShip.SP		= 200;
	refShip.Jetty			= false; // PB

	refShip.RigType		 = "Slo";
	refship.WaterLine	 = 0.1;//BB was 0.0
	refship.SpeedDependWeight  = 0.2;
	refship.SubSeaDependWeight = 0.3;
	refship.TurnDependWeight   = 0.2;

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 98;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.8; //
	refShip.period.3 = 1.0; //
	refShip.period.4 = 0.8; //
	refShip.period.5 = 0.8; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.5; //
	refShip.holland = 0.5; //
	refShip.portugal = 0.5; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.5; //
	refShip.america = 0.5; //
	refShip.sweden = 0.5; //

	refShip.Type.Trade	= true;
	refShip.Type.War	= true;

	refShip.Height.Bombs.Y		= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y		= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_b2	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.5;//BB was 13.5(a bit too fast)
		refShip.TurnRate		= 95;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 15.5;
		refShip.TurnRate		= 43;
		refship.InertiaAccelerationX	= 1.0;	refship.InertiaBrakingX		= 2.0;
		refship.InertiaAccelerationY	= 15;	refship.InertiaBrakingY		= 8;
		refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 3.0;

	}

// cute lil ship - loves sailing against the wind. Very agile but slower than a square rigger downwind.
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 058> is henceforth complete
// on this day and date Sunday Dec 26 2009, 1257h

//-------------------------------------------------------------------------
//  Cutter by Captain Hawk
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 059> (WBT3H)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Cutter1";
	refShip.All				= "Sloop1"
	refShip.id				= refShip.Name;
	refShip.SName			= "Cutter1N";
	refShip.Class			= 7;
	refShip.Walk			= "Cutter1";
	refShip.Cannon			= CANNON_TYPE_CARRONADE_LBS12;
	refShip.MaxCaliber		= 6;
	refShip.Weight			= Tonnes2CWT(100);
	refShip.Capacity		= 300;
	refShip.CannonsQuantity = 12;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew	  = 54;
	refShip.MinCrew	  = 11;
	refShip.Price			= 39600;
	refShip.HP 		   = 1500;
	refShip.SP 		   = 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 98;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag2 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.1; //
	refShip.period.1 = 0.6; //
	refShip.period.2 = 0.8; //
	refShip.period.3 = 0.9; //
	refShip.period.4 = 0.9; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.5; //
	refShip.holland = 0.5; //
	refShip.portugal = 0.5; //
	refShip.pirate = 0.4; //
	refShip.spain = 0.5; //
	refShip.america = 0.3; //
	refShip.sweden = 0.3; //


	refShip.Model = "Cutter"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.RigType		 = "Slo";
	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.3;

	refShip.Height.Bombs.Y 		 = 1.0;  refShip.Height.Bombs.DY	 = 0.5;
	refShip.Height.Grapes.Y		 = 2.0;  refShip.Height.Grapes.DY	 = 1.0;
	refShip.Height.Knippels.Y		 = 10.0; refShip.Height.Knippels.DY  = 8.0;
	refShip.Height.Balls.Y 		 = 1.0;  refShip.Height.Balls.DY	 = 0.5;


	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.2;//BB was 11.0
		refShip.TurnRate		= 95;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 15.0;
		refShip.TurnRate		= 70;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 3.0;

	}

// cute lil ship - loves sailing against the wind. Very agile but slower than a square rigger downwind.
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 059> is henceforth complete
// on this day and date Sunday Dec 26 2009, 1256h

//-------------------------------------------------------------------------
//  British Cutter by Thomas the Terror
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 069> (WBT3H)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name	 = "Cutter2";
	refShip.All	  = "Sloop1";
	refShip.id 	 = refShip.Name;
	refShip.SName	 = "Cutter1N";
	refShip.Class	 = 8;
	refShip.Walk		 = "Cutter1";
	refShip.Cannon		 = CANNON_TYPE_CARRONADE_LBS12;
	refShip.MaxCaliber		= 6;
	refShip.Weight 		 = Tonnes2CWT(100);
	refShip.Capacity		 = 300;
	refShip.CannonsQuantity = 12;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew	  = 54;
	refShip.MinCrew	  = 11;
	refShip.Price			= 39600;
	refShip.HP 		   = 1500;
	refShip.SP 		   = 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 98;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag2 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.1; //
	refShip.period.1 = 0.6; //
	refShip.period.2 = 0.8; //
	refShip.period.3 = 0.9; //
	refShip.period.4 = 0.9; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.5; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.5; //
	refShip.america = 0.4; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
	refShip.Model = "Cutter"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.RigType		 = "Slo";
	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.3;

	refShip.Height.Bombs.Y 		 = 1.0;  refShip.Height.Bombs.DY	 = 0.5;
	refShip.Height.Grapes.Y		 = 2.0;  refShip.Height.Grapes.DY	 = 1.0;
	refShip.Height.Knippels.Y		 = 10.0; refShip.Height.Knippels.DY  = 8.0;
	refShip.Height.Balls.Y 		 = 1.0;  refShip.Height.Balls.DY	 = 0.5;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.1;//BB was 11.0
		refShip.TurnRate		= 95;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 15.0;
		refShip.TurnRate		= 70;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 3.0;

	}

// cute lil ship - loves sailing against the wind. Very agile but slower than a square rigger downwind.
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 069> is henceforth complete
// on this day and date Sunday Dec 26 2009, 1256h

//-------------------------------------------------------------------------
// Ketch  //Petros
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 071> (WBT3H)
//-------------------------------------------------------------------------
	// PS -->
	makeref(refShip,ShipsTypes[n]);
	n++;
	// PS <-- makeref(refShip,ShipsTypes[SHIP_SLOOP_FRANCE]);
	refShip.Name			= "Ketch";
	refShip.All 			= "Sloop1";
	refShip.SName 			= "Ketch";
	refShip.id			= refShip.Name; // PS
	refShip.Class		   	= 7;
	refShip.Walk			= "Ketch";
	refShip.Cannon			= CANNON_TYPE_LONG_LBS6;
	refShip.MaxCaliber		= 6;
	refShip.Weight			= Tonnes2CWT(170);
	refShip.Capacity		= 700;
	refShip.CannonsQuantity 	= 16;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 48;
	refShip.MinCrew		 = 12;
	refShip.Price		   = 27200;//BB was 16000
	refShip.HP			  = 1000;
	refShip.SP			  = 200;
	// KK refShip.AbordageLocation = "BOARDING_SLOOP";

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 98;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.6; //
	refShip.period.3 = 0.8; //
	refShip.period.4 = 0.7; //
	refShip.period.5 = 0.4; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.5; //
	refShip.holland = 0.5; //
	refShip.portugal = 0.5; //
	refShip.pirate = 0.5; //
	refShip.spain = 0.5; //
	refShip.america = 0.5; //
	refShip.sweden = 0.5; //

	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;
	refShip.Type.Trade		= true;
	refShip.Type.War		= true;

	refShip.ClosestPoint = 0.15;
	refShip.BestPoint = 0.625;
	// KK refShip.RigType = sDet;
	refShip.WaterLine = 0.2;                 //  lowered waterline slightly HP
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.5;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.5;
		refShip.TurnRate		= 95;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 15.0;
		refShip.TurnRate		= 55;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 3.0;

	}

// cute lil ship - loves sailing against the wind. Very agile but slower than a square rigger downwind.
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 071> is henceforth complete
// on this day and date Sunday Dec 26 2009, 1256h

//-------------------------------------------------------------------------
// Lugger1, By CatalinaThePirate, 01/03/2004
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 060> (WBT3H)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Lugger1";
	refShip.SName			= "Lugger1";
	refShip.id				= refShip.Name;
	refShip.Class		   = 7;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS4;
	refShip.MaxCaliber		= 4;
	refShip.Weight			= Tonnes2CWT(120);
	refShip.Capacity		= 800;
	refShip.CannonsQuantity = 12;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 24;
	refShip.MinCrew		 = 5;
	refShip.Price		   = 12000;
	refShip.HP			  = 600;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 120;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refship.Flags.Mast4.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 1.0; //
	refShip.period.1 = 1.0; //
	refShip.period.2 = 1.0; //
	refShip.period.3 = 1.0; //
	refShip.period.4 = 1.0; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.5; //
	refShip.holland = 0.5; //
	refShip.portugal = 0.5; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.5; //
	refShip.america = 0.4; //
	refShip.sweden = 0.4; //

	refShip.Model = "Lugger"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.3;

//	refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
//	refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
//	refShip.InertiaAccelerationZ	= 6.0;	refShip.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
	refShip.InertiaAccelerationY	= 3;	refShip.InertiaBrakingY		= 0.5;
	refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;

	refShip.TurnRate		= 90;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.5;
		refShip.TurnRate		= 90;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 6.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// cute lil ship with a lug rig. good all rounder
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 060> is henceforth complete
// on this day and date Thursday Dec 31 2009, 2055h
// BB general tweak to all Luggers after starting Lugger1 adjusted 'down'

//-------------------------------------------------------------------------
// Lugger2
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 061> (WBT3H)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Lugger2";
	refShip.All				= "Lugger1";
	refShip.SName			= "Lugger1";
	refShip.id				= refShip.Name;
	refShip.Class		   = 7;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS4;
	refShip.MaxCaliber		= 4;
	refShip.Weight			= Tonnes2CWT(120);
	refShip.Capacity		= 800;//BB was 1000
	refShip.CannonsQuantity = 12;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 24;
	refShip.MinCrew		 = 5;
	refShip.Price		   = 12000;
	refShip.HP			  = 600;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 120;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refship.Flags.Mast4.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 1.0; //
	refShip.period.1 = 1.0; //
	refShip.period.2 = 1.0; //
	refShip.period.3 = 1.0; //
	refShip.period.4 = 1.0; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.5; //
	refShip.holland = 0.5; //
	refShip.portugal = 0.5; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.5; //
	refShip.america = 0.4; //
	refShip.sweden = 0.4; //

	refShip.Model = "Lugger"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.3;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.5;
		refShip.TurnRate		= 90;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 6.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// cute lil ship with a lug rig. good all rounder
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 061> is henceforth complete
// on this day and date Thursday Dec 31 2009, 2055h

//-------------------------------------------------------------------------
// Lugger CT
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 062> (WBT3H)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name		= "LuggerCT";
	refShip.All		= "Lugger1";
	refShip.sname		= "Lugger1";
	refShip.noNatStatMod = true;
	refShip.id 		= refShip.Name;
	refShip.Class			= 7;
	refShip.Cannon		 = CANNON_TYPE_LONG_LBS4;
	refShip.MaxCaliber		= 4;
	refShip.Weight 		 = Tonnes2CWT(120);
	refShip.Capacity		 = 800;
	refShip.CannonsQuantity = 12;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew	 = 24;
	refShip.MinCrew	 = 5;
	refShip.Price			= 12000;
	refShip.HP 		   = 600;
	refShip.SP 		   = 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 120;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refship.Flags.Mast4.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 1.0; //
	refShip.period.1 = 1.0; //
	refShip.period.2 = 1.0; //
	refShip.period.3 = 1.0; //
	refShip.period.4 = 1.0; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.5; //
	refShip.holland = 0.5; //
	refShip.portugal = 0.5; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.5; //
	refShip.america = 0.4; //
	refShip.sweden = 0.4; //

	refShip.Model = "Lugger"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.3;

	refShip.EmblemedSails.normalTex = "sail_whole_tan_plain.tga";
	refShip.EmblemedSails.nationFileName = "sail_whole_tan_plain.tga";

	// LDH added 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.5;
		refShip.TurnRate		= 90;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 6.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// cute lil ship with a lug rig. good all rounder
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 062> is henceforth complete
// on this day and date Thursday Dec 31 2009, 2055h

//------------------------------------------------------------------------------------
//      LuggerVML - From "Sea Legend is Back" Add-on - Stats by Jack Davidson
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 063> (WBT3H)  - Heavy variant!
//------------------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "LuggerVML";
	refShip.All				= "Lugger1";
	refShip.SName			= "LuggerHvy";
	refShip.id				= refShip.Name;
	refShip.Class			= 7;
	refShip.Walk			= "LuggerVML";
	refShip.Cannon			= CANNON_TYPE_LONG_LBS4;
	refShip.MaxCaliber		= 4;
	refShip.Weight			= Tonnes2CWT(150);
	refShip.Capacity		= 1100;//BB was 1000
	refShip.CannonsQuantity = 12;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew			= 28;//BB was 24
	refShip.MinCrew			= 5;
	refShip.Price			= 15300;//BB was 12800
	refShip.HP				= 900;
	refShip.SP				= 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 120;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 1.0; //
	refShip.period.1 = 1.0; //
	refShip.period.2 = 1.0; //
	refShip.period.3 = 1.0; //
	refShip.period.4 = 1.0; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.5; //
	refShip.holland = 0.5; //
	refShip.portugal = 0.5; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.5; //
	refShip.america = 0.4; //
	refShip.sweden = 0.4; //

	refShip.Type.Trade = true;
	refShip.Type.War = false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.3;

	refShip.EmblemedSails.normalTex = "sail_whole_tan_plain.tga";
	refShip.EmblemedSails.nationFileName = "sail_whole_tan_plain.tga";

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.5;
		refShip.TurnRate		= 85;//BB was 80
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.4;
		refShip.TurnRate		= 51;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 6.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// cute lil ship with a lug rig. good all rounder - heavy hull
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 063> is henceforth complete
// on this day and date Thursday Dec 31 2009, 2055h

//-------------------------------------------------------------------------
// Lugger3 by Seb, Model updated by Pgargon, ported by Armada
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 066> (WBT3H)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Lugger3";
	refShip.id				= refShip.Name;
	refShip.All				= "Lugger1";
	refShip.SName			= "LuggerAOP";
	refShip.Walk			= "Lugger3"; // PB & back84
	refShip.Class		   = 7;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS4;
	refShip.MaxCaliber		= 4;
	refShip.Weight			= Tonnes2CWT(130);
	refShip.Capacity		= 1150;//BB was 1000
	refShip.CannonsQuantity = 8;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;
	// NK <--
	refShip.MaxCrew		 = 26;//BB was 24
	refShip.MinCrew		 = 5;
	refShip.Price		   = 14300;//BB was 12000
	refShip.HP			  = 700;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 120;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 1.0; //
	refShip.period.1 = 1.0; //
	refShip.period.2 = 1.0; //
	refShip.period.3 = 1.0; //
	refShip.period.4 = 1.0; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.5; //
	refShip.holland = 0.5; //
	refShip.portugal = 0.5; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.5; //
	refShip.america = 0.4; //
	refShip.sweden = 0.4; //

	refShip.Type.Trade = true;
	refShip.Type.War = false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = -0.5;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.3;

	refShip.EmblemedSails.normalTex = "sail_whole_tan_plain.tga";
	refShip.EmblemedSails.nationFileName = "sail_whole_tan_plain.tga";

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.8;//BB was 12.0
		refShip.TurnRate		= 90;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 6.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// cute lil ship with a lug rig. good all rounder
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 066> is henceforth complete
// on this day and date Thursday Dec 31 2009, 2055h

//----------------------Muddymonkey---------------------------------------------------
// Weathered Lugger, Skin by Rafe Bligh       Code by Muddymonkey
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 067> (WBT3H)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         = "Lugger4";
	refShip.All            = "Lugger1";
	refShip.SName            = "Lugger1";
	refShip.id            = refShip.Name;
	refShip.Class		   = 7;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS4;
	refShip.MaxCaliber		= 4;
	refShip.Weight			= Tonnes2CWT(120);
	refShip.Capacity		= 950;//BB was 1000
	refShip.CannonsQuantity = 12;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 26;//BB was 24
	refShip.MinCrew		 = 5;
	refShip.Price		   = 14600;//BB was 12000
	refShip.HP			  = 600;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 120;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refship.Flags.Mast4.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 1.0; //
	refShip.period.1 = 1.0; //
	refShip.period.2 = 1.0; //
	refShip.period.3 = 1.0; //
	refShip.period.4 = 1.0; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.5; //
	refShip.holland = 0.5; //
	refShip.portugal = 0.5; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.5; //
	refShip.america = 0.4; //
	refShip.sweden = 0.4; //

	refShip.Model = "Lugger"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.3;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.1;//BB was 12.0
		refShip.TurnRate		= 90;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 6.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// cute lil ship with a lug rig. good all rounder
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 067> is henceforth complete
// on this day and date Thursday Dec 31 2009, 2055h

//-------------------------------------------------------------------------
// Edinburgh Trader by ZarethPL - Texture by D4V1DXxX - sails as light brig
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 074> (WBT2T)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "EdinburghTrader";
	refShip.All				= "HMS_Bounty";
	refShip.SName			= "Merchant2";
	refShip.id				= refShip.Name;
	refShip.Class			= 7;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS4;
	refShip.MaxCaliber		= 4;
	refShip.Weight			= Tonnes2CWT(350);
	refShip.Capacity		= 1250;
	refShip.CannonsQuantity	= 14;
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;
	refShip.MaxCrew			= 44;
	refShip.MinCrew			= 7;
	refShip.Price			= 19900;//BB was 15200
	refShip.HP				= 1000;
	refShip.SP				= 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 88;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.9; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.5; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.4; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade 			= true;
	refShip.Type.War 			= false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine			= 0.0;
	refShip.SpeedDependWeight	= 0.3;
	refShip.SubSeaDependWeight	= 0.3;
	
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.4;//BB was 12.45
		refShip.TurnRate		= 105;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.4;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.8;
		refShip.TurnRate		= 37;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 6;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// Small ship
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 074> is henceforth complete
// on this day and date Thursday Dec 31 2009, 2118h

//-------------------------------------------------------------------------
// Aurora class Frigate (Corvette1) - Stock corvette upgraded by Armada and Hylie Pistof
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 134> (WBT1L) - Light Frigate
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Corvette1";
	refShip.sname      		= "FrigateL";
	refShip.id				= refShip.Name;
	refShip.Class		   = 5;
	refShip.Walk			= "Aurora";
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(600);
	refShip.Capacity		= 1500;
	refShip.CannonsQuantity = 30;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 288;
	refShip.MinCrew		 = 58;
	refShip.Price		   = 145200;
	refShip.HP			  = 2500;
	refShip.SP			  = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 72;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.6; //
	refShip.period.4 = 0.4; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.3; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.3; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Aurora"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = 0.2;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.6;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.5;
		refShip.TurnRate		= 40;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT1)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 134> is henceforth complete
// on this day and date Jan 2 10, 1749h

//-------------------------------------------------------------------------
// Fast Merchantman (ex navy frigate) by Armada and Hylie Pistof
// Original skin by Petros; modified by Armada
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 075> (WBT4L)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "FastMerchantman1";
	refShip.SName	 		= "FastMerchant";
	refShip.id			= refShip.Name;
	refShip.Class		   = 5;
	refShip.all				= "Corvette1";
	refShip.Walk			= "FastMerchantman";
	refShip.Cannon			= CANNON_TYPE_LONG_LBS9;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(600);
	refShip.Capacity		= 2200;
	refShip.CannonsQuantity = 26;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;
	// NK <--
	refShip.MaxCrew		 = 150;
	refShip.MinCrew		 = 30;
	refShip.Price		   = 90000;
	refShip.HP			  = 2400;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 36;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.8; //
	refShip.period.4 = 0.6; //
	refShip.period.5 = 0.2; //
	//Nation
	refShip.england = 0.2; //
	refShip.france = 0.5; //
	refShip.holland = 0.5; //
	refShip.portugal = 0.5; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.2; //
	refShip.america = 0.0; //
	refShip.sweden = 0.1; //

	refShip.Model = "Merchantman"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;
	refShip.WaterLine = 0.2;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.55;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.TurnRate		= 70;
	refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
	refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
	refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;

	refShip.RigType = "Fri";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.5;
		refShip.TurnRate		= 70;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.0;
		refShip.TurnRate		= 45;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 1.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT4L)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 075> is henceforth complete
// on this day and date Dec 31 2009, 2307h

//-------------------------------------------------------------------------
// Fast Merchantman (ex navy frigate) by Armada and Hylie Pistof
// Original skin by Rafe Bligh; modified by Armada
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 076> (WBT4L)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name				= "FastMerchantman2";
	refShip.All				= "FastMerchantman1"; // PS
	refShip.SName	 			= "FastMerchant";
	refShip.id				= refShip.Name;
	refShip.Class		   		= 5;
	refShip.Walk				= "FastMerchantman";
	refShip.Cannon				= CANNON_TYPE_LONG_LBS9;
	refShip.MaxCaliber			= 9;
	refShip.Weight				= Tonnes2CWT(600);
	refShip.Capacity			= 2200;
	refShip.CannonsQuantity 		= 26;
	refShip.Cannons.Borts.cannonf.qty 	= 0;
	refShip.Cannons.Borts.cannonb.qty 	= 0;
	refShip.MaxCrew		 		= 150;
	refShip.MinCrew		 		= 30;
	refShip.Price		   		= 90000;
	refShip.HP			  	= 2400;
	refShip.SP			  	= 200;

	refShip.BigPicTexName = "SHIPS1"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 36;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.8; //
	refShip.period.4 = 0.6; //
	refShip.period.5 = 0.2; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.2; //
	refShip.holland = 0.2; //
	refShip.portugal = 0.2; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.5; //
	refShip.america = 0.4; //
	refShip.sweden = 0.2; //

	refShip.Model = "Merchantman"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;
	refShip.WaterLine = 0.2;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.55;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.5;
		refShip.TurnRate		= 70;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.0;
		refShip.TurnRate		= 45;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 1.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

	refShip.RigType = "Fri";

// Review: Vessel configured as:
// high seas cruiser, reduced draft V-hull, moderate turn circle (WBT4L)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 076> is henceforth complete
// on this day and date Dec 31 2009, 2313h

//-------------------------------------------------------------------------
// Fleut1
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 077> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Fleut1";
	refShip.SName	 		= "Fleut1L";
	refShip.id				= refShip.Name;
	refShip.Walk			= "FLEUT1";
	refShip.Class		   = 6;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS6;
	refShip.MaxCaliber		= 6;
	refShip.Weight			= Tonnes2CWT(450);
	refShip.Capacity		= 2000;
	refShip.CannonsQuantity 	= 20;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 60;
	refShip.MinCrew		 = 12;
	refShip.Price		   = 29000;
	refShip.HP			  = 1250;
	refShip.SP			  = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 70;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.7; //
	refShip.period.1 = 1.0; //
	refShip.period.2 = 0.8; //
	refShip.period.3 = 0.3; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.2; //
	refShip.france = 0.0; //
	refShip.holland = 0.4; //
	refShip.portugal = 0.2; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.2; //
	refShip.america = 0.0; //
	refShip.sweden = 0.2; //

	refShip.Model = "Light Fluyt"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = 0.2;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.8;
	
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;	

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 9.0;
		refShip.TurnRate		= 65;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.8;
		refShip.TurnRate		= 35;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 1.0;
		refShip.InertiaAccelerationY	= 8;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 077> is henceforth complete
// on this day and date Dec 31 2009, 2307h

//-------------------------------------------------------------------------
// Fleut2, Skin by Rafe Bligh
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 078> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Fleut2";
	refShip.All				= "Fleut1";
	refShip.SName	 		= "Fleut1L";
	refShip.id				= refShip.Name;
	refShip.Walk			= "FLEUT1";
	refShip.Class		   = 6;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS6;
	refShip.MaxCaliber		= 6;
	refShip.Weight			= Tonnes2CWT(450);
	refShip.Capacity		= 2000;
	refShip.CannonsQuantity = 20;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 60;
	refShip.MinCrew		 = 12;
	refShip.Price		   = 29000;
	refShip.HP			  = 1250;
	refShip.SP			  = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 70;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.7; //
	refShip.period.1 = 1.0; //
	refShip.period.2 = 0.8; //
	refShip.period.3 = 0.3; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.2; //
	refShip.france = 0.2; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.2; //

	refShip.Model = "Light Fluyt"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = 0.2;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.8;
	
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;	

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 9.0;
		refShip.TurnRate		= 65;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.8;
		refShip.TurnRate		= 35;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 1.0;
		refShip.InertiaAccelerationY	= 8;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

	refShip.RigType = "Bat";

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 078> is henceforth complete
// on this day and date Dec 31 2009, 2307h

//-------------------------------------------------------------------------
// Light Galleon (PO_Fleut50) by Petros
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 081> (WBT1H)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "PO_Fleut50";
	refShip.All 			= "Fleut1";
	refShip.SName 			= "Fleut1";
	refShip.id				= refShip.Name;
	refShip.Class			= 4;
	refShip.Walk			= "Fleut2";
	refShip.Cannon			= CANNON_TYPE_LONG_LBS9;//BB was 'CANNON_TYPE_Long_LBS9'
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(450);
	refShip.Capacity			= 5000;
	refShip.CannonsQuantity		= 30;

	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;

	refShip.MaxCrew			= 135;
	refShip.MinCrew			= 27;
	refShip.Price			= 68000;
	refShip.HP			= 3500;
	refShip.SP			= 200;
	refShip.Jetty			= false; // PB
// Petros -->
	refShip.EmblemedSails.normalTex = "sail_petros_plain.tga";
	refShip.EmblemedSails.nationFileName = "sail_petros_plain.tga";
// <-- Petros

	refShip.Model = "Fluyt"; // KK
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 70;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.9; //
	refShip.period.1 = 1.0; //
	refShip.period.2 = 0.8; //
	refShip.period.3 = 0.2; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0 //
	refShip.holland = 0.0; //
	refShip.portugal = 0.2; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.2; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade		= true;
	refShip.Type.War			= false;

	refShip.WaterLine			= 0.3;
	refShip.SpeedDependWeight	= 0.3;
	refShip.SubSeaDependWeight	= 0.9;
	refShip.TurnDependWeight		= 0.8;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 9.0;
		refShip.TurnRate		= 65;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.8;
		refShip.TurnRate		= 35;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 1.0;
		refShip.InertiaAccelerationY	= 8;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

	refShip.RigType = "Bat";

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 081> is henceforth complete
// on this day and date Dec 31 2009, 2307h

//-------------------------------------------------------------------------
// Dutch Fleut (NL_Fleut50) by Petros
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 082> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "NL_Fleut50";
	refShip.All 			= "Fleut1";
	refShip.SName 			= "Fleut1";
	refShip.id			= refShip.Name;
	refShip.Walk			= "Fleut2";
	refShip.Class			= 4;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS9;//BB was 'CANNON_TYPE_Long_LBS9'
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(450);
	refShip.Capacity			= 5000;
	refShip.CannonsQuantity		= 30;

	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;

	refShip.MaxCrew			= 135;
	refShip.MinCrew			= 27;
	refShip.Price			= 68000;
	refShip.HP			= 3500;
	refShip.SP			= 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 70;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.7; //
	refShip.period.1 = 1.0; //
	refShip.period.2 = 0.8; //
	refShip.period.3 = 0.2; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.4; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;
	refShip.Model = "Fluyt"; // KK
	refShip.Type.Trade		= true;
	refShip.Type.War			= false;

	refShip.WaterLine		= 0.3;
	refShip.SpeedDependWeight	= 0.3;
	refShip.SubSeaDependWeight	= 0.9;
	refShip.TurnDependWeight	= 0.8;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 9.0;
		refShip.TurnRate		= 65;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.8;
		refShip.TurnRate		= 35;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 1.0;
		refShip.InertiaAccelerationY	= 8;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

	refShip.RigType = "Bat";

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 082> is henceforth complete
// on this day and date Dec 31 2009, 2307h

//-------------------------------------------------------------------------
//      34 Gun Fleut of War (FleutWar) by Captain Hawk
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 083> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "FleutWar";
	refShip.All				= "Fleut1";
	refShip.Sname			= "FleutWarL";
	refShip.id				= refShip.Name;
	refShip.Walk			= "Fleut2";
	refShip.Class			= 4;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(450);
	refShip.Capacity		= 3500;
	refShip.CannonsQuantity = 34;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 204;
	refShip.MinCrew		 = 41;
	refShip.Price		   = 109600;
	refShip.HP		  = 3500;
	refShip.SP		  = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 56;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.5; //
	refShip.period.1 = 0.8; //
	refShip.period.2 = 0.7; //
	refShip.period.3 = 0.3; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.13; //
	refShip.france = 0.12; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.1; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = true;
	refShip.Type.War = true;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = 0.3;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.9;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 9.0;
		refShip.TurnRate		= 65;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.8;
		refShip.TurnRate		= 32;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 1.0;
		refShip.InertiaAccelerationY	= 8;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

	refShip.RigType = "Bat";

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 083> is henceforth complete
// on this day and date Dec 31 2009, 2307h

//-------------------------------------------------------------------------
//      Satanist Fleut of War (FleutWar) by Grey Roger
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 083> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "FleutWarSat";
	refShip.All				= "Fleut1";
	refShip.Nation			= PIRATE;
	refShip.unique			= true;
	refShip.Sname			= "FleutWarSat";
	refShip.id			= refShip.Name;
	refShip.Walk			= "Fleut2";
	refShip.Class			= 4;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS18;
	refShip.MaxCaliber		= 18;
	refShip.Weight			= Tonnes2CWT(405);
	refShip.Capacity		= 3500;
	refShip.CannonsQuantity = 34;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 340;
	refShip.MinCrew		 = 68;
	refShip.Price		   = 151200;
	refShip.HP		  = 4000;
	refShip.SP		  = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName	= "SHIPS2"; // Armada

	refShip.EmblemedSails.normalTex = "sail_whole_red_plain.tga";
	refShip.EmblemedSails.nationFileName = "sail_whole_red_plain.tga";

// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 130;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.01; //
	refShip.period.1 = 0.01; //
	refShip.period.2 = 0.01; //
	refShip.period.3 = 0.01; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.Model = "FleutWarSat"; // KK
	refShip.CanBuy		= false;
	refShip.CanEncounter	= false;

	refShip.WaterLine = 0.3;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.9;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 9.9;
		refShip.TurnRate		= 71;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.0;
		refShip.TurnRate		= 35;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 1.0;
		refShip.InertiaAccelerationY	= 8;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

	refShip.RigType = "Bat";

//-------------------------------------------------------------------------
//      Ex-Satanist Fleut of War (FleutWar) by Grey Roger
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 083> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "FleutWarExSat";
	refShip.All				= "Fleut1";
	refShip.Nation			= PIRATE;
	refShip.unique			= true;
	refShip.Sname			= "FleutWar";
	refShip.id			= refShip.Name;
	refShip.Walk			= "Fleut2";
	refShip.Class			= 4;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS18;
	refShip.MaxCaliber		= 18;
	refShip.Weight			= Tonnes2CWT(405);
	refShip.Capacity		= 3500;
	refShip.CannonsQuantity = 34;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 340;
	refShip.MinCrew		 = 68;
	refShip.Price		   = 151200;
	refShip.HP		  = 4000;
	refShip.SP		  = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 56;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.01; //
	refShip.period.1 = 0.01; //
	refShip.period.2 = 0.01; //
	refShip.period.3 = 0.01; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.Model = "FleutWarSat"; // KK
	refShip.CanBuy		= false;
	refShip.CanEncounter	= false;

	refShip.WaterLine = 0.3;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.9;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 9.9;
		refShip.TurnRate		= 71;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.0;
		refShip.TurnRate		= 35;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 1.0;
		refShip.InertiaAccelerationY	= 8;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

	refShip.RigType = "Bat";

//-------------------------------------------------------------------------
// FR_LightPinnace (French) by Yo Ho Ho
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 086> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "FR_LightPinnace";
	refShip.SName	 		= "PinnaceL";
	refShip.walk			= "LightPinnace"; // PB & back84
	refShip.id				= refShip.Name;
	refShip.Class		   = 6;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS6;
	refShip.MaxCaliber		= 6;
	refShip.Weight			= Tonnes2CWT(450);//BB was 550 same as normal Pinnace
	refShip.Capacity		= 2000;
	refShip.CannonsQuantity = 16;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 54;
	refShip.MinCrew		 = 11;
	refShip.Price		   = 26600;
	refShip.HP			  = 1250;
	refShip.SP			  = 200;
	refShip.Jetty			  = false; 	//JRH

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 88;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.6; //
	refShip.period.2 = 0.7; //
	refShip.period.3 = 0.4; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.35; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Light Pinnace"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = 0.8;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.3;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 9.0;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.6;
		refShip.TurnRate		= 29;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 3.0;

	}


// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 086> is henceforth complete
// on this day and date Jan 1 2010, 1046h

//-------------------------------------------------------------------------
// Pinnace1
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 087> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Pinnace1";
	refShip.SName	 		= "Pinnace1";
	refShip.id				= refShip.Name;
	refShip.Class		   = 4;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS9;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(750);
	refShip.Capacity		= 5000;
	refShip.CannonsQuantity = 24;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 6;
	// NK <--
	refShip.MaxCrew		 = 108;
	refShip.MinCrew		 = 35;
	refShip.Price		   = 51200;
	refShip.HP			  = 3500;
	refShip.SP			  = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 116;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag2 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.6; //
	refShip.period.2 = 0.7; //
	refShip.period.3 = 0.4; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.3; //
	refShip.holland = 0.4; //
	refShip.portugal = 0.36; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Pinnace"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = 0.5;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.3;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 9.0;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.6;
		refShip.TurnRate		= 29;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 3.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 087> is henceforth complete
// on this day and date Jan 1 2010, 1046h

//-------------------------------------------------------------------------
// Pinnace2
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 088> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Pinnace2";
	refShip.SName	 		= "Pinnace1";
	refShip.All				= "Pinnace1";
	refShip.id				= refShip.Name;
	refShip.Class		   = 4;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS9;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(750);
	refShip.Capacity		= 5000;
	refShip.CannonsQuantity = 24;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 6;
	// NK <--
	refShip.MaxCrew		 = 108;
	refShip.MinCrew		 = 35;
	refShip.Price		   = 51200;
	refShip.HP			  = 3500;
	refShip.SP			  = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 116;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag2 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.6; //
	refShip.period.2 = 0.7; //
	refShip.period.3 = 0.4; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.3; //
	refShip.france = 0.35; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.3; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Pinnace"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = 0.3;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.1;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 9.0;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.6;
		refShip.TurnRate		= 29;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 3.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 088> is henceforth complete
// on this day and date Jan 1 2010, 1046h

//-------------------------------------------------------------------------
// NL_Pinnace by Yo Ho Ho
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 090> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "NL_Pinnace";
	refShip.sname      		= "Pinnace1";
	refShip.All				= "Pinnace1";
	refShip.id				= refShip.Name;
	refShip.walk			= "NL_Pinnace"; // Hylie Pistof
	refShip.Class		   = 5;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS9;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(600);//BB was 800, reduced for better match vs other Pinnace
	refShip.Capacity		= 3000;
	refShip.CannonsQuantity = 26;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	refShip.MaxCrew		 = 117;
	refShip.MinCrew		 = 23;
	refShip.Price		   = 54800;
	refShip.HP			  = 2300;//BB was 2000, increased due to extra weight vs other Pinnace
	refShip.SP			  = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 116;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.6; //
	refShip.period.2 = 0.7; //
	refShip.period.3 = 0.4; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.37; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = true;
	refShip.Type.War = false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = -0.7;         // Was 0.5.  The flagpole fix let me raise it.  HP
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.3;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 9.0;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.6;
		refShip.TurnRate		= 29;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 3.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 090> is henceforth complete
// on this day and date Jan 1 2010, 1046h

//-------------------------------------------------------------------------
//      Merchantman (SP_Pinnace50) by Petros
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 091> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "SP_Pinnace50";
	refShip.id			= refShip.Name;
	refShip.All			= "Pinnace2";
	refShip.sname			= "PinnaceH";
	refShip.Class		  	= 4;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS9;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(750);//BB was 550, increased to better match capacity+hp
	refShip.Capacity		= 5000;
	refShip.CannonsQuantity 	= 30;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 6;
	// NK <--
	refShip.MaxCrew			= 135;
	refShip.MinCrew			= 27;
	refShip.Price		   = 68000;
	refShip.HP			  = 3500;
	refShip.SP			  = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 116;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.6; //
	refShip.period.2 = 0.7; //
	refShip.period.3 = 0.4; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.4; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade		= true;
	refShip.Type.War		= false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine		= 0.3;
	refShip.SpeedDependWeight	= 0.3;
	refShip.SubSeaDependWeight	= 1.1;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 9.0;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.6;
		refShip.TurnRate		= 29;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 3.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 091> is henceforth complete
// on this day and date Jan 1 2010, 1046h

//-------------------------------------------------------------------------
//      Waller Pinnace (WallerPinnace) by Captain Hawk
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 094> (WBT4H)  - high topweight - performance decreased!
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "WallerPinnace";
	refShip.sname			= "PinnaceWH";
	refShip.All				= "Pinnace1";
	refShip.id				= refShip.Name;
	refShip.Class		   = 1;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber		= 24;
	refShip.Weight			= Tonnes2CWT(1300);//BB increased vs normal pinnace
	refShip.Capacity		= 4000;
	refShip.CannonsQuantity = 54;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 6;
	// NK <--
	refShip.MaxCrew		 = 540;
	refShip.MinCrew		 = 108;
	refShip.Price		   = 272000;
	refShip.HP			  = 7000;
	refShip.SP			  = 200;
	refShip.Jetty = false; // CTM

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 54;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.4; //
	refShip.period.2 = 0.7; //
	refShip.period.3 = 0.4; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.4; //
	refShip.france = 0.3; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.3; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.1; //

	refShip.Model = "Heavy Pinnace"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = true;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = 0.5;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.1;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 8.5;
		refShip.TurnRate		= 42;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.6;
		refShip.TurnRate		= 29;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 3.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, moderate turn circle (WBT4H)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 094> is henceforth complete
// on this day and date Jan 1 2010, 1046h

//-------------------------------------------------------------------------
// Galeon1
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 096> (WBT4XL)  - Huge "Manila" galleon of 2000 tons
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Galeon1";
	if(iRealismMode>0)	refShip.SName = "Galeon1R_real";
	else				refShip.SName = "Galeon1R";
	refShip.Nation 			= SPAIN;
	refShip.id				= refShip.Name;
	refShip.Class			   = 2;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS18;
	refShip.MaxCaliber			= 18;
	refShip.Weight			= Tonnes2CWT(2200);
	refShip.Capacity			= 8000;
	refShip.CannonsQuantity 		= 40;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty 	= 2;
	refShip.Cannons.Borts.cannonb.qty	 = 4;
	// NK <--
	refShip.MaxCrew		 	= 350;
	refShip.MinCrew		 	= 68;
	refShip.Price			   = 168000;
	refShip.HP			  = 5500;
	refShip.SP			  = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 66;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag2 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.8; //
	refShip.period.1 = 1.0; //
	refShip.period.2 = 0.4; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.2; //
	refShip.france = 0.2; //
	refShip.holland = 0.2; //
	refShip.portugal = 0.3; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.4; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Galleon"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 8.5;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.7;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 11.5;
		refShip.TurnRate		= 20;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 6;	refShip.InertiaBrakingY		= 3;
		refShip.InertiaAccelerationZ	= 2.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, LARGE turn circle (WBT4XL)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 096> is henceforth complete
// on this day and date Jan 1 2010, 1711h

//-------------------------------------------------------------------------
// Light Manila Galeon (Galeon2)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 097> (WBT4XL)  - Huge galleon
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Galeon2";
	refShip.All 			= "Galeon1";
	if(iRealismMode>0)	refShip.SName = "Galeon1L_real";
	else				refShip.SName = "Galeon1L";
	refShip.id				= refShip.Name;
	refShip.Class		   = 2;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS18;
	refShip.MaxCaliber		= 18;
	refShip.Weight			= Tonnes2CWT(2000);
	refShip.Capacity		= 7500;
	refShip.CannonsQuantity = 36;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	// NK <--
	refShip.MaxCrew		 = 342;
	refShip.MinCrew		 = 68;
	refShip.Price		   = 155800;
	refShip.HP			  = 5500;
	refShip.SP			  = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 66;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag2 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 1.0; //
	refShip.period.1 = 0.9; //
	refShip.period.2 = 0.2; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.2; //
	refShip.france = 0.2; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.2; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.2; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

//	refShip.Model = "Galleon"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 8.5;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.7;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 11.5;
		refShip.TurnRate		= 20;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 6;	refShip.InertiaBrakingY		= 3;
		refShip.InertiaAccelerationZ	= 2.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, LARGE turn circle (WBT4XL)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 097> is henceforth complete
// on this day and date Jan 1 2010, 1711h

//-------------------------------------------------------------------------
//      Royal Galleon (SP_Galeon50)  by Petros
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 098> (WBT4XL)  - Huge galleon
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "SP_Galeon50";
	refShip.All 			= "Galeon1";
	if(iRealismMode>0)	refShip.SName = "Galeon1R_real";
	else				refShip.SName = "Galeon1R";
	refShip.id				= "SP_Galeon50";
	refShip.Class		   = 1;
	refShip.Cannon		  = CANNON_TYPE_LONG_LBS18;
	refShip.MaxCaliber	  = 18;
	refShip.Weight			= Tonnes2CWT(2200);
	refShip.Capacity		= 8000;
	refShip.CannonsQuantity = 40;
	refShip.MaxCrew		 = 350;
	refShip.MinCrew		 = 72;
	refShip.Price		   = 168000;
	refShip.HP			  = 5500;
	refShip.SP			  = 200;
	refShip.Jetty			= false; // PB
// Petros -->
	refShip.EmblemedSails.normalTex = "sail_petros_plain.tga";
	refShip.EmblemedSails.nationFileName = "sail_petros_plain.tga";
// <-- Petros

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 66;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag2 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 1.0; //
	refShip.period.1 = 1.0; //
	refShip.period.2 = 0.5; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.3; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.3; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;
	refShip.Model = "Galleon"; // KK
	refShip.Type.Trade		= true;
	refShip.Type.War		= false;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;
	refShip.TurnDependWeight = 0.8;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 8.5;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.7;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 11.5;
		refShip.TurnRate		= 24;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 6;	refShip.InertiaBrakingY		= 3;
		refShip.InertiaAccelerationZ	= 2.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, LARGE turn circle (WBT4XL)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 098> is henceforth complete
// on this day and date Jan 1 2010, 1711h

//-------------------------------------------------------------------------
// Spanish Historical War Galleon San Martin - by SuperChango
// Weathered version by SWS
//  WBT S/N 220 TEMPLATE 4 XL
// New details and textures by Craiggo. Import to PotC, plus deck texture, by Armada
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "SP_BattleGalleon";
	refShip.nation			= SPAIN;
	refShip.all				= "Galeon1";
	refShip.sname      		= "Galeon2H";
	refShip.id				= refShip.Name;
	refShip.Class		   = 1;
	refShip.Walk			= "BattleGalleon";
	refShip.Cannon			= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber		= 24;
	refShip.Weight			= Tonnes2CWT(2500);
	refShip.Capacity		= 6000;
	refShip.CannonsQuantity = 56;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 560;
	refShip.MinCrew		 = 112;
	refShip.Price		   = 280000;
	refShip.HP			  = 7000;
	refShip.SP			  = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 66;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 1.0; //
	refShip.period.1 = 0.9; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.2; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = -0.5;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 8.5;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.7;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 11.5;
		refShip.TurnRate		= 20;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 6;	refShip.InertiaBrakingY		= 3;
		refShip.InertiaAccelerationZ	= 2.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, LARGE turn circle (WBT4XL)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 097> is henceforth complete
// on this day and date Jan 1 2010, 1711h

//-------------------------------------------------------------------------
// Spanish Historical War Galleon San Martin - by SuperChango
//  WBT S/N 220 TEMPLATE 4 XL
// New details and textures by Craiggo. Import to PotC, plus deck texture, by Armada
// Modified version and textures by Bartolomeu o Portugues
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "PiratBattleGalleon";
	refShip.nation			= PORTUGAL;
	refShip.all				= "Galeon1";
	refShip.sname      		= "Galeon2H";
	refShip.unique			= true;
	refShip.id				= refShip.Name;
	refShip.Class		   = 1;
	refShip.Walk			= "BattleGalleon";
	refShip.Cannon			= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber		= 24;
	refShip.Weight			= Tonnes2CWT(2625); // Modified for Portugal, was 2500
	refShip.Capacity		= 6000; // Modified for Portugal, was 5000
	refShip.CannonsQuantity = 56;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 546; // Modified for Portugal, was 520
	refShip.MinCrew		 = 112;
	refShip.Price		   = 280000;
	refShip.HP			  = 6460; // Modified for Portugal, was 6800
	refShip.SP			  = 200;
	refShip.Jetty			= false; // PB

	refShip.EmblemedSails.normalTex = "sail_whole_red_plain.tga";
	refShip.EmblemedSails.nationFileName = "sail_whole_red_pirate6.tga";
	
	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 66;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
// <-- KK

	refShip.Type.Trade = true;
	refShip.Type.War = true;
	refShip.CanBuy		= false; //Quest Ship!!
	refShip.CanEncounter	= false; //Quest Ship!!

	refShip.WaterLine = -0.5;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 9.5;
		refShip.TurnRate		= 58; // Modified for Portugal, was 50
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.7;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 22;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 6;	refShip.InertiaBrakingY		= 3;
		refShip.InertiaAccelerationZ	= 2.0;	refShip.InertiaBrakingZ		= 4.0;
	}

//-------------------------------------------------------------------------
//      War Galleon (GaleonWar) by Petros
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 099> (WBT4XL)  - Huge galleon
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "GaleonWar";
	refShip.All 		= "Galeon1";
	refShip.SName 		= "Galeon2";
	refShip.id				= "GaleonWar";
	refShip.Class		   = 2;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber		= 24;
	refShip.Weight			= Tonnes2CWT(2300);
	refShip.Capacity		= 5000;
	refShip.CannonsQuantity = 40;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	// NK <--
	refShip.MaxCrew		 = 400;
	refShip.MinCrew		 = 80;
	refShip.Price		   = 208000;
	refShip.HP			  = 6000;
	refShip.SP			  = 200;
	refShip.Jetty			= false; // PB
// Petros -->
	refShip.EmblemedSails.normalTex = "sail_petros_plain.tga";
	refShip.EmblemedSails.nationFileName = "sail_petros_plain.tga";
// <-- Petros

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 66;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag2 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.7; //
	refShip.period.1 = 1.0; //
	refShip.period.2 = 0.5; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.3; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
	refShip.Model = "Armed Galleon"; // KK
	refShip.Type.Trade 	= true;
	refShip.Type.War 	= true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 8.5;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.7;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 11.5;
		refShip.TurnRate		= 22;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 6;	refShip.InertiaBrakingY		= 3;
		refShip.InertiaAccelerationZ	= 2.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, LARGE turn circle (WBT4XL)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 099> is henceforth complete
// on this day and date Jan 1 2010, 1711h

//-------------------------------------------------------------------------
//      War Galleon (Galeon50)  by Petros
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 100> (WBT4XL)  - Huge galleon
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Galeon50";
	refShip.All = "Galeon1";
	refShip.SName = "Galeon2";
	refShip.id				= "Galeon50";
	refShip.Class		   = 2;
	refShip.Cannon		  = CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber	  = 24;
	refShip.Weight			= Tonnes2CWT(2300);
	refShip.Capacity		= 5000;
	refShip.CannonsQuantity 	= 40;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	// NK <--
	refShip.MaxCrew		 = 400;
	refShip.MinCrew		 = 80;
	refShip.Price		   = 208000;
	refShip.HP			  = 6000;
	refShip.SP			  = 200;
	refShip.Jetty			= false; // PB

// Petros -->
	refShip.EmblemedSails.normalTex = "sail_petros_plain.tga";
	refShip.EmblemedSails.nationFileName = "sail_petros_plain.tga";
// <-- Petros

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 66;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag2 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 1.0; //
	refShip.period.1 = 1.0; //
	refShip.period.2 = 0.5; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.1; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.3; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.3; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;
	refShip.Model = "Armed Galleon"; // KK
	refShip.Type.Trade		= true;
	refShip.Type.War		= true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;
	refShip.TurnDependWeight = 0.8;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 8.5;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.7;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 11.5;
		refShip.TurnRate		= 20;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 6;	refShip.InertiaBrakingY		= 3;
		refShip.InertiaAccelerationZ	= 2.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, LARGE turn circle (WBT4XL)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 100> is henceforth complete
// on this day and date Jan 1 2010, 1711h

//-------------------------------------------------------------------------
// NL_FleutWar by Seb
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 154> (WBT4) - 4th Rate "Battle Frigate"
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "NL_FleutWar";
	refShip.id				= refShip.Name;
	refShip.all				= "Fleut1";
	refShip.SName			= "FleutWar";
	refShip.Walk			= "FleutWar"; // PB & back84
	refShip.Class		   = 4;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS18;
	refShip.MaxCaliber		= 18;
	refShip.Weight			= Tonnes2CWT(1200);
	refShip.Capacity		= 4000;
	refShip.CannonsQuantity = 46;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	// NK <--
	refShip.MaxCrew		 = 414;
	refShip.MinCrew		 = 83;
	refShip.Price		   = 199600;
	refShip.HP			  = 4000;
	refShip.SP			  = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 54;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;

	//Period
	refShip.period.0 = 0.1; //
	refShip.period.1 = 0.2; //
	refShip.period.2 = 0.4; //
	refShip.period.3 = 0.1; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 1.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //
// <-- KK

	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.3;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.8;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 11.0;
		refShip.TurnRate		= 32;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 154> is henceforth complete
// on this day and date Jan 2 2010, 2109h

//-------------------------------------------------------------------------
//	Dutch Two-decker by Thomas the Terror, based on original texture by Petros
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 096> (WBT4H)  - high topweight - performance decreased!
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name				= "NL_PinnaceofWar47";
	refShip.SName				= "PinnaceWH";
	refShip.id					= refShip.Name;
	refShip.walk				= "Pinnace1"; // PB
	refShip.All					= "Pinnace1";
	refShip.Class				= 1;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber			= 24;
	refShip.Weight				= Tonnes2CWT(1300);//BB was 550 increased vs normal Pinnace
	refShip.Capacity			= 4000;
	refShip.CannonsQuantity		= 54;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 6;
	// NK <--
	refShip.MaxCrew				 = 540;
	refShip.MinCrew				 = 108;
	refShip.Price				= 272000;
	refShip.HP					= 7000;
	refShip.SP					= 200;
	refShip.Jetty				= false; 	//JRH
//	refShip.RigType = "Fri";

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 54;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.4; //
	refShip.period.2 = 0.7; //
	refShip.period.3 = 0.6; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.5; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Heavy Pinnace"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = true;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = 0.5;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.1;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 8.7;
		refShip.TurnRate		= 42;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.85;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 11.0;
		refShip.TurnRate		= 28;
		refShip.InertiaAccelerationX = 0.2;		refShip.InertiaBrakingX = 2.0;
		refShip.InertiaAccelerationY = 7;		refShip.InertiaBrakingY = 6;
		refShip.InertiaAccelerationZ = 4.0;		refShip.InertiaBrakingZ = 2.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, moderate turn circle (WBT4H)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 096> is henceforth complete
// on this day and date Jan 1 2010, 1046h

//-------------------------------------------------------------------------
// War Galleon (Portuguese) - by Yo Ho Ho
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 102> (WBT4H)  - East Indiaman
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "PO_WarGalleon";
	refShip.id				= refShip.Name;
	refShip.All				= "Galeon1";
	refShip.walk			= "WarGalleon"; // PB & back84
	refShip.SName			= "Indiaman1H";
	refShip.Class			= 1;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(1200);
	refShip.Capacity		= 5000;
	refShip.CannonsQuantity = 52;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 4;
	refShip.Cannons.Borts.cannonb.qty = 4;
	// NK <--
	refShip.MaxCrew = 344;
	refShip.MinCrew = 84;
	refShip.Price = 272000;
	refShip.HP = 8000;
	refShip.SP = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 18;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast0.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.2; //
	refShip.period.2 = 0.5; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.2; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.3; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

// East Indiaman was an English invention

	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;
	refShip.Model = "Indiaman"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = true;

	refship.WaterLine = -0.9;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;

	refShip.GeraldSails.rey_a2 = 1;
	refShip.GeraldSails.rey_a3 = 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 9.5;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.75;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 11.0;
		refShip.TurnRate		= 30;
		refShip.InertiaAccelerationX = 0.2;		refShip.InertiaBrakingX = 2.0;
		refShip.InertiaAccelerationY = 7;		refShip.InertiaBrakingY = 6;
		refShip.InertiaAccelerationZ = 4.0;		refShip.InertiaBrakingZ = 2.0;

	}

// Review: Vessel configured as: East Indiaman
// high seas cruiser, deep draft V-hull, better turn circle (WBT4H)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 102> is henceforth complete
// on this day and date Jan 1 2010, 1834h

//-------------------------------------------------------------------------
// Heavy Trader (French) - by Yo Ho Ho
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 103> (WBT4H)  - Indiaman
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "FR_WarGalleon";
	refShip.id				= refShip.Name;
	refShip.All				= "Galeon1";
	refShip.walk			= "WarGalleon"; // PB & back84
	refShip.SName			= "Indiaman1H";
	refShip.Class			= 1;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(1200);
	refShip.Capacity		= 5000;
	refShip.CannonsQuantity = 52;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 4;
	refShip.Cannons.Borts.cannonb.qty = 4;
	// NK <--
	refShip.MaxCrew = 344;
	refShip.MinCrew = 84;
	refShip.Price = 272000;
	refShip.HP = 8000;
	refShip.SP = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 18;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast0.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.2; //
	refShip.period.2 = 0.5; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.25; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;
	refShip.Model = "Indiaman"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = true;

	refship.WaterLine = -0.9;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;

	refShip.GeraldSails.rey_a2 = 1;
	refShip.GeraldSails.rey_a3 = 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 9.5;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.75;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 11.0;
		refShip.TurnRate		= 30;
		refShip.InertiaAccelerationX = 0.2;		refShip.InertiaBrakingX = 2.0;
		refShip.InertiaAccelerationY = 7;		refShip.InertiaBrakingY = 6;
		refShip.InertiaAccelerationZ = 4.0;		refShip.InertiaBrakingZ = 2.0;

	}

// Review: Vessel configured as: East Indiaman
// high seas cruiser, deep draft V-hull, better turn circle (WBT4H)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 103> is henceforth complete
// on this day and date Jan 1 2010, 1834h

//-------------------------------------------------------------------------
// Heavy Trader (English) - by Yo Ho Ho
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 104> (WBT4H)  - Indiaman
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "RN_WarGalleon";
	refShip.id				= refShip.Name;
	refShip.All				= "Galeon1";
	refShip.walk			= "WarGalleon"; // PB & back84
	refShip.SName			= "Indiaman1H";
	refShip.Class			= 1;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(1200);
	refShip.Capacity		= 5000;
	refShip.CannonsQuantity = 52;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 4;
	refShip.Cannons.Borts.cannonb.qty = 4;
	// NK <--
	refShip.MaxCrew = 344;
	refShip.MinCrew = 84;
	refShip.Price = 272000;
	refShip.HP = 8000;
	refShip.SP = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 18;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast0.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.2; //
	refShip.period.2 = 0.5; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.25; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;
	refShip.Model = "Indiaman"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = true;

	refship.WaterLine = -0.9;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;

	refShip.GeraldSails.rey_a2 = 1;
	refShip.GeraldSails.rey_a3 = 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 9.5;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.75;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 11.0;
		refShip.TurnRate		= 30;
		refShip.InertiaAccelerationX = 0.2;		refShip.InertiaBrakingX = 2.0;
		refShip.InertiaAccelerationY = 7;		refShip.InertiaBrakingY = 6;
		refShip.InertiaAccelerationZ = 4.0;		refShip.InertiaBrakingZ = 2.0;

	}

// Review: Vessel configured as: East Indiaman
// high seas cruiser, deep draft V-hull, better turn circle (WBT4H)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 104> is henceforth complete
// on this day and date Jan 1 2010, 1834h

//-------------------------------------------------------------------------
// Heavy Trader (Dutch) - by Yo Ho Ho
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 105> (WBT4H)  - Indiaman
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "NL_WarGalleon";
	refShip.id				= refShip.Name;
	refShip.All				= "Galeon1";
	refShip.walk			= "WarGalleon"; // PB & back84
	refShip.SName			= "Indiaman1H";
	refShip.Class			= 1;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(1200);
	refShip.Capacity		= 5000;
	refShip.CannonsQuantity = 52;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 4;
	refShip.Cannons.Borts.cannonb.qty = 4;
	// NK <--
	refShip.MaxCrew = 344;
	refShip.MinCrew = 84;
	refShip.Price = 272000;
	refShip.HP = 8000;
	refShip.SP = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 18;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast0.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.2; //
	refShip.period.2 = 0.5; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.25; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;
	refShip.Model = "Indiaman"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = true;

	refship.WaterLine = -0.9;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;

	refShip.GeraldSails.rey_a2 = 1;
	refShip.GeraldSails.rey_a3 = 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 9.5;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.75;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 11.0;
		refShip.TurnRate		= 30;
		refShip.InertiaAccelerationX = 0.2;		refShip.InertiaBrakingX = 2.0;
		refShip.InertiaAccelerationY = 7;		refShip.InertiaBrakingY = 6;
		refShip.InertiaAccelerationZ = 4.0;		refShip.InertiaBrakingZ = 2.0;

	}

// Review: Vessel configured as: East Indiaman
// high seas cruiser, deep draft V-hull, better turn circle (WBT4H)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 105> is henceforth complete
// on this day and date Jan 1 2010, 1834h


//-------------------------------------------------------------------------
// Heavy Trader (Spanish) - by Yo Ho Ho
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 104> (WBT4H)  - Indiaman
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "SP_WarGalleon";
	refShip.id				= refShip.Name;
	refShip.All				= "Galeon1";
	refShip.walk			= "WarGalleon"; // PB & back84
	refShip.SName			= "Indiaman1H";
	refShip.Class			= 1;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(1200);
	refShip.Capacity		= 5000;
	refShip.CannonsQuantity = 52;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 4;
	refShip.Cannons.Borts.cannonb.qty = 4;
	// NK <--
	refShip.MaxCrew = 344;
	refShip.MinCrew = 84;
	refShip.Price = 272000;
	refShip.HP = 8000;
	refShip.SP = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 18;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast0.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.2; //
	refShip.period.2 = 0.5; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.25; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;
	refShip.Model = "Indiaman"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = true;

	refship.WaterLine = -0.9;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;

	refShip.GeraldSails.rey_a2 = 1;
	refShip.GeraldSails.rey_a3 = 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 9.5;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.75;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 11.0;
		refShip.TurnRate		= 30;
		refShip.InertiaAccelerationX = 0.2;		refShip.InertiaBrakingX = 2.0;
		refShip.InertiaAccelerationY = 7;		refShip.InertiaBrakingY = 6;
		refShip.InertiaAccelerationZ = 4.0;		refShip.InertiaBrakingZ = 2.0;

	}

// Review: Vessel configured as: East Indiaman
// high seas cruiser, deep draft V-hull, better turn circle (WBT4H)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 104> is henceforth complete
// on this day and date Jan 1 2010, 1834h


//-------------------------------------------------------------------------
// La Licorne texture by Seb
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 106> (WBT4H)  - Indiaman
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "FR_Licorne";
	refShip.id				= refShip.Name;
	refShip.All				= "Galeon1";
	refShip.SName			= "Indiaman1H";
	refShip.walk			= "WarGalleon"; // PB & back84
	refShip.Class			= 1;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(1200);
	refShip.Capacity		= 5000;
	refShip.CannonsQuantity = 52;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 4;
	refShip.Cannons.Borts.cannonb.qty = 4;
	// NK <--
	refShip.MaxCrew = 344;
	refShip.MinCrew = 84;
	refShip.Price = 272000;
	refShip.HP = 8000;
	refShip.SP = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 116;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast0.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.2; //
	refShip.period.2 = 0.5; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.35; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;
	refShip.Model = "Indiaman"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = true;

	refship.WaterLine = -0.9;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 9.5;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.75;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 11.0;
		refShip.TurnRate		= 30;
		refShip.InertiaAccelerationX = 0.2;		refShip.InertiaBrakingX = 2.0;
		refShip.InertiaAccelerationY = 7;		refShip.InertiaBrakingY = 6;
		refShip.InertiaAccelerationZ = 4.0;		refShip.InertiaBrakingZ = 2.0;

	}

// Review: Vessel configured as: East Indiaman
// high seas cruiser, deep draft V-hull, better turn circle (WBT4H)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 105> is henceforth complete
// on this day and date Jan 1 2010, 1834h

//-------------------------------------------------------------------------
//      Fast Galleon (FastGalleon1) by De Zeeroovers
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 001> (WBT1)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "FastGalleon1";
	refShip.All = "Galeon1";
	refShip.id				= "FastGalleon1";
	refShip.Class		   = 3;
	refShip.SName 		= "FastGalleon";
	refShip.Walk  = "FastGalleon"; // PB & back84
	refShip.Cannon			= CANNON_TYPE_LONG_LBS9;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(1750);
	refShip.Capacity		= 5000;
	refShip.CannonsQuantity = 38;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	refShip.MaxCrew		 = 360;
	refShip.MinCrew		 = 32;
	refShip.Price		   = 110000;
	refShip.HP			  = 4000;
	refShip.SP			  = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 66;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 1.0; //
	refShip.period.1 = 0.9; //
	refShip.period.2 = 0.4; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.2; //
	refShip.holland = 0.2; //
	refShip.portugal = 0.4; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.4; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
	refShip.Model = "Fast Galleon"; // KK
	refShip.Type.Trade 	= true;
	refShip.Type.War 	= true;

	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.8;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// <SWS - Willemstad Builders' Trials Winter 09>

	refShip.WaterLine = -1.0;
	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 31;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 6;	refShip.InertiaBrakingY		= 3;
		refShip.InertiaAccelerationZ	= 2.0;	refShip.InertiaBrakingZ		= 4.0;

	}
//
// Review: Vessel configured as:
// high seas cruiser, medium draft U-hull, moderate turn circle (WBT1)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 001> is henceforth complete
// on this day and date Sunday Dec 20 2009, 1311h
// Issues: As yet unable to influence roll factor

//-------------------------------------------------------------------------
//      Fast Galleon (FastGalleon2) by De Zeeroovers
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 002>
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "FastGalleon2";
	refShip.All 			= "Galeon1";
	refShip.id				= "FastGalleon2";
	refShip.Class		   = 3;
	refShip.SName 			= "FastGalleonW";
	refShip.Walk  = "FastGalleon"; // PB & back84
	refShip.Cannon			= CANNON_TYPE_LONG_LBS18;
	refShip.MaxCaliber		= 18;
	refShip.Weight			= Tonnes2CWT(1650);
	refShip.Capacity		= 4000;
	refShip.CannonsQuantity = 38;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	refShip.MaxCrew		 = 390;
	refShip.MinCrew		 = 45;
	refShip.Price		   = 120000;
	refShip.HP			  = 4500;
	refShip.SP			  = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 66;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 1.0; //
	refShip.period.1 = 0.9; //
	refShip.period.2 = 0.4; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.2; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.02; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
	refShip.Model = "Fast War Galleon"; // KK
	refShip.Type.Trade 	= false;
	refShip.Type.War 	= true;

	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.5;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.WaterLine = -0.7;
	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.5;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 31;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 6;	refShip.InertiaBrakingY		= 3;
		refShip.InertiaAccelerationZ	= 2.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// high seas cruiser, medium draft U-hull, moderate turn circle (WBT1)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 002> is henceforth complete
// on this day and date Sunday Dec 20 2009, 1325h

//-------------------------------------------------------------------------------------------------------------------------------------------------
//      Fast Galleon (FastGalleon3) Original FastGalleon1 by De Zeeroovers, retextured by Grey Roger using original texture file by Thomas the Terror
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 001> (WBT1)
//-------------------------------------------------------------------------------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "FastGalleon3";
	refShip.All = "Galeon1";
	refShip.id				= "FastGalleon3";
	refShip.Class		   = 3;
	refShip.SName 		= "FastGalleon";
	refShip.Walk  = "FastGalleon"; // PB & back84
	refShip.Cannon			= CANNON_TYPE_LONG_LBS9;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(1750);
	refShip.Capacity		= 5000;
	refShip.CannonsQuantity = 38;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	refShip.MaxCrew		 = 360;
	refShip.MinCrew		 = 32;
	refShip.Price		   = 110000;
	refShip.HP			  = 4000;
	refShip.SP			  = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName	= "SHIPS3"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 66;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 1.0; //
	refShip.period.1 = 0.9; //
	refShip.period.2 = 0.4; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.2; //
	refShip.holland = 0.2; //
	refShip.portugal = 0.4; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.4; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
	refShip.Model = "Fast Galleon"; // KK
	refShip.Type.Trade 	= true;
	refShip.Type.War 	= true;

	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.8;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// <SWS - Willemstad Builders' Trials Winter 09>

	refShip.WaterLine = -1.0;
	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 31;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 6;	refShip.InertiaBrakingY		= 3;
		refShip.InertiaAccelerationZ	= 2.0;	refShip.InertiaBrakingZ		= 4.0;

	}
//
// Review: Vessel configured as:
// high seas cruiser, medium draft U-hull, moderate turn circle (WBT1)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 001> is henceforth complete
// on this day and date Sunday Dec 20 2009, 1311h
// Issues: As yet unable to influence roll factor

//-------------------------------------------------------------------------------------------------------------------------------------------------
//      Fast Galleon (FastGalleon4) Original FastGalleon2 by De Zeeroovers, retextured by Grey Roger using original texture file by pirate_kk
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 001> (WBT1)
//-------------------------------------------------------------------------------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "FastGalleon4";
	refShip.All 			= "Galeon1";
	refShip.id				= "FastGalleon4";
	refShip.Class		   = 3;
	refShip.SName 			= "FastGalleonW";
	refShip.Walk  = "FastGalleon"; // PB & back84
	refShip.Cannon			= CANNON_TYPE_LONG_LBS18;
	refShip.MaxCaliber		= 18;
	refShip.Weight			= Tonnes2CWT(1650);
	refShip.Capacity		= 4000;
	refShip.CannonsQuantity = 38;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	refShip.MaxCrew		 = 390;
	refShip.MinCrew		 = 45;
	refShip.Price		   = 120000;
	refShip.HP			  = 4500;
	refShip.SP			  = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName	= "SHIPS3"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 66;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 1.0; //
	refShip.period.1 = 0.9; //
	refShip.period.2 = 0.4; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.03; //
	refShip.spain = 0.5; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
	refShip.Model = "Fast War Galleon"; // KK
	refShip.Type.Trade 	= false;
	refShip.Type.War 	= true;

	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.5;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.WaterLine = -0.7;
	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.5;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 31;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 6;	refShip.InertiaBrakingY		= 3;
		refShip.InertiaAccelerationZ	= 2.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// high seas cruiser, medium draft U-hull, moderate turn circle (WBT1)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 002> is henceforth complete
// on this day and date Sunday Dec 20 2009, 1325h

//-------------------------------------------------------------------------------------------------------------------------------------------------
//      Fast Galleon (FastGalleon5) Original FastGalleon2 by De Zeeroovers, retextured by Grey Roger based on old physical kit model
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 001> (WBT1)
//-------------------------------------------------------------------------------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "FastGalleon5";
	refShip.All 			= "Galeon1";
	refShip.id				= "FastGalleon5";
	refShip.Class		   = 3;
	refShip.SName 			= "FastGalleonW";
	refShip.Walk  = "FastGalleon"; // PB & back84
	refShip.Cannon			= CANNON_TYPE_LONG_LBS18;
	refShip.MaxCaliber		= 18;
	refShip.Weight			= Tonnes2CWT(1650);
	refShip.Capacity		= 4000;
	refShip.CannonsQuantity = 38;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	refShip.MaxCrew		 = 390;
	refShip.MinCrew		 = 45;
	refShip.Price		   = 120000;
	refShip.HP			  = 4500;
	refShip.SP			  = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName	= "SHIPS5"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 66;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.01; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.01; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
//	refShip.Model = "Fast War Galleon"; // KK
	refShip.Type.Trade 	= false;
	refShip.Type.War 	= true;

	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.5;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;

	refShip.WaterLine = -0.7;
	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.4;
		refShip.TurnRate		= 81;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.4;
		refShip.TurnRate		= 32;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 6;	refShip.InertiaBrakingY		= 3;
		refShip.InertiaAccelerationZ	= 2.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// high seas cruiser, medium draft U-hull, moderate turn circle (WBT1)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 002> is henceforth complete
// on this day and date Sunday Dec 20 2009, 1325h

//-------------------------------------------------------------------------
//  Pirate Fast Galleon (Roche Brasiliano'Ship) by Bartolomeu o Portugues
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 107> (WBT1)  - Spanish Cruiser
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "PiratFastGal";
	refShip.All 			= "Galeon1";
	refShip.id				= "PiratFastGal";
	refShip.Class		   = 3;
	refShip.SName = "FastGalleonW";
	refShip.Walk  = "FastGalleon"; // PB & back84
	refShip.Cannon			= CANNON_TYPE_CARRONADE_LBS18;
	refShip.MaxCaliber		= 18;
	refShip.Weight			= Tonnes2CWT(1650);
	refShip.Capacity		= 4000;
	refShip.CannonsQuantity = 38;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	refShip.MaxCrew		 = 390;
	refShip.MinCrew		 = 68;
	refShip.Price		   = 120000;
	refShip.HP			  = 4500;
	refShip.SP			  = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 66;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 1.0; //
	refShip.period.1 = 0.9; //
	refShip.period.2 = 0.4; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.05; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter	= false;
	refShip.CanBuy		= false;
	refShip.Model = "Fast War Galleon"; // KK
	refShip.Type.Trade 	= true;
	refShip.Type.War 	= true;

	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.5;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.WaterLine = -0.7;
	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.5;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 31;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 6;	refShip.InertiaBrakingY		= 3;
		refShip.InertiaAccelerationZ	= 2.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// high seas cruiser, medium draft U-hull, moderate turn circle (WBT1)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 107> is henceforth complete
// on this day and date 2 Jan 10, 0857h

//-------------------------------------------------------------------------
// Xebec1
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 108> (WBT2H)  - lateen "LCS"
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Xebec1";
	refShip.SName	 		= "Xebec1";
	refShip.id				= refShip.Name;
	refShip.Class			= 6;
	refShip.Cannon			= CANNON_TYPE_CARRONADE_LBS18;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity		= 1250;
	refShip.CannonsQuantity = 20;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 90;
	refShip.MinCrew		 = 18;
	refShip.Price		   = 46000;
	refShip.HP			  = 1250;
	refShip.SP			  = 200;

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 102;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.1; //
	refShip.period.4 = 0.2; //
	refShip.period.5 = 0.2; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.5; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;
	refShip.Model = "Xebec"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.3;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 90;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.4;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.0;
		refShip.TurnRate		= 55;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 15;	refShip.InertiaBrakingY		= 10;
		refShip.InertiaAccelerationZ	= 9.0;	refShip.InertiaBrakingZ		= 6.0;

	}

// Review: Vessel configured as:
// lateen ship, V-hull, moderate turn circle (WBT2H)  - littoral combatant
// no squaresail, reduced max speed to 11.5kts
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 108> is henceforth complete
// on this day and date Jan 02 2010, 0859h

//-------------------------------------------------------------------------
// Xebec2, By CatalinaThePirate, 01/03/2004
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 109> (WBT2H)  - lateen "LCS"
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Xebec2";
	refShip.All				= "Xebec1";
	refShip.SName	 		= "Xebec1";
	refShip.id				= refShip.Name;
	refShip.Class			= 6;
	refShip.Cannon			= CANNON_TYPE_CARRONADE_LBS18;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity		= 1250;
	refShip.CannonsQuantity = 20;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 90;
	refShip.MinCrew		 = 18;
	refShip.Price		   = 46000;
	refShip.HP			  = 1250;
	refShip.SP			  = 200;

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 102;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.1; //
	refShip.period.4 = 0.2; //
	refShip.period.5 = 0.2; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.5; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
	refShip.Model = "Xebec"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.3;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 90;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.4;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.0;
		refShip.TurnRate		= 55;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 15;	refShip.InertiaBrakingY		= 10;
		refShip.InertiaAccelerationZ	= 9.0;	refShip.InertiaBrakingZ		= 6.0;

	}

// Review: Vessel configured as:
// lateen ship, V-hull, moderate turn circle (WBT2H)  - littoral combatant
// no squaresail, reduced max speed to 11.5kts
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 109> is henceforth complete
// on this day and date Jan 02 2010, 0859h

//-------------------------------------------------------------------------
// Xebec Barbarossa, By Duke Surak'nar, 17/08/2003
// SWS - Heavy variant "Swordfish"
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 110> (WBT2H)  - lateen "LCS"
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name		= "Xebec3";
	refShip.All				= "Xebec1";
	if(iRealismMode>0)	refShip.SName = "XebecPir_real";
	else				refShip.SName = "XebecPir";
	refShip.Walk		= "Xebec1";
	refShip.id			= refShip.Name;
	refShip.Class		= 5;
	refShip.Cannon		= CANNON_TYPE_CARRONADE_LBS18;
	refShip.MaxCaliber	 = 9;
	refShip.Weight		= Tonnes2CWT(325);//BB was 250!? Much larger ship needed to accomodate crew increase!
	refShip.Capacity	= 1100;//BB was 1500, less cargo for crew quarters
	refShip.CannonsQuantity	= 20;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		= 150;
	refShip.MinCrew		= 30;
	refShip.Price		= 84300;//BB was 100000
	refShip.HP			= 2500;
	refShip.SP			= 200;

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 102;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.1; //
	refShip.period.4 = 0.2; //
	refShip.period.5 = 0.2; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.5; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;
	refShip.Type.Trade = false;
	refShip.Type.War = true;

// KK -->
	refShip.EmblemedSails.normalTex = "sail_barbarossa_plain.tga";
	refShip.EmblemedSails.nationFileName = "sail_barbarossa_plain.tga";
// <-- KK

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.2;
	refShip.SubSeaDependWeight = 0.2;
	refShip.TurnDependWeight = 0.4;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.0;//BB was 12.1
		refShip.TurnRate		= 100;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.5;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.5;
		refShip.TurnRate		= 55;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 15;	refShip.InertiaBrakingY		= 10;
		refShip.InertiaAccelerationZ	= 9.0;	refShip.InertiaBrakingZ		= 6.0;

	}

// Review: Vessel configured as:
// lateen ship, V-hull, moderate turn circle (WBT2H)  - littoral combatant/pirate modified for 12pdrs, larger rudder
// no squaresail, reduced max speed to 11.5kts
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 111> is henceforth complete
// on this day and date Jan 02 2010, 0938h

//-------------------------------------------------------------------------
//      Schooner Xebec (SchoonerXebec) by Captain Hawk
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 016> (WBT2H) "Grand Schooner" (Trimast)
//-------------------------------------------------------------------------

	// PS -->
	makeref(refShip,ShipsTypes[n]);
	n++;
	// PS <-- makeref(refShip,ShipsTypes[SHIP_XEBEC_FRANCE]);
	refShip.Name			= "SchoonerXebec";
	refShip.All				= "Xebec1";
	refShip.sname			= "Schooner3M";
	refShip.id				= refShip.Name; // PS
	refShip.Class			= 5;
	refShip.Cannon			= CANNON_TYPE_CARRONADE_LBS18;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity		= 1400;
	refShip.CannonsQuantity = 24;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 120;
	refShip.MinCrew		 = 24;
	refShip.Price		   = 71600;
	refShip.HP			  = 2000;
	refShip.SP			  = 200;
	// KK refShip.AbordageLocation = "BOARDING_XEBEC";

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 20;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag2 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.1; //
	refShip.period.4 = 0.2; //
	refShip.period.5 = 0.2; //
	//Nation
	refShip.england = 0.3; //
	refShip.france = 0.3; //
	refShip.holland = 0.2; //
	refShip.portugal = 0.2; //
	refShip.pirate = 0.1; //
	refShip.spain = 0.2; //
	refShip.america = 0.3; //
	refShip.sweden = 0.2; //

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.3;

//	default schooner F&A rig
	refShip.ClosestPoint = 0.15;
	refShip.BestPoint = 0.625;
	// KK refShip.RigType = sDet;


	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.0;
		refShip.TurnRate		= 75;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.4;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.0;
		refShip.TurnRate		= 55;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 15;	refShip.InertiaBrakingY		= 10;
		refShip.InertiaAccelerationZ	= 9.0;	refShip.InertiaBrakingZ		= 6.0;

	}

// Review: Vessel configured as:
// gaff rig trimast  "Grand" (heavy, 3 masted) schooner, V-hull, moderate turn circle (WBT2H)  - penalty for deep draft, higher turning circle
// no squaresail, reduced max speed to 12kts (fore and aft rigs not optimal for running, not-so-fine profile hull as smaller schooners, single-tier rigging only)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 016> is henceforth complete
// on this day and date Dec 22 2009, 2226h

//-------------------------------------------------------------------------
// XebecAS , By damski62 (locators & walkfile by ZarethPL)
// SWS - Heavy variant "Dolphin" - Quest only ship!
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 112> (WBT2H)  - lateen "LCS"
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name       = "XebecAS";
	refShip.All      = "Xebec1";
	refShip.nation	= SPAIN;
	if(iRealismMode>0)	refShip.SName = "XebecPir2_real";
	else				refShip.SName = "XebecPir2";
	refShip.walk      = "XebecAS";
	refShip.id        = refShip.Name;
	refShip.Class       = 4;
	refShip.Cannon		 = CANNON_TYPE_CARRONADE_LBS32;
	refShip.MaxCaliber	 = 18;
	refShip.Weight     = Tonnes2CWT(400);
	refShip.Capacity    = 2000;
	refShip.CannonsQuantity = 26;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	refShip.MaxCrew    = 200;
	refShip.MinCrew    = 47;
	refShip.Price       = 117800;//BB was 117600
	refShip.HP        = 3000;
	refShip.SP        = 200;
// Petros -->
	refShip.EmblemedSails.normalTex = "sail_petros_blue_white.tga";
	refShip.EmblemedSails.nationFileName = "sail_petros_blue_white.tga";
// <-- Petros

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 102;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.1; //
	refShip.period.4 = 0.2; //
	refShip.period.5 = 0.1; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.1; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = 0.5;
	refShip.SpeedDependWeight = 0.2;
	refShip.SubSeaDependWeight = 0.2;
	refShip.TurnDependWeight = 0.4;

	refShip.CanEncounter   = false;
	refShip.CanBuy		   = false;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.7;//BB was 12.75
		refShip.TurnRate		= 90;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.5;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.85;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 15;	refShip.InertiaBrakingY		= 10;
		refShip.InertiaAccelerationZ	= 9.0;	refShip.InertiaBrakingZ		= 2;

	}

// Review: Vessel configured as:
// lateen ship, V-hull, moderate turn circle (WBT2H)  - littoral combatant/pirate modified for 12pdrs, larger rudder
// no squaresail, reduced top speed
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 112> is henceforth complete
// on this day and date Jan 02 2010, 1036h

//-------------------------------------------------------------------------
// USS Enterprise by Kazeite / American Brig
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 113> (WBT2T) - HMS Interceptor model, with historical stats. Short hull - 10kts historical speed
//-------------------------------------------------------------------------
	// PS -->
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "USS_Enterprise";
	refShip.All				= "Brig1";
	refShip.SName			= "SloopUS";
	refShip.walk			= "";
	refShip.id				= refShip.Name;
	refShip.Class			= 6;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS4;
	refShip.MaxCaliber		= 4;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity		= 1000;
	refShip.CannonsQuantity = 24;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 144;
	refShip.MinCrew		 = 20;
	refShip.Price		   = 81600;
	refShip.HP			  = 2000;
	refShip.SP			  = 200;

// KK -->
	refShip.BigPicTexName = "SHIPS3"; //Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 6;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 1.0; //
	refShip.period.5 = 0.2; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.5; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;

	refShip.WaterLine = 0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.3;
	
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.5;
		refShip.TurnRate		= 105;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.4;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.8;
		refShip.TurnRate		= 37;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2) - no penalty to turning circle due to not-so-fine hull shape
// square rigger - does not handle as well upwind, compensate with stays and spanker
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 113> is henceforth complete
// on this day and date Jan 2 10, 1040h


//-------------------------------------------------------------------------
// Aurora class Frigate (RN_Corvette) - Stock corvette upgraded by Armada and Hylie Pistof
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 019> (WBT1L)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         = "RN_Corvette";
	refShip.All            = "Corvette1";
	refShip.sname      		= "FrigateL";
	refShip.id            = refShip.Name;
	refShip.Class		   = 5;
	refShip.Walk			= "Aurora";
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(600);
	refShip.Capacity		= 1500;
	refShip.CannonsQuantity = 30;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 288;
	refShip.MinCrew		 = 58;
	refShip.Price		   = 145200;
	refShip.HP			  = 2500;
	refShip.SP			  = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 72;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.7; //
	refShip.period.4 = 0.4; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.35; // Now shared with France and Spain - Armada
	refShip.france = 0.3; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.2; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
	refShip.Model = "Aurora"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = 0.2;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.55;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.5;
		refShip.TurnRate		= 40;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT1)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 019> is henceforth complete
// on this day and date Dec 24 2009, 1558h

//-------------------------------------------------------------------------
//	Corvette47 model by Sprut (SLiB) code Thomas the Terror
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 121> (WBT1L) - Corvette, French design
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Corvette47";
	refShip.sname      		= "Corvette1";
	refShip.all				= "Corvette1";
	refShip.id				= refShip.Name;
	refShip.Class			= 6;
	refShip.Walk			= "Corvette47"; // PB & back84
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(570);
	refShip.Capacity		= 1250;
	refShip.CannonsQuantity = 30;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	// NK <--
	refShip.MaxCrew		 = 270;
	refShip.MinCrew		 = 54;
	refShip.Price		   = 138000;
	refShip.HP			  = 2500;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 72;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
 	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.6; //
	refShip.period.4 = 0.5; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.2; //
	refShip.france = 0.45; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.2; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;

	refShip.WaterLine = 0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.55;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// original frigate rig
//	refShip.ClosestPoint = 0.3;
//	refShip.BestPoint = 0.8;
//	// KK refShip.RigType = sDet;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.2;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 45;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT1)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 019> is henceforth complete
// on this day and date Jan 2 10, 1749h

//-------------------------------------------------------------------------
// Aurora class Frigate (Corvette2) - Stock corvette upgraded by Armada and Hylie Pistof
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 122> (WBT1L) - Light Frigate
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Corvette2";
	refShip.All				= "Corvette1";
	refShip.sname      		= "FrigateL";
	refShip.id				= refShip.Name;
	refShip.Class		   = 5;
	refShip.Walk			= "Aurora";
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(600);
	refShip.Capacity		= 1500;
	refShip.CannonsQuantity = 30;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 288;
	refShip.MinCrew		 = 58;
	refShip.Price		   = 145200;
	refShip.HP			  = 2500;
	refShip.SP			  = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 72;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.6; //
	refShip.period.4 = 0.4; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.24; //
	refShip.france = 0.0; //
	refShip.holland = 0.2; //
	refShip.portugal = 0.2; //
	refShip.pirate = 0.01; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Aurora"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;

	refShip.WaterLine = 0.2;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.55;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.5;
		refShip.TurnRate		= 40;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT1)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 123> is henceforth complete
// on this day and date Jan 2 10, 1749h

//-------------------------------------------------------------------------
//	Pirate Corvette - Stock corvette upgraded by Armada and Hylie Pistof
//  Original skin from the SLiB mod, ported by KevAtl; modified by Armada
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 126> (WBT1L) - Pirate Light Frigate
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name		= "PiratCorvette";
	refShip.id			= refShip.Name;
	refShip.All			= "Corvette1";
	refShip.walk		= "Aurora";
	refShip.sname      		= "FrigateP";
	refShip.Class		=	5;
	refShip.Weight			= Tonnes2CWT(600);
	refShip.Capacity		= 1500;
	refShip.Cannon			= CANNON_TYPE_CARRONADE_LBS24;
	refShip.MaxCaliber	= 12;
	refShip.CannonsQuantity = 30;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	refShip.MaxCrew		= 288;
	refShip.MinCrew		= 58;
	refShip.Price	= 145200;
	refShip.HP		= 2500;
	refShip.SP		= 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 72;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
 	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.2; //
	refShip.period.4 = 0.1; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.05; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.WaterLine				= 0.2;
	refShip.SpeedDependWeight		= 0.3;
	refShip.SubSeaDependWeight	= 0.55;

	refShip.Model = "Aurora"; // KK
	refShip.Type.Trade		= false;
	refShip.Type.War 			= true;
	refShip.CanEncounter	= true;
	refShip.CanBuy 				= true;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.5;
		refShip.TurnRate		= 40;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT1)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 126> is henceforth complete
// on this day and date Jan 2 10, 1749h

//-------------------------------------------------------------------------
//  Crimson Blood - Stock corvette upgraded by Armada and Hylie Pistof
//  Original skin by Petros; modified by Armada
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 128> (WBT1L) - Light Frigate
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "CrimsonBlood";
	refShip.id				= refShip.Name;
	refShip.All				= "Corvette1";
	refShip.walk			= "Aurora";
	refShip.sname      		= "FrigateP";
	refShip.Class			= 5;
	refShip.Cannon			= CANNON_TYPE_CARRONADE_LBS24;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(600);
	refShip.Capacity		= 1500;
	refShip.CannonsQuantity = 30;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 288;
	refShip.MinCrew		 = 58;
	refShip.Price		   = 145200;
	refShip.HP			  = 2500;
	refShip.SP			  = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName = "SHIPS2"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 72;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.2; //
	refShip.period.4 = 0.1; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.05; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Aurora"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = 0.2;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.55;

	refShip.CanEncounter	= true;
	refShip.CanBuy = true;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.5;
		refShip.TurnRate		= 40;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT1)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 128> is henceforth complete
// on this day and date Jan 2 10, 1749h

//-------------------------------------------------------------------------
//  Portuguese Fast Navy by Bartolomeu o Portugues
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 135> (WBT1L) - Fragata Latina
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "PO_FastNavy";
	refShip.id				= refShip.Name;
	refShip.All				= "Corvette1";
	refShip.sname			= "FrigatePGL";
	refShip.Class			= 5;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(600);
	refShip.Capacity		= 1500;
	refShip.CannonsQuantity = 32;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	// NK <--
	refShip.MaxCrew		 = 270;
	refShip.MinCrew		 = 58;
	refShip.Price		   = 140000;
	refShip.HP			  = 2500;
	refShip.SP			  = 200;

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 72;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.3; //
	refShip.period.2 = 0.7; //
	refShip.period.3 = 0.4; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.6; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = 0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.55;

	refShip.GeraldSails.rey_b2	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.22;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.5;
		refShip.TurnRate		= 90;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.35;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.8;
		refShip.TurnRate		= 55;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT1) - lateen rig - better agility, reduced top speed
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 132> is henceforth complete
// on this day and date Jan 2 10, 1749h

//-------------------------------------------------------------------------
// Rossiya 1728 by Armada (Special thanks to Post Captain, KrisWood and SeaNorris)
// New historically accurate replacement for stock frigate and its sisters
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 017> (WBT1)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Frigate1";
	refShip.SName           		= "Frigate2";
	refShip.id				= refShip.Name;
	refShip.Walk			= "Frigate";
	refShip.Class		   = 5;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity		= 1750;
	refShip.CannonsQuantity = 36;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 378;
	refShip.MinCrew		 = 76;
	refShip.Price		   = 190200;
	refShip.HP			  = 3250;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 68;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.3; //
	refShip.period.3 = 0.4; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.3; //
	refShip.france = 0.2; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.3; //
	refShip.america = 0.0; //
	refShip.sweden = 0.2; //

	refShip.Model = "Rossiya";
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.3;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 72;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.2;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 33;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT1)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 017> is henceforth complete
// on this day and date Dec 24 2009, 0052h

//-------------------------------------------------------------------------
// US Battle Frigate (United States class Frigate) By ZarethPL
// Further model and texture work by Captain Armstrong and Armada; rigging by Hylie Pistof
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 016> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         			= "US_BattleFrigate";
	refShip.All           			= "Frigate1";
	refShip.id            			= refShip.Name;
	refShip.Walk					= "Constitution";
	refShip.SName			= "Constitution";
	refShip.Class				= 4;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber			= 24;
	refShip.Weight				= Tonnes2CWT(2200);
	refShip.Capacity			= 2500;
	refShip.CannonsQuantity			= 56;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty	= 2; // Chasers added by Armada
	refShip.Cannons.Borts.cannonb.qty	= 2;
	// NK <--
	refShip.MaxCrew				= 540;
	refShip.MinCrew				= 108;
	refShip.Price				= 282000;
	refShip.HP				= 5500;
	refShip.SP				= 200;

	refShip.BigPicTexName = "SHIPS4"; //Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 34;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";

	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.8; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.32; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.Model = "Frigate"; //Armada

	refShip.WaterLine = -0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;
	
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;	

// Constitution has significant amount of stays, and a very deep draft keel leading to superior performance upwind
	refShip.ClosestPoint = 0.25;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 65;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 30;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// Review: Vessel configured as:
// high seas cruiser, heavy, deep draft V-hull, moderate turn circle (WBT1H)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 016> is henceforth complete
// on this day and date Dec 23 2009, 0325h

//-------------------------------------------------------------------------
// USS Constitution (United States class Frigate) by ZarethPL
// Further model and texture work by Captain Armstrong and Armada; rigging by Hylie Pistof
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 016> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         			= "USS_Constitution";
	refShip.All           			= "Frigate1";
	refShip.nation					= AMERICA;
	refShip.id            			= refShip.Name;
	refShip.Walk					= "Constitution";
	refShip.SName				= "Constitution";
	refShip.Class				= 4;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber			= 24;
	refShip.Weight				= Tonnes2CWT(2200);
	refShip.Capacity			= 2500;
	refShip.CannonsQuantity			= 56;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty	= 2; // Chasers added by Armada
	refShip.Cannons.Borts.cannonb.qty	= 2;
	// NK <--
	refShip.MaxCrew				= 540;
	refShip.MinCrew				= 108;
	refShip.Price				= 282000;
	refShip.HP				= 5500;
	refShip.SP				= 200;

	refShip.BigPicTexName = "SHIPS4"; //Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 34;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";

	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
	refShip.Flags.UseNavalFlag = true;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.8; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.32; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter	= false;
	refShip.CanBuy		= false;
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.Model = "Frigate"; //Armada

	refShip.WaterLine = -0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;
	
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;

// Constitution has significant amount of stays, and a very deep draft keel leading to superior performance upwind
	refShip.ClosestPoint = 0.25;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 65;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 30;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// Review: Vessel configured as:
// high seas cruiser, heavy, deep draft V-hull, moderate turn circle (WBT1H)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 016> is henceforth complete
// on this day and date Dec 23 2009, 0325h

//-------------------------------------------------------------------------
// Iceni Queen (based on United States class Frigate by ZarethPL)
// Further model and texture work by Captain Armstrong and Armada; rigging by Hylie Pistof
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         		= "SuperFrigate";
	refShip.All           		= "Frigate1";
	refShip.id            		= refShip.Name;
	refShip.Walk				= "Constitution";
	refShip.SName				= "SuperFrigate";
	refShip.Class				= 4;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS18;
	refShip.MaxCaliber			= 18;
	refShip.Weight				= Tonnes2CWT(2500);
	refShip.Capacity			= 3500;
	refShip.CannonsQuantity			= 54;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty	= 2; // Chasers added by Armada
	refShip.Cannons.Borts.cannonb.qty	= 2;
	// NK <--
	refShip.MaxCrew				= 540;
	refShip.MinCrew				= 108;
	refShip.Price				= 300000;
	refShip.HP				= 5000;
	refShip.SP				= 200;

	refShip.BigPicTexName = "SHIPS4"; //Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 34;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";

	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.8; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 0.32; //
	refShip.france = 0.32; //
	refShip.holland = 0.32; //
	refShip.portugal = 0.25; //
	refShip.pirate = 0.1; //
	refShip.spain = 0.25; //
	refShip.america = 0.32; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter	= false;
	refShip.CanBuy		= false;
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.Model = "SuperFrigate"; //Armada

	refShip.WaterLine = -0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;
	
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;

// Has significant amount of stays, and a very deep draft keel leading to superior performance upwind
	refShip.ClosestPoint = 0.25;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 14.0;
		refShip.TurnRate		= 70;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.0;
		refShip.TurnRate		= 35;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;
	}

//-------------------------------------------------------------------------
// RN Battle Frigate (Endymion class Frigate) By ZarethPL
// Further model and texture work by Captain Armstrong and Armada; rigging by Hylie Pistof
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 016> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         			= "RN_BattleFrigate";
	refShip.All           			= "Frigate1";
	refShip.id            			= refShip.Name;
	refShip.Walk					= "Constitution";
	refShip.SName			= "ConstitutionRN";
	refShip.Class				= 4;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber			= 24;
	refShip.Weight				= Tonnes2CWT(2200);
	refShip.Capacity			= 2500;
	refShip.CannonsQuantity			= 56;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty	= 2; // Chasers added by Armada
	refShip.Cannons.Borts.cannonb.qty	= 2;
	// NK <--
	refShip.MaxCrew				= 540;
	refShip.MinCrew				= 108;
	refShip.Price				= 282000;
	refShip.HP				= 5500;
	refShip.SP				= 200;

	refShip.BigPicTexName = "SHIPS3"; //Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 34;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";

	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.9; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 0.3; //
	refShip.france = 0.3; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.2; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.Model = "Frigate"; //Armada

	refShip.WaterLine = -0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;
	
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;	

// Constitution has significant amount of stays, and a very deep draft keel leading to superior performance upwind
	refShip.ClosestPoint = 0.25;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 65;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 30;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// Review: Vessel configured as:
// high seas cruiser, heavy, deep draft V-hull, moderate turn circle (WBT1H)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 016> is henceforth complete
// on this day and date Dec 23 2009, 0325h

//-------------------------------------------------------------------------
// French Battle Frigate (Artémise class Frigate) By ZarethPL
// Further model and texture work by Captain Armstrong and Armada; rigging by Hylie Pistof
//     SWS / Flushdeck Frigate / WBT4
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         			= "FR_BattleFrigate";
	refShip.All           			= "Frigate1";
	refShip.id            			= refShip.Name;
	refShip.Walk					= "Constitution";
	refShip.SName			= "ConstitutionFR";
	refShip.Class				= 4;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber			= 24;
	refShip.Weight				= Tonnes2CWT(2200);
	refShip.Capacity			= 2500;
	refShip.CannonsQuantity			= 56;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty	= 2; // Chasers added by Armada
	refShip.Cannons.Borts.cannonb.qty	= 2;
	// NK <--
	refShip.MaxCrew				= 540;
	refShip.MinCrew				= 108;
	refShip.Price				= 282000;
	refShip.HP				= 5500;
	refShip.SP				= 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 34;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";

	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.9; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.2; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.1; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.Model = "Frigate"; //Armada

	refShip.WaterLine = -0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;
	
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;	

// Constitution has significant amount of stays, and a very deep draft keel leading to superior performance upwind
	refShip.ClosestPoint = 0.25;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 65;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 30;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// Review: Vessel configured as:
// high seas cruiser, heavy, deep draft V-hull, moderate turn circle (WBT1H)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 016> is henceforth complete
// on this day and date Dec 23 2009, 0325h

//--------------------------------------------------------------------
// Rossiya 1728 by Armada - Dutch version, based on original textures by Thomas the Terror and Petros
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 137> (WBT1L)
//--------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         = "NL_Frigate47";
	refShip.All            = "Frigate1";
	refShip.walk        = "Frigate";
	refShip.SName           		= "Frigate2";
	refShip.id            = refShip.Name;
	refShip.Class		   = 5;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity		= 1750;
	refShip.CannonsQuantity = 36;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	refShip.MaxCrew		 = 378;
	refShip.MinCrew		 = 76;
	refShip.Price		   = 190200;
	refShip.HP			  = 3250;
	refShip.SP			  = 200;

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 68;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.3; //
	refShip.period.3 = 0.4; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.3; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Rossiya";
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.3;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.9;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 72;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.2;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 33;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT1)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 137> is henceforth complete
// on this day and date Jan 2 10, 2030h

//-------------------------------------------------------------------------
// Rossiya 1728 by Armada - Generic version based on original texture by Rafe Bligh
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 138> (WBT1L)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Frigate2";
	refShip.All				= "Frigate1";
	refShip.walk        = "Frigate";
	refShip.SName           		= "Frigate2";
	refShip.id				= refShip.Name;
	refShip.Class		   = 5;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity		= 1750;
	refShip.CannonsQuantity = 36;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 378;
	refShip.MinCrew		 = 76;
	refShip.Price		   = 190200;
	refShip.HP			  = 3250;
	refShip.SP			  = 200;

	refShip.BigPicTexName = "SHIPS2"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 68;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.3; //
	refShip.period.3 = 0.4; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.2; //
	refShip.france = 0.0; //
	refShip.holland = 0.2; //
	refShip.portugal = 0.3; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.2; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Rossiya";
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.3;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.9;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 72;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.2;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 33;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT1)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 138> is henceforth complete
// on this day and date Jan 2 10, 2030h

//-------------------------------------------------------------------------
// Flushdeck frigate - was HMS Indefatigable by Inzane
// Originally HMS Surprise - re-textured by Armada
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 143> (WBT1LF) Advanced Frigate
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         			= "RN_Razee";
	refShip.All				= "Frigate1";
	refShip.SName           		= "FrigateAdv";
	refShip.Walk				= "Flushdeck";
	refShip.id            			= refShip.Name;
	refShip.Class				= 5;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber			= 12;
	refShip.Weight				= Tonnes2CWT(1300);
	refShip.Capacity			= 2500;
	refShip.CannonsQuantity			= 42;
	refShip.Cannons.Borts.cannonf.qty	= 2;
	refShip.Cannons.Borts.cannonb.qty	= 2;
	refShip.MaxCrew				= 420;
	refShip.MinCrew				= 84;
	refShip.Price				= 228000;
	refShip.HP				= 5000;
	refShip.SP				= 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 38;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag2 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.1; //
	refShip.period.4 = 0.7; //
	refShip.period.5 = 0.8; //
	//Nation
	refShip.england = 0.3; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Flushdeck"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.3;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.8;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.25;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.5;
		refShip.TurnRate		= 34;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT1LF) - advanced frigate
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 143> is henceforth complete
// on this day and date Jan 2 10, 2050h

//-------------------------------------------------------------------------
// Napoleonic paint scheme for Boussole, original by Inzane, retextured by Grey Roger
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         			= "FR_Razee";
	refShip.All				= "Frigate1";
	refShip.SName           		= "FrigateAdv";
	refShip.Walk				= "Flushdeck";
	refShip.id            			= refShip.Name;
	refShip.Class				= 5;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber			= 12;
	refShip.Weight				= Tonnes2CWT(1300);
	refShip.Capacity			= 2500;
	refShip.CannonsQuantity			= 42;
	refShip.Cannons.Borts.cannonf.qty	= 2;
	refShip.Cannons.Borts.cannonb.qty	= 2;
	refShip.MaxCrew				= 420;
	refShip.MinCrew				= 84;
	refShip.Price				= 228000;
	refShip.HP				= 5000;
	refShip.SP				= 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 38;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag2 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.2; //
	refShip.period.5 = 0.8; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.3; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.1; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Flushdeck"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.3;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.8;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.25;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.5;
		refShip.TurnRate		= 34;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

//-------------------------------------------------------------------------
// Historically accurate HMS Indefatigable - new model by Martes
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         			= "HMS_Indefatigable";
	refShip.All				= "Frigate1";
	refShip.SName           		= "Indy";
	refShip.Walk				= "Indefatigable";
	refShip.id            			= refShip.Name;
	refShip.Class				= 4;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber			= 24;
	refShip.Weight				= Tonnes2CWT(2200);
	refShip.Capacity			= 2500;
	refShip.CannonsQuantity			= 48;
	refShip.Cannons.Borts.cannonf.qty	= 2;
	refShip.Cannons.Borts.cannonb.qty	= 2;
	refShip.MaxCrew				= 420;
	refShip.MinCrew				= 84;
	refShip.Price				= 428000;
	refShip.HP				= 8000;
	refShip.SP				= 200;

	refShip.BigPicTexName	= "SHIPS5"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 38;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";

	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag2 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.4; //
	//Nation
	refShip.england = 0.02; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Indy"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = -0.1; //Martes - keep this value
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.25;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 65;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 30;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

//-------------------------------------------------------------------------
// Indefatigable class razee frigate - new model by Martes
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         			= "RN_Indefatigable";
	refShip.All				= "Frigate1";
	refShip.SName           		= "Indy";
	refShip.Walk				= "Indefatigable";
	refShip.id            			= refShip.Name;
	refShip.Class				= 4;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber			= 24;
	refShip.Weight				= Tonnes2CWT(2200);
	refShip.Capacity			= 2500;
	refShip.CannonsQuantity			= 48;
	refShip.Cannons.Borts.cannonf.qty	= 2;
	refShip.Cannons.Borts.cannonb.qty	= 2;
	refShip.MaxCrew				= 420;
	refShip.MinCrew				= 84;
	refShip.Price				= 428000;
	refShip.HP				= 8000;
	refShip.SP				= 200;

	refShip.BigPicTexName	= "SHIPS5"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 38;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";

	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag2 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.4; //
	//Nation
	refShip.england = 0.15; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Indy"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = -0.1; //Martes - keep this value
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.25;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 65;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 30;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

//---------------------------------------------------------------------------
// French version of Indefatigable class razee frigate - new model by Martes
//---------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         			= "FR_Indefatigable";
	refShip.All				= "Frigate1";
	refShip.SName           		= "Indy";
	refShip.Walk				= "Indefatigable";
	refShip.id            			= refShip.Name;
	refShip.Class				= 4;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber			= 24;
	refShip.Weight				= Tonnes2CWT(2200);
	refShip.Capacity			= 2500;
	refShip.CannonsQuantity			= 48;
	refShip.Cannons.Borts.cannonf.qty	= 2;
	refShip.Cannons.Borts.cannonb.qty	= 2;
	refShip.MaxCrew				= 420;
	refShip.MinCrew				= 84;
	refShip.Price				= 428000;
	refShip.HP				= 8000;
	refShip.SP				= 200;

	refShip.BigPicTexName	= "SHIPS5"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 38;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";

	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag2 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.4; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.1; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Indy"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = -0.1; //Martes - keep this value
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.25;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 65;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 30;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

//---------------------------------------------------------------------------
// Spanish version of Indefatigable class razee frigate - new model by Martes
//---------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         			= "SP_Indefatigable";
	refShip.All				= "Frigate1";
	refShip.SName           		= "Indy";
	refShip.Walk				= "Indefatigable";
	refShip.id            			= refShip.Name;
	refShip.Class				= 4;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber			= 24;
	refShip.Weight				= Tonnes2CWT(2200);
	refShip.Capacity			= 2500;
	refShip.CannonsQuantity			= 48;
	refShip.Cannons.Borts.cannonf.qty	= 2;
	refShip.Cannons.Borts.cannonb.qty	= 2;
	refShip.MaxCrew				= 420;
	refShip.MinCrew				= 84;
	refShip.Price				= 428000;
	refShip.HP				= 8000;
	refShip.SP				= 200;

	refShip.BigPicTexName	= "SHIPS5"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 38;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";

	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag2 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.4; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.06; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Indy"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = -0.1; //Martes - keep this value
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.25;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 65;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 30;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

//-------------------------------------------------------------------------
// Generic yellow Indefatigable class razee frigate - new model by Martes
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         			= "GEN_Indefatigable";
	refShip.All				= "Frigate1";
	refShip.SName           		= "Indy";
	refShip.Walk				= "Indefatigable";
	refShip.id            			= refShip.Name;
	refShip.Class				= 4;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber			= 24;
	refShip.Weight				= Tonnes2CWT(2200);
	refShip.Capacity			= 2500;
	refShip.CannonsQuantity			= 48;
	refShip.Cannons.Borts.cannonf.qty	= 2;
	refShip.Cannons.Borts.cannonb.qty	= 2;
	refShip.MaxCrew				= 420;
	refShip.MinCrew				= 84;
	refShip.Price				= 428000;
	refShip.HP				= 8000;
	refShip.SP				= 200;

	refShip.BigPicTexName	= "SHIPS5"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 38;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";

	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag2 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.4; //
	//Nation
	refShip.england = 0.1; //
	refShip.france = 0.05; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.05; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Indy"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = -0.1; //Martes - keep this value
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.25;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 65;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 30;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

//-------------------------------------------------------------------------
// Rossiya 1728 by Armada - Pirate version "Marauder", based on original texture by Damski62
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 144> (WBT1L)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "PiratFrigateSup";
	refShip.All 			= "frigate1";
	refShip.SName           = "FrigateP";
	refShip.id				= refShip.Name;
	refShip.Walk			= "Frigate";
	refShip.Class		   = 5;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity		= 2000;
	refShip.CannonsQuantity = 36;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 378;
	refShip.MinCrew		 = 76;
	refShip.Price		   = 190200;
	refShip.HP			  = 3250;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 68;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.2; //
	refShip.period.3 = 0.2; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.05; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Rossiya";
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.3;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.Type.Trade = false;
	refShip.Type.War = true;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 72;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.2;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.5;
		refShip.TurnRate		= 34;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT1)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 144> is henceforth complete
// on this day and date 2 Jan 10, 2052h

//-------------------------------------------------------------------------
// Rossiya 1728 by Armada - Satanist version by The Nameless Pirate
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 144> (WBT1L)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "PiratFrigateSat";
	refShip.All 			= "frigate1";
	refShip.SName			= "Frigate3";
	refShip.Nation			= PIRATE;
	refShip.unique			= true;
	refShip.id			= refShip.Name;
	refShip.Walk			= "Frigate";
	refShip.Class			= 5;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS18;
	refShip.MaxCaliber		= 18;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity		= 2000;
	refShip.CannonsQuantity = 36;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew			= 410;
	refShip.MinCrew			= 80;
	refShip.Price			= 210000;
	refShip.HP			= 3800;
	refShip.SP			= 200;

	refShip.BigPicTexName	= "SHIPS5"; // Armada
// KK -->

	refShip.EmblemedSails.normalTex = "sail_whole_red_plain.tga";
	refShip.EmblemedSails.nationFileName = "sail_whole_red_plain.tga";

	refShip.BI.Tex = 16;
	refShip.BI.Pic = 68;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
// <-- KK
	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.01; //
	refShip.period.3 = 0.01; //
	refShip.period.4 = 0.01;//
	refShip.period.5 = 0.0; //

	refShip.Model = "Rossiya_Sat";
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= false;
	refShip.CanBuy			= false;

	refShip.WaterLine = 0.3;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.Type.Trade = false;
	refShip.Type.War = true;
	

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 72;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.2;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.5;
		refShip.TurnRate		= 34;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT1)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 144> is henceforth complete
// on this day and date 2 Jan 10, 2052h

//-------------------------------------------------------------------------
// Rossiya 1728 by Armada - De-Satanised version by The Nameless Pirate
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 144> (WBT1L)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "PiratFrigateExSat";
	refShip.All 			= "frigate1";
	refShip.SName			= "Frigate3";
	refShip.Nation			= PIRATE;
	refShip.unique			= true;
	refShip.id			= refShip.Name;
	refShip.Walk			= "Frigate";
	refShip.Class			= 5;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS18;
	refShip.MaxCaliber		= 18;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity		= 2000;
	refShip.CannonsQuantity = 36;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew			= 410;
	refShip.MinCrew			= 80;
	refShip.Price			= 210000;
	refShip.HP			= 3800;
	refShip.SP			= 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->

	refShip.BI.Tex = 16;
	refShip.BI.Pic = 68;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
// <-- KK
	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.01; //
	refShip.period.3 = 0.01; //
	refShip.period.4 = 0.01;//
	refShip.period.5 = 0.0; //

	refShip.Model = "Rossiya_Sat";
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= false;
	refShip.CanBuy			= false;

	refShip.WaterLine = 0.3;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.Type.Trade = false;
	refShip.Type.War = true;
	

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 72;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.2;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.5;
		refShip.TurnRate		= 34;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT1)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 144> is henceforth complete
// on this day and date 2 Jan 10, 2052h

//-------------------------------------------------------------------------
// Frigate SATANIST
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 146> (WBT1L)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Frigate_sat";
	refShip.All				= "Frigate1";
	refShip.Nation			= PIRATE;
	refShip.unique			= true;
	refShip.id				= refShip.Name;
	refShip.SName           = "Frigate3";
	refShip.walk            = "Frigate_sat"; // PB
	refShip.Class		    = 5;
	refShip.Cannon		= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(1300);
	refShip.Capacity		= 2000;
	refShip.CannonsQuantity = 42;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	// NK <--
	refShip.MaxCrew		 = 420;
	refShip.MinCrew		 = 84;
	refShip.Price		   = 216000;
	refShip.HP			  = 4000;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.EmblemedSails.normalTex = "sail_whole_red_plain.tga";
	refShip.EmblemedSails.nationFileName = "sail_whole_red_plain.tga";

	refShip.BI.Tex = 16;
	refShip.BI.Pic = 68;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast0.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.01; //
	refShip.period.3 = 0.01; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.WaterLine = 0.2;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.9;

	refShip.CanEncounter		= false;
	refShip.CanBuy			= false;
	refShip.Model 			= "FrigateSat";

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 72;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.2;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 35;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT1)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 146> is henceforth complete
// on this day and date 2 Jan 10, 2052h

//-------------------------------------------------------------------------
// Ex-Satanist Frigate - retexture of "Frigate_sat" by Grey Roger
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 146> (WBT1L)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Frigate_Ex_Sat";
	refShip.All				= "Frigate1";
	refShip.Nation			= PIRATE;
	refShip.unique			= true;
	refShip.id				= refShip.Name;
	refShip.SName           = "Frigate3";
	refShip.walk            = "Frigate_sat"; // PB
	refShip.Class		    = 5;
	refShip.Cannon		= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(1300);
	refShip.Capacity		= 2000;
	refShip.CannonsQuantity = 42;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	// NK <--
	refShip.MaxCrew		 = 420;
	refShip.MinCrew		 = 84;
	refShip.Price		   = 216000;
	refShip.HP			  = 4000;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS5"; // Armada
// KK -->

	refShip.BI.Tex = 16;
	refShip.BI.Pic = 68;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast0.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.01; //
	refShip.period.3 = 0.01; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.WaterLine = 0.2;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.9;

	refShip.CanEncounter		= false;
	refShip.CanBuy			= false;
	refShip.Model 			= "FrigateSat";

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 72;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.2;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 35;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT1)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 146> is henceforth complete
// on this day and date 2 Jan 10, 2052h

//-------------------------------------------------------------------------
// Rossiya 1728 by Armada - French version based on l'Hermione
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 148> (WBT1L)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "FR_Frigate";
	refShip.id				= refShip.Name;
	refShip.All				= "frigate1";
	refShip.SName           		= "Frigate2";
	refShip.Class		   = 5;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity		= 1750;
	refShip.CannonsQuantity = 36;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 378;
	refShip.MinCrew		 = 76;
	refShip.Price		   = 190200;
	refShip.HP			  = 3250;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 68;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.3; //
	refShip.period.3 = 0.4; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.3; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Rossiya";
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.3;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 72;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.2;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 33;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT1)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 148> is henceforth complete
// on this day and date 2 Jan 10, 2052h

//-------------------------------------------------------------------------
// Rossiya 1728 by Armada - British version with texture by Armada
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 148> (WBT1L)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "RN_Frigate";
	refShip.id				= refShip.Name;
	refShip.All				= "frigate1";
	refShip.SName           		= "Frigate2";
	refShip.Class		   = 5;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity		= 1750;
	refShip.CannonsQuantity = 36;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 378;
	refShip.MinCrew		 = 76;
	refShip.Price		   = 190200;
	refShip.HP			  = 3250;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 68;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.3; //
	refShip.period.3 = 0.4; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.3; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Rossiya";
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.3;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 72;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.2;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 33;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT1)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 148> is henceforth complete
// on this day and date 2 Jan 10, 2052h

//-------------------------------------------------------------------------
// La Boussole original model by Inzane/retexturing and model tweaks by Seb
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 153> (WBT1L) - advanced frigate
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         			= "FR_Boussole";
	refShip.All				= "Frigate1";
	refShip.SName           		= "FrigateAdv";
	refShip.id            			= refShip.Name;
	refShip.Class				= 5;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber			= 12;
	refShip.Weight				= Tonnes2CWT(1000);
	refShip.Capacity			= 2500;
	refShip.CannonsQuantity			= 42;
	refShip.Cannons.Borts.cannonf.qty	= 2;
	refShip.Cannons.Borts.cannonb.qty	= 2;
	refShip.MaxCrew				= 420;
	refShip.MinCrew				= 84;
	refShip.Price				= 228000;
	refShip.HP				= 5000;
	refShip.SP				= 200;
	refShip.Walk 				= "Flushdeck";

	refShip.BigPicTexName	= "SHIPS2"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 38;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag2 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.3; //
	refShip.period.4 = 0.5; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.3; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Flushdeck"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.3;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.8;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.25;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.5;
		refShip.TurnRate		= 34;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT1LF) - advanced frigate
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 153> is henceforth complete
// on this day and date Jan 2 10, 2050h

//-----------------------START ADDED BY VERRUCKT---------------------------
// Lineship1
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 157> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Lineship1";
	refShip.id				= refShip.Name;
	refShip.walk			= "Lineship";
	refShip.All				= "NL_FleutWar";
	refShip.SName			= "SoL4R1";
	refShip.Class			= 5;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber		= 24;
	refShip.Weight			= Tonnes2CWT(1600);
	refShip.Capacity		= 2500;
	refShip.CannonsQuantity = 40;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	// NK <--
	refShip.MaxCrew			= 400;
	refShip.MinCrew			= 80;
	refShip.Price			= 220000;
	refShip.HP				= 5000;
	refShip.SP				= 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 32;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast5.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.3; //
	refShip.period.4 = 0.4; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.2; //
	refShip.france = 0.2; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.2; //
	refShip.america = 0.2; //
	refShip.sweden = 0.0; //

	refShip.Model = "Lineship"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.9;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.8;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 11.0;
		refShip.TurnRate		= 32;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 157> is henceforth complete
// on this day and date Jan 1 2010, 1046h

//-------------------------------------------------------------------------
// WARSHIP1
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 166> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "PO_Warship";
	refShip.id				= refShip.Name;
	refShip.walk			= "Warship";
	refShip.All				= "Lineship1";
	refShip.SName			= "SoL4R2";
	refShip.Class			= 4;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber		= 24;
	refShip.Weight			= Tonnes2CWT(1700);
	refShip.Capacity		= 2500;
	refShip.CannonsQuantity = 44;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	// NK <--
	refShip.MaxCrew 		= 440;
	refShip.MinCrew 		= 88;
	refShip.Price			= 248000;
	refShip.HP				= 6000;
	refShip.SP				= 200;

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 32;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast0.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.3; //
	refShip.period.5 = 0.4; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.15; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Warship"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.9;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.8;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 11.0;
		refShip.TurnRate		= 32;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 166> is henceforth complete
// on this day and date Jan 1 2010, 1046h

//-------------------------------------------------------------------------
// Swedish East Indiaman by Philipjn, ported by Armada
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 087> (WBT4)
//-------------------------------------------------------------------------
    makeref(refShip,ShipsTypes[n]);
    n++;
    refShip.Name            = "SwedishIndiaman1";
    refShip.All                = "Fleut1";
    refShip.SName             = "Indiaman1";
    refShip.id                = refShip.Name;
    refShip.Walk            = "";
    refShip.Class           = 4;
    refShip.Cannon            = CANNON_TYPE_LONG_LBS12;
    refShip.MaxCaliber        = 12;
    refShip.Weight            = Tonnes2CWT(1100);
    refShip.Capacity        = 4500;
    refShip.CannonsQuantity = 32;
    // NK cannon qtys 05-04-18 -->
    refShip.Cannons.Borts.cannonf.qty = 0;
    refShip.Cannons.Borts.cannonb.qty = 2;
    // NK <--
    refShip.MaxCrew         = 170;
    refShip.MinCrew         = 40
    refShip.Price           = 75000;
    refShip.HP              = 3000;
    refShip.SP              = 200;
    refShip.Jetty            = false; // PB

    refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
    refShip.BI.Tex = 16;
    refShip.BI.Pic = 116;
    refShip.QDeck = "ShipDeck6";
    refShip.CannonsDeck = 1;
    refShip.CargoHold = 1;
    refShip.Cabin = "Cabin2";
    refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
    refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.3; //
	refShip.period.3 = 0.2; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.5; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.3; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.5; //

	refShip.Model = "SwedishIndiaman"; // KK
	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
	refShip.Type.Trade		= true;
	refShip.Type.War		= false;

	refShip.WaterLine		= 0.3;
	refShip.SpeedDependWeight	= 0.3;
	refShip.SubSeaDependWeight	= 0.9;
	refShip.TurnDependWeight	= 0.8;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.7;
		refShip.TurnRate		= 65;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.8;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 11.5;
		refShip.TurnRate		= 30;
		refShip.InertiaAccelerationX = 0.2;		refShip.InertiaBrakingX = 2.0;
		refShip.InertiaAccelerationY = 7;		refShip.InertiaBrakingY = 6;
		refShip.InertiaAccelerationZ = 4.0;		refShip.InertiaBrakingZ = 2.0;
	}

// Review: Vessel configured as: East Indiaman
// high seas cruiser, deep draft V-hull, better turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 159> is henceforth complete
// on this day and date Jan 2 2010, 1146h

//-------------------------------------------------------------------------
// Batavia by Yo Ho Ho and Thomas the Terror, based on original texture by Petros
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 159> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "NL_Batavia";
	refShip.sname      		= "Indiaman1L";
	refShip.id				= refShip.Name;
	refShip.All				= "Fleut1";
	refShip.walk			= "";
	refShip.Class			= 4;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS18;
	refShip.MaxCaliber		= 18;
	refShip.Weight			= Tonnes2CWT(1050);
	refShip.Capacity		= 2500;
	refShip.CannonsQuantity		= 28;

	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;

	refShip.MaxCrew			= 200;
	refShip.MinCrew			= 54;

	refShip.Price           = 140800;
	refShip.HP              = 5000;
	refShip.SP              = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 70;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag2 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.2; //
	refShip.period.2 = 0.3; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.3; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
	refShip.Type.Trade		= true;
	refShip.Type.War		= true;

	refShip.WaterLine		= 0.3;
	refShip.SpeedDependWeight	= 0.3;
	refShip.SubSeaDependWeight	= 0.9;
	refShip.TurnDependWeight	= 0.8;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.2;//BB was 10.25
		refShip.TurnRate		= 65;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.8;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 11.0;
		refShip.TurnRate		= 30;
		refShip.InertiaAccelerationX = 0.2;		refShip.InertiaBrakingX = 2.0;
		refShip.InertiaAccelerationY = 7;		refShip.InertiaBrakingY = 6;
		refShip.InertiaAccelerationZ = 4.0;		refShip.InertiaBrakingZ = 2.0;

	}

// Review: Vessel configured as: East Indiaman
// high seas cruiser, deep draft V-hull, better turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 159> is henceforth complete
// on this day and date Jan 2 2010, 1146h

//-------------------------------------------------------------------------
// Bartolomeu's ship (Santiago) by Bartolomeu o Portugues
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 160> (WBT1L) Caravela Latina
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "FastCaravel";
	refShip.All 			= "Caravel1";
	if(iRealismMode>0)	refShip.SName = "Caravel1_real";
	else				refShip.SName = "Caravel1";
	refShip.id				= refShip.Name;
	refShip.Walk		 = "CARAVEL2";
	refShip.unique				= true;
	refShip.Nation			= PORTUGAL;
	refShip.Class		   = 5;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS6;
	refShip.MaxCaliber		= 6;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity		= 3000;
	refShip.CannonsQuantity 	= 32;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	// NK <--
	refShip.MaxCrew		 = 120;
	refShip.MinCrew		 = 24;
	refShip.Price		   = 50000;
	refShip.HP			  = 2500;
	refShip.SP			  = 200;
// KK -->
	refShip.EmblemedSails.normalTex = "sail_whole_red_plain.tga";
	refShip.EmblemedSails.nationFileName = "sail_whole_red_pirate6.tga";

	refShip.BigPicTexName = "SHIPS1"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 82;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast5.Flag1 = FLAG_PENNANT;
// <-- KK

	refShip.CanEncounter	= false;
	refShip.CanBuy		= false;
//	refShip.Model = "Caravel"; // KK
	refShip.Type.Trade 		= true;
	refShip.Type.War		= false;

	refShip.WaterLine = -0.2;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.5;

	refShip.GeraldSails.rey_a2  = 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.2;//BB way too fast vs other Caravels(even for a 'fast caravel')?(was 14.0!)
		refShip.TurnRate		= 65;
        refShip.InertiaAccelerationX    = 6;    refShip.InertiaBrakingX         = 0.4;
        refShip.InertiaAccelerationY    = 2.5;  refShip.InertiaBrakingY         = 0.5;
        refShip.InertiaAccelerationZ    = 2.5;  refShip.InertiaBrakingZ         = 2.0;
	}else{
		refShip.SpeedRate		= 14.0;
		refShip.TurnRate		= 45;
        refShip.InertiaAccelerationX    = 0.2;  refShip.InertiaBrakingX         = 2.0;
        refShip.InertiaAccelerationY    = 6;    refShip.InertiaBrakingY         = 4;
        refShip.InertiaAccelerationZ    = 3.0;  refShip.InertiaBrakingZ         = 3.0;
	}

	refShip.ClosestPoint = 0.20;
	refShip.BestPoint = 0.65;
	refShip.RigType = "Xeb";

// Review: Vessel configured as: "WBT1 Light mod 2" - Caravela Latina (lateen rig, Portuguese 4 masted caravel used throughout the Colonial period)
// small high seas cruiser, deep draft V-hull, moderate turn circle (WBT1); despite smaller displacement from WBT1, turning radii is larger than other small vessels due to deep draft V // (oceanic) hull
// she has a weak rudder response due to small hydroplane area making it challenging to judge her yaw axis momentum
// Lateen rig, vastly improved upwind capability, slightly reduced running performance. Identical maneuverability to Hybrid (bonus for lateens already given)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 160> is henceforth complete
// on this day and date Jan 2 10, 2131h

//-------------------------------------------------------------------------
// Lineship47 by Chris Roupé and Thomas the Terror
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 165> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Lineship47";
	refShip.id				= refShip.Name;
	refShip.walk			= "Lineship";
	refShip.All				= "Lineship1";
	refShip.sname      		= "SoL4R1";
	refShip.Class			= 5;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber		= 24;
	refShip.Weight			= Tonnes2CWT(1620);
	refShip.Capacity		= 2500;
	refShip.CannonsQuantity = 40;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	// NK <--
	refShip.MaxCrew			= 400;
	refShip.MinCrew			= 80;
	refShip.Price			= 220000;
	refShip.HP				= 5000;
	refShip.SP				= 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 32;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast5.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.3; //
	refShip.period.4 = 0.4; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.2; //
	refShip.france = 0.2; //
	refShip.holland = 0.2; //
	refShip.portugal = 0.1; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.05; //

	refShip.Model = "Lineship"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.9;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.8;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 11.0;
		refShip.TurnRate		= 32;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

	refShip.RigType = "Bat";

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 165> is henceforth complete
// on this day and date Jan 1 2010, 1046h

//-------------------------------------------------------------------------
//     Royal Navy 52-Gun Ship of the Line- skinned by Seb, then Armada; coded by Thomas the Terror
//		Extra guns and details added by Armada
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 167> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "RN_Warship";
	refShip.id				= refShip.Name;
	refShip.All				= "Lineship1";
	refShip.SName			= "SoL4R2";
	refShip.walk			= "Warship";
	refShip.Class			= 4; // Not a 3rd Rate as name suggests!
	refShip.Cannon			= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber		= 24;
	refShip.Weight			= Tonnes2CWT(1700);
	refShip.Capacity		= 2500;
	refShip.CannonsQuantity = 52;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	// NK <--
	refShip.MaxCrew 		= 440;
	refShip.MinCrew 		= 88;
	refShip.Price			= 248000;
	refShip.HP				= 6000;
	refShip.SP				= 200;

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 50;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast0.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.3; //
	refShip.period.5 = 0.3; //
	//Nation
	refShip.england = 0.15; //
	refShip.france = 0.1; //
	refShip.holland = 0.1; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.9;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.8;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 11.0;
		refShip.TurnRate		= 32;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

	refShip.RigType = "Bat";

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 167> is henceforth complete
// on this day and date Jan 1 2010, 1046h

//-------------------------------------------------------------------------
//	SP_Warship Warship - Skin by Seb coded by KevAtl 10-15-2007
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 170> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "SP_Warship";
	refShip.id				= refShip.Name;
	refShip.All				= "Lineship1";
	refShip.SName			= "SoL4R2";
	refShip.walk			= "Warship";
	refShip.Class			= 5;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber	= 24;
	refShip.Weight			= Tonnes2CWT(1800);
	refShip.Capacity		= 2500;
	refShip.CannonsQuantity = 44;

	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;

	refShip.MaxCrew   = 440;
	refShip.MinCrew   = 88;
	refShip.Price = 248000;
	refShip.HP    = 6000;
	refShip.SP    = 200;

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 32;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast0.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.3; //
	refShip.period.5 = 0.3; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.1; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.2; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Warship"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.9;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.8;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 11.0;
		refShip.TurnRate		= 32;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

	refShip.RigType = "Bat";

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 162> is henceforth complete
// on this day and date Jan 1 2010, 1046h


//-------------------------------------------------------------------------
// Seven Provincien by Yo Ho Ho
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 175> (WBT4)  - War Pinnace
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "NL_SevenProvincien";
	refShip.id				= refShip.Name;
	refShip.All				= "Pinnace1";
	refShip.SName			= "PinnaceWH";
	refShip.walk			= "Pinnace1"; // PB
	refShip.Class           = 1;
	refShip.Cannon          = CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber      = 24;
	refShip.Weight			= Tonnes2CWT(1300);
	refShip.Capacity        = 5000;
	refShip.CannonsQuantity = 58;

	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 6;

	refShip.MaxCrew         = 580;
	refShip.MinCrew         = 116;
	refShip.Price           = 288000;
	refShip.HP              = 7000;
	refShip.SP              = 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 54;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag2 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 1.0; //
	refShip.period.2 = 0.8; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.3; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;

	refShip.Type.Trade		= true;
	refShip.Type.War		= true;

	refship.WaterLine = 0.5;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 8.5;
		refShip.TurnRate		= 45;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.6;
		refShip.TurnRate		= 29;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 3.0;

	}

	refShip.RigType = "Bat";

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, moderate turn circle (WBT4H)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 0175> is henceforth complete
// on this day and date Jan 1 2010, 1046h

//-------------------------------------------------------------------------
// Dutch Lineship model by Yo Ho Ho - texture by Thomas the Terror
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 176> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "NL_Lineship";
	refShip.id				= refShip.Name;
	refShip.walk			= "Dutchlineship1";
	refShip.All				= "NL_FleutWar";
	refShip.SName			= "SoL4R4";
	refShip.Class			= 4;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber		= 24;
	refShip.Weight			= Tonnes2CWT(2000);
	refShip.Capacity		= 2750;
	refShip.CannonsQuantity = 60;
	refShip.Cannons.Borts.cannonf.qty = 4;
	refShip.Cannons.Borts.cannonb.qty = 4;
	refShip.MaxCrew 		= 600;
	refShip.MinCrew 		= 120;
	refShip.Price			= 336000;
	refShip.HP				= 8000;
	refShip.SP				= 200;

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 54;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.2; //
	refShip.period.2 = 0.5; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.4; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = -0.45;
	refShip.SpeedDependWeight = 0.4;
	refShip.SubSeaDependWeight = 1.15;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.8;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 11.0;
		refShip.TurnRate		= 32;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

	refShip.RigType = "Bat";

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 162> is henceforth complete
// on this day and date Jan 1 2010, 1046h

//-------------------------------------------------------------------------
// Wappen von Hamburg by Yo Ho Ho
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 177> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "NL_ConvoiShip";
	refShip.id				= refShip.Name;
	refShip.SName			= "Convoiship";
	refShip.All				= "NL_FleutWar";
	refShip.walk			= "Dutchlineship1";
	refShip.Class           = 4;
	refShip.Cannon          = CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber      = 24;
	refShip.Weight			= Tonnes2CWT(2250);
	refShip.Capacity        = 2750;
	refShip.CannonsQuantity = 60;

	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;

	refShip.MaxCrew         = 600;
	refShip.MinCrew         = 120;
	refShip.Price           = 336000;
	refShip.HP              = 8000;
	refShip.SP              = 200;

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 54;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.2; //
	refShip.period.2 = 0.5; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.3; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter	= true;
	refShip.CanBuy			= true;

	refShip.Type.Trade		= false;
	refShip.Type.War		= true;

	refship.WaterLine = -0.5;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.8;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 11.0;
		refShip.TurnRate		= 32;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

	refShip.RigType = "Bat";

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 177> is henceforth complete
// on this day and date Jan 1 2010, 1046h

//-------------------------------------------------------------------------
// Amsterdam (Spiegelretourschip) by Doober and Kazeite
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 180> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "NL_Amsterdam";
	refShip.id				= refShip.Name;
	refShip.SName			= "Amsterdam";
	refShip.All				= "Frigate1";
	refShip.Class			= 3;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS18;
	refShip.MaxCaliber		= 18;
	refShip.Weight			= Tonnes2CWT(1100);
	refShip.Capacity		= 4000;
	refShip.CannonsQuantity = 46;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	// NK <--
	refShip.Walk			= "Amsterdam"; // SeaNorris
	refShip.MaxCrew			= 414;
	refShip.MinCrew			= 83;
	refShip.Price			= 199600;
	refShip.HP				= 4000;
	refShip.SP				= 200;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 50;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag2 = FLAG_ENSIGN;
	refShip.Flags.UseMerchantFlag = true;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.8; //
	refShip.period.4 = 0.4; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.25; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade		= true;
	refShip.Type.War		= true;

	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = -0.3;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.6;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.0;
		refShip.TurnRate		= 70;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.2;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.0;
		refShip.TurnRate		= 35;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT1)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 180> is henceforth complete
// on this day and date Jan 2 10, 2030h

//-------------------------------------------------------------------------
// Battleship1 - 70-Gun 3rd Rate
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 212> (WBT4XL)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Battleship1";
	refShip.id				= refShip.Name;
	refShip.SName			= "SoL3R2";
	refShip.walk			= "Battleship1"; // PB
	refShip.Class			= 3;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber		= 24;

	refShip.Weight			= Tonnes2CWT(2500);
	refShip.Capacity		= 3000;
	refShip.CannonsQuantity = 70;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	// NK <--
	refShip.MaxCrew		 = 700;
	refShip.MinCrew		 = 140;
	refShip.Price		   = 400000;
	refShip.HP			  = 10000;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 86;
	refShip.QDeck = "ShipDeck2";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin1";
	refShip.Flags.Mast1.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag2 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.3; //
	refShip.period.3 = 0.2; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.1; //
	refShip.france = 0.1; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Battleship"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.75;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.55;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 1.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, LARGE turn circle (WBT4XL)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 212> is henceforth complete
// on this day and date Jan 1 2010, 1711h

//-------------------------------------------------------------------------
// Battleship2
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 213> (WBT4XL)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Battleship2";
	refShip.id				= refShip.Name;
	refShip.All				= "Battleship1"; // PB
	refShip.SName				= "SoL3R2";
	refShip.Class		   = 3;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber	  = 24;
	refShip.Weight			= Tonnes2CWT(2500);
	refShip.Capacity		= 3000;
	refShip.CannonsQuantity = 70;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	// NK <--
	refShip.MaxCrew		 = 700;
	refShip.MinCrew		 = 140;
	refShip.Price		   = 400000;
	refShip.HP			  = 10000;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 86;
	refShip.QDeck = "ShipDeck2";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin1";
	refShip.Flags.Mast5.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast1.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.3; //
	refShip.period.2 = 0.2; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.1; //
	refShip.france = 0.1; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.1; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.1; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Battleship"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.75;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.55;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 1.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, LARGE turn circle (WBT4XL)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 096> is henceforth complete
// on this day and date Jan 1 2010, 1711h

//----------------------Muddymonkey---------------------------------------------------
// Early Battleship by Seb, adapted to stock game hull by Armada
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 181> (WBT4XL)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         = "Battleship3";
	refShip.All				= "Battleship1"; // PB
	refShip.SName				= "SoL3R2";
	refShip.id            = refShip.Name;
	refShip.Class		   = 3;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber	  = 24;
	refShip.Weight			= Tonnes2CWT(2500);
	refShip.Capacity		= 3000;
	refShip.CannonsQuantity = 70;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	// NK <--
	refShip.MaxCrew		 = 700;
	refShip.MinCrew		 = 140;
	refShip.Price		   = 400000;
	refShip.HP			  = 10000;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 86;
	refShip.QDeck = "ShipDeck2";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin1";
	refShip.Flags.Mast1.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag2 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.3; //
	refShip.period.3 = 0.1; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.1; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Battleship"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = -0.5;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.55;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 1.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, LARGE turn circle (WBT4XL)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 096> is henceforth complete
// on this day and date Jan 1 2010, 1711h

//-------------------------------------------------------------------------
//	Battleship 6 - Skin by Seb  Code by KevAtl 10-15-2007
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 183> (WBT4XL)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name       = "RN_Battleship";
	refShip.All				= "Battleship1"; // PB
	refShip.SName				= "SoL3R2";
	refShip.id         = refShip.Name;
	refShip.Class      = 3;

	refShip.Cannon     = CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber = 24;
	refShip.Weight     = Tonnes2CWT(2500);
	refShip.Capacity   = 3000;

	refShip.CannonsQuantity = 70;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;

	refShip.MaxCrew    = 700;
	refShip.MinCrew    = 140;
	refShip.Price = 400000;
	refShip.HP    = 10000;
	refShip.SP    = 200;

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 86;
	refShip.QDeck = "ShipDeck2";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin1";
	refShip.Flags.Mast1.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag2 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.3; //
	refShip.period.3 = 0.2; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.1; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Battleship"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = -0.5;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.55;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 1.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, LARGE turn circle (WBT4XL)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 096> is henceforth complete
// on this day and date Jan 1 2010, 1711h


//-------------------------------------------------------------------------
// Spanish (red pattern) battleship by Jesus of Bonaire
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 185> (WBT4XL)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         			= "SP_Battleship";
	refShip.SName				= "SoL3R2";
	refShip.id            			= refShip.Name;
	refShip.All				= "Battleship1";
	refShip.Class		   		= 3;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber	  		= 24;
	refShip.Weight				= Tonnes2CWT(2800);
	refShip.Capacity			= 3000;
	refShip.CannonsQuantity 		= 70;
	refShip.Cannons.Borts.cannonf.qty 	= 2;
	refShip.Cannons.Borts.cannonb.qty 	= 4;
	refShip.MaxCrew		 		= 700;
	refShip.MinCrew		 		= 140;
	refShip.Price		   		= 400000;
	refShip.HP			 	= 10000;
	refShip.SP			  	= 200;

	refShip.BigPicTexName	= "SHIPS3"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 86;
	refShip.QDeck = "ShipDeck2";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin1";
	refShip.Flags.Mast1.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag2 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.3; //
	refShip.period.3 = 0.2; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.1; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Battleship"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = -0.5;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.55;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 1.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, LARGE turn circle (WBT4XL)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 096> is henceforth complete
// on this day and date Jan 1 2010, 1711h

//-------------------------------------------------------------------------
// Battleship4 by Maximus, reskinned and resurrected by Grey Roger
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 193> (WBT4XL)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			 = "Battleship4";
	refShip.SName				= "SoL3R4";
	refShip.All				= "Warship11";
	refShip.id				 = refShip.Name;
	refShip.Class		     = 3;
	refShip.Walk			 = "Battleship4"; // PB & back84
	refShip.Cannon			 = CANNON_TYPE_LONG_LBS32;
	refShip.MaxCaliber	     = 32;
	refShip.Weight			 = Tonnes2CWT(3000);
	refShip.Capacity		 = 3250;
	refShip.CannonsQuantity  = 80;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 6;
	refShip.MaxCrew			 = 800;
	refShip.MinCrew			 = 160;
	refShip.Price			 = 464000;
	refShip.HP				 = 12000;
	refShip.SP				 = 200;

	refShip.BigPicTexName	= "SHIPS5"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 86;
	refShip.QDeck = "ShipDeck3";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin1";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0;	//
	refShip.period.1 = 0.0;//
	refShip.period.2 = 0.2;	//
	refShip.period.3 = 0.3;	//
	refShip.period.4 = 0.0;	//
	refShip.period.5 = 0.0;	//
	//Nation
	refShip.england = 0.02;	//
	refShip.france = 0.0;	//
	refShip.holland = 0.0;	//
	refShip.portugal = 0.0;	//
	refShip.pirate = 0.0;	//
	refShip.spain = 0.0;	//

	refShip.Model = "EscalatedBattleship"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = -0.5;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.9;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 1.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, LARGE turn circle (WBT4XL)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 096> is henceforth complete
// on this day and date Jan 1 2010, 1711h

//-------------------------------------------------------------------------
// Battleship4 by Maximus, original AoP colour scheme resurrected by Grey Roger
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 193> (WBT4XL)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			 = "FR_Battleship4";
	refShip.SName				= "SoL3R4";
	refShip.All				= "Warship11";
	refShip.id				 = refShip.Name;
	refShip.Class		     = 3;
	refShip.Walk			 = "Battleship4"; // PB & back84
	refShip.Cannon			 = CANNON_TYPE_LONG_LBS32;
	refShip.MaxCaliber	     = 32;
	refShip.Weight			 = Tonnes2CWT(3000);
	refShip.Capacity		 = 3250;
	refShip.CannonsQuantity  = 80;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 6;
	refShip.MaxCrew			 = 800;
	refShip.MinCrew			 = 160;
	refShip.Price			 = 464000;
	refShip.HP				 = 12000;
	refShip.SP				 = 200;

	refShip.BigPicTexName	= "SHIPS5"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 86;
	refShip.QDeck = "ShipDeck3";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin1";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0;	//
	refShip.period.1 = 0.0;//
	refShip.period.2 = 0.2;	//
	refShip.period.3 = 0.3;	//
	refShip.period.4 = 0.0;	//
	refShip.period.5 = 0.0;	//
	//Nation
	refShip.england = 0.00;	//
	refShip.france = 0.03;	//
	refShip.holland = 0.0;	//
	refShip.portugal = 0.0;	//
	refShip.pirate = 0.0;	//
	refShip.spain = 0.0;	//

	refShip.Model = "EscalatedBattleship"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = -0.5;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.9;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 1.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, LARGE turn circle (WBT4XL)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 096> is henceforth complete
// on this day and date Jan 1 2010, 1711h

//-------------------------------------------------------------------------
// Battleship4 by Maximus, Spanish version by Grey Roger
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 193> (WBT4XL)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			 = "SP_Battleship4";
	refShip.SName				= "SoL3R4";
	refShip.All				= "Warship11";
	refShip.id				 = refShip.Name;
	refShip.Class		     = 3;
	refShip.Walk			 = "Battleship4"; // PB & back84
	refShip.Cannon			 = CANNON_TYPE_LONG_LBS32;
	refShip.MaxCaliber	     = 32;
	refShip.Weight			 = Tonnes2CWT(3000);
	refShip.Capacity		 = 3250;
	refShip.CannonsQuantity  = 80;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 6;
	refShip.MaxCrew			 = 800;
	refShip.MinCrew			 = 160;
	refShip.Price			 = 464000;
	refShip.HP				 = 12000;
	refShip.SP				 = 200;

	refShip.BigPicTexName	= "SHIPS5"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 86;
	refShip.QDeck = "ShipDeck3";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin1";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0;	//
	refShip.period.1 = 0.0;//
	refShip.period.2 = 0.2;	//
	refShip.period.3 = 0.3;	//
	refShip.period.4 = 0.0;	//
	refShip.period.5 = 0.0;	//
	//Nation
	refShip.england = 0.0;	//
	refShip.france = 0.0;	//
	refShip.holland = 0.0;	//
	refShip.portugal = 0.0;	//
	refShip.pirate = 0.0;	//
	refShip.spain = 0.02;	//

	refShip.Model = "EscalatedBattleship"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = -0.5;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.9;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 1.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, LARGE turn circle (WBT4XL)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 096> is henceforth complete
// on this day and date Jan 1 2010, 1711h

//-------------------------------------------------------------------------
//      British Warship by Thomas the Terror
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 188> (WBT4XL)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "RN_SuperiorWarship";
	refShip.id			= refShip.Name;
	refShip.All				= "PO_Warship";
	refShip.SName				= "RN_SuperiorWarship";
	refShip.walk			= "Battleship1"; // PB
	refShip.Class			= 3;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber		= 24;
	refShip.Weight			= Tonnes2CWT(3000);
	refShip.Capacity		= 3250;
	refShip.CannonsQuantity = 74;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	// NK <--
	refShip.MaxCrew		 = 740;
	refShip.MinCrew		 = 148;
	refShip.Price		   = 428000;
	refShip.HP			  = 11000;
	refShip.SP			  = 200;
//	refShip.RigType = "Fri";

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 50;
	refShip.QDeck = "ShipDeck2";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin1";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag2 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.2; //
	refShip.period.5 = 0.3; //
	//Nation
	refShip.england = 0.15; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Third Rate"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.7;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.9;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 1.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, LARGE turn circle (WBT4XL)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 096> is henceforth complete
// on this day and date Jan 1 2010, 1711h

//-------------------------------------------------------------------------
//      French Warship by Jesus of Bonaire
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 189> (WBT4XL)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name				= "FR_SuperiorWarship";
	refShip.id				= refShip.Name;
	refShip.All				= "PO_Warship";
	refShip.walk			= "Battleship1"; // PB
	refShip.SName				= "FR_Warship2";
	refShip.Class				= 3;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber			= 24;
	refShip.Weight				= Tonnes2CWT(3000);
	refShip.Capacity			= 3250;
	refShip.CannonsQuantity 		= 74;
	refShip.Cannons.Borts.cannonf.qty 	= 2;
	refShip.Cannons.Borts.cannonb.qty 	= 4;
	refShip.MaxCrew		 		= 740;
	refShip.MinCrew		 		= 148;
	refShip.Price		   		= 428000;
	refShip.HP			  	= 11000;
	refShip.SP			  	= 200;
//	refShip.RigType 			= "Fri";

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 50;
	refShip.QDeck = "ShipDeck2";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin1";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag2 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.2; //
	refShip.period.5 = 0.3; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.15; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Third Rate"; // Armada
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = -0.8;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.9;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 1.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, LARGE turn circle (WBT4XL)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 096> is henceforth complete
// on this day and date Jan 1 2010, 1711h

//-------------------------------------------------------------------------
//      Superior Warship by Kazeite (Armada- changed to 17th Century advanced battleship, used as Belette)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 191> (WBT4XL)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "FR_Belette";
	refShip.id			= refShip.Name;
	refShip.All				= "PO_Warship";
	refShip.SName				= "FR_Warship1";
	refShip.walk			= "Battleship1"; // PB
	refShip.Class			= 3;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber		= 24;
	refShip.Weight			= Tonnes2CWT(3000);
	refShip.Capacity		= 3250;
	refShip.CannonsQuantity = 74;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	// NK <--
	refShip.MaxCrew		 = 740;
	refShip.MinCrew		 = 148;
	refShip.Price		   = 428000;
	refShip.HP			  = 11000;
	refShip.SP			  = 200;
	refShip.RigType = "Fri";

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 86;
	refShip.QDeck = "ShipDeck2";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin1";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refship.Flags.Mast0.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.2; //
	refShip.period.3 = 0.05; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.08; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = -1.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.9;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 1.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, LARGE turn circle (WBT4XL)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 096> is henceforth complete
// on this day and date Jan 1 2010, 1711h

//-------------------------------------------------------------------------
// Heavy Lineship ("Neptune") by Yo Ho Ho
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 195> (WBT4XL)
// OMG x2
// Slowest ship in WBT
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			 = "HeavyLineship";
	refShip.SName				= "PinnaceW";
	refShip.All				= "PO_Warship";
	refShip.id				 = refShip.Name;
	refShip.Class		     = 2;
	refShip.walk			= "Pinnace1"; // PB
	refShip.Cannon			 = CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber	     = 12;
	refShip.Weight			 = Tonnes2CWT(1200);
	refShip.Capacity		 = 4000;
	refShip.CannonsQuantity  = 82;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 6;
	refShip.MaxCrew			 = 492;
	refShip.MinCrew			 = 98;
	refShip.Price			 = 236800;
	refShip.HP				 = 5000;
	refShip.SP				 = 200;
	refShip.Jetty				= false; 	//JRH

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 54;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag2 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.3; //
	refShip.period.2 = 0.4; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.2; //
	refShip.france = 0.2; //
	refShip.holland = 0.2; //
	refShip.portugal = 0.2; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.2; //
	refShip.america = 0.0; //
	refShip.sweden = 0.05; //
// <-- KK

	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.6;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.9;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 8.2;//BB was 8.25
		refShip.TurnRate		= 42;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 3.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, moderate turn circle (WBT4H) - way overloaded pinnace - handles like a XL class
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 096> is henceforth complete
// on this day and date Jan 1 2010, 1046h

//-------------------------------------------------------------------------
// HMS Endeavour - New model based on HMS Victory - by pgargon
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 196> (WBT4XL)
//-------------------------------------------------------------------------
	// PS -->
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "HMS_Endeavour";
	refShip.SName				= "Dauntless";
	refShip.id				= refShip.Name;
	refShip.Class			= 1;
	refShip.Walk			= "Endeavour";
	refShip.Nation  	= ENGLAND; //Armada
	refShip.Cannon			= CANNON_TYPE_LONG_LBS32;
	refShip.MaxCaliber		= 32;
	refShip.Weight			= Tonnes2CWT(3500);
	refShip.Capacity		= 5000;
	refShip.CannonsQuantity	= 108;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	refShip.MaxCrew			= 1080;
	refShip.MinCrew			= 210;
	refShip.Price			= 620000;
	refShip.HP				= 19000;
	refShip.SP				= 300;
// KK -->
	refShip.BigPicTexName = "SHIPS4"; //Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 22;
	refShip.QDeck				= "ShipDeck3";
	refShip.CannonsDeck			= 3;
	refShip.CargoHold			= 2;
	refShip.Cabin				= "Cabin3";
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.UseMerchantFlag = true;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.2; //
	refShip.period.4 = 0.5; //
	refShip.period.5 = 0.6; //
	//Nation
	refShip.england = 0.04; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Dauntless"; // Armada

	refShip.CanEncounter		= false;
	refShip.CanBuy				= false;

	refShip.Type.Trade 			= false;
	refShip.Type.War 			= true;

	refShip.WaterLine			= 0.0;
	refShip.SpeedDependWeight	= 0.3;
	refShip.SubSeaDependWeight	= 1.15;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 1.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, LARGE turn circle (WBT4XL)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 096> is henceforth complete
// on this day and date Jan 1 2010, 1711h

//-------------------------------------------------------------------------
// Spanish Ship of the Line - Endeavour Model from Razor, skin by Jesus of Bonaire
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 197> (WBT4XL)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name					= "SP_SotL";
	refShip.All					= "HMS_Endeavour";
	refShip.SName				= "SP_SotL";
	refShip.id					= refShip.Name;
	refShip.Class					= 2;
	refShip.Walk					= "Intrepide";
	refShip.Cannon					= CANNON_TYPE_LONG_LBS32;
	refShip.MaxCaliber				= 32;
	refShip.Weight					= Tonnes2CWT(3500);
	refShip.Capacity				= 3500;
	refShip.CannonsQuantity	= 94;
	refShip.Cannons.Borts.cannonf.qty		= 2;
	refShip.Cannons.Borts.cannonb.qty 		= 0;
	refShip.MaxCrew					= 940;
	refShip.MinCrew					= 180;
	refShip.Price					= 528000;
	refShip.HP					= 14000;
	refShip.SP					= 200;

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 22;
	refShip.QDeck				= "ShipDeck3";
	refShip.CannonsDeck			= 3;
	refShip.CargoHold			= 2;
	refShip.Cabin				= "Cabin3";
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.2; //
	refShip.period.5 = 0.5; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.04; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.Model = "Second Rate"; // KK
	refShip.Type.Trade 			= false;
	refShip.Type.War 			= true;

	refShip.WaterLine			= -0.4;
	refShip.SpeedDependWeight		= 0.3;
	refShip.SubSeaDependWeight		= 1.15;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 1.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, LARGE turn circle (WBT4XL)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 096> is henceforth complete
// on this day and date Jan 1 2010, 1711h

//-------------------------------------------------------------------------
// Intrépide by Seb
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 198> (WBT4XL)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name					= "FR_SotL";
	refShip.All					= "HMS_Endeavour";
	refShip.SName				= "FR_SotL";
	refShip.id					= refShip.Name;
	refShip.Class					= 2;
	refShip.Walk					= "Intrepide";
	refShip.Cannon					= CANNON_TYPE_LONG_LBS32;
	refShip.MaxCaliber				= 32;
	refShip.Weight					= Tonnes2CWT(3500);
	refShip.Capacity				= 3500;
	refShip.CannonsQuantity	= 94;
	refShip.Cannons.Borts.cannonf.qty		= 2;
	refShip.Cannons.Borts.cannonb.qty 		= 0;
	refShip.MaxCrew					= 940;
	refShip.MinCrew					= 180;
	refShip.Price					= 528000;
	refShip.HP					= 14000;
	refShip.SP					= 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 22;
	refShip.QDeck				= "ShipDeck3";
	refShip.CannonsDeck			= 3;
	refShip.CargoHold			= 2;
	refShip.Cabin				= "Cabin3";
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.2; //
	refShip.period.5 = 0.6; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.04; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //
	refShip.Model = "Second Rate"; // KK

	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;
	refShip.Type.Trade 			= false;
	refShip.Type.War 			= true;

	refShip.WaterLine			= 0;
	refShip.SpeedDependWeight		= 0.3;
	refShip.SubSeaDependWeight		= 1.15;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 1.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, LARGE turn circle (WBT4XL)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 096> is henceforth complete
// on this day and date Jan 1 2010, 1711h

//-------------------------------------------------------------------------
// HMS Dauntless - New model based on HMS Victory - by pgargon
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 199> (WBT4XL)
//-------------------------------------------------------------------------
	// PS -->
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "HMS_Dauntless";
	refShip.SName				= "Dauntless";
	refShip.id				= refShip.Name;
	refShip.Class			= 1;
	refShip.Walk			= "Endeavour";
	refShip.Nation  	= ENGLAND; // Armada
	refShip.Cannon             = CANNON_TYPE_LONG_LBS32;
	refShip.MaxCaliber         = 32;
	refShip.Weight             = Tonnes2CWT(3500);
	refShip.Capacity         = 5000;
	refShip.CannonsQuantity  = 102;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	refShip.MaxCrew             = 1020;
	refShip.MinCrew             = 204;
	refShip.Price             = 620000;
	refShip.HP                 = 19000;
	refShip.SP                 = 300;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 22;
	refShip.QDeck				= "ShipDeck3";
	refShip.CannonsDeck			= 3;
	refShip.CargoHold			= 2;
	refShip.Cabin				= "Cabin3";
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.UseNavalFlag = true;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.3; //
	refShip.period.4 = 0.5; //
	refShip.period.5 = 0.6; //
	//Nation
	refShip.england = 0.04; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Dauntless"; // Armada
	refShip.Type.Trade            = false;
	refShip.Type.War            = true;

	refShip.CanBuy                = false;
	refShip.CanEncounter        = false;

	refShip.WaterLine			= 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.9;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 1.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, LARGE turn circle (WBT4XL)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 096> is henceforth complete
// on this day and date Jan 1 2010, 1711h

//-------------------------------------------------------------------------
// US 2nd Rate Ship of the Line by Armada and Craiggo - based on the SotL models from Seb
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 200> (WBT4XL)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name					= "US_SotL";
	refShip.All					= "HMS_Endeavour";
	refShip.SName				= "US_SotL";
	refShip.id					= refShip.Name;
	refShip.Class					= 2;
	refShip.Walk					= "Intrepide";
	refShip.Cannon					= CANNON_TYPE_LONG_LBS32;
	refShip.MaxCaliber				= 32;
	refShip.Weight					= Tonnes2CWT(3500);
	refShip.Capacity				= 3500;
	refShip.CannonsQuantity	= 94;
	refShip.Cannons.Borts.cannonf.qty		= 2;
	refShip.Cannons.Borts.cannonb.qty 		= 0;
	refShip.MaxCrew					= 940;
	refShip.MinCrew					= 180;
	refShip.Price					= 528000;
	refShip.HP					= 14000;
	refShip.SP					= 200;

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 22;
	refShip.QDeck				= "ShipDeck3";
	refShip.CannonsDeck			= 3;
	refShip.CargoHold			= 2;
	refShip.Cabin				= "Cabin3";
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.1; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.04; //
	refShip.sweden = 0.0; //

	refShip.Model = "Second Rate"; // KK
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;
	refShip.Type.Trade 			= false;
	refShip.Type.War 			= true;

	refShip.WaterLine			= -0.4;
	refShip.SpeedDependWeight		= 0.3;
	refShip.SubSeaDependWeight		= 1.15;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 1.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, LARGE turn circle (WBT4XL)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 096> is henceforth complete
// on this day and date Jan 1 2010, 1711h

//-------------------------------------------------------------------------
// Victory by Seb [not accurate HMS Victory]
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 201> (WBT4XL)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name					= "RN_SotL";
	refShip.All					= "HMS_Endeavour";
	refShip.SName				= "RN_SotL";
	refShip.id					= refShip.Name;
	refShip.Class					= 2;
	refShip.Walk					= "Intrepide";
	refShip.Cannon					= CANNON_TYPE_LONG_LBS32;
	refShip.MaxCaliber				= 32;
	refShip.Weight					= Tonnes2CWT(3500);
	refShip.Capacity				= 3500;
	refShip.CannonsQuantity	= 94;
	refShip.Cannons.Borts.cannonf.qty		= 2;
	refShip.Cannons.Borts.cannonb.qty 		= 0;
	refShip.MaxCrew					= 940;
	refShip.MinCrew					= 180;
	refShip.Price					= 528000;
	refShip.HP					= 14000;
	refShip.SP					= 200;

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 22;
	refShip.QDeck				= "ShipDeck3";
	refShip.CannonsDeck			= 3;
	refShip.CargoHold			= 2;
	refShip.Cabin				= "Cabin3";
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.2; //
	refShip.period.5 = 0.6; //
	//Nation
	refShip.england = 0.05; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //
	refShip.Model = "Second Rate"; // KK

	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;
	refShip.Type.Trade 			= false;
	refShip.Type.War 			= true;

	refShip.WaterLine			= -0.4;
	refShip.SpeedDependWeight		= 0.3;
	refShip.SubSeaDependWeight		= 1.15;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 1.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, LARGE turn circle (WBT4XL)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 096> is henceforth complete
// on this day and date Jan 1 2010, 1711h

//-------------------------------------------------------------------------
// Manowar1
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 202> (WBT4XL)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Manowar1";
	refShip.id				= refShip.Name;
	refShip.walk			= "Manowar1";
	refShip.SName				= "SoL1R1";
	refShip.All					= "HMS_Endeavour";
	refShip.Class		   = 1;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS32;
	refShip.MaxCaliber	  = 32;
	refShip.Weight			= Tonnes2CWT(3500);
	refShip.Capacity		= 4000;
	refShip.CannonsQuantity = 100;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 8;
	// NK <--
	refShip.MaxCrew		 = 1000;
	refShip.MinCrew		 = 200;
	refShip.Price		   = 592000;
	refShip.HP			  = 16000;
	refShip.SP			  = 200;

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 118;
	refShip.QDeck = "ShipDeck3";
	refShip.CannonsDeck = 3;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin3";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag2 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.4; //
	refShip.period.3 = 0.3; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.02; //
	refShip.france = 0.02; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;
	refShip.Model = "Manowar"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = -0.5;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.9;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 1.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, LARGE turn circle (WBT4XL)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 096> is henceforth complete
// on this day and date Jan 1 2010, 1711h

//-------------------------------------------------------------------------
// Manowar2
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 203> (WBT4XL)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Manowar2";
	refShip.id				= refShip.Name;
	refShip.walk			= "Manowar2";
	refShip.SName				= "SoL1R1";
	refShip.All					= "Manowar1";
	refShip.Class		   = 1;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS32;
	refShip.MaxCaliber	  = 32;
	refShip.Weight			= Tonnes2CWT(3500);
	refShip.Capacity		= 4000;
	refShip.CannonsQuantity = 100;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 8;
	// NK <--
	refShip.MaxCrew		 = 1000;
	refShip.MinCrew		 = 200;
	refShip.Price		   = 592000;
	refShip.HP			  = 16000;
	refShip.SP			  = 200;

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 118;
	refShip.QDeck = "ShipDeck3";
	refShip.CannonsDeck = 3;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin3";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag2 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.4; //
	refShip.period.3 = 0.3; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.02; //
	refShip.france = 0.02; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Manowar"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = -0.5;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.9;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 1.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, LARGE turn circle (WBT4XL)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 096> is henceforth complete
// on this day and date Jan 1 2010, 1711h

//-------------------------------------------------------------------------
// Ship of the Line by Petros
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 204> (WBT4XL)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Manowar_gub";
	refShip.id				= refShip.Name;
	refShip.walk			= "Manowar_gub";
	refShip.SName				= "SoL1R1";
	refShip.All					= "Manowar1";
	refShip.Class		   = 1;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS32;
	refShip.MaxCaliber	  = 32;
	refShip.Weight			= Tonnes2CWT(3500);
	refShip.Capacity		= 4000;
	refShip.CannonsQuantity = 100;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 8;
	// NK <--
	refShip.MaxCrew		 = 1000;
	refShip.MinCrew		 = 200;
	refShip.Price		   = 592000;
	refShip.HP			  = 16000;
	refShip.SP			  = 200;

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 118;
	refShip.QDeck = "ShipDeck3";
	refShip.CannonsDeck = 3;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin3";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.3; //
	refShip.period.3 = 0.2; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.02; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Manowar"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = -0.9;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.9;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 1.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, LARGE turn circle (WBT4XL)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 096> is henceforth complete
// on this day and date Jan 1 2010, 1711h

//-------------------------------------------------------------------------
//			Manowar SS (SP_Manowar from SLiB) by KevAtl
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 207> (WBT4XL)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name	= "SP_Manowar";
	refShip.id		= refShip.Name;
	refShip.All					= "Manowar_gub"; // PB
	refShip.SName				= "SoL1R1";
	refShip.Class	= 1;

	refShip.Weight			= Tonnes2CWT(3000);
	refShip.Capacity		= 4000;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS32;
	refShip.MaxCaliber	= 32;

	refShip.CannonsQuantity	= 100;
	refShip.Cannons.Borts.cannonf.qty	= 2;
	refShip.Cannons.Borts.cannonb.qty	= 8;

	refShip.MaxCrew		= 1000;
	refShip.MinCrew		= 200;
	refShip.Price	= 592000;
	refShip.HP		= 16000;
	refShip.SP		= 200;

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 118;
	refShip.QDeck = "ShipDeck3";
	refShip.CannonsDeck = 3;
 	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin3";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag2 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.2; //
	refShip.period.3 = 0.3; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.02; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Manowar"; // KK
	refShip.Type.Trade	= false;
	refShip.Type.War		= true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = -1.0;
	refShip.SpeedDependWeight		= 0.3;
	refShip.SubSeaDependWeight	= 0.9;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 1.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, LARGE turn circle (WBT4XL)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 096> is henceforth complete
// on this day and date Jan 1 2010, 1711h

//  BALTIMORE STEAM PROPULSION LAB
//  BY PB, SC, NP, SWS
//-------------------------------------------------------------------------
// STEAM EXPERIMENT 1 "USS HUDSON" [ FICTIONAL SHIP ]
// New version based on the upgraded Constitution by Captain Armstrong and Armada
// WBT S/N 217X TEMPLATE 5
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;

	refShip.Name = "US_SteamFrigate";
	refShip.SName = "FrigateSteamUS";
	refShip.All		= "Frigate1";
	refShip.Nation  	= AMERICA;
	refShip.id = refShip.Name;
	refShip.Walk				= "Constitution";
	refShip.Class				= 5;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber			= 24;
	refShip.Weight				= Tonnes2CWT(3000);
	refShip.Capacity			= 1750;
	refShip.CannonsQuantity			= 46;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty	= 2;
	refShip.Cannons.Borts.cannonb.qty	= 2;
	// NK <--
	refShip.MaxCrew				= 440;
	refShip.MinCrew				= 88;
	refShip.Price				= 224000;
	refShip.HP				= 4000;
	refShip.SP				= 300;

// Steam-assisted frigate. Reduced cargo space from machinery & bunkerage, significantly increased tonnage.

	refShip.BigPicTexName = "SHIPS3"; //Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 34;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";

	refShip.Model = "Steam Frigate"; //Armada

	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.15; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.08; //
	refShip.sweden = 0.0; //

// Rare, but not unique ship in the late period.
// British experimented successfully with steam prototypes in 18th Century.

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = 0.4;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;
	
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;	

// Slightly increased maneuvrability from differential thrust options
// Constitution defaults TR = 65, yaw acceleration 1.9
// Ship sits considerably lower in the water due to increased tonnage.

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.0;
		refShip.TurnRate		= 78;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.95;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.0;
		refShip.TurnRate		= 45;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// Constitution default sails
	refShip.ClosestPoint = 0.25;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

// PB: Steam Ships -->
// Coordinates adjusted as ship is now 1.24 times larger - Armada
// Stack 1 = coal furnace exhaust
   refShip.steamship = true;
   refShip.stack1X = 0; // Width
   refShip.stack1Y = 5.58; // Height
   refShip.stack1Z = 7.44; // Length

// Smokestack 2 = boiler steam release
   refShip.stack2X = 5.58; // Width
   refShip.stack2Y = 3.1; // Height
   refShip.stack2Z = 3.2; // Length

//SWS Prop Wash
	refShip.prop1X = 7.44; // Width
    refShip.prop1Y = 0; // Height
    refShip.prop1Z = -1.86; // Length

	refShip.prop2X = -7.44; // Width
    refShip.prop2Y = 0; // Height
    refShip.prop2Z = -1.86; // Length
// PB: Steam Ships <--

// WBT S/N 217X TEMPLATE 5 USS HUDSON
// Jan 10 0000h
// Vessel configured as: Hybrid / Steam assisted, optimised for broad reach / upwind sailing
// Agility bonus from paddlewheel propulsion ; option for differential thrust

//-------------------------------------------------------------------------
// STEAM EXPERIMENT 2 "JEANNE D' ARC" [ FICTIONAL SHIP ]
// New version based on the upgraded Constitution by Captain Armstrong and Armada
// WBT S/N 218X TEMPLATE 5
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;

	refShip.Name = "FR_SteamFrigate";
	refShip.SName = "FrigateSteamFR";
	refShip.All		= "Frigate1";
	refShip.Nation  	= FRANCE;
	refShip.id = refShip.Name;
	refShip.Walk				= "Constitution";
	refShip.Class				= 5;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber			= 24;
	refShip.Weight				= Tonnes2CWT(3000);
	refShip.Capacity			= 1750;
	refShip.CannonsQuantity			= 46;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty	= 2;
	refShip.Cannons.Borts.cannonb.qty	= 2;
	// NK <--
	refShip.MaxCrew				= 440;
	refShip.MinCrew				= 88;
	refShip.Price				= 224000;
	refShip.HP				= 4000;
	refShip.SP				= 300;

// Steam-assisted frigate. Reduced cargo space from machinery & bunkerage, significantly increased tonnage.

	refShip.BigPicTexName	= "SHIPS1"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 34;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";

	refShip.Model = "Steam Frigate"; //Armada

	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.15; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.08; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

// Rare, but not unique ship in the late period.
// British experimented successfully with steam prototypes in 18th Century.
// The French created the world's first successful steam warships.

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = 0.4;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;
	
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;	

// Slightly increased maneuvrability from differential thrust options
// Constitution defaults TR = 65, yaw acceleration 1.9
// Ship sits considerably lower in the water due to increased tonnage.

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.0;
		refShip.TurnRate		= 78;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.95;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.0;
		refShip.TurnRate		= 45;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// Constitution default sails
	refShip.ClosestPoint = 0.25;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

// PB: Steam Ships -->
// Coordinates adjusted as ship is now 1.24 times larger - Armada
// Stack 1 = coal furnace exhaust
   refShip.steamship = true;
   refShip.stack1X = 0; // Width
   refShip.stack1Y = 5.58; // Height
   refShip.stack1Z = 7.44; // Length

// Smokestack 2 = boiler steam release
   refShip.stack2X = 5.58; // Width
   refShip.stack2Y = 3.1; // Height
   refShip.stack2Z = 3.2; // Length

//SWS Prop Wash
	refShip.prop1X = 7.44; // Width
    refShip.prop1Y = 0; // Height
    refShip.prop1Z = -1.86; // Length

	refShip.prop2X = -7.44; // Width
    refShip.prop2Y = 0; // Height
    refShip.prop2Z = -1.86; // Length
// PB: Steam Ships <--

// WBT S/N 218X TEMPLATE 5 JEANNE D' ARC
// Jan 10 0000h
// Vessel configured as: Hybrid / Steam assisted, optimised for broad reach / upwind sailing
// Agility bonus from paddlewheel propulsion ; option for differential thrust

//-------------------------------------------------------------------------
// STEAM EXPERIMENT 3 "HMS ASTREA" [ FICTIONAL SHIP ]
// New version based on the upgraded Constitution by Captain Armstrong and Armada
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;

	refShip.Name = "RN_SteamFrigate";
	refShip.SName = "FrigateSteamRN";
	refShip.All		= "Frigate1";
	refShip.Nation  	= ENGLAND;
	refShip.id = refShip.Name;
	refShip.Walk				= "Constitution";
	refShip.Class				= 5;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber			= 24;
	refShip.Weight				= Tonnes2CWT(3000);
	refShip.Capacity			= 1750;
	refShip.CannonsQuantity			= 46;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty	= 2;
	refShip.Cannons.Borts.cannonb.qty	= 2;
	// NK <--
	refShip.MaxCrew				= 440;
	refShip.MinCrew				= 88;
	refShip.Price				= 224000;
	refShip.HP				= 4000;
	refShip.SP				= 300;

// Steam-assisted frigate. Reduced cargo space from machinery & bunkerage, significantly increased tonnage.

	refShip.BigPicTexName = "SHIPS4"; //Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 34;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";

	refShip.Model = "Steam Frigate"; //Armada

	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.15; //
	//Nation
	refShip.england = 0.08; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

// Rare, but not unique ship in the late period.
// British experimented successfully with steam prototypes in 18th Century.

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = 0.4;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;
	
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;	

// Slightly increased maneuvrability from differential thrust options
// Constitution defaults TR = 65, yaw acceleration 1.9
// Ship sits considerably lower in the water due to increased tonnage.

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.0;
		refShip.TurnRate		= 78;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.95;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.0;
		refShip.TurnRate		= 45;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// Constitution default sails
	refShip.ClosestPoint = 0.25;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

// PB: Steam Ships -->
// Coordinates adjusted as ship is now 1.24 times larger - Armada
// Stack 1 = coal furnace exhaust
   refShip.steamship = true;
   refShip.stack1X = 0; // Width
   refShip.stack1Y = 5.58; // Height
   refShip.stack1Z = 7.44; // Length

// Smokestack 2 = boiler steam release
   refShip.stack2X = 5.58; // Width
   refShip.stack2Y = 3.1; // Height
   refShip.stack2Z = 3.2; // Length

//SWS Prop Wash
	refShip.prop1X = 7.44; // Width
    refShip.prop1Y = 0; // Height
    refShip.prop1Z = -1.86; // Length

	refShip.prop2X = -7.44; // Width
    refShip.prop2Y = 0; // Height
    refShip.prop2Z = -1.86; // Length
// PB: Steam Ships <--

//-------------------------------------------------------------------------
// STEAM EXPERIMENT 4 "KRAKEN'S REVENGE" [ EXTREMELY FICTIONAL SHIP ]
// New version based on the upgraded Constitution by Captain Armstrong and Armada, texture by Grey Roger
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;

	refShip.Name = "Pirate_SteamFrigate";
	refShip.SName = "FrigateSteamPir";
	refShip.All		= "Frigate1";
	refShip.Nation  	= ENGLAND;
	refShip.id = refShip.Name;
	refShip.Walk				= "Constitution";
	refShip.Class				= 5;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber			= 24;
	refShip.Weight				= Tonnes2CWT(3000);
	refShip.Capacity			= 1750;
	refShip.CannonsQuantity			= 46;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty	= 2;
	refShip.Cannons.Borts.cannonb.qty	= 2;
	// NK <--
	refShip.MaxCrew				= 440;
	refShip.MinCrew				= 88;
	refShip.Price				= 224000;
	refShip.HP				= 4000;
	refShip.SP				= 300;

// Steam-assisted frigate. Reduced cargo space from machinery & bunkerage, significantly increased tonnage.

	refShip.BigPicTexName = "SHIPS5"; //Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 34;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";

	refShip.Model = "Steam Frigate"; //Armada

	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.15; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.01; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

// Rare, but not unique ship in the late period.
// British experimented successfully with steam prototypes in 18th Century.

	refShip.CanEncounter	= false;
	refShip.CanBuy		= false;
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = 0.4;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;
	
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;	

// Slightly increased maneuvrability from differential thrust options
// Constitution defaults TR = 65, yaw acceleration 1.9
// Ship sits considerably lower in the water due to increased tonnage.

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.0;
		refShip.TurnRate		= 78;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.95;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.0;
		refShip.TurnRate		= 45;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// Constitution default sails
	refShip.ClosestPoint = 0.25;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

// PB: Steam Ships -->
// Coordinates adjusted as ship is now 1.24 times larger - Armada
// Stack 1 = coal furnace exhaust
   refShip.steamship = true;
   refShip.stack1X = 0; // Width
   refShip.stack1Y = 5.58; // Height
   refShip.stack1Z = 7.44; // Length

// Smokestack 2 = boiler steam release
   refShip.stack2X = 5.58; // Width
   refShip.stack2Y = 3.1; // Height
   refShip.stack2Z = 3.2; // Length

//SWS Prop Wash
	refShip.prop1X = 7.44; // Width
    refShip.prop1Y = 0; // Height
    refShip.prop1Z = -1.86; // Length

	refShip.prop2X = -7.44; // Width
    refShip.prop2Y = 0; // Height
    refShip.prop2Z = -1.86; // Length
// PB: Steam Ships <--

// BALTIMORE STEAM PROPULSION LAB END

//-------------------------------------------------------------------------
// Cursed Caravel, Reskinned PO_Caravel50 by Cylon13 (Caravela Hybrid)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 005> (WBT1 L mod 1)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "CursedCaravel";
	refShip.All 			= "Caravel1";
	refShip.SName 			= "CursedCaravel";
	refShip.walk			= "";
	refShip.unique			= true;
	refShip.id				= refShip.Name;
	refShip.Nation				= PIRATE;
	refShip.Class		   = 5;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity		= 2000;
	refShip.CannonsQuantity 	= 32;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	// NK <--
	refShip.MaxCrew		 = 200;
	refShip.MinCrew		 = 40;

	refShip.Price		   = 70000;
	refShip.HP			  = 100000;
	refShip.SP			  = 999999;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.EmblemedSails.normalTex = "sail_dutchman2.tga";
	refShip.EmblemedSails.nationFileName = "sail_dutchman2.tga";

	refShip.BI.Tex = 16;
	refShip.BI.Pic = 82;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast1.Flag1 = FLAG_NONE;
	refShip.Flags.Mast2.Flag1 = FLAG_NONE;
	refShip.Flags.Mast3.Flag1 = FLAG_NONE;
	refShip.Flags.Mast4.Flag1 = FLAG_NONE;
// <-- KK

	refShip.CanEncounter	= false;
	refShip.CanBuy		= false;
	refShip.Type.Trade 		= true;
	refShip.Type.War		= false;

	refShip.WaterLine = -0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.5;

	refShip.GeraldSails.rey_b2  = 1;
	refShip.GeraldSails.rey_b3  = 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.0;
		refShip.TurnRate		= 65;
        refShip.InertiaAccelerationX    = 6;    refShip.InertiaBrakingX         = 0.4;
        refShip.InertiaAccelerationY    = 2.5;  refShip.InertiaBrakingY         = 0.5;
        refShip.InertiaAccelerationZ    = 2.5;  refShip.InertiaBrakingZ         = 2.0;
	}else{
		refShip.SpeedRate		= 12.0;
		refShip.TurnRate		= 40;
        refShip.InertiaAccelerationX    = 0.2;  refShip.InertiaBrakingX         = 2.0;
        refShip.InertiaAccelerationY    = 6;    refShip.InertiaBrakingY         = 4;
        refShip.InertiaAccelerationZ    = 3.0;  refShip.InertiaBrakingZ         = 3.0;
	}

	refShip.ClosestPoint = 0.3;
	refShip.BestPoint = 0.8;
	refShip.RigType = "Gal";

// SWS - REFERENCE WBT1 - Fast Galleon
//	refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
//	refShip.InertiaAccelerationY	= 2;	refShip.InertiaBrakingY		= 0.5;
//	refShip.InertiaAccelerationZ	= 2.0;	refShip.InertiaBrakingZ		= 0.3;
//	refShip.TurnRate		= 80;

// Review: Vessel configured as: "WBT1 Light"
// small high seas cruiser, deep draft V-hull, moderate turn circle (WBT1); despite smaller displacement from WBT1, turning radii is larger than other small vessels due to deep draft V //(oceanic) hull
// she has a weak rudder response due to small hydroplane area making it challenging to judge her yaw axis momentum
// For all purposes this "cursed" ship should handle exactly like the light caravela.
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 005> is henceforth complete
// on this day and date Sunday Dec 20 2009, 1450h

//-------------------------------------------------------------------------
//      Cursed Flying Dutchman - By ZarethPL
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 215> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "CursedDutchman";
	refShip.SName			= "CursedDutchman";
	refShip.unique			= true;
	refShip.id				= "CursedDutchman";
	refShip.Nation			= PIRATE;
	refShip.walk			= "";
	refShip.Class			= 4;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS32;
	refShip.MaxCaliber		= 32;
	refShip.Weight			= Tonnes2CWT(2200);
	refShip.Capacity		= 4000;
	refShip.CannonsQuantity		= 56;
	refShip.Cannons.Borts.cannonf.qty = 6;
	refShip.Cannons.Borts.cannonb.qty = 4;
	refShip.Cannons.Borts.cannonl.qty = 23;
	refShip.Cannons.Borts.cannonr.qty = 23;
	refShip.MaxCrew			= 420;
	refShip.MinCrew			= 40;
	refShip.Price			= 300000;
	refShip.HP				= 100000;
	refShip.SP				= 999999;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.EmblemedSails.normalTex = "sail_dutchman2.tga";
	refShip.EmblemedSails.nationFileName = "sail_dutchman2.tga";

// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 54;
	refShip.QDeck				= "ShipDeck2";
	refShip.CannonsDeck			= 3;
	refShip.CargoHold			= 2;
	refShip.Cabin				= "CabinFDM";
// <-- KK

	refShip.CanEncounter		= false;
	refShip.CanBuy				= false;
//	refShip.Model = "Dutchman"; // KK
	refShip.Type.Trade 			= false;
	refShip.Type.War 			= true;

	refShip.WaterLine			= 0.2;
	refShip.SpeedDependWeight	= 0.4;
	refShip.SubSeaDependWeight	= 1.15;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 15.5;
		refShip.TurnRate		= 90;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.85;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 15.5;
		refShip.TurnRate		= 36;
		refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 3.0;
		refship.InertiaAccelerationY	= 2;	refship.InertiaBrakingY		= 2;
		refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 3.0;

	}

// Movement unaffected by wind - sails fastest INTO the wind
	refShip.ClosestPoint = 0.01;
	refShip.BestPoint = 0.01;
	// KK refShip.RigType = sDet;

// Review: Vessel configured as:
// Flying Dutchman
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 215> is henceforth complete
// on this day and date Jan 3 10, 1250h

//-------------------------------------------------------------------------
//      Flying Dutchman - Retextured version of ZarethPL's CursedDutchman by Armada
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 216> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "FlyingDutchman";
	refShip.Walk		 	= "FlyingDutchman";
	refShip.SName			= "FlyingDutchman";
	refShip.unique			= true;
	refShip.id				= "FlyingDutchman";
	refShip.Nation			= PIRATE;
	refShip.Class			= 4;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS32;
	refShip.MaxCaliber		= 32;
	refShip.Weight			= Tonnes2CWT(2500);
	refShip.Capacity		= 4000;
	refShip.CannonsQuantity		= 58;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 6;
	refShip.Cannons.Borts.cannonb.qty = 0;
	// NK <--
	refShip.MaxCrew			= 420;
	refShip.MinCrew			= 40;
	refShip.Price			= 300000;
	refShip.HP				= 100000;
	refShip.SP				= 999999;
// KK -->
	refShip.EmblemedSails.normalTex = "sail_dutchman1.tga";
	refShip.EmblemedSails.nationFileName = "sail_dutchman1.tga";

	refShip.BigPicTexName = "SHIPS2"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 54;
	refShip.QDeck				= "ShipDeck2";
	refShip.CannonsDeck			= 3;
	refShip.CargoHold			= 2;
	refShip.Cabin				= "Cabin2";
// <-- KK

	refShip.CanEncounter		= false;
	refShip.CanBuy				= false;
	refShip.Model = "Dutchman"; // KK
	refShip.Type.Trade 			= false;
	refShip.Type.War 			= true;

	refShip.WaterLine			= 0.2;
	refShip.SpeedDependWeight	= 0.4;
	refShip.SubSeaDependWeight	= 1.15;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 15.0;
		refShip.TurnRate		= 90;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.85;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 15.0;
		refShip.TurnRate		= 36;
		refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 3.0;
		refship.InertiaAccelerationY	= 2;	refship.InertiaBrakingY		= 2;
		refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 3.0;

	}

// Movement unaffected by wind - sails fastest INTO the wind
	refShip.ClosestPoint = 0.01;
	refShip.BestPoint = 0.01;
	// KK refShip.RigType = sDet;

// Review: Vessel configured as:
// Flying Dutchman
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 215> is henceforth complete
// on this day and date Jan 3 10, 1250h

//-------------------------------------------------------------------------
// Black Pearl by Bonjourmonami, texture by Legendary Spider
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 118> (WBT4HF)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name				= "BlackPearl";
	refShip.id					= refShip.Name;
	refShip.SName				= "GaleonPirF";
	refShip.Nation				= PIRATE;
	refShip.unique				= true;
	refShip.Class				= 5;
	refShip.Walk				= "BlackPearl";
	refShip.Cannon				= CANNON_TYPE_LONG_LBS18;
	refShip.MaxCaliber			= 24;
	refShip.Weight				= Tonnes2CWT(1000);
	refShip.Capacity			= 4500;
	refShip.CannonsQuantity		= 36;
	refShip.Cannons.Borts.cannonf.qty	= 2;
	refShip.Cannons.Borts.cannonb.qty	= 2;
	refShip.MaxCrew				= 324;
	refShip.MinCrew				= 65;
	refShip.Price				= 225000;
	refShip.HP					= 3600;
	refShip.SP					= 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.EmblemedSails.normalTex = "sail_whole_black_patch2.tga";
	refShip.EmblemedSails.nationFileName = "sail_whole_black_patch1.tga";
	refShip.night_stealth = true;	// PB: Half visibility at night

	refShip.BI.Tex = 16;
	refShip.BI.Pic = 2;
	refShip.QDeck = "ShipDeck7"; // SuperDurnius
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin4"; // Thomas the Terror
	refShip.DeckTexturesDir = "BlackPearl";
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
// <-- KK

	refShip.Model = "Black Pearl"; // KK
	refShip.Type.Trade			= true;
	refShip.Type.War			= true;

	refShip.CanBuy				= false;
	refShip.CanEncounter		= false;

	refShip.WaterLine			= -0.7;
	refShip.SpeedDependWeight	= 0.3;
	refShip.SubSeaDependWeight	= 1.0;

	refShip.Height.Bombs.Y		= 1.0;	refShip.Height.Bombs.DY = 0.5;
	refShip.Height.Grapes.Y		= 2.0;	refShip.Height.Grapes.DY = 1.0;
	refShip.Height.Knippels.Y	= 10.0;	refShip.Height.Knippels.DY = 8.0;
	refShip.Height.Balls.Y		= 1.0;	refShip.Height.Balls.DY = 0.5;

	refShip.GeraldSails.rey_a1	= 1;
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_b1	= 1;
	refShip.GeraldSails.rey_b2	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 16.0;
		refShip.TurnRate		= 77;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.75;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 16.8;
		refShip.TurnRate		= 40.1;
		refShip.InertiaAccelerationX = 0.4;	refShip.InertiaBrakingX = 2.0;
		refShip.InertiaAccelerationY = 10;	refShip.InertiaBrakingY = 4;
		refShip.InertiaAccelerationZ = 4.0;	refShip.InertiaBrakingZ = 2.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, better turn circle (WBT4HF)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 118> is henceforth complete
// on this day and date Jan 2 2010, 1727h

//-------------------------------------------------------------------------
// The Wicked Wench by Bonjourmonami, texture by Legendary Spider
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 117> (WBT4HF) - handling as English Fast Galleon
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name				= "WickedWench";
	refShip.All					= "BlackPearl";
	refShip.SName				= "GaleonEngF";
	refShip.id					= refShip.Name;
	refShip.nation				= ENGLAND;
	refShip.unique				= true;
	refShip.Class				= 5;
	refShip.Walk				= "BlackPearl";
	refShip.Cannon				= CANNON_TYPE_LONG_LBS18;
	refShip.MaxCaliber			= 18;
	refShip.Weight				= Tonnes2CWT(1100);
	refShip.Capacity			= 4500;
	refShip.CannonsQuantity		= 36;
	refShip.Cannons.Borts.cannonf.qty	= 2;
	refShip.Cannons.Borts.cannonb.qty	= 2;
	refShip.MaxCrew				= 324;
	refShip.MinCrew				= 65;
	refShip.Price				= 165600;
	refShip.HP					= 4500;
	refShip.SP					= 200;

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 16;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin3";
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.UseMerchantFlag = true;
// <-- KK

	refShip.Model = "Black Pearl"; // KK
	refShip.Type.Trade			= true;
	refShip.Type.War			= true;

	refShip.CanBuy				= false;
	refShip.CanEncounter		= false;

	refShip.WaterLine			= -0.7;
	refShip.SpeedDependWeight	= 0.3;
	refShip.SubSeaDependWeight	= 1.0;

	refShip.Height.Bombs.Y		= 1.0;	refShip.Height.Bombs.DY = 0.5;
	refShip.Height.Grapes.Y		= 2.0;	refShip.Height.Grapes.DY = 1.0;
	refShip.Height.Knippels.Y	= 10.0;	refShip.Height.Knippels.DY = 8.0;
	refShip.Height.Balls.Y		= 1.0;	refShip.Height.Balls.DY = 0.5;

	refShip.GeraldSails.rey_a1	= 1;
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_b1	= 1;
	refShip.GeraldSails.rey_b2	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 70;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.75;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 36.5;
		refShip.InertiaAccelerationX = 0.4;		refShip.InertiaBrakingX = 2.0;
		refShip.InertiaAccelerationY = 10;		refShip.InertiaBrakingY = 4;
		refShip.InertiaAccelerationZ = 4.0;		refShip.InertiaBrakingZ = 2.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, better turn circle (WBT4HF)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 117> is henceforth complete
// on this day and date Jan 2 2010, 1259h

//-------------------------------------------------------------------------
// Uncursed Black Pearl by Bonjourmonami, texture by Legendary Spider
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 119> (WBT4HF)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name				= "UncursedPearl";
	refShip.id					= refShip.Name;
	refShip.All					= "BlackPearl";
	refShip.SName				= "GaleonPirF";
	refShip.Nation				= PIRATE;
	refShip.unique				= true;
	refShip.Class				= 5;
	refShip.Walk				= "BlackPearl";
	refShip.Cannon				= CANNON_TYPE_LONG_LBS18;
	refShip.MaxCaliber			= 18;
	refShip.Weight				= Tonnes2CWT(1100);
	refShip.Capacity			= 4500;
	refShip.CannonsQuantity		= 36;
	refShip.Cannons.Borts.cannonf.qty	= 2;
	refShip.Cannons.Borts.cannonb.qty	= 2;
	refShip.MaxCrew				= 324;
	refShip.MinCrew				= 65;
	refShip.Price				= 165600;
	refShip.HP					= 4500;
	refShip.SP					= 200;
// KK -->
	refShip.EmblemedSails.normalTex = "sail_BlackPearl_whole.tga";
	refShip.EmblemedSails.nationFileName = "sail_BlackPearl_whole.tga";
	refShip.night_stealth = true;	// PB: Half visibility at night

	refShip.BigPicTexName = "SHIPS4"; //Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 2;
	refShip.QDeck = "ShipDeck7"; // SuperDurnius
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin4"; // Thomas the Terror
	refShip.DeckTexturesDir = "BlackPearl";
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
// <-- KK

	refShip.Model = "Black Pearl"; // KK
	refShip.Type.Trade			= false;
	refShip.Type.War			= true;

	refShip.CanBuy				= false;
	refShip.CanEncounter		= false;

	refShip.WaterLine			= -0.7;
	refShip.SpeedDependWeight	= 0.3;
	refShip.SubSeaDependWeight	= 1.0;

	refShip.Height.Bombs.Y		= 1.0;	refShip.Height.Bombs.DY = 0.5;
	refShip.Height.Grapes.Y		= 2.0;	refShip.Height.Grapes.DY = 1.0;
	refShip.Height.Knippels.Y	= 10.0;	refShip.Height.Knippels.DY = 8.0;
	refShip.Height.Balls.Y		= 1.0;	refShip.Height.Balls.DY = 0.5;

	refShip.GeraldSails.rey_a1	= 1;
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_b1	= 1;
	refShip.GeraldSails.rey_b2	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 70;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.75;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 36.5;
		refShip.InertiaAccelerationX = 0.4;		refShip.InertiaBrakingX = 2.0;
		refShip.InertiaAccelerationY = 10;		refShip.InertiaBrakingY = 4;
		refShip.InertiaAccelerationZ = 4.0;		refShip.InertiaBrakingZ = 2.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, better turn circle (WBT4HF)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 119> is henceforth complete
// on this day and date Jan 2 2010, 1728h

//-------------------------------------------------------------------------
// Cursed Pearl by Bonjourmonami, texture by Legendary Spider
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 120> (WBT4HF) - Faster due to removal of habitation related items
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name				= "CursedPearl";
	refShip.SName				= "CursedPearl";
	refShip.id					= SHIP_CURSED; // Fudge Dragon: Re-enable skeletons
	refShip.Nation				= PIRATE;
	refShip.unique				= true;
	refShip.Class				= 5;
	refShip.Walk				= "BlackPearl";
	refShip.Cannon				= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber			= 24;
	refShip.Weight				= Tonnes2CWT(1000);
	refShip.Capacity			= 2200;
	refShip.CannonsQuantity		= 36;
	refShip.Cannons.Borts.cannonf.qty	= 2;
	refShip.Cannons.Borts.cannonb.qty	= 2;
	refShip.MaxCrew				= 300;
	refShip.MinCrew				= 60;
	refShip.Price				= 225000;
	refShip.HP					= 100000; // stronger
// SWS: Pieter suggested a MoW should stand a chance against the Pearl
	refShip.SP					= 999999;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.EmblemedSails.normalTex = "sail_BlackPearl_torn.tga";
	refShip.EmblemedSails.nationFileName = "sail_BlackPearl_torn.tga";
	refShip.fog_trail = true;		// PB: Cursed Ship Trails Fog
	refShip.night_stealth = true;	// PB: Half visibility at night

	refShip.BI.Tex = 16;
	refShip.BI.Pic = 2;
	refShip.QDeck = "ShipDeck7"; // SuperDurnius
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin4"; // Thomas the Terror
	refShip.DeckTexturesDir = "BlackPearl";
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
// <-- KK

//	refShip.Model = "Black Pearl"; // KK
	refShip.Type.Trade			= false;
	refShip.Type.War			= true;

	refShip.CanBuy				= false;
	refShip.CanEncounter		= false;

	refShip.WaterLine			= -0.7;
	refShip.SpeedDependWeight	= 0.3;
	refShip.SubSeaDependWeight	= 1.0;

	refShip.Height.Bombs.Y		= 1.0;	refShip.Height.Bombs.DY = 0.5;
	refShip.Height.Grapes.Y		= 2.0;	refShip.Height.Grapes.DY = 1.0;
	refShip.Height.Knippels.Y	= 10.0;	refShip.Height.Knippels.DY = 8.0;
	refShip.Height.Balls.Y		= 1.0;	refShip.Height.Balls.DY = 0.5;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 16.0;
		refShip.TurnRate		= 70;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.0;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 16.8;
		refShip.TurnRate		= 36.5;
		refShip.InertiaAccelerationX = 0.4;	refShip.InertiaBrakingX = 2.0;
		refShip.InertiaAccelerationY = 10;	refShip.InertiaBrakingY = 4;
		refShip.InertiaAccelerationZ = 4.0;	refShip.InertiaBrakingZ = 2.0;

	}

// Review: Vessel configured as:  SUPERNATURAL CAPITAL SHIP - reduced inertia
// high seas cruiser, deep draft V-hull, better turn circle (WBT4HF)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 120> is henceforth complete
// on this day and date Jan 2 2010, 1728h

// HISTORICAL SHIP PACK -->
//-------------------------------------------------------------------------
// HMS Victory 1765 by pgargon (Generic version, no nameplate)
//-------------------------------------------------------------------------
// Armada -->
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "RN_FirstRate";
	refShip.id				= refShip.Name;
	refShip.SName			= "Victory";
	refShip.Walk			= "Victory";
	refShip.Class			= 1;
	refShip.Nation			= ENGLAND;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS32;
	refShip.MaxCaliber		= 32;
	refShip.Weight			= Tonnes2CWT(3500);
	refShip.Capacity		= 5000;
	refShip.CannonsQuantity = 104;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	refShip.MaxCrew		 = 1040;
	refShip.MinCrew		 = 208;
	refShip.Price		   = 624000;
	refShip.HP			  = 19000;
	refShip.SP			  = 300;

	refShip.BigPicTexName = "SHIPS3"; //Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 22;
	refShip.QDeck = "ShipDeck3";
	refShip.CannonsDeck = 3;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin3";
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.3; //
	refShip.period.5 = 0.5; //
	//Nation
	refShip.england = 0.06; //
	refShip.france = 0.03; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.02; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter = true;
	refShip.CanBuy		 = true;
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.Model = "Victory";

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.45;
	refShip.SubSeaDependWeight = 1.8;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.5;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.5;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 1.5;	refShip.InertiaBrakingX		= 1.5;
		refShip.InertiaAccelerationY	= 1.5;	refShip.InertiaBrakingY		= 1.5;
		refShip.InertiaAccelerationZ	= 1.5;	refShip.InertiaBrakingZ		= 1.5;

	}
// Armada <--

//-------------------------------------------------------------------------
// HMS Victory 1765 by pgargon (Unique version with nameplate)
// Texture by Armada
//-------------------------------------------------------------------------
// Armada -->
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "HMS_Victory";
	refShip.id				= refShip.Name;
	refShip.SName			= "Victory";
	refShip.Walk			= "Victory";
	refShip.Class			= 1;
	refShip.Nation			= ENGLAND;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS32;
	refShip.MaxCaliber		= 32;
	refShip.Weight			= Tonnes2CWT(3500);
	refShip.Capacity		= 5000;
	refShip.CannonsQuantity = 104;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	refShip.MaxCrew		 = 1040;
	refShip.MinCrew		 = 208;
	refShip.Price		   = 624000;
	refShip.HP			  = 19000;
	refShip.SP			  = 300;

	refShip.BigPicTexName = "SHIPS3"; //Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 22;
	refShip.QDeck = "ShipDeck3";
	refShip.CannonsDeck = 3;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin3";
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.UseNavalFlag = true;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.2; //
	refShip.period.4 = 0.3; //
	refShip.period.5 = 0.5; //
	//Nation
	refShip.england = 0.06; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter = false;
	refShip.CanBuy		 = false;
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.Model = "Victory";

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.45;
	refShip.SubSeaDependWeight = 1.8;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.5;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.5;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 1.5;	refShip.InertiaBrakingX		= 1.5;
		refShip.InertiaAccelerationY	= 1.5;	refShip.InertiaBrakingY		= 1.5;
		refShip.InertiaAccelerationZ	= 1.5;	refShip.InertiaBrakingZ		= 1.5;

	}
// Armada <--

//-------------------------------------------------------------------------
// US Victory by pgargon
//-------------------------------------------------------------------------
// Armada -->
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "US_FirstRate";
	refShip.id				= refShip.Name;
	refShip.SName			= "VictoryUS";
	refShip.Walk			= "Victory";
	refShip.Class			= 1;
	refShip.Nation			= AMERICA;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS32;
	refShip.MaxCaliber		= 32;
	refShip.Weight			= Tonnes2CWT(3500);
	refShip.Capacity		= 5000;
	refShip.CannonsQuantity = 104;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	refShip.MaxCrew		 = 1040;
	refShip.MinCrew		 = 208;
	refShip.Price		   = 624000;
	refShip.HP			  = 19000;
	refShip.SP			  = 300;

	refShip.BigPicTexName = "SHIPS4"; //Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 22;
	refShip.QDeck = "ShipDeck3";
	refShip.CannonsDeck = 3;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin3";
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.2; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.05; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter = true;
	refShip.CanBuy		 = true;
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.Model = "Victory";

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.45;
	refShip.SubSeaDependWeight = 1.8;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.5;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.5;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 1.5;	refShip.InertiaBrakingX		= 1.5;
		refShip.InertiaAccelerationY	= 1.5;	refShip.InertiaBrakingY		= 1.5;
		refShip.InertiaAccelerationZ	= 1.5;	refShip.InertiaBrakingZ		= 1.5;

	}
// Armada <--

//-------------------------------------------------------------------------
// FR Victory by pgargon
//-------------------------------------------------------------------------
// Armada -->
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "FR_FirstRate";
	refShip.id				= refShip.Name;
	refShip.SName			= "VictoryFR";
	refShip.Walk			= "Victory";
	refShip.Class			= 1;
	refShip.Nation			= FRANCE;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS32;
	refShip.MaxCaliber		= 32;
	refShip.Weight			= Tonnes2CWT(3500);
	refShip.Capacity		= 5000;
	refShip.CannonsQuantity = 104;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	refShip.MaxCrew		 = 1040;
	refShip.MinCrew		 = 208;
	refShip.Price		   = 624000;
	refShip.HP			  = 19000;
	refShip.SP			  = 300;

	refShip.BigPicTexName = "SHIPS3"; //Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 22;
	refShip.QDeck = "ShipDeck3";
	refShip.CannonsDeck = 3;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin3";
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.3; //
	refShip.period.5 = 0.5; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.03; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.01; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter = true;
	refShip.CanBuy		 = true;
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.Model = "Victory";

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.45;
	refShip.SubSeaDependWeight = 1.8;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.5;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.5;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 1.5;	refShip.InertiaBrakingX		= 1.5;
		refShip.InertiaAccelerationY	= 1.5;	refShip.InertiaBrakingY		= 1.5;
		refShip.InertiaAccelerationZ	= 1.5;	refShip.InertiaBrakingZ		= 1.5;

	}
// Armada <--

//-------------------------------------------------------------------------
// SP Victory by pgargon, retextured by Grey Roger
//-------------------------------------------------------------------------
// Armada -->
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "SP_FirstRate";
	refShip.id				= refShip.Name;
	refShip.SName			= "VictorySP";
	refShip.Walk			= "Victory";
	refShip.Class			= 1;
	refShip.Nation			= SPAIN;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS32;
	refShip.MaxCaliber		= 32;
	refShip.Weight			= Tonnes2CWT(3500);
	refShip.Capacity		= 5000;
	refShip.CannonsQuantity = 104;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	refShip.MaxCrew		 = 1040;
	refShip.MinCrew		 = 208;
	refShip.Price		   = 624000;
	refShip.HP			  = 19000;
	refShip.SP			  = 300;

	refShip.BigPicTexName = "SHIPS2"; //Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 22;
	refShip.QDeck = "ShipDeck3";
	refShip.CannonsDeck = 3;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin3";
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.3; //
	refShip.period.5 = 0.5; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.04; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter = true;
	refShip.CanBuy		 = true;
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.Model = "Victory";

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.45;
	refShip.SubSeaDependWeight = 1.8;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.5;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.5;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 1.5;	refShip.InertiaBrakingX		= 1.5;
		refShip.InertiaAccelerationY	= 1.5;	refShip.InertiaBrakingY		= 1.5;
		refShip.InertiaAccelerationZ	= 1.5;	refShip.InertiaBrakingZ		= 1.5;

	}
// Armada <--

//-------------------------------------------------------------------------
// Le Superbe 1784 by pgargon
//-------------------------------------------------------------------------
// Armada -->
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name				= "FR_Superbe";
	refShip.id				= refShip.Name;
	refShip.SName				= "Superbe";
	refShip.Walk				= "Superbe";
	refShip.Class				= 3;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber			= 24;
	refShip.Weight				= Tonnes2CWT(3000);
	refShip.Capacity			= 3000;
	refShip.CannonsQuantity 		= 76;
	refShip.Cannons.Borts.cannonf.qty 	= 2;
	refShip.Cannons.Borts.cannonb.qty 	= 2;
	refShip.MaxCrew		 		= 740;
	refShip.MinCrew		 		= 148;
	refShip.Price		   		= 450000;
	refShip.HP			  	= 12000;
	refShip.SP			  	= 250;

	refShip.BigPicTexName = "SHIPS4"; //Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 50;
	refShip.QDeck = "ShipDeck2";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin1";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.4; //
	refShip.period.5 = 0.5; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.2; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.2; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;
	refShip.Model = "Superbe";

	refShip.WaterLine = -0.1;
	refShip.SpeedDependWeight = 0.35;
	refShip.SubSeaDependWeight = 1;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.5;//BB was 12.5, reduced vs other class3
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 34;
		refShip.InertiaAccelerationX	= 4.0;	refShip.InertiaBrakingX		= 3.5;
		refShip.InertiaAccelerationY	= 3.0;	refShip.InertiaBrakingY		= 2.5;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 3.5;

	}
// Armada <--

//-------------------------------------------------------------------------
// Le Superbe 1784 - British version -  by pgargon
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name				= "RN_Superbe";
	refShip.id				= refShip.Name;
	refShip.SName				= "RN_Superbe";
	refShip.Walk				= "Superbe";
	refShip.Class				= 3;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber			= 24;
	refShip.Weight				= Tonnes2CWT(3000);
	refShip.Capacity			= 3000;
	refShip.CannonsQuantity 		= 76;
	refShip.Cannons.Borts.cannonf.qty 	= 2;
	refShip.Cannons.Borts.cannonb.qty 	= 2;
	refShip.MaxCrew		 		= 740;
	refShip.MinCrew		 		= 148;
	refShip.Price		   		= 450000;
	refShip.HP			  	= 12000;
	refShip.SP			  	= 250;

	refShip.BigPicTexName = "SHIPS3"; //Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 50;
	refShip.QDeck = "ShipDeck2";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin1";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.4; //
	refShip.period.5 = 0.5; //
	//Nation
	refShip.england = 0.3; //
	refShip.france = 0.3; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.3; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;
	refShip.Model = "Superbe";

	refShip.WaterLine = -0.1;
	refShip.SpeedDependWeight = 0.35;
	refShip.SubSeaDependWeight = 1;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.5;//BB was 12.5, reduced vs other class3
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 34;
		refShip.InertiaAccelerationX	= 4.0;	refShip.InertiaBrakingX		= 3.5;
		refShip.InertiaAccelerationY	= 3.0;	refShip.InertiaBrakingY		= 2.5;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 3.5;
	}

//-----------------------------------------------------------------------------------
// Le Superbe 1784 - Dutch/Portuguese version -  by pgargon, retextured by Grey Roger
//-----------------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name				= "NL_Superbe";
	refShip.id				= refShip.Name;
	refShip.SName				= "NL_Superbe";
	refShip.Walk				= "Superbe";
	refShip.Class				= 3;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber			= 24;
	refShip.Weight				= Tonnes2CWT(3000);
	refShip.Capacity			= 3000;
	refShip.CannonsQuantity 		= 76;
	refShip.Cannons.Borts.cannonf.qty 	= 2;
	refShip.Cannons.Borts.cannonb.qty 	= 2;
	refShip.MaxCrew		 		= 740;
	refShip.MinCrew		 		= 148;
	refShip.Price		   		= 450000;
	refShip.HP			  	= 12000;
	refShip.SP			  	= 250;

	refShip.BigPicTexName = "SHIPS5"; //Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 50;
	refShip.QDeck = "ShipDeck2";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin1";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.2; //
	refShip.period.5 = 0.2; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.2; //
	refShip.portugal = 0.1; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;
	refShip.Model = "Superbe";

	refShip.WaterLine = -0.1;
	refShip.SpeedDependWeight = 0.35;
	refShip.SubSeaDependWeight = 1;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.5;//BB was 12.5, reduced vs other class3
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 34;
		refShip.InertiaAccelerationX	= 4.0;	refShip.InertiaBrakingX		= 3.5;
		refShip.InertiaAccelerationY	= 3.0;	refShip.InertiaBrakingY		= 2.5;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 3.5;
	}

//-------------------------------------------------------------------------
// HMS Bellona 1760 by pgargon
//-------------------------------------------------------------------------
// Armada -->
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "HMS_Bellona";
	refShip.id			= refShip.Name;
	refShip.SName				= "Bellona";
	refShip.Walk			= "Bellona";
	refShip.Class			= 3;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber		= 24;
	refShip.Weight			= Tonnes2CWT(3250);
	refShip.Capacity		= 3000;
	refShip.CannonsQuantity = 84;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	refShip.MaxCrew		 = 840;
	refShip.MinCrew		 = 160;
	refShip.Price		  = 475000;
	refShip.HP			  = 12500;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 50;
	refShip.QDeck = "ShipDeck2";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin1";
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.1; //
	refShip.period.4 = 0.3; //
	refShip.period.5 = 0.3; //
	//Nation
	refShip.england = 0.3; //
	refShip.france = 0.2; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.2; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;
	refShip.Model = "Bellona";

	refShip.WaterLine = 0.5;
	refShip.SpeedDependWeight = 0.35;
	refShip.SubSeaDependWeight = 1;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.0;//BB was 12.5, reduced vs other class 3
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 34;
		refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 3.5;
		refship.InertiaAccelerationY	= 3.0;	refship.InertiaBrakingY		= 2.5;
		refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.5;

	}
// Armada <--

//-------------------------------------------------------------------------
// HMS Bellona 1760 - French version - by pgargon
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "FR_Bellona";
	refShip.id			= refShip.Name;
	refShip.SName				= "FR_Bellona";
	refShip.Walk			= "Bellona";
	refShip.Class			= 3;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber		= 24;
	refShip.Weight			= Tonnes2CWT(3250);
	refShip.Capacity		= 3000;
	refShip.CannonsQuantity = 84;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	refShip.MaxCrew		 = 840;
	refShip.MinCrew		 = 160;
	refShip.Price		  = 475000;
	refShip.HP			  = 12500;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 50;
	refShip.QDeck = "ShipDeck2";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin1";
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.1; //
	refShip.period.4 = 0.3; //
	refShip.period.5 = 0.3; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.2; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.1; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;
	refShip.Model = "Bellona";

	refShip.WaterLine = 0.5;
	refShip.SpeedDependWeight = 0.35;
	refShip.SubSeaDependWeight = 1;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.0;//BB was 12.5, reduced vs other class 3
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 34;
		refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 3.5;
		refship.InertiaAccelerationY	= 3.0;	refship.InertiaBrakingY		= 2.5;
		refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.5;
	}

//-------------------------------------------------------------------------
// HMS Bellona 1760 - US version - by pgargon
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "US_Bellona";
	refShip.id			= refShip.Name;
	refShip.SName				= "US_Bellona";
	refShip.Walk			= "Bellona";
	refShip.Class			= 3;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber		= 24;
	refShip.Weight			= Tonnes2CWT(3250);
	refShip.Capacity		= 3000;
	refShip.CannonsQuantity = 84;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	refShip.MaxCrew		 = 840;
	refShip.MinCrew		 = 160;
	refShip.Price		  = 475000;
	refShip.HP			  = 12500;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS3"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 50;
	refShip.QDeck = "ShipDeck2";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin1";
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.2; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.05; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;
	refShip.Model = "Bellona";

	refShip.WaterLine = 0.5;
	refShip.SpeedDependWeight = 0.35;
	refShip.SubSeaDependWeight = 1;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.0;//BB was 12.5, reduced vs other class 3
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 34;
		refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 3.5;
		refship.InertiaAccelerationY	= 3.0;	refship.InertiaBrakingY		= 2.5;
		refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.5;
	}

//-------------------------------------------------------------------------
// HMS Nonsuch 1654 by pgargon - Naval Ketch
//-------------------------------------------------------------------------
// Armada -->
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "KetchNavy";
	refShip.sname			= "Nonsuch";
	refShip.Walk			= "Nonsuch";
	refShip.id			    = refShip.Name;
	refShip.Class			= 8;
	refShip.Cannon			= CANNON_TYPE_CARRONADE_LBS12;
	refShip.MaxCaliber		= 6;
	refShip.Weight			= Tonnes2CWT(190);//BB was 100, increased based on normal Ketch + some 'hardening'
	refShip.Capacity		= 250;
	refShip.CannonsQuantity = 8;
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;
	refShip.MaxCrew			= 38;//BB was 24, increased vs normal Ketch
	refShip.MinCrew			= 8;//BB was 5
	refShip.Price			= 28600;//BB was 15600, increased vs normal Ketch
	refShip.HP				= 1000;
	refShip.SP				= 100;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.2;
	refShip.SubSeaDependWeight = 0.6;
	
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_b2	= 1;	

	refShip.BigPicTexName	= "SHIPS2"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 98;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1; // PB: No cannon deck nor cargo hold, but with a cabin does not work well
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refship.Flags.Mast1.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 1.0; //
	refShip.period.2 = 0.6; //
	refShip.period.3 = 0.1; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.1; //
	refShip.france = 0.1; //
	refShip.holland = 0.1; //
	refShip.portugal = 0.1; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.1; //
	refShip.america = 0.1; //
	refShip.sweden = 0.1; //

	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refship.InertiaAccelerationX	= 10.0;	refship.InertiaBrakingX		= 10.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 10;
	refship.InertiaAccelerationZ	= 10.0;	refship.InertiaBrakingZ		= 10.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.6;//BB was 7.0 increased vs normal Ketch
		refShip.TurnRate		= 105;//BB was 135 reduced vs normal Ketch
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 4.5;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
		}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 3.0;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 14;	refShip.InertiaBrakingY		= 5;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 3.0;

	}
// Armada <--

//-------------------------------------------------------------------------
//	HMS Greyhound 1720 by pgargon
//-------------------------------------------------------------------------
// Armada -->
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "HMS_Greyhound";
	refShip.sname      		= "Greyhound";
	refShip.id				= refShip.Name;
	refShip.Class			= 6;
	refShip.Walk			= "Greyhound";
	refShip.Cannon			= CANNON_TYPE_LONG_LBS9;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(570);
	refShip.Capacity		= 1250;
	refShip.CannonsQuantity = 22;
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 2;
	refShip.MaxCrew		 = 120;
	refShip.MinCrew		 = 24;
	refShip.Price		   = 138000;
	refShip.HP			  = 2000;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 72;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
 	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.2; //
	refShip.period.4 = 0.5; //
	refShip.period.5 = 0.3; //
	//Nation
	refShip.england = 0.45; //
	refShip.france = 0.05; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.05; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "6th_Rate"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;

	refShip.WaterLine = 0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.55;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.8;//BB was 13.2, reduced vs other class 6
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 45;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}
// Armada <--

//-------------------------------------------------------------------------
//	French version of 6th rate frigate HMS Greyhound by pgargon, modified by Grey Roger
//-------------------------------------------------------------------------
// Armada -->
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "FR_Greyhound";
	refShip.sname      		= "Greyhound";
	refShip.id				= refShip.Name;
	refShip.Class			= 6;
	refShip.Walk			= "Greyhound";
	refShip.Cannon			= CANNON_TYPE_LONG_LBS9;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(570);
	refShip.Capacity		= 1250;
	refShip.CannonsQuantity = 22;
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 2;
	refShip.MaxCrew		 = 120;
	refShip.MinCrew		 = 24;
	refShip.Price		   = 138000;
	refShip.HP			  = 2000;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 72;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
 	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.5; //
	refShip.period.5 = 0.3; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.45; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.25; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "6th_Rate"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;

	refShip.WaterLine = 0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.55;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.8;//BB was 13.2, reduced vs other class 6
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 45;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}
// Armada <--

//-------------------------------------------------------------------------
//	Portuguese version of HMS Greyhound 1720 by pgargon, modified by Grey Roger
//-------------------------------------------------------------------------
// Armada -->
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "PO_Greyhound";
	refShip.sname      		= "Greyhound";
	refShip.id				= refShip.Name;
	refShip.Class			= 6;
	refShip.Walk			= "Greyhound";
	refShip.Cannon			= CANNON_TYPE_LONG_LBS9;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(570);
	refShip.Capacity		= 1250;
	refShip.CannonsQuantity = 22;
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 2;
	refShip.MaxCrew		 = 120;
	refShip.MinCrew		 = 24;
	refShip.Price		   = 138000;
	refShip.HP			  = 2000;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 72;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
 	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.2; //
	refShip.period.4 = 0.5; //
	refShip.period.5 = 0.3; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.25; //
	refShip.portugal = 0.25; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "6th_Rate"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;

	refShip.WaterLine = 0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.55;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.8;//BB was 13.2, reduced vs other class 6
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 45;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}
// Armada <--

//-------------------------------------------------------------------------
// HMS Sophie (aka HMS Vincejo 1798) by pgargon
//-------------------------------------------------------------------------
// Armada -->
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			 = "HMS_Sophie";
	refShip.id 			 = refShip.Name;
	refShip.Walk		= "Sophie";
	refShip.sname			= "Sophie";
	refShip.All			= "Brig1";
	refShip.Class			= 7;
	refShip.Cannon		 = CANNON_TYPE_CARRONADE_LBS24;
	refShip.MaxCaliber		= 9;
	refShip.Weight 		 = Tonnes2CWT(200);
	refShip.Capacity		 = 1000;
	refShip.CannonsQuantity = 18;
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;
	refShip.MaxCrew	  = 120;
	refShip.MinCrew	  = 24;
	refShip.Price			= 69000;
	refShip.HP 		   = 1750;
	refShip.SP 		   = 200;

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;

	refShip.BigPicTexName = "SHIPS4"; //Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 6;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag2 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 1.0; //
	refShip.france = 0.3; //
	refShip.holland = 0.3; //
	refShip.portugal = 0.3; //
	refShip.pirate = 0.0; //
	refShip.spain = 1.0; //
	refShip.america = 0.2; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = 0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.2;

	refShip.Height.Bombs.Y 	 = 1.0; 	 refShip.Height.Bombs.DY	 = 1.0;
	refShip.Height.Grapes.Y	 = 2.0; 	 refShip.Height.Grapes.DY	 = 1.0;
	refShip.Height.Knippels.Y	 = 15.0;	 refShip.Height.Knippels.DY  = 10.0;
	refShip.Height.Balls.Y 	 = 1.0; 	 refShip.Height.Balls.DY	 = 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 95;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.5;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.0;
		refShip.TurnRate		= 45;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}
// Armada <--

//-------------------------------------------------------------------------
// USS Enterprise 1799 by pgargon
//-------------------------------------------------------------------------
// Armada -->
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "US_Enterprise";
	refShip.SName	 		= "Enterprise";
	refShip.id				= refShip.Name;
	refShip.Walk			= "USS_Enterprise";
	refShip.All				= "Schooner1";
	refShip.Class		   = 8;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS9;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(200);
	refShip.Capacity		= 600;
	refShip.CannonsQuantity = 14;
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;
	refShip.MaxCrew		 = 60;
	refShip.MinCrew		 = 12;
	refShip.Price		   = 46000;
	refShip.HP			  = 1500;
	refShip.SP			  = 200;

	refShip.BigPicTexName = "SHIPS3"; //Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 114;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refship.Flags.Mast3.Flag2 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refship.america = 1.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = -0.2;
	refShip.SpeedDependWeight = 0.2;
	refShip.SubSeaDependWeight = 0.2;
	
	refShip.GeraldSails.rey_b2	= 1;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 14.0;
		refShip.TurnRate		= 100;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.35;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 15.0;
		refShip.TurnRate		= 45;
		refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
		refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
		refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;

	}
// Armada <--

//-------------------------------------------------------------------------
// HMS Mordaunt 1681 by pgargon
//-------------------------------------------------------------------------
// Armada -->
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "HMS_Mordaunt";
	refShip.id				= refShip.Name;
	refShip.Walk			= "Mordaunt";
	refShip.SName			= "Mordaunt";
	refShip.all				= "PO_Warship";
	refShip.Class			= 4;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber		= 24;
	refShip.Weight			= Tonnes2CWT(1700);
	refShip.Capacity		= 3000;
	refShip.CannonsQuantity = 58;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	refShip.MaxCrew = 460;
	refShip.MinCrew = 92;
	refShip.Price = 272000;
	refShip.HP = 7000;
	refShip.SP = 200;

	refShip.BigPicTexName = "SHIPS4"; //Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 18;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.7; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.8; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.30;
	refship.TurnDependWeight = 0.8;

	refShip.GeraldSails.rey_a2 = 1;
	refShip.GeraldSails.rey_a3 = 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.2;//BB was 10.25
		refShip.TurnRate		= 65;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.8;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.2;
		refShip.TurnRate		= 36;
		refship.InertiaAccelerationX 	= 5.0; 	refship.InertiaBrakingX 	= 5.0;
		refship.InertiaAccelerationY 	= 4; 	refship.InertiaBrakingY 	= 4;
		refship.InertiaAccelerationZ 	= 5.0; 	refship.InertiaBrakingZ 	= 5.0;


	}
// Armada <--

// HISTORICAL SHIP PACK <--

// SHIP PACK 2 -->

//-------------------------------------------------------------------------
//	La Couronne 1636 by pgargon
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name				= "FR_Couronne";
	refShip.id					= refShip.Name;
	refShip.walk				= "Couronne";
	refShip.SName				= "Couronne";
	refShip.all					= "Galeon1";
	refShip.Class				= 3;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber			= 32;
	refShip.Weight				= Tonnes2CWT(2750);
	refShip.Capacity			= 3250;
	refShip.CannonsQuantity		= 64;
	refShip.Cannons.Borts.cannonf.qty = 8;
	refShip.Cannons.Borts.cannonb.qty = 8;
	refShip.MaxCrew				 = 640;
	refShip.MinCrew				 = 128;
	refShip.Price				= 364000;
	refShip.HP					= 9000;
	refShip.SP					= 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 86;
	refShip.QDeck = "ShipDeck2";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast1.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast5.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.6; //
	refShip.period.2 = 0.1; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.1; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.1;
	refShip.SpeedDependWeight = 0.35;
	refShip.SubSeaDependWeight = 0.75;

	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.5;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.8;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 11.5;
		refShip.TurnRate		= 32;
		refship.InertiaAccelerationX	= 3.5;	refship.InertiaBrakingX		= 3.0;
		refship.InertiaAccelerationY	= 2.5;	refship.InertiaBrakingY		= 2.5;
		refship.InertiaAccelerationZ	= 3.5;	refship.InertiaBrakingZ		= 3.0;

		refShip.RigType = "Bat";
	}

//-------------------------------------------------------------------------
// Apostól Felipe 1626 by pgargon
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name = "SP_ApostolFelipe";
	refShip.SName = "ApostolFelipe";
	refShip.id = refShip.Name;
	refShip.Class = 3;
	refShip.Walk = "ApostolFelipe";
	refShip.all	= "Galeon1";
	refShip.Cannon = CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber = 18;
	refShip.Weight = Tonnes2CWT(1100);
	refShip.Capacity = 4650;
	refShip.CannonsQuantity = 30;
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 2;
	refShip.MaxCrew = 260;
	refShip.MinCrew = 64;
	refShip.Price = 152800;//BB was 80000, too cheap vs others in class/performance
	refShip.HP = 5200;
	refShip.SP = 200;
	refShip.Jetty = false;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 66;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast1.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
	refship.Flags.Mast5.Flag1 = FLAG_PENNANT;

	//Period
	refShip.period.0 = 0.2; //
	refShip.period.1 = 1.0; //
	refShip.period.2 = 0.5; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.6; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter = true;
	refShip.CanBuy = true;
	refShip.Type.Trade = true;
	refShip.Type.War = true;

	refShip.WaterLine = -0.4;
	refShip.SpeedDependWeight = 0.2;
	refShip.SubSeaDependWeight = 0.5;
	refShip.TurnDependWeight = 0.45;

	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 8.0;
		refShip.TurnRate		= 45;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.8;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 8.0;
		refShip.TurnRate		= 25;
		refship.InertiaAccelerationX	= 4.5;	refship.InertiaBrakingX		= 4.5;
		refship.InertiaAccelerationY	= 3;	refship.InertiaBrakingY		= 3;
		refship.InertiaAccelerationZ	= 4.5;	refship.InertiaBrakingZ		= 4.5;

	}

//-------------------------------------------------------------------------
// Hannah 1775 by pgargon //BB a very confused ship re stats!! a light schooner
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "US_Hannah";
	refShip.SName			= "Hannah";
	refShip.id				= refShip.Name;
	refShip.Walk			= "Hannah";
	refShip.all					= "schooner1";
	refShip.Class		   = 7;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS6;//BB was LBS4
	refShip.MaxCaliber		= 6;// BB was 4
	refShip.Weight			= Tonnes2CWT(170);//BB was 150
	refShip.Capacity		= 900;//BB was 800
	refShip.CannonsQuantity = 4;
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;
	refShip.MaxCrew		 = 30;
	refShip.MinCrew		 = 9;//BB was 4
	refShip.Price		   = 16000;
	refShip.HP			  = 900;//BB was 550
	refShip.SP			  = 200;//BB was 150

	refShip.BigPicTexName	= "SHIPS2"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 114;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast1.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag2 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 1.0; //
	refShip.period.5 = 0.6; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.5; //
	refShip.holland = 0.5; //
	refShip.portugal = 0.5; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.6; //
	refShip.america = 0.7; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = true;
	refShip.Type.War = false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = -0.2;
	refShip.SpeedDependWeight = 0.2;
	refShip.SubSeaDependWeight = 0.2;
	refship.TurnDependWeight	= 0.3;

	refShip.Height.Bombs.Y		= 1.0;	refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;	refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;	refShip.Height.Balls.DY		= 1.0;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.9;//BB was 14.5
		refShip.TurnRate		= 90;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.5;
		refShip.TurnRate		= 38;
		refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
		refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
		refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;

	}

//-------------------------------------------------------------------------
// Hannah 1775 (Pirate version) by pgargon// BB as for the 'Hannah' above - light schooner
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "PiratHannah";
	refShip.SName			= "Hannah_p";
	refShip.id				= refShip.Name;
	refShip.Walk			= "Hannah_p";
	refShip.all					= "schooner1";
	refShip.Class		   = 7;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS6;//BB was LBS4
	refShip.MaxCaliber		= 6;
	refShip.Weight			= Tonnes2CWT(180);//BB was 150
	refShip.Capacity		= 800;//BB was 700
	refShip.CannonsQuantity = 12;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	refShip.MaxCrew		 = 48;
	refShip.MinCrew		 = 10;//BB was 6
	refShip.Price		   = 28000;
	refShip.HP			  = 1000;//BB was 600
	refShip.SP			  = 200;//BB was 180

	refShip.BigPicTexName	= "SHIPS2"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 114;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast1.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag2 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.9; //
	refShip.period.5 = 0.4; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.7; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = -0.2;
	refShip.SpeedDependWeight = 0.2;
	refShip.SubSeaDependWeight = 0.2;
	refship.TurnDependWeight	= 0.3;

	refShip.Height.Bombs.Y		= 1.0;	refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;	refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;	refShip.Height.Balls.DY		= 1.0;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 14.0;//BB was 14.3
		refShip.TurnRate		= 90;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.3;
		refShip.TurnRate		= 35;
		refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
		refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
		refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;

	}

//-------------------------------------------------------------------------
// HMS Speedy by pgargon
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "HMS_Speedy";
	refShip.SName	 		= "Speedy";
	refShip.id				= refShip.Name;
	refShip.walk			= "Speedy";
	refShip.all					= "Brig1";
	refShip.Class		   = 8;
	refShip.Cannon			= CANNON_TYPE_CARRONADE_LBS12;
	refShip.MaxCaliber		= 6;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity		= 650;
	refShip.CannonsQuantity = 14;
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;
	refShip.MaxCrew		 = 72;
	refShip.MinCrew		 = 14;
	refShip.Price		   = 44800;//BB was 76800
	refShip.HP			  = 1600;
	refShip.SP			  = 200;

	refShip.BigPicTexName = "SHIPS3"; //Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 6;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag2 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.8; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 1.0; //
	refShip.france = 0.5; //
	refShip.holland = 0.5; //
	refShip.portugal = 0.5; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.3; //
	refShip.america = 0.1; //
	refShip.sweden = 0.0; //

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = 0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.4;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 90;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.1;
		refShip.TurnRate		= 47;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// SHIP PACK 2 <--

//-------------------------------------------------------------------------
//	PO Poseidon- former PotBS Fourth Rate; based on French 'Le Fleuron'
//  Model by Jabberdau, conversion by Jack Harrison, locators and rigging by Craiggo and Armada
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name				= "PO_Poseidon";
	refShip.id					= refShip.Name;
	refShip.walk				= "Poseidon";
	refShip.SName				= "Poseidon";
	refShip.Class				= 3;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber			= 24;
	refShip.Weight				= Tonnes2CWT(2500);
	refShip.Capacity			= 3000;
	refShip.CannonsQuantity		= 66;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	refShip.MaxCrew				 = 640;
	refShip.MinCrew				 = 128;
	refShip.Price				= 364000;
	refShip.HP					= 9000;
	refShip.SP					= 200;

	refShip.BigPicTexName = "SHIPS3"; //Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 86;
	refShip.QDeck = "ShipDeck2";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin1";
	refShip.Flags.Mast1.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.3; //
	refShip.period.3 = 0.4; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.2; //
	refShip.portugal = 0.2; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.2;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.1;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.8;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 11.0;
		refShip.TurnRate		= 32;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

		//refShip.RigType = "Bat";
	}

//-------------------------------------------------------------------------
//	RN Poseidon- retexture by Armada
//  Model by Jabberdau, conversion by Jack Harrison, locators and rigging by Craiggo and Armada
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name				= "RN_Poseidon";
	refShip.id					= refShip.Name;
	refShip.walk				= "Poseidon";
	refShip.SName				= "Poseidon";
	refShip.Class				= 3;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber			= 24;
	refShip.Weight				= Tonnes2CWT(2500);
	refShip.Capacity			= 3000;
	refShip.CannonsQuantity		= 66;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	refShip.MaxCrew				 = 640;
	refShip.MinCrew				 = 128;
	refShip.Price				= 364000;
	refShip.HP					= 9000;
	refShip.SP					= 200;

	refShip.BigPicTexName = "SHIPS3"; //Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 86;
	refShip.QDeck = "ShipDeck2";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin1";
	refShip.Flags.Mast1.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.3; //
	refShip.period.3 = 0.4; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.2; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.2;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.1;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.8;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 11.0;
		refShip.TurnRate		= 32;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

		//refShip.RigType = "Bat";
	}

//-------------------------------------------------------------------------
//	Le Fleuron 1729- retexture of Poseidon by Armada
//  Model by Jabberdau, conversion by Jack Harrison, locators and rigging by Craiggo and Armada
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name				= "FR_Fleuron";
	refShip.id					= refShip.Name;
	refShip.walk				= "Poseidon";
	refShip.SName				= "Fleuron";
	refShip.Class				= 3;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber			= 24;
	refShip.Weight				= Tonnes2CWT(2500);
	refShip.Capacity			= 3000;
	refShip.CannonsQuantity		= 66;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	refShip.MaxCrew				 = 640;
	refShip.MinCrew				 = 128;
	refShip.Price				= 364000;
	refShip.HP					= 9000;
	refShip.SP					= 200;

	refShip.BigPicTexName = "SHIPS3"; //Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 86;
	refShip.QDeck = "ShipDeck2";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin1";
	refShip.Flags.Mast1.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.3; //
	refShip.period.3 = 0.4; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.2; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.2; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.2;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.1;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.8;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 11.0;
		refShip.TurnRate		= 32;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

		//refShip.RigType = "Bat";
	}
//-------------------------------------------------------------------------
//	Natividad - "FR_Fleuron" with "FR_Superbe" mizzen by Grey Roger
//	Armament reduced to 60 guns, crew reduced
//	For Hornblower sidequest
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name				= "SP_Natividad";
	refShip.id					= refShip.Name;
	refShip.walk				= "Poseidon";
	refShip.SName				= "Natividad";
	refShip.Class				= 3;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber			= 24;
	refShip.Weight				= Tonnes2CWT(2500);
	refShip.Capacity			= 3000;
	refShip.CannonsQuantity		= 60;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	refShip.MaxCrew				= 550;
	refShip.MinCrew				= 108;
	refShip.Price				= 350000;
	refShip.HP				= 8500;	// GR: reduced from 9000 on original Fleuron
	refShip.SP				= 200;

	refShip.BigPicTexName = "SHIPS5"; //Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 86;
	refShip.QDeck = "ShipDeck2";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin1";
	refShip.Flags.Mast1.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.02; //
	refShip.period.5 = 0.02; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.2; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.2;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.1;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.8;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 11.0;
		refShip.TurnRate		= 32;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

		//refShip.RigType = "Bat";
	}

//-------------------------------------------------------------------------
//  HMS Surprise (movie-accurate version) by Jack Harrison
//	Texture by JH and Armada; rigging by Craiggo
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         			= "HMS_Surprise";
	refShip.SName           		= "HMS_Surprise";
	refShip.walk					= "HMS_Surprise";
	refShip.all						= "Frigate1";
	refShip.nation					= ENGLAND;
	refShip.id            			= refShip.Name;
	refShip.Class				= 5;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS12
	refShip.MaxCaliber			= 12;
	refShip.Weight				= Tonnes2CWT(1300);
	refShip.Capacity			= 2000;
	refShip.CannonsQuantity			= 32;
	refShip.Cannons.Borts.cannonf.qty	= 0;
	refShip.Cannons.Borts.cannonb.qty	= 2;
	refShip.MaxCrew				= 300;
	refShip.MinCrew				= 60;
	refShip.Price				= 228000;
	refShip.HP				= 5000;
	refShip.SP				= 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 38;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
	refShip.Flags.UseNavalFlag = true;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.2; //
	refShip.period.4 = 0.7; //
	refShip.period.5 = 0.8; //
	//Nation
	refShip.england = 0.15; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= false;
	refShip.CanBuy			= false;

	refShip.WaterLine = 0.5;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.8;//BB was 14.0, too fast for this ship?
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.25;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14;
		refShip.TurnRate		= 34;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

//-------------------------------------------------------------------------
// RN_Surprise by pgargon- improved version of old HMS_Surprise, with fewer guns
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         			= "RN_Surprise";
	refShip.All						= "Frigate1";
	refShip.SName           		= "RN_Surprise";
	refShip.id            			= refShip.Name;
	refShip.Walk 					= "RN_Surprise";
	refShip.Class				= 5;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber			= 12;
	refShip.Weight				= Tonnes2CWT(1300);
	refShip.Capacity			= 1500;
	refShip.CannonsQuantity			= 32;
	refShip.Cannons.Borts.cannonf.qty	= 2;
	refShip.Cannons.Borts.cannonb.qty	= 2;
	refShip.MaxCrew				= 320;
	refShip.MinCrew				= 64;
	refShip.Price				= 228000;
	refShip.HP				= 4000;
	refShip.SP				= 200;

	refShip.BigPicTexName	= "SHIPS3"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 38;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag2 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.7; //
	refShip.period.5 = 0.8; //
	//Nation
	refShip.england = 0.45; //
	refShip.france = 0.0; //
	refShip.holland = 0.1; //
	refShip.portugal = 0.2; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.01; //
	refShip.sweden = 0.0; //

	refShip.Model = "Unite"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.3;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.8;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.25;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.5;
		refShip.TurnRate		= 34;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

//-------------------------------------------------------------------------
// Unité class frigate, French version of RN_Surprise by pgargon, retextured by Grey Roger
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         			= "FR_Surprise";
	refShip.All						= "Frigate1";
	refShip.SName           		= "RN_Surprise";
	refShip.id            			= refShip.Name;
	refShip.Walk 					= "RN_Surprise";
	refShip.Class				= 5;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber			= 12;
	refShip.Weight				= Tonnes2CWT(1300);
	refShip.Capacity			= 1500;
	refShip.CannonsQuantity			= 32;
	refShip.Cannons.Borts.cannonf.qty	= 2;
	refShip.Cannons.Borts.cannonb.qty	= 2;
	refShip.MaxCrew				= 320;
	refShip.MinCrew				= 64;
	refShip.Price				= 228000;
	refShip.HP				= 4000;
	refShip.SP				= 200;

	refShip.BigPicTexName	= "SHIPS3"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 38;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag2 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.7; //
	refShip.period.5 = 0.8; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.35; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.00; //
	refShip.sweden = 0.0; //

	refShip.Model = "Unite"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.3;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.8;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.25;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.5;
		refShip.TurnRate		= 34;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

//-------------------------------------------------------------------------
// Unité class frigate, Spanish version of RN_Surprise by pgargon, retextured by Grey Roger
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         			= "SP_Surprise";
	refShip.All						= "Frigate1";
	refShip.SName           		= "RN_Surprise";
	refShip.id            			= refShip.Name;
	refShip.Walk 					= "RN_Surprise";
	refShip.Class				= 5;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber			= 12;
	refShip.Weight				= Tonnes2CWT(1300);
	refShip.Capacity			= 1500;
	refShip.CannonsQuantity			= 32;
	refShip.Cannons.Borts.cannonf.qty	= 2;
	refShip.Cannons.Borts.cannonb.qty	= 2;
	refShip.MaxCrew				= 320;
	refShip.MinCrew				= 64;
	refShip.Price				= 228000;
	refShip.HP				= 4000;
	refShip.SP				= 200;

	refShip.BigPicTexName	= "SHIPS3"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 38;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag2 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.7; //
	refShip.period.5 = 0.8; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.2; //
	refShip.america = 0.00; //
	refShip.sweden = 0.0; //

	refShip.Model = "Unite"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.3;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.8;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.25;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.5;
		refShip.TurnRate		= 34;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

//-------------------------------------------------------------------------
//	San Felipe 1690 by pgargon
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name 	= "SP_SanFelipe";
	refShip.id		= refShip.Name;
	refShip.All		= "SP_Manowar";
	refShip.SName	= "SanFelipe";
	refShip.Class	= 1;
	refShip.walk	= "SanFelipe";
	refShip.Weight		= Tonnes2CWT(3000);
	refShip.Capacity	= 4250;
	refShip.Cannon		= CANNON_TYPE_LONG_LBS32;
	refShip.MaxCaliber	= 32;
	refShip.CannonsQuantity	= 108;
	refShip.Cannons.Borts.cannonf.qty	= 2;
	refShip.Cannons.Borts.cannonb.qty	= 4;
	refShip.MaxCrew		= 1080;
	refShip.MinCrew		= 204;
	refShip.Price	= 592000;
	refShip.HP		= 16000;
	refShip.SP		= 200;

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 40;
	refShip.QDeck = "ShipDeck3";
	refShip.CannonsDeck = 3;
 	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin1";
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.1; //
	refShip.period.2 = 0.4; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.03; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade	= false;
	refShip.Type.War		= true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight		= 0.3;
	refShip.SubSeaDependWeight	= 0.9;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 1.0;

	}

//-------------------------------------------------------------------------
// Soleil Royal by red10october; additional work by Armada
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 211> (WBT4XL)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			 = "FR_SoleilRoyal";
	refShip.SName			 = "SoleilRoyal";
	refShip.All				 = "HMS_Endeavour";
	refShip.id				 = refShip.Name;
	refShip.Class		     = 1;
	refShip.Walk			 = "";
	refShip.Cannon			 = CANNON_TYPE_LONG_LBS32;
	refShip.MaxCaliber	     = 32;
	refShip.Weight			 = Tonnes2CWT(4000);
	refShip.Capacity		 = 4500;
	refShip.CannonsQuantity  = 112;
	refShip.Cannons.Borts.cannonf.qty = 4;
	refShip.Cannons.Borts.cannonb.qty = 4;
	refShip.MaxCrew			 = 1100;
	refShip.MinCrew			 = 200;
	refShip.Price            = 600000;
	refShip.HP               = 17000;
	refShip.SP               = 200;

	refShip.BigPicTexName	= "SHIPS3"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 40;
	refShip.QDeck = "ShipDeck3";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin1";
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.2; //
	refShip.period.2 = 0.4; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.05; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.9;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 9.0;
		refShip.TurnRate		= 45;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 9.0;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 1.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, LARGE turn circle (WBT4XL)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 096> is henceforth complete
// on this day and date Jan 1 2010, 1711h

//-------------------------------------------------------------------------
// RN_RevengeM - 4-masted Galleon - By Nightwatcher
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 101> (WBT4H)  - English (Elizabethian) galleon
//	Merchant version - less crew, slower, more capacity
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name = "RN_RevengeM";
	refShip.SName = "GaleonEng";
	refShip.id = refShip.Name;
	refShip.Class = 3;
	refShip.Walk = "Revenge";
	refShip.Cannon = CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber = 12;
	refShip.Weight = Tonnes2CWT(1800);
	refShip.Capacity = 4800;
	refShip.CannonsQuantity = 40;
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 2;
	refShip.MaxCrew = 320;
	refShip.MinCrew = 40;
	refShip.Price = 160000;
	refShip.HP = 4500;
	refShip.SP = 400;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName	= "SHIPS4"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 66;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast5.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 1.0; //
	refShip.period.1 = 0.8; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.6; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

// Ships like these were "pirates", taking Spanish prizes as they circumnavigated the world under English flag

	refShip.CanEncounter = true;
	refShip.CanBuy = true;
//	refShip.Model = "Revenge"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = false;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.9;
	refShip.TurnDependWeight = 0.8;

	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;

	refShip.RigType = "Btn";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 9.0;
		refShip.TurnRate		= 65; // was 60
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.8;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 40; // was 35
		refShip.InertiaAccelerationX = 0.2;		refShip.InertiaBrakingX = 2.0;
		refShip.InertiaAccelerationY = 7;		refShip.InertiaBrakingY = 6;
		refShip.InertiaAccelerationZ = 4.0;		refShip.InertiaBrakingZ = 2.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, better turn circle (WBT4H)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 101> is henceforth complete
// on this day and date Jan 1 2010, 1834h

//-------------------------------------------------------------------------
// RN_RevengeW - 4-masted Galleon - By Nightwatcher; Textures by Craiggo
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 101> (WBT4H)  - English (Elizabethian) galleon
//	War version - more crew, heavier guns - represents Ark Royal
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name = "RN_RevengeW";
	refShip.SName = "GaleonEngW";
	refShip.id = refShip.Name;
	refShip.Class = 4;
	refShip.Walk = "Revenge";
	refShip.Cannon = CANNON_TYPE_LONG_LBS18;
	refShip.MaxCaliber = 24; // was 18
	refShip.Weight = Tonnes2CWT(1600);
	refShip.Capacity = 3500;
	refShip.CannonsQuantity = 40;
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 2;
	refShip.MaxCrew = 440; // was 400
	refShip.MinCrew = 45;
	refShip.Price = 190000;
	refShip.HP = 5000;
	refShip.SP = 400;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName	= "SHIPS4"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 66;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast5.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 1.0; //
	refShip.period.1 = 0.8; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.6; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

// Ships like these were "pirates", taking Spanish prizes as they circumnavigated the world under English flag

	refShip.CanEncounter = true;
	refShip.CanBuy = true;
//	refShip.Model = "Revenge"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.9;
	refShip.TurnDependWeight = 0.8;

	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;

	refShip.RigType = "Btn";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.8;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 35;
		refShip.InertiaAccelerationX = 0.2;		refShip.InertiaBrakingX = 2.0;
		refShip.InertiaAccelerationY = 7;		refShip.InertiaBrakingY = 6;
		refShip.InertiaAccelerationZ = 4.0;		refShip.InertiaBrakingZ = 2.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, better turn circle (WBT4H)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 101> is henceforth complete
// on this day and date Jan 1 2010, 1834h

//-------------------------------------------------------------------------
// RN_RevengeF - 4-masted Galleon - By Nightwatcher; Textures by Craiggo
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 101> (WBT4H)  - English (Elizabethian) galleon
//	Fast version - less crew, more speed, better turn - represents Revenge
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name = "RN_RevengeF";
	refShip.SName = "GaleonEngW";
	refShip.id = refShip.Name;
	refShip.Class = 4;
	refShip.Walk = "Revenge";
	refShip.Cannon = CANNON_TYPE_LONG_LBS18;
	refShip.MaxCaliber = 18;
	refShip.Weight = Tonnes2CWT(1600);
	refShip.Capacity = 3500;
	refShip.CannonsQuantity = 40;
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 2;
	refShip.MaxCrew = 370; // was 400
	refShip.MinCrew = 45;
	refShip.Price = 190000;
	refShip.HP = 5000;
	refShip.SP = 400;
	refShip.Jetty			= false; // PB

	refShip.BigPicTexName	= "SHIPS4"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 66;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast5.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 1.0; //
	refShip.period.1 = 0.8; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.6; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

// Ships like these were "pirates", taking Spanish prizes as they circumnavigated the world under English flag

	refShip.CanEncounter = true;
	refShip.CanBuy = true;
//	refShip.Model = "Revenge"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.9;
	refShip.TurnDependWeight = 0.8;

	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;

	refShip.RigType = "Btn";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.0; // was 10.0
		refShip.TurnRate		= 80; // was 60
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.8;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 11.0; // was 10.0
		refShip.TurnRate		= 40; // was 35
		refShip.InertiaAccelerationX = 0.2;		refShip.InertiaBrakingX = 2.0;
		refShip.InertiaAccelerationY = 7;		refShip.InertiaBrakingY = 6;
		refShip.InertiaAccelerationZ = 4.0;		refShip.InertiaBrakingZ = 2.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, better turn circle (WBT4H)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 101> is henceforth complete
// on this day and date Jan 1 2010, 1834h

//-------------------------------------------------------------------------
// Portuguese Caravela Redonda by pgargon
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "PO_CaravelR";
	refShip.id				= refShip.Name;
	refShip.SName			= "Caravel2_real";
	refShip.All				= "Carrack";
	refShip.walk			= "CaravelR";
	refShip.Class		    = 8;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS9;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(350);
	refShip.Capacity		= 1350;
	refShip.CannonsQuantity = 10;
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 2;
	refShip.MaxCrew		 = 70;
	refShip.MinCrew		 = 20;

	refShip.Price		   = 44000;
	refShip.HP			  = 1750;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS4"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 82;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 1.0; //
	refShip.period.1 = 0.6; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.7; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.6;
	
	refShip.GeraldSails.rey_a2	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 9.75;
		refShip.TurnRate		= 50;
        refShip.InertiaAccelerationX    = 6;    refShip.InertiaBrakingX         = 0.4;
        refShip.InertiaAccelerationY    = 2.25;  refShip.InertiaBrakingY         = 0.5;
        refShip.InertiaAccelerationZ    = 2.5;  refShip.InertiaBrakingZ         = 2.0;
	}else{
		refShip.SpeedRate		= 12.0;
		refShip.TurnRate		= 30;
        refShip.InertiaAccelerationX    = 0.2;  refShip.InertiaBrakingX         = 2.0;
        refShip.InertiaAccelerationY    = 6;    refShip.InertiaBrakingY         = 4;
        refShip.InertiaAccelerationZ    = 3.0;  refShip.InertiaBrakingZ         = 3.0;
	}

	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.8;
	refShip.RigType = "Btn";

//-------------------------------------------------------------------------
// Queen Anne's Revenge by Bonjourmonami
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name				= "QueenAnnesRevenge";
	refShip.id				= refShip.Name;
	refShip.SName				= "GaleonP";
	refShip.Nation				= PIRATE;
	refShip.unique				= true;
	refShip.Class				= 5;
	refShip.Walk				= "QueenAnnesRevenge"; // craiggo
	refShip.Cannon				= CANNON_TYPE_LONG_LBS18;
	refShip.MaxCaliber			= 18;
	refShip.Weight				= Tonnes2CWT(1100);
	refShip.Capacity			= 4500;
	refShip.CannonsQuantity			= 44;
	refShip.Cannons.Borts.cannonf.qty	= 2;
	refShip.Cannons.Borts.cannonb.qty	= 2;
	refShip.MaxCrew				= 420;
	refShip.MinCrew				= 70;
	refShip.Price				= 225000;
	refShip.HP				= 5000;
	refShip.SP				= 200;

	refShip.BigPicTexName	= "SHIPS3"; // Armada
// KK -->
	refShip.EmblemedSails.normalTex = "sail_torn_red_qar.tga";
	refShip.EmblemedSails.nationFileName = "sail_torn_red_qar.tga";

	refShip.BI.Tex = 16;
	refShip.BI.Pic = 2;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin2";
	refShip.Flags.Mast1.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
//	refShip.Flags.NoPennants = true;
// <-- KK

	refShip.Type.Trade			= false;
	refShip.Type.War			= true;

	refShip.CanBuy				= false;
	refShip.CanEncounter		= false;

	refShip.WaterLine			= -0.7;
	refShip.SpeedDependWeight	= 0.3;
	refShip.SubSeaDependWeight	= 1.0;

	refShip.Height.Bombs.Y		= 1.0;	refShip.Height.Bombs.DY = 0.5;
	refShip.Height.Grapes.Y		= 2.0;	refShip.Height.Grapes.DY = 1.0;
	refShip.Height.Knippels.Y	= 10.0;	refShip.Height.Knippels.DY = 8.0;
	refShip.Height.Balls.Y		= 1.0;	refShip.Height.Balls.DY = 0.5;

	refShip.GeraldSails.rey_b2	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 65;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.75;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 11.0;
		refShip.TurnRate		= 35;
		refShip.InertiaAccelerationX = 0.4;	refShip.InertiaBrakingX = 2.0;
		refShip.InertiaAccelerationY = 10;	refShip.InertiaBrakingY = 4;
		refShip.InertiaAccelerationZ = 4.0;	refShip.InertiaBrakingZ = 2.0;
	}

//-------------------------------------------------------------------------
// Lyon Hoy by Rider88
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 056> (WBT3H)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "PO_Hoy";
	refShip.All				= "Lugger1";
	refShip.SName	 		= "Hoy";
	refShip.id				= refShip.Name;
	refShip.Class		   = 8;
	refship.Walk		    = "Lyon"
	refShip.Cannon			= CANNON_TYPE_LONG_LBS4;
	refShip.MaxCaliber		= 4;
	refShip.Weight			= Tonnes2CWT(170);
	refShip.Capacity		= 1200;   //changed from 800 to reflect the large hull  HP
	refShip.CannonsQuantity = 8;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;
	// NK <--
	refShip.MaxCrew		 = 24;
	refShip.MinCrew		 = 5;
	refShip.Price		   = 14600;
	refShip.HP			  = 800;
	refShip.SP			  = 200;

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 98;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refship.Flags.Mast3.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 1.0; //
	refShip.period.3 = 0.9; //
	refShip.period.4 = 0.8; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.5; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Hoy"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.ClosestPoint = 0.22;       //  added these lines to adjust performance  HP
	refShip.BestPoint = 0.75;          //
	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;   //
	refShip.SubSeaDependWeight = 0.3;  //

	// LDH changed 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 90;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 15.3;
		refShip.TurnRate		= 55;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 3.0;

	}

// cute lil ship - loves sailing against the wind. Very agile but slower than a square rigger downwind.
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 056> is henceforth complete
// on this day and date Sunday Dec 26 2009, 1030h

//-------------------------------------------------------------------------
// Lyon Hoy by Rider88
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 056> (WBT3H)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "SP_Hoy";
	refShip.All				= "Lugger1";
	refShip.SName	 		= "Hoy";
	refShip.id				= refShip.Name;
	refShip.Class		   = 8;
	refship.Walk		    = "Lyon"
	refShip.Cannon			= CANNON_TYPE_LONG_LBS4;
	refShip.MaxCaliber		= 4;
	refShip.Weight			= Tonnes2CWT(170);
	refShip.Capacity		= 1200;     //changed from 800 to reflect the large hull  HP
	refShip.CannonsQuantity = 8;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;
	// NK <--
	refShip.MaxCrew		 = 24;
	refShip.MinCrew		 = 5;
	refShip.Price		   = 14600;
	refShip.HP			  = 800;
	refShip.SP			  = 200;

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 98;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refship.Flags.Mast3.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 1.0; //
	refShip.period.3 = 0.9; //
	refShip.period.4 = 0.8; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.5; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Hoy"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.ClosestPoint = 0.22;          //  added lines to adjust performance  HP
	refShip.BestPoint = 0.75;             //
	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;      //
	refShip.SubSeaDependWeight = 0.3;     //

	// LDH changed 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 95;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 15.3;
		refShip.TurnRate		= 55;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 3.0;

	}

// cute lil ship - loves sailing against the wind. Very agile but slower than a square rigger downwind.
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 056> is henceforth complete
// on this day and date Sunday Dec 26 2009, 1030h

//-------------------------------------------------------------------------
// Lyon Hoy by Rider88
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 056> (WBT3H)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "FR_Hoy";
	refShip.All				= "Lugger1";
	refShip.SName	 		= "Hoy";
	refShip.id				= refShip.Name;
	refShip.Class		   = 8;
	refship.Walk		    = "Lyon"
	refShip.Cannon			= CANNON_TYPE_LONG_LBS4;
	refShip.MaxCaliber		= 4;
	refShip.Weight			= Tonnes2CWT(170);
	refShip.Capacity		= 1200;        //changed from 800 to reflect the large hull  HP
	refShip.CannonsQuantity = 8;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;
	// NK <--
	refShip.MaxCrew		 = 24;
	refShip.MinCrew		 = 5;
	refShip.Price		   = 14600;
	refShip.HP			  = 800;
	refShip.SP			  = 200;

	refShip.BigPicTexName = "SHIPS1"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 98;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refship.Flags.Mast3.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 1.0; //
	refShip.period.3 = 0.9; //
	refShip.period.4 = 0.8; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.5; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.5; //

	refShip.Model = "Hoy"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.ClosestPoint = 0.22;            //  added these lines to adjust performance  HP
	refShip.BestPoint = 0.75;               //
	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;        //
	refShip.SubSeaDependWeight = 0.3;       //

	// LDH changed 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 95;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 15.3;
		refShip.TurnRate		= 55;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 3.0;

	}

// cute lil ship - loves sailing against the wind. Very agile but slower than a square rigger downwind.
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 056> is henceforth complete
// on this day and date Sunday Dec 26 2009, 1030h

//-------------------------------------------------------------------------
// Neptunus Privateer by SeaNorris and Rider88
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 038> (WBT2)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "PO_Neptunus";
	refShip.SName	 		= "SloopWar";
	refShip.id				= refShip.Name;
	refShip.Class		   = 6;
	refship.Walk                    = "Neptunus"
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity		= 1400;
	refShip.CannonsQuantity = 16;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;
	// NK <--
	refShip.MaxCrew		 = 132;
	refShip.MinCrew		 = 26;
	refShip.Price		   = 76800;
	refShip.HP			  = 2000;
	refShip.SP			  = 200;
	refShip.Jetty	= false; // PB

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 6;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refship.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refship.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.4; //
	refShip.period.3 = 0.9; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.4; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;
	refShip.Model = "Neptunus"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = -0.3;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.4;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 85;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.1;
		refShip.TurnRate		= 47;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;
	}

//-------------------------------------------------------------------------
// Neptunus Privateer by SeaNorris and Rider88
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 038> (WBT2)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "RN_Neptunus";
	refShip.SName	 		= "SloopWar";
	refShip.id				= refShip.Name;
	refShip.Class		   = 6;
	refship.Walk                    = "Neptunus"
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity		= 1400;
	refShip.CannonsQuantity = 16;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;
	// NK <--
	refShip.MaxCrew		 = 132;
	refShip.MinCrew		 = 26;
	refShip.Price		   = 76800;
	refShip.HP			  = 2000;
	refShip.SP			  = 200;
	refShip.Jetty	= false; // PB

	refShip.BigPicTexName	= "SHIPS3"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 6;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refship.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refship.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.4; //
	refShip.period.3 = 0.9; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.2; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.1; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.1; //

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;
	refShip.Model = "Neptunus"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = -0.3;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.4;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 85;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.1;
		refShip.TurnRate		= 47;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;
	}

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2) - no penalty to turning circle due to not-so-fine hull shape
// square rigger - does not handle as well upwind, compensate with stays and spanker
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 038> is henceforth complete
// on this day and date Sunday Dec 25 2009, 2009h

//-------------------------------------------------------------------------
// Neptunus Privateer by SeaNorris and Rider88
// Blue texture by Hylie Pistof
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "FR_Neptunus";
	refShip.SName	 		= "SloopWar";
	refShip.id				= refShip.Name;
	refShip.Class		   = 6;
	refship.Walk                    = "Neptunus"
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity		= 1400;
	refShip.CannonsQuantity = 16;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;
	// NK <--
	refShip.MaxCrew		 = 132;
	refShip.MinCrew		 = 26;
	refShip.Price		   = 76800;
	refShip.HP			  = 2000;
	refShip.SP			  = 200;
	refShip.Jetty	= false; // PB

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 6;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refship.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refship.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.4; //
	refShip.period.3 = 0.9; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.3; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;
	refShip.Model = "Neptunus"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = -0.3;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.4;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 85;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.1;
		refShip.TurnRate		= 47;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;
	}

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2) - no penalty to turning circle due to not-so-fine hull shape
// square rigger - does not handle as well upwind, compensate with stays and spanker
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 038> is henceforth complete
// on this day and date Sunday Dec 25 2009, 2009h

//-------------------------------------------------------------------------
// Neptunus Privateer by SeaNorris and Rider88
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 038> (WBT2)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "SP_Neptunus";
	refShip.SName	 		= "SloopWar";
	refShip.id				= refShip.Name;
	refShip.Class		   = 6;
	refship.Walk                    = "Neptunus"
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity		= 1400;
	refShip.CannonsQuantity = 16;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;
	// NK <--
	refShip.MaxCrew		 = 132;
	refShip.MinCrew		 = 26;
	refShip.Price		   = 76800;
	refShip.HP			  = 2000;
	refShip.SP			  = 200;
	refShip.Jetty	= false; // PB

	refShip.BigPicTexName	= "SHIPS3"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 6;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refship.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refship.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.4; //
	refShip.period.3 = 0.9; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.5; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;
	refShip.Model = "Neptunus"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = -0.3;
	refShip.SpeedDependWeight = 0.4;
	refShip.SubSeaDependWeight = 0.4;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 85;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.1;
		refShip.TurnRate		= 47;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;
	}

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2) - no penalty to turning circle due to not-so-fine hull shape
// square rigger - does not handle as well upwind, compensate with stays and spanker
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 038> is henceforth complete
// on this day and date Sunday Dec 25 2009, 2009h

//-------------------------------------------------------------------------
// Neptunus Privateer by SeaNorris and Rider88
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 038> (WBT2)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "NL_Neptunus";
	refShip.SName	 		= "SloopWar";
	refShip.id				= refShip.Name;
	refShip.Class		   = 6;
	refship.Walk                    = "Neptunus"
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity		= 1400;
	refShip.CannonsQuantity = 16;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;
	// NK <--
	refShip.MaxCrew		 = 132;
	refShip.MinCrew		 = 26;
	refShip.Price		   = 76800;
	refShip.HP			  = 2000;
	refShip.SP			  = 200;
	refShip.Jetty	= false; // PB

	refShip.BigPicTexName	= "SHIPS3"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 6;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refship.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refship.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.7; //
	refShip.period.3 = 0.9; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.5; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;
	refShip.Model = "Neptunus"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = -0.3;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.4;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 85;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.1;
		refShip.TurnRate		= 47;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;
	}

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2) - no penalty to turning circle due to not-so-fine hull shape
// square rigger - does not handle as well upwind, compensate with stays and spanker
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 038> is henceforth complete
// on this day and date Sunday Dec 25 2009, 2009h

//-------------------------------------------------------------------------
// Pirate scheme for Neptunus Privateer by Grey Roger
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "PiratNeptunus";
	refShip.SName	 		= "SloopWar";
	refShip.id				= refShip.Name;
	refShip.Class		   = 6;
	refship.Walk                    = "Neptunus"
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity		= 1400;
	refShip.CannonsQuantity = 16;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;
	// NK <--
	refShip.MaxCrew		 = 132;
	refShip.MinCrew		 = 26;
	refShip.Price		   = 76800;
	refShip.HP			  = 2000;
	refShip.SP			  = 200;
	refShip.Jetty	= false; // PB

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 6;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refship.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refship.Flags.Mast5.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.7; //
	refShip.period.3 = 0.9; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.02; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.2; //
	refShip.spain = 0.02; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanBuy			= true;
	refShip.CanEncounter		= false;
	refShip.Model = "Neptunus"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = -0.3;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.4;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 85;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.1;
		refShip.TurnRate		= 47;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;
	}

//-------------------------------------------------------------------------
// Postillionen by Rider88
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 038> (WBT2)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "PiratPostillionen";
	refShip.SName	 		= "Greyhound";
	refShip.id				= refShip.Name;
	refShip.Class		   = 6;
	refship.Walk                    = "Postillionen"
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(550);
	refShip.Capacity		= 1800;
	refShip.CannonsQuantity = 20;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;
	// NK <--
	refShip.MaxCrew		 = 146;
	refShip.MinCrew		 = 24;
	refShip.Price		   = 128800;
	refShip.HP			  = 2400;
	refShip.SP			  = 200;
	refShip.Jetty	= false; // PB

	refShip.BigPicTexName	= "SHIPS4"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 72;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refship.Flags.Mast5.Flag1 = FLAG_PENNANT;
	refship.Flags.Mast7.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.7; //
	refShip.period.3 = 0.5; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.2; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.Model = "Postillionen"; // KK

	refShip.WaterLine = 0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.6;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.5;
		refShip.TurnRate		= 40;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2) - no penalty to turning circle due to not-so-fine hull shape
// square rigger - does not handle as well upwind, compensate with stays and spanker
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 038> is henceforth complete
// on this day and date Sunday Dec 25 2009, 2009h

//-------------------------------------------------------------------------
// Postillionen by Rider88
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 038> (WBT2)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "NL_Postillionen";
	refShip.SName	 		= "Greyhound";
	refShip.id				= refShip.Name;
	refShip.Class		   = 6;
	refship.Walk                    = "Postillionen"
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(550);
	refShip.Capacity		= 1800;
	refShip.CannonsQuantity = 20;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;
	// NK <--
	refShip.MaxCrew		 = 146;
	refShip.MinCrew		 = 24;
	refShip.Price		   = 128800;
	refShip.HP			  = 2400;
	refShip.SP			  = 200;
	refShip.Jetty	= false; // PB

	refShip.BigPicTexName	= "SHIPS4"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 72;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refship.Flags.Mast5.Flag1 = FLAG_PENNANT;
	refship.Flags.Mast7.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.7; //
	refShip.period.3 = 0.5; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.2; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.Model = "Postillionen"; // KK

	refShip.WaterLine = 0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.6;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.5;
		refShip.TurnRate		= 40;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2) - no penalty to turning circle due to not-so-fine hull shape
// square rigger - does not handle as well upwind, compensate with stays and spanker
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 038> is henceforth complete
// on this day and date Sunday Dec 25 2009, 2009h

//-------------------------------------------------------------------------
// Postillionen by Rider88
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 038> (WBT2)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "SP_Postillionen";
	refShip.SName	 		= "Greyhound";
	refShip.id				= refShip.Name;
	refShip.Class		   = 6;
	refship.Walk                    = "Postillionen"
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(550);
	refShip.Capacity		= 1800;
	refShip.CannonsQuantity = 20;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;
	// NK <--
	refShip.MaxCrew		 = 146;
	refShip.MinCrew		 = 24;
	refShip.Price		   = 128800;
	refShip.HP			  = 2400;
	refShip.SP			  = 200;
	refShip.Jetty	= false; // PB

	refShip.BigPicTexName	= "SHIPS4"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 72;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refship.Flags.Mast5.Flag1 = FLAG_PENNANT;
	refship.Flags.Mast7.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.7; //
	refShip.period.3 = 0.5; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.2; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.Model = "Postillionen"; // KK

	refShip.WaterLine = 0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.6;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.5;
		refShip.TurnRate		= 40;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2) - no penalty to turning circle due to not-so-fine hull shape
// square rigger - does not handle as well upwind, compensate with stays and spanker
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 038> is henceforth complete
// on this day and date Sunday Dec 25 2009, 2009h

//-------------------------------------------------------------------------
// Postillionen by Rider88
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 038> (WBT2)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "PO_Postillionen";
	refShip.SName	 		= "Greyhound";
	refShip.id				= refShip.Name;
	refShip.Class		   = 6;
	refship.Walk                    = "Postillionen"
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(550);
	refShip.Capacity		= 1800;
	refShip.CannonsQuantity = 20;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;
	// NK <--
	refShip.MaxCrew		 = 146;
	refShip.MinCrew		 = 24;
	refShip.Price		   = 128800;
	refShip.HP			  = 2400;
	refShip.SP			  = 200;
	refShip.Jetty	= false; // PB

	refShip.BigPicTexName	= "SHIPS4"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 72;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refship.Flags.Mast5.Flag1 = FLAG_PENNANT;
	refship.Flags.Mast7.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.7; //
	refShip.period.3 = 0.5; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.2; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.Model = "Postillionen"; // KK

	refShip.WaterLine = 0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.6;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.5;
		refShip.TurnRate		= 40;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2) - no penalty to turning circle due to not-so-fine hull shape
// square rigger - does not handle as well upwind, compensate with stays and spanker
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 038> is henceforth complete
// on this day and date Sunday Dec 25 2009, 2009h

//-------------------------------------------------------------------------
// Postillionen by Rider88
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 038> (WBT2)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "RN_Postillionen";
	refShip.SName	 		= "Greyhound";
	refShip.id				= refShip.Name;
	refShip.Class		   = 6;
	refship.Walk                    = "Postillionen"
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(550);
	refShip.Capacity		= 1800;
	refShip.CannonsQuantity = 20;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;
	// NK <--
	refShip.MaxCrew		 = 146;
	refShip.MinCrew		 = 24;
	refShip.Price		   = 128800;
	refShip.HP			  = 2400;
	refShip.SP			  = 200;
	refShip.Jetty	= false; // PB

	refShip.BigPicTexName	= "SHIPS4"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 72;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refship.Flags.Mast5.Flag1 = FLAG_PENNANT;
	refship.Flags.Mast7.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.7; //
	refShip.period.3 = 0.5; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.2; //
	refShip.france = 0.2; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.2; //

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.Model = "Postillionen"; // KK

	refShip.WaterLine = 0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.6;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.5;
		refShip.TurnRate		= 40;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2) - no penalty to turning circle due to not-so-fine hull shape
// square rigger - does not handle as well upwind, compensate with stays and spanker
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 038> is henceforth complete
// on this day and date Sunday Dec 25 2009, 2009h

//-------------------------------------------------------------------------
// Postillionen by Rider88
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 038> (WBT2)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "FR_Postillionen";
	refShip.SName	 		= "Greyhound";
	refShip.id				= refShip.Name;
	refShip.Class		   = 6;
	refship.Walk                    = "Postillionen"
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(550);
	refShip.Capacity		= 1800;
	refShip.CannonsQuantity = 20;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;
	// NK <--
	refShip.MaxCrew		 = 146;
	refShip.MinCrew		 = 24;
	refShip.Price		   = 128800;
	refShip.HP			  = 2400;
	refShip.SP			  = 200;
	refShip.Jetty	= false; // PB

	refShip.BigPicTexName	= "SHIPS4"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 72;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refship.Flags.Mast5.Flag1 = FLAG_PENNANT;
	refship.Flags.Mast7.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.7; //
	refShip.period.3 = 0.5; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.2; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.Model = "Postillionen"; // KK

	refShip.WaterLine = 0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.6;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.5;
		refShip.TurnRate		= 40;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2) - no penalty to turning circle due to not-so-fine hull shape
// square rigger - does not handle as well upwind, compensate with stays and spanker
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 038> is henceforth complete
// on this day and date Sunday Dec 25 2009, 2009h

//-------------------------------------------------------------------------
// Light Pinnace by Pgargon
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 084> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "NL_LightPinnace";
	refShip.SName	 		= "PinnaceL";
	refShip.walk			= "DutchPinnace"; 
	refShip.id				= refShip.Name;
	refShip.Class		   = 6;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS6;
	refShip.MaxCaliber		= 6;
	refShip.Weight			= Tonnes2CWT(450);//BB was 550, same as class 5 Pinnace!
	refShip.Capacity		= 2000;
	refShip.CannonsQuantity = 20;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 75;
	refShip.MinCrew		 = 12;
	refShip.Price		   = 26600;
	refShip.HP			  = 1250;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS3"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 88;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.8; //
	refShip.period.2 = 0.9; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.3; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Light Pinnace"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = -0.8;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.3;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 9.0;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.6;
		refShip.TurnRate		= 29;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 3.0;
	}

	refShip.RigType = "Bat";

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 084> is henceforth complete
// on this day and date Jan 1 2010, 1045h

//-------------------------------------------------------------------------
// Light Pinnace by Pgargon
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 084> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "PO_LightPinnace";
	refShip.SName	 		= "PinnaceL";
	refShip.walk			= "dutchpinnace"; 
	refShip.id				= refShip.Name;
	refShip.Class		   = 6;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS6;
	refShip.MaxCaliber		= 6;
	refShip.Weight			= Tonnes2CWT(450);//BB was 550, same as class 5 Pinnace!
	refShip.Capacity		= 2000;
	refShip.CannonsQuantity = 20;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 75;
	refShip.MinCrew		 = 12;
	refShip.Price		   = 26600;
	refShip.HP			  = 1250;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS4"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 88;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.8; //
	refShip.period.2 = 0.9; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.4; //
	refShip.france = 0.4; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.4; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.4; //

	refShip.Model = "Light Pinnace"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = -0.9;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.3;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 9.0;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.6;
		refShip.TurnRate		= 29;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 3.0;

	}

	refShip.RigType = "Bat";

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 084> is henceforth complete
// on this day and date Jan 1 2010, 1045h

//-------------------------------------------------------------------------
// Light Pinnace by Pgargon
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 084> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "SP_LightPinnace";
	refShip.SName	 		= "PinnaceL";
	refShip.walk			= "dutchpinnace"; 
	refShip.id				= refShip.Name;
	refShip.Class		   = 6;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS6;
	refShip.MaxCaliber		= 6;
	refShip.Weight			= Tonnes2CWT(450);//BB was 550, same as class 5 Pinnace!
	refShip.Capacity		= 2000;
	refShip.CannonsQuantity = 20;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 75;
	refShip.MinCrew		 = 12;
	refShip.Price		   = 26600;
	refShip.HP			  = 1250;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS4"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 88;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.8; //
	refShip.period.2 = 0.9; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.4; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Light Pinnace"; // KK
	refShip.Type.Trade = true;
	refShip.Type.War = false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = -0.9;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.3;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 9.0;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.6;
		refShip.TurnRate		= 29;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 3.0;

	}

	refShip.RigType = "Bat";

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 084> is henceforth complete
// on this day and date Jan 1 2010, 1045h

//-------------------------------------------------------------------------
//	Fluyt Derfflinger by Pgargon 
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 076> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name		= "NL_Derfflinger";
	refShip.All		= "Fleut1";
	refShip.SName		= "Fleut1L";
	refShip.id			= refShip.Name;
	refShip.Walk		= "Derfflinger";
	refShip.Class		= 6;
	refShip.Weight		= Tonnes2CWT(400);
	refShip.Capacity	= 1750;
	refShip.Cannon		= CANNON_TYPE_LONG_LBS6;
	refShip.MaxCaliber	= 6;

	refShip.CannonsQuantity = 16;
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;

	refShip.MaxCrew		= 54;
	refShip.MinCrew		= 11;

	refShip.Price	= 26000;
	refShip.HP 		= 1250;
	refShip.SP 		= 200;
	refShip.Jetty	= false; // PB

	refShip.BigPicTexName	= "SHIPS4"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 70;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.8; //
	refShip.period.1 = 0.9; //
	refShip.period.2 = 0.6; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.5; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CannonsDeck	= 1;
	refShip.CargoHold		= 1;

	refShip.Model = "Derfflinger"; // KK
	refShip.Type.Trade	= true;
	refShip.Type.War		= false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refship.WaterLine					= -0.5;
	refship.SpeedDependWeight			= 0.35;
	refship.SubSeaDependWeight			= 0.8;
	refship.TurnDependWeight				= 0.35;
	
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 65;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.8;
		refShip.TurnRate		= 38;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 1.0;
		refShip.InertiaAccelerationY	= 8;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

	refShip.RigType = "Bat";

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 076> is henceforth complete
// on this day and date Dec 31 2009, 2307h

//-------------------------------------------------------------------------
//	Fluyt Derfflinger by Pgargon 
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 076> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name		= "FR_Derfflinger";
	refShip.All		= "Fleut1";
	refShip.SName		= "Fleut1L";
	refShip.id			= refShip.Name;
	refShip.Walk		= "Derfflinger";
	refShip.Class		= 6;
	refShip.Weight		= Tonnes2CWT(400);
	refShip.Capacity	= 1750;
	refShip.Cannon		= CANNON_TYPE_LONG_LBS6;
	refShip.MaxCaliber	= 6;

	refShip.CannonsQuantity = 16;
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;

	refShip.MaxCrew		= 54;
	refShip.MinCrew		= 11;

	refShip.Price	= 26000;
	refShip.HP 		= 1250;
	refShip.SP 		= 200;
	refShip.Jetty	= false; // PB

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 70;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.8; //
	refShip.period.1 = 0.9; //
	refShip.period.2 = 0.6; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.5; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.4; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.4; //

	refShip.CannonsDeck	= 1;
	refShip.CargoHold		= 1;

	refShip.Model = "Derfflinger"; // KK
	refShip.Type.Trade	= true;
	refShip.Type.War		= false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refship.WaterLine					= -0.5;
	refship.SpeedDependWeight			= 0.35;
	refship.SubSeaDependWeight			= 0.8;
	refship.TurnDependWeight				= 0.35;
	
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 65;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.8;
		refShip.TurnRate		= 38;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 1.0;
		refShip.InertiaAccelerationY	= 8;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

	refShip.RigType = "Bat";

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 076> is henceforth complete
// on this day and date Dec 31 2009, 2307h

//-------------------------------------------------------------------------
//	Fluyt Derfflinger by Pgargon 
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 076> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name		= "SP_Derfflinger";
	refShip.All		= "Fleut1";
	refShip.SName		= "Fleut1L";
	refShip.id			= refShip.Name;
	refShip.Walk		= "Derfflinger";
	refShip.Class		= 6;
	refShip.Weight		= Tonnes2CWT(400);
	refShip.Capacity	= 1750;
	refShip.Cannon		= CANNON_TYPE_LONG_LBS6;
	refShip.MaxCaliber	= 6;

	refShip.CannonsQuantity = 16;
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;

	refShip.MaxCrew		= 54;
	refShip.MinCrew		= 11;

	refShip.Price	= 26000;
	refShip.HP 		= 1250;
	refShip.SP 		= 200;
	refShip.Jetty	= false; // PB

	refShip.BigPicTexName	= "SHIPS3"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 70;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.8; //
	refShip.period.1 = 0.9; //
	refShip.period.2 = 0.6; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.5; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CannonsDeck	= 1;
	refShip.CargoHold		= 1;

	refShip.Model = "Derfflinger"; // KK  
	refShip.Type.Trade	= true;
	refShip.Type.War		= false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refship.WaterLine					= -0.5;
	refship.SpeedDependWeight			= 0.35;
	refship.SubSeaDependWeight			= 0.8;
	refship.TurnDependWeight				= 0.35;
	
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 65;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.8;
		refShip.TurnRate		= 38;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 1.0;
		refShip.InertiaAccelerationY	= 8;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

	refShip.RigType = "Bat";

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 076> is henceforth complete
// on this day and date Dec 31 2009, 2307h


//-------------------------------------------------------------------------
// Friedrich Wilhelm zu Pferde by Damski and Pgargon
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 174> (WBT4)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name				= "NL_FWzP";
	refShip.id				= refShip.Name;
	refShip.walk				= "FWzP";
	refShip.All				= "Frigate6";
	refShip.SName				= "FWzP";
	refShip.Nation				= HOLLAND;
	refShip.Class				= 4;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber			= 24;
	refShip.Weight				= Tonnes2CWT(2300);
	refShip.Capacity			= 3500;
	refShip.CannonsQuantity = 56;
	refShip.Cannons.Borts.cannonf.qty 	= 0;
	refShip.Cannons.Borts.cannonb.qty 	= 2;
	refShip.MaxCrew 			= 560;
	refShip.MinCrew 			= 112;
	refShip.Price				= 308000;
	refShip.HP				= 7500;
	refShip.SP				= 200;

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 54;
	refShip.QDeck = "ShipDeck2";
	refShip.CannonsDeck = 2;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin1";
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.5; //
	refShip.period.2 = 0.7; //
	refShip.period.3 = 0.4; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.7; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = -0.8;
	refShip.SpeedDependWeight = 0.2;
	refShip.SubSeaDependWeight = 0.5;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 9.75;
		refShip.TurnRate		= 55;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.8;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 11.0;
		refShip.TurnRate		= 32;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;
	}

	refShip.RigType = "Bat";

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, moderate turn circle (WBT4)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 162> is henceforth complete
// on this day and date Jan 1 2010, 1046h

//-------------------------------------------------------------------------
// HMS Unicorn 1748 by Pgargon
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 134> (WBT1L) - Light Frigate
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "HMS_Unicorn";
	refShip.sname      		= "Unicorn";
	refShip.all      		= "Corvette";
	refShip.id				= refShip.Name;
	refship.walk            =  "Unicorn";
	refShip.Class		   = 5;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS9;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(800);
	refShip.Capacity		= 1500;
	refShip.CannonsQuantity = 38;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 0;
	// NK <--
	refShip.MaxCrew		 = 200;
	refShip.MinCrew		 = 25;
	refShip.Price		   = 145200;
	refShip.HP			  = 2500;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 72;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.7; //
	refShip.period.4 = 0.4; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Unicorn"; // KK

	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = 0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.6;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.5;
		refShip.TurnRate		= 40;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;
	}

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT1)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 134> is henceforth complete
// on this day and date Jan 2 10, 1749h

//-------------------------------------------------------------------------
// French Unicorn by Grey Roger, based on HMS Unicorn by Pgargon
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 134> (WBT1L) - Light Frigate
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "FR_Unicorn";
	refShip.sname      		= "Unicorn";
	refShip.all      		= "Corvette";
	refShip.id				= refShip.Name;
	refship.walk            =  "Unicorn";
	refShip.Class		   = 5;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS9;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(800);
	refShip.Capacity		= 1500;
	refShip.CannonsQuantity = 38;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 0;
	// NK <--
	refShip.MaxCrew		 = 200;
	refShip.MinCrew		 = 25;
	refShip.Price		   = 145200;
	refShip.HP			  = 2500;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 72;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.7; //
	refShip.period.4 = 0.4; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.45; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.45; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Unicorn"; // KK

	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = 0.1;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.6;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.5;
		refShip.TurnRate		= 40;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;
	}

// Review: Vessel configured as:
// high seas cruiser, medium draft V-hull, moderate turn circle (WBT1)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 134> is henceforth complete
// on this day and date Jan 2 10, 1749h

//-------------------------------------------------------------------------
// La Dilligente Tartane by Kris Wood and Rider88
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 066> (WBT3H)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "FR_Dilligente";
	refShip.id				= refShip.Name;
	refShip.All				= "Tartane1";
	refShip.SName			= "TartaneWar";
	refShip.nation			= FRANCE;
	refShip.Walk			= "Dilligente"; // PB & back84
	refShip.Class		   = 8;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS9;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(110);//BB was 100
	refShip.Capacity		= 1200;
	refShip.CannonsQuantity = 4;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;
	// NK <--
	refShip.MaxCrew		 = 26;  // adjusted crew size  HP
	refShip.MinCrew		 = 6;
	refShip.Price		   = 14300;//BB was 12000
	refShip.HP			  = 600;
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 120;
	refShip.QDeck = "ShipDeck_4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.7; //
	refShip.period.3 = 1.0; //
	refShip.period.4 = 1.0; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.2; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = true;
	refShip.Type.War = false;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;  //lowered these to make it handle better  HP
	refShip.SubSeaDependWeight = 0.3; //lowered this to make it handle better  HP

//	default schooner F&A rig          //added this section to get better handling  HP
	refShip.ClosestPoint = 0.15;
	refShip.BestPoint = 0.625;
	// KK refShip.RigType = sDet;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.8;//BB was 12.0
		refShip.TurnRate		= 90;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 6.0;	refShip.InertiaBrakingZ		= 2.0;

	}

// cute lil ship with a lug rig. good all rounder
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 066> is henceforth complete
// on this day and date Thursday Dec 31 2009, 2055h

//-------------------------------------------------------------------------
//  Empress - Chinese Junk from PotC 3 - by Iron Roger Flint
//  Texture work by Legendary_Spider
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "Empress";
	refShip.id				= refShip.Name;
	refShip.SName			= "Empress";
	refShip.nation			= PIRATE;
	refShip.Walk			= "Empress";
	refShip.Class			= 5;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(240);
	refShip.Capacity		= 1200;
	refShip.CannonsQuantity = 10;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;
	// NK <--
	refShip.MaxCrew		 = 94;
	refShip.MinCrew		 = 5;
	refShip.Price		   = 44000;
	refShip.HP			  = 1750; //Armada - Reduced from 6000; WAY too strong!
	refShip.SP			  = 200;

	refShip.BigPicTexName	= "SHIPS4";
// KK -->
	refShip.EmblemedSails.normalTex = "sail_Empress.tga";
	refShip.EmblemedSails.nationFileName = "sail_Empress.tga";
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 120;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
// <-- KK

	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 1.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanBuy		= false;
	refShip.CanEncounter	= false;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.3;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.8;//BB was 12.0
		refShip.TurnRate		= 90;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 6.0;	refShip.InertiaBrakingZ		= 2.0;

	}

//-------------------------------------------------------------------------
// RAA Frigate by Jabberdau, Jack Harrison, Noriruru and Craiggo
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "RN_RaaFrigate";
	refShip.SName           		= "RaaFrigate";
	refShip.id				= refShip.Name;
	refship.walk                    =  "RaaFrigate";
	refShip.Class		   	= 5;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(900);
	refShip.Capacity		= 1250;
	refShip.CannonsQuantity = 32;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 0;
	// NK <--
	refShip.MaxCrew		 = 300;
	refShip.MinCrew		 = 70;
	refShip.Price		   = 190200;
	refShip.HP			  = 3250;
	refShip.SP			  = 200;
	refShip.Jetty	= false; // PB

	refShip.BigPicTexName	= "SHIPS4"; // Armada

// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 68;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast1.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_PENNANT;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.6; //
	refShip.period.3 = 0.5; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.4; //
	refShip.holland = 0.5; //
	refShip.portugal = 0.4; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.5; //
	refship.america = 0.0; //
	refShip.sweden = 0.4; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.3;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.0;
		refShip.TurnRate		= 70;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.2;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 33;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;
	}

//-------------------------------------------------------------------------
// Cursed Mariana - Model modified by Yo Ho Ho - Retextured by GhostOfDeath91
// <SWS - Willemstad Builders' Trials Winter 09 S/N 118> (WBT4HF)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name = "CursedMariana";
	refShip.All = "Mariana";
	refShip.id = refShip.Name;
	refShip.SName = "FlyingDutchman";
	refShip.Nation = PIRATE;
	refShip.unique = true;
	refShip.Class = 3;
	refShip.Walk = "";
	refShip.Cannon = CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber = 24;
	refShip.Weight = Tonnes2CWT(1650);
	refShip.Capacity = 4000;
	refShip.CannonsQuantity = 38;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 4;
	refShip.MaxCrew = 440;
	refShip.MinCrew = 45;
	refShip.Price = 284400;
	refShip.HP = 100000;
	refShip.SP = 999999;
	
	refShip.BigPicTexName = "SHIPS1"; //Armada
	// KK -->
	refShip.EmblemedSails.normalTex = "sail_Mariana.tga";
	refShip.EmblemedSails.nationFileName = "sail_Mariana.tga";
	refShip.devil_trail = true;		// PB: Cursed Ship Trails Fog
	refShip.night_stealth = true;	// PB: Half visibility at night
	
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 66;
	refShip.QDeck = "ShipDeck6";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin5";
	refShip.Flags.Mast1.Flag1 = FLAG_NONE;
	refShip.Flags.Mast2.Flag1 = FLAG_NONE;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast4.Flag1 = FLAG_NONE;
	refShip.Flags.Mast5.Flag1 = FLAG_ENSIGN;
	// <-- KK
	
	refShip.Model = "Mariana";
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanBuy = false;
	refShip.CanEncounter = false;
	
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.5;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.WaterLine = -0.7;
	
	// Movement unaffected by wind - sails fastest INTO the wind
	refShip.ClosestPoint = 0.01;
	refShip.BestPoint = 0.01;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
	refShip.SpeedRate = 12.5;
	refShip.TurnRate = 80;
	refShip.InertiaAccelerationX = 4; refShip.InertiaBrakingX = 0.5;
	refShip.InertiaAccelerationY = 2.0; refShip.InertiaBrakingY = 0.5;
	refShip.InertiaAccelerationZ = 2.5; refShip.InertiaBrakingZ = 2.0;
	}else{
	refShip.SpeedRate = 12.5;
	refShip.TurnRate = 30;
	refShip.InertiaAccelerationX = 0.4; refShip.InertiaBrakingX = 2.0;
	refShip.InertiaAccelerationY = 10; refShip.InertiaBrakingY = 4;
	refShip.InertiaAccelerationZ = 4.0; refShip.InertiaBrakingZ = 2.0;
	}

// Review: Vessel configured as:
// high seas cruiser, medium draft U-hull, moderate turn circle (WBT1)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 107> is henceforth complete
// on this day and date 2 Jan 10, 0857h

//-------------------------------------------------------------------------
// Prince de Neufchatel by Captain Armstrong
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name                    = "US_PrinceNeufchatel";
	refShip.SName                    = "PrinceNeufchatel";
	refShip.id                              = refShip.Name;
	refShip.Walk                    = "PrinceNeufchatel";
	refShip.All                             = "Schooner1";
	refShip.Class              = 6;
	refShip.Cannon                  = CANNON_TYPE_CARRONADE_LBS24;
	refShip.MaxCaliber              = 9;
	refShip.Weight                  = Tonnes2CWT(600);
	refShip.Capacity                = 1200;
	refShip.CannonsQuantity = 24;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	refShip.MaxCrew          = 130;
	refShip.MinCrew          = 30;
	refShip.Price              = 46000;
	refShip.HP                        = 2500;
	refShip.SP                        = 300;

	refShip.BigPicTexName = "SHIPS1"; //Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 114;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast3.Flag2 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refship.america = 0.8; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter    = true;
	refShip.CanBuy          = true;
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = -0.2;
	refShip.SpeedDependWeight = 0.2;
	refShip.SubSeaDependWeight = 0.2;
	
	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_b2	= 1;	

	refShip.Height.Bombs.Y          = 1.0;          refShip.Height.Bombs.DY         = 1.0;
	refShip.Height.Grapes.Y         = 2.0;          refShip.Height.Grapes.DY        = 1.0;
	refShip.Height.Knippels.Y       = 15.0;         refShip.Height.Knippels.DY      = 10.0;
	refShip.Height.Balls.Y          = 1.0;          refShip.Height.Balls.DY         = 1.0;

	refShip.ClosestPoint = 0.2;
	refShip.BestPoint = 0.3;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate               = 14.0;
		refShip.TurnRate                = 100;
		refShip.InertiaAccelerationX    = 4;    refShip.InertiaBrakingX         = 0.4;
		refShip.InertiaAccelerationY    = 2.35; refShip.InertiaBrakingY         = 0.5;
		refShip.InertiaAccelerationZ    = 2.5;  refShip.InertiaBrakingZ         = 2.0;
	}else{
		refShip.SpeedRate               = 15.0;
		refShip.TurnRate                = 45;
		refship.InertiaAccelerationX    = 8.0;  refship.InertiaBrakingX         = 8.0;
		refship.InertiaAccelerationY    = 6;    refship.InertiaBrakingY         = 6;
		refship.InertiaAccelerationZ    = 6.0;  refship.InertiaBrakingZ         = 6.0;
	}

//-------------------------------------------------------------------------
// British Heavy Sloop of War 'Volage' by Captain Armstrong
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         			= "RN_Volage";
	refShip.All						= "Corvette1";
	refShip.SName           		= "Volage";
	refShip.Walk					= "Volage";
	refShip.id            			= refShip.Name;
	refShip.Class				= 5;
	refShip.Cannon				= CANNON_TYPE_CARRONADE_LBS32;
	refShip.MaxCaliber			= 12;
	refShip.Weight				= Tonnes2CWT(800);
	refShip.Capacity			= 1800;
	refShip.CannonsQuantity			= 24;
	refShip.Cannons.Borts.cannonf.qty	= 0;
	refShip.Cannons.Borts.cannonb.qty	= 0;
	refShip.MaxCrew				= 155;
	refShip.MinCrew				= 36;
	refShip.Price				= 110000;
	refShip.HP				= 3000;
	refShip.SP				= 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 36;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.2; //
	refShip.period.5 = 0.8; //
	//Nation
	refShip.england = 0.6; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.3; //
	refShip.sweden = 0.0; //

	refShip.Model = "Volage"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.0;		// was 0.2, ship was too low in the water
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.6;	// was 1.0, ship was too low in the water when fully loaded

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;
	refShip.GeraldSails.rey_c4	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.8;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.25;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.1;
		refShip.TurnRate		= 40;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

//-------------------------------------------------------------------------
// French Heavy Sloop of War 'Volage' by Captain Armstrong
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         			= "FR_Volage";
	refShip.All						= "Corvette1";
	refShip.SName           		= "Volage";
	refShip.Walk					= "Volage";
	refShip.id            			= refShip.Name;
	refShip.Class				= 5;
	refShip.Cannon				= CANNON_TYPE_CARRONADE_LBS32;
	refShip.MaxCaliber			= 12;
	refShip.Weight				= Tonnes2CWT(800);
	refShip.Capacity			= 1800;
	refShip.CannonsQuantity			= 24;
	refShip.Cannons.Borts.cannonf.qty	= 0;
	refShip.Cannons.Borts.cannonb.qty	= 0;
	refShip.MaxCrew				= 155;
	refShip.MinCrew				= 36;
	refShip.Price				= 110000;
	refShip.HP				= 3000;
	refShip.SP				= 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 36;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.2; //
	refShip.period.5 = 0.8; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.6; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Volage"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.0;		// was 0.2, ship was too low in the water
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.6;	// was 1.0, ship was too low in the water when fully loaded

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;
	refShip.GeraldSails.rey_c4	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.8;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.25;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.1;
		refShip.TurnRate		= 40;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

//-------------------------------------------------------------------------
// Spanish Heavy Sloop of War 'Volage' by Captain Armstrong
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         			= "SP_Volage";
	refShip.All						= "Corvette1";
	refShip.SName           		= "Volage";
	refShip.Walk					= "Volage";
	refShip.id            			= refShip.Name;
	refShip.Class				= 5;
	refShip.Cannon				= CANNON_TYPE_CARRONADE_LBS32;
	refShip.MaxCaliber			= 12;
	refShip.Weight				= Tonnes2CWT(800);
	refShip.Capacity			= 1800;
	refShip.CannonsQuantity			= 24;
	refShip.Cannons.Borts.cannonf.qty	= 0;
	refShip.Cannons.Borts.cannonb.qty	= 0;
	refShip.MaxCrew				= 155;
	refShip.MinCrew				= 36;
	refShip.Price				= 110000;
	refShip.HP				= 3000;
	refShip.SP				= 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 36;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.2; //
	refShip.period.5 = 0.8; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.6; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Volage"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.0;		// was 0.2, ship was too low in the water
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.6;	// was 1.0, ship was too low in the water when fully loaded

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;
	refShip.GeraldSails.rey_c4	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.8;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.25;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.1;
		refShip.TurnRate		= 40;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}
//-------------------------------------------------------------------------
// Portuguese Heavy Sloop of War 'Volage' by Captain Armstrong
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         			= "PO_Volage";
	refShip.All						= "Corvette1";
	refShip.SName           		= "Volage";
	refShip.Walk					= "Volage";
	refShip.id            			= refShip.Name;
	refShip.Class				= 5;
	refShip.Cannon				= CANNON_TYPE_CARRONADE_LBS32;
	refShip.MaxCaliber			= 12;
	refShip.Weight				= Tonnes2CWT(800);
	refShip.Capacity			= 1800;
	refShip.CannonsQuantity			= 24;
	refShip.Cannons.Borts.cannonf.qty	= 0;
	refShip.Cannons.Borts.cannonb.qty	= 0;
	refShip.MaxCrew				= 155;
	refShip.MinCrew				= 36;
	refShip.Price				= 110000;
	refShip.HP				= 3000;
	refShip.SP				= 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 36;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.2; //
	refShip.period.5 = 0.8; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.6; //
	refShip.portugal = 0.6; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Volage"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.0;		// was 0.2, ship was too low in the water
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.6;	// was 1.0, ship was too low in the water when fully loaded

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;
	refShip.GeraldSails.rey_c4	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.8;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.25;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.1;
		refShip.TurnRate		= 40;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

//-------------------------------------------------------------------------
// United States Heavy Sloop of War 'Volage' by Captain Armstrong
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         			= "US_Volage";
	refShip.All						= "Corvette1";
	refShip.SName           		= "Volage";
	refShip.Walk					= "Volage";
	refShip.id            			= refShip.Name;
	refShip.Class				= 5;
	refShip.Cannon				= CANNON_TYPE_CARRONADE_LBS32;
	refShip.MaxCaliber			= 12;
	refShip.Weight				= Tonnes2CWT(800);
	refShip.Capacity			= 1800;
	refShip.CannonsQuantity			= 24;
	refShip.Cannons.Borts.cannonf.qty	= 0;
	refShip.Cannons.Borts.cannonb.qty	= 0;
	refShip.MaxCrew				= 155;
	refShip.MinCrew				= 36;
	refShip.Price				= 110000;
	refShip.HP				= 3000;
	refShip.SP				= 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 36;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.2; //
	refShip.period.5 = 0.8; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.6; //
	refShip.sweden = 0.0; //

	refShip.Model = "Volage"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.0;		// was 0.2, ship was too low in the water
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.6;	// was 1.0, ship was too low in the water when fully loaded

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b4	= 1;
	refShip.GeraldSails.rey_c4	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.8;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.25;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.1;
		refShip.TurnRate		= 40;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}


//-------------------------------------------------------------------------
// Trinity 2nd Rate (based on the Christianus Sextus) by Remus77
// Ported by Armada; rigging work by Hylie Pistof
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name					= "FR_Trinity";
	refShip.All					= "HMS_Endeavour";
	refShip.SName				= "Trinity";
	refShip.id					= refShip.Name;
	refShip.Class					= 2;
	refShip.Walk					= "";
	refShip.Cannon					= CANNON_TYPE_LONG_LBS32;
	refShip.MaxCaliber				= 32;
	refShip.Weight					= Tonnes2CWT(3500);
	refShip.Capacity				= 3250;
	refShip.CannonsQuantity	= 96;
	refShip.Cannons.Borts.cannonf.qty		= 2;
	refShip.Cannons.Borts.cannonb.qty 		= 2;
	refShip.MaxCrew					= 960;
	refShip.MinCrew					= 200;
	refShip.Price					= 525000;
	refShip.HP					= 13000;
	refShip.SP					= 200;

	refShip.BigPicTexName = "SHIPS1"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 40;
	refShip.QDeck				= "ShipDeck3";
	refShip.CannonsDeck			= 3;
	refShip.CargoHold			= 2;
	refShip.Cabin				= "Cabin3";
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.4; //
	refShip.period.3 = 0.5; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.05; //
	refShip.france = 0.05; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //
	
	refShip.Model = "Trinity";

	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;
	refShip.Type.Trade 			= false;
	refShip.Type.War 			= true;

	refShip.WaterLine			= -0.4;
	refShip.SpeedDependWeight		= 0.3;
	refShip.SubSeaDependWeight		= 1.15;

	refShip.GeraldSails.rey_a2	= 1;
	refShip.GeraldSails.rey_a3	= 1;
	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 1.0;

	}

//-------------------------------------------------------------------------
// Trinity 2nd Rate (based on the Christianus Sextus) by Remus77
// Unique repaint by Noriruru
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name					= "PO_Trinity";
	refShip.All					= "HMS_Endeavour";
	refShip.SName				= "RN_SotL";
	refShip.id					= refShip.Name;
	refShip.Class					= 2;
	refShip.Walk					= "";
	refShip.Cannon					= CANNON_TYPE_LONG_LBS32;
	refShip.MaxCaliber				= 32;
	refShip.Weight					= Tonnes2CWT(3500);
	refShip.Capacity				= 3500;
	refShip.CannonsQuantity	= 96;
	refShip.Cannons.Borts.cannonf.qty		= 2;
	refShip.Cannons.Borts.cannonb.qty 		= 2;
	refShip.MaxCrew					= 960;
	refShip.MinCrew					= 200;
	refShip.Price					= 530000;
	refShip.HP					= 15000;
	refShip.SP					= 200;

	refShip.BigPicTexName = "SHIPS2"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 18;
	refShip.QDeck				= "ShipDeck3";
	refShip.CannonsDeck			= 3;
	refShip.CargoHold			= 2;
	refShip.Cabin				= "Cabin3";
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
	refShip.Flags.UseNavalFlag = true;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.4; //
	refShip.period.3 = 0.5; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	
	refShip.Model = "Trinity";

	refShip.CanEncounter		= false;
	refShip.CanBuy			= false;
	refShip.Type.Trade 			= false;
	refShip.Type.War 			= true;

	refShip.WaterLine			= -0.4;
	refShip.SpeedDependWeight		= 0.3;
	refShip.SubSeaDependWeight		= 1.15;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 1.0;

	}

//-------------------------------------------------------------------------
// Trinity 2nd Rate (based on the Christianus Sextus) by Remus77
// Spanish repaint by Noriruru
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name					= "SP_Trinity";
	refShip.All					= "HMS_Endeavour";
	refShip.SName				= "RN_SotL";
	refShip.id					= refShip.Name;
	refShip.Class					= 2;
	refShip.Walk					= "";
	refShip.Cannon					= CANNON_TYPE_LONG_LBS32;
	refShip.MaxCaliber				= 32;
	refShip.Weight					= Tonnes2CWT(3500);
	refShip.Capacity				= 3500;
	refShip.CannonsQuantity	= 96;
	refShip.Cannons.Borts.cannonf.qty		= 2;
	refShip.Cannons.Borts.cannonb.qty 		= 2;
	refShip.MaxCrew					= 960;
	refShip.MinCrew					= 200;
	refShip.Price					= 530000;
	refShip.HP					= 15000;
	refShip.SP					= 200;

	refShip.BigPicTexName = "SHIPS2"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 18;
	refShip.QDeck				= "ShipDeck3";
	refShip.CannonsDeck			= 3;
	refShip.CargoHold			= 2;
	refShip.Cabin				= "Cabin3";
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.4; //
	refShip.period.3 = 0.5; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.05; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //
	
	refShip.Model = "Trinity";

	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;
	refShip.Type.Trade 			= false;
	refShip.Type.War 			= true;

	refShip.WaterLine			= -0.4;
	refShip.SpeedDependWeight		= 0.3;
	refShip.SubSeaDependWeight		= 1.15;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.0;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 1.0;

	}

//-------------------------------------------------------------------------
// USS Essex 1799 by Captain Armstrong
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         			= "US_Essex";
	refShip.All						= "Frigate1";
	refShip.SName           		= "Essex";
	refShip.walk					= "US_Essex";
	refShip.id            			= refShip.Name;
	refShip.Class				= 5;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS18;
	refShip.MaxCaliber			= 18;
	refShip.Weight				= Tonnes2CWT(1300);
	refShip.Capacity			= 2500;
	refShip.CannonsQuantity			= 46;
	refShip.Cannons.Borts.cannonf.qty	= 2;
	refShip.Cannons.Borts.cannonb.qty	= 2;
	refShip.MaxCrew				= 440;
	refShip.MinCrew				= 84;
	refShip.Price				= 260000;
	refShip.HP				= 5100;
	refShip.SP				= 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 36;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.8; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.15; //
	refShip.sweden = 0.0; //

	refShip.Model = "Essex";
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_a22	= 1;
	refShip.GeraldSails.rey_c2	= 1;
	refShip.GeraldSails.rey_a33	= 1;
	refShip.GeraldSails.rey_c3	= 1;
	refShip.GeraldSails.rey_c4	= 1;
	refShip.GeraldSails.rey_b4	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 76;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.25;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.4;
		refShip.TurnRate		= 33;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}
	
//-------------------------------------------------------------------------
// HMS Essex 1799(1814) by Captain Armstrong
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         			= "RN_Essex";
	refShip.All						= "Frigate1";
	refShip.SName           		= "Essex";
	refShip.walk					= "US_Essex";
	refShip.id            			= refShip.Name;
	refShip.Class				= 5;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS18;
	refShip.MaxCaliber			= 18;
	refShip.Weight				= Tonnes2CWT(1300);
	refShip.Capacity			= 2500;
	refShip.CannonsQuantity			= 46;
	refShip.Cannons.Borts.cannonf.qty	= 2;
	refShip.Cannons.Borts.cannonb.qty	= 2;
	refShip.MaxCrew				= 440;
	refShip.MinCrew				= 84;
	refShip.Price				= 260000;
	refShip.HP				= 5100;
	refShip.SP				= 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 36;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.8; //
	//Nation
	refShip.england = 0.2; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.1; //
	refShip.sweden = 0.0; //

	refShip.Model = "Essex";
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_a22	= 1;
	refShip.GeraldSails.rey_c2	= 1;
	refShip.GeraldSails.rey_a33	= 1;
	refShip.GeraldSails.rey_c3	= 1;
	refShip.GeraldSails.rey_c4	= 1;
	refShip.GeraldSails.rey_b4	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 76;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.25;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.4;
		refShip.TurnRate		= 33;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}
	

//-------------------------------------------------------------------------
// USS Essex 1799 (Dutch/Portugese version) by Captain Armstrong
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         			= "NL_Essex";
	refShip.All						= "Frigate1";
	refShip.SName           		= "Essex";
	refShip.walk					= "US_Essex";
	refShip.id            			= refShip.Name;
	refShip.Class				= 5;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS18;
	refShip.MaxCaliber			= 18;
	refShip.Weight				= Tonnes2CWT(1300);
	refShip.Capacity			= 2500;
	refShip.CannonsQuantity			= 46;
	refShip.Cannons.Borts.cannonf.qty	= 2;
	refShip.Cannons.Borts.cannonb.qty	= 2;
	refShip.MaxCrew				= 440;
	refShip.MinCrew				= 84;
	refShip.Price				= 260000;
	refShip.HP				= 5100;
	refShip.SP				= 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 36;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.8; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.4; //
	refShip.portugal = 0.4; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Essex";
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_a22	= 1;
	refShip.GeraldSails.rey_c2	= 1;
	refShip.GeraldSails.rey_a33	= 1;
	refShip.GeraldSails.rey_c3	= 1;
	refShip.GeraldSails.rey_c4	= 1;
	refShip.GeraldSails.rey_b4	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 76;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.25;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.4;
		refShip.TurnRate		= 33;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}
	
//-------------------------------------------------------------------------
// USS Essex 1799 (French version) by Captain Armstrong
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         			= "FR_Essex";
	refShip.All						= "Frigate1";
	refShip.SName           		= "Essex";
	refShip.walk					= "US_Essex";
	refShip.id            			= refShip.Name;
	refShip.Class				= 5;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS18;
	refShip.MaxCaliber			= 18;
	refShip.Weight				= Tonnes2CWT(1300);
	refShip.Capacity			= 2500;
	refShip.CannonsQuantity			= 46;
	refShip.Cannons.Borts.cannonf.qty	= 2;
	refShip.Cannons.Borts.cannonb.qty	= 2;
	refShip.MaxCrew				= 440;
	refShip.MinCrew				= 84;
	refShip.Price				= 260000;
	refShip.HP				= 5100;
	refShip.SP				= 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 36;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.8; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.4; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Essex";
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_a22	= 1;
	refShip.GeraldSails.rey_c2	= 1;
	refShip.GeraldSails.rey_a33	= 1;
	refShip.GeraldSails.rey_c3	= 1;
	refShip.GeraldSails.rey_c4	= 1;
	refShip.GeraldSails.rey_b4	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 76;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.25;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.4;
		refShip.TurnRate		= 33;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}
	
//-------------------------------------------------------------------------
// USS Essex 1799 (Spanish Version)  by Captain Armstrong
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         			= "SP_Essex";
	refShip.All						= "Frigate1";
	refShip.SName           		= "Essex";
	refShip.walk					= "US_Essex";
	refShip.id            			= refShip.Name;
	refShip.Class				= 5;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS18;
	refShip.MaxCaliber			= 18;
	refShip.Weight				= Tonnes2CWT(1300);
	refShip.Capacity			= 2500;
	refShip.CannonsQuantity			= 46;
	refShip.Cannons.Borts.cannonf.qty	= 2;
	refShip.Cannons.Borts.cannonb.qty	= 2;
	refShip.MaxCrew				= 440;
	refShip.MinCrew				= 84;
	refShip.Price				= 260000;
	refShip.HP				= 5100;
	refShip.SP				= 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 36;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.8; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.4; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model = "Essex";
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_a22	= 1;
	refShip.GeraldSails.rey_c2	= 1;
	refShip.GeraldSails.rey_a33	= 1;
	refShip.GeraldSails.rey_c3	= 1;
	refShip.GeraldSails.rey_c4	= 1;
	refShip.GeraldSails.rey_b4	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 76;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.25;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.4;
		refShip.TurnRate		= 33;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

//-------------------------------------------------------------------------
// USS Essex 1799, Satanist version for "Animists" quest in late periods
// Original by Captain Armstrong, retextured by Grey Roger
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         			= "Sat_Essex";
	refShip.All				= "Frigate1";
	refShip.SName           		= "Frigate3";
	refShip.walk				= "US_Essex";
	refShip.id            			= refShip.Name;
	refShip.Class				= 5;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS18;
	refShip.MaxCaliber			= 18;
	refShip.Weight				= Tonnes2CWT(1300);
	refShip.Capacity			= 2500;
	refShip.CannonsQuantity			= 46;
	refShip.Cannons.Borts.cannonf.qty	= 2;
	refShip.Cannons.Borts.cannonb.qty	= 2;
	refShip.MaxCrew				= 450;
	refShip.MinCrew				= 84;
	refShip.Price				= 290000;
	refShip.HP				= 5500;
	refShip.SP				= 200;

	refShip.BigPicTexName	= "SHIPS5"; // Armada

	refShip.EmblemedSails.normalTex = "sail_whole_red_plain.tga";
	refShip.EmblemedSails.nationFileName = "sail_whole_red_plain.tga";

	refShip.BI.Tex = 16;
	refShip.BI.Pic = 36;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.01;//
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.01; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model		= "Sat_Essex";
	refShip.Type.Trade	= false;
	refShip.Type.War	= true;
	refShip.CanEncounter	= false;
	refShip.CanBuy		= false;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_a22	= 1;
	refShip.GeraldSails.rey_c2	= 1;
	refShip.GeraldSails.rey_a33	= 1;
	refShip.GeraldSails.rey_c3	= 1;
	refShip.GeraldSails.rey_c4	= 1;
	refShip.GeraldSails.rey_b4	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.2;
		refShip.TurnRate		= 77;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.25;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.6;
		refShip.TurnRate		= 34;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

//-------------------------------------------------------------------------
// USS Essex 1799, de-Satanified version for "Animists" quest in late periods
// Original by Captain Armstrong, retextured by Grey Roger
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         			= "UnSat_Essex";
	refShip.All				= "Frigate1";
	refShip.SName           		= "Frigate3";
	refShip.walk				= "US_Essex";
	refShip.id            			= refShip.Name;
	refShip.Class				= 5;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS18;
	refShip.MaxCaliber			= 18;
	refShip.Weight				= Tonnes2CWT(1300);
	refShip.Capacity			= 2500;
	refShip.CannonsQuantity			= 46;
	refShip.Cannons.Borts.cannonf.qty	= 2;
	refShip.Cannons.Borts.cannonb.qty	= 2;
	refShip.MaxCrew				= 450;
	refShip.MinCrew				= 84;
	refShip.Price				= 290000;
	refShip.HP				= 5500;
	refShip.SP				= 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 36;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast4.Flag1 = FLAG_ENSIGN;

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.01;//
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.01; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Model		= "Sat_Essex";
	refShip.Type.Trade	= false;
	refShip.Type.War	= true;
	refShip.CanEncounter	= false;
	refShip.CanBuy		= false;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.0;

	refShip.GeraldSails.rey_a22	= 1;
	refShip.GeraldSails.rey_c2	= 1;
	refShip.GeraldSails.rey_a33	= 1;
	refShip.GeraldSails.rey_c3	= 1;
	refShip.GeraldSails.rey_c4	= 1;
	refShip.GeraldSails.rey_b4	= 1;

// Stays, lateen and deep draft, better than average upwind performance
	refShip.ClosestPoint = 0.28;
	refShip.BestPoint = 0.8;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.2;
		refShip.TurnRate		= 77;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 2.25;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 13.6;
		refShip.TurnRate		= 34;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 4;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 2.0;

	}

//-------------------------------------------------------------------------
// NL_NeptunusE Privateer by SeaNorris and Rider88
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 038> (WBT2)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "NL_NeptunusE";
	refShip.SName	 		= "SloopWar";
	refShip.id				= refShip.Name;
	refShip.Class		   = 6;
        refship.Walk                    = "Neptunus"
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity		= 1400;
	refShip.CannonsQuantity = 16;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;
	// NK <--
	refShip.MaxCrew		 = 132;
	refShip.MinCrew		 = 26;
	refShip.Price		   = 76800;
	refShip.HP			  = 2000;
	refShip.SP			  = 200;
	refShip.Jetty	= false; // PB

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 6;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast0.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast1.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
        refship.Flags.Mast3.Flag1 = FLAG_PENNANT;
        refship.Flags.Mast4.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.4; //
	refShip.period.2 = 0.7; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.3; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;
	refShip.Model = "Sloop-of-War"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = -0.5;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.4;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 85;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.1;
		refShip.TurnRate		= 47;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2) - no penalty to turning circle due to not-so-fine hull shape
// square rigger - does not handle as well upwind, compensate with stays and spanker
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 038> is henceforth complete
// on this day and date Sunday Dec 25 2009, 2009h

//-------------------------------------------------------------------------
// FR_NeptunusE Privateer by SeaNorris and Rider88
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 038> (WBT2)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "FR_NeptunusE";
	refShip.SName	 		= "SloopWar";
	refShip.id				= refShip.Name;
	refShip.Class		   = 6;
        refship.Walk                    = "Neptunus"
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity		= 1400;
	refShip.CannonsQuantity = 16;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;
	// NK <--
	refShip.MaxCrew		 = 132;
	refShip.MinCrew		 = 26;
	refShip.Price		   = 76800;
	refShip.HP			  = 2000;
	refShip.SP			  = 200;
	refShip.Jetty	= false; // PB

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 6;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast0.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast1.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
        refship.Flags.Mast3.Flag1 = FLAG_PENNANT;
        refship.Flags.Mast4.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.4; //
	refShip.period.2 = 0.7; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.3; //
	refShip.france = 0.3; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.1; //

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;
	refShip.Model = "Sloop-of-War"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = -0.5;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.4;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 85;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.1;
		refShip.TurnRate		= 47;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2) - no penalty to turning circle due to not-so-fine hull shape
// square rigger - does not handle as well upwind, compensate with stays and spanker
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 038> is henceforth complete
// on this day and date Sunday Dec 25 2009, 2009h

//-------------------------------------------------------------------------
// SP_NeptunusE Privateer by SeaNorris and Rider88
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 038> (WBT2)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "SP_NeptunusE";
	refShip.SName	 		= "SloopWar";
	refShip.id				= refShip.Name;
	refShip.Class		   = 6;
        refship.Walk                    = "Neptunus"
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity		= 1400;
	refShip.CannonsQuantity = 16;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;
	// NK <--
	refShip.MaxCrew		 = 132;
	refShip.MinCrew		 = 26;
	refShip.Price		   = 76800;
	refShip.HP			  = 2000;
	refShip.SP			  = 200;
	refShip.Jetty	= false; // PB

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 6;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast0.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast1.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
        refship.Flags.Mast3.Flag1 = FLAG_PENNANT;
        refship.Flags.Mast4.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.4; //
	refShip.period.2 = 0.7; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.3; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;
	refShip.Model = "Sloop-of-War"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = -0.5;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.4;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 85;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.1;
		refShip.TurnRate		= 47;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2) - no penalty to turning circle due to not-so-fine hull shape
// square rigger - does not handle as well upwind, compensate with stays and spanker
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 038> is henceforth complete
// on this day and date Sunday Dec 25 2009, 2009h

//-------------------------------------------------------------------------
// PO_NeptunusE Privateer by SeaNorris and Rider88
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 038> (WBT2)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "PO_NeptunusE";
	refShip.SName	 		= "SloopWar";
	refShip.id				= refShip.Name;
	refShip.Class		   = 6;
        refship.Walk                    = "Neptunus"
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity		= 1400;
	refShip.CannonsQuantity = 16;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 0;
	refShip.Cannons.Borts.cannonb.qty = 0;
	// NK <--
	refShip.MaxCrew		 = 132;
	refShip.MinCrew		 = 26;
	refShip.Price		   = 76800;
	refShip.HP			  = 2000;
	refShip.SP			  = 200;
	refShip.Jetty	= false; // PB

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 6;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";
	refShip.Flags.Mast0.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast1.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
        refship.Flags.Mast3.Flag1 = FLAG_PENNANT;
        refship.Flags.Mast4.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.4; //
	refShip.period.2 = 0.7; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.3; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanBuy			= true;
	refShip.CanEncounter		= true;
	refShip.Model = "Sloop-of-War"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = -0.5;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.4;

	refShip.Height.Bombs.Y		= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

// Brigs were difficult to sail upwind
	refShip.ClosestPoint = 0.295;
	refShip.BestPoint = 0.9;
	// KK refShip.RigType = sDet;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 13.0;
		refShip.TurnRate		= 85;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.1;
		refShip.TurnRate		= 47;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 12;	refShip.InertiaBrakingY		= 8;
		refShip.InertiaAccelerationZ	= 5.0;	refShip.InertiaBrakingZ		= 4.0;

	}

// Review: Vessel configured as:
// full square-rigged barque schooner, V-hull, moderate turn circle (WBT2) - no penalty to turning circle due to not-so-fine hull shape
// square rigger - does not handle as well upwind, compensate with stays and spanker
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 038> is henceforth complete
// on this day and date Sunday Dec 25 2009, 2009h

//-------------------------------------------------------------------------
// Arcadia Xebec by Elessaria (Ported from PotBS by Rider88)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 108> (WBT2H)  - lateen "LCS"
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "XebecVML";
	refShip.SName	 		= "Arcadia";
	refShip.id				= refShip.Name;
	refShip.Class			= 5;
	refShip.Walk			= "XebecVML";
	refShip.Cannon			= CANNON_TYPE_CARRONADE_LBS18;
	refShip.MaxCaliber		= 9;
	refShip.Weight			= Tonnes2CWT(350);
	refShip.Capacity		= 1500;
	refShip.CannonsQuantity = 30;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew		 = 170;
	refShip.MinCrew		 = 30;
	refShip.Price		   = 85000;
	refShip.HP			  = 3000;
	refShip.SP			  = 200;

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 102;
	refShip.QDeck = "ShipDeck1";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast3.Flag1 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.1; //
	refShip.period.4 = 0.2; //
	refShip.period.5 = 0.1; //
	//Nation
	refShip.england = 0.0; //
	refShip.france = 0.1; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.15; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;
	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.3;

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 12.5;
		refShip.TurnRate		= 80;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 2.4;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 14.0;
		refShip.TurnRate		= 50;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 15;	refShip.InertiaBrakingY		= 10;
		refShip.InertiaAccelerationZ	= 9.0;	refShip.InertiaBrakingZ		= 6.0;

	}

// Review: Vessel configured as:
// lateen ship, V-hull, moderate turn circle (WBT2H)  - littoral combatant
// no squaresail, reduced max speed to 11.5kts
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 108> is henceforth complete
// on this day and date Jan 02 2010, 0859h


//-------------------------------------------------------------------------
// HMS Centurion 1732 by KrisWood and Captain Armstrong
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 185> (WBT4XL)
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name         			= "HMS_Centurion";
	refShip.SName				= "Centurion";
	refShip.id            			= refShip.Name;
	refShip.All				= "Battleship1";
	refShip.Walk				= "Centurion";
	refShip.Class		   		= 3;
	refShip.Cannon				= CANNON_TYPE_LONG_LBS24;
	refShip.MaxCaliber	  		= 24;
	refShip.Weight				= Tonnes2CWT(2500);
	refShip.Capacity			= 3000;
	refShip.CannonsQuantity 		= 68;
	refShip.Cannons.Borts.cannonf.qty 	= 2;
	refShip.Cannons.Borts.cannonb.qty 	= 2;
	refShip.MaxCrew		 		= 700;
	refShip.MinCrew		 		= 140;
	refShip.Price		   		= 375000;
	refShip.HP			 	= 9500;
	refShip.SP			  	= 200;

	refShip.BigPicTexName	= "SHIPS1"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 16;
	refShip.QDeck = "ShipDeck2";
	refShip.CannonsDeck = 2
	refShip.CargoHold = 2;
	refShip.Cabin = "Cabin1";
	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_ENSIGN;
	refShip.Flags.Mast5.Flag2 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.3; //
	refShip.period.3 = 0.2; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 0.3; //
	refShip.france = 0.2; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.2; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanEncounter		= true;
	refShip.CanBuy			= true;

	refShip.WaterLine = 0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.55;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 10.5;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.73;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 10.5;
		refShip.TurnRate		= 25;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 1.0;

	}

// Review: Vessel configured as:
// high seas cruiser, deep draft V-hull, LARGE turn circle (WBT4XL)
//     <SWS - Willemstad Builders' Trials Winter 09 S/N 096> is henceforth complete
// on this day and date Jan 1 2010, 1711h

//-------------------------------------------------------------------------
//      Golden Hind by JRH, Hylie Pistof and Armada
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name				= "GoldenHind";
	refShip.All 				= "Galeon1";
	refShip.id				= "GoldenHind";
	refShip.Class		   		= 6;
	refShip.SName 				= "GaleonEng";
	refShip.Walk  				= "GoldenHind";
	refShip.Cannon				= CANNON_TYPE_LONG_LBS6;
	refShip.MaxCaliber			= 6;
	refShip.Weight				= Tonnes2CWT(450);
	refShip.Capacity			= 2000;
	refShip.CannonsQuantity 		= 22;
	refShip.Cannons.Borts.cannonf.qty 	= 2;
	refShip.Cannons.Borts.cannonb.qty 	= 2;
	refShip.MaxCrew		 		= 95;
	refShip.MinCrew		 		= 12;
	refShip.Price		   		= 26600;
	refShip.HP			 	= 1250;
	refShip.SP			  	= 200;
	refShip.Jetty				= false; // PB

	refShip.BigPicTexName = "SHIPS4"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 66;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";

	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast1.Flag1 = FLAG_ENSIGN;

// <-- KK

	//Period
	refShip.period.0 = 1.0; //
	refShip.period.1 = 0.0; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 1.0; //
	refShip.france = 0.0; //
	refShip.holland = 0.0; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter	= false;
	refShip.CanBuy		= false;
//	refShip.Model = "Fast Galleon"; // KK
	refShip.Type.Trade 	= false;
	refShip.Type.War 	= true;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.3;

	refShip.GeraldSails.rey_a2	= 1;		//??
	refShip.GeraldSails.rey_a3	= 1;		//??

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 9.0;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.6;
		refShip.TurnRate		= 29;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 3.0;
	}

//-------------------------------------------------------------------------
//      English Light Galleon imported from AoP by Grey Roger
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name				= "RN_Galeon_L";
	refShip.All 				= "Galeon1";
	refShip.id				= "RN_Galeon_L";
	refShip.Class		   		= 6;
	refShip.SName 				= "GaleonEng";
	refShip.Walk  				= "GoldenHind";
	refShip.Cannon				= CANNON_TYPE_LONG_LBS6;
	refShip.MaxCaliber			= 6;
	refShip.Weight				= Tonnes2CWT(450);
	refShip.Capacity			= 2000;
	refShip.CannonsQuantity 		= 22;
	refShip.Cannons.Borts.cannonf.qty 	= 2;
	refShip.Cannons.Borts.cannonb.qty 	= 2;
	refShip.MaxCrew		 		= 95;
	refShip.MinCrew		 		= 12;
	refShip.Price		   		= 26600;
	refShip.HP			 	= 1250;
	refShip.SP			  	= 200;
	refShip.Jetty				= false; // PB

	refShip.BigPicTexName = "SHIPS3"; //Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 66;
	refShip.QDeck = "ShipDeck5";
	refShip.CannonsDeck = 1;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_medium";

	refShip.Flags.Mast3.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast1.Flag1 = FLAG_ENSIGN;

// <-- KK

	//Period
	refShip.period.0 = 1.0; //
	refShip.period.1 = 0.3; //
	refShip.period.2 = 0.0; //
	refShip.period.3 = 0.0; //
	refShip.period.4 = 0.0; //
	refShip.period.5 = 0.0; //
	//Nation
	refShip.england = 1.0; //
	refShip.france = 0.05; //
	refShip.holland = 0.05; //
	refShip.portugal = 0.0; //
	refShip.pirate = 0.0; //
	refShip.spain = 0.0; //
	refShip.america = 0.0; //
	refShip.sweden = 0.0; //

	refShip.CanEncounter	= true;
	refShip.CanBuy		= true;
//	refShip.Model = "Fast Galleon"; // KK
	refShip.Type.Trade 	= true;
	refShip.Type.War 	= false;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.3;

	refShip.GeraldSails.rey_a2	= 1;		//??
	refShip.GeraldSails.rey_a3	= 1;		//??

	refShip.RigType = "Bat";

	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 9.0;
		refShip.TurnRate		= 60;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 1.9;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 12.6;
		refShip.TurnRate		= 29;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
		refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 3.0;
	}

// JRH quest -->
//-------------------------------------------------------------------------
// Boat2 by JRH
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "obj_Boat2";
	refShip.id				= "obj_Boat2";
	refShip.unique = true; // PRS3
	refShip.Class		   = 7;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 50;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 10;
	refShip.MinCrew		 = 2;
	refShip.SpeedRate		= 4;
	refShip.TurnRate		= 40;
	refShip.Price		   = 1000;
	refShip.HP			  = 100;
	refShip.SP			  = 100;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.CanBuy	= false; //JRH

	refShip.InertiaAccelerationX	= 5.0;	refShip.InertiaBrakingX		= 3.0;
	refShip.InertiaAccelerationY	= 0.4;	refShip.InertiaBrakingY		= 0.2;
	refShip.InertiaAccelerationZ	= 0.15;	refShip.InertiaBrakingZ		= 0.05;

	// LDH added 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

//-------------------------------------------------------------------------
// Boat2 with a swivelgun by JRH
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "obj_Boat2G";
	refShip.id				= "obj_Boat2G";
	refShip.unique = true; // PRS3
	refShip.Class		   = 7;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 50;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 10;
	refShip.MinCrew		 = 2;
	refShip.SpeedRate		= 50;			//was 4
	refShip.TurnRate		= 40;
	refShip.Price		   = 1000;
	refShip.HP			  = 100;
	refShip.SP			  = 100;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.CanBuy	= false; //JRH

	refShip.InertiaAccelerationX	= 5.0;	refShip.InertiaBrakingX		= 3.0;
	refShip.InertiaAccelerationY	= 0.4;	refShip.InertiaBrakingY		= 0.2;
	refShip.InertiaAccelerationZ	= 0.15;	refShip.InertiaBrakingZ		= 0.05;

	// LDH added 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y	

//-------------------------------------------------------------------------
// Boat2 with 10 soldiers and a swivelgun by JRH
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "obj_Boat2G_crew";
	refShip.id				= "obj_Boat2G_crew";
	refShip.unique = true; // PRS3
	refShip.Class		   = 7;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 50;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 10;
	refShip.MinCrew		 = 2;
	refShip.SpeedRate		= 50;			//was 4
	refShip.TurnRate		= 40;
	refShip.Price		   = 1000;
	refShip.HP			  = 100;
	refShip.SP			  = 100;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.CanBuy	= false; //JRH

	refShip.InertiaAccelerationX	= 5.0;	refShip.InertiaBrakingX		= 3.0;
	refShip.InertiaAccelerationY	= 0.4;	refShip.InertiaBrakingY		= 0.2;
	refShip.InertiaAccelerationZ	= 0.15;	refShip.InertiaBrakingZ		= 0.05;

	// LDH added 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

//-------------------------------------------------------------------------
// Boat2 with 6 soldiers and a swivelgun by JRH
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "obj_Boat2G_small_crew";
	refShip.id				= "obj_Boat2G_small_crew";
	refShip.unique = true; // PRS3
	refShip.Class		   = 7;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 50;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 6;
	refShip.MinCrew		 = 2;
	refShip.SpeedRate		= 50;			//was 4
	refShip.TurnRate		= 40;
	refShip.Price		   = 1000;
	refShip.HP			  = 100;
	refShip.SP			  = 100;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.CanBuy	= false; //JRH

	refShip.InertiaAccelerationX	= 5.0;	refShip.InertiaBrakingX		= 3.0;
	refShip.InertiaAccelerationY	= 0.4;	refShip.InertiaBrakingY		= 0.2;
	refShip.InertiaAccelerationZ	= 0.15;	refShip.InertiaBrakingZ		= 0.05;

	// LDH added 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

//-------------------------------------------------------------------------
// Dead soldier from Boat2G_crew by JRH
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "obj_soldier";
	refShip.id				= "obj_soldier";
	refShip.unique = true; // PRS3
	refShip.Class		   = 7;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 50;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 10;
	refShip.MinCrew		 = 2;
	refShip.SpeedRate		= 4;
	refShip.TurnRate		= 40;
	refShip.Price		   = 1000;
	refShip.HP			  = 100;
	refShip.SP			  = 100;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.CanBuy	= false; //JRH

	refShip.InertiaAccelerationX	= 5.0;	refShip.InertiaBrakingX		= 3.0;
	refShip.InertiaAccelerationY	= 0.4;	refShip.InertiaBrakingY		= 0.2;
	refShip.InertiaAccelerationZ	= 0.15;	refShip.InertiaBrakingZ		= 0.05;

	// LDH added 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

//-------------------------------------------------------------------------
// Boat3 by JRH
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "obj_Boat3";
	refShip.id				= "obj_Boat3";
	refShip.unique = true; // PRS3
	refShip.Class		   = 7;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 50;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 10;
	refShip.MinCrew		 = 2;
	refShip.SpeedRate		= 4;
	refShip.TurnRate		= 40;
	refShip.Price		   = 1000;
	refShip.HP			  = 100;
	refShip.SP			  = 100;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.CanBuy	= false; //JRH

	refShip.InertiaAccelerationX	= 5.0;	refShip.InertiaBrakingX		= 3.0;
	refShip.InertiaAccelerationY	= 0.4;	refShip.InertiaBrakingY		= 0.2;
	refShip.InertiaAccelerationZ	= 0.15;	refShip.InertiaBrakingZ		= 0.05;

	// LDH added 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

//-------------------------------------------------------------------------
// Boat4 by JRH
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "obj_Boat4";
	refShip.id				= "obj_Boat4";
	refShip.unique = true; // PRS3
	refShip.Class		   = 7;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 50;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 10;
	refShip.MinCrew		 = 2;
	refShip.SpeedRate		= 4;
	refShip.TurnRate		= 40;
	refShip.Price		   = 1000;
	refShip.HP			  = 100;
	refShip.SP			  = 100;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.CanBuy	= false; //JRH

	refShip.InertiaAccelerationX	= 5.0;	refShip.InertiaBrakingX		= 3.0;
	refShip.InertiaAccelerationY	= 0.4;	refShip.InertiaBrakingY		= 0.2;
	refShip.InertiaAccelerationZ	= 0.15;	refShip.InertiaBrakingZ		= 0.05;

	// LDH added 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

//-------------------------------------------------------------------------
// Boat4S by JRH
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "obj_Boat4S";
	refShip.id				= "obj_Boat4S";
	refShip.unique = true; // PRS3
	refShip.Class		   = 7;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 50;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 10;
	refShip.MinCrew		 = 2;
	refShip.SpeedRate		= 4;
	refShip.TurnRate		= 40;
	refShip.Price		   = 1000;
	refShip.HP			  = 100;
	refShip.SP			  = 100;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.CanBuy	= false; //JRH

	refShip.InertiaAccelerationX	= 5.0;	refShip.InertiaBrakingX		= 3.0;
	refShip.InertiaAccelerationY	= 0.4;	refShip.InertiaBrakingY		= 0.2;
	refShip.InertiaAccelerationZ	= 0.15;	refShip.InertiaBrakingZ		= 0.05;

	// LDH added 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

//-------------------------------------------------------------------------
// Treasurechest by JRH
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "obj_treasurechest";
	refShip.id				= "obj_treasurechest";
	refShip.unique = true; // PRS3
	refShip.Class		   = 7;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 50;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 10;
	refShip.MinCrew		 = 2;
	refShip.SpeedRate		= 4;
	refShip.TurnRate		= 40;
	refShip.Price		   = 1000;
	refShip.HP			  = 100;
	refShip.SP			  = 100;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.CanBuy	= false; //JRH

	refShip.InertiaAccelerationX	= 5.0;	refShip.InertiaBrakingX		= 3.0;
	refShip.InertiaAccelerationY	= 0.4;	refShip.InertiaBrakingY		= 0.2;
	refShip.InertiaAccelerationZ	= 0.15;	refShip.InertiaBrakingZ		= 0.05;

	// LDH added 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

//-------------------------------------------------------------------------
// Sacks1 by JRH
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "obj_sacks1";
	refShip.id				= "obj_sacks1";
	refShip.unique = true; // PRS3
	refShip.Class		   = 7;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 50;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 10;
	refShip.MinCrew		 = 2;
	refShip.SpeedRate		= 4;
	refShip.TurnRate		= 40;
	refShip.Price		   = 1000;
	refShip.HP			  = 100;
	refShip.SP			  = 100;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.CanBuy	= false; //JRH

	refShip.InertiaAccelerationX	= 5.0;	refShip.InertiaBrakingX		= 3.0;
	refShip.InertiaAccelerationY	= 0.4;	refShip.InertiaBrakingY		= 0.2;
	refShip.InertiaAccelerationZ	= 0.15;	refShip.InertiaBrakingZ		= 0.05;

	// LDH added 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

//-------------------------------------------------------------------------
// Sacks2 by JRH
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "obj_sacks2";
	refShip.id				= "obj_sacks2";
	refShip.unique = true; // PRS3
	refShip.Class		   = 7;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 50;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 10;
	refShip.MinCrew		 = 2;
	refShip.SpeedRate		= 4;
	refShip.TurnRate		= 40;
	refShip.Price		   = 1000;
	refShip.HP			  = 100;
	refShip.SP			  = 100;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.CanBuy	= false; //JRH

	refShip.InertiaAccelerationX	= 5.0;	refShip.InertiaBrakingX		= 3.0;
	refShip.InertiaAccelerationY	= 0.4;	refShip.InertiaBrakingY		= 0.2;
	refShip.InertiaAccelerationZ	= 0.15;	refShip.InertiaBrakingZ		= 0.05;

	// LDH added 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

//-------------------------------------------------------------------------
// Sacks3 by JRH
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "obj_sacks3";
	refShip.id				= "obj_sacks3";
	refShip.unique = true; // PRS3
	refShip.Class		   = 7;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 50;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 10;
	refShip.MinCrew		 = 2;
	refShip.SpeedRate		= 4;
	refShip.TurnRate		= 40;
	refShip.Price		   = 1000;
	refShip.HP			  = 100;
	refShip.SP			  = 100;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.CanBuy	= false; //JRH

	refShip.InertiaAccelerationX	= 5.0;	refShip.InertiaBrakingX		= 3.0;
	refShip.InertiaAccelerationY	= 0.4;	refShip.InertiaBrakingY		= 0.2;
	refShip.InertiaAccelerationZ	= 0.15;	refShip.InertiaBrakingZ		= 0.05;

	// LDH added 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;


//-------------------------------------------------------------------------
// PrisonShip1 by JRH (Pinnace1)
//-------------------------------------------------------------------------
	// PS -->
	makeref(refShip,ShipsTypes[n]);
	n++;
	// PS <-- makeref(refShip,ShipsTypes[SHIP_PINNACE_FRANCE]);
	refShip.Name			= "obj_PrisonShip1";					//was Pinnace1
	refShip.id				= "obj_PrisonShip1";				//was refShip.Name
	refShip.Class		   = 3;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS12;
	refShip.MaxCaliber		= 12;
	refShip.Weight			= Tonnes2CWT(550);
	refShip.Capacity		= 3200;
	refShip.CannonsQuantity = 24;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 6;
	// NK <--
	refShip.MaxCrew		 = 300;
	refShip.MinCrew		 = 60;
	refShip.SpeedRate		= 11;
	refShip.TurnRate		= 27;
	refShip.Price		   = 70000;
	refShip.HP			  = 4000;
	refShip.SP			  = 100;
	refShip.AbordageLocation = "BOARDING_PINNACE";

	refShip.Type.Trade = true;
	refShip.Type.War = false;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.CanBuy	= false;

	refShip.WaterLine = 0.5;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 1.3;
	//refShip.TurnDependWeight = 0.8;

	refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 2.0;
	refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
	refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 3.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
// PrisonShip2 by JRH (Battleship3)
//-------------------------------------------------------------------------
	// PS -->
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			 = "obj_PrisonShip2";				//JRH change
	refShip.all				 = "Lineship";
	refShip.SName			 = "Battleship3";				//JRH change
	refShip.id				 = "obj_PrisonShip2";
	refShip.Class		     = 1;
	refShip.Walk			 = "";
	refShip.Cannon			 = CANNON_TYPE_LONG_LBS32;
	refShip.MaxCaliber	     = 32;
	refShip.Weight			 = Tonnes2CWT(3000);
	refShip.Capacity		 = 6000;
	refShip.CannonsQuantity  = 76;
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	refShip.MaxCrew			 = 820;
	refShip.MinCrew			 = 160;
	refShip.SpeedRate		 = 11;
	refShip.TurnRate		 = 24.8;
	refShip.Price			 = 450000;
	refShip.HP				 = 17000;
	refShip.SP				 = 100;
	refShip.AbordageLocation = "BOARDING_BATTLESHIP";

	refShip.Type.Trade = false;
	refShip.Type.War = true;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.CanBuy	= false;

	refShip.WaterLine = 0.0;
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.9;

	refShip.InertiaAccelerationX	= 0.3;	refShip.InertiaBrakingX		= 2.0;
	refShip.InertiaAccelerationY	= 7;	refShip.InertiaBrakingY		= 6;
	refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;

//-------------------------------------------------------------------------
//  Cutter wreck by JRH
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "obj_Cutter_wreck";
	refShip.All				= "Sloop1"
	refShip.id				= refShip.Name;
	refShip.SName			= "Cutter1N";
	refShip.Class			= 7;
	refShip.Walk			= "obj_Cutter_wreck";
	refShip.Cannon			= CANNON_TYPE_CARRONADE_LBS12;
	refShip.MaxCaliber		= 6;
	refShip.Weight			= Tonnes2CWT(100);
	refShip.Capacity		= 300;
	refShip.CannonsQuantity = 12;
	// NK cannon qtys 05-04-18 -->
	refShip.Cannons.Borts.cannonf.qty = 2;
	refShip.Cannons.Borts.cannonb.qty = 2;
	// NK <--
	refShip.MaxCrew	  = 54;
	refShip.MinCrew	  = 11;
	refShip.Price			= 39600;
	refShip.HP 		   = 1500;
	refShip.SP 		   = 200;

	refShip.BigPicTexName	= "SHIPS2"; // Armada
// KK -->
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 8;
	refShip.QDeck = "ShipDeck4";
	refShip.CannonsDeck = 0;
	refShip.CargoHold = 1;
	refShip.Cabin = "Cabin_small";
	refShip.Flags.Mast2.Flag1 = FLAG_PENNANT;
	refShip.Flags.Mast2.Flag2 = FLAG_ENSIGN;
// <-- KK

	//Period
	refShip.period.0 = 0.1; //
	refShip.period.1 = 0.6; //
	refShip.period.2 = 0.8; //
	refShip.period.3 = 0.9; //
	refShip.period.4 = 0.9; //
	refShip.period.5 = 1.0; //
	//Nation
	refShip.england = 0.5; //
	refShip.france = 0.5; //
	refShip.holland = 0.5; //
	refShip.portugal = 0.5; //
	refShip.pirate = 0.4; //
	refShip.spain = 0.5; //
	refShip.america = 0.3; //
	refShip.sweden = 0.0; //


	refShip.Model = "Cutter"; // KK
	refShip.Type.Trade = false;
	refShip.Type.War = true;
	refShip.CanBuy		= true;
	refShip.CanEncounter	= true;

	refShip.RigType		 = "Slo";
	refShip.WaterLine = 0.75;			//original was 0.0
	refShip.SpeedDependWeight = 0.3;
	refShip.SubSeaDependWeight = 0.3;

	refShip.Height.Bombs.Y 		 = 1.0;  refShip.Height.Bombs.DY	 = 0.5;
	refShip.Height.Grapes.Y		 = 2.0;  refShip.Height.Grapes.DY	 = 1.0;
	refShip.Height.Knippels.Y		 = 10.0; refShip.Height.Knippels.DY  = 8.0;
	refShip.Height.Balls.Y 		 = 1.0;  refShip.Height.Balls.DY	 = 0.5;


	if(iRealismMode>0 || REALISTIC_SHIP_INERTIA){
		refShip.SpeedRate		= 11.2;//BB was 11.0
		refShip.TurnRate		= 95;
		refShip.InertiaAccelerationX	= 4;	refShip.InertiaBrakingX		= 0.4;
		refShip.InertiaAccelerationY	= 3;	refShip.InertiaBrakingY		= 0.5;
		refShip.InertiaAccelerationZ	= 2.5;	refShip.InertiaBrakingZ		= 2.0;
	}else{
		refShip.SpeedRate		= 15.0;
		refShip.TurnRate		= 70;
		refShip.InertiaAccelerationX	= 0.2;	refShip.InertiaBrakingX		= 0.5;
		refShip.InertiaAccelerationY	= 10;	refShip.InertiaBrakingY		= 6;
		refShip.InertiaAccelerationZ	= 4.0;	refShip.InertiaBrakingZ		= 3.0;
	}


//-------------------------------------------------------------------------
// elevator3 by JRH
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "obj_elevator3";
	refShip.id				= "obj_elevator3";
	refShip.unique = true; // PRS3
	refShip.Class		   = 7;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 50;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 10;
	refShip.MinCrew		 = 2;
	refShip.SpeedRate		= 4;
	refShip.TurnRate		= 40;
	refShip.Price		   = 1000;
	refShip.HP			  = 100;
	refShip.SP			  = 100;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.CanBuy	= false; //JRH

	refShip.InertiaAccelerationX	= 5.0;	refShip.InertiaBrakingX		= 3.0;
	refShip.InertiaAccelerationY	= 0.4;	refShip.InertiaBrakingY		= 0.2;
	refShip.InertiaAccelerationZ	= 0.15;	refShip.InertiaBrakingZ		= 0.05;

	// LDH added 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

//-------------------------------------------------------------------------
// barrel3 by JRH
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "obj_barrel3";
	refShip.id				= "obj_barrel3";
	refShip.unique = true; // PRS3
	refShip.Class		   = 7;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 50;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 10;
	refShip.MinCrew		 = 2;
	refShip.SpeedRate		= 4;
	refShip.TurnRate		= 40;
	refShip.Price		   = 1000;
	refShip.HP			  = 100;
	refShip.SP			  = 100;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.CanBuy	= false; //JRH

	refShip.InertiaAccelerationX	= 5.0;	refShip.InertiaBrakingX		= 3.0;
	refShip.InertiaAccelerationY	= 0.4;	refShip.InertiaBrakingY		= 0.2;
	refShip.InertiaAccelerationZ	= 0.15;	refShip.InertiaBrakingZ		= 0.05;

	// LDH added 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

//-------------------------------------------------------------------------
// barrel3_roll by JRH
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "obj_barrel3_roll";
	refShip.id				= "obj_barrel3_roll";
	refShip.unique = true; // PRS3
	refShip.Class		   = 7;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 50;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 10;
	refShip.MinCrew		 = 2;
	refShip.SpeedRate		= 4;
	refShip.TurnRate		= 40;
	refShip.Price		   = 1000;
	refShip.HP			  = 100;
	refShip.SP			  = 100;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.CanBuy	= false; //JRH

	refShip.InertiaAccelerationX	= 5.0;	refShip.InertiaBrakingX		= 3.0;
	refShip.InertiaAccelerationY	= 0.4;	refShip.InertiaBrakingY		= 0.2;
	refShip.InertiaAccelerationZ	= 0.15;	refShip.InertiaBrakingZ		= 0.05;

	// LDH added 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

//-------------------------------------------------------------------------
// ladder by JRH
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "obj_ladder";
	refShip.id				= "obj_ladder";
	refShip.unique = true; // PRS3
	refShip.Class		   = 7;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 50;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 10;
	refShip.MinCrew		 = 2;
	refShip.SpeedRate		= 4;
	refShip.TurnRate		= 40;
	refShip.Price		   = 1000;
	refShip.HP			  = 100;
	refShip.SP			  = 100;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.CanBuy	= false; //JRH

	refShip.InertiaAccelerationX	= 5.0;	refShip.InertiaBrakingX		= 3.0;
	refShip.InertiaAccelerationY	= 0.4;	refShip.InertiaBrakingY		= 0.2;
	refShip.InertiaAccelerationZ	= 0.15;	refShip.InertiaBrakingZ		= 0.05;

	// LDH added 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

//-------------------------------------------------------------------------
// ladder2 by JRH
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "obj_ladder2";
	refShip.id				= "obj_ladder2";
	refShip.unique = true; // PRS3
	refShip.Class		   = 7;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 50;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 10;
	refShip.MinCrew		 = 2;
	refShip.SpeedRate		= 4;
	refShip.TurnRate		= 40;
	refShip.Price		   = 1000;
	refShip.HP			  = 100;
	refShip.SP			  = 100;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.CanBuy	= false; //JRH

	refShip.InertiaAccelerationX	= 5.0;	refShip.InertiaBrakingX		= 3.0;
	refShip.InertiaAccelerationY	= 0.4;	refShip.InertiaBrakingY		= 0.2;
	refShip.InertiaAccelerationZ	= 0.15;	refShip.InertiaBrakingZ		= 0.05;

	// LDH added 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

//-------------------------------------------------------------------------
// invisible by JRH
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "obj_invisible";
   	refShip.SName			= "obj_invisible";
	refShip.id			= refShip.Name;
	refShip.unique = true; // PRS3
	refShip.Class		   = 7;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 50;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 10;
	refShip.MinCrew		 = 2;
	refShip.SpeedRate		= 4;
	refShip.TurnRate		= 40;
	refShip.Price		   = 1000;
	refShip.HP			  = 100;
	refShip.SP			  = 100;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.CanBuy	= false; //JRH

	refShip.InertiaAccelerationX	= 5.0;	refShip.InertiaBrakingX		= 3.0;
	refShip.InertiaAccelerationY	= 0.4;	refShip.InertiaBrakingY		= 0.2;
	refShip.InertiaAccelerationZ	= 0.15;	refShip.InertiaBrakingZ		= 0.05;

	// LDH added 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

//-------------------------------------------------------------------------
// broken_mast by JRH
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "obj_broken_mast";
	refShip.id				= "obj_broken_mast";
	refShip.unique = true; // PRS3
	refShip.Class		   = 7;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 50;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 10;
	refShip.MinCrew		 = 2;
	refShip.SpeedRate		= 4;
	refShip.TurnRate		= 40;
	refShip.Price		   = 1000;
	refShip.HP			  = 100;
	refShip.SP			  = 100;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.CanBuy	= false; //JRH

	refShip.InertiaAccelerationX	= 5.0;	refShip.InertiaBrakingX		= 3.0;
	refShip.InertiaAccelerationY	= 0.4;	refShip.InertiaBrakingY		= 0.2;
	refShip.InertiaAccelerationZ	= 0.15;	refShip.InertiaBrakingZ		= 0.05;

	// LDH added 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

//-------------------------------------------------------------------------
// hatch12 by JRH
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "obj_hatch12";
	refShip.id				= "obj_hatch12";
	refShip.unique = true; // PRS3
	refShip.Class		   = 7;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 50;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 10;
	refShip.MinCrew		 = 2;
	refShip.SpeedRate		= 4;
	refShip.TurnRate		= 40;
	refShip.Price		   = 1000;
	refShip.HP			  = 100;
	refShip.SP			  = 100;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.CanBuy	= false; //JRH

	refShip.InertiaAccelerationX	= 5.0;	refShip.InertiaBrakingX		= 3.0;
	refShip.InertiaAccelerationY	= 0.4;	refShip.InertiaBrakingY		= 0.2;
	refShip.InertiaAccelerationZ	= 0.15;	refShip.InertiaBrakingZ		= 0.05;

	// LDH added 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

//-------------------------------------------------------------------------
// boat2_down by JRH
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "obj_boat2_down";
	refShip.id				= "obj_boat2_down";
	refShip.unique = true; // PRS3
	refShip.Class		   = 7;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 50;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 10;
	refShip.MinCrew		 = 2;
	refShip.SpeedRate		= 4;
	refShip.TurnRate		= 40;
	refShip.Price		   = 1000;
	refShip.HP			  = 100;
	refShip.SP			  = 100;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.CanBuy	= false; //JRH

	refShip.InertiaAccelerationX	= 5.0;	refShip.InertiaBrakingX		= 3.0;
	refShip.InertiaAccelerationY	= 0.4;	refShip.InertiaBrakingY		= 0.2;
	refShip.InertiaAccelerationZ	= 0.15;	refShip.InertiaBrakingZ		= 0.05;

	// LDH added 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

//-------------------------------------------------------------------------
// raft by JRH
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "obj_raft";
	refShip.id				= "obj_raft";
	refShip.unique = true; // PRS3
	refShip.Class		   = 7;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 50;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 10;
	refShip.MinCrew		 = 2;
	refShip.SpeedRate		= 4;
	refShip.TurnRate		= 40;
	refShip.Price		   = 1000;
	refShip.HP			  = 100;
	refShip.SP			  = 100;
	refShip.Flags.Mast0.Flag1 = FLAG_ENSIGN;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.CanBuy	= false; //JRH

	refShip.InertiaAccelerationX	= 5.0;	refShip.InertiaBrakingX		= 3.0;
	refShip.InertiaAccelerationY	= 0.4;	refShip.InertiaBrakingY		= 0.2;
	refShip.InertiaAccelerationZ	= 0.15;	refShip.InertiaBrakingZ		= 0.05;

	// LDH added 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

//-------------------------------------------------------------------------
// raft2 by JRH
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "obj_raft2";
	refShip.id				= "obj_raft2";
	refShip.unique = true; // PRS3
	refShip.Class		   = 7;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 50;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 10;
	refShip.MinCrew		 = 2;
	refShip.SpeedRate		= 4;
	refShip.TurnRate		= 40;
	refShip.Price		   = 1000;
	refShip.HP			  = 100;
	refShip.SP			  = 100;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.CanBuy	= false; //JRH

	refShip.InertiaAccelerationX	= 5.0;	refShip.InertiaBrakingX		= 3.0;
	refShip.InertiaAccelerationY	= 0.4;	refShip.InertiaBrakingY		= 0.2;
	refShip.InertiaAccelerationZ	= 0.15;	refShip.InertiaBrakingZ		= 0.05;

	// LDH added 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

//-------------------------------------------------------------------------
// raft3 by JRH
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "obj_raft3";
	refShip.id				= "obj_raft3";
	refShip.unique = true; // PRS3
	refShip.Class		   = 7;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 50;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 10;
	refShip.MinCrew		 = 2;
	refShip.SpeedRate		= 4;
	refShip.TurnRate		= 40;
	refShip.Price		   = 1000;
	refShip.HP			  = 100;
	refShip.SP			  = 100;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.CanBuy	= false; //JRH

	refShip.InertiaAccelerationX	= 5.0;	refShip.InertiaBrakingX		= 3.0;
	refShip.InertiaAccelerationY	= 0.4;	refShip.InertiaBrakingY		= 0.2;
	refShip.InertiaAccelerationZ	= 0.15;	refShip.InertiaBrakingZ		= 0.05;

	// LDH added 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

//-------------------------------------------------------------------------
// fallen tree by JRH
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "obj_fallen_tree";
	refShip.id				= "obj_fallen_tree";
	refShip.unique = true; // PRS3
	refShip.Class		   = 7;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 50;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 10;
	refShip.MinCrew		 = 2;
	refShip.SpeedRate		= 4;
	refShip.TurnRate		= 40;
	refShip.Price		   = 1000;
	refShip.HP			  = 100;
	refShip.SP			  = 100;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.CanBuy	= false; //JRH

	refShip.InertiaAccelerationX	= 5.0;	refShip.InertiaBrakingX		= 3.0;
	refShip.InertiaAccelerationY	= 0.4;	refShip.InertiaBrakingY		= 0.2;
	refShip.InertiaAccelerationZ	= 0.15;	refShip.InertiaBrakingZ		= 0.05;

	// LDH added 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

//-------------------------------------------------------------------------
// Goldbug by JRH
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "obj_goldbug";
   	refShip.SName			= "obj_goldbug";
	refShip.id			= refShip.Name;
	refShip.unique = true; // PRS3
	refShip.Class		   = "";	//doesn't matter the code is below
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 50;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 9;
	refShip.MinCrew		 = 2;
	refShip.SpeedRate		= 4;
	refShip.TurnRate		= 40;
	refShip.Price		   = 1000;
	refShip.HP			  = 100;
	refShip.SP			  = 100;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.CanBuy	= false; //JRH

	refShip.BigPicTexName	= "SHIPS4"; // Armada
	refShip.BI.Tex = 16;
	refShip.BI.Pic = 8;

	refShip.InertiaAccelerationX	= 5.0;	refShip.InertiaBrakingX		= 3.0;
	refShip.InertiaAccelerationY	= 0.4;	refShip.InertiaBrakingY		= 0.2;
	refShip.InertiaAccelerationZ	= 0.15;	refShip.InertiaBrakingZ		= 0.05;

	// LDH added 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

//-------------------------------------------------------------------------
// skeleton by JRH
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "obj_skeleton";
	refShip.id				= "obj_skeleton";
	refShip.unique = true; // PRS3
	refShip.Class		   = 7;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 50;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 10;
	refShip.MinCrew		 = 2;
	refShip.SpeedRate		= 4;
	refShip.TurnRate		= 40;
	refShip.Price		   = 1000;
	refShip.HP			  = 100;
	refShip.SP			  = 100;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.CanBuy	= false; //JRH

	refShip.InertiaAccelerationX	= 5.0;	refShip.InertiaBrakingX		= 3.0;
	refShip.InertiaAccelerationY	= 0.4;	refShip.InertiaBrakingY		= 0.2;
	refShip.InertiaAccelerationZ	= 0.15;	refShip.InertiaBrakingZ		= 0.05;

	// LDH added 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

//-------------------------------------------------------------------------
// dead animal by JRH
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "obj_fur";
	refShip.id				= "obj_fur";
	refShip.unique = true; // PRS3
	refShip.Class		   = 7;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 50;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 10;
	refShip.MinCrew		 = 2;
	refShip.SpeedRate		= 4;
	refShip.TurnRate		= 40;
	refShip.Price		   = 1000;
	refShip.HP			  = 100;
	refShip.SP			  = 100;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.CanBuy	= false; //JRH

	refShip.InertiaAccelerationX	= 5.0;	refShip.InertiaBrakingX		= 3.0;
	refShip.InertiaAccelerationY	= 0.4;	refShip.InertiaBrakingY		= 0.2;
	refShip.InertiaAccelerationZ	= 0.15;	refShip.InertiaBrakingZ		= 0.05;

	// LDH added 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

//-------------------------------------------------------------------------
// wolf's head by JRH
//-------------------------------------------------------------------------
	makeref(refShip,ShipsTypes[n]);
	n++;
	refShip.Name			= "obj_wolfs_head";
	refShip.id				= "obj_wolfs_head";
	refShip.unique = true; // PRS3
	refShip.Class		   = 7;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 50;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 10;
	refShip.MinCrew		 = 2;
	refShip.SpeedRate		= 4;
	refShip.TurnRate		= 40;
	refShip.Price		   = 1000;
	refShip.HP			  = 100;
	refShip.SP			  = 100;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.CanBuy	= false; //JRH

	refShip.InertiaAccelerationX	= 5.0;	refShip.InertiaBrakingX		= 3.0;
	refShip.InertiaAccelerationY	= 0.4;	refShip.InertiaBrakingY		= 0.2;
	refShip.InertiaAccelerationZ	= 0.15;	refShip.InertiaBrakingZ		= 0.05;

	// LDH added 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

//<-- JRH quest

 //---DO NOT ADD BELOW THIS LINE---
	SHIP_TYPES_QUANTITY = n; // PS
//-------------------------------------------------------------------------
// Boat
//-------------------------------------------------------------------------
	SHIP_BOAT = SHIP_TYPES_QUANTITY;
	makeref(refShip,ShipsTypes[SHIP_BOAT]);
	refShip.Name			= "Boat";
	refShip.id				= "Boat"; // PSX
	refShip.unique = true; // PRS3
	//ShipLookupTable.id.Boat = SHIP_BOAT; // PSX
	refShip.Class		   = 7;
	refShip.Cannon		  = CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber	  = 0;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity		= 50;
	refShip.CannonsQuantity = 0;
	refShip.MaxCrew		 = 10;
	refShip.MinCrew		 = 2;
	refShip.SpeedRate		= 30;
	refShip.TurnRate		= 40;
	refShip.Price		   = 1000;
	refShip.HP			  = 100;
	refShip.SP			  = 100;

	refShip.CanEncounter	= false; // NK just to be sure.
	refShip.WaterLine = -0.1; // PB

	refShip.InertiaAccelerationX	= 5.0;	refShip.InertiaBrakingX		= 3.0;
	refShip.InertiaAccelerationY	= 0.4;	refShip.InertiaBrakingY		= 0.2;
	refShip.InertiaAccelerationZ	= 0.15;	refShip.InertiaBrakingZ		= 0.05;

	// LDH added 12Sep06
	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY 	= 0.5;
	refShip.Height.Grapes.Y 		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0; refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY 	= 0.5;

//-------------------------------------------------------------------------
// FORT
//-------------------------------------------------------------------------
	SHIP_FORT = SHIP_BOAT+1;
	makeref(refShip,ShipsTypes[SHIP_FORT]);
	refShip.Name			= "Fort";
	refShip.id				= "Fort"; // PSX
	refShip.SName			= "Fort"; // KK
	refShip.unique = true; // PRS3
	//ShipLookupTable.id.Fort = SHIP_FORT; // PSX
	refShip.Class		   = 1;
	refShip.Cannon			= CANNON_TYPE_LONG_LBS42;
	refShip.MaxCaliber		= 42;
	refShip.Weight			= Tonnes2CWT(22500);
	refShip.Capacity		= 2700000;
	refShip.CannonsQuantity = 68;
	refShip.MaxCrew		 = 3200;
	refShip.MinCrew		 = 360;
	refShip.SpeedRate		= 11.2;
	refShip.TurnRate		= 20;
	refShip.Price		   = 12000;
	refShip.HP			  = 54000;
	refShip.SP			  = 100;

	if(USE_REAL_CANNONS)
	{
		refShip.Cannons.Borts.cannonf.FireZone	= Degree2Radian(90.0) * FIRE_ANGLE_SCALAR_W;
		refShip.Cannons.Borts.cannonf.FireDir	 = Degree2Radian(0.0);
		refShip.Cannons.Borts.cannonf.FireAngMin	= Degree2Radian(-15.0) * FIRE_ANGLE_SCALAR_H;
		refShip.Cannons.Borts.cannonf.FireAngMax	= Degree2Radian(10.0) * FIRE_ANGLE_SCALAR_H;

		refShip.Cannons.Borts.cannonr.FireZone	= Degree2Radian(90.0) * FIRE_ANGLE_SCALAR_W;
		refShip.Cannons.Borts.cannonr.FireDir	 = Degree2Radian(90.0);
		refShip.Cannons.Borts.cannonr.FireAngMin	= Degree2Radian(-15.0) * FIRE_ANGLE_SCALAR_H;
		refShip.Cannons.Borts.cannonr.FireAngMax	= Degree2Radian(10.0) * FIRE_ANGLE_SCALAR_H;

		refShip.Cannons.Borts.cannonb.FireZone	= Degree2Radian(90.0) * FIRE_ANGLE_SCALAR_W;
		refShip.Cannons.Borts.cannonb.FireDir	 = Degree2Radian(180.0);
		refShip.Cannons.Borts.cannonb.FireAngMin	= Degree2Radian(-15.0) * FIRE_ANGLE_SCALAR_H;
		refShip.Cannons.Borts.cannonb.FireAngMax	= Degree2Radian(10.0) * FIRE_ANGLE_SCALAR_H;

		refShip.Cannons.Borts.cannonl.FireZone	= Degree2Radian(90.0) * FIRE_ANGLE_SCALAR_W;
		refShip.Cannons.Borts.cannonl.FireDir	 = Degree2Radian(270.0);
		refShip.Cannons.Borts.cannonl.FireAngMin	= Degree2Radian(-15.0) * FIRE_ANGLE_SCALAR_H;
		refShip.Cannons.Borts.cannonl.FireAngMax	= Degree2Radian(10.0) * FIRE_ANGLE_SCALAR_H;
	}

	refShip.Flags.NoPennants = true; // Armada: Attempted GA fix
	refShip.CanEncounter	= false;
	SHIP_TYPES_QUANTITY_WITH_FORT = SHIP_FORT + 1;

	// NK/HFM moved here 04-09-05
// KK -->
	makeref(rTypeList, ShipModels);
	DeleteAttribute(rTypeList, "");
	m = 0;
// <-- KK
	for (i = 0; i < SHIP_TYPES_QUANTITY_WITH_FORT - 1; i++)
	{
		makeref(refShip, ShipsTypes[i]);
		if (!CheckAttribute(refShip,"Name")) { continue; }
		if(!SHIP_INTERFACE_SCREENSHOTS) refShip.BigPicTexName = "SHIPS16";
		// PS -->
		if(!CheckAttribute(refShip,"All"))
		{
			if(!CheckAttribute(refShip,"Walk")) { refShip.Walk = refShip.Name; }
			// KK if(!CheckAttribute(refShip,"BI.Pic")) { refShip.BI.Pic = refShip.Name; }
			if(!CheckAttribute(refShip,"SName")) { refShip.SName = refShip.Name; }
		}
		else
		{
			si = GetShipIndex(refShip.All);
			if(si != -1 && si != SHIP_NOTUSED)
			{
				rship2= GetShipbyID(refShip.All);
				if(!CheckAttribute(refShip,"Walk")) refShip.Walk				= rship2.Walk;
				if(!CheckAttribute(refShip,"BI.Tex")) refShip.BI.Tex			= rship2.BI.Tex; // KK
				if(!CheckAttribute(refShip,"BI.Pic")) refShip.BI.Pic			= rship2.BI.Pic; // KK
				if(!CheckAttribute(refShip,"BigPicTexName") || !SHIP_INTERFACE_SCREENSHOTS)
				{
					if(!CheckAttribute(refShip,"BigPic"))
					{
						if(CheckAttribute(rship2,"BigPic")) refShip.BigPic = rship2.BigPic;
						else trace("SHIPS_INIT: " + rship2.id);
					}
					refShip.BigPicTexName = rship2.BigPicTexName;
				}
				if(!CheckAttribute(refShip,"SName")) refShip.SName				= rship2.SName;
// KK -->
				if (!CheckAttribute(refShip, "QDeck") && CheckAttribute(rship2, "QDeck")) refShip.QDeck = rship2.QDeck;
				if (!CheckAttribute(refShip, "CannonsDeck") && CheckAttribute(rship2, "CannonsDeck")) refShip.CannonsDeck = rship2.CannonsDeck;
				if (!CheckAttribute(refShip, "CargoHold") && CheckAttribute(rship2, "CargoHold")) refShip.CargoHold = rship2.CargoHold;
				if (!CheckAttribute(refShip, "Cabin") && CheckAttribute(rship2, "Cabin")) refShip.Cabin = rship2.Cabin;
// <-- KK
			}
			else
			{
				if(!CheckAttribute(refShip,"Walk")) { refShip.Walk = refShip.Name; }
				// KK if(!CheckAttribute(refShip,"BI.Pic")) { refShip.BI.Pic = refShip.Name; }
				if(!CheckAttribute(refShip,"SName")) { refShip.SName = refShip.Name; }
			}

		}
		// PB -->
		if(!CheckAttribute(refShip,"BigPic")) { refShip.BigPic = refShip.id; }
		if(!CheckAttribute(refShip,"BigPicTexName")) { refShip.BigPicTexName = "SHIPS16"; }
		switch(refShip.BigPicTexName)
		{
			case "SHIPS16": refShip.BigPicTex = 0; break;
			case "SHIPS1":  refShip.BigPicTex = 1; break;
			case "SHIPS2":  refShip.BigPicTex = 2; break;
			case "SHIPS3":  refShip.BigPicTex = 3; break;
			case "SHIPS4":  refShip.BigPicTex = 4; break;
			case "SHIPS5":  refShip.BigPicTex = 5; break;
		}

		switch(PERIOD_ACCURACY_LEVEL)
		{
			case 0:
				//Period
				refShip.period.0 = 1.0;
				refShip.period.1 = 1.0;
				refShip.period.2 = 1.0;
				refShip.period.3 = 1.0;
				refShip.period.4 = 1.0;
				refShip.period.5 = 1.0;
			break;
			case 1:
				//Period
				if(GetAttribute(refShip,"period.0") > 0.0)	refShip.period.0 = 1.0;
				if(GetAttribute(refShip,"period.1") > 0.0)	refShip.period.1 = 1.0;
				if(GetAttribute(refShip,"period.2") > 0.0)	refShip.period.2 = 1.0;
				if(GetAttribute(refShip,"period.3") > 0.0)	refShip.period.3 = 1.0;
				if(GetAttribute(refShip,"period.4") > 0.0)	refShip.period.4 = 1.0;
				if(GetAttribute(refShip,"period.5") > 0.0)	refShip.period.5 = 1.0;
				//Nation
				if(GetAttribute(refShip,"england")  > 0.0)	refShip.england  = 1.0;
				if(GetAttribute(refShip,"france")   > 0.0)	refShip.france   = 1.0;
				if(GetAttribute(refShip,"holland")  > 0.0)	refShip.holland  = 1.0;
				if(GetAttribute(refShip,"portugal") > 0.0)	refShip.portugal = 1.0;
				if(GetAttribute(refShip,"pirate")   > 0.0)	refShip.pirate   = 1.0;
				if(GetAttribute(refShip,"spain")    > 0.0)	refShip.spain    = 1.0;
				if(GetAttribute(refShip,"america")  > 0.0)	refShip.america  = 1.0;
				if(GetAttribute(refShip,"sweden")  > 0.0)	refShip.sweden   = 1.0;
			break;
		}
		// PB <--
		// Armada: Ship Tier Mod -->
        refShip.Class = 1;
        if(sti(refShip.MaxCrew) < 900)    refShip.Class = 2;
        if(sti(refShip.MaxCrew) < 550)    refShip.Class = 3;
        if(sti(refShip.MaxCrew) < 400)    refShip.Class = 4;
        if(sti(refShip.MaxCrew) < 250)    refShip.Class = 5;
        if(sti(refShip.MaxCrew) < 100)    refShip.Class = 6;
        if(sti(refShip.MaxCrew) <  60)    refShip.Class = 7;
        if(sti(refShip.MaxCrew) <  30)    refShip.Class = 8;
		if(refShip.id == "boat")		  refShip.Class = "";	//PB
		if(refShip.id == "fort")		  refShip.Class = "";	//PB
		if(HasSubStr(refShip.id, "obj_")) refShip.Class = "";	//JRH
        // Armada: Ship Tier Mod <--
		if(!CheckAttribute(refShip,"CanBuy")) refShip.CanBuy = refShip.CanEncounter; // 04-12-10 to allow for enc but unbuyable or vice versa
		// PS <--
		if (!CheckAttribute(refShip,"TurnRate"))
		{
			Trace("ERROR: Ship " + i + " doesn't have TurnRate attribute");
		}
		if (!CheckAttribute(refShip,"SpeedRate"))
		{
			Trace("ERROR: Ship " + i + " doesn't have SpeedRate attribute");
		}
		if (!CheckAttribute(refShip,"Class"))
		{
			Trace("ERROR: Ship " + i + " doesn't have class attribute");
		}
		else
		{
			if(refShip.Class != "") // PB: To skip class on "floating objects"
			{
				int iClass = sti(refShip.Class);
				if (iClass > MIN_CLASS) { Trace("ERROR: Ship " + i + " class > 8"); } //NK 04-09-13 changed these to defines.
				if (iClass < MAX_CLASS) { Trace("ERROR: Ship " + i + " class < 1"); }
			}
		}
		refShip.InertiaAccelerationY = stf(refShip.InertiaAccelerationY) / 6.0;
		// KNB switch section NK 05-04-10
		if(!USE_REAL_CANNONS)
		{
			si = sti(refShip.MaxCaliber);
			switch(si)
			{
				case 4: refShip.MaxCaliber = 12; break;
				case 6: refShip.MaxCaliber = 12; break;

				case 9: refShip.MaxCaliber = 16; break;

				case 12: refShip.MaxCaliber = 24; break;
				case 18: refShip.MaxCaliber = 24; break;

				case 24: refShip.MaxCaliber = 32; break;
				case 32: refShip.MaxCaliber = 32; break;
				case 42: refShip.MaxCaliber = 32; break;
				refShip.MaxCaliber = 16;
			}
			si = sti(refShip.MaxCaliber);
			refShip.Cannon = GetCannonByTypeAndCaliber("cannon", si);
		}
		// handle arc cannon qtys 05-04-18, auto-assign the L/R arcs. -->
		//make auto-assigned cannon qtys (-1) to 0.
		if(sti(refShip.Cannons.Borts.cannonf.qty) < 0) refShip.Cannons.Borts.cannonf.qty = 0;
		if(sti(refShip.Cannons.Borts.cannonb.qty) < 0) refShip.Cannons.Borts.cannonb.qty = 0;
		if(sti(refShip.Cannons.Borts.cannonl.qty) < 0) refShip.Cannons.Borts.cannonl.qty = 0;
		if(sti(refShip.Cannons.Borts.cannonr.qty) < 0) refShip.Cannons.Borts.cannonr.qty = 0;
		si = sti(refShip.CannonsQuantity); // how many guns
		if(si) // if ship has guns
		{
			si -= sti(refShip.Cannons.Borts.cannonf.qty);
			si -= sti(refShip.Cannons.Borts.cannonb.qty);
			if(si) // if any guns unassigned to chasers, then assign half to each broadside
			{
				refShip.Cannons.Borts.cannonl.qty = si/2;
				refShip.Cannons.Borts.cannonr.qty = si/2;
			}
		}
		// guns qty <--

		// PB -->
		if(SHIPS_WEIGHT)
		{
			MinCapacity			 = makeint(sti(refShip.HP)/100);
			if (sti(refShip.Cannon) != CANNON_TYPE_NONECANNON && sti(refShip.CannonsQuantity) > 0)
			{
				rCannon				 = GetCannonByType(sti(refShip.Cannon));
				CrewPerGun			 = stf(rCannon.caliber);
				if (rCannon.type	== CANNON_NAME_LONG)	CrewPerGun = CrewPerGun / 2.0;
				else										CrewPerGun = CrewPerGun / 6.0;
				CrewPerGun			 = fclamp(1.0, 10.0, CrewPerGun);									// Gun crew no less than 1 and no more than 10
				MinCapacity			+= makeint(0.5*CrewPerGun*sti(refShip.CannonsQuantity));			// We figure half the guns are being loaded at one time
			}
			if (sti(refShip.MinCrew) < MinCapacity)
			{
				refShip.MinCrew  = MinCapacity;
				MinCapacity		 = 10*sti(refShip.CannonsQuantity);
				if (sti(refShip.MaxCrew) < MinCapacity)
				{
					refShip.MaxCrew  = MinCapacity;
				}
			}
		}

		// NOTE: To be rewritten once all ships' cargo capacities are reconsidered
		if(SHIPS_WEIGHT && sti(refShip.Type.War) == true && sti(refShip.Type.Trade) == false)	// For warships
		{
			if (!CheckAttribute(refShip, "SupplyScalar")) refShip.SupplyScalar = 2.0;			// Double amount of supplies
			MinCapacity     = GetSupplyWeight(refShip);											// Required weight for supplies
			MinCapacity    += sti(refShip.Capacity)/3;											// Add 1/3rd of defined cargo capacity
		}
		else																					// For merchant/versatile ships
		{
			MinCapacity     = GetSupplyWeight(refShip);											// Required weight for supplies to ensure those can fit in the cargo hold
			if (sti(refShip.Capacity) > MinCapacity) MinCapacity = sti(refShip.Capacity);		// If supplies can fit, then use full cargo capacity, else use minimum required
		}
		if(SHIPS_WEIGHT)
		{
			MinCapacity     += sti(refShip.CannonsQuantity) * GetCannonWeight(sti(refShip.Cannon));	// Add extra capacity to allow for standard cannon type
			MinCapacity     += sti(refShip.MaxCrew)         * CREW_WEIGHT;							// Add extra capacity to allow for crew
		}
		refShip.Capacity = MinCapacity;
		// PB <--

		// NK/HFM -->
		refShip.InertiaAccelerationZ = stf(refShip.InertiaAccelerationZ) / 4.0;
		refShip.InertiaBrakingZ = stf(refShip.InertiaBrakingZ) / 10.0;
		if (CheckAttribute(refShip, "RigType"))
			sDet = refShip.RigType; // NK bugfix 05-04-10
		else
			sDet = strcut(refShip.name, 0, 2); // KK GetSymbol(refShip.name, 0) + GetSymbol(refShip.name, 1) + GetSymbol(refShip.name, 2);
		// NK new section 05-04-10
		cp = ""; bp = "";
		if (CheckAttribute(refShip, "ClosestPoint"))	cp = refShip.ClosestPoint;
		if (CheckAttribute(refShip, "BestPoint"   ))	bp = refShip.BestPoint;
		if (bNoPennants)								refShip.Flags.NoPennants = true; // KK
		if(cp == "" || bp == "")
		{
			switch (sDet)
			{
				case "Tar":
					refShip.ClosestPoint = 0.15;
					refShip.BestPoint = 0.6;
					// KK refShip.RigType = sDet;
				break;

				case "Bar":
					refShip.ClosestPoint = 0.29;
					refShip.BestPoint = 0.875;
					// KK refShip.RigType = sDet;
				break;

				case "Yac":
					refShip.ClosestPoint = 0.3;
					refShip.BestPoint = 0.8;
					// KK refShip.RigType = sDet;
				break;

				case "Lug":
					refShip.ClosestPoint = 0.225;
					refShip.BestPoint = 0.625;
					// KK refShip.RigType = sDet;
				break;

				case "Xeb":
					// KK refShip.RigType = sDet;
					refShip.ClosestPoint = 0.15;
					refShip.BestPoint = 0.6;
				break;

				case "Slo":
					refShip.ClosestPoint = 0.1;
					refShip.BestPoint = 0.625;
					// KK refShip.RigType = sDet;
				break;

				case "Gal":
					sDet = strcut(refShip.name,0,5);
					if(sDet == "Galeot")
					{
						refShip.ClosestPoint = 0.25;
						refShip.BestPoint = 0.625;
						refShip.RigType = "Gat";
					}
					else
					{
						refShip.ClosestPoint = 0.29;
						refShip.BestPoint = 0.875;
						refShip.RigType = "Gal";
					}
				break;

				case "Gat": // add this 05-04-10
					refShip.ClosestPoint = 0.25;
					refShip.BestPoint = 0.625;
					refShip.RigType = "Gat";
				break;

				case "Sch":
					refShip.ClosestPoint = 0.15;
					refShip.BestPoint = 0.625;
					// KK refShip.RigType = sDet;
				break;

				case "Car":
					refShip.ClosestPoint = 0.29 // KNB was 0.375
					refShip.BestPoint = 0.85; // KNB was 0.875
					// KK refShip.RigType = sDet;
				break;

				case "Fle":
					refShip.ClosestPoint = 0.29
					refShip.BestPoint = 0.875;
					// KK refShip.RigType = sDet;
				break;

				case "Pin":
					refShip.ClosestPoint = 0.29
					refShip.BestPoint = 0.85;
					// KK refShip.RigType = sDet;
				break;

				case "Bri":
					refShip.ClosestPoint = 0.29;
					refShip.BestPoint = 0.8;
					// KK refShip.RigType = sDet;
				break;

				case "Cor":
					refShip.ClosestPoint = 0.29;
					refShip.BestPoint = 0.8;
					// KK refShip.RigType = sDet;
				break;

				case "Fri":
					refShip.ClosestPoint = 0.29;
					refShip.BestPoint = 0.8;
					// KK refShip.RigType = sDet;
				break;

				case "Bat":
					refShip.ClosestPoint = 0.29;
					refShip.BestPoint = 0.875;
					// KK refShip.RigType = sDet;
				break;

				case "Man":
					refShip.ClosestPoint = 0.29;
					refShip.BestPoint = 0.875;
					// KK refShip.RigType = sDet;
				break;

				case "Fea":
					refShip.ClosestPoint = 0.29;
					refShip.BestPoint = 0.875;
					// KK refShip.RigType = sDet;
				break;

				case "Bla":
					refShip.ClosestPoint = 0.29;
					refShip.BestPoint = 0.875;
					// KK refShip.RigType = sDet;
				break;

				case "Btn": // brigantine, KNB 05-04-10
					refShip.ClosestPoint = 0.25;
					refShip.BestPoint = 0.7;
					refShip.RigType = "Btn";
				break;

                                case "Pol": // Polacca, HP 7-18-2018
					refShip.ClosestPoint = 0.22;
					refShip.BestPoint = 0.7;
					refShip.RigType = "Pol";
				break;
// KK -->
				case "1Br":
					refShip.ClosestPoint = 0.3;
					refShip.BestPoint = 0.8;
				break;
				case "2Br":
					refShip.ClosestPoint = 0.3;
					refShip.BestPoint = 0.8;
				break;
// <-- KK
				// 04-09-09 add default case
				if(!CheckAttribute(refShip, "ClosestPoint")) refShip.ClosestPoint = DEFAULT_CLOSESTPOINT;
				if(!CheckAttribute(refShip, "BestPoint")) refShip.BestPoint = DEFAULT_BESTPOINT;
				if(!CheckAttribute(refShip, "RigType")) refShip.RigType = "Fri";
			}
		}
		// NK new 05-04-10 to resume previous cp/bp
		if(cp != "") refShip.Closestpoint = cp;
		if(bp != "") refShip.Bestpoint = bp;
		// NK 05-04-10 <--
		// NK/HFM

		if(DEBUG && !HasSubStr(refShip.id, "obj_")) refShip.model = "all"; // PB: Allow repainting to all ships
		else
		{
			// KK -->
			if (CheckAttribute(refShip, "Model") && !HasSubStr(refShip.model, "Model")) {
				sDet = refShip.Model;
				if (!CheckAttribute(rTypeList, "tmp." + sDet)) {
					rTypeList.tmp.(sDet) = true;
					cp = "m" + m;
					rTypeList.(cp) = sDet;
					m++;
				}
			}
			// <-- KK
			else
			{
				refShip.model = "Model_" + refShip.id; // PB: Set a model for ALL ships to prevent potential CTDs
			}
		}
	}
	DeleteAttribute(rTypeList, "tmp"); // KK
}
