int nCurIsland = 1;
int nCurMap = 1;

ref chm = &NullCharacter;
int num_labels = 0;

void InitInterface_I(string iniName, int map)
{
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();//MAXIMUS: standard exit-string for exit-button

	chm = GetMainCharacter();

	SelectMap(map); // KK
	// PB: Why does that EXIT button have to glow so stupidly?

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcessCancelExit",0);
}

void ProcessCancelExit()
{
	IDoExit( RC_INTERFACE_MAP_EXIT );
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcessCancelExit");

	// PB: Return to Archipelago Map -->
	ref chm = GetMainCharacter();
	if (CheckAttribute(chm, "from_map"))
	{
		PostEvent("LaunchIAfterFrame",1,"sl", "A_MAP", 2);
		InterfaceStack.SelectMenu_node = "A_MAP";
		DeleteAttribute(chm, "from_map");
	}
	// PB: Return to Archipelago Map <--
	else
	{
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
	}
	interfaceResultCommand = exitCode;
	EndCancelInterface(false);
}

void SelectMap(int idx)
{
	if (idx < 0) return;
	string item_id = Items[idx].id;
	int n = 0;
	aref arMap;
	if (CheckCharacterItem(chm, item_id) == true && Items_FindItem(item_id, &arMap) >= 0) {
		string dispname = GetAssembledString(TranslateString("", arMap.name), arMap);
		CreateStringCheckCase(true, "fakeTitle", dispname, "interface_title", COLOR_NORMAL, 320, 5, SCRIPT_ALIGN_CENTER, 1.0, true);
		string island;
		// PB: Prevent missed attribute for books -->
		if(CheckAttribute(arMap, "island"))
		{
			island = arMap.island;
			aref arIsland; makearef(arIsland, GameInterface.maplist.(island));
			int num = GetAttributesNum(arIsland);
			nCurIsland = sti(GameInterface.maplist.(island));
		}
		// PB: Prevent missed attribute for books <--
		GameInterface.ItemIdx = idx;

		//Add unlocking of perk by levis -->
		if(CheckAttribute(arMap,"UnlockedPerk"))
		{
			UnlockPerkCharacter(GetMainCharacter(), arMap.UnlockedPerk);
			//lngFileID = LanguageOpenFile("AbilityDescribe.txt");
			//CreateString(true, "TIME", "You unlocked the perk: " + LanguageConvertString(lngFileID,book.UnlockedPerk), FONT_NORMAL, COLOR_NORMAL, 320, 482, SCRIPT_ALIGN_CENTER, 0.7);
			//LanguageCloseFile(lngFileID);
			DeleteAttribute(arMap,"UnlockedPerk");
		}
		//Add unlocking of perk <--

		SetNodeUsing("MAP", true);
		// Screwface : MAP TITLES ARE PERIOD DEPENDANT
		int period = GetCurrentPeriod();
		string path = GetResourceDirectory() + "Textures\INTERFACES\Maps\" + period;
		if(FindFile(path, "*.tga.tx", item_id + ".tga.tx") !="")
			{SetNewPicture("MAP", "INTERFACES\Maps\" + period  + "\" + item_id + ".tga");}
		else
			{SetNewPicture("MAP", "INTERFACES\Maps\" + item_id + ".tga");}
		// Screwface : end
		aref arLabels; makearef(arLabels, arMap.labels);
		num_labels = GetAttributesNum(arLabels);
		for (n = 0; n < num_labels; n++) {
			aref arlbl = GetAttributeN(arLabels, n);
			CreateString(true, "label_" + (n + 1), arlbl.label, "seadogs_small", COLOR_NORMAL, sti(arlbl.pos.x), sti(arlbl.pos.y), SCRIPT_ALIGN_LEFT, 0.7);
		}
	}
}
