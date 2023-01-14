void LocationInitIslaDeMuerte(ref n)
{
	// -------------------------------------------------
	Locations[n].id = "IslaDeMuerte_shore_01";
	locations[n].id.label = "Deserted shore";
	locations[n].worldmap = "IslaDeMuerte";
	Locations[n].name = "Deserted shore";
	Locations[n].image = "Outside_Shore_7";
	locations[n].filespath.models = "locations\Outside\Shore_7";

	//Sound
	locations[n].type = "treasure_cave";

	//Models
	//Always
	Locations[n].models.always.locators = "Shore07_l";
	Locations[n].models.always.shore = "Shore07";
	Locations[n].models.always.shore.foam = "1";
	Locations[n].models.always.seabed = "Shore07_sb";
	Locations[n].models.always.grassPatch = "Shore07_g";

	//Day
	locations[n].models.day.charactersPatch = "Shore07_p";
	//Night
	locations[n].models.night.charactersPatch = "Shore07_p";

	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	Locations[n].lockWeather = "IslaDeMuerte";

	//Reload map
	locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "IslaDeMuerte";
	Locations[n].reload.l1.emerge = "reload_1";
// KK -->
	if (VISIT_DECK == 1)
		Locations[n].reload.l1.label = "Ship.";
	else
		Locations[n].reload.l1.label = "Sea.";
// <-- KK
	locations[n].reload.l1.autoreload = "0";
	locations[n].locators_radius.reload.reload1 = 2.0;

	locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "Grotto";
	Locations[n].reload.l2.emerge = "reload2_back";
	Locations[n].reload.l2.label = "Treasure Cave Entrance";
	if(sti(GetStorylineVar(FindCurrentStoryline(), "JACK_SPARROW")) > 0 || sti(GetStorylineVar(FindCurrentStoryline(), "BART_PUZZLES")) > 0)
	{
		Locations[n].reload.l2.disable = "1";
	}
	locations[n].reload.l2.autoreload = "1";
	locations[n].locators_radius.reload.reload2_back = 0.8;

	Locations[n].island = "IslaDeMuerte";
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].id = "Grotto";
	locations[n].id.label = "Cave";
	Locations[n].image = "Outside_Grotto";
	locations[n].filespath.models = "locations\Outside\Grotto";

	//Sound
	locations[n].type = "treasure_cave";
	if(sti(GetStorylineVar(FindCurrentStoryline(), "ISLA_DE_MUERTE")) > 0 && iRealismMode == 0)
		locations[n].box1.items.cursedcoin = 881;	// PB: You can get yourself cursed, but need to find another to uncurse yourself
	else
		locations[n].box1.items.cursedcoin = 882;	// PB: Curse is not applied until you take coins out of the chest

	//Models
	//Always
	Locations[n].models.always.town = "Grotto";
	Locations[n].models.always.seabed = "Grotto_sb";
	Locations[n].models.always.grassPatch = "Grotto_grass";
	Locations[n].models.always.locators = "Grotto_locators";

	Locations[n].models.always.l2 = "Gold";
	Locations[n].models.always.l2.tech = "EnvironmentShader";
	Locations[n].models.always.l2.reflection = 1;

	Locations[n].models.always.Water1 = "water";
	Locations[n].models.always.Water1.uvslide.v0 = 0.0;
	Locations[n].models.always.Water1.uvslide.v1 = 0.0;
	Locations[n].models.always.Water1.tech = "LocationWaterFall";
	Locations[n].models.always.Water1.level = 50;

	Locations[n].models.always.Water2 = "cfall";
	Locations[n].models.always.Water2.uvslide.v0 = 0.3;
	Locations[n].models.always.Water2.uvslide.v1 = 0.0;
	Locations[n].models.always.Water2.tech = "LocationWaterFall";
	Locations[n].models.always.Water2.level = 50;

	//Day
	locations[n].models.day.charactersPatch = "Grotto_patch_day";
	//Night
	locations[n].models.night.charactersPatch = "Grotto_patch_day";

	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	Locations[n].lockWeather = "IslaDeMuerte";

	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "IslaDeMuerte";
	Locations[n].reload.l1.emerge = "reload_1";
