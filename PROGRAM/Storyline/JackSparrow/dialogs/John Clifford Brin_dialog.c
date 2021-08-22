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
		// -----------------------------------Диалог первый - первая встреча
		case "First time":
			Dialog.defAni = "Sit_Look_Around";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Sit_Look_Around";
			Dialog.cam = "1";

			dialog.snd = "Voice\BIBR\BIBR001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			if (pchar.quest.henry_talk == "nothing")
			{
				dialog.snd1 = "Voice\HENR\HENR020";
				dialog.snd2 = "Voice\HENR\HENR021";
				dialog.snd3 = "Voice\HENR\HENR022";
				dialog.text = DLG_TEXT[20];
				Link.l1 = DLG_TEXT[21];
				Link.l1.go = "Shortcut_exit1";
			}
		break;

		case "Talk_in_Tavern":
			dialog.snd = "Voice\BIBR\BIBR003";
			Dialog.Text = DLG_TEXT[46];
			Link.l1 = DLG_TEXT[47];
			Link.l1.go = "Exit";
		break;

		case "Reward_for_daughters":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3];
			Link.l1.go = "Reward_for_daughters2";
		break;

		case "Reward_for_daughters2":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "Reward_for_daughters3";
		break;

		case "Reward_for_daughters3":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[6];
			Link.l1 = DLG_TEXT[7];
			Link.l1.go = "Give_me_the_gold";
			Link.l2 = DLG_TEXT[8];
			Link.l2.go = "a_new_ship";
		break;

		case "Give_me_the_gold":
			dialog.snd = "Voice\BIBR\BIBR006";
			ChangeCharacterReputation(pchar, +5);
			AddMoneyToCharacter(pchar, +50000);
			Dialog.Text = DLG_TEXT[9];
			Link.l1 = DLG_TEXT[11];
			Link.l1.go = "Prepare_to_leave";
		break;

		case "a_new_ship":
			int tmpcalcgldnm = GetCargoGoods(pChar, 9);
			if ((tmpcalcgldnm >= 51) && (tmpcalcgldnm <= 1000))
			{
				dialog.snd = "Voice\BIBR\BIBR006";
				ChangeCharacterReputation(pchar, +5);
				GiveShip2Character(pchar, "HMS_Unicorn","Sparrow Hawk",-1,ENGLAND,true,true);
				SetCharacterGoods(pChar, GOOD_GOLD, 51.0);
			}
			if ((tmpcalcgldnm >= 1) && (tmpcalcgldnm <= 50))
			{
				dialog.snd = "Voice\BIBR\BIBR006";
				ChangeCharacterReputation(pchar, +5);
				GiveShip2Character(pchar, "HMS_Unicorn","Sparrow Hawk",-1,ENGLAND,true,true);
				SetCharacterGoods(pChar, GOOD_GOLD, 45.0);
			}
			if (tmpcalcgldnm <= 0)
			{
				dialog.snd = "Voice\BIBR\BIBR006";
				ChangeCharacterReputation(pchar, +5);
				GiveShip2Character(pchar, "HMS_Unicorn","Sparrow Hawk",-1,ENGLAND,true,true);
				SetCharacterGoods(pChar, GOOD_GOLD, 0.0);
			}
			Dialog.Text = DLG_TEXT[10];
			Link.l1 = DLG_TEXT[11];
			Link.l1.go = "Prepare_to_leave";
		break;

		case "Prepare_to_leave":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[14];
			Link.l1 = DLG_TEXT[15];
			Link.l1.go = "Exit_reward";
		break;

		case "Reward_for_daughters_Oxbay":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3];
			Link.l1.go = "Reward_for_daughters_Oxbay2";
		break;

		case "Reward_for_daughters_Oxbay2":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[64];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "Reward_for_daughters_Oxbay3";
		break;

		case "Reward_for_daughters_Oxbay3":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[65];
			Link.l1 = DLG_TEXT[11];
			Link.l1.go = "Prepare_to_leave_Oxbay";
			GiveShip2Character(pchar, "WickedWench","Wicked Wench",-1,ENGLAND,true,true);
			PChar.quest.wench_given_by = "Brin";
			SetCharacterShipLocation(Pchar, "Oxbay_port");
		break;

		case "Prepare_to_leave_Oxbay":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[14];
			Link.l1 = DLG_TEXT[15];
			Link.l1.go = "Exit_reward_Oxbay";
		break;

		case "Friendly_talk":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "Exit_reward";
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_reward":
			AddDialogExitQuest("Brin_leaves");
			DialogExit();
			NextDiag.CurrentNode = "Friendly_talk";
		break;

		case "Exit_reward_Oxbay":
			AddDialogExitQuest("Leave_Brin_Oxbay");
			DialogExit();
			NextDiag.CurrentNode = "Friendly_talk";
		break;

	}
}
