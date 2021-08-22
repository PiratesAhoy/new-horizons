//#include "DIALOGS\Antoine Lebretton_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"

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
			Link.l1.go = "node_1";
			NextDiag.TempNode = "Second time";
		break;

		case "node_1":
			dialog.snd = pcharrepphrase("Voice\ANLE\ANLE002", "Voice\ANLE\ANLE003");
			Dialog.text = pcharrepphrase(DLG_TEXT[6] + GetMyFullName(NPChar) + DLG_TEXT[7], DLG_TEXT[8]);
			Link.l1 = pcharrepphrase(DLG_TEXT[9], DLG_TEXT[10]);
			Link.l1.go =  "node_2";
		break;

		case "node_2":
			dialog.snd = pcharrepphrase("Voice\ANLE\ANLE004", "Voice\ANLE\ANLE005");
			Dialog.text = pcharrepphrase(DLG_TEXT[11], DLG_TEXT[12]);
			Link.l1 =pcharrepphrase( DLG_TEXT[13], DLG_TEXT[14]);
			Link.l1.go = "vine";
			link.l2 = pcharrepphrase(DLG_TEXT[15], DLG_TEXT[16]);
			link.l2.go = "exit";
		break;

		case "vine":
			dialog.snd = pcharrepphrase("Voice\ANLE\ANLE006", "Voice\ANLE\ANLE007");
			Dialog.text = pcharrepphrase(DLG_TEXT[17], DLG_TEXT[18]);
			if(makeint(pchar.reputation) >40 && makeint(pchar.money >0))
			{
				link.l1 = DLG_TEXT[19];
				link.l1.go = "rumours";
			}
			if(makeint(pchar.reputation) <41 && makeint(pchar.money >1))
			{
				link.l1 = DLG_TEXT[20];
				link.l1.go = "rumours";
			}
			Link.l2 = pcharrepphrase(DLG_TEXT[21], DLG_TEXT[22]);
			Link.l2.go = "rome";
		break;

		case "rome":
			dialog.snd = pcharrepphrase("Voice\ANLE\ANLE008", "Voice\ANLE\ANLE009");
			Dialog.text = pcharrepphrase(DLG_TEXT[23], DLG_TEXT[24]);
			if (makeint(pchar.reputation) >40 && makeint(PChar.money) > 0)
			{
				Link.l1 = DLG_TEXT[25];
				Link.l1.go = "rumours";
			}
			if (makeint(pchar.reputation) < 41 && makeint(pchar.money) > 1)
			{
				link.l1 = DLG_TEXT[26];
				link.l1.go = "rumours";
			}
			Link.l1 = pcharrepphrase(DLG_TEXT[27], DLG_TEXT[28]);
			Link.l1.go = "exit";
		break;

		case "rumours":
			if (makeint(pchar.reputation > 40))
			{
				PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneyToCharacter(pchar, -1);
			}
			else
			{
				PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneyToCharacter(pchar, -2);
			}
			dialog.snd = "Voice\ANLE\ANLE010";
			Dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "rumours_1";
			link.l2 = pcharrepphrase(DLG_TEXT[31], DLG_TEXT[32]);
			link.l2.go = "room";
			link.l3 = DLG_TEXT[33];
			link.l3.go = "town";
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
			link.l2 = XI_ConvertString("Until tomorrow") + " " + XI_ConvertString(roomWait) + ".";
			link.l2.go = "room_24";
		break;

		case "room_24":
			dialog.snd = "Voice\ANLE\ANLE014";
			Dialog.text = DLG_TEXT[41];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[42];
				link.l1.go = "room_24_wait";
			}
			link.l2 = pcharrepphrase(DLG_TEXT[43], DLG_TEXT[44]);
			link.l2.go = "hall_24_wait";
			link.l3 = DLG_TEXT[45];
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

		case "rumours_good":
			Dialog.text = SelectRumour(FindIslandByLocation(LoadedLocation.id), GetNationIDByType(GetCurrentLocationNation()) ); // KK
			Link.l1 = DLG_TEXT[51];
			link.l1.go = "rumours_1";
			link.l2 = DLG_TEXT[52];
			link.l2.go = "town";
			link.l3 = DLG_TEXT[53];
			link.l3.go = "crew";
//Lucas
			if (CheckQuestAttribute("lucas", "search"))
			{
				dialog.snd = "Voice\CHWI\CHWI005";
				Link.l4 = DLG_TEXT[279];
				Link.l4.go = "Find_Lucas1";
			}
