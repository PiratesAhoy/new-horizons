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

			if(CheckQuestAttribute("Players_rank", "Midshipman"))
			{				
				PlaySound("VOICE\ENGLISH\Dunnitt01.wav");
				dialog.text = DLG_TEXT[24];
				link.l1 = DLG_TEXT[25];
				link.l1.go = "Continue Chatter Mishipman";
			}
			if(CheckQuestAttribute("Players_rank", "Lieutenant"))
			{				
				dialog.text = DLG_TEXT[4];
				link.l1 = DLG_TEXT[5];
				link.l1.go = "Walk_away";
				link.l2 = DLG_TEXT[6];
				link.l2.go = "Sharpe Chat";
			}
			if(CheckQuestAttribute("Players_rank", "Commander"))
			{
				dialog.text = DLG_TEXT[11];
				link.l1 = DLG_TEXT[12];
				link.l1.go = "Continue Chatter Commander";
			}
		break;

		case "Continue Chatter Commander":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "exit";
//			link.l2 = DLG_TEXT[15];
//			link.l2.go = "Battle Plan";
		break;

		case "Continue Chatter Mishipman":
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1] + GetMyName(PChar) + Pchar.lastname + " sir.";
			link.l1.go = "Continue Chatter Mishipman2";
		break;

		case "Continue Chatter Mishipman2":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Walk_away";
		break;

		case "Walk_away":
			LAi_SetCitizenType(characterFromID("Major Dunnitt"));
			link.l1.go = "exit";
		break;

		case "Sharpe Chat":
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "Sharpe Chat2";
		break;

		case "Sharpe Chat2":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "exit";
		break;

		case "Make_ready_the_troops":
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "Exit_Make_ready_the_troops";
		break;

		case "Exit_Make_ready_the_troops":
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("Bush_First_Lieutenant");
			DialogExit();
		break;

		case "Transfer Sharpe":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "Exit_Transfer Sharpe";
		break;

		case "Exit_Transfer Sharpe":
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("Papers_in_order");
			DialogExit();
		break;

		case "Take_the_man":
			PlaySound("VOICE\ENGLISH\Dunnitt02.wav");
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Take_the_man2";
		break;

		case "Take_the_man2":
			PlaySound("VOICE\ENGLISH\Dunnitt03.wav");
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "Exit_Take_the_man";
		break;

		case "Exit_Take_the_man":
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("Sharpe_find_Hogan");
			DialogExit();
		break;

		case "Not_you_Sharpe":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "Not_you_Sharpe2";
		break;

		case "Not_you_Sharpe2":
			PlaySound("VOICE\ENGLISH\Dunnitt04.wav");
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "Exit_Not_you_Sharpe";
		break;

		case "Exit_Not_you_Sharpe":
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("Get_Harper_Cooper");
			DialogExit();
		break;

		
	}
}
