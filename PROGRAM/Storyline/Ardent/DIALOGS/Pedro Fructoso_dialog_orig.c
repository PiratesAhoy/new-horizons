void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag;
	string gov_kid, merch_kid;

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
			if (!CheckQuestAttribute("generate_convoy_quest_progress", "begin") && npchar.work != lastspeak_date)
			{
				link.l10 = DLG_TEXT[14];
				link.l10.go = "convoy";
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
			string roomWait = "";
			if (makeint(environment.time) >= 22.0 || makeint(environment.time) < 10.0)
			{
				roomWait = "eveningwait";
				link.l1 = DLG_TEXT[22];
				link.l1.go = "room_day";
			}
			else
			{
				roomWait = "daywait";
				link.l1 = DLG_TEXT[23];
				link.l1.go = "room_night";
			}
			link.l2 = XI_ConvertString("Until tomorrow") + " " + XI_ConvertString(roomWait) + ".";
			link.l2.go = "room_24";
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

		case "room_24":
			dialog.snd = "Voice\ANLE\ANLE014";
			Dialog.text = DLG_TEXT[29];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[30];
				link.l1.go = "room_24_wait";
			}
			link.l2 = pcharrepphrase(DLG_TEXT[31], DLG_TEXT[32]);
			link.l2.go = "hall_24_wait";
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

		case "free_drink":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\FRCO\FRCO001";
			dialog.text = DLG_TEXT[46] + GetMyFullName(NPChar) + DLG_TEXT[47];
			link.l1 = DLG_TEXT[48] + GetMyFullName(PChar) + DLG_TEXT[49];
			link.l1.go = "free_drink2";
		break;

		case "free_drink2":
			if (PChar.sex == "man")
			{
				gov_kid = "daughter";
				merch_kid = "son";
			}
			else
			{
				gov_kid = "son";
				merch_kid = "daughter";
			}
			dialog.text = DLG_TEXT[50] + gov_kid + DLG_TEXT[51] + merch_kid + DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "exit";

			if (!CheckAttribute(PChar, "kidnap"));
			{
				PChar.quest.kidnap = "Engaged";

				Preprocessor_AddQuestData("gov_kid", gov_kid);
				Preprocessor_AddQuestData("merch_kid", merch_kid);
				SetQuestHeader("Kidnap");
				AddQuestRecord("Kidnap", 1);
				Preprocessor_Remove("gov_kid");
				Preprocessor_Remove("merch_kid");
			}

			Diag.TempNode = "second time";
		break;
	}
}
