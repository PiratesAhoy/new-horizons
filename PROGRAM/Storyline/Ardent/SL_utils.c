
string Get_Speaker()
{
	ref PChar = GetMainCharacter();
	string speaker = "";
	int n;
	for (n=1; n<OFFICER_MAX; n++)
	{
		if(GetOfficersIndex(PChar, n) != -1)
		{
			speaker = characters[GetOfficersIndex(Pchar, n)].id;
			break;
		}
	}
	return speaker;
}

int GetCompanionSlotWithType(string ship_type)
{
	ref PChar = GetMainCharacter();
	int i, n, idx;
	if (ship_type == SHIP_NOTUSED_TYPE_NAME) return -1;
	if (PChar.ship.type == ship_type) return 0;	// First check if you have this ship type
	i = -1
	for (n=1; n<COMPANION_MAX; n++)			// Then see if anyone else has it
	{
		idx = GetCompanionIndex(PChar,n);
		if (i == -1 && GetCharacterShipID(Characters[idx]) == ship_type) i = n;
			
	}
	return i;
}

bool CanMarry(ref partner)
{
	ref PChar = GetMainCharacter();
	if (CheckQuestAttribute("spain_betrayal", "true")) return false;
	if (CheckAttribute(PChar, "married") && PChar.married != MR_SINGLE) return false;
	if (CheckAttribute(partner, "married") && partner.married != MR_SINGLE && !CheckAttribute(partner, "married.annulled")) return false;
	if (LAi_IsDead(partner)) return false;
	return true;
}