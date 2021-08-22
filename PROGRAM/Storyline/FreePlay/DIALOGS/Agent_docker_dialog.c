//#include "DIALOGS\Agent_docker_dialog.h"
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
		case "exit":
			Diag.CurrentNode = Diag.TempNode; //"First time";
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

			Preprocessor_Add("mister", GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false));
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "busy":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "name_that_ship";
		break;

		case "name_that_ship":
			dialog.text = DLG_TEXT[4] + PChar.quest.agentquest.enemy_ship.name + DLG_TEXT[5] + GetMyLastName(CharacterFromID("TQ_Captain1")) + DLG_TEXT[6];
			if (PChar.sex == "woman")
			{
				link.l1 = DLG_TEXT[17] + PChar.quest.agentquest.enemy_ship.name + DLG_TEXT[18];
				link.l1.go = "cant_go_aboard";
			}
			else
			{
				link.l1 = DLG_TEXT[7];
				link.l1.go = "never_seen_you";
			}
		break;

		case "never_seen_you":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "im_off";
		break;

		case "im_off":
			dialog.text = DLG_TEXT[10] + GetMyLastName(CharacterFromID("TQ_Captain1")) + DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			AddDialogExitQuest("AgentQuest_ready_to_board");
			Diag.TempNode = "thanks";
			link.l1.go = "exit";
		break;

		case "thanks":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "exit";
		break;

		case "help_you":
			Preprocessor_Add("miss", GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false));
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "name_that_ship";
		break;

		case "cant_go_aboard":
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20] + GetMyLastName(CharacterFromID("TQ_Captain1")) + DLG_TEXT[21];
			AddDialogExitQuest("AgentQuest_ready_to_board");
			Diag.TempNode = "thanks2";
			link.l1.go = "exit";
		break;

		case "thanks2":
			Preprocessor_Add("madam", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false));
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23] + GetMyLastName(CharacterFromID("TQ_Captain1")) + DLG_TEXT[24];
			link.l1.go = "exit";
		break;

		case "not_expecting_anyone":
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "whats_in_it";
		break;

		case "whats_in_it":
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "heave_ho";
		break;

		case "heave_ho":
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "exit";
		break;

		case "job_done":
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "break_time";
		break;

		case "break_time":
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			AddDialogExitQuest("AgentQuest_docker2_leaves");
			link.l1.go = "exit";
		break;
	}
}