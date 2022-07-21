#define SHOW_MAIN		0
#define SHOW_BUY		1
#define SHOW_SELL		2
#define SHOW_DESCRIBE	3

int	nCurScrollNum = -1;
string curItemGroup = ""; // KK
int showType = -1;
string oldCurNode = "";

ref refMyCh;
ref refTrader;

int nTradeQuantity = 0;
float buyratio = 1.0; // NK 05-04-08
bool useskill = true; // NK 05-04-08

int idLngFile = -1;
int buyPrice = 0;
int sellPrice = 0;
int nPlayerMoneyStart;
//bool anytrades = false; // TIH not needed anymore Aug24'06 - NK 05-04-07 to keep track of how often you use trader.
object gTradetracker; // TIH used to track trades to level up merchant Aug24'06

bool bEnableDown = true;

void InitInterface_RR(string iniName,ref pChar,ref pTrader)
{
	refTrader = pTrader;
	refMyCh = pChar;
	nPlayerMoneyStart = sti(refMyCh.Money);
	refTrader.dayssincelasttrade = 0;
	string tid = refTrader.id;
	if(CheckAttribute(ShipLookupTable, "itemtraders."+tid)) { ShipLookupTable.itemtraders.(tid) = true; }
	buyratio = 1.0;
	useskill = true;
	if(CheckAttribute(refTrader, "itemtrade.pricebuyratio")) buyratio = stf(refTrader.itemtrade.pricebuyratio); // NK 05-04-08
	if(CheckAttribute(refTrader, "itemtrade.pricenoskill")) useskill = !sti(refTrader.itemtrade.pricenoskill); // NK 05-04-08

// KK -->
	if (!LAi_IsCapturedLocation) {
		GameInterface.title = "titleItemsTrade";
		if (HasSubStr(pChar.location, "store")) {
			GameInterface.title = "titleStore"; //MAXIMUS
		}
	} else {
		GameInterface.title = "titleRansack";
	}

	curItemGroup = GUN_ITEM_TYPE;
	FillSelectedScroll();
// <-- KK

	//FillScroll();
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

// KK -->
	if (LAi_IsCapturedLocation) {
		SendMessage(&GameInterface, "lsls", MSG_INTERFACE_MSG_TO_NODE, "BUY_BUTTON", 0, XI_ConvertString("Take"));
		SendMessage(&GameInterface, "lsls", MSG_INTERFACE_MSG_TO_NODE, "SELL_BUTTON", 0, XI_ConvertString("Leave"));
	}
// <-- KK
	CreateExitString();//MAXIMUS: standard exit-string for exit-button

	SetCurrentNode("ITEMSLIST");

	CreateString(true,"Money","",FONT_NORMAL,COLOR_MONEY,173,393,SCRIPT_ALIGN_LEFT,0.9); // NK itemtrade 05-04-02 was 320,389,center,1.0
	CreateString(true,"SMoney","",FONT_NORMAL,COLOR_MONEY,467,393,SCRIPT_ALIGN_RIGHT,0.9); // NK itemtrade 05-04-02
	if(CheckAttribute(refMyCh,"firstname")==true) CreateString(true,"ChrName",refMyCh.name + " " + refMyCh.firstname + " " + refMyCh.lastname,FONT_NORMAL,COLOR_NORMAL,320,203,SCRIPT_ALIGN_CENTER,1.0);
	else CreateString(true,"ChrName",refMyCh.name + " " + refMyCh.lastname,FONT_NORMAL,COLOR_NORMAL,320,203,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"ItemsName","",FONT_NORMAL,COLOR_NORMAL,320,245,SCRIPT_ALIGN_CENTER,0.8);
	CreateString(true,"BuyPrice","",FONT_BOLD_NUMBERS,COLOR_NORMAL,260,307,SCRIPT_ALIGN_RIGHT,0.75);
	CreateString(true,"SellPrice","",FONT_BOLD_NUMBERS,COLOR_NORMAL,380,307,SCRIPT_ALIGN_LEFT,0.75);
	CreateString(true,"OnMyQuantity","",FONT_BOLD_NUMBERS,COLOR_NORMAL,79,413,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"OnTraderQuantity","",FONT_BOLD_NUMBERS,COLOR_NORMAL,561,413,SCRIPT_ALIGN_CENTER,1.0);

	CreateString(false,"PriceSum","",FONT_NORMAL,COLOR_NORMAL,324,245,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(false,"TradeQuantity","",FONT_NORMAL,COLOR_NORMAL,320,292,SCRIPT_ALIGN_CENTER,1.0);

	CreateString(TRUE,"itemname","",FONT_NORMAL,COLOR_NORMAL,320,475,SCRIPT_ALIGN_CENTER,0.8); // NK

	SetNodeUsing("BUYSELL_IMAGES",false);
	SetNodeUsing("OK_BUTTON",false);
	SetNodeUsing("CANCEL_BUTTON",false);
	SetNodeUsing("TRADEQUANTITY",false);
	SetNodeUsing("TEXTWINDOW",false);

	SetSelectable("EXIT_BUTTON",true);

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("frame","ProcessFrame",1);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);

// KK -->
	//SetSelectable("I_WEAPON", false);
	if (!LAi_IsCapturedLocation) {
		SetNodeUsing("SELL_LOOT_BUTTON",true);
		SetSelectable("SELL_LOOT_BUTTON",true);
	} else {
		SetNodeUsing("SELL_LOOT_BUTTON",false);
	}
// <-- KK
// LDH Fix
//	SetCurrentNode("SELL_LOOT_BUTTON");

// JRH -->
	if(CheckAttribute(refTrader,"id"))
	{
		if(refTrader.id == "pir_cap1" || refTrader.id == "pir_cap8" || refTrader.id == "pir_cap16"
		|| refTrader.id == "pir_cap18" || refTrader.id == "pir_cap23" || refTrader.id == "GB_storeowner")
		{		
			SetSelectable("SELL_LOOT_BUTTON",false);
		}
	}
// <-- JRH
}

void ProcessFrame()
{
	if(oldCurNode!=GetCurrentNode())
	{
		oldCurNode = GetCurrentNode();
		if(oldCurNode=="ITEMSLIST")
		{
			nCurScrollNum = -1;
		}
	}

	if(sti(GameInterface.itemslist.current)!=nCurScrollNum)
	{
		nCurScrollNum = sti(GameInterface.itemslist.current);
		SetShowMode(SHOW_MAIN);
		RefreshAllStrings();
		return;
	}

// KK -->
	if (showType == SHOW_MAIN) FreezeScreen(false);
// <-- KK
}

