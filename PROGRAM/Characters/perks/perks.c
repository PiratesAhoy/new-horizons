
#event_handler("evntChrPerkDelay","procChrPerkDelay");
//#include "interface\perks\perks_init.c"; //Added by Levis, There is only 1 perks init file so we can just use include can't we?
//Levis: To be safe reversed this how it used to be, should help with memory management as well.

#define 	PERK_TYPE_COMBAT		"Combat"
#define 	PERK_TYPE_SAILING		"Sailing"
#define 	PERK_TYPE_SEACOMBAT		"Sea Combat"
#define 	PERK_TYPE_SEADEFENCE	"Sea Defence"
#define 	PERK_TYPE_BOARDING		"Boarding"
#define 	PERK_TYPE_MERCHANT		"Merchant"
#define 	PERK_TYPE_DARING		"Daring"
#define 	PERK_TYPE_PARTY			"Party"
#define 	PERK_TYPE_REPAIR		"Repair"
#define 	PERK_TYPE_MISC			"Misc"

object ChrPerksList;
object PerkTypes;

extern void extrnInitPerks();

void InitPerks()
{
	DeleteAttribute(&ChrPerksList,"");
	if( LoadSegment("Characters\perks\perks_init.c") )
	{
		extrnInitPerks();
		UnloadSegment("Characters\perks\perks_init.c");
	}
	InitPerkTypes();
}

void InitPerkTypes()
{
	//Here we set which abilities govern the perktype the most.
	//The numbers behind it show the importance of the skills
	//The total sum for the perk type should be 10
	string type = PERK_TYPE_COMBAT;
	PerkTypes.(type).Skill.Fencing = 4;
	PerkTypes.(type).Skill.Grappling = 2;
	PerkTypes.(type).Skill.Accuracy = 3;
	PerkTypes.(type).Skill.Defence = 1;
	
	type = PERK_TYPE_SAILING;
	PerkTypes.(type).Skill.Sailing = 10;
	
	type = PERK_TYPE_SEACOMBAT;
	PerkTypes.(type).Skill.Sailing = 2;
	PerkTypes.(type).Skill.Cannons = 4;
	PerkTypes.(type).Skill.Accuracy = 2;
	PerkTypes.(type).Skill.Defence = 2;
	
	type = PERK_TYPE_SEADEFENCE;
	PerkTypes.(type).Skill.Sailing = 1;
	PerkTypes.(type).Skill.Repair = 3;
	PerkTypes.(type).Skill.Defence = 6;
	
	type = PERK_TYPE_BOARDING;
	PerkTypes.(type).Skill.Grappling = 8;
	PerkTypes.(type).Skill.Fencing = 2;
	
	type = PERK_TYPE_MERCHANT;
	PerkTypes.(type).Skill.Commerce = 8;
	PerkTypes.(type).Skill.Sneak = 2;
	
	type = PERK_TYPE_DARING;
	PerkTypes.(type).Skill.Sneak = 6;
	PerkTypes.(type).Skill.Commerce = 2;
	PerkTypes.(type).Skill.Fencing = 2;
	
	type = PERK_TYPE_PARTY;
	PerkTypes.(type).Skill.Leadership = 3;
	PerkTypes.(type).Skill.Defence = 5;
	PerkTypes.(type).Skill.Sneak = 2;
	
	type = PERK_TYPE_REPAIR;
	PerkTypes.(type).Skill.Repair = 7;
	PerkTypes.(type).Skill.Defence = 3;
	
	type = PERK_TYPE_MISC;
	PerkTypes.(type).Skill.Leadership = 10;

	//Add all the perks to the types to for easy lookup
	aref perklist, condition; 
	makearef(perklist, ChrPerksList.list);
	int num = GetAttributesNum(perklist);
	int condnum = 0;
	string perkname, perktype, perkname2;
	for(int n = 0; n < num; n++)
	{
		perkname = GetAttributeName(GetAttributeN(perklist, n));
		if(!CheckAttribute(perklist,perkname+".type"))
		{
			TraceAndLog("PERK ERROR: perk "+perkname+" doesn't have a type. Please post your compile.log file at piratesahoy.net!");
			//DeleteAttribute(perklist,perkname); //remove it cause it's probably useless and else people will at least notice better
			num -= 1;
			continue;
		}
		perktype = perklist.(perkname).type;
		PerkTypes.(perktype).Perks.(perkname) = perklist.(perkname).cost;
		if(CheckAttribute(perklist,perkname+".rank")) PerkTypes.(perktype).Perks.(perkname).rank = perklist.(perkname).rank;
		//Check if the perk unlocks another perk because that is better
		for(int i = 0; i < num; i++)
		{
			perkname2 = GetAttributeName(GetAttributeN(perklist, i));
			if(!CheckAttribute(perklist,perkname2+".type"))
			{
				trace("PERK ERROR: perk "+perkname2+" doesn't have a type");
				continue;
			}
			if(perktype == perklist.(perkname2).type)
			{
				if(CheckAttribute(perklist,perkname2+".condition"))
				{
					makearef(condition,perklist.(perkname2).condition);
					condnum = GetAttributesNum(condition);
					for(int j = 0; j < condnum; j++)
					{
						if(perkname == GetAttributeName(GetAttributeN(condition, j))) PerkTypes.(perktype).Perks.(perkname).unlocks = true;
					}
				}
			}
		}
	}
}

