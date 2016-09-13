#include "items\items.h"
extern void OpenBoxProcedure_WR(); // PB: Create external function
extern void OpenBoxProcedure_BUG(); // PB: Create external function
extern void OpenBoxProcedure_BART(); // PB: Create external function

object randItemModels[MAX_LOADED_RANDITEMS];
object itemModels[MAX_ITEMS];
object buttonModels[MAX_BUTTONS];

aref useLocators[MAX_BUTTONS];
aref useAttrs[MAX_BUTTONS];
int  useLocatorsCount=0;

float SPAWN_TIME = 168.0; //hours = 168.0

bool virtual_box = false;	//JRH

void Items_LoadModel (ref _itemModel, ref _item)
{
	if (!IsEntity(_itemModel))
	{
		string itemFolder = "items";
		CreateEntity(&_itemModel, "MODELR");
		if (CheckAttribute(_item, "folder"))
			itemFolder = _item.folder;
		SendMessage(&_itemModel, "ls", MSG_MODEL_SET_DIRPATH, itemFolder+"\\"); // qf)")
		SendMessage(&_itemModel, "ls", MSG_MODEL_LOAD_GEO, itemFolder + "\\" + _item.model);
		SendMessage(&_itemModel, "ls", MSG_MODEL_SET_DIRPATH,"");
		// NK set blades diff -->
		// 05-07-13 do for pistols as well
		if(HasSubStr(_item.model, "blade") || HasSubStr(_item.model, "pistol")) SendMessage(&_itemModel, "ls", MSG_MODEL_SET_TECHNIQUE, "BladeItem");
		else SendMessage(&_itemModel, "ls", MSG_MODEL_SET_TECHNIQUE, "RandItem");
		// NK <--
		LayerAddObject("execute", &_itemModel, ITEMS_LAYER);
		LayerAddObject("realize", &_itemModel, ITEMS_LAYER);

		Trace("ItemLogic: Loaded model "+itemFolder+"\\"+_item.model);
	}
}

void Item_OnLoadLocation(string currentLocation)
{
	Trace("ItemLogic: On load location "+currentLocation);
	// boal cabin -->
	if (bCabinStarted) return;
	// boal cabin <--

	// precache active locators in current location
	aref   activeLocation;
	ref chr = GetMainCharacter();
	int currentLocationIndex = FindLocation(currentLocation);
	chr.itemLocationIndex = currentLocationIndex;
	aref aloc, an, al;
	useLocatorsCount = 0;
	makearef(activeLocation, Locations[currentLocationIndex]);
	makearef (aloc, activeLocation.items);
	for (int i=0; i<GetAttributesNum(aloc); i++)
	{
		an = GetAttributeN(aloc, i);
		if (!CheckAttribute(an,"locator"))
			continue;
		if (!FindLocator(activeLocation.id, an.locator, &al, true))
			continue;

		useLocators[useLocatorsCount] = al;
		useAttrs[useLocatorsCount] = an;
		useLocatorsCount++;
	}

	// load buttons & items
	Items_ShowButtons(currentLocation);

	// PB: Treasure Quests -->
	if(!CheckAttribute(activeLocation, "locators.box.treasure_box"))
		RandItems_OnLoadLocation(activeLocation);
	// PB: Treasure Quests <--
	Box_OnLoadLocation(activeLocation);

	for (int itemN=0; itemN<ITEMS_QUANTITY; itemN++)
	{
		if (!CheckAttribute(Items[itemN], "startLocator"))
			continue;
		if (!CheckAttribute(Items[itemN], "startLocation"))
			continue;
		if (!CheckAttribute(Items[itemN], "shown"))
			continue;
		if (Items[itemN].shown == "1")
		{
		if (Items[itemN].startLocation == currentLocation)
		{
			Items_ShowItem(itemN);
		}}
	}
}

void Item_OnUnLoadLocation()
{
	Trace("ItemLogic: On unload location");
	for (int itemN=0; itemN<ITEMS_QUANTITY; itemN++)
	{
		if (IsEntity(&itemModels[itemN]))
			DeleteClass(&itemModels[itemN]);
	}
	for (int buttonN=0; buttonN<MAX_BUTTONS; buttonN++)
	{
		if (IsEntity(&buttonModels[buttonN]))
			DeleteClass(&itemModels[buttonN]);
	}

	RandItems_OnUnloadLocation();

	ref chr = GetMainCharacter();
	chr.itemLocationIndex = -1;
}

void Item_OnEnterLocator(aref _location, string _locator)
{
	ref chr = GetMainCharacter();
	int itemN;
	if (HasSubStr(_locator, "button"))
	{ // use item
		if(HasSubStr(_locator, "666") || HasSubStr(_locator, "999") || HasSubStr(_locator, "777"))
		{//MAXIMUS: by this way we can use any action
			chr.activeItem = -1;
			chr.activeLocator = _locator;
			chr.activeRandItem = false;
			chr.activeItem.pick = false;
			chr.activeItem.Action = "Action";
			chr.activeItem.Action.label = "alarm_bell";
			if(!HasSubStr(_locator, "999") && !HasSubStr(_locator, "777")) { Log_SetActiveAction(chr.activeItem.Action); }
			else
			{
				if(HasSubStr(_locator, "777"))
				{
					chr.activeItem.Action.label = "hidden_treasure";
					if(!CheckAttribute(chr,"location.first") && !bSeaActive) Log_SetActiveAction(chr.activeItem.Action);
				}
				if(HasSubStr(_locator, "666"))
				{
					chr.activeItem.Action.label = "steering_wheel";
					if(!CheckAttribute(chr,"location.first") && !bSeaActive) Log_SetActiveAction(chr.activeItem.Action);
				}
			}
		}
		else { traceif("ItemLogic: Entered locator "+_locator);
		for (itemN=0; itemN<ITEMS_QUANTITY; itemN++)
		{
			if (!CheckAttribute(Items[itemN], "useLocator"))
				continue;
			if (!CheckAttribute(Items[itemN], "useLocation"))
				continue;
			if (!CheckAttribute(Items[itemN], "shown"))
				continue;
			if (Items[itemN].shown == "0")
			{
			if (Items[itemN].useLocation == _location.id)
			{
			if (Items[itemN].useLocator == _locator)
			{
// KK -->
				if (_location.id == "Labirint_3" && CheckAttribute(_location, "filespath.models") == true && HasSubStr(_location.filespath.models, "Incas Temple\Labirint") == true && _locator == "button01")
					chr.activeItem.Action = "Idol";
				else
					chr.activeItem.Action = "Action";
// <-- KK
				Log_SetActiveAction(chr.activeItem.Action);
				chr.activeItem = itemN;
				chr.activeLocator = _locator;
				chr.activeRandItem = false;
				chr.activeItem.pick = false;
			}}}
		}}
	}
	else
	{traceif("ItemLogic: Entered locator "+_locator);
		for (itemN=0; itemN<ITEMS_QUANTITY; itemN++)
		{
			if (!CheckAttribute(Items[itemN], "startLocator"))
				continue;
			if (!CheckAttribute(Items[itemN], "startLocation"))
				continue;
			if (!CheckAttribute(Items[itemN], "shown"))
				continue;
			if (Items[itemN].startLocator == _locator)
			{
			if (Items[itemN].shown == "1")
			{
			if (Items[itemN].startLocation == _location.id)
			{
				chr.activeItem.Action = "Pick";
				Log_SetActiveAction(chr.activeItem.Action);
				chr.activeItem = itemN;
				chr.activeLocator = _locator;
				chr.activeRandItem = false;
				chr.activeItem.pick = true;
			}}}
		}
	}
	BLI_RefreshCommandMenu();
}

void Item_OnExitLocator()//MAXIMUS: was (aref _location, string _locator) - for what?
{
	Log_SetActiveAction("Nothing");
	//Characters[GetMainCharacterIndex()].activeItem = "";
	if(CheckAttribute(GetMainCharacter(),"activeItem.update")) DeleteAttribute(GetMainCharacter(),"activeItem.update");
	if(CheckAttribute(GetMainCharacter(),"activeItem")) DeleteAttribute(GetMainCharacter(),"activeItem");
	BLI_RefreshCommandMenu();
}

void Item_OnPickItem()
{
	aref activeLocation;
	ref chr = GetMainCharacter();
	if ( !CheckAttribute(chr,"itemLocationIndex") || sti(chr.itemLocationIndex) < 0 ) return;// TIH runtime error fix - do nothing if item picked up didnt exist (happens in cabins for some reason) Jul22'06
	/*makearef(activeLocation, Locations[sti(chr.itemLocationIndex)]);

	string displayItemName, youvegotString;
	youvegotString = TranslateString("", "you've_got");

	int activeItem = -1; // KK
	if (sti(chr.activeRandItem) == true) {
		string activeRandItemAttribute = "RandItemType"+sti(chr.activeItem);
		if (CheckAttribute(activeLocation, activeRandItemAttribute)) {
			activeItem = sti(activeLocation.(activeRandItemAttribute)); // KK
			displayItemName = TranslateString("", Items[activeItem].name);
		}
	} else {
		activeItem = sti(chr.activeItem);
		displayItemName = TranslateString("", Items[activeItem].name);
	}
	if (CheckAttribute(&Items[activeItem], "QualityName")) displayItemName = TranslateString("", Items[activeItem].QualityName) + " " + displayItemName; // KK
	chr.activeItem.label = youvegotString+" "+displayItemName+"!";*/

//JRH -->
	if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0 || sti(GetStorylineVar(FindCurrentStoryline(), "BUG_PUZZLES")) > 0 || sti(GetStorylineVar(FindCurrentStoryline(), "BART_PUZZLES")) > 0)
   	{
		Log_SetActiveAction("Nothing");
		makearef(activeLocation, Locations[sti(chr.itemLocationIndex)]);

		string displayItemName, youvegotString;
		youvegotString = TranslateString("", "you've_got");

		if (chr.activeRandItem == true)
		{
			string activeRandItemAttribute = "RandItemType"+sti(chr.activeItem);
			if (CheckAttribute(activeLocation, activeRandItemAttribute))
			{
	//------------------------------------------------------------------------------------------------------------
				if(Items[sti(activeLocation.(activeRandItemAttribute))].id == "koster1"
				|| Items[sti(activeLocation.(activeRandItemAttribute))].id == "koster3"
				|| Items[sti(activeLocation.(activeRandItemAttribute))].id == "koster4")
				{
					if(CheckCharacterItem(chr,"pistollog"))
					{
						Logit(TranslateString("","They are really heavy - one is enough!"));
						PlaySound("AMBIENT\JAIL\sigh.wav");
						PlaySound("AMBIENT\JAIL\sigh.wav");
						return;
					}
				}

				if(Items[sti(activeLocation.(activeRandItemAttribute))].id == "1_log")
				{
					if(CheckCharacterItem(chr,"bladeemptysack"))
					{
						if(!IsEquipCharacterByItem(chr, "bladeemptysack"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladeemptysack");
						}

						chr.quest.Legrands_logs = sti(chr.quest.Legrands_logs) + 1;

						if(CheckAttribute(chr, "quest.Legrands_logs"))
						{
							switch(chr.quest.Legrands_logs)
							{
								case "1": PlaySound("VOICE\ENGLISH\blaze_1.wav"); break;
								case "2": PlaySound("VOICE\ENGLISH\blaze_2.wav"); break;
								case "3": PlaySound("VOICE\ENGLISH\blaze_3.wav"); break;
								case "4": PlaySound("VOICE\ENGLISH\blaze_4.wav"); break;
								case "5": PlaySound("VOICE\ENGLISH\blaze_5.wav"); break;
								case "6": PlaySound("VOICE\ENGLISH\blaze_6.wav"); break;
								case "7": PlaySound("VOICE\ENGLISH\blaze_7.wav"); break;
								case "8": PlaySound("VOICE\ENGLISH\blaze_8.wav"); break;

								case "9": PlaySound("VOICE\ENGLISH\blaze_9.wav");
									  RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									  TakeItemFromCharacter(chr, "bladeemptysack");
									  GiveItem2Character(chr, "bladewoodsack");
									  EquipCharacterByItem(chr, "bladewoodsack");
									  Logit(TranslateString("","The sack is full - let's go home!"));

									  LAi_QuestDelay("delete_9_driftwood", 1.5);
								break;
							}
						}
					}
					else
					{
						Logit(TranslateString("","I need something to carry the wood in."));
						PlaySound("AMBIENT\JAIL\sigh.wav");
						PlaySound("AMBIENT\JAIL\sigh.wav");
						return;
					}
				}

				if(Items[sti(activeLocation.(activeRandItemAttribute))].id == "marsh_hen")
				{
					if(CheckCharacterItem(chr,"bladeemptysack_B"))
					{
						if(!IsEquipCharacterByItem(chr, "bladeemptysack_B"))
						{
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
							EquipCharacterByItem(chr, "bladeemptysack_B");
						}

						chr.quest.Legrands_hens = sti(chr.quest.Legrands_hens) + 1;

						if(CheckAttribute(chr, "quest.Legrands_hens"))
						{
							switch(chr.quest.Legrands_hens)
							{
								case "1": PlaySound("VOICE\ENGLISH\blaze_1.wav"); break;
								case "2": PlaySound("VOICE\ENGLISH\blaze_2.wav"); break;
								case "3": PlaySound("VOICE\ENGLISH\blaze_3.wav"); break;
								
								case "4": PlaySound("VOICE\ENGLISH\blaze_4.wav");
									  RemoveCharacterEquip(chr, BLADE_ITEM_TYPE);
									  TakeItemFromCharacter(chr, "bladeemptysack_B");
									  GiveItem2Character(chr, "bladebirdsack");
									  EquipCharacterByItem(chr, "bladebirdsack");
									  Logit(TranslateString("","The sack is full - let's go home!"));

									  LAi_QuestDelay("delete_4_marsh_hens", 1.5);
								break;
							}
						}
					}
				}

				if(Items[sti(activeLocation.(activeRandItemAttribute))].id == "shell1" 
				|| Items[sti(activeLocation.(activeRandItemAttribute))].id == "shell2"
				|| Items[sti(activeLocation.(activeRandItemAttribute))].id == "shell3"
				|| Items[sti(activeLocation.(activeRandItemAttribute))].id == "shell4"
				|| Items[sti(activeLocation.(activeRandItemAttribute))].id == "shell5"
				|| Items[sti(activeLocation.(activeRandItemAttribute))].id == "shell6")
				{
					chr.quest.Legrands_shells = sti(chr.quest.Legrands_shells) + 1;

					if(CheckAttribute(chr, "quest.Legrands_shells"))
					{
						switch(chr.quest.Legrands_shells)
						{
							case "1": PlaySound("VOICE\ENGLISH\blaze_1.wav"); break;
							case "2": PlaySound("VOICE\ENGLISH\blaze_2.wav"); break;
							case "3": PlaySound("VOICE\ENGLISH\blaze_3.wav"); break;
							case "4": PlaySound("VOICE\ENGLISH\blaze_4.wav"); break;
							case "5": PlaySound("VOICE\ENGLISH\blaze_5.wav"); break;	
							case "6": PlaySound("VOICE\ENGLISH\blaze_6.wav");
								  
								  LAi_QuestDelay("delete_6_shells", 1.5);
							break;
						}
					}
				}

				if(Items[sti(activeLocation.(activeRandItemAttribute))].id == "book63" 
				|| Items[sti(activeLocation.(activeRandItemAttribute))].id == "book67"
				|| Items[sti(activeLocation.(activeRandItemAttribute))].id == "book68")  LAi_QuestDelay("6_malta_books_check", 1.5);
				
	//------------------------------------------------------------------------------------------------------------
				SendMessage(&randItemModels[sti(chr.activeItem)], "lslff", MSG_MODEL_BLEND, "blenditemlit", 1000, 1.0, 0.0);
				GiveItem2Character(GetMainCharacter(), Items[sti(activeLocation.(activeRandItemAttribute))].id);

				displayItemName = TranslateString("", Items[sti(activeLocation.(activeRandItemAttribute))].name);

				if(Items[sti(activeLocation.(activeRandItemAttribute))].id == "barrel_big" || Items[sti(activeLocation.(activeRandItemAttribute))].id == "sack"
				|| Items[sti(activeLocation.(activeRandItemAttribute))].id == "brF13" || Items[sti(activeLocation.(activeRandItemAttribute))].id == "toolchest1"
				|| Items[sti(activeLocation.(activeRandItemAttribute))].id == "brF14R" || Items[sti(activeLocation.(activeRandItemAttribute))].id == "basket"
				|| Items[sti(activeLocation.(activeRandItemAttribute))].id == "brF4R" || Items[sti(activeLocation.(activeRandItemAttribute))].id == "brderrick"
				|| Items[sti(activeLocation.(activeRandItemAttribute))].id == "koster1" || Items[sti(activeLocation.(activeRandItemAttribute))].id == "koster3"
				|| Items[sti(activeLocation.(activeRandItemAttribute))].id == "koster4" || Items[sti(activeLocation.(activeRandItemAttribute))].id == "cannonball_box2"
				|| Items[sti(activeLocation.(activeRandItemAttribute))].id == "cannonball_box" || Items[sti(activeLocation.(activeRandItemAttribute))].id == "hatch2"
				|| Items[sti(activeLocation.(activeRandItemAttribute))].id == "plank3" || Items[sti(activeLocation.(activeRandItemAttribute))].id == "mdchest"
				|| Items[sti(activeLocation.(activeRandItemAttribute))].id == "surgery_kit" || Items[sti(activeLocation.(activeRandItemAttribute))].id == "cauldron1"
				|| Items[sti(activeLocation.(activeRandItemAttribute))].id == "temp_plank0" || Items[sti(activeLocation.(activeRandItemAttribute))].id == "plank1_long"
				|| Items[sti(activeLocation.(activeRandItemAttribute))].id == "plank2_long" || Items[sti(activeLocation.(activeRandItemAttribute))].id == "chestmap1"
				|| Items[sti(activeLocation.(activeRandItemAttribute))].id == "dummy_belt" || Items[sti(activeLocation.(activeRandItemAttribute))].id == "lockpick_JRH"
				|| Items[sti(activeLocation.(activeRandItemAttribute))].id == "megaphone" || Items[sti(activeLocation.(activeRandItemAttribute))].id == "boathook"
				|| Items[sti(activeLocation.(activeRandItemAttribute))].id == "musket_item" || Items[sti(activeLocation.(activeRandItemAttribute))].id == "spyglass5"
				|| Items[sti(activeLocation.(activeRandItemAttribute))].id == "mtoon_item" || Items[sti(activeLocation.(activeRandItemAttribute))].id == "pillow"
				|| Items[sti(activeLocation.(activeRandItemAttribute))].id == "fire_irons_item" || Items[sti(activeLocation.(activeRandItemAttribute))].id == "lever_item"
				|| Items[sti(activeLocation.(activeRandItemAttribute))].id == "cannonball2" || Items[sti(activeLocation.(activeRandItemAttribute))].id == "clockkey"
				|| Items[sti(activeLocation.(activeRandItemAttribute))].id == "empty_bottle" || Items[sti(activeLocation.(activeRandItemAttribute))].id == "ladder_big_45"
				|| Items[sti(activeLocation.(activeRandItemAttribute))].id == "wood_short_logs" || Items[sti(activeLocation.(activeRandItemAttribute))].id == "wood4_item"
				|| Items[sti(activeLocation.(activeRandItemAttribute))].id == "pole3_small" || Items[sti(activeLocation.(activeRandItemAttribute))].id == "spyglass6"
				|| Items[sti(activeLocation.(activeRandItemAttribute))].id == "sail" || Items[sti(activeLocation.(activeRandItemAttribute))].id == "sack3"
				|| Items[sti(activeLocation.(activeRandItemAttribute))].id == "boom_item")
				{

				}
				else Log_SetStringToLog(youvegotString+" "+displayItemName+"!");

				activeLocation.(activeRandItemAttribute) = -1;
			}
		}
		else
		{
			int activeItem = sti(chr.activeItem);
			Trace("ItemLogic: picking item "+Items[activeItem].id);
			Items[activeItem].shown = false;
			SendMessage(&itemModels[activeItem], "lslff", MSG_MODEL_BLEND, "blenditemlit", 1000, 1.0, 0.0);
			GiveItem2Character(GetMainCharacter(), Items[activeItem].id);

			displayItemName = TranslateString("", Items[activeItem].name);
		 	Log_SetStringToLog(youvegotString+" "+displayItemName+"!");
		}

		DeleteAttribute(chr,"activeItem");
//<-- JRH
   	}
    	else LaunchInfoScreen();
}

