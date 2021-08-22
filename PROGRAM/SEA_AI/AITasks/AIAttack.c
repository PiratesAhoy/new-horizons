// Set task attack for SeaAI
void AIAttack_GroupAttack(string sGroupAttacker, string sGroupAttacked, bool bAttackedTask, bool bOverride)
{
	// NK bugfix 05-05-11 -->
	int iG1 = Group_FindGroup(sGroupAttacker);
	int iG2 = Group_FindGroup(sGroupAttacked);
	if(iG1 == -1 || iG2 == -1) return;
	if (sGroupAttacked == "none") return;		// LDH there is a "none" group with no leader.  Probably a fort - 25Jan09
	ref rG1 = Group_GetGroupByIndex(iG1); //Group_GetGroupByID(sGroupAttacker);
	ref rG2 = Group_GetGroupByIndex(iG2); //Group_GetGroupByID(sGroupAttacked);
	// NK <--

	float fHP1 = Group_GetPowerHP_R(rG1);
	float fHP2 = Group_GetPowerHP_R(rG2);

	float fHPRatio1 = fHP1 / (fHP2 + 0.0001);
	float fHPRatio2 = fHP2 / (fHP1 + 0.0001);

	ref rCharacter1 = Group_GetGroupCommanderR(rG1);
	ref rCharacter2 = Group_GetGroupCommanderR(rG2);

	string sGroupType1 = Group_GetTypeR(rG1);
	string sGroupType2 = Group_GetTypeR(rG2);

	int iNation1 = sti(rCharacter1.nation);
	int iNation2 = sti(rCharacter2.nation);

	if (bOverride) SetCharacterRelationBoth(sti(rCharacter1.index), sti(rCharacter2.index), RELATION_ENEMY); // PB: Only do this if needed!

	// check for already attack
	if (sti(rG1.Task) == AITASK_ATTACK)
	{
		if (rG1.Task.Target != sGroupAttacked) { return; }
		//return;
	}

	// ====================================================== set attack task to ships
	if (sGroupAttacker != PLAYER_GROUP)
	{
		int iIndex = 0;

		int iCharactersNum2 = Group_GetCharactersNumR(rG2);
		int iDeadCharactersNum2 = Group_GetDeadCharactersNumR(rG2);

		// find targets for rG1
		if (iCharactersNum2 != iDeadCharactersNum2 && iCharactersNum2 > 0)
		{
			int i = 0;
			while (true)
			{
				int iCharacterIndex = Group_GetCharacterIndexR(rG1, i); i++;
				if (iCharacterIndex < 0) { break; }
				if (bOverride) SetCharacterRelationBoth(sti(rCharacter2.index), iCharacterIndex, RELATION_ENEMY); // PB: Only do this if needed!
				if (LAi_IsDead(&Characters[iCharacterIndex])) { continue; }

				int iCharacterVictim = -1;
				while (iCharacterVictim < 0)
				{
					iCharacterVictim = Group_GetCharacterIndexR(rG2, iIndex);
					if (iCharacterVictim < 0) { iIndex = 0; continue; }
					if (LAi_IsDead(&Characters[iCharacterVictim])) { iCharacterVictim = -1; }
					iIndex++;
				}

				Ship_SetTaskAttack(SECONDARY_TASK, iCharacterIndex, iCharacterVictim);
			}
		}
	}
	// ====================================================== set attack task to ships
	bool bTaskLock = false;

	if (sGroupAttacked == PLAYER_GROUP) { return; }
	if (!bAttackedTask) { return; }
	if (Group_isTaskLockR(rG2))
	{
		if (sti(rG2.Task) != AITASK_ATTACK) { return; }
		if (rG2.Task.Target != sGroupAttacker) { return; }

		bTaskLock = true;
	}

	float fLeadership = MakeFloat(GetShipSkill(rCharacter2, SKILL_LEADERSHIP)) / MAX_CHARACTER_SKILL;

	float fTmp = fHPRatio2;// * Clampf(fLeadership + 0.01);

	int iTask = AITASK_ATTACK;
	if (!bTaskLock) iTask = AIAttack_SelectTask(sGroupType2, fTmp);
	switch (iTask)
	{
		case AITASK_ATTACK:
			Group_SetTaskAttackEx(sGroupAttacked, sGroupAttacker, false, bOverride);
		break;
		case AITASK_RUNAWAY:
			Group_SetTaskRunaway(sGroupAttacked);
		break;
	}
}

