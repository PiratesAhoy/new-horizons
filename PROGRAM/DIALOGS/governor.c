void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, NextDiag;
	string NPC_Meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(NextDiag, NPChar.Dialog);
	
	string iDay, iMonth, cargoid, questbookname;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;
	ref ctown = GetCurrentTown();
	
	// RM -->
	int    iNation = sti(NPChar.nation);
	string sNation = iNation;
	// RM <--
	string stemp = ""; // KK
	string sLogTitle, sLogEntry;

	int smugglegoods, smuggleamount, smuggleweight, smugglemoney;
	int base_reward = 10;		// Percentage of value of contraband smuggled for governor if you just report smugglers
	int arrest_reward = 50;		// Percentage of value of contraband smuggled for governor if you arrested smugglers yourself
	int minimum_reward =2500;	// Minimum reward for governor smuggling if cargo is too low value for percentage reward
	string islandID;

	// PG -->
	if(GetMusicScheme() == "PGMUS") { // KK
		if(musicName != "music_govreward")
		{
			if(GetRMRelation(PChar,iNation) >= REL_AMNESTY) SetMusicNoPause("music_govfriend");
			else SetMusicNoPause("music_govenemy");
		}
	}
	// PG <--

	switch(Dialog.CurrentNode)
	{
		case "LoM":
			dialog.text = DLG_TEXT[74];
			Link.l1 = DLG_TEXT[75] + GetCharacterAddressForm(NPChar, ADDR_POLITE, false, false) + ".";
			Link.l1.go = "LoMa";
			Link.l2 = DLG_TEXT[36];
			Link.l2.go = "exit";
		break;

		case "LoMa":
			dialog.text = DLG_TEXT[33] + GetNationRoyalByType(iNation) + DLG_TEXT[34] + GetLoMCost(iNation) + DLG_TEXT[35];
			Link.l1 = DLG_TEXT[36];
			Link.l1.go = "exit";
			if(GetCharacterMoney(PChar) > GetLoMCost(iNation))
			{
				Link.l2 = DLG_TEXT[37];
				Link.l2.go = "LoMb";
			}
		break;

		case "LoMb":
// KK -->
			Preprocessor_Add("gov_nation", XI_ConvertString(GetNationNameByType(iNation)));
			if (CheckAttribute(PChar, "Got_Relation_Book"))
			{
				stemp = GetHostileNations(iNation);
				if (stemp != "")
					stemp = DLG_TEXT[38] + DLG_TEXT[39] + DLG_TEXT[40] + stemp + DLG_TEXT[42] + DLG_TEXT[43];
				else
					stemp = DLG_TEXT[38] + DLG_TEXT[39] + DLG_TEXT[41] + DLG_TEXT[43];
			}
			else
			{
				stemp = DLG_TEXT[38];
			}
			AddMoneyToCharacter(PChar, -GetLoMCost(iNation));
			SetRank(PChar, iNation, GetOldRank(PChar, iNation));
			PChar.executions = 0;
			if(sti(PChar.reputation) >= REP_COMEBACKMIN && GetRank(PChar, iNation)) stemp += DLG_TEXT[44] + GetNationRoyalByType(iNation) + DLG_TEXT[45] + TranslateString(GetRankName(PChar, iNation),"") + ".";
			dialog.Text = stemp;
			if (CheckAttribute(PChar, "Got_Relation_Book"))
			{
				Link.l1 = DLG_TEXT[46];
				Link.l1.go = "exit";
			}
			else
			{
				dialog.Text = DLG_TEXT[38];
				Link.l1 = DLG_TEXT[76] + GetCharacterAddressForm(NPChar, ADDR_POLITE, false, false) + DLG_TEXT[77];
				Link.l1.go = "relationbook";
			}
// <-- KK
		break;

		case "amnesty":
			dialog.text = DLG_TEXT[47] + XI_ConvertString(GetNationNameByType(iNation)) + ", " + GetMyAddressForm(NPChar, PChar, ADDR_TITLE, false, false) + DLG_TEXT[48] + GetNationRoyalByType(iNation) + DLG_TEXT[49];
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "exit";
			if(sti(pchar.reputation) >= 40)
			{
				pchar.nations.(sNation).Amnesty = RMAmnestyCost(PChar, iNation);
				dialog.text = DLG_TEXT[51] + XI_ConvertString(GetNationNameByType(iNation)) + DLG_TEXT[52] + GetNationRoyalByType(iNation) + DLG_TEXT[53] + ShowMoney(-sti(pchar.nations.(sNation).Amnesty)) + DLG_TEXT[35];
				if(makeint(pchar.money) >= 0-makeint(pchar.nations.(sNation).Amnesty))
				{
					Link.l2 = DLG_TEXT[54];
					Link.l2.go = "Amnestyc";
				}
			}
		break;

		case "Amnestyc":
			dialog.text = DLG_TEXT[55] + GetMyFullName(PChar) + ".";
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(pchar, sti(pchar.nations.(sNation).Amnesty));
			DeleteAttribute(pchar,("nations."+sNation+".Amnesty"));
			RMAmnesty(&Pchar, iNation);
			Link.l1 = DLG_TEXT[56];
			Link.l1.go = "exit";
		break;

		case "promote":
			if(iNation != PIRATE && sti(GetAttribute(PChar, "executions")) >= 10)
			{
				dialog.text = DLG_TEXT[116];
				link.l1 = DLG_TEXT[117];
				link.l1.go = "executions_warning";
			}
			else
			{
				NPChar.templand = GetCharacterLand(PChar);
				Promote(&PChar, &NPChar, iNation);
				if (iNation == PIRATE)
				{
					dialog.text = LinkRandPhrase(DLG_TEXT[113] + TranslateString(GetRankName(PChar, iNation),"") + ".", DLG_TEXT[114] + TranslateString(GetRankName(PChar, iNation),"") + ".", DLG_TEXT[115] + TranslateString(GetRankName(PChar, iNation),"") + ".");
				}
				else
				{
					if (GetCharacterLand(PChar) - sti(NPChar.templand) > 0)
					{
						dialog.text = DLG_TEXT[57] + TranslateString(GetRankName(PChar, iNation),"") + DLG_TEXT[58] + (GetCharacterLand(PChar) - sti(NPChar.templand)) + DLG_TEXT[59] + GetNationRoyalByType(iNation) + ".";
					}
					else
					{
						dialog.text = DLG_TEXT[57] + TranslateString(GetRankName(PChar, iNation),"") + ".";
					}
				}
				DeleteAttribute(NPChar,"templand");
				Link.l1 = DLG_TEXT[60];
				if (GetMySimpleOldName(PChar) == "Horatio Hornblower" && iNation == ENGLAND && GetRank(PChar, ENGLAND) == 6) Link.l1.go = "Hornblower_ordered_to_Greenford";
				else Link.l1.go = "exit";
			}
		break;

		case "Hornblower_ordered_to_Greenford":
			Preprocessor_Add("briefing_officer", GetMyFullName(CharacterFromID("Sir Edward Pellew")));
			Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_POLITE, false, false));
			dialog.text = DLG_TEXT[110];
			link.l1 = DLG_TEXT[111];
			AddDialogExitQuest("Hornblower_initiate_Natividad");
			link.l1.go = "exit";
		break;

		case "leave":
			dialog.text = DLG_TEXT[61] + PChar.name + "? " + GetNationRoyalByType(iNation) + DLG_TEXT[62];
			Link.l1 = DLG_TEXT[63];
			Link.l1.go = "leavec";
			if(sti(PChar.reputation) < REP_LEAVEMIN + 5)
			{
				dialog.text = GetNationRoyalByType(iNation) + DLG_TEXT[64] + PChar.name + ".");
				Link.l1 = DLG_TEXT[69];
			}
			Link.l2 = DLG_TEXT[65];
			Link.l2.go = "exit";
		break;

		case "leavec":
			ChangeCharacterReputation(&PChar, -5);
			dialog.text = DLG_TEXT[66];
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "exit";
			if(LeaveService(PChar, iNation, false))
			{
				dialog.text = DLG_TEXT[67] + XI_ConvertString(DEFAULT_TITLE) + " " + PChar.lastname ".";
				Link.l1 = DLG_TEXT[68];
				Link.l1.go = "leavebad";
			}
		break;

		case "leavebad":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			ref sld;
			string loc;
			float dist;
			GetNearLocator( "goto", &dist, &loc, 0);
			sld = LAi_CreateFantomCharacter(false, 0, true, true, true, LAi_SoldierModel(iNation), "goto", loc);
			LAi_group_MoveCharacter(sld, GetSoldiersGroup(iNation));

			sld = LAi_CreateFantomCharacter(false, 0, true, true, true, LAi_SoldierModel(iNation), "goto", loc);
			LAi_group_MoveCharacter(sld, GetSoldiersGroup(iNation));

			LAi_group_SetRelation(GetSoldiersGroup(iNation), LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups(GetSoldiersGroup(iNation), LAI_GROUP_PLAYER, true);
		// RM <--
		break;

		case "quests":
// boal -->
			//Levis fixed some of the logic here.
			if (CheckQuestAttribute("generate_kill_quest", "completed") && pchar.quest.generate_kill_quest.town==GetCurrentTownID())
			{
				dialog.text = DLG_TEXT[16];
				link.l1 = DLG_TEXT[17];
				link.l1.go = "kill_pirate_completed";
			}
			else
			{
				bool otherquest = false;
				stemp = "";
				if (!CheckAttribute(pchar, "quest.generate_kill_quest") && GetNationRelation2MainCharacter(iNation) != RELATION_ENEMY)
				{
					Preprocessor_Add("gov_nation", XI_ConvertString(GetNationNameByType(iNation)));
					stemp = DLG_TEXT[14];
					link.l1 = DLG_TEXT[15];
					link.l1.go = "kill_pirate";
					otherquest = true;
				}
				if (CheckQuestAttribute("generate_kill_quest", "searching") && PChar.quest.generate_kill_quest.town == GetCurrentTownID())
				{
					dialog.text = DLG_TEXT[189];
					link.l1 = DLG_TEXT[190] + GetShipDescribe("Quest pirate", false, false, true, true) + DLG_TEXT[191];
					link.l1.go = "kill_pirate_give_up";
				}
				//Added by Levis for the smuggler guild
				if (!CheckAttribute(pchar,"quest.smuggling_guild.governor_smuggling") && IsInServiceOf(iNation) && iNation != PIRATE && !CheckAttribute(PChar, "quest.governor_smuggling.recover_cargo") && !CheckAttribute(PChar, "quest.governor_smuggling.recover_money"))
//				if (!CheckAttribute(pchar,"quest.smuggling_guild.governor_quest") && IsInServiceOf(iNation) && iNation != PIRATE)
				{
					islandID = FindIslandByLocation(PChar.location);
					if (islandID != "") smugglegoods = getRandomContrabandGood(GetIslandByID(islandID));
					if (smugglegoods > 0)
					{
						NPChar.quest.smuggle.goods = smugglegoods;
						if(otherquest)	stemp = stemp + DLG_TEXT[81];
						stemp = stemp + DLG_TEXT[82];
						link.l2 = DLG_TEXT[83];
						link.l2.go = "smuggler guild";
						otherquest = true;
					}
				}
				if (!CheckAttribute(PChar, "quest.agentquest") && sti(PChar.PlayerType) == PLAYER_TYPE_AGENT && FindCurrentStoryline() == FindStoryline("FreePlay") && PChar.rank >= 10 && GetCharacterBaseSkill(PChar, SKILL_SNEAK) >= 6)
				{
					if (GetServedNation() == iNation || HaveLetterOfMarque(iNation))
					{
						if(otherquest) stemp = stemp + DLG_TEXT[155];
						stemp = stemp + DLG_TEXT[156];
						link.l3 = DLG_TEXT[157];
						link.l3.go = "agent_quest";
						otherquest = true;
					}
				}
				if (!IsInServiceOf(iNation) && iNation != PERSONAL_NATION) stemp = stemp + " " + DLG_TEXT[102];
				if (otherquest) dialog.text = stemp;
			}
		break;
		
		//Added by Levis for the smugglers guild -->
		case "smuggler guild":
			smugglegoods = sti(GetAttribute(NPChar, "quest.smuggle.goods"));
			smuggleweight = sti(GetAttribute(Goods[smugglegoods], "weight"));
			if (GetSquadronFreeSpace(PChar, smugglegoods)*smuggleweight >= 300)
			{
				NPChar.quest.smuggle.amount = 300/smuggleweight;
				dialog.text = DLG_TEXT[84];
				link.l1 = DLG_TEXT[85];
				link.l1.go = "Smuggler_Accepted";
				link.l2 = DLG_TEXT[86];
				link.l2.go = "Smuggler_Refused";
			}
			else
			{
				DeleteAttribute(NPChar, "quest.smuggle");
				dialog.text = DLG_TEXT[121];
				link.l1 = DLG_TEXT[122];
				link.l1.go = "exit";
			}
		break;
		
		case "Smuggler_Accepted":
			Preprocessor_Add("amount", NPChar.quest.smuggle.amount);
			Preprocessor_Add("cargo", XI_ConvertString(Goods[sti(GetAttribute(NPChar, "quest.smuggle.goods"))].name));
			Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_POLITE, false, false));
			dialog.text = DLG_TEXT[87];
			link.l1 = DLG_TEXT[88];
			link.l1.go = "Smuggler_Accepted_Exit";
		break;
		
		case "Smuggler_Accepted_Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Smuggler Guild Accepted Governor");
			DialogExit();
		break;
		
		case "Smuggler_Refused":
			DeleteAttribute(NPChar, "quest.smuggle");
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Smuggler Guild Refused Governor");
			DialogExit();
		break;
		
		case "FirstSmugglingReport":
			Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_POLITE, false, false));
			dialog.text = DLG_TEXT[90] + DLG_TEXT[91] + 2500 + "." + DLG_TEXT[92];
			link.l1 = DLG_TEXT[88];
			if(CheckCharacterItem(Pchar,"smuggling_papers"))
			{
				link.l1.go = "FirstSmugglingReport2";
			}
			else
			{
				AddDialogExitQuest("Hand in First Smuggling Report");
				link.l1.go = "exit";
			}
		break;
		
		case "FirstSmugglingReport2":
			Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_POLITE, false, false));
			dialog.text = DLG_TEXT[108];
			link.l1 = DLG_TEXT[109];
			AddDialogExitQuest("Hand in First Smuggling Report");
			link.l1.go = "exit";
		break;
		
		case "BuyersList":
			AddDialogExitQuest("Hand in Buyers List");
			Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_POLITE, false, false));
			dialog.text = DLG_TEXT[93] + DLG_TEXT[91] + 1500 + "." + DLG_TEXT[92];
			link.l1 = DLG_TEXT[88];
			link.l1.go = "exit";
		break;
		
		case "SecondSmugglingReport":
			AddDialogExitQuest("Hand in Second Smuggling Report");
			Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_POLITE, false, false));
			dialog.text = DLG_TEXT[94] + DLG_TEXT[91] + 3500 + "." + DLG_TEXT[92];
			link.l1 = DLG_TEXT[88];
			link.l1.go = "exit";
		break;
		
		case "FinalReport":
			dialog.text = DLG_TEXT[96];
			link.l1 = DLG_TEXT[97];
			link.l1.go = "exit";
			AddDialogExitQuest("Hand in Final Smuggling Report");
		break;
		
		//Added by Levis for the smugglers guild <--

		// Added by Grey Roger for smuggling for governor -->

		case "smuggling_check_cargo":
			Preprocessor_Add("amount", NPChar.quest.smuggle.amount);
			Preprocessor_Add("cargo", XI_ConvertString(Goods[sti(GetAttribute(NPChar, "quest.smuggle.goods"))].name));
			Preprocessor_Add("addr", GetMyAddressForm(NPChar, PChar, ADDR_TITLE, false, false));
			if(CheckAttribute(PChar, "quest.smuggling_guild.governor_smuggling.arrested")) stemp = DLG_TEXT[124];
			else stemp = DLG_TEXT[90];
			stemp = stemp + DLG_TEXT[125];
			if (GetSquadronGoods(PChar, sti(PChar.quest.smuggling_guild.governor_smuggling.goods)) >= sti(PChar.quest.smuggling_guild.governor_smuggling.amount))
			{
				stemp = stemp + DLG_TEXT[126];
				dialog.text = stemp;
				link.l1 = DLG_TEXT[127];
				RemoveCharacterGoods(PChar, sti(PChar.quest.smuggling_guild.governor_smuggling.goods), sti(PChar.quest.smuggling_guild.governor_smuggling.amount));
			}
			else
			{
				stemp = stemp + DLG_TEXT[128];
				dialog.text = stemp;
				link.l1 = DLG_TEXT[129];
				AddDialogExitQuest("governor_smuggling_recover_cargo");
				PChar.quest.governor_smuggling.recover_cargo = true;
				PChar.quest.governor_smuggling.recover_cargo.goods = PChar.quest.smuggling_guild.governor_smuggling.goods;
				PChar.quest.governor_smuggling.recover_cargo.amount = PChar.quest.smuggling_guild.governor_smuggling.amount;
				PChar.quest.governor_smuggling.recover_cargo.governor = NPChar.id;
				PChar.quest.governor_smuggling.recover_cargo.nation = NPChar.nation;
			}
			if (sti(GetAttribute(PChar, "quest.smuggling_guild.governor_smuggling.money")) > 0)
			{
				NPChar.quest.cargo_checked = true;
				link.l1.go = "smuggling_check_money";
			}
			else
			{
				if (CheckAttribute(PChar, "quest.governor_smuggling.recover_cargo"))
				{
					if(CheckCharacterItem(Pchar,"smuggling_papers"))
					{
						link.l1.go = "FirstSmugglingReport2";
					}
					else
					{
						AddDialogExitQuest("Hand in First Smuggling Report");
						link.l1.go = "exit";
					}
					if (!CheckAttribute(NPChar, "original_TempNode")) NPChar.original_TempNode = NextDiag.TempNode;
					NextDiag.TempNode = "smuggling_return_cargo";
				}
				else
				{
					link.l1.go = "smuggling_reward";
				}
			}
		break;

		case "smuggling_check_money":
			smugglemoney = sti(PChar.quest.smuggling_guild.governor_smuggling.money);
			Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_POLITE, false, false));
			Preprocessor_Add("money", PChar.quest.smuggling_guild.governor_smuggling.money);
			if (CheckAttribute(NPChar, "quest.cargo_checked"))
			{
				stemp = DLG_TEXT[131];
				DeleteAttribute(NPChar, "quest.cargo_checked")
			}
			else
			{
				if(CheckAttribute(PChar, "quest.smuggling_guild.governor_smuggling.arrested")) stemp = DLG_TEXT[124];
				else stemp = DLG_TEXT[90];
				stemp = stemp + DLG_TEXT[130];
			}
			dialog.text = stemp;
			if(sti(PChar.money) >= smugglemoney)
			{
				PlayStereoSound("INTERFACE\took_item.flac");
				AddMoneyToCharacter(PChar, -1 * smugglemoney);
				link.l1 = DLG_TEXT[132];
				if (CheckAttribute(PChar, "quest.governor_smuggling.recover_cargo"))
				{
					if(CheckCharacterItem(PChar,"smuggling_papers"))
					{
						link.l1.go = "FirstSmugglingReport2";
					}
					else
					{
						AddDialogExitQuest("Hand in First Smuggling Report");
						link.l1.go = "exit";
					}
					if (!CheckAttribute(NPChar, "original_TempNode")) NPChar.original_TempNode = NextDiag.TempNode;
					NextDiag.TempNode = "smuggling_return_cargo";
				}
				else link.l1.go= "smuggling_reward";
			}
			else
			{
				link.l1 = DLG_TEXT[133];
				link.l1.go = "smuggling_owe_money";
			}
		break;

		case "smuggling_owe_money":
			Preprocessor_Add("money", PChar.quest.smuggling_guild.governor_smuggling.money);
			dialog.text = DLG_TEXT[134];
			AddDialogExitQuest("governor_smuggling_recover_money");
			PChar.quest.governor_smuggling.recover_money = true;
			PChar.quest.governor_smuggling.recover_money.amount = PChar.quest.smuggling_guild.governor_smuggling.money;
			PChar.quest.governor_smuggling.recover_money.governor = NPChar.id;
			PChar.quest.governor_smuggling.recover_money.nation = NPChar.nation;
			link.l1 = DLG_TEXT[135];
			if(CheckCharacterItem(PChar,"smuggling_papers"))
			{
				link.l1.go = "FirstSmugglingReport2";
			}
			else
			{
				AddDialogExitQuest("Hand in First Smuggling Report");
				link.l1.go = "exit";
			}
			if (!CheckAttribute(NPChar, "original_TempNode")) NPChar.original_TempNode = NextDiag.TempNode;
			NextDiag.TempNode = "smuggling_return_money";
		break;

		case "smuggling_return_cargo":
			Preprocessor_Add("amount", PChar.quest.governor_smuggling.recover_cargo.amount);
			Preprocessor_Add("cargo", XI_ConvertString(Goods[sti(GetAttribute(PChar, "quest.governor_smuggling.recover_cargo.goods"))].name));
			dialog.text = DLG_TEXT[143];
			if (GetSquadronGoods(PChar, sti(PChar.quest.governor_smuggling.recover_cargo.goods)) >= sti(PChar.quest.governor_smuggling.recover_cargo.amount))
			{
				link.l1 = DLG_TEXT[144];
				link.l1.go = "smuggling_return_cargo2";
			}
			else
			{
				link.l1 = DLG_TEXT[145];
				link.l1.go = "smuggling_still_not_returned";
			}
		break;

		case "smuggling_return_cargo2":
			RemoveCharacterGoods(PChar, sti(PChar.quest.governor_smuggling.recover_cargo.goods), sti(PChar.quest.governor_smuggling.recover_cargo.amount));
			DeleteAttribute(PChar, "quest.governor_smuggling.recover_cargo");	// Wipe the attributes which say you owe the governor some cargo
			PChar.quest.governor_smuggling_time_up_cargo.over = "yes";		// Cancel the timer which penalises you for not returning cargo
			stemp = DLG_TEXT[146];
			if (CheckAttribute(PChar, "quest.governor_smuggling.recover_money"))	// Check if you also have money to return
			{
				Preprocessor_Add("money", sti(PChar.quest.governor_smuggling.recover_money.amount));
				stemp = stemp + "\n" + DLG_TEXT[148];
				if (sti(PChar.money) >= sti(PChar.quest.governor_smuggling.recover_money.amount))
				{
					link.l1 = DLG_TEXT[149];
					link.l1.go = "smuggling_return_money2";
				}
				else
				{
					if (!CheckAttribute(NPChar, "original_TempNode")) NPChar.original_TempNode = NextDiag.TempNode;
					NextDiag.TempNode = "smuggling_return_money";
					link.l1 = DLG_TEXT[150];
					link.l1.go = "smuggling_still_not_returned";
				}
			}
			else
			{
				Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_POLITE, false, false));
				stemp = stemp + DLG_TEXT[147];
				link.l1 = DLG_TEXT[154];
				link.l1.go = "exit";
				AddDialogExitQuest("close_governor_smuggling");
			}
			dialog.text = stemp;
		break;

		case "smuggling_return_money":
			Preprocessor_Add("money", sti(PChar.quest.governor_smuggling.recover_money.amount));
			dialog.text = DLG_TEXT[148];
			if (sti(PChar.money) >= sti(PChar.quest.governor_smuggling.recover_money.amount))
			{
				link.l1 = DLG_TEXT[149];
				link.l1.go = "smuggling_return_money2";
			}
			else
			{
				if (!CheckAttribute(NPChar, "original_TempNode")) NPChar.original_TempNode = NextDiag.TempNode;
				NextDiag.TempNode = "smuggling_return_money";
				link.l1 = DLG_TEXT[150];
				link.l1.go = "smuggling_still_not_returned";
			}
		break;

		case "smuggling_return_money2":
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(PChar, -1 * sti(PChar.quest.governor_smuggling.recover_money.amount));
			DeleteAttribute(PChar, "quest.governor_smuggling.recover_money");	// Wipe the attributes which say you owe the governor some money
			PChar.quest.governor_smuggling_time_up_money.over = "yes";		// Cancel the timer which penalises you for not returning money
			stemp = DLG_TEXT[151];
			if (CheckAttribute(PChar, "quest.governor_smuggling.recover_cargo"))	// Check if you also have cargo to return
			{
				Preprocessor_Add("amount", PChar.quest.governor_smuggling.recover_cargo.amount);
				Preprocessor_Add("cargo", XI_ConvertString(Goods[sti(GetAttribute(PChar, "quest.governor_smuggling.recover_cargo.goods"))].name));
				stemp = stemp + DLG_TEXT[143];
				if (GetSquadronGoods(PChar, sti(PChar.quest.governor_smuggling.recover_cargo.goods)) >= sti(PChar.quest.governor_smuggling.recover_cargo.amount))
				{
					link.l1 = DLG_TEXT[144];
					link.l1.go = "smuggling_return_cargo2";
				}
				else
				{
					link.l1 = DLG_TEXT[145];
					link.l1.go = "smuggling_still_not_returned";
					if (!CheckAttribute(NPChar, "original_TempNode")) NPChar.original_TempNode = NextDiag.TempNode;
					NextDiag.TempNode = "smuggling_return_cargo";
				}
			}
			else
			{
				Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_POLITE, false, false));
				stemp = stemp + DLG_TEXT[147];
				link.l1 = DLG_TEXT[154];
				link.l1.go = "exit";
				AddDialogExitQuest("close_governor_smuggling");
			}
			dialog.text = stemp;
		break;

		case "smuggling_still_not_returned":
			Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_POLITE, false, false));
			dialog.text = DLG_TEXT[153];
			link.l1 = DLG_TEXT[154];
			link.l1.go = "exit";
		break;

		case "smuggling_reward":
			int final_reward;
			string smuggling_reward;
			smugglemoney = sti(PChar.quest.smuggling_guild.governor_smuggling.money);
			stemp = DLG_TEXT[136];
			if(CheckAttribute(PChar, "quest.smuggling_guild.governor_smuggling.arrested"))
			{
				AddXP(PChar, SKILL_SNEAK, 1000, XP_GROUP_OFFIC);
				stemp = stemp + DLG_TEXT[138];
				final_reward = smugglemoney * arrest_reward / 100;
				smuggling_reward = arrest_reward + DLG_TEXT[139] + final_reward + DLG_TEXT[140];
				ChangeRMRelation(PChar, sti(PChar.quest.smuggling_guild.governor_smuggling.nation), 2);
			}
			else
			{
				AddXP(PChar, SKILL_SNEAK, 500, XP_GROUP_OFFIC);
				stemp = stemp + DLG_TEXT[137];
				final_reward = smugglemoney * base_reward / 100;
				smuggling_reward = base_reward + DLG_TEXT[139] + final_reward + DLG_TEXT[140];
				ChangeRMRelation(PChar, sti(pchar.quest.smuggling_guild.governor_quest.nation), 1);
			}
			if (final_reward < minimum_reward)
			{
				final_reward = minimum_reward;
				smuggling_reward = DLG_TEXT[141] + final_reward + DLG_TEXT[142];
			}
			stemp = stemp + smuggling_reward;
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(PChar, final_reward);
			Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_POLITE, false, false));
			dialog.text = stemp;
			link.l1 = DLG_TEXT[88];
			if(CheckCharacterItem(PChar,"smuggling_papers"))
			{
				link.l1.go = "FirstSmugglingReport2";
			}
			else
			{
				AddDialogExitQuest("Hand in First Smuggling Report");
				link.l1.go = "exit";
			}	
		break;

		// <-- Added by Grey Roger for smuggling for governor

		case "kill_pirate":
			GenerateQuestShip("Quest pirate", iNation); // PB: Use Generic Function
			dialog.text = DLG_TEXT[18] + GetShipDescribe("Quest pirate", true, true, true, true) + DLG_TEXT[21] + FindIslandName(pchar.quest.generate_kill_quest.destination) + DLG_TEXT[22] + pchar.quest.generate_kill_quest.money + DLG_TEXT[23]; // KK
			link.l1 = DLG_TEXT[24];
			link.l1.go = "kill_pirate_agree";
			link.l2 = DLG_TEXT[25];
			link.l2.go = "kill_pirate_refused";
		break;

		case "kill_pirate_agree":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("kill_pirate_agree");
		break;

		case "kill_pirate_refused":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("kill_pirate_refused");
		break;

		case "kill_pirate_completed":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 15);
			}
			else { AddPartyExp(pchar, 1500); }
		    PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(pchar, makeint(pchar.quest.generate_kill_quest.money));
			AddDialogExitQuest("kill_pirate_refused_2");
			ChangeCharacterReputation(pchar, 1);
			// PB: Add relation points -->
			float points  = stf(GetAttribute(CharacterFromID("Quest pirate"), "Points"));
			if (points < 1.0) points = 1.0;
			ChangeRMRelation(pchar, iNation, points);
			AttackRMRelation(pchar, sti(pchar.quest.generate_kill_quest.nation) );
			// PB: Add relation points <--
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			pchar.quest.generate_kill_quest = "wait_timer";
		break;

		case "kill_pirate_give_up":
			Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_POLITE, false, false));
			dialog.text = DLG_TEXT[192] + GetShipDescribe("Quest pirate", false, false, true, true) + DLG_TEXT[193];
			link.l1 = DLG_TEXT[154];
			AddDialogExitQuest("kill_pirate_failed");
			link.l1.go = "exit";
			ChangeRMRelation(PChar, iNation, -1.0);
		break;
