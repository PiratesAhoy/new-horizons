int nCurScroll;

//int lngFileID;

object objNewItemsEquip;

void InitInterface_I(string iniName, int item)
{
	//remove all skill modifiers
	ref pch;
	if(CheckAttribute(GetMainCharacter(),"Interface.Fellow")) { pch = CharacterFromId(characters[GetMainCharacterIndex()].Interface.Fellow); }
	else { pch = GetMainCharacter(); }

    // JRH remove ghost ammo -->
	if(ENABLE_AMMOMOD == 1)
	{
		int gp = GetCharacterItem(pch, "gunpowder");
		if(gp == 0)
		{
			TakenItems(pch, "gunpowder", 1); TakenItems(pch, "gunpowder", -1);
		}

		int pb = GetCharacterItem(pch, "pistolbullets");
		if(pb == 0)
		{
			TakenItems(pch, "pistolbullets", 1); TakenItems(pch, "pistolbullets", -1);
		}

		int pg = GetCharacterItem(pch, "pistolgrapes");
		if(pg == 0)
		{
			TakenItems(pch, "pistolgrapes", 1); TakenItems(pch, "pistolgrapes", -1);
		}

		int mb = GetCharacterItem(pch, "musketbullets");
		if(mb == 0)
		{
			TakenItems(pch, "musketbullets", 1); TakenItems(pch, "musketbullets", -1);
		}

		if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0 || sti(GetStorylineVar(FindCurrentStoryline(), "BUG_PUZZLES")) > 0)
		{
			int ca = GetCharacterItem(pch, "cartridges");
			if(ca == 0)
			{
				TakenItems(pch, "cartridges", 1); TakenItems(pch, "cartridges", -1);
			}
			int gpb = GetCharacterItem(pch, "cart_box_O");
			if(gpb == 0)
			{
				TakenItems(pch, "cart_box_O", 1); TakenItems(pch, "cart_box_O", -1);
			}
			int cap = GetCharacterItem(pch, "caps_box_O");
			if(cap == 0)
			{
				TakenItems(pch, "caps_box_O", 1); TakenItems(pch, "caps_box_O", -1);
			}
		}

		int ar = GetCharacterItem(pch, "bladearrows");
		if(ar == 0)
		{
			TakenItems(pch, "bladearrows", 1); TakenItems(pch, "bladearrows", -1);
		}

		int ar2 = GetCharacterItem(pch, "arrows2");
		if(ar2 == 0)
		{
			TakenItems(pch, "arrows2", 1); TakenItems(pch, "arrows2", -1);
		}

		int ro = GetCharacterItem(pch, "rockets");
		if(ro == 0)
		{
			TakenItems(pch, "rockets", 1); TakenItems(pch, "rockets", -1);
		}
	}
    // <-- JRH

//	GameInterface.title = "titleItems";

	nCurScroll=-1;
	SetUsedItems();
//	FillScroll();
	string selection = GUN_ITEM_TYPE;
	if (item > -1 && item < ITEMS_QUANTITY && CheckAttribute(&Items[item], "groupID") == true) selection = Items[item].groupID; // KK

	//JRH -->
	if (selection == BLADE_ITEM_TYPE || selection == ARMOR_ITEM_TYPE || selection == AMMUNITION_ITEM_TYPE || selection == FLASK_ITEM_TYPE || selection == POUCH_ITEM_TYPE || selection == BELT_ITEM_TYPE || selection == OPEN_ITEM_TYPE) selection = GUN_ITEM_TYPE;
	if (selection == SPYGLASS_ITEM_TYPE  || selection == LOCKPICK_ITEM_TYPE || selection == CLOCK_ITEM_TYPE || selection == COMPASS_ITEM_TYPE || selection == DOCUMENT_ITEM_TYPE || selection == OUTFIT_ITEM_TYPE) selection = OBJECT_ITEM_TYPE;
	if (selection == EQUIP_ITEM_TYPE || selection == EXAMINE_ITEM_TYPE) selection = QUEST_ITEM_TYPE;
	//<-- JRH

	FillSelectedScroll(selection);
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();//MAXIMUS: standard exit-string for exit-button
	CreateString(true, "ItemName", "", FONT_NORMAL, COLOR_YELLOW, 320, 200, SCRIPT_ALIGN_CENTER, 1.1); // KK

// KK -->
	bool hasShip = false;
	for (int i = 0; i < 4; i++) {
		int cidx = GetCompanionIndex(GetMainCharacter(), i);
		if (cidx < 0) continue;
		if (GetCharacterShipType(GetCharacter(cidx)) != SHIP_NOTUSED) {
			hasShip = true;
			break;
		}
	}
	SetSelectable("I_SHIPHOLD", !LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm() && hasShip);
	if (hasShip == false && GetBerthedShipsQuantityForTown(GetTownIDFromLocID(characters[GetMainCharacterIndex()].location)) > 0) {
		hasShip = true;
		GameInterface.GoDirectToShipBerthing = true;
		SendMessage(&GameInterface, "lsls", MSG_INTERFACE_MSG_TO_NODE, "I_SHIP", 0, "#"+XI_ConvertString("Sel Berth"));
	}
// <-- KK

// MAXIMUS interface MOD -->
	SetSelectable("I_SHIP", !LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm() && hasShip); // KK
	// KK SetSelectable("I_NATIONS",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	SetSelectable("I_TRADEBOOK",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	// PB SetSelectable("I_QUESTBOOK",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	SetSelectable("I_SHIPLOG",!LAi_IsBoardingProcess() && !LAi_group_IsActivePlayerAlarm());
	SetSelectable("EXIT_BUTTON",true);
// MAXIMUS interface MOD <--

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("frame","FrameProcess",1);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("TossItemYes", "I_TossItem", 0); //Levis
	SetEventHandler("TossItemNo", "Remove_Confirm", 0); //Levis
	//SetEventHandler("EquipPress","ProcEquipPress",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);

	FrameProcess();
	UpdateItemData();

// KK -->
	switch (selection)
	{
		case GUN_ITEM_TYPE: SetSelectable("B_WEAPON",false); CreateStringCheckCase(true,"fakeTitle",XI_ConvertString("IntWeapon"),"interface_title",COLOR_NORMAL,320,5,SCRIPT_ALIGN_CENTER,1.0,true); break;
		case POTION_ITEM_TYPE: SetSelectable("B_POTION",false); CreateStringCheckCase(true,"fakeTitle",XI_ConvertString("IntMedicine"),"interface_title",COLOR_NORMAL,320,5,SCRIPT_ALIGN_CENTER,1.0,true); break;
		case OBJECT_ITEM_TYPE: SetSelectable("B_ITEMS",false); CreateStringCheckCase(true,"fakeTitle",XI_ConvertString("IntItems"),"interface_title",COLOR_NORMAL,320,5,SCRIPT_ALIGN_CENTER,1.0,true); break;
		case MAP_ITEM_TYPE: SetSelectable("B_MAP",false); CreateStringCheckCase(true,"fakeTitle",XI_ConvertString("IntMap"),"interface_title",COLOR_NORMAL,320,5,SCRIPT_ALIGN_CENTER,1.0,true); break;
		case QUEST_ITEM_TYPE: SetSelectable("B_QUEST",false); CreateStringCheckCase(true,"fakeTitle",XI_ConvertString("IntQuest"),"interface_title",COLOR_NORMAL,320,5,SCRIPT_ALIGN_CENTER,1.0,true); break;
	}
// <-- KK
	// PB -->
	// Why is this necessary? It works without it for regular maps
	if(CheckAttribute(pch, "inventory")) // Return to Maps Tab
	{
		ChangeSelectedScroll(MAP_ITEM_TYPE);    UpdateItemData();
		DeleteAttribute(pch, "inventory");
	}
	if(CheckAttribute(pch, "bookreading")) // Return to Items Tab
	{
		ChangeSelectedScroll(OBJECT_ITEM_TYPE);    UpdateItemData();
		DeleteAttribute(pch, "bookreading");
	}
	// PB <--
}

