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
		// -----------------------------------|иалог первый - первая встреча
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
			link.l4 = pcharrepphrase(DLG_TEXT[46], DLG_TEXT[47]);
			link.l4.go = "bottle",
			link.l99 = DLG_TEXT[12];
			link.l99.go = "exit";
		break;

		case "quests":
			itest = 0;
			dialog.snd = "Voice\FRCO\FRCO003";
			dialog.text = DLG_TEXT[13];
			if (!CheckQuestAttribute("generate_convoy_quest_progress", "begin") && npchar.work != lastspeak_date)
			{
				link.l10 = DLG_TEXT[14];
				link.l10.go = "convoy";
			}
			if (CheckQuestAttribute("ardent_convoy", "Cartagena"))
			{
				link.l11 = DLG_TEXT[56];
				link.l11.go = "ardent_convoy";
			}
			link.l99 = DLG_TEXT[15];
			link.l99.go = "second time";
		break;

		case "crew":
			if (makeint(environment.time) > 22.0 || makeint(environment.time) < 10.0)
			{
				dialog.snd = "Voice\FRCO\FRCO017";
				Dialog.text = DLG_TEXT[18];
				link.l1 = DLG_TEXT[19];
				link.l1.go = "room";
				link.l2 = DLG_TEXT[20];
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
			dialog.text = DLG_TEXT[21];
			if (makeint(environment.time) >= 22.0 || makeint(environment.time) < 10.0)
			{

				link.l1 = DLG_TEXT[22];
				link.l1.go = "room_day";
			}
			else
			{
				link.l1 = DLG_TEXT[23];
				link.l1.go = "room_night";
			}
		break;

		case "room_day":
			dialog.snd = "Voice\FRCO\FRCO019";
			Dialog.text = DLG_TEXT[24];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[25];
				link.l1.go = "room_day_wait";
			}
			link.l2 = pcharrepphrase(DLG_TEXT[26], DLG_TEXT[27]);
			link.l2.go = "hall_day_wait";
			link.l3 = DLG_TEXT[28];
			link.l3.go = "second time";
		break;

		case "room_night":
			dialog.snd = "Voice\FRCO\FRCO019";
			Dialog.text = DLG_TEXT[29];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[30];
				link.l1.go = "room_night_wait";
			}
			link.l2 = pcharrepphrase(DLG_TEXT[31], DLG_TEXT[32]);
			link.l2.go = "hall_night_wait";
			link.l3 = DLG_TEXT[33];
			link.l3.go = "second time";
		break;

		case "room_night_wait":
			DialogExit();
			Diag.CurrentNode =  Diag.TempNode;
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
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
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
				dialog.text = DLG_TEXT[36];
				link.l1 = DLG_TEXT[37];
				link.l1.go = "exit";
			}
			else
			{
				if (GetNationRelation2MainCharacter(GetCurrentLocationNation()) == RELATION_ENEMY) // KK
				{
					dialog.text = DLG_TEXT[38];
					link.l1 = DLG_TEXT[39];
					link.l1.go = "exit";
				}
				else
				{
					if (makeint(pchar.reputation) <25)
					{
						dialog.text = DLG_TEXT[40];
						link.l1 = DLG_TEXT[41];
						link.l1.go = "exit";
					}
					else
					{
						int randomGod = rand(1);
						if (randomGod == 1)
						{
							dialog.text = DLG_TEXT[42];
							link.l1 = DLG_TEXT[43];
							link.l1.go = "exit";
							AddDialogExitQuest("prepare_for_convoy_quest");
						}
						else
						{
							dialog.text = DLG_TEXT[44];
							link.l1 = DLG_TEXT[45];
							link.l1.go = "exit";
						}
					}
				}
			}
		break;

		case "bottle":
			dialog.text = pcharrepphrase(DLG_TEXT[48], DLG_TEXT[49]);
			link.l1 = DLG_TEXT[50];
			link.l1.go = "choose_bottle";
			link.l2 = DLG_TEXT[51];
			link.l2.go = "second time";
		break;

		case "choose_bottle":
			dialog.text = DLG_TEXT[52];
			if(sti(pchar.money)>=335)
			{
				link.l1 = DLG_TEXT[53];
				link.l1.go = "buy_wine_bottle";
			}
			if(sti(pchar.money)>=137)
			{
				link.l2 = DLG_TEXT[54];
				link.l2.go = "buy_rum_bottle";
			}
			link.l3 = DLG_TEXT[55];
			link.l3.go = "exit";
		break;

		case "buy_wine_bottle":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(Pchar, -335);
			GiveItem2Character(PChar, "potionwine");
			AddDialogExitQuest("sleep_in_tavern");
			if (GetDayTime() == DAY_TIME_NIGHT) TavernWaitDate2("wait_day");
			else TavernWaitDate2("wait_night");
			DialogExit();
			Diag.CurrentNode =  Diag.TempNode;
		break;

		case "buy_rum_bottle":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(Pchar, -137);
			GiveItem2Character(PChar, "potionrum");
			AddDialogExitQuest("sleep_in_tavern");
			if (GetDayTime() == DAY_TIME_NIGHT) TavernWaitDate2("wait_day");
			else TavernWaitDate2("wait_night");
			DialogExit();
			Diag.CurrentNode =  Diag.TempNode;
		break;

		case "ardent_convoy":
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
//			PChar.quest.ardent_convoy = "Cartagena_hotel";
			link.l1.go = "Exit";
		break;
	}
}
