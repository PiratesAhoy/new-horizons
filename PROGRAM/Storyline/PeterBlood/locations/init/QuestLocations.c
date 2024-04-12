void LocationInitQuestLocations(ref n)
{
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Estate For Piter Blood Start
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
locations[n].id = "Estate";
locations[n].id.label = "Estate";
locations[n].filespath.models = "locations\Estate";
locations[n].image = "loading\EstateN.tga.tx";
//Sound
locations[n].type = "house";
//Models
//Always
locations[n].models.always.estate = "estate";
locations[n].models.always.windows = "estate_windows";
Locations[n].models.always.windows.tech = "LocationWindows";
Locations[n].models.always.windows.level = 66532;
//VolumeLight
Locations[n].models.always.vlight = "estate_vlight";
Locations[n].models.always.vlight.uvslide.v0 = 0.05;
Locations[n].models.always.vlight.uvslide.v1 = 0.0;
Locations[n].models.always.vlight.tech = "LocationWaterFall";
Locations[n].models.always.vlight.level = 99950;
locations[n].models.always.locators = "estate_locators";
locations[n].models.always.grassPatch = "estate_grass";
//Day
locations[n].models.day.charactersPatch = "estate_patch";
locations[n].models.day.fonar = "estate_fd";
//Night
locations[n].models.night.charactersPatch = "estate_patch";
locations[n].models.night.fonar = "estate_fn";
//Environment
locations[n].environment.weather = "true";
locations[n].environment.sea = "false";
locations[n].environment.weather.rain = false;
Locations[n].QuestlockWeather = "11 Hour";
Locations[n].QuestlockWeather.hours = 11;
Locations[n].QuestlockWeather.minutes = 00;
//Reload map
locations[n].reload.l1.name = "reload3";
locations[n].reload.l1.go = "EstateLordBedRoom";
locations[n].reload.l1.emerge = "reload1";
locations[n].reload.l1.autoreload = "0";
locations[n].reload.l1.label = "Bedroom";
locations[n].reload.l2.name = "reload4";
locations[n].reload.l2.go = "EstateOffice";
locations[n].reload.l2.emerge = "reload1";
locations[n].reload.l2.autoreload = "0";
locations[n].reload.l2.label = "Cabinet";
locations[n].reload.l2.disable = true;
locations[n].boxneedkey.box1 = true;
locations[n].boxneedkey.box1.KeyItem = "key_pitt";
locations[n].locators_radius.item.item1 = 1.0;
locations[n].randitemsstay = true;
n = n + 1;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\
// Estate For Piter Blood Start room
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
locations[n].id = "EstateLordBedRoom";
locations[n].id.label = "Bedroom";
Locations[n].filespath.models = "locations\inside\ResBedRoom";
Locations[n].image = "Inside_ResBedRoom.tga";
//Models
//Sound
locations[n].type = "house";
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
locations[n].environment.weather = "true";
locations[n].lockWeather = "Inside";

Locations[n].environment.sea = "false";
Locations[n].models.back = "back\redb_";
//Environment
locations[n].environment.weather = "true";
locations[n].environment.sea = "false";
Locations[n].QuestlockWeather = "11 Hour";
Locations[n].QuestlockWeather.hours = 11;
Locations[n].QuestlockWeather.minutes = 00;
//Reload map
locations[n].reload.l1.name = "reload1";
locations[n].reload.l1.go = "Estate";
locations[n].reload.l1.emerge = "reload3";
locations[n].reload.l1.autoreload = "0";
locations[n].reload.l1.label = "Estate";
n = n + 1;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Estate For Piter Blood Start room 3
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
locations[n].id = "EstateOffice";
locations[n].id.label = "Cabinet";
locations[n].filespath.models = "locations\EstateRooms\EstateOffice";
locations[n].image = "loading\EstateRoomN.tga.tx";
//Sound
locations[n].type = "residence";
//Models
//Always
locations[n].models.always.EstateOffice = "estateOffice";
locations[n].models.always.windows = "estateOffice_windows";
Locations[n].models.always.windows.tech = "LocationWindows";
Locations[n].models.always.windows.level = 66532;
//VolumeLight
Locations[n].models.always.vlight = "estateOffice_vlight";
Locations[n].models.always.vlight.uvslide.v0 = 0.05;
Locations[n].models.always.vlight.uvslide.v1 = 0.0;
Locations[n].models.always.vlight.tech = "LocationWaterFall";
Locations[n].models.always.vlight.level = 99950;
locations[n].models.always.locators = "estateOffice_locators";
locations[n].models.always.grassPatch = "estateOffice_grass";
//Day
locations[n].models.day.charactersPatch = "estateOffice_patch";
locations[n].models.day.fonar = "estateOffice_fd";
//Night
locations[n].models.night.charactersPatch = "estateOffice_patch";
locations[n].models.night.fonar = "estateOffice_fn";
//Environment
locations[n].environment.weather = "true";
locations[n].environment.sea = "false";
Locations[n].QuestlockWeather = "11 Hour";
Locations[n].QuestlockWeather.hours = 11;
Locations[n].QuestlockWeather.minutes = 00;
//Reload map
locations[n].reload.l1.name = "reload1";
locations[n].reload.l1.go = "Estate";
locations[n].reload.l1.emerge = "reload4";
locations[n].reload.l1.autoreload = "0";
locations[n].reload.l1.label = "Estate";
n = n + 1;
locations[n].id = "Havana_Restoran";
locations[n].id.label = "test";
locations[n].image = "inside\tavern.tga.tx";
//Town sack
locations[n].townsack = "Havana";
locations[n].lockWeather = "Inside";
//Sound
locations[n].type = "house";
locations[n].fastreload = "bermudes";
locations[n].island = "bermudes";
//Models
//Always
locations[n].filespath.models = "locations\inside\Residence09";
locations[n].models.always.locators = "Res09_locators";
locations[n].models.always.l1 = "Res09";
locations[n].models.always.l1.level = 65538;
locations[n].models.always.window = "Res09_windows";
locations[n].models.always.window.tech = "LocationWindows";
locations[n].models.always.window.level = 65539;
Locations[n].models.back = "back\redb_";
//Day
Locations[n].models.day.charactersPatch = "Res09_patch";
//Night
Locations[n].models.night.charactersPatch = "Res09_patch";
//Environment
Locations[n].environment.weather = "true";
Locations[n].environment.sea = "false";
//Reload map
locations[n].reload.l1.name = "reload1";
locations[n].reload.l1.go = "Havana_town";
locations[n].reload.l1.emerge = "houseO1";
n = n + 1;
Locations[n].id = "Test_Fort_1";
locations[n].id.label = "Test";
//Info
Locations[n].image = "outside\Fort.tga.tx";
//Sound
locations[n].type = "fort";
locations[n].townsack = "bermudes";
locations[n].island = "Bermudes";
//Models
Locations[n].filespath.models = "locations\Fort_inside\Test_fort\Fort_3";
Locations[n].models.always.Fort_3 = "Fort_3";
locations[n].models.always.Fort_3.sea_reflection = 1;
Locations[n].models.always.Fort_3.seabed = "Fort_3_sb";
Locations[n].models.always.locators = "Fort_3_locators";
Locations[n].models.always.grassPatch = "Fort_3_grass";
Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
Locations[n].models.always.l1 = "plan1";
Locations[n].models.always.l1.level = 9;
Locations[n].models.always.l1.tech = "LocationModelBlend";
Locations[n].models.always.l2 = "plan2";
Locations[n].models.always.l2.level = 8;
Locations[n].models.always.l2.tech = "LocationModelBlend";
Locations[n].models.always.l3 = "plan3";
Locations[n].models.always.l3.level = 7;
Locations[n].models.always.l3.tech = "LocationModelBlend";
Locations[n].models.always.l4 = "plan4";
Locations[n].models.always.l4.level = 6;
Locations[n].models.always.l4.tech = "LocationModelBlend";
Locations[n].models.always.l5 = "Fort_3_trees";
Locations[n].models.always.l5.tech = "DLightModel";
Locations[n].models.always.l6 = "Fort_3_terra";
//Locations[n].models.always.l6 = "Fort_3_lest";
//Locations[n].models.always.l6.tech = "DLightModel";
//Locations[n].models.always.l7 = "Fort_3_open";
//Locations[n].models.always.l7.tech = "DLightModel";
//Locations[n].models.always.l8 = "Fort_3_close";
//Locations[n].models.always.l8.tech = "DLightModel";
//Day
//locations[n].models.day.charactersPatch = "Fort_3_path";
//locations[n].models.day.charactersPatch = "Fort_3_path_quest";//Патч открытых дверей
locations[n].models.day.charactersPatch = "Fort_3_path_quest1";//Патч закрытых дверей
Locations[n].models.day.FortFonarsDay = "Fort_3_fd";
//Night
//locations[n].models.night.charactersPatch = "Fort_3_path";
//locations[n].models.night.charactersPatch = "Fort_3_path_quest";//Патч открытых дверей
locations[n].models.night.charactersPatch = "Fort_3_path_quest1";//Патч закрытых дверей
Locations[n].models.night.FortBigNight= "Fort_3_fn";
//Environment
locations[n].environment.weather = "true";
locations[n].environment.sea = "true";
//Reload map
locations[n].reload.l1.name = "boat";
locations[n].reload.l1.go = "Hispaniola2";
locations[n].reload.l1.emerge = "reload_7";
locations[n].locators_radius.reload.boat = 9.0;
locations[n].reload.l2.name = "reload2";
locations[n].reload.l2.go = "Test_Fort_1";
locations[n].reload.l2.emerge = "reload3";
locations[n].reload.l3.name = "reload4";
locations[n].reload.l3.go = "Test_Fort_ammo_1";
locations[n].reload.l3.emerge = "reload1";
locations[n].reload.l4.name = "reload3";
locations[n].reload.l4.go = "Test_Fort_1";
locations[n].reload.l4.emerge = "reload2";
locations[n].reload.l5.name = "reload5";
locations[n].reload.l5.go = "";
locations[n].reload.l5.emerge = "reload6";
locations[n].reload.l6.name = "reload7";
locations[n].reload.l6.go = "";
locations[n].reload.l6.emerge = "reload2";
locations[n].reload.l7.name = "reload8";
locations[n].reload.l7.go = "";
locations[n].reload.l7.emerge = "reload3";
n = n + 1;
Locations[n].id = "Test_Fort_2";
locations[n].id.label = "Test";
//Info
Locations[n].image = "outside\Fort.tga.tx";
//Sound
locations[n].type = "fort";
locations[n].townsack = "bermudes";
locations[n].island = "Bermudes";
//Models
Locations[n].filespath.models = "locations\Fort_inside\Test_fort\Fort_4";
Locations[n].models.always.Fort_4 = "Fort_4";
locations[n].models.always.Fort_4.sea_reflection = 1;
Locations[n].models.always.Fort_4.seabed = "Fort_4_sb";
Locations[n].models.always.locators = "Fort_4_locators";
Locations[n].models.always.grassPatch = "Fort_4_grass";
Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
Locations[n].models.always.l1 = "plan1";
Locations[n].models.always.l1.level = 9;
Locations[n].models.always.l1.tech = "LocationModelBlend";
Locations[n].models.always.l2 = "plan2";
Locations[n].models.always.l2.level = 8;
Locations[n].models.always.l2.tech = "LocationModelBlend";
Locations[n].models.always.l3 = "plan3";
Locations[n].models.always.l3.level = 7;
Locations[n].models.always.l3.tech = "LocationModelBlend";
Locations[n].models.always.l4 = "plan4";
Locations[n].models.always.l4.level = 6;
Locations[n].models.always.l4.tech = "LocationModelBlend";
Locations[n].models.always.l5 = "Fort_4_trees";
Locations[n].models.always.l5.tech = "DLightModel";
Locations[n].models.always.l6 = "Fort_4_terra";
//Day
locations[n].models.day.charactersPatch = "Fort_4_path";
//locations[n].models.day.charactersPatch = "Fort_4_path2";
Locations[n].models.day.FortFonarsDay = "Fort_4_fd";
//Night
locations[n].models.night.charactersPatch = "Fort_4_path";
//locations[n].models.night.charactersPatch = "Fort_4_path2";
Locations[n].models.night.FortBigNight= "Fort_4_fn";
//Environment
locations[n].environment.weather = "true";
locations[n].environment.sea = "true";
//Reload map
locations[n].reload.l1.name = "boat";
locations[n].reload.l1.go = "Hispaniola2";
locations[n].reload.l1.emerge = "reload_7";
locations[n].locators_radius.reload.boat = 9.0;
locations[n].reload.l2.name = "reload2";
locations[n].reload.l2.go = "Test_Fort_2";
locations[n].reload.l2.emerge = "reload3";
locations[n].reload.l3.name = "reload4";
locations[n].reload.l3.go = "Test_Fort_ammo_2";
locations[n].reload.l3.emerge = "reload3";
locations[n].reload.l4.name = "reload3";
locations[n].reload.l4.go = "Test_Fort_2";
locations[n].reload.l4.emerge = "reload2";
n = n + 1;
Locations[n].id = "Test_Fort_3";
locations[n].id.label = "Test";
//Info
Locations[n].image = "outside\Fort.tga.tx";
//Sound
locations[n].type = "fort";
locations[n].townsack = "bermudes";
locations[n].island = "Bermudes";
//Models
Locations[n].filespath.models = "locations\Fort_inside\Test_fort\Fort_5";
Locations[n].models.always.Fort_5 = "Fort_5";
locations[n].models.always.Fort_5.sea_reflection = 1;
Locations[n].models.always.Fort_5.seabed = "Fort_5_sb";
Locations[n].models.always.locators = "Fort_5_locators";
Locations[n].models.always.grassPatch = "Fort_5_grass";
Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
Locations[n].models.always.l1 = "plan1";
Locations[n].models.always.l1.level = 9;
Locations[n].models.always.l1.tech = "LocationModelBlend";
Locations[n].models.always.l2 = "plan2";
Locations[n].models.always.l2.level = 8;
Locations[n].models.always.l2.tech = "LocationModelBlend";
Locations[n].models.always.l3 = "plan3";
Locations[n].models.always.l3.level = 7;
Locations[n].models.always.l3.tech = "LocationModelBlend";
Locations[n].models.always.l4 = "plan4";
Locations[n].models.always.l4.level = 6;
Locations[n].models.always.l4.tech = "LocationModelBlend";
Locations[n].models.always.l5 = "Fort_5_trees";
Locations[n].models.always.l5.tech = "DLightModel";
Locations[n].models.always.l6 = "Fort_5_terra";
//Locations[n].models.always.l6 = "Fort_5_lest";
//Locations[n].models.always.l6.tech = "DLightModel";
//Locations[n].models.always.l7 = "Fort_5_open";
//Locations[n].models.always.l7.tech = "DLightModel";
//Locations[n].models.always.l8 = "Fort_5_close";
//Locations[n].models.always.l8.tech = "DLightModel";
//Day
locations[n].models.day.charactersPatch = "Fort_5_path";
//locations[n].models.day.charactersPatch = "Fort_5_path_quest";
//locations[n].models.day.charactersPatch = "Fort_5_path_quest1";
Locations[n].models.day.FortFonarsDay = "Fort_5_fd";
//Night
locations[n].models.night.charactersPatch = "Fort_5_path";
//locations[n].models.night.charactersPatch = "Fort_5_path_quest";
//locations[n].models.night.charactersPatch = "Fort_5_path_quest1";
Locations[n].models.night.FortBigNight= "Fort_5_fn";
//Environment
locations[n].environment.weather = "true";
locations[n].environment.sea = "true";
//Reload map
locations[n].reload.l1.name = "boat";
locations[n].reload.l1.go = "Hispaniola2";
locations[n].reload.l1.emerge = "reload_7";
locations[n].locators_radius.reload.boat = 9.0;
locations[n].reload.l2.name = "reload9";
locations[n].reload.l2.go = "Test_Fort_3";
locations[n].reload.l2.emerge = "reload7";
locations[n].reload.l3.name = "reload7";
locations[n].reload.l3.go = "Test_Fort_3";
locations[n].reload.l3.emerge = "reload9";
locations[n].reload.l4.name = "reload6";
locations[n].reload.l4.go = "Test_Fort_3";
locations[n].reload.l4.emerge = "reload5";
Locations[n].reload.l5.name = "reload5";
Locations[n].reload.l5.go = "Test_Fort_3";
Locations[n].reload.l5.emerge = "reload6";
locations[n].reload.l7.name = "reload3";
locations[n].reload.l7.go = "Test_Fort_3";
locations[n].reload.l7.emerge = "reload2";
locations[n].reload.l8.name = "reload2";
locations[n].reload.l8.go = "Test_Fort_3";
locations[n].reload.l8.emerge = "reload3";
n = n + 1;
locations[n].id = "Guadeloupe_shore_test";
locations[n].id.label = "Guadeloupe Shore";
locations[n].filespath.models = "locations\outside\RockShore";
locations[n].image = "loading\Rockshore_512.tga";
locations[n].island = "Bermudes";
locations[n].type = "seashore";
Locations[n].models.always.jungle = "rockshore";
locations[n].models.always.jungle.sea_reflection = 1;
Locations[n].models.always.seabed = "rockshore_sb";
Locations[n].models.always.grassPatch = "rockshore_grass";
Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
Locations[n].models.always.locators = "rockshore_locators";
locations[n].models.day.jumpPatch = "rockshore_jump_patch";
//locations[n].models.always.plan = "plan1";
//locations[n].models.always.plan.level = 9;
//Day
locations[n].models.day.charactersPatch = "rockshore_patch_day";
locations[n].models.day.jumpPatch = "rockshore_jump_patch";
//Night
locations[n].models.night.charactersPatch = "rockshore_patch_day";
locations[n].models.night.jumpPatch = "rockshore_jump_patch";
locations[n].environment.weather = "true";
locations[n].environment.sea = "true";
locations[n].reload.l1.name = "boat";
locations[n].reload.l1.go = "Hispaniola2";
locations[n].reload.l1.emerge = "reload_7";
locations[n].locators_radius.reload.boat = 9.0;
n = n + 1;
locations[n].id = "MountainPathDMChest";
locations[n].id.label = "MountainPath";
locations[n].filespath.models = "locations\outside\MountainPathDMChest";
locations[n].image = "loading\mountainpath_512.tga";
//Sound
locations[n].island = "Bermudes";
locations[n].type = "seashore";
//Models
//Always
Locations[n].models.always.MountainPathDMChest = "MountainPathDMChest";
locations[n].models.always.MountainPathDMChest.sea_reflection = 1;
Locations[n].models.always.seabed = "MountainPathDMChest_sb";
Locations[n].models.always.grassPatch = "mountainPath_grass";
Locations[n].models.always.grassPatch.texture = "grass\grassRock.tga.tx";
Locations[n].models.always.locators = "MountainPathDMChest_locators";
Locations[n].models.always.gold = "gold";
Locations[n].models.always.gold.tech = "EnvironmentShader";
Locations[n].models.always.gold.reflection = 1;
//Day
locations[n].models.day.charactersPatch = "MountainPathDMChest_patch_day";
//Night
locations[n].models.night.charactersPatch = "MountainPathDMChest_patch_day";
//Waterfall
Locations[n].models.always.Waterfall1 = "waterfall1";
Locations[n].models.always.Waterfall1.uvslide.v0 = 0.6;
Locations[n].models.always.Waterfall1.uvslide.v1 = 0.0;
Locations[n].models.always.Waterfall1.tech = "LocationWaterFall";
Locations[n].models.always.Waterfall1.level = 99950;
Locations[n].models.always.Waterfall2 = "waterfall2";
Locations[n].models.always.Waterfall2.uvslide.v0 = 0.3;
Locations[n].models.always.Waterfall2.uvslide.v1 = 0.0;
Locations[n].models.always.Waterfall2.tech = "LocationWaterFall";
Locations[n].models.always.Waterfall2.level = 99949;
Locations[n].locators_radius.SLquest.lofgreen = 5.0;
//Environment
locations[n].environment.weather = "true";
locations[n].environment.sea = "true";
n = n + 1;
locations[n].id = "Antigua_shore_test";
locations[n].id.label = "Antigua Shore";
locations[n].filespath.models = "locations\outside\Sandshore";
locations[n].image = "loading\Sandshore_512.tga";
Locations[n].island = "KhaelRoa"; // NK 04-08-29
Locations[n].worldmap = "Khael Roa";
locations[n].type = "seashore";
Locations[n].models.always.town = "sandshore";
locations[n].models.always.town.sea_reflection = 1;
Locations[n].models.always.seabed = "sandshore_sb";
Locations[n].models.always.grassPatch = "sandshore_grass";
Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
Locations[n].models.always.locators = "sandshore_locators";
locations[n].models.always.plan = "plan1";
locations[n].models.always.plan.level = 9;
locations[n].models.always.plan.sea_reflection = 1;
//Day
locations[n].models.day.charactersPatch = "sandshore_patch_day";
locations[n].models.day.jumpPatch = "sandshore_jump_patch";
//Night
locations[n].models.night.charactersPatch = "sandshore_patch_day";
locations[n].models.night.jumpPatch = "sandshore_jump_patch";
locations[n].environment.weather = "true";
locations[n].environment.sea = "true";
n = n + 1;
locations[n].id = "PuertoPrincipe_port2";
locations[n].NameForLoc = "PuertoPrincipe Port";
locations[n].image = "outside/harbor3.tga.tx";
//Models
//Always
locations[n].filespath.models = "locations\Outside\Shore_house";
Locations[n].models.always.shore11 = "shore11";
locations[n].models.always.shore11.sea_reflection = 1;
Locations[n].models.always.shore11.seabed = "shore11_sb";
Locations[n].models.always.locators = "shore11_locators";
Locations[n].models.always.grassPatch = "shore11_grass";
Locations[n].models.always.grassPatch.texture = "grass\grassshore.tga.tx";
Locations[n].models.always.l1 = "plan1";
Locations[n].models.always.l1.level = 9;
Locations[n].models.always.l1.tech = "LocationModelBlend";
Locations[n].models.always.l2 = "plan2";
Locations[n].models.always.l2.level = 8;
Locations[n].models.always.l2.tech = "LocationModelBlend";
Locations[n].models.always.l3 = "plan3";
Locations[n].models.always.l3.level = 7;
Locations[n].models.always.l3.tech = "LocationModelBlend";
//Day
Locations[n].models.day.l4 = "smg";
Locations[n].models.day.l4.tech = "dLightModel";
locations[n].models.day.charactersPatch = "shore11_patchsmg";
//Night
locations[n].models.night.charactersPatch = "shore11_patch";
//Environment
locations[n].environment.weather = "true";
locations[n].environment.sea = "true";
Locations[n].island = "KhaelRoa"; // NK 04-08-29
Locations[n].worldmap = "Khael Roa";
locations[n].type = "seashore";
n = n + 1;
}