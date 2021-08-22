//#include "DIALOGS\Found_Blaze_2_dialog.h"
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

		case "Exit_to_Tavern":
			NPChar.quest.meeting = NPC_meeting;
			DoQuestCheckDelay("Story_OfficersGoToTavernWithBlaze", 1.0);
			DialogExit();
		break;

		case "Exit_3":
			NPChar.quest.meeting = NPC_meeting;
			DoQuestCheckDelay("Story_OfficersShutUpAfterFoundBlaze", 2.0);
			DialogExit();	
		break;


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

			dialog.snd = "Voice\FOB2\FOB2001";
			d.Text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;


		case "Miracle":
			Dialog.defAni = "";
			Dialog.defLinkAni = "";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "";
			
			dialog.snd = "Voice\FOB2\FOB2002";
			d.Text = DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3];
			Link.l1.go =  "exit";
			AddDialogExitQuest("found_blaze_exit_2");
		break;

		case "Talk_In_Tavern":
			dialog.snd = "Voice\FOB2\FOB2003";
			d.Text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "exit";
			AddDialogExitQuest("found_blaze_Exit_in_Tavern_1");
		break;

		case "Talk_In_Tavern_1":
			dialog.snd = "Voice\FOB2\FOB2004";
			d.Text = DLG_TEXT[6];
			Link.l1 = DLG_TEXT[7];
			Link.l1.go = "exit";
			AddDialogExitQuest("found_blaze_Exit_in_Tavern_2");
		break;

		case "Talk_In_Tavern_2":
			dialog.snd = "Voice\FOB2\FOB2005";
			d.Text = DLG_TEXT[8];
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "Talk_In_Tavern_3";
		break;

		case "Talk_In_Tavern_3":
			dialog.snd = "Voice\FOB2\FOB2006";
			d.Text = DLG_TEXT[10];
			Link.l1 = DLG_TEXT[11];
			Link.l1.go = "Exit_Danielle";
		break;

		case "WeAreWaiting":
			dialog.snd = "Voice\FOB2\FOB2007";
			Diag.Tempnode = "WeAreWaiting";
			Dialog.Text = DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "Exit";
		break;

		case "beauvallet_captured":
			dialog.snd = "Voice\FOB2\FOB2008";
			Diag.Tempnode = "beauvallet_captured";
			Dialog.Text = DLG_TEXT[14];
			Link.l1 = DLG_TEXT[15];
			Link.l1.go = "Exit";
		break;

	}

}
