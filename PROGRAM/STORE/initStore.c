// NK move this to seadogs.c - extern void StoreInit();

void InitStores()
{
	int i;
	// NK 05-03-30 use int qty and oversized array -->

	for(i=0; i<STORE_MAX; i++)
	{
		DeleteAttribute(&Stores[i],"");
		stores[i].index = i;
	}
	// OK, I'm putting the function in store.h rather than using loadsegment. 05-07-12
	//if(LoadSegment("store\store_init.c"))
	//{
		StoreInit();
		//UnloadSegment("store\store_init.c");
	//}

	for(i=0; i<STORE_QUANTITY; i++)
	{
		StoreVoidFill(&stores[i]); // now do this here, so we only do it when we need to.
		FillStoreGoods(&stores[i]);
	}
	// NK <--
}

void SetStoresTradeType(int StoreNum,int GoodsNum,int TradeType)
{
	string tmpstr = Goods[GoodsNum].Name;
	Stores[StoreNum].Goods.(tmpstr).TradeType = TradeType;
}

void FillStoreGoods(ref pRef)
{
	FillStoreGoods2(&pRef); // NK
}

void StoreVoidFill(ref pRef)
{
	string goodName;
	if(!CheckAttribute(pRef,"StoreSize")) pRef.StoreSize = "large"; // "small" // NK
	// NK 05-03-30 don't do this because we are initing stores _before_ this now. pRef.Island = "";
	for(int i=0; i<GOODS_QUANTITY; i++)
	{
	    goodName = Goods[i].Name;
	    pRef.Goods.(goodName).TradeType = TRADE_TYPE_NORMAL;
		pRef.Goods.(goodName).NotUsed = false;
	}
}
