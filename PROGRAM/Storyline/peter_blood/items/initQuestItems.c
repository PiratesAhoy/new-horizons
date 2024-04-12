void InitQuestItems()
{
	ref itm;
	int n = QUESTITEMS_QUANTITY;

	//--------------------------------------------------------------------------------------------------------------------------------------------------
	// QUEST ITEMS
	//------------------------------------------------------------------------------------O---------QUEST SETTINGS---------------------------O------
	// QUEST ITEMS: ItmIndex                                                   picIndex   |            startLocation , startLocator          |
	//			      | itmID                                     modelID           |     | setshown   |      useLocation , useLocator       |
	//			      |  |                txtname                    |  picTexture  |     | | shownval |      |           quest , tex , pic  |
	//----------------|--|-------------------|-----------------------|----------|---|-----O-|-|--------|------|-----------|------------------O------


//OBS ev har Questitems sina modeller i ITEMS, huh?


	n = InitQuestItem(n,"key_pitt",		"key_pitt",			"",	"JRH7",	1,	0,0,	"","",	"","",	"","",""); 


	QUESTITEMS_QUANTITY = n;
}
