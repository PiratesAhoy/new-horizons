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
	n = InitQuestItem(n,"key12",		"key12",	"chest2_vco",	"JRH7",	12,	0,0,	"","",	"","",	"","",""); //mine tunnel2
	n = InitQuestItem(n,"key13",		"key13",	"chest2_vco",	"JRH7",	13,	0,0,	"","",	"","",	"","",""); //mine tunnel3
	n = InitQuestItem(n,"key14",		"key14",	"chest2_vco",	"JRH7",	14,	0,0,	"","",	"","",	"","",""); //mine tunnel1	
	n = InitQuestItem(n,"key15",		"key15",		"",	"JRH7",	15,	0,0,	"","",	"","",	"","",""); //key collection to chests in food cellar
	n = InitQuestItem(n,"key16",		"key16",	"keymiddle",	"JRH7",	16,	0,0,	"","",	"","",	"","",""); //Eden tunnel
	n = InitQuestItem(n,"key17",		"key17",		"",	"JRH11",5,	0,0,	"","",	"","",	"","",""); //key to counter in study & counter in farm bedroom
	n = InitQuestItem(n,"key18",		"key18",		"",	"JRH12",11,	0,0,	"","",	"","",	"","",""); //key in corridor	
	n = InitQuestItem(n,"key19",		"key19",	"keymiddle",	"JRH16",12,	0,0,	"","",	"","",	"","",""); //key to flag chest
	n = InitQuestItem(n,"key30",		"key30",        "keymiddle",    "JRH17",15,	0,0,	"","",	"","",	"","",""); //to tunnel from Citadel Rock also used in GoldBug to Maroon Cave
	n = InitQuestItem(n,"key35",		"key35",		"",	"JRH7",	7,	0,0,	"","",	"","",	"","",""); //Kristiania oriel room
	n = InitQuestItem(n,"key36",		"key36",		"",	"JRH30",16,	0,0,	"","",	"","",	"","",""); //farm key quest2
	n = InitQuestItem(n,"key37",		"key37",		"",	"JRH37",6,	0,0,	"","",	"","",	"","",""); //not used yet
	n = InitQuestItem(n,"key39",		"key39",	"keymiddle",	"JRH38",7,	0,0,	"","",	"","",	"","",""); //careen corvette convicts

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
	n = InitQuestItem(n,"picture8_A",	"picture8_A",		"",	"JRH6",	8,	0,0,	"","",	"","",	"","",""); //Frans Hals painting cut out
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

	n = InitQuestItem(n,"red_uniform",	"red_uniform",		"",    "JRH11",	6,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"package",		"package",		"",    "JRH11",	13,	0,0,	"","",	"","",	"","","");	
	n = InitQuestItem(n,"notebook",		"notebook",		"",    "JRH11",	14,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"sealed_map",	"sealed_map",		"",    "JRH11",	15,	0,0,	"","",	"","",	"","","");

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
	n = InitQuestItem(n,"mket_item",	"",	       "musket",             8,	10,	0,0,	"","",	"","",	"","",""); //careen shore
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
	n = InitQuestItem(n,"tape",		"tape",			"",    "JRH11",	16,	0,0,	"","",	"","",	"","",""); //first aid plaster tape and 2 bandages
