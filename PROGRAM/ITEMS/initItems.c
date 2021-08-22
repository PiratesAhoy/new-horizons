// The code in this file has been cleaned up. A lot of code, which was disabled
// for several build patch levela, was removed. Also some comments have been
// removed to keep the code readable. To keep credit where credit is due, please
// leave this note. The following modders have done a good job on improving item
// diversity and usability (abbreviations as in code): KK, NK, KevAtl, PB, JRH,
// scheffnow, SuperDurnius, BB (and others, but I kept all their comments)
// 2011-08-31 Sulan

extern void InitQuestItems(); // KK

object StoredItems;

void InitItems()  // economics adjusted by BB & Sulan 2011-08
{
  InitButtons();
  ref itm;
  int n,i;

  for(n=0; n<MAX_ITEMS; n++) // NK
  {
    makeref(itm,Items[n]);
	if(CheckAttribute(itm,"persistent")) StoreItem(itm);
    DeleteAttribute(&itm, "");
    itm.id = "blank";
    itm.index = n; // NK
    itm.numrand = 1;
    itm.skiptrade = true;
    itm.skiptype = false; // skip auto assign of itm.type.(itm.groupID) = true. 05-04-07
    itm.skipsell = false; // 05-04-06 so traders can buy items but not sell them.
    itm.skiprand = true;
    itm.skipequip = true;
    itm.skipgeneral = false; // 05-04-01 NK itemtrade
    itm.minlevel = 1; // fudgefix for trading
    itm.quality = -1; // NK 05-04-03 itemtrade assign quality. -1 means auto-assign based on price.
    itm.describe = "";
    itm.model = "";
    itm.shown = false;
    itm.startLocation = "";
    itm.startLocator = "";
    itm.useLocation = "";
    itm.useLocator = "";
    itm.describe = "";
  }

  // KK -->
  QUESTITEMS_QUANTITY = InitQuestItem(0, "gold",    "gold",   "",     4,  2,    0,0,  "","",  "","",    "","",""  );
  if (FindFile("PROGRAM\" + GetStorylinePath(FindCurrentStoryline()) + "ITEMS", "*.c", "initQuestItems.c") != "") {
    if (LoadSegment(GetStorylinePath(FindCurrentStoryline()) + "ITEMS\initQuestItems.c")) {
      initQuestItems();
      UnloadSegment(GetStorylinePath(FindCurrentStoryline()) + "ITEMS\initQuestItems.c");
    }
  }
  n = QUESTITEMS_QUANTITY;

  //--------------------------------------------------------------------------------------------------------------------------------------------------
  // QUEST ITEMS
  //------------------------------------------------------------------------------------O---------QUEST SETTINGS---------------------------O------
  // QUEST ITEMS: ItmIndex                                                   picIndex   |            startLocation , startLocator          |
  //			    | itmID                                     modelID           |     | setshown   |      useLocation , useLocator       |
  //			    |  |                txtname                    |  picTexture  |     | | shownval |      |           quest , tex , pic  |
  //----------------|--|-------------------|-----------------------|----------|---|-----O-|-|--------|------|-----------|------------------O------
  n = InitQuestItem(n,"aztec_compass",	"aztec_compass",		"",	 "PETROS",	 1,		0,0,	"","",	"","",		"","",""	);
  n = InitQuestItem(n,"pornushka",		"love_letters_of_priest","",		4,	16,		0,0,	"","",	"","",		"","",""	);
  n = InitQuestItem(n,"letter_to_domingues","letter_to_domingues","",		4,	11,		0,0,	"","",	"","",		"","",""	);
  n = InitQuestItem(n,"letter_to_bernard","letter_to_bernard",	"",			4,	11,		0,0,	"","",	"","",		"","",""	);
  n = InitQuestItem(n,"letter_prison",	"prison_letter",		"",			4,	10,		0,0,	"","",	"","",		"","",""	);
  //Levis & JRH: Apothecary quest:
  n = InitQuestItem(n,"hotel_flyer",	"hotel_flyer",			"",			4,	14,		0,0,	"","",	"","",		"","",""	);
  n = InitQuestItem(n,"package_steven",	"package_steven",	    "",	   "ccc",    2,	    0,0,	"","",	"","",		"","",""	);
  n = InitQuestItem(n,"hotel_crucifix",	"hotel_crucifix",	    "",        1,    9,	    0,0,	"","",	"","",		"","",""	);
  n = InitQuestItem(n,"hotel_bible",	"hotel_bible",	  	    "",       13,   16,	    0,0,	"","",	"","",		"","",""	);
  n = InitQuestItem(n,"hotel_sextant",	"hotel_sextant",	    "",       11,    9,	    0,0,	"","",	"","",		"","",""	);
  n = InitQuestItem(n,"hotel_drawing",	"hotel_drawing",	    "",  "JRH11",   12,	    0,0,	"","",	"","",		"","",""	);
  n = InitQuestItem(n,"hotel_megaphone","hotel_megaphone",	    "",  "JRH16",    9,	    0,0,	"","",	"","",		"","",""	);
  n = InitQuestItem(n,"hotel_spyglass", "hotel_spyglass",	    "",  "JRH24",   10,	    0,0,	"","",	"","",		"","",""	);
  n = InitQuestItem(n,"hotel_whistle",  "hotel_whistle",	    "",  "JRH16",   10,	    0,0,	"","",	"","",		"","",""	);
  n = InitQuestItem(n,"hotel_grappling","hotel_grappling",	    "",       24,    6,	    0,0,	"","",	"","",		"","",""	);
  n = InitQuestItem(n,"hotel_surgery",  "hotel_surgery",	    "",   "JRH9",    10,    0,0,	"","",	"","",		"","",""	);
  n = InitQuestItem(n,"hotel_bandages", "hotel_bandages",	    "",   "JRH9",    15,    0,0,	"","",	"","",		"","",""	);
  n = InitQuestItem(n,"hotel_keys",     "hotel_keys",	        "",  "JRH18",   11,     0,0,	"","",	"","",		"","",""	);
  n = InitQuestItem(n,"chair_45",       "chair_45",	    "chair_45",  "LEVIS",    5,     0,0,	"","",	"","",		"","",""	);
  // --> added by CatalinaThePirate
  n = InitQuestItem(n,"animists_amulet",	"ANIMISTS_amulet",	"",			4,	12,		0,0,	"","",	"","",		"","",""	);
  n = InitQuestItem(n,"Letter_Reward",	"letter_reward",		"",			4,	11,		0,0,	"","",	"","",		"","",""	);
  n = InitQuestItem(n,"estrella_token",	"estrella_token",		"",			8,	13,		0,0,	"","",	"","",		"","",""	);
  // <-- added by CatalinaThePirate
  n = InitQuestItem(n,"old_journal",	"old_journal",			"",			4,	 8,		0,0,	"","",	"","",		"","",""	);
  n = InitQuestItem(n,"old_journal2",	"old_journal2",			"",			4,	 8,		0,0,	"","",	"","",		"","",""	);
  n = InitQuestItem(n,"small_chest",	"small_chest",			"",			4,	 1,		0,0,	"","",	"","",		"","",""	);
  n = InitQuestItem(n,"SpanishLetter",	"SpanishLetter",		"",	 		4,  14,		0,0,	"","",	"","",		"","",""	);
  n = InitQuestItem(n,"EITC_Passport",	"EITC_Passport",		"",			4,	13,		0,0,	"","",	"","",		"","",""	); // PB: For Cutler Beckett
  n = InitQuestItem(n,"Trade_PassportE","Trade_PassportE",		"",			4,	13,		0,0,	"","",	"","",		"","",""	); // PB: For player types
  n = InitQuestItem(n,"Trade_PassportF","Trade_PassportF",		"",			4,	13,		0,0,	"","",	"","",		"","",""	); // PB: For player types
  n = InitQuestItem(n,"Trade_PassportS","Trade_PassportS",		"",			4,	13,		0,0,	"","",	"","",		"","",""	); // PB: For player types
  n = InitQuestItem(n,"Trade_PassportH","Trade_PassportH",		"",			4,	13,		0,0,	"","",	"","",		"","",""	); // PB: For player types
  n = InitQuestItem(n,"Trade_PassportP","Trade_PassportP",		"",			4,	13,		0,0,	"","",	"","",		"","",""	); // PB: For player types
  n = InitQuestItem(n,"Trade_Passport",	"Trade_Passport",		"",			4,	13,		0,0,	"","",	"","",		"","",""	); // PB: For player types
  n = InitQuestItem(n,"Davy_Chest",	"Davy_Chest",			"",		 	"AS",	 8,		0,0,	"","",	"","",		"","",""	); // PB: Davy Jones
  n = InitQuestItem(n,"Devil_Contract",	"Devil_Contract",		"",			4,	3,		0,0,	"","",	"","",		"","",""	); // PB: For Ricardo Orellana
  n = InitQuestItem(n,"Correspondence1","Correspondence1",		"",	 		4,	14,		0,0,	"","",	"","",		"","",""	); //PW letter1 for arnaud/sabine matton sidequest
  n = InitQuestItem(n,"Correspondence2","Correspondence2",		"",	 		4,	14,		0,0,	"","",	"","",		"","",""	); //PW letter2 for arnaud/sabine matton sidequest
  n = InitQuestItem(n,"cryskull",	"cryskull",		 	"cryskul",  		12,	8,		0,0,	"","",	"","",		"","",""	); // GR: amber skull for "Crystal Skull" sidequest
  QUESTITEMS_QUANTITY = n;
  // <-- KK

// --> added by JRH for Woodes Rogers Quest
if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0 || sti(GetStorylineVar(FindCurrentStoryline(), "BUG_PUZZLES")) > 0
|| sti(GetStorylineVar(FindCurrentStoryline(), "BART_PUZZLES")) > 0)
{

  //--------------------------------------------------------------------------------------------------------------------------------------------------
  // QUEST BLADES:              	  	                    			     			  Price
  //          ItemIndex              	       	            picTexture     minDamage       Piercing	   Nation  |
  //		     |   bladeID           	        modelID       |  picIndex |  maxDamage | Blocking  | Disarm|
  //-----------------|------|-------------------------------|---------|------|----|----|-------|---|-------|--|----|--------------------------
  n = InitQuestBlade(n, "bladep0", 	                "bladep0", "JRH14", 16,   5,   5,     15,  0, 	  "", 0,   0);    //fake pocket pistol (right hand)
  n = InitQuestBlade(n, "bladep2", 	                "bladep2", 	"", "",  "", "",      "", "", 	  "", 0,   0);    //fake long pistol (right hand)
  n = InitQuestBlade(n, "bladep6", 	                "bladep6", 	"", "",   5,   7,      5,  5, 	  "", 0,   0);    //fake duelbarrel pistol (right hand)
  n = InitQuestBlade(n, "bladep202",	              "bladep202", 	"", "",  "", "",      "", "", 	  "", 0,   0);    //fake Teach pistol (right hand)
  n = InitQuestBlade(n, "bladep203", 	              "bladep203", 	"", "",  "", "",      "", "", 	  "", 0,   0);    //fake Teach pistol (right hand) 
  n = InitQuestBlade(n, "bladep204", 	              "bladep204", 	"", "",  "", "",      "", "", 	  "", 0,   0);    //fake Teach pistol (right hand) 
  n = InitQuestBlade(n, "bladep205",	              "bladep205",   "JRH", 13,  "", "",      "", "", 	  "", 0,   0);    //fake Teach pistol (right hand)
  n = InitQuestBlade(n, "bladearmchair",             "armchair01",      "", "",  "", "",      "", "", 	  "", 0,   1);    //armchair

//  n = InitQuestBlade(n, "bladeA2", 	                "bladeA2",  "JRH4",  5,   10, 12,     15, 10, 	  "", 0,   1);    //AOP blade2 rapier POTC blade2-type
//  n = InitQuestBlade(n, "bladeA5", 	                "bladeA4",  "JRH4",  4,   10, 12,     15, 10, 	  "", 0,   1);    //AOP blade4 rapier red/yellow       		//obs bladeA4 & A5 have switched id
//  n = InitQuestBlade(n, "bladeA4", 	                "bladeA5",  "JRH4",  2,   27, 37,     32, 27, 	  "", 3,   1);    //AOP blade5 short broad sabre/cutlass	//obs bladeA4 & A5 have switched id
//  n = InitQuestBlade(n, "bladeA11", 	               "bladeA11",  "JRH4",  3,   10, 12,     15, 10, 	  "", 0,   1);    //AOP blade11 black rapier
//  n = InitQuestBlade(n, "bladeA17", 	               "bladeA17",  "JRH4",  1,   10, 12,     15, 10, 	  "", 0,   1);    //AOP blade17 very long yellow sabre
  n = InitQuestBlade(n, "bladeaxe4", 	                   "axe4",  "JRH2", 14,   10, 12,     15, 10, 	  "", 0,   0);    //execution axe
  n = InitQuestBlade(n, "bladeaxe5", 	                   "axe5",  "JRH2", 15,   10, 12,     15, 10, 	  "", 0,   0);    //small axe in temple (AOP axes unvisible)

  n = InitQuestBlade(n, "bladeplank2", 	            "bladeplank2",  "JRH4",  6,   10, 12,     15, 10, 	  "", 0,   0);    //plank to equip, on the edge
  n = InitQuestBlade(n, "bladepickaxe1", 	       "pickaxe1",  "JRH2", 13,   10, 12,     15, 10, 	  "", 0,   0);    //pickaxe broad, found in armory
  n = InitQuestBlade(n, "bladeirontool",          "bladeirontool",  "JRH2",  9,   10, 12,     15, 10, 	  "", 0,   0);    //tool to open Galley with
  n = InitQuestBlade(n, "bladehammer", 	                 "hammer",  "JRH2", 10,   10, 12,     15, 10, 	  "", 0,   0);    //small sledgehammer
  n = InitQuestBlade(n, "bladepickaxe2", 	       "pickaxe2",  "JRH2", 11,   10, 12,     15, 10, 	  "", 0,   0);    //pickaxe 2 points
  n = InitQuestBlade(n, "bladesaw", 	                    "saw",  "JRH2", 12,   10, 12,     15, 10, 	  "", 0,   0);    //saw

  n = InitQuestBlade(n, "bladebasket", 	            "bladebasket",  	"", "",   10, 12,     15, 10, 	  "", 0,   0);    //Blade basket (shop)
  n = InitQuestBlade(n, "bladeglobe", 	             "bladeglobe",  	"", "",   10, 12,     15, 10, 	  "", 0,   0);    //Blade globe (shop)

  n = InitQuestBlade(n, "bladewood", 	                   "wood",  "JRH3",  7,    5, 10,      0,  5, 	  "", 0,   0);    //wood
  n = InitQuestBlade(n, "bladebarrel", 	              "palka03_B",  "JRH3",  5,    5, 10,      0,  5, 	  "", 0,   0);    //Blade barrel (shop) + Rum barrel distillery + filled barrel prison
  n = InitQuestBlade(n, "bladebarrel2", 	      "palka03_B",  "JRH3",  5,    5, 10,      0,  5, 	  "", 0,   0);    //Blade barrel empty, gibbet room, for rum use
  n = InitQuestBlade(n, "bladebucket", 	           "bucket_water",  "JRH3",  8,   10, 12,     15, 10, 	  "", 0,   0);    //Blade bucket water
  n = InitQuestBlade(n, "bladebottlew4", 	      "bottle_w4",  "JRH3",  6,    5,  5,      0,  0, 	  "", 0,   0);    //Blade bottlew4 molasses
  n = InitQuestBlade(n, "bladebottlew5", 	      "bottle_w4",  "JRH3",  6,    5,  5,      0,  0, 	  "", 0,   0);    //Blade bottlew5 wine Eden tunnel
  n = InitQuestBlade(n, "bladesack", 	                  "sack2",  "JRH3", 11 ,   5,  5,      0,  0, 	  "", 0,   1);    //filled sack with books
  n = InitQuestBlade(n, "bladeskull1", 	                 "skull1",  "JRH3",  2,    5,  5,      0,  0, 	  "", 0,   0);    //(horizontal) for equip use

  n = InitQuestBlade(n, "bladesurgery", 	   "bladesurgery",  "JRH9", 10,   "", "",      0,  0, 	  "", 0,   0);    //locked, for equip use
  n = InitQuestBlade(n, "bladesurgery2", 	   "bladesurgery",  "JRH9", 11,   "", "",      0,  0, 	  "", 0,   0);    //open no saw, for equip use
  n = InitQuestBlade(n, "bladesurgery3", 	   "bladesurgery",  "JRH9", 12,   "", "",      0,  0, 	  "", 0,   0);    //open with saw, for equip use
  n = InitQuestBlade(n, "bladesurgcan",            "bladesurgcan",  "JRH9", 10,   "", "",      0,  0, 	  "", 0,   0);    //locked, for equip use, with cannabis
  n = InitQuestBlade(n, "bladesurgcan2",           "bladesurgcan",  "JRH9", 11,   "", "",      0,  0, 	  "", 0,   0);    //open no saw, for equip use, with cannabis
  n = InitQuestBlade(n, "bladesurgcan3",           "bladesurgcan",  "JRH9", 12,   "", "",      0,  0, 	  "", 0,   0);    //open with saw, for equip use, with cannabis

  n = InitQuestBlade(n, "bladesurgery_r",        "bladesurgery_r",  "JRH9", 10,   "", "",      0,  0, 	  "", 0,   0);    //locked, for equip use + rolls
  n = InitQuestBlade(n, "bladesurgery2_r",       "bladesurgery_r",  "JRH9", 11,   "", "",      0,  0, 	  "", 0,   0);    //open no saw, for equip use + rolls
  n = InitQuestBlade(n, "bladesurgery3_r",       "bladesurgery_r",  "JRH9", 12,   "", "",      0,  0, 	  "", 0,   0);    //open with saw, for equip use + rolls
  n = InitQuestBlade(n, "bladesurgcan_r",        "bladesurgcan_r",  "JRH9", 10,   "", "",      0,  0, 	  "", 0,   0);    //locked, for equip use, with cannabis + rolls
  n = InitQuestBlade(n, "bladesurgcan2_r",       "bladesurgcan_r",  "JRH9", 11,   "", "",      0,  0, 	  "", 0,   0);    //open no saw, for equip use, with cannabis + rolls
  n = InitQuestBlade(n, "bladesurgcan3_r",       "bladesurgcan_r",  "JRH9", 12,   "", "",      0,  0, 	  "", 0,   0);    //open with saw, for equip use, with cannabis + rolls

  n = InitQuestBlade(n, "bladeprescriptions","bladeprescriptions",  "JRH9", 14,   "", "",      0,  0, 	  "", 0,   0);    //prescriptions (rolls) equip if no surgkit
  n = InitQuestBlade(n, "bladefish", 	              "bladefish",  "JRH4", 10,   "", "",      0,  0, 	  "", 0,   0);    //for equip use
  n = InitQuestBlade(n, "bladeviolin", 	            "bladeviolin", "JRH10", 15,   "", "",      0,  0, 	  "", 0,   0);    //for equip use
  n = InitQuestBlade(n, "bladedefense", 	        "defence", "JRH10",  3,   "", "",      0,  0, 	  "", 0,   0);    //shield against mine bomb

  n = InitQuestBlade(n, "bladecannon_ball",    "bladecannon_ball", "JRH16",  4,   "", "",      0,  0, 	  "", 0,   0);    //cannon ball for cannon crew
  n = InitQuestBlade(n, "bladerammer", 	            "bladerammer", "JRH20", 15,   "", "",      0,  0, 	  "", 0,   0);    //rammer for cannon crew
  n = InitQuestBlade(n, "bladesponge", 	            "bladesponge",      "", "",   "", "",      0,  0, 	  "", 0,   0);    //sponge for cannon crew
  n = InitQuestBlade(n, "bladeladle", 	             "bladeladle", "JRH21",  8,   "", "",      0,  0, 	  "", 0,   0);    //ladle for cannon crew
  n = InitQuestBlade(n, "bladewad", 	               "bladewad",      "", "",   "", "",      0,  0, 	  "", 0,   0);    //wad for cannon crew
  n = InitQuestBlade(n, "bladepowderhornA",         "powderhornA", "JRH10", 11,   "", "",      0,  0, 	  "", 0,   1);    //powderhorn pchar (fightmode)
  n = InitQuestBlade(n, "bladepowderhornP",         "powderhornP", "JRH10", 11,   "", "",      0,  0, 	  "", 0,   1);    //powderhorn pchar (not fightmode)
  n = InitQuestBlade(n, "bladepowderhornN",         "powderhornN", "JRH10", 11,   "", "",      0,  0, 	  "", 0,   1);    //powderhorn npc:s careen_shore

  n = InitQuestBlade(n, "bladepinion_small",  "bladepinion_small", "JRH10",  6,   "", "",      0,  0, 	  "", 0,   1);    //
  n = InitQuestBlade(n, "bladepinion_large",  "bladepinion_large", "JRH10",  7,   "", "",      0,  0, 	  "", 0,   1);    //
  n = InitQuestBlade(n, "bladeMap_Hgold",          "bb_Map_piece",      "", "",   "", "",      0,  0, 	  "", 0,   1);    //
  n = InitQuestBlade(n, "folding_knife",                 "blade5", "JRH11",  3,    6, 15,     35,  0, 	  "", 0,   0);    //

  n = InitQuestBlade(n, "bladecauldron",              "cauldron2", "JRH13", 12,   "", "",      0,  0, 	  "", 0,   1);    //empty
  n = InitQuestBlade(n, "bladecauldron_w",          "cauldron2_w", "JRH13", 16,   "", "",      0,  0, 	  "", 0,   1);    //water
  n = InitQuestBlade(n, "bladetop",                        "top2", "JRH13", 10,   "", "",      0,  0, 	  "", 0,   1);    //alchemy

  n = InitQuestBlade(n, "bladebottle_CE0",           "bottle_CE0", "JRH13",  1,   "", "",      0,  0, 	  "", 0,   1);    //empty
  n = InitQuestBlade(n, "bladebottle_CW1",           "bottle_CW1", "JRH13",  2,   "", "",      0,  0, 	  "", 0,   1);    //Ѕ water
  n = InitQuestBlade(n, "bladebottle_CT1_sulf",      "bottle_CT1", "JRH13",  3,   "", "",      0,  0, 	  "", 0,   1);    //Ѕ H2SO4
  n = InitQuestBlade(n, "bladebottle_CT1_nitr",      "bottle_CT1", "JRH13",  3,   "", "",      0,  0, 	  "", 0,   1);    //Ѕ HNO3
  n = InitQuestBlade(n, "bladebottle_CT1_hydr",      "bottle_CT1", "JRH13",  3,   "", "",      0,  0, 	  "", 0,   1);    //Ѕ HCl
  n = InitQuestBlade(n, "bladebottle_CT1_hydrnitr",  "bottle_CT1", "JRH13",  3,   "", "",      0,  0, 	  "", 0,   1);    //Ѕ HNO3+HCl

  n = InitQuestBlade(n, "bladebottle_CT2_sulf_w",    "bottle_CT2", "JRH13",  5,   "", "",      0,  0, 	  "", 0,   1);    //H2SO4 + water
  n = InitQuestBlade(n, "bladebottle_CT2_sulf_c",    "bottle_CT2", "JRH13",  5,   "", "",      0,  0, 	  "", 0,   1);    //H2SO4 + chilesalp
  n = InitQuestBlade(n, "bladebottle_CT2_nitr_w",    "bottle_CT2", "JRH13",  5,   "", "",      0,  0, 	  "", 0,   1);    //Aqua Fortis
  n = InitQuestBlade(n, "bladebottle_CT2_hydr",      "bottle_CT2", "JRH13",  5,   "", "",      0,  0, 	  "", 0,   1);    //HCl
  n = InitQuestBlade(n, "bladebottle_CT2_hydrnitr",  "bottle_CT2", "JRH13",  5,   "", "",      0,  0, 	  "", 0,   1);    //HNO3+HCl
  n = InitQuestBlade(n, "bladebottle_CG2",           "bottle_CG2", "JRH13",  6,   "", "",      0,  0, 	  "", 0,   1);    //H2O + copperas
  n = InitQuestBlade(n, "bladebottle_CA2",           "bottle_CA2", "JRH13",  7,   "", "",      0,  0, 	  "", 0,   1);    //Aqua Regis

  n = InitQuestBlade(n, "bladebottle_CP2",           "bottle_CP2", "JRH13",  8,   "", "",      0,  0, 	  "", 0,   1);    //(pink) champagne
  n = InitQuestBlade(n, "bladebottle_CB1",           "bottle_CB1", "JRH13",  4,   "", "",      0,  0, 	  "", 0,   1);    //raw cognac (pure alchohol)
  n = InitQuestBlade(n, "bladebottle_CB2",           "bottle_CB2", "JRH12", 12,   "", "",      0,  0, 	  "", 0,   1);    //equip cognac (very temp), becomes cognac
  n = InitQuestBlade(n, "bladebottle_CR2",           "bottle_CR2", "JRH12", 13,   "", "",      0,  0, 	  "", 0,   1);    //equip wine bottle (very temp), becomes potionwine2

  n = InitQuestBlade(n, "bladecompasses",     "pair_of_compasses", "JRH10", 12,    1,  1,      0,  0, 	  "", 0,   0);
  n = InitQuestBlade(n, "bladekeysimple",             "keysimple", "JRH10", 14,    1,  1,      0,  0, 	  "", 0,   0);    //to belt

  n = InitQuestBlade(n, "bladechurchsilver",       "churchsilver",  "JRH3", 10,    1,  1,      0,  0,     "", 0,   0);    //sack with d:o
  n = InitQuestBlade(n, "bladelockpick",          "bladelockpick", "JRH14",  1,    1,  1,      0,  0, 	  "", 0,   0);    //
  n = InitQuestBlade(n, "bladehandle", 	            "bladehandle", "JRH14",  2,    1,  1,      0,  0, 	  "", 0,   0);    //
  n = InitQuestBlade(n, "bladeladder", 	            "bladeladder", "JRH14",  3,    3,  3,      0, 20, 	  "", 0,   0);    //choir
  n = InitQuestBlade(n, "bladeoilbottle",        "bladeoilbottle", "JRH14",  4,    0,  0,      0,  0, 	  "", 0,   0);    //
  n = InitQuestBlade(n, "bladekeygrand",               "keygrand", "JRH14",  5,    1,  1,      0,  0, 	  "", 0,   0);    //to clock in church_choir

  n = InitQuestBlade(n, "bladeladder2", 	   "bladeladder2", "JRH14",  3,    3,  3,      0, 20, 	  "", 0,   0);    //wood tower
  n = InitQuestBlade(n, "bladeflag_pir",          "bladeflag_pir", "JRH16",  6,    0,  0,      0,  0, 	  "", 0,   1);    //Rackham
  n = InitQuestBlade(n, "bladeflag_pir2",        "bladeflag_pir2", "JRH32",  1,    0,  0,      0,  0, 	  "", 0,   1);    //Teach
  n = InitQuestBlade(n, "bladeflag_HOL",          "bladeflag_HOL", "JRH32",  2,    0,  0,      0,  0, 	  "", 0,   1);    //
  n = InitQuestBlade(n, "bladeflag_ENG",          "bladeflag_ENG", "JRH32",  3,    0,  0,      0,  0, 	  "", 0,   1);    //
  n = InitQuestBlade(n, "bladeflag_FRA",          "bladeflag_FRA", "JRH32",  4,    0,  0,      0,  0, 	  "", 0,   1);    //
  n = InitQuestBlade(n, "bladeflag_POR",          "bladeflag_POR", "JRH32",  5,    0,  0,      0,  0, 	  "", 0,   1);    //
  n = InitQuestBlade(n, "bladeflag_SPA",          "bladeflag_SPA", "JRH32",  6,    0,  0,      0,  0, 	  "", 0,   1);    //
  n = InitQuestBlade(n, "bladeflag_PRE",          "bladeflag_PRE", "JRH32",  7,    0,  0,      0,  0, 	  "", 0,   1);    //
  n = InitQuestBlade(n, "bladeflag_IRE",          "bladeflag_IRE", "JRH32",  8,    0,  0,      0,  0, 	  "", 0,   1);    //
  n = InitQuestBlade(n, "bladeflag_SWE",          "bladeflag_SWE", "JRH32",  9,    0,  0,      0,  0, 	  "", 0,   1);    //
  n = InitQuestBlade(n, "bladeflag_HOL2",        "bladeflag_HOL2", "JRH32", 10,    0,  0,      0,  0, 	  "", 0,   1);    //
  n = InitQuestBlade(n, "bladeflag_AME",          "bladeflag_AME", "JRH32", 11,    0,  0,      0,  0, 	  "", 0,   1);    //
  n = InitQuestBlade(n, "bladeflag_SPA2",        "bladeflag_SPA2", "JRH32", 12,    0,  0,      0,  0, 	  "", 0,   1);    //
  n = InitQuestBlade(n, "bladepainting",          "bladepainting",  "JRH6",  8,    0,  0,      0,  0, 	  "", 0,   1);    //Frans Hals rolled

  n = InitQuestBlade(n, "bladechest_red",        "bladechest_red", "JRH16",  7,    0,  0,      0,  0, 	  "", 0,   0);    //blue cavern chest
  n = InitQuestBlade(n, "bladeboathook_1",      "bladeboathook_1", "JRH16",  8,    0,  0,      0,  0, 	  "", 0,   0);    //passive mode
  n = InitQuestBlade(n, "bladeboathook_2",      "bladeboathook_2", "JRH16",  8,    0,  0,      0,  0, 	  "", 0,   0);    //fight mode
  n = InitQuestBlade(n, "blademegaphone",        "blademegaphone", "JRH16",  9,    0,  0,      0,  0, 	  "", 0,   0);    //megaphone
  n = InitQuestBlade(n, "bladewhistle",            "bladewhistle", "JRH16", 10,    0,  0,      0,  0, 	  "", 0,   0);    //whistle
  n = InitQuestBlade(n, "bladespyglass5",        "bladespyglass5", "JRH16", 11,    5, 10,      5,  1, 	  "", 0,   0);    //cave shore use

  n = InitQuestBlade(n, "tool1",	      "pair_of_compasses",  "JRH2",  6,    1,  1,      1,  1, 	  "", 0,   0);    //pair of compasses etc
  n = InitQuestBlade(n, "tool2",		           "axe1",  "JRH2",  8,    1,  1,      1,  1, 	  "", 0,   0);    //axe etc
  n = InitQuestBlade(n, "tool3",		         "hammer",  "JRH2",  7,    1,  1,      1,  1, 	  "", 0,   0);    //club etc
  n = InitQuestBlade(n, "tool4",		          "drill",  "JRH2",  3,    1,  1,      1,  1, 	  "", 0,   0);    //drill etc
  n = InitQuestBlade(n, "tool5",		            "saw",  "JRH2",  4,    1,  1,      1,  1, 	  "", 0,   0);    //saw etc
  n = InitQuestBlade(n, "tool6",		       "pickaxe1",  "JRH2",  5,    1,  1,      1,  1, 	  "", 0,   0);    //lever etc
 
  n = InitQuestBlade(n, "bladelever",		     "bladelever", "JRH10", 10,    1,  1,      1,  1, 	  "", 0,   0);    //Cartagena
  n = InitQuestBlade(n, "bladeclockkey",          "bladeclockkey", "JRH14",  5,    1,  1,      0,  0, 	  "", 0,   0);    //Cartagena
  n = InitQuestBlade(n, "bladefire_irons",	"bladefire_irons", "JRH16",  3,    1,  1,      1,  1, 	  "", 0,   0);    //Cartagena
  n = InitQuestBlade(n, "bladeacid",		      "bladeacid",       1,  5,    1,  1,      1,  1, 	  "", 0,   0);    //Cartagena

//Q2
  n = InitQuestBlade(n, "bladebarrel3", 	   "bladebarrel3", "JRH27",  4,    5, 10,      0,  5, 	  "", 0,   0);	  //Bladebarrel3 Eden tunnel

  n = InitQuestBlade(n, "bladebottle_CC1",           "bottle_CC1", "JRH22",  4,   "", "",      0,  0, 	  "", 0,   1);    //Ѕ black powder: grinded limestone
  n = InitQuestBlade(n, "bladebottle_CG1",           "bottle_CG1", "JRH22",  3,   "", "",      0,  0, 	  "", 0,   1);    //Ѕ grey powder: grinded SB2S3
  n = InitQuestBlade(n, "bladebottle_CV1_ss",        "bottle_CV1", "JRH13",  3,   "", "",      0,  0, 	  "", 0,   1);    //Ѕ white powder, after first boiling: Sodium Sulfate
  n = InitQuestBlade(n, "bladebottle_CV1_sc",        "bottle_CV1", "JRH13",  3,   "", "",      0,  0, 	  "", 0,   1);    //Ѕ white powder, after filter: Sodium Carbonate
  n = InitQuestBlade(n, "bladebottle_CV1_cao",       "bottle_CV1", "JRH13",  3,   "", "",      0,  0, 	  "", 0,   1);    //Ѕ white powder, after grey powder oven heat2
  n = InitQuestBlade(n, "bladebottle_CV1_NH4Cl",     "bottle_CV1", "JRH13",  3,   "", "",      0,  0, 	  "", 0,   1);    //Ѕ white powder, after dung in oven heat1
  n = InitQuestBlade(n, "bladebottle_CR1",           "bottle_CR1", "JRH30",  9,   "", "",      0,  0, 	  "", 0,   1);    //Ѕ red powder, after filter
  n = InitQuestBlade(n, "bladebottle_BTc_mix3",      "bottle_BTc", "JRH30",  1,   "", "",      0,  0, 	  "", 0,   1);    //3/4 Na2CO3 + H2O + CaS, before filter
  n = InitQuestBlade(n, "bladebottle_BTc_hydr",      "bottle_BTc", "JRH30",  1,   "", "",      0,  0, 	  "", 0,   1);    //3/4 2NaCl + H2SO4
  n = InitQuestBlade(n, "bladebottle_CV2",           "bottle_CV2", "JRH13",  5,   "", "",      0,  0, 	  "", 0,   1);    //mix2 after oven
  n = InitQuestBlade(n, "bladebottle_BY2_mix7",      "bottle_BY2", "JRH22",  5,   "", "",      0,  0, 	  "", 0,   1);    //full: yellow liquid
  n = InitQuestBlade(n, "bladebottle_BY1_mix7",      "bottle_BY1", "JRH22",  1,   "", "",      0,  0, 	  "", 0,   1);    //Ѕ: yellow liquid (as a rest)
  n = InitQuestBlade(n, "bladebottle_GY2",           "bottle_GY2", "JRH22",  5,   "", "",      0,  0, 	  "", 0,   1);    //full: light yellow gas
  n = InitQuestBlade(n, "bladebottle_BS1_LH",        "bottle_BS1", "JRH22",  2,   "", "",      0,  0, 	  "", 0,   1);    //Ѕ: Liquor Hepatis
  n = InitQuestBlade(n, "bladebottle_BS2_LH",        "bottle_BS2", "JRH22",  6,   "", "",      0,  0, 	  "", 0,   1);    //full: Liquor Hepatis
  n = InitQuestBlade(n, "bladebottle_BY2_mix9",      "bottle_BY2", "JRH22",  5,   "", "",      0,  0, 	  "", 0,   1);    //full: light yellow powder
  n = InitQuestBlade(n, "bladebottle_BP1_ps",        "bottle_BP1", "JRH30", 10,   "", "",      0,  0, 	  "", 0,   1);    //Ѕ purple: Pulvis Solaris
  n = InitQuestBlade(n, "bladebottle_BP2_ps",        "bottle_BP2", "JRH30", 11,   "", "",      0,  0, 	  "", 0,   1);    //full purple: Pulvis Solaris
  n = InitQuestBlade(n, "bladebottle_BAU",           "bottle_BAU", "JRH30", 12,   "", "",      0,  0, 	  "", 0,   1);    //

  n = InitQuestBlade(n, "bladebottle_CB2_mix9",      "bottle_CB2", "JRH12", 12,   "", "",      0,  0, 	  "", 0,   1);    //full: dark yellow powder: dried mix9
  n = InitQuestBlade(n, "bladebottle_CB1_mix9",      "bottle_CB1", "JRH13",  4,   "", "",      0,  0, 	  "", 0,   1);    //Ѕ dark yellow powder: dried mix9
  n = InitQuestBlade(n, "bladebottle_CC2_bps",       "bottle_AC2", "JRH22",  8,   "", "",      0,  0, 	  "", 0,   1);    //full: Black Pulvis Solaris
  n = InitQuestBlade(n, "bladebottle_CQ1",           "bottle_CQ1", "JRH30", 13,   "", "",      0,  0, 	  "", 0,   1);    //Ѕ liquid mercury
  n = InitQuestBlade(n, "bladebottle_CT2_mix11",     "bottle_CT2", "JRH13",  5,   "", "",      0,  0, 	  "", 0,   1);    //full white 
  n = InitQuestBlade(n, "bladebottle_CA2_mix11",     "bottle_CA2", "JRH13",  7,   "", "",      0,  0, 	  "", 0,   1);    //full orange liquid: HgO + HNO2, before filter
  n = InitQuestBlade(n, "bladebottle_CR2_rps",       "bottle_CR2", "JRH12", 13,   "", "",      0,  0, 	  "", 0,   1);    //full: Red Pulvis Solaris

  n = InitQuestBlade(n, "bladekeyring",       	        "keyring", "JRH31", 14,   2,   2,      0,  0, 	  "", 0,   0);    //Maltese location
  n = InitQuestBlade(n, "bladeBB", 	                "bladeBB", "JRH33",  1,   22, 37,     40, 40, 	  "", 5,   0);    //Teach's cutlass
  n = InitQuestBlade(n, "bladelever3",		    "bladelever3", "JRH33",  2,    3,  3,      1,  1, 	  "", 0,   0);    //outside BB upper cave
  n = InitQuestBlade(n, "blade_gp_dry",		   "blade_gp_dry", "JRH37",  7,    3,  3,      1,  1, 	  "", 0,   0);    //
  n = InitQuestBlade(n, "BBdagger",	               "BBdagger", "JRH28", 16,    6, 15,     30,  4, 	  "", 0,   0);    //BB treasure to cut out painting
  n = InitQuestBlade(n, "bladechair", 	             "bladechair", "LEVIS",  5,    5, 10,      0,  5, 	  "", 0,   0);    //burning cave
  n = InitQuestBlade(n, "pitchfork", 	              "pitchfork", "JRH38",  8,   20, 20,     15, 10, 	  "", 0,   0);    //careen corvette

//GoldBug
  n = InitQuestBlade(n, "bladeemptysack",                 "sack2", "JRH3",  10,    1,  1,      0,  0,     "", 0,   0);    //for driftwood
  n = InitQuestBlade(n, "bladeemptysack_P",            "bladewad", "JRH3",  10,    1,  1,      0,  0,     "", 0,   0);    //for Pym books
  n = InitQuestBlade(n, "bladesemifullsack_P",       	  "sack2", "JRH25", 12,    1,  1,      0,  0,     "", 0,   0);    //for Pym books
  n = InitQuestBlade(n, "bladefullsack_P",            "sack2_big", "JRH25", 11,    1,  1,      0,  0,     "", 0,   0);    //for Pym books
  n = InitQuestBlade(n, "bladewoodsack",       	   	  "sack2", "JRH19",  5,    1,  1,      0,  0,     "", 0,   0);    //sack with 9 driftwood
  n = InitQuestBlade(n, "bladeemptysack_B",            "bladewad", "JRH3",  10,    1,  1,      0,  0,     "", 0,   0);    //for birds
  n = InitQuestBlade(n, "bladebirdsack",       	       "bladewad", "JRH20",  1,    1,  1,      0,  0,     "", 0,   0);    //sack with 4 birds
  
  n = InitQuestBlade(n, "bladecrypto_d",       	  "bb_Map_piece2", "JRH19",  9,    1,  1,      0,  0,     "", 0,   0);    //crypto
  n = InitQuestBlade(n, "bladecrypto_dl",         "bb_Map_piece2", "JRH19", 10,    1,  1,      0,  0,     "", 0,   0);    //crypto
  n = InitQuestBlade(n, "bladecrypto_ds",         "bb_Map_piece2", "JRH19", 11,    1,  1,      0,  0,     "", 0,   0);    //crypto
  n = InitQuestBlade(n, "bladecrypto_dsk",        "bb_Map_piece2", "JRH19", 12,    1,  1,      0,  0,     "", 0,   0);    //crypto
  n = InitQuestBlade(n, "bladecrypto_cl",          "bb_Map_piece", "JRH19", 13,    1,  1,      0,  0,     "", 0,   0);    //crypto
  n = InitQuestBlade(n, "bladecrypto_csk",         "bb_Map_piece", "JRH19", 14,    1,  1,      0,  0,     "", 0,   0);    //crypto
  n = InitQuestBlade(n, "bladecrypto_cskp",        "bb_Map_piece", "JRH19", 15,    1,  1,      0,  0,     "", 0,   0);    //crypto
  n = InitQuestBlade(n, "bladecrypto_cskt",        "bb_Map_piece", "JRH19", 16,    1,  1,      0,  0,     "", 0,   0);    //crypto
  n = InitQuestBlade(n, "bladefryingpan",        "bladefryingpan", "JRH19",  7,    1,  1,      0,  0,     "", 0,   0);    //temp model?
  
  n = InitQuestBlade(n, "bladeflag_usa",          "bladeflag_usa", "JRH18", 13,    0,  0,      0,  0, 	  "", 0,   0);    //
  n = InitQuestBlade(n, "bladewood_short",           "wood_short", "JRH18", 14,    0,  0,      0,  0, 	  "", 0,   0);    //after axe
  n = InitQuestBlade(n, "bladewood4",                "bladewood4", "JRH18", 15,   "", "",      0,  0, 	  "", 0,   1);    //after saw

  n = InitQuestBlade(n, "bladebottle_AC2",           "bottle_AC2", "JRH22",  8,   "", "",      0,  0, 	  "", 0,   1);    //Medium bottles, also CE0
  n = InitQuestBlade(n, "bladebottle_AG2",           "bottle_AG2", "JRH22",  7,   "", "",      0,  0, 	  "", 0,   1);    //
  n = InitQuestBlade(n, "bladebottle_AN2",           "bottle_AN2", "JRH13",  5,   "", "",      0,  0, 	  "", 0,   1);    //
  n = InitQuestBlade(n, "bladebottle_AS2",           "bottle_AS2", "JRH22",  6,   "", "",      0,  0, 	  "", 0,   1);    //
  n = InitQuestBlade(n, "bladebottle_AY2",           "bottle_AY2", "JRH22",  5,   "", "",      0,  0, 	  "", 0,   1);    //
  n = InitQuestBlade(n, "bladebottle_AZ2",           "bottle_AZ2", "JRH22", 10,   "", "",      0,  0, 	  "", 0,   1);    //

  n = InitQuestBlade(n, "bladebottle_BE0",           "bottle_BE0", "JRH13",  1,   "", "",      0,  0, 	  "", 0,   1);    //Big bottles
  n = InitQuestBlade(n, "bladebottle_BC1",           "bottle_BC1", "JRH22",  4,   "", "",      0,  0, 	  "", 0,   1);    //
  n = InitQuestBlade(n, "bladebottle_BC2",           "bottle_BC2", "JRH22",  8,   "", "",      0,  0, 	  "", 0,   1);    //
  n = InitQuestBlade(n, "bladebottle_BG1",           "bottle_BG1", "JRH22",  3,   "", "",      0,  0, 	  "", 0,   1);    //
  n = InitQuestBlade(n, "bladebottle_BG2",           "bottle_BG2", "JRH22",  7,   "", "",      0,  0, 	  "", 0,   1);    //
  n = InitQuestBlade(n, "bladebottle_BN1",           "bottle_BN1", "JRH13",  3,   "", "",      0,  0, 	  "", 0,   1);    //
  n = InitQuestBlade(n, "bladebottle_BN2",           "bottle_BN2", "JRH13",  5,   "", "",      0,  0, 	  "", 0,   1);    //
  n = InitQuestBlade(n, "bladebottle_BS1",           "bottle_BS1", "JRH22",  2,   "", "",      0,  0, 	  "", 0,   1);    //
  n = InitQuestBlade(n, "bladebottle_BS2",           "bottle_BS2", "JRH22",  6,   "", "",      0,  0, 	  "", 0,   1);    //
  n = InitQuestBlade(n, "bladebottle_BY1",           "bottle_BY1", "JRH22",  1,   "", "",      0,  0, 	  "", 0,   1);    //
  n = InitQuestBlade(n, "bladebottle_BY2",           "bottle_BY2", "JRH22",  5,   "", "",      0,  0, 	  "", 0,   1);    //
  n = InitQuestBlade(n, "bladebottle_BZ1",           "bottle_BZ1", "JRH22",  9,   "", "",      0,  0, 	  "", 0,   1);    //
  n = InitQuestBlade(n, "bladebottle_BZ2",           "bottle_BZ2", "JRH22", 10,   "", "",      0,  0, 	  "", 0,   1);    //

  n = InitQuestBlade(n, "bladewood2", 	                  "wood2",  "JRH3",  7,    5, 10,      0,  5, 	  "", 0,   0);    //wood doubled
  n = InitQuestBlade(n, "bladefireworks", 	 "bladefireworks", "JRH18", 16,    5, 10,      0,  5, 	  "", 0,   0);    //
  n = InitQuestBlade(n, "sledgehammer", 	   "sledgehammer", "JRH21", 16,    5, 10,      0,  5, 	  "", 0,   0);    //
  
  n = InitQuestBlade(n, "bladebarrel_gp0", 	      "palka03_B", "JRH22", 11,    5, 10,      0,  5, 	  "", 0,   0);	  //Bladebarrel empty for GP use
  n = InitQuestBlade(n, "bladebarrel_gpW", 	      "palka03_B", "JRH22", 11,    5, 10,      0,  5, 	  "", 0,   0);	  //Bladebarrel wrong mixture
  n = InitQuestBlade(n, "bladebarrel_gpS", 	      "palka03_B", "JRH22", 11,    5, 10,      0,  5, 	  "", 0,   0);	  //Bladebarrel standard GP
  n = InitQuestBlade(n, "bladebarrel_gpF", 	      "palka03_B", "JRH22", 11,    5, 10,      0,  5, 	  "", 0,   0);	  //Bladebarrel fireworks GP

  n = InitQuestBlade(n, "bladepaperroll",          "bb_Map_piece", "JRH17", 14,   "", "",      0,  0, 	  "", 0,   1);    //rolled BH sketch

  n = InitQuestBlade(n, "bladeflint",               "flintstone",    "BOP", 15,   "", "",      0,  0, 	  "", 0,   1);    //flint to steel
  n = InitQuestBlade(n, "bladespade",               "bladespade",   "JRH2", 16,    3, 13,      5, 15, 	  "", 0,   0);    //
  n = InitQuestBlade(n, "treasurechest_red",  "treasurechest_red", "JRH16",  7,    0,  0,      0,  0, 	  "", 0,   0);    //closed red chest

  n = InitQuestBlade(n, "bladewoodX", 	              "wood_pile",  "JRH3",  7,    5, 10,      0,  5, 	  "", 0,   0);    //lots of wood


  //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  // QUEST GUNS:           			 		                       Accuracy
  //		ItemIndex	    		      picTexture        minDamage     	 | Charges  	  Change model				Ammo type
  //		   |	 gunID           modelID               | picIndex    | maxDamage |   | Reload time| Nation		Sound		     | Price
  //-----------------|-------|----------------|----------------|------|------|---|-------|---|---|--------|---|----------------|---------------------|----|-----------------------
  n = InitQuestGun(n, "pistol201",     	"pistol201",	      "JRH",  9,    50, 67.5,   60,  1, 12,	 "", "", "OBJECTS\DUEL\pistol_medium3.wav", "pb", 0);	 //pistol201 Johnson
  n = InitQuestGun(n, "pistol202",     	"pistol202",	      "JRH", 10,    35, 50, 	40,  1,  8,	 "", "", "OBJECTS\DUEL\pistol_small2.wav",  "pb", 0);	 //pistol202 Caesar
  n = InitQuestGun(n, "pistol203",     	"pistol203",	      "JRH", 11,    60, 80, 	70,  1, 16,	 "", "", "OBJECTS\DUEL\pistol_big2.wav",    "pb", 0);	 //pistol203 Hornigold
  n = InitQuestGun(n, "pistol204",     	"pistol204",	      "JRH", 12,    40, 55, 	50,  1,  8,	 "", "", "OBJECTS\DUEL\pistol_grape.wav",   "pb", 0);	 //pistol204 Eden
  n = InitQuestGun(n, "pistol205",     	"pistol205",	      "JRH", 13,    50, 67.5, 	60,  1, 12,	 "", "", "OBJECTS\DUEL\pistol_medium2.wav", "pb", 0);    //pistol205 Richards
  n = InitQuestGun(n, "pistol206",     	"pistol206",	      "JRH", 14,    65, 85, 	75,  1, 16,	 "", "", "OBJECTS\DUEL\pistol_musket.wav",  "pb", 0);	 //pistol206 Hands
  n = InitQuestGun(n, "pistol20",     	"pistol201",	      "JRH", 16,    "", "", 	"",  6, 60,	  1, "", 		   "", 		    "pb", 2);	 //Blackbeard's Belt with 6 guns
  n = InitQuestGun(n, "pistol0",     	"pistol0",          "JRH14", 15,    20, 30, 	40,  2, 12,	 "", "", "OBJECTS\DUEL\pistol_pocket.wav",  "pb", 0);	 //pocket pistol

  n = InitQuestGun(n, "pistolb1",     	"blade1",	         "", "",    "", "", 	"",  0, "",	 "", "", 		   "",                "", 0);	 //Fake Saber (left hand)
  n = InitQuestGun(n, "pistolbarrel",     "palka03_B",	         "", "",    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //Pistol barrel (crew shop)
  n = InitQuestGun(n, "pistolbarrel4",    "palka03_B4",	         "", "",    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //Pistol barrel (guncrew) at the back
  n = InitQuestGun(n, "pistolbucket",     "bucket_water",    "JRH3",  8,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //Pistol bucket water
  n = InitQuestGun(n, "pistoltar",        "bucket_tar",     "JRH16", 13,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //Pistol bucket tar
  n = InitQuestGun(n, "pistolbottlew4",   "bottle_w4",       "JRH3",  6,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //Pistol bottlew4 molasses
  n = InitQuestGun(n, "pistolbottlew5",   "bottle_w4",       "JRH3",  6,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //Pistol bottlew5 wine Eden tunnel
  n = InitQuestGun(n, "pistol_armchair",  "armchair02",          "", "",    20, 20,    100,  0, 0.1,	 "", "",     "OBJECTS\DUEL\yah_break.wav",  "pb", 0);    //goods in shop, sound ev used later on (with throw = 1)
  //..........................................................................................................................................................................................................
  n = InitQuestGun(n, "pistolmdchest_F1", "mdchest_F1",	     "JRH8",  1,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //locked
  n = InitQuestGun(n, "pistolmdchest_F1_C","mdchest_F1_C",   "JRH8",  1,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //locked
  //..........................................................................................................................................................................................................
  n = InitQuestGun(n, "pistolmdchest_F2A","mdchest_F2",	     "JRH8",  2,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //half open - empty
  n = InitQuestGun(n, "pistolmdchest_F2A_C","mdchest_F2_C",  "JRH8",  2,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //half open - empty
  n = InitQuestGun(n, "pistolmdchest_F2A_S","mdchest_F2_S",  "JRH8",  2,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //half open - empty
  n = InitQuestGun(n, "pistolmdchest_F2A_CS","mdchest_F2_CS","JRH8",  2,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //half open - empty

  n = InitQuestGun(n, "pistolmdchest_F2B","mdchest_F2",	     "JRH8",  3,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //half open - empty
  n = InitQuestGun(n, "pistolmdchest_F2B_C","mdchest_F2_C",  "JRH8",  3,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //half open - empty
  n = InitQuestGun(n, "pistolmdchest_F2B_S","mdchest_F2_S",  "JRH8",  3,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //half open - empty
  n = InitQuestGun(n, "pistolmdchest_F2B_CS","mdchest_F2_CS","JRH8",  3,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //half open - empty
  //..........................................................................................................................................................................................................
  n = InitQuestGun(n, "pistolmdchest_F3A","mdchest_F2",	     "JRH8",  6,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //half open - some bottles
  n = InitQuestGun(n, "pistolmdchest_F3A_C","mdchest_F2_C",  "JRH8",  6,    "", "", 	"",  0, "",	 "", "", 	           "",              "pb", 0);    //half open - some bottles
  n = InitQuestGun(n, "pistolmdchest_F3A_S","mdchest_F2_S",  "JRH8",  6,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //half open - some bottles
  n = InitQuestGun(n, "pistolmdchest_F3A_CS","mdchest_F2_CS","JRH8",  6,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //half open - some bottles

  n = InitQuestGun(n, "pistolmdchest_F3B","mdchest_F2",	     "JRH8",  7,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //half open - some bottles
  n = InitQuestGun(n, "pistolmdchest_F3B_C","mdchest_F2_C",  "JRH8",  7,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //half open - some bottles
  n = InitQuestGun(n, "pistolmdchest_F3B_S","mdchest_F2_S",  "JRH8",  7,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //half open - some bottles
  n = InitQuestGun(n, "pistolmdchest_F3B_CS","mdchest_F2_CS","JRH8",  7,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //half open - some bottles
  //..........................................................................................................................................................................................................
  n = InitQuestGun(n, "pistolmdchest_F4A","mdchest_F4",	     "JRH8",  9,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //open - some bottles
  n = InitQuestGun(n, "pistolmdchest_F4A_C","mdchest_F4_C",  "JRH8",  9,    "", "", 	"",  0, "",	 "", "", 	   	   "",              "pb", 0);    //open - some bottles
  n = InitQuestGun(n, "pistolmdchest_F4A_S","mdchest_F4_S",  "JRH8",  9,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //open - some bottles
  n = InitQuestGun(n, "pistolmdchest_F4A_CS","mdchest_F4_CS","JRH8",  9,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //open - some bottles

  n = InitQuestGun(n, "pistolmdchest_F4B","mdchest_F4",	     "JRH8", 10,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //open - some bottles
  n = InitQuestGun(n, "pistolmdchest_F4B_C","mdchest_F4_C",  "JRH8", 10,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //open - some bottles
  n = InitQuestGun(n, "pistolmdchest_F4B_S","mdchest_F4_S",  "JRH8", 10,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //open - some bottles
  n = InitQuestGun(n, "pistolmdchest_F4B_CS","mdchest_F4_CS","JRH8", 10,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //open - some bottles

  n = InitQuestGun(n, "pistolmdchest_F4C","mdchest_F4",	     "JRH8", 11,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //open - some bottles
  n = InitQuestGun(n, "pistolmdchest_F4C_C","mdchest_F4_C",  "JRH8", 11,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //open - some bottles
  n = InitQuestGun(n, "pistolmdchest_F4C_S","mdchest_F4_S",  "JRH8", 11,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //open - some bottles
  n = InitQuestGun(n, "pistolmdchest_F4C_CS","mdchest_F4_CS","JRH8", 11,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //open - some bottles
  //..........................................................................................................................................................................................................
  n = InitQuestGun(n, "pistolmdchest_F5A","mdchest_F4",	     "JRH8", 13,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //open - filled
  n = InitQuestGun(n, "pistolmdchest_F5A_C","mdchest_F4_C",  "JRH8", 13,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //open - filled
  n = InitQuestGun(n, "pistolmdchest_F5A_S","mdchest_F4_S",  "JRH8", 13,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //open - filled
  n = InitQuestGun(n, "pistolmdchest_F5A_CS","mdchest_F4_CS","JRH8", 13,    "", "", 	"",  0, "",	 "", "", 	 	   "",              "pb", 0);    //open - filled

  n = InitQuestGun(n, "pistolmdchest_F5B","mdchest_F4",	     "JRH8", 14,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //open - filled
  n = InitQuestGun(n, "pistolmdchest_F5B_C","mdchest_F4_C",  "JRH8", 14,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //open - filled
  n = InitQuestGun(n, "pistolmdchest_F5B_S","mdchest_F4_S",  "JRH8", 14,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //open - filled
  n = InitQuestGun(n, "pistolmdchest_F5B_CS","mdchest_F4_CS","JRH8", 14,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //open - filled

  n = InitQuestGun(n, "pistolmdchest_F5C","mdchest_F4",	     "JRH8", 15,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //open - filled
  n = InitQuestGun(n, "pistolmdchest_F5C_C","mdchest_F4_C",  "JRH8", 15,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //open - filled
  n = InitQuestGun(n, "pistolmdchest_F5C_S","mdchest_F4_S",  "JRH8", 15,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //open - filled
  n = InitQuestGun(n, "pistolmdchest_F5C_CS","mdchest_F4_CS","JRH8", 15,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //open - filled
  //..........................................................................................................................................................................................................
  n = InitQuestGun(n, "pistolmdchest_F6", "mdchest_F6",	     "JRH8",  5,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //closed - repaired
  n = InitQuestGun(n, "pistolmdchest_F6_C","mdchest_F6_C",   "JRH8",  5,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //closed - repaired
  n = InitQuestGun(n, "pistolmdchest_F6_S","mdchest_F6_S",   "JRH8",  5,    "", "", 	"",  0, "",	 "", "", 	           "",              "pb", 0);    //closed - repaired
  n = InitQuestGun(n, "pistolmdchest_F6_CS","mdchest_F6_CS", "JRH8",  5,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //closed - repaired
  //..........................................................................................................................................................................................................
  n = InitQuestGun(n, "pistolmdclothsack", "mdclothsack",    "JRH9", 15,    "", "", 	"",  0, "",	 "", "", 	           "",              "pb", 0);
  n = InitQuestGun(n, "pistolmdcloth", 	 "mdcloth",	     "JRH9", 15,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);
  n = InitQuestGun(n, "pistolmdsack", 	 "mdsack",	     "JRH3", 10,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);

  n = InitQuestGun(n, "pistolfoodchest", "pistolfoodchest",  "JRH4", 12,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //food chest
  n = InitQuestGun(n, "pistolfoodchest2","pistolfoodchest2", "JRH4", 12,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //food chest + ale barrel
  n = InitQuestGun(n, "pistoltoolchest1","pistoltoolchest1", "JRH2",  1,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //empty carp chest
  n = InitQuestGun(n, "pistoltoolchest2","pistoltoolchest2", "JRH2",  2,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //filled carp chest

  n = InitQuestGun(n, "pistolmine",	 "pistolmine",	    "JRH10",  2,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //mine in temple
  n = InitQuestGun(n, "pistolspade",	 "spade",            "JRH2", 16,    20, 20,    100,  1, 0.1,	 "", "",               "PEOPLE\wood3.wav",  "pb", 0);    //spade

  n = InitQuestGun(n, "pistolrammer",	 "pistolrammer",         "", "",    "", "",      "", 0, "",	 "", "",               	   "",              "pb", 0);    //passive vertical rammer for cannon crew
  n = InitQuestGun(n, "pistolsponge",	 "pistolsponge",         "", "",    "", "",      "", 0, "",	 "", "",               	   "",              "pb", 0);    //passive vertical sponge for cannon crew
  n = InitQuestGun(n, "pistolhammer",	 "hammer",  	     "JRH2", 10,    20, 20,    100,  1, 0.1,	 "", "",                   "",                "", 0);    //used in BB wreck instead
  n = InitQuestGun(n, "pistolwad",	 "pistolwad",  	         "", "",    "", "",      "", 0, "",	 "", "",               	   "",              "pb", 0);    //passive wad for cannon crew
  n = InitQuestGun(n, "pistolcannon_ball","pistolcannon_ball",   "", "",    "", "",      "", 0, "",	 "", "",               	   "",              "pb", 0);    //passive ball for cannon crew

  n = InitQuestGun(n, "pistolplank2",	 "bladeplank2",      "JRH4",  6,    "", "",      "", 0, "",	 "", "",               	   "",              "pb", 0);    //plank to equip, on the edge
  n = InitQuestGun(n, "pistolwheel",	 "pistolwheel",     "JRH10",  5,    20, 20,     100, 1, 0.1,	 "", "",               	   "",              "pb", 1);    //wheel
  n = InitQuestGun(n, "pistolhand",	 "invisible",       "JRH10",  8,     1,  1,     100, 1, 0.1,	 "", "",               	   "",              "pb", 1);    //mechanics pickups
  n = InitQuestGun(n, "pistolMap_Hgold", "bb_Map_piece",         "", "",     1,  1,     100, 1, 0.1,	 "", "",               	   "",              "pb", 1);    //
  n = InitQuestGun(n, "pistoltinderbox", "tinderbox",       "JRH11",  4,     1,  1,     100, 1, 0.1,	 "", "",               	   "",              "tb", 0);    //tinderbox pistol style

  n = InitQuestGun(n, "pistolsteel",      "firesteel",        "BOP", 16,     1,  1,     100, 1, 0.1,	 "", "",               	   "",              "tb", 0);    //steel to flint

  n = InitQuestGun(n, "pistolretort",	 "retort2",         "JRH13",  9,    "", "",      "", 1, 0.1,	 "", "",               	   "",                "", 1);    //alchemy
  n = InitQuestGun(n, "pistolglass_tube","glass_tube2",     "JRH13", 11,    "", "",      "", 1, 0.1,	 "", "",               	   "",                "", 1);    //alchemy
  n = InitQuestGun(n, "pistolsalt",	 "saltjar",   	    "JRH13", 13,    "", "",      "", 1, 0.1,	 "", "",               	   "",                "", 0);    //alchemy salt
  n = InitQuestGun(n, "pistolnitre",	 "nitresack",       "JRH13", 15,    "", "",      "", 1, 0.1,	 "", "",               	   "",                "", 0);    //alchemy nitre
  n = InitQuestGun(n, "pistolcopperas",  "copperasbox",     "JRH13", 14,    "", "",      "", 1, 0.1,	 "", "",               	   "",                "", 0);    //alchemy copperas

  n = InitQuestGun(n, "pistolmap1",	 "pistolmap1",      "JRH10", 13,    "", "",     100, 1, 0.1,	 "", "",               	   "",              "pb", 0);    //wr_ships
  n = InitQuestGun(n, "pistollog",	 "pistollog",       "JRH16",  5,    "", "",     100, 1, 0.1,	 "", "",               	   "",              "pb", 0);    //swamp island

//Q2
  n = InitQuestGun(n, "pistolcalciumsack", "calciumsack",   "JRH30", 14,    "", "",      "", 1, 0.1,	 "", "",               	   "",                "", 0);    //alchemy
  n = InitQuestGun(n, "pistolstonebasket_R","stonebasket_R","JRH30",  8,    "", "",      "", 1, 0.1,	 "", "",               	   "",                "", 0);    //mercury oxide
  n = InitQuestGun(n, "pistolstonebasket_G","stonebasket_G","JRH30",  6,    "", "",      "", 1, 0.1,	 "", "",               	   "",                "", 0);    //limestone
  n = InitQuestGun(n, "pistolstonebasket_M","stonebasket_M","JRH30",  5,    "", "",      "", 1, 0.1,	 "", "",               	   "",                "", 0);    //antimony
  n = InitQuestGun(n, "pistolstonebasket_B","stonebasket_B","JRH30",  7,    "", "",      "", 1, 0.1,	 "", "",               	   "",                "", 0);    //black antimony
  n = InitQuestGun(n, "pistolbucket_dung","bucket_dung",    "JRH21",  3,    "", "",      "", 1, 0.1,	 "", "", 		   "",                "", 0);
  n = InitQuestGun(n, "pistolretort3",	  "retort3",        "JRH30",  4,    "", "",      "", 1, 0.1,	 "", "",               	   "",                "", 1);    //alchemy
  n = InitQuestGun(n, "pistolsulphur_WR", "sulphur_basket_WR","JRH21", 10,  "", "",      "", 1, 0.1,	 "", "",               	   "",                "", 0);    //smaller in WoodesRogers
  n = InitQuestGun(n, "pistolcharcoal_WR","charcoal_jar_WR","JRH21",  6,    "", "",      "", 1, 0.1,	 "", "",               	   "",                "", 0);    //smaller in WoodesRogers
  n = InitQuestGun(n, "pistolfunnel",	 "pistolfunnel",    "JRH30",  2,    "", "",      "", 1, 0.1,	 "", "",               	   "",                "", 1);    //alchemy2
  n = InitQuestGun(n, "pistolcloth",	 "pistolcloth",     "JRH30",  3,    "", "",      "", 1, 0.1,	 "", "",               	   "",                "", 1);    //alchemy
  n = InitQuestGun(n, "pistolbladeBB",	 "pistolbladeBB",   "JRH33",  1,    "", "",     100, 1, 0.1,	 "", "",               	   "",                "", 0);    //
  n = InitQuestGun(n, "pistolbook71",    "pistolbook71",    "JRH35", 15,    "", "", 	"",  0, "",	 "", "", 		   "",                "", 0);    //

//GoldBug
  n = InitQuestGun(n, "revolver",	 "revolver",        "JRH19",  1,    40, 60,      65, 6,   8,	 "", "", "OBJECTS\DUEL\pistol_medium2.wav", "ca", 0);    //
  n = InitQuestGun(n, "pistol204_P",     "pistol204_P",	    "JRH28",  5,    40, 55, 	 50, 2,  20,	 "", "", "OBJECTS\DUEL\pistol_small2.wav",  "pc", 0);	 //pistol204 percussion lock 
  n = InitQuestGun(n, "pistolbedlinen",  "bedlinen",	    "JRH20", 11,    "", "", 	 "", 0,  "",	 "", "", 		   "",              "pb", 0);
  n = InitQuestGun(n, "pistolbucket_nitre","bucket_nitre",  "JRH20", 11,     1,  1, 	100, 1, 0.1,	 "", "", 		   "",                "", 0);
  n = InitQuestGun(n, "pistolbucket_empty","bucket_empty",  "JRH21",  3,     1,  1, 	100, 1, 0.1,	 "", "", 		   "",                "", 0);
  n = InitQuestGun(n, "pistolbucket_water","bucket_water",   "JRH3",  8,     1,  1, 	100, 1, 0.1,	 "", "", 		   "",                "", 0);
  n = InitQuestGun(n, "pistolhand2",	      "invisible",  "JRH10",  8,     1,  1, 	100, 1, 0.1,	 "", "", 		   "",                "", 0);

  n = InitQuestGun(n, "pistolnitre_E",	 "nitresack_E",     "JRH21",  2,    20, 20,     100, 1, 0.1,	 "", "",               	   "",                "", 0);    // 
  n = InitQuestGun(n, "pistolnitre_H",	 "nitresack_H",     "JRH13", 15,    20, 20,     100, 1, 0.1,	 "", "",               	   "",                "", 0);    // 
  n = InitQuestGun(n, "pistolnitre_big_F","nitresack_big_F","JRH21",  1,    20, 20,     100, 1, 0.1,	 "", "",               	   "",                "", 0);    //

  n = InitQuestGun(n, "pistolsulphur_E", "sulphur_basket_E","JRH21",  9,    20, 20,     100, 1, 0.1,	 "", "",               	   "",                "", 0);    //
  n = InitQuestGun(n, "pistolsulphur_H", "sulphur_basket_H","JRH21", 10,    20, 20,     100, 1, 0.1,	 "", "",               	   "",                "", 0);    //
  n = InitQuestGun(n, "pistolsulphur_F", "sulphur_basket_F","JRH21", 11,    20, 20,     100, 1, 0.1,	 "", "",               	   "",                "", 0);    //
  
  n = InitQuestGun(n, "pistolcharcoal_E",  "charcoal_jar_E","JRH21",  5,    20, 20,     100, 1, 0.1,	 "", "",               	   "",                "", 0);    //
  n = InitQuestGun(n, "pistolcharcoal_H",  "charcoal_jar_H","JRH21",  6,    20, 20,     100, 1, 0.1,	 "", "",               	   "",                "", 0);    //
  n = InitQuestGun(n, "pistolcharcoal_F",  "charcoal_jar_F","JRH21",  7,    20, 20,     100, 1, 0.1,	 "", "",               	   "",                "", 0);    //

  n = InitQuestGun(n, "pistolpyrite_E",   "pyritebox",       "JRH21", 13,    20, 20,    100, 1, 0.1,	 "", "",               	   "",              "pb", 0);    //
  n = InitQuestGun(n, "pistolpyrite_H",   "pyritebox",       "JRH21", 14,    20, 20,    100, 1, 0.1,	 "", "",               	   "",              "pb", 0);    //
  n = InitQuestGun(n, "pistolpyrite_F",   "pyritebox",       "JRH21", 15,    20, 20,    100, 1, 0.1,	 "", "",               	   "",                "", 0);    //
  
  n = InitQuestGun(n, "pistolbarrel_gp0", "palka03_B",	     "JRH22", 11,    "", "", 	100, 1, 0.1,	 "", "", 		   "",                "", 0);    //pistolbarrel empty for GP use
  n = InitQuestGun(n, "pistolbarrel_gpW", "palka03_B",	     "JRH22", 11,    "", "", 	100, 1, 0.1,	 "", "", 		   "",                "", 0);    //pistolbarrel wrong mixture
  n = InitQuestGun(n, "pistolbarrel_gpS", "palka03_B",	     "JRH22", 11,    "", "", 	100, 1, 0.1,	 "", "", 		   "",                "", 0);    //pistolbarrel standard GP
  n = InitQuestGun(n, "pistolbarrel_gpF", "palka03_B",	     "JRH22", 11,    "", "", 	100, 1, 0.1,	 "", "", 		   "",                "", 0);    //pistolbarrel fireworks GP

  n = InitQuestGun(n, "pistolsextant2",    "sextant2",	     "JRH24", 11,    "", "", 	100, 1, 0.1,	 "", "", 		   "",                "", 0);    //
  n = InitQuestGun(n, "pistolFWchest","pistolFWchest",       "JRH18", 16,    "", "", 	"",  0, "",	 "", "", 		   "",              "pb", 0);    //fireworks

} 

  //items here: common or quest + common use 
  n = InitQuestBlade(n, "blade3carpets",        "roll_of_carpets",      "", "",   10, 12,     15, 10, 	  "", 0,   0);    //Blade 3 carpets, also in Tortuga

  //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  // JRH <--

  //--------------------------------------------------------------------------------------------------------------------------------------------------
  // Non-trade Non-random special general items
  //------------------------------------------------------------------------------------SKILL ITEM SETTINGS-------------------------------------------
  // GENERAL:  ItemIndex                   picIndex          Price        numneeded  leader      accuracy    repair       sneak   skiptrade
  //           |  itmID      modelID           |   rare         |         |   stack     |  fencing  |  cannons  |  defence  |     |  skiprand
  //           |   |            |  picTexture  |    |  MinLevel | indian  |   |  hidden |   |  sailing  |  grapple  | commerce    |  |  skipequip
  //-----------|---|------------|----------|---|----|----|------|----|----|---|--|------|---|---|---|---|---|---|---|---|---|-----|--|--|--|skipsell--
  // HOLY ITEMS: scheffnow
  //-----------|---|------------|----------|---|----|----|------|----|----|---|--|------|---|---|---|---|---|---|---|---|---|-----|--|--|--|----------
  n = InitItem(n,"holycross1", "",         8,  1, 0.01,  0,     0,   0,   1,  1, 1,    +2, +4,  0, +2, +2, +2,  0,  0,  0,  0,    1, 1, 1, 1);
  n = InitItem(n,"holycross2", "",         8,  2, 0.10,  0,     0,   0,   0,  0, 0,     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,    1, 1, 1, 1);
  n = InitItem(n,"holycross3", "",         8,  3, 0.01,  0,     0,   0,   1,  1, 1,    +2,  0,  0,  0,  0,  0,  0,  0, +4, +4,    1, 1, 1, 1);
  //--------------------------------------------------------------------------------------------------------------------------------------------------
  // TATTOOS:   Alan_Smithee Opium Den & Tattoos
  //-----------|---|------------|----------|---|----|----|------|----|----|---|--|------|---|---|---|---|---|---|---|---|---|-----|--|--|--|----------
  n = InitItem(n,"tatt1",      "",  "medals2", 5, 0.10,  0,     0,   0,   0,  0, 0,     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,    1, 1, 1, 1);
  n = InitItem(n,"tatt2",      "",  "medals2", 7, 0.10,  0,     0,   0,   0,  0, 0,     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,    1, 1, 1, 1);
  n = InitItem(n,"tatt3",      "",  "medals2", 8, 0.10,  0,     0,   0,   0,  0, 0,     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,    1, 1, 1, 1);
  n = InitItem(n,"tatt4",      "",  "medals2", 9, 0.10,  0,     0,   0,   0,  0, 0,     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,    1, 1, 1, 1);
  n = InitItem(n,"tatt5",      "",  "medals2",10, 0.10,  0,     0,   0,   0,  0, 0,     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,    1, 1, 1, 1);
  //-----------|---|------------|----------|---|----|----|------|----|----|---|--|------|---|---|---|---|---|---|---|---|---|-----|--|--|--|----------
  // --> added by SCM for Mateus Santos Quest, modified by Grey Roger
  n = InitItem(n,"Santos_Keys", "",        8, 11, 0.10,  5,     0,   0,   0,  0, 1,     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,    1, 1, 1, 1); // Mateus Santos' keys
  n = InitItem(n,"Santos_Journal1", "",    4,  8, 0.10,  5,  3000,   0,   0,  0, 1,     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,    1, 1, 1, 1); // Mateus Santos' Journal
  n = InitItem(n,"Santos_Journal2", "",    4,  8, 0.10,  5,  3000,   0,   0,  0, 1,     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,    1, 1, 1, 1); // Mateus Santos' Journal
  n = InitItem(n,"Santos_Ring", "",        8, 12, 0.10,  5,  2400,   0,   0,  0, 1,    +2, +1,  0,  0,  0,  0,  0,  0,  0,  0,    0, 1, 1, 1); // Mateus Santos' Ring
  // <-- added by SCM for Mateus Santos Quest
  n = InitItem(n,"Sparrow_Ring", "",        2, 6, 0.10,  5,  3000,   0,   0,  0, 1,    +2, +1,  0,  0,  0,  0,  0,  0,  0,  0,    0, 1, 1, 1); // Jack Sparrow's Ring
  n = InitItem(n,"Sparrow_Ring1", "",       2, 7, 0.10,  5,  2500,   0,   0,  0, 1,    +2, +1,  0,  0,  0,  0,  0,  0,  0,  0,    0, 1, 1, 1); // Jack Sparrow's Ring
  // ccc building kit start -->
  //----------------------------------------------------------------------------------------------------------------------------
  // BUILDING     ItemIndex                                                             planks                     piercing
  // EXTERIORS        | ID                  modelID          chrmodel                      |   money            maxDmg|
  //                  |  |                     |              |           dialog           |    |    crew  minDmg |   |  block
  //------------------|--|---------------------|--------------|-------------|--------------|----|-----|------|----|---|---|-----
  n = InitBLDexterior(n,"house",      "B_house02",    "B_man",        "b_house.c",        20,  4000,  3,   1.0, 2.0,  0, 20 );  // house
  n = InitBLDexterior(n,"workshop",   "B_workshop",   "B_worker",     "b_workshop.c",     20,  4000,  3,   1.0, 2.0,  0, 20 );  // workshop
  n = InitBLDexterior(n,"farm",       "B_farm",       "B_farmer",     "B_farm.c",         30,  5000, 10,   1.0, 2.0,  0, 20 );  // farm
  n = InitBLDexterior(n,"mansion",    "B_manor",      "B_girl",       "b_mansion.c",      30, 20000,  5,   1.0, 2.0,  0, 20 );  // mansion
  n = InitBLDexterior(n,"observatory","B_lighthouse", "B_girl",       "b_mansion.c",      30, 20000,  5,   1.0, 2.0,  0, 20 );  // observatory
  n = InitBLDexterior(n,"forest",     "B_leaf",       "B_man",        "b_forest.c",        2,  1000,  5,   1.0, 2.0,  0, 20 );  // forest
  n = InitBLDexterior(n,"jungle",     "b_bigforest",  "B_invisible",  "b_bigforest.c",    20,  1000,  5,   1.0, 2.0,  0, 20 );  // BIG forest added Feb06
  n = InitBLDexterior(n,"jungle2",    "b_leaf",       "B_invisible",  "b_bigforest.c",     2,  1000,  5,   1.0, 2.0,  0, 20 );  // small forest added Feb06
  n = InitBLDexterior(n,"College",    "b_college",    "B_invisible",  "B_invisible.c",    40, 10000,  5,   1.0, 2.0,  0, 20 );  // College  added Feb06
  n = InitBLDexterior(n,"church",     "b_church",     "B_invisible",  "B_invisible.c",    40, 10000,  5,   1.0, 2.0,  0, 20 );  // church added Feb06
  n = InitBLDexterior(n,"barracks",   "b_barracks",   "B_invisible",  "B_invisible.c",    40, 10000,  5,   1.0, 2.0,  0, 20 );  // barracks added Feb06
  n = InitBLDexterior(n,"windmill",   "b_windmill",   "B_invisible",  "B_invisible.c",    40, 10000,  5,   1.0, 2.0,  0, 20 );  // windmill added Feb06
  n = InitBLDexterior(n,"shipyard",   "b_shipyard",   "B_worker",     "B_shipyard.c",     40, 10000,  5,   1.0, 2.0,  0, 20 );  // shipyard added Feb06
  n = InitBLDexterior(n,"shipyard2",  "b_shipyard",   "B_worker",     "B_shipyard2.c",    40, 10000,  5,   1.0, 2.0,  0, 20 );  // PB: Shipyard that doesn't function
  n = InitBLDexterior(n,"warehouse",  "b_warehouse",  "B_invisible",  "B_invisible.c",    40, 10000,  5,   1.0, 2.0,  0, 20 );  // warehouse  added Feb06
  n = InitBLDexterior(n,"warehouse_destroyed","b_warehouse_destroyed",
						      "B_invisible",  "B_invisible.c",    40, 10000,  5,   1.0, 2.0,  0, 20 );  // ruined warehouse added 24/9/20
  n = InitBLDexterior(n,"keep",       "B_keep",       "B_soldier",    "b_keep.c",         30, 20000, 15,   1.0, 2.0,  0, 20 );  // keep
  n = InitBLDexterior(n,"tower",      "B_tower",      "B_soldier",    "b_keep.c",         30, 20000, 15,   1.0, 2.0,  0, 20 );  // Tower (old Keep)
  n = InitBLDexterior(n,"bastion",    "B_town",       "B_soldier",    "b_fortification.c",30, 10000, 15,   1.0, 2.0,  0, 20 );  // bastion
  n = InitBLDexterior(n,"townwalls",  "B_townwalls",  "B_soldier",    "b_fortification.c",90, 50000, 30,   1.0, 2.0,  0, 20 );  // townwalls  added Feb06  used for Antigua
  n = InitBLDexterior(n,"box",        "B_box",        "B_invisible",  "b_box.c",           2,   100,  0,   1.0, 2.0,  0, 20 );  // box
  n = InitBLDexterior(n,"fence",      "B_fence",      "B_soldier",    "b_fortification.c",10,  1000,  5,   1.0, 2.0,  0, 20 );  // stockade fence
  n = InitBLDexterior(n,"fence2",     "B_fence",      "B_invisible",  "",                 10,  1000,  5,   1.0, 2.0,  0, 20 );  // stockade fence
  n = InitBLDexterior(n,"bastion2",   "B_town",       "B_invisible",  "",                 30, 10000, 15,   1.0, 2.0,  0, 20 );  // bastion
  n = InitBLDexterior(n,"keep2",      "B_keep",       "B_invisible",  "",                 30, 20000, 15,   1.0, 2.0,  0, 20 );  // keep
  n = InitBLDexterior(n,"bale",       "B_Bale",       "B_invisible",  "b_box.c",           2,   100,  0,   1.0, 2.0,  0, 20 );  // Bale
  n = InitBLDexterior(n,"entrance",   "B_entrance",   "B_invisible",  "",                 20,  4000,  3,   1.0, 2.0,  0, 20 );  // entrance
  n = InitBLDexterior(n,"wall",       "B_wall",       "B_invisible",  "",                 20,  4000,  3,   1.0, 2.0,  0, 20 );  // wall
  n = InitBLDexterior(n,"Sign",       "B_sign",       "B_invisible",  "",                 20,  4000,  3,   1.0, 2.0,  0, 20 );  // Sign
  n = InitBLDexterior(n,"keep3",      "B_keep3",      "B_soldier",    "b_keep.c",         30, 20000, 15,   1.0, 2.0,  0, 20 );  // bigger keep
  n = InitBLDexterior(n,"tower2",     "B_tower2",     "B_invisible",  "b_keep.c",         30, 20000, 15,   1.0, 2.0,  0, 20 );  // Tower with gallows
  n = InitBLDexterior(n,"cannonb",    "B_cannonb",    "B_invisible",  "",                 30, 10000, 15,   1.0, 2.0,  0, 20 );  // big cannon
  n = InitBLDexterior(n,"cannonl",    "B_cannonl",    "B_invisible",  "",                 30, 10000, 15,   1.0, 2.0,  0, 20 );  // small cannon
  n = InitBLDexterior(n,"hut",        "B_hut",        "B_invisible",  "",                 20,  4000,  3,   1.0, 2.0,  0, 20 );  // hut
  n = InitBLDexterior(n,"boxes",      "B_boxes",      "B_invisible",  "b_box.c",           2,   100,  0,   1.0, 2.0,  0, 20 );  // boxes
  n = InitBLDexterior(n,"chain",      "B_chain",      "B_invisible",  "",                 20,  4000,  3,   1.0, 2.0,  0, 20 );  // chain
  n = InitBLDexterior(n,"gallows",    "B_gallows",    "B_invisible",  "",                 20,  4000,  3,   1.0, 2.0,  0, 20 );  // gallows
  n = InitBLDexterior(n,"hutindy",    "B_hutindy",    "B_invisible",  "",                 20,  4000,  3,   1.0, 2.0,  0, 20 );  // indian hut
  n = InitBLDexterior(n,"ladder",     "B_ladder",     "B_invisible",  "",                 20,  4000,  3,   1.0, 2.0,  0, 20 );  // ladder
  n = InitBLDexterior(n,"roche",      "B_roche",      "B_invisible",  "",                 20,  4000,  3,   1.0, 2.0,  0, 20 );  // roche brasiliano
  n = InitBLDexterior(n,"grapnel",    "B_grapnel",    "B_invisible",  "",                 20,  4000,  3,   1.0, 2.0,  0, 20 );  // grapnel
  n = InitBLDexterior(n,"tent",       "B_tent",       "B_invisible",  "B_invisible.c",    40, 10000,  5,   1.0, 2.0,  0, 20 );  // military tent
  n = InitBLDexterior(n,"pit",        "B_pit",        "B_invisible",  "",                 20,  4000,  3,   1.0, 2.0,  0, 20 );  // fire pit
  n = InitBLDexterior(n,"fontain",    "B_fontain",    "B_invisible",	"",               20,  4000,  3,   1.0, 2.0,  0, 20 ); 	// fountain
  n = InitBLDexterior(n,"fontain2",   "B_fontain2",   "B_invisible",	"",               20,  4000,  3,   1.0, 2.0,  0, 20 ); 	// small fountain
  n = InitBLDexterior(n,"hedgerow",   "B_hedgerow",   "B_invisible",	"",               20,  4000,  3,   1.0, 2.0,  0, 20 ); 	// hedgerow
  n = InitBLDexterior(n,"hedgerow2",  "B_hedgerow2",  "B_invisible",	"",               20,  4000,  3,   1.0, 2.0,  0, 20 ); 	// hedgerow2
  n = InitBLDexterior(n,"boulder",    "B_boulder",    "B_invisible",	"",                2,   100,  3,   1.0, 2.0,  0, 20 ); 	// boulder / rock
  n = InitBLDexterior(n,"Field_Cannon_1",     "Field_Cannon_1",     "B_invisible", "",    30, 10000, 15,   1.0, 2.0,  0, 20 );  // iron field cannon
  n = InitBLDexterior(n,"Field_Cannon_1x2",   "Field_Cannon_1x2",   "B_invisible", "",    30, 10000, 15,   1.0, 2.0,  0, 20 );  // iron double-barrel field cannon
  n = InitBLDexterior(n,"Field_Cannon_2",     "Field_Cannon_2",     "B_invisible", "",    30, 10000, 15,   1.0, 2.0,  0, 20 );  // bronze field cannon
  n = InitBLDexterior(n,"Field_Cannon_2x2",   "Field_Cannon_2x2",   "B_invisible", "",    30, 10000, 15,   1.0, 2.0,  0, 20 );  // bronze double-barrel field cannon
  n = InitBLDexterior(n,"Field_Cannon_3",     "Field_Cannon_3",     "B_invisible", "",    30, 10000, 15,   1.0, 2.0,  0, 20 );  // black field cannon
  n = InitBLDexterior(n,"Field_Cannon_3x2",   "Field_Cannon_3x2",   "B_invisible", "",    30, 10000, 15,   1.0, 2.0,  0, 20 );  // black double-barrel field cannon
  n = InitBLDexterior(n,"Field_Cannon_broken","Field_Cannon_broken","B_invisible", "",    30, 10000, 15,   1.0, 2.0,  0, 20 );  // broken iron field cannon

  n = InitBLDexterior(n,"dovecote",   "b_dovecote",   "B_invisible",  "B_invisible.c",    40, 10000,  5,   1.0, 2.0,  0, 20 );  // JRH special for quest in Tortuga
  n = InitBLDexterior(n,"stone_floor","b_stone_floor","B_invisible",  "B_invisible.c",    40, 10000,  5,   1.0, 2.0,  0, 20 );  // JRH special for quest in Tortuga

  n = InitBLDexterior(n,"Totem1",     "B_Totem1",      "B_invisible",  "",                 2,   100,  5,   1.0, 2.0,  0, 20 );  // Indian totems
  n = InitBLDexterior(n,"Totem2",     "B_Totem2",      "B_invisible",  "",                 2,   100,  5,   1.0, 2.0,  0, 20 );
  n = InitBLDexterior(n,"Totem3",     "B_Totem3",      "B_invisible",  "",                 2,   100,  5,   1.0, 2.0,  0, 20 );
  n = InitBLDexterior(n,"Totem4",     "B_Totem4",      "B_invisible",  "",                 2,   100,  5,   1.0, 2.0,  0, 20 );
  n = InitBLDexterior(n,"Tipi2",      "B_tipi2",       "B_invisible",  "",                 5,  1000,  5,   1.0, 2.0,  0, 20 );	// Indian tepee
  n = InitBLDexterior(n,"Tipi3",      "B_tipi3",       "B_invisible",  "",                 5,  1000,  5,   1.0, 2.0,  0, 20 );	// Indian tepee

  //-----------------------------------------------------------------------------------------------------------------------------
  // BUILDING     ItemIndex                                  planks         Charges              Accuracy
  // INTERIORS        | ID                  modelID            |   money       |  Speed      maxDmg  |
  //                  |  |                     |               |    |   crew   |   |   minDmg  |     |
  //------------------|--|---------------------|---------------|----|----|-----|---|-----|-----|-----|---------------------------
  n = InitBLDinterior(n,"Windmillfan",        "B_Windmillfan", 5,  5000, 3,    1, 10,   10.0, 10.0,  80 );   // Fan for windmill
  n = InitBLDinterior(n,"marketstall",        "B_market",      5,  5000, 3,    1, 10,   10.0, 10.0,  80 );   // marketstall
  n = InitBLDinterior(n,"luxurious furniture","B_furniture",   5,  1000, 1,    1,  1,   10.0, 10.0,  80 );   // luxurious furniture
  n = InitBLDinterior(n,"boudoir",            "B_boudoir",     5,  1000, 1,    1,  1,   10.0, 10.0,  80 );   // boudoir
  n = InitBLDinterior(n,"office",             "B_office",      5,  1000, 1,    1,  1,   10.0, 10.0,  80 );   // office
  n = InitBLDinterior(n,"mine",               "B_derrick",    10,  4000, 5,    1, 10,   10.0, 10.0,  80 );   // mine
  n = InitBLDinterior(n,"dock",               "B_dock",       10,  4000, 5,    1, 10,   10.0, 10.0,  80 );   // dock
  n = InitBLDinterior(n,"distillery",         "B_distillery", 10,  4000, 5,    1, 10,   10.0, 10.0,  80 );   // distillery
  n = InitBLDinterior(n,"foundry",            "B_foundry",    10,  4000, 5,    1, 10,   10.0, 10.0,  80 );   // foundry
  n = InitBLDinterior(n,"Cannon",             "B_Cannon",      1,  5000, 5,    1, 10,  200.0,300.0,  70 );   // Cannon
  //--------------------------------------------------------------------------------------------------------------------------------
  // ccc building kit end <--

  // --> added by JRH for Woodes Rogers Quest
  //--------------------------------------------------------------------------------------------------------------------------------
  // BUILDING ITEMS JRH:	itmID
  //	              ItemIndex  |     		    	         model
  //----------------------|------|---------------------------------|----------------------------------------------------------------
//all items are available for all storylines JRH
  n = InitBuildingItemJRH(n,	"toolchest1",  			"toolchest"); 		//Carpenterґs chest - start mode

  n = InitBuildingItemJRH(n,	"brF4R",  			"Flotsam4R"); 		//broken roof pieces
  n = InitBuildingItemJRH(n,	"brF11",  			"Flotsam11");
  n = InitBuildingItemJRH(n,	"brF12",  			"Flotsam12");
  n = InitBuildingItemJRH(n,	"brF12horiz",  			"Flotsam12horiz");
  n = InitBuildingItemJRH(n,	"brF13",  			"Flotsam13");
  n = InitBuildingItemJRH(n,	"brF14R", 			"Flotsam14R");
  n = InitBuildingItemJRH(n,	"brF15",  			"Flotsam15");
  n = InitBuildingItemJRH(n,	"brF15Down",			"Flotsam15Down");
  n = InitBuildingItemJRH(n,	"brF16",  			"Flotsam16");
  n = InitBuildingItemJRH(n,	"brF17",  			"Flotsam17");
  n = InitBuildingItemJRH(n,	"brF17W",  			"Flotsam17_wreck");
  n = InitBuildingItemJRH(n,	"brF17R", 			"Flotsam17R");
  n = InitBuildingItemJRH(n,	"brF7R",  			"Flotsam7R");		//broken roof pieces

  n = InitBuildingItemJRH(n,	"koster1",  			"koster1");		//burned palisade
  n = InitBuildingItemJRH(n,	"koster2",  			"koster2");		//burned palisade
  n = InitBuildingItemJRH(n,	"koster3",  			"koster3");		//burned palisade
  n = InitBuildingItemJRH(n,	"koster4",  			"koster4");		//burned palisade
  n = InitBuildingItemJRH(n,	"koster5",  			"koster5");		//koster3 45

  n = InitBuildingItemJRH(n,	"gatedoor_small_N06",		"gatedoor_small_N06");	//mine
  n = InitBuildingItemJRH(n,	"gatedoor_semi_small",		"gatedoor_semi_small");	//shipyard loft
  n = InitBuildingItemJRH(n,	"gatedoor_very_small",		"gatedoor_very_small");
  n = InitBuildingItemJRH(n,	"gatedoor_vsmall_BRG",		"gatedoor_vsmall_BRG");	//in blue cavern
  n = InitBuildingItemJRH(n,	"gatedoor_vsmall_HUT",		"gatedoor_vsmall_HUT"); //in prison
  n = InitBuildingItemJRH(n,	"gatedoor_vsmall_HUTR",		"gatedoor_vsmall_HUTR");//in prison
  n = InitBuildingItemJRH(n,	"gatedoor_vsmall_GSH",		"gatedoor_vsmall_GSH"); //to shop
  n = InitBuildingItemJRH(n,	"gatedoor_vsmall_GSHR",		"gatedoor_vsmall_GSHR");//to shop upside down
  n = InitBuildingItemJRH(n,	"gatedoor_vsmall_GN3",		"gatedoor_vsmall_GN3"); //pair to tav 03
  n = InitBuildingItemJRH(n,	"gatedoor_vsmall_GN3R",		"gatedoor_vsmall_GN3R");//pair to tav 03 upside down
  n = InitBuildingItemJRH(n,	"gatedoor_small_stone",		"gatedoor_small_stone");
  n = InitBuildingItemJRH(n,	"gatedoor_w_45",		"gatedoor_w_45");	//woodwall 45 degrees: corridor normal
  
  n = InitBuildingItemJRH(n,	"gatedoor_wR",			"gatedoor_wR");		//woodwall dark is down
  n = InitBuildingItemJRH(n,	"gatedoor_w5",			"gatedoor_w5");		//gatedoor to library, woodwall
  n = InitBuildingItemJRH(n,	"gatedoor_w6",			"gatedoor_w6");		//gatedoor back to mine, woodwall
  n = InitBuildingItemJRH(n,	"gatedoor_w7",			"gatedoor_w7");		//gatedoor metal blue cavern to shore
  n = InitBuildingItemJRH(n,	"gatedoor_wN",			"gatedoor_wN");		//door N, woodwall
  n = InitBuildingItemJRH(n,	"gatedoor_p",			"gatedoor_p");		//plankwall (vertical)
  n = InitBuildingItemJRH(n,	"gatedoor_pgreen",		"gatedoor_pgreen");	//plankwall more green (vertical)
  n = InitBuildingItemJRH(n,	"gatedoor_pgrey",		"gatedoor_pgrey");	//plankwall grey (vertical)
  n = InitBuildingItemJRH(n,	"gatedoor_mi",			"gatedoor_mi");		//stockwall mine
  n = InitBuildingItemJRH(n,	"gatedoor_5",			"gatedoor_5");		//gatedoor to library from storeroom
  n = InitBuildingItemJRH(n,	"gatedoor_p5",			"gatedoor_p5");		//gatedoor to library from storeroom with planks
  n = InitBuildingItemJRH(n,	"gatedoor_Res2",		"gatedoor_Res2");	//gatedoor to poker room from entre
  n = InitBuildingItemJRH(n,	"gatedoor_stone",		"gatedoor_stone");	//stonewall gps, mine tunnelA lights
  n = InitBuildingItemJRH(n,	"gatedoor_white_stone",		"gatedoor_white_stone");//stonewall food cellar
  n = InitBuildingItemJRH(n,	"gatedoor_white_stone_90",	"gatedoor_white_stone_90");//stonewall Cayman town
  n = InitBuildingItemJRH(n,	"gatedoor_store4_wall",		"gatedoor_store4_wall");//wall food cellar
  n = InitBuildingItemJRH(n,	"gatedoor_CRY",			"gatedoor_CRY");	//chapel_stairs
  n = InitBuildingItemJRH(n,	"gatedoor_GC2",			"gatedoor_GC2");	//crypt to Rdm church (just wall)
  n = InitBuildingItemJRH(n,	"gatedoor_CR2",			"gatedoor_CR2");	//crypt to Rdm church (door)
  n = InitBuildingItemJRH(n,	"gatedoor_Mine",		"gatedoor_Mine");	//mine stone tunnel wall, attic stairs, corridor normal
 
  n = InitBuildingItemJRH(n,	"gatedoor_CAB",			"gatedoor_CAB");	//wall outer cabin
  n = InitBuildingItemJRH(n,	"gatedoor_LH1",			"gatedoor_LH1");	//wood_tower2 (as a door)
  n = InitBuildingItemJRH(n,	"gatedoor_WT1",			"gatedoor_WT1");	//wood_tower2
  n = InitBuildingItemJRH(n,	"gatedoor_WT2",			"gatedoor_WT2");	//wood_tower2 upside down
  n = InitBuildingItemJRH(n,	"gatedoor_PYR",			"gatedoor_PYR");	//BOP: inside pyramid
  n = InitBuildingItemJRH(n,	"gatedoor_PRI",			"gatedoor_PRI");	//prison office

  n = InitBuildingItemJRH(n,	"gatefloor_w",			"gatefloor_w");		//horizontal
  n = InitBuildingItemJRH(n,	"gatefloor_w2",			"gatefloor_w2");	//horizontal, no handles
  n = InitBuildingItemJRH(n,	"gateroof_white_stone",		"gateroof_white_stone");//horizontal, upside down
  n = InitBuildingItemJRH(n,	"gateroof_wood",		"gateroof_wood");	//attic_stairs + animists_stairs

  n = InitBuildingItemJRH(n,	"door_N",			"door_N");		//door N default
  n = InitBuildingItemJRH(n,	"door_NGR",			"door_NGR");		//door N grey
  n = InitBuildingItemJRH(n,	"door_N01",			"door_N01");		//door N redbrown
  n = InitBuildingItemJRH(n,	"door_N02",			"door_N02");		//library: green frame
  n = InitBuildingItemJRH(n,	"door_A02",			"door_A02");		//library to gunroom
  n = InitBuildingItemJRH(n,	"door_A02R",			"door_A02R");		//library to gunroom, upside down
  n = InitBuildingItemJRH(n,	"door_A03",			"door_A03");		//gps to gunroom
  n = InitBuildingItemJRH(n,	"door_A03R",			"door_A03R");		//gps to gunroom, upside down

  n = InitBuildingItemJRH(n,	"door_A05R",			"door_A05R");		//sacristy reversed
  n = InitBuildingItemJRH(n,	"door_A05B",			"door_A05B");		//black
  n = InitBuildingItemJRH(n,	"door_N04",			"door_N04");		//residence brown art noveau
  n = InitBuildingItemJRH(n,	"door_N04R",			"door_N04R");		//residence brown art noveau upside down
  n = InitBuildingItemJRH(n,	"door_N44",			"door_N44");		//pirate churc
  n = InitBuildingItemJRH(n,	"door_N44T",			"door_N44T");		//pirate church 90 degrees
  n = InitBuildingItemJRH(n,	"door_N05",			"door_N05");		//library brown
  n = InitBuildingItemJRH(n,	"door_N05R",			"door_N05R");		//library brown upside down
  n = InitBuildingItemJRH(n,	"door_N05L",			"door_N05L");		//library brown lying down, a little bigger too
  n = InitBuildingItemJRH(n,	"door_N06",			"door_N06");		//mine, shop office to roof
 
  n = InitBuildingItemJRH(n,	"door_N07",			"door_N07");		//storesmall
  n = InitBuildingItemJRH(n,	"door_A01",			"door_A01");		//tavern storeroom
  n = InitBuildingItemJRH(n,	"door_N08",			"door_N08");		//crew wall - no real door
  n = InitBuildingItemJRH(n,	"door_N09",			"door_N09");		//shop office to wr mother
  n = InitBuildingItemJRH(n,	"door_N10",			"door_N10");		//crew tavern: in kitchen
  n = InitBuildingItemJRH(n,	"door_N11",			"door_N11");		//shore to blue cavern
  n = InitBuildingItemJRH(n,	"door_N11R",			"door_N11R");		//upside down
  n = InitBuildingItemJRH(n,	"door_M12",			"door_M12");		//fake bookshelf, a little bigger door
  n = InitBuildingItemJRH(n,	"door_H1",			"door_H1");		//metal door in deck2_prow
  n = InitBuildingItemJRH(n,	"door_largeh",			"door_largeh");		//servant, corridor normal
  
  n = InitBuildingItemJRH(n,	"door_largeh2",			"door_largeh2");	//claire's house
  n = InitBuildingItemJRH(n,	"doubledoor",			"doubledoor");		//tavern upstairs
  n = InitBuildingItemJRH(n,	"door_sklad",			"door_sklad");		//wr_crew, farm_kitchen = 'add'
  n = InitBuildingItemJRH(n,	"door_shya",			"door_shya");		//inside shipyard (FF port2)
  n = InitBuildingItemJRH(n,	"door_LBR",			"door_LBR");		//inside New cloister Cartagena

  n = InitBuildingItemJRH(n,	"hatch1",			"hatch1");		//roof hatch (outside, QC)
  n = InitBuildingItemJRH(n,	"hatch3",			"hatch3");		//roof hatch tavern storeroom
  n = InitBuildingItemJRH(n,    "hatch3U",			"hatch3U");		//prison cell floor (hatch3 up)
  n = InitBuildingItemJRH(n,    "hatch3U_T",			"hatch3U_T");		//prison cell floor (hatch3U open)
  n = InitBuildingItemJRH(n,	"hatch3V",			"hatch3V");		//farm servant window
  n = InitBuildingItemJRH(n,	"hatch4",			"hatch4");		//roof hatch shop office
  n = InitBuildingItemJRH(n,	"hatch5",			"hatch5");		//ship hatch galley, tilted
  n = InitBuildingItemJRH(n,	"hatch5_A",			"hatch5_A");		//ship hatch galley, vertical closed
  n = InitBuildingItemJRH(n,	"hatch5_B",			"hatch5_B");		//ship hatch galley, vertical closed upside down
  n = InitBuildingItemJRH(n,	"hatch6",			"hatch6");		//ship hatch galley, horizontal
  n = InitBuildingItemJRH(n,	"hatch7",			"hatch7");		//counter crew quarters
  n = InitBuildingItemJRH(n,	"hatch8",			"hatch8");		//prison cell wall: pistol106 chest
  n = InitBuildingItemJRH(n,	"hatch8_tilt",			"hatch8_tilt");		//prison cell wall:  stuck at 45
  n = InitBuildingItemJRH(n,    "hatch9",			"hatch9");		//prison cell floor: black
  n = InitBuildingItemJRH(n,    "hatch10",			"hatch10");		//dungeon4 to guard
  n = InitBuildingItemJRH(n,	"hatch11D",			"hatch11D");		//roof hatch dungeon3 (darker)
  n = InitBuildingItemJRH(n,	"hatch11D_O",			"hatch11D_O");		//roof hatch dungeon3 (darker) open
  n = InitBuildingItemJRH(n,	"hatch12",			"hatch12");		//ships floor hatch
  n = InitBuildingItemJRH(n,	"hatch12R",			"hatch12R");		//ships ceiling hatch
  n = InitBuildingItemJRH(n,	"hatch13",			"hatch13");		//ships floor hatch metal
  n = InitBuildingItemJRH(n,	"hatch13R",			"hatch13R");		//ships ceiling hatch metal
  n = InitBuildingItemJRH(n,	"hatch14",			"hatch14");		//tavern_upstairs
  n = InitBuildingItemJRH(n,	"hatch11_T",			"hatch11_T");		//wood tower
  n = InitBuildingItemJRH(n,	"hatch11_O",			"hatch11_O");		//wood tower
  n = InitBuildingItemJRH(n,	"hatch11V",			"hatch11V");		//loghouse

  n = InitBuildingItemJRH(n,	"cannonball_box",		"B_box");		//armory
  n = InitBuildingItemJRH(n,	"cannonball_box2",		"B_box");		//armory
  n = InitBuildingItemJRH(n,	"2groups_of_boxes",		"2groups_of_boxes");	//Deck1_yellow

  n = InitBuildingItemJRH(n,	"rope_horizontal",		"ROPE_horizontal");
  n = InitBuildingItemJRH(n,	"rope_vertical",		"ROPE_vertical");
  n = InitBuildingItemJRH(n,	"rope_vertical_long",		"ROPE_vertical_long");	//very long, Bishops Hostel 
  n = InitBuildingItemJRH(n,	"rope_horizontal_long",		"ROPE_horizontal_long");//very long, careen shore  
  n = InitBuildingItemJRH(n,	"rope_45_long",			"ROPE_45_long");	//careen shore
  n = InitBuildingItemJRH(n,	"rope_vertical_bright",		"ROPE_vertical_bright");
  n = InitBuildingItemJRH(n,	"hook",				"hook");

  n = InitBuildingItemJRH(n,	"chain_horizontal",		"CHAIN_horizontal");	//BB_careen_holdS

  n = InitBuildingItemJRH(n,	"mast_bridge",			"Flotsam14R_dark");	//mast as a bridge
  n = InitBuildingItemJRH(n,	"lever_up",			"lever_up");
  n = InitBuildingItemJRH(n,	"lever_down",			"lever_down");
  n = InitBuildingItemJRH(n,	"lever_base",			"lever_base");		//in wr_crew, else as 'add'
  n = InitBuildingItemJRH(n,	"lever3_up",			"lever3_up");		//mine control: arm1 coas as lever
  n = InitBuildingItemJRH(n,	"lever3_down",			"lever3_down");
  n = InitBuildingItemJRH(n,	"steplock",			"steplock");
  n = InitBuildingItemJRH(n,	"steplock2",			"steplock2");		//brighter in dark prison
  n = InitBuildingItemJRH(n,	"steplock3",			"steplock3");		//lighter in temple
  n = InitBuildingItemJRH(n,	"steplock_v",			"steplock_v");		//on study wall for levers
  n = InitBuildingItemJRH(n,	"steplock_v3",			"steplock_v3");		//in mine control for lever3

  n = InitBuildingItemJRH(n,	"brderrick",			"derrick_tilt");
  n = InitBuildingItemJRH(n,	"sack",				"sack");
  n = InitBuildingItemJRH(n,	"basket",  			"basket");
  n = InitBuildingItemJRH(n,	"barrel_big",			"barrel");
  n = InitBuildingItemJRH(n,	"barrel_roll",			"barrel_roll");
  n = InitBuildingItemJRH(n,	"barrel3",			"barrel3");		//water barrel inner cabin
  n = InitBuildingItemJRH(n,	"bed2",				"bed2");		//bed brighter red (library curtain)
  n = InitBuildingItemJRH(n,	"bookshelf",			"bookshelf");		//bookshelf, used once in tavern storeroom
  n = InitBuildingItemJRH(n,	"bookshelf2",			"bookshelf2");		//brighter bookshelf
  n = InitBuildingItemJRH(n,	"bookshelf4",			"bookshelf4");		//brighter bookshelf, using backside
  n = InitBuildingItemJRH(n,	"textile",			"textile");		//textile tilted: tent
  n = InitBuildingItemJRH(n,	"textile2",			"textile2");		//textile tilted: carpet
  n = InitBuildingItemJRH(n,	"textileA",			"textileA");		//textile: sailcloth
  n = InitBuildingItemJRH(n,	"textileB",			"textileB");		//textile: curtain
  n = InitBuildingItemJRH(n,	"clock",			"clock");
  n = InitBuildingItemJRH(n,	"clock_big",			"clock_big");
  n = InitBuildingItemJRH(n,	"clock_big2",			"clock_big2");		//big clock2 is just a little smaller
  n = InitBuildingItemJRH(n,	"globe",			"globe");
  n = InitBuildingItemJRH(n,	"distillery_tank",		"distillery_tank");
  n = InitBuildingItemJRH(n,	"cannon_pipe",			"cannon_pipe");		//pipe to distillery
  n = InitBuildingItemJRH(n,	"cannon_pipe2",			"cannon_pipe2");	//pipe to wr_corvdeck1 (a little bigger)
  n = InitBuildingItemJRH(n,	"distillery_lid",		"distillery_lid");
  n = InitBuildingItemJRH(n,	"damper_closed",		"damper_closed");
  n = InitBuildingItemJRH(n,	"damper_half",			"damper_half");
  n = InitBuildingItemJRH(n,	"damper_open",			"damper_open");
  n = InitBuildingItemJRH(n,	"smuggler_goods",		"STORES_X");		//shipyard loft
  n = InitBuildingItemJRH(n,	"chest1",			"ChestWithBottles_x");  //tav storeroom, armory m.fl
  n = InitBuildingItemJRH(n,	"chest1_vco",			"chest1_vco");		//vco chest, aop texture
  n = InitBuildingItemJRH(n,	"chest3L_vco",			"chest3L_vco");		//vco chest in cavern, Locked
  n = InitBuildingItemJRH(n,	"chest3U_vco",			"chest3U_vco");		//vco chest in cavern, Unlocked
  n = InitBuildingItemJRH(n,	"chest3",			"Small_ChestWithBottles");//crew tavern
  n = InitBuildingItemJRH(n,	"chest4_coas",			"chest4_coas");		//stevensons chest in wr_secret
  n = InitBuildingItemJRH(n,	"chest5_coas",			"chest5_coas");		//flagchest in wood_tower2
  n = InitBuildingItemJRH(n,	"chest6U_vco",			"chest6U_vco");		//
  n = InitBuildingItemJRH(n,	"torch42",			"torch42");		//vco torch 4002142
  n = InitBuildingItemJRH(n,	"periscope_tilted",		"periscope_tilted");

  n = InitBuildingItemJRH(n,	"gibbet1",			"gibbet1");		//45 up skeleton
  n = InitBuildingItemJRH(n,	"gibbet2",			"gibbet2");		//45 down
  n = InitBuildingItemJRH(n,	"gibbet3",			"gibbet3");		//45 up
  n = InitBuildingItemJRH(n,	"gibbet4",			"gibbet4");		//horizontal

  n = InitBuildingItemJRH(n,	"pole2",			"pole2");		//bladeboom vertical big
  n = InitBuildingItemJRH(n,	"pole3",			"pole3");		//bladeboom horizontal
  n = InitBuildingItemJRH(n,	"plank1",			"plank1");		//bladeplank on the edge
  n = InitBuildingItemJRH(n,	"plank1_dark",			"plank1_dark");		//bladeplank on the edge
  n = InitBuildingItemJRH(n,	"plank1_long",			"plank1_long");		//bladeplank on the edge (deck2 prow 2 st)
  n = InitBuildingItemJRH(n,	"plank1_very_long",		"plank1_very_long");	//Maltains
  n = InitBuildingItemJRH(n,	"plank2",			"plank2");		//bladeplank flat
  n = InitBuildingItemJRH(n,	"plank2_dark",			"plank2_dark");		//bladeplank flat
  n = InitBuildingItemJRH(n,	"plank2_long",			"plank2_long");		//big plank flat (hold)
  n = InitBuildingItemJRH(n,	"plank2_very_long_dark",	"plank2_very_long_dark");//careen_shore
  n = InitBuildingItemJRH(n,	"plank3",			"plank3");		//bladeplank 45 up
  n = InitBuildingItemJRH(n,	"temp_plank0",			"temp_plank0");		//2 planks together under elevator (switch to blade resp pistolplank2 when picked up)
  n = InitBuildingItemJRH(n,	"skull2",			"skull2");		//(vertical) blocking floor hatch in cell
  n = InitBuildingItemJRH(n,	"barrel2_roll",			"palka03");		//like bladebarrel but lying down

  n = InitBuildingItemJRH(n,	"storehouse_destroyed",		"storehouse_destroyed");
  n = InitBuildingItemJRH(n,	"church_destroyed",		"church_destroyed");
  n = InitBuildingItemJRH(n,	"mill_destroyed",		"mill_destroyed");
  n = InitBuildingItemJRH(n,	"shipyard1",			"b_shipyard");		//AOP shipyard1
 
  n = InitBuildingItemJRH(n,	"shipwreck2",			"shipwreck2");		//swamp island2: Ceres as an item

  n = InitBuildingItemJRH(n,	"cannonball2",			"cannon_ball");		//cannonball for placing in wall (armory)
  n = InitBuildingItemJRH(n,	"cannon_bigger",		"cannon_bigger");	//cannon tower
  n = InitBuildingItemJRH(n,	"cannon_very_big",		"cannon_very_big");
  n = InitBuildingItemJRH(n,	"cannon_very_big_upside_down",	"cannon_very_big_upside_down");//1 in cave_shore
  n = InitBuildingItemJRH(n,	"Cannonbox",			"Cannonbox");		//cannon tower
  
  n = InitBuildingItemJRH(n,	"musket_item",			"musket_item");		//cannon tower, up
  n = InitBuildingItemJRH(n,	"musket_item2",			"musket_item2");	//cannon tower, down
  n = InitBuildingItemJRH(n,	"chair",			"chair");		//prison guard
  n = InitBuildingItemJRH(n,	"chair_fallen",			"chair_fallen");	//prison guard

  n = InitBuildingItemJRH(n,	"boat2",			"boat2");		//empty AOP boat
 
  n = InitBuildingItemJRH(n,	"boat3",			"boat3");		//boat3 on land (large)
  n = InitBuildingItemJRH(n,	"boat4",			"boat4");		//boat4 on land (white)

  n = InitBuildingItemJRH(n,	"rock1",			"rock1");		//
  n = InitBuildingItemJRH(n,	"rock2",			"rock2");		//
  n = InitBuildingItemJRH(n,	"window",			"window");		//exterior pirate church
  n = InitBuildingItemJRH(n,	"window2",			"window2");		//blocking door in blue cavern

  n = InitBuildingItemJRH(n,	"ffport02_planks",		"ffport02_planks");	//light brown planks on shya shore
  n = InitBuildingItemJRH(n,	"ladder_hold",			"ladder_hold");		//ladder from deck2 used in hold_A
  n = InitBuildingItemJRH(n,	"ladder_big",			"ladder_big");		//ladder from alchemy up to servant room
  n = InitBuildingItemJRH(n,	"ladder_medium",		"ladder_medium");	//ladder in church_choir

  n = InitBuildingItemJRH(n,	"xebec_wreck",			"xebec_wreck");		//vco xebec as a wreck in shya shore

  n = InitBuildingItemJRH(n,	"hut3",				"hut3");		//Rogers farmhouse
  n = InitBuildingItemJRH(n,	"hut3_C",			"hut3_C");		//Chinatown wood
  n = InitBuildingItemJRH(n,	"stoneH1",			"stoneH1");		//AOP stoneH1
  n = InitBuildingItemJRH(n,	"anvil",			"anvil");
  n = InitBuildingItemJRH(n,	"anvil_tilt",			"anvil_tilt");
  n = InitBuildingItemJRH(n,	"stool",			"stool");		//alchemy

  n = InitBuildingItemJRH(n,	"smg1_A",			"smg1_A");		//goods on shore
  n = InitBuildingItemJRH(n,	"smg3",				"smg3");		//goods on shore
  n = InitBuildingItemJRH(n,	"smg7",				"smg7");		//goods on shore
  n = InitBuildingItemJRH(n,	"smg11",			"smg11");		//goods on shore

  n = InitBuildingItemJRH(n,	"fish02",			"fish02");		//galleon deck prow
  n = InitBuildingItemJRH(n,	"cauldron1",			"cauldron1");		//farm_kitchen
  n = InitBuildingItemJRH(n,	"hammock",			"hammock");		//hold_second
  n = InitBuildingItemJRH(n,	"hammock_ropes",		"hammock_ropes");	//careen deck1
  n = InitBuildingItemJRH(n,	"qcport",			"qcport");		//
  n = InitBuildingItemJRH(n,	"qcport_plan3",			"qcport_plan3");	//
  n = InitBuildingItemJRH(n,	"swamp_island1",		"swamp_island1");	//
  n = InitBuildingItemJRH(n,	"swamp_island2",		"swamp_island2");	//

  n = InitBuildingItemJRH(n,	"chart1",			"chart1");		//farm_bedroom
  n = InitBuildingItemJRH(n,	"chart2A",			"chart2A");		//farm_bedroom
  n = InitBuildingItemJRH(n,	"chart2B",			"chart2B");		//farm_bedroom
  n = InitBuildingItemJRH(n,	"chart2C",			"chart2C");		//farm_bedroom
  n = InitBuildingItemJRH(n,	"chart2D",			"chart2D");		//farm_bedroom
  n = InitBuildingItemJRH(n,	"chart3A",			"chart3A");		//farm_alchemy2
  n = InitBuildingItemJRH(n,	"chart3B",			"chart3B");		//farm_alchemy2
  n = InitBuildingItemJRH(n,	"chart3C",			"chart3C");		//farm_alchemy2
  n = InitBuildingItemJRH(n,	"chart3D",			"chart3D");		//farm_alchemy2
  n = InitBuildingItemJRH(n,	"books1",			"books1");		//farm_servant
  n = InitBuildingItemJRH(n,	"bookcase",			"bookcase");		//farm_servant
  n = InitBuildingItemJRH(n,	"carpet1",			"carpet1");		//farm_servant

  n = InitBuildingItemJRH(n,	"fur1",				"fur1");		//Dave's room
  n = InitBuildingItemJRH(n,	"niche_wall",			"niche_wall");		//farm bedroom behind chart
  n = InitBuildingItemJRH(n,	"FransHals",			"FransHals");		//Friday room

  n = InitBuildingItemJRH(n,	"clockkey",			"clockkey");		//church_choir
  n = InitBuildingItemJRH(n,	"handle",			"handle");		//church_choir
  n = InitBuildingItemJRH(n,	"handle_v",			"handle_v");		//Goldbug: Charleston church
  n = InitBuildingItemJRH(n,	"handle_big",			"handle_big");		//pyramid puzzle
  n = InitBuildingItemJRH(n,	"handle_big_45",		"handle_big_45");	//pyramid puzzle

  n = InitBuildingItemJRH(n,	"stuckkey",			"stuckkey");		//church_choir
  n = InitBuildingItemJRH(n,	"cello",			"cello");		//church_choir
  n = InitBuildingItemJRH(n,	"violin",			"violin");		//church_choir
  n = InitBuildingItemJRH(n,	"flute",			"flute");		//church_choir
  n = InitBuildingItemJRH(n,	"sheet_music",			"sheet_music");		//church_choir
  n = InitBuildingItemJRH(n,	"pillow",			"pillow");		//church_choir
  n = InitBuildingItemJRH(n,	"pillow1",			"pillow1");		//BB_careen_deck1
  n = InitBuildingItemJRH(n,	"pillow1_u",			"pillow1_u");		//BB_careen_deck1
  n = InitBuildingItemJRH(n,	"pillow2",			"pillow2");		//BB_careen_deck1
  n = InitBuildingItemJRH(n,	"pillow2_u",			"pillow2_u");		//BB_careen_deck1
  n = InitBuildingItemJRH(n,	"pillow3",			"pillow3");		//BB_careen_deck1
  n = InitBuildingItemJRH(n,	"pillow3_u",			"pillow3_u");		//BB_careen_deck1
  n = InitBuildingItemJRH(n,	"Lo_jrh_1",			"Lo_jrh_1");		//BB_careen_deck1
  n = InitBuildingItemJRH(n,	"Lo_jrh_2",			"Lo_jrh_2");		//BB_careen_deck1
  n = InitBuildingItemJRH(n,	"Lo_jrh_3",			"Lo_jrh_3");		//BB_careen_deck1
  n = InitBuildingItemJRH(n,	"Lo_jrh_4",			"Lo_jrh_4");		//BB_careen_deck1
  n = InitBuildingItemJRH(n,	"Lo_jrh_5",			"Lo_jrh_5");		//BB_careen_deck1

  n = InitBuildingItemJRH(n,	"rum_party1",			"rum_party1");		//church outside, QAR
  n = InitBuildingItemJRH(n,	"rum_party1_dark",		"rum_party1_dark");	//QAR
  n = InitBuildingItemJRH(n,	"rum_party2",			"rum_party2");		//church outside
  n = InitBuildingItemJRH(n,	"rum_party3",			"rum_party3");		//church outside
  n = InitBuildingItemJRH(n,	"long_table",			"long_table");		//church outside

  n = InitBuildingItemJRH(n,	"lilgun",			"lilgun");		//wood tower
  n = InitBuildingItemJRH(n,	"fallen_tree",			"fallen_tree");		//storm cave_shore

  n = InitBuildingItemJRH(n,	"raft2_logs",			"raft2_logs");		//raft2 item on land without ropes
  n = InitBuildingItemJRH(n,	"raft2_ropes",			"raft2_ropes");		//raft2 item on land with ropes, ready for sea!
  n = InitBuildingItemJRH(n,	"number_plate1",		"number_plate1");
  n = InitBuildingItemJRH(n,	"number_plate2",		"number_plate2");
  n = InitBuildingItemJRH(n,	"number_plate3",		"number_plate3");
  n = InitBuildingItemJRH(n,	"number_plate2_floor",		"number_plate2_floor");
  n = InitBuildingItemJRH(n,	"number_plate4",		"number_plate4");

  n = InitBuildingItemJRH(n,	"build_clock2",			"build_clock2");	//Cartagena
  n = InitBuildingItemJRH(n,	"fire_irons_item",		"fire_irons_item");	//Cartagena
  n = InitBuildingItemJRH(n,	"lever_item",			"lever_item");		//Cartagena
  n = InitBuildingItemJRH(n,	"wall_weapons",			"wall_weapons");	//Cartagena
  n = InitBuildingItemJRH(n,	"confessional",			"confessional");	//Cartagena
  n = InitBuildingItemJRH(n,	"derrick",			"derrick");		//Cartagena
  n = InitBuildingItemJRH(n,	"door_panel",			"door_panel");		//Cartagena

//JRH
//Q2
  n = InitBuildingItemJRH(n,	"ellipse_tower",		"ellipse_tower");	//
  n = InitBuildingItemJRH(n,	"cellar_wall",			"cellar_wall");		// = "B_house02" with an empty inside
  n = InitBuildingItemJRH(n,	"barn",				"barn");		//used for its ladder
  n = InitBuildingItemJRH(n,	"door_largeh2_tilt",		"door_largeh2_tilt");	//Eden passage
  n = InitBuildingItemJRH(n,	"L_bridge",			"L_bridge");		//outside grotto1
  n = InitBuildingItemJRH(n,	"gatedoor_Mine_light",		"gatedoor_Mine_light");	//BB tunnel
  n = InitBuildingItemJRH(n,	"gatedoor_Tower",		"gatedoor_Tower");	//BB tower 
  n = InitBuildingItemJRH(n,	"gatedoor_Tower_45",		"gatedoor_Tower_45");	//BB tower 
  n = InitBuildingItemJRH(n,	"blockdoor",			"blockdoor");		//BB tower
  n = InitBuildingItemJRH(n,	"stoneblock",			"stoneblock");		//BB cave off pist
  n = InitBuildingItemJRH(n,	"gatedoor_KRI",			"gatedoor_KRI");	//Kristiania
  n = InitBuildingItemJRH(n,	"spanish_church",		"spanish_church");	//Kristiania
 
  n = InitBuildingItemJRH(n,	"swedish_stonehouse",		"swedish_stonehouse");	//Kristiania
  n = InitBuildingItemJRH(n,	"fort_tower",			"fort_tower");		//Kristiania
  n = InitBuildingItemJRH(n,	"fort_tower_wall",		"fort_tower_wall");	//Kristiania	
  n = InitBuildingItemJRH(n,	"fort_wall",			"fort_wall");		//Kristiania
  n = InitBuildingItemJRH(n,	"port_tower",			"port_tower");		//Kristiania
  n = InitBuildingItemJRH(n,	"gateroof_church_stone",	"gateroof_church_stone");//horizontal, upside down, nueva suecia
  n = InitBuildingItemJRH(n,	"tourist_spyglass",		"tourist_spyglass");	//BB tower top
  n = InitBuildingItemJRH(n,	"rig",				"rig");			//BB lower cave
  n = InitBuildingItemJRH(n,	"door_fort",			"door_fort");		//BB lower cave

  n = InitBuildingItemJRH(n,	"chest_BB1",			"chest_BB1");		//BB treasure
  n = InitBuildingItemJRH(n,	"chest_BB2",			"chest_BB2");		//BB treasure
  n = InitBuildingItemJRH(n,	"chest_BB3",			"chest_BB3");		//BB treasure

  n = InitBuildingItemJRH(n,	"4_sacks",			"4_sacks");		//BB treasure
  n = InitBuildingItemJRH(n,	"2_sacks",			"2_sacks");		//BB treasure
  n = InitBuildingItemJRH(n,	"cherub",			"cherub");		//BB treasure
  n = InitBuildingItemJRH(n,	"FransHals_45",			"FransHals_45");	//BB treasure
  n = InitBuildingItemJRH(n,	"FransHals_frame45",		"FransHals_frame45");	//BB treasure
  n = InitBuildingItemJRH(n,	"censer_item",			"censer_item");		//BB treasure

  n = InitBuildingItemJRH(n,	"fireplace_wood",		"fireplace_wood");	//BB cave
  n = InitBuildingItemJRH(n,	"ropes_blocks",			"ropes_blocks");	//BB cave
  n = InitBuildingItemJRH(n,	"ropes_blocks_small",		"ropes_blocks_small");	//BOP pyramid
  n = InitBuildingItemJRH(n,	"boom_item",			"boom_item");		//BB cave
  n = InitBuildingItemJRH(n,	"boom_item_metal",		"boom_item_metal");	//alchemy2

  n = InitBuildingItemJRH(n,	"prison_bars",			"prison_bars");		//BB prison2
  n = InitBuildingItemJRH(n,	"prison_building",		"prison_building");	//exterior
  n = InitBuildingItemJRH(n,	"prison_pier",			"prison_pier");		//exterior
  n = InitBuildingItemJRH(n,	"prison_bridge",		"prison_bridge");	//exterior
  n = InitBuildingItemJRH(n,	"door_N_90",			"door_N_90");		//BB prison elevator
  n = InitBuildingItemJRH(n,	"door_R_90",			"door_R_90");		//BB prison
  n = InitBuildingItemJRH(n,	"hanged_man",			"hanged_man");		//BB prison
  n = InitBuildingItemJRH(n,	"gatedoor_elevator",		"gatedoor_elevator");	//BB prison elevator
  n = InitBuildingItemJRH(n,	"gateroof_elevator",		"gateroof_elevator");	//BB prison elevator
  n = InitBuildingItemJRH(n,	"elevator_button_up",		"elevator_button_up");
  n = InitBuildingItemJRH(n,	"elevator_button_down",		"elevator_button_down");

  n = InitBuildingItemJRH(n,	"crate",			"crate");		//BB_alcove
  n = InitBuildingItemJRH(n,	"crate2",			"crate2");		//BB_alcove, on the edge
  n = InitBuildingItemJRH(n,	"door_wreck",			"door_wreck");		//Kristiania_port
  n = InitBuildingItemJRH(n,	"door_N13",			"door_N13");		//gps hold_wreck
  n = InitBuildingItemJRH(n,	"hatch12G",			"hatch12G");		//hold_wreck
  n = InitBuildingItemJRH(n,	"hatch12G_U",			"hatch12G_U");		//hold careen corvette
  n = InitBuildingItemJRH(n,	"AltarPicture",			"AltarPicture");	//Abbess room

  n = InitBuildingItemJRH(n,	"roll_of_rolls",		"roll_of_rolls");	//Tortuga sailmaker
  n = InitBuildingItemJRH(n,	"sailcloth_wall",		"sailcloth_wall");	//Tortuga sailmaker
  n = InitBuildingItemJRH(n,	"sailcloth_floor",		"sailcloth_floor");	//Tortuga sailmaker
  n = InitBuildingItemJRH(n,	"wood_floor",			"wood_floor");		//Tortuga small woddhouse

  n = InitBuildingItemJRH(n,	"door_green",			"door_green");		//Estate maze
  n = InitBuildingItemJRH(n,	"door_window",			"door_window");		//Estate maze
  n = InitBuildingItemJRH(n,	"door_window2",			"door_window2");	//Kristiania
  n = InitBuildingItemJRH(n,	"gatedoor_church_stone",      "gatedoor_church_stone"); //Kristiania church passage

  n = InitBuildingItemJRH(n,	"big_hut",			"big_hut");		//BB isle
  n = InitBuildingItemJRH(n,	"small_hut",			"small_hut");		//BB isle
  n = InitBuildingItemJRH(n,	"sandfloor",			"sandfloor");		//BB isle
  n = InitBuildingItemJRH(n,	"fishingnet",			"fishingnet");		//BB isle

  n = InitBuildingItemJRH(n,	"carpet4S",			"carpet4S");		//jrh room
  n = InitBuildingItemJRH(n,	"IronMaiden",			"IronMaiden");		//prison2
  n = InitBuildingItemJRH(n,	"bonfire",			"bonfire");		//careen_shore
  n = InitBuildingItemJRH(n,	"derrick_broken",		"derrick_broken");	//careen_shore

  n = InitBuildingItemJRH(n,	"guillotine",			"guillotine");		//dungeon_5
  n = InitBuildingItemJRH(n,	"prison_bars_big",		"prison_bars_big");	//dungeon_5
  n = InitBuildingItemJRH(n,	"AltarPicture_big",		"AltarPicture_big");	//dungeon_5
  n = InitBuildingItemJRH(n,	"green2",			"green2");		//dungeon_5
  n = InitBuildingItemJRH(n,	"gatedoor_open",		"gatedoor_open");	//dungeon_5
  n = InitBuildingItemJRH(n,	"irongates",			"irongates");		//dungeon_5
  n = InitBuildingItemJRH(n,	"irongates_open",		"irongates_open");	//dungeon_5
  n = InitBuildingItemJRH(n,	"pitchfork_item",		"pitchfork_item");	//capmd_2

//goldbug
  n = InitBuildingItemJRH(n,	"tipi",				"tipi");
  n = InitBuildingItemJRH(n,	"pirate_house",			"pirate_house");
  n = InitBuildingItemJRH(n,	"pirate_shed",			"pirate_shed");
 
  n = InitBuildingItemJRH(n,	"horse_fence",			"horse_fence");
 
  n = InitBuildingItemJRH(n,	"door_U1",			"door_U1");		//Legrands house
  n = InitBuildingItemJRH(n,	"door_attic",			"door_attic");		//Legrands house
  n = InitBuildingItemJRH(n,	"door_fort",			"door_fort");		//white fort towers

  n = InitBuildingItemJRH(n,	"door_barn",			"door_barn");
  n = InitBuildingItemJRH(n,	"door_PL",			"door_PL");		//plantation dark storerooms
  n = InitBuildingItemJRH(n,	"chimney",			"chimney");		//Chinatown
  n = InitBuildingItemJRH(n,	"stonewall45",			"stonewall45");	
  n = InitBuildingItemJRH(n,	"shipwreck3",			"shipwreck3");		//Sullivan shore2
  n = InitBuildingItemJRH(n,	"windmill_mast",		"windmill_mast");	//Sullivan shore2
 
  n = InitBuildingItemJRH(n,	"palm3",			"palm3");
  n = InitBuildingItemJRH(n,	"derrick_45",			"derrick_45");

  n = InitBuildingItemJRH(n,	"counter",			"counter");
 
  n = InitBuildingItemJRH(n,	"EdgarPoe",			"EdgarPoe");
 
  n = InitBuildingItemJRH(n,	"door_sklad45",			"door_sklad45");
  n = InitBuildingItemJRH(n,	"hatch11B",			"hatch11B");		//penthouse
  n = InitBuildingItemJRH(n,	"hatch11DB",			"hatch11DB");		//Pym
  n = InitBuildingItemJRH(n,	"loghouse",			"loghouse");		//Charleston

  n = InitBuildingItemJRH(n,	"devils_seat",			"devils_seat");
  n = InitBuildingItemJRH(n,	"rig",				"rig");			//BB lower cave, dungeon_5

  n = InitBuildingItemJRH(n,	"gatedoor_Wi2",			"gatedoor_Wi2");	//Moultrie store
  n = InitBuildingItemJRH(n,	"gatedoor_whf",		        "gatedoor_whf");	//Moultrie fort
 
  n = InitBuildingItemJRH(n,	"gatedoor_fto",		        "gatedoor_fto");	//fort tower room
  n = InitBuildingItemJRH(n,	"gatedoor_warehouse",		"gatedoor_warehouse");	//warehouse
  n = InitBuildingItemJRH(n,	"gatefloor_oven",		"gatefloor_oven");	//Chinatown
  n = InitBuildingItemJRH(n,	"gatedoor_chi",			"gatedoor_chi");	//Chinatown
  n = InitBuildingItemJRH(n,	"gatedoor_plantation",		"gatedoor_plantation");	//plantation tavern
  n = InitBuildingItemJRH(n,	"gatedoor_BRI",			"gatedoor_BRI");	//door_N06 on brick wall
  n = InitBuildingItemJRH(n,	"gatefloor_cavern",		"gatefloor_cavern");	//Maroon_cavern

  n = InitBuildingItemJRH(n,	"empty_bottle",			"empty_bottle");	//restaurant kitchen

  
  n = InitBuildingItemJRH(n,	"ladder_big_45",		"ladder_big_45");	//Fort Moultrie
  n = InitBuildingItemJRH(n,	"ladder_very_big2",		"ladder_very_big2");	//Goldbug
  n = InitBuildingItemJRH(n,	"hatch11D_O2",			"hatch11D_O2");		//roof hatch Fort Moultrie
  n = InitBuildingItemJRH(n,	"hatch11V_O",			"hatch11V_O");		//Chinatown
  n = InitBuildingItemJRH(n,	"hatch15",			"hatch15");		//Dupin office
 
  n = InitBuildingItemJRH(n,	"roll_of_planks1",		"roll_of_planks");	//1 pile of planks
  n = InitBuildingItemJRH(n,	"roll_of_planks2",		"roll_of_planks2");	//1 pile of planks

  n = InitBuildingItemJRH(n,	"doubledoor_45",		"doubledoor_45");	//Charleston Pym's house
  n = InitBuildingItemJRH(n,	"door_N06_45",			"door_N06_45");		//Charleston tailor
  n = InitBuildingItemJRH(n,	"door_H1_45",			"door_H1_45");		//Charleston old fort
  n = InitBuildingItemJRH(n,	"door_N_45",			"door_N_45");		//Charleston Dupin's room
  n = InitBuildingItemJRH(n,	"armchair01",			"armchair01");		//Poe armchair
  n = InitBuildingItemJRH(n,	"small_roof",			"small_roof");		//
  n = InitBuildingItemJRH(n,	"textileB_45",			"textileB_45");		//textile: curtain 45

  n = InitBuildingItemJRH(n,	"carpet3",			"carpet3");		//Dupin_office
  
  n = InitBuildingItemJRH(n,	"tree3",			"tree3");		//Bishops Hostel
  n = InitBuildingItemJRH(n,	"tree_barrel",			"tree_barrel");		//Chinatown
  n = InitBuildingItemJRH(n,	"2_tubs1",			"2_tubs1");		//Chinatown
  n = InitBuildingItemJRH(n,	"2_tubs3",			"2_tubs3");		//Chinatown
  n = InitBuildingItemJRH(n,	"2_tubs4",			"2_tubs4");		//Chinatown

  n = InitBuildingItemJRH(n,	"medicine_table2",		"medicine_table2");	//Chinatown
  n = InitBuildingItemJRH(n,	"rope_ale",			"rope_ale");		//Chinatown
  n = InitBuildingItemJRH(n,	"2_close_boxes",		"2_close_boxes");	//Chinatown
  n = InitBuildingItemJRH(n,	"crank",			"crank");		//Chinatown
  n = InitBuildingItemJRH(n,	"crank2",			"crank2");		//smaller, in alchemy2
  n = InitBuildingItemJRH(n,	"oven",				"oven");		//Chinatown
  n = InitBuildingItemJRH(n,	"stump",			"stump");		//Chinatown
  n = InitBuildingItemJRH(n,	"cannon_pipe45",		"cannon_pipe45");	//Chinatown
  n = InitBuildingItemJRH(n,	"cannon_pipe45s",		"cannon_pipe45s");	//smaller, in alchemy2
  n = InitBuildingItemJRH(n,	"cannon_pipe45_up",		"cannon_pipe45_up");	//Chinatown
  n = InitBuildingItemJRH(n,	"cannon_pipe_up",		"cannon_pipe_up");	//Chinatown

  n = InitBuildingItemJRH(n,	"hay",				"hay");			//Chinatown
  n = InitBuildingItemJRH(n,	"pyrite_basket",	        "pyrite_basket");	//Chinatown sulphur room
  n = InitBuildingItemJRH(n,	"pyrite_basket_up",	        "pyrite_basket_up");	//Chinatown fireworks lab

  n = InitBuildingItemJRH(n,	"32_chairs_R",	        	"32_chairs_R");		//Chinatown
  n = InitBuildingItemJRH(n,	"32_chairs_L",	        	"32_chairs_L");		//Chinatown
  n = InitBuildingItemJRH(n,	"stonebox",			"stonebox");		//Chinatown
  n = InitBuildingItemJRH(n,	"roof_top",			"roof_top");		//Chinatown

  n = InitBuildingItemJRH(n,	"periscope",			"periscope");		//Chinatown
  n = InitBuildingItemJRH(n,	"bench_scales",			"bench_scales");	//Chinatown
  n = InitBuildingItemJRH(n,	"1_lanternF_night",		"1_lanternF_night");	//Chinatown
  n = InitBuildingItemJRH(n,	"1_lanternF_day",		"1_lanternF_day");	//Chinatown

  n = InitBuildingItemJRH(n,	"gibbet",			"gibbet");		//Charleston shore
  n = InitBuildingItemJRH(n,	"gibbet_high",			"gibbet_high");		//Kristiania_port
  n = InitBuildingItemJRH(n,	"walk_plank",			"walk_plank");		//Bishops Hostel
  n = InitBuildingItemJRH(n,	"walk_plank_180",		"walk_plank_180");	//Bishops Hostel
  
  n = InitBuildingItemJRH(n,	"gatefloor_w45",		"gatefloor_w45");	//Charleston port
  n = InitBuildingItemJRH(n,	"pirate_flag",			"pirate_flag");		//Pym's study
  n = InitBuildingItemJRH(n,	"WhalingShip",			"WhalingShip");		//Pym's bedroom
  n = InitBuildingItemJRH(n,	"NicheBooks",			"NicheBooks");		//Pym's bedroom
  n = InitBuildingItemJRH(n,	"anchor_item",			"anchor_item");		//Pym's bedroom
  n = InitBuildingItemJRH(n,	"skull3",			"skull3");		//Pym's towerroom
  n = InitBuildingItemJRH(n,	"2_sabres",			"2_sabres");		//Pym's towerroom
  n = InitBuildingItemJRH(n,	"pole3_small",			"pole3_small");		//bladeboom horizontal

  n = InitBuildingItemJRH(n,	"BugIllustration",		"BugIllustration");	//lieutenant G's bedroom
  n = InitBuildingItemJRH(n,	"sail",				"sail");		//boathouse
  n = InitBuildingItemJRH(n,	"iron_gate",			"iron_gate");		//Legrand's Hut
  n = InitBuildingItemJRH(n,	"ladder_very_big_45",		"ladder_very_big_45");	//ladder to Legrands attic
  n = InitBuildingItemJRH(n,	"green",			"green");		//Legrand's Hut
  n = InitBuildingItemJRH(n,	"fallen_tree2",			"fallen_tree2");	//storm Legrand's Hut
  n = InitBuildingItemJRH(n,	"sack3",			"sack3");		//treasure style sack
  n = InitBuildingItemJRH(n,	"FWchest",			"FWchest");		//fireworks chest in chinaroom
  n = InitBuildingItemJRH(n,	"toolbox_item",			"toolbox");		//dungeon_5
  n = InitBuildingItemJRH(n,	"porthole",			"porthole");		//inside careen shore blockhouse
	

//items here: common or quest + common use 
//all items are available for all storylines JRH
 n = InitBuildingItemJRH(n,	"chimney_45",			"chimney_45");		//Tortuga
 n = InitBuildingItemJRH(n,	"chimney_45_night",		"chimney_45_night");	//Tortuga
 n = InitBuildingItemJRH(n,	"chimney_pot",			"chimney_pot");		//Tortuga + Legrands house
 n = InitBuildingItemJRH(n,	"chimney_pot_night",		"chimney_pot_night");	//Tortuga	
 n = InitBuildingItemJRH(n,	"port_mast1",			"port_mast1");		//Tortuga
 n = InitBuildingItemJRH(n,	"port_mast2",			"port_mast2");		//Tortuga
 n = InitBuildingItemJRH(n,	"port_rey1",			"port_rey1");		//Tortuga
 n = InitBuildingItemJRH(n,	"ladder_very_big",		"ladder_very_big");	//ladder to wood tower + Tortuga
 n = InitBuildingItemJRH(n,	"ladder_biggest",		"ladder_biggest");	//Tortuga sailmaker
 n = InitBuildingItemJRH(n,	"ladder_very_big2",		"ladder_very_big2");	//Goldbug + Tortuga
 n = InitBuildingItemJRH(n,	"bars_down",			"bars_down");		//Tortuga

 n = InitBuildingItemJRH(n,	"market_C4",			"market_C4");		//Charleston
 n = InitBuildingItemJRH(n,	"market_C1+1",			"market_C1+1");		//Charleston + Tortuga
 n = InitBuildingItemJRH(n,	"market_P1",			"market_P1");		//Charleston
 n = InitBuildingItemJRH(n,	"market_P1+W",			"market_P1+W");		//Charleston
 n = InitBuildingItemJRH(n,	"market_P2",			"market_P2");		//Charleston + Tortuga
 n = InitBuildingItemJRH(n,	"market_V_X1",			"market_V_X1");		//Charleston
 n = InitBuildingItemJRH(n,	"market_tent_fruit",		"market_tent_fruit");	//Tortuga
 n = InitBuildingItemJRH(n,	"market_tent",			"market_tent");		//Tortuga

 n = InitBuildingItemJRH(n,	"cannon2",			"cannon2");		//Tortuga
 n = InitBuildingItemJRH(n,	"cannon1",			"cannon1");		//Tortuga
 n = InitBuildingItemJRH(n,	"gatedoor",			"gatedoor");		//quest loc + Tortuga
 n = InitBuildingItemJRH(n,	"gatedoor_small",		"gatedoor_small");      //quest loc + Tortuga
 n = InitBuildingItemJRH(n,	"gatedoor_w",			"gatedoor_w");		//woodwall dark is up, quest loc + Tortuga
 n = InitBuildingItemJRH(n,	"gatedoor_small_stone",		"gatedoor_small_stone");
 n = InitBuildingItemJRH(n,	"medicine_table",		"medicine_table");	//outside church + Tortuga
 n = InitBuildingItemJRH(n,	"1_lanternD_night",		"1_lanternD_night");	//Tortuga
 n = InitBuildingItemJRH(n,	"1_lanternD_day",		"1_lanternD_day");	//Tortuga
 n = InitBuildingItemJRH(n,	"1_lanternE_night",		"1_lanternE_night");	//Tortuga
 n = InitBuildingItemJRH(n,	"1_lanternE_day",		"1_lanternE_day");	//Tortuga
 n = InitBuildingItemJRH(n,	"2_lanternsA_night",		"2_lanternsA_night");	//Tortuga
 n = InitBuildingItemJRH(n,	"2_lanternsA_day",		"2_lanternsA_day");	//Tortuga
 n = InitBuildingItemJRH(n,	"2_lanternsB_night",		"2_lanternsB_night");	//Tortuga
 n = InitBuildingItemJRH(n,	"2_lanternsB_day",		"2_lanternsB_day");	//Tortuga
 n = InitBuildingItemJRH(n,	"2_lanternsC_night",		"2_lanternsC_night");	//Tortuga
 n = InitBuildingItemJRH(n,	"2_lanternsC_day",		"2_lanternsC_day");	//Tortuga

 n = InitBuildingItemJRH(n,	"watchtower",			"watchtower");		//Tortuga + careen shore
 n = InitBuildingItemJRH(n,	"watchtower_damaged",		"watchtower_damaged");  //careen shore
 n = InitBuildingItemJRH(n,	"watchtower_roof",		"watchtower_roof");  	//careen shore
 n = InitBuildingItemJRH(n,	"gatedoor_shipyard",		"gatedoor_shipyard");	//Tortuga
 n = InitBuildingItemJRH(n,	"hatch16_T",			"hatch16_T");		//Tortuga shipyard
 n = InitBuildingItemJRH(n,	"hatch16_V",			"hatch16_V");		//Tortuga shipyard
 n = InitBuildingItemJRH(n,	"door_Tortuga",			"door_Tortuga");	//Tortuga shipyard
 n = InitBuildingItemJRH(n,	"door_Tortuga2",		"door_Tortuga2");	//Tortuga loanshark
 n = InitBuildingItemJRH(n,	"door_TortugaT",		"door_TortugaT");	//90, prison2 stairs
 
 n = InitBuildingItemJRH(n,	"carpet2",			"carpet2");		//Claire's room + Tortuga loanshark, hotel
 n = InitBuildingItemJRH(n,	"gatedoor_Mine_dark",		"gatedoor_Mine_dark");	//corridor dark
 n = InitBuildingItemJRH(n,	"gatedoor_w_45_dark",		"gatedoor_w_45_dark");	//woodwall 45 degrees: corridor dark
 n = InitBuildingItemJRH(n,	"gatedoor_Tortuga1",		"gatedoor_Tortuga1");	//Tortuga townhall 
 n = InitBuildingItemJRH(n,	"gatedoor_Tortuga1_night",	"gatedoor_Tortuga1_night"); //Tortuga townhall
 n = InitBuildingItemJRH(n,	"gatedoor_Tortuga2",		"gatedoor_Tortuga2");	//Tortuga to jungle stairs
 n = InitBuildingItemJRH(n,	"door_largeh_dark",		"door_largeh_dark");	//corridor dark
 n = InitBuildingItemJRH(n,	"door_N06T",			"door_N06T");		//mine, turned 90 degrees + Tortuga
 n = InitBuildingItemJRH(n,	"gatedoor_fta",		        "gatedoor_fta");	//Goldbug + Tortuga

 n = InitBuildingItemJRH(n,	"tree2_night",			"tree2_night");		//Tortuga

 n = InitBuildingItemJRH(n,	"palm2_big_night",		"palm2_big_night");	//Tortuga
 n = InitBuildingItemJRH(n,	"ship_building",		"ship_building");	//Tortuga
 n = InitBuildingItemJRH(n,	"ship_building_night",		"ship_building_night");	//Tortuga
 n = InitBuildingItemJRH(n,	"wood_pier",			"wood_pier");		//Goldbug + Tortuga
 n = InitBuildingItemJRH(n,	"well",				"well");		//Goldbug + Tortuga
 n = InitBuildingItemJRH(n,	"wagon",			"wagon");		//Tortuga
 n = InitBuildingItemJRH(n,	"anchor_big",			"anchor_big");		//Tortuga
 n = InitBuildingItemJRH(n,	"body",				"body");		//Tortuga
 n = InitBuildingItemJRH(n,	"shipwreck",			"shipwreck");		//AOP shipwreck also in Tortuga
 n = InitBuildingItemJRH(n,	"boat2_B",			"boat2_B");		//upside down
 n = InitBuildingItemJRH(n,	"boat2_C",			"boat2_C");		//on one side
 n = InitBuildingItemJRH(n,	"plank2_very_long",		"plank2_very_long");	//Goldbug + Tortuga

 n = InitBuildingItemJRH(n,	"carpet4",			"carpet4");		//Oranjestad port store
 n = InitBuildingItemJRH(n,	"textile4",			"textile4");		//Oranjestad port store
 n = InitBuildingItemJRH(n,	"jars",				"jars");		//Oranjestad port store

 n = InitBuildingItemJRH(n,	"lamp",				"lamp");		//Turks
 n = InitBuildingItemJRH(n,	"door_N03",			"door_N03");		//WR + Turks
 n = InitBuildingItemJRH(n,	"door_MdTav",			"door_MdTav");		//Turks

 n = InitBuildingItemJRH(n,	"textile3",			"textile3");		//textile tilted: curtain also in Tortuga
 n = InitBuildingItemJRH(n,	"bed",				"bed");			//also in Tortuga
 n = InitBuildingItemJRH(n,	"dummy",			"dummy");		//this one stays (without belt), also in Tortuga
 n = InitBuildingItemJRH(n,	"pole1",			"pole1");		//bladeboom vertical, also in Tortuga
 n = InitBuildingItemJRH(n,	"carpet3V",			"carpet3V");		//Pym's towerroom, also in Tortuga

 n = InitBuildingItemJRH(n,	"wood_long_log",		"wood_long_log");	//Chinatown + Aruba

 n = InitBuildingItemJRH(n,	"gatedoor_w8",			"gatedoor_w8");		//gatedoor metal on dark stones, also in Assassin
 n = InitBuildingItemJRH(n,	"gatedoor_SPA",			"gatedoor_SPA");	//cloister
 n = InitBuildingItemJRH(n,	"door_H1_small",		"door_H1_small");	//Citadel Rock
 n = InitBuildingItemJRH(n,	"iron_gate_big",		"iron_gate_big");	//cloister
 n = InitBuildingItemJRH(n,	"iron_gate45",			"iron_gate45");		//cloister
 n = InitBuildingItemJRH(n,	"door_fort_high",		"door_fort_high");	//cloister

 n = InitBuildingItemJRH(n,	"door_A05",			"door_A05");		//sacristy, also Santo Domingo bridge
 n = InitBuildingItemJRH(n,	"gatedoor_attic_brick",		"gatedoor_attic_brick");//attic stairs, hiding door & frame, also Santo Domingo bridge
 n = InitBuildingItemJRH(n,	"porch",			"porch");		//bb_prison entre

 //Moved to common by Levis & JRH:
 n = InitBuildingItemJRH(n,	"door_M11",			"door_M11");		//ships: cabin door, a little bigger, hotel
 n = InitBuildingItemJRH(n,	"gatedoor_dark_stone",		"gatedoor_dark_stone");	//stonewall mine tunnelA no lights, hotel
 n = InitBuildingItemJRH(n,	"hatch2",			"hatch2");		//floor hatch (inside, loansh. Redm), hotel
 n = InitBuildingItemJRH(n,	"hatch11",			"hatch11");		//floor hatch mine tunnelA, hotel
 n = InitBuildingItemJRH(n,	"hatch11D_O3",			"hatch11D_O3");		//dito brighter, Pym's, hotel
 n = InitBuildingItemJRH(n,	"suspension_bridge",		"suspension_bridge");	//Citadel
 n = InitBuildingItemJRH(n,	"suspension_bridge_ropes",	"suspension_bridge_ropes");//Citadel
 n = InitBuildingItemJRH(n,	"small_planks",			"small_planks");	//Citadel
 n = InitBuildingItemJRH(n,	"bench",			"bench");		//Fort Moultrie, cloister
 n = InitBuildingItemJRH(n,	"armchair02",			"armchair02");		//red armchair
 n = InitBuildingItemJRH(n,	"WallMap",			"WallMap");		//Cartographer Santiago

 n = InitBuildingItemJRH(n,	"tree1",			"tree1");		//Chinatown, cloister
 n = InitBuildingItemJRH(n,	"church_window",		"church_window");	//Kristiania, cloister
 n = InitBuildingItemJRH(n,	"church_window_small",		"church_window_small");	//new_cloister BOP
 n = InitBuildingItemJRH(n,	"palm2",			"palm2");		//Charleston, cloister
 n = InitBuildingItemJRH(n,	"palm2_big",			"palm2_big");		//Tortuga, cloister
 n = InitBuildingItemJRH(n,	"tree2",			"tree2");		//Chinatown, Tortuga, cloister
 n = InitBuildingItemJRH(n,	"wheelbarrow",			"wheelbarrow");		//cloister
 n = InitBuildingItemJRH(n,	"iron_gate3",			"iron_gate3");		//Estate maze, cloister
 n = InitBuildingItemJRH(n,	"hatch11_S",			"hatch11_S");		//BB cave, cloister
  //--------------------------------------------------------------------------------------------------------------------------------
  // JRH <--

  // NK 05-04-07 so we can skip the skiptrade items. Note that _some_ items after FIRST_TRADE_ITEM will have skiptrade;
  FIRST_TRADE_ITEM = n;
  // IMPORTANT: makesure that none _before_ it do _not_!
  // NOTE: as of 05-07-22, I am moving this back to cover all items with skiprand = false as well. This is because we need to sort by level all following items.
  // That means that some of Alan's stuff is above, and some below.


  //-----------------------------------------------------------------------------------------------------------------
  // Pickup items all are default set to SKIPTRADE
  //-----------------------------------------------------------------------------------------------------------------
  // PICKUP GOLD:                               gold
  //             ItemIndex                rare    |    numrand increment (adds more than one of this to random items tree)
  //                 |  itmID   modelID     |     |    |
  //-----------------|--|----------|--------|-----|----|-------------------------------------------------------------
  n = InitPickUpItem(n,"100gp", "purse",  0.30,  100,  RANDITEMS_MAXCHANCE*1.5 ); // 100 gp // numrand = 15
  n = InitPickUpItem(n,"250gp", "pursem", 0.20,  250,  RANDITEMS_MAXCHANCE*1.25 );// 250 gp // numrand = 12
  n = InitPickUpItem(n,"500gp", "pursel", 0.10,  500,  RANDITEMS_MAXCHANCE*0.5 ); // 500 gp // numrand = 5
  //-----------------------------------------------------------------------------------------------------------------

  //-----------------------------------------------------------------------------------------------------------------
  // Alan_Smithee Apothecary Meds -->
  //-----------------------------------------------------------------------------------------------------------------
  // APOTHECARY:                          picIndex           Price  ispotion  antidote            skiptrade
  //            ItemIndex        picTexture   |   rare         |     | pic      |   health         | skiprand
  //                |  itmID   modelID    |   |    |  MinLevel |     |  | tex   |   |              | | skipequip
  //----------------|----|--------|-------|---|----|-----|-----|-----|--|--|----|---|--------------|-|-|-------------
  n = InitApothItem(n,"leeches",  "",    "AS",1,  0.50,  1,  300,    1, 2, 2,   1, -10.0,          1,1,1);// Leeches
  n = InitApothItem(n,"meds1",    "",    "AS",4,  0.15,  1,  350,    0, 0, 0,   0,   0.0,          1,0,1);// Acetum Saturninum
  n = InitApothItem(n,"meds2",    "",    "AS",6,  0.15,  1,  350,    0, 0, 0,   0,   0.0,          1,0,1);// Confectio Damocritis
  n = InitApothItem(n,"meds3",    "",    "AS",5,  0.15,  1,  350,    0, 0, 0,   0,   0.0,          1,0,1);// Tincture of Laudenum
  n = InitApothItem(n,"meds4",    "",    "AS",3,  0.15,  1,  350,    0, 0, 0,   0,   0.0,          1,0,1);// Turpeth
  //-----------------------------------------------------------------------------------------------------------------
  // Alan_Smithee Apothecary Meds <--
  //-----------------------------------------------------------------------------------------------------------------


  //-------------------------------------------------------------------------------------------------------------------------------
  // ccc special weapon assembly kit -->
  // PB: SWAK Code moved here, so you won't fast-equip SWAK weapon's unless you don't have anything else
  // NK 05-07-10 change stun, steal, stealth from bool to float for chance, place all effect1/effect2 things under always.fx.* or (attacktype).fx.*
  // NK 05-07-22 fiddle with rarity.
  //===================================================================
  // These are just too crazy to put into compaction functions
  //===================================================================

  // PB: Fists // moved here because its sort of a special weapon
  makeref(itm,Items[n]);
  itm.id          = "bladeX4";
  itm.fist        = 1;  // new attribute, exclusively for your fists
  itm.enblrld     = true; // you can reload your gun when using this
  itm.skiptrade   = true; // you can't buy them
  itm.skiprand    = true; // you can't find them
  itm.skipequip   = true; // not used in auto equip
  itm.groupID     = BLADE_ITEM_TYPE;
  itm.name        = "itmname_bladeX4";
  itm.describe    = "itmdescr_bladeX4";
  itm.folder      = "ammo";
  itm.model       = "invisible";    // Completely empty model; had to be added to enable you to 'draw' your fists
  itm.picIndex    = 11;         // Picture made by Petros
  itm.picTexture  = "ITEMS_ccc";
  itm.price       = 1;
  itm.minlevel    = 1;
  itm.rare        = 1.0;  // NK 05-04-06 for itemtrading to have nonzero rare.
  itm.dmg_min     = 0;
  itm.dmg_max     = 0;
  itm.piercing    = 0;    // Baste: was 100
  itm.block       = 0;
  n++;

  //JRH: like fists
  makeref(itm,Items[n]);
  itm.id          = "bladearrows";
  itm.fist        = 1;  // new attribute, exclusively for your fists
  itm.enblrld     = true; // you can reload your gun when using this
  itm.skiptrade   = true; // you can't buy them
  itm.skiprand    = true; // you can't find them
  itm.skipequip   = true; // not used in auto equip
  itm.groupID     = BLADE_ITEM_TYPE;
  itm.name        = "itmname_bladearrows";
  itm.describe    = "itmdescr_bladearrows";
  itm.folder      = "ammo";
  itm.model       = "arrow";
  itm.picIndex    = 2;        
  itm.picTexture  = "ITEMS_BOP";
  itm.price       = 2;
  itm.minlevel    = 1;
  itm.rare        = 1.0;  // NK 05-04-06 for itemtrading to have nonzero rare.
  itm.dmg_min     = 0;
  itm.dmg_max     = 0;
  itm.piercing    = 0;    // Baste: was 100
  itm.block       = 0;
  n++;

// JRH: Cursed Maquahuitl
  makeref(itm,Items[n]);
  itm.id                      = "pistolmaquahuitl";
  itm.multidmg                = 1;      // new attribute, does multiple damage
  itm.enblrld     	      = true; 
  itm.sound                   = "OBJECTS\DUEL\electricity.wav";//JRH
//  itm.always.fx.effect0       = "canfire2";   // graphic effect, choose particlename from resource\ini\particles\
//  itm.always.fx.effect0.time  = 10;
  itm.shottype                = "";    //JRH
  itm.skiptrade               = true;    // you can sell the item
  itm.skipsell                = true;    // PB: make them buyable
  itm.skiprand                = true;
  itm.skipequip               = true;
  itm.groupID                 = GUN_ITEM_TYPE;
  itm.name                    = "itmname_pistolmaquahuitl";
  itm.describe                = "itmdescr_pistolmaquahuitl";
  itm.folder                  = "ammo";
  itm.model                   = "maquahuitl_cursed";
  itm.picIndex                = 5;
  itm.picTexture              = "ITEMS_BOP";
  itm.price                   = 180;
  itm.chargeQ                 = 1;
  itm.chargespeed             = 3;   
  itm.dmg_min                 = 30.0;			
  itm.dmg_max                 = 50.0;
  itm.accuracy                = 100;   
  itm.rare                    = 0.00;
  itm.minlevel                = 14;			
  itm.nation                  = "";
  n++;

// JRH: snakewand
  makeref(itm,Items[n]);
  itm.id                      = "snakewand";
  itm.skiptrade               = true;
  itm.skipsell                = true;
  itm.skiprand                = true;
  itm.skipequip               = true;
  itm.groupID                 = BLADE_ITEM_TYPE;
  itm.name                    = "itmname_snakewand";
  itm.describe                = "itmdescr_snakewand";
  itm.folder                  = "ammo";
  itm.model                   = "OtherItemsJRH/snakewand";
  itm.picIndex                = 16;
  itm.picTexture              = "ITEMS_JRH37";  
  itm.price                   = 0;
  itm.piercing                = 60;
  itm.block                   = 30;
  itm.minlevel                = 99;
  itm.rare                    = 0.00;
  itm.param.time              = 0.1;
  itm.param.colorstart        = argb(64, 64, 64, 64);
  itm.param.colorend          = argb(0, 32, 32, 32);
  itm.nation                  = PIRATE;
  n++;

// JRH: bladethunder
  makeref(itm,Items[n]);
  itm.id                      = "bladethunder";
  itm.skiptrade               = true;
  itm.skipsell                = true;
  itm.skiprand                = true;
  itm.skipequip               = true;
  itm.groupID                 = BLADE_ITEM_TYPE;
  //itm.name                    = "itmname_tridentNeptune";
  //itm.describe                = "itmdescr_tridentNeptune";
  itm.folder                  = "ammo";
  itm.model                   = "OtherItemsJRH/bladethunder";
  //itm.picIndex                = 7;
  //itm.picTexture              = "ITEMS_AS";
  itm.price                   = 800000;
  //itm.dmg_min                 = 30.0;
  //itm.dmg_max                 = 50.0;
  itm.piercing                = 60;
  itm.block                   = 30;
  itm.minlevel                = 99;
  itm.rare                    = 0.00;
  itm.param.time              = 0.1;
  itm.param.colorstart        = argb(64, 64, 64, 64);
  itm.param.colorend          = argb(0, 32, 32, 32);
  itm.nation                  = PIRATE;
  n++;

// JRH: pistollightning
  makeref(itm,Items[n]);
  itm.id                      = "pistollightning";
  itm.enblrld     	      = true; 
  //itm.sound                   = "OBJECTS\DUEL\electricity.wav";//JRH
  itm.shottype                = "";    //JRH
  itm.skiptrade               = true;    // you can sell the item
  itm.skipsell                = true;    // PB: make them buyable
  itm.skiprand                = true;
  itm.skipequip               = true;
  itm.groupID                 = GUN_ITEM_TYPE;
  //itm.name                    = "itmname_pistolmaquahuitl";
  //itm.describe                = "itmdescr_pistolmaquahuitl";
  itm.folder                  = "ammo";
  itm.model                   = "OtherItemsJRH/pistollightning";
  //itm.picIndex                = 5;
  //itm.picTexture              = "ITEMS_BOP";
  itm.price                   = 1;
  itm.chargeQ                 = 1;
  itm.chargespeed             = 3;   
  //itm.dmg_min                 = 10.0;			
  //itm.dmg_max                 = 20.0;
  itm.accuracy                = 100;   
  itm.rare                    = 0.00;
  itm.minlevel                = 14;			
  itm.nation                  = "";
  n++;

// JRH: Blowgun
  makeref(itm,Items[n]);
  itm.id                      = "blowgun";
  itm.sound                   = "OBJECTS\duel\ArrowBlow.wav";  // soundfile played when used
  itm.arrow          		= 1;	//checks if enemy got a shield 
  itm.poison          		= 1;    // poisons targets
  itm.enblrld     	      = true;
  itm.shottype                = "ar2";    //JRH
  itm.skiptrade               = false;  // you can sell the item
  itm.skipsell                = true;   // you can't buy them
  itm.skiprand                = true;
  itm.skipequip               = false;
  itm.groupID                 = GUN_ITEM_TYPE;
  itm.name                    = "itmname_blowgun";
  itm.describe                = "itmdescr_blowgun";
  itm.folder                  = "ammo";
  itm.model                   = "blowgun";		
  itm.picIndex                = 1;
  itm.picTexture              = "ITEMS_BOP2";
  itm.price                   = 45;
  itm.chargeQ                 = 1;
  itm.chargespeed             = 1.0;
  itm.dmg_min                 = 5.0;
  itm.dmg_max                 = 10.0;
  itm.accuracy                = 80;
  itm.rare                    = 0.0;
  itm.nation                  = PIRATE;
  n++;

// JRH: Rocket
  makeref(itm,Items[n]);
  itm.id                      = "pistolrocket";
  itm.multidmg                = 1;
  itm.selfdmg                 = 1;
  itm.sound                   = "OBJECTS\duel\rocket.wav";
  itm.enblrld     	      = true;
  itm.shottype                = "ro";    //JRH
  itm.skiptrade               = false;  // you can sell the item
  itm.skipsell                = true;   // you can't buy them
  itm.skiprand                = true;
  itm.skipequip               = false;
  itm.groupID                 = GUN_ITEM_TYPE;
  itm.name                    = "itmname_pistolrocket";
  itm.describe                = "itmdescr_pistolrocket";
  itm.folder                  = "ammo";
  itm.model                   = "rocket";		
  itm.picIndex                = 4;
  itm.picTexture              = "ITEMS_BOP2";
  itm.price                   = 45;
  itm.chargeQ                 = 1;
  itm.chargespeed             = 2.0;
  itm.dmg_min                 = 60.0;  
  itm.dmg_max                 = 150.0;
  itm.accuracy                = 70; 
  itm.rare                    = 0.0;
  itm.nation                  = PIRATE;
  n++;

// JRH: Whip
  makeref(itm,Items[n]);
  itm.id                      = "pistolwhip";
  itm.sound                   = "OBJECTS\duel\whip.wav";
  itm.enblrld     	      = true;
  itm.shottype                = "";    //JRH
  itm.skiptrade               = false;  // you can sell the item
  itm.skipsell                = true;   // you can't buy them
  itm.skiprand                = true;
  itm.skipequip               = false;
  itm.groupID                 = GUN_ITEM_TYPE;
  itm.name                    = "itmname_pistolwhip";
  itm.describe                = "itmdescr_pistolwhip";
  itm.folder                  = "ammo";
  itm.model                   = "whip_rolled";		
  itm.picIndex                = 14;
  itm.picTexture              = "ITEMS_BOP2";
  itm.price                   = 0;
  itm.chargeQ                 = 1;
  itm.chargespeed             = 0.1;
  itm.dmg_min                 = 0.0;  
  itm.dmg_max                 = 0.0;
  itm.accuracy                = 100; 
  itm.rare                    = 0.0;
  itm.nation                  = PIRATE;
  n++;

// JRH: Holy Water
  makeref(itm,Items[n]);
  itm.id                      = "holy_water";
//  itm.sound                   = "OBJECTS\duel\holy_water.wav";
  itm.throw_HW                = 1;
  itm.enblrld   	      = true;			//temp testing
  itm.skiptrade               = true;
  itm.skipsell                = true;
  itm.skiprand                = true;
  itm.skipequip               = true;
  itm.groupID                 = GUN_ITEM_TYPE;
  itm.name                    = "itmname_holy_water";
  itm.describe                = "itmdescr_holy_water";
  itm.folder                  = "ammo";
  itm.model                   = "holy_water";
  itm.picIndex                = 11;        
  itm.picTexture              = "ITEMS_JRH26";  
  itm.price                   = 1;
  itm.chargeQ                 = 1;
  itm.chargespeed             = 0.1;
  itm.dmg_min                 = 0.0;
  itm.dmg_max                 = 0.0;
  itm.accuracy                = 100;
  itm.rare                    = 0.0;
  itm.minlevel                = 1;
  itm.nation                  = PIRATE;
  n++;

  // Cobblestone
  makeref(itm,Items[n]);
  itm.id          = "pistolrock";
  itm.sound       = "OBJECTS\duel\sword_inbody.wav";  // soundfile played when used
  itm.throw       = 1;    // new attribute, weapon that you throw, so only one time use
  itm.stun        = 0.75;   // stuns targets
  itm.stealth     = 0.75;   // doesn't alarm victim
  itm.skiptrade   = true;   // you can't trade the item (who'd buy a simple stone...?)
  itm.skiprand    = false;
  itm.skipequip   = NO_SPECIALWEAPONED_NPC;
  itm.groupID     = GUN_ITEM_TYPE;
  itm.name        = "itmname_pistolrock";
  itm.describe    = "itmdescr_pistolrock";
  itm.folder      = "ammo";
  itm.model       = "Sapphire";
  itm.picIndex    = 3;
  itm.picTexture  = "ITEMS_ccc";
  itm.price       = 5;
  itm.chargeQ     = 1;
  itm.chargespeed = 0.5;
  itm.dmg_min     = 1.0;  //BB(5.0)
  itm.dmg_max     = 5.0;  //BB(10.0)
  itm.accuracy    = 80;   //BB(80)
  itm.rare        = 0.25;   //BB(0.5)
  itm.secondary   = true;
  itm.nation                  = PIRATE;
  itm.sneaky                  = true; // PB: Sneaky Trader
  n++;

  // Etherbottle
  makeref(itm,Items[n]);
  itm.id                      = "pistolgas";
  itm.multidmg                = 1;  // new attribute, does multiple damage
  itm.selfdmg                 = 1;  // hurts user if used too close
  itm.sound                   = "OBJECTS\SHIPCHARGE\ship_bow.wav";  // soundfile played when used
  itm.always.fx.qty           = 2;
  itm.always.fx.effect0       = "cancloud";   // graphic effect, choose particlename from resource\ini\particles\
  itm.always.fx.effect0.time  = 20;       // duration of this effect
  itm.always.fx.effect1       = "artifact";   // second graphic effect
  itm.always.fx.effect1.time  = 5;        // duration of this effect
  itm.throw                   = 1;    // new attribute, weapon that you throw, so only one time use
  itm.stun                    = 0.75;   // stuns targets
  itm.skiptrade               = false;  // you can sell the item
  itm.skipsell                = true;   // you can't buy them
  itm.skiprand                = false;
  itm.skipequip               = NO_SPECIALWEAPONED_NPC ;
  itm.groupID                 = GUN_ITEM_TYPE;
  itm.name                    = "itmname_pistolgas";
  itm.describe                = "itmdescr_pistolgas";
  itm.folder                  = "ammo";
  itm.model                   = "adrenaline";   // copy "adrenaline" model and texture into "ammo" folder !
  itm.picIndex                = 10;         // New picture by Petros to
  itm.picTexture              = "ITEMS_ccc";  // distinguish with the bottle 'o rum
  itm.price                   = 55;   // BB (800)
  itm.chargeQ                 = 1;
  itm.chargespeed             = 0.5;
  itm.dmg_min                 = 1.0;
  itm.dmg_max                 = 2.0;
  itm.accuracy                = 70;   // BB (99)
  itm.rare                    = 0.25;   // BB (0.3)
  itm.minlevel                = 4;      //Sulan added minlevel to improve rarity.
  itm.secondary               = true;
  itm.nation                  = PIRATE;
  itm.sneaky                  = true; // PB: Sneaky Trader
  n++;

  // Stinkpot
  makeref(itm,Items[n]);
  itm.id                      = "pistolstink";
  itm.multidmg                = 1;  // new attribute, does multiple damage
  itm.selfdmg                 = 1;  // hurts user if used too close
  itm.sound                   = "OBJECTS\SHIPCHARGE\ship_onfire.wav"; // soundfile played when used
  itm.always.fx.qty           = 2;
  itm.always.fx.effect0       = "ship_smoke";   // graphic effect
  itm.always.fx.effect0.time  = 5;        // duration of this effect
  itm.always.fx.effect1       = "fort_fire";    // graphic effect2
  itm.always.fx.effect1.time  = 20;       // duration
  itm.throw                   = 1;    // new attribute, weapon that you throw, so only one time use
  itm.poison                  = 1;    // poisons targets
  itm.skiptrade               = false;  // you can sell the item
  itm.skipsell                = true;   // you can't buy them
  itm.skiprand                = false;
  itm.skipequip               = NO_SPECIALWEAPONED_NPC ;
  itm.groupID                 = GUN_ITEM_TYPE;
  itm.name                    = "itmname_pistolstink";
  itm.describe                = "itmdescr_pistolstink";
  itm.folder                  = "ammo";
  itm.model                   = "potionBig";
  itm.picIndex                = 8;
  itm.picTexture              = "ITEMS_ccc";
  itm.price                   = 70;   // BB (800)
  itm.chargeQ                 = 1;
  itm.chargespeed             = 0.5;
  itm.dmg_min                 = 5.0;  // BB(15)
  itm.dmg_max                 = 15.0; // BB(30)
  itm.accuracy                = 70;   // BB(99)
  itm.rare                    = 0.25;   // BB(0.3)
  itm.minlevel                = 3;      //Sulan added minlevel to improve rarity.
  itm.secondary               = true;
  itm.nation                  = PIRATE;
  itm.sneaky                  = true; // PB: Sneaky Trader
  n++;

  // Grenade
  makeref(itm,Items[n]);
  itm.id                      = "pistolgrenade";
  itm.multidmg                = 1;  // new attribute, does multiple damage
  itm.selfdmg                 = 1;  // hurts user if used too close
  itm.misfire                 = 5;  // chance in % that weapon hurts user only
  itm.sound                   =  "OBJECTS\SHIPCHARGE\cannon_fire3.wav"; // soundfile played when used
  itm.always.fx.qty           = 2;
  itm.always.fx.effect0       = "blast";      // graphic effect, choose particlename from resource\ini\particles\
  itm.always.fx.effect0.time  = 5;        // duration of this effect
  itm.always.fx.effect1       = "fort_fire";    // second graphic effect
  itm.always.fx.effect1.time  = 20;       // duration of this effect
  itm.throw                   = 1;    // new attribute, weapon that you throw, so only one time use
  itm.skiptrade               = false;  // you can sell the item
  itm.skipsell                = false;  // PB: make them buyable
  itm.skiprand                = false;
  itm.skipequip               = NO_SPECIALWEAPONED_NPC ;
  itm.groupID                 = GUN_ITEM_TYPE;
  itm.name                    = "itmname_pistolgrenade";
  itm.describe                = "itmdescr_pistolgrenade";
  itm.folder                  = "ammo";
  itm.model                   = "grenado";
  itm.picIndex                = 1;
  itm.picTexture              = "ITEMS_ccc";
  itm.price                   = 110;   // BB(10)
  itm.chargeQ                 = 1;
  itm.chargespeed             = 0.5;   // for instant use after equip
  itm.dmg_min                 = 40.0;  // BB (100.0)[wider and lower range of damage to better
  itm.dmg_max                 = 150.0; // BB (120.0)[reflect early grenade tech and reliability.
  itm.accuracy                = 70;    // BB (99)
  itm.minlevel                = 5;     // Sulan added minlevel to improve rarity.
  itm.rare                    = 0.15;  // BB (0.35)
  itm.secondary               = true;
  itm.nation                  = PIRATE;
  itm.sneaky                  = true; // PB: Sneaky Trader
  n++;

  // Poisoned Throwingknife
  makeref(itm,Items[n]);
  itm.id                      = "pistolpdart";
  itm.sound                   = "OBJECTS\duel\sword_wind.wav";  // soundfile played when used
  itm.throw                   = 1;    // new attribute, weapon that you throw, so only one time use
  itm.poison                  = 1;    // poisons targets
  itm.stealth                 = 0.75;   // doesn't alarm victim
  itm.skiptrade               = false;  // you can sell the item
  itm.skipsell                = true;   // you can't buy them
  itm.skiprand                = false;
  itm.skipequip               = NO_SPECIALWEAPONED_NPC ;
  itm.groupID                 = GUN_ITEM_TYPE;
  itm.name                    = "itmname_pistolpdart";
  itm.describe                = "itmdescr_pistolpdart";
  itm.folder                  = "ammo";
  itm.model                   = "PoisenedDagger";		//JRH: blade5 didn't go well with bladepclub203
  itm.picIndex                = 6;
  itm.picTexture              = "ITEMS_ccc";
  itm.price                   = 45;     // BB (800)
  itm.chargeQ                 = 1;
  itm.chargespeed             = 0.5;
  itm.dmg_min                 = 5.0;
  itm.dmg_max                 = 10.0;
  itm.accuracy                = 60;   // BB (80)
  itm.rare                    = 0.25;   // Sulan (0.6)
  itm.secondary               = true;
  itm.nation                  = PIRATE;
  itm.sneaky                  = true; // PB: Sneaky Trader
  n++;

  // Blunderbuss
  makeref(itm,Items[n]);
  itm.id                      = "pistolbbuss";
  itm.multidmg                = 1;      // new attribute, does multiple damage
  itm.misfire                 = 5;      // chance in % that weapon hurts user only
  itm.sound                   = "OBJECTS\DUEL\pistol_bbus.wav";//JRH
  itm.shottype                = "pg2";    //JRH
  itm.skiptrade               = false;    // you can sell the item
  itm.skipsell                = false;    // PB: make them buyable
  itm.skiprand                = false;
  itm.skipequip               = false;    // LDH
  itm.groupID                 = GUN_ITEM_TYPE;
  itm.name                    = "itmname_pistolbbuss";
  itm.describe                = "itmdescr_pistolbbuss";
  itm.folder                  = "ammo";
  itm.model                   = "blunder1_10_back";		//JRH start case
  itm.picIndex                = 7;
  itm.picTexture              = "ITEMS_ccc";
  itm.price                   = 180;
  itm.chargeQ                 = 1;
  itm.chargespeed             = 30;   // BB (40) 	JRH was 30
  itm.dmg_min                 = 45.0;			// JRH was 10
  itm.dmg_max                 = 80.0;
  itm.accuracy                = 40;   // BB (60)
  itm.rare                    = 0.15; // BB (0.08)
  itm.minlevel                = 14;			// JRH was 3
  itm.nation                  = "";
  itm.sneaky                  = true; // PB: Sneaky Trader
  itm.firstperiod = PERIOD_GOLDEN_AGE_OF_PIRACY; 	//JRH
  itm.lastperiod  = PERIOD_NAPOLEONIC;			//JRH
  n++;

  // Jack Sparrow pistol// Quest item!
  makeref(itm,Items[n]);
  itm.id                      = "pistol3_14";
  itm.sound                   = "OBJECTS\DUEL\pistol_shot4.wav";//JRH
  itm.shottype                = "pb"; //JRH
  itm.skiptrade               = false;
  itm.skipsell                = true;
  itm.skiprand                = true;
  itm.skipequip               = false;
  itm.groupID                 = GUN_ITEM_TYPE;
  itm.name                    = "itmname_pistol3_14";
  itm.describe                = "itmdescr_pistol3_14";
  itm.folder                  = "ammo";
  itm.model                   = "pistol3_14";
  itm.picIndex                = 6;
  itm.picTexture              = "ITEMS_21";
  itm.price                   = 9587;   // BB (1700)
  itm.chargeQ                 = 1;
  itm.chargespeed             = 10;   // BB (20)
  itm.dmg_min                 = 150.0;
  itm.dmg_max                 = 175.0;
  itm.minlevel                = 99;     //BB added minlevel to improve rarity.
  itm.accuracy                = 85;
  itm.rare                    = 0.00;   // will not appear in shops / chests ever
  itm.nation                  = PIRATE;
  n++;

  // Mercenary pistol// Assassin's quest item!
  makeref(itm,Items[n]);
  itm.id                      = "pistol4_1";
  itm.sound                   = "OBJECTS\DUEL\pistol_big.wav";
  itm.shottype                = "pb"; //JRH
  itm.skiptrade               = false;  //BB you can sell them
  itm.skipsell                = true;   //BB you can't buy them
  itm.skiprand                = true;
  itm.skipequip               = false;
  itm.groupID                 = GUN_ITEM_TYPE;
  itm.name                    = "itmname_pistol4_1";
  itm.describe                = "itmdescr_pistol4_1";
  itm.folder                  = "ammo";
  itm.model                   = "pistol4_1";
  itm.picIndex                = 15;
  itm.picTexture              = "ITEMS_ccc";
  itm.price                   = 8479;    // BB (20000)
  itm.chargeQ                 = 4;
  itm.chargespeed             = 30;
  itm.dmg_min                 = 50.0;
  itm.dmg_max                 = 85.0; //BB(70)
  itm.minlevel                = 99;     //BB+PB added minlevel to improve rarity
  itm.accuracy                = 70;   //BB(55)
  itm.rare                    = 0.00;
  itm.nation                  = "";
  n++;

 //JRH: Portugize// Freeplay quest item!
  makeref(itm,Items[n]);
  itm.id                      = "portugize";
  itm.sound                   = "OBJECTS\DUEL\pistol_grape.wav";
  itm.shottype                = "pg"; //JRH
  itm.skiptrade               = false;  //BB you can sell them
  itm.skipsell                = true;   //BB you can't buy them
  itm.skiprand                = true;   // you can't randomly find it
  itm.skipequip               = false;
  itm.groupID                 = GUN_ITEM_TYPE;
  itm.name                    = "itmname_portugize";
  itm.describe                = "itmdescr_portugize";
  itm.folder                  = "ammo";
  itm.model                   = "portugize_back";
  itm.picIndex                = 11;
  itm.picTexture              = "ITEMS_JRH39";
  itm.price                   = 8479;
  itm.chargeQ                 = 5;
  itm.chargespeed             = 35;
  itm.dmg_min                 = 30.0;
  itm.dmg_max                 = 60.0;
  itm.minlevel                = 99;     //BB+PB added minlevel to improve rarity
  itm.accuracy                = 30;
  itm.rare                    = 0.00;
  itm.nation                  = "";
  n++;

  // Sandbag
  makeref(itm,Items[n]);
  itm.id                      = "bladeX2";
  itm.sound                   = "OBJECTS\duel\sword_inbody.wav";  // soundfile played when used
  //BB removed graphical effects of 'stars' when knocked out, like for cobblestone(non combustible unlike stinkpot+etherbottle)
  itm.stun                    = 0.75;     // stuns targets
  itm.stealth                 = 0.75;     // doesn't alarm victim
  itm.skiptrade               = false;    // you can sell the item
  itm.skipsell                = true;     // you can't buy them
  itm.skiprand                = false;
  itm.skipequip               = NO_SPECIALWEAPONED_NPC ;
  itm.groupID                 = BLADE_ITEM_TYPE;
  itm.name                    = "itmname_bladeX2";
  itm.describe                = "itmdescr_bladeX2";
  itm.folder                  = "ammo";
  itm.model                   = "Sandbag";
  itm.picIndex                = 2;
  itm.picTexture              = "ITEMS_ccc";
  itm.price                   = 18;  // BB (50)
  itm.dmg_min                 = 3.0;
  itm.dmg_max                 = 7.0;
  itm.piercing                = 0;
  itm.minlevel                = 1;
  itm.rare                    = 0.2; // Sulan (0.4)
  itm.block                   = 3;
  itm.nation                  = PIRATE;
  itm.secondary               = true;
  itm.sneaky                  = true; // PB: Sneaky Trader
  n++;

  // Thief's knife
  makeref(itm,Items[n]);
  itm.id                      = "bladeX3";
  itm.sound                   = "OBJECTS\shipcharge\sail_damage1.wav";  // soundfile played when used
  itm.steal                   = 0.65;   // gives you the target's money and weapons//BB(0.75)
  itm.skiptrade               = false;  // you can sell the item
  itm.skipsell                = true;   // you can't buy them
  itm.skiprand                = false;
  itm.skipequip               = NO_SPECIALWEAPONED_NPC ;
  itm.groupID                 = BLADE_ITEM_TYPE;
  itm.name                    = "itmname_bladeX3";
  itm.describe                = "itmdescr_bladeX3";
  itm.folder                  = "ammo";
  itm.model                   = "blade5";
  itm.picIndex                = 4;
  itm.picTexture              = "ITEMS_ccc";
  itm.price                   = 50;  //BB (25)
  itm.dmg_min                 = 1.0;
  itm.dmg_max                 = 1.0;
  itm.piercing                = 25;
  itm.minlevel                = 1;
  itm.rare                    = 0.25;  //BB (0.1)
  itm.block                   = 0;
  itm.param.time              = 0.1;
  itm.param.colorstart        = argb(64, 64, 64, 64);
  itm.param.colorend          = argb(0, 32, 32, 32);
  itm.secondary               = true;
  itm.nation                  = PIRATE;
  itm.sneaky                  = true; // PB: Sneaky Trader
  n++;

  // Borgiablade
  makeref(itm,Items[n]);
  itm.id                      = "bladeX1";
  itm.poison                  = 1;    // poisons targets
  itm.skiptrade               = false;  // you can sell the item
  itm.skipsell                = true;   // you can't buy them
  itm.skiprand                = false;
  itm.skipequip               = NO_SPECIALWEAPONED_NPC ;
  itm.groupID                 = BLADE_ITEM_TYPE;
  itm.name                    = "itmname_bladeX1";
  itm.describe                = "itmdescr_bladeX1";
  itm.folder                  = "ammo";
  itm.model                   = "blade2";
  itm.picIndex                = 9;
  itm.picTexture              = "ITEMS_ccc";
  itm.price                   = 98;     //BB (500)
  itm.dmg_min                 = 11.0;   //BB (10.0)
  itm.dmg_max                 = 15.0;   //BB (12.0)
  itm.piercing                = 20;     //BB (15)
  itm.rare                    = 0.3;    //Sulan (0.5)
  itm.minlevel                = 3;      //Sulan added minlevel to improve rarity.
  itm.block                   = 10;
  itm.param.time              = 0.1;
  itm.param.colorstart        = argb(64, 64, 64, 64);
  itm.param.colorend          = argb(0, 32, 32, 32);
  itm.nation                  = PIRATE;
  itm.sneaky                  = true; // PB: Sneaky Trader
  n++;
  // ccc special weapon assembly kit <--

  // BB keep progression from lowest value to highest linked with stats. High value unique player rewards.
  // Francis Drake's Sword (SLiB KevAtl) - renamed from blade28 plus new model and texture 09-10-2007// BB lowest value.
  makeref(itm,Items[n]);
  itm.id                      = "bladeFD";
  itm.skiptrade               = false;  //BB you can sell the item
  itm.skipsell                = true;   // you can't buy it
  itm.skiprand                = true;   // you can't randomly find it
  itm.skipequip               = false;
  itm.groupID                 = BLADE_ITEM_TYPE;
  itm.name                    = "itmname_bladeFD";
  itm.describe                = "itmdescr_bladeFD";
  itm.folder                  = "ammo";
  itm.model                   = "Drake_Sword";	// was "bladeFD"
  itm.picIndex                = 10;		// was 12
  itm.picTexture              = "ITEMS_AS";	// was "items_CCC"
  itm.price                   = 13460;  //BB (25000)
  itm.dmg_min                 = 28.0;   //BB (22.0) Stats based on English Officers Sabre(just better)
  itm.dmg_max                 = 43.0;   //BB (38.0)
  itm.piercing                = 70;
  itm.block                   = 65;     //Sulan (70)
  itm.minlevel                = 99;     //BB+PB
  itm.rare                    = 0.00;   // should be unique
  itm.param.time              = 0.1;
  itm.skill.fencing           = +1;
  itm.param.colorstart        = argb(64, 64, 64, 64);
  itm.param.colorend          = argb(0, 32, 32, 32);
  itm.nation                  = PIRATE;
  n++;

  // Alternative version of Francis Drake's sword for use by Francis Drake
  makeref(itm,Items[n]);
  itm.id                      = "bladeFD2";
  itm.skiptrade               = false;  //BB you can sell the item
  itm.skipsell                = true;   // you can't buy it
  itm.skiprand                = true;   // you can't randomly find it
  itm.skipequip               = false;
  itm.groupID                 = BLADE_ITEM_TYPE;
  itm.name                    = "itmname_bladeFD2";
  itm.describe                = "itmdescr_bladeFD2";
  itm.folder                  = "ammo";
  itm.model                   = "Drake_Sword";	// was "bladeFD"
  itm.picIndex                = 10;		// was 12
  itm.picTexture              = "ITEMS_AS";	// was "items_CCC"
  itm.price                   = 13460;  //BB (25000)
  itm.dmg_min                 = 28.0;   //BB (22.0) Stats based on English Officers Sabre(just better)
  itm.dmg_max                 = 43.0;   //BB (38.0)
  itm.piercing                = 70;
  itm.block                   = 65;     //Sulan (70)
  itm.minlevel                = 99;     //BB+PB
  itm.rare                    = 0.00;   // should be unique
  itm.param.time              = 0.1;
  itm.skill.fencing           = +1;
  itm.param.colorstart        = argb(64, 64, 64, 64);
  itm.param.colorend          = argb(0, 32, 32, 32);
  itm.nation                  = ENGLAND;
  n++;

  // Sword of Cortйs (SLiB KevAtl)
  makeref(itm,Items[n]);
  itm.id                      = "bladeSC";
  itm.skiptrade               = false;  //BB you can sell the item
  itm.skipsell                = true;   // you can't buy it
  itm.skiprand                = true;   // you can't randomly find it
  itm.skipequip               = false;
  itm.groupID                 = BLADE_ITEM_TYPE;
  itm.name                    = "itmname_bladeSC";
  itm.describe                = "itmdescr_bladeSC";
  itm.folder                  = "ammo";
  itm.model                   = "Cortes_Sword";// was "bladeSC"
  itm.picIndex                = 9;		// was 13
  itm.picTexture              = "ITEMS_AS";	// was "items_CCC"
  itm.price                   = 15660;  //BB (25000)
  itm.dmg_min                 = 25.0;
  itm.dmg_max                 = 40.0;
  itm.piercing                = 65;     //BB (90)
  itm.block                   = 85;
  itm.minlevel                = 99;     //BB+PB
  itm.rare                    = 0.00;   // should be unique
  itm.param.time              = 0.1;
  itm.skill.sneak             = -1;
  itm.skill.fencing           = +1;
  itm.param.colorstart        = argb(64, 64, 64, 64);
  itm.param.colorend          = argb(0, 32, 32, 32);
  itm.nation                  = SPAIN;
  n++;

  // Reward for killing Malcolm Hatcher
  makeref(itm,Items[n]);
  itm.id                      = "bladeMH";
  itm.skiptrade               = false;  // you can sell the item
  itm.skipsell                = true;   // you can't buy it
  itm.skiprand                = true;   // you can't randomly find it
  itm.skipequip               = false;
  itm.groupID                 = BLADE_ITEM_TYPE;
  itm.name                    = "itmname_bladeMH";
  itm.describe                = "itmdescr_bladeMH";
  itm.folder                  = "ammo";
  itm.model                   = "bladeMH";// was "bladeSC"
  itm.picIndex                = 11;
  itm.picTexture              = "ITEMS_AS";
  itm.price                   = 2345;  //
  itm.dmg_min                 = 30.0;
  itm.dmg_max                 = 44.0;
  itm.piercing                = 65;     //BB (90)
  itm.block                   = 30;
  itm.minlevel                = 99;     //BB+PB
  itm.rare                    = 0.00;   // should be unique
  itm.param.time              = 0.1;
  itm.skill.sneak             = +1;
  itm.param.colorstart        = argb(64, 64, 64, 64);
  itm.param.colorend          = argb(0, 32, 32, 32);
  itm.nation                  = SPAIN;
  n++;

  // Sword of Bartolomeu (Russian Team)
  makeref(itm,Items[n]);
  itm.id                      = "bladeBP";
  itm.skiptrade               = false;  //BB you can sell the item
  itm.skipsell                = true;   // you can't buy it
  itm.skiprand                = true;   // you can't randomly find it
  itm.skipequip               = false;
  itm.groupID                 = BLADE_ITEM_TYPE;
  itm.name                    = "itmname_bladeBP";
  itm.describe                = "itmdescr_bladeBP";
  itm.folder                  = "ammo";
  itm.model                   = "bladeBP";
  itm.picIndex                = 14;
  itm.picTexture              = "ITEMS_ccc";
  itm.price                   = 18350;  //BB (25000)
  itm.dmg_min                 = 29.0;   //BB (20.0)
  itm.dmg_max                 = 46.0;   //BB (36.0)
  itm.piercing                = 75;
  itm.block                   = 80;
  itm.minlevel                = 99;     //BB+PB
  itm.rare                    = 0.00;   // should be unique
  itm.param.time              = 0.1;
  itm.skill.fencing           = +1;
  itm.param.colorstart        = argb(64, 64, 64, 64);
  itm.param.colorend          = argb(0, 32, 32, 32);
  itm.nation                  = PIRATE;
  n++;

   // Sword of Elting (SuperDurnius re-colour)
  makeref(itm,Items[n]);
  itm.id                      = "Blade_ProudOfAnvil";
  itm.skiptrade               = false;  //BB you can sell the item
  itm.skipsell                = true;   // you can't buy it
  itm.skiprand                = true;   // you can't randomly find it
  itm.skipequip               = false;
  itm.groupID                 = BLADE_ITEM_TYPE;
  itm.name                    = "itmname_bladePOA";
  itm.describe                = "itmdescr_bladePOA";
  itm.folder                  = "ammo";
  itm.model                   = "Blade_ProudOfAnvil";
  itm.picIndex                = 12;
  itm.picTexture              = "ITEMS_22";
  itm.price                   = 6000;
  itm.dmg_min                 = 36.0;   
  itm.dmg_max                 = 48.0;   
  itm.piercing                = 55;
  itm.block                   = 44;
  itm.minlevel                = 99;     
  itm.rare                    = 0.00;   // should be unique
  itm.param.time              = 0.1;
  itm.skill.fencing           = +1;
  itm.param.colorstart        = argb(64, 64, 64, 64);
  itm.param.colorend          = argb(0, 32, 32, 32);
  itm.nation                  = PIRATE;
  n++;

   // Sword of Triton
  makeref(itm,Items[n]);
  itm.id                      = "Blade_Triton";
  itm.skiptrade               = false;  //BB you can sell the item
  itm.skipsell                = true;   // you can't buy it
  itm.skiprand                = true;   // you can't randomly find it
  itm.skipequip               = false;
  itm.groupID                 = BLADE_ITEM_TYPE;
  itm.name                    = "itmname_bladeTriton";
  itm.describe                = "itmdescr_bladeTriton";
  itm.folder                  = "ammo";
  itm.model                   = "bladetriton";
  itm.picIndex                = 16;
  itm.picTexture              = "ITEMS_ccc";
  itm.price                   = 10000;
  itm.dmg_min                 = 40.0;   
  itm.dmg_max                 = 60.0;   
  itm.piercing                = 60;
  itm.block                   = 30;
  itm.minlevel                = 99;     
  itm.rare                    = 0.00;   // should be unique
  itm.param.time              = 0.1;
  itm.param.colorstart        = argb(64, 64, 64, 64);
  itm.param.colorend          = argb(0, 32, 32, 32);
  itm.nation                  = PIRATE;
  n++;

  // TJ&PB: Neptune's Trident -->
  makeref(itm,Items[n]);
  itm.id                      = "Trident_Neptune";
  itm.skiptrade               = false;
  itm.skipsell                = true;
  itm.skiprand                = true;
  itm.skipequip               = true;
  itm.groupID                 = BLADE_ITEM_TYPE;
  itm.name                    = "itmname_tridentNeptune";
  itm.describe                = "itmdescr_tridentNeptune";
  itm.folder                  = "ammo";
  itm.model                   = "trident";
  itm.picIndex                = 7;
  itm.picTexture              = "ITEMS_AS";
  itm.price                   = 800000;
  itm.dmg_min                 = 40.0;
  itm.dmg_max                 = 60.0;
  itm.piercing                = 60;
  itm.block                   = 30;
  itm.minlevel                = 99;
  itm.rare                    = 0.00;
  itm.param.time              = 0.1;
  itm.param.colorstart        = argb(64, 64, 64, 64);
  itm.param.colorend          = argb(0, 32, 32, 32);
  itm.nation                  = PIRATE;
  n++;
  // TJ&PB: Neptune's Trident <--

  // Sword of Roxanne Lalliere (SuperDurnius re-colour)
  makeref(itm,Items[n]);
  itm.id                      = "blthag02";
  itm.skiptrade               = false;  //BB you can sell the item
  itm.skipsell                = true;   // you can't buy it
  itm.skiprand                = true;   // you can't randomly find it
  itm.skipequip               = false;
  itm.groupID                 = BLADE_ITEM_TYPE;
  itm.name                    = "itmname_blthag02";
  itm.describe                = "itmdescr_blthag02";
  itm.folder                  = "ammo";
  itm.model                   = "blthag02";
  itm.picIndex                = 11;
  itm.picTexture              = "ITEMS_22";
  itm.price                   = 3000;
  itm.dmg_min                 = 22.0;
  itm.dmg_max                 = 33.0;
  itm.piercing                = 40;
  itm.block                   = 38;
  itm.minlevel                = 99;
  itm.rare                    = 0.00;   // should be unique
  itm.param.time              = 0.1;
  itm.skill.fencing           = +1;
  itm.param.colorstart        = argb(64, 64, 64, 64);
  itm.param.colorend          = argb(0, 32, 32, 32);
  itm.nation                  = PIRATE;
  n++;

  // Angel Sword
  makeref(itm,Items[n]);
  itm.id                      = "blangel";
  itm.skiptrade               = false;  //BB you can sell the item
  itm.skipsell                = true;   // you can't buy it
  itm.skiprand                = true;   // you can't randomly find it
  itm.skipequip               = false;
  itm.groupID                 = BLADE_ITEM_TYPE;
  itm.name                    = "itmname_blangel";
  itm.describe                = "itmdescr_blangel";
  itm.folder                  = "ammo";
  itm.model                   = "blangel";
  itm.picIndex                = 15;
  itm.picTexture              = "ITEMS_BOP2";
  itm.price                   = 5000;
  itm.dmg_min                 = 20.0;
  itm.dmg_max                 = 35.0;
  itm.piercing                = 50;
  itm.block                   = 25;
  itm.minlevel                = 99;
  itm.rare                    = 0.00;   // should be unique
  itm.param.time              = 0.1;
  itm.skill.fencing           = -1;
  itm.skill.leadership        = +1;
  itm.skill.commerce          = +1;
  itm.param.colorstart        = argb(64, 64, 64, 64);
  itm.param.colorend          = argb(0, 32, 32, 32);
  itm.nation                  = HOLLAND;
  n++;

  // Jack Sparrow's Cutlass (Russian Mod)//BB slightly 'crazy' weapon - it is JS!//BB highest value.
  makeref(itm,Items[n]);
  itm.id                      = "blade42";
  itm.skiptrade               = false;    //BB you can sell the item
  itm.skipsell                = true;     // you can't buy it
  itm.skiprand                = true;     // you can't randomly find it
  itm.skipequip               = false;
  //itm.skipequip   = NO_SPECIALWEAPONED_NPC ;
  itm.groupID                 = BLADE_ITEM_TYPE;
  itm.name                    = "itmname_blade42";
  itm.describe                = "itmdescr_blade42";
  itm.folder                  = "ammo";
  itm.model                   = "blade42";
  itm.picIndex                = 8;
  itm.picTexture              = "ITEMS_23";
  itm.price                   = 19304;    //BB (25000)
  itm.dmg_min                 = 10.0;     //BB (40.0) - now very low!
  itm.dmg_max                 = 65.0;     //BB (55.0) - now very high!
  itm.piercing                = 75;       //BB (60)
  itm.block                   = 85;       //BB (60)
  itm.minlevel                = 99;       //BB+PB added minlevel to improve rarity.
  itm.rare                    = 0.00;     // should be unique
  itm.param.time              = 0.1;
  itm.skill.fencing           = +1;
  itm.param.colorstart        = argb(64, 64, 64, 64);
  itm.param.colorend          = argb(0, 32, 32, 32);
  itm.nation                  = PIRATE;
  n++;

  //JRH Indian Shield hand
  makeref(itm,Items[n]);
  itm.id                      = "shield_hand";
  itm.sound                   = "OBJECTS\duel\shield.wav";  // soundfile played when used
  itm.skiptrade               = false;    // you can sell the item
  itm.skipsell                = true;     // you can't buy them
  itm.skiprand                = true;
  itm.skipequip               = false;
  itm.groupID                 = BLADE_ITEM_TYPE;
  itm.name                    = "itmname_shield_hand";
  itm.describe                = "itmdescr_shield_hand";
  itm.folder                  = "ammo";
  itm.model                   = "shield_hand";
  itm.picIndex                = 3;
  itm.picTexture              = "ITEMS_BOP2";
  itm.price                   = 18;
  itm.dmg_min                 = 5.0;
  itm.dmg_max                 = 15.0;
  itm.piercing                = 10;
  itm.minlevel                = 1;
  itm.rare                    = 0.0;
  itm.block                   = 90;
  itm.nation                  = PIRATE;
  n++;

  //JRH Indian Shield back
  makeref(itm,Items[n]);
  itm.id                      = "shield_back";
  itm.sound                   = "OBJECTS\duel\shield.wav";  // soundfile played when used
  itm.skiptrade               = false;    // you can sell the item
  itm.skipsell                = true;     // you can't buy them
  itm.skiprand                = true;
  itm.skipequip               = false;
  itm.groupID                 = BLADE_ITEM_TYPE;
  itm.name                    = "itmname_shield_back";
  itm.describe                = "itmdescr_shield_back";
  itm.folder                  = "ammo";
  itm.model                   = "shield_back";
  itm.picIndex                = 3;
  itm.picTexture              = "ITEMS_BOP2";
  itm.price                   = 18;
  itm.dmg_min                 = 5.0;
  itm.dmg_max                 = 15.0;
  itm.piercing                = 10;
  itm.minlevel                = 1;
  itm.rare                    = 0.0;
  itm.block                   = 90;
  itm.nation                  = PIRATE;
  n++;

//JRH
  makeref(itm,Items[n]);
  itm.id          = "zombie_touch";
  itm.poison      = 1;    // poisons targets
  itm.skiptrade   = true; // you can't buy them
  itm.skiprand    = true; // you can't find them
  itm.skipequip   = true; // not used in auto equip
  itm.groupID     = BLADE_ITEM_TYPE;
  itm.name        = "itmname_zombie_touch";
  itm.describe    = "itmdescr_zombie_touch";
  itm.folder      = "ammo";
  itm.model       = "invisible";    // Completely empty model; had to be added to enable you to 'draw' your fists
  itm.picIndex    = 11;         // Picture made by Petros
  itm.picTexture  = "ITEMS_ccc";
  itm.price       = 1;
  itm.minlevel    = 1;
  itm.rare        = 1.0;
  itm.dmg_min     = 1;
  itm.dmg_max     = 1;
  itm.piercing    = 0;
  itm.block       = 0;
  n++;

//JRH
  makeref(itm,Items[n]);
  itm.id          = "bladebone";
   itm.sound = "OBJECTS\DUEL\boom.wav";
  itm.skiptrade   = true; // you can't buy them
  itm.skiprand    = true; // you can't find them
  itm.skipequip   = true; // not used in auto equip
  itm.groupID     = BLADE_ITEM_TYPE;
  itm.name        = "itmname_bladebone";
  itm.describe    = "itmdescr_bladebone";
  itm.folder      = "ammo";
  itm.model       = "bone";
  itm.picIndex    = 11;
  itm.picTexture  = "ITEMS_ccc";
  itm.price       = 1;
  itm.minlevel    = 1;
  itm.rare        = 1.0;
  itm.dmg_min     = 5;
  itm.dmg_max     = 5;
  itm.piercing    = 10;
  itm.block       = 5;
  n++;

  // GR: chief's tomahawk for Crystal Skull sidequest
  makeref(itm,Items[n]);
  itm.id                      = "tomahawk_chief";
  itm.skiptrade               = false;  //BB you can sell the item
  itm.skipsell                = true;   // you can't buy it
  itm.skiprand                = true;   // you can't randomly find it
  itm.skipequip               = false;
  itm.groupID                 = BLADE_ITEM_TYPE;
  itm.name                    = "itmname_tomahawk_chief";
  itm.describe                = "itmdescr_tomahawk_chief";
  itm.folder                  = "ammo";
  itm.model                   = "tomahawk_chief";
  itm.picIndex                = 8;
  itm.picTexture              = "ITEMS_GR";
  itm.price                   = 1500;
  itm.dmg_min                 = 28.0;
  itm.dmg_max                 = 45.0;
  itm.piercing                = 70;
  itm.block                   = 13;
  itm.minlevel                = 99;     //BB+PB
  itm.rare                    = 0.00;   // should be unique
  itm.param.time              = 0.1;
  itm.skill.leadership        = +1;
  itm.param.colorstart        = argb(64, 64, 64, 64);
  itm.param.colorend          = argb(0, 32, 32, 32);
  itm.nation                  = PIRATE;
  n++;

if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0 || sti(GetStorylineVar(FindCurrentStoryline(), "BUG_PUZZLES")) > 0
|| sti(GetStorylineVar(FindCurrentStoryline(), "BART_PUZZLES")) > 0)
{
  //JRH more special (quest) weapons -->
  // Throwing Pistols
  makeref(itm,Items[n]);
  itm.id = "pistolthrow5";
  itm.sound = "OBJECTS\DUEL\pistol_throw.wav";
  itm.skipsell = true;	// you can't buy it or sell it
  itm.skiprand = true;
  itm.skipequip = true;
  itm.groupID = GUN_ITEM_TYPE;
  itm.name = "itmname_pistolthrow5";
  itm.describe = "itmdescr_pistolthrow5";
  itm.folder = "ammo";
  itm.model = "OtherItemsJRH\pclub201";
  itm.picIndex = 8;
  itm.picTexture = "ITEMS_JRH";
  itm.price = 2;
  itm.chargeQ = 5;
  itm.chargespeed = 0.5;
  itm.dmg_min = 7.0;
  itm.dmg_max = 12.0;
  itm.accuracy = 80;
  itm.rare = 0.00;	// should be unique
  n++;

  // Throwing Pistols
  makeref(itm,Items[n]);
  itm.id = "pistolthrow4";
  itm.sound = "OBJECTS\DUEL\pistol_throw.wav";
  itm.skipsell = true;	// you can't buy it or sell it
  itm.skiprand = true;
  itm.skipequip = true;
  itm.groupID = GUN_ITEM_TYPE;
  itm.name = "itmname_pistolthrow4";
  itm.describe = "itmdescr_pistolthrow4";
  itm.folder = "ammo";
  itm.model = "OtherItemsJRH\pclub202";
  itm.picIndex = 8;
  itm.picTexture = "ITEMS_JRH";
  itm.price = 2;
  itm.chargeQ = 4;
  itm.chargespeed = 0.5;
  itm.dmg_min = 7.0;
  itm.dmg_max = 12.0;
  itm.accuracy = 80;
  itm.rare = 0.00;	// should be unique
  n++;

  // Throwing Pistols
  makeref(itm,Items[n]);
  itm.id = "pistolthrow3";
  itm.sound = "OBJECTS\DUEL\pistol_throw.wav";
  itm.skipsell = true;	// you can't buy it or sell it
  itm.skiprand = true;
  itm.skipequip = true;
  itm.groupID = GUN_ITEM_TYPE;
  itm.name = "itmname_pistolthrow3";
  itm.describe = "itmdescr_pistolthrow3";
  itm.folder = "ammo";
  itm.model = "OtherItemsJRH\pclub204";
  itm.picIndex = 8;
  itm.picTexture = "ITEMS_JRH";
  itm.price = 2;
  itm.chargeQ = 3;
  itm.chargespeed = 0.5;
  itm.dmg_min = 7.0;
  itm.dmg_max = 12.0;
  itm.accuracy = 80;
  itm.rare = 0.00;	// should be unique
  n++;

  // Throwing Pistols
  makeref(itm,Items[n]);
  itm.id = "pistolthrow2";
  itm.sound = "OBJECTS\DUEL\pistol_throw.wav";
  itm.skipsell = true;	// you can't buy it or sell it
  itm.skiprand = true;
  itm.skipequip = true;
  itm.groupID = GUN_ITEM_TYPE;
  itm.name = "itmname_pistolthrow2";
  itm.describe = "itmdescr_pistolthrow2";
  itm.folder = "ammo";
  itm.model = "OtherItemsJRH\pclub205";
  itm.picIndex = 8;
  itm.picTexture = "ITEMS_JRH";
  itm.price = 2;
  itm.chargeQ = 2;
  itm.chargespeed = 0.5;
  itm.dmg_min = 7.0;
  itm.dmg_max = 12.0;
  itm.accuracy = 80;
  itm.rare = 0.00;	// should be unique
  n++;

  // Throwing Pistols
  makeref(itm,Items[n]);
  itm.id = "pistolthrow1";
  itm.sound = "OBJECTS\DUEL\pistol_throw.wav";
  itm.skipsell = true;	// you can't buy it or sell it
  itm.skiprand = true;
  itm.skipequip = true;
  itm.groupID = GUN_ITEM_TYPE;
  itm.name = "itmname_pistolthrow1";
  itm.describe = "itmdescr_pistolthrow1";
  itm.folder = "ammo";
  itm.model = "OtherItemsJRH\pclub206";
  itm.picIndex = 8;
  itm.picTexture = "ITEMS_JRH";
  itm.price = 2;
  itm.chargeQ = 1;
  itm.chargespeed = 0.5;
  itm.dmg_min = 7.0;
  itm.dmg_max = 12.0;
  itm.accuracy = 80;
  itm.rare = 0.00;	// should be unique
  n++;

  // Throwingknife not poisoned, 1 thug QC + Vane boarders
  makeref(itm,Items[n]);
  itm.id = "pistoldart";
  itm.throw = 1;	// new attribute, weapon that you throw, so only one time use
  itm.sound = "OBJECTS\duel\knife_male.wav";
  itm.skipsell = true;	// you can't buy it or sell it
  itm.skiprand = true;	//special for brothel quest
  itm.skipequip = true;
  itm.groupID = GUN_ITEM_TYPE;
  itm.name = "itmname_pistoldart";
  itm.describe = "itmdescr_pistoldart";
  itm.folder = "ammo";
  itm.model  = "PoisenedDagger";
  itm.picIndex = 16;
  itm.picTexture = "ITEMS_JRH28";
  itm.price = 1;
  itm.chargeQ = 1;
  itm.chargespeed = 0.5;
  itm.dmg_min = 5.0;
  itm.dmg_max = 10.0;
  itm.accuracy = 80;
  itm.rare = 0.00;	// should be unique
  n++;

  // Throwingaxe, Vane boarders
  makeref(itm,Items[n]);
  itm.id = "pistolthrowaxe";
  itm.sound = "OBJECTS\DUEL\axe_kill_male.wav";
  itm.throw = 1;	// new attribute, weapon that you throw, so only one time use
  itm.skipsell = true;	// you can't buy it or sell it
  itm.skiprand = true;
  itm.skipequip = true;
  itm.groupID = GUN_ITEM_TYPE;
  itm.name = "itmname_pistolthrowaxe";
  itm.describe = "itmdescr_pistolthrowaxe";
  itm.folder = "ammo";
  itm.model = "OtherItemsJRH\axe5";
  itm.picIndex = 8;
  itm.picTexture = "ITEMS_JD";
  itm.price = 0;
  itm.chargeQ = 1;
  itm.chargespeed = 0.5;
  itm.dmg_min = 10.0;
  itm.dmg_max = 20.0;
  itm.accuracy = 80;
  itm.rare = 0.00;	// should be unique
  n++;

//JRH
  makeref(itm,Items[n]);
  itm.id = "pistolcenser";
  itm.enblrld     	      = true;
  itm.shottype                = "";
  itm.sound = "OBJECTS\DUEL\censer.wav";
  itm.skipsell = true;	// you can't buy it or sell it
  itm.skiprand = true;
  itm.groupID = GUN_ITEM_TYPE;
  itm.name = "itmname_pistolcenser";
  itm.describe = "itmdescr_pistolcenser";
  itm.folder = "Ammo";
  itm.model = "OtherItemsJRH\pistolcenser";
  itm.picIndex = 11;
  itm.picTexture = "ITEMS_JRH14";
  itm.price = 0;
  itm.chargeQ = 1;
  itm.chargespeed = 0.1;
  itm.dmg_min = 10.0;
  itm.dmg_max = 20.0;
  itm.accuracy = 80;
  itm.rare = 0.00;	// should be unique
  n++;

//JRH pistolcenser for protection only
  makeref(itm,Items[n]);
  itm.id = "pistolcenserD";			//for defensive use
  itm.enblrld     	      = true;
  itm.shottype                = "inc";
  itm.sound = "OBJECTS\DUEL\censer.wav";
  itm.skipsell = true;	// you can't buy it or sell it
  itm.skiprand = true;
  itm.groupID = GUN_ITEM_TYPE;
  itm.name = "itmname_pistolcenserD";
  itm.describe = "itmdescr_pistolcenserD";
  itm.folder = "Ammo";
  itm.model = "OtherItemsJRH\pistolcenser";
  itm.picIndex = 11;
  itm.picTexture = "ITEMS_JRH14";
  itm.price = 1;
  itm.chargeQ = 1;
  itm.chargespeed = 0.2;
  itm.dmg_min = 0.0;
  itm.dmg_max = 0.0;
  itm.accuracy = 100;
  itm.rare = 0.00;	// should be unique
  n++;

//JRH pistolcenser without incense
  makeref(itm,Items[n]);
  itm.id = "pistolcenserE";			//for defensive use
  itm.enblrld     	      = true;
  itm.shottype                = "";
  //itm.sound = "OBJECTS\DUEL\censer.wav";
  itm.skiptrade               = false;  //BB you can sell the item
  itm.skipsell                = true;   // you can't buy it
  itm.skiprand                = true;   // you can't randomly find it
  itm.skipequip               = false;
  itm.groupID = GUN_ITEM_TYPE;
  itm.name = "itmname_pistolcenserE";
  itm.describe = "itmdescr_pistolcenserE";
  itm.folder = "Ammo";
  itm.model = "OtherItemsJRH\pistolcenser_empty";
  itm.picIndex = 15;
  itm.picTexture = "ITEMS_JRH36";
  itm.price = 450;
  itm.chargeQ = 0;
  itm.chargespeed = 0.1;
  itm.dmg_min = 0.0;
  itm.dmg_max = 0.0;
  itm.accuracy = 0;
  itm.rare = 0.00;	// should be unique
  n++;

  // Hand cannon
  makeref(itm,Items[n]);
  itm.id = "pistolcannon";
  itm.multidmg                = 1;
  itm.shottype                = "pg6";
  //itm.sound = "OBJECTS\SHIPCHARGE\CR24C.wav";		//+ additional sound in LAi_events
  itm.skipsell = true;	// you can't buy it or sell it
  itm.skiprand = true;
  itm.groupID = GUN_ITEM_TYPE;
  itm.name = "itmname_pistolcannon";
  itm.describe = "itmdescr_pistolcannon";
  itm.folder = "Ammo";
  itm.model = "OtherItemsJRH\pistolcannon";
  itm.picIndex = 11;
  itm.picTexture = "ITEMS_JRH37";
  itm.price = 0;
  itm.chargeQ = 1;
  itm.chargespeed = 40.0;
  itm.dmg_min = 200.0;
  itm.dmg_max = 400.0;
  itm.accuracy = 80;
  itm.rare = 0.00;	// should be unique
  n++;

  // BladePistolclub
  makeref(itm,Items[n]);
  itm.id 			= "bladepclub203";
  itm.pistolclub 		= 1; 	// new attribute, exclusively for your bladepclub
  itm.skipsell = true;	// you can't buy it or sell it
  itm.skiprand 	= true;	// you can't find them
  itm.skipequip 	= true;	// not used in auto equip
  itm.groupID 	= BLADE_ITEM_TYPE;
  itm.name 	= "itmname_bladepclub203";
  itm.describe 	= "itmdescr_bladepclub203";
  itm.folder 	= "ammo";
  itm.model = "OtherItemsJRH\pclub203";
  itm.picIndex 	= 16;
  itm.picTexture 	= "ITEMS_JRH4";
  itm.price 	= 0;				//so you can't mess up things by giving it away
  itm.minlevel 	= 1;
  itm.rare 	= 0.00;				// should be unique
  itm.dmg_min 	= 0;
  itm.dmg_max 	= 0;
  itm.piercing 	= 100;
  itm.block 	= 5;
  itm.disarm	= 0;
  n++;

  // Bladeplank
  makeref(itm,Items[n]);
  itm.id = "bladeplank";
  itm.sound = "OBJECTS\DUEL\plank.wav";	// soundfile played when used
  itm.skipsell = true;	// you can't buy them
  itm.skiprand = true;
  itm.skipequip = true;
  itm.groupID = BLADE_ITEM_TYPE;
  itm.name = "itmname_bladeplank";
  itm.describe = "itmdescr_bladeplank";
  itm.folder = "ammo";
  itm.model = "OtherItemsJRH\bladeplank";
  itm.picIndex = 6;
  itm.picTexture = "ITEMS_JRH4";
  itm.price = 0;
  itm.dmg_min = 5.0;
  itm.dmg_max = 15.0;
  itm.piercing = 5;
  itm.minlevel = 1;
  itm.rare = 0.00;				// should be unique
  itm.block = 25;
  itm.param.time = 0.1;
  itm.param.colorstart = argb(64, 64, 64, 64);
  itm.param.colorend = argb(0, 32, 32, 32);
  itm.disarm	= 0;
  n++;

  // Bladeboom
  makeref(itm,Items[n]);
  itm.id = "bladeboom";
  itm.sound = "OBJECTS\DUEL\boom.wav";	// soundfile played when used
  itm.skipsell = true;	// you can't buy them
  itm.skiprand = true;
  itm.skipequip = true;
  itm.groupID = BLADE_ITEM_TYPE;
  itm.name = "itmname_bladeboom";
  itm.describe = "itmdescr_bladeboom";
  itm.folder = "ammo";
  itm.model = "OtherItemsJRH\bladeboom";
  itm.picIndex = 7;
  itm.picTexture = "ITEMS_JRH4";
  itm.price = 0;
  itm.dmg_min = 8.0;
  itm.dmg_max = 17.0;
  itm.piercing = 10;
  itm.minlevel = 1;
  itm.rare = 0.00;				// should be unique
  itm.block = 15;
  itm.param.time = 0.1;
  itm.param.colorstart = argb(64, 64, 64, 64);
  itm.param.colorend = argb(0, 32, 32, 32);
  itm.disarm	= 0;
  n++;

  makeref(itm,Items[n]);
  itm.id = "pistolboom";
  itm.shottype           = "pb";
  itm.skipsell = true;	// you can't buy it or sell it
  itm.skiprand = true;
  itm.groupID = GUN_ITEM_TYPE;
  itm.name = "itmname_pistolboom";
  itm.describe = "itmdescr_pistolboom";
  itm.folder = "Ammo";
  itm.model = "OtherItemsJRH\pistolboom";
  itm.picIndex = 7;
  itm.picTexture = "ITEMS_JRH4";
  itm.price = 0;
  itm.chargeQ = 0;
  itm.chargespeed = 0.1;
  itm.dmg_min = 0.0;
  itm.dmg_max = 0.0;
  itm.accuracy = 0;
  itm.rare = 0.00;
  n++;

  // Bladeanchor
  makeref(itm,Items[n]);
  itm.id = "bladeanchor";
  itm.sound = "OBJECTS\DUEL\anchor.wav";
  itm.skipsell = true;	// you can't buy them
  itm.skiprand = true;
  itm.skipequip = NO_SPECIALWEAPONED_NPC ;
  itm.groupID = BLADE_ITEM_TYPE;
  itm.name = "itmname_bladeanchor";
  itm.describe = "itmdescr_bladeanchor";
  itm.folder = "ammo";
  itm.model = "OtherItemsJRH\anchor";
  itm.picIndex = 8;
  itm.picTexture = "ITEMS_JRH4";
  itm.price = 0;
  itm.dmg_min = 10.0;
  itm.dmg_max = 20.0;
  itm.piercing = 15;
  itm.minlevel = 1;
  itm.rare = 0.00;				// should be unique
  itm.block = 10;
  itm.param.time = 0.1;
  itm.param.colorstart = argb(64, 64, 64, 64);
  itm.param.colorend = argb(0, 32, 32, 32);
  itm.disarm	= 0;
  n++;

  // Bladeanchor big
  makeref(itm,Items[n]);
  itm.id = "bladeanchor_big";
  itm.sound = "OBJECTS\DUEL\anchor.wav";
  itm.skipsell = true;	// you can't buy them
  itm.skiprand = true;
  itm.skipequip = NO_SPECIALWEAPONED_NPC ;
  itm.groupID = BLADE_ITEM_TYPE;
  itm.name = "itmname_bladeanchor_big";
  itm.describe = "itmdescr_bladeanchor_big";
  itm.folder = "ammo";
  itm.model = "OtherItemsJRH\bladeanchor_big";
  itm.picIndex = 15;
  itm.picTexture = "ITEMS_JRH28";
  itm.price = 0;
  itm.dmg_min = 10.0;
  itm.dmg_max = 20.0;
  itm.piercing = 15;
  itm.minlevel = 1;
  itm.rare = 0.00;				// should be unique
  itm.block = 10;
  itm.param.time = 0.1;
  itm.param.colorstart = argb(64, 64, 64, 64);
  itm.param.colorend = argb(0, 32, 32, 32);
  itm.disarm	= 0;
  n++;

  // Bladespyglass6, Selkirk
  makeref(itm,Items[n]);
  itm.id = "bladespyglass6";
  itm.sound = "OBJECTS\DUEL\spyglass.wav";
  itm.skipsell = true;	// you can't buy them
  itm.skiprand = true;
  itm.skipequip = NO_SPECIALWEAPONED_NPC ;
  itm.groupID = BLADE_ITEM_TYPE;
  itm.name = "itmname_bladespyglass6";
  itm.describe = "itmdescr_bladespyglass6";
  itm.folder = "ammo";
  itm.model = "OtherItemsJRH\bladespyglass6";
  itm.picIndex = 10;
  itm.picTexture = "ITEMS_JRH24";
  itm.price = 0;
  itm.dmg_min = 5.0;
  itm.dmg_max = 10.0;
  itm.piercing = 5;
  itm.minlevel = 1;
  itm.rare = 0.00;				// should be unique
  itm.block = 10;
  itm.param.time = 0.1;
  itm.param.colorstart = argb(64, 64, 64, 64);
  itm.param.colorend = argb(0, 32, 32, 32);
  itm.disarm	= 0;
  n++;

  // Bladechalice
  makeref(itm,Items[n]);
  itm.id = "bladechalice";
  itm.sound = "OBJECTS\DUEL\chalice.wav";
  itm.skipsell = true;	// you can't buy them
  itm.skiprand = true;
  itm.skipequip = NO_SPECIALWEAPONED_NPC ;
  itm.groupID = BLADE_ITEM_TYPE;
  itm.name = "itmname_bladechalice";
  itm.describe = "itmdescr_bladechalice";
  itm.folder = "ammo";
  itm.model = "OtherItemsJRH\bladechalice";
  itm.picIndex = 9;
  itm.picTexture = "ITEMS_JRH14";
  itm.price = 0;			//why 10?
  itm.dmg_min = 7.0;
  itm.dmg_max = 13.0;
  itm.piercing = 5;
  itm.minlevel = 1;
  itm.rare = 0.00;				// should be unique
  itm.block = 7;
  itm.param.time = 0.1;
  itm.param.colorstart = argb(64, 64, 64, 64);
  itm.param.colorend = argb(0, 32, 32, 32);
  itm.disarm	= 0;
  n++;

  // Blade candelabre
  makeref(itm,Items[n]);
  itm.id = "bladecandelabre";
  itm.sound = "OBJECTS\DUEL\candelabre.wav";
  itm.skipsell = true;	// you can't buy them
  itm.skiprand = true;
  itm.skipequip = NO_SPECIALWEAPONED_NPC ;
  itm.groupID = BLADE_ITEM_TYPE;
  itm.name = "itmname_bladecandelabre";
  itm.describe = "itmdescr_bladecandelabre";
  itm.folder = "ammo";
  itm.model = "OtherItemsJRH\bladecandelabre";
  itm.picIndex = 13;
  itm.picTexture = "ITEMS_JRH14";
  itm.price = 0;
  itm.dmg_min = 9.0;
  itm.dmg_max = 17.0;
  itm.piercing = 5;
  itm.minlevel = 1;
  itm.rare = 0.00;				// should be unique
  itm.block = 9;
  itm.param.time = 0.1;
  itm.param.colorstart = argb(64, 64, 64, 64);
  itm.param.colorend = argb(0, 32, 32, 32);
  n++;

  // Blade reliquary
  makeref(itm,Items[n]);
  itm.id = "bladereliquary";
  itm.sound = "OBJECTS\VOICES\skeleton_body2.wav";
  itm.always.fx.qty = 1;
  itm.always.fx.effect0 = "blast_dirt_small";
  itm.always.fx.effect0.time = 5;
  itm.skipsell = true;	// you can't buy them
  itm.skiprand = true;
  itm.skipequip = NO_SPECIALWEAPONED_NPC ;
  itm.groupID = BLADE_ITEM_TYPE;
  itm.name = "itmname_bladereliquary";
  itm.describe = "itmdescr_bladereliquary";
  itm.folder = "ammo";
  itm.model = "OtherItemsJRH\bladereliquary";
  itm.picIndex = 12;
  itm.picTexture = "ITEMS_JRH14";
  itm.price = 0;
  itm.dmg_min = 5.0;
  itm.dmg_max = 9.0;
  itm.piercing = 5;
  itm.minlevel = 1;
  itm.rare = 0.00;				// should be unique
  itm.block = 5;
  itm.param.time = 0.1;
  itm.param.colorstart = argb(64, 64, 64, 64);
  itm.param.colorend = argb(0, 32, 32, 32);
  n++;

  // Blade censer
  makeref(itm,Items[n]);
  itm.id = "bladecenser";
  itm.sound = "OBJECTS\DUEL\censer.wav";
  itm.always.fx.qty = 1;
  itm.always.fx.effect0 = "gunfire";
  itm.always.fx.effect0.time = 7;
  itm.skipsell = true;	// you can't buy them
  itm.skiprand = true;
  itm.skipequip = NO_SPECIALWEAPONED_NPC ;
  itm.groupID = BLADE_ITEM_TYPE;
  itm.name = "itmname_bladecenser";
  itm.describe = "itmdescr_bladecenser";
  itm.folder = "ammo";
  itm.model = "OtherItemsJRH\bladecenser";
  itm.picIndex = 11;
  itm.picTexture = "ITEMS_JRH14";
  itm.price = 0;
  itm.dmg_min = 3.0;
  itm.dmg_max = 5.0;
  itm.piercing = 5;
  itm.minlevel = 1;
  itm.rare = 0.00;				// should be unique
  itm.block = 3;
  itm.param.time = 0.1;
  itm.param.colorstart = argb(64, 64, 64, 64);
  itm.param.colorend = argb(0, 32, 32, 32);
  n++;

  // Blade stool
  makeref(itm,Items[n]);
  itm.id = "bladestool";
  itm.sound = "PEOPLE\wood1.wav";		// soundfile played when used
  itm.skipsell = true;	// you can't buy it or sell it
  itm.skiprand = true;
  itm.skipequip = true;
  itm.groupID = BLADE_ITEM_TYPE;
  itm.name = "itmname_bladestool";
  itm.describe = "itmdescr_bladestool";
  itm.folder = "ammo";
  itm.model = "OtherItemsJRH\bladestool";
  itm.picIndex = 7;
  itm.picTexture = "ITEMS_CCC";
  itm.price = 0;
  itm.dmg_min = 5.0;
  itm.dmg_max = 10.0;
  itm.piercing = 10;
  itm.minlevel = 1;
  itm.rare = 0.00;				// should be unique
  itm.block = 5;
  itm.param.time = 0.1;
  itm.param.colorstart = argb(64, 64, 64, 64);
  itm.param.colorend = argb(0, 32, 32, 32);
  itm.disarm	= 0;
  n++;

  // Blade broom
  makeref(itm,Items[n]);
  itm.id = "bladebroom";
  itm.sound = "PEOPLE\step_sand.wav";	// soundfile played when used
  itm.skipsell = true;	// you can't buy it or sell it
  itm.skiprand = true;
  itm.skipequip = true;
  itm.groupID = BLADE_ITEM_TYPE;
  itm.name = "itmname_bladebroom";
  itm.describe = "itmdescr_bladebroom";
  itm.folder = "ammo";
  itm.model = "OtherItemsJRH\bladebroom";
  itm.picIndex = 12;
  itm.picTexture = "ITEMS_JRH21";
  itm.price = 0;
  itm.dmg_min = 5.0;
  itm.dmg_max = 5.0;
  itm.piercing = 10;
  itm.minlevel = 1;
  itm.rare = 0.00;				// should be unique
  itm.block = 10;
  itm.param.time = 0.1;
  itm.param.colorstart = argb(64, 64, 64, 64);
  itm.param.colorend = argb(0, 32, 32, 32);
  itm.disarm	= 0;
  n++;

  // Fake Blunderbuss (right hand), mistress uses it on roof
  makeref(itm,Items[n]);
  itm.id = "bladebbuss";
  itm.sound = "OBJECTS\DUEL\club_bbuss.wav";	// soundfile played when used
  itm.skipsell = true;	// you can't buy it or sell it
  itm.skiprand = true;
  itm.skipequip = true;
  itm.groupID = BLADE_ITEM_TYPE;
  itm.name = "itmname_bladebbuss";
  itm.describe = "itmdescr_bladebbuss";
  itm.folder = "ammo";
  itm.model = "OtherItemsJRH\bladebbuss";
  itm.picIndex = 7;
  itm.picTexture = "ITEMS_CCC";
  itm.price = 0;
  itm.dmg_min = 8.0;
  itm.dmg_max = 17.0;
  itm.piercing = 10;
  itm.minlevel = 1;
  itm.rare = 0.00;				// should be unique
  itm.block = 10;
  itm.param.time = 0.1;
  itm.param.colorstart = argb(64, 64, 64, 64);
  itm.param.colorend = argb(0, 32, 32, 32);
  itm.disarm	= 0;
  n++;

 // Clubmusketoon
  makeref(itm,Items[n]);
  itm.id 			= "clubmusketoon";
  itm.rifleclub 		= 1; 	// new attribute, exclusively for your rifleclub
  itm.skipsell = true;	// you can't buy it or sell it
  itm.skiprand 	= true;	// you can't find them
  itm.skipequip 	= true;	// not used in auto equip
  itm.groupID 	= BLADE_ITEM_TYPE;
  itm.name 	= "itmname_clubmusketoon";
  itm.describe 	= "itmdescr_clubmusketoon";
  itm.folder 	= "ammo";
  itm.model = "OtherItemsJRH\clubmusketoon";
  itm.picIndex 	= 9;
  itm.picTexture = "ITEMS_JRH24";
  itm.price 	= 0;				//so you can't mess up things by giving it away
  itm.minlevel 	= 1;
  itm.rare 	= 0.00;				// should be unique
  itm.dmg_min 	= 0;
  itm.dmg_max 	= 0;
  itm.piercing 	= 100;
  itm.block 	= 10;
  itm.disarm	= 0;
  n++;
  //JRH more special (quest) weapons <--
}


  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  // AXES Models and textures from SLiB Mod. Jack Davidson
  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  // AXES:       ItemIndex                       picIndex         Price          Piercing   Nation (-1 for general)
  //               |bladeID   modelID               | rare          |  minDamage     |Blocking|       DisableWeaponsMod
  //               |  |          | picTexture       |  |   MinLevel |   | maxDamage  |   |    |    Disarm  |      Available in period      Last period of availability
  //---------------|--|----------|----------|-------|--|------|-----|---|-----|------|---|----|-----|------|--------------|----------------------------|----------------------------
  n = InitBlade(n,"bladeaxe3","axe3", "JD",         8, 0.90,  1,   20, 10.0, 18.0, 30,  4,  PIRATE, 1,     1,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Hatchet//BB
  n = InitBlade(n,"bladeaxe1","axe1", "JD",         6, 0.37,  1,   33, 10.0, 26.0, 40,  5,  PIRATE, 1,     1,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Axe //BB
  n = InitBlade(n,"bladeaxe2","axe2", "JD",         7, 0.25,  3,   79, 14.0, 30.0, 50,  6,  PIRATE, 1,     1,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Boarding Axe//BB
  n = InitBlade(n,"topor1",  "topor1", "24",        2, 0.05,  9, 1323, 26.0, 40.0, 60, 10,  PIRATE, 1,     1,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Engraved Felling Axe //BB
  n = InitBlade(n,"topor2",  "topor2", "24",        3, 0.01, 15, 2507, 28.0, 45.0, 70, 13,  PIRATE, 1,     1,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Single Half-Moon Battle Axe //BB
  n = InitBlade(n,"battleax","battleax_back","BOP2",13,0.01, 15, 2507, 28.0, 45.0, 70, 13,  PIRATE, 1,     1,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Master Battle Axe 
  n = InitBlade(n,"bladelead","bladelead","JD",    16, 0.25,  1,   14,  4.0, 10.0,  0,  0,  PIRATE, 1,     1,    PERIOD_GOLDEN_AGE_OF_PIRACY, PERIOD_NAPOLEONIC); // Bronze Knuckles // SLiB special weapons added by KevAtl 09-03-2007
  n = InitBlade(n,"bladeclub","bladeclub","JD",    13, 0.20,  1,   19,  5.0, 20.0, 40,  5,  PIRATE, 1,     1,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Banger Club // SLiB special weapons added by KevAtl 09-03-2007
  n = InitBlade(n,"tomahawk", "tomahawk", "BOP",    4, 0.00,  9, 1323, 26.0, 40.0, 60, 10,  PIRATE, 1,     1,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Tomahawk special for Oranjestad //JRH
  n = InitBlade(n,"halberd",  "halberd",   "22",   13, 0.00,  9, 2507, 30.0, 40.0, 80, 10,  PIRATE, 1,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_THE_SPANISH_MAIN); // Halberd for Conquistadors //JRH
  n = InitBlade(n,"machete",  "machete", "JRH25",  13, 0.00,  1,   20, 10.0, 20.0, 30, 5,   PIRATE, 1,     1,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Machete //JRH
  //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  // BLADES:                                               picIndex          Price          Piercing   Nation
  //        ItemIndex  bladeID   modelID                      |  rare           | minDamage     |Blocking|          DisableWeaponsMod
  //            |         |          |             picTexture |    |   MinLevel |    | maxDamage|   |    |      Disarm    |   Available in period         Last period of availability
  //------------|---------|----------|-------------------|----|----|------|-----|----|-----|----|---|----|---------|------|------------|-----------------------------|---------------
  n = InitBlade(n, "blade1",  "blade1",                  6,  11,  0.90,   1,   63, 15.0, 18.0, 14, 13,  "",        0,     0,    PERIOD_COLONIAL_POWERS,      PERIOD_NAPOLEONIC); // Sabre//BB
  n = InitBlade(n, "blade2",  "blade2",                  6,  10,  0.90,   1,   67, 12.0, 17.0, 20, 10,  "",        0,     0,    PERIOD_THE_SPANISH_MAIN,     PERIOD_NAPOLEONIC); // Rapier//BB
  n = InitBlade(n, "blade3",  "blade3",                  6,   8,  0.90,   1,   56, 15.0, 17.0, 15, 10,  FRANCE,    1,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Badelaire//BB
  n = InitBlade(n, "blade4",  "blade4",                  6,   7,  0.90,   1,   60, 15.0, 18.0, 15, 11,  "",        1,     0,    PERIOD_GOLDEN_AGE_OF_PIRACY, PERIOD_NAPOLEONIC); // Cutlass//BB (BASE SWORD WEAPON)
  n = InitBlade(n, "blade5",  "blade5",                  6,   9,  0.90,   1,   12,  6.0, 15.0, 30,  4,  "",        0,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Dagger //BB
  n = InitBlade(n, "blade6",  "blade6",                  6,  12,  0.50,   4,  139, 14.0, 19.0, 19, 19,  PIRATE,    1,     0,    PERIOD_THE_SPANISH_MAIN,     PERIOD_COLONIAL_POWERS); // Schiavona (pirate?)//BB
  n = InitBlade(n, "blade7",  "blade7",                  6,  13,  0.50,   2,   58, 13.0, 18.0, 25,  5,  "",        0,     0,    PERIOD_THE_SPANISH_MAIN,     PERIOD_COLONIAL_POWERS); // Yataghan//BB
  n = InitBlade(n, "blade8",  "blade8",                  3,   1,  0.10,   7,  290, 18.0, 23.0, 20, 26,  "",        1,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_GOLDEN_AGE_OF_PIRACY); // Maltese Knight Sword//BB
  n = InitBlade(n, "blade9",  "blade9",                  3,   2,  0.10,  11,  494, 26.0, 41.0, 57, 35,  FRANCE,    5,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_GOLDEN_AGE_OF_PIRACY); // French Admiralty Rapier//BB
  n = InitBlade(n, "blade10", "blade10",                 3,   3,  0.40,   5,  161, 21.0, 26.0, 28, 13,  "",        1,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_GOLDEN_AGE_OF_PIRACY); // Piranha//BB
  n = InitBlade(n, "blade11", "blade11",                 3,   4,  0.30,   4,  264, 18.0, 22.0, 25, 19,  ENGLAND,   3,     0,    PERIOD_THE_SPANISH_MAIN,     PERIOD_NAPOLEONIC); // Highlander//BB
  n = InitBlade(n, "blade12", "blade12",                 3,   5,  0.20,   6,  470, 17.0, 21.0, 30, 28,  "",        1,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Arabic Scimitar//BB
  n = InitBlade(n, "blade13", "blade13",                 3,   6,  0.10,   5,  285, 16.0, 19.0, 35, 15,  "",        1,     0,    PERIOD_THE_SPANISH_MAIN,     PERIOD_NAPOLEONIC); // Dueling Rapier//BB
  n = InitBlade(n, "blade14", "blade14",                 3,   7,  0.05,   9, 2280, 22.0, 32.0, 33, 56,  SPAIN,     5,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Spanish Nobility Longsword//BB
  n = InitBlade(n, "blade15", "blade15",                 3,   8,  0.15,   5,  280, 19.0, 21.0, 21, 23,  PORTUGAL,  1,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_GOLDEN_AGE_OF_PIRACY); // Iberian Longsword//BB
  n = InitBlade(n, "blade16", "blade16",                 3,   9,  0.15,  10,  711, 21.0, 29.0, 35, 25,  SPAIN,     3,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_GOLDEN_AGE_OF_PIRACY); // Tizona//BB
  n = InitBlade(n, "blade17", "blade17",                 3,  10,  0.10,   9,  340, 15.0, 25.0, 35, 19,  "",        1,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_THE_SPANISH_MAIN); // Flamigera//BB
  n = InitBlade(n, "blade18", "blade18",                 3,  11,  0.00,  99,16350, 27.0, 45.0, 70, 80,  "",        4,     0,    PERIOD_THE_SPANISH_MAIN,     PERIOD_NAPOLEONIC); // Sabre of Nicholas Sharp//(Unique+quest item)BB
  n = InitBlade(n, "blade19", "blade19",                 3,  12,  0.15,   7,  364, 15.0, 26.0, 38, 20,  "",        1,     0,    PERIOD_THE_SPANISH_MAIN,     PERIOD_NAPOLEONIC); // German Rapier//BB
  n = InitBlade(n, "blade20", "blade20",                 3,  13,  0.15,   9,  410, 22.0, 27.0, 30, 30,  "",        1,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Asiatic Broadsword//BB
  n = InitBlade(n, "blade21", "blade21",                 3,  14,  0.45,   7,  334, 24.0, 29.0, 29, 19,  "",        2,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_THE_SPANISH_MAIN); // Falchion//BB
  n = InitBlade(n, "blade22", "blade22",                 3,  15,  0.10,   8,  578, 29.0, 40.0, 49, 34,  ENGLAND,   2,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Corsair's Pride//BB
  n = InitBlade(n, "blade23", "blade23",                 3,  16,  0.10,  11, 2548, 27.0, 37.0, 52, 42,  HOLLAND,   5,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Dutch Admiralty Sword//BB
  n = InitBlade(n, "blade24", "blade24",                 6,  14,  0.12,  12, 2562, 22.0, 37.0, 40, 40,  ENGLAND,   5,     0,    PERIOD_COLONIAL_POWERS,      PERIOD_NAPOLEONIC); // English Officer's Sabre//BB
  n = InitBlade(n, "blade25", "blade25",                 6,  15,  0.05,  17, 4910, 20.0, 35.0, 35, 45,  FRANCE,    6,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // French Nobility Sword//BB
  n = InitBlade(n, "blade26", "blade26",                 9,  16,  0.15,  16, 3106, 23.0, 35.0, 50, 35,  HOLLAND,   5,     0,    PERIOD_THE_SPANISH_MAIN,     PERIOD_NAPOLEONIC); // Solingen Rapier (Petros)//BB
  n = InitBlade(n, "blade27", "blade27",                 6,  16,  0.25,  12,  527, 20.0, 35.0, 35, 29,  "",        3,     0,    PERIOD_GOLDEN_AGE_OF_PIRACY, PERIOD_NAPOLEONIC); // Bosun's Choice//BB (common as name denotes)
  n = InitBlade(n, "blade28", "blade28",                 9,  15,  0.15,   9,  490, 20.0, 35.0, 30, 15,  "",        2,     0,    PERIOD_THE_SPANISH_MAIN,     PERIOD_NAPOLEONIC); // Shamshir (SLiB KevAtl)//BB
  n = InitBlade(n, "blade29", "blade29",                 9,  14,  0.12,  10, 2373, 20.0, 30.0, 36, 34,  PORTUGAL,  5,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Portuguese Officer's Sword//BB
  n = InitBlade(n, "blade30", "blade30",                 9,  13,  0.20,  11,  527, 20.0, 29.0, 40, 27,  HOLLAND,   3,     0,    PERIOD_COLONIAL_POWERS,      PERIOD_NAPOLEONIC); // Dueling Sabre (SLiB KevAtl)//BB
  n = InitBlade(n, "blade31", "blade31",                 9,  12,  0.15,  10,  560, 20.0, 40.0, 42, 10,  "",        3,     0,    PERIOD_THE_SPANISH_MAIN,     PERIOD_NAPOLEONIC); // Snake Head (SLiB KevAtl)//BB
  n = InitBlade(n, "blade32", "blade32",                 9,  11,  0.02,  20, 5890, 27.0, 51.0, 51, 27,  PORTUGAL,  5,     0,    PERIOD_THE_SPANISH_MAIN,     PERIOD_NAPOLEONIC); // Damascus Shamshir (SLiB KevAtl)//BB (rare+powerfull)
  n = InitBlade(n, "blade33", "blade33",                 9,  10,  0.02,  15, 3880, 25.0, 39.0, 45, 28,  SPAIN,     4,     0,    PERIOD_THE_SPANISH_MAIN,     PERIOD_NAPOLEONIC); // Moorish Sabre (SLiB KevAtl)//BB  (rare)
  n = InitBlade(n, "blade34", "blade34",                 9,   9,  0.02,  18, 5240, 33.0, 44.0, 50, 40,  PIRATE,    6,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Dragon's Head (SLiB KevAtl)//BB (rare+powerfull)
  n = InitBlade(n, "blade35", "blade35",                23,   1,  0.01,  19, 5400, 22.0, 49.0, 35, 40,  "",        4,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Knights Templer Sword//BB (rare+powerfull)
  n = InitBlade(n, "blade36", "blade36",                23,   2,  0.25,   4,   96, 12.0, 20.0, 30, 12,  "",        1,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Hunting Sword//BB
  n = InitBlade(n, "blade37", "blade37",                23,   3,  0.01,   9, 1894,  9.0, 19.0, 31, 10,  "",        1,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Gold and Jewel Encrusted Dagger//BB (rare+expensive+ceremonial)
  n = InitBlade(n, "blade38", "blade38",                23,   4,  0.10,  13,  564, 13.0, 25.0, 39, 25,  "",        2,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Kilij//BB
  n = InitBlade(n, "blade39", "blade39",                23,   5,  0.10,  12,  932, 12.0, 19.0, 20, 22,  ENGLAND,   3,     0,    PERIOD_GOLDEN_AGE_OF_PIRACY, PERIOD_NAPOLEONIC); // Gold Handled Naval Dirk//BB (rare+expensive+ceremonial)
  n = InitBlade(n, "blade40", "blade40",                23,   6,  0.01,  24, 8209, 25.0, 39.0, 50, 40,  "",        4,     0,    PERIOD_GOLDEN_AGE_OF_PIRACY, PERIOD_NAPOLEONIC); // Polish Hussar's Szabla//BB (rare+powerfull)
  n = InitBlade(n, "blade41", "blade41",                23,   7,  0.01,  28, 9200, 29.0, 43.0, 55, 35,  "",        6,     0,    PERIOD_COLONIAL_POWERS,      PERIOD_NAPOLEONIC); // Russian Cossack's Shashka//BB (rare+powerfull)
  n = InitBlade(n, "blade43", "blade43",                23,  10,  0.08,  19, 5607, 24.0, 38.0, 45, 40,  "",        5,     0,    PERIOD_REVOLUTIONS,          PERIOD_NAPOLEONIC); // US Cavalry Sabre//BB (rare, slight upgrade on 'english officer sabre')
  n = InitBlade(n, "blade44", "blade44",                23,   9,  0.15,  14,  681, 21.0, 32.0, 48, 30,  SPAIN,     3,     0,    PERIOD_THE_SPANISH_MAIN,     PERIOD_NAPOLEONIC); // Spanish Cup-Hilt Rapier//BB
  n = InitBlade(n, "blade45", "blade45",                23,  11,  0.05,   9,  480, 14.0, 25.0, 26, 20,  PORTUGAL,  2,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Crab Claw BroadSword//BB (rare+'fantasy' blade)
  n = InitBlade(n, "blade46", "blade46",                23,  12,  0.15,   3,  132, 12.0, 20.0, 19, 21,  "",        1,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Shortsword//BB renamed 'shortsword' model is very short!
  n = InitBlade(n, "blade47", "blade47",                23,  13,  0.15,   9,  350, 14.0, 25.0, 26, 21,  SPAIN,     2,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Light Tizona//BB (pre-cursor to the Tizona)
  n = InitBlade(n, "blade48", "blade48",                23,  14,  0.50,   3,   50,  8.0, 12.0, 15, 18,  "",        2,     0,    PERIOD_GOLDEN_AGE_OF_PIRACY, PERIOD_NAPOLEONIC); // Wooden Handled Naval Dirk//BB(defensive)
  n = InitBlade(n, "blade49", "blade49",                23,  15,  0.35,   7,   81, 11.0, 19.0, 17, 20,  "",        3,     0,    PERIOD_GOLDEN_AGE_OF_PIRACY, PERIOD_NAPOLEONIC); // Bronze Handled Naval Dirk//BB(defensive)
  n = InitBlade(n, "blade50", "blade50",                23,  16,  0.10,  14,  667, 18.0, 39.0, 49, 28,  PIRATE,    2,     0,    PERIOD_GOLDEN_AGE_OF_PIRACY, PERIOD_NAPOLEONIC); // Venetian Navy Cutlass//BB
  n = InitBlade(n, "blade51", "blade51",                24,   1,  0.05,  16, 4540, 20.0, 32.0, 33, 40,  FRANCE,    4,     0,    PERIOD_GOLDEN_AGE_OF_PIRACY, PERIOD_NAPOLEONIC); // French Court Sword//BB (pre-cursor to French Nobility sword)
  n = InitBlade(n, "bladeC2", "bladeC2",                21,  14,  0.20,  12,  822, 21.0, 27.0, 40, 30,  "",        3,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Back-bladed Sidesword (CoAS Metazot)//BB
  n = InitBlade(n, "bladeC6", "bladeC6",                21,  15,  0.50,   6,  250, 15.0, 19.0, 33, 19,  "",        1,     0,    PERIOD_GOLDEN_AGE_OF_PIRACY, PERIOD_NAPOLEONIC); // Smallsword (CoAS Metazot)//BB
  n = InitBlade(n, "bladeC10","bladeC10",               21,  11,  0.50,   5,  209, 15.0, 25.0, 27, 18,  "",        2,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_THE_SPANISH_MAIN); // Falchion (CoAS Metazot)//BB
  n = InitBlade(n, "bladeC11","bladeC11",               21,  13,  0.20,   8,  449, 17.0, 22.0, 30, 32,  "",        5,     0,    PERIOD_THE_SPANISH_MAIN,     PERIOD_NAPOLEONIC); // Milanese longsword(CoAS Metazot)//BB model is very long(so now a longsword)
  n = InitBlade(n, "bladeC12","bladeC12",               21,  12,  0.20,  10,  483, 14.0, 35.0, 37, 19,  "",        3,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Katzbalger (CoAS Metazot)//BB
  n = InitBlade(n, "bladeC17","bladeC17",               25,   2,  0.00,  10, 3420, 24.0, 62.0, 39, 45,  "",        3,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_COLONIAL_POWERS); // Flamberge Rapier // GR - for "Ardent" storyline
  n = InitBlade(n, "bladeC18","bladeC18",               21,  10,  0.20,  10,  590, 25.0, 39.0, 39, 20,  "",        3,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Shellcup Falchion (CoAS Metazot)//BB
  n = InitBlade(n, "bladeC23","bladeC23",                9,   8,  0.00,  99, 5532, 36.0, 50.0, 48, 37,  SPAIN,     4,     0,    PERIOD_THE_SPANISH_MAIN,     PERIOD_NAPOLEONIC); // Toledo rapier (CoAS GoF) // GR - for "Ardent" storyline
  n = InitBlade(n, "bladeC26","bladeC26",               21,  16,  0.15,  11,  516, 19.0, 31.0, 40, 25,  "",        2,     0,    PERIOD_THE_SPANISH_MAIN,     PERIOD_NAPOLEONIC); // Pappenheimer Rapier (CoAS Metazot)//BB
  n = InitBlade(n, "bladeC30","bladeC30",               21,   8,  0.25,  13, 1651, 19.0, 29.0, 46, 29,  "",        4,     0,    PERIOD_THE_SPANISH_MAIN,     PERIOD_NAPOLEONIC); // Swept Hilt Rapier  (CoAS Metazot)//BB
  n = InitBlade(n, "bladeC33","bladeC33",               21,   9,  0.20,   9,  588, 14.0, 26.0, 30, 45,  HOLLAND,   3,     0,    PERIOD_GOLDEN_AGE_OF_PIRACY, PERIOD_NAPOLEONIC); // Germanic Baskethilt Sword (CoAS Metazot)//BB
  n = InitBlade(n, "bladeC35","bladeC35",               21,  14,  0.03,  19, 5200, 20.0, 40.0, 40, 45,  "",        3,     0,    PERIOD_GOLDEN_AGE_OF_PIRACY, PERIOD_NAPOLEONIC); // Hibernian (Irish sword) //JRMM
  n = InitBlade(n, "bladeC36","bladeC36",                9,   5,  0.00,  99, 8000, 15.0, 30.0, 30, 40,  PIRATE,    3,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Katana //JRH, fix in items_utilite.c
  n = InitBlade(n, "blade308","blade308",                9,   6,  0.00,  99, 5500, 27.0, 42.0, 45, 37,  "",        4,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Based on Anathros, Sword of the Earth from "Two Worlds" // GR
  n = InitBlade(n, "bladeCiri","CiriSword",              9,   7,  0.00,  99, 8000, 15.0, 30.0, 30, 40,  "",        3,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Ciri's sword from Witcher 3 // DeathDaisy 
  n = InitBlade(n, "witcher_steel","witcher_steel_back", 25,  1,  0.00,  99, 8000, 15.0, 30.0, 30, 40,  "",        3,     0,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Flambard used by Geralt // Grey Roger/The Nameless Pirate
  
  n = InitBlade(n, "bladeA2","bladeA2", 	     "JRH4",  5,  0.00,  99, 1000, 21.0, 39.0, 28, 13,  "",        1,     1,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // WoodesRogers quest
  n = InitBlade(n, "bladeA4","bladeA4", 	     "JRH4",  4,  0.00,  99, 1000, 21.0, 26.0, 28, 13,  "",        3,     1,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // WoodesRogers quest
  n = InitBlade(n, "bladeA5","bladeA5", 	     "JRH4",  2,  0.00,  99, 1000, 21.0, 26.0, 42, 13,  "",        1,     1,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // WoodesRogers quest  
  n = InitBlade(n, "bladeA17","bladeA17", 	     "JRH4",  1,  0.00,  99, 1000, 21.0, 26.0, 28, 20,  "",        1,     1,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // WoodesRogers quest

  n = InitBlade(n, "bladeA11","bladeA11", 	     "JRH4",  3,  0.00,  99,  200, 10.0, 12.0, 15, 10,  "",        0,     1,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // WoodesRogers quest

  n = InitBlade(n, "Barmansknife","Barmansknife",       22,   7,  0.90,   1,    5,  3.0,  9.0, 20,  3,  PIRATE,    0,     1,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Breadknife (SuperDurnius)//BB USE AS BASE VALUE FOR ECONOMY (CHEAPEST)
  n = InitBlade(n, "Guestsknife","Guestsknife",         22,   6,  0.90,   1,    9,  3.0, 11.0, 25,  4,  PIRATE,    0,     1,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Knife (SuperDurnius)//BB
  n = InitBlade(n, "MerchantsBlade","MerchantsBlade",   22,   9,  0.90,   1,   59, 10.0, 15.0, 13, 14,  "",        0,     1,    PERIOD_GOLDEN_AGE_OF_PIRACY, PERIOD_NAPOLEONIC); // Merchants Blade (SuperDurnius)//BB(defensive)
  n = InitBlade(n, "Merchantsdagger","Merchantsdagger", 22,   8,  0.90,   1,   14,  5.0, 12.0, 20,  7,  "",        0,     1,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Merchants Dagger (SuperDurnius)//BB(defensive)
  n = InitBlade(n, "Minersaxe","worker_Axe",            22,   2,  0.90,   1,   26, 10.0, 19.0, 30,  6,  PIRATE,    1,     1,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Woodmen's Axe (SuperDurnius)//BB
  n = InitBlade(n, "Minerscrow","worker_Crow",          22,   1,  0.80,   1,   15,  3.0, 13.0,  5, 10,  PIRATE,    1,     1,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Shovel (SuperDurnius)//BB
  n = InitBlade(n, "Minerspick","worker_Pick",          22,   4,  0.80,   1,   19,  8.0, 13.0, 15, 10,  PIRATE,    1,     1,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Pickaxe (SuperDurnius)//BB
  n = InitBlade(n, "Minersspade","worker_Spade",        22,   3,  0.80,   1,   17,  3.0, 13.0,  5, 15,  PIRATE,    2,     1,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Spade (SuperDurnius)//BB
  n = InitBlade(n, "Piratesdagger","piratesdagger",     22,   5,  0.80,   1,   48, 10.0, 15.0, 34,  9,  "",        0,     1,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC); // Stiletto (SuperDurnius)//BB
  n = InitBlade(n, "blademketB", "blademusketB",   "JRH28",   4,  0.00,  20, 4000, 20.0, 40.0, 40, 20,  "",        5,     1,    PERIOD_REVOLUTIONS,          PERIOD_NAPOLEONIC); // Musket with bayonet //JRH
  n = InitBlade(n, "blademketK", "blademusketK",   "JRH28",   3,  0.00,  20, 3305, 20.0, 30.0, 30, 20,  "",        5,     1,    PERIOD_GOLDEN_AGE_OF_PIRACY, PERIOD_COLONIAL_POWERS); // Musket with primitive bayonet //JRH
  n = InitBlade(n, "blade_mKnife", "blade_mKnife", "JRH28",   2,  0.20,   1,   60,  6.0, 15.0, 30,  4,  "",        0,     1,    PERIOD_GOLDEN_AGE_OF_PIRACY, PERIOD_COLONIAL_POWERS); // Knife to use as primitive bayonet //JRH

  //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  // GUNS: ItemIndex                               picIndex          Price                 Charges
  //         | gunID        modelID                   |  rare           | minDamage   Accuracy|Reload time                                     DisableWeaponsMod
  //         |   |             |            picTexture|   |  MinLevel   |     | maxDamage  |  |   | Nation           Sound              Ammo type    |       Available in period         Last period of availability
  //-------------|-------------|------------------|---|---|------|------|-----|-----|------|--|---|--|------------------|-------------------|--------|---------------|----------------------------|-----------------
  n = InitGun(n,"pistol1a", "pistol1a",          21,  3, 0.50,   1,    150, 15.0, 25.0,    5, 1,  8, "", "OBJECTS\DUEL\pistol_small.wav",  "pb",     0,    PERIOD_EARLY_EXPLORERS, 	PERIOD_THE_SPANISH_MAIN);  // GR: Older style short pistol, from AoP
  n = InitGun(n,"pistol1", "pistol1",             6,  1, 0.50,   1,    150, 15.0, 25.0,    5, 1,  8, "", "OBJECTS\DUEL\pistol_small.wav",  "pb",     0,    PERIOD_GOLDEN_AGE_OF_PIRACY,	PERIOD_NAPOLEONIC);  // Short Pistol//BB BASE FOR PISTOLS
  n = InitGun(n,"pistol2", "pistol2a",            6,  2, 0.50,   3,    208, 40.0, 55.0,   50, 1, 12, "", "OBJECTS\DUEL\pistol_medium.wav", "pb",     0,    PERIOD_EARLY_EXPLORERS, 	PERIOD_NAPOLEONIC);  // Long Pistol//BB small calibre(less dmg)+good accuracy
  n = InitGun(n,"pistol7a", "pistol7a",           9,  4, 0.20,   5,    357, 15.0, 25.0,    5, 3, 25, "", "OBJECTS\DUEL\pistol_small.wav",  "pb",     0,    PERIOD_EARLY_EXPLORERS, 	PERIOD_THE_SPANISH_MAIN);  // GR: Brace of older style small Pistols
  n = InitGun(n,"pistol7", "pistol7",             9,  1, 0.20,   5,    357, 15.0, 25.0,    5, 3, 25, "", "OBJECTS\DUEL\pistol_small.wav",  "pb",     0,    PERIOD_GOLDEN_AGE_OF_PIRACY,	PERIOD_NAPOLEONIC);  // Brace of Small Pistols (Alan Smithee)
  n = InitGun(n,"PiratesPistol","PiratesPistol", 22, 10, 0.20,   7,    554, 35.0, 70.0,   45, 1, 10, "", "OBJECTS\DUEL\pistol_medium.wav", "pb",     0,    PERIOD_THE_SPANISH_MAIN,     PERIOD_NAPOLEONIC);  // Pirates Pistol (SuperDurnius)
  n = InitGun(n,"pistol6", "pistol6",             6,  6, 0.05,   9,   1026, 30.0, 40.0,   55, 2, 24, "", "OBJECTS\DUEL\pistol_medium.wav", "pb",     0,    PERIOD_GOLDEN_AGE_OF_PIRACY, PERIOD_NAPOLEONIC);  // Double-Shot Pistol
  n = InitGun(n,"pistol3", "pistol3",             6,  3, 0.37,  11,   1402, 30.0, 60.0,   30, 1, 20, "", "OBJECTS\DUEL\pistol_grape.wav",  "pg",     0,    PERIOD_GOLDEN_AGE_OF_PIRACY, PERIOD_NAPOLEONIC);  // Grapeshot Pistol
  n = InitGun(n,"pistol8", "pistol8",             9,  3, 0.15,  20,   1500, 35.0, 70.0,   50, 3, 10, "", "OBJECTS\DUEL\pistol_medium.wav", "pb",     0,    PERIOD_THE_SPANISH_MAIN, 	PERIOD_NAPOLEONIC);  // old Brace of Mid-size Pistols (Alan Smithee) now brace of flintlock pistols (JRMM)
  n = InitGun(n,"pistol4", "pistol4a",            6,  4, 0.05,  15,   2286, 20.0, 30.0,   50, 4, 35, "", "OBJECTS\DUEL\pistol_small.wav",  "pb",     0,    PERIOD_COLONIAL_POWERS,	PERIOD_NAPOLEONIC);  // Quad-Barrel Pistol
  n = InitGun(n,"pistol5", "pistol5a",            6,  5, 0.10,  16,   2653, 50.0,150.0,   70, 1, 14, "", "OBJECTS\DUEL\pistol_big.wav",    "pb",     0,    PERIOD_GOLDEN_AGE_OF_PIRACY, PERIOD_NAPOLEONIC);  // Horse Pistol (was Scrapper Pistol)
  n = InitGun(n,"pistol6_2","pistol6_2",         21,  2, 0.00,  99,   1500, 45.0, 55.0,   60, 2, 24, "", "OBJECTS\DUEL\pistol_medium.wav", "pb",     0,    PERIOD_GOLDEN_AGE_OF_PIRACY, PERIOD_NAPOLEONIC);  // Special double-shot pistol (GR - to be found next door to San Juan residence)
  n = InitGun(n,"DuelPistol","DuelPistol",	 21,  1, 0.01,	16,   4000, 75.0,135.0,   80, 1, 12, "", "OBJECTS\DUEL\pistol_big.wav",    "pb",     0,    PERIOD_COLONIAL_POWERS,	PERIOD_NAPOLEONIC);  // Duelling Pistol (GR)
  n = InitGun(n,"pistolmtoon", "musketoon_back",  8,  9, 0.08,  17,   2968, 75.0,125.0,   60, 1, 24, "", "OBJECTS\DUEL\pistol_mtoon.wav",  "pg2",    1,    PERIOD_GOLDEN_AGE_OF_PIRACY, PERIOD_NAPOLEONIC);  // JRH: model was Musketoon
  n = InitGun(n,"pistol9", "pistol9a",            9,  2, 0.10,  30,   5000, 50.0,150.0,   70, 2, 28, "", "OBJECTS\DUEL\pistol_big.wav",    "pb",     0,    PERIOD_GOLDEN_AGE_OF_PIRACY, PERIOD_NAPOLEONIC);  // old Brace of Large Pistols (Alan Smithee) now brace of Horse Pistols (JRMM)
  n = InitGun(n,"pistolmket",  "musket_back",     8, 10, 0.05,  20,   3245,150.0,250.0,   60, 1, 30, "", "", 				   "mb",     1,    PERIOD_GOLDEN_AGE_OF_PIRACY, PERIOD_NAPOLEONIC);  // JRH: model was Musket, sound played in LAi_events
  n = InitGun(n,"pistol10", "pistol10",        "JD",  5, 0.02,  99,   6572, 60.0, 90.0,   60, 1,  1, "", "OBJECTS\DUEL\pistol_shotgun.wav","pg",     1,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC);  // Pump Shotgun SLiB  LDH fix sound error
  n = InitGun(n,"pistol25", "pistol5b",          24,  9, 0.02,  54,   9999, 50.0,150.0,   70, 4, 14, "", "OBJECTS\DUEL\pistol_big.wav",    "pb",     0,    PERIOD_GOLDEN_AGE_OF_PIRACY, PERIOD_NAPOLEONIC);  // Brace of four Horse Pistols (JRMM)
  n = InitGun(n,"pistol26", "pistol26",          24, 10, 0.02,  24,   9999, 30.0, 60.0,   30, 4, 35, "", "OBJECTS\DUEL\pistol_grape.wav",  "pg",     0,    PERIOD_NAPOLEONIC, 	        PERIOD_NAPOLEONIC);  // Four-barrel Grapeshot Pistol (JRH)
  n = InitGun(n,"pistol27", "pistol27",          21,  4, 0.10,   5,    450, 35.0, 60.0,   40, 1, 12, SPAIN, "OBJECTS\DUEL\pistol_medium.wav", "pb",  0,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC);  // Miquelet (GR + JRH)
  n = InitGun(n,"pistolbow", "bow",           "BOP",  1, 0.00,   1,     20, 30.0, 40.0,   80, 1, 1.5,"", "OBJECTS\DUEL\bow.wav",           "ar",     1,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC);  // Bow (BOP)
  n = InitGun(n,"LongRifle_C", "LongRifle_C_back", "BOP2",11,0.00,99,    1, 50.0,150.0,   20, 1, 30, "", "OBJECTS\DUEL\pistol_medium2.wav","pb2",    1,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC);  // JRH: Long Rifle for All Storylines
  n = InitGun(n,"LongRifle_CT","LongRifle_CT_back","BOP2",12,0.00,99,    1,150.0,250.0,   80, 1, 30, "", "OBJECTS\DUEL\pistol_medium2.wav","pb2",    1,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC);  // JRH: Long Rifle for All Storylines, with telescope
  n = InitGun(n,"telescope",    "",		   "BOP2", 9,0.00,99,    1,150.0,250.0,   80, 1, 30, "", "",                                 "",     1,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC);  // JRH: Telescope
  n = InitGun(n,"LongRifle_BT","LongRifle_BT_back","BOP2",10,0.00,99,12000,150.0,250.0,   80, 1,  1, "", "OBJECTS\DUEL\pistol_medium2.wav",  "",     1,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC);  // JRH: Custom quest musket for BOP, with telescope
  n = InitGun(n,"LongRifle_W", "LongRifle_W_back", "BOP2", 7,0.00,99,    0,150.0,250.0,   80, 1, 30, "", "OBJECTS\DUEL\pistol_medium2.wav", "pb2",   1,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC);  // JRH: Custom quest musket for WR
  n = InitGun(n,"LongRifle_WT","LongRifle_WT_back","BOP2", 8,0.00,99,    0,150.0,250.0,   80, 1, 30, "", "OBJECTS\DUEL\pistol_medium2.wav", "pb2",   1,    PERIOD_EARLY_EXPLORERS,      PERIOD_NAPOLEONIC);  // JRH: Custom quest musket for WR, with telescope
  n = InitGun(n,"LongRifle_H", "LongRifle_H_back", "BOP2",16,0.02,25, 4000,150.0,250.0,  120, 1, 35, "", "OBJECTS\DUEL\pistol_musket2.wav", "pb2",   1,    PERIOD_NAPOLEONIC,      	PERIOD_NAPOLEONIC);  // TY: Baker Rifle for Hornblower and Napoleonic
  n = InitGun(n,"pistolcollier","pistolcollier", 21,  5, 0.00,  99,   9999, 40.0,120.0,   50, 6, 12, "", "OBJECTS\DUEL\pistol_medium.wav", "pb",     0,    PERIOD_NAPOLEONIC,      	PERIOD_NAPOLEONIC);  // GR: Collier revolver
  
  n = InitGun(n,"pistol11", "pistol11",     "JRH28",  6, 0.15,   4,   750, 40.0, 60.0,   80, 1, 14, "", "OBJECTS\DUEL\pistol_medium.wav", "pb",      0,    PERIOD_EARLY_EXPLORERS,      PERIOD_THE_SPANISH_MAIN);	// JRH: wheellock
  n = InitGun(n,"pistol12", "pistol12",     "JRH28",  7, 0.05,   9,  1500, 40.0, 60.0,   80, 2, 28, "", "OBJECTS\DUEL\pistol_medium3.wav","pb",      0,    PERIOD_EARLY_EXPLORERS,      PERIOD_THE_SPANISH_MAIN);	// JRH: wheellock expensive pair
  n = InitGun(n,"pistol13", "pistol13_back","JRH28",  8, 0.10,  14,  2000, 75.0,125.0,   80, 1, 24, "", "OBJECTS\DUEL\pistol_medium.wav", "pb2",     1,    PERIOD_EARLY_EXPLORERS,      PERIOD_THE_SPANISH_MAIN);	// JRH: Short wheellock musket 
  n = InitGun(n,"Arguebuse", "Arguebuse_back",    "JRH28", 1, 0.15,17,2000,100.0,200.0,  40, 1, 24, "", "OBJECTS\DUEL\pistol_big2.wav",   "mb",      1,    PERIOD_EARLY_EXPLORERS,      PERIOD_THE_SPANISH_MAIN);	// JRH: Arguebuse
  n = InitGun(n,"pistolmketB",  "musketB_back",   "JRH28", 4, 0.05,20,4000,150.0,250.0,  60, 1, 30, "", "", 				  "mb",      1,    PERIOD_REVOLUTIONS,          PERIOD_NAPOLEONIC);  		// JRH: Musket with bayonet, sound played in LAi_events 
 //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


  if ( ENABLE_AMMOMOD )
  {
  // JRH ammo mod start -->
  //----------------------------------------------------------------------------------------------------------------------
  // AMMOMOD:                                                          rare       Price    skiptrade
  //          ItemIndex                                        picIndex  |          |      | skiprand
  //              |     itmID        groupID          picTexture   |     | MinLevel |      | | skipequip
  //--------------|-------|-------------|-------------------|------|-----|----|-----|------|-|-|--------------------------
  n = InitAmmoMod(n,"powderflask",  FLASK_ITEM_TYPE,      "JRH",   1,  0.10,  3,   150,    0,0,0);// Powder Flask
  n = InitAmmoMod(n,"ammopouch",    POUCH_ITEM_TYPE,      "JRH",   2,  0.10,  3,   120,    0,0,0);// Ammo Pouch
  n = InitAmmoMod(n,"gunpowder",    AMMUNITION_ITEM_TYPE, "JRH",   4,  0.95,  1,    10,    0,0,1);// Gun powder
  n = InitAmmoMod(n,"pistolbullets",AMMUNITION_ITEM_TYPE, "JRH",   5,  0.95,  1,     5,    0,0,1);// Pistol Bullets
  n = InitAmmoMod(n,"pistolgrapes", AMMUNITION_ITEM_TYPE, "JRH",   6,  0.60,  1,     8,    0,0,1);// Grape Shot
  n = InitAmmoMod(n,"musketbullets",AMMUNITION_ITEM_TYPE, "JRH",   7,  0.20,  3,    10,    0,0,1);// Musket Bullets
  n = InitAmmoMod(n,"arrows2",      AMMUNITION_ITEM_TYPE, "BOP2",  2,  0.00,  3,     1,    1,1,1);// JRH: Small poisoned arrows for the Blowgun
  n = InitAmmoMod(n,"rockets",      AMMUNITION_ITEM_TYPE, "BOP2",  5,  0.00,  3,     1,    1,1,1);// JRH: Rockets
  n = InitAmmoMod(n,"rocketbag",    POUCH_ITEM_TYPE,      "BOP2",  6,  0.00,  3,     1,    1,1,0);// JRH: Rocket Bag
  n = InitAmmoMod(n,"quiver",       POUCH_ITEM_TYPE,      "BOP",   3,  0.00,  3,     2,    1,1,0);// JRH: Quiver
  n = InitAmmoMod(n,"curare",       AMMUNITION_ITEM_TYPE, "JRH28",13,  0.00,  3,     2,    1,1,1);// JRH: for poisoned arrows
  n = InitAmmoMod(n,"tar",          AMMUNITION_ITEM_TYPE, "JRH28",14,  0.00,  3,     2,    1,1,1);// JRH: for flaming arrows
  if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) < 1 && sti(GetStorylineVar(FindCurrentStoryline(), "BUG_PUZZLES")) < 1)
  {
    n = InitAmmoMod(n,"powderbarrel", FLASK_ITEM_TYPE,      "JRH16", 2,  0.03, 10,  1500,    0,0,0);// Sulan: Powder Barrel
    n = InitAmmoMod(n,"ammobag",      POUCH_ITEM_TYPE,      "JRH16", 1,  0.03, 10,   500,    0,0,0);// Sulan: Ammo Bag
  }
  if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0 || sti(GetStorylineVar(FindCurrentStoryline(), "BUG_PUZZLES")) > 0)
  {
    n = InitAmmoMod(n,"ammobag1",AMMUNITION_ITEM_TYPE,    "JRH",   3,  0.00,  3,    75,    1,1,1);// Quest Ammo Bag not equipable
    n = InitAmmoMod(n,"ammobag2",     POUCH_ITEM_TYPE,	  "JRH",   3,  0.00,  3,    75,    1,1,0);// Quest Ammo Bag
    n = InitAmmoMod(n,"pistolbelt",   BELT_ITEM_TYPE,	  "JRH",  15,  0.00,  3,     0,    1,1,0);// Quest item
    n = InitAmmoMod(n,"pistolcannon1",AMMUNITION_ITEM_TYPE,"JRH37",11, 0.00,  3,     0,    1,1,1);// Quest Pistolcannon not equipable
    n = InitAmmoMod(n,"fake_pclub",AMMUNITION_ITEM_TYPE, "JRH4",  16,  0.00,  1,     1,    1,1,1);// Quest special disable equip
    n = InitAmmoMod(n,"fake_anchor",AMMUNITION_ITEM_TYPE,"JRH4",   8,  0.00,  1,     1,    1,1,1);// Quest special disable equip
    n = InitAmmoMod(n,"cartridges",AMMUNITION_ITEM_TYPE,"JRH19",   2,  0.00,  1,    20,    1,1,1);// for revolver
    n = InitAmmoMod(n,"nails",     AMMUNITION_ITEM_TYPE,"JRH24",   7,  0.00,  1,     5,    1,1,1);// instead of pistolgrapes	
    n = InitAmmoMod(n,"incense",   AMMUNITION_ITEM_TYPE,"JRH36",  11,  0.00,  1,     1,    1,1,1);// for pistolcenserD
    n = InitAmmoMod(n,"p_package",    OPEN_ITEM_TYPE,   "JRH27",   1,  0.00,  1,     1,    1,1,1);//
    n = InitAmmoMod(n,"p_case_C",     OPEN_ITEM_TYPE,   "JRH27",   2,  0.00,  1,     1,    1,1,1);// closed
    n = InitAmmoMod(n,"p_case_3",     OPEN_ITEM_TYPE,   "JRH27",   9,  0.00,  1,     1,    1,1,1);// open filled
    n = InitAmmoMod(n,"p_case_2A",    OPEN_ITEM_TYPE,   "JRH27",  10,  0.00,  1,     1,    1,1,1);//
    n = InitAmmoMod(n,"p_case_2B",    OPEN_ITEM_TYPE,   "JRH27",  11,  0.00,  1,     1,    1,1,1);//
    n = InitAmmoMod(n,"p_case_2C",    OPEN_ITEM_TYPE,   "JRH27",  12,  0.00,  1,     1,    1,1,1);//
    n = InitAmmoMod(n,"p_case_1A",    OPEN_ITEM_TYPE,   "JRH27",  13,  0.00,  1,     1,    1,1,1);//
    n = InitAmmoMod(n,"p_case_1B",    OPEN_ITEM_TYPE,   "JRH27",  14,  0.00,  1,     1,    1,1,1);//
    n = InitAmmoMod(n,"p_case_1C",    OPEN_ITEM_TYPE,   "JRH27",  15,  0.00,  1,     1,    1,1,1);//
    n = InitAmmoMod(n,"p_case_0",     BELT_ITEM_TYPE,   "JRH27",  16,  0.00,  1,     1,    1,1,1);//    
    n = InitAmmoMod(n,"cart_box_C",   OPEN_ITEM_TYPE,   "JRH27",   5,  0.00,  1,     1,    1,1,1);// 
    n = InitAmmoMod(n,"cart_box_O",   BELT_ITEM_TYPE,   "JRH27",   6,  0.00,  1,     1,    1,1,1);// 
    n = InitAmmoMod(n,"caps_box_C",   OPEN_ITEM_TYPE,   "JRH27",   7,  0.00,  1,     1,    1,1,1);// 
    n = InitAmmoMod(n,"caps_box_O",   BELT_ITEM_TYPE,   "JRH27",   8,  0.00,  1,     1,    1,1,1);// 

    n = InitAmmoMod(n,"flagchest_closed",OPEN_ITEM_TYPE,"JRH32",  13,  0.00,  1,     1,    1,1,1);// 
    n = InitAmmoMod(n,"flagchest_openA", OPEN_ITEM_TYPE,"JRH32",  14,  0.00,  1,     1,    1,1,1);//
    n = InitAmmoMod(n,"flagchest_openB", BELT_ITEM_TYPE,"JRH32",  14,  0.00,  1,     1,    1,1,1);//
    n = InitAmmoMod(n,"flagchest_empty", BELT_ITEM_TYPE,"JRH32",  15,  0.00,  1,     1,    1,1,1);// 

    n = InitAmmoMod(n,"toolbox_filled", OPEN_ITEM_TYPE, "JRH36",  16,  0.00,  1,     1,    1,1,1);// 
    n = InitAmmoMod(n,"toolbox_empty",   BELT_ITEM_TYPE, "JRH36",  16,  0.00,  1,     1,    1,1,1);// 
  }
  }
  //----------------------------------------------------------------------------------------------------------------------
  // JRH ammo mod end <--

  //  scheffnow - tailorsmod -->
  //-----------------------------------------------------------------------------------------------
  // ARMOR:  ItemIndex        picIndex      bladefrac  minlevel
  //        |  armorID        | coverage  |  gunstop |
  //        |   |      picTexture   |   | bladestop | gunfrac
  //------------|---|---------------|---|---|---|---|---|---|--|-----------------------------------
  n = InitArmor(n, "Soldier_Hol",   7, 14, 50, 40, 50,  5, 85, 2); // Frac values are inverse.
  n = InitArmor(n, "Soldier_Hol2",  7, 14, 50, 40, 50,  7, 85, 3); // Lower is better!
  n = InitArmor(n, "Soldier_Hol3",  7, 14, 50, 40, 50,  7, 82, 5);
  n = InitArmor(n, "Soldier_Hol4",  7, 14, 50, 50, 50, 10, 80, 7);
  n = InitArmor(n, "Soldier_Hol5",  7, 14, 50, 50, 50, 10, 77, 9);
  n = InitArmor(n, "Soldier_Hol6",  7, 14, 50, 50, 50, 12, 77, 11);
  n = InitArmor(n, "Soldier_Por",   7, 14, 60, 35, 50,  7, 80, 2);
  n = InitArmor(n, "Soldier_Por2",  7, 14, 60, 35, 50, 10, 80, 4);
  n = InitArmor(n, "Soldier_Por3",  7, 14, 60, 35, 50, 10, 77, 6);
  n = InitArmor(n, "Soldier_Por4",  7, 14, 60, 45, 50, 12, 75, 8);
  n = InitArmor(n, "Soldier_Por5",  7, 14, 60, 45, 50, 12, 75, 10);
  n = InitArmor(n, "Soldier_Por6",  7, 14, 60, 45, 50, 15, 75, 12);
  n = InitArmor(n, "Soldier_Spa",   7, 14, 55, 40, 50,  7, 80, 2);
  n = InitArmor(n, "Soldier_Spa2",  7, 14, 55, 40, 50, 10, 80, 3);
  n = InitArmor(n, "Soldier_Spa3",  7, 14, 55, 40, 50, 10, 77, 5);
  n = InitArmor(n, "Soldier_Spa4",  7, 14, 55, 50, 50, 12, 75, 7);
  n = InitArmor(n, "Soldier_Spa5",  7, 14, 55, 50, 50, 12, 75, 9);
  n = InitArmor(n, "Soldier_Spa6",  7, 14, 55, 50, 50, 15, 75, 11);
  n = InitArmor(n, "Offic_hol",     7, 14, 70, 75, 40, 15, 70, 10);
  n = InitArmor(n, "Offic_por",     7, 14, 70, 70, 40, 17, 70, 10);
  n = InitArmor(n, "Offic_spa",     7, 14, 70, 65, 40, 20, 70, 10);
  n = InitArmor(n, "Lucas",         7, 14, 60, 60, 30, 25, 70, 12);
  //-----------------------------------------------------------------------------------------------

  //-----------------------------------------------------------------------------------------------
  // STANDARD ARMOR:                      picIndex         price      bladefrac      armor
  //                armorID                  | rare          | coverage  |  gunstop   |      quality
  //     ItemIndex     |          picTexture |   |  minlevel |   | bladestop | gunfrac|  cmodel|
  //---------------|---|---------------|-----|---|-----|-----|---|---|---|---|---|----|----|---|-----
  n = InitStdArmor(n, "gorget",	      24,   14, 0.20,  1,  1200,  5, 5,  90,  2, 95,  5,  "" , 1);
  n = InitStdArmor(n, "jerkin",	      24,   15, 0.20,  1,  2500, 40, 10, 90,  5, 90, 10,  "" , 2);
  n = InitStdArmor(n, "cured", 	      24,   16, 0.15,  1,  3250, 40, 15, 90,  7, 85, 10,  "" , 2);
  n = InitStdArmor(n, "cheaparmor",    7,   14, 0.15,  1,  4237, 40, 20, 90, 10, 80, 20,  "1", 3); // Frac values are inverse.  //BB increased price+rare(you have to buy it!)
  n = InitStdArmor(n, "commonarmor",   7,    6, 0.08,  8,  8380, 50, 40, 50, 15, 75, 40,  "2", 6); // Lower is better!      //BB slight increase in performance to counter higher weapon damage
  n = InitStdArmor(n, "goldarmor",     7,    5, 0.01, 15, 16409, 60, 60, 30, 25, 70, 60,  "3", 9);                //BB min.level adjusted to spread out range of availabilty
  //-----------------------------------------------------------------------------------------------
  //  scheffnow - tailorsmod <--


  //-----------------------------------------------------------------------------------------------------------------------------------------------------------------
  // SPYGLASSES: ItemIndex                                        Price  texture                activate    nation     cannons   crew     morale    skiptrade
  //               |    itmID   model         icIndex  rare          |      |                      | update  | shipname  | hull    | speed     quality| skiprand
  //               |      |       |   picTexture  |     |   MinLevel |      |                zoom  |    |    | | shiptype| | sail  | | charge    |    | | skipequip
  //---------------|------|-------|-----------|---|-----|----|-------|------|------------------|---|----|----|-|-|-------|-|-|-----|-|-|--|------|----|-|-|----------
  n = InitSpyglass(n,"spyglass1","",          8, 14,  0.30,  1,    600, "eye_BadTub.tga",    3.0, 500, 150,  1,1,1,      0,0,0,    0,0,0, 0,     1,   0,0,0);// Cheap Spyglass  //BB increased price
  n = InitSpyglass(n,"spyglass2","",          8, 15,  0.10,  1,   1200, "eye_CommonTub.tga", 6.0, 500, 150,  1,1,1,      0,1,1,    0,1,0, 0,     3,   0,0,0);// Average Spyglass//BB increased price
  n = InitSpyglass(n,"spyglass3","",          8, 16,  0.05,  8,   4500, "eye_GoodTub.tga",   8.0, 500, 150,  1,1,1,      1,1,1,    1,1,0, 1,     7,   0,0,0);// Great Spyglass  //BB increased price
  n = InitSpyglass(n,"spyglass4","spyglass4", 1, 14,  0.01, 15,   9800, "eye_BestTub.tga",  10.0, 500, 150,  1,1,1,      1,1,1,    1,1,1, 1,     9,   0,0,0);// Master Spyglass //BB increased price
  //-----------------------------------------------------------------------------------------------------------------------------------------------------------------


  //-----------------------------------------------------------------------------------------------------------------------------------------------------------------
  // POTIONS: ItemIndex                         picIndex               numrandmod     antidote        skipsell
  //             |     itmID  modelID               |  rare        Price  |   pic    |   health       | skiprand
  //             |      |        |      picTexture  |   |   MinLevel |    |    | tex |   |    quality | | skipequip
  //-------------|------|--------|--------------|---|---|------|-----|----|----|--|--|---|------|-----|-|-|----------------------------------------------------------
  n = InitPotion(n,"medical1",  "",             8,  7,  0.80,  1,    80, 2.5,  6, 1, 0,  30.0,  0,    0,0,0);// Bandage by Duncan
  n = InitPotion(n,"medical2",  "",             8,  6,  0.30,  5,   150, 1.5,  2, 1, 0,  60.0,  4,    0,0,0);// Cauterization Kit by Duncan
  n = InitPotion(n,"potion1",   "potion",       1,  7,  0.15, 10,   250, 2.5,  1, 1, 0, 100.0,  0,    1,0,0);// Small potion
  n = InitPotion(n,"potion2",   "potionbig",    1,  1,  0.05, 15,   350, 1.5,  0, 1, 0, 150.0,  4,    1,0,0);// Large potion
  n = InitPotion(n,"potion3",   "Antidote",     1,  5,  0.40,  1,   145, 1.0,  3, 1, 1,   0.0,  0,    0,0,0);// Antidote
  n = InitPotion(n,"potion4",   "balsam",       1,  4,  0.15,  7,   280, 1.0,  5, 1, 1,  60.0,  5,    1,0,0);// Mixture
  n = InitPotion(n,"potionrum", "Adrenaline",   1,  3,  0.10,  6,   120, 0.4,  4, 1, 0,  50.0,  4,    1,0,0);// Rum  by VERRUCKT
  n = InitPotion(n,"potionwine","elixir",       1,  6,  0.10, 12,   300, 0.2,  7, 1, 0, 180.0,  7,    1,0,0);// Wine by VERRUCKT
  if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0 || sti(GetStorylineVar(FindCurrentStoryline(), "BUG_PUZZLES")) > 0)
  {
    n = InitPotion(n,"potionwine2", "",   "JRH12", 13,	0.10,  3,     0, 0.2,  5, 2, 0, 180.0,  7,    1,1,0);// JRH Red Wine from church cellar
    n = InitPotion(n,"tobacco",     "",   "JRH11",  2,	0.80,  0,   150, 2.5,  0, 2, 0,  15.0,  0,    1,1,1);// JRH quest potion
    n = InitPotion(n,"sewing_kit",  "",   "JRH11",  1,	0.30,  0,   425, 1.5,  1, 2, 0,  45.0,  4,    1,1,1);// JRH quest potion
    n = InitPotion(n,"cognac", 	    "",   "JRH12", 12,	0.20,  3,   500, 0.4,  4, 2, 0,  90.0,  4,    1,1,1);// JRH drinkable cognac
    n = InitPotion(n,"myrrh",       "",   "JRH36", 12,  0.15, 10,     0, 2.5,  3, 2, 0, 100.0,  0,    1,1,1);// JRH myrrh for special use
  }
  if(sti(GetStorylineVar(FindCurrentStoryline(), "BART_PUZZLES")) > 0 || sti(GetStorylineVar(FindCurrentStoryline(), "BUG_PUZZLES")) > 0
  || sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0)
  {
     n = InitPotion(n,"calabash","calabash","BOP",  6,  0.40,  1,   145, 1.0,  6, 2, 1,   0.0,  0,    1,1,1);// Antidote
     n = InitPotion(n,"herbs",   "herbs",   "BOP",  7,  0.15, 10,   250, 2.5,  7, 2, 0, 100.0,  0,    1,1,1);// Potion
  }
  //-----------------------------------------------------------------------------------------------------------------------------------------------------------------

  //-------------------------------------------------------------------O----------------SKILL ITEM SETTINGS----------------O-----------------------------------------
  // GENERAL:  ItemIndex                 picIndex          Price   numneeded    leader     accuracy    repair       sneak skiptrade   skipsell
  //           |    itmID  modelID          |   rare         |         | stack    | fencing   | cannons   | defence   |   |  skiprand |
  //           |      |      |   picTexture |    |  MinLevel | indian  |  | hidden|   |  sailing  |  grapple  |  commerce |   |  skipequip
  //-----------|------|------|----------|---|----|-----|-----|----|----|--|--|----|---|---|---|---|---|---|---|---|---|---|---|---|---|-------------------------------
  // SPECIAL ITEMS:
  //-----------|------|------|----------|---|----|-----|-----|----|----|--|--|----|---|---|---|---|---|---|---|---|---|---|---|---|---|-------------------------------
  n = InitItem(n,"cursedcoin", "",      4, 15, 0.10,   5,   1500, 0,   1, 1, 1,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1);

  n = InitItem(n,"luckydimeA", "","JRH38",  9, 0.10,   5,   1500, 0,   1, 1, 1,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1);
  n = InitItem(n,"luckydimeB", "","JRH38", 10, 0.10,   5,   1500, 0,   1, 1, 1,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1);


  n = InitItem(n,"lockpick",    "",     8,  8, 0.10,   5,    110, 0,   0, 0, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0, +1,  0,  0,  0,  1); // Lockpick
  n = InitItem(n,"ayahuasca", "", "Levis",  1, 0.00,   1,      1, 0,   0, 0, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  0,  1); // Ayahuasca
  n = InitItem(n,"opium", "", 	  "Levis",  2, 0.00,   1,      0, 0,   0, 0, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  0,  1); // Opium
  n = InitItem(n,"vegetal", "",   "Levis",  3, 0.00,   1,    100, 0,   0, 0, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  0,  1); // Vegetal
  //--------------------------------------------------------------------------------------------------------------------------------------------------
  n = InitItem(n,"compass1", "",       11,  1,  0.20,  1,    508, 0,   1, 0, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0);// Cheap Compass
  n = InitItem(n,"compass2", "",       11,  2,  0.10,  4,   1916, 0,   1, 0, 0,   0,  0, +1,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0);// Normal Compass		// + skill item
  n = InitItem(n,"compass3", "",       11,  3,  0.05, 10,   5800, 0,   1, 0, 0,   0,  0, +1,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0);// Enhanced Compass	// + skill item // KK
  n = InitItem(n,"clock1", "",         11, 12,  0.15,  1,    250, 0,   1, 0, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0);// Simple clock
  n = InitItem(n,"clock2", "",         11, 13,  0.05, 10,   6293, 0,   1, 0, 0,   0,  0, +1,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0);// Chronometer			// ++ skill item
  n = InitItem(n,"sextant", "",        11,  9,  0.05,  6,   4107, 0,   1, 0, 0,   0,  0, +1,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0);// Sextant				// ++ skill item
  n = InitItem(n,"scales", "",         11,  8,  0.05,  3,   1340, 0,   1, 0, 0,   0,  0,  0,  0,  0,  0,  0,  0, +1,  0,  0,  1,  0,  0);// Scales				// + skill item
  n = InitItem(n,"doctortoolkit", "",  11,  4,  0.05,  8,   5031, 0,   1, 0, 0,   0,  0,  0,  0,  0,  0,  0, +1,  0,  0,  0,  1,  0,  0);// Doctor's Toolkit	// ++ skill item
  n = InitItem(n,"microscope", "",     11,  5,  0.05,  5,   3410, 0,   1, 0, 0,  +1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0);// Microscope			// + skill item
  n = InitItem(n,"carpentertools", "", 24,  5,  0.05,  4,   2410, 0,   1, 0, 0,   0,  0,  0,  0,  0,  0, +1,  0,  0,  0,  0,  1,  0,  0);// Carpenter's Toolkit	// + skill item JRMM
  n = InitItem(n,"silkgrapple", "",    24,  6,  0.05,  6,   6410, 0,   1, 0, 0,   0,  0,  0,  0,  0, +1,  0,  0,  0,  0,  0,  1,  0,  0);// Silk Grapple lines	// + skill item JRMM
  n = InitItem(n,"gunnerdrum", "",     24,  7,  0.05,  4,   1410, 0,   1, 0, 0,   0,  0,  0,  0, +1,  0,  0,  0,  0,  0,  0,  1,  0,  0);// Gunner's Drum	    // + skill item JRMM
  n = InitItem(n,"gunnerglass", "",    24,  8,  0.05,  4,   3410, 0,   1, 0, 0,   0,  0,  0, +1,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0);// Gunner's Glass	    // + skill item JRMM
  n = InitItem(n,"masterkeys", "",     24, 11,  0.05,  4,   2410, 0,   1, 0, 0,  +1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0);// Master Keys	     	// + skill item JRMM
  n = InitItem(n,"luckcharm", "",      24, 12,  0.02,  1,   9000, 0,   1, 0, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0, +1,  0,  0,  0,  1);// Good Luck charm	    // + skill item JRMM
  n = InitItem(n,"bladekit", "",       24, 13,  0.10,  3,   1410, 0,   1, 0, 0,   0, +1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0);// Blade Kit		    // ++ skill item JRMM
  //------------------------------------------------------------------------------------------------------------------------------------------------------------------
  // BOOKS: added by Short Jack Gold
  //-----------------------------------------------------------------------------------------------------------------------------------------------------------------
  n = InitItem(n,"book1",  "",         13,  3,  0.10,  2,   2212, 0,   1, 0, 0,   0,  0,  0,  0,  0, +2,  0,  0,  0,  0,  0,  1,  0,  0);// Black Bart's Bumper Book of Boarding
  n = InitItem(n,"book2",  "",         13,  4,  0.05,  3,   2310, 0,   1, 0, 0,   0,  0,  0, +1,  0,  0,  0,  0, +1,  0,  0,  1,  0,  0);// Boelen Algebra
  n = InitItem(n,"book9",  "",         13,  1,  0.25,  1,    100, 0,   1, 0, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  0);// Cooking With Albatross - PB: Clue about "Dead Albatross" effect
  n = InitItem(n,"book10", "",         13, 13,  0.05,  2,   1240, 0,   1, 0, 1,   0,  0,  0,  0,  0,  0,  0, +1,  0,  0,  0,  1,  0,  0);// Definitive Defence
  n = InitItem(n,"book3",  "",         11, 15,  0.05,  3,   2360, 0,   1, 0, 0,   0,  0,  0,  0,  0,  0,  0,  0, +1, +1,  0,  1,  0,  0);// Drow's Double Your Dubloons
  n = InitItem(n,"book11", "",         13, 11,  0.05,  8,   1830, 0,   1, 0, 1,   0,  0,  0,  0, +1,  0,  0,  0,  0,  0,  0,  1,  0,  0);// Fighting Forts
  n = InitItem(n,"book12", "",         13,  5,  0.10,  2,   1220, 0,   1, 0, 1,   0,  0,  0, +1,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0);// Great Gun Sights
  n = InitItem(n,"book13", "",         13,  6,  0.10,  1,   1108, 0,   1, 0, 1,  +1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0);// Handy Sea Phrases
  n = InitItem(n,"book4",  "",         13, 14,  0.05,  3,   2310, 0,   1, 0, 0,   0,  0, +2,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0);// Hook's Book
  n = InitItem(n,"book14", "",         13,  8,  0.10,  1,   1105, 0,   1, 0, 1,   0,  0,  0,  0,  0,  0,  0, +1,  0,  0,  0,  1,  0,  0);// How to Repel Boarders
  n = InitItem(n,"book5",  "",         13, 15,  0.10,  2,   2215, 0,   1, 0, 0,   0,  0,  0,  0,  0,  0, +1,  0,  0,  0,  0,  1,  0,  0);// Morgan's Missing Mizzen
  n = InitItem(n,"book6",  "",         13,  9,  0.10,  3,   2320, 0,   1, 0, 0,   0,  0,  0,  0, +1,  0,  0,  0,  0,  0,  0,  1,  0,  0);// Morgan's Mast Mashing
  n = InitItem(n,"book7",  "",         11, 14,  0.05,  9,   2975, 0,   1, 0, 0,  +1,  +1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0);// Morgan's Almanac
  n = InitItem(n,"book8",  "",         13,  2,  0.10,  1,   2117, 0,   1, 0, 0,   0,  0, +1,  0,  0, +1,  0,  0,  0,  0,  0,  1,  0,  0);// Pirating With Petros
  n = InitItem(n,"book15", "",         13, 12,  0.10,  3,   1306, 0,   1, 0, 1,   0,  0,  0,  0,  0,  0, +1,  0,  0,  0,  0,  1,  0,  0);// Ship Repair Without Nails
  n = InitItem(n,"relationbook", "",   13,  4,  0.00,  1,      1, 0,   1, 0, 1,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1);// Nation Relations Tutorial
  n = InitItem(n,"piratebook", "",     13, 10,  0.00,  1,    500, 0,   1, 0, 1,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1);// Pirate Tutorial
  //------------------------------------------------------------------------------------------------------------------------------------------------------------------
  // Questbook: added by Levis
  //----------------------------------------------------------------------------------------------------------------------------------------------------------------- 
  n = InitItem(n,"book_exorcist", "",  13, 16,  0.00,  3,      0, 0,   1, 0, 1,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  0,  0);// Exorcist Book
  //------------------------------------------------------------------------------------------------------------------------------------------------------------------
  // Questitem: Indian Treasure Quest
  //----------------------------------------------------------------------------------------------------------------------------------------------------------------- 
   n = InitItem(n,"indian_treasure_note", "",  4, 7,  0.00,  1,2, 0,   1, 0, 1,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  0,  1);// Indian Treasure
  //------------------------------------------------------------------------------------------------------------------------------------------------------------------
  // Smuggling Quest items
  //----------------------------------------------------------------------------------------------------------------------------------------------------------------- 
  n = InitItem(n,"smugglingbook", "",        13, 9, 0.05, 1,  200, 0,   1, 0, 1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0);// Smuggling Tutorial
//  n = InitItem(n,"smugglingbook2", "",       13,10, 0.01, 1, 1800, 0,   1, 0, 1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0);// Opium Tutorial
  n = InitItem(n,"opiumlist", "",            13, 8, 0.01, 1,    0, 0,   1, 0, 1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1);// Opium List
  n = InitItem(n,"smuggling_papers", "",      4, 8, 0.00, 1,    0, 0,   0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1); // Smuggling
  n = InitItem(n,"smuggling_first_report", "",4, 9, 0.00, 1,    0, 0,   0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1); // Smuggling Report
  n = InitItem(n,"smuggling_second_report","",4, 9, 0.00, 1,    0, 0,   0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1); // Smuggling Report Opium
  //------------------------------------------------------------------------------------------------------------------------------------------------------------------
  // SKILLBOOKS: added by Levis
  //-----------------------------------------------------------------------------------------------------------------------------------------------------------------
  if(ALLOW_LOCKED_PERKS)
  {
  n = InitItem(n,"skillbook1", "",     13, 4,   0.10,  1,   1875, 0,   0, 0, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0);// Unlock Advance Defence
  n = InitItem(n,"skillbook2", "",     13,14,   0.02,  6,   3165, 0,   0, 0, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0);// Unlock Gun Professional
  n = InitItem(n,"skillbook3", "",     13,10,   0.05,  4,   2550, 0,   0, 0, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0);// Unlock Advanced Damage Control
  n = InitItem(n,"skillbook4", "",     13, 8,   0.01, 10,   3715, 0,   0, 0, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0);// Unlock Cannon Professional
  }
  // PB: SuperDurnius' work on books is now used; number 16 remain unused but could be used for future books
  //     Some skill modifiers changed; all modders' books now give more bonus points than minus points  //BB changed to no negatives and less positive and more cost and higher rarity.
  //-----------------------------------------------------------------------------------------------------------------------------------------------------------------

  // Questbooks Cartagena Library: added by JRH
  //-----------------------------------------------------------------------------------------------------------------------------------------------------------------
  n = InitItem(n,"book21F", "",     "JRH5", 1,  0.00,  1,    179, 0,   0, 0, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1);//law
  n = InitItem(n,"book22F", "",     "JRH5", 2,  0.00,  1,    142, 0,   0, 0, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1);//sea battles
  n = InitItem(n,"book23F", "",     "JRH5", 3,  0.00,  1,    211, 0,   0, 0, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1);//shipbuilding
  n = InitItem(n,"book24F", "",     "JRH5", 4,  0.00,  1,    460, 0,   0, 0, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1);//history
  n = InitItem(n,"book26F", "",     "JRH5", 6,  0.00,  1,    464, 0,   0, 0, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1);//medicine
  n = InitItem(n,"book27F", "",     "JRH5", 7,  0.00,  1,    108, 0,   0, 0, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1);//chemistry
  n = InitItem(n,"book28F", "",     "JRH5", 8,  0.00,  1,    437, 0,   0, 0, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1);//erotica
  n = InitItem(n,"book29F", "",     "JRH5", 9,  0.00,  1,    373, 0,   0, 0, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1);//poetry
  n = InitItem(n,"book31F", "",     "JRH5",11,  0.00,  1,    241, 0,   0, 0, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1);//Dampier's book
  n = InitItem(n,"book33F", "",     "JRH5",13,  0.00,  1,    104, 0,   0, 0, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1);//geography
  n = InitItem(n,"book34F", "",     "JRH5",14,  0.00,  1,    557, 0,   0, 0, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1);//trade
  n = InitItem(n,"book35F", "",     "JRH5",15,  0.00,  1,    291, 0,   0, 0, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1);//mercury
  n = InitItem(n,"book36F", "",     "JRH5",16,  0.00,  1,    219, 0,   0, 0, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1);//GoldBug

  //--------------------------------------------------------------------------------------------------------------------------------------------------
  // JEWELRY:
  //--------------------------------------------------------------------------------------------------------------------------------------------------
  n = InitItem(n,"jewelry1", "sapphire",2,  1,  0.05,  3,    753, 0,   1, 1, 0,   0,  0,  0,  0,  0,  0,  0,  0, +1,  0,  0,  0,  0,  1);// Sapphire			// + skill item //BB remove all skill bonus
  n = InitItem(n,"jewelry2", "diamond", 2,  2,  0.02,  4,   1118, 0,   1, 1, 0,  +1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1);// Diamond				// + skill item //BB but add value to price
  n = InitItem(n,"jewelry3", "ruby",    2,  3,  0.10,  1,    856, 0,   1, 1, 0,   0, +1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1);// Ruby				// + skill item //BB this is valuable and rare
  n = InitItem(n,"jewelry4", "emerald", 2,  4,  0.10,  2,    809, 0,   1, 1, 0,   0,  0,  0,  0,  0,  0, +1,  0,  0,  0,  0,  0,  0,  1);// Emerald				// + skill item //BB gems and jewelry after all!
  n = InitItem(n,"jewelry5", "",        2,  5,  0.10,  1,    209, 0,   1, 1, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1);// Gold Nugget			//BB economci adjusts also.
  n = InitItem(n,"jewelry6", "",        2,  6,  0.10,  2,    320, 0,   1, 1, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1);// Silver sapphire ring
  n = InitItem(n,"jewelry7", "",        2,  7,  0.10,  5,    650, 0,   1, 1, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1);// Gold emerald ring
  n = InitItem(n,"jewelry8", "",        2,  8,  0.15,  1,    730, 0,   1, 1, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0, +1,  0,  0,  0,  1);// Lucky Ring			// + skill item //BB as above, remove all
  n = InitItem(n,"jewelry9", "",        2,  9,  0.15,  2,    960, 0,   1, 1, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0, +1,  0,  0,  0,  1);// Bronze Cross		// + skill item //BB skill bonus for
  n = InitItem(n,"jewelry10","",        2, 10,  0.10,  7,    714, 0,   1, 1, 0,   0,  0,  0,  0,  0, +1,  0,  0,  0,  0,  0,  0,  0,  1);// Gold sapphire ring	// + skill item //BB jewelry items
  n = InitItem(n,"jewelry11","pearlbig",2, 11,  0.15,  2,    693, 0,   1, 1, 0,   0,  0, +1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1);// Large pearl
  n = InitItem(n,"jewelry12","pearlsmall",2,12, 0.20,  1,    320, 0,   1, 1, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1);// Small pearl
  n = InitItem(n,"jewelry13","",        2, 13,  0.10,  3,    482, 0,   1, 1, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1);// Silver Brooch
  n = InitItem(n,"jewelry14","",        2, 14,  0.05,  7,    911, 0,   1, 1, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1);// Gold Brooch
  n = InitItem(n,"jewelry15","",        2, 15,  0.05,  9,   4390, 0,   1, 1, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1);// Emerald Pendant
  n = InitItem(n,"jewelry16","",        2, 16,  0.02, 12,   6925, 0,   1, 1, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1);// Gem necklace
  //--------------------------------------------------------------------------------------------------------------------------------------------------
  // INDIAN TRINKETS:
  //--------------------------------------------------------------------------------------------------------------------------------------------------
  n = InitItem(n,"indian1", "",         5,  1,  0.10,  3,   1750, 1,   1, 1, 0,   0,  0,  0,  0,  0,  0,  0,  0, +1,  0,  0,  0,  0,  1);// Irgantachul Idol
  n = InitItem(n,"indian2", "",         5,  2,  0.05,  1,     70, 1,   1, 1, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1);// Weird Animal Figurine
  n = InitItem(n,"indian3", "",         5,  3,  0.10,  1,    150, 1,   1, 1, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1);// Small Mosaic
  n = InitItem(n,"indian4", "",         5,  4,  0.20,  1,     50, 1,   1, 1, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1);// Clay Jar
  n = InitItem(n,"indian5", "",         5,  5,  0.05,  6,   1730, 1,   1, 1, 0,   0,  0, +1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1);// Markuchankatu Mask	// + skill item
  n = InitItem(n,"indian6", "",         5,  6,  0.05,  4,    770, 1,   1, 1, 0,   0, +1,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  1);// Akumalartu Figurine	// +- skill item
  n = InitItem(n,"indian7", "",         5,  7,  0.10,  3,   1720, 1,   1, 1, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0, +1,  0,  0,  0,  1);// Pikachuatl Idol		// + skill item
  n = InitItem(n,"indian8", "",         5,  8,  0.08,  4,   1440, 1,   1, 1, 0,  +1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1);// Royal Cuspidor
  n = InitItem(n,"indian9", "",         5,  9,  0.05,  5,    460, 1,   1, 1, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1);// Bakachukta Idol
  n = InitItem(n,"indian10", "",        5, 10,  0.07,  2,   1270, 1,   1, 1, 0,   0,  0,  0,  0,  0,  0, +1,  0,  0,  0,  0,  0,  0,  1);// Yxtoikchatlu Idol
  n = InitItem(n,"indian11", "",        5, 11,  0.10,  5,   1250, 1,   1, 1, 0,   0,  0,  0,  0,  0,  0,  0, +1,  0,  0,  0,  0,  0,  1);// Wisdom Tooth Figurine
  n = InitItem(n,"indian12", "",        5, 12,  0.07,  5,    280, 1,   1, 1, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1);// Morchachtulak Idol
  n = InitItem(n,"indian13", "",        5, 13,  0.10,  1,    140, 1,   1, 1, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1);// Ancient Ritual Jar
  n = InitItem(n,"indian14", "",        5, 14,  0.05,  5,    490, 1,   1, 1, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1);// Ichtyloxtumba Idol
  n = InitItem(n,"indian15", "",        5, 15,  0.05,  9,    290, 1,   1, 1, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1);// Clay Ritual Bath
  n = InitItem(n,"indian16", "",        5, 16,  0.05,  3,    120, 1,   1, 1, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1);// Unusually Painted Pot
  n = InitItem(n,"indian17", "stat1",   5, 14,  0.01, 55,   6000, 1,   1, 1, 0,  +1, +1,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1);// Darien Idol			// quest item
  //--------------------------------------------------------------------------------------------------------------------------------------------------
  // MINERALS:
  //--------------------------------------------------------------------------------------------------------------------------------------------------
  n = InitItem(n,"mineral1", "",        7,  1,  0.08,  3,    410, 1,   3, 1, 0,   0,  0,  0,  0, +1,  0,  0,  0,  0,  0,  0,  0,  0,  1);// Pyrite
  n = InitItem(n,"mineral2", "",        7,  2,  0.09,  5,    880, 0,   2, 1, 0,   0,  0,  0, +1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1);// Garnet
  n = InitItem(n,"mineral3", "",        7,  3,  0.08,  8,    950, 1,   2, 1, 0,   0,  0, +1,  0,  0, +1,  0,  0,  0,  0,  0,  0,  0,  1);// Chrysoberyl
  n = InitItem(n,"mineral7", "",        7,  7,  0.12,  5,    650, 0,   1, 1, 0,   0,  0,  0,  0,  0,  0, +1,  0,  0, -1,  0,  0,  0,  1);// Smoky Quartz
  n = InitItem(n,"mineral8", "",        7,  8,  0.08,  8,    630, 0,   1, 1, 0,   0,  0,  0,  0,  0,  0,  0,  0, +1,  0,  0,  0,  0,  1);// Tormaline
  n = InitItem(n,"mineral9", "",        7,  9,  0.10,  9,    550, 0,   2, 1, 0,   0,  0,  0,  0,  0,  0,  0, +1,  0,  0,  0,  0,  0,  1);// Topaz
  n = InitItem(n,"mineral15", "",       7, 15,  0.05,  6,    720, 0,   1, 1, 0,   0,  0,  0,  0, +1,  0,  0,  0,  0,  0,  0,  0,  0,  1);// Platinum
  n = InitItem(n,"mineral16", "",       7, 16,  0.10,  6,    210, 0,   4, 1, 0,  +1,  0, +1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1);// Rock Crystal
  //--------------------------------------------------------------------------------------------------------------------------------------------------
  // SPECIAL:
  //--------------------------------------------------------------------------------------------------------------------------------------------------
  n = InitItem(n,"chinatiger", "",      7, 10,  0.03,  8,   4580, 0,   1, 1, 0,   0,  0,  0, +2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1);// LDH unhide 05Jan09
  n = InitItem(n,"whiteskull", "",      7, 11,  0.08, 10,   2750, 1,   1, 1, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1);// quest item
  n = InitItem(n,"roseskull", "",       7, 12,  0.05, 13,   3250, 1,   1, 1, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1);// quest item
  n = InitItem(n,"blueskull", "",       7, 13,  0.01, 15,   8100, 1,   1, 1, 0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1);// quest item
  n = InitItem(n,"albatross", "",       7,  4,  0.05,  1,     25, 0,   1, 1, 1,   0,  0,  0,  0,  0,  0,  0,  0,  0, -2,  1,  0,  0,  1);// Albatross

if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0 || sti(GetStorylineVar(FindCurrentStoryline(), "BUG_PUZZLES")) > 0
|| sti(GetStorylineVar(FindCurrentStoryline(), "BART_PUZZLES")) > 0)
{
  // JRH MORE (QUEST) ITEMS:
  //-----------------------------------------------------------------------------------------------------------------------------------------------------------------
  n = InitItem(n, "drawing_kit", "",   "JRH11", 12, 0.30, 0, 5000, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1);//JRH quest item + 1 navigation perk
  n = InitItem(n, "tin_jug", 	"",    "JRH11",  7, 0.18, 0,  340, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1);//
  n = InitItem(n, "silver_bar", "",    "JRH11",  8, 0.18, 0, 6250, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1);//
  n = InitItem(n, "foreign_items","",  "JRH11", 10, 0.18, 0,  263, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1);//
  n = InitItem(n, "strange_shells","", "JRH11", 11, 0.18, 0,   54, 0,  1, 0, 1,	  0,  0,  0,  0,  0,  0,  0,  0,  0, +2,  0,  1,  1,  1);//

  n = InitItem(n, "tankard","",        "JRH16", 14, 0.01, 0,  180, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1);//tankard
  n = InitItem(n, "plate","",          "JRH16", 15, 0.01, 0,   95, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1);//plate
  n = InitItem(n, "copper_cauldron","","JRH16", 16, 0.01, 0,  350, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1);//copper_cauldron
  n = InitItem(n, "fish","",              "AS",  2, 0.01, 0,	1, 0,  6, 0, 1,	 -2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1);//fish
  n = InitItem(n, "bible_shot","",      "JRH3", 14, 0.00, 0,	0, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0, +1,  0, +1,  1,  1,  1,  1);//selkirk damaged bible
  n = InitItem(n, "jewelcross","",     "JRH14", 10, 0.00, 0, 1971, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1);//church treasure
  n = InitItem(n, "fake_reliquary","", "JRH14", 12, 0.00, 0, 1050, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0,  0,  0, +3,  0,  1,  1,  1);//church treasure
  n = InitItem(n, "fake_chalice","",   "JRH14",  9, 0.00, 0, 1575, 0,  1, 0, 0,	 +1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1);//temp use
  n = InitItem(n, "fake_censer","",    "JRH14", 11, 0.00, 0,  945, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0, +4,  0,  0,  0,  1,  1,  1);//temp use
  n = InitItem(n, "fake_candelabre","","JRH14", 13, 0.00, 0, 1260, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0,  0, +2,  0,  0,  1,  1,  1);//temp use
  n = InitItem(n,"rolls_of_bandages","","JRH9", 15, 0.00, 1,  800, 0,  1, 1, 1,	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  0);//JRH quest item

  n = InitItem(n,"coin1",	"",    "JRH15",  1, 0.00, 0,  187, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1);//swedish silver
  n = InitItem(n,"coin2",	"",    "JRH15",  2, 0.00, 0,   47, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1);//swedish copper
  n = InitItem(n,"coin3",	"",    "JRH15",  3, 0.00, 0,  750, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1);//spanish gold
  n = InitItem(n,"coin4",	"",    "JRH15",  4, 0.00, 0,  187, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1);//spanish silver
  n = InitItem(n,"coin5",	"",    "JRH15",  5, 0.00, 0,  375, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1);//english gold
  n = InitItem(n,"coin6",	"",    "JRH15",  6, 0.00, 0,   47, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1);//english silver
  n = InitItem(n,"coin7",	"",    "JRH15",  7, 0.00, 0,   70, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1);//chinese brass
  n = InitItem(n,"coin8",	"",    "JRH15",  8, 0.00, 0,   47, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1);//chinese copper
  n = InitItem(n,"coin9",	"",    "JRH15",  9, 0.00, 0,  375, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1);//arabic gold
  n = InitItem(n,"coin10",	"",    "JRH15", 10, 0.00, 0,   94, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1);//arabic silver
  n = InitItem(n,"coin11",	"",    "JRH15", 11, 0.00, 0,   23, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1);//arabic small silver
  n = InitItem(n,"coin12",	"",    "JRH15", 12, 0.00, 0,  187, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1);//french gold
  n = InitItem(n,"coin13",	"",    "JRH15", 13, 0.00, 0,  375, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1);//dutch gold
  n = InitItem(n,"coin14",	"",    "JRH15", 14, 0.00, 0,  187, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1);//dutch square silver
  n = InitItem(n,"coin15",	"",    "JRH15", 15, 0.00, 0,  187, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1);//dutch round silver
  n = InitItem(n,"coin16",	"",    "JRH15", 16, 0.00, 0,  187, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1);//portuguese gold
  n = InitItem(n,"coin4_bad",	"",    "JRH14", 14, 0.00, 0,    0, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1);//spanish piece of eight, not of any use

  n = InitItem(n, "gold_bars", "",     "JRH37", 12, 0.18, 0,12500, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1);//JRH BB treasure
  n = InitItem(n, "silver_bars", "",   "JRH37", 13, 0.18, 0,12500, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1);//JRH BB treasure
  n = InitItem(n, "gold_coins", "",    "JRH37", 14, 0.18, 0,12500, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1);//JRH BB treasure
  n = InitItem(n, "valuable_weapons","","JRH37",15, 0.18, 0,12500, 0,  1, 0, 0,	  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1);//JRH BB treasure
}
  //-----------------------------------------------------------------------------------------------------------------------------------------------------------------

  n = InitMaps(n); // KK

  n = RestoreStoredItems(n); // Added by Levis
  
  //-------------------------------------------------------------------------------------------------------------------------------
  // NK -->
  //set Items_quantity
  ITEMS_QUANTITY = n;

  //InitRandItems(); // TIH moved further down Aug24'06
  //InitWeaponItemArrays(); // TIH moved further down Aug24'06
  SKILLITEMS_QUANTITY = 0;
  TRADEITEMS_QUANTITY = 0; // NK 05-04-01 itemtrade
  float price, qual;
  string tmpstr;
  for(n=0; n<ITEMS_QUANTITY; n++) //loop for skill items
  {
    makeref(itm,Items[n]);
    //trace("-----------------------------------------------");
    //trace("Item "+ n +": "+itm.id);
    // NK 05-04-03 itemtrade assign quality -->
    if(sti(itm.skiptrade))
    {
      itm.skipgeneral = true;
      itm.skipsell = true;
      DeleteAttribute(&itm,"quality");
    } // 05-04-01 NK itemtrade add skipgeneral attribute, delete qual
    else
    {
      if(sti(itm.quality) == -1)  // means we auto-assign
      {
        price = stf(itm.price);
        if(!CheckAttribute(itm,"groupID"))
        {
          // All items have groupID now so this code is never used
          qual = pow2(price, IT_QUAL_AI_POW) * IT_QUAL_AI_SCL;  // price^0.5 * 0.165, 150=2, 925=5, 3700=10
//          Trace("Item without GroupID = " + itm.id);  // never gets executed
        }
        else
        {
          price /= IT_WEAP_PRICE_SCL;               // price / 0.25
          qual = pow2(price, IT_QUAL_AW_POW) * IT_QUAL_AW_SCL; // (price*4)^0.33333 * 0.22, 200=2, 3000=5, 5000=6, 23500=10
        }
        itm.quality = iclamp(IT_QUAL_MIN, IT_QUAL_MAX, round(qual));  // 1..10
      }
	  if(sti(itm.quality) == -2)	DeleteAttribute(itm, "quality"); // PB: Remove attribute for items that should remain available throughout the game
      if(CheckAttribute(itm,"groupID"))
      {
        if(!sti(itm.skiptype))
        {
          tmpstr = itm.groupID;
          itm.types.(tmpstr) = true;
        }
      }
      TRADEITEMS_QUANTITY++; // NK 05-04-01 itemtrade
    }
    // NK <--
    if(!CheckAttribute(itm,"minlevel")) itm.minlevel = 1;
//    if(sti(itm.minlevel) < 1) itm.minlevel = 1;
    if(sti(itm.minlevel) < 0) itm.minlevel = 0;   // LDH reduced minlevel minimum to zero - 09May09
    if(CheckAttribute(itm,"skill"))
    {
      SKILLITEMS[SKILLITEMS_QUANTITY].id = itm.id;
      SKILLITEMS_QUANTITY++;
      if(!CheckAttribute(itm,"skill.num")) itm.skill.num = 1;
      if(!CheckAttribute(itm,"skill.stack")) itm.skill.stack = false;			//JRH
      if(!CheckAttribute(itm,"skill.hidden")) itm.skill.hidden = 0;
    }
    //DumpAttributes(itm);
    //trace("-----------------------------------------------");
  }
  // NK <--
  // TIH --> moved these to here, so that they use proper settings that may be set above Aug24'06
  InitRandItems(); // init random items from this list
  InitWeaponItemArrays(); // moved down here so it can USE the ITEMS_QUANTITY to perform
  // TIH <--
  //-------------------------------------------------------------------------------------------------------------------------------
  trace("Items initialization complete. Loaded "+ITEMS_QUANTITY+" items.");
}
//===============================================================================================================================


//-------------------------------------------------------------------------------------------------------------------------------
void InitButtons()
{
  aref lab3;
  makearef(lab3, Locations[FindLocation("Labirint_3")]);

  lab3.items.b_1.locator = "button01";
  lab3.items.b_1.model   = "b1";
  lab3.items.b_1.itemDeltaY  = 0.0;
  lab3.items.b_1.deltaY  = -0.05;
  lab3.items.b_1.trigged  = false;

/*
  lab3.items.b_2.locator = "b_2";
  lab3.items.b_2.model   = "items\b2";
  lab3.items.b_2.itemDeltaY  = 0.1;
  lab3.items.b_2.deltaY  = -0.1;
  lab3.items.b_2.trigged  = false;

  lab3.items.b_3.locator = "b_3";
  lab3.items.b_3.model   = "items\b3";
  lab3.items.b_3.itemDeltaY  = 0.1;
  lab3.items.b_3.deltaY  = -0.1;
  lab3.items.b_3.trigged  = false;

  lab3.items.b_4.locator = "b_4";
  lab3.items.b_4.model   = "items\b4";
  lab3.items.b_4.deltaY  = -0.1;
  lab3.items.b_4.trigged  = 0;

  lab3.items.b_5.locator = "b_5";
  lab3.items.b_5.model   = "items\b5";
  lab3.items.b_5.deltaY  = -0.1;
  lab3.items.b_5.trigged  = false;

  lab3.items.b_6.locator = "b_6";
  lab3.items.b_6.model   = "items\b6";
  lab3.items.b_6.deltaY  = -0.3;
  lab3.items.b_6.trigged  = false;

  lab3.items.b_7.locator = "b_7";
  lab3.items.b_7.model   = "items\b7";
  lab3.items.b_7.deltaY  = -0.1;
  lab3.items.b_7.trigged  = false;

  lab3.items.b_8.locator = "b_8";
  lab3.items.b_8.model   = "items\b8";
  lab3.items.b_8.deltaY  = -0.1;
  lab3.items.b_8.trigged  = false;

  lab3.items.b_9.locator = "b_9";
  lab3.items.b_9.model   = "items\b9";
  lab3.items.b_9.deltaY  = -0.3;
  lab3.items.b_9.trigged  = false;
*/
}
//-------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------
void InitRandItems()
{
  ref rnditem, itm;

// NK -->
// loop through items to find all rand-enabled items.
  RANDITEMS_QUANTITY = 0;
  int i, j;
  for(i = 0; i < ITEMS_QUANTITY; i++)
  {
    makeref(itm,Items[i]);
    if(CheckAttribute(itm,"skiprand") && sti(itm.skiprand)) continue;
    for(j = 0; j < sti(itm.numrand); j++)
    {
      makeref(rnditem,RandItems[RANDITEMS_QUANTITY]);
      rnditem.id = itm.id;
      rnditem.maxQuantity = intRet(CheckAttribute(itm,"groupID"),1,4);
      RANDITEMS_QUANTITY++;
    }
  }
// NK <--
}
//-------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------
void InitWeaponItemArrays()
{
  ref WeaponItem;
  ref Item;
  BLADE_HIGH = -1;
  GUN_HIGH   = -1;
  int i;
  for(i = 0; i < ITEMS_QUANTITY; i++)
  {
    makeref(Item,Items[i]);
    if(CheckAttribute(Item,"groupID") && !sti(Item.skipequip))
    {
      switch(Item.groupID)
      {
        case BLADE_ITEM_TYPE:
          BLADE_HIGH++;
          makeref(WeaponItem,BladeItems[BLADE_HIGH]);
          CopyAttributes(WeaponItem,Item);
        break;
        case GUN_ITEM_TYPE:
          GUN_HIGH++;
          makeref(WeaponItem,GUNItems[GUN_HIGH]);
          CopyAttributes(WeaponItem,Item);
        break;
      }
    }
  }
  SortBladeArray(0,BLADE_HIGH,"minlevel","dmg_max");  // LDH sort by minlevel then max damage within minlevel, fast sort - 09May09
  SortGunArray(0,GUN_HIGH);

//  Trace("----------PostSort--------------------------------------");
//  for(i = 0; i <= BLADE_HIGH; i++)
//  {
//    Trace(i + "," + BladeItems[i].minLevel + "," + BladeItems[i].id + "," + sti(BladeItems[i].dmg_max) + "," + BladeItems[i].price);
//  }
//  Trace("----------PostSort--------------------------------------");
//  for(i = 0; i <= GUN_HIGH; i++)
//  {
//    Trace(i + "," + GunItems[i].minLevel + "," + GunItems[i].id + "," + sti(GunItems[i].dmg_max) + "," + GunItems[i].price);
//  }
//  Trace("--------------------------------------------------------");
}
//-------------------------------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------------------------------
// Sulan: simplified and improved Weaponsmod code by scheffnow      --->
//-------------------------------------------------------------------------------------------------------------------------------
 int InitBlade( ref     ItemIndex,
                string  id,
                string  ModelID,
                string  picTexture,
                int     picIndex,
                float   Rare,
                int     MinLevel,
                int     Price,
                float   DmgMin,
                float   DmgMax,
                int     Piercing,
                int     Blocking,
                string  nation,
                float   Disarm,
                int     NoWeaponsMod,
                int     firstperiod,
                int     lastperiod) // PB: Added to enable disarming with weapons mod on // Sulan: Added NoWeaponsMod for items which don't have quality textures, added period
{
  ref blade;
  int BladeIndex = ItemIndex;
  string  typetemp;     // NK 05-04-06
  nation += "";         // Sulan: if called without nation string
  int i;
  int QualityPiercing;
  int QualityBlocking;
  int QualityMinLevel;
  int QualityPrice;
  float QualityDisarm; // PB: Added to limit disarming
  float QualityRare;
  float QualityDmgMin;
  float QualityDmgMax;
  bool  QualitySkipRand;
  bool  QualitySkipTrade;
  bool  QualitySkipSell; // NK 05-04-06 so traders can buy items but not sell them.
  bool  QualitySkipEquip; // PB
  string  QualityTexture;
  string  QualityName;
  string  BladeID;


  if(ENABLE_WEAPONSMOD && (NoWeaponsMod == 0))
  {
    for (i = 0; i < 6; i++)
    {
      // start quality settings
      QualityDmgMin = (1.0 + (i-2) * 0.05) * DmgMin;  // 0.90, 0.95, 1.00, 1.05, 1.10, 1.15
      QualityDmgMax = (1.0 + (i-2) * 0.05) * DmgMax;
      QualityPrice  = (1.0 + (i-2) * 0.25) * Price;   // 0.50, 0.75, 1.00, 1.25, 1.50, 1.75
      if ( IT_RPG_STYLE ) QualityRare = Rare * (1.0 - 0.12 * makefloat(abs(1-i))); // TIH so the low quality items show up for low level characters (they get purged at higher levels)
      else                QualityRare = Rare * (1.0 - 0.17 * makefloat(abs(2-i))); // NK 05-04-05 mod so bad items are rarer, as well as excellent, average = Rare
      QualitySkipTrade = false;
      QualitySkipRand  = true;	// PB: You loot weapons all the time anyway
      QualitySkipSell  = false; // NK 05-04-06 so traders can buy items but not sell them.
      QualitySkipEquip = false; // PB
      QualityDisarm = (-2 + i) * Disarm // PB: Added to limit disarming to good sabers and up
      switch(i)
      {
        case 0:
          QualityTexture  = "ITEMS_" + picTexture + "-2";
          if(BLADEDAMAGE_ENABLED) QualityName = "Broken"; // PB: Replace Badly Worn with Broken
          else QualityName  = "Badly worn";
          BladeID   = id + "-2";
          QualitySkipSell = true; // NK 05-04-06 so traders can buy items but not sell them.
          if(BLADEDAMAGE_ENABLED) QualitySkipEquip  = true; // So enemies don't carry broken blades
        break;

        case 1:
          QualityTexture  = "ITEMS_" + picTexture + "-1";
          QualityName = "Worn";
          BladeID   = id + "-1";
          if ( !IT_RPG_STYLE ) QualitySkipSell  = true; // TIH skipsell if players are showing all items regardless of level // NK 05-04-06 so traders can buy items but not sell them.
        break;

        case 2:
          QualityTexture  = "ITEMS_" + picTexture;
          QualityName = "Average";
          BladeID   = id;
        break;

        case 3:
          QualityTexture  = "ITEMS_" + picTexture + "+1";
          QualityName = "Good";
          BladeID   = id + "+1";
        break;

        case 4:
          QualityTexture  = "ITEMS_" + picTexture + "+2";
          QualityName = "Fine";
          BladeID   = id + "+2";
          QualitySkipRand = true;
        break;

        case 5:
          QualityTexture  = "ITEMS_" + picTexture + "+3";
          QualityName = "Excellent";    // LDH fix spelling 07May09
          BladeID   = id + "+3";
          QualitySkipSell = true;
          QualitySkipRand = true; // You won't find excellent blades
        break;
      }

      QualityBlocking = makeint(-2 + i + Blocking); // TIH 'makeint' instead of 'sti' Nov21'06
      if(QualityBlocking < 0)
      {
        QualityBlocking = 0;
      }
      QualityPiercing = makeint(-2 + i + Piercing); // TIH 'makeint' instead of 'sti' Nov21'06
      if(QualityPiercing < 0)
      {
        QualityPiercing = 0;
      }
      QualityMinLevel = makeint(-2 + i + MinLevel);         // TIH 'makeint' instead of 'sti' Nov21'06 // TIH number change Aug24'06 - TIH fixed to restrict better quality to higher levels
      if(QualityMinLevel < 0 && MinLevel != 0)              // NK fix for too many daggers 05-07-09
      {
        QualityMinLevel = 0;
      }
      // end quality settings

      makeref(blade,Items[BladeIndex]);
      blade.id            = BladeID;
      blade.baseid        = id; // TIH
      blade.BladeQuality  = i;
      blade.groupID       = BLADE_ITEM_TYPE;
      blade.name          = "itmname_" + id;
      blade.describe      = "itmdescr_" + id;
      blade.model         = ModelID;
      blade.QualityName   = QualityName;
      blade.picTexture    = QualityTexture;
      blade.picIndex      = picIndex;
      blade.minlevel      = QualityMinLevel;
      blade.price         = QualityPrice; // LDH 09May09
      blade.dmg_min       = QualityDmgMin;
      blade.dmg_max       = QualityDmgMax;
      blade.piercing      = QualityPiercing;
      blade.block         = QualityBlocking;
      blade.skiptrade     = QualitySkipTrade;
      blade.skipequip     = QualitySkipEquip;
      // PB: Unique Blades -->
      if (IsWeaponUnique(id))
      {
        blade.rare        = 0.00;
        blade.minlevel    = 99;
      }
      else
      {
        blade.skiprand    = QualitySkipRand;
        blade.skipsell    = QualitySkipSell; // NK 05-04-06 so traders can buy items but not sell them.
        blade.rare        = QualityRare;
      }
      if (stf(blade.rare) == 0.0)
      {
        blade.skiprand    = true;
        blade.skipsell    = true;
        blade.minlevel    = 99;
      }
      // PB: Unique Blades <--
	switch(id)
	{
		case "blade1" :		blade.param.time  = 0.05;		break;  // special case
        	case "blade24":		blade.param.time  = 0.05;		break;  // special case
		case "bladeC36":	QualitySkipRand = true;			break;  // special case, JRH (only in stores)
		case "bladeclub":	blade.sound = "OBJECTS\DUEL\club2.wav";	break;//JRH
		// PB: Who would want to buy this? -->
		case "Barmansknife":
			QualitySkipSell = true;		
			if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0) QualitySkipTrade = true;
		break;
		case "Guestsknife":	QualitySkipSell = true;		break;
		case "MerchantsBlade":	QualitySkipSell = true;		break;
		case "Merchantsdagger":	QualitySkipSell = true;		break;
		case "Minersaxe":	QualitySkipSell = true;		break;
		case "Minerscrow":	QualitySkipSell = true;		break;
		case "Piratesdagger":	QualitySkipSell = true;		break;
		// PB: Who would want to buy this? <--
	}
      if ( IT_RPG_STYLE && QualityRare < IT_WEAP_RARITY_CUTOFF ) blade.skipsell = true; // TIH do not ever sell extremely rare items
      if (sti(blade.skipsell) != 1 && i<5) blade.replacewith = GetWeaponIDByQuality(id, i+1); // NK 05-04-06 so that if a weapon sellability gets lost due to quality upping (or they buy a -2 or -1 one), we replace with the next up.
      // PB: Disarm mode toggles -->
      if (DISARM_MODE == 2)
      { blade.disarm    = 100;  } // Testmode
      else {blade.disarm  = QualityDisarm;} // Default
      // PB: Disarm mode toggles <--
      blade.folder    = "ammo";
      blade.param.time  = 0.1;
      blade.param.colorstart  = argb(64, 64, 64, 64);
      blade.param.colorend  = argb(0, 32, 32, 32);
      typetemp = BLADE_ITEM_TYPE;
      blade.types.(typetemp) = true;
      /* Sulan : I don't know what this should do - it seems it doesn't do anything
      if(nation != "")
      {
        typetemp = IT_TYPE_NATION + nation;
        blade.types.(typetemp) = true;
        typetemp = BLADE_ITEM_TYPE + "_" + typetemp;
        blade.types.(typetemp) = true;
      }
      */
      blade.nation = nation + "";
      blade.firstperiod = firstperiod;
      blade.lastperiod = lastperiod;
      BladeIndex++;
    }
  }
  else       // Sulan: Not using the Weaponsmod (different qualities)
  {
    makeref(blade,Items[BladeIndex]);
    blade.id                = id;
    blade.groupID           = BLADE_ITEM_TYPE;
    blade.name              = "itmname_" + id;
    blade.describe          = "itmdescr_" + id;
    blade.model             = ModelID;
    blade.picTexture        = "ITEMS_" + picTexture;
    blade.picIndex          = picIndex;
    blade.folder            = "ammo";
    blade.param.time        = 0.1;
    blade.param.colorstart  = argb(64, 64, 64, 64);
    blade.param.colorend    = argb(0, 32, 32, 32);
    blade.skiptrade         = false;
    blade.skipequip         = false;
    // PB: Unique Blades -->
    if (IsWeaponUnique(id))
    {
      blade.rare      = 0.00;
      blade.minlevel    = 99;
    }
    else
    {
      blade.skiprand    = true;		// PB: You loot weapons all the time anyway
      blade.skipsell    = false;	// NK 05-04-06 so traders can buy items but not sell them.
      blade.rare        = rare;
    }
    if (stf(blade.rare) == 0.0)
    {
      blade.skiprand    = true;
      blade.skipsell    = true;
      blade.minlevel    = 99;
    }
    // PB: Unique Blades <--
    switch(id)
    {
		case "bladelead":		blade.stun = 0.10;							// Stun enemies
								blade.skipequip = NO_SPECIALWEAPONED_NPC;	// Random characters don't use them
								blade.skiptrade = true;						// Not sold from regular traders
								blade.sneaky = true;		break;			// PB: Sneaky Trader
		case "bladeclub":		blade.stun = 0.75;							// Stun enemies
								blade.skipequip = NO_SPECIALWEAPONED_NPC;	// Random characters don't use them
								blade.skiptrade = true;						// Not sold from regular traders
								blade.sneaky = true;						// PB: Sneaky Trader
								blade.sound = "OBJECTS\DUEL\club2.wav";	break;	//JRH
		case "blade1" :			blade.param.time  = 0.05;	break;			// special case
		case "blade24":			blade.param.time  = 0.05;	break;			// special case
		case "bladeC36":   		blade.skiprand    = true;	break;  		// special case, JRH (only in stores)
		// PB: Who would want to buy this? -->
		case "Barmansknife":	blade.skipsell = true;		
		if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0) blade.SkipTrade = true; break;
		case "Guestsknife":		blade.skipsell = true;		break;
		case "MerchantsBlade":	blade.skipsell = true;		break;
		case "Merchantsdagger":	blade.skipsell = true;		break;
		case "Minersaxe":		blade.skipsell = true;		break;
		case "Minerscrow":		blade.skipsell = true;		break;
		case "Piratesdagger":	blade.skipsell = true;		break;
		case "Machete":			blade.skipsell = true;		break;	//JRH
		case "MinersSpade":		blade.sound = "PEOPLE\spade.wav";break; //JRH
		// PB: Who would want to buy this? <--
    }

    if ( IT_RPG_STYLE && Rare < IT_WEAP_RARITY_CUTOFF ) blade.skipsell = true; // TIH do not ever sell extremely rare items

    blade.minlevel      = MinLevel;
    blade.price         = Price;
    blade.dmg_min       = DmgMin;
    blade.dmg_max       = DmgMax;
    blade.piercing      = Piercing;
    blade.block         = Blocking;

    // PB: Disarm mode toggles -->
    if (DISARM_MODE == 2)
      { blade.disarm = 100; }     // Testmode
    else
      { blade.disarm = Disarm; }  // Default
    // PB: Disarm mode toggles <--
    blade.nation = nation + "";
    BladeIndex++;
  }
  blade.firstperiod = firstperiod;
  blade.lastperiod = lastperiod;
  return BladeIndex;
}

bool IsWeaponUnique(string id)
{
  bool isUnique = false;
  switch(id)
  {
	case "blade18":		isUnique = true;        break;  // Saber of Nicholas Sharp    - Quest only blade
	case "blade24":		isUnique = true;        break;  // English Officer's Saber    - English presentation blade
	case "blade22":		isUnique = true;        break;  // Corsair's Pride            - English presentation blade
	case "blade23":		isUnique = true;        break;  // Dutch Admiralty Sword      - Dutch presentation blade
	case "blade26":		isUnique = true;        break;  // Solingen Rapier            - Dutch presentation blade
	case "blade9":		isUnique = true;        break;  // French Admiralty Rapier    - French presentation blade
	case "blade25":		isUnique = true;        break;  // French Nobility Sword      - French presentation blade
	case "blade33":		isUnique = true;        break;  // Moorish Saber              - Spanish presentation blade
	case "blade14":		isUnique = true;        break;  // Spanish Nobility Longsword - Spanish presentation blade
	case "blade29":		isUnique = true;        break;  // Portugese Officer's Sword  - Portugese presentation blade
	case "blade32":		isUnique = true;        break;  // Damascus Shamshir          - Portugese presentation blade
	case "blade43":		isUnique = true;        break;  // US Cavalry Saber           - American presentation blade
	case "blade34":		isUnique = true;        break;  // Dragon's Head              - Pirate special blade
	case "bladeC17":	isUnique = true;	break;	// Flamberge rapier           - For "Ardent" storyline only
	case "bladeC23":	isUnique = true;	break;	// Toledo rapier              - For "Ardent" storyline only
	case "bladeC36":	isUnique = true;	break;	// Katana	              - Japanese import
	case "blade308":	isUnique = true;	break;	// Based on Anathros	      - From "Two Worlds"
	case "bladeCiri":	isUnique = true;	break;	// Ciri's Blade		      - Forged by gnomes
	case "bladeMH":		isUnique = true;	break;	// Secret Reward              - Reward for killing Malcolm Hatcher
	case "witcher_steel":	isUnique = true;	break;	// Geralt's steel flambard
	case "tomahawk_chief":  isUnique = true;        break;  // Chief's tomahawk for "Crystal Skull" sidequest  
	case "pistol10":	isUnique = true;        break;  // Shotgun
	case "pistol62":	isUnique = true;        break;  // Special dual-barrel pistol - Easter egg in San Juan residence
	case "LongRifle_BT":	isUnique = true;        break;  // Bartolomeu
	case "LongRifle_C":	isUnique = true;        break;  // All Storylines
	case "LongRifle_CT":	isUnique = true;        break;  // All Storylines
	case "LongRifle_W":	isUnique = true;        break;  // WoodesRogers
	case "LongRifle_WT":	isUnique = true;        break;  // WoodesRogers
	case "pistolbow":	isUnique = true;        break;  // Bow
	case "pistolwhip":	isUnique = true;        break;  // Bartolomeu
	case "machete":		isUnique = true;        break;  // JRH
	case "blademketB":	isUnique = true;        break;  // JRH
	case "blademketK":	isUnique = true;        break;  // JRH
	case "collier":		isUnique = true;        break;  // Collier revolver
	case "bladeA2":		isUnique = true;        break;  // JRH WR quest
	case "bladeA4":		isUnique = true;        break;  // JRH WR quest
	case "bladeA5":		isUnique = true;        break;  // JRH WR quest
	case "bladeA11":	isUnique = true;        break;  // JRH WR quest
	case "bladeA17":	isUnique = true;        break;  // JRH WR quest
  }
  return isUnique;
}

int InitGun(  ref ItemIndex,
      string  id,
      string  ModelID,
      string  picTexture,
      int   picIndex,
      float Rare,
      int   MinLevel,
      int   Price,
      float DmgMin,
      float DmgMax,
      int   Accuracy,
      int   Charges,
      int   ChargeSpeed,
      string  nation,
      string  sound,
      string  shottype,
      int NoWeaponsMod,
      int firstperiod,
      int lastperiod)
{
  ref gun;
  int i;
  int gunIndex;
  int QualityAccuracy;
  int QualityChargeSpeed;
  int QualityMinLevel;
  int QualityPrice;
  float QualityRare;
  float QualityDmgMin;
  float QualityDmgMax;
  bool  QualitySkipRand;
  bool  QualitySkipSell; // NK 05-04-06 so traders can buy items but not sell them.
  string  QualityTexture;
  string  QualityName;
  string  gunID;
  string  typetemp; // NK 05-04-06
  nation += "";
  gunIndex = ItemIndex;

  if(ENABLE_WEAPONSMOD && (NoWeaponsMod == 0))
  {
    for (i = 0; i < 6; i++)
    {
      QualityDmgMin = (1.0 + (i-2) * 0.05) * DmgMin;
      QualityDmgMax = (1.0 + (i-2) * 0.05) * DmgMax * WEAPMOD_GUNDMG; // * 1.5
      QualityPrice  = (0.5 + stf(i * 0.25)) * Price;
      if ( IT_RPG_STYLE ) QualityRare = Rare * (1.0 - 0.12 * makefloat(abs(1-i))); // TIH so the low quality items show up for low level characters (they get purged at higher levels)
      else        QualityRare = Rare * (1.0 - 0.17 * makefloat(abs(2-i))); // NK 05-04-05 mod so bad items are rarer, as well as excellent, average = Rare
      QualityAccuracy = makeint(-2 + i + Accuracy); // TIH 'makeint' instead of 'sti' Nov21'06
      QualitySkipRand = true;	// PB: You loot weapons all the time anyway
      QualitySkipSell = false;	// NK 05-04-06 so traders can buy items but not sell them. Fix type 05-04-07
      switch(i)
      {
        case 0:
          QualityTexture  = "ITEMS_" + picTexture + "-2";
          QualityName = "Badly worn";
          gunID   = id + "-2";
          if ( !IT_RPG_STYLE ) QualitySkipSell  = true; // TIH skipsell if players are showing all items regardless of level // NK 05-04-06 so traders can buy items but not sell them.
          QualitySkipRand = true;
        break;

        case 1:
          QualityTexture  = "ITEMS_" + picTexture + "-1";
          QualityName = "Worn";
          gunID   = id + "-1";
          if ( !IT_RPG_STYLE ) QualitySkipSell  = true; // TIH skipsell if players are showing all items regardless of level // NK 05-04-06 so traders can buy items but not sell them.
        break;

        case 2:
          QualityTexture  = "ITEMS_" + picTexture;
          QualityName  = "Average";
          gunID    = id;
        break;

        case 3:
          QualityTexture  = "ITEMS_" + picTexture + "+1";
          QualityName = "Good";
          gunID   = id + "+1";
        break;

        case 4:
          QualityTexture  = "ITEMS_" + picTexture + "+2";
          QualityName = "Fine";
          gunID   = id + "+2";
          QualitySkipRand = true;
        break;

        case 5:
          QualityTexture  = "ITEMS_" + picTexture + "+3";
          QualityName = "Excellent";    // LDH fixed spelling 07May09
          gunID   = id + "+3";
          QualitySkipSell = true;
          QualitySkipRand = true;
        break;
      }
      QualityMinLevel = makeint(-2 + i + MinLevel); // TIH 'makeint' instead of 'sti' Nov21'06 // TIH number change Aug24'06 - TIH fixed to restrict better quality to higher levels
      if(QualityMinLevel < 0)
      {
        QualityMinLevel = 0;
      }

      QualityChargeSpeed = ChargeSpeed;

      makeref(gun,Items[gunIndex]);
      gun.id          = gunID;
      gun.baseid      = id; // TIH
      gun.sound       = sound;  //JRH
      gun.shottype    = shottype;//JRH
      gun.gunQuality  = i;
      gun.groupID     = GUN_ITEM_TYPE;
      gun.name        = "itmname_" + id;
      gun.describe    = "itmdescr_" + id;
      gun.model       = ModelID;
      gun.chargeQ     = Charges;
      gun.QualityName = QualityName;
      gun.picTexture  = QualityTexture;
      gun.picIndex    = picIndex;
      gun.minlevel    = QualityMinLevel;
      gun.price       = QualityPrice; // LDH 09May09
      gun.dmg_min     = QualityDmgMin;
      gun.dmg_max     = QualityDmgMax;
      gun.chargespeed = QualityChargeSpeed;
      gun.accuracy    = QualityAccuracy;
      switch(id)
      {
        case "pistol3":      gun.multidmg = 1;     break; // PB: Grapeshot Pistol
	case "portugize":    gun.multidmg = 1;     break; // JRH: Grapeshot Pistol
        case "pistolmtoon":  gun.multidmg = 1;     break; // PB: Musketoon
        case "pistol10":     gun.enblrld = true;   break; // PB: Shotgun
        case "LongRifle_BT": gun.enblrld = true;   break; // JRH: Bartolomeu
	case "LongRifle_CT": gun.enblrld = true;   break; // JRH: All Storylines
	case "LongRifle_WT": gun.enblrld = true;   break; // JRH: WoodesRogers
	case "pistol26":     gun.multidmg = 1;     break; // JRH
	case "pistolbow":    gun.arrow = 1;        break; // JRH
      }
      // PB: Unique Guns -->
      if (IsWeaponUnique(id))
      {
        gun.rare      = 0.00;
        gun.minlevel    = 99;
      }
      else
      {
        gun.skiprand    = QualitySkipRand;
        gun.skipsell    = QualitySkipSell; // NK 05-04-06 so traders can buy items but not sell them.
        gun.rare        = QualityRare;
      }
      if (stf(gun.rare) == 0.0)
      {
        gun.skiprand    = true;
        gun.skipsell    = true;
        gun.minlevel    = 99;
      }
      // PB: Unique Guns <--
      gun.skipequip   = false;
      gun.skiptrade   = false;
      if ( IT_RPG_STYLE && QualityRare < IT_WEAP_RARITY_CUTOFF ) gun.skipsell = true; // TIH do not ever sell extremely rare items
      if (sti(gun.skipsell) != 1 && i<5) gun.replacewith = GetWeaponIDByQuality(id, i+1); // NK 05-04-06 so that if a weapon sellability gets lost due to quality upping (or they buy a -2 or -1 one), we replace with the next up.
      gun.folder      = "ammo";
      typetemp = GUN_ITEM_TYPE;
      gun.types.(typetemp) = true;
      /*
      if(nation != "")
      {
        typetemp = IT_TYPE_NATION + nation;
        gun.types.(typetemp) = true;
        typetemp = GUN_ITEM_TYPE + "_" + typetemp;
        gun.types.(typetemp) = true;
      }
      */
      gun.nation = nation + "";
      gun.firstperiod = firstperiod;
      gun.lastperiod  = lastperiod;
      gunIndex++;
    }
  }
  else    // Sulan: Not using the Weaponsmod (different qualities)
  {
    makeref(gun,Items[gunIndex]);
    gun.id      = id;
    gun.name    = "itmname_" + id;
    gun.describe  = "itmdescr_" + id;
    gun.model     = ModelID;
    gun.picIndex  = picIndex;
    gun.picTexture  = "ITEMS_" + picTexture;
    gun.folder    = "ammo";

    switch(id)
    {
        case "pistol3":      gun.multidmg = 1;     break; // PB: Grapeshot Pistol
        case "pistolmtoon":  gun.multidmg = 1;     break; // PB: Musketoon
        case "pistol10":     gun.enblrld = true;   break; // PB: Shotgun
		case "LongRifle_BT": gun.enblrld = true;   break; // JRH: Bartolomeu
		case "LongRifle_CT": gun.enblrld = true;   break; // JRH: All Storylines
		case "LongRifle_WT": gun.enblrld = true;   break; // JRH: WoodesRogers
		case "pistolbow":    gun.arrow = 1;        break; // JRH
    }
    // PB: Unique Guns -->
    if (IsWeaponUnique(id))
    {
      gun.rare      = 0.00;
      gun.minlevel    = 99;
    }
    else
    {
      gun.skiprand    = false;
      gun.skipsell    = false; // NK 05-04-06 so traders can buy items but not sell them.
      gun.rare        = Rare;
    }
    if (stf(gun.rare) == 0.0)
    {
      gun.skiprand    = true;
      gun.skipsell    = true;
      gun.minlevel    = 99;
    }
    // PB: Unique Guns <--
    gun.skipequip = false;
    gun.skiptrade   = false;
    if ( IT_RPG_STYLE && rare < IT_WEAP_RARITY_CUTOFF ) gun.skipsell = true; // TIH do not ever sell extremely rare items

    gun.price       = Price;
    gun.minlevel    = Minlevel;
    gun.groupID     = GUN_ITEM_TYPE;
    gun.chargeQ     = Charges;
    gun.chargespeed = ChargeSpeed;
    gun.dmg_min     = DmgMin;
    gun.dmg_max     = DmgMax;
    gun.accuracy    = Accuracy;
    gun.sound       = sound; //JRH
    gun.shottype    = shottype; //JRH
    gun.nation      = nation + "";
    gun.firstperiod = firstperiod;
    gun.lastperiod  = lastperiod;
    gunIndex++;
  }
  return gunIndex;
}
//-------------------------------------------------------------------------------------------------------------------------------
// Sulan: simplified and improved Weaponsmod code by scheffnow   <---
//-------------------------------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------------------------------
//  scheffnow - tailorsmod -->
// TIH fixed function to "int" ... was "bool" ???
int InitArmor( ref  ItemIndex,
      string  id,
      int  picTexture,
      int  picIndex,
      int  coverage,
      int  bladestop,
      int  bladefrac,
      int  gunstop,
      int  gunfrac,
      int  minlevel )
{
  ref armor;
  int armorIndex = ItemIndex;
  makeref(armor,Items[armorIndex]);
  armor.id      = id;
  armor.groupID   = ARMOR_ITEM_TYPE;
  armor.name      = "itmname_" + id;
  armor.describe    = "itmdescr_" + id;
  armor.model     = "";
  armor.folder    = "items";
  armor.picIndex    = picIndex;
  armor.picTexture  = "ITEMS_" + picTexture;
  armor.modelitem   = true; // NK 05-04-12 to distinguish from normal armor.

  armor.skiptrade   = true;
  armor.skiprand    = true;
  armor.skipequip   = true;
  armor.price     = 1;  // ccc jan06, price was 0 which made this a questitem which can't be transfered
  armor.minlevel    = minlevel;
  armor.rare      = 0.01;

  armor.armor     = 50;
  armor.coverage    = coverage;
  armor.bladestop   = bladestop;
  armor.bladefrac   = bladefrac;
  armor.gunstop   = gunstop;
  armor.gunfrac   = gunfrac;

  armorIndex++;
  return armorIndex;
}
//  scheffnow - tailorsmod <--
//-------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------
// TIH --> compact this file with function usage
int InitStdArmor( ref ItemIndex,
      string  id,
      int   picTexture,
      int   picIndex,
      float rare,
      int   minlevel,
      int   price,
      int   coverage,
      int   bladestop,
      int   bladefrac,
      int   gunstop,
      int   gunfrac,
      int   armorlevel,
      string  cmodel,
      int   quality)
{
  ref armor;
  int armorIndex = ItemIndex;
  makeref(armor,Items[armorIndex]);

  armor.id      = id;
  armor.groupID   = ARMOR_ITEM_TYPE;
  armor.name      = "itmname_" + id;
  armor.describe    = "itmdescr_" + id;
  armor.model     = "";
  armor.folder    = "items";
  armor.picIndex    = picIndex;
  armor.picTexture  = "ITEMS_" + picTexture;
  armor.cmodel    = cmodel;

  armor.skiptrade   = false;
  armor.skiprand    = false;
  armor.skipequip   = false;
  armor.quality   = quality;

  armor.price     = price;
  armor.minlevel    = minlevel;
  armor.rare      = rare;

  //GreatZen -->
  armor.coverage    = coverage;
  armor.bladestop   = bladestop;
  armor.bladefrac   = bladefrac;
  armor.gunstop   = gunstop;
  armor.gunfrac   = gunfrac;
  armor.armor     = armorlevel;
  // GreatZen <--

  if ( id == "cheaparmor" ) armor.skill.fencing = -1; // GreatZen
//if ( id == "commonarmor" ) armor.skill.fencing = -1; //BB added check for other armour types, armour does slow you down, you trade of for the protection.

  armorIndex++;
  return armorIndex;
}
// TIH <--
//-------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------
// TIH --> compact this file with function usage
int InitQuestItem(  ref ItemIndex, string id, string txtname, string model,
            int picTexture, int picIndex,
            int setshown, int shownval,
            string startLocation, string startLocator,
            string useLocation, string useLocator,
            string quest, string tex, string pic
          )
{
  ref qstitm;
  int qstitmIndex = ItemIndex;
  makeref(qstitm,Items[qstitmIndex]);

  qstitm.id       = id;
  qstitm.name     = "itmname_" + txtname;
  qstitm.describe   = "itmdescr_" + txtname;
  qstitm.picIndex   = picIndex;
  qstitm.picTexture   = "ITEMS_" + picTexture;
  qstitm.model    = model;
  qstitm.skiptrade  = true;
  qstitm.skiprand   = true;
  qstitm.skipequip  = true;
  qstitm.price    = 0;
  qstitm.groupID    = QUEST_ITEM_TYPE;//MAXIMUS
  switch(id)
  {
	case "skull_ring":			qstitm.groupID		= EQUIP_ITEM_TYPE;		  
		    	     							qstitm.skipequip = false;	break;
	case "Montejo_Book":							qstitm.skill.Sneak = +1;
		    	     							qstitm.skipequip = false;	break;
	case "moccasins":   			qstitm.groupID		= EQUIP_ITEM_TYPE;		  
		    	     							qstitm.skipequip = false;	break;
	case "mayan_compass":   		qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;	
	case "empty_pipe": 	    						qstitm.price = 1; 	  	break;
	case "filled_pipe": 			qstitm.groupID		= EQUIP_ITEM_TYPE;		  
		    	     							qstitm.skipequip = false;	break;
	case "dried_mushrooms": 		qstitm.groupID		= EXAMINE_ITEM_TYPE;
										qstitm.price = 1; 		break;	
	case "pulverized_mushrooms": 		qstitm.groupID		= EQUIP_ITEM_TYPE;		  
		            							qstitm.skipequip = false;		
										qstitm.price = 1;		break;
	case "crypto1":				qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;  // JRH: crypto start
	case "crypto2":				qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;  // JRH: crypto solved
	case "book52":				qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;  // JRH: book + freq. table
	case "book53":				qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;  // JRH: open book
	case "book54":				qstitm.groupID		= EQUIP_ITEM_TYPE;			break;  // JRH: freq. table
	case "wrinkled_paper":			qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;  // JRH: wrinkled paper
	case "bird_sketch_doc":			qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;  // JRH: sketch of a bird, now enabled to see backside
	case "BH_sketch_out":			qstitm.groupID		= EQUIP_ITEM_TYPE;			break;  // JRH: BH sketch, now enabled to roll
	case "rolled_paper":			qstitm.groupID		= EQUIP_ITEM_TYPE;			break;  // JRH: BH sketch rolled
	case "rolled_paper_gp":			qstitm.groupID		= EQUIP_ITEM_TYPE;			break;  // JRH: BH sketch rolled & filled with gp
	case "med_bag1_doc_NO":			qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;  // JRH: med bag
	case "med_bag1_doc_YES":		qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;  // JRH: med bag
	case "med_bag1_out":			qstitm.groupID		= EQUIP_ITEM_TYPE;			break;  // JRH: med bag
	case "med_bag2_doc":			qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;  // JRH: med bag + itms
	case "med_bag2_out":			qstitm.groupID		= EQUIP_ITEM_TYPE;			break;  // JRH: med bag + itms
	case "crypto_excel":			qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;  // JRH: crypto excel info
	case "detective_kit1":			qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;  // JRH
	case "detective_kit2":			qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;  // JRH
	case "detective_kit3":			qstitm.groupID		= EQUIP_ITEM_TYPE;			break;  // JRH
	case "detective_kit4":			qstitm.groupID		= EQUIP_ITEM_TYPE;			break;  // JRH
	case "detective_kit5":			qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;  // JRH
	case "doc1A":				qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;  // JRH closed note
	case "doc1B":				qstitm.groupID		= EQUIP_ITEM_TYPE;			break;  // JRH open note
	case "doc2A":				qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;  // JRH closed folder
	case "doc2B":				qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;  // JRH semi open folder
	case "doc2E":				qstitm.groupID		= EQUIP_ITEM_TYPE;			break;  // JRH left side: recipe gpF
	case "doc3C":				qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;  // JRH right side: recipe gpS
	case "doc3D":				qstitm.groupID		= EQUIP_ITEM_TYPE;			break;  // JRH right side: mix instr.
	case "doc4A":				qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;  // JRH closed burned book
	case "doc4B":				qstitm.groupID		= EQUIP_ITEM_TYPE;			break;  // JRH open burned book
	case "doc5A":				qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;  // JRH bottle
	case "doc5B":				qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;  // JRH closed scroll
	case "doc5C":				qstitm.groupID		= EQUIP_ITEM_TYPE;			break;  // JRH open scroll
	case "doc6A":				qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;  // JRH closed envelope
	case "doc6B":				qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;  // JRH open envelope
	case "doc6C":				qstitm.groupID		= EQUIP_ITEM_TYPE;			break;  // JRH yellow paper
	case "bagcompass4":			qstitm.groupID		= POUCH_ITEM_TYPE;			break;  // JRH Compass in a bag
	case "book55A":				qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;  // JRH Whaling
	case "book55B":				qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;  // JRH Whaling
	case "book55C":				qstitm.groupID		= EQUIP_ITEM_TYPE;			break;  // JRH Whaling
	case "book55D":				qstitm.groupID		= EQUIP_ITEM_TYPE;			break;  // JRH Whaling
	case "book61A":				qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;  // JRH
	case "book61B":				qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;  // JRH
	case "book61C1":			qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;  // JRH
	case "book61C2":			qstitm.groupID		= EQUIP_ITEM_TYPE;			break;  // JRH

	case "knitting_basket":			qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;
	case "knitting":			qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;
	case "needles":				qstitm.groupID		= EQUIP_ITEM_TYPE;			break;
	case "yarn":				qstitm.groupID		= EQUIP_ITEM_TYPE;			break;
	case "pliers":				qstitm.groupID		= EQUIP_ITEM_TYPE;			break;
	case "magnet":				qstitm.groupID		= EQUIP_ITEM_TYPE;			break;
	case "poe_manuscript":			qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;
	case "doc60A":				qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;  // JRH WR closed envelope
	case "doc60B":				qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;  // JRH WR open envelope
	case "doc60C":				qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;  // JRH WR letter front side
        case "doc60D":				qstitm.groupID		= EQUIP_ITEM_TYPE;   qstitm.price = 1;	break;  // JRH WR letter back side
	case "book69A":				qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;  // JRH Teach's logbook
	case "book69B":				qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;  // JRH Teach's logbook
	case "book69C":				qstitm.groupID		= EQUIP_ITEM_TYPE;   qstitm.price = 1;	break;  // JRH Teach's logbook
	case "BB_hatA1":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;  // JRH Teach's hat
	case "BB_hatB":				qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;  // JRH Teach's hat
	case "BB_hatC":				qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;  // JRH Teach's hat
	case "BB_key":									     qstitm.price = 1;	break;  // JRH Teach's hat
	case "BB_hatA2":			qstitm.groupID		= EQUIP3_ITEM_TYPE;  qstitm.price = 1;
										qstitm.skill.leadership = +1;	break;  // JRH Teach's hat
	case "BB_coin":				qstitm.groupID		= EQUIP2_ITEM_TYPE;
										qstitm.skill.sneak= +1;		break;  // JRH Teach's amulet
	case "paper_clip":			qstitm.groupID		= EQUIP_ITEM_TYPE;			break;  // JRH
	case "auction_list_roll":		qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;  // JRH
	case "auction_list_open":		qstitm.groupID		= EXAMINE_ITEM_TYPE;			break;  // JRH
	case "tailors_book":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;  // JRH
	case "tailors_note":			qstitm.groupID		= EQUIP_ITEM_TYPE;   qstitm.price = 1;	break;  // JRH

	case "book70_start":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;  // JRH burned alchemy book
	case "book70":				qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;  // JRH burned alchemy book
	case "book70_0":			qstitm.groupID		= EQUIP_ITEM_TYPE;   qstitm.price = 1;	break;
	case "book70_1":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book70_2":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book70_3":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book70_4":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book70_5":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book70_6":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book70_7":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book70_8":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book70_9":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book70_10":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book70_11":			qstitm.groupID		= EQUIP_ITEM_TYPE;   qstitm.price = 1;	break;

	case "book71_9_start":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;  // JRH ripped alchemy book
	case "book71_9":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;  // JRH ripped alchemy book
	case "book71_10":			qstitm.groupID		= EQUIP_ITEM_TYPE;   qstitm.price = 1;	break;
	case "book71_11":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book71_12":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book71_13":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book71_14":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book71_15":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book71_16":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book71_17":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book71_18":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book71_19":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book71_20":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book71_21":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book71_22":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book71_23":			qstitm.groupID		= EQUIP_ITEM_TYPE;   qstitm.price = 1;	break;

	case "book72_package":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book72_closed":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book72_openL":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book72_openR":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book72_edenL":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book72_edenR":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book72_caesarL":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book72_caesarR":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book72_handsL":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book72_handsR":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book72_richardsL":		qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book72_richardsR":		qstitm.groupID		= EQUIP_ITEM_TYPE;   qstitm.price = 1;	break;

	case "newspaper1":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "newspaper2":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "newspaper3":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "bandages_trousersX":		qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "bandages_trousersQ":		qstitm.groupID		= EQUIP_ITEM_TYPE;   qstitm.price = 1;	break;
	case "shirt_shoes":			qstitm.groupID		= EQUIP_ITEM_TYPE;   qstitm.price = 1;	break;
	case "socks_sewing":			qstitm.groupID		= EQUIP_ITEM_TYPE;   qstitm.price = 1;	break;
	case "waistcoat":			qstitm.groupID		= EQUIP_ITEM_TYPE;   qstitm.price = 1;	break;
	case "sash":				qstitm.groupID		= EQUIP_ITEM_TYPE;   qstitm.price = 1;	break;

	case "package":				qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "notebook":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "sealed_map":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "red_uniform":			qstitm.groupID		= EQUIP_ITEM_TYPE;   qstitm.price = 1;	break;

	case "book73_closed":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "book73_open":			qstitm.groupID		= EQUIP_ITEM_TYPE;   qstitm.price = 1;	break;
	
	case "megaphone":								     qstitm.price = 1;	break;
	case "boathook":								     qstitm.price = 1;	break;
	case "spyglass5":								     qstitm.price = 1;	break;
	case "long_johns":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "long_johns_map":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "bandana":				qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "bandana_key":			qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
    	case "MariasLetter":	qstitm.groupID = BOOK_ITEM_TYPE;	qstitm.QuestName = "hornblower_read_marias_letter";	qstitm.text = "MariasLetter";	break;  // GR: Letter from Maria from shortly before she died: Hornblower storyline
	
	case "port_stock":			qstitm.groupID		= EQUIP_ITEM_TYPE;   qstitm.price = 1;	break;
	case "port_metal":			qstitm.groupID		= EQUIP_ITEM_TYPE;   qstitm.price = 1;	break;
	case "port_rest":			qstitm.groupID		= EQUIP_ITEM_TYPE;   qstitm.price = 1;	break;
	case "port_magazine":			qstitm.groupID		= EQUIP_ITEM_TYPE;   qstitm.price = 1;	break;
	case "port_barrel":			qstitm.groupID		= EQUIP_ITEM_TYPE;   qstitm.price = 1;	break;
	case "port_mechanism":			qstitm.groupID		= EQUIP_ITEM_TYPE;   qstitm.price = 1;	break;
	case "port_2":				   					     qstitm.price = 1;	break;
	case "port_3":				  					     qstitm.price = 1;	break;
	case "port_4":				   					     qstitm.price = 1;	break;
	case "port_5":				   					     qstitm.price = 1;	break;
	case "engineer_letter1":		qstitm.groupID		= EXAMINE_ITEM_TYPE; 			break;
	case "engineer_letter2":		qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
	case "engineer_letter3":		qstitm.groupID		= EXAMINE_ITEM_TYPE; qstitm.price = 1;	break;
  }
  if ( setshown == 1 ) qstitm.shown = shownval;

  if ( startLocation != "" )  qstitm.startLocation  = startLocation;
  if ( startLocator != "" )   qstitm.startLocator   = startLocator;
  if ( useLocation != "" )  qstitm.useLocation    = useLocation;
  if ( useLocator != "" )   qstitm.useLocator     = useLocator;

  if ( quest != "" )  qstitm.quest    = quest;
  if ( tex != "" )  qstitm.quest.tex  = tex;
  if ( pic != "" )  qstitm.quest.pic  = pic;

  qstitmIndex++;
  return qstitmIndex;
}
// TIH <--
//-------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------
// TIH --> compact this file with function usage
int InitSpyglass(
      ref   ItemIndex,
      string  id,
      string  model,
      int   picTexture,
      int   picIndex,
      float rare,
      int   minlevel,
      float price,
      string  texture,

      float zoom,
      int   time_activate,
      int   time_update,
      int   nation,
      int   ship_name,
      int   ship_type,
      int   cannons,
      int   hull,
      int   sail,
      int   crew,
      int   speed,
      int   charge,
	  int   morale,

      int quality, int skipsell, int skiprand, int skipequip
      )
{
  ref spyitm;
  int spyIndex = ItemIndex;
  makeref(spyitm,Items[spyIndex]);

  spyitm.id       = id;
  spyitm.name     = "itmname_" + id;
  spyitm.describe   = "itmdescr_" + id;
  spyitm.model    = model;
  spyitm.picIndex   = picIndex;
  spyitm.picTexture   = "ITEMS_" + picTexture;
  spyitm.folder     = "items";
  spyitm.groupID    = SPYGLASS_ITEM_TYPE;

  spyitm.price  = price;
  spyitm.minlevel = minlevel;
  spyitm.rare   = rare;

  spyitm.skiptrade = false;
  spyitm.skipsell  = skipsell;
  spyitm.skiprand  = skiprand;
  spyitm.skipequip = skipequip;
  spyitm.quality   = quality;

  spyitm.scope.texture    = texture;
  spyitm.scope.zoom       = zoom;
  spyitm.scope.time_activate  = time_activate;
  spyitm.scope.time_update  = time_update;
  spyitm.scope.show.nation  = nation;
  spyitm.scope.show.cannons   = cannons;
  spyitm.scope.show.ship_name = ship_name;
  spyitm.scope.show.ship_type = ship_type;
  spyitm.scope.show.hull    = hull;
  spyitm.scope.show.sail    = sail;
  spyitm.scope.show.crew    = crew;
  spyitm.scope.show.speed   = speed;
  spyitm.scope.show.charge  = charge;
  spyitm.scope.show.morale  = morale;

  spyIndex++;
  return spyIndex;
}
// TIH <--
//-------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------
// TIH --> compact this file with function usage
int InitPotion(
      ref   ItemIndex,
      string  id,
      string  model,
      int   picTexture,
      int   picIndex,
      float rare,
      int   minlevel,
      float price,

      float numrand,
      int   pic,
      int   tex,
      bool  antidote,
      float health,
      int   quality,

      int skipsell, int skiprand, int skipequip
      )
{
  ref potionitm;
  int potionIndex = ItemIndex;
  makeref(potionitm,Items[potionIndex]);

  potionitm.id      = id;
  potionitm.name      = "itmname_" + id;
  potionitm.describe    = "itmdescr_" + id;
  potionitm.model     = model;
  potionitm.picIndex    = picIndex;
  potionitm.picTexture  = "ITEMS_" + picTexture;
  potionitm.groupID     = POTION_ITEM_TYPE;//MAXIMUS

  potionitm.numrand   = RANDITEMS_MAXCHANCE * numrand; // 05-07-22
  potionitm.skiptrade = false;
  potionitm.skipsell  = skipsell;
  potionitm.skiprand  = skiprand;
  potionitm.skipequip = skipequip;
  potionitm.quality   = quality;

//  potionitm.shown     = false;
  potionitm.price     = price;
  potionitm.potion.pic  = pic;
  potionitm.potion.tex  = tex;
  if ( health > 0 )     potionitm.potion.health = health;
  if ( antidote )     potionitm.potion.antidote = true;
  potionitm.minlevel    = minlevel;
  potionitm.rare      = rare;

//JRH -->
  potionitm.potion.sound = "INTERFACE\drink.wav";
  switch(id)
  {
	case "medical1":   potionitm.potion.sound = "PEOPLE\clothes2.wav";  break; 	
 	case "medical2":   potionitm.potion.sound = "INTERFACE\cauterization.wav"; break; 
    	case "sewing_kit": potionitm.potion.sound = "INTERFACE\sewing.wav";  break; 	
 	case "tobacco":    potionitm.potion.sound = "INTERFACE\chewing.wav";  break; 
	case "herbs":      potionitm.potion.sound = "INTERFACE\chewing.wav";  break; 
	case "myrrh":      potionitm.potion.sound = "INTERFACE\chewing.wav";  break; 		
  }
//<-- JRH
  potionIndex++;
  return potionIndex;
}
// TIH <--
//-------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------
// TIH --> compact this file with function usage
int InitItem( ref   ItemIndex,
              string  id,
              string  model,
              string  picTexture,
              int   picIndex,
              float rare,
              int   minlevel,
              float price,
              int   indiantype,
              int numneeded, int stack, int hidden,
              int leadership, int fencing, int sailing, int accuracy, int cannons,
              int grappling, int repair, int defence, int commerce, int sneak,
              int skiptrade, int skiprand, int skipequip, int skipsell
          )
{
  ref genitm;
  int genitmIndex = ItemIndex;
  makeref(genitm,Items[genitmIndex]);
  genitm.id         = id;
  genitm.name       = "itmname_" + id;
  genitm.describe   = "itmdescr_" + id;
  genitm.model      = model;
  genitm.picTexture = "ITEMS_" + picTexture;
  genitm.picIndex   = picIndex;

  // GreatZen -->
  						genitm.skill.num    = 1;		//MAXIMUS
  if ( numneeded > 1 )	genitm.skill.num    = numneeded;
						genitm.skill.stack  = false;	//JRH
  if ( stack >= 1 )		genitm.skill.stack  = true;		//JRH
  						genitm.skill.hidden = false;	//MAXIMUS
  if ( hidden == 1 )	genitm.skill.hidden = true;

  bool SkillBonus = true;
  if (HasSubStr(id, "jewel") || HasSubStr(id, "indian") || HasSubStr(id, "mineral") || id == "chinatiger")
  {
    SkillBonus = iRealismMode<2 && !ITEM_REALISM;			// BB&Sulan: no bonuses - for those who like more realism, to whom a ruby does not grant any fencing skills
    if(iRealismMode>0)		genitm.skill.hidden     = true;	// PB: You do get the bonus on Realistic Game Mode, but you don't get to see it
  }
  if(SkillBonus)
  {
    if ( leadership != 0 )  genitm.skill.leadership = leadership;
    if ( fencing    != 0 )  genitm.skill.fencing    = fencing;
    if ( sailing    != 0 )  genitm.skill.sailing    = sailing;
    if ( accuracy   != 0 )  genitm.skill.accuracy   = accuracy;
    if ( cannons    != 0 )  genitm.skill.cannons    = cannons;
    if ( grappling  != 0 )  genitm.skill.grappling  = grappling;
    if ( repair     != 0 )  genitm.skill.repair     = repair;
    if ( defence    != 0 )  genitm.skill.defence    = defence;
    if ( commerce   != 0 )  genitm.skill.commerce   = commerce;
    if ( sneak      != 0 )  genitm.skill.sneak      = sneak;
  }
  // GreatZen <--

  genitm.skiptrade = skiptrade;
  genitm.skiprand  = skiprand;
  genitm.skipequip = skipequip;
  genitm.skipsell  = skipsell;

  genitm.types.indian = false;//MAXIMUS
  if ( indiantype == 1 )  genitm.types.indian = true;

  genitm.groupID = OBJECT_ITEM_TYPE; // KK
  switch(id)
  {
    case "lockpick": genitm.groupID = LOCKPICK_ITEM_TYPE;		  // PB: Lockpick
					 genitm.sneaky = true;				  break;  // PB: Sneaky Trader
    case "Santos_Journal1": genitm.sneaky = true;		  break;  // PB: Sneaky Trader
    case "Santos_Journal2": genitm.sneaky = true;		  break;  // PB: Sneaky Trader
    case "compass1": genitm.groupID = COMPASS_ITEM_TYPE;  break;  // PB: Compass
    case "compass2": genitm.groupID = COMPASS_ITEM_TYPE;  break;  // PB: Compass
    case "compass3": genitm.groupID = COMPASS_ITEM_TYPE;  break;  // KK: Compass
    case "clock1"  : genitm.groupID = CLOCK_ITEM_TYPE;    break;  // PB: Clock
    case "clock2"  : genitm.groupID = CLOCK_ITEM_TYPE;    break;  // PB: Clock
	case "bladekit": genitm.groupID = IT_TYPE_BLACKSMITH; break;  // PB: Blade Care Kit
    case "book1"   : genitm.groupID = DOCUMENT_ITEM_TYPE; break;  // Black Bart's Bumper Book of Boarding
    case "book2"   : genitm.groupID = BOOK_ITEM_TYPE;     genitm.text = "book2"; break;  // Boelen Algebra
    case "book3"   : genitm.groupID = DOCUMENT_ITEM_TYPE; break;  // Drow's Double Your Dubloons
    case "book4"   : genitm.groupID = DOCUMENT_ITEM_TYPE; break;  // Hook's Book
    case "book5"   : genitm.groupID = DOCUMENT_ITEM_TYPE; break;  // Morgan's Missing Mizzen
    case "book6"   : genitm.groupID = DOCUMENT_ITEM_TYPE; break;  // Morgan's Mast Mashing
    case "book7"   : genitm.groupID = DOCUMENT_ITEM_TYPE; break;  // Morgan's Almanac
    case "book8"   : genitm.groupID = DOCUMENT_ITEM_TYPE; break;  // Pirating With Petros
    case "book9":						  // Cooking With Albatross - PB: Clue about "Dead Albatross" effect
	genitm.groupID = BOOK_ITEM_TYPE;
	if (GetCurrentPeriod() == PERIOD_EARLY_EXPLORERS) genitm.text = "cookbook_early";
	else genitm.text = "cookbook";
    break;
    case "book10"  : genitm.groupID = DOCUMENT_ITEM_TYPE; break;  // Definitive Defence
    case "book11"  : genitm.groupID = DOCUMENT_ITEM_TYPE; break;  // Fighting Forts
    case "book12"  : genitm.groupID = DOCUMENT_ITEM_TYPE; break;  // Great Gun Sights
    case "book13"  : genitm.groupID = DOCUMENT_ITEM_TYPE; break;  // Handy Sea Phrases
    case "book14"  : genitm.groupID = DOCUMENT_ITEM_TYPE; break;  // How to Repel Boarders
    case "book15"  : genitm.groupID = DOCUMENT_ITEM_TYPE; break;  // Ship Repair Without Nails
//	case "notebook": genitm.groupID = DOCUMENT_ITEM_TYPE; break;  // JRH: notebook
    case "red_uniform": genitm.groupID = OUTFIT_ITEM_TYPE;break;  // JRH: red uniform
	case "smugglingbook": 	genitm.groupID = BOOK_ITEM_TYPE;      genitm.QuestName = "Read_Smuggling_Book";		genitm.text = "smugglingbook"; 				break; // Smuggling tutorial book
//	case "smugglingbook2": 	genitm.groupID = BOOK_ITEM_TYPE;      genitm.text = "smugglingbook2"; 				break; // Smuggling opium tutorial 
	case "opiumlist": 	genitm.groupID = BOOK_ITEM_TYPE;      genitm.text = "opiumlist"; 				break; // Smuggling opium tutorial book
	case "relationbook":  	genitm.groupID = BOOK_ITEM_TYPE;      genitm.QuestName = "Read_Relation_Book";		genitm.text = "relationbook"; 			break; // Nation relations tutorial book
	case "piratebook":  	genitm.groupID = BOOK_ITEM_TYPE;      genitm.QuestName = "Read_Pirate_Book";		genitm.text = "piratebook"; genitm.sneaky = true;	break; // Pirate tutorial book
	case "book_exorcist": 	genitm.groupID = BOOK_ITEM_TYPE;      genitm.QuestName = "Telescope_Found_Book";	genitm.text = "book_exorcist";			break; // Levis: For telescope unlocking
	case "skillbook1":    	genitm.groupID = BOOK_ITEM_TYPE;      genitm.UnlockedPerk = "AdvancedDefence";		genitm.text = "skillbook1";				break; // Levis
	case "skillbook2":    	genitm.groupID = DOCUMENT_ITEM_TYPE;  genitm.UnlockedPerk = "GunProfessional";		break; // Levis Skillbook 2
	case "skillbook3":    	genitm.groupID = BOOK_ITEM_TYPE;      genitm.UnlockedPerk = "AdvancedDamageControl";	genitm.text = "skillbook3";				break; // Levis
	case "skillbook4":    	genitm.groupID = DOCUMENT_ITEM_TYPE;  genitm.UnlockedPerk = "CannonProfessional";	break; // Levis Skillbook 4
	case "indian_treasure_note": genitm.groupID = BOOK_ITEM_TYPE; genitm.QuestName = "Found Treasure Note"; 	genitm.text = "indian_treasure_note";	break; //Levis: Indian Treasure

	case "luckydimeA":	genitm.groupID = FLIP_ITEM_TYPE;      genitm.skill.Sneak = +2;				genitm.skill.hidden = true;	break;	//JRH easter-egg
	case "luckydimeB":	genitm.groupID = FLIP_ITEM_TYPE;      genitm.skill.Sneak = +2;				genitm.skill.hidden = true;  	break;	//JRH easter-egg
  }

  //genitm.shown    = false;
  genitm.price      = price;
  genitm.minlevel   = minlevel;
  genitm.rare       = rare;

  genitmIndex++;
  return genitmIndex;
}
// TIH <--
//-------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------
// TIH --> compact this file with function usage
int InitPickUpItem( ref ItemIndex, string id, string model, float rare, int gold, float numrand )
{
  ref itm;
  int itmIndex = ItemIndex;
  makeref(itm,Items[itmIndex]);

  itm.id      = id;
  itm.name    = "itmname_" + id;
  itm.model     = model;

  itm.skiptrade   = true;
  itm.skiprand  = false;
  itm.skipequip   = true;
  itm.numrand   = numrand;
  itm.groupID = OBJECT_ITEM_TYPE; // KK


//  itm.shown     = false;
  itm.minlevel  = 0;
  itm.rare    = rare;
  itm.gold    = gold;

  // PB: Add picture -->
  itm.picIndex  = 2;
  itm.picTexture  = "ITEMS_4";
  // PB: Add picture <--

  itmIndex++;
  return itmIndex;
}
// TIH <--
//-------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------
// TIH --> compact this file with function usage
int InitApothItem(  ref ItemIndex, string id, string model, string picTexture, int picIndex,
          float rare, int minlevel, float price,
          bool potiontype, int pic, int tex, bool antidote, float health,
          int skiptrade, int skiprand, int skipequip
        )
{
  ref itm;
  int itmIndex = ItemIndex;
  makeref(itm,Items[itmIndex]);

  itm.id      = id;
  itm.name    = "itmname_" + id;
  itm.describe  = "itmdescr_" + id;
  itm.model     = model;
  itm.picIndex  = picIndex;
  itm.picTexture  = "ITEMS_" + picTexture;
  itm.groupID = POTION_ITEM_TYPE; // KK

  itm.skipsell    = true;
  itm.skiptrade   = skiptrade;
  itm.skiprand    = skiprand;
  itm.skipequip   = skipequip;

//  itm.shown     = false;
  itm.rare    = rare;
  itm.minlevel  = minlevel;
  itm.price     = price;

  if ( potiontype ) {
    itm.skiptrade  = false;
    itm.potion.pic = pic;
    itm.potion.tex = tex;
    if ( antidote )   itm.potion.antidote = true;
    if ( health != 0 )  itm.potion.health = health;
  }

  itmIndex++;
  return itmIndex;
}
// TIH <--
//-------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------
// TIH --> compact this file with function usage
int InitAmmoMod(  ref ItemIndex, string id, string groupID, string  picTexture, int picIndex, float rare,
          int minlevel, int price,
          int skiptrade, int skiprand, int skipequip
        )
{
  ref ammoitm;
  int ammoitmIndex = ItemIndex;
  makeref(ammoitm,Items[ammoitmIndex]);

  ammoitm.id      = id;
  ammoitm.name    = "itmname_" + id;
  ammoitm.describe  = "itmdescr_" + id;
  ammoitm.model     = "";
  ammoitm.picTexture = "ITEMS_" + picTexture;
  ammoitm.picIndex  = picIndex;
  ammoitm.rare      = rare;

  ammoitm.skiptrade   = skiptrade;
  ammoitm.skiprand  = skiprand;
  ammoitm.skipequip   = skipequip;
  if ( groupID != "" ) ammoitm.groupID = groupID;
//  ammoitm.shown     = false;
  ammoitm.price     = price;
  ammoitm.minlevel  = minlevel;
//  ammoitm.rare    = 0.1;		//this must be wrong JRH

  ammoitmIndex++;
  return ammoitmIndex;
}
// TIH <--
//-------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------
// TIH --> compact this file with function usage
int InitBLDexterior(  ref ItemIndex, string id, string model,
            string chrmodel, string dialog, int planks, int money, int crew,
            float dmg_min, float dmg_max, int piercing, int block
          )
{
  ref bld;
  int bldIndex = ItemIndex;
  makeref(bld,Items[bldIndex]);

  bld.id      = id;
  bld.groupID   = BLADE_ITEM_TYPE;
  bld.name    = "itmname_building";
  bld.describe  = "itmdescr_building";
  bld.picIndex  = 13;
  bld.picTexture  = "ITEMS_4";
  bld.folder    = "ammo";
  bld.model     = "BuildingSet\"+model; // PB: Clean up "AMMO" subfolder
  bld.building.chrmodel   = chrmodel;
  bld.building.dialog   = dialog;
  bld.building.planks   = planks;
  bld.building.money    = money;
  bld.building.crew     = crew;
  bld.dmg_min   = dmg_min;
  bld.dmg_max   = dmg_max;
  bld.piercing  = piercing;
  bld.block     = block;

  bldIndex++;
  return bldIndex;
}
// TIH <--
//-------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------
// TIH --> compact this file with function usage
int InitBLDinterior(  ref ItemIndex, string id, string model,
            int planks, int money, int crew,
            int chargeQ, int chargespeed, float dmg_min, float dmg_max, int accuracy
          )
{
  ref bld;
  int bldIndex = ItemIndex;
  makeref(bld,Items[bldIndex]);

  bld.id      = id;
  bld.groupID   = GUN_ITEM_TYPE;
  bld.name    = "itmname_building";
  bld.describe  = "itmdescr_building";
  bld.picIndex  = 13;
  bld.picTexture  = "ITEMS_4";
  bld.folder    = "ammo";
  bld.model     = "BuildingSet\"+model; // PB: Clean up "AMMO" subfolder
  bld.building.planks = planks;
  bld.building.money  = money;
  bld.building.crew   = crew;
  bld.chargeQ   = chargeQ;
  bld.chargespeed = chargespeed;
  bld.dmg_min   = dmg_min;
  bld.dmg_max   = dmg_max;
  bld.accuracy  = accuracy;

  bldIndex++;
  return bldIndex;
}
// TIH <--
//-------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------
// JRH -->
int InitQuestBlade( 	ref	ItemIndex,
			string	id,
			string	ModelID,
			string  picTexture,
			int	picIndex,
			float	DmgMin,
			float	DmgMax,
			int	Piercing,
			int	Blocking,
			string	nation,
			float	Disarm,
			int   price)
{
	ref		blade;
	int		BladeIndex = ItemIndex;
	string	typetemp; // NK 05-04-06
	nation += ""; // NK 05-04-14 for some reason we have to do this.
	makeref(blade,Items[BladeIndex]);

	blade.id		= id;
	blade.groupID		= BLADE_ITEM_TYPE;
	blade.name		= "itmname_" + id;
	blade.describe		= "itmdescr_" + id;
	blade.folder 		= "ammo";
	blade.model		= "OtherItemsJRH\"+ModelID;
	blade.picTexture	= "ITEMS_" + picTexture;
	blade.picIndex		= picIndex;

	blade.param.time	= 0.1;
	blade.param.colorstart	= argb(64, 64, 64, 64);
	blade.param.colorend	= argb(0, 32, 32, 32);

	blade.skipequip		= true;
	blade.skiptrade		= true;
	blade.skiprand		= true;
	blade.skipsell		= true;

	blade.rare		= 0.00;
	blade.minlevel		= 1;
	blade.price		= price;

	blade.dmg_min		= DmgMin;
	blade.dmg_max		= DmgMax;
	blade.piercing		= Piercing;
	blade.block		= Blocking;

	// PB: Disarm mode toggles -->
	if (DISARM_MODE == 2) 	{ blade.disarm = 100;	}			// Testmode
	else 					{ blade.disarm = Disarm; }	// Default
	// PB: Disarm mode toggles <--

	switch(id)
  	{
		case "bladeflint":	blade.fist = true;			break; //JRH
		case "bladeplank2":	blade.sound = "OBJECTS\DUEL\plank.wav";	break; //JRH
		case "bladespade":	blade.sound = "PEOPLE\spade.wav";	break; //JRH
		case "bladetrophy":	blade.sound = "INTERFACE\wheel_place.wav"; break; //JRH
	}

	BladeIndex++;
	return BladeIndex;
}
//<-- JRH
//-------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------
//JRH -->
int InitQuestGun(	ref	ItemIndex,
			string	id,
			string	model,
			string	picTexture,
			int	picIndex,
			float	dmg_min,
			float	dmg_max,
			int	accuracy,
			int	chargeQ,
			int	chargespeed,
			int	change,
			string	nation,
			string	sound,
			string	shottype,
			int   price)
{
	ref	gun;
	int	gunIndex = ItemIndex;
	string	typetemp; // NK 05-04-06
	nation += ""; // NK 05-04-14 for some reason we have to do this.

	makeref(gun,Items[gunIndex]);

	gun.id 		= id;
	gun.name 	= "itmname_" + id;
	gun.describe 	= "itmdescr_" + id;
	gun.folder 	= "ammo";
	gun.model 	= "OtherItemsJRH\"+model;
	gun.picIndex 	= picIndex;
	gun.picTexture 	= "ITEMS_" + picTexture;

	gun.skiptrade 	= true;
	gun.skiprand 	= true;
	gun.skipequip 	= true;
	gun.skipsell	= true;

	gun.price 	= price;
	gun.minlevel 	= 1;			//check
	gun.rare 	= 0.00;

	gun.groupID 	= GUN_ITEM_TYPE;
	gun.chargeQ 	= chargeQ;
	gun.chargespeed = chargespeed;
	gun.change	= change;
	gun.dmg_min 	= dmg_min;
	gun.dmg_max 	= dmg_max;
	gun.accuracy 	= accuracy;
	gun.sound 	= sound;
	gun.shottype 	= shottype;

	switch(id)
  	{
		case "pistolsteel":      gun.enblrld = true;   		break; //JRH
		case "pistolbladeBB":    gun.enblrld = true;   		break; //JRH
	}

	gunIndex++;
	return gunIndex;
}
//<-- JRH
//-------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------
//JRH -->
int InitBuildingItemJRH(ref ItemIndex, string id, string model)
{
	ref	bld;
	int	bldIndex = ItemIndex;
	makeref(bld,Items[bldIndex]);

	bld.id 		= id;
	bld.name 	= "itmname_" + id;
	bld.folder 	= "ammo";
	bld.model 	= "BuildingItemsJRH\"+model;

	bldIndex++;
	return bldIndex
}
//<-- JRH
//-------------------------------------------------------------------------------------------------------------------------------

// KK -->
int InitMap(int n, ref map)
{
	ref refMap;

	if (!CheckAttribute(map, "id")) return n;
	if (!FindFile("RESOURCE\Textures\INTERFACES\Maps", "*.tga.tx", map.id + ".tga.tx")) return n;

	makeref(refMap, Items[n]);
	DeleteAttribute(refMap, "");
	CopyAttributes(refMap, map);
	refMap.index = n;
	//refMap.picTexture = "items_maps";	//JRH
	refMap.numrand = 0;
	refMap.quality = -2;   // PB: If -2, attribute is removed and item should be ALWAYS available
	refMap.rare    = 0.01; // PB: Low value so each trader has only VERY few of them
	refMap.skipequip = true;
	refMap.skiptype = true;
	if (!CheckAttribute(map, "skiptrade")) {
	refMap.skiptrade = false;
	refMap.skipgeneral = false;
	}
	if (!CheckAttribute(map, "skipsell")) refMap.skipsell = false;
	refMap.groupID = MAP_ITEM_TYPE;
	n++;

	DeleteAttribute(map, "");

	return n;
}

int InitMaps(int n)
{
	object Map;
	ref curMap; makeref(curMap, Map); aref labels;

	curMap.id = "map";
	curMap.name = "itmname_map";
	curMap.describe = "itmdescr_map";
	curMap.island = "Archipelago";
	curMap.location = TranslateString("", "Archipelago");
	curMap.picIndex = 1;
	curMap.picTexture = "items_maps";	//JRH
	curMap.price = 2000;
	curMap.skiptrade = true;
	curMap.skipsell = true;

	curMap.labels = "";
	makearef(labels, curMap.labels);
	n = InitMap(n, curMap);

	curMap.id = "mapKhaelRoa";
	curMap.name = "itmname_mapIsland";
	curMap.describe = "itmdescr_mapIsland";
	curMap.island = "KhaelRoa";
	curMap.location = FindIslandName("Khael Roa");
	curMap.picIndex = 2;
	curMap.picTexture = "items_maps";	//JRH
	curMap.price = 1000;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	labels.temple.label = TranslateString("", "Incas Temple");
	labels.temple.pos.x = 140;
	labels.temple.pos.y = 150;
	n = InitMap(n, curMap);

	curMap.id = "mapAntigua";
	curMap.name = "itmname_mapIsland";
	curMap.describe = "itmdescr_mapIsland";
	curMap.island = "Antigua";
	curMap.location = FindIslandName("Antigua");
	curMap.picIndex = 29;
	curMap.picTexture = "items_maps";	//JRH
	curMap.price = 1000;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	labels.StJohns.label = FindTownName("St John's");
	//labels.StJohns.ShowTownNation = "St John's";
	labels.StJohns.pos.x = 232;
	labels.StJohns.pos.y = 255;
	n = InitMap(n, curMap);

	curMap.id = "mapCayman";
	curMap.name = "itmname_mapIsland";
	curMap.describe = "itmdescr_mapIsland";
	curMap.island = "Cayman";
	curMap.location = FindIslandName("Cayman");
	curMap.picIndex = 6;
	curMap.picTexture = "items_maps";	//JRH
	curMap.price = 1000;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	labels.Cayman.label = FindTownName("Grand Cayman");
	labels.Cayman.pos.x = 315;
	labels.Cayman.pos.y = 290;
	n = InitMap(n, curMap);

	curMap.id = "mapConceicao";
	curMap.name = "itmname_mapIsland";
	curMap.describe = "itmdescr_mapIsland";
	curMap.island = "Conceicao";
	curMap.location = FindIslandName("Conceicao");
	curMap.picIndex = 8;
	curMap.picTexture = "items_maps";	//JRH
	curMap.price = 1000;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	labels.Conceicao.label = FindTownName("Conceicao");
	labels.Conceicao.pos.x = 245;
	labels.Conceicao.pos.y = 215;
	n = InitMap(n, curMap);

	curMap.id = "mapCuba";
	curMap.name = "itmname_mapIsland";
	curMap.describe = "itmdescr_mapIsland";
	curMap.island = "Cuba";
	curMap.location = FindIslandName("Cuba");
	curMap.picIndex = 21;
	curMap.picTexture = "items_maps";	//JRH
	curMap.price = 1000;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	labels.Havana.label = FindTownName("Havana");
	labels.Havana.pos.x = 88;
	labels.Havana.pos.y = 145;
	labels.Santiago.label = FindTownName("Santiago");
	labels.Santiago.pos.x = 330;
	labels.Santiago.pos.y = 323;
	n = InitMap(n, curMap);

	curMap.id = "mapDouwesen";
	curMap.name = "itmname_mapIsland";
	curMap.describe = "itmdescr_mapIsland";
	curMap.island = "Douwesen";
	curMap.location = FindIslandName("Douwesen");
	curMap.picIndex = 13;
	curMap.picTexture = "items_maps";	//JRH
	curMap.price = 1000;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	labels.Douwesen.label = FindTownName("Douwesen");
	labels.Douwesen.pos.x = 290;
	labels.Douwesen.pos.y = 250;
	n = InitMap(n, curMap);

	curMap.id = "mapFalaiseDeFleur";
	curMap.name = "itmname_mapIsland";
	curMap.describe = "itmdescr_mapIsland";
	curMap.island = "FalaiseDeFleur";
	curMap.location = FindIslandName("Falaise de Fleur");
	curMap.picIndex = 14;
	curMap.picTexture = "items_maps";	//JRH
	curMap.price = 1000;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	labels.FalaiseDeFleur.label = FindTownName("Falaise de Fleur");
	labels.FalaiseDeFleur.pos.x = 213;
	labels.FalaiseDeFleur.pos.y = 265;
	n = InitMap(n, curMap);

	curMap.id = "mapGuadeloupe";
	curMap.name = "itmname_mapIsland";
	curMap.describe = "itmdescr_mapIsland";
	curMap.island = "Guadeloupe";
	curMap.location = FindIslandName("Guadeloupe");
	curMap.picIndex = 24;
	curMap.picTexture = "items_maps";	//JRH
	curMap.price = 1000;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	labels.PointeaPitre.label = FindTownName("Pointe a Pitre");
	labels.PointeaPitre.pos.x = 260;
	labels.PointeaPitre.pos.y = 233;
	n = InitMap(n, curMap);

	curMap.id = "mapHispaniola";
	curMap.name = "itmname_mapIsland";
	curMap.describe = "itmdescr_mapIsland";
	curMap.island = "Hispaniola";
	curMap.location = FindIslandName("Hispaniola");
	curMap.picIndex = 22;
	curMap.picTexture = "items_maps";	//JRH
	curMap.price = 1000;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	labels.portauprince.label = FindTownName("Port au Prince");
	labels.portauprince.pos.x = 165;
	labels.portauprince.pos.y = 268;
	labels.tortuga.label = FindTownName("tortuga");
	labels.tortuga.pos.x = 172;
	labels.tortuga.pos.y = 106;
	labels.santodomingo.label = FindTownName("santo domingo");
	labels.santodomingo.pos.x = 288;
	labels.santodomingo.pos.y = 370;
	n = InitMap(n, curMap);

	curMap.id = "mapIslaMuelle";
	curMap.name = "itmname_mapIsland";
	curMap.describe = "itmdescr_mapIsland";
	curMap.island = "IslaMuelle";
	curMap.location = FindIslandName("Isla Muelle");
	curMap.picIndex = 16;
	curMap.picTexture = "items_maps";	//JRH
	curMap.price = 1000;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	labels.IslaMuelle.label = FindTownName("Isla Muelle");
	labels.IslaMuelle.pos.x = 238;
	labels.IslaMuelle.pos.y = 221;
	n = InitMap(n, curMap);

	curMap.id = "mapOxbay";
	curMap.name = "itmname_mapIsland";
	curMap.describe = "itmdescr_mapIsland";
	curMap.island = "Oxbay";
	curMap.location = FindIslandName("Oxbay");
	curMap.picIndex = 7;
	curMap.picTexture = "items_maps";	//JRH
	curMap.price = 1000;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	labels.Oxbay.label = FindTownName("Oxbay");
	labels.Oxbay.pos.x = 365;
	labels.Oxbay.pos.y = 333;
	labels.Greenford.label = FindTownName("Greenford");
	labels.Greenford.pos.x = 145;
	labels.Greenford.pos.y = 237;
	n = InitMap(n, curMap);

	curMap.id = "mapQuebradasCostillas";
	curMap.name = "itmname_mapIsland";
	curMap.describe = "itmdescr_mapIsland";
	curMap.island = "QuebradasCostillas";
	curMap.location = FindIslandName("Quebradas Costillas");
	curMap.picIndex = 23;
	curMap.picTexture = "items_maps";	//JRH
	curMap.price = 1000;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	labels.QuebradasCostillas.label = FindTownName("Quebradas Costillas");
	labels.QuebradasCostillas.pos.x = 65;
	labels.QuebradasCostillas.pos.y = 299;
	labels.Charlestown.label = FindTownName("Charlestown");
	labels.Charlestown.pos.x = 99;
	labels.Charlestown.pos.y = 160;
	n = InitMap(n, curMap);

	curMap.id = "mapRedmond";
	curMap.name = "itmname_mapIsland";
	curMap.describe = "itmdescr_mapIsland";
	curMap.island = "Redmond";
	curMap.location = FindIslandName("Redmond");
	curMap.picIndex = 5;
	curMap.picTexture = "items_maps";	//JRH
	curMap.price = 1000;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	labels.Redmond.label = FindTownName("Redmond");
	labels.Redmond.pos.x = 375;
	labels.Redmond.pos.y = 282;
	n = InitMap(n, curMap);

	curMap.id = "mapSaintMartin";
	curMap.name = "itmname_mapIsland";
	curMap.describe = "itmdescr_mapIsland";
	curMap.island = "SaintMartin";
	curMap.location = FindIslandName("Saint Martin");
	curMap.picIndex = 31;
	curMap.picTexture = "items_maps";	//JRH
	curMap.price = 1000;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	labels.Marigot.label = FindTownName("Marigot");
	labels.Marigot.pos.x = 353;
	labels.Marigot.pos.y = 296;
	labels.Philipsburg.label = FindTownName("Philipsburg");
	labels.Philipsburg.pos.x = 275;
	labels.Philipsburg.pos.y = 180;
	n = InitMap(n, curMap);

	curMap.id = "mapTurks";
	curMap.name = "itmname_mapIsland";
	curMap.describe = "itmdescr_mapIsland";
	curMap.island = "Turks";
	curMap.location = FindIslandName("Turks");
	curMap.picIndex = 30;
	curMap.picTexture = "items_maps";	//JRH
	curMap.price = 1000;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	labels.Turks.label = FindTownName("Grand Turk");
	labels.Turks.pos.x = 240;
	labels.Turks.pos.y = 251;
	n = InitMap(n, curMap);

	curMap.id = "mapAruba";
	curMap.name = "itmname_mapIsland";
	curMap.describe = "itmdescr_mapIsland";
	curMap.island = "Aruba";
	curMap.location = FindIslandName("Aruba");
	curMap.picIndex = 15;
	curMap.picTexture = "items_maps";	//JRH
	curMap.price = 1000;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	labels.Aruba.label = FindTownName("Oranjestad");
	labels.Aruba.pos.x = 310;
	labels.Aruba.pos.y = 289;
	n = InitMap(n, curMap);

	curMap.id = "mapCuracao";
	curMap.name = "itmname_mapIsland";
	curMap.describe = "itmdescr_mapIsland";
	curMap.island = "Curacao";
	curMap.location = FindIslandName("Curacao");
	curMap.picIndex = 20;
	curMap.picTexture = "items_maps";	//JRH
	curMap.price = 1000;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	labels.Curacao.label = FindTownName("Willemstad");
	labels.Curacao.pos.x = 314;
	labels.Curacao.pos.y = 165;
	n = InitMap(n, curMap);

	curMap.id = "mapEleuthera";
	curMap.name = "itmname_mapIsland";
	curMap.describe = "itmdescr_mapIsland";
	curMap.island = "Eleuthera";
	curMap.location = FindIslandName("Eleuthera");
	curMap.picIndex = 32;
	curMap.picTexture = "items_maps";	//JRH
	curMap.price = 1000;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	labels.Eleuthera.label = FindTownName("Eleuthera");
	labels.Eleuthera.pos.x = 243;
	labels.Eleuthera.pos.y = 195;
	labels.Alice.label = FindTownName("Alice");
	labels.Alice.pos.x = 165;
	labels.Alice.pos.y = 255;
	n = InitMap(n, curMap);

	curMap.id = "mapRedmond_Dungeon";
	curMap.name = "itmname_mapDungeon";
	curMap.describe = "itmdescr_mapDungeon";
	curMap.island = "Redmond";
	curMap.location = FindTownName("Redmond");
	curMap.picIndex = 3;
	curMap.picTexture = "items_maps";	//JRH
	curMap.price = 1500;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	n = InitMap(n, curMap);

	curMap.id = "mapCartagena_Library";
	curMap.name = "itmname_mapLibrary";
	curMap.describe = "itmdescr_mapLibrary";
	curMap.island = "Colombia";
	curMap.location = TranslateString("", "Library map");
	curMap.picIndex = 3;
	curMap.picTexture = "items_maps";	//JRH
	curMap.price = "285";
	curMap.skiptrade = false;		//you can sell			
	curMap.skipsell = true;			//but not buy it
	curMap.labels = "";
	makearef(labels, curMap.labels);
	n = InitMap(n, curMap);

	curMap.id = "mapOxbay_Dungeon";
	curMap.name = "itmname_mapDungeon";
	curMap.describe = "itmdescr_mapDungeon";
	curMap.island = "Oxbay";
	curMap.location = FindTownName("Oxbay");
	curMap.picIndex = 9;
	curMap.picTexture = "items_maps";	//JRH
	curMap.price = 1500;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	n = InitMap(n, curMap);

	curMap.id = "mapOxbay_Cave";
	curMap.name = "itmname_mapCave";
	curMap.describe = "itmdescr_mapCave";
	curMap.island = "Oxbay";
	curMap.location = FindIslandName("Oxbay");
	curMap.picIndex = 10;
	curMap.picTexture = "items_maps";	//JRH
	curMap.price = 1200;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	n = InitMap(n, curMap);

	curMap.id = "mapDouwesen_Cave";
	curMap.name = "itmname_mapCave";
	curMap.describe = "itmdescr_mapCave";
	curMap.island = "Douwesen";
	curMap.location = FindIslandName("Douwesen");
	curMap.picIndex = 11;
	curMap.picTexture = "items_maps";	//JRH
	curMap.price = 1200;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	n = InitMap(n, curMap);

	curMap.id = "mapKhaelRoa_TempleGround";
	curMap.name = "itmname_mapKRTempleGround";
	curMap.describe = "itmdescr_mapKRTempleGround";
	curMap.island = "KhaelRoa";
	curMap.location = FindIslandName("Khael Roa");
	curMap.picIndex = 12;
	curMap.picTexture = "items_maps";	//JRH
	curMap.price = 1300;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	n = InitMap(n, curMap);

	curMap.id = "mapKhaelRoa_TempleUpper";
	curMap.name = "itmname_mapKRTempleUpper";
	curMap.describe = "itmdescr_mapKRTempleUpper";
	curMap.island = "KhaelRoa";
	curMap.location = FindIslandName("Khael Roa");
	curMap.picIndex = 4;
	curMap.picTexture = "items_maps";	//JRH
	curMap.price = 1300;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	n = InitMap(n, curMap);

	//JRH -->
	curMap.id = "mapBB1";					//Hornigold
	curMap.name = "itmname_mapBB1";
	curMap.describe = "itmdescr_mapBB1";
	curMap.island = "Map piece 1";
	curMap.location = TranslateString("", "Map piece");
	curMap.picIndex = 1;
	curMap.picTexture = "items_maps2";
	curMap.price = 1000;
	curMap.skiptrade = true;
	curMap.skipsell = true;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	n = InitMap(n, curMap);

	curMap.id = "mapBB2A";					//Caesar dirty map
	curMap.name = "itmname_mapBB2A";
	curMap.describe = "itmdescr_mapBB2A";
	curMap.island = "Map piece 2A";
	curMap.location = TranslateString("", "Map piece");
	curMap.picIndex = 2;
	curMap.picTexture = "items_maps2";
	curMap.price = 1000;
	curMap.skiptrade = true;
	curMap.skipsell = true;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	n = InitMap(n, curMap);

	curMap.id = "mapBB2B";					//Caesar clean map
	curMap.name = "itmname_mapBB2B";
	curMap.describe = "itmdescr_mapBB2B";
	curMap.island = "Map piece 2B";
	curMap.location = TranslateString("", "Map piece");
	curMap.picIndex = 3;
	curMap.picTexture = "items_maps2";
	curMap.price = 1000;
	curMap.skiptrade = true;
	curMap.skipsell = true;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	n = InitMap(n, curMap);

	curMap.id = "mapBB3";					//Eden, island unknown
	curMap.name = "itmname_mapBB3";
	curMap.describe = "itmdescr_mapBB3";
	curMap.island = "Map piece 3";
	curMap.location = TranslateString("", "Map piece");
	curMap.picIndex = 4;
	curMap.picTexture = "items_maps2";
	curMap.price = 1000;
	curMap.skiptrade = true;
	curMap.skipsell = true;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	n = InitMap(n, curMap);

	curMap.id = "mapBB3T";					//Eden, island known
	curMap.name = "itmname_mapBB3T";
	curMap.describe = "itmdescr_mapBB3T";
	curMap.island = "Map piece 3";
	curMap.location = TranslateString("", "Map piece");
	curMap.picIndex = 24;
	curMap.picTexture = "items_maps2";
	curMap.price = 1000;
	curMap.skiptrade = true;
	curMap.skipsell = true;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	n = InitMap(n, curMap);

	curMap.id = "mapBB4A";					//Richards left half
	curMap.name = "itmname_mapBB4A";
	curMap.describe = "itmdescr_mapBB4A";
	curMap.island = "Map piece 4";
	curMap.location = TranslateString("", "Map piece");
	curMap.picIndex = 5;
	curMap.picTexture = "items_maps2";
	curMap.price = 1000;
	curMap.skiptrade = true;
	curMap.skipsell = true;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	n = InitMap(n, curMap);

	curMap.id = "mapBB4A_back";				//Richards left half, sketch on backside
	curMap.name = "itmname_mapBB4A_back";
	curMap.describe = "itmdescr_mapBB4A_back";
	curMap.island = "Map piece 4";
	curMap.location = TranslateString("", "Map piece");
	curMap.picIndex = 14;
	curMap.picTexture = "items_maps2";
	curMap.price = 1000;
	curMap.skiptrade = true;
	curMap.skipsell = true;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	n = InitMap(n, curMap);

	curMap.id = "mapBB4B";					//Richards right half
	curMap.name = "itmname_mapBB4B";
	curMap.describe = "itmdescr_mapBB4B";
	curMap.island = "Map piece 4";
	curMap.location = TranslateString("", "Map piece");
	curMap.picIndex = 6;
	curMap.picTexture = "items_maps2";
	curMap.price = 1000;
	curMap.skiptrade = true;
	curMap.skipsell = true;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	n = InitMap(n, curMap);

	curMap.id = "mapBB4C";					//Richards repaired map
	curMap.name = "itmname_mapBB4C";
	curMap.describe = "itmdescr_mapBB4C";
	curMap.island = "Map piece 4";
	curMap.location = TranslateString("", "Map piece");
	curMap.picIndex = 7;
	curMap.picTexture = "items_maps2";
	curMap.price = 1000;
	curMap.skiptrade = true;
	curMap.skipsell = true;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	n = InitMap(n, curMap);

	curMap.id = "mapBB5A";					//Hands bloody map
	curMap.name = "itmname_mapBB5A";
	curMap.describe = "itmdescr_mapBB5A";
	curMap.island = "Map piece 5";
	curMap.location = TranslateString("", "Map piece");
	curMap.picIndex = 8;
	curMap.picTexture = "items_maps2";
	curMap.price = 1000;
	curMap.skiptrade = true;
	curMap.skipsell = true;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	n = InitMap(n, curMap);

	curMap.id = "mapBB5B";					//Hands clean map
	curMap.name = "itmname_mapBB5B";
	curMap.describe = "itmdescr_mapBB5B";
	curMap.island = "Map piece 5";
	curMap.location = TranslateString("", "Map piece");
	curMap.picIndex = 16;
	curMap.picTexture = "items_maps2";
	curMap.price = 1000;
	curMap.skiptrade = true;
	curMap.skipsell = true;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	n = InitMap(n, curMap);

	curMap.id = "mapBB6";					//Johnson, island unknown
	curMap.name = "itmname_mapBB6";
	curMap.describe = "itmdescr_mapBB6";
	curMap.island = "Map piece 6";
	curMap.location = TranslateString("", "Map piece");
	curMap.picIndex = 15;
	curMap.picTexture = "items_maps2";
	curMap.price = 1000;
	curMap.skiptrade = true;
	curMap.skipsell = true;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	n = InitMap(n, curMap);

	curMap.id = "mapBB6T";					//Johnson, island known
	curMap.name = "itmname_mapBB6T";
	curMap.describe = "itmdescr_mapBB6T";
	curMap.island = "Map piece 6";
	curMap.location = TranslateString("", "Map piece");
	curMap.picIndex = 23;
	curMap.picTexture = "items_maps2";
	curMap.price = 1000;
	curMap.skiptrade = true;
	curMap.skipsell = true;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	n = InitMap(n, curMap);

	curMap.id = "mapWR1";					//blue letters
	curMap.name = "itmname_mapWR1";
	curMap.describe = "itmdescr_mapWR1";
	curMap.island = "Archipelago";
	curMap.location = TranslateString("", "Archipelago");
	curMap.picIndex = 9;
	curMap.picTexture = "items_maps2";
	curMap.price = 2000;
	curMap.skiptrade = true;
	curMap.skipsell = true;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	n = InitMap(n, curMap);

	curMap.id = "mapWR2";					//red pins
	curMap.name = "itmname_mapWR2";
	curMap.describe = "itmdescr_mapWR2";
	curMap.island = "Archipelago";
	curMap.location = TranslateString("", "Archipelago");
	curMap.picIndex = 10;
	curMap.picTexture = "items_maps2";
	curMap.price = 2000;
	curMap.skiptrade = true;
	curMap.skipsell = true;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	n = InitMap(n, curMap);

	curMap.id = "mapWR3";					//lines attempt1
	curMap.name = "itmname_mapWR3";
	curMap.describe = "itmdescr_mapWR3";
	curMap.island = "Archipelago";
	curMap.location = TranslateString("", "Archipelago");
	curMap.picIndex = 11;
	curMap.picTexture = "items_maps2";
	curMap.price = 2000;
	curMap.skiptrade = true;
	curMap.skipsell = true;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	n = InitMap(n, curMap);

	curMap.id = "mapWR4";					//lines attempt2
	curMap.name = "itmname_mapWR4";
	curMap.describe = "itmdescr_mapWR4";
	curMap.island = "Archipelago";
	curMap.location = TranslateString("", "Archipelago");
	curMap.picIndex = 12;
	curMap.picTexture = "items_maps2";
	curMap.price = 2000;
	curMap.skiptrade = true;
	curMap.skipsell = true;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	n = InitMap(n, curMap);

	curMap.id = "mapWR5";					//lines attempt3
	curMap.name = "itmname_mapWR5";
	curMap.describe = "itmdescr_mapWR5";
	curMap.island = "Archipelago";
	curMap.location = TranslateString("", "Archipelago");
	curMap.picIndex = 13;
	curMap.picTexture = "items_maps2";
	curMap.price = 2000;
	curMap.skiptrade = true;
	curMap.skipsell = true;
	curMap.labels = "";
	makearef(labels, curMap.labels);
	n = InitMap(n, curMap);
	//<-- JRH

	return n;
}
// <-- KK

//Levis added for persistent items
void StoreItem(ref itm)
{
	if(CheckPartyItem(itm.id))
	{
		int numstored = GetAttributesNum(StoredItems);
		trace("ITEMS: Store "+itm.id+" at place "+numstored+" for recovery after init");
		aref sitem; makearef(sitem,StoredItems.(numstored));
		CopyAttributes(sitem,itm);
	}
	else
	{
		trace("ITEMS: Don't store "+itm.id+" because it isn't used anymore");
	}
}

int  RestoreStoredItems(int n)
{
	int numstored = GetAttributesNum(StoredItems);
	aref olditm, itm;
	int oldidx = -1;
	for(int i=0;i<numstored;i++)
	{
		makearef(olditm,StoredItems.(i));
		oldidx = GetItemIndex(olditm.id);
		if(oldidx < 0) // PB: If item not yet initialized
		{
			oldidx = n;
			n++;
		}
		makearef(itm,Items[oldidx]);
		trace("ITEMS: Restore "+olditm.id+" at place "+oldidx+" in the itemsarray");
		CopyAttributes(itm,olditm);
		itm.index = oldidx; // PB: Reset index
	}
	DeleteAttribute(StoredItems, ""); // PB: was DeleteClass(StoredItems);
	return n;
}