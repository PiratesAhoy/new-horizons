//#include "DIALOGS\Simon Hanpool_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"

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
			if(CheckQuestAttribute("RheimsBook","1")) //for Mosh d23
			{
				link.l10 = DLG_TEXT[13];
				link.l10.go = "Node_2";
			}
			if (pchar.quest.main_line == "after_library" && iTest < QUEST_COUNTER)
			{
				Preprocessor_Add("pronoun2", XI_ConvertString(GetMyPronounObj(CharacterFromID("Danielle"))));
				if (Characters[GetCharacterIndex(DLG_TEXT[15])].sex == "woman") Preprocessor_Add("person", XI_ConvertString("girl"));
				else Preprocessor_Add("person", XI_ConvertString("man"));
				link.l1 = DLG_TEXT[14] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[15])]) + DLG_TEXT[17];
				link.l1.go = "search_danielle";
				iTest = iTest + 1;
			}
			if (Characters[GetCharacterIndex("Father Bernard")].quest.church_help == "to_greenford" && iTest < QUEST_COUNTER)
			{
				link.l2 = DLG_TEXT[18];	
				link.l2.go = "church_help";
				iTest = iTest + 1;
			}
			if (Characters[GetCharacterIndex("Father Bernard")].quest.church_help == "after_off" && iTest < QUEST_COUNTER)
			{
				link.l3 = DLG_TEXT[19];	
				link.l3.go = "after_off";
				iTest = iTest + 1;
			}
			if (Characters[GetCharacterIndex("Father Bernard")].quest.church_help == "bad_dautch")
			{
				link.l4 = DLG_TEXT[20];
				link.l4.go = "good_dautch";
				iTest = iTest + 1;
			}
			if (Characters[GetCharacterIndex("Father Bernard")].quest.church_help == "dautch_denied")
			{
				link.l4 = DLG_TEXT[21];
				link.l4.go = "good_dautch";
				iTest = iTest + 1;
			}
			if (Characters[GetCharacterIndex("Father Bernard")].quest.church_help == "good_dautch")
			{
				link.l5 = DLG_TEXT[22];
				link.l5.go = "good_dautch";
				iTest = iTest + 1;
			}
			if (pchar.quest.main_line == "return_idol_from_greenford_soldier" && iTest < QUEST_COUNTER)
			{
				link.l6 = DLG_TEXT[23] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[24])]) + DLG_TEXT[26];
				link.l6.go = "idol";
				iTest = iTest + 1;
			}
			if (CheckQuestAttribute("ANIMISTS", "to_greenford") || CheckQuestAttribute("ANIMISTS","after_pirates") || CheckQuestAttribute("ANIMISTS", "to_greenford_2"))
			{
				link.l7 = DLG_TEXT[27];
				link.l7.go = "ANIMISTS";
			}
			if(CheckQuestAttribute("Find_Blaze","TalkWithBarmen"))
			{
				link.l8 = DLG_TEXT[28] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[29])]) + DLG_TEXT[31];
				link.l8.go = "FindBlaze_1";
			}
			if(CheckQuestAttribute("RheimsBook","24"))//For Mosh36
			{
				if (makeint(pchar.money) > 0)
				{
					link.l9 = DLG_TEXT[32];
					link.l9.go = "maskarad";
				}
			}
			if (CheckQuestAttribute("ANIMISTS", "to_greenford_for_teacher"))
			{
				link.l1 = DLG_TEXT[33];
				link.l1.go = "to_greenford_for_teacher_2";
			}

 // Viper - fix for Missing Children Quest begin
			if (CheckQuestAttribute("ANIMISTS", "to_prison_for_teacher") && LAi_IsDead(characterFromID("Greenford Prison Commendant")))
			{
				link.l1 = DLG_TEXT[121];
				link.l1.go = "dopros";
			}
