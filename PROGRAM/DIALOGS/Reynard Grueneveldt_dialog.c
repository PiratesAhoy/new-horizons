void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar = GetMainCharacter();
	int iTest;

	switch(Dialog.CurrentNode)
	{
		// ----------------------------------- Диалог первый - первая встреча
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\REGR\REGR001";

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "talk_1";

			NextDiag.TempNode = "second time";
		break;

		case "talk_1":
			Dialog.snd = "voice\REGR\REGR002";
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3] + GetMyFullName(PChar) + DLG_TEXT[4] + GetMyShipNameShow(PChar) + DLG_TEXT[5];
			link.l1.go = "talk_2";
		break;

		case "talk_2":
			Dialog.snd = "voice\REGR\REGR003";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "quests";
			link.l99 = DLG_TEXT[8];
			link.l99.go = "talk_3";
		break;

		case "talk_3":
			Dialog.snd = "voice\REGR\REGR004";
			Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_TITLE, false, false)); // KK
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "exit";
		break;

		case "second time":
			Dialog.snd = "voice\REGR\REGR005";
			Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_TITLE, false, false)); // KK
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "quests";
			link.l99 = DLG_TEXT[13];
			link.l99.go = "exit";
		break;

		case "quests":
			iTest = 0;
			Dialog.snd = "voice\REGR\REGR006";
			Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_TITLE, false, false)); // KK
			dialog.text = DLG_TEXT[14];
			if (CheckQuestAttribute("ANIMISTS", "begin") && iTest < QUEST_COUNTER)
			{
				link.l1 = DLG_TEXT[15];
				Link.l1.go = "ANIMISTS_1";
				iTest = iTest + 1;
			}
			if (CheckQuestAttribute("ANIMISTS", "completed") && GetAttribute(npchar, "quest.ANIMISTS") != "completed" && iTest < QUEST_COUNTER)
			{
				link.l1 = DLG_TEXT[16];
				link.l1.go = "ANIMISTS_completed";
			}
			if (characters[GetCharacterIndex("Toff Oremans")].quest.daughter == "help_begin" && iTest < QUEST_COUNTER)
			{
				link.l2 = DLG_TEXT[17];
				link.l2.go = "daughter_1";
			}
			if (characters[GetCharacterIndex("Toff Oremans")].quest.daughter == "good_2_complete" || characters[GetCharacterIndex("Toff Oremans")].quest.daughter == "almost_complete")
			{
				link.l2 = DLG_TEXT[18];
				link.l2.go = "daughter_5";
			}
			link.l99 = DLG_TEXT[19];
			link.l99.go = "exit";
		break;

		case "ANIMISTS_completed":
			Dialog.snd = "voice\REGR\REGR007";
			Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_TITLE, false, false)); // KK
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
			npchar.quest.ANIMISTS = "completed";
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2800);
				AddPartyExpChar(pchar, "Sneak", 28);
			}
			else { AddPartyExp(pchar, 2800); }
			PlayStereoSound("INTERFACE\took_item.wav"); // PB: Play sound
			AddMoneyToCharacter(pchar, 15000); // PB: Add reward
		break;

		case "daughter_1":
			Dialog.snd = "voice\REGR\REGR008";
			dialog.text = DLG_TEXT[22];
			Preprocessor_Add("Bernardo Gamboa", GetCharacterFullName("Bernardo Gamboa")); // KK
			Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_TITLE, false, false)); // KK
			link.l1 = DLG_TEXT[23];
			link.l1.go = "daughter_2";
		break;

		case "daughter_2":
			Dialog.snd = "voice\REGR\REGR009";
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "daughter_3";
		break;

		case "daughter_3":
			Dialog.snd = "voice\REGR\REGR010";
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "daughter_4";
		break;

		case "daughter_4":
			Dialog.snd = "voice\REGR\REGR011";
			AddQuestRecord("daughter", 2); // PB: Must be BEFORE the Preprocessor_Add line for that one to still work
			characters[GetCharacterIndex("Toff Oremans")].quest.daughter = "governor";
			Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_TITLE, false, false)); // KK
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "exit";
		break;

		case "daughter_5":
			Dialog.snd = "voice\REGR\REGR012";
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "daughter_6";
		break;

		case "daughter_6":
			Dialog.snd = "voice\REGR\REGR013";
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "daughter_7";
		break;

		case "daughter_7":
			Dialog.snd = "voice\REGR\REGR014";
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "exit";
			AddQuestRecord("daughter", 5);
			if (characters[GetCharacterIndex("Toff Oremans")].quest.daughter == "almost_complete")
			{
				closeQuestHeader("daughter");
				characters[GetCharacterIndex("Toff Oremans")].quest.daughter = "almost_2_complete";
			}
			characters[GetCharacterIndex("Toff Oremans")].quest.daughter = "bad_2_complete";
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 4500);
				AddPartyExpChar(pchar, "Sneak", 45);
			}
			else { AddPartyExp(pchar, 4500); }
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, 850);
		break;

		case "ANIMISTS_1":
			Dialog.snd = "voice\REGR\REGR015";
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "ANIMISTS_2";
		break;

		case "ANIMISTS_2":
			Dialog.snd = "voice\REGR\REGR016";
			Preprocessor_Add("person", PChar.sex);
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "ANIMISTS_3";
		break;

		case "ANIMISTS_3":
			Dialog.snd = "voice\REGR\REGR017";
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "ANIMISTS_4";
		break;

		case "ANIMISTS_4":
			Dialog.snd = "voice\REGR\REGR018";
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "ANIMISTS_5";
			link.l2 = DLG_TEXT[46];
			link.l2.go = "ANIMISTS_denied";
			pchar.quest.ANIMISTS = "denied";
			pchar.quest.exit_from_douwesen_townhall.win_condition.l1 = "location";
			pchar.quest.exit_from_douwesen_townhall.win_condition.l1.location = "Douwesen_town";
			pchar.quest.exit_from_douwesen_townhall.win_condition = "exit_from_douwesen_townhall_complete";
		break;

		case "ANIMISTS_5":
			Dialog.snd = "voice\REGR\REGR019";
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "exit";
			pchar.quest.ANIMISTS = "to_douwesen_tavern";
			AddQuestRecord("ANIMISTS", 3);
			ChangeCharacterAddressGroup(&characters[GetCharacterIndex("Gheraed Drabbe")], "Douwesen_tavern", "sit", "sit5");
		break;

		case "ANIMISTS_denied":
			AddQuestRecord("ANIMISTS", 2);
			CloseQuestHeader("ANIMISTS");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "gov_1":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[134];
			link.l1 = DLG_TEXT[135];
			link.l1.go = "gov_2";
		break;

		case "gov_2":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[136];
			link.l1 = DLG_TEXT[137];
			link.l1.go = "gov_3";
			TakeItemFromCharacter(pchar, "Letter_Governor");
		break;

		case "gov_3":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[138];
			link.l1 = DLG_TEXT[139];
			link.l1.go = "gov_4";
		break;

		case "gov_4":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[140];
			link.l1 = DLG_TEXT[141];
			link.l1.go = "gov_5";
		break;

		case "gov_5":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[142];
			link.l1 = DLG_TEXT[143];
			link.l1.go = "gov_6";
		break;

		case "gov_6":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[144];
			link.l1 = DLG_TEXT[145];
			link.l1.go = "gov_7";
		break;

		case "gov_7":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[146];
			link.l1 = DLG_TEXT[147];
			link.l1.go = "gov_8";
		break;

		case "gov_8":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[148];
			link.l1 = DLG_TEXT[149];
			link.l1.go = "gov_9";
		break;

		case "gov_9":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[150];
			link.l1 = DLG_TEXT[151];
			link.l1.go = "exit";
			AddDialogExitQuest("dehors_townhall");
		break;

		case "kapitein_arrest1":
			link.l1 = GetMyFullName(CharacterFromID("Reynard Grueneveldt")) + DLG_TEXT[153];
			if (PChar.model == Nations[HOLLAND].fantomModel.m0)
			{
				dialog.text = DLG_TEXT[152];
				link.l1.go = "kapitein_arrest2";
			}
			else
			{
				dialog.text = DLG_TEXT[0];
				link.l1.go = "kapitein_rumbled";
			}
		break;

		case "kapitein_arrest2":
			dialog.text = DLG_TEXT[154];
			link.l1 = DLG_TEXT[155];
			link.l1.go = "kapitein_arrest3";
		break;

		case "kapitein_arrest3":
			dialog.text = DLG_TEXT[156];
			link.l1 = DLG_TEXT[157];
			link.l1.go = "kapitein_arrest4";
		break;

		case "kapitein_arrest4":
			dialog.text = DLG_TEXT[158];
			link.l1 = DLG_TEXT[159];
			AddDialogExitQuest("kapitein_goto_chest");
			link.l1.go = "exit";
		break;

		case "kapitein_rumbled":
			Preprocessor_Add("person", PChar.sex);
			dialog.text = DLG_TEXT[160];
			link.l1 = DLG_TEXT[161];
			AddDialogExitQuest("kapitein_busted");
			link.l1.go = "exit";
		break;

		case "kapitein_trial1":
			dialog.text = GetMyFullName(PChar) + DLG_TEXT[162];
			link.l1 = DLG_TEXT[163];
			link.l1.go = "kapitein_trial2";
		break;

		case "kapitein_trial2":
			Preprocessor_Add("person", XI_ConvertString(PChar.sex));
			dialog.text = DLG_TEXT[164] + GetMySimpleName(CharacterFromID("drunk_soldier")) + DLG_TEXT[165];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "kapitein_trial3":
			Preprocessor_Add("person", XI_ConvertString(PChar.sex));
			Preprocessor_Add("pronoun2", XI_ConvertString(GetMyPronounPossessive(PChar)));
		//	if (PChar.sex == "woman") Preprocessor_Add("pronoun2", XI_ConvertString("her"));
		//	else Preprocessor_Add("pronoun2", XI_ConvertString("his"));
			dialog.text = DLG_TEXT[166] + GetMySimpleName(CharacterFromID("assisting_soldier")) + DLG_TEXT[167];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "kapitein_trial4":
			dialog.text = "";
			link.l1 = DLG_TEXT[168] + GetMySimpleName(CharacterFromID("assisting_soldier")) + DLG_TEXT[169];
			link.l1.go = "kapitein_end_trial";
		break;

		case "kapitein_end_trial":
			dialog.text = DLG_TEXT[170];
			link.l1 = DLG_TEXT[171];
			link.l1.go = "exit";
		break;

		case "kapitein_pardon":
			dialog.text = DLG_TEXT[172] + GetMySimpleName(PChar) + DLG_TEXT[173];
			link.l1 = DLG_TEXT[174];
			link.l1.go = "kapitein_pardon2";
		break;

		case "kapitein_pardon2":
			dialog.text = DLG_TEXT[175];
			link.l1 = DLG_TEXT[176];
			link.l1.go = "kapitein_pardon3";
		break;

		case "kapitein_pardon3":
			dialog.text = DLG_TEXT[177];
			link.l1 = DLG_TEXT[178];
			link.l1.go = "exit";
		break;
	}
}
