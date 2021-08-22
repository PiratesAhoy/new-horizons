//Leveling file completly rewritten for BETA4 by Levis and Pieter Boelen

//Initialize some stuff
int AllDaysCount;//MAXIMUS: calculates days amount (updating in calendar.c)
bool PostInitActive = false;
object PostInitQueue;
object SkillBonus;

#event_handler("PostInitChars","PostInitChars");
#event_handler("procAddXPtoSkillsMain","procAddXPtoSkillsMain");
#event_handler("procSelectPerksForCharacter","procSelectPerksForCharacter");
#event_handler("procAddXP","procAddXP");
#event_handler("procPreparePerks","procPreparePerks");

#include "Characters\skills\skill_utils.c";
#include "Characters\perks\perks.c"

#define DEBUG_EXPERIENCE	0					//(int) on 0 no messages are given. on 1 only error, on 2 everything is given.
#define DEBUG_POSTINIT		0					//(int) on 0 no messages are given. on 1 only error, on 2 everything is given.
#define DEBUG_NOAUTOLEVEL	0					//(int) on 0 no messages are given. on 1 only error, on 2 everything is given.
#define DEBUG_PERKSELECT	0					//(int) on 0 no messages are given. on 1 only error, on 2 everything is given.
#define DEBUG_OFFICERPRICE	0					//(int) on 0 no messages are given. on 1 only error, on 2 everything is given.

#define XP_GROUP_PLAYER		"player"			//(DO NOT CHANGE) XP will only be given to the player
#define XP_GROUP_OFFIC		"officers"			//(DO NOT CHANGE) XP will be given to player and officers
#define XP_GROUP_PARTY		"party"				//(DO NOT CHANGE) XP will be given to everyone in the party

#define SKILLS_UP_BONUS			25				// From 10 to 99 - speed of player's skills-increase
#define SKILL_EXPERIENCE_MULTIPLIER	0.8			// FLOAT - Must be a float higher than 0.0 - default is 1.0 - the rate at which the characters gain skill experience: For a 30% increase set to 1.3
#define EXPERIENCE_MULTIPLIER	0.8				// FLOAT - Must be a float higher than 0.0 - default is 1.0 - the rate at which the characters gain experience: For a 30% increase set to 1.3

#define ADD_SKILLPOINTS_PERLEVEL		2		// INT - The amount of new skill points added each level up for ALL characters (player and officers)
#define ADD_ABILITYPOINTS_PERLEVEL		1		// INT - The amount of new ability points added each level up for ALL characters (player and officers)

#define IMPORTANCE_BONUS_GAIN			25		// INT - The multiplier for the importance if a bonus is present for this skill
#define IMPORTANCE_SKILL_GAIN			30		// INT - The multiplier for each level the character has already in this skill
#define IMPORTANCE_BOOST				40		// INT - The multiplier for the importance set in officers.c

#define NPC_ONE_BONUS_CHANCE			60		// INT - The chance an NPC will have only 1 bonus skill
#define NPC_TWO_BONUS_CHANCE			30		// INT - The chance an NPC will have 2 bonus skills. If one and two aren't 100 together, there is a chance the NPC has no bonus skills.

#define	POSTINIT_AMOUNT_PIECES			3		// INT - Divide the XP given to a character on a post init run by this. Make this higher to increase amount of FPS at load, but longer post init
#define POSTINIT_AMOUNT_LEVELS			1		// INT - Amount of levels done simultaniously on post init. Higher is lower post init time but also lower FPS on load
#define POSTINIT_MAX_ALLOW_LEVEL_POST	20		// INT - Characters higher then this level wont be going trough post init, lower this to get shorter post init but longer loading times

//=====================================================
//  MAIN FUNCTION
//=====================================================

//This function is called each character load
void InitAutoSkillsSystem(ref refCharacter, bool dailyUpdate)
{
	RestoreCharacterEvents(refCharacter); //Check if any events were stored in the character which need to be processed
	if(!IsMainCharacter(refCharacter))
	{
		if ( CheckAttribute(refCharacter,"corpse")) return;
		if ( CheckAttribute(refCharacter,"isBuilding")) return; //we don't need to check buildings
		if (!CheckAttribute(refCharacter,"completeinit")) 
		{
			if(DEBUG_EXPERIENCE>1 || DEBUG_POSTINIT>1) Trace("Need to init skills");
			InitCharacterSkills(refCharacter);
			return;
		}
		if(!bAllies(refCharacter))
		{
			if(DEBUG_EXPERIENCE>1 || DEBUG_POSTINIT>1 || DEBUG_NOAUTOLEVEL > 1) Trace("XP LOG: Start InitAutoSkillsSystem for "+GetMySimpleName(refCharacter)+" id: "+refCharacter.id);
			/*if (!CheckAttribute(refCharacter,"Experience")) refCharacter.Experience = 1;
			if (!CheckAttribute(refCharacter,"rank")) refCharacter.rank = 1;*/ //Should be fixed by InitCharacter Already
			//int nextSkill = 50000;
			//int skillsCalc = 0;
			//if(SKILLS_UP_BONUS<10) SKILLS_UP_BONUS = 10;
			//if(SKILLS_UP_BONUS>99) SKILLS_UP_BONUS = 99;
			if(dailyUpdate && AUTO_SKILL_SYSTEM)
			{
				float curSpeed = makefloat(stf(SKILLS_UP_BONUS+100)/100);
				int numUp = sti(GetDataYear() + GetDataMonth() + AllDaysCount);
				int expUp = sti(GetDifficulty()*500);
				if (CheckAttribute(refCharacter,"locDate") && numUp - sti(refCharacter.locDate) > 0) {
					numUp = sti(numUp - sti(refCharacter.locDate));
					expUp = expUp*numUp;
				} else {
					expUp = 0;
				}
				//Levis: The rest will now all be handled by the addxp function.
				AddXP(refCharacter, "", expUp, XP_GROUP_PLAYER);
				refCharacter.locDate = sti(GetDataYear() + GetDataMonth() + AllDaysCount);
			}
		}
	}
	else
	{
		if(!CheckAttribute(refCharacter,"completeinit")) refCharacter.completeinit = true;
	}
}

//=====================================================
//  Adding XP functions
//=====================================================

//This function is always called. it determins who should get the XP etc
bool AddXP(ref chref, string expName, int _exp, string group)
{
	ref chr, capt;
	int cn,i;
	bool LevelUp = false;
	//First catch some weird cases which shouldn't happen in the first place. let log if they do happen.
	if(!CheckAttribute(chref,"index")) { if(DEBUG_EXPERIENCE>0) Trace("XP ERROR: Character "+GetMySimpleName(chref)+" has no index"); return false;}
	if(sti(chref.index)<0) { if(DEBUG_EXPERIENCE>0){ Trace("XP ERROR: Character "+GetMySimpleName(chref)+" has index smaller than 0")}; return false; }
	if(_exp < 0) 
	{ 
		_exp = -(_exp); 
		if(DEBUG_EXPERIENCE>0) Trace("XP ERROR: NEGATIVE XP CALL");
	}
	if(_exp == 0)
	{
		if(DEBUG_EXPERIENCE>0) Trace("XP ERROR: ZERO XP CALL");
		return false;
	}
	
	if(DEBUG_EXPERIENCE>0) Trace("XP LOG: Called AddXP for "+GetMySimpleName(chref)+" with skill: "+expName+" and xp: "+_exp+" and group: "+group);

	//If we are only doing the player we can return here (for performance reasons)
	if(group == XP_GROUP_PLAYER)
	{
		//Add a difficulty multiplier
		float diffmult = 1.0-((GetDifficulty()-1.0) / 6.0); //Let's make it a bit less dependent on difficulty
		int xp = makeint(makefloat(_exp)*GetXPmult(expName));
		if(AddXPtoChar(chref, expName, makeint(diffmult*xp))) LevelUp = true;
		return LevelUp;
	}

	//Check for shared experience
	bool SharedXP = GetOfficersPerkUsing(chref,"SharedExperience");
	if(DEBUG_EXPERIENCE>1) { if(SharedXP) Trace("XP LOG: SharedXP is active"); }
	
	//Now handle the officers
	if(group == XP_GROUP_OFFIC)
	{
		float skillmult, tempmult;
		capt = GetCharacter(FindCaptainIndex(chref));												// Get the captain of the ship
		for(i=-1; i < GetPassengersQuantity(capt); i++)												// Start at -1 to include captain
		{
			if (i == -1)	cn = sti(capt.index);													// Captain of the group
			else			cn = GetPassenger(capt, i);												// Passenger of this character
			if (cn < 0)													continue;					// Skip invalid characters
			chr = GetCharacter(cn);																	// Reference to the character
			if (CheckAttribute(chr,"prisoned") && sti(chr.prisoned))	continue;					// Filter prisoned characters
			if(DEBUG_EXPERIENCE>1) Trace("XP LOG: Loop "+i+", Checking Officer "+GetMySimpleName(chr)+" with id "+chr.id);

			// Determine Skill Multiplier for this character
			skillmult = 0.0;
			if (cn == sti(chref.index))											skillmult = 1.0;	// The character who gained the XP gets 100%
			if (expName == "")													skillmult = 1.0;	// All characters join in "general XP"
			if (expName == SKILL_FENCING)															// Fencing is a personal skill and should be handled differently
			{
				if (skillmult < 0.5 && bAllies(chref) && IsOfficer(chr))	skillmult = 0.5;	// Character is in the player shore party
			}
			else																					// For any non-personal skills
			{
				tempmult = GetOfficerSkillFactor(chr, expName);										// This means some officers can get 200% XP!
				if (skillmult < tempmult) skillMult = tempmult;										// The officer who gains the XP will ALWAYS get it
			}
			if (IsMainCharacter(chr))																// Special case for the player, because you cannot focus on all skills at the same time
			{
				skillmult = 0.5;																	// Only 50% of all skills
				if (expName == SKILL_LEADERSHIP)								skillmult = 1.0;	// But a captain MUST know how to lead a crew
				if (expName == SKILL_SAILING)									skillmult = 1.0;	// And navigate a ship
			}
			if (skillmult < 0.5 && SharedXP)									skillmult = 0.5;	// Sharing XP, so everybody gets at least 50%
			if(DEBUG_EXPERIENCE>1) Trace("XP LOG: skillmult = "+skillmult);

			// Add Experience
			if (skillmult > 0.0)																	// If any XP is to be added to this character
			{
				if(AddXP(chr, expName, makeint(_exp*skillmult), XP_GROUP_PLAYER)) LevelUp = true;	// Add that XP and see if it resulted in a Level-Up
			}
		}
	}
	
	//Now handle the companions
	if(group == XP_GROUP_PARTY)
	{
		capt = GetCharacter(FindCommanderIndex(chref));										// Get the commander of the fleet
		for (i = 0; i < COMPANION_MAX; i++)
		{
			cn = GetCompanionIndex(capt, i);
			if (cn < 0) continue;
			chr = GetCharacter(cn);												// Reference to the character
			if(DEBUG_EXPERIENCE>1) Trace("XP LOG: Loop "+i+", Checking Companion "+GetMySimpleName(chr)+" with id "+chr.id);
			if(AddXP(chr, expName, _exp, XP_GROUP_OFFIC)) LevelUp = true;							// Add the XP to the companion and maybe his officers
		}
	}

	//returns true if there is a levelup somewhere
	return LevelUp;
}

