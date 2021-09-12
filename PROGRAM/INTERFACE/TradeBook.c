#define NONEISLAND_TEXTURE_NAME	"interfaces\empty_sea.tga"

int nCurScroll;
int idxIsland;
ref refIsland;
int townsQty, nCurScrolli; // added by MAXIMUS
int curTown = 1; // added by MAXIMUS
bool bBeParty; // added by MAXIMUS
//ref pchar = GetMainCharacter();

int islandsortorder[22] = {3,4,5,15,17,19,8,16,1,14,10,9,2,12,6,13,11,0,20,21};				// LDH sort islands 22Feb09
int islandsortorder_early[22] = {3,4,5,19,8,16,1,14,10,9,2,6,0,13,20,21,11,12,15,17};		// LDH sort islands 22Feb09

void InitInterface_S(string iniName, string town)
{
	//ref PChar = GetMainCharacter();
	GameInterface.title = "titleColonies";

	FillScroll();
// KK -[improved by MAXIMUS]->
	if (!TownExist(town)) town = GetCurrentTownID();
	string island = "";
	if(town=="")
	{
		// PB: Show the Current Island -->
		if(bSeaActive)
		{
			if (pchar.location != "")
			{
				ref CurrentIsland = GetIslandByID(pchar.location);
				// But it does need to have a store:
				if(sti(GetAttribute(CurrentIsland, "visible")) == true)
					island = CurrentIsland.id; 
			}
		}
		else
		{
			island = FindIslandByLocation(pchar.location); 
		}
		// PB: Show the Current Island <--
	}
	else
	{
		island = GetIslandIDFromTown(town);
	}

	// LDH sort islands 22Feb09 -->
	int isl = FindIsland(island);
	bool found = false;
	for (int num=0 ; num<22 ; num++)
	{
		if(GetCurrentPeriod() == PERIOD_EARLY_EXPLORERS)
			{if (islandsortorder_early[num] == isl) {found = true; break;}}
		else
			{if (islandsortorder[num] == isl) {found = true; break;}}
	}
	if (!found) num = 0;
	GameInterface.islandslist.current=num;
	// LDH <--

	townsQty = GetIslandTownsQuantity(island);
	while(townsQty>1)
	{
		if(GetTownIDFromIsland(island, townsQty)==town)
		{
			curTown = townsQty;
			break;
		}
		townsQty--;
	}
// <-[improved by MAXIMUS]- KK
	if(bAnimation && bNewInterface) iniName = "NEW_INTERFACES\ANIMATION\TradeBook.ini";
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
// MAXIMUS interface MOD -->
	CreateExitString();//MAXIMUS: standard exit-string for exit-button

	CreateString(true,"IslandName","",FONT_NORMAL,COLOR_NORMAL,395,42,SCRIPT_ALIGN_CENTER,0.8);
	CreateString(true,"VisitDate","",FONT_NORMAL,COLOR_GREEN_LIGHT,225,76,SCRIPT_ALIGN_LEFT,0.8); // added by MAXIMUS
	CreateString(true,"TownName","",FONT_NORMAL,COLOR_NORMAL,395,111,SCRIPT_ALIGN_CENTER,0.8);

	CreateString(true,"Import0","",FONT_NORMAL,COLOR_NORMAL,72,163,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Import1","",FONT_NORMAL,COLOR_NORMAL,72,207,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Import2","",FONT_NORMAL,COLOR_NORMAL,72,251,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Import3","",FONT_NORMAL,COLOR_NORMAL,72,295,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Import4","",FONT_NORMAL,COLOR_NORMAL,72,339,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Import5","",FONT_NORMAL,COLOR_NORMAL,72,383,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Import6","",FONT_NORMAL,COLOR_NORMAL,72,427,SCRIPT_ALIGN_LEFT,0.8);

	CreateString(true,"Export0","",FONT_NORMAL,COLOR_NORMAL,222,163,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Export1","",FONT_NORMAL,COLOR_NORMAL,222,207,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Export2","",FONT_NORMAL,COLOR_NORMAL,222,251,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Export3","",FONT_NORMAL,COLOR_NORMAL,222,295,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Export4","",FONT_NORMAL,COLOR_NORMAL,222,339,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Export5","",FONT_NORMAL,COLOR_NORMAL,222,383,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Export6","",FONT_NORMAL,COLOR_NORMAL,222,427,SCRIPT_ALIGN_LEFT,0.8);

	CreateString(true,"Contraband0","",FONT_NORMAL,COLOR_NORMAL,372,163,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Contraband1","",FONT_NORMAL,COLOR_NORMAL,372,207,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Contraband2","",FONT_NORMAL,COLOR_NORMAL,372,251,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Contraband3","",FONT_NORMAL,COLOR_NORMAL,372,295,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Contraband4","",FONT_NORMAL,COLOR_NORMAL,372,339,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Contraband5","",FONT_NORMAL,COLOR_NORMAL,372,383,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Contraband6","",FONT_NORMAL,COLOR_NORMAL,372,427,SCRIPT_ALIGN_LEFT,0.8);


	CreateString(true,"Import00","",FONT_NORMAL,COLOR_MONEY,82,183,SCRIPT_ALIGN_LEFT,0.7);
	CreateString(true,"Import01","",FONT_NORMAL,COLOR_MONEY,82,227,SCRIPT_ALIGN_LEFT,0.7);
	CreateString(true,"Import02","",FONT_NORMAL,COLOR_MONEY,82,271,SCRIPT_ALIGN_LEFT,0.7);
	CreateString(true,"Import03","",FONT_NORMAL,COLOR_MONEY,82,315,SCRIPT_ALIGN_LEFT,0.7);
	CreateString(true,"Import04","",FONT_NORMAL,COLOR_MONEY,82,359,SCRIPT_ALIGN_LEFT,0.7);
	CreateString(true,"Import05","",FONT_NORMAL,COLOR_MONEY,82,403,SCRIPT_ALIGN_LEFT,0.7);
	CreateString(true,"Import06","",FONT_NORMAL,COLOR_MONEY,82,447,SCRIPT_ALIGN_LEFT,0.7);

	CreateString(true,"Export00","",FONT_NORMAL,COLOR_MONEY,232,183,SCRIPT_ALIGN_LEFT,0.7);
	CreateString(true,"Export01","",FONT_NORMAL,COLOR_MONEY,232,227,SCRIPT_ALIGN_LEFT,0.7);
	CreateString(true,"Export02","",FONT_NORMAL,COLOR_MONEY,232,271,SCRIPT_ALIGN_LEFT,0.7);
	CreateString(true,"Export03","",FONT_NORMAL,COLOR_MONEY,232,315,SCRIPT_ALIGN_LEFT,0.7);
	CreateString(true,"Export04","",FONT_NORMAL,COLOR_MONEY,232,359,SCRIPT_ALIGN_LEFT,0.7);
	CreateString(true,"Export05","",FONT_NORMAL,COLOR_MONEY,232,403,SCRIPT_ALIGN_LEFT,0.7);
	CreateString(true,"Export06","",FONT_NORMAL,COLOR_MONEY,232,447,SCRIPT_ALIGN_LEFT,0.7);

	CreateString(true,"Contraband00","",FONT_NORMAL,COLOR_MONEY,412,183,SCRIPT_ALIGN_LEFT,0.7);
	CreateString(true,"Contraband01","",FONT_NORMAL,COLOR_MONEY,412,227,SCRIPT_ALIGN_LEFT,0.7);
	CreateString(true,"Contraband02","",FONT_NORMAL,COLOR_MONEY,412,271,SCRIPT_ALIGN_LEFT,0.7);
	CreateString(true,"Contraband03","",FONT_NORMAL,COLOR_MONEY,412,315,SCRIPT_ALIGN_LEFT,0.7);
	CreateString(true,"Contraband04","",FONT_NORMAL,COLOR_MONEY,412,359,SCRIPT_ALIGN_LEFT,0.7);
	CreateString(true,"Contraband05","",FONT_NORMAL,COLOR_MONEY,412,403,SCRIPT_ALIGN_LEFT,0.7);
	CreateString(true,"Contraband06","",FONT_NORMAL,COLOR_MONEY,412,447,SCRIPT_ALIGN_LEFT,0.7);
	
	//Levis Smuggler addon for tradebook
	CreateString(true,"Contraband0_desc","",FONT_NORMAL,COLOR_NORMAL,372,180,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Contraband1_desc","",FONT_NORMAL,COLOR_NORMAL,372,224,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Contraband2_desc","",FONT_NORMAL,COLOR_NORMAL,372,268,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Contraband3_desc","",FONT_NORMAL,COLOR_NORMAL,372,312,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Contraband4_desc","",FONT_NORMAL,COLOR_NORMAL,372,356,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Contraband5_desc","",FONT_NORMAL,COLOR_NORMAL,372,400,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Contraband6_desc","",FONT_NORMAL,COLOR_NORMAL,372,444,SCRIPT_ALIGN_LEFT,0.8);
	
	CreateString(true,"Contraband0_desc2","",FONT_NORMAL,COLOR_NORMAL,472,180,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Contraband1_desc2","",FONT_NORMAL,COLOR_NORMAL,472,224,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Contraband2_desc2","",FONT_NORMAL,COLOR_NORMAL,472,268,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Contraband3_desc2","",FONT_NORMAL,COLOR_NORMAL,472,312,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Contraband4_desc2","",FONT_NORMAL,COLOR_NORMAL,472,356,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Contraband5_desc2","",FONT_NORMAL,COLOR_NORMAL,472,400,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Contraband6_desc2","",FONT_NORMAL,COLOR_NORMAL,472,444,SCRIPT_ALIGN_LEFT,0.8);
	
	CreateString(true,"Contraband10","",FONT_NORMAL,COLOR_MONEY,540,183,SCRIPT_ALIGN_LEFT,0.7);
	CreateString(true,"Contraband11","",FONT_NORMAL,COLOR_MONEY,540,227,SCRIPT_ALIGN_LEFT,0.7);
	CreateString(true,"Contraband12","",FONT_NORMAL,COLOR_MONEY,540,271,SCRIPT_ALIGN_LEFT,0.7);
	CreateString(true,"Contraband13","",FONT_NORMAL,COLOR_MONEY,540,315,SCRIPT_ALIGN_LEFT,0.7);
	CreateString(true,"Contraband14","",FONT_NORMAL,COLOR_MONEY,540,359,SCRIPT_ALIGN_LEFT,0.7);
	CreateString(true,"Contraband15","",FONT_NORMAL,COLOR_MONEY,540,403,SCRIPT_ALIGN_LEFT,0.7);
	CreateString(true,"Contraband16","",FONT_NORMAL,COLOR_MONEY,540,447,SCRIPT_ALIGN_LEFT,0.7);
	
	CreateString(true,"Contraband20","",FONT_NORMAL,COLOR_NORMAL,462,163,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Contraband21","",FONT_NORMAL,COLOR_NORMAL,462,207,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Contraband22","",FONT_NORMAL,COLOR_NORMAL,462,251,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Contraband23","",FONT_NORMAL,COLOR_NORMAL,462,295,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Contraband24","",FONT_NORMAL,COLOR_NORMAL,462,339,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Contraband25","",FONT_NORMAL,COLOR_NORMAL,462,383,SCRIPT_ALIGN_LEFT,0.8);
	CreateString(true,"Contraband26","",FONT_NORMAL,COLOR_NORMAL,462,427,SCRIPT_ALIGN_LEFT,0.8);

	string groupIcons = "GOODS";
	if(bNewIcons==true) groupIcons = "GOODS_NEW";

	CreateImage("igood0",groupIcons,"",34,164,66,196);
	CreateImage("igood1",groupIcons,"",34,208,66,240);
	CreateImage("igood2",groupIcons,"",34,252,66,284);
	CreateImage("igood3",groupIcons,"",34,296,66,328);
	CreateImage("igood4",groupIcons,"",34,340,66,372);
	CreateImage("igood5",groupIcons,"",34,384,66,416);
	CreateImage("igood6",groupIcons,"",34,428,66,460);

	CreateImage("egood0",groupIcons,"",184,164,216,196);
	CreateImage("egood1",groupIcons,"",184,208,216,240);
	CreateImage("egood2",groupIcons,"",184,252,216,284);
	CreateImage("egood3",groupIcons,"",184,296,216,328);
	CreateImage("egood4",groupIcons,"",184,340,216,372);
	CreateImage("egood5",groupIcons,"",184,384,216,416);
	CreateImage("egood6",groupIcons,"",184,428,216,460);

	CreateImage("cgood0",groupIcons,"",334,164,366,196);
	CreateImage("cgood1",groupIcons,"",334,208,366,240);
	CreateImage("cgood2",groupIcons,"",334,252,366,284);
	CreateImage("cgood3",groupIcons,"",334,296,366,328);
	CreateImage("cgood4",groupIcons,"",334,340,366,372);
	CreateImage("cgood5",groupIcons,"",334,384,366,416);
	CreateImage("cgood6",groupIcons,"",334,428,366,460);

// KK -->
	int town_nation = GetTownNation(town);
	SetNewPicture("NATION", "interfaces\flags\Crest_" + GetNationFlagImage(town_nation) + ".tga");
	SetSelectable("MANAGE_BUTTON", town_nation == PERSONAL_NATION);

	bool hasShip = false;
	for (int i = 0; i < COMPANION_MAX; i++) {
		int cidx = GetCompanionIndex(PChar, i);
		if (cidx < 0) continue;
		if (GetCharacterShipType(GetCharacter(cidx)) != SHIP_NOTUSED) {
			hasShip = true;
			break;
		}
	}
	SetSelectable("I_SHIPHOLD", !LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm() && hasShip);
	if (hasShip == false && GetBerthedShipsQuantityForTown(GetTownIDFromLocID(PChar.location)) > 0) {
		hasShip = true;
		GameInterface.GoDirectToShipBerthing = true;
		SendMessage(&GameInterface, "lsls", MSG_INTERFACE_MSG_TO_NODE, "I_SHIP", 0, "#"+XI_ConvertString("Sel Berth"));
	}
// <-- KK

// MAXIMUS interface MOD -->
	SetSelectable("I_SHIP", !LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm() && hasShip); // KK
	// KK SetSelectable("I_NATIONS",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	// PB SetSelectable("I_QUESTBOOK",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	SetSelectable("I_SHIPLOG",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	SetSelectable("EXIT_BUTTON",true);
	SetNodeUsing("VIDEOPIE",bAnimation && bNewInterface);

	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
// MAXIMUS interface MOD <--

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("frame","FrameProcess",1);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
}

void FrameProcess()
{
	if(nCurScroll!=sti(GameInterface.islandslist.current))
	{
		nCurScroll = sti(GameInterface.islandslist.current);
		SetVariable();
	}
}

void SetVariable()
{
	idxIsland = XI_GetIsland(nCurScroll);
	if(idxIsland==-1) return;
	refIsland = GetIslandByIndex(idxIsland);
	GameInterface.strings.IslandName = FindIslandName(refIsland.id); // KK

	townsQty = GetIslandTownsQuantity(refIsland.id);

	SetNodeUsing("LEFTCHANGE_TOWN",townsQty>1);
	SetSelectable("LEFTCHANGE_TOWN",townsQty>1);
	SetNodeUsing("RIGHTCHANGE_TOWN",townsQty>1);
	SetSelectable("RIGHTCHANGE_TOWN",townsQty>1);

	string town = GetTownIDFromIsland(refIsland.id, curTown);
	int town_nation = GetTownNation(town);
// KK -->
	GameInterface.strings.TownName = FindTownName(town);
	SetNewPicture("NATION", "interfaces\flags\Crest_" + GetNationFlagImage(town_nation) + ".tga");
	SetSelectable("MANAGE_BUTTON", town_nation == PERSONAL_NATION);
// <-- KK
	int curStore = GetTownStoreIndex(GetTownIDFromIsland(refIsland.id, curTown));//MAXIMUS: the simplest way :) -->

	// LDH always display a town if possible - 03Jan09
	if (curStore < 0)
	{
		curTown = 1;
		town = GetTownIDFromIsland(refIsland.id, curTown);
		town_nation = GetTownNation(town);
		GameInterface.strings.TownName = FindTownName(town); // KK
		SetNewPicture("NATION", "interfaces\flags\Crest_" + GetNationFlagImage(town_nation) + ".tga"); // KK
		curStore = GetTownStoreIndex(GetTownIDFromIsland(refIsland.id, curTown));
	}

	XI_SetIslandData(curStore);
	if(curStore<0)
	{
		GameInterface.strings.VisitDate = XI_ConvertString("There is no shop")+"!";
		ChangeStringColor("VisitDate", COLOR_RED_LIGHT);
		ChangeStringColor("TownName", COLOR_NORMAL);
		return;
	}//MAXIMUS <--
	if(CheckAttribute(Stores[curStore],"STORE_CURDATE"))
	{
		GameInterface.strings.VisitDate = XI_ConvertString("Last visit") + ": " + Stores[curStore].STORE_CURDATE;
		ChangeStringColor("VisitDate", COLOR_GREEN_LIGHT);
		ChangeStringColor("TownName", COLOR_GREEN_LIGHT);
	}
	else
	{
		GameInterface.strings.VisitDate = XI_ConvertString("Store was not visited");
		ChangeStringColor("VisitDate", COLOR_RED_LIGHT);
		ChangeStringColor("TownName", COLOR_NORMAL);
	}
}

void SetNextParty(bool bRight)
{
	if(bRight)
	{
		curTown++;
		if(curTown > townsQty) { curTown = 1; }
	}
	else
	{
		curTown--;
		if(curTown < 1) { curTown = townsQty; }
	}
}

void XI_SetIslandData(int curStore)
{	// trade info
	string tradeAttr,strAttr,picAttr,strPrice;
	int idxGoods;
	bool fIvisible = false;
	if(CheckAttribute(refIsland,"visible") && sti(refIsland.visible)==true)	fIvisible = true;
	for(int i=0;i<7;i++)
	{
		string impAttr1, impAttr2, impSell, impBuy;
		string expAttr1, expAttr2, expSell, expBuy;
		string conAttr1, conAttr2, conSell, conBuy;
		int j;
		tradeAttr = "id"+(i+1);
		// for import goods
		strAttr = "Import"+i;
		strPrice = "Import0"+i; // added by MAXIMUS
		picAttr = "igood"+i;
		if(fIvisible)
		{
			if(CheckAttribute(refIsland,"Trade.Import."+tradeAttr) && curStore!=-1)
			{
				idxGoods = sti(refIsland.Trade.Import.(tradeAttr));
// added by MAXIMUS -->
				impAttr1 = "importsell"+i;
				impAttr2 = "importbuy"+i;
				if(CheckAttribute(Stores[curStore],impAttr1) && CheckAttribute(Stores[curStore],impAttr2))
				{
				//	GameInterface.strings.(strPrice) = Stores[curStore].(impAttr1) + " " + XI_ConvertString("gp")+"." + " / "+Stores[curStore].(impAttr2) + " " + XI_ConvertString("gp")+".";
					GameInterface.strings.(strPrice) = Stores[curStore].(impAttr1) + " / " + Stores[curStore].(impAttr2);
				}
				else GameInterface.strings.(strPrice) = "...";
// added by MAXIMUS <--
				GameInterface.strings.(strAttr) = XI_ConvertString(Goods[idxGoods].name);
				GameInterface.pictures.(picAttr).pic = Goods[idxGoods].name;
			}
			else
			{
				GameInterface.strings.(strAttr) = "";
				GameInterface.strings.(strPrice) = "";
				GameInterface.pictures.(picAttr).pic = "";
			}
		}
		else
		{
			GameInterface.strings.(strAttr) = "";
			GameInterface.strings.(strPrice) = "";
			GameInterface.pictures.(picAttr).pic = "";
		}
		// for export goods
		strAttr = "Export"+i;
		strPrice = "Export0"+i; // added by MAXIMUS
		picAttr = "egood"+i;
		if(fIvisible)
		{
			if(CheckAttribute(refIsland,"Trade.Export."+tradeAttr) && curStore!=-1)
			{
				idxGoods = sti(refIsland.Trade.Export.(tradeAttr));
// added by MAXIMUS -->
				expAttr1 = "exportsell"+i;
				expAttr2 = "exportbuy"+i;
			//	if(CheckAttribute(Stores[curStore],expAttr1)) expSell = Stores[curStore].(expAttr1) + " " + XI_ConvertString("gp")+".";
				if(CheckAttribute(Stores[curStore],expAttr1)) expSell = Stores[curStore].(expAttr1);
			//	if(CheckAttribute(Stores[curStore],expAttr2)) expBuy = " / "+Stores[curStore].(expAttr2) + " " + XI_ConvertString("gp")+".";
				if(CheckAttribute(Stores[curStore],expAttr2)) expBuy = " / " + Stores[curStore].(expAttr2);
				if(CheckAttribute(Stores[curStore],"STORE_CURDATE")) GameInterface.strings.(strPrice) = expSell + expBuy;
				else GameInterface.strings.(strPrice) = "...";
// added by MAXIMUS <--
				GameInterface.strings.(strAttr) = XI_ConvertString(Goods[idxGoods].name);
				GameInterface.pictures.(picAttr).pic = Goods[idxGoods].name;
			}
			else
			{
				GameInterface.strings.(strAttr) = "";
				GameInterface.strings.(strPrice) = "";
				GameInterface.pictures.(picAttr).pic = "";
			}
		}
		else
		{
			GameInterface.strings.(strAttr) = "";
			GameInterface.strings.(strPrice) = "";
			GameInterface.pictures.(picAttr).pic = "";
		}
		// for contraband goods
		strAttr = "Contraband"+i;
		strPrice = "Contraband0"+i;
		//Levis Smuggler addon -->
		string smugstrPrice = "Contraband1"+i;
		string desc1 = "Contraband"+i+"_desc";
		string desc2 = "Contraband"+i+"_desc2";
		string strAttr2 = "Contraband2"+i;
		//Levis Smuggler addon <--
		picAttr = "cgood"+i;
		if(fIvisible)
		{
			if(CheckAttribute(refIsland,"Trade.Contraband."+tradeAttr) && curStore!=-1)//MAXIMUS: if we'll have contraband trader - curStore!=-1 can be deleted
			{
				idxGoods = sti(refIsland.Trade.Contraband.(tradeAttr));
				GameInterface.strings.(strAttr) = XI_ConvertString(Goods[idxGoods].name);
				conAttr1 = "contrasell"+i;
				conAttr2 = "contrabuy"+i;
			//	if(CheckAttribute(Stores[curStore],conAttr1)) conSell = Stores[curStore].(conAttr1) + " " + XI_ConvertString("gp")+".";
				if(CheckAttribute(Stores[curStore],conAttr1)) conSell = Stores[curStore].(conAttr1);
			//	if(CheckAttribute(Stores[curStore],conAttr2)) conBuy = " / "+Stores[curStore].(conAttr2) + " " + XI_ConvertString("gp")+".";
				if(CheckAttribute(Stores[curStore],conAttr2)) conBuy = " / " + Stores[curStore].(conAttr2);
				if(CheckAttribute(Stores[curStore],"STORE_CURDATE") && CheckCharacterPerk(GetMainCharacter(),"Trustworthy")) GameInterface.strings.(strPrice) = conSell + conBuy;
				else GameInterface.strings.(strPrice) = XI_ConvertString("Unknown_price");
				GameInterface.pictures.(picAttr).pic = Goods[idxGoods].name;
				//Levis Smuggler Addon -->
				GameInterface.strings.(desc1) = XI_ConvertString("Trader_desc");
				GameInterface.strings.(desc2) = XI_ConvertString("Smuggler_desc");
				string islcon = "Good_"+idxGoods;
				if(CheckAttribute(refIsland,"smuggling.curprices.Good_"+idxGoods))
				{
					GameInterface.strings.(smugstrPrice) = refIsland.smuggling.curprices.(islcon).price+" / --"; 
					GameInterface.strings.(strAttr2) = " ("+refIsland.smuggling.curprices.(islcon).date+")";
				}
				else 
				{ 
					GameInterface.strings.(smugstrPrice) = XI_ConvertString("by deal"); 
					GameInterface.strings.(strAttr2) = "";
				}
				//Levis Smuggler addon <--
			}
			else
			{
				GameInterface.strings.(strAttr) = "";
				GameInterface.strings.(strPrice) = "";
				GameInterface.pictures.(picAttr).pic = "";
				//Levis Smuggler Addon -->
				GameInterface.strings.(desc1) = "";
				GameInterface.strings.(desc2) = "";
				GameInterface.strings.(smugstrPrice) = "";
				GameInterface.strings.(strAttr2) = "";
				//Levis Smuggler addon <--
			}
		}
		else
		{
			GameInterface.strings.(strAttr) = "";
			GameInterface.strings.(strPrice) = "";
			GameInterface.pictures.(picAttr).pic = "";
		}
	}
}

void FillScroll()
{
	int i;
	string attributeName;

	nCurScroll = -1;
	GameInterface.islandslist.current = 0;
	GameInterface.islandslist.BadPicture1 = NONEISLAND_TEXTURE_NAME;
	GameInterface.islandslist.ImagesGroup.t1 = "ISLANDSICON";

	int islandIdx;
	ref islandRef;
	for(i=0; i<ISLANDS_QUANTITY; i++) // NK 05-03-30 use int for max, and oversized array
	{
		attributeName = "pic" + (i+1);
		islandIdx = XI_GetIsland(i);
		if(islandIdx==-1) break;

		islandRef = GetIslandByIndex(islandIdx);
		GameInterface.islandslist.(attributeName).img1 = islandRef.id;
		GameInterface.islandslist.(attributeName).tex1 = 0;
	}
	GameInterface.islandslist.ListSize = i;
}

void ProcessCancelExit()
{
	IDoExit(RC_INTERFACE_TRADEBOOK_EXIT);
}

int XI_GetIsland(int inum)
{
	if(inum<0) return -1;
	if(inum>=ISLANDS_QUANTITY) return -1; // NK 05-03-30 use int for max, and oversized array

	int idx = 0;
	for(int n=0; n<ISLANDS_QUANTITY; n++)	// LDH 22Feb09
	{
		int i = islandsortorder[n];			// LDH sort islands 22Feb09
		if(GetCurrentPeriod() == PERIOD_EARLY_EXPLORERS)
			i = islandsortorder_early[n];

		if( GetAttribute(&Islands[i],"visible") == false) return -1;
		if( idx==inum ) return i;
		idx++;
	}
	return -1;
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("frame","FrameProcess");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcessCommandExecute"); // MAXIMUS interface MOD

    interfaceResultCommand = exitCode;
// MAXIMUS interface MOD -->
	EndCancelInterface(true);
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	switch(nodName)
	{
	case "LEFTCHANGE_TOWN":
		if(comName=="click")
		{
			if(bBeParty)
			{
				SetNextParty(false);
				SetVariable();
			}
		}
	break;

	case "RIGHTCHANGE_TOWN":
		if(comName=="click")
		{
			if(bBeParty)
			{
				SetNextParty(true);
				SetVariable();
			}
		}
	break;

// KK -->
	case "MANAGE_BUTTON":
		if(comName == "click")
		{
			int idxIsland = XI_GetIsland(nCurScroll);
			if (idxIsland >= 0) {
				ref refIsland = GetIslandByIndex(idxIsland);
				int townsQty = GetIslandTownsQuantity(refIsland.id);
				string town = GetTownIDFromIsland(refIsland.id, curTown);
				ref mchr = GetMainCharacter();
				mchr.ManageFromColoniesScreen = town;
trace("manag: "+mchr.ManageFromColoniesScreen);
				PostEvent("LaunchIAfterFrame", 1, "sl", "ManageColony", 1);
				interfaceResultCommand = RC_INTERFACE_TRADEBOOK_EXIT;
				EndCancelInterface(false);
				return;
			}
		}
	break;
// <-- KK
	}

	int x;ref tmpch;string tmpstr;
        if(nodName=="I_CHARACTER")
{
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_TRADEBOOK_EXIT;
		EndCancelInterface(false);

	}
}
        if(nodName=="I_SHIP")
{
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_TRADEBOOK_EXIT;
		EndCancelInterface(false);

	}
}
        if(nodName=="I_SHIPHOLD")
{
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_TRADEBOOK_EXIT;
		EndCancelInterface(false);

	}
}
        if(nodName=="I_PASSENGER")
{
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_TRADEBOOK_EXIT;
		EndCancelInterface(false);

	}
}
        if(nodName=="I_QUESTBOOK")
{
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_TRADEBOOK_EXIT;
		EndCancelInterface(false);

	}
}
        if(nodName=="I_SHIPLOG")
{
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_TRADEBOOK_EXIT;
		EndCancelInterface(false);

	}
}
        if(nodName=="I_NATIONS")
{
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_TRADEBOOK_EXIT;
		EndCancelInterface(false);

	}
}
        if(nodName=="I_ITEMS")
{
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_TRADEBOOK_EXIT;
		EndCancelInterface(false);

	}
}
}
// MAXIMUS interface MOD <--