void DoAction()
{
	string snd = GetEventData();
	DelEventHandler("bAction","DoAction");

	switch(snd)
	{
		case "AMBIENT\TOWN\Alarm.wav":
		break;

		case "NATURE\windmill.wav":
		break;

		case "AMBIENT\SHIP\parusa_hlp_002.wav":
			LaunchInfoScreen();
		break;
	}
}

void Item_OnUseItem()
{
	aref aloc, an, al;

	aref activeLocation;
	ref chr = GetMainCharacter();
	if (!CheckAttribute(chr, "activeItem")) return; // PB: Prevent error logs
	int activeItem = sti(chr.activeItem);
	if(activeItem==-1)
	{
		SetEventHandler("bAction","DoAction",1);
		string snd = "";
		float up = 0.0;
		if(HasSubStr(chr.activeLocator,"666")) { up = 1.8; snd = "AMBIENT\TOWN\Alarm.wav"; PostEvent("bAction",3000,"s",snd); }//MAXIMUS: IDEA!!! During mutiny-fight, for example, player can call his loyal crew for help
		if(HasSubStr(chr.activeLocator,"999")) { up = 1.3; snd = "NATURE\windmill.wav"; PostEvent("bAction",3000,"s",snd); }//MAXIMUS: Here we can make SeaLoad
		if(HasSubStr(chr.activeLocator,"777")) { up = 2.0; snd = "AMBIENT\SHIP\parusa_hlp_002.wav"; PostEvent("bAction",200,"s",snd); }
		PlayLocatorSound(&Locations[sti(chr.itemLocationIndex)], "item", chr.activeLocator, snd, up);
		return;
	}
	makearef(activeLocation, Locations[sti(chr.itemLocationIndex)]);

	makearef (aloc, activeLocation.items);
	Log_SetActiveAction("Nothing");
	Log_SetStringToLog(XI_ConvertString("Using") + " " + XI_ConvertString(Items[activeItem].id));
	Trace("ItemLogic: using item "+Items[activeItem].id);
	Items[activeItem].shown = true;
	Items_LoadModel(&itemModels[activeItem], &Items[activeItem]);

	for (int i=0; i<GetAttributesNum(aloc); i++)
	{
		an = GetAttributeN(aloc, i);
		if (an.locator == chr.activeLocator)
			break;
	}

	FindLocator(activeLocation.id, chr.activeLocator, &al, true);
	SendMessage(&itemModels[activeItem], "lffffffffffff", MSG_MODEL_SET_POSITION, makeFloat(al.x), makeFloat(al.y)+makefloat(an.itemDeltaY), makeFloat(al.z), makeFloat(al.vx.x), makeFloat(al.vx.y), -makeFloat(al.vx.z), makeFloat(al.vy.x), makeFloat(al.vy.y), -makeFloat(al.vy.z), makeFloat(al.vz.x), makeFloat(al.vz.y), -makeFloat(al.vz.z));
	SendMessage(&itemModels[activeItem], "lslff", MSG_MODEL_BLEND, "blenditem", 1000, 0.0, 1.0);

	SetEventHandler("frame", "Item_OnUseFrame", 0);
	TakeItemFromCharacter(GetMainCharacter(), Items[activeItem].id);
	Items[activeItem].startLocator = "";
	an.trigged = true;
	al.active = true;
	al.timePassed = 0;

	DeleteAttribute(chr,"activeItem");

	CompleteQuestName("OnUse_"+Items[activeItem].id);
}

void Item_OnUseFrame()
{
	aref aloc, an, al;
	aref activeLocation;
	ref chr = GetMainCharacter();
	makearef(activeLocation, Locations[sti(chr.itemLocationIndex)]);

	makearef (aloc, activeLocation.items);
	bool usedOnFrame=false;
	for (int i=0; i<useLocatorsCount; i++)
	{
		an = useAttrs[i];
		al = useLocators[i];
		if (!CheckAttribute(al, "active"))
			continue;
		if (al.active != "1")
			continue;
		int timePassed = sti(al.timePassed) + GetDeltaTime();
		al.timePassed = timePassed;
		if (timePassed > BUTTON_ACTIVATION_TIME)
		{
			al.active = false;
			continue;
		}

		usedOnFrame = true;
		float timeK = makefloat(timePassed) / makefloat(BUTTON_ACTIVATION_TIME);
		float deltaY = makefloat(an.deltaY) * timeK;

		SendMessage(&buttonModels[i], "lffffffffffff", MSG_MODEL_SET_POSITION, makeFloat(al.x), makeFloat(al.y)+deltaY, makeFloat(al.z), makeFloat(al.vx.x), makeFloat(al.vx.y), -makeFloat(al.vx.z), makeFloat(al.vy.x), makeFloat(al.vy.y), -makeFloat(al.vy.z), makeFloat(al.vz.x), makeFloat(al.vz.y), -makeFloat(al.vz.z));

		for (int j=0; j<ITEMS_QUANTITY; j++)
		{
			if (Items[j].useLocator == an.locator)
			{
				SendMessage(&itemModels[j], "lffffffffffff", MSG_MODEL_SET_POSITION, makeFloat(al.x), makeFloat(al.y)+makeFloat(an.itemDeltaY)+deltaY, makeFloat(al.z), makeFloat(al.vx.x), makeFloat(al.vx.y), -makeFloat(al.vx.z), makeFloat(al.vy.x), makeFloat(al.vy.y), -makeFloat(al.vy.z), makeFloat(al.vz.x), makeFloat(al.vz.y), -makeFloat(al.vz.z));
				break;
			}
		}
	}

	if (!usedOnFrame)
		DelEventHandler("frame", "Item_OnUseFrame");
}

void Items_ShowButtons(string _locationName)
{
	aref al;
	Trace("ItemLogic: found "+useLocatorsCount+" buttons");
	for (int i=0; i<useLocatorsCount; i++)
	{
		Items_LoadModel(&buttonModels[i], &useAttrs[i]);
		al = useLocators[i];
		if (useAttrs[i].trigged != "1")
			SendMessage(&buttonModels[i], "lffffffffffff", MSG_MODEL_SET_POSITION, makeFloat(al.x), makeFloat(al.y), makeFloat(al.z), makeFloat(al.vx.x), makeFloat(al.vx.y), -makeFloat(al.vx.z), makeFloat(al.vy.x), makeFloat(al.vy.y), -makeFloat(al.vy.z), makeFloat(al.vz.x), makeFloat(al.vz.y), -makeFloat(al.vz.z));
		else
			SendMessage(&buttonModels[i], "lffffffffffff", MSG_MODEL_SET_POSITION, makeFloat(al.x), makeFloat(al.y)+makefloat(useAttrs[i].deltaY), makeFloat(al.z), makeFloat(al.vx.x), makeFloat(al.vx.y), -makeFloat(al.vx.z), makeFloat(al.vy.x), makeFloat(al.vy.y), -makeFloat(al.vy.z), makeFloat(al.vz.x), makeFloat(al.vz.y), -makeFloat(al.vz.z));
	}
}

void Items_ShowItem(int _itemN)
{
	aref al;
	aref activeLocation;
	ref chr = GetMainCharacter();
	makearef(activeLocation, Locations[sti(chr.itemLocationIndex)]);

	if (Items[_itemN].model == "")
	{
		Trace("ItemLogic: no model for item "+activeLocation.id+"."+Items[_itemN].id);
		return;
	}

	if (Items[_itemN].startLocator != "")
	{ //unused
		Items_LoadModel(&itemModels[_itemN], &Items[_itemN]);

		if (!FindLocator(Items[_itemN].startLocation, Items[_itemN].startLocator, &al, true))
			Trace("ItemLogic: locator for item "+_itemN+" not found! ["+Items[_itemN].startLocation+">>"+Items[_itemN].startLocator);
		Trace ("ItemLogic: showing item at "+al.x+", "+al.y+", "+al.z);
		SendMessage(&itemModels[_itemN], "lffffffffffff", MSG_MODEL_SET_POSITION, makeFloat(al.x), makeFloat(al.y), makeFloat(al.z), makeFloat(al.vx.x), makeFloat(al.vx.y), -makeFloat(al.vx.z), makeFloat(al.vy.x), makeFloat(al.vy.y), -makeFloat(al.vy.z), makeFloat(al.vz.x), makeFloat(al.vz.y), -makeFloat(al.vz.z));
	}
	else
	{ //used
		if (Items[_itemN].useLocation != activeLocation.id)
			return;

		Items_LoadModel(&itemModels[_itemN], &Items[_itemN]);

		for (int i=0; i<useLocatorsCount; i++)
		{
			al = useLocators[i];
			if (useAttrs[i].locator == Items[_itemN].useLocator)
			{
				SendMessage(&itemModels[i], "lffffffffffff", MSG_MODEL_SET_POSITION, makeFloat(al.x), makeFloat(al.y)+makeFloat(useAttrs[i].itemDeltaY)+makeFloat(useAttrs[i].deltaY), makeFloat(al.z), makeFloat(al.vx.x), makeFloat(al.vx.y), -makeFloat(al.vx.z), makeFloat(al.vy.x), makeFloat(al.vy.y), -makeFloat(al.vy.z), makeFloat(al.vz.x), makeFloat(al.vz.y), -makeFloat(al.vz.z));
				return;
			}
		}
	}
}

void Items_HideItem(int itemN)
{
}

int Items_FindItem(string itemID, ref itemARef)
{
	// NK -->
	// 04-09-08 let's try again. :)
	/*aref curItem;
	for(int i=0; i<ITEMS_QUANTITY; i++)
	{
		makearef(curItem,Items[i]);
		if( curItem.id == itemID )
		{
			itemARef = curItem;
			return i;
		}
	}*/
	int i = GetItemIndex(itemID);
	//trace("Finding item " + itemID + ", has index " + i);
	if(i >= 0 && i < ITEMS_QUANTITY) //{ itemARef = &Items[i]; return i; //}
	{ makearef(itemARef, Items[i]); return i; }
	// NK <--
	return -1;
}

