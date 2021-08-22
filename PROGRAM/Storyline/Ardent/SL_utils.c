
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
	if (LAi_IsDead(partner)) return false;
	return true;
}

bool StoreDialog(ref ch)
{
	if (CheckAttribute(ch, "quest.original_dialog_filename"))
	{
		return false;
	}
	else
	{
		ch.quest.original_dialog_filename = ch.Dialog.Filename;
		ch.quest.original_dialog_CurrentNode = ch.dialog.CurrentNode;
		return true;
	}
}

bool RestoreDialog(ref ch)
{
	if (CheckAttribute(ch, "quest.original_dialog_filename"))
	{
		ch.Dialog.Filename = ch.quest.original_dialog_filename;
		ch.dialog.CurrentNode = ch.quest.original_dialog_CurrentNode;
		DeleteAttribute(ch, "quest.original_dialog_filename");
		DeleteAttribute(ch, "quest.original_dialog_CurrentNode");
		return true;
	}
	else
	{
		return false;
	}
}