void CreateOtherCharacters()
{
	ref ch;

	makeref(ch,Characters[MAX_CHARACTERS+BOAT_CHARACTER]);		// boat character
// NK 05-04-05 NOTE!!! we are NOT replacing this MAX_CHARACTERS with CHARACTERS_QUANTITY!!!
	ch.old.name = "Boat";
	ch.old.lastname = "Character";
	ch.name 	= "Boat";
	ch.lastname = "Character";
	ch.id		= "Boat1234";
	ch.nation	= ENGLAND;
	ch.activity_begin = "0";
	ch.activity_end = "24";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "10";
	ch.skill.Accuracy = "10";
	ch.skill.Cannons = "10";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.Ship.Name = "Boat";
	ch.Ship.Type = SHIP_BOAT_NAME; // PS
	ch.Ship.Stopped = true;

}