// NK 04-09-08 added general GetItemIndex() using NativeFindCharacter()
int GetItemIndex(string id)
{
	int i = NativeFindCharacter(&Items, id);
	if(i >= 0 && i < ITEMS_QUANTITY) { return i; }
	//trace("GetItemIndex: item " + id + " not found!");
	return -1;
}
// NK <--
// ************** RANDOM ITEMS *****************
void RandItems_OnLoadLocation(ref _location)
{
	string locatorName;
	aref randItemLocator;
	for (int i=1; i<MAX_LOADED_RANDITEMS; i++)
	{
		string lastSpawnTimeString = "LastSpawnTime"+i;
		string randItemTypeString = "RandItemType"+i;
		locatorName = "randitem"+i;
		if (!FindLocator(_location.id, locatorName, &randItemLocator, true))
			break;

		// randitem locator found
		if (CheckAttribute(_location, lastSpawnTimeString))
		{ // already spawned?
			if (CheckAttribute(_location, randItemTypeString))
			{
				if (sti(_location.(randItemTypeString)) != -1)
				{
					RandItems_DrawRandItem(i, _location, randItemLocator);
				}
				else
				{ //already picked up, try to respawn
					if ((stf(_location.(lastSpawnTimeString))+SPAWN_TIME) < Items_MakeTime(GetTime(), GetDataDay(), GetDataMonth(), GetDataYear()))
					{
						RandItems_SpawnRandItem(i, _location, randItemLocator);
					}
				}
			}
			else
			{ // nothing here
				if ((stf(_location.(lastSpawnTimeString))+SPAWN_TIME) < Items_MakeTime(GetTime(), GetDataDay(), GetDataMonth(), GetDataYear()))
				{
					RandItems_SpawnRandItem(i, _location, randItemLocator);
				}
			}
		}
		else
		{
			RandItems_SpawnRandItem(i, _location, randItemLocator);
		}
	}
}

void RandItems_OnUnloadLocation()
{
	for (int itemN=0; itemN<MAX_LOADED_RANDITEMS; itemN++)
	{
		if (IsEntity(&randItemModels[itemN]))
			DeleteClass(&randItemModels[itemN]);
	}
}

float Items_MakeTime (float _h, float _d, float _m, float _y)
{
	return (_h+24.0*(_d + 30.0*(_m + 12.0*_y)));
}

void RandItems_SpawnRandItem(int _index, aref _location, aref al)
{
	aref randItem;
	string lastSpawnTimeString;
	int n = -1; // TIH initialize Aug24'06

	string alName = GetAttributeName(al);
	string alNameAttribute = "items."+alName;
	// NK temporarily locations with named rand items will ignore the name. BUT if ID == blade1, will still gen that.
	// NK 05-03-25 fix this so it checks location's randitemsstay attribute.
	bool generate = true;// TIH name change for clarity
	if (CheckAttribute(_location, alNameAttribute))
	{
		// TIH --> logic fix
		bool locSetItem = false;
		if ( RANDOM_DUNGEON_BLADES == 0 ) { locSetItem = true; }
		if ( CheckAttribute(_location,"randitemsstay") && sti(_location.randitemsstay) ) { locSetItem = true; }
		if ( locSetItem )
		{
			generate = false;
			n = Items_FindItem(_location.items.(alName), &randItem);
			if (n == -1) return;
			lastSpawnTimeString = "LastSpawnTime"+_index;
			_location.(lastSpawnTimeString) = Items_MakeTime(0, 15, 1, 2003);
		}
		// TIH <--
	}
	// else
	if(generate)
	{
		// NK <--
		// TIH --> rpg_style only
		// use 'rare' in the formula for spawning a random item (adjusted scale)
		// also will try at least RARE_RAND_RETRIES times to find an item (instead of just once)
		// Nov21'06 fix: 'n' has now been set to -1 when it fails a check, so that the prior value of 'n' doesn't
		// simply carry through to the end of the function, thus spawning an item that failed the checks!
		if ( IT_RPG_STYLE ) {
			int 	nn;
			float 	itemProb
			bool 	itmSelected = false;
			int		levelCut = makeint(RARE_MAXLEVEL_ABOVE + GetLevel(GetMainCharacter()) + makeint(CalcCharacterSkill(GetMainCharacter(),SKILL_SNEAK) / 2));
			for ( nn = 0; nn < RARE_RAND_RETRIES; nn++) {
				n = Items_FindItem(RandItems[rand(RANDITEMS_QUANTITY-1)].id, &randItem);
				if ( n == -1 ) continue;
				if ( CheckAttribute(randItem, "model") && randItem.model == "" ) {n = -1;continue;} // Nov21'06 // cant use items without models
				if ( RARE_MAXLEVEL_ABOVE > 0 && sti(randItem.minlevel) > levelCut ) {n = -1;continue;} // Nov21'06 // cant use item if too much higher than player
				if ( CheckAttribute(randItem, "rare") )
				{
					// TIH locator items are rare to begin with, so we beef the probability with pure luck:
					itemProb = stf(randItem.rare) * makefloat(CalcCharacterSkill(GetMainCharacter(),SKILL_SNEAK));
					if ( rand(1000) > (itemProb*1000) ) {n = -1;continue;} // Nov21'06 // its 1000 for a reason
				}
				if ( n >= 0 ) break; // Nov21'06 // if we get this far, then we have a candidate!
			}
			// TIH --> last ditch effort to give them SOMETHING Aug24'06
			if ( n == -1 && frnd() > 0.5 )
			{
				switch ( rand(6) )
				{
					case 0: n = Items_FindItem("100gp", &randItem); break;
					case 1: n = Items_FindItem("250gp", &randItem); break;
					case 2: n = Items_FindItem("medical1", &randItem); break;
					case 3: n = Items_FindItem("potion3", &randItem); break;
					case 4: n = Items_FindItem("indian4", &randItem); break;
					case 5: n = Items_FindItem("indian3", &randItem); break;
					case 6: n = Items_FindItem("pistolrock", &randItem); break;
				}
			}
			// TIH <--
			if (n == -1) return; // TIH die on failed find Nov21'06
		} else {
			// prior basic method
			n = Items_FindItem(RandItems[rand(RANDITEMS_QUANTITY-1)].id, &randItem);
			if (n == -1) return; // TIH die on failed find Nov21'06
		}
		// TIH <--

		lastSpawnTimeString = "LastSpawnTime"+_index;
		_location.(lastSpawnTimeString) = Items_MakeTime(GetTime(), GetDataDay(), GetDataMonth(), GetDataYear());
	}

	if (!CheckAttribute(randItem, "model")) // Sulan: bugfix
	{
		Trace("ItemLogic -> randItem spawn: no model for item "+_location.id+"."+randItem.id);
		return;
	}

	Items_LoadModel(&randItemModels[_index],  randItem);
	SendMessage(&randItemModels[_index], "lffffffffffff", MSG_MODEL_SET_POSITION, makeFloat(al.x), makeFloat(al.y), makeFloat(al.z), makeFloat(al.vx.x), makeFloat(al.vx.y), -makeFloat(al.vx.z), makeFloat(al.vy.x), makeFloat(al.vy.y), -makeFloat(al.vy.z), makeFloat(al.vz.x), makeFloat(al.vz.y), -makeFloat(al.vz.z));

	lastSpawnTimeString = "RandItemType"+_index;
	_location.(lastSpawnTimeString) = n;
}

void RandItems_DrawRandItem(int _index, aref _location, aref al)
{
	string randItemTypeString = "RandItemType"+_index;
// KK -->
	if (!CheckAttribute(_location, randItemTypeString)) {
		trace("ItemLogic -> randItem draw: missing attribute " + randItemTypeString + " in location " + _location.id);
		return;
	}
// <-- KK
	int n = sti(_location.(randItemTypeString));
	if (n < 0) return; // KK

	if (Items[n].model == "")
	{
		Trace("ItemLogic -> randItem draw: no model for item "+_location.id+"."+Items[n].id);
		return;
	}

	Items_LoadModel(&randItemModels[_index],  &Items[n]);
	SendMessage(&randItemModels[_index], "lffffffffffff", MSG_MODEL_SET_POSITION, makeFloat(al.x), makeFloat(al.y), makeFloat(al.z), makeFloat(al.vx.x), makeFloat(al.vx.y), -makeFloat(al.vx.z), makeFloat(al.vy.x), makeFloat(al.vy.y), -makeFloat(al.vy.z), makeFloat(al.vz.x), makeFloat(al.vz.y), -makeFloat(al.vz.z));
}

void RandItem_OnEnterLocator(aref _location, string _locator)
{
	int randIndex = sti(strcut(_locator, 8, strlen(_locator)-1));
	string randItemAttribute = "RandItemType"+randIndex;
	ref chr = GetMainCharacter();
	if (CheckAttribute(_location, randItemAttribute))
	{
		int currentType = sti(_location.(RandItemAttribute));
		if (currentType != -1)
		{
			chr.activeItem.Action = "Pick";
			Log_SetActiveAction(chr.activeItem.Action);
			Log_SetActionLabel(TranslateString("", "Item"));
			chr.activeItem = randIndex;
			chr.activeLocator = _locator;
			chr.activeRandItem = true;
			chr.activeItem.pick = true;
			BLI_RefreshCommandMenu();
		}
	}
}

// ****************** BOXES ********************
void Box_EnterToLocator(aref loc, string locName)
{
	if(!bCabinStarted && !CheckAttribute(loc,locName)) return; // KK
	if (HasSubStr(locName, "private"))
	{ // check if private box opened
		if (!CheckAttribute(loc, locName+".opened")) return;
		if (sti(loc.(locName).opened) != true) return; // KK
	}

	ref chr = GetMainCharacter();
	chr.boxname = locName;

	//MAXIMUS: moved here for preventing wrong action showing -->
	Log_SetActiveAction("OpenBox");
	//MAXIMUS: moved here for preventing wrong action showing <--

	if (ENABLE_AMMOMOD) {// TIH --> mod toggle 7-7-06
// added by MAXIMUS [for gunpowder barrels] -->
		string locType = strcut(locName, 0, strlen(locName)-3);
		string locCur = Locations[FindLocation(chr.location)].filespath.models;
		string locBoard = strcut(locCur, 0, strlen(locCur)-2);
// KK -->
		string barrel = "Carefully! It's a very dangerous barrel!!!";
		string storage = "GUNPOWDER STORAGE. Be careful with opened fire!";
// added by MAXIMUS [for gunpowder barrels] <--

		if (HasSubStr(locName, "box")) {
			Log_SetActiveAction("OpenBox");
			if (ownDeckStarted()) {
				chr.boxname.boxlabel = "SeaBox";
			} else {
				if (LAi_IsBoardingProcess() && !IsFort && !IsTown)
					chr.boxname.boxlabel = "SeaBox";
				else
				{
					if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0 || sti(GetStorylineVar(FindCurrentStoryline(), "BUG_PUZZLES")) > 0)
   					{
						chr.boxname.boxlabel = "";//JRH skip text Chest on "boxes"
					}
					else
					{
						if(sti(GetStorylineVar(FindCurrentStoryline(), "BART_PUZZLES")) > 0)
						{
							if(chr.location == "Admiral_Office" || chr.location == "Governor_Daughter_House" || chr.location == "Cartagena_church" 
							|| chr.location == "Cartagena_church_stairs" || chr.location == "Cartagena_church_cave")
							{
								chr.boxname.boxlabel = "";//JRH skip text Chest on "boxes"
							}
							else
							{
								if(chr.location == "Cartagena_center")
								{
									if(chr.boxname == "box1" || chr.boxname == "box2")
									{
										chr.boxname.boxlabel = "";//JRH skip text Chest on "boxes"
									}
								}
							}
							else chr.boxname.boxlabel = "ItemsBox";
						}
					}
					else chr.boxname.boxlabel = "ItemsBox";

					if(chr.location == "Cartagena_center_facade")
					{
						chr.boxname.boxlabel = "";//JRH skip text Chest on "boxes"
					}

					if(chr.location == "Cartagena_hotel_room1" || chr.location == "Cartagena_hotel_room2")
					{
						if(chr.boxname == "box4") chr.boxname.boxlabel = "";//JRH skip text Chest on "boxes"
					}

					if(chr.location == "Cartagena_hotel_private")
					{
						if(chr.boxname == "box5") chr.boxname.boxlabel = "";//JRH skip text Chest on "boxes"
					}
				}
			}
			if (!CheckAttribute(chr,"BoxName.update")) Event("procChrOpenBox", "s", chr.boxname.boxlabel);
		}
		if (locName == "weaponslocker")
		{
			Log_SetActiveAction("OpenWeaponsLocker");
			chr.boxname.boxlabel = locName;
			if(!CheckAttribute(chr,"BoxName.update")) Event("procChrOpenBox", "s", locName);
		}
		if (locType == "gunpowder") {
			if (locName == "gunpowder_1") {
				if (LAi_IsBoardingProcess()) {
					if (HasSubStr(chr.location, "BOARDING_")) { // KK
						//Log_SetStringToLog(storage);
						Log_SetActiveAction("OpenBarrel");
						if(!CheckAttribute(chr,"BoxName.update")) Event("procChrOpenBox", "s", storage);
					} else {
						CheckReloadAction(chr, "");//MAXIMUS
						if(HasSubStr(locBoard,"locations\decks\udec")) {
							//Log_SetStringToLog(barrel);
							Log_SetActiveAction("OpenBarrel");
							if(!CheckAttribute(chr,"BoxName.update")) Event("procChrOpenBox", "s", barrel);
						}
					}
				} else {
					if (bDeckStarted) {
						if (HasSubStr(locBoard, "locations\decks\udec")) {
							//Log_SetStringToLog(barrel);
							Log_SetActiveAction("OpenBarrel");
							if(!CheckAttribute(chr,"BoxName.update")) Event("procChrOpenBox", "s", barrel);
						} else {
							//Log_SetStringToLog(storage);
							Log_SetActiveAction("OpenBarrel");
							if(!CheckAttribute(chr, "BoxName.update")) Event("procChrOpenBox", "s", storage);
						}
					}
				}
			} else {
				if (HasSubStr(locBoard, "locations\decks\udec")) {
					//Log_SetStringToLog(barrel);
					Log_SetActiveAction("OpenBarrel");
					if(!CheckAttribute(chr, "BoxName.update")) Event("procChrOpenBox", "s", barrel);
				} else {
					Log_SetActiveAction("Nothing");
				}
			}
		}
	} else {
		Log_SetActiveAction("Action");
	}// TIH <-- mod toggle
// <-- KK
	BLI_RefreshCommandMenu();

	// ccc Nov05 Greater Oxbay
	if(loc.id=="Greenford_M_crypt") // PB
	{
		PlaySound("people\step_sand.wav");
		Logit(TranslateString("","Looks like someone has been digging here.."));
		if(GetCharacterEquipByGroup(chr,BLADE_ITEM_TYPE) == "Minersspade" && CheckCharacterItem(chr, "Minersspade"))
			Logit(TranslateString("","Do you want to dig as well? With your ") + GetItemNameByID(chr.equip.blade) + "???"));
		else
			LogIt(TranslateString("","What am I going to dig with? My HANDS? I need a spade!"));
	}
}