int AIAttack_SelectTask(string sGroupType, float fRatio)
{
// START MOD Code by Stone-D : 01/08/2003
	int iTask = AITASK_RUNAWAY;  //NK trying back to normal, was // Temporary in lieu of borked AI MOD.
// END MOD Code by Stone-D : 01/08/2003
	// NK trying back to normal 05-04-20 int iTask = AITASK_ATTACK;
	switch (sGroupType)
	{
		case "war":
			if (fRatio > 0.8) iTask = AITASK_ATTACK;
		break;
		case "trade":
			if (fRatio > 1.5) iTask = AITASK_ATTACK;
		break;
		case "pirate":
			if (fRatio > 0.7) iTask = AITASK_ATTACK;
		break;
	}
	return iTask;
}

// check attack task for Group
void AIAttack_CheckTask(string sGroupID)
{
	// NK bugfix 05-05-11 -->
	// skip if group is player group - move up here 05-05-11
	if (sGroupID == PLAYER_GROUP) { return; }
	int iG1 = Group_FindGroup(sGroupID);
	if(iG1 == -1) return;
	ref rG1 = Group_GetGroupByIndex(iG1);
	string sGroupType1 = Group_GetTypeR(rG1);
	int iG2 = Group_FindGroup(rG1.Task.Target);
	bool newtask = false;
	if(iG2 == -1) newtask = true;
	else
	{
		//ref rG1 = Group_GetGroupByID(sGroupID);
		ref rG2 = Group_GetGroupByIndex(iG2); //Group_GetGroupByID(rG1.Task.Target);

		ref rCharacter1 = Group_GetGroupCommanderR(rG1);
		newtask = Group_isDeadR(rG2);
	}

	// if group task is lock, check for task complete, if not - continue task
	float fAng = frnd() * PIm2;
	if (newtask)
	{
		// NK <--
		switch (sGroupType1)
		{
			case "trade":
				if(CheckAttribute(rG1.Task.Target,"Pos")) Group_SetTaskMove(sGroupID, stf(rG1.Task.Target.Pos.x), stf(rG1.Task.Target.Pos.z));
			break;
			case "war":
				Group_SetTaskMove(sGroupID, 10000.0 * sin(fAng) , 10000.0 * cos(fAng));
			break;
			case "pirate":
				Group_SetTaskMove(sGroupID, 10000.0 * sin(fAng) , 10000.0 * cos(fAng));
			break;
		}
		// find new task
		return;
	}

	if (!Group_isTaskLockR(rG1))
	{
		float fHP1 = Group_GetPowerHP_R(rG1);
		float fHP2 = Group_GetPowerHP_R(rG2);
		float fAHP1 = Group_GetAttackHPDistance_R(rG1, 300.0);

		float fAHPRatio1 = fHP1 / (fAHP1 + 0.0001);
		float fHPRatio1 = fHP1 / (fHP2 + 0.0001);

		float fLeadership = MakeFloat(GetShipSkill(rCharacter1, SKILL_LEADERSHIP)) / MAX_CHARACTER_SKILL;

		float fTmp = fAHPRatio1;// * Clampf(fLeadership + 0.01);

		switch (AIAttack_SelectTask(sGroupType1, fTmp))
		{
			case AITASK_RUNAWAY:
				Group_SetTaskRunaway(sGroupID);
				return;
			break;
		}
	}

	// check attack task for dead targets
	int iIndex = 0;

	int iCharactersNum2 = Group_GetCharactersNumR(rG2);

	// find targets for rG1
	int i = 0;
	while (true)
	{
		int iCharacterIndex = Group_GetCharacterIndexR(rG1, i); i++;
		if (iCharacterIndex < 0) { break; }
		ref rCharacter = GetCharacter(iCharacterIndex);
		if (LAi_IsDead(rCharacter)) { continue; }
		if (CheckAttribute(rCharacter, "SeaAI.Task"))
		{
			if (sti(rCharacter.SeaAI.Task) != AITASK_ATTACK) { continue; }
			if (!LAi_IsDead(&Characters[sti(rCharacter.SeaAI.Task.Target)])) { continue; }
		}

		int iCharacterVictim = -1;
		while (iCharacterVictim < 0)
		{
			iCharacterVictim = Group_GetCharacterIndexR(rG2, iIndex);
			if (iCharacterVictim < 0) { iIndex = 0; continue; }
			if (LAi_IsDead(&Characters[iCharacterVictim])) { iCharacterVictim = -1; }
			iIndex++;
		}

		Ship_SetTaskAttack(SECONDARY_TASK, iCharacterIndex, iCharacterVictim);
	}
}
