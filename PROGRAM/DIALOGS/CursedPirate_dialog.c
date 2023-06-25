//#include "DIALOGS\CursedPirate_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
// --->SJG
			if (CheckQuestAttribute("Beckett_talk", "Nomainquest")) // KK
			{
				Locations[FindLocation("quest_redmond_tavern")].vcskip = true;
				AddDialogExitQuest("exit_from_silehard_complete");
				AddDialogExitQuest("player_back");
				CloseQuestHeader("Story_OxbayCaptured");
				locations[FindLocation("Redmond_town_01")].reload.l11.go = "quest_redmond_tavern";
			}
// <--SJG
		break;

		case "fight1":
			AddDialogExitQuest("Story_CursedCoinsFirstFightWithPirates");
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "fight2":
			AddDialogExitQuest("Story_CursedCoinsFightPiratesAgain");
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "First time":
			Dialog.defAni = "dialog_stay2";
			Dialog.defCam = "2";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			

			pchar.quest.Story_CursedCoins = "TalkToMcDorey";
			
			dialog.snd = "Voice\CUPI\CUPI001";
			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "Node_1";
			Link.l2 = DLG_TEXT[2];
			Link.l2.go = "Node_2";
			NPC_Meeting = "1"; 
	
		break;

		case "Node_1":
			dialog.snd = "Voice\CUPI\CUPI002";
			d.Text = DLG_TEXT[3];
			Link.l1 = DLG_TEXT[4];
			Link.l1.go = "Node_3";
			Link.l2 = DLG_TEXT[5];
			Link.l2.go = "Node_2";
		break;

		case "Node_2":
			dialog.snd = "Voice\CUPI\CUPI003";
			d.Text = DLG_TEXT[6];
			Link.l1 = DLG_TEXT[7];
			Link.l1.go = "Node_4";
			Link.l2 = DLG_TEXT[8];
			Link.l2.go = "Node_5";
		break;

		case "Node_3":
			dialog.snd = "Voice\CUPI\CUPI004";
			d.Text = DLG_TEXT[9];
			Link.l1 = DLG_TEXT[10];
			Link.l1.go = "Node_4";
			Link.l2 = DLG_TEXT[11];
			Link.l2.go = "Node_5";
			AddQuestRecord("chest", 2);
		break;

		case "Node_4":
			dialog.snd = "Voice\CUPI\CUPI005";
			d.Text = DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "Fight1";			
		break;

		case "Node_5":
			dialog.snd = "Voice\CUPI\CUPI006";
			d.Text = DLG_TEXT[14];
			Link.l1 = DLG_TEXT[15];
			Link.l1.go = "Node_6";			
		break;

		case "Node_6":
			dialog.snd = "Voice\CUPI\CUPI007";
			TakeItemFromCharacter(Pchar,"chest");
			AddDialogExitQuest("Story_CursedCoinsGiveOutChest");
			d.Text = DLG_TEXT[16];
			Link.l1 = DLG_TEXT[17];
			Link.l1.go = "Exit";	
			AddQuestRecord("chest", 3);		
		break;

		case "We_are_immortal":
			dialog.snd = "Voice\CUPI\CUPI008";
			d.Text = DLG_TEXT[18];
			Link.l1 = DLG_TEXT[20];
			Link.l1.go = "We_are_immortal_1";
			Link.l2 = DLG_TEXT[19];
			Link.l2.go = "fight2";
			AddQuestRecord("chest", 4);
		break;

		case "We_are_immortal_1":
			dialog.snd = "Voice\CUPI\CUPI009";
			d.Text = DLG_TEXT[21];
			Link.l1 = DLG_TEXT[22];
			Link.l1.go = "Node_6";
			Link.l2 = DLG_TEXT[23];
			Link.l2.go = "fight2";
		break;
	}
}