bool CheckPerkAvailable(string perkName)
{
	//if( CheckCharacterPerk(refUsedCharacter,perkName) ) return false;
	//return true;
	//Levis Disable perks -->
	int i, dn;
	aref arCur, arDis;
	string needName;
	makearef(arDis,ChrPerksList.list.(perkName).disable);
	dn = GetAttributesNum(arDis);
	
	for(i=0; i<dn; i++)
	{
		arCur = GetAttributeN(arDis,i);
		needName = GetAttributeName(arCur);
		switch(needName)
		{
			case "iRealismMode":
				if(REALISTIC_ABILITIES == 1 && iRealismMode>=sti(GetAttributeValue(arCur)))		{ return false; } // PB: To allow REALISTIC_ABILITIES to override the Realism Mode
			break;
			
			case "REALISTIC_ABILITIES":
				if(REALISTIC_ABILITIES == 1 && iRealismMode == 0)								{ return true;  } // PB: To ensure Arcade Game Mode does override the Build Default
				if(REALISTIC_ABILITIES >= sti(GetAttributeValue(arCur)))						{ return false; }
			break;
			
			case "StorylineVar":
				if(sti(GetStorylineVar(FindCurrentStoryline(), GetAttributeValue(arCur))) < 1)	{ return false; }
			break;
		}
	}
	//Levis Disable perks <--
	return true;
}

//Levis Check rank
bool CheckPerkRank(ref character, string perkName)
{
	if( CheckAttribute(ChrPerksList,"list."+perkName + ".rank"))
	{
		if( CheckAttribute(character,"rank"))
		{
			int Playerrank = makeint(character.rank);
			int Perkrank = makeint(ChrPerksList.list.(perkName).rank);
			if(Playerrank >= Perkrank)
			{
				return true;
			}
		}
		return false;
	}
	return true;
}

int GetPerkRank(string perkName)
{
	if( CheckAttribute(ChrPerksList,"list."+perkName + ".rank"))
	{
		int Perkrank = makeint(ChrPerksList.list.(perkName).rank);
		return Perkrank;
	}
	return 0;
}

//Check perk conditions
bool CheckPerkConditions(ref refUsedCharacter, string PerkName)
{
	aref perkARef; 
	makearef(perkARef, ChrPerksList.list.(PerkName).condition);
	string abilName;
	bool canassign = true;
	for(int i = 0; i < GetAttributesNum(perkARef); i++)
	{
		abilName = GetAttributeName(GetAttributeN(perkARef,i));
		if(!CheckPerkSimple(refUsedCharacter, abilName))
		{
			canassign = false;
		}
	}
	return canassign;
}

