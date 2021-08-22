//#include "DIALOGS\French Patrol_dialog.h"
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
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "fight_exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
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
			Dialog.snd = "dialogs\0\009";

			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "Node_1";
		break;

		case "Node_1":
			d.Text = DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3];
			Link.l1.go = "Node_2";
			Link.l2 = DLG_TEXT[4];
			Link.l2.go = "Node_4";
		break;

		case "Node_2":
			d.Text = DLG_TEXT[5];
			Link.l1 = DLG_TEXT[6];
			Link.l1.go = "Node_3";
			Link.l2 = DLG_TEXT[7];
			Link.l2.go = "Node_4";
		break;

		case "Node_3":
			d.Text = DLG_TEXT[8];
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "Node_5";			
		break;

		case "Node_4":
			d.Text = DLG_TEXT[10];
			Link.l1 = DLG_TEXT[11];
			Link.l1.go = "Node_5";			
		break;

		case "Node_5":
			d.Text = DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "exit";			
			AddDialogExitQuest("french_patrol_fight_exit");
		break;

	}
}
