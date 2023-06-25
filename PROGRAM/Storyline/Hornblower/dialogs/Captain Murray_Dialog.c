//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;

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
			Diag.CurrentNode = Diag.TempNode; //"First time";
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

			if(CheckQuestAttribute("Soldier_Company", "Foot"))
			{	
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
			}
			if(CheckQuestAttribute("Soldier_Company", "Rifles"))
			{	
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Exit";
			}
		break;

		case "Looking_for_who":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Looking_for_who2";
		break;

		case "Looking_for_who2":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit_Looking_for_who";
		break;

		case "Exit_Looking_for_who":
			AddDialogExitQuest("Dunnitt_for_transfer");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Papers_in_order":
			PlaySound("VOICE\ENGLISH\Murray01.wav");
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Exit_Papers_in_order";
		break;

		case "Exit_Papers_in_order":
			AddDialogExitQuest("Dunnitt_reams_Sharpe");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Not_going_to_make_it":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "Exit_Not_going_to_make_it";
		break;

		case "Exit_Not_going_to_make_it":
			AddDialogExitQuest("Murray_slumps2");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Cough_cough":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "Exit";
		break;

			}
}
