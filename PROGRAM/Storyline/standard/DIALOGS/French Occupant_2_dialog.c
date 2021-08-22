//#include "DIALOGS\French Occupant_2_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"

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
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_1":
			DialogExit();
			ChangeCharacterAddress(characterFromID("Valentin Massoni"),"Oxbay_town_exit","citizen08");
		break;


		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\FROC\FROC001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Node_2";
		break;

		case "Node_2":
			dialog.snd = "Voice\FROC\FROC002";
			dialog.TempNode = "Once_again";
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Exit_1";
		break;

		case "Once_again":
			dialog.snd = "Voice\FROC\FROC003";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Exit";
		break;




	}
}
