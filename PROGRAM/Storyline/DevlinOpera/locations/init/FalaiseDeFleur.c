void LocationInitFalaiseDeFleur(ref n)
{
        //------------------------------------

	Locations[n].id = "Wedding_Ballroom";
	locations[n].id.label = "#stown_name# townhall";
	Locations[n].filespath.models = "locations\inside\Residence_BackHall";
	Locations[n].image = "Inside_Residence_BackHall";

	//Town sack
	Locations[n].townsack = "Falaise De Fleur";

	//Sound
	locations[n].type = "residence";
	//locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].models.always.locators = "ResB_l";
	Locations[n].models.always.l1 = "ResB";
	Locations[n].models.always.window = "ResB_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "ResB_p";
	Locations[n].models.day.lights.candles = "candelabrum_small";

	//Night
	Locations[n].models.night.charactersPatch = "ResB_p";
	Locations[n].models.night.lights.candles = "candelabrum_small";

	//Environment
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redrsb_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_De_Fleur_townhall";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "Residence.";
	LAi_LocationFightDisable(&Locations[n], true);


	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

//-------------------------------

	Locations[n].id = "Haraldo_Bedroom";
	locations[n].id.label = "Redmond Townhall. Silehards's Bedroom";
	Locations[n].filespath.models = "locations\inside\ResBedRoom";
	Locations[n].image = "Inside_ResBedRoom";

	//Town sack
	Locations[n].townsack = "Falaise De Fleur"; // NK 04-08-29
	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29

	//Sound
	locations[n].type = "residence";
	//Models
	//Always
	Locations[n].models.always.locators = "bed_l";
	Locations[n].models.always.l1 = "bed";
	Locations[n].models.always.window = "bed_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "bed_p";

	//Night
	Locations[n].models.night.charactersPatch = "bed_p";	

	//Environment
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\redb_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Wedding_Ballroom";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "";
	LAi_LocationFightDisable(&Locations[n], false);

	n = n + 1;

//------------------------------------------------------

	Locations[n].id = "Recovery_House";
	locations[n].id.label = "House";
	Locations[n].filespath.models = "locations\inside\Smallhome";
	Locations[n].image = "Inside_Smallhome";

	//Town sack
	Locations[n].townsack = "Falaise de Fleur";

	//Sound
	locations[n].type = "house";
	locations[n].fastreload = "Falaise_De_Fleur";
	//Models
	//Always
	Locations[n].models.always.locators = "sh_l";
	Locations[n].models.always.house = "sh";
	Locations[n].models.always.window = "sh_w";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 50;
	//Day
	Locations[n].models.day.charactersPatch = "sh_p";

	//Night
	Locations[n].models.night.charactersPatch = "sh_p";

	//Environment
	Locations[n].environment.weather = "true";
	locations[n].lockWeather = "Inside";
	Locations[n].environment.sea = "false";
	Locations[n].models.back = "back\ffsh_";
	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "Falaise_de_fleur_location_03";
	Locations[n].reload.l1.emerge = "home4";
	Locations[n].reload.l1.autoreload = "0";
	Locations[n].reload.l1.label = "#stown_name#.";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].vcskip = true; // KK

	Locations[n].island = "FalaiseDeFleur"; // NK 04-08-29
	n = n + 1;

}