// boal <--

// PB -->
		case "reset_forts":
			if (GetRMRelation(PChar, iNation) >= REL_NEUTRAL)
			{
				NPChar.resetCost = 0;
				dialog.Text = DLG_TEXT[101];
				Link.l2 = DLG_TEXT[60];
				Link.l2.go = "exit_reset";
			}
			else
			{
				NPChar.resetCost = -makeint(RMAmnestyCost(PChar, iNation)/10);
				dialog.Text = DLG_TEXT[99] + NPChar.resetCost + DLG_TEXT[100];
				Link.l1 = DLG_TEXT[36];
				Link.l1.go = "exit";
				if (GetCharacterMoney(PChar) >= sti(NPChar.resetCost))
				{
					Link.l2 = DLG_TEXT[54];
					Link.l2.go = "exit_reset";
				}
			}
		break;

		case "exit_reset":
			ResetForts(iNation);
			if (sti(NPChar.resetCost) > 0)
			{
				PlayStereoSound("INTERFACE\took_item.flac");
				AddMoneyToCharacter(pchar, -sti(NPChar.resetCost));
			}
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "relationbook":
			GiveItem2Character(pchar, "relationbook");
			PChar.Got_Relation_Book = true;
			dialog.Text = DLG_TEXT[78];
			if (IsInServiceOf(iNation))		Link.l1 = DLG_TEXT[79];
			else					Link.l1 = DLG_TEXT[60];
			Link.l1.go = "international relations";
		break;

		case "restore_ship":
			float relch = RequiredNextRankDirect(GetRank(PChar, iNation)+1) - RequiredNextRankDirect(GetRank(PChar, iNation));
			if (GetRMRelation(PChar, iNation) - relch < 0.0)
			{
				dialog.Text = DLG_TEXT[106];
				Link.l1 = DLG_TEXT[107];
				Link.l1.go = "leavec";
			}
			else
			{
				GiveShip2Character(pchar,pchar.lost.ship.type,GetRandomShipNameForNation(iNation),-1,iNation,true,true);
				DeleteAttribute(pchar, "lost.ship.type");
				ChangeRMRelation(PChar, iNation, -relch);

				Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_POLITE, false, false));
				dialog.Text = DLG_TEXT[104];
				Link.l1 = DLG_TEXT[105];
				Link.l1.go = "Exit";
			}
		break;
