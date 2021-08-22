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

		case "got_to_Oxbay_for_refit":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "got_to_Oxbay_for_refit2";
		break;

		case "got_to_Oxbay_for_refit2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Exit_Attack_Report";
		break;

		case "Simpson_rummor":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "Exit_Simpson_Rummor";
		break;

		case "Simpson_challenged":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "Exit_Simpson_challenged";
		break;

		case "Simpson_dead":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "Exit_Simpson_dead";
		break;

		case "Simpson_death_explained":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "Exit_Simpson_death_explained";
		break;
		
		case "Exit_Attack_Report":
			pchar.quest.Battle_Bloodied = "Upstairs room fight";
			AddDialogExitQuest("Pellew buts in");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_Simpson_Rummor":
			AddDialogExitQuest("Pellew_upstairs_Again");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Continue_with_Justinian":
			PlaySound("VOICE\ENGLISH\Sawyer01.wav");
			dialog.text = DLG_TEXT[24];
			link.l1.go = "Continue_with_Justinian1";
		break;

		case "Continue_with_Justinian1":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "Continue_with_Justinian2";
		break;

		case "Continue_with_Justinian2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "Continue_with_Justinian3";
		break;

		case "Continue_with_Justinian3":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "Continue_with_Justinian4";
		break;

		case "Continue_with_Justinian4":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "Continue_with_Justinian5";
		break;

		case "Continue_with_Justinian5":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "Exit_Continue_with_Justinian";
		break;

		case "Sent_to_Jamaica":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Sent_to_Jamaica2";
		break;

		case "Sent_to_Jamaica2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "Exit_Sent_to_Jamaica";
		break;

		case "Exit_Continue_with_Justinian":
			AddDialogExitQuest("Keene_has_his_say");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Hornblower_Greenford":
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "Hornblower_Greenford2";
		break;

		case "Hornblower_Greenford2":
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "Hornblower_Greenford3";
		break;

		case "Hornblower_Greenford3":
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Hornblower_Greenford4";
		break;

		case "Hornblower_Greenford4":
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "Hornblower_Greenford5";
		break;

		case "Hornblower_Greenford5":
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "Hornblower_Greenford6";
		break;

		case "Hornblower_Greenford6":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "Exit_Hornblower_Greenford";
		break;

		case "Exit_Hornblower_Greenford":
			AddDialogExitQuest("Prepare_to_board_the_Renown");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Bush_on_board":
			PlaySound("VOICE\ENGLISH\Sawyer02.wav");
			dialog.text = DLG_TEXT[37];
			link.l1.go = "Exit_Bush_on_board";
		break;

		case "Exit_Bush_on_board":
			AddDialogExitQuest("Bush_reply1");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Bush_reported":
			PlaySound("VOICE\ENGLISH\Sawyer03.wav");
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "Bush_reported2";
		break;

		case "Bush_reported2":
			PlaySound("VOICE\ENGLISH\Sawyer04.wav");
			dialog.text = DLG_TEXT[40];
			link.l1.go = "Exit_Bush_reported";
		break;

		case "Exit_Bush_reported":
			AddDialogExitQuest("Sawyer_Buckland_question");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Get_the_ship_underway":
			PlaySound("VOICE\ENGLISH\Sawyer05.wav");
			dialog.text = DLG_TEXT[41];
			link.l1.go = "Get_the_ship_underway2";
		break;

		case "Get_the_ship_underway2":
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "Exit_Get_the_ship_underway";
		break;

		case "Exit_Get_the_ship_underway":
			AddDialogExitQuest("Ship_makes_sail");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Hoist_the_mainsail":
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "Exit_Hoist_the_mainsail";
		break;

		case "Exit_Hoist_the_mainsail":
			SetCurrentTime(01.00, 0);
			AddDialogExitQuest("Off_to_sea_Sawyer");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "So_you_want_to_get_sail_off":
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "So_you_want_to_get_sail_off2";
		break;

		case "So_you_want_to_get_sail_off2":
			dialog.text = DLG_TEXT[48];
			link.l1.go = "Exit_So_you_want_to_get_sail_off";
		break;

		case "Exit_So_you_want_to_get_sail_off":
			AddDialogExitQuest("Wellard_stops_the_hoist");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Who_countermands_my_orders":
			dialog.text = DLG_TEXT[49];
			link.l1.go = "Exit_Who_countermands_my_orders";
		break;

		case "Exit_Who_countermands_my_orders":
			AddDialogExitQuest("Wellard_in_trouble");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit":
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Wellard_is_it":
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "Wellard_is_it2";
		break;

		case "Wellard_is_it2":
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "Exit_Wellard_is_it";
		break;

		case "Exit_Wellard_is_it":
			AddDialogExitQuest("The_beating_of_Wellard");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Sail_to_Cuba":
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "Sail_to_Cuba2";
		break;

		case "Sail_to_Cuba2":
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "Sail_to_Cuba3";
		break;

		case "Sail_to_Cuba3":
			dialog.text = DLG_TEXT[56];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "Exit_Sail_to_Cuba";
		break;

		case "Exit_Sail_to_Cuba":
			AddDialogExitQuest("Bush_chimes_in");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Plotting":
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "Exit_Plotting";
		break;

		case "Exit_Plotting":
			AddDialogExitQuest("The_Doctor_Speaks2");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "I_Know_youre_here":
			dialog.text = DLG_TEXT[58];
			link.l1.go = "Exit_I_Know_youre_here";
		break;

		case "Exit_I_Know_youre_here":
			AddDialogExitQuest("Captain_falls_in_the_Hold");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_Simpson_challenged":
			AddDialogExitQuest("the_fight_starts");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_Simpson_dead":
			AddDialogExitQuest("the_future_begins");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_Simpson_death_explained":
			AddDialogExitQuest("Promotion_and_a_ship2");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_Sent_to_Jamaica":
			AddDialogExitQuest("Pellew_orders_Jamaica");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;
	}
}

