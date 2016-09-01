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
	if(!CheckAttribute(NPChar, "quest.item_date")) NPChar.quest.item_date = NPChar.quest.meeting;


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

		     // JRH -->
			if(pchar.quest.wr_quest2 == "QC_store_keeper")
			{
				dialog.text = DLG_TEXT[34];
				link.l1 = DLG_TEXT[35];
				link.l1.go = "from_bedroom";	
			}
			else
			{
		     // <-- JRH
				if(TradeCheck(PChar, NPChar)) { // NK
				if (npchar.quest.meeting == "0")
				{
					Dialog.snd = "voice\PEBL\PEBL001";
					Dialog.Text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1] + npchar.name + " " + npchar.lastname + DLG_TEXT[2];
					Link.l1 = DLG_TEXT[3] + GetMyFullName(PChar) + DLG_TEXT[4];
					link.l1.go = "node_1";
				}
				NextDiag.TempNode = "Second time";
				// NK -->
				}
				else
				{
					dialog.text = DLG_TEXT[31] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[32];
					Link.l1 = DLG_TEXT[33];
					Link.l1.go = "exit";
					if(sti(PChar.Skill.Commerce)>=5)
					{
						Link.l2 = TranslateString("","low_trade_1");
						Link.l2.go = "low_price";
					}
					NextDiag.TempNode = "First time";
				}
				// NK <--
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
		     // JRH -->
			if(pchar.quest.wr_quest2 == "QC_store_keeper")
			{
				dialog.text = DLG_TEXT[34];
				link.l1 = DLG_TEXT[35];
				link.l1.go = "from_bedroom";
			}
			else
			{
		     // <-- JRH
				if(TradeCheck(PChar, NPChar)) { // NK
				Dialog.snd = pcharrepphrase("voice\PEBL\PEBL002", "voice\PEBL\PEBL003");
				dialog.text = pcharrepphrase(DLG_TEXT[5] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[6], DLG_TEXT[7]);
				Link.l1 = pcharrepphrase(DLG_TEXT[8] + npchar.name + DLG_TEXT[9], DLG_TEXT[10]); 
				link.l1.go = "node_1";
				// NK -->
				}
				else
				{
					dialog.text = DLG_TEXT[31] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[32];
					Link.l1 = DLG_TEXT[33];
					Link.l1.go = "exit";
				}
				// NK <--
				NextDiag.TempNode = "Second time";
			}
		break;

		case "node_1":
			Dialog.snd = "voice\PEBL\PEBL004";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "trade";
			link.l2 = DLG_TEXT[13];
			link.l2.go = "quests";
			link.l3 = DLG_TEXT[14];
			link.l3.go = "exit";
		break;

		case "trade":
			Dialog.snd = "voice\PEBL\PEBL005";
			dialog.Text = DLG_TEXT[15];
			Link.l1 = DLG_TEXT[16];
			Link.l1.go = "trade_1";
			Link.l2 = DLG_TEXT[17];
			Link.l2.go = "items";
			Link.l3 = DLG_TEXT[18];
			Link.l3.go = "exit";
		break;

		case "trade_1":
			NextDiag.CurrentNode = NextDiag.TempNode;
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
			
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LaunchItemsTrade(NPChar);
		break;

		case "quests":
			iTest = 0;
			Dialog.snd = "voice\PEBL\PEBL006";
			Dialog.text = DLG_TEXT[19];
			Link.l1 = DLG_TEXT[20];
			Link.l1.go = "no_quests";
			if (CheckQuestAttribute("nigel_away_for_ship", "talk_with_clauss"))
			{
				link.l1 = DLG_TEXT[21];
				link.l1.go = "clauss";
			}
		break;
		
		case "clauss":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "clauss_2";
		break;
		
		case "clauss_2":
			dialog.text = DLG_TEXT[24];
			if (makeint(pchar.money >=2632))
			{
				link.l1 = DLG_TEXT[25];
				link.l1.go = "clauss_3";
			}
			link.l2 = DLG_TEXT[26];
			link.l2.go = "exit";
		break;
		
		case "clauss_3":
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "exit";
			AddDialogExitQuest("clauss_to_tavern");
		break;
		
		case "no_quests":
			Dialog.snd = "voice\PEBL\PEBL007";
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "node_1";
		break;

	// JRH -->
		case "from_bedroom":
			PlaySound("VOICE\ENGLISH\Por_m_a_035.wav");
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "from_bedroom_options";
		break;
