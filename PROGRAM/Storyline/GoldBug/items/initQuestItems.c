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


//OBS Questitems har sina modeller i ITEMS!

	n = InitQuestItem(n,"book49",		"book49",	  "book49",    "JRH12",  9,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"1_log",	        "1_log",	   "1_log",    "JRH19",	 6,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"marsh_hen",      	"marsh_hen",   "marsh_hen",    "JRH20",	 2,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"crypto",         	"crypto",         "crypto",    "JRH19",	 9,	0,0,	"","",	"","",	"","",""); //
    	n = InitQuestItem(n,"crypto1",         	"crypto1",          	"",    "JRH20", 13,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"crypto2",         	"crypto2",          	"",    "JRH20", 14,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"crypto_excel",     "crypto_excel",         "",    "JRH17", 12,	0,0,	"","",	"","",	"","",""); //

	n = InitQuestItem(n,"shell1",         	"shell1",         "shell1",    "JRH20",	 3,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"shell2",         	"shell2",         "shell2",    "JRH20",	 4,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"shell3",         	"shell3",         "shell3",    "JRH20",	 5,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"shell4",         	"shell4",         "shell4",    "JRH20",	 6,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"shell5",         	"shell5",         "shell5",    "JRH20",	 7,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"shell6",         	"shell6",         "shell6",    "JRH20",	 8,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"shell_collection", "shell_collection",     "",    "JRH20",  9,	0,0,	"","",	"","",	"","",""); //

	n = InitQuestItem(n,"goldbug",	       	"goldbug",       "goldbug",    "JRH19",	 4,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"goldbug2",	       	"goldbug2",       	"",    "JRH17",	 5,	0,0,	"","",	"","",	"","","");//wrapped in paper
	n = InitQuestItem(n,"wrinkled_paper",   "wrinkled_paper",       "",    "JRH17",	 6,	0,0,	"","",	"","",	"","","");//
	n = InitQuestItem(n,"bird_sketch",      "bird_sketch",       	"",    "JRH17",	 7,	0,0,	"","",	"","",	"","","");//
	n = InitQuestItem(n,"bird_sketch_doc",  "bird_sketch_doc",      "",    "JRH17",	 7,	0,0,	"","",	"","",	"","","");//
	n = InitQuestItem(n,"bird_backside",    "bird_backside",       	"",    "JRH17",	 9,	0,0,	"","",	"","",	"","","");//
	n = InitQuestItem(n,"BH_sketch",        "BH_sketch",       	"",    "JRH17",	10,	0,0,	"","",	"","",	"","","");//
	n = InitQuestItem(n,"BH_sketch_out",	"BH_sketch_out",       	"",    "JRH17",	10,	0,0,	"","",	"","",	"","","");//
	n = InitQuestItem(n,"rolled_paper",     "rolled_paper",       	"",    "JRH17",	13,	0,0,	"","",	"","",	"","","");//
	n = InitQuestItem(n,"rolled_paper_gp",	"rolled_paper_gp",      "",    "JRH17",	14,	0,0,	"","",	"","",	"","","");//

	n = InitQuestItem(n,"inkpen",          	"inkpen",         "inkpen",    "JRH19",	 3,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"key12",		"key12",	"chest2_vco",	"JRH7",	12,	0,0,	"","",	"","",	"","",""); //(mine tunnel1) used here only for the green box
	n = InitQuestItem(n,"key2",		"key2",			"",     "JRH7",  2,	0,0,	"","",	"","",	"","",""); //to Legrands weaponslocker
	n = InitQuestItem(n,"key20",		"key20",	"keymiddle",   "JRH19",  8,	0,0,	"","",	"","",	"","",""); //to Legrands grot
	n = InitQuestItem(n,"key21",		"key21",	        "",    "JRH20", 12,	0,0,	"","",	"","",	"","",""); //to hotel room1 
	n = InitQuestItem(n,"key22",		"key22",	        "",    "JRH20", 16,	0,0,	"","",	"","",	"","",""); //to sacristy from church Charleston


	n = InitQuestItem(n,"key24",		"key24",       "keymiddle",    "JRH22", 13,	0,0,	"","",	"","",	"","",""); //to Chinatown charcoal
	n = InitQuestItem(n,"key25",		"key25",	        "",    "JRH22", 14,	0,0,	"","",	"","",	"","",""); //to Chinatown sulphur
	n = InitQuestItem(n,"key26",		"key26",      "chest2_vco",    "JRH22", 15,	0,0,	"","",	"","",	"","",""); //to Chinatown nitre, green box
	n = InitQuestItem(n,"key27",		"key27",	  	"",    "JRH22", 16,	0,0,	"","",	"","",	"","",""); //to Chinatown gunpowder mixing

	n = InitQuestItem(n,"key28",		"key28",	  	"",    "JRH24", 13,	0,0,	"","",	"","",	"","",""); //to Charleston Brothel
        n = InitQuestItem(n,"key29",		"key29",	  	"",    "JRH25",  5,	0,0,	"","",	"","",	"","",""); //to Charleston Tailor
	n = InitQuestItem(n,"key30",		"key30",       "keymiddle",    "JRH17", 15,	0,0,	"","",	"","",	"","",""); //to Maroon Cave
	n = InitQuestItem(n,"key31",		"key31",                "",    "JRH25", 14,	0,0,	"","",	"","",	"","",""); //to FM Gate Tower
	n = InitQuestItem(n,"key32",		"key32",                "",    "JRH25", 15,	0,0,	"","",	"","",	"","",""); //to FM Prison

	n = InitQuestItem(n,"bigfish",		"bigfish",	 "bigfish",	    "", "",	0,0,	"","",	"","",	"","",""); //as an item at church	
	n = InitQuestItem(n,"meat",		"meat",			"",	"JRH4",	 9,	0,0,	"","",	"","",	"","","");
    	n = InitQuestItem(n,"2winebottles",	"2winebottles",		"",	"JRH4",	11,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"bread",		"bread",		"",	"JRH4",	13,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"ale",		"ale",	      "barrel_ale",	"JRH4",	14,	0,0,	"","",	"","",	"","",""); 

	n = InitQuestItem(n,"letter_paper",	"letter_paper",	        "",    "JRH20",	10,	0,0,	"","",	"","",	"","",""); 
	n = InitQuestItem(n,"surgery_kit",	"",	     "surgery_kit",	    "", "",	0,0,	"","",	"","",	"","",""); //as an item in Legrands grot

	n = InitQuestItem(n,"key7",		"key7",			"",	"JRH7",  7,	0,0,	"","",	"","",	"","",""); //G:s house
	n = InitQuestItem(n,"key8",		"key8",		"invisible",	"JRH7",	 8,	0,0,	"","",	"","",	"","",""); //invisible

	n = InitQuestItem(n,"spyglass5",	"",	       "spyglass5",        "",  "",	0,0,	"","",	"","",	"","",""); //randitem spyglass5
	n = InitQuestItem(n,"book26",		"book26",		"",	"JRH5",	 6,	0,0,	"","",	"","",	"","",""); //medicine
	n = InitQuestItem(n,"book27",		"book27",		"",	"JRH5",	 7,	0,0,	"","",	"","",	"","",""); //chemistry
	n = InitQuestItem(n,"book33",		"book33",		"",	"JRH5",	13,	0,0,	"","",	"","",	"","",""); //geography

	n = InitQuestItem(n,"book21",		"book21",		"",	"JRH5",	 1,	0,0,	"","",	"","",	"","",""); //law
	n = InitQuestItem(n,"chain",		"chain",		"",     "JRH3",	 9,	0,0,	"","",	"","",	"","",""); //chain & handcuffs	
	n = InitQuestItem(n,"medicine_leaves",	"medicine_leaves",	"",	"JRH9",  1,	0,0,	"","",	"","",	"","","");

	n = InitQuestItem(n,"measuring_tape",	"measuring_tape",	"",    "JRH24",	 1,	0,0,	"","",	"","",	"","",""); //measuring-tape
	n = InitQuestItem(n,"peg",		"peg",			"",    "JRH24",	 3,	0,0,	"","",	"","",	"","",""); //peg
	n = InitQuestItem(n,"knitting_basket",	"knitting_basket","knitting_basket","JRH26", 4, 0,0,	"","",	"","",	"","",""); //basket
	n = InitQuestItem(n,"magnet",		"magnet",		"",    "JRH26",	 7,	0,0,	"","",	"","",	"","",""); //magnet
	n = InitQuestItem(n,"magnet2",		"magnet2",		"",    "JRH26",	 8,	0,0,	"","",	"","",	"","",""); //magnet with a string
        n = InitQuestItem(n,"knitting",		"knitting",		"",    "JRH26",	 1,	0,0,	"","",	"","",	"","",""); //
        n = InitQuestItem(n,"yarn",		"yarn",		        "",    "JRH26",	 2,	0,0,	"","",	"","",	"","",""); //
        n = InitQuestItem(n,"needles",		"needles",		"",    "JRH26",	 3,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"needles2",		"needles2",		"",    "JRH26",	 6,	0,0,	"","",	"","",	"","",""); //as lockpick tools
	n = InitQuestItem(n,"pliers",		"pliers",		"",    "JRH24",	 8,	0,0,	"","",	"","",	"","",""); //

	n = InitQuestItem(n,"wax_candles",	"wax_candles",		"",    "JRH26",	 9,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"altar_bread",	"altar_bread",		"",    "JRH26",	10,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"flyswatter",	"flyswatter",		"",    "JRH26",	12,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"shrine",		"shrine",		"",    "AS",	 3,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"cowl",		"cowl",			"",    "JRH17",	11,	0,0,	"","",	"","",	"","","");

	n = InitQuestItem(n,"blue_uniform",	"blue_uniform",		"",     "JRH4", 15,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"2winebottles",	"2winebottles",		"",	"JRH4",	11,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"book28",		"book28",		"",	"JRH5",	 8,	0,0,	"","",	"","",	"","",""); //erotica
	n = InitQuestItem(n,"book29",		"book29",		"",	"JRH5",	 9,	0,0,	"","",	"","",	"","",""); //poetry
	n = InitQuestItem(n,"book30",		"book30",		"",	"JRH5",	10,	0,0,	"","",	"","",	"","",""); //collection of poetry

	n = InitQuestItem(n,"mdchest",		"",	 	 "mdchest",	    "", "",	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"mdchest_broken",	"",	  "mdchest_broken",	    "", "",	0,0,	"","",	"","",	"","",""); //

	n = InitQuestItem(n,"book42",		"book42",    "scroll_long",    "JRH12",  2,	0,0,	"","",	"","",	"","",""); //alchemy: 3parted scroll
	n = InitQuestItem(n,"book47",		"book47",   "bb_Map_piece",    "JRH12",  7,	0,0,	"","",	"","",	"","",""); //alchemy: worn parchment

	n = InitQuestItem(n,"gibbet_rope",	"gibbet_rope",	 	"",    "JRH24",	 4,	0,0,	"","",	"","",	"","",""); //visible on Legrand body
	n = InitQuestItem(n,"fort_rope",	"fort_rope",	 	"",    "JRH24",	 4,	0,0,	"","",	"","",	"","",""); //visible on Legrand body
	n = InitQuestItem(n,"cork",		"cork",	 		"",    "JRH24",	 5,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"corkscrew",	"corkscrew",	 	"",    "JRH24",	 6,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"spyglass6",	"",	       "spyglass6",         "", "",	0,0,	"","",	"","",	"","",""); //randitem spyglass6, model not prepared yet

	n = InitQuestItem(n,"book52",		"book52",		"",    "JRH17",	 1,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"book53",		"book53",		"",    "JRH17",	 2,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"book54",		"book54",		"",    "JRH17",	 3,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"book55A",		"book55A",		"",    "JRH25",	 1,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"book55B",		"book55B",		"",    "JRH25",	 2,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"book55C",		"book55C",		"",    "JRH25",	 3,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"book55D",		"book55D",		"",    "JRH25",	 4,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"book56",		"book56",		"",    "JRH25",	 6,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"book57",		"book57",		"",    "JRH25",	 7,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"book58",		"book58",		"",    "JRH25",	 8,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"book59",		"book59",		"",    "JRH25",	 9,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"book60",		"book60",		"",    "JRH25",	10,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"book61A",		"book61A",		"",    "JRH26",	13,	0,0,	"","",	"","",	"","",""); //hymn book with letters
	n = InitQuestItem(n,"book61B",		"book61B",		"",    "JRH26",	14,	0,0,	"","",	"","",	"","",""); //hymn book with letters
	n = InitQuestItem(n,"book61C1",		"book61C1",		"",    "JRH26",	15,	0,0,	"","",	"","",	"","",""); //hymn book with letters
	n = InitQuestItem(n,"book61C2",		"book61C2",		"",    "JRH26",	 5,	0,0,	"","",	"","",	"","",""); //hymn book with letters
	n = InitQuestItem(n,"book61D",		"book61D",		"",    "JRH26",	16,	0,0,	"","",	"","",	"","",""); //hymn book with letters

	n = InitQuestItem(n,"detective_kit1",	"detective_kit1",	"",    "JRH18",	 1,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"detective_kit2",	"detective_kit2",	"",    "JRH18",	12,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"detective_kit3",	"detective_kit3",	"",    "JRH18",	 2,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"detective_kit4",	"detective_kit4",	"",    "JRH18",	 3,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"detective_kit5",	"detective_kit5",	"",    "JRH18",	 3,	0,0,	"","",	"","",	"","",""); //
	
	n = InitQuestItem(n,"D_feather",	"D_feather",		"",    "JRH18",	 4,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"D_scissors",	"D_scissors",		"",    "JRH18",	 5,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"D_compasses",	"D_compasses",		"",    "JRH18",	 6,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"D_scalpel",	"D_scalpel",		"",    "JRH18",	 7,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"D_magnifying",	"D_magnifying",		"",    "JRH18",	 8,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"D_tweezers",	"D_tweezers",		"",    "JRH18",	 9,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"D_hairpin",	"D_hairpin",		"",    "JRH18",	10,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"D_key23",		"D_key23",		"",    "JRH18",	11,	0,0,	"","",	"","",	"","",""); //

	n = InitQuestItem(n,"med_bag1_obj",	"med_bag1_obj",		"",    "JRH17",	 4,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"med_bag1_doc_NO",	"med_bag1_doc_NO",	"",    "JRH17",	 4,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"med_bag1_doc_YES",	"med_bag1_doc_YES",	"",    "JRH17",	 4,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"med_bag1_out",	"med_bag1_out",		"",    "JRH17",	 4,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"med_bag2_obj",	"med_bag2_obj",		"",    "JRH17",	 8,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"med_bag2_doc",	"med_bag2_doc",		"",    "JRH17",	 8,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"med_bag2_out",	"med_bag2_out",		"",    "JRH17",	16,	0,0,	"","",	"","",	"","",""); //

	n = InitQuestItem(n,"Poes_clothes",	"Poes_clothes",		"",    "JRH24",	14,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"Poes_urn",		"Poes_urn",		"",    "JRH24",	15,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"Poes_books",	"Poes_books",		"",    "JRH24",	16,	0,0,	"","",	"","",	"","",""); //

	n = InitQuestItem(n,"doc1A",		"doc1A",		"",    "JRH22",	12,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"doc1B",		"doc1B",		"",    "JRH23",	 4,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"doc2A",		"doc2A",		"",    "JRH23",	 9,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"doc2B",		"doc2B",		"",    "JRH23",	10,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"doc2C",		"doc2C",		"",    "JRH23",	 7,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"doc3C",		"doc3C",		"",    "JRH23",	 8,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"doc2D",		"doc2D",		"",    "JRH23",	11,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"doc3D",		"doc3D",		"",    "JRH23",	12,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"doc2E",		"doc2E",		"",    "JRH23",	16,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"doc4A",		"doc4A",	   "doc4A",    "JRH23",	 5,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"doc4B",		"doc4B",		"",    "JRH23",	 6,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"doc5A",		"doc5A",		"",    "JRH23",	 1,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"doc5B",		"doc5B",		"",    "JRH23",	 2,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"doc5C",		"doc5C",		"",    "JRH23",	 3,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"doc6A",		"doc6A",		"",    "JRH23",	13,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"doc6B",		"doc6B",		"",    "JRH23",	14,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"doc6C",		"doc6C",		"",    "JRH23",	15,	0,0,	"","",	"","",	"","",""); //

	n = InitQuestItem(n,"bagcompass4",	"bagcompass4",		"",    "JRH24",	12,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"glasses",		"glasses",		"",     "JRH3", 13,	0,0,	"","",	"","",	"","",""); //glasses
	n = InitQuestItem(n,"blue_uniform",	"blue_uniform",		"",     "JRH4", 15,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"G_journal",	"G_journal",		"",	     4,	8,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"G_letter1",	"G_letter1",		"",	     4,	9,	0,0,	"","",	"","",	"","","");	
	n = InitQuestItem(n,"G_letter2",	"G_letter2",		"",	     4,	3,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"G_letter3",	"G_letter3",		"",          4,	16,	0,0,	"","",	"","",	"","","");

	n = InitQuestItem(n,"sailbag",		"sailbag",		"",    "JRH24",	2,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"sergeants_note",	"sergeants_note",	"",    "JRH25",	16,	0,0,	"","",	"","",	"","",""); 
	n = InitQuestItem(n,"bone",		"bone",			"",      "CCC",	11,	0,0,	"","",	"","",	"","",""); 

	n = InitQuestItem(n,"mixed_treasure",	"mixed_treasure",	"",    "JRH28",	 9,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"emptysack",	"emptysack",		"",     "JRH3",	10,	0,0,	"","",	"","",	"","",""); //empty book sack, from WR
	n = InitQuestItem(n,"treasuresack",	"treasuresack",		"",    "JRH28",	10,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"poe_manuscript", "poe_manuscript", "bb_Map_piece","JRH27",  3,	0,0,	"","",	"","",	"","",""); //first version of the Gold Bug
	
	n = InitQuestItem(n,"icollection",	"incas_collection",	"",	     4,	 5,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"sword_handle1",	"sword_handle1",	"",    "JRH28",	11,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"sword_handle2",	"sword_handle2",	"",    "JRH28",	12,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"treasure1",	"treasure1",		"",    "JRH29",	 1,	0,0,	"","",	"","",	"","",""); //bowl
	n = InitQuestItem(n,"treasure2",	"treasure2",		"",    "JRH29",	 2,	0,0,	"","",	"","",	"","",""); //censer
	n = InitQuestItem(n,"treasure3",	"treasure3",		"",    "JRH29",	 3,	0,0,	"","",	"","",	"","",""); //opal
	n = InitQuestItem(n,"treasure4",	"treasure4",		"",    "JRH29",	 4,	0,0,	"","",	"","",	"","",""); //elephant
	n = InitQuestItem(n,"treasure5",	"treasure5",		"",    "JRH29",	 5,	0,0,	"","",	"","",	"","",""); //large ring
	n = InitQuestItem(n,"treasure6",	"treasure6",		"",    "JRH29",	 6,	0,0,	"","",	"","",	"","",""); //small ring
	n = InitQuestItem(n,"treasure7",	"treasure7",		"",    "JRH29",	 7,	0,0,	"","",	"","",	"","",""); //finger ring
	n = InitQuestItem(n,"treasure8",	"treasure8",		"",    "JRH29",	 8,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"treasure9",	"treasure9",		"",    "JRH29",	 9,	0,0,	"","",	"","",	"","",""); //large clock
	n = InitQuestItem(n,"treasure10",	"treasure10",		"",    "JRH29",	10,	0,0,	"","",	"","",	"","",""); //small clock
	n = InitQuestItem(n,"treasure11",	"treasure11",		"",    "JRH29",	11,	0,0,	"","",	"","",	"","",""); //clock with chain
	n = InitQuestItem(n,"treasure12",	"treasure12",		"",    "JRH29",	12,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"treasure13",	"treasure13",		"",    "JRH29",	13,	0,0,	"","",	"","",	"","",""); //large crucifix
	n = InitQuestItem(n,"treasure14",	"treasure14",		"",    "JRH29",	14,	0,0,	"","",	"","",	"","",""); //crucifix blue stone
	n = InitQuestItem(n,"treasure15",	"treasure15",		"",    "JRH29",	15,	0,0,	"","",	"","",	"","",""); //crucifix red srones
	n = InitQuestItem(n,"treasure16",	"treasure16",		"",    "JRH29",	16,	0,0,	"","",	"","",	"","",""); //


