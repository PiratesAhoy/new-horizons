void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar = GetMainCharacter();

	switch(Dialog.CurrentNode)
	{
		// ----------------------------------- |иалог первый - первая встреча
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			dialog.text = DLG_TEXT[0] + GetMyFullName(NPChar) + DLG_TEXT[1] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[2];		// changed from .spa to .por by KAM
			Link.l1 = DLG_TEXT[3] + GetMyFullName(PChar) + DLG_TEXT[4];
			Link.l1.go = "node_1";
			NextDiag.TempNode = "First time";
		break;

		case "node_1":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "quests";
			link.l2 = DLG_TEXT[10] + GetCharacterAddressForm(NPChar, ADDR_TITLE, false, false) + ".";
			link.l2.go = "node_2";
		break;

		case "node_2":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "exit";
		break;

		case "quests":
			dialog.text = DLG_TEXT[13] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[14];		// changed from .spa to .por by KAM
			if (CheckQuestAttribute("nigel_con_parri_checker", "win_win") || CheckQuestAttribute("nigel_con_parri_checker", "win"))
			{
				link.l2 = DLG_TEXT[15];
				link.l2.go = "garri";
			}
			link.l99 = DLG_TEXT[16];
			link.l99.go = "exit";
		break;

		case "garri":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "garri_2";
		break;

		case "garri_2":
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			if (CheckQuestAttribute("nigel_con_parri_checker", "win_win"))
			{
				link.l1.go = "garri_3";
			}
			else
			{
				link.l1.go = "exit";
			}
			AddQuestrecord("nigel", 15);
			DeleteAttribute(PChar, "quest.nigel_con_parri_checker");
			PChar.quest.con_parri_expired.over = "yes";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, 3000);
			ChangeCharacterReputation(pchar, 1);
			AddDialogExitQuest("nigel_third_encounter");
		break;

		case "garri_3":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "garri_4";
		break;

		case "garri_4":
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "exit";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, 6000);
			ChangeCharacterReputation(pchar, 1);
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "j_day":
			dialog.text = GetMyFullName(PChar) + DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "continue1";
		break;

		case "continue1":
			LAi_QuestDelay("ex_dialog", 2);
			DialogExit();
			NextDiag.CurrentNode = "j_day2";
		break;

		case "j_day2":
			dialog.text = GetMyFullName(PChar) + DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "exit";
		break;

		case "gov_1":
			dialog.text = DLG_TEXT[91];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "exit";
		    GiveItem2Character(Pchar, "Medal_B");
			AddDialogExitQuest("BenavidesBis_forte");
		break;

		case "gov_2":
			dialog.text = DLG_TEXT[92];
			link.l1 = DLG_TEXT[93];
			link.l1.go = "gov_3";
		break;

		case "gov_3":
			dialog.text = DLG_TEXT[94];
			link.l1 = DLG_TEXT[95];
			link.l1.go = "gov_4";
		break;

		case "gov_4":
			dialog.text = DLG_TEXT[96];
			link.l1 = DLG_TEXT[97];
			link.l1.go = "gov_5";
		    GiveItem2Character(Pchar, "Medal_A");
		break;

		case "gov_5":
			dialog.text = DLG_TEXT[98];
			link.l1 = DLG_TEXT[99];
			link.l1.go = "gov_6";
		break;

		case "gov_6":
			dialog.text = DLG_TEXT[100];
			link.l1 = DLG_TEXT[101];
			link.l1.go = "gov_7";
		break;

		case "gov_7":
			dialog.text = DLG_TEXT[102];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "gov_8";
		break;

		case "gov_8":
			dialog.text = DLG_TEXT[104];
			link.l1 = DLG_TEXT[105];
			link.l1.go = "exit";
			AddDialogExitQuest("recevoir_recompensebis4");
		break;
	}
}
