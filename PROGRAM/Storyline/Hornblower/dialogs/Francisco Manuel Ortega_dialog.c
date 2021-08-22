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

		case "Exit":
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "giving_my_surrender":
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "giving_my_surrender2";
		break;

		case "giving_my_surrender2":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "giving_my_surrender3";
		break;

		case "giving_my_surrender3":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "giving_my_surrender4";
		break;

		case "giving_my_surrender4":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit_giving_my_surrender";
		break;

		case "Exit_giving_my_surrender":
			AddDialogExitQuest("into_surrendered_fort");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "here_are_my_troops":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Exit_here_are_my_troops";
		break;

		case "Exit_here_are_my_troops":
			AddDialogExitQuest("go_join_spanish_troops");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

	}
}

