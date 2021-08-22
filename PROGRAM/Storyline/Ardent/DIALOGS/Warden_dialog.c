//#include "DIALOGS\Warden_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{	case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
		break;

		case "feeding":
			int iPhrase = rand(3);

			switch (iPhrase)
			{
				case 0:
					dialog.text = DLG_TEXT[0];
				break;
	
				case 1:
					dialog.text = DLG_TEXT[2];
				break;

				case 2:
					dialog.text = DLG_TEXT[4];
				break;

				case 3:
					dialog.text = DLG_TEXT[6];
				break;
			}
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[3];
			link.l2.go = "exit";
			link.l3 = DLG_TEXT[5];
			link.l3.go = "exit";
			link.l4 = DLG_TEXT[7];
			link.l4.go = "exit";
		break;

		case "not_again":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "not_again2";
		break;

		case "not_again2":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "exit";
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
	}
}