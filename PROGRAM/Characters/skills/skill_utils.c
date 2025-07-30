//=====================================================
//  Skill Functions
//=====================================================

string PickSkillNoAutoLevel(ref chref)
{
	string skill;
	int importance = 0;
	float importance_total = stf(chref.skillimportancetotal);
	if(importance_total < 1) return "freeskill";
	int PickVal = rand(makeint(importance_total));
	for(int n = 0; n < NUM_DIFF_SKILLS; n++)
	{
		skill = GetSkillName(n);
		importance = sti(chref.skill.(skill).importance);
		if(PickVal <= importance)
		{
			if(GetCharacterSkill(chref, skill) >= MAX_CHARACTER_SKILL)
			{
				chref.skillimportancetotal = sti(chref.skillimportancetotal) - sti(chref.skill.(skill).importance);
				chref.skill.(skill).importance = 0;
				if(DEBUG_NOAUTOLEVEL > 1) Trace("Importance for "+skill+" is set to 0 because skill is maxed out");
				return PickSkillNoAutoLevel(chref);
			}
			else
			{
				return skill;
			}
		}
		else
		{
			PickVal = PickVal - importance;
		}
	}
	//if all fails return the last one because it means the rand value was to higher
	Trace("XP ERROR: Overflow in PickSkillNoAUtoLevel");
	return skill;
}

//Simple Increase of base skill
void IncreaseBaseSkill(ref character, string skillName, int inc)
{
	character.Skill.(skillName) = GetCharacterBaseSkill(character, skillName) + inc;
	ResetEffectiveSkill(character, skillName); // PB: Need to recalculate this
}

// Simple personal skill, only including personal modifications
// Note: use CalcCharacterSkill instead to consider item
//  modifiers.
int GetCharacterSkill(ref character, string skillName)
{
	int skillPoints = GetCharacterBaseSkill(character, skillName);
	//Levis add a character based modifier also
	skillPoints += GetCharacterCharMod(character, skillName);
	skillPoints = iclamp(0, MAX_CHARACTER_SKILL, skillPoints);
	return skillPoints;
}

//This returns just the skill value
int GetCharacterBaseSkill(ref character, string skillName)
{
	int skillPoints = 0;
	if(CheckAttribute(character, "Skill." + skillName))
	{
		skillPoints = sti(character.Skill.(skillName));
	}
	return skillPoints;
}

//This function returns the charmod for the skill if it isn't calculated it will be calculated
int GetCharacterCharMod(ref character, string skillName)
{
	if(!CheckAttribute(character,"skill."+skillName+".charmod"))
	{
		character.skill.(skillName).charmod = CalcCharacterCharMod(character, skillName);
	}
	return sti(character.skill.(skillName).charmod);
}

//This function calculates the charmod by checking all that are set to this character
int CalcCharacterCharMod(ref character, string skillName)
{
	int retval = 0;
	if(CheckAttribute(character,"charmods."+skillName))
	{
		aref charmod; makearef(charmod,character.charmods.(skillName));
		int nummods = GetAttributesNum(charmod);
		for(int n = 0; n < nummods; n++)
		{
			retval += sti(GetAttributeValue(GetAttributeN(charmod, n)));
		}
	}
	return retval;
}

//Call this function for a specific skill to give it a bonus or penalty.
//The ID can be used to remove just this charmode. The desc can be used to give it a describtion (TODO)
void SetSkillCharMod(ref character, string skillName, int offset, string id, string desc)
{
	if(CheckAttribute(character,"charmods."+skillName+"."+id))
	{
		//If it already exists we change the id
		id = id + "_new";
		//Now call it again so it gets set right
		SetSkillCharMod(character, skillName, offset, id, desc)
	}
	else
	{
		character.charmods.(skillName).(id) = offset;
		character.charmods.(skillName).(id).desc = desc;
		ResetCharMod(character, skillName); //reset stuff so it gets recalced
	}
	if(offset < 0)
	{
		//Check if an old importance is present. It might be we just put a skill which was maxed out already down so in that case we should put back the importance
		if(CheckAttribute(character,"skill."+skillName+".importance.old"))
		{
			character.skill.(skillName).importance = character.skill.(skillName).importance.old;
			DeleteAttribute(&character,"skill."+skillName+".importance.old");
		}
	}
}

//This can be called to remove a specific charmod
void RemoveSkillCharMod(ref character, string skillName, string id)
{
	if(CheckAttribute(character,"charmods."+skillName+"."+id))
	{
		//First check if a newer one was set
		if(CheckAttribute(character,"charmods."+skillName+"."+id+"_new"))
		{
			//If a newer one was set we want to remove this one first
			id = id + "_new";
			RemoveSkillCharMod(character, skillName, id);
		}
		else
		{
			//If there isn't a newer one we remove this one
			DeleteAttribute(&character,"charmods."+skillName+"."+id);
			ResetCharMod(character, skillName); //reset stuff so it gets recalced
		}
	}
}

