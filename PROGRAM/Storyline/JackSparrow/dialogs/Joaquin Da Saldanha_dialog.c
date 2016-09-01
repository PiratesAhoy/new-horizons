//#include "DIALOGS\Joaquin Da Saldanha_dialog.h"
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
			Dialog.snd = "dialogs\0\009";

			dialog.text  = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";

			if  (makeint(pchar.reputation) >= 0 && PChar.quest.Lucas == "")
			{
				dialog.text = DLG_TEXT[2] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[3])]) + DLG_TEXT[5];
				link.l1 = DLG_TEXT[6];
				link.l1.go = "Find_Lucas2";
			}
			if (PChar.quest.Lucas == "refused")
			{
				dialog.text = DLG_TEXT[7];
				link.l1 = DLG_TEXT[8];
				link.l1.go = "Find_Lucas5";
				link.l2 = DLG_TEXT[9];
				link.l2.go = "Find_Lucas_exit_refused";
			}
			if (PChar.quest.Lucas == "search")
			{
				dialog.text = DLG_TEXT[10];
				link.l1 = DLG_TEXT[11];
				link.l1.go = "Exit";
			}
			if (PChar.quest.Lucas == "search2")
			{
				dialog.text = DLG_TEXT[12];
				link.l1 = DLG_TEXT[13];
				link.l1.go = "Ransom_Lucas1";
			}
			if (PChar.quest.Lucas == "ransom" || "sign" || "sign1" || "sign2" || "tail" )
			{
				dialog.text = DLG_TEXT[14];
				link.l1 = DLG_TEXT[15];
				link.l1.go = "Exit";
			}
			if (PChar.quest.Lucas == "return")
			{
				dialog.text = DLG_TEXT[16];
				link.l1 = DLG_TEXT[17];
				link.l1.go = "return";
			}

		break;

		case "Find_Lucas2":

			dialog.text = DLG_TEXT[18] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[19])]) + DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Find_Lucas3";

		break;

		case "Find_Lucas3":

			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Find_Lucas4";

		break;

		case "Find_Lucas4":

			dialog.text = DLG_TEXT[24] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[25])]) + DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "Find_Lucas5";
			link.l2 = DLG_TEXT[28];
			link.l2.go = "Find_Lucas_refuse";

		break;

		case "Find_Lucas5":

			dialog.text = DLG_TEXT[29] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[30])]) + DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "Find_Lucas_exit";

		break;

		case "Find_Lucas_refuse":

			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "Find_Lucas_exit_refused";

		break;

		case "Ransom_Lucas1":

			dialog.text = DLG_TEXT[35] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[36])]) + DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "Ransom_Lucas2";

		break;

		case "Ransom_Lucas2":

			dialog.text = DLG_TEXT[39] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[40])]) + DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "Ransom_Lucas3";
			link.l2 = DLG_TEXT[43];
			link.l2.go = "Exit_ransom_refused";
		break;

		case "Ransom_Lucas3":

			dialog.text = DLG_TEXT[44] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[45])]) + DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "Ransom_Lucas_exit";

		break;

		case "return":

			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "Exit_return";

		break;

		case "Exit":

			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();

		break;

		case "Ransom_Lucas_exit":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Lucas_ransom_start");

		break;

		case "Find_Lucas_exit":

			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();

			AddDialogExitQuest("Lucas_search_start");

		break;

		case "Find_Lucas_exit_refused":

			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();

			AddDialogExitQuest("Lucas_search_refused");

		break;

		case "Exit_ransom_refused":

			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();

			AddDialogExitQuest("Lucas_ransom_refused");

		break;

		case "Exit_return":

			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();

			AddDialogExitQuest("Lucas_end");

		break;

	}
}