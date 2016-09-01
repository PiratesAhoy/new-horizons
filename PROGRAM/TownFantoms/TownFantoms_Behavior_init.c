void InitBehaviors()
{
	DeleteAttribute(TownFantomBehaviors, "");

	aref schedule, curitem;

	/* Notes: 
	If timemask or daymask is not assigned, it is assumed to be always true.
	If chance is not assigned, it is assumed to be 1.0--i.e. do this always.
	timemask operates off three-hour 'timesegs' or time segments.

	Locations: You MAY assign locations. Here is the list of supported locations
	+Home - the fantom's house, or other place of residence.
	+Church - the town's church. If no church is specified, the fantom's home will be used.
	+Town - the town proper. If the town has multiple locations, when the fantom is first checked in a timeseg a random one will be assigned.
	+Port - the town's port.
	+Mansion - the town governor's residence/mansion/house/whatever.
	+Tavern - the town's tavern.
	+Store - the town's store.
	+Shipyard - the town's shipyard.
	+Exit - the area right outside the town's walls.

	You can add more. If you want a town location, add an entry to the town define
	ctown.locations.(loc_general_name) = LocationID;
	(example: for Redmond, ctown.locations.prison = "Redmond_prison"; )
	Then you can use loc = "prison" below.

	If a town has multiple copies of a location, the form is
	ctown.locations.(loc_general_name) = number_of_locations;
	ctown.locations.(loc_general_name).loc0 = ID_of_first_version; and so forth.

	If a location is not found, the entry is DELETED.
	*/
	
	// Male Townsperson, normal religion level.
	TownFantomBehaviors.MaleCitizen_Rel0 = "";
	makearef(schedule, TownFantomBehaviors.MaleCitizen_Rel0);

	// sleep
	schedule.l0 = "Sleep";
	makearef(curitem, schedule.l0);
	curitem.loc = "Home";
	curitem.timemask = "11000001";

	// go to church
	schedule.l1 = "Go to church";
	makearef(curitem, schedule.l1);
	curitem.loc = "Church";
	curitem.timemask = "00110000"; // 6am-noon
	curitem.daymask = "1000000"; // Sunday only
	curitem.chance = 0.75; // might be sick
	
	// stay home from church if above chance fails
	schedule.l2 = "Stay home from church";
	makearef(curitem, schedule.l2);
	curitem.loc = "Home";
	curitem.timemask = schedule.church.timemask;
	curitem.daymask = "1000000"; // Sunday only

	// go to tavern for special
	schedule.l3 = "Tavern special";
	makearef(curitem, schedule.l3);
	curitem.loc = "Tavern";
	curitem.timemask = "00111110";
	curitem.daymask = "0111111";
	curitem.chance = 0.03;

	// go to tavern normal
	schedule.l4 = "Tavern";
	makearef(curitem, schedule.l4);
	curitem.loc = "Tavern";
	curitem.timemask = "00001010";
	curitem.daymask = "0111111";
	curitem.chance = 0.15;

	// buy stuff at store
	schedule.l5 = "Go to store";
	makearef(curitem, schedule.l5);
	curitem.loc = "Tavern";
	curitem.timemask = "00101100";
	curitem.daymask = "0111111";
	curitem.chance = 0.05;

	// walk around in port
	schedule.l6 = "Port";
	makearef(curitem, schedule.l6);
	curitem.loc = "Port";
	curitem.timemask = "00101100";
	curitem.daymask = "0111111";
	curitem.chance = 0.05;

	// walk around the exit
	schedule.l6 = "Play or work outside";
	makearef(curitem, schedule.l6);
	curitem.loc = "Exit";
	curitem.timemask = "00111100";
	curitem.daymask = "1111111";
	curitem.chance = 0.1;

	// walk around town
	schedule.l7 = true;
	makearef(curitem, schedule.l7);
	//curitem.timemask = "00111110";
	curitem.chance = 0.75; // chance of fantom not being there at all

	schedule.qty = 8;
}
