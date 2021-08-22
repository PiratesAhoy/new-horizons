//#include "DIALOGS\Spanish_Captain1_dialog.h"
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
	{
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "surrendered":
			dialog.text = DLG_TEXT[0];			
			link.l1 = DLG_TEXT[1];
			link.l1.go = "fates";
		break;

		case "fates":
			if (PChar.ServedNation == PIRATE) dialog.text = DLG_TEXT[2];
			else dialog.text = DLG_TEXT[3];			
			link.l1 = DLG_TEXT[4];
			link.l1.go = "work";
		break;

		case "work":
			dialog.text = DLG_TEXT[5];
			link.l1.go = "exit";
		break;

		case "caught_in_port":
			Preprocessor_Add("gender", PChar.sex);
			PlaySound("VOICE\ENGLISH\Spa_m_b_043.wav");
			dialog.text = DLG_TEXT[7];			
			link.l1 = DLG_TEXT[8];
			link.l1.go = "fight";
			link.l2 = DLG_TEXT[9];
			link.l2.go = "back_to_prison";
		break;

		case "fight":
			AddDialogExitQuest("port_fight");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "back_to_prison":
			AddDialogExitQuest("back_to_prison");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "sailing_together":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
		break;
	}
}