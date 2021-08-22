// #include "DIALOGS\Enc_Tradepost.h"
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
	int iTest;
	
	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;

	PChar = GetMainCharacter();
	PChar.storekeeper.Idx = -1;//MAXIMUS
	Npchar.nation = Characters[getCharacterIndex("St John's Commander")].nation;
	
	Preprocessor_Add("sir", FirstLetterUp(GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)));

	int bribe = Makeint(GetCharacterShipHP(Pchar)*0.5);

	// PB: Moved above -->
	if (CheckAttribute(pchar, "quest.generate_trade_quest_progress.iQuantityGoods"))
	{
		int iQuantityShipGoods = pchar.quest.generate_trade_quest_progress.iQuantityGoods;
		int iQuestTradeGoods = pchar.quest.generate_trade_quest_progress.iTradeGoods;
	}
	// PB: Moved above <--

	switch(Dialog.CurrentNode)
	{
		case "First time":
			Dialog.defAni = "dialog_stay2";
			Dialog.defCam = "2";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";


			// --> SJG for Jack Sparrow Story
			if (CheckCharacterItem(PChar,"EITC_Passport"))
			{
				d.Text = DLG_TEXT[0];
		        Link.l1 = DLG_TEXT[31] + pchar.lastname + DLG_TEXT[32];
				Link.l1.go = "EITC Trading";
			}
			else
			// <-- SJG
			{
				if (ProfessionalNavyNation() == sti(GetAttribute(NPChar, "nation")))
				{
					d.Text = DLG_TEXT[68] + GetRankName(PChar, sti(GetAttribute(NPChar, "nation"))) + DLG_TEXT[69];
					Link.l1 = DLG_TEXT[70];
					Link.l1.go = "trade";
					Link.l2 = DLG_TEXT[5];
					Link.l2.go = "duty";
					Link.l4 = DLG_TEXT[41];
					Link.l4.go = "exit";
				}
				else
				{
					d.Text = DLG_TEXT[0];
					if(sti(PChar.money)>bribe )
					{
						Link.l0 = DLG_TEXT[1]+bribe+DLG_TEXT[2];
						Link.l0.go = "bribe";
					}
					Link.l1 = DLG_TEXT[3];
					if(GetRMRelation(Pchar, sti(NPChar.nation) ) < REL_NEUTRAL )
					{
						Link.l1.go = "lomfalse";
					} 
					else 
					{
						Link.l1.go = "lomtrue";
					}
					Link.l12 = DLG_TEXT[4];
					Link.l12.go = "deny";
					Link.l2 = DLG_TEXT[5];
					Link.l2.go = "duty";
					Link.l4 = Randswear()+DLG_TEXT[6];
					Link.l4.go = "exit";
				}
				// PB: Able to skip past the Navy difficulties if you have a cargo to deliver -->
				if (CheckQuestAttribute("generate_trade_quest_progress", "begin") || CheckQuestAttribute("generate_trade_quest_progress",  "failed"))
				{
					if (GetSquadronGoods(pchar, iQuestTradeGoods) >= iQuantityShipGoods && pchar.quest.generate_trade_quest_progress.iTradeColony == GetCurrentTownID() && CheckAttribute(PChar, "quest.generate_trade_quest_progress.iTradeExp"))
					{
						link.l3 = DLG_TEXT[48];
						link.l3.go = "generate_quest_2";
					}
				}
				// PB: Able to skip past the Navy difficulties if you have a cargo to deliver <--
			}
		break;

		case "duty":
			if (ProfessionalNavyNation() == sti(GetAttribute(NPChar, "nation")))
			{
				d.Text = DLG_TEXT[71];
				Link.l1 = DLG_TEXT[70];
				Link.l1.go = "trade";
			}
			else
			{
				d.Text = DLG_TEXT[7];
				if(sti(PChar.money)>bribe )
				{
				Link.l0 = DLG_TEXT[1]+bribe+DLG_TEXT[2];
				Link.l0.go = "bribe";
				}
				Link.l1 = DLG_TEXT[3];
				if(GetRMRelation(Pchar, sti(NPChar.nation) ) < REL_NEUTRAL )
				{
				Link.l1.go = "lomfalse";
				}
				else
				{
				Link.l1.go = "lomtrue";
				}
				Link.l3 = Randswear()+DLG_TEXT[6];
				Link.l3.go = "exit";
			}
		break;

		case "lomfalse":
			if(frnd() < 0.7 )
			{
				d.Text = DLG_TEXT[8];
				Link.l99 = Randswear()+DLG_TEXT[9];
				Link.l99.go = "fight";
			}
			else
			{
				d.Text = DLG_TEXT[10];
				link.l1 = DLG_TEXT[11];
				link.l1.go = "trade";
			}
		break;

		case "lomtrue":
			d.Text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "trade";
		break;

		case "deny":
			d.Text = DLG_TEXT[13];
			Link.l1 = DLG_TEXT[14];
			Link.l1.go = "deny2";
			Link.l2 = DLG_TEXT[15];
			Link.l2.go = "exit";
		break;

		case "deny2":
			if(frnd() < 0.3 )
			{
				// DeathDaisy -->
				PreProcessor_Add("GENDERSubj", strupper(GetMyPronounSubj(PChar)));
				PreProcessor_Add("GENDERObj", strupper(GetMyPronounObj(PChar)));
				// DeathDaisy <--
				d.Text = Randswear()+DLG_TEXT[16];
				Link.l99 = Randswear()+DLG_TEXT[17];
				Link.l99.go = "fight";
			}
			else
			{
				d.Text = DLG_TEXT[18];
				link.l1 = DLG_TEXT[19];
				link.l1.go = "trade";
			}
		break;

		case "bribe":
			if(frnd() < 0.2 )
			{
				d.Text = DLG_TEXT[20];
				Link.l99 = Randswear()+DLG_TEXT[21];
				Link.l99.go = "fight";
			}
			else
			{
			AddMoneytoCharacter(Pchar, -bribe);
			d.Text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "trade";
			}
		break;

// --> SJG for Jack Sparrow Story
		case "EITC Trading":
			D.text = DLG_TEXT[23] + pchar.lastname + DLG_TEXT[24];
			Link.l1 = DLG_TEXT[25];
			if (!CheckCharacterItem(Pchar,"Map_Doc_1"))
			{
			Link.l1.go = "EITC Trading2";
			}
			/*if (CheckCharacterItem(Pchar,"Map_Doc_1") && !checkCharacterItem(Pchar, "Map_Doc_2"))
			{
			Link.l1.go = "EITC Trading5";
			}*/
			if (CheckCharacterItem(Pchar,"Map_Doc_1"))// && checkCharacterItem(Pchar, "Map_Doc_2"))
			{
			Link.l1.go = "EITC Trading6";
			}
		break;

		case "EITC Trading2":
			D.text = DLG_TEXT[26];
			Link.l1 = DLG_TEXT[27];
			Link.l1.go = "EITC Trading3";
		break;

		case "EITC Trading3":
			GiveItem2Character(Pchar,"Map_Doc_1");
			pchar.map = "1";
			AddQuestRecord("Beckett","16");
			if (!CheckAttribute(PChar, "quest.got_antigua_goods"))
			{
				PChar.quest.got_antigua_goods = true;
				AddCharacterGoods(PChar, GOOD_CINNAMON, 80);
				AddCharacterGoods(PChar, GOOD_SILK, 80);
			}
			D.text = DLG_TEXT[28];
			Link.l1 = DLG_TEXT[29];
			Link.l1.go = "EITC Trading4";
		break;

		case "EITC Trading4":
			if (GetAttribute(pchar, "compass") == "1" && GetAttribute(pchar, "map") == "1")
			{
				AddQuestRecord("Aztec", 4);
			}
			D.text = DLG_TEXT[30];
			Link.l1 = DLG_TEXT[33];
			Link.l1.go = "EITCtrade";
			Link.l2 =DLG_TEXT[34];
			Link.l2.go = "exit";
		break;

		case "EITC Trading5":
			D.text = DLG_TEXT[26];
			Link.l1 = DLG_TEXT[33];
			Link.l1.go = "EITCtrade";
			Link.l2 =DLG_TEXT[34];
			Link.l2.go = "exit";
		break;

		case "EITC Trading6":
			D.text = DLG_TEXT[35];
			if (!CheckAttribute(PChar, "quest.got_antigua_goods"))
			{
				Link.l1 = DLG_TEXT[36];
				Link.l1.go = "EITC Trading7";
			}
			Link.l2 =DLG_TEXT[33];
			Link.l2.go = "EITCtrade";
			Link.l3 =DLG_TEXT[34];
			Link.l3.go = "exit";
		break;

		case "EITC Trading7":
			D.text = DLG_TEXT[37];
			Link.l1 = DLG_TEXT[33];
			Link.l1.go = "EITCtrade";
			Link.l2 =DLG_TEXT[34];
			Link.l2.go = "exit";
			if (!CheckAttribute(PChar, "quest.got_antigua_goods"))
			{
				PChar.quest.got_antigua_goods = true;
				AddCharacterGoods(PChar, GOOD_CINNAMON, 80);
				AddCharacterGoods(PChar, GOOD_SILK, 80);
			}
		break;
// <-- SJG

// ----------- exits ------------------------
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "trade":
			D.text = DLG_TEXT[38];
			if(TradeCheck(PChar, NPChar, false)) {
			link.l1 = DLG_TEXT[39];
			link.l1.go = "market"; }
			link.l2 = DLG_TEXT[40];
			link.l2.go = "quests";
			link.l3 = DLG_TEXT[41];
			link.l3.go = "exit";
		break;

		case "market":
			dialog.Text = DLG_TEXT[42];
			Link.l1 = DLG_TEXT[43];
			Link.l1.go = "trade_1";
			Link.l2 = DLG_TEXT[44];
			Link.l2.go = "items";
			Link.l3 = DLG_TEXT[45];
			Link.l3.go = "exit";
		break;

		case "trade_1":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			PChar.storekeeper.Idx = sti(NPChar.index);	//MAXIMUS
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
			DialogExit();
			LaunchItemsTrade(NPChar);
		break;
		// <-- ES add to fix trade quest
		case "quests":
			iTest = 0;
			Dialog.text = DLG_TEXT[46];
			if (CheckQuestAttribute("generate_trade_quest_progress", "begin") || CheckQuestAttribute("generate_trade_quest_progress",  "failed"))
			{
				if (GetSquadronGoods(pchar, iQuestTradeGoods) >= iQuantityShipGoods && pchar.quest.generate_trade_quest_progress.iTradeColony == GetCurrentTownID() && CheckAttribute(PChar, "quest.generate_trade_quest_progress.iTradeExp"))
				{
					dialog.text = DLG_TEXT[47];
					link.l1 = DLG_TEXT[48];
					link.l1.go = "generate_quest_2";
				}
			}
			else
			{
				if (!CheckQuestAttribute("generate_trade_quest_progress", "begin"))
				{
					link.l1 = DLG_TEXT[49];
					link.l1.go = "generate_quest";
				}
			}
			link.l2 = DLG_TEXT[50];
			Link.l2.go = "exit";
		break;

		case "generate_quest":
			if(!CheckAttribute(npchar,"quest.trade_date")) npchar.quest.trade_date = ""; // added by MAXIMUS
			if(npchar.quest.trade_date != lastspeak_date)
			{
				npchar.quest.trade_date = lastspeak_date;
				//проверка враждебности нам страны торговца
				if (GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY) // KK
				{
					dialog.text = DLG_TEXT[51];
					link.l1 = DLG_TEXT[52];
					link.l1.go = "exit";
				}
				else
				{
					int iTradeNation = GenerateNationTrade(sti(NPChar.nation)); // KK
					if (iTradeNation < 0)
					{
						dialog.text = DLG_TEXT[53];
						link.l1 = DLG_TEXT[54];
						link.l1.go = "exit";
					}
					else
					{
						//проверяем импорт/экспорт
						float fprice, tprice;
						// NK redo this to take price into account 05-05-12 -->
						int iTradeGoods = GenerateGoodForTrade(sti(NPChar.nation), iTradeNation, &fprice, &tprice); // KK
						string sNation = GenerateTradeQuest(pchar, iTradeNation, iTradeGoods, fprice, tprice, true);// MAXIMUS: all was moved into MAXIMUS_Functions.c - returns translated string
						//проверяем свободное место (при этом должно вмещаться по меньшей мере 100 единиц выбранного груза
						if (GetSquadronFreeSpace(pchar, iTradeGoods) < 100 || sNation=="")
						{
							dialog.text = DLG_TEXT[55];
							link.l1 = DLG_TEXT[56];
							link.l1.go = "exit";
						}
						else
						{
							dialog.text = DLG_TEXT[57] + sNation + DLG_TEXT[58] + pchar.quest.generate_trade_quest_progress.iMoney + DLG_TEXT[59];
							link.l1 = XI_ConvertString("quest_map");
							link.l1.go = "exit_map";
							link.l2 = DLG_TEXT[60];
							link.l2.go = "exit_trade";
							link.l3  = DLG_TEXT[61];
							link.l3.go = "exit";
						}
					}
				}
			}
			else
			{
				dialog.text = DLG_TEXT[62];
				link.l1 = DLG_TEXT[63];
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
			link.l1 = DLG_TEXT[60];
			link.l1.go = "exit_trade";
			link.l2 = XI_ConvertString("quest_map");
			link.l2.go = "exit_map";
			link.l3  = DLG_TEXT[61];
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
				dialog.text = DLG_TEXT[64];
				link.l1 = DLG_TEXT[65];
				link.l1.go = "exit";
				ChangeCharacterReputation(pchar, -1);
				// PB: Enable Future Ones -->
				RemoveCharacterGoods(PChar, makeint(PChar.quest.generate_trade_quest_progress.iTradeGoods), makeint(PChar.quest.generate_trade_quest_progress.iQuantityGoods));
				DeleteAttribute(pchar,"quest.generate_trade_quest_progress");
				// PB: Enable Future Ones <--
			}
			else
			{
				dialog.text = DLG_TEXT[66] + GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false) + "."; // DeathDaisy: changed "young man" to "my good man/woman" since player isn't always young
				link.l1 = DLG_TEXT[67];
				link.l1.go = "exit";
				ChangeCharacterReputation(pchar, 1);
				TradeQuestDone();
			}
			AddDialogExitQuest("close_trade_quest");
		break;

		case "no_quests":
			D.text = DLG_TEXT[41];
			Link.l1 = DLG_TEXT[42];
			Link.l1.go = "node_1";
		break;
		// <-- ES add to fix trade quest
		case "fight":
			PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_039.wav");
			LAi_group_SetRelation(NPchar.chr_ai.group, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			Ambush("navy", 3, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "");
			//Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

// -->SJG for Jack Sparrow Story
		case "EITCtrade":
			//Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			PChar.storekeeper.Idx = sti(NPChar.index);//MAXIMUS
			LaunchStore(GetCurrentStore(NPChar.location));
		break;
// <-- SJG

	}
}
