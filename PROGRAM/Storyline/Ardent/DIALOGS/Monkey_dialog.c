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
			int iPhrase = rand(3);

			switch (iPhrase)
			{
				case 0:
					dialog.text = DLG_TEXT[0];
				break;
	
				case 1:
					PlaySound("trep\monkey.wav");
					dialog.text = DLG_TEXT[2];
				break;

				case 2:
					dialog.text = DLG_TEXT[4];
				break;

				case 3:
					PlaySound("trep\monkey.wav");
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

		case "farewell1":
			PlaySound("trep\monkey.wav");
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "farewell2";
		break;

		case "farewell2":
			PlaySound("trep\monkey.wav");
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "farewell3";
		break;

		case "farewell3":
			PlaySound("trep\monkey.wav");
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			AddDialogExitQuest("monkey_farewell2");
			link.l1.go = "exit";
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

	}
}