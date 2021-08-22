void ProcessDialogEvent()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	PChar.storekeeper.Idx = -1;//MAXIMUS
	aref Link, Diag;
	string NPC_Meeting;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------  -  
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "trade":
			dialog.snd = "Voice\ALMI\ALMI001";
			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "trade_1";
			Link.l2 = DLG_TEXT[2];
			Link.l2.go = "items";
			Link.l3 = DLG_TEXT[3];
			Link.l3.go = "exit";
		break;

		case "trade_1":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			PChar.storekeeper.Idx = sti(NPChar.index);//MAXIMUS
			LaunchStore(GetCurrentStore(NPChar.location));
		break;

		case "items":
			if (!CheckAttribute(npchar, "quest.item_date") || npchar.quest.item_date != lastspeak_date)
			// PB: Prevent error
			{
				GiveItemToTrader(npchar);
				npchar.quest.item_date = lastspeak_date;
			}
			
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			LaunchItemsTrade(NPChar);
		break;

		case "First time":
			Dialog.defAni = "dialog_stay2";
			Dialog.defCam = "2";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			if(TradeCheck(PChar, NPChar, true)) { // NK

			if(NPChar.quest.meeting == "0")
			{
				dialog.snd = "Voice\ALMI\ALMI002";
				d.Text = DLG_TEXT[4] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[5];
				Link.l1 = DLG_TEXT[6] + GetMyFullName(PChar) + DLG_TEXT[7]; /*GetMyFullName(PChar)*/
				Link.l1.go = "meeting";
				NPC_Meeting = "1";
			}
			else
			{
				dialog.snd1 = "Voice\ALMI\ALMI003";
				dialog.snd2 = "Voice\ALMI\ALMI004";
				dialog.snd3 = "Voice\ALMI\ALMI005";
				// Ah, I meant model in terms of what is the resultant phrase, i.e. write "he" or "she" as the model, and you'll get the gender-appropriate version. Shoulda picked a better variable name than model... :\ ( :kev )
				// so if you wanted him/her, you could write GetMyPronoun(PChar, "her")
				// You could also call the appropriate function (GetMyPronounSubj() for he/she), but I for sure can't remember what the real names of the pronouns are, so I wrote the above as a shortcut. :]
				
				// Also it appears the randphrase will have as the three choices:
				//a. Why, forsooth!  My dear 
				//b. !  Pleased to see you.  Shall we trade? + pronoun + What goods have you brought us this time, captain?
				//c. Ah, captain!  Pray, what can I do for you?
				//so I think what you meant was:
				//RandPhrase(DLG_TEXT[8] + GetSomeAddress(NPChar, PChar) + DLG_TEXT[9], DLG_TEXT[10], DLG_TEXT[11], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				// with the first two (8,9) chained together with an address and 10 and 11 standing alone.
				// I don't know what form of address you'd want--with "my dear" it would presumably be anything but the insulting/hostile ones... (and excepting courting, because there's already a my in those)
				// Or even just the pchar's first name alone, rather than something compound or a title.
				// But let's assume you want 'imptitle' address. Line would be:
				d.Text = RandPhrase(DLG_TEXT[8] + GetMyAddressForm(NPChar, PChar, ADDR_IMPTITLE, false, false) + DLG_TEXT[9], DLG_TEXT[10], DLG_TEXT[11], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				// imptitle is 'impersonal title'--for lack of a better term; feel free to change it here and any references in dlg_func.c. What I mean by it, per there, is the impersonal use of a title, i.e. sir/madam instead of Mr./Ms.
				if(TradeCheck(PChar, NPChar, false))
				{
					Link.l1 = DLG_TEXT[12];
					if (CheckAttribute(Pchar, "Quest.Story_OxbayCaptured"))
					{
						Link.l1.go = "no trade";
					}
					else
					{
						Link.l1.go = "trade";
					}
				}
				Link.l2 = DLG_TEXT[13];
				Link.l2.go = "quest lines";
				Link.l3 = DLG_TEXT[14];
				Link.l3.go = "exit";
			}
			// NK -->
			}
			else
			{
				// this would be GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) or perhaps more likely ADDR_INSULT. :)
				// could you also put any isolated strings like the below in the H file?
				// so it would read:
				//d.Text = DLG_TEXT[xx] + GetMyAddressForm(NPChar, PChar, ADDR_INSULT, false, false) + DLG_TEXT[yy];
				// with link.l1 = DLG_TEXT[zz]
				dialog.text = DLG_TEXT[53] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[54];
				Link.l1 = DLG_TEXT[55];
				Link.l1.go = "exit";
				if(sti(PChar.Skill.Commerce)>=5)
				{
					Link.l2 = LanguageConvertString(tmpLangFileID,"low_trade_1");
					Link.l2.go = "low_price";
				}
				Diag.TempNode = "First time";
			}
			// NK <--
		break;

		case "low_price":
			dialog.text = LanguageConvertString(tmpLangFileID,"low_trade_2");
			link.l1 = LanguageConvertString(tmpLangFileID,"low_trade_3");
			link.l1.go = "market_low";
			link.l3 = LanguageConvertString(tmpLangFileID,"low_trade_4");
			link.l3.go = "exit";
			Diag.TempNode = "First time";
		break;

		case "market_low":
			dialog.Text = LanguageConvertString(tmpLangFileID,"low_trade_5");
			Link.l1 = LanguageConvertString(tmpLangFileID,"low_trade_6");
			Link.l1.go = "trade_low";
			Link.l3 = LanguageConvertString(tmpLangFileID,"low_trade_4");
			Link.l3.go = "exit";
			Diag.TempNode = "First time";
		break;

		case "trade_low":
			Diag.TempNode = "First time";
			DialogExit();
			tradeLow = true;
			PChar.storekeeper.Idx = sti(NPChar.index);//MAXIMUS
			LaunchStore(GetCurrentStore(NPChar.location));
		break;

		case "Meeting":
			dialog.snd = "Voice\ALMI\ALMI006";
			d.Text = DLG_TEXT[15] + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + DLG_TEXT[16] + GetMyFullName(NPChar) + DLG_TEXT[17]; //NPChar.name + " " + NPChar.lastname 
			if(TradeCheck(PChar, NPChar, false))
			{
				Link.l1 = DLG_TEXT[18] + GetMyName(NPChar) + DLG_TEXT[19];
				if (CheckAttribute(Pchar, "Quest.Story_OxbayCaptured"))
				{
					Link.l1.go = "no trade";
				}
				else
				{
					Link.l1.go = "trade";
				}
			}
			Link.l2 = DLG_TEXT[20] + GetMyName(NPChar) + DLG_TEXT[21];
			Link.l2.go = "quest lines";
			Link.l3 = DLG_TEXT[22];
			Link.l3.go = "exit";
		break;

		case "quest lines":
			dialog.snd = "Voice\ALMI\ALMI007";
			d.Text = DLG_TEXT[23];
			if (CheckAttribute(pchar, "quest.generate_trade_quest_progress.iQuantityGoods"))	// LDH was quest.quest.generate, fixed 01Jan09
			{
				int iQuantityShipGoods = sti(pchar.quest.generate_trade_quest_progress.iQuantityGoods);
				int iQuestTradeGoods = sti(pchar.quest.generate_trade_quest_progress.iTradeGoods);
			}
			if (CheckQuestAttribute("generate_trade_quest_progress", "begin") || CheckQuestAttribute("generate_trade_quest_progress",  "failed"))
			{
				if (pchar.quest.generate_trade_quest_progress.iTradeColony == GetCurrentTownID() && CheckAttribute(PChar, "quest.generate_trade_quest_progress.iTradeExp"))
				{
					dialog.snd = "Voice\EMRI\EMRI006";
					dialog.text = DLG_TEXT[24];
					link.l1 = DLG_TEXT[25];
					if(GetSquadronGoods(pchar, iQuestTradeGoods) >= iQuantityShipGoods)
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
					if(!CheckAttribute(Pchar, "Quest.Story_OxbayCaptured"))
					{
						link.l1 = DLG_TEXT[26];
						link.l1.go = "generate_quest";
					}
				}
			}
			link.l99 = DLG_TEXT[27];
			Link.l99.go = "no quest";
		break;

		case "generate_quest":
			if(!CheckAttribute(npchar,"quest.trade_date")) npchar.quest.trade_date = ""; // added by MAXIMUS
			if(npchar.quest.trade_date != lastspeak_date)
			{
				npchar.quest.trade_date = lastspeak_date;
				//    
				if (GetNationRelation2MainCharacter(GetTownNation(GetTownIDFromLocID(NPChar.location))) == RELATION_ENEMY) // KK
				{
					Preprocessor_Add("nation_desc", GetNationDescByType(sti(NPChar.nation)));
					dialog.snd = "Voice\ALMI\ALMI009";
					dialog.text = DLG_TEXT[28];
					link.l1 = DLG_TEXT[29];
					link.l1.go = "exit";
				}
				else
				{
					int iTradeNation = GenerateNationTrade(GetTownNation(GetTownIDFromLocID(NPChar.location))); // KK
					if (iTradeNation < 0)
					{
						dialog.snd = "Voice\ALMI\ALMI010";
						dialog.text = DLG_TEXT[30];
						link.l1 = DLG_TEXT[31];
						link.l1.go = "exit";
					}
					else
					{
						// /
						float fprice, tprice;
						// NK redo this to take price into account 05-05-12 -->
						int iTradeGoods = GenerateGoodForTrade(GetTownNation(GetTownIDFromLocID(NPChar.location)), iTradeNation, &fprice, &tprice);
						string sNation = GenerateTradeQuest(pchar, iTradeNation, iTradeGoods, fprice, tprice, true);// MAXIMUS: all was moved into MAXIMUS_Functions.c - returns translated string
						if (GetSquadronFreeSpace(pchar, iTradeGoods) < 100 || sNation=="")
						{
							dialog.snd = "Voice\ALMI\ALMI011";
							dialog.text = DLG_TEXT[32];
							link.l1 = DLG_TEXT[33];
							link.l1.go = "exit";
						}
						else
						{
							dialog.snd = "Voice\ALMI\ALMI012";
							dialog.text = DLG_TEXT[34] + sNation + DLG_TEXT[35] + pchar.quest.generate_trade_quest_progress.iMoney + DLG_TEXT[36];
							link.l1 = XI_ConvertString("quest_map");
							link.l1.go = "exit_map";
							link.l2 = DLG_TEXT[37];
							link.l2.go = "exit_trade";
							link.l3  = DLG_TEXT[38];
							link.l3.go = "exit";
						}
					}
				}
			}
			else
			{
				dialog.snd = "Voice\ALMI\ALMI013";
				dialog.text = DLG_TEXT[39];
				link.l1 = DLG_TEXT[40];
				link.l1.go = "exit";
			}
		break;

		case "exit_map":
			Diag.CurrentNode = "after_map";
			DialogExit();
			LaunchPelagoMap();
		break

		case "after_map":
			dialog.snd = "Voice\ALMI\ALMI012";
			dialog.text = XI_ConvertString("quest_talk")+" "+GetMyName(PChar)+"?";
			link.l1 = DLG_TEXT[37];
			link.l1.go = "exit_trade";
			link.l2 = XI_ConvertString("quest_map");
			link.l2.go = "exit_map";
			link.l3  = DLG_TEXT[38];
			link.l3.go = "exit";
		break;
		
		case "exit_trade":
			AddDialogExitQuest("trade_quest_open");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "generate_quest_2":
			if (pchar.quest.generate_trade_quest_progress == "failed")
			{
				dialog.snd = "Voice\ALMI\ALMI014";
				dialog.text = DLG_TEXT[41];
				link.l1 = DLG_TEXT[42];
				link.l1.go = "exit";
				ChangeCharacterReputation(pchar, -1);
				// PB: Enable Future Ones -->
				RemoveCharacterGoods(PChar, makeint(PChar.quest.generate_trade_quest_progress.iTradeGoods), makeint(PChar.quest.generate_trade_quest_progress.iQuantityGoods));
				DeleteAttribute(pchar,"quest.generate_trade_quest_progress");
				// PB: Enable Future Ones <--
			}
			else
			{
				dialog.snd = "Voice\ALMI\ALMI015";
				dialog.text = DLG_TEXT[43] + GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false) + DLG_TEXT[44];
				link.l1 = DLG_TEXT[45];
				link.l1.go = "exit";
				ChangeCharacterReputation(pchar, 1);
				TradeQuestDone();
			}
			AddDialogExitQuest("close_trade_quest");
		break;

		case "No quest":
			dialog.snd = "Voice\ALMI\ALMI016";
			d.Text = DLG_TEXT[46] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, true, false) + DLG_TEXT[47]; // maybe should be lastname, not firstname?
			Link.l1 = DLG_TEXT[48];
			if (CheckAttribute(Pchar, "Quest.Story_OxbayCaptured"))
			{
				Link.l1.go = "no trade";
			}
			else
			{
				Link.l1.go = "trade";
			}
			Link.l2 = DLG_TEXT[49];
			Link.l2.go = "exit";
		break;

		case "No trade":
			dialog.snd = "Voice\ALMI\ALMI017";
			d.Text = DLG_TEXT[50] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, true, false) + DLG_TEXT[51]; // maybe should be lastname, not firstname?
			Link.l1 = DLG_TEXT[52];
			Link.l1.go = "No quest";
		break;

		case "cargo_missing":
			AddQuestRecord("trade", 3);
			Preprocessor_Add("quantity", sti(pchar.quest.generate_trade_quest_progress.iQuantityGoods));
			Preprocessor_Add("cargo", XI_ConvertString(Goods[sti(pchar.quest.generate_trade_quest_progress.iTradeGoods)].name));
			dialog.snd = "Voice\ALMI\ALMI015";
			dialog.text = DLG_TEXT[56];
			link.l1 = DLG_TEXT[57];
			link.l1.go = "exit";
		break;

	}
	LanguageCloseFile(tmpLangFileID);
}
