//#include "DIALOGS\Redmond Soldier_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d; 
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting, TempInfoCharacterID_1, TempInfoCharacterID_2;
	int DonationSize;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
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

			PlaySound("VOICE\ENGLISH\pir_capKK.wav");
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";	
		break;

		case "outside_tailor":
			PlaySound("VOICE\ENGLISH\c_brother1B.wav");
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "outside_tailor1";
		break;

		case "outside_tailor1":
			PlaySound("VOICE\ENGLISH\gr_Hgold5.wav");
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "outside_tailor2";
		break;

		case "outside_tailor2":
			PlaySound("VOICE\ENGLISH\gr_Hgold3.wav");
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "outside_tailor3";
		break;

		case "outside_tailor3":
			PlaySound("VOICE\ENGLISH\gr_Hgold2.wav");
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "outside_tailor4";
		break;

		case "outside_tailor4":
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "outside_tailor5";
		break;

		case "outside_tailor5":
			PlaySound("VOICE\ENGLISH\gr_Hgold6.wav");
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "outside_tailor6";
		break;

		case "outside_tailor6":
			PlaySound("VOICE\ENGLISH\gr_Hgold5.wav");
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "outside_tailor7";
		break;

		case "outside_tailor7":
			PlaySound("VOICE\ENGLISH\gr_Hgold6.wav");
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "outside_tailor8";
		break;

		case "outside_tailor8":
			PlaySound("VOICE\ENGLISH\pir_capEE.wav");
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "exit";
			AddDialogExitQuest("search_ladder_to_Charleston_roofs");
		break;





		case "tailor_open":
			PlaySound("VOICE\ENGLISH\gr_Hgold4.wav");
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
			AddDialogExitQuest("unlock_Charleston_tailor2");
		break;

		case "study_open":
			PlaySound("VOICE\ENGLISH\pir_capFF.wav");
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit";
			AddDialogExitQuest("study_open_done");
		break;
	}
}