//Levis Locked Perks -->
bool CheckCharacterPerkLocked(ref Character, string perkName)
{
	if(PerkHasLock(Character, perkName))
	{
		if(!CheckAttribute(Character,"unlocked_mind"))
		{
			if( CheckAttribute(Character,"perks.unlocked."+perkName))
			{
				return false;
			}
			if(IsOfficerCompanion(Character))
			{
				ref captain = GetCharacter(FindCaptainIndex(Character));
				return CheckCharacterPerkLocked(captain, perkName)
			}
			if(IsPassenger(character) && !IsMainCharacter(character))
			{
				//If the main character has the perk unlocked then all officers will have it unlocked to. not the other way around tough.
				return CheckCharacterPerkLocked(GetMainCharacter(), perkName);
			}
			if(IsCompanion(character)&& !IsMainCharacter(character))
			{
				//If the main character has the perk unlocked then all officers will have it unlocked to. not the other way around tough.
				return CheckCharacterPerkLocked(GetMainCharacter(), perkName);
			}
			if(!IsMainCharacter(character))
			{
				//This is a random Character so return what the mainCharacter has for locked perks.
				return CheckCharacterPerkLocked(GetMainCharacter(), perkName);
			}
			return true;
		}
	}
	return false;
}

bool PerkHasLock(ref Character, string perkName)
{
	//Checks if the perk has a lock
	if(ALLOW_LOCKED_PERKS)
	{
		if( CheckAttribute(ChrPerksList,"list."+perkName + ".locked"))
		{
			return true;
		}
		if( CheckAttribute(Character,"perks.locked."+perkName))
		{
			return true;
		}
	}
	return false;
}

bool UnlockPerkCharacter(ref Character, string perkName)
{
	if(!CheckAttribute(Character,"perks.unlocked."+perkName))
	{
		if(PerkHasLock(Character, perkName)) //Levis only unlock if there is a lock in place
		{
			//Only show notification if player is main character
			if(IsMainCharacter(Character) && GetAttribute(Character, "location") != "Tutorial_Deck") // PB: Skip sound here
			{
				int lngFileID = LanguageOpenFile("AbilityDescribe.txt");
				string Text = LanguageConvertString(lngFileID,"Unlocked");
				string Name = LanguageConvertString(lngFileID,perkName);
				PlaySound("INTERFACE\notebook.wav");
				Logit(Text + " " + Name);
				LanguageCloseFile(lngFileID);
			}
			DeleteAttribute(Character,"perks.locked."+perkName);
			Character.perks.unlocked.(perkName) = true;
			return true;
		}
	}
	return false;
}

void LockPerk(ref Character, string perkName)
{
	Character.perks.locked.(perkName) = true;
}
// <--Levis Locked Perks

bool CheckCharacterPerk(ref chref, string perkName)
{
	/*if(isOfficerPerk(chref, perkName)) //Only when the perk is in the scope of this character
	{
		if (CheckPerkAvailable(perkName)) //Levis disable perks
		{
			if( CheckAttribute(chref,"perks.list."+perkName) ) return true;
		}
	}
	return false;*/
//	return CheckPerkForGroup(chref, perkName); //Levis
	return CheckPerkForSingleCharacter(chref, perkName); // GR - shouldn't this be a single character check rather than entire group?
}

