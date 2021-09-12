bool TestIntValue(int nValue, int nCompareValue, string sOperation)
{
	switch(sOperation)
	{
	case ">=":
			if(nValue >= nCompareValue) return true;
			return false;
	break;
	case "<=":
			if(nValue <= nCompareValue) return true;
			return false;
	break;
	case "=":
			if(nValue == nCompareValue) return true;
			return false;
	break;
	case ">":
			if(nValue > nCompareValue) return true;
			return false;
	break;
	case "<":
			if(nValue < nCompareValue) return true;
			return false;
	break;
	}
	trace("ERROR: invalid operation(" + sOperation + ")");
	return false;
}

bool ProcessCondition(aref condition)
{
	bool bTmp;
	int i;
	ref tmpRef, refCharacter;
	aref arTmpARef;
	string sConditionName, sTmpString, locGroup;
	float fx, fy, fz;
	bool ret = false; // KK

	sConditionName = GetAttributeValue(condition);
	if(CheckAttribute(condition,"character"))
	{
		condition.characterIdx = "" + GetCharacterIndex(condition.character);
		DeleteAttribute(condition,"character");
	}
	if(sti(GetAttribute(condition,"characterIdx")) > -1) // PB
	{
		refCharacter = GetCharacter(sti(condition.characterIdx));
	}
	else
	{
		refCharacter = GetMainCharacter();
	}

	switch(sConditionName)
	{
    //Boyer add for weather
    case "ExitFromSea":
        if (bSeaActive == false)
        {
            return true;
        }
        return false;
    break;
	case "Goods":
		return TestIntValue(GetCargoGoods(refCharacter,sti(condition.goods)),sti(condition.quantity),condition.operation);
	break;
	case "party_goods":
		return TestIntValue(GetSquadronGoods(refCharacter,sti(condition.goods)),sti(condition.quantity),condition.operation);
	break;
	case "item":
		return CheckCharacterItem(refCharacter,condition.item);
	break;
	case "passenger":
		if(CheckAttribute(condition,"npc"))
		{
			condition.npcIdx = "" + GetCharacterIndex(condition.npc);
			DeleteAttribute(condition,"npc");
		}
		i = FindFellowtravellers(refCharacter,GetCharacter(sti(condition.npcIdx)));
		if(i==FELLOWTRAVEL_PASSENGER) return true;
		if(i==FELLOWTRAVEL_OFFICER) return true;
		if(i==FELLOWTRAVEL_CAPTIVE) return true;
		return false;
	break;
	case "prisoner":
		if(CheckAttribute(condition,"npc"))
		{
			condition.npcIdx = "" + GetCharacterIndex(condition.npc);
			DeleteAttribute(condition,"npc");
		}
		i = FindFellowtravellers(refCharacter,GetCharacter(sti(condition.npcIdx)));
		return i==FELLOWTRAVEL_CAPTIVE;
	break;
	case "officer":
		if(CheckAttribute(condition,"npc"))
		{
			condition.npcIdx = "" + GetCharacterIndex(condition.npc);
			DeleteAttribute(condition,"npc");
		}
		i = FindFellowtravellers(refCharacter,GetCharacter(sti(condition.npcIdx)));
		return i==FELLOWTRAVEL_OFFICER;
	break;
	case "companion":
		if(CheckAttribute(condition,"npc"))
		{
			condition.npcIdx = "" + GetCharacterIndex(condition.npc);
			DeleteAttribute(condition,"npc");
		}
		i = FindFellowtravellers(refCharacter,GetCharacter(sti(condition.npcIdx)));
		return i==FELLOWTRAVEL_COMPANION;
	break;
	case "ship_class":
		i = GetCharacterShipClass(refCharacter);
		if(i==-1) return false;
		return TestIntValue(i,sti(condition.class),condition.operation);
	break;
	case "ship":
		return GetCharacterShipType(refCharacter) == sti(condition.type);
	break;
	case "cannons":
		return GetCaracterShipCannonsType(refCharacter) == sti(condition.type);
	break;
	case "hold_space":
		return TestIntValue(GetCargoFreeSpace(refCharacter),sti(condition.quantity),condition.operation);
	break;
	case "party_hold_space":
		i = GetSquadronFreeSpace(refCharacter,sti(condition.goods));
		return TestIntValue(i,sti(condition.quantity),condition.operation);
	break;
	case "Crew_Space":
		return TestIntValue(GetFreeCrewQuantity(refCharacter),sti(condition.quantity),condition.operation);
	break;
	case "Party_Crew_Space":
		return TestIntValue(GetFreePartyCrewQuantity(refCharacter),sti(condition.quantity),condition.operation);
	break;
	case "Skill":
		i = CalcCharacterSkill(refCharacter,condition.skill);
		return TestIntValue(i,sti(condition.value),condition.operation);
	break;
	case "Party_Skill":
		i = GetShipSkill(refCharacter,condition.skill);
		return TestIntValue(i,sti(condition.value),condition.operation);
	break;
	case "Rank":
		return TestIntValue(sti(refCharacter.rank),sti(condition.value),condition.operation);
	break;
	case "Reputation":
		return TestIntValue(sti(refCharacter.reputation),sti(condition.value),condition.operation);
	break;
	case "relation":
//		return GetRMRelationType(GetRMRelation(refCharacter, sti(condition.nation) )) == sti(condition.relation); // PB: Simpler alternate, requires INTEGER input instead of strings!
		i = GetRMRelationType(GetRMRelation(refcharacter,GetNationTypeByID(condition.nation))); // GR
//		i = GetNationRelation2Character(GetNationTypeByID(condition.nation),sti(refCharacter.index));
		bTmp = false;
		switch(condition.relation)
		{
			case "Friendly":	bTmp = i==RELATION_FRIEND; break;
			case "Hostile":		bTmp = i==RELATION_ENEMY; break;
			case "Neutral":		bTmp = i==RELATION_NEUTRAL; break;
		}
		return bTmp;
	break;

	case "location":
		if(refCharacter.location==condition.location) return !CharacterIsDead(refCharacter);
		return false;
	break;

	case "locator":
		if(refCharacter.location == condition.location)
		{
			locGroup = condition.locator_group;
			if( !CheckAttribute(refCharacter,"Quests.LocatorCheck."+locGroup) )
			{
				if(IsEntity(refCharacter))
				{
					refCharacter.Quests.LocatorCheck.(locGroup) = "";
					if( GetCharacterPos(refCharacter,&fx,&fy,&fz) )
					{
						if( CheckCurLocator(locGroup,condition.locator, fx,fy,fz) )
							refCharacter.Quests.LocatorCheck.(locGroup) = condition.locator;
					}
					AddCharacterLocatorGroup(refCharacter,locGroup);
				}
				else
				{
					Trace("character "+refCharacter.id+" not entity");
					return false;
				}
			}
			if(refCharacter.Quests.LocatorCheck.(locGroup)==condition.locator)	return true;
		}
		return false;
	break;
	case "NPC_Death":
		return CharacterIsDead(refCharacter);
	break;
	case "Nation_Ship_sink":
		return TestIntValue(GetNationShipKilled(refCharacter,condition.nation),sti(condition.quantity),condition.operation);
	break;
	case "Nation_Ship_Capture":
		return TestIntValue(GetNationShipCaptured(refCharacter,condition.nation),sti(condition.quantity),condition.operation);
	break;
	case "Class_Ship_sink":
		return TestIntValue(GetClassShipKilled(refCharacter,sti(condition.class)),sti(condition.quantity),condition.operation);
	break;
	case "Class_Ship_Capture":
		return TestIntValue(GetClassShipCaptured(refCharacter,sti(condition.class)),sti(condition.quantity),condition.operation);
	break;
	case "Time":
		return GetDayTime() == condition.time;
	break;
	case "Timer":
		if( GetDataYear() < sti(condition.date.year) ) return false;
		if( GetDataYear() > sti(condition.date.year) ) return true;
		if( GetDataMonth() < sti(condition.date.month) ) return false;
		if( GetDataMonth() > sti(condition.date.month) ) return true;
		if( GetDataDay() < sti(condition.date.day) ) return false;
		if( GetDataDay() > sti(condition.date.day) ) return true;
		// NK to use hour if there 04-09-18 -->
		if(CheckAttribute(condition,"date.hour"))
		{
			if( sti(environment.date.hour) < sti(condition.date.hour) ) { return false; }
		}
		// NK <--
		return true;
	break;
	case "Ship_HP":
		return TestIntValue(GetCurrentShipHP(refCharacter),sti(condition.quantity),condition.operation);
	break;
	case "Quest":
		return CheckActiveQuest(condition.quest);
	break;
	case "Character_Capture":
		if( CheckAttribute(refCharacter,"Killer.status") && sti(refCharacter.Killer.status)==KILL_BY_ABORDAGE ) return true;
		return false;
	break;
// KK -->
	case "SeaEnter":
		return bSeaActive && !bAbordageStarted;
	break;
// <-- KK
	case "MapEnter":
		// LDH added 21Feb09
		if (CheckAttribute(refCharacter,"directsail1.QuestCheckMapEnter"))	// set in Directsail upon islandswitch
		{
			DeleteAttribute(refCharacter,"directsail1.QuestCheckMapEnter");
			return true;
		}
		return IsEntity(&worldMap);	//TIH bugfix from stock //return IsEntity(worldMap);
	break;
	case "ExitFromLocation":
		return refCharacter.location != condition.location;
	break;
	case "Ship_location":
		if( CheckAttribute(refCharacter,"location.from_sea") && refCharacter.location.from_sea==condition.location ) return true;
		return false;
	break;
// KK -->
	case "Fort_destroy":
		ret = false;
		if (CheckAttribute(refCharacter,"FortDestroy")) {
			ret = refCharacter.FortDestroy == "1";
			if (ret) DeleteAttribute(refCharacter, "FortDestroy");
		}
		return ret;
	break;
	case "Colony_capture":
		ret = false;
		if (CheckAttribute(refCharacter, "QuestColonyCaptured") && CheckAttribute(condition, "town")) {
			ret = sti(refCharacter.QuestColonyCaptured) == true && refCharacter.QuestColonyCaptured.town == condition.town;
			if (ret && CheckAttribute(condition, "nation")) ret = GetTownNation(condition.town) == sti(condition.nation);
			if (ret) DeleteAttribute(refCharacter, "QuestColonyCaptured");
		}
		return ret;
	break;
	case "Group_Death":
		ret = false;
		if (CheckAttribute(condition, "group")) {
			sTmpString = condition.group;
			if (CheckAttribute(refCharacter, "GroupDeath." + sTmpString)) {
				makearef(arTmpARef, refCharacter.GroupDeath);
				ret = sti(arTmpARef.(sTmpString)) == true;
				if (ret) {
					DeleteAttribute(arTmpARef, sTmpString);
					if (GetAttributesNum(arTmpARef) == 0) DeleteAttribute(refCharacter, "GroupDeath");
				}
			}
		}
		return ret;
	break;
// <-- KK
	case "ActIntoLocator":
		if(refCharacter.location == condition.location)
		{
			locGroup = condition.locator_group;
			if( !CheckAttribute(refCharacter,"Quests.LocatorCheck."+locGroup) )
			{
				if(IsEntity(refCharacter))
				{
					refCharacter.Quests.LocatorCheck.(locGroup) = "";
					if( GetCharacterPos(refCharacter,&fx,&fy,&fz) )
					{
						if( CheckCurLocator(locGroup,condition.locator, fx,fy,fz) )
							refCharacter.Quests.LocatorCheck.(locGroup) = condition.locator;
					}
					AddCharacterLocatorGroup(refCharacter,locGroup);
				}
				else
				{
					Trace("character "+refCharacter.id+" not entity");
					return false;
				}
			}
			if(refCharacter.Quests.LocatorCheck.(locGroup)==condition.locator)
			{
				SetPossibleAction(refCharacter,condition,true);
			}
			else
			{
				SetPossibleAction(refCharacter,condition,false);
			}
		}
		return false;
	break;
	}
	trace("ERROR: unidentified condition type(): " + sConditionName);
	DumpAttributes(condition);
	return false;
}

