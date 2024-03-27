//#include "DIALOGS\Desmond Ray Beltrop_dialog.h"

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
	
	// DeathDaisy -->
	string PCharDiminutive;
	if(PChar.sex == "woman")
		PCharDiminutive = "girl";
	else
		PCharDiminutive = "boy";
	
	Preprocessor_Add("diminutive", XI_ConvertString(PCharDiminutive));
	// DeathDaisy <--
	
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
			

			NextDiag.TempNode = "first time";
			
			dialog.snd = "Voice\CAMA\CAMA001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			//разговор с блейзом
			if(CheckQuestAttribute("main_line", "blaze_talk_with_beltrop"))
//			if (pchar.quest.main_line == "blaze_talk_with_beltrop")
			// --> SJG
			{
				if(CheckQuestAttribute("henry_talk", "henry_quest_chat2"))
//				if(pchar.quest.henry_talk == "henry_quest_chat2")
				{
					ChangeCharacterAddress(CharacterFromID("Yusuf Rais"),"none", " ");
					ChangeCharacterAddress(CharacterFromID("Barbossa"),"none", " ");

					dialog.snd = "Voice\CAMA\CAMA002";
					dialog.text = DLG_TEXT[2] + DLG_TEXT[257] + DLG_TEXT[4];
					link.l1 = pcharrepphrase(DLG_TEXT[5], DLG_TEXT[6]);
					link.l1.go = "node_2";
				}							
				else
				{
					dialog.snd = "Voice\CAMA\CAMA002";
					Preprocessor_Add("gender", GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false));
					dialog.text = DLG_TEXT[2] + characters[GetCharacterIndex(DLG_TEXT[3])].lastname + DLG_TEXT[4];
					link.l1 = pcharrepphrase(DLG_TEXT[5], DLG_TEXT[6]);
					link.l1.go = "node_2";
				}
				// <-- SJG
			}
		break;
		
		case "node_2":
			dialog.snd = "Voice\CAMA\CAMA003";
			dialog.text = DLG_TEXT[7];
			link.l1 = pcharrepphrase(DLG_TEXT[8], DLG_TEXT[9]);
			link.l1.go = "node_3";
		break;
		
		case "node_3":
			dialog.snd = pcharrepphrase("Voice\CAMA\CAMA004", "Voice\CAMA\CAMA005");
			dialog.text = pcharrepphrase(DLG_TEXT[10], DLG_TEXT[11]);
			link.l1 = DLG_TEXT[12] + characters[GetCharacterIndex(DLG_TEXT[13])].lastname + DLG_TEXT[14];
			link.l1.go = "node_4";
		break;
		
		case "node_4":
			dialog.snd = "Voice\CAMA\CAMA006";
			dialog.text = DLG_TEXT[15] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[16])]) + DLG_TEXT[17];
			link.l1 = pcharrepphrase(DLG_TEXT[18], DLG_TEXT[19]);
			link.l1.go = "node_5";
		break;
		
		case "node_5":
			dialog.snd = "Voice\CAMA\CAMA007";
			dialog.text = DLG_TEXT[20];
			link.l1 = pcharrepphrase(DLG_TEXT[21] + characters[GetCharacterIndex(DLG_TEXT[22])].lastname + DLG_TEXT[23], DLG_TEXT[24]);
			link.l1.go = "node_6";
		break;
		
		case "node_6":
			dialog.snd = "Voice\CAMA\CAMA008";
			dialog.text = DLG_TEXT[25];
			link.l1 = pcharrepphrase(DLG_TEXT[26], DLG_TEXT[27]);
			link.l1.go = "blaze_exit_from_beltrop";
			AddQuestRecord("Blaze_search_Rheims", 7);
		break;

		case "blaze_exit_from_beltrop":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			pchar.quest.main_line = "blaze_talk_with_beltrop_complete";
			Locations[FindLocation("Smugglers_residence")].reload.l1.disable = 0;
			if (GetTime() >= 22.0 || GetTime() < 8.0)
			{
				Locations[FindLocation("Smugglers_Lair")].reload.l6.disable = 0;
			}
			//даем возможность блейзу просто убить стражников
			pchar.quest.kill_guards_in_rheims_house_smugglers.win_condition.l1 = "NPC_Death";
			pchar.quest.kill_guards_in_rheims_house_smugglers.win_condition.l1.character = "Macario Regalo";
			pchar.quest.kill_guards_in_rheims_house_smugglers.win_condition.l2 = "NPC_Death";
			pchar.quest.kill_guards_in_rheims_house_smugglers.win_condition.l2.character = "Evaristo Filho";
			pchar.quest.kill_guards_in_rheims_house_smugglers.win_condition = "kill_guards_in_rheims_house_smugglers_complete";
			//сразу же даем квест на попадание в дом
			pchar.quest.blaze_to_rheims_house_in_smugglers.win_condition.l1 = "location";
			pchar.quest.blaze_to_rheims_house_in_smugglers.win_condition.l1.location = "Rheims_house_in_smugglers";
			pchar.quest.blaze_to_rheims_house_in_smugglers.win_condition = "blaze_to_rheims_house_in_smugglers_complete";
		break;

		case "smuggler_line":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "exit";
			
			if (CheckQuestAttribute("smuggler_line", "to_beltrop"))
			{
				dialog.text = DLG_TEXT[30];
				link.l1 = DLG_TEXT[31];
				link.l1.go = "smuggler_line_1";
			}
			if (CheckQuestAttribute("smuggler_line", "refused"))
			{
				dialog.text = DLG_TEXT[252] + GetMyName(PChar) + DLG_TEXT[253];
				link.l1 = DLG_TEXT[254];
				link.l1.go = "smuggler_line_refused";
			}
			if (CheckQuestAttribute("smuggler_line", "wait_for_change_mind"))
			{
				dialog.text = DLG_TEXT[32];
				link.l1 = DLG_TEXT[33];
				link.l1.go = "first_mission";
				link.l2 = DLG_TEXT[34];
				link.l2.go = "exit";
			}
			if (CheckQuestAttribute("smuggler_line", "first_mission_free_space_off"))
			{
				if (GetSquadronFreeSpace(pchar, GOOD_SANDAL) < 300)
				{
					dialog.text = DLG_TEXT[35];
					link.l1 = DLG_TEXT[36];
					link.l1.go = "exit";
				}
				else
				{
					dialog.text = DLG_TEXT[37];
					link.l1 = DLG_TEXT[38];
					link.l1.go = "first_mission_9";
				}
			}
			if (CheckQuestAttribute("smuggler_line", "first_mission_free_space_off_expired"))
			{
				dialog.text = DLG_TEXT[39] + pchar.name + DLG_TEXT[40];
				link.l1 = DLG_TEXT[41];
				link.l1.go = "first_mission_free_space_off_expired";
			}
			if (CheckQuestAttribute("smuggler_line", "smuggler_line_first_mission_soldiers_arrest_maginot"))
			{
				dialog.text = DLG_TEXT[42];
				link.l1 = DLG_TEXT[43];
				link.l1.go = "smuggler_line_first_mission_soldiers_arrest_maginot";
			}
			if (CheckQuestAttribute("smuggler_line", "second_mission_to_beltrop_with_money_and_with_ring") && makeint(pchar.money)>=10000)
			{
				dialog.text = DLG_TEXT[44];
				link.l1 = DLG_TEXT[45];
				link.l1.go = "second_mission_to_beltrop_with_money_and_with_ring";
			}
			if (CheckQuestAttribute("smuggler_line", "second_mission_return_to_beltrop_after_prison"))
			{
				dialog.text = DLG_TEXT[46];
				link.l1 = DLG_TEXT[47];
				link.l1.go = "second_mission_return_to_beltrop_after_prison";
			}
			if (CheckQuestAttribute("smuggler_line", "second_mission_after_fight_with_killers"))
			{
				dialog.text = DLG_TEXT[48];
				link.l1 = DLG_TEXT[49];
				link.l1.go = "second_mission_after_fight_with_killers";
			}
			if (CheckQuestAttribute("smuggler_line", "second_mission_truth_to_maginot"))
			{
				dialog.text = DLG_TEXT[50];
				link.l1 = DLG_TEXT[51];
				link.l1.go = "second_mission_truth_to_maginot";
			}
			if (CheckQuestAttribute("smuggler_line", "second_mission_after_fight_with_killers_take_money") && makeint(pchar.money)>=10000)
			{
				dialog.text = DLG_TEXT[52];
				link.l1 = DLG_TEXT[53];
				link.l1.go = "second_mission_after_fight_with_killers_take_money";
			}
			if (CheckQuestAttribute("smuggler_line", "third_mission_to_douwesen_expired"))
			{
				dialog.text = DLG_TEXT[54];
				link.l1 = DLG_TEXT[55];
				link.l1.go = "third_mission_to_douwesen_expired";
			}
			if (CheckQuestAttribute("smuggler_line", "third_mission_to_douwesen_shore"))
			{
				dialog.text = DLG_TEXT[56];
				link.l1 = DLG_TEXT[57];
				link.l1.go = "exit";
				AddDialogExitQuest("third_mission_speak_with_pirate_head");
			}
			if (CheckQuestAttribute("smuggler_line", "third_mission_pirate_head_exit_from_shore"))
			{
				dialog.text = DLG_TEXT[58];
				link.l1 = DLG_TEXT[59];
				link.l1.go = "third_mission_pirate_head_exit_from_shore";
			}
			if (CheckQuestAttribute("smuggler_line", "fourth_mission_meet_with_jean_in_tavern_good") || CheckQuestAttribute("smuggler_line", "fourth_mission_ring_completed"))
			{
				dialog.text = DLG_TEXT[60];
				link.l1 = DLG_TEXT[61];
				link.l1.go = "fourth_mission_completed";
			}
			if (CheckQuestAttribute("smuggler_line", "fourth_mission_kill_jean"))
			{
				Preprocessor_Add("Nathaniel", GetMyName(PChar));
				dialog.text = DLG_TEXT[62];
				link.l1 = DLG_TEXT[63];
				link.l1.go = "fourth_mission_kill_jean";
			}
			if (CheckQuestAttribute("smuggler_line", "fourth_mission_ring_france_was_enemy"))
			{
				Preprocessor_Add("Nathaniel", GetMyName(PChar));
				dialog.text = DLG_TEXT[64];
				link.l1 = DLG_TEXT[65];
				link.l1.go = "fourth_mission_kill_jean";
			}
			if (CheckQuestAttribute("smuggler_line", "fourth_mission_with_officer_to_shop_wrong"))
			{
				dialog.text = DLG_TEXT[66];
				link.l1 = DLG_TEXT[67];
				link.l1.go = "fourth_mission_with_officer_to_shop_wrong";
			}
			if (CheckQuestAttribute("smuggler_line", "fourth_mission_return_to_beltrop"))
			{
				dialog.text = DLG_TEXT[68];
				link.l1 = DLG_TEXT[69];
				link.l1.go = "fourth_mission_kill_jean";
			}
			if (CheckQuestAttribute("smuggler_line", "fifth_mission_know_about_betrayer"))
			{
				dialog.text = DLG_TEXT[70];
				link.l1 = DLG_TEXT[71];
				link.l1.go = "fifth_mission_know_about_betrayer";
			}
			if (CheckQuestAttribute("smuggler_line", "fifth_mission_trap_charged"))
			{
				dialog.text = DLG_TEXT[72];
				link.l1 = DLG_TEXT[73];
				if (HasSubstr(GetCharacterShipLocation(PChar), "_port"))
				{
					link.l1.go = "fifth_mission_move_fleet";
				}
				else
				{
					link.l1.go = "exit";
					AddDialogExitQuest("fifth_mission_trap");
				}
			}
			if (CheckQuestAttribute("smuggler_line", "fifth_mission_move_fleet"))
			{
				Preprocessor_Add("Nathaniel", GetMyName(PChar));
				dialog.text = DLG_TEXT[247];
				switch(GetCharacterShipLocation(PChar))
				{
					case "Conceicao_port": link.l1 = DLG_TEXT[248]; break;
					case "Conceicao_shore_01": link.l1 = DLG_TEXT[249]; break;
					case "Conceicao_Shore_03": link.l1 = DLG_TEXT[250]; break;
					case "Conceicao_shore_02": link.l1 = DLG_TEXT[251]; break;
					link.l1 = "I'm at '" + GetCharacterShipLocation(PChar) + "', wherever that is!";
				}
				if (GetCharacterShipLocation(PChar) != "Conceicao_port") AddDialogExitQuest("fifth_mission_trap");
				link.l1.go = "exit";
			}
			if (CheckQuestAttribute("smuggler_line", "trap_completed"))
			{
				dialog.text = DLG_TEXT[74];
				link.l1 = DLG_TEXT[75];
				link.l1.go = "trap_completed_2";
			}
			if (CheckQuestAttribute("smuggler_barrakuda", "died_bad"))
			{
				dialog.text = DLG_TEXT[76];
				link.l1 = DLG_TEXT[77];
				link.l1.go = "trap_completed_2";
			}

			NextDiag.TempNode = "smuggler_line";
		break;

		case "smuggler_line_1":
			dialog.text = DLG_TEXT[78];
			link.l1 = DLG_TEXT[79];
			link.l1.go = "smuggler_line_2";
		break;

		case "smuggler_line_2":
			dialog.text = DLG_TEXT[80];
			link.l1 = DLG_TEXT[81];
			link.l1.go = "first_mission";
			link.l2 = DLG_TEXT[82];
			link.l2.go = "smuggler_line_decline";
		break;

		case "smuggler_line_decline":
			dialog.text = DLG_TEXT[83];
			link.l1 = DLG_TEXT[84];
			link.l1.go = "exit";
			AddDialogExitQuest("smuggler_line_decline");
		break;

		case "smuggler_line_refused":
			dialog.text = DLG_TEXT[255];
			link.l1 = DLG_TEXT[256];
			link.l1.go = "smuggler_line_2";
		break;

		case "first_mission":
			dialog.text = DLG_TEXT[85];
			link.l1 = DLG_TEXT[86];
			link.l1.go = "first_mission_2";
		break;

		case "first_mission_2":
			dialog.text = DLG_TEXT[87];
			link.l1 = DLG_TEXT[88];
			link.l1.go = "first_mission_3";
		break;

		case "first_mission_3":
			dialog.text = DLG_TEXT[89];
			link.l1 = DLG_TEXT[90];
			link.l1.go = "first_mission_4";
		break;

		case "first_mission_4":
			dialog.text = DLG_TEXT[91];
			link.l1 = DLG_TEXT[92];
			link.l1.go = "first_mission_5";
		break;

		case "first_mission_5":
			dialog.text = DLG_TEXT[93] + pchar.name + DLG_TEXT[94];
			link.l1 = DLG_TEXT[95];
			link.l1.go = "first_mission_6";
		break;

		case "first_mission_6":
			dialog.text = DLG_TEXT[96];
			link.l1 = DLG_TEXT[97];			
			link.l1.go = "first_mission_7";
		break;

		case "first_mission_7":
			dialog.text = DLG_TEXT[98];
			link.l1 = DLG_TEXT[99];
			link.l1.go = "first_mission_8";
		break;

		case "first_mission_8":
			if (GetSquadronFreeSpace(pchar, GOOD_SANDAL) < 300)
			{
				dialog.text = DLG_TEXT[100];
				link.l1 = DLG_TEXT[101];
				link.l1.go = "first_mission_free_space_off";
			}
			else
			{
				dialog.text = DLG_TEXT[102];
				link.l1 = DLG_TEXT[103];
				link.l1.go = "first_mission_9";
			}
		break;

		case "first_mission_9":
			dialog.text = DLG_TEXT[104] + GetMyName(PChar) + DLG_TEXT[105];
			link.l1 = DLG_TEXT[106];
			link.l1.go = "first_mission_10";
		break;

		case "first_mission_10":
			dialog.text = DLG_TEXT[107];
			link.l1 = DLG_TEXT[108];
			link.l1.go = "exit";
			AddDialogExitQuest("smuggler_line_first_mission_accept");
		break;

		case "first_mission_free_space_off":
			dialog.text = DLG_TEXT[109];
			link.l1 = DLG_TEXT[110];
			link.l1.go = "exit";
			AddDialogExitQuest("smuggler_line_first_mission_free_space_off");
		break;

		case "first_mission_free_space_off_expired":
			dialog.text = DLG_TEXT[111];
			link.l1 = DLG_TEXT[112];
			link.l1.go = "first_mission_free_space_off_expired_2";
		break;

		case "first_mission_free_space_off_expired_2":
			dialog.text = DLG_TEXT[113];
			link.l1 = DLG_TEXT[114];
			link.l1.go = "first_mission_free_space_off_expired_3";
		break;

		case "first_mission_free_space_off_expired_3":
			dialog.text = DLG_TEXT[115];
			link.l1 = DLG_TEXT[116];
			link.l1.go = "first_mission_free_space_off_expired_4";
		break;

		case "first_mission_free_space_off_expired_4":
			dialog.text = DLG_TEXT[117];
			link.l1 = DLG_TEXT[118];
			link.l2.go = "second_mission";
		break;

		case "smuggler_line_first_mission_soldiers_arrest_maginot":
			dialog.text = DLG_TEXT[119];
			link.l1 = DLG_TEXT[120];
			link.l1.go = "smuggler_line_first_mission_soldiers_arrest_maginot_2";
		break;

		case "smuggler_line_first_mission_soldiers_arrest_maginot_2":
			dialog.text = DLG_TEXT[121];
			link.l1 = DLG_TEXT[122];
			link.l1.go = "smuggler_line_first_mission_soldiers_arrest_maginot_3";
		break;

		case "smuggler_line_first_mission_soldiers_arrest_maginot_3":
			dialog.text = DLG_TEXT[123];
			link.l1 = DLG_TEXT[124];
			link.l1.go = "second_mission";
			AddDialogExitQuest("smuggler_line_first_mission_award");
		break;

		case "second_mission":
			dialog.text = DLG_TEXT[125];
			link.l1 = DLG_TEXT[126];
			link.l1.go = "second_mission_2";
		break;

		case "second_mission_2":
			dialog.text = DLG_TEXT[127];
			link.l1 = DLG_TEXT[128];
			link.l1.go = "second_mission_3";
		break;

		case "second_mission_3":
			dialog.text = DLG_TEXT[129];
			link.l1 = DLG_TEXT[130];
			link.l1.go = "second_mission_4";
		break;

		case "second_mission_4":
			dialog.text = DLG_TEXT[131] + pchar.lastname + DLG_TEXT[132];
			link.l1 = DLG_TEXT[133];
			link.l1.go = "second_mission_5";
		break;

		case "second_mission_5":
			dialog.text = DLG_TEXT[134];
			link.l1 = DLG_TEXT[135];
			link.l1.go = "exit";
			AddDialogExitQuest("smuggler_line_second_mission_accept");
		break;

		case "second_mission_to_beltrop_with_money_and_with_ring":
			dialog.text = DLG_TEXT[136];
			link.l1 = DLG_TEXT[137];
			link.l1.go = "second_mission_to_beltrop_with_money_and_with_ring_2";
		break;

		case "second_mission_to_beltrop_with_money_and_with_ring_2":
			dialog.text = DLG_TEXT[138];
			link.l1 = DLG_TEXT[139];
			link.l1.go = "second_mission_to_beltrop_with_money_and_with_ring_3";
		break;

		case "second_mission_to_beltrop_with_money_and_with_ring_3":
			dialog.text = DLG_TEXT[140];
			link.l1 = DLG_TEXT[141];
			link.l1.go = "third_mission";
			AddDialogExitQuest("second_mission_money_delivered_to_beltrop");
		break;

		case "second_mission_return_to_beltrop_after_prison":
			dialog.text = DLG_TEXT[142];
			link.l1 = DLG_TEXT[143];
			link.l1.go = "second_mission_return_to_beltrop_after_prison_2";
		break;

		case "second_mission_return_to_beltrop_after_prison_2":
			dialog.text = DLG_TEXT[144];
			link.l1 = DLG_TEXT[145];
			link.l1.go = "third_mission";
			AddDialogExitQuest("second_mission_money_not_delivered_to_beltrop");
		break;

		case "second_mission_after_fight_with_killers":
			dialog.text = DLG_TEXT[146];
			link.l1 = DLG_TEXT[147];
			link.l1.go = "second_mission_after_fight_with_killers_2";
		break;

		case "second_mission_after_fight_with_killers_2":
			dialog.text = DLG_TEXT[148];
			link.l1 = DLG_TEXT[149];
			link.l1.go = "third_mission";
			AddDialogExitQuest("second_mission_after_fight_with_killers_return_to_beltrop");
		break;

		case "second_mission_truth_to_maginot":
			dialog.text = DLG_TEXT[150];
			link.l1 = DLG_TEXT[151];
			link.l1.go = "second_mission_truth_to_maginot_2";
		break;

		case "second_mission_truth_to_maginot_2":
			dialog.text = DLG_TEXT[152];
			link.l1 = DLG_TEXT[153];
			link.l1.go = "third_mission";
			AddDialogExitQuest("second_mission_truth_to_maginot_and_say_beltrop");
		break;

		case "second_mission_after_fight_with_killers_take_money":
			dialog.text = DLG_TEXT[154];
			link.l1 = DLG_TEXT[155];
			link.l1.go = "second_mission_after_fight_with_killers_take_money_2";
		break;

		case "second_mission_after_fight_with_killers_take_money_2":
			dialog.text = DLG_TEXT[156];
			link.l1 = DLG_TEXT[157];
			link.l1.go = "third_mission";
			AddDialogExitQuest("second_mission_after_fight_with_killers_return_money");
		break;

		case "third_mission":
			PChar.quest.smuggler_line.QCGov = GetTownGovernorID("Quebradas Costillas");	// May be Isenbrandt Jurcksen or Skull depending on whether you've defeated the Cozumel fleet
			dialog.text = DLG_TEXT[158];
			link.l1 = DLG_TEXT[159];
			link.l1.go = "third_mission_2";
		break;

		case "third_mission_2":
			dialog.text = DLG_TEXT[160] + GetMyFullName(CharacterFromID(PChar.quest.smuggler_line.QCGov)) + DLG_TEXT[162];
			link.l1 = DLG_TEXT[163];
			link.l1.go = "third_mission_3";
		break;

		case "third_mission_3":
			Preprocessor_Add("Nathaniel", GetMyName(PChar));
			dialog.text = DLG_TEXT[164];
			link.l1 = DLG_TEXT[165];
			link.l1.go = "third_mission_4";
		break;

		case "third_mission_4":
			dialog.text = DLG_TEXT[166];
			link.l1 = DLG_TEXT[167];
			link.l1.go = "exit";
			AddDialogExitQuest("third_mission_accept");
		break;

		case "third_mission_to_douwesen_expired":
			if (checkQuestAttribute("smuggler_line.first_mission", "completed") || checkQuestAttribute("smuggler_line.second_mission", "completed"))
			{
				dialog.text = DLG_TEXT[168];
				link.l1 = DLG_TEXT[169];
				link.l1.go = "third_mission_to_douwesen_expired_2";
			}
			else
			{
				dialog.text = DLG_TEXT[170];
				link.l1 = DLG_TEXT[171];
				link.l1.go = "third_mission_to_douwesen_expired_fire_fight";
				link.l2 = DLG_TEXT[172];
				link.l2.go = "third_mission_to_douwesen_expired_fire_without_fight";
			}
		break;

		case "third_mission_to_douwesen_expired_fire_fight":
			dialog.text = DLG_TEXT[173];
			link.l1 = DLG_TEXT[174];
			link.l1.go = "exit";
			AddDialogExitQuest("third_mission_to_douwesen_expired_fire_fight");
		break;

		case "third_mission_to_douwesen_expired_fire_without_fight":
			dialog.text = DLG_TEXT[175];
			link.l1 = DLG_TEXT[176];
			link.l1.go = "exit";
			AddDialogExitQuest("third_mission_to_douwesen_expired_fire_without_fight");
		break;

		case "third_mission_pirate_head_exit_from_shore":
			dialog.text = DLG_TEXT[177];
			link.l1 = DLG_TEXT[178];
			link.l1.go = "third_mission_to_douwesen_expired_2";
			AddDialogExitQuest("third_mission_award");
		break;

		case "third_mission_to_douwesen_expired_2":
			if (checkQuestAttribute("smuggler_line.second_mission", "completed"))
			{
				dialog.text = DLG_TEXT[179];
				link.l1 = DLG_TEXT[180];
				link.l1.go = "fourth_mission";
			}
			else
			{
				dialog.text = DLG_TEXT[181];
				link.l1 = DLG_TEXT[182];
				link.l1.go = "fourth_mission";
			}
		break;

		case "fourth_mission":
			dialog.text = DLG_TEXT[183];
			link.l1 = DLG_TEXT[184];
			link.l1.go = "exit";
			AddDialogExitQuest("fourth_mission_acepted");
		break;

		case "fourth_mission_completed":
			dialog.text = DLG_TEXT[185];
			link.l1 = DLG_TEXT[186];
			link.l1.go = "fifth_mission";
			AddDialogExitQuest("fourth_mission_completed");
		break;

		case "fourth_mission_kill_jean":
			if (checkQuestAttribute("smuggler_line.second_mission", "completed") || checkQuestAttribute("smuggler_line.third_mission", "completed"))
			{
				dialog.text = DLG_TEXT[187];
				link.l1 = DLG_TEXT[188];
				link.l1.go = "fourth_mission_kill_jean_2";
			}
			else
			{
				Preprocessor_Add("Nathaniel", GetMyName(PChar));
				dialog.text = DLG_TEXT[189];
				link.l1 = DLG_TEXT[190];
				link.l1.go = "fourth_mission_kill_jean_fire_fight";
				link.l2 = DLG_TEXT[191];
				link.l2.go = "fourth_mission_kill_jean_fire_without_fight";
			}
		break;

		case "fourth_mission_kill_jean_2":
			dialog.text = DLG_TEXT[192];
			link.l1 = DLG_TEXT[193];
			link.l1.go = "fifth_mission";
			AddDialogExitQuest("fourth_mission_failed");
		break;

		case "fourth_mission_kill_jean_fire_fight":
			dialog.text = DLG_TEXT[194];
			link.l1 = DLG_TEXT[195];
			link.l1.go = "exit";
			AddDialogExitQuest("fourth_mission_kill_jean_fire_fight");
		break;

		case "fourth_mission_kill_jean_fire_without_fight":
			dialog.text = DLG_TEXT[196];
			link.l1 = DLG_TEXT[197];
			link.l1.go = "exit";
			AddDialogExitQuest("fourth_mission_kill_jean_fire_without_fight");
		break;

		case "fourth_mission_with_officer_to_shop_wrong":
			Preprocessor_Add("Nathaniel", GetMyName(PChar));
			dialog.text = DLG_TEXT[198];
			link.l1 = DLG_TEXT[199];
			link.l1.go = "fifth_mission";
			AddDialogExitQuest("fourth_mission_failed");
		break;

		case "fifth_mission":
			if (checkQuestAttribute("smuggler_line.third_mission", "completed"))
			{
				dialog.text = DLG_TEXT[200];
				link.l1 = DLG_TEXT[201];
				link.l1.go = "fifth_mission_2";
			}
			else
			{
				dialog.text= DLG_TEXT[202];
				link.l1 = DLG_TEXT[203];
				link.l1.go = "fifth_mission_2";
			}
		break;

		case "fifth_mission_2":
			dialog.text = DLG_TEXT[204];
			link.l1 = DLG_TEXT[205];
			link.l1.go = "fifth_mission_3";
		break;

		case "fifth_mission_3":
			dialog.text = DLG_TEXT[206];
			link.l1 = DLG_TEXT[207];
			link.l1.go = "fifth_mission_4";
		break;

		case "fifth_mission_4":
			dialog.text = DLG_TEXT[208];
			link.l1 = DLG_TEXT[209];
			link.l1.go = "exit";
			AddDialogExitQuest("fifth_mission_meet_with_barrakuda");
		break;

		case "fifth_mission_meet_with_barrakuda_2":
			dialog.text = DLG_TEXT[235];
			link.l1 = DLG_TEXT[236];
			link.l1.go = "fifth_mission_meet_with_barrakuda_3";
		break;

		case "fifth_mission_meet_with_barrakuda_3":
			dialog.text = DLG_TEXT[237];
			link.l1 = DLG_TEXT[238];
			link.l1.go = "fifth_mission_meet_with_barrakuda_4";
		break;

		case "fifth_mission_meet_with_barrakuda_4":
			dialog.text = DLG_TEXT[239] + GetMyName(PChar) + ".";
			link.l1 = DLG_TEXT[240];
			link.l1.go = "fifth_mission_meet_with_barrakuda_5";
		break;

		case "fifth_mission_meet_with_barrakuda_5":
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Barrakuda"));
			if (IsCompanion(CharacterFromID("Barrakuda")))
			{
				dialog.text = DLG_TEXT[241];
				link.l1 = DLG_TEXT[242];
				link.l1.go = "exit";
				AddDialogExitQuest("fifth_mission_accept");
			}
			else
			{
				dialog.text = DLG_TEXT[243];
				link.l1 = DLG_TEXT[244];
				link.l1.go = "exit";
				AddDialogExitQuest("fifth_mission_wait_for_join_barrakuda");
			}
		break;

		case "fifth_mission_know_about_betrayer":
			dialog.text = DLG_TEXT[210];
			link.l1 = DLG_TEXT[211];
			link.l1.go = "fifth_mission_know_about_betrayer_2";
		break;

		case "fifth_mission_know_about_betrayer_2":
			dialog.text = DLG_TEXT[212];
			link.l1 = DLG_TEXT[213];
			link.l1.go = "fifth_mission_know_about_betrayer_3";
		break;

		case "fifth_mission_know_about_betrayer_3":
			dialog.text = DLG_TEXT[214];
			link.l1 = DLG_TEXT[215];
			link.l1.go = "fifth_mission_know_about_betrayer_4";
		break;

		case "fifth_mission_know_about_betrayer_4":
			dialog.text = DLG_TEXT[216];
			link.l1 = DLG_TEXT[217];
			link.l1.go = "fifth_mission_know_about_betrayer_5";
		break;

		case "fifth_mission_know_about_betrayer_5":
			dialog.text = DLG_TEXT[218];
			link.l1 = DLG_TEXT[219];
			link.l1.go = "fifth_mission_know_about_betrayer_6";
		break;

		case "fifth_mission_know_about_betrayer_6":
			dialog.text = DLG_TEXT[220];
			link.l1 = DLG_TEXT[221];
			link.l1.go = "exit";
			AddDialogExitQuest("fifth_mission_prepare_for_trap");
		break;

		case "fifth_mission_move_fleet":
			dialog.text = DLG_TEXT[245];
			link.l1 = DLG_TEXT[246];
			AddDialogExitQuest("fifth_mission_move_fleet");
			link.l1.go = "exit";
		break;

		case "trap_completed":
			Preprocessor_Add("Nathaniel", GetMyName(PChar));
			dialog.text = DLG_TEXT[222];
			link.l1 = DLG_TEXT[223];
			link.l1.go = "trap_completed_2";
		break;

		case "trap_completed_2":
			if (checkQuestAttribute("smuggler_line.first_mission", "completed") && checkQuestAttribute("smuggler_line.second_mission", "completed") && checkQuestAttribute("smuggler_line.third_mission", "completed") && checkQuestAttribute("smuggler_line.fourth_mission", "completed"))
			{
				dialog.text = DLG_TEXT[224];
				link.l1 = DLG_TEXT[225];
				link.l1.go = "trap_completed_3";
				link.l2 = DLG_TEXT[226];
				link.l2.go = "final_fight";
			}
			else
			{
				dialog.text = DLG_TEXT[227];
				link.l1 = DLG_TEXT[228];
				link.l1.go = "final_fight_2";
			}
		break;

		case "final_fight":
			dialog.text = DLG_TEXT[229];
			link.l1 = DLG_TEXT[230];
			link.l1.go = "exit";
			AddDialogExitQuest("smuggler_line_final_fight");
		break;

		case "final_fight_2":
			dialog.text = DLG_TEXT[231];
			link.l1 = DLG_TEXT[232];
			link.l1.go = "exit";
			AddDialogExitQuest("smuggler_line_final_fight_2");
		break;

		case "trap_completed_3":
			dialog.text = DLG_TEXT[233];
			link.l1 = DLG_TEXT[234];
			link.l1.go = "exit";
			AddDialogExitQuest("smuggler_line_completed");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
