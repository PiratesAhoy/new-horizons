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
//			if(CheckQuestAttribute("Soldier_Company", "Rifles"))
			else
			{	
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Exit";
			}
		break;

		case "Job_done_Sir":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Job_done_Sir2";
		break;

		case "Job_done_Sir2":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit_Job_done_Sir";
		break;

		case "Exit_Job_done_Sir":
			AddDialogExitQuest("Our_ruse_continues");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Take_you_to_camp":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Take_you_to_camp2";
		break;

		case "Take_you_to_camp2":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "Take_you_to_camp3";
		break;

		case "Take_you_to_camp3":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "Exit_Take_you_to_camp";
		break;

		case "Exit_Take_you_to_camp":
			AddDialogExitQuest("Lead_off_to_Rifles");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Officer_over_there":
				dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "Exit_Officer_over_there";
		break;

		case "Exit_Officer_over_there":
			AddDialogExitQuest("Talk_to_Murray");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

			}
}