void RefreshAllStrings()
{
	int priceSum;
	string itmName = GetItemsID(nCurScrollNum);
	aref refitm;
	int itmIdx = Items_FindItem(itmName,&refitm);
	ref mchref = GetMainCharacter();

	if(itmIdx>=0)
	{
		GameInterface.strings.Money = MakeMoneyShow(sti(mchref.money),MONEY_SIGN,MONEY_DELIVER);
// KK -->
		SetNodeUsing("MAIN_IMAGES", showType == SHOW_MAIN);
		SetSelectable("INFO_BUTTON", true);
		int traderMoney = 0;
		if (!LAi_IsCapturedLocation) traderMoney = GetCharacterMoney(&refTrader);
		if(CheckAttribute(refTrader,"itemtrade.quality")) GameInterface.strings.SMoney = TranslateString("","Qual") + " " + refTrader.itemtrade.quality + ",   " + MakeMoneyShow(traderMoney,MONEY_SIGN,MONEY_DELIVER); // NK itemtrade 05-04-02
		if(CheckAttribute(refitm,"name"))
		{
			// scheffnow - weaponsmod -->
			string sIName = "";
			if (CheckAttribute(refitm, "QualityName")) sIName = TranslateString("", "q"+refitm.QualityName); // LDH added quality "q" translation string - 07May09

			// MAXIMUS 31.05.2019: corrected for russian spelling ==>
			switch(LanguageGetLanguage())
			{
				case "Russian":
					GameInterface.strings.ItemsName = GetAssembledString(TranslateString("", refitm.name), refitm) + " " + sIName;
				break;
				GameInterface.strings.ItemsName = sIName + " " + GetAssembledString(TranslateString("", refitm.name), refitm);
			}
			// MAXIMUS 31.05.2019: corrected for russian spelling <==

			// scheffnow - weaponsmod <--
		} else {
			GameInterface.strings.ItemsName = "";
		}
// <-- KK
		buyPrice = GetTradeItemPrice(itmIdx,PRICE_TYPE_BUY);
		sellPrice = GetTradeItemPrice(itmIdx,PRICE_TYPE_SELL);
		GameInterface.strings.BuyPrice = buyPrice;
		GameInterface.strings.SellPrice = sellPrice;
		GameInterface.strings.OnMyQuantity = GetCharacterItem(refMyCh,itmName);
		GameInterface.strings.OnTraderQuantity = GetCharacterItem(refTrader,itmName);

		GameInterface.strings.TradeQuantity = nTradeQuantity;
		if(showType==SHOW_BUY)
		{	priceSum = nTradeQuantity * GetTradeItemPrice(itmIdx,PRICE_TYPE_BUY);
		}
		else
		{	priceSum = nTradeQuantity * GetTradeItemPrice(itmIdx,PRICE_TYPE_SELL);
		}
		GameInterface.strings.priceSum = priceSum;

		if(showType==SHOW_DESCRIBE)
		{
			SetItemDescribe(refitm);
		}

		SetSelectable("BUY_BUTTON",true);
		SetSelectable("SELL_BUTTON",true);
		if (LAi_IsCapturedLocation == false && buyPrice <= 1) // KK
		{
			SetSelectable("BUY_BUTTON",false);
			SetSelectable("SELL_BUTTON",false);
			ShowHelpString("chelp_itemstrade#10");
			return;
		}

		// TIH --> allow the sell of equipped items, except equipped spyglass, its special Jul15'06
		//if( GetCharacterItem(refMyCh,itmName)==1 && ItemUsedByCharacter(itmIdx) )// old method
		/*if( GetCharacterItem(refMyCh,itmName)==1 && ItemUsedByCharacter(itmIdx) && Items[GetItemIndex(itmName)].groupID == SPYGLASS_ITEM_TYPE )
		{
			SetSelectable("SELL_BUTTON",false);
			ShowHelpString("chelp_itemstrade#11");
			return;
		}*/
		// TIH <--

		SetSelectable("BUY_BUTTON",GetCharacterItem(refTrader,itmName) > 0);
		SetSelectable("SELL_BUTTON", false);
		int quantity = GetCharacterItem(refMyCh, itmName);
		int isEquiped = IsEquipCharacterByItem(refMyCh, itmName);
		if (isEquiped == true && quantity > 0) SetSelectable("SELL_BUTTON", true);
		if (isEquiped == true && Items[GetItemIndex(itmName)].groupID == SPYGLASS_ITEM_TYPE && quantity == 1) SetSelectable("SELL_BUTTON", false);
		if (isEquiped == false && quantity > 0) SetSelectable("SELL_BUTTON", true);

	//JRH -->
		if(CheckAttribute(refTrader,"id") && refTrader.id == "pir_cap8")
		{
			//La Bouche
			SetSelectable("BUY_BUTTON",false);
			SetSelectable("SELL_LOOT_BUTTON",false);

			if(itmName == "jewelcross" || itmName == "fake_chalice"
			|| itmName == "fake_candelabre" || itmName == "fake_censer")
			SetSelectable("SELL_BUTTON",false);

			if(itmName == "fake_reliquary" && CheckCharacterItem(mchref,"fake_reliquary"))
			SetSelectable("SELL_BUTTON",true);

			return;
		}

		if(CheckAttribute(refTrader,"id") && refTrader.id == "pir_cap1")
		{
			//Vane
			SetSelectable("BUY_BUTTON",false);
			SetSelectable("SELL_LOOT_BUTTON",false);

			if(itmName == "fake_reliquary" || itmName == "fake_chalice"
			|| itmName == "fake_candelabre" || itmName == "fake_censer")
			SetSelectable("SELL_BUTTON",false);

			if(itmName == "jewelcross" && CheckCharacterItem(mchref,"jewelcross"))
			SetSelectable("SELL_BUTTON",true);

			return;
		}

		if(CheckAttribute(refTrader,"id") && refTrader.id == "pir_cap16")
		{
			//Roberts
			SetSelectable("BUY_BUTTON",false);
			SetSelectable("SELL_LOOT_BUTTON",false);

			if(itmName == "jewelcross" || itmName == "fake_reliquary"
			|| itmName == "fake_candelabre" || itmName == "fake_chalice")
			SetSelectable("SELL_BUTTON",false);

			if(itmName == "fake_censer" && CheckCharacterItem(mchref,"fake_censer"))
			SetSelectable("SELL_BUTTON",true);

			return;
		}

		if(CheckAttribute(refTrader,"id") && refTrader.id == "pir_cap18")
		{
			//Rackham
			SetSelectable("BUY_BUTTON",false);
			SetSelectable("SELL_LOOT_BUTTON",false);

			if(itmName == "jewelcross" || itmName == "fake_reliquary"
			|| itmName == "fake_censer" || itmName == "fake_chalice")
			SetSelectable("SELL_BUTTON",false);

			if(itmName == "fake_candelabre" && CheckCharacterItem(mchref,"fake_candelabre"))
			SetSelectable("SELL_BUTTON",true);

			return;
		}

		if(CheckAttribute(refTrader,"id") && refTrader.id == "pir_cap23")
		{
			//Taylor
			SetSelectable("BUY_BUTTON",false);
			SetSelectable("SELL_LOOT_BUTTON",false);

			if(itmName == "jewelcross" || itmName == "fake_reliquary"
			|| itmName == "fake_candelabre" || itmName == "fake_censer")
			SetSelectable("SELL_BUTTON",false);

			if(itmName == "fake_chalice" && CheckCharacterItem(mchref,"fake_chalice"))
			SetSelectable("SELL_BUTTON",true);

			return;
		}

		if(itmName =="coin1" || itmName=="coin2" || itmName=="coin3"|| itmName=="coin4" || itmName=="coin5" || itmName=="coin6" || itmName=="coin7"|| itmName=="coin8"
		|| itmName=="coin9" || itmName=="coin10" || itmName=="coin12" || itmName=="coin13" || itmName=="coin14"|| itmName=="coin15" || itmName=="coin16")
		{
			SetSelectable("SELL_BUTTON",false);
			SetSelectable("SELL_LOOT_BUTTON",false);
		}

		if(CheckAttribute(refTrader,"id")  )
		{
			if(refTrader.id == "GB_storeowner" || refTrader.id == "merchant1" || refTrader.id == "merchant2" || refTrader.id == "merchant3" || refTrader.id == "merchant4"
			|| refTrader.id == "merchant5" || refTrader.id == "merchant6" || refTrader.id == "merchant7" || refTrader.id == "merchant8" || refTrader.id == "merchant9" || refTrader.id == "merchant10")
			{
				SetSelectable("SELL_LOOT_BUTTON",false);
				if(itmName =="gunpowder") SetSelectable("SELL_BUTTON",false);
			}
		}
	//<-- JRH

		SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"CONTEXTHELP", 0);
	}
	else
	{
		SetSelectable("BUY_BUTTON",false);
		SetSelectable("SELL_BUTTON",false);
// KK -->
		GameInterface.strings.BuyPrice = "";
		GameInterface.strings.SellPrice = "";
		GameInterface.strings.ItemsName = "";
		SetSelectable("INFO_BUTTON", false);
		SetNodeUsing("MAIN_IMAGES", false);
// <-- KK
	}
}

bool ItemUsedByCharacter(int itmIdx)
{
	if(itmIdx<0 || itmIdx>=ITEMS_QUANTITY) return false;
	return IsEquipCharacterByItem(GetMainCharacter(),Items[itmIdx].id);
}

int GetTradeItemPrice(int itmIdx, int tradeType)
{
	int itmprice = 0;
	if(itmIdx<0 || itmIdx>ITEMS_QUANTITY) return 0;
	if (LAi_IsCapturedLocation) return 0; // KK

	if(CheckAttribute(&Items[itmIdx],"price"))
	{
		itmprice = sti(Items[itmIdx].price);
	}

	float skillModify = 1.0; // NK 05-04-09
	if(useskill) skillModify = GetCharPriceMod(&refMyCh, tradeType, true, false); // NK now use central func 05-04-19
	if(tradeType==PRICE_TYPE_SELL)
	{
		skillModify *= buyratio; // NK 05-04-09
	}

	return makeint(makefloat(GetItemPriceTrader(&refTrader, Items[itmIdx].id))*skillModify); // NK itemtrade 05-04-02 return makeint(makefloat(itmprice)*skillModify);
}

