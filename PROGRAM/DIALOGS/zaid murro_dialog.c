//#include "DIALOGS\zaid murro_dialog.h"
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
	int iTest;

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
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			if (npchar.quest.meeting == "0")
			{
				Dialog.snd = "voice\ZAMU\ZAMU001";
				Dialog.Text = TimeGreeting() + DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1];
			}
			else
			{
				Dialog.snd = "voice\ZAMU\ZAMU002";
				Dialog.Text = TimeGreeting() + DLG_TEXT[2] + GetMyName(Pchar) + DLG_TEXT[3];
			}
			Link.l1 = pcharrepphrase(DLG_TEXT[4], DLG_TEXT[5]);
			if (npchar.quest.meeting == "0")
			{
				Link.l1.go = "node_1"; 
			}
			else
			{
				Link.l1.go = "node_4"; 
			}
			link.l2 = pcharrepphrase(DLG_TEXT[6], DLG_TEXT[7]);
			link.l2.go = "exit";
			NextDiag.TempNode = "First time";
		break;

		case "node_1":
			Dialog.snd = "voice\ZAMU\ZAMU003";
			dialog.text = DLG_TEXT[8];
			link.l1 = pcharrepphrase(DLG_TEXT[9] + GetMyName(Pchar) + DLG_TEXT[10] + GetMyShipNameShow(PChar) + DLG_TEXT[11], DLG_TEXT[12] + GetMyName(Pchar) + DLG_TEXT[13] + GetMyShipNameShow(PChar) + DLG_TEXT[14]);
			link.l1.go = "node_2";
			link.l2 = pcharrepphrase(DLG_TEXT[15], DLG_TEXT[16]);
			link.l2.go = "exit";
		break;

		case "node_2":
			Dialog.snd = "voice\ZAMU\ZAMU004";
			dialog.text = DLG_TEXT[17];
			link.l1 = pcharrepphrase(DLG_TEXT[18], DLG_TEXT[19]);
			link.l1.go = "node_3";
			npchar.quest.meeting = "1";
		break;

		case "node_3":
			Dialog.snd = "voice\ZAMU\ZAMU005";
			dialog.text = DLG_TEXT[20] + GetMyFullName(NPChar) + DLG_TEXT[21];
			link.l1 = pcharrepphrase(DLG_TEXT[22] + GetMyName(NPChar) + DLG_TEXT[23], DLG_TEXT[24]);
			link.l1.go = "node_4";
			link.l2 = pcharrepphrase(DLG_TEXT[25], DLG_TEXT[26]);
			link.l2.go = "exit";
		break;

		case "node_4":
			Dialog.snd = "voice\ZAMU\ZAMU006";
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "rumours";
			link.l2 = DLG_TEXT[29];
			link.l2.go = "quests";
		break;

		case "rumours":
			if (characters[GetCharacterIndex("Claire Larrouse")].quest.goldmine == "0")
			{
				Dialog.snd = "voice\ZAMU\ZAMU007";
				dialog.text = DLG_TEXT[30] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[31])]) + DLG_TEXT[33];
				link.l1 = DLG_TEXT[34];
				link.l1.go = "clair_1";
				link.l2 = DLG_TEXT[35];
				link.l2.go = "quests";
				link.l3 = DLG_TEXT[36];
				link.l3.go = "exit";
			}
			else
			{
				dialog.text = SelectRumour(FindIslandByLocation(LoadedLocation.id), GetNationIDByType(GetCurrentLocationNation()) );
				link.l1 = pcharrepphrase(DLG_TEXT[37], DLG_TEXT[38]);
				link.l1.go = "exit";
				link.l2 = pcharrepphrase(DLG_TEXT[39], DLG_TEXT[40] + GetMyName(NPChar) + DLG_TEXT[41]);
				link.l2.go = "quests";
			}
		break;

		case "clair_1":
			Dialog.snd = "voice\ZAMU\ZAMU008";
			dialog.text = DLG_TEXT[42];
			link.l1 = pcharrepphrase(DLG_TEXT[43], DLG_TEXT[44]);
			link.l1.go = "clair_2";
		break;

		case "clair_2":
			Dialog.snd = "voice\ZAMU\ZAMU009";
			dialog.text = DLG_TEXT[45];
			link.l1 = pcharrepphrase(DLG_TEXT[46], DLG_TEXT[47]);
			link.l1.go = "quests";
			link.l2 = pcharrepphrase(DLG_TEXT[48], DLG_TEXT[49]);
			link.l2.go = "exit";
			characters[GetCharacterIndex("Claire Larrouse")].quest.goldmine = "1";
		break;

		case "quests":
			iTest = 0;
			Dialog.snd = "voice\ZAMU\ZAMU010";
			Dialog.text = DLG_TEXT[50];
			//////////////////////////////
			// Выдача квестов
			//////////////////////////////
			if (npchar.quest_begin == "0")
			{
				if (characters[GetCharacterIndex("Vigila Mendes")].quest.escort == "0")
				{
					link.l1 = pcharrepphrase(DLG_TEXT[51], DLG_TEXT[52]);
					link.l1.go = "escort_1";
				}
				if ((characters[GetCharacterIndex("Vigila Mendes")].quest.escort == "done")&&(npchar.quest.end_escort == "0"))
				{
					link.l1 = pcharrepphrase(DLG_TEXT[53], DLG_TEXT[54]);
					link.l1.go = "end_escort_1";
					npchar.quest.end_escort = "done";
				}
				if ((npchar.quest.bandits == "0")&&(npchar.quest.end_escort == "done"))
				{
					link.l1 = pcharrepphrase(DLG_TEXT[55], DLG_TEXT[56]);
					link.l1.go = "bandits_1";
				}
				if (npchar.quest.bandits == "1")
				{
					link.l1 = pcharrepphrase(DLG_TEXT[57], DLG_TEXT[58]);
					link.l1.go = "bandits_01";
				}
				if (npchar.quest.bandits == "2")
				{
					link.l1 = DLG_TEXT[59];
					link.l1.go = "exit";
				}
				if (npchar.quest.bandits == "3")
				{
					link.l1 = DLG_TEXT[60];
					link.l1.go = "bandits_over";
				}
			}
			Link.l99 = DLG_TEXT[61];
			Link.l99.go = "exit";
		break;

		case "bandits_over":
			Dialog.snd = "voice\ZAMU\ZAMU011";
			dialog.text = DLG_TEXT[62];
			link.l1 = DLG_TEXT[63];
			link.l1.go = "exit";
			npchar.quest.bandits = "done";
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1800);
				AddPartyExpChar(pchar, "Sneak", 18);
			}
			else { AddPartyExp(pchar, 1800); }
			Officersreaction("good");
			ChangeCharacterReputation(pchar, 2);
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(pchar, 800);
			// Julian -->
			GiveItem2Character(Pchar,"spyglass3");
			Log_SetStringToLog(GlobalStringConvert("QUEST_MESSAGE13"));
			// Julian <--
			CloseQuestHeader("murro"); // NK
			npchar.location = "none";
		break;

		case "bandits_01":
			Dialog.snd = "voice\ZAMU\ZAMU012";
			dialog.text = DLG_TEXT[64];
			link.l1 = pcharrepphrase(DLG_TEXT[65], DLG_TEXT[66]);
			link.l1.go = "bandits_4";
			link.l2 = pcharrepphrase(DLG_TEXT[67], DLG_TEXT[68]);
			link.l2.go = "exit"
		break;

		case "bandits_1":
			Dialog.snd = "voice\ZAMU\ZAMU013";
			dialog.text = DLG_TEXT[69];
			link.l1 = DLG_TEXT[70];
			link.l1.go = "bandits_2";
		break;

		case "bandits_2":
			Dialog.snd = "voice\ZAMU\ZAMU014";
			dialog.text = DLG_TEXT[71];
			link.l1 = pcharrepphrase(DLG_TEXT[72], DLG_TEXT[73]);
			link.l1.go = "bandits_3";
		break;

		case "bandits_3":
			Dialog.snd = "voice\ZAMU\ZAMU015";
			dialog.text = DLG_TEXT[74];
			link.l1 = pcharrepphrase(DLG_TEXT[75], DLG_TEXT[76]);
			link.l1.go = "bandits_4";
			link.l2 = pcharrepphrase(DLG_TEXT[77], DLG_TEXT[78]);
			link.l2.go = "exit";
			npchar.quest.bandits = "1";
		break;

		case "bandits_4":
			Dialog.snd = "voice\ZAMU\ZAMU022";
			dialog.text = DLG_TEXT[79];
			link.l1 = pcharrepphrase(DLG_TEXT[80], DLG_TEXT[81]);
			link.l1.go = "exit";
			npchar.quest.bandits = "1"; //NK
			SetQuestHeader("murro"); // NK
			AddQuestrecord("murro", 1);
			pchar.quest.revenge_for_bandits.win_condition.l1 = "location";
			pchar.quest.revenge_for_bandits.win_condition.l1.location = "Muelle_town_exit";
			pchar.quest.revenge_for_bandits.win_condition = "revenge_for_bandits"; //NK fix
		break;

		case "end_escort_1":
			Dialog.snd = "voice\ZAMU\ZAMU016";
			dialog.text = DLG_TEXT[82] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[83];
			link.l1 = DLG_TEXT[84];
			link.l1.go = "end_escort_2";
		break;

		case "end_escort_2":
			Dialog.snd = "voice\ZAMU\ZAMU017";
			dialog.text = DLG_TEXT[85];
			link.l1 = pcharrepphrase(DLG_TEXT[86], DLG_TEXT[87]);
			link.l1.go = "end_escort_3";
		break;

		case "end_escort_3":
			Dialog.snd = "voice\ZAMU\ZAMU018";
			dialog.text = DLG_TEXT[88];
			link.l1 = DLG_TEXT[89];
			link.l1.go = "exit";
			npchar.quest.end_escort = "done";
			AddDialogExitQuest("zaid_to_muelle_town");
		break;

		case "escort_1":
			Dialog.snd = "voice\ZAMU\ZAMU019";
			dialog.text = DLG_TEXT[90];
			link.l1 = pcharrepphrase(DLG_TEXT[91], DLG_TEXT[92]);
			link.l1.go = "escort_2";
		break;

		case "escort_2":
			Dialog.snd = "voice\ZAMU\ZAMU020";
			dialog.text = DLG_TEXT[93];
			link.l1 = pcharrepphrase(DLG_TEXT[94], DLG_TEXT[95]);
			link.l1.go = "escort_3";
		break;

		case "escort_3":
			Dialog.snd = "voice\ZAMU\ZAMU021";
			dialog.text = DLG_TEXT[96];
			link.l1 = pcharrepphrase(DLG_TEXT[97], DLG_TEXT[98]);
			link.l1.go = "exit";
			characters[GetCharacterIndex("Vigila Mendes")].quest.escort = "1";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
