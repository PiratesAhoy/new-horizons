//#include "DIALOGS\Jack_dialog.h"
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
			Dialog.snd = "voice\THDI\THDI001";

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";

			if (GetCharacterShipModel(PChar) == "Black Pearl" || GetCharacterShipID(PChar) == SHIP_CURSED)
			{
				if(PChar.sex == "woman") dialog.text = DLG_TEXT[2] + DLG_TEXT[4] + DLG_TEXT[5];
				else dialog.text = DLG_TEXT[2] + DLG_TEXT[3] + DLG_TEXT[5];
				link.l1 = DLG_TEXT[6];
				link.l1.go = "locked_in_here";
			}
		break;

		case "locked_in_here":
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			AddDialogExitQuest("Hit_Sparrow_runs_away");
			link.l1.go = "Exit";
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