void FrameProcess()
{
	if(nCurScroll!=sti(GameInterface.itemslist.current))
	{
		nCurScroll = sti(GameInterface.itemslist.current);
		UpdateItemData();
	}
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

// MAXIMUS interface MOD -->
	int x;ref tmpch;string tmpstr;
        if(nodName=="I_CHARACTER")
{
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		ProcessCancelExit();
		EndCancelInterface(false);

	}
}
        if(nodName=="I_SHIP")
{
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		ProcessCancelExit();
		EndCancelInterface(false);

	}
}
        if(nodName=="I_SHIPHOLD")
{
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		ProcessCancelExit();
		EndCancelInterface(false);

	}
}
        if(nodName=="I_PASSENGER")
{
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		ProcessCancelExit();
		EndCancelInterface(false);

	}
}
        if(nodName=="I_QUESTBOOK")
{
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		ProcessCancelExit();
		EndCancelInterface(false);

	}
}
        if(nodName=="I_TRADEBOOK")
{
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		ProcessCancelExit();
		EndCancelInterface(false);

	}
}
        if(nodName=="I_SHIPLOG")
{
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		ProcessCancelExit();
		EndCancelInterface(false);

	}
}
        if(nodName=="I_NATIONS")
{
if(comName=="activate" || comName=="click")
	{

		PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
		InterfaceStack.SelectMenu_node = nodName;
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		ProcessCancelExit();
		EndCancelInterface(false);

	}
}
// MAXIMUS interface MOD <--

	switch(nodName)
	{
	case "EQUIP_BUTTON":
		if(comName=="activate" || comName=="click")
		{

		//JRH -->
			ref PChar;
			PChar = GetMainCharacter();

			string itmName = GetItemIDByOrder(nCurScroll);

			if(IsEquipCharacterByItem(Pchar, "pistol20"))	//RELEASE PISTOL20 OR EQUIP OTHER GUN OR EQUIP ANY BLADE!!!
			{
				if(CheckCharacterItem(Pchar,"ammobag2"))
				{
					aref itemref; makearef(itemref,Items[GetItemIndex(itmName)]);
					if(CheckAttribute(itemref,"groupID") && itemref.groupID == GUN_ITEM_TYPE)
					{
						if(IsEquipCharacterByItem(Pchar, "ammobag2")) RemoveCharacterEquip(Pchar, POUCH_ITEM_TYPE);

						TakeItemFromCharacter(Pchar, "ammobag2");
						GiveItem2Character(Pchar, "ammobag1");
					}
				}
				if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0) LAi_QuestDelay("pchar_outfit_check", 0.1);	//JRH: see quest_reaction
			}
			else
			{
				if(IsEquipCharacterByItem(Pchar, "pistolthrow5") || IsEquipCharacterByItem(Pchar, "pistolthrow4")
				|| IsEquipCharacterByItem(Pchar, "pistolthrow3") || IsEquipCharacterByItem(Pchar, "pistolthrow2")
				|| IsEquipCharacterByItem(Pchar, "pistolthrow1"))	//RELEASE PISTOLTROW 1-5
				{
					if(IsEquipCharacterByItem(Pchar, "ammobag2")) RemoveCharacterEquip(Pchar, POUCH_ITEM_TYPE);

					if(CheckCharacterItem(Pchar,"ammobag2"))
					{
						TakeItemFromCharacter(Pchar, "ammobag2");
						GiveItem2Character(Pchar, "ammobag1");
					}
					if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0) LAi_QuestDelay("pchar_outfit_check", 0.1);	//JRH: see quest_reaction
				}
			}
			else
			{
				if(IsEquipCharacterByItem(Pchar, "pistolbelt"))	//RELEASE PISTOLBELT
				{
					if(itmName == "pistolbelt")	//yes should be different, pistolbelt is not a gun
					{
						if(IsEquipCharacterByItem(Pchar, "ammobag2")) RemoveCharacterEquip(Pchar, POUCH_ITEM_TYPE);

						if(CheckCharacterItem(Pchar,"ammobag2"))
						{
							TakeItemFromCharacter(Pchar, "ammobag2");
							GiveItem2Character(Pchar, "ammobag1");
						}
						if(IsEquipCharacterByItem(Pchar, "pistolcannon")) RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
						if(CheckCharacterItem(Pchar,"pistolcannon"))
						{
							TakeItemFromCharacter(Pchar, "pistolcannon");
							GiveItem2Character(Pchar, "pistolcannon1");
						}

						if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0) LAi_QuestDelay("pchar_outfit_check", 0.1);	//JRH: see quest_reaction
					}
				}
			}
			else
			{
				if(itmName == "pistol20" || itmName == "pistolbelt" || itmName == "pistolthrow5"
				|| itmName == "pistolthrow4" || itmName == "pistolthrow3" || itmName == "pistolthrow2"
				|| itmName == "pistolthrow1")	//EQUIP PISTOL20 or PISTOLTHROW 1-5 or PISTOLBELT
				{
					if(CheckCharacterItem(Pchar,"ammobag1"))
					{
						TakeItemFromCharacter(Pchar, "ammobag1");
						GiveItem2Character(Pchar, "ammobag2");
					}
					if(CheckCharacterItem(Pchar,"pistolcannon1"))
					{
						TakeItemFromCharacter(Pchar, "pistolcannon1");
						GiveItem2Character(Pchar, "pistolcannon");
					}

					if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0) LAi_QuestDelay("pchar_outfit_check", 0.1);	//JRH: see quest_reaction
				}
			}

			if(itmName == "ammobag2")
			{
				RemoveCharacterEquip(Pchar, POUCH_ITEM_TYPE);
				TakeItemFromCharacter(Pchar, "ammobag1");

				if(!CheckCharacterItem(Pchar,"ammobag2"))
				GiveItem2Character(Pchar, "ammobag2");

				TakeItemFromCharacter(Pchar, "ammopouch");
				RemoveCharacterEquip(Pchar, FLASK_ITEM_TYPE);
				TakeItemFromCharacter(Pchar, "powderflask");
				if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0) LAi_QuestDelay("pchar_outfit_check", 0.1);	//JRH: see quest_reaction
			}

			if(itmName == "med_bag2_out")
			{
				PlaySound("PEOPLE\clothes1.wav");
				RemoveCharacterEquip(Pchar, OUTFIT_ITEM_TYPE);
				TakeItemFromCharacter(Pchar, "med_bag2_out");
				GiveItem2Character(Pchar, "med_bag1_out");
				TakeItemFromCharacter(Pchar, "crypto_excel");
			}

			if(itmName == "med_bag1_out")
			{
				PlaySound("INTERFACE\cancel.wav");

				if(CheckAttribute(Pchar,"quest.med_bag1_out") && Pchar.quest.med_bag1_out == "equipped")
				{
					//RELEASE
					RemoveCharacterEquip(Pchar, OUTFIT_ITEM_TYPE);
					TakeItemFromCharacter(Pchar, "med_bag1_out");
					GiveItem2Character(Pchar, "med_bag1_doc_YES");	//restarts item loop
					Pchar.quest.med_bag1_out = "released";
				}
				else
				{
					//EQUIP
					Pchar.quest.med_bag1_out = "equipped";
				}
			}

			//EMPTY
			if(itmName == "detective_kit3")
			{
				TakeItemFromCharacter(Pchar, "detective_kit3");

				if(CheckCharacterItem(Pchar,"D_feather") && CheckCharacterItem(Pchar,"D_scissors") && CheckCharacterItem(Pchar,"D_compasses")
				&& CheckCharacterItem(Pchar,"D_scalpel") && CheckCharacterItem(Pchar,"D_magnifying") && CheckCharacterItem(Pchar,"D_tweezers"))
				{
					PlaySound("INTERFACE\cancel.wav");
					TakeItemFromCharacter(Pchar, "D_feather");
					TakeItemFromCharacter(Pchar, "D_scissors");
					TakeItemFromCharacter(Pchar, "D_compasses");
					TakeItemFromCharacter(Pchar, "D_scalpel");
					TakeItemFromCharacter(Pchar, "D_magnifying");
					TakeItemFromCharacter(Pchar, "D_tweezers");
					GiveItem2Character(Pchar, "detective_kit4");
					Pchar.quest.detective_kit = "filled";
				}
				else
				{
					PlaySound("INTERFACE\detective_kit_lock.wav");
					GiveItem2Character(Pchar, "detective_kit1");
					Pchar.quest.detective_kit = "empty";
				}
			}

			//FILLED
			if(itmName == "detective_kit4")
			{
				PlaySound("INTERFACE\detective_kit_lock.wav");
				TakeItemFromCharacter(Pchar, "detective_kit4");
				GiveItem2Character(Pchar, "detective_kit1");

				if(CheckAttribute(Pchar,"quest.Dkit4_first_time") && Pchar.quest.Dkit4_first_time == "no")
				{

				}
				else
				{
					//it is the first time
					Pchar.quest.Dkit4_first_time = "no";

					LAi_QuestDelay("Dkit1_prepared", 0.5);
				}
			}

			if(itmName == "doc1B")
			{
				PlaySound("INTERFACE\paper_small.wav");
				TakeItemFromCharacter(Pchar, "doc1B");
				GiveItem2Character(Pchar, "doc1A");

				if(CheckCharacterItem(Pchar,"med_bag1_doc_YES"))
				{
					TakeItemFromCharacter(Pchar, "med_bag1_doc_YES");
					GiveItem2Character(Pchar, "med_bag1_out");
					EquipCharacterByItem(Pchar, "med_bag1_out");
					Pchar.quest.med_bag1_out = "equipped";
				}
			}

			if(itmName == "doc4B")
			{
				PlaySound("INTERFACE\book_close.wav");
				TakeItemFromCharacter(Pchar, "doc4B");
				GiveItem2Character(Pchar, "doc4A");

				if(CheckCharacterItem(Pchar,"med_bag1_doc_YES"))
				{
					TakeItemFromCharacter(Pchar, "med_bag1_doc_YES");
					GiveItem2Character(Pchar, "med_bag1_out");
					EquipCharacterByItem(Pchar, "med_bag1_out");
					Pchar.quest.med_bag1_out = "equipped";
				}
			}

			if(itmName == "doc5C")
			{
				PlaySound("AMBIENT\TAVERN\open_bottle.wav");
				TakeItemFromCharacter(Pchar, "doc5C");
				GiveItem2Character(Pchar, "doc5A");

				if(CheckCharacterItem(Pchar,"med_bag1_doc_YES"))
				{
					TakeItemFromCharacter(Pchar, "med_bag1_doc_YES");
					GiveItem2Character(Pchar, "med_bag1_out");
					EquipCharacterByItem(Pchar, "med_bag1_out");
					Pchar.quest.med_bag1_out = "equipped";
				}
			}

			if(itmName == "doc6C")
			{
				PlaySound("INTERFACE\paper_small.wav");
				TakeItemFromCharacter(Pchar, "doc6C");
				GiveItem2Character(Pchar, "doc6A");

				if(CheckCharacterItem(Pchar,"med_bag1_doc_YES"))
				{
					TakeItemFromCharacter(Pchar, "med_bag1_doc_YES");
					GiveItem2Character(Pchar, "med_bag1_out");
					EquipCharacterByItem(Pchar, "med_bag1_out");
					Pchar.quest.med_bag1_out = "equipped";
				}
			}

			if(itmName == "doc60D")
			{
				PlaySound("INTERFACE\paper_small.wav");
				TakeItemFromCharacter(Pchar, "doc60D");
				GiveItem2Character(Pchar, "doc60A");
			}
			if(itmName == "doc2E")
			{
				PlaySound("INTERFACE\book_close.wav");
				TakeItemFromCharacter(Pchar, "doc2D");
				TakeItemFromCharacter(Pchar, "doc2E");
				TakeItemFromCharacter(Pchar, "doc3D");
				GiveItem2Character(Pchar, "doc2A");

				if(CheckCharacterItem(Pchar,"med_bag1_doc_YES"))
				{
					TakeItemFromCharacter(Pchar, "med_bag1_doc_YES");
					GiveItem2Character(Pchar, "med_bag1_out");
					EquipCharacterByItem(Pchar, "med_bag1_out");
					Pchar.quest.med_bag1_out = "equipped";
				}
			}

			if(itmName == "doc3D")
			{
				PlaySound("INTERFACE\book_close.wav");
				TakeItemFromCharacter(Pchar, "doc2D");
				TakeItemFromCharacter(Pchar, "doc2E");
				TakeItemFromCharacter(Pchar, "doc3D");
				GiveItem2Character(Pchar, "doc2A");

				if(CheckCharacterItem(Pchar,"med_bag1_doc_YES"))
				{
					TakeItemFromCharacter(Pchar, "med_bag1_doc_YES");
					GiveItem2Character(Pchar, "med_bag1_out");
					EquipCharacterByItem(Pchar, "med_bag1_out");
					Pchar.quest.med_bag1_out = "equipped";
				}
			}

			if(itmName == "bagcompass4")
			{
				if(IsEquipCharacterByItem(Pchar, "bagcompass4"))
				{
					//RELEASE
					if(CheckAttribute(Pchar,"model") && Pchar.model == "William Legrand3")
					{
						SetModel(Pchar, "William Legrand", Pchar.model.animation, Pchar.sex, stf(Pchar.model.height), true);
						PlaySound("PEOPLE\clothes1.wav"); PlaySound("INTERFACE\button1.wav");
					}
				}
				else
				{
					//EQUIP
					if(CheckAttribute(Pchar,"model") && Pchar.model == "William Legrand")
					{
						SetModel(Pchar, "William Legrand3", Pchar.model.animation, Pchar.sex, stf(Pchar.model.height), true);
						PlaySound("PEOPLE\clothes1.wav"); PlaySound("INTERFACE\button1.wav");
					}
				}
			}

			if(itmName == "bladespyglass6") PlaySound("PEOPLE\spyglass.wav");
			if(itmName == "pistolsextant2") PlaySound("INTERFACE\pinion_take.wav");

			if(itmName == "book54")
			{
				PlaySound("INTERFACE\book_close.wav");
				PlaySound("INTERFACE\book_close.wav");
				TakeItemFromCharacter(Pchar, "book54");
				GiveItem2Character(Pchar, "book52");
			}

			if(itmName == "book55C")
			{
				PlaySound("INTERFACE\took_item.wav");
				TakeItemFromCharacter(Pchar, "book55C");
				GiveItem2Character(Pchar, "book55D");
				GiveItem2Character(Pchar, "key29");
				Pchar.quest.key29 = "picked_up";
			}

			if(itmName == "book55D")
			{
				PlaySound("INTERFACE\book_close.wav");
				TakeItemFromCharacter(Pchar, "book55D");
				GiveItem2Character(Pchar, "book55A");
			}

			if(itmName == "BH_sketch_out")
			{
				PlaySound("INTERFACE\paper.wav");
				TakeItemFromCharacter(Pchar, "BH_sketch_out");
				GiveItem2Character(Pchar, "rolled_paper");
			}

			if(itmName == "rolled_paper")
			{
				PlaySound("PEOPLE\gunpowder.wav");
				TakeItemFromCharacter(Pchar, "rolled_paper");
				GiveItem2Character(Pchar, "rolled_paper_gp");
				TakenItems(Pchar, "gunpowder", -100);
			}

			if(itmName == "rolled_paper_gp")
			{
				PlaySound("INTERFACE\paper.wav");
				TakeItemFromCharacter(Pchar, "rolled_paper_gp");
				GiveItem2Character(Pchar, "bladepaperroll");

				LAi_QuestDelay("bladepaperroll_equip_check", 0.1);
			}

			if(itmName == "bladearrows")
			{
				if(IsEquipCharacterByItem(Pchar, "bladearrows"))
				{
					//RELEASE
					//no problem
				}
				else
				{
					//EQUIP
					LAi_QuestDelay("indian_arrow_tomahawk_equip_check", 0.1);
				}
			}

			if(itmName == "tomahawk")
			{
				if(IsEquipCharacterByItem(Pchar, "tomahawk"))
				{
					//RELEASE
					//no problem
				}
				else
				{
					//EQUIP
					LAi_QuestDelay("indian_arrow_tomahawk_equip_check", 0.1);
				}
			}

			if(itmName != "pistolbow" || itmName != "blowgun")
			{
				if(HasSubStr(itmName, "pistol"))
				{
					if(IsEquipCharacterByItem(Pchar, FindCharacterItemByGroup(&PChar, GUN_ITEM_TYPE)))
					{
						//RELEASE
						//no problem
					}
					else
					{
						//EQUIP
						LAi_QuestDelay("indian_pistols_equip_check", 0.1);
					}
				}
			}

			if(itmName == "shield_hand")
			{
				TakeItemFromCharacter(Pchar, "shield_hand");
				GiveItem2Character(Pchar, "shield_back");
				EquipCharacterByItem(Pchar, "shield_back");

				LAi_QuestDelay("indian_shield_equip_check", 0.1);
			}

			if(itmName == "shield_back")
			{
				LAi_QuestDelay("indian_shield_equip_check", 0.1);
			}

			if(itmName == "skull_ring")
			{
				if(IsEquipCharacterByItem(Pchar, "skull_ring"))
				{
					//RELEASE
					Pchar.skull_ring = "off";
					PlaySound("PEOPLE\teleport.wav");

					LAi_QuestDelay("skull_ring_release", 2.0);
				}
				else
				{
					//EQUIP
					Pchar.skull_ring = "on";
					PlaySound("PEOPLE\transform.wav");

					if(IsEquipCharacterByItem(Pchar, "moccasins")) RemoveCharacterEquip(Pchar, EQUIP_ITEM_TYPE);
					if(IsEquipCharacterByItem(Pchar, "filled_pipe")) RemoveCharacterEquip(Pchar, EQUIP_ITEM_TYPE);
					SetModel(Pchar, pchar.model, "man", "man", 1.8, true);
					Pchar.filled_pipe = "released";

					LAi_QuestDelay("skull_ring_equip", 2.0);
				}

				LAi_QuestDelay("skull_ring_hp", 0.1);
			}

			if(itmName == "moccasins")
			{
				if(IsEquipCharacterByItem(Pchar, "moccasins"))
				{
					//RELEASE
					SetModel(Pchar, pchar.model, "man", "man", 1.8, true);
					PlaySound("PEOPLE\clothes1.wav");
				}
				else
				{
					//EQUIP
					SetModel(Pchar, pchar.model, "fast_man", "man", 1.8, true);
					PlaySound("PEOPLE\clothes1.wav");

					if(IsEquipCharacterByItem(Pchar, "skull_ring")) RemoveCharacterEquip(Pchar, EQUIP_ITEM_TYPE);
					if(IsEquipCharacterByItem(Pchar, "filled_pipe")) RemoveCharacterEquip(Pchar, EQUIP_ITEM_TYPE);
					Pchar.skull_ring = "off";
					Pchar.filled_pipe = "released";


					LAi_QuestDelay("moccasins_equip", 2.0);
					LAi_QuestDelay("skull_ring_release", 2.0);
				}

				LAi_QuestDelay("skull_ring_hp", 0.1);
			}

			if(itmName == "pulverized_mushrooms")
			{
				//EQUIP
				if(CheckCharacterItem(Pchar,"empty_pipe"))
				{
					PlaySound("AMBIENT\CHURCH\bench1_2.wav");
					PlaySound("PEOPLE\clothes3.wav");
					PlaySound("PEOPLE\clothes3.wav");
					TakeItemFromCharacter(Pchar, "pulverized_mushrooms");
					TakeItemFromCharacter(Pchar, "empty_pipe");
					GiveItem2Character(Pchar, "filled_pipe");

					if(IsEquipCharacterByItem(Pchar, "skull_ring")) RemoveCharacterEquip(Pchar, EQUIP_ITEM_TYPE);
					if(IsEquipCharacterByItem(Pchar, "moccasins")) RemoveCharacterEquip(Pchar, EQUIP_ITEM_TYPE);
					if(IsEquipCharacterByItem(Pchar, "filled_pipe")) RemoveCharacterEquip(Pchar, EQUIP_ITEM_TYPE);
					SetModel(Pchar, pchar.model, "man", "man", 1.8, true);
					Pchar.skull_ring = "off";
					Pchar.filled_pipe = "released";

					LAi_QuestDelay("skull_ring_release", 2.0);
				}
			}

			if(itmName == "filled_pipe")
			{
				if(IsEquipCharacterByItem(Pchar, "filled_pipe"))
				{
					//RELEASE
					PlaySound("OBJECTS\SHIPCHARGE\sail_damage3.wav");
					Pchar.filled_pipe = "released";
				}
				else
				{
					//EQUIP
					PlaySound("INTERFACE\cancel.wav");
					Pchar.filled_pipe = "equipped";

					if(IsEquipCharacterByItem(Pchar, "skull_ring")) RemoveCharacterEquip(Pchar, EQUIP_ITEM_TYPE);
					if(IsEquipCharacterByItem(Pchar, "moccasins")) RemoveCharacterEquip(Pchar, EQUIP_ITEM_TYPE);
					SetModel(Pchar, pchar.model, "man", "man", 1.8, true);
					Pchar.skull_ring = "off";

					LAi_QuestDelay("filled_pipe_equip", 0.1);
					LAi_QuestDelay("skull_ring_release", 2.0);
				}
			}

			bool ExtraUpdate = false; // PB
			if(itmName == "telescope")
			{
				if(CheckCharacterItem(Pchar,"LongRifle_W"))
				{
					PlaySound("PEOPLE\spyglass.wav");
					RemoveCharacterEquip (Pchar, GUN_ITEM_TYPE);
					TakeItemFromCharacter(Pchar, "telescope");
					TakeItemFromCharacter(Pchar, "LongRifle_W");
					GiveItem2Character   (Pchar, "LongRifle_WT");
					EquipCharacterByItem (Pchar, "LongRifle_WT");
					ExtraUpdate = true; // PB
				}
				else
				{
					if(CheckCharacterItem(Pchar,"LongRifle_C"))
					{
						PlaySound("PEOPLE\spyglass.wav");
						RemoveCharacterEquip (Pchar, GUN_ITEM_TYPE);
						TakeItemFromCharacter(Pchar, "telescope");
						TakeItemFromCharacter(Pchar, "LongRifle_C");
						GiveItem2Character   (Pchar, "LongRifle_CT");
						EquipCharacterByItem (Pchar, "LongRifle_CT");
						ExtraUpdate = true; // PB
					}
				}
			}

			if(itmName == "LongRifle_WT" && IsEquipedItem("LongRifle_WT"))
			{
				PlaySound("PEOPLE\key_box.wav");
				TakeItemFromCharacter(Pchar, "LongRifle_WT");
				GiveItem2Character(Pchar, "LongRifle_W");
				EquipCharacterByItem(Pchar, "LongRifle_W");
				GiveItem2Character(Pchar, "telescope");
				ExtraUpdate = true; // PB
			}

			if(itmName == "LongRifle_CT" && IsEquipedItem("LongRifle_CT"))
			{
				PlaySound("PEOPLE\key_box.wav");
				TakeItemFromCharacter(Pchar, "LongRifle_CT");
				GiveItem2Character  (Pchar, "telescope");
				GiveItem2Character  (Pchar, "LongRifle_C");
				EquipCharacterByItem(Pchar, "LongRifle_C");
				ExtraUpdate = true; // PB
			}

			if(itmName == "yarn" || itmName == "magnet")
			{
				if(CheckCharacterItem(Pchar,"yarn") && CheckCharacterItem(Pchar,"magnet"))
				{
					PlaySound("PEOPLE\clothes1.wav");
					TakeItemFromCharacter(Pchar, "yarn");
					TakeItemFromCharacter(Pchar, "magnet");
					GiveItem2Character(Pchar, "magnet2");
				}
				else
				{
					PlaySound("VOICE\ENGLISH\Poe_and.wav");
					Logit(TranslateString("","I'm not sure what to do with this item."));
					Logit(TranslateString("","Maybe something is missing?"));
					return;
				}
			}

			if(itmName == "needles" || itmName == "pliers")
			{
				if(CheckCharacterItem(Pchar,"needles") && CheckCharacterItem(Pchar,"pliers"))
				{
					PlaySound("INTERFACE\water_tap.wav");
					TakeItemFromCharacter(Pchar, "needles");
					TakeItemFromCharacter(Pchar, "pliers");
					GiveItem2Character(Pchar, "needles2");
				}
				else
				{
					PlaySound("VOICE\ENGLISH\Poe_and.wav");
					Logit(TranslateString("","I'm not sure what to do with this item."));
					Logit(TranslateString("","Maybe something is missing?"));
					return;
				}
			}

			if(itmName == "book61D")
			{
				PlaySound("INTERFACE\paper_small.wav");
				RemoveCharacterEquip(Pchar, EQUIP_ITEM_TYPE);
				TakeItemFromCharacter(Pchar, "book61D");
				GiveItem2Character(Pchar, "book61C2");
			}

			if(itmName == "book61C2")
			{
				PlaySound("INTERFACE\book_close.wav");
				RemoveCharacterEquip(Pchar, EQUIP_ITEM_TYPE);
				TakeItemFromCharacter(Pchar, "book61C2");
				GiveItem2Character(Pchar, "book61A");
			}
	//------------------------------------------------------------------------------

			if(itmName == "pistol204_P")
			{
				if(IsEquipCharacterByItem(Pchar, "pistol204_P"))
				{
					//RELEASE
					
					if(CheckCharacterItem(Pchar,"p_case_2C"))
					{
						RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
						TakeItemFromCharacter(Pchar, "pistol204_P");
						TakeItemFromCharacter(Pchar, "p_case_2C");
						GiveItem2Character(Pchar, "p_case_3");
						Pchar.p_case_status = "3";
					}
					if(CheckCharacterItem(Pchar,"p_case_1B"))
					{
						RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
						TakeItemFromCharacter(Pchar, "pistol204_P");
						TakeItemFromCharacter(Pchar, "p_case_1B");
						GiveItem2Character(Pchar, "p_case_2A");
						Pchar.p_case_status = "2A";
					}
					if(CheckCharacterItem(Pchar,"p_case_1C"))
					{
						RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
						TakeItemFromCharacter(Pchar, "pistol204_P");
						TakeItemFromCharacter(Pchar, "p_case_1C");
						GiveItem2Character(Pchar, "p_case_2B");
						Pchar.p_case_status = "2B";
					}
					if(CheckCharacterItem(Pchar,"p_case_0"))
					{
						RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
						TakeItemFromCharacter(Pchar, "pistol204_P");
						TakeItemFromCharacter(Pchar, "p_case_0");
						GiveItem2Character(Pchar, "p_case_1A");
						Pchar.p_case_status = "1A";
					}
					if(CheckCharacterItem(Pchar,"p_case_C"))
					{
						RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
					}
				}
				else
				{
					//EQUIP
					RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
					EquipCharacterByItem(Pchar, "pistol204_P");

					LAi_QuestDelay("pistol_204_load_check", 2.0);
				}
				ExtraUpdate = true; // PB
			}

			if(itmName == "cart_box_O")
			{
				PlaySound("INTERFACE\book_close.wav");
				TakenItems(Pchar, "cart_box_O", -100);

				if(IsEquipCharacterByItem(Pchar, "pistol204_P"))
				{
					GiveItem2Character(Pchar, "cart_box_C");
				}
				else
				{
					if(CheckCharacterItem(Pchar,"p_case_C"))
					{
						GiveItem2Character(Pchar, "cart_box_C");
					}
					else
					{
						//PISTOL NOT EQUIPPED, CASE IS OPEN

						if(CheckCharacterItem(Pchar,"p_case_2B"))
						{
							TakeItemFromCharacter(Pchar, "p_case_2B");
							GiveItem2Character(Pchar, "p_case_3");
							Pchar.p_case_status = "3";
						}
						if(CheckCharacterItem(Pchar,"p_case_1A"))
						{
							TakeItemFromCharacter(Pchar, "p_case_1A");
							GiveItem2Character(Pchar, "p_case_2A");
							Pchar.p_case_status = "2A";
						}
						if(CheckCharacterItem(Pchar,"p_case_1C"))
						{
							TakeItemFromCharacter(Pchar, "p_case_1C");
							GiveItem2Character(Pchar, "p_case_2C");
							Pchar.p_case_status = "2C";
						}
						if(CheckCharacterItem(Pchar,"p_case_0"))
						{
							TakeItemFromCharacter(Pchar, "p_case_0");
							GiveItem2Character(Pchar, "p_case_1B");
							Pchar.p_case_status = "1B";
						}
					}
				}

				ExtraUpdate = true; // PB
			}

			if(itmName == "caps_box_O")
			{
				PlaySound("PEOPLE\spyglass.wav");
				TakenItems(Pchar, "caps_box_O", -100);

				if(IsEquipCharacterByItem(Pchar, "pistol204_P"))
				{
					GiveItem2Character(Pchar, "caps_box_C");
				}
				else
				{
					if(CheckCharacterItem(Pchar,"p_case_C"))
					{
						GiveItem2Character(Pchar, "caps_box_C");
					}
					else
					{
						//PISTOL NOT EQUIPPED, CASE IS OPEN

						if(CheckCharacterItem(Pchar,"p_case_2A"))
						{
							TakeItemFromCharacter(Pchar, "p_case_2A");
							GiveItem2Character(Pchar, "p_case_3");
							Pchar.p_case_status = "3";
						}
						if(CheckCharacterItem(Pchar,"p_case_1A"))
						{
							TakeItemFromCharacter(Pchar, "p_case_1A");
							GiveItem2Character(Pchar, "p_case_2B");
							Pchar.p_case_status = "2B";
						}
						if(CheckCharacterItem(Pchar,"p_case_1B"))
						{
							TakeItemFromCharacter(Pchar, "p_case_1B");
							GiveItem2Character(Pchar, "p_case_2C");
							Pchar.p_case_status = "2C";
						}
						if(CheckCharacterItem(Pchar,"p_case_0"))
						{
							TakeItemFromCharacter(Pchar, "p_case_0");
							GiveItem2Character(Pchar, "p_case_1C");
							Pchar.p_case_status = "1C";
						}
					}
				}

				ExtraUpdate = true; // PB
			}

			if(itmName == "p_case_0")
			{
				PlaySound("INTERFACE\p_case_close.wav");
				TakeItemFromCharacter(Pchar, "p_case_0");
				GiveItem2Character(Pchar, "p_case_C");
				Pchar.p_case_status = "0";
				ExtraUpdate = true; // PB
			}

			if(itmName == "flagchest_empty")
			{
				PlaySound("PEOPLE\clothes1.wav");
				TakeItemFromCharacter(Pchar, "flagchest_empty");

				if(CheckAttribute(Pchar,"equip.blade") && HasSubStr(Pchar.equip.blade, "bladeflag_"))
			//	if (HasSubStr(Pchar.equip.blade, "bladeflag_"))
				{
					RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
					EquipCharacterByItem(Pchar, "bladeX4");
				}
				TakeItemFromCharacter(Pchar, "bladeflag_pir");
				TakeItemFromCharacter(Pchar, "bladeflag_pir2");
				TakeItemFromCharacter(Pchar, "bladeflag_HOL");
				TakeItemFromCharacter(Pchar, "bladeflag_ENG");
				TakeItemFromCharacter(Pchar, "bladeflag_FRA");
				TakeItemFromCharacter(Pchar, "bladeflag_POR");
				TakeItemFromCharacter(Pchar, "bladeflag_SPA");
				TakeItemFromCharacter(Pchar, "bladeflag_PRE");
				TakeItemFromCharacter(Pchar, "bladeflag_IRE");
				TakeItemFromCharacter(Pchar, "bladeflag_SWE");
				TakeItemFromCharacter(Pchar, "bladeflag_HOL2");
				TakeItemFromCharacter(Pchar, "bladeflag_AME");
				TakeItemFromCharacter(Pchar, "bladeflag_SPA2");

				GiveItem2Character(Pchar, "flagchest_openB");

				ExtraUpdate = true; // PB
			}

			if(itmName == "flagchest_openB")
			{
				PlaySound("INTERFACE\p_case_close.wav");
				TakeItemFromCharacter(Pchar, "flagchest_openB");
				GiveItem2Character(Pchar, "flagchest_closed");

				ExtraUpdate = true; // PB
			}

			if(itmName == "book69C")
			{
				PlaySound("INTERFACE\book_close.wav");
				TakeItemFromCharacter(Pchar, "book69C");
				GiveItem2Character(Pchar, "book69A");	
			}

			if(itmName == "BB_hatA2")
			{
		//		PlaySound("PEOPLE\clothes1.wav");

				if(IsEquipCharacterByItem(Pchar, "BB_hatA2"))
				{
					//RELEASE					

					if(CheckAttribute(Pchar,"model"))
					{
						switch(Pchar.model)
						{
							case "Howard_Pyle_hat":
								SetModel(Pchar, "Howard_Pyle", Pchar.model.animation, Pchar.sex, stf(Pchar.model.height), true);
							break;

							case "Howard_Pyle_hat_b":
								SetModel(Pchar, "Howard_Pyle_b", Pchar.model.animation, Pchar.sex, stf(Pchar.model.height), true);
							break;

							case "Howard_Pyle_hat_a":
								SetModel(Pchar, "Howard_Pyle_a", Pchar.model.animation, Pchar.sex, stf(Pchar.model.height), true);

							break;
						}
					}
				}
				else 
				{
					//EQUIP

					if(CheckAttribute(Pchar,"model"))
					{
						switch(Pchar.model)
						{
							case "Howard_Pyle":
								SetModel(Pchar, "Howard_Pyle_hat", Pchar.model.animation, Pchar.sex, stf(Pchar.model.height), true);
							break;

							case "Howard_Pyle_b":
								SetModel(Pchar, "Howard_Pyle_hat_b", Pchar.model.animation, Pchar.sex, stf(Pchar.model.height), true);
							break;

							case "Howard_Pyle_a":
								SetModel(Pchar, "Howard_Pyle_hat_a", Pchar.model.animation, Pchar.sex, stf(Pchar.model.height), true);
							break;
						}
					}	
				}

				LAi_QuestDelay("check_Pyle_hat", 0.01);	
		
			}

			if(itmName == "paper_clip")
			{
				PlaySound("INTERFACE\water_tap.wav");
				TakeItemFromCharacter(Pchar, "paper_clip");
				GiveItem2Character(Pchar, "paper_clip2");
				AddQuestRecord("KR_amulet","8");

		//		ExtraUpdate = true; // PB
			}

			if(itmName == "tailors_note")
			{
				PlaySound("INTERFACE\book_close.wav");
				TakeItemFromCharacter(Pchar, "tailors_note");
				GiveItem2Character(Pchar, "tailors_book");
			}

			if(itmName == "book70_0")
			{
				PlaySound("INTERFACE\book_close.wav");
				TakeItemFromCharacter(Pchar, "book70_0");
				TakeItemFromCharacter(Pchar, "book70_1");
				GiveItem2Character(Pchar, "book70");
			}

			if(itmName == "book70_11")
			{
				PlaySound("INTERFACE\book_close.wav");
				TakeItemFromCharacter(Pchar, "book70_10");
				TakeItemFromCharacter(Pchar, "book70_11");
				GiveItem2Character(Pchar, "book70");
			}

			if(itmName == "book71_10")
			{
				PlaySound("INTERFACE\paper.wav");
				TakeItemFromCharacter(Pchar, "book71_10");
				TakeItemFromCharacter(Pchar, "book71_11");
				GiveItem2Character(Pchar, "book71_9");
			}

			if(itmName == "book71_23")
			{
				PlaySound("INTERFACE\paper.wav");
				TakeItemFromCharacter(Pchar, "book71_22");
				TakeItemFromCharacter(Pchar, "book71_23");
				GiveItem2Character(Pchar, "book71_9");
			}

			if(itmName == "book72_richardsR")
			{
				PlaySound("INTERFACE\book_close.wav");
				TakeItemFromCharacter(Pchar, "book72_richardsL");
				TakeItemFromCharacter(Pchar, "book72_richardsR");
				GiveItem2Character(Pchar, "book72_closed");
			}

			if(itmName == "bandages_trousersQ")
			{
				if(Pchar.model == "Howard_Pyle_1")
				{
					PlaySound("PEOPLE\clothes1.wav");
					TakeItemFromCharacter(Pchar, "bandages_trousersQ");
					SetModel(PChar, "Howard_Pyle_2", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);

					LAi_QuestDelay("pchar_mhm", 0.01);
				}	
			}

			if(itmName == "shirt_shoes")
			{
				if(Pchar.model == "Howard_Pyle_2")
				{
					PlaySound("PEOPLE\clothes1.wav");
					TakeItemFromCharacter(Pchar, "shirt_shoes");
					SetModel(PChar, "Howard_Pyle_3", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);

					LAi_QuestDelay("pchar_mhm", 0.01);
				}	
			}

			if(itmName == "socks_sewing")
			{
				if(Pchar.model == "Howard_Pyle_3")
				{
					PlaySound("PEOPLE\clothes1.wav");
					TakeItemFromCharacter(Pchar, "socks_sewing");
					SetModel(PChar, "Howard_Pyle_4", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);

					LAi_QuestDelay("pchar_mhm", 0.01);
				}	
			}

			if(itmName == "waistcoat")
			{
				if(Pchar.model == "Howard_Pyle_4")
				{
					PlaySound("PEOPLE\clothes1.wav");
					TakeItemFromCharacter(Pchar, "waistcoat");
					SetModel(PChar, "Howard_Pyle_5", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);

					LAi_QuestDelay("pchar_mhm", 0.01);
				}	
			}

			if(itmName == "sash")
			{
				if(Pchar.model == "Howard_Pyle_5")
				{
					PlaySound("PEOPLE\clothes1.wav");
					TakeItemFromCharacter(Pchar, "sash");
					SetModel(PChar, "Howard_Pyle", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);

					LAi_QuestDelay("pchar_mhm", 0.01);
					LAi_QuestDelay("pchar_outfit_check", 0.1);	//if pistol20 is equipped etc
				}	
			}

			if(itmName == "red_uniform")
			{
				PlaySound("PEOPLE\clothes1.wav");
				TakeItemFromCharacter(Pchar, "red_uniform");
				Pchar.quest.red_uniform = "yes";

				if(CheckAttribute(Pchar,"model"))
				{
					switch(Pchar.model)
					{
						case "Pira4M_TUS_a":
							SetModel(PChar, "ShkiperM_U_a", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
						break;

						case "Pira4M_TUS_b":
							SetModel(PChar, "ShkiperM_U_b", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
						break;

						case "Pira4M_TUS":
							SetModel(PChar, "ShkiperM_U", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
						break;
					}
				}
				LAi_QuestDelay("pchar_very_nice", 1.0);
				
				LAi_QuestDelay("secret_room_finished_check", 0.1);
			}

			if(itmName == "toolbox_empty")
			{
				PlaySound("PEOPLE\blade_basket.wav");
				PlaySound("INTERFACE\klonk.wav");
				TakeItemFromCharacter(Pchar, "toolbox_empty");
				TakeItemFromCharacter(Pchar, "bladesaw");
				TakeItemFromCharacter(Pchar, "bladehammer");
				TakeNItems(Pchar,"nails", -8);
				TakeItemFromCharacter(Pchar, "bladeirontool");
				GiveItem2Character(Pchar, "toolbox_filled");
			}

			if(itmName == "book73_open")
			{
				PlaySound("INTERFACE\book_close.wav");
				TakeItemFromCharacter(Pchar, "book73_open");
				GiveItem2Character(Pchar, "book73_closed");
			}

			if(itmName == "port_stock" || itmName == "port_metal")
			{
				if(CheckAttribute(Pchar,"Portugize_phase"))
				{
					switch(Pchar.Portugize_phase)
					{
						case "1":
							if(CheckCharacterItem(Pchar,"port_tools"))
							{
								PlaySound("PEOPLE\chopchop.wav");
								TakeItemFromCharacter(Pchar, "port_stock");
								TakeItemFromCharacter(Pchar, "port_metal");
								GiveItem2Character(Pchar, "port_2");
								Pchar.Portugize_phase = "2";
							}
							else
							{
								if (PChar.sex == "man") { PlaySound("VOICE\ENGLISH\blaze_huh.wav"); }
								else PlaySound("VOICE\ENGLISH\gr_wench3_couldnt.wav");
								Logit(TranslateString("","I need Tools to assemble this thing."));
								return;
							}
						break;

						case "0":
							if (PChar.sex == "man") { PlaySound("VOICE\ENGLISH\blaze_sigh.wav"); }
							else PlaySound("VOICE\ENGLISH\gr_wench3_sigh.wav");
							Logit(TranslateString("","I don't have all parts yet."));
							return;
						break;
					}
				}
			}

			if(itmName == "port_rest")
			{
				if(CheckAttribute(Pchar,"Portugize_phase"))
				{
					switch(Pchar.Portugize_phase)
					{
						case "2":
							PlaySound("INTERFACE\cancel.wav");
							PlaySound("INTERFACE\cancel.wav");
							TakeItemFromCharacter(Pchar, "port_rest");
							TakeItemFromCharacter(Pchar, "port_2");
							GiveItem2Character(Pchar, "port_3");
							Pchar.Portugize_phase = "3";
						break;

						case "1":
							if(CheckCharacterItem(Pchar,"port_tools"))
							{
								if (PChar.sex == "man") { PlaySound("OBJECTS\DUEL\man_attack5.wav"); }
								else PlaySound("VOICE\ENGLISH\gr_wench3_angry.wav");
								Logit(TranslateString("","No, that's not the right part."));
								return;
							}
							else
							{
								if (PChar.sex == "man") { PlaySound("VOICE\ENGLISH\blaze_huh.wav"); }
								else PlaySound("VOICE\ENGLISH\gr_wench3_couldnt.wav");
								Logit(TranslateString("","I need Tools to assemble this thing."));
								return;
							}
						break;

						case "0":
							if (PChar.sex == "man") { PlaySound("VOICE\ENGLISH\blaze_sigh.wav"); }
							else PlaySound("VOICE\ENGLISH\gr_wench3_sigh.wav");
							Logit(TranslateString("","I don't have all parts yet."));
							return;
						break;
					}
				}
			}

			if(itmName == "port_magazine")
			{
				if(CheckAttribute(Pchar,"Portugize_phase"))
				{
					switch(Pchar.Portugize_phase)
					{
						case "3":
							PlaySound("PEOPLE\beltkey.wav");
							PlaySound("PEOPLE\beltkey.wav");
							TakeItemFromCharacter(Pchar, "port_magazine");
							TakeItemFromCharacter(Pchar, "port_3");
							GiveItem2Character(Pchar, "port_4");
							Pchar.Portugize_phase = "4";
						break;

						case "2":
							if (PChar.sex == "man") { PlaySound("OBJECTS\DUEL\man_attack5.wav"); }
							else PlaySound("VOICE\ENGLISH\gr_wench3_angry.wav");
							Logit(TranslateString("","No, that's not the right part."));
							return;
						break;

						case "1":
							if(CheckCharacterItem(Pchar,"port_tools"))
							{
								if (PChar.sex == "man") { PlaySound("OBJECTS\DUEL\man_attack5.wav"); }
								else PlaySound("VOICE\ENGLISH\gr_wench3_angry.wav");
								Logit(TranslateString("","No, that's not the right part."));
								return;
							}
							else
							{
								if (PChar.sex == "man") { PlaySound("VOICE\ENGLISH\blaze_huh.wav"); }
								else PlaySound("VOICE\ENGLISH\gr_wench3_couldnt.wav");
								Logit(TranslateString("","I need Tools to assemble this thing."));
								return;
							}
						break;

						case "0":
							if (PChar.sex == "man") { PlaySound("VOICE\ENGLISH\blaze_sigh.wav"); }
							else PlaySound("VOICE\ENGLISH\gr_wench3_sigh.wav");
							Logit(TranslateString("","I don't have all parts yet."));
							return;
						break;
					}
				}
			}

			if(itmName == "port_barrel")
			{
				if(CheckAttribute(Pchar,"Portugize_phase"))
				{
					switch(Pchar.Portugize_phase)
					{
						case "4":
							PlaySound("INTERFACE\bell_broken.wav");
							TakeItemFromCharacter(Pchar, "port_barrel");
							TakeItemFromCharacter(Pchar, "port_4");
							GiveItem2Character(Pchar, "port_5");
							Pchar.Portugize_phase = "5";
						break;

						case "3":
							if (PChar.sex == "man") { PlaySound("OBJECTS\DUEL\man_attack5.wav"); }
							else PlaySound("VOICE\ENGLISH\gr_wench3_angry.wav");
							Logit(TranslateString("","No, that's not the right part."));
							return;
						break;

						case "2":
							if (PChar.sex == "man") { PlaySound("OBJECTS\DUEL\man_attack5.wav"); }
							else PlaySound("VOICE\ENGLISH\gr_wench3_angry.wav");
							Logit(TranslateString("","No, that's not the right part."));
							return;
						break;

						case "1":
							if(CheckCharacterItem(Pchar,"port_tools"))
							{
								if (PChar.sex == "man") { PlaySound("OBJECTS\DUEL\man_attack5.wav"); }
								else PlaySound("VOICE\ENGLISH\gr_wench3_angry.wav");
								Logit(TranslateString("","No, that's not the right part."));
								return;
							}
							else
							{
								if (PChar.sex == "man") { PlaySound("VOICE\ENGLISH\blaze_huh.wav"); }
								else PlaySound("VOICE\ENGLISH\gr_wench3_couldnt.wav");
								Logit(TranslateString("","I need Tools to assemble this thing."));
								return;
							}
						break;

						case "0":
							if (PChar.sex == "man") { PlaySound("VOICE\ENGLISH\blaze_sigh.wav"); }
							else PlaySound("VOICE\ENGLISH\gr_wench3_sigh.wav");
							Logit(TranslateString("","I don't have all parts yet."));
							return;
						break;
					}
				}
			}

			if(itmName == "port_mechanism")
			{
				if(CheckAttribute(Pchar,"Portugize_phase"))
				{
					switch(Pchar.Portugize_phase)
					{
						case "5":
							PlaySound("PEOPLE\spyglass.wav");
							TakeItemFromCharacter(Pchar, "port_mechanism");
							TakeItemFromCharacter(Pchar, "port_5");
							TakeItemFromCharacter(Pchar, "port_tools");
							GiveItem2Character(Pchar, "portugize");
						
							LAi_QuestDelay("portugize_equip", 0.2);
							LAi_QuestDelay("delete_library_map", 0.5);
						break;

						case "4":
							if (PChar.sex == "man") { PlaySound("OBJECTS\DUEL\man_attack5.wav"); }
							else PlaySound("VOICE\ENGLISH\gr_wench3_angry.wav");
							Logit(TranslateString("","No, that's not the right part."));
							return;
						break;


						case "3":
							if (PChar.sex == "man") { PlaySound("OBJECTS\DUEL\man_attack5.wav"); }
							else PlaySound("VOICE\ENGLISH\gr_wench3_angry.wav");
							Logit(TranslateString("","No, that's not the right part."));
							return;
						break;

						case "2":
							if (PChar.sex == "man") { PlaySound("OBJECTS\DUEL\man_attack5.wav"); }
							else PlaySound("VOICE\ENGLISH\gr_wench3_angry.wav");
							Logit(TranslateString("","No, that's not the right part."));
							return;
						break;

						case "1":
							if(CheckCharacterItem(Pchar,"port_tools"))
							{
								if (PChar.sex == "man") { PlaySound("OBJECTS\DUEL\man_attack5.wav"); }
								else PlaySound("VOICE\ENGLISH\gr_wench3_angry.wav");
								Logit(TranslateString("","No, that's not the right part."));
								return;
							}
							else
							{
								if (PChar.sex == "man") { PlaySound("VOICE\ENGLISH\blaze_huh.wav"); }
								else PlaySound("VOICE\ENGLISH\gr_wench3_couldnt.wav");
								Logit(TranslateString("","I need Tools to assemble this thing."));
								return;
							}
						break;

						case "0":
							if (PChar.sex == "man") { PlaySound("VOICE\ENGLISH\blaze_sigh.wav"); }
							else PlaySound("VOICE\ENGLISH\gr_wench3_sigh.wav");
							Logit(TranslateString("","I don't have all parts yet."));
							return;
						break;
					}
				}
			}	
//JRH equip
		//<-- JRH

			I_EquipItem();
			// PB -->
			if(ExtraUpdate)
			{
				PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
				InterfaceStack.SelectMenu_node = "I_ITEMS";
				EndCancelInterface(false);
			}
			// PB <--
		}
		if(comName=="upstep" || comName=="deactivate")
		{
			SetCurrentNode("ITEMSLIST");
		}
	break;
// KK -->
	case "EXAMINE_BUTTON":
		if(comName=="activate" || comName=="click")
		{
			I_ExamineItem();
		}
		if(comName=="upstep" || comName=="deactivate")
		{
			SetCurrentNode("ITEMSLIST");
		}
	break;
// <-- KK
// JRH -->
	case "FLIP_BUTTON":
		if(comName=="activate" || comName=="click")
		{
			I_FlipItem();
		}
		if(comName=="upstep" || comName=="deactivate")
		{
			SetCurrentNode("ITEMSLIST");
		}
	break;
// <-- JRH
// Levis -->
	case "TOSS_BUTTON":
		if(comName=="activate" || comName=="click")
		{
			GameInterface.itemslist.currenttemp = nCurScroll;
			SetNodeUsing("MSC_CONFIRM_RECTANGLE", true);
			SetNodeUsing("MSC_TEXTWINDOW", true);
			SetNodeUsing("MSC_CONFIRM_YES_BUTTON", true);
			SetNodeUsing("MSC_CONFIRM_NO_BUTTON", true);
			SetCurrentNode("MSC_CONFIRM_NO_BUTTON");
			SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "MSC_CONFIRM_NO_BUTTON");
			SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "MSC_CONFIRM_YES_BUTTON");
			SetFormatedText("MSC_TEXTWINDOW", TranslateString("", "TossItemInterface"));
			SetFormatedText("MSC_TEXTWINDOW", "Are you sure you want to toss this item?");
		}
	break;
