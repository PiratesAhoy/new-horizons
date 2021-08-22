// Note from MAXIMUS
// If anyone will change (or will add new) .label or (.id) - please
// be patient and add this label into RESOURCE\INI\TEXTS\(all languages)\interface_strings.txt
// It's VERY important for multilingual BUILD
void InitIslands()
{
	int		n, i;
	object oIsland, locator;
	ref q, rIsland;

	//ISLANDS_QUANTITY = 0; // NK 05-03-30 use int and oversized array

	n = 0;
	q = &n;
	makeref(rIsland, oIsland);

	/*for (i=0; i<MAX_ISLANDS; i++)
	{
		DeleteAttribute(&Islands[i], "");

		Islands[i].id = "";
		Islands[i].reload_enable = true;
		Islands[i].visible = true;
	}*/

	// ==================================================================================================
	// Create temp module for enumerate locators
		CreateEntity(&locator, "locator");


	// ==================================================================================================
	// Falaise de fleur
		rIsland.id = "FalaiseDeFleur";
		rIsland.model = "FalaiseDeFleur";
		rIsland.filespath.models = "islands\FalaiseDeFleur";
		rIsland.refl_model = "FalaiseDeFleur_refl";
		rIsland.locators = "FalaiseDeFleur_locators";
		rIsland.visible = true;
		rIsland.smuggling_nation = FRANCE;
		// NK -->
		rIsland.towns.quantity = 1;
		rIsland.towns.1 = "Falaise de Fleur";
		// NK <--

		rIsland.reload.l1.label = "#stown_name# Port"; // KK
		rIsland.reload.l1.name = "reload_1";
		rIsland.reload.l1.go = "Falaise_de_fleur_port_01";
		rIsland.reload.l1.emerge = "sea";
		rIsland.reload.l1.radius = 200.0;
		rIsland.reload.l1.pic = 15;
		rIsland.reload.l1.tex = "t1";
		rIsland.reload.l1.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l2.label = "Octopus Bay";
		rIsland.reload.l2.name = "reload_2";
		rIsland.reload.l2.go = "Falaise_de_Fleur_shore";
		rIsland.reload.l2.emerge = "reload1";
		rIsland.reload.l2.radius = 200.0;
		rIsland.reload.l2.pic = 21;
		rIsland.reload.l2.tex = "t2";
		rIsland.reload.l2.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l3.label = "#stown_name# Fort"; // KK
		rIsland.reload.l3.name = "reload_fort1";
		rIsland.reload.l3.go = "Fort"; // KK
		rIsland.reload.l3.GoAfterBoard.location = "reload_1";
		rIsland.reload.l3.emerge = "see";
		rIsland.reload.l3.radius = 250.0;
		rIsland.reload.l3.commander = "FalaiseDeFleur Commander"; // KK
		rIsland.reload.l3.fort.model = "FalaiseDeFleur_fort1";
		rIsland.reload.l3.fort.locators = "FalaiseDeFleur_fort1_locators";
		rIsland.reload.l3.pic = 22;
		rIsland.reload.l3.tex = "t1";
		rIsland.reload.l3.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.InterfaceTextures.t1 = "battle_interface\moor-town.tga";
		rIsland.InterfaceTextures.t1.h = 4;
		rIsland.InterfaceTextures.t1.v = 16;
		rIsland.InterfaceTextures.t2 = "battle_interface\moor-shores.tga";
		rIsland.InterfaceTextures.t2.h = 4;
		rIsland.InterfaceTextures.t2.v = 16;

		rIsland.Trade.Export.id1 = GOOD_SAILCLOTH;
		rIsland.Trade.Export.id2 = GOOD_CHOCOLATE;
		rIsland.Trade.Export.id3 = GOOD_LINEN;
		rIsland.Trade.Export.id4 = GOOD_SILK;
		rIsland.Trade.Export.id5 = GOOD_SILVER;
		rIsland.Trade.Import.id1 = GOOD_PLANKS;
		rIsland.Trade.Import.id2 = GOOD_EBONY;
		rIsland.Trade.Import.id3 = GOOD_RUM;
		rIsland.Trade.Import.id4 = GOOD_LEATHER;
		rIsland.Trade.Import.id5 = GOOD_GOLD;
		rIsland.Trade.Import.id6 = GOOD_TREATMENT;
		rIsland.Trade.Contraband.id1 = GOOD_SANDAL;
		rIsland.Trade.Contraband.id2 = GOOD_FRUITS;
		rIsland.Trade.Contraband.id3 = GOOD_CINNAMON;

		AddIsland(q, rIsland, locator);

	// ==================================================================================================
	// Redmond
		rIsland.id = "Redmond";
		rIsland.model = "redmond";
		rIsland.filespath.models = "islands\redmond";
		rIsland.refl_model = "redmond_refl";
		rIsland.locators = "redmond_locators";
		rIsland.visible = true;
		rIsland.smuggling_nation = ENGLAND;
		// NK -->
		rIsland.towns.quantity = 1;
		rIsland.towns.1 = "Redmond";
		// NK <--

		rIsland.reload.l1.label = "#stown_name# Port"; // KK
		rIsland.reload.l1.name = "reload_2";
		rIsland.reload.l1.go = "REDMOND_PORT";
		rIsland.reload.l1.emerge = "sea_1";
		rIsland.reload.l1.radius = 600.0;
		rIsland.reload.l1.pic = 7;
		rIsland.reload.l1.tex = "t1";
		rIsland.reload.l1.goto_enable = false; // Screwface: Disable Sail-To

		if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0)
		{
			rIsland.reload.l2.label = "Woodes Rogers' Port";
			rIsland.reload.l2.name = "reload_1";
			rIsland.reload.l2.go = "wr_port";
			rIsland.reload.l2.emerge = "reload1";
			rIsland.reload.l2.radius = 200.0;
			rIsland.reload.l2.pic = 10;
			rIsland.reload.l2.tex = "t1";
			rIsland.reload.l2.enable = false;      //start disabled
			rIsland.reload.l2.goto_enable = false; // Screwface: Disable Sail-To

			rIsland.reload.l3.label = "Cave shore";
			rIsland.reload.l3.name = "reload_3";
			rIsland.reload.l3.go = "wr_cave_shore";
			rIsland.reload.l3.emerge = "reload11";
			rIsland.reload.l3.radius = 200.0;
			rIsland.reload.l3.pic = 2;
			rIsland.reload.l3.tex = "t2";
			rIsland.reload.l3.enable = false;      //start disabled
			rIsland.reload.l3.goto_enable = false; // Screwface: Disable Sail-To
		}
		else
		{
			rIsland.reload.l2.label = "Devil's Throat";
			rIsland.reload.l2.name = "reload_1";
			rIsland.reload.l2.go = "Redmond_Shore_01";
			rIsland.reload.l2.emerge = "reload1";
			rIsland.reload.l2.radius = 200.0;
			rIsland.reload.l2.pic = 12;
			rIsland.reload.l2.tex = "t2";
			rIsland.reload.l2.goto_enable = false; // Screwface: Disable Sail-To

			rIsland.reload.l3.label = "Rocky Shore";
			rIsland.reload.l3.name = "reload_3";
			rIsland.reload.l3.go = "Redmond_Shore_02";
			rIsland.reload.l3.emerge = "reload1";
			rIsland.reload.l3.radius = 200.0;
			rIsland.reload.l3.pic = 13;
			rIsland.reload.l3.tex = "t2";
			rIsland.reload.l3.goto_enable = false; // Screwface: Disable Sail-To
		}

		rIsland.reload.l4.label = "#stown_name# Fort"; // KK
		rIsland.reload.l4.name = "reload_fort1";
		rIsland.reload.l4.go = "Fort"; // KK
		rIsland.reload.l4.GoAfterBoard.location = "reload_2";
		rIsland.reload.l4.emerge = "see";
		rIsland.reload.l4.commander = "Redmond Commander"; // KK
		rIsland.reload.l4.radius = 250.0;
		rIsland.reload.l4.fort.model = "Redmond_fort1";
		rIsland.reload.l4.fort.locators = "Redmond_fort1_locators";
		rIsland.reload.l4.pic = 22;
		rIsland.reload.l4.tex = "t1";
		rIsland.reload.l4.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.InterfaceTextures.t1 = "battle_interface\moor-town.tga";
		rIsland.InterfaceTextures.t1.h = 4;
		rIsland.InterfaceTextures.t1.v = 16;
		rIsland.InterfaceTextures.t2 = "battle_interface\moor-shores.tga";
		rIsland.InterfaceTextures.t2.h = 4;
		rIsland.InterfaceTextures.t2.v = 16;

		rIsland.Trade.Export.id1 = GOOD_SAILCLOTH;
		rIsland.Trade.Export.id2 = GOOD_LINEN;
		rIsland.Trade.Export.id3 = GOOD_ALE;
		rIsland.Trade.Export.id4 = GOOD_CLOTHES;
		rIsland.Trade.Import.id1 = GOOD_PLANKS;
		rIsland.Trade.Import.id2 = GOOD_CINNAMON;
		rIsland.Trade.Import.id3 = GOOD_SILK;
		rIsland.Trade.Import.id4 = GOOD_SANDAL;
		rIsland.Trade.Contraband.id1 = GOOD_EBONY;
		rIsland.Trade.Contraband.id2 = GOOD_COFFEE;
		rIsland.Trade.Contraband.id3 = GOOD_PAPRIKA;

		AddIsland(q, rIsland, locator);

	// ==================================================================================================
	// Isla Muelle
		rIsland.id = "IslaMuelle";
		rIsland.model = "IslaMuelle";
		rIsland.filespath.models = "islands\IslaMuelle";
		rIsland.refl_model = "IslaMuelle_refl";
		rIsland.locators = "IslaMuelle_locators";
		rIsland.visible = true;
		rIsland.smuggling_nation = SPAIN;
		// NK -->
		rIsland.towns.quantity = 1;
		rIsland.towns.1 = "Isla Muelle";
		// NK <--

		rIsland.reload.l1.label = "#stown_name# Port"; // KK
		rIsland.reload.l1.name = "reload_1";
		rIsland.reload.l1.go = "Muelle_port";
		rIsland.reload.l1.emerge = "Reload3";
		rIsland.reload.l1.radius = 200.0;
		rIsland.reload.l1.pic = 8;
		rIsland.reload.l1.tex = "t1";
		rIsland.reload.l1.ships.l0.ay = 2.5;			// LDH fix until the locators.gm file can be updated - 24Apr09
		rIsland.reload.l1.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l2.label = "Shore";
		rIsland.reload.l2.name = "reload_2";
		rIsland.reload.l2.go = "Muelle_shore_02";
		rIsland.reload.l2.emerge = "see";
		rIsland.reload.l2.radius = 200.0;
		rIsland.reload.l2.enable = false;
		rIsland.reload.l2.pic = 14;
		rIsland.reload.l2.tex = "t2";
		rIsland.reload.l2.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l3.label = "Oyster Beach";
		rIsland.reload.l3.name = "reload_3";
		rIsland.reload.l3.go = "Muelle_shore";
		rIsland.reload.l3.emerge = "reload2";
		rIsland.reload.l3.radius = 200.0;
		rIsland.reload.l3.pic = 15;
		rIsland.reload.l3.tex = "t2";
		rIsland.reload.l3.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l4.label = "#stown_name# Fort"; // KK
		rIsland.reload.l4.name = "reload_fort1";
		rIsland.reload.l4.go = "Fort"; // KK
		rIsland.reload.l4.GoAfterBoard.location = "reload_1";
		rIsland.reload.l4.emerge = "see";
		rIsland.reload.l4.commander = "IslaMuelle Commander"; // KK
		rIsland.reload.l4.radius = 250.0;
		rIsland.reload.l4.fort.model = "IslaMuelle_fort1";
		rIsland.reload.l4.fort.locators = "IslaMuelle_fort1_locators";
		rIsland.reload.l4.pic = 22;
		rIsland.reload.l4.tex = "t1";
		rIsland.reload.l4.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.InterfaceTextures.t1 = "battle_interface\moor-town.tga";
		rIsland.InterfaceTextures.t1.h = 4;
		rIsland.InterfaceTextures.t1.v = 16;
		rIsland.InterfaceTextures.t2 = "battle_interface\moor-shores.tga";
		rIsland.InterfaceTextures.t2.h = 4;
		rIsland.InterfaceTextures.t2.v = 16;

		rIsland.Trade.Export.id1 = GOOD_EBONY;
		rIsland.Trade.Export.id2 = GOOD_MAHOGANY;
		rIsland.Trade.Export.id3 = GOOD_CINNAMON;
		rIsland.Trade.Export.id4 = GOOD_SANDAL;
		rIsland.Trade.Export.id5 = GOOD_GOLD;
		rIsland.Trade.Export.id6 = GOOD_BRICKS;
		rIsland.Trade.Import.id1 = GOOD_PLANKS;
		rIsland.Trade.Import.id2 = GOOD_SAILCLOTH;
		rIsland.Trade.Import.id3 = GOOD_SUGAR;
		rIsland.Trade.Import.id4 = GOOD_LINEN;
		rIsland.Trade.Import.id5 = GOOD_SILVER;
		rIsland.Trade.Import.id6 = GOOD_TREATMENT;
		rIsland.Trade.Contraband.id1 = GOOD_ALE;
		rIsland.Trade.Contraband.id2 = GOOD_SILK;
		rIsland.Trade.Contraband.id3 = GOOD_TOBACCO;

		AddIsland(q, rIsland, locator);

	// ==================================================================================================
	// Oxbay
		rIsland.id = "Oxbay";
		rIsland.model = "Oxbay";
		rIsland.filespath.models = "islands\Oxbay";
		rIsland.refl_model = "Oxbay_refl";
		rIsland.locators = "Oxbay_locators";
		rIsland.visible = true;
		rIsland.smuggling_nation = ENGLAND;
		// NK -->
		rIsland.towns.quantity = 2;
		rIsland.towns.1 = "Oxbay";
		rIsland.towns.2 = "Greenford";
		// NK <--

		rIsland.reload.l1.label = "#stown_name# Port"; // KK
		rIsland.reload.l1.name = "reload_2";
		rIsland.reload.l1.go = "Oxbay_port";
		rIsland.reload.l1.emerge = "reload2";
		rIsland.reload.l1.radius = 200.0;
		rIsland.reload.l1.pic = 16;
		rIsland.reload.l1.tex = "t1";
		rIsland.reload.l1.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l2.label = "#stown_name# Port"; // KK
		rIsland.reload.l2.name = "reload_1";
		rIsland.reload.l2.go = "Greenford_port";
		rIsland.reload.l2.emerge = "reload1";
		rIsland.reload.l2.radius = 200.0;
		rIsland.reload.l2.pic = 17;
		rIsland.reload.l2.tex = "t1";
        rIsland.reload.l2.ships.l0.ay = 3.4;        // LDH 11Dec16
		rIsland.reload.l2.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l3.label = "Gray Rock Bay";
		rIsland.reload.l3.name = "reload_3";
		rIsland.reload.l3.go = "Oxbay_shore_02";
		rIsland.reload.l3.emerge = "reload1";
		rIsland.reload.l3.radius = 300.0;
		rIsland.reload.l3.pic = 22;
		rIsland.reload.l3.tex = "t2";
		rIsland.reload.l3.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l4.label = "Lighthouse";
		rIsland.reload.l4.name = "reload_4";
		rIsland.reload.l4.go = "Oxbay_lighthouse";
		rIsland.reload.l4.emerge = "reload3";
		rIsland.reload.l4.radius = 200.0;
		rIsland.reload.l4.pic = 23;
		rIsland.reload.l4.tex = "t2";
		rIsland.reload.l4.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l5.label = "Far Beach";
		rIsland.reload.l5.name = "reload_5";
		rIsland.reload.l5.go = "Oxbay_Shore_01";
		rIsland.reload.l5.emerge = "see";
		rIsland.reload.l5.radius = 200.0;
		rIsland.reload.l5.pic = 24;
		rIsland.reload.l5.tex = "t2";
		rIsland.reload.l5.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l6.label = "#stown_name# Fort"; // KK
		rIsland.reload.l6.name = "reload_fort1";
		rIsland.reload.l6.go = "Fort"; // KK
		rIsland.reload.l6.GoAfterBoard.location = "reload_1";
		rIsland.reload.l6.emerge = "see";
		rIsland.reload.l6.radius = 250.0;
		rIsland.reload.l6.commander = "Greenford Commander"; // KK
		rIsland.reload.l6.fort.model = "Oxbay_fort1";
		rIsland.reload.l6.fort.locators = "Oxbay_fort1_locators";
		rIsland.reload.l6.pic = 22;
		rIsland.reload.l6.tex = "t1";
		rIsland.reload.l6.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l7.label = "#stown_name# Fort"; // KK
		rIsland.reload.l7.name = "reload_fort2";
		rIsland.reload.l7.go = "Fort"; // KK
		rIsland.reload.l7.GoAfterBoard.location = "reload_2";
		rIsland.reload.l7.emerge = "see";
		rIsland.reload.l7.commander = "Oxbay Commander"; // KK
		rIsland.reload.l7.radius = 250.0;
		rIsland.reload.l7.fort.model = "Oxbay_fort2";
		rIsland.reload.l7.fort.locators = "Oxbay_fort2_locators";
		rIsland.reload.l7.pic = 22;
		rIsland.reload.l7.tex = "t1";
		rIsland.reload.l7.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.InterfaceTextures.t1 = "battle_interface\moor-town.tga";
		rIsland.InterfaceTextures.t1.h = 4;
		rIsland.InterfaceTextures.t1.v = 16;
		rIsland.InterfaceTextures.t2 = "battle_interface\moor-shores.tga";
		rIsland.InterfaceTextures.t2.h = 4;
		rIsland.InterfaceTextures.t2.v = 16;

		rIsland.Trade.Export.id1 = GOOD_SANDAL;
		rIsland.Trade.Export.id2 = GOOD_RUM;
		rIsland.Trade.Export.id3 = GOOD_TOBACCO;
		rIsland.Trade.Export.id4 = GOOD_SILVER;
		rIsland.Trade.Export.id5 = GOOD_GOLD;
		rIsland.Trade.Import.id1 = GOOD_SAILCLOTH;
		rIsland.Trade.Import.id2 = GOOD_CHOCOLATE;
		rIsland.Trade.Import.id3 = GOOD_SILK;
		rIsland.Trade.Import.id4 = GOOD_LEATHER;
		rIsland.Trade.Contraband.id1 = GOOD_EBONY;
		rIsland.Trade.Contraband.id2 = GOOD_COFFEE;
		rIsland.Trade.Contraband.id3 = GOOD_PAPRIKA;
		rIsland.Trade.Contraband.id4 = GOOD_BRICKS;

		AddIsland(q, rIsland, locator);

	// ==================================================================================================
	// Conceicao
		rIsland.id = "Conceicao";
		rIsland.model = "Conceicao";
		rIsland.filespath.models = "islands\Conceicao";
		rIsland.refl_model = "Conceicao_refl";
		rIsland.locators = "Conceicao_locators";
		rIsland.visible = true;
		rIsland.smuggling_nation = PORTUGAL;
		// NK -->
		rIsland.towns.quantity = 2;
		rIsland.towns.1 = "Conceicao";
		rIsland.towns.2 = "Smugglers Lair";
		// NK <--

		rIsland.reload.l1.label = "#stown_name# Port"; // KK
		rIsland.reload.l1.name = "reload_1";
		rIsland.reload.l1.go = "Conceicao_port";
		rIsland.reload.l1.emerge = "reload2";
		rIsland.reload.l1.radius = 200.0;
		rIsland.reload.l1.pic = 18;
		rIsland.reload.l1.tex = "t1";
        rIsland.reload.l1.ships.l0.ay = -1.5;           // LDH 11Dec16
		rIsland.reload.l1.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l2.label = "Sunny Haven";
		rIsland.reload.l2.name = "reload_2";
		rIsland.reload.l2.go = "Conceicao_shore_01";
		rIsland.reload.l2.emerge = "reload1";
		rIsland.reload.l2.radius = 200.0;
		rIsland.reload.l2.pic = 25;
		rIsland.reload.l2.tex = "t2";
		rIsland.reload.l2.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l3.label = "Leviathan Rock";
		rIsland.reload.l3.name = "reload_3";
		rIsland.reload.l3.go = "Conceicao_shore_02";
		rIsland.reload.l3.emerge = "see";
		rIsland.reload.l3.radius = 200.0;
		rIsland.reload.l3.pic = 26;
		rIsland.reload.l3.tex = "t2";
		rIsland.reload.l3.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l4.label = "#stown_name# Fort"; // KK
		rIsland.reload.l4.name = "reload_fort1";
		rIsland.reload.l4.go = "Fort"; // KK
		rIsland.reload.l4.GoAfterBoard.location = "reload_1";
		rIsland.reload.l4.emerge = "see";
		rIsland.reload.l4.radius = 250.0;
		rIsland.reload.l4.commander = "Conceicao Commander"; // KK
		rIsland.reload.l4.fort.locators = "Conceicao_fort1_locators";
		rIsland.reload.l4.fort.model = "Conceicao_fort1";
		rIsland.reload.l4.pic = 22;
		rIsland.reload.l4.tex = "t1";
		rIsland.reload.l4.goto_enable = false; // Screwface: Disable Sail-To
		
		rIsland.reload.l5.label = "Linda Praia";
		rIsland.reload.l5.name = "reload_4";
		rIsland.reload.l5.go = "Conceicao_Shore_03";
		rIsland.reload.l5.emerge = "see";
		rIsland.reload.l5.radius = 200.0;
		rIsland.reload.l5.pic = 26;
		rIsland.reload.l5.tex = "t2";
		rIsland.reload.l5.enable = false;		
		rIsland.reload.l5.goto_enable = false; // Screwface: Disable Sail-To		

		rIsland.InterfaceTextures.t1 = "battle_interface\moor-town.tga";
		rIsland.InterfaceTextures.t1.h = 4;
		rIsland.InterfaceTextures.t1.v = 16;
		rIsland.InterfaceTextures.t2 = "battle_interface\moor-shores.tga";
		rIsland.InterfaceTextures.t2.h = 4;
		rIsland.InterfaceTextures.t2.v = 16;

		rIsland.Trade.Export.id1 = GOOD_SAILCLOTH;
		rIsland.Trade.Export.id2 = GOOD_SUGAR;
		rIsland.Trade.Export.id3 = GOOD_CINNAMON;
		rIsland.Trade.Export.id4 = GOOD_FRUITS;
		rIsland.Trade.Import.id1 = GOOD_SILK;
		rIsland.Trade.Import.id2 = GOOD_ALE;
		rIsland.Trade.Import.id3 = GOOD_RUM;
		rIsland.Trade.Import.id4 = GOOD_CHOCOLATE;
		rIsland.Trade.Import.id5 = GOOD_GOLD;
		rIsland.Trade.Import.id6 = GOOD_SILVER;
		rIsland.Trade.Import.id7 = GOOD_TREATMENT;
		rIsland.Trade.Contraband.id1 = GOOD_WINE;
		rIsland.Trade.Contraband.id2 = GOOD_MAHOGANY;
		rIsland.Trade.Contraband.id3 = GOOD_COPRA;

		AddIsland(q, rIsland, locator);

	// ==================================================================================================
	// Douwesen
		rIsland.id = "Douwesen";
		rIsland.model = "Douwesen";
		rIsland.filespath.models = "islands\Douwesen";
		rIsland.refl_model = "Douwesen_refl";
		rIsland.locators = "Douwesen_locators";
		rIsland.visible = true;
		rIsland.smuggling_nation = HOLLAND;
		// NK -->
		rIsland.towns.quantity = 2;
		rIsland.towns.1 = "Douwesen";
		rIsland.towns.2 = "Pirate Fort";
		// NK <--

		rIsland.reload.l1.label = "#stown_name# Port"; // KK
		rIsland.reload.l1.name = "reload_1";
		rIsland.reload.l1.go = "Douwesen_port";
		rIsland.reload.l1.emerge = "reload2";
		rIsland.reload.l1.radius = 200.0;
		rIsland.reload.l1.pic = 19;
		rIsland.reload.l1.tex = "t1";
        rIsland.reload.l1.ships.l0.ay = 2.7;        // LDH 11Dec16
		rIsland.reload.l1.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l2.label = "Palm Beach";
		rIsland.reload.l2.name = "reload_2";
		rIsland.reload.l2.go = "Douwesen_shore_01";
		rIsland.reload.l2.emerge = "reload1";
		rIsland.reload.l2.radius = 200.0;
		rIsland.reload.l2.pic = 27;
		rIsland.reload.l2.tex = "t2";
		rIsland.reload.l2.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l3.label = "Crab Cliffs";
		rIsland.reload.l3.name = "reload_3";
		rIsland.reload.l3.go = "Douwesen_shore_02";
		rIsland.reload.l3.emerge = "reload1";
		rIsland.reload.l3.radius = 200.0;
		rIsland.reload.l3.pic = 28;
		rIsland.reload.l3.tex = "t2";
		rIsland.reload.l3.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l4.label = "#stown_name# Fort"; // KK
		rIsland.reload.l4.name = "reload_fort1";
		rIsland.reload.l4.go = "Fort"; // KK
		rIsland.reload.l4.GoAfterBoard.location = "reload_1";
		rIsland.reload.l4.emerge = "see";
		rIsland.reload.l4.radius = 250.0;
		rIsland.reload.l4.commander = "Douwesen Commander"; // KK
		rIsland.reload.l4.fort.model = "Douwesen_fort1";
		rIsland.reload.l4.fort.locators = "Douwesen_fort1_locators";
		rIsland.reload.l4.pic = 22;
		rIsland.reload.l4.tex = "t1";
		rIsland.reload.l4.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.InterfaceTextures.t1 = "battle_interface\moor-town.tga";
		rIsland.InterfaceTextures.t1.h = 4;
		rIsland.InterfaceTextures.t1.v = 16;
		rIsland.InterfaceTextures.t2 = "battle_interface\moor-shores.tga";
		rIsland.InterfaceTextures.t2.h = 4;
		rIsland.InterfaceTextures.t2.v = 16;

		rIsland.Trade.Export.id1 = GOOD_TOBACCO;
		rIsland.Trade.Export.id2 = GOOD_COFFEE;
		rIsland.Trade.Export.id3 = GOOD_COPRA;
		rIsland.Trade.Export.id4 = GOOD_ALE;
		rIsland.Trade.Export.id5 = GOOD_FOOD;
		rIsland.Trade.Export.id6 = GOOD_TREATMENT;
		rIsland.Trade.Import.id1 = GOOD_PLANKS;
		rIsland.Trade.Import.id2 = GOOD_SAILCLOTH;
		rIsland.Trade.Import.id3 = GOOD_WHEAT;
		rIsland.Trade.Import.id4 = GOOD_RUM;
		rIsland.Trade.Import.id5 = GOOD_GOLD;
		rIsland.Trade.Import.id6 = GOOD_SILVER;
		rIsland.Trade.Import.id7 = GOOD_OIL;
		rIsland.Trade.Import.id8 = GOOD_COTTON;
		rIsland.Trade.Contraband.id1 = GOOD_SUGAR;
		rIsland.Trade.Contraband.id2 = GOOD_LINEN;
		rIsland.Trade.Contraband.id3 = GOOD_WINE;

		AddIsland(q, rIsland, locator);

	// ==================================================================================================
	// Quebradas
		rIsland.id = "QuebradasCostillas";
		rIsland.model = "QuebradasCostillas";
		rIsland.filespath.models = "islands\QuebradasCostillas";
		rIsland.refl_model = "QuebradasCostillas_refl";
		rIsland.locators = "QuebradasCostillas_locators";
		rIsland.visible = true; // KK
		rIsland.smuggling_nation = ENGLAND; // KK
		// NK -->
		rIsland.towns.quantity = 2;
		rIsland.towns.1 = "Charlestown";
		rIsland.towns.2 = "Quebradas Costillas";
		// NK <--

		rIsland.reload.l1.label = "#stown_name# Port"; // KK
		rIsland.reload.l1.name = "reload_2";
		rIsland.reload.l1.go = "Charlestown_port";
		rIsland.reload.l1.emerge = "reload1_back";
		rIsland.reload.l1.radius = 200.0;
		rIsland.reload.l1.pic = 9;
		rIsland.reload.l1.tex = "t1";
		rIsland.reload.l1.ships.l0.ay = 3.0;    // LDH 11Dec16
		rIsland.reload.l1.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l2.label = "#stown_name# Port"; // KK
		rIsland.reload.l2.name = "reload_1";
		rIsland.reload.l2.go = "QC_port";
		rIsland.reload.l2.emerge = "reload1";
		rIsland.reload.l2.radius = 200.0;
		rIsland.reload.l2.pic = 10;
		rIsland.reload.l2.tex = "t1";
		rIsland.reload.l2.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l3.label = "White bay";
		rIsland.reload.l3.name = "reload_3";
		rIsland.reload.l3.go = "QC_Shore1";
		rIsland.reload.l3.emerge = "reload1";
		rIsland.reload.l3.radius = 200.0;
		rIsland.reload.l3.pic = 16;
		rIsland.reload.l3.tex = "t2";
		rIsland.reload.l3.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l4.label = "#stown_name# Fort"; // KK
		rIsland.reload.l4.name = "reload_fort1";
		rIsland.reload.l4.go = "Fort"; // KK
		rIsland.reload.l4.GoAfterBoard.location = "reload_2";
		rIsland.reload.l4.emerge = "see";
		rIsland.reload.l4.radius = 250.0;
		rIsland.reload.l4.commander = "Charlestown Commander"; // KK
		rIsland.reload.l4.fort.model = "QuebradasCostillas_Fort1";
		rIsland.reload.l4.fort.locators = "QuebradasCostillas_Fort1_locators";
		rIsland.reload.l4.pic = 22;
		rIsland.reload.l4.tex = "t1";
		rIsland.reload.l4.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.InterfaceTextures.t1 = "battle_interface\moor-town.tga";
		rIsland.InterfaceTextures.t1.h = 4;
		rIsland.InterfaceTextures.t1.v = 16;
		rIsland.InterfaceTextures.t2 = "battle_interface\moor-shores.tga";
		rIsland.InterfaceTextures.t2.h = 4;
		rIsland.InterfaceTextures.t2.v = 16;

		rIsland.Trade.Export.id1 = GOOD_RUM;
		rIsland.Trade.Export.id2 = GOOD_ALE;
		rIsland.Trade.Export.id3 = GOOD_WINE;
		rIsland.Trade.Export.id4 = GOOD_PLANKS;
		rIsland.Trade.Import.id1 = GOOD_GOLD;
		rIsland.Trade.Import.id2 = GOOD_SILVER;
		rIsland.Trade.Import.id3 = GOOD_MAHOGANY;
		rIsland.Trade.Import.id4 = GOOD_GUNPOWDER;
		rIsland.Trade.Import.id5 = GOOD_CLOTHES;
		rIsland.Trade.Import.id6 = GOOD_COTTON;
		rIsland.Trade.Import.id7 = GOOD_OIL;
		rIsland.Trade.Contraband.id1 = GOOD_EBONY;
		rIsland.Trade.Contraband.id2 = GOOD_COFFEE;
		rIsland.Trade.Contraband.id3 = GOOD_PAPRIKA;

		AddIsland(q, rIsland, locator);

	// ==================================================================================================
	// Khael Roa
		rIsland.id = "KhaelRoa";
		rIsland.model = "KhaelRoa";
		rIsland.filespath.models = "islands\KhaelRoa";
		rIsland.refl_model = "KhaelRoa_refl";
		rIsland.locators = "KhaelRoa_locators";
		rIsland.visible = false;
		rIsland.Enc_enable = false;
		rIsland.skipCR = true; // KK
		rIsland.smuggling_nation = PERSONAL_NATION; // PB: Can use as your own personal Hide-Out
		// NK -->
		rIsland.towns.quantity = 1;
		rIsland.towns.1 = "Khael Roa";
		// NK <--

		rIsland.reload.l1.label = "Khael Roa Shore";
		rIsland.reload.l1.name = "reload_1";
		rIsland.reload.l1.go = "KhaelRoa_port";
		rIsland.reload.l1.emerge = "Reload2";
		rIsland.reload.l1.radius = 200.0;
		rIsland.reload.l1.enable = false;
		rIsland.reload.l1.goto_enable = false; // Screwface: Disable Sail-To
		rIsland.reload.l1.pic = 8;
		rIsland.reload.l1.tex = "t2";

		rIsland.InterfaceTextures.t2 = "battle_interface\moor-shores.tga";
		rIsland.InterfaceTextures.t2.h = 4;
		rIsland.InterfaceTextures.t2.v = 16;

		AddIsland(q, rIsland, locator);

	// ==================================================================================================

	// ==================================================================================================
	// Cayman
		rIsland.id = "Cayman";
		rIsland.model = "Cayman";
		rIsland.filespath.models = "islands\Cayman";
		rIsland.refl_model = "Cayman_refl";
		rIsland.locators = "Cayman_locators";
		rIsland.visible = true;
		rIsland.smuggling_nation = ENGLAND;
		// NK -->
		rIsland.towns.quantity = 1;
		rIsland.towns.1 = "Grand Cayman";
		// NK <--

		rIsland.reload.l1.label = "#stown_name#"; // KK
		rIsland.reload.l1.name = "reload_1";
		rIsland.reload.l1.go = "Cayman_port";
		rIsland.reload.l1.emerge = "sea";
		rIsland.reload.l1.radius = 200.0;
		rIsland.reload.l1.pic = 6;
		rIsland.reload.l1.tex = "t1";
		rIsland.reload.l1.ships.l0.ay = 1.7;			// LDH fix until the locators.gm file can be updated - 19Apr09
		rIsland.reload.l1.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l2.label = "Cayman Kai";
		rIsland.reload.l2.name = "reload_2";
		rIsland.reload.l2.go = "Cayman_Shore_02";
		rIsland.reload.l2.emerge = "see"; // KK
		rIsland.reload.l2.radius = 200.0;
		rIsland.reload.l2.pic = 9;
		rIsland.reload.l2.tex = "t2";
		rIsland.reload.l2.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l3.label = "Sand Bluff";
		rIsland.reload.l3.name = "reload_3";
		rIsland.reload.l3.go = "Cayman_Shore_03";
		rIsland.reload.l3.emerge = "reload1";
		rIsland.reload.l3.radius = 200.0;
		rIsland.reload.l3.pic = 10;
		rIsland.reload.l3.tex = "t2";
		rIsland.reload.l3.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l4.label = "Eden Rock";
		rIsland.reload.l4.name = "reload_4";
		rIsland.reload.l4.go = "Cayman_Shore_01";
		rIsland.reload.l4.emerge = "reload1";
		rIsland.reload.l4.radius = 200.0;
		rIsland.reload.l4.pic = 11;
		rIsland.reload.l4.tex = "t2";
		rIsland.reload.l4.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l5.label = "#stown_name# Fort"; // KK
		rIsland.reload.l5.name = "reload1_2";
		rIsland.reload.l5.go = "Fort"; // KK
		rIsland.reload.l5.GoAfterBoard.location = "reload_1";
		rIsland.reload.l5.emerge = "see";
		rIsland.reload.l5.radius = 250.0;
		rIsland.reload.l5.commander = "Grand Cayman Commander"; // KK
		rIsland.reload.l5.fort.model = "Cayman_fort2";
		rIsland.reload.l5.fort.locators = "Cayman_fort2_locators";
		rIsland.reload.l5.pic = 22;
		rIsland.reload.l5.tex = "t1";
		rIsland.reload.l5.goto_enable = false; // Screwface: Disable Sail-To