// KK -->
void ChangeSelectedScroll()
{
	DeleteAttribute(&GameInterface,"itemslist");
	FillSelectedScroll();
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"ITEMSLIST",-1);
	SetCurrentNode("ITEMSLIST");
	SetSelectable("I_WEAPON", curItemGroup == GUN_ITEM_TYPE);
	SetSelectable("I_POTION", curItemGroup == POTION_ITEM_TYPE);
	SetSelectable("I_ITEMS", curItemGroup == OBJECT_ITEM_TYPE);
	SetSelectable("I_MAP", curItemGroup == MAP_ITEM_TYPE);
}
// <-- KK

void FillSelectedScroll()
{
	int idx,i;
	string attributeName;
	string itemName;

	aref arImgGrp;
	makearef(arImgGrp,GameInterface.itemslist.ImagesGroup);
	arImgGrp.t0 = "ICONS";
	arImgGrp.t1 = "usedflag";
	// KK -->
	if (!LAi_IsCapturedLocation) {
		switch (LanguageGetLanguage()) {
			case "Polish":
				arImgGrp.t2 = "TRADE_STATE_POL";
			break;
			// default:
			arImgGrp.t2 = "TRADE_STATE";
		}
	}
	// <-- KK
	FillImagesGroupForItems(arImgGrp);
	GameInterface.itemslist.NotUsed = 5;
	GameInterface.itemslist.BadTex1 = GetItemPictureTexture("itemslist.ImagesGroup","");
	GameInterface.itemslist.BadPic1 = GetItemPictureName("");

	idx = 0;
	aref curItem,arItem;
	aref rootItems;
	object tempitemnames; // NK 05-04-05

	string curItemID = OBJECT_ITEM_TYPE;
	string name; // KK
	makearef(rootItems,refMyCh.Items);
	for(i=0; i<GetAttributesNum(rootItems); i++)
	{
		attributeName = "pic" + (idx+1);
		curItem = GetAttributeN(rootItems,i);
		itemName = GetAttributeName(curItem);
		if(!TraderUseItem(&refTrader, itemName)) continue; // NK itemtrade 05-04-02 skip qty <=0 items.
		if (!IsTradeItem(itemname)) continue; // KK
		if(Items_FindItem(GetAttributeName(curItem),&arItem)>=0)
		{
			if(CheckAttribute(arItem,"groupID"))
			{
				curItemID = OBJECT_ITEM_TYPE;
				if(arItem.groupID==GUN_ITEM_TYPE || arItem.groupID==BLADE_ITEM_TYPE || arItem.groupID==ARMOR_ITEM_TYPE || arItem.groupID==AMMUNITION_ITEM_TYPE) { curItemID = GUN_ITEM_TYPE; }
				if(arItem.groupID==POTION_ITEM_TYPE) curItemID = POTION_ITEM_TYPE;
				if (arItem.groupID == MAP_ITEM_TYPE) curItemID = MAP_ITEM_TYPE; // KK
				if(curItemID==curItemGroup)
				{
					attributeName = "pic" + (idx+1);
					GameInterface.itemslist.(attributeName).img1 = GetItemPictureName(arItem.id);
					GameInterface.itemslist.(attributeName).tex1 = GetItemPictureTexture("itemslist.ImagesGroup",arItem.id);
					GameInterface.itemslist.(attributeName).str1 = "#" + GetCharacterItem(refMyCh, arItem.id) + " / " + GetCharacterItem(refTrader, arItem.id); // KK
					GameInterface.itemslist.(attributeName).itemID = arItem.id;
					if( IsEquipCharacterByItem(refMyCh,itemName) )
					{
						GameInterface.itemslist.(attributeName).img2 = "usedflag";
						GameInterface.itemslist.(attributeName).tex2 = 1;
					}
// KK -->
					name = "";
					//if (CheckAttribute(arItem, "QualityName")) name = TranslateString("", "q"+arItem.QualityName) + " "; // PB: Correct quality name // MAXIMUS 31.05.2019: corrected for russian spelling
					if (GetAttribute(arItem,"groupID") == QUEST_ITEM_TYPE)
					{
						name += PreprocessText(TranslateString("", arItem.name)); // PB
					}
					else
					{
						name += GetAssembledString(TranslateString("", arItem.name), arItem); // Levis
					}

					// MAXIMUS 31.05.2019: corrected for russian spelling ==>
					if (CheckAttribute(arItem, "QualityName"))
					{
						switch(LanguageGetLanguage())
						{
							case "Russian":
								name = name + " " + TranslateString("", "q"+arItem.QualityName);
							break;
							name = TranslateString("", "q"+arItem.QualityName) + " " + name; // PB: Correct quality name //default for English
						}
					}
					// MAXIMUS 31.05.2019: corrected for russian spelling <==

					if(DynamicInterfaceLevel() > 1) GameInterface.itemslist.(attributeName).str2 = "#" + name; // PB: Dynamic Interfaces
// <-- KK
					GameInterface.itemslist.(attributeName).img3 = GetItemStatus(itemName, true);
					GameInterface.itemslist.(attributeName).tex3 = 2;
					GameInterface.itemslist.(attributeName).img4 = GetItemStatus(itemName, false);
					GameInterface.itemslist.(attributeName).tex4 = 2;
					idx++;
				}
				else
				{
					attributeName = "pic" + (idx+1);
					GameInterface.itemslist.(attributeName).img1 = GameInterface.itemslist.BadPic1;
					GameInterface.itemslist.(attributeName).tex1 = GameInterface.itemslist.BadTex1;
				}
			}
			else
			{
				if(curItemID==curItemGroup)
				{
					attributeName = "pic" + (idx+1);
					GameInterface.itemslist.(attributeName).img1 = GetItemPictureName(arItem.id);
					GameInterface.itemslist.(attributeName).tex1 = GetItemPictureTexture("itemslist.ImagesGroup",arItem.id);
					GameInterface.itemslist.(attributeName).str1 = "#" + GetCharacterItem(refMyCh, arItem.id) + " / " + GetCharacterItem(refTrader, arItem.id); // KK
					GameInterface.itemslist.(attributeName).itemID = arItem.id;
// KK -->
					name = "";
					//if (CheckAttribute(arItem, "QualityName")) name = TranslateString("", "q"+arItem.QualityName) + " "; // PB: Correct quality name // MAXIMUS 31.05.2019: corrected for russian spelling
					if (GetAttribute(arItem,"groupID") == QUEST_ITEM_TYPE)
					{
						name += PreprocessText(TranslateString("", arItem.name)); // PB
					}
					else
					{
						name += GetAssembledString(TranslateString("", arItem.name), arItem); // Levis
					}

					// MAXIMUS 31.05.2019: corrected for russian spelling ==>
					if (CheckAttribute(arItem, "QualityName"))
					{
						switch(LanguageGetLanguage())
						{
							case "Russian":
								name = name + " " + TranslateString("", "q"+arItem.QualityName);
							break;
							name = TranslateString("", "q"+arItem.QualityName) + " " + name; // PB: Correct quality name //default for English
						}
					}
					// MAXIMUS 31.05.2019: corrected for russian spelling <==

					if(DynamicInterfaceLevel() > 1) GameInterface.itemslist.(attributeName).str2 = "#" + name; // PB: Dynamic Interfaces
// <-- KK
					GameInterface.itemslist.(attributeName).img3 = GetItemStatus(itemName, true);
					GameInterface.itemslist.(attributeName).tex3 = 2;
					GameInterface.itemslist.(attributeName).img4 = GetItemStatus(itemName, false);
					GameInterface.itemslist.(attributeName).tex4 = 2;
					idx++;
				}
				else
				{
					attributeName = "pic" + (idx+1);
					GameInterface.itemslist.(attributeName).img1 = GameInterface.itemslist.BadPic1;
					GameInterface.itemslist.(attributeName).tex1 = GameInterface.itemslist.BadTex1;
				}
			}
		}
		else
		{
			attributeName = "pic" + (idx+1);
			GameInterface.itemslist.(attributeName).img1 = GameInterface.itemslist.BadPic1;
			GameInterface.itemslist.(attributeName).tex1 = GameInterface.itemslist.BadTex1;
		}
		tempitemnames.(itemName) = true;
	}

	makearef(rootItems,refTrader.Items);
	for(i=0; i<GetAttributesNum(rootItems); i++)
	{
		attributeName = "pic" + (idx+1);
		curItem = GetAttributeN(rootItems,i);
		itemName = GetAttributeName(curItem);
		if(!TraderSellItem(&refTrader, itemName)) continue; // NK itemtrade 05-04-02 skip qty <=0 items.
		if( CheckAttribute(tempitemnames,itemName) ) continue; // NK modded 05-04-05
		if(Items_FindItem(GetAttributeName(curItem),&arItem)>=0)
		{
			if(CheckAttribute(arItem,"groupID"))
			{
				curItemID = OBJECT_ITEM_TYPE;
				if(arItem.groupID==GUN_ITEM_TYPE || arItem.groupID==BLADE_ITEM_TYPE || arItem.groupID==ARMOR_ITEM_TYPE || arItem.groupID==AMMUNITION_ITEM_TYPE) { curItemID = GUN_ITEM_TYPE; }
				if(arItem.groupID==POTION_ITEM_TYPE) curItemID = POTION_ITEM_TYPE;
				if (arItem.groupID == MAP_ITEM_TYPE) curItemID = MAP_ITEM_TYPE; // KK
				if(curItemID==curItemGroup)
				{
					if(curItemID==GUN_ITEM_TYPE && arItem.id=="bladeX4") continue;//MAXIMUS
					attributeName = "pic" + (idx+1);
					GameInterface.itemslist.(attributeName).img1 = GetItemPictureName(arItem.id);
					GameInterface.itemslist.(attributeName).tex1 = GetItemPictureTexture("itemslist.ImagesGroup",arItem.id);
					GameInterface.itemslist.(attributeName).str1 = "#" + GetCharacterItem(refMyCh, arItem.id) + " / " + GetCharacterItem(refTrader, arItem.id); // KK
					GameInterface.itemslist.(attributeName).itemID = arItem.id;
// KK -->
					name = "";
					//if (CheckAttribute(arItem, "QualityName")) name = TranslateString("", "q"+arItem.QualityName) + " "; // PB: Correct quality name // MAXIMUS 31.05.2019: corrected for russian spelling
					if (GetAttribute(arItem,"groupID") == QUEST_ITEM_TYPE)
					{
						name += PreprocessText(TranslateString("", arItem.name)); // PB
					}
					else
					{
						name += GetAssembledString(TranslateString("", arItem.name), arItem); // Levis
					}

					// MAXIMUS 31.05.2019: corrected for russian spelling ==>
					if (CheckAttribute(arItem, "QualityName"))
					{
						switch(LanguageGetLanguage())
						{
							case "Russian":
								name = name + " " + TranslateString("", "q"+arItem.QualityName);
							break;
							name = TranslateString("", "q"+arItem.QualityName) + " " + name; // PB: Correct quality name //default for English
						}
					}
					// MAXIMUS 31.05.2019: corrected for russian spelling <==

					if(DynamicInterfaceLevel() > 1) GameInterface.itemslist.(attributeName).str2 = "#" + name; // PB: Dynamic Interfaces
// <-- KK
					GameInterface.itemslist.(attributeName).img3 = GetItemStatus(itemName, true);
					GameInterface.itemslist.(attributeName).tex3 = 2;
					GameInterface.itemslist.(attributeName).img4 = GetItemStatus(itemName, false);
					GameInterface.itemslist.(attributeName).tex4 = 2;
					idx++;
				}
				else
				{
					attributeName = "pic" + (idx+1);
					GameInterface.itemslist.(attributeName).img1 = GameInterface.itemslist.BadPic1;
					GameInterface.itemslist.(attributeName).tex1 = GameInterface.itemslist.BadTex1;
				}
			}
			else
			{
				if(curItemID==curItemGroup)
				{
					attributeName = "pic" + (idx+1);
					GameInterface.itemslist.(attributeName).img1 = GetItemPictureName(arItem.id);
					GameInterface.itemslist.(attributeName).tex1 = GetItemPictureTexture("itemslist.ImagesGroup",arItem.id);
					GameInterface.itemslist.(attributeName).str1 = "#" + GetCharacterItem(refMyCh, arItem.id) + " / " + GetCharacterItem(refTrader, arItem.id); // KK
					GameInterface.itemslist.(attributeName).itemID = arItem.id;
					if( IsEquipCharacterByItem(refMyCh,itemName) )
					{
						GameInterface.itemslist.(attributeName).img2 = "usedflag";
						GameInterface.itemslist.(attributeName).tex2 = 1;
					}
// KK -->
					name = "";
					//if (CheckAttribute(arItem, "QualityName")) name = TranslateString("", "q"+arItem.QualityName) + " "; // PB: Correct quality name // MAXIMUS 31.05.2019: corrected for russian spelling
					if (GetAttribute(arItem,"groupID") == QUEST_ITEM_TYPE)
					{
						name += PreprocessText(TranslateString("", arItem.name)); // PB
					}
					else
					{
						name += GetAssembledString(TranslateString("", arItem.name), arItem); // Levis
					}

					// MAXIMUS 31.05.2019: corrected for russian spelling ==>
					if (CheckAttribute(arItem, "QualityName"))
					{
						switch(LanguageGetLanguage())
						{
							case "Russian":
								name = name + " " + TranslateString("", "q"+arItem.QualityName);
							break;
							name = TranslateString("", "q"+arItem.QualityName) + " " + name; // PB: Correct quality name //default for English
						}
					}
					// MAXIMUS 31.05.2019: corrected for russian spelling <==

					if(DynamicInterfaceLevel() > 1) GameInterface.itemslist.(attributeName).str2 = "#" + name; // PB: Dynamic Interfaces
// <-- KK
					GameInterface.itemslist.(attributeName).img3 = GetItemStatus(itemName, true);
					GameInterface.itemslist.(attributeName).tex3 = 2;
					GameInterface.itemslist.(attributeName).img4 = GetItemStatus(itemName, false);
					GameInterface.itemslist.(attributeName).tex4 = 2;
					idx++;
				}
				else
				{
					attributeName = "pic" + (idx+1);
					GameInterface.itemslist.(attributeName).img1 = GameInterface.itemslist.BadPic1;
					GameInterface.itemslist.(attributeName).tex1 = GameInterface.itemslist.BadTex1;
				}
			}
		}
		else
		{
			attributeName = "pic" + (idx+1);
			GameInterface.itemslist.(attributeName).img1 = GameInterface.itemslist.BadPic1;
			GameInterface.itemslist.(attributeName).tex1 = GameInterface.itemslist.BadTex1;
		}
	}

	GameInterface.itemslist.ListSize = idx-1;
	GameInterface.itemslist.current = 0;
	nCurScrollNum = -1;
}