//--------------------------------------------------------------------------------------------------------------------
		case "from_bedroom_options":
			dialog.text = DLG_TEXT[38];

			if(CheckAttribute(PChar,"qcstore_door") && PChar.qcstore_door == "not_yet")
			{
				link.l1 = DLG_TEXT[39];
				link.l1.go = "option_door";
			}
			
			if(CheckAttribute(PChar,"qcstore_deal") && PChar.qcstore_deal == "no")
			{
				link.l2 = DLG_TEXT[40];
				link.l2.go = "option_no_deal";
			}
			else
			{
				link.l2 = DLG_TEXT[104];
				link.l2.go = "option_deal";//OBS
			}

			if(CheckAttribute(PChar,"qcstore_jump") && PChar.qcstore_jump == "not_yet")
			{
				link.l3 = DLG_TEXT[41];
				link.l3.go = "option_jump";
			}

			if(CheckAttribute(PChar,"qcstore_bedroom") && PChar.qcstore_bedroom == "not_yet")
			{
				link.l4 = DLG_TEXT[42];
				link.l4.go = "option_bedroom";
			}

			link.l5 = DLG_TEXT[43];
			link.l5.go = "option_kill";
		break;
//.................................................................................................................

		case "option_door":
			PChar.qcstore_door = "done";

			if(CheckAttribute(PChar,"qcstore_jump") && PChar.qcstore_jump == "done")
			{
				if(CheckAttribute(PChar,"qcstore_bedroom") && PChar.qcstore_bedroom == "done")
				{
					PChar.qcstore_deal = "yes";
				}
			}

			PlaySound("VOICE\ENGLISH\Por_m_a_034.wav");
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "exit";
			AddDialogExitQuest("leave_town");
		break;

		case "option_no_deal":
			LAi_SetStayType(Pchar);//so the ordinary trade talk isnґt started during this option
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "option_no_deal_1";
		break;
		
		case "option_no_deal_1":
			dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];
			link.l1.go = "exit";
			AddDialogExitQuest("leave_no_deal");
		break;

		case "option_jump":
			PChar.qcstore_jump = "done";

			if(CheckAttribute(PChar,"qcstore_door") && PChar.qcstore_door == "done")
			{
				if(CheckAttribute(PChar,"qcstore_bedroom") && PChar.qcstore_bedroom == "done")
				{
					PChar.qcstore_deal = "yes";
				}
			}

			PlaySound("VOICE\ENGLISH\Por_m_a_041.wav");
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "exit";
			AddDialogExitQuest("leave_jump");
		break;

		case "option_bedroom":
			PChar.qcstore_bedroom = "done";

			if(CheckAttribute(PChar,"qcstore_door") && PChar.qcstore_door == "done")
			{
				if(CheckAttribute(PChar,"qcstore_jump") && PChar.qcstore_jump == "done")
				{
					PChar.qcstore_deal = "yes";
				}
			}

			PlaySound("VOICE\ENGLISH\Por_m_a_007.wav");
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "exit";
			AddDialogExitQuest("leave_bedroom");
		break;

		case "option_kill":
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "exit";
			AddDialogExitQuest("Blowhorn_fight");
		break;
//--------------------------------------------------------------------------------------------------------------------
		case "option_deal":
			PlaySound("VOICE\ENGLISH\Por_m_a_022.wav");
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "option_deal_1";
		break;
		
		case "option_deal_1":
			PlaySound("VOICE\ENGLISH\Por_m_a_017.wav");
			dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "option_deal_2";
		break;

		case "option_deal_2":
			PlaySound("VOICE\ENGLISH\Por_m_a_020.wav");
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "option_deal_3";
		break;

		case "option_deal_3":
			PlaySound("VOICE\ENGLISH\Por_m_a_035.wav");
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "option_deal_4";
		break;

		case "option_deal_4":
			PlaySound("VOICE\ENGLISH\Por_m_a_019.wav");
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "option_deal_5";
		break;

		case "option_deal_5":
			PlaySound("VOICE\ENGLISH\Por_m_a_018.wav");
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "option_deal_6";
		break;

		case "option_deal_6":
			PlaySound("VOICE\ENGLISH\gr_wench3_mhm.wav");
			dialog.text = DLG_TEXT[65];
			link.l1 = DLG_TEXT[66];
			link.l1.go = "option_deal_7";
		break;

		case "option_deal_7":
			PlaySound("INTERFACE\coins7.wav");
			int gold;
			gold = GetCharacterMoney(Pchar);
			AddMoneyToCharacter(Pchar,-gold/2);
			AddMoneyToCharacter(CharacterFromID("Peter Blowhorn"),gold/2);

			dialog.text = DLG_TEXT[67];
			link.l1 = DLG_TEXT[68];
			link.l1.go = "option_deal_8";
		break;

		case "option_deal_8":
			PlaySound("VOICE\ENGLISH\blaze_huh.wav");
			dialog.text = DLG_TEXT[69];
			link.l1 = DLG_TEXT[70];
			link.l1.go = "option_deal_9";
		break;

		case "option_deal_9":
			PlaySound("VOICE\ENGLISH\gr_wench3_oh.wav");
			dialog.text = DLG_TEXT[71];
			link.l1 = DLG_TEXT[72];
			link.l1.go = "option_deal_10";
		break;

		case "option_deal_10":
			PlaySound("VOICE\ENGLISH\Por_m_a_022.wav");
			dialog.text = DLG_TEXT[73];
			link.l1 = DLG_TEXT[74];
			link.l1.go = "exit";
			AddDialogExitQuest("Store_deal");
		break;
