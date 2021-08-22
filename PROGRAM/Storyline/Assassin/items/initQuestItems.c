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
	n = InitQuestItem(n,"order",		"order",			"",			4,	3,		0,0,	"","",	"","",		"","",""	);
	n = InitQuestItem(n,"report",		"report",			"",			4,	 8,		0,0,	"","",	"","",		"","",""	);
	n = InitQuestItem(n,"time_bomb",		"time_bomb",			"",			"ccc",	 1,		0,0,	"","",	"","",		"","",""	);
	n = InitQuestItem(n,"Gaga_Keys",		"Gaga_Keys",			"",			8,	   11,		0,0,	"","",	"","",		"","",""	);
	n = InitQuestItem(n,"Roche_letter",		"Roche_letter", "",		 4,	       16,		0,      0,	    "","",	"","",		"","",""	);	
	n = InitQuestItem(n,"Medal_B", 	        "Medal_B",			    "",			"medals2",	 2,		0,0,	"","",	"","",		"","",""	);
	n = InitQuestItem(n,"Pass",		"Pass",			"",			4,	3,		0,0,	"","",	"","",		"","",""	);
	n = InitQuestItem(n,"purse", 	        "purse",			    "",			"ccc",	 2,		0,0,	"","",	"","",		"","",""	);
	n = InitQuestItem(n,"fougasse",		"fougasse",			"",			"AS",	 3,		0,0,	"","",	"","",		"","",""	);
	n = InitQuestItem(n,"Medal_A", 	        "Medal_A",			    "",			"medals2",	 1,		0,0,	"","",	"","",		"","",""	);	
	QUESTITEMS_QUANTITY = n;
}