/*
	n = InitQuestItem(n,"key1",		"key1",			"",	"JRH7",	1,	0,0,	"","",	"","",	"","",""); //QC padlock key to upper chest
	n = InitQuestItem(n,"key2",		"key2",			"",	"JRH7",	2,	0,0,	"","",	"","",	"","",""); //QC padlock key to bottom chest	
	n = InitQuestItem(n,"key3",		"key3",			"",	"JRH7",	3,	0,0,	"","",	"","",	"","",""); //QC left big key to final chest
	n = InitQuestItem(n,"key4",		"key4",			"",	"JRH7",	4,	0,0,	"","",	"","",	"","",""); //QC right small key to final chest, & to cupboard
	n = InitQuestItem(n,"key5",		"key5",			"",	"JRH7",	5,	0,0,	"","",	"","",	"","",""); //found in clock, wr bedroom to kitchen
	n = InitQuestItem(n,"key6",		"key6",			"",	"JRH7",	6,	0,0,	"","",	"","",	"","",""); //found in LS, to shop from LS	
	n = InitQuestItem(n,"key7",		"key7",			"",	"JRH7",	7,	0,0,	"","",	"","",	"","",""); //storeroom backdoor key found in distillery
	n = InitQuestItem(n,"key8",		"key8",		"invisible",	"JRH7",	8,	0,0,	"","",	"","",	"","",""); //padlock key to counter in shop
	n = InitQuestItem(n,"key9",		"key9",			"",	"JRH7",	9,	0,0,	"","",	"","",	"","",""); //key collection to chests in shop
	n = InitQuestItem(n,"key10",		"key10",		"",	"JRH7",	10,	0,0,	"","",	"","",	"","",""); //small key to study chest	
	n = InitQuestItem(n,"key11",		"key11",		"",	"JRH7",	11,	0,0,	"","",	"","",	"","",""); //small key to surgkit (in the back of medchest)
	n = InitQuestItem(n,"key12",		"key12",	"chest2_vco",	"JRH7",	12,	0,0,	"","",	"","",	"","",""); //mine tunnel1
	n = InitQuestItem(n,"key13",		"key13",	"chest2_vco",	"JRH7",	13,	0,0,	"","",	"","",	"","",""); //mine tunnel2
	n = InitQuestItem(n,"key14",		"key14",	"chest2_vco",	"JRH7",	14,	0,0,	"","",	"","",	"","",""); //mine tunnel3	
	n = InitQuestItem(n,"key15",		"key15",		"",	"JRH7",	15,	0,0,	"","",	"","",	"","",""); //key collection to chests in food cellar
	n = InitQuestItem(n,"key16",		"key16",	"keymiddle",	"JRH7",	16,	0,0,	"","",	"","",	"","",""); //blue cavern chest key
	n = InitQuestItem(n,"key17",		"key17",		"",	"JRH11",5,	0,0,	"","",	"","",	"","",""); //key to counter in study
	n = InitQuestItem(n,"key18",		"key18",		"",	"JRH12",11,	0,0,	"","",	"","",	"","",""); //key in corridor	
	n = InitQuestItem(n,"key19",		"key19",	"keymiddle",	"JRH16",12,	0,0,	"","",	"","",	"","",""); //key to flag chest
	
	n = InitQuestItem(n,"dummy_belt",	"",		"dummy_belt",	    "", "",	0,0,	"","",	"","",	"","",""); //Blackbeardґs Belt (empty) on dummy

	n = InitQuestItem(n,"book21",		"book21",		"",	"JRH5",	1,	0,0,	"","",	"","",	"","",""); //law
	n = InitQuestItem(n,"book22",		"book22",		"",	"JRH5",	2,	0,0,	"","",	"","",	"","",""); //sea battles
	n = InitQuestItem(n,"book23",		"book23",		"",	"JRH5",	3,	0,0,	"","",	"","",	"","",""); //shipbuilding
	n = InitQuestItem(n,"book24",		"book24",		"",	"JRH5",	4,	0,0,	"","",	"","",	"","",""); //history
	n = InitQuestItem(n,"book25",		"book25",		"",	"JRH5",	5,	0,0,	"","",	"","",	"","",""); //Dampier's book defect
	n = InitQuestItem(n,"book26",		"book26",		"",	"JRH5",	6,	0,0,	"","",	"","",	"","",""); //medicine
	n = InitQuestItem(n,"book27",		"book27",		"",	"JRH5",	7,	0,0,	"","",	"","",	"","",""); //chemistry
	n = InitQuestItem(n,"book28",		"book28",		"",	"JRH5",	8,	0,0,	"","",	"","",	"","",""); //erotica
	n = InitQuestItem(n,"book29",		"book29",		"",	"JRH5",	9,	0,0,	"","",	"","",	"","",""); //poetry
	n = InitQuestItem(n,"book30",		"book30",		"",	"JRH5",	10,	0,0,	"","",	"","",	"","",""); //collection of poetry
	n = InitQuestItem(n,"book31",		"book31",		"",	"JRH5",	11,	0,0,	"","",	"","",	"","",""); //Dampier's book repaired
	
	n = InitQuestItem(n,"book33",		"book33",		"",	"JRH5",	13,	0,0,	"","",	"","",	"","",""); //geography
	n = InitQuestItem(n,"book34",		"book34",		"",	"JRH5",	14,	0,0,	"","",	"","",	"","",""); //trade
	n = InitQuestItem(n,"book35",		"book35",		"",	"JRH5",	15,	0,0,	"","",	"","",	"","",""); //mercury
	n = InitQuestItem(n,"book36",		"book36",		"",	"JRH5",	16,	0,0,	"","",	"","",	"","",""); //Poe: hidden treasure

	n = InitQuestItem(n,"book41",		"book41",		"",    "JRH12", 1,	0,0,	"","",	"","",	"","",""); //gunnery
	n = InitQuestItem(n,"book42",		"book42",    "scroll_long",    "JRH12", 2,	0,0,	"","",	"","",	"","",""); //alchemy: 3parted scroll
	n = InitQuestItem(n,"book43",		"book43",		"",    "JRH12", 3,	0,0,	"","",	"","",	"","",""); //alchemy: 3parted scroll
	n = InitQuestItem(n,"book44",		"book44",		"",    "JRH12", 4,	0,0,	"","",	"","",	"","",""); //alchemy: 3parted scroll
	n = InitQuestItem(n,"book45",		"book45",	  "book45",    "JRH12", 5,	0,0,	"","",	"","",	"","",""); //alchemy: 2 old notebooks
	n = InitQuestItem(n,"book46",		"book46",		"",    "JRH12", 6,	0,0,	"","",	"","",	"","",""); //alchemy: scroll corridor
	n = InitQuestItem(n,"book47",		"book47",   "bb_Map_piece",    "JRH12", 7,	0,0,	"","",	"","",	"","",""); //alchemy: worn parchment
	n = InitQuestItem(n,"book48",		"book48",		"",    "JRH12", 8,	0,0,	"","",	"","",	"","",""); //alchemy: book
	n = InitQuestItem(n,"book49",		"book49",	  "book49",    "JRH12", 9,	0,0,	"","",	"","",	"","",""); //alchemy: 2parted book
	n = InitQuestItem(n,"book50",		"book50",		"",    "JRH12", 10,	0,0,	"","",	"","",	"","",""); //alchemy: 2parted book
	n = InitQuestItem(n,"book51",		"book51",		"",    "JRH12", 14,	0,0,	"","",	"","",	"","",""); //alchemy: champagne to cognac

	n = InitQuestItem(n,"bible",		"bible",		"",     "JRH3", 16,	0,0,	"","",	"","",	"","",""); //selkirk bible

	n = InitQuestItem(n,"picture1",		"picture1",		"",	"JRH6",	1,	0,0,	"","",	"","",	"","",""); //town map
	n = InitQuestItem(n,"picture2",		"picture2",		"",	"JRH6",	2,	0,0,	"","",	"","",	"","",""); //Island map	
	n = InitQuestItem(n,"picture3",		"picture3",		"",	"JRH6",	3,	0,0,	"","",	"","",	"","",""); //America map
	n = InitQuestItem(n,"picture4",		"picture4",		"",	"JRH6",	4,	0,0,	"","",	"","",	"","",""); //Blackbeard fights
	n = InitQuestItem(n,"picture5",		"picture5",		"",	"JRH6",	5,	0,0,	"","",	"","",	"","",""); //document
	n = InitQuestItem(n,"picture6",		"picture6",		"",	"JRH6",	6,	0,0,	"","",	"","",	"","",""); //document ripped out	
	n = InitQuestItem(n,"picture7",		"picture7",		"",	"JRH6",	7,	0,0,	"","",	"","",	"","",""); //Dampier portrait
	n = InitQuestItem(n,"picture8",		"picture8",		"",	"JRH6",	8,	0,0,	"","",	"","",	"","",""); //Frans Hals portrait
	n = InitQuestItem(n,"picture9",		"picture9",		"",	"JRH6",	9,	0,0,	"","",	"","",	"","",""); //skeleton
	n = InitQuestItem(n,"picture10",	"picture10",		"",	"JRH6",	10,	0,0,	"","",	"","",	"","",""); //alchemist	
	n = InitQuestItem(n,"picture11",	"picture11",		"",	"JRH6",	11,	0,0,	"","",	"","",	"","",""); //astrology
	n = InitQuestItem(n,"picture13",	"picture13",		"",	"JRH6",	13,	0,0,	"","",	"","",	"","",""); //ship painting
	n = InitQuestItem(n,"picture14",	"picture14",		"",	"JRH6",	14,	0,0,	"","",	"","",	"","",""); //Uraniburg	
	n = InitQuestItem(n,"picture15",	"picture15",		"",	"JRH6",	15,	0,0,	"","",	"","",	"","",""); //Rogers painting

	n = InitQuestItem(n,"note1",		"note1",		"",	"JRH6",	12,	0,0,	"","",	"","",	"","",""); //note unreadable
	n = InitQuestItem(n,"note2",		"note2",		"",	"JRH6",	16,	0,0,	"","",	"","",	"","",""); //note readable	
	n = InitQuestItem(n,"note3",		"note3",		"",    "JRH10", 1,	0,0,	"","",	"","",	"","",""); //note in temple
	
	n = InitQuestItem(n,"amnesty_doc",	"amnesty_doc",		"",    "JRH10", 4,	0,0,	"","",	"","",	"","",""); //a 'Woodes Rogers'

	n = InitQuestItem(n,"chestmap1",	"",	       "chestmap1",	   "", "",	0,0,	"","",	"","",	"","",""); //in capsmall
	n = InitQuestItem(n,"excel_document",	"excel_document",	"",    "JRH10",	16,	0,0,	"","",	"","",	"","",""); //excel document	

	n = InitQuestItem(n,"mdchest",		"",	 	 "mdchest",	   "", "",	0,0,	"","",	"","",	"","",""); //fake medchest placed in shop
	n = InitQuestItem(n,"mdchest2",		"",	        "mdchest2",	   "", "",	0,0,	"","",	"","",	"","",""); //fake medchest placed in food supply (lying on one side)
	n = InitQuestItem(n,"mdchest2_exp",	"",	    "mdchest2_exp",	   "", "",	0,0,	"","",	"","",	"","",""); //fake medchest placed in food supply (lying on one side) burned by explosion

	n = InitQuestItem(n,"mdchest_B2",	"mdchest_B2",	 	"",	"JRH8", 8,	0,0,	"","",	"","",	"","",""); //back: empty
	n = InitQuestItem(n,"mdchest_B3",	"mdchest_B3",	 	"",	"JRH8", 12,	0,0,	"","",	"","",	"","",""); //back: filled
	n = InitQuestItem(n,"mdchest_B4",	"mdchest_B4",	 	"",	"JRH8", 16,	0,0,	"","",	"","",	"","",""); //back: filled + key

	n = InitQuestItem(n,"mdchest_rope",	"mdchest_rope",	        "",	"JRH3", 3,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"medicine_list",	"medicine_list",	"",	"JRH3", 4,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"medicine_leaves",	"medicine_leaves",	"",	"JRH9", 1,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"anti_scurvy_pills","anti_scurvy_pills",	"",	"JRH9", 9,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"filled_medium_drawer","filled_medium_drawer","",	"JRH9", 4,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"mortar_ointment",	"mortar_ointment",	"",	"JRH9", 5,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"cough_syrup",	"cough_syrup",	 	"",	"JRH9", 6,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"blood_letting",	"blood_letting",	"",	"JRH9", 7,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"filled_large_drawer","filled_large_drawer", "",	"JRH9", 8,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"empty_large_drawer","empty_large_drawer",  "",	"JRH9", 16,	0,0,	"","",	"","",	"","","");

	n = InitQuestItem(n,"bag_of_herbs",	"bag_of_herbs",	 	"",	"JRH3", 10,	0,0,	"","",	"","",	"","",""); //sack for herbs, also pistolmdsack & pistolmdclothsack
	n = InitQuestItem(n,"prescriptions",	"prescriptions",	"",	"JRH9", 14,	0,0,	"","",	"","",	"","",""); //prescriptions, see also bladeprescriptions
	n = InitQuestItem(n,"empty_bottles",	"empty_bottles",	"",	"JRH9", 2,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"mercury_bottles",	"mercury_bottles",	"",	"JRH9", 3,	0,0,	"","",	"","",	"","","");

	n = InitQuestItem(n,"surgery_kit",	"",	     "surgery_kit",	   "", "",	0,0,	"","",	"","",	"","",""); //as an item in shop
	n = InitQuestItem(n,"surgery_saw",	"surgery_saw",	 	"",	"JRH9", 13,	0,0,	"","",	"","",	"","",""); //as an item, NEEDED???

	n = InitQuestItem(n,"foodchest",	"",   	       "foodchest",	   "", "",	0,0,	"","",	"","",	"","",""); //as an item in food supply
	n = InitQuestItem(n,"bigfish",		"",	         "bigfish",	   "", "",	0,0,	"","",	"","",	"","",""); //as an item at church	
	n = InitQuestItem(n,"meat",		"meat",			"",	"JRH4",	9,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"2winebottles",	"2winebottles",		"",	"JRH4",	11,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"bread",		"bread",		"",	"JRH4",	13,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"ale",		"ale",	      "barrel_ale",	"JRH4",	14,	0,0,	"","",	"","",	"","",""); //ale: used as pickup item (no vis model)	

	n = InitQuestItem(n,"lockpick_JRH",	"",	    "lockpick_JRH",         "", "",	0,0,	"","",	"","",	"","",""); //used as visible item in church_choir, switched to bladelockpick when p.u.	
	n = InitQuestItem(n,"red_animist",	"red_animist",		"",    "JRH14",	6,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"many_red_animists","many_red_animists",	"",    "JRH14",	7,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"pack_of_red_cloth","pack_of_red_cloth","red_cloth","JRH14",8,	0,0,	"","",	"","",	"","","");

	n = InitQuestItem(n,"package",		"package",		"",    "JRH11",	13,	0,0,	"","",	"","",	"","","");	
	n = InitQuestItem(n,"temp_purse",	"temp_purse",		"",          4,	2,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"temp_coins",	"temp_coins",		"",    "JRH11",	9,	0,0,	"","",	"","",	"","","");

	n = InitQuestItem(n,"megaphone",	"",	       "megaphone",        "", "",	0,0,	"","",	"","",	"","",""); //randitem megaphone
	n = InitQuestItem(n,"boathook",		"",	        "boathook",        "", "",	0,0,	"","",	"","",	"","",""); //randitem boathook
	n = InitQuestItem(n,"spyglass5",	"",	       "spyglass5",        "", "",	0,0,	"","",	"","",	"","",""); //randitem spyglass5

	n = InitQuestItem(n,"cannonballs",	"cannonballs",		"",     "JRH3",	1,	0,0,	"","",	"","",	"","",""); //cannonballs for pickup

	n = InitQuestItem(n,"glasses",		"glasses",		"",     "JRH3", 13,	0,0,	"","",	"","",	"","",""); //glasses
	n = InitQuestItem(n,"chain",		"chain",		"",     "JRH3",	9,	0,0,	"","",	"","",	"","",""); //chain & handcuffs	
	n = InitQuestItem(n,"corkscrews",	"corkscrews",		"",     "JRH3",	12,	0,0,	"","",	"","",	"","",""); //corkscrews as lockpick tools
	n = InitQuestItem(n,"emptysack",	"emptysack",		"",     "JRH3",	10,	0,0,	"","",	"","",	"","",""); //empty book sack
	n = InitQuestItem(n,"glue",		"glue",			"",     "JRH3",	15,	0,0,	"","",	"","",	"","",""); //glue

	n = InitQuestItem(n,"blue_uniform",	"blue_uniform",		"",     "JRH4", 15,	0,0,	"","",	"","",	"","",""); //found in prison cell
	n = InitQuestItem(n,"elevator_ropes",	"elevator_ropes","invisible",  "JRH10",	9,	0,0,	"","",	"","",	"","",""); //found at anchor wr_ships
	n = InitQuestItem(n,"raft_ropes",	"raft_ropes", "raft_ropes",    "JRH10",	9,	0,0,	"","",	"","",	"","",""); //found on mast swamp_wreck
	n = InitQuestItem(n,"lever",		"lever",		"",    "JRH10",	10,	0,0,	"","",	"","",	"","",""); //study

	n = InitQuestItem(n,"mtoon_item",	"",	       "musketoon",          8,	9,	0,0,	"","",	"","",	"","",""); //QC_store
*/



























	QUESTITEMS_QUANTITY = n;
}
