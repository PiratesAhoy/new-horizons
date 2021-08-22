#define SHOW_TYPE_MAIN		0
#define SHOW_TYPE_DISCARD	1
#define SHOW_TYPE_INFO		2

int nCurShowType = 0;

int nCurScrollNum;
int nCurFourNum;

ref  refCharacter;

int nDiscardQuantity = 0;
string strCurNodeName;

void InitInterface(string iniName)
{
	GameInterface.title = "titleShipHold";

	FillFourImage();
	FillScroll();

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();//MAXIMUS: standard exit-string for exit-button

	refCharacter = GetMainCharacter();
	CreateString(true,"Money",MakeMoneyShow(sti(refCharacter.Money),MONEY_SIGN,MONEY_DELIVER),FONT_NORMAL,COLOR_MONEY,320,393,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"ShipName","",FONT_SEADOGS,COLOR_NORMAL,320,201,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"Weight","",FONT_NORMAL,COLOR_NORMAL,304,240,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"FreeSpace","",FONT_NORMAL,COLOR_NORMAL,304,274,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(false,"Discarding","",FONT_NORMAL,COLOR_NORMAL,320,314,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(false,"GoodsName","",FONT_NORMAL,COLOR_YELLOW,320,232,SCRIPT_ALIGN_CENTER,0.9); // KK

	SetNodeUsing("DISCARD_COUNTER",false);
	SetNodeUsing("ALL_DISCARD",false);
	SetNodeUsing("CANCEL_DISCARD",false); // KK
	SetNodeUsing("OK_DISCARD",false);
	SetNodeUsing("GOODS_DESCRIBE",false);

	SetVariable();
	ProcessFrame();
	ChangeScroll();

// KK -->
	bool hasShip = false;
	for (int i = 0; i < COMPANION_MAX; i++) {
		int cidx = GetCompanionIndex(refCharacter, i);
		if (cidx < 0) continue;
		if (GetCharacterShipType(GetCharacter(cidx)) != SHIP_NOTUSED) {
			hasShip = true;
			break;
		}
	}
	SetSelectable("I_SHIPHOLD", !LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm() && hasShip);
	if (hasShip == false && GetBerthedShipsQuantityForTown(GetTownIDFromLocID(refCharacter.location)) > 0) {
		hasShip = true;
		GameInterface.GoDirectToShipBerthing = true;
		SendMessage(&GameInterface, "lsls", MSG_INTERFACE_MSG_TO_NODE, "I_SHIP", 0, XI_ConvertString("Sel Berth"));
	}

	if(CheckQuestAttribute("generate_trade_quest_progress", "begin"))
	{
		string sTradeDestination = FindTownName(refCharacter.quest.generate_trade_quest_progress.iTradeColony);
		string tradeGoodName = XI_ConvertString(Goods[sti(refCharacter.quest.generate_trade_quest_progress.iTradeGoods)].name);
		string stminfo = XI_ConvertString("Trade Mission Deliver") + " " + refCharacter.quest.generate_trade_quest_progress.iQuantityGoods + " " + XI_ConvertString("cwt") + ". " + tradeGoodName + " " + XI_ConvertString("into") + " " + TranslateString(sTradeDestination, "Store") + ".";
		if (GetSquadronGoods(refCharacter, sti(refCharacter.quest.generate_trade_quest_progress.iTradeGoods) < sti(refCharacter.quest.generate_trade_quest_progress.iQuantityGoods)))
		{
			int ishort = (sti(refCharacter.quest.generate_trade_quest_progress.iQuantityGoods) - GetSquadronGoods(refCharacter, sti(refCharacter.quest.generate_trade_quest_progress.iTradeGoods)));
			if (ishort > 0) stminfo += (" " + XI_ConvertString("Short by") + ishort + " " + XI_ConvertString("cwt") + ". " + XI_ConvertString("of") + " " + tradeGoodName + ".");
		}
		SetFormatedText("TRADEMISSION_INFO", stminfo);
		SetNodeUsing("TRADEMISSION_INFO", true);
	}
// <-- KK

// MAXIMUS interface MOD -->
	SetSelectable("I_SHIP", !LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm() && hasShip); // KK
	// KK SetSelectable("I_NATIONS",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	SetSelectable("I_TRADEBOOK",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	SetSelectable("I_QUESTBOOK",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	SetSelectable("I_SHIPLOG",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());	
	SetSelectable("EXIT_BUTTON",true);
	// MAXIMUS interface MOD <--

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("frame","ProcessFrame",1);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
}

void SelectDiscard()
{
	if(GetSelectable("DISCARD_BUTTON")==true)	SetCurrentNode("DISCARD_BUTTON");
	else	SetCurrentNode("INFO_BUTTON");
}

void FillFourImage()
{
	int i;
	string tmp1,tmp2,tmpStr;
	int tmpID;
	int bSelected;

	GameInterface.FourImage.current = 0;
	GameInterface.FourImage.BadTwoPicture = "interfaces\blank_ship.tga";
	GameInterface.FourImage.ImagesGroup.t0 = "ICONS";
	GameInterface.FourImage.ImagesGroup.t1 = "SHIPS16";
	GameInterface.FourImage.ImagesGroup.t2 = "SHIPS1";
	GameInterface.FourImage.ImagesGroup.t3 = "SHIPS2";
	GameInterface.FourImage.ImagesGroup.t4 = "SHIPS3";
	GameInterface.FourImage.ImagesGroup.t5 = "SHIPS4";
	GameInterface.FourImage.ImagesGroup.t6 = "SHIPS5";
	ref refMainCh = GetMainCharacter();
	for(i=0; i<COMPANION_MAX; i++)
	{
		bSelected=true;
		if(i==0)
		{
			tmpID = GetMainCharacterIndex();
		}
		else
		{
			tmpID = GetCompanionIndex(refMainCh,i);
		}
		if(tmpID!=-1)
		{
			tmpID = GetCharacterShipType(GetCharacter(tmpID)); // PS
			if(tmpID==SHIP_NOTUSED)
			{
				tmp1="";
				tmp2="";
				bSelected=false;
			}
			else
			{
				tmp1 = ShipsTypes[tmpID].Class;
				tmp2 = ShipsTypes[tmpID].SName; // PS
			}
		}
		else
		{
			tmp1="";
			tmp2="";
			bSelected=false;
		}
		tmpStr = "pic"+(i+1);
		GameInterface.FourImage.(tmpStr).selected	= bSelected;
		GameInterface.FourImage.(tmpStr).img1		= "ship back";
		if(GetShipTexture(tmpID)!=-1)	GameInterface.FourImage.(tmpStr).img2 = GetShipPicName(tmpID); // PS
		GameInterface.FourImage.(tmpStr).str1		= "#"+tmp1;
		GameInterface.FourImage.(tmpStr).str2		= GetShipString(tmpID); //PS tempfix XI_ConvertString(tmp2);
		GameInterface.FourImage.(tmpStr).tex1		= 0;
		GameInterface.FourImage.(tmpStr).tex2		= 1+GetShipTexture(tmpID); // PS
	}
}

void ProcessFrame()
{
	int cn;
	string sPlayerName;

	if(GetCurrentNode()!=strCurNodeName)
	{
		strCurNodeName = GetCurrentNode();
		switch(strCurNodeName)
		{
			case "SHIPSLIST":	SetShowType(SHOW_TYPE_MAIN); break;
			case "GOODSLIST":	SetShowType(SHOW_TYPE_MAIN); break;
			case "DISCARD_BUTTON":	SetShowType(SHOW_TYPE_MAIN); break;
			// KK case "INFO_BUTTON":	SetShowType(SHOW_TYPE_MAIN); break;
			case "DISCARD_COUNTER":	SetShowType(SHOW_TYPE_DISCARD); break;
			case "ALL_DISCARD":	SetShowType(SHOW_TYPE_DISCARD); break;
			case "CANCEL_DISCARD": SetShowType(SHOW_TYPE_DISCARD); break; // KK
			case "OK_DISCARD":	SetShowType(SHOW_TYPE_DISCARD); break;
			case "GOODS_DESCRIBE":	SetShowType(SHOW_TYPE_INFO); break;
		}
	}

	if(sti(GameInterface.FourImage.current)!=nCurFourNum)
	{
		nCurFourNum = sti(GameInterface.FourImage.current);
		refCharacter = GetMainCharacter();
		if(nCurFourNum>0)
		{
			cn = GetCompanionIndex(refCharacter,nCurFourNum);
			if(cn==-1)
			{
				nCurFourNum=0;
			}
			else
			{
				refCharacter = GetCharacter(cn);
			}
		}

		if(CheckAttribute(refCharacter,"Ship.Name"))
		{
			GameInterface.strings.ShipName = GetMyShipName(refCharacter);
		}
		else
		{
			GameInterface.strings.ShipName = XI_ConvertString(SHIP_NAME_NOTUSED);
		}

		GameInterface.strings.FreeSpace = RecalculateCargoLoad(refCharacter) + "/" + GetCargoMaxSpace(refCharacter); // PB: RecalculateCargoLoad was GetCargoLoad
		ChangeScroll();
	}

	if(nDiscardQuantity>0) SetSelectable("OK_DISCARD",true);
	else SetSelectable("OK_DISCARD",false);

	if(sti(GameInterface.goodslist.current)!=nCurScrollNum)
	{
		nCurScrollNum = sti(GameInterface.goodslist.current);
		SetSelectable("DISCARD_BUTTON",GetCargoGoods(refCharacter,GetGoodsIndexForI(nCurScrollNum))>0 && GetRemovable(refCharacter));
		GameInterface.strings.Weight = GetGoodWeightByType(GetGoodsIndexForI(nCurScrollNum),1) + " " + XI_ConvertString("cwt");
	}
}

void SetVariable()
{
	nCurScrollNum = -1;
	nCurFourNum = -1;
}

void FillScroll()
{
	int i;
	string attributeName;
	aref pRef;
	string goodsName;

	GameInterface.goodslist.current = 0;
	//GameInterface.goodslist.ListSize = GOODS_QUANTITY;// TIH
	GameInterface.goodslist.ImagesGroup.t1 = "ICONS";
	if (bNewIcons == true)
		GameInterface.goodslist.ImagesGroup.t2 = "GOODS_NEW";
	else
		GameInterface.goodslist.ImagesGroup.t2 = "GOODS";
	GameInterface.goodslist.SpecTechniqueColor = argb(55,255,255,255);
	GameInterface.goodslist.SpecTechniqueName = "iSpec1";
	int idx = 1;// TIH
	for(i=0; i<GOODS_QUANTITY; i++)
	{
		if (!CANNONPOWDER_MOD && i == GOOD_GUNPOWDER) continue;// TIH dont show if mod is OFF 7-7-06
	//	if (USE_REAL_CANNONS && i == GOOD_BOMBS) continue;// TIH dont show if mod is ON 7-7-06 // PB: Commented out to enable seeing bombs when you got some from the forts
		attributeName = "pic" + idx;// TIH
		makearef(pRef,GameInterface.goodslist.(attributeName));
		goodsName = Goods[i].Name;
		pRef.str1 = goodsName;
		pRef.str2 = "";
		pRef.img2 = goodsName;
		pRef.img1 = "cannon back";
		pRef.tex2 = 1;
		pRef.tex1 = 0;
		pRef.goodsNum = i;
		idx++;	// TIH
	}
	GameInterface.goodslist.ListSize = idx-1;// TIH
}

void ChangeScroll()
{
	int i;
	string attributeName;
	string goodsName;

	// fill visible goods
	int idx = 1;
	for(i=0; i<GOODS_QUANTITY; i++)
	{
		if(GetCargoGoods(refCharacter,i)==0) continue;
		if (!CANNONPOWDER_MOD && i == GOOD_GUNPOWDER) continue;// TIH dont show if mod is OFF 7-7-06
		//if (USE_REAL_CANNONS && i == GOOD_BOMBS) continue;// TIH dont show if mod is ON Jul10'06 // PB: Commented out to enable seeing bombs when you got some from the forts
		attributeName = "pic" + idx;
		GameInterface.goodslist.(attributeName).str1 = Goods[i].Name;
		GameInterface.goodslist.(attributeName).str2 = "#"+GetCargoGoods(refCharacter,i);
		GameInterface.goodslist.(attributeName).spec2 = false;
		GameInterface.goodslist.(attributeName).img2 = Goods[i].Name;
		GameInterface.goodslist.(attributeName).goodsNum = i;
		idx++;
	}
	// fill invisible goods
	for(i=0; i<GOODS_QUANTITY; i++)
	{
		if(GetCargoGoods(refCharacter,i)!=0) continue;
		if (!CANNONPOWDER_MOD && i == GOOD_GUNPOWDER) continue;// TIH dont show if mod is OFF 7-7-06
		//if (USE_REAL_CANNONS && i == GOOD_BOMBS) continue;// TIH dont show if mod is ON Jul10'06 // PB: Commented out to enable seeing bombs when you got some from the forts
		attributeName = "pic" + idx;
		GameInterface.goodslist.(attributeName).str1 = "";
		GameInterface.goodslist.(attributeName).str2 = "";
		GameInterface.goodslist.(attributeName).spec2 = true;
		GameInterface.goodslist.(attributeName).img2 = Goods[i].Name;
		GameInterface.goodslist.(attributeName).goodsNum = i;
		idx++;
	}
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"GOODSLIST",-1);
	if(GetRemovable(refCharacter) && GetCargoGoods(refCharacter,GetGoodsIndexForI(nCurScrollNum))>0)
	{
		SetSelectable("DISCARD_BUTTON",true);
	}
	else
	{
		SetSelectable("DISCARD_BUTTON",false);
	}
	GameInterface.strings.Weight = GetGoodWeightByType(GetGoodsIndexForI(nCurScrollNum),1) + " " + XI_ConvertString("cwt");
}

void ProcessCancelExit()
{
	interfaceResultCommand = RC_INTERFACE_SHIPHOLD_EXIT;
	IDoExit();
}

void IDoExit()
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("frame","ProcessFrame");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcessCommandExecute");

// MAXIMUS interface MOD -->
/*	if( CheckAttribute(&InterfaceStates,"InstantExit") && sti(InterfaceStates.InstantExit)==true )
	{
		EndCancelInterface(true);
	}
	else
	{
		PostEvent("LaunchIAfterFrame",1,"sl", "I_SELECTMENU", 1);
		EndCancelInterface(false);
	}*/
	EndCancelInterface(true);
// MAXIMUS interface MOD <--
}