//Handle for a single character
bool AddXPtoChar(ref chref, string expName, int _exp)
{
	bool LevelUp = false;
	
	//In case the officertype is changed, we should apply the importances again
//	if(!CheckAttribute(chref,"skillsetup")) InitCharacterSkills(chref); //shouldn't happen but does seem to happen sometimes
	if(!CheckAttribute(chref,"skillsetup") || chref.skillsetup != chref.quest.officerType) // PB: This function can be called FROM InitCharacterSkills, so the above line could trigger an infinite loop
	{
		if(DEBUG_EXPERIENCE>1) Trace("XP LOG: Offictype for "+GetMySimpleName(chref)+" is set or changed so (re)apply the importances.");
		SetCharSkillImportance(chref,1);
	}
	
	int realExp = _exp;
	int officerprice = 0;
	string eventname = "";

	if(DEBUG_EXPERIENCE>0) Trace("XP LOG: Called AddXPtoChar for "+GetMySimpleName(chref)+" with skill: "+expName+" and xp: "+realExp+ " CurXP: "+chref.Experience);
	
	//First add the skillxp so we can use the increase for perk assignment when needed.
	//If we are using the auto skill system let's assign the skill points:
	if(AUTO_SKILL_SYSTEM)
	{
		if (CheckAttribute(chref, "skipPostInit"))	AddXPtoSkillsMain(chref, expName, realExp); // PB: Allow overriding the PostInit process if necessary
		else 										PostEvent("procAddXPtoSkillsMain",0,"lsls",sti(chref.index),expName,realExp,chref.location);
	}
	
	//Now add the overal experience
	//Add the experience to the character.

	int nextExp = CalculateExperienceFromRank(sti(chref.rank)+1);
	int curExp = sti(chref.Experience) + realExp;
	float mhp = 0;
	int n = 0;
	string skill = "freeskill";

	chref.Experience = curExp;
	
	if(CheckAttribute(chref,"completeinit") && curExp >= nextExp && !CheckAttribute(chref,"quest.NoRaise"))
	{
		//We need to check the officerprice before the level is increased. Since the last update maybe the assignment or skill levels have been changed.
		//We only check if we are going levelup
		officerprice = GetBaseOfficerPrice(chref);
		if(DEBUG_OFFICERPRICE > 1) trace("OFFICERPRICE check previous price: "+officerprice+" for "+GetMySimpleName(chref));
	}
	
	//Check if we go level up
	while (curExp >= nextExp)
	{
		//Increase the rank of the character
		chref.rank = sti(chref.rank) + 1;
		//Calculate new nextExp
		nextExp = CalculateExperienceFromRank(sti(chref.rank)+1);
		//Set return value
		LevelUp = true;
		//Add freepoints for perks
		chref.perks.FreePoints = makeint(chref.perks.FreePoints) + ADD_ABILITYPOINTS_PERLEVEL;
		if(CheckAttribute(chref,"completeinit"))
		{
			//Freepoints for skills
			if(!AUTO_SKILL_SYSTEM) 
			{
				if(bAllies(chref))
				{
					chref.skill.freeskill = sti(chref.skill.freeskill) + ADD_SKILLPOINTS_PERLEVEL;
				}
				else
				{
					for(n = 0; n < ADD_SKILLPOINTS_PERLEVEL; n++)
					{
						skill = PickSkillNoAutoLevel(chref);
						IncreaseBaseSkill(chref, skill, 1);
					}
				}
			}
			string LevelText = "";
			//Display the levelup
			if(IsInParty(GetMainCharacterIndex(), sti(chref.index)))
			{
				if (GetAttribute(GetMainCharacter(), "location") != "Tutorial_Deck") // PB: Skip sound here
				{
					if(CheckAttribute(chref,"FakeLevelUp"))
					{
						LevelText = TranslateString("","Fake Level Up") + " for " + GetMySimpleName(chref) + "!" + " " + TranslateString("","(Now level") + " " + chref.rank + ")";
					}
					else
					{
						LevelText = GetMySimpleName(chref) + " " + TranslateString("","has gained a new level!") + " " + TranslateString("","(Now level") + " " + GetTotalRank(chref) + ")");
						PlayStereoSound("interface\new_level.wav");
						AddMsgToCharacter(chref,MSGICON_LEVELUP);
					}
					LogIt(LevelText);
				}
			}
			else
			{
				LevelText = GetMySimpleName(chref) + " " + TranslateString("","has gained a new level!") + " " + TranslateString("","(Now level") + " " + GetTotalRank(chref) + ")");
				//This character has noone to choose his perks so we must do it for him.
				if(!bAllies(chref))
				{
					SelectPerksForCharacter(chref, 2);
				}
			}
			// LDH 01May09
			if(DEBUG_EXPERIENCE>0) Trace(LevelText);
		}
		else
		{
			//Pick Perks
			if(LAi_IsBoardingProcess() || CheckAttribute(chref, "skipPostInit")) // PB: Allow overriding the PostInit process if necessary
			{
				SelectPerksForCharacter(chref, 1); //This is because we need to know which perks a character has for the weapon locker
			}
			else
			{
				PostEvent("procSelectPerksForCharacter",1,"lls",sti(chref.index),1,chref.location);
			}
			if(!AUTO_SKILL_SYSTEM)
			{
				//initializing without autolevel
				for(n = 0; n < ADD_SKILLPOINTS_PERLEVEL; n++)
				{
					skill = PickSkillNoAutoLevel(chref);
					if(DEBUG_NOAUTOLEVEL > 1) trace("Picked "+skill+" freeskill "+chref.skill.freeskill);
					IncreaseBaseSkill(chref, skill, 1);
				}
			}
		}
	}
	//Set new HP
	if(LevelUp)
	{
		if(CheckAttribute(chref,"FakeLevelUp"))
		{
			//Because the resethp takes the fake levels in account already we need to remove them here.
			if(!CheckAttribute(chref,"FakeLevels")) chref.FakeLevels = 0; //Levis
			int oldrank = sti(chref.rank);
			chref.rank = sti(chref.rank) - sti(chref.FakeLevels);
			chref.rank = oldrank;
		}
		if(CheckAttribute(chref,"completeinit")) ResetMaxHP(chref);
		
		//Now we check how much the officer price would have increased and we add this to the already existing officerprice
		if(CheckAttribute(chref,"completeinit") && !CheckAttribute(chref,"quest.NoRaise"))
		{
			officerprice = GetBaseOfficerPrice(chref) - officerprice;
			if(DEBUG_OFFICERPRICE > 1) trace("OFFICERPRICE substracted price is: "+officerprice+" for "+GetMySimpleName(chref));
			if(officerprice > 0) //We'll never lower the officerprice
			{
				chref.quest.OfficerPrice = sti(chref.quest.OfficerPrice) + officerprice;
				//If there is an old officerprice, we raise this too in case it is put back
				if(CheckAttribute(chref,"quest.officerprice.old")) chref.quest.officerprice.old = sti(chref.quest.officerprice.old) + officerprice;
				if(DEBUG_OFFICERPRICE > 1) trace("OFFICERPRICE set to: "+chref.quest.OfficerPrice+" for "+GetMySimpleName(chref));
			}
		}
	}
	return LevelUp;
}

