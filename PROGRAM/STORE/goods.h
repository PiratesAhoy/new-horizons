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
#define GOOD_GOLD       9   // 16.67
#define GOOD_SILVER     10  // 14.00
#define GOOD_CINNAMON	11	// 8.00
#define GOOD_CHOCOLATE	12	// 7.00
#define GOOD_COFFEE		13	// 7.00
#define GOOD_FOOD		14
#define GOOD_TREATMENT	15
#define GOOD_PAPRIKA	16	// 6.00
#define GOOD_WINE		17	// 5.00
#define GOOD_SANDAL		18	// 5.00
#define GOOD_EBONY		19  // 4.33
#define GOOD_MAHOGANY	20	// 4.00
#define GOOD_SUGAR		21	// 3.00
#define GOOD_TOBACCO	22	// 3.00
#define GOOD_ALE		23	// 3.00
#define GOOD_SILK		24	// 3.00
#define GOOD_LINEN		25	// 2.67
#define GOOD_FRUITS		26	// 2.67
#define GOOD_CLOTHES	27	// 2.67
#define GOOD_BRICKS     28  // 2.50
#define GOOD_OIL		29	// 2.50
#define GOOD_COTTON		30	// 2.00
#define GOOD_COPRA		31	// 1.50
#define GOOD_LEATHER	32	// 1.00

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
