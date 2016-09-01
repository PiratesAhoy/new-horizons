//#include "DIALOGS\Artois Voysey_dialog.h"

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
		break;

		case "exit1":
			AddDialogExitQuest("Leave_Voysey");
			Diag.CurrentNode = "continue2";
			DialogExit();
			AddQuestRecord("artois", 3);
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
			
			dialog.snd = "Voice\ARVO\ARVO001";
			d.Text = DLG_TEXT[0];
			if (PChar.sex == "man")
			{
				Link.l1 = DLG_TEXT[1]; 
			}
			else 
			{
				Link.l1 = DLG_TEXT[2]; 
			}
			Link.l1.go = "continue";
		break;

		case "continue":
			dialog.snd = "Voice\ARVO\ARVO002";
			d.Text = DLG_TEXT[3];
			Link.l1 = PCharPhrase (DLG_TEXT[4], DLG_TEXT[5] + GetMyName(Pchar) + DLG_TEXT[6]);
			Link.l1.go = "continue2";
		break;

		case "continue2":
			dialog.snd = "Voice\ARVO\ARVO003";
			d.Text = DLG_TEXT[7];
			Link.l99 = DLG_TEXT[8];
			Link.l99.go = "exit1";
			Link.l2 = DLG_TEXT[9];
			Link.l2.go = "listed";
		break;

		case "listed":
			AddDialogExitQuest("Voysey_listed");
			AddQuestRecord("artois", 2);
			Diag.CurrentNode = "officer_Artois";
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "officer_Artois":
			dialog.snd1 = "Voice\ARVO\ARVO004";
			dialog.snd2 = "Voice\ARVO\ARVO005";
			dialog.snd3 = "Voice\ARVO\ARVO006";
			Diag.TempNode = "officer_Artois";
			d.Text = RandPhrase (DLG_TEXT[10], DLG_TEXT[11], DLG_TEXT[12], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "exit";
		break;

		case "Captured":
			dialog.snd = "Voice\ARVO\ARVO007";
			d.Text = DLG_TEXT[14];
			Link.l1 = DLG_TEXT[15];
			Link.l1.go = "continue4";
		break;

		case "continue4":
			dialog.snd = "Voice\ARVO\ARVO008";
			d.Text = DLG_TEXT[16];
			Link.l1 = DLG_TEXT[17];
			Link.l1.go = "continue5";
			Link.l2 = DLG_TEXT[18];
			Link.l2.go = "continue6";
		break;

		case "continue5":
			dialog.snd = "Voice\ARVO\ARVO009";
			pchar.quest.treasure_found.win_condition.l1 = "locator";
			pchar.quest.treasure_found.win_condition.l1.location = "Douwesen_shore_ship";
			pchar.quest.treasure_found.win_condition.l1.locator_group = "randitem";
			pchar.quest.treasure_found.win_condition.l1.locator = "randitem1";
			pchar.quest.treasure_found.win_condition = "treasure_found";
			NPChar.loyality = makeint(NPChar.loyality) - 5;
			d.Text = DLG_TEXT[19];
			Link.l1 = DLG_TEXT[20];
			Link.l1.go = "exit";
			OfficersReaction("bad");
			AddDialogExitQuest("Voysey_listed_2");
			AddQuestRecord("artois", 11);
		break;
		
		case "continue6":
			dialog.snd = "Voice\ARVO\ARVO010";
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			if (GetNationRelation2MainCharacter(PORTUGAL) == RELATION_ENEMY)
			{
				link.l1.go = "continue7";
			}
			else
			{
				link.l1.go = "exit";
			}
			AddQuestRecord("artois", 12);
			AddDialogExitQuest("prepare_shoot_in_artois");
		break;
		
		case "continue7":
			dialog.snd = "Voice\ARVO\ARVO011";
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "continue_8";
		break;
		
		case "continue_8":
			dialog.snd = "Voice\ARVO\ARVO012";
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "exit";
			AddDialogExitQuest("portugal_becomes_neutral");
			AddQuestRecord("artois", 13);
		break;
		
		case "final_talk":
			dialog.snd = "Voice\ARVO\ARVO013";
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "final_talk_2";
		break;
		
		case "final_talk_2":
			dialog.snd = "Voice\ARVO\ARVO014";
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "exit";
			pchar.quest.artois_line = "completed";
			NPChar.Dialog.Filename = "Enc_Officer_dialog.c"; // PB
			Diag.TempNode = "Hired"; // PB
		break;
	}
}
