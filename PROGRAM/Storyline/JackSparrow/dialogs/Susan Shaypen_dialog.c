//#include "DIALOGS\Susan Shaypen_dialog.h"
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

			Dialog.mood = "normal";
			
			dialog.snd = "Voice\ARSI\ARSI001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";

			if (pchar.quest.Jacks_early_days == "A_spot_of_bother")			
			{
				dialog.snd = "Voice\ARSI\ARSI002";
				dialog.text = DLG_TEXT[2] + GetMyName(Pchar) + DLG_TEXT[3];
				link.l1 = DLG_TEXT[4];
				link.l1.go = "Talk_to_Susan";
			}
			if (checkquestattribute("Jacks_early_days", "Waiting"))
			{
				dialog.snd = "Voice\ARSI\ARSI002";
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "Exit";
			}
			if (checkquestattribute("Jacks_early_days", "xxx"))
			{
				dialog.snd = "Voice\ARSI\ARSI002";
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "Exit";
			}
		break;

		case "Greenford_Tavern":
				dialog.snd = "Voice\ARSI\ARSI002";
				dialog.text = DLG_TEXT[2] + GetMyName(Pchar) + DLG_TEXT[3];
				link.l1 = DLG_TEXT[4];
				link.l1.go = "Talk_to_Susan";
		break;

		case "Talk_to_Susan":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "Talk_to_Susan2";
		break;

		case "Talk_to_Susan2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "Talk_to_Susan3";
		break;		
		
		case "Talk_to_Susan3":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "Exit_Sisters_begin_search";			
		break;
		
		case "Susan_on_Beach":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[11] + GetMyName(Pchar) + DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "Susan_on_Beach2";
		break;		

		case "Susan_on_Beach2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "Susan_on_Beach3";
		break;

		case "Susan_on_Beach3":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "Susan_on_Beach4";
		break;

		case "Susan_on_Beach4":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Susan_on_Beach5";
		break;

		case "Susan_on_Beach5":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Susan_on_Beach6";
		break;

		case "Susan_on_Beach6":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Susan_on_Beach7";
			link.l2 = DLG_TEXT[24];
			link.l2.go = "Not_going_to_help";
		break;

		case "Susan_on_Beach7":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "Susan_on_Beach8";
		break;

		case "Susan_on_Beach8":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "Exit_Susan_on_Beach";
		break;

		case "Not_going_to_help":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Not_going_to_help2";
		break;

		case "Not_going_to_help2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "Not_going_to_help3";
		break;

		case "Not_going_to_help3":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "Exit_Not_going_to_help";
		break;

		case "arrival_at_Tortuga":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "exitTortugaone";				
		break;

		case "discussion_at_Tortuga":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "exitTortugatwo";				
		break;

		case "Susan_on_QC_Dock":
			Change_Mood("angry");
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[39] + GetMyName(Pchar) + DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "Susan_on_QC2";
		break;

		case "Susan_on_QC2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "Susan_on_QC2XX";
		break;		
		
		case "Susan_on_QC2XX":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[44];
			if (CheckCharacterItem(Pchar,"EITC_Passport"))
			{
				link.l1 = DLG_TEXT[55];
				link.l1.go = "become_partners";
			}
			else
			{
				link.l1 = DLG_TEXT[45];
				link.l1.go = "Susan_on_QC3";
			}
		break;

		case "Susan_on_QC3":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "Susan_on_QC4";
		break;

		case "Susan_on_QC4":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "Exit_Susan_on_QC";
		break;

		case "Found_Shaypen":
			Change_Mood("angry");
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[39] + GetMyName(Pchar) + DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "Found_Shaypen2";
		break;

		case "Found_Shaypen2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[52];	
			link.l1 = DLG_TEXT[53];
			link.l1.go = "Found_Shaypen3";
			link.l2 = DLG_TEXT[96];
			link.l2.go = "become_partners";
		break;

		case "Found_Shaypen3":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "Found_Shaypen4";
		break;

		case "Found_Shaypen4":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "Exit_Susan_on_QC";
		break;

		case "become_partners":
			Change_Mood("normal");
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[56];
			link.l1 = DLG_TEXT[57];
			link.l1.go = "become_partners2";
		break;

		case "become_partners2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[58];
			link.l1 = DLG_TEXT[59];
			link.l1.go = "Exit_become_partners";
		break;

		case "Who_is_the_Big_Man":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[60];
			link.l1 = DLG_TEXT[61];
			link.l1.go = "Exit_the_Big_Man";
		break;

		case "Shock_at_being_left":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[62];
			link.l1 = DLG_TEXT[63];
			link.l1.go = "Exit_the_Shock";
		break;

		case "What_are_you_up_to":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[64];
			link.l1 = DLG_TEXT[65];
			link.l1.go = "What_are_you_up_to2";
		break;

		case "What_are_you_up_to2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[66];
			link.l1 = DLG_TEXT[67];
			link.l1.go = "What_are_you_up_to3";
		break;

		case "What_are_you_up_to3":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[68];
			link.l1 = DLG_TEXT[69];
			link.l1.go = "Exit_the_Talk";
		break;

		case "Part_company_for_now":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[70];
			link.l1 = DLG_TEXT[71];
			link.l1.go = "Exit_part_company";
		break;

		case "Part_company_at_Oxbay":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[97];
			link.l1 = DLG_TEXT[98];
			link.l1.go = "Part_company_at_Oxbay2";
		break;

		case "Part_company_at_Oxbay2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[99];
			link.l1 = DLG_TEXT[100];
			link.l1.go = "Exit_part_company_at_Oxbay";
		break;

		case "Different_Islands":
			Change_Mood("angry");
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[72];
			link.l1 = DLG_TEXT[73];
			link.l1.go = "Different_Islands2";
		break;

		case "Different_Islands2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "Different_Islands3";
		break;

		case "Different_Islands3":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[76];
			link.l1 = DLG_TEXT[77];
			link.l1.go = "Different_Islands4";
		break;

		case "Different_Islands4":
			Change_Mood("normal");
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[78];
			link.l1 = DLG_TEXT[79];
			link.l1.go = "Exit_Different_Islands";
		break;

		case "The_Brock_Saga":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[80];
			link.l1 = DLG_TEXT[81];
			link.l1.go = "Exit_Brock_Saga";
		break;

		case "The_Brock_hunt_Oxbay":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[82];
			link.l1 = DLG_TEXT[83];
			link.l1.go = "Exit_Brock_Oxbay";
		break;

		case "I_found_the_Governor":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[84];
			link.l1 = DLG_TEXT[85];
			link.l1.go = "Exit_found_Governor";
		break;

		case "I_found_the_Governor":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[84];
			link.l1 = DLG_TEXT[85];
			link.l1.go = "Exit_found_Governor";
		break;

		case "Joins_the_Governor":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[86];
			link.l1 = DLG_TEXT[87];
			link.l1.go = "Joins_the_Governor2";	
		break;

		case "Joins_the_Governor2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[88];
			link.l1 = DLG_TEXT[89];
			link.l1.go = "Exit_Joins_the_Governor";
		break;

		case "Dead_end_Quest_Oxbay":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[90];
			link.l1 = DLG_TEXT[91];
			link.l1.go = "Dead_end_Quest_Oxbay2";
		break;

		case "Dead_end_Quest_Oxbay2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[92];
			link.l1 = DLG_TEXT[93];
			link.l1.go = "Exit_Dead_end_Quest_Oxbay";
		break;

		case "Wrong_arrival_at_QC":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[94];
			link.l1 = DLG_TEXT[95];
			link.l1.go = "Exit_Wrong_arrival_at_QC";
		break;

		case "Exit_Wrong_arrival_at_QC":
			pchar.quest.Jacks_early_days = "Waiting";
			Dialog.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_Dead_end_Quest_Oxbay":
			pchar.quest.Jacks_early_days = "Waiting";
			AddDialogExitQuest("Dead_end_Quest_Oxbay_onward");
			Dialog.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_Joins_the_Governor":
			Pchar.Quest.On_to_the_Tailors2.over = "yes";
			Pchar.Quest.to_find_a_sister.over = "yes";
			Pchar.Quest.to_find_a_sisterA.over = "yes";
			RemoveOfficersIndex(pchar, GetCharacterIndex("Annabella Brin"));
			RemovePassenger(pchar, characterFromID("Annabella Brin"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Annabella Brinkley"));
			RemovePassenger(pchar, characterFromID("Annabella Brinkley"));
			RemoveCharacterCompanion(pchar, characterFromID("Annabella Brinkley"));
			SetCharacterShipLocation(Pchar, "Oxbay_port");
			if (!CheckCharacterItem(Pchar,"Map_Doc_1"))
			{
				GiveItem2Character(Pchar,"Map_Doc_1");
				AddQuestRecord("Aztec", 10);
			}
			GiveItem2Character(Pchar,"jewelry2");
			GiveItem2Character(Pchar,"jewelry2");
			GiveItem2Character(Pchar,"jewelry2");
			pchar.quest.Jacks_early_days = "Waiting";
			AddDialogExitQuest("My_new_ship_Oxbay");
			Dialog.CurrentNode = "First time";
			DialogExit();
			AddQuestRecord("Mystery Woman",10);
		break;

		case "Exit_found_governor":
			pchar.quest.Jacks_early_days = "Waiting";
			AddDialogExitQuest("Meet_Governor_Brin");
			Dialog.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_Brock_Oxbay":
			pchar.quest.Jacks_early_days = "Waiting";
			AddDialogExitQuest("Brock_found_in_Oxbay");
			Dialog.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_Brock_Saga":
			pchar.quest.Jacks_early_days = "Waiting";
			AddDialogExitQuest("Continue_for_Brock");
			Dialog.CurrentNode = "First time";
			DialogExit();
			AddQuestRecord("Mystery Woman",8);
		break;

		case "Exit_Different_Islands":
			AddDialogExitQuest("What_to_do_next");
			Dialog.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_part_company":
			AddMoneyToCharacter(pchar, +20000);
			pchar.quest.Jacks_early_days = "Waiting";
			AddDialogExitQuest("Jamaica_bound");
			Dialog.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_part_company_at_Oxbay":
			if (!CheckCharacterItem(Pchar,"Map_Doc_1"))
			{
				GiveItem2Character(Pchar,"Map_Doc_1");
				AddQuestRecord("Aztec", 10);
			}
			//GiveItem2Character(Pchar,"Map_Doc_2");
			GiveItem2Character(Pchar,"jewelry2");
			GiveItem2Character(Pchar,"jewelry2");
			pchar.quest.Jacks_early_days = "Waiting";
			AddDialogExitQuest("My_new_ship_Oxbay2");
			AddQuestRecord("Mystery Woman",10);
			Dialog.CurrentNode = "First time";
			DialogExit();
			LAi_ActorGoToLocator(characterFromID("Susan Shaypen"), "reload", "reload1", "", 5.0);
		break;

		case "Exit_the_Talk":
			pchar.quest.Jacks_early_days = "Waiting";
			AddDialogExitQuest("Skull_comes_back");
			Dialog.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_the_Shock":
			AddDialogExitQuest("Skull_joins_in2");
			Dialog.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_the_Big_Man":
			AddDialogExitQuest("Go_see_Skull");
			Dialog.CurrentNode = "First time";
			DialogExit();
		break;
		
		case "Exit_Sisters_begin_search":		
			DisableFastTravel(false);					
			AddDialogExitQuest("Is_this_a_sidetrack");		
			Dialog.CurrentNode = "First time";		
			DialogExit();
		break;

		case "ExitTortugaone":		
			DisableFastTravel(false);					
			AddDialogExitQuest("Looking_for_Brinkley");		
			Dialog.CurrentNode = "First time";		
			DialogExit();
		break;		

		case "ExitTortugatwo":							
			AddDialogExitQuest("Meet_Bootstrap_Bill");		
			Dialog.CurrentNode = "First time";		
			DialogExit();
		break;

		case "Exit_Susan_on_QC":
			pchar.quest.Jacks_early_days = "Ines_Diaz_Discussion";
			AddDialogExitQuest("Swordfight_on_Dock");		
			Dialog.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_become_partners":
			AddPassenger(Pchar, characterFromID("Susan Shaypen"), 0);
			SetOfficersIndex(Pchar, 3, getCharacterIndex("Susan Shaypen"));
			LAi_SetOfficerType(characterFromID("Susan Shaypen"));
			/*Pchar.quest.On_the_trail.win_condition.l1 = "location";
			PChar.quest.On_the_trail.win_condition.l1.character = Pchar.id;
			Pchar.quest.On_the_trail.win_condition.l1.location = "QC_Tavern";
			Pchar.quest.On_the_trail.win_condition = "On_the_trail";*/
			pchar.quest.Susan_Shaypen_Quests = "Ines_Diaz_with_Susan";
			Dialog.CurrentNode = "First time";		
			DisableFastTravel(false);

			DialogExit();
		break;
		
		case "Exit_Susan_on_Beach":
			AddPassenger(Pchar, characterFromID("Susan Shaypen"), 0);			
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Susan Shaypen"));
			LAi_SetOfficerType(characterFromID("Susan Shaypen"));		
			pchar.quest.Jacks_early_days = "xxx";		
			DisableFastTravel(false);		
			AddQuestRecord("My Early Days","7");			
			AddDialogExitQuest("Working_with_Susan");		
			Dialog.CurrentNode = "First time";		
			DialogExit();
		break;

		case "Exit_Not_going_to_help":					
			AddDialogExitQuest("Not_going_to_help_Susan");		
			Dialog.CurrentNode = "First time";		
			DialogExit();
		break;
		
		case "Exit":	
			Dialog.CurrentNode = "First time";		
			DialogExit();
		break;

		
	}
}

