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

		case "First_meeting":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "First_meeting2";
		break;

		case "First_meeting2":
			AddDialogExitQuest("go_upstairs");
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Exit";
		break;

		case "First_meeting_Greenford":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "First_meeting_Greenford2";
		break;

		case "First_meeting_Greenford2":
			AddDialogExitQuest("Collect_new_officers4");
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Exit";
		break;

		case "Fire_ship_sighted":
			AddDialogExitQuest("Get_to_port_fire_ship");
			PlaySound("VOICE\ENGLISH\GeneralAlarm.wav");
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "Exit";
		break;

		case "Where_is_Quelp":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "Where_is_Quelp2";
		break;

		case "Where_is_Quelp2":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "Where_is_Quelp3";
		break;

		case "Where_is_Quelp3":
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "Where_is_Quelp4";
		break;

		case "Where_is_Quelp4":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "Where_is_Quelp5";
		break;

		case "Where_is_Quelp5":
			AddDialogExitQuest("Get_ready_for_Cayman");
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "Exit";
		break;

		case "Exit":
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Your_orders_Sir":
			AddDialogExitQuest("Hornblower_taken");
			PlaySound("VOICE\ENGLISH\Chadd01.wav");
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "Exit";
		break;

		case "Signal_is_Correct":
			AddDialogExitQuest("Back_to_Fort_Bomb");
			PlaySound("VOICE\ENGLISH\Chadd02.wav");
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
//			link.l1.go = "Exit_Signal_is_Correct";	// "Exit_Signal_is_Correct" does not exist
			link.l1.go = "Exit";
		break;

		case "Report_to_HQ":
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "Exit_Report_to_HQ";
		break;

		case "Exit_Report_to_HQ":
			AddDialogExitQuest("assigned_to_atropos2");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;
	}
}

