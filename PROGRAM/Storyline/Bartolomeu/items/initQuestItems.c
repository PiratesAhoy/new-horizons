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
	n = InitQuestItem(n,"Letter_Governor",		"Letter_Governor",    "",		4,	3,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"Letter_King",			"Letter_King",	      "",		4,	3,	0,0,	"","",	"","",	"","","");	
	n = InitQuestItem(n,"Darien_idol",			"Darien_idol",		"stat1",	4,	4,	1,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"navy_papers",			"navy_papers",	      "",		4,	3,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"Letter_Spy",			"Letter_Spy", 	      "",		4,	10,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"Fort_Keys",			"Fort_Keys",		  "",   	8,	11,	0,0,	"","",	"","",	"","","");	
	n = InitQuestItem(n,"muerte_map",			"muerte_map",		  "",  "maps", 	15,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"Animist_cloth", "Animist_cloth","Animist_cloth", "JRH17", 	11,	0,0,	"","",	"","",	"","","");
    n = InitQuestItem(n,"key3",   				"key3",				  "",  "JRH7",   3,	0,0,	"","",	"","",	"","","");
    n = InitQuestItem(n,"key4",   				"key4",				  "",  "JRH7",   4,	0,0,	"","",	"","",	"","","");
    n = InitQuestItem(n,"Montejo_Book",			"Montejo_Book",		  "",      13,  12,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"skull_ring",			"skull_ring", 	      "",   "BOP",	 8,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"moccasins",			"moccasins",          "",   "BOP",	 9,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"mayan_compass",   "mayan_compass", "mayan_compass","BOP",	10,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"empty_pipe",			"empty_pipe",         "",   "BOP",	11,	0,0,	"","",	"","",	"","","");	
	n = InitQuestItem(n,"filled_pipe",			"filled_pipe",        "",   "BOP",	12,	0,0,	"","",	"","",	"","","");	
	n = InitQuestItem(n,"dried_mushrooms",		"dried_mushrooms", 	  "",   "BOP",	13,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"pulverized_mushrooms","pulverized_mushrooms","",   "BOP",	14,	0,0,	"","",	"","",	"","","");

	n = InitBuildingItemJRH(n,	"build_clock2",			"build_clock2");	//Cartagena
	n = InitBuildingItemJRH(n,	"fire_irons_item",		"fire_irons_item");	//Cartagena
	n = InitBuildingItemJRH(n,	"lever_item",			"lever_item");		//Cartagena
	n = InitBuildingItemJRH(n,	"wall_weapons",			"wall_weapons");	//Cartagena

	QUESTITEMS_QUANTITY = n;
}
