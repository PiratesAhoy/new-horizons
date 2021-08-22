#define PRICE_TYPE_BUY	0
#define PRICE_TYPE_SELL	1

#event_handler("NextDay","StoreDayUpdateStart");
#event_handler("EvStoreDayUpdate","StoreDayUpdate");

// not needed now 05-05-12 ref rStoreTown; // NK 05-04-15 so we don't recalc each time

// change object to ref ( why object??? ) NK 05-05-12
void SetStoreGoods(ref _refStore,int _Goods,int _Quantity)
{
	string tmpstr = Goods[_Goods].name;
	_refStore.Goods.(tmpstr).Quantity = _Quantity;
}

void AddStoreGoods(ref _refStore,int _Goods,int _Quantity)
{
	aref refGoods;
	string tmpstr = Goods[_Goods].name;
	makearef(refGoods,_refStore.Goods.(tmpstr));
	int q = 0;
	if( CheckAttribute(refGoods,"Quantity") ) {q = sti(refGoods.Quantity);}
	refGoods.Quantity = q +_Quantity;
}

// Added by Levis
int AddTradeGood(ref sisland, string TradeType, int index, int Good)
{
	//First check if the good is somewhere already
	if(GetGoodTradeType(sisland, Good) == TRADE_TYPE_NORMAL)
	{
		string id = "id"+index;
		sisland.Trade.(TradeType).(id) = Good;
		index++;
	}
	return index;
}

void RemoveStoreGoods(ref _refStore,int _Goods,int _Quantity)
{
	aref refGoods;
	string tmpstr = Goods[_Goods].name;
	makearef(refGoods,_refStore.Goods.(tmpstr));
	int q = 0;
	if( CheckAttribute(refGoods,"Quantity") ) q = sti(refGoods.Quantity);
	if(q<_Quantity) {refGoods.Quantity = 0;}
	else {refGoods.Quantity = q - _Quantity;}
}

int GetStoreGoodsQuantity(ref _refStore,int _Goods)
{
	string tmpstr = Goods[_Goods].name;
	int q = 0;
	if( CheckAttribute(_refStore,"Goods."+tmpstr) )
	{
		q = sti(_refStore.Goods.(tmpstr).Quantity);
	}
	// Levis: Fetch Quest New -->
	ref ctown = GetTownFromID(GetTownIDFromGroup(_refStore.group));
	int count = 0;
	string cargoid = getAllFetchQuestCargo(count,ctown);
	while(cargoid != "")
	{
		if(sti(getCargoGood(Islands[FindIsland(ctown.island)], cargoid))==_Goods)
		{
			q = 0;
		}
		count++;
		cargoid = getAllFetchQuestCargo(count,ctown);
	}
	// Levis: Fetch Quest New <--
	return q;
}

// NK -->
int GetGoodPriceByType(ref refStore, ref char, int iGoodType, int quantity, int PriceType)
{
	//if(!TestRef(rStoreTown) || !CheckAttribute(rStoreTown,"size")) rStoreTown = GetCurrentTown();
	int unitSize = sti(Goods[iGoodType].Units);
	int i = iGoodType;
	bool tmpbooltn = false;
	string tname = GetTownIDFromGroup(refStore.group);
	int tsize = GetTownSize(tname);
	//if(CheckAttribute(rStoreTown,"id") && rStoreTown.id == tname) tmpbooltn = true;
	//if(!tmpbooltn)
	//{
		//rStoreTown = GetTownFromID(tname);
		//if(!CheckAttribute(rStoreTown,"size")) { trace("town " +tname + ", " + rStoreTown.name + " has no size!"); tsize = DEFAULT_TOWN_POP; }
		//else { tsize = sti(rStoreTown.size); } // assign the aref up here. NK 05-04-15
	//}
	//temp so it doesn't get so slow.
	// TIH added gunpowder here, as it KILLS the game with high quantitys! Jul20'06
	if( i==GOOD_BALLS || i==GOOD_GRAPES || i==GOOD_KNIPPELS || i==GOOD_BOMBS || i==GOOD_GUNPOWDER )
	{
		return makeint((quantity*GetStoreGoodsPrice(&refStore, iGoodType, PriceType, &char, 0) + unitSize-1) / unitSize);
	}
	//start normal good price find loop
	// sped up 05-04-15 NK
	//int oQty = GetStoreGoodsQuantity(refStore, iGoodType); // find orig qty.
	int price = 0;
	int mult = 1;
	if(PriceType == PRICE_TYPE_BUY) mult = -1;
	// new 05-04-15 -->
	string tmpstr = Goods[iGoodType].name;
	int gqty = refStore.Goods.(tmpstr).Quantity;
	if(gqty > 2 * quantity && gqty > tsize/4 ) // i.e. number is big enough we can do averages
	{
		price =  (GetStoreGoodsPrice(&refStore, iGoodType, PriceType, &char, 0) + GetStoreGoodsPrice(&refStore, iGoodType, PriceType, &char, mult * quantity)) / 2 * quantity;
	}
	else
	{
		for(i = 0; i < quantity; i++)
		{
			price += GetStoreGoodsPrice(&refStore, iGoodType, PriceType, &char, i);
		}
	}
	int sumPrice = (price + unitSize-1) / unitSize;
	return sumPrice;
}

