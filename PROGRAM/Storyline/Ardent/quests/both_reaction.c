void BothQuestComplete(string sQuestName)
{
	ref PChar, NPChar, sld;

	PChar = GetMainCharacter();

	switch(sQuestName)
	{
		case "intro":
//			PauseAllSounds();
//			PlayStereoOGG("Ardent_start");
			StartQuestMovie(true, true, true);

			switch (GetCharacterShipCabin(PChar))
			{
				case "Cabin_none":
					ChangeCharacterAddressGroup(CharacterFromID("Inquisitor"), "Tutorial_Deck", "goto", "goto2");
				break;

				case "Tutorial_Deck":
					ChangeCharacterAddressGroup(CharacterFromID("Inquisitor"), "Tutorial_Deck", "goto", "goto2");
				break;

				// default
				ChangeCharacterAddressGroup(CharacterFromID("Inquisitor"), "Tutorial_Deck", "reload", "reload1");
			}

			locations[FindLocation("Tutorial_Deck")].type = "Ardent_cabin";
			LAi_SetActorType(characterFromID("Inquisitor"));
			Characters[GetCharacterIndex("Inquisitor")].Dialog.CurrentNode = "start";
			LAi_ActorDialog(characterfromID("Inquisitor"), pchar, "intro_done", 1.0, 1.0);
		break;

		case "intro_done":
			ChangeCharacterAddress(characterFromID("Inquisitor"), "None", "");
			DeleteAttribute(PChar, "shiplog");
			if (GetServedNation() == PERSONAL_NATION)
			{
				SetRelationsAsNation(PERSONAL_NATION);
				SetRMRelation(PChar, SPAIN, REL_WAR);
				WriteNewLogEntry(GetTranslatedLog("Captured!"), GetTranslatedLog("Damnation! That was one smuggling run too many. The patrol ships were too much for ours to take on and the wind wouldn't let us escape to sea."),"Personal",true);
			}
			else
			{
				WriteNewLogEntry(GetTranslatedLog("Captured!"), GetTranslatedLog("Damnation! That ship wasn't an easy merchant after all, but a fighting ship filled with soldiers. That will teach me to look at a ship's flag before attacking, though as we're being boarded, I may not have time to make use of the lesson."),"Personal",true);
			}

			if (PChar.quest.alignment == "good")
			{
				ChangeCharacterAddress(characterFromID("Gheerkin Kamalaas"), "None", "");
				ChangeCharacterAddress(characterFromID("Morys Badlad"), "None", "");
			}
			else
			{
				ChangeCharacterAddress(characterFromID("Louwe Louwman"), "None", "");
				ChangeCharacterAddress(characterFromID("Giraldo Annibal"), "None", "");
			}

			if (!CheckQuestAttribute("cheating", "true"))
			{
				LAi_Fade("", "");
				LAi_QuestDelay("Arrested", 2.0);
			}
		break;

		case "Arrested":
			switch (GetCharacterShipCabin(PChar))
			{
				case "Cabin_none":
					ChangeCharacterAddressGroup(CharacterFromID("Spanish_Captain1"), "Tutorial_Deck", "goto", "goto2");
				break;

				case "Tutorial_Deck":
					ChangeCharacterAddressGroup(CharacterFromID("Spanish_Captain1"), "Tutorial_Deck", "goto", "goto2");
				break;

				// default
				ChangeCharacterAddressGroup(CharacterFromID("Spanish_Captain1"), "Tutorial_Deck", "reload", "reload1");
			}
			LAi_SetActorType(characterFromID("Spanish_Captain1"));
			Characters[GetCharacterIndex("Spanish_Captain1")].Dialog.CurrentNode = "surrendered";
			LAi_ActorDialog(characterfromID("Spanish_Captain1"), pchar, "Arrested_done", 0.0, 0.0);
		break;

		case "Arrested_done":
			EndQuestMovie();
			ChangeCharacterAddress(characterFromID("Spanish_Captain1"), "None", "");
			LAi_QuestDelay("StartAdventure", 0.0);
		break;

		PChar.questnotfound = true; // PB: Testing
	}
}
