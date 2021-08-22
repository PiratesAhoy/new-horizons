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

		case "First_words_at_dinner":
			PlaySound("VOICE\ENGLISH\Etienne01.wav");
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Exit_First_words_at_dinner";
		break;

		case "Exit_First_words_at_dinner":
			AddDialogExitQuest("Duchess_one");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Second_words_at_dinner":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[4] + Pchar.lastname + DLG_TEXT[5];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Exit_Second_words_at_dinner";
		break;

		case "Exit_Second_words_at_dinner":
			AddDialogExitQuest("Duchess_two");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Third_words_at_dinner":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Exit_Third_words_at_dinner";
		break;

		case "Exit_Third_words_at_dinner":
			AddDialogExitQuest ("Masseredo_interjection"); //("Duchess_three");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Fourth_words_at_dinner":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Exit_Fourth_words_at_dinner";
		break;

		case "Exit_Fourth_words_at_dinner":
			AddDialogExitQuest("Duchess_three");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Fifth_words_at_dinner":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Exit_Fifth_words_at_dinner";
		break;

		case "Exit_Fifth_words_at_dinner":
			AddDialogExitQuest("Leave_the_Dinner");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "words_after_dinner":
			PlaySound("VOICE\ENGLISH\Etienne02.wav");
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "words_after_dinner2";
		break;

		case "words_after_dinner2":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "words_after_dinner3";
		break;

		case "words_after_dinner3":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Exit_words_after_dinner";
		break;

		case "Exit_words_after_dinner":
			AddDialogExitQuest("The_Duchess_and_Officer");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit":
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;


	}
}