//Add XP to all skills
bool AddXPtoSkillsMain(ref chref, string expName, int skillExp)
{
	if(DEBUG_EXPERIENCE>1) Trace("XP LOG: Called AddXPtoSkillsMain with Exp: "+skillExp);
	//If there is an expname we only add it to that specific skill
	if(expName != "") return AddXPtoSkill(chref, expName, skillExp);
	bool LevelUp = false;
	if(skillExp < 1) return LevelUp;
	//Start the loop
	string skill;
	int importance = 0;
	float importance_total = stf(chref.skillimportancetotal);
	float mult;
	float xp = 0;
	for(int n = 0; n < NUM_DIFF_SKILLS; n++)
	{
		skill = GetSkillName(n);
		importance = sti(chref.skill.(skill).importance);
		//We got a total amount of XP to spend. We divide this over the different skills based on the importance of the skill
		if (importance_total > 0.0) mult = makefloat(importance) / importance_total;
		else						mult = 0.0;
		xp = makefloat(skillExp) * mult;
		if(xp < 1) continue;
		if(AddXPtoSkill(chref, skill, makeint(xp))) LevelUp = true;
	}
	return LevelUp;
}

//Adding XP to a skill
bool AddXPtoSkill(ref chref, string expName, int skillExp)
{
	bool LevelUp = false;
	//if(skillExp < 1) return LevelUp;
	
	//Check if the unmodified skilllevel is zero. if so we don't add experience to it.
	int modval = GetCharacterBaseSkill(chref, expName);
	if(modval == 0) return LevelUp;
	
	//If the importance is set to 0 we skip this skill also
	if(sti(chref.skill.(expName).importance) == 0) return LevelUp;
	
	int chrSkillExp = sti(chref.Experience.(expName));
	
	//Add the bonus to the experience
	if (CheckAttribute(chref,"skill."+expName+".bonus")) skillExp = makeint(skillExp * stf(chref.skill.(expName).bonus));
	
	// Add the multiplier
	skillExp = makeint(skillExp * SKILL_EXPERIENCE_MULTIPLIER);

	// Add to currSkill
	int curSkill = chrSkillExp + skillExp;
	
	if(DEBUG_EXPERIENCE>1) Trace("XP LOG: AddXP to skill: "+expName+" Old Skill Exp: "+chrSkillExp+" increase with: "+makeint(skillExp) +" needed for next level: "+CalculateSkillExperienceFromRank(sti(chref.skill.(expName))+1));

	int nextSkill = CalculateSkillExperienceFromRank(sti(chref.skill.(expName))+1);
	while (curSkill >= nextSkill)
	{
		LevelUp = true;
		//Substract the xp needed to level up.
		curSkill = curSkill-nextSkill;
		//Add the level
		if(GetCharacterSkill(chref, expName) >= MAX_CHARACTER_SKILL)
		{
			//We don't need any more XP on this skill
			if(sti(chref.skill.(expName).importance) > 0)
			{
				chref.skillimportancetotal = sti(chref.skillimportancetotal) - sti(chref.skill.(expName).importance);
				chref.skill.(expName).importance.old = chref.skill.(expName).importance; //we store the importance in case we need it again.
				chref.skill.(expName).importance = 0;
				if(DEBUG_EXPERIENCE>1) Trace("Importance for "+expName+" is set to 0 because skill is maxed out");
			}
		}
		else
		{
			IncreaseBaseSkill(chref, expName, 1);
			if(CheckAttribute(chref,"completeinit") && GetCharacterSkill(chref, expName)>0)
			{
				if (iRealismMode == 0 && LogsToggle >= LOG_NORMAL && IsInParty(GetMainCharacterIndex(), sti(chref.index))) // KK
				{
					if (GetAttribute(GetMainCharacter(), "location") != "Tutorial_Deck") // PB: Skip sound here
					{
						LogIt(GetMySimpleName(chref) + " " + TranslateString("","Gained") + " " + XI_ConvertString("skill_level") + " " + XI_ConvertString(expName) + " - " + GetCharacterSkill(chref, expName)));
					}
				}
			}
		}
		//Calculate next needed skill exp
		nextSkill = CalculateSkillExperienceFromRank(sti(chref.skill.(expName))+1);
		if(CheckAttribute(chref,"completeinit")) ResetEffectiveSkill(chref, expName); // PB: Update effective skills because actual number changed
	}
	//Change amount of xp on char
	chref.Experience.(expName) = curSkill;
	//If we have a specific skill increase we should call the update importance function
	UpdateSkillImportance(chref, expName, skillExp);
	if(!CheckAttribute(chref,"PreparePerks") && LevelUp)
	{
		chref.PreparePerks = true;
		PostEvent("procPreparePerks",100,"l",sti(chref.index));
	}
	if(LevelUp) ResetCharMod(chref, expName); //Reset the charmod
	return LevelUp;
}

//Old XP functions, now all redirect to the new one

int AddCharacterExpChar(ref chref, string expName, int _exp) {return makeint(AddXP(chref, expName, _exp, XP_GROUP_OFFIC));}
int AddCharacterExp(ref chref,int _exp) { return makeint(AddXP(chref, "", _exp, XP_GROUP_OFFIC)); }
void Ship_AddCharacterExpChar(ref rCharacter, string expName, int iExpQuantity) { AddXP(rCharacter, expName, iExpQuantity, XP_GROUP_OFFIC); }
int AddCharacterExpNSChar(ref chref, string expName, int _exp) { return makeint(AddXP(chref, expName, _exp, XP_GROUP_PLAYER)); }
int AddCharacterExpNS(ref chref,int _exp) { return makeint(AddXP(chref, "", _exp, XP_GROUP_OFFIC)); }
void AddPartyExpChar(ref chref, string expName, int _exp) { AddXP(chref, expName, _exp, XP_GROUP_PARTY); }
void AddPartyExp(ref chref, int _exp) { AddXP(chref, "", _exp, XP_GROUP_PARTY); }
void AddExpAndShow(ref chref, int _exp)
{
	AddXP(chref, "", _exp, XP_GROUP_OFFIC);
	LogIt("+" + _exp + XI_ConvertString("add experience"));
}

//=====================================================
//  Skill Bonus Functions
//=====================================================

void SetUpCharacterBonus(ref chr)
{
	//First we determine how many bonus skills this character will have.
	int randval,numbonus,numbskill;
	int val = rand(100);
	aref Bonus, B_Skill;
	string skillname;
	string nation = UNKNOWN_NATION;
	if (CheckAttribute(chr, "nation")) nation = chr.nation; // PB: Prevent error logs!
	numbonus = 0;
	if(val < NPC_ONE_BONUS_CHANCE) numbonus = 1;
	if(val < (NPC_ONE_BONUS_CHANCE+NPC_TWO_BONUS_CHANCE)) numbonus = 2;
	if(DEBUG_EXPERIENCE>1) Trace("XP LOG: Setup Bonusses for: "+GetMySimpleName(chr)+" with "+numbonus+" bonusses and nation = "+nation);
	int cval = 100;
	bool picked[NUM_DIFF_SKILLS];
	for(int n = 0; n < numbonus; n++)
	{
		if(nation != UNKNOWN_NATION)
		{
			//The total value of the bonus skills will always be 100 so we start with a random value under 100.
			randval = rand(cval);
			//Now we see which skill this gives us
			makearef(Bonus,SkillBonus.(nation));
			numbskill = GetAttributesNum(Bonus);
			int totval = 0;
			for(int i = 0; i < numbskill; i++)
			{
				if(picked[i] != true)
				{
					//Get the value of this skill
					B_Skill = GetAttributeN(Bonus,i);
					totval += sti(B_Skill);
					//Check if we found the right skill
					if(randval <= totval)
					{
						picked[i] = true;
						skillname = GetAttributeName(B_Skill);
						chr.skill.(skillname).bonus = 1.25;
						cval -= sti(B_Skill);
						if(DEBUG_EXPERIENCE>1) trace("XP LOG: Picked "+skillname);
						break;
					}
				}
			}
		}
		else
		{
			skillname = GetSkillName(rand(9));
			if(DEBUG_EXPERIENCE>1) trace("XP LOG: No nation set, so picked "+skillname);
			chr.skill.(skillname).bonus = 1.25;
		}
	}
	chr.bonussetup = true;
}

