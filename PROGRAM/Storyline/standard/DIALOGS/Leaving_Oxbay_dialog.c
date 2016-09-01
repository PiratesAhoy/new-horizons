//#include "DIALOGS\Leaving_Oxbay_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d; 
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting, TempInfoCharacterID_1, TempInfoCharacterID_2;
	int DonationSize;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1] + Characters[getCharacterIndex(DLG_TEXT[2])].lastname + DLG_TEXT[3];
			Link.l1.go = "node_1";
		break;

		case "Node_1":
			d.Text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5] + Characters[getCharacterIndex(DLG_TEXT[6])].lastname + DLG_TEXT[7];
			Link.l1.go = "node_2";
			Link.l2 = DLG_TEXT[8];
			Link.l2.go = "node_3";
		break;

		case "Node_2":
			d.Text = DLG_TEXT[9];
			Link.l1 = DLG_TEXT[10];
			Link.l1.go = "node_4";
		break;

		case "Node_3":
			d.Text = DLG_TEXT[11];
			Link.l1 = DLG_TEXT[12];
			Link.l1.go = "exit";
			Characters[getCharacterIndex("Rabel Iverneau")].dialog.CurrentNode = "Let's get out";
			AddDialogExitQuest("Story_RabelSuggestsToRun");	
		break;

		case "Node_4":
			d.Text = DLG_TEXT[13];
			Link.l1 = DLG_TEXT[14];
			Link.l1.go = "exit";
			AddDialogExitQuest("leaving_oxbay_exit_no_run");
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
		
	}
}

