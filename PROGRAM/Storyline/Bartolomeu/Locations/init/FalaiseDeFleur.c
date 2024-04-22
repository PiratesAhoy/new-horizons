void LocationInitFalaiseDeFleur(ref n)
{
	object lcn;
	ref location;

	makeref(location, lcn);

	// Falaise_de_fleur_location_02 -------------------------------------------------
	location.id = "Falaise_de_fleur_location_02";
	location.id.label = "#stown_name#. Slums.";
	location.worldmap = "Falaise De Fleur";
	location.image = "Town_FalaiseDeFleur_Town_01";

	//Town sack
	location.townsack = "Falaise de Fleur";

	//Sound
	location.type = "town";
	LAi_LocationFantomsGen(&location, true);
	location.fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	location.filespath.models = "locations\Town_FalaiseDeFleur\town_01";
	location.models.always.city = "FF01";
	location.models.always.locators = "FF01_l";
	location.models.always.grassPatch = "FF01_g";
	location.models.always.l1 = "plan_1";
	location.models.always.l1.level = 9;
	location.models.always.l1.tech = "LocationModelBlend";
	location.models.always.l2 = "plan_2";
	location.models.always.l2.level = 8;
	location.models.always.l2.tech = "LocationModelBlend";
	location.models.always.l3 = "plan_3";
	location.models.always.l3.level = 7;
	location.models.always.l3.tech = "LocationModelBlend";

	//Day
	location.models.day.fonar = "FF01_fd";
	location.models.day.charactersPatch = "FF01_p";
	//Night
	location.models.night.fonar = "FF01_fn";
	location.models.night.charactersPatch = "FF01_p";
	//Environment
	location.environment.weather = "true";
	location.environment.sea = "false";
	//Reload map
	location.reload.l1.name = "Falaise_de_fleur_location_02_01";
	location.reload.l1.go = "Falaise_de_fleur_port_01";
	location.reload.l1.emerge = "Falaise_de_fleur_location_01_02";
	location.reload.l1.autoreload = "0";
	location.reload.l1.label = "Sea port.";

	location.reload.l2.name = "Falaise_de_fleur_location_02_03";
	location.reload.l2.go = "Falaise_de_fleur_location_03";
	location.reload.l2.emerge = "Falaise_de_fleur_location_03_02";
	location.reload.l2.autoreload = "0";
	location.reload.l2.label = "#stown_name#. Center.";

	location.reload.l3.name = "Falaise_de_fleur_location_02_perechod";
	location.reload.l3.go = "Falaise_de_Fleur_jungle";
	location.reload.l3.emerge = "reload2";
	location.reload.l3.autoreload = "0";
	location.reload.l3.label = "Jungle.";

	location.reload.l4.name = "locator21";
	location.reload.l4.go = "house_of_Elzire_Ayarai";
	location.reload.l4.emerge = "reload1";
	location.reload.l4.autoreload = "0";
	location.reload.l4.label = "House.";

	location.reload.l5.name = "locator20";
	location.reload.l5.go = "HouseInsideR20";
	location.reload.l5.emerge = "reload1";
	location.reload.l5.autoreload = "0";
	location.reload.l5.label = "House.";

	location.reload.l6.name = "locator19";
	location.reload.l6.go = "Smuggler_Residence";
	location.reload.l6.emerge = "reload1";
	location.reload.l6.autoreload = "0";
	location.reload.l6.label = "House of Luc Merin";

	location.island = "FalaiseDeFleur"; // NK 04-08-29
	AddGameLocation(n, &location);

	//---------------------------------------------------

	location.filespath.models = "locations\inside\mediumHouse";

	location.id = "Smuggler_Residence";
	location.id.label = "House of Luc Merin";
	location.image = "Inside_MediumHouse";

	//Town sack
	location.townsack = "FalaiseDeFleur"; // NK 04-08-29
	location.fastreload = "Falaise_De_Fleur";

	//Sound
	location.type = "house";

	//Models
	//Always
	location.models.always.locators = "MH_l";
	location.models.always.house = "MH";
	//location.models.always.env = "smalltavern_env";
	location.models.always.window = "MH_w";
	location.models.always.window.tech = "LocationWindows";
	location.models.always.window.level = 50;
	//Day
	location.models.day.charactersPatch = "MH_p";

	//Night
	location.models.night.charactersPatch = "MH_p";

	//Environment
	location.environment.weather = "true";
	locations[n].lockWeather = "Inside";
	location.environment.sea = "false";
	location.models.back = "back\doumh_";
	//Reload map
	location.reload.l1.name = "Reload1";
	location.reload.l1.go = "Falaise_de_fleur_location_02";
	location.reload.l1.emerge = "locator19";

	location.vcskip = true; // KK

	location.island = "FalaiseDeFleur"; // NK 04-08-29
	AddGameLocation(n, &location);

	// -------------------------------------------------
}
