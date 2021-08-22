//#include "DIALOGS\Bartholomew Roberts_dialog.h"
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
			
			dialog.snd = "Voice\ARSI\ARSI001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "a_place_to_stay":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "a_place_to_stay2";
		break;


		case "a_place_to_stay2":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "a_place_to_stay3";
		break;

		case "a_place_to_stay3":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "a_place_to_stay4";
		break;

		case "a_place_to_stay4":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Exit_a_place_to_stay";
		break;

		case "Exit_a_place_to_stay":
			AddDialogExitQuest("Meet_Maria");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Maria_introduced":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "Exit_Maria_introduced";
		break;

		case "Exit_Maria_introduced":
			AddDialogExitQuest("Maria_speaks");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit":
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Bush_will_stay":
			PlaySound("VOICE\ENGLISH\Mason01.wav");
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "Bush_will_stay2";
		break;

		case "Bush_will_stay2":
			PlaySound("VOICE\ENGLISH\Mason02.wav");
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "Exit_Bush_will_stay";
		break;

		case "Exit_Bush_will_stay":
			AddDialogExitQuest("Bush_Pays_up");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "owes_fifteen":
			PlaySound("VOICE\ENGLISH\Mason03.wav");
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "Exit_owes_fifteen";
		break;

		case "Exit_owes_fifteen":
			AddDialogExitQuest("Maria_chimes_in");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Time_daydreaming":
			PlaySound("VOICE\ENGLISH\Mason04.wav");
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "Exit_Time_daydreaming";
		break;

		case "Exit_Time_daydreaming":
			AddDialogExitQuest("Bush_to_bed");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Come_to_gloat":
			PlaySound("VOICE\ENGLISH\Mason05.wav");
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit_Come_to_gloat";
		break;

		case "Exit_Come_to_gloat":
			AddDialogExitQuest("Maria_behind_bars");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "She_wept":
			PlaySound("VOICE\ENGLISH\Mason06.wav");
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "She_wept2";
		break;

		case "She_wept2":
			PlaySound("VOICE\ENGLISH\Mason07.wav");
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "She_wept3";
		break;

		case "She_wept3":
			PlaySound("VOICE\ENGLISH\Mason08.wav");
			dialog.text = DLG_TEXT[24];
//			link.l1 = DLG_TEXT[21];
			link.l1.go = "Exit_She_wept";
		break;

		case "Exit_She_wept":
			AddDialogExitQuest("Gone_and_done_it");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Prepare_for_wedding":
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "Prepare_for_wedding2";
		break;

		case "Prepare_for_wedding2":
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "Exit";
		break;

		case "go_home":
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "first_names";
		break;

		case "first_names":
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "Exit";
		break;

		case "leave_them_alone":
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "Exit";
		break;

		case "sad_news1":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "sad_news2";
		break;

		case "sad_news2":
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "sad_news3";
		break;

		case "sad_news3":
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			GiveItem2Character(PChar, "MariasLetter");
			link.l1.go = "where_child";
		break;

		case "where_child":
			dialog.text = DLG_TEXT[41];
			link.l1 = "...";
			AddDialogExitQuest("upstairs_to_kid");
			link.l1.go = "exit";
		break;

		case "fine_boy":
			dialog.text = "";
			link.l1 = DLG_TEXT[42];
			link.l1.go = "read_letter";
		break;

		case "read_letter":
			dialog.text = DLG_TEXT[43];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "in_the_dark":
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "messenger_letter";
		break;

		case "messenger_letter":
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "report_to_HQ";
		break;

		case "report_to_HQ":
			dialog.text = DLG_TEXT[48];
			link.l1 = "";
			link.l1.go = "exit";
		break;
	}
}

