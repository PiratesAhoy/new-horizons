void QuestAbordageStartEvent()
{
	int iCharacter1 = GetEventData();
	int iCharacter2 = GetEventData();

	int iTestCharacter = GetCharacterIndex("Pirate Captain 04");

	if (iCharacter1 == iTestCharacter || iCharacter2 == iTestCharacter)
	{
		int smuggle_cargo2 = sti(Characters[GetCharacterIndex("Thomas O'Reily")].smuggle_cargo2);
		int smuggle_amount2 = sti(Characters[GetCharacterIndex("Thomas O'Reily")].smuggle_amount2);
		Characters[GetCharacterIndex("Thomas O'Reily")].quest.contraband = "boarding";
		AddCharacterGoods(GetMainCharacter(), smuggle_cargo2, smuggle_amount2);
	}
}