void ActivateCharacterPerk(ref chref, string perkName)
{
	if( !CheckAttribute(&ChrPerksList,"list."+perkName) )
	{
		trace("Invalid perk name - " + perkName);
		return;
	}

	int timeDelay = 0;
	int timeDuration = 0;

	if( CheckAttribute(&ChrPerksList,"list."+perkName+".TimeDuration") )
	{	timeDelay = sti(ChrPerksList.list.(perkName).TimeDuration);
		timeDuration = timeDelay;
	}
	if( CheckAttribute(&ChrPerksList,"list."+perkName+".TimeDelay") )
	{	timeDelay = sti(ChrPerksList.list.(perkName).TimeDelay);
		if(timeDuration<=0)	{timeDuration=timeDelay;}
	}

	chref.perks.list.(perkName).delay = timeDelay;
	chref.perks.list.(perkName).active = timeDuration;

	if(sti(chref.index)==GetMainCharacterIndex())
	{
		AddPerkToActiveList(perkName);
	}

	if(timeDelay>0) PostEvent("evntChrPerkDelay",1000,"sl",perkName,sti(chref.index));
	Event("eSwitchPerks","l",sti(chref.index));
}

bool GetCharacterPerkUsing(ref chref, string perkName)
{
	/*if(!isOfficerPerk(chref, perkName)) return false; //not in the scope of this character -Levis
	if( !CheckAttribute(chref,"perks.list."+perkName) ) return false;
	if( CheckAttribute(chref,"perks.list."+perkName+".delay") ) return false;
	return true;*/
	return CheckPerkForGroup(chref, perkName); //Levis
}

bool GetOfficersPerkUsing(ref chref, string perkName)
{
	/*int i, cn;
	if(IsMainCharacter(chref))
	{
		if(GetCharacterPerkUsing(chref, perkName))
		{
			return true;
		}

		int num = GetPassengersQuantity(chref);
		for(i = 0; i < num; i++)
		{
			cn = GetPassenger(chref, i);
			if(cn < 0)
				continue;

			ref chr = GetCharacter(cn);
			if(CheckAttribute(chr,"prisoned") || IsCompanion(chr) || IsTrader(chr))
				continue;

			if(GetCharacterPerkUsing(GetCharacter(cn), perkName))
			{
				return true;
			}
		}
	}
	else
	{
		// current char is officer 0
		for(i = 0; i < 4; i++)
		{
			cn = GetOfficersIndex(chref , i);
			if(cn<0) {continue;}
			if( GetCharacterPerkUsing(&Characters[cn], perkName) ) {return true;}
		}
	}
	return false;*/
	return CheckPerkForGroup(chref, perkName); //Levis
}

bool IsCharacterPerkOn(ref chref, string perkName)
{
	aref arRoot, arBase;
	makearef(arRoot,chref.perks.list);
	if( !CheckAttribute(arRoot,perkName) ) return false;
	makearef(arBase,ChrPerksList.list.(perkName));
	if( CheckAttribute(arBase,"TimeDuration") || CheckAttribute(arBase,"TimeDelay") ) {
		return CheckAttribute(arRoot,perkName+".active");
	}
	return true;
}

// NK -->
bool GetPerkBool(ref chr, string perk, bool summ) //return char+officers perk check if summ, else return char perk check
{
	if(summ) return GetOfficersPerkUsing(&chr, perk);
	return IsCharacterPerkOn(&chr, perk);
}
// NK <--

void CharacterPerkOff(ref chref, string perkName)
{
	DeleteAttribute(chref,"perks.list."+perkName+".active");
	Event("eSwitchPerks","l",sti(chref.index));
	if(sti(chref.index)==GetMainCharacterIndex())
	{
		DelPerkFromActiveList(perkName);
	}
}

bool CheckOfficersPerk(ref chref, string perkName)
{
	/*int i,cn;
	if(CheckPerkAvailable(perkName)) //Levis disable perks
	{
		for (i = 0; i < 4; i++)
		{
			cn = GetOfficersIndex(chref, "" + i);
			if (cn < 0) continue;
			if (IsCharacterPerkOn(GetCharacter(cn), perkName)) return true;
		}
	}
	return false;*/
	return CheckPerkForGroup(chref, perkName);
}

