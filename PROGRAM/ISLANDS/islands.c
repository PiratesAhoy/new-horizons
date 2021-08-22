extern void InitIslands();

// KK -->
void IslandsInit()
{
	if(LoadSegment("islands\islands_init.c"))
	{
		InitIslands();
		UnloadSegment("islands\islands_init.c");
	}
	trace("IslandsInit: "+ISLANDS_QUANTITY+" islands loaded.");
}
// <-- KK

ref GetIslandByIndex(int iIslandIndex) 
{
	return &Islands[iIslandIndex]; 
}

ref GetIslandByID(string sIslandID)
{
	// NK use native 05-05-03 -->
	int idx = FindIsland(sIslandID);
	if(idx >= 0 && idx <ISLANDS_QUANTITY) return &Islands[idx];
	return &Islands[0];
	// NK <--
	/*for (int i=0;i<ISLANDS_QUANTITY;i++) // NK 05-03-30 use int for max, and oversized array
	{
		if (Islands[i].id == sIslandID) return &Islands[i];
	}
	//Trace("Invalid island ID: " + sIslandID);
	return &Islands[0];*/
}

aref FindIslandReloadLocator(string sIslandID, string sLocatorName)
{
	aref	arReload, arLocator;

	int		iIsland = FindIsland(sIslandID);
	if (iIsland < 0)
	{
		Trace("Can't find island sIslandID = " + sIslandID );
		// KK return arLocator;
		aref tmpref; makearef(tmpref, NullCharacter); // KK
		return tmpref; // KK
	}
	ref		rIsland = GetIslandByIndex(iIsland);
	makearef(arReload, rIsland.reload);
	int		iNumReload = GetAttributesNum(arReload);
	for (int i=0;i<iNumReload;i++)
	{
		arLocator = GetAttributeN(arReload, i);
		if (arLocator.Name == sLocatorName)
		{
			return arLocator;
		}
	}
	Trace("Can't find locator = " + sLocatorName + " on island sIslandID = " + sIslandID );
	return arLocator;
}

int FindIsland(string id)
{
	if (id=="") return -1;
	// NK use native 05-05-03 -->
	int idx = NativeFindCharacter(&Islands, id);
	if(idx >= 0 && idx <ISLANDS_QUANTITY) return idx;
	return -1;
	// NK <--
	/*for(int n = 0; n<ISLANDS_QUANTITY; n++) // NK 05-03-30 use int for max, and oversized array
	{
		if(Islands[n].id == id) return n;
	}
	return -1;*/
}

void Island_SetReloadEnableGlobal(string sIslandID, bool bEnable)
{
	ref rIsland = GetIslandByID(sIslandID);
	rIsland.reload_enable = bEnable;
}

void Island_SetReloadEnableLocal(string sIslandID, string sLocatorID, bool bEnable)
{
	aref arIslandReloadLocator = FindIslandReloadLocator(sIslandID, sLocatorID);
	arIslandReloadLocator.enable = bEnable;
}

bool Island_isReloadEnableGlobal(string sIslandID)
{
	ref rIsland = GetIslandByID(sIslandID);
	if(CheckCharacterItem(GetMainCharacter(), "Davy_Chest")) return false; // PB: The Curse of Davy Jones
	return sti(rIsland.reload_enable);
}

bool Island_isReloadFort(string sIslandID, string sLocatorID)
{
	aref arIslandReloadLocator = FindIslandReloadLocator(sIslandID, sLocatorID);
	if (CheckAttribute(arIslandReloadLocator,"fort")) return true;
	return false;
}

bool Island_isReloadEnableLocal(string sIslandID, string sLocatorID)
{
	aref arIslandReloadLocator = FindIslandReloadLocator(sIslandID, sLocatorID);
	if (!CheckAttribute(arIslandReloadLocator,"enable")) return true;
	return sti(arIslandReloadLocator.enable);
}

void Island_SetGotoEnableLocal(string sIslandID, string sLocatorID, bool bEnable)
{
	aref arIslandReloadLocator = FindIslandReloadLocator(sIslandID, sLocatorID);
	arIslandReloadLocator.goto_enable = bEnable;
}

bool Island_isGotoEnableLocal(string sIslandID, string sLocatorID)
{
	ref PChar = GetMainCharacter();
	aref arIslandReloadLocator = FindIslandReloadLocator(sIslandID, sLocatorID);
	if (!Island_isReloadEnableGlobal(sIslandID))				return false; // PB
	if (!Island_isReloadEnableLocal(sIslandID, sLocatorID))		return false; // PB
	if (CheckCharacterItem(PChar, "map"+sIslandID))				return true;  // PB
	if (iRealismMode == 0 || !DISCOVER_SAIL_TO)					return true;  // PB
	if (!CheckAttribute(arIslandReloadLocator,"goto_enable"))	return true;
	return sti(arIslandReloadLocator.goto_enable);
}