//		rIsland.reload.l6.label = "reload 5";
//		rIsland.reload.l6.name = "reload_5";
//		rIsland.reload.l6.go = "";
//		rIsland.reload.l6.emerge = "";
//		rIsland.reload.l6.radius = 200.0;
//		rIsland.reload.l6.pic = 5;
//		rIsland.reload.l6.tex = "t2";
//		rIsland.reload.l6.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.InterfaceTextures.t1 = "battle_interface\moor-town.tga";
		rIsland.InterfaceTextures.t1.h = 4;
		rIsland.InterfaceTextures.t1.v = 16;
		rIsland.InterfaceTextures.t2 = "battle_interface\moor-shores.tga";
		rIsland.InterfaceTextures.t2.h = 4;
		rIsland.InterfaceTextures.t2.v = 16;

		rIsland.Trade.Export.id1 = GOOD_SANDAL;
		rIsland.Trade.Export.id2 = GOOD_RUM;
		rIsland.Trade.Export.id3 = GOOD_TOBACCO;
		rIsland.Trade.Import.id1 = GOOD_SAILCLOTH;
		rIsland.Trade.Import.id2 = GOOD_CHOCOLATE;
		rIsland.Trade.Import.id3 = GOOD_SILK;
		rIsland.Trade.Import.id4 = GOOD_LEATHER;
		rIsland.Trade.Contraband.id1 = GOOD_EBONY;
		rIsland.Trade.Contraband.id2 = GOOD_COFFEE;
		rIsland.Trade.Contraband.id3 = GOOD_PAPRIKA;

		AddIsland(q, rIsland, locator);

	// ==================================================================================================
	// Hispaniola (Gaity)
		rIsland.id = "Hispaniola";
		rIsland.model = "Gaity";
		rIsland.filespath.models = "islands\Gaity";
		rIsland.refl_model = "Gaity_refl";
		rIsland.locators = "Gaity_locators";
		rIsland.visible = true;
		rIsland.smuggling_nation = SPAIN;
		// NK -->
		rIsland.towns.quantity = 4; // KK
		rIsland.towns.1 = "Port au Prince";
		rIsland.towns.2 = "Santo Domingo";
		rIsland.towns.3 = "Tortuga";
		rIsland.towns.4 = "Buccaneers Camp"; // KK
		// NK <--

		rIsland.reload.l1.label = "#stown_name#"; // KK
		rIsland.reload.l1.name = "reload_1";
		rIsland.reload.l1.go = "PoPrince_Port";
		rIsland.reload.l1.emerge = "Reload2";
		rIsland.reload.l1.radius = 200.0;
		rIsland.reload.l1.pic = 0;
		rIsland.reload.l1.tex = "t1";
		rIsland.reload.l1.ships.l0.ay = 1.7;		// LDH 11Dec16
		rIsland.reload.l1.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l2.label = "#stown_name#"; // KK
		rIsland.reload.l2.name = "reload_3";
		rIsland.reload.l2.go = "Santo_Domingo_port";
		rIsland.reload.l2.emerge = "Reload1";
		rIsland.reload.l2.radius = 200.0;
		rIsland.reload.l2.pic = 1;
		rIsland.reload.l2.tex = "t1";
		rIsland.reload.l2.ships.l0.ay = 0.7;		// LDH 11Dec16
		rIsland.reload.l2.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l3.label = "#stown_name# Port"; // KK
		rIsland.reload.l3.name = "reload_7";
		rIsland.reload.l3.go = "Tortuga_port";
		rIsland.reload.l3.emerge = "Reload2";
		rIsland.reload.l3.radius = 200.0;
		rIsland.reload.l3.pic = 2;
		rIsland.reload.l3.tex = "t1";
		rIsland.reload.l3.ships.l0.ay = -0.8;		// LDH 11Dec16
		rIsland.reload.l3.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l4.label = "Boca de Yuman";
		rIsland.reload.l4.name = "reload_2";
		rIsland.reload.l4.go = "Hispaniola_shore_01";
		rIsland.reload.l4.emerge = "Reload1";
		rIsland.reload.l4.radius = 200.0;
		rIsland.reload.l4.pic = 0;
		rIsland.reload.l4.tex = "t2";
		rIsland.reload.l4.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l5.label = "Boca de Hubon";
		rIsland.reload.l5.name = "reload_4";
		rIsland.reload.l5.go = "Hispaniola_shore_02";
		rIsland.reload.l5.emerge = "Reload1";
		rIsland.reload.l5.radius = 200.0;
		rIsland.reload.l5.pic = 1;
		rIsland.reload.l5.tex = "t2";
		rIsland.reload.l5.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l6.label = "Cape Francos";
		rIsland.reload.l6.name = "reload_5";
		rIsland.reload.l6.go = "Hispaniola_shore_03";
		rIsland.reload.l6.emerge = "see";
		rIsland.reload.l6.radius = 200.0;
		rIsland.reload.l6.pic = 2;
		rIsland.reload.l6.tex = "t2";
		rIsland.reload.l6.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l7.label = "Ile a Vache";
		rIsland.reload.l7.name = "reload_9";
		rIsland.reload.l7.go = "Hispaniola_shore_04";
		rIsland.reload.l7.emerge = "Reload1";
		rIsland.reload.l7.radius = 200.0;
		rIsland.reload.l7.pic = 3;
		rIsland.reload.l7.tex = "t2";
		rIsland.reload.l7.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l8.label = "#stown_name# Fort"; // KK
		rIsland.reload.l8.name = "reload1_2";
		rIsland.reload.l8.go = "Fort"; // KK
		rIsland.reload.l8.GoAfterBoard.location = "reload_1";
		rIsland.reload.l8.emerge = "see";
		rIsland.reload.l8.radius = 250.0;
		rIsland.reload.l8.commander = "Port au Prince Commander"; // KK
		rIsland.reload.l8.fort.model = "Gaity_fort2";
		rIsland.reload.l8.fort.locators = "Gaity_fort2_locators";
		rIsland.reload.l8.pic = 22;
		rIsland.reload.l8.tex = "t1";
		rIsland.reload.l8.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l9.label = "#stown_name# Fort"; // KK
		rIsland.reload.l9.name = "reload_8";
		rIsland.reload.l9.go = "Fort"; // KK
		rIsland.reload.l9.GoAfterBoard.location = "reload_3";
		rIsland.reload.l9.emerge = "see";
		rIsland.reload.l9.radius = 250.0;
		rIsland.reload.l9.commander = "Santo Domingo Commander"; // KK
		rIsland.reload.l9.fort.model = "Gaity_fort3";
		rIsland.reload.l9.fort.locators = "Gaity_fort3_locators";
		rIsland.reload.l9.pic = 22;
		rIsland.reload.l9.tex = "t1";
		rIsland.reload.l9.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l10.label = "#stown_name# Fort"; // KK
		rIsland.reload.l10.name = "reload_6";
		rIsland.reload.l10.go = "Fort"; // KK
		rIsland.reload.l10.GoAfterBoard.location = "reload_7";
		rIsland.reload.l10.emerge = "see";
		rIsland.reload.l10.radius = 250.0;
		rIsland.reload.l10.commander = "Tortuga Commander"; // KK
		rIsland.reload.l10.fort.model = "Gaity_fort1";
		rIsland.reload.l10.fort.locators = "Gaity_fort1_locators";
		rIsland.reload.l10.pic = 22;
		rIsland.reload.l10.tex = "t1";
		rIsland.reload.l10.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.InterfaceTextures.t1 = "battle_interface\moor-town.tga";
		rIsland.InterfaceTextures.t1.h = 4;
		rIsland.InterfaceTextures.t1.v = 16;
		rIsland.InterfaceTextures.t2 = "battle_interface\moor-shores.tga";
		rIsland.InterfaceTextures.t2.h = 4;
		rIsland.InterfaceTextures.t2.v = 16;

		rIsland.Trade.Export.id1 = GOOD_EBONY;
		rIsland.Trade.Export.id2 = GOOD_MAHOGANY;
		rIsland.Trade.Export.id3 = GOOD_CINNAMON;
		rIsland.Trade.Export.id4 = GOOD_SANDAL;
		rIsland.Trade.Export.id5 = GOOD_GOLD;
		rIsland.Trade.Export.id6 = GOOD_SILVER;
		rIsland.Trade.Import.id1 = GOOD_PLANKS;
		rIsland.Trade.Import.id2 = GOOD_SAILCLOTH;
		rIsland.Trade.Import.id3 = GOOD_SUGAR;
		rIsland.Trade.Import.id4 = GOOD_LINEN;
		rIsland.Trade.Import.id5 = GOOD_TREATMENT;
		rIsland.Trade.Contraband.id1 = GOOD_ALE;
		rIsland.Trade.Contraband.id2 = GOOD_SILK;
		rIsland.Trade.Contraband.id3 = GOOD_TOBACCO;

		AddIsland(q, rIsland, locator);

	// ==================================================================================================
	// Cuba
		rIsland.id = "Cuba";
		rIsland.model = "Cuba";
		rIsland.filespath.models = "islands\Cuba";
		rIsland.refl_model = "Cuba_refl";
		rIsland.locators = "Cuba_locators";
		rIsland.visible = true;
		rIsland.smuggling_nation = SPAIN;
		// NK -->
		rIsland.towns.quantity = 2;
		rIsland.towns.1 = "Santiago";
		rIsland.towns.2 = "Havana";
		// NK <--

		rIsland.reload.l1.label = "#stown_name#"; // KK
		rIsland.reload.l1.name = "reload_1";
		rIsland.reload.l1.go = "Santiago_port"; // KK
		rIsland.reload.l1.emerge = "reload2"; // KK
		rIsland.reload.l1.radius = 200.0;
		rIsland.reload.l1.pic = 23;
		rIsland.reload.l1.tex = "t1";
		rIsland.reload.l1.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l2.label = "#stown_name#"; // KK
		rIsland.reload.l2.name = "reload_3";
		rIsland.reload.l2.go = "Cuba_Port";
		rIsland.reload.l2.emerge = "sea_2";
		rIsland.reload.l2.radius = 200.0;
		rIsland.reload.l2.pic = 24;
		rIsland.reload.l2.tex = "t1";
        rIsland.reload.l2.ships.l0.ay = 3.0;        // LDH 11Dec16
		rIsland.reload.l2.goto_enable = false; // Screwface: Disable Sail-To

