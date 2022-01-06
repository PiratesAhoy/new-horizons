// Note from MAXIMUS
// If anyone will change (or will add new) .label.text - please
// be patient and add this label into RESOURCE\INI\TEXTS\(all languages)\interface_strings.txt
// It's VERY important for multilingual BUILD
void wdmInitWorldMap()
{
	//Init world map object
	DeleteAttribute(&worldMap, ""); // KK

	//Debug info
	worldMap.debug = "false";
	worldMap.evwin = "false";
	worldMap.noenc = "false";
	//=========================================================================
	//Storm interface
	worldMap.storm.num = 0;
	worldMap.storm.cur = 0;
	worldMap.storm.x = 0;
	worldMap.storm.z = 0;
	worldMap.storm.time = 0;
	//Encounter interface
	worldMap.encounter.num = 0;
	worldMap.encounter.cur = 0;
	worldMap.encounter.x = 0;
	worldMap.encounter.z = 0;
	worldMap.encounter.ay = 0;
	worldMap.encounter.time = 0;
	worldMap.encounter.type = -1;
	worldMap.encounter.attack = -1;
	//=========================================================================
	worldMap.fontIslands = "SEADOGS";//"DIALOG21";
	worldMap.fontLocations = "SEADOGS_SMALL";//"normal";
	worldMap.labelPivotX = 0.5;
	worldMap.labelPivotY = 1.5;
	worldMap.heightViewLabel = 250.0;
	worldMap.icon.width = 32;
	worldMap.icon.height = 32;
	worldMap.icon.texture = "icons" + GetCurrentPeriod() + ".tga"; // KK
	worldMap.icon.num = 16; // KK
	worldMap.icon.frames = 8;
	worldMap.icon.fps = 10;
	//=========================================================================
	worldMap.eventWindow.font.header = "normal";
	worldMap.eventWindow.font.text = "normal";
	worldMap.eventWindow.font.button = "normal";
	//==========================================================================
// PB -->
	//Start date
	worldMap.date.hour = CharHour;
	worldMap.date.min = CharMinute;
	worldMap.date.sec = CharSecond;
	worldMap.date.day = CharDay;
	worldMap.date.month = CharMonth;
	worldMap.date.year = CharYear;
// <-- PB
	worldMap.date.hourPerSec = 4.0;
	//Output info
	worldMap.date.font = "normal";
	//1=========================================================================
	//Name
	worldMap.islands.FalaiseDeFleur.name = "FalaiseDeFleur";
	//Geometry parameters
	worldMap.islands.FalaiseDeFleur.position.x = -746.6099;
	worldMap.islands.FalaiseDeFleur.position.y = 30.0;
	worldMap.islands.FalaiseDeFleur.position.z = 234.9465;
	worldMap.islands.FalaiseDeFleur.position.rx = -730.7285;
	worldMap.islands.FalaiseDeFleur.position.rz = 246.8357;
	worldMap.islands.FalaiseDeFleur.radius = 110.0;
	worldMap.islands.FalaiseDeFleur.kradius = 0.75;
	//Island label
	worldMap.islands.FalaiseDeFleur.label.text = FindIslandName("Falaise De Fleur");
	worldMap.islands.FalaiseDeFleur.label.icon = -1;
	worldMap.islands.FalaiseDeFleur.label.visible = "true";
	//Island locations----------------------------------------------------------
	//City
	//Name
	worldMap.islands.FalaiseDeFleur.locations.city2.name = "Falaise De Fleur";
	worldMap.islands.FalaiseDeFleur.locations.city2.real = "Falaise De Fleur";//MAXIMUS: attribute .real needed for several things in the future
	//Geometry parameters
	worldMap.islands.FalaiseDeFleur.locations.city2.move = "false";
	worldMap.islands.FalaiseDeFleur.locations.city2.position.x = -726.7285;
	worldMap.islands.FalaiseDeFleur.locations.city2.position.y = 4.035;
	worldMap.islands.FalaiseDeFleur.locations.city2.position.z = 244.7357;
	worldMap.islands.FalaiseDeFleur.locations.city2.position.ay = 0.0;
	worldMap.islands.FalaiseDeFleur.locations.city2.modelName = "town";
	worldMap.islands.FalaiseDeFleur.locations.city2.visible = "false";
	worldMap.islands.FalaiseDeFleur.locations.city2.move = "false";
	//Label
	wdmSetIcon("Falaise de Fleur", FindTownName("Falaise De Fleur"), GetTownNation("Falaise de Fleur")); // KK
	worldMap.islands.FalaiseDeFleur.locations.city2.label.visible = "false";
	// initial ship location
	worldMap.islands.FalaiseDeFleur.locations.city2.ship.pos.x = -728.7278; // KK
	worldMap.islands.FalaiseDeFleur.locations.city2.ship.pos.z = 252.5644; // KK
	//Name
	worldMap.islands.FalaiseDeFleur.locations.city1.name = "FShore 1";
	//Geometry parameters
	worldMap.islands.FalaiseDeFleur.locations.city1.position.x = -702.3931;
	worldMap.islands.FalaiseDeFleur.locations.city1.position.y = 2.905;
	worldMap.islands.FalaiseDeFleur.locations.city1.position.z = 276.5357;
	worldMap.islands.FalaiseDeFleur.locations.city1.position.ay = 0.0;
	worldMap.islands.FalaiseDeFleur.locations.city1.modelName = "leaf";
	worldMap.islands.FalaiseDeFleur.locations.city1.visible = "false";
	worldMap.islands.FalaiseDeFleur.locations.city1.move = "false";
	//Label
	worldMap.islands.FalaiseDeFleur.locations.city1.label.text = "Octopus Bay";
	worldMap.islands.FalaiseDeFleur.locations.city1.label.icon = -1;
	worldMap.islands.FalaiseDeFleur.locations.city1.label.visible = "false";
	// initial ship location
	worldMap.islands.FalaiseDeFleur.locations.city1.ship.pos.x = -696.8785; // KK
	worldMap.islands.FalaiseDeFleur.locations.city1.ship.pos.z = 280.8657; // KK
	//

	//2=========================================================================
	//Name
	worldMap.islands.Redmond.name = "Redmond";
	//Geometry parameters
	worldMap.islands.Redmond.isVisibleName = 0;
	worldMap.islands.Redmond.position.x = 300.9059;
	worldMap.islands.Redmond.position.y = 30.0;
	worldMap.islands.Redmond.position.z = -188.6696;
	worldMap.islands.Redmond.position.rx = 312.9202;
	worldMap.islands.Redmond.position.rz = -174.4065;
	worldMap.islands.Redmond.radius = 140.0;	
	worldMap.islands.Redmond.kradius = 0.75;
	//Island label
	worldMap.islands.Redmond.label.text = FindIslandName("Redmond");
	worldMap.islands.Redmond.label.icon = -1;
	worldMap.islands.Redmond.label.visible = "true";

	//City
	//Name
	worldMap.islands.Redmond.locations.city3.name = "Redmond";
	worldMap.islands.Redmond.locations.city3.real = "Redmond";
	//Geometry parameters
	worldMap.islands.Redmond.locations.city3.position.x = 254.3152;
	worldMap.islands.Redmond.locations.city3.position.y = 3.0;
	worldMap.islands.Redmond.locations.city3.position.z = -196.9065;
	worldMap.islands.Redmond.locations.city3.position.ay = 0.0;
	worldMap.islands.Redmond.locations.city3.modelName = "town";
	worldMap.islands.Redmond.locations.city3.visible = "false";
	worldMap.islands.Redmond.locations.city3.move = "false";
	//Label
	wdmSetIcon("Redmond", FindTownName("Redmond"), GetTownNation("Redmond")); // KK
	worldMap.islands.Redmond.locations.city3.label.visible = "false";
	// initial ship location
	worldMap.islands.Redmond.locations.city3.ship.pos.x = 261.1002; // KK
	worldMap.islands.Redmond.locations.city3.ship.pos.z = -180.3465; // KK
	//Name
	worldMap.islands.Redmond.locations.city1.name = "RShore 1";
	//Geometry parameters
	worldMap.islands.Redmond.locations.city1.position.x = 304.1752;
	worldMap.islands.Redmond.locations.city1.position.y = 2.445;
	worldMap.islands.Redmond.locations.city1.position.z = -198.6085;
	worldMap.islands.Redmond.locations.city1.position.ay = 0.0;
	worldMap.islands.Redmond.locations.city1.modelName = "leaf";
	worldMap.islands.Redmond.locations.city1.visible = "false";
	worldMap.islands.Redmond.locations.city1.move = "false";
	//Label
	if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0)
	{
		worldMap.islands.Redmond.locations.city1.label.text = "Woodes Rogers' Port";
	}
	else 
	{
		worldMap.islands.Redmond.locations.city1.label.text = "Devil's Throat";
	}
	worldMap.islands.Redmond.locations.city1.label.icon = -1;
	worldMap.islands.Redmond.locations.city1.label.visible = "false";
	// initial ship location
	worldMap.islands.Redmond.locations.city1.ship.pos.x = 310.6102; // KK
	worldMap.islands.Redmond.locations.city1.ship.pos.z = -183.0665; // KK
	//Name
	worldMap.islands.Redmond.locations.city2.name = "RShore 2";
	//Geometry parameters
	worldMap.islands.Redmond.locations.city2.position.x = 279.0622;
	worldMap.islands.Redmond.locations.city2.position.y = 2.445;
	worldMap.islands.Redmond.locations.city2.position.z = -230.4625;
	worldMap.islands.Redmond.locations.city2.position.ay = 0.0;
	worldMap.islands.Redmond.locations.city2.modelName = "leaf";
	worldMap.islands.Redmond.locations.city2.visible = "false";
	worldMap.islands.Redmond.locations.city2.move = "false";
	//Label
	if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0)
	{
		worldMap.islands.Redmond.locations.city2.label.text = "Cave Shore";
	}
	else
	{
		worldMap.islands.Redmond.locations.city2.label.text = "Rocky Shore";
	}
	worldMap.islands.Redmond.locations.city2.label.icon = -1;
	worldMap.islands.Redmond.locations.city2.label.visible = "false";
	// initial ship location
	worldMap.islands.Redmond.locations.city2.ship.pos.x = 267.8302; // KK
	worldMap.islands.Redmond.locations.city2.ship.pos.z = -233.9565; // KK

	//3=========================================================================
	//Name
	worldMap.islands.Oxbay.name = "Oxbay";
	//Geometry parameters
	worldMap.islands.Oxbay.isVisibleName = 0;
	worldMap.islands.Oxbay.position.x = -915.4337;
	worldMap.islands.Oxbay.position.y = 30.0;
	worldMap.islands.Oxbay.position.z = 415.2678;
	worldMap.islands.Oxbay.position.rx = -876.6284;
	worldMap.islands.Oxbay.position.rz = 409.4471;
	worldMap.islands.Oxbay.radius = 120.0;	
	worldMap.islands.Oxbay.kradius = 0.75;
	//Island label
	worldMap.islands.Oxbay.label.text = FindIslandName("Oxbay");
	worldMap.islands.Oxbay.label.icon = -1;
	worldMap.islands.Oxbay.label.visible = "true";

	//City
	//Name
	worldMap.islands.Oxbay.locations.city5.name = "Oxbay";
	worldMap.islands.Oxbay.locations.city5.real = "Oxbay";
	//Geometry parameters
	worldMap.islands.Oxbay.locations.city5.position.x = -946.0005;
	worldMap.islands.Oxbay.locations.city5.position.y = 4.2868;
	worldMap.islands.Oxbay.locations.city5.position.z = 459.8549;
	worldMap.islands.Oxbay.locations.city5.position.ay = 2.5765;
	worldMap.islands.Oxbay.locations.city5.modelName = "town";
	worldMap.islands.Oxbay.locations.city5.visible = "false";
	worldMap.islands.Oxbay.locations.city5.move = "false";
	//Label
	wdmSetIcon("Oxbay", FindTownName("Oxbay"), GetTownNation("Oxbay")); // KK
	worldMap.islands.Oxbay.locations.city5.label.visible = "false";
	// initial ship location
	worldMap.islands.Oxbay.locations.city5.ship.pos.x = -957.7789; // KK
	worldMap.islands.Oxbay.locations.city5.ship.pos.z = 485.0871; // KK
	//Name
	worldMap.islands.Oxbay.locations.city1.name = "OShore 2";
	//Geometry parameters
	worldMap.islands.Oxbay.locations.city1.position.x = -900.3443;
	worldMap.islands.Oxbay.locations.city1.position.y = 4.0;
	worldMap.islands.Oxbay.locations.city1.position.z = 445.7554;
	worldMap.islands.Oxbay.locations.city1.position.ay = 3.442;
	worldMap.islands.Oxbay.locations.city1.modelName = "leaf";
	worldMap.islands.Oxbay.locations.city1.visible = "false";
	worldMap.islands.Oxbay.locations.city1.move = "false";
	//Label
	worldMap.islands.Oxbay.locations.city1.label.text = "Gray Rock Bay";
	worldMap.islands.Oxbay.locations.city1.label.icon = -1;
	worldMap.islands.Oxbay.locations.city1.label.visible = "false";
	// initial ship location
	worldMap.islands.Oxbay.locations.city1.ship.pos.x = -878.0484; // KK
	worldMap.islands.Oxbay.locations.city1.ship.pos.z = 479.1171; // KK
	//Name
	worldMap.islands.Oxbay.locations.city4.name = "OShore 1";
	//Geometry parameters
	worldMap.islands.Oxbay.locations.city4.position.x = -955.7721;
	worldMap.islands.Oxbay.locations.city4.position.y = 4.1908;
	worldMap.islands.Oxbay.locations.city4.position.z = 390.6621;
	worldMap.islands.Oxbay.locations.city4.position.ay = 3.442;
	worldMap.islands.Oxbay.locations.city4.modelName = "leaf";
	worldMap.islands.Oxbay.locations.city4.visible = "false";
	worldMap.islands.Oxbay.locations.city4.move = "false";
	//Label
	worldMap.islands.Oxbay.locations.city4.label.text = "Far Beach";
	worldMap.islands.Oxbay.locations.city4.label.icon = -1;
	worldMap.islands.Oxbay.locations.city4.label.visible = "false";
	// initial ship location
	worldMap.islands.Oxbay.locations.city4.ship.pos.x = -968.0349; // KK
	worldMap.islands.Oxbay.locations.city4.ship.pos.z = 393.2861; // KK
	//Name
	worldMap.islands.Oxbay.locations.city2.name = "Lighthouse";
	//Geometry parameters
	worldMap.islands.Oxbay.locations.city2.position.x = -927.8184;
	worldMap.islands.Oxbay.locations.city2.position.y = 3.8403;
	worldMap.islands.Oxbay.locations.city2.position.z = 385.1061;
	worldMap.islands.Oxbay.locations.city2.position.ay = 3.442;
	worldMap.islands.Oxbay.locations.city2.modelName = "leaf";
	worldMap.islands.Oxbay.locations.city2.visible = "false";
	worldMap.islands.Oxbay.locations.city2.move = "false";
	//Label
	worldMap.islands.Oxbay.locations.city2.label.text = "Lighthouse";
	worldMap.islands.Oxbay.locations.city2.label.icon = -1;
	worldMap.islands.Oxbay.locations.city2.label.visible = "false";
	// initial ship location
	worldMap.islands.Oxbay.locations.city2.ship.pos.x = -917.8984; // KK
	worldMap.islands.Oxbay.locations.city2.ship.pos.z = 372.9071; // KK
	//Name
	worldMap.islands.Oxbay.locations.city3.name = "Greenford";
	worldMap.islands.Oxbay.locations.city3.real = "Greenford";
	//Geometry parameters
	worldMap.islands.Oxbay.locations.city3.position.x = -867.4754;
	worldMap.islands.Oxbay.locations.city3.position.y = 3.6448;
	worldMap.islands.Oxbay.locations.city3.position.z = 413.0871;
	worldMap.islands.Oxbay.locations.city3.position.ay = 2.5765;
	worldMap.islands.Oxbay.locations.city3.modelName = "town";
	worldMap.islands.Oxbay.locations.city3.visible = "false";
	worldMap.islands.Oxbay.locations.city3.move = "false";
	//Label
	wdmSetIcon("Greenford", FindTownName("Greenford"), GetTownNation("Greenford")); // KK
	worldMap.islands.Oxbay.locations.city3.label.visible = "false";
	// initial ship location
	worldMap.islands.Oxbay.locations.city3.ship.pos.x = -859.8684; // KK
	worldMap.islands.Oxbay.locations.city3.ship.pos.z = 405.3671; // KK

	//4=========================================================================
	//Name
	worldMap.islands.Douwesen.name = "Douwesen";
	//Geometry parameters
	worldMap.islands.Douwesen.isVisibleName = 0;
	worldMap.islands.Douwesen.position.x = -503.5165;
	worldMap.islands.Douwesen.position.y = 30.0;
	worldMap.islands.Douwesen.position.z = 685.5855;
	worldMap.islands.Douwesen.position.rx = -471.2567;
	worldMap.islands.Douwesen.position.rz = 674.4498;
	worldMap.islands.Douwesen.radius = 90.0;	
	worldMap.islands.Douwesen.kradius = 0.75;
	//Island label
	worldMap.islands.Douwesen.label.text = FindIslandName("Douwesen");
	worldMap.islands.Douwesen.label.icon = -1;
	worldMap.islands.Douwesen.label.visible = "true";

	//City
	//Name
	worldMap.islands.Douwesen.locations.city1.name = "Douwesen";
	worldMap.islands.Douwesen.locations.city1.real = "Douwesen";
	//Geometry parameters
	worldMap.islands.Douwesen.locations.city1.position.x = -498.1167;
	worldMap.islands.Douwesen.locations.city1.position.y = 4.0532;
	worldMap.islands.Douwesen.locations.city1.position.z = 689.8098;
	worldMap.islands.Douwesen.locations.city1.position.ay = 0.0;
	worldMap.islands.Douwesen.locations.city1.modelName = "town";
	worldMap.islands.Douwesen.locations.city1.visible = "false";
	worldMap.islands.Douwesen.locations.city1.move = "false";
	//Label
	wdmSetIcon("Douwesen", FindTownName("Douwesen"), GetTownNation("Douwesen")); // KK
	worldMap.islands.Douwesen.locations.city1.label.visible = "false";
	// initial ship location
	worldMap.islands.Douwesen.locations.city1.ship.pos.x = -482.9967; // KK
	worldMap.islands.Douwesen.locations.city1.ship.pos.z = 668.6898; // KK
	//Name
	worldMap.islands.Douwesen.locations.city2.name = "DShore 1";
	//Geometry parameters
	worldMap.islands.Douwesen.locations.city2.position.x = -510.8167;
	worldMap.islands.Douwesen.locations.city2.position.y = 1.84;
	worldMap.islands.Douwesen.locations.city2.position.z = 709.7098;
	worldMap.islands.Douwesen.locations.city2.position.ay = 0.0;
	worldMap.islands.Douwesen.locations.city2.modelName = "leaf";
	worldMap.islands.Douwesen.locations.city2.visible = "false";
	worldMap.islands.Douwesen.locations.city2.move = "false";
	//Label
	worldMap.islands.Douwesen.locations.city2.label.text = "Palm Beach";
	worldMap.islands.Douwesen.locations.city2.label.icon = -1;
	worldMap.islands.Douwesen.locations.city2.label.visible = "false";
	// initial ship location
	worldMap.islands.Douwesen.locations.city2.ship.pos.x = -521.7295; // KK
	worldMap.islands.Douwesen.locations.city2.ship.pos.z = 710.8098; // KK
	//Name
	worldMap.islands.Douwesen.locations.city3.name = "DShore 2";
	//Geometry parameters
	worldMap.islands.Douwesen.locations.city3.position.x = -461.8042;
	worldMap.islands.Douwesen.locations.city3.position.y = 4.4537;
	worldMap.islands.Douwesen.locations.city3.position.z = 715.3430;
	worldMap.islands.Douwesen.locations.city3.position.ay = 0.0;
	worldMap.islands.Douwesen.locations.city3.modelName = "leaf";
	worldMap.islands.Douwesen.locations.city3.visible = "false";
	worldMap.islands.Douwesen.locations.city3.move = "false";
	//Label
	worldMap.islands.Douwesen.locations.city3.label.text = "Crab Cliffs";
	worldMap.islands.Douwesen.locations.city3.label.icon = -1;
	worldMap.islands.Douwesen.locations.city3.label.visible = "false";
	// initial ship location
	worldMap.islands.Douwesen.locations.city3.ship.pos.x = -448.4867; // KK
	worldMap.islands.Douwesen.locations.city3.ship.pos.z = 718.8998; // KK

	//5=========================================================================
	//Name
	worldMap.islands.Conceicao.name = "Conceicao";
	//Geometry parameters
	worldMap.islands.Conceicao.isVisibleName = 0;
	worldMap.islands.Conceicao.position.x = -780.4724;
	worldMap.islands.Conceicao.position.y = 30.0;
	worldMap.islands.Conceicao.position.z = 663.7298;
	worldMap.islands.Conceicao.position.rx = -707.8312;
	worldMap.islands.Conceicao.position.rz = 673.5406;
	worldMap.islands.Conceicao.radius = 100.0;	
	worldMap.islands.Conceicao.kradius = 0.75;
	//Island label
	worldMap.islands.Conceicao.label.text = FindIslandName("Conceicao");
	worldMap.islands.Conceicao.label.icon = -1;
	worldMap.islands.Conceicao.label.visible = "true";
	//City
	//Name
	worldMap.islands.Conceicao.locations.city1.name = "CShore 1";
	//Geometry parameters
	worldMap.islands.Conceicao.locations.city1.position.x = -773.4312;
	worldMap.islands.Conceicao.locations.city1.position.y = 3.7401;
	worldMap.islands.Conceicao.locations.city1.position.z = 624.6777;
	worldMap.islands.Conceicao.locations.city1.position.ay = 0.0;
	worldMap.islands.Conceicao.locations.city1.modelName = "leaf";
	worldMap.islands.Conceicao.locations.city1.visible = "false";
	worldMap.islands.Conceicao.locations.city1.move = "false";
	//Label
	worldMap.islands.Conceicao.locations.city1.label.text = "Sunny Haven";
	worldMap.islands.Conceicao.locations.city1.label.icon = -1;
	worldMap.islands.Conceicao.locations.city1.label.visible = "false";
	// initial ship location
	worldMap.islands.Conceicao.locations.city1.ship.pos.x = -772.2512; // KK
	worldMap.islands.Conceicao.locations.city1.ship.pos.z = 615.5106; // KK
	//Name
	worldMap.islands.Conceicao.locations.city2.name = "Conceicao";
	worldMap.islands.Conceicao.locations.city2.real = "Conceicao";
	//Geometry parameters
	worldMap.islands.Conceicao.locations.city2.position.x = -793.8731;
	worldMap.islands.Conceicao.locations.city2.position.y = 5.5;
	worldMap.islands.Conceicao.locations.city2.position.z = 654.3124;
	worldMap.islands.Conceicao.locations.city2.position.ay = 0.0;
	worldMap.islands.Conceicao.locations.city2.modelName = "town";
	worldMap.islands.Conceicao.locations.city2.visible = "false";
	worldMap.islands.Conceicao.locations.city2.move = "false";
	//Label
	wdmSetIcon("Conceicao", FindTownName("Conceicao"), GetTownNation("Conceicao")); // KK
	worldMap.islands.Conceicao.locations.city2.label.visible = "false";
	// initial ship location
	worldMap.islands.Conceicao.locations.city2.ship.pos.x = -816.4512; // KK
	worldMap.islands.Conceicao.locations.city2.ship.pos.z = 657.9606; // KK
	//Name
	worldMap.islands.Conceicao.locations.city3.name = "CShore 2";
	//Geometry parameters
	worldMap.islands.Conceicao.locations.city3.position.x = -747.8712;
	worldMap.islands.Conceicao.locations.city3.position.y = 3.3976;
	worldMap.islands.Conceicao.locations.city3.position.z = 689.4085;
	worldMap.islands.Conceicao.locations.city3.position.ay = 0.0;
	worldMap.islands.Conceicao.locations.city3.modelName = "leaf";
	worldMap.islands.Conceicao.locations.city3.visible = "false";
	worldMap.islands.Conceicao.locations.city3.move = "false";
	//Label
	worldMap.islands.Conceicao.locations.city3.label.text = "Leviathan Rock";
	worldMap.islands.Conceicao.locations.city3.label.icon = -1;
	worldMap.islands.Conceicao.locations.city3.label.visible = "false";
	// initial ship location
	worldMap.islands.Conceicao.locations.city3.ship.pos.x = -746.4312; // KK
	worldMap.islands.Conceicao.locations.city3.ship.pos.z = 700.1606; // KK

	//6=========================================================================
	//Name
	worldMap.islands.IslaMuelle.name = "IslaMuelle";
	//Geometry parameters
	worldMap.islands.IslaMuelle.isVisibleName = 0;
	worldMap.islands.IslaMuelle.position.x = -451.9622;
	worldMap.islands.IslaMuelle.position.y = 30.0;
	worldMap.islands.IslaMuelle.position.z = -314.4281;
	worldMap.islands.IslaMuelle.position.rx = -519.2072;
	worldMap.islands.IslaMuelle.position.rz = -323.7959;
	worldMap.islands.IslaMuelle.radius = 140.0;	
	worldMap.islands.IslaMuelle.kradius = 0.75;
	//Island label
	worldMap.islands.IslaMuelle.label.text = FindIslandName("Isla Muelle");
	worldMap.islands.IslaMuelle.label.icon = -1;
	worldMap.islands.IslaMuelle.label.visible = "true";

	//City
	//Name
	worldMap.islands.IslaMuelle.locations.city1.name = "Isla Muelle";
	worldMap.islands.IslaMuelle.locations.city1.real = "Isla Muelle";
	//Geometry parameters
	worldMap.islands.IslaMuelle.locations.city1.position.x = -413.6792;
	worldMap.islands.IslaMuelle.locations.city1.position.y = 5.1262;
	worldMap.islands.IslaMuelle.locations.city1.position.z = -326.9566;
	worldMap.islands.IslaMuelle.locations.city1.position.ay = 0.0;
	worldMap.islands.IslaMuelle.locations.city1.modelName = "town";
	worldMap.islands.IslaMuelle.locations.city1.visible = "false";
	worldMap.islands.IslaMuelle.locations.city1.move = "false";
	//Label
	wdmSetIcon("Isla Muelle", FindTownName("Isla Muelle"), GetTownNation("Isla Muelle")); // KK
	worldMap.islands.IslaMuelle.locations.city1.label.visible = "false";
	// initial ship location
	worldMap.islands.IslaMuelle.locations.city1.ship.pos.x = -397.3872; // KK
	worldMap.islands.IslaMuelle.locations.city1.ship.pos.z = -355.6559; // KK
	//Name
	worldMap.islands.IslaMuelle.locations.city2.name = "MShore 1";
	//Geometry parameters
	worldMap.islands.IslaMuelle.locations.city2.position.x = -511.3802;
	worldMap.islands.IslaMuelle.locations.city2.position.y = 4.0276;
	worldMap.islands.IslaMuelle.locations.city2.position.z = -294.9553;
	worldMap.islands.IslaMuelle.locations.city2.position.ay = 0.0;
	worldMap.islands.IslaMuelle.locations.city2.modelName = "leaf";
	worldMap.islands.IslaMuelle.locations.city2.visible = "false";
	worldMap.islands.IslaMuelle.locations.city2.move = "false";
	//Label
	worldMap.islands.IslaMuelle.locations.city2.label.text = "Oyster Beach";
	worldMap.islands.IslaMuelle.locations.city2.label.icon = -1;
	worldMap.islands.IslaMuelle.locations.city2.label.visible = "false";
	// initial ship location
	worldMap.islands.IslaMuelle.locations.city2.ship.pos.x = -518.8672; // KK
	worldMap.islands.IslaMuelle.locations.city2.ship.pos.z = -281.5659; // KK
	//Name
	worldMap.islands.IslaMuelle.locations.city3.name = "MShore 2";
	//Geometry parameters
	worldMap.islands.IslaMuelle.locations.city3.position.x = -405.8461;
	worldMap.islands.IslaMuelle.locations.city3.position.y = 2.9717;
	worldMap.islands.IslaMuelle.locations.city3.position.z =  -236.823;
	worldMap.islands.IslaMuelle.locations.city3.position.ay = 0.0;
	worldMap.islands.IslaMuelle.locations.city3.modelName = "leaf";
	worldMap.islands.IslaMuelle.locations.city3.visible = "false";
	worldMap.islands.IslaMuelle.locations.city3.move = "false";
	//Label
	worldMap.islands.IslaMuelle.locations.city3.label.text = "Hidden Coast";
	worldMap.islands.IslaMuelle.locations.city3.label.icon = -1;
	worldMap.islands.IslaMuelle.locations.city3.label.visible = "false";
	// initial ship location
	worldMap.islands.IslaMuelle.locations.city3.ship.pos.x = -394.8672; // KK
	worldMap.islands.IslaMuelle.locations.city3.ship.pos.z = -226.6659; // KK

	//7=========================================================================
	//Name
	worldMap.islands.QuebradasCostillas.name = "QuebradasCostillas";
	//Geometry parameters
	worldMap.islands.QuebradasCostillas.isVisibleName = 0;
	worldMap.islands.QuebradasCostillas.position.x = -662.419;
	worldMap.islands.QuebradasCostillas.position.y = 30.0;
	worldMap.islands.QuebradasCostillas.position.z = -201.8127;
	worldMap.islands.QuebradasCostillas.position.rx = -641.6077;
	worldMap.islands.QuebradasCostillas.position.rz = -168.2621;
	worldMap.islands.QuebradasCostillas.radius = 90.0;	
	worldMap.islands.QuebradasCostillas.kradius = 0.75;
	//Island label
	worldMap.islands.QuebradasCostillas.label.text = FindIslandName("Quebradas Costillas");
	worldMap.islands.QuebradasCostillas.label.icon = -1;
	worldMap.islands.QuebradasCostillas.label.visible = "true";

	//City
	//Name
	worldMap.islands.QuebradasCostillas.locations.city1.name = "Charlestown";
	worldMap.islands.QuebradasCostillas.locations.city1.real = "Charlestown";
	//Geometry parameters
	worldMap.islands.QuebradasCostillas.locations.city1.position.x = -623.7422;
	worldMap.islands.QuebradasCostillas.locations.city1.position.y = 3.3649;
	worldMap.islands.QuebradasCostillas.locations.city1.position.z = -239.6096;
	worldMap.islands.QuebradasCostillas.locations.city1.position.ay = 0.0;
	worldMap.islands.QuebradasCostillas.locations.city1.modelName = "town";
	worldMap.islands.QuebradasCostillas.locations.city1.visible = "false";
	worldMap.islands.QuebradasCostillas.locations.city1.move = "false";
	//Label
	wdmSetIcon("Charlestown", FindTownName("Charlestown"), GetTownNation("Charlestown")); // KK
	worldMap.islands.QuebradasCostillas.locations.city1.label.visible = "false";
	// initial ship location
	worldMap.islands.QuebradasCostillas.locations.city1.ship.pos.x = -617.0612; // KK
	worldMap.islands.QuebradasCostillas.locations.city1.ship.pos.z = -247.2122; // KK
	//Name
	worldMap.islands.QuebradasCostillas.locations.city2.name = "Quebradas Costillas";
	worldMap.islands.QuebradasCostillas.locations.city2.real = "Quebradas Costillas";
	//Geometry parameters
	worldMap.islands.QuebradasCostillas.locations.city2.position.x = -668.2125;
	worldMap.islands.QuebradasCostillas.locations.city2.position.y = 3.9294;
	worldMap.islands.QuebradasCostillas.locations.city2.position.z = -186.4157;
	worldMap.islands.QuebradasCostillas.locations.city2.position.ay = 0.0;
	worldMap.islands.QuebradasCostillas.locations.city2.modelName = "town";
	worldMap.islands.QuebradasCostillas.locations.city2.visible = "false";
	worldMap.islands.QuebradasCostillas.locations.city2.move = "false";
	//Label
	wdmSetIcon("Quebradas Costillas", FindTownName("Quebradas Costillas"), GetTownNation("Quebradas Costillas")); // KK
	worldMap.islands.QuebradasCostillas.locations.city2.label.visible = "false";
	// initial ship location
	worldMap.islands.QuebradasCostillas.locations.city2.ship.pos.x = -664.2263; // KK
	worldMap.islands.QuebradasCostillas.locations.city2.ship.pos.z = -173.4321; // KK
	//Name
	worldMap.islands.QuebradasCostillas.locations.city3.name = "QC_Shore1";
	//Geometry parameters
	worldMap.islands.QuebradasCostillas.locations.city3.position.x = -691.4187;
	worldMap.islands.QuebradasCostillas.locations.city3.position.y = 2.9137;
	worldMap.islands.QuebradasCostillas.locations.city3.position.z = -195.6121;
	worldMap.islands.QuebradasCostillas.locations.city3.position.ay = 2.5765;
	worldMap.islands.QuebradasCostillas.locations.city3.modelName = "leaf";
	worldMap.islands.QuebradasCostillas.locations.city3.visible = "false";
	worldMap.islands.QuebradasCostillas.locations.city3.move = "false";
	//Label
	worldMap.islands.QuebradasCostillas.locations.city3.label.text = "White Bay";
	worldMap.islands.QuebradasCostillas.locations.city3.label.icon = -1;
	worldMap.islands.QuebradasCostillas.locations.city3.label.visible = "false";
	// initial ship location
	worldMap.islands.QuebradasCostillas.locations.city3.ship.pos.x = -703.2149; // KK
	worldMap.islands.QuebradasCostillas.locations.city3.ship.pos.z = -191.7402; // KK

	//8=========================================================================
	//Name
	worldMap.islands.KhaelRoa.name = "KhaelRoa";
	//Geometry parameters
	worldMap.islands.KhaelRoa.isVisibleName = 0;
	worldMap.islands.KhaelRoa.position.x = 801.3779;
	worldMap.islands.KhaelRoa.position.y = 30.0;
	worldMap.islands.KhaelRoa.position.z = -445.5364;
	worldMap.islands.KhaelRoa.position.rx = 805.0779;
	worldMap.islands.KhaelRoa.position.rz = -437.1364;
	worldMap.islands.KhaelRoa.radius = 70.0;
	worldMap.islands.KhaelRoa.kradius = 0.75;
	//Island label
	worldMap.islands.KhaelRoa.label.text = FindIslandName("Khael Roa");
	worldMap.islands.KhaelRoa.label.icon = -1;
	worldMap.islands.KhaelRoa.label.visible = "true";

	//City
	//Name
	worldMap.islands.KhaelRoa.locations.city1.name = "Khael Roa";
	//Geometry parameters
	worldMap.islands.KhaelRoa.locations.city1.position.x = 786.8229;
	worldMap.islands.KhaelRoa.locations.city1.position.y = 3.545;
	worldMap.islands.KhaelRoa.locations.city1.position.z = -440.5574;
	worldMap.islands.KhaelRoa.locations.city1.position.ay = 0.0;
	worldMap.islands.KhaelRoa.locations.city1.modelName = "leaf";
	worldMap.islands.KhaelRoa.locations.city1.visible = "false";
	worldMap.islands.KhaelRoa.locations.city1.move = "false";
	//Label
	wdmSetIcon("Khael Roa", FindTownName("Khael Roa"), -2); // KK
	worldMap.islands.KhaelRoa.locations.city1.label.visible = "false";
	// initial ship location
	worldMap.islands.KhaelRoa.locations.city1.ship.pos.x = 851.0879; // KK
	worldMap.islands.KhaelRoa.locations.city1.ship.pos.z = -481.1264; // KK

	//9=========================================================================
	//Name
	worldMap.islands.Cayman.name = "Cayman";
	//Geometry parameters
	worldMap.islands.Cayman.isVisibleName = 0;
	worldMap.islands.Cayman.position.x = 600.5008;
	worldMap.islands.Cayman.position.y = 30.0;
	worldMap.islands.Cayman.position.z = -266.3481;
	worldMap.islands.Cayman.position.rx = 594.8008;
	worldMap.islands.Cayman.position.rz = -254.6481;
	worldMap.islands.Cayman.radius = 100.0;	
	worldMap.islands.Cayman.kradius = 0.75;
	//Island label
	worldMap.islands.Cayman.label.text = FindIslandName("Cayman");
	worldMap.islands.Cayman.label.icon = -1;
	worldMap.islands.Cayman.label.visible = "true";

	//City
	//Name
	worldMap.islands.Cayman.locations.city1.name = "Grand Cayman";
	worldMap.islands.Cayman.locations.city1.real = "Grand Cayman";
	//Geometry parameters
	worldMap.islands.Cayman.locations.city1.position.x = 573.9121;
	worldMap.islands.Cayman.locations.city1.position.y = 2.5377;
	worldMap.islands.Cayman.locations.city1.position.z = -231.1446;
	worldMap.islands.Cayman.locations.city1.position.ay = 2.5765;
	worldMap.islands.Cayman.locations.city1.modelName = "town";
	worldMap.islands.Cayman.locations.city1.visible = "false";
	worldMap.islands.Cayman.locations.city1.move = "false";
	//Label
	wdmSetIcon("Grand Cayman", FindTownName("Grand Cayman"), GetTownNation("Grand Cayman")); // KK
	worldMap.islands.Cayman.locations.city1.label.visible = "false";
	// initial ship location
	worldMap.islands.Cayman.locations.city1.ship.pos.x = 585.0808; // KK
	worldMap.islands.Cayman.locations.city1.ship.pos.z = -247.2381; // KK
	//Name
	worldMap.islands.Cayman.locations.city2.name = "CaymanShore 1";
	//Geometry parameters
	worldMap.islands.Cayman.locations.city2.position.x = 545.8608;
	worldMap.islands.Cayman.locations.city2.position.y = 1.6832;
	worldMap.islands.Cayman.locations.city2.position.z = -227.7633;
	worldMap.islands.Cayman.locations.city2.position.ay = 2.5765;
	worldMap.islands.Cayman.locations.city2.modelName = "leaf";
	worldMap.islands.Cayman.locations.city2.visible = "false";
	worldMap.islands.Cayman.locations.city2.move = "false";
	//Label
	worldMap.islands.Cayman.locations.city2.label.text = "Eden Rock";
	worldMap.islands.Cayman.locations.city2.label.icon = -1;
	worldMap.islands.Cayman.locations.city2.label.visible = "false";
	// initial ship location
	worldMap.islands.Cayman.locations.city2.ship.pos.x = 540.8608;
	worldMap.islands.Cayman.locations.city2.ship.pos.z = -233.6881;
	//Name
	worldMap.islands.Cayman.locations.city3.name = "CaymanShore 2";
	//Geometry parameters
	worldMap.islands.Cayman.locations.city3.position.x = 604.6814;
	worldMap.islands.Cayman.locations.city3.position.y = 1.7303;
	worldMap.islands.Cayman.locations.city3.position.z = -279.9429;
	worldMap.islands.Cayman.locations.city3.position.ay = 2.5765;
	worldMap.islands.Cayman.locations.city3.modelName = "leaf";
	worldMap.islands.Cayman.locations.city3.visible = "false";
	worldMap.islands.Cayman.locations.city3.move = "false";
	//Label
	worldMap.islands.Cayman.locations.city3.label.text = "Cayman Kai";
	worldMap.islands.Cayman.locations.city3.label.icon = -1;
	worldMap.islands.Cayman.locations.city3.label.visible = "false";
	// initial ship location
	worldMap.islands.Cayman.locations.city3.ship.pos.x = 598.2008;
	worldMap.islands.Cayman.locations.city3.ship.pos.z = -269.6181;
	//Name
	worldMap.islands.Cayman.locations.city4.name = "CaymanShore 3";
	//Geometry parameters
	worldMap.islands.Cayman.locations.city4.position.x = 635.4861;
	worldMap.islands.Cayman.locations.city4.position.y = 1.8672;
	worldMap.islands.Cayman.locations.city4.position.z = -310.6980;
	worldMap.islands.Cayman.locations.city4.position.ay = 2.5765;
	worldMap.islands.Cayman.locations.city4.modelName = "leaf";
	worldMap.islands.Cayman.locations.city4.visible = "false";
	worldMap.islands.Cayman.locations.city4.move = "false";
	//Label
	worldMap.islands.Cayman.locations.city4.label.text = "Sand Bluff";
	worldMap.islands.Cayman.locations.city4.label.icon = -1;
	worldMap.islands.Cayman.locations.city4.label.visible = "false";
	// initial ship location
	worldMap.islands.Cayman.locations.city4.ship.pos.x = 636.0808;
	worldMap.islands.Cayman.locations.city4.ship.pos.z = -319.4181;

	//10=========================================================================
	//Name
	worldMap.islands.Hispaniola.name = "Hispaniola";
	//Geometry parameters
	worldMap.islands.Hispaniola.isVisibleName = 0;
	worldMap.islands.Hispaniola.position.x = -63.4097;
	worldMap.islands.Hispaniola.position.y = 30.0;
	worldMap.islands.Hispaniola.position.z = -455.923;
	worldMap.islands.Hispaniola.position.rx = -73.0069;
	worldMap.islands.Hispaniola.position.rz = -444.6382;
	worldMap.islands.Hispaniola.radius = 275.0;	
	worldMap.islands.Hispaniola.kradius = 0.75;
	//Island label
	worldMap.islands.Hispaniola.label.text = FindIslandName("Hispaniola");
	worldMap.islands.Hispaniola.label.icon = -1;
	worldMap.islands.Hispaniola.label.visible = "true";

	//City
	//Name
	worldMap.islands.Hispaniola.locations.city1.name = "Port au Prince";
	worldMap.islands.Hispaniola.locations.city1.real = "Port au Prince";
	//Geometry parameters
	worldMap.islands.Hispaniola.locations.city1.position.x = -16.9595;
	worldMap.islands.Hispaniola.locations.city1.position.y = 7.4634;
	worldMap.islands.Hispaniola.locations.city1.position.z = -423.9855;
	worldMap.islands.Hispaniola.locations.city1.position.ay = 2.5765;
	worldMap.islands.Hispaniola.locations.city1.modelName = "town";
	worldMap.islands.Hispaniola.locations.city1.visible = "false";
	worldMap.islands.Hispaniola.locations.city1.move = "false";
	//Label
	wdmSetIcon("Port au Prince", FindTownName("Port au Prince"), GetTownNation("Port au Prince")); // KK
	worldMap.islands.Hispaniola.locations.city1.label.visible = "false";
	// initial ship location
	worldMap.islands.Hispaniola.locations.city1.ship.pos.x = 4.4131; // KK
	worldMap.islands.Hispaniola.locations.city1.ship.pos.z = -435.0882; // KK
	//Name
	worldMap.islands.Hispaniola.locations.city2.name = "Santo Domingo";
	worldMap.islands.Hispaniola.locations.city2.real = "Santo Domingo";
	//Geometry parameters
	worldMap.islands.Hispaniola.locations.city2.position.x = -140.2759;
	worldMap.islands.Hispaniola.locations.city2.position.y = 3.9344;
	worldMap.islands.Hispaniola.locations.city2.position.z = -286.315;
	worldMap.islands.Hispaniola.locations.city2.position.ay = 2.5765;
	worldMap.islands.Hispaniola.locations.city2.modelName = "town";
	worldMap.islands.Hispaniola.locations.city2.visible = "false";
	worldMap.islands.Hispaniola.locations.city2.move = "false";
	//Label
	wdmSetIcon("Santo Domingo", FindTownName("Santo Domingo"), GetTownNation("Santo Domingo")); // KK
	worldMap.islands.Hispaniola.locations.city2.label.visible = "false";
	// initial ship location
	worldMap.islands.Hispaniola.locations.city2.ship.pos.x = -129.0269; // KK
	worldMap.islands.Hispaniola.locations.city2.ship.pos.z = -276.4582; // KK
	//Name
	worldMap.islands.Hispaniola.locations.city3.name = "Tortuga";
	worldMap.islands.Hispaniola.locations.city3.real = "Tortuga";
	//Geometry parameters
	worldMap.islands.Hispaniola.locations.city3.position.x = 9.7264;
	worldMap.islands.Hispaniola.locations.city3.position.y = 3.6288;
	worldMap.islands.Hispaniola.locations.city3.position.z = -672.3076;
	worldMap.islands.Hispaniola.locations.city3.position.ay = 2.5765;
	worldMap.islands.Hispaniola.locations.city3.modelName = "town";
	worldMap.islands.Hispaniola.locations.city3.visible = "false";
	worldMap.islands.Hispaniola.locations.city3.move = "false";
	//Label
	wdmSetIcon("Tortuga", FindTownName("Tortuga"), GetTownNation("Tortuga")); // KK
	worldMap.islands.Hispaniola.locations.city3.label.visible = "false";
	// initial ship location
	worldMap.islands.Hispaniola.locations.city3.ship.pos.x = 3.4031; // KK
	worldMap.islands.Hispaniola.locations.city3.ship.pos.z = -664.9182; // KK
	//Name
	worldMap.islands.Hispaniola.locations.city4.name = "HiShore 1";
	//Geometry parameters
	worldMap.islands.Hispaniola.locations.city4.position.x = -179.947;
	worldMap.islands.Hispaniola.locations.city4.position.y = 4.4292;
	worldMap.islands.Hispaniola.locations.city4.position.z = -253.5226;
	worldMap.islands.Hispaniola.locations.city4.position.ay = 0.0;
	worldMap.islands.Hispaniola.locations.city4.modelName = "leaf";
	worldMap.islands.Hispaniola.locations.city4.visible = "false";
	worldMap.islands.Hispaniola.locations.city4.move = "false";
	//Label
	worldMap.islands.Hispaniola.locations.city4.label.text = "Boca de Yuman";
	worldMap.islands.Hispaniola.locations.city4.label.icon = -1;
	worldMap.islands.Hispaniola.locations.city4.label.visible = "false";
	// initial ship location
	worldMap.islands.Hispaniola.locations.city4.ship.pos.x = -195.6769;
	worldMap.islands.Hispaniola.locations.city4.ship.pos.z = -233.7182;
	//Name
	worldMap.islands.Hispaniola.locations.city5.name = "HiShore 2";
	//Geometry parameters
	worldMap.islands.Hispaniola.locations.city5.position.x = -134.8179;
	worldMap.islands.Hispaniola.locations.city5.position.y = 4.6608;
	worldMap.islands.Hispaniola.locations.city5.position.z = -470.0968;
	worldMap.islands.Hispaniola.locations.city5.position.ay = 0.0;
	worldMap.islands.Hispaniola.locations.city5.modelName = "leaf";
	worldMap.islands.Hispaniola.locations.city5.visible = "false";
	worldMap.islands.Hispaniola.locations.city5.move = "false";
	//Label
	worldMap.islands.Hispaniola.locations.city5.label.text = "Boca de Hubon";
	worldMap.islands.Hispaniola.locations.city5.label.icon = -1;
	worldMap.islands.Hispaniola.locations.city5.label.visible = "false";
	// initial ship location
	worldMap.islands.Hispaniola.locations.city5.ship.pos.x = -140.1969;
	worldMap.islands.Hispaniola.locations.city5.ship.pos.z = -487.2582;
	//Name
	worldMap.islands.Hispaniola.locations.city6.name = "HiShore 3";
	//Geometry parameters
	worldMap.islands.Hispaniola.locations.city6.position.x = -222.0431;
	worldMap.islands.Hispaniola.locations.city6.position.y = 3.4424;
	worldMap.islands.Hispaniola.locations.city6.position.z = -446.4653;
	worldMap.islands.Hispaniola.locations.city6.position.ay = 0.0;
	worldMap.islands.Hispaniola.locations.city6.modelName = "leaf";
	worldMap.islands.Hispaniola.locations.city6.visible = "false";
	worldMap.islands.Hispaniola.locations.city6.move = "false";
	//Label
	worldMap.islands.Hispaniola.locations.city6.label.text = "Cape Francos";
	worldMap.islands.Hispaniola.locations.city6.label.icon = -1;
	worldMap.islands.Hispaniola.locations.city6.label.visible = "false";
	// initial ship location
	worldMap.islands.Hispaniola.locations.city6.ship.pos.x = -249.7869;
	worldMap.islands.Hispaniola.locations.city6.ship.pos.z = -447.4082;
	//Name
	worldMap.islands.Hispaniola.locations.city7.name = "HiShore 4";
	//Geometry parameters
	worldMap.islands.Hispaniola.locations.city7.position.x = -42.4663;
	worldMap.islands.Hispaniola.locations.city7.position.y = 4.2723;
	worldMap.islands.Hispaniola.locations.city7.position.z = -353.8619;
	worldMap.islands.Hispaniola.locations.city7.position.ay = 0.0;
	worldMap.islands.Hispaniola.locations.city7.modelName = "leaf";
	worldMap.islands.Hispaniola.locations.city7.visible = "false";
	worldMap.islands.Hispaniola.locations.city7.move = "false";
	//Label
	worldMap.islands.Hispaniola.locations.city7.label.text = "Ile a Vache";
	worldMap.islands.Hispaniola.locations.city7.label.icon = -1;
	worldMap.islands.Hispaniola.locations.city7.label.visible = "false";
	// initial ship location
	worldMap.islands.Hispaniola.locations.city7.ship.pos.x = -36.7296;
	worldMap.islands.Hispaniola.locations.city7.ship.pos.z = -336.7162;

	//11=========================================================================
	//Name
	worldMap.islands.Cuba.name = "Cuba";
	//Geometry parameters
	worldMap.islands.Cuba.isVisibleName = 0;
	worldMap.islands.Cuba.position.x = 458.8936;
	worldMap.islands.Cuba.position.y = 30.0;
	worldMap.islands.Cuba.position.z = -684.1776;
	worldMap.islands.Cuba.position.rx = 469.0741;
	worldMap.islands.Cuba.position.rz = -724.3237;
	worldMap.islands.Cuba.radius = 345.0;
	worldMap.islands.Cuba.kradius = 0.75;
	//Island label
	worldMap.islands.Cuba.label.text = FindIslandName("Cuba");
	worldMap.islands.Cuba.label.icon = -1;
	worldMap.islands.Cuba.label.visible = "true";

	//City
	//Name
	worldMap.islands.Cuba.locations.city1.name = "Havana";
	worldMap.islands.Cuba.locations.city1.real = "Havana";
	//Geometry parameters
	worldMap.islands.Cuba.locations.city1.position.x = 665.9487;
	worldMap.islands.Cuba.locations.city1.position.y = 3.5548;
	worldMap.islands.Cuba.locations.city1.position.z = -794.3237;
	worldMap.islands.Cuba.locations.city1.position.ay = 2.5765;
	worldMap.islands.Cuba.locations.city1.modelName = "town";
	worldMap.islands.Cuba.locations.city1.visible = "false";
	worldMap.islands.Cuba.locations.city1.move = "false";
	//Label
	wdmSetIcon("Havana", FindTownName("Havana"), GetTownNation("Havana")); // KK
	worldMap.islands.Cuba.locations.city1.label.visible = "false";
	// initial ship location
	worldMap.islands.Cuba.locations.city1.ship.pos.x = 679.4241; // KK
	worldMap.islands.Cuba.locations.city1.ship.pos.z = -807.0537; // KK
	//Name
	worldMap.islands.Cuba.locations.city2.name = "Santiago";
	worldMap.islands.Cuba.locations.city2.real = "Santiago";
	//Geometry parameters
	worldMap.islands.Cuba.locations.city2.position.x = 341.0741;
	worldMap.islands.Cuba.locations.city2.position.y = 4.0596;
	worldMap.islands.Cuba.locations.city2.position.z = -466.252;
	worldMap.islands.Cuba.locations.city2.position.ay = 2.5765;
	worldMap.islands.Cuba.locations.city2.modelName = "town";
	worldMap.islands.Cuba.locations.city2.visible = "false";
	worldMap.islands.Cuba.locations.city2.move = "false";
	//Label
	wdmSetIcon("Santiago", FindTownName("Santiago"), GetTownNation("Santiago")); // KK
	worldMap.islands.Cuba.locations.city2.label.visible = "false";
	// initial ship location
	worldMap.islands.Cuba.locations.city2.ship.pos.x = 341.1041; // KK
	worldMap.islands.Cuba.locations.city2.ship.pos.z = -450.5037; // KK
	//Name
	worldMap.islands.Cuba.locations.city3.name = "CubShore 1";
	//Geometry parameters
	worldMap.islands.Cuba.locations.city3.position.x = 427.9565;
	worldMap.islands.Cuba.locations.city3.position.y = 4.441;
	worldMap.islands.Cuba.locations.city3.position.z = -608.8666;
	worldMap.islands.Cuba.locations.city3.position.ay = 2.5765;
	worldMap.islands.Cuba.locations.city3.modelName = "leaf";
	worldMap.islands.Cuba.locations.city3.visible = "false";
	worldMap.islands.Cuba.locations.city3.move = "false";
	//Label
	worldMap.islands.Cuba.locations.city3.label.text = "Bahia de San Antonio";
	worldMap.islands.Cuba.locations.city3.label.icon = -1;
	worldMap.islands.Cuba.locations.city3.label.visible = "false";
	// initial ship location
	worldMap.islands.Cuba.locations.city3.ship.pos.x = 439.6841;
	worldMap.islands.Cuba.locations.city3.ship.pos.z = -632.2637;
	//Name
	worldMap.islands.Cuba.locations.city4.name = "CubShore 2";
	//Geometry parameters
	worldMap.islands.Cuba.locations.city4.position.x = 607.7595;
	worldMap.islands.Cuba.locations.city4.position.y = 3.6814;
	worldMap.islands.Cuba.locations.city4.position.z = -723.2116;
	worldMap.islands.Cuba.locations.city4.position.ay = 2.5765;
	worldMap.islands.Cuba.locations.city4.modelName = "leaf";
	worldMap.islands.Cuba.locations.city4.visible = "false";
	worldMap.islands.Cuba.locations.city4.move = "false";
	//Label
	worldMap.islands.Cuba.locations.city4.label.text = "Bahia de Moa";
	worldMap.islands.Cuba.locations.city4.label.icon = -1;
	worldMap.islands.Cuba.locations.city4.label.visible = "false";
	// initial ship location
	worldMap.islands.Cuba.locations.city4.ship.pos.x = 607.9641;
	worldMap.islands.Cuba.locations.city4.ship.pos.z = -708.4737;
	//Name
	worldMap.islands.Cuba.locations.city5.name = "CubShore 3";
	//Geometry parameters
	worldMap.islands.Cuba.locations.city5.position.x = 314.6297;
	worldMap.islands.Cuba.locations.city5.position.y = 5.665;
	worldMap.islands.Cuba.locations.city5.position.z = -608.3251;
	worldMap.islands.Cuba.locations.city5.position.ay = 2.5765;
	worldMap.islands.Cuba.locations.city5.modelName = "leaf";
	worldMap.islands.Cuba.locations.city5.visible = "false";
	worldMap.islands.Cuba.locations.city5.move = "false";
	//Label
	worldMap.islands.Cuba.locations.city5.label.text = "Punta de Maisi";
	worldMap.islands.Cuba.locations.city5.label.icon = -1;
	worldMap.islands.Cuba.locations.city5.label.visible = "false";
	// initial ship location
	worldMap.islands.Cuba.locations.city5.ship.pos.x = 297.9401;
	worldMap.islands.Cuba.locations.city5.ship.pos.z = -609.159;
	//Name
	worldMap.islands.Cuba.locations.city6.name = "CubShore 4";
	//Geometry parameters
	worldMap.islands.Cuba.locations.city6.position.x = 605.6831;
	worldMap.islands.Cuba.locations.city6.position.y = 4.0355;
	worldMap.islands.Cuba.locations.city6.position.z = -822.7637;
	worldMap.islands.Cuba.locations.city6.position.ay = 2.5765;
	worldMap.islands.Cuba.locations.city6.modelName = "leaf";
	worldMap.islands.Cuba.locations.city6.visible = "false";
	worldMap.islands.Cuba.locations.city6.move = "false";
	//Label
	worldMap.islands.Cuba.locations.city6.label.text = "Playa de Sabana";
	worldMap.islands.Cuba.locations.city6.label.icon = -1;
	worldMap.islands.Cuba.locations.city6.label.visible = "false";
	// initial ship location
	worldMap.islands.Cuba.locations.city6.ship.pos.x = 606.7924;
	worldMap.islands.Cuba.locations.city6.ship.pos.z = -836.8972;
	//Name
	worldMap.islands.Cuba.locations.city7.name = "CubShore 5";
	//Geometry parameters
	worldMap.islands.Cuba.locations.city7.position.x = 390.3229;
	worldMap.islands.Cuba.locations.city7.position.y = 4.1671;
	worldMap.islands.Cuba.locations.city7.position.z = -470.0433;
	worldMap.islands.Cuba.locations.city7.position.ay = 2.5765;
	worldMap.islands.Cuba.locations.city7.modelName = "leaf";
	worldMap.islands.Cuba.locations.city7.visible = "false";
	worldMap.islands.Cuba.locations.city7.move = "false";
	//Label
	worldMap.islands.Cuba.locations.city7.label.text = "Playa de Sierra Maestra";
	worldMap.islands.Cuba.locations.city7.label.icon = -1;
	worldMap.islands.Cuba.locations.city7.label.visible = "false";
	// initial ship location
	worldMap.islands.Cuba.locations.city7.ship.pos.x = 388.8241;
	worldMap.islands.Cuba.locations.city7.ship.pos.z = -448.9037;
	//Name
	worldMap.islands.Cuba.locations.city8.name = "CubShore 6";
	//Geometry parameters
	worldMap.islands.Cuba.locations.city8.position.x = 475.8303;
	worldMap.islands.Cuba.locations.city8.position.y = 3.736;
	worldMap.islands.Cuba.locations.city8.position.z = -654.3232;
	worldMap.islands.Cuba.locations.city8.position.ay = 2.5765;
	worldMap.islands.Cuba.locations.city8.modelName = "leaf";
	worldMap.islands.Cuba.locations.city8.visible = "false";
	worldMap.islands.Cuba.locations.city8.move = "false";
	//Label
	worldMap.islands.Cuba.locations.city8.label.text = "Peninsula de Zapata";
	worldMap.islands.Cuba.locations.city8.label.icon = -1;
	worldMap.islands.Cuba.locations.city8.label.visible = "false";
	// initial ship location
	worldMap.islands.Cuba.locations.city8.ship.pos.x = 479.5174;
	worldMap.islands.Cuba.locations.city8.ship.pos.z = -643.6989;

	//12=========================================================================
	//Name
	worldMap.islands.Guadeloupe.name = "Guadeloupe";
	//Geometry parameters
	worldMap.islands.Guadeloupe.isVisibleName = 0;
	worldMap.islands.Guadeloupe.position.x = -720.2772;
	worldMap.islands.Guadeloupe.position.y = 30.0;
	worldMap.islands.Guadeloupe.position.z = 13.939;
	worldMap.islands.Guadeloupe.position.rx = -740.3181;
	worldMap.islands.Guadeloupe.position.rz = 19.6724;
	worldMap.islands.Guadeloupe.radius = 110.0;	
	worldMap.islands.Guadeloupe.kradius = 0.75;
	//Island label
	worldMap.islands.Guadeloupe.label.text = FindIslandName("Guadeloupe");
	worldMap.islands.Guadeloupe.label.icon = -1;
	worldMap.islands.Guadeloupe.label.visible = "true";

	//City
	//Name
	if(GetCurrentPeriod() == PERIOD_EARLY_EXPLORERS)
	{
		worldMap.islands.Guadeloupe.locations.city1.name = "GuadShore 2";
		worldMap.islands.Guadeloupe.locations.city1.modelName = "leaf";
		worldMap.islands.Guadeloupe.locations.city1.label.text = "Bahía Grande";
		worldMap.islands.Guadeloupe.locations.city1.label.icon = -1;

		worldMap.islands.Guadeloupe.locations.city2.label.text = "Ensenada del Bosque Quebrado";
	}
	else
	{
		worldMap.islands.Guadeloupe.locations.city1.name = "Pointe a Pitre";
		worldMap.islands.Guadeloupe.locations.city1.real = "Pointe a Pitre";
		worldMap.islands.Guadeloupe.locations.city1.modelName = "town";
		wdmSetIcon("Pointe a Pitre", FindTownName("Pointe a Pitre"), GetTownNation("Pointe a Pitre")); // KK

		worldMap.islands.Guadeloupe.locations.city2.label.text = "Anse Casse-Bois";
	}
	//Geometry parameters
	worldMap.islands.Guadeloupe.locations.city1.position.x = -715.3181;
	worldMap.islands.Guadeloupe.locations.city1.position.y = 4.0855;
	worldMap.islands.Guadeloupe.locations.city1.position.z = 3.3855;
	worldMap.islands.Guadeloupe.locations.city1.position.ay = 2.5765;
	worldMap.islands.Guadeloupe.locations.city1.visible = "false";
	worldMap.islands.Guadeloupe.locations.city1.move = "false";
	//Label
	worldMap.islands.Guadeloupe.locations.city1.label.visible = "false";
	// initial ship location
	worldMap.islands.Guadeloupe.locations.city1.ship.pos.x = -717.0381; // KK
	worldMap.islands.Guadeloupe.locations.city1.ship.pos.z = 13.0324; // KK
	//Name
	worldMap.islands.Guadeloupe.locations.city2.name = "GuadShore 1";
	//Geometry parameters
	worldMap.islands.Guadeloupe.locations.city2.position.x = -779.1116;
	worldMap.islands.Guadeloupe.locations.city2.position.y = 4.1819;
	worldMap.islands.Guadeloupe.locations.city2.position.z = -13.2189;
	worldMap.islands.Guadeloupe.locations.city2.position.ay = 0.0;
	worldMap.islands.Guadeloupe.locations.city2.modelName = "leaf";
	worldMap.islands.Guadeloupe.locations.city2.visible = "false";
	worldMap.islands.Guadeloupe.locations.city2.move = "false";
	//Label
	worldMap.islands.Guadeloupe.locations.city2.label.icon = -1;
	worldMap.islands.Guadeloupe.locations.city2.label.visible = "false";
	// initial ship location
	worldMap.islands.Guadeloupe.locations.city2.ship.pos.x = -785.9379;
	worldMap.islands.Guadeloupe.locations.city2.ship.pos.z = -26.7967;

	//13=========================================================================
	//Name
	// LDH changed from .Sent. - 31Dec08
	worldMap.islands.SaintMartin.name = "SaintMartin";
	//Geometry parameters
	worldMap.islands.SaintMartin.isVisibleName = 0;
	worldMap.islands.SaintMartin.position.x = -725.3333;
	worldMap.islands.SaintMartin.position.y = 30.0;
	worldMap.islands.SaintMartin.position.z = -366.6779;
	worldMap.islands.SaintMartin.position.rx = -722.6486;
	worldMap.islands.SaintMartin.position.rz = -368.5712;
	worldMap.islands.SaintMartin.radius = 80.0;	
	worldMap.islands.SaintMartin.kradius = 0.75;
	//Island label
	worldMap.islands.SaintMartin.label.text = FindIslandName("Saint Martin");
	worldMap.islands.SaintMartin.label.icon = -1;
	worldMap.islands.SaintMartin.label.visible = "true";

	//City
	//Name
	worldMap.islands.SaintMartin.locations.city1.name = "Philipsburg";
	worldMap.islands.SaintMartin.locations.city1.real = "Philipsburg";
	//Geometry parameters
	worldMap.islands.SaintMartin.locations.city1.position.x = -719.6706;
	worldMap.islands.SaintMartin.locations.city1.position.y = 2.0558;
	worldMap.islands.SaintMartin.locations.city1.position.z = -382.1479;
	worldMap.islands.SaintMartin.locations.city1.position.ay = 1.5765;
	worldMap.islands.SaintMartin.locations.city1.modelName = "town";
	worldMap.islands.SaintMartin.locations.city1.visible = "false";
	worldMap.islands.SaintMartin.locations.city1.move = "false";
	//Label
	wdmSetIcon("Philipsburg", FindTownName("Philipsburg"), GetTownNation("Philipsburg")); // KK
	worldMap.islands.SaintMartin.locations.city1.label.visible = "false";
	// initial ship location
	worldMap.islands.SaintMartin.locations.city1.ship.pos.x = -712.3986; // KK
	worldMap.islands.SaintMartin.locations.city1.ship.pos.z = -385.3712; // KK
	//Name
	worldMap.islands.SaintMartin.locations.city2.name = "Marigot";
	worldMap.islands.SaintMartin.locations.city2.real = "Marigot";
	//Geometry parameters
	worldMap.islands.SaintMartin.locations.city2.position.x = -733.8557;
	worldMap.islands.SaintMartin.locations.city2.position.y = 2.1656;
	worldMap.islands.SaintMartin.locations.city2.position.z = -351.7199;
	worldMap.islands.SaintMartin.locations.city2.position.ay = 1.5765;
	worldMap.islands.SaintMartin.locations.city2.modelName = "town";
	worldMap.islands.SaintMartin.locations.city2.visible = "false";
	worldMap.islands.SaintMartin.locations.city2.move = "false";
	//Label
	wdmSetIcon("Marigot", FindTownName("Marigot"), GetTownNation("Marigot")); // KK
	worldMap.islands.SaintMartin.locations.city2.label.visible = "false";
	// initial ship location
	worldMap.islands.SaintMartin.locations.city2.ship.pos.x = -745.6486; // KK
	worldMap.islands.SaintMartin.locations.city2.ship.pos.z = -347.3212; // KK
	//Name
	worldMap.islands.SaintMartin.locations.city3.name = "SaintMartin_shore_01";
	//Geometry parameters
	worldMap.islands.SaintMartin.locations.city3.position.x = -752.5318;
	worldMap.islands.SaintMartin.locations.city3.position.y = 3.1175;
	worldMap.islands.SaintMartin.locations.city3.position.z = -393.1995;
	worldMap.islands.SaintMartin.locations.city3.position.ay = 0.0;
	worldMap.islands.SaintMartin.locations.city3.modelName = "leaf";
	worldMap.islands.SaintMartin.locations.city3.visible = "false";
	worldMap.islands.SaintMartin.locations.city3.move = "false";
	//Label
	worldMap.islands.SaintMartin.locations.city3.label.text = "Simpson Bay";
	worldMap.islands.SaintMartin.locations.city3.label.icon = -1;
	worldMap.islands.SaintMartin.locations.city3.label.visible = "false";
	// initial ship location
	worldMap.islands.SaintMartin.locations.city3.ship.pos.x = -762.8386;
	worldMap.islands.SaintMartin.locations.city3.ship.pos.z = -401.2712;
	//Name
	worldMap.islands.SaintMartin.locations.city4.name = "SaintMartin_shore_02";
	//Geometry parameters
	worldMap.islands.SaintMartin.locations.city4.position.x = -699.4996;
	worldMap.islands.SaintMartin.locations.city4.position.y = 2.9686;
	worldMap.islands.SaintMartin.locations.city4.position.z = -345.7777;
	worldMap.islands.SaintMartin.locations.city4.position.ay = 0.0;
	worldMap.islands.SaintMartin.locations.city4.modelName = "leaf";
	worldMap.islands.SaintMartin.locations.city4.visible = "false";
	worldMap.islands.SaintMartin.locations.city4.move = "false";
	//Label
	worldMap.islands.SaintMartin.locations.city4.label.text = "Baie Orient";
	worldMap.islands.SaintMartin.locations.city4.label.icon = -1;
	worldMap.islands.SaintMartin.locations.city4.label.visible = "false";
	// initial ship location
	worldMap.islands.SaintMartin.locations.city4.ship.pos.x = -689.6086;
	worldMap.islands.SaintMartin.locations.city4.ship.pos.z = -340.6944;

	//14=========================================================================
	//Name
	worldMap.islands.Antigua.name = "Antigua";
	//Geometry parameters
	worldMap.islands.Antigua.isVisibleName = 0;
	worldMap.islands.Antigua.position.x = -907.983;
	worldMap.islands.Antigua.position.y = 30.0;
	worldMap.islands.Antigua.position.z = -236.7188;
	worldMap.islands.Antigua.position.rx = -905.6271;
	worldMap.islands.Antigua.position.rz = -239.7206;
	worldMap.islands.Antigua.radius = 90.0;	
	worldMap.islands.Antigua.kradius = 0.75;
	//Island label
	worldMap.islands.Antigua.label.text = FindIslandName("Antigua");
	worldMap.islands.Antigua.label.icon = -1;
	worldMap.islands.Antigua.label.visible = "true";

	//City
	//Name
	worldMap.islands.Antigua.locations.city1.name = "St John's";
	worldMap.islands.Antigua.locations.city1.real = "St John's";
	//Geometry parameters
	worldMap.islands.Antigua.locations.city1.position.x = -894.2138;
	worldMap.islands.Antigua.locations.city1.position.y = 2.9738;
	worldMap.islands.Antigua.locations.city1.position.z = -241.2955;
	worldMap.islands.Antigua.locations.city1.position.ay = 1.5765;
	worldMap.islands.Antigua.locations.city1.modelName = "town";
	worldMap.islands.Antigua.locations.city1.visible = "false";
	worldMap.islands.Antigua.locations.city1.move = "false";
	//Label
	wdmSetIcon("St John's", FindTownName("St John's"), GetTownNation("St John's")); // KK
	worldMap.islands.Antigua.locations.city1.label.visible = "false";
	// initial ship location
	worldMap.islands.Antigua.locations.city1.ship.pos.x = -906.0667; // KK
	worldMap.islands.Antigua.locations.city1.ship.pos.z = -234.8193; // KK
	//Name
	worldMap.islands.Antigua.locations.city2.name = "Antigua_shore";
	//Geometry parameters
	worldMap.islands.Antigua.locations.city2.position.x = -963.139;
	worldMap.islands.Antigua.locations.city2.position.y = 3.8908;
	worldMap.islands.Antigua.locations.city2.position.z = -231.3354;
	worldMap.islands.Antigua.locations.city2.position.ay = 2.5765;
	worldMap.islands.Antigua.locations.city2.modelName = "leaf";
	worldMap.islands.Antigua.locations.city2.visible = "false";
	worldMap.islands.Antigua.locations.city2.move = "false";
	//Label
	worldMap.islands.Antigua.locations.city2.label.text = "Muscetto Cove";
	worldMap.islands.Antigua.locations.city2.label.icon = -1;
	worldMap.islands.Antigua.locations.city2.label.visible = "false";
	// initial ship location
	worldMap.islands.Antigua.locations.city2.ship.pos.x = -971.9271;
	worldMap.islands.Antigua.locations.city2.ship.pos.z = -243.2906;

	//15=========================================================================
	//Name
	// LDH changed from .Terks. - 05Jan09
	worldMap.islands.Turks.name = "Turks";
	//Geometry parameters
	worldMap.islands.Turks.isVisibleName = 0;
	worldMap.islands.Turks.position.x = -144.7866;
	worldMap.islands.Turks.position.y = 30.0;
	worldMap.islands.Turks.position.z = -819.767;
	worldMap.islands.Turks.position.rx = -129.5201;
	worldMap.islands.Turks.position.rz = -812.7909;
	worldMap.islands.Turks.radius = 90.0;	
	worldMap.islands.Turks.kradius = 0.75;
	//Island label
	worldMap.islands.Turks.label.text = FindIslandName("Turks");
	worldMap.islands.Turks.label.icon = -1;
	worldMap.islands.Turks.label.visible = "true";

	//City
	//Name
	worldMap.islands.Turks.locations.city1.name = "Grand Turk";
	worldMap.islands.Turks.locations.city1.real = "Grand Turk";
	//Geometry parameters
	worldMap.islands.Turks.locations.city1.position.x = -144.5201;
	worldMap.islands.Turks.locations.city1.position.y = 3.665;
	worldMap.islands.Turks.locations.city1.position.z = -819.7909;
	worldMap.islands.Turks.locations.city1.position.ay = 1.5765;
	worldMap.islands.Turks.locations.city1.modelName = "town";
	worldMap.islands.Turks.locations.city1.visible = "false";
	worldMap.islands.Turks.locations.city1.move = "false";
	//Label
	wdmSetIcon("Grand Turk", FindTownName("Grand Turk"), GetTownNation("Grand Turk")); // KK
	worldMap.islands.Turks.locations.city1.label.visible = "false";
	// initial ship location
	worldMap.islands.Turks.locations.city1.ship.pos.x = -142.9416; // KK
	worldMap.islands.Turks.locations.city1.ship.pos.z = -829.4609; // KK
	//Name
	worldMap.islands.Turks.locations.city2.name = "TurksShore 1";
	//Geometry parameters
	worldMap.islands.Turks.locations.city2.position.x = -144.5201;
	worldMap.islands.Turks.locations.city2.position.y = 1.9502;
	worldMap.islands.Turks.locations.city2.position.z = -789.7688;
	worldMap.islands.Turks.locations.city2.position.ay = 0.0;
	worldMap.islands.Turks.locations.city2.modelName = "leaf";
	worldMap.islands.Turks.locations.city2.visible = "false";
	worldMap.islands.Turks.locations.city2.move = "false";
	//Label
	worldMap.islands.Turks.locations.city2.label.text = "White Reefs";
	worldMap.islands.Turks.locations.city2.label.icon = -1;
	worldMap.islands.Turks.locations.city2.label.visible = "false";
	// initial ship location
	worldMap.islands.Turks.locations.city2.ship.pos.x = -154.8901;
	worldMap.islands.Turks.locations.city2.ship.pos.z = -782.3209;
	//Name
	worldMap.islands.Turks.locations.city3.name = "TurksShore 2";
	//Geometry parameters
	worldMap.islands.Turks.locations.city3.position.x = -170.0388;
	worldMap.islands.Turks.locations.city3.position.y = 1.5196;
	worldMap.islands.Turks.locations.city3.position.z = -851.6784;
	worldMap.islands.Turks.locations.city3.position.ay = 0.0;
	worldMap.islands.Turks.locations.city3.modelName = "leaf";
	worldMap.islands.Turks.locations.city3.visible = "false";
	worldMap.islands.Turks.locations.city3.move = "false";
	//Label
	worldMap.islands.Turks.locations.city3.label.text = "Sandy Point";
	worldMap.islands.Turks.locations.city3.label.icon = -1;
	worldMap.islands.Turks.locations.city3.label.visible = "false";
	// initial ship location
	worldMap.islands.Turks.locations.city3.ship.pos.x = -164.6001;
	worldMap.islands.Turks.locations.city3.ship.pos.z = -857.4209;
	//Name
	worldMap.islands.Turks.locations.city4.name = "TurksShore 3";
	//Geometry parameters
	worldMap.islands.Turks.locations.city4.position.x = -100.0533;
	worldMap.islands.Turks.locations.city4.position.y = 1.713;
	worldMap.islands.Turks.locations.city4.position.z = -824.8675;
	worldMap.islands.Turks.locations.city4.position.ay = 0.0;
	worldMap.islands.Turks.locations.city4.modelName = "leaf";
	worldMap.islands.Turks.locations.city4.visible = "false";
	worldMap.islands.Turks.locations.city4.move = "false";
	//Label
	worldMap.islands.Turks.locations.city4.label.text = "Birds Cove";
	worldMap.islands.Turks.locations.city4.label.icon = -1;
	worldMap.islands.Turks.locations.city4.label.visible = "false";
	// initial ship location
	worldMap.islands.Turks.locations.city4.ship.pos.x = -97.1401;
	worldMap.islands.Turks.locations.city4.ship.pos.z = -817.6909;
	//Name
	worldMap.islands.Turks.locations.city5.name = "Turks_Lighthouse";
	//Geometry parameters
	worldMap.islands.Turks.locations.city5.position.x = -121.0422;
	worldMap.islands.Turks.locations.city5.position.y = 2.4311;
	worldMap.islands.Turks.locations.city5.position.z = -823.8687;
	worldMap.islands.Turks.locations.city5.position.ay = 0.0;
	worldMap.islands.Turks.locations.city5.modelName = "leaf";
	worldMap.islands.Turks.locations.city5.visible = "false";
	worldMap.islands.Turks.locations.city5.move = "false";
	//Label
	worldMap.islands.Turks.locations.city5.label.text = "Old Lighthouse";
	worldMap.islands.Turks.locations.city5.label.icon = -1;
	worldMap.islands.Turks.locations.city5.label.visible = "false";
	// initial ship location
	worldMap.islands.Turks.locations.city5.ship.pos.x = -120.0001;
	worldMap.islands.Turks.locations.city5.ship.pos.z = -834.8509;

	//16=========================================================================
	//Name
	worldMap.islands.Curacao.name = "Curacao";
	//Geometry parameters
	worldMap.islands.Curacao.isVisibleName = 0;
	worldMap.islands.Curacao.position.x = -341.0551;
	worldMap.islands.Curacao.position.y = 30.0;
	worldMap.islands.Curacao.position.z = 608.5984;
	worldMap.islands.Curacao.position.rx = -323.7226;
	worldMap.islands.Curacao.position.rz = 636.0241;
	worldMap.islands.Curacao.radius = 85.0;
	worldMap.islands.Curacao.kradius = 0.75;
	//Island label
	worldMap.islands.Curacao.label.text = FindIslandName("Curacao");
	worldMap.islands.Curacao.label.icon = -1;
	worldMap.islands.Curacao.label.visible = "true";

	//City
	//Name
	worldMap.islands.Curacao.locations.city1.name = "Willemstad";
	worldMap.islands.Curacao.locations.city1.real = "Willemstad";
	//Geometry parameters
	worldMap.islands.Curacao.locations.city1.position.x = -324.2226;
	worldMap.islands.Curacao.locations.city1.position.y = 3.306;
	worldMap.islands.Curacao.locations.city1.position.z = 596.6591;
	worldMap.islands.Curacao.locations.city1.position.ay = 1.5765;
	worldMap.islands.Curacao.locations.city1.modelName = "town";
	worldMap.islands.Curacao.locations.city1.visible = "false";
	worldMap.islands.Curacao.locations.city1.move = "false";
	//Label
	wdmSetIcon("Willemstad", FindTownName("Willemstad"), GetTownNation("Willemstad")); // KK
	worldMap.islands.Curacao.locations.city1.label.visible = "false";
	// initial ship location
	worldMap.islands.Curacao.locations.city1.ship.pos.x = -324.2226;
	worldMap.islands.Curacao.locations.city1.ship.pos.z = 587.7595;
	//Name
	worldMap.islands.Curacao.locations.city2.name = "CuracaoShore 1";
	//Geometry parameters
	worldMap.islands.Curacao.locations.city2.position.x = -396.8925;
	worldMap.islands.Curacao.locations.city2.position.y = 2.8527;
	worldMap.islands.Curacao.locations.city2.position.z = 616.7492;
	worldMap.islands.Curacao.locations.city2.position.ay = 0.0;
	worldMap.islands.Curacao.locations.city2.modelName = "leaf";
	worldMap.islands.Curacao.locations.city2.visible = "false";
	worldMap.islands.Curacao.locations.city2.move = "false";
	//Label
	worldMap.islands.Curacao.locations.city2.label.text = "Bullen Bay";
	worldMap.islands.Curacao.locations.city2.label.icon = -1;
	worldMap.islands.Curacao.locations.city2.label.visible = "false";
	// initial ship location
	worldMap.islands.Curacao.locations.city2.ship.pos.x = -404.1746;
	worldMap.islands.Curacao.locations.city2.ship.pos.z = 618.9048;
	//Name
	worldMap.islands.Curacao.locations.city3.name = "CuracaoShore 2";
	//Geometry parameters
	worldMap.islands.Curacao.locations.city3.position.x = -283.5058;
	worldMap.islands.Curacao.locations.city3.position.y = 2.7098;
	worldMap.islands.Curacao.locations.city3.position.z = 630.1101;
	worldMap.islands.Curacao.locations.city3.position.ay = 0.0;
	worldMap.islands.Curacao.locations.city3.modelName = "leaf";
	worldMap.islands.Curacao.locations.city3.visible = "false";
	worldMap.islands.Curacao.locations.city3.move = "false";
	//Label
	worldMap.islands.Curacao.locations.city3.label.text = "Bocht Van Hato";
	worldMap.islands.Curacao.locations.city3.label.icon = -1;
	worldMap.islands.Curacao.locations.city3.label.visible = "false";
	// initial ship location
	worldMap.islands.Curacao.locations.city3.ship.pos.x = -279.0132;
	worldMap.islands.Curacao.locations.city3.ship.pos.z = 634.4284;
	
	//17=========================================================================
	//Name
	worldMap.islands.Eleuthera.name = "Eleuthera";
	//Geometry parameters
	worldMap.islands.Eleuthera.isVisibleName = 0;
	worldMap.islands.Eleuthera.position.x = 133.2902;
	worldMap.islands.Eleuthera.position.y = 30.0;
	worldMap.islands.Eleuthera.position.z = -950.2642;
	worldMap.islands.Eleuthera.position.rx = 164.3902;
	worldMap.islands.Eleuthera.position.rz = -977.6642;
	worldMap.islands.Eleuthera.radius = 70.0;
	worldMap.islands.Eleuthera.kradius = 0.75;
	//Island label
	worldMap.islands.Eleuthera.label.text = FindIslandName("Eleuthera");
	worldMap.islands.Eleuthera.label.icon = -1;
	worldMap.islands.Eleuthera.label.visible = "true";

	//City
	//Name
	worldMap.islands.Eleuthera.locations.city1.name = "Eleuthera";
	worldMap.islands.Eleuthera.locations.city1.real = "Eleuthera";
	//Geometry parameters
	worldMap.islands.Eleuthera.locations.city1.position.x = 143.0902;
	worldMap.islands.Eleuthera.locations.city1.position.y = 3.665;
	worldMap.islands.Eleuthera.locations.city1.position.z = -954.4642;
	worldMap.islands.Eleuthera.locations.city1.position.ay = 1.5765;
	worldMap.islands.Eleuthera.locations.city1.modelName = "town";
	worldMap.islands.Eleuthera.locations.city1.visible = "false";
	worldMap.islands.Eleuthera.locations.city1.move = "false";
	//Label
	wdmSetIcon("Eleuthera", FindTownName("Eleuthera"), GetTownNation("Eleuthera")); // KK
	worldMap.islands.Eleuthera.locations.city1.label.visible = "false";
	// initial ship location
	worldMap.islands.Eleuthera.locations.city1.ship.pos.x = 138.3729;
	worldMap.islands.Eleuthera.locations.city1.ship.pos.z = -962.1888;
	//Name
	worldMap.islands.Eleuthera.locations.city2.name = "Alice";
	worldMap.islands.Eleuthera.locations.city2.real = "Alice";
	//Geometry parameters
	worldMap.islands.Eleuthera.locations.city2.position.x = 164.9797; 
	worldMap.islands.Eleuthera.locations.city2.position.y = 2.228; 
	worldMap.islands.Eleuthera.locations.city2.position.z = -934.5041; 
	worldMap.islands.Eleuthera.locations.city2.position.ay = 1.5765;
	worldMap.islands.Eleuthera.locations.city2.modelName = "town";
	worldMap.islands.Eleuthera.locations.city2.visible = "false";
	worldMap.islands.Eleuthera.locations.city2.move = "false";
	//Label
	wdmSetIcon("Alice", FindTownName("Alice"), GetTownNation("Alice")); // KK
	worldMap.islands.Eleuthera.locations.city2.label.visible = "false";
	// initial ship location
	worldMap.islands.Eleuthera.locations.city2.ship.pos.x = 171.5334;
	worldMap.islands.Eleuthera.locations.city2.ship.pos.z = -932.4945;