void Box_ExitFromLocator();//MAXIMUS: was (aref loc, string locName) - for what?
{
	if(CheckAttribute(GetMainCharacter(),"boxname.boxlabel")) DeleteAttribute(GetMainCharacter(),"boxname.boxlabel");
	if(CheckAttribute(GetMainCharacter(),"boxname")) DeleteAttribute(GetMainCharacter(),"boxname");
	Log_SetActiveAction("Nothing");
	BLI_RefreshCommandMenu();
}

void OpenBoxProcedure()
{

//JRH -->
	if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0)
	{ 
		if(virtual_box == false)
		{
			LoadStorylineFile("", "SL_utils.c");	// PB: To Prevent Errors
			OpenBoxProcedure_WR();
			return;
		}
	}
	if(sti(GetStorylineVar(FindCurrentStoryline(), "BUG_PUZZLES")) > 0)
	{ 
		if(virtual_box == false)
		{
			LoadStorylineFile("", "SL_utils.c");	// PB: To Prevent Errors
			OpenBoxProcedure_BUG();
			return;
		}
	}
	if(sti(GetStorylineVar(FindCurrentStoryline(), "BART_PUZZLES")) > 0)
	{ 
		if(virtual_box == false)
		{
			LoadStorylineFile("", "SL_utils.c");	// PB: To Prevent Errors
			OpenBoxProcedure_BART();
			return;
		}
	}
//<-- JRH
	ref chr = GetMainCharacter();
	if( !CheckAttribute(chr,"boxname") ) return;
	int locidx = FindLoadedLocation();
	if(locidx<0) return;
	string atrName = chr.boxname;
	aref ar;
	if(!HasSubStr(chr.boxname,"corpse")){//MAXIMUS: makes box from corpse with hand-icon in the top-left corner -->
		makearef(ar,Locations[locidx].(atrName));
		if(GetAttributesNum(ar)==0)
		{
			Locations[locidx].(atrName).Money = 0;
			makearef(ar,Locations[locidx].(atrName));
		}

    // JRH -->
//-----------------------------------------------------------------------------------------------------------------
	int gp;
	int pb;
	int pg;
	int mb;
	//note in INTERFACE\itemsbox search JRH: normal box sounds avoided when not wanted

		float x, y, z;
		string lctr;
		ref corpse;
		GetCharacterPos(chr, &x, &y, &z);

		//JRH -->
		if(Locations[locidx].id=="Cartagena_center_facade")
		{
			switch(chr.boxname)
			{
			    //facade 2 ----------------------------------------------------------------------------
				case "box2":
					chr.Cartagena_facade2 = "R";
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Cartagena_center_facade", "box", "box3");
				break;

				case "box3":
					PlaySound("PEOPLE\run_stone.wav");
					if(CheckAttribute(chr,"Cartagena_facade2") && chr.Cartagena_facade2 == "R")
					{
						ChangeCharacterAddressGroup(chr, "Cartagena_center_facade", "reload", "reload13");
					}
					else ChangeCharacterAddressGroup(chr, "Cartagena_center_facade", "reload", "reload12");
				break;

				case "box7":
					chr.Cartagena_facade2 = "L";
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Cartagena_center_facade", "box", "box3");
				break;

			    //facade 1 ----------------------------------------------------------------------------
				case "box4":
					chr.Cartagena_facade1 = "R";
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Cartagena_center_facade", "box", "box5");
				break;

				case "box5":
					PlaySound("PEOPLE\run_stone.wav");
					if(CheckAttribute(chr,"Cartagena_facade1") && chr.Cartagena_facade1 == "R")
					{
						ChangeCharacterAddressGroup(chr, "Cartagena_center_facade", "reload", "reload14");
					}
					else ChangeCharacterAddressGroup(chr, "Cartagena_center_facade", "reload", "reload16");
				break;

				case "box6":
					chr.Cartagena_facade1 = "L";
					PlaySound("PEOPLE\run_stone.wav");
					ChangeCharacterAddressGroup(chr, "Cartagena_center_facade", "box", "box5");
				break;
			}
			return;
		}

		if(Locations[locidx].id=="Cartagena_hotel_room1")
		{
			switch(chr.boxname)
			{
				case "box1":
					if(CheckAttribute(chr,"CH_r1_1") && chr.CH_r1_1 == "open")
					{
						PlaySound("AMBIENT\JAIL\door_003.wav");
						LaunchItemsBox(&ar);
					}
					else
					{
						if(CheckCharacterItem(chr,"hotel_keys"))
						{
							PlaySound("INTERFACE\key_unlock2.wav");
							chr.CH_r1_1 = "open";
						}
						else PlaySound("INTERFACE\locked_window.wav");
					}
				break;

				case "box3":
					PlaySound("INTERFACE\small_door.wav");
					LaunchItemsBox(&ar);
				break;

				case "box4":
					PlaySound("PEOPLE\creak2.wav");
					ChangeCharacterAddressGroup(chr, "Cartagena_hotel_room1", "reload", "reload5");
				break;
			}
			return;
		}

		if(Locations[locidx].id=="Cartagena_hotel_room2")
		{
			switch(chr.boxname)
			{
				case "box1":
					if(CheckAttribute(chr,"CH_r2_1") && chr.CH_r2_1 == "open")
					{
						PlaySound("AMBIENT\JAIL\door_003.wav");
						LaunchItemsBox(&ar);
					}
					else
					{
						if(CheckCharacterItem(chr,"hotel_keys"))
						{
							PlaySound("INTERFACE\key_unlock2.wav");
							chr.CH_r2_1 = "open";
						}
						else PlaySound("INTERFACE\locked_window.wav");
					}
				break;

				case "box2":
					PlaySound("INTERFACE\small_door.wav");
					LaunchItemsBox(&ar);
				break;

				case "box3":
					PlaySound("INTERFACE\small_door.wav");
					LaunchItemsBox(&ar);
				break;

				case "box4":
					PlaySound("PEOPLE\creak2.wav");
					ChangeCharacterAddressGroup(chr, "Cartagena_hotel_room2", "reload", "reload5");
				break;
			}
			return;
		}

		if(Locations[locidx].id=="Cartagena_hotel_room3")
		{
			switch(chr.boxname)
			{
				case "box1":
					if(CheckAttribute(chr,"CH_r3_1") && chr.CH_r3_1 == "open")
					{
						PlaySound("AMBIENT\JAIL\door_003.wav");
						LaunchItemsBox(&ar);
					}
					else
					{
						if(CheckCharacterItem(chr,"hotel_keys"))
						{
							PlaySound("INTERFACE\key_unlock2.wav");
							chr.CH_r3_1 = "open";
						}
						else PlaySound("INTERFACE\locked_window.wav");
					}
				break;

				case "box2":
					PlaySound("INTERFACE\small_door.wav");
					LaunchItemsBox(&ar);
				break;

				case "box3":
					PlaySound("INTERFACE\small_door.wav");
					LaunchItemsBox(&ar);
				break;
			}
			return;
		}

		if(Locations[locidx].id=="Cartagena_hotel_room4")
		{
			switch(chr.boxname)
			{
				case "box1":
					if(CheckAttribute(chr,"CH_r4_1") && chr.CH_r4_1 == "open")
					{
						PlaySound("AMBIENT\JAIL\door_003.wav");
						LaunchItemsBox(&ar);
					}
					else
					{
						if(CheckCharacterItem(chr,"hotel_keys"))
						{
							PlaySound("INTERFACE\key_unlock2.wav");
							chr.CH_r4_1 = "open";
						}
						else PlaySound("INTERFACE\locked_window.wav");
					}
				break;

				case "box2":
					PlaySound("INTERFACE\small_door.wav");
					LaunchItemsBox(&ar);
				break;
			}
			return;
		}

		if(Locations[locidx].id=="Cartagena_hotel_office")
		{
			switch(chr.boxname)
			{
				case "box1":
					if(CheckAttribute(chr,"CH_of_1") && chr.CH_of_1 == "open")
					{
						PlaySound("AMBIENT\JAIL\door_003.wav");
						LaunchItemsBox(&ar);
					}
					else
					{
						if(CheckCharacterItem(chr,"hotel_keys"))
						{
							PlaySound("INTERFACE\key_unlock2.wav");
							chr.CH_of_1 = "open";
						}
						else PlaySound("INTERFACE\locked_window.wav");
					}
				break;

				case "box2":
					PlaySound("PEOPLE\counter_open.wav");
					LaunchItemsBox(&ar);
				break;

				case "box3":
					PlaySound("INTERFACE\chart_move.wav");
					PlaySound("INTERFACE\chart_move.wav");
					LaunchItemsBox(&ar);
				break;
			}
			return;
		}

		if(Locations[locidx].id=="Cartagena_hotel_private")
		{
			switch(chr.boxname)
			{
				case "box1":
					if(CheckAttribute(chr,"CH_pr_1") && chr.CH_pr_1 == "open")
					{
						PlaySound("AMBIENT\JAIL\door_003.wav");
						LaunchItemsBox(&ar);
					}
					else
					{
						if(CheckCharacterItem(chr,"hotel_keys"))
						{
							PlaySound("INTERFACE\key_unlock2.wav");
							chr.CH_pr_1 = "open";
						}
						else PlaySound("INTERFACE\locked_window.wav");
					}
				break;

				case "box2":
					PlaySound("PEOPLE\counter_open.wav");
					LaunchItemsBox(&ar);
				break;

				case "box3":
					PlaySound("PEOPLE\counter_open.wav");
					LaunchItemsBox(&ar);
				break;

				case "box4":
					PlaySound("INTERFACE\chart_move.wav");
					PlaySound("INTERFACE\chart_move.wav");
					LaunchItemsBox(&ar);
				break;

				case "box5":
					if(CheckCharacterItem(chr,"hotel_keys"))
					{
						if(CheckAttribute(chr,"quest.CH_pr_5") && chr.quest.CH_pr_5 == "on")
						{
							return;
						}
						else
						{
							chr.quest.CH_pr_5 = "on";
							PlaySound("INTERFACE\key_unlock.wav");

							LAi_QuestDelay("unlock_hotel_private", 2.0);
						}
					}
					else
					{
						Logit(TranslateString("","Cartagena Hotel"));
						PlaySound("INTERFACE\knock.wav");
					}
				break;
			}
			return;
		}

		if(Locations[locidx].id=="Cartagena Hotel")
		{
			switch(chr.boxname)
			{
				case "box1":
					PlaySound("PEOPLE\counter_open.wav");
					LaunchItemsBox(&ar);
				break;

				case "box2":
					PlaySound("AMBIENT\JAIL\door_003.wav");
					LaunchItemsBox(&ar);
				break;

				case "box3":
					if(CheckAttribute(chr,"CH_ho_3") && chr.CH_ho_3 == "open")
					{
						PlaySound("AMBIENT\JAIL\door_003.wav");
						LaunchItemsBox(&ar);
					}
					else
					{
						if(CheckCharacterItem(chr,"hotel_keys"))
						{
							PlaySound("INTERFACE\key_unlock2.wav");
							chr.CH_ho_3 = "open";
						}
						else PlaySound("INTERFACE\locked_window.wav");
					}
				break;

				case "box4":
					PlaySound("PEOPLE\counter_open.wav");
					LaunchItemsBox(&ar);
				break;
			}
			return;
		}

		if(Locations[locidx].id=="Cartagena_hotel_attic")
		{
			switch(chr.boxname)
			{
				case "box3":
					if(CheckAttribute(chr,"CH_at_3") && chr.CH_at_3 == "open")
					{
						PlaySound("PEOPLE\counter_open.wav");
						LaunchItemsBox(&ar);
					}
					else
					{
						if(CheckCharacterItem(chr,"hotel_keys"))
						{
							PlaySound("INTERFACE\key_unlock2.wav");
							chr.CH_at_3 = "open";
						}
						else PlaySound("INTERFACE\locked_window.wav");
					}
				break;

			}
			return;
		}

		if(Locations[locidx].id=="Roa_cabin")
		{
			switch(chr.boxname)
			{
				case "box1":
					//place your own things here
					LaunchItemsBox(&ar);
				break;
			}
			return;
		}

		if(Locations[locidx].id=="Turks_church")
		{
			switch(chr.boxname)
			{
				case "box1":
					//collection box
					LaunchItemsBox(&ar);

					LAi_QuestDelay("stealing_holycross_Turks", 0.5);
				break;
			}
			return;
		}

		if(Locations[locidx].id=="Tortuga_townhall")
		{
			switch(chr.boxname)
			{
				case "box1":
					PlaySound("AMBIENT\JAIL\door_003.wav");		
				break;

				case "box2":
					PlaySound("PEOPLE\counter_open.wav");
				break;

				case "box3":
					PlaySound("INTERFACE\closet_open.wav");
				break;

				case "box4":
					PlaySound("AMBIENT\JAIL\door_003.wav");	
				break;
			}
		}
		//<-- JRH

		if(Locations[locidx].id=="Havana_Town_02")
		{
			switch(chr.boxname)
			{
				case "box1":
					ChangeCharacterAddressGroup(chr, "Havana_Town_02", "box", "box2");
				break;
				
				case "box2":
					ChangeCharacterAddressGroup(chr, "Havana_Town_02", "box", "box1");
				break;
				
				case "box3":
					ChangeCharacterAddressGroup(chr, "Havana_Town_02", "box", "box4");
				break;
				
				case "box4":
					ChangeCharacterAddressGroup(chr, "Havana_Town_02", "box", "box3");
				break;
			}
			return;
		}
		if(Locations[locidx].id=="Santiago_port")
		{
			switch(chr.boxname)
			{
				case "box1":
					ChangeCharacterAddressGroup(chr, "Santiago_port", "box", "box2");
				break;
				
				case "box2":
					ChangeCharacterAddressGroup(chr, "Santiago_port", "box", "box1");
				break;
				
				case "box3":
					ChangeCharacterAddressGroup(chr, "Santiago_port", "box", "box4");
				break;
				
				case "box4":
					ChangeCharacterAddressGroup(chr, "Santiago_port", "box", "box3");
				break;
				
				case "box5":
					ChangeCharacterAddressGroup(chr, "Santiago_port", "box", "box6");
				break;
				
				case "box6":
					ChangeCharacterAddressGroup(chr, "Santiago_port", "box", "box5");
				break;
				
				case "box7":
					ChangeCharacterAddressGroup(chr, "Santiago_port", "box", "box8");
				break;
				
				case "box8":
					ChangeCharacterAddressGroup(chr, "Santiago_port", "box", "box7");
				break;
				
				case "box9":
					ChangeCharacterAddressGroup(chr, "Santiago_port", "box", "box10");
				break;
				
				case "box10":
					ChangeCharacterAddressGroup(chr, "Santiago_port", "box", "box9");
				break;
			}
			return;
		}
		if(Locations[locidx].id=="Santiago_town_01")
		{
			switch(chr.boxname)
			{
				case "box1":
					ChangeCharacterAddressGroup(chr, "Santiago_town_01", "box", "box2");
				break;
				
				case "box2":
					ChangeCharacterAddressGroup(chr, "Santiago_town_01", "box", "box1");
				break;
				
				case "box3":
					ChangeCharacterAddressGroup(chr, "Santiago_town_01", "box", "box4");
				break;
				
				case "box4":
					ChangeCharacterAddressGroup(chr, "Santiago_town_01", "box", "box3");
				break;
				
				case "box5":
					ChangeCharacterAddressGroup(chr, "Santiago_town_01", "box", "box6");
				break;
				
				case "box6":
					ChangeCharacterAddressGroup(chr, "Santiago_town_01", "box", "box5");
				break;
				
				case "box7":
					ChangeCharacterAddressGroup(chr, "Santiago_town_01", "box", "box8");
				break;
				
				case "box8":
					ChangeCharacterAddressGroup(chr, "Santiago_town_01", "box", "box7");
				break;
				
				case "box9":
					ChangeCharacterAddressGroup(chr, "Santiago_town_01", "box", "box10");
				break;
				
				case "box10":
					ChangeCharacterAddressGroup(chr, "Santiago_town_01", "box", "box9");
				break;
			}
			return;
		}

		// PB: Treasure Quests -->
		//Levis added location dependancy for required item
		string loc = Locations[locidx].id;
		if(chr.boxname == "treasure_box" && GetAttribute(chr, "required_item."+loc) != "-1")
		{
			if(CheckCharacterEquipByGroup(chr,BLADE_ITEM_TYPE) == chr.required_item.(loc))
			{
				if(!CheckAttribute(chr, "digging"))	chr.digging = 6-rand(sti(chr.skill.sneak)/2);
				else								chr.digging = sti(chr.digging)-1;

				if(sti(chr.digging) < 1)
				{
					LogIt(TranslateString("","You dig up a treasurechest"));
					PlaySound("AMBIENT\JAIL\jail_door2.wav");
					//Levis run quest on opening:
					if(CheckAttribute(chr,"quest.treasure_chest."+loc))
					{
						LAi_QuestDelay(chr.quest.treasure_chest.(loc),0);
					}
					DeleteLocatorGlobal(chr.location, "box", "treasure_box");
					if(CheckAttribute(chr,"boxname")) { DeleteAttribute(chr,"boxname"); }
					Log_SetActiveAction("Nothing");
					BLI_RefreshCommandMenu();

					DeleteAttribute(chr, "required_item."+loc);
					DeleteAttribute(chr, "digging"));
					DeleteAttribute(chr, "treasureloc");

					LaunchItemsBox(&ar);
				}
				else
				{
					switch(GetAttribute(chr, "required_item."+loc))
					{
						case "Minerspick":
							PlaySound("people\blade_kling.wav");
							LAi_tmpl_ani_PlayAnimation(chr, "attack_7", 1.0);
							CreateParticleSystemX("cannon_embers",x,y,z, 0.0, 0.0, 0.0, 0);
							break;
						case "Minersspade":
							PlaySound("people\step_sand.wav");
							LAi_tmpl_ani_PlayAnimation(chr, "Ground_look_around", 1.0);
							CreateParticleSystemX("blast_dirt",x,y,z, 0.0, 0.0, 0.0, 0);
							break;
					}

					if (AUTO_SKILL_SYSTEM) {
						AddCharacterExpChar(chr, "Sneak", 50+Rand(100));
					} else {
						AddCharacterExp(chr, 50+Rand(100));
					}
					Logit(TranslateString("","You must dig DEEPER !"));
				}
			}
			else
			{
				switch(GetAttribute(chr, "required_item."+loc))
				{
					case "Minerspick":
						LogIt(TranslateString("","How am I going to pry this loose? I think a pickaxe should do the trick!"));
						break;
					case "Minersspade":
						LogIt(TranslateString("","What am I going to dig with? My HANDS? I need a spade!"));
						break;
				}
			}
			return;
		}
		// PB: Treasure Quests <--

