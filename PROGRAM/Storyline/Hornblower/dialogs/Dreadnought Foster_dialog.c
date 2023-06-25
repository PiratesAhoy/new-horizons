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
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "Again_More_new_Orders":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "now2";
		break;

		case "now2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5] + GetMyFullName(PChar) + DLG_TEXT[6];
			link.l1.go = "now3";
		break;

		case "now3":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "now4";
		break;

		case "now4":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "now5";
		break;

		case "now5":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "now6";
		break;

		case "now6":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "now7";
		break;

		case "now7":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "now8";
		break;

		case "now8":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "Exit_new_orders";
		break;

		case "Before_meeting_parker":
			dialog.text = DLG_TEXT[19] + Pchar.lastname + DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Exit_Before_meeting_parker";
		break;

		case "Exit_Before_meeting_parker":
			AddDialogExitQuest("Things_to_do_first2");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Foster_exam_one":
			PlaySound(voice_path + "Foster01.wav");
			dialog.text = DLG_TEXT[22];
//			link.l1 = DLG_TEXT[18];
			link.l1.go = "Exit_Foster_exam_one";
		break;

		case "Exit_Foster_exam_one":
			AddDialogExitQuest("Hammond_starts");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Foster_exam_two":
			PlaySound(voice_path + "Foster02.wav");
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "Foster_exam_two2";
		break;

		case "Foster_exam_two2":
			PlaySound(voice_path + "Foster03.wav");
			dialog.text = DLG_TEXT[25];
//			link.l1 = DLG_TEXT[24];
			link.l1.go = "Exit_Foster_exam_two";
		break;

		case "Exit_Foster_exam_two":
			AddDialogExitQuest("Hammond_again");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Got_to_get_aboard":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "Got_to_get_aboard2";
		break;

		case "Got_to_get_aboard2":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "Got_to_get_aboard3";
		break;

		case "Got_to_get_aboard3":
			dialog.text = DLG_TEXT[30];
//			link.l1 = DLG_TEXT[27];
			link.l1.go = "Exit_Got_to_get_aboard";
		break;

		case "Go_to_the_wheel":
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "Exit_go_to_the_wheel";
		break;

		case "Steering_instructions":
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "Exit_Steering_instructions";
		break;

		case "Hold_her_steady":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "Exit_Hold_her_steady";
		break;

		case "Hard_a_lea":
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[36] + DLG_TEXT[38];
			link.l1.go = "Exit_Hard_a_lea";
		break;

		case "Save_yourself_Hornblower":
			PlaySound("OBJECTS\ABORDAGE\korabl_gorit_002.wav");
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "Exit_Save_yourself_Hornblower";
		break;

		case "Where_were_you":
			PlaySound(voice_path + "Foster04.wav");
			dialog.text = DLG_TEXT[41];
			link.l1.go = "Exit_Where_were_you";
		break;

		case "Exit_Where_were_you":
			AddDialogExitQuest("Captains_argue");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "read implications":
			PlaySound(voice_path + "Foster05.wav");
			dialog.text = DLG_TEXT[42];
			link.l1.go = "Exit_read implications";
		break;

		case "Exit_read implications":
			AddDialogExitQuest("Captains_argue3");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "perspicacity":
			PlaySound(voice_path + "Foster06.wav");
			dialog.text = DLG_TEXT[43];
			link.l1.go = "Exit_perspicacity";
		break;

		case "Exit_perspicacity":
			AddDialogExitQuest("Captains_argue5");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "no_appology":
			PlaySound(voice_path + "Foster07.wav");
			dialog.text = DLG_TEXT[44];
			link.l1.go = "Exit_no_appology";
		break;

		case "Exit_no_appology":
			AddDialogExitQuest("Captains_argue7");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "your_appology":
			PlaySound(voice_path + "Foster08.wav");
			dialog.text = DLG_TEXT[45];
			link.l1.go = "Exit_your_appology";
		break;

		case "Exit_your_appology":
			AddDialogExitQuest("Captains_argue9");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "most_welcome":
			PlaySound(voice_path + "Foster09.wav");
			dialog.text = DLG_TEXT[46];
			link.l1.go = "Exit_most_welcome";
		break;

		case "Exit_most_welcome":
			AddDialogExitQuest("Captains_argue11");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Look_forward":
			PlaySound(voice_path + "Foster10.wav");
			dialog.text = DLG_TEXT[47];
			link.l1.go = "Exit_Look_forward";
		break;

		case "Exit_Look_forward":
			AddDialogExitQuest("Captains_argue13");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "staring_at":
			PlaySound(voice_path + "Foster11.wav");
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "Exit_staring_at";
		break;

		case "Exit_staring_at":
			AddDialogExitQuest("Captains_argue14");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "owe_life":
			PlaySound(voice_path + "Foster12.wav");
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "Exit_owe_life";
		break;

		case "Exit_owe_life":
			AddDialogExitQuest("Captains_leave");
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

		case "Exit_Got_to_get_aboard":
			AddDialogExitQuest("Swim_to_fire_ship");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_go_to_the_wheel":
			AddDialogExitQuest("Fire_ship_main_deck3");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_Steering_instructions":
			AddDialogExitQuest("Fire_ship_main_deck5");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_Hold_her_steady":
			AddDialogExitQuest("Fire_ship_main_deck7");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_Hard_a_lea":
			AddDialogExitQuest("Fire_ship_main_deck9");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_Save_yourself_Hornblower":
			AddDialogExitQuest("Fire_ship_main_deck11");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "You're_decommissioned":
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "You're_decommissioned2";
		break;

		case "You're_decommissioned2":
			dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];
			link.l1.go = "Exit_You're_decommissioned";
		break;

		case "Exit_You're_decommissioned":
			AddDialogExitQuest("Find_lodgings");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Cashiered":
			dialog.text = DLG_TEXT[56] + Pchar.lastname + ".";
			link.l1 = DLG_TEXT[57];
			link.l1.go = "Cashiered Two";
		break;

		case "Cashiered Two":
			dialog.text = DLG_TEXT[58] + Pchar.lastname + ".";
			link.l1 = DLG_TEXT[59];
			link.l1.go = "Cashiered Three";
		break;

		case "Cashiered Three":
			dialog.text = DLG_TEXT[60] + Pchar.lastname + ". " DLG_TEXT[60];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "Exit_Cashiered";
		break;

		case "Exit_Cashiered":
			AddDialogExitQuest("No_Longer_in_the_Navy");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

	}
}

