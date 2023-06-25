//#include "DIALOGS\Peter Willemoes_dialog.h"
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

			Dialog.mood = "normal";

			dialog.snd = "Voice\ARGU\ARGU001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";

			if(checkquestattribute("Jacks_early_days", "Get_ready_for_Guadeloupe"))
			{
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];			
				link.l1.go = "ExitOxbay";
			}
			if (checkquestattribute("Jacks_early_days", "And_now_Peter"))
			{
				dialog.text = DLG_TEXT[4];
				link.l1 = DLG_TEXT[5];			
				link.l1.go = "Exit_to_Konrad";
			}			

		break;		

		case "Option_Talk":
				dialog.text = DLG_TEXT[6] + getmyname(pchar) + DLG_TEXT[7];
				link.l1 = DLG_TEXT[8];			
				link.l1.go = "Option_Talk2";
		break;

		case "Option_Talk2":
				dialog.text = DLG_TEXT[9];
				link.l1 = DLG_TEXT[10];			
				link.l1.go = "Option_Talk3";		
		break;

		case "Option_Talk3":
				dialog.text = DLG_TEXT[11];
				link.l1 = DLG_TEXT[12];			
				link.l1.go = "Option_Talk4";		
		break;

		case "Option_Talk4":
				dialog.text = DLG_TEXT[13] + getmyname(pchar) + DLG_TEXT[14];
				link.l1 = DLG_TEXT[15];			
				link.l1.go = "Option_Talk5";		
		break;

		case "Option_Talk5":
				dialog.text = DLG_TEXT[16];
				link.l1 = DLG_TEXT[17];			
				link.l1.go = "Option_Talk6";		
		break;

		case "Option_Talk6":
				dialog.text = DLG_TEXT[18];
				link.l1 = DLG_TEXT[19];			
				link.l1.go = "Exit_Option_Talk";		
		break;

		case "Exit_Option_Talk":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Mings_sums_up");			
		break;
		
		case "Exit_to_Konrad":
			pchar.quest.Jacks_early_days = "Stratergy_discussion";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Stratergy_discussion");			
		break;		
		
		case "ExitOxbay":
			RemoveOfficersIndex(pchar, GetCharacterIndex("Peter Willemoes"));
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
