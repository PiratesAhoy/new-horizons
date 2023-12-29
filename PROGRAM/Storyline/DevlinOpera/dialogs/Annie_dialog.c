//#include "DIALOGS\Annie_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();
		break;

	
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

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";

			if (CheckQuestAttribute("ANNIE", "comeswith"))
			{
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "Exit";
			}

			if (CheckQuestAttribute("ANNIE", "hired"))
			{
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "Exit";
			}

			if (CheckQuestAttribute("ANNIE", "available"))
			{
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "yesyes_Annie2";
			link.l2 = DLG_TEXT[40];
			link.l2.go = "Exit";
			}
		break;

		case "startolino":
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			AddDialogExitQuest("Father_introduces_daughter");
		break;

		case "Annie_freaking":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Annie_freaking2";
		break;

		case "Annie_freaking2":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Annie_freaking3";
		break;

		case "Annie_freaking3":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			AddDialogExitQuest("Talking_about_frogs");
		break;

		case "Annie_patrols":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Annie_patrols2";
		break;

		case "Annie_patrols2":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
			AddDialogExitQuest("to_Cayman_for_governor");
		break;

		case "Scouts_landed":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "Scouts_landed2";
		break;

		case "Scouts_landed2":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "Corsairs_by_land";
			link.l2 = DLG_TEXT[16];
			link.l2.go = "Corsairs_by_sea";
		break;

		case "Corsairs_by_land":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "Corsairs_by_land2";
		break;

		case "Corsairs_by_land2":
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "Corsairs_by_land3";
		break;

		case "Corsairs_by_land3":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "Corsairs_by_land4";
			link.l2 = DLG_TEXT[25];
			link.l2.go = "Annie_joins_ruse";
		break;

		case "Corsairs_by_land4":
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "exit";
			AddDialogExitQuest("Land_ruse_begins");
		break;

		case "Annie_joins_ruse":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "exit";
			AddDialogExitQuest("Land_ruse_begins_Annie");
		break;

		case "Scouts_ded_with_Annie":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "Scouts_ded_with_Annie2";
		break;

		case "Scouts_ded_with_Annie2":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "exit";
			AddDialogExitQuest("Kay_picks_up");
		break;

		case "Wants_Officer":
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "Wants_Officer2";
		break;

		case "Wants_Officer2":
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "exit";
			AddDialogExitQuest("KOB_confirms");
		break;

		case "Decision":
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "yesyes_Annie";
			link.l2 = DLG_TEXT[40];
			link.l2.go = "nono_Annie";
		break;

		case "yesyes_Annie":
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "exit";
			AddDialogExitQuest("Goodbye_Byrnes");
			AddDialogExitQuest("Annie_hired");
		break;

		case "yesyes_Annie2":
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "exit";
			AddDialogExitQuest("Annie_hired");
		break;

		case "nono_Annie":
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "exit";
			AddDialogExitQuest("Goodbye_Byrnes");
			AddDialogExitQuest("Annie_available");
		break;

//=============================================================

		case "Corsairs_by_sea":
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "Corsairs_by_sea2";
		break;

		case "Corsairs_by_sea2":
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "exit";
			AddDialogExitQuest("Cayman_sea_battle_setup");
		break;

	}
}