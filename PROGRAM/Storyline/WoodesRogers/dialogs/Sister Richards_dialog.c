//#include "DIALOGS\Church crew_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

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
			Dialog.snd = "voice\THDI\THDI001";

			PlaySound("VOICE\ENGLISH\Eng_f_c_001.wav");
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Richards1";
			
			Diag.TempNode = "first time";
		break;

		case "Richards1":
			PlaySound("VOICE\ENGLISH\gr_wench3_sigh.wav");
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Richards2";
		break;

		case "Richards2":
			PlaySound("VOICE\ENGLISH\Eng_f_c_003.wav");
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Richards3";
		break;

		case "Richards3":
			PlaySound("VOICE\ENGLISH\gr_wench3_angry.wav");
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Richards4";
		break;

		case "Richards4":
			PlaySound("VOICE\ENGLISH\Eng_f_c_001.wav");
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Richards5";
		break;

		case "Richards5":
	//		PlaySound("VOICE\ENGLISH\Eng_f_c_006.wav");
			PlaySound("VOICE\ENGLISH\gr_wench3_sigh.wav");
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "Richards6";
		break;

		case "Richards6":
			PlaySound("VOICE\ENGLISH\Eng_f_c_005.wav");
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "Richards7";
		break;

		case "Richards7":
			PlaySound("VOICE\ENGLISH\Eng_f_c_003.wav");
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "Richards8";
		break;

		case "Richards8":
			PlaySound("VOICE\ENGLISH\Eng_f_c_004.wav");
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
			AddDialogExitQuest("Charleston_blockade_start");
		break;

	//bb scene here --------------------------------------------------------

		case "Richards9":
			PlaySound("VOICE\ENGLISH\gr_wench3_sigh.wav");
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Richards10";
		break;

		case "Richards10":
			PlaySound("VOICE\ENGLISH\Eng_f_c_003.wav");
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Richards11";
		break;

		case "Richards11":
			PlaySound("VOICE\ENGLISH\Eng_f_c_001.wav");
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Richards12";
		break;

		case "Richards12":
			PlaySound("VOICE\ENGLISH\Eng_f_c_004.wav");
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "Richards13";
		break;

		case "Richards13":
			PlaySound("VOICE\ENGLISH\Eng_f_c_002.wav");
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "Richards14";
		break;

		case "Richards14":
			PlaySound("VOICE\ENGLISH\Eng_f_c_005.wav");
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "exit";
			AddDialogExitQuest("abbess_info_done");
		break;

		case "unlock_to_town":
			PlaySound("VOICE\ENGLISH\Eng_f_c_002.wav");
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "exit";
			AddDialogExitQuest("Sister_Richards_leaves4");
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