//-----------------------------------------------------------------------------------------------------------
		// ccc Nov05 Greater Oxbay
		if(Locations[locidx].id=="Greenford_M_crypt") // PB
		{
			if(CheckCharacterEquipByGroup(chr,BLADE_ITEM_TYPE) == "Minersspade")
			{
				PlaySound("people\step_sand.wav");
				LAi_tmpl_ani_PlayAnimation(chr, "Ground_look_around", 1.0);
				CreateParticleSystemX("blast_dirt",x,y,z, 0.0, 0.0, 0.0, 0); // PB: Eye Candy
				//LAi_Fade("", "");

				switch(Rand(25))
				{
					case 1:
						PlaySound("INTERFACE\took_item.wav");
						Logit(TranslateString("","Among THIS handful of earth you find a piece of mineral"));
						Logit(TranslateString("","You must dig DEEPER !"));
						GiveItem2Character(chr, "mineral"+ makeint(1 + rand(2)) );
					break;

					case 2:
						PlaySound("INTERFACE\took_item.wav");
						Logit(TranslateString("","On THIS shovelload blinks a jewel.."));
						Logit(TranslateString("","You must dig DEEPER !"));
						GiveItem2Character(chr, "jewelry"+ makeint(1 + rand(13)) );
					break;

					case 3:
						PlaySound("INTERFACE\took_item.wav");
						Logit(TranslateString("","The sword of a buried abbot"));
						Logit(TranslateString("","You must dig DEEPER !"));
						GiveItem2Character(chr, "blade25");
					break;

					case 4:
						PlaySound("INTERFACE\took_item.wav");
						Logit(TranslateString("","An artefact from the temple that once stood here"));
						Logit(TranslateString("","You must dig DEEPER !"));
						GiveItem2Character(chr, "indian"+ makeint(1 + rand(9)) );
					break;

					case 5:
						if (AUTO_SKILL_SYSTEM) {
							AddCharacterExpChar(chr, "Sneak", 50+Rand(100));
						} else {
							AddCharacterExp(chr, 50+Rand(100));
						}
						Logit(TranslateString("","You plunge into the remains of a halfdecayed plaguevictim.."));
						// TODO: use effective value for defence?
						// or even summonSkillFromName???
						chr.chr_ai.poison = 30+rand(50-sti(chr.skill.Sneak)-sti(chr.skill.defence) );
						PlayStereoSound("ambient\tavern\man5.wav");
						PlaySound("OBJECTS\DUEL\sword_inbody1.wav");

						corpse = LAi_CreateFantomCharacterEx(false, 0, true, false, 0.0, "skel1", "", "");
						LAi_SetImmortal(corpse, true);
						corpse.name = XI_ConvertString("The late");
						corpse.corpse = true;
						LAi_SetStunnedTypeNoGroup(corpse);
						LAi_group_MoveCharacter(corpse, LAI_GROUP_CORPSES);
						LAI_group_SetRelationWithAllStock(LAI_GROUP_CORPSES, LAI_GROUP_NEUTRAL);
						TeleportCharacterToPos(corpse, x,y,z);
						corpse.dialog.filename = "corpse_dialog.c";
					break;

					case 6:
						if (AUTO_SKILL_SYSTEM) {
							AddCharacterExpChar(chr, "Sneak", 50+Rand(100));
						} else {
							AddCharacterExp(chr, 50+Rand(100));
						}
						Logit(TranslateString("","Someone's buried here.. but he aint dead!!"));
						CreateParticleSystemX("ball_splash",x+1,y,z, 0.0, 0.0, 0.0, 0);
						PlayStereoSound("ambient\tavern\man5.wav");
						corpse = LAi_CreateFantomCharacterEx(false, 0, false, false, 0.0, "skel3", "", "");
						GiveItem2Character(corpse, "blade5");
						EquipCharacterByItem(corpse, "blade5");
						LAi_SetCitizenType(corpse);
						LAi_group_MoveCharacter(corpse, "Ambush");
						LAi_group_SetRelation("Ambush", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
						LAi_group_SetRelation("Ambush", LAI_GROUP_MONSTERS, LAI_GROUP_ENEMY); // so he fights ghosts
						TeleportCharacterToPos(corpse, x+1,y,z);
						LAi_SetHP(corpse, LAi_GetCharacterHP(chr)*3,  LAi_GetCharacterHP(chr)*3);
						LAi_SetImmortal(corpse, true);
					break;

					case 7:
						if (AUTO_SKILL_SYSTEM) {
							AddCharacterExpChar(chr, "Sneak", 50+Rand(100));
						} else {
							AddCharacterExp(chr, 50+Rand(100));
						}
						Logit(TranslateString("","A file of LIVING Maltese knights comes to exorcise their crypt"));
						Logit(TranslateString("","You might be exorcised as well.."));
						Ambush("maltese", 6, LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
					break;

					case 8:
						if (AUTO_SKILL_SYSTEM) {
							AddCharacterExpChar(chr, "Sneak", 50+Rand(100));
						} else {
							AddCharacterExp(chr, 50+Rand(100));
						}
						Logit(TranslateString("","The grandmaster himself checks his treasure.."));
						PlayStereoSound("VOICE\"+LanguageGetLanguage()+"\Eng_m_a_078.wav");
						corpse = LAi_CreateFantomCharacterEx(false, 3, true, false, 0.0, "priest", "", "");
						GiveItem2Character(corpse, "blade25");
						EquipCharacterByItem(corpse, "blade25");
						LAi_SetCitizenType(corpse);
						LAi_group_MoveCharacter(corpse, "Ambush");
						LAi_group_SetRelation("Ambush", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
						LAi_group_SetRelation("Ambush", LAI_GROUP_MONSTERS, LAI_GROUP_ENEMY); // so he fights ghosts
						TeleportCharacterToPos(corpse, x+4,y,z+4);
						LAi_SetHP(corpse, LAi_GetCharacterHP(chr)*4,  LAi_GetCharacterHP(chr)*4);
						LAi_SetImmortal(corpse, false);
					break;

					case 9:
						if (AUTO_SKILL_SYSTEM) {
							AddCharacterExpChar(chr, "Sneak", 50+Rand(100));
						} else {
							AddCharacterExp(chr, 50+Rand(100));
						}
						if(chr.equip.blade != "bladeX4") {
							PlaySound("OBJECTS\duel\sword_slide3.wav");
							Logit(TranslateString("","Your spade hits a stone and breaks.."));
							TakeItemFromCharacter(chr, GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE)); // PB: Corrected
							RemoveCharacterEquip(chr, BLADE_ITEM_TYPE );
							EquipCharacterByItem(chr, "bladeX4");
						} else {
							Logit(TranslateString("","You must dig DEEPER !"));
						}
					break;

					case 10:
						Logit(TranslateString("","You dig up a treasurechest"));
						PlaySound("AMBIENT\JAIL\jail_door2.wav");
						LaunchItemsBox(&ar);
					break;

					case 11:
						Logit(TranslateString("","You dig up a treasurechest"));
						PlaySound("AMBIENT\JAIL\jail_door2.wav");
						LaunchItemsBox(&ar);
					break;

					case 12:
						Logit(TranslateString("","You dig up a treasurechest"));
						PlaySound("AMBIENT\JAIL\jail_door2.wav");
						LaunchItemsBox(&ar);
					break;

					case 13:
						if (AUTO_SKILL_SYSTEM) {
							AddCharacterExpChar(chr, "Sneak", 50+Rand(100));
						} else {
							AddCharacterExp(chr, 50+Rand(100));
						}
						Logit(TranslateString("","An  Akkelani witchdoctor. Mummified.. but spitting VENOM !"));
						CreateParticleSystemX("ball_splash",x+1,y,z, 0.0, 0.0, 0.0, 0);
						PlayStereoSound("ambient\inca temple\quickpatters.wav");
						corpse = LAi_CreateFantomCharacterEx(false, 3, true, false, 0.0, "mummy", "", "");
						GiveItem2Character(corpse, "bladeX1");
						EquipCharacterByItem(corpse, "bladeX1");
						GiveItem2Character(corpse, "pistolpdart");
						EquipCharacterByItem(corpse, "pistolpdart");
						GiveItem2Character(corpse, "indian"+ makeint(1 + rand(9)) );
						LAi_SetCitizenType(corpse);
						LAi_group_MoveCharacter(corpse, "Ambush");
						LAi_group_SetRelation("Ambush", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
						LAi_group_SetRelation("Ambush", LAI_GROUP_MONSTERS, LAI_GROUP_ENEMY); // so he fights ghosts
						TeleportCharacterToPos(corpse, x+1,y,z);
						LAi_SetHP(corpse, LAi_GetCharacterHP(chr)*2,  LAi_GetCharacterHP(chr)*2);
						LAi_SetImmortal(corpse, false);
					break;

					if (AUTO_SKILL_SYSTEM) {
						AddCharacterExpChar(chr, "Sneak", 50+Rand(100));
					} else {
						AddCharacterExp(chr, 50+Rand(100));
					}
					Logit(TranslateString("","You must dig DEEPER !"));
				}
			}
			else
				LogIt(TranslateString("","What am I going to dig with? My HANDS? I need a spade!"));
			return;
		}

		//ccc boobytrap->
		if(Locations[locidx].type == "house" || Locations[locidx].type == "military")	// ccc Greater Oxbay
		// NK -->
		{
			for(int i = 0; i < 32; i++)
			{
				if(!CheckAttribute(&Characters[LOC_FANTOM_CHARACTERS + i], "id")) continue; //if no ID continue
				if(Characters[LOC_FANTOM_CHARACTERS + i].location == Locations[locidx].id) //if loc is correct
				{
					if(!LAi_IsDead(&Characters[LOC_FANTOM_CHARACTERS + i])) //if not dead
					{ LAi_group_SetRelation(LAI_DEFAULT_GROUP, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
					LAi_group_SetRelation(LAI_GROUP_GUARDS, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);	// ccc Greater Oxbay
					LAi_group_SetRelation(GetCurrentCitizenGroup(), LAI_GROUP_PLAYER, LAI_GROUP_ENEMY); // ccc Dec 05 alerts houseowners
					break; } //only THEN set them hostile
				}
			}
		}
		// NK <--

		// PB: Rewritten -->
		int lock;
		bool OpenLock = false;

		if (ownDeckStarted()) OpenLock = true; // KK
		// If you are on your own ship, all locks are open

		if(REMEMBER_OPEN && CheckAttribute(Locations[locidx],"openboxes."+atrName)) OpenLock = true;
		// If the lock has already been opened, it will stay open

		if(CheckAttribute(Locations[locidx],"jammed."+atrName))
		// If the lock is jammed, it will not open
		{
			Log_SetStringToLog(TranslateString("","This lock will not open. There seems to be a lockpick stuck in it."));
			return;
		}

		if(!OpenLock)
		// If the lock is not yet open, try to open the lock
		{
			lock = rand(100) + 3 * makeint(chr.skill.sneak) + LOCK_OPEN;
			// Chance to open the lock
			if(CheckCharacterEquipByGroup(chr, LOCKPICK_ITEM_TYPE) != "") lock = 2 * lock;
			// Having a lockpick doubles your chance of opening a lock

			if(lock + NO_MINES < 20 && !CheckAttribute(Locations[locidx],"trapboxes."+atrName))
			// Boobytrap: If the boobytrap already exploded, don't explode again
			{
				Log_SetStringToLog(TranslateString("","Boobytrapped") + "!");
				Explosion (chr, rand(20));
				if(ONE_TRAP) Locations[locidx].trapboxes.(atrName) = true;
				return;
			}
			if(lock < 33 && CheckCharacterEquipByGroup(chr, LOCKPICK_ITEM_TYPE) == "")
			// Hurt yourself: You never hurt yourself if you have a lockpick
			{
				if(chr.sex == "woman") PlaySound("OBJECTS\VOICES\DEAD\female\dead_wom4.wav");
				else PlaySound("OBJECTS\VOICES\DEAD\male\dead6.wav");
				Log_SetStringToLog(TranslateString("","Your prying knife slips from the lock... into your hand!"));

				if(AUTO_SKILL_SYSTEM)
				{
					AddPartyExpChar(chr, "Defence", 50+Rand(100));
					AddPartyExpChar(chr, "Sneak", 50+Rand(100));	// LDH added 28Dec08
				}
				else
				{
					AddCharacterExp(chr, 50+Rand(100));
				}
				LAi_ApplyCharacterDamage(chr, 10);
				if (sti(LAi_GetCharacterHP(chr)) < 11) Lai_KillCharacter(chr);
				return;
			}
			if(lock < 66)
			// Fail to open the lock
			{
				if(CheckCharacterEquipByGroup(chr, LOCKPICK_ITEM_TYPE) != "")
				{
					PlaySound("AMBIENT\JAIL\chains.wav");
					Log_SetStringToLog(TranslateString("","You failed to open the lock with your lockpick. Better try again."));
				}
				else
				{
					PlaySound("AMBIENT\JAIL\jail_door1.wav");
					Log_SetStringToLog(TranslateString("","You try to pick the lock with your knife... in vain!"));
				}
				if(AUTO_SKILL_SYSTEM)
				{
					AddPartyExpChar(chr, "Defence", 50+Rand(100));
					AddPartyExpChar(chr, "Sneak", 50+Rand(100)); 	// LDH added 28Dec08
				}
				else
				{
					AddPartyExp(chr, 50+Rand(100));
				}
				return;
			}
			if(CheckCharacterEquipByGroup(chr, LOCKPICK_ITEM_TYPE) != "" && rand(100) < 10)
			// Lockpick fails
			{
				PlaySound("AMBIENT\JAIL\sigh.wav");			// Player sighs because his lockpick failed :-P
				TakeItemFromCharacter(chr,"lockpick");		// One lockpick is taken away
				Log_SetStringToLog(TranslateString("","Your lockpick broke and got stuck in the lock!"));
				Locations[locidx].jammed.(atrName) = true;	// The lock can't be opened anymore
				if(AUTO_SKILL_SYSTEM)
				{
					AddPartyExpChar(chr, "Defence", 50+Rand(100));
					AddPartyExpChar(chr, "Sneak", 50+Rand(100));	// LDH added 28Dec08
				}
				else
				{
					AddPartyExp(chr, 50+Rand(100));
				}
				return;
			}
			OpenLock = true;
		}

		if(OpenLock)
		{
			// PB: Treasure Quests -->
			if(chr.boxname == "treasure_box")
			{	
				LogIt(TranslateString("","You dig up a treasurechest"));
				PlaySound("AMBIENT\JAIL\jail_door2.wav");
				//Levis run quest
				if(CheckAttribute(chr,"quest.treasure_chest."+loc))
				{
					LAi_QuestDelay(chr.quest.treasure_chest.(loc),0);
				}

				DeleteLocatorGlobal(chr.location, "box", "treasure_box");
				if(CheckAttribute(chr,"boxname")) { DeleteAttribute(chr,"boxname"); }
				Log_SetActiveAction("Nothing");
				BLI_RefreshCommandMenu();

				DeleteAttribute(chr, "required_item");
				DeleteAttribute(chr, "digging"));
				DeleteAttribute(chr, "treasureloc");
			}
			// PB: Treasure Quests <--

			if(REMEMBER_OPEN) Locations[locidx].openboxes.(atrName) = true;
			LaunchItemsBox(&ar);
		}
	}
	// PB: Rewritten <--
	if(FindLocation(chr.location)!=-1 && !sti(Interfacestates.Launched))//MAXIMUS: open corpse-box -->
	{
		int tmpi = sti(locations[FindLocation(chr.location)].locators.box.(atrName).corpseIdx);
		aref rootLocs; makearef(rootLocs, locations[FindLocation(chr.location)].locators);
		if(tmpi<0)
		{
			Log_SetStringToLog(TranslateString("","NoItems"));
			DeleteLocatorGlobal(chr.location, "box", atrName);
			if(CheckAttribute(GetMainCharacter(),"boxname")) { DeleteAttribute(GetMainCharacter(),"boxname"); }
			Log_SetActiveAction("Nothing");
			BLI_RefreshCommandMenu();
			return;
		}
		ref chCorpse = GetCharacter(tmpi);
		int bCorpseMode = CORPSEMODE;
		if(CheckAttribute(chCorpse,"CORPSEMODE") && sti(chCorpse.CORPSEMODE)==4) bCorpseMode = 4;
		if(bCorpseMode<4 && !IsEntity(chCorpse))
		{
			Log_SetStringToLog(TranslateString("","NoItems"));
			DeleteLocatorGlobal(chr.location, "box", atrName);
			if(CheckAttribute(GetMainCharacter(),"boxname")) { DeleteAttribute(GetMainCharacter(),"boxname"); }
			Log_SetActiveAction("Nothing");
			BLI_RefreshCommandMenu();
			return;
		}
		aref testItems;
		string itmName = "";
		int it;
		if(CheckAttribute(chCorpse,"dialog.filename") && chCorpse.dialog.filename=="Maltese_corpse_dialog.c")
		{
			chr.forcedlg = true;
			chCorpse.lootDialog = true;
			if(bCorpseMode==4)
			{
				ref tempChar = MalteseKnight();
				DialogMain(tempChar);
				Lai_SetActorType(tempChar);
				LAi_ActorTurnToCharacter(tempChar, GetMainCharacter());
				LAi_ActorAnimation(tempChar, "Bead", "", -1);
				LAi_CharacterLogoff(chCorpse);
				CharacterExitFromLocation(chCorpse);
			}
			else { Event("dlgReady","l", tmpi); }
			DeleteLocatorGlobal(chr.location, "box", atrName);
			if(CheckAttribute(chr,"boxname")) { DeleteAttribute(chr,"boxname"); }
			Log_SetActiveAction("Nothing");
			BLI_RefreshCommandMenu();
			DeleteAttribute(chCorpse,"lootDialog");
			if(CheckAttribute(chCorpse,"CORPSEMODE")) DeleteAttribute(chCorpse,"CORPSEMODE");
		}
		else
		{
			if(!CheckAttribute(chCorpse,"Money")) chCorpse.Money = 0;
			if(CheckAttribute(chCorpse,"Items.bladeX4")) { DeleteAttribute(chCorpse,"Items.bladeX4"); }
			makearef(testItems,chCorpse.items);
			for(it=0; it<GetAttributesNum(testItems); it++)
			{
				itmName = GetAttributeName(GetAttributeN(testItems,it));
				if(GetCharacterItem(chCorpse,itmName)==0) DeleteAttribute(chCorpse,"Items."+itmName);
			}
			if(GetAttributesNum(testItems)==0 && sti(chCorpse.Money)==0) Log_SetStringToLog(TranslateString("","NoItems"));
			else
			{
				PlaySound("OBJECTS\shipcharge\sail_damage1.wav");
				bDeadExchange = true;
				deadChr = chCorpse;
				if(IsCharacterEquipByGroup(chCorpse,BLADE_ITEM_TYPE)) { RemoveCharacterEquip(chCorpse, BLADE_ITEM_TYPE); }
				if(IsCharacterEquipByGroup(chCorpse,GUN_ITEM_TYPE)) { RemoveCharacterEquip(chCorpse, GUN_ITEM_TYPE); }
				if(IsCharacterEquipByGroup(chCorpse,ARMOR_ITEM_TYPE)) { RemoveCharacterEquip(chCorpse, ARMOR_ITEM_TYPE); }
				LaunchLootingScreen();
			}
			if(CheckAttribute(&Locations[FindLoadedLocation()],"building") || bCorpseMode < 3)
			{
				if(bCorpseMode!=4)
				{
					LAi_SetImmortal(chCorpse, false);
					ChangeCharacterAddressGroup(chCorpse, "None", "", "");
					PostEvent("RemoveCorpse", 100, "i", chCorpse);
				}
			}
			if(bCorpseMode==4) { RestoreCharacter(chCorpse); }
			if(CheckAttribute(GetMainCharacter(),"boxname")) { DeleteAttribute(GetMainCharacter(),"boxname"); }
			DeleteLocatorGlobal(chr.location, "box", atrName);
			Log_SetActiveAction("Nothing");
			BLI_RefreshCommandMenu();
		}
	}//MAXIMUS: open corpse-box <--
	//MAXIMUS: makes box from corpse with hand-icon in the top-left corner <--

	virtual_box = false;	//JRH
}

void Box_OnLoadLocation(ref _location)
{
	string locatorName;
	aref boxLocator;
	int i;
	bool isAbordageBox = false;
	if (CheckAttribute(_location, "boarding"))
	{
		if (_location.boarding == "true")
		{
			isAbordageBox = true;
		}
	}

	// private box
	for (i=1; i < MAX_HANDLED_BOXES; i++)
	{
		locatorName = "private"+i;
		if (!FindLocator(_location.id, locatorName, &boxLocator, true))
		{
			break;
		}

		if (!CheckAttribute(_location, locatorName))
		{
			_location.(locatorName) = "";
			_location.(locatorName).open = true;
		}
	}

	// simple box
	for (i=1; i < MAX_HANDLED_BOXES; i++)
	{
		locatorName = "box"+i;
		if (!FindLocator(_location.id, locatorName, &boxLocator, true))
		{
			break;
		}

		// found box
		Box_FillBox(&_location, locatorName, isAbordageBox); // NK do the code in separate function. 05-05-04

	} //for(i)

	// LDH moved from below 09May09
// KK -->
	if (HasSubStr(_location.id, "Boarding_Cabin") == true && FindLocator(_location.id, "weaponslocker", &boxLocator, true) == true) {
		Box_FillBox(&_location, "weaponslocker", isAbordageBox);
	}
// <-- KK

// added by MAXIMUS [for gunpowder barrels] -->
	if (ENABLE_AMMOMOD) {	// LDH change
	// JRH fix oct 06: ammo in GunpowderStorage (own ship) is again generated in itemsbox, some of this below is not used - no changes here
		for (i=1; i < MAX_HANDLED_BOXES; i++)
		{
			locatorName = "gunpowder_"+i;
			if (!FindLocator(_location.id, locatorName, &boxLocator, true))
			{
				break;
			}
			// found box
			string itmID = GetRandSubString("powderflask,ammopouch,pistolbullets,pistolgrapes,musketbullets,pistol13,pistol14,pistolgrenade,pistolbbuss");//JRH moved out pb ab
			int itmIdx = GetItemIndex(itmID);
			int itmQty, ShCl;
			itmQty = 1;
			ShCl = makeint(GetCharacterShipClass(GetMainCharacter()));
			switch(itmID)// MAXIMUS 21.07.2006: moved here from itemsbox interface. if we have some amount of bullets, why should we change it by each open-box procedure?
			{
				case "pistolbullets": itmQty = 300*(8 - ShCl) + rand(100); break;
				case "pistolgrapes": itmQty = 75*(8 - ShCl) + rand(75); break;
				case "musketbullets": itmQty = 15*(8 - ShCl) + rand(15); break;
			}
			string locCur = Locations[FindLocation(_location.id)].filespath.models;
			string locBoard = strcut(locCur, 0, strlen(locCur)-2);
			if(locBoard!="locations\decks\udeck") itmQty = 0;
			if(itmIdx != -1)
			{
				_location.(locatorName).items.(itmID) = itmQty;
				if(bDeckStarted)
				{
					if(locatorName=="gunpowder_1")
					{
						_location.(locatorName).items.pistolbullets = 300*(8 - ShCl) + rand(100);
						_location.(locatorName).items.pistolgrapes = 75*(8 - ShCl) + rand(75);
						_location.(locatorName).items.musketbullets = 15*(8 - ShCl) + rand(15);
					}
				}
			}
			else _location.(locatorName).items.(itmID) = 0;
		}
	}
// added by MAXIMUS [for gunpowder barrels] <--

	// Screwface : transform some locators in random box or permanent box
	// NK do via switch 05-05-04
	switch(_location.id)
	{
		case "Hispaniola_Grot": locatorName = "randitem1";_location.(locatorName).open = true;return; break; //permanent chest
		case  "Roa_Grot": locatorName = "randitem1";_location.(locatorName).open = true;return; break;
		case  "Turks_Cavern_02": locatorName = "randitem1";_location.(locatorName).open = true;return; break;
		case  "Turks_shore_ship": locatorName = "randitem1";_location.(locatorName).open = true; return; break; //Box_FillBox(&_location, locatorName, isAbordageBox); return; break; //Section to make a random chest - NK call func 05-05-04
		case  "Hispaniola_Grot3": locatorName = "randitem1"; _location.(locatorName).open = true; return;break;
		case  "Cuba_Shore_01": locatorName = "randitem1"; _location.(locatorName).open = true; return;break;
		case  "Turks_Cave_Exit_02": locatorName = "Goto4"; _location.(locatorName).open = true; return;break;
		case  "Cayman_Grot_01": locatorName = "randitem1"; _location.(locatorName).open = true; return;break;
		case  "Cayman_Grot_02": locatorName = "randitem4"; _location.(locatorName).open = true; return;break;
		case  "Guadeloupe_Lighthouse": locatorName = "randitem1"; _location.(locatorName).open = true; return;break;
		case  "Oxbay_Jungle_02": locatorName = "citizen04"; _location.(locatorName).open = true; return;break;
		case  "Dungeon 1": locatorName = "randitem1"; _location.(locatorName).open = true; return;break;
		case  "Conceicao_Grot": locatorName = "randitem1"; _location.(locatorName).open = true; return;break;
		case  "Hispaniola_shore_02": locatorName = "citizen04"; _location.(locatorName).open = true; return;break;
	}
}

// NK 05-05-04 made this separate function, not just inside Box_OnLoadLocation()
// that way ScrewFace can call it rather than duplicating the code.
void Box_FillBox(ref _location, string locatorName, bool isAbordageBox)
{
	// LDH 30Apr09
	// make your ship's chests lootable only once per day.
	// unfortunately, this makes ALL your ships' crew cabin boxes, for example, lootable only once per day.
	int SpawnTime = SPAWN_TIME;
	if (ownDeckStarted())
	{
		SpawnTime = 20;		// 20 hours, so you can loot your own ship once per day at the same time every day
		isAbordageBox = false;
	}

	bool needRespawn;
	if (!CheckAttribute(_location, (locatorName)))
	{
		needRespawn = true;
		_location.(locatorName) = Items_MakeTime(GetTime(), GetDataDay(), GetDataMonth(), GetDataYear());
	}
	else
	{
		// LDH 30Apr09
		if ((sti(_location.(locatorName)) + SpawnTime) < Items_MakeTime(GetTime(), GetDataDay(), GetDataMonth(), GetDataYear()))
		{
			needRespawn = true;
			_location.(locatorName) = Items_MakeTime(GetTime(), GetDataDay(), GetDataMonth(), GetDataYear());
		}
		else
		{
			needRespawn = false;
		}
	}
	if(_location.id=="Grotto")		needRespawn = false; // PB: Cursed Coins
	if(_location.id=="Roa_Cabin")	needRespawn = false; // JRH: Place your own things in Roa_cabin

	//respawn items in box
	if (needRespawn || isAbordageBox)
	{
		//clear items in box
		if (CheckAttribute(_location, locatorName))
		{
			aref boxRef;
			makearef(boxRef, _location.(locatorName));
			if (CheckAttribute(boxRef, "items"))
			{
				aref boxItems;
				makearef(boxItems, boxRef.items);
				DeleteAttribute(boxItems,  "");
				/*for (int k=0; k<GetAttributesNum(boxItems);k++)
				{
					string boxItemName = GetAttributeName(boxItems, k);
					DeleteAttribute(boxItems, boxItemName);
				}*/
			}
		}

		//fill box with new items
		string goodItemName;
		int spawnItemsCount = OBJECTS_IN_BOX;
		ref chr = GetMainCharacter();
		spawnItemsCount = spawnItemsCount + spawnItemsCount * makefloat(CalcCharacterSkill(chr,SKILL_SNEAK)) / 10.0; // NK

		if(_location.id=="Greenford_M_crypt")	spawnItemsCount = spawnItemsCount +40;	// ccc Nov05 Greater Oxbay // PB

	//JRH empty boxes -->
		if(_location.id=="Swamp_grot")spawnItemsCount = 0;
		if(_location.id=="swamp_wreck_inside")spawnItemsCount = 0;
		if(_location.id=="Loghouse")spawnItemsCount = 0;
		if(_location.id=="QC_shipyard2_JRH")spawnItemsCount = 0;
		if(_location.id=="QC_store_bedroom")spawnItemsCount = 0;
		if(_location.id=="wr_residence")spawnItemsCount = 0;
		if(_location.id=="wr_kitchen")spawnItemsCount = 0;
		if(_location.id=="wr_food_supply")spawnItemsCount = 0;
		if(_location.id=="wr_armory")spawnItemsCount = 0;
		if(_location.id=="wr_gunpowder")spawnItemsCount = 0;
		if(_location.id=="wr_shop")spawnItemsCount = 0;
		if(_location.id=="loanshark_cellar")spawnItemsCount = 0;
		if(_location.id=="wr_crew")spawnItemsCount = 0;
		if(_location.id=="wr_library")spawnItemsCount = 0;
		if(_location.id=="wr_study")spawnItemsCount = 0;
		if(_location.id=="wr_secret")spawnItemsCount = 0;
		if(_location.id=="wr_prison")spawnItemsCount = 0;
		if(_location.id=="wr_shop_office")spawnItemsCount = 0;
		if(_location.id=="wr_mother")spawnItemsCount = 0;
		if(_location.id=="Dave_Edna_room")spawnItemsCount = 0;
		if(_location.id=="Redmond_shipyard")spawnItemsCount = 0;
		if(_location.id=="wr_cannon_tower")spawnItemsCount = 0;
		if(_location.id=="wr_cavern")spawnItemsCount = 0;		//if coins etc
		if(_location.id=="wr_animists")spawnItemsCount = 0;
		if(_location.id=="wr_gall_galley")spawnItemsCount = 0;
		if(_location.id=="wr_corv_smallcabin_R")spawnItemsCount = 0;
		if(_location.id=="wr_gall_cap_inner")spawnItemsCount = 0;
		if(_location.id=="wr_corv_crew")spawnItemsCount = 0;
		if(_location.id=="wr_corv_capmd")spawnItemsCount = 0;
		if(_location.id=="wr_gall_captain")spawnItemsCount = 0;
		if(_location.id=="Defoes_cabin")spawnItemsCount = 0;
		if(_location.id=="wr_farm_bedroom")spawnItemsCount = 0;
		if(_location.id=="wr_farm_grot")spawnItemsCount = 0;
		if(_location.id=="church_wine_cellar")spawnItemsCount = 0;
		if(_location.id=="church_choir")spawnItemsCount = 0;
		if(_location.id=="wr_church_inside")spawnItemsCount = 0;
		if(_location.id=="wr_wood_tower2")spawnItemsCount = 0;
		if(_location.id=="wr_bedroom")spawnItemsCount = 0;
		if(_location.id=="stonehouse_inside")spawnItemsCount = 0;
		if(_location.id=="wr_church_attic_stairs")spawnItemsCount = 0;
		if(_location.id=="Kristiania_shipwreck")spawnItemsCount = 0;

		if(_location.id=="Legrands_kitchen")spawnItemsCount = 0;
		if(_location.id=="Legrands_grot")spawnItemsCount = 0;
		if(_location.id=="Moultrie_hotel_room1")spawnItemsCount = 0;
		if(_location.id=="Moultrie_hotel_room2")spawnItemsCount = 0;
		if(_location.id=="Moultrie_store")spawnItemsCount = 0;
		if(_location.id=="Moultrie_store_room")spawnItemsCount = 0;
		if(_location.id=="Fort_Moultrie_gunpowder")spawnItemsCount = 0;
		if(_location.id=="Fort_Moultrie_armory")spawnItemsCount = 0;
		if(_location.id=="Lieutenant_G_kitchen")spawnItemsCount = 0;
		if(_location.id=="Lieutenant_G_office")spawnItemsCount = 0;
		if(_location.id=="Lieutenant_G_bedroom")spawnItemsCount = 0;
		if(_location.id=="Fort_M_tower2C")spawnItemsCount = 0;
		if(_location.id=="Fort_M_tower3C")spawnItemsCount = 0;
		if(_location.id=="Fort_M_tower5C")spawnItemsCount = 0;
		if(_location.id=="Dupin_office")spawnItemsCount = 0; 
		if(_location.id=="Dupin_private")spawnItemsCount = 0;
		if(_location.id=="GB_Charleston_town")spawnItemsCount = 0;
		if(_location.id=="GB_Charleston_church_office")spawnItemsCount = 0;
		if(_location.id=="Poe_bedroom")spawnItemsCount = 0;
		if(_location.id=="Landlady_private")spawnItemsCount = 0;  
		if(_location.id=="GB_chinese_gunpowder")spawnItemsCount = 0;
		if(_location.id=="GB_chinese_nitre")spawnItemsCount = 0;
		if(_location.id=="GB_chinese_sulphur")spawnItemsCount = 0;
		if(_location.id=="GB_sulphur_corridor")spawnItemsCount = 0;
		if(_location.id=="GB_chinese_restaurant")spawnItemsCount = 0;
		if(_location.id=="Bessop_tavern")spawnItemsCount = 0;
		if(_location.id=="GB_Charleston_governor_office")spawnItemsCount = 0;
		if(_location.id=="GB_Charleston_governor_bedroom")spawnItemsCount = 0;
		if(_location.id=="GB_Charleston_governor_kitchen")spawnItemsCount = 0;
		if(_location.id=="GB_Charleston_store")spawnItemsCount = 0;

		if(_location.id=="bb_Maltains")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box12.items.Malta_relic = 1;
			locations[FindLocation(chr.location)].box12.items.book66 = 1;
			locations[FindLocation(chr.location)].box23.items.book65 = 1;
			locations[FindLocation(chr.location)].box30.items.book64 = 1;
			
			locations[FindLocation(chr.location)].box31.items.Malta_cross = 1;
			locations[FindLocation(chr.location)].box24.items.Malta_outfit = 1;
			locations[FindLocation(chr.location)].box24.items.Malta_syringe = 1;
			locations[FindLocation(chr.location)].box24.items.Malta_box = 1;
			locations[FindLocation(chr.location)].box22.items.Malta_statue = 1;
			locations[FindLocation(chr.location)].box6.items.Malta_medkit = 1;
			locations[FindLocation(chr.location)].box8.items.Malta_icon = 1;
			locations[FindLocation(chr.location)].box8.items.Malta_censer = 1;
			
			locations[FindLocation(chr.location)].box30.items.Malta_poison = 1;
		}

		if(_location.id=="Citadel_tower_bedroom")
		{
			spawnItemsCount = 0;
		}

		if(_location.id=="Citadel_cave")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box1.items.bladespade = 1;
		}

		if(_location.id=="Cartagena Hotel")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box3.items.potionrum = 1;
			locations[FindLocation(chr.location)].box3.items.meds1 = 1;
		}

		if(_location.id=="Cartagena_hotel_room1")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box1.items.hotel_megaphone = 1;
			locations[FindLocation(chr.location)].box3.items.hotel_sextant = 1;
		}

		if(_location.id=="Cartagena_hotel_room2")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box1.items.hotel_surgery = 1;
		}

		if(_location.id=="Cartagena_hotel_room3")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box2.items.hotel_bandages = 1;
			locations[FindLocation(chr.location)].box3.items.hotel_crucifix = 1;
		}

		if(_location.id=="Cartagena_hotel_room4")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box1.items.meds2 = 1;
			locations[FindLocation(chr.location)].box2.items.hotel_whistle = 1;
		}

		if(_location.id=="Cartagena_hotel_office")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box1.items.hotel_grappling = 1;
			locations[FindLocation(chr.location)].box1.items.jewelry14 = 1;
			locations[FindLocation(chr.location)].box2.items.hotel_spyglass = 1;
			locations[FindLocation(chr.location)].box3.items.meds3 = 1;
		}

		if(_location.id=="Cartagena_hotel_private")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box1.items.hotel_drawing = 1;
			locations[FindLocation(chr.location)].box1.items.potionrum = 2;
			locations[FindLocation(chr.location)].box2.items.hotel_keys = 1;
			locations[FindLocation(chr.location)].box4.items.meds4 = 1;
		}

		if(_location.id=="Cartagena_hotel_attic")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box3.items.hotel_bible = 1;
		}

		if(_location.id=="Legrands_house")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box2.items.pistolmtoon = 2;
			locations[FindLocation(chr.location)].box2.items.machete = 1;
		}

		if(_location.id=="Legrands_attic")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box2.items.emptysack = 3;

			locations[FindLocation(chr.location)].box6.items.treasure10 = 140;	//gold watches
			locations[FindLocation(chr.location)].box6.items.treasure11 = 55;
			locations[FindLocation(chr.location)].box6.items.treasure9 = 4;

			locations[FindLocation(chr.location)].box7.items.treasure1 = 1;		//bowl

			locations[FindLocation(chr.location)].box8.items.treasure6 = 174;	//rings
			locations[FindLocation(chr.location)].box8.items.treasure5 = 25;
			locations[FindLocation(chr.location)].box8.items.treasure7 = 1;

			locations[FindLocation(chr.location)].box9.items.indian6 = 4;		//other
			locations[FindLocation(chr.location)].box9.items.icollection = 1;
			locations[FindLocation(chr.location)].box9.items.jewelry11 = 6;
			locations[FindLocation(chr.location)].box9.items.treasure4 = 1;	

			locations[FindLocation(chr.location)].box10.items.sword_handle1 = 1;	//censers, handles
			locations[FindLocation(chr.location)].box10.items.sword_handle2 = 1;
			locations[FindLocation(chr.location)].box10.items.fake_censer = 2;	
			locations[FindLocation(chr.location)].box10.items.treasure2 = 1;

			locations[FindLocation(chr.location)].box11.items.treasure8 = 20;	//chains
			locations[FindLocation(chr.location)].box11.items.treasure12 = 6;
			locations[FindLocation(chr.location)].box11.items.treasure16 = 4;

			locations[FindLocation(chr.location)].box12.items.holycross1 = 58;	//crucifix
			locations[FindLocation(chr.location)].box12.items.treasure13 = 10;
			locations[FindLocation(chr.location)].box12.items.treasure14 = 13;
			locations[FindLocation(chr.location)].box12.items.treasure15 = 2;
			locations[FindLocation(chr.location)].box12.items.jewelcross = 1;

			locations[FindLocation(chr.location)].box13.items.jewelry2 = 110;	//jewels
			locations[FindLocation(chr.location)].box13.items.jewelry3 = 18;
			locations[FindLocation(chr.location)].box13.items.jewelry4 = 310;
			locations[FindLocation(chr.location)].box13.items.jewelry1 = 21;
			locations[FindLocation(chr.location)].box13.items.treasure3 = 1;	

			locations[FindLocation(chr.location)].box14.items.coin3 = 724;		//coins
			locations[FindLocation(chr.location)].box14.items.coin5 = 312;
			locations[FindLocation(chr.location)].box14.items.coin9 = 519;
			locations[FindLocation(chr.location)].box14.items.coin12 = 1373;
			locations[FindLocation(chr.location)].box14.items.coin13 = 642;
			locations[FindLocation(chr.location)].box14.items.coin16 = 830;
			locations[FindLocation(chr.location)].box14.items.cursedcoin = 100;
		}
		if(_location.id=="GB_Charleston_opium")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box5.items.potion3 = 1;
		}
		if(_location.id=="GB_Charleston_tailorsShop")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box8.items.bladeanchor = 1;
		}
		if(_location.id=="Swamp_loghouse") spawnItemsCount = 0;
		if(_location.id=="Maroon_cavern") spawnItemsCount = 0;
		if(_location.id=="Cartagena_church")spawnItemsCount = 0;
		if(_location.id=="Cartagena_church_cave")spawnItemsCount = 0;
		if(_location.id=="Lieutenant_G_kitchen")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box1.items.copper_cauldron = 1;
			locations[FindLocation(chr.location)].box1.items.bread = 2;
			locations[FindLocation(chr.location)].box1.items.meat = 2;
			locations[FindLocation(chr.location)].box1.items.bladebarrel = 1;
			locations[FindLocation(chr.location)].box1.items.pistolsalt = 1;

			locations[FindLocation(chr.location)].box2.items.indian8 = 4;
			locations[FindLocation(chr.location)].box2.items.plate = 6;
			locations[FindLocation(chr.location)].box2.items.indian16 = 2;

			locations[FindLocation(chr.location)].box3.items.tin_jug = 1;
			locations[FindLocation(chr.location)].box3.items.bladeoilbottle = 2;
			locations[FindLocation(chr.location)].box3.items.barmansknife = 1;
		}
		if(_location.id=="GB_Charleston_church")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box1.items.key22 = 1;
			locations[FindLocation(chr.location)].box5.items.measuring_tape = 1;
			locations[FindLocation(chr.location)].box5.items.peg = 4;
			locations[FindLocation(chr.location)].box5.items.magnet = 1;
			locations[FindLocation(chr.location)].box5.items.nails = 6;
			locations[FindLocation(chr.location)].box5.items.bladepickaxe2 = 1;

			locations[FindLocation(chr.location)].box7.items.fake_candelabre = 2;
			locations[FindLocation(chr.location)].box7.items.wax_candles = 4;
			locations[FindLocation(chr.location)].box8.items.potionwine2 = 1;
			locations[FindLocation(chr.location)].box8.items.fake_chalice = 1;
			locations[FindLocation(chr.location)].box9.items.altar_bread = 5;
			locations[FindLocation(chr.location)].box10.items.fake_censer = 1;
			locations[FindLocation(chr.location)].box11.items.pliers = 1;
			locations[FindLocation(chr.location)].box12.items.book61A = 1;
			locations[FindLocation(chr.location)].box13.items.book_exorcist = 1;
			locations[FindLocation(chr.location)].box14.items.flyswatter = 1;
			locations[FindLocation(chr.location)].box15.items.shrine = 1;
			locations[FindLocation(chr.location)].box15.items.jewelcross = 1;
			locations[FindLocation(chr.location)].box16.items.cowl = 16;
		}
		if(_location.id=="Lieutenant_G_bedroom")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box1.items.book2 = 1;
			locations[FindLocation(chr.location)].box1.items.book26 = 1;
			locations[FindLocation(chr.location)].box1.items.book27 = 1;
			locations[FindLocation(chr.location)].box1.items.book33 = 1;
			locations[FindLocation(chr.location)].box1.items.book11 = 1;
			locations[FindLocation(chr.location)].box1.items.book52 = 1;
		}
		if(_location.id=="Lieutenant_G_office")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box1.items.map = 1;
			locations[FindLocation(chr.location)].box1.items.glasses = 1;
			locations[FindLocation(chr.location)].box1.items.pistolgrenade = 1;

			locations[FindLocation(chr.location)].box2.items.bladeflag_usa = 1;

			locations[FindLocation(chr.location)].box3.items.microscope = 1;

			locations[FindLocation(chr.location)].box4.items.blade24 = 1;
			locations[FindLocation(chr.location)].box4.items.blue_uniform = 1;

			locations[FindLocation(chr.location)].box5.items.leeches = 1;
			locations[FindLocation(chr.location)].box5.items.fish = 1;

			locations[FindLocation(chr.location)].box6.items.G_journal = 1;
			locations[FindLocation(chr.location)].box6.items.G_letter1 = 1;
			locations[FindLocation(chr.location)].box6.items.G_letter2 = 1;
			locations[FindLocation(chr.location)].box6.items.G_letter3 = 1;
		}
		if(_location.id=="Fort_Moultrie_armory")
		{
			locations[FindLocation(chr.location)].box2.items.medical2 = 1;
		}
		if(_location.id=="Poe_bedroom")
		{
			locations[FindLocation(chr.location)].box1.items.Poes_clothes = 1;
			locations[FindLocation(chr.location)].box1.items.2winebottles = 1;
			locations[FindLocation(chr.location)].box1.items.Poes_urn = 1;
			locations[FindLocation(chr.location)].box2.items.Poes_books = 1;
		}
		if(_location.id=="Pym_drawing_room")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box7.items.book56 = 1;
			locations[FindLocation(chr.location)].box6.items.book57 = 1;
		}
		if(_location.id=="Pym_bedroom")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box2.items.potionrum = 1;
			locations[FindLocation(chr.location)].box5.items.book55A = 1;
		}
		if(_location.id=="Pym_study")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box3.items.book60 = 1;
			locations[FindLocation(chr.location)].box2.items.book59 = 1;
			locations[FindLocation(chr.location)].box7.items.book58 = 1;
			locations[FindLocation(chr.location)].box4.items.bladeemptysack_P = 1;
		}
		if(_location.id=="Pym_towerroom")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box6.items.pistolsextant2 = 1;
		}
		if(_location.id=="Bishops_Hostel")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box57.items.mixed_treasure = 9;
		}
		if(_location.id=="Tortuga_townhall")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box1.items.medical1 = 1;
			locations[FindLocation(chr.location)].box2.items.jewelry5 = 1;
			locations[FindLocation(chr.location)].box3.items.potion3 = 1;
			locations[FindLocation(chr.location)].box3.items.bladeX3 = 1;
			locations[FindLocation(chr.location)].box4.items.indian4 = 1;
		}

		if(_location.id=="Oranjestad_store_02")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box1.items.indian4 = 1;
		}

		if(_location.id=="Turks_church")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box1.items.holycross1 = 1;
		}

		if(_location.id=="Turks_tavern_kitchen")
		{
			spawnItemsCount = 0;
		}

		if(_location.id=="Turks_tavern_bedroom")
		{
			spawnItemsCount = 0;
		}

		if(_location.id=="BB_sloop_cabin")
		{
			spawnItemsCount = 0;
		}

		if(_location.id=="BB_sloop_hold")
		{
			spawnItemsCount = 0;
		}

		if(_location.id=="BB_prison_alcove")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box7.items.key3 = 1;
		}

		if(_location.id=="BB_graveyard") spawnItemsCount = 0;

		if(_location.id=="BB_abbess") 
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box1.items.crypt_sketch = 1;
		}

		if(_location.id=="BB_church_room")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box4.items.bladehammer = 1;	
		}

		if(_location.id=="BB_crypt1")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box1.items.potion4 = 1;
			locations[FindLocation(chr.location)].box1.items.silvercross = 1;
			locations[FindLocation(chr.location)].box2.items.icon = 1;
			locations[FindLocation(chr.location)].box3.items.rosary = 1;
			locations[FindLocation(chr.location)].box4.items.bladebroom = 1;
			locations[FindLocation(chr.location)].box5.items.bladebroom = 1;
		}

		if(_location.id=="BB_crypt2_1")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box1.items.wax_candles = 1;
		}

		if(_location.id=="BB_crypt2_2")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box1.items.altar_bread = 1;
			locations[FindLocation(chr.location)].box1.items.potionwine2 = 2;
		}

		if(_location.id=="BB_misericord")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box4.items.pistolcenser = 1;
			locations[FindLocation(chr.location)].box4.items.potion3 = 1;
			locations[FindLocation(chr.location)].box3.items.treasure7 = 1;
		}

		if(_location.id=="BB_Eden_tunnel")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box4.items.corkscrew = 1;
			locations[FindLocation(chr.location)].box1.items.bladebottlew5 = 1;
			locations[FindLocation(chr.location)].box1.items.pistolbottlew5 = 1;
			locations[FindLocation(chr.location)].box2.items.bladebottlew5 = 1;
			locations[FindLocation(chr.location)].box2.items.pistolbottlew5 = 1;
		}

		if(_location.id=="wr_farm_kitchen")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box1.items.pistolretort3 = 6;
		}

		if(_location.id=="wr_farm_servant")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box1.items.pistolnitre = 4;
		}

		if(_location.id=="wr_farm_alchemy")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box1.items.pistolcalciumsack = 5;
			locations[FindLocation(chr.location)].box1.items.pistolcharcoal_WR = 8;
		}

		if(_location.id=="wr_farm_alchemy2")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box1.items.pistolsalt = 6;
			locations[FindLocation(chr.location)].box2.items.pistolcloth = 7;
			locations[FindLocation(chr.location)].box3.items.pistolfunnel = 1;
			locations[FindLocation(chr.location)].box3.items.bladebottle_CE0 = 9;
		}

		if(_location.id=="wr_farm_booty")
		{
			spawnItemsCount = 0;
			locations[FindLocation(chr.location)].box5.items.bladebottle_BE0 = 8;
			locations[FindLocation(chr.location)].box7.items.pistolbucket_dung = 4;
			locations[FindLocation(chr.location)].box7.items.pistolstonebasket_G = 6;
			locations[FindLocation(chr.location)].box7.items.pistolsulphur_WR = 5;
		}

		if(_location.id=="wr_farm_booty2")
		{
			spawnItemsCount = 0;

			locations[FindLocation(chr.location)].box3.items.bladebottle_CV1_cao = 4;
			locations[FindLocation(chr.location)].box3.items.pistolstonebasket_M = 4;
			locations[FindLocation(chr.location)].box3.items.pistolstonebasket_B = 5;
			locations[FindLocation(chr.location)].box1.items.pistolstonebasket_R = 4;
		}

		for (int j = 0; j < spawnItemsCount; j++) {
			if (needRespawn || isAbordageBox)
			{
				string itemID;
				if (SpawnItem(chr, &itemID,isAbordageBox,makefloat(CalcCharacterSkill(chr,SKILL_SNEAK)))) // NK
				{
// KK -->
					if (locatorName == "weaponslocker") {
						while (true) {
							int itemidx = GetItemIndex(itemID);
							if (itemidx != -1) {
								if (CheckAttribute(&Items[itemidx], "groupID") == true) {
									if (Items[itemidx].groupID == BLADE_ITEM_TYPE || Items[itemidx].groupID == GUN_ITEM_TYPE || Items[itemidx].groupID == ARMOR_ITEM_TYPE) break;
								}
							}
							if (SpawnItem(chr, &itemID,isAbordageBox,makefloat(CalcCharacterSkill(chr,SKILL_SNEAK)))) continue;
						}
					}
// <-- KK
					if (CheckAttribute(_location, locatorName+".items."+itemID))
					{
						_location.(locatorName).items.(itemID) = sti(_location.(locatorName).items.(itemID)) + 1;
					}
					else
					{
						_location.(locatorName).items.(itemID) = 1;
					}
				}
			}
		}
	}//respawn
}

