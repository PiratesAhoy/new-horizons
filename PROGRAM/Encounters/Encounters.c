#include "encounters\encounters.h"
#include "encounters\encounters_map.c"
#include "encounters\encounters_quest.c"

#define MAX_MAP_ENCOUNTERS		16
object MapEncounters[MAX_MAP_ENCOUNTERS];

extern void InitEncounters();

void EncountersInit()
{
	if(LoadSegment("Encounters\Encounters_init.c"))
	{
		InitEncounters();
		UnloadSegment("Encounters\Encounters_init.c");
	}

	ReleaseMapEncounters();
}

// NK new one function 05-05-11
int FindEncounter(int type, int nat)
{
	int iTypes[2]; // MUST BE MAX_ENCOUNTER_TYPES*10!
	int i;
	SetArraySize(&iTypes, ENCOUNTERS_QUANTITY*10);
	for(i = 0; i < ENCOUNTERS_QUANTITY*10; i++) iTypes[i] = -1;
	int iNumTypes = 0;

	ref rCharacter = GetMainCharacter();
	int iCharacterRank = sti(rCharacter.rank);
	bool cap = GetShipCap();
	if(cap) { if((8-GetCharacterShipClass(rCharacter)) * 2 < iCharacterRank) { iCharacterRank = (8-GetCharacterShipClass(rCharacter)) * 2; } } // NK

	//int iChance = rand(100);

	for (i=0; i<MAX_ENCOUNTER_TYPES; i++)
	{
		if(sti(EncountersTypes[i].Type) == type)
		{
			if(sti(EncountersTypes[i].Skip) || !Encounter_CanNation(i, nat)) { continue; }
			// check chance
			// check MinRank / MaxRank
			if(cap) // NK apply ship cap here 05-04-24
			{
				if(sti(EncountersTypes[i].MinRank) > iCharacterRank || sti(EncountersTypes[i].MaxRank) < iCharacterRank) { continue; }
			}
			iTypes[iNumTypes] = i;
			iNumTypes += sti(EncountersTypes[i].Chance);
		}
	}
	if(iNumTypes == 0) 
	{
		//Trace("FindWarEncounter: not find any war encounters!");
		return -1;
	}
	int findnum = rand(iNumTypes-1);
	while(findnum >=0 && iTypes[findnum] == -1) findnum--;
	return iTypes[findnum];
}

int FindWarEncounter()
{
	int iTypes[100];
	int iNumTypes = 0;

	ref rCharacter = GetMainCharacter();
	int iCharacterRank = sti(rCharacter.rank);
	if(GetShipCap()) { if((8-GetCharacterShipClass(rCharacter)) * 2 < iCharacterRank) { iCharacterRank = (8-GetCharacterShipClass(rCharacter)) * 2; } } // NK

	int iChance = rand(100);

	for (int i=0; i<ENCOUNTERS_QUANTITY; i++)
	{
		if(sti(EncountersTypes[i].Type) == ENCOUNTER_WAR)
		{
			if(sti(EncountersTypes[i].Skip)) { continue; }
			// check chance
			if(iChance > sti(EncountersTypes[i].Chance)) { continue; }
			// check MinRank / MaxRank
			if(GetShipCap())
			{ if(sti(EncountersTypes[i].MinRank) > iCharacterRank && sti(EncountersTypes[i].MaxRank) < iCharacterRank) { continue; } } // NK apply ship cap here 05-04-24
			//{
				iTypes[iNumTypes] = i;
				iNumTypes++;
			//}
		}
	}
	if(iNumTypes == 0) 
	{
		//Trace("FindWarEncounter: not find any war encounters!");
		return -1;
	}
	return iTypes[rand(iNumTypes-1)];
}

int FindMerchantEncounter()
{
	int iTypes[100];
	int iNumTypes = 0;

	ref rCharacter = GetMainCharacter();
	int iCharacterRank = sti(rCharacter.rank);
	if(GetShipCap()) { if((8-GetCharacterShipClass(rCharacter)) * 2 < iCharacterRank) { iCharacterRank = (8-GetCharacterShipClass(rCharacter)) * 2; } } // NK

	int iChance = rand(100);

	for (int i=0; i<ENCOUNTERS_QUANTITY; i++)
	{
		if(sti(EncountersTypes[i].Type) == ENCOUNTER_TRADE)
		{
			// check chance
			if(iChance > sti(EncountersTypes[i].Chance)) continue;
			// check MinRank / MaxRank
			if(GetShipCap())
			{ if(sti(EncountersTypes[i].MinRank) > iCharacterRank || sti(EncountersTypes[i].MaxRank) < iCharacterRank) { continue; } } // NK apply ship cap here 05-04-24
			//{
				iTypes[iNumTypes] = i;
				iNumTypes++;
			//}
		}
	}
	if(iNumTypes == 0) 
	{
		//Trace("FindMerchantEncounter: not find any merchant!");
		return -1;
	}
	return iTypes[rand(iNumTypes - 1)];
}

bool Encounter_CanNation(int iEncounter, int iNation)
{
	string sNation = "Nation.Exclude." + Nations[iNation].Name;
	if(!CheckAttribute(&EncountersTypes[iEncounter], sNation)) return true;
	return !sti(EncountersTypes[iEncounter].(sNation));
}

bool Encounter_GetClassesFromRank(int iEncounter, int iRank, ref rMClassMin, ref rMClassMax, ref rWClassMin, ref rWClassMax)
{
	ref rEnc = &EncountersTypes[iEncounter];
	if(!GetShipCap()) iRank = -1; // NK new shipcap rules 05-04-25
	rMClassMin = 0; rMClassMax = 0; 
	rWClassMin = 0; rWClassMax = 0;

	string sRank = "Rank." + iRank;
	if(!CheckAttribute(rEnc, sRank))
	{
		// find nearest rank 
		if(iRank == -1) iRank = 20; // NK new shipcap rules 05-04-25 - this line should never need be used because all encs should have a -1 rank!
		if(CheckAttribute(rEnc, "Rank"))
		{
			int iLastRank = -1;
			int iBestRank = 1000;

			aref aRanks; makearef(aRanks, rEnc.Rank);
			int iNumRanks = GetAttributesNum(aRanks);
			for (int i=0; i<iNumRanks; i++)
			{
				aref aRank = GetAttributeN(aRanks, i);
				string sName = GetAttributeName(aRank);
				int iCurRank = sti(sName);
				if(abs(iRank - iCurRank) < iBestRank)
				{
					iBestRank = abs(iRank - iCurRank);
					iLastRank = iCurRank;
				}
			}
			if(iLastRank == -1) { return false; }
			sRank = "Rank." + iLastRank;
		}
		else
		{
			return false;
		}
	}

	rMClassMin = rEnc.(sRank).1;
	rMClassMax = rEnc.(sRank).0;

	rWClassMin = rEnc.(sRank).3;
	rWClassMax = rEnc.(sRank).2;
	
	return true;
}