void procChrPerkDelay()
{
	string perkName = GetEventData();
	int chrIdx = GetEventData();

	aref arPerk;
	makearef(arPerk,Characters[chrIdx].perks.list.(perkName));
	if( !CheckAttribute(arPerk,"delay") ) return;
	int delay = sti(arPerk.delay);
	delay--;

	if( CheckAttribute(arPerk,"active") )
	{
		int iActive = sti(arPerk.active)-1;
		if( iActive>0 )	{arPerk.active = iActive;}
		else
		{
			CharacterPerkOff(GetCharacter(chrIdx),perkName);
		}
	}

	if( delay<=0 )
	{	DeleteAttribute(&Characters[chrIdx],"perks.list."+perkName+".delay");
		DeleteAttribute(&Characters[chrIdx],"perks.list."+perkName+".active");
		PostEvent("evntPerkAgainUsable",1);
	}
	else
	{
		Characters[chrIdx].perks.list.(perkName).delay = delay;
		PostEvent("evntChrPerkDelay",1000,"sl",perkName,chrIdx);
	}
}

void EnableUsingAbility(ref chref,string perkName)
{
	Event("evntChrPerkDelay","sl",perkName,sti(chref.index));
}

void PerkLoad()
{
//	int iRDTSC = RDTSC_B();

	ref mainCh = GetMainCharacter();
	string locName = mainCh.location;
	aref arPerksRoot,arPerk;
	int i,j,n,tmpi;

	//TODO: Use loaded locations instead
	for(i=0; i<CHARACTERS_QUANTITY; i++) // NK 05-04-05 use CHARACTERS_QUANTITY. This is weird, though, it doesn't count fantoms.
	{
		if(Characters[i].location == locName)
		{
			makearef(arPerksRoot,Characters[i].perks.list);
			n = GetAttributesNum(arPerksRoot);
			for(j=0; j<n; j++)
			{
				arPerk = GetAttributeN(arPerksRoot,j);
				if( CheckAttribute(arPerk,"delay") )
				{
					tmpi = sti(arPerk.delay);
					if( tmpi>0 )
					{
						PostEvent("evntChrPerkDelay",1000,"sl",GetAttributeName(arPerk),i);
					}
				}
			}
		}
	}

//	trace("TIME!!! PerkLoad() = " + RDTSC_E(iRDTSC));
}

void ClearActiveChrPerks(ref chref)
{
	aref arPerksRoot, arPerk;
	int i,n,j,cn;

	for (j = 0; j < OFFICER_MAX; j++)
	{
		cn = GetOfficersIndex(chref,j);
		if( cn<0 ) {continue;}
		makearef( arPerksRoot, Characters[cn].perks.list );
		n = GetAttributesNum(arPerksRoot);
		for (i = 0; i < n; i++)
		{
			arPerk = GetAttributeN(arPerksRoot,i);
			if (CheckAttribute(arPerk,"delay"))		DeleteAttribute(arPerk,"delay");
			if (CheckAttribute(arPerk,"active"))	DeleteAttribute(arPerk,"active");
		}
	}
}

