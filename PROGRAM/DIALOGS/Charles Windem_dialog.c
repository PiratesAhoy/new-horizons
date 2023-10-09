//#include "DIALOGS\Charles Windem_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string gov_kid, merch_kid;

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
			    //JRH -->
				if(CheckAttribute(Pchar,"quest.wr_quest1") && Pchar.quest.wr_quest1 == "off")
				{
					Link.l4 = DLG_TEXT[95];
					Link.l4.go = "where_are_they_hint";
				}
			    //<-- JRH
				Link.l99 = DLG_TEXT[15] + GetMyName(NPChar) + DLG_TEXT[16];
				Link.l99.go = "exit";
			     //JRH -->
				if(CheckAttribute(Pchar,"quest.med_Windem") && Pchar.quest.med_Windem == "empty_bottles")
				{
					Link.l7 = DLG_TEXT[109];
					if(CheckCharacterItem(Pchar,"pistolmdchest_F2B") || CheckCharacterItem(Pchar,"pistolmdchest_F2B_C") 
				    		|| CheckCharacterItem(Pchar,"pistolmdchest_F2B_S") || CheckCharacterItem(Pchar,"pistolmdchest_F2B_CS"))
					{
						Link.l7.go = "empty_bottles";
					}
					else
					{
						Link.l7.go = "not_without_medchest";
					}
				}
			    //<-- JRH
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
		    //JRH -->
			if(CheckAttribute(Pchar,"quest.wr_quest1") && Pchar.quest.wr_quest1 == "off")
			{
				Link.l4 = DLG_TEXT[90];
				Link.l4.go = "where_are_they";
			}
		    //<-- JRH
			Link.l5 = DLG_TEXT[25];
			Link.l5.go = "exit";
		    //JRH -->
			if(CheckAttribute(Pchar,"quest.med_Windem") && Pchar.quest.med_Windem == "empty_bottles")
			{
				Link.l6 = DLG_TEXT[109];
				if(CheckCharacterItem(Pchar,"pistolmdchest_F2B") || CheckCharacterItem(Pchar,"pistolmdchest_F2B_C")
				    	|| CheckCharacterItem(Pchar,"pistolmdchest_F2B_S") || CheckCharacterItem(Pchar,"pistolmdchest_F2B_CS"))
				{
					Link.l6.go = "empty_bottles";
				}
				else
				{
					Link.l6.go = "not_without_medchest";
				}
			}
		    //<-- JRH
		break;

		case "quest lines":
			dialog.snd = "Voice\CHWI\CHWI007";
			d.Text = DLG_TEXT[26] + GetMyName(Pchar) + DLG_TEXT[27];
			Link.l1 = DLG_TEXT[28];
			Link.l1.go = "rumours";
			Link.l2 = DLG_TEXT[29];
			Link.l2.go = "quest lines_1";
		break;

		case "quest lines_1":
			iTest = 0;
			dialog.snd = "Voice\CHWI\CHWI008";
			d.Text = DLG_TEXT[30];
			if(Checkattribute(Pchar, "Quest.Story_Ask_for_Glover") && Pchar.quest.Story_ask_for_glover == "1" && iTest < QUEST_COUNTER)
			{
				Link.l1 = GetMyName(NPChar) + DLG_TEXT[31] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[32])]) + DLG_TEXT[34];
				Link.l1.go = "Story_Ewan Glover";
			}
			if (!CheckQuestAttribute("generate_convoy_quest_progress", "begin") && npchar.work != lastspeak_date && pchar.location != "Quest_redmond_tavern")
			{
				link.l3 = DLG_TEXT[35];
				link.l3.go = "convoy";
			}

//Lucas
			if (CheckQuestAttribute("lucas", "search"))
			{
				dialog.snd = "Voice\CHWI\CHWI005";
				d.Text = DLG_TEXT[36];
				Link.l4 = DLG_TEXT[37];
				Link.l4.go = "Find_Lucas2";
			}
//Lucas

