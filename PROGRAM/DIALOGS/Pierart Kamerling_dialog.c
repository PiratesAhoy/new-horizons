void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	int iTest, NPC_Meeting;
	
	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;

	
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
			
			dialog.snd = "Voice\FRCO\FRCO001";
			dialog.text = DLG_TEXT[0] + GetMyFullName(NPChar) + DLG_TEXT[1];
			link.l1 = pcharrepphrase(DLG_TEXT[2] + GetMyFullName(PChar) + DLG_TEXT[3], DLG_TEXT[4] + GetMyFullName(PChar) + DLG_TEXT[5]);
			link.l1.go = "second time";
		
			Diag.TempNode = "second time";
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
			
			Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
			
			dialog.snd = "Voice\FRCO\FRCO002";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "quests";
			link.l2 = pcharrepphrase(DLG_TEXT[8], DLG_TEXT[9]);
			link.l2.go = "crew";
			link.l3 = pcharrepphrase(DLG_TEXT[10], DLG_TEXT[11]);
			link.l3.go = "room";
			link.l99 = DLG_TEXT[12];
			link.l99.go = "exit";
		break;

		case "quests":
			itest = 0;
			dialog.snd = "Voice\FRCO\FRCO003";
			dialog.text = DLG_TEXT[13];
			
			if (pchar.quest.main_line == "blaze_to_incas_collection_begin" || pchar.quest.main_line == "kill_pirate_06")
			{
				if (iTest < QUEST_COUNTER)
				{
					Link.l1 = DLG_TEXT[14];
					Link.l1.go = "blaze_to_incas_collection_begin_2";
				}
			}
			if (pchar.quest.main_line == "after_speak_with_peasant" && iTest < QUEST_COUNTER)
			{
				link.l2 = DLG_TEXT[15] + characters[GetCharacterIndex(DLG_TEXT[16])].ship.name + DLG_TEXT[17];
				link.l2.go = "after_speak_with_peasant_2";
			}
			if (CheckQuestAttribute("ANIMISTS", "to_douwesen_tavern"))  // --> Cat 
			{
				link.l3 = DLG_TEXT[88];
				link.l3.go = "Node_5";
			} // <-- Cat
			if (pchar.quest.main_line ==  "blaze_talk_with_innes_diaz_complete_21" && iTest < QUEST_COUNTER)
			{
				link.l4 = DLG_TEXT[18] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[19])]) + DLG_TEXT[21];
				link.l4.go = "search_rheims";
				iTest = iTest + 1;
			}
			if(CheckQuestAttribute("RheimsBook","3"))//for Mosh d25
			{
				link.l1 = DLG_TEXT[22];
				link.l1.go = "Node_2";
			}
			if(CheckQuestAttribute("RheimsBook","27"))//For MoshD39
			{
				link.l1 = DLG_TEXT[23];
				link.l1.go = "Node_4_1";
			}
			if(CheckQuestAttribute("ReturnMoney","3000"))//moneyBack
			{
			//	dialog.text = "Ах! это снова вы. Я не знал что у вас важные дела к командиру.";
				link.l1 = DLG_TEXT[24];
				link.l1.go = "Node_3";
			}
			if (!CheckQuestAttribute("generate_convoy_quest_progress", "begin") && npchar.work != lastspeak_date)
			{
				link.l10 = DLG_TEXT[25];
				link.l10.go = "convoy";
			}
			link.l99 = DLG_TEXT[26];
			link.l99.go = "second time";
		break;

		case "Node_2":
			dialog.snd = "Voice\FRCO\FRCO004";
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "Node_2_1";			
		break;

		case "Node_2_1":
			dialog.snd = "Voice\FRCO\FRCO005";
			dialog.text = DLG_TEXT[29];
			if(makeint(PChar.money) >= 3000)
			{
				link.l1 = DLG_TEXT[30];
				link.l1.go = "Pay_1";
			}
			link.l2 = DLG_TEXT[31];
			link.l2.go = "NotPay_1";
		break;

		case "Pay_1":
			dialog.snd = "Voice\FRCO\FRCO006";
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "Pay_2";			
		break;

		case "Pay_2":
			dialog.snd = "Voice\FRCO\FRCO007";
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "exitandpay";			
		break;

		case "NotPay_1":
			dialog.snd = "Voice\FRCO\FRCO008";
			dialog.text = DLG_TEXT[36];
			if(makeint(PChar.money) >= 3000)
			{
				link.l1 = DLG_TEXT[37];
				link.l1.go = "Pay_1";
			}
			link.l2 = DLG_TEXT[38];
			link.l2.go = "exitandnotpay";
		break;

		case "Node_3":
			dialog.snd = "Voice\FRCO\FRCO009";
			dialog.text = DLG_TEXT[39] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "exit";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(Pchar,6000);
			Pchar.quest.ReturnMoney = "0";//деньги вернулись!!!
			AddQuestRecord("Story_Find_Rheims", 116);
		break;

		case "Node_4_1":
			dialog.snd = "Voice\FRCO\FRCO010";
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "Exit";
			AddQuestRecord("Story_Find_Rheims", 126);
			Pchar.quest.RheimsBook = "28";
		break;
		
		case "Node_5":  // --> Cat 
			dialog.snd = "Voice\FRCO\FRCO012";
			dialog.text = DLG_TEXT[89];
			link.l1 = DLG_TEXT[90];
			link.l1.go = "exit";
			pchar.quest.ANIMISTS = "to_douwesen_tavern2";
		break;  // <-- Cat 

		case "exitandpay":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(Pchar,-3000);
			Pchar.quest.ReturnMoney = "1";//сохраним, для откупа...
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			AddQuestRecord("Story_Find_Rheims", 114);
			Pchar.quest.RheimsBook = "4";//For Mosh d26
		break;

		case "exitandnotpay":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			AddQuestRecord("Story_Find_Rheims", 115);
			Pchar.quest.RheimsBook = "4";//For Mosh d26
		break;

		case "search_rheims":
			dialog.snd = "Voice\FRCO\FRCO011";
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "second time";
			AddQuestRecord("Blaze_search_rheims", 14);
		break;

		case "after_speak_with_peasant_2":
			dialog.snd = "Voice\FRCO\FRCO012";
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "after_speak_with_peasant_3";
		break;

		case "after_speak_with_peasant_3":
			dialog.snd = "Voice\FRCO\FRCO013";
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "exit";
			ChangeCharacterAddressGroup(CharacterFromID("peasant"), "none", "", ""); // KK
			pchar.quest.main_line = "to_douwesen_pirates";
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			AddQuestrecord("Where_are_i", 2);
			Preprocessor_Remove("Danielle");
		break;

		case "blaze_to_incas_collection_begin_2":
			dialog.snd = "Voice\FRCO\FRCO014";
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[52])]) + DLG_TEXT[54];
			link.l1.go = "blaze_to_incas_collection_begin_3";
		break;

		case "blaze_to_incas_collection_begin_3":
			dialog.snd = "Voice\FRCO\FRCO015";
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "blaze_to_incas_collection_begin_4";
		break;

		case "blaze_to_incas_collection_begin_4":
			dialog.snd = "Voice\FRCO\FRCO016";
			dialog.text = DLG_TEXT[57];
			Preprocessor_Add("gender", GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false)); // DeathDaisy
			link.l1 = pcharrepphrase(DLG_TEXT[58], DLG_TEXT[59]);
			link.l1.go = "blaze_to_incas_collection_begin_exit_1";
		break;

		case "blaze_to_incas_collection_begin_exit_1":			
			DialogExit();
			Diag.CurrentNode =  Diag.TempNode;
			pchar.quest.main_line = "blaze_to_incas_collection_begin_1";
			AddDialogExitQuest("Friedrich_Corleis_go_away");
		break;

		case "crew":
			if (makeint(environment.time) > 22.0 || makeint(environment.time) < 10.0)
			{
				dialog.snd = "Voice\FRCO\FRCO017";
				Dialog.text = DLG_TEXT[60];
				link.l1 = DLG_TEXT[61];
				link.l1.go = "room";
				link.l2 = DLG_TEXT[62];
				link.l2.go = "quests";
			}
			else
			{
				Diag.CurrentNode = Diag.TempNode;
				DialogExit();
				LaunchHireCrew();
			}
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;

		case "room":
			dialog.snd = "Voice\FRCO\FRCO018";
			dialog.text = DLG_TEXT[63];
			string roomWait = "";
			if (makeint(environment.time) >= 22.0 || makeint(environment.time) < 10.0)
			{
				roomWait = "eveningwait";
				link.l1 = DLG_TEXT[64];
				link.l1.go = "room_day";
			}
			else
			{
				roomWait = "daywait";
				link.l1 = DLG_TEXT[65];
				link.l1.go = "room_night";
			}
			link.l2 = XI_ConvertString("Until tomorrow") + " " + XI_ConvertString(roomWait) + ".";
			link.l2.go = "room_24";
		break;

		case "room_24":
			dialog.snd = "Voice\ANLE\ANLE014";
			Dialog.text = DLG_TEXT[66];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[67];
				link.l1.go = "room_24_wait";
			}
			link.l2 = pcharrepphrase(DLG_TEXT[68], DLG_TEXT[69]);
			link.l2.go = "hall_24_wait";
			link.l3 = DLG_TEXT[70];
			link.l3.go = "second time";
		break;

		case "room_24_wait":
			DialogExit();
			Diag.CurrentNode =  Diag.TempNode;
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -5);
			AddDialogExitQuest("sleep_in_tavern");
			WaitDate("",0,0,0,24,1);
			RecalculateJumpTable();
		break;

		case "hall_24_wait":
			DialogExit();
			Diag.CurrentNode =  Diag.TempNode;
			LAi_Fade("", "");
			WaitDate("",0,0,0,24,1);
			RecalculateJumpTable();
		break;

		case "room_day":
			dialog.snd = "Voice\FRCO\FRCO019";
			Dialog.text = DLG_TEXT[66];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[67];
				link.l1.go = "room_day_wait";
			}
			link.l2 = pcharrepphrase(DLG_TEXT[68], DLG_TEXT[69]);
			link.l2.go = "hall_day_wait";
			link.l3 = DLG_TEXT[70];
			link.l3.go = "second time";
		break;

		case "room_night":
			dialog.snd = "Voice\FRCO\FRCO019";
			Dialog.text = DLG_TEXT[71];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[72];
				link.l1.go = "room_night_wait";
			}
			link.l2 = pcharrepphrase(DLG_TEXT[73], DLG_TEXT[74]);
			link.l2.go = "hall_night_wait";
			link.l3 = DLG_TEXT[75];
			link.l3.go = "second time";
		break;

		case "room_night_wait":
			DialogExit();
			Diag.CurrentNode =  Diag.TempNode;
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -5);
			AddDialogExitQuest("sleep_in_tavern");
			TavernWaitDate2("wait_night");
		break;

		case "hall_night_wait":
			DialogExit();
			Diag.CurrentNode =  Diag.TempNode;
			TavernWaitDate("wait_night");
		break;

		case "room_day_wait":
			DialogExit();
			Diag.CurrentNode =  Diag.TempNode;
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -5);
			AddDialogExitQuest("sleep_in_tavern");
			TavernWaitDate2("wait_day");
		break;

		case "hall_day_wait":
			DialogExit();
			Diag.CurrentNode =  Diag.TempNode;
			TavernWaitDate("wait_day");
		break;

		case "tavern_keeper":
			Diag.TempNode = "second time";
			
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\FRCO\FRCO020";
			dialog.text = DLG_TEXT[76];
			link.l1 = DLG_TEXT[77];
			link.l1.go = "exit_sit";
		break;

		case "exit_sit":
			Diag.CurrentNode = Diag.TempNode;
			//NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			AddDialogExitQuest("exit_sit");
		break;
		
		case "convoy":
			npchar.work = lastspeak_date;
			if (GetCompanionIndex(pchar,1) != -1 && GetCompanionIndex(pchar,2) != -1 && GetCompanionIndex(pchar,3) != -1)
			{
				dialog.text = DLG_TEXT[78];
				link.l1 = DLG_TEXT[79];
				link.l1.go = "exit";
			}
			else
			{
				if (GetNationRelation2MainCharacter(GetCurrentLocationNation()) == RELATION_ENEMY)
				{
					dialog.text = DLG_TEXT[80];
					link.l1 = DLG_TEXT[81];
					link.l1.go = "exit";
				}
				else
				{
					if (makeint(pchar.reputation) <25)
					{
						dialog.text = DLG_TEXT[82];
						link.l1 = DLG_TEXT[83];
						link.l1.go = "exit";
					}
					else
					{
						int randomGod = rand(1);
						if (randomGod == 1)
						{
							dialog.text = DLG_TEXT[84];
							link.l1 = DLG_TEXT[85];
							link.l1.go = "exit";
							AddDialogExitQuest("prepare_for_convoy_quest");
							
						}
						else
						{
							dialog.text = DLG_TEXT[86];
							link.l1 = DLG_TEXT[87];
							link.l1.go = "exit";
						}
					}
				}
			}
		break;
	}
}