bool SpawnItem(ref _chr, ref _id, bool isAbordageBox, float luck)
{
	float rarity;
	int currentPeriod = GetCurrentPeriod();
	if(RANDITEMS_QUANTITY < 1) return false; // NK
	int i = rand(RANDITEMS_QUANTITY-1);
	int chrRank = sti(_chr.rank);
	if ( IT_RPG_STYLE ) chrRank += roundup(luck / 2);// TIH rpg_style only - add luck to this Jul25'06
	int itemRank = 0;
	aref randItem;

	if (Items_FindItem(RandItems[i].id, &randItem) == -1)
	{
		return SpawnAnotherItemChance(&_chr, &_id, isAbordageBox, luck, &randItem);
	}
	if (CheckAttribute(randItem, "minLevel"))
	{
		itemRank = sti(randItem.minLevel);
	}
	if (itemRank > chrRank)
	{
		return SpawnAnotherItemChance(&_chr, &_id, isAbordageBox, luck, &randItem);
	}
	// Sulan: weapons periods -->
	if (CheckAttribute(randItem, "firstperiod") && CheckAttribute(randItem, "lastperiod"))
	{
		// item is not yet available
		if(currentPeriod  < sti(randItem.firstperiod)) return SpawnAnotherItemChance(&_chr, &_id, isAbordageBox, luck, &randItem);
		// item is available no more
		if(currentPeriod  > sti(randItem.lastperiod)) return SpawnAnotherItemChance(&_chr, &_id, isAbordageBox, luck, &randItem);
	}
	// <-- Sulan: weapons periods

	// Sulan: Improved rarity code -->
	float itemProb = 0.03; // default: 3% chance for items without rarity
	if (CheckAttribute(randItem, "rare"))		itemProb = stf(randItem.rare);
	if(itemProb == 0.0) return SpawnAnotherItemChance(&_chr, &_id, isAbordageBox, luck, &randItem); // unique items
	if (isAbordageBox)
	{
		if (CheckAttribute(randItem, "skiprand"))
		{
			// if item should not appear at random
			if(randItem.skiprand == true) return SpawnAnotherItemChance(&_chr, &_id, isAbordageBox, luck, &randItem);
		}
	}
	rarity=frand(1);
	trace("trying to spawn item: "+randItem.id+" with rarity="+rarity+" itemProb="+itemProb*ModItemQtyPlayer());
	if(itemProb*ModItemQtyPlayer()<=rarity) return SpawnAnotherItemChance(&_chr, &_id, isAbordageBox, luck, &randItem);
	// <-- Sulan: Improved rarity code
	// NK -->
	_id = randItem.id; return true;
	// TIH --> fixed to prevent endless loop chance (thats bad) Aug24'06
	// forces it to no higher than .5 chance (in case someone sets it to 1.0 in IS.h !!!)
	// TIH <--
	// NK <-- return true;
}

