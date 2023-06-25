//#include "DIALOGS\Skull_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

	
	switch(Dialog.CurrentNode)
	{
		// ----------------------------------- -иалог первый - первая вс=реча
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

			NextDiag.TempNode = "first time";
			
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			// NK -->
			if(GetNationRelation2MainCharacter(PIRATE) != RELATION_ENEMY && HaveLetterOfMarque(PIRATE)) // PB: Added LoM check
			{
				dialog.text = "I'm busy.";
			}
			// NK <--
			if (GetNationRelation2MainCharacter(PIRATE) != RELATION_ENEMY) // PB
			{
                if (GetLetterOfMarqueQuantity() == 0 && !HaveLetterOfMarque(PIRATE)) // PB
    			{
    				dialog.text = DLG_TEXT[34];
    				link.l1 = DLG_TEXT[35];
    				link.l1.go = "piratefun";
    				link.l2 = DLG_TEXT[36];
    				link.l2.go = "exit";
    			}
    		}

			if ( CheckQuestAttribute("Bonnie_talk","Words_from_Skull") )
			{
				dialog.text = DLG_TEXT[42];
				link.l1 = DLG_TEXT[43];
				link.l1.go = "Exit_Skull";
			}
		break;

		case "piratefun": //<<------------------this node was added, love verruckt
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "piratefun2";
			link.l2 = DLG_TEXT[39];
			link.l2.go = "exit";
			//AddDialogExitQuest("piratefun");
		break;

		case "piratefun2": //<<------------------this node was added, love verruckt
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "exit";
			AddDialogExitQuest("piratefun");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_Skull":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Round_the_Room");
		break;
	}
}