//Reset charmod
//Call this to have the system recalc the charmod
void ResetCharMod(ref character, string skillName)
{
	DeleteAttribute(character, "skill." + skillName + ".charmod");
	ResetEffectiveSkill(character, skillName); //Reset EffectiveSkill so it all gets calculated again
}

// Reset effective skills
// Called on gaining a skill point in AddXPtoSkill AND when GetEffectiveSkill detects officer type has been changed
void ResetEffectiveSkill(ref character, string skillName)
{
	DeleteAttribute(character, "skill." + skillName + ".effective");
	ResetPartySkill(character, skillName);
}

void ResetEffectiveSkillAll(ref character)
{
	for(int i = 0; i < NUM_DIFF_SKILLS; i++)
	{
		if(DEBUG_EXPERIENCE>1) trace("XP LOG: Reset effective skill "+GetSkillName(i));
		ResetEffectiveSkill(character, GetSkillName(i));
	}
}

// Reset ONLY party skills
// Called when officer is added by AddPassenger or removed by RemovePassenger
void ResetPartySkill(ref character, string skillName)
{
	DeleteAttribute(character, "skill." + skillName + ".party");
	int idx = FindCaptainIndex(character);
	if(idx >= 0)
	{
		//If this character is part of a party we want to have the whole party.
		ref captain = GetCharacter(idx);
		DeleteAttribute(captain, "skill." + skillName + ".party");
	}
	ResetShipSkill(character, skillName);
}

// Reset ship skills
// Called when GetShipSkill detects ship class or fleet size has changed
void ResetShipSkill(ref character, string skillName)
{
	DeleteAttribute(character, "skill." + skillName + ".ship");
	int idx = FindCaptainIndex(character);
	if(idx >= 0)
	{
		// The ship skills are stored with the captain, not the officer
		ref captain = GetCharacter(idx);
		DeleteAttribute(captain, "skill." + skillName + ".ship");
	}
}

// Total personal skill, including item modifiers
int CalcCharacterSkill(ref character, string skillName)
{
	int skillPoints = GetCharacterSkill(character, skillName)
	if(!CheckAttribute(character, "Skill." + skillName + ".modifier"))
	{
		skillPoints += CalcSkillModifier(character, skillName);
	}
	else
	{
		skillPoints += sti(character.Skill.(skillName).modifier);
	}
	skillPoints = iclamp(0, MAX_CHARACTER_SKILL, skillPoints);
	return skillPoints;
}

// Effective personal skill, based on officer type
int GetEffectiveSkill(ref character, string skillName)
{
	if (GetAttribute(character,"skill."+skillName+".officertype") != GetAttribute(character,"quest.officerType")) // Levis: Detect this has changed and update accordingly
	{
		ResetEffectiveSkill(character, skillName);
	}

	int skillPoints = 0;
	if (CheckAttribute(character, "Skill." + skillName + ".effective"))
	{
		skillPoints = sti(character.Skill.(skillName).effective);
	}
	else
	{
		skillPoints = CalcEffectiveSkill(character, skillName);
	}
	return skillPoints;
}

int CalcEffectiveSkill(ref character, string skillName)
{
	int skillPoints = CalcCharacterSkill(character, skillName);
	skillPoints = GetEffectiveSkillByValue(character, skillName, skillPoints);
	character.Skill.(skillName).effective   = skillPoints;
	character.skill.(skillName).officertype = GetAttribute(character,"quest.officerType"); // Levis: we also store for which officertype this is set, so when it's changed we know to change the mod too
	return skillPoints;
}

int GetEffectiveSkillByValue(ref character, string skillName, int skillPoints)
{
	if(IsCompanion(character) || skillName == SKILL_FENCING) // PB: Perhaps treat ALL captains equally by adding CharacterHasShip?
	{
		return skillPoints;
	}

	if(CheckAttribute(character, "quest.officerType"))
	{
		return (skillPoints * GetOfficerSkillFactor(character, skillName) + 1) / 2;
	}
	
	return 0;
}

int GetPartySkill(ref character, string skillName)
{
	int skillPoints = 0;
	if (CheckAttribute(character, "Skill." + skillName + ".party"))
	{
		skillPoints = sti(character.Skill.(skillName).party);
	}
	else
	{
		skillPoints = CalcPartySkill(character, skillName);
	}
	return skillPoints;
}

int CalcPartySkill(ref character, string skillName)
{
	int skillPoints = CalcCharacterSkill(character, skillName); // Captain can use ALL skills
	if(skillName != SKILL_FENCING) // Aconcagua: Fencing is a personal skill...
	{
		int i, cn, charSkill;
		if(IsMainCharacter(character))
		{
			int num = GetPassengersQuantity(character);
			for(i = 0; i < num; i++)
			{
				cn = GetPassenger(character, i);
				if(cn < 0)													continue;
				ref chr = GetCharacter(cn);
				if(CheckAttribute(chr, "prisoned") || IsCompanion(chr))		continue;
	
				charSkill = GetEffectiveSkill(chr, skillName);
				if(charSkill > skillPoints)	skillPoints = charSkill;
			}
		}
		else
		{
			if (IsCompanion(character))
			{
				for(i = 1; i < OFFICER_MAX; i++)
				{
					cn = GetOfficersIndex(&character,i);
					if(cn >= 0)
					{
						charSkill = GetEffectiveSkill(GetCharacter(cn), skillName);
						if(charSkill > skillPoints)	skillPoints = charSkill;
					}
				}
			}
		}
	}
	character.Skill.(skillName).party = skillPoints;
	return skillPoints;
}