// <-- Levis
	case "ITEMSLIST":
		if(comName=="activate")
		{
			if(GetSelectable("EQUIP_BUTTON"))
			{
				SetCurrentNode("EQUIP_BUTTON");
			}
			if (GetSelectable("EXAMINE_BUTTON"))
			{
				SetCurrentNode("EXAMINE_BUTTON");
			}
			// JRH -->
			if (GetSelectable("FLIP_BUTTON"))
			{
				SetCurrentNode("FLIP_BUTTON");
			}
			// <-- JRH
			//Levis -->
			if (GetSelectable("TOSS_BUTTON"))
			{
				SetCurrentNode("TOSS_BUTTON");
			}
			//<-- Levis
		}
		if(comName=="upstep")
		{
			if( SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE,"TEXTWINDOW",6, true) )
			{	SendMessage(&GameInterface,"lslls",MSG_INTERFACE_MSG_TO_NODE,"TEXTWINDOW",-1,3, comName);
			}
		}
		if(comName=="downstep")
		{
			if( SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE,"TEXTWINDOW",6, false) )
			{	SendMessage(&GameInterface,"lslls",MSG_INTERFACE_MSG_TO_NODE,"TEXTWINDOW", -1,3, comName);
			}
		}
	break;
	case "B_WEAPON": if(comName=="activate" || comName=="click") { ChangeSelectedScroll(GUN_ITEM_TYPE);    UpdateItemData(); } break;
	case "B_POTION": if(comName=="activate" || comName=="click") { ChangeSelectedScroll(POTION_ITEM_TYPE); UpdateItemData(); } break;
	case "B_ITEMS":  if(comName=="activate" || comName=="click") { ChangeSelectedScroll(OBJECT_ITEM_TYPE); UpdateItemData(); } break;
	case "B_MAP":    if(comName=="activate" || comName=="click") { ChangeSelectedScroll(MAP_ITEM_TYPE);    UpdateItemData(); } break;
	case "B_QUEST":  if(comName=="activate" || comName=="click") { ChangeSelectedScroll(QUEST_ITEM_TYPE);  UpdateItemData(); } break;
	}
}
// Levis -->

