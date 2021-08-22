//#include "DIALOGS\Quest_ANIMISTS_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"

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
			Dialog.snd = "voice\QUSA\QUSA001";

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			if (pchar.quest.ANIMISTS == "letter_to_domingues")
			{
				Dialog.snd = "voice\QUSA\QUSA002";
				dialog.text = DLG_TEXT[2] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[3];
				link.l1 = DLG_TEXT[4];
				link.l1.go = "prepare_fight";
				link.l2 = DLG_TEXT[5];
				link.l2.go = "talk_in_shore";
			}
			if (pchar.quest.ANIMISTS == "letter_to_father_bernard")
			{
				Dialog.snd = "voice\QUSA\QUSA003";
				dialog.text = DLG_TEXT[6];
				link.l1 = DLG_TEXT[7];
				link.l1.go = "letter_to_father_bernard_2";
			}
			if (pchar.quest.ANIMISTS == "dopros")
			{
				Dialog.snd = "voice\QUSA\QUSA004";
				dialog.text = DLG_TEXT[8];
				link.l1 = DLG_TEXT[9];
				link.l1.go = "dopros_2";
			}
			if (pchar.quest.ANIMISTS == "freedom_letter")
			{
				Dialog.snd = "voice\QUSA\QUSA005";
				dialog.text = DLG_TEXT[10];
				link.l1 = DLG_TEXT[11];
				link.l1.go = "freedom_letter";
			}
			if (pchar.quest.ANIMISTS == "force_freedom")
			{
				Dialog.snd = "voice\QUSA\QUSA006";
				dialog.text = DLG_TEXT[12];
				link.l1 = DLG_TEXT[13];
				link.l1.go = "force_freedom";  // <-- Cat
				pchar.quest.exit_from_prison_with_teacher.win_condition.l1 = "ExitFromLocation";
				pchar.quest.exit_from_prison_with_teacher.win_condition.l1.location = "Greenford_prison";
				pchar.quest.exit_from_prison_with_teacher.win_condition = "exit_from_prison_with_teacher";
			}
			if (pchar.quest.ANIMISTS == "with_teacher_on_ship")
			{
				Dialog.snd = "voice\QUSA\QUSA007";
				dialog.text = DLG_TEXT[14];
				link.l1 = DLG_TEXT[15];
				link.l1.go = "with_teacher_to_muelle";
			}
			if (pchar.quest.ANIMISTS == "with_teacher_in_tavern")
			{
				Dialog.snd = "voice\QUSA\QUSA008";
				dialog.text = DLG_TEXT[16];
				link.l1 = DLG_TEXT[17];
				link.l1.go = "with_teacher_in_tavern";
			}

// Viper - Missing Children Quest Fix Begin
			if (pchar.quest.ANIMISTS == "wardendead")
			{
				dialog.text = DLG_TEXT[8];
				link.l1 = DLG_TEXT[50];
				link.l1.go = "wardendead";
			}
		break;

		case "wardendead":
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "exit";
			pchar.quest.ANIMISTS = "with_teacher_to_muelle";
			AddPassenger(Pchar, characterFromID("Teacher"), 0);
			pchar.quest.with_teacher_to_muelle.win_condition.l1 = "location";
			pchar.quest.with_teacher_to_muelle.win_condition.l1.location = "Turks";
			pchar.quest.with_teacher_to_muelle.win_condition = "with_teacher_to_muelle";
			AddQuestRecord("Sao Feng", 32);
		break;

// Viper - Missing Children Quest Fix End

		case "with_teacher_in_tavern":
			Dialog.snd = "voice\QUSA\QUSA009";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "with_teacher_in_tavern_2";
		break;

		case "with_teacher_in_tavern_2":
			Dialog.snd = "voice\QUSA\QUSA010";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
			AddQuestRecord("Sao Feng", 35);
		break;

		case "with_teacher_to_muelle":
			Dialog.snd = "voice\QUSA\QUSA011";
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "exit";

		break;

		case "freedom_letter":
			Dialog.snd = "voice\QUSA\QUSA012";
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "freedom_letter_2";
		break;

		case "freedom_letter_2":
			Dialog.snd = "voice\QUSA\QUSA013";
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "exit";
			AddDialogExitQuest("Story_freedom_letter");  // --> Cat
			pchar.quest.ANIMISTS = "with_teacher_to_muelle";
			AddPassenger(Pchar, characterFromID("Teacher"), 0);
			AddQuestRecord("Sao Feng", 32);
		break;
			
		case "dopros_2":
			Dialog.snd = "voice\QUSA\QUSA014";
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "dopros_3";
		break;

		case "dopros_3":
			Dialog.snd = "voice\QUSA\QUSA015";
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "dopros_4";
		break;

		case "dopros_4":			
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "dopros_5";
		break;

		case "dopros_5":
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "dopros_6";
			pchar.quest.ANIMISTS = "wait_for_night_in_prison";
		break;

		case "dopros_6":
			Dialog.snd = "voice\QUSA\QUSA016";
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "dopros_6a";
		break;

		case "dopros_6a":
			Dialog.snd = "voice\QUSA\QUSA016";
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "dopros_7";
		break;

		case "dopros_7":
			Dialog.snd = "voice\QUSA\QUSA017";
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "exit";
			AddDialogExitQuest("teacher_died");
			AddQuestRecord("Sao Feng", 34);
		break;

		case "letter_to_father_bernard_2":
			Dialog.snd = "voice\QUSA\QUSA018";
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "exit";
			AddDialogExitQuest("second_fight_with_ANIMISTS");
		break;

		case "talk_in_shore":
			Dialog.snd = "voice\QUSA\QUSA019";
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "prepare_fight";
			link.l2 = DLG_TEXT[44];
			link.l2.go = "talk_in_shore_2";
		break;

		case "talk_in_shore_2":
			Dialog.snd = "voice\QUSA\QUSA020";
			dialog.text = DLG_TEXT[45] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "exit";			
			AddDialogExitQuest("i_give_first_letter_to_ANIMISTS");
		break;

		case "prepare_fight":
			Dialog.snd = "voice\QUSA\QUSA021";
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "exit";
			AddDialogExitQuest("fight_with_mystery_mens_in_muelle_shore");
		break;

//  -->  Cat		
		case "force_freedom":  
			Dialog.snd = "voice\QUSA\QUSA012";
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "freedom_letter_2";
		break;
//  <-- Cat

		case "exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