//JRH
	//Name
	worldMap.islands.Eleuthera.locations.city3.name = "EleutheraShore 1";
	//Geometry parameters
	worldMap.islands.Eleuthera.locations.city3.position.x = 1235.0;			//reload_4 coordinates
	worldMap.islands.Eleuthera.locations.city3.position.y = 2.0;			//?
	worldMap.islands.Eleuthera.locations.city3.position.z = -1622.0;		//reload_4 coordinates

	worldMap.islands.Eleuthera.locations.city3.position.ay = 0.0;
	worldMap.islands.Eleuthera.locations.city3.modelName = "leaf";
	worldMap.islands.Eleuthera.locations.city3.visible = "false";
	worldMap.islands.Eleuthera.locations.city3.move = "false";
	//Label
	worldMap.islands.Eleuthera.locations.city3.label.text = "Citadel Rock";
	worldMap.islands.Eleuthera.locations.city3.label.icon = -1;
	worldMap.islands.Eleuthera.locations.city3.label.visible = "false";
	// initial ship location
	worldMap.islands.Eleuthera.locations.city3.ship.pos.x = 1135.0; // KK		//ship_1 near reload_4
	worldMap.islands.Eleuthera.locations.city3.ship.pos.z = -1679.0; // KK		//ship_1 near reload_4

	//17=========================================================================
	//Name
	worldMap.islands.Aruba.name = "Aruba";
	//Geometry parameters
	worldMap.islands.Aruba.isVisibleName = 0;
	worldMap.islands.Aruba.position.x = -168.6169;
	worldMap.islands.Aruba.position.y = 30.0;
	worldMap.islands.Aruba.position.z = 550.3819;
	worldMap.islands.Aruba.position.rx = -169.8129;
	worldMap.islands.Aruba.position.rz = 565.5464;
	worldMap.islands.Aruba.radius = 85.0;
	worldMap.islands.Aruba.kradius = 0.75;
	//Island label
	worldMap.islands.Aruba.label.text = FindIslandName("Aruba");
	worldMap.islands.Aruba.label.icon = -1;
	worldMap.islands.Aruba.label.visible = "true";

	//City
	//Name
	if(GetCurrentPeriod() == PERIOD_EARLY_EXPLORERS)
	{
		worldMap.islands.Aruba.locations.city1.name = "ArubaShore2";
		worldMap.islands.Aruba.locations.city1.modelName = "leaf";

		worldMap.islands.Aruba.locations.city1.label.text = "Sandy Beach";
		worldMap.islands.Aruba.locations.city1.label.icon = -1;
	}
	else
	{
		worldMap.islands.Aruba.locations.city1.name = "Oranjestad";
		worldMap.islands.Aruba.locations.city1.real = "Oranjestad";

		worldMap.islands.Aruba.locations.city1.modelName = "town";
	}
	//Geometry parameters
	worldMap.islands.Aruba.locations.city1.position.x = -177.4276;
	worldMap.islands.Aruba.locations.city1.position.y = 3.9001;
	worldMap.islands.Aruba.locations.city1.position.z = 573.0608;
	worldMap.islands.Aruba.locations.city1.position.ay = 1.5765;
	worldMap.islands.Aruba.locations.city1.visible = "false";
	worldMap.islands.Aruba.locations.city1.move = "false";
	//Label
	wdmSetIcon("Oranjestad", FindTownName("Oranjestad"), GetTownNation("Oranjestad")); // KK
	worldMap.islands.Aruba.locations.city1.label.visible = "false";
	// initial ship location
	worldMap.islands.Aruba.locations.city1.ship.pos.x = -177.4276;
	worldMap.islands.Aruba.locations.city1.ship.pos.z = 579.3799;	
	//Name
	worldMap.islands.Aruba.locations.city2.name = "ArubaShore";
	//Geometry parameters
	worldMap.islands.Aruba.locations.city2.position.x = -136.3858;
	worldMap.islands.Aruba.locations.city2.position.y = 2.3877;
	worldMap.islands.Aruba.locations.city2.position.z = 588.7742;
	worldMap.islands.Aruba.locations.city2.position.ay = 0.0;
	worldMap.islands.Aruba.locations.city2.modelName = "leaf";
	worldMap.islands.Aruba.locations.city2.visible = "false";
	worldMap.islands.Aruba.locations.city2.move = "false";
	//Label
	worldMap.islands.Aruba.locations.city2.label.text = "Rocky Cove";
	worldMap.islands.Aruba.locations.city2.label.icon = -1;
	worldMap.islands.Aruba.locations.city2.label.visible = "false";
	// initial ship location
	worldMap.islands.Aruba.locations.city2.ship.pos.x = -135.1689;
	worldMap.islands.Aruba.locations.city2.ship.pos.z = 595.4637;
	
	//18=========================================================================
	//Name
	worldMap.islands.IslaMona.name = "IslaMona";
	//Geometry parameters
	worldMap.islands.IslaMona.isVisibleName = 0;	
	worldMap.islands.IslaMona.position.x = -288.5556;  // East  = +, West  = -
	worldMap.islands.IslaMona.position.y = 20.0;
	worldMap.islands.IslaMona.position.z = -235.5098;   // North = -, South = +
	worldMap.islands.IslaMona.position.rx = -314.0483; // What's this???
	worldMap.islands.IslaMona.position.rz = -201.129;  // What's this???
	worldMap.islands.IslaMona.radius = 40.0;
	worldMap.islands.IslaMona.kradius = 0.75;
	//Island label
	worldMap.islands.IslaMona.label.text = FindIslandName("Isla Mona");
	worldMap.islands.IslaMona.label.icon = -1;
	worldMap.islands.IslaMona.label.visible = "true";

	//City
	//Geometry parameters
	worldMap.islands.IslaMona.locations.city0.position.x = worldMap.islands.IslaMona.position.x;
	worldMap.islands.IslaMona.locations.city0.position.y = 0.691;
	worldMap.islands.IslaMona.locations.city0.position.z = worldMap.islands.IslaMona.position.z;
	worldMap.islands.IslaMona.locations.city0.position.ay = 0.0;
	worldMap.islands.IslaMona.locations.city0.modelName = "leaf";
	worldMap.islands.IslaMona.locations.city0.visible = "false";
	worldMap.islands.IslaMona.locations.city0.move = "false";

	//19=========================================================================	
	//Name
	worldMap.islands.Battle_Rocks.name = "Battle_Rocks";
	//Geometry parameters
	worldMap.islands.Battle_Rocks.isVisibleName = 0;
	worldMap.islands.Battle_Rocks.position.x = -806.0774;
	worldMap.islands.Battle_Rocks.position.y = 20.0;
	worldMap.islands.Battle_Rocks.position.z = 537.4297;
	worldMap.islands.Battle_Rocks.position.rx = -776.2158;
	worldMap.islands.Battle_Rocks.position.rz = 567.0417;
	worldMap.islands.Battle_Rocks.radius = 30.0;
	worldMap.islands.Battle_Rocks.kradius = 0.75;
	//Island label
	worldMap.islands.Battle_Rocks.label.text = FindIslandName("Petit Tabac"); // PB
	worldMap.islands.Battle_Rocks.label.icon = -1;
	worldMap.islands.Battle_Rocks.label.visible = "true";

	//Cities - way for adding new fake island-model into the WorldMap
	//Geometry parameters
	worldMap.islands.Battle_Rocks.locations.city0.position.x = worldMap.islands.Battle_Rocks.position.x;
	worldMap.islands.Battle_Rocks.locations.city0.position.y = 0.9333;
	worldMap.islands.Battle_Rocks.locations.city0.position.z = worldMap.islands.Battle_Rocks.position.z;
	worldMap.islands.Battle_Rocks.locations.city0.position.ay = 0.0;
	worldMap.islands.Battle_Rocks.locations.city0.modelName = "leaf";
	worldMap.islands.Battle_Rocks.locations.city0.visible = "false";
	worldMap.islands.Battle_Rocks.locations.city0.move = "false";

	//20=========================================================================		
	//Name
	worldMap.islands.Colombia.name = "Colombia";
	//Geometry parameters
	worldMap.islands.Columbia.isVisibleName = 0;	
	worldMap.islands.Colombia.position.x = -55.4972;
	worldMap.islands.Colombia.position.y = 30.0;
	worldMap.islands.Colombia.position.z = 801.376;
	worldMap.islands.Colombia.position.rx = -24.6888;
	worldMap.islands.Colombia.position.rz = 807.4202;
	worldMap.islands.Colombia.radius = 180.0;
	worldMap.islands.Colombia.kradius = 0.75;

	//Island label
	worldMap.islands.Colombia.label.text = FindIslandName("Colombia");
	worldMap.islands.Colombia.label.icon = -1;
	worldMap.islands.Colombia.label.visible = "true";

	//City
	worldMap.islands.Colombia.locations.city1.name = "Cartagena";
	worldMap.islands.Colombia.locations.city1.real = "Cartagena";	
	//Geometry parameters
	worldMap.islands.Colombia.locations.city1.position.x = -1.6267;
	worldMap.islands.Colombia.locations.city1.position.y = 2.0859;
	worldMap.islands.Colombia.locations.city1.position.z = 808.5257;
	worldMap.islands.Colombia.locations.city1.position.ay = 0.0;
	worldMap.islands.Colombia.locations.city1.modelName = "town";
	worldMap.islands.Colombia.locations.city1.visible = "false";
	worldMap.islands.Colombia.locations.city1.move = "false";
	//Label
	wdmSetIcon("Cartagena", FindTownName("Cartagena"), GetTownNation("Cartagena")); // KK
	worldMap.islands.Colombia.locations.city1.label.visible = "false";
	// initial ship location
	worldMap.islands.Colombia.locations.city1.ship.pos.x = 14.3628;
	worldMap.islands.Colombia.locations.city1.ship.pos.z = 794.5574;
	//Name
	worldMap.islands.Colombia.locations.city2.name = "Colombia_shore";
	//Geometry parameters
	worldMap.islands.Colombia.locations.city2.position.x = 46.0673;
	worldMap.islands.Colombia.locations.city2.position.y = 2.0859;
	worldMap.islands.Colombia.locations.city2.position.z = 769.6588;
	worldMap.islands.Colombia.locations.city2.position.ay = 0.0;
	worldMap.islands.Colombia.locations.city2.modelName = "leaf";
	worldMap.islands.Colombia.locations.city2.visible = "false";
	worldMap.islands.Colombia.locations.city2.move = "false";
	//Label
	worldMap.islands.Colombia.locations.city2.label.text = "Dolphin Sands";
	worldMap.islands.Colombia.locations.city2.label.icon = -1;
	worldMap.islands.Colombia.locations.city2.label.visible = "false";
	// initial ship location
	worldMap.islands.Colombia.locations.city2.ship.pos.x = 43.8198;
	worldMap.islands.Colombia.locations.city2.ship.pos.z = 762.9149;
	
	//=========================================================================
	//Internal information - !!!Beware, nor any checks!!!
	//=========================================================================
	//Player ship
	worldMap.playerShipX = 246.27;
	worldMap.playerShipZ = 775.34;
	worldMap.playerShipAY = 3.0;
	worldMap.playerShipActionRadius = 20.0;
	worldMap.playerShipDispX = stf(worldMap.playerShipX) - stf(worldMap.islands.Oxbay.position.rx);
	worldMap.playerShipDispZ = stf(worldMap.playerShipZ) - stf(worldMap.islands.Oxbay.position.rz);	
	//Camera
	worldMap.wdmCameraAY = 0.0;					//Rotation angle of the camera
	worldMap.wdmCameraY = 250.0;				//Camera Height
	//Enemy ship	
	worldMap.enemyshipViewDistMin = 60.0;		//Distance at which the ship starts to fade
	worldMap.enemyshipViewDistMax = 120.0;		//Distance at which the ship disappears completely
	worldMap.enemyshipDistKill = 140.0;			//Distance at which the kill vehicle
	worldMap.enemyshipBrnDistMin = 80.0;		//Minimum distance on the ship who give birth
	worldMap.enemyshipBrnDistMax = 130.0;		//The maximum distance at which the ship Rozsa
	//storm
	worldMap.stormViewDistMin = 90.0;			//Distance at which the storm begins to fade
	worldMap.stormViewDistMax = 180.0;			//Distance at which the storm disappears completely
	worldMap.stormDistKill = 190.0;				//Distance at which the killing storm
	worldMap.stormBrnDistMin = 100.0;			//The minimum distance at which the storm Rozsa
	worldMap.stormBrnDistMax = 140.0;			//The maximum distance at which the storm Rozsa
	worldMap.stormZone = 150.0;					//Overall range of storm