void ProcessCancelExit()
{
	// Sulan -->
	if(nPlayerMoneyStart < sti(refMyCh.Money))
	{
		WriteNewLogEntry("Visited "+FindTownName(GetCurrentTownID()),"Traded off all the collected blades, pistols, gems and other junk to a local merchant. The trade earned me "+(sti(refMyCh.Money)-nPlayermoneyStart)+" pieces of gold.","Ship",true);
	}
	if(nPlayerMoneyStart > sti(refMyCh.Money))
	{
		WriteNewLogEntry("Visited "+FindTownName(GetCurrentTownID()),"Found some interesting new items while browsing through the inventory of a local merchant. I had to pay "+(nPlayerMoneyStart-sti(refMyCh.Money))+" pieces of gold.","Ship",true);
	}
	// Sulan <--


	// TIH --> figure out how many different types of items were traded Aug24'06
	int numTrades = 0;
	if (CheckAttribute(gTradetracker, "tradeitems")) {
		aref tmp; makearef(tmp,gTradetracker.tradeitems); numTrades = GetAttributesNum(tmp);
	}
	if (numTrades <= 0) { numTrades = 1; }
	if (CheckAttribute(refTrader, "itemtrade.numtimes")) { refTrader.itemtrade.numtimes = sti(refTrader.itemtrade.numtimes) + numTrades; }
	else { refTrader.itemtrade.numtimes = numTrades; }
	trace("IT traded with trader "+ refTrader.itemtrade.numtimes +" times");
	DeleteAttribute(&gTradetracker, "tradeitems"); // TIH clear this global
	//if(CheckAttribute(refTrader, "itemtrade.numtimes")) { refTrader.itemtrade.numtimes = sti(refTrader.itemtrade.numtimes) + anytrades; }
	//else { refTrader.itemtrade.numtimes = anytrades; } // NK so we know we traded.
	// TIH <--
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("frame","ProcessFrame");
    DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcessCommandExecute");

	interfaceResultCommand = RC_INTERFACE_ITEMSTRADE_EXIT;
    EndCancelInterface(true);
}