void ProcessDiscard()
{
	SetShowType(SHOW_TYPE_DISCARD);
	nDiscardQuantity = 0;
	GameInterface.strings.Discarding = "0";
}

void DiscardOk()
{
// KK -->
	if(CheckQuestAttribute("generate_trade_quest_progress", "begin"))
	{
		string sTradeDestination = FindTownName(refCharacter.quest.generate_trade_quest_progress.iTradeColony);
		string tradeGoodName = XI_ConvertString(Goods[sti(refCharacter.quest.generate_trade_quest_progress.iTradeGoods)].name);
		string stminfo = XI_ConvertString("Trade Mission Deliver") + " " + refCharacter.quest.generate_trade_quest_progress.iQuantityGoods + " " + XI_ConvertString("cwt") + ". " + tradeGoodName + " " + XI_ConvertString("into") + " " + TranslateString(sTradeDestination, "Store") + ".";
		if (GetSquadronGoods(refCharacter, sti(refCharacter.quest.generate_trade_quest_progress.iTradeGoods) < sti(refCharacter.quest.generate_trade_quest_progress.iQuantityGoods)))
		{
			int ishort = (sti(refCharacter.quest.generate_trade_quest_progress.iQuantityGoods) - GetSquadronGoods(refCharacter, sti(refCharacter.quest.generate_trade_quest_progress.iTradeGoods)));
			if (ishort > 0) stminfo += (" " + XI_ConvertString("Short by") + ishort + " " + XI_ConvertString("cwt") + ". " + XI_ConvertString("of") + " " + tradeGoodName + ".");
		}
		SetFormatedText("TRADEMISSION_INFO", stminfo);
	}
// <-- KK
	RemoveCharacterGoods(refCharacter,GetGoodsIndexForI(nCurScrollNum),nDiscardQuantity);
	SetShowType(SHOW_TYPE_MAIN);
	GameInterface.strings.FreeSpace = GetCargoLoad(refCharacter)+"/"+GetCargoMaxSpace(refCharacter);
	ChangeScroll();
}