/*
	//Player ship
	worldMap.playerShipX = -1000.0;
	worldMap.playerShipZ = -300.0;
	worldMap.playerShipAy = 0.0;
	worldMap.playerShipActionRadius = 20.0;
	//Camera
	worldMap.wdmCameraAY = 30.0;				//Rotation angle of the camera
	worldMap.wdmCameraY = 230.0;				//Camera Height
	//Enemy ship	
	worldMap.enemyshipViewDistMin = 60.0;		//Distance at which the ship starts to fade
	worldMap.enemyshipViewDistMax = 120.0;		//Distance at which the ship disappears completely
	worldMap.enemyshipDistKill = 150.0;			//Distance at which the kill vehicle
	worldMap.enemyshipBrnDistMin = 80.0;		//Minimum distance on the ship who give birth
	worldMap.enemyshipBrnDistMax = 130.0;		//The maximum distance at which the ship Rozsa
	//storm
	worldMap.stormViewDistMin = 90.0;			//Distance at which the storm begins to fade
	worldMap.stormViewDistMax = 180.0;			//Distance at which the storm disappears completely
	worldMap.stormDistKill = 190.0;				//Distance at which the killing storm
	worldMap.stormBrnDistMin = 100.0;			//The minimum distance at which the storm Rozsa
	worldMap.stormBrnDistMax = 140.0;			//The maximum distance at which the storm Rozsa
	worldMap.stormZone = 120.0;					//Overall range of storm
	//============================================//

	//=========================================================================
	//Initialization labels
	//=========================================================================
//	InitializationLabels();
//	DeleteAttribute(&worldMap, "labeltype");
*/

}
