int activeItem = -1;
bool bRandomItem = false;

void InitInterface(string iniName)
{
	ref PChar = GetMainCharacter();
	if(!bAbordageStarted && !ownDeckStarted() && CheckAttribute(PChar,"hiddenthing") && GetTime()<23.50 && GetTime()>4.30)
	{
		if(!CheckAttribute(PChar,"hiddenthing.ambush"))
		{
			LAi_group_SetRelation(LAI_DEFAULT_GROUP, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_SetRelation(LAI_GROUP_GUARDS, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_SetRelation(GetCurrentCitizenGroup(), LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			Ambush("Soldiers", 4, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND, "");
			ChangeCharacterReputation(PChar, -3);
			ProcessCancelExit();
			PChar.hiddenthing.ambush = true;
			return;
		}
	}

	string shText = "";
	string sIcons = "";
	string sPictr = "";
	if(CheckAttribute(PChar,"activeItem.Action.label"))
	{
		shText = PChar.activeItem.Action.label;
		if(!bAbordageStarted && GetTime()<23.50 && GetTime()>4.30 && !CheckAttribute(PChar,"hiddenthing.ambush"))
		{
			shText += " "+TranslateString("","try_to_do_it_later_tonight");
			PChar.hiddenthing = true;
		}
		else
		{
			sIcons = "BOX_IMAGE";
			sPictr = "BoxImage";
			if(CheckAttribute(PChar,"hiddenthing.ambush")) DeleteAttribute(PChar,"hiddenthing.ambush");
			if(CheckAttribute(PChar,"hiddenthing")) DeleteAttribute(PChar,"hiddenthing");
			DeleteLocatorGlobal(PChar.location, "item", PChar.activeLocator);
			Item_OnExitLocator();
			float x, y, z;
			GetCharacterPos(&PChar, &x, &y, &z);
			WriteLocatorGlobal(PChar.location, "box", "hidden_box", "", -1, x, y, z, true);
			shText = TranslateString("","some_strange_small_trunk_here");
		}
	}

	if(CheckAttribute(PChar,"activeItem.pick") && sti(PChar.activeItem)>=0)
	{
		aref activeLocation;
		activeItem = sti(PChar.activeItem);
		if(CheckAttribute(PChar,"itemLocationIndex") && sti(PChar.itemLocationIndex)>=0)
		{
			makearef(activeLocation, Locations[sti(PChar.itemLocationIndex)]);
			if (CheckAttribute(PChar,"activeRandItem") && sti(PChar.activeRandItem)==true) {
				string activeRandItemAttribute = "RandItemType"+sti(PChar.activeItem);
				if (CheckAttribute(activeLocation, activeRandItemAttribute)) {
					activeItem = sti(activeLocation.(activeRandItemAttribute));
					bRandomItem = true;
				}
			} else {
				activeItem = sti(PChar.activeItem);
				bRandomItem = false;
			}
		}
// KK -->
		string displayItemName = TranslateString("", Items[activeItem].name);
		if (CheckAttribute(&Items[activeItem], "QualityName")) displayItemName = TranslateString("", "q"+Items[activeItem].QualityName) + " " + displayItemName; // PB: Correct quality name
		shText = TranslateString("", "you've_got") + " " + displayItemName+"!";
// <-- KK
		sIcons = GetItemTextureName(Items[activeItem].id);
		sPictr = GetItemPictureName(Items[activeItem].id);
	}

	EngineLayersOffOn(true);
	locCameraSleep(true);
	SetTimeScale(0.0);
	BLIVisible(false); // KK

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

	SetFormatedText("INFO_TEXT", shText);
	SendMessage(&GameInterface, "lsl", MSG_INTERFACE_MSG_TO_NODE, "INFO_TEXT", 5);
	CreateImage("Item", sIcons, sPictr, 288, 136, 352, 200);

	if (!GetSelectable("BUTTON_TAKE")) SetCurrentNode("BUTTON_LEAVE"); // KK

	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ItemLeave","ProcessItemLeave",0);
	SetEventHandler("ItemTake","ProcessItemTake",0);
}

void ResetView()
{
	ref pch = GetMainCharacter();
	SendMessage(&IActions,"ll",LI_SET_VISIBLE,true);
	UpdateTimeScale(); // PB
	locCameraSleep(false);
	EngineLayersOffOn(false);
	BLIVisible(true);
	DeleteEntitiesByType("scrshoter");
	CheckReloadAction(pch, ""); // KK
}

void ProcessItemLeave()
{
	ref PChar = GetMainCharacter();
	if (bRandomItem) {
		aref activeLocation;
		activeItem = sti(PChar.activeItem);
		string activeRandItemAttribute;
		if(CheckAttribute(PChar,"itemLocationIndex") && sti(PChar.itemLocationIndex)>=0)
		{
			makearef(activeLocation, Locations[sti(PChar.itemLocationIndex)]);
			if (CheckAttribute(PChar,"activeRandItem") && sti(PChar.activeRandItem)==true) {
				activeRandItemAttribute = "RandItemType"+sti(PChar.activeItem);
				if (CheckAttribute(activeLocation, activeRandItemAttribute)) {
					activeItem = sti(activeLocation.(activeRandItemAttribute));
				}
				string locatorName = "randitem" + activeItem;
				aref randItemLocator;
				FindLocator(activeLocation.id, locatorName, &randItemLocator, true);
				RandItems_DrawRandItem(activeItem, activeLocation, randItemLocator);
			} else {
				activeItem = sti(PChar.activeItem);
			}
		}
	} else {
		// ...
	}
	Event("exitCancel");
}

void ProcessItemTake()
{
	Log_SetActiveAction("Nothing");

	ref PChar = GetMainCharacter();
	aref activeLocation; makearef(activeLocation, Locations[sti(PChar.itemLocationIndex)]);

	if (bRandomItem) {
		string activeRandItemAttribute = "RandItemType"+sti(PChar.activeItem);
		SendMessage(&randItemModels[sti(PChar.activeItem)], "lslff", MSG_MODEL_BLEND, "blenditemlit", 1000, 1.0, 0.0);
		GiveItem2Character(PChar, Items[activeItem].id);
		activeLocation.(activeRandItemAttribute) = -1;
	} else {
		activeItem = sti(PChar.activeItem);
		Trace("ItemLogic: picking item "+Items[activeItem].id);
		Items[activeItem].shown = false;
		SendMessage(&itemModels[activeItem], "lslff", MSG_MODEL_BLEND, "blenditemlit", 1000, 1.0, 0.0);
		GiveItem2Character(PChar, Items[activeItem].id);

		//MAXIMUS: deleting temporary added locators -->
		string curLocName = PChar.activeLocator;
		if(CheckAttribute(activeLocation, "locators.items."+curLocName+".tmpLocator"))
		{
			PChar.activeItem = "";
			PChar.activeLocator = "";
			PChar.activeItem.pick = false;
			if(CheckAttribute(Items[activeItem],"startLocator")) { DeleteAttribute(Items[activeItem],"startLocator"); }
			if(CheckAttribute(Items[activeItem],"bShown")) { DeleteAttribute(Items[activeItem],"bShown"); }
			DeleteLocatorGlobal(PChar.location, "items", curLocName);
		}
		//MAXIMUS: deleting temporary added locators <--
	}
	DeleteAttribute(PChar,"activeItem");
	Event("exitCancel");
}

void ProcessCancelExit()
{
	IDoExit(RC_INTERFACE_INFOBOX_EXIT);
}

void IDoExit(int exitCode)
{
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ItemLeave","ProcessItemLeave");
	DelEventHandler("ItemTake","ProcessItemTake");

	interfaceResultCommand = exitCode;
    ResetView();
	EndCancelInterface(true);
}