bool bQuestCheckProcess = false;
void QuestsCheck()
{
	if(bQuestCheckProcess) return;
	bQuestCheckProcess = true;
	aref quests;
	aref quest;
	aref conditions;
	aref condition;
	int  nQuestsNum;
	int  nConditionsNum;
	int  n,m;
	string sQuestName;
	bool bQuestCompleted;


	makearef(quests,Characters[GetMainCharacterIndex()].quest);

	nQuestsNum = GetAttributesNum(quests);

	for(n = 0; n < nQuestsNum; n++)
	{
		quest = GetAttributeN(quests,n);

		sQuestName = GetAttributeName(quest);

		if(CheckAttribute(quest,"win_condition"))
		{
			if(quest.win_condition == "no")
			{
				// quest with no win condition; completed on first check
				OnQuestComplete(quest);
				nQuestsNum = GetAttributesNum(quests);
				continue;
			}
			makearef(conditions,quest.win_condition);
			nConditionsNum = GetAttributesNum(conditions);
			if(nConditionsNum == 0)
			{
				// quest with no win condition; completed on first check
				OnQuestComplete(quest);
				nQuestsNum = GetAttributesNum(quests);
				continue;
			}
			bQuestCompleted = true;
			for(m = 0; m < nConditionsNum; m++)
			{
				condition = GetAttributeN(conditions,m);
				if(ProcessCondition(condition) == false)
				{
					bQuestCompleted = false;
					break;
				}
			}
			if(bQuestCompleted)
			{
				OnQuestComplete(quest);
				nQuestsNum = GetAttributesNum(quests);
			}
		}

		if(CheckAttribute(quest,"fail_condition"))
		{
			makearef(conditions,quest.fail_condition);
			nConditionsNum = GetAttributesNum(conditions);
			if(nConditionsNum == 0) continue;
			for(m = 0; m < nConditionsNum; m++)
			{
				condition = GetAttributeN(conditions,m);
				if(ProcessCondition(condition) == true)
				{
					OnQuestFailed(quest);
					nQuestsNum = GetAttributesNum(quests);
					break;
				}
			}
		}
	}

	for(n = 0; n < GetAttributesNum(quests); n++)
	{
		quest = GetAttributeN(quests,n);
		if(CheckAttribute(quest,"over") && quest.over=="yes")
		{
			// delete quests already completed or failed
			DeleteAttribute(quests,GetAttributeName(quest));
			n--;
		}
	}
	bQuestCheckProcess = false;
}

