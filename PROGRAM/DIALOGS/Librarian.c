void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag;
	int buyprice, bookindex;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	
	int librarymult = 1.2; //Books at the library are slightly more expensive, but he will always have them.

	switch(Dialog.CurrentNode)
	{
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "first time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\PADI\PADI001";
				
			Dialog.Text = DLG_TEXT[0];
			if(ALLOW_LOCKED_PERKS)
			{
				Link.l1 = DLG_TEXT[2];
				Link.l1.go = "skillbooks";
			}
			Link.l9 = DLG_TEXT[1];
			Link.l9.go = "exit";
		break;
		
		case "skillbooks":
			Dialog.Text = DLG_TEXT[3];
			Link.l1 = DLG_TEXT[4];
			Link.l1.go = "skillbook1";
			Link.l2 = DLG_TEXT[5];
			Link.l2.go = "skillbook2";
			Link.l3 = DLG_TEXT[6];
			Link.l3.go = "skillbook3";
			Link.l4 = DLG_TEXT[7];
			Link.l4.go = "skillbook4";
			Link.l9 = DLG_TEXT[8];
			Link.l9.go = "exit";
		break;
		
		case "skillbook1":
			bookindex = GetItemIndex("skillbook1");
			buyprice = round(GetBoookPrice(bookindex)*librarymult);
			Dialog.Text = GetRandomBookReply()+DLG_TEXT[20]+buyprice+DLG_TEXT[21];
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "buybook";
			Link.l2 = DLG_TEXT[8];
			Link.l2.go = "exit";
			NPChar.buybook.bookid = "skillbook1";
			NPChar.buybook.price = buyprice;
		break;
		
		case "skillbook2":
			bookindex = GetItemIndex("skillbook2");
			buyprice = round(GetBoookPrice(bookindex)*librarymult);
			Dialog.Text = GetRandomBookReply()+DLG_TEXT[20]+buyprice+DLG_TEXT[21];
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "buybook";
			Link.l2 = DLG_TEXT[8];
			Link.l2.go = "exit";
			NPChar.buybook.bookid = "skillbook2";
			NPChar.buybook.price = buyprice;
		break;
		
		case "skillbook3":
			bookindex = GetItemIndex("skillbook3");
			buyprice = round(GetBoookPrice(bookindex)*librarymult);
			Dialog.Text = GetRandomBookReply()+DLG_TEXT[20]+buyprice+DLG_TEXT[21];
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "buybook";
			Link.l2 = DLG_TEXT[8];
			Link.l2.go = "exit";
			NPChar.buybook.bookid = "skillbook3";
			NPChar.buybook.price = buyprice;
		break;
		
		case "skillbook4":
			bookindex = GetItemIndex("skillbook4");
			buyprice = round(GetBoookPrice(bookindex)*librarymult);
			Dialog.Text = GetRandomBookReply()+DLG_TEXT[20]+buyprice+DLG_TEXT[21];
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "buybook";
			Link.l2 = DLG_TEXT[8];
			Link.l2.go = "exit";
			NPChar.buybook.bookid = "skillbook4";
			NPChar.buybook.price = buyprice;
		break;
		
		case "buybook":
			buyprice = sti(NPChar.buybook.price);
			if(sti(PChar.money) >= buyprice)
			{
				GiveItem2Character(PChar, NPChar.buybook.bookid);
				AddMoneytoCharacter(PChar, -1*buyprice);
				Dialog.Text = DLG_TEXT[22];
				Link.l1 = DLG_TEXT[23];
				Link.l1.go = "exit";
			}
			else
			{
				Dialog.Text = DLG_TEXT[24];
				Link.l1 = DLG_TEXT[25];
				Link.l1.go = "exit";
			}
		break;
	}
}

string GetRandomBookReply()
{
	int index = 10;
	int amount = 3; //At the moment I've made up 3 replies, but there are placeholders for up to 10 replies.
	index += rand((amount-1));
	return DLG_TEXT[index];
}

int GetBoookPrice(int itmIdx)
{
	int itmprice = 0;
	if(CheckAttribute(&Items[itmIdx],"price"))
	{
		itmprice = sti(Items[itmIdx].price);
	}

	float skillModify = GetCharPriceMod(GetMainCharacter(), PRICE_TYPE_BUY, true, false);
	return makeint(makefloat(GetItemPriceTrader(CharacterRef, Items[itmIdx].id))*skillModify);
}
