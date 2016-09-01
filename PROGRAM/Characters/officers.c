object OfficerTypes;

//=======================| OFFICERS |=======================//
#define OFFIC_TYPE_REGCAP 		"captain"// NK -->
#define OFFIC_TYPE_CAPMERCHANT	"merchant captain"
#define OFFIC_TYPE_CAPPRIVATEER	"privateer captain" // PB
#define OFFIC_TYPE_CAPNAVY 		"navy captain"
#define OFFIC_TYPE_CAPPIRATE	"pirate captain"
#define OFFIC_TYPE_PIRATE		"pirate"
#define OFFIC_TYPE_RANDCHAR 	"fighter"
#define OFFIC_TYPE_CIVILIAN 	"civilian"// NK <--
#define OFFIC_TYPE_SAILOR 		"sailors"
#define OFFIC_TYPE_BOATSWAIN 	"boatswain"
#define OFFIC_TYPE_CANNONEER 	"cannoneer"
#define OFFIC_TYPE_QMASTER 		"quartermaster"
#define OFFIC_TYPE_NAVIGATOR 	"navigator"
#define OFFIC_TYPE_FIRSTMATE 	"first mate"
#define OFFIC_TYPE_CARPENTER 	"carpenter"// MAXIMUS -->
#define OFFIC_TYPE_DOCTOR 		"doctor"
#define OFFIC_TYPE_ABORDAGE 	"deck fighter"// MAXIMUS <--
#define OFFIC_TYPE_TRADER		"trader" // KK
#define OFFIC_TYPE_GUARD		"guard" // Levis
#define OFFIC_TYPE_SHOPKEEPER	"shop merchant" // Levis

extern void eInitOfficerTypes();

void InitOfficerTypes()
{
	if(LoadSegment("Characters\officertypes\init_officertypes.c"))
	{
		eInitOfficerTypes();
		UnloadSegment("Characters\officertypes\init_officertypes.c");
	}
}

int GetOfficerSkillFactor(ref Officer, string SkillName)
{
	int skillFactor;
	string officType = Officer.quest.officerType;
	if(CheckAttribute(OfficerTypes, officType))
	{
		if(!CheckAttribute(OfficerTypes,officType+".skills"))
		{
			trace("ERROR: missing skills for "+officType+" for Character "+GetMySimpleName(Officer)); 
			DumpAttributes(Officer);
			Officer.quest.officerType = GetRandomEnemyType();
			officType = Officer.quest.officerType;
		}
		skillFactor = sti(OfficerTypes.(officType).skills.(SkillName)); // KK
	}
	else
	{
		trace("ERROR: missing skillfactor for type "+officType+" and skill "+SkillName); 
		DumpAttributes(Officer);
		skillFactor = 2;
	}
	// factor: can be 0, 1, 2:
	// 0: no contribution
	// 1: half contribution
	// 2: full contribution
	
	return skillFactor;
}

float GetOfficerPriceMod(ref Officer)
{
	if(CheckAttribute(Officer, "quest.officertype"))
	{
		if(CheckAttribute(OfficerTypes,Officer.quest.officertype+".pricemod"))
		{
			string officType = Officer.quest.officertype;
			return stf(OfficerTypes.(officType).pricemod);
		}
	}
	return 1.0;
}

string GetBoardingCrewType(ref Captain)
{
	if(!CheckAttribute(Captain, "quest.officertype"))
	{
		trace("ERROR Captain "+Captain.id+" does't have a officertype. This shouldn't happen");
		Captain.quest.officertype = GetCaptainType(Captain);
	}
	if(CheckAttribute(OfficerTypes,Captain.quest.officertype+".crewtype"))
	{
		string officType = Captain.quest.officertype;
		return OfficerTypes.(officType).crewtype;
	}
	return GetRandomEnemyType();
}

int GetHPBaseBonusOT(ref chr)
{
	if(CheckAttribute(chr, "quest.officertype"))
	{
		if(CheckAttribute(OfficerTypes,chr.quest.officertype+".hpbasebonus"))
		{
			string officType = chr.quest.officertype;
			return sti(OfficerTypes.(officType).hpbasebonus);
		}
	}
	return 0;
}

int GetHPLevelBonusOT(ref chr)
{
	if(CheckAttribute(chr, "quest.officertype"))
	{
		if(CheckAttribute(OfficerTypes,chr.quest.officertype+".hplevelbonus"))
		{
			string officType = chr.quest.officertype;
			return sti(OfficerTypes.(officType).hplevelbonus);
		}
	}
	return 0;
}

int GetOfficTypeRankBonus(string officertype)
{
	if(CheckAttribute(OfficerTypes,officertype+".rankbonus"))
	{
		return sti(OfficerTypes.(officertype).rankbonus);
	}
	return 0;
}

int GetCaptainIndexCompanion(ref officer)
{
	if(CheckAttribute(officer,"CompanionOf.idx")) return sti(officer.CompanionOf.idx);
	return -1;
}

void MakeOfficerCaptain(ref officer)
{
	if (CheckAttribute(officer, "quest.officertype")) officer.quest.oldofficertype = officer.quest.officertype; // PB: Just in case
	officer.quest.officertype = GetCaptainType(officer);
	officer.quest.officerprice.old = sti(officer.quest.officerprice);
}

