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

		case "Pellew_Sharpe_and_Tunnel":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Exit_Pellew_Sharpe_and_Tunnel";
		break;

		case "Exit_Pellew_Sharpe_and_Tunnel":
			AddDialogExitQuest("Off_to_see_Larrs");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "We_will_go_to_jail":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Exit_We_will_go_to_jail";
		break;

		case "Exit_We_will_go_to_jail":
			AddDialogExitQuest("Wellesley_Sharpe_Harper_Go");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Plan_for_Smugglers_House":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Plan_for_Smugglers_House2";
		break;

		case "Plan_for_Smugglers_House2":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Plan_for_Smugglers_House3";
		break;

		case "Plan_for_Smugglers_House3":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "Plan_for_Smugglers_House4";
		break;

		case "Plan_for_Smugglers_House4":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "Plan_for_Smugglers_House5";
		break;

		case "Plan_for_Smugglers_House5":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "Plan_for_Smugglers_House6";
		break;

		case "Plan_for_Smugglers_House6":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "Exit_Plan_for_Smugglers_House";
		break;

		case "Exit_Plan_for_Smugglers_House":
			AddDialogExitQuest("Pellew_confirms_plan");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Time_to_get_to_the_ship":
			dialog.text = DLG_TEXT[18] + Pchar.lastname + DLG_TEXT[20];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit_Time_to_get_to_the_ship";
		break;

		case "Exit_Time_to_get_to_the_ship":
			AddDialogExitQuest("In_ship_for_Jamaica_with_Wellesley");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Defeat_crack_troops":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "Defeat_crack_troops2";
		break;

		case "Defeat_crack_troops2":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "Defeat_crack_troops3";
		break;

		case "Defeat_crack_troops3":
			PlaySound("VOICE\ENGLISH\Well03.wav");
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "Defeat_crack_troops4";
		break;

		case "Defeat_crack_troops4":
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "Defeat_crack_troops5";
		break;

		case "Defeat_crack_troops5":
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "Exit_Defeat_crack_troops";
		break;

		case "Exit_Defeat_crack_troops":
			AddDialogExitQuest("Pellew_gives_Ship");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Work_with_Sharpe":
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "Work_with_Sharpe2";
		break;

		case "Work_with_Sharpe2":
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[23] + "?";
			link.l1.go = "Work_with_Sharpe3";
		break;

		case "Work_with_Sharpe3":
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "Work_with_Sharpe4";
		break;

		case "Work_with_Sharpe4":
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Exit_Work_with_Sharpe";
		break;

		case "Exit_Work_with_Sharpe":
			AddDialogExitQuest("Sharpe_and_the_traitor");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Just_in_time":
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			dialog.text = DLG_TEXT[60];
			link.l1 = DLG_TEXT[61];
			link.l1.go = "Just_in_time2";
		break;

		case "Just_in_time2":
			dialog.text = DLG_TEXT[62];
			link.l1 = DLG_TEXT[63];
			link.l1.go = "Just_in_time3";
		break;

		case "Just_in_time3":
			LAi_ActorRunToLocation(characterFromID("Matthews"), "reload", "reload_2_city", "none", "", "", "",0.0);
			LAi_ActorRunToLocation(characterFromID("Oldroyd"), "reload", "reload_2_city", "none", "", "", "",0.0);
			LAi_ActorRunToLocation(characterFromID("Styles"), "reload", "reload_2_city", "none", "", "", "",0.0);
			dialog.text = DLG_TEXT[64];
			link.l1 = DLG_TEXT[65];
			link.l1.go = "Just_in_time4";
		break;

		case "Just_in_time4":
			dialog.text = DLG_TEXT[66];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "Exit_Just_in_time";
		break;

		case "Exit_Just_in_time":
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			AddDialogExitQuest("Antigua_Land_Battle");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "The_reinforcements":
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "The_reinforcements2";
		break;

		case "The_reinforcements2":
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "The_reinforcements3";
		break;

		case "The_reinforcements3":
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "The_reinforcements4";
		break;

		case "The_reinforcements4":
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "Exit_The_reinforcements";
		break;

		case "Exit_The_reinforcements":
			AddDialogExitQuest("Hold_the_line");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Safe_and_Promotion":
			dialog.text = DLG_TEXT[54];
			link.l1.go = "Safe_and_Promotion2";
		break;

		case "Safe_and_Promotion2":
			PlaySound("VOICE\ENGLISH\Well01.wav");
			dialog.text = DLG_TEXT[55];
			link.l1.go = "Exit_Safe_and_Promotion";
		break;

		case "Exit_Safe_and_Promotion":
			AddDialogExitQuest("Sharpe_Promoted");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Promotion_Confirmed":
			PlaySound("VOICE\ENGLISH\Well02.wav");
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "Promotion_Confirmed2";
		break;

		case "Promotion_Confirmed2":
			dialog.text = DLG_TEXT[59];
			link.l1.go = "Exit_Promotion_Confirmed";
		break;

		case "Exit_Promotion_Confirmed":
			AddDialogExitQuest("Battle_Preparations_Antigua");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "A_damn_fine_job":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "A_damn_fine_job2";
		break;

		case "A_damn_fine_job2":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[41] + " " + DLG_TEXT[25];
			link.l1.go = "A_damn_fine_job3";
		break;

		case "A_damn_fine_job3":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "A_damn_fine_job4";
		break;

		case "A_damn_fine_job4":
			dialog.text = DLG_TEXT[28];
			link.l1.go = "Exit_A_damn_fine_job";
		break;

		case "Exit_A_damn_fine_job":
			AddDialogExitQuest("Midshipman_Sharpe");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Ship_introduction":
			dialog.text = DLG_TEXT[67];
			link.l1 = DLG_TEXT[68];
			link.l1.go = "Ship_introduction2";
		break;

		case "Ship_introduction2":
			dialog.text = DLG_TEXT[69];
			link.l1 = DLG_TEXT[70];
			link.l1.go = "Exit_Ship_introduction";
		break;

		case "Exit_Ship_introduction":
			AddDialogExitQuest("Got_to_find_Sharpe");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Where_to_find_Sharpe":
			dialog.text = DLG_TEXT[71];
			link.l1 = DLG_TEXT[72];
			link.l1.go = "Where_to_find_Sharpe2";
		break;

		case "Where_to_find_Sharpe2":
			dialog.text = DLG_TEXT[73];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "Where_to_find_Sharpe3";
		break;

		case "Where_to_find_Sharpe3":
			dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "Where_to_find_Sharpe4";
		break;

		case "Where_to_find_Sharpe4":
			dialog.text = DLG_TEXT[76];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "Exit_Where_to_find_Sharpe";
		break;

		case "Exit_Where_to_find_Sharpe":
			AddDialogExitQuest("Wind_up_scene");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;



			}
}
