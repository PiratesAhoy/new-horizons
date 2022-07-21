//#include "DIALOGS\Davy Jones_dialog.h"

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

			if (pchar.quest.main_line == "speak_with_peasant")
			{
				Pchar.quest.Open_the_Grotto.win_condition.l1 = "item";
				PChar.quest.Open_the_Grotto.win_condition.l1.item = "Map_Doc_1";
				Pchar.quest.Open_the_Grotto.win_condition.l2 = "item";
				Pchar.quest.Open_the_Grotto.win_condition.l2.item = "Map_Doc_2";
				Pchar.quest.Open_the_Grotto.win_condition.l3 = "item";
				Pchar.quest.Open_the_Grotto.win_condition.l3.item = "Map_Doc_3";
				Pchar.quest.Open_the_Grotto.win_condition.l4 = "item";
				Pchar.quest.Open_the_Grotto.win_condition.l4.item = "Map_Doc_4";
				Pchar.quest.Open_the_Grotto.win_condition = "Open_the_Grotto";
				if (GetAttribute(pchar, "davy") == "helped")
				{
					Dialog.snd = "voice\PEDI\PEDI002";
					Dialog.Text = DLG_TEXT[61];
					Link.l1 = DLG_TEXT[62];
					Link.l1.go = "DavyJoneshelp";
					setCharacterShipLocation(pchar, "Oxbay_shore_01");
				}
				else
				{
					Dialog.snd = "voice\PEDI\PEDI002";
					Dialog.Text = DLG_TEXT[35];
					Link.l1 = DLG_TEXT[36];
					Link.l1.go = "ForDavyJones";
				}
				pchar.quest.main_line = "no_davy";
			}
			else
			{
				if (GetAttribute(PChar, "Jack") == "Pirate" || GetAttribute(PChar, "Jack") == "Pirate_Lord")
				{
					dialog.text = DLG_TEXT[65];
					link.l1 = DLG_TEXT[66]
				}
				else
				{
					dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1] + GetMyFullName(PChar) + ".";
				}
				link.l1.go = "begin_1";
			}
			break;
			
		case "begin_1":
			dialog.snd = "Voice\CLLA\CLLA004";
			if (GetAttribute(PChar, "Jack") == "Pirate" || GetAttribute(PChar, "Jack") == "Pirate_Lord")
			{
				dialog.text = DLG_TEXT[67];
				link.l1 = DLG_TEXT[68]
			}
			else
			{
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
			}
			link.l1.go = "begin_2";
			break;
			
		case "begin_2":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "begin_3";
			break;

		case "begin_3":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "begin_4";
			break;

		case "begin_3":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "begin_4";
			break;

		case "begin_4":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "begin_5";
			break;

		case "begin_5":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "begin_6";
			break;

		case "begin_6":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "begin_7";
			break;

		case "begin_7":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "begin_8";
			break;

		case "begin_8":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "begin_9";
			break;

		case "begin_9":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "begin_10";
			break;

		case "begin_10":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "begin_11";
			LAi_ActorAnimation(characterFromID("Davy Jones"), "Ground_sitting", "", "");
			LAi_ActorAnimation(Pchar, "Ground_sitting", "", "");
			break;

		case "begin_11":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "begin_12";
			break;

		case "begin_12":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "begin_13";
			break;

		case "begin_13":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "exit";
			AddDialogExitQuest("davy_leave");
			break;

		case "begin_14":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "begin_15";
			break;

		case "begin_15":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "exit";
			AddDialogExitQuest("pushdavy");
			break;

		case "begin_16":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "begin_17";
			break;

		case "begin_17":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[34] + GetMyFullName(PChar) + " !";
			link.l1.go = "exit";
			AddDialogExitQuest("Davyshootsme");
			break;
			
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			break;
			
		case "ForDavyJones":
			GiveModel2Player("Jack", true);
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "ForDavyJones2";
			break;

		case "ForDavyJones2":
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "ForDavyJones3";
			break;

		case "ForDavyJones3":
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "ForDavyJones4";
			break;

		case "ForDavyJones4":
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "ForDavyJones5";
			break;

		case "ForDavyJones5":
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "ForDavyJones6";
			link.l2 = DLG_TEXT[47];
			link.l2.go = "ForDavyJones8";
			break;

		case "ForDavyJones6":
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "ForDavyJones7";
			break;

		case "ForDavyJones7":
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "ForDavyJones9";
			SetShipRemovable(pchar, true);
			if (PreprocessText("#scursed_ship#") == "Black Pearl")
				GiveShip2Character(pchar,"UncursedPearl",PreprocessText("#scursed_ship#"),-1,PIRATE,true,true);
			else
				GiveShip2Character(pchar,"CrimsonBlood", PreprocessText("#scursed_ship#"),-1,PIRATE,true,true);
			HoistFlag(PIRATE);
			if (PChar.location == "Oxbay_shore_01")
			{
				SetCharacterShipLocation(Pchar, "Oxbay_shore_01");
				EnableEquip(pchar, BLADE_ITEM_TYPE, true);
				EnableEquip(pchar, GUN_ITEM_TYPE, true);
				EquipCharacterByItem(pchar, FindCharacterItemByGroup(pchar, BLADE_ITEM_TYPE));
				EquipCharacterByItem(pchar, FindCharacterItemByGroup(pchar, GUN_ITEM_TYPE));
				AddCharacterGoods(pchar, GOOD_WHEAT, 70);
				AddCharacterGoods(pchar, GOOD_RUM, 35);
				AddMoneyToCharacter(pchar, 5000);
				SetNextWeather("Heavy Fog"); // PB
			}
			break;

		case "ForDavyJones8":
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "ForDavyJones10";
			SetShipRemovable(pchar, true);
			GiveShip2Character(pchar, "Tartane1", "What Luck",-1,ENGLAND,true,true);
			SetCharacterShipLocation(pchar, "Oxbay_shore_01");
			EnableEquip(pchar, BLADE_ITEM_TYPE, true);
			EnableEquip(pchar, GUN_ITEM_TYPE, true);
			EquipCharacterByItem(pchar, FindCharacterItemByGroup(pchar, BLADE_ITEM_TYPE));
			EquipCharacterByItem(pchar, FindCharacterItemByGroup(pchar, GUN_ITEM_TYPE));
			AddCharacterGoods(pchar, GOOD_WHEAT, 2);
			AddCharacterGoods(pchar, GOOD_RUM, 2);
			AddMoneyToCharacter(pchar, 100);
			SetNextWeather("Heavy Fog"); // PB
			break;

		case "ForDavyJones9":
			SetQuestHeader("Davy Jones");
			AddQuestRecord("Davy Jones",1);
			DialogExit();
			NextDiag.CurrentNode = "ForDavyJones12";
			AddDialogExitQuest("Find_Barbossa_with_Black_Pearl");
			break;

		case "ForDavyJones10":
			SetQuestHeader("Davy Jones");
			AddQuestRecord("Davy Jones",2);
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Find_Davy_for_Black_Pearl");	
			break;

		case "ForDavyJones11":
			dialog.text = DLG_TEXT[69];
			link.l1 = DLG_TEXT[70];
			link.l1.go = "ForDavyJones6";
			break;

		case "ForDavyJones12":
			dialog.text = DLG_TEXT[71];
			link.l1 = DLG_TEXT[72];
			link.l1.go = "Exit";
			break;

		case "Caught_up_after_Cayman":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[54] + GetMyFullName(PChar) + "?";
			link.l1 = DLG_TEXT[55];
			link.l1.go = "exit";

			if(GetAttribute(pchar, "Jack") == "pirate" || GetAttribute(pchar, "Jack") == "Pirate_Lord")
			{
				AddDialogExitQuest("Tia_to_Davy_DMC");
			}
			else
			{
				AddDialogExitQuest("Tia_to_Davy_early");
			}
			break;

		case "Tia_Talk_to_Davy_early2":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[56] + GetMyFullName(PChar) + DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "exit";
			pchar.Davy = "helped";
			AddDialogExitQuest("Tia_to_Davy_early3");
			break;

		case "Tia_Talk_to_Davy_DMC2":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[59] + GetMyFullName(PChar) + "!";
			link.l1 = DLG_TEXT[60];
			link.l1.go = "exit";
			AddDialogExitQuest("Tia_to_Davy_DMC3");
			break;

		case "DavyJonesHelp":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "exit";
			GiveModel2Player("Jack", true);
			SetShipRemovable(pchar, true);
			if (PreprocessText("#scursed_ship#") == "Black Pearl")
				GiveShip2Character(pchar,"UncursedPearl",PreprocessText("#scursed_ship#"),-1,PIRATE,true,true);
			else
				GiveShip2Character(pchar,"CrimsonBlood", PreprocessText("#scursed_ship#"),-1,PIRATE,true,true);
			setCharacterShipLocation(pchar, "Oxbay_shore_01");
			HoistFlag(PIRATE);
			EnableEquip(pchar, BLADE_ITEM_TYPE, true);
			EnableEquip(pchar, GUN_ITEM_TYPE, true);
			EquipCharacterByItem(pchar, FindCharacterItemByGroup(pchar, BLADE_ITEM_TYPE));
			EquipCharacterByItem(pchar, FindCharacterItemByGroup(pchar, GUN_ITEM_TYPE));
			AddCharacterGoods(pchar, GOOD_WHEAT, 70);
			AddCharacterGoods(pchar, GOOD_RUM, 35);
			AddMoneyToCharacter(pchar, 5000);

			SetQuestHeader("Davy Jones");
			AddQuestRecord("Davy Jones",3);
			AddDialogExitQuest("Find_Barbossa_with_Black_Pearl");
			break;
			
			case "Davy_talk_shipwreck1":
			//PlaySound("VOICE\ENGLISH\DavyJones1.wav");
			dialog.text = DLG_TEXT[73];
			link.l1.go = "Davy_talk_shipwreck1_2";
			break;
			
			case "Davy_talk_shipwreck1_2":
			dialog.text = DLG_TEXT[74];
			link.l1.go = "exit";
			AddDialogExitQuest("Sailor_2_to_davy");
			break;
			
			case "Davy_talk_shipwreck1_sail2":
			dialog.text = DLG_TEXT[75];
			link.l1.go = "exit";
			AddDialogExitQuest("Sailor_2_to_davy_2");
			break;
			
			// To the depths.
			case "Davy_talk_shipwreck1_sail2_2":
			dialog.text = DLG_TEXT[76];
			link.l1.go = "exit";
			AddDialogExitQuest("Davy_talk_Sailor_2_kill");
			break;
			
			// Life is cruel. Why should the afterlife be any different?
			case "Davy_talk_shipwreck1_sail1_2":
			dialog.text = DLG_TEXT[77];
			link.l1.go = "Davy_talk_shipwreck1_sail1_3";
			break;
			
			// Will you serve
			case "Davy_talk_shipwreck1_sail1_3":
			dialog.text = DLG_TEXT[78];
			link.l1.go = "exit";
			AddDialogExitQuest("Davy_talk_Sailor_1_4");
			break;
			
			case "Davy_talk_will":
			dialog.text = DLG_TEXT[79];
			link.l1 = DLG_TEXT[80];
			link.l1.go = "Davy_talk_will_2";
			break;
			
			case "Davy_talk_will_2":
			dialog.text = DLG_TEXT[81];
			link.l1 = DLG_TEXT[82];
			link.l1.go = "Davy_talk_will_3";
			break;
			
			case "Davy_talk_will_3":
			dialog.text = DLG_TEXT[83];
			link.l1.go = "exit";
			AddDialogExitQuest("Video_to_deck_from_shipw");
			break;
			
			case "Davy_to_jack_deck":
			dialog.text = DLG_TEXT[84];
			link.l1 = DLG_TEXT[85];
			link.l1.go = "Davy_to_jack_deck2";
			break;
			
			case "Davy_to_jack_deck2":
			dialog.text = DLG_TEXT[86];
			link.l1 = DLG_TEXT[87];
			link.l1.go = "Davy_to_jack_deck3";
			break;
			
			case "Davy_to_jack_deck3":
			dialog.text = DLG_TEXT[88];
			link.l1 = DLG_TEXT[89];
			link.l1.go = "Davy_to_jack_deck4";
			break;
			
			case "Davy_to_jack_deck4":
			dialog.text = DLG_TEXT[90];
			link.l1 = DLG_TEXT[91];
			link.l1.go = "Davy_to_jack_deck5";
			break;
			
			case "Davy_to_jack_deck5":
			dialog.text = DLG_TEXT[92];
			link.l1 = DLG_TEXT[93];
			link.l1.go = "Davy_to_jack_deck6";
			break;
			
			case "Davy_to_jack_deck6":
			dialog.text = DLG_TEXT[94];
			link.l1 = DLG_TEXT[95];
			link.l1.go = "Davy_to_jack_deck7";
			break;
			
			case "Davy_to_jack_deck7":
			dialog.text = DLG_TEXT[96];
			link.l1 = DLG_TEXT[97];
			link.l1.go = "Davy_to_jack_deck8";
			break;
			
			case "Davy_to_jack_deck8":
			dialog.text = DLG_TEXT[98];
			link.l1 = DLG_TEXT[99];
			link.l1.go = "exit";
			AddDialogExitQuest("Sparrow_gibbs_after_shipw");
			break;
			
	}
}