//This function Inits the chances for bonusses
//Each nation has specific chances. The total of the values added together should be 100, as many skills can be added
void InitBonusChances()
{
	string nation = ENGLAND;
	string skill = SKILL_SAILING;
	SkillBonus.(nation).(skill) = 65;
	skill = SKILL_LEADERSHIP;
	SkillBonus.(nation).(skill) = 35;
	
	nation = FRANCE;
	skill = SKILL_DEFENCE;
	SkillBonus.(nation).(skill) = 75;
	skill = SKILL_REPAIR;
	SkillBonus.(nation).(skill) = 25;
	
	nation = SPAIN;
	skill = SKILL_SNEAK;
	SkillBonus.(nation).(skill) = 80;
	skill = SKILL_COMMERCE;
	SkillBonus.(nation).(skill) = 20;
	
	nation = PIRATE;
	skill = SKILL_FENCING;
	SkillBonus.(nation).(skill) = 50;
	skill = SKILL_GRAPPLING;
	SkillBonus.(nation).(skill) = 50;
	
	nation = HOLLAND;
	skill = SKILL_COMMERCE;
	SkillBonus.(nation).(skill) = 80;
	skill = SKILL_SAILING;
	SkillBonus.(nation).(skill) = 20;
	
	nation = PORTUGAL;
	skill = SKILL_ACCURACY;
	SkillBonus.(nation).(skill) = 50;
	skill = SKILL_CANNONS;
	SkillBonus.(nation).(skill) = 50;
	
	nation = AMERICA;
	skill = SKILL_REPAIR;
	SkillBonus.(nation).(skill) = 70;
	skill = SKILL_LEADERSHIP;
	SkillBonus.(nation).(skill) = 30;
}

//=====================================================
//  Skill Importance Functions
//=====================================================

void UpdateSkillImportance(ref chref, string expName, int skillExp)
{
	if(GetCharacterSkill(chref, expName) >= MAX_CHARACTER_SKILL) return;
	//small bursts of experience will probably increase your importance more then one large burst.
	//At least thats what this function is aiming for.
	int nextSkill = makeint(CalculateSkillExperienceFromRank(sti(chref.skill.(expName))+1));
	//We want to know the percentage of experience we gathered for the nextskill
	//We take a random number from the skillExp to have randomization in it and favor small bursts
	float percentage = rand(skillExp) / nextSkill * 100;
	//if the percentage is over 50% we should increase the importance by default. so we multiply the percentage times 2
	//We take a random number from this percentage and see if we are lucky.
	int chance = makeint(percentage * 2);
	if(DEBUG_EXPERIENCE>1) Trace("XP LOG: chance of increasing importance: "+chance+" for skill: "+expName);
	if(rand(100)<chance)
	{
		//Very low importance should increase fast so you can level this skill easier.
		int importance = sti(chref.skill.(expName).importance);
		int inc = 0;
		if(importance < 25) inc = 3;
		if(importance < 50) inc = 1;
		if(importance < 75) inc = 2;
		if(importance < 75) inc = 3;
		chref.skill.(expName).importance = importance + inc;
		chref.skillimportancetotal = sti(chref.skillimportancetotal) + inc;
	}
	//We shouldn't add an max because when playing longer all the importances will grow. At one moment they will all be capped to the max then.
	//This way they would eventually all increase lineair.
}

//Adding skillpriorities to a character
void SetCharSkillImportance(ref chref, int SkillVariation)
{
	if(DEBUG_EXPERIENCE>1) Trace("XP LOG: add skill importance for character: "+GetMySimpleName(chref));
	//Check if there is an offictype assigned
	if(!CheckAttribute(chref,"quest.officertype"))
	{
		chref.quest.officertype = OFFIC_TYPE_CIVILIAN;
		Trace("XP ERROR: No officertype assigned to: "+GetMySimpleName(chref)+" now set to: "+chref.quest.officertype);
	}
	string offictype = chref.quest.officertype;
	//Start the loop
	ref pchar = GetMainCharacter();
	//We use the skill list in maincharacter to loop trough so we know its always accurate
	string skill;
	int importance = 0;
	int total = 0;
	for(int n = 0; n < NUM_DIFF_SKILLS; n++)
	{
		skill = GetSkillName(n);
		//Check if a level has been set already
		if(!CheckAttribute(chref,"skill."+skill)) chref.skill.(skill) = 1;
		//Get the importance for the skill
		if(CheckAttribute(OfficerTypes,offictype+".skills."+skill+".importance"))
		{
			importance = sti(OfficerTypes.(offictype).skills.(skill).importance)*IMPORTANCE_BOOST+rand(SkillVariation*10);
		}
		else
		{
			if(DEBUG_EXPERIENCE>1) Trace("XP LOG: No importance assiged to: "+skill+" for offictype: "+offictype+" so use default");
			importance = 1+rand(15)+rand(SkillVariation*10);
		}
		//When we have a bonus for the skill increase importance
		if(CheckAttribute(chref,"skill."+skill+".bonus")) 
		{
			if(stf(chref.skill.(skill).bonus) > 1)
			{
				importance += IMPORTANCE_BONUS_GAIN+rand(SkillVariation*10);
				if(DEBUG_EXPERIENCE>1) Trace("XP LOG: Bonus found so importance increased");
			}
		}
		//If the level is higher the 1 for this skill it should also get extra importance
		if(GetCharacterSkill(chref, skill) > 1)
		{
			importance += IMPORTANCE_SKILL_GAIN*GetCharacterSkill(chref, skill);
			if(DEBUG_EXPERIENCE>1) Trace("XP LOG: Character has level in skill so add importance");
		}
		if(DEBUG_EXPERIENCE>1) Trace("XP LOG:  Set skill "+skill+" to importance: "+importance+" for "+GetMySimpleName(chref));
		//Set the importance
		chref.skill.(skill).importance = importance;
		total += importance;
		//Set experience for skill in case it isn't set yet
		if(!CheckAttribute(chref,"Experience."+skill)) chref.Experience.(skill) = 0;
	}
	//Set this so we know when it's set for someone.
	chref.skillimportancetotal = total;
	chref.skillsetup = chref.quest.officerType;
}

//=====================================================
//  Perk Functions
//=====================================================

void PrepareSelectPerksForCharacter(ref chref)
{
	if(DEBUG_PERKSELECT>1) Trace("PERK SELECT: Prepare SelectPerksForCharacter for: "+GetMySimpleName(chref));
	//Let's check the different perktypes and see what our character can pick
	//We use the skill list in maincharacter to loop trough so we know its always accurate
	int numperktypes = GetAttributesNum(PerkTypes);
	aref perktype;
	int total = 0;
	int numskills = 0;
	int weight = 0;
	int sumskill = 0;
	int highest = -1;
	int hval = 0;
	string skillname, typename;
	for(int n = 0; n < numperktypes; n++)
	{
		typename = GetAttributeName(GetAttributeN(PerkTypes, n));
		makearef(perktype,PerkTypes.(typename).Skill);
		//A perktype has serveral contributing skills. They are weighted and when added together with theire
		//weighting they can be max 100. We use this number to determine which skilltype will be picked.
		sumskill = 0;
		if(!CheckAttribute(chref,"PerkTypes."+typename+".maxed")) //If we have all perks already it will have no weight anymore.
		{
			numskills = GetAttributesNum(perktype);
			for(int i = 0; i < numskills; i++)
			{
				weight = sti(GetAttributeValue(GetAttributeN(perktype, i)));
				skillname = GetAttributeName(GetAttributeN(perktype, i));
				sumskill += weight*GetCharacterSkill(chref, skillname)
			}
		}
		chref.PerkTypes.(typename) = sumskill;
		if(DEBUG_PERKSELECT>1) Trace("PERK SELECT: Perktype: "+typename+" has a score of: "+sumskill);
		total += sumskill;
		if(sumskill > hval) {highest = n; hval=sumskill;}
	}
	if(DEBUG_PERKSELECT>1) Trace("PERK SELECT: There is a total of: "+total);
	chref.PerkTypes = total;
	chref.PerkTypes.highest = highest;
}