void RestoreOfficerFromCaptain(ref officer)
{
	if(CheckAttribute(officer,"quest.oldofficertype"))
	{
		officer.quest.officertype = officer.quest.oldofficertype;
	}
	else
	{
		officer.quest.officertype = GetRandomOfficerType();
	}
	//Also restore the old officerprice
	if(CheckAttribute(officer,"quest.officerprice.old"))
	{
		officer.quest.officerprice = sti(officer.quest.officerprice.old);
	}
	else
	{
		officer.quest.officerprice = GetBaseOfficerPrice(officer);
	}
	DeleteAttribute(officer,"quest.officerprice.old");
	DeleteAttribute(officer,"quest.oldofficertype");
}

string GetRandomEnemyType()
{
	string retVal = "";
	int numtypes = GetAttributesNum(OfficerTypes);
	int picked;
	int attempts = 0;
	string type;
	while(retVal == "")
	{
		picked = rand(numtypes-1);
		type = GetAttributeName(GetAttributeN(OfficerTypes,picked));
		if(CheckAttribute(OfficerTypes,type+".EnemyType"))
		{
			retVal = type;
		}
		if(attempts>10) retVal = OFFIC_TYPE_RANDCHAR;
		else attempts ++;
	}
	return retVal;
}

string GetRandomOfficerType()
{
	string retVal = "";
	int numtypes = GetAttributesNum(OfficerTypes);
	int picked;
	int attempts = 0;
	string type;
	while(retVal == "")
	{
		picked = rand(numtypes-1);
		type = GetAttributeName(GetAttributeN(OfficerTypes,picked));
		if(CheckAttribute(OfficerTypes,type+".usableoffictype"))
		{
			retVal = type;
		}
		if(attempts>10) retVal = OFFIC_TYPE_ABORDAGE;
		else attempts ++;
	}
	return retVal;
}

bool UsableOfficer(ref _refEnemy)
{
	if(CheckAttribute(_refEnemy,"quest.officertype"))
	{
		return UsableOfficerType(_refEnemy.quest.officertype, true);
	}
	return false;
}

bool UsableOfficerType(string officertype, bool bUsable)
{
	if(!CheckAttribute(OfficerTypes,officertype)) 
	{
		if (DEBUG_OFFICERPRICE > 0) trace("OFFIC TYPE ERROR: Type "+officertype+" not present");
	}
	else
	{
		if(!bUsable || CheckAttribute(OfficerTypes,officertype+".usableoffictype"))
		{
			return true;
		}
	}
	return false;
}

int FindFreeRandomOfficer()
{
	// this function rewritten by KAM so new officers don't keep overwriting captains on shore leave [changes made by MAXIMUS 07.10.2007]

	for(int tempnum=0; tempnum<=NUM_RANDOM_OFFICERS; tempnum++) // NK 05-03-30 we now use char not exist to stop loop, so we can have any number of enc_off.
	{
		string tempid = "Enc_Officer_" + tempnum;
		int tempidx = GetCharacterIndex(tempid);
		if(tempidx==-1) break; // NK 05-03-30 ditto
		ref tempChar = GetCharacter(tempidx);

		if(bAllies(tempChar))									{ continue; }
		if(tempChar.location == loadedLocation.id)				{ continue; }	// PB: To prevent prospective officers from disappearing when you're talking to them
		if(LAi_IsBoardingProcess())
		{
			if (tempChar.id == boarding_enemy.id)				{ continue; }	// PB: Skip the captain of the ship you're currently boarding
			if (IsOfficerOf(boarding_enemy, tempChar))			{ continue; }	// MM: Skip also any officers assigned to this ship
		}

	//	TraceAndLog("FindFreeRandomOfficer clears " + GetMySimpleName(tempChar));
		ClearCharacter(tempChar); // PB: Completely erase the unused character

		return tempidx;
	}

	return -1;
}

void UseAyahuasca(ref officer)
{
	float a,b,c;
	GetCharacterPos(officer, &a, &b, &c);
	int action = rand(100);
	if(action<=5) //5% chance
	{
		//Kill the officer
		CreateParticleSystem("fire" , a, b+0.0, c, 0.0, 0.0, 0.0, 1);
		CreateParticleSystem("fire" , a, b+0.4, c, 0.0, 0.0, 0.0, 1);
		CreateParticleSystem("fire" , a, b+0.8, c, 0.0, 0.0, 0.0, 1);
		CreateParticleSystem("fire" , a, b+1.2, c, 0.0, 0.0, 0.0, 1);
		CreateParticleSystem("fire" , a, b+1.6, c, 0.0, 0.0, 0.0, 1);
		LAi_KillCharacter(officer);
		Logit(TranslateString("","Officer Got Killed"));
		return;
	}
	if(action<=35)	// 30% chance
	{
		//Poison the officer
		officer.chr_ai.poison = 150;
		Logit(TranslateString("","Officer Got Poisoned"));
		return;
	}
	if(action<=65) //30% chance
	{
		//Add XP
		int exp = (5-GetDifficulty())*pow(sti(officer.rank),0.5)*(rand(7)+3)*1800
		AddCharacterExpNS(officer, exp);
		Logit(TranslateString("","Officer Got Experience"));
		return;
	}
	if(action<=75) //10% Chance
	{
		//Unlock mind
		CreateParticleSystem("stars_short" , a, b+1.0, c, 0.0, 0.0, 0.0, 1);
		MakeSuperOfficer(officer);
		Logit(TranslateString("","Officer Got Unlocked"));
		return;
	}
	//else do nothing
	Logit(TranslateString("","Nothing happened"));
	return;
}

bool MakeSuperOfficer(ref officer)
{
	if(!CheckAttribute(officer,"unlocked_mind"))
	{
		officer.unlocked_mind = true;
		return true;
	}
	return false;
}