void SetShowMode(int st)
{
	if(st==showType) return;

	switch(showType)
	{
		case SHOW_MAIN:
			DisableString("ItemsName");
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
			SetNodeUsing("BUYSELL_IMAGES",false);
			SetNodeUsing("OK_BUTTON",false);
			SetNodeUsing("CANCEL_BUTTON",false);
			SetNodeUsing("TRADEQUANTITY",false);
			CreateImage("TradeType","","",0,0,0,0);
		break;
		case SHOW_SELL:
			DisableString("PriceSum");
			DisableString("TradeQuantity");
			SetNodeUsing("BUYSELL_IMAGES",false);
			SetNodeUsing("OK_BUTTON",false);
			SetNodeUsing("CANCEL_BUTTON",false);
			SetNodeUsing("TRADEQUANTITY",false);
			CreateImage("TradeType","","",0,0,0,0);
		break;
		case SHOW_DESCRIBE:
			SetNodeUsing("TEXTWINDOW",false);
			SendMessage(&GameInterface, "lsls", MSG_INTERFACE_MSG_TO_NODE, "INFO_BUTTON", 0, XI_ConvertString("INFO")); // KK
		break;
	}

	showType = st;

	switch(showType)
	{
		case SHOW_MAIN:
			EnableString("ItemsName");
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
			SetNodeUsing("BUYSELL_IMAGES",!LAi_IsCapturedLocation); // KK
			SetNodeUsing("OK_BUTTON",true);
			SetNodeUsing("CANCEL_BUTTON",true);
			SetNodeUsing("TRADEQUANTITY",true);
// KK -->
			if (!LAi_IsCapturedLocation) {
				switch (LanguageGetLanguage()) {
					case "Polish":
						CreateImage("TradeType","BUY_SELL_POL","buy",126,242,190,306);
					break;
					// default:
					CreateImage("TradeType","BUY_SELL","buy",126,242,190,306);
				}
			}
			FreezeScreen(true);
// <-- KK
		break;
		case SHOW_SELL:
			EnableString("PriceSum");
			EnableString("TradeQuantity");
			SetNodeUsing("BUYSELL_IMAGES",!LAi_IsCapturedLocation);
			SetNodeUsing("OK_BUTTON",true);
			SetNodeUsing("CANCEL_BUTTON",true);
			SetNodeUsing("TRADEQUANTITY",true);
// KK -->
			if (!LAi_IsCapturedLocation) {
				switch (LanguageGetLanguage()) {
					case "Polish":
						CreateImage("TradeType","BUY_SELL_POL","sell",450,242,514,306);
					break;
					// default:
					CreateImage("TradeType","BUY_SELL","sell",450,242,514,306);
				}
			}
			FreezeScreen(true);
// <-- KK
		break;
		case SHOW_DESCRIBE:
			SetNodeUsing("TEXTWINDOW",true);
// KK -->
			SendMessage(&GameInterface, "lsls", MSG_INTERFACE_MSG_TO_NODE, "INFO_BUTTON", 0, XI_ConvertString("OK"));
			SetNodeUsing("INFO_BUTTON", true);
			SetCurrentNode("INFO_BUTTON");
			FreezeScreen(true);
// <-- KK
		break;
	}

}

string GetItemsID(int scrollIdx)
{
	if(scrollIdx<0) return "";
	string attributeName = "pic" + (scrollIdx+1);
	if( CheckAttribute(&GameInterface,"itemslist."+attributeName+".itemID") )
	{
		return GameInterface.itemslist.(attributeName).itemID;
	}
	return "";
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	switch(nodName)
	{
		case "ITEMSLIST":
			if(comName=="deactivate")
			{
				PostEvent("exitCancel",1);
			}
			if(comName=="downstep" || comName=="speeddown")
			{
				if(GetSelectable("BUY_BUTTON"))
				{
					SetCurrentNode("BUY_BUTTON");
					return;
				}
				if(GetSelectable("SELL_BUTTON"))
				{
					SetCurrentNode("SELL_BUTTON");
					return;
				}
			}
			if(comName=="upstep")
			{
				SetCurrentNode("SELL_LOOT_BUTTON");
			}
		break;

		case "INFO_BUTTON":
			if(comName=="activate" || comName=="click")
			{
				if (showType == SHOW_DESCRIBE) {
					SetShowMode(SHOW_MAIN);
				} else {
					SetShowMode(SHOW_DESCRIBE);
					SetCurrentNode("TEXTWINDOW");
				}
				RefreshAllStrings();
				return;
			}
			if(comName=="leftstep")
			{
				if( GetSelectable("BUY_BUTTON") )
				{
					SetCurrentNode("BUY_BUTTON");
				}
				return;
			}
			if(comName=="rightstep")
			{
				if( GetSelectable("SELL_BUTTON") )
				{
					SetCurrentNode("SELL_BUTTON");
				}
				return;
			}
		break;

		case "BUY_BUTTON":
			if(comName=="activate" || comName=="click")
			{
				SetShowMode(SHOW_BUY);
				SetStartTradeQuantity();
				RefreshAllStrings();
				SetCurrentNode("TRADEQUANTITY");
			}
		break;

		case "SELL_BUTTON":
			if(comName=="activate" || comName=="click")
			{
				SetShowMode(SHOW_SELL);
				SetStartTradeQuantity();
				RefreshAllStrings();
				SetCurrentNode("TRADEQUANTITY");
			}
		break;

		case "TRADEQUANTITY":
			if(comName=="activate")
			{
				DoTradeOperation();
				SetShowMode(SHOW_MAIN);
				SetCurrentNode("ITEMSLIST");
				RefreshAllStrings();
			}
			switch(comName)
			{
			case "rightstep":	AddTradeQuantity(1); break;
			case "speedright":	AddTradeQuantity(10); break;
			case "leftstep":	AddTradeQuantity(-1); break;
			case "speedleft":	AddTradeQuantity(-10); break;
			}
		break;

		case "OK_BUTTON":
			if(comName=="activate" || comName=="click")
			{
				DoTradeOperation();
				SetShowMode(SHOW_MAIN);
				SetCurrentNode("ITEMSLIST");
				RefreshAllStrings();
			}
		break;

		case "CANCEL_BUTTON":
			if(comName=="activate" || comName=="click")
			{
				SetShowMode(SHOW_MAIN);
				SetCurrentNode("ITEMSLIST");
			}
		break;

		case "TEXTWINDOW":
			if(comName=="downstep")
			{
				if(!bEnableDown)
				{
					SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"TEXTWINDOW",-1, 0,ACTION_UPSTEP);
				} else {
					bEnableDown = SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE,"TEXTWINDOW", 6, 0);
				}
			}
			if(comName=="upstep")
			{
				bEnableDown = SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE,"TEXTWINDOW", 6, 0);
			}
		break;

		case "SELL_LOOT_BUTTON":
			if(comName=="activate" || comName=="click")
			{
				SellAllLoot();
				SetShowMode(SHOW_MAIN);
				SetCurrentNode("ITEMSLIST");
				RefreshAllStrings();
			}
			if(comName=="downstep")
			{
				SetCurrentNode("ITEMSLIST");
			}
			if(comName=="upstep")
			{
				SetCurrentNode("INFO_BUTTON");
			}
		break;

// KK -->
		case "I_WEAPON":
			if (comName == "activate" || comName == "click") {
				curItemGroup = GUN_ITEM_TYPE;
				ChangeSelectedScroll();
				RefreshAllStrings();
			}
		break;

		case "I_POTION":
			if (comName == "activate" || comName == "click") {
				curItemGroup = POTION_ITEM_TYPE;
				ChangeSelectedScroll();
				RefreshAllStrings();
			}
		break;

		case "I_ITEMS":
			if (comName == "activate" || comName == "click") {
				curItemGroup = OBJECT_ITEM_TYPE;
				ChangeSelectedScroll();
				RefreshAllStrings();
			}
		break;

		case "I_MAP":
			if (comName == "activate" || comName == "click") {
				curItemGroup = MAP_ITEM_TYPE;
				ChangeSelectedScroll();
				RefreshAllStrings();
			}
		break;
// <-- KK
	}
}