bool SelectPerksForCharacter(ref chref, int attempts)
{
	if(sti(chref.perks.FreePoints) < 1)
	{
		if(DEBUG_PERKSELECT>1) Trace("PERK SELECT: No free point for "+GetMySimpleName(chref)+"so cancelled SelectPerksForCharacter");
		return false;
	}
	if(!CheckAttribute(chref,"PerkTypes")) PrepareSelectPerksForCharacter(chref);
	if(sti(chref.PerkTypes) <= 0) return false;
	string typename;
	int numperktypes = GetAttributesNum(PerkTypes);
	if(DEBUG_PERKSELECT>1) Trace("PERK SELECT: Called SelectPerksForCharacter for: "+GetMySimpleName(chref));
	string offictype = chref.quest.officertype;
	//First we try to add a perk to the highest PerkType
	typename = GetAttributeName(GetAttributeN(PerkTypes, sti(chref.PerkTypes.highest)));
	if(SelectPerkForType(typename, chref))
	{
		return true;
	}
	else
	{
		//Let's try again a few more times and see if we can find a nice perk.
		int rnum = 0;
		for(int n = 0; n < attempts; n++)
		{
			if(DEBUG_PERKSELECT>1) Trace("PERK SELECT: attempt "+(n+2)+" to find a perk");
			//Let's find a random perktype. By taking a random of the total and checking it agains the weights we should still
			//Take the character into account
			rnum = rand(sti(chref.PerkTypes));
			if(DEBUG_PERKSELECT>1) Trace("PERK SELECT: attempt "+(n+2)+" random number: "+rnum);
			for(int i = 0; i < numperktypes; i++)
			{
				if(sti(chref.perks.FreePoints) < 1)
				{
					if(DEBUG_PERKSELECT>1) Trace("PERK SELECT: no more freepoints left. Break the loop");
					break;
				}
				typename = GetAttributeName(GetAttributeN(PerkTypes, i));
				if(rnum < sti(chref.PerkTypes.(typename)))
				{
					if(SelectPerkForType(typename, chref)) 
					{
						return true;
					}
					break;
				}
				else
				{
					rnum -= sti(chref.PerkTypes.(typename));
				}
			}
		}
	}
	return false;
}

bool SelectPerkForType(string type, ref chref)
{
	if(DEBUG_PERKSELECT>1) Trace("PERK SELECT: called SelectPerkForType for type: "+type+" with points: "+sti(chref.perks.FreePoints));
	aref perks; makearef(perks,PerkTypes.(type).Perks);
	//Let's loop trough the perks and see if there is any we can assign.
	int numperks = GetAttributesNum(perks);
	string perkname;
	string offictype = chref.quest.officertype;
	if(type == PERK_TYPE_COMBAT) offictype = "Combat";
	int score = 0;
	int highest = -1;
	int hval = 0;
	bool lockedperks = false;
	bool nonassignable = false;
	for(int n = 0; n < numperks; n++)
	{
		perkname = GetAttributeName(GetAttributeN(perks, n));
		//We keep an score for each perk, the better the score the higher the chance it will be chose.
		if(isPerkAssignableOfficer(chref, perkname, sti(chref.perks.FreePoints)))
		{
			//A higher cost means a more interesting perk normally so if we can affort it we should take it.
			score = sti(perks.(perkname));
			//Let's check if its a contributing perk
			if(CheckAttribute(OfficerTypes,offictype+".noncontribchance"))
			{
				if(rand(100) < sti(OfficerTypes.(offictype).noncontribchance))
				{
					//The perk is allowed to be scored. Now let's see if it's an actual assigned perk for this officertype. If so we give it 1 bonus.
					if(CheckAttribute(OfficerTypes,offictype+".perks."+perkname))
					{
						score += 1;
					}
				}
			}
			else
			{
				//If there is no noncontribchance then if the perk isn't set for the offictype we wont look at it.
				if(!CheckAttribute(OfficerTypes,offictype+".perks."+perkname))
				{
					continue;
				}
			}
			//Check if the main character has the perk already unlocked
			if(CheckCharacterPerkLocked(chref, perkname))
			{
				//If the perk is locked there is a chance this will be unlocked. At level 25 all will be unlocked
				if(rand(50)<pow(sti(chref.rank),1.2))
				{
					//If the perk is unlocked this is good so we add something to the score
					score += 1;
				}
				lockedperks = true;
			}
			if(CheckAttribute(perks,perkname+".rank"))
			{
				if(sti(chref.rank) >= sti(perks.(perkname).rank))
				{
					//We passed the required rank for this perk so that makes it more important
					score += 1;
				}
			}
			if(CheckAttribute(perks,perkname+".unlocks"))
			{
				//This perk unlocks new perks so that makes it extra important
				score += 2;
			}
			if(LAi_IsBoardingProcess())
			{
				//If we are boarding, the gun perks are important because they allow the crew to handle better weapons
				if(perkname == "Gunman")
				{
					score += 3;
				}
				if(perkname == "GunProfessional" || perkname == "GunFighter")
				{
					score += 1;
				}
			}
			if(DEBUG_PERKSELECT>1) Trace("PERK SELECT: Perk: "+perkname+" is avaible and has a score of: "+score);
			if(score > highest){ highest = n; hval = score;}
		}
		else
		{
			if(DEBUG_PERKSELECT>1) trace("PERK SELECT: Perk: "+perkname+" is non assignable");
			nonassignable = true;
		}
	}
	if(score == 0 && !lockedperks && !nonassignable)
	{
		if(DEBUG_PERKSELECT>1) Trace("PERK SELECT: Perktype "+type+" is maxed out so run prepare again");
		chref.PerkTypes.(type).maxed = true;
		PrepareSelectPerksForCharacter(chref); //Run the prepare again so the new weights are calculated.
		return false;
	}
	if(highest >= 0)
	{
		int chance = 100;
		if(hval <2) chance -= 40; //If the score is only 1 we have a 50% chance of taking this perk. There might be something better or we should wait till something with more points comes along
		if(sti(chref.rank) < 10) chance -= 25; //If we are below level 10 we should have a large chance of skipping a perk because there is a large chance something better is out there.
		if(sti(chref.rank) < 20) chance -= 15; //If we are below level 20 we should have a chance of skipping a perk because there is a large chance something better is out there.
		if(type != GetAttributeName(GetAttributeN(PerkTypes, sti(chref.PerkTypes.highest)))) chance -= 35; //If this isn't the best PerkType we should have less chance of picking one.
		if(rand(100)<chance)
		{
			perkname = GetAttributeName(GetAttributeN(perks, highest));
			if(CheckCharacterPerkLocked(chref, perkname))
			{
				UnlockPerkCharacter(chref, perkname); 
				if(DEBUG_PERKSELECT>1) Trace("PERK SELECT: Unlocked perk: "+perkname+" for: "+GetMySimpleName(chref));
			}
			chref.perks.list.(perkname) = 1;
			chref.perks.FreePoints = sti(chref.perks.FreePoints) - GetPerkCost(perkname);
			DeleteAttribute(chref,"ContribList");
			if(DEBUG_PERKSELECT>1) Trace("PERK SELECT: Assigned perk: "+perkname+" with cost: "+GetPerkCost(perkname)+" to: "+GetMySimpleName(chref));
			return true;
		}
	}
	return false;
}

//=====================================================
//  Character Functions
//=====================================================

//This function will set up a complete character with everything set
void InitCharacterSkills(ref chref)
{
	if(DEBUG_EXPERIENCE>1) Trace("XP LOG: Start InitCharacterSkills for " + GetMySimpleName(chref));
	CheckCharacterSetup(chref); //First check if everything is there.
	int rank = sti(chref.rank);
	int skillrank = 1;
	if(!CheckAttribute(chref,"assignrank"))
	{
		SetCharSkillImportance(chref, 1); //Setup the importance
		skillrank = ResetSkillsandPerks(chref);
		if (!CheckAttribute(chref,"bonussetup")) SetUpCharacterBonus(chref); //Setup the bonus
		if(DEBUG_EXPERIENCE>1)trace("XP LOG: Rank Check "+GetMySimpleName(chref)+" rank: "+rank+" skillrank: "+skillrank);
		if(skillrank > rank && !CheckAttribute(chref,"IsFantom")) rank = skillrank; //Fantoms keep their assigned rank so they get the XP they need.
		if(rank < 5) rank = GetRandomRank(CharacterIsFriend(chref), chref.quest.officerType, 0); //We don't like level 1 characters that much
		if(DEBUG_POSTINIT > 1 || DEBUG_EXPERIENCE > 1)Trace("POSTINIT: rank "+rank);
	}
	else
	{
		skillrank = sti(chref.assignrank);
		rank = sti(chref.assignrank);
		if(DEBUG_POSTINIT > 1)Trace("POSTINIT: assigned rank "+rank);
	}
	if(rank>1)
	{
		if(CheckAttribute(chref,"questchar"))
		{
			if(DEBUG_POSTINIT > 1)Trace("POSTINIT: quest char");
			//Questchars always use skillrank
			chref.rank = skillrank;
			chref.Experience = CalculateExperienceFromRank(skillrank);
			//Let's give them some perks
			chref.perks.FreePoints =  skillrank * ADD_ABILITYPOINTS_PERLEVEL;
			for(int n = 0; n < skillrank; n++)
			{
				SelectPerksForCharacter(chref, rand(1));
			}
			FinishCharInit(chref);
		}
		else
		{
			bool dopost = false;
			if(AllowCharacterPostInit() && rank < POSTINIT_MAX_ALLOW_LEVEL_POST && !CheckAttribute(chref, "skipPostInit")) // PB: Allow skipping PostInit process
			{
				dopost = true;
			}
			if(dopost) dopost = AddToPostInitQueue(chref, rank);
			if(!dopost)
			{
				if(DEBUG_POSTINIT > 1)Trace("POSTINIT: do normal init");
				AddXPtoChar(chref, "", CalculateExperienceFromRank(rank)); //Bypassing multipliers and shared experience
				FinishCharInit(chref);
			}
		}
	}
}

