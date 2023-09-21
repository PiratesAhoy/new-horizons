//#include "DIALOGS\Ines Diaz_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	int iTest, iTime, iAddTime, NPC_meeting;

	
	switch(Dialog.CurrentNode)
	{
		// ----------------------------------- Диалог первый - первая встреча
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\INDI\INDI001";
			Dialog.Text = DLG_TEXT[0] + GetMyName(NPChar) + DLG_TEXT[1];
			link.l1 = pcharrepphrase(DLG_TEXT[2] + GetMyName(NPChar) + DLG_TEXT[3], DLG_TEXT[4]);
			link.l1.go = "node_2";
			NextDiag.TempNode = "Second time";
			if (CheckQuestAttribute("Susan_Shaypen_Quests", "Ines_Diaz_with_Susan"))
			{
				dialog.snd = "Voice\INDI\INDI005";
				dialog.text = DLG_TEXT[190] + GetMyFullName(NPChar) + DLG_TEXT[191];
				link.l1 = DLG_TEXT[192] + GetMyFullName(PChar) + DLG_TEXT[193] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[194])]) + ".";
				link.l1.go = "Ines_Diaz_with_Susan1";
			}
		break;

		case "node_2":
			dialog.snd = pcharrepphrase("Voice\INDI\INDI002", "Voice\INDI\INDI003");
			dialog.text = pcharrepphrase(DLG_TEXT[5], DLG_TEXT[6]);
			if (CheckQuestAttribute("Jacks_early_days", "Ines_Diaz_Discussion"))
			{
				link.l1 = DLG_TEXT[7] + GetMyFullName(PChar) + DLG_TEXT[8];
				link.l1.go = "Ines_Diaz_Discussion1";
			}
			else
			{
				link.l1 = pcharrepphrase(DLG_TEXT[7] + GetMyFullName(PChar) + DLG_TEXT[8], DLG_TEXT[9] + GetMyName(NPChar) + DLG_TEXT[10]);
				link.l1.go = "Second time";
			}
		break;

		case "Second time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";

			dialog.snd = "Voice\INDI\INDI004";	

			if (CheckQuestAttribute("Jacks_early_days", "Ines_Diaz_Discussion"))
			{
				dialog.snd = "Voice\INDI\INDI005";
				dialog.text = DLG_TEXT[173];
				link.l1 = DLG_TEXT[174];
				link.l1.go = "Ines_Diaz_Discussion2";
			}
			else
			{
				if (CheckQuestAttribute("Susan_Shaypen_Quests", "Ines_Diaz_with_Susan"))
				{
					dialog.snd = "Voice\INDI\INDI005";
					dialog.text = DLG_TEXT[195] + GetMyFullName(PChar) + DLG_TEXT[196];
					link.l1 = DLG_TEXT[197] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[194])]) + DLG_TEXT[198];
					link.l1.go = "Ines_Diaz_with_Susan1";
				}
				else
				{
					dialog.text = DLG_TEXT[11];
					if(npchar.quest.about == "0")
					{
						link.l1 = DLG_TEXT[12];
						link.l1.go = "about";
					}
					link.l2 = DLG_TEXT[13];
					link.l2.go = "quests";
					link.l3 = DLG_TEXT[14];
					link.l3.go = "crew";
					link.l4 = pcharrepphrase(DLG_TEXT[15], DLG_TEXT[16]);
					link.l4.go = "room";
					if (CheckQuestAttribute("henry_talk", "henry_new_dialog")) // --> Beckett quest by SJG
					{
						link.l5 = DLG_TEXT[170];
						link.l5.go = "Beckett Search";
					}                                                          // <--- Beckett SJG
					link.l99 = DLG_TEXT[17];
					link.l99.go = "exit";
				}
			}
			NextDiag.TempNode = "Second time";
		break;

		case "Ines_Diaz_with_Susan1":
			dialog.snd = "Voice\INDI\INDI005";
			dialog.text = DLG_TEXT[185];
			link.l1 = DLG_TEXT[186];
			link.l1.go = "Ines_Diaz_with_Susan2";
		break;

		case "Ines_Diaz_with_Susan2":
			dialog.snd = "Voice\INDI\INDI005";
			dialog.text = DLG_TEXT[187];
			link.l1 = DLG_TEXT[188];
			link.l1.go = "Exit_With_Susan";
			link.l2 = DLG_TEXT[189];
			link.l2.go = "Exit_Susan_sleep";
		break;
		

		case "RheimsFind_1":
			dialog.snd = "Voice\INDI\INDI005";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "RheimsFind_2";			
		break;

		case "RheimsFind_2":
			dialog.snd = "Voice\INDI\INDI006";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "RheimsFind_3";			
		break;

		case "RheimsFind_3":
			dialog.snd = "Voice\INDI\INDI007";
			dialog.text = DLG_TEXT[22] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[23])]) + DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "exit";
			PChar.quest.RheimsBook = "1";
			AddQuestRecord("Story_Find_Rheims", 111);
		break;

		case "room":
			dialog.snd = "Voice\INDI\INDI008";
			dialog.text = DLG_TEXT[27];
			string roomWait = "";
			if (makeint(environment.time) >= 22.0 || makeint(environment.time) < 10.0)
			{
				roomWait = "eveningwait";
				link.l1 = DLG_TEXT[28];
				link.l1.go = "room_day";
			}
			else
			{
				roomWait = "daywait";
				link.l1 = DLG_TEXT[29];
				link.l1.go = "room_night";
			}
			link.l2 = XI_ConvertString("Until tomorrow") + " " + XI_ConvertString(roomWait) + ".";
			link.l2.go = "room_24";
		break;

		case "room_24":
			dialog.snd = "Voice\ANLE\ANLE014";
			Dialog.text = DLG_TEXT[30];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[31];
				link.l1.go = "room_24_wait";
			}
			link.l2 = pcharrepphrase(DLG_TEXT[32], DLG_TEXT[33]);
			link.l2.go = "hall_24_wait";
			link.l3 = DLG_TEXT[34];
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
			dialog.snd = "Voice\INDI\INDI009";
			Dialog.text = DLG_TEXT[30];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[31];
				link.l1.go = "room_day_wait";
			}
			link.l2 = pcharrepphrase(DLG_TEXT[32], DLG_TEXT[33]);
			link.l2.go = "hall_day_wait";
			link.l3 = DLG_TEXT[34];
			link.l3.go = "second time";
		break;

		case "room_night":
			dialog.snd = "Voice\INDI\INDI010";
			Dialog.text = DLG_TEXT[35];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[36];
				link.l1.go = "room_night_wait";
			}
			link.l2 = pcharrepphrase(DLG_TEXT[37], DLG_TEXT[38]);
			link.l2.go = "hall_night_wait";
			link.l3 = DLG_TEXT[39];
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

		case "about":
			dialog.snd = "Voice\INDI\INDI011";
			dialog.text = DLG_TEXT[40];
			link.l1 = pcharrepphrase(DLG_TEXT[41], DLG_TEXT[42]);
			link.l1.go = "about_2";
		break;

		case "about_2":
			dialog.snd = "Voice\INDI\INDI012";
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "about_3";
		break;

		case "about_3":
			dialog.snd = "Voice\INDI\INDI013";
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "about_4";
			link.l2 = DLG_TEXT[47];
			link.l2.go = "Second time";
		break;

		case "about_4":
			dialog.snd = "Voice\INDI\INDI014";
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "about_5";
			link.l2 = DLG_TEXT[50];
			link.l2.go = "Second time";
		break;

		case "about_5":
			dialog.snd = "Voice\INDI\INDI015";
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "about_6";
			link.l2 = DLG_TEXT[53];
			link.l2.go = "Second time";
		break;

		case "about_6":
			dialog.snd = "Voice\INDI\INDI016";
			dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];
			link.l1.go = "about_7";
			link.l2 = DLG_TEXT[56];
			link.l2.go = "Second time";
		break;

		case "about_7":
			dialog.snd = "Voice\INDI\INDI017";
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "about_8";
			link.l2 = DLG_TEXT[59];
			link.l2.go = "Second time";
		break;

		case "about_8":
			dialog.snd = "Voice\INDI\INDI018";
			dialog.text = DLG_TEXT[60];
			link.l1 = DLG_TEXT[61];
			link.l1.go = "about_9";
			link.l2 = DLG_TEXT[62];
			link.l2.go = "Second time";
		break;

		case "about_9":
			dialog.snd = "Voice\INDI\INDI019";
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "about_10";
			link.l2 = DLG_TEXT[65];
			link.l2.go = "Second time";
		break;

		case "about_10":
			dialog.snd = "Voice\INDI\INDI020";
			dialog.text = DLG_TEXT[66];
			link.l1 = DLG_TEXT[67];
			link.l1.go = "about_11";
			link.l2 = DLG_TEXT[68];
			link.l2.go = "Second time";
		break;

		case "about_11":
			dialog.snd = "Voice\INDI\INDI021";
			dialog.text = DLG_TEXT[69];
			link.l1 = pcharrepphrase(DLG_TEXT[70], DLG_TEXT[71]);
			link.l1.go = "about_12";
			link.l2 = DLG_TEXT[72];
			link.l2.go = "Second time";
		break;

		case "about_12":
			dialog.snd = pcharrepphrase("Voice\INDI\INDI022", "Voice\INDI\INDI023");
			dialog.text = pcharrepphrase(DLG_TEXT[73], DLG_TEXT[74]);
			link.l1 = pcharrepphrase(DLG_TEXT[75], DLG_TEXT[76] + GetMyName(NPChar) + DLG_TEXT[77]);
			link.l1.go = "about_13";
			link.l2 = DLG_TEXT[78];
			link.l2.go = "Second time";
		break;

		case "about_13":
			dialog.snd = "Voice\INDI\INDI024";
			dialog.text = DLG_TEXT[79] + characters[GetcharacterIndex(DLG_TEXT[80])].name  + " " + characters[GetcharacterIndex(DLG_TEXT[81])].lastname + DLG_TEXT[82];
			link.l1 = DLG_TEXT[83] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[84])]) + DLG_TEXT[85];
			link.l1.go = "about_14";
			link.l2 = DLG_TEXT[86];
			link.l2.go = "Second time";
		break;

		case "about_14":
			dialog.snd = "Voice\INDI\INDI025";
			dialog.text = DLG_TEXT[87];
			link.l1 = DLG_TEXT[88];
			link.l1.go = "about_15";
			link.l2 = DLG_TEXT[89];
			link.l2.go = "Second time";
		break;

		case "about_15":
			dialog.snd = "Voice\INDI\INDI026";
			dialog.text = DLG_TEXT[90];
			link.l1 = DLG_TEXT[91];
			link.l1.go = "about_16";
			link.l2 = DLG_TEXT[92];
			link.l2.go = "Second time";
		break;

		case "about_16":
			dialog.snd = "Voice\INDI\INDI027";
			dialog.text = DLG_TEXT[93];
			link.l1 = DLG_TEXT[94];
			link.l1.go = "about_17";
			link.l2 = DLG_TEXT[95];
			link.l2.go = "Second time";
		break;

		case "about_17":
			dialog.snd = "Voice\INDI\INDI028";
			dialog.text = DLG_TEXT[96];
			link.l1 = pcharrepphrase(DLG_TEXT[97], DLG_TEXT[98]);
			link.l1.go = "Second time";
			npchar.quest.about = "1";
		break;

		case "quests":
			iTest = 0;
			dialog.snd = "Voice\INDI\INDI029";
			dialog.text = DLG_TEXT[99];
			//Разговор Блейза
			if (pchar.quest.main_line == "blaze_talk_with_silehard_complete" && iTest < QUEST_COUNTER)
			{
				link.l1 = DLG_TEXT[100] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[101])]) + DLG_TEXT[103];
				link.l1.go = "blaze_search_rheims";
				iTest = iTest + 1;
			}
			if (CheckQuestAttribute("ANIMISTS", "to_qc"))
			{
				link.l1 = DLG_TEXT[104];
				link.l1.go = "ANIMISTS";
				iTest = iTest + 1;
			}
			if (CheckQuestAttribute("estrella_qc", "here"))  // <-- Estrella quest by Cat
			{
				link.l1 = DLG_TEXT[162];
				Link.l1.go = "Estrella_Armand";
				iTest = iTest + 1;
			}  // Estrella quest by Cat <--
			link.l99 = DLG_TEXT[105];
			link.l99.go = "second time";
		break;

		case "ANIMISTS":
			dialog.snd = "Voice\INDI\INDI030";
			dialog.text = DLG_TEXT[106];
			link.l1 = pcharrepphrase(DLG_TEXT[107], DLG_TEXT[108]);
			link.l1.go = "ANIMISTS_1";
		break;

		case "ANIMISTS_1":
			dialog.snd = "Voice\INDI\INDI031";
			dialog.text = DLG_TEXT[109];
			link.l1 = DLG_TEXT[110];
			link.l1.go = "ANIMISTS_2";
		break;

		case "ANIMISTS_2":
			dialog.snd = "Voice\INDI\INDI032";
			dialog.text = DLG_TEXT[111];
			link.l1 = DLG_TEXT[112];
			link.l1.go = "exit";
			AddQuestRecord("Sao Feng", 7);
			pchar.quest.ANIMISTST = "go_to_beach";
			pchar.quest.ANIMISTS = "frigate_lost";
			SetRumourState("Children_GreenChurch", true); // NK
			ChangeCharacterAddressGroup(&characters[GetCharacterIndex("father Gareth")], "Redmond_church", "goto", "goto12");
		break;

		case "blaze_search_rheims":
			dialog.snd = "Voice\INDI\INDI033";
			dialog.text = DLG_TEXT[113];
			if (npchar.quest.rheims == "speak_with_humans")
			{
				link.l1 = DLG_TEXT[114];
				link.l1.go = "blaze_search_rheims_1";
			}
			else
			{
				link.l1 = DLG_TEXT[115];
				link.l1.go = "blaze_search_rheims_7";
			}
		break;

		case "blaze_search_rheims_1":
			dialog.snd = "Voice\INDI\INDI034";
			dialog.text = DLG_TEXT[116];
			link.l1 = DLG_TEXT[117];
			link.l1.go = "blaze_search_rheims_2";
		break;

		case "blaze_search_rheims_2":
			if (makeint(pchar.reputation) > 40 && CalcCharacterSkill(pchar, SKILL_LEADERSHIP) > 4)
			{
				dialog.snd = "Voice\INDI\INDI035";
				dialog.text = DLG_TEXT[118];
				link.l1 = DLG_TEXT[119];
				link.l1.go = "blaze_search_rheims_3";
				link.l2 = DLG_TEXT[120];
				link.l2.go = "blaze_search_rheims_8";
			}
			else
			{
				dialog.snd = "Voice\INDI\INDI036";
				dialog.text = DLG_TEXT[121];
				link.l1 = pcharrepphrase(DLG_TEXT[122], DLG_TEXT[123]);
				link.l1.go = "ines_denied_exit";
			}
		break;

		case "blaze_search_rheims_3":
			dialog.snd = "Voice\INDI\INDI037";
			dialog.text = DLG_TEXT[124];
			link.l1 = DLG_TEXT[125];
			link.l1.go = "blaze_search_rheims_4";
		break;

		case "blaze_search_rheims_4":
			dialog.snd = "Voice\INDI\INDI038";
			dialog.text = DLG_TEXT[126] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[127])]) + DLG_TEXT[128];
			link.l1 = DLG_TEXT[129];
			link.l1.go = "blaze_search_rheims_5";
		break;

		case "blaze_search_rheims_5":
			dialog.snd = "Voice\INDI\INDI039";
			dialog.text = DLG_TEXT[130];
			link.l1 = DLG_TEXT[131];
			link.l1.go = "blaze_search_rheims_6";
		break;

		case "blaze_search_rheims_6":
			dialog.snd = "Voice\INDI\INDI040";
			dialog.text = DLG_TEXT[132];
			link.l1 = DLG_TEXT[133];
			link.l1.go = "exit";
			pchar.quest.main_line = "blaze_talk_with_innes_diaz_complete";
			AddQuestRecord("Blaze_search_Rheims", 2);
		break;

		case "blaze_search_rheims_7":
			dialog.snd = "Voice\INDI\INDI041";
			dialog.text = DLG_TEXT[134];
			link.l1 = DLG_TEXT[135];
			link.l1.go = "ines_denied_exit";
		break;

		case "blaze_search_rheims_8":
			dialog.snd = "Voice\INDI\INDI042";
			dialog.text = DLG_TEXT[136];
			link.l1 = DLG_TEXT[137];
			link.l1.go = "blaze_search_rheims_9";
		break;

		case "blaze_search_rheims_9":
			if (CalcCharacterSkill(pchar, SKILL_LEADERSHIP) > 5)
			{
				dialog.snd = "Voice\INDI\INDI043";
				dialog.text = DLG_TEXT[138];
				link.l1 = DLG_TEXT[139];
				link.l1.go = "blaze_search_rheims_6";
			}
			else
			{
				dialog.snd = "Voice\INDI\INDI044";
				dialog.text = DLG_TEXT[140];
				link.l1 = DLG_TEXT[141];
				link.l1.go = "blaze_search_rheims_10";
			}
		break;

		case "blaze_search_rheims_10":
			dialog.snd = "Voice\INDI\INDI045";
			dialog.text = DLG_TEXT[142];
			link.l1 = DLG_TEXT[143];
			link.l1.go = "ines_denied_exit";
		break;

		case "ines_denied_exit":
			AddQuestRecord("Blaze_search_Rheims", 3);
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			pchar.quest.main_line = "ines_info_denied";
			Locations[FindLocation("QC_town")].reload.l3.disable = 1;
			//включаем квест на мужика, который даст инфу о реймсе.
			pchar.vcskip = true; // NK 04-08
			pchar.quest.ines_denied_exit_from_tavern.win_condition.l1 = "location";
			pchar.quest.ines_denied_exit_from_tavern.win_condition.l1.location = "QC_town";
			pchar.quest.ines_denied_exit_from_tavern.win_condition = "ines_denied_exit_from_tavern_complete";
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
				dialog.snd = "Voice\INDI\INDI046";
				dialog.text = DLG_TEXT[144];
				link.l1 = DLG_TEXT[145];
				link.l1.go = "room";
				link.l2 = DLG_TEXT[146];
				link.l2.go = "second time";
			}
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "room":
			dialog.snd = "Voice\INDI\INDI047";
			dialog.text = DLG_TEXT[147];
			if (makeint(environment.time) >= 22.0 || makeint(environment.time) < 6.0)
			{

				link.l1 = DLG_TEXT[148];
				link.l1.go = "room_day";
			}
			else
			{
				link.l1 = DLG_TEXT[149];
				link.l1.go = "room_night";
			}
		break;

		case "room_day":
			dialog.snd = "Voice\INDI\INDI048";
			Dialog.text = DLG_TEXT[150];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[151];
				link.l1.go = "room_day_wait";
			}
			link.l2 = pcharrepphrase(DLG_TEXT[152], DLG_TEXT[153]);
			link.l2.go = "hall_day_wait";
			link.l3 = DLG_TEXT[154];
			link.l3.go = "second time";
		break;

		case "room_night":
			dialog.snd = "Voice\INDI\INDI049";
			Dialog.text = DLG_TEXT[155];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[156];
				link.l1.go = "room_night_wait";
			}
			link.l2 = pcharrepphrase(DLG_TEXT[157], DLG_TEXT[158]);
			link.l2.go = "hall_night_wait";
			link.l3 = DLG_TEXT[159];
			link.l3.go = "second time";
		break;

		case "room_night_wait":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(pchar, -5);
			AddDialogExitQuest("sleep_in_conceicao_tavern");
			TavernWaitDate("wait_night");
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
			AddDialogExitQuest("sleep_in_conceicao_tavern");
			TavernWaitDate("wait_day");
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
			Dialog.snd = "dialogs\0\009";

			dialog.snd = "Voice\INDI\INDI050";
			dialog.text = DLG_TEXT[160];
			link.l1 = DLG_TEXT[161];
			link.l1.go = "exit_sit";
		break;

		case "exit_sit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			AddDialogExitQuest("exit_sit");
		break;

