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
	n = InitQuestItem(n,"juan_bucket_emp",	"juan_bucket_emp",		"",	"JRH13",  12,	0,0,	"",	"",	"","",	"","",""); //Empty Water Bucket
	n = InitQuestItem(n,"juan_bucket_ful",	"juan_bucket_ful",		"",	"JRH13",  16,	0,0,	"",	"",	"","",	"","",""); //Filled Water Bucket
	n = InitQuestItem(n,"sketch_paper",	"sketch_paper",			"",	"BTP3",	9,	0,0,	"",	"",	"","",	"","",""); //Paper
	n = InitQuestItem(n,"jorge_bible",	"jorge_bible",			"",	"JRH31", 3,	0,0,	"",	"",	"","",	"","",""); //Jorge's Bible
	n = InitQuestItem(n,"santiago_key",	"santiago_key",			"",	"24", 11,	0,0,	"",	"",	"","",	"","",""); //Key for Ricardo
	n = InitQuestItem(n,"blue_robe",	"blue_robe",			"",	"JRH17", 11,	0,0,	"",	"",	"","",	"","",""); //Blue Robe
	n = InitQuestItem(n,"second_part_map",	"second_part_map",		"",	"BTP2",	2,	0,0,	"",	"",	"","",	"","",""); //Blaze's map piece
	n = InitQuestItem(n,"full_map",	        "full_map",		        "",	"BTP",	8,	0,0,	"",	"",	"","",	"","",""); //Full map
	n = InitQuestItem(n,"jauri_map",	"jauri_map",		        "",	"BTP",	10,	0,0,	"",	"",	"","",	"","",""); //Jauri's map
	QUESTITEMS_QUANTITY = n;
}
