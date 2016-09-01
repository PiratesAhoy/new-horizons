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
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "ExitFirst_meeting";
		break;		
	
		case "Exit":	
			NextDiag.CurrentNode = "First time";		
			DialogExit();
		break;

		case "SearchExit":		
			AddDialogExitQuest("to_find_a_sister");		
			NextDiag.CurrentNode = "First time";		
			DialogExit();
		break;

		case "ExitFirst_meeting":
			AddDialogExitQuest("go_upstairs");		
			NextDiag.CurrentNode = "First time";		
			DialogExit();
		break;		
	}
}

