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
	n = InitQuestItem(n,"a_letter",		"a_letter",			"",	"BTP1",	10,	0,0,	"",	"",	"","",	"","",""); //Letter from Eugene Devlin
	n = InitQuestItem(n,"first_part_map",	"first_part_map",		"",	"BTP2",	1,	0,0,	"",	"",	"","",	"","",""); //Beatrice's map piece
	n = InitQuestItem(n,"key_haraldo",	"key_haraldo",			"",	"JRH7",	1,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"jauri_note",	"jauri_note",			"",	"BTP3",	7,	0,0,	"",	"",	"","",	"","",""); //Note on Jauri's Door

	QUESTITEMS_QUANTITY = n;
}
