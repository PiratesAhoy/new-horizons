void SL_Reinit()
{
	ref pc = GetMainCharacter();
	ref ch;
	int n;

	// PB: Original values restored -->
	aref gun;

	if (Items_FindItem("pistolbbuss", &gun) >= 0) {	// Blunderbuss
		gun.minlevel    = 8;
		gun.price       = 460;
		gun.dmg_min     = 40.0;
		gun.dmg_max     = 70.0;
		gun.accuracy    = 40;
		DeleteAttribute(gun, "misfire");
	}

	if (Items_FindItem("pistol1", &gun) >= 0) {		// Short Pistol
		gun.minlevel    = 1;
		gun.price       = 150;
		gun.dmg_min     = 35.0;
		gun.dmg_max     = 45.0;
		gun.accuracy    = 40;
	}

	if (Items_FindItem("pistol2", &gun) >= 0) {		// Long Pistol
		gun.minlevel    = 2;
		gun.price       = 208;
		gun.dmg_min     = 30.0;
		gun.dmg_max     = 40.0;
		gun.accuracy    = 60;
	}

	if (Items_FindItem("pistol7", &gun) >= 0) {		// Brace of Small Pistols
		gun.minlevel    = 6;
		gun.price       = 357;
		gun.dmg_min     = 35.0;
		gun.dmg_max     = 45.0;
		gun.accuracy    = 40;
	}

	if (Items_FindItem("PiratesPistol", &gun) >= 0) {	// Pirates Pistol
		gun.minlevel    = 4;
		gun.price       = 254;
		gun.dmg_min     = 40.0;
		gun.dmg_max     = 55.0;
		gun.accuracy    = 50;
	}

	if (Items_FindItem("pistol6", &gun) >= 0) {		// Double-Shot Pistol
		gun.minlevel    = 12;
		gun.price       = 1260;
		gun.dmg_min     = 40.0;
		gun.dmg_max     = 60.0;
		gun.accuracy    = 55;
	}

	if (Items_FindItem("pistol3", &gun) >= 0) {		// Grapeshot Pistol
		gun.minlevel    = 7;
		gun.price       = 402;
		gun.dmg_min     = 50.0;
		gun.dmg_max     = 70.0;
		gun.accuracy    = 30;
	}

	if (Items_FindItem("pistol8", &gun) >= 0) {		// Brace of Mid-size Pistols
		gun.minlevel    = 14;
		gun.price       = 1026;
		gun.dmg_min     = 40.0;
		gun.dmg_max     = 55.0;
		gun.accuracy    = 50;
	}

	if (Items_FindItem("pistol4", &gun) >= 0) {		// Quad-Barrel Pistol
		gun.minlevel    = 20;
		gun.price       = 3620;
		gun.dmg_min     = 45.0;
		gun.dmg_max     = 60.0;
		gun.accuracy    = 45;
	}

	if (Items_FindItem("pistol5", &gun) >= 0) {		// Scrapper Pistol
		gun.minlevel    = 8;
		gun.price       = 653;
		gun.dmg_min     = 40.0;
		gun.dmg_max     = 60.0;
		gun.accuracy    = 55;
	}

	if (Items_FindItem("pistolmtoon", &gun) >= 0) {	// Musketoon
		gun.minlevel    = 6;
		gun.price       = 968;
		gun.dmg_min     = 50.0;
		gun.dmg_max     = 80.0;
		gun.accuracy    = 60;
		DeleteAttribute(gun, "multidmg");
	}

	if (Items_FindItem("pistol9", &gun) >= 0) {		// Brace of Large Pistols
		gun.minlevel    = 17;
		gun.price       = 2286;
		gun.dmg_min     = 50.0;
		gun.dmg_max     = 65.0;
		gun.accuracy    = 50;
	}

	if (Items_FindItem("pistolmket", &gun) >= 0) {		// Musket
		gun.minlevel    = 10;
		gun.price       = 3245;
		gun.dmg_min     = 70.0;
		gun.dmg_max     = 100.0;
		gun.accuracy    = 80;
	}

	if (Items_FindItem("pistol10", &gun) >= 0) {		// Pump Shotgun SLiB
		gun.minlevel    = 20;
		gun.price       = 6572;
		gun.dmg_min     = 60.0;
		gun.dmg_max     = 90.0;
		gun.accuracy    = 60;
		gun.chargeQ     = 3;
		gun.chargespeed = 15;
		gun.shottype    = "pg";
	}
	// PB: Original values restored <--
}
