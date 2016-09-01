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
			Dialog.snd = "dialogs\0\009";

			dialog.text = DLG_TEXT[0] + GetMyFullName(NPChar) + DLG_TEXT[1] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[2];		// changed from .spa to .por by KAM
			Link.l1 = DLG_TEXT[3] + GetMyFullName(PChar) + DLG_TEXT[4];
			Link.l1.go = "node_1";
			NextDiag.TempNode = "First time";
		break;

		case "node_1":
			dialog.text = DLG_TEXT[8];
			Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_CIVIL, false, false)); // KK
			link.l1 = DLG_TEXT[9];
			link.l1.go = "quests";
			link.l2 = DLG_TEXT[10];
			link.l2.go = "node_2";
		break;

		case "node_2":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "exit";
		break;

		case "quests":
			if (CheckQuestAttribute("Santiago", "payergov"))
			{
				dialog.snd = "Voice\REGR\REGR007";
				dialog.Text = DLG_TEXT[70];
				link.l1 = DLG_TEXT[71];
				link.l1.go = "gov_1";
			}
			if (CheckQuestAttribute("Santiago", "paspaye") && makeint(pchar.money) >= 10000)
			{
				link.l2 = DLG_TEXT[83];
				link.l2.go = "gov_5";
			}
			link.l99 = DLG_TEXT[13];
			link.l99.go = "exit";
		break;

		case "gov_1":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[72];
			link.l1 = DLG_TEXT[84];
			link.l1.go = "gov_1_1";
		break;

		case "gov_1_1":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[85];
			link.l1 = DLG_TEXT[73];
			link.l1.go = "gov_2";
		break;

		case "gov_2":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "gov_3";
		break;

		case "gov_3":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[76];
			link.l1 = DLG_TEXT[77];
			link.l1.go = "gov_4";
		break;

		case "gov_4":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[78];
			if (makeint(pchar.money >= 10000))
			{
				link.l1 = DLG_TEXT[79];
				link.l1.go = "gov_5";
			}
			link.l2 = DLG_TEXT[80];
			link.l2.go = "exit";
			pchar.quest.santiago = "paspaye";
		break;

		case "gov_5":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -10000);
			dialog.snd = "Voice\CLLA\CLLA006";
			dialog.text = DLG_TEXT[81];
			link.l1 = DLG_TEXT[82];
			link.l1.go = "exit";
			pchar.quest.santiago = "preparation";
			AddDialogExitQuest("txikilibre");
			AddQuestRecord("Santiago", "7");
			ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "Guadeloupe_Port", "Officers", "Reload3_1");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
