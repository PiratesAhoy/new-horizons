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

		case "Can_you_help":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Can_you_help2";
		break;

		case "Can_you_help2":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Can_you_help3";
		break;

		case "Can_you_help3":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit_Can_you_help";
		break;

		case "Exit_Can_you_help":
			AddDialogExitQuest("Wellard_in_tow");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Any_orders":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Exit_Any_orders";
		break;

		case "Exit_Any_orders":
			AddDialogExitQuest("Boat_coming_alongside");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Stop_the_hoist":
			dialog.text = DLG_TEXT[10];
			link.l1.go = "Exit_Stop_the_hoist";
		break;

		case "Exit_Stop_the_hoist":
			AddDialogExitQuest("Sawyer_reacts");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "It_is_me_sir":
			dialog.text = DLG_TEXT[11];
			link.l1.go = "Exit_It_is_me_sir";
		break;

		case "Exit_It_is_me_sir":
			AddDialogExitQuest("Sawyer_reacts2");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Mutiny_meeting_wellard":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "Exit_Mutiny_meeting_wellard";
		break;

		case "Exit_Mutiny_meeting_wellard":
			AddDialogExitQuest("Move_down_to_deck");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;


	}
}