// PB <--

// KK -->
		case "international relations":
			stemp = GetHostileNations(iNation);
			if (stemp != "")
				stemp = DLG_TEXT[39] + DLG_TEXT[40] + stemp + DLG_TEXT[42] + DLG_TEXT[43];
			else
				stemp = DLG_TEXT[39] + DLG_TEXT[41] + DLG_TEXT[43];
			dialog.Text = stemp;
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "exit";
		break;

		case "Colony_management":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			LaunchCaptureColony(PChar, GetCurrentTownID());
		break;
// <-- KK

// GR -->
		case "executions_warning":
			PChar.executions_warned = true;	// Note the fact that you have been warned
			PChar.executions = 0;		// Reset counter so you aren't punished again unless you've been executing more prisoners
			SetRMRelation(PChar, iNation, RequiredNextRankDirect(GetRank(PChar, iNation)));	// Reset relation points to base level for current rank
			PlaySound("INTERFACE\notebook_01.wav");
			Preprocessor_Add("nationdesc", XI_ConvertString(GetNationDescByType(iNation)));
			Preprocessor_Add("nation", XI_ConvertString(GetNationNameByType(iNation)));
			sLogTitle = GetTranslatedLog("Prisoner Executions");
			sLogEntry = GetTranslatedLog("The #snationdesc# government did not take kindly to my treatment of prisoners. I had better stop executing them if I want to remain in the service of #snation#.");
			WriteNewLogEntry(PreprocessText(sLogTitle),PreprocessText(sLogEntry), "Personal", true);
			Preprocessor_Delete("nationdesc");
			Preprocessor_Delete("nation");
			dialog.text = DLG_TEXT[118];
			if (GetLetterOfMarqueQuantity() > 1) dialog.text = DLG_TEXT[118] + DLG_TEXT[119];
			link.l1 = DLG_TEXT[120];
			link.l1.go = "exit";
		break;

		case "agent_quest":
			int My_Nation = sti(NPChar.nation);
			int Enemy_Nation = FindEnemyNation2Nation(My_Nation);
			if (Enemy_Nation == PIRATE) Enemy_Nation = FindEnemyNation2Nation(My_Nation); // Make Pirate targets less likely
			PChar.quest.agentquest.enemy_nation = Enemy_Nation;
			if (GetCurrentPeriod() == PERIOD_EARLY_EXPLORERS)
			{
				if (My_Nation == SPAIN || My_Nation == PORTUGAL)
				{
					PChar.quest.agentquest.port1 = "Tortuga_port";
					PChar.quest.agentquest.port2 = "QC_port";
				}
				else
				{
					PChar.quest.agentquest.port1 = "Cuba_port";
					PChar.quest.agentquest.port2 = "Muelle_port";
				}
			}
			else
			{
				switch(Enemy_Nation)
				{
					case ENGLAND:
						PChar.quest.agentquest.port1 = "Antigua_port";
						PChar.quest.agentquest.port2 = "REDMOND_PORT";
					break;

					case FRANCE:
						PChar.quest.agentquest.port1 = "Marigot_port";
						PChar.quest.agentquest.port2 = "PoPrince_Port";
					break;

					case SPAIN:
						PChar.quest.agentquest.port1 = "Cuba_port";
						PChar.quest.agentquest.port2 = "Muelle_port";
					break;

					case PIRATE:
						PChar.quest.agentquest.port1 = "Tortuga_port";
						PChar.quest.agentquest.port2 = "QC_port";
					break;

					case HOLLAND:
						PChar.quest.agentquest.port1 = "Willemstad_port";
						PChar.quest.agentquest.port2 = "Douwesen_port";
					break;

					case PORTUGAL:
						int Friend_nation = FindFriendlyNation2Nation(PORTUGAL);
						if (Friend_nation == PORTUGAL) Friend_nation = FindFriendlyNation2Nation(PORTUGAL);
						switch(Friend_nation)
						{
							case ENGLAND:	PChar.quest.agentquest.port1 = "REDMOND_PORT"; break;
							case FRANCE:	PChar.quest.agentquest.port1 = "Marigot_port"; break;
							case SPAIN:	PChar.quest.agentquest.port1 = "Muelle_port"; break;
							case HOLLAND:	PChar.quest.agentquest.port1 = "Willemstad_port"; break;
							case AMERICA:	PChar.quest.agentquest.port1 = "Eleuthera_Port"; break;
							PChar.quest.agentquest.port1 = "QC_port";
						}
						PChar.quest.agentquest.port2 = "Conceicao_port";
						if (GetCurrentPeriod() < PERIOD_REVOLUTIONS && Friend_nation == SWEDEN) PChar.quest.agentquest.port1 = "QC_port";
					break;

					case GUEST1_NATION:
						if (GetCurrentPeriod() >= PERIOD_REVOLUTIONS)
						{
							PChar.quest.agentquest.port1 = "Eleuthera_Port";
							PChar.quest.agentquest.port2 = "Alice_Port";
						}
						else
						{
							PChar.quest.agentquest.port1 = "Tortuga_port";
							PChar.quest.agentquest.port2 = "QC_port";
						}
					break;
					PChar.quest.agentquest.port1 = "Tortuga_port";
					PChar.quest.agentquest.port2 = "QC_port";
				}
			}
			string town1, town1_name, island1, island1_name;
			town1 = GetTownIDFromLocID(PChar.quest.agentquest.port1);
			town1_name = FindTownName(town1);
			island1 = GetIslandIDFromTown(town1);
			island1_name = FindIslandName(island1);
			PChar.quest.agentquest = "accepted";
			PChar.quest.agentquest.governor = NPChar.id;
			PChar.quest.agentquest.enemy_ship.type = GetShipID(Force_GetShipType(4, 6, "War", Enemy_Nation));
			PChar.quest.agentquest.enemy_ship.name = GetRandomShipNameForNation(Enemy_Nation);
			PChar.quest.agentquest.town1 = town1;
			Characters[GetCharacterIndex("TQ_Captain1")].nation = Enemy_Nation;
			GiveShip2Character(CharacterFromID("TQ_Captain1"), PChar.quest.agentquest.enemy_ship.type, PChar.quest.agentquest.enemy_ship.name, -1, Enemy_Nation, true, true);

			PChar.quest.agentquest.original_flag = GetCurrentFlag();
			PChar.quest.agentquest.original_location_from_sea = PChar.location.from_sea;
