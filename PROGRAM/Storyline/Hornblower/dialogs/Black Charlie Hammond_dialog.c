//#include "DIALOGS\Captain Horatio Hornblower_dialog.h"
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

	string voice_path = "VOICE\ENGLISH\";
	if (CheckDirectory("RESOURCE\Sounds\VOICE\"+LanguageGetLanguage()+"\","*") > 0) voice_path = "VOICE\" + LanguageGetLanguage() + "\";

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
			PlaySound(voice_path + "Hammond16.wav");
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "Hammond_exam_one":
			PlaySound(voice_path + "Hammond01.wav");
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Examination_one2";
		break;

		case "Examination_one2":
			PlaySound(voice_path + "Hammond02.wav");
			dialog.text = DLG_TEXT[4];
			link.l1.go = "Exit_Ham_Exam_one";
		break;

		case "Exit_Ham_Exam_one":
			AddDialogExitQuest("Now_Foster_two");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Hammond_exam_two":
			PlaySound(voice_path + "Hammond03.wav");
			dialog.text = DLG_TEXT[5];
//			link.l1 = DLG_TEXT[5] + GetMyFullName(PChar) + DLG_TEXT[6];
			link.l1.go = "Exit_Ham_Exam_two";
		break;

		case "Exit_Ham_Exam_two":
			AddDialogExitQuest("General_Alarm");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Implying_what":
			PlaySound(voice_path + "Hammond04.wav");
			dialog.text = DLG_TEXT[22];
			link.l1.go = "Exit_Implying_what";
		break;

		case "Exit_Implying_what":
			AddDialogExitQuest("Captains_argue2");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Offensive_remark":
			PlaySound(voice_path + "Hammond05.wav");
			dialog.text = DLG_TEXT[23];
			link.l1.go = "Exit_Offensive_remark";
		break;

		case "Exit_Offensive_remark":
			AddDialogExitQuest("Captains_argue4");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "appology":
			PlaySound(voice_path + "Hammond06.wav");
			dialog.text = DLG_TEXT[24];
			link.l1.go = "Exit_appology";
		break;

		case "Exit_appology":
			AddDialogExitQuest("Captains_argue6");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "continue_further":
			PlaySound(voice_path + "Hammond07.wav");
			dialog.text = DLG_TEXT[25];
			link.l1.go = "Exit_continue_further";
		break;

		case "Exit_continue_further":
			AddDialogExitQuest("Captains_argue8");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "recompense":
			PlaySound(voice_path + "Hammond08.wav");
			dialog.text = DLG_TEXT[26];
			link.l1.go = "Exit_recompense";
		break;

		case "Exit_recompense":
			AddDialogExitQuest("Captains_argue10");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "send_second":
			PlaySound(voice_path + "Hammond09.wav");
			dialog.text = DLG_TEXT[27];
			link.l1.go = "Exit_send_second";
		break;

		case "Exit_send_second":
			AddDialogExitQuest("Captains_argue12");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Court_Martial_two":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Court_Martial_two2";
		break;

		case "Court_Martial_two2":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Exit_Court_Martial_two";
		break;

		case "Exit_Court_Martial_two":
			AddDialogExitQuest("The_Court_Martial_Begins5");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Before_meeting_parker":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[19] + pchar.lastname + DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Exit_before_Parker";
		break;

		case "outside_the_gates":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[22] + pchar.lastname + DLG_TEXT[23] + pchar.lastname;
			link.l1 = DLG_TEXT[24];
			link.l1.go = "Exit_before_Residence";
		break;

		case "You're_decommissioned":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "You're_decommissioned2";
		break;

		case "You're_decommissioned2":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "You're_decommissioned3";
		break;

		case "You're_decommissioned3":
			PlaySound(voice_path + "Hammond10.wav");
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "Exit_You're_decommissioned";
		break;

		case "Exit_You're_decommissioned":
			AddDialogExitQuest("Find_lodgings");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Hammond_and_Nephew":
			PlaySound(voice_path + "Hammond11.wav");
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Hammond_and_Nephew2";
		break;

		case "Hammond_and_Nephew2":
			PlaySound(voice_path + "Hammond12.wav");
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Exit_Hammond_and_Nephew";
		break;

		case "Exit_Hammond_and_Nephew":
			AddDialogExitQuest("Which_Captain_would_you_join");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit":
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_new_orders":
			AddDialogExitQuest("Sir_Peter_Parker");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_before_Parker":
			AddDialogExitQuest("Things_to_do_first2");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_before_Residence":
			AddDialogExitQuest("Meet_again_Nelson3");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Put_Down":
			PlaySound(voice_path + "Hammond13.wav");
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "Exit_Put_Down";
		break;

		case "Exit_Put_Down":
			AddDialogExitQuest("Pellew_buts_in");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "I_must_insist":
			PlaySound(voice_path + "Hammond14.wav");
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Exit_I_must_insist";
		break;

		case "Exit_I_must_insist":
			AddDialogExitQuest("Pellew_puts_down");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Include_Jack":
			PlaySound(voice_path + "Hammond15.wav");
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "Exit_Include_Jack";
		break;

		case "Exit_Include_Jack":
			AddDialogExitQuest("Hammond_dismissed");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Surrender_time":
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "Surrender_time2";
		break;

		case "Surrender_time2":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "Exit_Surrender_time";
		break;

		case "Exit_Surrender_time":
			AddDialogExitQuest("Hammond_Wolfe_join");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Surrender_easy":
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "Exit_Surrender_easy";
		break;

		case "Exit_Surrender_easy":
			AddDialogExitQuest("Hornblower_and_picklock");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Deal_with_them":
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "Deal_with_them2";
		break;

		case "Deal_with_them2":
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "Deal_with_them3";
		break;

		case "Deal_with_them3":
			dialog.text = DLG_TEXT[43];
//			link.l1 = DLG_TEXT[40];
			link.l1.go = "Exit_Deal_with_them";
		break;

		case "Exit_Deal_with_them":
			AddDialogExitQuest("Hotspur_crew_arrives");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "What_have_I_done":
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "What_have_I_done2";
		break;

		case "What_have_I_done2":
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "What_have_I_done3";
		break;

		case "What_have_I_done3":
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "Exit_What_have_I_done";
		break;

		case "Exit_What_have_I_done":
			AddDialogExitQuest("Walk_to_death");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Stop_Sir":
			PlaySound(voice_path + "Hammond17.wav");
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "Exit_Stop_Sir";
		break;

		case "Exit_Stop_Sir":
			AddDialogExitQuest("Hammond Suicide4");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

	}
}

