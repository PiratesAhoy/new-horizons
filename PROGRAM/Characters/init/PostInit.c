void DoCharactersPostInit()
{
	int i;
	for (i = 0; i < TOTAL_CHARACTERS; i++)
	{
		if (!Character_PostInit(i)) break;
	}
}