// SJG --> Beckett search
		case "Beckett search":
			dialog.text = DLG_TEXT[171];
			link.l1 = DLG_TEXT[172];
			link.l1.go = "second time";
		break;
// <-- SJG
		
// <-- Cat		
		case "Estrella_Armand":   
			dialog.snd = "Voice\INDI\INDI041";
			dialog.text = DLG_TEXT[163];
			link.l1 = DLG_TEXT[164];
			link.l1.go = "Estrella_Armand2";
		break;
		
		case "Estrella_Armand2":
			dialog.text = DLG_TEXT[165];
			link.l1 = "Armand Delacroix.";
			link.l1.go = "Estrella_Armand3";
		break;
		
		case "Estrella_Armand3":
			dialog.text = DLG_TEXT[166];
			link.l1 = DLG_TEXT[167];
			link.l1.go = "Estrella_Armand4";
		break;
		
		case "Estrella_Armand4":
			dialog.text = DLG_TEXT[168];
			link.l1 = DLG_TEXT[169];
			link.l1.go = "exit";
		break;
//  Cat <--	
// SJG -->
		case "Ines_Diaz_Discussion1":
			dialog.snd = "Voice\INDI\INDI005";
			dialog.text = DLG_TEXT[173];
			link.l1 = DLG_TEXT[174];
			link.l1.go = "Ines_Diaz_Discussion2";
		break;

		case "Ines_Diaz_Discussion2":
			dialog.text = DLG_TEXT[175];
			link.l1 = DLG_TEXT[176];
			link.l1.go = "InesDiscuss";
		break;

		case "InesDiscuss":
			dialog.text = DLG_TEXT[177];
			link.l1 = DLG_TEXT[178];
			link.l1.go = "InesDiscuss2";
		break;
		
		case "InesDiscuss2":
			dialog.text = DLG_TEXT[179];
			link.l1 = DLG_TEXT[180];
			link.l1.go = "InesDiscuss3";
		break;
		
		case "InesDiscuss3":
			dialog.text = DLG_TEXT[181];
			link.l1 = DLG_TEXT[182];
			link.l1.go = "InesDiscuss4";
		break;

		case "InesDiscuss4":
			dialog.text = DLG_TEXT[183];
			link.l1 = DLG_TEXT[184];
			link.l1.go = "Exit_Discussion";
			if(stf(environment.time)>=22.0 || stf(environment.time)<6.0)
			{
				link.l2 = DLG_TEXT[199];
				link.l2.go = "InesDiscuss4_night";
			}
		break;

		case "InesDiscuss4_night":
			dialog.text = DLG_TEXT[200];
			link.l1 = DLG_TEXT[189];
			link.l1.go = "Exit_Discussion_Night";
			link.l2 = DLG_TEXT[201];
			if (IsBrothelEnabled() && sti(PChar.money)>=50) link.l2 = link.l2 + DLG_TEXT[202];
			else link.l2 = link.l2 + DLG_TEXT[203];
			link.l2.go = "Exit_Discussion";
		break;

		case "Exit_Discussion":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("On_my_own_to_Skull");
		break;

		case "Exit_Discussion_Night":
			if (stf(environment.time) >= 22.0 || stf(environment.time) < 6.0)
			{
				TavernWaitDate("wait_day");
			}
			SetNextWeather("Blue Sky");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("On_my_own_to_Skull");
		break;

		case "Exit_With_Susan":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Susan_to_Skull");
		break;

		case "Exit_Susan_sleep":
			if (stf(environment.time) >= 22.0 || stf(environment.time) < 6.0)
			{
				TavernWaitDate("wait_day");
			}
			SetNextWeather("Blue Sky");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Susan_to_Skull");
		break;
//<-- SJG		
	}
}
