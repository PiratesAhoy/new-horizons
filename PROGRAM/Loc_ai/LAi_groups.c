

//An object that describes otnoscheniya one group to another
object LAi_grp_relations;
float LAi_grp_playeralarm = 0.0; // KK
bool LAi_grp_alarmactive = false;

//------------------------------------------------------------------------------------------
//Initialize
//------------------------------------------------------------------------------------------

//Initialize
bool LAi_group_Init()
{
	//While everything is calm
	LAi_grp_playeralarm = 0.0;
	LAi_grp_alarmactive = false;
	//Create groups and load parameters
	if(CreateEntity(&LAi_grp_relations, "CharactersGroups") == 0) return false;
	//Initialize the standard group of characters
	LAi_group_Register(LAI_DEFAULT_GROUP);
	//Group Team
	LAi_group_Register(LAI_GROUP_PLAYER);
	LAi_group_SetLookRadius(LAI_GROUP_PLAYER, LAI_GROUP_PLA_LOOK);
	LAi_group_SetHearRadius(LAI_GROUP_PLAYER, LAI_GROUP_PLA_HEAR);
	LAi_group_SetSayRadius(LAI_GROUP_PLAYER, LAI_GROUP_PLA_SAY);
	LAi_group_SetPriority(LAI_GROUP_PLAYER, LAI_GROUP_PPLAYER);
	//Group ohranika
	LAi_group_Register(LAI_GROUP_GUARDS);
	LAi_group_SetLookRadius(LAI_GROUP_GUARDS, LAI_GROUP_GRD_LOOK);
	LAi_group_SetHearRadius(LAI_GROUP_GUARDS, LAI_GROUP_GRD_HEAR);
	LAi_group_SetSayRadius(LAI_GROUP_GUARDS, LAI_GROUP_GRD_SAY);
	LAi_group_SetPriority(LAI_GROUP_PLAYER, LAI_GROUP_PGUARDS);
	// KK: Patrol
	LAi_group_Register(LAI_GROUP_PATROL);
	LAi_group_SetLookRadius(LAI_GROUP_PATROL, LAI_GROUP_PTR_LOOK);
	LAi_group_SetHearRadius(LAI_GROUP_PATROL, LAI_GROUP_PTR_HEAR);
	LAi_group_SetSayRadius(LAI_GROUP_PATROL, LAI_GROUP_PTR_SAY);
	LAi_group_SetPriority(LAI_GROUP_PLAYER, LAI_GROUP_PGUARDS);
	//The group of actors
	LAi_group_Register(LAI_GROUP_ACTOR);
	LAi_group_SetLookRadius(LAI_GROUP_ACTOR, LAI_GROUP_ACT_LOOK);
	LAi_group_SetHearRadius(LAI_GROUP_ACTOR, LAI_GROUP_ACT_HEAR);
	LAi_group_SetSayRadius(LAI_GROUP_ACTOR, LAI_GROUP_ACT_SAY);
	LAi_group_SetPriority(LAI_GROUP_PLAYER, LAI_GROUP_PDEFAULT);
	//Group of the Governor
	LAi_group_Register(LAI_GROUP_HUBER);
	LAi_group_SetLookRadius(LAI_GROUP_HUBER, LAI_GROUP_HUB_LOOK);
	LAi_group_SetHearRadius(LAI_GROUP_HUBER, LAI_GROUP_HUB_HEAR);
	LAi_group_SetSayRadius(LAI_GROUP_HUBER, LAI_GROUP_HUB_SAY);
	LAi_group_SetPriority(LAI_GROUP_PLAYER, LAI_GROUP_PCITIZENS);
	//Group of monsters
	LAi_group_Register(LAI_GROUP_MONSTERS);
	LAi_group_SetRelation(LAI_GROUP_MONSTERS, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	LAi_group_SetLookRadius(LAI_GROUP_MONSTERS, LAI_GROUP_MNS_LOOK);
	LAi_group_SetHearRadius(LAI_GROUP_MONSTERS, LAI_GROUP_MNS_HEAR);
	LAi_group_SetSayRadius(LAI_GROUP_MONSTERS, LAI_GROUP_MNS_SAY);
	LAi_group_SetPriority(LAI_GROUP_PLAYER, 0);
	//Relationship
	//Guards
	LAi_group_SetRelation(LAI_GROUP_GUARDS, LAI_DEFAULT_GROUP, LAI_GROUP_FRIEND);
	LAi_group_SetAlarmReaction(LAI_GROUP_GUARDS, LAI_DEFAULT_GROUP, LAI_GROUP_FRIEND, LAI_GROUP_FRIEND);
	LAi_group_SetRelation(LAI_GROUP_GUARDS, LAI_GROUP_PATROL, LAI_GROUP_FRIEND); // KK
	LAi_group_SetAlarmReaction(LAI_GROUP_GUARDS, LAI_GROUP_PATROL, LAI_GROUP_FRIEND, LAI_GROUP_FRIEND); // KK
	LAi_group_SetRelation(LAI_GROUP_GUARDS, LAI_GROUP_HUBER, LAI_GROUP_FRIEND);
	LAi_group_SetAlarmReaction(LAI_GROUP_GUARDS, LAI_GROUP_HUBER, LAI_GROUP_FRIEND, LAI_GROUP_FRIEND);
	//Huber
	LAi_group_SetRelation(LAI_GROUP_HUBER, LAI_DEFAULT_GROUP, LAI_GROUP_FRIEND);
	LAi_group_SetAlarmReaction(LAI_GROUP_HUBER, LAI_DEFAULT_GROUP, LAI_GROUP_FRIEND, LAI_GROUP_FRIEND);
	//Actor
	LAi_group_SetRelation(LAI_GROUP_ACTOR, LAI_DEFAULT_GROUP, LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation(LAI_GROUP_ACTOR, LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);
	LAi_group_SetRelation(LAI_GROUP_ACTOR, LAI_GROUP_HUBER, LAI_GROUP_NEUTRAL);
	LAi_group_SetAlarmReaction(LAI_GROUP_ACTOR, LAI_DEFAULT_GROUP, LAI_GROUP_NEUTRAL, LAI_GROUP_NEUTRAL);
	LAi_group_SetAlarmReaction(LAI_GROUP_ACTOR, LAI_GROUP_GUARDS, LAI_GROUP_NEUTRAL, LAI_GROUP_NEUTRAL);
	LAi_group_SetAlarmReaction(LAI_GROUP_ACTOR, LAI_GROUP_PATROL, LAI_GROUP_NEUTRAL, LAI_GROUP_NEUTRAL); // KK
	LAi_group_SetAlarmReaction(LAI_GROUP_ACTOR, LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL, LAI_GROUP_NEUTRAL);
	LAi_group_SetAlarmReaction(LAI_GROUP_ACTOR, LAI_GROUP_HUBER, LAI_GROUP_NEUTRAL, LAI_GROUP_NEUTRAL);
	//Player
	LAi_group_SetRelation(LAI_GROUP_PLAYER, LAI_DEFAULT_GROUP, LAI_GROUP_NEUTRAL);
	LAi_group_SetAlarmReaction(LAI_GROUP_PLAYER, LAI_DEFAULT_GROUP, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL);
	LAi_group_SetAlarmReaction(LAI_GROUP_PLAYER, LAI_GROUP_GUARDS, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
	LAi_group_SetAlarmReaction(LAI_GROUP_PLAYER, LAI_GROUP_PATROL, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND); // KK
	LAi_group_SetAlarmReaction(LAI_GROUP_PLAYER, LAI_GROUP_HUBER, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL);
	//Restore relations
	SendMessage(&LAi_grp_relations, "s", "LoadDataRelations");
	//We take into account the time elapsed
	if(LAi_restoreStates)
	{
		SendMessage(&LAi_grp_relations, "s", "RestoreStates");
	}
	return true;
}

//Free resources
void LAi_group_Release()
{
	DeleteAttribute(&LAi_grp_relations, "quests");
	LAi_group_ClearAllTargets();
	SendMessage(&LAi_grp_relations, "s", "SaveData");
	//Remove the object groups
	DeleteClass(&LAi_grp_relations);
}

void LAi_group_SaveInfo()
{
	SendMessage(&LAi_grp_relations, "s", "SaveData");
}

//------------------------------------------------------------------------------------------
//Register the new group, setting the general parameters
//------------------------------------------------------------------------------------------

//Register a new group
void LAi_group_Register(string groupName)
{
	SendMessage(&LAi_grp_relations, "ss", "RegistryGroup", groupName);
	LAi_group_SetLookRadius(groupName, LAI_GROUP_DEF_LOOK);
	LAi_group_SetHearRadius(groupName, LAI_GROUP_DEF_HEAR);
	LAi_group_SetSayRadius(groupName, LAI_GROUP_DEF_SAY);
}

//Set the radius of visibility for the group
void LAi_group_SetLookRadius(string groupName, float radius)
{
	SendMessage(&LAi_grp_relations, "ssf", "SetGroupLook", groupName, radius);
}

//Set the range for the group of hearing
void LAi_group_SetHearRadius(string groupName, float radius)
{
	SendMessage(&LAi_grp_relations, "ssf", "SetGroupHear", groupName, radius);
}

//Set the range for the group of messages
void LAi_group_SetSayRadius(string groupName, float radius)
{
	SendMessage(&LAi_grp_relations, "ssf", "SetGroupSay", groupName, radius);
}

//Set the priority for the group
void LAi_group_SetPriority(string groupName, int priority)
{
	SendMessage(&LAi_grp_relations, "ssl", "SetGroupPriority", groupName, priority);
}

//Set the alarm level 0..1
void LAi_group_SetAlarm(string group1, string group2, float level)
{
	SendMessage(&LAi_grp_relations, "sssf", "SetAlarm", group1, group2, level);
}

//Set the rate of decay of an alarm unit /s
void LAi_group_SetAlarmDown(string group1, string group2, float down)
{
	SendMessage(&LAi_grp_relations, "sssf", "SetAlarmDown", group1, group2, down);
}


//------------------------------------------------------------------------------------------
//Move the character in the group
//------------------------------------------------------------------------------------------

//Move the character to a new group
void LAi_group_MoveCharacter(aref chr, string groupName)
{
	if (CheckAttribute(chr, "chr_ai.group")) chr.old.chr_ai.group = chr.chr_ai.group; // KK
	chr.chr_ai.group = groupName;
	SendMessage(&LAi_grp_relations, "sis", "MoveChr", chr, groupName);
}

//------------------------------------------------------------------------------------------
//Relationship groups
//------------------------------------------------------------------------------------------

//Set the relationship between the two groups
void LAi_group_SetRelation(string group1, string group2, string curRelation)
{
	SendMessage(&LAi_grp_relations, "ssss", "SetRelation", group1, group2, curRelation);
}

//Set the relationship between the groups when an alarm is triggered and after
void LAi_group_SetAlarmReaction(string group1, string group2, string actRelation, string relRelation)
{
	SendMessage(&LAi_grp_relations, "sssss", "SetAlarmReaction", group1, group2, actRelation, relRelation);
}

//Set on each other 2 groups
void LAi_group_FightGroups(string group1, string group2, bool asignWarriorType)
{
	LAi_group_FightGroupsEx(group1, group2, asignWarriorType, -1, -1, true, false);
}

//Set on each other 2 groups, with the possible installation of officers
void LAi_group_FightGroupsEx(string group1, string group2, bool asignWarriorType, int commander1, int commander2, bool isStay, bool isDialog)
{
	//We indicate that the update should be carried out immediately
	SendMessage(&LAi_grp_relations, "s", "ResetWaveTime");
	//Set the warriors character types
	if(asignWarriorType)
	{
		ref mchr = GetMainCharacter();
		for(int i = 0; i < LAi_numloginedcharacters; i++)
		{
			int idx = LAi_loginedcharacters[i];
			if(idx >= 0)
			{
				//Skip the main character or officer
				if(idx == GetMainCharacterIndex()) continue;
				for(int j = 1; j < OFFICER_MAX; j++)
				{
					if(GetOfficersIndex(mchr, j) == idx) break;
				}
				if(j < OFFICER_MAX) continue;
				//Check if a character in the hit group
				ref chr = &Characters[idx];
				if(CheckAttribute(chr, "chr_ai.group"))
				{
					bool selected = false;
					bool isOne;
					if(chr.chr_ai.group == group1)
					{
						selected = true;
						isOne = true;
					}else{
						if(chr.chr_ai.group == group2)
						{
							selected = true;
							isOne = false;
						}
					}
					// ccc Building Kit Sep 05; next line checks that stunned & buildings don't join fights
					if(selected && chr.chr_ai.type != LAI_TYPE_BUILDING && chr.chr_ai.type != LAI_TYPE_STUNNED)
					{
						LAi_SetWarriorTypeNoGroup(chr);
						LAi_warrior_SetStay(chr, isStay);
						LAi_warrior_DialogEnable(chr, isDialog);
						if(isOne)
						{
							if(commander1 >= 0)
							{
								LAi_warrior_SetCommander(chr, &Characters[commander1]);
							}
							LAi_group_MoveCharacter(chr, group1);
						}else{
							if(commander2 >= 0)
							{
								LAi_warrior_SetCommander(chr, &Characters[commander2]);
							}
							LAi_group_MoveCharacter(chr, group2);
						}
					}
				}
			}
		}
	}
	//Настроим группы
	LAi_group_SetRelation(group1, group2, LAI_GROUP_ENEMY);
	LAi_group_SetHearRadius(group1, 40000000.0);
	LAi_group_SetSayRadius(group1, 40000000.0);
	LAi_group_SetHearRadius(group2, 40000000.0);
	LAi_group_SetSayRadius(group2, 40000000.0);
}

//------------------------------------------------------------------------------------------
//Objectives
//------------------------------------------------------------------------------------------

//Select the target for this character
int LAi_group_GetTarget(aref chr)
{
	int index = -1;
	if(SendMessage(&LAi_grp_relations, "sie", "GetTrg", chr, &index) == 0)
	{
		index = -1;
	}
	return index;
}

//Check target
bool LAi_group_ValidateTarget(aref chr, aref trg)
{
	return (SendMessage(&LAi_grp_relations, "sii", "VldTrg", chr, trg) != 0);
}

//The Enemy Is this character
bool LAi_group_IsEnemy(aref chr, aref trg)
{
	return (SendMessage(&LAi_grp_relations, "sii", "IsEnemy", chr, trg) != 0);
}

//------------------------------------------------------------------------------------------
//The response to attack
//------------------------------------------------------------------------------------------

//Response groups to attack attack-> hit
bool LAi_group_Attack(aref attack, aref hit)
{
	if(attack.chr_ai.group == hit.chr_ai.group)
	{
		//Ignore his
		return false;
	}
	//Set on each other
	SendMessage(&LAi_grp_relations, "sss", "Attack", attack.chr_ai.group, hit.chr_ai.group);
	//Add the enemy
	SendMessage(&LAi_grp_relations, "siif", "AddTarget", hit, attack, 10.0 + rand(10));
	return true;
}

//Update the list of enemies of the character
void LAi_group_UpdateTargets(aref chr)
{
	SendMessage(&LAi_grp_relations, "si", "UpdChrTrg", chr);
}

//------------------------------------------------------------------------------------------
//Utilities
//------------------------------------------------------------------------------------------

//Remove all destinations from the
void LAi_group_ClearAllTargets()
{
	SendMessage(&LAi_grp_relations, "s", "ClearAllTargets");
}

//Get the value of an alarm for a player
float LAi_group_GetPlayerAlarm()
{
	return LAi_grp_playeralarm;
}

//If the alarm is active for the player
bool LAi_group_IsActivePlayerAlarm()
{
	if (bSeaActive) return false; // PB: This should NEVER be on at sea!
	return LAi_grp_alarmactive;
}

//Set the quest for a slew of
void LAi_group_SetCheck(string groupName, string quest)
{
	// PB: Use new system instead -->
	ref PChar = GetMainCharacter();
	PChar.quest.(quest).win_condition.l1 = "Group_Death";
	PChar.quest.(quest).win_condition.l1.group = groupName;
	PChar.quest.(quest).win_condition = quest;
	// PB: Use new system instead <--

/*	// PB: Old code no longer works; system was rewritten by KK to fix boarding problems
	//Find the free field
	aref quests;
	makearef(quests, LAi_grp_relations.quests);
	int num = GetAttributesNum(quests);
	string atr = "q";
	for(int i = 0; i < num + 10; i++)
	{
		atr = "q" + i;
		if(!CheckAttribute(quests, atr)) break;
	}
	//Fill
	quests.(atr).group = groupName;
	if(quest!="") quests.(atr).quest = quest;//MAXIMUS
*/
}

//Set the event to a slew of
/* PB --> void LAi_group_SetCheckEvent(string groupName)
{
	//Find the free field
	aref quests;
	makearef(quests, LAi_grp_relations.quests);
	int num = GetAttributesNum(quests);
	string atr = "q";
	for(int i = 0; i < num + 10; i++)
	{
		atr = "q" + i;
		if(!CheckAttribute(quests, atr)) break;
	}
	//Fill
	quests.(atr).group = groupName;
} <-- PB */


//Remove the quest for a slew of
void LAi_group_RemoveCheck(string groupName)
{
	// PB: Use new system instead -->
	aref quests;
	ref PChar = GetMainCharacter();
	makearef(quests, PChar.quest);
	int num = GetAttributesNum(quests);
	for(int i = 0; i < num; i++)
	{
		aref atr = GetAttributeN(&quests, i);
		if(GetAttribute(atr, "win_condition.l1.group") == groupName)
		{
			//Remove
			DeleteAttribute(&quests, GetAttributeName(GetAttributeN(&quests, i)));
			i = -1;
			num = GetAttributesNum(&quests);
		}
	}
	// PB: Use new system instead <--

/*	// PB: Old code no longer works; system was rewritten by KK to fix boarding problems
	//Find the free field
	aref quests;
	makearef(quests, LAi_grp_relations.quests);
	int num = GetAttributesNum(quests);
	for(int i = 0; i < num; i++)
	{
		aref atr = GetAttributeN(&quests, i);
		if(atr.group == groupName)
		{
			//Remove
			DeleteAttribute(&quests, GetAttributeName(GetAttributeN(&quests, i)));
			i = -1;
			num = GetAttributesNum(&quests);
		}
	}
*/
}

//Check the quest for a slew of
/* KK --> void LAi_group_CheckGroupQuest(aref chr)
{
	//Get the branch with quests
	aref quests; makearef(quests, LAi_grp_relations.quests);
	if(GetAttributesNum(&quests)<=0) return;

	//Check the other characters in this group
	if(!CheckAttribute(chr, "chr_ai.group"))
	{
		Trace("CheckGroupQuest: Character <" + chr.id + "> can't have field chr_ai.group");
		return;
	}

	int i;
	int num = GetAttributesNum(&quests);
	string group = chr.chr_ai.group;
	for(i=0; i<LAi_numloginedcharacters; i++)
	{
		int idx = LAi_loginedcharacters[i];
		if(idx<0) continue;
		if(idx==sti(chr.index)) continue;

		if(!CheckAttribute(&Characters[idx], "chr_ai.group")) Characters[idx].chr_ai.group = LAI_DEFAULT_GROUP;
		if(group==Characters[idx].chr_ai.group) //There are still alive in this group
		{
			if(!CheckAttribute(&Characters[idx],"corpse")) return; // NK handling for corpses 05-07-19. Not really needed, because when we kill we set to corpse group. But this is a template for disarm...
		}
	}

	//Last of the magikan ...
	for(i = 0; i < num; i++)
	{
		aref atr = GetAttributeN(&quests, i);
		if(atr.group!=group) continue;

		//Found a quest, run it for execution
		if(CheckAttribute(atr, "quest")) LAi_QuestDelay(atr.quest, 0.000001);
//		else
//		{
//			if (!CheckAttribute(GetMainCharacter(), "groupkill"))		// LDH - added so that this this event is posted only once
//			{
//				characters[GetMainCharacterIndex()].groupkill = true;
//				PostEvent("LAi_event_GroupKill", 1, "s", group);
//			}
//		}
		//Now delete
		DeleteAttribute(&quests, GetAttributeName(GetAttributeN(&quests, i)));
		i = -1;
		num = GetAttributesNum(&quests);
	}
} <-- KK */


//------------------------------------------------------------------------------------------
//The response to requests
//------------------------------------------------------------------------------------------

//Update the alarm, called on every frame
#event_handler("CharacterGroup_UpdateAlarm", "LAi_group_UpdateAlarm");
void LAi_group_UpdateAlarm()
{
	ref mchr = GetMainCharacter(); // KK
	LAi_grp_playeralarm = GetEventData();
	LAi_grp_alarmactive = GetEventData();
	if(!bSeaActive)
	{
		// PB -->
		if(!LAi_grp_alarmactive && CheckAttribute(mchr, "locationLock"))
		{
			EndQuestMovie();
			DeleteAttribute(mchr,"locationLock");
			// GR: Stealing Soldier Uniforms -->
			if (CheckAttribute(mchr, "receivemodel"))
			{
				if (!CheckAttribute(mchr, "clothes." + mchr.receivemodel))
				{
					GiveModel2Player(mchr.receivemodel, false);					// if you have just defeated a group of soldiers and reinforcements,
					LogIt("You take a uniform from one of the dead soldiers");	// get a free uniform as set by SoldierReinforcements in CCCFunctions.c
				}
				DeleteAttribute(mchr, "receivemodel");
			}
			// GR: Stealing Soldier Uniforms <--
		}
		// PB <--

		if(iRealismMode>0 || SHORE_DANGER_ALARM) // Screwface
		{
			if(!CheckAttribute(mchr,"doalarm"))
			{
				LAi_grp_alarmactive = false;
			}
			else
			{
				if(!LAi_grp_alarmactive) DeleteAttribute(mchr,"doalarm");
			}
		}//Screwface : end
	}
	Sound_OnAlarm(LAi_grp_alarmactive);
}
//#20190717-01
void resetGroupRel()
{
    aref aGrp, qGrp;
	makearef(aGrp, LAi_grp_relations.savedata);
	int num = GetAttributesNum(aGrp);
	for(int i = 0; i < num; i++)
	{
		aref atr = GetAttributeN(&aGrp, i);
		if(sti(atr.curState) != LAI_GROUP_ENEMY_INT) continue;		//line 534
		if(sti(atr.isactive) == 0)
            atr.curState = LAI_GROUP_NEITRAL_INT;
	}
}
