void Island_Start()
{
	SendMessage(&Island, "l", MSG_ISLAND_START);
}

void Island_Reload(string sIslandID, string sNewIslandModel)
{
	int iIslandID = FindIsland(sIslandID);
	if (iIslandID < 0)
	{
		return;
	}
	ref rIsland = GetIslandByIndex(iIslandID);
	rIsland.model = sNewIslandModel;
	if (bSeaActive)
	{
		SendMessage(&Island, "lsss", MSG_ISLAND_LOAD_GEO, "islands", rIsland.filespath.models, sNewIslandModel);
	}
}