void OnQuestComplete(aref quest)
{
	if(!CheckAttribute(quest,"over") && CheckAttribute(quest,"win_condition"))
	{
		if(quest.win_condition == "_") return;
		quest.over = "yes";
		// PB: Error checking -->
		ref PChar = GetMainCharacter();
		PChar.quest.completed_win_condition = GetAttributeName(quest); //So we can check which quest send us here.
		DeleteAttribute(PChar, "questnotfound");				// Make sure this is GONE!

		// Common Quests
		CommonQuestComplete(quest.win_condition);				// <-- Execute the actual quest case
		if(!CheckAttribute(PChar, "questnotfound"))
		{
			DeleteAttribute(PChar, "quest.completed_win_condition"); //Levis remove it to be sure
			trace("Quest name " + quest.win_condition + " FOUND in CommonQuestComplete");
			return;
		}
		DeleteAttribute(PChar, "questnotfound");

		// Main Quests
		if (FindFile("PROGRAM\" + GetStorylinePath(FindCurrentStoryline()), "*.c", "SL_utils.c") != "")
		{
			if (!SegmentIsLoaded(GetStorylinePath(FindCurrentStoryline()) + "SL_utils.c"))
			{
				trace("Loading " + GetStorylinePath(FindCurrentStoryline()) + "SL_utils.c");
				LoadSegment(GetStorylinePath(FindCurrentStoryline()) + "SL_utils.c");
			}
		}
		LoadStorylineFile("quests\", "quests_reaction.c");		// PB: To Prevent Errors
		QuestComplete(quest.win_condition);						// <-- Execute the actual quest case
		if(!CheckAttribute(PChar, "questnotfound"))
		{
			DeleteAttribute(PChar, "quest.completed_win_condition"); //Levis remove it to be sure
			trace("Quest name " + quest.win_condition + " FOUND in QuestComplete");
			return;
		}
		DeleteAttribute(PChar, "questnotfound");

		// Both/Side Quests
		LoadStorylineFile("quests\", "both_reaction.c");		// PB: To Prevent Errors
		BothQuestComplete(quest.win_condition);					// <-- Execute the actual quest case
		if(!CheckAttribute(PChar, "questnotfound"))
		{
			DeleteAttribute(PChar, "quest.completed_win_condition"); //Levis remove it to be sure
			trace("Quest name " + quest.win_condition + " FOUND in BothQuestComplete");
			return;
		}
		DeleteAttribute(PChar, "questnotfound");

		// Side Quests
		SideQuestComplete(quest.win_condition);				// <-- Execute the actual quest case
		if(!CheckAttribute(PChar, "questnotfound"))
		{
			DeleteAttribute(PChar, "quest.completed_win_condition"); //Levis remove it to be sure
			trace("Quest name " + quest.win_condition + " FOUND in SideQuestComplete");
			return;
		}
		DeleteAttribute(PChar, "questnotfound");
		DeleteAttribute(PChar, "quest.completed_win_condition"); //Levis remove it to be sure

		TraceAndLog("ERROR - Quest name " + quest.win_condition + " NOT found in ANY function");
		// PB: Error checking <--
	}
}

void OnQuestFailed(aref quest)
{
	if(CheckAttribute(quest,"fail_condition"))
	{
		if(quest.fail_condition == "_") return;
		quest.over = "yes";
		// PB: Error checking -->
		ref PChar = GetMainCharacter();
		DeleteAttribute(PChar, "questnotfound");				// Make sure this is GONE!

		// Common Quests
		CommonQuestComplete(quest.fail_condition);				// <-- Execute the actual quest case
		if(!CheckAttribute(PChar, "questnotfound"))
		{
			trace("Quest name " + quest.fail_condition + " FOUND in CommonQuestComplete");
			return;
		}
		DeleteAttribute(PChar, "questnotfound");

		// Main Quests
		LoadStorylineFile("quests\", "quests_reaction.c");		// PB: To Prevent Errors
		QuestComplete(quest.fail_condition);					// <-- Execute the actual quest case
		if(!CheckAttribute(PChar, "questnotfound"))
		{
			trace("Quest name " + quest.fail_condition + " FOUND in QuestComplete");
			return;
		}
		DeleteAttribute(PChar, "questnotfound");

		// Both Quests
		LoadStorylineFile("quests\", "both_reaction.c");		// PB: To Prevent Errors
		BothQuestComplete(quest.fail_condition);				// <-- Execute the actual quest case
		if(!CheckAttribute(PChar, "questnotfound"))
		{
			trace("Quest name " + quest.fail_condition + " FOUND in BothQuestComplete");
			return;
		}
		DeleteAttribute(PChar, "questnotfound");

		// Side Quests
		SideQuestComplete(quest.fail_condition);				// <-- Execute the actual quest case
		if(!CheckAttribute(PChar, "questnotfound"))
		{
			trace("Quest name " + quest.fail_condition + " FOUND in SideQuestComplete");
			return;
		}
		DeleteAttribute(PChar, "questnotfound");

		TraceAndLog("ERROR - Quest name " + quest.fail_condition + " NOT found in ANY function");
		// PB: Error checking <--
	}
}

void QC_DoUnloadLocation()
{
	DeleteAttribute(GetMainCharacter(),"GroupDeath");
	for(int n=0; n<CHARACTERS_QUANTITY; n++) // NK 05-04-05 use CHARACTERS_QUANTITY
	{
		DeleteAttribute(GetCharacter(n),"Quests.LocatorCheck");
	}
}

void SetPossibleAction(ref chref, aref condition, bool setting)
{
	if(setting)
	{
		if(CheckAttribute(condition,"act"))
		{
			condition.oldact = g_ActiveActionName;
			Log_SetActiveAction(condition.act);
		}
		chref.Quests.quest_act = GetAttributeName(condition);
	}
	else
	{
		if(CheckAttribute(condition,"oldact"))
		{
			Log_SetActiveAction(condition.oldact);
			DeleteAttribute(condition,"oldact");
		}
		DeleteAttribute(chref,"Quests.quest_act");
	}
}
