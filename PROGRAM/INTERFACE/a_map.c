
void InitInterface(string iniName)
{
	GameInterface.title = "titleReserved";

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();//MAXIMUS: standard exit-string for exit-button

	ref chm = GetMainCharacter();
	CreateString(true,"TIME",GetHumanDate(GetDataYear(), GetDataMonth(), GetDataDay()) + " - " + GetStringTime(GetTime()),"seadogs_small",COLOR_BLUE_LIGHT,620,460,SCRIPT_ALIGN_RIGHT,0.6);

	if(CheckAttribute(chm, "maplegend"))		// PB: Show note on Right-Clicking functionality
	{
		CreateString(true, "HelpText", XI_ConvertString("MapHelpString"), FONT_NORMAL, COLOR_MONEY, 320, 478, SCRIPT_ALIGN_CENTER, 0.7);
		DeleteAttribute(chm, "maplegend");	// ... but only once
	}

	HideToolT();
	ShowMap();
	ShowButtons();

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
	SetEventHandler("frame","HideToolT",1);
}

void ShowMap()
{
	object fakeMap;
	ref chm = GetMainCharacter();

	float startX = makefloat(199.0)+makefloat(23.0); //189
	float startY = makefloat(37.0)+makefloat(23.0); //50
	float endX = makefloat(665.0)-makefloat(23.0); //653
	float endY = makefloat(501.0)-makefloat(23.0); //493

	float FAKE_MAP_TO_SEA_SCALE_X = makefloat(2000/stf(endX-startX));
	float FAKE_MAP_TO_SEA_SCALE_Y = makefloat(2000/stf(endY-startY));

	float fakeMapPosX = makefloat(sti(stf(endX-startX)/2)+startX);
	float fakeMapPosY = makefloat(sti(stf(endY-startY)/2)+startY);

	fakeMap.X = fakeMapPosX;
	fakeMap.Y = fakeMapPosY;

	fakeMap.poz.X = makefloat(makefloat(worldMap.playerShipX)/FAKE_MAP_TO_SEA_SCALE_X);
	fakeMap.poz.Y = makefloat(makefloat(worldMap.playerShipZ)/FAKE_MAP_TO_SEA_SCALE_Y);

	int fakeShipPosX = makeint(makefloat(fakeMap.X) - makefloat(fakeMap.poz.X));
	int fakeShipPosY = makeint(makefloat(fakeMap.Y) + makefloat(fakeMap.poz.Y));

	ref shipRef = GetShipByType(GetCharacterShipType(chm));
	aref arship; makearef(arship, chm.ship);
	int picScale = 7;

	// PB: Legend -->
	if(bAnimation)
	{
		int x,y;
		x = 45; y = 105;
		CreateString(true,"LEGEND",TranslateString("","- LEGEND -"),"seadogs_small",COLOR_YELLOW_LIGHT,x+10,y-5,SCRIPT_ALIGN_LEFT,0.7);
		
		x = x-10; y = y+20;
		CreateString(true,"SHIP_LEGEND",TranslateString("",": Ship Position"),"seadogs_small",COLOR_YELLOW_LIGHT,x+10,y-5,SCRIPT_ALIGN_LEFT,0.7);
		CreateImage("SHIP_ICON", "SHIPS16", "Brig1", sti(x-picScale), sti(y-picScale)+2, sti(x+picScale), sti(y+picScale)+2);

		y = y+20;
		CreateString(true,"CONVOY_LEGEND",TranslateString("",": Escort Destination"),"seadogs_small",COLOR_YELLOW_LIGHT,x+10,y-5,SCRIPT_ALIGN_LEFT,0.7);
		CreateImage("CONVOY_ICON", "ICONS", "ship speed icon", sti(x-picScale), sti(y-picScale)+2, sti(x+picScale), sti(y+picScale)+2);

		y = y+20;
		CreateString(true,"CARGO_LEGEND",TranslateString("",": Cargo Destination"),"seadogs_small",COLOR_YELLOW_LIGHT,x+10,y-5,SCRIPT_ALIGN_LEFT,0.7);
		CreateImage("CARGO_ICON", "ICONS", "ship capacity icon", sti(x-picScale), sti(y-picScale)+2, sti(x+picScale), sti(y+picScale)+2);

		y = y+20;
		CreateString(true,"TREASURE_LEGEND",TranslateString("",": Hidden Treasure"),"seadogs_small",COLOR_YELLOW_LIGHT,x+10,y-5,SCRIPT_ALIGN_LEFT,0.7);
		CreateImage("TREASURE_ICON", "MARK", "mark", sti(x-picScale), sti(y-picScale)+2, sti(x+picScale), sti(y+picScale)+2);
	}
	// PB: Legend <--

	// PB: Sextant and Chronometer -->
	bool ShowPosition = iRealismMode == 0 && !NAVIGATION_EQUIPMENT;
	if(!bSeaActive) ShowPosition = true; // You know where you are when you are ashore
	if(CheckCharacterItem(chm,"clock2") && CheckCharacterItem(chm,"sextant")) ShowPosition = true;
	if(ShowPosition)
	{
		CreateImage("SHIP", "SHIPS16", "Brig1", sti(fakeShipPosX-picScale), sti(fakeShipPosY-picScale), sti(fakeShipPosX+picScale), sti(fakeShipPosY+picScale)); // PB: Brig matches with worldmap player ship model
		SetPictureBlind("SHIP",true,minBlindColor,maxBlindColor);
	}
	// PB: Sextant and Chronometer <--

	// stljeffbb Jan 15 2012 -->
	if(iRealismMode>1 || OPEN_SEA_MOD) {
		SetNodeUsing("MAP", false);
		SetNodeUsing("MAP_SCALED", true);
	}else{
		SetNodeUsing("MAP", true);
		SetNodeUsing("MAP_SCALED", false);
	}
	// stljeffbb Jan 15 2012 <--

	aref refLabel;
	makearef(refLabel, worldMap.labels);
	for (int n = 0; n < GetAttributesNum(refLabel); n++) {
		string labelId = GetAttributeName(GetAttributeN(refLabel,n));

		if (!CheckAttribute(worldMap, "labels." + labelId)) {
			trace("Label " + labelId + " not valid");
			continue;
		}
		if (!CheckAttribute(worldMap, "labels." + labelId + ".position")) {
			trace("Label " + labelId + " does not have a position");
			continue;
		}

		string labelText = worldMap.labels.(labelId).text;
		float pozX = makefloat(makefloat(worldMap.labels.(labelId).position.x)/FAKE_MAP_TO_SEA_SCALE_X);
		float pozY = makefloat(makefloat(worldMap.labels.(labelId).position.z)/FAKE_MAP_TO_SEA_SCALE_Y);

		int fakeX = makeint(makefloat(fakeMap.X) - pozX);
		int fakeY = makeint(makefloat(fakeMap.Y) + pozY)-20;

		string labelType = worldMap.labels.(labelId).type;
		if (labelType == "Island") {
			CreateString(true,labelId,labelText,"seadogs_small",COLOR_GREEN_LIGHT,fakeX,fakeY,SCRIPT_ALIGN_CENTER,0.7);
		}
		if (labelType == "Town") {
			string town_id = worldMap.labels.(labelId).id;
			string town_name = worldMap.labels.(labelId).name;
			// Convoy quests
			string convoy_destination = GetAttribute(chm, "quest.generate_convoy_quest.destination");
			if(convoy_destination == town_id || convoy_destination == town_name)
			{
				CreateImage("CONVOY", "ICONS", "ship speed icon", fakeX-5, fakeY+7, fakeX+9, fakeY+21);
				if(HasSubStr(chm.location,"tavern") || chm.location == "Antigua_mansion_study")
				{
					SetPictureBlind("CONVOY",true,minBlindColor,maxBlindColor);
					SetPictureBlind("SHIP",false,minBlindColor,maxBlindColor);
				}
			}

			// Trader quests
			int ShowTradeQuest = 0;
			if(GetAttribute(chm, "quest.generate_trade_quest_progress") == "begin")	ShowTradeQuest = 1;
			if(HasSubStr(chm.location,"store"))										ShowTradeQuest = 2;
			string iTradeColony = GetAttribute(chm, "quest.generate_trade_quest_progress.iTradeColony");
			if (iTradeColony == town_id || iTradeColony == town_name) {
				if(ShowTradeQuest > 0) {
					CreateImage("CARGO", "ICONS", "ship capacity icon", fakeX-5, fakeY+7, fakeX+9, fakeY+21);
					if(ShowTradeQuest > 1) {
						SetPictureBlind("CARGO",true,minBlindColor,maxBlindColor);
						SetPictureBlind("SHIP",false,minBlindColor,maxBlindColor);
					}
				}
			}
		}

		// Treasures
		if(GetAttribute(chm, "treasureloc") == labelId)
		{
			CreateImage("MARK", "MARK", "mark", fakeX-5, fakeY+7, fakeX+9, fakeY+21);
			if(CheckAttribute(chm, "treasuremap"))
			{
				SetPictureBlind("MARK",true,minBlindColor,maxBlindColor);
				SetPictureBlind("SHIP",false,minBlindColor,maxBlindColor);
				DeleteAttribute(chm, "treasuremap");
			}
		}
	}
}

