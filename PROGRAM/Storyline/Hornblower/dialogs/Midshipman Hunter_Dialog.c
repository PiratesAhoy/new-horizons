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

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "our_first_meeting":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "our_first_meeting2";
		break;

		case "our_first_meeting2":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "our_first_meeting3";
		break;

		case "our_first_meeting3":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "our_first_meeting4";
		break;
		
		case "our_first_meeting4":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "our_first_meeting5";
		break;

		case "our_first_meeting5":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "our_first_meeting6";
		break;

		case "our_first_meeting6":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "our_first_meeting7";
		break;

		case "our_first_meeting7":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "our_first_meeting8";
		break;

		case "our_first_meeting8":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "our_first_meeting9";
		break;

		case "our_first_meeting9":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "our_first_meeting10";
		break;

		case "our_first_meeting10":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "our_first_meeting11";
		break;

		case "our_first_meeting11":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "our_first_meeting12";
		break;

		case "our_first_meeting12":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "Exit_our_first_meeting";
		break;

		case "Exit_our_first_meeting":
			AddDialogExitQuest("Off_to_the_Mystery_House");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "the_French_shell":
			dialog.text = DLG_TEXT[65];
			link.l1 = DLG_TEXT[66];
			link.l1.go = "the_French_shell2";
		break;

		case "the_French_shell2":
			dialog.text = DLG_TEXT[67];
			link.l1 = DLG_TEXT[68];
			link.l1.go = "Exit_the_French_shell";
		break;

		case "Exit_the_French_shell":
			AddDialogExitQuest("Off_to_the_Mystery_House5");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "See_the_French_ship":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "See_the_French_ship2";
		break;

		case "See_the_French_ship2":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "See_the_French_ship3";
		break;

		case "See_the_French_ship3":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "Exit_See_the_French_ship";
		break;

		case "Exit_See_the_French_ship":
			AddDialogExitQuest("Spot_the_soldier");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "I_see_a_soldier":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "Exit_I_see_a_soldier";
		break;

		case "Exit_I_see_a_soldier":
			AddDialogExitQuest("Talk_to_the_soldier");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Back_with_the_crew":
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "Back_with_the_crew2";
		break;

		case "Back_with_the_crew2":
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "Exit_Back_with_the_crew";
		break;

		case "Exit_Back_with_the_crew":
			AddDialogExitQuest("Now_take_the_ship2");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "get_ready_for_capture":
			dialog.text = DLG_TEXT[38] + Pchar.lastname + "?";
			link.l1 = DLG_TEXT[39];
			link.l1.go = "get_ready_for_capture2";
		break;

		case "get_ready_for_capture2":
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "get_ready_for_capture3";
		break;

		case "get_ready_for_capture3":
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "Exit_get_ready_for_capture";
		break;

		case "Exit_get_ready_for_capture":
			AddDialogExitQuest("Le_Reve_Capture_at_sea");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "In_the_Spanish_Fort":
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "Exit_In_the_Spanish_Fort";
		break;

		case "Exit_In_the_Spanish_Fort":
			AddDialogExitQuest("Find_Kennedy_in_Prison");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Talk_about_Archie":
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "Talk_about_Archie2";
		break;

		case "Talk_about_Archie2":
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "Exit_Talk_about_Archie";
		break;

		case "Exit_Talk_about_Archie":
			AddDialogExitQuest("More_days_in_Prison");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Talk_about_Escape":
			dialog.text = DLG_TEXT[48] + Pchar.lastname + DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "Talk_about_Escape2";
		break;

		case "Talk_about_Escape2":
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "Exit_Talk_about_Escape";
		break;

		case "Exit_Talk_about_Escape":
			AddDialogExitQuest("Here_comes_the_Duchess");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Archie_still_sick":
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "Archie_still_sick2";
		break;

		case "Archie_still_sick2":
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "Exit_Archie_still_sick";
		break;

		case "Exit_Archie_still_sick":
			AddDialogExitQuest("The_Duchess_is_back");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Did_you_have_a_nice_walk":
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "Did_you_have_a_nice_walk2";
		break;

		case "Did_you_have_a_nice_walk2":
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "Exit_Did_you_have_a_nice_walk";
		break;

		case "Exit_Did_you_have_a_nice_walk":
			AddDialogExitQuest("Go_see_Kennedy_again");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "A_Nice_Dinner_Sir":
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "Exit_A_Nice_Dinner_Sir";
		break;

		case "Exit_A_Nice_Dinner_Sir":
			AddDialogExitQuest("The_Duchess_explains");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		
		
		
		
		
		

	
			}
}
