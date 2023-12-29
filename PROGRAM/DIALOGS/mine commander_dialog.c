//#include "DIALOGS\mine commander_dialog.h"
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
			Dialog.snd = "voice\MICO\MICO001";
			
			dialog.text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1];
			link.l1 = DLG_TEXT[2];
			link.l1.go = "exit";

			if (pchar.quest.main_line == "ask_for_resque_leborio" || pchar.quest.main_line == "after_speak_with_leborio")
			{
				link.l1 = DLG_TEXT[3];
				link.l1.go = "resque_leborio";
			}
			if (pchar.quest.main_line == "resque_leborio_denied")
			{
				link.l1 = DLG_TEXT[4] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[5])]) + DLG_TEXT[7];
				link.l1.go = "resque_leborio_4";
			}
			if (pchar.quest.main_line == "soldier_to_mine_commander_resque")
			{
				Dialog.snd = "voice\MICO\MICO002";
				dialog.text = DLG_TEXT[8];
				link.l1 = DLG_TEXT[9];
				link.l1.go = "soldier_to_mine_commander_resque_2";
			}
			if (pchar.quest.main_line == "kick_on_mine_not_exist")
			{
				Dialog.snd = "voice\MICO\MICO003";
				dialog.text = DLG_TEXT[10];
				link.l1 = pcharrepphrase(DLG_TEXT[11], DLG_TEXT[12]);
				link.l1.go = "kick_on_mine_not_exist_2";
			}
			
			NextDiag.TempNode = "first time";
		break;

		case "kick_on_mine_not_exist_2":
			Dialog.snd = "voice\MICO\MICO004";
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "soldier_to_mine_commander_resque_8";
		break;

		case "soldier_to_mine_commander_resque_2":
			Dialog.snd = "voice\MICO\MICO005";
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16] + GetMyFullName(PChar) + DLG_TEXT[17];
			link.l1.go = "soldier_to_mine_commander_resque_3";
		break;

		case "soldier_to_mine_commander_resque_3":
			Dialog.snd = "voice\MICO\MICO006";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "soldier_to_mine_commander_resque_4";
		break;

		case "soldier_to_mine_commander_resque_4":
			Dialog.snd = "voice\MICO\MICO007";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "soldier_to_mine_commander_resque_5";
		break;

		case "soldier_to_mine_commander_resque_5":
			Dialog.snd = "voice\MICO\MICO008";
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "soldier_to_mine_commander_resque_6";
		break;

		case "soldier_to_mine_commander_resque_6":
			Dialog.snd = "voice\MICO\MICO009";
			dialog.text = DLG_TEXT[24];
			if (makeint(pchar.tempmoney) >= 1000)
			{
				link.l1 = DLG_TEXT[25];
				link.l1.go = "soldier_to_mine_commander_resque_7";
			}
			link.l2 = DLG_TEXT[26];
			link.l2.go = "resque_denied";
		break;

		case "soldier_to_mine_commander_resque_7":
			Dialog.snd = "voice\MICO\MICO010";
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "soldier_to_mine_commander_resque_8";
		break;

		case "soldier_to_mine_commander_resque_8":
			Dialog.snd = "voice\MICO\MICO011";
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "soldier_to_mine_commander_resque_9";
		break;

		case "soldier_to_mine_commander_resque_9":
			Dialog.snd = "voice\MICO\MICO012";
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32] + characters[GetCharacterIndex(DLG_TEXT[33])].lastname + DLG_TEXT[34];
			link.l1.go = "soldier_to_mine_commander_resque_10";
		break;

		case "soldier_to_mine_commander_resque_10":
			Dialog.snd = "voice\MICO\MICO013";
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "soldier_to_mine_commander_resque_11";
		break;

		case "soldier_to_mine_commander_resque_11":
			Dialog.snd = "voice\MICO\MICO014";
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "exit";
			if (npchar.location == "Oxbay_mine") 
			{
				AddDialogExitQuest("mine_commander_resque_exit");
			}
			else
			{
				pchar.quest.main_line = "talk_with_Liborio_2";
			}			
			AddQuestRecord("search_danielle", 13);
		break;

		case "resque_denied":
			Dialog.snd = "voice\MICO\MICO015";
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "exit";
			AddDialogExitQuest("mine_commander_resque_denied_exit");
		break;

		case "resque_leborio":
			Dialog.snd = "voice\MICO\MICO016";
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[43])]) + DLG_TEXT[45];
			link.l1.go = "resque_leborio_2";
		break;

		case "resque_leborio_2":
			Dialog.snd = "voice\MICO\MICO017";
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "resque_leborio_3";
		break;

		case "resque_leborio_3":
			Dialog.snd = "voice\MICO\MICO018";
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "resque_leborio_4";
		break;

		case "resque_leborio_4":
			Dialog.snd = "voice\MICO\MICO019";
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "resque_leborio_5";
		break;

		case "resque_leborio_5":
			Dialog.snd = "voice\MICO\MICO020";
			dialog.text = DLG_TEXT[52];
			if (pchar.money >=1000)
			{
				link.l1 = DLG_TEXT[53];
				link.l1.go = "resque_leborio_6";
			}
			link.l2 = DLG_TEXT[54];
			link.l2.go = "exit_2";
		break;
		
		case "resque_leborio_6":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(pchar, -1000);
			AddQuestRecord("search_danielle", 19);
			if (pchar.quest.main_line == "ask_for_resque_leborio")
			{
				pchar.quest.main_line = "resque_leborio";
			}
			else
			{
				pchar.quest.main_line = "resque_leborio_bad";
			}
		break;

		case "Exit_2":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			pchar.quest.main_line = "resque_leborio_denied";
			AddQuestRecord("search_danielle", 20);
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