void I_TossItem()
{
	Remove_Confirm();
	int currentitem = sti(GameInterface.itemslist.currenttemp);
	ref PChar = GetMainCharacter();
	string itemid = GetItemIDByOrder(currentitem);
	string curItemGroup = Items[GetItemIndex(itemid)].groupID
	TakeItemFromCharacter(Pchar, itemid);
	DeleteAttribute(&GameInterface,"itemslist");
	//FillSelectedScroll(curItemGroup);
	if(!GetSelectable("B_WEAPON")) { curItemGroup = GUN_ITEM_TYPE; }
	if(!GetSelectable("B_POTION")) { curItemGroup = POTION_ITEM_TYPE; }
	if(!GetSelectable("B_ITEMS")) { curItemGroup = OBJECT_ITEM_TYPE; }
	if(!GetSelectable("B_MAP")) { curItemGroup = MAP_ITEM_TYPE; } // KK
	if(!GetSelectable("B_QUEST")) { curItemGroup = QUEST_ITEM_TYPE; }
	FillSelectedScroll(curItemGroup);
	nCurScroll = currentitem;
	GameInterface.itemslist.current = nCurScroll;
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"ITEMSLIST",nCurScroll);
	UpdateItemData();
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_REFRESH_SCROLL,"ITEMSLIST");
	trace("ITEMS: Tossed item: "+itemid);
}

void Remove_Confirm()
{
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);
	SetNodeUsing("MSC_CONFIRM_RECTANGLE", false);
	SetNodeUsing("MSC_TEXTWINDOW", false);
	SetNodeUsing("MSC_CONFIRM_YES_BUTTON", false);
	SetNodeUsing("MSC_CONFIRM_NO_BUTTON", false);
	SetCurrentNode("ITEMSLIST");
}
// <-- Levis

void I_EquipItem()
{
	int currentitem = nCurScroll; // KK
	ProcEquipPress();
	DeleteAttribute(&GameInterface,"itemslist");
	string curItemGroup = OBJECT_ITEM_TYPE;
	if(!GetSelectable("B_WEAPON"))	{ curItemGroup = GUN_ITEM_TYPE; }
	if(!GetSelectable("B_POTION"))	{ curItemGroup = POTION_ITEM_TYPE; }
	if(!GetSelectable("B_ITEMS"))	{ curItemGroup = OBJECT_ITEM_TYPE; }
	if(!GetSelectable("B_MAP"))		{ curItemGroup = MAP_ITEM_TYPE; } // KK
	if(!GetSelectable("B_QUEST"))	{ curItemGroup = QUEST_ITEM_TYPE; }
	FillSelectedScroll(curItemGroup);
// KK -->
	nCurScroll = currentitem;
	GameInterface.itemslist.current = nCurScroll;
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"ITEMSLIST",nCurScroll);
	UpdateItemData();
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_REFRESH_SCROLL,"ITEMSLIST");
// <-- KK
	SetCurrentNode("ITEMSLIST");
}

