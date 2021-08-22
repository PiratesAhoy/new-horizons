//#include "DIALOGS\Evaristo Filho_dialog.h"

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
			
			dialog.snd = "Voice\EVFI\EVFI001";
			dialog.text = DLG_TEXT[0] + characters[getCharacterIndex(DLG_TEXT[1])].lastname + DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "exit";
			
			if (pchar.quest.main_line == "blaze_found_book_in_rheims_house")
			{
				dialog.snd = "Voice\EVFI\EVFI002";
				dialog.text = DLG_TEXT[4];
				link.l1 = DLG_TEXT[5];
				link.l1.go = "node_2";
			}
			// GR: if you haven't already triggered the Rheims House Easter egg, you're not playing "Tales of a Sea Hawk", and you don't have a cargo quest which could time out due to time travel,
			// and none of the "Hard Labours of an Assassin" timers are active,
			// allow Easter egg to trigger
			if (!CheckAttribute(PChar, "quest.rheims_house.done") && FindCurrentStoryline() != FindStoryline("NewHorizons") && !CheckQuestAttribute("generate_trade_quest_progress", "begin")
			&& !CheckAttribute(PChar, "quest.Hit_timer1") && !CheckAttribute(PChar, "quest.Hit_timer2") && !CheckAttribute(PChar, "quest.Hit_timer3") && !CheckAttribute(PChar, "quest.Hit_timer4") && !CheckAttribute(PChar, "quest.Hit_timer5"))
			{
				if (GetDayTime() == DAY_TIME_NIGHT) link.l1 = DLG_TEXT[8];
				else link.l1 = DLG_TEXT[9];
				AddDialogExitQuest("Rheims_house_setup");
			}

			NextDiag.TempNode = "first time";
		break;

		case "node_2":
			dialog.snd = "Voice\EVFI\EVFI003";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			AddDialogExitQuest("back_to_smuggler_guard");
		break;

// GR: Nathaniel's dialog in Rheims House Easter egg -->
		case "Nathaniel_surprise":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11] + GetMyFullName(PChar) + DLG_TEXT[12];
			link.l1.go = "Nathaniel_Rheims";
		break;

		case "Nathaniel_Rheims":
			dialog.text = DLG_TEXT[13] + GetMyFullName(NPChar) + DLG_TEXT[14];
			if (sti(PChar.quest.rheims_house.current_year) != 1750)
			{
				link.l1 = DLG_TEXT[15];
				link.l1.go = "Nathaniel_year";
			}
			else
			{
				link.l1 = DLG_TEXT[25];
				link.l1.go = "Nathaniel_search";
			}
		break;

		case "Nathaniel_year":
			dialog.text = GetDataYear() + DLG_TEXT[16];
			link.l1 = DLG_TEXT[17] + PChar.quest.rheims_house.current_year + DLG_TEXT[18];
			link.l1.go = "Nathaniel_search";
		break;

		case "Nathaniel_search":
			if (sti(PChar.quest.rheims_house.current_year) != 1750)
			{
				dialog.text = DLG_TEXT[19];
				if (sti(PChar.quest.rheims_house.current_year) < 1750) dialog.text = dialog.text + DLG_TEXT[20];
				dialog.text = dialog.text + DLG_TEXT[21];
			}
			else dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[22];
			AddDialogExitQuest("Rheims_exit_setup");
			link.l1.go = "Exit";
			NextDiag.TempNode = "Nathaniel_continue_search";
		break;

		case "Nathaniel_continue_search":
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "Exit";
		break;
// <-- GR: End of Rheims House Easter egg

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
