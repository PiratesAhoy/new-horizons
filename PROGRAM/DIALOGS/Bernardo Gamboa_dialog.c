//#include "DIALOGS\Bernardo Gamboa_dialog.h"
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


		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\BEGA\BEGA001";
			dialog.text = DLG_TEXT[0];
			if (characters[getCharacterIndex("Toff Oremans")].quest.daughter == "help_begin")
			{
				link.l1 = DLG_TEXT[1];
				link.l1.go = "bad_help_1";
			}
			if (characters[getCharacterIndex("Toff Oremans")].quest.daughter == "governor")
			{
				link.l1 = DLG_TEXT[2];
				link.l1.go = "good_help_1";
			}
			link.l2 = DLG_TEXT[3];
			link.l2.go = "exit_node";
		break;

		case "good_help_1":
			dialog.snd = "Voice\BEGA\BEGA002";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "good_help_2";
		break;

		case "good_help_2":
			dialog.snd = "Voice\BEGA\BEGA003";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			characters[GetCharacterIndex("Corentin Lucay")].dialog.currentnode = "one";
			AddDialogExitQuest("talk_in_gamboa_ship");
		break;

		case "one":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\BEGA\BEGA004";
			dialog.text = DLG_TEXT[8] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[9])]) + DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
			characters[GetCharacterIndex("Corentin Lucay")].dialog.currentnode = "two";
			AddDialogExitQuest("talk_in_gamboa_ship");
		break;

		case "two":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\BEGA\BEGA005";
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "exit";
			AddDialogExitQuest("gamboa_died");
		break;

		case "bad_help_1":
			dialog.snd = "Voice\BEGA\BEGA006";
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "bad_help_2";
		break;

		case "bad_help_2":
			dialog.snd = "Voice\BEGA\BEGA007";
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "bad_help_3";
		break;

		case "bad_help_3":
			dialog.snd = "Voice\BEGA\BEGA008";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit";
			characters[getCharacterIndex("Toff Oremans")].quest.daughter = "bad_complete";
			AddDialogExitQuest("bad_fight_in_ship");
		break;

// KK -->
		case "you_again":
			dialog.snd = "Voice\BEGA\BEGA008";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
			characters[getCharacterIndex("Toff Oremans")].quest.daughter = "bad_complete";
			AddDialogExitQuest("bad_fight_in_ship");
		break;
// <-- KK

		case "exit_node":
			AddDialogExitQuest("from_the_ship");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
	}
}
