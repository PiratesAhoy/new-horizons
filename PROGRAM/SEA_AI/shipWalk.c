void Ship_Walk_Create()
{
	int charIndex = GetEventData();
	aref ship = GetEventData();
	
	ref ch = GetCharacter(charIndex);
	int shipType = GetCharacterShipType(ch); // PS

	//Trace("Adding ship: " + ShipsTypes[shipType].name);

	// PS -->
	string walk = ShipsTypes[shipType].name;
	if(CheckAttribute(ShipsTypes[shipType],"walk")) walk = ShipsTypes[shipType].walk;

	// TODO: Configure sailor models
	if (ENABLE_SHIP_SAILORS) {
		SendMessage(PeopleOnShip,"lis",AI_MESSAGE_ADD_SHIP, ship, walk);
	}
}
