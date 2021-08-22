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
	n = InitQuestItem(n,"Letter_Lafitte",	"Letter_Lafitte",	"",	4,	3,	0,0,	"",	"",	"","",	"","","");
	n = InitQuestItem(n,"time_bomb",	"time_bomb",		"",	"ccc",	1,	0,0,	"",	"",	"","",	"","","");

	n = InitQuestItem(n,"engineer_letter1",	"engineer_letter1",	"",	"JRH23", 13,	0,0,	"",	"",	"","",	"","",""); //closed
	n = InitQuestItem(n,"engineer_letter2",	"engineer_letter2",	"",	"JRH23", 14,	0,0,	"",	"",	"","",	"","",""); //open
	n = InitQuestItem(n,"engineer_letter3",	"engineer_letter3",	"",	"JRH23", 15,	0,0,	"",	"",	"","",	"","",""); //sheet

	n = InitQuestItem(n,"port_stock",	"port_stock",		"",	"JRH39", 1,	0,0,	"",	"",	"","",	"","","");
	n = InitQuestItem(n,"port_metal",	"port_metal",		"",	"JRH39", 2,	0,0,	"",	"",	"","",	"","","");
	n = InitQuestItem(n,"port_rest",	"port_rest",		"",	"JRH39", 3,	0,0,	"",	"",	"","",	"","","");
	n = InitQuestItem(n,"port_magazine",	"port_magazine",	"",	"JRH39", 4,	0,0,	"",	"",	"","",	"","","");
 	n = InitQuestItem(n,"port_barrel",	"port_barrel",		"",	"JRH39", 5,	0,0,	"",	"",	"","",	"","","");
	n = InitQuestItem(n,"port_mechanism",	"port_mechanism",	"",	"JRH39", 6,	0,0,	"",	"",	"","",	"","","");

	n = InitQuestItem(n,"port_2",		"port_2",		"",	"JRH39", 7,	0,0,	"",	"",	"","",	"","","");
	n = InitQuestItem(n,"port_3",		"port_3",		"",	"JRH39", 8,	0,0,	"",	"",	"","",	"","","");
	n = InitQuestItem(n,"port_4",		"port_4",		"",	"JRH39", 9,	0,0,	"",	"",	"","",	"","","");
	n = InitQuestItem(n,"port_5",		"port_5",		"",	"JRH39", 10,	0,0,	"",	"",	"","",	"","","");
	n = InitQuestItem(n,"port_tools",	"port_tools",		"",	"JRH39", 12,	0,0,	"",	"",	"","",	"","","");

	n = InitQuestItem(n,"poker_invite1",	"poker_invite1",	"",	"JRH39", 14,	0,0,	"",	"",	"","",	"","",""); //poker tournament invite 
	n = InitQuestItem(n,"poker_invite2",	"poker_invite2",	"",	"JRH39", 15,	0,0,	"",	"",	"","",	"","",""); //poker tournament invite

	n = InitQuestItem(n,"plans_copy",	"plans_copy",		"",	"GR",	10,	0,0,	"",	"",	"","",	"","",""); // Agent quest: copy of secret document
	
	n = InitQuestBlade(n, "bladetrophy",          "bladetrophy",     "JRH39", 13,   5,  10,      0,  5, 	  "", 0,   0);    //mini-trophy, won in poker tournament

	QUESTITEMS_QUANTITY = n;
}