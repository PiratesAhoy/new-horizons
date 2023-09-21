void ProcessDialogEvent()
{
	ref NPChar;
	int NPC_meeting;
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
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay1";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\ANLE\ANLE001";
			Dialog.Text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1];
			Link.l1 = pcharrepphrase(DLG_TEXT[2] + GetMyFullName(PChar) + DLG_TEXT[3], DLG_TEXT[4] + GetMyFullName(PChar) + DLG_TEXT[5]);
			Link.l1.go = "rumours";
			NextDiag.TempNode = "Second time";
		break;

		case "rumours":
			dialog.snd = "Voice\ANLE\ANLE010";
			Dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "rumours_1";
			link.l2 = pcharrepphrase(DLG_TEXT[31], DLG_TEXT[32]);
			link.l2.go = "room";
			Link.l3 = DLG_TEXT[80];
			Link.l3.go = "exit";
		break;

		case "room":
			dialog.snd = "Voice\ANLE\ANLE012";
			dialog.text = DLG_TEXT[38];
			string roomWait = "";
			if (makeint(environment.time) >= 22.0 || makeint(environment.time) < 10.0)
			{
				roomWait = "eveningwait";
				link.l1 = DLG_TEXT[39];
				link.l1.go = "room_day";
			}
			else
			{
				roomWait = "daywait";
				link.l1 = DLG_TEXT[40];
				link.l1.go = "room_night";
			}
			link.l2 = DLG_TEXT[277] + XI_ConvertString(roomWait) + ".";
			link.l2.go = "room_24";
		break;

		case "room_day":
			dialog.snd = "Voice\ANLE\ANLE013";
			Dialog.text = DLG_TEXT[41];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[42];
				link.l1.go = "room_day_wait";
			}
			link.l2 = pcharrepphrase(DLG_TEXT[43], DLG_TEXT[44]);
			link.l2.go = "hall_day_wait";
			link.l3 = DLG_TEXT[45];
			link.l3.go = "second time";
		break;

		case "room_night":
			dialog.snd = "Voice\ANLE\ANLE014";
			Dialog.text = DLG_TEXT[46];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[47];
				link.l1.go = "room_night_wait";
			}
			link.l2 = pcharrepphrase(DLG_TEXT[48], DLG_TEXT[49]);
			link.l2.go = "hall_night_wait";
			link.l3 = DLG_TEXT[50];
			link.l3.go = "second time";
		break;

		case "room_24":
			dialog.snd = "Voice\ANLE\ANLE014";
			Dialog.text = DLG_TEXT[46];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[47];
				link.l1.go = "room_24_wait";
			}
			link.l2 = pcharrepphrase(DLG_TEXT[48], DLG_TEXT[49]);
			link.l2.go = "hall_24_wait";
			link.l3 = DLG_TEXT[50];
			link.l3.go = "second time";
		break;

		case "room_night_wait":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			PlayStereoSound("INTERFACE\took_item.flac");
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
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(pchar, -5);
			AddDialogExitQuest("sleep_in_tavern");
			TavernWaitDate2("wait_day");
		break;

		case "hall_day_wait":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			TavernWaitDate("wait_day");
		break;

		case "room_24_wait":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			PlayStereoSound("INTERFACE\took_item.flac");
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

		case "rumours_good":
			Dialog.text = SelectRumour(FindIslandByLocation(LoadedLocation.id), GetNationIDByType(GetCurrentLocationNation()) ); // KK
			Link.l1 = DLG_TEXT[51];
			link.l1.go = "rumours_1";
			link.l2 = DLG_TEXT[53];
			link.l2.go = "crew";
		break;

		case "rumours_1":
			iTest = 0;
			dialog.snd = "Voice\ANLE\ANLE015";
			Dialog.text = DLG_TEXT[56] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[57];
			Link.l1 = DLG_TEXT[78];
			Link.l1.go = "rumours_good";
			if(CheckAttribute(npchar,"work")) npchar.work = npchar.work;
			else npchar.work = "";
			if (!CheckQuestAttribute("generate_convoy_quest_progress", "begin") && npchar.work != lastspeak_date)
			{
				link.l2 = DLG_TEXT[79];
				link.l2.go = "convoy";
			}
			if (CheckQuestAttribute("Santiago", "payertavernier"))
			{
				link.l2 = DLG_TEXT[278];
				link.l2.go = "tav_1";
			}
			if (CheckQuestAttribute("Santiago", "paspayerhum")&& makeint(pchar.money >= 1000))
			{
				link.l1 = DLG_TEXT[280];
				link.l1.go = "tav_2";
			}

			Link.l3 = DLG_TEXT[80];
			Link.l3.go = "exit";
		break;
		
		case "convoy":
			npchar.work = lastspeak_date;
			if (GetCompanionIndex(pchar,1) != -1 && GetCompanionIndex(pchar,2) != -1 && GetCompanionIndex(pchar,3) != -1)
			{
				dialog.text = DLG_TEXT[81];
				link.l1 = DLG_TEXT[82];
				link.l1.go = "exit";
			}
			else
			{
				if (GetNationRelation2MainCharacter(GetCurrentLocationNation()) == RELATION_ENEMY)
				{
					dialog.text = DLG_TEXT[83];
					link.l1 = DLG_TEXT[84];
					link.l1.go = "exit";
				}
				else
				{
					if (makeint(pchar.reputation) <25)
					{
						dialog.text = DLG_TEXT[85];
						link.l1 = DLG_TEXT[86];
						link.l1.go = "exit";
					}
					else
					{
						int randomGod = rand(1);
						if (randomGod == 1)
						{
							dialog.text = DLG_TEXT[87];
							link.l1 = DLG_TEXT[88];
							link.l1.go = "exit";
							AddDialogExitQuest("prepare_for_convoy_quest");
							
						}
						else
						{
							dialog.text = DLG_TEXT[89];
							link.l1 = DLG_TEXT[90];
							link.l1.go = "exit";
						}
					}
				}
			}
		break;

		case "Second time":
			dialog.snd = "Voice\ANLE\ANLE035";
			Dialog.text = DLG_TEXT[158] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[159];
			link.l1 = pcharrepphrase(DLG_TEXT[160], DLG_TEXT[161]);
			link.l1.go = "rumours";
			link.l2 = pcharrepphrase(DLG_TEXT[162], DLG_TEXT[163]);
			link.l2.go = "crew";
			link.l3 = pcharrepphrase(DLG_TEXT[164], DLG_TEXT[165]);
			link.l3.go = "room";
			Link.l99 = DLG_TEXT[80];
			Link.l99.go = "exit";
			NextDiag.TempNode = "Second time";
		break;

		case "crew":
			if (makeint(environment.time) <= 22.0 && makeint(environment.time) >= 10.0)
			{
				DialogExit();
				NextDiag.CurrentNode =  NextDiag.TempNode;
				launchhirecrew();
			}
			else
			{
				dialog.snd = "Voice\ANLE\ANLE064";
				dialog.text = DLG_TEXT[252];
				link.l1 = DLG_TEXT[253];
				link.l1.go = "room";
				link.l2 = DLG_TEXT[254];
				link.l2.go = "second time";
			}
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
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
			Dialog.snd = "dialogs\0\009";

			dialog.snd = "Voice\ANLE\ANLE071";
			dialog.text = DLG_TEXT[275];
			link.l1 = DLG_TEXT[276];
			link.l1.go = "exit_sit";
		break;

		case "tav_1":
			dialog.snd = "Voice\CLLA\CLLA008";
			dialog.text = DLG_TEXT[279];
			if (makeint(pchar.money >= 1000))
			{
				link.l1 = DLG_TEXT[280];
				link.l1.go = "tav_2";
			}
			link.l2 = DLG_TEXT[281];
			link.l2.go = "exit";
			pchar.quest.santiago = "paspayerhum";
		break;

		case "tav_2":
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(pchar, -1000);
			dialog.snd = "Voice\CLLA\CLLA006";
			dialog.text = DLG_TEXT[282];
			link.l1 = DLG_TEXT[283];
			link.l1.go = "exit";
			ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "Guadeloupe_Port", "Officers", "Reload4_1");	
			AddDialogExitQuest("directavernier");
		break;

		case "exit_sit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			AddDialogExitQuest("exit_sit");
		break;
	}
}
