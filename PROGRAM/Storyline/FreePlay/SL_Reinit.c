void SL_Reinit()
{
	ref pc = GetMainCharacter();
	ref ch;
	int n;

// KK -->
	if (CharPlayerType == PLAYER_TYPE_CASTAWAY) {
		ShipsTypes[GetShipIndex("Tartane1")].MinCrew = 1;
		ShipsTypes[GetShipIndex("Tartane1")].Price = 100;
		ShipsTypes[GetShipIndex("Tartane2")].MinCrew = 1;
		ShipsTypes[GetShipIndex("Tartane2")].Price = 100;
		ShipsTypes[GetShipIndex("Gunboat")].Price = 4500;
		//ShipsTypes[GetShipIndex("TartaneWar")].Price = 8000;
	}
// <-- KK
}
