//Different Worktypes for Islands
#define		ISLAND_WORKTYPE_MINING		0
#define		ISLAND_WORKTYPE_TIMBER		1
#define		ISLAND_WORKTYPE_FARMING		2
#define		ISLAND_WORKTYPE_SPICES		3
#define		ISLAND_WORKTYPE_PLANTATION	4
#define		ISLAND_WORKTYPE_PROCESSING	5

void GetIslandOptions(ref island, ref q, string tradetype)
{
	int worktype = GetIslandWorktyp(island);
	switch(worktype)
	{
		case ISLAND_WORKTYPE_MINING:
			switch(tradetype)
			{
				//Export
				case TRADE_TYPE_EXPORT_NAME:
					AddIslandOption(island, q, GOOD_GOLD);
					AddIslandOption(island, q, GOOD_SILVER);
					AddIslandOption(island, q, GOOD_BRICKS);
				break;
				//Import
				case TRADE_TYPE_IMPORT_NAME:
					AddIslandOption(island, q, GOOD_MAHOGANY);
					AddIslandOption(island, q, GOOD_GUNPOWDER);
					AddIslandOption(island, q, GOOD_COFFEE);
				break;
				//Contraband
				case TRADE_TYPE_CONTRABAND_NAME:
					AddIslandOption(island, q, GOOD_EBONY);
				break;
			}
		break;
		
		case ISLAND_WORKTYPE_TIMBER:
			switch(tradetype)
			{
				//Export
				case TRADE_TYPE_EXPORT_NAME:
					AddIslandOption(island, q, GOOD_SANDAL);
					AddIslandOption(island, q, GOOD_EBONY);
					AddIslandOption(island, q, GOOD_MAHOGANY);
				break;
				//Import
				case TRADE_TYPE_IMPORT_NAME:
					AddIslandOption(island, q, GOOD_CINNAMON);
					AddIslandOption(island, q, GOOD_CLOTHES);
					AddIslandOption(island, q, GOOD_BRICKS);
				break;
				//Contraband
				case TRADE_TYPE_CONTRABAND_NAME:
					AddIslandOption(island, q, GOOD_COPRA);
				break;
			}
		break;
		
		case ISLAND_WORKTYPE_FARMING:
			switch(tradetype)
			{
				//Export
				case TRADE_TYPE_EXPORT_NAME:
					AddIslandOption(island, q, GOOD_FOOD);
					AddIslandOption(island, q, GOOD_FRUITS);
					AddIslandOption(island, q, GOOD_COPRA);
				break;
				//Import
				case TRADE_TYPE_IMPORT_NAME:
					AddIslandOption(island, q, GOOD_SAILCLOTH);
					AddIslandOption(island, q, GOOD_LEATHER);
					AddIslandOption(island, q, GOOD_SANDAL);
				break;
				//Contraband
				case TRADE_TYPE_CONTRABAND_NAME:
					AddIslandOption(island, q, GOOD_TOBACCO);
				break;
			}
		break;
		
		case ISLAND_WORKTYPE_SPICES:
			switch(tradetype)
			{
				//Export
				case TRADE_TYPE_EXPORT_NAME:
					AddIslandOption(island, q, GOOD_CINNAMON);
					AddIslandOption(island, q, GOOD_PAPRIKA);
					AddIslandOption(island, q, GOOD_SUGAR);
				break;
				//Import
				case TRADE_TYPE_IMPORT_NAME:
					AddIslandOption(island, q, GOOD_LINEN);
					AddIslandOption(island, q, GOOD_FRUITS);
					AddIslandOption(island, q, GOOD_COTTON);
				break;
				//Contraband
				case TRADE_TYPE_CONTRABAND_NAME:
					AddIslandOption(island, q, GOOD_OIL);
				break;
			}
		break;
		
		case ISLAND_WORKTYPE_PLANTATION:
			switch(tradetype)
			{
				//Export
				case TRADE_TYPE_EXPORT_NAME:
					AddIslandOption(island, q, GOOD_COFFEE);
					AddIslandOption(island, q, GOOD_COTTON);
					AddIslandOption(island, q, GOOD_TOBACCO);
				break;
				//Import
				case TRADE_TYPE_IMPORT_NAME:
					AddIslandOption(island, q, GOOD_PLANKS);
					AddIslandOption(island, q, GOOD_ALE);
					AddIslandOption(island, q, GOOD_FOOD);
				break;
				//Contraband
				case TRADE_TYPE_CONTRABAND_NAME:
					AddIslandOption(island, q, GOOD_SUGAR);
				break;
			}
		break;
		
		case ISLAND_WORKTYPE_PROCESSING:
			switch(tradetype)
			{
				//Export
				case TRADE_TYPE_EXPORT_NAME:
					AddIslandOption(island, q, GOOD_OIL);
					AddIslandOption(island, q, GOOD_ALE);
					AddIslandOption(island, q, GOOD_LEATHER);
				break;
				//Import
				case TRADE_TYPE_IMPORT_NAME:
					AddIslandOption(island, q, GOOD_SILVER);
					AddIslandOption(island, q, GOOD_TREATMENT);
					AddIslandOption(island, q, GOOD_PAPRIKA);
				break;
				//Contraband
				case TRADE_TYPE_CONTRABAND_NAME:
					AddIslandOption(island, q, GOOD_CHOCOLATE);
				break;
			}
		break;
	}
}

