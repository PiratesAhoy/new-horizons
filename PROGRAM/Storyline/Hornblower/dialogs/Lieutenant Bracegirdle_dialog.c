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

		case "First_meeting_Greenford":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Exit_First_meeting_Greenford";
		break;

		case "Exit_First_meeting_Greenford":
			AddDialogExitQuest("go_back_for_Pellew");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "dispose_of_the_body":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Exit_dispose_of_the_body";
		break;

		case "Exit_dispose_of_the_body":
			AddDialogExitQuest("Bush_Leaves_Upstairs");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Report_gentlemen":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit_Report_gentlemen";
		break;

		case "Exit_Report_gentlemen":
			AddDialogExitQuest("Into_ship_one_position");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

	}
}

