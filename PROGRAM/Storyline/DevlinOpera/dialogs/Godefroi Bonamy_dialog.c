//#include "DIALOGS\Godefroi Bonamy_Dialog.h"
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
			link.l1.go = "porky2";

			if (CheckQuestAttribute("BONAMY", "leadme"))
			{
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "Exit";
			}
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
			link.l1.go = "porky2";
		break;

		case "porky2":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "porky3";
		break;

		case "porky3":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "porky4";
		break;

		case "porky4":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "porky5";
		break;

		case "porky5":
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "porky6";
		break;

		case "porky6":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "porky7";
		break;

		case "porky7":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "porky8";
		break;

		case "porky8":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "porky9";
		break;

		case "porky9":
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "porky10";
		break;

		case "porky10":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "exit";
			AddDialogExitQuest("Unite_to_Beach");
		break;

		case "Le_Blaze_is_back":
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "Le_Blaze_is_back2";
		break;

		case "Le_Blaze_is_back2":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "Le_Blaze_is_back3";
		break;

		case "Le_Blaze_is_back3":
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "Le_Blaze_is_back4";
		break;

		case "Le_Blaze_is_back4":
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "exit";
			AddDialogExitQuest("To_le_Hold");
		break;

		case "Confronting_Luc":
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "exit";
			AddDialogExitQuest("Bonamy_Luc3");
		break;

		case "Confronting_Luc2":
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "exit";
			AddDialogExitQuest("Bonamy_Luc5");
		break;

		case "Confronting_Luc3":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "exit";
			AddDialogExitQuest("Bonamy_vs_Luc");
		break;

		case "Triumph":
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "Triumph2";
		break;

		case "Triumph2":
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "Triumph3";
		break;

		case "Triumph3":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "exit";
			AddDialogExitQuest("Lead_Bonamy_ashore");
		break;

		case "Y_he_attacked":
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "Y_he_attacked2";
		break;

		case "Y_he_attacked2":
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "Y_he_attacked3";
		break;

		case "Y_he_attacked3":
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "exit";
			AddDialogExitQuest("Bonamys_Last_Duel");
		break;

		case "Stop_town":
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "exit";
			AddDialogExitQuest("Stop_town2");
		break;
	}
}