bool isPerkAssignable(ref character, string perkName, int freePoints)
{
	//Check if already assigned
	if(CheckPerkForSingleCharacter(character, perkName)) return false;
	//Check free points
	if(freePoints < GetPerkCost(perkName)) return false;
	//Locked Perks
	if(CheckCharacterPerkLocked(character, perkName)) return false;
	//Added by Levis, Just to be sure
	if(!CheckPerkAvailable(perkName)) return false;
	//Check Rank
	if(!CheckPerkRank(character, perkName)) return false;
	//Check Conditions
	if(!CheckPerkConditions(character, PerkName)) return false;
	//Removed by Levis, should already be done in Perklist and else in CheckPerkAvaible.
	/*aref disable;
	makearef(disable, ChrPerksList.list.(perkName).disable);
	if(CheckAttribute(disable, "iRealismMode") && sti(disable.iRealismMode) <= iRealismMode)
		return false;
	if(CheckAttribute(disable, "REALISTIC_ABILITIES") && disable.REALISTIC_ABILITIES <= REALISTIC_ABILITIES)
		return false;

	aref conditions;
	makearef(conditions, ChrPerksList.list.(perkName).condition);
	int num = GetAttributesNum(conditions);
	int n;
	for(n = 0; n < num; n++)
	{
		string perk = GetAttributeName(GetAttributeN(conditions, n));
		makearef(disable, ChrPerksList.list.(perkName).disable);
		if(!CheckAttribute(disable, "iRealismMode") || sti(disable.iRealismMode) > iRealismMode)
		{
			if(!CheckAttribute(disable, "REALISTIC_ABILITIES") || disable.REALISTIC_ABILITIES > REALISTIC_ABILITIES)
			{
				if(!CheckCharacterPerk(character, perk))
					return false;
			}
		}
	}*/
	return true;
}

bool isPerkAssignableNoLock(ref character, string perkName, int freePoints)
{
	//Check if already assigned
	if(CheckPerkForSingleCharacter(character, perkName)) return false;
	//Check free points
	if(freePoints < GetPerkCost(perkName)) return false;
	//Added by Levis, Just to be sure
	if(!CheckPerkAvailable(perkName)) return false;
	//Check Rank
	if(!CheckPerkRank(character, perkName)) return false;
	//Check Conditions
	if(!CheckPerkConditions(character, PerkName)) return false;
	return true;
}

bool isPerkAssignableOfficer(ref character, string perkName, int freePoints)
{
	//Check if perk is already chosen
	if(CheckPerkSimple(character, perkName)) return false;
	//Check free points
	if(freePoints < GetPerkCost(perkName)) return false;
	//Check if avaible
	if(!CheckPerkAvailable(perkname)) return false;
	//Check Rank
	if(!CheckPerkRank(character, perkName)) return false;
	//Check Conditions
	if(!CheckPerkConditions(character, PerkName)) return false;
	return true;
}

bool isPerkExisting(string perkName)
{
	return CheckAttribute(&ChrPerksList, "list." + perkName);
}

// Aconcagua: moved to here
//Levis show only officer perks
bool isOfficerPerk(ref character, string perkName)
{
	if(IsMainCharacter(character)) return true; //Main Character has all perks
	//Check if perk is a combat perk, if so return true
	aref allPerks;
	makearef(allPerks, OfficerTypes.Combat.perks);
	int num = GetAttributesNum(allPerks);
	int n;
	string perk;
	for(n = 0; n < num; n++)
	{
		perk = GetAttributeName(GetAttributeN(allPerks, n));
		if(perk == perkName)
		{
			return true;
		}
	}
	//Else check if the perk is for this specific officer
	string officerType = OFFIC_TYPE_RANDCHAR;
	if(CheckAttribute(character,"quest.officertype")) officerType = character.quest.officertype;
	makearef(allPerks, OfficerTypes.(officerType).perks);
	num = GetAttributesNum(allPerks);
	for(n = 0; n < num; n++)
	{
		perk = GetAttributeName(GetAttributeN(allPerks, n));
		if(perk == perkName)
		{
			return true;
		}
	}
	//If officer has unlocked his mind
	if(CheckAttribute(Character,"unlocked_mind"))
	{
		makearef(allPerks, OfficerTypes.SuperOfficer.perks);
		num = GetAttributesNum(allPerks);
		for(n = 0; n < num; n++)
		{
			perk = GetAttributeName(GetAttributeN(allPerks, n));
			if(perk == perkName)
			{
				return true;
			}
		}
	}
	//If nothig returned true then we return false
	return false;
}

//Check only for this character, should only be used for perk interface
bool CheckPerkForSingleCharacter(ref character, string perkName)
{
	if(isOfficerPerk(character, perkName)) //Only when the perk is in the scope of this character
	{
		if (CheckPerkAvailable(perkName)) //Levis disable perks
		{
			return CheckPerkSimple(character, perkName);
		}
	}
	return false;
}

