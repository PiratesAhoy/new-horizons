void ProcessDialogEvent()
{
	ref NPChar;

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

	ref PChar = GetMainCharacter();
	PChar.storekeeper.Idx = -1;//MAXIMUS

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
			
			if (TradeCheck(PChar, NPChar, true))
			{ // NK
				if (npchar.quest.meeting == "0")
				{
					dialog.snd = "Voice\GHDA\GHDA001";
					Dialog.Text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1] + GetMyFullName(NPChar) + DLG_TEXT[2]; // NK
					Link.l1 = DLG_TEXT[3] + GetMyFullName(PChar) + DLG_TEXT[4];
					if (!LAi_IsCapturedLocation)
						link.l1.go = "node_1";
					else
						link.l1.go = "Second time";
				}
				NextDiag.TempNode = "Second time";
			// NK -->
			}
			else
			{
				dialog.text = DLG_TEXT[42] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[43];
				Link.l1 = DLG_TEXT[44];
				Link.l1.go = "exit";
				if(sti(PChar.Skill.Commerce)>=5)
				{
					Link.l2 = TranslateString("","low_trade_1");
					Link.l2.go = "low_price";
				}
				NextDiag.TempNode = "First time";
			}
			// NK <--
		break;

		case "low_price":
			dialog.text = TranslateString("","low_trade_2");
			link.l1 = TranslateString("","low_trade_3");
			link.l1.go = "market_low";
			link.l3 = TranslateString("","low_trade_4");
			link.l3.go = "exit";
			NextDiag.TempNode = "First time";
		break;

		case "market_low":
			dialog.Text = TranslateString("","low_trade_5");
			Link.l1 = TranslateString("","low_trade_6");
			Link.l1.go = "trade_low";
			Link.l3 = TranslateString("","low_trade_4");
			Link.l3.go = "exit";
			NextDiag.TempNode = "First time";
		break;

		case "trade_low":
			NextDiag.TempNode = "First time";
			DialogExit();
			tradeLow = true;
			PChar.storekeeper.Idx = sti(NPChar.index);//MAXIMUS
			LaunchStore(GetCurrentStore(NPChar.location));
		break;

		case "second time":
			if(TradeCheck(PChar, NPChar, true))
			{ // NK
				dialog.snd = pcharrepphrase("Voice\GHDA\GHDA002", "Voice\GHDA\GHDA003");
// KK -->
				if (!LAi_IsCapturedLocation) {
					dialog.text = pcharrepphrase(DLG_TEXT[5] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[6], DLG_TEXT[7]); // NK
					Link.l1 = pcharrepphrase(DLG_TEXT[8] + npchar.name + DLG_TEXT[9], DLG_TEXT[10]); 
					link.l1.go = "node_1";
				}
				else
				{
					dialog.text = DLG_TEXT[69];
					Link.l1 = DLG_TEXT[70]; 
					link.l1.go = "trade_1";
					link.l2 = DLG_TEXT[71];
					link.l2.go = "items";
					link.l4 = DLG_TEXT[73];
					link.l4.go = "exit";
				}
// <-- KK
			// NK -->
			}
			else
			{
				dialog.text = DLG_TEXT[42] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[43];
				Link.l1 = DLG_TEXT[44];
				Link.l1.go = "exit";
			}
			// NK <--
			NextDiag.TempNode = "Second time";
		break;

		case "node_1":
			dialog.snd = "Voice\GHDA\GHDA004";
			dialog.text = DLG_TEXT[11];
			if(TradeCheck(PChar, NPChar, false)) {
			link.l1 = DLG_TEXT[12];
			link.l1.go = "market"; }
			link.l2 = DLG_TEXT[13];
			link.l2.go = "quests";
			link.l3 = DLG_TEXT[14];
			link.l3.go = "exit";
		break;

		case "market":
			dialog.snd = "Voice\GHDA\GHDA005";
			dialog.Text = DLG_TEXT[15];
			Link.l1 = DLG_TEXT[16];
			Link.l1.go = "trade_1";
			Link.l2 = DLG_TEXT[17];
			Link.l2.go = "items";
			Link.l4 = DLG_TEXT[18];
			Link.l4.go = "exit";
		break;

		case "trade_1":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			PChar.storekeeper.Idx = sti(NPChar.index);//MAXIMUS
			LaunchStore(GetCurrentStore(NPChar.location));
		break;

		case "items":
			if (!CheckAttribute(npchar, "quest.item_date") || npchar.quest.item_date != lastspeak_date) // KK
			{
				GiveItemToTrader(npchar);
				npchar.quest.item_date = lastspeak_date;
			}
			
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LaunchItemsTrade(NPChar);
		break;

		case "quests":
			iTest = 0;
			if (CheckAttribute(pchar, "quest.generate_trade_quest_progress.iQuantityGoods"))	// LDH was quest.quest.generate, fixed 01Jan09
			{
				int iQuantityShipGoods = sti(pchar.quest.generate_trade_quest_progress.iQuantityGoods);
				int iQuestTradeGoods = sti(pchar.quest.generate_trade_quest_progress.iTradeGoods);
			}
			if (CheckQuestAttribute("generate_trade_quest_progress", "begin") || CheckQuestAttribute("generate_trade_quest_progress",  "failed"))
			{
				if (pchar.quest.generate_trade_quest_progress.iTradeColony == GetCurrentTownID() && CheckAttribute(PChar, "quest.generate_trade_quest_progress.iTradeExp"))
				{
					dialog.snd = "Voice\GHDA\GHDA006";
					dialog.text = DLG_TEXT[19];
					link.l1 = DLG_TEXT[20];
					if (GetSquadronGoods(pchar, iQuestTradeGoods) >= iQuantityShipGoods)
					{
						link.l1.go = "generate_quest_2";
					}
					else
					{
						link.l1.go = "cargo_missing";
					}
				}
			}
			else
			{
				if (!CheckQuestAttribute("generate_trade_quest_progress", "begin"))
				{
					link.l1 = DLG_TEXT[21];
					link.l1.go = "generate_quest";
				}
			}
			link.l99 = DLG_TEXT[22];
			Link.l99.go = "exit";
		break;

		case "generate_quest":
			if(!CheckAttribute(npchar,"quest.trade_date")) npchar.quest.trade_date = ""; // added by MAXIMUS
			if(npchar.quest.trade_date != lastspeak_date)
			{
				npchar.quest.trade_date = lastspeak_date;
				//проверка враждебности нам страны торговца
				if (GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY) // KK
				{
					Preprocessor_Add("nation_name", GetNationNameByType(sti(NPChar.nation)));
					dialog.snd = "Voice\GHDA\GHDA007";
					dialog.text = DLG_TEXT[23];
					link.l1 = DLG_TEXT[24];
					link.l1.go = "exit";
				}
				else
				{
					int iTradeNation = GenerateNationTrade(sti(NPChar.nation)); // KK
					if (iTradeNation < 0)
					{
						dialog.snd = "Voice\GHDA\GHDA008";
						dialog.text = DLG_TEXT[25];
						link.l1 = DLG_TEXT[26];
						link.l1.go = "exit";
					}
					else
					{
						//проверяем импорт/экспорт
						float fprice, tprice;
						// NK redo this to take price into account 05-05-12 -->
						int iTradeGoods = GenerateGoodForTrade(sti(NPChar.nation), iTradeNation, &fprice, &tprice); // TIH nation fix Aug30'06 // KK
						string sNation = GenerateTradeQuest(pchar, iTradeNation, iTradeGoods, fprice, tprice, true);// MAXIMUS: all was moved into MAXIMUS_Functions.c - returns translated string
						//проверяем свободное место (при этом должно вмещаться по меньшей мере 100 единиц выбранного груза
						if (GetSquadronFreeSpace(pchar, iTradeGoods) < 100 || sNation=="")
						{
							dialog.snd = "Voice\GHDA\GHDA009";
							dialog.text = DLG_TEXT[27];
							link.l1 = DLG_TEXT[28];
							link.l1.go = "exit";
						}
						else
						{
							dialog.snd = "Voice\GHDA\GHDA010";
							dialog.text = DLG_TEXT[29] + sNation + DLG_TEXT[30] + pchar.quest.generate_trade_quest_progress.iMoney + DLG_TEXT[31];
							link.l1 = XI_ConvertString("quest_map");
							link.l1.go = "exit_map";
							link.l2 = DLG_TEXT[32];
							link.l2.go = "exit_trade";
							link.l3  = DLG_TEXT[33];
							link.l3.go = "exit";
						}
					}
				}
			}
			else
			{
				dialog.snd = "Voice\GHDA\GHDA011";
				dialog.text = DLG_TEXT[34];
				link.l1 = DLG_TEXT[35];
				link.l1.go = "exit";
			}
		break;

		case "exit_map":
			NextDiag.CurrentNode = "after_map";
			DialogExit();
			LaunchPelagoMap();
		break

		case "after_map":
			dialog.snd = "Voice\GHDA\GHDA010";
			dialog.text = XI_ConvertString("quest_talk")+" "+GetMyName(PChar)+"?";
			link.l1 = DLG_TEXT[32];
			link.l1.go = "exit_trade";
			link.l2 = XI_ConvertString("quest_map");
			link.l2.go = "exit_map";
			link.l3  = DLG_TEXT[33];
			link.l3.go = "exit";
		break;

		case "exit_trade":
			AddDialogExitQuest("trade_quest_open");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "generate_quest_2":
			if (pchar.quest.generate_trade_quest_progress == "failed")
			{
				dialog.snd = "Voice\GHDA\GHDA012";
				dialog.text = DLG_TEXT[36];
				link.l1 = DLG_TEXT[37];
				link.l1.go = "exit";
				ChangeCharacterReputation(pchar, -1);
				// PB: Enable Future Ones -->
				RemoveCharacterGoods(PChar, makeint(PChar.quest.generate_trade_quest_progress.iTradeGoods), makeint(PChar.quest.generate_trade_quest_progress.iQuantityGoods));
				DeleteAttribute(pchar,"quest.generate_trade_quest_progress");
				// PB: Enable Future Ones <--
			}
			else
			{
				dialog.snd = "Voice\GHDA\GHDA013";
				dialog.text = DLG_TEXT[38] + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + ".";
				link.l1 = DLG_TEXT[39];
				link.l1.go = "exit";
				ChangeCharacterReputation(pchar, 1);
				TradeQuestDone();
			}
			AddDialogExitQuest("close_trade_quest");
		break;

		case "cargo_missing":
			AddQuestRecord("trade", 3);
			Preprocessor_Add("ladlass", GetMyAddressForm(NPChar, PChar, ADDR_INFORMAL, false, false));
			Preprocessor_Add("quantity", sti(pchar.quest.generate_trade_quest_progress.iQuantityGoods));
			Preprocessor_Add("cargo", XI_ConvertString(Goods[sti(pchar.quest.generate_trade_quest_progress.iTradeGoods)].name));
			dialog.snd = "Voice\GHDA\GHDA013";
			dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "exit";
		break;
		
		case "no_quests":
			dialog.snd = "Voice\GHDA\GHDA014";
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "node_1";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
