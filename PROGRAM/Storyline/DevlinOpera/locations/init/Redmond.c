void LocationInitRedmond(ref n)
{
        //------------------------------------

	Locations[n].id = "Storyteller_house";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\MediumHouse";
	Locations[n].image = "Inside_MediumHouse.tga";

	//Town sack
	Locations[n].townsack = "Redmond";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Redmond";
	//Models
	//Always
	Locations[n].models.always.locators = "mh_l";
	Locations[n].models.always.shipyard = "mh";
	Locations[n].models.always.window = "mh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "mh_p";

	//Night
	Locations[n].models.night.charactersPatch = "mh_p";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redmh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Redmond_Port";
	Locations[n].reload.l1.emerge = "Door_4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name# port";

	Locations[n].vcskip = true;

	Locations[n].island = "Redmond"; // NK 04-08-29
	n = n + 1;

}