// KK -->
void I_ExamineItem()
{
	string itmName = GetItemIDByOrder(nCurScroll);
	aref itmRef;
	if (Items_FindItem(itmName, &itmRef) >= 0 && CheckAttribute(itmRef, "index")) GameInterface.ItemIdx = itmRef.index;

	ref PChar;
	PChar = GetMainCharacter();
	if(itmName == "notebook")
	{
		if(!CheckAttribute(Pchar,"quest.study_notebook") || Pchar.quest.study_notebook != "yes")
		{
			LAi_QuestDelay("notebook", 0.1);
		}
	}

	if(itmName == "map")
	{
		if(CheckAttribute(Pchar,"quest.check_pelagomap") && Pchar.quest.check_pelagomap == "enabled")
		{
			AddQuestRecord("Woodes_Rogers_quest", "2");
			Pchar.quest.check_pelagomap = "disabled";
		}

		if(GetAttribute(pchar, "Eden_map") == "on1" || GetAttribute(pchar, "Eden_map") == "on2")
		{
			Pchar.Eden_map = "on2";
			LAi_QuestDelay("I_know_which_island", 0.1);
		}

		if(GetAttribute(pchar, "Defoe_map") == "on1" || GetAttribute(pchar, "Defoe_map") == "on2")
		{
			Pchar.Defoe_map = "on2";
			LAi_QuestDelay("I_know_which_island", 0.1);
		}

	// PB: Only One Map Interface -->
		PostEvent("LaunchIAfterFrame",1,"sl", "A_MAP", 2);
		InterfaceStack.SelectMenu_node = "A_MAP";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		PChar.inventory = true;
		return;
	}
//JRH -->
	if(itmName == "book52")
	{
		PlaySound("INTERFACE\book_open.wav");
		TakeItemFromCharacter(Pchar, "book52");
		GiveItem2Character(Pchar, "book53");
		AddQuestRecord("The_message","3");
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book53")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book53");
		GiveItem2Character(Pchar, "book54");
		AddQuestRecord("The_message","4");
		Pchar.quest.book53 = "yes";
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;
	}

	if(itmName == "wrinkled_paper")
	{
		if(Pchar.model == "William Legrand")
		{
			LAi_SetPlayerType(pchar);
			PlaySound("INTERFACE\paper.wav");
			TakeItemFromCharacter(Pchar, "wrinkled_paper");
			GiveItem2Character(Pchar, "bird_sketch");
			AddQuestRecord("The_message","6");
			Pchar.quest.Fort_password = "yes";
			PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
			InterfaceStack.SelectMenu_node = "I_ITEMS";
			interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
			EndCancelInterface(false);
			return;	
		}
		else return;	
	}

	if(itmName == "bird_sketch_doc")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "bird_sketch_doc");
		GiveItem2Character(Pchar, "bird_backside");
		//AddQuestRecord("The_message","6");
		//Pchar.quest.Fort_password = "yes";
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "crypto1")
	{
		PlaySound("INTERFACE\paper.wav");

		if(!CheckAttribute(Pchar,"Lut_G_cipher") || Pchar.Lut_G_cipher != "done")
		{
			Pchar.Lut_G_cipher = "done";

			LAi_QuestDelay("Lut_G_cipher", 0.1);
		}
	}

	if(itmName == "crypto2")
	{
		PlaySound("INTERFACE\paper.wav");

		if(CheckAttribute(Pchar,"quest.beeline") && Pchar.quest.beeline == "unknown")
		{
			Pchar.quest.beeline = "50_feet";
			Characters[GetCharacterIndex("Edgar Allan Poe")].dialog.CurrentNode  = "beeline_50_feet";
			
			LAi_QuestDelay("beeline_50_feet", 0.1);
		}

		if(!CheckAttribute(Pchar,"quest.bye_bye_Poe") || Pchar.quest.bye_bye_Poe != "done")
		{
			LAi_QuestDelay("bye_bye_Poe", 1.0);
		}
	}

	if(itmName == "med_bag1_doc_YES")
	{
		PlaySound("PEOPLE\clothes1.wav");
		TakeItemFromCharacter(Pchar, "med_bag1_doc_YES");
		GiveItem2Character(Pchar, "med_bag1_obj");
		GiveItem2Character(Pchar, "med_bag2_doc");
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "med_bag1_doc_NO")
	{
		PlaySound("VOICE\ENGLISH\claire_hmm.wav");

		LAi_QuestDelay("med_woman_sees_all", 0.5);
		return;
	}

	if(itmName == "med_bag2_doc")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "med_bag2_doc");
		GiveItem2Character(Pchar, "med_bag2_obj");
		GiveItem2Character(Pchar, "crypto_excel");
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "crypto_excel")
	{
		PlaySound("INTERFACE\paper.wav");
		
		if(!CheckAttribute(Pchar,"quest.message7") || Pchar.quest.message7 != "done")
		{
			AddQuestRecord("The_message","7");
			Pchar.quest.message7 = "done";
		}

		if(!CheckCharacterItem(Pchar,"med_bag2_out"))
		{
			TakeItemFromCharacter(Pchar, "med_bag1_obj");
			TakeItemFromCharacter(Pchar, "med_bag2_obj");
			GiveItem2Character(Pchar, "med_bag2_out");
		}
	}

	//LOCKED
	if(itmName == "detective_kit1")
	{
		if(CheckCharacterItem(Pchar,"D_hairpin"))
		{
			PlaySound("INTERFACE\detective_kit_open.wav");
			TakeItemFromCharacter(Pchar, "detective_kit1");
			
			if(CheckAttribute(Pchar,"quest.detective_kit") && Pchar.quest.detective_kit == "keys")
			{
				GiveItem2Character(Pchar, "detective_kit2");
			}

			if(CheckAttribute(Pchar,"quest.detective_kit") && Pchar.quest.detective_kit == "empty")
			{
				GiveItem2Character(Pchar, "detective_kit3");
			}
			
			if(CheckAttribute(Pchar,"quest.detective_kit") && Pchar.quest.detective_kit == "filled")
			{
				GiveItem2Character(Pchar, "detective_kit5");
			}

			PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
			InterfaceStack.SelectMenu_node = "I_ITEMS";
			interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
			EndCancelInterface(false);
			return;
		}
		else 
		{
			PlaySound("PEOPLE\beltkey.wav");
			return;
		}
	}

	//EMPTY BUT WITH KEYS
	if(itmName == "detective_kit2")
	{
		PlaySound("AMBIENT\JAIL\chains2.wav");
		TakeItemFromCharacter(Pchar, "detective_kit2");
		GiveItem2Character(Pchar, "detective_kit3");
		GiveItem2Character(Pchar, "D_key23");

		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;
	}

	//FILLED
	if(itmName == "detective_kit5")
	{
		PlaySound("PEOPLE\key_box.wav");
		TakeItemFromCharacter(Pchar, "detective_kit5");
		GiveItem2Character(Pchar, "detective_kit3");
		GiveItem2Character(Pchar, "D_feather");
		GiveItem2Character(Pchar, "D_scissors");
		GiveItem2Character(Pchar, "D_compasses");
		GiveItem2Character(Pchar, "D_scalpel");
		GiveItem2Character(Pchar, "D_magnifying");
		GiveItem2Character(Pchar, "D_tweezers");

		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;
	}

	if(itmName == "doc1A")
	{
		PlaySound("INTERFACE\paper_small.wav");
		TakeItemFromCharacter(Pchar, "doc1A");
		GiveItem2Character(Pchar, "doc1B");

		if(!CheckAttribute(Pchar,"quest.gunpowder4") || Pchar.quest.gunpowder4 != "done")
		{
			AddQuestRecord("Gunpowder","1");
			Pchar.quest.gunpowder4 = "done";
		}
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;
	}

	if(itmName == "doc2A")
	{
		PlaySound("INTERFACE\book_open.wav");
		TakeItemFromCharacter(Pchar, "doc2A");
		GiveItem2Character(Pchar, "doc2B");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;
	}

	if(itmName == "doc2B")
	{
		PlaySound("INTERFACE\book_open.wav");
		TakeItemFromCharacter(Pchar, "doc2B");
		GiveItem2Character(Pchar, "doc2C");
		GiveItem2Character(Pchar, "doc3C");

		if(!CheckAttribute(Pchar,"quest.gunpowder2") || Pchar.quest.gunpowder2 != "done")
		{
			AddQuestRecord("Gunpowder","2");
			Pchar.quest.gunpowder2 = "done";
		}
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;
	}

	if(itmName == "doc3C")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "doc2C");
		TakeItemFromCharacter(Pchar, "doc3C");

		if(CheckAttribute(Pchar,"quest.fireworks_recipe") && Pchar.quest.fireworks_recipe == "yes")
		{
			GiveItem2Character(Pchar, "doc2E");

			if(!CheckAttribute(Pchar,"quest.gunpowder3") || Pchar.quest.gunpowder3 != "done")
			{
				AddQuestRecord("Gunpowder","3");
				Pchar.quest.gunpowder3 = "done";
				AddQuestRecord("Fireworks","2");
			}
		}
		else GiveItem2Character(Pchar, "doc2D");

		GiveItem2Character(Pchar, "doc3D");

		if(!CheckAttribute(Pchar,"quest.gunpowder5") || Pchar.quest.gunpowder5 != "done")
		{
			AddQuestRecord("Gunpowder","5");
			Pchar.quest.gunpowder5 = "done";
		}
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;
	}

	if(itmName == "doc4A")
	{
		PlaySound("INTERFACE\book_open.wav");
		TakeItemFromCharacter(Pchar, "doc4A");
		GiveItem2Character(Pchar, "doc4B");
		
		if(!CheckAttribute(Pchar,"quest.charcoal4") || Pchar.quest.charcoal4 != "done")
		{
			//AddQuestRecord("Charcoal","2");
			AddQuestRecord("Charcoal","5");
			AddQuestRecord("Charcoal","6");
			AddQuestRecord("Charcoal","7");
			AddQuestRecord("Charcoal","8");
			AddQuestRecord("Charcoal","9");

			Pchar.quest.charcoal4 = "done";
		}

		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;
	}

	if(itmName == "doc5A")
	{
		PlaySound("AMBIENT\TAVERN\open_bottle.wav");
		TakeItemFromCharacter(Pchar, "doc5A");
		GiveItem2Character(Pchar, "doc5B");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;
	}

	if(itmName == "doc5B")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "doc5B");
		GiveItem2Character(Pchar, "doc5C");
		
		if(!CheckAttribute(Pchar,"quest.salpeter5") || Pchar.quest.salpeter5 != "done")
		{
			//AddQuestRecord("Salpeter","5");
			AddQuestRecord("Salpeter","7");
			AddQuestRecord("Salpeter","8");
			AddQuestRecord("Salpeter","9");
			AddQuestRecord("Salpeter","10");
			AddQuestRecord("Salpeter","11");
			AddQuestRecord("Salpeter","12");
			AddQuestRecord("Salpeter","13");
			Pchar.quest.salpeter5 = "done";
		}

		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;
	}

	if(itmName == "doc6A")
	{
		PlaySound("INTERFACE\paper_small.wav");
		TakeItemFromCharacter(Pchar, "doc6A");
		GiveItem2Character(Pchar, "doc6B");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;
	}

	if(itmName == "doc6B")
	{
		PlaySound("INTERFACE\paper_small.wav");
		TakeItemFromCharacter(Pchar, "doc6B");
		GiveItem2Character(Pchar, "doc6C");
		
		if(!CheckAttribute(Pchar,"quest.sulfur3") || Pchar.quest.sulfur3 != "done")
		{
			//AddQuestRecord("Sulfur","3");
			AddQuestRecord("Sulfur","5");
			AddQuestRecord("Sulfur","6");
			AddQuestRecord("Sulfur","7");
			AddQuestRecord("Sulfur","8");
			AddQuestRecord("Sulfur","9");
			AddQuestRecord("Sulfur","10");
			AddQuestRecord("Sulfur","11");
			Pchar.quest.sulfur3 = "done";
		}

		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;
	}

	if(itmName == "doc60A")
	{
		PlaySound("INTERFACE\paper_small.wav");
		TakeItemFromCharacter(Pchar, "doc60A");
		GiveItem2Character(Pchar, "doc60B");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;
	}

	if(itmName == "doc60B")
	{
		PlaySound("INTERFACE\paper_small.wav");
		TakeItemFromCharacter(Pchar, "doc60B");
		GiveItem2Character(Pchar, "doc60C");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;
	}

	if(itmName == "doc60C")
	{
		PlaySound("INTERFACE\paper_small.wav");
		TakeItemFromCharacter(Pchar, "doc60C");
		GiveItem2Character(Pchar, "doc60D");
		AddQuestRecord("KR_letter","5");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;
	}

	if(itmName == "book55A")
	{
		PlaySound("INTERFACE\button3.wav");
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book55A");
		GiveItem2Character(Pchar, "book55B");
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book55B")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book55B");

		if(CheckAttribute(Pchar,"quest.key29") && Pchar.quest.key29 == "picked_up")
		{
			GiveItem2Character(Pchar, "book55D");
		}
		else 
		{
			GiveItem2Character(Pchar, "book55C");
		}
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "dried_mushrooms")
	{
		PlaySound("PEOPLE\clothes3.wav");
		PlaySound("PEOPLE\clothes3.wav");
		PlaySound("PEOPLE\grass_noise.wav");
		TakeItemFromCharacter(Pchar, "dried_mushrooms");
		GiveItem2Character(Pchar, "pulverized_mushrooms");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "knitting_basket")
	{
		PlaySound("PEOPLE\basket.wav");
		TakeItemFromCharacter(Pchar, "knitting_basket");
		GiveItem2Character(Pchar, "knitting");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "knitting")
	{
		PlaySound("INTERFACE\button3.wav");
		TakeItemFromCharacter(Pchar, "knitting");
		GiveItem2Character(Pchar, "yarn");
		GiveItem2Character(Pchar, "needles");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book61A")
	{
		PlaySound("INTERFACE\book_open.wav");
		TakeItemFromCharacter(Pchar, "book61A");
		GiveItem2Character(Pchar, "book61B");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book61B")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book61B");

		if(CheckCharacterItem(Pchar,"book61D"))
		{
			GiveItem2Character(Pchar, "book61C2");
		}
		else GiveItem2Character(Pchar, "book61C1");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book61C1")
	{
		PlaySound("INTERFACE\paper_small.wav");
		TakeItemFromCharacter(Pchar, "book61C1");
		GiveItem2Character(Pchar, "book61C2");
		GiveItem2Character(Pchar, "book61D");

		AddQuestRecord("Claude_Frollo's_mission","5");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}
//---------------------------------------------------------------------
	if(itmName == "p_package")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "p_package");
		GiveItem2Character(Pchar, "p_case_C");

		PlaySound("VOICE\ENGLISH\Poe_look.wav");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "p_case_C")
	{
		PlaySound("INTERFACE\p_case_open.wav");
		TakeItemFromCharacter(Pchar, "p_case_C");

		if(CheckAttribute(Pchar,"p_case_status"))
		{
			switch(Pchar.p_case_status)
			{
				case "3": GiveItem2Character(Pchar, "p_case_3"); break;
				case "2A": GiveItem2Character(Pchar, "p_case_2A"); break;
				case "2B": GiveItem2Character(Pchar, "p_case_2B"); break;
				case "2C": GiveItem2Character(Pchar, "p_case_2C"); break;
				case "1A": GiveItem2Character(Pchar, "p_case_1A"); break;
				case "1B": GiveItem2Character(Pchar, "p_case_1B"); break;
				case "1C": GiveItem2Character(Pchar, "p_case_1C"); break;
				case "0": GiveItem2Character(Pchar, "p_case_0"); break;
			}
		}

		if(!CheckAttribute(Pchar,"pistol_case") || Pchar.pistol_case != "already_seen")
		{
			Pchar.pistol_case = "already_seen";
			PlaySound("VOICE\ENGLISH\Poe_ooh.wav");
			AddQuestRecord("Weapons","10");
		}

		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "p_case_3")
	{
		PlaySound("OBJECTS\DUEL\reload1.wav");
		TakeItemFromCharacter(Pchar, "p_case_3");
		GiveItem2Character(Pchar, "p_case_2C");
		GiveItem2Character(Pchar, "pistol204_P");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "p_case_2A")
	{
		PlaySound("OBJECTS\DUEL\reload1.wav");
		TakeItemFromCharacter(Pchar, "p_case_2A");
		GiveItem2Character(Pchar, "p_case_1B");
		GiveItem2Character(Pchar, "pistol204_P");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "p_case_2B")
	{
		PlaySound("OBJECTS\DUEL\reload1.wav");
		TakeItemFromCharacter(Pchar, "p_case_2B");
		GiveItem2Character(Pchar, "p_case_1C");
		GiveItem2Character(Pchar, "pistol204_P");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "p_case_2C")
	{
		PlaySound("PEOPLE\clothes4.wav");
		TakeItemFromCharacter(Pchar, "p_case_2C");
		GiveItem2Character(Pchar, "p_case_1C");
		GiveItem2Character(Pchar, "cart_box_C");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "p_case_1A")
	{
		PlaySound("OBJECTS\DUEL\reload1.wav");
		TakeItemFromCharacter(Pchar, "p_case_1A");
		GiveItem2Character(Pchar, "p_case_0");
		GiveItem2Character(Pchar, "pistol204_P");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "p_case_1B")
	{
		PlaySound("PEOPLE\clothes4.wav");
		TakeItemFromCharacter(Pchar, "p_case_1B");
		GiveItem2Character(Pchar, "p_case_0");
		GiveItem2Character(Pchar, "cart_box_C");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "p_case_1C")
	{
		PlaySound("INTERFACE\button1.wav");
		TakeItemFromCharacter(Pchar, "p_case_1C");
		GiveItem2Character(Pchar, "p_case_0");
		GiveItem2Character(Pchar, "caps_box_C");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "cart_box_C")
	{
		PlaySound("INTERFACE\book_open.wav");
		TakeItemFromCharacter(Pchar, "cart_box_C");
		TakenItems(Pchar, "cart_box_O", makeint(Pchar.gpb_status));
		
		LAi_QuestDelay("pistol_204_load_check", 2.0);

		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "caps_box_C")
	{
		PlaySound("INTERFACE\water_tap.wav");
		TakeItemFromCharacter(Pchar, "caps_box_C");
		TakenItems(Pchar, "caps_box_O", makeint(Pchar.cap_status));
		
		LAi_QuestDelay("pistol_204_load_check", 2.0);

		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "poe_manuscript")
	{
		PlaySound("INTERFACE\paper.wav");
		
		if(!CheckAttribute(Pchar,"manuscript") || Pchar.manuscript != "already_seen")
		{
			Pchar.manuscript = "already_seen";

			LAi_QuestDelay("skeletons_talk", 1.0);
		}
	}

	if(itmName == "flagchest_closed")
	{
		PlaySound("INTERFACE\p_case_open.wav");
		TakeItemFromCharacter(Pchar, "flagchest_closed");
		GiveItem2Character(Pchar, "flagchest_openA");

		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;
	}

	if(itmName == "flagchest_openA")
	{
		PlaySound("PEOPLE\clothes1.wav");
		TakeItemFromCharacter(Pchar, "flagchest_openA");
		GiveItem2Character(Pchar, "flagchest_empty");
	
		if(CheckAttribute(Pchar,"tower.flag"))
		{
			if(pchar.tower.flag != "pir") GiveItem2Character(Pchar, "bladeflag_pir");
			if(pchar.tower.flag != "pir2") GiveItem2Character(Pchar, "bladeflag_pir2");
			if(pchar.tower.flag != "HOL") GiveItem2Character(Pchar, "bladeflag_HOL");
			if(pchar.tower.flag != "ENG") GiveItem2Character(Pchar, "bladeflag_ENG");
			if(pchar.tower.flag != "FRA") GiveItem2Character(Pchar, "bladeflag_FRA");
			if(pchar.tower.flag != "POR") GiveItem2Character(Pchar, "bladeflag_POR");
			if(pchar.tower.flag != "SPA") GiveItem2Character(Pchar, "bladeflag_SPA");
			if(pchar.tower.flag != "PRE") GiveItem2Character(Pchar, "bladeflag_PRE");
			if(pchar.tower.flag != "IRE") GiveItem2Character(Pchar, "bladeflag_IRE");
			if(pchar.tower.flag != "SWE") GiveItem2Character(Pchar, "bladeflag_SWE");
			if(pchar.tower.flag != "HOL2") GiveItem2Character(Pchar, "bladeflag_HOL2");
			if(pchar.tower.flag != "AME") GiveItem2Character(Pchar, "bladeflag_AME");
			if(pchar.tower.flag != "SPA2") GiveItem2Character(Pchar, "bladeflag_SPA2");
		}

		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book69A")
	{
		PlaySound("INTERFACE\book_open.wav");
		TakeItemFromCharacter(Pchar, "book69A");
		GiveItem2Character(Pchar, "book69B");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;
	}

	if(itmName == "book69B")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book69B");
		GiveItem2Character(Pchar, "book69C");
		AddQuestRecord("KR_logbook","7");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;
	}

	if(itmName == "BB_hatA1")
	{
		PlaySound("PEOPLE\clothes1.wav");
		TakeItemFromCharacter(Pchar, "BB_hatA1");
		GiveItem2Character(Pchar, "BB_hatB");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;
	}

	if(itmName == "BB_hatB")
	{
		PlaySound("PEOPLE\clothes1.wav");
		TakeItemFromCharacter(Pchar, "BB_hatB");
		GiveItem2Character(Pchar, "BB_hatC");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;
	}

	if(itmName == "BB_hatC")
	{
		PlaySound("PEOPLE\clothes1.wav");
		PlaySound("INTERFACE\took_item.wav");
		TakeItemFromCharacter(Pchar, "BB_hatC");
		GiveItem2Character(Pchar, "BB_hatA2");
		GiveItem2Character(Pchar, "BB_key");

		AddQuestRecord("KR_tricorn","5");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;
	}

	if(itmName == "auction_list_roll")
	{
		PlaySound("INTERFACE\carpet_move.wav");
		TakeItemFromCharacter(Pchar, "auction_list_roll");
		GiveItem2Character(Pchar, "auction_list_open");

		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;
	}

	if(itmName == "auction_list_open")
	{
		PlaySound("INTERFACE\paper.wav");
		Pchar.Kr_quest = "6_locations";
		Locations[FindLocation("Kristiania_center")].reload.l9.disable = 0;
		locations[FindLocation("Kristiania_townhall_entre")].id.label = "Townhall office";
		ChangeCharacterAddressGroup(CharacterFromID("Kr_chapel_monk"), "Kristiania_chapel", "goto", "goto12");

		LAi_QuestDelay("switch_auction_lists", 0.1);
	}

	if(itmName == "tailors_book")
	{
		PlaySound("INTERFACE\paper_small.wav");
		TakeItemFromCharacter(Pchar, "tailors_book");
		GiveItem2Character(Pchar, "tailors_note");

		Pchar.jungle_path = "know_how";
		AddQuestRecord("KR_logbook","5");

		//now the way to the red house is enabled
		Locations[FindLocation("KR_jungle_8")].reload.l3.go = "KR_jungle_13";
		Locations[FindLocation("KR_jungle_8")].reload.l3.emerge = "reload3";
		Locations[FindLocation("KR_jungle_8")].reload.l5.go = "KR_jungle_13";
		Locations[FindLocation("KR_jungle_8")].reload.l5.emerge = "reload3";

		Locations[FindLocation("KR_jungle_10")].reload.l1.go = "KR_jungle_13";
		Locations[FindLocation("KR_jungle_10")].reload.l1.emerge = "reload1";
		Locations[FindLocation("KR_jungle_10")].reload.l6.go = "KR_jungle_13";
		Locations[FindLocation("KR_jungle_10")].reload.l6.emerge = "reload1";

		pchar.quest.check_logbook.win_condition.l1 = "location";
		pchar.quest.check_logbook.win_condition.l1.location = "Redhouse_room";
		pchar.quest.check_logbook.win_condition = "check_logbook";

		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;
	}

	if(itmName == "book70_start")
	{
		PlaySound("INTERFACE\book_open.wav");
		TakeItemFromCharacter(Pchar, "book70_start");
		GiveItem2Character(Pchar, "book70_0");
		GiveItem2Character(Pchar, "book70_1");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book70")
	{
		PlaySound("INTERFACE\book_open.wav");
		TakeItemFromCharacter(Pchar, "book70");
		GiveItem2Character(Pchar, "book70_0");
		GiveItem2Character(Pchar, "book70_1");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book70_1")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book70_0"); 
		TakeItemFromCharacter(Pchar, "book70_1");
		GiveItem2Character(Pchar, "book70_2"); 
		GiveItem2Character(Pchar, "book70_3");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book70_2")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book70_2"); 
		TakeItemFromCharacter(Pchar, "book70_3");
		GiveItem2Character(Pchar, "book70_0"); 
		GiveItem2Character(Pchar, "book70_1");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book70_3")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book70_2"); 
		TakeItemFromCharacter(Pchar, "book70_3");
		GiveItem2Character(Pchar, "book70_4"); 
		GiveItem2Character(Pchar, "book70_5");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book70_4")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book70_4"); 
		TakeItemFromCharacter(Pchar, "book70_5");
		GiveItem2Character(Pchar, "book70_2"); 
		GiveItem2Character(Pchar, "book70_3");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book70_5")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book70_4"); 
		TakeItemFromCharacter(Pchar, "book70_5");
		GiveItem2Character(Pchar, "book70_6"); 
		GiveItem2Character(Pchar, "book70_7");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book70_6")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book70_6"); 
		TakeItemFromCharacter(Pchar, "book70_7");
		GiveItem2Character(Pchar, "book70_4"); 
		GiveItem2Character(Pchar, "book70_5");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book70_7")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book70_6"); 
		TakeItemFromCharacter(Pchar, "book70_7");
		GiveItem2Character(Pchar, "book70_8"); 
		GiveItem2Character(Pchar, "book70_9");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book70_8")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book70_8"); 
		TakeItemFromCharacter(Pchar, "book70_9");
		GiveItem2Character(Pchar, "book70_6"); 
		GiveItem2Character(Pchar, "book70_7");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book70_9")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book70_8"); 
		TakeItemFromCharacter(Pchar, "book70_9");
		GiveItem2Character(Pchar, "book70_10"); 
		GiveItem2Character(Pchar, "book70_11");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book70_10")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book70_10"); 
		TakeItemFromCharacter(Pchar, "book70_11");
		GiveItem2Character(Pchar, "book70_8"); 
		GiveItem2Character(Pchar, "book70_9");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book71_9_start")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book71_9_start");
		GiveItem2Character(Pchar, "book71_10"); 
		GiveItem2Character(Pchar, "book71_11");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book71_9")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book71_9");
		GiveItem2Character(Pchar, "book71_10"); 
		GiveItem2Character(Pchar, "book71_11");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book71_11")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book71_10");
		TakeItemFromCharacter(Pchar, "book71_11");
		GiveItem2Character(Pchar, "book71_12"); 
		GiveItem2Character(Pchar, "book71_13");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book71_12")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book71_12");
		TakeItemFromCharacter(Pchar, "book71_13");
		GiveItem2Character(Pchar, "book71_10"); 
		GiveItem2Character(Pchar, "book71_11");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book71_13")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book71_12");
		TakeItemFromCharacter(Pchar, "book71_13");
		GiveItem2Character(Pchar, "book71_14"); 
		GiveItem2Character(Pchar, "book71_15");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book71_14")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book71_14");
		TakeItemFromCharacter(Pchar, "book71_15");
		GiveItem2Character(Pchar, "book71_12"); 
		GiveItem2Character(Pchar, "book71_13");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book71_15")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book71_14");
		TakeItemFromCharacter(Pchar, "book71_15");
		GiveItem2Character(Pchar, "book71_16"); 
		GiveItem2Character(Pchar, "book71_17");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book71_16")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book71_16");
		TakeItemFromCharacter(Pchar, "book71_17");
		GiveItem2Character(Pchar, "book71_14"); 
		GiveItem2Character(Pchar, "book71_15");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book71_17")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book71_16");
		TakeItemFromCharacter(Pchar, "book71_17");
		GiveItem2Character(Pchar, "book71_18"); 
		GiveItem2Character(Pchar, "book71_19");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book71_18")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book71_18");
		TakeItemFromCharacter(Pchar, "book71_19");
		GiveItem2Character(Pchar, "book71_16"); 
		GiveItem2Character(Pchar, "book71_17");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book71_19")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book71_18");
		TakeItemFromCharacter(Pchar, "book71_19");
		GiveItem2Character(Pchar, "book71_20"); 
		GiveItem2Character(Pchar, "book71_21");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book71_20")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book71_20");
		TakeItemFromCharacter(Pchar, "book71_21");
		GiveItem2Character(Pchar, "book71_18"); 
		GiveItem2Character(Pchar, "book71_19");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book71_21")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book71_20");
		TakeItemFromCharacter(Pchar, "book71_21");
		GiveItem2Character(Pchar, "book71_22"); 
		GiveItem2Character(Pchar, "book71_23");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book71_22")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book71_22");
		TakeItemFromCharacter(Pchar, "book71_23");
		GiveItem2Character(Pchar, "book71_20"); 
		GiveItem2Character(Pchar, "book71_21");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book72_package")
	{
		PlaySound("PEOPLE\clothes1.wav");
		TakeItemFromCharacter(Pchar, "book72_package");
		GiveItem2Character(Pchar, "book72_closed"); 

		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book72_closed")
	{
		if(CheckAttribute(Pchar,"note72") && Pchar.note72 == "read")
		{
			PlaySound("INTERFACE\book_open.wav");
			TakeItemFromCharacter(Pchar, "book72_closed");
			GiveItem2Character(Pchar, "book72_openL"); 
			GiveItem2Character(Pchar, "book72_openR"); 
			TakeItemFromCharacter(Pchar, "note72");
		//	Pchar.note72 = "not_read";

			PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
			InterfaceStack.SelectMenu_node = "I_ITEMS";
			interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
			EndCancelInterface(false);
			return;
		}
		else 
		{
			PlaySound("INTERFACE\paper_small.wav");
			Pchar.note72 = "read";
		}	
	}

	if(itmName == "book72_openL")
	{
		PlaySound("INTERFACE\paper_small.wav");
	}

	if(itmName == "book72_openR")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book72_openL");
		TakeItemFromCharacter(Pchar, "book72_openR");
		GiveItem2Character(Pchar, "book72_edenL"); 
		GiveItem2Character(Pchar, "book72_edenR"); 

		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book72_edenL")
	{
		PlaySound("INTERFACE\paper_small.wav");

		if(!CheckAttribute(Pchar,"book72_edenL") || Pchar.book72_edenL != "read")
		{
			Pchar.book72_edenL = "read";
			AddQuestRecord("Charles_Eden", "2");
			Pchar.eden_info = "start";
			ChangeCharacterAddressGroup(characterFromID("Edmund Christobel Shaw"), "Grand_Cayman_townhall", "goto", "goto12");
			LAi_SetStayType(characterFromID("Edmund Christobel Shaw"));
			//these open to Estate
			Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.box.box1 = 0.8;
			Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.goto.box1 = 0.8;
		}
	}

	if(itmName == "book72_edenR")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book72_edenL");
		TakeItemFromCharacter(Pchar, "book72_edenR");
		GiveItem2Character(Pchar, "book72_caesarL"); 
		GiveItem2Character(Pchar, "book72_caesarR"); 

		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book72_caesarL")
	{
		PlaySound("INTERFACE\paper_small.wav");

		if(!CheckAttribute(Pchar,"book72_caesarL") || Pchar.book72_caesarL != "read")
		{
			Pchar.book72_caesarL = "read";
			AddQuestRecord("Caesar", "3");
		}
	}

	if(itmName == "book72_caesarR")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book72_caesarL");
		TakeItemFromCharacter(Pchar, "book72_caesarR");
		GiveItem2Character(Pchar, "book72_handsL"); 
		GiveItem2Character(Pchar, "book72_handsR"); 

		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book72_handsL")
	{
		PlaySound("INTERFACE\paper_small.wav");

		if(!CheckAttribute(Pchar,"book72_handsL") || Pchar.book72_handsL != "read")
		{
			Pchar.book72_handsL = "read";
			AddQuestRecord("Israel_Hands", "3");
		
			SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);
			Characters[GetCharacterIndex("Hands")].name = TranslateString("","Beggar");
			Characters[GetCharacterIndex("Hands")].lastname = TranslateString("","");
			characters[GetCharacterIndex("Hands")].dialog.CurrentNode = "beggar";
			LAi_SetPoorType(CharacterFromID("Hands"));
			ChangeCharacterAddressGroup(CharacterFromID("Hands"), "Willemstad_town_3", "officers", "reload7_1");

			LAi_QuestDelay("start_Hands_Willemstad", 0.1);
		}
	}

	if(itmName == "book72_handsR")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book72_handsL");
		TakeItemFromCharacter(Pchar, "book72_handsR");
		GiveItem2Character(Pchar, "book72_richardsL"); 
		GiveItem2Character(Pchar, "book72_richardsR"); 

		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book72_richardsL")
	{
		PlaySound("INTERFACE\paper_small.wav");

		if(!CheckAttribute(Pchar,"book72_richardsL") || Pchar.book72_richardsL != "read")
		{
			Pchar.book72_richardsL = "read";
			AddQuestRecord("Blackbeards_crew","3");
			AddQuestRecord("Blackbeards_crew","5");

			//open wr_cave_shore here
			Island_SetReloadEnableLocal("Redmond", "reload_3", true);
			Locations[FindLocation("wr_cave_shore")].models.always.locators = "Shore04_l_JRHsea";

			LAi_QuestDelay("Vane_Richards_from game", 1.0);
			LAi_QuestDelay("Vane_Richards_from_jumpstart_and_game", 2.0);
		}
	}

	if(itmName == "newspaper1")
	{
		PlaySound("INTERFACE\paper_small.wav");
		Pchar.newspaper1 = "read";

		LAi_QuestDelay("return_newspaper1", 0.1);
		LAi_QuestDelay("read_all_newspapers", 0.1);
	}
	
	if(itmName == "newspaper2")
	{
		PlaySound("INTERFACE\paper_small.wav");

		if(!CheckAttribute(Pchar,"newspaper2") || Pchar.newspaper2 != "read")
		{
			Pchar.newspaper2 = "read";
			AddQuestRecord("Caesar","2");
			SetQuestHeader("Blackbeards_crew");
			AddQuestRecord("Blackbeards_crew","1");
		}

		LAi_QuestDelay("return_newspaper2", 0.1);
		LAi_QuestDelay("read_all_newspapers", 0.1);
	}

	if(itmName == "newspaper3")
	{
		PlaySound("INTERFACE\paper_small.wav");
		
		if(!CheckAttribute(Pchar,"newspaper3") || Pchar.newspaper3 != "read")
		{
			Pchar.newspaper3 = "read";
			AddQuestRecord("Richards","2");
			AddQuestRecord("Israel_Hands","2");
			AddQuestRecord("Blackbeards_crew","2");

			ChangeCharacterAddressGroup(CharacterFromID("Odel"), "Smugglers_Tavern", "goto", "goto17");

			pchar.quest.Odel_dialog.win_condition.l1 = "locator";
			pchar.quest.Odel_dialog.win_condition.l1.location = "Smugglers_Tavern";
			pchar.quest.Odel_dialog.win_condition.l1.locator_group = "goto";
			pchar.quest.Odel_dialog.win_condition.l1.locator = "goto17";
			pchar.quest.Odel_dialog.win_condition = "Odel_dialog";
		}

		LAi_QuestDelay("return_newspaper3", 0.1);
		LAi_QuestDelay("read_all_newspapers", 0.1);
	}

	if(itmName == "bandages_trousersX")
	{
		PlaySound("PEOPLE\clothes1.wav");
		PlaySound("INTERFACE\took_item.wav");
		TakeItemFromCharacter(Pchar, "bandages_trousersX");
		GiveItem2Character(Pchar, "bandages_trousersQ");
		GiveItem2Character(Pchar, "key36");

		SetLocatorRadius(locations[FindLocation("wr_farm_alchemy")], "box", "box8", 0.6);	
		SetLocatorRadius(locations[FindLocation("wr_farm_alchemy")], "reload", "reload2", 0.0001);
		SetLocatorRadius(locations[FindLocation("wr_farm_alchemy2")], "box", "box17", 0.7);	
		SetLocatorRadius(locations[FindLocation("wr_farm_alchemy2")], "reload", "reload2", 0.0001);

		Locations[FindLocation("wr_farm_alchemy")].locators_radius.box.box8 = 0.6;
		Locations[FindLocation("wr_farm_alchemy")].locators_radius.reload.reload2 = 0.0001;
		Locations[FindLocation("wr_farm_alchemy2")].locators_radius.box.box17 = 0.7;
		Locations[FindLocation("wr_farm_alchemy2")].locators_radius.reload.reload2 = 0.0001;	


		SetLocatorRadius(locations[FindLocation("wr_farm_servant")], "box", "box5", 0.7);	
		SetLocatorRadius(locations[FindLocation("wr_farm_servant")], "reload", "reload2", 0.0001);
		SetLocatorRadius(locations[FindLocation("wr_farm_alchemy2")], "box", "box18", 0.7);	
		SetLocatorRadius(locations[FindLocation("wr_farm_alchemy2")], "reload", "reload3", 0.0001);		

		Locations[FindLocation("wr_farm_servant")].locators_radius.box.box5 = 0.7;
		Locations[FindLocation("wr_farm_servant")].locators_radius.reload.reload2 = 0.0001;
		Locations[FindLocation("wr_farm_alchemy2")].locators_radius.box.box18 = 0.7;
		Locations[FindLocation("wr_farm_alchemy2")].locators_radius.reload.reload3 = 0.0001;

		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "package")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "package");
		GiveItem2Character(Pchar, "notebook"); 
		GiveItem2Character(Pchar, "sealed_map"); 

	//	AddQuestRecord("Secrets", "6");
			
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "notebook")
	{
		PlaySound("INTERFACE\book_open.wav");
		if(!CheckAttribute(Pchar,"quest.study_notebook") || Pchar.quest.study_notebook != "yes")
		{
			Pchar.quest.study_notebook = "yes";
			PlaySound("INTERFACE\notebook_01.wav");
			PlaySound("INTERFACE\notebook_01.wav");

			SetQuestHeader("Benjamin_Hornigold");
			AddQuestRecord("Benjamin_Hornigold", "1");
		//	CloseQuestHeader("Benjamin_Hornigold");

			SetQuestHeader("Caesar");
			AddQuestRecord("Caesar", "1");

			SetQuestHeader("Israel_Hands");
			AddQuestRecord("Israel_Hands", "1");

			SetQuestHeader("Charles_Eden");
			AddQuestRecord("Charles_Eden", "1");

			SetQuestHeader("Richards");
			AddQuestRecord("Richards", "1");

			SetQuestHeader("Johnson");
			AddQuestRecord("Johnson", "1");		//blank

			LAi_QuestDelay("secret_room_finished_check", 0.1);
		}
	}
