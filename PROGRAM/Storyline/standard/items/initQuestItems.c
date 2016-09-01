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
	n = InitQuestItem(n,"Chest",			"chest",				"",			4,	1,		0,0,	"","",	"","",		"","",""	);
//	n = InitQuestItem(n,"coins",			"coins",				"purse",	4,	15,		0,0,	"","",	"","",		"","",""	); // Unused
//	n = InitQuestItem(n,"gov_letter",		"gov_letter",			"",			4,	3,		0,0,	"","",	"","",		"","",""	); // Unused
	n = InitQuestItem(n,"idol",				"incas_idol",			"stat1",	4,	4,		1,0,	"","",	"Labirint_3","button01",		"","",""	);
	n = InitQuestItem(n,"icollection",		"incas_collection",		"",			4,	5,		0,0,	"","",	"","",		"","",""	);
//	n = InitQuestItem(n,"legend_piece",		"piece_of_legend",		"",			4,	6,		0,0,	"","",	"","",		"","",""	); // Unused
	n = InitQuestItem(n,"legend_notes",		"notes_of_legend",		"",			4,	7,		0,0,	"","",	"","",		"","",""	);
//	n = InitQuestItem(n,"legend_copy",		"copyes_of_legend",		"",			4,	7,		0,0,	"","",	"","",		"","",""	); // Unused
	n = InitQuestItem(n,"rheims_journal",	"rheims_journal",		"",			4,	8,		0,0,	"","",	"","",		"","",""	);
	n = InitQuestItem(n,"domingues_fucked",	"compramat_to_domigues","",			4,	9,		0,0,	"","",	"","",		"","",""	);
//	n = InitQuestItem(n,"rheims_letter",	"rheims_letter",		"",			4,	10,		0,0,	"","",	"","",		"","",""	); // Unused
	n = InitQuestItem(n,"Massoni_papers",	"massoni_papers",		"",			4,	13,		0,0,	"","",	"","",		"","",""	);
	n = InitQuestItem(n,"artefact",			"artefact",				"",			1,	16,		0,0,	"","",	"","",		"onuseartefact","questcommands","0"	);
	n = InitQuestItem(n,"Story_Gramota",	"story_gramota",		"",			4,	 3,		0,0,	"","",	"","",		"","",""	);

	QUESTITEMS_QUANTITY = n;
}
