// Most prices adjusted and some code simplified by Sulan 2011-08 
// note taken of initial price, e.g. Sulan (50) = initial price was 50

void InitGoods()
{
	//NK delete old attribs -->
	for(int i = 0; i < GetArraySize(&Goods); i++)
	{
		for(int j = 0; j < GetAttributesNum(&Goods[i]); j++) 
	    {
	      DeleteAttribute(&Goods[i], GetAttributeName(GetAttributeN(&Goods[i], j)));
	    }
	}
  // NK

	// KNB - NK add dispersion
	// KNB change stats
	// SWS - WBT project ; rebalancing munitions, 2 Jan 10
	// Balls do splinter damage to crew leading to depletion of manpower proportional to hull integrity
	// grapes should not kill entire crew in one salvo unless massive broadside; we're firing a wooden hulls which have 
	// good ballistic resistance - no option to target enemy deck specifically nor is it easy to hit
	// chainshot - untouched, no bonus to crew damage except for splintering
	// bombs - "heated shot" mainly will set fire to enemy ship, and will not magically destroy 200 crew in one salvo

	Goods[GOOD_BALLS].Name			= "Balls";
	Goods[GOOD_BALLS].Cost			= 2 * GOODS_PRICE_SCALAR;
	Goods[GOOD_BALLS].Weight		= 2;
	Goods[GOOD_BALLS].Units			= 20;
	Goods[GOOD_BALLS].SpeedV0		= 1.0;
	if(USE_REAL_CANNONS)
	{
		Goods[GOOD_BALLS].DamageHull  = 12.0;
		Goods[GOOD_BALLS].DamageRig   = 2.0;
		Goods[GOOD_BALLS].DamageCrew  = 1.10;
		Goods[GOOD_BALLS].Dispersion.X = 2.0;
		Goods[GOOD_BALLS].Dispersion.Y = 6.0;
		Goods[GOOD_BALLS].Dispersion.V = 0.03;
	}
	else
	{
		Goods[GOOD_BALLS].DamageHull	= 10.0;
		Goods[GOOD_BALLS].DamageRig	= 2.0;
		Goods[GOOD_BALLS].DamageCrew	= 1.2;
		Goods[GOOD_BALLS].Dispersion.X = 1.0;
		Goods[GOOD_BALLS].Dispersion.Y = 3.0;
		Goods[GOOD_BALLS].Dispersion.V = 0.03;
	}
	Goods[GOOD_BALLS].skip = true;


	Goods[GOOD_GRAPES].Name		= "Grapes";
	Goods[GOOD_GRAPES].Cost		= 5 * GOODS_PRICE_SCALAR;     // Sulan (10)
	Goods[GOOD_GRAPES].Weight		= 2;
	Goods[GOOD_GRAPES].Units		= 20;
	Goods[GOOD_GRAPES].SpeedV0		= 0.5;
	if(USE_REAL_CANNONS)
	{
		Goods[GOOD_GRAPES].DamageHull = 2.0;
		Goods[GOOD_GRAPES].DamageRig  = 3.0; // was 9.0 SWS/ !? should do more dmg to crew
		Goods[GOOD_GRAPES].DamageCrew = 3.0; // but not excessively high value as 1 crew = 1 hp
		Goods[GOOD_GRAPES].Dispersion.X = 5.0;
		Goods[GOOD_GRAPES].Dispersion.Y = 12.0;
		Goods[GOOD_GRAPES].Dispersion.V = 0.12;
	}
	else
	{
		Goods[GOOD_GRAPES].DamageHull	= 2.0;
		Goods[GOOD_GRAPES].DamageRig	= 3.0;
		Goods[GOOD_GRAPES].DamageCrew	= 3.0;
		Goods[GOOD_GRAPES].Dispersion.X = 2.5;
		Goods[GOOD_GRAPES].Dispersion.Y = 6.0;
		Goods[GOOD_GRAPES].Dispersion.V = 0.06;
	}
	Goods[GOOD_GRAPES].skip = true;

	
	Goods[GOOD_KNIPPELS].Name		= "Knippels";
	Goods[GOOD_KNIPPELS].Cost		= 10 * GOODS_PRICE_SCALAR;  // Sulan (20)
	Goods[GOOD_KNIPPELS].Weight		= 3;
	Goods[GOOD_KNIPPELS].Units		= 20;
	if(USE_REAL_CANNONS)
	{
		Goods[GOOD_KNIPPELS].SpeedV0  = 0.85; // TIH gameplay adjustment Aug24'06 // was 0.9
		Goods[GOOD_KNIPPELS].DamageHull = 4.0;
		Goods[GOOD_KNIPPELS].DamageRig  = 10.0;
		Goods[GOOD_KNIPPELS].DamageCrew = 1.0;
		Goods[GOOD_KNIPPELS].Dispersion.X = 3.0;
		Goods[GOOD_KNIPPELS].Dispersion.Y = 8.0;
		Goods[GOOD_KNIPPELS].Dispersion.V = 0.08;
	}
	else
	{
		Goods[GOOD_KNIPPELS].DamageHull = 4.0;
		Goods[GOOD_KNIPPELS].DamageRig  = 10.0;
		Goods[GOOD_KNIPPELS].DamageCrew = 1.0;
		Goods[GOOD_KNIPPELS].DamageCrew = 1.5;
		Goods[GOOD_KNIPPELS].Dispersion.X = 1.5;
		Goods[GOOD_KNIPPELS].Dispersion.Y = 4.0;
		Goods[GOOD_KNIPPELS].Dispersion.V = 0.08;
	}
	Goods[GOOD_KNIPPELS].skip = true;
	
	Goods[GOOD_BOMBS].Name		= "Bombs";
	Goods[GOOD_BOMBS].Cost      = 25 * GOODS_PRICE_SCALAR; // Sulan  (50)
	Goods[GOOD_BOMBS].Weight    = 3;
	Goods[GOOD_BOMBS].Units     = 20;
	if(USE_REAL_CANNONS) // fort-specific heated shot.
	{
		Goods[GOOD_BOMBS].SpeedV0   = 1.0;
		Goods[GOOD_BOMBS].DamageHull  = 15.0; // NK, since 42's are nerfed. Was 10 for KNB.
		Goods[GOOD_BOMBS].DamageRig   = 4.0;
		Goods[GOOD_BOMBS].DamageCrew  = 1.25;
		Goods[GOOD_BOMBS].Dispersion.X = 2.0;
		Goods[GOOD_BOMBS].Dispersion.Y = 6.0;
		Goods[GOOD_BOMBS].Dispersion.V = 0.03;
		Goods[GOOD_BOMBS].NoTrade = true;  // Doesn't show up in stores
	}
	else
	{
		Goods[GOOD_BOMBS].SpeedV0		= 0.8;
		Goods[GOOD_BOMBS].DamageHull	= 9.0;
		Goods[GOOD_BOMBS].DamageRig	= 4.0;
		Goods[GOOD_BOMBS].DamageCrew	= 1.5;
		Goods[GOOD_BOMBS].Dispersion.X = 1.0;
		Goods[GOOD_BOMBS].Dispersion.Y = 3.0;
		Goods[GOOD_BOMBS].Dispersion.V = 0.03;
		Goods[GOOD_BOMBS].NoTrade = true;  // Sulan
	}
	Goods[GOOD_BOMBS].skip = true;
	// KNB <--

	SortAmmo();
	// NK <--

	Goods[GOOD_SAILCLOTH].Name		= "Sailcloth";
	Goods[GOOD_SAILCLOTH].Weight	= 2;
	Goods[GOOD_SAILCLOTH].Cost		= 6 * GOODS_PRICE_SCALAR; // Sulan (3)
	Goods[GOOD_SAILCLOTH].Units		= 1;
	Goods[GOOD_SAILCLOTH].Swim.Model	= "roll_of_materials";
	Goods[GOOD_SAILCLOTH].Swim.Time		= 10;
	Goods[GOOD_SAILCLOTH].skip = true; // NK

	Goods[GOOD_PLANKS].Name		= "Planks";
	Goods[GOOD_PLANKS].Weight	= 4;
	Goods[GOOD_PLANKS].Cost		= 4 * GOODS_PRICE_SCALAR;
	Goods[GOOD_PLANKS].Units	= 1;
	Goods[GOOD_PLANKS].Swim.Model	= "roll_of_planks";
	Goods[GOOD_PLANKS].Swim.Time	= 15;
	Goods[GOOD_PLANKS].skip = true; // NK

	Goods[GOOD_WHEAT].Name		= "Ration";
	Goods[GOOD_WHEAT].Weight	= 2;
	Goods[GOOD_WHEAT].Cost		= 6 * GOODS_PRICE_SCALAR; // Sulan (4)
	Goods[GOOD_WHEAT].Units		= 1;
	Goods[GOOD_WHEAT].Swim.Model	= "sack";
	Goods[GOOD_WHEAT].Swim.Time		= 10;
	Goods[GOOD_WHEAT].skip = true; // NK

	Goods[GOOD_EBONY].Name		= "Ebony";
	Goods[GOOD_EBONY].Weight	= 6;
	Goods[GOOD_EBONY].Cost		= 65 * GOODS_PRICE_SCALAR; // Sulan (26)
	Goods[GOOD_EBONY].Units		= 1;

	Goods[GOOD_CHOCOLATE].Name		= "Chocolate";
	Goods[GOOD_CHOCOLATE].Weight	= 2;
	Goods[GOOD_CHOCOLATE].Cost		= 18 * GOODS_PRICE_SCALAR; // Sulan (14)
	Goods[GOOD_CHOCOLATE].Units		= 1;
	Goods[GOOD_CHOCOLATE].Swim.Model	= "bale";
	Goods[GOOD_CHOCOLATE].Swim.Time		= 5;

	Goods[GOOD_SUGAR].Name		= "Sugar";
	Goods[GOOD_SUGAR].Weight	= 2;
	Goods[GOOD_SUGAR].Cost		= 12 * GOODS_PRICE_SCALAR;   // Sulan (6)
	Goods[GOOD_SUGAR].Units		= 1;

	Goods[GOOD_WINE].Name		= "Wine";
	Goods[GOOD_WINE].Weight		= 2;
	Goods[GOOD_WINE].Cost		= 20 * GOODS_PRICE_SCALAR;     // Sulan (10)
	Goods[GOOD_WINE].Units		= 1;

	Goods[GOOD_LINEN].Name		= "Linen";
	Goods[GOOD_LINEN].Weight	= 3;
	Goods[GOOD_LINEN].Cost		= 16 * GOODS_PRICE_SCALAR;    // Sulan (8)
	Goods[GOOD_LINEN].Units		= 1;
	Goods[GOOD_LINEN].Swim.Model	= "roll_of_rolls";
	Goods[GOOD_LINEN].Swim.Time		= 10;

	Goods[GOOD_RUM].Name		= "Rum";
	Goods[GOOD_RUM].Weight		= 1;
	Goods[GOOD_RUM].Cost		= 17 * GOODS_PRICE_SCALAR;     // Sulan (6)
	Goods[GOOD_RUM].Units		= 1;
	Goods[GOOD_RUM].Swim.Model	= "barrel";
	Goods[GOOD_RUM].Swim.Time	= 10;
	Goods[GOOD_RUM].skip = true; // NK

	Goods[GOOD_TOBACCO].Name	= "Tobacco";
	Goods[GOOD_TOBACCO].Weight	= 4;
	Goods[GOOD_TOBACCO].Cost	= 31 * GOODS_PRICE_SCALAR;    // Sulan (12)
	Goods[GOOD_TOBACCO].Units	= 1;
	Goods[GOOD_TOBACCO].Swim.Model	= "bale";
	Goods[GOOD_TOBACCO].Swim.Time	= 5;

	Goods[GOOD_COFFEE].Name		= "Coffee";
	Goods[GOOD_COFFEE].Weight	= 2;
	Goods[GOOD_COFFEE].Cost		= 28 * GOODS_PRICE_SCALAR;   // Sulan (14)
	Goods[GOOD_COFFEE].Units	= 1;
	Goods[GOOD_COFFEE].Swim.Model	= "sack";
	Goods[GOOD_COFFEE].Swim.Time	= 5;

	Goods[GOOD_MAHOGANY].Name	= "Mahogany";
	Goods[GOOD_MAHOGANY].Weight	= 4;
	Goods[GOOD_MAHOGANY].Cost	= 42 * GOODS_PRICE_SCALAR;   // Sulan (16)
	Goods[GOOD_MAHOGANY].Units	= 1;
	Goods[GOOD_MAHOGANY].Swim.Model	= "roll_of_planks";
	Goods[GOOD_MAHOGANY].Swim.Time	= 15;

	Goods[GOOD_CINNAMON].Name	= "Cinnamon";
	Goods[GOOD_CINNAMON].Weight	= 2;
	Goods[GOOD_CINNAMON].Cost	= 23 * GOODS_PRICE_SCALAR;   // Sulan (16)
	Goods[GOOD_CINNAMON].Units	= 1;
	Goods[GOOD_CINNAMON].Swim.Model	= "bale";
	Goods[GOOD_CINNAMON].Swim.Time	= 5;

	Goods[GOOD_COPRA].Name		= "Copra";
	Goods[GOOD_COPRA].Weight	= 4;
	Goods[GOOD_COPRA].Cost		= 12 * GOODS_PRICE_SCALAR;    // Sulan (6)
	Goods[GOOD_COPRA].Units		= 1;
	Goods[GOOD_COPRA].Swim.Model	= "basket";
	Goods[GOOD_COPRA].Swim.Time		= 10;

	Goods[GOOD_PAPRIKA].Name	= "Paprika";
	Goods[GOOD_PAPRIKA].Weight	= 2;
	Goods[GOOD_PAPRIKA].Cost	= 18 * GOODS_PRICE_SCALAR;    // Sulan (12)
	Goods[GOOD_PAPRIKA].Units	= 1;
	Goods[GOOD_PAPRIKA].Swim.Model	= "box";
	Goods[GOOD_PAPRIKA].Swim.Time	= 5;

	Goods[GOOD_FRUITS].Name		= "Fruits";
	Goods[GOOD_FRUITS].Weight	= 3;
	Goods[GOOD_FRUITS].Cost		= 16 * GOODS_PRICE_SCALAR;     // Sulan (8)
	Goods[GOOD_FRUITS].Units	= 1;
	Goods[GOOD_FRUITS].Swim.Model	= "box";
	Goods[GOOD_FRUITS].Swim.Time	= 5;

	Goods[GOOD_ALE].Name	= "Ale";
	Goods[GOOD_ALE].Weight	= 1;
	Goods[GOOD_ALE].Cost	= 9 * GOODS_PRICE_SCALAR;          // Sulan (3)
	Goods[GOOD_ALE].Units	= 1;
	Goods[GOOD_ALE].Swim.Model	= "barrel";
	Goods[GOOD_ALE].Swim.Time	= 10;

	Goods[GOOD_SILK].Name	= "Silk";
	Goods[GOOD_SILK].Weight	= 4;
	Goods[GOOD_SILK].Cost	= 34 * GOODS_PRICE_SCALAR;         // Sulan (12)
	Goods[GOOD_SILK].Units	= 1;
	Goods[GOOD_SILK].Swim.Model	= "roll_of_rolls";
	Goods[GOOD_SILK].Swim.Time	= 10;

	Goods[GOOD_CLOTHES].Name	= "Clothes";
	Goods[GOOD_CLOTHES].Weight	= 3;
	Goods[GOOD_CLOTHES].Cost	= 20 * GOODS_PRICE_SCALAR;       // Sulan (8)
	Goods[GOOD_CLOTHES].Units	= 1;
	Goods[GOOD_CLOTHES].Swim.Model	= "bale";
	Goods[GOOD_CLOTHES].Swim.Time	= 10;

	Goods[GOOD_COTTON].Name		= "Cotton";
	Goods[GOOD_COTTON].Weight	= 3;
	Goods[GOOD_COTTON].Cost		= 12 * GOODS_PRICE_SCALAR;       // Sulan (6)
	Goods[GOOD_COTTON].Units	= 1;
	Goods[GOOD_COTTON].Swim.Model	= "bale";
	Goods[GOOD_COTTON].Swim.Time	= 5;

	Goods[GOOD_SANDAL].Name		= "Sandal";
	Goods[GOOD_SANDAL].Weight	= 4;
	Goods[GOOD_SANDAL].Cost		= 40 * GOODS_PRICE_SCALAR;       // Sulan (20)
	Goods[GOOD_SANDAL].Units	= 1;
	Goods[GOOD_SANDAL].Swim.Model	= "box";
	Goods[GOOD_SANDAL].Swim.Time	= 15;

	Goods[GOOD_LEATHER].Name	= "Leather";
	Goods[GOOD_LEATHER].Weight	= 4;
	Goods[GOOD_LEATHER].Cost	= 11 * GOODS_PRICE_SCALAR;       // Sulan (4)
	Goods[GOOD_LEATHER].Units	= 1;
	Goods[GOOD_LEATHER].Swim.Model	= "bale";
	Goods[GOOD_LEATHER].Swim.Time	= 10;

	Goods[GOOD_OIL].Name	= "Oil";
	Goods[GOOD_OIL].Weight	= 2;
	Goods[GOOD_OIL].Cost	= 10 * GOODS_PRICE_SCALAR;            // Sulan (5)
	Goods[GOOD_OIL].Units	= 1;

// added by MAXIMUS [gunpowder mod] --> // TIH --> mod toggle/adjust 7-7-06
	Goods[GOOD_GUNPOWDER].Name	= "Gunpowder";
	Goods[GOOD_GUNPOWDER].Weight = 20;
	Goods[GOOD_GUNPOWDER].Cost	= 30 * GOODS_PRICE_SCALAR;      // Sulan (100)
	Goods[GOOD_GUNPOWDER].Units	= 300;
	Goods[GOOD_GUNPOWDER].Swim.Model = "barrel";
	Goods[GOOD_GUNPOWDER].Swim.Time	= 10;
	if (!CANNONPOWDER_MOD) {
		Goods[GOOD_GUNPOWDER].NoTrade = true;
	}
	Goods[GOOD_GUNPOWDER].skip = true;
// added by MAXIMUS [gunpowder mod] <-- // TIH <-- mod toggle

	// from SLiB Mod by Jack Davidson -->

	Goods[GOOD_GOLD].Name    = "Gold";
	Goods[GOOD_GOLD].Weight  = 2; // TIH was 1: gold weighs the same as silver?
	Goods[GOOD_GOLD].Cost    = 200 * GOODS_PRICE_SCALAR;       // Sulan (50)
	Goods[GOOD_GOLD].Units   = 1;

	Goods[GOOD_SILVER].Name    = "Silver";
	Goods[GOOD_SILVER].Weight  = 2;
	Goods[GOOD_SILVER].Cost    = 124 * GOODS_PRICE_SCALAR;      // Sulan (24)
	Goods[GOOD_SILVER].Units   = 1;

	Goods[GOOD_BRICKS].Name    = "Bricks";
	Goods[GOOD_BRICKS].Weight  = 2; // TIH was 4: bricks weigh more than gold?
	Goods[GOOD_BRICKS].Cost    = 5 * GOODS_PRICE_SCALAR;
	Goods[GOOD_BRICKS].Units   = 1;

	Goods[GOOD_FOOD].Name		= "Wheat";
	Goods[GOOD_FOOD].Weight		= 2;
	Goods[GOOD_FOOD].Cost		= 8 * GOODS_PRICE_SCALAR;          // Sulan (4)
	Goods[GOOD_FOOD].Units		= 1;
	Goods[GOOD_FOOD].Swim.Model	= "sack";
	Goods[GOOD_FOOD].Swim.Time	= 7;

	Goods[GOOD_TREATMENT].Name		= "Medicines";
	Goods[GOOD_TREATMENT].Weight	= 3;
	Goods[GOOD_TREATMENT].Cost		= 27 * GOODS_PRICE_SCALAR;    // Sulan (14)
	Goods[GOOD_TREATMENT].Units		= 1;
	Goods[GOOD_TREATMENT].Swim.Model= "box";
	Goods[GOOD_TREATMENT].Swim.Time	= 5;

	// from SLiB Mod by Jack Davidson <--
}

