void Ship_OnDead()
{
	int charIndex = GetEventData();

	SendMessage(&Seafoam, "la", MSG_SHIP_DELETE ,&Characters[charIndex]);
	SendMessage(&PeopleOnShip, "la", MSG_SHIP_DELETE ,&Characters[charIndex]);
	SendMessage(&SinkEffect, "la", MSG_SHIP_DELETE ,&Characters[charIndex]);
	SendMessage(&Telescope, "la", MSG_SHIP_DELETE ,&Characters[charIndex]);
}