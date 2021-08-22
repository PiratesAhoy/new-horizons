//#include "DIALOGS\soldier1.h"
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
		case "First time":
			Dialog.defAni = "Gov_Dialog_1";
			Dialog.ani = "Gov_Dialog_2";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "meet";
			NPChar.greeting = ""; // NK
		break;

		case "meet":
			LAi_CharacterEnableDialog(CharacterFromID("Martin Warner"));
			d.Text = DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3];
			Link.l1.go = "EXIT3";	
		break;
		
		case "meeting":
			d.Text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "meeting1";
		break;

		case "meeting1":
			d.Text = DLG_TEXT[6];
			Link.l1 = DLG_TEXT[7];
			Link.l1.go = "exit1";
		break;

		case "meeting2":
			d.Text = DLG_TEXT[8];
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "meeting3";
			Link.l2 = DLG_TEXT[10];
			Link.l2.go = "exit";
			NPChar.FaceId = 47; // NK
		break;

		case "meeting3":
			SetCharacterShipLocation( CharacterFromID("Jack Greenfield"), "Redmond_port" );
			d.Text = DLG_TEXT[11] + DLG_TEXT[13]; // NK
			Link.l1 = DLG_TEXT[12];
			Link.l1.go = "exit2";
		break;

		case "exit":
// NK -->
			LAi_QuestDelay("soldier_in_tavern4", 0.5);
			SetCharacterShipLocation( CharacterFromID("Jack Greenfield"), "Redmond_port" );
// NK <--
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;	
		
		case "exit1":
			LAi_QuestDelay("soldier_in_tavern2", 1.0); // NK
			Diag.CurrentNode = "meeting2";
			DialogExit();
		break;
		
		case "exit2":
			AddDialogExitQuest("Small_Pause_Before_Convoy");
			Diag.CurrentNode = "meeting2";
			DialogExit();
		break;

		case "EXIT3":
			LAi_QuestDelay("soldier_in_tavern0", 0);
			Diag.CurrentNode = "meeting";
			DialogExit();
		break;
	}
}