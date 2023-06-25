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

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "Hornblower_for_me":
			PlaySound("VOICE\ENGLISH\JackHam01.wav");
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Hornblower_for_me2";
		break;

		case "Hornblower_for_me2":
			PlaySound("VOICE\ENGLISH\JackHam02.wav");
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit_Hornblower_for_me";
		break;

		case "Exit_Hornblower_for_me":
			AddDialogExitQuest("Pellews_Deal");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Signal_from_flagship":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Exit_Signal_from_flagship";
		break;

		case "Exit_Signal_from_flagship":
			AddDialogExitQuest("meeting_on_flagship");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Reporting_sir":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "Exit_Reporting_sir";
		break;

		case "Exit_Reporting_sir":
			AddDialogExitQuest("The_first_landing");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Semaphore_operator":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "Exit_Semaphore_operator";
		break;

		case "Exit_Semaphore_operator":
			AddDialogExitQuest("What_a_knockout");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "We_need_to_be_quick":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "Exit_We_need_to_be_quick";
		break;

		case "Exit_We_need_to_be_quick":
			AddDialogExitQuest("Who_has_the_fuses");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "It_will_take_too_long":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "Exit_It_will_take_too_long";
		break;

		case "Exit_It_will_take_too_long":
			AddDialogExitQuest("Send_Hammond_back");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "He_told_us_to_go":
			PlaySound("VOICE\ENGLISH\JackHam03.wav");
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "He_told_us_to_go2";
		break;

		case "He_told_us_to_go2":
			PlaySound("VOICE\ENGLISH\JackHam04.wav");
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Exit_He_told_us_to_go";
		break;

		case "Exit_He_told_us_to_go":
			AddDialogExitQuest("Chadd_wants_orders");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Dont_like_attitude":
			PlaySound("VOICE\ENGLISH\JackHam06.wav");
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Dont_like_attitude2";
		break;

		case "Dont_like_attitude2":
			PlaySound("VOICE\ENGLISH\JackHam07.wav");
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "Dont_like_attitude3";
		break;

		case "Dont_like_attitude3":
			PlaySound("VOICE\ENGLISH\JackHam08.wav");
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "Exit_Dont_like_attitude";
		break;

		case "Exit_Dont_like_attitude":
			AddDialogExitQuest("Interupt_for_Hotspur5");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Your_Uncle":
			PlaySound("VOICE\ENGLISH\JackHam05.wav");
			dialog.text = DLG_TEXT[28];
//			link.l1 = DLG_TEXT[27];
			link.l1.go = "Exit_Your_Uncle";
		break;

		case "Exit_Your_Uncle":
			AddDialogExitQuest("Hornblower_and_picklock2");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Withdraw_Signal_from_flagship":
			PlaySound("VOICE\ENGLISH\JackHam09.wav");
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Withdraw_Signal_from_flagship2";
		break;

		case "Withdraw_Signal_from_flagship2":
			PlaySound("VOICE\ENGLISH\JackHam10.wav");
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "Withdraw_Signal_from_flagship3";
		break;

		case "Withdraw_Signal_from_flagship3":
			PlaySound("VOICE\ENGLISH\JackHam11.wav");
			dialog.text = DLG_TEXT[33];
//			link.l1 = DLG_TEXT[27];
			link.l1.go = "Exit_Withdraw_Signal_from_flagship";
		break;

		case "Exit_Withdraw_Signal_from_flagship":
			AddDialogExitQuest("Chadd_Knows_Signal");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

			}
}
