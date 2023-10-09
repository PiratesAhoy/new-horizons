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

		case "Ships_are_fighting":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[2] + Pchar.lastname + DLG_TEXT[3];
			link.l1 = DLG_TEXT[4];
			link.l1.go = "Exit_Ships_are_fighting";
		break;

		case "Exit_Ships_are_fighting":
			AddDialogExitQuest("The_Don_Arrives");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "the_Spanish_beach":
			dialog.text = DLG_TEXT[2] + Pchar.lastname + DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "Exit_the_Spanish_beach";
		break;

		case "Exit_the_Spanish_beach":
			AddDialogExitQuest("move_up_the_beach");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "the_Spanish_have_the_ship":
			dialog.text = DLG_TEXT[2] + Pchar.lastname + DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "Exit_the_Spanish_have_the_ship";
		break;

		case "Exit_the_Spanish_have_the_ship":
			AddDialogExitQuest("Recapture_the_Renown");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "we_must_knock_out_their_cannon":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "we_must_knock_out_their_cannon2";
		break;

		case "we_must_knock_out_their_cannon2":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "we_must_knock_out_their_cannon3";
		break;

		case "we_must_knock_out_their_cannon3":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "Exit_we_must_knock_out_their_cannon";
		break;

		case "Exit_we_must_knock_out_their_cannon":
			AddDialogExitQuest("Sharpe_sends_out_Patrick");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "firing_instructions":
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "Exit_firing_instructions";
		break;

		case "Exit_firing_instructions":
			AddDialogExitQuest("Ready_to_fire_cannon");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "second_cannon_shot":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "second_cannon_shot2";
		break;

		case "second_cannon_shot2":
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "Exit_second_cannon_shot";
		break;

		case "Exit_second_cannon_shot":
			AddDialogExitQuest("Clear_for_firing");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "A_hit_sir_A_hit":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "Exit_A_hit_sir_A_hit";
		break;

		case "Exit_A_hit_sir_A_hit":
			AddDialogExitQuest("The_French_back_off");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "The_riflemen_in_position":
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "The_riflemen_in_position2";
		break;

		case "The_riflemen_in_position2":
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "Exit_The_riflemen_in_position";
		break;

		case "Exit_The_riflemen_in_position":
			AddDialogExitQuest("Some_gunners_die");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "a_second_retreat":
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "a_second_retreat2";
		break;

		case "a_second_retreat2":
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "a_second_retreat3";
		break;

		case "a_second_retreat3":
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "a_second_retreat4";
		break;

		case "a_second_retreat4":
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "a_second_retreat5";
		break;

		case "a_second_retreat5":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "Exit_a_second_retreat";
		break;

		case "Exit_a_second_retreat":
			AddDialogExitQuest("Where_are_the_reinforcements");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Change_orders":
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "Exit_Change_orders";
		break;

		case "Exit_Change_orders":
			AddDialogExitQuest("Go_to_the_guns");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "We_did_what_we_could":
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "Exit_We_did_what_we_could";
		break;

		case "Exit_We_did_what_we_could":
			AddDialogExitQuest("Defensive_positions2");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "They_have_cannon":
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "Exit_They_have_cannon";
		break;

		case "Exit_They_have_cannon":
			AddDialogExitQuest("The_French_assualt3XXX");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "First_volley_over":
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "Exit_First_volley_over";
		break;

		case "Exit_First_volley_over":
			AddDialogExitQuest("French_second_volley1Z");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Their_cannon_are_done":
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "Exit_Their_cannon_are_done";
		break;

		case "Exit_Their_cannon_are_done":
			AddDialogExitQuest("The_French_assualt5XXX");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit":
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_Ships_are_fighting":
			AddDialogExitQuest("The_Don_Arrives");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Hired_for_Hotspur":
			PlaySound("VOICE\ENGLISH\Matthews01.wav");
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "Exit_Hired_for_Hotspur";
		break;

		case "Exit_Hired_for_Hotspur":
			AddDialogExitQuest("Styles_needs_a_job");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Landing_party":
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "Exit_Landing_party";
		break;

		case "Exit_Landing_party":
			AddDialogExitQuest("Wolfe_volunteers");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "We_will_wait_here":
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "We_will_wait_here2";
		break;

		case "We_will_wait_here2":
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "Exit_We_will_wait_here";
		break;

		case "Exit_We_will_wait_here":
			AddDialogExitQuest("Lead_off");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Were's_Captain_Hornblower":
			PlaySound("VOICE\ENGLISH\Matthews02.wav");
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "Were's_Captain_Hornblower2";
		break;

		case "Were's_Captain_Hornblower2":
			PlaySound("VOICE\ENGLISH\Matthews03.wav");
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "Were's_Captain_Hornblower3";
		break;

		case "Were's_Captain_Hornblower3":
			PlaySound("VOICE\ENGLISH\Matthews04.wav");
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "Were's_Captain_Hornblower4";
		break;

		case "Were's_Captain_Hornblower4":
			PlaySound("VOICE\ENGLISH\Matthews05.wav");
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "Were's_Captain_Hornblower5";
		break;

		case "Were's_Captain_Hornblower5":
			PlaySound("VOICE\ENGLISH\Matthews06.wav");
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "Exit_Were's_Captain_Hornblower";
		break;

		case "Exit_Were's_Captain_Hornblower":
			AddDialogExitQuest("Hammond_the_wimp_three");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

	}
}