// KK -->
		rIsland.reload.l3.label = "Bahia de San Antonio";
		rIsland.reload.l3.name = "reload_2";
		rIsland.reload.l3.go = "Cuba_shore_01";
		rIsland.reload.l3.emerge = "reload1";
		rIsland.reload.l3.radius = 200.0;
		rIsland.reload.l3.pic = 21;
		rIsland.reload.l3.tex = "t2";
		rIsland.reload.l3.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l4.label = "Bahia de Moa";
		rIsland.reload.l4.name = "reload_5";
		rIsland.reload.l4.go = "Cuba_shore_02";
		rIsland.reload.l4.emerge = "Reload2";
		rIsland.reload.l4.radius = 200.0;
		rIsland.reload.l4.pic = 15;
		rIsland.reload.l4.tex = "t2";
		rIsland.reload.l4.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l5.label = "Peninsula de Zapata";
		rIsland.reload.l5.name = "reload_6";
		rIsland.reload.l5.go = "Cuba_Shore_06";
		rIsland.reload.l5.emerge = "Reload1";
		rIsland.reload.l5.radius = 200.0;
		rIsland.reload.l5.pic = 10;
		rIsland.reload.l5.tex = "t1";
		rIsland.reload.l5.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l6.label = "Punta de Maisi";
		rIsland.reload.l6.name = "reload_7";
		rIsland.reload.l6.go = "Cuba_Shore_03";
		rIsland.reload.l6.emerge = "Reload1";
		rIsland.reload.l6.radius = 200.0;
		rIsland.reload.l6.pic = 34;
		rIsland.reload.l6.tex = "t2";
		rIsland.reload.l6.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l7.label = "Playa de Sierra Maestra";
		rIsland.reload.l7.name = "reload_8";
		rIsland.reload.l7.go = "Cuba_Shore_05";
		rIsland.reload.l7.emerge = "Reload1";
		rIsland.reload.l7.radius = 200.0;
		rIsland.reload.l7.pic = 27;
		rIsland.reload.l7.tex = "t2";
