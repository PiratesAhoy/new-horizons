
void ProcessDialogEvent()
{
	ref NPChar;

	DeleteAttribute(&Dialog,"Links");
	aref Link, NextDiag;
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	int iTest;

	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;

	ref PChar;
	PChar = GetMainCharacter();

	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "First time":
			Dialog.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			
			if (CheckQuestAttribute("smuggler_line", "smuggler_line_first_mission_meet_soldiers"))
			{
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "exit";
				AddDialogExitQuest("smuggler_line_first_mission_jean_first_talk_with_soldiers");
			}
			if (CheckQuestAttribute("smuggler_line", "second_mission_money_prepare_for_troubles"))
			{
				dialog.text = DLG_TEXT[4];
				link.l1 = DLG_TEXT[5];
				link.l1.go = "second_mission_money_prepare_for_troubles";
			}
			if (CheckQuestAttribute("smuggler_line", "second_mission_to_tavern_room_wait_for_killers"))
			{
				dialog.text = DLG_TEXT[6] + GetMyFullName(PChar) + "?";
				link.l1 = DLG_TEXT[7];
				link.l1.go = "second_mission_to_tavern_room_wait_for_killers";
			}
			NextDiag.TempNode = "First time";
		break;

		case "first_mission_arrest_jean":
			dialog.text = "";
			link.l1 = DLG_TEXT[25];
			AddDialogExitQuest("smuggler_line_first_mission_soldiers_arrest_jean");
			link.l1.go = "exit";
		break;

		case "second_mission_money_prepare_for_troubles":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "second_mission_money_prepare_for_troubles_search";
			link.l2 = DLG_TEXT[10];
			link.l2.go = "second_mission_money_prepare_for_troubles_not_search";
		break;

		case "second_mission_money_prepare_for_troubles_search":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "second_mission_money_prepare_for_troubles_search_2";
		break;

		case "second_mission_money_prepare_for_troubles_search_2":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "second_mission_money_prepare_for_troubles_search_3";
			link.l2 = DLG_TEXT[15];
			link.l2.go = "second_mission_money_prepare_for_troubles_not_search";
		break;

		case "second_mission_money_prepare_for_troubles_search_3":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "second_mission_money_prepare_for_troubles_search_4";
			link.l2 = DLG_TEXT[18];
			link.l2.go = "second_mission_money_prepare_for_troubles_not_search";
		break;

		case "second_mission_money_prepare_for_troubles_search_4":
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "exit";
			AddDialogExitQuest("second_mission_money_to_france_governor");
		break;

		case "second_mission_money_prepare_for_troubles_not_search":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "exit";
			AddDialogExitQuest("second_mission_money_troubles_fight");
		break;

		case "second_mission_to_tavern_room_wait_for_killers":
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "exit";
			AddDialogExitQuest("second_mission_fight_with_killers");
		break;

		case "fourth_mission":
			Dialog.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			if (CheckQuestAttribute("smuggler_line", "fourth_mission_ring"))
			{
				link.l1 = DLG_TEXT[26];
				link.l1.go = "fourth_mission_ring";
			}
			if (CheckQuestAttribute("smuggler_line", "fourth_mission_with_officer_to_shop_wrong"))
			{
				dialog.text = DLG_TEXT[27];
				link.l1 = "...";
				AddDialogExitQuest("fourth_mission_jean_to_soldier1");
				link.l1.go = "exit";
			}
			if (CheckQuestAttribute("smuggler_line", "fourth_mission_with_officer_to_shop_right"))
			{
				dialog.text = DLG_TEXT[28];
				link.l1 = "...";
				AddDialogExitQuest("fourth_mission_jean_to_soldier1");
				link.l1.go = "exit";
			}
		break;

		case "fourth_mission_ring":
			if (GetNationRelation2MainCharacter(FRANCE) == RELATION_ENEMY)
			{
				dialog.text = DLG_TEXT[29];
				link.l1 = DLG_TEXT[30];
				link.l1.go = "exit";
				AddDialogExitQuest("fourth_mission_ring_france_was_enemy");
			}
			else
			{
				dialog.text = DLG_TEXT[31];
				link.l1 = DLG_TEXT[32];
				link.l1.go = "fourth_mission_ring_2";
			}
		break;

		case "fourth_mission_ring_2":
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "fourth_mission_ring_3";
		break;

		case "fourth_mission_ring_3":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "fourth_mission_ring_4";
			link.l2 = DLG_TEXT[37];
			link.l2.go = "fourth_mission_ring_6";
		break;

		case "fourth_mission_ring_4":
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "fourth_mission_ring_5";
		break;

		case "fourth_mission_ring_5":
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "exit";
			AddDialogExitQuest("fourth_mission_with_officer_to_shop_wrong");
		break;

		case "fourth_mission_ring_6":
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "fourth_mission_ring_7";
		break;

		case "fourth_mission_ring_7":
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "exit";
			AddDialogExitQuest("fourth_mission_with_officer_to_shop_right");
		break;

		case "fourth_mission_with_officer_to_shop_wrong":
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "fourth_mission_with_officer_to_shop_wrong_2";
		break;

		case "fourth_mission_with_officer_to_shop_wrong_2":
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "fourth_mission_with_officer_to_shop_wrong_3";
		break;

		case "fourth_mission_with_officer_to_shop_wrong_3":
			If (PChar.sex == "woman") Preprocessor_Add("noble", XI_ConvertString("gentlewoman"));
			else Preprocessor_Add("noble", XI_ConvertString("gentleman"));
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "fourth_mission_with_officer_to_shop_wrong_4";
		break;

		case "fourth_mission_with_officer_to_shop_wrong_4":
			Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false));
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "exit";
			AddDialogExitQuest("fourth_mission_after_shop_wrong");
		break;

		case "fourth_mission_with_officer_to_shop_right":
			dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];
			link.l1.go = "fourth_mission_with_officer_to_shop_right_2";
		break;

		case "fourth_mission_with_officer_to_shop_right_2":
			dialog.text = DLG_TEXT[56];
			link.l1  = DLG_TEXT[57];
			link.l1.go = "fourth_mission_with_officer_to_shop_right_3";
		break;

		case "fourth_mission_with_officer_to_shop_right_3":
			dialog.text = DLG_TEXT[58];
			link.l1 = DLG_TEXT[59];
			link.l1.go = "exit";
			AddDialogExitQuest("fourth_mission_officer_exit_from_shop");
		break;

		case "Exit":
			Nextdiag.CurrentNode = Nextdiag.TempNode;
			DialogExit();
		break;
	}
}