void Island_SetEncountersEnable(string sIslandID, bool bEnable)
{
	ref rIsland = GetIslandByID(sIslandID);
	rIsland.Enc_enable = bEnable;
}

bool Island_IsEncountersEnable(string sIslandID)
{
	ref rIsland = GetIslandByID(sIslandID);
	if (!CheckAttribute(rIsland, "Enc_enable")) return true;
	return sti(rIsland.Enc_enable);
}

int FindIslandBySeaLocation(string locID)
{
	if(FindIsland(locID)!=-1) return FindIsland(locID);//MAXIMUS
	int n,m;
	aref arroot,arreload;
	for(n=0; n<ISLANDS_QUANTITY; n++) // NK 05-03-30 use int for max, and oversized array
	{
		makearef(arroot,Islands[n].reload);
		for(m=0; m<GetAttributesNum(arroot); m++)
		{
			arreload = GetAttributeN(arroot,m);
			if(arreload.go == locID) return n;
		}
	}
	return -1;
}

// KK -->
string FindIslandName(string islandid)
{
	int iIsland;
	switch (islandid)
	{
		case "Falaise de Fleur":    islandid = "FalaiseDeFleur";     break;
		case "Isla Muelle":         islandid = "IslaMuelle";         break;
		case "Quebradas Costillas": islandid = "QuebradasCostillas"; break;
		case "Saint Martin":        islandid = "SaintMartin";        break;
		case "Khael Roa":           islandid = "KhaelRoa";           break;
		case "Petit Tabac":         islandid = "Battle_Rocks";       break;
		case "Isla Mona":           islandid = "IslaMona";           break;
	}
	iIsland = FindIsland(islandid);
	if (iIsland >= 0 && CheckAttribute(&Islands[iIsland], "name") == true) return XI_ConvertString(Islands[iIsland].name);
	return "";
}

void AddIsland(ref n, ref island, object locator)
{
	int i, inum, t, j, jnum, k;
	string sattr, st, sval, sIslandID;
	ref rIsland, chr, rPeriod;
	aref arTmps, arTmp, arNodes, arNode;
	bool bIsTown = false;
	bool bIsFort = false;
	makeref(rIsland, Islands[n]);
	makeref(rPeriod, Periods[GetCurrentPeriod()]);
	DeleteAttribute(rIsland, "");
	CopyAttributes(rIsland, island);

	sIslandID = rIsland.id;
	if (CheckAttribute(island, "towns")) {
		DeleteAttribute(rIsland, "towns");
		if(!IsIslandDisabled(rIsland.id))
		{
			if (CheckAttribute(rPeriod, "Islands." + sIslandID + ".towns")) makearef(arTmps, rPeriod.Islands.(sIslandID).towns);
			else makearef(arTmps, island.towns);
			inum = GetAttributesNum(arTmps);
			t = 1;
			st = t;
			for (i = 0; i < inum; i++)
			{
				arTmp = GetAttributeN(arTmps, i);
				sattr = GetAttributeValue(arTmp);
				if (!TownExist(sattr)) continue;
				rIsland.towns.(st) = sattr;
				t++;
				st = t;
			}
		}
		rIsland.towns.quantity = t - 1;
	}
	if (CheckAttribute(island, "reload")) {
		DeleteAttribute(rIsland, "reload");
		if(!IsIslandDisabled(rIsland.id))
		{
			if (CheckAttribute(rPeriod, "Islands." + sIslandID + ".reload")) makearef(arTmps, rPeriod.Islands.(sIslandID).reload);
			else makearef(arTmps, island.reload);
			inum = GetAttributesNum(arTmps);
			t = 1;
			st = "l" + t;
			for (i = 0; i < inum; i++)
			{
				arTmp = GetAttributeN(arTmps, i);
				if (!CheckAttribute(arTmp, "go")) continue;
				if (arTmp.go == "Fort") {
					if (!CheckAttribute(arTmp, "commander")) continue;
					sattr = arTmp.commander;
					for (j = 0; j < TOWNS_QUANTITY; j++)
					{
						jnum = GetTownNumForts(Towns[j].id);
						for (k = 0; k < jnum; k++)
						{
							if (GetTownFortCommanderID(Towns[j].id, k) == sattr) {
								bIsTown = false;
								bIsFort = true;
								sattr = Towns[j].id;
								break;
							}
						}
						if (sattr != arTmp.commander) break;
					}
				} else {
					bIsTown = true;
					bIsFort = false;
					sattr = GetTownIDFromLocID(arTmp.go)
				}
				makearef(arNodes, arTmps.(st));
				jnum = GetAttributesNum(arNodes);
				if (jnum > 0) {
					arNode = GetAttributeN(arNodes, 0);
					sattr = GetAttributeName(arNode);
					sval = GetAttributeValue(arNode);
					rIsland.reload.(st).(sattr) = sval;
					makearef(arNode, rIsland.reload.(st));
					CopyAttributes(arNode, arNodes);
				}
				t++;
				st = "l" + t;
			}
		}
	}

	if (CheckAttribute(rPeriod, "Islands." + sIslandID + ".Name"))
		rIsland.name = rPeriod.Islands.(sIslandID).Name;
	else
	{
		switch (sIslandID)
		{
			case "Conceicao":           rIsland.name = "Grenada";      break;
			case "Douwesen":            rIsland.name = "Bonaire";      break;
			case "FalaiseDeFleur":      rIsland.name = "Martinique";   break;
			case "IslaMuelle":          rIsland.name = "Puerto Rico";  break;
			case "Oxbay":               rIsland.name = "Barbados";     break;
			case "Redmond":             rIsland.name = "Jamaica";      break;
			case "QuebradasCostillas":  rIsland.name = "Nevis";        break;
			case "SaintMartin":         rIsland.name = "Saint Martin"; break;
			case "KhaelRoa":            rIsland.name = "Cozumel";      break;
			case "Battle_Rocks":        rIsland.name = "Petit Tabac";  break;
			case "IslaMona":            rIsland.name = "Isla Mona";    break;
			// default:
			                            rIsland.name = sIslandID;
		}
	}

	if (CheckAttribute(rPeriod, "Islands." + sIslandID + ".smuggling_nation")) rIsland.smuggling_nation = rPeriod.Islands.(sIslandID).smuggling_nation;

	if(IsIslandDisabled(rIsland.id))
	{
		rIsland.reload_enable = false;
		rIsland.visible = false;
	}
	else
	{
		if (!CheckAttribute(rIsland, "reload_enable")) rIsland.reload_enable = true;
		if (!CheckAttribute(rIsland, "visible")) rIsland.visible = true;
	}

	if (CheckAttribute(rPeriod, "Islands." + sIslandID + ".Model")) rIsland.model = rPeriod.Islands.(sIslandID).Model;

	SendMessage(&locator, "le", LM_LOCATE_I, rIsland);

	DeleteAttribute(island, "");
	n++;
}

