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

		case "After_first_Battle":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[2];
			link.l1.go = "After_first_Battle2";
		break;

		case "After_first_Battle2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[3];
			link.l1 = DLG_TEXT[4];
			link.l1.go = "Exit_after_the_battle";
		break;		

		case "Exit_after_the_battle":
			AddQuestRecord("Battle Bloodied", 3);
			AddDialogExitQuest("Given_Sailing_Orders");
			NextDiag.CurrentNode = "First time";		
			DialogExit();
		break;

		case "Exit":	
			NextDiag.CurrentNode = "First time";		
			DialogExit();
		break;

		case "First_sailing_orders":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "First_sailing_orders2";
		break;

		case "First_sailing_orders2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[3];
//			link.l1 = DLG_TEXT[5];
			link.l1.go = "Exit_First_sailing_orders";
		break;

		case "Exit_First_sailing_orders":
			AddDialogExitQuest("Sail_for_Guadeloupe3");
			NextDiag.CurrentNode = "First time";		
			DialogExit();
		break;

	}
}

