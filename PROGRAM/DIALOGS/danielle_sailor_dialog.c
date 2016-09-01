//#include "DIALOGS\danielle_sailor_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

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
			
			dialog.snd = "Voice\DASA\DASA001";
			Dialog.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "node_2";
			
			if (pchar.quest.main_line == "blaze_to_incas_collection_begin_6" || pchar.quest.main_line == "blaze_to_incas_collection_begin")
			{
				dialog.snd = "Voice\DASA\DASA002";
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "exit_to_ship";
				link.l2 = DLG_TEXT[4];
				link.l2.go = "exit";
			}
			//if (pchar.quest.main_line == "kill_pirate_06")
			//trace ("characters[GetCharacterIndex(Pirate Captain 06)].act.hp" + characters[GetCharacterIndex(Pirate Captain 06)].act.hp);
			if (pchar.quest.main_line == "kill_pirate_06")
			{
				dialog.snd = "Voice\DASA\DASA003";
				dialog.text = DLG_TEXT[5];
				link.l1 = DLG_TEXT[6];
				link.l1.go = "wait_two_days";
			}
			if (pchar.quest.main_line == "blaze_to_incas_collection_begin_7")
			{
				dialog.snd = "Voice\DASA\DASA004";
				dialog.text = DLG_TEXT[7];
				link.l1 = DLG_TEXT[8];
				link.l1.go = "statuets_exit";
			}
			
			NPChar.quest.first_talk = "1";
			NextDiag.TempNode = "first time";
		break;

		case "statuets_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("danielle_sailor_statuets_exit");
		break;

		case "wait_two_days":
			AddDialogExitQuest("find_statuets_complete");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "node_2":
			dialog.snd = "Voice\DASA\DASA005";
			Dialog.Text = DLG_TEXT[9];
			Link.l1 = DLG_TEXT[10];
			Link.l1.go = "exit";
			SetQuestHeader("Talk_with_Ralph_Fawn_in_quest_tavern");
			AddQuestRecord("Talk_with_Ralph_Fawn_in_quest_tavern", 1);
			ChangeCharacterAddressGroup(&characters[GetCharacterIndex("Blaze")], "Quest_redmond_tavern", "goto", "goto2");
			ChangeCharacterAddressGroup(&characters[GetCharacterIndex("Ralph Fawn")], "Quest_redmond_tavern", "goto", "goto3");
		break;

		case "exit_to_ship":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("exit_to_ship");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
