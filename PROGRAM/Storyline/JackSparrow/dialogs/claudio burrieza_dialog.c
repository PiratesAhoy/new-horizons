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

	ref PChar = GetMainCharacter();

	switch(Dialog.CurrentNode)
	{
		//-----------------------------------Диалог первый - первая встреча
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\CLBU\CLBU001";
			Dialog.Text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1];
			Link.l1 = pcharrepphrase(DLG_TEXT[2] + GetMyFullName(PChar) + DLG_TEXT[3], DLG_TEXT[4] + GetMyFullName(PChar) + DLG_TEXT[5]);
			Link.l1.go = "node_1"; 
			NextDiag.TempNode = "second time";
		break;

		case "second time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";

			dialog.snd1 = "Voice\CLBU\CLBU002";
			dialog.snd2 = "Voice\CLBU\CLBU003";
			dialog.snd3 = "Voice\CLBU\CLBU004";
			dialog.text = randphrase(DLG_TEXT[6], DLG_TEXT[7] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[8], DLG_TEXT[9], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			link.l1 = pcharrepphrase(DLG_TEXT[10], DLG_TEXT[11]);
			link.l1.go = "node_1";
			link.l2 = pcharrepphrase(DLG_TEXT[12], DLG_TEXT[13]);
			link.l2.go = "exit";
		break;

		case "node_1":
			if (npchar.quest.meeting == "0")
			{
				dialog.snd = "Voice\CLBU\CLBU005";
				dialog.text = DLG_TEXT[14] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[15] + GetMyFullName(NPChar) + DLG_TEXT[16];
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.snd = "Voice\CLBU\CLBU006";
				dialog.text = DLG_TEXT[17] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[18];
			}
			link.l1 = pcharrepphrase(DLG_TEXT[19], DLG_TEXT[20]);
			link.l1.go = "crew";
			link.l2 = DLG_TEXT[21];
			link.l2.go = "quests";
			link.l3 = pcharrepphrase(DLG_TEXT[22], DLG_TEXT[23]);
			link.l3.go = "room";
			if (checkquestattribute("Jacks_early_days", "Second_time_Petros"))
			{
				link.l4 = DLG_TEXT[114];
				link.l4.go = "Dialog_for_CCC_quest";
			}
			link.l99 = pcharrepphrase(DLG_TEXT[24], DLG_TEXT[25]);
			link.l99.go = "exit";
		break;

		case "Dialog_for_CCC_quest":
			dialog.text = DLG_TEXT[115];
			link.l1 = DLG_TEXT[116];
			link.l1.go = "exit";
			pchar.quest.Jacks_early_days = "Continue_for_CCC";
		break;

		case "quests":
			iTest = 0;
			dialog.snd = "Voice\CLBU\CLBU007";
			dialog.text = DLG_TEXT[26];
			if (pchar.quest.main_line == "after_speak_with_leborio" && iTest < QUEST_COUNTER)
			{
				link.l1 = DLG_TEXT[27];
				link.l1.go = "pismena";
				iTest = iTest + 1;
			}
			if (pchar.quest.main_line == "to_isla_muelle" && iTest < QUEST_COUNTER)
			{
				link.l1 = DLG_TEXT[28];
				link.l1.go = "pismena";
				iTest = iTest + 1;
			}
			// TIH --> quest progression helper usage Nov1'06
			// This attr is set in the Leborio Drago_dialog.c file when you have completed
			// the needed steps with Leborio. Thus allowing you to talk to this tavern guy
			// at any time after to continue the hunt for danielle.
			if (CheckQuestAttribute("pismena","begin"))
			{
				link.l1 = DLG_TEXT[28];
				link.l1.go = "pismena";
			}
			// TIH <--
			if (pchar.quest.main_line ==  "blaze_talk_with_innes_diaz_complete_21" && iTest < QUEST_COUNTER)
			{
				link.l2 = DLG_TEXT[29] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[30])]) + DLG_TEXT[32];
				link.l2.go = "search_rheims";
				iTest = iTest + 1;
			}
			if (CheckQuestAttribute("Story_DominguesCompromat","Find") || CheckQuestAttribute("Story_DominguesCompromat","sailAway") )
			{
				link.l2 = pcharrepphrase(DLG_TEXT[33]+GetCharacterFullName(DLG_TEXT[34])+DLG_TEXT[35], DLG_TEXT[36]+GetCharacterFullName(DLG_TEXT[37])+DLG_TEXT[38]);
				link.l2.go = "Danielle_find_FerroCerezo_1";
			}
			if (CheckQuestAttribute("ANIMISTS", "to_muelle_for_rumors"))
			{
				link.l3 = DLG_TEXT[39];
				link.l3.go = "to_muelle_for_rumors";
			}
			if (CheckQuestAttribute("nigel_away_for_ship", "begin"))
			{
				link.l4 = DLG_TEXT[40];
				link.l4.go = "nigel_away_for_ship";
			}
			if (!CheckQuestAttribute("generate_convoy_quest_progress", "begin") && npchar.work != lastspeak_date)
			{
				link.l10 = DLG_TEXT[41];
				link.l10.go = "convoy";
			}
			if (CheckQuestAttribute("Jacks_early_days", "Rescue_CCC"))
			{
				link.l5 = DLG_TEXT[114];
				link.l5.go = "Looking_for_CCC";
			}
			link.l99 = DLG_TEXT[42];
			link.l99.go = "node_1";
		break;
		
		case "nigel_away_for_ship":
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "nigel_away_for_ship_2";
		break;
		
		case "nigel_away_for_ship_2":
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "nigel_away_for_ship_3";
		break;
		
		case "nigel_away_for_ship_3":
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "nigel_away_for_ship_4";
		break;
		
		case "nigel_away_for_ship_4":
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "exit";
			pchar.quest.nigel_away_for_ship = "talk_in_muelle";
			AddQuestrecord("nigel", 23);
		break;

		case "to_muelle_for_rumors":
			dialog.snd = "Voice\CLBU\CLBU008";
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "to_muelle_for_rumors_2";
		break;

		case "to_muelle_for_rumors_2":
			dialog.snd = "Voice\CLBU\CLBU009";
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "to_muelle_for_rumors_3";
		break;

		case "to_muelle_for_rumors_3":
			dialog.snd = "Voice\CLBU\CLBU010";
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "to_muelle_for_rumors_4";
		break;

		case "to_muelle_for_rumors_4":
			dialog.snd = "Voice\CLBU\CLBU011";
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "to_muelle_for_rumors_5";
		break;

		case "to_muelle_for_rumors_5":
			dialog.snd = "Voice\CLBU\CLBU012";
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "to_muelle_for_rumors_6";
		break;

		case "to_muelle_for_rumors_6":
			dialog.snd = "Voice\CLBU\CLBU013";
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "to_muelle_for_rumors_7";
		break;

		case "to_muelle_for_rumors_7":
			dialog.snd = "Voice\CLBU\CLBU014";
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "to_muelle_for_rumors_8";
		break;

		case "to_muelle_for_rumors_8":
			dialog.snd = "Voice\CLBU\CLBU015";
			dialog.text = DLG_TEXT[65];
			link.l1 = DLG_TEXT[66];
			link.l1.go = "to_muelle_for_rumors_9";
		break;

		case "to_muelle_for_rumors_9":
			dialog.snd = "Voice\CLBU\CLBU016";
			dialog.text = GetCharacterFullName(DLG_TEXT[67]) + DLG_TEXT[68];
			link.l1 = DLG_TEXT[69];
			link.l1.go = "exit";
			pchar.quest.ANIMISTS = "speak_with_jordano";
			AddDialogExitQuest("speak_with_jordano");
		break;

		case "Looking_for_CCC":
			dialog.snd = "Voice\CLBU\CLBU015";
			dialog.text = DLG_TEXT[115];
			link.l1 = DLG_TEXT[116];
			link.l1.go = "Exit_Looking_for_CCC";
		break;

		case "Exit_Looking_for_CCC":
			pchar.quest.Jacks_early_days = "Now_Find_CCC";		
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		// nikita
		case "Danielle_find_FerroCerezo_1":
			if( CheckQuestAttribute("Story_DominguesCompromat","Find") )
			{
				dialog.snd = "Voice\CLBU\CLBU017";
				dialog.text = DLG_TEXT[70] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[71];
				link.l1 = DLG_TEXT[72];
				link.l1.go = "exit";
			}
			else
			{
				dialog.snd = "Voice\CLBU\CLBU018";
				dialog.text = DLG_TEXT[73] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[74];
				link.l1 = DLG_TEXT[75];
				link.l1.go = "exit";
				AddDialogExitQuest("FerroCerezo_sailaway_recognize");
			}
		break;

		case "search_rheims":
			dialog.snd = "Voice\CLBU\CLBU019";
			dialog.text = characters[GetCharacterIndex(DLG_TEXT[76])].lastname + DLG_TEXT[77];
			link.l1 = DLG_TEXT[78];
			link.l1.go = "node_1";
			AddQuestrecord("Blaze_search_rheims", 15);
		break;

		case "pismena":
			dialog.snd = "Voice\CLBU\CLBU020";
			dialog.text = DLG_TEXT[79];
			link.l1 = DLG_TEXT[80] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[81])]) + DLG_TEXT[83];
			link.l1.go = "pismena_2";
		break;

		case "pismena_2":
			dialog.snd = "Voice\CLBU\CLBU021";
			dialog.text = DLG_TEXT[84];
			link.l1 = DLG_TEXT[85];
			link.l1.go = "exit";
			pchar.quest.pismena = "end"; // TIH close quest progression helper Nov1'06
			pchar.quest.movie_with_fight.win_condition.l1 = "locator";
			pchar.quest.movie_with_fight.win_condition.l1.location = "Muelle_tavern";
			pchar.quest.movie_with_fight.win_condition.l1.locator_group = "reload";
			pchar.quest.movie_with_fight.win_condition.l1.locator = "reload1";
			pchar.quest.movie_with_fight.win_condition = "movie_with_fight_complete";
			AddQuestRecord("search_danielle", 21);
		break;

		case "crew":
			if (makeint(environment.time) > 22.0 || makeint(environment.time) < 10.0)
			{
				dialog.snd = "Voice\CLBU\CLBU022";
				Dialog.text = DLG_TEXT[86];
				link.l1 = DLG_TEXT[87];
				link.l1.go = "room";
				link.l2 = DLG_TEXT[88];
				link.l2.go = "quests";
			}
			else
			{
				Dialog.CurrentNode = NextDiag.TempNode;
				DialogExit();
				LaunchHireCrew();
			}
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "room":
			dialog.snd = "Voice\CLBU\CLBU023";
			dialog.text = DLG_TEXT[89];
			string roomWait = "";
			if (makeint(environment.time) >= 22.0 || makeint(environment.time) < 10.0)
			{
				roomWait = "eveningwait";
				link.l1 = DLG_TEXT[90];
				link.l1.go = "room_day";
			}
			else
			{
				roomWait = "daywait";
				link.l1 = DLG_TEXT[91];
				link.l1.go = "room_night";
			}
			link.l2 = XI_ConvertString("Until tomorrow") + " " + XI_ConvertString(roomWait) + ".";
			link.l2.go = "room_24";
		break;

		case "room_24":
			dialog.snd = "Voice\ANLE\ANLE014";
			Dialog.text = DLG_TEXT[92];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[93];
				link.l1.go = "room_24_wait";
			}
			link.l2 = pcharrepphrase(DLG_TEXT[94], DLG_TEXT[95]);
			link.l2.go = "hall_24_wait";
			link.l3 = DLG_TEXT[96];
			link.l3.go = "second time";
		break;

		case "room_24_wait":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -5);
			AddDialogExitQuest("sleep_in_tavern");
			WaitDate("",0,0,0,24,1);
			RecalculateJumpTable();
		break;

		case "hall_24_wait":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			LAi_Fade("", "");
			WaitDate("",0,0,0,24,1);
			RecalculateJumpTable();
		break;

		case "room_day":
			dialog.snd = "Voice\CLBU\CLBU024";
			Dialog.text = DLG_TEXT[92];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[93];
				link.l1.go = "room_day_wait";
			}
			link.l2 = pcharrepphrase(DLG_TEXT[94], DLG_TEXT[95]);
			link.l2.go = "hall_day_wait";
			link.l3 = DLG_TEXT[96];
			link.l3.go = "second time";
		break;

		case "room_night":
			dialog.snd = "Voice\CLBU\CLBU025";
			Dialog.text = DLG_TEXT[97];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[98];
				link.l1.go = "room_night_wait";
			}
			link.l2 = pcharrepphrase(DLG_TEXT[99], DLG_TEXT[100]);
			link.l2.go = "hall_night_wait";
			link.l3 = DLG_TEXT[101];
			link.l3.go = "second time";
		break;

		case "room_night_wait":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -5);
			AddDialogExitQuest("sleep_in_tavern");
			TavernWaitDate2("wait_night");
		break;

		case "hall_night_wait":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			TavernWaitDate("wait_night");
		break;

		case "room_day_wait":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -5);
			AddDialogExitQuest("sleep_in_tavern");
			TavernWaitDate2("wait_day");
		break;

		case "hall_day_wait":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			TavernWaitDate("wait_day");
		break;

		case "tavern_keeper":
			NextDiag.TempNode = "second time";
			
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\CLBU\CLBU026";
			dialog.text = DLG_TEXT[102];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "exit_sit";
		break;

		case "exit_sit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			AddDialogExitQuest("exit_sit");
		break;
		
		case "convoy":
			npchar.work = lastspeak_date;
			if (GetCompanionIndex(pchar,1) != -1 && GetCompanionIndex(pchar,2) != -1 && GetCompanionIndex(pchar,3) != -1)
			{
				dialog.text = DLG_TEXT[104];
				link.l1 = DLG_TEXT[105];
				link.l1.go = "exit";
			}
			else
			{
				if (GetNationRelation2MainCharacter(GetCurrentLocationNation()) == RELATION_ENEMY) // KK
				{
					dialog.text = DLG_TEXT[106];
					link.l1 = DLG_TEXT[107];
					link.l1.go = "exit";
				}
				else
				{
					if (makeint(pchar.reputation) <25)
					{
						dialog.text = DLG_TEXT[108];
						link.l1 = DLG_TEXT[109];
						link.l1.go = "exit";
					}
					else
					{
						int randomGod = rand(1);
						if (randomGod == 1)
						{
							dialog.text = DLG_TEXT[110];
							link.l1 = DLG_TEXT[111];
							link.l1.go = "exit";
							AddDialogExitQuest("prepare_for_convoy_quest");
							
						}
						else
						{
							dialog.text = DLG_TEXT[112];
							link.l1 = DLG_TEXT[113];
							link.l1.go = "exit";
						}
					}
				}
			}
		break;
	}
}
