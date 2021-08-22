#define RELATION_CHANGE_PROBABILITY 1 // PB: Percentage chance of relation change per day, accepts 0.1 increments
// PB: Many substantial rewrites made throughout this file in August 2015

// KK -->
int NATIONS_QUANTITY = 0;
int iForceDetectionFalseFlag = 0;
// KK <--

extern void InitNations();
extern void relations_init(); // KK

#event_handler(GET_RELATION_EVENT,"GetRelationEvent");

void Nations_SetAllHostile()
{
	ref PChar = GetMainCharacter();
	for (int i=0; i<NATIONS_QUANTITY; i++)
	{
		SetRMRelation(PChar, i, REL_MIN);
	}
}

void NationsInit()
{
	if(LoadSegment("nations\nations_init.c"))
	{
		InitNations();
		UnloadSegment("nations\nations_init.c");
	}
}

void SetNationRelation2MainCharacter(int iNation, int iRelationType)
{
	ref PChar = GetMainCharacter();
	SetRMRelation(PChar, iNation, RelationToRMRelation(iRelationType));
}

void SetNationRelationBoth(int iNation1, int iNation2, int iRelationType)
{
	if (iNation1 >= 0 && iNation1 < NATIONS_QUANTITY && iNation2 >= 0 && iNation2 < NATIONS_QUANTITY) { // KK
		NationsRelations[iNation1 * NATIONS_QUANTITY + iNation2] = iRelationType;
		NationsRelations[iNation2 * NATIONS_QUANTITY + iNation1] = iRelationType;
	}
}

// =================================================================================================
// Character Relation
// =================================================================================================
void SetCharacterRelationAsOtherCharacter(int iCharacterIndex1, int iCharacterIndex2)
{
	Characters[iCharacterIndex1].relation.UseOtherCharacter = iCharacterIndex2;
}

void SetCharacterRelationBoth(int iCharacterIndex1, int iCharacterIndex2, int iRelationType)
{
	if (iCharacterIndex1 < 0 || iCharacterIndex2 < 0) return;
	SetCharacterRelation(iCharacterIndex1, iCharacterIndex2, iRelationType);
	SetCharacterRelation(iCharacterIndex2, iCharacterIndex1, iRelationType);
}

void SetCharacterRelation(int iCharacterIndex1, int iCharacterIndex2, int iRelationType)
{
	if (iCharacterIndex1 < 0) return; // KK, LDH 14Oct06 removed test for iCharacterIndex2<0
	string sTemp1 = "" + iCharacterIndex2;
	Characters[iCharacterIndex1].relation.(sTemp1) = iRelationType;
/*
	ref chr1 = &characters[iCharacterIndex1];
	ref chr2 = &characters[iCharacterIndex2];
	Trace("Set relation between " + GetMyShipNameShow(chr1) + " and " + GetMyShipNameShow(chr2) + " to " + iRelationType);
*/
}

// =================================================================================================
// Get Relation Methods
// =================================================================================================
int GetNationRelation(int iNation1, int iNation2)
{
	if (iNation1 < PERSONAL_NATION || iNation1 >= NATIONS_QUANTITY) return RELATION_NEUTRAL;
	if (iNation2 < PERSONAL_NATION || iNation2 >= NATIONS_QUANTITY) return RELATION_NEUTRAL;

	if (iNation1 == PERSONAL_NATION) return GetNationRelation2MainCharacter(iNation2); // PB
	if (iNation2 == PERSONAL_NATION) return GetNationRelation2MainCharacter(iNation1); // PB

	return NationsRelations[iNation1 * NATIONS_QUANTITY + iNation2];
}

int GetNationRelation2MainCharacter(int iNation)
{
	if (!IsEntity(&worldMap) || GetCurrentFlag() == PERSONAL_NATION) // PB: GetFlagRMRelation for PERSONAL_NATION ends up calling this function again, creating an endless loop!
	{
		return GetRMRelationType(GetRMRelation(GetMainCharacter(), iNation));
	}
	else
	{
		return GetFlagRMRelation(iNation); // PB: Worldmap calls this function from engine!
	}
}

int GetNationRelation2Character(int iNation, int iCharacterIndex)
{
	ref rCharacter = GetCharacter(iCharacterIndex);
	if (CheckAttribute(rCharacter, "relation.UseOtherCharacter"))
	{
		if (sti(rCharacter.relation.UseOtherCharacter) >= 0)
		{
			rCharacter = GetCharacter(sti(rCharacter.relation.UseOtherCharacter));
		}
	}

	if (IsMainCharacter(rCharacter))	return GetNationRelation2MainCharacter(iNation); // PB
	return GetNationRelation(iNation, sti(rCharacter.nation));
}

int GetRelation(int iCharacterIndex1, int iCharacterIndex2)
{
	bool ismc1, ismc2;
	int iNation1, iNation2;
	string stmp;
	int iMCI = GetMainCharacterIndex();

	ref rCharacter1 = GetCharacter(iCharacterIndex1);
	ref rCharacter2 = GetCharacter(iCharacterIndex2);

	if (CheckAttribute(&rCharacter1, "relation.UseOtherCharacter"))
	{
		if (sti(rCharacter1.relation.UseOtherCharacter) >= 0)
		{
			rCharacter1 = GetCharacter(sti(rCharacter1.relation.UseOtherCharacter));
		}
	}
	if (CheckAttribute(&rCharacter2, "relation.UseOtherCharacter"))
	{
		if (sti(rCharacter2.relation.UseOtherCharacter) >= 0)
		{
			rCharacter2 = GetCharacter(sti(rCharacter2.relation.UseOtherCharacter));
		}
	}

	if (sti(rCharacter1.index) == sti(rCharacter2.index)) return RELATION_FRIEND;

	// character 2 character relation
	{
		string sTemp = "relation." + rCharacter2.index;
		if (CheckAttribute(&rCharacter1,sTemp))
		{
			return sti(rCharacter1.(sTemp));
		}
	}
	//Trace("iNation1 = " + iNation1 + ", iNation2 = " + iNation2);

	iNation1 = sti(rCharacter1.nation);
	iNation2 = sti(rCharacter2.nation);

	if (iNation1 <  PERSONAL_NATION  || iNation2 <  PERSONAL_NATION ) return RELATION_NEUTRAL; // LDH fix for iNation < 0
	if (iNation1 >= NATIONS_QUANTITY || iNation2 >= NATIONS_QUANTITY) return RELATION_NEUTRAL; // KK
	// 04-12-06 new section
	ismc1 = IsInParty(iMCI, sti(rCharacter1.index));
	ismc2 = IsInParty(iMCI, sti(rCharacter2.index));
	if(ismc1 && ismc2) return RELATION_FRIEND;

	if (iNation1 == NEUTRAL_NATION || iNation2 == NEUTRAL_NATION) return RELATION_NEUTRAL; // KK

	if (iNation1 == PERSONAL_NATION && iNation2 == PERSONAL_NATION) return RELATION_NEUTRAL; // PB
	if (iNation1 == PERSONAL_NATION && iNation2 >= 0 && iNation2 < NATIONS_QUANTITY) return GetNationRelation2MainCharacter(iNation2); // PB
	if (iNation2 == PERSONAL_NATION && iNation1 >= 0 && iNation1 < NATIONS_QUANTITY) return GetNationRelation2MainCharacter(iNation1); // PB

	if(iNation1 >= NATIONS_QUANTITY)
	{
		if(ismc1) //this should never be false...
		{
			iNation1 = RMGetHighestRelation(GetMainCharacter());
		}
		else return RELATION_NEUTRAL; // this case should never occur, since only pchar can set to >=maxnat.
	}
	if(iNation2 >= NATIONS_QUANTITY && iNation2 != PERSONAL_NATION) // KK
	{
		if(ismc2) //this should never be false...
		{
			iNation2 = RMGetHighestRelation(GetMainCharacter());
		}
		else return RELATION_NEUTRAL; // this case should never occur, since only pchar can set to >=maxnat.
	}

	// nation 2 character relation
	if(ismc1) //if (iMCI == sti(rCharacter1.index))
	{
		//Trace("iMainCharacterRelation = " + GetNationRelation2MainCharacter(iNation2));
		if (iNation2 == PERSONAL_NATION) return RELATION_FRIEND; // KK
		return GetNationRelation2MainCharacter(iNation2); // PB
	}
	if(ismc2) //if (iMCI == sti(rCharacter2.index))
	{
		//Trace("iMainCharacterRelation = " + GetNationRelation2MainCharacter(iNation1));
		if (iNation1 == PERSONAL_NATION) return RELATION_FRIEND; // KK
		return GetNationRelation2MainCharacter(iNation1); // PB
	}

	// nation 2 nation relation
	return NationsRelations[iNation1 * NATIONS_QUANTITY + iNation2];
}

int GetRelationEvent()
{
	int iCharacterIndex1 = GetEventData();
	int iCharacterIndex2 = GetEventData();
	return GetRelation(iCharacterIndex1, iCharacterIndex2);
}

int FindEnemyNation2Nation(int iNation)
{
	return FindNationWithRelation(iNation, RELATION_ENEMY, true);
}

// NK add friendly/neutral case here too 04-09-09
int FindFriendlyNation2Nation(int iNation)
{
	return FindNationWithRelation(iNation, RELATION_ENEMY, false);
}
// NK <--

int FindNationWithRelation(int iNation, int relation, bool YesNo)
{
	int iNations[MAX_NATIONS];
	int iNumNations = 0;
	bool CheckVal;

	for (int i=0;i<NATIONS_QUANTITY;i++)
	{
		if (YesNo)	CheckVal = GetNationRelation(i,iNation) == relation;
		else		CheckVal = GetNationRelation(i,iNation) != relation;
		if (CheckVal)
		{
			iNations[iNumNations] = i;
			iNumNations++;
		}
	}
	if (iNumNations == 0) return PIRATE;		// LDH fix
	return iNations[rand(iNumNations - 1)];
}

int FindEnemyNation2Character(int iCharacterIndex)
{
	int iNation;
	ref ch = GetCharacter(iCharacterIndex);

	if (IsMainCharacter(ch))	iNation = GetServedNation();
	else						iNation = ch.nation;

	return FindEnemyNation2Nation(iNation);
}

