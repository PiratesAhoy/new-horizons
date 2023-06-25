//#include "DIALOGS\Agent_crewman_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	ref old_ship_location;
	string old_ship_location_name, old_ship_town, shiploc;
	int nation;
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча

		case "exit":
			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();
		break;

	
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			dialog.text = DLG_TEXT[0] + GetAddressForm(ADDR_POLITE, GetServedNation(), PChar.sex == "woman");
			link.l1 = DLG_TEXT[2];
			link.l1.go = "Exit";
		break;

		case "dismiss_ship":
			old_ship_location = LocationFromID(PChar.quest.agentquest.original_location_from_sea);
			old_ship_town = GetTownIDFromLocID(PChar.quest.agentquest.original_location_from_sea);
			if (HasSubStr(old_ship_location.id.label, "town_name")) old_ship_location_name =  FindTownName(old_ship_town);
			else old_ship_location_name = TranslateString("", old_ship_location.id.label);
			PChar.quest.agentquest.old_ship_location_name = old_ship_location_name;
			dialog.text = DLG_TEXT[0] + GetAddressForm(ADDR_POLITE, GetServedNation(), PChar.sex == "woman");
			link.l1 = DLG_TEXT[3] + GetCharacterAddressForm(NPChar, ADDR_CIVIL, false, true) + DLG_TEXT[4] + FindTownName(PChar.quest.agentquest.original_town) + DLG_TEXT[5];
			link.l1.go = "exit";
		break;

		case "smuggler_meet":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7] + GetMyFullName(PChar) + DLG_TEXT[8] + FindTownName(PChar.quest.agentquest.original_town) + DLG_TEXT[9];
			link.l1.go = "smuggler_pay_me";
		break;

		case "smuggler_pay_me":
			dialog.text = DLG_TEXT[10];
			if (sti(PChar.quest.agentquest.smuggler_fare) == 0) link.l1 = DLG_TEXT[11];
			else link.l1 = DLG_TEXT[12] + PChar.quest.agentquest.smuggler_fare + DLG_TEXT[13] + FindTownName(PChar.quest.agentquest.original_town) + DLG_TEXT[14];
			link.l1.go = "smuggler_no_pay";
		break;

		case "smuggler_no_pay":
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "smuggler_lets_go";
		break;

		case "smuggler_lets_go":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			AddDialogExitQuest("AgentQuest_smuggler_depart");
			link.l1.go = "exit";
		break;

		case "smuggler_pay_up":
			dialog.text = DLG_TEXT[19] + PChar.quest.agentquest.smuggler_fare + DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "smuggler_warning";
		break;

		case "smuggler_warning":
			Diag.TempNode = "smuggler_warning2";
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "exit";
		break;

		case "smuggler_warning2":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "exit";
		break;

		case "smuggler_payoff":
			Diag.TempNode = "smuggler_till_next_time";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, -1 * sti(PChar.quest.agentquest.smuggler_fare));
			PChar.quest.agentquest.smuggler_fare = 0;
			int govnation;
			if (CheckAttribute(CharacterFromID(PChar.quest.agentquest.governor), "nation")) govnation = sti(GetAttribute(CharacterFromID(PChar.quest.agentquest.governor), "nation"));
			else govnation = GetServedNation();
			dialog.text = DLG_TEXT[26] + XI_ConvertString(GetNationDescByType(govnation)) + DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "exit";
		break;

		case "smuggler_till_next_time":
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "exit";
		break;

		case "agent_start1":
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "agent_start_introductions1";
		break;

		case "agent_start_introductions1":
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34] + GetMyFullName(NPChar) + DLG_TEXT[35] + XI_ConvertString(GetMyPronounObj(NPChar)) + DLG_TEXT[36];
			link.l1.go = "agent_start_introductions2";
		break;

		case "agent_start_introductions2":
			dialog.text = DLG_TEXT[37] + XI_ConvertString(NPChar.sex) + DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "agent_start_introductions3";
		break;

		case "agent_start_introductions3":
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			if (PChar.location == "Eleuthera_tavern") link.l1 = link.l1 + DLG_TEXT[43];
			else link.l1 = link.l1 + DLG_TEXT[42];
			link.l1.go = "exit";

			PChar.quest.AgentStart_get_room.win_condition.l1 = "location";
			PChar.quest.AgentStart_get_room.win_condition.l1.location = FindTownTavern(GetCurrentTownID())+"_upstairs";
			PChar.quest.AgentStart_get_room.win_condition = "AgentStart_get_room";
		break;

		case "agent_start_talk_in_room":
			dialog.text = DLG_TEXT[44];
			link.l1 = PChar.quest.agent_start.officername + DLG_TEXT[45];
			link.l1.go = "agent_start_have_you_ship";
		break;

		case "agent_start_have_you_ship":
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47] + GetMyShipNameShow(PChar) + DLG_TEXT[48];
			link.l1.go = "agent_start_seaworthy";
		break;

		case "agent_start_seaworthy":
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "agent_start_who_are_you";
		break;

		case "agent_start_who_are_you":
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "agent_start_real_name";
		break;

		case "agent_start_real_name":
			dialog.text = DLG_TEXT[53] + GetMySimpleOldName(NPChar) + DLG_TEXT[54];
			link.l1 = DLG_TEXT[55] + GetMyRespectfullyName(CharacterFromID("Malcolm Hatcher")) + DLG_TEXT[56];
			link.l1.go = "agent_start_where_moored";
		break;

		case "agent_start_where_moored":
			string sNation;
			sNation = XI_ConvertString(GetNationDescByType(GetTownNation(GetCurrentTownID())));
			if (GetTownNation(GetCurrentTownID()) == PIRATE) sNation = DLG_TEXT[58];
			if (GetTownNation(GetCurrentTownID()) == AMERICA && GetCurrentPeriod() >= PERIOD_REVOLUTIONS) sNation = DLG_TEXT[59];
			dialog.text = DLG_TEXT[57] + sNation + DLG_TEXT[60];

			if (HasSubstr(GetCharacterShipLocation(PChar), "_port"))
			{
				if (GetTownIDFromLocID(GetCharacterShipLocation(PChar)) == GetCurrentTownID()) shiploc = "here";
				else shiploc = FindTownName(GetTownIDFromLocID(GetCharacterShipLocation(PChar)));
			}
			else shiploc = PreprocessText(GetCharacterShipLocationName(PChar));
			if (shiploc == "here")
			{
				link.l1 = DLG_TEXT[61];
				link.l1.go = "agent_start_move_your_ship";
			}
			else
			{
				link.l1 = DLG_TEXT[62] + shiploc + DLG_TEXT[63];
				link.l1.go = "agent_start_lets_go";
			}
			Preprocessor_AddQuestData("name", GetMySimpleName(NPChar));
			Preprocessor_AddQuestData("name2", GetMySimpleOldName(NPChar));
			Preprocessor_AddQuestData("pronoun3", XI_ConvertString(GetMyPronounPossessive(NPChar)));
			AddQuestRecord("Beginning_Agent", 2);
			Preprocessor_Remove("pronoun3");
			Preprocessor_Remove("name2");
			Preprocessor_Remove("name");
		break;

		case "agent_start_move_your_ship":
			dialog.text = DLG_TEXT[64];
			if (PChar.location == "Eleuthera_tavern_upstairs") dialog.text = dialog.text + DLG_TEXT[66];
			else dialog.text = dialog.text + DLG_TEXT[65];
			link.l1 = DLG_TEXT[67];
			AddDialogExitQuest("AgentStart_Prepare_Leave_Room");
			link.l1.go = "exit";
			Preprocessor_AddQuestData("name2", GetMySimpleOldName(NPChar));
			Preprocessor_AddQuestData("nation", XI_ConvertString(GetNationDescByType(GetTownNation(GetCurrentTownID()))));
			AddQuestRecord("Beginning_Agent", 3);
			Preprocessor_Remove("nation");
			Preprocessor_Remove("name2");
		break;

		case "agent_start_lets_go":
			dialog.text = DLG_TEXT[68];
			link.l1 = DLG_TEXT[69];
			AddDialogExitQuest("AgentStart_follow_to_ship");
			link.l1.go = "exit";
		break;

		case "agent_start_ship_moved":
			if (HasSubstr(GetCharacterShipLocation(PChar), "_port"))
			{
				if (GetTownIDFromLocID(GetCharacterShipLocation(PChar)) == GetCurrentTownID()) shiploc = "here";
				else shiploc = FindTownName(GetTownIDFromLocID(GetCharacterShipLocation(PChar)));
			}
			else shiploc = PreprocessText(GetCharacterShipLocationName(PChar));
			dialog.text = DLG_TEXT[70];
			if (shiploc == "here")
			{
				link.l1 = DLG_TEXT[71];
				link.l1.go = "exit_still_move_ship";
			}
			else
			{
				link.l1 = DLG_TEXT[72] + shiploc + DLG_TEXT[73];
				link.l1.go = "agent_start_lets_go";
			}
		break;

		case "exit_still_move_ship":
			Diag.CurrentNode = "agent_start_ship_moved"; //"First time";
			DialogExit();
		break;

		case "agent_start_where_to_go":
			string agent_destination, agent_destination_island;
			nation = sti(Characters[GetCharacterIndex("Malcolm Hatcher")].nation);
			if (nation == PERSONAL_NATION) nation = FindFriendlyNation2Nation(PERSONAL_NATION);
			switch(nation)
			{
				case ENGLAND:
					if (GetCurrentPeriod() == PERIOD_EARLY_EXPLORERS)
					{
						agent_destination = FindTownName("Tortuga") + DLG_TEXT[78];
						agent_destination_island = "Hispaniola";
					}
					else
					{
						agent_destination = DLG_TEXT[81];
						agent_destination_island = "Antigua";
					}
				break;

				case FRANCE:
					if (GetCurrentPeriod() == PERIOD_EARLY_EXPLORERS)
					{
						agent_destination = DLG_TEXT[78];
						agent_destination_island = "Hispaniola";
					}
					else
					{
						agent_destination = DLG_TEXT[82] + FindTownName("Pointe a Pitre");
						agent_destination_island = "Guadeloupe";
					}
				break;

				case SPAIN:
					agent_destination = DLG_TEXT[83] + FindTownName("Havana");
					agent_destination_island = "Cuba";
				break;

				case PIRATE:
					agent_destination = DLG_TEXT[84];
					agent_destination_island = "QuebradasCostillas";
				break;

				case HOLLAND:
					if (GetCurrentPeriod() == PERIOD_EARLY_EXPLORERS)
					{
						agent_destination = DLG_TEXT[78];
						agent_destination_island = "Hispaniola";
					}
					else
					{
						agent_destination = DLG_TEXT[79] + FindTownName("Willemstad");
						agent_destination_island = "Curacao";
					}
				break;

				case PORTUGAL:
					agent_destination = DLG_TEXT[79] + FindTownName("Conceicao");
					agent_destination_island = "Conceicao";
				break;

				case GUEST1_NATION:
					if (GetCurrentPeriod() >= PERIOD_REVOLUTIONS)
					{
						agent_destination = DLG_TEXT[79] + FindTownName("Eleuthera");
						agent_destination_island = "Eleuthera";
					}
					else
					{
						agent_destination = DLG_TEXT[79] + FindTownName(GetTownIDFromLocID(PChar.quest.agent_start.HQ));
						agent_destination_island = "SaintMartin";
					}
				break;
			}
			if (agent_destination_island != "Hispaniola") agent_destination = agent_destination + DLG_TEXT[80] + FindIslandName(agent_destination_island);
			dialog.text = DLG_TEXT[74] + agent_destination + DLG_TEXT[75];
			link.l1 = DLG_TEXT[76] + FindIslandName(agent_destination_island) + DLG_TEXT[77];
			link.l1.go = "exit";
			Preprocessor_AddQuestData("name2", GetMySimpleOldName(NPChar));
			Preprocessor_AddQuestData("destination", agent_destination);
			AddQuestRecord("Beginning_Agent", 4);
			Preprocessor_Remove("destination");
			Preprocessor_Remove("name2");
		break;

		case "agent_start_reward":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(PChar, "Sneak", 1000);
				AddPartyExpChar(PChar, "", 100);
				AddPartyExpChar(PChar, "Leadership", 100);
			}
			else {AddPartyExp(PChar, 1100);}
			dialog.text = DLG_TEXT[86];
			if(!HaveLetterOfMarque(sti(NPChar.nation)))
			{
				dialog.text = dialog.text + DLG_TEXT[87] + DLG_TEXT[88];
				link.l1 = DLG_TEXT[89];
				link.l1.go = "agent_start_receive_lom";
			}
			else dialog.text = dialog.text + DLG_TEXT[88];
			link.l2 = DLG_TEXT[90];
			link.l2.go = "agent_start_receive_money";
		break;

		case "agent_start_receive_lom":
			SetRank(PChar, sti(NPChar.nation), GetOldRank(PChar, sti(NPChar.nation)));
			dialog.text = DLG_TEXT[91] + GetMyName(PChar) + DLG_TEXT[92];
			link.l1 = DLG_TEXT[93] + GetMyName(NPChar) + DLG_TEXT[94];
			link.l1.go = "exit";
			Preprocessor_AddQuestData("nation", XI_ConvertString(GetNationDescByType(sti(NPChar.nation))));
			AddQuestRecord("Beginning_Agent", 5);
			Preprocessor_Remove("nation");
			CloseQuestHeader("Beginning_Agent");
		break;

		case "agent_start_receive_money":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, 2500);
			dialog.text = DLG_TEXT[91] + GetMyName(PChar) + DLG_TEXT[92];
			link.l1 = DLG_TEXT[93] + GetMyName(NPChar) + DLG_TEXT[94];
			link.l1.go = "exit";
			AddQuestRecord("Beginning_Agent", 6);
			CloseQuestHeader("Beginning_Agent");
		break;
	}
}