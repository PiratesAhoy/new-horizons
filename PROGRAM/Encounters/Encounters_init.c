// NK change all instances of merchant to trade
void Enc_ExcludeNation(ref rEnc, int iNation)
{
	string sNation = GetNationIDByType(iNation); // PB: was Nations[iNation].Name
	rEnc.Nation.Exclude.(sNation) = true;
}

void Enc_AddShips(ref rEnc, string sEType, int iShipsMin, int iShipsMax)
{
	rEnc.(sEType).ShipsMin = iShipsMin;		rEnc.(sEType).ShipsMax = iShipsMax;
}

void Enc_AddClasses(ref rEnc, int iRank, int iMClassMin, int iMClassMax, int iWClassMin, int iWClassMax)
{
	string sRank = "Rank." + iRank;
	rEnc.(sRank).0 = iMClassMin; rEnc.(sRank).1 = iMClassMax;
	rEnc.(sRank).2 = iWClassMin; rEnc.(sRank).3 = iWClassMax;
}

void InitEncounters()
{
	int i, n;
	ref rEnc;

	//find max pirate classes allowed
	int maxpirate1 = 1;
	int maxpirate2 = 2;
	int maxpirate3_1 = 3;
	int maxpirate3_2 = 3;
	if(MAXPIRATECLASS > maxpirate3_1)
	{
		maxpirate1 = MAXPIRATECLASS;
		maxpirate2 = MAXPIRATECLASS;
		maxpirate3_1 = MAXPIRATECLASS;
		maxpirate3_2 = MAXPIRATECLASS;
	}
	else
	{
		if(MAXPIRATECLASS > maxpirate2)
		{
			maxpirate1 = MAXPIRATECLASS;
			maxpirate2 = MAXPIRATECLASS;
			maxpirate3_1 = MAXPIRATECLASS;
			maxpirate3_2 = MAXPIRATECLASS + 1;
		}
		else
		{
			if(MAXPIRATECLASS > maxpirate1)
			{
				maxpirate1 = MAXPIRATECLASS;
				maxpirate2 = MAXPIRATECLASS + 1;
				maxpirate3_1 = MAXPIRATECLASS + 1;
				maxpirate3_2 = MAXPIRATECLASS + 2;
			}
		}
	}
//rest the same until new encounters, but maxpirateX subbed for hard numbers, and pirate has been turned off for everything but pirate encounters.

	for (i = 0; i < MAX_ENCOUNTER_TYPES; i++)
	{
		makeref(rEnc, EncountersTypes[i]);
		DeleteAttribute(&rEnc,"");
		rEnc.Index = i;
		rEnc.Chance = 10; // NK 05-05-11 switch to one big array, not frnd() and loop.
		rEnc.Skip = true;
		rEnc.MinRank = 1;
		rEnc.MaxRank = 1000;
		rEnc.Trade.ShipsMin = 0;		rEnc.Trade.ShipsMax = 0;
		rEnc.War.ShipsMin = 0;			rEnc.War.ShipsMax = 0;
		rEnc.Type = ENCOUNTER_TRADE;
	}
	n = 0;
	ENCOUNTERS_QUANTITY = 0;
	// ======================== TRADE ENCOUNTERS ========================

	// small merchant: 3 + 0
	makeref(rEnc, EncountersTypes[ENCOUNTER_TYPE_MERCHANT0]);
	n++; rEnc.Skip = false;
	rEnc.Type = ENCOUNTER_TRADE;
	rEnc.MinRank = 1;
	Enc_AddShips(rEnc, "Trade", 1, 3);
	Enc_ExcludeNation(rEnc, PIRATE);

	Enc_AddClasses(rEnc, 1, 5, 6, 0, 0);
	Enc_AddClasses(rEnc, 2, 5, 6, 0, 0);
	Enc_AddClasses(rEnc, 3, 4, 6, 0, 0);
	Enc_AddClasses(rEnc, 4, 4, 6, 0, 0);
	Enc_AddClasses(rEnc, 5, 3, 6, 0, 0);
	Enc_AddClasses(rEnc, 6, 3, 6, 0, 0);
	Enc_AddClasses(rEnc, 7, 3, 6, 0, 0);
	Enc_AddClasses(rEnc, 8, 3, 5, 0, 0);
	Enc_AddClasses(rEnc, 9, 3, 5, 0, 0);
	Enc_AddClasses(rEnc, 10,3, 5, 0, 0);
	Enc_AddClasses(rEnc, -1,4, 6, 0, 0); // NK for shipcap off

	// medium merchant: 2 + 1
	makeref(rEnc, EncountersTypes[ENCOUNTER_TYPE_MERCHANT1]);
	n++; rEnc.Skip = false;
	rEnc.Type = ENCOUNTER_TRADE;
	rEnc.MinRank = 3;
	Enc_AddShips(rEnc, "Trade", 2, 3);
	Enc_AddShips(rEnc, "War", 1, 1);
	Enc_ExcludeNation(rEnc, PIRATE);

	Enc_AddClasses(rEnc, 3, 4, 6, 4, 6);
	Enc_AddClasses(rEnc, 4, 4, 6, 4, 6);
	Enc_AddClasses(rEnc, 5, 3, 6, 3, 5);
	Enc_AddClasses(rEnc, 6, 3, 6, 3, 5);
	Enc_AddClasses(rEnc, 7, 3, 6, 2, 4);
	Enc_AddClasses(rEnc, 8, 3, 5, 2, 4);
	Enc_AddClasses(rEnc, 9, 3, 5, 2, 4);
	Enc_AddClasses(rEnc, 10,3, 5, 2, 4);
	Enc_AddClasses(rEnc, -1,4, 6, 3, 6); // NK for shipcap off

	// large merchant: 1 + 3
	makeref(rEnc, EncountersTypes[ENCOUNTER_TYPE_MERCHANT2]);
	n++; rEnc.Skip = false;
	rEnc.Type = ENCOUNTER_TRADE;
	rEnc.MinRank = 4;
	Enc_AddShips(rEnc, "Trade", 1, 1);
	Enc_AddShips(rEnc, "War", 2, 3);
	Enc_ExcludeNation(rEnc, PIRATE);

	Enc_AddClasses(rEnc, 4, 4, 5, 3, 5);
	Enc_AddClasses(rEnc, 5, 4, 5, 3, 5);
	Enc_AddClasses(rEnc, 6, 3, 5, 2, 5);
	Enc_AddClasses(rEnc, 7, 3, 5, 2, 5);
	Enc_AddClasses(rEnc, 8, 3, 5, 2, 4);
	Enc_AddClasses(rEnc, 9, 3, 5, 2, 4);
	Enc_AddClasses(rEnc, 10,3, 5, 2, 4);
	Enc_AddClasses(rEnc, -1,MAXMERCHANTCLASS, 5, 2, 4); // NK for shipcap off

// ======================== WAR ENCOUNTERS ========================
	makeref(rEnc, EncountersTypes[ENCOUNTER_TYPE_PATROL]);	// 0 + 3
	n++; rEnc.Skip = false;
	rEnc.Type = ENCOUNTER_WAR;
	rEnc.MinRank = 2;
	Enc_AddShips(rEnc, "War", 1, 3);
	Enc_ExcludeNation(rEnc, PIRATE);

	Enc_AddClasses(rEnc, 3, 0, 0, 5, 6);
	Enc_AddClasses(rEnc, 4, 0, 0, 4, 6);
	Enc_AddClasses(rEnc, 5, 0, 0, 4, 6);
	Enc_AddClasses(rEnc, 6, 0, 0, 3, 5);
	Enc_AddClasses(rEnc, 7, 0, 0, 3, 5);
	Enc_AddClasses(rEnc, 8, 0, 0, 2, 4);
	Enc_AddClasses(rEnc, 9, 0, 0, 2, 4);
	Enc_AddClasses(rEnc, 10,0, 0, 2, 4);
	Enc_AddClasses(rEnc, -1,0, 0, 3, 5); // NK for shipcap off

// 
	makeref(rEnc, EncountersTypes[ENCOUNTER_TYPE_FLEET]);	// 0 + 4
	n++; rEnc.Skip = false;
	rEnc.Type = ENCOUNTER_WAR;
	rEnc.MinRank = 5;
	Enc_AddShips(rEnc, "War", 3, 4);
	Enc_ExcludeNation(rEnc, PIRATE);

	Enc_AddClasses(rEnc, 5, 0, 0, 2, 4);
	Enc_AddClasses(rEnc, 6, 0, 0, 1, 4);
	Enc_AddClasses(rEnc, 7, 0, 0, 1, 4);
	Enc_AddClasses(rEnc, 8, 0, 0, 1, 3);
	Enc_AddClasses(rEnc, 9, 0, 0, 1, 3);
	Enc_AddClasses(rEnc, 10,0, 0, 1, 2);
	Enc_AddClasses(rEnc, -1,0, 0, 2, 4); // NK for shipcap off

// 
	makeref(rEnc, EncountersTypes[ENCOUNTER_TYPE_CORSAR]);	// 0 + 3
	n++; rEnc.Skip = false;
	Enc_AddShips(rEnc, "War", 1, 3);
	rEnc.MinRank = 3;
	rEnc.Type = ENCOUNTER_WAR;
	Enc_ExcludeNation(rEnc, ENGLAND);
	Enc_ExcludeNation(rEnc, FRANCE);
	Enc_ExcludeNation(rEnc, SPAIN);
	// !!!PIRATE ONLY!!! //
	Enc_ExcludeNation(rEnc, HOLLAND);
	Enc_ExcludeNation(rEnc, PORTUGAL);
	if (bGuest1NationExists) Enc_ExcludeNation(rEnc, GUEST1_NATION);
	if (bGuest2NationExists) Enc_ExcludeNation(rEnc, GUEST2_NATION);

	Enc_AddClasses(rEnc, 3, 0, 0, 4, 5);
	Enc_AddClasses(rEnc, 4, 0, 0, 4, 5);
	Enc_AddClasses(rEnc, 5, 0, 0, maxpirate3_2, 5);
	Enc_AddClasses(rEnc, 6, 0, 0, maxpirate3_1, 5);
	Enc_AddClasses(rEnc, 7, 0, 0, maxpirate2, 5);
	Enc_AddClasses(rEnc, 8, 0, 0, maxpirate2, 5);
	Enc_AddClasses(rEnc, 9, 0, 0, maxpirate1, 5);
	Enc_AddClasses(rEnc, 10,0, 0, maxpirate1, 5);
	Enc_AddClasses(rEnc, -1,0, 0, maxpirate2, 5); // NK for shipcap off

// 
	makeref(rEnc, EncountersTypes[ENCOUNTER_TYPE_PIRATE]);	// 0 + 2
	n++; rEnc.Skip = false;
	Enc_AddShips(rEnc, "War", 1, 2);
	rEnc.MinRank = 1;
	rEnc.MaxRank = 6;
	rEnc.Type = ENCOUNTER_WAR;
	Enc_ExcludeNation(rEnc, ENGLAND);
	Enc_ExcludeNation(rEnc, FRANCE);
	Enc_ExcludeNation(rEnc, SPAIN);
	// !!!PIRATE ONLY!!! //
	Enc_ExcludeNation(rEnc, HOLLAND);
	Enc_ExcludeNation(rEnc, PORTUGAL);
	if (bGuest1NationExists) Enc_ExcludeNation(rEnc, GUEST1_NATION);
	if (bGuest2NationExists) Enc_ExcludeNation(rEnc, GUEST2_NATION);

	Enc_AddClasses(rEnc, 1, 0, 0, 6, 6);
	Enc_AddClasses(rEnc, 2, 0, 0, 6, 6);
	Enc_AddClasses(rEnc, 3, 0, 0, 5, 6);
	Enc_AddClasses(rEnc, 4, 0, 0, 5, 6);
	Enc_AddClasses(rEnc, 5, 0, 0, 4, 6);
	Enc_AddClasses(rEnc, -1,0, 0, 4, 6); // NK for shipcap off

// Punitive squadron
	makeref(rEnc, EncountersTypes[ENCOUNTER_TYPE_PUNITIVE_SQUADRON]);	// 0 + 2
	n++; rEnc.Skip = false;
//max now 8; rest of this unchanged.
	Enc_AddShips(rEnc, "War", 2, 8);
	rEnc.Skip = true;
	rEnc.MinRank = 1;
	rEnc.Type = ENCOUNTER_WAR;
	Enc_ExcludeNation(rEnc, PIRATE);
	if(GetCurrentPeriod() <= PERIOD_EARLY_EXPLORERS)	// Only Spain and Portugal had large fleets in 16th century
	{
		Enc_ExcludeNation(rEnc, ENGLAND);
		Enc_ExcludeNation(rEnc, FRANCE);
		Enc_ExcludeNation(rEnc, HOLLAND);
	}

	Enc_AddClasses(rEnc, 1, 0, 0, 5, 6);
	Enc_AddClasses(rEnc, 2, 0, 0, 5, 5);
	Enc_AddClasses(rEnc, 3, 0, 0, 4, 5);
	Enc_AddClasses(rEnc, 4, 0, 0, 4, 4);
	Enc_AddClasses(rEnc, 5, 0, 0, 3, 5);
	Enc_AddClasses(rEnc, 6, 0, 0, 3, 4);
	Enc_AddClasses(rEnc, 7, 0, 0, 3, 3);
	Enc_AddClasses(rEnc, 8, 0, 0, 2, 3);
	Enc_AddClasses(rEnc, 9, 0, 0, 2, 3);
	Enc_AddClasses(rEnc, 10,0, 0, 1, 3);
	Enc_AddClasses(rEnc, -1,0, 0, 2, 4); // NK for shipcap off

// new encounters ->
// ======================== TRADE ENCOUNTERS ========================

// MERCHANT FLEET - LOCAL (shallow waters) - merchant class 3-7 - NO ESCORT 
	makeref(rEnc, EncountersTypes[ENCOUNTER_TYPE_LMERCHANT0]);
	n++; rEnc.Skip = false;
	rEnc.Type = ENCOUNTER_TRADE;
	rEnc.Chance = 7;
	rEnc.MinRank = 1;
	Enc_AddShips(rEnc, "Trade", 2, 8);
	Enc_ExcludeNation(rEnc, PIRATE);

	Enc_AddClasses(rEnc, 1, 7, 7, 0, 0);
	Enc_AddClasses(rEnc, 2, 6, 7, 0, 0);
	Enc_AddClasses(rEnc, 3, 6, 7, 0, 0);
	Enc_AddClasses(rEnc, 4, 5, 6, 0, 0);
	Enc_AddClasses(rEnc, 5, 5, 6, 0, 0);
	Enc_AddClasses(rEnc, 6, 4, 6, 0, 0);
	Enc_AddClasses(rEnc, 7, 4, 6, 0, 0);
	Enc_AddClasses(rEnc, 8, 3, 5, 0, 0);
	Enc_AddClasses(rEnc, 9, 3, 5, 0, 0);
	Enc_AddClasses(rEnc, 10,3, 5, 0, 0);
	Enc_AddClasses(rEnc, -1,MAXMERCHANTCLASS, 5, 0, 0); // NK for shipcap off

// MERCHANT FLEET - REGIONAL (coastal waters) - merchants - ESCORTED by warships
	makeref(rEnc, EncountersTypes[ENCOUNTER_TYPE_LMERCHANT1]);
	n++; rEnc.Skip = false;
	rEnc.Type = ENCOUNTER_TRADE;
	rEnc.Chance = 5;
	rEnc.MinRank = 4;
	Enc_AddShips(rEnc, "Trade", 3, 6);
	Enc_AddShips(rEnc, "War", 1, 4);
	Enc_ExcludeNation(rEnc, PIRATE);

	Enc_AddClasses(rEnc, 4, 5, 6, 4, 6);
	Enc_AddClasses(rEnc, 5, 5, 6, 4, 5);
	Enc_AddClasses(rEnc, 6, 4, 6, 4, 5);
	Enc_AddClasses(rEnc, 7, 4, 5, 3, 4);
	Enc_AddClasses(rEnc, 8, 3, 5, 3, 4);
	Enc_AddClasses(rEnc, 9, 3, 5, 3, 3);
	Enc_AddClasses(rEnc, 10,3, 4, 2, 3);
	Enc_AddClasses(rEnc, 12,3, 4, 2, 3);
	Enc_AddClasses(rEnc, -1,MAXMERCHANTCLASS, 5, 2, 4); // NK for shipcap off

// TREASURE FLEET!!! - TRANS ATLANTIC (deep ocean waters) merchants - ESCORTED by warships
	makeref(rEnc, EncountersTypes[ENCOUNTER_TYPE_LMERCHANT2]);
	n++; rEnc.Skip = false;
	if(GetCurrentPeriod() >= PERIOD_NAPOLEONIC) rEnc.Skip = true; // PB: No Treasure Fleets after 1790
	rEnc.Type = ENCOUNTER_TRADE;
	rEnc.Chance = 3;
	rEnc.MinRank = 5;
	Enc_AddShips(rEnc, "Trade", 2, 4);
	Enc_AddShips(rEnc, "War", 2, 6);
	Enc_ExcludeNation(rEnc, ENGLAND);
	Enc_ExcludeNation(rEnc, FRANCE);
	// !!!SPAIN ONLY!!! //
	Enc_ExcludeNation(rEnc, PIRATE);
	Enc_ExcludeNation(rEnc, HOLLAND);
	Enc_ExcludeNation(rEnc, PORTUGAL);
	if (bGuest1NationExists) Enc_ExcludeNation(rEnc, GUEST1_NATION);
	if (bGuest2NationExists) Enc_ExcludeNation(rEnc, GUEST2_NATION);

	Enc_AddClasses(rEnc, 5, 3, 5, 3, 4);
	Enc_AddClasses(rEnc, 7, 3, 5, 2, 4);
	Enc_AddClasses(rEnc, 8, 3, 5, 2, 3);
	Enc_AddClasses(rEnc, 11,3, 5, 2, 3);
	Enc_AddClasses(rEnc, -1,MAXMERCHANTCLASS, 5, 1, 4); // NK for shipcap off

// ======================== WAR ENCOUNTERS ========================

// MILITARY - LOCAL PATROL (shallow waters) - Nations guarding their territorial waters
	makeref(rEnc, EncountersTypes[ENCOUNTER_TYPE_LPATROL]);
	n++; rEnc.Skip = false;
	rEnc.Type = ENCOUNTER_WAR;
	rEnc.Chance = 5;
	rEnc.MinRank = 1;
	Enc_AddShips(rEnc, "War", 2, 8);
	Enc_ExcludeNation(rEnc, PIRATE);
	if(GetCurrentPeriod() <= PERIOD_EARLY_EXPLORERS)	// England, France and Holland had no large fleets in 16th century
	{
		Enc_ExcludeNation(rEnc, ENGLAND);
		Enc_ExcludeNation(rEnc, FRANCE);
		Enc_ExcludeNation(rEnc, HOLLAND);
	}
	if(GetCurrentPeriod() <= PERIOD_EARLY_EXPLORERS || GetCurrentPeriod() >= PERIOD_NAPOLEONIC) Enc_ExcludeNation(rEnc, PORTUGAL);

	Enc_AddClasses(rEnc, 1, 0, 0, 5, 6);
	Enc_AddClasses(rEnc, 3, 0, 0, 4, 6);
	Enc_AddClasses(rEnc, 5, 0, 0, 3, 5);
	Enc_AddClasses(rEnc, 7, 0, 0, 3, 4);
	Enc_AddClasses(rEnc, 9, 0, 0, 2, 4);
	Enc_AddClasses(rEnc, 12,0, 0, 2, 3);
	Enc_AddClasses(rEnc, -1,0, 0, 2, 4); // NK for shipcap off


// MILITARY - REGIONAL PATROL (coastal waters) - enough guns to take you out so watch it!
	makeref(rEnc, EncountersTypes[ENCOUNTER_TYPE_LFLEET]);
	n++; rEnc.Skip = false;
	rEnc.Type = ENCOUNTER_WAR;
	rEnc.Chance = 3;
	rEnc.MinRank = 2;
	Enc_AddShips(rEnc, "War", 4, 8);
	Enc_ExcludeNation(rEnc, PIRATE);
	if(GetCurrentPeriod() <= PERIOD_EARLY_EXPLORERS || GetCurrentPeriod() >= PERIOD_NAPOLEONIC) Enc_ExcludeNation(rEnc, HOLLAND);
	if(GetCurrentPeriod() <= PERIOD_EARLY_EXPLORERS || GetCurrentPeriod() >= PERIOD_NAPOLEONIC) Enc_ExcludeNation(rEnc, PORTUGAL);
	if(GetCurrentPeriod() <= PERIOD_EARLY_EXPLORERS) Enc_ExcludeNation(rEnc, ENGLAND);
	if(GetCurrentPeriod() <= PERIOD_EARLY_EXPLORERS) Enc_ExcludeNation(rEnc, FRANCE);

	Enc_AddClasses(rEnc, 2, 0, 0, 3, 5);
	Enc_AddClasses(rEnc, 4, 0, 0, 2, 5);
	Enc_AddClasses(rEnc, 6, 0, 0, 2, 4);
	Enc_AddClasses(rEnc, 9, 0, 0, 2, 3);
	Enc_AddClasses(rEnc, 11,0, 0, 1, 3);
	Enc_AddClasses(rEnc, 14,0, 0, 1, 3);
	Enc_AddClasses(rEnc, -1,0, 0, 1, 3); // NK for shipcap off

// ARMADA!!! - TRANS ATLANTIC (deep ocean waters) - heavyweights looking for another Battle of Trafalgar
	makeref(rEnc, EncountersTypes[ENCOUNTER_TYPE_LCORSAR]);
	n++; rEnc.Skip = false;
	Enc_AddShips(rEnc, "War", 6, 10);
	rEnc.MinRank = 3;
	rEnc.Type = ENCOUNTER_WAR;
	rEnc.Chance = 1;
	Enc_ExcludeNation(rEnc, PIRATE);
	if(GetCurrentPeriod() <= PERIOD_EARLY_EXPLORERS || GetCurrentPeriod() >= PERIOD_NAPOLEONIC) Enc_ExcludeNation(rEnc, HOLLAND);
	if(GetCurrentPeriod() <= PERIOD_EARLY_EXPLORERS || GetCurrentPeriod() >= PERIOD_NAPOLEONIC) Enc_ExcludeNation(rEnc, PORTUGAL);
	if(GetCurrentPeriod() <= PERIOD_EARLY_EXPLORERS)	// England and France had no large fleets in 16th century
	{
		Enc_ExcludeNation(rEnc, ENGLAND);
		Enc_ExcludeNation(rEnc, FRANCE);
	}

	Enc_AddClasses(rEnc, 3, 0, 0, 3, 4);
	Enc_AddClasses(rEnc, 4, 0, 0, 2, 3);
	Enc_AddClasses(rEnc, 6, 0, 0, 2, 3);
	Enc_AddClasses(rEnc, 8, 0, 0, 1, 3);
	Enc_AddClasses(rEnc, 10,0, 0, 1, 3);
	Enc_AddClasses(rEnc, 12,0, 0, 1, 3);
	Enc_AddClasses(rEnc, -1,0, 0, 1, 3); // NK for shipcap off

// PIRATES OF THE CARIBBEAN
	makeref(rEnc, EncountersTypes[ENCOUNTER_TYPE_LPIRATE]);
	n++; rEnc.Skip = false;
	Enc_AddShips(rEnc, "War", 1, 3);
	Enc_AddShips(rEnc, "Trade", 1, 2);
	rEnc.MinRank = 1;
	rEnc.Type = ENCOUNTER_WAR;
	Enc_ExcludeNation(rEnc, ENGLAND);
	Enc_ExcludeNation(rEnc, FRANCE);
	Enc_ExcludeNation(rEnc, SPAIN);
	// !!!PIRATE ONLY!!! //
	Enc_ExcludeNation(rEnc, HOLLAND);
	Enc_ExcludeNation(rEnc, PORTUGAL);
	if (bGuest1NationExists) Enc_ExcludeNation(rEnc, GUEST1_NATION);
	if (bGuest2NationExists) Enc_ExcludeNation(rEnc, GUEST2_NATION);

	Enc_AddClasses(rEnc, 1, 5, 6, 5, 6);
	Enc_AddClasses(rEnc, 2, 5, 6, 5, 6);
	Enc_AddClasses(rEnc, 3, 5, 5, 4, 6);
	Enc_AddClasses(rEnc, 4, 5, 5, 4, 5);
	Enc_AddClasses(rEnc, 5, 4, 5, maxpirate3_2, 5);
	Enc_AddClasses(rEnc, 6, 4, 5, maxpirate3_1, 5);
	Enc_AddClasses(rEnc, 7, 4, 5, maxpirate2, 5);
	Enc_AddClasses(rEnc, 8, 3, 5, maxpirate2, 5);
	Enc_AddClasses(rEnc, 9, 3, 4, maxpirate1, 5);
	Enc_AddClasses(rEnc, 10,3, 4, maxpirate1, maxpirate3_2);
	Enc_AddClasses(rEnc, -1,6, 8, 6, 8); // NK for shipcap off

// PUNITIVE SQUADRON!!! - the Governor quickly commandeered all seaworthy gunships in his harbor to hunt you down. 
// NK edit for maxshipclass rankscale
	makeref(rEnc, EncountersTypes[ENCOUNTER_TYPE_LPUNITIVE_SQUADRON]); 
	n++; rEnc.Skip = false;
	Enc_AddShips(rEnc, "War", 3, 8);
	//rEnc.Skip = true;
	rEnc.MinRank = 3;
	rEnc.Type = ENCOUNTER_WAR;
	rEnc.Chance = 7;
	Enc_ExcludeNation(rEnc, PIRATE);
	if(GetCurrentPeriod() <= PERIOD_EARLY_EXPLORERS || GetCurrentPeriod() >= PERIOD_NAPOLEONIC) Enc_ExcludeNation(rEnc, HOLLAND);
	if(GetCurrentPeriod() <= PERIOD_EARLY_EXPLORERS || GetCurrentPeriod() >= PERIOD_NAPOLEONIC) Enc_ExcludeNation(rEnc, PORTUGAL);
	if(GetCurrentPeriod() <= PERIOD_EARLY_EXPLORERS)	// England and France had no large fleets in 16th century
	{
		Enc_ExcludeNation(rEnc, ENGLAND);
		Enc_ExcludeNation(rEnc, FRANCE);
	}

	Enc_AddClasses(rEnc, 3, 0, 0, 4, 6);
	Enc_AddClasses(rEnc, 5, 0, 0, 3, 6);
	Enc_AddClasses(rEnc, 7, 0, 0, 2, 5);
	Enc_AddClasses(rEnc, 9, 0, 0, 2, 4);
	Enc_AddClasses(rEnc, 11,0, 0, 1, 5);
	Enc_AddClasses(rEnc, 13,0, 0, 1, 4);
	Enc_AddClasses(rEnc, -1,0, 0, 1, 4); // NK for shipcap off

	ENCOUNTERS_QUANTITY = n;

	Trace("Init encounters complete.");
}