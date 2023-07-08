//#include "DIALOGS\Smuggler Agent_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d, her;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;

	LAi_group_SetRelation(LAI_GROUP_PLAYER, "Smugglers", LAI_GROUP_NEUTRAL); // ccc: Fix the problem with smugglers remaining hostile
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	string PatrolState;
	ref SmugglingIsland;
	int n;
	n = GetCharacterCurrentIsland(Pchar);
	if(n < 0) return "none";
	SmugglingIsland = GetIslandByIndex(n);
	
	int topay;

	float topay_inflation_rate = 1.1;
	float inflation;
	if (CheckAttribute(PChar,"quest.smuggling_guild.times_payed")) inflation = pow(topay_inflation_rate, sti(PChar.quest.smuggling_guild.times_payed));
	else inflation = 1.0;
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча

		case "Smuggling_exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			AddDialogExitQuest("Made Deal with Smuggler"); //Add quest
			DialogExit();
		break;
		
		//Levis: Collector sidequest
		case "Request for Collector 1":
			d.Text = DLG_TEXT[51];
			Link.l1 = DLG_TEXT[52];
			Link.l1.go = "Request for Collector 2";
		break;
		
		case "Request for Collector 2":
			d.Text = DLG_TEXT[53];
			Link.l1 = DLG_TEXT[54];
			Link.l1.go = "Request for Collector 3";
		break;
		
		case "Request for Collector 3":
			d.Text = DLG_TEXT[55];
			Link.l1 = DLG_TEXT[56];
			Link.l1.go = "exit";
			AddDialogExitQuest("Smugglers Collector Meet in Tavern");
			Diag.TempNode = "Meeting";
			NPChar.quest.made_offer_collector = true;
			DeleteAttribute(&PChar,"quest.mysterious_plants.crewmember.attacked_tell_steven");
		break;
		
		case "Offer Collector":
			if(CheckSmugglerLiking(pchar) >= 25)
			{
				AddQuestRecord("smuggle_collector", 3);
				d.Text = DLG_TEXT[58];
				Link.l1 = DLG_TEXT[59];
				Link.l1.go = "Accept Offer Collector";
				Link.l2 = DLG_TEXT[60];
				Link.l2.go = "Decline Offer Collector";
			}
			else
			{
				//Added by levis to repay for your sins
				topay = makeint(pow2((25-CheckSmugglerLiking(pchar)),3)*5*inflation);
				pchar.quest.smuggling_guild.pay_redeem = topay;
				d.Text = DLG_TEXT[26] + topay + DLG_TEXT[27];
				if (sti(PChar.money) >= topay)
				{
					Link.l1 = DLG_TEXT[29];
					Link.l1.go = "Pay";
				}
				Link.l2 = DLG_TEXT[28];
				Link.l2.go = "Exit";
			}
		break;
		
		case "Accept Offer Collector":
			ChangeSmugglerLiking(pchar, 5);
			d.Text = DLG_TEXT[63];
			Link.l1 = DLG_TEXT[64];
			Link.l1.go = "exit";
			AddDialogExitQuest("Accept Collectors Offer");
		break;
		
		case "Decline Offer Collector":
			d.Text = DLG_TEXT[61];
			Link.l1 = DLG_TEXT[62];
			Link.l1.go = "exit";
			ChangeSmugglerLiking(pchar, -10);
			AddDialogExitQuest("Decline Collectors Offer");
		break;
		
		case "Collector Contact":
			ChangeSmugglerLiking(pchar, 5);
			GetSmugglingGuildMembers(1, "Collector", "Smuggler_Collector.c");
			d.Text = DLG_TEXT[66]+pchar.quest.smuggling_guild.people.Collector.Collector0.name+DLG_TEXT[67]+pchar.quest.smuggling_guild.people.Collector.Collector0.location+DLG_TEXT[68]+pchar.quest.smuggling_guild.people.Collector.Collector0.island+DLG_TEXT[69];
			Link.l1 = DLG_TEXT[70];
			Link.l1.go = "exit";
			AddDialogExitQuest("Smugglers Set Collector");
		break;
		//Levis End Collector sidequest
		
		// Added by Levis -->
		case "Smuggling prepare exit":
			Diag.CurrentNode = "Ready to go";
			NPChar.quest.meeting = NPC_Meeting;
			AddDialogExitQuest("Prepare Smuggling"); //Add quest
			PChar.quest.Contraband.contact = NPChar.id;
			DialogExit();
		break;
		
		case "Exit_Pay":
			PlayStereoSound("INTERFACE\writing.wav");
			Diag.CurrentNode = "AfterPay";
			NPChar.quest.meeting = NPC_Meeting;
			AddDialogExitQuest("Smuggler Paid for relation");
			DialogExit();
		break;
		
		case "Ready to go":
			if(getSmugglingState(SmugglingIsland) == 1) PatrolState = DLG_TEXT[78];
			if(getSmugglingState(SmugglingIsland) == 2) PatrolState = DLG_TEXT[79];
			if(getSmugglingState(SmugglingIsland) == 3) PatrolState = DLG_TEXT[80];
			if(getSmugglingState(SmugglingIsland) == 4) PatrolState = DLG_TEXT[81];
			d.Text = DLG_TEXT[19] + TranslateString("",locations[FindLocation(Pchar.quest.contraband.CurrentPlace)].name) + DLG_TEXT[22]+PatrolState;
			Link.l1 = DLG_TEXT[23];
			Link.l1.go = "Smuggling_exit";
			Link.l2 = DLG_TEXT[48];
			Link.l2.go = "Smuggling cancel exit";
			PChar.quest.Prepare_Smuggling_Fail.over = "yes";
		break;
		
		case "Smuggling cancel exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			AddDialogExitQuest("Cancel_Smuggling"); //Add quest
			DialogExit();
		break;
		//Added by Levis <--
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "First time":			
			if(NPChar.quest.meeting == "0")
			{
				Dialog.snd = "voice\SMAG\SMAG001";
				d.Text = DLG_TEXT[0];
				if (GetCharacterShipType(PChar) == SHIP_NOTUSED) Link.l1 = DLG_TEXT[1] + GetMyFullName(PChar) + DLG_TEXT[2];
				else Link.l1 = PCharPhrase(DLG_TEXT[1] + GetMyFullName(PChar) + DLG_TEXT[2], DLG_TEXT[3] + GetMyFullName(PChar) + DLG_TEXT[4] + GetMyShipNameShow(PChar) + DLG_TEXT[5]);
				Link.l1.go = "meeting";
				NPC_Meeting = "1"; 
			}
			else
			{
				Dialog.snd = "voice\SMAG\SMAG002";
				d.Text = DLG_TEXT[6];
				if(FindFirstContrabandGoods(PChar) != -1)
				{
					Link.l1 = DLG_TEXT[7];
					Link.l1.go = "Meeting_3";
				}
/*
				if(CheckCharacterItem(Pchar,"opium") || CheckSmugglerLiking(pchar) >= 75)
				{
					if(!CheckAttribute(pchar,"quest.smuggling_guild.opium_explain"))
					{
						Link.l2 = DLG_TEXT[31];
						Link.l2.go = "Othergoods";
					}
					else
					{
						if(!CheckAttribute(pchar,"quest.smuggling_guild.opium_explain_effects"))
						{
							Link.l2 = DLG_TEXT[45];
							Link.l2.go = "Opium Effects";
						}
					}
				}
*/
				//Levis: Collector sidequest
				if(CheckAttribute(PChar,"quest.smuggle_collector.made_offer_collector"))
				{
					Link.l3 = DLG_TEXT[57];
					Link.l3.go = "Offer Collector";
				}
				if(CheckAttribute(PChar,"quest.smuggle_collector.collect_bows") && sti(PChar.items.pistolbow) >= 10)
				{
					Link.l3 = DLG_TEXT[65];
					Link.l3.go = "Collector Contact";
				}
				//Levis: End Collector sidequest
				//Levis: Thomas -->
				if(CheckAttribute(pchar,"quest.smuggling_guild.quests.see_thomas_make_deal.time_to_report"))
				{
					Link.l4 = DLG_TEXT[71];
					Link.l4.go = "Report Thomas";
				}
				//Levis: Thomas <--

				// GR: Agent trophy quest --->
				if (CheckQuestAttribute("agentquest", "find_smuggler"))
				{
					link.l1 = DLG_TEXT[82] + FindTownName(PChar.quest.agentquest.original_town) + DLG_TEXT[83];
					link.l1.go = "Agent_quest_passage";
				}
				// GR: Agent trophy quest <---
				Link.l5 = DLG_TEXT[8];
				Link.l5.go = "Exit";
			}
		break;
		
		//Levis: Thomas -->
		case "Report Thomas":
			AddDialogExitQuest("Reported Thomas to Smugglers");
			d.Text = DLG_TEXT[72];
			Link.l1 = DLG_TEXT[73];
			Link.l1.go = "Exit";
		break;
		//Levis: Thomas <--
		
		//Levis opium explanation ->
		case "Othergoods":
			d.Text = "";
			if(CheckCharacterItem(Pchar,"opium"))
			{
				d.Text = DLG_TEXT[32];
			}
			d.Text = d.Text + DLG_TEXT[33];
			Link.l1 = DLG_TEXT[34];
			Link.l1.go = "Give Book and List";
			Link.l2 = DLG_TEXT[45];
			Link.l2.go = "Opium Effects";
		break;
		
		case "Opium Effects":
			pchar.quest.smuggling_guild.opium_explain_effects = true;
			AddDialogExitQuest("Smugglers Opium Effects Explain");
			d.Text = DLG_TEXT[46];
			Link.l1 = DLG_TEXT[47];
			Link.l1.go = "Exit";
		break;
		
		case "Give Book and List":
			d.Text = DLG_TEXT[35];
			Link.l1 = DLG_TEXT[36];
			Link.l1.go = "Exit Opium List";
		break;
		
		case "Exit Opium List":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			AddDialogExitQuest("Smugglers Opium Explain");
			DialogExit();
		break;
		//Levis opium explanation <-

		case "Meeting":
			Dialog.snd = "voice\SMAG\SMAG003";
			d.Text = DLG_TEXT[9];
			if(FindFirstContrabandGoods(PChar) != -1)
			{
				Link.l1 = DLG_TEXT[10];
				Link.l1.go = "Meeting_1";
			}
