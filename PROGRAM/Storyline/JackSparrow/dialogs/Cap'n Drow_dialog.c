//#include "DIALOGS\Merciless Mark_dialog.h"
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

			if(checkquestattribute("Jacks_early_days", "Move_to_Meeting"))
			{
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];			
				link.l1.go = "exit";
			}
			if (checkquestattribute("Jacks_early_days", "Talking_at_Guadeloupe"))
			{
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];			
				link.l1.go = "Island_stuff";
			}			
			if (checkquestattribute("Jacks_early_days", "In_Prison_on_Guadeloupe"))
			{
				dialog.text = DLG_TEXT[28];
				link.l1 = DLG_TEXT[29];			
				link.l1.go = "In_French_Prison";
			}
			if(checkquestattribute("Bonnie_talk", "Needing_some_help") && checkquestattribute("NathanK_contract", "sealed"))
			{
				dialog.text = DLG_TEXT[6];
				link.l1 = DLG_TEXT[7];			
				link.l1.go = "Island_stuff3";			
			}
			if (GetAttribute(pchar, "Alantic_PL") == "none1")
			{
				dialog.text = DLG_TEXT[34];
				link.l1 = DLG_TEXT[35];
				link.l1.go = "PL_Alantic";	
			}
			if (GetAttribute(pchar, "Alantic_PL") == "none")
			{
				dialog.text = DLG_TEXT[40];
				link.l1 = DLG_TEXT[41];
				link.l1.go = "PL_Alantic";
			}
		break;

		case "Island_stuff":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];			
			link.l1.go = "Island_Stuff2";
		break;	

		case "Island_stuff2":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];			
			link.l1.go = "Exit_Island_stuff";
		break;
		
		case "Island_stuff4":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];			
			link.l1.go = "Island_stuff5";
		break;

		case "Island_stuff5":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];			
			link.l1.go = "Island_stuff6";
		break;
		
		case "Island_stuff6":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];			
			link.l1.go = "Island_stuff7";
		break;		

		case "Island_stuff7":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];			
			link.l1.go = "Island_stuff8";
		break;		

//		case "Island_stuff8":
//			dialog.text = DLG_TEXT[18];
//			link.l1 = DLG_TEXT[19];			
//			link.l1.go = "Exit_Island_stuff";
//		break;
		
		case "Arrival_at_Jamaica":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];			
			link.l1.go = "Arrival_at_Jamaica2";
		break;

		case "Arrival_at_Jamaica2":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];			
			link.l1.go = "ExitJamaicaArrival";
		break;

		case "In_French_Prison":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];			
			link.l1.go = "In_French_Prison2";
		break;

		case "In_French_Prison2":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];			
			link.l1.go = "Exit_French_Prison";
		break;

		case "PL_Alantic":
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "PL_Alantic2";
		break;

		case "PL_Alantic2":
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "Exit";

			GiveItem2Character(pchar, "Sparrow_Ring");
			PlayStereoSound("INTERFACE\took_item.flac");
			pchar.Alantic_PL = "Drow";

			AddQuestRecord("Slaver", 10);
			AddQuestRecord("Pirate Lord", 11);
			CloseQuestHeader("Slaver");
		break;

		case "Exit_French_Prison":
			pchar.quest.Jacks_early_days = "Sailing_for_Turks";		
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Get_off_Guadeloupe");
		break;
		
		case "Exit_Island_stuff":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Back_to_Rackham");
		break;

		case "Exit_for_choice":
			pchar.quest.NathanK_contract = "sealed";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;		

		case "ExitJamaicaArrival":
			pchar.quest.Bonnie_talk = "Talk_to_the_chief";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Jamaica_CCC4");
		break;		
		
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
