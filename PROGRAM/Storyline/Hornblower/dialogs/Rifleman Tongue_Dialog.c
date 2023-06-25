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
//			PlaySound("VOICE\ENGLISH\Tongue02.wav");
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
			}
			else
			{	
//			PlaySound("VOICE\ENGLISH\Tongue01.wav");
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Exit";
			}
		break;

		case "With_Sharpe_to_Lighthouse":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "With_Sharpe_to_Lighthouse2";
		break;

		case "With_Sharpe_to_Lighthouse2":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit_With_Sharpe_to_Lighthouse";
		break;

		case "Exit_With_Sharpe_to_Lighthouse":
			AddDialogExitQuest("A_choice_of_ways");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit":
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Wounded_Murray":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Exit_Wounded_Murray";
		break;

		case "Exit_Wounded_Murray":
			AddDialogExitQuest("Murray_slumps");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

			}
}