//This function finishes the character setup process
void FinishCharInit(ref chr)
{
	if(DEBUG_EXPERIENCE>1 || DEBUG_POSTINIT > 1) trace("XP LOG: Finish character init for " + GetMySimpleName(chr));
	//Try to select another perk to compensate for the lack of try during init
	PostEvent("procSelectPerksForCharacter",1,"lls",sti(chr.index),2,chr.location);
	//Set the skills right
	ResetSkillModifierAll(chr); // PB: was ResetEffectiveSkillAll
	//Set the HP right
	ResetHP(chr); // PB: was ResetMaxHP
	//Equip things if not done yet
	ExecuteCharacterEquip(chr);
	//Set an officerprice
	if(!CheckAttribute(chr,"quest.NoRaise"))
	{
		chr.quest.OfficerPrice = GetBaseOfficerPrice(chr) -10 + rand(20); //A little randomization
	}
	if(DEBUG_OFFICERPRICE > 1) trace("OFFICERPRICE set to: "+chr.quest.OfficerPrice+" for "+GetMySimpleName(chr));
	chr.completeinit = true;
	DeleteAttribute(chr, "skipPostInit"); // PB: Init finished, time to remove this
}

//This function checks all kinds of things in the character and if it isn't right it will set it up.
//TODO: Merge this with an other check function which is called earlier in the process (during create character)
void CheckCharacterSetup(ref chref)
{
	if (!CheckAttribute(chref,"id")) {chref.id = "without_id"; }
	if (!CheckAttribute(chref,"Experience")) {chref.Experience = 1; }
	if (!CheckAttribute(chref,"perks.FreePoints")){chref.perks.FreePoints = 1; }
	if (!CheckAttribute(chref,"skill.freeskill")){chref.skill.freeskill = 0; }
	if (!CheckAttribute(chref,"quest.officertype") || GetAttribute(chref,"quest.officertype") == "combat")
	{
		if(GetAttribute(chref,"isOfficer") == 1)
		{
			chref.quest.officertype = GetRandomOfficerType();
		}
		else
		{
			if(GetAttribute(chref,"issoldier") == 1)
			{
				chref.quest.officertype = OFFIC_TYPE_GUARD;
			}
			else
			{
				if(GetAttribute(chref,"isMerchant") == 1)
				{
					chref.quest.officertype = OFFIC_TYPE_SHOPKEEPER;
				}
				else
				{
					if(GetAttribute(chref,"isWarrior") == 1)
					{
						chref.quest.officertype = GetRandomEnemyType();
					}
					else
					{
						if (CheckAttribute(chref, "model"))	chref.quest.officertype = FindRandomModelOfficerType(chref.model);	// PB: Assign officer type based on model
						else								chref.quest.officertype = OFFIC_TYPE_CIVILIAN;						// Default if model is missing
					}
				}
			}
		}
	}
	if (CharacterHasShip(chref)) chref.quest.officerType = GetCaptainType(chref);
	if (!CheckAttribute(chref,"rank")) {chref.rank = 1; }
	if (!CheckAttribute(chref,"quest.officerprice") && !IsMainCharacter(chref)) chref.quest.officerprice = 0;
	if (!CheckAttribute(chref,"Money")) {
		chref.Money = GetRandCharMoney(chref, makeint(Rand(8)+2)); //Levis: Reduced amount of money characters carry
//	} else { // PB: Commented out, because zero money may be intentional!
//		if (sti(chref.Money) == 0) chref.Money = GetRandCharMoney(chref, makeint(Rand(8)+2));
	}
	//Checks for leaving officers
	if (!CheckAttribute(chref,"questchar") && !CheckAttribute(chref,"loyality"))
	{
		chref.loyality = 5+rand(15);
	}
	if (!CheckAttribute(chref,"questchar") && !CheckAttribute(chref,"alignment"))
	{
		if(rand(1)==1) chref.alignment = "good";
		else chref.alignment = "bad";
	}
	if (!CheckAttribute(chref,"questchar") && !CheckAttribute(chref,"reputation"))
	{
		chref.reputation = rand(20) + rand(20) + rand(20) + rand(20) + 5;	// If reputation not already set, this should give a random number between 5 and 85, biased towards average of 45 i.e. neutral
	}
	if (!CheckAttribute(chref,"homelocation")) 
	{
		int loc = FindLocation(chref.location);
		bool set = false;
		if(loc > -1)
		{
			if(GetAttribute(Locations[loc],"type") == "tavern")
			{
				chref.homelocation = "";
				chref.homelocation.group = "";
				chref.homelocation.locator = "";
				chref.homestate = "";
				set = true;
			}
		}
		if(!set)
		{
			chref.homelocation = chref.location; // PB: was alignment???
			chref.homelocation.group = chref.location.group;
			chref.homelocation.locator = chref.location.locator;
			if(CheckAttribute(chref,"chr_ai.type")) chref.homestate = chref.chr_ai.type;
			else chref.homestate = "citizen";
		}
	}
	SetBaseShipData(chref); // PB: Not sure if this serves any purpose here, but it gets aborted if already done
}

int ResetSkillsandPerks(ref chref)
{
	//Reset the Character to level 1
	if(DEBUG_EXPERIENCE>1) trace("XP LOG: Character "+GetMySimpleName(chref)+" has been reset to 0"); //Show these always
	string skill;
	int skillrank = 0;
	for(int n = 0; n < NUM_DIFF_SKILLS; n++)
	{
		skill = GetSkillName(n);
		skillrank += (sti(chref.skill.(skill))-1);
		if(!CheckAttribute(chref,"questchar")) //Don't reset skills for questchars
		{
			chref.skill.(skill) = 1;
			chref.skill.(skill).bonus = 1.0;
		}
	}
	if(!CheckAttribute(chref,"quest.NoRaise")) chref.officerprice = 0;
	chref.Experience = 0;
	ResetHP(chref);
	DeleteAttribute(chref,"perks");
	DeleteAttribute(chref,"ContribList");
	DeleteAttribute(chref,"bonussetup");
	chref.rank = 1;
	chref.perks.FreePoints = 1;
	chref.skill.freeskill = 0;
	skillrank = makeint(skillrank/ADD_SKILLPOINTS_PERLEVEL);
	if (skillrank < 1) skillrank = 1; // PB: Fix to prevent negative character levels
	return skillrank;
}

//=====================================================
//  HP Functions
//=====================================================

float ResetHP(ref chr)
{
	if(CheckAttribute(chr,"old.chr_ai.hp"))
	{
		DeleteAttribute(chr,"old.chr_ai.hp");
		DeleteAttribute(chr,"old.chr_ai.hp_max");
	}
	ResetMaxHP(chr);
	float HP = stf(chr.chr_ai.hp_max);
	chr.chr_ai.hp = HP;
	return HP;
}

