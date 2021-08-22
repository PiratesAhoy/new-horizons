#define ENCOUNTER_GROUP		"egroup__"

int FindFreeMapEncounterSlot()
{
	for (int i=0;i<MAX_MAP_ENCOUNTERS;i++) 
	{
		if(sti(MapEncounters[i].bUse) == false) return i;
	}
	//Trace("FindFreeMapEncounterSlot: Can't find free slot!!!");
	return -1;
}

void ManualReleaseMapEncounter(int iEncounterSlot)
{
	DeleteAttribute(&MapEncounters[iEncounterSlot], "");
	MapEncounters[iEncounterSlot].bUse = false;
}

void ReleaseMapEncounters()
{
	for (int i=0;i<MAX_MAP_ENCOUNTERS;i++) 
	{
		DeleteAttribute(&MapEncounters[i],"");
		MapEncounters[i].bUse = false;
	}
}

void ReleaseMapEncounter(int iEncounterSlot)
{
	//Trace("Release encounter with slot " + iEncounterSlot);
	if(sti(MapEncounters[iEncounterSlot].bUse) == true)
	{
		DeleteAttribute(&MapEncounters[iEncounterSlot],"");
		MapEncounters[iEncounterSlot].bUse = false;
		return;
	}
	//Trace("ReleaseMapEncounter: ERROR: Encounter not used idx = " + iEncounterSlot);
}

ref GetMapEncounterRef(int iEncounterSlot)
{
	return &MapEncounters[iEncounterSlot];
}

ref GetMapEncounterNationRef(int iEncounterSlot)
{
	if(sti(MapEncounters[iEncounterSlot].bUse) == true)
	{
		return GetNationByType(sti(MapEncounters[iEncounterSlot].Nation));
	}
	//Trace("GetMapEncounterNationString: error: not found use slot iEncounterSlot = " + iEncounterSlot);
	return GetNationByType(ENGLAND);
}

bool GenerateMapEncounter(int iMapEncounterType, string sIslandID, ref iEncounter1, ref iEncounter2)
{
	iEncounter1 = -1;
	iEncounter2 = -1;

	bool bReturn = false;
	int iNearIslandNation = PIRATE;

	// NK 05-06-27 actually get island nation.
	if(sIslandID != "")
	{
		if(!Island_IsEncountersEnable(sIslandID)) {	return false; }

		ref isl = GetIslandByID(worldMap.islands.(wdmCurrentIsland).name);
		iNearIslandNation = sti(isl.smuggling_nation);
	}
	// NK <--

	switch(iMapEncounterType)
	{
		case WDM_ETYPE_MERCHANT:		// merchant ship
		// NK add non-follow warfleets. 05-06-27
			if(frnd() > ENC_NONFOLLOW_WARFLEET_CHANCE)
			{
				bReturn = GenerateMapEncounter_Merchant(iNearIslandNation, iEncounter1);
			}
			else
			{
				bReturn = GenerateMapEncounter_War(iNearIslandNation, iEncounter1, -1);
			}
			// NK <--
		break;
		case WDM_ETYPE_FOLLOW:			// war ship
			bReturn = GenerateMapEncounter_War(iNearIslandNation, iEncounter1, GetMainCharacterIndex());
		break;
		case WDM_ETYPE_WARRING:			// 2 war (or 1 war and 1 trade, or 2 trade) ships in battle
			bReturn = GenerateMapEncounter_Battle(iNearIslandNation, iEncounter1, iEncounter2);
		break;
	}

	if(!bReturn) return false;

	ref rEncounter1, rEncounter2;
	if(iEncounter1 != -1)
	{
		rEncounter1 = &MapEncounters[iEncounter1];
		rEncounter1.GroupName = ENCOUNTER_GROUP + iEncounter1;
		//Trace("rEncounter1.GroupName = " + rEncounter1.GroupName)
	}
	if(iEncounter2 != -1)
	{
		rEncounter2 = &MapEncounters[iEncounter2];
		rEncounter2.GroupName = ENCOUNTER_GROUP + iEncounter2;
		//Trace("rEncounter2.GroupName = " + rEncounter2.GroupName)
	}

	int i1 = iEncounter1;
	int i2 = iEncounter2;

	//Trace("Create encounter with slot " + iEncounter1 + ", Real = " + i1);
	//Trace("Create encounter with slot " + iEncounter2 + ", Real = " + i2);

	return true;
}

