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
				d.Text = "Good day, " + GetMyFullName(PChar) + ".";
				Link.l1 = "You know who I am?";
				Link.l1.go = "meeting";
				NPChar.quest.meeting = "1"; 
			}
			else
			{
				if(pchar.model	== "Vanderdecken")
				{
					dialog.text = "Hello again. Thanks for dealing with me.";
					Link.l1 = "No thanks at all! I want my personality back!";
					Link.l1.go = "personality_back";
					Link.l2 = "Thank YOU! The ladies will love me with my new look!";
					Link.l2.go = "exit";
					Diag.TempNode = "First time";
				}
				else
				{
					dialog.text = "Come back for more, have you?";
					Link.l1 = "Not at all. Just paying my respects to Your Cursedness.";
					Link.l1.go = "exit";
					Link.l2 = "Yes, I have. Gimme, gimme!";
					Link.l2.go = "shipyard";
					Diag.TempNode = "First time";
				}
			}
		break;

		case "Meeting":
			d.Text = "Of course. Do I look like an ordinary person to you?";
			Link.l1 = "Now you mention it; no, you don't.";				
			Link.l1.go = "Meeting2";
		break;

		case "Meeting2":
			d.Text = "I am captain " + GetMyFullName(NPChar) + ". Perhaps you've heard of me.";
			Link.l1 = "I recall hearing that you captained the Flying Dutchman. But what of Davy Jones then?";
			Link.l1.go = "Meeting3";
		break;

		case "Meeting3":
			d.Text = "Ah; even an old cursed pirate captain like myself might want to retire at some point.";
			Link.l1 = "So you gave your ship to this Davy Jones character? Just like that?";
			Link.l1.go = "Meeting4";
		break;

		case "Meeting4":
			d.Text = "I didn't give her away. There is always a price to be paid for a special ship like that. I can offer the same to you.";
			Link.l1 = "What exactly do you mean?";
			Link.l1.go = "Shipyard";
		break;

		case "Shipyard":
			dialog.Text = "Are you willing to pay what it takes?";
			Link.l1 = "Sure thing. Now how about those oh-so-special-ships of yours?";
			Link.l1.go = "Shipyard_interface";
			if(CheckCharacterItem(npchar,"cursedcoin"))
			{
				Link.l2 = "Well... I usually lose my finest ships to nasty storms anyway. So there's no point, really.";
				Link.l2.go = "BuyTrident";
			}
			Link.l3 = "Ehm. On second thought; no, not really. I've got to go someplace else. Bye.";
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
			d.Text = "Since you are such a splendid customer, I'll make you a deal: Have another look at my stock.";
			Link.l1 = "What good is that going to do me?";				
			Link.l1.go = "Shipyard";
		break;

		case "BuyTrident":
			d.Text = "What if I could offer you an antidote to storms? In a manner of speaking, that is. I've admittedly grown rather fond of it, but I'll sell it to you if the price is right. How does 1,000,000 gold pieces sound to you?";
			Link.l1 = "Oh, you old joker! You can't be serious on that. Wha? You ARE serious? Uhm... I'll send you my reply by us pirates' new patented 'Express Bottle Messaging System'. It's known as 'E-Bottle' for short. Anyway, time to go now!";
			Link.l1.go = "Exit";
			if(sti(Pchar.money) >= 1000000)
			{
				Link.l2 = "That's a hefty sum indeed! But it so happens I do have that amount of cash. So I'll take it right now, you don't have to wrap it.";
				Link.l2.go = "BuyTrident2";
			}
		break;

		case "BuyTrident2":
			d.Text = "And there's a special offer on today! Buy one Trident for 1,000,000 of your gold coins and you will get one of mine in return. Half hour warranty included.";
			Link.l1 = "Two for the price of one, is it? It seems I'm in luck! I WANT IT!!!";
			Link.l1.go = "Exit_buy";
			Link.l2 = "But... This coin looks mysterious. It seems to give off an aura of great ancient power! I don't want it!";
			Link.l2.go = "BuyTridentNo";
		break;
		
		case "BuyTridentNo":
			d.Text = "Sorry, no backsies. Now! GET! OUT!!!";
			Link.l1 = "But I mean it! I really DON'T want that coin. Just that Trident will do.";
			Link.l1.go = "BuyTridentNo";
			Link.l2 = "I get the message. I'll be going now... (To self: Oh dear! What did I get myself into this time?)";
			Link.l2.go = "Exit_buy2";
		break;

		case "Exit_buy":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneytoCharacter  ( pchar, -1000000);
			GiveItem2Character   ( pchar, "Trident_Neptune");
			TakeItemFromCharacter(npchar, "cursedcoin");
			GiveItem2Character   ( pchar, "cursedcoin");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "Exit_buy2":
			PlayStereoSound("INTERFACE\took_item.wav");
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
