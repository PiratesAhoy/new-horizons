//#include "DIALOGS\Smugglers_vs_Blythe.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
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
			Link.l1.go = "exit"; 
			AddDialogExitQuest("nigel_answer_to_smuggler");
		break;
		
		case "nigel_fight":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "nigel_fight_with_smugglers";
			link.l2 = DLG_TEXT[4];
			link.l2.go = "we_and_nigel_fight_with_smugglers";
		break;
		
		case "nigel_fight_with_smugglers":
			dialogexit();
			AddDialogExitQuest("nigel_fight_with_smugglers");
//			npchar.dialog.currnetnode = "empty";
			Diag.CurrentNode = "empty";
			Diag.TempNode = "empty";
		break;
		
		case "we_and_nigel_fight_with_smugglers":
			dialogexit();
			AddDialogExitQuest("we_and_nigel_fight_with_smugglers");
//			npchar.dialog.currnetnode = "empty";
			Diag.CurrentNode = "empty";
			Diag.TempNode = "empty";
		break;
		
		case "we_and_nigel_fight":
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "exit";
			AddDialogExitQuest("we_and_nigel_fight_with_smugglers");
		break;
		
		case "empty":
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "exit";
		break;

		case "continue":
			d.Text = DLG_TEXT[9];
			Link.l1 = DLG_TEXT[10]; 
			Link.l1.go = "exit1";
			Link.l2 = DLG_TEXT[11];
			Link.l2.go = "fight";
		break;

		case "fight":
			Diag.CurrentNode = "continue";
			LAi_QuestDelay("Smugglers_fight2", 0.01);
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
	}
}