//#include "DIALOGS\Morgan Terror_Dialog.h"
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
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
//			NPChar.quest.meeting = NPC_Meeting;
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

				
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "our_first_meeting":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "our_first_meeting2";
		break;

		case "our_first_meeting2":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "our_first_meeting3";
		break;

		case "our_first_meeting3":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "our_first_meeting4";
		break;
		
		case "our_first_meeting4":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "our_first_meeting5";
		break;

		case "our_first_meeting5":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "our_first_meeting6";
		break;

		case "our_first_meeting6":
			AddMoneyToCharacter(pchar, -200);
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "Exit_our_first_meeting";
		break;

		case "Exit_our_first_meeting":
			AddDialogExitQuest("Beach_for_French_ship");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Swannexitagain":
			AddDialogExitQuest("Off_to_shipyard_now");
			DialogExit();
		break;
		

//		case "Exit": 
//			Diag.CurrentNode = Diag.TempNode;
//			DialogExit();
//		break;

	
			}
}
