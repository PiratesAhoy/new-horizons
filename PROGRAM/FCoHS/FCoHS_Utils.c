// ---------------------------------
// Calculate "Comply to Hail" chance
// ---------------------------------
float FCoHS_Util_CalculateComplyToHailChance(ref rShipCharacter)
{
	ref rMainCharacter = GetMainCharacter();
	// @CHECK (EL#1#): What to do if the ship doesn't have a FantomType
	if (!CheckAttribute(rShipCharacter, "FantomType")) return;

	float fBaseChance = sqr(stf(rMainCharacter.Reputation) / stf(REPUTATION_MAX));

	// @TODO (EL#1#): Implement further "Willingness to Comply" modifiers
	switch (rShipCharacter.FantomType)
	{
		case "trade":

			break;
		case "war":

			break;
		case "pirate":

			break;
	}
}


// --------------------
// Update the Tradebook
// --------------------
void FCoHS_Util_UpdateTradebookAway(int iStore)
{
	// @TODO (EL#3#): Find way to work with Storeref?
	ref refStore = &Stores[iStore];

	refStore.STORE_CURDATE = GetStringDate(GetDataYear(), GetDataMonth(), GetDataDay()) + " " + GetStringTime(GetTime());
	for (int g = 0; g < GOODS_QUANTITY; g++)
	{
		for (int i = 0; i < 7; i++)
		{
			string impAttr1, expAttr1, conAttr1, impAttr2, expAttr2, conAttr2, tradeAttr;
			int sellPrice, buyPrice;
			impAttr1 = "importsell" + i;
			expAttr1 = "exportsell" + i;
			conAttr1 = "contrasell" + i;
			impAttr2 = "importbuy" + i;
			expAttr2 = "exportbuy" + i;
			conAttr2 = "contrabuy" + i;
			tradeAttr = "id" + (i + 1);
			aref curIsland;
			makearef(curIsland, Islands[FindIsland(Stores[iStore].island)]);

			// LDH moved price calculations inside if statements for speed 04Mar09
			if (CheckAttribute(curIsland, "Trade.Import.id" + (i + 1)))
			{
				if (curIsland.Trade.Import.(tradeAttr) == g)
				{
					sellPrice = GetStoreGoodsPrice(refStore, FindGood(Goods[g].Name), PRICE_TYPE_SELL, GetMainCharacter(), 0);
					buyPrice  = GetStoreGoodsPrice(refStore, FindGood(Goods[g].Name), PRICE_TYPE_BUY, GetMainCharacter(), 0);
					refStore.(impAttr1) = sellPrice;
					refStore.(impAttr2) = buyPrice;
				}
			}
			if (CheckAttribute(curIsland, "Trade.Export.id" + (i + 1)))
			{
				if (curIsland.Trade.Export.(tradeAttr) == g)
				{
					sellPrice = GetStoreGoodsPrice(refStore, FindGood(Goods[g].Name), PRICE_TYPE_SELL, GetMainCharacter(), 0);
					buyPrice  = GetStoreGoodsPrice(refStore, FindGood(Goods[g].Name), PRICE_TYPE_BUY, GetMainCharacter(), 0);
					refStore.(expAttr1) = sellPrice;
					refStore.(expAttr2) = buyPrice;
				}
			}
			if (CheckAttribute(curIsland, "Trade.Contraband.id" + (i + 1)))
			{
				if (curIsland.Trade.Contraband.(tradeAttr) == g)
				{
					sellPrice = GetStoreGoodsPrice(refStore, FindGood(Goods[g].Name), PRICE_TYPE_SELL, GetMainCharacter(), 0);
					buyPrice  = GetStoreGoodsPrice(refStore, FindGood(Goods[g].Name), PRICE_TYPE_BUY, GetMainCharacter(), 0);
					refStore.(conAttr1) = sellPrice;
					refStore.(conAttr2) = buyPrice;
				}
			}
		}
	}
}