// KK -->
int GetNationTypeByID(string nationName)
{
	for(int i=0; i<NATIONS_QUANTITY; i++)
	{
		if (Nations[i].id == nationName) return i;
	}
	return UNKNOWN_NATION;
}

string GetNationIDByType(int iNationType)
{
	string retText = InvalidNation(iNationType);
	if (retText != "")	return retText;
	
	ref rNation = GetNationByType(iNationType);
	return rNation.id;
}

string InvalidNation(int iNationType)
{
	string nationText = "";
	if (iNationType == NEUTRAL_NATION)							return "neutral";	// KAM
	if (iNationType == PERSONAL_NATION)							return "personal";	// KK
	if (iNationType == PRIVATEER_NATION)							return "privateer";	// GR
	if (iNationType < -1 || iNationType >= NATIONS_QUANTITY)	return "unknown";	// NK
	return nationText;
}
// <-- KK

string GetNationNameByType(int iNationType)
{
	string retText = InvalidNation(iNationType);
	if (retText != "")	return retText;
	
	ref rNation = GetNationByType(iNationType);
	return rNation.Name;
}

// KK -->
string GetNationOfficialNameByType(int iNationType)
{
	string retText = InvalidNation(iNationType);
	if (retText != "")	return retText;
	
	string stmp = GetNationIDByType(iNationType);
	ref rPeriod; makeref(rPeriod, Periods[GetCurrentPeriod()]);
	if (CheckAttribute(rPeriod, "Nations.OfficialName." + stmp)) return rPeriod.Nations.OfficialName.(stmp);
	return GetNationNameByType(iNationType);
}
// <-- KK

ref GetNationByType(int iNationType)
{
	if (iNationType < 0 || iNationType >= NATIONS_QUANTITY) iNationType = PIRATE;		// LDH fix
	return &Nations[iNationType];
}

// RM Put these in Nations.c -->

//NEW PROPERTY: nation[n].Desc = adjective, i.e. French
//this returns it.
string GetNationDescByType(int iNationType)
{
	string retText = InvalidNation(iNationType);
	if (retText != "")	return retText;
	
	ref rNation = GetNationByType(iNationType);
	return rNation.Desc;
}