//pÃ¤r BB1
	if(itmName == "sealed_map")
	{
		if(IsEquipCharacterByItem(Pchar, "folding_knife"))
		{
			PlaySound("INTERFACE\paper_small.wav");
			TakeItemFromCharacter(Pchar, "sealed_map");
			GiveItem2Character(Pchar, "mapBB1"); 

			Logit(TranslateString("","You've received e new item"));
			PlaySound("INTERFACE\important_item.wav");

			if(!CheckAttribute(Pchar,"quest.study_mapBB1") || Pchar.quest.study_mapBB1 != "yes")
			{
				AddQuestRecord("Benjamin_Hornigold", "2");
			}
		}
		else PlaySound("VOICE\ENGLISH\blaze_huh.wav");

		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "mapBB1")
	{
		if(GetAttribute(pchar, "mapBB1") == "info")
		{
			//do nothing
		}
		else
		{
			DeleteQuestHeader("Benjamin_Hornigold");
			AddQuestRecord("Benjamin_Hornigold", "3");
			CloseQuestHeader("Benjamin_Hornigold");	
			Pchar.quest.study_mapBB1 = "yes";
			Pchar.mapBB1 = "info";

			LAi_QuestDelay("secret_room_finished_check", 0.1);
		}
	}

	if(itmName == "mapBB2A")
	{
		if(GetAttribute(pchar, "Caesar_map") == "cleaning")
		{
			//do nothing
		}
		else
		{
			Pchar.Caesar_map = "cleaning";
			Pchar.Hands_map = "off";
			AddQuestRecord("Caesar", "17");
		
			LAi_QuestDelay("clean_up_map", 0.1);
		}
	}

	if(itmName == "mapBB2B")
	{
		if(GetAttribute(pchar, "mapBB2B") == "info")
		{
			//do nothing
		}
		else
		{
			Pchar.mapBB2B = "info";
			DeleteQuestHeader("Caesar");
			AddQuestRecord("Caesar","17");
			AddQuestRecord("Caesar","18");
			CloseQuestHeader("Caesar");
		}
	}

	if(itmName == "mapBB3")
	{
		if(GetAttribute(pchar, "Eden_map") == "off")
		{
			//do nothing
		}
		else
		{
			Pchar.Eden_map = "on1";
			AddQuestRecord("Charles_Eden", "11");

			LAi_QuestDelay("which_island", 0.1);
		}
	}

	if(itmName == "mapBB4A")
	{
		if(CheckAttribute(Pchar,"monastary") && Pchar.monastary == "dont_disturb")
		{
			AddQuestRecord("Richards", "24");
		}
		else
		{
			if(Locations[FindLocation("BB_crypt2_2")].reload.l2.disable == 0)
			{
				AddQuestRecord("Richards", "24");
			}
			else
			{
				PlaySound("INTERFACE\paper_small.wav");
				TakeItemFromCharacter(Pchar, "mapBB4A");
				GiveItem2Character(Pchar, "mapBB4A_back");

				PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
				InterfaceStack.SelectMenu_node = "I_ITEMS";
				interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
				EndCancelInterface(false);
				return;
			}	
		}
	}

	if(itmName == "mapBB4A_back")
	{
		PlaySound("INTERFACE\paper_small.wav");
		TakeItemFromCharacter(Pchar, "mapBB4A_back");
		GiveItem2Character(Pchar, "mapBB4A");

		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "mapBB4B")
	{
		AddQuestRecord("Richards", "25");
	}

	if(itmName == "mapBB4C")
	{
		if(GetAttribute(pchar, "mapBB4C") == "info")
		{
			//do nothing
		}
		else
		{
			Pchar.mapBB4C = "info";
			DeleteQuestHeader("Richards");
			AddQuestRecord("Richards","23");
			CloseQuestHeader("Richards");
		}
	}

	if(itmName == "mapBB5A")
	{
		if(GetAttribute(pchar, "Hands_map") == "cleaning")
		{
			//do nothing
		}
		else
		{
			Pchar.Hands_map = "cleaning";
			Pchar.Caesar_map = "off";
			AddQuestRecord("Israel_Hands", "13");
		
			LAi_QuestDelay("clean_up_map", 0.1);
		}
	}

	if(itmName == "mapBB5B")
	{
		if(GetAttribute(pchar, "mapBB5B") == "info")
		{
			//do nothing
		}
		else
		{
			Pchar.mapBB5B = "info";
			DeleteQuestHeader("Israel_Hands");
			AddQuestRecord("Israel_Hands", "14");
			CloseQuestHeader("Israel_Hands");
		}
	}

	if(itmName == "mapBB6")
	{
		if(GetAttribute(pchar, "Defoe_map") == "off")
		{
			//do nothing
		}
		else
		{
			Pchar.Defoe_map = "on1";
			AddQuestRecord("Johnson", "5");

			LAi_QuestDelay("which_island", 0.1);
		}
	}

	if(itmName == "mapWR1")
	{
		//blue letters
		if(GetAttribute(pchar, "WR1_map") == "on")
		{
			LAi_QuestDelay("return_to_defoe12", 0.1);	//Kristiania
		}
		else
		{
			Pchar.WR1_map = "on";
			LAi_SetSitType(Pchar);

			LAi_QuestDelay("return_to_defoe11", 0.1);	//Saint_X		
		}
	}

	if(itmName == "mapWR2")
	{
		LAi_QuestDelay("return_to_defoe16", 0.1);
	}

	if(itmName == "mapWR3")
	{
		LAi_QuestDelay("return_to_defoe20", 0.1);
	}

	if(itmName == "mapWR4")
	{
		LAi_QuestDelay("return_to_defoe24", 0.1);
	}

	if(itmName == "mapWR5")
	{
		if(GetAttribute(pchar, "WR5_map") == "done")
		{
			//nothing more happens
		}
		else LAi_QuestDelay("return_to_defoe29", 0.1);
	}

	if(itmName == "toolbox_filled")
	{
		PlaySound("PEOPLE\basket.wav");
		PlaySound("INTERFACE\metal_fall.wav");
		TakeItemFromCharacter(Pchar, "toolbox_filled");
		GiveItem2Character(Pchar, "toolbox_empty");

		GiveItem2Character(Pchar, "bladesaw");
		GiveItem2Character(Pchar, "bladehammer");
		TakeNItems(Pchar,"nails", 8);
		GiveItem2Character(Pchar, "bladeirontool");
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "book73_closed")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "book73_closed");
		GiveItem2Character(Pchar, "book73_open"); 
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "long_johns")
	{
		PlaySound("OBJECTS\SHIPCHARGE\sail_damage1.wav");
		TakeItemFromCharacter(Pchar, "long_johns");
		GiveItem2Character(Pchar, "long_johns_map"); 
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "long_johns_map")
	{
		PlaySound("INTERFACE\paper_small.wav");
		TakeItemFromCharacter(Pchar, "long_johns_map");
		GiveItem2Character(Pchar, "mapBB1"); 
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "bandana")
	{
		PlaySound("PEOPLE\clothes1.wav");
		TakeItemFromCharacter(Pchar, "bandana");
		GiveItem2Character(Pchar, "bandana_key"); 
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "bandana_key")
	{
		PlaySound("INTERFACE\took_item.wav");
		TakeItemFromCharacter(Pchar, "bandana_key");
		GiveItem2Character(Pchar, "key17"); 
		
		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}

	if(itmName == "engineer_letter1")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "engineer_letter1");
		GiveItem2Character(Pchar, "engineer_letter2");

		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;
	}

	if(itmName == "engineer_letter2")
	{
		PlaySound("INTERFACE\paper.wav");
		TakeItemFromCharacter(Pchar, "engineer_letter2");
		GiveItem2Character(Pchar, "engineer_letter3");

		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;
	}

	if(itmName == "engineer_letter3")
	{
		PlaySound("INTERFACE\paper.wav");
		SetQuestHeader("Beginning_Engineer")
		AddQuestRecord("Beginning_Engineer", "1");
	}

	if(itmName == "mapCartagena_Library")
	{
		PlaySound("INTERFACE\paper.wav");
		AddQuestRecord("Beginning_Engineer", "5");
	}