// KK -->
	if (VISIT_DECK == 1)
		Locations[n].reload.l1.label = "Ship.";
	else
		Locations[n].reload.l1.label = "Sea.";
// <-- KK
	Locations[n].reload.l1.desable = 1;
	locations[n].reload.l1.autoreload = "0";
	locations[n].locators_radius.reload.reload1_back = 3.0;

	locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "IslaDeMuerte_shore_01";
	Locations[n].reload.l2.emerge = "reload2_back";
	Locations[n].reload.l2.label = "Deserted shore";
	locations[n].reload.l2.autoreload = "1";
	locations[n].locators_radius.reload.reload2_back = 0.8;

	Locations[n].island = "IslaDeMuerte";
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].filespath.models = "locations\Outside\Shore_ship";

	Locations[n].id = "IslaDeMuerte_shore_02";
	locations[n].id.label = "Dead Man's Bay";
	Locations[n].image = "Outside_Shore_Ship";
	//Sound
	locations[n].type = "treasure_cave";

	//Models
	//Always
	Locations[n].models.always.jungle = "ShoreShip";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.locators = "ShoreShip_l";
	Locations[n].models.always.grassPatch = "ShoreShip_g";
	Locations[n].models.always.seabed = "ShoreShip_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan_3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";

	//Day
	Locations[n].models.day.charactersPatch = "ShoreShip_p";
	//Night
	Locations[n].models.night.charactersPatch = "ShoreShip_p";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].lockWeather = "IslaDeMuerte";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "IslaDeMuerte_cavern_1";
	Locations[n].reload.l1.emerge = "reload2";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "The cavern";
	Locations[n].reload.l1.disable = "0";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "IslaDeMuerte_cavern_1";
	Locations[n].reload.l2.emerge = "reload2";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.label = "The cavern";
	Locations[n].reload.l2.disable = "0";
	Locations[n].locators_radius.reload.reload1_back = 0.8;

	Locations[n].reload.l3.name = "reload1_cabin";
	Locations[n].reload.l3.go = "IslaDeMuerte_Cabin";
	Locations[n].reload.l3.emerge = "reload1_back";
	Locations[n].reload.l3.autoreload = "0";
	Locations[n].reload.l3.label = "Captain's Cabin";
	Locations[n].reload.l3.disable = "0";
	Locations[n].locators_radius.reload.reload1_cabin = 1.1;

	Locations[n].reload.l4.name = "reload2_cabin";
	Locations[n].reload.l4.go = "IslaDeMuerte_Cabin";
	Locations[n].reload.l4.emerge = "reload2_back";
	Locations[n].reload.l4.autoreload = "0";
	Locations[n].reload.l4.label = "Captain's Cabin";
	Locations[n].reload.l4.disable = "0";
	Locations[n].locators_radius.reload.reload2_cabin = 1.1;

	Locations[n].reload.l5.name = "sea_back";
	Locations[n].reload.l5.go = "IslaDeMuerte";
	Locations[n].reload.l5.emerge = "reload_2";
	Locations[n].reload.l5.autoreload = "0";
// KK -->
	if (VISIT_DECK == 1)
		Locations[n].reload.l5.label = "Ship.";
	else
		Locations[n].reload.l5.label = "Sea.";