//			PChar.quest.agentquest.original_town = GetTownIDFromLocID(PChar.location.from_sea);
			PChar.quest.agentquest.original_town = GetCurrentTownID();
			PChar.quest.agentquest.original_island = GetIslandIDFromTown(PChar.quest.agentquest.original_town);

			dialog.text = DLG_TEXT[158] + PChar.quest.agentquest.enemy_ship.name + DLG_TEXT[159] + GetShipDescribe("TQ_Captain1", true, false, false, false) + DLG_TEXT[160] + town1_name + DLG_TEXT[161] + island1_name + DLG_TEXT[162];
			link.l1 = DLG_TEXT[163] + PChar.quest.agentquest.enemy_ship.name + DLG_TEXT[164];
			link.l1.go = "agent_quest2";
		break;

		case "agent_quest2":
			dialog.text = DLG_TEXT[165];
			link.l1 = DLG_TEXT[166] + PChar.quest.agentquest.town1 + DLG_TEXT[167];
			link.l1.go = "exit_AgentQuest_setup";
			link.l2 = DLG_TEXT[168];
			link.l2.go = "exit_AgentQuest_refused";
		break;

		case "agent_quest_return":
			dialog.text = DLG_TEXT[169];
			link.l1 = DLG_TEXT[170] + PChar.quest.agentquest.enemy_ship.name + DLG_TEXT[171] + FindTownName(GetTownIDFromLocID(PChar.quest.agentquest.port1)) + DLG_TEXT[172] + FindTownName(GetTownIDFromLocID(PChar.quest.agentquest.port2)) + DLG_TEXT[173];
			link.l1.go = "agent_quest_return2";
			TakeItemFromCharacter(PChar, "plans_copy");
		break;

		case "agent_quest_return2":
			dialog.text = DLG_TEXT[174];
			if (GetNationRelation(sti(NPChar.nation), sti(PChar.quest.agentquest.enemy_nation)) == RELATION_ENEMY)
			{
				dialog.text = dialog.text + DLG_TEXT[175] + XI_ConvertString(GetNationDescByType(sti(PChar.quest.agentquest.enemy_nation))) + DLG_TEXT[176];
			}
			else
			{
				dialog.text = dialog.text + DLG_TEXT[177] + GetNationNameByType(sti(NPChar.nation)) + DLG_TEXT[178] + GetNationNameByType(sti(PChar.quest.agentquest.enemy_nation)) + DLG_TEXT[179] + GetNationNameByType(sti(PChar.quest.agentquest.enemy_nation)) + DLG_TEXT[180];
			}
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(PChar, 20000);
			if(AUTO_SKILL_SYSTEM) AddPartyExpChar(PChar, "Sneak", 10000);
			else AddPartyExpChar(PChar, "", 10000);
			ChangeRMRelation(PChar, iNation, 5);
			if (!CheckAttribute(PChar, "quest.agentquest.smuggler_fare") || sti(PChar.quest.agentquest.smuggler_fare) == 0)
			{
				link.l1 = DLG_TEXT[188];
				AddDialogExitQuest("Agentquest_return_ships_and_officers");
				link.l1.go = "exit";
			}
			else
			{
				link.l1 = DLG_TEXT[181];
				link.l1.go = "agent_quest_expenses";
			}

			PChar.quest.agentquest = "completed";
		break;

		case "agent_quest_expenses":
			dialog.text = DLG_TEXT[182];
			link.l1 = DLG_TEXT[183] + PChar.quest.agentquest.smuggler_fare + DLG_TEXT[184];
			link.l1.go = "agent_quest_expenses2";
		break;

		case "agent_quest_expenses2":
			int agent_extra_reward = 1000*(GetTownEconomy(GetCurrentTown()) + 3)	// GetTownEconomy ranges from -2 (starving) to +2 (wealthy)
			if (sti(PChar.quest.agentquest.smuggler_fare) >= 20000) agent_extra_reward += sti(PChar.quest.agentquest.smuggler_fare) - 20000;
			else agent_extra_reward += sti(PChar.quest.agentquest.smuggler_fare) / 3;
			dialog.text = DLG_TEXT[185] + 20000 + DLG_TEXT[186] + agent_extra_reward + DLG_TEXT[187];
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(PChar, agent_extra_reward);
			link.l1 = DLG_TEXT[188];
			AddDialogExitQuest("Agentquest_return_ships_and_officers");
			AddDialogExitQuest("Agentquest_prepare_pay_smuggler");
			link.l1.go = "exit";
		break;

		case "exit_AgentQuest_setup":
			AddDialogExitQuest("AgentQuest_setup");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "exit_AgentQuest_refused":
			AddDialogExitQuest("Agentquest_refused");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