void DoTradeOperation()
{
	if(nTradeQuantity<=0) return;
	string itmName = GetItemsID(nCurScrollNum);
	aref itemref; makearef(itemref,Items[GetItemIndex(itmName)]);// TIH added for ease of use Jul15'06
	ref mchref = GetMainCharacter();

	int TQ;		//JRH
	TQ = nTradeQuantity;
	int gp1;
	int pb;
	int pb1;
	int pg;
	int pg1;
	int pg2;
	int mb;
	int mb1;
	int am;
	int am1;
	int p;
	int s;

	if(showType==SHOW_SELL)
	{
		// TIH --> unequip if selling it off Jul15'06
		bool soldEquip = false;
		// first check if they are selling ALL of the item
		if ( nTradeQuantity >= GetCharacterItem(refMyCh,itmName) && CheckAttribute(itemref,"groupID") ) {
			if ( IsEquipCharacterByItem(refMyCh,itmName) ) {
				RemoveCharacterEquip(refMyCh, itemref.groupID);
				soldEquip = true;
			}
		}
		// TIH <-- allow selling equipped items

		// PB: Cursed Coins -->
		if(itmName=="cursedcoin" && GetCursedCoinCount()>0)
		{
			if(nTradeQuantity == sti(refMyCh.items.cursedcoin))
				nTradeQuantity = nTradeQuantity-1;
		}
		// PB: Cursed Coins <--

		TakeNItems(refTrader,itmName,nTradeQuantity);
		TakeNItems(refMyCh,itmName,-nTradeQuantity);
		AddMoneyToCharacter(mchref,nTradeQuantity*sellPrice);
		if(AUTO_SKILL_SYSTEM)
		{
			AddPartyExpChar(mchref, "Commerce", makeint(nTradeQuantity*sellPrice/10));
			AddCharacterExpNSChar(&refTrader, "Commerce", makeint(nTradeQuantity*sellPrice/10));
		}
		AddMoneyToCharacter(&refTrader,-nTradeQuantity*sellPrice); // NK itemtrade 05-04-02
		// TIH --> auto-requip if sold off equipped items Jul15'06
		// do after TakeNItems, because of the "Find" function needs the prior one removed
		if ( soldEquip && CheckAttribute(itemref,"groupID") ) {
			// if sold off their blade, equip last best item or their fists
			if ( itemref.groupID == BLADE_ITEM_TYPE ) {
				EquipCharacterByItem(refMyCh, FindCharacterItemByGroup(refMyCh, BLADE_ITEM_TYPE) );
				//EquipCharacterByItem(refMyCh, "bladeX4");
			}
			// if sold off their gun, equip last best gun allowed in inventory
			if ( itemref.groupID == GUN_ITEM_TYPE ) {
				EquipCharacterByItem(refMyCh, FindCharacterItemByGroup(refMyCh, GUN_ITEM_TYPE) );
			}
			soldEquip = false;// reset just in case
		}
		// TIH <-- allow selling equipped items

		//JRH -->
		if(itmName == "drawing_kit")
		{
			if(CheckAttribute(mchref,"quest.drawing_kit"))
			{
				switch(mchref.quest.drawing_kit)
				{
					case "speed":
						if(CheckCharacterPerk(mchref, "SailingProfessional"))
						{
							DeleteAttribute(mchref,"perks.list.SailingProfessional");
						}
						else
						{
							if(CheckCharacterPerk(mchref, "SandbankManeuver"))
							{
								DeleteAttribute(mchref,"perks.list.SandbankManeuver");
							}
						}
						else
						{
							if(CheckCharacterPerk(mchref, "Turn180"))
							{
								DeleteAttribute(mchref,"perks.list.Turn180");
							}
						}
						else
						{
							DeleteAttribute(mchref,"perks.list.ShipSpeedUp");
						}
						mchref.quest.drawing_kit = "none";
					break;

					case "maneuver":
						if(CheckCharacterPerk(mchref, "SailingProfessional"))
						{
							DeleteAttribute(mchref,"perks.list.SailingProfessional");
						}
						else
						{
							if(CheckCharacterPerk(mchref, "SandbankManeuver"))
							{
								DeleteAttribute(mchref,"perks.list.SandbankManeuver");
							}
						}
						else
						{
							if(CheckCharacterPerk(mchref, "Turn180"))
							{
								DeleteAttribute(mchref,"perks.list.Turn180");
							}
						}
						else
						{
							DeleteAttribute(mchref,"perks.list.ShipTurnRateUp");
						}
						mchref.quest.drawing_kit = "none";
					break;

					case "turn180":
						if(CheckCharacterPerk(mchref, "SailingProfessional"))
						{
							DeleteAttribute(mchref,"perks.list.SailingProfessional");
						}
						else
						{
							if(CheckCharacterPerk(mchref, "SandbankManeuver"))
							{
								DeleteAttribute(mchref,"perks.list.SandbankManeuver");
							}
						}
						else
						{
							DeleteAttribute(mchref,"perks.list.Turn180");
						}
						mchref.quest.drawing_kit = "none";
					break;

					case "sandbank":
						if(CheckCharacterPerk(mchref, "SailingProfessional"))
						{
							DeleteAttribute(mchref,"perks.list.SailingProfessional");
						}
						else
						{
							DeleteAttribute(mchref,"perks.list.SandbankManeuver");
						}
						mchref.quest.drawing_kit = "none";
					break;

					case "storm":
						if(CheckCharacterPerk(mchref, "SailingProfessional"))
						{
							DeleteAttribute(mchref,"perks.list.SailingProfessional");
						}
						else
						{
							DeleteAttribute(mchref,"perks.list.StormProfessional");
						}
    						mchref.quest.drawing_kit = "none";
					break;

					case "seawolf":
						DeleteAttribute(mchref,"perks.list.SailingProfessional");
						mchref.quest.drawing_kit = "none";
					break;

					case "def1":
						if(CheckCharacterPerk(mchref, "ProfessionalDamageControl"))
						{
							DeleteAttribute(mchref,"perks.list.ProfessionalDamageControl");
						}
						else
						{
							if(CheckCharacterPerk(mchref, "AdvancedDamageControl"))
							{
								DeleteAttribute(mchref,"perks.list.AdvancedDamageControl");
							}
						}
						else
						{
							DeleteAttribute(mchref,"perks.list.BasicDamageControl");
						}
						mchref.quest.drawing_kit = "none";
					break;

					case "def2":
						if(CheckCharacterPerk(mchref, "ProfessionalDamageControl"))
						{
							DeleteAttribute(mchref,"perks.list.ProfessionalDamageControl");
						}
						else
						{
							DeleteAttribute(mchref,"perks.list.AdvancedDamageControl");
						}
						mchref.quest.drawing_kit = "none";
					break;

					case "def3":
						DeleteAttribute(mchref,"perks.list.ProfessionalDamageControl");
						mchref.quest.drawing_kit = "none";
					break;
				}
			}
		}
		//<-- JRH
	}

	if(showType==SHOW_BUY)
	{
		// TIH --> bracket fixing Jul15'06
		//JRH -->
		if(itmName=="gunpowder" || itmName=="pistolbullets" || itmName=="pistolgrapes" || itmName=="musketbullets")
		{
			if(itmName=="gunpowder")
			{
			    //JRH -->
			    if(IsEquipCharacterByItem(mchref, "powderbarrel"))
			    {
				    p = (4 * MAX_GUNPOWDER);      	      // Sulan: introduced MAX_GUNPOWDER
			    }
			    else
			    {
					if(IsEquipCharacterByItem(mchref, "ammobag2"))
					{
						p = (3 * MAX_GUNPOWDER);      	      // Sulan: introduced MAX_GUNPOWDER
					}
					else
					{
						if(IsEquipCharacterByItem(mchref, "powderflask"))
						{
							p = (2 * MAX_GUNPOWDER);      // Sulan: introduced MAX_GUNPOWDER
						}
						else p = MAX_GUNPOWDER;            // Sulan: introduced MAX_GUNPOWDER
					}
			    }
			    //<-- JRH

				int gp;
				gp = GetCharacterItem(mchref, "gunpowder");
				TQ = nTradeQuantity;

				if(gp >= p)
				{
					TakeNItems(mchref,"gunpowder", -100);
					TakeNItems(mchref,"gunpowder", p);
					return;	//just in case
				}
				else
				{
					if(TQ + gp >= p) gp1 = p - gp;
					if(TQ + gp < p) gp1 = TQ;
					TakeNItems(refTrader, "gunpowder", -gp1);
					TakeNItems(refMyCh, "gunpowder", gp1);
					AddMoneyToCharacter(mchref,-gp1*buyPrice);
					if(AUTO_SKILL_SYSTEM)
					{
						AddPartyExpChar(mchref, "Commerce", makeint(gp1*buyPrice/10));
						AddCharacterExpNSChar(&refTrader, "Commerce", makeint(gp1*buyPrice/10));
					}
					AddMoneyToCharacter(&refTrader,gp1*buyPrice);
				}
			}

			if(itmName=="pistolbullets" || itmName=="pistolgrapes" || itmName=="musketbullets")
			{
			    //JRH -->
			    if(IsEquipCharacterByItem(mchref, "ammobag"))
			    {
			 	    s = (4 * MAX_SHOTS); 	     // Sulan: introduced MAX_SHOTS;
			    }
			    else
			    {
					if(IsEquipCharacterByItem(mchref, "ammobag2"))
					{
						s = (3 * MAX_SHOTS); 	     // Sulan: introduced MAX_SHOTS;
					}
					else
					{
						if(IsEquipCharacterByItem(mchref, "ammopouch"))
						{
							s = (2 * MAX_SHOTS); // Sulan: introduced MAX_SHOTS
						}
						else s = MAX_SHOTS;       // Sulan: introduced MAX_SHOTS
					}
			    }
			    //<-- JRH

				// JRH fix oct 06 -->
				pb = GetCharacterItem(mchref, "pistolbullets");
				pg = GetCharacterItem(mchref, "pistolgrapes");
				mb = GetCharacterItem(mchref, "musketbullets");
				am = pb + pg + 2*mb;

				if(am < s)
				{
					if(itmName=="pistolbullets" || itmName=="pistolgrapes")
					{
						if(TQ + am > s) am1 = s - am;
						if(TQ + am <= s) am1 = TQ;
						TakeNItems(refTrader,itmName,-am1);
						TakeNItems(refMyCh,itmName,am1);
						AddMoneyToCharacter(mchref,-am1*buyPrice);
						if(AUTO_SKILL_SYSTEM)
						{
							AddPartyExpChar(mchref, "Commerce", makeint(am1*buyPrice/10));
							AddCharacterExpNSChar(&refTrader, "Commerce", makeint(am1*buyPrice/10));
						}
						AddMoneyToCharacter(&refTrader,am1*buyPrice);
					}
					if(itmName=="musketbullets")
					{
						if(TQ > (s - am)/2) am1 = (s - am)/2;
						if(TQ <= (s - am)/2) am1 = TQ;
						TakeNItems(refTrader,itmName,-am1);
						TakeNItems(refMyCh,itmName,am1);
						AddMoneyToCharacter(mchref,-am1*buyPrice);
						if(AUTO_SKILL_SYSTEM)
						{
							AddPartyExpChar(mchref, "Commerce", makeint(am1*buyPrice/10));
							AddCharacterExpNSChar(&refTrader, "Commerce", makeint(am1*buyPrice/10));
						}
						AddMoneyToCharacter(&refTrader,am1*buyPrice);
					}
				}
				// <-- JRH
			}
		}
		else
		{
			TakeNItems(refTrader,itmName,-nTradeQuantity);
			TakeNItems(refMyCh,itmName,nTradeQuantity);
			AddMoneyToCharacter(mchref,-nTradeQuantity*buyPrice);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(mchref, "Commerce", makeint(nTradeQuantity*buyPrice/10));
				AddCharacterExpNSChar(&refTrader, "Commerce", makeint(nTradeQuantity*buyPrice/10));
			}
			AddMoneyToCharacter(&refTrader,nTradeQuantity*buyPrice); // NK itemtrade 05-04-02
			// TIH --> auto-equip better spyglass if bought another Jul15'06
			if ( nTradeQuantity > 0 && CheckAttribute(itemref,"groupID") ) {
				if ( itemref.groupID == SPYGLASS_ITEM_TYPE ) {
					if(GetCharacterEquipByGroup(refMyCh,SPYGLASS_ITEM_TYPE) == "" || sti(itemref.quality) > sti(Items[GetItemIndex(GetCharacterEquipByGroup(refMyCh,SPYGLASS_ITEM_TYPE))].quality) ) { // PB: Prevent errors
						RemoveCharacterEquip(refMyCh, SPYGLASS_ITEM_TYPE);// remove equip of old one
						EquipCharacterByItem(refMyCh, itmName);// equip the new better one
					}
				}
			}
			// TIH <-- auto-equip better spyglass
		}
		// TIH <-- bracket fixing
	}

	// TIH --> count types of items traded to better level a merchant up Aug24'06
	// (only per type, not every single sold quantity)
	if (!CheckAttribute(gTradetracker,"tradeitems")) { gTradetracker.tradeitems = ""; }
	gTradetracker.tradeitems.(itmName) = nTradeQuantity;
	//anytrades = true; // NK 05-04-07
	// TIH <--

	nTradeQuantity = 0;
	if(sti(mchref.money)<0)
	{
		mchref.money = 0;
	}

	UpdateScroll();	//TIH update all items, as the equip flag make have changed
}