int GetShipSkill(ref character, string skillName)
{
	if (skillName == SKILL_LEADERSHIP || skillName == SKILL_SAILING)
	{
		bool ResetSkills = GetCharacterShipClass(character) != sti(GetAttribute(character, "skill." + skillName + ".shipclass"));
		ResetSkills = ResetSkills || GetCompanionQuantity (character) != sti(GetAttribute(character, "skill." + skillName + ".fleetsize"));
		if (ResetSkills) ResetShipSkill(character, skillName);
	}

	int skillPoints = 0;
	if (CheckAttribute(character, "Skill." + skillName + ".ship"))
	{
		skillPoints = sti(character.Skill.(skillName).ship);
	}
	else
	{
		skillPoints = CalcShipSkill(character, skillName);
	}
	return skillPoints;
}

int CalcShipSkill(ref character, string skillName)
{
	int skillPoints = GetPartySkill(character, skillName);
	int shipclass   = GetCharacterShipClass(character);
	if(EnableLimitedShipClass() && skillPoints > 1 && shipclass > 0)
	{
		if(skillName == SKILL_LEADERSHIP || skillName == SKILL_SAILING)
		{
			if (shipclass < 6)
			{
				int dclass = shipclass - GetShipMinClassForCharacter(character);
				if (dclass < 0)
				{
					skillPoints += dclass;
				}
			}
			if (IsMainCharacter(character))
			{
				if (GetPartySkill(character, SKILL_LEADERSHIP) < FLEETCOMMAND_MIN_LEVEL && CheckFleetShips(false))
				{
					skillPoints--;
				}
			}
		}
	}

	if(skillPoints < 1)	skillPoints = 1;
	character.Skill.(skillName).ship        = skillPoints;
	character.skill.(skillName).shipclass   = shipclass;
	character.skill.(skillName).fleetsize   = GetCompanionQuantity (character);
	return skillPoints;
}

//=====================================================
//  Skill Modifier Functions
//=====================================================

// Set skill modifier from items
int CalcSkillModifier(ref character, string skillName)
{
	int j, qty;
	int mod = 0;
	ref itm;

	int iChrCabin = FindCharacterShipCabin(character); // KK
	for(j = 0; j < SKILLITEMS_QUANTITY; j++)
	{
		itm = &Items[NativeFindCharacter(&Items, SkillItems[j].id)];
		if(!CheckAttribute(itm, "skill." + skillName))
			continue;
// KK -->

		string itmid = itm.id;
		qty = GetCharacterItem(character, itmid);

		if (iChrCabin >= 0 && CheckAttribute(&Locations[iChrCabin], "box1.items." + itmid) == true)
			qty += sti(Locations[iChrCabin].box1.items.(itmid));
// <-- KK
		if( qty >= sti(itm.skill.num)) // *.skill.num = num required for effect. Default = 1
		{
			if(CheckAttribute(itm, "groupID") && IsCanEquiping(character, itm.groupID) && !IsEquipCharacterByItem(character, itmid))
				continue; // if equipable and not equipped, skip // KK

			// *.stack = bool indicating if items can be stacked together. Default = false (JRH)
			if(sti(itm.skill.stack) == false) qty = 1;
			mod += sti(itm.skill.(skillName)) * qty; // PB: Used to end with '/sti(itm.skill.num)'
		}
	}

//	mod = iclamp(-MAX_SKILL_INCREASE, MAX_SKILL_INCREASE, mod); // PB: Single line
	mod = iclamp(-100, MAX_SKILL_INCREASE, mod);				// JRH: for cursed coins
	character.skill.(skillName).modifier = mod;
	return mod;
}

// Reset item skill modifier
// Called when receiving/losing a skill item through TakeNItems
void ResetSkillModifier(ref character, string skillName)
{
	DeleteAttribute(character, "skill." + skillName + ".modifier");
	ResetEffectiveSkill(character, skillName);
}

void ResetSkillModifierAll(ref character)
{
	for(int i = 0; i < NUM_DIFF_SKILLS; i++)
	{
		if(DEBUG_EXPERIENCE>1) trace("XP LOG: Reset skill modifier "+GetSkillName(i));
		ResetSkillModifier(character, GetSkillName(i));
	}
}

void ResetPartySkillAll(ref character)
{
	for(int i = 0; i < NUM_DIFF_SKILLS; i++)
	{
		if(DEBUG_EXPERIENCE>1) trace("XP LOG: Reset party skill "+GetSkillName(i));
		ResetPartySkill(character, GetSkillName(i));
	}
}