// <-- GR
	}
	//Taken from switch so it works in both instances
	if (Dialog.CurrentNode == "Second time" || Dialog.CurrentNode == "First Time")
	{
// KK -->
		if (sti(NPChar.nation) != PERSONAL_NATION)
		{
			if (GetAttribute(npchar, "quest.meeting") == "1")
			{
				// RM -->
				Preprocessor_Add("gov_nation", XI_ConvertString(GetNationDescByType(iNation)));
				if(iNation != PIRATE)
				{
					if (CheckAttribute(PChar, "Got_Relation_Book"))
					{
						Link.l3 = DLG_TEXT[27];
						Link.l3.go =  "international relations";
					}
					else
					{
						Link.l3 = DLG_TEXT[80];
						Link.l3.go =  "relationbook";
					}
				}
				if (GetRMRelation(PChar, iNation) <= REL_WAR) {
					Link.l4 = DLG_TEXT[26];
					Link.l4.go = "amnesty";
				} else {
					if (IsRecognizedByForts(iNation))
					{
						Link.l4 = DLG_TEXT[98];
						Link.l4.go = "reset_forts";
					}
					if (!IsInServiceOf(iNation)) { // PB: was GetRMRelation(PChar,iNation) < REL_NEUTRAL
						if(ProfessionalNavyNation() == UNKNOWN_NATION && iNation != PIRATE)
						{
							Link.l5 = DLG_TEXT[28];
							Link.l5.go = "LoM";
						}
					} else {
						if (SetupMR(&PChar, &NPChar)) {
							dialog.text = GenerateMR(PChar, NPChar);
						}
						if (PromoteCanBe(PChar, iNation) && GetRMRelation(PChar, iNation) > RequiredNextRank(PChar, iNation)) {
							if (GetMusicScheme() == "PGMUS") SetMusicNoPause("music_govreward"); // PG // KK
							if (iNation == PIRATE) link.l5 = DLG_TEXT[112];
							else Link.l5 = DLG_TEXT[29];
							Link.l5.go = "promote";
						}
						if(ProfessionalNavyNation() == iNation && CheckAttribute(PChar, "lost.ship.type") && GetCharacterShipID(PChar) == SHIP_LIFEBOAT)
						{
							Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_POLITE, false, false));
							Link.l6 = DLG_TEXT[103];
							Link.l6.go = "restore_ship";
						}
						if(ProfessionalNavyNation() == UNKNOWN_NATION)
						{
							Link.l7 = PCharRepPhrase(DLG_TEXT[30] + XI_ConvertString(GetNationNameByType(iNation)) + DLG_TEXT[31], DLG_TEXT[32] + XI_ConvertString(GetNationNameByType(iNation)) + ".");
							Link.l7.go = "leave";
						}
					}
				}
			}else{
				npchar.quest.meeting = "1";
			}
		} else {
			Preprocessor_Add("addr1", GetMyAddressForm(NPChar, PCHAR, ADDR_CIVIL, false, false));
			Preprocessor_Add("addr2", GetCharacterAddressForm(NPChar, ADDR_CIVIL, false, false));
			dialog.text = DLG_TEXT[70];
			link.a1 = DLG_TEXT[71];
			link.a1.go = "Colony_management";
			link.l2 = DLG_TEXT[72];
			link.l2.go = "quests";
			link.l3 = DLG_TEXT[73];
			link.l3.go = "exit";
		}
		//Levis if we got something to report, we don't need the quest dialog 
		if(GetAttribute(pchar,"quest.smuggling_guild.governor_smuggling.town") == GetCurrentTownID())
