void SL_Reinit()
{
	ref pc = GetMainCharacter();
	ref ch;
	int n;

// KK -->
	aref arMap;
	if (Items_FindItem("mapKhaelRoa_TempleGround", &arMap) >= 0) {
		arMap.price = 0;
		arMap.skiptrade = true;
		arMap.skipsell = true;
	}
	if (Items_FindItem("mapKhaelRoa_TempleUpper", &arMap) >= 0) {
		arMap.price = 0;
		arMap.skiptrade = true;
		arMap.skipsell = true;
	}

	if (GetDifficulty() == DIFFICULTY_SWASHBUCKLER) {
		ShipsTypes[GetShipIndex("Tartane1")].MinCrew = 1;
		ShipsTypes[GetShipIndex("Tartane1")].Price = 100;
		ShipsTypes[GetShipIndex("Tartane2")].MinCrew = 1;
		ShipsTypes[GetShipIndex("Tartane2")].Price = 100;
		ShipsTypes[GetShipIndex("Gunboat")].Price = 4500;
		//ShipsTypes[GetShipIndex("TartaneWar")].Price = 8000;
	}
// <-- KK
}
