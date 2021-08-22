// Aconcagua: now defined as constant, replacing the MAX_GOODS var.
#define GOODS_QUANTITY 33

#define GOOD_WHEAT		0	// PB: Rations first
#define GOOD_RUM		1	// PB: Rations first
#define GOOD_BALLS		2
#define GOOD_GRAPES		3
#define GOOD_KNIPPELS	4
#define GOOD_BOMBS		5

#define GOOD_GUNPOWDER	6
#define GOOD_SAILCLOTH	7
#define GOOD_PLANKS		8	// Numbers below are value index based on cost per cwt, multiply by GOODS_PRICE_SCALAR for actual cost/cwt
#define GOOD_GOLD       9   // 100
#define GOOD_SILVER     10  // 62
#define GOOD_COFFEE	11	// 14
#define GOOD_CINNAMON	12	// 11.5
#define GOOD_MAHOGANY		13	// 10.5
#define GOOD_EBONY		14 //10.3
#define GOOD_WINE			15 //10
#define GOOD_SANDAL		16	// 10
#define GOOD_PAPRIKA		17	// 9
#define GOOD_TREATMENT	18	// 9
#define GOOD_CHOCOLATE	19  // 9
#define GOOD_ALE	20	// 9
#define GOOD_SILK		21	// 8.5
#define GOOD_TOBACCO	22	// 7.75
#define GOOD_CLOTHES		23	// 6.6
#define GOOD_SUGAR		24	// 6
#define GOOD_FRUITS		25	// 5.3
#define GOOD_LINEN		26	// 5.3 
#define GOOD_OIL	27	// 5
#define GOOD_FOOD     28  // 4
#define GOOD_COTTON		29	// 4
#define GOOD_LEATHER		30	// 3.6
#define GOOD_COPRA		31	// 3
#define GOOD_BRICKS	32	// 2.5

object  Goods[GOODS_QUANTITY]; // NK

ref GetGoodByType(int iGoodType)
{
	return &Goods[iGoodType];
}

int FindGood(string sGood)
{
	for (int i=0; i<GOODS_QUANTITY; i++) { if (Goods[i].Name == sGood) return i; }
	return -1;
}

ref GetGoodByID(string sGood)
{
	for (int i=0; i<GOODS_QUANTITY; i++) { if (Goods[i].Name == sGood) return &Goods[i]; }
	trace("WARNING! Goods ID (" + sGood +") not found!");
}

int GetGoodWeightByType(int iGoodType,int quantity)
{
	int unitSize = sti(Goods[iGoodType].Units);
	int unitQuantity = (quantity+unitSize-1)/unitSize;
	int weight = unitQuantity*sti(Goods[iGoodType].Weight);
	return weight;
}

int GetGoodQuantityByWeight(int iGoodType,int weight)
{
	int unitSize = sti(Goods[iGoodType].Units);
	int uqnt = weight/sti(Goods[iGoodType].Weight);
	return unitSize*uqnt;
}

// NK -->
float GetGoodPricePerWeight(int iGoodType)
{
	int price = MakeInt(Goods[iGoodType].Cost);
	int weight = MakeInt(Goods[iGoodType].Weight);
	float sumPrice = price / weight;
	return sumPrice;
}
// NK <--