//.............................................................................
		case "dress_deal":
			dialog.text = DLG_TEXT[75];
			link.l1 = DLG_TEXT[76];
			link.l1.go = "dress_deal_1";
		break;
			
		case "dress_deal_1":
			PlaySound("VOICE\ENGLISH\Por_m_a_041.wav");
			dialog.text = DLG_TEXT[77];
			link.l1 = DLG_TEXT[78];
			link.l1.go = "dress_deal_2";
		break;

		case "dress_deal_2":
			PlaySound("VOICE\ENGLISH\Por_m_a_022.wav");
			dialog.text = DLG_TEXT[79];
			link.l1 = DLG_TEXT[80];
			link.l1.go = "dress_deal_3";
		break;

		case "dress_deal_3":
			PlaySound("VOICE\ENGLISH\Por_m_a_007.wav");
			dialog.text = DLG_TEXT[81];
			link.l1 = DLG_TEXT[82];
			link.l1.go = "dress_deal_4";
		break;

		case "dress_deal_4":
			PlaySound("OBJECTS\DUEL\man_attack5.wav");
			dialog.text = DLG_TEXT[83];
			link.l1 = DLG_TEXT[84];
			link.l1.go = "dress_deal_5";
		break;

		case "dress_deal_5":
			PlaySound("VOICE\ENGLISH\Por_m_a_019.wav");
			dialog.text = DLG_TEXT[85];
			link.l1 = DLG_TEXT[86];
			link.l1.go = "dress_deal_6";
		break;

		case "dress_deal_6":
			PlaySound("VOICE\ENGLISH\Por_m_a_018.wav");
			dialog.text = DLG_TEXT[87];
			link.l1 = DLG_TEXT[88];
			link.l1.go = "dress_deal_7";
		break;

		case "dress_deal_7":
			PlaySound("VOICE\ENGLISH\blaze_huh.wav");
			dialog.text = DLG_TEXT[89];
			link.l1 = DLG_TEXT[90];
			link.l1.go = "no_dress_deal";
			link.l2 = DLG_TEXT[91];
			link.l2.go = "dress_deal_8";
		break;

		case "no_dress_deal":
			PlaySound("VOICE\ENGLISH\gr_wench3.wav");
			dialog.text = DLG_TEXT[92];
			link.l1 = DLG_TEXT[93];
			link.l1.go = "exit";
			Pchar.quest.wr_quest2 = "store_no_disguise";
			AddDialogExitQuest("store_departure");
		break;

		case "dress_deal_8":
			PlaySound("VOICE\ENGLISH\gr_wench3_aye.wav");
			dialog.text = DLG_TEXT[94];
			link.l1 = DLG_TEXT[95];
			link.l1.go = "exit";
			Pchar.quest.wr_quest2 = "store_disguise";
			AddDialogExitQuest("Caroline_dress");
		break;

		case "dress_deal_9":
			//after Caroline dress
			dialog.text = DLG_TEXT[96];
			link.l1 = DLG_TEXT[97];
			link.l1.go = "exit";
			AddDialogExitQuest("Blaze_dress");
		break;
//.............................................................................
		case "store_roof_talk":
			dialog.text = DLG_TEXT[98];
			link.l1 = DLG_TEXT[99];
			link.l1.go = "exit";
			AddDialogExitQuest("store_roof_4");
		break;

		case "store_roof_talk_2":
			dialog.text = DLG_TEXT[100];
			link.l1 = DLG_TEXT[101];
			link.l1.go = "store_roof_talk_3";
		break;

		case "store_roof_talk_3":
			PlaySound("OBJECTS\DUEL\man_attack5.wav");
			dialog.text = DLG_TEXT[102];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "exit";
			AddDialogExitQuest("store_roof_7");
		break;
	// <-- JRH
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
