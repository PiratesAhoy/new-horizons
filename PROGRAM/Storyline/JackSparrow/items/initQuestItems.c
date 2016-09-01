void InitQuestItems()
{
	int n = QUESTITEMS_QUANTITY;

	//--------------------------------------------------------------------------------------------------------------------------------------------------
	// QUEST ITEMS
	//------------------------------------------------------------------------------------O---------QUEST SETTINGS---------------------------O------
	// QUEST ITEMS: ItmIndex                                                   picIndex   |            startLocation , startLocator          |
	//			      | itmID                                     modelID           |     | setshown   |      useLocation , useLocator       |
	//			      |  |                txtname                    |  picTexture  |     | | shownval |      |           quest , tex , pic  |
	//----------------|--|-------------------|-----------------------|----------|---|-----O-|-|--------|------|-----------|------------------O------
	n = InitQuestItem(n,"Map_Doc_1",		"Map_Doc_1",			"",		   11,	6,		0,0,	"","",	"","",		"","",""	);
	n = InitQuestItem(n,"Map_Doc_2",		"Map_Doc_2",			"",		   11,	7,		0,0,	"","",	"","",		"","",""	);
	n = InitQuestItem(n,"Map_Doc_3",		"Map_Doc_3",			"",		   11, 10,		0,0,	"","",	"","",		"","",""	);
	n = InitQuestItem(n,"Map_Doc_4",		"Map_Doc_4",			"",		   11, 11,		0,0,	"","",	"","",		"","",""	);
	n = InitQuestItem(n,"small_chestJS",	"small_chestJS",		"",			4,	 1,		0,0,	"","",	"","",		"","",""	);

	QUESTITEMS_QUANTITY = n;
}