// NK 05-04-15 PLEASE DON'T USE THIS FUNCTION. IT'S SLOW!
int GetGoodQuantityByPrice(ref refStore, ref char, int iGoodType, int sumPrice, int PriceType)
{
	//if(GetTownIDFromGroup(refStore.group) != "") { rStoreTown = GetTownFromID(GetTownIDFromGroup(refStore.group)); } // NK 05-04-15 set store's town aref.
	int unitSize = sti(Goods[iGoodType].Units);
	int i = 0;
	int curprice = 0;
	//int oQty = GetStoreGoodsQuantity(refStore, iGoodType); // find orig qty.
	sumPrice *= unitSize;
	/*int mult = 1;
	if(PriceType == PRICE_TYPE_BUY) mult = -1;*/
	while(curprice < sumPrice)
	{
		curprice += GetStoreGoodsPrice(&refStore, iGoodType, PriceType, &char, i);
		i++;
	}
	if(curprice > sumPrice) i--;
	i = i / unitSize;
	return i;
}

// NK <--

// 05-05-12 no longer needed. MUST SET rStoreTown FIRST, BEFORE CALLING THIS!
int GetStoreGoodsPrice(ref _refStore,int _Goods,int _PriceType,ref chref, int offset)
{
	if (LAi_IsCapturedLocation) return 0; // KK
	int _TradeSkill = GetShipSkill(chref,SKILL_COMMERCE);
	aref refGoods;
	string tmpstr = Goods[_Goods].name;
	int basePrice = MakeInt(Goods[_Goods].Cost);
	if( !CheckAttribute(_refStore,"Goods."+tmpstr) ) return 0;
	makearef(refGoods,_refStore.Goods.(tmpstr));
 	//int tradeType = MakeInt(refGoods.TradeType);
	string town = GetTownIDFromGroup(_refStore.group); // KK
	ref ctown = GetTownFromID(town); //Levis
	int tradeType = GetGoodTradeType(Islands[FindIsland(ctown.island)], _Goods); //Changed by levis to use common function //Changed again to use proper function
	int gqty = makeint(refGoods.Quantity) + offset; // NK
	if(gqty==0) { gqty = 1; }//MAXIMUS [fix "divide by zero"]
	
	float tradeModify=1.0;
	float discount = (0.1 * GetTownCrewMorale(town) / (MORALE_MAX - MORALE_MIN)) * makefloat(GetTownNation(town) == PERSONAL_NATION); // KK
	// NK -->
	if(tradeType == TRADE_TYPE_AMMUNITION) {
		basePrice -= makeint(basePrice * discount); // KK
		return basePrice;
	}
	tradeModify = 1.0 - 0.2 + stf(refGoods.RndPriceModify);
	/*switch(tradeType)
	{
	case TRADE_TYPE_NORMAL:
		tradeModify=0.8+stf(refGoods.RndPriceModify);
		break;
	case TRADE_TYPE_EXPORT:
		tradeModify=0.3+stf(refGoods.RndPriceModify);
		break;
	case TRADE_TYPE_IMPORT:
		tradeModify=1.3+stf(refGoods.RndPriceModify);
		break;
	case TRADE_TYPE_CONTRABAND:
		tradeModify=2.5+stf(refGoods.RndPriceModify);
		break;
	case TRADE_TYPE_AMMUNITION:
		return basePrice;
		break;
	}*/
	// NK <--

	float skillModify = GetCharPriceMod(&chref, _PriceType, true, false); // NK now use central func 05-04-19

	// NK -->
	int tsize = GetTownSize(GetTownIDFromGroup(_refStore.group));
	//NK now use global - if(GetTownIDFromGroup(_refStore.group) != "") { tsize = GetTownSize(GetTownIDFromGroup(_refStore.group)); }
	//if( != "") { tsize = sti(rStoreTown.size) } // NK 05-04-15
	float qtyModify = makefloat(tsize) / makefloat(gqty);
	//scale qty modifier. Funky scaling math for mod < 1.
	/*if(qtyModify >= 1) { qtyModify = 1.0 + ((qtyModify-1.0) * GQTY_PRICE_SCALAR); }
	else { qtyModify = 1/(1+((1/qtyModify)-1)*GQTY_PRICE_SCALAR); }*/
	qtyModify = pow2(qtyModify, GQTY_PRICECHG_POW); // 05-04-15 just use a power.
	if(tradeType == TRADE_TYPE_CONTRABAND)
	{
		qtyModify *= GQTY_CONTRABAND_PRICE_SCALAR;
		tradeModify = 0.5 + stf(refGoods.RndPriceModify);
	}
	qtyModify = fclamp(GQTY_PRICE_MINSCL, GQTY_PRICE_MAXSCL, qtyModify); // NK 05-04-15 to clamp qty modifier.
	return MakeInt(basePrice*tradeModify*skillModify * qtyModify - discount); // KK
	// NK <--
}