// NK -->
void SortAmmo()
{
	int curbest = GOOD_BALLS;
	float best = 0.0;
	int i;
	string stype = "ship"; // since forts always use bombs, no need for "fort". But if I rewrite FindOtherBallType, then we'll need one.
	//find best vs. hull
	string type = "DamageHull";
	for(i = GOOD_BALLS; i <= GOOD_BOMBS; i++)// TIH typo fix 7-7-06
	{
		if(stf(Goods[i].(type)) > best) { best = stf(Goods[i].(type)); curbest = i; }
	}
	ShipLookupTable.ammo.(stype).Hull.idx = curbest;
	ShipLookupTable.ammo.(stype).Hull.range = Goods[curbest].SpeedV0;

	//find best vs. rig
	type = "DamageRig";
	curbest = GOOD_BALLS;
	best = 0.0;
	for(i = GOOD_BALLS; i <= GOOD_BOMBS; i++)
	{
		if(stf(Goods[i].(type)) > best) { best = stf(Goods[i].(type)); curbest = i; }
	}
	ShipLookupTable.ammo.(stype).Rig.idx = curbest;
	ShipLookupTable.ammo.(stype).Rig.range = Goods[curbest].SpeedV0;

	//find best vs. crew
	type = "DamageCrew";
	curbest = GOOD_BALLS;
	best = 0.0;
	for(i = GOOD_BALLS; i <= GOOD_BOMBS; i++)
	{
		if(stf(Goods[i].(type)) > best) { best = stf(Goods[i].(type)); curbest = i; }
	}
	ShipLookupTable.ammo.(stype).Crew.idx = curbest;
	ShipLookupTable.ammo.(stype).Crew.range = Goods[curbest].SpeedV0;

	//find best range
	type = "SpeedV0";
	curbest = GOOD_BALLS;
	best = 0.0;
	for(i = GOOD_BALLS; i <= GOOD_BOMBS; i++)
	{
		if(stf(Goods[i].(type)) > best) { best = stf(Goods[i].(type)); curbest = i; }
	}
	ShipLookupTable.ammo.(stype).Range.idx = curbest;

	//find best all-round
	curbest = GOOD_BALLS;
	best = 0.0;
	if(USE_REAL_CANNONS)
	{
		for(i = GOOD_BALLS; i <= GOOD_BOMBS; i++)
		{
			if(stf(Goods[i].DamageHull) + 0.5 * stf(Goods[i].DamageRig) + stf(Goods[i].DamageCrew) > best)
			{ best = stf(Goods[i].DamageHull) + stf(Goods[i].DamageRig) + stf(Goods[i].DamageCrew); curbest = i; }
		}
	}
	else
	{
		for(i = GOOD_BALLS; i <= GOOD_BOMBS; i++)
		{
			if(stf(Goods[i].DamageHull) + stf(Goods[i].DamageRig) + stf(Goods[i].DamageCrew) > best)
			{ best = stf(Goods[i].DamageHull) + stf(Goods[i].DamageRig) + stf(Goods[i].DamageCrew); curbest = i; }
		}
	}
	ShipLookupTable.ammo.(stype).All.idx = curbest;
	ShipLookupTable.ammo.(stype).All.range = Goods[curbest].SpeedV0;
}
// NK <--
