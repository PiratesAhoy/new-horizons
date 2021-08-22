//#include "DIALOGS\Greenford Commander_dialog.h"

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
			Dialog.defAni = "Gov_Dialog_1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Gov_Dialog_2";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\GRCO\GRCO001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			if (pchar.quest.Jacks_early_days == "now_in_prison")
			{
				dialog.snd = "Voice\GRCO\GRCO003";
				dialog.text = DLG_TEXT[2];
				Link.l1 = DLG_TEXT[3];
				Link.l1.go = "now_in_prison_2";
			}
			if (pchar.quest.Jacks_early_days == "second_narrow_squeak" && GetAttribute(pchar, "Jack") != "1")
			{
				dialog.snd = "Voice\GRCO\GRCO003";
				dialog.text = DLG_TEXT[8];
				Link.l1 = DLG_TEXT[9];
				Link.l1.go = "still_in_prison";
			}
			if (CheckQuestAttribute("ANIMISTS", "to_prison_for_teacher_3"))
			{
				link.l1 = DLG_TEXT[46];
				link.l1.go = "freedom_letter";
			}
			if (CheckQuestAttribute("ANIMISTS", "to_prison_for_teacher"))
			{
				link.l1 = DLG_TEXT[47];
				link.l1.go = "dopros";
			}
			if (CheckQuestAttribute("ANIMISTS", "raskainye"))
			{
				dialog.snd = "Voice\GRCO\GRCO002";
				dialog.text = DLG_TEXT[48];
				link.l1 = DLG_TEXT[49];
				link.l1.go = "exit";
				pchar.quest.ANIMISTS = "dopros";
			}
		break;

		case "dopros":
			dialog.snd = "Voice\GRCO\GRCO003";
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "dopros_2";
		break;

		case "dopros_2":
			dialog.snd = "Voice\GRCO\GRCO004";
			dialog.text = DLG_TEXT[53];
			if (CalcCharacterSkill(pchar, SKILL_LEADERSHIP) > 3)
			{
				link.l1 = DLG_TEXT[54];
				link.l1.go = "dopros_3";
			}
			link.l2 = DLG_TEXT[55];
			link.l2.go = "dopros_bad";
		break;

		case "dopros_3":
			if (CalcCharacterSkill(pchar, SKILL_LEADERSHIP) > 5)
			{
				dialog.snd = "Voice\GRCO\GRCO005";
				dialog.text = DLG_TEXT[56];
				link.l1 = DLG_TEXT[57];
				link.l1.go = "exit";
				pchar.quest.ANIMISTS = "dopros";
				AddDialogExitQuest("mystery_man_to_prison");
				AddQuestRecord("Sao Feng", "31");
			}
			else
			{
				dialog.snd = "Voice\GRCO\GRCO006";
				dialog.text = DLG_TEXT[58];
				link.l1 = DLG_TEXT[59];
				link.l1.go = "dopros_4";
			}
		break;

		case "dopros_4":
			dialog.snd = "Voice\GRCO\GRCO007";
			dialog.text = DLG_TEXT[60];
			if (makeint(pchar.money >= 5000))
			{
				link.l1 = DLG_TEXT[61];
				link.l1.go = "money_good";
			}
			link.l2 = DLG_TEXT[62];
			link.l2.go = "dopros_bad";
		break;

		case "dopros_bad":
			dialog.snd = "Voice\GRCO\GRCO008";
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "dopros_bad_2";
			link.l2 = DLG_TEXT[65];
			link.l2.go = "exit";
			AddQuestRecord("Sao Feng", "28");
		break;

		case "dopros_bad_2":
			dialog.snd = "Voice\GRCO\GRCO009";
			dialog.text = DLG_TEXT[66];
			link.l1 = DLG_TEXT[67];
			link.l1.go = "dopros_bad_3";
			AddQuestRecord("Sao Feng", "29");
		break;

		case "dopros_bad_3":
			dialog.snd = "Voice\GRCO\GRCO010";
			dialog.text = DLG_TEXT[68];
			link.l1 = DLG_TEXT[69];
			link.l1.go = "exit";
			AddDialogExitQuest("prison_commander_captured");
		break;

		case "money_good":
			AddMoneyToCharacter(pchar, -5000);
			dialog.snd = "Voice\GRCO\GRCO011";
			dialog.text = DLG_TEXT[70];
			link.l1 = DLG_TEXT[71];
			link.l1.go = "exit";
			pchar.quest.ANIMISTS = "dopros";
			AddDialogExitQuest("mystery_man_to_prison");
			AddQuestRecord("Sao Feng", "30");
		break;

		case "freedom_letter":
			dialog.snd = "Voice\GRCO\GRCO012";
			dialog.text = DLG_TEXT[72];
			link.l1 = DLG_TEXT[73];
			link.l1.go = "exit";
			pchar.quest.ANIMISTS = "freedom_letter";
			TakeItemFromCharacter(PChar,"letter_prison");	// GR: you gave the letter to the commandant
			AddDialogExitQuest("mystery_man_to_prison");
		break;

		case "now_in_prison_2":
			dialog.snd = "Voice\GRCO\GRCO015";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "now_in_prison_3";
		break;

		case "now_in_prison_3":
			dialog.snd = "Voice\GRCO\GRCO016";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit_now_in_prison";
		break;

		case "Exit_now_in_prison":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("soldier_speaks_up");
		break;

		case "still_in_prison":
			dialog.snd = "Voice\GRCO\GRCO015";
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "still_in_prison2";
		break;

		case "still_in_prison2":
			dialog.snd = "Voice\GRCO\GRCO015";
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "still_in_prison3";
		break;

		case "still_in_prison3":
			dialog.snd = "Voice\GRCO\GRCO015";
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "still_in_prison4";
		break;

		case "still_in_prison4":
			dialog.snd = "Voice\GRCO\GRCO015";
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "still_in_prison5";
		break;

		case "still_in_prison5":
			dialog.snd = "Voice\GRCO\GRCO015";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit_still_in_prison";
		break;

		case "Exit_still_in_prison":
			GiveItem2Character(Pchar,"jewelry2");
			GiveItem2Character(Pchar,"jewelry2");
			GiveItem2Character(Pchar,"jewelry2");
			GiveItem2Character(Pchar,"jewelry2");
			GiveItem2Character(Pchar,"jewelry2");
			GiveItem2Character(Pchar,"jewelry2");
			GiveItem2Character(Pchar,"jewelry2");
			GiveItem2Character(Pchar,"jewelry2");
			GiveItem2Character(Pchar,"jewelry2");
			GiveItem2Character(Pchar,"jewelry2");
			AddQuestRecord("My Early Days","8");
			pchar.Jack = "1";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("free_again_in_Greenford");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
