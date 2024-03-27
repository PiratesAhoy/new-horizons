

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
	string sNation;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;

	ref PChar;
	PChar = GetMainCharacter();

	Preprocessor_Add("Beltrop", GetMyLastName(CharacterFromID("Desmond Ray Beltrop")));

	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "First time":
			if (npchar.quest.meeting == "0")
			{
				Dialog.Text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1] + GetMyFullName(NPChar) + DLG_TEXT[2];
				Link.l1 = DLG_TEXT[3] + GetMyFullName(PChar) + DLG_TEXT[4];
				link.l1.go = "node_1";
			}
			NextDiag.TempNode = "Second time";
		break;

		case "second time":
			dialog.text = pcharrepphrase(DLG_TEXT[5] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[6], DLG_TEXT[7]);
			Link.l1 = pcharrepphrase(DLG_TEXT[8] + GetMyName(NPChar) + DLG_TEXT[9], DLG_TEXT[10]); 
			link.l1.go = "node_1";
			NextDiag.TempNode = "Second time";
		break;

		case "node_1":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "market";
			link.l2 = DLG_TEXT[13];
			link.l2.go = "quests";
			link.l3 = DLG_TEXT[14];
			link.l3.go = "exit";
		break;

		case "market":
			dialog.Text = DLG_TEXT[15];
			Link.l1 = DLG_TEXT[16];
			Link.l1.go = "trade_1";
			Link.l2 = DLG_TEXT[17];
			Link.l2.go = "items";
			Link.l3 = DLG_TEXT[18];
			Link.l3.go = "exit";
		break;

		case "trade_1":
			Nextdiag.CurrentNode = Nextdiag.TempNode;
			//NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			LaunchStore(FALAISE_DE_FLEUR_STORE);
		break;

		case "items":
			if (npchar.quest.item_date != lastspeak_date)
			{
				GiveItemToTrader(npchar);
				npchar.quest.item_date = lastspeak_date;
			}
			Nextdiag.CurrentNode = Nextdiag.TempNode;
			DialogExit();
			LaunchItemsTrade(NPChar);
		break;

		case "quests":
			iTest = 0;
			Dialog.text = DLG_TEXT[19];
			if (CheckAttribute(pchar, "quest.iQuantityGoods"))
			{
				int iQuantityShipGoods = pchar.quest.iQuantityGoods;
				int iQuestTradeGoods = pchar.quest.iTradeGoods;
			}
			if (CheckQuestAttribute("generate_trade_quest_progress", "begin") || CheckQuestAttribute("generate_trade_quest_progress",  "failed"))
			{
				if (CheckQuestAttribute("iTradeNation", npchar.nation) &&  GetSquadronGoods(pchar, iQuestTradeGoods) >= iQuantityShipGoods)
				{
					dialog.text = DLG_TEXT[20];
					link.l1 = DLG_TEXT[21];
					link.l1.go = "generate_quest_2";
				}
			}
			else
			{
				if (!CheckQuestAttribute("generate_trade_quest_progress", "begin"))
				{
					link.l1 = DLG_TEXT[22];
					link.l1.go = "generate_quest";
				}
			}
			if (CheckQuestAttribute("smuggler_line", "smuggler_line_first_mission_accept") && GetSquadronGoods(PChar, GOOD_SANDAL) > 0)
			{
				link.l2 = DLG_TEXT[23] + GetMyFullName(CharacterFromID("Desmond Ray Beltrop")) + ".";
				link.l2.go = "smuggler_line_first_mission";
			}
			if (CheckQuestAttribute("smuggler_line", "smuggler_line_first_mission_get_more_sandal") && GetSquadronGoods(PChar, GOOD_SANDAL) >= 300)
			{
				dialog.text = DLG_TEXT[151] + GetMyName(PChar) + DLG_TEXT[152];
				link.l1 = DLG_TEXT[153];
				AddDialogExitQuest("smuggler_line_first_mission_wait_night");
				link.l1.go = "exit";
			}
			if (CheckQuestAttribute("smuggler_line", "second_mission_accept"))
			{
				if  (checkquestattribute("smuggler_line.first_mission", "completed"))
				{
					dialog.text = DLG_TEXT[24];
					link.l1 = DLG_TEXT[25];
					link.l1.go = "second_mission";
				}
				else
				{
					link.l1 = DLG_TEXT[26];
					link.l1.go = "second_mission";
				}
			}
			if (CheckQuestAttribute("smuggler_line", "second_mission_after_fight_with_killers"))
			{
				dialog.text = DLG_TEXT[27];
				link.l1 = DLG_TEXT[28];
				link.l1.go = "second_mission_after_fight_with_killers";
			}
			if (CheckQuestAttribute("smuggler_line", "fourth_mission_to_jean"))
			{
				if (CheckQuestAttribute("smuggler_line.second_mission", "completed"))
				{
					dialog.text = DLG_TEXT[29];
					link.l1 = DLG_TEXT[30];
					link.l1.go = "fourth_mission_to_jean";
				}
				else
				{
					dialog.text = DLG_TEXT[31];
					link.l1 = DLG_TEXT[32];
					link.l1.go = "fourth_mission_to_jean";
				}
			}
			if (CheckQuestAttribute("smuggler_line", "fourth_mission_capture_susanne"))
			{
				dialog.text = DLG_TEXT[33];
				link.l1 = DLG_TEXT[34];
				link.l1.go = "fourth_mission_capture_susanne";
			}
			if (CheckQuestAttribute("smuggler_line", "fourth_mission_officer_exit_from_shop"))
			{
				dialog.text = DLG_TEXT[35];
				link.l1 = DLG_TEXT[36];
				link.l1.go = "fourth_mission_officer_exit_from_shop";
			}
			link.l99 = DLG_TEXT[37];
			Link.l99.go = "no_quests";
		break;

		case "generate_quest":
			if (npchar.quest.trade_date != lastspeak_date)
			{
				npchar.quest.trade_date = lastspeak_date;
				//проверка враждебности нам страны торговца
				if (GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY)
				{
					Preprocessor_Add("nation_desc", XI_ConvertString(GetNationDescByType(sti(NPChar.nation))));
					dialog.text = DLG_TEXT[38];
					link.l1 = DLG_TEXT[39];
					link.l1.go = "exit";
				}
				else
				{
					int iTradeNation = GenerateNationTrade(sti(NPChar.nation));
					if (iTradeNation < 0)
					{
						dialog.text = DLG_TEXT[40];
						link.l1 = DLG_TEXT[41];
						link.l1.go = "exit";
					}
					else
					{
						float fprice, tprice;
						// NK redo this to take price into account 05-05-12 -->
						int iTradeGoods = GenerateGoodForTrade(sti(NPChar.nation), iTradeNation, &fprice, &tprice);
						sNation = GenerateTradeQuest(pchar, iTradeNation, iTradeGoods, fprice, tprice, true);
						if (GetSquadronFreeSpace(pchar, iTradeGoods) < 100 || sNation=="")
						{
							dialog.text = DLG_TEXT[42];
							link.l1 = DLG_TEXT[43];
							link.l1.go = "exit";
						}
						else
						{
							dialog.text = DLG_TEXT[44] + sNation + DLG_TEXT[45] + pchar.quest.generate_trade_quest_progress.iMoney + DLG_TEXT[46];
							link.l1 = DLG_TEXT[47];
							link.l1.go = "exit_trade";
							link.l2  = DLG_TEXT[48];
							link.l2.go = "exit";
						}
					}
				}
			}
			else
			{
				dialog.text = DLG_TEXT[49];
				link.l1 = DLG_TEXT[50];
				link.l1.go = "exit";
			}
		break;
		
		case "exit_trade":
			AddDialogExitQuest("trade_quest_open");
			Nextdiag.CurrentNode = Nextdiag.TempNode;
			DialogExit();
		break;

		case "generate_quest_2":
			if (pchar.quest.generate_trade_quest_progress == "failed")
			{
				dialog.text = DLG_TEXT[51];
				link.l1 = DLG_TEXT[52];
				link.l1.go = "exit";
				ChangeCharacterReputation(pchar, -1);
			}
			else
			{
				dialog.text = DLG_TEXT[53] + GetMyAddressForm(NPchar, PChar, ADDR_GENDER, false, false) + ".";
				link.l1 = DLG_TEXT[54];
				link.l1.go = "exit";
				ChangeCharacterReputation(pchar, 1);
				TradeQuestDone();
			}
			AddDialogExitQuest("close_trade_quest");
		break;
		
		case "no_quests":
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "node_1";
		break;

		case "smuggler_line_first_mission":
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "smuggler_line_first_mission_2";
		break;

		case "smuggler_line_first_mission_short_cargo":
			dialog.text = GetMyFullName(CharacterFromID("Desmond Ray Beltrop")) + DLG_TEXT[148] + GetSquadronGoods(PChar, GOOD_SANDAL) + DLG_TEXT[149];
			link.l1 = DLG_TEXT[150];
			AddQuestRecord("smuggler_line", 65);
			link.l1.go = "exit";
		break;

		case "smuggler_line_first_mission_2":
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "exit";
			if (GetSquadronGoods(pchar, GOOD_SANDAL) >= 300) AddDialogExitQuest("smuggler_line_first_mission_wait_night");
			else AddDialogExitQuest("smuggler_line_first_mission_wait_night_short_cargo");
		break;	

		case "smuggler_line_first_mission_before_soldiers":
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "exit";
			
			AddDialogExitQuest("smuggler_line_first_mission_soldiers");
			NextDiag.TempNode = "Second time";
		break;	

		case "smuggler_line_first_mission_jean_first_talk_with_soldiers":
			dialog.text = DLG_TEXT[63];
			link.l1 = "...";
			link.l1.go = "exit";
			
			AddDialogExitQuest("smuggler_line_first_mission_jean_first_talk_with_soldiers2");
			NextDiag.TempNode = "Second time";
		break;

		case "second_mission":
			dialog.text = DLG_TEXT[65];
			link.l1 = DLG_TEXT[66];
			link.l1.go = "second_mission_2";
		break;

		case "second_mission_2":
			dialog.text = DLG_TEXT[67];
			link.l1 = DLG_TEXT[68];
			link.l1.go = "second_mission_3";
		break;

		case "second_mission_3":
			Preprocessor_Add("DesmondRay", GetMySimpleName(CharacterFromID("Desmond Ray Beltrop")));
			dialog.text = DLG_TEXT[69];
			link.l1 = DLG_TEXT[70];
			link.l1.go = "second_mission_4";
		break;

		case "second_mission_4":
			dialog.text = DLG_TEXT[71];
			link.l1 = DLG_TEXT[72];
			link.l1.go = "second_mission_money";
			link.l2 = DLG_TEXT[73];
			link.l2.go = "second_mission_delay";
			link.l3 = DLG_TEXT[74];
			link.l3.go = "second_mission_truth";
		break;

		case "second_mission_money": //дает деньги, но на нас нападают солдаты.
			dialog.text = DLG_TEXT[75];
			link.l1 = DLG_TEXT[76];
			link.l1.go = "second_mission_money_2";
		break;

		case "second_mission_money_2":
			dialog.text = DLG_TEXT[77];
			link.l1 = DLG_TEXT[78];
			link.l1.go = "second_mission_money_3";
		break;

		case "second_mission_money_3":
			dialog.text = DLG_TEXT[79];
			link.l1 = DLG_TEXT[80];
			link.l1.go = "exit";
			AddDialogExitQuest("second_mission_money_prepare_for_troubles");
		break;

		case "second_mission_delay": //берем отсрочку, но по истечении дня на нас нападают
			dialog.text = DLG_TEXT[81];
			link.l1 = DLG_TEXT[82];
			link.l1.go = "exit";
			AddDialogExitQuest("second_mission_wait_two_days");
		break;

		case "second_mission_truth": //возвращаемся к Мачадо, потом узнаем, что солдаты убили человека, которого мачадо послал разбираться с Арно.
			dialog.text = DLG_TEXT[83];
			link.l1 = DLG_TEXT[84];
			link.l1.go = "exit";
			AddDialogExitQuest("second_mission_truth_to_maginot");
		break;

		case "second_mission_after_fight_with_killers_return":
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "second_mission_after_fight_with_killers";
		break;

		case "second_mission_after_fight_with_killers":
			dialog.text = DLG_TEXT[85];
			link.l1 = DLG_TEXT[86];
			link.l1.go = "second_mission_after_fight_with_killers_2";
		break;

		case "second_mission_after_fight_with_killers_2":
			dialog.text = DLG_TEXT[87];
			link.l1 = DLG_TEXT[88];
			link.l1.go = "second_mission_after_fight_with_killers_3";
		break;

		case "second_mission_after_fight_with_killers_3":
			Preprocessor_Add("monsieur", GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false));
			dialog.text = DLG_TEXT[89];
			link.l1 = DLG_TEXT[90];
			link.l1.go = "second_mission_after_fight_with_killers_4";
		break;

		case "second_mission_after_fight_with_killers_4":
			dialog.text = DLG_TEXT[91];
			link.l1 = DLG_TEXT[92];
			link.l1.go = "second_mission_after_fight_with_killers_5";
		break;

		case "second_mission_after_fight_with_killers_5":
			dialog.text = DLG_TEXT[93];
			link.l1 = DLG_TEXT[94];
			link.l1.go = "exit";
			AddDialogExitQuest("second_mission_after_fight_with_killers_take_money");
		break;

		case "fourth_mission_to_jean":
			dialog.text = DLG_TEXT[95];
			link.l1 = DLG_TEXT[96];
			link.l1.go = "fourth_mission_to_jean_2";
		break;

		case "fourth_mission_to_jean_2":
			dialog.text = DLG_TEXT[97];
			link.l1 = DLG_TEXT[98];
			link.l1.go = "fourth_mission_to_jean_3";
			link.l2 = DLG_TEXT[99];
			link.l2.go = "fourth_mission_to_jean_possible_fight";
		break;

		case "fourth_mission_to_jean_3":
			dialog.text = DLG_TEXT[100];
			link.l1 = DLG_TEXT[101];
			link.l1.go = "fourth_mission_to_jean_4";
		break;

		case "fourth_mission_to_jean_4":
			dialog.text = DLG_TEXT[102];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "fourth_mission_fight";
			link.l2 = DLG_TEXT[104];
			link.l2.go = "fourth_mission_to_jean_5";
		break;

		case "fourth_mission_to_jean_5":
			dialog.text = DLG_TEXT[105];
			link.l1 = DLG_TEXT[106];
			link.l1.go = "fourth_mission_ring";
			link.l2 = DLG_TEXT[107];
			link.l2.go = "fourth_mission_to_jean_6";
		break;

		case "fourth_mission_to_jean_6":	
		//	dialog.text = DLG_TEXT[108];
		//	link.l1 = DLG_TEXT[109];			// This is just "But ", including the space - an incomplete sentence?
		//	link.l1.go = "exit";

			AddDialogExitQuest("fourth_mission_return_to_beltrop");
			Nextdiag.CurrentNode = Nextdiag.TempNode;	// Just exit and trigger the next part of the quest
			DialogExit();
		break;

		case "fourth_mission_ring":
			int roll = rand(12);
			int sneakskill = CalcCharacterSkill(PChar, "sneak");
			if (sneakskill >= roll)
			{
				Preprocessor_Add("shopkeeper", GetMyName(NPChar));
				dialog.text = DLG_TEXT[110];
				link.l1 = DLG_TEXT[111];
				link.l1.go = "exit";
				AddDialogExitQuest("fourth_mission_ring");
			}
			else
			{
				dialog.text = DLG_TEXT[112];
				link.l1 = DLG_TEXT[113];
				link.l1.go = "fourth_mission_to_jean_6";
				link.l2 = DLG_TEXT[114];
				link.l2.go = "fourth_mission_fight";
			}
		break;

		case "fourth_mission_to_jean_possible_fight":
			dialog.text = DLG_TEXT[115];
			link.l1 = DLG_TEXT[116];
			link.l1.go = "fourth_mission_fight";
			link.l2 = DLG_TEXT[117];
			link.l2.go = "fourth_mission_to_jean_possible_fight_2";
		break;

		case "fourth_mission_to_jean_possible_fight_2":
			dialog.text = DLG_TEXT[118];
			link.l1 = DLG_TEXT[119];
			link.l1.go = "fourth_mission_fight";
			link.l2 = DLG_TEXT[120];
			link.l2.go = "fourth_mission_to_jean_3";
		break;

		case "fourth_mission_fight":
			int iNation = GetServedNation();
			sNation = "";
			if (iNation != PERSONAL_NATION) sNation = XI_ConvertString(GetNationDescByType(iNation)) + " ";
			Preprocessor_Add("nation", sNation);
			dialog.text = DLG_TEXT[121];
			link.l1 = DLG_TEXT[122];
			link.l1.go = "exit";
			AddDialogExitQuest("fourth_mission_fight");
		break;

		case "fourth_mission_capture_susanne":
			dialog.text = DLG_TEXT[123];
			link.l1 = DLG_TEXT[124];
			link.l1.go = "fourth_mission_capture_susanne_2";
		break;

		case "fourth_mission_capture_susanne_2":
			dialog.text = DLG_TEXT[125];
			link.l1 = DLG_TEXT[126];
			link.l1.go = "fourth_mission_capture_susanne_3";
		break;

		case "fourth_mission_capture_susanne_3":
			dialog.text = DLG_TEXT[127];
			link.l1 = DLG_TEXT[128];
			link.l1.go = "fourth_mission_capture_susanne_4";
		break;

		case "fourth_mission_capture_susanne_4":
			dialog.text = DLG_TEXT[129];
			link.l1 = GetMyLastName(CharacterFromID("Desmond Ray Beltrop")) + DLG_TEXT[130];
			link.l1.go = "fourth_mission_capture_susanne_5";
		break;

		case "fourth_mission_capture_susanne_5":
			dialog.text = DLG_TEXT[131];
			link.l1 = DLG_TEXT[132];
			link.l1.go = "fourth_mission_capture_susanne_6";
		break;

		case "fourth_mission_capture_susanne_6":
			dialog.text = DLG_TEXT[133];
			link.l1 = DLG_TEXT[134];
			link.l1.go = "exit";
			AddDialogExitQuest("fourth_mission_capture_susanne_wait_in_tavern");
		break;

		case "fourth_mission_meet_with_jean_in_tavern_good":
			dialog.text = DLG_TEXT[135];
			link.l1 = DLG_TEXT[136];
			link.l1.go = "exit";
			AddDialogExitQuest("fourth_mission_meet_with_jean_in_tavern_good");
		break;

		case "fourth_mission_meet_with_jean_in_tavern_bad":
			dialog.text = DLG_TEXT[137];
			link.l1 = DLG_TEXT[138];
			link.l1.go = "exit";
			AddDialogExitQuest("fourth_mission_meet_with_jean_in_tavern_bad");
		break;

		case "fourth_mission_officer_exit_from_shop":
			dialog.text = DLG_TEXT[139];
			link.l1 = DLG_TEXT[140];
			link.l1.go = "exit";
			AddDialogExitQuest("fourth_mission_ring_completed");
		break;

		case "resque_susanne":
			dialog.text = DLG_TEXT[141];
			link.l1 = DLG_TEXT[142];
			link.l1.go = "fourth_mission_meet_with_jean_in_tavern_good";
			link.l2 = DLG_TEXT[143];
			link.l2.go = "fourth_mission_meet_with_jean_in_tavern_bad";
		break;

		case "smuggler_line_fourth_mission_jean_first_talk_with_soldiers":
			dialog.text = DLG_TEXT[144];
			link.l1 = "...";
			AddDialogExitQuest("fourth_mission_soldier_to_player");
			link.l1.go = "exit";
		break;

		case "Exit":
			Nextdiag.CurrentNode = Nextdiag.TempNode;
			DialogExit();
		break;
	}
}