//JRH examine
	
//<-- JRH
	
	//Levis Skill Books -->
	if(itmRef.groupID == BOOK_ITEM_TYPE)
	{
		PostEvent("LaunchIAfterFrame",1,"sl", "I_BOOK", 2);
		InterfaceStack.SelectMenu_node = "I_BOOK";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;
	}
	//Levis Skill Books <--

	PostEvent("LaunchIAfterFrame",1,"sl", "I_MAP", 2);
	InterfaceStack.SelectMenu_node = "I_MAP";
	interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
	EndCancelInterface(false);
}
// <-- KK

// JRH -->
void I_FlipItem()
{
	string itmName = GetItemIDByOrder(nCurScroll);
	aref itmRef;
	if (Items_FindItem(itmName, &itmRef) >= 0 && CheckAttribute(itmRef, "index")) GameInterface.ItemIdx = itmRef.index;
	ref PChar;
	PChar = GetMainCharacter();

	if(itmName == "luckydimeA" || itmName == "luckydimeB")
	{
		PlaySound("INTERFACE\flip_coin.wav");
		TakeItemFromCharacter(Pchar, "luckydimeA");
		TakeItemFromCharacter(Pchar, "luckydimeB");
		
		if(rand(1) <1)
		{
			GiveItem2Character(Pchar, "luckydimeA"); 
		}
		else GiveItem2Character(Pchar, "luckydimeB");

		PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
		InterfaceStack.SelectMenu_node = "I_ITEMS";
		interfaceResultCommand = RC_INTERFACE_ITEMS_EXIT;
		EndCancelInterface(false);
		return;	
	}
}
// <-- JRH

void ChangeSelectedScroll(string curItemGroup)
{
	DeleteAttribute(&GameInterface,"itemslist");

    // JRH remove ghost ammo -->
	ref curchar;
	if(CheckAttribute(GetMainCharacter(),"Interface.Fellow")) { curchar = CharacterFromId(characters[GetMainCharacterIndex()].Interface.Fellow); }
	else { curchar = GetMainCharacter(); }

	if(ENABLE_AMMOMOD == 1)
	{
		int gp = GetCharacterItem(curchar, "gunpowder");
		if(gp == 0)
		{
			TakenItems(curchar, "gunpowder", 1); TakenItems(curchar, "gunpowder", -1);
		}

		int pb = GetCharacterItem(curchar, "pistolbullets");
		if(pb == 0)
		{
			TakenItems(curchar, "pistolbullets", 1); TakenItems(curchar, "pistolbullets", -1);
		}

		int pg = GetCharacterItem(curchar, "pistolgrapes");
		if(pg == 0)
		{
			TakenItems(curchar, "pistolgrapes", 1); TakenItems(curchar, "pistolgrapes", -1);
		}

		int mb = GetCharacterItem(curchar, "musketbullets");
		if(mb == 0)
		{
			TakenItems(curchar, "musketbullets", 1); TakenItems(curchar, "musketbullets", -1);
		}

		if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0 || sti(GetStorylineVar(FindCurrentStoryline(), "BUG_PUZZLES")) > 0)
		{
			int ca = GetCharacterItem(curchar, "cartridges");
			if(ca == 0)
			{
				TakenItems(curchar, "cartridges", 1); TakenItems(curchar, "cartridges", -1);
			}
			int gpb = GetCharacterItem(curchar, "cart_box_O");
			if(gpb == 0)
			{
				TakenItems(curchar, "cart_box_O", 1); TakenItems(curchar, "cart_box_O", -1);
			}
			int cap = GetCharacterItem(curchar, "caps_box_O");
			if(cap == 0)
			{
				TakenItems(curchar, "caps_box_O", 1); TakenItems(curchar, "caps_box_O", -1);
			}
		}

		int ar = GetCharacterItem(curchar, "bladearrows");
		if(ar == 0)
		{
			TakenItems(curchar, "bladearrows", 1); TakenItems(curchar, "bladearrows", -1);
		}

		int ar2 = GetCharacterItem(curchar, "arrows2");
		if(ar2 == 0)
		{
			TakenItems(curchar, "arrows2", 1); TakenItems(curchar, "arrows2", -1);
		}
		int ro = GetCharacterItem(curchar, "rockets");
		if(ro == 0)
		{
			TakenItems(curchar, "rockets", 1); TakenItems(curchar, "rockets", -1);
		}
	}
    // <-- JRH

	FillSelectedScroll(curItemGroup);
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"ITEMSLIST",-1);
	SetCurrentNode("ITEMSLIST");
	SetSelectable("B_WEAPON",true);
	SetSelectable("B_POTION",true);
	SetSelectable("B_ITEMS",true);
	SetSelectable("B_MAP",true); // KK
	SetSelectable("B_QUEST",true);
	switch(curItemGroup)
	{
		case GUN_ITEM_TYPE: SetSelectable("B_WEAPON",false); CreateStringCheckCase(true,"fakeTitle",XI_ConvertString("IntWeapon"),"interface_title",COLOR_NORMAL,320,5,SCRIPT_ALIGN_CENTER,1.0,true); break;
		case POTION_ITEM_TYPE: SetSelectable("B_POTION",false); CreateStringCheckCase(true,"fakeTitle",XI_ConvertString("IntMedicine"),"interface_title",COLOR_NORMAL,320,5,SCRIPT_ALIGN_CENTER,1.0,true); break;
		case OBJECT_ITEM_TYPE: SetSelectable("B_ITEMS",false); CreateStringCheckCase(true,"fakeTitle",XI_ConvertString("IntItems"),"interface_title",COLOR_NORMAL,320,5,SCRIPT_ALIGN_CENTER,1.0,true); break;
		case MAP_ITEM_TYPE: SetSelectable("B_MAP",false); CreateStringCheckCase(true,"fakeTitle",XI_ConvertString("IntMap"),"interface_title",COLOR_NORMAL,320,5,SCRIPT_ALIGN_CENTER,1.0,true); break; // KK
		case QUEST_ITEM_TYPE: SetSelectable("B_QUEST",false); CreateStringCheckCase(true,"fakeTitle",XI_ConvertString("IntQuest"),"interface_title",COLOR_NORMAL,320,5,SCRIPT_ALIGN_CENTER,1.0,true); break;
	}
}

void UpdateItemData()
{
//	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"CONTEXTHELP",0);

	string attributeName = "pic" + (nCurScroll+1);
	if( !CheckAttribute(&GameInterface,"itemslist."+attributeName+".itemID") )
	{
		GameInterface.strings.ItemName = ""; // KK
		SetFormatedText("TEXTWINDOW","");
		return;
	}

	aref itemARef;
	if( Items_FindItem(GameInterface.itemslist.(attributeName).itemID,&itemARef)<0 )
	{
		GameInterface.strings.ItemName = ""; // KK
		SetFormatedText("TEXTWINDOW","");
		return;
	}

	string newLineStr = GlobalStringConvert("newline");
	string itmDescribe = "";
	string strTmp;
	string Quality = "";
	if( CheckAttribute(itemARef,"name") ) // NK, was checking attr "describe"
	{
		if( GetAttribute(itemARef,"groupID") == QUEST_ITEM_TYPE)
		{
			GameInterface.strings.ItemName = PreprocessText(TranslateString("", itemARef.name)); // PB
		}
		else
		{
			GameInterface.strings.ItemName = GetAssembledString(TranslateString("", itemARef.name), itemARef); // KK
		}
	}
	if( CheckAttribute(itemARef,"groupID") )
	{
        // scheffnow - weaponsmod -->
  	    // NK moved above if
        // scheffnow - weaponsmod <--
		switch(itemARef.groupID)
		{
			case GUN_ITEM_TYPE:
				// scheffnow - weaponsmod -->
				if (CheckAttribute(itemARef,"QualityName"))
				{
					// LDH added quality "q" translation string - 07May09
					Quality = TranslateString("", "q"+itemARef.QualityName) + " ";
				}
				GameInterface.strings.ItemName = Quality + GameInterface.strings.ItemName; // KK
				// scheffnow - weaponsmod <--
				itmDescribe = GetAssembledString(TranslateString("", "weapon gun parameters"), itemARef) + newLineStr;
			break;
			case BLADE_ITEM_TYPE:
				// scheffnow - weaponsmod -->
				if (CheckAttribute(itemARef,"QualityName"))
				{
					// LDH added quality "q" translation string - 07May09
					Quality = TranslateString("", "q"+itemARef.QualityName) + " ";
				}
				GameInterface.strings.ItemName = Quality + GameInterface.strings.ItemName; // KK
				// scheffnow - weaponsmod <--
				itmDescribe = GetAssembledString(TranslateString("", "weapon blade parameters"), itemARef) + newLineStr; // KK
			break;
			// GreatZen -->
			case ARMOR_ITEM_TYPE:
				itmDescribe = GetAssembledString(TranslateString("", "weapon armor parameters"),itemARef) + newLineStr;
			break;
			// GreatZen <--
			
		}
	}
	else
	{	if( CheckAttribute(itemARef,"potion") )
		{
			itmDescribe = TranslateString("", "Potion parameters")+":";
			if( CheckAttribute(itemARef,"potion.health") )
			{
				itmDescribe += " "+TranslateString("", "health value");
				if(stf(itemARef.potion.health)>=0)
				{	itmDescribe += "+" + sti(itemARef.potion.health) + ".";
				} else
				{	itmDescribe += sti(itemARef.potion.health) + ".";
				}
			}
			itmDescribe += newLineStr;
		}
	}
	// KK itmDescribe += newLineStr;
	if( CheckAttribute(itemARef,"describe") )
	{
		if( GetAttribute(itemARef,"groupID") == QUEST_ITEM_TYPE)
		{
			itmDescribe = GetAssembledString(itmDescribe,itemARef) + PreprocessText(TranslateString("", itemARef.describe)) + GetItemBonuses(itemARef.id); // PB
		}
		else
		{
			itmDescribe = GetAssembledString(itmDescribe,itemARef) + GetAssembledString(TranslateString("", itemARef.describe), itemARef) + GetItemBonuses(itemARef.id); // NK
		}
	}

	SetFormatedText("TEXTWINDOW",itmDescribe);

	SetNodeUsing("EXAMINE_BUTTON", false); // KK

	//Levis -->
	SetNodeUsing("TOSS_BUTTON", true);
	bool TossEnable = true;
	if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES" )) > 0)	TossEnable = false; // JRH
	if(sti(GetStorylineVar(FindCurrentStoryline(), "BUG_PUZZLES")) > 0)	TossEnable = false; // JRH
	if(sti(GetAttribute(itemARef, "price")) <= 1)						TossEnable = false; // PB
	if(GetAttribute(itemARef, "id")    == "bladeX4")					TossEnable = false;
	if(GetAttribute(itemARef, "id")    == "map")						TossEnable = false;
	if(GetAttribute(itemARef, "id")    == "cursedcoin")					TossEnable = false;
	if(GetAttribute(itemARef, "id")    == "albatross")					TossEnable = false;
	if(GetAttribute(itemARef, "id")    == "telescope")					TossEnable = false;
	if(!GetSelectable("B_QUEST"))										TossEnable = false;
	SetSelectable("TOSS_BUTTON",	TossEnable);
	//Levis <--

	if( CheckAttribute(itemARef,"groupID") )
	{
// KK -->
		if (itemARef.groupID == MAP_ITEM_TYPE || itemARef.groupID == DOCUMENT_ITEM_TYPE || itemARef.groupID == BOOK_ITEM_TYPE
		|| itemARef.groupID == EXAMINE_ITEM_TYPE || itemARef.groupID == OPEN_ITEM_TYPE) {
			//JRH: DOCUMENT_ITEM_TYPE
			SetNodeUsing("EQUIP_BUTTON", false);
			SetNodeUsing("FLIP_BUTTON", false);
			SetNodeUsing("EXAMINE_BUTTON", true);
			return;
		}
// <-- KK
// JRH -->
		if (itemARef.groupID == FLIP_ITEM_TYPE) {
			SetNodeUsing("EQUIP_BUTTON", false);
			SetNodeUsing("EXAMINE_BUTTON", false);
			SetNodeUsing("FLIP_BUTTON", true);
			return;
		}
// <-- JRH

		if (itemARef.groupID!=BLADE_ITEM_TYPE && itemARef.groupID!=GUN_ITEM_TYPE && itemARef.groupID!=ARMOR_ITEM_TYPE && itemARef.groupID!=SPYGLASS_ITEM_TYPE
		&& itemARef.groupID!=FLASK_ITEM_TYPE && itemARef.groupID!=POUCH_ITEM_TYPE && itemARef.groupID!=LOCKPICK_ITEM_TYPE
		&& itemARef.groupID!=CLOCK_ITEM_TYPE && itemARef.groupID!=COMPASS_ITEM_TYPE && itemARef.groupID!=BELT_ITEM_TYPE
		&& itemARef.groupID!=DOCUMENT_ITEM_TYPE && itemARef.groupID!=OUTFIT_ITEM_TYPE
		&& itemARef.groupID!=EQUIP_ITEM_TYPE) {
			//JRH: new types
			SetNodeUsing("EQUIP_BUTTON",false);
			SetNodeUsing("EXAMINE_BUTTON", false);
			SetNodeUsing("FLIP_BUTTON", false);	//JRH
			return;
		}
		SetNodeUsing("EQUIP_BUTTON",true);
		SetSelectable("EQUIP_BUTTON",ThisItemCanBeEquip(itemARef));

		//Levis: Only equip telescope if you have the long rifle -->
		if(GetAttribute(itemARef, "id") == "telescope")
		{
			if(!CheckCharacterItem(GetMainCharacter(),"LongRifle_C") && !CheckCharacterItem(GetMainCharacter(),"LongRifle_W"))
			{
				SetSelectable("EQUIP_BUTTON",false);
			}
		}
		//Levis <--

		if(IsEquipedItem(itemARef.id))
		{
			SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"EQUIP_BUTTON",0, "#"+XI_ConvertString("Release that"));
			if(itemARef.groupID==GUN_ITEM_TYPE || itemARef.groupID==BLADE_ITEM_TYPE || itemARef.groupID==ARMOR_ITEM_TYPE || itemARef.groupID==SPYGLASS_ITEM_TYPE
			|| itemARef.groupID==FLASK_ITEM_TYPE || itemARef.groupID==POUCH_ITEM_TYPE || itemARef.groupID==LOCKPICK_ITEM_TYPE
			|| itemARef.groupID==CLOCK_ITEM_TYPE || itemARef.groupID==COMPASS_ITEM_TYPE || itemARef.groupID==BELT_ITEM_TYPE
			|| itemARef.groupID==OUTFIT_ITEM_TYPE || itemARef.groupID==EQUIP_ITEM_TYPE)
			{
				//JRH: new types
				SetSelectable("EQUIP_BUTTON",true);
			}
			SetSelectable("TOSS_BUTTON", false); //Levis
		}
		else
		{
			SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"EQUIP_BUTTON",0, "#"+XI_ConvertString("Equip that"));
			SetNodeUsing("FLIP_BUTTON", false); //JRH
		}
	} else {
		SetNodeUsing("EQUIP_BUTTON",false);
		SetNodeUsing("EXAMINE_BUTTON", false); // KK
		SetSelectable("TOSS_BUTTON", false); //Levis
		SetNodeUsing("FLIP_BUTTON", false);  //JRH
	}
}
/*
void FillScroll()
{
    int i,j;
    string attributeName;

	if(nCurScroll<0)	nCurScroll = 0;
	GameInterface.itemslist.current = nCurScroll;
	nCurScroll = -1;
	GameInterface.itemslist.ImagesGroup.t0 = "usedflag";
	GameInterface.itemslist.ImagesGroup.t1 = "ICONS";
	aref arImgGrp;
	makearef(arImgGrp,GameInterface.itemslist.ImagesGroup);
	FillImagesGroupForItems(arImgGrp);
	GameInterface.itemslist.NotUsed = 5;

	GameInterface.itemslist.BadTex1 = GetItemPictureTexture("itemslist.ImagesGroup","");
	GameInterface.itemslist.BadPic1 = GetItemPictureName("");

	aref curItem,arItem;
	aref rootItems; makearef(rootItems,Characters[GetMainCharacterIndex()].Items);
    for(i=0; i<GetAttributesNum(rootItems); i++)
    {
		attributeName = "pic" + (i+1);
		curItem = GetAttributeN(rootItems,i);
		j = sti(GetAttributeValue(curItem));

		if( Items_FindItem(GetAttributeName(curItem),&arItem) >= 0 )
		{
			GameInterface.itemslist.(attributeName).img1 = GetItemPictureName(arItem.id);
			GameInterface.itemslist.(attributeName).tex1 = GetItemPictureTexture("itemslist.ImagesGroup",arItem.id);
			if(j>1)	GameInterface.itemslist.(attributeName).str1 = "#"+j;
			GameInterface.itemslist.(attributeName).itemID = arItem.id;
			if(IsEquipedItem(arItem.id))
			{
				GameInterface.itemslist.(attributeName).img2 = "usedflag";
				GameInterface.itemslist.(attributeName).tex2 = 0;
			}
		}
		else
		{
			GameInterface.itemslist.(attributeName).img1 = GameInterface.itemslist.BadPic1;
			GameInterface.itemslist.(attributeName).tex1 = GameInterface.itemslist.BadTex1;
		}
    }
	GameInterface.itemslist.ListSize = i;
	//DumpAttributes(&GameInterface);
}
*/
void ProcessCancelExit()
{
	IDoExit(RC_INTERFACE_ITEMS_EXIT);
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("frame","FrameProcess");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("TossItemYes", "I_TossItem"); //Levis
	DelEventHandler("TossItemNo", "Remove_Confirm"); //Levis
	//DelEventHandler("EquipPress","ProcEquipPress");
	DelEventHandler("ievnt_command","ProcessCommandExecute");

	RefreshUsedItems();
	ref chref;
	if(CheckAttribute(GetMainCharacter(),"Interface.Fellow")) { chref = CharacterFromId(characters[GetMainCharacterIndex()].Interface.Fellow); }
	else { chref = GetMainCharacter(); }

	if(CheckAttribute(GetMainCharacter(),"Interface.Fellow")) { DeleteAttribute(GetMainCharacter(),"Interface.Fellow"); }
    interfaceResultCommand = exitCode;
// MAXIMUS interface MOD -->
/*
	if( CheckAttribute(&InterfaceStates,"InstantExit") && sti(InterfaceStates.InstantExit)==true )
	{
		EndCancelInterface(true);
	}
	else
	{
		PostEvent("LaunchIAfterFrame",1,"sl", "I_SELECTMENU", 1);
		EndCancelInterface(false);
	}*/
	EndCancelInterface(true);
// MAXIMUS interface MOD <--

	if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0) LAi_QuestDelay("pchar_outfit_check", 0.1);	//JRH: see quest_reaction
}