float ResetMaxHP(ref chr)
{
	float HP = CHAR_START_HITPOINTS;
	if(!CheckAttribute(chr,"old.chr_ai.hp"))
	{
		//First let's save the percentage of HP we have at the moment.
		float HPper = 1;
		if(CheckAttribute(chr,"chr_ai.hp") && CheckAttribute(chr,"chr_ai.hp_max")) HPper = stf(chr.chr_ai.hp)/stf(chr.chr_ai.hp_max);
		int type = 0;
		int PlayerHPperLevel = CHAR_HITPOINTS_PER_LEVEL;
		float level = makefloat(GetLevel(&chr));
		if(!CheckAttribute(chr,"FakeLevels")) chr.FakeLevels = 0; //Levis
		level = level + sti(chr.FakeLevels); //Levis
		if(CheckAttribute(chr, "HPBonus")) HP += stf(chr.HPBonus);
		HP += GetHPBaseBonusOT(chr);
		//For now friendly and not friendly are the same, might change later.
		if(CharacterIsFriend(chr))
		{
			//Friendly
			PlayerHPperLevel = (PlayerHPperLevel+1)-GetDifficulty()+GetHPLevelBonusOT(chr);
		}
		else
		{
			//Not Friendly
			PlayerHPperLevel = (PlayerHPperLevel)-(4-GetDifficulty())+GetHPLevelBonusOT(chr);
		}
		HP += (level-1) * PlayerHPperLevel;
		if(IsCharacterPerkOn(chr, "Toughness"))
		{
			HP = HP * 1.1;			// 10% health bonus for the tough guys
			chr.chr_ai.hp_dlt = LAI_DEFAULT_DLTHP * TOUGHNESS_REGEN_MULT; // higher regeneration rate, default is 0.1 - LDH 14Apr09
		}
		if(CheckAttribute(chr,"chr_ai.hpchecker")) //Check if there is an hpchecker, if so we need to change that too
		{
			float diff = stf(chr.chr_ai.hp_max) - stf(chr.chr_ai.hpchecker);
			if((HP - diff) < 20) //Check if we are below 20 (to have some margin)
			{
				chr.chr_ai.hpchecker = 20;
			}
			else
			{
				chr.chr_ai.hpchecker = HP - diff;
			}
		}
		if(HP < 20) //Incase a very large negative modification is applied
		{
			HP = 20;
		}
		chr.chr_ai.hp_max = HP;
		//Apply the percentage again to the new HP (if we have any change)
		chr.chr_ai.hp = HP * HPper;
	}
	else
	{
		HP = stf(chr.chr_ai.hp_max);
	}
	return HP;
}

int ChangeHPBonus(ref chr, int offset)
{
	if(CheckAttribute(chr, "HPBonus")) offset += sti(chr.HPBonus);
/*	if(offset > sti(chr.chr_ai.hp_max)) //Never have a HPbonus larger then the max HP - PB: Why not?
	{
		offset = sti(chr.chr_ai.hp_max) - 1;
	}*/
	chr.HPBonus = offset;
	ResetMaxHP(chr); // PB: Make sure the HP is updated to take into account the new bonus
	return sti(offset);
}

//=====================================================
//  POST-INIT Functions
//=====================================================

//All characters are first added to a queue, from there they are processed in runtime. This functions adds the character to a layer. The higher the layer the later the character will be processed
bool AddToPostInitQueue(ref chr, int rank)
{
	if(DEBUG_POSTINIT > 1)Trace("POSTINIT: try to add "+GetMySimpleName(chr)+" to queue with rank "+rank);
	if(GetAttribute(PostInitQueue,"active")==true) StopPostInitChars();
	float x,y,z,gx,gy,gz,dist;
	GetCharacterPos(GetMainCharacter(),&x,&y,&z);
	GetCharacterPos(chr,&gx,&gy,&gz);
	string idx = chr.index;
	dist = sqrt(sqr(x - gx) + sqr(y - gy) + sqr(z - gz));
	//For each 20 we make a new layer.
	int layer = makeint(dist/10.0);
	if(layer == 0)
	{
		if(DEBUG_POSTINIT > 1)Trace("POSTINIT: character too close, do normal init ");
		return false;
	}
	else
	{
		chr.assignrank = rank; //store the rank in the character in case it isn't completly processed before exiting the location
		string layername = "layer"+layer;
		PostInitQueue.Characters.list.(layername).(idx).distance = dist;
		PostInitQueue.Characters.list.(layername).(idx).rank = rank;
		PostInitQueue.Characters.amount = GetAmountInPostInitQueue() + 1;
		if(sti(GetAttribute(PostInitQueue,"MaxLayer")) < layer) PostInitQueue.MaxLayer = layer;
		if(DEBUG_POSTINIT > 1)Trace("POSTINIT: added to queue");		
	}
	return true;
}

int GetAmountInPostInitQueue()
{
	if(!CheckAttribute(PostInitQueue,"Characters.amount")) return 0;
	return sti(PostInitQueue.Characters.amount);
}

void StartPostInitChars()
{
	if(DEBUG_POSTINIT > 1)Trace("POSTINIT: start post init event");
	DeleteAttribute(&PostInitQueue,"paused"); //Levis: incase it was still paused
	PostInitQueue.active = true;
	PostInitQueue.active.layer = 0;
	PostInitQueue.active.character = 0;
	PostInitQueue.active.piece = 0;
	PostEvent("PostInitChars",1000);
	PostInitActive = true;
}

void PausePostInit()
{
	if(DEBUG_POSTINIT > 1)Trace("POSTINIT: pause post init event");
	PostInitQueue.active = false;
	PostInitQueue.paused = true;
}

void ResumePostInit()
{
	if(DEBUG_POSTINIT > 1)Trace("POSTINIT: resume post init event");
	DeleteAttribute(&PostInitQueue,"paused");
	PostInitQueue.active = true;
	//Restore Events
	if(CheckAttribute(PostInitQueue,"restorelist"))
	{
		aref chars; makearef(chars,PostInitQueue.restorelist);
		ref chref;
		int numchars = GetAttributesNum(chars);
		for(int n = 0; n < numchars; n++)
		{
			chref = GetCharacter(sti(GetAttributeName(GetAttributeN(chars, n))));
			RestoreCharacterEvents(chref);
		}
	}
	DeleteAttribute(&PostInitQueue,"restorelist");
	PostEvent("PostInitChars",1);
}

void PostInitChars()
{
	if(DEBUG_POSTINIT > 1)Trace("POSTINIT: eventcall"); 
	if(GetAttribute(PostInitQueue,"active")==true)
	{
		int curlayer = sti(PostInitQueue.active.layer);
		int curchr = sti(PostInitQueue.active.character);
		int curpiece = sti(PostInitQueue.active.piece);
		string curlayername = "layer"+curlayer;
		aref layer; makearef(layer,PostInitQueue.Characters.list.(curlayername));
		if(GetAttributesNum(layer) > 0 && GetAttributesNum(layer) > sti(PostInitQueue.active.character))
		{
			aref Character = GetAttributeN(layer,curchr);
			ref chr = GetCharacter(sti(GetAttributeName(Character)));
			if(DEBUG_POSTINIT > 1)Trace("POSTINIT: character "+GetMySimpleName(chr)+" id "+chr.id); 
			if(!CheckAttribute(chr,"rank"))
			{
				CheckCharacterSetup(chr); //This shouldn't happen but it seems somewhere between adding it to post init and doing it the rank gets removed sometimes???
				trace("XP ERROR: Character "+GetMySimpleName(chr)+" was missing rank during post init");
				DumpAttributes(chr);
			}
			if(sti(GetAttribute(Character,"rank"))>0)
			{
				int addlevel = POSTINIT_AMOUNT_LEVELS;
				if(addlevel > sti(Character.rank)) addlevel = sti(Character.rank);
				int exp = makeint((CalculateExperienceFromRank(sti(chr.rank)+addlevel) - sti(chr.experience))/(POSTINIT_AMOUNT_PIECES-curpiece));
				if(AddXPtoChar(chr, "", exp))
				{
					Character.rank = sti(Character.rank)-addlevel;
					PostInitQueue.active.piece = 0;
				}
				else
				{
					PostInitQueue.active.piece = curpiece + 1;
				}
			}
			else
			{
				FinishCharInit(chr);
				PostInitQueue.active.character = curchr + 1;
			}
		}
		else
		{
			if(DEBUG_POSTINIT > 1)TraceandLog("POSTINIT: Layer "+curlayer+" finished!"); 
			PostInitQueue.active.layer = curlayer+1;
			PostInitQueue.active.character = 0;
			if((curlayer+1) > sti(GetAttribute(PostInitQueue,"MaxLayer")))
			{
				if(DEBUG_POSTINIT > 1)Trace("POSTINIT: reached max layer"); 
				StopPostInitChars();
			}
		}
		PostEvent("PostInitChars",1);
	}
}

void StopPostInitChars()
{
	if(DEBUG_POSTINIT > 1)TraceandLog("POSTINIT: Stop postinit event"); 
	PostInitQueue.active = false;
	PostInitQueue.MaxLayer = 0;
	PostInitQueue.Characters.amount = 0;
	aref Characters; makearef(Characters,PostInitQueue.Characters);
	DeleteAttribute(Characters,"list");
	if(DEBUG_POSTINIT>1) DumpAttributes(PostInitQueue);
	PostInitActive = false;
}

//This returns if post init is allowed or not
bool AllowCharacterPostInit()
{
	if(LAi_IsBoardingProcess()) return false;
	if(GetAttribute(PostInitQueue,"allowed") == false) return false;
	return true;
}

//Use this to enable the use of post init when a character is created
void SetCharacterPostInit(bool state)
{
	if(DEBUG_POSTINIT > 1)Trace("POSTINIT: state is "+state);
	PostInitQueue.allowed = state;
}

