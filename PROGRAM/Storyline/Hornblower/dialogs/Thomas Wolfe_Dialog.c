//#include "DIALOGS\Morgan Terror_Dialog.h"
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
//			NPChar.quest.meeting = NPC_Meeting;
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

			PlaySound("VOICE\ENGLISH\Wolfe01.wav");
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "Hired_at_Greenford":
			PlaySound("VOICE\ENGLISH\Wolfe01.wav");
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[2];
			link.l1.go = "Exit_Hired_at_Greenford";
		break;

		case "Exit_Hired_at_Greenford":
			AddDialogExitQuest("Wolfe's_Experience");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Sailed_the_Convoys":
			PlaySound("VOICE\ENGLISH\Wolfe02.wav");
			dialog.text = DLG_TEXT[3];
			link.l1 = DLG_TEXT[2];
			link.l1.go = "Exit_Sailed_the_Convoys";
		break;

		case "Exit_Sailed_the_Convoys":
			AddDialogExitQuest("Wolfe's_Excuse");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Pregnant_girl":
			PlaySound("VOICE\ENGLISH\Wolfe03.wav");
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[2];
			link.l1.go = "Exit_Pregnant_girl";
		break;

		case "Exit_Pregnant_girl":
			AddDialogExitQuest("Sign_here_Wolfe");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "I'll_volunteer":
			PlaySound("VOICE\ENGLISH\Wolfe04.wav");
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "Exit_I'll_volunteer";
		break;

		case "Exit_I'll_volunteer":
			AddDialogExitQuest("Hammond_volunteers");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Gotcha":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Exit_Gotcha";
		break;

		case "Exit_Gotcha":
			AddDialogExitQuest("Bush_sees_Pellew");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Capture_Soldiers":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "Exit_Capture_Soldiers";
		break;

		case "Exit_Capture_Soldiers":
			AddDialogExitQuest("Soldiers_Wolfe_BeachXXX");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Hung_you":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "Exit_Hung_you";
		break;

		case "Exit_Hung_you":
			AddDialogExitQuest("Hammond_Confesses");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "turnabout":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "escape_from_guadeloupe1";
		break;

		case "escape_from_guadeloupe1":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "escape_from_guadeloupe2";
		break;

		case "escape_from_guadeloupe2":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "whos_the_boss1";
		break;

		case "whos_the_boss1":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "whos_the_boss2";
		break;

		case "whos_the_boss2":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "exit_whos_the_boss";
		break;

		case "exit_whos_the_boss":
			AddDialogExitQuest("interrogate_wolfe2");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "good_cop":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "get_me_out1";
		break;

		case "get_me_out1":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "get_me_out2";
		break;

		case "get_me_out2":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "exit_get_me_out";
		break;

		case "exit_get_me_out":
			AddDialogExitQuest("release_wolfe");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "where_now":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "exit";
		break;
	}
}