void DiscardAll()
{
	nDiscardQuantity = GetCargoGoods(refCharacter,GetGoodsIndexForI(nCurScrollNum));
	DiscardOk();
}

void DiscardCancel()
{
	SetShowType(SHOW_TYPE_MAIN);
	GameInterface.strings.FreeSpace = GetCargoLoad(refCharacter) + "/" + GetCargoMaxSpace(refCharacter);
	SetCurrentNode("GOODSLIST");
}

void DecreaseDiscard()
{
	if(nDiscardQuantity>0)
	{
		nDiscardQuantity = nDiscardQuantity - GetGoodsUnitSize();
		if(nDiscardQuantity<0) nDiscardQuantity = 0;
		GameInterface.strings.Discarding = ""+nDiscardQuantity;
		int oldGoodsQ = GetCargoGoods(refCharacter,GetGoodsIndexForI(nCurScrollNum));
		int deltaGoodsW = GetGoodWeightByType(GetGoodsIndexForI(nCurScrollNum),oldGoodsQ-nDiscardQuantity) - GetGoodWeightByType(GetGoodsIndexForI(nCurScrollNum),oldGoodsQ);
		GameInterface.strings.FreeSpace = (GetCargoLoad(refCharacter)+deltaGoodsW) + "/" + GetCargoMaxSpace(refCharacter);
	}
}

