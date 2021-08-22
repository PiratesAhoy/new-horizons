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

	n = InitQuestItem(n,"key3",		"key3",			"",	"JRH7",	3,	0,0,	"",	"",	"","",	"","",""); //Key to Havana prison door
	n = InitQuestItem(n,"key4",		"key4",			"",	"JRH7",	4,	0,0,	"",	"",	"","",	"","",""); //Key to Havana prison cells
	n = InitQuestItem(n,"SecurityLetter",	"SecurityLetter",	"",	  4,   14,	0,0,	"",	"",	"","",	"","","");
	n = InitQuestItem(n,"TainoRug",		"TainoRug",	"taino_rug",	"GR",   1,	0,0,	"",	"",	"","",	"","",""); // Taino rug
	n = InitQuestItem(n,"SignetRing",	"SignetRing",		"",	"GR",   2,	0,0,	"",	"",	"","",	"","",""); // Signet ring
	n = InitQuestItem(n,"WeddingRing",	"WeddingRing",		"",	"GR",   4,	0,0,	"",	"",	"","",	"","",""); // Wedding ring
  	n = InitQuestItem(n,"jewelry7_q", 	"jewelry7_q",        	"",	  2,    7,	0,0,	"",	"",	"","",	"","",""); // Gold emerald ring
  	n = InitQuestItem(n,"jewelry10_q",	"jewelry10_q",		"",       2,   10,	0,0,	"",	"",	"","",	"","",""); // Gold sapphire ring
	n = InitQuestItem(n,"ExplainLetter",	"ExplainLetter",	"",	  4,   10,	0,0,	"",	"",	"","",	"","",""); // Letter to Santiago governor from daughter / son
	n = InitQuestItem(n,"CourtingLetter",	"CourtingLetter",	"",	  4,   11,	0,0,	"",	"",	"","",	"","",""); // Letter from merchant's son / daughter to governor's daughter / son
	n = InitQuestItem(n,"BetrayedLetter",	"BetrayedLetter",	"",	  4,    9,	0,0,	"",	"",	"","",	"","",""); // Letter from governor's daughter / son who has left you because you became hostile to Spain
	n = InitQuestItem(n,"PrisonPass",	"PrisonPass",		"",	  4,    3,	0,0,	"",	"",	"","",	"","",""); // Visitor pass for a prison
	n = InitQuestItem(n,"FakePrisonPass",	"FakePrisonPass",	"",	  4,    3,	0,0,	"",	"",	"","",	"","",""); // Forged visitor pass for a prison
	n = InitQuestItem(n,"BattleOrders",	"BattleOrders",		"",	"GR",   5,	0,0,	"",	"",	"","",	"","",""); // Battle orders for attack on Port Royale
	n = InitQuestItem(n,"BattleOrders2",	"BattleOrders2",	"",	"GR",   7,	0,0,	"",	"",	"","",	"","",""); // Battle orders for attack on Santiago
	n = InitQuestItem(n,"fake_fort_release","fake_fort_release",	"",	"GR",   6,	0,0,	"",	"",	"","",	"","",""); // Forged release papers for a prisoner
	n = InitQuestItem(n,"medal1",		"medal1",		"",	 "8",   3,	0,0,	"",	"",	"","",	"","",""); // Medal received for delivering battle orders to Santiago governor

  //------------------------------------------------------------------------------------SKILL ITEM SETTINGS-------------------------------------------
  // GENERAL:  ItemIndex                   picIndex          Price        numneeded  leader      accuracy    repair       sneak   skiptrade
  //           |  itmID      modelID           |   rare         |         |   stack     |  fencing  |  cannons  |  defence  |     |  skiprand
  //           |   |            |  picTexture  |    |  MinLevel | indian  |   |  hidden |   |  sailing  |  grapple  | commerce    |  |  skipequip
  //-----------|---|------------|----------|---|----|----|------|----|----|---|--|------|---|---|---|---|---|---|---|---|---|-----|--|--|--|skipsell--
  n = InitItem(n,"WeddingRing", "",      "GR", 4, 0.0,   1,   200,   0,   0,  0, 1,    +2,  0,  0,  0,  0,  0,  0,  0,  0, +2,    1, 1, 1, 1); // Wedding ring
	

	QUESTITEMS_QUANTITY = n;
}