void RestoreCharacterEvents(ref chref)
{
	int i;
	if(!CheckAttribute(chref,"postevent")) return;
	if(DEBUG_POSTINIT > 1)Trace("POSTINIT: restore events for "+GetMySimpleName(chref));
	//Restore the perk picking
	if(CheckAttribute(chref,"postevent.perks"))
	{
		if(DEBUG_POSTINIT > 1)Trace("POSTINIT: restore perk picks for "+GetMySimpleName(chref));
		for(i = 0; i < sti(chref.postevent.perks); i++)
		{
			SelectPerksForCharacter(chref, 1);
		}
	}
	//Restore the skills xp assignment
	if(CheckAttribute(chref,"postevent.skills"))
	{
		for(i = 0; i < NUM_DIFF_SKILLS; i++)
		{
			string skillname = GetSkillName(i);
			if(CheckAttribute(chref,"postevent.skills."+skillname))
			{
				if(DEBUG_POSTINIT > 1)Trace("POSTINIT: restore skill XP for skill "+skillname+" for "+GetMySimpleName(chref));
				AddXPtoSkillsMain(chref, skillname, sti(chref.postevent.skills.(skillname)));
			}
		}
		if(CheckAttribute(chref,"postevent.skills.all"))
		{
			if(DEBUG_POSTINIT > 1)Trace("POSTINIT: restore skill XP for all skill for "+GetMySimpleName(chref));
			AddXPtoSkillsMain(chref, "", sti(chref.postevent.skills.all));
		}
	}
	//Added by Levis for smuggling
	if(CheckAttribute(chref,"postevent.CheckCoastGuard"))
	{
		//Trace("EVENTS: restore coastguard check event");
		StartCoastGuardCheck();
	}
	if(CheckAttribute(chref,"postevent.checkbuildings"))
	{
		aref locs; makearef(locs,chref.postevent.checkbuildings);
		for(i=0;i<GetAttributesNum(locs);i++)
		{
			string loc = GetAttributeName(GetAttributeN(locs,i));
			//Trace("EVENTS: restore blockade check event for location "+loc);
			StartBlockadeCheck(loc);
		}
	}
	DeleteAttribute(chref,"postevent");
}

void procAddXP()
{
	int cidx = GetEventData();
	string expName = GetEventData();
	int _exp = GetEventData();
	string group = GetEventData();
	string location = GetEventData();
	ref chref = GetCharacter(cidx);
	ref pchar = GetMainCharacter();
	if(IsCompanionOfficer(pchar, chref)) location = pchar.location; //So characters on other ships owned by pchar will be updated instantly also
	if(location == pchar.location)
	{
		if(DEBUG_EXPERIENCE > 0 || DEBUG_POSTINIT > 0)trace("XP LOG: Event for addXP triggered for "+GetMySimpleName(chref));
		AddXP(chref, expName, _exp, group);
	}
}

void procAddXPtoSkillsMain()
{
	//Event to call the function in post init to speed things up
	int cidx = GetEventData();
	string expName = GetEventData();
	int skillExp = GetEventData();
	string location = GetEventData();
	if(cidx < 0) return;
	ref pchar = GetMainCharacter();
	ref chref = GetCharacter(cidx);
	if(IsCompanionOfficer(pchar, chref)) location = pchar.location; //So characters on other ships owned by pchar will be updated instantly also
	if(!CheckAttribute(PostInitQueue,"paused") && location == pchar.location)
	{
		if(DEBUG_EXPERIENCE > 0 || DEBUG_POSTINIT > 0)trace("XP LOG: Event for skills "+expName+" ("+skillExp+") triggered for "+GetMySimpleName(chref));
		AddXPtoSkillsMain(chref, expName, skillExp);
	}
	else
	{
		//Store the event so we can call it agian when resumed
		if(DEBUG_EXPERIENCE > 0 || DEBUG_POSTINIT > 0)trace("XP LOG: Store event for skill "+expName+" for "+GetMySimpleName(chref));
		int skillvalue = skillExp;
		if(expName == "") expName = "all";
		if(CheckAttribute(chref,"postevent.skills."+expName)) skillvalue += sti(chref.postevent.skills.(expName));
		chref.postevent.skills.(expName) = skillvalue;
		string idx = chref.index;
		PostInitQueue.restorelist.(idx) = true;
	}
}

void procSelectPerksForCharacter()
{
	//Event to call the function in post init to speed things up
	int cidx = GetEventData();
	int attempts = GetEventData();
	string location = GetEventData();
	if(cidx < 0) return;
	ref pchar = GetMainCharacter();
	ref chref = GetCharacter(cidx);
	if(IsCompanionOfficer(pchar, chref)) location = pchar.location; //So characters on other ships owned by pchar will be updated instantly also
	if(!CheckAttribute(PostInitQueue,"paused") && location == pchar.location)
	{
		if(DEBUG_PERKSELECT > 0 || DEBUG_POSTINIT > 0)trace("PERK SELECT: Event triggered for "+GetMySimpleName(chref));
		SelectPerksForCharacter(chref, attempts);
	}
	else
	{
		//Store the event so we can call it agian when resumed
		if(DEBUG_PERKSELECT > 0 || DEBUG_POSTINIT > 0)trace("PERK SELECT: Store Event for "+GetMySimpleName(chref));
		int perkvalue = 1;
		if(CheckAttribute(chref,"postevent.perks")) perkvalue += sti(chref.postevent.perks);
		chref.postevent.perks = perkvalue;
		string idx = chref.index;
		PostInitQueue.restorelist.(idx) = true;
	}
}

void ProcPreparePerks()
{
	int idx = GetEventData();
	ref chref = GetCharacter(idx);
	if(DEBUG_PERKSELECT > 0 || DEBUG_POSTINIT > 0)trace("PERK SELECT: Event prepareperks triggered for "+GetMySimpleName(chref));
	PrepareSelectPerksForCharacter(chref);
	DeleteAttribute(&chref,"PreparePerks");
}

//=====================================================
//  Calculate Functions
//=====================================================

int CalculateExperienceFromRank(int _Rank)
{
	if(_Rank < 1) return 0;
	return makeint(1200*pow((_Rank-1),2)+100*(_Rank-1)+800*pow(2.75,sqrt(_Rank-1)));
}

int CalculateSkillExperienceFromRank(int rank)
{
	//makeint(((CalculateExperienceFromRank(rank)-CalculateExperienceFromRank(rank-1))*SKILL_NEXT_XP_MULT) / ADD_SKILLPOINTS_PERLEVEL
	int maxexp = CalculateExperienceFromRank(makeint((MAX_CHARACTER_SKILL * NUM_DIFF_SKILLS) / ADD_SKILLPOINTS_PERLEVEL)); //Take the XP needed for level all skillpoints are used
	//We have NUM_DIFF_SKILLS skills each going to MAX_CHARACTER_SKILL. We need to know how !MAX_CHARACTER_SKILL, so use a for-loop.
	int amskills = 0;
	for(int n = 1; n < MAX_CHARACTER_SKILL; n++) {amskills += pow(n,2);}
	return makeint((maxexp/NUM_DIFF_SKILLS) / amskills * pow((rank-1),2));
}

int GetTotalRank(ref chr)
{
	int charRank = sti(chr.rank);
	if(CheckAttribute(chr, "FakeLevels")) charRank += sti(chr.FakeLevels);
	return charRank;
}

//=====================================================
//  Lookup Functions
//=====================================================

//Get xp multiplier for different skills
float GetXPmult(string Skillname)
{
	float expMult = 1;
	switch (Skillname)
	{
		case "Leadership":	expMult =  2.5 ; break;
		case "Fencing":		expMult =  1.75; break;
		case "Sailing":		expMult =  0.8 ; break;
		case "Accuracy":	expMult =  1.25; break;
		case "Cannons":		expMult =  0.4 ; break;
		case "Repair":		expMult = 50   ; break;
		case "Defence":		expMult =  1.5 ; break;
		case "Sneak":		expMult =  1.5 ; break;
		case "Grappling":	expMult =  3   ; break;
		case "Commerce": 	expMult =  0.50; break;
	}
	return expMult*EXPERIENCE_MULTIPLIER;
}

// skill and expirence service
string GetSkillName(int _SkillType)
{
	switch(_SkillType)
	{
		case 0:		return SKILL_LEADERSHIP;	break;
		case 1:		return SKILL_FENCING;		break;
		case 2:		return SKILL_SAILING;		break;
		case 3:		return SKILL_ACCURACY;		break;
		case 4:		return SKILL_CANNONS;		break;
		case 5:		return SKILL_GRAPPLING;		break;
		case 6:		return SKILL_REPAIR;		break;
		case 7:		return SKILL_DEFENCE;		break;
		case 8:		return SKILL_COMMERCE;		break;
		case 9:		return SKILL_SNEAK;			break;
	}
	return "";
}