void AddTradeQuantity(int incrVal)
{
	ref mchref = GetMainCharacter();
	nTradeQuantity = nTradeQuantity + incrVal;
	if(nTradeQuantity<0)
	{
		nTradeQuantity = 0;
		RefreshAllStrings();
		return;
	}

	if(LAi_IsCapturedLocation == false && buyPrice == 0) // KK
	{
		nTradeQuantity = 0;
	}

	string itmName = GetItemsID(nCurScrollNum);
	if(showType==SHOW_SELL)
	{
		int realQ = GetCharacterItem(refMyCh,itmName);
		if( realQ > 0 && IsEquipCharacterByItem(refMyCh,itmName) ){
			// TIH --> allow the selling of equipped items Jul15'06
			// EXCEPT the current equipped spyglass... it is a required special
			if ( Items[GetItemIndex(itmName)].groupID == SPYGLASS_ITEM_TYPE ) {
				realQ--;
			}
			// TIH <-- allow sell equips
		}
		if(realQ<nTradeQuantity)
		{
			nTradeQuantity = realQ;
		}
		// NK itemtrade 05-04-02 -->
		if(sellprice*nTradeQuantity > GetCharacterMoney(&refTrader))
		{
			nTradeQuantity = GetCharacterMoney(&refTrader) / sellPrice;
		}
		// NK <--
	}

	if(showType==SHOW_BUY)
	{
		if(GetCharacterItem(refTrader,itmName)<nTradeQuantity)
		{
			nTradeQuantity = GetCharacterItem(refTrader,itmName);
		}

		if(buyPrice*nTradeQuantity > sti(mchref.money))
		{
			nTradeQuantity = sti(mchref.money) / buyPrice;
		}
	}

	RefreshAllStrings();
}

void SetItemDescribe(aref arItm)
{
	string describeStr = "";
	if( CheckAttribute(arItm,"groupID") )
	{
		if(arItm.groupID==GUN_ITEM_TYPE)
		{
			describeStr += GetAssembledString(TranslateString("","weapon gun parameters"), arItm) + GlobalStringConvert("newline");
		}
		if(arItm.groupID==BLADE_ITEM_TYPE)
		{
			describeStr += GetAssembledString(
				TranslateString("","weapon blade parameters"), arItm) + GlobalStringConvert("newline");
		}
		// GreatZen -->
		if(arItm.groupID==ARMOR_ITEM_TYPE)
		{
			describeStr = GetAssembledString(TranslateString("","weapon armor parameters"),arItm) + GlobalStringConvert("newline");
		}
		// GreatZen <--
	}
	if( CheckAttribute(arItm,"describe") )
	{
		if (GetAttribute(arItm,"groupID") == QUEST_ITEM_TYPE)
		{
			describeStr += PreprocessText(TranslateString("",arItm.describe)) + GetItemBonuses(arItm.id); // PB
		}
		else
		{
			describeStr += GetAssembledString(TranslateString("",arItm.describe), arItm) + GetItemBonuses(arItm.id); // Levis
		}
	}
	SetFormatedText("TEXTWINDOW",describeStr);

	bEnableDown = SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE,"TEXTWINDOW", 6, 0);
}

void SetStartTradeQuantity()
{
	if( showType == SHOW_SELL )
	{
		nTradeQuantity = GetCharacterItem(refMyCh,GetItemsID(nCurScrollNum));
		if( nTradeQuantity>0 && IsEquipCharacterByItem(refMyCh, GetItemsID(nCurScrollNum)) ) {
			// TIH --> allow the selling of equipped items Jul15'06
			// EXCEPT the current equipped spyglass... it is a required special
			if ( Items[ GetItemIndex( GetItemsID(nCurScrollNum) ) ].groupID == SPYGLASS_ITEM_TYPE ) {
				nTradeQuantity--;
			}
			// TIH <-- allow sell equips
		}
		if(sellprice*nTradeQuantity > GetCharacterMoney(&refTrader))
		{
			nTradeQuantity = GetCharacterMoney(&refTrader) / sellPrice;
		}
		return;
	}

	nTradeQuantity = 0;
	AddTradeQuantity(1);
}

