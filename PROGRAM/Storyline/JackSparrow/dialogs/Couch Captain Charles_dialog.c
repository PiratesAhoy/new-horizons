//#include "DIALOGS\Sir Christopher Mings_dialog.h"
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

		break;

		case "Get_me_Out_of_here":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];			
			link.l1.go = "Get_me_Out_of_here2";
		break;	

		case "Get_me_Out_of_here2":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];			
			link.l1.go = "Get_me_Out_of_here3";
		break;
		
		case "Get_me_Out_of_here3":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];			
			link.l1.go = "Get_me_Out_of_here4";
		break;

		case "Get_me_Out_of_here4":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];			
			link.l1.go = "Get_me_Out_of_here5";
		break;
		
		case "Get_me_Out_of_here5":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];			
			link.l1.go = "Get_me_Out_of_here6";
		break;		

		case "Get_me_Out_of_here6":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];			
			link.l1.go = "Get_me_Out_of_here7";
		break;		

		case "Get_me_Out_of_here7":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];			
			link.l1.go = "Exit_Get_me_out";
		break;
		
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
		
		case "Exit_Island_stuff":
			pchar.quest.Mings_contract = "done";
			pchar.quest.Catalina_contract = "done";
			pchar.quest.CCC_contract = "done";
			pchar.quest.KK_contract = "done";
			pchar.quest.Merciless_contract = "done";
			pchar.quest.Maximus_contract = "done";
			pchar.quest.Petros_contract = "done";
			pchar.quest.ThomasT_contract = "done";
			pchar.quest.NathanK_contract = "done";
			
			pchar.quest.Bonnie_talk = "Needing_family_help";
			pchar.quest.Chosen_Quest = "CCC";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Moving_right_along");
		break;

		case "Exit_for_choice":
			pchar.quest.CCC_contract = "sealed";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;		

		case "Exit_Get_me_out":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Return_to_Petros_with_CCC");
		break;		
		
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
