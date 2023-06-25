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
		// -----------------------------------Диалог первый - первая встреча
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
			link.l2 = DLG_TEXT[8];
			link.l2.go = "talk_3";
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
			link.l5 = DLG_TEXT[13];
			link.l5.go = "exit";
		break;

		case "quests":
			itest = 0;
			Dialog.snd = "voice\REGR\REGR006";
			Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_TITLE, false, false)); // KK
			dialog.text = DLG_TEXT[14];
			if (GetAttribute(pchar,"quest.ANIMISTS") == "1" && iTest < QUEST_COUNTER)
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
			link.l99  = DLG_TEXT[19];
			link.l99.go = "exit";
		break;

		case "ANIMISTS_completed":
			Dialog.snd = "voice\REGR\REGR007";
			npchar.quest.ANIMISTS = "completed";
			LAi_type_actor_Reset(characterFromID("Sao Feng's Body1"));
			LAi_type_actor_Reset(characterFromID("Sao Feng's Body2"));
			LAi_SetStayType(characterFromID("Sao Feng's Body1"));
			LAi_SetStayType(characterFromID("Sao Feng's Body2"));
			AddMoneyToCharacter(pchar, 50000));
			AddQuestRecord("Sao Feng", 36);
			if (Characters[GetCharacterIndex("Father Bernard")].quest.ANIMISTS == "completed")
			{
				CloseQuestHeader("Sao Feng");
			}
			else
			{
				pchar.ANIMISTS = "women_returned";
			}

			pchar.quest.Teague_gives_Piece_of_8.win_condition.l1 = "location";
			pchar.quest.Teague_gives_Piece_of_8.win_condition.l1.location = "Turks_port";	//JRH: new Turks, was Turks_Town
			pchar.quest.Teague_gives_Piece_of_8.win_condition = "Teague_gives_Piece_of_8";
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2800);
				AddPartyExpChar(pchar, "Sneak", 28);
			}
			else { AddPartyExp(pchar, 2800); }
			Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_TITLE, false, false)); // KK
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
		break;

		case "ANIMISTS_1":
			Dialog.snd = "voice\REGR\REGR015";
			if (IsInServiceOf(PIRATE))
			{
				dialog.text = DLG_TEXT[38];
				link.l1 = DLG_TEXT[39];
				link.l1.go = "ANIMISTS_2";
			}
			else
			{
				dialog.text = DLG_TEXT[134];
				link.l1  = DLG_TEXT[135];
				link.l1.go = "exit";
			}
		break;

		case "ANIMISTS_2":
			Dialog.snd = "voice\REGR\REGR016";
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
			SetQuestHeader("Sao Feng");
			AddQuestRecord("Sao Feng", 3);
			AddQuestRecord("Pirate Lord", 5); 
			ChangeCharacterAddressGroup(&characters[GetCharacterIndex("Tai Huang")], "Turks_tavern", "sit", "sit5");
			SetRumourState("Sao_Feng_start", false); 
			pchar.Colours = "0";
		break;

		case "ANIMISTS_denied":
			pchar.Colours = "0";
			pchar.Sao_Feng = "NO";
			SetQuestHeader("Sao Feng");
			AddQuestRecord("Sao Feng", 2);
			CloseQuestHeader("Sao Feng");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
