//#include "DIALOGS\ralph fawn_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

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
			Dialog.snd = "voice\RAFA\RAFA001";
			
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
		break;
		
		case "turks_prison":
			Dialog.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "Exit_1";
		break;
		
		case "escape_in_coffin_guard_talk_self":
			Dialog.Text = DLG_TEXT[2];
			AddDialogExitQuest("escape_in_coffin_video");
			Link.l1.go = "Exit_2"; 
		break;
		
		//Talk to Jack at smugglers den smuggler_1
		case "Smuggler_Jack_Talk":
			Dialog.Text = DLG_TEXT[3];		
			Link.l1 = DLG_TEXT[4];
			Link.l1.go = "Smuggler_Jack_Talk_options"; 
		break;
		
		//Gives player two choices pay 10000 or attack
		case "Smuggler_Jack_Talk_options":
			if(pchar.money >= 10000)  {
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			Link.l1.go = "Figh_smugglers"; 
			link.l2 = DLG_TEXT[7];
			Link.l2.go = "Bribe_smugglers"; 
			
			}
			else {
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			Link.l1.go = "Figh_smugglers"; 
			}	
		break;
	
		
		case "Figh_smugglers":
			DialogExit();
			AddDialogExitQuest("At_smugglers_fight_action");
		break;
		
		case "Bribe_smugglers":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Figh_smugglers";
			link.l2 = DLG_TEXT[10];
			link.l2.go = "Bribe_smugglers2";
		break;
		
		case "Bribe_smugglers2":
			PlaySound("interface\coins7.wav");
			Logit("Gold removed -10000");
			Dialog.Text = DLG_TEXT[11];
			Link.l1 = DLG_TEXT[12];
			AddDialogExitQuest("At_smugglers_fight_bribe");
			Link.l1.go = "Exit_2";
		break;
		
		case "Exit_1":
			Diag.CurrentNode = "turks_prison";
			DialogExit();
		break;
		
		case "Exit_2":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
		
		case "Shipwreck_will_talk":
			Dialog.Text = DLG_TEXT[13];		
			Link.l1 = DLG_TEXT[14];
			Link.l1.go = "Shipwreck_will_talk_1";
			
		break;
		
		case "Shipwreck_will_talk_1":
			Dialog.Text = DLG_TEXT[15];		
			AddDialogExitQuest("Sailor_talk_status_check");
			Link.l1.go = "Exit_2";
			
		break;
		
		case "Shipwreck_will_talk2":
			Dialog.Text = DLG_TEXT[16];		
			Link.l1 = DLG_TEXT[17];
			AddDialogExitQuest("Sailor_talk_status_check");
			Link.l1.go = "Exit_2";
		break;
		
		case "Shipwreck_will_talk_corpse":
			Dialog.Text = DLG_TEXT[18];		
			AddDialogExitQuest("Video_at_shipwreck_dutchman");
			Link.l1.go = "Exit_2";
		break;
		
		case "MACCUS_talk":
			Dialog.Text = DLG_TEXT[19];		
			AddDialogExitQuest("Davy_talk_Sailor_1");
			Link.l1.go = "Exit_2";
		break;
		// Don't listen to him!  
		case "Sailor_2_to_davy":
			Dialog.Text = DLG_TEXT[20];		
			AddDialogExitQuest("Davy_talk_Sailor_2");
			Link.l1.go = "Exit_2";
		break;
		// I'll take my chances, Sir.  
		case "Sailor_2_to_davy_2":
			Dialog.Text = DLG_TEXT[21];		
			AddDialogExitQuest("Davy_talk_Sailor_2_2");
			Link.l1.go = "Exit_2";
		break;
		// Cruel bastard! 
		case "Sailor_1_to_davy_2":
			Dialog.Text = DLG_TEXT[22];		
			AddDialogExitQuest("Davy_talk_Sailor_1_3");
			Link.l1.go = "Exit_2";
		break;
		
		// I will serve.
		case "Sailor_1_to_davy_3":
			Dialog.Text = DLG_TEXT[23];		
			AddDialogExitQuest("Davy_talk_will");
			Link.l1.go = "Exit_2";
		break;

		//Tortuga crew dialogues
		case "Crewman_to_gibbs_tavern":
			Dialog.Text = DLG_TEXT[24];		
			AddDialogExitQuest("Gibbs_to_crewman_tavern_after");
			Link.l1.go = "Exit_2";
		break;
		
		//Tortuga crew dialogues
		case "Crewman2_to_gibbs_tavern":
			Dialog.Text = DLG_TEXT[25];		
			AddDialogExitQuest("Gibbs_to_crewman2_tavern_after");
			Link.l1.go = "Exit_2";
		break;
		
		//Tortuga crew dialogues
		case "Crewman3_to_gibbs_tavern":
			Dialog.Text = DLG_TEXT[26];		
			AddDialogExitQuest("Gibbs_to_crewman3_tavern_after");
			Link.l1.go = "Exit_2";
		break;
	
	}
}