// Viper - fix for Missing Children Quest end

			if (!CheckQuestAttribute("generate_convoy_quest_progress", "begin") && npchar.work != lastspeak_date)
			{
				link.l10 = DLG_TEXT[34];
				link.l10.go = "convoy";
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


 // Viper - fix for Missing Children Quest begin
		case "to_greenford_for_teacher_2":
			if (LAi_IsDead(characterFromID("Greenford Prison Commendant")))
			{
				dialog.text = DLG_TEXT[124]
				link.l1 = DLG_TEXT[123];
				link.l1.go = "exit";
				pchar.quest.ANIMISTS = "wardendead";
				AddDialogExitQuest("mystery_man_to_prison");
				AddQuestRecord("ANIMISTS", 38);
			}
			else
			{
				LAi_warrior_DialogEnable(CharacterFromID("Greenford Prison Commendant"), true);//PW: Enable dialog for replacement warden
				Characters[GetCharacterIndex("Greenford Prison Commendant")].Dialog.Filename = "Greenford Commander_dialog.c";
				Dialog.snd = "voice\SIHA\SIHA004";
				dialog.text = DLG_TEXT[46];
				link.l1 = DLG_TEXT[47];
				link.l1.go = "exit";
				pchar.quest.ANIMISTS = "to_prison_for_teacher";
				AddQuestRecord("ANIMISTS", 27);
			}
		break;

		case "dopros":
			dialog.text = DLG_TEXT[122];
			link.l1 = DLG_TEXT[123];
			link.l1.go = "exit";
			pchar.quest.ANIMISTS = "wardendead";
			AddDialogExitQuest("mystery_man_to_prison");
			AddQuestRecord("ANIMISTS", 38);
		break;
 // Viper - fix for Missing Children Quest end

		case "Node_2":
			Dialog.snd = "voice\SIHA\SIHA005";
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "exit";
			Pchar.quest.RheimsBook = "2";//For Mosh d24
			chrEnableReloadLocator("Greenford_town","reload17",true);
			AddQuestRecord("Story_Find_Rheims", 112);
		break;


		case "maskarad":
			Dialog.snd = "voice\SIHA\SIHA006";
			dialog.text = DLG_TEXT[50];
			if (makeint(pchar.money) >=50)
			{
				link.l1 = DLG_TEXT[51];
				link.l1.go = "maskarad_2";
			}
			link.l2 = DLG_TEXT[52];
			link.l2.go = "exit";
			AddDialogExitQuest("check_for_maskarad");
			pchar.quest.RheimsBook = "24_1";
		break;

		case "maskarad_2":
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(pchar, -50);
			Dialog.snd = "voice\SIHA\SIHA007";
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "exit";
			pchar.quest.RheimsBook = "24_2";
		break;

		case "FindBlaze_1":
			Dialog.snd = "voice\SIHA\SIHA008";
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "exit";
			AddDialogExitQuest("danielle_greenford_talk_barman");
		break;

		case "ANIMISTS":
			Dialog.snd = "voice\SIHA\SIHA009";
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "ANIMISTS_2";
		break;

		case "ANIMISTS_2":
			Dialog.snd = "voice\SIHA\SIHA010";
			dialog.text = DLG_TEXT[59] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[60])]) + DLG_TEXT[62];
			link.l1 = DLG_TEXT[63];
			link.l1.go = "exit";
			pchar.quest.ANIMISTS = "after_samuelle";
		break;

		case "good_dautch":
			Dialog.snd = "voice\SIHA\SIHA011";
			dialog.text = DLG_TEXT[64];
			link.l1 = DLG_TEXT[65];
			link.l1.go = "exit";
			Characters[GetCharacterIndex("Father Bernard")].quest.church_help = "almost_done";
			Preprocessor_AddQuestData("Jerald", GetMyLastName(CharacterFromID("Father Jerald")));
			AddQuestRecord("church_help", 12);
			Preprocessor_Remove("Jerald");
		break;

		case "after_off":
			Dialog.snd = "voice\SIHA\SIHA012";
			dialog.text = DLG_TEXT[66];
			link.l1 = DLG_TEXT[67];
			link.l1.go = "after_off_2";
		break;

		case "after_off_2":
			Dialog.snd = "voice\SIHA\SIHA013";
			dialog.text = DLG_TEXT[68] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[69])]) + DLG_TEXT[71];
			link.l1 = DLG_TEXT[72];
			link.l1.go = "exit";
			pchar.quest.Church_help = "Kinne";  //  --Cat
			AddQuestRecord("church_help", 8);
			Characters[GetCharacterIndex("Father Bernard")].quest.church_help = "to_dautch";
			Locations[FindLocation("Yedam Kinne_house")].vcskip = true; // NK
		break;

		case "idol":
			Dialog.snd = "voice\SIHA\SIHA014";
			dialog.text = DLG_TEXT[73];
			link.l1 = DLG_TEXT[74];
			link.l1.go = "idol_2";
		break;

		case "idol_2":
			Dialog.snd = "voice\SIHA\SIHA015";
			if (Characters[GetCharacterIndex("Danielle")].sex == "woman") dialog.text = DLG_TEXT[75];
			else dialog.text = DLG_TEXT[125];
			link.l1 = DLG_TEXT[76];
			link.l1.go = "idol_3";
		break;

		case "idol_3":
			Dialog.snd = "voice\SIHA\SIHA016";
			dialog.text = DLG_TEXT[77];
			link.l1 = DLG_TEXT[78];
			link.l1.go = "exit";
			pchar.quest.main_line = "return_idol_from_greenford";
			AddQuestRecord("Revenge_for_Silehard", 6);
		break;

		case "church_help":
			Dialog.snd = "voice\SIHA\SIHA017";
			dialog.text = DLG_TEXT[79] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[80])]) + DLG_TEXT[82] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[83];
			link.l1 = DLG_TEXT[84];
			link.l1.go = "exit";
			Characters[GetCharacterIndex("Father Bernard")].quest.church_help = "after_traktir";
			Preprocessor_AddQuestData("SimonHanpool", GetMySimpleName(CharacterFromID("Simon Hanpool")));
			AddQuestRecord("church_help", 2);
			Preprocessor_Remove("SimonHanpool");
		break;

		case "search_danielle":
			Dialog.snd = "voice\SIHA\SIHA018";
			Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounSubj(CharacterFromID("Danielle"))));
			Preprocessor_Add("pronoun2", XI_ConvertString(GetMyPronounObj(CharacterFromID("Danielle"))));
			dialog.text = DLG_TEXT[85];
			link.l1 = DLG_TEXT[86];
			link.l1.go = "search_danielle_2";
		break;

		case "search_danielle_2":
			Dialog.snd = "voice\SIHA\SIHA019";
			dialog.text = DLG_TEXT[87] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[88];
			if (makeint(pchar.money) >=1)
			{
				link.l1 = DLG_TEXT[89];
				link.l1.go = "search_danielle_3";
			}
			link.l2 = DLG_TEXT[90];
			link.l2.go = "exit";
		break;

		case "search_danielle_3":
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(pchar, -1);
			Dialog.snd = "voice\SIHA\SIHA020";
			Preprocessor_Add("Pronoun_upper", FirstLetterUp(XI_ConvertString(GetMyPronounSubj(CharacterFromID("Danielle")))));
			Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounSubj(CharacterFromID("Danielle"))));
			Preprocessor_Add("pronoun2", XI_ConvertString(GetMyPronounObj(CharacterFromID("Danielle"))));
			dialog.text = DLG_TEXT[91];
			link.l1 = DLG_TEXT[92];
			link.l1.go = "search_danielle_4";
		break;

		case "search_danielle_4":
			Dialog.snd = "voice\SIHA\SIHA021";
			dialog.text = DLG_TEXT[93] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[94];
			if (makeint(pchar.money) >=1)
			{
				link.l1 = DLG_TEXT[95];
				link.l1.go = "search_danielle_5";
			}
			link.l2 = DLG_TEXT[96];
			link.l2.go = "exit";
		break;

		case "search_danielle_5":
			Dialog.snd = "voice\SIHA\SIHA022";
			dialog.text  = DLG_TEXT[97];
			link.l1 = DLG_TEXT[98];
			link.l1.go = "search_danielle_6";
		break;

		case "search_danielle_6":
			Dialog.snd = "voice\SIHA\SIHA023";
			dialog.text = DLG_TEXT[99];
			link.l1 = DLG_TEXT[100];
			link.l1.go = "search_danielle_7";
		break;

		case "search_danielle_7":
			Dialog.snd = "voice\SIHA\SIHA024";
			dialog.text = DLG_TEXT[101];
			link.l1 = DLG_TEXT[102];
			link.l1.go = "exit";
			pchar.quest.main_line = "to_rudnik";
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
