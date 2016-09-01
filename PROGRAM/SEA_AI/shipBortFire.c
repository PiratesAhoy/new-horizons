void Ship_BortFire()
{
	int cannons_qty, c;
	float	x, y, z, dx, dy, dz, d2x, d2y, d2z;
	string	bortName;
	aref	firedShip;
	ref rCharacter;

	rCharacter = GetCharacter(GetEventData());
	firedShip = GetEventData();
	bortName = GetEventData();
	dx = GetEventData();
	dy = GetEventData();
	dz = GetEventData();
	d2x = GetEventData();
	d2y = GetEventData();
	d2z = GetEventData();
	// boal fix charge 29.11.03 -->
	DeleteAttribute(rCharacter,"ship.changedammo");  //turns out we do need this after all. :} 04-09-15 NK
	//rCharacter.BOAL_ReadyCharge = "0";
	//Log_SetStringToLog("Ship_BortFire " + rCharacter.id + " "+ bortName);
	// boal fix charge 29.11.03 <--

    //gunner shout JRH
	if (JRH_GUNSOUNDS == 1 && IsMainCharacter(rCharacter) == true) { 
		//ballNumber = 0;
		x = stf(rCharacter.ship.pos.x);
		y = stf(rCharacter.ship.pos.y);
		z = stf(rCharacter.ship.pos.z);
		cannons_qty = GetCannonArcQty(rCharacter, GetQuadFromBort(bortName));
		for (c = 0; c < cannons_qty; c++)
		{
			Play3DSound("gunner_shout", x, y, z);
		}
	}

	SendMessage(&SeaOperator, "lisffffff", MSG_SEA_OPERATOR_FIRE, firedShip, bortName, dx, dy, dz, d2x, d2y, d2z);
// KK -->
	if (ENABLE_EXTRA_SOUNDS == 1 && IsMainCharacter(rCharacter) == true) {
		if (CheckAttribute(rCharacter, "Ship.Cannons.DoFireRequest")) DeleteAttribute(rCharacter, "Ship.Cannons.DoFireRequest");
		rCharacter.Ship.Cannons.Borts.(bortName).fired_time = GetSeaTime();
		rCharacter.GetCannonsReloadTime = "";
		rCharacter.GetCannonsReloadTime.quad = bortName;
		Event("CANNON_GET_RECHARGE_TIME", "i", rCharacter);
	}
// <-- KK
}