string GetStoreGoodsType(ref _refStore,int _Goods)
{
	//Changed by Levis to use island depended trade types
	ref ctown = GetTownFromID(GetTownIDFromGroup(_refStore.group));
	int tradeType = GetGoodTradeType(Islands[FindIsland(ctown.island)], _Goods);
	/*string tmpstr = Goods[_Goods].name;
	int tradeType = TRADE_TYPE_NORMAL;
	if( CheckAttribute(_refStore,"Goods."+tmpstr) ) {
		tradeType = sti(_refStore.Goods.(tmpstr).TradeType);
	}*/

	switch(tradeType)
	{
	case TRADE_TYPE_NORMAL:
		return TRADE_TYPE_NORMAL_NAME;
		break;
	case TRADE_TYPE_EXPORT:
		return TRADE_TYPE_EXPORT_NAME;
		break;
	case TRADE_TYPE_IMPORT:
		return TRADE_TYPE_IMPORT_NAME;
		break;
	case TRADE_TYPE_CONTRABAND:
		return TRADE_TYPE_CONTRABAND_NAME;
		break;
	case TRADE_TYPE_AMMUNITION:
		return TRADE_TYPE_AMMUNITION_NAME;
		break;
	}
	Trace("Missing trade type");
	return TRADE_TYPE_NORMAL_NAME;
}

//Added by Levis
int GetGoodTradeType(ref sisland, int Good)
{
	//This function returns the trade type set at the island for the good.
	int i,j,nq,n,tt;
	aref arTypes,arCurType;
	makearef(arTypes,sisland.Trade);
	nq = GetAttributesNum(arTypes);
	for(i=0;i<nq;i++)
	{
		arCurType = GetAttributeN(arTypes,i);
		tt=TRADE_TYPE_NORMAL;
		switch(GetAttributeName(arCurType))
		{
			case TRADE_TYPE_EXPORT_NAME:		tt=TRADE_TYPE_EXPORT;		break;
			case TRADE_TYPE_IMPORT_NAME:		tt=TRADE_TYPE_IMPORT;		break;
			case TRADE_TYPE_CONTRABAND_NAME:	tt=TRADE_TYPE_CONTRABAND;	break;
			case TRADE_TYPE_AMMUNITION_NAME:	tt=TRADE_TYPE_AMMUNITION;	break;
		}
		n = GetAttributesNum(arCurType);
		for(j=0;j<n;j++)
		{
			if(GetAttributeValue(GetAttributeN(arCurType,j))==Good) return tt;
		}
	}
	return TRADE_TYPE_NORMAL;
}