void ShowButtons()
{
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "EXIT_BUTTON");

	for(int i=0; i<ISLANDS_QUANTITY+1; i++)
	{
		string rcString = "RECTANGLE"+sti(i+2);
		SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, rcString);
	}
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();
	if(!hasSubStr(comName, "click")) return;
//	if (!bRMouseDown) return; // PB: Add functionality to left button too

	for(int i=0; i<ISLANDS_QUANTITY+2; i++)
	{
		string rcString = "RECTANGLE"+sti(i+1);
		if(nodName!=rcString) continue;
		ShowIslandInfo(i); break;
	}
}

void ShowIslandInfo(int Idx) 
{
	string sHeader = "";
	string sText1 = "";
	int isIdx = Idx;
	if(Idx==22) { isIdx = 9; }
	sHeader = Islands[isIdx].id;
	int colonyNation = -1;

	string isIsland = Islands[isIdx].id;
	
	string itmName = "map" + isIsland;
	
	// PB: On left-click, try to open Island Map -->
	ref PChar = GetMainCharacter();
	if (!bRMouseDown)
	{
		if (CheckCharacterItem(PChar, itmName) == true)
		{
			aref itmRef;
			if (Items_FindItem(itmName, &itmRef) >= 0 && CheckAttribute(itmRef, "index")) GameInterface.ItemIdx = itmRef.index;
			
			PChar.from_map = true;
			
			PostEvent("LaunchIAfterFrame",1,"sl", "I_MAP", 2);
			InterfaceStack.SelectMenu_node = "I_MAP";
			interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
			EndCancelInterface(false);
		}
	}
	// PB: On left-click, try to open Island Map <--
	else
	{
		for(int c=1; c<10; c++)
		{
			string cityNum = "city"+c;
			if(CheckAttribute(worldMap,"islands."+isIsland+".locations."+cityNum+".label.text") && CheckAttribute(worldMap,"islands."+isIsland+".locations."+cityNum+".real") && CheckAttribute(worldMap,"islands."+isIsland+".locations."+cityNum+".label.icon"))
			{
				string colonyName = worldMap.islands.(isIsland).locations.(cityNum).name;
				string colonyId = worldMap.islands.(isIsland).locations.(cityNum).name;
				colonyNation = sti(worldMap.islands.(isIsland).locations.(cityNum).label.icon);
				if (colonyNation == 8)	colonyNation = PERSONAL_NATION;
				if(Idx==9 && cityNum=="city3") { sText1 += ""; colonyNation = sti(worldMap.islands.(isIsland).locations.city2.label.icon); }
				else sText1 += TranslateString("", FindTownName(colonyId))+" - "+XI_ConvertString(GetNationNameByType(colonyNation)) +"                                                                                             ";
				if(Idx==22 && cityNum=="city3") { sHeader = FindTownName(colonyId); isIsland = worldMap.islands.(isIsland).locations.(cityNum).name; sText1 = TranslateString("", FindTownName(colonyId))+" - "+XI_ConvertString(GetNationNameByType(colonyNation)); } // Tortuga
			}
		}
		if(Idx!=22) // For all except Tortuga
		{
			colonyNation = Islands[isIdx].smuggling_nation;
			sHeader = TranslateString("", FindIslandName(sHeader));
		}
		CreateTooltip(sHeader, sText1, colonyNation);
	}
}