//Lucas
		break;

		case "town":
			Link.l2 = DLG_TEXT[54];
			Link.l2.go = "store";
			Link.l3 = DLG_TEXT[55];
			Link.l3.go = "shipyard";
		break;

		case "rumours_1":
			iTest = 0;
			dialog.snd = "Voice\ANLE\ANLE015";
			Dialog.text = DLG_TEXT[56] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[57];
			if (iTest < QUEST_COUNTER)
			{
				Link.l98 = DLG_TEXT[78];
				Link.l98.go = "rumours_good";
				iTest = iTest + 1;
			}
			if ((characters[GetCharacterIndex("Thierry Bosquet")].quest.gambling == "1")&&(iTest < QUEST_COUNTER))
			{
				link.l1 = DLG_TEXT[58];
				link.l1.go = "bukaner";
				iTest = iTest + 1;
			}
			if ((Characters[GetCharacterIndex("Patric Cardone")].quest.teodoro =="1")&&(iTest < QUEST_COUNTER))
			{
				Link.l2 = DLG_TEXT[59] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[60])]) + DLG_TEXT[62];
				Link.l2.go = "Teodoro";
				iTest = iTest + 1;
			}
			if ((characters[GetCharacterIndex("Turpin Cabanel")].quest.smugglers == "2")&&(iTest < QUEST_COUNTER))
			{
				link.l3 = DLG_TEXT[63];
				link.l3.go = "smugglers";
				iTest = iTest + 1;
			}
			if ((characters[GetCharacterIndex("Baldewyn Coffier")].quest.hire == "question_1")&&(iTest < QUEST_COUNTER))
			{
				link.l4 = DLG_TEXT[64] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[65])]) + DLG_TEXT[67];
				link.l4.go = "baldewyn_1";
				iTest = iTest + 1;
			}
			if ((characters[GetCharacterIndex("Turpin Cabanel")].quest.smugglers == "teodoro")&&(iTest < QUEST_COUNTER))
			{
				link.l5 = DLG_TEXT[68];
				link.l5.go = "smugglers_3";
				iTest = iTest + 1;
			}
//Lucas
			if (CheckQuestAttribute("lucas", "search"))
			{
				dialog.snd = "Voice\CHWI\CHWI005";
				Link.l6 = DLG_TEXT[279];
				Link.l6.go = "Find_Lucas1";
			}