//		rIsland.reload.l7.enable = false;
		rIsland.reload.l7.goto_enable = false; // PB

		rIsland.reload.l8.label = "Playa de Sabana";
		rIsland.reload.l8.name = "reload_9";
		rIsland.reload.l8.go = "Cuba_Shore_04";
		rIsland.reload.l8.emerge = "Reload1";
		rIsland.reload.l8.radius = 200.0;
		rIsland.reload.l8.pic = 35;
		rIsland.reload.l8.tex = "t2";
		rIsland.reload.l8.goto_enable = false; // Screwface: Disable Sail-To
// <-- KK

		rIsland.reload.l9.label = "#stown_name# Fort"; // KK
		rIsland.reload.l9.name = "reload1_2";
		rIsland.reload.l9.go = "Fort"; // KK
		rIsland.reload.l9.GoAfterBoard.location = "reload_1";
		rIsland.reload.l9.emerge = "see";
		rIsland.reload.l9.radius = 250.0;
		rIsland.reload.l9.commander = "Santiago Commander"; // KK
		rIsland.reload.l9.fort.model = "Cuba_fort2";
		rIsland.reload.l9.fort.locators = "Cuba_fort2_locators";
		rIsland.reload.l9.pic = 22;
		rIsland.reload.l9.tex = "t1";
		rIsland.reload.l9.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l10.label = "#stown_name# Fort"; // KK
		rIsland.reload.l10.name = "reload_4";
		rIsland.reload.l10.go = "Fort"; // KK
		rIsland.reload.l10.GoAfterBoard.location = "reload_3";
		rIsland.reload.l10.emerge = "see";
		rIsland.reload.l10.radius = 250.0;
		rIsland.reload.l10.commander = "Havana Commander"; // KK
		rIsland.reload.l10.fort.model = "Cuba_fort1";
		rIsland.reload.l10.fort.locators = "Cuba_fort1_locators";
		rIsland.reload.l10.pic = 22;
		rIsland.reload.l10.tex = "t1";
		rIsland.reload.l10.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.InterfaceTextures.t1 = "battle_interface\moor-town.tga";
		rIsland.InterfaceTextures.t1.h = 4;
		rIsland.InterfaceTextures.t1.v = 16;
		rIsland.InterfaceTextures.t2 = "battle_interface\moor-shores.tga";
		rIsland.InterfaceTextures.t2.h = 4;
		rIsland.InterfaceTextures.t2.v = 16;

		rIsland.Trade.Export.id1 = GOOD_EBONY;
		rIsland.Trade.Export.id2 = GOOD_MAHOGANY;
		rIsland.Trade.Export.id3 = GOOD_CINNAMON;
		rIsland.Trade.Export.id4 = GOOD_SANDAL;
		rIsland.Trade.Import.id1 = GOOD_PLANKS;
		rIsland.Trade.Import.id2 = GOOD_SAILCLOTH;
		rIsland.Trade.Import.id3 = GOOD_SUGAR;
		rIsland.Trade.Import.id4 = GOOD_LINEN;
		rIsland.Trade.Import.id5 = GOOD_TREATMENT;
		rIsland.Trade.Contraband.id1 = GOOD_ALE;
		rIsland.Trade.Contraband.id2 = GOOD_SILK;
		rIsland.Trade.Contraband.id3 = GOOD_TOBACCO;

		AddIsland(q, rIsland, locator);

	// ==================================================================================================
	// Guadeloupe
		rIsland.id = "Guadeloupe";
		rIsland.model = "Guadelupa";
		rIsland.filespath.models = "islands\Guadelupa";
		rIsland.refl_model = "Guadelupa_refl";
		rIsland.locators = "Guadelupa_locators";
		rIsland.visible = true;
		rIsland.smuggling_nation = FRANCE;
		// NK -->
		rIsland.towns.quantity = 1;
		rIsland.towns.1 = "Pointe a Pitre";
		// NK <--

		rIsland.reload.l1.label = "#stown_name#"; // KK
		rIsland.reload.l1.name = "reload_2";
		rIsland.reload.l1.go = "Guadeloupe_Port";
		rIsland.reload.l1.emerge = "reload2_back";
		rIsland.reload.l1.radius = 200.0;
		rIsland.reload.l1.pic = 14;
		rIsland.reload.l1.tex = "t1";
		rIsland.reload.l1.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l2.label = "Anse Casse-Bois";
		rIsland.reload.l2.name = "reload_3";
		rIsland.reload.l2.go = "Guadeloupe_shore_01";
		rIsland.reload.l2.emerge = "see";
		rIsland.reload.l2.radius = 200.0;
		rIsland.reload.l2.pic = 20;
		rIsland.reload.l2.tex = "t2";
		rIsland.reload.l2.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l3.label = "#stown_name# Fort"; // KK
		rIsland.reload.l3.name = "reload_1";
		rIsland.reload.l3.go = "Fort"; // KK
		rIsland.reload.l3.GoAfterBoard.location = "reload_2";
		rIsland.reload.l3.emerge = "see";
		rIsland.reload.l3.radius = 250.0;
		rIsland.reload.l3.commander = "Pointe a Pitre Commander"; // KK
		rIsland.reload.l3.fort.model = "Guadelupa_fort1";
		rIsland.reload.l3.fort.locators = "Guadelupa_fort1_locators";
		rIsland.reload.l3.pic = 22;
		rIsland.reload.l3.tex = "t1";
		rIsland.reload.l3.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.InterfaceTextures.t1 = "battle_interface\moor-town.tga";
		rIsland.InterfaceTextures.t1.h = 4;
		rIsland.InterfaceTextures.t1.v = 16;
		rIsland.InterfaceTextures.t2 = "battle_interface\moor-shores.tga";
		rIsland.InterfaceTextures.t2.h = 4;
		rIsland.InterfaceTextures.t2.v = 16;

		rIsland.Trade.Export.id1 = GOOD_SAILCLOTH;
		rIsland.Trade.Export.id2 = GOOD_CHOCOLATE;
		rIsland.Trade.Export.id3 = GOOD_LINEN;
		rIsland.Trade.Export.id4 = GOOD_SILK;
		rIsland.Trade.Import.id1 = GOOD_PLANKS;
		rIsland.Trade.Import.id2 = GOOD_EBONY;
		rIsland.Trade.Import.id3 = GOOD_RUM;
		rIsland.Trade.Import.id4 = GOOD_LEATHER;
		rIsland.Trade.Import.id5 = GOOD_GOLD;
		rIsland.Trade.Import.id6 = GOOD_SILVER;
		rIsland.Trade.Contraband.id1 = GOOD_SANDAL;
		rIsland.Trade.Contraband.id2 = GOOD_FRUITS;
		rIsland.Trade.Contraband.id3 = GOOD_CINNAMON;

		AddIsland(q, rIsland, locator);

	// ==================================================================================================
	// Saint Martin (SENT)	// changed by ccc Feb 06
		rIsland.id = "SaintMartin";
		rIsland.model = "sent";
		rIsland.filespath.models = "islands\sent";
		rIsland.refl_model = "sent_refl";
		rIsland.locators = "sent_locators";
		rIsland.visible = true;
		rIsland.smuggling_nation = HOLLAND;
		// NK -->
		rIsland.towns.quantity = 2;
		rIsland.towns.1 = "Philipsburg";
		rIsland.towns.2 = "Marigot";
		// NK <--

		rIsland.reload.l1.label = "#stown_name#"; // KK
		rIsland.reload.l1.name = "reload_1";
		rIsland.reload.l1.go = "Philipsburg_port";
		rIsland.reload.l1.emerge = "reload1";
		rIsland.reload.l1.radius = 200.0;
		rIsland.reload.l1.pic = 11;
		rIsland.reload.l1.tex = "t1";
        rIsland.reload.l1.ships.l0.ay = 2.0;        // LDH 11Dec16
		rIsland.reload.l1.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l2.label = "Fort Amsterdam";
		rIsland.reload.l2.name = "reload1_2";
		rIsland.reload.l2.go = "Fort"; // KK
		rIsland.reload.l2.GoAfterBoard.location = "reload_1";
		rIsland.reload.l2.emerge = "see";
		rIsland.reload.l2.radius = 250.0;
		rIsland.reload.l2.commander = "Philipsburg Commander"; // KK
		rIsland.reload.l2.fort.model = "Sent_fort1";
		rIsland.reload.l2.fort.locators = "Sent_fort1_locators";
		rIsland.reload.l2.pic = 22;
		rIsland.reload.l2.tex = "t1";
		rIsland.reload.l2.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l3.label = "#stown_name#"; // KK
		rIsland.reload.l3.name = "reload_3";
		rIsland.reload.l3.go = "Marigot_port";
		rIsland.reload.l3.emerge = "sea";
		rIsland.reload.l3.radius = 200.0;
		rIsland.reload.l3.pic = 12;
		rIsland.reload.l3.tex = "t1";
        rIsland.reload.l3.ships.l0.ay = -1.3;       // LDH 11Dec16
		rIsland.reload.l3.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l4.label = "Fort St Louis";
		rIsland.reload.l4.name = "reload_5";
		rIsland.reload.l4.go = "Fort"; // KK
		rIsland.reload.l4.GoAfterBoard.location = "reload_1";
		rIsland.reload.l4.emerge = "see";
		rIsland.reload.l4.radius = 250.0;
		rIsland.reload.l4.commander = "Marigot Commander"; // KK
		rIsland.reload.l4.fort.model = "Sent_fort2";
		rIsland.reload.l4.fort.locators = "Sent_fort2_locators";
		rIsland.reload.l4.pic = 22;
		rIsland.reload.l4.tex = "t1";
		rIsland.reload.l4.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l5.label = "Simpson Bay";
		rIsland.reload.l5.name = "reload_2";
		rIsland.reload.l5.go = "SaintMartin_shore_01";
		rIsland.reload.l5.emerge = "reload1";
		rIsland.reload.l5.radius = 200.0;
		rIsland.reload.l5.pic = 17;
		rIsland.reload.l5.tex = "t2";
		rIsland.reload.l5.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l6.label = "Baie Orient";
		rIsland.reload.l6.name = "reload_4";
		rIsland.reload.l6.go = "SaintMartin_shore_02";
		rIsland.reload.l6.emerge = "see";	// Akella's spelling ;)
		rIsland.reload.l6.radius = 200.0;
		rIsland.reload.l6.pic = 18;
		rIsland.reload.l6.tex = "t2";
		rIsland.reload.l6.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.InterfaceTextures.t1 = "battle_interface\moor-town.tga";
		rIsland.InterfaceTextures.t1.h = 4;
		rIsland.InterfaceTextures.t1.v = 16;
		rIsland.InterfaceTextures.t2 = "battle_interface\moor-shores.tga";
		rIsland.InterfaceTextures.t2.h = 4;
		rIsland.InterfaceTextures.t2.v = 16;

		rIsland.Trade.Export.id1 = GOOD_SAILCLOTH;
		rIsland.Trade.Export.id2 = GOOD_CHOCOLATE;
		rIsland.Trade.Export.id3 = GOOD_LINEN;
		rIsland.Trade.Export.id4 = GOOD_SILK;
		rIsland.Trade.Export.id5 = GOOD_GOLD;
		rIsland.Trade.Export.id6 = GOOD_SILVER;
		rIsland.Trade.Import.id1 = GOOD_PLANKS;
		rIsland.Trade.Import.id2 = GOOD_EBONY;
		rIsland.Trade.Import.id3 = GOOD_RUM;
		rIsland.Trade.Import.id4 = GOOD_LEATHER;
		rIsland.Trade.Contraband.id1 = GOOD_SANDAL;
		rIsland.Trade.Contraband.id2 = GOOD_FRUITS;
		rIsland.Trade.Contraband.id3 = GOOD_CINNAMON; // KK

		AddIsland(q, rIsland, locator);

	// ==================================================================================================
	// Antigua	changed by ccc Jan 06
		rIsland.id = "Antigua";
		rIsland.model = "Antigua";
		rIsland.filespath.models = "islands\Antigua";
		rIsland.refl_model = "Antigua_refl";
		rIsland.locators = "Antigua_locators";
		rIsland.visible = true;
		rIsland.smuggling_nation = ENGLAND;
		// NK -->
		rIsland.towns.quantity = 1;
		rIsland.towns.1 = "St John's";
		// NK <--

		rIsland.reload.l1.label = "Fort James";
		rIsland.reload.l1.name = "reload_1";
		rIsland.reload.l1.go = "Fort"; // KK
		rIsland.reload.l1.GoAfterBoard.location = "reload_2";
		rIsland.reload.l1.emerge = "see";
		rIsland.reload.l1.radius = 250.0;
		rIsland.reload.l1.commander = "St John's Commander"; // KK
		rIsland.reload.l1.fort.model = "Antigua_fort1";
		rIsland.reload.l1.fort.locators = "Antigua_fort1_locators";
		rIsland.reload.l1.pic = 22;
		rIsland.reload.l1.tex = "t1";
		rIsland.reload.l1.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l2.label = "#stown_name#"; // KK
		rIsland.reload.l2.name = "reload_2";
		rIsland.reload.l2.go = "Antigua_port";
		rIsland.reload.l2.emerge = "sea_2";
		rIsland.reload.l2.radius = 200.0;
		rIsland.reload.l2.pic = 13;
		rIsland.reload.l2.tex = "t1";
		rIsland.reload.l2.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l3.label = "Muscetto Cove";
		rIsland.reload.l3.name = "reload_3";
		rIsland.reload.l3.go = "Antigua_shore";
		rIsland.reload.l3.emerge = "reload1";
		rIsland.reload.l3.radius = 200.0;
		rIsland.reload.l3.pic = 19;
		rIsland.reload.l3.tex = "t2";
		rIsland.reload.l3.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.InterfaceTextures.t1 = "battle_interface\moor-town.tga";
		rIsland.InterfaceTextures.t1.h = 4;
		rIsland.InterfaceTextures.t1.v = 16;
		rIsland.InterfaceTextures.t2 = "battle_interface\moor-shores.tga";
		rIsland.InterfaceTextures.t2.h = 4;
		rIsland.InterfaceTextures.t2.v = 16;

		// victualler stores only ship supplies
		rIsland.Trade.Contraband.id1 = GOOD_CHOCOLATE;
		rIsland.Trade.Contraband.id2 = GOOD_SILK;
		rIsland.Trade.Contraband.id3 = GOOD_LEATHER;
		rIsland.Trade.Contraband.id4 = GOOD_EBONY;
		rIsland.Trade.Contraband.id5 = GOOD_COFFEE;
		rIsland.Trade.Contraband.id6 = GOOD_PAPRIKA;
		rIsland.Trade.Contraband.id7 = GOOD_SANDAL;
		rIsland.Trade.Contraband.id8 = GOOD_FRUITS;
		rIsland.Trade.Contraband.id9 = GOOD_CINNAMON;
		rIsland.Trade.Contraband.id10 = GOOD_TOBACCO;
		rIsland.Trade.Contraband.id11 = GOOD_ALE;
		rIsland.Trade.Contraband.id12 = GOOD_OIL;
		rIsland.Trade.Contraband.id13 = GOOD_COPRA;
		rIsland.Trade.Contraband.id14 = GOOD_WINE;
		rIsland.Trade.Contraband.id15 = GOOD_MAHOGANY;
		rIsland.Trade.Contraband.id16 = GOOD_SUGAR;
		rIsland.Trade.Contraband.id17 = GOOD_COTTON;
		rIsland.Trade.Contraband.id18 = GOOD_CLOTHES;
		rIsland.Trade.Contraband.id19 = GOOD_LINEN;
		rIsland.Trade.Contraband.id20 = GOOD_TREATMENT;

		AddIsland(q, rIsland, locator);

	// ==================================================================================================
	// Turks
		rIsland.id = "Turks";
		rIsland.model = "Terks";
		rIsland.filespath.models = "islands\Terks";
		rIsland.refl_model = "Terks_refl";
		rIsland.locators = "Terks_locators";
		rIsland.visible = true;
		rIsland.smuggling_nation = ENGLAND; // PB: Pirates as Coastguard?
