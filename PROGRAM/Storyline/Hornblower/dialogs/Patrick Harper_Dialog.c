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

		case "Bryan's_tale":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Bryan's_tale2";
		break;

		case "Bryan's_tale2":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Bryan's_tale3";
		break;

		case "Bryan's_tale3":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Bryan's_tale4";
		break;

		case "Bryan's_tale4":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Bryan's_tale5";
		break;

		case "Bryan's_tale5":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "Exit_Bryan's_tale";
		break;

		case "Exit_Bryan's_tale":
			AddDialogExitQuest("Go_explore_the_Tunnels");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Directions_for_Tunnel":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Directions_for_Tunnel2";
		break;

		case "Directions_for_Tunnel2":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Directions_for_Tunnel3";
		break;

		case "Directions_for_Tunnel3":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "Directions_for_Tunnel4";
		break;

		case "Directions_for_Tunnel4":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "Exit_Directions_for_Tunnel";
		break;

		case "Exit_Directions_for_Tunnel":
			AddDialogExitQuest("Down_the_rabbit_hole6");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "A_Room_with_a_view":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "A_Room_with_a_view2";
		break;

		case "A_Room_with_a_view2":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "Exit_A_Room_with_a_view";
		break;

		case "Exit_A_Room_with_a_view":
			AddDialogExitQuest("Sharpe_and_Ships_plans");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Another_Room_with_a_view":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "Another_Room_with_a_view2";
		break;

		case "Another_Room_with_a_view2":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit_Another_Room_with_a_view";
		break;

		case "Exit_Another_Room_with_a_view":
			AddDialogExitQuest("Sharpe_more_plans");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Spoke_with_miner":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "Exit_Spoke_with_miner";
		break;

		case "Exit_Spoke_with_miner":
			AddDialogExitQuest("Sharpe_and_the_burial");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Loyalty_forward":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "Exit_I_Chose_Teresa";
			link.l2 = DLG_TEXT[32];
			link.l2.go = "Exit_I_Chose_Riflemen";
		break;

		case "Exit_I_Chose_Teresa":
			AddDialogExitQuest("Chose_Teresa");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_I_Chose_Riflemen":
			AddDialogExitQuest("Chose_Riflemen");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "We_need_to_find_Sharpe":
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "We_need_to_find_Sharpe2";
		break;

		case "We_need_to_find_Sharpe2":
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "Exit_We_need_to_find_Sharpe";
		break;

		case "Exit_We_need_to_find_Sharpe":
			AddDialogExitQuest("Plantation_Battle");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "I'll_look_around":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "Exit_I'll_look_around";
		break;

		case "Exit_I'll_look_around":
			AddDialogExitQuest("Teresa_Cooper_Church");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Cooper_doing_gates":
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "Exit_Cooper_doing_gates";
		break;

		case "Exit_Cooper_doing_gates":
			AddDialogExitQuest("French_pull_back");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Escaping_to_ship":
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "Exit";
		break;

		case "You_must_see_this":
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "Exit_You_must_see_this";
		break;

		case "Exit_You_must_see_this":
			AddDialogExitQuest("Follow_Harper_Signal_Tower");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "See_Captain_Murray":
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "Exit";
		break;

		case "right_way":
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "Exit";
		break;

		case "back_from_scouting":
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "Exit";
		break;
	}
}