void GetEconomyOptions(ref ctown, ref island, ref q, string tradetype)
{
	int economy = GetTownEconomy(ctown);
	switch(economy)
	{
		case TOWN_ECONOMY_STARVING:
			switch(tradetype)
			{
				//Export
				case TRADE_TYPE_EXPORT_NAME:
					AddIslandOption(island, q, GOOD_PLANKS);
					AddIslandOption(island, q, GOOD_BRICKS);
				break;
				//Import
				case TRADE_TYPE_IMPORT_NAME:
					AddIslandOption(island, q, GOOD_FOOD);
				break;
				//Contraband
				case TRADE_TYPE_CONTRABAND_NAME:
					AddIslandOption(island, q, GOOD_SILK);
				break;
			}
		break;
		
		case TOWN_ECONOMY_STRUGGLING:
			switch(tradetype)
			{
				//Export
				case TRADE_TYPE_EXPORT_NAME:
					AddIslandOption(island, q, GOOD_CLOTHES);
					AddIslandOption(island, q, GOOD_SANDAL);
				break;
				//Import
				case TRADE_TYPE_IMPORT_NAME:
					AddIslandOption(island, q, GOOD_COTTON);
				break;
				//Contraband
				case TRADE_TYPE_CONTRABAND_NAME:

				break;
			}
		break;
		
		case TOWN_ECONOMY_SURVIVING:
			switch(tradetype)
			{
				//Export
				case TRADE_TYPE_EXPORT_NAME:
					AddIslandOption(island, q, GOOD_COPRA);
					AddIslandOption(island, q, GOOD_SAILCLOTH);
				break;
				//Import
				case TRADE_TYPE_IMPORT_NAME:
					AddIslandOption(island, q, GOOD_CHOCOLATE);
				break;
				//Contraband
				case TRADE_TYPE_CONTRABAND_NAME:
					AddIslandOption(island, q, GOOD_LINEN);
				break;
			}
		break;
		
		case TOWN_ECONOMY_PROSPERING:
			switch(tradetype)
			{
				//Export
				case TRADE_TYPE_EXPORT_NAME:
					AddIslandOption(island, q, GOOD_WINE);
					AddIslandOption(island, q, GOOD_SILK);
				break;
				//Import
				case TRADE_TYPE_IMPORT_NAME:
					AddIslandOption(island, q, GOOD_OIL);
				break;
				//Contraband
				case TRADE_TYPE_CONTRABAND_NAME:
				
				break;
			}
		break;
		
		case TOWN_ECONOMY_WEALTHY:
			switch(tradetype)
			{
				//Export
				case TRADE_TYPE_EXPORT_NAME:
					AddIslandOption(island, q, GOOD_CHOCOLATE);
					AddIslandOption(island, q, GOOD_TREATMENT);
				break;
				//Import
				case TRADE_TYPE_IMPORT_NAME:
					AddIslandOption(island, q, GOOD_GOLD);
				break;
				//Contraband
				case TRADE_TYPE_CONTRABAND_NAME:
					AddIslandOption(island, q, GOOD_CLOTHES);
				break;
			}
		break;
	}
}