void IncreaseDiscard()
{
	if( nDiscardQuantity<GetCargoGoods(refCharacter,GetGoodsIndexForI(nCurScrollNum)) )
	{
		nDiscardQuantity = nDiscardQuantity + GetGoodsUnitSize();
		if( nDiscardQuantity > GetCargoGoods(refCharacter,GetGoodsIndexForI(nCurScrollNum)) )
		{
			nDiscardQuantity = GetCargoGoods(refCharacter,GetGoodsIndexForI(nCurScrollNum));
		}
		GameInterface.strings.Discarding = ""+nDiscardQuantity;
		int oldGoodsQ = GetCargoGoods(refCharacter,GetGoodsIndexForI(nCurScrollNum));
		int deltaGoodsW = GetGoodWeightByType(GetGoodsIndexForI(nCurScrollNum),oldGoodsQ-nDiscardQuantity) - GetGoodWeightByType(GetGoodsIndexForI(nCurScrollNum),oldGoodsQ);
		GameInterface.strings.FreeSpace = (GetCargoLoad(refCharacter)+deltaGoodsW) + "/" + GetCargoMaxSpace(refCharacter);
	}
}

int GetGoodsIndexForI(int n)
{
	if(n<0) return 0;
	string attrName = "pic"+(n+1);
	return sti(GameInterface.goodslist.(attrName).goodsNum);
}