// KK -->
//NEW PROPERTY: Periods[n].Royal.(nation) = title, i.e. 'His Most Christian Majesty Charlie the _great'
//this returns it.
// MAXIMUS 14.08.2019: changes for translation were added
string GetNationRoyalByType(int iNationType)
{
	string sNation, sRet;
	ref rPeriod; makeref(rPeriod, Periods[GetCurrentPeriod()]);
	sRet = "";

	int tmpRoyalFileID = -1; // MAXIMUS 14.08.2019: changes for translation
	if(FindFile("RESOURCE\INI\TEXTS\"+LanguageGetLanguage(), "*.txt", "periods_strings.txt") != "") tmpRoyalFileID = LanguageOpenFile("periods_strings.txt"); // MAXIMUS 14.08.2019: changes for translation

	if (iNationType >= 0 && iNationType < NATIONS_QUANTITY)	// LDH fix for iNationType < 0
	{
		sNation = GetNationIDByType(iNationType);
		if (CheckAttribute(rPeriod, "Royal." + sNation + ".Title"))
		{
			sRet = rPeriod.Royal.(sNation).Title;
		}
		if (CheckAttribute(rPeriod, "Royal." + sNation + ".Name"))
		{
			if(sRet == "")	
			{
				sRet  =       rPeriod.Royal.(sNation).Name;
				if(tmpRoyalFileID!=-1) sRet = LanguageConvertString(tmpRoyalFileID, sRet); // MAXIMUS 14.08.2019: changes for translation
			}
			else
			{
				if(tmpRoyalFileID!=-1) sRet += " " + LanguageConvertString(tmpRoyalFileID, rPeriod.Royal.(sNation).Name); // MAXIMUS 14.08.2019: changes for translation
				else sRet += " " + rPeriod.Royal.(sNation).Name;
			}
		}
		if(sRet == "") sRet = XI_ConvertString("unknown");
	}
	return sRet;
}
// <-- KK

string GetTownByNation(int iNation)
{
	int random;
	int i, j;
	string sTowns[100];
	string iTowns[100];

	j=0;
	for (i = 0; i < TOWNS_QUANTITY; i++)
	{
		string townid = Towns[i].id;
		if (GetTownNation(townid) == iNation)
		{
			sTowns[j] = Towns[i].name;
			iTowns[j] = Towns[i].id
			j++;
		}
	}
	if(j>0)
	{
		random = rand(j-1);
		return sTowns[random];
	}
	else
	{
		return "";
	}
}

//START RM CODE
//gets RMRelation between char and iNation
float GetRMRelation(ref char, int iNation)
{
	if (iNation == PERSONAL_NATION) return REL_NEUTRAL;
	string sNation = "" + iNation;
	float rel = REL_AMNESTY; // default to amnesty
	//if(sti(char.nation) == iNation) rel = REL_NEUTRAL;
	if(CheckAttribute(char, "nations."+sNation+".Relation"))
	{ rel = stf(char.nations.(sNation).Relation); }
	return rel;
}

//gets stock relation type based on RMRelation
int GetRMRelationType(float rel)
{
	if(rel <= REL_WAR) return RELATION_ENEMY;
	if(rel < REL_NEUTRAL) return RELATION_NEUTRAL;
	return RELATION_FRIEND;
}

//return name of relation, enemy->neutral->LoM->rank.
string GetRMRelationName(ref char, int iNation)
{
	float rel = GetRMRelation(char, iNation);
	// PB: Rewritten to prevent Letter of Marque text unless you actually have one -->
	if(rel <= REL_WAR)				return "Hostile";
	if(rel <= REL_AFTERATTACK)		return "Wary";
	if(GetRank(char, iNation))		return GetRankName(char, iNation);
	if(HaveLetterOfMarque(iNation))
	{
		if (iNation == PIRATE)		return "Member of Brotherhood";
		else						return "Letter of Marque";
	}
	if(rel < REL_NEUTRAL)			return "Neutral";
	if(rel >= REL_NEUTRAL)			return "Friendly";
	// PB: Rewritten to prevent Letter of Marque text unless you actually have one <--
}

//sets RMRelation between char and iNation to rel, sets
//stockrelation based on that, and logs if LogsToggle on. Requires NK - Toggles.
float SetRMRelation(ref char, int iNation, float rel)
{
	string sNation = "" + iNation;
	if (rel < REL_MIN) rel = REL_MIN;
	rel = makefloat(rel); // PB: To ensure the correct data type
	char.nations.(sNation).Relation = rel;

	//log new relation
	if (iRealismMode == 0 && LogsToggle == LOG_VERBOSE) Log_SetStringToLog(XI_ConvertString(GetNationNameByType(iNation))+ " - " + XI_ConvertString(GetRMRelationName(char, iNation)) +"."); // PB: Fixes a dispay error // KK
	return rel;
}

//changes RMRelation between char and iNation, calling setRMR.
float ChangeRMRelation(ref char, int iNation, float relch)
{
	float relorg = GetRMRelation(char, iNation);
	float newrel = relorg + relch;
	if (relch >= 0.0)																// GAINING points
	{
		if (!IsInServiceOf(iNation))												// If not in the service
		{
			if (newrel >= REL_NEUTRAL)	newrel = REL_NEUTRAL;						// Prevent becoming MORE than Friendly
			if (newrel < relorg)		newrel = relorg;							// But don't ever LOSE points while you're meant to be gaining them!
		}
	}
	else																			// Losing points
	{
		if (IsMainCharacter(char)   && newrel <  REL_NEUTRAL)						// If dropping below Friendly
			LooseLetterOfMarque(iNation);											// Lose any Letter of Marque
	}
	SetRMRelation(char, iNation, newrel);

	//log new relation
	if (iRealismMode == 0 && LogsToggle == LOG_VERBOSE) Log_SetStringToLog(XI_ConvertString(GetNationNameByType(iNation))+ " - " + TranslateString("",GetRMRelationName(char, iNation)) + "."); // KK
	return newrel;
}

// 04-12-06 added
int RMGetHighestRelation(ref char)
{
	int bestnat = PIRATE;
	float tpoints = REL_MIN;
	for(int i = 0; i < NATIONS_QUANTITY; i++)
	{
		if(GetRMRelation(&char, i) > tpoints)
		{
			tpoints = GetRMRelation(&char, i);
			bestnat = i;
		}
	}
	if(tpoints < REL_AMNESTY) bestnat = PIRATE;
	return bestnat;
}

//gets cost for amnesty
int RMAmnestyCost(ref ch, int iNation)
{
	int CostValue;
	CostValue = makeint(sqrt(stf(ch.rank)) * makefloat(GetRMRelation(ch, iNation)) / stf(ch.reputation) * 15000.0 / 100.0) * 100;
	if (sti(GetAttribute(ch, "executions")) > 0) CostValue = CostValue - 1000 * sti(GetAttribute(ch, "executions"));
	return CostValue;
}

//sets amnesty with iNation
void RMAmnesty(ref ch, int iNation)
{
	SetRMRelation(ch, iNation, REL_AMNESTY);
	ResetForts(iNation); // PB: Use separate function
	ch.executions = 0;
	//SetRMKills(ch, iNation, 0);
}

// KK -->
void ResetForts(int iNation)
{
	ref ch;
	for (int i = 0; i < TOWNS_QUANTITY; i++) {
		string townid = Towns[i].id;
		if (GetTownNation(townid) == iNation) {
			int fortq = GetTownNumForts(townid) - 1;
			while (fortq >= 0) {
				ch = GetTownFortCommander(townid, fortq);
				ResetCharacterMemory(ch); // PB: was SetCharacterRelationBoth(GetTownFortCommanderIndex(townid, fortq), GetMainCharacterIndex(), RELATION_FRIEND);
				fortq--;
			}
		}
	}
	LAi_group_SetRelation(GetSoldiersGroup(iNation), LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL); // maybe LAI_GROUP_FRIEND?
	LAi_group_SetRelation(GetCitizensGroup(iNation), LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL); // maybe LAI_GROUP_FRIEND?
}

void ResetAllForts()
{
	for (int i=0; i<NATIONS_QUANTITY; i++)
	{
		ResetForts(i);
	}
}

void ResetCharacterMemory(ref chr)
{
	DeleteAttribute(chr,"recognized");
	DeleteAttribute(chr,"betrayed");
	DeleteAttribute(chr,"PlayerNation");
	DeleteAttribute(chr,"PlayerShip");
	DeleteAttribute(chr,"relation_to_pirates");
}

bool IsRecognizedByForts(int iNation)
{
	ref ch;
	for (int i = 0; i < TOWNS_QUANTITY; i++) {
		string townid = Towns[i].id;
		if (GetTownNation(townid) == iNation) {
			int fortq = GetTownNumForts(townid) - 1;
			while (fortq >= 0) {
				ch = GetTownFortCommander(townid, fortq);
				if (IsRecognizedByFort(ch)) return true;
				fortq--;
			}
		}
	}
	return false;
}

bool IsRecognizedByFort(ref chr)
{
	if (CheckAttribute(chr, "recognized"))	return true;
	if (CheckAttribute(chr, "betrayed"))	return true;
	if (CheckAttribute(chr, "PlayerNation") && GetNationRelation(sti(chr.PlayerNation), sti(chr.nation)) == RELATION_ENEMY)	return true;
	return false;
}
// <-- KK

//gets RMRelation between char and gov.
float GetGovRelation(ref char, ref gov)
{
	float rel = 0.0;
	string id = gov.id;
	if(CheckAttribute(char,"GovRelations."+id))
	{ rel = stf(char.GovRelations.(id)); }
	return rel;
}


//sets RMRelation bgetween char and gov to rel.
float SetGovRelation(ref char, ref gov, float rel)
{
	string id = gov.id;
	if(rel < REL_MIN) rel = REL_MIN;
	char.GovRelations.(id) = rel;
	return rel;
}


//changes RMRelation between char and gov by relch.
float ChangeGovRelation(ref char, ref gov, float relch)
{
	string id = gov.id;
	relch += GetGovRelation(char, gov);
	if(relch < REL_MIN) relch = REL_MIN;
	char.GovRelations.(id) = relch;
	return relch;
}


//gets sum RMRelation between char, and gov /and gov's nation/,
//used to find if forts fire.
float GetRMRelationWithGov(ref char, ref gov)
{
	return GetRMRelation(char, sti(gov.nation)) + GetGovRelation(char, gov);
}


//find if fort should be hostile, based on char, and fortchar's governor.
// KK Never used anyway
int GovHostileCheck(ref char, ref fortchar)
{
	// KK -->
	if (CheckAttribute(fortchar, "town")) {
		int govidx = GetTownGovernorIndex(fortchar.town);
		if (govidx > -1) return GetRMRelationType(GetRMRelationWithGov(char, GetCharacter(govidx)));
		//	if(CheckAttribute(fortchar,"gov")) { return GetRMRelationType(GetRMRelationWithGov(char, CharacterFromID(fortchar.gov))); }
	}
	// <-- KK
	return GetRMRelationType(GetRMRelation(char, sti(fortchar.nation)));
}


/*NEW PROPERTY: in object Islands, for each Islands[n], where n is an inhabited island,
add property towns
add property towns.quantity = num towns on island
add property towns.i (where i is the number of the town) = town id.*/

// PB: Completely Rewritten -->

//run this whenever friendly or neutral thing of iNation is /attacked/ by char.
float AttackRMRelation(ref char, int iNation)
{
	bool bad = false;
	float rel = GetRMRelation(char, iNation);
	if(rel > REL_NEUTRAL)																		// Relation is Friendly or better
	{
		bad = true;																				// Leave service on BAD terms
		ChangeCharacterReputation(char, REPCH_FRIENDLY);										// Lose 30(!) reputation points
		SetRMRelation(char, iNation, REL_AFTERATTACK);											// You immediately become WARY with this nation
	}
	else
	{
		if(rel > REL_AFTERATTACK)																// Relation is above Wary
		{
			ChangeCharacterReputation(char, REPCH_NEUTRAL);										// Lose another 1 reputation point
			SetRMRelation(char, iNation, REL_AFTERATTACK);										// You immediately become WARY with this nation
		}
		else
		{
			if(GetRMRelation(char, iNation) > REL_WAR) SetRMRelation(char, iNation, REL_WAR);	// You immediate become HOSTILE with this nation!
		}
	}
	LeaveService(char, iNation, bad);															// Leave service with this nation
	return GetRMRelation(char, iNation); // NK 04-09-20 func must return something, it's a float. Oops!
}

// Explanation: this to be executed on the ENEMY CAPTAIN to check in advance if this is a legal attack (should be in line with UpdateRMRelation)
bool IsPrizeShip(ref char)
{
	int curFlag       = GetCurrentFlag();
	int iNation       = GetAttribute(char, "nation");
	if (iNation < 0 || iNation >= NATIONS_QUANTITY) 	return false;									// Just in case

	if (GetCurrentFlag() == PIRATE)						return false;									// Any act under a pirate flag is an act of piracy
	if (CheckAttribute(char, "betrayed"))				return false;									// You deliberately betrayed them
	if (GetFlagRMRelation(iNation) != RELATION_ENEMY)	return false;									// You were flying a friendly flag

	// Loop through nations to determine if this was an act of piracy
	for(int i = 0; i < NATIONS_QUANTITY; i++)
	{
		if (i == PIRATE) continue;																		// The pirates don't count
		if (GetNationRelation(i, iNation) == RELATION_ENEMY && IsInServiceOf(i)) return true;			// You are in the service of a nation hostile to the one you attacked
	}
	return false;																						// No legal reason for the attack, so not a legal prize
}

// Explanation: this changes relations based on an event (sink/take ship, sack/take town, etc.)
bool UpdateRMRelation(ref char, int iNation, float fPoints)
{
	if (iNation < 0 || iNation >= NATIONS_QUANTITY) return false;

	int i;
	string sLogTitle, sLogEntry;
	int iActOfPiracy  = iNation != PIRATE;																	// 0 if attacking the pirates, 1 if attacking any other ship
	int ServedNation  = GetServedNation();																	// This may change DURING the below process, but we don't care about that
	int curFlag       = GetCurrentFlag();
	float rel         = 0.0
	float relChange   = 0.0;

	bool bValidAttack = GetFlagRMRelation(iNation) == RELATION_ENEMY && !CheckAttribute(char, "traitor");	// You were flying a hostile flag and did not deliberately betray them
	bValidAttack      = bValidAttack || iActOfPiracy == 0;													// Never an invalid attack if you hit the pirates (even under a pirate flag)
	DeleteAttribute(char, "traitor");																		// This was temporarily added to the player
	if (bValidAttack)
	{
		// Loop through nations to determine if this was an act of piracy
		for(i = 0; i < NATIONS_QUANTITY; i++)
		{
			if (i == PIRATE) continue;																		// You gain points with the pirates through iActOfPiracy
			if (GetNationRelation(i, iNation) == RELATION_ENEMY && IsInServiceOf(i))						// You are in the service of a nation hostile to the one you attacked
			{
				relChange = fPoints;
				if (GetLetterOfMarqueQuantity() > 1)	relChange = relChange * (1 - GetLetterOfMarqueQuantity()/10); // GR: Reduce points for multiple LoMs
			//	TraceAndLog("Add " + relChange + " points: You are in the service of " + GetNationNameByType(i) + ", which is at war with " + GetNationNameByType(iNation));
				ChangeRMRelation(char, i, relChange);
				if (curFlag != PIRATE)	iActOfPiracy = 0;													// Any act under a pirate flag IS an act of piracy
			}
		}

		// This happens if you aren't in any service OR you did this attack under a pirate flag, but not if it was the pirates you attacked
		if (iActOfPiracy > 0)	iActOfPiracy = fPoints;														// For an act of piracy, add full points with the pirates

		// Loop through nations to determine how the attacked nation and its allies should respond to this
		for(i = 0; i < NATIONS_QUANTITY; i++)
		{
			if(GetNationRelation(i, iNation) == RELATION_FRIEND)											// This is the nation you attacked OR an ally
			{
				rel = GetRMRelation(char, i);																// Relation between the checked nation and the player
				if (i == iNation)																			// This is the nation you attacked
				{
					relChange = rel  -  REL_WAR + 1;														// You may immediately become HOSTILE with this nation!
					if (makeint(rel) <= REL_WAR)								relChange = fPoints;		// They are already hostile, so just subtract the number
					else																					// You were friendly with them before, bastard!	
					{
						if (i == PIRATE)										relChange = fPoints;		// The pirates aren't too concerned with you attacking other pirates
						else {if (iActOfPiracy > 0)								iActOfPiracy += relChange;}	// You had no legal reason for this attack, TRAITOR!
					}
				}
				else																						// This is an ally
				{
					relChange = rel  -  REL_AFTERATTACK + 1;												// You may immediately become Wary with this nation
					if (makeint(rel) <= REL_AFTERATTACK)						relChange = fPoints;		// They are already Wary, so just subtract the number
					else																					// Else, add an explanatory text message
					{
						sLogTitle = GetNationNameByType(i) + " turned Wary of me";
						sLogEntry = "The " + GetNationDescByType(i) + " government turned wary of me because of my attack on their " + GetNationDescByType(iNation) + " allies.";
						WriteNewLogEntry(sLogTitle,sLogEntry, "Personal", true);
					}
					if (ServedNation != PERSONAL_NATION && iActOfPiracy == 0)								// Only if you are serving ONE specific nation and committed no act of piracy
					{
						rel = GetNationRelation(i, ServedNation);											// Relation between the ally and your own served nation
					//	TraceAndLog("Served Nation = " + GetNationNameByType(ServedNation) + ", relation with " + GetNationNameByType(i) + " = " + rel);
						if(rel == RELATION_NEUTRAL || rel == RELATION_FRIEND)	relChange = 0.0;			// You have a legal reason, so the ally doesn't mind
					}
				}

				if (relChange > 0.0)																		// There are points to subtract
				{
					if (relChange < fPoints)									relChange = fPoints;		// Relation change is too small
				//	TraceAndLog("Remove " + relChange + " points: " + GetNationNameByType(i) + " and " + GetNationNameByType(iNation) + " are allied");
					ChangeRMRelation(char, i, -relChange);
				}
			}
		}
	}
	else																									// Attacking a ship while under a friendly flag is NOT accepted!
	{
		// Loop through nations to give you the appropriate penalty
		for(i = 0; i < NATIONS_QUANTITY; i++)
		{
			if (i == PIRATE) continue;																		// The pirates don't mind your gross act of piracy
			rel = GetRMRelation(char, i);																	// Relation between the checked nation and the player
			LeaveService(char, i, false);																	// Lose navy commission and all your LoMs
			if (GetNationRelation(i, iNation) == RELATION_FRIEND)											// This is the nation you attacked OR an ally
			{
				if (i == iNation)																			// This is the nation you attacked
				{
					SetRMRelation(char, i, REL_MIN);														// The nation you attacked REALLY doesn't approve!
				}
				else																						// This is an ally
				{
					if (rel > REL_WAR) SetRMRelation(char, i, REL_WAR);										// These turn hostile too, if they weren't already
				}
			}
			else
			{
				if (rel > REL_AFTERATTACK) SetRMRelation(char, i, REL_AFTERATTACK);							// All other nations turn Wary because you are untrustworthy
			}
			relChange = rel - GetRMRelation(char, i);														// Determine how many points you lost through this action
			iActOfPiracy += relChange;																		// Add all those together and give them to the pirates
		}
	}

	// You committed an act of piracy
	bool bPirated     = false;
	if (iActOfPiracy > 0)
	{
		bPirated = true;																					// Mark captured ship as being pirated
		if (IsInServiceOf(PIRATE))	iActOfPiracy = fPoints;													// No bonus points if you are already in the Brotherhood
		rel = ChangeRMRelation(char, PIRATE, iActOfPiracy);													// Add points to pirates

		// If you just became Wary to the pirates through an act of piracy, you are now marked as a TRAITOR
		if (GetServedNation() != PIRATE && makeint(rel) >= REL_AFTERATTACK)
		{
			sLogTitle = "Marked as a Pirate";
			sLogEntry = "The civilized nations of the world consider me a pirate in consequence of my actions. I had better tread carefully around them if I want to avoid getting my head in a noose. It may be possible to rectify this by declaring my loyalties as a Privateer. On the other hand, joining the Brethren of the Coast could be much more profitable.";
			WriteNewLogEntry(sLogTitle,sLogEntry, "Personal", true);
			SetServedNation(PIRATE);
		}

		if (GetServedNation() == PIRATE)
		{
			if(!CheckAttribute(char,"quest.pirate_tutorial")) CompleteQuestName("piratebook"); // GR: Pirate Tutorial
		}
		else
		{
			if(CheckAttribute(char,"quest.relation_tutorial")) // PB: Now you should know what you're doing!
			{
				// No longer an honourable merchant
				if (CheckCharacterItem(char, "Trade_Passport"))	TakeItemFromCharacter(char, "Trade_Passport");
				if (CheckCharacterItem(char, "EITC_Passport"))	TakeItemFromCharacter(char, "EITC_Passport");
			}
			else
			{
				CompleteQuestName("relationbook");	// PB: Relations Tutorial, was: Lai_QuestDelay("relationbook", 0.0);
			}
		}

	}

	//return if this was a valid attack or an act of piracy
	return bPirated;
}
// PB: Completely Rewritten <--

int GetLoMCost(int iNation)
{
	ref PChar = GetMainCharacter();
	int CostValue = (5.0 - GetRMRelation(PChar, iNation))*LOM_COST;
	if (CostValue < LOM_COST) CostValue = LOM_COST; // PB: Just in case
	if (sti(GetAttribute(PChar, "executions")) > 0) CostValue = CostValue + 1000 * sti(GetAttribute(PChar, "executions"));
	return CostValue;
}

// soldiers killed section
// used to see if soldiers actually should be hostile or not.
int GetRMKills(ref chr, int nat)
{
	int num = -1;
	string snat = nat;
	if(CheckAttribute(chr,"nation."+snat+".kills")) { num = sti(chr.nations.(snat).kills); }
	//else { chr.nations.(snat).kills = 0; }
	return num;
}

int SetRMKills(ref chr, int nat, int kills)
{
	int old = GetRMKills(&chr, nat);
	string snat = nat;
	chr.nations.(snat).kills = kills;
	DebugLog((kills) + " " + GetNationDescByType(nat) + " " + XI_ConvertString("soldiers killed") + ".");
	return old;
}

int ChangeRMKills(ref chr, int nat, int kills)
{
	string snat = nat;
	int old = GetRMKills(&chr, nat);
	if(old == -1) old = 0;
	old += kills;
	chr.nations.(snat).kills = kills;
	return kills;
}

string GetRMKillRelation(ref chr, int nat)
{
	if(GetRMKills(&chr, nat) >= RM_GROUP_MINKILLS) return LAI_GROUP_ENEMY;
	return LAI_GROUP_NEUTRAL;
}

void SetAllSoldierGroups(ref chr)
{
	string groupname;
	for(int i = 0; i < NATIONS_QUANTITY; i++)
	{
		groupname = GetSoldiersGroup(i);
		LAi_group_SetRelation(groupname, LAI_GROUP_PLAYER, GetRMKillRelation(&chr, i));
		DebugLog("setting " + groupname + " to " + GetRMKillRelation(&chr, i));
	}
}

// KK -->
int isSoldier(ref ch)
{
	if (!TestRef(ch)) return -1;
	if (CheckAttribute(ch, "isSoldier") && sti(ch.isSoldier) == true) {
		if (IsOfficer(ch) || IsCompanion(ch) || IsPassenger(ch)) // PB: No Soldier Behaviour for Player Party
		{
			DeleteAttribute(ch, "isSoldier");
		}
		else
		{
			if (CheckAttribute(ch, "nation"))	return sti(ch.nation);
			if (CheckAttribute(ch, "location"))	return GetLocationNationFromID(ch.location);
			return GetCurrentLocationNation();
		}
	}
	return UNKNOWN_NATION;
}
// <-- KK

bool AddOneSoldier(string group)
{
	if(group == "error" || group == "") return false;
	int nat = isSoldier(group);
	if(nat == UNKNOWN_NATION) return false;
	ChangeRMKills(GetMainCharacter(), nat, 1);
}
// RM <--

// PB: Make Start New Game Nation Selection work -->
void SetRelationsAsNation(int iNation)
{
	int i;
	ref PChar = GetMainCharacter();
	if(iNation == PERSONAL_NATION)
	{
		for (i = 0; i < NATIONS_QUANTITY; i++)
		{
			if(i == PIRATE	)	SetRMRelation(PChar, i, (REL_WAR + REL_MIN)/2);
			else				SetRMRelation(PChar, i,  REL_AFTERATTACK);
		}
	}
	else
	{
		for (i = 0; i < NATIONS_QUANTITY; i++)
		{
			if (i == PIRATE && iNation != PIRATE)	SetRMRelation(PChar, i, (REL_WAR + REL_MIN)/2);	
			else									SetRMRelation(PChar, i, RelationToRMRelation(GetNationRelation(iNation, i)) );
		}
	}
	SetServedNation(iNation);
	HoistFlag(iNation);
}
// PB: Make Start New Game Nation Selection work <--

void SetServedNation(int iNation)
{
	ref PChar = GetMainCharacter();
	int NumLoMs = 0;													// Count number of LoMs
	bool BecomePirate = iNation == PIRATE;								// Enforce becoming a pirate upon joining them
	for (int i=0; i<NATIONS_QUANTITY; i++)								// Check all nations
	{
		if (IsInServiceOf(i))											// If you have a LoM and/or a navy commission
		{
			NumLoMs = NumLoMs + 1;										// Add one to the counter
			iNation = i;												// Set served nation to THIS instead
			if (i == PIRATE)	BecomePirate = true;					// If you once joined the pirates, you remain a pirate even if you have another LoM
		}
	}
	if (BecomePirate)			iNation = PIRATE;						// Make sure you remain a pirate if appropriate
	else
	{
		if (NumLoMs > 1)		iNation = PERSONAL_NATION;				// If you have multiple LoMs, you don't serve any specific nation
	}
	PChar.ServedNation = iNation;										// Make sure this sticks
}

int GetServedNation()
{
	ref PChar = GetMainCharacter();
	if(!CheckAttribute(PChar, "ServedNation"))
		PChar.ServedNation = PERSONAL_NATION;							// Don't serve anyone until you get a LoM (prevents missed attribute error)
	return sti(PChar.ServedNation);										// Make sure this sticks
}

// KK -->
int GetFlagRMRelation(int iNation)
{
	return GetNationRelation(GetCurrentFlag(), iNation);
}

float RelationToRMRelation(int rel)
{
	switch (rel)
	{
		case RELATION_ENEMY:
			return REL_WAR;
		break;
		case RELATION_NEUTRAL:
			return REL_AMNESTY;
		break;
		case RELATION_FRIEND:
			return REL_NEUTRAL; // PB: was -1
		break;
	}
}

void ReceiveLetterOfMarque(int iNation)
{
	ref PChar = GetMainCharacter();
	string sNation = ""+iNation;
	aref arTmp;
	if (iNation >= 0 && iNation < NATIONS_QUANTITY) {
		makearef(arTmp, PChar.nations.(sNation));
		arTmp.LoM = "1";
	}
	SetServedNation(iNation); // PB: Mark that you're now serving this nation
}

void LooseLetterOfMarque(int iNation)
{
	ref PChar = GetMainCharacter();
	if (!IsInServiceOf(iNation)) return; // PB: Only do this if you HAVE something to lose
	string sNation = ""+iNation;
	if (iNation >= 0 && iNation < NATIONS_QUANTITY) // PB: Only do this if you HAVE something to lose
	{
	//	TraceAndLog("Loose Letter of Marque from " + GetNationNameByType(iNation));
		DeleteAttribute(PChar, "nations."+sNation+".LoM");
		if (ProfessionalNavyNation() == iNation) DeleteAttribute(PChar, "professionalnavy"); // PB: No more navy
	}
	SetServedNation(PERSONAL_NATION);	// PB: Cancel your original served nation
	HoistFlag(GetServedNation());		// PB: Hoist a new appropriate flag
}

bool HaveLetterOfMarque(int iNation)
{
	ref PChar = GetMainCharacter();
	string sNation = ""+iNation;
	if (iNation >= 0 && iNation < NATIONS_QUANTITY)
		return CheckAttribute(PChar, "nations."+sNation+".LoM");
	return false;
}

// PB -->
float GetLetterOfMarqueQuantity()
{
	float numLoM = 0.0;
	for (int i=0; i<NATIONS_QUANTITY; i++)
	{
		if (i == PIRATE) continue;
		if (HaveLetterOfMarque(i)) numLoM = numLoM + 1.0;
	}
	return numLoM;
}

int ProfessionalNavyNation()
{
	ref PChar = GetMainCharacter();
	return ProfessionalNavyNationChar(Pchar);
}

int ProfessionalNavyNationChar(ref char)
{
	if (CheckAttribute(Char, "professionalnavy"))	return sti(Char.professionalnavy);
	return UNKNOWN_NATION;
}

bool IsInAnyService()
{
	if (GetLetterOfMarqueQuantity() > 0) return true;
	return ProfessionalNavyNation() != UNKNOWN_NATION;
}

bool IsInServiceOf(int iNation)
{
	ref PChar = GetMainCharacter();
//	if (iNation == PERSONAL_NATION)				return true; // PB: This unlocks the smuggling quest for Personal Governors
	if (HaveLetterOfMarque(iNation))			return true;
	if (ProfessionalNavyNation() == iNation)	return true;
	return false;
}
// PB <--

//GR -->
void Process_Execution(int exec_score)
{
	ref PChar = GetMainCharacter();
	int Execution_Limit = 10;
	int i;
	string sLogTitle, sLogEntry;
	if(!CheckAttribute(PChar, "executions")) PChar.executions = exec_score;
	else PChar.executions = sti(PChar.executions) + exec_score;
	if(sti(GetAttribute(PChar, "executions")) >= Execution_Limit && CheckAttribute(PChar, "executions_warned"))	// GR: you've already been warned about executing prisoners and done it anyway
	{
		for (i=0; i<NATIONS_QUANTITY; i++)							// Check all nations
		{
			if (i == PIRATE || i == PERSONAL_NATION) continue;				// Executions don't get you kicked out of pirates or your own service
			if (HaveLetterOfMarque(i) || ProfessionalNavyNation() == i)
			{
				LeaveService(PChar, i, false);
			}
		}
		PChar.executions = 0;
		SetServedNation(PIRATE);								// If you're going to behave like a pirate, you can become one!
		sLogTitle = "Marked as a Pirate";
		sLogEntry = "The civilised nations of the world consider me a pirate in consequence of my actions. I had better tread carefully around them if I want to avoid getting my head in a noose. Joining the Brethren of the Coast could be rather profitable. And they don't care what I do to prisoners!";
		WriteNewLogEntry(sLogTitle,sLogEntry, "Personal", true);
	}
}
// GR <--

int GetCurrentFlag()
{
	return sti(characters[GetMainCharacterIndex()].nation);
}

void HoistFlag(int iNation)
{
	int cc, compIdx, iNation1;
	bool bPlayerCompanion;
	bool bCompanionMutiny = false; // KK;
	ref rCharacter;
	ref PChar = GetMainCharacter();

	for (cc = 0; cc < COMPANION_MAX; cc++)
	{
		compIdx = GetCompanionIndex(PChar, cc);
		if(compIdx < 0) continue;
		rCharacter = GetCharacter(compIdx);
		bPlayerCompanion = true;
	//	if (!GetRemovable   (rCharacter))									bPlayerCompanion = false;
		if (sti(GetAttribute(rCharacter, "CompanionEnemyEnable")) == true)	bPlayerCompanion = false;
		if (IsMainCharacter (rCharacter))									bPlayerCompanion = true;
		if (bPlayerCompanion)
		{
			rCharacter.nation = iNation;
			rCharacter.Flags.DoRefresh = true;
		}
		else
		{
			iNation1 = iNation;
			if(GetNationRelation(iNation1, sti(rCharacter.nation)) == RELATION_ENEMY)
			{
				SetMutineer(rCharacter, true);
				bCompanionMutiny = true;
			}
		}
	}
	if (bCompanionMutiny) ShipMutiny(); // KK

	if (IsEntity(&BattleInterface))
	{
		RefreshBattleInterface(true); // TIH: refresh minimap colours if relation changed Aug27'06
	}
	RefreshFlags(); // KK
	if(bSeaActive && iNation == PIRATE)
	{
		LogIt(TranslateString("","You have hoisted a Pirate flag! Argh!"));
		if (ENABLE_EXTRA_SOUNDS == 1) PlaySound("OBJECTS\abordage\abordage_wining.wav");
	}
}

float GetChanceDetectFalseFlag()
{
	// original code -->
	//	float rank = GetRankFromPoints(GetScore(GetMainCharacter()));
	//	return CHANCE_DETECT_FALSE_FLAG_BASE+(CHANCE_DETECT_FALSE_FLAG_MAX-CHANCE_DETECT_FALSE_FLAG_BASE)*rank/MAX_RANK;
	// original code <--

	// PB -->
	if (iForceDetectionFalseFlag ==  1)	return 1.0;
	if (iForceDetectionFalseFlag == -1)	return 0.0;
	// PB <--

	// LDH -->
	ref mchr = GetMainCharacter(); // KK
	float score  = GetScore(mchr); // KK
	float rank   = GetRankFromPoints(score);
	int   sneak  = CalcCharacterSkill(mchr, SKILL_SNEAK);
	int difficulty = GetDifficulty();
	float chance = rank/MAX_RANK * (11.0-sneak)/10.0;
	chance = chance * difficulty/2.0;		// 0.5, 1.0, 1.5, 2.0
	if(IsCharacterPerkOn(mchr, "Disguiser")) chance = chance * 0.9;
	//	chance = chance * (difficulty+1)/3.0;		// alternate difficulty calculation 0.67, 1,0, 1.33, 1.67
	chance = fclamp(CHANCE_DETECT_FALSE_FLAG_BASE, CHANCE_DETECT_FALSE_FLAG_MAX, chance); // PURSEON: so chance doesn't go over min/max
	//	LogIt("False Flag Detection - Score: " + score + ", rank: " + rank + ", Sneak: " + sneak + ", Chance: " + chance*100.0 + "%"); // for testing
	//	LogIt("The chance of your false flag being detected is " + chance*100.0 + "%");	// Tell the player, it might get him used to looking for it.
	return chance;
	// LDH <--
}

string GetSoldiersDialog(int nation, string town)
{
	string dialogfile = "";
	switch(nation) {
	case ENGLAND:
		switch (town) {
		case "Oxbay":
			dialogfile = "Oxbay";
			break;
		case "Greenford":
			dialogfile = "Greenford";
			break;
		case "Charlestown":
			dialogfile = "Oxbay";
			break;
			// default:
			dialogfile = "Redmond";
		}
		break;
	case FRANCE:
		dialogfile = "Falaise De Fleur";
		break;
	case SPAIN:
		dialogfile = "Isla Muelle";
		break;
	case HOLLAND:
		dialogfile = "Douwesen";
		break;
	case PORTUGAL:
		dialogfile = "Conceicao";
		break;
	case PERSONAL_NATION:
		dialogfile = "Personal";
		break;
		// default:
		dialogfile = GetNationIDByType(nation);
	}
	return dialogfile + " Soldier_dialog.c";
}

string GetSoldiersGreeting(int nation, string town)
{
	string greeting = "";
	switch(nation) {
	case ENGLAND:
		switch (town) {
		case "Oxbay":
			greeting = "Oxbay";
			break;
		case "Greenford":
			greeting = "Greenford";
			break;
		case "Charlestown":
			greeting = "Charlestown";
			break;
			// default:
			greeting = "Redmond";
		}
		break;
	case FRANCE:
		greeting = "Falaise De Fleur";
		break;
	case SPAIN:
		greeting = "Isla Muelle";
		break;
	case HOLLAND:
		greeting = "Douwesen";
		break;
	case PORTUGAL:
		greeting = "Conceicao";
		break;
	case PERSONAL_NATION:
		greeting = "Redmond";
		break;
		// default:
		greeting = GetNationIDByType(nation);
	}
	return "Gr_" + greeting + " Soldier";
}

string GetCitizensName(int nation)
{
	switch(nation)
	{
	case ENGLAND: return "ENGLAND"; break;
	case FRANCE: return "FRANCE"; break;
	case SPAIN: return "SPAIN"; break;
	case HOLLAND: return "DOUWESEN"; break;
	case PORTUGAL: return "CONCEICAO"; break;
	case PERSONAL_NATION: return "PERSONAL"; break;
	}
	return "";
}

void InitRelations()
{
	string initfile = "";
	string slpath = GetStorylinePath(FindCurrentStoryline());
	if (FindFile("PROGRAM\" + slpath + "Nations", "*.c", "relations_init.c") != "") {
		initfile = slpath + "Nations\relations_init.c";
		if (LoadSegment(initfile)) {
			relations_init();
			UnloadSegment(initfile);
		}
	} else {
		initfile = "Nations\relations_init.c";
		if (LoadSegment(initfile)) {
			relations_init();
			UnloadSegment(initfile);
		}
	}
}

void InitGroups()
{
	LAi_group_SetRelation("CONCEICAO_SOLDIERS", "CONCEICAO_CITIZENS", LAI_GROUP_FRIEND);
	LAi_group_SetRelation("CONCEICAO_SOLDIERS", "CONCEICAO_SOLDIERS", LAI_GROUP_FRIEND);
	LAi_group_SetRelation("CONCEICAO_SOLDIERS", LAI_DEFAULT_GROUP, LAI_GROUP_FRIEND);
	LAi_group_SetAlarmReaction("CONCEICAO_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
	LAi_group_SetAlarmReaction("CONCEICAO_SOLDIERS", "CONCEICAO_CITIZENS", LAI_GROUP_FRIEND, LAI_GROUP_FRIEND);
	LAi_group_SetLookRadius("CONCEICAO_SOLDIERS", LAI_GROUP_GRD_LOOK);
	LAi_group_SetHearRadius("CONCEICAO_SOLDIERS", LAI_GROUP_GRD_HEAR);
	LAi_group_SetSayRadius("CONCEICAO_SOLDIERS", LAI_GROUP_GRD_SAY);
	LAi_group_SetPriority("CONCEICAO_CITIZENS", LAI_GROUP_PCITIZENS);
	LAi_group_SetPriority("CONCEICAO_SOLDIERS", LAI_GROUP_PGUARDS);

	LAi_group_SetLookRadius("CONCEICAO_CITIZENS", LAI_GROUP_DEF_LOOK);
	LAi_group_SetHearRadius("CONCEICAO_CITIZENS", LAI_GROUP_DEF_HEAR);
	LAi_group_SetSayRadius("CONCEICAO_CITIZENS", LAI_GROUP_DEF_SAY);

	LAi_group_SetAlarmReaction("SMUGGLERS_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
	LAi_group_SetRelation("SMUGGLERS_SOLDIERS", "SMUGGLERS_SOLDIERS", LAI_GROUP_FRIEND);
	LAi_group_SetRelation("SMUGGLERS_CITIZENS", "SMUGGLERS_SOLDIERS", LAI_GROUP_FRIEND);
	LAi_group_SetRelation("SMUGGLERS_SOLDIERS", LAI_DEFAULT_GROUP, LAI_GROUP_FRIEND);
	LAi_group_SetLookRadius("SMUGGLERS_SOLDIERS", LAI_GROUP_GRD_LOOK);
	LAi_group_SetHearRadius("SMUGGLERS_SOLDIERS", LAI_GROUP_GRD_HEAR);
	LAi_group_SetSayRadius("SMUGGLERS_SOLDIERS", LAI_GROUP_GRD_SAY);
	LAi_group_SetAlarmReaction("SMUGGLERS_SOLDIERS", "SMUGGLERS_CITIZENS", LAI_GROUP_FRIEND, LAI_GROUP_FRIEND);
	LAi_group_SetPriority("SMUGGLERS_CITIZENS", LAI_GROUP_PCITIZENS);
	LAi_group_SetPriority("SMUGGLERS_SOLDIERS", LAI_GROUP_PGUARDS);

	LAi_group_SetLookRadius("SMUGGLERS_CITIZENS", LAI_GROUP_DEF_LOOK);
	LAi_group_SetHearRadius("SMUGGLERS_CITIZENS", LAI_GROUP_DEF_HEAR);
	LAi_group_SetSayRadius("SMUGGLERS_CITIZENS", LAI_GROUP_DEF_SAY);

	LAi_group_SetAlarmReaction("DOUWESEN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
	LAi_group_SetRelation("DOUWESEN_CITIZENS", "DOUWESEN_SOLDIERS", LAI_GROUP_FRIEND);
	LAi_group_SetRelation("DOUWESEN_SOLDIERS", "DOUWESEN_SOLDIERS", LAI_GROUP_FRIEND);
	LAi_group_SetRelation("DOUWESEN_SOLDIERS", LAI_DEFAULT_GROUP, LAI_GROUP_FRIEND);
	LAi_group_SetLookRadius("DOUWESEN_SOLDIERS", LAI_GROUP_GRD_LOOK);
	LAi_group_SetHearRadius("DOUWESEN_SOLDIERS", LAI_GROUP_GRD_HEAR);
	LAi_group_SetSayRadius("DOUWESEN_SOLDIERS", LAI_GROUP_GRD_SAY);
	LAi_group_SetAlarmReaction("DOUWESEN_SOLDIERS", "DOUWESEN_CITIZENS", LAI_GROUP_FRIEND, LAI_GROUP_FRIEND);
	LAi_group_SetPriority("DOUWESEN_CITIZENS", LAI_GROUP_PCITIZENS);
	LAi_group_SetPriority("DOUWESEN_SOLDIERS", LAI_GROUP_PGUARDS);

	LAi_group_SetLookRadius("DOUWESEN_CITIZENS", LAI_GROUP_DEF_LOOK);
	LAi_group_SetHearRadius("DOUWESEN_CITIZENS", LAI_GROUP_DEF_HEAR);
	LAi_group_SetSayRadius("DOUWESEN_CITIZENS", LAI_GROUP_DEF_SAY);

	LAi_group_SetAlarmReaction("DOUWESEN_PIRATE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
	LAi_group_SetRelation("DOUWESEN_PIRATE_SOLDIERS", "DOUWESEN_PIRATE_SOLDIERS", LAI_GROUP_FRIEND);
	LAi_group_SetRelation("DOUWESEN_PIRATE_CITIZENS", "DOUWESEN_PIRATE_SOLDIERS", LAI_GROUP_FRIEND);
	LAi_group_SetRelation("DOUWESEN_PIRATE_SOLDIERS", LAI_DEFAULT_GROUP, LAI_GROUP_FRIEND);
	LAi_group_SetLookRadius("DOUWESEN_PIRATE_SOLDIERS", LAI_GROUP_GRD_LOOK);
	LAi_group_SetHearRadius("DOUWESEN_PIRATE_SOLDIERS", LAI_GROUP_GRD_HEAR);
	LAi_group_SetSayRadius("DOUWESEN_PIRATE_SOLDIERS", LAI_GROUP_GRD_SAY);
	LAi_group_SetAlarmReaction("DOUWESEN_PIRATE_SOLDIERS", "DOUWESEN_PIRATE_CITIZENS", LAI_GROUP_FRIEND, LAI_GROUP_FRIEND);
	LAi_group_SetPriority("DOUWESEN_PIRATE_CITIZENS", LAI_GROUP_PCITIZENS);
	LAi_group_SetPriority("DOUWESEN_PIRATE_SOLDIERS", LAI_GROUP_PGUARDS);

	LAi_group_SetLookRadius("DOUWESEN_PIRATE_CITIZENS", LAI_GROUP_DEF_LOOK);
	LAi_group_SetHearRadius("DOUWESEN_PIRATE_CITIZENS", LAI_GROUP_DEF_HEAR);
	LAi_group_SetSayRadius("DOUWESEN_PIRATE_CITIZENS", LAI_GROUP_DEF_SAY);

	LAi_group_SetAlarmReaction("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
	LAi_group_SetRelation("FRANCE_CITIZENS", "FRANCE_SOLDIERS", LAI_GROUP_FRIEND);
	LAi_group_SetRelation("FRANCE_SOLDIERS", "FRANCE_SOLDIERS", LAI_GROUP_FRIEND);
	LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_DEFAULT_GROUP, LAI_GROUP_FRIEND);
	LAi_group_SetLookRadius("FRANCE_SOLDIERS", LAI_GROUP_GRD_LOOK);
	LAi_group_SetHearRadius("FRANCE_SOLDIERS", LAI_GROUP_GRD_HEAR);
	LAi_group_SetSayRadius("FRANCE_SOLDIERS", LAI_GROUP_GRD_SAY);
	LAi_group_SetAlarmReaction("FRANCE_SOLDIERS", "FRANCE_CITIZENS", LAI_GROUP_FRIEND, LAI_GROUP_FRIEND);
	LAi_group_SetPriority("FRANCE_CITIZENS", LAI_GROUP_PCITIZENS);
	LAi_group_SetPriority("FRANCE_SOLDIERS", LAI_GROUP_PGUARDS);

	LAi_group_SetLookRadius("FRANCE_CITIZENS", LAI_GROUP_DEF_LOOK);
	LAi_group_SetHearRadius("FRANCE_CITIZENS", LAI_GROUP_DEF_HEAR);
	LAi_group_SetSayRadius("FRANCE_CITIZENS", LAI_GROUP_DEF_SAY);

	LAi_group_SetAlarmReaction("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
	LAi_group_SetRelation("SPAIN_CITIZENS", "SPAIN_SOLDIERS", LAI_GROUP_FRIEND);
	LAi_group_SetRelation("SPAIN_SOLDIERS", "SPAIN_SOLDIERS", LAI_GROUP_FRIEND);
	LAi_group_SetRelation("SPAIN_SOLDIERS", LAI_DEFAULT_GROUP, LAI_GROUP_FRIEND);
	LAi_group_SetLookRadius("SPAIN_SOLDIERS", LAI_GROUP_GRD_LOOK);
	LAi_group_SetHearRadius("SPAIN_SOLDIERS", LAI_GROUP_GRD_HEAR);
	LAi_group_SetSayRadius("SPAIN_SOLDIERS", LAI_GROUP_GRD_SAY);
	LAi_group_SetAlarmReaction("SPAIN_SOLDIERS", "SPAIN_CITIZENS", LAI_GROUP_FRIEND, LAI_GROUP_FRIEND);
	LAi_group_SetPriority("SPAIN_CITIZENS", LAI_GROUP_PCITIZENS);
	LAi_group_SetPriority("SPAIN_SOLDIERS", LAI_GROUP_PGUARDS);

	LAi_group_SetLookRadius("SPAIN_CITIZENS", LAI_GROUP_DEF_LOOK);
	LAi_group_SetHearRadius("SPAIN_CITIZENS", LAI_GROUP_DEF_HEAR);
	LAi_group_SetSayRadius("SPAIN_CITIZENS", LAI_GROUP_DEF_SAY);

	LAi_group_SetAlarmReaction("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
	LAi_group_SetRelation("ENGLAND_CITIZENS", "ENGLAND_SOLDIERS", LAI_GROUP_FRIEND);
	LAi_group_SetRelation("ENGLAND_SOLDIERS", "ENGLAND_SOLDIERS", LAI_GROUP_FRIEND);
	LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_DEFAULT_GROUP, LAI_GROUP_FRIEND);
	LAi_group_SetLookRadius("ENGLAND_SOLDIERS", LAI_GROUP_GRD_LOOK);
	LAi_group_SetHearRadius("ENGLAND_SOLDIERS", LAI_GROUP_GRD_HEAR);
	LAi_group_SetSayRadius("ENGLAND_SOLDIERS", LAI_GROUP_GRD_SAY);
	LAi_group_SetAlarmReaction("ENGLAND_SOLDIERS", "ENGLAND_CITIZENS", LAI_GROUP_FRIEND, LAI_GROUP_FRIEND);
	LAi_group_SetPriority("ENGLAND_CITIZENS", LAI_GROUP_PCITIZENS);
	LAi_group_SetPriority("ENGLAND_SOLDIERS", LAI_GROUP_PGUARDS);

	LAi_group_SetLookRadius("ENGLAND_CITIZENS", LAI_GROUP_DEF_LOOK);
	LAi_group_SetHearRadius("ENGLAND_CITIZENS", LAI_GROUP_DEF_HEAR);
	LAi_group_SetSayRadius("ENGLAND_CITIZENS", LAI_GROUP_DEF_SAY);

	LAi_group_SetAlarmReaction("SWEDEN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
	LAi_group_SetRelation("SWEDEN_CITIZENS", "SWEDEN_SOLDIERS", LAI_GROUP_FRIEND);
	LAi_group_SetRelation("SWEDEN_SOLDIERS", "SWEDEN_SOLDIERS", LAI_GROUP_FRIEND);
	LAi_group_SetRelation("SWEDEN_SOLDIERS", LAI_DEFAULT_GROUP, LAI_GROUP_FRIEND);
	LAi_group_SetLookRadius("SWEDEN_SOLDIERS", LAI_GROUP_GRD_LOOK);
	LAi_group_SetHearRadius("SWEDEN_SOLDIERS", LAI_GROUP_GRD_HEAR);
	LAi_group_SetSayRadius("SWEDEN_SOLDIERS", LAI_GROUP_GRD_SAY);
	LAi_group_SetAlarmReaction("SWEDEN_SOLDIERS", "SWEDEN_CITIZENS", LAI_GROUP_FRIEND, LAI_GROUP_FRIEND);
	LAi_group_SetPriority("SWEDEN_CITIZENS", LAI_GROUP_PCITIZENS);
	LAi_group_SetPriority("SWEDEN_SOLDIERS", LAI_GROUP_PGUARDS);

	LAi_group_SetLookRadius("SWEDEN_CITIZENS", LAI_GROUP_DEF_LOOK);
	LAi_group_SetHearRadius("SWEDEN_CITIZENS", LAI_GROUP_DEF_HEAR);
	LAi_group_SetSayRadius("SWEDEN_CITIZENS", LAI_GROUP_DEF_SAY);
	
	LAi_group_SetAlarmReaction("AMERICA_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
	LAi_group_SetRelation("AMERICA_CITIZENS", "AMERICA_SOLDIERS", LAI_GROUP_FRIEND);
	LAi_group_SetRelation("AMERICA_SOLDIERS", "AMERICA_SOLDIERS", LAI_GROUP_FRIEND);
	LAi_group_SetRelation("AMERICA_SOLDIERS", LAI_DEFAULT_GROUP, LAI_GROUP_FRIEND);
	LAi_group_SetLookRadius("AMERICA_SOLDIERS", LAI_GROUP_GRD_LOOK);
	LAi_group_SetHearRadius("AMERICA_SOLDIERS", LAI_GROUP_GRD_HEAR);
	LAi_group_SetSayRadius("AMERICA_SOLDIERS", LAI_GROUP_GRD_SAY);
	LAi_group_SetAlarmReaction("AMERICA_SOLDIERS", "AMERICA_CITIZENS", LAI_GROUP_FRIEND, LAI_GROUP_FRIEND);
	LAi_group_SetPriority("AMERICA_CITIZENS", LAI_GROUP_PCITIZENS);
	LAi_group_SetPriority("AMERICA_SOLDIERS", LAI_GROUP_PGUARDS);

	LAi_group_SetLookRadius("AMERICA_CITIZENS", LAI_GROUP_DEF_LOOK);
	LAi_group_SetHearRadius("AMERICA_CITIZENS", LAI_GROUP_DEF_HEAR);
	LAi_group_SetSayRadius("AMERICA_CITIZENS", LAI_GROUP_DEF_SAY);

	LAi_group_SetAlarmReaction("QC_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
	LAi_group_SetRelation("QC_CITIZENS", "QC_SOLDIERS", LAI_GROUP_FRIEND);
	LAi_group_SetRelation("QC_SOLDIERS", "QC_SOLDIERS", LAI_GROUP_FRIEND);
	LAi_group_SetRelation("QC_SOLDIERS", LAI_DEFAULT_GROUP, LAI_GROUP_FRIEND);
	LAi_group_SetLookRadius("QC_SOLDIERS", LAI_GROUP_GRD_LOOK);
	LAi_group_SetHearRadius("QC_SOLDIERS", LAI_GROUP_GRD_HEAR);
	LAi_group_SetSayRadius("QC_SOLDIERS", LAI_GROUP_GRD_SAY);
	LAi_group_SetAlarmReaction("QC_SOLDIERS", "QC_CITIZENS", LAI_GROUP_FRIEND, LAI_GROUP_FRIEND);
	LAi_group_SetPriority("QC_CITIZENS", LAI_GROUP_PCITIZENS);
	LAi_group_SetPriority("QC_SOLDIERS", LAI_GROUP_PGUARDS);

	LAi_group_SetLookRadius("QC_CITIZENS", LAI_GROUP_DEF_LOOK);
	LAi_group_SetHearRadius("QC_CITIZENS", LAI_GROUP_DEF_HEAR);
	LAi_group_SetSayRadius("QC_CITIZENS", LAI_GROUP_DEF_SAY);

	LAi_group_SetAlarmReaction("ANIMIST_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_ENEMY);
	LAi_group_SetRelation("ANIMIST_SOLDIERS", "ANIMIST_SOLDIERS", LAI_GROUP_FRIEND);
	LAi_group_SetLookRadius("ANIMIST_SOLDIERS", LAI_GROUP_GRD_LOOK);
	LAi_group_SetHearRadius("ANIMIST_SOLDIERS", LAI_GROUP_GRD_HEAR);
	LAi_group_SetSayRadius("ANIMIST_SOLDIERS", LAI_GROUP_GRD_SAY);
	LAi_group_SetPriority("ANIMIST_SOLDIERS", LAI_GROUP_PGUARDS);
}

bool CheckGuestNation(int iGuestNation, int iNation)
{
	int i;
	if (iGuestNation >= GUEST1_NATION && iGuestNation <= GUEST2_NATION) {
		for (i = 0; i < NATIONS_QUANTITY; i++)
		{
			if (GetFlagIndex(i) == iGuestNation) return true;
		}
	}
	return false;
}

void SetNationRelationChangeEnable(int iNation1, int iNation2, bool bEnable)
{
	string stmp;
	if (iNation1 == iNation2 || iNation1 < 0 || iNation1 >= NATIONS_QUANTITY || iNation2 < 0 || iNation2 >= NATIONS_QUANTITY) return;
	stmp = "n" + iNation2;
	if (bEnable) {
		if (CheckAttribute(&Nations[iNation1], "Relations." + stmp + ".lock")) DeleteAttribute(&Nations[iNation1], "Relations." + stmp + ".lock");
		stmp = "n" + iNation1;
		if (CheckAttribute(&Nations[iNation2], "Relations." + stmp + ".lock")) DeleteAttribute(&Nations[iNation2], "Relations." + stmp + ".lock");
	} else {
		Nations[iNation1].Relations.(stmp).lock = true;
		stmp = "n" + iNation1
		Nations[iNation2].Relations.(stmp).lock = true;
	}
}

bool isNationRelationChangeEnabled(int iNation1, int iNation2)
{
	string stmp = "n" + iNation1;
	bool bEnable = true;
	if (iNation1 == iNation2 || iNation1 < 0 || iNation1 >= NATIONS_QUANTITY || iNation2 < 0 || iNation2 >= NATIONS_QUANTITY) return false;
	if (!CheckAttribute(&Nations[iNation1], "Relations." + stmp + ".lock")) {
		stmp = "n" + iNation2;
		if (!CheckAttribute(&Nations[iNation2], "Relations." + stmp + ".lock")) return true;
	}
	return false;
}

int CheckNationsQuantity(int iPeriod)
{
	int iNationsQuantity = 6;
	ref rPeriod; makeref(rPeriod, Periods[iPeriod]);

	bGuest1NationExists = CheckAttribute(rPeriod, "Nations.Guest1");
	bGuest2NationExists = CheckAttribute(rPeriod, "Nations.Guest2");

	if (bGuest1NationExists)
		iNationsQuantity++;
	else
		Nations[GUEST1_NATION].disabled = true;
	if (bGuest2NationExists)
		iNationsQuantity++;
	else
		Nations[GUEST2_NATION].disabled = true;

	return iNationsQuantity;
}

string CheckNationNameByPeriod(int iNation, int iPeriod, bool bDisplay)
{
	string id = "";
	ref rPeriod; makeref(rPeriod, Periods[iPeriod]);
	if (iNation == GUEST1_NATION && CheckAttribute(rPeriod, "Nations.Guest1") == true) {
		id = "Guest1";
	} else {
		if (iNation == GUEST2_NATION && CheckAttribute(rPeriod, "Nations.Guest2") == true) {
			id = "Guest2";
		} else {
			id = GetNationIDByType(iNation);
		}
	}
	if (HasSubStr(id, "Guest") && CheckAttribute(rPeriod, "Nations." + id))  id = rPeriod.Nations.(id);
	if (bDisplay) {
		if (CheckAttribute(rPeriod, "Nations.Name." + id)) id = rPeriod.Nations.Name.(id);
	}
	return id;
}

int GetFlagIndex(int iNation)
{
	ref rNation;
	if (iNation >= 0 && iNation < NATIONS_QUANTITY) {
		makeref(rNation, Nations[iNation]);
		if (CheckAttribute(rNation, "FlagIdx")) return sti(rNation.FlagIdx);
	}
	return iNation;
}
// <-- KK

// Sulan: Improved Random Relations code -->
void RandomNationsRelationsChange()
{
	int i,j;
	int newRelation  = RELATION_UNKNOWN;
	int ServedNation = GetServedNation();
	int random;
	ref pchar = GetMainCharacter();
	string logTitle;
	string logEntry;

	// PB: Rewritten to a maximum of one change per day -->
	if(rand(1000) < RELATION_CHANGE_PROBABILITY*10)			// do relation change
	{
		// STEP 1: Find nations for relation change
		i = PERSONAL_NATION;
		j = PERSONAL_NATION;
		while(i==PERSONAL_NATION || i==PIRATE)				// Pirate relation doesn't change
		{
			i = rand(NATIONS_QUANTITY-1);
		}
		while(j==PERSONAL_NATION || j==PIRATE || i==j)		// Also don't change relation to same nation
		{
			j = rand(NATIONS_QUANTITY-1);
		}

		// STEP 2: Figure out what to do with them
		switch(GetNationRelation(i,j))
		{
			case RELATION_ENEMY:
				logTitle = GetNationNameByType(i)+" and "+GetNationNameByType(j)+" make peace";
				logEntry = "After some time of bloody warfare "+GetNationNameByType(i)+" and "+GetNationNameByType(j)+" have declared a ceasefire.";
				if(GetNationRelation2MainCharacter(i)==RELATION_FRIEND && GetNationRelation2MainCharacter(j)==RELATION_FRIEND) logEntry += " This is good news as it was a very hard time to keep friendly relations with two warfaring parties.";
				if(IsInServiceOf(i) && GetNationRelation2MainCharacter(j)==RELATION_ENEMY) logEntry += "\n \nAlthough good news in general, this is bad news for me. Attacking "+GetNationDescByType(j)+" ships and towns will not raise my reputation with the "+GetNationDescByType(i)+" anymore.";
				if(IsInServiceOf(j) && GetNationRelation2MainCharacter(i)==RELATION_ENEMY) logEntry += "\n \nAlthough good news in general, this is bad news for me. Attacking "+GetNationDescByType(i)+" ships and towns will not raise my reputation with the "+GetNationDescByType(j)+" anymore.";
				WriteNewLogEntry(logTitle, logEntry, "General",false);
				newRelation = RELATION_NEUTRAL;
				break;
			case RELATION_NEUTRAL:
				random = rand(2);
				if(random==0)
				{
					logTitle = GetNationNameByType(i)+" and "+GetNationNameByType(j)+" have allied";
					logEntry = GetNationNameByType(i)+" and "+GetNationNameByType(j)+" have formed an alliance. Attacking ships or towns of either nation will also decrease the standing with the ally.";
					if(GetNationRelation2MainCharacter(i)==RELATION_FRIEND && GetNationRelation2MainCharacter(j)==RELATION_FRIEND) logEntry += " Very good news, indeed. Working for the "+GetNationDescByType(i)+" and the "+GetNationDescByType(j)+", as I currently do, my deeds will raise my standing with both nations.";
					if(GetNationRelation2MainCharacter(i)==RELATION_ENEMY && GetNationRelation2MainCharacter(j)==RELATION_ENEMY) logEntry += " Whoops! It seems I have bothered them a little too much. But their alliance won't stop me.";
					if(IsInServiceOf(i) && GetNationRelation2MainCharacter(j)==RELATION_ENEMY) logEntry += "\n \nThis makes working for the "+GetNationDescByType(i)+" somewhat more difficult, as sinking "+GetNationDescByType(j)+" ships is no longer an option.";
					if(IsInServiceOf(j) && GetNationRelation2MainCharacter(i)==RELATION_ENEMY) logEntry += "\n \nThis makes working for the "+GetNationDescByType(j)+" somewhat more difficult, as sinking "+GetNationDescByType(i)+" ships is no longer an option.";
					WriteNewLogEntry(logTitle, logEntry, "General",false);
					newRelation = RELATION_FRIEND;
				}
				if(random==1)  // i declared war on j
				{
					logTitle = GetNationNameByType(i)+" is at war with "+GetNationNameByType(j);
					logEntry = GetNationNameByType(i)+" has declared war on "+GetNationNameByType(j)+". "+GetNationDescByType(i)+" ships have attacked a small "+GetNationDescByType(j)+" settlement, as I was told.";
					if(IsInServiceOf(i) && GetNationRelation2MainCharacter(j)==RELATION_ENEMY) logEntry += "\n \nIt was about time to show those "+GetNationDescByType(j)+" landlubbers who's in charge in the caribbean!";
					if(IsInServiceOf(j) && GetNationRelation2MainCharacter(i)==RELATION_ENEMY) logEntry += "\n \nThose bloody cowards! The next "+GetNationDescByType(i)+" ship we encounter will surely pay for this.";
					WriteNewLogEntry(logTitle, logEntry, "General",false);
					newRelation = RELATION_ENEMY;
				}
				if(random==2)  // j declared war on i
				{
					logTitle = GetNationNameByType(j)+" is at war with "+GetNationNameByType(i);
					logEntry = GetNationNameByType(j)+" has declared war on "+GetNationNameByType(i)+". "+GetNationDescByType(j)+" troops have landed near  "+GetTownByNation(i)+", as I was told.";
					if(IsInServiceOf(i) && GetNationRelation2MainCharacter(j)==RELATION_ENEMY) logEntry += "\n \nThose bloody cowards! The next "+GetNationDescByType(j)+" ship we encounter will surely pay for this.";
					if(IsInServiceOf(j) && GetNationRelation2MainCharacter(i)==RELATION_ENEMY) logEntry += "\n \nIt was about time to show those "+GetNationDescByType(i)+" landlubbers who's in charge in the caribbean!";
					WriteNewLogEntry(logTitle, logEntry, "General",false);
					newRelation = RELATION_ENEMY;
				}
				break;
			case  RELATION_FRIEND:
				random = rand(2);
				if(random==0)
				{
					logTitle = GetNationNameByType(i)+" and "+GetNationNameByType(j)+" broke their alliance";
					logEntry = GetNationNameByType(i)+" and "+GetNationNameByType(j)+" have broken their alliance, but are currently peaceful. Observers report military activity on both sides, but so far an open conflict has been avoided.";
					newRelation = RELATION_NEUTRAL;
				}
				if(random==1) // i broke the alliance
				{
					logTitle = GetNationNameByType(i)+" and "+GetNationNameByType(j)+" broke their alliance";
					logEntry = GetNationNameByType(i)+" and "+GetNationNameByType(j)+" have broken their alliance and are now at war! It was reported that "+GetNationNameByType(i)+" broke the alliance by "+GetBreakAllianceReason(i,j);
					if(IsInServiceOf(j) && GetNationRelation2MainCharacter(i)==RELATION_ENEMY) logEntry += "\n \nThose treacherous bastards! The "+GetNationDescByType(i)+" will pay for this betrayal. I have ordered to open fire on sight of any "+GetNationDescByType(i)+" ship.";
					WriteNewLogEntry(logTitle, logEntry, "General",false);
					newRelation = RELATION_NEUTRAL;
				}
				if(random==2) // j broke the alliance
				{
					logTitle = GetNationNameByType(j)+" and "+GetNationNameByType(i)+" broke their alliance";
					logEntry = GetNationNameByType(j)+" and "+GetNationNameByType(i)+" have broken their alliance and are now at war! It was reported that "+GetNationNameByType(j)+" broke the alliance by "+GetBreakAllianceReason(j,i);
					if(IsInServiceOf(i) && GetNationRelation2MainCharacter(j)==RELATION_ENEMY) logEntry += "\n \nThose treacherous bastards! The "+GetNationDescByType(j)+" will pay for this betrayal. I have ordered to open fire on sight of any "+GetNationDescByType(j)+" ship.";
					WriteNewLogEntry(logTitle, logEntry, "General",false);
					newRelation = RELATION_ENEMY;
				}
			break;
		}

		// STEP 3: Change relation and match player if required
		SetNationRelationBoth(i, j, newRelation);
		if(ServedNation != PERSONAL_NATION)				// For any player that serves a specific nation
		{
			if(i == ServedNation || j == ServedNation)
			{
				if(i == ServedNation) i = j;			// Don't change your relation to your OWN nation
				SetNationRelation2MainCharacter(i, newRelation);
			}
		}

		// STEP 4: Notify the player that this happened the first time
		if(!CheckAttribute(PChar, "changing_relations_note"))	// PB: Add clarifying note
		{
			SetQuestHeader("changing_relations");
			AddQuestRecord("changing_relations", "1");
			CloseQuestHeader("changing_relations");
			PChar.changing_relations_note = 1;
		}
	}
	// PB: Rewritten to a maximum of one change per day <--
}

string GetBreakAllianceReason(int traitor, int victim)
{
	int random;

	string sReasons[6];
	sReasons[0] = "'accidently' sinking the "+GetNationDescByType(victim)+" military supply convoy.";
	sReasons[1] = "treating the "+GetNationDescByType(victim)+" ambassador in a 'disrespectful' manner, as was reported from Europe.";
	sReasons[2] = "brutally burning down a small settlement of the "+GetNationDescByType(victim)+", leaving no one alive (I am curious how they got this report then?).";
	sReasons[3] = "officially knighting a notorious freebooter, who plundered the "+GetNationDescByType(victim)+" colonies in the previous war.";
	sReasons[4] = "inciting a slave revolt in a major "+GetNationDescByType(victim)+" colony.";
	sReasons[5] = "sending a horde of French squirrels with blond wigs to pillage a Spanish monastery.\n \n This doesn't make any sense at all and does not really explain why "+GetNationNameByType(traitor)+" broke their alliance, but that's what they did.";

	random = rand(5);
	return sReasons[random];
}
// <-- Sulan