//		if(GetAttribute(pchar,"quest.smuggling_guild.governor_quest.town") == GetCurrentTownID())
		{
			if(CheckCharacterItem(Pchar,"smuggling_first_report"))
			{
				if(CheckAttribute(PChar, "quest.smuggling_guild.governor_smuggling.arrested"))
				{
					link.l2 = DLG_TEXT[123];
				}
				else
				{
					link.l2 = DLG_TEXT[89];
				}
				link.l2.go = "FirstSmugglingReport";
				if (sti(GetAttribute(PChar, "quest.smuggling_guild.governor_smuggling.money")) > 0) link.l2.go = "smuggling_check_money";
				if (!CheckAttribute(PChar, "quest.smuggling_guild.governor_smuggling.goods_left")) link.l2.go = "smuggling_check_cargo";
			}
		}

		if(GetAttribute(pchar,"quest.smuggling_guild.governor_quest.town") == GetCurrentTownID())
		{
			if(CheckCharacterItem(Pchar,"opiumlist") && !CheckAttribute(pchar,"quest.smuggling_guild.governor_quest.gave_buyers_list"))
			{
				link.l2 = DLG_TEXT[89];
				link.l2.go = "BuyersList";
			}
		}
		if(GetAttribute(pchar,"quest.smuggling_guild.governor_quest.town") == GetCurrentTownID())
		{
			if(CheckCharacterItem(Pchar,"smuggling_second_report"))
			{
				link.l2 = DLG_TEXT[89];
				link.l2.go = "SecondSmugglingReport";
			}
		}
		if(CheckGovernorAllInfo())
		{
			link.l2 = DLG_TEXT[95];
			link.l2.go = "FinalReport";
		}
// <-- KK
	}
}