bool GenerateMapEncounter_WriteNumShips(ref rEncounter, int iEncounterType, int iMaxShipNum)
{
	aref	aWar,aMerc;
	ref		rEnc;

	makeref(rEnc,EncountersTypes[iEncounterType]);
	makearef(aWar,rEnc.War);
	makearef(aMerc,rEnc.Trade); // NK

	int iNumMerchantShips, iNumWarShips;

	iNumMerchantShips = sti(aMerc.ShipsMin) + rand(sti(aMerc.ShipsMax) - sti(aMerc.ShipsMin));
	iNumWarShips = sti(aWar.ShipsMin) + rand(sti(aWar.ShipsMax) - sti(aWar.ShipsMin));

	int iTotalShips = iNumMerchantShips + iNumWarShips;
	if(iTotalShips == 0) 
	{
		//Trace("GenerateMapEncounter_WriteNumShips: iTotalShips = 0, iEncounterType = " + iEncounterType);
		return false;
	}

//NK --> below is recapped, to MAX_SHIPS_ON_SEA
	if(iMaxShipNum != -1)
	{
		int compqty = GetCompanionQuantity(GetMainCharacter());
		while (iTotalShips > MAX_SHIPS_ON_SEA-compqty || iTotalShips > iMaxShipNum)
		{
			if(iNumWarShips) { iNumWarShips--; iTotalShips--; }
			if(iTotalShips <= MAX_SHIPS_ON_SEA-compqty && iTotalShips <= iMaxShipNum) break;

			if(iNumMerchantShips) { iNumMerchantShips--; iTotalShips--; }
		}
	}
// NK <-- 

	rEncounter.NumMerchantShips = iNumMerchantShips;
	rEncounter.NumWarShips = iNumWarShips;

	ref PChar = GetMainCharacter();
	PChar.encounter.type = iEncounterType;

	return true;
}

bool GenerateMapEncounter_Merchant(int iNearIslandNation, ref iEncounter)
{
	// find free slot in dynamic encounter table for map
	int iEncounterSlot = FindFreeMapEncounterSlot();
	if(iEncounterSlot == -1) return false;
	ManualReleaseMapEncounter(iEncounterSlot);

	ref rEncounter = &MapEncounters[iEncounterSlot];

	// NK do this below:
	// find real encounter

	// nation find
	int iNationsCanBe[MAX_NATIONS]; 
	int iNumNationsCanBe = 0;
	for (int i=0; i<NATIONS_QUANTITY; i++)
	{
		/*bool bCanBe = Encounter_CanNation(iEncounterType, i);
		if(!bCanBe) continue;*/
		if(i == iNearIslandNation && rand(2) == 1) 
		{
			iNationsCanBe[0] = i;
			iNumNationsCanBe = 1;
			break;
		}
		iNationsCanBe[iNumNationsCanBe] = i;
		iNumNationsCanBe++;
	}

	if(iNumNationsCanBe == 0) return false;

	rEncounter.Nation = iNationsCanBe[rand(iNumNationsCanBe - 1)];

	// NK use FindEncounter() 05-06-27
	int iEncounterType = FindEncounter(ENCOUNTER_TRADE, sti(rEncounter.Nation));
	if(iEncounterType == -1) return false;
	rEncounter.RealEncounterType = iEncounterType;

	GenerateMapEncounter_WriteNumShips(rEncounter, iEncounterType, 4);

	iEncounter = iEncounterSlot;
	rEncounter.bUse = true;
	rEncounter.Type = "trade";

	rEncounter.Task = AITASK_MOVE;
	// create move point coordinates here

	return true;
}

