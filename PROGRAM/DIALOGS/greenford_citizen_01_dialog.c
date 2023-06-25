//#include "DIALOGS\greenford_citizen_01_dialog.h"

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
			
			dialog.snd = "Voice\GRCZ\GRCZ001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			if (pchar.quest.main_line == "to_oxbay_by_prisoner_escape")
			{
				dialog.snd = "Voice\GRCZ\GRCZ002";
				Dialog.Text = DLG_TEXT[2] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[3];
				Link.l1 = DLG_TEXT[4];
				Link.l1.go = "researcher_2";
			}

			NextDiag.TempNode = "first time";
		break;

		case "researcher_2":
			dialog.snd = "Voice\GRCZ\GRCZ003";
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "researcher_3";
		break;

		case "researcher_3":
			dialog.snd = "Voice\GRCZ\GRCZ004";
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "researcher_4";
		break;

		case "researcher_4":
			dialog.snd = "Voice\GRCZ\GRCZ005";
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "researcher_5";
		break;

		case "researcher_5":
			dialog.snd = "Voice\GRCZ\GRCZ006";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "researcher_6";
		break;

		case "researcher_6":
			dialog.snd = "Voice\GRCZ\GRCZ007";
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "researcher_7";
		break;

		case "researcher_7":
			dialog.snd = "Voice\GRCZ\GRCZ008";
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "researcher_8";
		break;

		case "researcher_8":
			dialog.snd = "Voice\GRCZ\GRCZ009";
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "researcher_9";
		break;

		case "researcher_9":
			SetQuestHeader("resque_researcher");
			dialog.snd = "Voice\GRCZ\GRCZ010";
			dialog.text = DLG_TEXT[19] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[20])]) + DLG_TEXT[21];
			link.l1 = DLG_TEXT[22] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[23])]) + DLG_TEXT[24];
			link.l1.go = "researcher_good";
			link.l2 = DLG_TEXT[25];
			link.l2.go = "researcher_bad";
		break;

		case "researcher_good":
			dialog.snd = "Voice\GRCZ\GRCZ011";
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "researcher_good_exit";
		break;

		case "researcher_good_exit":
			DialogExit();
			AddDialogExitQuest("greenford_citizen_01_researcher_good_exit");
		break;

		case "researcher_bad":
			dialog.snd = "Voice\GRCZ\GRCZ012";
			Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false));
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "researcher_bad_exit";
			link.l2 = DLG_TEXT[30];
			link.l2.go = "researcher_good";
		break;

		case "researcher_bad_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("greenford_citizen_01_researcher_bad_exit");
		break;
	
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
