void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
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
	// -----------------------------------|иалог первый - первая встреча
		case "First time":
			Dialog.defAni = "Gov_Dialog_1";
			Dialog.ani = "Gov_Dialog_2";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			if(TradeCheck(PChar, NPChar, true)) { // NK
				if(NPChar.quest.meeting == "0")
				{
					d.Text = TimeGreeting() + DLG_TEXT[0] + GetMyFullName(NPChar) + DLG_TEXT[1];
					Link.l1 = DLG_TEXT[2] + GetMyFullName(PChar) + DLG_TEXT[3] + GetMyShipNameShow(PChar) + DLG_TEXT[4];
					Link.l1.go = "meeting";
					NPChar.quest.meeting = "1"; 
				}
				else
				{
					d.Text = TimeGreeting() + DLG_TEXT[5] + GetMyName(Pchar) + DLG_TEXT[6] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[7];
					Link.l1 = DLG_TEXT[8];
					Link.l1.go = "Shipyard";
					Link.l2 = DLG_TEXT[9];
					Link.l2.go = "quest lines";
					Link.l99 = DLG_TEXT[10];
					Link.l99.go = "exit";
				}
			// NK -->
			}
			else
			{
				dialog.text = DLG_TEXT[45] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[46];
				Link.l1 = DLG_TEXT[47];
				Link.l1.go = "exit";
				if(sti(PChar.Skill.Commerce)>=5)
				{
					Link.l2 = TranslateString("","high_trade_1");
					Link.l2.go = "high_price";
				}
				Diag.TempNode = "First time";
			}
			// NK <--
		break;

		case "high_price":
			dialog.text = TranslateString("","high_trade_2");
			link.l1 = TranslateString("","high_trade_3");
			link.l1.go = "shipyard_high";
			link.l2 = TranslateString("","high_trade_4");
			link.l2.go = "exit";
			Diag.TempNode = "First time";
		break;

		case "shipyard_high":
			dialog.Text = TranslateString("","high_trade_5");
			Link.l1 = TranslateString("","high_trade_6");
			Link.l1.go = "SHIPYARD_interface_high";
			Link.l3 = TranslateString("","high_trade_4");
			Link.l3.go = "Exit";
			Diag.TempNode = "First time";
		break;

		case "SHIPYARD_interface_high":
			Diag.TempNode = "First time";
			if(npchar.quest.Meeting != lastspeak_date)
			{
				FillShipsList(&NPChar); // NK

				npchar.quest.Meeting = lastspeak_date;
			}			
			DialogExit();
			tradeHigh = true;
			LaunchShipyard(npchar);
		break;

		case "Meeting":
			d.Text = DLG_TEXT[11];
			Link.l1 = DLG_TEXT[12] + GetMyName(NPChar) +DLG_TEXT[13];
			Link.l1.go = "Shipyard";			
			Link.l2 = DLG_TEXT[14];
			Link.l2.go = "quest lines";
			Link.l3 = DLG_TEXT[15];
			Link.l3.go = "exit";
		break;

		case "quest lines":
			d.Text = DLG_TEXT[16]+ GetMyName(PChar) + DLG_TEXT[17];
			Link.l1 = DLG_TEXT[18];
			Link.l1.go = "no quest";
		break;

		case "No quest":
			d.Text = DLG_TEXT[19] + GetMyName(Pchar) + DLG_TEXT[20];
			Link.l1 = DLG_TEXT[21];
			Link.l1.go = "Shipyard";
			Link.l2 = DLG_TEXT[22];
			Link.l2.go = "exit";
		break;

		case "shipyard":
			d.Text = DLG_TEXT[48] + DLG_TEXT[23];	// ccc 15oct04 shipyard waiting : changed by MAXIMUS
			Link.l9 = DLG_TEXT[49];	// ccc
			Link.l9.go = "exit";	// ccc
			Link.l1 = DLG_TEXT[24];
			Link.l1.go = "SHIPYARD_interface";
		break;

		case "SHIPYARD_interface":
			Diag.CurrentNode = Diag.TempNode;
			
			if (npchar.quest.Meeting != lastspeak_date)
			{
				FillShipsList(&NPChar); // NK

				npchar.quest.Meeting = lastspeak_date;
			}

			DialogExit();
			LaunchShipyard(npchar);
		break;

		case "continue":
			Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
			if (NPC_Meeting == "1")
			{
				d.Text = DLG_TEXT[27] + GetMyName(Pchar) + DLG_TEXT[28];
				Link.l1 = DLG_TEXT[29];
				Link.l1.go = "continue1";
			}
			else
			{
				d.Text = DLG_TEXT[30];
				Link.l1 = DLG_TEXT[31];
				Link.l1.go = "continue1";
			}
		break;

		case "continue1":
			NPC_Meeting = "1"; 
			d.Text = DLG_TEXT[32];
			Link.l1 = DLG_TEXT[33];
			Link.l1.go = "continue3";
			Link.l2 = DLG_TEXT[34];
			Link.l2.go = "exit1";
			
			if(makeint(PChar.skill.leadership) > 200)
			{
				d.Text = DLG_TEXT[35];
				Link.l1 = DLG_TEXT[36];
				Link.l1.go = "exit2";
			}
		break;

		case "continue2":
			d.Text = PCharPhrase(DLG_TEXT[37], DLG_TEXT[38] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[39]);
			Link.l1 = DLG_TEXT[40] + GetMyName(NPChar) +DLG_TEXT[41];
			if(CheckAttribute(Pchar, "Quest.Story_OxbayCaptured"))
			{
				Link.l1.go = "No ships";
			}
			else
			{
				Link.l1.go = "Shipyard";
			}			
			Link.l2 = DLG_TEXT[42];
			Link.l2.go = "quest lines";
			Link.l3 = DLG_TEXT[43];
			Link.l3.go = "continue3";
			Link.l4 = DLG_TEXT[44];
			Link.l4.go = "exit";
		break;

		case "continue3":
			AddDialogExitQuest("change_clauss_adress");
			Diag.CurrentNode = "First time";
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "exit2":
			Pchar.quest.pirate_fort.win_condition.l1 = "location";
			Pchar.quest.pirate_fort.win_condition.l1.character = "Blaze";
			Pchar.quest.pirate_fort.win_condition.l1.location = "Pirate_fort";
			Pchar.quest.pirate_fort.win_condition = "Pirates_vs_Blaze";
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "exit1":
			Diag.CurrentNode = "continue2";
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;
	}
}