// KK -->
		rIsland.towns.quantity = 1;
		rIsland.towns.1 = "Grand Turk";
// KK <--

		rIsland.reload.l1.label = "#stown_name#"; // KK
		rIsland.reload.l1.name = "reload_1";
		rIsland.reload.l1.go = "Turks_Port";
		rIsland.reload.l1.emerge = "Reload1";
		rIsland.reload.l1.radius = 200.0;
		rIsland.reload.l1.pic = 10;
		rIsland.reload.l1.tex = "t1";
		rIsland.reload.l1.ships.l0.ay = 3.0;    // LDH 11Dec16
		rIsland.reload.l1.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l2.label = "Turtle Bay";
		rIsland.reload.l2.name = "reload_2";
		rIsland.reload.l2.go = "Turks_Lighthouse";
		rIsland.reload.l2.emerge = "reload3";
		rIsland.reload.l2.radius = 200.0;
		rIsland.reload.l2.pic = 4;
		rIsland.reload.l2.tex = "t2";
		rIsland.reload.l2.ships.l0.ay = 3.0;    // LDH 12Dec16
		rIsland.reload.l2.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l3.label = "White reefs";
		rIsland.reload.l3.name = "reload_3";
		rIsland.reload.l3.go = "Turks_shore_01";
		rIsland.reload.l3.emerge = "reload1";
		rIsland.reload.l3.radius = 200.0;
		rIsland.reload.l3.pic = 5;
		rIsland.reload.l3.tex = "t2";
		rIsland.reload.l3.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l4.label = "Sandy Point";
		rIsland.reload.l4.name = "reload_4";
		rIsland.reload.l4.go = "Turks_Shore_04";
		rIsland.reload.l4.emerge = "reload3";
		rIsland.reload.l4.radius = 200.0;
		rIsland.reload.l4.pic = 6;
		rIsland.reload.l4.tex = "t2";
		rIsland.reload.l4.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l5.label = "Birds Cove";
		rIsland.reload.l5.name = "reload_5";
		rIsland.reload.l5.go = "Turks_shore_05";
		rIsland.reload.l5.emerge = "see";
		rIsland.reload.l5.radius = 200.0;
		rIsland.reload.l5.pic = 7;
		rIsland.reload.l5.tex = "t2";
		rIsland.reload.l5.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l6.label = "#stown_name# Fort"; // KK
		rIsland.reload.l6.name = "reload1_2";
		rIsland.reload.l6.go = "Fort"; // KK
		rIsland.reload.l6.GoAfterBoard.location = "reload_1";
		rIsland.reload.l6.emerge = "see";
		rIsland.reload.l6.radius = 250.0;
		rIsland.reload.l6.commander = "Grand Turk Commander"; // KK
		rIsland.reload.l6.fort.model = "Terks_fort1";
		rIsland.reload.l6.fort.locators = "Terks_fort1_locators";
		rIsland.reload.l6.pic = 22;
		rIsland.reload.l6.tex = "t1";
		rIsland.reload.l6.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.InterfaceTextures.t1 = "battle_interface\moor-town.tga";
		rIsland.InterfaceTextures.t1.h = 4;
		rIsland.InterfaceTextures.t1.v = 16;
		rIsland.InterfaceTextures.t2 = "battle_interface\moor-shores.tga";
		rIsland.InterfaceTextures.t2.h = 4;
		rIsland.InterfaceTextures.t2.v = 16;

