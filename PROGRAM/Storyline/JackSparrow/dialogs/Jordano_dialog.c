//#include "DIALOGS\Jordano_dialog.h"
	
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
		// -----------------------------------Диалог первый - первая встреча
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
			link.l1.go = "exit";

			if (CheckQuestAttribute("ANIMISTS", "speak_with_jordano"))
			{
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "lie";
			}
		break;

		case "lie":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "lie_good";
		break;

		case "lie_good":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "lie_good_2";
		break;

		case "lie_good_2":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "lie_good_3";
		break;

		case "lie_good_3":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "lie_good_4";
		break;
		
		case "lie_good_4":  // --> edited by Cat for Animists Quest fix
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "lie_good_5";
		break;

		case "lie_good_5":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];  // <-- edited by Cat for Animists Quest fix
			link.l1.go = "exit";
			pchar.quest.ANIMISTS = "to_greenford_for_teacher";
			AddQuestRecord("Sao Feng", 26);
			DeleteAttribute(&Locations[FindLocation("Muelle_town_01")],"vcskip"); // NK
			AddDialogExitQuest("speak_with_jordano2");  // <-- edited by Cat for Animists Quest fix
		break;
					
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
