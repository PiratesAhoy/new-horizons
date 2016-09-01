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
	n = InitQuestItem(n,"key16",		"key16",	"keymiddle",	"JRH7",	16,	0,0,	"","",	"","",	"","",""); //Eden tunnel
	n = InitQuestItem(n,"key17",		"key17",		"",	"JRH11",5,	0,0,	"","",	"","",	"","",""); //key to counter in study
	n = InitQuestItem(n,"key18",		"key18",		"",	"JRH12",11,	0,0,	"","",	"","",	"","",""); //key in corridor	
	n = InitQuestItem(n,"key19",		"key19",	"keymiddle",	"JRH16",12,	0,0,	"","",	"","",	"","",""); //key to flag chest
	
	n = InitQuestItem(n,"dummy_belt",	"",		"dummy_belt",	    "", "",	0,0,	"","",	"","",	"","",""); //Blackbeard´s Belt (empty) on dummy

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
//	n = InitQuestItem(n,"lever",		"lever",		"",    "JRH10",	10,	0,0,	"","",	"","",	"","",""); //study, replaced by bladelever InitItems

	n = InitQuestItem(n,"mtoon_item",	"",	       "musketoon",          8,	9,	0,0,	"","",	"","",	"","",""); //QC_store
//Q2
	n = InitQuestItem(n,"mdchest_broken",	"",	  "mdchest_broken",	    "", "",	0,0,	"","",	"","",	"","",""); //alcove
	n = InitQuestItem(n,"key33",		"key33",  	"keygrand",	"JRH5", 12,	0,0,	"","",	"","",	"","",""); //monastary crypt
	n = InitQuestItem(n,"wax_candles",	"wax_candles",		"",    "JRH26",	 9,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"altar_bread",	"altar_bread",		"",    "JRH26",	10,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"book62",		"book62",	   "bookB",         13, 16,	0,0,	"","",	"","",	"","",""); //exorcist book
	n = InitQuestItem(n,"treasure7",	"treasure7",		"",    "JRH29",	 7,	0,0,	"","",	"","",	"","",""); //finger ring
	n = InitQuestItem(n,"silvercross",	"silvercross",		"",          1,	 9,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"rosary",		"rosary",		"",    "JRH12",	15,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"icon",		"icon",			"",    "JRH12",	16,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"crypt_sketch",	"crypt_sketch",		"",     "JRH8",	 4,	0,0,	"","",	"","",	"","","");
        n = InitQuestItem(n,"corkscrew",	"corkscrew",            "",    "JRH24",	 6,	0,0,	"","",	"","",	"","","");


	QUESTITEMS_QUANTITY = n;
}