// KK -->
		rIsland.Trade.Export.id1 = GOOD_RUM;
		rIsland.Trade.Export.id2 = GOOD_WINE;
		rIsland.Trade.Export.id3 = GOOD_LEATHER;
		rIsland.Trade.Export.id4 = GOOD_FRUITS;
		rIsland.Trade.Import.id1 = GOOD_SUGAR;
		rIsland.Trade.Import.id2 = GOOD_TREATMENT;
		rIsland.Trade.Import.id3 = GOOD_GOLD;
		rIsland.Trade.Import.id4 = GOOD_SILVER;
// <-- KK

		AddIsland(q, rIsland, locator);

// KK -->
	// ==================================================================================================
	// Curacao
		rIsland.id = "Curacao";
		rIsland.model = "Curacao";
		rIsland.filespath.models = "islands\Curacao";
		rIsland.refl_model = "Curacao_refl";
		rIsland.locators = "Curacao_locators";
		rIsland.visible = true;
		rIsland.smuggling_nation = HOLLAND;
		// NK -->
		rIsland.towns.quantity = 1;
		rIsland.towns.1 = "Willemstad";
		// NK <--

		rIsland.reload.l1.label = "#stown_name# Port"; // KK
		rIsland.reload.l1.name = "reload_1";
		rIsland.reload.l1.go = "Willemstad_port";
		rIsland.reload.l1.emerge = "sea";
		rIsland.reload.l1.radius = 200.0;
		rIsland.reload.l1.pic = 20;
		rIsland.reload.l1.tex = "t1";
		rIsland.reload.l1.ships.l0.ay = 3.14;		// LDH fix until the locators.gm file can be updated - 19Apr09
		rIsland.reload.l1.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l2.label = "Bullen Bay";
		rIsland.reload.l2.name = "reload_2";
		rIsland.reload.l2.go = "Curacao_shore_01";
		rIsland.reload.l2.emerge = "see";
		rIsland.reload.l2.radius = 200.0;
		rIsland.reload.l2.pic = 29;
		rIsland.reload.l2.tex = "t2";
		rIsland.reload.l2.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l3.label = "Bocht Van Hato";
		rIsland.reload.l3.name = "reload_3";
		rIsland.reload.l3.go = "Curacao_shore_02";
		rIsland.reload.l3.emerge = "reload1";
		rIsland.reload.l3.radius = 200.0;
		rIsland.reload.l3.pic = 25;
		rIsland.reload.l3.tex = "t2";
		rIsland.reload.l3.enable = false;
		rIsland.reload.l3.goto_enable = false; // PB

		rIsland.reload.l4.label = "#stown_name# Fort"; // KK
		rIsland.reload.l4.name = "reload_fort1";
		rIsland.reload.l4.go = "Fort"; // KK
		rIsland.reload.l4.GoAfterBoard.location = "reload_1";
		rIsland.reload.l4.emerge = "see";
		rIsland.reload.l4.radius = 250.0;
		rIsland.reload.l4.commander = "Willemstad Commander"; // KK
		rIsland.reload.l4.fort.model = "Curacao_fort1";
		rIsland.reload.l4.fort.locators = "Curacao_fort1_locators";
		rIsland.reload.l4.pic = 22;
		rIsland.reload.l4.tex = "t1";
		rIsland.reload.l4.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.InterfaceTextures.t1 = "battle_interface\moor-town.tga";
		rIsland.InterfaceTextures.t1.h = 4;
		rIsland.InterfaceTextures.t1.v = 16;
		rIsland.InterfaceTextures.t2 = "battle_interface\moor-shores.tga";
		rIsland.InterfaceTextures.t2.h = 4;
		rIsland.InterfaceTextures.t2.v = 16;

		rIsland.Trade.Export.id1 = GOOD_TOBACCO;
		rIsland.Trade.Export.id2 = GOOD_COFFEE;
		rIsland.Trade.Export.id3 = GOOD_COPRA;
		rIsland.Trade.Export.id4 = GOOD_ALE;
		rIsland.Trade.Export.id5 = GOOD_FOOD;
		rIsland.Trade.Export.id6 = GOOD_TREATMENT;
		rIsland.Trade.Import.id1 = GOOD_PLANKS;
		rIsland.Trade.Import.id2 = GOOD_SAILCLOTH;
		rIsland.Trade.Import.id3 = GOOD_WHEAT;
		rIsland.Trade.Import.id4 = GOOD_GOLD;
		rIsland.Trade.Import.id5 = GOOD_SILVER;
		rIsland.Trade.Contraband.id1 = GOOD_SUGAR;
		rIsland.Trade.Contraband.id2 = GOOD_LINEN;
		rIsland.Trade.Contraband.id3 = GOOD_WINE;

		AddIsland(q, rIsland, locator);

	// ==================================================================================================
	// Eleuthera
		rIsland.id = "Eleuthera";
		rIsland.model = "Eleuthera";
		rIsland.filespath.models = "islands\Eleuthera";
		rIsland.refl_model = "Eleuthera_refl";
		rIsland.locators = "Eleuthera_locators";
		rIsland.visible = true;
		rIsland.smuggling_nation = ENGLAND;
		// NK -->
		rIsland.towns.quantity = 2;
		rIsland.towns.1 = "Eleuthera";
		rIsland.towns.2 = "Alice";
		// NK <--

		rIsland.reload.l1.label = "#stown_name# Port";
		rIsland.reload.l1.name = "reload_1";
		rIsland.reload.l1.go = "Eleuthera_Port";
		rIsland.reload.l1.emerge = "reload1";
		rIsland.reload.l1.radius = 200.0;
		rIsland.reload.l1.pic = 4;
		rIsland.reload.l1.tex = "t1";
		rIsland.reload.l1.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l2.label = "#stown_name# Fort";
		rIsland.reload.l2.name = "reload_fort1";
		rIsland.reload.l2.go = "Fort"; // KK
		rIsland.reload.l2.GoAfterBoard.location = "reload_1";
		rIsland.reload.l2.emerge = "see";
		rIsland.reload.l2.radius = 250.0;
		rIsland.reload.l2.commander = "Eleuthera Commander";
		rIsland.reload.l2.fort.model = "Eleuthera_fort1";
		rIsland.reload.l2.fort.locators = "Eleuthera_fort1_locators";
		rIsland.reload.l2.pic = 22;
		rIsland.reload.l2.tex = "t1";
		rIsland.reload.l2.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l3.label = "#stown_name# Port";
		rIsland.reload.l3.name = "reload_3";
		rIsland.reload.l3.go = "Alice_Port";
		rIsland.reload.l3.emerge = "reload61";
		rIsland.reload.l3.radius = 200.0;
		rIsland.reload.l3.pic = 5;
		rIsland.reload.l3.tex = "t1";
		rIsland.reload.l3.goto_enable = false; // Screwface: Disable Sail-To

		//JRH
		rIsland.reload.l4.label = "Citadel Rock";
		rIsland.reload.l4.name = "reload_4";
		rIsland.reload.l4.go = "Eleuthera_shore";
		rIsland.reload.l4.emerge = "reload2";
		rIsland.reload.l4.radius = 300.0;
		rIsland.reload.l4.pic = 15;
		rIsland.reload.l4.tex = "t2";
		rIsland.reload.l4.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.InterfaceTextures.t1 = "battle_interface\moor-town.tga";
		rIsland.InterfaceTextures.t1.h = 4;
		rIsland.InterfaceTextures.t1.v = 16;
		rIsland.InterfaceTextures.t2 = "battle_interface\moor-shores.tga";
		rIsland.InterfaceTextures.t2.h = 4;
		rIsland.InterfaceTextures.t2.v = 16;

		rIsland.Trade.Export.id1 = GOOD_TOBACCO;
		rIsland.Trade.Export.id2 = GOOD_COFFEE;
		rIsland.Trade.Export.id3 = GOOD_COPRA;
		rIsland.Trade.Export.id4 = GOOD_ALE;
		rIsland.Trade.Export.id5 = GOOD_FOOD;
		rIsland.Trade.Export.id6 = GOOD_TREATMENT;
		rIsland.Trade.Import.id1 = GOOD_PLANKS;
		rIsland.Trade.Import.id2 = GOOD_SAILCLOTH;
		rIsland.Trade.Import.id3 = GOOD_WHEAT;
		rIsland.Trade.Import.id4 = GOOD_GOLD;
		rIsland.Trade.Import.id5 = GOOD_SILVER;
		rIsland.Trade.Import.id6 = GOOD_OIL;
		rIsland.Trade.Import.id7 = GOOD_BRICKS;
		rIsland.Trade.Import.id8 = GOOD_CLOTHES;
		rIsland.Trade.Contraband.id1 = GOOD_SUGAR;
		rIsland.Trade.Contraband.id2 = GOOD_LINEN;
		rIsland.Trade.Contraband.id3 = GOOD_WINE;

		AddIsland(q, rIsland, locator);

	// ==================================================================================================
	// Aruba
		rIsland.id = "Aruba";
		rIsland.model = "Aruba";
		rIsland.filespath.models = "islands\Aruba";
		rIsland.refl_model = "Aruba_refl";
		rIsland.locators = "Aruba_locators";
		rIsland.visible = true;
		rIsland.smuggling_nation = HOLLAND;
		// NK -->
		rIsland.towns.quantity = 1;
		rIsland.towns.1 = "Oranjestad";
		// NK <--

		rIsland.reload.l1.label = "#stown_name# Port";
		rIsland.reload.l1.name = "reload_1";
		rIsland.reload.l1.go = "Oranjestad_port";
		rIsland.reload.l1.emerge = "reload1";
		rIsland.reload.l1.radius = 200.0;
		rIsland.reload.l1.pic = 10;
		rIsland.reload.l1.tex = "t1";
		rIsland.reload.l1.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l2.label = "Rocky Cove";
		rIsland.reload.l2.name = "reload_3";
		rIsland.reload.l2.go = "Aruba_shore";
		rIsland.reload.l2.emerge = "see";
		rIsland.reload.l2.radius = 200.0;
		rIsland.reload.l2.pic = 30;
		rIsland.reload.l2.tex = "t2";
		rIsland.reload.l2.goto_enable = false; // Screwface: Disable Sail-To

		/*rIsland.reload.l3.label = "#stown_name# Fort";
		rIsland.reload.l3.name = "reload_1";
		rIsland.reload.l3.go = "Fort"; // KK
		rIsland.reload.l3.GoAfterBoard.location = "reload_2";
		rIsland.reload.l3.emerge = "see";
		rIsland.reload.l3.radius = 250.0;
		rIsland.reload.l3.commander = "Oranjestad Commander"; // KK
		rIsland.reload.l3.fort.model = "Aruba_fort1";
		rIsland.reload.l3.fort.locators = "Aruba_fort1_locators";
		rIsland.reload.l3.pic = 1;
		rIsland.reload.l3.tex = "t1";
		rIsland.reload.l3.ships.l0.x = -5.0;
		rIsland.reload.l3.ships.l0.z = -150.0;
		rIsland.reload.l3.ships.l0.ay = 0.0;
		rIsland.reload.l3.goto_enable = false; // Screwface: Disable Sail-To*/

		rIsland.InterfaceTextures.t1 = "battle_interface\moor-town.tga";
		rIsland.InterfaceTextures.t1.h = 4;
		rIsland.InterfaceTextures.t1.v = 16;
		rIsland.InterfaceTextures.t2 = "battle_interface\moor-shores.tga";
		rIsland.InterfaceTextures.t2.h = 4;
		rIsland.InterfaceTextures.t2.v = 16;

		rIsland.Trade.Export.id1 = GOOD_TOBACCO;
		rIsland.Trade.Export.id2 = GOOD_COFFEE;
		rIsland.Trade.Export.id3 = GOOD_COPRA;
		rIsland.Trade.Export.id4 = GOOD_ALE;
		rIsland.Trade.Export.id5 = GOOD_FOOD;
		rIsland.Trade.Export.id6 = GOOD_TREATMENT;
		rIsland.Trade.Import.id1 = GOOD_PLANKS;
		rIsland.Trade.Import.id2 = GOOD_SAILCLOTH;
		rIsland.Trade.Import.id3 = GOOD_WHEAT;
		rIsland.Trade.Import.id4 = GOOD_GOLD;
		rIsland.Trade.Import.id5 = GOOD_SILVER;
		rIsland.Trade.Contraband.id1 = GOOD_SUGAR;
		rIsland.Trade.Contraband.id2 = GOOD_LINEN;
		rIsland.Trade.Contraband.id3 = GOOD_WINE;

		AddIsland(q, rIsland, locator);
