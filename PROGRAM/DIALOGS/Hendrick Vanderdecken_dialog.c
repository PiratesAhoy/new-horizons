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
		case "First time":
			Dialog.defAni = "Gov_Dialog_1";
			Dialog.ani = "Gov_Dialog_2";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.cam = "1";

			if(NPChar.quest.meeting == "0")
			{
				d.Text = DLG_TEXT[0] + GetMyFullName(PChar) + DLG_TEXT[1];
				Link.l1 = DLG_TEXT[2];
				Link.l1.go = "meeting";
				NPChar.quest.meeting = "1"; 
			}
			else
			{
				if(pchar.model	== "Vanderdecken")
				{
					d.Text = DLG_TEXT[3];
					Link.l1 = DLG_TEXT[4];
					Link.l1.go = "personality_back";
					Link.l2 = DLG_TEXT[5];
					Link.l2.go = "exit";
					Diag.TempNode = "First time";
				}
				else
				{
					d.Text = DLG_TEXT[6];
					Link.l1 = DLG_TEXT[7];
					Link.l1.go = "exit";
					Link.l2 = DLG_TEXT[8];
					Link.l2.go = "shipyard";
					Diag.TempNode = "First time";
				}
			}
		break;

		case "Meeting":
			d.Text = DLG_TEXT[9];
			Link.l1 = DLG_TEXT[10];	
			Link.l1.go = "Meeting2";
		break;

		case "Meeting2":
			d.Text = DLG_TEXT[11] + GetMyFullName(NPChar) + DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "Meeting3";
		break;

		case "Meeting3":
			d.Text = DLG_TEXT[14];
			Link.l1 = DLG_TEXT[15];
			Link.l1.go = "Meeting4";
		break;

		case "Meeting4":
			d.Text = DLG_TEXT[16];
			Link.l1 = DLG_TEXT[17];
			Link.l1.go = "Shipyard";
		break;

		case "Shipyard":
			d.Text = DLG_TEXT[18];
			Link.l1 = DLG_TEXT[19];
			Link.l1.go = "Shipyard_interface";
			if(CheckCharacterItem(npchar,"cursedcoin"))
			{
				Link.l2 = DLG_TEXT[20];
				Link.l2.go = "BuyTrident";
			}
			Link.l3 = DLG_TEXT[21];
			Link.l3.go = "Exit";
			Diag.TempNode = "First time";
		break;

		case "Shipyard_interface":
			Diag.TempNode = "First time";
			if(npchar.quest.Meeting != lastspeak_date)
			{
				FillShipsList(&NPChar); // NK
				npchar.quest.Meeting = lastspeak_date;
			}			
			DialogExit();
			tradeHigh = true;
			LaunchShipyard(npchar);
			// Fun stuff:
			SetNextWeather("Day Storm");
			if(pchar.model	== "Vanderdecken")
			{
				pchar.name		 = npchar.name;
				pchar.lastname	 = npchar.lastname;
				pchar.headmodel  = npchar.headmodel;
				pchar.model.animation = npchar.model.animation;
				GiveModel2Player(npchar.model,true);
				npchar.name		 = TranslateString("","Hendrick");
				npchar.lastname	 = TranslateString("","Vanderdecken");
				npchar.model.animation = "man";
				npchar.headmodel  = "h_Vanderdecken";
				SetModelfromArray(npchar, GetModelIndex("Vanderdecken"));
			}
			else
			{
				npchar.name		 = pchar.name;
				npchar.lastname	 = pchar.lastname;
				npchar.headmodel = pchar.headmodel;
				npchar.model.animation = pchar.model.animation;
				SetModelfromArray(npchar, GetModelIndex(pchar.model));
				pchar.name		 = TranslateString("","Hendrick");
				pchar.lastname	 = TranslateString("","Vanderdecken");
				pchar.model.animation = "man";
				pchar.headmodel  = "h_Vanderdecken";
				GiveModel2Player("Vanderdecken",true);
			}
		break;

		case "personality_back":
			d.Text = DLG_TEXT[22];
			Link.l1 = DLG_TEXT[23];
			Link.l1.go = "Shipyard";
		break;

		case "BuyTrident":
			d.Text = DLG_TEXT[24];
			Link.l1 = DLG_TEXT[25];
			Link.l1.go = "Exit";
			if(sti(Pchar.money) >= 1000000)
			{
				Link.l2 = DLG_TEXT[26];
				Link.l2.go = "BuyTrident2";
			}
		break;

		case "BuyTrident2":
			d.Text = DLG_TEXT[27];
			Link.l1 = DLG_TEXT[28];
			Link.l1.go = "Exit_buy";
			Link.l2 = DLG_TEXT[29];
			Link.l2.go = "BuyTridentNo";
		break;
		
		case "BuyTridentNo":
			d.Text = DLG_TEXT[30];
			Link.l1 = DLG_TEXT[31];
			Link.l1.go = "BuyTridentNo";
			Link.l2 = DLG_TEXT[32];
			Link.l2.go = "Exit_buy2";
		break;

		case "Exit_buy":
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneytoCharacter  ( pchar, -1000000);
			GiveItem2Character   ( pchar, "Trident_Neptune");
			TakeItemFromCharacter(npchar, "cursedcoin");
			GiveItem2Character   ( pchar, "cursedcoin");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "Exit_buy2":
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneytoCharacter  ( pchar, -1000000);
			GiveItem2Character   ( pchar, "Trident_Neptune");
			TakeItemFromCharacter(npchar, "cursedcoin");
			GiveItem2Character   ( pchar, "cursedcoin");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			DoQuestReloadToLocation("IslaDeMuerte_shore_02", "reload", "reload1_cabin" ,"_");
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
	}
}