bool SpawnAnotherItemChance(ref _chr, ref _id, bool isAbordageBox, float luck, aref randItem)
{
	int noSkipChance = RAND_ITEM_NOSKIP;
	if(RAND_ITEM_NOSKIP > 0.5) noSkipChance = 0.5;
	if(frnd() > noSkipChance && !CheckAttribute(randItem,"groupID")) { return false; }
	else { return SpawnItem(&_chr, &_id, isAbordageBox, luck); }
}

bool SpawnItemOrg(ref _chr, ref _id, bool isAbordageBox, float luck)
{
	float rarity;
	int currentPeriod = GetCurrentPeriod();
	if(RANDITEMS_QUANTITY < 1) return false; // NK
	int i = rand(RANDITEMS_QUANTITY-1);
	int chrRank = sti(_chr.rank);
	if ( IT_RPG_STYLE ) chrRank += roundup(luck / 2);// TIH rpg_style only - add luck to this Jul25'06
	int itemRank = 0;
	aref randItem;
	bool ok = true; // NK
	if (Items_FindItem(RandItems[i].id, &randItem) == -1)
	{
		ok = false; // NK - return false;
	}
	if (CheckAttribute(randItem, "minLevel"))
	{
		itemRank = sti(randItem.minLevel);
	}
	if (itemRank > chrRank)
	{
		ok = false; //NK - return false;
	}
	// Sulan: Historic Weapons -->
	if (CheckAttribute(randItem, "firstperiod") && CheckAttribute(randItem, "lastperiod"))
	{
		if(currentPeriod  < sti(randItem.firstperiod)) ok=false; // item is not yet available
		if(currentPeriod  > sti(randItem.lastperiod)) ok=false;  // item is available no more
	}
	// <-- Sulan: Historic Weapons

	// Sulan: Improved rarity code -->
	float itemProb = 0.03; // default: 3% chance for items without rarity
	if (CheckAttribute(randItem, "rare"))		itemProb = stf(randItem.rare);
	if(itemProb == 0.0) ok = false; // unique items
	if (isAbordageBox)
	{
		if (CheckAttribute(randItem, "skiprand"))
		{
			if(randItem.skiprand == true) ok = false;  // if item should not appear at random
		}
	}
	rarity=frand(1);
	if(itemProb*ModItemQtyPlayer()<=rarity) ok = false;
	// <-- Sulan: Improved rarity code
	
	trace("trying to spawn item: "+randItem.id+" with ok = "+ok+" rarity="+rarity+" itemProb="+itemProb*ModItemQtyPlayer());

	// NK -->
	if(ok) { _id = randItem.id; return true; }
	// TIH --> fixed to prevent endless loop chance (thats bad) Aug24'06
	// forces it to no higher than .5 chance (in case someone sets it to 1.0 in IS.h !!!)
	int noSkipChance = RAND_ITEM_NOSKIP;
	if(RAND_ITEM_NOSKIP > 0.5) noSkipChance = 0.5;
	if(frnd() > noSkipChance && !CheckAttribute(randItem,"groupID")) { return false; }
	else { return SpawnItem(&_chr, &_id, isAbordageBox, luck); }
	// TIH <--
	// NK <-- return true;
}
