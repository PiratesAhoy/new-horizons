void LocationInitConceicao(ref n)
{
	object lcn;
	ref location;
	makeref(location, lcn);
	// -------------------------------------------------	
	Location.filespath.models = "locations\town_Conceicao\town";

	Location.id = "Conceicao_town";
	location.id.label = "#stown_name# town";
	location.worldmap = "Conceicao";
	Location.image = "Town_Conceicao_Town.tga";

	//Town sack
	Location.townsack = "Conceicao";

	//Sound
	location.type = "town";
	location.fastreload = "Conceicao";
	//Models
	//Always
	Location.models.always.locators = "ConTown_l";
  	Location.models.always.grassPatch = "ConTown_g";
	Location.models.always.town = "ConTown";
	Location.models.always.l1 = "Contown_b02";
	Location.models.always.l1.level = 9;
	Location.models.always.l1.tech = "LocationModelBlend";
	Location.models.always.l2 = "Contown_b03";
	Location.models.always.l2.level = 8;
	Location.models.always.l2.tech = "LocationModelBlend";
	Location.models.always.l3 = "Contown_b04";
	Location.models.always.l3.level = 7;
	Location.models.always.l3.tech = "LocationModelBlend";
	//Day
	Location.models.day.fonar = "ConTown_fd";
	Location.models.day.charactersPatch = "ConTown_pd";
	Location.models.day.jumpPatch = "ConTown_j";
	//Night
	Location.models.night.fonar = "ConTown_fn";
	Location.models.night.charactersPatch = "ConTown_pn";
	Location.models.night.jumpPatch = "ConTown_j";
	//Environment
	Location.environment.weather = "true";
	Location.environment.sea = "false";
	//Reload map
	LAi_LocationFantomsGen(&location, true);
	Location.reload.l1.name = "reload1";
	Location.reload.l1.go = "Conceicao_town_exit";
	Location.reload.l1.emerge = "Reload2";
	Location.reload.l1.autoreload = "0";
	Location.reload.l1.label = "Jungle.";

	Location.reload.l2.name = "reload2";
	Location.reload.l2.go = "Conceicao_Port";
	Location.reload.l2.emerge = "reload1";
	Location.reload.l2.autoreload = "0";
	Location.reload.l2.label = "Sea port.";

	Location.reload.l3.name = "reload4";
	Location.reload.l3.go = "Conceicao_Tavern";
	Location.reload.l3.emerge = "reload1";
	Location.reload.l3.autoreload = "0";
	Location.reload.l3.label = "Tavern.";

	Location.reload.l4.name = "reload18";
	Location.reload.l4.go = "Conceicao_Store";
	Location.reload.l4.emerge = "reload1";
	Location.reload.l4.autoreload = "0";
	Location.reload.l4.label = "Store.";
	Location.reload.l4.close_for_night = 1;

	Location.reload.l5.name = "reload13";
	Location.reload.l5.go = "Conceicao_Shipyard";
	Location.reload.l5.emerge = "reload1";
	Location.reload.l5.autoreload = "0";
	Location.reload.l5.label = "Shipyard.";
	Location.reload.l5.close_for_night = 1;

	Location.reload.l6.name = "reload14";
	Location.reload.l6.go = "Conceicao_townhall";
	Location.reload.l6.emerge = "reload1";
	Location.reload.l6.autoreload = "0";
	Location.reload.l6.label = "Residence.";
	Location.reload.l6.close_for_night = 1;

	Location.reload.l7.name = "reload7";
	Location.reload.l7.go = "Conceicao_church";
	Location.reload.l7.emerge = "reload1";
	Location.reload.l7.autoreload = "0";
	Location.reload.l7.label = "Church.";
	Location.reload.l7.close_for_night = 1;

	Location.reload.l8.name = "reload12";
	Location.reload.l8.go = "Conceicao_UsurerHouse";
	Location.reload.l8.emerge = "reload1";
	Location.reload.l8.autoreload = "0";
	Location.reload.l8.label = "Loanshark's Office.";
	Location.reload.l8.close_for_night = 1;

	Location.reload.l9.name = "reload16";
	Location.reload.l9.go = "Conceicao_TailorsShop";
	Location.reload.l9.emerge = "locator2"; //r1
	Location.reload.l9.autoreload = "0";
	Location.reload.l9.label = "Tailor's Shop.";
	Location.reload.l9.close_for_night = 1;

	Location.reload.l10.name = "reload11";
	Location.reload.l10.go = "Portuguese_Navy";
	Location.reload.l10.emerge = "locator2";
	Location.reload.l10.autoreload = "0";
	Location.reload.l10.label = "Navy Office";

	//Hitman
	Location.reload.l11.name = "reload15";
	Location.reload.l11.go = "Hit_house2";
	Location.reload.l11.emerge = "reload1";
	Location.reload.l11.autoreload = "0";
	Location.reload.l11.label = "House of Amérigo Vieira";	//spell-checked by KAM
	//Hitman

// RobC/Alan_Smithee Blacksmiths -->
	Location.reload.l12.name = "reload6";
	Location.reload.l12.go = "Con_blacksmith";
	Location.reload.l12.emerge = "reload1";
	Location.reload.l12.autoreload = "0";
	Location.reload.l12.label = "Smithy";
	Location.reload.l12.close_for_night = 1;
// RobC/Alan_Smithee Blacksmiths <--

	Location.island = "Conceicao"; // NK 04-08-29
	AddGameLocation(n, &location);

	// -------------------------------------------------

	Location.filespath.models = "locations\Inside\shipyard2";

	Location.id = "Portuguese_Navy";
	location.id.label = "Navy Office";
	Location.image = "";

	//Town sack
	Location.townsack = "Conceicao";

	//Sound
	location.type = "residence";
	location.fastreload = "Conceicao";
	//Models
	//Always
	Location.models.always.locators = "sh02_l";
	Location.models.always.shipyard = "sh02";
	Location.models.always.window = "sh02_w";
	Location.models.always.window.tech = "LocationWindows";
	Location.models.always.window.level = 50;

	//Day
	Location.models.day.charactersPatch = "sh02_p";

	//Night
	Location.models.night.charactersPatch = "sh02_p";

	//Environment
	Location.environment.weather = "false";
	Location.environment.sea = "false";
	Location.models.back = "back\mush2_";
	//Reload map
	Location.reload.l1.name = "locator2";
	Location.reload.l1.go = "Conceicao_town";
	Location.reload.l1.emerge = "reload11";
	Location.reload.l1.autoreload = "0";
	Location.reload.l1.label = "Town";
	LAi_LocationFightDisable(&location, false);
	
	Location.island = "Conceicao"; // NK 04-08-29
	AddGameLocation(n, &location);	
}