void GetNationOptions(ref ctown, ref island, ref q, string tradetype)
{
	int nation = GetTownNation(ctown.id);
	switch(nation)
	{
		case ENGLAND:
			switch(tradetype)
			{
				//Export
				case TRADE_TYPE_EXPORT_NAME:
					AddIslandOption(island, q, GOOD_GUNPOWDER);
				break;
				//Import
				case TRADE_TYPE_IMPORT_NAME:
					AddIslandOption(island, q, GOOD_CINNAMON);
					AddIslandOption(island, q, GOOD_SUGAR);
				break;
				//Contraband
				case TRADE_TYPE_CONTRABAND_NAME:
					AddIslandOption(island, q, GOOD_LEATHER);
				break;
			}
		break;
		
		case FRANCE:
			switch(tradetype)
			{
				//Export
				case TRADE_TYPE_EXPORT_NAME:
					AddIslandOption(island, q, GOOD_WINE);
				break;
				//Import
				case TRADE_TYPE_IMPORT_NAME:
					AddIslandOption(island, q, GOOD_EBONY);
					AddIslandOption(island, q, GOOD_FRUITS);
				break;
				//Contraband
				case TRADE_TYPE_CONTRABAND_NAME:
					AddIslandOption(island, q, GOOD_ALE);
				break;
			}
		break;
		
		case SPAIN:
			switch(tradetype)
			{
				//Export
				case TRADE_TYPE_EXPORT_NAME:
					AddIslandOption(island, q, GOOD_LEATHER);
				break;
				//Import
				case TRADE_TYPE_IMPORT_NAME:
					AddIslandOption(island, q, GOOD_GOLD);
					AddIslandOption(island, q, GOOD_SILVER);
				break;
				//Contraband
				case TRADE_TYPE_CONTRABAND_NAME:
					AddIslandOption(island, q, GOOD_SANDAL);
				break;
			}
		break;
		
		case PIRATE:
			switch(tradetype)
			{
				//Export
				case TRADE_TYPE_EXPORT_NAME:
					AddIslandOption(island, q, GOOD_ALE);
				break;
				//Import
				case TRADE_TYPE_IMPORT_NAME:
					AddIslandOption(island, q, GOOD_COPRA);
					AddIslandOption(island, q, GOOD_SANDAL);
				break;
				//Contraband
				case TRADE_TYPE_CONTRABAND_NAME:
					AddIslandOption(island, q, GOOD_WINE);
				break;
			}
		break;
		
		case HOLLAND:
			switch(tradetype)
			{
				//Export
				case TRADE_TYPE_EXPORT_NAME:
					AddIslandOption(island, q, GOOD_LINEN);
				break;
				//Import
				case TRADE_TYPE_IMPORT_NAME:
					AddIslandOption(island, q, GOOD_TOBACCO);
					AddIslandOption(island, q, GOOD_MAHOGANY);
				break;
				//Contraband
				case TRADE_TYPE_CONTRABAND_NAME:
					AddIslandOption(island, q, GOOD_COFFEE);
				break;
			}
		break;
		
		case PORTUGAL:
			switch(tradetype)
			{
				//Export
				case TRADE_TYPE_EXPORT_NAME:
					AddIslandOption(island, q, GOOD_SILK);
				break;
				//Import
				case TRADE_TYPE_IMPORT_NAME:
					AddIslandOption(island, q, GOOD_WINE);
					AddIslandOption(island, q, GOOD_SILK);
				break;
				//Contraband
				case TRADE_TYPE_CONTRABAND_NAME:
					AddIslandOption(island, q, GOOD_FRUITS);
				break;
			}
		break;
		
		case AMERICA:
			switch(tradetype)
			{
				//Export
				case TRADE_TYPE_EXPORT_NAME:
					AddIslandOption(island, q, GOOD_GOLD);
				break;
				//Import
				case TRADE_TYPE_IMPORT_NAME:
					AddIslandOption(island, q, GOOD_PLANKS);
					AddIslandOption(island, q, GOOD_LINEN);
				break;
				//Contraband
				case TRADE_TYPE_CONTRABAND_NAME:
					AddIslandOption(island, q, GOOD_BRICKS);
				break;
			}
		break;
	}
}

