//#include "DIALOGS\LaCroix_dialog.h"

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

			dialog.snd = "Voice\CLLA\CLLA001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			break;

		case "logbook":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[2];
			link.l1.go = "exit";
			AddDialogExitQuest("birdsearch2");
			break;

		case "logbook2":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[3];
			link.l1.go = "exit";
			AddDialogExitQuest("birdsearch4");
			break;

		case "blow_it":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[4];
			link.l1.go = "exit";
			break;

		case "run":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[5];
			link.l1.go = "exit";
			AddDialogExitQuest("birdfly");
			break;

		case "begin_5":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
			AddDialogExitQuest("attaque");
			break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			break;
	}
}
