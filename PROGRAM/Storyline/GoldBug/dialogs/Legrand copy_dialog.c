
void ProcessDialogEvent()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	ref lcn = &Locations[FindLocation(PChar.location)];
	
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
			Dialog.snd = "voice\PADI\PADI001";
			
			PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			
			Diag.TempNode = "first time";
		break;

		case "Jup_with_wood":
			PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Jup_with_wood1";
		break;

		case "Jup_with_wood1":
			TakenItems(Pchar, "coin7", 1);
			Pchar.quest.Jupiter_coin7 = "yes";
			PlaySound("INTERFACE\coin_drop.wav");
			Dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "exit";
			AddDialogExitQuest("Jup_with_wood_done");
		break;

		case "Jup_with_paper_bug":
			PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
			Dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Jup_with_paper_bug1";
		break;

		case "Jup_with_paper_bug1":
			PlaySound("INTERFACE\paper.wav");
			PlaySound("OBJECTS\DUEL\man_attack6.wav");
			TakenItems(Pchar, "letter_paper", -1);
			TakenItems(Pchar, "goldbug2", -1);
			TakenItems(Pchar, "wrinkled_paper", 1);
			TakenItems(NPchar, "letter_paper", 1);
			TakenItems(NPchar, "goldbug", 1);

			Dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Jup_with_paper_bug2";
		break;

		case "Jup_with_paper_bug2":
			TakenItems(Pchar, "jewelry12", 1);
			TakenItems(Pchar, "jewelry12", 1);
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			PlaySound("AMBIENT\TAVERN\tinkle2.wav");
			PlaySound("AMBIENT\TAVERN\tinkle2.wav");
			Dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "Jup_with_paper_bug3";
		break;

		case "Jup_with_paper_bug3":
			PlaySound("VOICE\ENGLISH\blaze_hah.wav");
			Dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "Jup_with_paper_bug4";
		break;

		case "Jup_with_paper_bug4":
		//	PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
			PlaySound("PEOPLE\clothes1.wav");

			GiveItem2Character(characterFromID("Legrand_copy"), "bladeemptysack_B");
			RemoveCharacterEquip(characterFromID("Legrand_copy"), BLADE_ITEM_TYPE);
			EquipCharacterByItem(characterFromID("Legrand_copy"), "bladeemptysack_B");

			GiveItem2Character(Pchar, "bladeemptysack");
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			EquipCharacterByItem(Pchar, "bladeemptysack");

			Dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit";
			AddDialogExitQuest("Jup_with_paper_bug_done");
		break;

		case "plantation_meeting":
			PlaySound("VOICE\ENGLISH\blaze_very_nice.wav");
			Dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
			AddDialogExitQuest("plantation_switch");
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