//Ardent
			if (CheckQuestAttribute("ardent_kidnap.find_merchant", "true"))
			{
				dialog.snd = "Voice\CHWI\CHWI005";
				d.Text = DLG_TEXT[36];
				if (PChar.sex == "man") Preprocessor_Add("kid", XI_ConvertString("lad"));
				else Preprocessor_Add("kid", XI_ConvertString("lass"));
				Link.l5 = DLG_TEXT[114];
				Link.l5.go = "ardent_kidnap1";
			}

			if (CheckQuestAttribute("abduction_status", "pirate_rescued"))
			{
				dialog.snd = "Voice\CHWI\CHWI005";
				d.Text = DLG_TEXT[36];
				if (PChar.sex == "man") Preprocessor_Add("person", XI_ConvertString("woman"));
				else Preprocessor_Add("person", XI_ConvertString("man"));
				Preprocessor_Add("romance", GetMyFullName(CharacterFromID(PChar.quest.romance)));
				Link.l5 = DLG_TEXT[127];
				Link.l5.go = "ardent_abduction1";
			}

			if (CheckQuestAttribute("ardent_kidnap.status", "deal_done"))
			{
				dialog.snd = "Voice\CHWI\CHWI005";
				d.Text = DLG_TEXT[36];
				link.l5 = DLG_TEXT[132];
				link.l5.go = "ardent_kidnap_rescue1";
			}
// Ardent

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
			PlayStereoSound("INTERFACE\took_item.wav");
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
			PlayStereoSound("INTERFACE\took_item.wav");
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

//Lucas
		case "Find_Lucas1":
			dialog.snd = "Voice\CHWI\CHWI016";
			d.Text = DLG_TEXT[82];
			Link.l1 = DLG_TEXT[83];
			Link.l1.go = "Find_Lucas2";
		break;

		case "Find_Lucas2":
			dialog.snd = "Voice\CHWI\CHWI017";
			d.Text = DLG_TEXT[84];
			Link.l1 = DLG_TEXT[85];
			Link.l1.go = "Find_Lucas3";
		break;

		case "Find_Lucas3":
			dialog.snd = "Voice\CHWI\CHWI018";
			d.Text = DLG_TEXT[86];
			Link.l1 = DLG_TEXT[87];
			Link.l1.go = "Find_Lucas4";
		break;

		case "Find_Lucas4":
			dialog.snd = "Voice\CHWI\CHWI019";
			d.Text = DLG_TEXT[88];
			Link.l1 = DLG_TEXT[89];
			Link.l1.go = "Find_Lucas_exit";
		break;

		case "Find_Lucas_exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();

			AddDialogExitQuest("Lucas_search1");
		break;
//Lucas

	//JRH -->
//Woodes Rogers
		case "where_are_they":
			d.Text = DLG_TEXT[91];
			Link.l1 = DLG_TEXT[92];
			Link.l1.go = "where_are_they2";
		break;

		case "where_are_they2":
			d.Text = DLG_TEXT[93];
			Link.l1 = DLG_TEXT[94];
			Link.l1.go = "exit";
		break;

		case "where_are_they_hint":
			PlaySound("OBJECTS\DUEL\man_attack5.wav");
			d.Text = DLG_TEXT[96];
			Link.l1 = DLG_TEXT[97];
			Link.l1.go = "exit";
		break;

		case "pistol1":
			d.Text = DLG_TEXT[98];
			Link.l1 = DLG_TEXT[99];
			Link.l1.go = "pistol1_A";
		break;

		case "pistol1_A":
			d.Text = DLG_TEXT[100];
			Link.l1 = DLG_TEXT[101];
			Link.l1.go = "pistol1_B";
		break;

		case "pistol1_B":
			d.Text = DLG_TEXT[102];
			Link.l1 = DLG_TEXT[103];
			Link.l1.go = "pistol1_C";
		break;

		case "pistol1_C":
			d.Text = DLG_TEXT[104];
			if (makeint(pchar.money) >= 5)
			{
				PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneyToCharacter(pchar, -5);
				Link.l1 = DLG_TEXT[105];
				Link.l1.go = "exit";
				AddDialogExitQuest("library_open");
			}
			else
			{
				Link.l2 = DLG_TEXT[106];
				Link.l2.go = "pistol1_D";
			}
		break;

		case "pistol1_D":
			d.Text = DLG_TEXT[107];
			Link.l1 = DLG_TEXT[108];
			Link.l1.go = "exit";
			AddDialogExitQuest("library_closed");
		break;

		case "not_without_medchest":
			d.Text = DLG_TEXT[112];
			Link.l1 = DLG_TEXT[113];
			Link.l1.go = "exit";
		break;

		case "empty_bottles":
			PlaySound("AMBIENT\SHOP\noise4.wav");
			PlaySound("INTERFACE\button2.wav");
			PlaySound("INTERFACE\button2.wav");
			GiveItem2Character(Pchar, "Empty_bottles");

			d.Text = DLG_TEXT[110];
			Link.l1 = DLG_TEXT[111];
			Link.l1.go = "exit";
			AddDialogExitQuest("Windem_bottles");
		break;
	//<-- JRH