/*
			if(CheckCharacterItem(Pchar,"opium") || CheckSmugglerLiking(pchar) >= 75)
			{
				if(!CheckAttribute(pchar,"quest.smuggling_guild.opium_explain"))
				{
					Link.l2 = DLG_TEXT[31];
					Link.l2.go = "Othergoods";
				}
				else
				{
					if(!CheckAttribute(pchar,"quest.smuggling_guild.opium_explain_effects"))
					{
						Link.l2 = DLG_TEXT[45];
						Link.l2.go = "Opium Effects";
					}
				}
			}
*/
			//Levis: Collector sidequest
			if(CheckAttribute(PChar,"quest.smuggle_collector.made_offer_collector"))
			{
				Link.l3 = DLG_TEXT[57];
				Link.l3.go = "Offer Collector";
			}
			if(CheckAttribute(PChar,"quest.smuggle_collector.collect_bows") && sti(PChar.items.pistolbow) >= 10)
			{
				Link.l3 = DLG_TEXT[65];
				Link.l3.go = "Collector Contact";
			}
			//Levis: End Collector sidequest
			//Levis: Thomas -->
			if(CheckAttribute(pchar,"quest.smuggling_guild.quests.see_thomas_make_deal.time_to_report"))
			{
				Link.l4 = DLG_TEXT[71];
				Link.l4.go = "Report Thomas";
			}
			//Levis: Thomas <--
			// GR: Agent trophy quest --->
			if (CheckQuestAttribute("agentquest", "find_smuggler"))
			{
				link.l1 = DLG_TEXT[82] + FindTownName(PChar.quest.agentquest.original_town) + DLG_TEXT[83];
				link.l1.go = "Agent_quest_passage";
			}
			// GR: Agent trophy quest <---
			Link.l5 = DLG_TEXT[11];
			Link.l5.go = "Exit";
		break;

		case "Meeting_1":
			Dialog.snd = "voice\SMAG\SMAG004";
			d.Text = DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "Meeting_2";				
			Link.l2 = DLG_TEXT[14];
			Link.l2.go = "exit";				
		break;

		case "Meeting_2":
			Dialog.snd = "voice\SMAG\SMAG005";
			d.Text = DLG_TEXT[15];
			Link.l1 = DLG_TEXT[16];
			Link.l1.go = "Meeting_3";				
		break;

		//Added by Levis for liking
		case "Pay":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(Pchar, -1 * sti(pchar.quest.smuggling_guild.pay_redeem));
			Dialog.snd = "voice\SMAG\SMAG005";
			d.Text = DLG_TEXT[30];
			Link.l1 = DLG_TEXT[49];
			Link.l1.go = "Exit_Pay"; // PB: Above AddDialogExitQuest needs to be executed!
		break;
		
		case "AfterPay":
			d.Text = DLG_TEXT[50];
			Link.l1 = DLG_TEXT[10];
			Link.l1.go = "Meeting_1";
		break;
		//End add

		case "Meeting_3":
			if(CheckAttribute(Pchar, "quest.Contraband.Active") && Pchar.quest.Contraband.Active == true)
			{
				Dialog.snd = "voice\SMAG\SMAG006";				
				d.Text = DLG_TEXT[17];
				Link.l1 = DLG_TEXT[18];
				Link.l1.go = "Exit";				
			}
			else
			{
				//Added liking check by Levis
				if(CheckSmugglerLiking(pchar) >= 25)
				{
					Pchar.quest.contraband.CurrentPlace = SelectSmugglingLocation();
					Dialog.snd = "voice\SMAG\SMAG007";
					if(getSmugglingState(SmugglingIsland) == 1) PatrolState = DLG_TEXT[74];
					if(getSmugglingState(SmugglingIsland) == 2) PatrolState = DLG_TEXT[75];
					if(getSmugglingState(SmugglingIsland) == 3) PatrolState = DLG_TEXT[76];
					if(getSmugglingState(SmugglingIsland) == 4) PatrolState = DLG_TEXT[77];
				
					d.Text = DLG_TEXT[20]+PatrolState+DLG_TEXT[25];    //+locations[FindLocation(Pchar.quest.contraband.CurrentPlace)].name  // TALISMAN - remove beach name so player has to go back to agent to find out where to go.
					if (!CheckAttribute(Pchar,"quest.smuggling_got_book")) d.Text = d.Text + DLG_TEXT[24];
					if (CheckAttribute(pchar, "amount_smuggleruns") && sti(pchar.amount_smuggleruns) > 2)    // PB & TALISMAN
					{
						Link.l1 = DLG_TEXT[21];
						Link.l1.go = "Smuggling prepare exit";
					}
					else
					{
						Link.l1 = DLG_TEXT[21];
						Link.l1.go = "Meeting_4"; //  -- TALISMAN - additional dialog added below
					}
				}
				else
				{
					//Added by levis to repay for your sins
					topay = makeint(pow2((25-CheckSmugglerLiking(pchar)),3)*5*inflation);
					pchar.quest.smuggling_guild.pay_redeem = topay;
					d.Text = DLG_TEXT[26] + topay + DLG_TEXT[27];
					if (sti(PChar.money) >= topay)
					{
						Link.l1 = DLG_TEXT[29];
						Link.l1.go = "Pay";
					}
					Link.l2 = DLG_TEXT[28];
					Link.l2.go = "Exit";
				}
			}
		break;
		
		//TALISMAN - add dialog to try and explain things ---->>
		case "Meeting_4":
			d.Text = DLG_TEXT[37];
			Link.l1 = DLG_TEXT[38];
			Link.l1.go = "Meeting_5";
		break;

		case "Meeting_5":
			d.Text = DLG_TEXT[39];
			Link.l1 = DLG_TEXT[40];
			Link.l1.go = "Meeting_6";
		break;
		
		case "Meeting_6":
			d.Text = DLG_TEXT[41];
			Link.l1 = DLG_TEXT[42];
			Link.l1.go = "Meeting_7";
		break;

		case "Meeting_7":
			d.Text = DLG_TEXT[43];
			Link.l1 = DLG_TEXT[44];
			Link.l1.go = "Smuggling prepare exit";
		break;
		// <<--- TALISMAN end of add dialog

		// GR: Agent trophy quest --->
		case "Agent_quest_passage":
			if(CheckSmugglerLiking(PChar) >= 25)
			{
				d.Text = DLG_TEXT[84];
				Link.l1 = DLG_TEXT[85];
				Link.l1.go = "Agent_quest_passage2";
			}
			else
			{
				topay = makeint(pow2((25-CheckSmugglerLiking(pchar)),3)*5*inflation);
				pchar.quest.smuggling_guild.pay_redeem = topay;
				d.Text = DLG_TEXT[26] + topay + DLG_TEXT[27];
				if (sti(PChar.money) >= topay)
				{
					Link.l1 = DLG_TEXT[29];
					Link.l1.go = "Pay";
				}
				Link.l2 = DLG_TEXT[28];
				Link.l2.go = "Exit";
			}
		break;

		case "Agent_quest_passage2":
			d.Text = DLG_TEXT[86];
			Link.l1 = DLG_TEXT[87];
			Link.l1.go = "Agent_quest_passage3";
		break;

		case "Agent_quest_passage3":
			switch(PChar.quest.agentquest.port2)
			{
				case "QC_port": PChar.quest.agentquest.smuggler_beach = "QC_Shore1"; break;
				case "Muelle_port": PChar.quest.agentquest.smuggler_beach = "Muelle_shore"; break;
				case "REDMOND_PORT": PChar.quest.agentquest.smuggler_beach = "Redmond_shore_02"; break;
				case "PoPrince_Port": PChar.quest.agentquest.smuggler_beach = "Hispaniola_shore_02"; break;
				case "Douwesen_port": PChar.quest.agentquest.smuggler_beach = "Douwesen_shore_02"; break;
				case "Conceicao_port": PChar.quest.agentquest.smuggler_beach = "Conceicao_shore_01"; break;
				case "Alice_Port": PChar.quest.agentquest.smuggler_beach = "Eleuthera_shore"; break;
			}
			d.Text = DLG_TEXT[88] + TranslateString("", Locations[FindLocation(PChar.quest.agentquest.smuggler_beach)].name) + DLG_TEXT[89];
			Link.l1 = DLG_TEXT[90];
			Link.l1.go = "Agent_quest_fare";
		break;

		case "Agent_quest_fare":
			string dislandid = PChar.quest.agentquest.original_island;
			string cislandid = GetIslandIDFromTown(GetCurrentTownID());
			float distancedestination = GetDistance2D(stf(worldMap.islands.(dislandid).position.x), stf(worldMap.islands.(dislandid).position.z), stf(worldMap.islands.(cislandid).position.x), stf(worldMap.islands.(cislandid).position.z));
			int fare = 10000 + makeint(distancedestination * (200-CheckSmugglerLiking(PChar)) * ((GetDifficulty()+4)/5.0) * 0.05);
			PChar.quest.agentquest.smuggler_distance = distancedestination;
			PChar.quest.agentquest.smuggler_fare = fare;
			d.Text = DLG_TEXT[91] + fare + DLG_TEXT[92];
			if (PChar.money >= fare)
			{
				Link.l1 = DLG_TEXT[93];
				Link.l1.go = "Exit_Agent_quest_fare_paid";
			}
			else
			{
				Link.l1 = DLG_TEXT[94];
				Link.l1.go = "Agent_quest_fare_unpaid";
			}
		break;

		case "Agent_quest_fare_unpaid":
			d.Text = DLG_TEXT[95];
			Link.l1 = DLG_TEXT[96];
			Link.l1.go = "Exit_Agent_quest_fare_unpaid";
		break;

		case "Exit_Agent_quest_fare_paid":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, -1 * sti(PChar.quest.agentquest.smuggler_fare));
			PChar.quest.agentquest.smuggler_fare = 0;
			AddDialogExitQuest("AgentQuest_Met_Smuggler_Agent");
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "Exit_Agent_quest_fare_unpaid":
			PChar.quest.agentquest.smuggler_fare = sti(PChar.quest.agentquest.smuggler_fare) * 2;
			AddDialogExitQuest("AgentQuest_Met_Smuggler_Agent");
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;
		// GR: Agent trophy quest <---
	}
}