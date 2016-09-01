//#include "DIALOGS\murderer_in_greenford_01_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

	
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
			Dialog.snd = "voice\MUGR\MUGR001";

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			
			if (pchar.quest.main_line == "resque_researcher_good")
			{
				Dialog.snd = "voice\MUGR\MUGR019";
				Dialog.Text = DLG_TEXT[2];
				Link.l1 = DLG_TEXT[3];
				Link.l1.go = "bad";
				link.l2 = DLG_TEXT[4];
				link.l2.go = "good";
			}

			if (pchar.quest.main_line == "resque_researcher_bad")
			{
				Dialog.snd = "voice\MUGR\MUGR002";
				Dialog.Text = DLG_TEXT[5];
				Link.l1 = DLG_TEXT[6];
				Link.l1.go = "kick_exit";
			}

			if (pchar.quest.main_line == "resque_researcher_bad_kick")
			{
				Dialog.snd = "voice\MUGR\MUGR003";
				Dialog.Text = DLG_TEXT[7];
				Link.l1 = DLG_TEXT[8];
				Link.l1.go = "kick_2";
			}
			NextDiag.TempNode = "first time";
		break;

		case "kick_2":
			Dialog.snd = "voice\MUGR\MUGR004";
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "kick_3";
		break;

		case "kick_3":
			Dialog.snd = "voice\MUGR\MUGR005";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "kick_2_exit";
		break;

		case "kick_exit":
			//pchar.quest.kicked_by_murderer.win_condition = "kicked_by_murderer_complete";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogexitQuest("kicked_by_murderer_complete");
		break;

		case "kick_2_exit":
			AddQuestRecord("resque_researcher", 3);
			pchar.quest.killing_in_greenford = 1;
			pchar.quest.murderer = npchar.id;
			AddDialogExitQuest("kick_murderer_complete");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "good":
			Dialog.snd = "voice\MUGR\MUGR006";
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "good_2";
		break;

		case "good_2":
			Dialog.snd = "voice\MUGR\MUGR007";
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "good_money";
			link.l2 = DLG_TEXT[17] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[18])]) + DLG_TEXT[19];
			link.l2.go = "good_leadership";
			link.l3 = DLG_TEXT[20];
			link.l3.go = "bad";
		break;

		case "good_money":
			Dialog.snd = "voice\MUGR\MUGR008";
			dialog.text = DLG_TEXT[21];
			if (makeint(pchar.money) > 2000)
			{
				link.l1 = DLG_TEXT[22];
				link.l1.go = "good_money_2";
			}
			link.l2 = DLG_TEXT[23];
			link.l2.go = "good_2";
		break;

		case "good_leadership":
			if (CalcCharacterSkill(pchar, SKILL_LEADERSHIP) >= 5)
			{
				Dialog.snd = "voice\MUGR\MUGR009";
				dialog.text = DLG_TEXT[24];
				link.l1 = DLG_TEXT[25];
				link.l1.go = "good_leadership_2";
			}
			else
			{
				Dialog.snd = "voice\MUGR\MUGR010";
				dialog.text = DLG_TEXT[26];
				link.l1 = DLG_TEXT[27];
				link.l1.go = "bad";
				link.l2 = DLG_TEXT[28];
				link.l2.go = "exit";
			}
		break;

		case "good_leadership_2":
			Dialog.snd = "voice\MUGR\MUGR011";
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "good_leadership_3";
		break;

		case "good_leadership_3":
			Dialog.snd = "voice\MUGR\MUGR012";
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "good_leadership_4";
		break;

		case "good_leadership_4":
			Dialog.snd = "voice\MUGR\MUGR013";
			AddQuestRecord("resque_researcher", 4);
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "good_exit";
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1000);
				AddPartyExpChar(pchar, "Sneak", 10);
			}
			else { AddPartyExp(pchar, 1000); }
		break;

		case "good_money_2":
			Dialog.snd = "voice\MUGR\MUGR014";
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "good_money_3";
			link.l2 = DLG_TEXT[37];
			link.l2.go = "good_2";
		break;

		case "good_money_3":
			AddQuestRecord("resque_researcher", 5);
			Dialog.snd = "voice\MUGR\MUGR015";
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "good_exit";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -2000);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1000);
				AddPartyExpChar(pchar, "Sneak", 10);
			}
			else { AddPartyExp(pchar, 1000); }
		break;

		case "good_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			pchar.quest.main_line = "resque_researcher_complete";
			AddDialogExitQuest("kill_all_murderer_in_greenford_complete");
		break;

		case "bad":
			Dialog.snd = "voice\MUGR\MUGR016";
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "bad_2";
		break;

		case "bad_2":
			Dialog.snd = "voice\MUGR\MUGR017";
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "bad_3";
		break;

		case "bad_3":
			Dialog.snd = "voice\MUGR\MUGR018";
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "fight_exit";
		break;

		case "fight_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("kill_murderer_2_complete");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