bool GenerateMapEncounter_War(int iNearIslandNation, ref iEncounter, int iCharacterIndexAsEnemy)
{
	int iEncounterType = -1;

	// find free slot in dynamic encounter table for map
	int iEncounterSlot = FindFreeMapEncounterSlot();
	if(iEncounterSlot == -1) return false;
	ManualReleaseMapEncounter(iEncounterSlot);

	ref rEncounter = &MapEncounters[iEncounterSlot];

	// try to find quest encounters
	if(iCharacterIndexAsEnemy != -1)
	{
		// try to find Quest encounter
		int iQEncounter = Encounter_FindFirstQuestMapEncounter(ENCOUNTER_WAR);
		if(iQEncounter >= 0)
		{
			ref rQEncounter = Encounter_GetQuestMapEncounter(iQEncounter);
			if(rand(99) < sti(rQEncounter.Rand))
			{
				string sGroupID = rQEncounter.ID;
				if(!sti(rQEncounter.Permanent)) { Encounter_DeleteQuestMapEncounter(sGroupID);	}
				ref rGCommander = Group_GetGroupCommander(sGroupID);
				
				rEncounter.Nation = sti(rGCommander.Nation);
				rEncounter.bUse = true;
				rEncounter.qID = sGroupID;
				rEncounter.GroupName = sGroupID;
				rEncounter.GeraldSails = true;

				iEncounter = iEncounterSlot;
				return true;
			}
		}
	}

	// try to make punitive squadron
	ref rMainCharacter = GetMainCharacter();
	int iReputation = sti(rMainCharacter.reputation);
	if(iReputation < 40 && iCharacterIndexAsEnemy != -1)	// FIX-ME
	{
		if(rand(100) < 40 * ((41 - iReputation) / 40))
		{
			iEncounterType = ENCOUNTER_TYPE_PUNITIVE_SQUADRON;
		}
	}

	// NK do this below:
	// find real encounter if not punitive

	// nation find
	int iNationsCanBe[MAX_NATIONS]; 
	int iNumNationsCanBe = 0;
	for (int i=0; i<NATIONS_QUANTITY; i++)
	{
		/*bool bCanBe = Encounter_CanNation(iEncounterType, i);
		if(!bCanBe) continue;*/
		if(iCharacterIndexAsEnemy != -1 && GetNationRelation2Character(i, iCharacterIndexAsEnemy) != RELATION_ENEMY) continue;
		if(i == iNearIslandNation && rand(2) == 1) 
		{
			iNationsCanBe[0] = i;
			iNumNationsCanBe = 1;
			break;
		}
		iNationsCanBe[iNumNationsCanBe] = i;
		iNumNationsCanBe++;
	}

	if(iNumNationsCanBe == 0) return false;

	rEncounter.Nation = iNationsCanBe[rand(iNumNationsCanBe - 1)];

	// find real encounter if not punitive - NK use FindEncounter() 05-06-27
	if(iEncounterType == -1)
	{
		iEncounterType = FindEncounter(ENCOUNTER_WAR, sti(rEncounter.Nation)); if(iEncounterType == -1) return false;
	}

	rEncounter.RealEncounterType = iEncounterType;
	GenerateMapEncounter_WriteNumShips(rEncounter, iEncounterType, 4);

	rEncounter.Task = AITASK_ATTACK;
	rEncounter.Task.Target = PLAYER_GROUP; // if iCharacterIndexAsEnemy == GetMainCharacterIndex()
	iEncounter = iEncounterSlot;

	rEncounter.Type = "war";
	if(sti(rEncounter.Nation) == PIRATE)	rEncounter.Type = "pirate"; // Viper

	rEncounter.bUse = true;

	return true;
}

bool GenerateMapEncounter_Battle(int iNearIslandNation, ref iEncounter1, ref iEncounter2)
{
	// generate first encounter
	// NK allow trade fleets here too 05-06-27
	bool tmpbool;
	if(frnd() <= WARRING_CHANCE_TRADE) tmpbool = GenerateMapEncounter_Merchant(iNearIslandNation, iEncounter1);
	else tmpbool = GenerateMapEncounter_War(iNearIslandNation, iEncounter1, -1);
	if(!tmpbool)
	{
		iEncounter1 = -1; iEncounter2 = -1;
		return false;
	}

	// generate second encounter
	if(frnd() <= WARRING_CHANCE_TRADE) tmpbool = GenerateMapEncounter_Merchant(iNearIslandNation, iEncounter2);
	else tmpbool = GenerateMapEncounter_War(iNearIslandNation, iEncounter2, -1);
	if(!tmpbool)
	{
		ManualReleaseMapEncounter(iEncounter1);
		iEncounter1 = -1; iEncounter2 = -1;
		return false;
	}
	// NK <--

	ref rEncounter1 = &MapEncounters[iEncounter1];
	ref rEncounter2 = &MapEncounters[iEncounter2];

	int iRealEncounterType1 = rEncounter1.RealEncounterType;
	int iRealEncounterType2 = rEncounter2.RealEncounterType;

	// find nations for battle between two encounters
	int iNation1 = sti(rEncounter1.Nation);
	int iNation2 = sti(rEncounter2.Nation);
	
	// if we hit the target with nations - return
	if(GetNationRelation(iNation1, iNation2) != RELATION_ENEMY)
	{
		// search enemy for iNation1
		int iNationsCanBe[MAX_NATIONS]; 
		int iNumNationsCanBe = 0;
		for (int i=0; i<NATIONS_QUANTITY; i++)
		{
			bool bCanBe = Encounter_CanNation(iRealEncounterType2, i);
			if(!bCanBe) continue;
			if(GetNationRelation(i, iNation1) != RELATION_ENEMY) continue;
			iNationsCanBe[iNumNationsCanBe] = i;
			iNumNationsCanBe++;
		}

		if(iNumNationsCanBe == 0) 
		{
			ManualReleaseMapEncounter(iEncounter1);
			ManualReleaseMapEncounter(iEncounter2);
			iEncounter1 = -1; iEncounter2 = -1;
			return false;
		}

		rEncounter2.Nation = iNationsCanBe[rand(iNumNationsCanBe - 1)];
	}

	rEncounter1.Task = AITASK_ATTACK;	rEncounter1.Task.Target = ENCOUNTER_GROUP + iEncounter2;
	rEncounter2.Task = AITASK_ATTACK;	rEncounter2.Task.Target = ENCOUNTER_GROUP + iEncounter1;

	rEncounter1.Lock = true;	rEncounter2.Lock = true;
	rEncounter1.bUse = true;	rEncounter2.bUse = true;

	return true;
}