// <-- KK

	// ==================================================================================================
	// Isla Mona
		rIsland.id = "IslaMona";
		rIsland.model = "islamona";
		rIsland.filespath.models = "islands\IslaDeMuerte";
		rIsland.refl_model = "islamona_refl";
		rIsland.locators = "islamona_locators";
		rIsland.visible = false;
		rIsland.skipCR = true; // KK
		rIsland.smuggling_nation = SPAIN; // PB: Matches with Isla Muelle
		rIsland.towns.quantity = 1;
		rIsland.towns.1 = "";

		rIsland.reload.l1.label = "Isla Mona Shore";
		rIsland.reload.l1.name = "reload_1";
		rIsland.reload.l1.go = "IslaMona_port";
		rIsland.reload.l1.emerge = "Reload3";
		rIsland.reload.l1.radius = 200.0;
		rIsland.reload.l1.enable = false;
		rIsland.reload.l1.goto_enable = false; // PB
		rIsland.reload.l1.pic = 0;
		rIsland.reload.l1.tex = "t2";

		rIsland.InterfaceTextures.t2 = "battle_interface\moor-shores.tga";
		rIsland.InterfaceTextures.t2.h = 4;
		rIsland.InterfaceTextures.t2.v = 16;

		AddIsland(q, rIsland, locator);

	// ==================================================================================================
	// Cartagena
		rIsland.id = "Colombia";
		rIsland.model = "Cartahena";
		rIsland.filespath.models = "islands\Cartahena";
		rIsland.refl_model = "Cartahena_refl";
		rIsland.locators = "Cartahena_locators";
		rIsland.Enc_enable = false;	// PB: To prevent ships being generated IN the mainland
		rIsland.smuggling_nation = SPAIN;
		rIsland.towns.quantity = 1;
		rIsland.towns.1 = "Cartagena";

		rIsland.reload.l1.label = "#stown_name# Port";
		rIsland.reload.l1.name = "reload_1";
		rIsland.reload.l1.go = "Cartagena_Port";
		rIsland.reload.l1.emerge = "reload3";
		rIsland.reload.l1.ships.l0.ay = 2.5;
		rIsland.reload.l1.radius = 200.0;
		rIsland.reload.l1.pic = 3;
		rIsland.reload.l1.tex = "t1";
		rIsland.reload.l1.ships.l0.ay = 3.0;        // LDH 11Dec16
		rIsland.reload.l1.goto_enable = false;

		rIsland.reload.l2.label = "San Felipe Fort"; // KK
		rIsland.reload.l2.name = "reload_fort1";
		rIsland.reload.l2.go = "Fort"; // KK
		rIsland.reload.l2.GoAfterBoard.location = "reload_1";
		rIsland.reload.l2.emerge = "see";
		rIsland.reload.l2.radius = 250.0;
		rIsland.reload.l2.commander = "Cartagena Commander"; // KK
		rIsland.reload.l2.fort.model = "Cartahena_Fort1";
		rIsland.reload.l2.fort.locators = "Cartahena_Fort1_locators";
		rIsland.reload.l2.pic = 21;
		rIsland.reload.l2.tex = "t1";
		rIsland.reload.l2.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l3.label = "Dolphin Sands";
		rIsland.reload.l3.name = "reload_3";
		rIsland.reload.l3.go = "Colombia_shore";
		rIsland.reload.l3.emerge = "reload1";
		rIsland.reload.l3.radius = 200.0;
		rIsland.reload.l3.pic = 21;
		rIsland.reload.l3.tex = "t2";
		rIsland.reload.l3.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.InterfaceTextures.t1 = "battle_interface\moor-town.tga";
		rIsland.InterfaceTextures.t1.h = 4;
		rIsland.InterfaceTextures.t1.v = 16;
		rIsland.InterfaceTextures.t2 = "battle_interface\moor-shores.tga";
		rIsland.InterfaceTextures.t2.h = 4;
		rIsland.InterfaceTextures.t2.v = 16;

		// PB: Temporary copied from Isla Muelle - no contraband, because NO SHORE
		rIsland.Trade.Export.id1 = GOOD_EBONY;
		rIsland.Trade.Export.id2 = GOOD_MAHOGANY;
		rIsland.Trade.Export.id3 = GOOD_CINNAMON;
		rIsland.Trade.Export.id4 = GOOD_SANDAL;
		rIsland.Trade.Export.id5 = GOOD_GOLD;
		rIsland.Trade.Export.id6 = GOOD_BRICKS;
		rIsland.Trade.Import.id1 = GOOD_PLANKS;
		rIsland.Trade.Import.id2 = GOOD_SAILCLOTH;
		rIsland.Trade.Import.id3 = GOOD_SUGAR;
		rIsland.Trade.Import.id4 = GOOD_LINEN;
		rIsland.Trade.Import.id5 = GOOD_SILVER;
		rIsland.Trade.Import.id6 = GOOD_TREATMENT;

		AddIsland(q, rIsland, locator);

	// ==================================================================================================
	// Isla de Muerte
		rIsland.id = "IslaDeMuerte";
		rIsland.model = "islamona";
		rIsland.filespath.models = "islands\IslaDeMuerte";
		rIsland.refl_model = "islamona_refl";
		rIsland.locators = "islamona_locators";
		rIsland.reload_enable = false;
		rIsland.visible = false;
		rIsland.Enc_enable = false;
		rIsland.skipCR = true; // KK
		rIsland.smuggling_nation = PIRATE;
		rIsland.towns.quantity = 1;
		rIsland.towns.1 = "";

		rIsland.reload.l1.label = "Deserted shore";
		rIsland.reload.l1.name = "reload_1";
		rIsland.reload.l1.go = "IslaDeMuerte_shore_01";
		rIsland.reload.l1.emerge = "reload1";
		rIsland.reload.l1.radius = 200.0;
		rIsland.reload.l1.pic = 31;
		rIsland.reload.l1.tex = "t2";
		rIsland.reload.l1.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l2.label = "Dead Man's Bay";
		rIsland.reload.l2.name = "reload_2";
		rIsland.reload.l2.go = "IslaDeMuerte_shore_02";
		rIsland.reload.l2.emerge = "sea_back";
		rIsland.reload.l2.radius = 200.0;
		rIsland.reload.l2.pic = 32;
		rIsland.reload.l2.tex = "t2";
		rIsland.reload.l2.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.reload.l3.label = "Witch's Rock";
		rIsland.reload.l3.name = "reload_3";
		rIsland.reload.l3.go = "IslaDeMuerte_shore_03";
		rIsland.reload.l3.emerge = "reload1";
		rIsland.reload.l3.radius = 200.0;
		rIsland.reload.l3.pic = 33;
		rIsland.reload.l3.tex = "t2";
		rIsland.reload.l3.goto_enable = false; // Screwface: Disable Sail-To

		rIsland.InterfaceTextures.t2 = "battle_interface\moor-shores.tga";
		rIsland.InterfaceTextures.t2.h = 4;
		rIsland.InterfaceTextures.t2.v = 16;

		AddIsland(q, rIsland, locator);

	// ==================================================================================================
	// Petit Tabac
		rIsland.id = "Battle_Rocks";
		rIsland.model = "Terks";
		rIsland.filespath.models = "islands\Terks";
		rIsland.refl_model = "Terks_refl";
		rIsland.locators = "Terks_locators";
		rIsland.visible = false;
		rIsland.smuggling_nation = PORTUGAL; // PB: Matches with Conceicao
		rIsland.towns.quantity = 1;
		rIsland.towns.1 = "";

		rIsland.reload.l1.label = "Devil Creek";
		rIsland.reload.l1.name = "reload_2";
		rIsland.reload.l1.go = "Devil_Creek";
		rIsland.reload.l1.emerge = "see";
		rIsland.reload.l1.radius = 200.0;
		rIsland.reload.l1.pic = 26;
		rIsland.reload.l1.tex = "t2";
		rIsland.reload.l1.enable = false;
		rIsland.reload.l1.goto_enable = false; // PB

		rIsland.InterfaceTextures.t2 = "battle_interface\moor-shores.tga";
		rIsland.InterfaceTextures.t2.h = 4;
		rIsland.InterfaceTextures.t2.v = 16;

		AddIsland(q, rIsland, locator);

		ISLANDS_QUANTITY = q;

	// ==================================================================================================
	// delete temp module
		DeleteClass(&locator);
}
