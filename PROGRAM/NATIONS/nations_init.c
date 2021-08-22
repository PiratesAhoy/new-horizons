void InitNations()
{
	int period = GetCurrentPeriod(); // PB

	ref rNation;
	for(int n = 0; n < MAX_NATIONS; n++) { Nations[n].index = n; } // NK 05-03-23 add int so we know what nation we're in

	NATIONS_QUANTITY = CheckNationsQuantity(period); // KK

	//England
	makeref(rNation,Nations[ENGLAND]);
	rNation.id = "England";
	rNation.Name = "England";		//changed by KAM
	// NK -->
	rNation.Desc = "English";		//changed by KAM
	// NK <--
	rNation.worldMapShip = "british";
	rNation.ShipNamePrefix = "HMS"; // KK: His/Her Majesty's Ship
	rNation.FlagIdx = ENGLAND;
	rNation.laigroup = "ENGLAND";

// PB -->
	if (period == PERIOD_EARLY_EXPLORERS) {
		//Location fantom models
		rNation.fantomModel.m0 = "offic_eng_15";
		rNation.fantomModel.m1 = "soldier_eng_15";
		rNation.fantomModel.m2 = "soldier_eng2_15";
		rNation.fantomModel.m3 = "soldier_eng3_15";
		rNation.fantomModel.m4 = "soldier_eng4_15";
		rNation.fantomModel.m5 = "soldier_eng5_15";
		rNation.fantomModel.m6 = "soldier_eng6_15";
		//Boarding models
		rNation.boardingModel.enemy.m1 = "offic_eng_15";
		rNation.boardingModel.enemy.m1.ani = "man";
		rNation.boardingModel.enemy.m2 = "soldier_eng_15";
		rNation.boardingModel.enemy.m2.ani = "man";
		rNation.boardingModel.enemy.m3 = "soldier_eng2_15";
		rNation.boardingModel.enemy.m3.ani = "man";
		rNation.boardingModel.enemy.m4 = "soldier_eng3_15";
		rNation.boardingModel.enemy.m4.ani = "man";
		rNation.boardingModel.enemy.m5 = "soldier_eng4_15";
		rNation.boardingModel.enemy.m5.ani = "man";
		rNation.boardingModel.enemy.m6 = "soldier_eng5_15";
		rNation.boardingModel.enemy.m6.ani = "man";
		rNation.boardingModel.enemy.m7 = "soldier_eng6_15";
		rNation.boardingModel.enemy.m7.ani = "man";
	}
	if (period == PERIOD_THE_SPANISH_MAIN) {
		//Location fantom models
		rNation.fantomModel.m0 = "offic_eng_16";
		rNation.fantomModel.m1 = "soldier_eng_16";
		rNation.fantomModel.m2 = "soldier_eng2_16";
		rNation.fantomModel.m3 = "soldier_eng3_16";
		rNation.fantomModel.m4 = "soldier_eng4_16";
		rNation.fantomModel.m5 = "soldier_eng5_16";
		rNation.fantomModel.m6 = "soldier_eng6_16";
		//Boarding models
		rNation.boardingModel.enemy.m1 = "offic_eng_16";
		rNation.boardingModel.enemy.m1.ani = "man";
		rNation.boardingModel.enemy.m2 = "soldier_eng_16";
		rNation.boardingModel.enemy.m2.ani = "man";
		rNation.boardingModel.enemy.m3 = "soldier_eng2_16";
		rNation.boardingModel.enemy.m3.ani = "man";
		rNation.boardingModel.enemy.m4 = "soldier_eng3_16";
		rNation.boardingModel.enemy.m4.ani = "man";
		rNation.boardingModel.enemy.m5 = "soldier_eng4_16";
		rNation.boardingModel.enemy.m5.ani = "man";
		rNation.boardingModel.enemy.m6 = "soldier_eng5_16";
		rNation.boardingModel.enemy.m6.ani = "man";
		rNation.boardingModel.enemy.m7 = "soldier_eng6_16";
		rNation.boardingModel.enemy.m7.ani = "man";
	} 
	if (period == PERIOD_GOLDEN_AGE_OF_PIRACY) {

		rNation.Name = "Britain";		//the Kingdom of Britain was founded 1707
		rNation.Desc = "British";

		//Location fantom models
		rNation.fantomModel.m0 = "offic_eng_17";
		rNation.fantomModel.m1 = "soldier_eng_17";
		rNation.fantomModel.m2 = "soldier_eng2_17";
		rNation.fantomModel.m3 = "soldier_eng3_17";
		rNation.fantomModel.m4 = "soldier_eng4_17";
		rNation.fantomModel.m5 = "soldier_eng5_17";
		rNation.fantomModel.m6 = "soldier_eng6_17";
		//Boarding models
		rNation.boardingModel.enemy.m1 = "offic_eng_17";
		rNation.boardingModel.enemy.m1.ani = "man";
		rNation.boardingModel.enemy.m2 = "soldier_eng_17";
		rNation.boardingModel.enemy.m2.ani = "man";
		rNation.boardingModel.enemy.m3 = "soldier_eng2_17";
		rNation.boardingModel.enemy.m3.ani = "man";
		rNation.boardingModel.enemy.m4 = "soldier_eng3_17";
		rNation.boardingModel.enemy.m4.ani = "man";
		rNation.boardingModel.enemy.m5 = "soldier_eng4_17";
		rNation.boardingModel.enemy.m5.ani = "man";
		rNation.boardingModel.enemy.m6 = "soldier_eng5_17";
		rNation.boardingModel.enemy.m6.ani = "man";
		rNation.boardingModel.enemy.m7 = "soldier_eng6_17";
		rNation.boardingModel.enemy.m7.ani = "man";
	}
	if (period == PERIOD_COLONIAL_POWERS || period == PERIOD_REVOLUTIONS || period == PERIOD_NAPOLEONIC) {

		rNation.Name = "Britain";		//the Kingdom of Britain was founded 1707
		rNation.Desc = "British";

		//Location fantom models
		rNation.fantomModel.m0 = "offic_eng_18";
		rNation.fantomModel.m1 = "Soldier_Eng_18";
		rNation.fantomModel.m2 = "Soldier_Eng2_18";
		rNation.fantomModel.m3 = "Soldier_Eng3_18";
		rNation.fantomModel.m4 = "Soldier_Eng4_18";
		rNation.fantomModel.m5 = "Soldier_Eng5_18";
		rNation.fantomModel.m6 = "Soldier_Eng6_18";
		//Boarding models
		rNation.boardingModel.enemy.m1 = "offic_eng_18";
		rNation.boardingModel.enemy.m1.ani = "man";
		rNation.boardingModel.enemy.m2 = "Soldier_Eng_18";
		rNation.boardingModel.enemy.m2.ani = "man";
		rNation.boardingModel.enemy.m3 = "Soldier_Eng2_18";
		rNation.boardingModel.enemy.m3.ani = "man";
		rNation.boardingModel.enemy.m4 = "Soldier_Eng3_18";
		rNation.boardingModel.enemy.m4.ani = "man";
		rNation.boardingModel.enemy.m5 = "Soldier_Eng4_18";
		rNation.boardingModel.enemy.m5.ani = "man";
		rNation.boardingModel.enemy.m6 = "Soldier_Eng5_18";
		rNation.boardingModel.enemy.m6.ani = "man";
		rNation.boardingModel.enemy.m7 = "Soldier_Eng6_18";
		rNation.boardingModel.enemy.m7.ani = "man";
	}
// <-- PB
	// NK -->
	rNation.Ranks.Quantity = 12;
	rNation.Ranks.1 = "Midshipman";
	rNation.Ranks.2 = "Acting Lieutenant";
	rNation.Ranks.3 = "Lieutenant";
	rNation.Ranks.4 = "Senior Lieutenant";
	rNation.Ranks.5 = "Commander";
	rNation.Ranks.6 = "Post Captain";
	rNation.Ranks.7 = "Commodore";
	rNation.Ranks.8 = "Rear Admiral";
	rNation.Ranks.9 = "Vice Admiral";
	rNation.Ranks.10 = "Admiral";
	rNation.Ranks.11 = "Admiral of the Fleet";
	rNation.Ranks.12 = "First Lord of the Admiralty";
	rNation.Titles.Quantity = 12;
	rNation.Titles.1 = "Midshipman";
	rNation.Titles.2 = "Acting Lieutenant";
	rNation.Titles.3 = "Lieutenant";
	rNation.Titles.4 = "Senior Lieutenant";
	rNation.Titles.5 = "Commander";
	rNation.Titles.6 = "Captain";
	rNation.Titles.7 = "Knight";
	rNation.Titles.8 = "Baronet";
	rNation.Titles.9 = "Baron";
	rNation.Titles.10 = "Viscount";
	rNation.Titles.11 = "Earl";
	rNation.Titles.12 = "Marquess";
	// NK <--

	//France
	makeref(rNation,Nations[FRANCE]);
	rNation.id = "France";
	rNation.Name = "France";
	// NK -->
	rNation.Desc = "French";
// KK -->
	if (period >= GetPeriodFromYear(1800)) {
		rNation.worldMapShip = "napoleonic";
	} else {
		rNation.worldMapShip = "french";
	}
	//rNation.ShipNamePrefix = "FS"; // PB: French Ship (NATO designation); France does not use prefixes internally
	rNation.FlagIdx = FRANCE;
	rNation.laigroup = "FRANCE";
// <-- KK
	// NK <--

// PB -->
	if (period == PERIOD_EARLY_EXPLORERS) {
		//Location fantom models
		rNation.fantomModel.m0 = "offic_fra_15";
		rNation.fantomModel.m1 = "soldier_fra_15";
		rNation.fantomModel.m2 = "soldier_fra2_15";
		rNation.fantomModel.m3 = "soldier_fra3_15";
		rNation.fantomModel.m4 = "soldier_fra4_15";
		rNation.fantomModel.m5 = "soldier_fra5_15";
		rNation.fantomModel.m6 = "soldier_fra6_15";
		//Boarding models
		rNation.boardingModel.enemy.m1 = "offic_fra_15";
		rNation.boardingModel.enemy.m1.ani = "man";
		rNation.boardingModel.enemy.m2 = "soldier_fra_15";
		rNation.boardingModel.enemy.m2.ani = "man";
		rNation.boardingModel.enemy.m3 = "soldier_fra2_15";
		rNation.boardingModel.enemy.m3.ani = "man";
		rNation.boardingModel.enemy.m4 = "soldier_fra3_15";
		rNation.boardingModel.enemy.m4.ani = "man";
		rNation.boardingModel.enemy.m5 = "soldier_fra4_15";
		rNation.boardingModel.enemy.m5.ani = "man";
		rNation.boardingModel.enemy.m6 = "soldier_fra5_15";
		rNation.boardingModel.enemy.m6.ani = "man";
		rNation.boardingModel.enemy.m7 = "soldier_fra6_15";
		rNation.boardingModel.enemy.m7.ani = "man";
	}
	if (period == PERIOD_THE_SPANISH_MAIN) {
		//Location fantom models
		rNation.fantomModel.m0 = "offic_fra_16";
		rNation.fantomModel.m1 = "soldier_fra_16";
		rNation.fantomModel.m2 = "soldier_fra2_16";
		rNation.fantomModel.m3 = "soldier_fra3_16";
		rNation.fantomModel.m4 = "soldier_fra4_16";
		rNation.fantomModel.m5 = "soldier_fra5_16";
		rNation.fantomModel.m6 = "soldier_fra6_16";
		//Boarding models
		rNation.boardingModel.enemy.m1 = "offic_fra_16";
		rNation.boardingModel.enemy.m1.ani = "man";
		rNation.boardingModel.enemy.m2 = "soldier_fra_16";
		rNation.boardingModel.enemy.m2.ani = "man";
		rNation.boardingModel.enemy.m3 = "soldier_fra2_16";
		rNation.boardingModel.enemy.m3.ani = "man";
		rNation.boardingModel.enemy.m4 = "soldier_fra3_16";
		rNation.boardingModel.enemy.m4.ani = "man";
		rNation.boardingModel.enemy.m5 = "soldier_fra4_16";
		rNation.boardingModel.enemy.m5.ani = "man";
		rNation.boardingModel.enemy.m6 = "soldier_fra5_16";
		rNation.boardingModel.enemy.m6.ani = "man";
		rNation.boardingModel.enemy.m7 = "soldier_fra6_16";
		rNation.boardingModel.enemy.m7.ani = "man";
	}
	if (period == PERIOD_GOLDEN_AGE_OF_PIRACY) {
		//Location fantom models
		rNation.fantomModel.m0 = "Offic_Fra_17";
		rNation.fantomModel.m1 = "Soldier_Fra_17";
		rNation.fantomModel.m2 = "Soldier_Fra2_17";
		rNation.fantomModel.m3 = "Soldier_Fra3_17";
		rNation.fantomModel.m4 = "Soldier_Fra4_17";
		rNation.fantomModel.m5 = "Soldier_Fra5_17";
		rNation.fantomModel.m6 = "Soldier_Fra6_17";
		//Boarding models
		rNation.boardingModel.enemy.m1 = "Offic_Fra_17";
		rNation.boardingModel.enemy.m1.ani = "man";
		rNation.boardingModel.enemy.m2 = "Soldier_Fra_17";
		rNation.boardingModel.enemy.m2.ani = "man";
		rNation.boardingModel.enemy.m3 = "Soldier_Fra2_17";
		rNation.boardingModel.enemy.m3.ani = "man";
		rNation.boardingModel.enemy.m4 = "Soldier_Fra3_17";
		rNation.boardingModel.enemy.m4.ani = "man";
		rNation.boardingModel.enemy.m5 = "Soldier_Fra4_17";
		rNation.boardingModel.enemy.m5.ani = "man";
		rNation.boardingModel.enemy.m6 = "Soldier_Fra5_17";
		rNation.boardingModel.enemy.m6.ani = "man";
		rNation.boardingModel.enemy.m7 = "Soldier_Fra6_17";
		rNation.boardingModel.enemy.m7.ani = "man";
	} 
	if (period == PERIOD_COLONIAL_POWERS || period == PERIOD_REVOLUTIONS) {
		//Location fantom models
		rNation.fantomModel.m0 = "offic_fra_18";
		rNation.fantomModel.m1 = "Soldier_Fra_18";
		rNation.fantomModel.m2 = "Soldier_Fra2_18";
		rNation.fantomModel.m3 = "Soldier_Fra3_18";
		rNation.fantomModel.m4 = "Soldier_Fra4_18";
		rNation.fantomModel.m5 = "Soldier_Fra5_18";
		rNation.fantomModel.m6 = "Soldier_Fra6_18";
		//Boarding models
		rNation.boardingModel.enemy.m1 = "offic_fra_18";
		rNation.boardingModel.enemy.m1.ani = "man";
		rNation.boardingModel.enemy.m2 = "Soldier_Fra_18";
		rNation.boardingModel.enemy.m2.ani = "man";
		rNation.boardingModel.enemy.m3 = "Soldier_Fra2_18";
		rNation.boardingModel.enemy.m3.ani = "man";
		rNation.boardingModel.enemy.m4 = "Soldier_Fra3_18";
		rNation.boardingModel.enemy.m4.ani = "man";
		rNation.boardingModel.enemy.m5 = "Soldier_Fra4_18";
		rNation.boardingModel.enemy.m5.ani = "man";
		rNation.boardingModel.enemy.m6 = "Soldier_Fra5_18";
		rNation.boardingModel.enemy.m6.ani = "man";
		rNation.boardingModel.enemy.m7 = "Soldier_Fra6_18";
		rNation.boardingModel.enemy.m7.ani = "man";
	} 
	if (period == PERIOD_NAPOLEONIC) {
		//Location fantom models
		rNation.fantomModel.m0 = "offic_fra_19";
		rNation.fantomModel.m1 = "soldier_fra_19";
		rNation.fantomModel.m2 = "soldier_fra2_19";
		rNation.fantomModel.m3 = "soldier_fra3_19";
		rNation.fantomModel.m4 = "soldier_fra4_19";
		rNation.fantomModel.m5 = "soldier_fra5_19";
		rNation.fantomModel.m6 = "soldier_fra6_19";
		//Boarding models
		rNation.boardingModel.enemy.m1 = "offic_fra_19";
		rNation.boardingModel.enemy.m1.ani = "man";
		rNation.boardingModel.enemy.m2 = "soldier_fra_19";
		rNation.boardingModel.enemy.m2.ani = "man";
		rNation.boardingModel.enemy.m3 = "soldier_fra2_19";
		rNation.boardingModel.enemy.m3.ani = "man";
		rNation.boardingModel.enemy.m4 = "soldier_fra3_19";
		rNation.boardingModel.enemy.m4.ani = "man";
		rNation.boardingModel.enemy.m5 = "soldier_fra4_19";
		rNation.boardingModel.enemy.m5.ani = "man";
		rNation.boardingModel.enemy.m6 = "soldier_fra5_19";
		rNation.boardingModel.enemy.m6.ani = "man";
		rNation.boardingModel.enemy.m7 = "soldier_fra6_19";
		rNation.boardingModel.enemy.m7.ani = "man";
	}
// <-- PB
	// NK -->
	rNation.Ranks.Quantity = 12;
	rNation.Ranks.1 = "Enseigne";
	rNation.Ranks.2 = "Sous-Lieutenant de Vaisseau";
	rNation.Ranks.3 = "Lieutenant de Vaisseau";
	rNation.Ranks.4 = "Capitaine de Corvette";
	rNation.Ranks.5 = "Capitaine de Fregate";
	rNation.Ranks.6 = "Capitaine de Vaisseau";
	rNation.Ranks.7 = "Contre-Amiral";
	rNation.Ranks.8 = "Vice-Amiral";
	rNation.Ranks.9 = "Vice-Amiral d'Escadre";
	rNation.Ranks.10 = "Amiral";
	rNation.Ranks.11 = "Amiral d'Escadre";
	rNation.Ranks.12 = "Amiral de France";
	rNation.Titles.Quantity = 12;
	rNation.Titles.1 = "Enseigne";
	rNation.Titles.2 = "Sous-Lieutenant de Vaisseau";
	rNation.Titles.3 = "Lieutenant de Vaisseau";
	rNation.Titles.4 = "Capitaine de Corvette";
	rNation.Titles.5 = "Capitaine de Fregate";
	rNation.Titles.6 = "Capitaine de Vaisseau";
	rNation.Titles.7 = "Chevalier";
	rNation.Titles.8 = "Baronnet";
	rNation.Titles.9 = "Baron";
	rNation.Titles.10 = "Vicomte";
	rNation.Titles.11 = "Comte";
	rNation.Titles.12 = "Marquis";
	// NK <--

	//Spain
	makeref(rNation,Nations[SPAIN]);
	rNation.id = "Spain";
	rNation.Name = "Spain";
	// NK -->
	rNation.Desc = "Spanish";
	// NK <--
	rNation.worldMapShip = "spanish";
	//rNation.ShipNamePrefix = "ESPS"; // PB: Spanish Naval Ship (Spain does not use prefixes internally)
	rNation.FlagIdx = SPAIN; // KK
	rNation.laigroup = "SPAIN";

// PB -->
	if (period == PERIOD_EARLY_EXPLORERS) {
		//Location fantom models
		rNation.fantomModel.m0 = "offic_spa_15";
		rNation.fantomModel.m1 = "soldier_spa_15";
		rNation.fantomModel.m2 = "soldier_spa2_15";
		rNation.fantomModel.m3 = "soldier_spa3_15";
		rNation.fantomModel.m4 = "soldier_spa4_15";
		rNation.fantomModel.m5 = "soldier_spa5_15";
		rNation.fantomModel.m6 = "soldier_spa6_15";
		//Boarding models
		rNation.boardingModel.enemy.m1 = "offic_spa_15";
		rNation.boardingModel.enemy.m1.ani = "man";
		rNation.boardingModel.enemy.m2 = "soldier_spa_15";
		rNation.boardingModel.enemy.m2.ani = "man";
		rNation.boardingModel.enemy.m3 = "soldier_spa2_15";
		rNation.boardingModel.enemy.m3.ani = "man";
		rNation.boardingModel.enemy.m4 = "soldier_spa3_15";
		rNation.boardingModel.enemy.m4.ani = "man";
		rNation.boardingModel.enemy.m5 = "soldier_spa4_15";
		rNation.boardingModel.enemy.m5.ani = "man";
		rNation.boardingModel.enemy.m6 = "soldier_spa5_15";
		rNation.boardingModel.enemy.m6.ani = "man";
		rNation.boardingModel.enemy.m7 = "soldier_spa6_15";
		rNation.boardingModel.enemy.m7.ani = "man";
	}
	if (period == PERIOD_THE_SPANISH_MAIN) {
		rNation.fantomModel.m0 = "offic_spa_16";
		rNation.fantomModel.m1 = "soldier_spa_16";
		rNation.fantomModel.m2 = "soldier_spa2_16";
		rNation.fantomModel.m3 = "soldier_spa3_16";
		rNation.fantomModel.m4 = "soldier_spa4_16";
		rNation.fantomModel.m5 = "soldier_spa5_16";
		rNation.fantomModel.m6 = "soldier_spa6_16";
		//Boarding models
		rNation.boardingModel.enemy.m1 = "offic_spa_16";
		rNation.boardingModel.enemy.m1.ani = "man";
		rNation.boardingModel.enemy.m2 = "soldier_spa_16";
		rNation.boardingModel.enemy.m2.ani = "man";
		rNation.boardingModel.enemy.m3 = "soldier_spa2_16";
		rNation.boardingModel.enemy.m3.ani = "man";
		rNation.boardingModel.enemy.m4 = "soldier_spa3_16";
		rNation.boardingModel.enemy.m4.ani = "man";
		rNation.boardingModel.enemy.m5 = "soldier_spa4_16";
		rNation.boardingModel.enemy.m5.ani = "man";
		rNation.boardingModel.enemy.m6 = "soldier_spa5_16";
		rNation.boardingModel.enemy.m6.ani = "man";
		rNation.boardingModel.enemy.m7 = "soldier_spa6_16";
		rNation.boardingModel.enemy.m7.ani = "man";
	}
		if (period == PERIOD_GOLDEN_AGE_OF_PIRACY) {
		rNation.fantomModel.m0 = "offic_spa_17";
		rNation.fantomModel.m1 = "soldier_spa_17";
		rNation.fantomModel.m2 = "soldier_spa2_17";
		rNation.fantomModel.m3 = "soldier_spa3_17";
		rNation.fantomModel.m4 = "soldier_spa4_17";
		rNation.fantomModel.m5 = "soldier_spa5_17";
		rNation.fantomModel.m6 = "soldier_spa6_17";
		//Boarding models
		rNation.boardingModel.enemy.m1 = "offic_spa_17";
		rNation.boardingModel.enemy.m1.ani = "man";
		rNation.boardingModel.enemy.m2 = "soldier_spa_17";
		rNation.boardingModel.enemy.m2.ani = "man";
		rNation.boardingModel.enemy.m3 = "soldier_spa2_17";
		rNation.boardingModel.enemy.m3.ani = "man";
		rNation.boardingModel.enemy.m4 = "soldier_spa3_17";
		rNation.boardingModel.enemy.m4.ani = "man";
		rNation.boardingModel.enemy.m5 = "soldier_spa4_17";
		rNation.boardingModel.enemy.m5.ani = "man";
		rNation.boardingModel.enemy.m6 = "soldier_spa5_17";
		rNation.boardingModel.enemy.m6.ani = "man";
		rNation.boardingModel.enemy.m7 = "soldier_spa6_17";
		rNation.boardingModel.enemy.m7.ani = "man";
	}
	if (period == PERIOD_COLONIAL_POWERS || period == PERIOD_REVOLUTIONS) {
		//Location fantom models
		//Location fantom models
		rNation.fantomModel.m0 = "offic_spa_18";
		rNation.fantomModel.m1 = "Soldier_Spa_18";
		rNation.fantomModel.m2 = "Soldier_Spa2_18";
		rNation.fantomModel.m3 = "Soldier_Spa3_18";
		rNation.fantomModel.m4 = "Soldier_Spa4_18";
		rNation.fantomModel.m5 = "Soldier_Spa5_18";
		rNation.fantomModel.m6 = "Soldier_Spa6_18";
		//Boarding models
		rNation.boardingModel.enemy.m1 = "offic_spa_18";
		rNation.boardingModel.enemy.m1.ani = "man";
		rNation.boardingModel.enemy.m2 = "Soldier_Spa_18";
		rNation.boardingModel.enemy.m2.ani = "man";
		rNation.boardingModel.enemy.m3 = "Soldier_Spa2_18";
		rNation.boardingModel.enemy.m3.ani = "man";
		rNation.boardingModel.enemy.m4 = "Soldier_Spa3_18";
		rNation.boardingModel.enemy.m4.ani = "man";
		rNation.boardingModel.enemy.m5 = "Soldier_Spa4_18";
		rNation.boardingModel.enemy.m5.ani = "man";
		rNation.boardingModel.enemy.m6 = "Soldier_Spa5_18";
		rNation.boardingModel.enemy.m6.ani = "man";
		rNation.boardingModel.enemy.m7 = "Soldier_Spa6_18";
		rNation.boardingModel.enemy.m7.ani = "man";
	}
	if (period == PERIOD_NAPOLEONIC) {
		//Location fantom models
		rNation.fantomModel.m0 = "offic_spa_19";
		rNation.fantomModel.m1 = "Soldier_Spa_19";
		rNation.fantomModel.m2 = "Soldier_Spa2_19";
		rNation.fantomModel.m3 = "Soldier_Spa3_19";
		rNation.fantomModel.m4 = "Soldier_Spa4_19";
		rNation.fantomModel.m5 = "Soldier_Spa5_19";
		rNation.fantomModel.m6 = "Soldier_Spa6_19";
		rNation.fantomModel.m7 = "Soldier_Spa7_19";
		//Boarding models
		rNation.boardingModel.enemy.m1 = "offic_spa_19";
		rNation.boardingModel.enemy.m1.ani = "man";
		rNation.boardingModel.enemy.m2 = "Soldier_Spa_19";
		rNation.boardingModel.enemy.m2.ani = "man";
		rNation.boardingModel.enemy.m3 = "Soldier_Spa2_19";
		rNation.boardingModel.enemy.m3.ani = "man";
		rNation.boardingModel.enemy.m4 = "Soldier_Spa3_19";
		rNation.boardingModel.enemy.m4.ani = "man";
		rNation.boardingModel.enemy.m5 = "Soldier_Spa4_19";
		rNation.boardingModel.enemy.m5.ani = "man";
		rNation.boardingModel.enemy.m6 = "Soldier_Spa5_19";
		rNation.boardingModel.enemy.m6.ani = "man";
		rNation.boardingModel.enemy.m7 = "Soldier_Spa6_19";
		rNation.boardingModel.enemy.m7.ani = "man";
		rNation.boardingModel.enemy.m8 = "Soldier_Spa7_19";
		rNation.boardingModel.enemy.m8.ani = "man";
	}
// <-- PB
	// NK -->
	rNation.Ranks.Quantity = 12;
	rNation.Ranks.1 = "Aspirante";
	rNation.Ranks.2 = "Alférez de Fragate";
	rNation.Ranks.3 = "Alférez de Navío";
	rNation.Ranks.4 = "Teniente de Navío";
	rNation.Ranks.5 = "Capitán de Corbeta";
	rNation.Ranks.6 = "Capitán de Fragata";
	rNation.Ranks.7 = "Capitán de Navío";
	rNation.Ranks.8 = "Contra Almirante";
	rNation.Ranks.9 = "Vice Almirante";
	rNation.Ranks.10 = "Almirante";
	rNation.Ranks.11 = "Almirante General";
	rNation.Ranks.12 = "Capitán General";
	rNation.Titles.Quantity = 12;
	rNation.Titles.1 = "Aspirante";
	rNation.Titles.2 = "Alférez de Fragate";
	rNation.Titles.3 = "Alférez de Navío";
	rNation.Titles.4 = "Teniente de Navío";
	rNation.Titles.5 = "Capitán de Corbeta";
	rNation.Titles.6 = "Capitán de Fragata";
	rNation.Titles.7 = "Caballero";
	rNation.Titles.8 = "Baronet";
	rNation.Titles.9 = "Barón";
	rNation.Titles.10 = "Vizconde";
	rNation.Titles.11 = "Conde";
	rNation.Titles.12 = "Marqués";
	// NK <--

	//Pirate
	makeref(rNation,Nations[PIRATE]);
	rNation.id = "Pirate";
	rNation.Name = "Pirate";
	// NK -->
	rNation.Desc = "Pirate";
	// NK <--
	rNation.worldMapShip = "pirates";
	rNation.FlagIdx = PIRATE; // KK
	rNation.laigroup = "QC";

	//Location fantom models
	rNation.fantomModel.m0 = "pirat1";
	rNation.fantomModel.m1 = "pirat2";
	rNation.fantomModel.m2 = "pirat3";
	rNation.fantomModel.m3 = "pirat4";
	rNation.fantomModel.m4 = "pirat5";
	rNation.fantomModel.m5 = "pirat6";
	rNation.fantomModel.m6 = "pirat7";
	//Boarding models
	rNation.boardingModel.enemy.m0 = "pirat1";
	rNation.boardingModel.enemy.m0.ani = "man";
	rNation.boardingModel.enemy.m1 = "pirat2";
	rNation.boardingModel.enemy.m1.ani = "man";
	rNation.boardingModel.enemy.m2 = "pirat3";
	rNation.boardingModel.enemy.m2.ani = "man";
	rNation.boardingModel.enemy.m3 = "pirat4";
	rNation.boardingModel.enemy.m3.ani = "man";
	rNation.boardingModel.enemy.m4 = "pirat5";
	rNation.boardingModel.enemy.m4.ani = "man";
	rNation.boardingModel.enemy.m5 = "pirat6";
	rNation.boardingModel.enemy.m5.ani = "man";
	rNation.boardingModel.enemy.m6 = "pirat7";
	rNation.boardingModel.enemy.m6.ani = "man";
	rNation.boardingModel.enemy.m7 = "pirat8";
	rNation.boardingModel.enemy.m7.ani = "man";
	rNation.boardingModel.enemy.m8 = "pirat9";
	rNation.boardingModel.enemy.m8.ani = "man";
	rNation.boardingModel.enemy.m9 = "pirat11";
	rNation.boardingModel.enemy.m9.ani = "man";
	rNation.boardingModel.enemy.m10 = "pirat13";
	rNation.boardingModel.enemy.m10.ani = "man";
	rNation.boardingModel.enemy.m11 = "pirtt7";
	rNation.boardingModel.enemy.m11.ani = "man";
	rNation.boardingModel.enemy.m12 = "33_Piratess10";
	rNation.boardingModel.enemy.m12.ani = "man";
	rNation.boardingModel.enemy.m13 = "50evl2in";
	rNation.boardingModel.enemy.m13.ani = "man";
	rNation.boardingModel.enemy.m14 = "Capitan";
	rNation.boardingModel.enemy.m14.ani = "man";
	rNation.boardingModel.enemy.m15 = "Corsair1_2";
	rNation.boardingModel.enemy.m15.ani = "man";
	rNation.boardingModel.enemy.m16 = "Corsair1_3";
	rNation.boardingModel.enemy.m16.ani = "man";
	rNation.boardingModel.enemy.m17 = "Corsair1_4";
	rNation.boardingModel.enemy.m17.ani = "man";
	rNation.boardingModel.enemy.m18 = "Corsair2";
	rNation.boardingModel.enemy.m18.ani = "man";
	rNation.boardingModel.enemy.m19 = "Corsair3";
	rNation.boardingModel.enemy.m19.ani = "man";
	rNation.boardingModel.enemy.m20 = "Killer";
	rNation.boardingModel.enemy.m20.ani = "man";
	rNation.boardingModel.enemy.m21 = "Napitan";
	rNation.boardingModel.enemy.m21.ani = "man";
	rNation.boardingModel.enemy.m22 = "Will_2";
	rNation.boardingModel.enemy.m22.ani = "man";

	// NK -->
	rNation.Titles.Quantity = 12;
	rNation.Titles.1 = "Unknown Freebooter";
	rNation.Titles.2 = "Unknown Pirate";
	rNation.Titles.3 = "Freebooter";
	rNation.Titles.4 = "Cutthroat";
	rNation.Titles.5 = "Promising Pirate";
	rNation.Titles.6 = "Well-known Pirate";
	rNation.Titles.7 = "Famous Pirate";
	rNation.Titles.8 = "Infamous Pirate";
	rNation.Titles.9 = "Dread Pirate";
	rNation.Titles.10 = "Scourge of the Archipelago";
	rNation.Titles.11 = "Scourge of the Caribbean";
	rNation.Titles.12 = "Scourge of the Seven Seas";
	rNation.Ranks.Quantity = 12;
	rNation.Ranks.1 = "Unrecognised";
	rNation.Ranks.2 = "Barely Known";
	rNation.Ranks.3 = "Recognized";
	rNation.Ranks.4 = "Tolerated";
	rNation.Ranks.5 = "Acknowledged";
	rNation.Ranks.6 = "Well-known";
	rNation.Ranks.7 = "Famous";
	rNation.Ranks.8 = "Acclaimed";
	rNation.Ranks.9 = "Illustrious";
	rNation.Ranks.10 = "Renowned";
	rNation.Ranks.11 = "Legendary";
	rNation.Ranks.12 = "Mythic";
	// NK <--

	//Holland
	makeref(rNation,Nations[HOLLAND]);
	rNation.id = "Holland";
	rNation.Name = "Holland";
	// NK -->
	rNation.Desc = "Dutch";
	// NK <--
	rNation.worldMapShip = "dutch";
//	rNation.ShipNamePrefix = "Zr.Ms."; // PB: Zijner/Harer Majesteits Schip, archaic Dutch language
	rNation.FlagIdx = HOLLAND; // KK
	rNation.laigroup = "DOUWESEN";

// PB -->
	if (period == PERIOD_EARLY_EXPLORERS) {
		//Location fantom models
		rNation.fantomModel.m0 = "offic_hol_15";
		rNation.fantomModel.m1 = "Soldier_Hol_15";
		rNation.fantomModel.m2 = "Soldier_Hol2_15";
		rNation.fantomModel.m3 = "Soldier_Hol3_15";
		rNation.fantomModel.m4 = "Soldier_Hol4_15";
		rNation.fantomModel.m5 = "Soldier_Hol5_15";
		rNation.fantomModel.m6 = "Soldier_Hol6_15";
		//Boarding models
		rNation.boardingModel.enemy.m1 = "offic_hol_15";
		rNation.boardingModel.enemy.m1.ani = "man";
		rNation.boardingModel.enemy.m2 = "Soldier_Hol_15";
		rNation.boardingModel.enemy.m2.ani = "man";
		rNation.boardingModel.enemy.m3 = "Soldier_Hol2_15";
		rNation.boardingModel.enemy.m3.ani = "man";
		rNation.boardingModel.enemy.m4 = "Soldier_Hol3_15";
		rNation.boardingModel.enemy.m4.ani = "man";
		rNation.boardingModel.enemy.m5 = "Soldier_Hol4_15";
		rNation.boardingModel.enemy.m5.ani = "man";
		rNation.boardingModel.enemy.m6 = "Soldier_Hol5_15";
		rNation.boardingModel.enemy.m6.ani = "man";
		rNation.boardingModel.enemy.m7 = "Soldier_Hol6_15";
		rNation.boardingModel.enemy.m7.ani = "man";
	} 
	if (period == PERIOD_GOLDEN_AGE_OF_PIRACY) {
		//Location fantom models
		rNation.fantomModel.m0 = "offic_hol_17";
		rNation.fantomModel.m1 = "Soldier_Hol_17";
		rNation.fantomModel.m2 = "Soldier_Hol2_17";
		rNation.fantomModel.m3 = "Soldier_Hol3_17";
		rNation.fantomModel.m4 = "Soldier_Hol4_17";
		rNation.fantomModel.m5 = "Soldier_Hol5_17";
		rNation.fantomModel.m6 = "Soldier_Hol6_17";
		//Boarding models
		rNation.boardingModel.enemy.m1 = "offic_hol_17";
		rNation.boardingModel.enemy.m1.ani = "man";
		rNation.boardingModel.enemy.m2 = "Soldier_Hol_17";
		rNation.boardingModel.enemy.m2.ani = "man";
		rNation.boardingModel.enemy.m3 = "Soldier_Hol2_17";
		rNation.boardingModel.enemy.m3.ani = "man";
		rNation.boardingModel.enemy.m4 = "Soldier_Hol3_17";
		rNation.boardingModel.enemy.m4.ani = "man";
		rNation.boardingModel.enemy.m5 = "Soldier_Hol4_17";
		rNation.boardingModel.enemy.m5.ani = "man";
		rNation.boardingModel.enemy.m6 = "Soldier_Hol5_17";
		rNation.boardingModel.enemy.m6.ani = "man";
		rNation.boardingModel.enemy.m7 = "Soldier_Hol6_17";
		rNation.boardingModel.enemy.m7.ani = "man";
	}
	if (period == PERIOD_THE_SPANISH_MAIN) {
		//Location fantom models
		rNation.fantomModel.m0 = "Offic_hol_16";
		rNation.fantomModel.m1 = "soldier_hol_16";
		rNation.fantomModel.m2 = "soldier_hol2_16";
		rNation.fantomModel.m3 = "soldier_hol3_16";
		rNation.fantomModel.m4 = "soldier_hol4_16";
		rNation.fantomModel.m5 = "soldier_hol5_16";
		rNation.fantomModel.m6 = "soldier_hol6_16";
		//Boarding models
		rNation.boardingModel.enemy.m1 = "Offic_hol_16";
		rNation.boardingModel.enemy.m1.ani = "man";
		rNation.boardingModel.enemy.m2 = "soldier_hol_16";
		rNation.boardingModel.enemy.m2.ani = "man";
		rNation.boardingModel.enemy.m3 = "soldier_hol2_16";
		rNation.boardingModel.enemy.m3.ani = "man";
		rNation.boardingModel.enemy.m4 = "soldier_hol3_16";
		rNation.boardingModel.enemy.m4.ani = "man";
		rNation.boardingModel.enemy.m5 = "soldier_hol4_16";
		rNation.boardingModel.enemy.m5.ani = "man";
		rNation.boardingModel.enemy.m6 = "soldier_hol5_16";
		rNation.boardingModel.enemy.m6.ani = "man";
		rNation.boardingModel.enemy.m7 = "soldier_hol6_16";
		rNation.boardingModel.enemy.m7.ani = "man";
	}
	if (period == PERIOD_COLONIAL_POWERS || period == PERIOD_REVOLUTIONS || period == PERIOD_NAPOLEONIC) {
		//Location fantom models
		rNation.fantomModel.m0 = "offic_hol_18";
		rNation.fantomModel.m1 = "Soldier_Hol_18";
		rNation.fantomModel.m2 = "Soldier_Hol2_18";
		rNation.fantomModel.m3 = "Soldier_Hol3_18";
		rNation.fantomModel.m4 = "Soldier_Hol4_18";
		rNation.fantomModel.m5 = "Soldier_Hol5_18";
		rNation.fantomModel.m6 = "Soldier_Hol6_18";
		//Boarding models
		rNation.boardingModel.enemy.m1 = "offic_hol_18";
		rNation.boardingModel.enemy.m1.ani = "man";
		rNation.boardingModel.enemy.m2 = "Soldier_Hol_18";
		rNation.boardingModel.enemy.m2.ani = "man";
		rNation.boardingModel.enemy.m3 = "Soldier_Hol2_18";
		rNation.boardingModel.enemy.m3.ani = "man";
		rNation.boardingModel.enemy.m4 = "Soldier_Hol3_18";
		rNation.boardingModel.enemy.m4.ani = "man";
		rNation.boardingModel.enemy.m5 = "Soldier_Hol4_18";
		rNation.boardingModel.enemy.m5.ani = "man";
		rNation.boardingModel.enemy.m6 = "Soldier_Hol5_18";
		rNation.boardingModel.enemy.m6.ani = "man";
		rNation.boardingModel.enemy.m7 = "Soldier_Hol6_18";
		rNation.boardingModel.enemy.m7.ani = "man";
	}
// <-- PB
	// NK -->
	rNation.Ranks.Quantity = 12;
	rNation.Ranks.1 = "Cadet Officier";
	rNation.Ranks.2 = "Adjutant Onderofficier";
	rNation.Ranks.3 = "Derde Luitenant";
	rNation.Ranks.4 = "Tweede Luitenant";
	rNation.Ranks.5 = "Eerste Luitenant";
	rNation.Ranks.6 = "Kapitein-Luitenant";
	rNation.Ranks.7 = "Kapitein ter Zee";
	rNation.Ranks.8 = "Commandeur";
	rNation.Ranks.9 = "Schout-bij-Nacht";
	rNation.Ranks.10 = "Vice-Admiraal";
	rNation.Ranks.11 = "Luitenant-Admiraal";
	rNation.Ranks.12 = "Admiraal";
	rNation.Titles.Quantity = 12;
	rNation.Titles.1 = "Cadet Officier";
	rNation.Titles.2 = "Adjutant Onderofficier";
	rNation.Titles.3 = "Derde Luitenant";
	rNation.Titles.4 = "Tweede Luitenant";
	rNation.Titles.5 = "Eerste Luitenant";
	rNation.Titles.6 = "Kapitein-Luitenant";
	rNation.Titles.7 = "Ridder";
	rNation.Titles.8 = "Erfridder";
	rNation.Titles.9 = "Baron";
	rNation.Titles.10 = "Burggraaf";
	rNation.Titles.11 = "Graaf";
	rNation.Titles.12 = "Markies";
	// NK <--

	//Portugal
	makeref(rNation,Nations[PORTUGAL]);
	rNation.id = "Portugal";
	rNation.Name = "Portugal";
	// NK -->
	rNation.Desc = "Portuguese";
	// NK <--
	rNation.worldMapShip = "portuguese";
	//rNation.ShipNamePrefix = "PNS"; // PB: Portuguese Navy Ship (NATO designation, not used internally)
	rNation.FlagIdx = PORTUGAL; // KK
	rNation.laigroup = "CONCEICAO";

	if (period == PERIOD_EARLY_EXPLORERS) {
		//Location fantom models
		rNation.fantomModel.m0 = "offic_por_15"; //ARF fix
		rNation.fantomModel.m1 = "soldier_por_15";
		rNation.fantomModel.m2 = "soldier_por2_15";
		rNation.fantomModel.m3 = "soldier_por3_15";
		rNation.fantomModel.m4 = "soldier_por4_15";
		rNation.fantomModel.m5 = "soldier_por5_15";
		rNation.fantomModel.m6 = "soldier_por6_15";
		//Boarding models
		rNation.boardingModel.enemy.m1 = "offic_por_15"; //ARF fix
		rNation.boardingModel.enemy.m1.ani = "man";
		rNation.boardingModel.enemy.m2 = "soldier_por_15";
		rNation.boardingModel.enemy.m2.ani = "man";
		rNation.boardingModel.enemy.m3 = "soldier_por2_15";
		rNation.boardingModel.enemy.m3.ani = "man";
		rNation.boardingModel.enemy.m4 = "soldier_por3_15";
		rNation.boardingModel.enemy.m4.ani = "man";
		rNation.boardingModel.enemy.m5 = "soldier_por4_15";
		rNation.boardingModel.enemy.m5.ani = "man";
		rNation.boardingModel.enemy.m6 = "soldier_por5_15";
		rNation.boardingModel.enemy.m6.ani = "man";
		rNation.boardingModel.enemy.m7 = "soldier_por6_15";
		rNation.boardingModel.enemy.m7.ani = "man";
	} 
	if (period == PERIOD_THE_SPANISH_MAIN) {
		//Location fantom models
		rNation.fantomModel.m0 = "offic_por_16";
		rNation.fantomModel.m1 = "soldier_por_16";
		rNation.fantomModel.m2 = "soldier_por2_16";
		rNation.fantomModel.m3 = "soldier_por3_16";
		rNation.fantomModel.m4 = "soldier_por4_16";
		rNation.fantomModel.m5 = "soldier_por5_16";
		rNation.fantomModel.m6 = "soldier_por6_16";
		//Boarding models
		rNation.boardingModel.enemy.m1 = "offic_por_16"; //ARF fix
		rNation.boardingModel.enemy.m1.ani = "man";
		rNation.boardingModel.enemy.m2 = "soldier_por_16";
		rNation.boardingModel.enemy.m2.ani = "man";
		rNation.boardingModel.enemy.m3 = "soldier_por2_16";
		rNation.boardingModel.enemy.m3.ani = "man";
		rNation.boardingModel.enemy.m4 = "soldier_por3_16";
		rNation.boardingModel.enemy.m4.ani = "man";
		rNation.boardingModel.enemy.m5 = "soldier_por4_16";
		rNation.boardingModel.enemy.m5.ani = "man";
		rNation.boardingModel.enemy.m6 = "soldier_por5_16";
		rNation.boardingModel.enemy.m6.ani = "man";
		rNation.boardingModel.enemy.m7 = "soldier_por6_16";
		rNation.boardingModel.enemy.m7.ani = "man";
	}
	if (period == PERIOD_GOLDEN_AGE_OF_PIRACY) {
		rNation.fantomModel.m0 = "Offic_Por_172";
		rNation.fantomModel.m1 = "Soldier_Por1172";
		rNation.fantomModel.m2 = "Soldier_Por2172";
		rNation.fantomModel.m3 = "Soldier_Por3172";
		rNation.fantomModel.m4 = "Soldier_Por4172";
		rNation.fantomModel.m5 = "Soldier_Por5172";
		rNation.fantomModel.m6 = "Soldier_Por6172";
		//Boarding models
		rNation.boardingModel.enemy.m1 = "Offic_Por_172";
		rNation.boardingModel.enemy.m1.ani = "man";
		rNation.boardingModel.enemy.m2 = "Soldier_Por1172";
		rNation.boardingModel.enemy.m2.ani = "man";
		rNation.boardingModel.enemy.m3 = "Soldier_Por2172";
		rNation.boardingModel.enemy.m3.ani = "man";
		rNation.boardingModel.enemy.m4 = "Soldier_Por3172";
		rNation.boardingModel.enemy.m4.ani = "man";
		rNation.boardingModel.enemy.m5 = "Soldier_Por4172";
		rNation.boardingModel.enemy.m5.ani = "man";
		rNation.boardingModel.enemy.m6 = "Soldier_Por5172";
		rNation.boardingModel.enemy.m6.ani = "man";
		rNation.boardingModel.enemy.m7 = "Soldier_Por6172";
		rNation.boardingModel.enemy.m7.ani = "man";
	}
	if (period == PERIOD_COLONIAL_POWERS) {
		rNation.fantomModel.m0 = "Offic_Por_17";
		rNation.fantomModel.m1 = "Soldier_Por_17";
		rNation.fantomModel.m2 = "Soldier_Por2_17";
		rNation.fantomModel.m3 = "Soldier_Por3_17";
		rNation.fantomModel.m4 = "Soldier_Por4_17";
		rNation.fantomModel.m5 = "Soldier_Por5_17";
		rNation.fantomModel.m6 = "Soldier_Por6_17";
		//Boarding models
		rNation.boardingModel.enemy.m1 = "Offic_Por_17";
		rNation.boardingModel.enemy.m1.ani = "man";
		rNation.boardingModel.enemy.m2 = "Soldier_Por_17";
		rNation.boardingModel.enemy.m2.ani = "man";
		rNation.boardingModel.enemy.m3 = "Soldier_Por2_17";
		rNation.boardingModel.enemy.m3.ani = "man";
		rNation.boardingModel.enemy.m4 = "Soldier_Por3_17";
		rNation.boardingModel.enemy.m4.ani = "man";
		rNation.boardingModel.enemy.m5 = "Soldier_Por4_17";
		rNation.boardingModel.enemy.m5.ani = "man";
		rNation.boardingModel.enemy.m6 = "Soldier_Por5_17";
		rNation.boardingModel.enemy.m6.ani = "man";
		rNation.boardingModel.enemy.m7 = "Soldier_Por6_17";
		rNation.boardingModel.enemy.m7.ani = "man";
	}
	if (period == PERIOD_REVOLUTIONS) {
		rNation.fantomModel.m0 = "Offic_Por_18";
		rNation.fantomModel.m1 = "Soldier_Por_18";
		rNation.fantomModel.m2 = "Soldier_Por2_18";
		rNation.fantomModel.m3 = "Soldier_Por3_18";
		rNation.fantomModel.m4 = "Soldier_Por4_18";
		rNation.fantomModel.m5 = "Soldier_Por5_18";
		rNation.fantomModel.m6 = "Soldier_Por6_18";
		//Boarding models
		rNation.boardingModel.enemy.m1 = "Offic_Por_18";
		rNation.boardingModel.enemy.m1.ani = "man";
		rNation.boardingModel.enemy.m2 = "Soldier_Por_18";
		rNation.boardingModel.enemy.m2.ani = "man";
		rNation.boardingModel.enemy.m3 = "Soldier_Por2_18";
		rNation.boardingModel.enemy.m3.ani = "man";
		rNation.boardingModel.enemy.m4 = "Soldier_Por3_18";
		rNation.boardingModel.enemy.m4.ani = "man";
		rNation.boardingModel.enemy.m5 = "Soldier_Por4_18";
		rNation.boardingModel.enemy.m5.ani = "man";
		rNation.boardingModel.enemy.m6 = "Soldier_Por5_18";
		rNation.boardingModel.enemy.m6.ani = "man";
		rNation.boardingModel.enemy.m7 = "Soldier_Por6_18";
		rNation.boardingModel.enemy.m7.ani = "man";
	}
	if (period == PERIOD_NAPOLEONIC) {
		rNation.fantomModel.m0 = "Offic_Por_19";
		rNation.fantomModel.m1 = "Soldier_Por_19";
		rNation.fantomModel.m2 = "Soldier_Por2_19";
		rNation.fantomModel.m3 = "Soldier_Por3_19";
		rNation.fantomModel.m4 = "Soldier_Por4_19";
		rNation.fantomModel.m5 = "Soldier_Por5_19";
		rNation.fantomModel.m6 = "Soldier_Por6_19";
		//Boarding models
		rNation.boardingModel.enemy.m1 = "Offic_Por_19";
		rNation.boardingModel.enemy.m1.ani = "man";
		rNation.boardingModel.enemy.m2 = "Soldier_Por_19";
		rNation.boardingModel.enemy.m2.ani = "man";
		rNation.boardingModel.enemy.m3 = "Soldier_Por2_19";
		rNation.boardingModel.enemy.m3.ani = "man";
		rNation.boardingModel.enemy.m4 = "Soldier_Por3_19";
		rNation.boardingModel.enemy.m4.ani = "man";
		rNation.boardingModel.enemy.m5 = "Soldier_Por4_19";
		rNation.boardingModel.enemy.m5.ani = "man";
		rNation.boardingModel.enemy.m6 = "Soldier_Por5_19";
		rNation.boardingModel.enemy.m6.ani = "man";
		rNation.boardingModel.enemy.m7 = "Soldier_Por6_19";
		rNation.boardingModel.enemy.m7.ani = "man";
	}
	// NK -->
	rNation.Ranks.Quantity = 12;
	rNation.Ranks.1 = "Aspirante";
	rNation.Ranks.2 = "Subtenente";
	rNation.Ranks.3 = "Segundo-Tenente";
	rNation.Ranks.4 = "Primeiro-Tenente";
	rNation.Ranks.5 = "CapitÝo-Tenente";
	rNation.Ranks.6 = "CapitÝo-de-Fragata";
	rNation.Ranks.7 = "CapitÝo-de-Mar-e-Guerra";
	rNation.Ranks.8 = "Comodoro";
	rNation.Ranks.9 = "Contra-Almirante";
	rNation.Ranks.10 = "Vice-Almirante";
	rNation.Ranks.11 = "Almirante";
	rNation.Ranks.12 = "Almirante da Armada";
	rNation.Titles.Quantity = 12;
	rNation.Titles.1 = "Aspirante";
	rNation.Titles.2 = "Subtenente";
	rNation.Titles.3 = "Segundo-Tenente";
	rNation.Titles.4 = "Primeiro-Tenente";
	rNation.Titles.5 = "CapitÝo-Tenente";
	rNation.Titles.6 = "CapitÝo-de-Fragata";
	rNation.Titles.7 = "Cavaleiro";
	rNation.Titles.8 = "Baronete";
	rNation.Titles.9 = "BarÝo";
	rNation.Titles.10 = "Visconde";
	rNation.Titles.11 = "Conde";
	rNation.Titles.12 = "Marquês";
	// NK <--

// KK -->
	if (NATIONS_QUANTITY > 6)
	{
		if (period == PERIOD_REVOLUTIONS || period == PERIOD_NAPOLEONIC)
		{
			//USA
			makeref(rNation,Nations[AMERICA]);
			rNation.id = "America";
			rNation.Name = "America";
			// NK -->
			rNation.Desc = "American";
			// NK <--
			rNation.worldMapShip = "american";
			rNation.ShipNamePrefix = "USS"; // KK: United States Ship – Commissioned ships only
			rNation.FlagIdx = GUEST1_NATION; // KK
			rNation.laigroup = "AMERICA";

			//Location fantom models
			rNation.fantomModel.m0 = "USA_lut_18";
			rNation.fantomModel.m1 = "Soldier_USA_18";
			rNation.fantomModel.m2 = "Soldier_USA2_18";
			rNation.fantomModel.m3 = "Soldier_USA3_18";
			rNation.fantomModel.m4 = "Soldier_USA4_18";
			rNation.fantomModel.m5 = "Soldier_USA5_18";
			rNation.fantomModel.m6 = "Soldier_USA5_18";
			//Boarding models
			rNation.boardingModel.enemy.m1 = "USA_lut_18";
			rNation.boardingModel.enemy.m1.ani = "man";
			rNation.boardingModel.enemy.m2 = "Soldier_USA_18";
			rNation.boardingModel.enemy.m2.ani = "man";
			rNation.boardingModel.enemy.m3 = "Soldier_USA2_18";
			rNation.boardingModel.enemy.m3.ani = "man";
			rNation.boardingModel.enemy.m4 = "Soldier_USA3_18";
			rNation.boardingModel.enemy.m4.ani = "man";
			rNation.boardingModel.enemy.m5 = "Soldier_USA4_18";
			rNation.boardingModel.enemy.m5.ani = "man";
			rNation.boardingModel.enemy.m6 = "Soldier_USA5_18";
			rNation.boardingModel.enemy.m6.ani = "man";
			// NK -->
			rNation.Ranks.Quantity = 12;
			rNation.Ranks.1 = "Ensign";
			rNation.Ranks.2 = "Acting Lieutenant";
			rNation.Ranks.3 = "Lieutenant";
			rNation.Ranks.4 = "Senior Lieutenant";
			rNation.Ranks.5 = "Commander";
			rNation.Ranks.6 = "Post Captain";
			rNation.Ranks.7 = "Commodore";
			rNation.Ranks.8 = "Rear Admiral";
			rNation.Ranks.9 = "Vice Admiral";
			rNation.Ranks.10 = "Admiral";
			rNation.Ranks.11 = "Fleet Admiral";
			rNation.Ranks.12 = "Chief of Naval Operations";
			rNation.Titles.Quantity = 12;
			rNation.Titles.1 = "Ensign";
			rNation.Titles.2 = "Acting Lieutenant";
			rNation.Titles.3 = "Lieutenant";
			rNation.Titles.4 = "Senior Lieutenant";
			rNation.Titles.5 = "Commander";
			rNation.Titles.6 = "Captain";
			rNation.Titles.7 = "Commodore";
			rNation.Titles.8 = "Delegate";
			rNation.Titles.9 = "Representative";
			rNation.Titles.10 = "Senator Elect";
			rNation.Titles.11 = "Senator";
			rNation.Titles.12 = "Governor";
			// NK <--
		}
	
		if  (period == PERIOD_THE_SPANISH_MAIN || period == PERIOD_GOLDEN_AGE_OF_PIRACY || period == PERIOD_COLONIAL_POWERS)
		{	
			//SWEDEN
			makeref(rNation,Nations[SWEDEN]);
			rNation.id = "Sweden";
			rNation.Name = "Sweden";
			// NK -->
			rNation.Desc = "Swedish";
			// NK <--
			rNation.worldMapShip = "Swedish";
			rNation.ShipNamePrefix = "HSwMS"; //
			rNation.FlagIdx = SWEDEN; // KK
			rNation.laigroup = "SWEDEN";

			if(period == PERIOD_THE_SPANISH_MAIN) 
			{
				//Location fantom models
				rNation.fantomModel.m0 = "Offic_Swe_16";
				rNation.fantomModel.m1 = "Soldier_Swe_16";
				rNation.fantomModel.m2 = "Soldier_Swe2_16";
				rNation.fantomModel.m3 = "Soldier_Swe3_16";
				rNation.fantomModel.m4 = "Soldier_Swe4_16";
				rNation.fantomModel.m5 = "Soldier_Swe5_16";
				rNation.fantomModel.m6 = "Soldier_Swe6_16";
				//Boarding models
				rNation.boardingModel.enemy.m1 = "Offic_Swe_16";
				rNation.boardingModel.enemy.m1.ani = "man";
				rNation.boardingModel.enemy.m2 = "Soldier_Swe_16";
				rNation.boardingModel.enemy.m2.ani = "man";
				rNation.boardingModel.enemy.m3 = "Soldier_Swe2_16";
				rNation.boardingModel.enemy.m3.ani = "man";
				rNation.boardingModel.enemy.m4 = "Soldier_Swe3_16";
				rNation.boardingModel.enemy.m4.ani = "man";
				rNation.boardingModel.enemy.m5 = "Soldier_Swe4_16";
				rNation.boardingModel.enemy.m5.ani = "man";
				rNation.boardingModel.enemy.m6 = "Soldier_Swe5_16";
				rNation.boardingModel.enemy.m6.ani = "man";
				rNation.boardingModel.enemy.m7 = "Soldier_Swe6_16";
				rNation.boardingModel.enemy.m7.ani = "man";
			}

			if(period == PERIOD_GOLDEN_AGE_OF_PIRACY || period == PERIOD_COLONIAL_POWERS)
			{
				//Location fantom models
				rNation.fantomModel.m0 = "Dragoon_Swe_18";
				rNation.fantomModel.m1 = "Soldier_Swe3_18";
				rNation.fantomModel.m2 = "Soldier_Swe9_18";
				rNation.fantomModel.m3 = "Soldier_Swe10_18";
				rNation.fantomModel.m4 = "Soldier_Swe13_18";
				rNation.fantomModel.m5 = "Soldier_Swe14_18";
				rNation.fantomModel.m6 = "Soldier_Swe6_18";
				//Boarding models
				rNation.boardingModel.enemy.m1 = "Dragoon_Swe_18";
				rNation.boardingModel.enemy.m1.ani = "man";
				rNation.boardingModel.enemy.m2 = "Soldier_Swe3_18";
				rNation.boardingModel.enemy.m2.ani = "man";
				rNation.boardingModel.enemy.m3 = "Soldier_Swe9_18";
				rNation.boardingModel.enemy.m3.ani = "man";
				rNation.boardingModel.enemy.m4 = "Soldier_Swe10_18";
				rNation.boardingModel.enemy.m4.ani = "man";
				rNation.boardingModel.enemy.m5 = "Soldier_Swe13_18";
				rNation.boardingModel.enemy.m5.ani = "man";
				rNation.boardingModel.enemy.m6 = "Soldier_Swe14_18";
				rNation.boardingModel.enemy.m6.ani = "man";
				rNation.boardingModel.enemy.m7 = "Soldier_Swe6_18";
				rNation.boardingModel.enemy.m7.ani = "man";
			}

			// JRH -->
			rNation.Ranks.Quantity = 12;
			rNation.Ranks.1 = "Underlöjtnant";
			rNation.Ranks.2 = "Överlöjtnant";
			rNation.Ranks.3 = "Kaptenlöjtnant";
			rNation.Ranks.4 = "Kapten";
			rNation.Ranks.5 = "Örlogskapten";
			rNation.Ranks.6 = "Kommendörkapten";
			rNation.Ranks.7 = "Kommendör";
			rNation.Ranks.8 = "Schoutbynacht";
			rNation.Ranks.9 = "Konteramiral";
			rNation.Ranks.10 = "Viceamiral";
			rNation.Ranks.11 = "Amiral";
			rNation.Ranks.12 = "Riksamiral";
			rNation.Titles.Quantity = 12;
			rNation.Titles.1 = "Underlöjtnant";
			rNation.Titles.2 = "Överlöjtnant";
			rNation.Titles.3 = "Kaptenlöjtnant";
			rNation.Titles.4 = "Kapten";
			rNation.Titles.5 = "Örlogskapten";
			rNation.Titles.6 = "Kommendörkapten";
			rNation.Titles.7 = "Riddare";
			rNation.Titles.8 = "Friherre";
			rNation.Titles.9 = "Greve";
			rNation.Titles.10 = "Borgmästare";
			rNation.Titles.11 = "Landshövding";
			rNation.Titles.12 = "Riksråd";
			// JRH <--
		}
	}
// <-- KK

	//Player boarding command
	for(int i = 0; i < NATIONS_QUANTITY; i++)
	{
		makeref(rNation, Nations[i]);
//NK -->
		rNation.boardingModel.player.m0 = "black_corsair";
		rNation.boardingModel.player.m0.ani = "man";
		rNation.boardingModel.player.m1 = "sailor1";
		rNation.boardingModel.player.m1.ani = "man";
		rNation.boardingModel.player.m2 = "sailor2";
		rNation.boardingModel.player.m2.ani = "man";
		rNation.boardingModel.player.m3 = "sailor3";
		rNation.boardingModel.player.m3.ani = "man";
		rNation.boardingModel.player.m4 = "sailor4";
		rNation.boardingModel.player.m4.ani = "man";
		rNation.boardingModel.player.m5 = "sailor5";
		rNation.boardingModel.player.m5.ani = "man";
		rNation.boardingModel.player.m6 = "sailor6";
		rNation.boardingModel.player.m6.ani = "man";
		rNation.boardingModel.player.m7 = "bocman4";
		rNation.boardingModel.player.m7.ani = "man";
		rNation.boardingModel.player.m8 = "chameleon";
		rNation.boardingModel.player.m8.ani = "man";
		rNation.boardingModel.player.m9 = "bocman8";
		rNation.boardingModel.player.m9.ani = "man";
		rNation.boardingModel.player.m10 = "sailor16";
		rNation.boardingModel.player.m10.ani = "man";
		rNation.boardingModel.player.m11 = "sailor19";
		rNation.boardingModel.player.m11.ani = "man";
		rNation.boardingModel.player.m12 = "sailor13";
		rNation.boardingModel.player.m12.ani = "man";
		rNation.boardingModel.player.m13 = "sailor14";
		rNation.boardingModel.player.m13.ani = "man";
		rNation.boardingModel.player.m14 = "sailor10";
		rNation.boardingModel.player.m14.ani = "man";
		rNation.boardingModel.player.m15 = "bocman10";
		rNation.boardingModel.player.m15.ani = "man";
		rNation.boardingModel.player.m16 = "bocman16";
		rNation.boardingModel.player.m16.ani = "man";
		rNation.boardingModel.player.m17 = "bocman17";
		rNation.boardingModel.player.m17.ani = "man";
//NK <--
	}

	trace("InitNations: NATIONS_QUANTITY="+NATIONS_QUANTITY+", bGuest1NationExists="+bGuest1NationExists+", bGuest2NationExists="+bGuest2NationExists); // KK
	//Trace("Init nations complete.");
}