int GetGoodsUnitSize()
{
	if(nCurScrollNum<0) return 0;
	return sti( Goods[GetGoodsIndexForI(nCurScrollNum)].Units );
}

void ProcessInfo()
{
// KK -->
	switch (nCurShowType)
	{
		case SHOW_TYPE_MAIN:
			SetShowType(SHOW_TYPE_INFO);
			string goodName;
			int lngFileID = LanguageOpenFile("GoodsDescribe.txt");
			goodName = Goods[GetGoodsIndexForI(nCurScrollNum)].Name;
			GameInterface.strings.GoodsName = LanguageConvertString(lngFileID,goodName);
			string goodsDescr = GetAssembledString( LanguageConvertString(lngFileID,goodName+"_descr"), &Goods[GetGoodsIndexForI(nCurScrollNum)]);
			SetFormatedText("GOODS_DESCRIBE",goodsDescr);
			LanguageCloseFile(lngFileID);
			SetCurrentNode("GOODS_DESCRIBE");
		break;
		case SHOW_TYPE_INFO:
			SetShowType(SHOW_TYPE_MAIN);
		break;
	}
// <-- KK
}

void SetShowType(int newShowType)
{
	if(newShowType==nCurShowType) return;

	switch(nCurShowType)
	{
	case SHOW_TYPE_MAIN:
		SetNodeUsing("DISCARD_BUTTON",false);
		SetNodeUsing("INFO_BUTTON",false);
		SetNodeUsing("MAIN_IMAGES",false);
		//SetNodeUsing("TRANSFER_BUTTON",false); // NK
		DisableString("Weight");
		DisableString("FreeSpace");
	break;
	case SHOW_TYPE_DISCARD:
		SetNodeUsing("DISCARD_COUNTER",false);
		SetNodeUsing("ALL_DISCARD",false);
		SetNodeUsing("CANCEL_DISCARD",false); // KK
		SetNodeUsing("OK_DISCARD",false);
		SetNodeUsing("MAIN_IMAGES",false);
		FreezeScreen(false); // KK
		//SetNodeUsing("TRANSFER_BUTTON",false); // NK
		DisableString("Discarding");
		DisableString("Weight");
		DisableString("FreeSpace");
	break;
	case SHOW_TYPE_INFO:
		DisableString("GoodsName"); // KK
		SetNodeUsing("GOODS_DESCRIBE",false);
// KK -->
		SendMessage(&GameInterface, "lsls", MSG_INTERFACE_MSG_TO_NODE, "INFO_BUTTON", 0, XI_ConvertString("INFO"));
		FreezeScreen(false);
// <-- KK
		//SetNodeUsing("TRANSFER_BUTTON",false); // NK
	break;
	}

	nCurShowType = newShowType;
	switch(nCurShowType)
	{
	case SHOW_TYPE_MAIN:
		SetNodeUsing("DISCARD_BUTTON",true);
		SetNodeUsing("INFO_BUTTON",true);
		SetNodeUsing("MAIN_IMAGES",true);
		//SetNodeUsing("TRANSFER_BUTTON",true); // NK
		EnableString("Weight");
		EnableString("FreeSpace");
	break;
	case SHOW_TYPE_DISCARD:
		SetNodeUsing("DISCARD_COUNTER",true);
		SetNodeUsing("ALL_DISCARD",true);
		SetNodeUsing("CANCEL_DISCARD",true); // KK
		SetNodeUsing("OK_DISCARD",true);
		SetNodeUsing("MAIN_IMAGES",true);
		FreezeScreen(true); // KK
		EnableString("Discarding");
		EnableString("Weight");
		EnableString("FreeSpace");
	break;
	case SHOW_TYPE_INFO:
		EnableString("GoodsName"); // KK
		SetNodeUsing("GOODS_DESCRIBE",true);
// KK -->
		FreezeScreen(true);
		SendMessage(&GameInterface, "lsls", MSG_INTERFACE_MSG_TO_NODE, "INFO_BUTTON", 0, XI_ConvertString("OK"));
		SetNodeUsing("INFO_BUTTON", true);
		SetCurrentNode("INFO_BUTTON");
// <-- KK
	break;
	}
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();
// MAXIMUS interface MOD -->
	int x;ref tmpch;string tmpstr;
	if(nodName=="I_CHARACTER")
	{
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_SHIPHOLD_EXIT;
			EndCancelInterface(false);
		}
	}
	if(nodName=="I_SHIP")
	{
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_SHIPHOLD_EXIT;
			EndCancelInterface(false);
		}
	}
	if(nodName=="I_PASSENGER")
	{
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_SHIPHOLD_EXIT;
			EndCancelInterface(false);
		}
	}
	if(nodName=="I_QUESTBOOK")
	{
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_SHIPHOLD_EXIT;
			EndCancelInterface(false);
		}
	}
	if(nodName=="I_TRADEBOOK")
	{
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_SHIPHOLD_EXIT;
			EndCancelInterface(false);
		}
	}
	if(nodName=="I_SHIPLOG")
	{
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_SHIPHOLD_EXIT;
			EndCancelInterface(false);
		}
	}
	if(nodName=="I_NATIONS")
	{
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_SHIPHOLD_EXIT;
			EndCancelInterface(false);
		}
	}
	if(nodName=="I_ITEMS")
	{
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_SHIPHOLD_EXIT;
			EndCancelInterface(false);
		}
	}
