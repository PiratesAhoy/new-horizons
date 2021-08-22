//#include "DIALOGS\raoul rheims_dialog.h"

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
		case "First_meeting":
			Dialog.defAni = "dialog_stay1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.snd = "voice\RARH\RARH001";
			
			dialog.text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1];
			link.l1 = DLG_TEXT[2];
			link.l1.go = "exit";

			AddDialogExitQuest("Rheims_away_from_residence");
			NextDiag.TempNode = "first time";
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
			Dialog.snd = "voice\RARH\RARH002";			

			dialog.text = DLG_TEXT[3];
			link.l1 = DLG_TEXT[4];
			link.l1.go = "exit";

			if (pchar.quest.main_line == "talk_with_rheims_in_douwesen_tavern" || CheckQuestAttribute("RheimsBook", "30"))
			{
				Dialog.snd = "voice\RARH\RARH003";
				Dialog.Text = DLG_TEXT[5];
				Link.l1 = DLG_TEXT[6] + GetMyFullName(NPChar) + DLG_TEXT[7];
				Link.l1.go = "talk_in_tavern";
			}
			if (CheckQuestAttribute("RheimsBook", "31"))
			{
				Dialog.snd = "voice\RARH\RARH004";
				dialog.text = DLG_TEXT[8];
				link.l1 = DLG_TEXT[9];
				link.l1.go = "exit";
				pchar.quest.rheimsbook = "vincent_go_to_killing_rheims";
				AddDialogExitQuest("vincent_to_rheims_house");
			}
			NextDiag.TempNode = "first time";
		break;

		case "danielle_speak_with_almost_dead_rheims_node":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.snd = "voice\RARH\RARH005";

			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "danielle_speak_with_almost_dead_rheims";
		break;

		case "danielle_speak_with_almost_dead_rheims":
			Dialog.snd = "voice\RARH\RARH006";
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "danielle_speak_with_almost_dead_rheims_2";
		break;

		case "danielle_speak_with_almost_dead_rheims_2":
			Dialog.snd = "voice\RARH\RARH007";
			if (PChar.sex == "woman") Preprocessor_Add("person", XI_ConvertString("girl"));
			else Preprocessor_Add("person", XI_ConvertString("lad"));
			dialog.text = DLG_TEXT[14] + characters[GetCharacterIndex(DLG_TEXT[15])].lastname + DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "danielle_speak_with_almost_dead_rheims_3";
		break;

		case "danielle_speak_with_almost_dead_rheims_3":
			Dialog.snd = "voice\RARH\RARH008";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "danielle_speak_with_almost_dead_rheims_4";
		break;

		case "danielle_speak_with_almost_dead_rheims_4":
			Dialog.snd = "voice\RARH\RARH009";
			if (PChar.sex == "woman") Preprocessor_Add("person", XI_ConvertString("girl"));
			else Preprocessor_Add("person", XI_ConvertString("lad"));
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "danielle_speak_with_almost_dead_rheims_5";
		break;

		case "danielle_speak_with_almost_dead_rheims_5":
			Dialog.snd = "voice\RARH\RARH010";
			dialog.text = DLG_TEXT[22] + characters[getCharacterIndex(DLG_TEXT[23])].lastname + DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "exit";
			AddDialogExitQuest("start_quest_movie_speak_with_rheims_complete_2");
		break;

		case "talk_in_tavern":
			Dialog.snd = "voice\RARH\RARH011";
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "talk_in_tavern_2";
		break;

		case "talk_in_tavern_2":
			Dialog.snd = "voice\RARH\RARH012";
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "talk_in_tavern_3";
		break;

		case "talk_in_tavern_3":
			Dialog.snd = "voice\RARH\RARH013";
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "exit";
			AddDialogExitQuest("from_tavern_to_rheims_house_complete");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
