//#include "DIALOGS\Estrella Disguised_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	
	DeleteAttribute(&Dialog,"Links");
	aref Link, NextDiag;
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	int iTest;

	ref PChar;
	PChar = GetMainCharacter();
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча	
		case "exit":
			Dialog.CurrentNode = Dialog.TempNode;
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

			Dialog.TempNode = "Second time";
			Dialog.Text = DLG_TEXT[0] + GetMyName(Pchar) + DLG_TEXT[1];
			link.l1 = DLG_TEXT[2];
			link.l1.go = "trembling";
		break;	
		
		case "trembling":
			Dialog.Text = DLG_TEXT[3] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "not_afraid";
		break;

		case "not_afraid":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "not_afraid2";	
		break;

		case "not_afraid2":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "not_afraid3";	
		break;
		
		case "not_afraid3":
			dialog.text = DLG_TEXT[10] + GetMyName(Pchar) + DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "exit_officer";
		break;
		
		case "exit_officer":
			AddDialogExitQuest("Story_EstrellaBecomesOfficer");
			DialogExit();
		break;
		
		case "close_call":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "Exit_reunited";
		break;	
		
		case "Exit_reunited":
			AddDialogExitQuest("estrella_disguised_exit_run1");
			DialogExit();
		break;
		
		case "reunited":
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "exit_estrella_disguised_attack1";
		break;
		
		case "exit_estrella_disguised_attack1":
			AddDialogExitQuest("estrella_disguised_attack1");
			DialogExit();
		break;
		
		case "reunited2":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "exit_estrella_disguised_attack2";
		break;
		
		case "exit_estrella_disguised_attack2":
			AddDialogExitQuest("estrella_disguised_attack4");
			DialogExit();
		break;		
		
		case "estrella_farewell":
			dialog.text = DLG_TEXT[19] + GetMyName(Pchar) + DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Exit_StageRight";
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1250);
				AddPartyExpChar(pchar, "Sneak", 13);
			}
			else { AddPartyExp(pchar, 1250); }
			ChangeCharacterReputation(pchar, +1);
			AddQuestRecord("estrella", 5);
			CloseQuestHeader("estrella");
		break;
		
		case "Exit_StageRight":
			AddDialogExitQuest("Story_Exit_StageRight");
			DialogExit();
		break;
		
		}
}