//Checks if a perk is taken or not
bool CheckPerkSimple(ref character, string perkName)
{
	if( CheckAttribute(character,"perks.list."+perkName) ) return true;
	return false;
}

//Levis definitive function to check if the perk should contribute or not
bool CheckPerkForGroup(ref character, string perkName)
{
	//Lets first check if we checked before
	if(CheckAttribute(character,"ContribList."+perkName)) 
	{
		//Because perks are assigned in all different ways and the code to do it is crap we add a random function to sometimes check if the list is still right.
		bool val = sti(character.ContribList.(perkName));
		return val;
	}
	//Check if we are dealing with a captain cause they shouldn't contribute
	string officerType = OFFIC_TYPE_RANDCHAR;
	if(CheckAttribute(character,"quest.officertype")) officerType = character.quest.officertype;
	if(CheckAttribute(OfficerTypes,officerType+".notcontribute")) 
	{
		if(GetCharacterShipType(character) == SHIP_NOTUSED)
		{
			return false;
		}
	}
	if(!CheckPerkAvailable(perkName)) return false;
	//If it isn't in the contriblist we check what should be in there
	int i,cn;
	aref allPerks;
	ref chr, captain;
	//First check the character
	if(CheckPerkForSingleCharacter(character, perkName)){ character.ContribList.(perkName)=true;  return true;}
	//Else check if the perk is a combat perk or special perk
	makearef(allPerks, OfficerTypes.Combat.perks);
	int num = GetAttributesNum(allPerks);
	string perk;
	for(i = 0; i < num; i++)
	{
		perk = GetAttributeName(GetAttributeN(allPerks, i));
		if(perk == perkName)
		{
			//It's one of the combat perks so check if its selected yet
			character.ContribList.(perkName)=CheckPerkinList(character, perkName); 
			return CheckPerkinList(character, perkName);
		}
	}
	//Look trough the officers
	num = GetPassengersQuantity(character);
	for(i = 0; i < num; i++)
	{
		cn = GetPassenger(character, i);
		if(cn < 0) continue;
		chr = GetCharacter(cn);
		if(CheckAttribute(chr,"prisoned") || IsTrader(chr)) continue;
		captain = GetCharacter(FindCaptainIndex(character));
		if(CheckPerkForSingleCharacter(chr, perkName)){ character.ContribList.(perkName)=true;  return true;}
	}
	//Maybe you are a officer instead of a captain so check the perks of your captain too
	if(IsPassenger(character) && GetOfficerOf(character) != GetAttribute(character, "index"))
	{
		captain = GetCharacter(FindCaptainIndex(character));
		if(CheckPerkForSingleCharacter(captain, perkName)){ character.ContribList.(perkName)=true;  return true;} // Only checks if the captain is personally contributing the perk, not if he's getting it from his officers
		if(CheckPerkForGroup(captain, perkName)){ character.ContribList.(perkName)=true;  return true;}
	}
	character.ContribList.(perkName)=false; 
	return false;
}

bool CheckPerkinList(ref Character, string perkName)
{
	if( !CheckAttribute(character,"perks.list."+perkName) ) return false;
	if( CheckAttribute(character,"perks.list."+perkName+".delay") ) return false;
	return true;
}

//Levis Add perkcost-->
int GetPerkCost(string perkName)
{
	aref Perk;
	makearef(Perk,ChrPerksList.list.(perkName));
	if (CheckAttribute(Perk,"cost") && PERK_MULTIPLIER>0)
	{
		int cost = makeint(sti(Perk.cost)*PERK_MULTIPLIER);
		if(cost>0)
		{
			return cost;
		}
		else
		{
			return 1;
		}
	}
	return 1;
}
//<-- Levis Add perkcost