// Ardent -->
		case "ardent_kidnap1":
			DeleteQuestAttribute("ardent_kidnap.find_merchant");
			if (PChar.sex == "man")
			{
				merch_kid = DLG_TEXT[116];
				gov_kid = DLG_TEXT[120];
			}
			else
			{
				merch_kid = DLG_TEXT[117];
				gov_kid = DLG_TEXT[121];
			}
			d.TEXT = DLG_TEXT[115] + GetMyFullName(CharacterFromID(PChar.quest.villain)) + merch_kid + DLG_TEXT[118] + GetMyFullName(CharacterFromID("Gilbert Downing")) + DLG_TEXT[119] + gov_kid + DLG_TEXT[122];
			link.l1 = DLG_TEXT[123] + GetMyFullName(CharacterFromID(PChar.quest.villain)) + DLG_TEXT[124];
			link.l1.go = "ardent_kidnap2";
		break;

		case "ardent_kidnap2":
			d.Text = DLG_TEXT[125];
			link.l1 = DLG_TEXT[126];
			Preprocessor_AddQuestData("merchant", GetMyFullName(CharacterFromID("Gilbert Downing")));
			AddQuestRecord("Kidnap", 19);
			Preprocessor_Remove("merchant");
			link.l1.go = "exit";
		break;

		case "ardent_abduction1":
			Preprocessor_Add("romance", GetMyFullName(CharacterFromID(PChar.quest.romance)));
			Preprocessor_Add("villain", GetMyFullName(CharacterFromID(PChar.quest.villain)));
			d.Text = DLG_TEXT[128];
			link.l1 = DLG_TEXT[129];
			link.l1.go = "ardent_abduction2";
		break;

		case "ardent_abduction2":
			Preprocessor_AddQuestData("romance", GetMySimpleName(CharacterFromID(PChar.quest.romance)));
			Preprocessor_AddQuestData("villain", GetMySimpleName(CharacterFromID(PChar.quest.villain)));
			AddQuestRecord("Abduction", 15);
			Preprocessor_Remove("villain");
			Preprocessor_Remove("romance");
			Preprocessor_Add("romance", GetMyFullName(CharacterFromID(PChar.quest.romance)));
			d.Text = DLG_TEXT[130];
			if (PChar.sex == "man") Preprocessor_Add("pronoun", XI_ConvertString("she"));
			else Preprocessor_Add("pronoun", XI_ConvertString("he"));
			PChar.quest.abduction_status = "married_villain";
			Locations[FindLocation("Redmond_town_03")].reload.l9.disable = 0; // Re-open house of Gilbert Downing
			link.l1 = DLG_TEXT[131];
			link.l1.go = "exit";
		break;

		case "ardent_kidnap_rescue1":
			PChar.quest.ardent_kidnap.status = "buy_wine";
			Preprocessor_Add("romance", GetMyFullName(CharacterFromID(PChar.quest.romance)));
			Preprocessor_Add("villain", GetMyFullName(CharacterFromID(PChar.quest.villain)));
			d.Text = DLG_TEXT[133];
			link.l1 = DLG_TEXT[134];
			link.l1.go = "ardent_kidnap_rescue2";
		break;

		case "ardent_kidnap_rescue2":
			Preprocessor_Add("villain", GetMyFullName(CharacterFromID(PChar.quest.villain)));
			Preprocessor_Add("pronoun", GetMyPronounSubj(CharacterFromID(PChar.quest.villain)));
			d.Text = DLG_TEXT[135];
			link.l1 = DLG_TEXT[136];
			AddDialogExitQuest("kidnap_rescue_goto_Downing_House");
			Locations[FindLocation("Redmond_town_03")].reload.l9.disable = 0;
			link.l1.go = "exit";
		break;
// <-- Ardent
	}
}
