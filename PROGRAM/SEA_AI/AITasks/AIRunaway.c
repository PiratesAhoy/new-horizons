void AIRunaway_GroupRunaway(string sGroupID)
{
	ref rG = Group_GetGroupByID(sGroupID);

	if (Group_isDeadR(rG)) { return; }

	int i = 0;
	while (true)
	{
		int iCharacterIndex = Group_GetCharacterIndexR(rG, i); i++;
		if (iCharacterIndex < 0) { break; }
		if (LAi_IsDead(&Characters[iCharacterIndex])) { continue; }
		Ship_SetTaskRunaway(SECONDARY_TASK, iCharacterIndex);
	}	
}