void ProcEquipPress()
{
	ref chref;
	if(CheckAttribute(GetMainCharacter(),"Interface.Fellow")) { chref = CharacterFromId(characters[GetMainCharacterIndex()].Interface.Fellow); }
	else { chref = GetMainCharacter(); }
	string itmName = GetItemIDByOrder(nCurScroll);
	aref itmRef;
	if( Items_FindItem(itmName,&itmRef)>=0 && CheckAttribute(itmRef,"groupID") )
	{
		string itmGroup = itmRef.groupID;
		if( IsEquipedItem(itmName) )
		{
			objNewItemsEquip.(itmGroup) = "";
		}
		else
		{
			objNewItemsEquip.(itmGroup) = itmName;
		}
	}
}

string GetItemIDByOrder(int num)
{
	string attrName = "pic"+(num+1);
	if( CheckAttribute(&GameInterface,"itemslist."+attrName+".itemID") )
		return GameInterface.itemslist.(attrName).itemID;
	return "";
}

void SetUsedItems()
{
	ref mchref;
	if(CheckAttribute(GetMainCharacter(),"Interface.Fellow")) { mchref = CharacterFromId(characters[GetMainCharacterIndex()].Interface.Fellow); }
	else { mchref = GetMainCharacter(); }
	DeleteAttribute(&objNewItemsEquip,"");
	aref arEquip;
	makearef(arEquip,mchref.equip);
	CopyAttributes(&objNewItemsEquip,arEquip);
}

bool IsEquipedItem(string itemID)
{
	int q = GetAttributesNum(&objNewItemsEquip);

	aref arEquip;
	for(int i=0; i<q; i++)
	{
		arEquip = GetAttributeN(&objNewItemsEquip,i);
		if( GetAttributeValue(arEquip)==itemID ) return true;
	}

	return false;
}

void RefreshUsedItems()
{
	ref mchref;
	if(CheckAttribute(GetMainCharacter(),"Interface.Fellow")) { mchref = CharacterFromId(characters[GetMainCharacterIndex()].Interface.Fellow); }
	else { mchref = GetMainCharacter(); }
	aref arItm;

	string sItemName;
	string sGroupName;
	aref arEquip;
	int q = GetAttributesNum(&objNewItemsEquip);

	for(int i=0; i<q; i++)
	{
		arEquip = GetAttributeN(&objNewItemsEquip,i);
		sGroupName = GetAttributeName(arEquip);
		sItemName = GetAttributeValue(arEquip);
		if(sItemName=="")
		{	RemoveCharacterEquip(mchref,sGroupName);
		}
		else
		{	EquipCharacterByItem(mchref,sItemName);
		}
	}
}

bool ThisItemCanBeEquip( aref arItem )
{
	ref mchref;
	if(CheckAttribute(GetMainCharacter(),"Interface.Fellow")) { mchref = CharacterFromId(characters[GetMainCharacterIndex()].Interface.Fellow); }
	else { mchref = GetMainCharacter(); }

	if( !CheckAttribute(arItem,"groupID") )
	{
		trace("WARNING!!! item "+arItem.id+" hav`t attr. groupID");
		return false;
	}
	if( !IsCanEquiping(mchref,arItem.groupID) )
	{
		ShowHelpString("chelp_items#10");
		return false;
	}
	if(arItem.groupID!=GUN_ITEM_TYPE) return true;

	if( !CheckAttribute(arItem,"chargeQ") )
	{
		trace("WARNING!!! item "+arItem.id+" hav`t attr. chargeQ");
		return false;
	}
	int chrgQ = sti(arItem.chargeQ);

	if(chrgQ<2) return true;
	if( !IsCharacterPerkOn(mchref,"Gunman") )
	{
		ShowHelpString("chelp_items#11");
		return false;
	}

	if(chrgQ<4) return true;
	if( !IsCharacterPerkOn(mchref,"GunProfessional") )
	{
		ShowHelpString("chelp_items#11");
		return false;
	}

	//JRH -->
	if(chrgQ<6) return true;
	if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0 || sti(GetStorylineVar(FindCurrentStoryline(), "BUG_PUZZLES")) > 0)
	{
		if(!IsCharacterPerkOn(mchref,"GunFighter") )
		{
			ShowHelpString("chelp_items#11");
			return false;
		}
	}
	//<-- JRH

	return true;
}

void FillSelectedScroll(string itemsID)
{
	SetNodeUsing("EQUIP_BUTTON", false); // KK
	SetNodeUsing("EXAMINE_BUTTON", false); // KK
	SetNodeUsing("FLIP_BUTTON", false);  //JRH

	ref pch;
	if(CheckAttribute(GetMainCharacter(),"Interface.Fellow")) { pch = CharacterFromId(characters[GetMainCharacterIndex()].Interface.Fellow); }
	else { pch = GetMainCharacter(); }

	int i,j,allItems;
	string attributeName;

	if(nCurScroll<0)	nCurScroll = 0;
	GameInterface.itemslist.current = nCurScroll;
	nCurScroll = -1;
	GameInterface.itemslist.ImagesGroup.t0 = "usedflag";
	GameInterface.itemslist.ImagesGroup.t1 = "ICONS";
	aref arImgGrp;
	makearef(arImgGrp,GameInterface.itemslist.ImagesGroup);
	FillImagesGroupForItems(arImgGrp);
	GameInterface.itemslist.NotUsed = 5;

	GameInterface.itemslist.BadTex1 = GetItemPictureTexture("itemslist.ImagesGroup","");
	GameInterface.itemslist.BadPic1 = GetItemPictureName("");

	aref curItem,arItem;
	aref rootItems; makearef(rootItems,pch.Items);
	int loaded = 0;
	string curItemID = OBJECT_ITEM_TYPE;
	for(i=0; i<GetAttributesNum(rootItems); i++)
	{
		curItemID = OBJECT_ITEM_TYPE;
		attributeName = "pic" + (i+1);
		curItem = GetAttributeN(rootItems,i);
		j = sti(GetAttributeValue(curItem));

		if(Items_FindItem(GetAttributeName(curItem),&arItem)>=0)
		{
			if(CheckAttribute(arItem,"groupID"))
			{
				curItemID = OBJECT_ITEM_TYPE;
			//	if(arItem.groupID==GUN_ITEM_TYPE || arItem.groupID==BLADE_ITEM_TYPE || arItem.groupID==ARMOR_ITEM_TYPE || arItem.groupID==AMMUNITION_ITEM_TYPE) { curItemID = GUN_ITEM_TYPE; }
				if(arItem.groupID==GUN_ITEM_TYPE || arItem.groupID==BLADE_ITEM_TYPE || arItem.groupID==ARMOR_ITEM_TYPE || arItem.groupID==AMMUNITION_ITEM_TYPE || arItem.groupID==FLASK_ITEM_TYPE || arItem.groupID==POUCH_ITEM_TYPE || arItem.groupID==BELT_ITEM_TYPE || arItem.groupID==OPEN_ITEM_TYPE) { curItemID = GUN_ITEM_TYPE; }
				//JRH: added 4 types to GUN_ITEM_TYPE
				if(arItem.groupID==POTION_ITEM_TYPE) curItemID = POTION_ITEM_TYPE;
				//if(arItem.groupID==SPYGLASS_ITEM_TYPE || arItem.groupID==FLASK_ITEM_TYPE || arItem.groupID==POUCH_ITEM_TYPE || arItem.groupID==LOCKPICK_ITEM_TYPE || arItem.groupID==CLOCK_ITEM_TYPE || arItem.groupID==COMPASS_ITEM_TYPE) { curItemID = OBJECT_ITEM_TYPE; }
				if (arItem.groupID == MAP_ITEM_TYPE) curItemID = MAP_ITEM_TYPE; // KK
				if(arItem.groupID==QUEST_ITEM_TYPE || arItem.groupID==EQUIP_ITEM_TYPE || arItem.groupID==EXAMINE_ITEM_TYPE) curItemID = QUEST_ITEM_TYPE;
				if(curItemID==itemsID)
				{
				//	if(curItemID==GUN_ITEM_TYPE && arItem.id=="bladeX4") continue;//MAXIMUS
					attributeName = "pic" + (loaded+1);
					GameInterface.itemslist.(attributeName).img1 = GetItemPictureName(arItem.id);
					GameInterface.itemslist.(attributeName).tex1 = GetItemPictureTexture("itemslist.ImagesGroup",arItem.id);
					if(j>1)	GameInterface.itemslist.(attributeName).str1 = "#"+j;
// KK -->
					string name = "";
					if (CheckAttribute(arItem, "QualityName")) name = TranslateString("", "q"+arItem.QualityName) + " "; // PB: Correct quality name
					if( GetAttribute(arItem,"groupID") == QUEST_ITEM_TYPE)
					{
						name += PreprocessText(TranslateString("", arItem.name)); // PB
					}
					else
					{
						name += GetAssembledString(TranslateString("", arItem.name), arItem); // Levis
					}
					// MAXIMUS 31.05.2019: corrected for russian spelling ==>
					if (CheckAttribute(arItem, "QualityName"))
					{
						switch(LanguageGetLanguage())
						{
							case "Russian":
								name = name + " " + TranslateString("", "q"+arItem.QualityName);
							break;
							name = TranslateString("", "q"+arItem.QualityName) + " " + name; // PB: Correct quality name //default for English
						}
					}
					// MAXIMUS 31.05.2019: corrected for russian spelling <==

					if(DynamicInterfaceLevel() > 1) GameInterface.itemslist.(attributeName).str2 = "#" + name; // PB: Dynamic Interfaces
// <-- KK
					GameInterface.itemslist.(attributeName).itemID = arItem.id;
					if(IsEquipedItem(arItem.id))
					{
						GameInterface.itemslist.(attributeName).img2 = "usedflag";
						GameInterface.itemslist.(attributeName).tex2 = 0;
					}
					loaded++;
				}
				else
				{
					attributeName = "pic" + (loaded+1);
					GameInterface.itemslist.(attributeName).img1 = GameInterface.itemslist.BadPic1;
					GameInterface.itemslist.(attributeName).tex1 = GameInterface.itemslist.BadTex1;
				}
			}
			else
			{
				if(curItemID==itemsID)
				{
				//	if(curItemID==GUN_ITEM_TYPE && arItem.id=="bladeX4") continue;//MAXIMUS
					attributeName = "pic" + (loaded+1);
					GameInterface.itemslist.(attributeName).img1 = GetItemPictureName(arItem.id);
					GameInterface.itemslist.(attributeName).tex1 = GetItemPictureTexture("itemslist.ImagesGroup",arItem.id);
					if(j>1)	GameInterface.itemslist.(attributeName).str1 = "#"+j;
					GameInterface.itemslist.(attributeName).itemID = arItem.id;
					if(IsEquipedItem(arItem.id))
					{
						GameInterface.itemslist.(attributeName).img2 = "usedflag";
						GameInterface.itemslist.(attributeName).tex2 = 0;
					}
					loaded++;
				}
				else
				{
					attributeName = "pic" + (loaded+1);
					GameInterface.itemslist.(attributeName).img1 = GameInterface.itemslist.BadPic1;
					GameInterface.itemslist.(attributeName).tex1 = GameInterface.itemslist.BadTex1;
				}
			}
		}
		else
		{
			attributeName = "pic" + (loaded+1);
			GameInterface.itemslist.(attributeName).img1 = GameInterface.itemslist.BadPic1;
			GameInterface.itemslist.(attributeName).tex1 = GameInterface.itemslist.BadTex1;
		}
  }
	GameInterface.itemslist.ListSize = loaded;
	if (nCurScroll < 0) nCurScroll = 0;
	if (nCurScroll > loaded) nCurScroll = loaded;
	GameInterface.itemslist.current = nCurScroll;
}
