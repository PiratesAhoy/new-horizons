//#include "DIALOGS\Found_Blaze_1_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d; 
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting, TempInfoCharacterID_1, TempInfoCharacterID_2;
	int DonationSize;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "exit":
			NPChar.quest.meeting = NPC_meeting;
			DialogExit();
		break;

		case "First time":
			Dialog.defAni = "";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "";
			
			dialog.snd = "Voice\FOB1\FOB1001";
			d.Text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			AddDialogExitQuest("found_blaze_exit_1");
		break;

		case "Miracle_2":
			Dialog.defAni = "";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "";
			
			dialog.snd = "Voice\FOB1\FOB1002";
			d.Text = DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3];
			Link.l1.go = "exit";
			AddDialogExitQuest("Story_OfficersShutUpAfterFoundBlaze");
		break;

		case "Explanation":
			Dialog.defAni = "";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "";
			
			dialog.snd = "Voice\FOB1\FOB1003";
			d.Text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "Explanation_1";
		break;

		case "Explanation_1":
			dialog.snd = "Voice\FOB1\FOB1004";
			d.Text = DLG_TEXT[6] + Characters[GetCharacterIndex(DLG_TEXT[7])].ship.name + DLG_TEXT[8];
			Link.l1 = DLG_TEXT[9];
			if(Pchar.Reputation <= 30)
			{
				Link.l1.go = "Explanation_2_normal";
			}
			if(Pchar.Reputation >= 70)
			{
				Link.l1.go = "Explanation_2_normal";
			}
			if(Pchar.Reputation >= 30 && Pchar.Reputation <= 70)
			{
				Link.l1.go = "Explanation_2_normal";
			}
		break;

		case "Explanation_2_normal":
			dialog.snd = "Voice\FOB1\FOB1005";
			d.Text = DLG_TEXT[10];
			Link.l1 =  DLG_TEXT[11];
			Link.l1.go =  "Explanation_3";
		break;

		case "Explanation_3":
			dialog.snd = "Voice\FOB1\FOB1006";
			d.Text = DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "Explanation_4";
		break;

		case "Explanation_4":
			dialog.snd = "Voice\FOB1\FOB1007";
			d.Text = DLG_TEXT[14] + GetMyName(Pchar) + DLG_TEXT[15];
			Link.l1 = DLG_TEXT[16];
			Link.l1.go = "exit";
			DoQuestCheckDelay("Story_OfficersGoToTavernWithBlaze", 1.0);
		break;

		case "Talk_In_Tavern":
			dialog.snd = "Voice\FOB1\FOB1008";
			d.Text = DLG_TEXT[17];
			Link.l1 = DLG_TEXT[18];
			Link.l1.go = "exit";
			AddDialogExitQuest("found_blaze_Exit_in_Tavern_1");
		break;

		case "Talk_In_Tavern_1":
			dialog.snd = "Voice\FOB1\FOB1009";
			d.Text = DLG_TEXT[19];
			Link.l1 = DLG_TEXT[20];
			Link.l1.go = "exit";
			AddDialogExitQuest("found_blaze_Exit_in_Tavern_2");
		break;

		case "Talk_In_Tavern_2":
			dialog.snd = "Voice\FOB1\FOB1010";
			d.Text = DLG_TEXT[21];
			Link.l1 = DLG_TEXT[22];
			Link.l1.go = "Talk_In_Tavern_3";
		break;

		case "Talk_In_Tavern_3":
			dialog.snd = "Voice\FOB1\FOB1011";
			d.Text = DLG_TEXT[23];
			Link.l1 = DLG_TEXT[24];
			Link.l1.go = "exit";
			//AddDialogExitQuest("found_blaze_Exit_Danielle");
		break;

		case "LetUsGoWithYou":
			dialog.snd = "Voice\FOB1\FOB1012";
			Dialog.Text = GetMyName(PChar) + DLG_TEXT[25];
			Link.l1 = DLG_TEXT[26];
			Link.l1.go = "LetUsGoWithYou_1";
		break;

		case "LetUsGoWithYou_1":
			dialog.snd = "Voice\FOB1\FOB1013";
			Dialog.Text = DLG_TEXT[27];
			Link.l1 = DLG_TEXT[28];
			Link.l1.go = "LetUsGoWithYou_3";
		break;

		case "LetUsGoWithYou_3":
			dialog.snd = "Voice\FOB1\FOB1014";
			Dialog.Text = DLG_TEXT[29];
			Link.l1 = DLG_TEXT[30];
			Link.l1.go = "LetUsGoWithYou_4";
		break;

		case "LetUsGoWithYou_4":
			dialog.snd = "Voice\FOB1\FOB1015";
			AddDialogExitQuest("Fem_LeavingOfficersOnboard");
			Diag.Tempnode = "LetUsGoWithYou_again";
			Dialog.Text = DLG_TEXT[31];
			Link.l1 = DLG_TEXT[32];
			Link.l1.go = "Exit";
		break;

		case "LetUsGoWithYou_again":
			Diag.Tempnode = "LetUsGoWithYou_again";
			dialog.snd = "Voice\FOB1\FOB1016";
			Dialog.Text = DLG_TEXT[33];
			Link.l1 = DLG_TEXT[34];
			Link.l1.go = "Exit";
		break;

		case "WeAreWaiting":
			dialog.snd = "Voice\FOB1\FOB1017";
			Diag.Tempnode = "WeAreWaiting";
			Dialog.Text = DLG_TEXT[35];
			Link.l1 = DLG_TEXT[36];
			Link.l1.go = "Exit";
		break;

		case "beauvallet_captured":
			dialog.snd = "Voice\FOB1\FOB1018";
			Diag.Tempnode = "beauvallet_captured";
			Dialog.Text = DLG_TEXT[37];
			Link.l1 = DLG_TEXT[38];
			Link.l1.go = "Exit";
		break;


	}

}