void CreateTooltip(string header, string text1, int colonyNation)
{
	SetNodeUsing("WINDOW_FAD",true);
	SetNodeUsing("RECT",true);
	SetNodeUsing("INFO_PICT",true);
	SetNodeUsing("TEXT",true);
	SetCurrentNode("TEXT");
	SetFormatedText("TEXT",header);
	SetNodeUsing("INFO_TEXT",true);
	SetFormatedText("INFO_TEXT",text1);
	SetSelectable("EXIT_BUTTON",false);

	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "WINDOW_FAD");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "RECT");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 3, "INFO_PICT");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 3, "INFO_TEXT");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 3, "TEXT");

	SetNewPicture("INFO_PICT", "interfaces\flags\Crest_" + GetNationFlagImage(colonyNation) + ".png");
}

void HideToolT()
{
	if (bRMouseDown) return;

	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);

	SetNodeUsing("WINDOW_FAD",false);
	SetNodeUsing("RECT", false);
	SetNodeUsing("INFO_PICT",false);
	SetNodeUsing("TEXT",false);
	SetNodeUsing("INFO_TEXT",false);
	SetSelectable("EXIT_BUTTON",true);
	SetCurrentNode("OFFIC_1");
}

void ProcessCancelExit()
{
	IDoExit( RC_INTERFACE_A_MAP_EXIT );
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcessCommandExecute");
	DelEventHandler("frame","HideToolT");

	ref PChar = GetMainCharacter();
	if(CheckAttribute(PChar, "inventory"))
	{
		DeleteAttribute(GameInterface, "islandlist");
		DeleteAttribute(GameInterface, "maplist");
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = exitCode;
		EndCancelInterface(false);
	}
	else
	{
		interfaceResultCommand = exitCode;
		EndCancelInterface(true);
	}
}
