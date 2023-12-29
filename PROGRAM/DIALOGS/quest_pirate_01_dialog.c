//#include "DIALOGS\quest_pirate_01_dialog.h"

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
		// ----------------------------------- Диалог первый - первая встреча
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\QUP1\QUP1001";

			NextDiag.TempNode = "first time";

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			if (pchar.quest.main_line == "ines_info_denied")
			{
				Dialog.snd = pcharrepphrase("voice\QUP1\QUP1002", "voice\QUP1\QUP1003");
				dialog.text = pcharrepphrase(DLG_TEXT[2], DLG_TEXT[3]);
				link.l1 = pcharrepphrase(DLG_TEXT[4], DLG_TEXT[5]);
				link.l1.go = "ines_info_denied_2";
			}
			if (pchar.quest.main_line == "blaze_talk_with_innes_diaz_complete_21")
			{
				Dialog.snd = pcharrepphrase("voice\QUP1\QUP1004", "voice\QUP1\QUP1005");
				dialog.text = pcharrepphrase(DLG_TEXT[6], DLG_TEXT[7]);
				link.l1 = DLG_TEXT[8];
				link.l1.go = "ines_info_denied_4";
			}
			if (pchar.quest.main_line == "blaze_to_incas_collection_begin_1")
			{
				Dialog.snd = "voice\QUP1\QUP1006";
				Preprocessor_Add("sir", strlower(GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false))); // DeathDaisy
				dialog.text = DLG_TEXT[9] + pchar.lastname + DLG_TEXT[10];
				link.l1 = DLG_TEXT[11];
				link.l1.go = "blaze_to_incas_collection_begin_2";
			}
			if (pchar.quest.main_line == "blaze_to_incas_collection_begin_2")
			{
				Dialog.snd = "voice\QUP1\QUP1007";
				dialog.text = DLG_TEXT[13];
				link.l1 = DLG_TEXT[14];
				link.l1.go = "go_with_blaze";
				link.l2 = DLG_TEXT[15];
				link.l2.go = "go_one";
			}
			if (pchar.quest.main_line == "blaze_to_incas_collection_begin_3")
			{
				Dialog.snd = "voice\QUP1\QUP1008";
				dialog.text = DLG_TEXT[16];
				link.l1 = DLG_TEXT[17];
				link.l1.go = "exit";
			}
			if (pchar.quest.main_line == "blaze_to_incas_collection_begin_4")
			{
				Dialog.snd = "voice\QUP1\QUP1009";
				dialog.text = DLG_TEXT[18];
				link.l1 = DLG_TEXT[19];
				link.l1.go = "blaze_to_incas_collection_begin_5";
			}
			if (pchar.quest.main_line == "blaze_to_incas_collection_begin_5" && pchar.location == "Douwesen_jungle_03")
			{
				Dialog.snd = "voice\QUP1\QUP1010";
				dialog.text = DLG_TEXT[20];
				link.l1 = DLG_TEXT[21];
				link.l1.go = "blaze_to_incas_collection_begin_6";
			}
		break;

		case "go_with_blaze":
			Dialog.snd = "voice\QUP1\QUP1011";
			dialog.text = DLG_TEXT[22] + pchar.lastname + DLG_TEXT[23];
			if (makeint(pchar.money) >= 100)
			{
				link.l1 = DLG_TEXT[24];
				link.l1.go = "go_with_blaze_2";
			}
			link.l2 = DLG_TEXT[25];
			link.l2.go = "go_one";
		break;

		case "go_one":
			Dialog.snd = "voice\QUP1\QUP1012";
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "exit";
			AddDialogExitQuest("quest_pirate_01_exit_go_one");
		break;

		case "go_with_blaze_2":
			Dialog.snd = "voice\QUP1\QUP1013";
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(pchar, -100);
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "exit";
			AddQuestRecord("blaze_to_incas_collection", 3);
			AddDialogExitQuest("prepare_go_to_pirate_fort_complete");
		break;

		case "blaze_to_incas_collection_begin_2":
			Dialog.snd = "voice\QUP1\QUP1014";
			characters[GetCharacterIndex("Friedrich Corleis")].location.group = "merchant"; 
			characters[GetCharacterIndex("Friedrich Corleis")].location.locator = "goto1";
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "blaze_to_incas_collection_begin_3";
		break;

		case "blaze_to_incas_collection_begin_3":
			Dialog.snd = "voice\QUP1\QUP1015";
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "blaze_to_incas_collection_begin_4";
		break;

		case "blaze_to_incas_collection_begin_4":
			Dialog.snd = "voice\QUP1\QUP1016";
			Preprocessor_Add("gentleman", XI_ConvertString("gentle" + PChar.sex));
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "blaze_to_incas_collection_begin_exit";
		break;

		case "blaze_to_incas_collection_begin_5":
			Dialog.snd = "voice\QUP1\QUP1017";
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "exit";
			AddDialogExitQuest("quest_pirate_01_exit_from_fort");
		break;

		case "blaze_to_incas_collection_begin_6":
			Dialog.snd = "voice\QUP1\QUP1018";
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "exit";
			AddDialogExitQuest("quest_pirate_01_exit_with_fight");
		break;

		case "blaze_to_incas_collection_begin_exit":
			EndQuestMovie();TrackQuestMovie("end","quest_pirate_01_dialog.c -> blaze_to_incas_collection_begin_exit");
			pchar.quest.main_line = "blaze_to_incas_collection_begin_2";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("teleport_to_douwesen_exit");
		break;

		case "ines_info_denied_2":
			Dialog.snd = pcharrepphrase("voice\QUP1\QUP1019", "voice\QUP1\QUP1020");
			dialog.text = pcharrepphrase(DLG_TEXT[40], DLG_TEXT[41]);
			link.l1 = pcharrepphrase(DLG_TEXT[42], DLG_TEXT[43]);
			link.l1.go = "ines_info_denied_3";
		break;

		case "ines_info_denied_3":
			Dialog.snd = pcharrepphrase("voice\QUP1\QUP1021", "voice\QUP1\QUP1022");
			dialog.text = pcharrepphrase(DLG_TEXT[44], DLG_TEXT[45]);
			link.l1 = pcharrepphrase(DLG_TEXT[46], DLG_TEXT[47]);
			link.l1.go = "ines_info_denied_4";
		break;

		case "ines_info_denied_4":
			Dialog.snd = pcharrepphrase("voice\QUP1\QUP1023", "voice\QUP1\QUP1024");
			dialog.text = pcharrepphrase(DLG_TEXT[48], DLG_TEXT[49]);
			if (makeint(pchar.money) >= 1500)
			{
				link.l1 = pcharrepphrase(DLG_TEXT[50], DLG_TEXT[51]);
				link.l1.go = "ines_info_denied_6";
			}
			link.l2 = DLG_TEXT[52];
			link.l2.go = "ines_info_denied_7";
			link.l3 = pcharrepphrase(DLG_TEXT[53], DLG_TEXT[54]);
			link.l3.go = "ines_info_denied_5";
		break;

		case "ines_info_denied_5":
			Dialog.snd = pcharrepphrase("voice\QUP1\QUP1025", "voice\QUP1\QUP1026");
			dialog.text = pcharrepphrase(DLG_TEXT[55], DLG_TEXT[56]);
			if (makeint(pchar.money) >= 1500)
			{
				link.l1 = pcharrepphrase(DLG_TEXT[57], DLG_TEXT[58]);
				link.l1.go = "ines_info_denied_6";
			}
			link.l2 = pcharrepphrase(DLG_TEXT[59], DLG_TEXT[60]);
			link.l2.go = "ines_info_denied_exit_2";
			link.l3 = DLG_TEXT[61];
			link.l3.go = "ines_info_denied_7";
		break;

		case "ines_info_denied_6":
			Dialog.snd = "voice\QUP1\QUP1027";
			dialog.text = DLG_TEXT[62];
			link.l1 = pcharrepphrase(DLG_TEXT[63], DLG_TEXT[64]);
			link.l1.go = "exit";
			AddDialogExitQuest("quest_pirate_ines_info_denied_6");
		break;

		case "ines_info_denied_7":
			Dialog.snd = "voice\QUP1\QUP1028";
			dialog.text = DLG_TEXT[65];
			link.l1 = DLG_TEXT[66];
			link.l1.go = "ines_info_denied_8";
		break;

		case "ines_info_denied_8":
			if (makeint(pchar.reputation) < 30)
			{
				Dialog.snd = "voice\QUP1\QUP1029";
				dialog.text = DLG_TEXT[67];
				link.l1 = DLG_TEXT[68];
				link.l1.go = "ines_info_denied_bad_good";
			}
			else
			{
				Dialog.snd = "voice\QUP1\QUP1030";
				dialog.text = DLG_TEXT[69];
				link.l1 = DLG_TEXT[70];
				link.l1.go = "ines_info_denied_bad_bad";
			}
		break;

		case "ines_info_denied_bad_good":
			Dialog.snd = "voice\QUP1\QUP1031";
			dialog.text = DLG_TEXT[71];
			link.l1 = DLG_TEXT[72] + characters[GetCharacterIndex(DLG_TEXT[73])].lastname;
			link.l1.go = "ines_info_denied_6";
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(pchar, 356);
		break;

		case "ines_info_denied_bad_bad":
			if (CalcCharacterSkill(pchar, SKILL_LEADERSHIP) > 3)
			{
				Dialog.snd = "voice\QUP1\QUP1032";
				dialog.text = DLG_TEXT[74];
				link.l1 = DLG_TEXT[75];
				link.l1.go = "ines_info_denied_6";
			}
			else
			{
				Dialog.snd = "voice\QUP1\QUP1033";
				dialog.text = DLG_TEXT[76];
				link.l1 = DLG_TEXT[77];
				link.l1.go = "exit";
				AddDialogExitQuest("fight_with_quest_pirate_after_ines_denied");
			}
		break;

		case "ines_info_denied_exit_2":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddQuestRecord("Blaze_search_Rheims", 5);
			pchar.quest.main_line = "blaze_talk_with_innes_diaz_complete_21";
			locations[FindLocation("QC_town")].reload.l3.disable = 0;
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		
		case "mines":
			dialog.text = DLG_TEXT[78];
			link.l1 = DLG_TEXT[79];
			link.l1.go = "exit";
		break;
	}
}