string GetItemStatus(string itemName, bool bIsForMy)
{
	if (bIsForMy) {
// KK -->
		int quantity = GetCharacterItem(refMyCh, itemName);
		int isEquiped = IsEquipCharacterByItem(refMyCh, itemName);
		if (isEquiped == true && Items[GetItemIndex(itemName)].groupID == SPYGLASS_ITEM_TYPE && quantity == 1) return "";
		if (isEquiped == true && quantity > 0) return "sell";
		if (isEquiped == false && quantity > 0) return "sell";
// <-- KK
		return "";
	} else {
		if (GetCharacterItem(refTrader, itemName) > 0) return "buy";
		return "";
	}
}

// START MOD Code by Stone-D : 29/07/2003
// LDH - June 27, 2006 - Sell all jewelry, indian trinkets and minerals that do not alter skills.  Won't sell quest items.
// LDH - Can sell lower quality blades as well.
// LDH - Also fixed a bug that missed some items each pass causing player to have to click Sell All Loot more than once.
void SellAllLoot()
{
    int i,j,s,t,q;
	int itmIdx;
	string itemName;
	aref curItem,arItem;
	aref refitm;
	aref rootItems;
	makearef(rootItems,refMyCh.Items);
	ref mchref = GetMainCharacter();
	// LDH -->
	int CharLevel = sti(mchref.rank);
	int JunkBladeMaxDamage;
	string itemShortName;
	// LDH <--
	bool SellMe;
	bool Done;

	j=0;
	q=0;
	t=0;
	Done=false;

	while (!Done)
	{
	Done = true;	// LDH moved from below
	for(i=0; i<GetAttributesNum(rootItems); i++)
    {
		curItem = GetAttributeN(rootItems,i);
		itemName = GetAttributeName(curItem);
		SellMe = false;
//		Done = true;  // LDH moved above, wasn't getting all items in one pass
		if(!TraderUseItem(&refTrader, itemName)) continue; // NK itemtrade 05-04-02 skip qty <=0 items.

// LDH -->
		itemShortName = strleft(itemName,5);	// LDH - shorten name

		if (itemShortName == "jewel")
		{
			SellMe = true;
		}
		if (itemShortName == "india")
		{
			SellMe = true;
		}
		if(itemShortName == "miner")
		{
			SellMe = true;
		}

		itmIdx = Items_FindItem(itemName,&refitm);	// Moved from below.  If function not called here the following code is broken.

		if (itmIdx >= 0)	// this test is probably unnecessary, but Items_FindItem must be called or rest of code doesn't work.
		{
			if (SELL_JUNK_BLADES && itemShortName == "blade")	// Sell low quality blades.
			{
				JunkBladeMaxDamage = 12;	// below level 5 sell daggers only (dmg 12)(20)
				if (CharLevel >= JUNK_BLADE_LEVEL_1) JunkBladeMaxDamage = 20;	// at level  5, start selling blades with max_dmg < 20(40)
				if (CharLevel >= JUNK_BLADE_LEVEL_2) JunkBladeMaxDamage = 25;	// at level  9, start selling blades with max_dmg < 25(60)
				if (CharLevel >= JUNK_BLADE_LEVEL_3) JunkBladeMaxDamage = 30;	// at level 13, start selling blades with max_dmg < 30(70)

				if (CheckAttribute(refitm, "dmg_max") && sti(refitm.dmg_max) < JunkBladeMaxDamage) SellMe = true;
				if (CheckAttribute(refitm, "piercing") && CheckAttribute(refitm, "block"))
				{
					if(sti(refitm.piercing) > 40 || sti(refitm.block) > 40) SellMe = false;	// don't sell if pierce/block over 40
				}
			}
			// LDH 22Jan09 - all items now have a skill attribute. Need to check for actual skill change
			// Don't sell items that alter skills (includes blades if blades ever have skill mods added)
//			if (CheckAttribute(refitm,"skill"))
			// LDH changed "defence" to "defence" - 06Feb09
			if (CheckAttribute(refitm,"skill.leadership") ||
				CheckAttribute(refitm,"skill.fencing") ||
				CheckAttribute(refitm,"skill.sailing") ||
				CheckAttribute(refitm,"skill.accuracy") ||
				CheckAttribute(refitm,"skill.cannons") ||
				CheckAttribute(refitm,"skill.grappling") ||
				CheckAttribute(refitm,"skill.repair") ||
				CheckAttribute(refitm,"skill.defence") ||
				CheckAttribute(refitm,"skill.commerce") ||
				CheckAttribute(refitm,"skill.sneak")
			   )
			{
				SellMe = false;
			}
		}
// LDH <--

		if(!SellMe) { continue; }
		itmIdx = Items_FindItem(itemName,&refitm);	// LDH moved above, left here just in case
		j = GetCharacterItem(refMyCh,itemName);
		if (ItemUsedByCharacter(itmIdx)) j = j - 1; // LDH - Don't sell equipped item as loot!
		// PB: Keep one of these for Treasure-Hunter-y -->
		if(itemName == "Minerspick" || itemName == "Minersspade")
		{
			j = j - 1;
		}
		// PB: Keep one of these for Treasure-Hunter-y <--
		if (j < 1) continue; // LDH
		s = GetTradeItemPrice(itmIdx,PRICE_TYPE_SELL);
		if(s<=0) { continue; } // Checks for quest items
		Done = false;
		q = q+j;
		t = t+(s*j);	// LDH fix, wasn't adding full amount for multiple items
		gTradetracker.tradeitems.(itemName) = q;	// LDH 15Oct06 - add trade numbers for merchant levelup for items sold by selling loot
		Log_SetStringToLog(GetAssembledString(TranslateString("",refitm.name),refitm) + ": " + j + " * " + s + " = " + (j*s));
		TakeNItems(refTrader,itemName,j);
		TakeNItems(refMyCh,itemName,-j);
		AddMoneyToCharacter(mchref,j*s);
		if(AUTO_SKILL_SYSTEM)
		{
			AddPartyExpChar(mchref, "Commerce", makeint(j*s/10));
			AddCharacterExpNSChar(&refTrader, "Commerce", makeint(j*s/10));
		}
		AddMoneyToCharacter(&refTrader,-j*s); // NK itemtrade 05-04-02
    }
	}
	if ( q > 0 ) Log_SetStringToLog(XI_ConvertString("Sold") + " " + q + " " + XI_ConvertString("items for") + " " + t);// TIH display fix, dont show if nothing sold
	UpdateScroll();
}

void UpdateScroll()
{
	int numItems=GameInterface.itemslist.ListSize;

	for (int i = 0; i <= numItems; i++) // KK
	{
		string attributeName = "pic"+(i+1);
		string itemName = GetItemsID(i);
		GameInterface.itemslist.(attributeName).str1 = "#" + GetCharacterItem(refMyCh, itemName) + " / " + GetCharacterItem(refTrader,itemName); // KK
		// TIH --> change equip status Jul15'06
		if ( IsEquipCharacterByItem(refMyCh,itemName) ) {
			GameInterface.itemslist.(attributeName).img2 = "usedflag";
			GameInterface.itemslist.(attributeName).tex2 = 1;
		} else {
			DeleteAttribute(&GameInterface,"itemslist."+ attributeName +".img2");
			DeleteAttribute(&GameInterface,"itemslist."+ attributeName +".tex2");
		}
		// TIH <--
		GameInterface.itemslist.(attributeName).img3 = GetItemStatus(itemName, true);
		GameInterface.itemslist.(attributeName).img4 = GetItemStatus(itemName, false);
		SendMessage(&GameInterface,"lsl", MSG_INTERFACE_SCROLL_CHANGE, "ITEMSLIST", i);// TIH done below
	}
	//SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"ITEMSLIST",-1);// TIH refresh the list once, instead on each item
}

// END MOD Code by Stone-D : 29/07/2003

// KK -->
void FreezeScreen(bool bSet)
{
	bSet = !bSet;
	SetSelectable("ITEMSLIST", bSet);
	SetNodeUsing("LEFTSCROLLBUTTON", bSet);
	SetNodeUsing("RIGHTSCROLLBUTTON", bSet);
	SetSelectable("I_WEAPON", bset == true && curItemGroup != GUN_ITEM_TYPE);
	SetSelectable("I_POTION", bset == true && curItemGroup != POTION_ITEM_TYPE);
	SetSelectable("I_ITEMS", bset == true && curItemGroup != OBJECT_ITEM_TYPE);
	SetSelectable("I_MAP", bset == true && curItemGroup != MAP_ITEM_TYPE);
}
// <-- KK
