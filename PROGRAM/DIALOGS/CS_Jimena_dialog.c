//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode; //"First time";
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
			Dialog.snd = "dialogs\0\009";

			if(GetAttribute(NPChar, "betrayed") == "true")
			{
				dialog.text = DLG_TEXT[38];
				link.l1 = DLG_TEXT[39];
			}
			else
			{
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
			}
			link.l1.go = "Exit";
		break;

		case "overheard":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "buy_wine";
		break;

		case "buy_wine":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			AddDialogExitQuest("colombian_silver_after_talk_jimena");
			link.l1.go = "exit";
		break;

		case "talk_privately":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "not_town_or_fort";
		break;

		case "not_town_or_fort":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "help_indians";
		break;

		case "help_indians":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "ask_for_medicine";
		break;

		case "ask_for_medicine":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "how_much_medicine";
		break;

		case "how_much_medicine":
			dialog.text = DLG_TEXT[14];
			if(GetSquadronFreeSpace(PChar, GOOD_TREATMENT) >= 100)
			{
				link.l1 = DLG_TEXT[15];
				link.l1.go = "go_get_medicine";
			}
			else
			{
				link.l1 = DLG_TEXT[24];
				link.l1.go = "not_enough_space";
			}
			if(GetSquadronGoods(PChar, GOOD_TREATMENT) >= 100)
			{
				link.l2 = DLG_TEXT[21];
				link.l2.go = "set_up_deal";
			}
		break;

		case "go_get_medicine":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "go_get_medicine2";
		break;

		case "go_get_medicine2":
			dialog.text = DLG_TEXT[18] + DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			AddDialogExitQuest("colombian_silver_check_return_with_medicine");
			link.l1.go = "exit";
		break;

		case "not_enough_space":
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "make_space";
		break;

		case "make_space":
			dialog.text = DLG_TEXT[27] + DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			AddDialogExitQuest("colombian_silver_check_return_with_medicine");
			link.l1.go = "exit";
		break;

		case "set_up_deal":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			AddDialogExitQuest("colombian_silver_jimena_sets_up_deal");
			link.l1.go = "exit";
		break;

		case "too_busy_to_talk":
			dialog.text = DLG_TEXT[28];
			if(GetSquadronGoods(PChar, GOOD_TREATMENT) >= 100)
			{
				link.l1 = DLG_TEXT[29];
				link.l1.go = "get_a_room";
			}
			link.l2 = DLG_TEXT[30];
			link.l2.go = "exit";
		break;

		case "get_a_room":
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			AddDialogExitQuest("colombian_silver_prepare_jimena_for_room");
			link.l1.go = "exit";
		break;

		case "you_have_medicine":
			dialog.text = DLG_TEXT[33];
			if(GetSquadronGoods(PChar, GOOD_TREATMENT) >= 100)
			{
				link.l1 = DLG_TEXT[34];
				link.l1.go = "set_up_deal";
			}
			else
			{
				link.l1 = DLG_TEXT[35];
				link.l1.go = "betrayed";
			}
		break;

		case "betrayed":
			NPChar.quest.betrayed = "true";
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "exit";
		break;
	}
}