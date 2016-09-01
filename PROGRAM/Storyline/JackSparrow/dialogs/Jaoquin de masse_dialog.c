//#include "DIALOGS\Jaoquin de masse_dialog.h"
	
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
		// ----------------------------------- Диалог первый - первая встреча
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

			if (CheckQuestAttribute("ANIMISTS", "first_time_Masse"))
			{
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "first_time_Masse";
			}
		//	if (CheckQuestAttribute("ANIMISTS", "to_prison_for_teacher")) 
		//	{ 
		//		dialog.text = DLG_TEXT[4]; 
		//		link.l1 = DLG_TEXT[5]; 
		//		link.l1.go = "exit"; 
		//		pchar.quest.ANIMISTS = "raskainye"; 
		//		AddDialogExitQuest("to_greenford_prison"); 
		//	}
		break;

		case "first_time_Masse":
			dialog.text = DLG_TEXT[6] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "first_time_Masse_2";
		break;

		case "first_time_Masse_2":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "first_time_Masse_3";
		break;

		case "first_time_Masse_3":
			dialog.text = DLG_TEXT[11] + GetCharacterFullName(npchar.id) + DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "first_time_Masse_4";
		break;

		case "first_time_Masse_4":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "first_time_Masse_5";
		break;

		case "first_time_Masse_5":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
			AddDialogExitQuest("masse_becomes_officer");
			pchar.quest.ANIMISTS = "to_muelle_for_rumors";
		break;

		case "Which_ship":
			dialog.text = DLG_TEXT[22];			/*18*/
			link.l1 = DLG_TEXT[23];				/*19*/
			link.l1.go = "exit_mefisto";
			//link.l2 = DLG_TEXT[20];
			//link.l2.go = "exit_pearl";
			//link.l3 = DLG_TEXT[21];
			//link.l3.go = "exit_sink";
			AddDialogExitQuest("Abordage_End"); // PB: To prevent player getting stuck
		break;

		case "Leaving":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "exit";
			AddDialogExitQuest("Jaoquin_leaves");
		break;

		case "exit_mefisto":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "exit_pearl":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "exit_sink":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