bool GetStoreGoodsUsed(ref _refStore,int _Goods)
{
	ref ctown = GetTownFromID(GetTownIDFromGroup(_refStore.group));//PW for using island not store attributes
	int tradeType = GetGoodTradeType(Islands[FindIsland(ctown.island)], _Goods);//PW for using island not store attributes

	string tmpstr = Goods[_Goods].name;
	if( !CheckAttribute(_refStore,"Goods."+tmpstr) ) return false;
	if( sti(_refStore.Goods.(tmpstr).NotUsed)==true ) return false;
	//if (sti(_refStore.Goods.(tmpstr).TradeType) == TRADE_TYPE_CONTRABAND) {
	if (tradeType == TRADE_TYPE_CONTRABAND)	// PW change to function to use island based tradeType
	{
		if (!CheckOfficersPerk(GetMainCharacter(),"Trustworthy") && !LAi_IsCapturedLocation && GetTownNation(GetTownIDFromGroup(_refStore.group)) != PERSONAL_NATION) return false; // KK
	}

	// KNB - Check NoTrade flag for goods.
	if( CheckAttribute(Goods[_Goods],"NoTrade") && Goods[_Goods].NoTrade == true) return false;

	return true;
}

void SetStoresTradeUsed(int StoreNum,int GoodsNum,bool goodsUsed)
{
	string tmpstr = Goods[GoodsNum].Name;
	Stores[StoreNum].Goods.(tmpstr).NotUsed = !goodsUsed;
}

int storeDayUpdateCnt = -1;
void StoreDayUpdateStart()
{
	//trace("Gauging: NEXTDAY_store updates start");
	if(storeDayUpdateCnt >= 0) return;
	storeDayUpdateCnt = 0;
	PostEvent("EvStoreDayUpdate", 30);
}
void StoreDayUpdate()
{
	if(storeDayUpdateCnt >= 0)
	{
		UpdateStore(&Stores[storeDayUpdateCnt]);
		storeDayUpdateCnt++;
		if(storeDayUpdateCnt >= STORE_QUANTITY) storeDayUpdateCnt = -1;
		PostEvent("EvStoreDayUpdate", 30);
	}
	//else trace("Gauging: NEXTDAY_store updates end");
}

void UpdateStore(ref pStore)
{
	bool bigSize = pStore.StoreSize=="large";
	aref gref, curref;
	makearef(gref,pStore.Goods);
	int nq = GetAttributesNum(gref);
	int n;
	string tmpstr;
	// NK -->
	int tsize = DEFAULT_TOWN_POP;
	bool pirtown = false;
	//string logstr = "";
	//if(GetTownIDFromGroup(pStore.group) != "")
	//{
		tsize = GetTownSize(GetTownIDFromGroup(pStore.group));
		pirtown = GetTownNation(GetTownIDFromGroup(pStore.group)) == PIRATE;
		//Log_SetStringToLog("Store " + pStore.group + " of town " +  GetTownIDFromGroup(pStore.group) + " (pop " + tsize + ")");
	//}
	// NK <--
	for(int i=0; i<GOODS_QUANTITY; i++)
	{
		tmpstr = Goods[i].name;
		if( !CheckAttribute(gref,tmpstr) ) continue;
		makearef(curref,gref.(tmpstr));
		if( sti(curref.TradeType)==TRADE_TYPE_AMMUNITION ) {
			// NK -->
			//curref.Quantity = 1000+Rand(50)*20;
			n = sti(curref.Quantity) / sti(goods[i].Units);
			if(n < TT_AMMO_SCALE * GQTY_MAX_SCALAR * tsize * (1 + pirtown)) n += GetProductGoods(TRADE_TYPE_NORMAL,tsize * (1 + pirtown)) / TT_NORMAL_SCALE * TT_AMMO_SCALE;
			n *= sti(goods[i].Units);
			curref.Quantity = n;
			continue;
		}
		/*if( i==GOOD_SAILCLOTH || i==GOOD_PLANKS ) {
			curref.Quantity = 600+Rand(100);
			continue;
		}*/
		n = sti(curref.Quantity);
		if(i == GOOD_WHEAT)
		{
			//logstr = "Wheat at " + GetTownIDFromGroup(pStore.group) + " is ";
			if(n < tsize * MIN_FOOD_SCALAR)
			{
				n += GetProductGoods(sti(curref.TradeType),tsize);
				n += (tsize * FOOD_PER_CREW / 2);
				//logstr += "less than min.";
			}
			else
			{
				n -= GetConsumeGoods(sti(curref.TradeType),tsize);
				n += (tsize * FOOD_PER_CREW / 2);
				//logstr = "greater than min";
				if(n < tsize * MAX_FOOD_SCALAR)
				{
					//logstr += " and less than max.";
					n += GetProductGoods(sti(curref.TradeType),tsize);
				}
				else
				{
					//logstr += " and greater than max.";
					n -= GetConsumeGoods(TRADE_TYPE_EXPORT,tsize);
				}
			}
			//logstr += " Change " + (n - sti(curref.Quantity)) + ".";
			//Log_SetStringToLog(logstr);
		}
		else
		{
			if(n > tsize * GQTY_HIGH_SCALAR * GetTTScale(sti(curref.TradeType))) n -= GetConsumeGoods(sti(curref.TradeType),tsize);
			if(n < tsize * GQTY_LOW_SCALAR * GetTTScale(sti(curref.TradeType))) n += GetProductGoods(sti(curref.TradeType),tsize);
			if(n > tsize * GQTY_SEMIHIGH_SCALAR * GetTTScale(sti(curref.TradeType))) n -= GetConsumeGoods(sti(curref.TradeType),tsize)*0.5;
			if(n < tsize * GQTY_SEMILOW_SCALAR * GetTTScale(sti(curref.TradeType))) n += GetProductGoods(sti(curref.TradeType),tsize)*0.5;
			if(n > tsize * GQTY_MIN_SCALAR * GetTTScale(sti(curref.TradeType))) n -= GetConsumeGoods(sti(curref.TradeType),tsize);
			if(n < tsize * GQTY_MAX_SCALAR * GetTTScale(sti(curref.TradeType))) n += GetProductGoods(sti(curref.TradeType),tsize);
		}
		if(n<0) n=0;
		// NK <--
		curref.RndPriceModify = AddPriceModify(stf(curref.RndPriceModify),sti(curref.TradeType));
		curref.Quantity = n;
	}
}

