//#include "DIALOGS\Charles Windem_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;

	int iTest, iTime, iAddTime;

	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Diag.TempNode = "First time";

			if(NPChar.quest.meeting == "0")
			{
				dialog.snd = "Voice\CHWI\CHWI001";
				d.Text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1];
				Link.l1 = DLG_TEXT[2] + GetMyFullName(PChar) + DLG_TEXT[3];
				Link.l1.go = "meeting";
				NPChar.quest.meeting = "1";
				Dialog.snd = "dialogs\speech\chrar001";
			}
			else
			{
				dialog.snd1 = "Voice\CHWI\CHWI002";
				dialog.snd2 = "Voice\CHWI\CHWI003";
				dialog.snd3 = "Voice\CHWI\CHWI004";
				d.Text = RandPhrase(DLG_TEXT[4] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + GetMyName(PChar) + DLG_TEXT[5] + TimeGreeting() + DLG_TEXT[6], DLG_TEXT[7] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + GetMyName(PChar) + DLG_TEXT[8], DLG_TEXT[9] + GetMyName(Pchar) + DLG_TEXT[10], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				Link.l1 = DLG_TEXT[11];
				Link.l1.go = "crew hire";
				Link.l2 = DLG_TEXT[12];
				Link.l2.go = "quest lines";
				if (npchar.location == "Redmond_tavern")
				{
					link.l3 = pcharrepphrase(DLG_TEXT[13], DLG_TEXT[14]);
					link.l3.go = "room";
				}
				Link.l99 = DLG_TEXT[15] + GetMyName(NPChar) + DLG_TEXT[16];
				Link.l99.go = "exit";
			}
		break;

		case "Meeting":
			dialog.snd = "Voice\CHWI\CHWI006";
			d.Text = DLG_TEXT[17] + GetMyName(Pchar) + DLG_TEXT[18] + GetMyFullName(NPChar) + DLG_TEXT[19];
			Link.l1 = DLG_TEXT[20] + GetMyName(NPChar) + DLG_TEXT[21];
			Link.l1.go = "crew hire";
			Link.l2 = GetMyName(NPChar) + DLG_TEXT[22];
			Link.l2.go = "quest lines";
			if (npchar.location == "Redmond_tavern")
			{
				link.l3 = pcharrepphrase(DLG_TEXT[23], DLG_TEXT[24]);
				link.l3.go = "room";
			}
			Link.l4 = DLG_TEXT[25];
			Link.l4.go = "exit";
		break;

		case "quest lines":
			dialog.snd = "Voice\CHWI\CHWI007";
			d.Text = DLG_TEXT[26] + GetMyName(Pchar) + DLG_TEXT[27];
			Link.l1 = DLG_TEXT[28];
			Link.l1.go = "rumours";
			Link.l2 = DLG_TEXT[29];
			Link.l2.go = "quest lines_1";
// -->SJG
			if(CheckQuestAttribute("Story_1stTaskComplete", "1"))
			{
			Link.l3 = DLG_TEXT[90];
			Link.l3.go = "WheresBeckett";
			}
			if(CheckQuestAttribute("Story_1stTaskComplete", "2"))
			{
			Link.l3 = DLG_TEXT[90];
			Link.l3.go = "WheresBeckett";
			}
		break;

		case "WheresBeckett":
			dialog.snd = "Voice\CHWI\CHWI007";
			d.Text = DLG_TEXT[91] + PChar.name + ".";
			Link.l1 = DLG_TEXT[92];
			Link.l1.go = "WheresBeckett2";
		break;

		case "WheresBeckett2":
			dialog.snd = "Voice\CHWI\CHWI007";
			d.Text = DLG_TEXT[93];
			Link.l1 = DLG_TEXT[94];
			Link.l1.go = "exit";
		break;
// <--SJG
		case "quest lines_1":
			iTest = 0;
			dialog.snd = "Voice\CHWI\CHWI008";
			d.Text = DLG_TEXT[30];
			if (!CheckQuestAttribute("generate_convoy_quest_progress", "begin") && npchar.work != lastspeak_date && pchar.location != "Quest_redmond_tavern")
			{
				link.l3 = DLG_TEXT[35];
				link.l3.go = "convoy";
			}

			Link.l99 = DLG_TEXT[38] + GetMyName(NPChar) + DLG_TEXT[39];
			Link.l99.go = "No quest";
		break;

		case "convoy":
			npchar.work = lastspeak_date;
			if (GetCompanionIndex(pchar,1) != -1 && GetCompanionIndex(pchar,2) != -1 && GetCompanionIndex(pchar,3) != -1)
			{
				dialog.text = DLG_TEXT[40];
				link.l1 = DLG_TEXT[41];
				link.l1.go = "exit";
			}
			else
			{
				if (GetNationRelation2MainCharacter(GetCurrentLocationNation()) == RELATION_ENEMY) // KK
				{
					dialog.text = DLG_TEXT[42];
					link.l1 = DLG_TEXT[43];
					link.l1.go = "exit";
				}
				else
				{
					if (makeint(pchar.reputation) <25)
					{
						dialog.text = DLG_TEXT[44];
						link.l1 = DLG_TEXT[45];
						link.l1.go = "exit";
					}
					else
					{
						int randomGod = rand(1);
						if (randomGod == 1)
						{
							dialog.text = DLG_TEXT[46];
							link.l1 = DLG_TEXT[47];
							link.l1.go = "exit";
							pchar.quest.destination = GetTownIDFromLocID(NPChar.location); // KK
							AddDialogExitQuest("prepare_for_convoy_quest");
						}
						else
						{
							dialog.text = DLG_TEXT[48];
							link.l1 = DLG_TEXT[49];
							link.l1.go = "exit";
						}
					}
				}
			}
		break;

		case "rumours":
			d.Text = SelectRumour(FindIslandByLocation(LoadedLocation.id), GetNationIDByType(GetCurrentLocationNation()) ); // KK
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "crew hire";
			Link.l2 = DLG_TEXT[51];
			Link.l2.go = "quest lines";
			Link.l3 = DLG_TEXT[52] + GetMyName(NPChar) + DLG_TEXT[53];
			Link.l3.go = "exit";
		break;

		case "no quest":
			dialog.snd = "Voice\CHWI\CHWI009";
			d.Text = DLG_TEXT[54];
			Link.l1 = DLG_TEXT[55];
			Link.l1.go = "crew hire";
			Link.l2 = DLG_TEXT[56];
			Link.l2.go = "quest lines";
			Link.l3 = DLG_TEXT[57] + GetMyName(NPChar) + DLG_TEXT[58];
			Link.l3.go = "exit";
		break;

		case "Story_Ewan Glover":
			dialog.snd = "Voice\CHWI\CHWI010";
			d.Text = DLG_TEXT[59] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[60])]) + DLG_TEXT[61] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[62];
			Link.l1 = DLG_TEXT[63];
			Link.l1.go = "exit";
			AddDialogExitQuest("Glover_exit");
		break;


		case "crew hire":
			if (makeint(environment.time) > 22.0 || makeint(environment.time) < 10.0)
			{
				dialog.snd = "Voice\CHWI\CHWI011";
				Dialog.text = DLG_TEXT[64];
				if (npchar.location == "Redmond_tavern")
				{
					link.l1 = DLG_TEXT[65];
					link.l1.go = "room";
				}
				link.l2 = DLG_TEXT[66];
				link.l2.go = "quest lines";
			}
			else
			{
				Diag.CurrentNode = Diag.TempNode;
				DialogExit();
				LaunchHireCrew();
			}
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "room":
			string roomWait = "";
			dialog.snd = "Voice\CHWI\CHWI012";
			dialog.text = DLG_TEXT[67];
			if (makeint(environment.time) >= 22.0 || makeint(environment.time) < 10.0)
			{
				roomWait = "eveningwait";
				link.l1 = DLG_TEXT[68];
				link.l1.go = "room_day";
			}
			else
			{
				roomWait = "daywait";
				link.l1 = DLG_TEXT[69];
				link.l1.go = "room_night";
			}
			link.l2 = XI_ConvertString("Until tomorrow") + " " + XI_ConvertString(roomWait) + ".";
			link.l2.go = "room_24";
		break;

		case "room_24":
			dialog.snd = "Voice\ANLE\ANLE014";
			Dialog.text = DLG_TEXT[70];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[71];
				link.l1.go = "room_24_wait";
			}
			link.l2 = pcharrepphrase(DLG_TEXT[72], DLG_TEXT[73]);
			link.l2.go = "hall_24_wait";
			link.l3 = DLG_TEXT[74];
			link.l3.go = "quest lines";
		break;

		case "room_24_wait":
			DialogExit();
			Diag.CurrentNode =  Diag.TempNode;
			PlayStereoSound("INTERFACE\took_item.flac");
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
			dialog.snd = "Voice\CHWI\CHWI013";
			Dialog.text = DLG_TEXT[70];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[71];
				link.l1.go = "room_day_wait";
			}
			link.l2 = pcharrepphrase(DLG_TEXT[72], DLG_TEXT[73]);
			link.l2.go = "hall_day_wait";
			link.l3 = DLG_TEXT[74];
			link.l3.go = "quest lines";
		break;

		case "room_night":
			dialog.snd = "Voice\CHWI\CHWI014";
			Dialog.text = DLG_TEXT[75];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[76];
				link.l1.go = "room_night_wait";
			}
			link.l2 = pcharrepphrase(DLG_TEXT[77], DLG_TEXT[78]);
			link.l2.go = "hall_night_wait";
			link.l3 = DLG_TEXT[79];
			link.l3.go = "quest lines";
		break;

		case "room_night_wait":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(pchar, -5);
			AddDialogExitQuest("sleep_in_tavern");
			TavernWaitDate2("wait_night");
		break;

		case "hall_night_wait":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			TavernWaitDate("wait_night");
		break;

		case "room_day_wait":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(pchar, -5);
			AddDialogExitQuest("sleep_in_tavern");
			TavernWaitDate2("wait_day");
		break;

		case "hall_day_wait":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			TavernWaitDate("wait_day");
		break;

		case "tavern_keeper":
			Diag.TempNode = "first time";

			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			dialog.snd = "Voice\CHWI\CHWI015";

			dialog.text = DLG_TEXT[80];
			link.l1 = DLG_TEXT[81];
			link.l1.go = "exit_sit";
		break;

		case "exit_sit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("exit_sit");
		break;
	}
}
