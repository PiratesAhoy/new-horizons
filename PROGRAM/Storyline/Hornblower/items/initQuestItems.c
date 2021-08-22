void InitQuestItems()
{
	ref itm;
	int n = QUESTITEMS_QUANTITY;

	//--------------------------------------------------------------------------------------------------------------------------------------------------
	// QUEST ITEMS
	//----------------------------------------------------------------------------O---------QUEST SETTINGS------------------------------------O------
	// QUEST ITEMS: ItmIndex                                             picIndex |            startLocation , startLocator			  |
	//		     | itmID                             modelID	|     | setshown   |		useLocation , useLocator	  |
	//		  |  |                txtname            |  picTexture  |     | | shownval |		|              quest , tex , pic  |
	//----------------|--|-------------------|---------------|--------|-----|-----O-|-|--------|------------|---------------|------------------O------
	n = InitQuestItem(n,"MariasLetter",	"MariasLetter",	"",	 4,  	 11,	0,0,	   "", "",	"","",		"", "", ""); // Letter from Maria from shortly before she died

	QUESTITEMS_QUANTITY = n;
}