float AddPriceModify(float curModify, int tradeType)
{
	float fMaxModify = 0.39;
	if(tradeType==TRADE_TYPE_CONTRABAND) fMaxModify = 0.99;
	if(curModify>0.01)
	{
		if(curModify<fMaxModify)	curModify += 0.01 - 0.02*frnd();
		else	curModify -= 0.01*frnd();
	}
	else	curModify += 0.01*frnd();
	return curModify;
}

// NK -->
float GetTTScale(int tradeType)
{
	switch(tradeType)
	{
		case TRADE_TYPE_NORMAL:		return  TT_NORMAL_SCALE;	break;
		case TRADE_TYPE_EXPORT:		return  TT_EXPORT_SCALE;	break;
		case TRADE_TYPE_IMPORT:		return  TT_IMPORT_SCALE;	break;
		case TRADE_TYPE_CONTRABAND: return  TT_CONTRABAND_SCALE;	break;
	}
	return TT_NORMAL_SCALE;
}
int GetProductGoods(int tradeType, int size)
{
	float retnum = makefloat(size)/10.0*(1.0 - GQTY_VARIANCE + frand(GQTY_VARIANCE*2.0));
	switch(tradeType)
	{
		case TRADE_TYPE_NORMAL:		retnum *= TT_NORMAL_SCALE;	break;
		case TRADE_TYPE_EXPORT:		retnum *= TT_EXPORT_SCALE;	break;
		case TRADE_TYPE_IMPORT:		retnum *= TT_IMPORT_SCALE;	break;
		case TRADE_TYPE_CONTRABAND: retnum *= TT_CONTRABAND_SCALE;	break;
	}
	return makeint(retnum);
}

int GetConsumeGoods(int tradeType, int size)
{
	float retnum = makefloat(size)/10.0*(1.0 - GQTY_VARIANCE + frand(GQTY_VARIANCE*2.0));
	switch(tradeType)
	{
		case TRADE_TYPE_NORMAL: 	retnum *= TT_NORMAL_SCALE;	break;
		case TRADE_TYPE_EXPORT: 	retnum *= TT_EXPORT_SCALE;	break;
		case TRADE_TYPE_IMPORT: 	retnum *= TT_IMPORT_SCALE; break;
		case TRADE_TYPE_CONTRABAND: retnum *= TT_CONTRABAND_SCALE; break;
	}
	return makeint(retnum);
}
// NK <--

// KK -->
int GetStoreOwnerIndex(int store_no)
{
	if (store_no < 0 || store_no >= STORE_QUANTITY) return -1;
	if (!CheckAttribute(&Stores[store_no], "owner")) return -1;
	return GetCharacterIndex(Stores[store_no].owner);
}
// <-- KK
