// --> PW 12/2016 Build 14 4.1 ProcessTradeDecrease(),ProcessTradeIncrease(),ProcessSell() rewritten to allow multipliers and dynamic price changes
// SellAllProcessReal(bool reset) revised to give same results as normal store transactions using same function calls 
// minor changes to RefreshAllStrings () to conform <-- PW

#define SHOW_MAIN	0
#define SHOW_BUY	1
#define SHOW_SELL	2
#define SHOW_INFO	3

#define HIGH_TRADE  3000	// LDH if trade is over this amount, it logs as a high value trade - 31Dec08

int showType;

int nCurScrollNum;
string oldCurNode="";

ref refCharacter;
ref refStore;

int nPlayerMoney;
int nPlayerMoneyStart;
// NK -->
int nCurPrice;
int nStoreMoney;
string sTownName;
int tsize = DEFAULT_TOWN_POP;
// NK <--
int nTradeQuantity;

void InitInterface_RR(string iniName,ref pChar,ref pStore)
{
  refStore = pStore;
	refCharacter = pChar;
  showType = SHOW_MAIN;

	UpdateTradebook();		
	
// KK -->
	if (!LAi_IsCapturedLocation) {
		GameInterface.title = "titleStore";
	} else {
		GameInterface.title = "titleRansack";
	}
// <-- KK

	CreateStartingCargo();// TIH transfer time fix Jul20'06
    FillScroll();
    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();//MAXIMUS: standard exit-string for exit-button
// KK -->
		if (LAi_IsCapturedLocation) {
		SendMessage(&GameInterface, "lsls", MSG_INTERFACE_MSG_TO_NODE, "BUY_BUTTON", 0, XI_ConvertString("Take"));
		SendMessage(&GameInterface, "lsls", MSG_INTERFACE_MSG_TO_NODE, "SELL_BUTTON", 0, XI_ConvertString("Leave"));
		SetNodeUsing("SELLEVERYTHING_BUTTON", false);
		SetNodeUsing("SELLALL_BUTTON", false);
  	}
// <-- KK
    SetVariable();

    CreateString(true,"Money","",FONT_NORMAL,COLOR_MONEY,173,395,SCRIPT_ALIGN_LEFT,0.9); // NK
	CreateString(true,"SMoney","",FONT_NORMAL,COLOR_MONEY,467,395,SCRIPT_ALIGN_RIGHT,0.9); // NK
	CreateString(true,"CurPrice","",FONT_NORMAL,COLOR_MONEY,320,395,SCRIPT_ALIGN_CENTER,0.9); // NK
    CreateString(true,"ShipName","",FONT_SEADOGS,COLOR_NORMAL,320,203,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"GoodsName","",FONT_NORMAL,COLOR_NORMAL,320,239,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"GoodsWeight","",FONT_NORMAL,COLOR_NORMAL,324,275,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(true,"BuyPrice","",FONT_BOLD_NUMBERS,COLOR_NORMAL,260,303,SCRIPT_ALIGN_RIGHT,0.75);
    CreateString(true,"SellPrice","",FONT_BOLD_NUMBERS,COLOR_NORMAL,380,303,SCRIPT_ALIGN_LEFT,0.75);
    CreateString(true,"OnShipQuantity","",FONT_BOLD_NUMBERS,COLOR_NORMAL,79,360,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"OnShipSpaceQuantity","",FONT_BOLD_NUMBERS,COLOR_NORMAL,79,415,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"OnStoreQuantity","",FONT_BOLD_NUMBERS,COLOR_NORMAL,561,413,SCRIPT_ALIGN_CENTER,1.0);

    CreateString(false,"PriceSum","",FONT_NORMAL,COLOR_NORMAL,324,249,SCRIPT_ALIGN_LEFT,1.0);
    CreateString(false,"TradeQuantity","",FONT_NORMAL,COLOR_NORMAL,320,279,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(false,"GoodWeightSum","",FONT_NORMAL,COLOR_NORMAL,324,354,SCRIPT_ALIGN_LEFT,1.0);

	SetNodeUsing("BUYSELL_IMAGES",false);
    SetNodeUsing("OK_BUTTON",false);
    SetNodeUsing("CANCEL_BUTTON",false);
    SetNodeUsing("TRADEQUANTITY",false);
	SetSelectable("EXIT_BUTTON",true);

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
    SetEventHandler("frame","ProcessFrame",1);
    SetEventHandler("BuyPress","ProcessBuy",0);
    SetEventHandler("SellPress","ProcessSell",0);
// START MOD Code by Stone-D : 28/07/2003
    SetEventHandler("SellAllPress","SellAllProcess",0);
	SetEventHandler("SellAllPress2","SellAllProcess2",0); // NK
// END MOD Code by Stone-D : 28/07/2003
    SetEventHandler("OkPress","ProcessOk",0);
    SetEventHandler("CancelPress","ProcessCancel",0);
    SetEventHandler("decreaseTrade","ProcessTradeDecrease",0);
    SetEventHandler("increaseTrade","ProcessTradeIncrease",0);
    SetEventHandler("exitCancel","ProcessCancelExit",0);
    SetEventHandler("ievntGetHelpTexture","iprocGetHelpTexture",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
}

void ProcessFrame()
{
    if(sti(GameInterface.scrollitems.current)!=nCurScrollNum)
    {
		nCurScrollNum = sti(GameInterface.scrollitems.current);
		SetShowMode(SHOW_MAIN);
		RefreshAllStrings();
		SetBuySellEnable();
		return;
    }

	if(oldCurNode!=GetCurrentNode())
	{
		oldCurNode = GetCurrentNode();
		switch(oldCurNode)
		{
		case "SCROLLITEMS": SetShowMode(SHOW_MAIN); break;
		case "BUY_BUTTON": SetShowMode(SHOW_MAIN); break;
		case "SELL_BUTTON": SetShowMode(SHOW_MAIN); break;
		}
		RefreshAllStrings();
	}

// KK -->
	if (showType == SHOW_MAIN) FreezeScreen(false);
// <-- KK
}

void RefreshAllStrings()
{
	if(showType==SHOW_MAIN)
	{
		GameInterface.strings.CurPrice = ""; // NK
		GameInterface.strings.Money = MakeMoneyShow(nPlayerMoney,MONEY_SIGN,MONEY_DELIVER);
// KK -->
		if (!LAi_IsCapturedLocation)
			GameInterface.strings.SMoney = MakeMoneyShow(nStoreMoney,MONEY_SIGN,MONEY_DELIVER); // NK
		else
			GameInterface.strings.SMoney = MakeMoneyShow(0,MONEY_SIGN,MONEY_DELIVER);
// <-- KK
		GameInterface.strings.GoodsName = XI_ConvertString(Goods[GetGoodsIndexForI(nCurScrollNum)].Name);
		GameInterface.strings.GoodsWeight = Goods[GetGoodsIndexForI(nCurScrollNum)].Weight + XI_ConvertString("cwt");
		// NK <--
		GameInterface.strings.BuyPrice = "" + GetStoreGoodsPrice(refStore,GetGoodsIndexForI(nCurScrollNum),PRICE_TYPE_BUY,GetMainCharacter(), 0);
		if(tradeLow==false) GameInterface.strings.SellPrice = "" + GetStoreGoodsPrice(refStore,GetGoodsIndexForI(nCurScrollNum),PRICE_TYPE_SELL,GetMainCharacter(), 0);
		else GameInterface.strings.SellPrice = "" + GetStoreGoodsPrice(refStore,GetGoodsIndexForI(nCurScrollNum),PRICE_TYPE_SELL,GetMainCharacter(), 0)/4*3;

		// NK <--
		GameInterface.strings.OnShipQuantity = "" + GetCargoGoods(refCharacter,GetGoodsIndexForI(nCurScrollNum));
		GameInterface.strings.OnShipSpaceQuantity = "" + GetCargoFreeSpace(refCharacter);
		GameInterface.strings.OnStoreQuantity = "" + GetStoreGoodsQuantity(refStore,GetGoodsIndexForI(nCurScrollNum));
		if( CheckAttribute(refCharacter,"Ship.Name") ) {
			GameInterface.strings.ShipName = refCharacter.Ship.Name;
		} else {
			GameInterface.strings.ShipName = XI_ConvertString(SHIP_NAME_NOTUSED);
		}
	}
	else
	{
	    GameInterface.strings.TradeQuantity = "" + nTradeQuantity;
	    GameInterface.strings.GoodWeightSum = "" + GetGoodWeightByType(GetGoodsIndexForI(nCurScrollNum),nTradeQuantity);
		// NK -->
		int priceSum;
		
		if(showType == SHOW_BUY)
		{
			GameInterface.strings.CurPrice = MakeMoneyShow(GetStoreGoodsPrice(&refStore, GetGoodsIndexForI(nCurScrollNum), PRICE_TYPE_BUY, GetMainCharacter(), -nTradeQuantity),MONEY_SIGN,MONEY_DELIVER);
		}
		if(showType == SHOW_SELL)
		{
			if(tradeLow==false)
			{
				GameInterface.strings.CurPrice = MakeMoneyShow(GetStoreGoodsPrice(&refStore, GetGoodsIndexForI(nCurScrollNum), PRICE_TYPE_SELL, GetMainCharacter(), nTradeQuantity-GetGoodsUnitSize()),MONEY_SIGN,MONEY_DELIVER);
			}
			else
			{
				GameInterface.strings.CurPrice = MakeMoneyShow((GetStoreGoodsPrice(&refStore, GetGoodsIndexForI(nCurScrollNum), PRICE_TYPE_SELL, GetMainCharacter(), nTradeQuantity-GetGoodsUnitSize())/4*3),MONEY_SIGN,MONEY_DELIVER);
			}
		}
		if(showType == SHOW_BUY) GameInterface.strings.priceSum = "" + nCurPrice;
		if(showType == SHOW_SELL) GameInterface.strings.priceSum = "" + nCurPrice;
		if(nTradeQuantity > 0)
		{
			int moneyShow = 0;
			float dividerByThis;
			if ( GetGoodsUnitSize()>0 ) dividerByThis = nTradeQuantity/GetGoodsUnitSize();
			if ( dividerByThis>0 ) moneyShow = MakeMoneyShow(makeint(nCurPrice/dividerByThis),MONEY_SIGN,MONEY_DELIVER);
			if(showType==SHOW_BUY) GameInterface.strings.priceSum = GameInterface.strings.priceSum + " (" + moneyShow + ")";
			if(showType == SHOW_SELL) GameInterface.strings.priceSum = GameInterface.strings.priceSum + " (" + moneyShow + ")";
		//	{
		//		if(tradeLow==false) GameInterface.strings.priceSum = GameInterface.strings.priceSum + " (" + moneyShow + ")";
		//		else GameInterface.strings.priceSum = GameInterface.strings.priceSum + " (" + MakeMoneyShow(makeint((nCurPrice/4*3)/dividerByThis),MONEY_SIGN,MONEY_DELIVER) + ")";
		//	}
		}
		else { GameInterface.strings.priceSum = GameInterface.strings.priceSum + " (0)"; }
		// NK <--
	}
}

void SetVariable()
{
	nCurScrollNum = -1;
	//if(GetTownIDFromGroup(refStore.group) != "") { sTownName = GetTownIDFromGroup(refStore.group); } // NK, add aref 05-04-15
	//else { sTownName = GetCurrentTownID(); }
	sTownName = GetCurrentTownID();
	ref mainRef = GetMainCharacter();
	nPlayerMoney = sti(mainRef.Money);
	nPlayerMoneyStart = sti(mainRef.Money);
	// NK -->
	nStoreMoney = GetTownGold(sTownName);
	tsize = GetTownSize(sTownName);
	nCurPrice = 0;
	// NK <--
	nTradeQuantity = 0;
}

void FillScroll()
{
    int i;
    string goodName;
    string attributeName;
    aref pRef;

    GameInterface.scrollitems.current = 0;
	GameInterface.scrollitems.ImagesGroup.t0 = "ICONS";
// KK -->
	if(bNewIcons==true) GameInterface.scrollitems.ImagesGroup.t1 = "GOODS_NEW";
	else GameInterface.scrollitems.ImagesGroup.t1 = "GOODS";
	
	switch (LanguageGetLanguage())
	{
		case "Polish":
			GameInterface.scrollitems.ImagesGroup.t2 = "TRADE_STATE_POL";
		break;
		// default:
		GameInterface.scrollitems.ImagesGroup.t2 = "TRADE_STATE";
	}

	int idx = 1;
    for(i=0; i<GOODS_QUANTITY; i++)
    {
		if( !GetStoreGoodsUsed(refStore,i) ) continue;
		attributeName = "pic" + idx;
		goodName = Goods[i].Name;

		makearef(pRef,GameInterface.scrollitems.(attributeName));
		pRef.str1 = goodName;
		pRef.img1 = "cannon back";
		pRef.tex1 = 0;
		pRef.img2 = goodName;
		pRef.tex2 = 1;
		pRef.img3 = GetGoodStatus(goodName, true);
		pRef.tex3 = 2;
		pRef.img4 = GetGoodStatus(goodName, false);
		pRef.tex4 = 2;
		pRef.goodsIndex = i;
		idx++;
	}
// <-- KK
	GameInterface.scrollitems.ListSize = idx-1;
}

void ProcessBuy()
{
	nTradeQuantity = 0;
	nCurPrice = 0; 
	SetShowMode(SHOW_BUY);
	RefreshAllStrings();
}
void ProcessSell()
{
	int i
	int unitSize = GetGoodsUnitSize();
	nTradeQuantity = 0;
	nCurPrice = 0;
	nTradeQuantity  = GetCargoGoods(refCharacter,GetGoodsIndexForI(nCurScrollNum))/unitSize;
	for(i=0; i<nTradeQuantity; i++)
	{
		if(tradeLow==false) nCurPrice += makeint(GetStoreGoodsPrice(refStore, GetGoodsIndexForI(nCurScrollNum), PRICE_TYPE_SELL, GetMainCharacter(), i)) ;
		else 	nCurPrice += makeint(GetStoreGoodsPrice(refStore, GetGoodsIndexForI(nCurScrollNum), PRICE_TYPE_SELL, GetMainCharacter(), i)/4*3) ;
	}
	nTradeQuantity  = nTradeQuantity  * unitSize;

	SetShowMode(SHOW_SELL);
	RefreshAllStrings();
}

void ProcessOk()
{
	int exch; // NK
	if(nTradeQuantity<=0) return; // NK
	string goodName = goods[GetGoodsIndexForI(nCurScrollNum)].name;//MAXIMUS

//	Event("KB_End"); // KK		// LDH is this really necessary? - 31Jan09

	if(showType==SHOW_BUY)
	{
		//if(GetGoodPriceByType(&refStore, refCharacter, GetGoodsIndexForI(nCurScrollNum),nTradeQuantity,PRICE_TYPE_BUY) > nPlayerMoney) return; // NK
		SetStoreGoods(refStore,GetGoodsIndexForI(nCurScrollNum),GetStoreGoodsQuantity(refStore,GetGoodsIndexForI(nCurScrollNum))-nTradeQuantity);
		AddCharacterGoods(refCharacter,GetGoodsIndexForI(nCurScrollNum),nTradeQuantity);
		// NK -->
		exch = nCurPrice; //GetGoodPriceByType(&refStore, refCharacter, GetGoodsIndexForI(nCurScrollNum),nTradeQuantity,PRICE_TYPE_BUY);
		nPlayerMoney -= exch;
		nStoreMoney += exch;
		// NK <--
		if(AUTO_SKILL_SYSTEM)//MAXIMUS -->
		{
			refCharacter.(goodName).buy = GetStoreGoodsPrice(refStore,GetGoodsIndexForI(nCurScrollNum),PRICE_TYPE_BUY,GetMainCharacter(), 0);
			if(!CheckAttribute(refCharacter,"."+(goodName)+".old.buy")) { refCharacter.(goodName).old.buy = refCharacter.(goodName).buy; }
		}//MAXIMUS <--
	}
	if(showType==SHOW_SELL)
	{
		//if(GetGoodPriceByType(&refStore, refCharacter, GetGoodsIndexForI(nCurScrollNum),nTradeQuantity,PRICE_TYPE_SELL) > nStoreMoney) return; // NK
		SetStoreGoods(refStore,GetGoodsIndexForI(nCurScrollNum),GetStoreGoodsQuantity(refStore,GetGoodsIndexForI(nCurScrollNum))+nTradeQuantity);
		RemoveCharacterGoods(refCharacter,GetGoodsIndexForI(nCurScrollNum),nTradeQuantity);
		// NK -->
		exch = nCurPrice; //GetGoodPriceByType(&refStore, refCharacter, GetGoodsIndexForI(nCurScrollNum),nTradeQuantity,PRICE_TYPE_SELL);
		
		nPlayerMoney += exch;
		nStoreMoney -= exch;
		// NK <--
		if(AUTO_SKILL_SYSTEM)//MAXIMUS -->
		{
			refCharacter.(goodName).sell = GetStoreGoodsPrice(refStore,GetGoodsIndexForI(nCurScrollNum),PRICE_TYPE_SELL,GetMainCharacter(), 0);
			if(!CheckAttribute(refCharacter,"."+(goodName)+".old.sell")) { refCharacter.(goodName).old.sell = refCharacter.(goodName).sell; }
		}//MAXIMUS <--
	}
	// LDH log high trades - 31Dec08
	if (exch >= HIGH_TRADE)
	{
		string strTrade = "TRADING: ";
		strTrade += StrLeft(refCharacter.location+":                    ", 20);
		if(showType==SHOW_BUY) strTrade += " Bought ";
		else strTrade += " Sold ";
		strTrade += nTradeQuantity + " " + goodName + " for " + exch;
		Trace(strTrade);
	}
	//MAXIMUS -->
	ref tmpref = GetMainCharacter();
	if(AUTO_SKILL_SYSTEM)
	{
		int skillNum = makeint(exch/10);
		bool bLucky = false;
		if(CheckAttribute(refCharacter,"."+(goodName)+".sell") && CheckAttribute(refCharacter,"."+(goodName)+".old.buy"))
		{
			if(sti(refCharacter.(goodName).sell)>sti(refCharacter.(goodName).old.buy)) { skillNum = makeint(exch/5); bLucky = true; }
			else { bLucky = false; }
			refCharacter.(goodName).old.buy = sti(refCharacter.(goodName).buy);
		}
		if(CheckAttribute(refCharacter,"."+(goodName)+".buy") && CheckAttribute(refCharacter,"."+(goodName)+".old.sell"))
		{
			if(sti(refCharacter.(goodName).buy)<sti(refCharacter.(goodName).old.sell)) { skillNum = makeint(exch/5); bLucky = true; }
			else { if(!bLucky) { bLucky = false; } }
			refCharacter.(goodName).old.sell = sti(refCharacter.(goodName).sell);
		}
		if(bLucky) { AddPartyExpChar(tmpref, "Sneak", skillNum); }
		AddPartyExpChar(tmpref, "Commerce", skillNum);
		if(CheckAttribute(GetMainCharacter(),"storekeeper.Idx") && sti(tmpref.storekeeper.Idx)!=-1) { AddCharacterExpNSChar(&characters[sti(tmpref.storekeeper.Idx)], "Commerce", skillNum); }
	}
	//MAXIMUS <--
	tmpref.Money = nPlayerMoney;
	// NK -->
	if(sTownName != "") SetTownGold(sTownName, nStoreMoney);
/* TIH prior time method replaced by singular function */
	nTradeQuantity = 0;
	nCurPrice = 0;
	// NK <--
    ScrollChange();

	SetShowMode(SHOW_MAIN);
	RefreshAllStrings();
	SetBuySellEnable();
	SetCurrentNode("SCROLLITEMS");
}

void ProcessCancel()
{
	nTradeQuantity = 0;
	nCurPrice = 0; // NK
	SetShowMode(SHOW_MAIN);
	RefreshAllStrings();
	SetCurrentNode("SCROLLITEMS");
}

void ProcessTradeDecrease()
{
	int i
	int mult = 1;
	if (GetQuickControl("alt")) mult = 100;
	if (GetQuickControl("shift")) mult = 10;
	int unitSize = GetGoodsUnitSize();

	if(showType==SHOW_BUY)
	{
		for(i=0; i<mult; i++)
		{
			if(nTradeQuantity - unitSize <= 0) { nTradeQuantity = 0; nCurPrice = 0; RefreshAllStrings(); continue; }
			nTradeQuantity -= unitSize;
			nCurPrice -= GetStoreGoodsPrice(&refStore, GetGoodsIndexForI(nCurScrollNum), PRICE_TYPE_BUY, GetMainCharacter(), -nTradeQuantity - unitSize);
		}
	}
	if(showType==SHOW_SELL)
	{
		for(i=0; i<mult; i++)
		{
			if(nTradeQuantity - unitSize <= 0) { nTradeQuantity = 0; nCurPrice = 0; RefreshAllStrings(); continue; }
			nTradeQuantity -= unitSize;
			if(tradeLow==false)
			{
				nCurPrice -= GetStoreGoodsPrice(refStore, GetGoodsIndexForI(nCurScrollNum), PRICE_TYPE_SELL, GetMainCharacter(), nTradeQuantity/ unitSize);
			}
			else
			{
				nCurPrice -= GetStoreGoodsPrice(refStore, GetGoodsIndexForI(nCurScrollNum), PRICE_TYPE_SELL, GetMainCharacter(), nTradeQuantity/ unitSize)/4*3;
			}
		}
	}
	RefreshAllStrings();
}

void ProcessTradeIncrease()
{
	if(nTradeQuantity <= 0)  nCurPrice = 0;
	int nCurQuantity = GetCargoGoods(refCharacter,GetGoodsIndexForI(nCurScrollNum));
	int i
	int mult = 1;
	if (GetQuickControl("alt")) mult = 100;
	if (GetQuickControl("shift")) mult = 10;
	int unitSize = GetGoodsUnitSize();

	if(showType==SHOW_BUY)
	{
		for(i=0; i<mult; i++)
		{
			int max1 = GetGoodQuantityByWeight(GetGoodsIndexForI(nCurScrollNum),GetCargoFreeSpace(refCharacter)+GetGoodWeightByType(GetGoodsIndexForI(nCurScrollNum),nCurQuantity)) - nCurQuantity;
			// int max2 = GetGoodQuantityByPrice(&refStore, refCharacter, GetGoodsIndexForI(nCurScrollNum),nPlayerMoney,PRICE_TYPE_BUY);
			int max3 = GetStoreGoodsQuantity(refStore,GetGoodsIndexForI(nCurScrollNum));
			if(nTradeQuantity+unitSize>max1) continue; // calc altered to include unitSize for next increase PW
			// if(nTradeQuantity+unitsSize>max2) return;
			if(nTradeQuantity+ unitSize>max3) continue; // calc altered to include unitSize for next increase PW
			// NK -->
			if(GetGoodsIndexForI(nCurScrollNum) == GOOD_WHEAT)
			{
				if(GetStoreGoodsQuantity(&refStore, GetGoodsIndexForI(nCurScrollNum)) - nTradeQuantity <= tsize * MIN_FOOD_SCALAR) { return; }
			}
			// NK <--

			// if(max1-nTradeQuantity < unitSize) unitSize = max1-nTradeQuantity; //dissallow partial units PW
			//NK - if(max2-nTradeQuantity < unitSize) unitSize = max2-nTradeQuantity;
			// if(max3-nTradeQuantity < unitSize) unitSize = max3-nTradeQuantity;//dissallow partial units PW

			if(nCurPrice + makeint (GetStoreGoodsPrice(&refStore, GetGoodsIndexForI(nCurScrollNum), PRICE_TYPE_BUY, GetMainCharacter(), -( nTradeQuantity + unitSize)))  > nPlayerMoney) return;
			nTradeQuantity = nTradeQuantity + unitSize;
			nCurPrice += GetStoreGoodsPrice(&refStore, GetGoodsIndexForI(nCurScrollNum), PRICE_TYPE_BUY, GetMainCharacter(), -(nTradeQuantity)) ;
		}
	}
	if(showType==SHOW_SELL)
	{
		for(i=0; i<mult; i++)
		{
			if(nTradeQuantity + unitSize > nCurQuantity) continue;

			if(tradeLow==false)
			{
				if(nCurPrice + GetStoreGoodsPrice(&refStore, GetGoodsIndexForI(nCurScrollNum), PRICE_TYPE_SELL, GetMainCharacter(), nTradeQuantity/unitSize) >= nStoreMoney) return;
			}
			else
			{
				if(nCurPrice/4*3 + GetStoreGoodsPrice(&refStore, GetGoodsIndexForI(nCurScrollNum), PRICE_TYPE_SELL, GetMainCharacter(), nTradeQuantity/unitSize)/4*3 >= nStoreMoney) return;
			}
			int oldTQ = nTradeQuantity;
	
			nTradeQuantity = nTradeQuantity + unitSize;

			if(tradeLow==false)
				nCurPrice += makeint(GetStoreGoodsPrice(&refStore, GetGoodsIndexForI(nCurScrollNum), PRICE_TYPE_SELL, GetMainCharacter(), oldTQ/unitSize));
			else
				nCurPrice += makeint(GetStoreGoodsPrice(&refStore, GetGoodsIndexForI(nCurScrollNum), PRICE_TYPE_SELL, GetMainCharacter(), oldTQ/unitSize)/4*3);
		}
	}
	RefreshAllStrings();
}

void ScrollChange()
{
	aref pRef;
	string attributeName = "pic" + (nCurScrollNum+1);
	makearef(pRef,GameInterface.scrollitems.(attributeName));
	pRef.img3 = GetGoodStatus(pRef.str1, true);
	pRef.img4 = GetGoodStatus(pRef.str1, false);
	pRef.tex3 = 2; // KK
	pRef.tex4 = 2; // KK
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"SCROLLITEMS",nCurScrollNum);
}

void ProcessCancelExit()
{
//	Event("KB_End"); // KK		// LDH is this really necessary? - 31Jan09

	// Sulan -->
	if(nPlayerMoney > nPlayerMoneyStart)
	{
		WriteNewLogEntry(GetTranslatedLog("Visited")+" "+FindTownName(sTownName),GetTranslatedLog("Visited the local merchant, sold off our cargo and refilled our supplies. The trade earned me")+" "+(nPlayerMoney-nPlayermoneyStart)+" "+GetTranslatedLog("pieces of gold."),"Ship",true);    
	}
	if(nPlayerMoney < nPlayerMoneyStart)
	{
		WriteNewLogEntry(GetTranslatedLog("Visited")+" "+FindTownName(sTownName),GetTranslatedLog("Visited the local merchant to refill our supplies. I had to leave")+" "+(nPlayerMoneyStart-nPlayermoney)+" "+GetTranslatedLog("pieces of gold to the storekeeper."),"Ship",true);
	}
	// Sulan <--

	UpdateTradebook();		// LDH need this here to update from last trade - 04Mar09

	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("frame","ProcessFrame");
    DelEventHandler("BuyPress","ProcessBuy");
    DelEventHandler("SellPress","ProcessSell");
// START MOD Code by Stone-D : 28/07/2003
    DelEventHandler("SellAllPress","SellAllProcess");
	DelEventHandler("SellAllPress2","SellAllProcess2"); // NK, 4-12 bugfix
// END MOD Code by Stone-D : 28/07/2003
    DelEventHandler("OkPress","ProcessOk");
    DelEventHandler("CancelPress","ProcessCancel");
    DelEventHandler("decreaseTrade","ProcessTradeDecrease");
    DelEventHandler("increaseTrade","ProcessTradeIncrease");
    DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievntGetHelpTexture","iprocGetHelpTexture");
	DelEventHandler("ievnt_command","ProcessCommandExecute");

	CargoTransferTimelapse();// TIH transfer time fix Jul20'06

	// TIH --> ship chooser handler Jul17'06
	// has them return to ship chooser or not depending if more than one ship in their fleet
	int numCompanions = GetCompanionQuantity(GetMainCharacter());
	if (numCompanions > 1) {
		nPrevInterface = INTERFACE_SHIP_CHOOSE;// tells it what to do
		interfaceResultCommand = RC_INTERFACE_STORE_EXIT;
		EndOkInterface();// this does the redirect to ship chooser
	} else {
		interfaceResultCommand = RC_INTERFACE_STORE_EXIT;
    	EndCancelInterface(true);
		if(CheckAttribute(GetMainCharacter(),"storekeeper.Idx")) { DeleteAttribute(GetMainCharacter(),"storekeeper.Idx"); }//MAXIMUS
	}
	/* prior method
	interfaceResultCommand = RC_INTERFACE_STORE_EXIT;
    EndCancelInterface(true);
    */
	// TIH <--
}

// NK -->
// moved GetGoodPriceByType and GetGoodQuantityByPrice to StoreUtilite.c
// NK <--

void SetShowMode(int st)
{
	if(showType==st) return;

	switch(showType)
	{
	case SHOW_MAIN:
		DisableString("GoodsName");
		DisableString("GoodsWeight");
		DisableString("BuyPrice");
		DisableString("SellPrice");
		SetNodeUsing("BUY_BUTTON",false);
		SetNodeUsing("INFO_BUTTON",false);
		SetNodeUsing("SELL_BUTTON",false);
		SetNodeUsing("MAIN_IMAGES",false);
		FreezeScreen(false);
	break;

	case SHOW_BUY:
		DisableString("PriceSum");
		DisableString("TradeQuantity");
		DisableString("GoodWeightSum");
		SetNodeUsing("BUYSELL_IMAGES",false);
		SetNodeUsing("OK_BUTTON",false);
		SetNodeUsing("CANCEL_BUTTON",false);
		SetNodeUsing("TRADEQUANTITY",false);
		CreateImage("TradeType","","",0,0,0,0);
	break;

	case SHOW_SELL:
		DisableString("PriceSum");
		DisableString("TradeQuantity");
		DisableString("GoodWeightSum");
		SetNodeUsing("BUYSELL_IMAGES",false);
		SetNodeUsing("OK_BUTTON",false);
		SetNodeUsing("CANCEL_BUTTON",false);
		SetNodeUsing("TRADEQUANTITY",false);
		CreateImage("TradeType","","",0,0,0,0);
	break;

	case SHOW_INFO:
		SetNodeUsing("GOODS_DESCRIBE",false);
		SendMessage(&GameInterface, "lsls", MSG_INTERFACE_MSG_TO_NODE, "INFO_BUTTON", 0, XI_ConvertString("INFO")); // KK
	break;
	}

	showType=st;
	switch(st)
	{
	case SHOW_MAIN:
		EnableString("GoodsName");
		EnableString("GoodsWeight");
		EnableString("BuyPrice");
		EnableString("SellPrice");
		SetNodeUsing("BUY_BUTTON",true);
		SetNodeUsing("INFO_BUTTON",true);
		SetNodeUsing("SELL_BUTTON",true);
		SetNodeUsing("MAIN_IMAGES",true);
	break;

	case SHOW_BUY:
		EnableString("PriceSum");
		EnableString("TradeQuantity");
		EnableString("GoodWeightSum");
		SetNodeUsing("BUYSELL_IMAGES",!LAi_IsCapturedLocation); // KK
		SetNodeUsing("OK_BUTTON",true);
		SetNodeUsing("CANCEL_BUTTON",true);
		SetNodeUsing("TRADEQUANTITY",true);
// KK -->

		switch (LanguageGetLanguage()) {
			case "Polish":
				CreateImage("TradeType","BUY_SELL_POL","buy",126,242,190,306);
			break;
			// default:
			CreateImage("TradeType","BUY_SELL","buy",126,242,190,306);
		}

		FreezeScreen(true);
// <-- KK
	break;

	case SHOW_SELL:
		EnableString("PriceSum");
		EnableString("TradeQuantity");
		EnableString("GoodWeightSum");
		SetNodeUsing("BUYSELL_IMAGES",!LAi_IsCapturedLocation); // KK
		SetNodeUsing("OK_BUTTON",true);
		SetNodeUsing("CANCEL_BUTTON",true);
		SetNodeUsing("TRADEQUANTITY",true);
// KK -->
		switch (LanguageGetLanguage()) {
			case "Polish":
				CreateImage("TradeType","BUY_SELL_POL","sell",450,242,514,306);
			break;
			// default:
			CreateImage("TradeType","BUY_SELL","sell",450,242,514,306);
		}

		FreezeScreen(true);
// <-- KK
	break;

	case SHOW_INFO:
		SetNodeUsing("GOODS_DESCRIBE",true);
		// KK SetCurrentNode("GOODS_DESCRIBE");
		DoGoodsDescribe();
// KK -->
		SendMessage(&GameInterface, "lsls", MSG_INTERFACE_MSG_TO_NODE, "INFO_BUTTON", 0, XI_ConvertString("OK"));
		SetNodeUsing("INFO_BUTTON", true);
		SetCurrentNode("INFO_BUTTON");
		FreezeScreen(true);
// <-- KK
	break;
	}
}

int GetGoodsIndexForI(int n)
{
	string attrName = "pic"+(n+1);
	return sti(GameInterface.scrollitems.(attrName).goodsIndex);
}

int GetGoodsUnitSize()
{
	if(nCurScrollNum<0) return 0;
	return sti( Goods[GetGoodsIndexForI(nCurScrollNum)].Units );
}

string I_strRetVal;
ref iprocGetHelpTexture()
{
	string nodName = GetEventData();

	I_strRetVal = "";
	switch(nodName)
	{
	case "OK_BUTTON":
		if(showType==SHOW_BUY)
		{	I_strRetVal = "interfaces\help\store\store_buy_ok.tga";
		}
		else
		{	I_strRetVal = "interfaces\help\store\store_sell_ok.tga";
		}
	break;

	case "CANCEL_BUTTON":
		if(showType==SHOW_BUY)
		{	I_strRetVal = "interfaces\help\store\store_buy_cancel.tga";
		}
		else
		{	I_strRetVal = "interfaces\help\store\store_sell_cancel.tga";
		}
	break;

	case "TRADEQUANTITY":
		if(showType==SHOW_BUY)
		{	I_strRetVal = "interfaces\help\store\store_buy_quantity.tga";
		}
		else
		{	I_strRetVal = "interfaces\help\store\store_sell_quantity.tga";
		}
	break;
	}

	return &I_strRetVal;
}

void DoGoodsDescribe()
{
	//string goodName;
	//int lngFileID = LanguageOpenFile("GoodsDescribe.txt");
	string goodName = Goods[GetGoodsIndexForI(nCurScrollNum)].Name;
	string goodsDescr = GetAssembledString(TranslateString("", goodName+"_descr"), &Goods[GetGoodsIndexForI(nCurScrollNum)]);
	SetFormatedText("GOODS_DESCRIBE",goodsDescr);
	//LanguageCloseFile(lngFileID);
}

void SetBuySellEnable()
{
	bool sellEnable = false;
	bool buyEnable = false;

	int goodsIdx = GetGoodsIndexForI(nCurScrollNum);
	if(goodsIdx>=0)
	{
		if( GetCargoGoods(refCharacter,goodsIdx)>0 )	{sellEnable = true;}
		if( GetStoreGoodsQuantity(refStore,goodsIdx)>0 && GetStoreGoodsType(refStore, goodsIdx) != TRADE_TYPE_CONTRABAND_NAME)	{buyEnable = true;} // NK
	}

// KK -->
	if (LAi_IsCapturedLocation) {
		sellEnable = true;
		buyEnable = true;
	}
// <-- KK

	SetSelectable("SELL_BUTTON",sellEnable);
	SetSelectable("BUY_BUTTON",buyEnable);
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	switch(nodName)
	{
	case "INFO_BUTTON":
		if(comName=="activate" || comName=="click")
		{	SetShowMode(SHOW_INFO);
		}
		if(comName=="rightstep")
		{	if(GetSelectable("SELL_BUTTON")) {SetCurrentNode("SELL_BUTTON");}
		}
		if(comName=="leftstep")
		{	if(GetSelectable("BUY_BUTTON")) {SetCurrentNode("BUY_BUTTON");}
		}
	break;
	}
}

string GetGoodStatus(string goodName, bool bIsForMy)
{
	int nGoodIdx = FindGood(goodName);

	if(bIsForMy) {
		if( GetCargoGoods(refCharacter,nGoodIdx)>0 ) {return "sell";}
		return "";
	}

	else {
		if( GetStoreGoodsQuantity(refStore,nGoodIdx)>0 ) {return "buy";}
		return "";
	}
}

// START MOD Code by Stone-D : 29/07/2003
// NK -->
void SellAllProcess()
{
	SellAllProcessReal(false);
}

void SellAllProcess2()
{
	SellAllProcessReal(true);
}

// LDH 26Nov06 replaced all refCharacter with mainRef in calls to GetGoodPriceByType()
void SellAllProcessReal(bool reset)
{
	// NK <--
	int c,i,m,p, j;
	int tQuantity, needQty;
	int Quantity;
	string GoodStr;
	ref mainRef = GetMainCharacter();
	m = sti(mainRef.Money);
	c = 0; // NK
/* TIH prior time method replaced by singular function */
	float SupplyScalar = SupplyScalarByCharacter(refCharacter);
	for(i=0;i<GOODS_QUANTITY;i++)
	{
		needQty = 0; // NK
		if( !GetStoreGoodsUsed(refStore,i) ) { continue; }
		GoodStr = Goods[i].name;
// rewritten by MAXIMUS -->
		int needMoney, buyQty;
		int unitSize = sti( Goods[i].Units);
//		tQuantity = GetCargoGoods(refCharacter,i);
		// NK -->
		if(reset)
		{
			if(nPlayerMoney>0)
			{
				if(GetCargoGoods(refCharacter,i) > 0 && CheckAttribute(Goods[i], "noTrade") && sti(Goods[i].noTrade)) needQty = 0; // NK / KNB to skip bombs and other notrade goods 05-04-13
				else
				{
					if(i == GOOD_WHEAT) 
					{ 
						if (FOOD_ON != 1) { 
							needQty = 0;// TIH do not autobuy food if the mod is OFF Jul14'06
						} else {
							buyQty = 1+makeint(makefloat(GetCrewQuantity(refCharacter)) * FOOD_PER_CREW * WHEAT_DAYS * SupplyScalar); // TIH at least 1
							if(GetStoreGoodsQuantity(refStore, i) - buyQty <= tsize * MIN_FOOD_SCALAR) buyQty = 0; // PW check town has food
							if(GetStoreGoodsQuantity(refStore, i) < buyQty) buyQty = 0; //PW check store has quantity required
							needMoney = GetStoreGoodsPrice(&refStore, GetGoodsIndexForI(nCurScrollNum), PRICE_TYPE_BUY, GetMainCharacter(), buyQty/unitSize);
							//if(tradeLow==false) needMoney = GetGoodPriceByType(&refStore, mainRef, i, buyQty,PRICE_TYPE_BUY);
							//else needMoney = GetGoodPriceByType(&refStore, mainRef, i, buyQty,PRICE_TYPE_BUY)/4*3;
							if(needMoney>nPlayerMoney) buyQty = 0;// PW
							needQty = buyQty;//PW
						}
					}
					if(i == GOOD_RUM) 
					{ 
						if (FOOD_ON != 1) { 
							needQty = 0;// TIH do not autobuy food if the mod is OFF Jul14'06
						} else {
							buyQty = 1+makeint(makefloat(GetCrewQuantity(refCharacter)) * FOOD_PER_CREW * RUM_DAYS * SupplyScalar); // TIH at least 1
							if(GetStoreGoodsQuantity(refStore, i) < buyQty) buyQty = 0; //PW check store has quantity required
							needMoney = GetStoreGoodsPrice(&refStore, GetGoodsIndexForI(nCurScrollNum), PRICE_TYPE_BUY, GetMainCharacter(), buyQty/unitSize);
							//if(tradeLow==false) needMoney = GetGoodPriceByType(&refStore, mainRef, i, buyQty,PRICE_TYPE_BUY);
							//else needMoney = GetGoodPriceByType(&refStore, mainRef, i, buyQty,PRICE_TYPE_BUY)/4*3;
							if(needMoney>nPlayerMoney) buyQty = 0;// PW
							needQty = buyQty;//PW
						}
					}
					if(i == GOOD_BALLS) 
					{ 
						buyQty = unitSize * (1 + makeint(makefloat(GetMaxCannonQuantity(refCharacter)) * BALLS_PER * SupplyScalar / unitSize)); 
						if(GetStoreGoodsQuantity(refStore, i) < buyQty) buyQty = 0; //PW check store has quantity required
						needMoney = GetStoreGoodsPrice(&refStore, GetGoodsIndexForI(nCurScrollNum), PRICE_TYPE_BUY, GetMainCharacter(), buyQty/unitSize);
						//if(tradeLow==false) needMoney = GetGoodPriceByType(&refStore, mainRef, i, buyQty,PRICE_TYPE_BUY);
						//else needMoney = GetGoodPriceByType(&refStore, mainRef, i, buyQty,PRICE_TYPE_BUY)/4*3;
						if(needMoney>nPlayerMoney) buyQty = 0;//PW
						needQty = buyQty; //PW
					}
					if(i == GOOD_GRAPES) 
					{ 
						buyQty = unitSize * (1 + makeint(makefloat(GetMaxCannonQuantity(refCharacter)) * GRAPE_PER * SupplyScalar / unitSize)); 
						if(GetStoreGoodsQuantity(refStore, i) < buyQty) buyQty = 0; //PW check store has quantity required
						needMoney = GetStoreGoodsPrice(&refStore, GetGoodsIndexForI(nCurScrollNum), PRICE_TYPE_BUY, GetMainCharacter(), buyQty/unitSize);
						//if(tradeLow==false) needMoney = GetGoodPriceByType(&refStore, mainRef, i, buyQty,PRICE_TYPE_BUY);
						//else needMoney = GetGoodPriceByType(&refStore, mainRef, i, buyQty,PRICE_TYPE_BUY)/4*3;
						if(needMoney>nPlayerMoney) buyQty = 0; //PW
						needQty = buyQty; //PW
					}
					if(i == GOOD_KNIPPELS) 
					{ 
						buyQty = unitSize * (1 + makeint(makefloat(GetMaxCannonQuantity(refCharacter)) * CHAIN_PER * SupplyScalar / unitSize));
						if(GetStoreGoodsQuantity(refStore, i) < buyQty) buyQty = 0; //PW check store has quantity required
						needMoney = GetStoreGoodsPrice(&refStore, GetGoodsIndexForI(nCurScrollNum), PRICE_TYPE_BUY, GetMainCharacter(), buyQty/unitSize);
						//if(tradeLow==false) needMoney = GetGoodPriceByType(&refStore, mainRef, i, buyQty,PRICE_TYPE_BUY);
						//else needMoney = GetGoodPriceByType(&refStore, mainRef, i, buyQty,PRICE_TYPE_BUY)/4*3;
						if(needMoney>nPlayerMoney) needQty = 0; //PW
						needQty = buyQty; //PW
					}
					if(i == GOOD_BOMBS) 
					{ 
						if (USE_REAL_CANNONS) { 
							needQty = 0;// TIH do not autobuy bombs if the mod is ON - in case noTrade is not set  Jul14'06
						} else {
							buyQty = unitSize * (1 + makeint(makefloat(GetMaxCannonQuantity(refCharacter)) * BOMBS_PER * SupplyScalar / unitSize)); 
							if(GetStoreGoodsQuantity(refStore, i) < buyQty) buyQty = 0; //PW check store has quantity required
							needMoney = GetStoreGoodsPrice(&refStore, GetGoodsIndexForI(nCurScrollNum), PRICE_TYPE_BUY, GetMainCharacter(), buyQty/unitSize);
							//if(tradeLow==false) needMoney = GetGoodPriceByType(&refStore, mainRef, i, buyQty,PRICE_TYPE_BUY);
							//else needMoney = GetGoodPriceByType(&refStore, mainRef, i, buyQty,PRICE_TYPE_BUY)/4*3;
							if(needMoney>nPlayerMoney) needQty = 0; //PW
							needQty = buyQty; //PW
						}
					}
				// added by MAXIMUS [gunpowder mod] --> // TIH --> fixed slop  7-7-06
					if(i == GOOD_GUNPOWDER) 
					{ 
						if (!CANNONPOWDER_MOD || GetMaxCannonQuantity(refCharacter) <= 0) {// do not buy if they have no cannons 
							needQty = 0;// TIH do not autobuy cannonpowder if the mod is OFF - in case noTrade is not set  Jul14'06
						} else {
							ref rCannon; makeref(rCannon,Cannon[GetCaracterShipCannonsType(refCharacter)]);// TIH typo fix
							int needPwdr = 0;

							// LDH 23Apr09
							// Note that the character can have bombs even if USE_REAL_CANNONS is off
							int shotQty = GetCargoGoods(refCharacter,GOOD_BALLS) + GetCargoGoods(refCharacter,GOOD_GRAPES) + GetCargoGoods(refCharacter,GOOD_KNIPPELS) + GetCargoGoods(refCharacter,GOOD_BOMBS);
							int PowderPerShot = 0;
							if(CheckAttribute(rCannon,"gunpowder")) PowderPerShot = sti(rCannon.gunpowder);
							buyQty = unitSize *(1 + makeint(POWDER_PER * shotQty * PowderPerShot * SupplyScalar/unitSize));	// enough powder to fire POWDER_PER times the ammo you have on board
							if(GetStoreGoodsQuantity(refStore, i) < buyQty) buyQty = 0; //PW check store has quantity required
							needMoney = GetStoreGoodsPrice(&refStore, GetGoodsIndexForI(nCurScrollNum), PRICE_TYPE_BUY, GetMainCharacter(), buyQty/unitSize);
							//if(tradeLow==false) needMoney = GetGoodPriceByType(&refStore, mainRef, i, buyQty,PRICE_TYPE_BUY);
							//else needMoney = GetGoodPriceByType(&refStore, mainRef, i, buyQty,PRICE_TYPE_BUY)/4*3;
							if(needMoney>nPlayerMoney) buyQty = 0; //PW
							needQty = buyQty;
						}
					}
				// added by MAXIMUS [gunpowder mod] <-- // TIH <-- fixed slop
					if(i == GOOD_SAILCLOTH) 
					{ 
						buyQty = makeint(makefloat(GetCharacterShipHP(refCharacter)) * SAIL_PER * SupplyScalar);// TIH RE-typo typo fix
						needMoney = GetStoreGoodsPrice(&refStore, GetGoodsIndexForI(nCurScrollNum), PRICE_TYPE_BUY, GetMainCharacter(), buyQty/unitSize);
						//if(tradeLow==false) needMoney = GetGoodPriceByType(&refStore, mainRef, i, buyQty,PRICE_TYPE_BUY);
						//else needMoney = GetGoodPriceByType(&refStore, mainRef, i, buyQty,PRICE_TYPE_BUY)/4*3;
						if(needMoney>nPlayerMoney) needQty = 0;
						else needQty = buyQty;
					}
					if(i == GOOD_PLANKS) 
					{ 
						buyQty = makeint(makefloat(GetCharacterShipHP(refCharacter)) * PLANKS_PER * SupplyScalar); 
						needMoney = GetStoreGoodsPrice(&refStore, GetGoodsIndexForI(nCurScrollNum), PRICE_TYPE_BUY, GetMainCharacter(), buyQty/unitSize);
						//if(tradeLow==false) needMoney = GetGoodPriceByType(&refStore, mainRef, i, buyQty,PRICE_TYPE_BUY);
						//else needMoney = GetGoodPriceByType(&refStore, mainRef, i, buyQty,PRICE_TYPE_BUY)/4*3;
						if(needMoney>nPlayerMoney) needQty = 0;
						else needQty = buyQty;
					}
				}
			}
		}
			
		tQuantity = GetCargoGoods(refCharacter,i); // moved here by MAXIMUS
// rewritten by MAXIMUS <--
//		if( reset && needQty <= 0 ) { continue; }	// TIH bugfix [commented out by MAXIMUS for old-style AUTOBUY function]
		if( reset && needQty > 0 )					// TIH bugfix
		{
			// PW: revised calculations -->
			if(needQty > tQuantity)
			{
				int nTQ = 0;
				tQuantity = needQty - tQuantity;
				p=0;
				Quantity = tQuantity/sti( Goods[i].Units ) ;
				for(j=0; j<Quantity; j++)
				{
					nTQ = nTQ + sti( Goods[i].Units );
					p += GetStoreGoodsPrice(refStore, i, PRICE_TYPE_BUY, GetMainCharacter(),-(nTQ));
				//	p += GetGoodPriceByType(&refStore, GetMainCharacter(), i, j, PRICE_TYPE_BUY); // NK//PW
				}
			// PW: revised calculations <--
				SetStoreGoods(refStore,i,GetStoreGoodsQuantity(refStore,i) - tQuantity);
				SetCharacterGoods(refCharacter,i,needQty);
				//p = -p;
				nPlayerMoney -= p;
				nStoreMoney += p;
				c = c + p;
				Log_SetStringToLog(XI_ConvertString(GoodStr) + ": " + tQuantity + " : " + p);
				// LDH log high trades - 31Dec08
				if (abs(p) >= HIGH_TRADE)
				{
					string strTrade = "TRADING: ";
					strTrade += StrLeft(refCharacter.location+":                    ", 20);
					if (p < 0) strTrade += " Bought ";
					else strTrade += " Sold ";
					strTrade += tQuantity + " " + GoodStr + " for " + abs(p);
					Trace(strTrade);
				}
				tQuantity = 0;
			}
			else
			{
				tQuantity = tQuantity - needQty;
			}
		}
		if( tQuantity <= 0 ) { continue; }			// TIH bugfix
		// NK <--
		p=0;
// LDH 26Nov06 replaced refCharacter with mainRef for quest goods
		// TIH --> prevent the auto-sale of QUEST cargo from merchant jobs! Aug30'06
		if (CheckAttribute(mainRef, "quest.generate_trade_quest.iQuantityGoods")) 
		{
			int iQuantityShipGoods = sti(mainRef.quest.generate_trade_quest.iQuantityGoods);
			int iQuestTradeGoods = sti(mainRef.quest.generate_trade_quest.iTradeGoods);
			if ( i == iQuestTradeGoods ) 
			{
				if ( tQuantity > iQuantityShipGoods ) 
				{
					tQuantity = tQuantity - iQuantityShipGoods; // ready to sell off extra
				}
				else { continue; }// dont sell off what you need to complete the quest
			}
		}
		//TIH <--
		//PW -->revised calculations
		Quantity = tQuantity/sti( Goods[i].Units );
		for(j=0; j<Quantity; j++)
		{
			if(tradeLow==false) p += makeint(GetStoreGoodsPrice(refStore, i, PRICE_TYPE_SELL, GetMainCharacter(), j));
			else 				p += makeint(GetStoreGoodsPrice(refStore, i, PRICE_TYPE_SELL, GetMainCharacter(), j)/4*3); // NK
		}
		//tQuantity = tQuantity * GetGoodsUnitSize() ;
//<--PW revised calculations
		SetStoreGoods(refStore,i,GetStoreGoodsQuantity(refStore,i)+tQuantity);
		RemoveCharacterGoods(refCharacter,i,tQuantity);

		nPlayerMoney += p;
		nStoreMoney -= p; // NK
		c = c + p;
		Log_SetStringToLog(XI_ConvertString(GoodStr) + ": " + tQuantity + " : " + p);
		// LDH log high trades - 31Dec08
		if (abs(p) >= HIGH_TRADE)
		{
			strTrade = "TRADING: ";
			strTrade += StrLeft(refCharacter.location+":                    ", 20);
			if (p < 0) strTrade += " Bought ";
			else strTrade += " Sold ";
			strTrade += tQuantity + " " + GoodStr + " for " + abs(p);
			Trace(strTrade);
		}
	}

	if(nPlayerMoney<=0) nPlayerMoney = 0; // added by MAXIMUS
	mainRef.Money = nPlayerMoney;
	if(sTownName != "") SetTownGold(sTownName, nStoreMoney); // NK
	Log_SetStringToLog(XI_ConvertString("Cash") + ": " + m + stringRet(c>=0," +"," ") + c + " = " + mainRef.Money);
	if(AUTO_SKILL_SYSTEM)
	{
		AddPartyExpChar(refCharacter, "Commerce", makeint(sti(c)/10));
		if(CheckAttribute(refCharacter,"storekeeper.Idx") && sti(refCharacter.storekeeper.Idx)!=-1) { AddCharacterExpNSChar(&characters[sti(refCharacter.storekeeper.Idx)], "Commerce", makeint(sti(c)/10)); }
	}
//	Log_SetStringToLog("");// TIH gets excessive Aug24'06
	UpdateScroll();
	SetShowMode(SHOW_MAIN);
	RefreshAllStrings();
	SetBuySellEnable();
 // added by MAXIMUS -->
	if(oldCurNode=="SELLEVERYTHING_BUTTON") { SetSelectable("SELLEVERYTHING_BUTTON",false); SetSelectable("SELLALL_BUTTON",true); }
	if(oldCurNode=="SELLALL_BUTTON") { SetSelectable("SELLEVERYTHING_BUTTON",true); SetSelectable("SELLALL_BUTTON",false); }
 // added by MAXIMUS <--
	SetCurrentNode("SCROLLITEMS");
}

void UpdateScroll()
{
	int numItems=GameInterface.scrollitems.ListSize;
	int i;
	aref pRef;

	for(i=0; i<numItems; i++)
	{
		string attributeName = "pic"+(i+1);
		makearef(pRef,GameInterface.scrollitems.(attributeName));
		pRef.img3 = GetGoodStatus(pRef.str1, true);
		pRef.img4 = GetGoodStatus(pRef.str1, false);
		pRef.tex3 = 2; // KK
		pRef.tex4 = 2; // KK
		SendMessage(&GameInterface,"lsl", MSG_INTERFACE_SCROLL_CHANGE, "SCROLLITEMS", i);
	}
}

// END MOD Code by Stone-D : 29/07/2003

// TIH --> proper time spent loading/unloading cargo Jul20'06
// divide by zero fix, time calc adjustment, prevents months (even a year) lost buying ammo or unloading whole ships
// first function logs their starting cargo numbers - called in interface initialization
// second function figures out how much time it will take after you are done dealing with all cargo - called when exiting interface
// changed to base it off WEIGHT not UNITS (imagine buying 15000 gunpowder (only 50 weight), you could lose 100 days with a small crew!!!)
void CreateStartingCargo()
{
	if( CheckAttribute(refCharacter,"startingCargo") ) DeleteAttribute(refCharacter,"startingCargo");
	int i;
	string sfstr;
	for(i=0;i<GOODS_QUANTITY;i++)
	{
		sfstr = "good" + i;
		refCharacter.startingCargo.(sfstr) = GetCargoGoods(refCharacter,i);
	}

}
void CargoTransferTimelapse()
{
	ref mainRef = GetMainCharacter();	// LDH 26Nov06 added

	if( TIME_MOVEGOOD < 1 ) 									{return;} // no need to bother if the mod has been disabled
	if( CheckAttribute(GetMainCharacter(),"skipstoretime") ) 	{return;} // tutorial has no time spendature
	if( !CheckAttribute(refCharacter,"startingCargo") ) 		{return;} // no attribute? no execute

	int goodsTransfer = 0;
	int newQty = 0;
	int oldQty = 0;
	string attrGood = "";

	// go through their hold, and see what changed
	// if no quantities changed for a good, then OBVIOUSLY you dont spend time transfering it !!!
	int i;
	string sfstr;
	for(i=0;i<GOODS_QUANTITY;i++)
	{
		sfstr = "good" + i;
		newQty = GetCargoGoods(refCharacter,i);
		oldQty = refCharacter.startingCargo.(sfstr);
		
		// if a change in quantity, add it to transfer
		if ( newQty != oldQty ) {
			goodsTransfer += makeint( ( abs(newQty - oldQty) / sti( Goods[i].Units ) ) * sti( Goods[i].Weight ) );
		}
	}
	DeleteAttribute(refCharacter,"startingCargo");

	if ( goodsTransfer <= 0 ) return; // dont do anything if no goods to move about

	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");// MAXIMUS

	LogIt(LanguageConvertString(tmpLangFileID,"Crew begins transfer of") + " " + goodsTransfer + " " + LanguageConvertString(tmpLangFileID,"cwt of cargo."));

	// now figure out the calculation of how long your crew will take
//	int crewNum = GetCrewQuantity(refCharacter);
	int crewNum = GetSquadronCrewQuantity(mainRef);	// LDH 26Nov06
	if (crewNum < 1) crewNum = 1;// if no crew, then captain alone has to transfer the goods

	float leaderDivisor = makefloat( GetShipSkill(mainRef, SKILL_LEADERSHIP) * 0.05 );// leadership reduces time wasted
	if (leaderDivisor <= 0) leaderDivisor = 0.01;// if a seriously poor leader (skill 0), then set to lowest

	int timeToAdd = 60 + makeint(((TIME_MOVEGOOD * goodsTransfer) / crewNum) / leaderDivisor);// takes at least one hour
	if ( timeToAdd > 10080 ) timeToAdd = 10080;// never go above 7 days for ANY transfer

	// LDH 16Oct06 changed rounding to more accurately reflect time passed
	if ( timeToAdd > 1440 ) { 
//		if ( makeint(round(timeToAdd/1440)) < 2 ) 	LogIt(LanguageConvertString(tmpLangFileID,"Transfer takes roughly a day"));// MAXIMUS
		if ( round(timeToAdd/1440) < 1.5 ) 			LogIt(LanguageConvertString(tmpLangFileID,"Transfer takes roughly a day"));// MAXIMUS
		else 										LogIt(LanguageConvertString(tmpLangFileID,"Transfer takes roughly") + " " + makeint(round(timeToAdd/1440)) + " " + XI_ConvertString("days"));// MAXIMUS
	} else {
//		if ( makeint(round(timeToAdd/60)) < 2 ) 	LogIt(LanguageConvertString(tmpLangFileID,"Transfer takes roughly an hour"));// MAXIMUS
		if ( round(timeToAdd/60) < 1.5 ) 			LogIt(LanguageConvertString(tmpLangFileID,"Transfer takes roughly an hour"));// MAXIMUS
		else 										LogIt(LanguageConvertString(tmpLangFileID,"Transfer takes roughly") + " " + makeint(round(timeToAdd/60)) + " " + XI_ConvertString("hours"));// MAXIMUS
	}

	AddTimeToCurrent(0, timeToAdd );
	LogIt(TranslateString("","Time:") +" "+ GetStringTime(GetTime()));		// LDH 15Oct06 added time display
	LanguageCloseFile(tmpLangFileID);
}
// TIH <--

// KK -->
void FreezeScreen(bool bSet)
{
	bSet = !bSet;
	SetSelectable("ITEMSLIST", bSet);
	SetNodeUsing("LEFTSCROLLBUTTON", bSet);
	SetNodeUsing("RIGHTSCROLLBUTTON", bSet);
	SetSelectable("SELLALL_BUTTON", bSet);
	SetSelectable("SELLEVERYTHING_BUTTON", bSet);
}
// <-- KK

void UpdateTradebook()		// LDH code moved to its own function - 04Mar09
{
// added by MAXIMUS [for TradeBook update] -->
	refStore.STORE_CURDATE = GetHumanDate(GetDataYear(),GetDataMonth(),GetDataDay()); // PB: Looks more 'real' with a written date and without the time
	for(int g=0; g<GOODS_QUANTITY; g++)
	{
		for(int i=0; i<7; i++)
		{
			string impAttr1, expAttr1, conAttr1, impAttr2, expAttr2, conAttr2, tradeAttr;
			int sellPrice, buyPrice;
			impAttr1 = "importsell"+i;
			expAttr1 = "exportsell"+i;
			conAttr1 = "contrasell"+i;
			impAttr2 = "importbuy"+i;
			expAttr2 = "exportbuy"+i;
			conAttr2 = "contrabuy"+i;
			tradeAttr = "id"+(i+1);
			ref mainChar = GetMainCharacter();// MAXIMUS bug fix
			aref curIsland; makearef(curIsland,Islands[GetIslandIdxByLocationIdx(FindLocation(mainChar.location))]);// MAXIMUS bug fix

			// LDH moved price calculations inside if statements for speed 04Mar09
			if(CheckAttribute(curIsland,"Trade.Import.id"+(i+1)))
			{
				if(curIsland.Trade.Import.(tradeAttr)==g)
				{
					sellPrice = GetStoreGoodsPrice(refStore,FindGood(Goods[g].Name),PRICE_TYPE_SELL,GetMainCharacter(), 0);
					buyPrice  = GetStoreGoodsPrice(refStore,FindGood(Goods[g].Name),PRICE_TYPE_BUY,GetMainCharacter(), 0);
					refStore.(impAttr1) = sellPrice;
					refStore.(impAttr2) = buyPrice;
				}
			}
			if(CheckAttribute(curIsland,"Trade.Export.id"+(i+1)))
			{
				if(curIsland.Trade.Export.(tradeAttr)==g)
				{
					sellPrice = GetStoreGoodsPrice(refStore,FindGood(Goods[g].Name),PRICE_TYPE_SELL,GetMainCharacter(), 0);
					buyPrice  = GetStoreGoodsPrice(refStore,FindGood(Goods[g].Name),PRICE_TYPE_BUY,GetMainCharacter(), 0);
					refStore.(expAttr1) = sellPrice;
					refStore.(expAttr2) = buyPrice;
				}
			}
			if(CheckAttribute(curIsland,"Trade.Contraband.id"+(i+1)))
			{
				if(curIsland.Trade.Contraband.(tradeAttr)==g)
				{
					sellPrice = GetStoreGoodsPrice(refStore,FindGood(Goods[g].Name),PRICE_TYPE_SELL,GetMainCharacter(), 0);
					buyPrice  = GetStoreGoodsPrice(refStore,FindGood(Goods[g].Name),PRICE_TYPE_BUY,GetMainCharacter(), 0);
					refStore.(conAttr1) = sellPrice;
					refStore.(conAttr2) = buyPrice;
				}
			}
		}
	}
// added by MAXIMUS [for TradeBook update] <--
}