// <-- KK
	Locations[n].locators_radius.reload.sea_back = 3.0;

	Locations[n].island = "IslaDeMuerte";
	n = n + 1;

	//  -------------------------------------------------
	locations[n].id = "IslaDeMuerte_Cabin";
	locations[n].id.label = "Captain's Cabin";
	locations[n].filespath.models = "locations\Inside\ShipyardPirates";
	locations[n].image = "Inside_ShipyardPirates";

	//Town sack
	Locations[n].townsack = "Redmond"; // PB: Otherwise Vanderdecken doesn't sell ships

	//Sound
	locations[n].type = "music_pirate_governor";

	//Models
	//Always
	locations[n].models.always.locators = "ShipyardPirates_locators";
	locations[n].models.always.shipyard = "ShipyardPirates";
	locations[n].models.always.window = "ShipyardPirates_fn";
	Locations[n].models.always.window.tech = "LocationWindows";
	Locations[n].models.always.window.level = 65532;

	//Day
	locations[n].models.day.charactersPatch = "ShipyardPirates_patch";
	//Night
	locations[n].models.night.charactersPatch = "ShipyardPirates_patch";


	//Environment
	locations[n].environment.weather = "true";
	locations[n].environment.sea = "true";
	Locations[n].lockWeather = "IslaDeMuerte";

	//Reload map
	locations[n].reload.l1.name = "reload1_back";
	locations[n].reload.l1.go = "IslaDeMuerte_shore_02";
	locations[n].reload.l1.emerge = "reload1_cabin";
	locations[n].reload.l1.autoreload = "0";
	locations[n].reload.l1.label = "Dead Man's Bay";

	locations[n].reload.l2.name = "reload2_back";
	locations[n].reload.l2.go = "IslaDeMuerte_shore_02";
	locations[n].reload.l2.emerge = "reload2_cabin";
	locations[n].reload.l2.autoreload = "0";
	locations[n].reload.l2.label = "Dead Man's Bay";

	Locations[n].island = "IslaDeMuerte";
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Cavern";

	Locations[n].id = "IslaDeMuerte_Cavern_1";
	locations[n].id.label = "Cavern";
	Locations[n].image = "Inside_Cavern";

	//Sound
	locations[n].type = "treasure_cave";

	//Models
	//Always
	Locations[n].models.always.locators = "cavern_l";
	Locations[n].models.always.l1 = "cavern";
	Locations[n].models.always.l2 = "Crystals";
	Locations[n].models.always.l2.tech = "EnvironmentShader";
	Locations[n].models.always.l2.reflection = 0.25;

	Locations[n].models.always.Waterfall1 = "water";
	Locations[n].models.always.Waterfall1.uvslide.v0 = 0.0;
    Locations[n].models.always.Waterfall1.uvslide.v1 = 0.0;
    Locations[n].models.always.Waterfall1.tech = "LocationWaterFall";
	Locations[n].models.always.Waterfall1.level = 50;

	Locations[n].models.always.Waterfall2 = "cfall";
	Locations[n].models.always.Waterfall2.uvslide.v0 = 0.3;
    Locations[n].models.always.Waterfall2.uvslide.v1 = 0.0;
	Locations[n].models.always.Waterfall2.tech = "LocationWaterFall";
	Locations[n].models.always.Waterfall2.level = 50;

	//Day
	Locations[n].models.day.charactersPatch = "cavern_p";
	//Night
	Locations[n].models.night.charactersPatch = "cavern_p";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].lockWeather = "IslaDeMuerte";

	//Reload map
	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "IslaDeMuerte_shore_02";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.disable = "0";
	Locations[n].reload.l1.label = "Dead Man's Bay";
	Locations[n].locators_radius.reload.reload2 = 0.8;

	Locations[n].reload.l2.name = "reload2_back";
	Locations[n].reload.l2.go = "IslaDeMuerte_shore_02";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.disable = "0";
	Locations[n].reload.l2.label = "Dead Man's Bay";
	Locations[n].locators_radius.reload.reload2_back = 0.8;

	Locations[n].reload.l3.name = "reload1";
	Locations[n].reload.l3.go = "IslaDeMuerte_Cavern_2";
	Locations[n].reload.l3.emerge = "reload1";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "Dead Man's Bay";
	Locations[n].reload.l3.disable = "0";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].reload.l4.name = "reload1_back";
	Locations[n].reload.l4.go = "IslaDeMuerte_Cavern_2";
	Locations[n].reload.l4.emerge = "reload1";
	Locations[n].reload.l4.autoreload = "1";
	Locations[n].reload.l4.label = "Dead Man's Bay";
	Locations[n].reload.l4.disable = "0";
	Locations[n].locators_radius.reload.reload1_back = 0.8;

	Locations[n].island = "IslaDeMuerte";
	n = n + 1;

	//  -------------------------------------------------
	Locations[n].filespath.models = "locations\Inside\Grot";

	Locations[n].id = "IslaDeMuerte_Cavern_2";
	locations[n].id.label = "Cavern";
	Locations[n].image = "Inside_Grot";

	//Sound
	locations[n].type = "treasure_cave";

	//Models
	Locations[n].models.back = "back\grotenv_";
	//Always
	Locations[n].models.always.cave = "Grot";
	Locations[n].models.always.locators = "Grot_l";

	//Day
	Locations[n].models.day.charactersPatch = "Grot_p";
	//Night
	Locations[n].models.night.charactersPatch = "Grot_p";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "false";
	Locations[n].lockWeather = "IslaDeMuerte";

	//Reload map
	Locations[n].reload.l1.name = "reload1";
	Locations[n].reload.l1.go = "IslaDeMuerte_Cavern_1";
	Locations[n].reload.l1.emerge = "reload1";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.disable = "0";
	Locations[n].reload.l1.label = "Cavern";
	Locations[n].locators_radius.reload.reload1 = 0.8;

	Locations[n].reload.l2.name = "reload1_back";
	Locations[n].reload.l2.go = "IslaDeMuerte_Cavern_1";
	Locations[n].reload.l2.emerge = "reload1";
	Locations[n].reload.l2.autoreload = "1";
	Locations[n].reload.l2.disable = "0";
	Locations[n].reload.l2.label = "Cavern";
	Locations[n].locators_radius.reload.reload1_back = 0.8;

	Locations[n].island = "IslaDeMuerte";
	n = n + 1;

   	// -------------------------------------------------
    Locations[n].id = "IslaDeMuerte_shore_03";
	locations[n].id.label = "Witch's Rock";
	Locations[n].filespath.models = "locations\Outside\Shore_3";
	Locations[n].image = "Outside_Shore_3";
	Locations[n].name = "Witch's Rock";

 	//Sound
	locations[n].type = "treasure_cave";

   	//Models
	//Always
	Locations[n].models.always.jungle = "shore03";
	Locations[n].models.always.jungle.foam = "1";
	Locations[n].models.always.locators = "shore03_l";
    Locations[n].models.always.seabed = "shore03_sb";
	Locations[n].models.always.seabed.foam = "1";
	Locations[n].models.always.grassPatch = "Shore03_g";

	Locations[n].models.always.l1 = "plan_1";
	Locations[n].models.always.l1.level = 9;
	Locations[n].models.always.l1.tech = "LocationModelBlend";
	Locations[n].models.always.l2 = "plan_2";
	Locations[n].models.always.l2.level = 8;
	Locations[n].models.always.l2.tech = "LocationModelBlend";
	Locations[n].models.always.l3 = "plan_3";
	Locations[n].models.always.l3.level = 7;
	Locations[n].models.always.l3.tech = "LocationModelBlend";

	//Day
	Locations[n].models.day.charactersPatch = "shore03_p";
	//Night
	Locations[n].models.night.charactersPatch = "shore03_p";

	//Environment
	Locations[n].environment.weather = "true";
	Locations[n].environment.sea = "true";
	Locations[n].lockWeather = "IslaDeMuerte";

	//Reload map
	Locations[n].reload.l1.name = "reload2";
	Locations[n].reload.l1.go = "";
	Locations[n].reload.l1.emerge = "";
	Locations[n].reload.l1.autoreload = "1";
	Locations[n].reload.l1.label = "";
	Locations[n].locators_radius.reload.reload2 = 0.8;

	Locations[n].reload.l3.name = "reload2_back";
	Locations[n].reload.l3.go = "";
	Locations[n].reload.l3.emerge = "";
	Locations[n].reload.l3.autoreload = "1";
	Locations[n].reload.l3.label = "";
	Locations[n].locators_radius.reload.reload2_back = 0.8;

 	Locations[n].reload.l2.name = "reload1";
	Locations[n].reload.l2.go = "IslaDeMuerte";
	Locations[n].reload.l2.emerge = "reload_3";
	Locations[n].reload.l2.autoreload = "0";
// KK -->
	if (VISIT_DECK == 1)
		Locations[n].reload.l2.label = "Ship.";
	else
		Locations[n].reload.l2.label = "Sea.";
// <-- KK
	Locations[n].locators_radius.reload.reload1 = 9.0;

	Locations[n].island = "IslaDeMuerte";
	n = n + 1;
}