bool IsIslandDisabled(string sIslandName)
{
	ref rPeriod;
	makeref(rPeriod, Periods[GetCurrentPeriod()]);
	if (CheckAttribute(rPeriod, "Islands." + sIslandName + ".disable") == true && sti(rPeriod.Islands.(sIslandName).disable) == true) return true;
	return false;
}
// <-- KK

string FindIslandByLocation(string locID)//MAXIMUS
{
	// PB: Simplified -->
	ref PChar = GetMainCharacter();
	if(locID != "")
	{
		int ind = FindIsland(locID);
		if (ind >= 0) // If location is an existing island
		{
			return locID; // Return that
		}
		else
		{
			ind = FindLocation(locID);
			if (ind >= 0) // You are in a valid location ashore
			{
				ref lcn = &locations[ind];
				if(CheckAttribute(lcn,"island"))				return lcn.island;							// Return location island
				if(CheckAttribute(lcn,"townsack"))				return GetIslandIDFromTown(lcn.townsack);	// If missing, return town's island
				if(CheckAttribute(PChar,"location.from_sea"))	return PChar.location.from_sea;				// For ship deck
			}
		}
		TraceAndLog("FindIslandByLocation ERROR: Please post your compile.log file at piratesahoy.net!");
		trace("No island found for " + locID);
	}
	return "";
	// PB: Simplified <--
/*	if(locID=="" || FindLocation(locID)==-1)
	{
		if(CheckAttribute(&characters[GetMainCharacterIndex()],"location.from_sea")) return Islands[FindIslandBySeaLocation(characters[GetMainCharacterIndex()].location.from_sea)].id;
		return "";
	}
	if(CheckAttribute(&locations[FindLocation(locID)],"townsack")) return GetIslandIDFromTown(GetCurrentTownID()); // PB: This is DEFINITELY wrong!
	if(CheckAttribute(&locations[FindLocation(locID)],"island")) return locations[FindLocation(locID)].island;
	if(FindIslandBySeaLocation(FindSeaShoreForLocation(locID))!=-1) return Islands[FindIslandBySeaLocation(FindSeaShoreForLocation(locID))].id;
	return "";*/
}