//	n = InitQuestItem(n,"crypt_sketch",	"crypt_sketch",		"",     "JRH8",	 4,	0,0,	"","",	"","",	"","",""); //replaced by backside of mapBB4A
        n = InitQuestItem(n,"corkscrew",	"corkscrew",            "",    "JRH24",	 6,	0,0,	"","",	"","",	"","","");
	
	n = InitQuestItem(n,"key34",		"key34",		"",    "JRH31", 15,	0,0,	"","",	"","",	"","",""); //Maltese key
	n = InitQuestItem(n,"book63",		"book63",	  "book63",    "JRH31",  1,	0,0,	"","",	"","",	"","",""); //Maltese medicine
        n = InitQuestItem(n,"book64",		"book64",	        "",    "JRH31",  2,	0,0,	"","",	"","",	"","",""); //Maltese french
	n = InitQuestItem(n,"book65",		"book65",	        "",    "JRH31",  3,	0,0,	"","",	"","",	"","",""); //Maltese bible
        n = InitQuestItem(n,"book66",		"book66",	        "",    "JRH31",  4,	0,0,	"","",	"","",	"","",""); //Maltese pile of sheets
	n = InitQuestItem(n,"book67",		"book67",     "document67",    "JRH31",  5,	0,0,	"","",	"","",	"","",""); //Maltese official document
	n = InitQuestItem(n,"book68",		"book68",    "scroll_long",    "JRH31",  6,	0,0,	"","",	"","",	"","",""); //Maltese scroll
	n = InitQuestItem(n,"Malta_icon",	"Malta_icon",	        "",    "JRH31",  7,	0,0,	"","",	"","",	"","",""); //Maltese icon
	n = InitQuestItem(n,"Malta_outfit",	"Malta_outfit",	        "",    "JRH31",  8,	0,0,	"","",	"","",	"","",""); //Maltese outfit
	n = InitQuestItem(n,"Malta_poison",	"Malta_poison",	        "",    "JRH31",  9,	0,0,	"","",	"","",	"","",""); //Maltese poison
	n = InitQuestItem(n,"Malta_syringe",	"Malta_syringe",	"",    "JRH31", 10,	0,0,	"","",	"","",	"","",""); //Maltese syringe bandage
	n = InitQuestItem(n,"Malta_medkit",	"Malta_medkit",	        "",    "JRH31", 11,	0,0,	"","",	"","",	"","",""); //Maltese medicine kit
	n = InitQuestItem(n,"Malta_statue",	"Malta_statue",	        "",    "JRH31", 12,	0,0,	"","",	"","",	"","",""); //Maltese statuette
	n = InitQuestItem(n,"Malta_box",	"Malta_box",	        "",    "JRH31", 13,	0,0,	"","",	"","",	"","",""); //Maltese shrine
	n = InitQuestItem(n,"Malta_relic",	"Malta_relic",	        "",    "JRH29",  7,	0,0,	"","",	"","",	"","",""); //Maltese relic
	n = InitQuestItem(n,"Malta_cross",	"Malta_cross",	        "",    "JRH29", 13,	0,0,	"","",	"","",	"","",""); //Maltese crucifix
	n = InitQuestItem(n,"Malta_censer",	"Malta_censer",	        "",    "JRH29",  2,	0,0,	"","",	"","",	"","",""); //Maltese censer

	n = InitQuestItem(n,"switch_button",	"switch_button",	"",    "JRH33",  3,	0,0,	"","",	"","",	"","",""); //
	
	n = InitQuestItem(n,"doc60A",		"doc60A",		"",    "JRH23",	13,	0,0,	"","",	"","",	"","",""); //Letter from Tobias Knight
	n = InitQuestItem(n,"doc60B",		"doc60B",		"",    "JRH23",	14,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"doc60C",		"doc60C",		"",    "JRH23",	15,	0,0,	"","",	"","",	"","",""); //
        n = InitQuestItem(n,"doc60D",		"doc60D",		"",    "JRH33",	 4,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"book69A",		"book69A",    		"",    "JRH33",  5,	0,0,	"","",	"","",	"","",""); //Teach's logbook
	n = InitQuestItem(n,"book69B",		"book69B",    		"",    "JRH33",  6,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"book69C",		"book69C",    		"",    "JRH33",  7,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"BB_hatA1",		"BB_hatA1",    		"",    "JRH33",  9,	0,0,	"","",	"","",	"","",""); //Teach's hat start
	n = InitQuestItem(n,"BB_hatB",		"BB_hatB",    		"",    "JRH33", 10,	0,0,	"","",	"","",	"","",""); //Teach's hat inside
        n = InitQuestItem(n,"BB_hatC",		"BB_hatC",    		"",    "JRH33", 11,	0,0,	"","",	"","",	"","",""); //Teach's hat inside key
	n = InitQuestItem(n,"BB_key",	        "BB_key",    		"",    "JRH33", 12,	0,0,	"","",	"","",	"","",""); //Teach's key
	n = InitQuestItem(n,"BB_hatA2",		"BB_hatA2",    		"",    "JRH33",  9,	0,0,	"","",	"","",	"","",""); //Teach's hat equip
	n = InitQuestItem(n,"BB_coin",		"BB_coin",    		"",    "JRH32", 16,	0,0,	"","",	"","",	"","",""); //Teach's amulet
	n = InitQuestItem(n,"paper_clip",	"paper_clip",    	"",    "JRH33", 13,	0,0,	"","",	"","",	"","",""); //start
	n = InitQuestItem(n,"paper_clip2",	"paper_clip2",    	"",    "JRH33", 14,	0,0,	"","",	"","",	"","",""); //hook
	n = InitQuestItem(n,"auction_list_roll","auction_list_roll","scroll_long", "JRH31", 6,	0,0,	"","",	"","",	"","",""); //auction list
	n = InitQuestItem(n,"auction_list_open","auction_list_open",	"",    "JRH33",  8,	0,0,	"","",	"","",	"","",""); //auction list
	n = InitQuestItem(n,"tailors_book",	"tailors_book",		"",    "JRH33", 15,	0,0,	"","",	"","",	"","",""); //
	n = InitQuestItem(n,"tailors_note",	"tailors_note",		"",    "JRH33", 16,	0,0,	"","",	"","",	"","",""); //

	n = InitQuestItem(n,"book70_start",	"book70_start",    	"",    "JRH34", 13,	0,0,	"","",	"","",	"","",""); //burned alchemy book
	n = InitQuestItem(n,"book70",		"book70",    		"",    "JRH34", 13,	0,0,	"","",	"","",	"","",""); //burned alchemy book
	n = InitQuestItem(n,"book70_0",		"book70_0",    		"",    "JRH34",  9,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"book70_1",		"book70_1",    		"",    "JRH34", 10,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"book70_2",		"book70_2",    		"",    "JRH34",  1,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"book70_3",		"book70_3",    		"",    "JRH34",  2,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"book70_4",		"book70_4",    		"",    "JRH34",  3,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"book70_5",		"book70_5",    		"",    "JRH34",  4,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"book70_6",		"book70_6",    		"",    "JRH34",  5,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"book70_7",		"book70_7",    		"",    "JRH34",  6,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"book70_8",		"book70_8",    		"",    "JRH34",  7,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"book70_9",		"book70_9",    		"",    "JRH34",  8,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"book70_10",	"book70_10",    	"",    "JRH34", 11,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"book70_11",	"book70_11",    	"",    "JRH34", 12,	0,0,	"","",	"","",	"","","");

	n = InitQuestItem(n,"book71_9_start",	"book71_9_start", "book71",    "JRH35", 15,	0,0,	"","",	"","",	"","",""); //ripped alchemy book
	n = InitQuestItem(n,"book71_9",		"book71_9",    		"",    "JRH35", 15,	0,0,	"","",	"","",	"","",""); //ripped alchemy book
	n = InitQuestItem(n,"book71_10",	"book71_10",    	"",    "JRH35",  1,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"book71_11",	"book71_11",    	"",    "JRH35",  2,	0,0,	"","",	"","",	"","","");	
	n = InitQuestItem(n,"book71_12",	"book71_12",    	"",    "JRH35",  3,	0,0,	"","",	"","",	"","","");	
	n = InitQuestItem(n,"book71_13",	"book71_13",    	"",    "JRH35",  4,	0,0,	"","",	"","",	"","","");	
	n = InitQuestItem(n,"book71_14",	"book71_14",    	"",    "JRH35",  5,	0,0,	"","",	"","",	"","","");	
	n = InitQuestItem(n,"book71_15",	"book71_15",    	"",    "JRH35",  6,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"book71_16",	"book71_16",    	"",    "JRH35",  7,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"book71_17",	"book71_17",    	"",    "JRH35",  8,	0,0,	"","",	"","",	"","","");	
	n = InitQuestItem(n,"book71_18",	"book71_18",    	"",    "JRH35",  9,	0,0,	"","",	"","",	"","","");	
	n = InitQuestItem(n,"book71_19",	"book71_19",    	"",    "JRH35", 10,	0,0,	"","",	"","",	"","","");	
	n = InitQuestItem(n,"book71_20",	"book71_20",    	"",    "JRH35", 11,	0,0,	"","",	"","",	"","","");	
	n = InitQuestItem(n,"book71_21",	"book71_21",    	"",    "JRH35", 12,	0,0,	"","",	"","",	"","","");			
	n = InitQuestItem(n,"book71_22",	"book71_22",    	"",    "JRH35", 13,	0,0,	"","",	"","",	"","","");	
	n = InitQuestItem(n,"book71_23",	"book71_23",    	"",    "JRH35", 14,	0,0,	"","",	"","",	"","","");			
	
	n = InitQuestItem(n,"book72_package",	"book72_package",    	"",    "JRH36", 14,	0,0,	"","",	"","",	"","",""); //History of Pirates
	n = InitQuestItem(n,"book72_closed",	"book72_closed",    	"",    "JRH36", 13,	0,0,	"","",	"","",	"","",""); 
	n = InitQuestItem(n,"book72_openL",	"book72_openL",    	"",    "JRH36",  1,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"book72_openR",	"book72_openR",    	"",    "JRH36",  2,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"book72_edenL",	"book72_edenL",    	"",    "JRH36",  3,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"book72_edenR",	"book72_edenR",    	"",    "JRH36",  4,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"book72_caesarL",	"book72_caesarL",    	"",    "JRH36",  5,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"book72_caesarR",	"book72_caesarR",    	"",    "JRH36",  6,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"book72_handsL",	"book72_handsL",    	"",    "JRH36",  7,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"book72_handsR",	"book72_handsR",    	"",    "JRH36",  8,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"book72_richardsL",	"book72_richardsL",    	"",    "JRH36",  9,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"book72_richardsR",	"book72_richardsR",    	"",    "JRH36", 10,	0,0,	"","",	"","",	"","","");

	n = InitQuestItem(n,"newspaper1",	"newspaper1",    	"",    "JRH34", 14,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"newspaper2",	"newspaper2",    	"",    "JRH34", 15,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"newspaper3",	"newspaper3",    	"",    "JRH34", 16,	0,0,	"","",	"","",	"","","");

	n = InitQuestItem(n,"bandages_trousersX","bandages_trousersX",  "",    "JRH37",  1,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"bandages_trousersQ","bandages_trousersQ",  "",    "JRH37",  1,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"shirt_shoes",      "shirt_shoes",    	"",    "JRH37",  2,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"socks_sewing",     "socks_sewing",    	"",    "JRH37",  3,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"waistcoat",        "waistcoat",    	"",    "JRH37",  4,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"sash",        	"sash",    		"",    "JRH37",  5,	0,0,	"","",	"","",	"","","");

	n = InitQuestItem(n,"gpmap",        	"",    		   "gpmap",         "", "",	0,0,	"","",	"","",	"","","");	//temp map piece hidden in gp-store
	n = InitQuestItem(n,"doc61",		"doc61",		"",    "JRH37",	 8,	0,0,	"","",	"","",	"","",""); 	//from gov Stapleton
	n = InitQuestItem(n,"Pell_outfit",	"Pell_outfit",		"",    "JRH37",	 9,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"key38",		"key38",  	 	"",    "JRH37", 10,	0,0,	"","",	"","",	"","",""); 	//prison2 keys

	n = InitQuestItem(n,"idol",		"incas_idol",	   "stat1",	4,	 4,	0,0,	"","",	"","",	"","","");	//burning cave item
	n = InitQuestItem(n,"icollection",	"incas_collection",     "",	4,	 5,	0,0,	"","",	"","",	"","","");	//burning cave item
	n = InitQuestItem(n,"contract1",	"contract1",		"",    "JRH30",	15,	0,0,	"","",	"","",	"","",""); 	//burning cave item
	n = InitQuestItem(n,"contract2",	"contract2",		"",    "JRH31",	16,	0,0,	"","",	"","",	"","",""); 	//burning cave item
	n = InitQuestItem(n,"contract3",	"contract3",		"",    "JRH35",	16,	0,0,	"","",	"","",	"","",""); 	//burning cave item
	n = InitQuestItem(n,"book73_closed",	"book73_closed",  "book73",    "JRH38",	 1,	0,0,	"","",	"","",	"","",""); 	//Fibonacci
	n = InitQuestItem(n,"book73_open",	"book73_open",		"",    "JRH38",	 2,	0,0,	"","",	"","",	"","",""); 	//Fibonacci

	n = InitQuestItem(n,"long_johns",	"long_johns",		"",    "JRH38",	 3,	0,0,	"","",	"","",	"","",""); 	//
	n = InitQuestItem(n,"long_johns_map",	"long_johns_map",	"",    "JRH38",	 4,	0,0,	"","",	"","",	"","",""); 	//
	n = InitQuestItem(n,"bandana",		"bandana",		"",    "JRH38",	 5,	0,0,	"","",	"","",	"","",""); 	//
	n = InitQuestItem(n,"bandana_key",	"bandana_key",		"",    "JRH38",	 6,	0,0,	"","",	"","",	"","",""); 	//

	n = InitQuestItem(n,"LOM_swe",		"LOM_swe",		"",    "JRH38",	 11,	0,0,	"","",	"","",	"","",""); 	//swedish Letter of Marque
	n = InitQuestItem(n,"letter_cartagena",	"letter_cartagena",	"",    "JRH38",	 12,	0,0,	"","",	"","",	"","","");
	n = InitQuestItem(n,"letter_turks",	"letter_turks",		"",    "JRH38",	 12,	0,0,	"","",	"","",	"","","");




	QUESTITEMS_QUANTITY = n;
}