//Lucas
			if (!CheckQuestAttribute("generate_convoy_quest_progress", "begin") && npchar.work != lastspeak_date)
			{
				link.l10 = DLG_TEXT[79];
				link.l10.go = "convoy";
			}
			Link.l99 = DLG_TEXT[80];
			Link.l99.go = "exit";
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

		case "baldewyn_1":
			dialog.snd = "Voice\ANLE\ANLE021";
			dialog.text = DLG_TEXT[109] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[110] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[111])]) + DLG_TEXT[112];
			link.l1 = DLG_TEXT[113];
			link.l1.go = "baldewyn_2";
		break;

		case "baldewyn_2":
			if (pchar.reputation > 40)
			{
				dialog.snd = "Voice\ANLE\ANLE022";
				dialog.text = DLG_TEXT[114] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[115] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[116])]) + DLG_TEXT[117];
				link.l1 = DLG_TEXT[118];
				link.l1.go = "exit";
				characters[GetCharacterIndex("Baldewyn Coffier")].quest.hire = "question_1_done";
			}
			else
			{
				dialog.snd = "Voice\ANLE\ANLE023";
				dialog.text = DLG_TEXT[119] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[120])]) + DLG_TEXT[121];
				link.l1 = DLG_TEXT[122];
				link.l1.go = "baldewyn_3";
				link.l2 = DLG_TEXT[123];
				link.l2.go = "baldewyn_4";
			}
		break;

		case "baldewyn_3":
			dialog.snd = "Voice\ANLE\ANLE024";
			dialog.text = DLG_TEXT[124];
			link.l1 = DLG_TEXT[125];
			link.l1.go = "exit";
			characters[GetCharacterIndex("baldewyn Coffier")].quest.hire = "question_1_done";
		break;

		case "baldewyn_4":
			dialog.snd = "Voice\ANLE\ANLE025";
			Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
			dialog.text = DLG_TEXT[126] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[127];
			link.l1 = DLG_TEXT[128];
			link.l1.go = "exit";
			characters[GetCharacterIndex("Baldewyn Coffier")].quest.hire = "question_1_not_done";
		break;

		case "teodoro":
			dialog.snd = "Voice\ANLE\ANLE028";
			Dialog.Text = DLG_TEXT[135];
			Link.l1 = DLG_TEXT[136];
			Link.l1.go = "exit";
			if (makeint(Pchar.money) > 0)
			{
				Link.l2 = DLG_TEXT[137];
				Link.l2.go = "teodoro1";
			}
		break;

		case "teodoro1":
			dialog.snd = "Voice\ANLE\ANLE029";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -1);
			Dialog.text = DLG_TEXT[138];
			link.l1 = DLG_TEXT[139];
			link.l1.go = "teodoro2";
		break;

		case "teodoro2":
			dialog.snd = "Voice\ANLE\ANLE030";
			Dialog.text = DLG_TEXT[140];
			Link.l1 = DLG_TEXT[141];
			link.l1.go = "teodoro_3";
		break;

		case "teodoro_3":
			dialog.snd = "Voice\ANLE\ANLE031";
			Dialog.text = DLG_TEXT[142];
			Link.l1 = DLG_TEXT[143];
			link.l1.go = "teodoro_4";
		break;

		case "teodoro_4":
			dialog.snd = "Voice\ANLE\ANLE032";
			Dialog.text = DLG_TEXT[144] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[145])]) + DLG_TEXT[147];
			Link.l1 = DLG_TEXT[148] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[149])]) + DLG_TEXT[151];
			Link.l1.go = "teodoro_5";
		break;

		case "teodoro_5":
			dialog.snd = "Voice\ANLE\ANLE033";
			Dialog.Text = DLG_TEXT[152] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[153];
			Link.l1 = DLG_TEXT[154];
			link.l1.go = "teodoro_6";
			Characters[GetCharacterIndex("Patric Cardone")].quest.teodoro = "4";

			Preprocessor_AddQuestData("Antoine Lebretton", GetMyFullName(NPChar));
			Preprocessor_AddQuestData("Lucien Bescanceny", GetMyFullName(CharacterFromID("Lucien Bescanceny")));
			Preprocessor_AddQuestData("Antoine", GetMyName(NPChar));
			Preprocessor_AddQuestData("Bescanceny", GetMyLastName(CharacterFromID("Lucien Bescanceny")));
			AddQuestRecord("Patric", 4); // NK
			Preprocessor_Remove("Bescanceny");
			Preprocessor_Remove("Antoine");
			Preprocessor_Remove("Lucien Bescanceny");
			Preprocessor_Remove("Antoine Lebretton");
		break;

		case "teodoro_6":
			dialog.snd = "Voice\ANLE\ANLE034";
			Dialog.text = DLG_TEXT[155];
			Link.l1 = DLG_TEXT[156];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[157];
			Link.l2.go = "rumours";
		break;

		case "smugglers":
			dialog.snd = "Voice\ANLE\ANLE037";
			Dialog.text = DLG_TEXT[169];
			link.l1 = DLG_TEXT[170];
			link.l1.go = "smugglers_1";
		break;

		case "smugglers_1":
			dialog.snd = "Voice\ANLE\ANLE038";
			Dialog.text = DLG_TEXT[171] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[172];
			link.l1 = DLG_TEXT[173];
			link.l1.go = "smugglers_2";
		break;

		case "smugglers_2":
			if (pchar.reputation > 40)
			{
				dialog.snd = "Voice\ANLE\ANLE039";
				Dialog.text = DLG_TEXT[174];
				link.l1 = DLG_TEXT[175];
				link.l1.go = "exit";
				characters[GetCharacterIndex("Turpin Cabanel")].quest.smugglers = "find";
			}
			else
			{
				dialog.snd = "Voice\ANLE\ANLE040";
				Dialog.text = DLG_TEXT[176];
				link.l1 = DLG_TEXT[177];
				link.l1.go = "exit";
				characters[GetCharacterIndex("Turpin Cabanel")].quest.smugglers = "search";
			}
		break;

		case "smugglers_3":
			dialog.snd = "Voice\ANLE\ANLE041";
			dialog.text = DLG_TEXT[178] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[179];
			if(Characters[GetCharacterIndex("Patric Cardone")].quest.teodoro == "0")
			dialog.text = DLG_TEXT[178] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[179] + " " + DLG_TEXT[278]; // NK
			link.l1 = DLG_TEXT[180];
			link.l1.go = "exit";
		break;

		case "bukaner":
			dialog.snd = "Voice\ANLE\ANLE042";
			dialog.text = DLG_TEXT[181];
			link.l1 = DLG_TEXT[182];
			link.l1.go = "exit";
			if (makeint(pchar.money) >= 500)
			{
				link.l1 = DLG_TEXT[183];
				link.l1.go = "bukaner_2";
			}
		break;

		case "bukaner_2":
			dialog.snd = "Voice\ANLE\ANLE043";
			dialog.text = DLG_TEXT[184] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[185];
			link.l1 = DLG_TEXT[186];
			link.l1.go = "bukaner_3";
			link.l2 = DLG_TEXT[187];
			link.l2.go = "bukaner_4";
		break;

		case "bukaner_3":
			dialog.snd = "Voice\ANLE\ANLE044";
			dialog.text = DLG_TEXT[188];
			link.l1 = DLG_TEXT[189];
			link.l1.go = "exit";
			characters[GetCharacterIndex("Thierry Bosquet")].quest.gambling = "done_1";
		break;

		case "bukaner_4":
			dialog.snd = "Voice\ANLE\ANLE045";
			dialog.text = DLG_TEXT[190];
			link.l1 = DLG_TEXT[191];
			link.l1.go = "exit";
			characters[GetCharacterIndex("Thierry Bosquet")].quest.gambling = "done_1";
			link.l2 = DLG_TEXT[192];
			link.l2.go = "bukaner_5";
		break;

		case "bukaner_5":
			dialog.snd = "Voice\ANLE\ANLE046";
			dialog.text = DLG_TEXT[193];
			link.l1 = DLG_TEXT[194];
			link.l1.go = "exit";
			characters[GetCharacterIndex("Thierry Bosquet")].quest.gambling = "2";
			AddMoneyToCharacter(pchar, -500);
		break;

		case "store":
			dialog.snd = "Voice\ANLE\ANLE026";
			Dialog.text = DLG_TEXT[129];
			Link.l1 = DLG_TEXT[130];
			Link.l1.go = "rumours_good";
			Link.l2 = DLG_TEXT[131];
			Link.l2.go = "exit";
		break;

		case "shipyard":
			dialog.snd = "Voice\ANLE\ANLE027";
			Dialog.text = DLG_TEXT[132];
			Link.l1 = DLG_TEXT[133];
			Link.l1.go = "rumours_good";
			Link.l2 = DLG_TEXT[134];
			Link.l2.go = "exit";
		break;

		case "Second time":
			dialog.snd = "Voice\ANLE\ANLE035";
			Dialog.text = DLG_TEXT[158] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[159];
			link.l1 = pcharrepphrase(DLG_TEXT[160], DLG_TEXT[161]);
			link.l1.go = "time_2";
			link.l2 = pcharrepphrase(DLG_TEXT[162], DLG_TEXT[163]);
			link.l2.go = "crew";
			link.l3 = pcharrepphrase(DLG_TEXT[164], DLG_TEXT[165]);
			link.l3.go = "room";
			NextDiag.TempNode = "Second time";
		break;

		case "Time_2":
			dialog.snd = "Voice\ANLE\ANLE036";
			Dialog.text = DLG_TEXT[166];
			link.l1 = DLG_TEXT[167];
			link.l1.go = "exit";
			if (makeint(pchar.money > 0))
			{
				link.l2 = DLG_TEXT[168];
				Link.l2.go = "rumours";
			}
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

		case "exit_sit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			AddDialogExitQuest("exit_sit");
		break;

//Lucas
		case "Find_Lucas1":
			dialog.snd = "Voice\CHWI\CHWI016";
			dialog.Text = DLG_TEXT[280];
			Link.l1 = DLG_TEXT[281];
			Link.l1.go = "Find_Lucas2";
		break;

		case "Find_Lucas2":
			dialog.snd = "Voice\CHWI\CHWI017";
			dialog.Text = DLG_TEXT[282];
			Link.l1 = DLG_TEXT[283];
			Link.l1.go = "Find_Lucas3";
		break;

		case "Find_Lucas3":
			dialog.snd = "Voice\CHWI\CHWI018";
			dialog.Text = DLG_TEXT[284];
			Link.l1 = DLG_TEXT[285];
			Link.l1.go = "Find_Lucas4";
		break;

		case "Find_Lucas4":
			dialog.snd = "Voice\CHWI\CHWI019";
			dialog.Text = DLG_TEXT[286];
			Link.l1 = DLG_TEXT[287];
			Link.l1.go = "Find_Lucas_exit";
		break;

		case "Find_Lucas_exit":
			NextDiag.CurrentNode =  NextDiag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();

			AddDialogExitQuest("Lucas_search1");
		break;
//Lucas
	}
}