// MAXIMUS interface MOD <--

	switch(nodName)
	{
	case "GOODSLIST":
		// NK -->
		if(comName=="activate" || comName=="downstep")	{SelectDiscard();}
		/*if(comName=="activate")	{SelectDiscard();}
		if(comName=="downstep")	{SetCurrentNode("TRANSFER_BUTTON");}*/
		// NK <--
	break;

	case "DISCARD_BUTTON":
		if(comName=="activate" || comName=="click")
		{
			ProcessDiscard();
			SetCurrentNode("DISCARD_COUNTER");
		}
	break;

	case "INFO_BUTTON":
		if(comName=="activate" || comName=="click")	{ProcessInfo();}
		if(comName=="leftstep")	{SelectDiscard();}
	break;

	case "DISCARD_COUNTER":
		// KK if(comName=="deactivate")	{DiscardCancel();}
		if(comName=="leftstep")		{DecreaseDiscard();}
		if(comName=="rightstep")	{IncreaseDiscard();}
	break;

	case "ALL_DISCARD":
		// KK if(comName=="deactivate")	{DiscardCancel();}
		if(comName=="activate" || comName=="click")
		{
			DiscardAll();
			PlayStereoSound("OBJECTS\SHIPCHARGE\take_prey.wav");
			SetCurrentNode("GOODSLIST");
		}
	break;

// KK -->
	case "CANCEL_DISCARD":
		if (comName == "activate" || comName == "click")
		{
			DiscardCancel();
		}
	break;
// <-- KK

	case "OK_DISCARD":
		// KK if(comName=="deactivate")	{DiscardCancel();}
		if(comName=="activate" || comName=="click")
		{
			DiscardOk();
			PlayStereoSound("OBJECTS\SHIPCHARGE\take_prey.wav");
			SetCurrentNode("GOODSLIST");
		}
	break;
	}
}

// KK -->
void FreezeScreen(bool bSet)
{
	bSet = !bSet;
	SetSelectable("SHIPSLIST", bSet);
	SetSelectable("GOODSLIST", bSet);
	SetNodeUsing("LEFTSCROLLBUTTON", bSet);
	SetNodeUsing("RIGHTSCROLLBUTTON", bSet);
	SetSelectable("I_CHARACTER",bSet);
	SetSelectable("I_SHIP", bSet);
	SetSelectable("I_PASSENGER", bSet);
	SetSelectable("I_QUESTBOOK", bSet);
	SetSelectable("I_TRADEBOOK", bSet);
	SetSelectable("I_SHIPLOG", bSet);
	SetSelectable("I_NATIONS", bSet);
	SetSelectable("I_ITEMS", bSet);
}
// <-- KK