bool AddIslandOption(ref island, ref q, int good);
{
	//Check so we don't have double items
	if(CheckAttribute(island,"Trade.Options"))
	{
		aref options;
		makearef(options, island.Trade.Options);
		int optionsnum = GetAttributesNum(options);
		for(int i=0; i<optionsnum; i++)
		{
			if(sti(GetAttributeN(options,i)) == good)
			{
				return false;
			}
		}
	}
	//If everything is okay add it
	string id = "id" + sti(q);
	island.Trade.Options.(id) = good;
	q++;
	return true;
}

int GetIslandWorktyp(ref island)
{
	return sti(island.Trade.Worktype);
}

bool UpdateTownImportExport(ref Store, bool skipdaycheck)
{
	//This function changes the import/export products of a town if needed.
	//Get the town
	ref ctown = GetTownFromGroup(Store.group);
	ctown.id = Store.group; //Stupid GetTown ...
	//Check if the attribute exist else make it.
	int yeardays = GetDayOfYear(GetDataYear(), GetDataMonth(), GetDataDay());
	if(!CheckAttribute(Store,"lastimportupdate")) Store.lastimportupdate = yeardays;
	//Check if we need to run again
	int day = sti(Store.lastimportupdate);
	if(yeardays < day) 
	{
		day = day + GetYearDays(GetDataYear() - 1);
	}
	if((day + UPDATE_IMPORT_PER_DAYS) < yeardays || skipdaycheck ==  True)
	{
		//Get some refs
		int n = 0;
		ref q = &n;
		ref island = GetIslandByID(Store.Island);
		int shifttt = rand(3);
		if(CheckAttribute(island,"Trade.Worktype"))
		{
			//Reset the store for easier processing
			for(j=0; j<GOODS_QUANTITY: j++)
			{
				string goodName = Goods[j].Name;
				if(CheckAttribute(Store,"Goods."+goodName))
				{
					if(Store.Goods.(goodName).TradeType != TRADE_TYPE_AMMUNITION)
					{
						Store.Goods.(goodName).TradeType = TRADE_TYPE_NORMAL;
					}
				}
				else
				{
					Store.Goods.(goodName).TradeType = TRADE_TYPE_NORMAL;
				}
			}
			for(int i=1; i<4: i++)
			{
				int index = i+shifttt;
				if(index>3) index -= 3;
				//Go from 1 to 3 which is import/export/contraband
				string tradetype = GetTradeTypeName(index);
				string storename = Store.Group;
				//Delete the old island settings
				DeleteAttribute(island,"Trade."+storename+"."+tradetype);
				//Get the options from the Island
				GetIslandOptions(island, q, tradetype);
				//Get the options from the Nations
				GetNationOptions(ctown, island, q, tradetype)
				//Get options from economy
				GetEconomyOptions(ctown, island, q, tradetype)
				//Select the options we want
				int shift = 0;
				for(int j=1; j<7: j++)
				{
					//A little bit of randomization
					aref options;
					makearef(options, island.Trade.Options);
					int optionsnum = GetAttributesNum(options);
					int choose = rand(optionsnum)-1;
					if(choose == -1)
					{
						shift -= 1;
					}
					else
					{
						// Set the island
						string id = "id" + (j + shift);
						string optionid = GetAttributeName(GetAttributeN(options,choose));
						//Check if the thing isn't import/export already before setting it as contraband
						bool add = true
						string StoreTradeType = GetStoreGoodsType(Store, sti(options.(optionid)));
						if(StoreTradeType == TRADE_TYPE_NORMAL_NAME)
						{
							// Set the island
							island.Trade.(storename).(tradetype).(id) = options.(optionid);
							// Set the store
							goodName = Goods[sti(options.(optionid))].Name;
							Store.Goods.(goodName).TradeType = GetTradeTypeByName(tradetype);
						}
						else
						{
							shift -= 1;
						}
						// Remove the options
						string delete = "Trade.Options." + optionid;
						DeleteAttribute(island,delete);
					}
				}
				DeleteAttribute(island,"Trade.Options");
			}
			return true;
		}
		Store.lastimportupdate = yeardays;
	}
	return false;
}