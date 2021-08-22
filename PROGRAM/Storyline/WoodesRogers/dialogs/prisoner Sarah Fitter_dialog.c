//#include "DIALOGS\prisoner Sarah Fitter_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	ref lcn = &Locations[FindLocation(PChar.location)];
	
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
			Dialog.snd = "voice\PADI\PADI001";

			PlaySound("VOICE\ENGLISH\Eng_f_c_001.wav");

			if (Pchar.location == "wr_chapel")
			{
				Dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "exit";
			}
			else
			{
				Dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "exit";
			}

			Diag.TempNode = "first time";
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
