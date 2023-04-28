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

	//Start date
	worldMap.date.hour = CharHour;
	worldMap.date.min = CharMinute;
	worldMap.date.sec = CharSecond;
	worldMap.date.day = CharDay;
	worldMap.date.month = CharMonth;
	worldMap.date.year = CharYear;
	worldMap.date.hourPerSec = 1.5;

	//=========================================================================
	//Labels
	//=========================================================================
	//Icons description
	// 0----------->
	// 1-----------> frames
	// 2----------->
	// ...
	// icons
	//
	worldMap.icon.width = 32;
	worldMap.icon.height = 32;
	worldMap.icon.num = 16; // KK
	worldMap.icon.frames = 8;
	worldMap.icon.fps = 10;
	worldMap.icon.texture = "icons" + GetCurrentPeriod() + ".tga"; // KK
	//Label types description
	worldMap.labeltype.Island.icon = -1;				//Default icon
	worldMap.labeltype.Island.font = "INTERFACE_NORMAL";			//Default font
	worldMap.labeltype.Island.pivotX = -0.5;			//Default label shifting left-upper point by X (1 -> full width)
	worldMap.labeltype.Island.pivotY = -0.5;			//Default label shifting left-upper point by Y (1 -> full height)
	worldMap.labeltype.Island.heightView = 1000.0;		//Default camera height when hide this labels
	worldMap.labeltype.Island.weight = 100;				//Weight is use when shake intersection labels
	worldMap.labeltype.Town.icon = -1;
	worldMap.labeltype.Town.font = "INTERFACE_NORMAL";
	worldMap.labeltype.Town.pivotX = -0.5;
	worldMap.labeltype.Town.pivotY = -0.5;
	worldMap.labeltype.Town.heightView = 250.0;
	worldMap.labeltype.Town.weight = 50;
	worldMap.labeltype.Shore.icon = -1;
	worldMap.labeltype.Shore.font = "INTERFACE_NORMAL";
	worldMap.labeltype.Shore.pivotX = -0.5;
	worldMap.labeltype.Shore.pivotY = -0.5;
	worldMap.labeltype.Shore.heightView = 200.0;
	worldMap.labeltype.Shore.weight = 1;

	// ========================================================================
	// Islands
	// ========================================================================
	worldMap.labels.FalaiseDeFleur.type = "Island";
	worldMap.labels.FalaiseDeFleur.id = "FalaiseDeFleur";
	worldMap.labels.FalaiseDeFleur.locator = "FalaiseDeFleur";
	worldMap.labels.FalaiseDeFleur.text = FindIslandName("Falaise De Fleur");

	worldMap.labels.Redmond.type = "Island";
	worldMap.labels.Redmond.id = "Redmond";
	worldMap.labels.Redmond.locator = "Redmond";
	worldMap.labels.Redmond.text = FindIslandName("Redmond");

	worldMap.labels.Oxbay.type = "Island";
	worldMap.labels.Oxbay.id = "Oxbay";
	worldMap.labels.Oxbay.locator = "Oxbay";
	worldMap.labels.Oxbay.text = FindIslandName("Oxbay");

	worldMap.labels.Douwesen.type = "Island";
	worldMap.labels.Douwesen.id = "Douwesen";
	worldMap.labels.Douwesen.locator = "Douwesen";
	worldMap.labels.Douwesen.text = FindIslandName("Douwesen");

	worldMap.labels.Conceicao.type = "Island";
	worldMap.labels.Conceicao.id = "Conceicao";
	worldMap.labels.Conceicao.locator = "Conceicao";
	worldMap.labels.Conceicao.text = FindIslandName("Conceicao");

	worldMap.labels.IslaMuelle.type = "Island";
	worldMap.labels.IslaMuelle.id = "IslaMuelle";
	worldMap.labels.IslaMuelle.locator = "IslaMuelle";
	worldMap.labels.IslaMuelle.text = FindIslandName("Isla Muelle");

	worldMap.labels.QuebradasCostillas.type = "Island";
	worldMap.labels.QuebradasCostillas.id = "QuebradasCostillas";
	worldMap.labels.QuebradasCostillas.locator = "QuebradasCostillas";
	worldMap.labels.QuebradasCostillas.text = FindIslandName("QuebradasCostillas");

	worldMap.labels.KhaelRoa.type = "Island";
	worldMap.labels.KhaelRoa.id = "KhaelRoa";
	worldMap.labels.KhaelRoa.locator = "KhaelRoa";
	worldMap.labels.KhaelRoa.text = FindIslandName("Khael Roa");

	worldMap.labels.Cayman.type = "Island";
	worldMap.labels.Cayman.id = "Cayman";
	worldMap.labels.Cayman.locator = "Cayman";
	worldMap.labels.Cayman.text = FindIslandName("Cayman");

	worldMap.labels.Hispaniola.type = "Island";
	worldMap.labels.Hispaniola.id = "Hispaniola";
	worldMap.labels.Hispaniola.locator = "Hispaniola";
	worldMap.labels.Hispaniola.text = FindIslandName("Hispaniola");

	worldMap.labels.Cuba.type = "Island";
	worldMap.labels.Cuba.id = "Cuba";
	worldMap.labels.Cuba.locator = "Cuba";
	worldMap.labels.Cuba.text = FindIslandName("Cuba");

	worldMap.labels.Guadeloupe.type = "Island";
	worldMap.labels.Guadeloupe.id = "Guadeloupe";
	worldMap.labels.Guadeloupe.locator = "Guadeloupe";
	worldMap.labels.Guadeloupe.text = FindIslandName("Guadeloupe");

	worldMap.labels.SaintMartin.type = "Island";
	worldMap.labels.SaintMartin.id = "SaintMartin";
	worldMap.labels.SaintMartin.locator = "SaintMartin";
	worldMap.labels.SaintMartin.text = FindIslandName("Saint Martin");

	worldMap.labels.Antigua.type = "Island";
	worldMap.labels.Antigua.id = "Antigua";
	worldMap.labels.Antigua.locator = "Antigua";
	worldMap.labels.Antigua.text = FindIslandName("Antigua");

	worldMap.labels.Turks.type = "Island";
	worldMap.labels.Turks.id = "Turks";
	worldMap.labels.Turks.locator = "Turks";
	worldMap.labels.Turks.text = FindIslandName("Turks");

	worldMap.labels.Curacao.type = "Island";
	worldMap.labels.Curacao.id = "Curacao";
	worldMap.labels.Curacao.locator = "Curacao";
	worldMap.labels.Curacao.text = FindIslandName("Curacao");

	worldMap.labels.Eleuthera.type = "Island";
	worldMap.labels.Eleuthera.id = "Eleuthera";
	worldMap.labels.Eleuthera.locator = "Eleuthera";
	worldMap.labels.Eleuthera.text = FindIslandName("Eleuthera");

	worldMap.labels.Aruba.type = "Island";
	worldMap.labels.Aruba.id = "Aruba";
	worldMap.labels.Aruba.locator = "Aruba";
	worldMap.labels.Aruba.text = FindIslandName("Aruba");

	worldMap.labels.IslaMona.type = "Island";
	worldMap.labels.IslaMona.id = "IslaMona";
	worldMap.labels.IslaMona.locator = "IslaMona";
	worldMap.labels.IslaMona.text = FindIslandName("Isla Mona");

	worldMap.labels.Battle_Rocks.type = "Island";
	worldMap.labels.Battle_Rocks.id = "Battle_Rocks";
	worldMap.labels.Battle_Rocks.locator = "Battle_Rocks";
	worldMap.labels.Battle_Rocks.text = FindIslandName("Petit Tabac");

	worldMap.labels.Colombia.type = "Island";
	worldMap.labels.Colombia.id = "Colombia";
	worldMap.labels.Colombia.locator = "Colombia";
	worldMap.labels.Colombia.text = FindIslandName("Colombia");

	worldMap.labels.IslaDeMuerte.type = "Island";
	worldMap.labels.IslaDeMuerte.id = "IslaDeMuerte";
	worldMap.labels.IslaDeMuerte.locator = "IslaDeMuerte";
	worldMap.labels.IslaDeMuerte.text = TranslateString("","Isla De Muerte");

	//------- TOWN ------------------------------------------------------------

	worldMap.labels.FalaiseDeFleur_town_1.type = "Town";
	worldMap.labels.FalaiseDeFleur_town_1.id = "Falaise de Fleur";
	worldMap.labels.FalaiseDeFleur_town_1.locator = "FalaiseDeFleur_town";
	worldMap.labels.FalaiseDeFleur_town_1.text = FindTownName("Falaise de Fleur");
	worldMap.labels.FalaiseDeFleur_town_1.icon = GetTownNation("Falaise de Fleur");


	worldMap.labels.Redmond_town_1.type = "Town";
	worldMap.labels.Redmond_town_1.id = "Redmond";
	worldMap.labels.Redmond_town_1.locator = "Redmond_town";
	worldMap.labels.Redmond_town_1.text = FindTownName("Redmond");
	worldMap.labels.Redmond_town_1.icon = GetTownNation("Redmond");


	worldMap.labels.Oxbay_town_1.type = "Town";
	worldMap.labels.Oxbay_town_1.id = "Oxbay";
	worldMap.labels.Oxbay_town_1.locator = "Oxbay_town_1";
	worldMap.labels.Oxbay_town_1.text = FindTownName("Oxbay");
	worldMap.labels.Oxbay_town_1.icon = GetTownNation("Oxbay");

	worldMap.labels.Oxbay_town_2.type = "Town";
	worldMap.labels.Oxbay_town_2.id = "Greenford";
	worldMap.labels.Oxbay_town_2.locator = "Oxbay_town_2";
	worldMap.labels.Oxbay_town_2.text = FindTownName("Greenford");
	worldMap.labels.Oxbay_town_2.icon = GetTownNation("Greenford");


	worldMap.labels.Douwesen_town_1.type = "Town";
	worldMap.labels.Douwesen_town_1.id = "Douwesen";
	worldMap.labels.Douwesen_town_1.locator = "Douwesen_town_1";
	worldMap.labels.Douwesen_town_1.text = FindTownName("Douwesen");
	worldMap.labels.Douwesen_town_1.icon = GetTownNation("Douwesen");


	worldMap.labels.Conceicao_town_1.type = "Town";
	worldMap.labels.Conceicao_town_1.id = "Conceicao";
	worldMap.labels.Conceicao_town_1.locator = "Conceicao_town_1";
	worldMap.labels.Conceicao_town_1.text = FindTownName("Conceicao");
	worldMap.labels.Conceicao_town_1.icon = GetTownNation("Conceicao");


	worldMap.labels.IslaMuelle_town_1.type = "Town";
	worldMap.labels.IslaMuelle_town_1.id = "Isla Muelle";
	worldMap.labels.IslaMuelle_town_1.locator = "IslaMuelle_town_1";
	worldMap.labels.IslaMuelle_town_1.text = FindTownName("Isla Muelle");
	worldMap.labels.IslaMuelle_town_1.icon = GetTownNation("Isla Muelle");


	worldMap.labels.QuebradasCostillas_town_1.type = "Town";
	worldMap.labels.QuebradasCostillas_town_1.id = "Charlestown";
	worldMap.labels.QuebradasCostillas_town_1.locator = "QuebradasCostillas_town_1";
	worldMap.labels.QuebradasCostillas_town_1.text = FindTownName("Charlestown");
	worldMap.labels.QuebradasCostillas_town_1.icon = GetTownNation("Charlestown");

	worldMap.labels.QuebradasCostillas_town_2.type = "Town";
	worldMap.labels.QuebradasCostillas_town_2.id = "QuebradasCostillas_town_2";
	worldMap.labels.QuebradasCostillas_town_2.locator = "QuebradasCostillas_town_2";
	worldMap.labels.QuebradasCostillas_town_2.text = FindTownName("Quebradas Costillas");
	worldMap.labels.QuebradasCostillas_town_2.icon = GetTownNation("Quebradas Costillas");


	worldMap.labels.KhaelRoa_town_1.type = "Town";
	worldMap.labels.KhaelRoa_town_1.id = "Khael Roa";
	worldMap.labels.KhaelRoa_town_1.locator = "KhaelRoa_town_1";
	worldMap.labels.KhaelRoa_town_1.text = FindTownName("Khael Roa");
	worldMap.labels.KhaelRoa_town_1.icon = GetTownNation("Khael Roa");


	worldMap.labels.Cayman_town_1.type = "Town";
	worldMap.labels.Cayman_town_1.id = "Grand Cayman";
	worldMap.labels.Cayman_town_1.locator = "Cayman_town_1";
	worldMap.labels.Cayman_town_1.text = FindTownName("Grand Cayman");
	worldMap.labels.Cayman_town_1.icon = GetTownNation("Grand Cayman");


	worldMap.labels.Hispaniola_town_1.type = "Town";
	worldMap.labels.Hispaniola_town_1.id = "Port au Prince";
	worldMap.labels.Hispaniola_town_1.locator = "Hispaniola_town_1";
	worldMap.labels.Hispaniola_town_1.text = FindTownName("Port au Prince");
	worldMap.labels.Hispaniola_town_1.icon = GetTownNation("Port au Prince");

	worldMap.labels.Hispaniola_town_2.type = "Town";
	worldMap.labels.Hispaniola_town_2.id = "Santo Domingo";
	worldMap.labels.Hispaniola_town_2.locator = "Hispaniola_town_2";
	worldMap.labels.Hispaniola_town_2.text = FindTownName("Santo Domingo");
	worldMap.labels.Hispaniola_town_2.icon = GetTownNation("Santo Domingo");

	worldMap.labels.Hispaniola_town_3.type = "Town";
	worldMap.labels.Hispaniola_town_3.id = "Tortuga";
	worldMap.labels.Hispaniola_town_3.locator = "Hispaniola_town_3";
	worldMap.labels.Hispaniola_town_3.text = FindTownName("Tortuga");
	worldMap.labels.Hispaniola_town_3.icon = GetTownNation("Tortuga");


	worldMap.labels.Cuba_town_1.type = "Town";
	worldMap.labels.Cuba_town_1.id = "Havana";
	worldMap.labels.Cuba_town_1.locator = "Cuba_town_1";
	worldMap.labels.Cuba_town_1.text = FindTownName("Havana");
	worldMap.labels.Cuba_town_1.icon = GetTownNation("Havana");

	worldMap.labels.Cuba_town_2.type = "Town";
	worldMap.labels.Cuba_town_2.id = "Santiago";
	worldMap.labels.Cuba_town_2.locator = "Cuba_town_2";
	worldMap.labels.Cuba_town_2.text = FindTownName("Santiago");
	worldMap.labels.Cuba_town_2.icon = GetTownNation("Santiago");


	worldMap.labels.Guadeloupe_town_1.id = "Pointe a Pitre";
	worldMap.labels.Guadeloupe_town_1.locator = "Guadeloupe_town_1";
	if(GetCurrentPeriod() == PERIOD_EARLY_EXPLORERS) {
		worldMap.labels.Guadeloupe_town_1.type = "Shore";
		worldMap.labels.Guadeloupe_town_1.text = "Bahía Grande";
	}
	else {
		worldMap.labels.Guadeloupe_town_1.type = "Town";
		worldMap.labels.Guadeloupe_town_1.text = FindTownName("Pointe a Pitre");
		worldMap.labels.Guadeloupe_town_1.icon = GetTownNation("Pointe a Pitre");
	}


	worldMap.labels.SaintMartin_town_1.type = "Town";
	worldMap.labels.SaintMartin_town_1.id = "Philipsburg";
	worldMap.labels.SaintMartin_town_1.locator = "SaintMartin_town_1";
	worldMap.labels.SaintMartin_town_1.text = FindTownName("Philipsburg");
	worldMap.labels.SaintMartin_town_1.icon = GetTownNation("Philipsburg");

	worldMap.labels.SaintMartin_town_2.type = "Town";
	worldMap.labels.SaintMartin_town_2.id = "Marigot";
	worldMap.labels.SaintMartin_town_2.locator = "SaintMartin_town_2";
	worldMap.labels.SaintMartin_town_2.text = FindTownName("Marigot");
	worldMap.labels.SaintMartin_town_2.icon = GetTownNation("Marigot");


	worldMap.labels.Antigua_town_1.type = "Town";
	worldMap.labels.Antigua_town_1.id = "St John's";
	worldMap.labels.Antigua_town_1.locator = "Antigua_town_1";
	worldMap.labels.Antigua_town_1.text = FindTownName("St John's");
	worldMap.labels.Antigua_town_1.icon = GetTownNation("St John's");


	worldMap.labels.Turks_town_1.type = "Town";
	worldMap.labels.Turks_town_1.id = "Grand Turk";
	worldMap.labels.Turks_town_1.locator = "Turks_town_1";
	worldMap.labels.Turks_town_1.text = FindTownName("Grand Turk");
	worldMap.labels.Turks_town_1.icon = GetTownNation("Grand Turk");


	worldMap.labels.Curacao_town_1.type = "Town";
	worldMap.labels.Curacao_town_1.id = "Willemstad";
	worldMap.labels.Curacao_town_1.locator = "Curacao_town_1";
	worldMap.labels.Curacao_town_1.text = FindTownName("Willemstad");
	worldMap.labels.Curacao_town_1.icon = GetTownNation("Willemstad");


	worldMap.labels.Eleuthera_town_1.type = "Town";
	worldMap.labels.Eleuthera_town_1.id = "Eleuthera";
	worldMap.labels.Eleuthera_town_1.locator = "Eleuthera_town_1";
	worldMap.labels.Eleuthera_town_1.text = FindTownName("Eleuthera");
	worldMap.labels.Eleuthera_town_1.icon = GetTownNation("Eleuthera");

	worldMap.labels.Eleuthera_town_2.type = "Town";
	worldMap.labels.Eleuthera_town_2.id = "Alice";
	worldMap.labels.Eleuthera_town_2.locator = "Eleuthera_town_2";
	worldMap.labels.Eleuthera_town_2.text = FindTownName("Alice");
	worldMap.labels.Eleuthera_town_2.icon = GetTownNation("Alice");


	worldMap.labels.Aruba_town_1.id = "Oranjestad";
	worldMap.labels.Aruba_town_1.locator = "Aruba_town_1";
	if(GetCurrentPeriod() == PERIOD_EARLY_EXPLORERS) {
		worldMap.labels.Aruba_town_1.type = "Shore";
		worldMap.labels.Aruba_town_1.text = "Sandy Beach";
	}
	else {
		worldMap.labels.Aruba_town_1.type = "Town";
		worldMap.labels.Aruba_town_1.text = FindTownName("Oranjestad");
		worldMap.labels.Aruba_town_1.icon = GetTownNation("Oranjestad");
	}


	worldMap.labels.Colombia_town_1.type = "Town";
	worldMap.labels.Colombia_town_1.id = "Cartagena";
	worldMap.labels.Colombia_town_1.locator = "Colombia_town_1";
	worldMap.labels.Colombia_town_1.text = FindTownName("Cartagena");
	worldMap.labels.Colombia_town_1.icon = GetTownNation("Cartagena");

	//------- SHORE -----------------------------------------------------------

	worldMap.labels.FalaiseDeFleur_shore_1.type = "Shore";
	worldMap.labels.FalaiseDeFleur_shore_1.id = "FalaiseDeFleur_shore";
	worldMap.labels.FalaiseDeFleur_shore_1.locator = "FalaiseDeFleur_shore";
	worldMap.labels.FalaiseDeFleur_shore_1.text = "Octopus Bay";


	worldMap.labels.Redmond_shore_1.type = "Shore";
	worldMap.labels.Redmond_shore_1.id = "Redmond_shore_1";
	worldMap.labels.Redmond_shore_1.locator = "Redmond_shore_1";
	if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0)
	{
		worldMap.labels.Redmond_shore_1.text = "Woodes Rogers' Port";
	}
	else
	{
		worldMap.labels.Redmond_shore_1.text = "Devil's Throat";
	}

	worldMap.labels.Redmond_shore_2.type = "Shore";
	worldMap.labels.Redmond_shore_2.id = "Redmond_shore_2";
	worldMap.labels.Redmond_shore_2.locator = "Redmond_shore_2";
	if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0)
	{
		worldMap.labels.Redmond_shore_2.text = "Cave Shore";
	}
	else
	{
		worldMap.labels.Redmond_shore_2.text = "Rocky Shore";
	}


	worldMap.labels.Oxbay_shore_1.type = "Shore";
	worldMap.labels.Oxbay_shore_1.id = "Oxbay_shore_1";
	worldMap.labels.Oxbay_shore_1.locator = "Oxbay_shore_1";
	worldMap.labels.Oxbay_shore_1.text = "Gray Rock Bay";

	worldMap.labels.Oxbay_shore_2.type = "Shore";
	worldMap.labels.Oxbay_shore_2.id = "Oxbay_shore_2";
	worldMap.labels.Oxbay_shore_2.locator = "Oxbay_shore_2";
	worldMap.labels.Oxbay_shore_2.text = "Far Beach";

	worldMap.labels.Oxbay_shore_3.type = "Shore";
	worldMap.labels.Oxbay_shore_3.id = "Oxbay_shore_3";
	worldMap.labels.Oxbay_shore_3.locator = "Oxbay_shore_3";
	worldMap.labels.Oxbay_shore_3.text = "Lighthouse";


	worldMap.labels.Douwesen_shore_1.type = "Shore";
	worldMap.labels.Douwesen_shore_1.id = "Douwesen_shore_1";
	worldMap.labels.Douwesen_shore_1.locator = "Douwesen_shore_1";
	worldMap.labels.Douwesen_shore_1.text = "Palm Beach";

	worldMap.labels.Douwesen_shore_2.type = "Shore";
	worldMap.labels.Douwesen_shore_2.id = "Douwesen_shore_2";
	worldMap.labels.Douwesen_shore_2.locator = "Douwesen_shore_2";
	worldMap.labels.Douwesen_shore_2.text = "Crab Cliffs";


	worldMap.labels.Conceicao_shore_1.type = "Shore";
	worldMap.labels.Conceicao_shore_1.id = "Conceicao_shore_1";
	worldMap.labels.Conceicao_shore_1.locator = "Conceicao_shore_1";
	worldMap.labels.Conceicao_shore_1.text = "Sunny Haven";

	worldMap.labels.Conceicao_shore_2.type = "Shore";
	worldMap.labels.Conceicao_shore_2.id = "Conceicao_shore_2";
	worldMap.labels.Conceicao_shore_2.locator = "Conceicao_shore_2";
	worldMap.labels.Conceicao_shore_2.text = "Leviathan Rock";


	worldMap.labels.IslaMuelle_shore_1.type = "Shore";
	worldMap.labels.IslaMuelle_shore_1.id = "IslaMuelle_shore_1";
	worldMap.labels.IslaMuelle_shore_1.locator = "IslaMuelle_shore_1";
	worldMap.labels.IslaMuelle_shore_1.text = "Oyster Beach";

	worldMap.labels.IslaMuelle_shore_2.type = "Shore";
	worldMap.labels.IslaMuelle_shore_2.id = "IslaMuelle_shore_2";
	worldMap.labels.IslaMuelle_shore_2.locator = "IslaMuelle_shore_2";
	worldMap.labels.IslaMuelle_shore_2.text = "Hidden Coast";


	worldMap.labels.QuebradasCostillas_shore_1.type = "Shore";
	worldMap.labels.QuebradasCostillas_shore_1.id = "QuebradasCostillas_shore_1";
	worldMap.labels.QuebradasCostillas_shore_1.locator = "QuebradasCostillas_shore_1";
	worldMap.labels.QuebradasCostillas_shore_1.text = "White Bay";


	worldMap.labels.Cayman_shore_1.type = "Shore";
	worldMap.labels.Cayman_shore_1.id = "Cayman_shore_1";
	worldMap.labels.Cayman_shore_1.locator = "Cayman_shore_1";
	worldMap.labels.Cayman_shore_1.text = "Eden Rock";

	worldMap.labels.Cayman_shore_2.type = "Shore";
	worldMap.labels.Cayman_shore_2.id = "Cayman_shore_2";
	worldMap.labels.Cayman_shore_2.locator = "Cayman_shore_2";
	worldMap.labels.Cayman_shore_2.text = "Cayman Kai";

	worldMap.labels.Cayman_shore_3.type = "Shore";
	worldMap.labels.Cayman_shore_3.id = "Cayman_shore_3";
	worldMap.labels.Cayman_shore_3.locator = "Cayman_shore_3";
	worldMap.labels.Cayman_shore_3.text = "Sand Bluff";


	worldMap.labels.Hispaniola_shore_1.type = "Shore";
	worldMap.labels.Hispaniola_shore_1.id = "Hispaniola_shore_1";
	worldMap.labels.Hispaniola_shore_1.locator = "Hispaniola_shore_1";
	worldMap.labels.Hispaniola_shore_1.text = "Boca de Yuman";

	worldMap.labels.Hispaniola_shore_2.type = "Shore";
	worldMap.labels.Hispaniola_shore_2.id = "Hispaniola_shore_2";
	worldMap.labels.Hispaniola_shore_2.locator = "Hispaniola_shore_2";
	worldMap.labels.Hispaniola_shore_2.text = "Boca de Hubon";

	worldMap.labels.Hispaniola_shore_3.type = "Shore";
	worldMap.labels.Hispaniola_shore_3.id = "Hispaniola_shore_3";
	worldMap.labels.Hispaniola_shore_3.locator = "Hispaniola_shore_3";
	worldMap.labels.Hispaniola_shore_3.text = "Cape Francos";

	worldMap.labels.Hispaniola_shore_4.type = "Shore";
	worldMap.labels.Hispaniola_shore_4.id = "Hispaniola_shore_4";
	worldMap.labels.Hispaniola_shore_4.locator = "Hispaniola_shore_4";
	worldMap.labels.Hispaniola_shore_4.text = "Ile a Vache";


	worldMap.labels.Cuba_shore_1.type = "Shore";
	worldMap.labels.Cuba_shore_1.id = "Cuba_shore_1";
	worldMap.labels.Cuba_shore_1.locator = "Cuba_shore_1";
	worldMap.labels.Cuba_shore_1.text = "Bahia de San Antonio";

	worldMap.labels.Cuba_shore_2.type = "Shore";
	worldMap.labels.Cuba_shore_2.id = "Cuba_shore_2";
	worldMap.labels.Cuba_shore_2.locator = "Cuba_shore_2";
	worldMap.labels.Cuba_shore_2.text = "Bahia de Moa";

	worldMap.labels.Cuba_shore_3.type = "Shore";
	worldMap.labels.Cuba_shore_3.id = "Cuba_shore_3";
	worldMap.labels.Cuba_shore_3.locator = "Cuba_shore_3";
	worldMap.labels.Cuba_shore_3.text = "Punta de Maisi";

	worldMap.labels.Cuba_shore_4.type = "Shore";
	worldMap.labels.Cuba_shore_4.id = "Cuba_shore_4";
	worldMap.labels.Cuba_shore_4.locator = "Cuba_shore_4";
	worldMap.labels.Cuba_shore_4.text = "Playa de Sabana";

	worldMap.labels.Cuba_shore_5.type = "Shore";
	worldMap.labels.Cuba_shore_5.id = "Cuba_shore_5";
	worldMap.labels.Cuba_shore_5.locator = "Cuba_shore_5";
	worldMap.labels.Cuba_shore_5.text = "Playa de Sierra Maestra";

	worldMap.labels.Cuba_shore_6.type = "Shore";
	worldMap.labels.Cuba_shore_6.id = "Cuba_shore_6";
	worldMap.labels.Cuba_shore_6.locator = "Cuba_shore_6";
	worldMap.labels.Cuba_shore_6.text = "Peninsula de Zapata";


	worldMap.labels.Guadeloupe_shore_1.type = "Shore";
	worldMap.labels.Guadeloupe_shore_1.id = "Guadeloupe_shore_1";
	worldMap.labels.Guadeloupe_shore_1.locator = "Guadeloupe_shore_1";
	if(GetCurrentPeriod() == PERIOD_EARLY_EXPLORERS) {
		worldMap.labels.Guadeloupe_shore_1.text = "Ensenada del Bosque Quebrado";
	}
	else {
		worldMap.labels.Guadeloupe_shore_1.text = "Anse Casse-Bois";
	}


	worldMap.labels.SaintMartin_shore_1.type = "Shore";
	worldMap.labels.SaintMartin_shore_1.id = "SaintMartin_shore_1";
	worldMap.labels.SaintMartin_shore_1.locator = "SaintMartin_shore_1";
	worldMap.labels.SaintMartin_shore_1.text = "Simpson Bay";

	worldMap.labels.SaintMartin_shore_2.type = "Shore";
	worldMap.labels.SaintMartin_shore_2.id = "SaintMartin_shore_2";
	worldMap.labels.SaintMartin_shore_2.locator = "SaintMartin_shore_2";
	worldMap.labels.SaintMartin_shore_2.text = "Baie Orient";


	worldMap.labels.Antigua_shore_1.type = "Shore";
	worldMap.labels.Antigua_shore_1.id = "Antigua_shore_1";
	worldMap.labels.Antigua_shore_1.locator = "Antigua_shore_1";
	worldMap.labels.Antigua_shore_1.text = "Muscetto Cove";


	worldMap.labels.Turks_shore_1.type = "Shore";
	worldMap.labels.Turks_shore_1.id = "Turks_shore_1";
	worldMap.labels.Turks_shore_1.locator = "Turks_shore_1";
	worldMap.labels.Turks_shore_1.text = "White Reefs";

	worldMap.labels.Turks_shore_2.type = "Shore";
	worldMap.labels.Turks_shore_2.id = "Turks_shore_2";
	worldMap.labels.Turks_shore_2.locator = "Turks_shore_2";
	worldMap.labels.Turks_shore_2.text = "Sandy Point";

	worldMap.labels.Turks_shore_3.type = "Shore";
	worldMap.labels.Turks_shore_3.id = "Turks_shore_3";
	worldMap.labels.Turks_shore_3.locator = "Turks_shore_3";
	worldMap.labels.Turks_shore_3.text = "Birds Cove";

	worldMap.labels.Turks_shore_4.type = "Shore";
	worldMap.labels.Turks_shore_4.id = "Turks_shore_4";
	worldMap.labels.Turks_shore_4.locator = "Turks_shore_4";
	worldMap.labels.Turks_shore_4.text = "Old Lighthouse";


	worldMap.labels.Curacao_shore_1.type = "Shore";
	worldMap.labels.Curacao_shore_1.id = "Curacao_shore_1";
	worldMap.labels.Curacao_shore_1.locator = "Curacao_shore_1";
	worldMap.labels.Curacao_shore_1.text = "Bullen Bay";

	worldMap.labels.Curacao_shore_2.type = "Shore";
	worldMap.labels.Curacao_shore_2.id = "Curacao_shore_2";
	worldMap.labels.Curacao_shore_2.locator = "Curacao_shore_2";
	worldMap.labels.Curacao_shore_2.text = "Bocht Van Hato";


	worldMap.labels.Eleuthera_shore_1.type = "Shore";
	worldMap.labels.Eleuthera_shore_1.id = "Eleuthera_shore_1";
	worldMap.labels.Eleuthera_shore_1.locator = "Eleuthera_shore_1";
	worldMap.labels.Eleuthera_shore_1.text = "Citadel Rock";


	worldMap.labels.Aruba_shore_1.type = "Shore";
	worldMap.labels.Aruba_shore_1.id = "Aruba_shore_1";
	worldMap.labels.Aruba_shore_1.locator = "Aruba_shore_1";
	worldMap.labels.Aruba_shore_1.text = "Rocky Cove";


	worldMap.labels.Colombia_shore_1.type = "Shore";
	worldMap.labels.Colombia_shore_1.id = "Colombia_shore_1";
	worldMap.labels.Colombia_shore_1.locator = "Colombia_shore_1";
	worldMap.labels.Colombia_shore_1.text = "Dolphin Sands";

	//=========================================================================
	//Internal information - !!!Caution, no checks!!!
	//=========================================================================
	//Прараметры влияния ветра на скорость коробля (относительная скорость)
	worldMap.shipSpeedOppositeWind = 0.3;
	worldMap.shipSpeedOverWind = 0.8;

	//Player ship
	worldMap.playerShipActionRadius = 20.0;
	worldMap.playerShipX = 246.27;
	worldMap.playerShipZ = 775.34;
	worldMap.playerShipAy = 3.0;
	//Camera
	worldMap.wdmCameraAY = 0.0;					// Rotation angle of the camera
	worldMap.wdmCameraY = 250.0;				// Camera Height
	worldMap.wdmCameraRotLock = 0;				// Lock camera rotation
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

	//=========================================================================
	//Storm interface
	//=========================================================================
	worldMap.storm.num = 0;
	worldMap.storm.cur = 0;
	worldMap.storm.x = 0;
	worldMap.storm.z = 0;
	worldMap.storm.time = 0;
	worldMap.playerInStorm = 0;
	worldMap.stormWhithTornado = 0;

	//=========================================================================
	//Encounter interface
	//=========================================================================
	worldMap.encounter.num = 0;
	worldMap.encounter.cur = 0;
	worldMap.encounter.x = 0;
	worldMap.encounter.z = 0;
	worldMap.encounter.ay = 0;
	worldMap.encounter.time = 0;
	worldMap.encounter.type = -1;
	worldMap.encounter.attack = -1;
	worldMap.encounter.id = "";
	//=========================================================================
	worldMap.fontIslands = "SEADOGS";//"DIALOG21";
	worldMap.fontLocations = "SEADOGS_SMALL";//"normal";
	worldMap.labelPivotX = 0.5;
	worldMap.labelPivotY = 1.5;
	worldMap.heightViewLabel = 250.0;
	//=========================================================================
	worldMap.eventWindow.font.header = "normal";
	worldMap.eventWindow.font.text = "normal";
	worldMap.eventWindow.font.button = "normal";
	//=========================================================================

	//=========================================================================
	//System, NOT FOR EDIT!!!
	//=========================================================================
	DeleteAttribute(&worldMap, "encounters");
	DeleteAttribute(&worldMap, "addQuestEncounters");
	worldMap.encounters = "";
	worldMap.addQuestEncounters = "";

	//=========================================================================
	//Current island
	//=========================================================================
	worldMap.island = WDM_NONE_ISLAND;
	worldMap.island.x = 0;
	worldMap.island.z = 0;
	worldMap.zeroX = 0;
	worldMap.zeroZ = 0;

	//=========================================================================
	//Wind (read only)
	//=========================================================================
	worldMap.WindX = 0.0; // Normalized Direction
	worldMap.WindZ = 1.0; // Wind
	worldMap.WindF = 0.5; // Normalized wind force 0..1

	//=========================================================================
	//Old internal GUI params
	//=========================================================================
	worldMap.eventWindow.font.header = "normal";
	worldMap.eventWindow.font.text = "normal";
	worldMap.eventWindow.font.button = "normal";
	worldMap.date.font = "normal";

	//=========================================================================
	//Initialization labels
	//=========================================================================
	InitializationLabels();
	DeleteAttribute(&worldMap, "labeltype");


	//==========================================================================
	// coordinates for the start of the game, cities on a paper map and teleports


	worldMap.islands.FalaiseDeFleur.name = "FalaiseDeFleur";
	worldMap.islands.FalaiseDeFleur.position.x = -746.6099;
	// worldMap.islands.FalaiseDeFleur.position.y = 30.0;
	worldMap.islands.FalaiseDeFleur.position.z = 234.9465;
	worldMap.islands.FalaiseDeFleur.position.rx = -730.7285;
	worldMap.islands.FalaiseDeFleur.position.rz = 246.8357;
	// worldMap.islands.FalaiseDeFleur.radius = 110.0;
	// worldMap.islands.FalaiseDeFleur.kradius = 0.75;

	worldMap.islands.Redmond.name = "Redmond";
	worldMap.islands.Redmond.position.x = 300.9059;
	worldMap.islands.Redmond.position.z = -188.6696;
	worldMap.islands.Redmond.position.rx = 312.9202;
	worldMap.islands.Redmond.position.rz = -174.4065;

	worldMap.islands.Oxbay.name = "Oxbay";
	worldMap.islands.Oxbay.position.x = -915.4337;
	worldMap.islands.Oxbay.position.z = 415.2678;
	worldMap.islands.Oxbay.position.rx = -876.6284;
	worldMap.islands.Oxbay.position.rz = 409.4471;

	worldMap.islands.Douwesen.name = "Douwesen";
	worldMap.islands.Douwesen.position.x = -503.5165;
	worldMap.islands.Douwesen.position.z = 685.5855;
	worldMap.islands.Douwesen.position.rx = -471.2567;
	worldMap.islands.Douwesen.position.rz = 674.4498;

	worldMap.islands.Conceicao.name = "Conceicao";
	worldMap.islands.Conceicao.position.x = -780.4724;
	worldMap.islands.Conceicao.position.z = 663.7298;
	worldMap.islands.Conceicao.position.rx = -707.8312;
	worldMap.islands.Conceicao.position.rz = 673.5406;

	worldMap.islands.IslaMuelle.name = "IslaMuelle";
	worldMap.islands.IslaMuelle.position.x = -451.9622;
	worldMap.islands.IslaMuelle.position.z = -314.4281;
	worldMap.islands.IslaMuelle.position.rx = -519.2072;
	worldMap.islands.IslaMuelle.position.rz = -323.7959;

	worldMap.islands.QuebradasCostillas.name = "QuebradasCostillas";
	worldMap.islands.QuebradasCostillas.position.x = -662.419;
	worldMap.islands.QuebradasCostillas.position.z = -201.8127;
	worldMap.islands.QuebradasCostillas.position.rx = -641.6077;
	worldMap.islands.QuebradasCostillas.position.rz = -168.2621;

	worldMap.islands.KhaelRoa.name = "KhaelRoa";
	worldMap.islands.KhaelRoa.position.x = 801.3779;
	worldMap.islands.KhaelRoa.position.z = -445.5364;
	worldMap.islands.KhaelRoa.position.rx = 805.0779;
	worldMap.islands.KhaelRoa.position.rz = -437.1364;

	worldMap.islands.Cayman.name = "Cayman";
	worldMap.islands.Cayman.position.x = 600.5008;
	worldMap.islands.Cayman.position.z = -266.3481;
	worldMap.islands.Cayman.position.rx = 594.8008;
	worldMap.islands.Cayman.position.rz = -254.6481;

	worldMap.islands.Hispaniola.name = "Hispaniola";
	worldMap.islands.Hispaniola.position.x = -63.4097;
	worldMap.islands.Hispaniola.position.z = -455.923;
	worldMap.islands.Hispaniola.position.rx = -73.0069;
	worldMap.islands.Hispaniola.position.rz = -444.6382;

	worldMap.islands.Cuba.name = "Cuba";
	worldMap.islands.Cuba.position.x = 458.8936;
	worldMap.islands.Cuba.position.z = -684.1776;
	worldMap.islands.Cuba.position.rx = 469.0741;
	worldMap.islands.Cuba.position.rz = -724.3237;

	worldMap.islands.Guadeloupe.name = "Guadeloupe";
	worldMap.islands.Guadeloupe.position.x = -720.2772;
	worldMap.islands.Guadeloupe.position.z = 13.939;
	worldMap.islands.Guadeloupe.position.rx = -740.3181;
	worldMap.islands.Guadeloupe.position.rz = 19.6724;

	worldMap.islands.SaintMartin.name = "SaintMartin";
	worldMap.islands.SaintMartin.position.x = -725.3333;
	worldMap.islands.SaintMartin.position.z = -366.6779;
	worldMap.islands.SaintMartin.position.rx = -722.6486;
	worldMap.islands.SaintMartin.position.rz = -368.5712;

	worldMap.islands.Antigua.name = "Antigua";
	worldMap.islands.Antigua.position.x = -907.983;
	worldMap.islands.Antigua.position.z = -236.7188;
	worldMap.islands.Antigua.position.rx = -905.6271;
	worldMap.islands.Antigua.position.rz = -239.7206;

	worldMap.islands.Turks.name = "Turks";
	worldMap.islands.Turks.position.x = -144.7866;
	worldMap.islands.Turks.position.z = -819.767;
	worldMap.islands.Turks.position.rx = -129.5201;
	worldMap.islands.Turks.position.rz = -812.7909;

	worldMap.islands.Curacao.name = "Curacao";
	worldMap.islands.Curacao.position.x = -341.0551;
	worldMap.islands.Curacao.position.z = 608.5984;
	worldMap.islands.Curacao.position.rx = -323.7226;
	worldMap.islands.Curacao.position.rz = 636.0241;

	worldMap.islands.Eleuthera.name = "Eleuthera";
	worldMap.islands.Eleuthera.position.x = 133.2902;
	worldMap.islands.Eleuthera.position.z = -950.2642;
	worldMap.islands.Eleuthera.position.rx = 164.3902;
	worldMap.islands.Eleuthera.position.rz = -977.6642;

	worldMap.islands.Aruba.name = "Aruba";
	worldMap.islands.Aruba.position.x = -168.6169;
	worldMap.islands.Aruba.position.z = 550.3819;
	worldMap.islands.Aruba.position.rx = -169.8129;
	worldMap.islands.Aruba.position.rz = 565.5464;

	worldMap.islands.IslaMona.name = "IslaMona";
	worldMap.islands.IslaMona.position.x = -288.5556;
	worldMap.islands.IslaMona.position.z = -235.5098;
	worldMap.islands.IslaMona.position.rx = -314.0483;
	worldMap.islands.IslaMona.position.rz = -201.129;

	worldMap.islands.Colombia.name = "Colombia";
	worldMap.islands.Colombia.position.x = -55.4972;
	worldMap.islands.Colombia.position.z = 801.376;
	worldMap.islands.Colombia.position.rx = -24.6888;
	worldMap.islands.Colombia.position.rz = 807.4202;

	worldMap.islands.IslaDeMuerte.name = "IslaDeMuerte";
	worldMap.islands.IslaDeMuerte.position.x = 386.499;
	worldMap.islands.IslaDeMuerte.position.z = 425.603;
	worldMap.islands.IslaDeMuerte.position.rx = 375.139;
	worldMap.islands.IslaDeMuerte.position.rz = 418.814;
}

void InitializationLabels()
{
	// Let's go over all the islands
	aref arrayLabels;
	makearef(arrayLabels, worldMap.labels);
	int num = GetAttributesNum(arrayLabels);
	for(int i = 0; i < num; i++)
	{
		// Link to label description
		aref label = GetAttributeN(arrayLabels, i);
		//
		if(!CheckAttribute(label, "type")) continue;
		string typeName = label.type;
		// Get the label type
		aref typeParams;
		makearef(typeParams, worldMap.labeltype.(typeName));
		// Iterate over the label type parameters and add to the label
		int numParams = GetAttributesNum(typeParams);
		for(int j = 0; j < numParams; j++)
		{
			// Parameter name
			string param = GetAttributeName(GetAttributeN(typeParams, j));
			// Checking the presence in the label
			if(CheckAttribute(label, param) != 0) continue;
			// Copying the parameter
			label.(param) = typeParams.(param);
		}
	}
}
