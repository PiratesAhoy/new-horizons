void ProcessDialogEvent()
{
	ref NPChar;
	
	DeleteAttribute(&Dialog,"Links");
	aref Link, NextDiag;
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	int iTest, NPC_Meeting;
	
	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;

	ref PChar;
	PChar = GetMainCharacter();

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
			Dialog.snd = "voice\SIHA\SIHA001";

			Dialog.Text = DLG_TEXT[0] + GetMyFullName(NPChar) + DLG_TEXT[1];
			Link.l1 = DLG_TEXT[2];
			Link.l1.go = "second time"; 
			npchar.quest.meeting = "1";
			
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
			Dialog.snd = "voice\SIHA\SIHA002";

			NextDiag.TempNode = "second time";

			dialog.text = DLG_TEXT[3] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[4];
			link.l1 = pcharrepphrase(DLG_TEXT[5], DLG_TEXT[6]);
			link.l1.go = "crew";
			link.l2 = DLG_TEXT[7];
			link.l2.go = "quests";
			link.l3 = pcharrepphrase(DLG_TEXT[8], DLG_TEXT[9]);
			link.l3.go = "room";
			link.l99 = pcharrepphrase(DLG_TEXT[10], DLG_TEXT[11]);
			link.l99.go = "exit";
		break;
		
		case "quests":
			iTest = 0;
			Dialog.snd = "voice\SIHA\SIHA003";
			dialog.text = DLG_TEXT[12];
			if (!CheckQuestAttribute("generate_convoy_quest_progress", "begin") && npchar.work != lastspeak_date)
			{
				link.l11 = DLG_TEXT[34];
				link.l11.go = "convoy";
			}
			link.l99 = DLG_TEXT[35];
			link.l99.go = "exit";
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

		case "crew":
			if (makeint(environment.time) > 22.0 || makeint(environment.time) < 10.0)
			{
				Dialog.snd = "voice\SIHA\SIHA025";
				Dialog.text = DLG_TEXT[103];
				link.l1 = DLG_TEXT[104];
				link.l1.go = "room";
				link.l2 = DLG_TEXT[105];
				link.l2.go = "quests";
			}
			else
			{
				Dialog.CurrentNode = NextDiag.TempNode; // NK 4-12
				NPChar.quest.meeting = NPC_Meeting;
				DialogExit();
				LaunchHireCrew();
			}
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "room":
			Dialog.snd = "voice\SIHA\SIHA026";
			dialog.text = DLG_TEXT[106];
			string roomWait = "";
			if (makeint(environment.time) >= 22.0 || makeint(environment.time) < 10.0)
			{
				roomWait = "eveningwait";
				link.l1 = DLG_TEXT[107];
				link.l1.go = "room_day";
			}
			else
			{
				roomWait = "daywait";
				link.l1 = DLG_TEXT[108];
				link.l1.go = "room_night";
			}
			link.l2 = XI_ConvertString("Until tomorrow") + " " + XI_ConvertString(roomWait) + ".";
			link.l2.go = "room_24";
		break;

		case "room_24":
			dialog.snd = "Voice\ANLE\ANLE014";
			Dialog.text = DLG_TEXT[109];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[110];
				link.l1.go = "room_24_wait";
			}
			link.l2 = pcharrepphrase(DLG_TEXT[111], DLG_TEXT[112]);
			link.l2.go = "hall_24_wait";
			link.l3 = DLG_TEXT[113];
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
			Dialog.snd = "voice\SIHA\SIHA027";
			Dialog.text = DLG_TEXT[109];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[110];
				link.l1.go = "room_day_wait";
			}
			link.l2 = pcharrepphrase(DLG_TEXT[111], DLG_TEXT[112]);
			link.l2.go = "hall_day_wait";
			link.l3 = DLG_TEXT[113];
			link.l3.go = "second time";
		break;

		case "room_night":
			Dialog.snd = "voice\SIHA\SIHA028";
			Dialog.text = DLG_TEXT[114];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[115];
				link.l1.go = "room_night_wait";
			}
			link.l2 = pcharrepphrase(DLG_TEXT[116], DLG_TEXT[117]);
			link.l2.go = "hall_night_wait";
			link.l3 = DLG_TEXT[118];
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
			Dialog.snd = "voice\SIHA\SIHA029";

			dialog.text = DLG_TEXT[119];
			link.l1 = DLG_TEXT[120];
			link.l1.go = "exit_sit";
		break;

		case "exit_sit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			AddDialogExitQuest("exit_sit");
		break;
	}
}
