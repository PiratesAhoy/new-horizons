#define ITEM_MODE_SWAP		0
#define ITEM_MODE_TAKE		1
#define ITEM_MODE_NONE		2
//#define ITEM_MODE_INFO		3

aref g_refItems;

int nCurScroll1;
int nCurScroll2;

string oldNodeName="";
int oldItemMode = -1;

bool g_bIBoxUsed;

string oldCurScrollName = "ONE_ITEMSLIST";

string boxName;		//JRH missing ;
string boxType;
string curLoc;
string curLocId;	//JRH bookshelf
bool isItemsBox = false;

int idLngFile;

bool bEnableDown = false;
ref lootedChar;
bool noConfirm = false; // added by MAXIMUS [confirmation dialog will be disabled, if character hasn't any items]

void InitInterface_RS(string iniName,ref itemsRef,string faceID)
{
	ref pch = GetMainCharacter();

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

	lootedChar = itemsRef;

// changed by MAXIMUS -->
   //JRH -->
	string weaponID = GetCharacterEquipByGroup(pch,GUN_ITEM_TYPE);
	aref weapon;
	Items_FindItem(weaponID, &weapon);

	int s; //shots
	int ShCl = makeint(GetCharacterShipClass(pch));
    //JRH <--

	// TIH lets just set this here, so its not pasted every other line below 7-7-06
	// this is never changed to true anyway, so I really don't understand the need for it
	isGunpowder = false;

	// TIH --> total house cleaning 7-7-06
	if(faceID=="")
	{
		boxName = pch.boxname;
		boxType = strcut(boxName, 0, strlen(boxName)-3);
		curLoc = Locations[FindLocation(pch.location)].filespath.models;
		curLocId = Locations[FindLocation(pch.location)].id;	//JRH bookshelf
		int powderCount;
		string whichInterface = "";

		//changed by MAXIMUS: box-labels weren't right -->
			if(boxName=="WeaponsLocker") { whichInterface = "Weaponslocker"; }
			else
			{
				if(boxType == "gunpowder")
				{
					if(boxName == "gunpowder_1")
					{
						if(LAi_IsBoardingProcess())
						{
							if (HasSubStr(pch.location, "BOARDING_")) // KK
								whichInterface = "GunpowderStorageEnemy";
							else
								whichInterface = "GunpowderBarrelEnemy";
						}
						else
						{
							if(HasSubStr(curLoc,"locations\decks\udec")) { whichInterface = "GunpowderBarrel"; }
							else { whichInterface = "GunpowderStorage"; }
						}
					}
					else
					{
						if(LAi_IsBoardingProcess()) { whichInterface = "GunpowderBarrelEnemy"; }
						else { whichInterface = "GunpowderBarrel"; }
					}
				}
				else
				{
					if(HasSubStr(boxName, "box") && HasSubStr(curLoc, "locations\decks")) { whichInterface = "SeaBox"; }
					else { whichInterface = "ItemsBox"; }
				}

			//JRH -->
				switch (curLocId)
				{
					case "New_cloister_library":
						if(boxName == "box8" || boxName == "box9" || boxName == "box10" || boxName == "box11" || boxName == "box12"
						|| boxName == "box14" || boxName == "box15" || boxName == "box18" || boxName == "box19" || boxName == "box20")
						{
							whichInterface = "BookShelf";
						}
						else whichInterface = "ItemsBox";
					break;
				
					case "wr_library":
						whichInterface = "BookShelf";
					break;

					case "wr_residence":
						if(boxName == "box1" || boxName == "box3")
						{
							whichInterface = "BookShelf";
						}
						else whichInterface = "ItemsBox";
					break;

					case "wr_study":
						if(boxName == "box5" || boxName == "box7")
						{
							whichInterface = "ItemsBox";
						}
						
						if(boxName == "box16") 
						{
							whichInterface = "Rogerscorpse";
						}
						
						if(boxName == "box1" || boxName == "box2" || boxName == "box3"
						|| boxName == "box4" || boxName == "box6")
						{
							whichInterface = "BookShelf";
						}
					break;

					case "Defoes_cabin":
						if(boxName == "box2" || boxName == "box3")
						{
							whichInterface = "BookShelf";
						}
						else whichInterface = "ItemsBox";
					break;

					case "wr_farm_servant":
						if(boxName == "box2")
						{
							whichInterface = "BookShelf";
						}
						else whichInterface = "ItemsBox";
					break;

					case "wr_church_inside":
						if(boxName == "box1")
						{
							whichInterface = "CollectionBox";
						}
						else whichInterface = "ItemsBox";
					break;

					case "GB_Charleston_church":
						if(boxName == "box1")
						{
							whichInterface = "CollectionBox";
						}
						else whichInterface = "ItemsBox";
					break;

					case "Turks_church":
						if(boxName == "box1")
						{
							whichInterface = "CollectionBox";
						}
						else whichInterface = "ItemsBox";
					break;

					case "wr_secret":
						if(boxName == "box1")
						{
							whichInterface = "StevensonChest";
						}
						else whichInterface = "ItemsBox";
					break;

					case "wr_cannon_tower":
						if(boxName == "box1")
						{
							whichInterface = "GunpowderBarrel";
						}
						else whichInterface = "ItemsBox";
					break;

					case "wr_gunpowder":
						if(boxName == "box3")
						{
							whichInterface = "GunpowderBarrel";
						}
						else whichInterface = "ItemsBox";
					break;

					case "Legrands_house":
						if(boxName == "box7")
						{
							whichInterface = "BookShelf";
						}
						else
						{
							if(boxName == "box1" || boxName == "box3" || boxName == "box5"
							|| boxName == "box6" || boxName == "box7")
							{
								whichInterface = "ItemsBox";
							}
						}
					break;

					case "Legrands_attic":
						if(boxName == "box6" || boxName == "box7" || boxName == "box8"
						|| boxName == "box9" || boxName == "box10" || boxName == "box11"
						|| boxName == "box12" || boxName == "box13")
						{
							whichInterface = "TreasureSack";
						}
						else whichInterface = "ItemsBox";
					break;

					case "Poe_bedroom":
						if(boxName == "box2")
						{
							whichInterface = "BookShelf";
						}
						else whichInterface = "ItemsBox";
					break;

					case "Cartagena_church":
						if(boxName == "box4")
						{
							whichInterface = "CollectionBox";
						}
						else whichInterface = "ItemsBox";
					break;

					case "Pym_drawing_room":
						if(boxName == "box6" || boxName == "box7")
						{
							whichInterface = "BookShelf";
						}
						else whichInterface = "ItemsBox";
					break;

					case "Pym_bedroom":
						if(boxName == "box5")
						{
							if(CheckAttribute(pch, "quest.pym_niche") && pch.quest.pym_niche == "open")
							{
								whichInterface = "BookShelf";
							}
							else whichInterface = "ItemsBox";
						}
						else whichInterface = "ItemsBox";
					break;

					case "Pym_study":
						if(boxName == "box2" || boxName == "box3" || boxName == "box7")
						{
							whichInterface = "BookShelf";
						}
						else whichInterface = "ItemsBox";
					break;

					case "Kristiania_townhall_entre":
						if(boxName == "box4" || boxName == "box5")
						{
							whichInterface = "BookShelf";
						}
						else whichInterface = "ItemsBox";
					break;
					
					case "Kristiania_townhall":
						if(boxName == "box4" || boxName == "box5")
						{
							whichInterface = "BookShelf";
						}
						else whichInterface = "ItemsBox";
					break;

					case "Redhouse_room":
						if(boxName == "box1" || boxName == "box2")
						{
							whichInterface = "BookShelf";
						}
						else whichInterface = "ItemsBox";
					break;

					case "Kristiania_cathedral":
						if(boxName == "box6")
						{
							whichInterface = "CollectionBox";
						}
						else whichInterface = "ItemsBox";
					break;

					case "BB_sloop_wreck_hold":
						if(boxName == "box1")
						{
							whichInterface = "GunpowderStorage_JRH";
						}
						else whichInterface = "ItemsBox";
					break;

					case "BB_prison_officer":
						if(boxName == "box13") 
						{
							whichInterface = "Tookdrunk";
						}
						else whichInterface = "ItemsBox";
					break;

					case "BB_careen_holdS":
						if(boxName == "box1") 
						{
							whichInterface = "GunpowderStorage_JRH";
						}
						else whichInterface = "ItemsBox";
					break;
				
					case "BB_careen_capmd_2":
						if(boxName == "box5" || boxName == "box6" || boxName == "box7" || boxName == "box8") 
						{
							whichInterface = "Weaponslocker";
						}
						else whichInterface = "ItemsBox";
					break;
				}
			//<-- JRH
				
			}
		//changed by MAXIMUS: box-labels weren't right -->

		// do specific actions based on the whichInterface HERE
		switch (whichInterface)
		{
		    //JRH -->
			case "Rogerscorpse":
				GameInterface.title = "titleRogerscorpse";
				PlaySound("PEOPLE\clothes1.wav");
				isGunpowder = false;
				isItemsBox = true;
				break;

			case "BookShelf":
				GameInterface.title = "titleBookShelf";
				PlaySound("AMBIENT\RESIDENCE\some2.wav");
				isGunpowder = false;
				isItemsBox = true;
				break;

			case "CollectionBox":
				GameInterface.title = "titleCollectionBox";
				PlaySound("INTERFACE\collection_box.wav");
				isGunpowder = false;
				isItemsBox = true;
				break;

			case "StevensonChest":
				GameInterface.title = "titleStevensonChest";
				PlaySound("AMBIENT\JAIL\door_003.wav");
				isGunpowder = false;
				isItemsBox = true;
				break;

			case "TreasureSack":
				GameInterface.title = "titleTreasureSack";
				PlaySound("PEOPLE\clothes1.wav");
				isGunpowder = false;
				isItemsBox = true;
				break;

			case "GunpowderStorage_JRH":
				//empty
				GameInterface.title = "titleGunpowderStorage";
				PlaySound("AMBIENT\JAIL\door_003.wav");
				isGunpowder = false;
				isItemsBox = true;
				break;

			case "Tookdrunk":
				GameInterface.title = "titleTookdrunk";
				PlaySound("OBJECTS\SHIPCHARGE\sail_damage1.wav");
				isGunpowder = false;
				isItemsBox = true;
				break;
		    //<-- JRH

			case "Weaponslocker":
				GameInterface.title = "titleWeaponslocker";
				PlaySound("AMBIENT\JAIL\door_003.wav");// was door_002 which is corrupted in a way
				isGunpowder = false;
				isItemsBox = true;
				break;

			case "SeaBox":
				GameInterface.title = "titleSeaBox";
				PlaySound("AMBIENT\JAIL\door_001.wav");
				isGunpowder = false;
				isItemsBox = true;
				break;

			case "ItemsBox":
				GameInterface.title = "titleItemsBox";
			    //JRH to avoid standard box sound when keys etc etc -->
				if(Locations[FindLocation(pch.location)].id == "QC_shipyard2_JRH" || Locations[FindLocation(pch.location)].id == "wr_kitchen"
				|| Locations[FindLocation(pch.location)].id == "wr_armory" || Locations[FindLocation(pch.location)].id == "Dave_Edna_room"
				|| Locations[FindLocation(pch.location)].id == "wr_prison" || Locations[FindLocation(pch.location)].id == "wr_food_supply"
				|| Locations[FindLocation(pch.location)].id == "wr_gibbet" || Locations[FindLocation(pch.location)].id == "wr_animists"
				|| Locations[FindLocation(pch.location)].id == "wr_mine" || Locations[FindLocation(pch.location)].id == "wr_bedroom"
				|| Locations[FindLocation(pch.location)].id == "Redmond_UsurerHouse" || Locations[FindLocation(pch.location)].id == "Tavern_storeroom"
				|| Locations[FindLocation(pch.location)].id == "wr_church_attic" || Locations[FindLocation(pch.location)].id == "Redmond_shipyard"
				|| Locations[FindLocation(pch.location)].id == "wr_cannon_tower" || Locations[FindLocation(pch.location)].id == "wr_cavern"
				|| Locations[FindLocation(pch.location)].id == "wr_church_inside" || Locations[FindLocation(pch.location)].id == "church_wine_cellar"
				|| Locations[FindLocation(pch.location)].id == "Swamp_grot" || Locations[FindLocation(pch.location)].id == "Legrands_house"
				|| Locations[FindLocation(pch.location)].id == "Legrands_kitchen" || Locations[FindLocation(pch.location)].id == "Moultrie_hotel_room1"
				|| Locations[FindLocation(pch.location)].id == "Moultrie_hotel_room2" || Locations[FindLocation(pch.location)].id == "Fort_M_tower2C"
				|| Locations[FindLocation(pch.location)].id == "Fort_M_tower3C" || Locations[FindLocation(pch.location)].id == "Lieutenant_G_kitchen"
				|| Locations[FindLocation(pch.location)].id == "Lieutenant_G_office" || Locations[FindLocation(pch.location)].id == "Lieutenant_G_bedroom"
				|| Locations[FindLocation(pch.location)].id == "Pym_drawing_room" || Locations[FindLocation(pch.location)].id == "GB_Charleston_church_office"
				|| Locations[FindLocation(pch.location)].id == "Dupin_private" || Locations[FindLocation(pch.location)].id == "Poe_bedroom"
				|| Locations[FindLocation(pch.location)].id == "GB_Charleston_opium" || Locations[FindLocation(pch.location)].id == "Dupin_office"
				|| Locations[FindLocation(pch.location)].id == "GB_Charleston_town" || Locations[FindLocation(pch.location)].id == "GB_chinese_gunpowder"
				|| Locations[FindLocation(pch.location)].id == "GB_chinese_nitre" || Locations[FindLocation(pch.location)].id == "GB_sulphur_corridor"
				|| Locations[FindLocation(pch.location)].id == "GB_chinese_restaurant" || Locations[FindLocation(pch.location)].id == "Swamp_loghouse"
				|| Locations[FindLocation(pch.location)].id == "Cartagena_church" || Locations[FindLocation(pch.location)].id == "Cartagena_church_cave"
				|| Locations[FindLocation(pch.location)].id == "Tortuga_townhall" || Locations[FindLocation(pch.location)].id == "GB_Charleston_store"
				|| Locations[FindLocation(pch.location)].id == "GB_Charleston_governor_office" || Locations[FindLocation(pch.location)].id == "GB_Charleston_governor_bedroom"
				|| Locations[FindLocation(pch.location)].id == "GB_Charleston_governor_kitchen" || Locations[FindLocation(pch.location)].id == "Pym_bedroom" 
				|| Locations[FindLocation(pch.location)].id == "Pym_study" || Locations[FindLocation(pch.location)].id == "GB_Charleston_tailorsShop"
				|| Locations[FindLocation(pch.location)].id == "Pym_towerroom" || Locations[FindLocation(pch.location)].id == "GB_Charleston_church"
				|| Locations[FindLocation(pch.location)].id == "BB_prison_alcove" || Locations[FindLocation(pch.location)].id == "BB_crypt1"
				|| Locations[FindLocation(pch.location)].id == "wr_farm_alchemy2" || Locations[FindLocation(pch.location)].id == "wr_farm_booty2"
				|| Locations[FindLocation(pch.location)].id == "wr_farm_kitchen" || Locations[FindLocation(pch.location)].id == "wr_farm_servant"
				|| Locations[FindLocation(pch.location)].id == "Cartagena_hotel_room1" || Locations[FindLocation(pch.location)].id == "Cartagena_hotel_room2"	
				|| Locations[FindLocation(pch.location)].id == "Cartagena_hotel_room3" || Locations[FindLocation(pch.location)].id == "Cartagena_hotel_room4"
				|| Locations[FindLocation(pch.location)].id == "Cartagena hotel" || Locations[FindLocation(pch.location)].id == "Cartagena_hotel_office"
				|| Locations[FindLocation(pch.location)].id == "Cartagena_hotel_private" || Locations[FindLocation(pch.location)].id == "Cartagena_hotel_attic"
				|| Locations[FindLocation(pch.location)].id == "bb_Maltains" || Locations[FindLocation(pch.location)].id == "bb_Eden_estate"
				|| Locations[FindLocation(pch.location)].id == "bb_Eden_bedroom1" || Locations[FindLocation(pch.location)].id == "bb_Eden_attic2"
				|| Locations[FindLocation(pch.location)].id == "bb_Eden_attic3" || Locations[FindLocation(pch.location)].id == "Oriel_room"
				|| Locations[FindLocation(pch.location)].id == "Redhouse_entre" || Locations[FindLocation(pch.location)].id == "Redhouse_room"
				|| Locations[FindLocation(pch.location)].id == "Kristiania_townhall_entre" || Locations[FindLocation(pch.location)].id == "Kristiania_townhall"
				|| Locations[FindLocation(pch.location)].id == "NS_hidden_town_priest" || Locations[FindLocation(pch.location)].id == "Kristiania_shipyard"
				|| Locations[FindLocation(pch.location)].id == "Kristiania_fort_commander" || Locations[FindLocation(pch.location)].id == "Nueva_Suecia_tailor_upstairs"
				|| Locations[FindLocation(pch.location)].id == "Kristiania_cathedral" || Locations[FindLocation(pch.location)].id == "wr_shop"
				|| Locations[FindLocation(pch.location)].id == "church_choir" || Locations[FindLocation(pch.location)].id == "Legrands_attic"
				|| Locations[FindLocation(pch.location)].id == "wr_farm_bedroom" || Locations[FindLocation(pch.location)].id == "Turks_tavern_bedroom"
				|| Locations[FindLocation(pch.location)].id == "bb_Eden_office" || Locations[FindLocation(pch.location)].id == "Citadel_tower_bedroom"
				|| Locations[FindLocation(pch.location)].id == "Mayan_village" || Locations[FindLocation(pch.location)].id == "BB_careen_capmd_2"
				|| Locations[FindLocation(pch.location)].id == "cloister_exit")
				{
					//sounds generated in item_logic
				}
				else
			    //<-- JRH
				{
					PlaySound("AMBIENT\JAIL\door_003.wav");// was door_004 which is corrupted in a way
				}

				isGunpowder = false;
				isItemsBox = true;
				break;

			case "GunpowderStorage":
				GameInterface.title = "titleGunpowderStorage";
				isGunpowder = true;
				isItemsBox = false;
				PlaySound("AMBIENT\JAIL\door_003.wav");// was door_002 which is corrupted in a way
				SupplyAmmo(true);
				if(ENABLE_AMMOMOD==1) {// TIH --> mod toggle 7-7-06
					locations[FindLocation(pch.location)].(boxName).items.gunpowder     = 300*(8 - ShCl) + rand(100);
					locations[FindLocation(pch.location)].(boxName).items.pistolbullets = 300*(8 - ShCl) + rand(100);
					locations[FindLocation(pch.location)].(boxName).items.pistolgrapes  =  75*(8 - ShCl) + rand( 75);
					locations[FindLocation(pch.location)].(boxName).items.musketbullets =  15*(8 - ShCl) + rand( 15);
				}// TIH <-- mod toggle
				break;

			case "GunpowderBarrel":
				GameInterface.title = "titleGunpowderBarrel";
				PlaySound("AMBIENT\JAIL\door_003.wav");
				if (CANNONPOWDER_MOD) {// TIH --> mod toggle 7-7-06
					//JRH in here
					powderCount = GetCargoGoods(pch, GOOD_GUNPOWDER);
					locations[FindLocation(pch.location)].(boxName).open = true;
					locations[FindLocation(pch.location)].(boxName).items.gunpowder = powderCount;
				}// TIH <-- mod toggle
				isGunpowder = true;
				isItemsBox = false;
				break;

			case "GunpowderStorageEnemy":
				GameInterface.title = "titleGunpowderStorage";
				PlaySound("AMBIENT\JAIL\door_003.wav");// was door_002 which is corrupted in a way
				if (CANNONPOWDER_MOD) {// TIH --> mod toggle 7-7-06
					if(bAbordageStarted && !bCabinStarted && !bDeckStarted && !bCrewStarted)
					{
						powderCount = GetCargoGoods(boarding_enemy, GOOD_GUNPOWDER);
						locations[FindLocation(pch.location)].(boxName).open = true;
						locations[FindLocation(pch.location)].(boxName).items.gunpowder = powderCount;
					}
				}// TIH <-- mod toggle
				isGunpowder = true;
				isItemsBox = false;
				break;

			case "GunpowderBarrelEnemy":
				GameInterface.title = "titleGunpowderBarrel";
				PlaySound("AMBIENT\JAIL\door_003.wav");
				if (CANNONPOWDER_MOD) {// TIH --> mod toggle 7-7-06
					if(bAbordageStarted && !bCabinStarted && !bDeckStarted && !bCrewStarted)
					{
						powderCount = GetCargoGoods(boarding_enemy, GOOD_GUNPOWDER);
						locations[FindLocation(pch.location)].(boxName).open = true;
						locations[FindLocation(pch.location)].(boxName).items.gunpowder = powderCount;
					}
				}// TIH <-- mod toggle
				isGunpowder = true;
				isItemsBox = false;
				break;

		}// end switch whichInterface

	}
	else
	{
		GameInterface.title = ""; isGunpowder = false;	// LDH set this to prevent missing attribute error later - 06Mar09
		// changed by MAXIMUS -->
		if(bDeadExchange==true) { GameInterface.title = "titleExchangeWithDead"; isGunpowder = false; }
		if(bEnemyExchange==true) { GameInterface.title = "titleExchangeWithEnemy"; isGunpowder = false; }
		if(bStealExchange==true) { GameInterface.title = "titleExchangeByStealing"; isGunpowder = false; }

		// LDH this needs to go through all the passengers, not just the active officers - 06Mar09
		// it works the way it is because of a test later in the code
		for(int i = 1; i < OFFICER_MAX; i++)
		{
		    ref Char = GetCharacter(GetOfficersIndex(GetMainCharacter(), i));
			if(CheckAttribute(Char,"faceID"))
			{
			  if(faceID==Char.faceID) GameInterface.title = "titleExchangeItems";
			  isGunpowder = false;
			}
		}

		// changed by MAXIMUS <--

		// Viper - Kindly ask that officer to unequip the stuff
		RemoveCharacterEquip(itemsRef, GUN_ITEM_TYPE);
		RemoveCharacterEquip(itemsRef, BLADE_ITEM_TYPE);
		RemoveCharacterEquip(itemsRef, ARMOR_ITEM_TYPE);	// NK
		RemoveCharacterEquip(itemsRef, LOCKPICK_ITEM_TYPE);	// PB
		RemoveCharacterEquip(itemsRef, CLOCK_ITEM_TYPE);	// PB
		RemoveCharacterEquip(itemsRef, COMPASS_ITEM_TYPE);	// PB
		RemoveCharacterEquip(itemsRef, FLASK_ITEM_TYPE);	//JRH
		RemoveCharacterEquip(itemsRef, POUCH_ITEM_TYPE);	//JRH
	}
	// TIH <-- total house cleaning
	g_refItems = itemsRef;

	bool bFromCharacterScreen = CheckAttribute(pch, "ExchangeItemsFromCharacterScreen"); // KK
	if (!bFromCharacterScreen) { // KK
		locCameraSleep(true);
		SetTimeScale(0.0);

		Log_SetActiveAction("Nothing");
		BLIVisible(false);
		SendMessage(&IActions,"ll",LI_SET_VISIBLE,false);

	/*	LayerFreeze(REALIZE,bSeaActive && !ownDeckStarted() && !LAi_IsBoardingProcess());
		LayerFreeze(EXECUTE,true);
		bool bShow = ownDeckStarted();
		if(!bShow) bShow = LAi_IsBoardingProcess();
		LayerFreeze(SEA_REALIZE,!bSeaActive && bShow);
		LayerFreeze(SEA_EXECUTE,true);*/

		// MM: To avoid boarding crash -->
	/*	LayerFreeze(REALIZE,true);
		LayerFreeze(SEA_REALIZE,true);
		LayerFreeze(EXECUTE,true);
		LayerFreeze(SEA_EXECUTE,true);*/
		// MM: To avoid boarding crash <--
		
		LayerFreeze(REALIZE,false); // PB: Try this even simpler
	}

	FillScroll();
// KK -->
	InitToolTip();
	SetImageGroups();
	SetToolTip();

	GameInterface.MyPic.current = 0;
	GameInterface.MyPic.ImagesGroup.t0 = "EMPTYFACE";
	GameInterface.MyPic.pic1.str1 = "";
	GameInterface.MyPic.pic1.img1 = "emptyface";
	if (bNewInterface) GameInterface.MyPic.pic1.img1 = "emptyface_new";
	GameInterface.MyPic.pic1.tex1 = 0;
	GameInterface.MyPic.ListSize = 1;
	GameInterface.MyPic.NotUsed = 0;

	GameInterface.FACEPICT.current = 0;
	GameInterface.FACEPICT.ImagesGroup.t0 = "EMPTYFACE";
	GameInterface.FACEPICT.ImagesGroup.t1 = "GOODS";
	GameInterface.FACEPICT.ImagesGroup.t2 = "RELATIONS";
	GameInterface.FACEPICT.ImagesGroup.t3 = "BOX_IMAGE";
	GameInterface.FACEPICT.pic1.str1 = "";
	GameInterface.FACEPICT.pic1.img1 = "emptyface";
	if (bNewInterface) GameInterface.FACEPICT.pic1.img1 = "emptyface_new";
	GameInterface.FACEPICT.pic1.tex1 = 0;
	GameInterface.FACEPICT.ListSize = 1;
	GameInterface.FACEPICT.NotUsed = 0;
// <-- KK

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();//MAXIMUS: standard exit-string for exit-button
// KK -->
	if (!bFromCharacterScreen) {
		SetNodeUsing("VIDEOBASE",false);
		SetNodeUsing("SCROLLRECTANGLE",false);
		SetNodeUsing("DOWNSCROLLRECT",false);
		SetNodeUsing("DOWNRECTSMOOTH",false);
		SetNodeUsing("BACKSLIDE",false);
		SetNodeUsing("TITLE",false);
		CreateString(true, "ScreenTitle", XI_ConvertString(GameInterface.title), FONT_TITLE, COLOR_NORMAL, 320, 6, SCRIPT_ALIGN_CENTER, 1.0);
		SetNodeUsing("CENTERRECTANGLE",false);
		SetNodeUsing("CENTERBOUND",false);
		if(bAnimation) SetNodeUsing("BACKGROUND",false); // PB: Dynamic Interfaces
		SetNodeUsing("INFO",false);
	}

	//CreateImage("MyPic",GetFaceGroupName(GetMainCharacterIndex()),GetFacePictureName(GetMainCharacterIndex()),5,39,133,167);

	GameInterface.MyPic.pic1.str2 = "#" + GetMySimpleName(pch);
	GameInterface.MyPic.pic1.img1 = GetFacePictureName(GetMainCharacterIndex());
	AddFaceGroup("MyPic.ImagesGroup", GetFaceGroupName(GetMainCharacterIndex()));
	GameInterface.MyPic.pic1.tex1 = FindFaceGroupNum("MyPic.ImagesGroup", GetFaceGroupName(GetMainCharacterIndex()));
	SendMessage(&GameInterface, "ls", MSG_INTERFACE_REFRESH_SCROLL, "MyPic");

	GameInterface.pictures.OtherPic.tex = "";
	GameInterface.pictures.OtherPic.pic = "";
	if(faceID == "") {
		g_bIBoxUsed = true;
		if (boxType == "gunpowder") {
			//CreateImage("OtherPic","GOODS","Gunpowder",-5,292,143,450);// TIH no need for mod toggle on this 7-7-06
			GameInterface.FACEPICT.pic1.str2 = "Gunpowder";
			GameInterface.FACEPICT.pic1.img1 = "Gunpowder";
			GameInterface.FACEPICT.pic1.tex1 = 1;
		} else {
			curLoc = Locations[FindLocation(pch.location)].filespath.models;
			if (boxName == "WeaponsLocker") {
				//CreateImage("OtherPic","RELATIONS","Enemy",-5,292,143,450);
				GameInterface.FACEPICT.pic1.str2 = "Weaponslocker";
				GameInterface.FACEPICT.pic1.img1 = "Enemy";
				GameInterface.FACEPICT.pic1.tex1 = 2;
			} else {
				else
				{
					//CreateImage("OtherPic","BOX_IMAGE","BoxImage",5,302,133,430);
					GameInterface.FACEPICT.pic1.str2 = "ItemsBox";
					if (ownDeckStarted()) GameInterface.FACEPICT.pic1.str2 = "SeaBox";
					if (LAi_IsBoardingProcess() && !IsFort && !IsTown) GameInterface.FACEPICT.pic1.str2 = "SeaBox";
					GameInterface.FACEPICT.pic1.img1 = "BoxImage";
					GameInterface.FACEPICT.pic1.tex1 = 3;
				}

				//JRH -->
				switch (curLocId)
				{
					case "New_cloister_library":
						if(boxName == "box8" || boxName == "box9" || boxName == "box10" || boxName == "box11" || boxName == "box12"
						|| boxName == "box14" || boxName == "box15" || boxName == "box18" || boxName == "box19" || boxName == "box20")
						{
							CreateImage("OtherPic","SHELF_IMAGE","ShelfImage",5,302,133,430);//JRH bookshelf
						} 
					break;

					case "wr_library":
						CreateImage("OtherPic","SHELF_IMAGE","ShelfImage",5,302,133,430);//JRH bookshelf
					break;
			
					case "wr_residence":
						if(boxName == "box1" || boxName == "box3")
						{
							CreateImage("OtherPic","SHELF_IMAGE","ShelfImage",5,302,133,430);//JRH bookshelf
						}
					break;
				
					case "wr_study":
						if(boxName == "box5" || boxName == "box7")
						{
							GameInterface.FACEPICT.pic1.str2 = "ItemsBox";
							GameInterface.FACEPICT.pic1.img1 = "BoxImage";
							GameInterface.FACEPICT.pic1.tex1 = 3;
						}
						else
						{
							if(boxName == "box16")
							{
								CreateImage("OtherPic","ROGERS_IMAGE","RogersImage",5,302,133,430);
							}
						}
						else CreateImage("OtherPic","SHELF_IMAGE","ShelfImage",5,302,133,430);//JRH bookshelf
					break;
				
					case "Defoes_cabin":
						if(boxName == "box2" || boxName == "box3")
						{
							CreateImage("OtherPic","SHELF_IMAGE","ShelfImage",5,302,133,430);//JRH bookshelf
						}
					break;
				
					case "wr_farm_servant":
						if(boxName == "box2")
						{
							CreateImage("OtherPic","SHELF_IMAGE","ShelfImage",5,302,133,430);//JRH bookshelf
						}
					break;
				
					case "wr_church_inside":
						if(boxName == "box1")
						{
							CreateImage("OtherPic","COLLECTION_IMAGE","CollectionImage",5,302,133,430);
						}
						else CreateImage("OtherPic","SHELF_IMAGE","ShelfImage",5,302,133,430);//JRH bookshelf
					break;
				
					case "wr_cannon_tower":
						if(boxName == "box1")
						{
							GameInterface.FACEPICT.pic1.str2 = "Gunpowder";
							GameInterface.FACEPICT.pic1.img1 = "Gunpowder";
							GameInterface.FACEPICT.pic1.tex1 = 1;
						}
					break;
				
					case "wr_gunpowder":
						if(boxName == "box3")
						{
							GameInterface.FACEPICT.pic1.str2 = "Gunpowder";
							GameInterface.FACEPICT.pic1.img1 = "Gunpowder";
							GameInterface.FACEPICT.pic1.tex1 = 1;
						}
					break;
				
					case "GB_Charleston_church":
						if(boxName == "box1")
						{
							CreateImage("OtherPic","COLLECTION_IMAGE","CollectionImage",5,302,133,430);
						}
					break;
				
					case "Legrands_house":
						if(boxName == "box7")
						{
							CreateImage("OtherPic","SHELF_IMAGE","ShelfImage",5,302,133,430);//JRH bookshelf
						}
					break;
				
					case "Legrands_attic":
						if(boxName == "box6" || boxName == "box7" || boxName == "box8" || boxName == "box9"
						|| boxName == "box10" || boxName == "box11" || boxName == "box12" || boxName == "box13")
						{
							CreateImage("OtherPic","TREASURE_IMAGE","TreasureImage",5,302,133,430);//JRH treasuresack
						}
					break;
				
					case "Poe_bedroom":
						if(boxName == "box2")
						{
							CreateImage("OtherPic","SHELF_IMAGE","ShelfImage",5,302,133,430);//JRH bookshelf
						}
					break;
				
					case "Cartagena_church":
						if(boxName == "box4")
						{
							CreateImage("OtherPic","COLLECTION_IMAGE","CollectionImage",5,302,133,430);
						}
					break;
				
					case "Pym_drawing_room":
						if(boxName == "box6" || boxName == "box7")
						{
							CreateImage("OtherPic","SHELF_IMAGE","ShelfImage",5,302,133,430);//JRH bookshelf
						}
					break;
				
					case "Pym_bedroom":
						if(boxName == "box5")
						{
							if(CheckAttribute(pch, "quest.pym_niche") && pch.quest.pym_niche == "open")
							{
								CreateImage("OtherPic","SHELF_IMAGE","ShelfImage",5,302,133,430);//JRH bookshelf
							}
						}
					break;
				
					case "Pym_study":
						if(boxName == "box2" || boxName == "box3" || boxName == "box7")
						{
							CreateImage("OtherPic","SHELF_IMAGE","ShelfImage",5,302,133,430);//JRH bookshelf
						}
					break;
				
					case "Turks_church":
						if(boxName == "box1")
						{
							CreateImage("OtherPic","COLLECTION_IMAGE","CollectionImage",5,302,133,430);
						}
						else CreateImage("OtherPic","SHELF_IMAGE","ShelfImage",5,302,133,430);//JRH bookshelf
					break;
				
					case "Kristiania_townhall_entre":
						if(boxName == "box4" || boxName == "box5")
						{
							CreateImage("OtherPic","SHELF_IMAGE","ShelfImage",5,302,133,430);//JRH bookshelf
						}
					break;

					case "Kristiania_townhall":
						if(boxName == "box4" || boxName == "box5")
						{
							CreateImage("OtherPic","SHELF_IMAGE","ShelfImage",5,302,133,430);//JRH bookshelf
						}
					break;
				
					case "Redhouse_room":
						if(boxName == "box1" || boxName == "box2")
						{
							CreateImage("OtherPic","SHELF_IMAGE","ShelfImage",5,302,133,430);//JRH bookshelf
						}
					break;
				
					case "BB_sloop_wreck_hold":
						if(boxName == "box1")
						{
							GameInterface.FACEPICT.pic1.str2 = "Gunpowder";
							GameInterface.FACEPICT.pic1.img1 = "Gunpowder";
							GameInterface.FACEPICT.pic1.tex1 = 1;
						}
					break;

					case "BB_prison_officer":
						if(boxName == "box13")
						{
							CreateImage("OtherPic","TOOK_IMAGE","TookImage",5,302,133,430);
						}
						else
						{
							GameInterface.FACEPICT.pic1.str2 = "ItemsBox";
							GameInterface.FACEPICT.pic1.img1 = "BoxImage";
							GameInterface.FACEPICT.pic1.tex1 = 3;
						}
					break;

					case "BB_careen_holdS":
						if(boxName == "box1")
						{
							GameInterface.FACEPICT.pic1.str2 = "Gunpowder";
							GameInterface.FACEPICT.pic1.img1 = "Gunpowder";
							GameInterface.FACEPICT.pic1.tex1 = 1;
						}
					break;

					case "BB_careen_capmd_2":
						if(boxName == "box5" || boxName == "box6" || boxName == "box7" || boxName == "box8") 
						{
							GameInterface.FACEPICT.pic1.str2 = "Weaponslocker";
							GameInterface.FACEPICT.pic1.img1 = "Enemy";
							GameInterface.FACEPICT.pic1.tex1 = 2;
						}
						else
						{
							GameInterface.FACEPICT.pic1.str2 = "ItemsBox";
							GameInterface.FACEPICT.pic1.img1 = "BoxImage";
							GameInterface.FACEPICT.pic1.tex1 = 3;
						}
					break;
				}
				//<-- JRH
			}
		}
	} else {
		g_bIBoxUsed = false;
// changed by MAXIMUS -->
		if (CheckAttribute(GameInterface, "title") && GameInterface.title == "titleExchangeWithDead") {	// LDH fix for missing attrib
		    SetNewPicture("EN_PIC", "interfaces\portraits\128\face_skull.tga");
			//SetNewPicture("FACEPICT", "interfaces\portraits\128\face_skull.tga");
			GameInterface.FACEPICT.pic1.str2 = "#" + XI_ConvertString("BodyOf") + GetMySimpleName(lootedChar);
			GameInterface.FACEPICT.pic1.img1 = "";
			GameInterface.FACEPICT.pic1.tex1 = "";
			GameInterface.FACEPICT.BadPicture1 = "interfaces\portraits\128\face_skull.tga";
		} else {
		    SetNewPicture("EN_PIC", "interfaces\portraits\128\face_" + faceID + ".tga");
			//SetNewPicture("FACEPICT", "interfaces\portraits\128\face_" + faceID + ".tga");
			GameInterface.FACEPICT.pic1.str2 = "#" + GetMySimpleName(lootedChar);
			GameInterface.FACEPICT.pic1.img1 = GetFacePictureName(sti(lootedChar.index));
			AddFaceGroup("FACEPICT.ImagesGroup", GetFaceGroupName(sti(lootedChar.index)));
			GameInterface.FACEPICT.pic1.tex1 = FindFaceGroupNum("FACEPICT.ImagesGroup", GetFaceGroupName(sti(lootedChar.index)));
		}
// changed by MAXIMUS <--
	}
	SendMessage(&GameInterface, "ls", MSG_INTERFACE_REFRESH_SCROLL, "FACEPICT");
	SetNodeUsing("FACEPICT", true);
// <-- KK

	CreateString(TRUE,"itemname","",FONT_NORMAL,COLOR_NORMAL,320,475,SCRIPT_ALIGN_CENTER,0.8); // NK

// added by MAXIMUS-->
	SetSelectable("EXIT_BUTTON",true);
	SetNodeUsing("CONFIRM_RECTANGLE",false);
	SetNodeUsing("TEXTWINDOW",false);
	SetNodeUsing("CONFIRM_YES_BUTTON",false);
	SetNodeUsing("CONFIRM_NO_BUTTON",false);
	SetNodeUsing("REL_PIC",false);
	SetNodeUsing("EN_PIC",false);
// added by MAXIMUS <--

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("frame","FrameProcess",1);

	SetEventHandler("ievnt_command","ProcInterfaceCommand",0);
// added by MAXIMUS-->
	SetEventHandler("ExitPress","ProcessExit",0);
	SetEventHandler("ExitNo","ProcessExit_no",0);
	SetEventHandler("ExitYes","ProcessExit_yes",0);
// added by MAXIMUS <--

	SetItemMode(ITEM_MODE_SWAP);

	IGotoNewNode("TWO_ITEMSLIST");
	IGotoNewNode("ONE_ITEMSLIST");

	SetUpDownUsed();
	SetScrollsUsing();
}

// added by MAXIMUS -->
void ProcessExit()
{
	string faceID;
	SetNodeUsing("CONFIRM_RECTANGLE",true);
	SetNodeUsing("TEXTWINDOW",true);
	SetNodeUsing("CONFIRM_YES_BUTTON",true);
	SetNodeUsing("CONFIRM_NO_BUTTON",true);
	SetNodeUsing("REL_PIC",true);
	SetNodeUsing("EN_PIC",true);
	SetCurrentNode("CONFIRM_NO_BUTTON");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "CONFIRM_NO_BUTTON");
	SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "CONFIRM_YES_BUTTON");

	SetFormatedText("TEXTWINDOW", TranslateString("","Exit from exchange confirm"));
}

void ProcessExit_no()
{
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);

	SetNodeUsing("CONFIRM_RECTANGLE",false);
	SetNodeUsing("TEXTWINDOW",false);
	SetNodeUsing("CONFIRM_YES_BUTTON",false);
	SetNodeUsing("CONFIRM_NO_BUTTON",false);
	SetNodeUsing("REL_PIC",false);
	SetNodeUsing("EN_PIC",false);

	SetCurrentNode("INFO_BUTTON");
}

void ProcessExit_yes()
{
//	if(oldItemMode==ITEM_MODE_INFO) SetItemMode(ITEM_MODE_SWAP);
//	else IDoExit(RC_INTERFACE_ITEMSBOX_EXIT);
//	else
	IDoExit(RC_INTERFACE_DO_RESUME_GAME);
}
// added by MAXIMUS <--

void FrameProcess()
{
// KK -->
	if (!bRMouseDown)
		HideToolTip();
	else
		return;
// <-- KK

	IGotoNewNode(GetCurrentNode());

	if( nCurScroll1 != sti(GameInterface.one_itemslist.current) ||
		nCurScroll2 != sti(GameInterface.two_itemslist.current) )
	{
		nCurScroll1 = sti(GameInterface.one_itemslist.current);
		nCurScroll2 = sti(GameInterface.two_itemslist.current);
		if(oldItemMode!=ITEM_MODE_SWAP)	{SetItemMode(ITEM_MODE_SWAP);}
		SetUpDownUsed();
	}
}

void FillScroll()
{
	int i,j,q,iqty;
    string attributeName, name;
	aref curItem,arItem,rootItems;
	aref arImgGrp;
	ref mchref = GetMainCharacter();

	if(CheckAttribute(&GameInterface,"one_itemslist.current"))
		nCurScroll1 = sti(GameInterface.one_itemslist.current);
	else	nCurScroll1 = 0;
	if(CheckAttribute(&GameInterface,"two_itemslist.current"))
		nCurScroll2 = sti(GameInterface.two_itemslist.current);
	else	nCurScroll2 = 0;

	DeleteAttribute(&GameInterface,"one_itemslist");
	DeleteAttribute(&GameInterface,"two_itemslist");

	//============================================================================
	// PLAYER ITEMS
	//============================================================================
	GameInterface.one_itemslist.NotUsed = 5;
	GameInterface.one_itemslist.current = nCurScroll1;
	GameInterface.one_itemslist.ImagesGroup.t0 = "usedflag";// TIH
	GameInterface.one_itemslist.ImagesGroup.t1 = "ICONS";// TIH
	makearef(arImgGrp,GameInterface.one_itemslist.ImagesGroup);
	FillImagesGroupForItems(arImgGrp);

	i=0;
	// figure out the total gold the player has and add it to the first scroll item
	if( sti(mchref.Money)>0 )
	{
		GameInterface.one_itemslist.pic1.img1 = GetItemPictureName("Gold");
		GameInterface.one_itemslist.pic1.tex1 = GetItemPictureTexture("one_itemslist.ImagesGroup","Gold");
		GameInterface.one_itemslist.pic1.itemID = "Money";
		GameInterface.one_itemslist.pic1.str1 = "#"+sti(mchref.Money);		// LDH 15Oct06 fix for decimal point money
		if(DynamicInterfaceLevel() > 0) GameInterface.one_itemslist.pic1.str2 = "Gold"; // KK: Dynamic Interfaces
		i++;
	}
	// loop through all items except maps of the player and add to scroller
	makearef(rootItems,mchref.Items);
	for(j=0; j<GetAttributesNum(rootItems); j++)
    {
		attributeName = "pic" + (i+1);
		curItem = GetAttributeN(rootItems,j);
		if (GetAttributeName(curItem) == "bladeX4") continue;// TIH simply never show fists in looting screens 7-7-06

		if( Items_FindItem(GetAttributeName(curItem),&arItem)>=0 )
		{
			if (GetAttribute(arItem, "name") == "itmname_building" && GetAttribute(arItem, "describe") == "itmdescr_building") continue; // PB: You're not supposed to loot these...
// KK -->
			if (CheckAttribute(arItem, "groupID") == true && arItem.groupID == MAP_ITEM_TYPE) continue;
			iqty = sti(GetAttributeValue(curItem));
// <-- KK
			GameInterface.one_itemslist.(attributeName).img1 = GetItemPictureName(arItem.id);
			GameInterface.one_itemslist.(attributeName).tex1 = GetItemPictureTexture("one_itemslist.ImagesGroup",arItem.id);
			GameInterface.one_itemslist.(attributeName).itemID = arItem.id;
			//if(CheckConsumedItem(arItem.id)) {// TIH doesnt work right?
			if (iqty > 1) {// TIH absolute check
				GameInterface.one_itemslist.(attributeName).str1 = "#" + iqty;
			}
// KK -->
			name = "";
			if (CheckAttribute(arItem, "QualityName")) name = TranslateString("", "q"+arItem.QualityName) + " "; // PB: Correct quality name
			if( GetAttribute(arItem,"groupID") == QUEST_ITEM_TYPE)
			{
				name += PreprocessText(TranslateString("", arItem.name)); // PB
			}
			else
			{
				name += GetAssembledString(TranslateString("", arItem.name),arItem);
			}
			if(DynamicInterfaceLevel() > 0) GameInterface.one_itemslist.(attributeName).str2 = "#" + name; // PB: Dynamic Interfaces
// <-- KK
			// TIH --> add equipped checkmarks
			if( IsEquipCharacterByItem(mchref,arItem.id) )
			{
				GameInterface.one_itemslist.(attributeName).img2 = "usedflag";
				GameInterface.one_itemslist.(attributeName).tex2 = 0;
			}
			// TIH <--
		}
		else
		{
			trace("WARNING! Can`t find item ID = "+GetAttributeName(curItem)+" value: "+GetAttributeValue(curItem)+" ");
			GameInterface.one_itemslist.(attributeName).img1 = "itm16";
			GameInterface.one_itemslist.(attributeName).tex1 = 0;
		}
		i++;
    }
	GameInterface.one_itemslist.ListSize = i;

	//============================================================================
	// TRANSFER FROM ITEMS
	//============================================================================
	GameInterface.two_itemslist.NotUsed = 5;
	GameInterface.two_itemslist.current = nCurScroll2;
	makearef(arImgGrp,GameInterface.two_itemslist.ImagesGroup);
	FillImagesGroupForItems(arImgGrp);

	i=0;
	// if the location/character has no gold, create the attribute and set to zero
	if(!CheckAttribute(g_refItems,"Money"))	g_refItems.Money = 0;

	makearef(rootItems,g_refItems.Items);
	q = GetAttributesNum(rootItems);

	// loop through items to find any gold to add to the total
	for(j=0; j<q; j++)
	{
		curItem = GetAttributeN(rootItems,j);
		if(sti(GetAttributeValue(curItem))<=0)	continue;
		if( Items_FindItem(GetAttributeName(curItem),&arItem)>=0 )
		{
			if( CheckAttribute(arItem,"Gold") )
			{
				g_refItems.Money = sti(g_refItems.Money) + sti(arItem.Gold)*GetCharacterItem(g_refItems,arItem.Gold);
				DeleteAttribute(rootItems,arItem.id);
				j--; q--;
			}
		}
	}
	if( sti(g_refItems.Money)>0 )
	{
		GameInterface.two_itemslist.pic1.img1 = GetItemPictureName("Gold");
		GameInterface.two_itemslist.pic1.tex1 = GetItemPictureTexture("two_itemslist.ImagesGroup","Gold");
		GameInterface.two_itemslist.pic1.itemID = "Money";
		GameInterface.two_itemslist.pic1.str1 = "#"+sti(g_refItems.Money);		// LDH 15Oct06 fix for decimal point money
		if(DynamicInterfaceLevel() > 0) GameInterface.two_itemslist.pic1.str2 = "Gold"; // KK: Dynamic Interfaces
		i++;
	}

	// loop through items of the location/character and add to second scroller
	for(j=0; j<q; j++)
	{
		attributeName = "pic" + (i+1);
		curItem = GetAttributeN(rootItems,j);

		if(sti(GetAttributeValue(curItem))<=0)	continue;
		if (GetAttributeName(curItem) == "bladeX4") continue;// TIH simply never show fists in looting screens 7-7-06

		if( Items_FindItem(GetAttributeName(curItem),&arItem)>=0 )
		{
			if (GetAttribute(arItem, "name") == "itmname_building" && GetAttribute(arItem, "describe") == "itmdescr_building") continue; // PB: You're not supposed to loot these...
			
			if(bDeadExchange)
			{
				if(IsCharacterEquipByGroup(g_refItems,BLADE_ITEM_TYPE)) { RemoveCharacterEquip(g_refItems, BLADE_ITEM_TYPE); }
				if(IsCharacterEquipByGroup(g_refItems,GUN_ITEM_TYPE)) { RemoveCharacterEquip(g_refItems, GUN_ITEM_TYPE); }
				if(IsCharacterEquipByGroup(g_refItems,ARMOR_ITEM_TYPE)) { RemoveCharacterEquip(g_refItems, ARMOR_ITEM_TYPE); }
			}
			GameInterface.two_itemslist.(attributeName).img1 = GetItemPictureName(arItem.id);
			GameInterface.two_itemslist.(attributeName).tex1 = GetItemPictureTexture("two_itemslist.ImagesGroup",arItem.id);
			GameInterface.two_itemslist.(attributeName).itemID = arItem.id;
			//if(CheckConsumedItem(arItem.id)) {// TIH doesnt work right?
			if ( sti(GetAttributeValue(curItem)) > 1 ) {// TIH absolute check
				GameInterface.two_itemslist.(attributeName).str1 = "#"+sti(GetAttributeValue(curItem));
			}
// KK -->
			name = "";
			if (CheckAttribute(arItem, "QualityName")) name = TranslateString("", "q"+arItem.QualityName) + " "; // PB: Correct quality name
			name += GetAssembledString(TranslateString("", arItem.name),arItem);
			if(DynamicInterfaceLevel() > 0) GameInterface.two_itemslist.(attributeName).str2 = "#" + name; // PB: Dynamic Interfaces
// <-- KK
		}
		else
		{
			trace("WARNING! Can`t find item ID = "+GetAttributeName(curItem));
			GameInterface.two_itemslist.(attributeName).img1 = "itm16";
			GameInterface.two_itemslist.(attributeName).tex1 = 0;
		}
		i++;
	}
	GameInterface.two_itemslist.ListSize = i;
	if(i==0) noConfirm = true;

	nCurScroll1 = sti(GameInterface.one_itemslist.current);
	nCurScroll2 = sti(GameInterface.two_itemslist.current);
}

void ProcessCancelExit()
{
// changed by MAXIMUS -->
	if(!isItemsBox)
	{
		if(bDeadExchange==true || bEnemyExchange==true || bStealExchange==true)
		{
			if(noConfirm==true) ProcessExit_yes();// TIH procedure fix 7-7-06
			else ProcessExit();
		}
		else
		{
//	        if(oldItemMode==ITEM_MODE_INFO) SetItemMode(ITEM_MODE_SWAP);
//	        else IDoExit(RC_INTERFACE_ITEMSBOX_EXIT);
//	        else
			IDoExit(RC_INTERFACE_DO_RESUME_GAME);
		}
	}
	else
	{
//	    if(oldItemMode==ITEM_MODE_INFO) SetItemMode(ITEM_MODE_SWAP);
//	    else IDoExit(RC_INTERFACE_ITEMSBOX_EXIT);
//	    else
		IDoExit(RC_INTERFACE_DO_RESUME_GAME);
	}
// changed by MAXIMUS <--
}

void IDoExit(int exitCode)
{
	int s; // NK for below for() statements

	int cortes_disabled = CURSES_DISABLED - 2*MakeInt(CURSES_DISABLED/2);
	int albatross_disabled = MakeInt(CURSES_DISABLED/2) - 2*MakeInt(CURSES_DISABLED/4);

	ref pchar = GetMainCharacter();
	// PB: Albatross Easter Egg -->
	if(sti(GetAttribute(g_refItems, "items.albatross"))>0 && !albatross_disabled)
	{
		TakeNItems(pchar, "albatross", sti(g_refItems.items.albatross));
		DeleteAttribute(g_refItems, "items.albatross");
	}
	// PB: Albatross Easter Egg <--

	// PB: Cursed Coins -->
	if(sti(GetAttribute(g_refItems, "items.cursedcoin"))>0 && GetCursedCoinCount()>0 && !cortes_disabled)
	{
		// You can give them to officers, companions and crew
		if(bAllies(g_refItems))
		{
			// But NOT the last one
			if(sti(GetAttribute(g_refItems, "items.cursedcoin"))>1)
			{
				TakeNItems(pchar, "cursedcoin", sti(g_refItems.items.cursedcoin)-1);
				g_refItems.items.cursedcoin = 1;
			}
			if(sti(GetAttribute(pchar, "items.cursedcoin")) <1)
			{
				GiveItem2Character(pchar, "cursedcoin");
				DeleteAttribute(g_refItems, "items.cursedcoin");
			}
		}
		else
		{
			if(pchar.location == "Grotto")
			{
				// You can get rid of the last one ONLY if you put the entire 882 in there
				if(sti(GetAttribute(g_refItems, "items.cursedcoin"))<882)
				{
					if(sti(GetAttribute(pchar, "items.cursedcoin")) <1)
					{
						GiveItem2Character(pchar, "cursedcoin");
						g_refItems.items.cursedcoin = sti(g_refItems.items.cursedcoin)-1;
					}
				}
				else
				{
					// Lift the curse
				}
			}
			else
			{
				// You can put them in your ships' chests or weaponslockers
				if(pchar.location == "Tutorial_Deck" || HasSubStr(pchar.location, "Companion_Cabin_"))
				{
					// But NOT the last one
					if(sti(GetAttribute(pchar, "items.cursedcoin")) <1)
					{
						GiveItem2Character(pchar, "cursedcoin");
						g_refItems.items.cursedcoin = sti(g_refItems.items.cursedcoin)-1;
					}
				}
				else
				{
					TakeNItems(pchar, "cursedcoin", sti(g_refItems.items.cursedcoin));
					DeleteAttribute(g_refItems, "items.cursedcoin");
				}
			}
		}
	}
	if(bAllies(g_refItems))	CheckCharacterCurse(g_refItems);
	CheckCharacterCurse(pchar);
	// PB: Cursed Coins <--

	if(!g_bIBoxUsed)
	{
		if( CalcCharacterSkill(g_refItems, SKILL_FENCING) > 0 )
		{
			EquipCharacterByItem(g_refItems, FindCharacterItemByGroup(g_refItems,BLADE_ITEM_TYPE));
			EquipCharacterByItem(g_refItems, FindCharacterItemByGroup(g_refItems,GUN_ITEM_TYPE));
			EquipCharacterByItem(g_refItems, FindCharacterItemByGroup(g_refItems,ARMOR_ITEM_TYPE));		// NK
			EquipCharacterByItem(g_refItems, FindCharacterItemByGroup(g_refItems,FLASK_ITEM_TYPE));		//JRH
			EquipCharacterByItem(g_refItems, FindCharacterItemByGroup(g_refItems,POUCH_ITEM_TYPE));		//JRH
		}
		EquipCharacterByItem(g_refItems, FindCharacterItemByGroup(g_refItems,LOCKPICK_ITEM_TYPE));	// PB
		EquipCharacterByItem(g_refItems, FindCharacterItemByGroup(g_refItems,CLOCK_ITEM_TYPE));		// PB
		EquipCharacterByItem(g_refItems, FindCharacterItemByGroup(g_refItems,COMPASS_ITEM_TYPE));	// PB
	}

	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("frame","FrameProcess");
	DelEventHandler("ievnt_command","ProcInterfaceCommand");
// added by MAXIMUS -->
	DelEventHandler("ExitPress","ProcessExit");
	DelEventHandler("ExitNo","ProcessExit_no");
	DelEventHandler("ExitYes","ProcessExit_yes");
// added by MAXIMUS <--

// KK -->
	bDeadExchange = false;
	bEnemyExchange = false;
	bStealExchange = false;
// <-- KK

    interfaceResultCommand = exitCode;

// LDH - go back to Character screen if exchange called from there.
	if (CheckAttribute(pchar, "ExchangeItemsFromCharacterScreen"))
	{
		PostEvent("LaunchIAfterFrame",1,"sl", "I_CHARACTER", 1);
	    EndCancelInterface(false);
		return;
	}
	else
	{
		EndCancelInterface(true);	// original code
	}

	UpdateTimeScale(); // PB
	locCameraSleep(false);
	BLIVisible(true);
	if(interfaceResultCommand == RC_INTERFACE_DO_RESUME_GAME) { DeleteEntitiesByType("scrshoter"); }
}

void IGotoNewNode(string newNode)
{
	if(oldNodeName==newNode) return;
	oldNodeName=newNode;
	if(newNode=="ONE_ITEMSLIST")	SetScroll(true);
	if(newNode=="TWO_ITEMSLIST")	SetScroll(false);

	if(oldItemMode!=ITEM_MODE_SWAP)
	{
		if(newNode!="DESCRIBEWINDOW")
		{
			SetItemMode(ITEM_MODE_SWAP);
			SetUpDownUsed();
		}
	}
}

void SetScroll(bool bIsOne)
{
	if(bIsOne)
	{
		if(oldCurScrollName=="TWO_ITEMSLIST")
		{
			SetNodeUsing("TWO_LEFTSCROLLBUTTON",false);
			SetNodeUsing("TWO_RIGHTSCROLLBUTTON",false);
		}
		SetNodeUsing("ONE_LEFTSCROLLBUTTON",true);
		SetNodeUsing("ONE_RIGHTSCROLLBUTTON",true);
		oldCurScrollName = "ONE_ITEMSLIST";
	}
	else
	{
		if(oldCurScrollName=="ONE_ITEMSLIST")
		{
			SetNodeUsing("ONE_LEFTSCROLLBUTTON",false);
			SetNodeUsing("ONE_RIGHTSCROLLBUTTON",false);
		}
		SetNodeUsing("TWO_LEFTSCROLLBUTTON",true);
		SetNodeUsing("TWO_RIGHTSCROLLBUTTON",true);
		oldCurScrollName = "TWO_ITEMSLIST";
	}
}

void SetItemMode(int mode)
{
	switch(oldItemMode)
	{
	case ITEM_MODE_SWAP:
		SetNodeUsing("INFO_BUTTON",false);
		SetNodeUsing("SWAP_BUTTON",false);
		SetNodeUsing("ONEUP_BUTTON",false);
		SetNodeUsing("ONEDOWN_BUTTON",false);
		SetNodeUsing("ALLUP_BUTTON",false);
		SetNodeUsing("ALLDOWN_BUTTON",false);
	break;
	//case ITEM_MODE_INFO:	SetNodeUsing("DESCRIBEWINDOW",false);	break;
	}

	oldItemMode = mode;

	switch(mode)
	{
	case ITEM_MODE_SWAP:
		SetNodeUsing("INFO_BUTTON",true);
		SetNodeUsing("SWAP_BUTTON",true);
		SetNodeUsing("ONEUP_BUTTON",true);
		SetNodeUsing("ONEDOWN_BUTTON",true);
		SetNodeUsing("ALLUP_BUTTON",true);
		SetNodeUsing("ALLDOWN_BUTTON",true);
	break;
	//case ITEM_MODE_INFO:	SetNodeUsing("DESCRIBEWINDOW",true);	break;
	}
}

void ProcInterfaceCommand()
{
	string comName = GetEventData();
	string nodeName = GetEventData();
	int scrollstep = 0;

// KK -->
	if (bRMouseDown) {
		if (comName != "click") return;

		ShowDescription(nodeName);
		return;
	}

	if (HasSubStr(nodeName, "AITEM1_")) {
		scrollstep = sti(strcut(nodeName, 7, strlen(nodeName) - 1));
		nodeName = "ONE_ITEMSLIST";
	}
	if (HasSubStr(nodeName, "AITEM2_")) {
		scrollstep = sti(strcut(nodeName, 7, strlen(nodeName) - 1));
		nodeName = "TWO_ITEMSLIST";
	}
// <-- KK

	switch(nodeName)
	{
	/*case "INFO_BUTTON":
		if(comName=="upstep") {GoToTopScroll();}
		if(comName=="downstep") {GoToBottomScroll();}
		if(comName=="rightstep") {SelectButtonRight("ONEDOWN_BUTTON");}
		if(comName=="deactivate")	{SetCurrentNode(oldCurScrollName);}
// KK -->
		if(comName=="activate" || comName=="click")
		{
			//SetItemMode(ITEM_MODE_INFO);
			//SetDescribeText();
			//SetCurrentNode("DESCRIBEWINDOW");
			ShowDescription(true);
		}
// <-- KK
	break;*/

// KK -->
	/*case "SHOW_DESCRIPTION_OK_BUTTON":
		if(comName == "activate" || comName == "click" || comName == "deactivate")
		{
			ShowDescription(false);
		}
	break;*/
// <-- KK

	case "ONEDOWN_BUTTON":
		if(comName=="upstep") {GoToTopScroll();}
		if(comName=="downstep") {GoToBottomScroll();}
		if(comName=="leftstep") {SelectButtonLeft("INFO_BUTTON");}
		if(comName=="rightstep") {SelectButtonRight("ONEUP_BUTTON");}
		if(comName=="activate" || comName=="click")	{GiveOneItem();}
		if(comName=="deactivate")	{SetCurrentNode(oldCurScrollName);}
	break;

	case "ONEUP_BUTTON":
		if(comName=="upstep") {GoToTopScroll();}
		if(comName=="downstep") {GoToBottomScroll();}
		if(comName=="leftstep") {SelectButtonLeft("ONEDOWN_BUTTON");}
		if(comName=="rightstep") {SelectButtonRight("SWAP_BUTTON");}
		if(comName=="activate" || comName=="click")	{TakeOneItem();}
		if(comName=="deactivate")	{SetCurrentNode(oldCurScrollName);}
	break;

	case "SWAP_BUTTON":
		if(comName=="upstep") {GoToTopScroll();}
		if(comName=="downstep") {GoToBottomScroll();}
		if(comName=="leftstep") {SelectButtonLeft("ONEUP_BUTTON");}
		if(comName=="rightstep") {SelectButtonRight("ALLUP_BUTTON");}
		if(comName=="activate" || comName=="click")	{ChangeItemsSlot();}
		if(comName=="deactivate")	{SetCurrentNode(oldCurScrollName);}
	break;

	case "ALLUP_BUTTON":
		if(comName=="upstep") {GoToTopScroll();}
		if(comName=="downstep") {GoToBottomScroll();}
		if(comName=="leftstep") {SelectButtonLeft("SWAP_BUTTON");}
		if(comName=="rightstep") {SelectButtonRight("ALLDOWN_BUTTON");}
		if(comName=="activate" || comName=="click")	{TakeItemsCollection();}
		if(comName=="deactivate")	{SetCurrentNode(oldCurScrollName);}
	break;

	case "ALLDOWN_BUTTON":
		if(comName=="upstep") {GoToTopScroll();}
		if(comName=="downstep") {GoToBottomScroll();}
		if(comName=="leftstep") {SelectButtonLeft("ALLUP_BUTTON");}
		if(comName=="activate" || comName=="click")	{GiveItemsCollection();}
		if(comName=="deactivate")	{SetCurrentNode(oldCurScrollName);}
	break;

	case "ONE_ITEMSLIST":
		if(comName=="downstep")	{SelectButtonLeft("SWAP_BUTTON");}
		if (comName == "click" || comName == "activate") {
			GoToTopScroll();
			nCurScroll1 += scrollstep;
			GameInterface.ONE_ITEMSLIST.current = nCurScroll1;
			SetUpDownUsed(); // KK
			SendMessage(&GameInterface, "lsl", MSG_INTERFACE_SCROLL_CHANGE, "ONE_ITEMSLIST", nCurScroll1);
			SendMessage(&GameInterface,"ls", MSG_INTERFACE_REFRESH_SCROLL, "ONE_ITEMSLIST");
		}
	break;

	case "TWO_ITEMSLIST":
		if(comName=="upstep")	{SelectButtonLeft("SWAP_BUTTON");}
		if (comName == "click" || comName == "activate") {
			GoToBottomScroll();
			nCurScroll2 += scrollstep;
			GameInterface.TWO_ITEMSLIST.current = nCurScroll2;
			SetUpDownUsed(); // KK
			SendMessage(&GameInterface, "lsl", MSG_INTERFACE_SCROLL_CHANGE, "TWO_ITEMSLIST", nCurScroll2);
			SendMessage(&GameInterface,"ls", MSG_INTERFACE_REFRESH_SCROLL, "TWO_ITEMSLIST");
		}
	break;

	/*case "DESCRIBEWINDOW":
		if(comName=="downstep")
		{
			if(!bEnableDown)
			{
				SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,"DESCRIBEWINDOW",-1, 0,ACTION_UPSTEP);
			} else {
				bEnableDown = SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE,"DESCRIBEWINDOW", 6, 0);
			}
		}
		if(comName=="upstep")
		{
			bEnableDown = SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE,"DESCRIBEWINDOW", 6, 0);
		}
	break;*/
	}
}

void ChangeItemsSlot()
{
	string itm1 = GetItemIDByOrder(true,nCurScroll1);
	string itm2 = GetItemIDByOrder(false,nCurScroll2);
	string itm1name = "";                // Sulan: Quicker Inventory
	string itm2name = "";                // Sulan: Quicker Inventory
	aref aritem;                         // Sulan: Quicker Inventory
	int limit;

	if(itm1=="" || itm1!=itm2)
	{
		if( !CanCharacterTakeItem(true,itm2) ) return;
	}

	int iq1 = GetItemQntByOrder(true,nCurScroll1);
	int iq2 = GetItemQntByOrder(false,nCurScroll2);
	int gp2; int p;//JRH

	aref mchref; makearef(mchref,Characters[GetMainCharacterIndex()]);

	if(iq1>0)
	{
		if(itm1=="Money")
		{
			if(itm2=="Malta_outfit" || itm2=="Malta_syringe" || itm2=="Malta_icon" || itm2=="Malta_poison" || itm2=="Malta_medkit"
			|| itm2=="Malta_statue" || itm2=="Malta_box" || itm2=="Malta_cross" || itm2=="Malta_censer")
			{
				iq1 = 0;
			}
			else
			{
				mchref.Money = 0;
				g_refItems.Money = iq1+sti(g_refItems.Money);
			}
		}
		else
		{ // --> Sulan 07/2010: Check for quantity limits
			if(itm1=="pistolbullets" || itm1=="pistolgrapes" || itm1=="musketbullets" || itm1=="gunpowder" || itm1=="bladearrows" || itm1=="arrows2" || itm1=="rockets"
			|| itm1=="blade_mKnife" || itm1=="pistolmket" || itm1=="pistolmketB")
			{
				limit = HowManyItemsCanITake(itm1, g_refitems);
				if (limit < iq1) iq1 = limit;
			}
			if(itm2=="Malta_outfit" || itm2=="Malta_syringe" || itm2=="Malta_icon" || itm2=="Malta_poison" || itm2=="Malta_medkit"
			|| itm2=="Malta_statue" || itm2=="Malta_box" || itm2=="Malta_cross" || itm2=="Malta_censer")
			{
				iq1 = 0;
			}
			if(iq1 >0)
			{
				TakeNItems(GetMainCharacter(),itm1,-iq1);
				TakeNItems(g_refItems        ,itm1, iq1); // PB
			}
		} // <--
	}
	if(iq2>0)
	{
		if(itm2=="Money")
		{
			g_refItems.Money = sti(g_refItems.Money)-iq2;
			mchref.Money = iq2+sti(mchref.Money);
		}
		else
		{
			if(itm2=="pistolbullets" || itm2=="pistolgrapes" || itm2=="musketbullets" || itm2=="gunpowder" || itm2=="bladearrows" || itm2=="arrows2" || itm2=="rockets"
			|| itm2=="blade_mKnife" || itm2=="pistolmket" || itm2=="pistolmketB")
			{
				limit = HowManyItemsCanITake(itm2, mchref);
				if (limit < iq2) iq2 = limit;
			}
			if(itm2=="Malta_outfit" || itm2=="Malta_syringe" || itm2=="Malta_icon" || itm2=="Malta_poison" || itm2=="Malta_medkit"
			|| itm2=="Malta_statue" || itm2=="Malta_box" || itm2=="Malta_cross" || itm2=="Malta_censer")
			{
				PlaySound("VOICE\ENGLISH\blaze_hah.wav");
				limit = 0;
				if (limit < iq2) iq2 = limit;
			}
			if(iq2>0)
			{
				TakeNItems(GetMainCharacter(),itm2, iq2);
				TakeNItems(g_refItems        ,itm2,-iq2); // PB
			}
		}
	}

//JRH -->
	if(itm1=="coin1" || itm1=="coin2" || itm1=="coin3"|| itm1=="coin4" || itm1=="coin5" || itm1=="coin6" || itm1=="coin7"|| itm1=="coin8"
	|| itm1=="coin9" || itm1=="coin10" || itm1=="coin12" || itm1=="coin13" || itm1=="coin14"|| itm1=="coin15")
	{
		PlaySound("INTERFACE\cancel.wav");

		//count how many coins there are in the collection box now!
		mchref.quest.collect_coins = sti(mchref.quest.collect_coins) + 1;

		int price;
		price = GetItemPriceByID(itm1);
		mchref.quest.collect_value = sti(mchref.quest.collect_value) + price;

		if(itm1=="coin2" || itm1=="coin3" || itm1=="coin6" || itm1=="coin7" || itm1=="coin10" || itm1=="coin12" || itm1=="coin15")
		{
			mchref.quest.collect_right_coins = sti(mchref.quest.collect_right_coins) + 1;
		}
	}

	if(itm1=="coin11")
	{
		PlaySound("INTERFACE\coin_drop.wav");
		g_refItems.Items.(itm1) = sti(g_refItems.Items.(itm1)) -1;
		if( iq1<=0 ) DeleteAttribute(g_refItems,"Items."+itm1);

		LAi_QuestDelay("coin_too_small", 0.1);
	}

	if(itm1=="coin16")
	{
		PlaySound("VOICE\ENGLISH\blaze_huh.wav");

		TakeNItems(GetMainCharacter(),itm1,1);
		g_refItems.Items.(itm1) = sti(g_refItems.Items.(itm1)) -1;
		if( iq1<=0 ) DeleteAttribute(g_refItems,"Items."+itm1);

		LAi_QuestDelay("coin_too_large", 0.1);
	}

	if(itm2=="coin1" || itm2=="coin2" || itm2=="coin3"|| itm2=="coin4" || itm2=="coin5" || itm2=="coin6" || itm2=="coin7"|| itm2=="coin8"
	|| itm2=="coin9" || itm2=="coin10"|| itm2=="coin11" || itm2=="coin12" || itm2=="coin13" || itm2=="coin14"|| itm2=="coin15" || itm2=="coin16")
	{
		PlaySound("INTERFACE\took_item.wav");

		//count how many coins there are in the collection box now!
		mchref.quest.collect_coins = sti(mchref.quest.collect_coins) - 1;

		price = GetItemPriceByID(itm2);
		mchref.quest.collect_value = sti(mchref.quest.collect_value) - price;

		if(itm2=="coin2" || itm2=="coin3" || itm2=="coin6" || itm2=="coin7" || itm2=="coin10" || itm2=="coin12" || itm2=="coin15")
		{
			mchref.quest.collect_right_coins = sti(mchref.quest.collect_right_coins) - 1;
		}
	}

	if(itm1=="coin1" || itm1=="coin2" || itm1=="coin3"|| itm1=="coin4" || itm1=="coin5" || itm1=="coin6" || itm1=="coin7"|| itm1=="coin8"
	|| itm1=="coin9" || itm1=="coin10" || itm1=="coin12" || itm1=="coin13" || itm1=="coin14"|| itm1=="coin15"
	|| itm2=="coin1" || itm2=="coin2" || itm2=="coin3"|| itm2=="coin4" || itm2=="coin5" || itm2=="coin6" || itm2=="coin7"|| itm2=="coin8"
	|| itm2=="coin9" || itm2=="coin10"|| itm2=="coin11" || itm2=="coin12" || itm2=="coin13" || itm2=="coin14"|| itm2=="coin15" || itm2=="coin16")
	{
		LAi_QuestDelay("collection_box", 0.1);
	}

	if(itm1=="ammopouch" || itm1=="powderflask" || itm1=="ammobag1" || itm1=="ammobag2")
	{
		if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0) LAi_QuestDelay("pistol_ranking_list", 0.1);
	}

	if(itm1=="bladepowderhornP" || itm1=="bladepowderhornA")
	{
		if(IsEquipCharacterByItem(mchref, "powderflask"))
		{
			p = 12;
		}
		else
		{
			p = 6;
		}

		gp2 = GetCharacterItem(mchref, "gunpowder");
		if(gp2 > p)
		{
			TakeNItems(mchref,"gunpowder", -100);
			TakeNItems(mchref,"gunpowder", p);
		}
	}
//<-- JRH

	// Sulan: Quicker Inventory  -->
	//FillScroll();
	if( Items_FindItem(itm1,&arItem)>=0 )
	{
		itm1name = "#";
		if (CheckAttribute(arItem, "QualityName")) itm1name += TranslateString("", "q"+arItem.QualityName) + " ";

		itm1name += GetAssembledString(TranslateString("", arItem.name),arItem);
	}
	if( Items_FindItem(itm2,&arItem)>=0 )
	{
		itm2name = "#";
		if (CheckAttribute(arItem, "QualityName")) itm2name += TranslateString("", "q"+arItem.QualityName) + " ";
		itm2name += GetAssembledString(TranslateString("", arItem.name),arItem);
	}
	InsertItem( 0, itm1, iq1, itm1name);
	InsertItem( 1, itm2, iq2, itm2name);
	RemoveItem( 0, itm1, iq1);
	RemoveItem( 1, itm2, iq2);
	// <-- Sulan
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"ONE_ITEMSLIST",-1);
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"TWO_ITEMSLIST",-1);
	SetUpDownUsed();
	SetScrollsUsing();
}

// Sulan: Rewrote these functions to reduce the code mess :)
void TakeOneItem()
{
	TakeItems(false);
}
void GiveOneItem()
{
	GiveItems(false);
}
void TakeItemsCollection()
{
	TakeItems(true);
}
void GiveItemsCollection()
{
	GiveItems(true);
}

void GiveItems(bool bMoreThanOneItem)
{
	string itm1 = GetItemIDByOrder(true,nCurScroll1);
	string itm1name;
	int iq1 = GetItemQntByOrder(true,nCurScroll1);
	bool takeitem = false;
	int limit;
	int newQty;
	int amount;
	aref aritem;
	aref mchref; makearef(mchref,Characters[GetMainCharacterIndex()]);

	if(iq1<=0) return;
	if(!bMoreThanOneItem) amount = 1;
	else amount = iq1;

	int p;		//JRH
	int gp2;	//JRH

	if(itm1=="Money")
	{
		if(bMoreThanOneItem)
		{
			mchref.Money = 0;
			g_refItems.Money = sti(g_refItems.Money)+amount;
			takeitem = true;
		}
		else
		{
			if(iq1 >= GOLD_PER_CLICK)
			{
				amount = GOLD_PER_CLICK;
				iq1 = iq1 - GOLD_PER_CLICK;
				mchref.Money = sti(mchref.Money) - GOLD_PER_CLICK;
				g_refItems.Money = sti(g_refItems.Money) + GOLD_PER_CLICK;
			}
			else
			{
				iq1 = 0;
				amount = sti(mchref.Money);
				g_refItems.Money = sti(g_refItems.Money) + sti(mchref.Money);
				mchref.Money = 0;
			}
			takeitem = true;
		}
	}
	else
	{ // for bullets and gunpowder follow the quantity restrictions
		if (itm1=="gunpowder" || itm1=="pistolbullets" || itm1=="pistolgrapes" || itm1=="musketbullets" || itm1=="bladearrows" || itm1=="arrows2" || itm1=="rockets"
		|| itm1=="blade_mKnife" || itm1=="pistolmket" || itm1=="pistolmketB")
		{
			if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0) LAi_QuestDelay("pistol20_ammo_check", 0.1);	//JRH see quest_reaction

			limit = HowManyItemsCanITake(itm1, g_refItems);
			if (limit < amount) amount = limit;
			if(amount >0) takeitem = true;
			if(CANNONPOWDER_MOD && isGunpowder)
			{
				if(bAbordageStarted && !bCabinStarted && !bDeckStarted && !bCrewStarted)
				{
					newQty = sti(GetCargoGoods(boarding_enemy, GOOD_GUNPOWDER))-1;
					SetCharacterGoods(boarding_enemy, GOOD_GUNPOWDER, newQty);
				}
				else
				{
					newQty = sti(GetCargoGoods(GetMainCharacter(), GOOD_GUNPOWDER))-1;
					if(bDeckStarted) SetCharacterGoods(GetMainCharacter(), GOOD_GUNPOWDER, newQty);
				}
			}
		}
		if(itm1=="cannonballs")
		{
			if(amount >0)
			{
				takeitem = true;
				//count how many cannonballs there are in the counter box now!
				if(mchref.boxname == "box3")
				{
					mchref.quest.cannonballs_in_counterbox = sti(mchref.quest.cannonballs_in_counterbox) + 1;
				}
				//LogIt("cannonballs left = " + mchref.quest.cannonballs_in_counterbox);
			}
		}
		else
		{
			//NEW GIVE
			if(itm1=="picture1" || itm1=="picture2" || itm1=="picture3"|| itm1=="picture4" || itm1=="picture5" || itm1=="picture6" || itm1=="picture7"
			|| itm1=="picture8" || itm1=="picture9" || itm1=="picture10" || itm1=="picture11" || itm1=="picture13" || itm1=="picture14"|| itm1=="picture15")
			{
				PlaySound("AMBIENT\SHOP\paper.wav");
				takeitem = true;
			}
		}

		else takeitem = true; // for any other item: just give it away
		if(takeitem)
		{
			TakeNItems(GetMainCharacter(),itm1,-amount);
			TakeNItems(g_refItems        ,itm1, amount); // PB

	//JRH -->
			if(itm1=="ammopouch" || itm1=="powderflask" || itm1=="ammobag1" || itm1=="ammobag2" || itm1=="powderbarrel" || itm1=="ammobag")
			{
				if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0) LAi_QuestDelay("pistol_ranking_list", 0.1);
			}

			if(itm1=="bladepowderhornP" || itm1=="bladepowderhornA")
			{
				if(IsEquipCharacterByItem(mchref, "powderflask"))
				{
					p = 12;
				}
				else
				{
					p = 6;
				}

				gp2 = GetCharacterItem(mchref, "gunpowder");
				if(gp2 > p)
				{
					TakeNItems(mchref,"gunpowder", -100);
					TakeNItems(mchref,"gunpowder", p);
				}
			}

			if(itm1 == "pistol20")
			{
				if(CheckCharacterItem(mchref,"bladepclub203"))
				{
					GiveItem2Character(mchref, "bladeX4");
				}

				if(IsEquipCharacterByItem(mchref, "bladepclub203"))
				{
					RemoveCharacterEquip(mchref, BLADE_ITEM_TYPE);
					EquipCharacterByItem(mchref, "bladeX4");
				}

				TakeItemFromCharacter(mchref, "bladepclub203");
			}

			if(itm1 == "drawing_kit")
			{
				if(CheckAttribute(mchref,"quest.drawing_kit"))
				{
					switch(mchref.quest.drawing_kit)
					{
						case "speed":
							if(CheckCharacterPerk(mchref, "SailingProfessional"))
							{
								DeleteAttribute(mchref,"perks.list.SailingProfessional");
							}
							else
							{
								if(CheckCharacterPerk(mchref, "SandbankManeuver"))
								{
									DeleteAttribute(mchref,"perks.list.SandbankManeuver");
								}
							}
							else
							{
								if(CheckCharacterPerk(mchref, "Turn180"))
								{
									DeleteAttribute(mchref,"perks.list.Turn180");
								}
							}
							else
							{
								DeleteAttribute(mchref,"perks.list.ShipSpeedUp");
							}
							mchref.quest.drawing_kit = "none";
						break;

						case "maneuver":
							if(CheckCharacterPerk(mchref, "SailingProfessional"))
							{
								DeleteAttribute(mchref,"perks.list.SailingProfessional");
							}
							else
							{
								if(CheckCharacterPerk(mchref, "SandbankManeuver"))
								{
									DeleteAttribute(mchref,"perks.list.SandbankManeuver");
								}
							}
							else
							{
								if(CheckCharacterPerk(mchref, "Turn180"))
								{
									DeleteAttribute(mchref,"perks.list.Turn180");
								}
							}
							else
							{
								DeleteAttribute(mchref,"perks.list.ShipTurnRateUp");
							}
							mchref.quest.drawing_kit = "none";
						break;

						case "turn180":
							if(CheckCharacterPerk(mchref, "SailingProfessional"))
							{
								DeleteAttribute(mchref,"perks.list.SailingProfessional");
							}
							else
							{
								if(CheckCharacterPerk(mchref, "SandbankManeuver"))
								{
									DeleteAttribute(mchref,"perks.list.SandbankManeuver");
								}
							}
							else
							{
								DeleteAttribute(mchref,"perks.list.Turn180");
							}
							mchref.quest.drawing_kit = "none";
						break;

						case "sandbank":
							if(CheckCharacterPerk(mchref, "SailingProfessional"))
							{
								DeleteAttribute(mchref,"perks.list.SailingProfessional");
							}
							else
							{
								DeleteAttribute(mchref,"perks.list.SandbankManeuver");
							}
							mchref.quest.drawing_kit = "none";
						break;

						case "storm":
							if(CheckCharacterPerk(mchref, "SailingProfessional"))
							{
								DeleteAttribute(mchref,"perks.list.SailingProfessional");
							}
							else
							{
								DeleteAttribute(mchref,"perks.list.StormProfessional");
							}
    							mchref.quest.drawing_kit = "none";
						break;

						case "seawolf":
							DeleteAttribute(mchref,"perks.list.SailingProfessional");
							mchref.quest.drawing_kit = "none";
						break;

						case "def1":
							if(CheckCharacterPerk(mchref, "ProfessionalDamageControl"))
							{
								DeleteAttribute(mchref,"perks.list.ProfessionalDamageControl");
							}
							else
							{
								if(CheckCharacterPerk(mchref, "AdvancedDamageControl"))
								{
									DeleteAttribute(mchref,"perks.list.AdvancedDamageControl");
								}
							}
							else
							{
								DeleteAttribute(mchref,"perks.list.BasicDamageControl");
							}
							mchref.quest.drawing_kit = "none";
						break;

						case "def2":
							if(CheckCharacterPerk(mchref, "ProfessionalDamageControl"))
							{
								DeleteAttribute(mchref,"perks.list.ProfessionalDamageControl");
							}
							else
							{
								DeleteAttribute(mchref,"perks.list.AdvancedDamageControl");
							}
							mchref.quest.drawing_kit = "none";
						break;

						case "def3":
							DeleteAttribute(mchref,"perks.list.ProfessionalDamageControl");
							mchref.quest.drawing_kit = "none";
						break;
					}
				}
			}

			//skip 16 & 11 here ( never stays in box)
			if(itm1=="coin1" || itm1=="coin2" || itm1=="coin3"|| itm1=="coin4" || itm1=="coin5" || itm1=="coin6" || itm1=="coin7"|| itm1=="coin8"
			|| itm1=="coin9" || itm1=="coin10" || itm1=="coin12" || itm1=="coin13" || itm1=="coin14"|| itm1=="coin15")
			{
					PlaySound("INTERFACE\cancel.wav");

					//count how many coins there are in the collection box now!
					mchref.quest.collect_coins = sti(mchref.quest.collect_coins) + 1;

					int price;
					price = GetItemPriceByID(itm1);
					mchref.quest.collect_value = sti(mchref.quest.collect_value) + price;

					if(itm1=="coin2" || itm1=="coin3" || itm1=="coin6" || itm1=="coin7" || itm1=="coin10" || itm1=="coin12" || itm1=="coin15")
					{
						mchref.quest.collect_right_coins = sti(mchref.quest.collect_right_coins) + 1;
					}

					LAi_QuestDelay("collection_box", 0.1);
			}

			if(itm1=="coin11")
			{
				PlaySound("INTERFACE\coin_drop.wav");
				g_refItems.Items.(itm1) = sti(g_refItems.Items.(itm1)) -1;
				if( iq1<=0 ) DeleteAttribute(g_refItems,"Items."+itm1);

				LAi_QuestDelay("coin_too_small", 0.1);
			}

			if(itm1=="coin16")
			{
				PlaySound("VOICE\ENGLISH\blaze_huh.wav");

				TakeNItems(GetMainCharacter(),itm1,1);
				g_refItems.Items.(itm1) = sti(g_refItems.Items.(itm1)) -1;
				if( iq1<=0 ) DeleteAttribute(g_refItems,"Items."+itm1);

				LAi_QuestDelay("coin_too_large", 0.1);
			}

			if(itm1=="Pell_outfit")
			{
				if(CheckCharacterItem(CharacterFromID("Pell"),"Pell_outfit"))
				{
					PlaySound("PEOPLE\clothes2.wav");
					SetModel(characterFromID("Pell"), "bb_Pell", "man", "man", 1.8, false);
					g_refItems.Items.(itm1) = sti(g_refItems.Items.(itm1)) -1;

					LAi_QuestDelay("pchar_yah", 0.1);
				}
			}
	//<-- JRH

		}
	}
	// Sulan: Quicker Inventory  -->
	// FillScroll();
	if(takeitem)
	{
		if( Items_FindItem(itm1,&arItem)>=0 )
		{
			itm1name = "#";
			if (CheckAttribute(arItem, "QualityName")) itm1name += TranslateString("", "q"+arItem.QualityName) + " ";
			itm1name += GetAssembledString(TranslateString("", arItem.name),arItem);
	  	}
		MoveItem( 0, itm1, amount, itm1name);
		// <-- Sulan
		SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"ONE_ITEMSLIST",-1);
		SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"TWO_ITEMSLIST",-1);
		SetUpDownUsed();
		SetScrollsUsing();
	}
}

void TakeItems(bool bMoreThanOneItem)
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");//JRH
	string itm2 = GetItemIDByOrder(false,nCurScroll2);
	string itm2name;
	int iq2 = GetItemQntByOrder(false,nCurScroll2);
	int newQty;
	bool takeitem = false;
	int limit;
	int amount;
	aref aritem;
	aref mchref; makearef(mchref,Characters[GetMainCharacterIndex()]);

	if(iq2<=0) return;
	if(!bMoreThanOneItem) amount = 1;
	else amount = iq2;

    //JRH -->
	int gp;
	int pb;
	int cb;	//cannonballls
	int b;	//balls
	int t_p;
	int t_c;
    //<-- JRH

	if(itm2=="Money")
	{
		if(bMoreThanOneItem)
		{
			mchref.Money = sti(mchref.Money)+amount;
			g_refItems.Money = 0;
			takeitem=true;
		}
		else
		{
			if(iq2 >= GOLD_PER_CLICK)
			{
				amount = GOLD_PER_CLICK;
				iq2 = iq2 - GOLD_PER_CLICK;
				mchref.Money = sti(mchref.Money) + GOLD_PER_CLICK;
				g_refItems.Money = iq2;
			}
			else
			{
				amount = iq2;
				mchref.Money = sti(mchref.Money) + iq2;
				iq2 = 0;
				g_refItems.Money = 0;
			}
			takeitem=true;
		}
	}
	else
	{ // for bullets and gunpowder follow the quantity restrictions
		if(itm2=="pistolbullets" || itm2=="pistolgrapes" || itm2=="musketbullets" || itm2=="gunpowder" || itm2=="bladearrows" || itm2=="arrows2" || itm2=="rockets"
		|| itm2=="blade_mKnife" || itm2=="pistolmket" || itm2=="pistolmketB")
		{
			if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0) LAi_QuestDelay("pistol20_ammo_check", 0.1);	//JRH see quest_reaction

			limit = HowManyItemsCanITake(itm2, mchref);
			if (limit < amount) amount = limit;
			if(amount >0) takeitem = true;
			if(CANNONPOWDER_MOD && isGunpowder)
			{
				if(bAbordageStarted && !bCabinStarted && !bDeckStarted && !bCrewStarted)
				{
					newQty = sti(GetCargoGoods(boarding_enemy, GOOD_GUNPOWDER))-1;
					SetCharacterGoods(boarding_enemy, GOOD_GUNPOWDER, newQty);
				}
				else
				{
					newQty = sti(GetCargoGoods(GetMainCharacter(), GOOD_GUNPOWDER))-1;
					if(bDeckStarted) SetCharacterGoods(GetMainCharacter(), GOOD_GUNPOWDER, newQty);
				}
			}
		}

		if(itm2=="picture1" || itm2=="picture2" || itm2=="picture3"|| itm2=="picture4" || itm2=="picture5" || itm2=="picture6" || itm2=="picture7"
		|| itm2=="picture8" || itm2=="picture9" || itm2=="picture10" || itm2=="picture11" || itm2=="picture13" || itm2=="picture14"|| itm2=="picture15")
		{
			if(CheckCharacterItem(mchref,"picture1") || CheckCharacterItem(mchref,"picture2") || CheckCharacterItem(mchref,"picture3")
			|| CheckCharacterItem(mchref,"picture4") || CheckCharacterItem(mchref,"picture5") || CheckCharacterItem(mchref,"picture6")
			|| CheckCharacterItem(mchref,"picture7") || CheckCharacterItem(mchref,"picture8") || CheckCharacterItem(mchref,"picture9")
			|| CheckCharacterItem(mchref,"picture10") || CheckCharacterItem(mchref,"picture11") || CheckCharacterItem(mchref,"picture13")
 			|| CheckCharacterItem(mchref,"picture14") || CheckCharacterItem(mchref,"picture15"))
			{
				Logit(TranslateString("","Choose ONE picture."));
				PlaySound("VOICE\ENGLISH\blaze_mhm.wav");
			}
			else
			{
				if(itm2=="picture7")
				{
					Logit(TranslateString("","Yes, this picture seems to be the right one!"));
					PlaySound("VOICE\ENGLISH\blaze_hah.wav");


					if(!CheckCharacterItem(GetMainCharacter(),"glue"))
					{
						Logit(TranslateString("","Now I need some glue to repair the Book!"));

					}
				}
				else
				{
					Logit(TranslateString("","No, this is not the right picture!"));
					PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
				}

				PlaySound("AMBIENT\SHOP\paper.wav");

				amount = 1;
				if(amount >0) takeitem = true;
			}
		}

		if(itm2=="Malta_outfit" || itm2=="Malta_syringe" || itm2=="Malta_icon" || itm2=="Malta_poison" || itm2=="Malta_medkit"
		|| itm2=="Malta_statue" || itm2=="Malta_box" || itm2=="Malta_cross" || itm2=="Malta_censer")
		{
			PlaySound("VOICE\ENGLISH\blaze_hah.wav");
			amount = 0; if(amount >0) takeitem = false;
		}

		switch(itm2)
		{
			case "cannonballs":
				if(CheckCharacterItem(mchref,"cannonballs"))
				{
					Logit(TranslateString("","They are really heavy - one set is enough!"));
					PlaySound("VOICE\ENGLISH\blaze_hah.wav");
				}
				else
				{
					amount = 1;
					if(amount >0) takeitem = true;

					//count how many cannonballs there are in the counter box now!
					if(mchref.boxname == "box3")
					{
						mchref.quest.cannonballs_in_counterbox = sti(mchref.quest.cannonballs_in_counterbox) - 1;
					}
					//LogIt("cannonballs left = " + mchref.quest.cannonballs_in_counterbox);
				}
			break;

			case "pistolretort":
				if(CheckCharacterItem(mchref,"pistolretort"))
				{
					Logit(TranslateString("","One retort is enough!"));
					PlaySound("INTERFACE\glass1.wav");
				}
				else
				{
					amount = 1;
					if(amount >0) takeitem = true;
				}
			break;

			case "bladetop":
				if(CheckCharacterItem(mchref,"bladetop"))
				{
					Logit(TranslateString("","One top is enough!"));
					PlaySound("INTERFACE\glass1.wav");
				}
				else
				{
					amount = 1;
					if(amount >0) takeitem = true;
				}
			break;

			case "pistolglass_tube":
				if(CheckCharacterItem(mchref,"pistolglass_tube"))
				{
					Logit(TranslateString("","One glass tube is enough!"));
					PlaySound("INTERFACE\glass1.wav");
				}
				else
				{
					amount = 1;
					if(amount >0) takeitem = true;
				}
			break;

			case "bladebottle_CE0":
				if(mchref.location == "church_wine_cellar")
				{
					amount = 1;			//any limit here?
					if(amount >0) takeitem = true;
				}
				else
				{
					if(CheckCharacterItem(mchref,"bladebottle_CE0"))
					{
						Logit(TranslateString("","One empty bottle is enough!"));
						PlaySound("INTERFACE\glass1.wav");
					}
					else
					{
						amount = 1;
						if(amount >0) takeitem = true;
					}
				}
			break;

			case "bladebottle_BE0":
				if(CheckCharacterItem(mchref,"bladebottle_BE0"))
				{
					Logit(TranslateString("","One empty bottle is enough!"));
					PlaySound("INTERFACE\glass1.wav");
				}
				else
				{
					amount = 1;
					if(amount >0) takeitem = true;
				}
			break;

			case "bladebottle_CP2":
				if(CheckCharacterItem(mchref,"bladebottle_CP2"))
				{
					Logit(TranslateString("","One Champagne bottle is enough!"));
					PlaySound("INTERFACE\glass1.wav");
				}
				else
				{
					amount = 1;
					if(amount >0) takeitem = true;
				}
			break;

			case "pistolsalt":
				if(mchref.location == "wr_corv_crew")
				{
					if(amount >0) takeitem = true;
				}
				else
				{
					int ps = GetCharacterItem(mchref, "pistolsalt");
				
					if(ps >= 2)
					{
						Logit(TranslateString("","Two Salt Jars are enough!"));
						PlaySound("INTERFACE\button2.flac");
					}
					else
					{
						amount = 1;
						if(amount >0) takeitem = true;
					}
				}
			break;

			case "pistolcloth":
				if(CheckCharacterItem(mchref,"pistolcloth"))
				{
					Logit(TranslateString("","One Filter is enough!"));
					PlaySound("PEOPLE\clothes4.wav");
				}
				else
				{
					amount = 1;
					if(amount >0) takeitem = true;
				}
			break;			
//JRH
			case "pistolcalciumsack":
				if(CheckCharacterItem(mchref,"pistolcalciumsack"))
				{
					Logit(TranslateString("","One Calcium Sack is enough!"));
					PlaySound("PEOPLE\clothes4.wav");
				}
				else
				{
					amount = 1;
					if(amount >0) takeitem = true;
				}
			break;	

			case "pistolcharcoal_WR":
				int coal = GetCharacterItem(mchref, "pistolcharcoal_WR");
				
				if(coal >= 2)
				{
					Logit(TranslateString("","Two Coal Jars are enough!"));
					PlaySound("INTERFACE\button2.flac");
				}
				else
				{
					amount = 1;
					if(amount >0) takeitem = true;
				}
			break;

			case "pistolnitre":
				if(mchref.location == "wr_corv_smallcabin_R")
				{
					if(amount >0) takeitem = true;
				}
				else
				{
					if(CheckCharacterItem(mchref,"pistolnitre"))
					{
						Logit(TranslateString("","One Nitre Sack is enough!"));
						PlaySound("PEOPLE\clothes4.wav");
					}
					else
					{
						amount = 1;
						if(amount >0) takeitem = true;
					}
				}
			break;

			case "pistolstonebasket_G":
				if(CheckCharacterItem(mchref,"pistolstonebasket_G"))
				{
					Logit(TranslateString("","One Limestone Basket is enough!"));
					PlaySound("PEOPLE\cavern1.wav");
				}
				else
				{
					amount = 1;
					if(amount >0) takeitem = true;
				}
			break;

			case "pistolbucket_dung":
				if(CheckCharacterItem(mchref,"pistolbucket_dung"))
				{
					Logit(TranslateString("","One Camel Dung Bucket is enough!"));
					PlaySound("PEOPLE\cancel.wav");
				}
				else
				{
					amount = 1;
					if(amount >0) takeitem = true;
				}
			break;
			
			case "pistolsulphur_WR":
				if(CheckCharacterItem(mchref,"pistolsulphur_WR"))
				{
					Logit(TranslateString("","One Sulphur Basket is enough!"));
					PlaySound("PEOPLE\basket.wav");
				}
				else
				{
					amount = 1;
					if(amount >0) takeitem = true;
				}
			break;

			case "pistolretort3":
				int wax = GetCharacterItem(mchref, "pistolretort3");
				
				if(wax >= 2)
				{
					Logit(TranslateString("","Two Wax Jars are enough!"));
					PlaySound("INTERFACE\button2.flac");
				}
				else
				{
					amount = 1;
					if(amount >0) takeitem = true;
				}
			break;

			case "pistolstonebasket_M":
				if(CheckCharacterItem(mchref,"pistolstonebasket_M"))
				{
					Logit(TranslateString("","One Antimony Basket is enough!"));
					PlaySound("PEOPLE\cavern1.wav");
				}
				else
				{
					amount = 1;
					if(amount >0) takeitem = true;
				}
			break;
		
			case "pistolstonebasket_B":
				if(CheckCharacterItem(mchref,"pistolstonebasket_B"))
				{
					Logit(TranslateString("","One Black Antimony Basket is enough!"));
					PlaySound("PEOPLE\cavern1.wav");
				}
				else
				{
					amount = 1;
					if(amount >0) takeitem = true;
				}
			break;

			case "pistolstonebasket_R":
				if(CheckCharacterItem(mchref,"pistolstonebasket_R"))
				{
					Logit(TranslateString("","One Mercury Oxide Basket is enough!"));
					PlaySound("PEOPLE\cavern1.wav");
				}
				else
				{
					amount = 1;
					if(amount >0) takeitem = true;
				}
			break;

			case "bladebottlew5":
				if(CheckCharacterItem(mchref,"bladebottlew5"))
				{
					Logit(TranslateString("","One wine bottle in each hand is enough!"));
					PlaySound("INTERFACE\glass1.wav");
				}
				else
				{
					if(CheckCharacterItem(mchref,"bladebarrel3"))
					{
						Logit(TranslateString("","Not a chance!"));
						PlaySound("VOICE\ENGLISH\blaze_puh.wav");
					}
				}
				else
				{
					amount = 1;
					if(amount >0) takeitem = true;
				}
			break;

			case "pistolbottlew5":
				if(CheckCharacterItem(mchref,"pistolbottlew5"))
				{
					Logit(TranslateString("","One wine bottle in each hand is enough!"));
					PlaySound("INTERFACE\glass1.wav");
				}
				else
				{
					if(CheckCharacterItem(mchref,"bladebarrel3"))
					{
						Logit(TranslateString("","Not a chance!"));
						PlaySound("VOICE\ENGLISH\blaze_puh.wav");
					}
				}
				else
				{
					amount = 1;
					if(amount >0) takeitem = true;
				}
			break;

			case "mixed_treasure":
				if(CheckCharacterItem(mchref,"emptysack"))
				{
					TakeItemFromCharacter(mchref, "emptysack");
					TakeItemFromCharacter(mchref, "mixed_treasure");
					GiveItem2Character(mchref, "treasuresack");
					SetModel(mchref, "William Legrand_sack", mchref.model.animation, mchref.sex, stf(mchref.model.height), true);

					if(CheckAttribute(mchref,"treasure_chest") && mchref.treasure_chest == "prepare2")
					{
						PlaySound("PEOPLE\clothes1.wav");
						SetModel(characterFromID("Edgar Allan Poe"), "Edgar Allan Poe_sack", "man", "man", 1.8, true);
						SetModel(characterFromID("Jupiter"), "jupiter_sack", "man", "man", 1.8, true);
						GiveItem2Character(characterFromID("Jupiter"), "treasuresack");
						GiveItem2Character(characterFromID("Edgar Allan Poe"), "treasuresack");
						mchref.treasure_tour = "2"; 
						amount = 3;
						if(amount >0) takeitem = true;

						LAi_QuestDelay("3_next_sacks_taken", 0.1);
					}
					else
					{
						if(CheckAttribute(mchref,"treasure_chest") && mchref.treasure_chest == "prepare3")
						{
							PlaySound("PEOPLE\clothes1.wav");
							SetModel(characterFromID("Edgar Allan Poe"), "Edgar Allan Poe_sack", "man", "man", 1.8, true);
							GiveItem2Character(characterFromID("Edgar Allan Poe"), "treasuresack");
							mchref.treasure_tour = "3"; 
							amount = 2;
							if(amount >0) takeitem = true;

							LAi_QuestDelay("2_last_sacks_taken", 0.1);
						}
					}
					else 
					{
						//first time
						amount = 1;
						if(amount >0) takeitem = true;

						LAi_QuestDelay("check_3_first_sacks", 0.1);
					}

					LAi_QuestDelay("place_treasure_in_sacks", 0.1);
				}
				else
				{
					PlaySound("VOICE\ENGLISH\blaze_huh.wav");
					Logit(TranslateString("","I need something to carry the Treasure in."));
				}
			break;

			//default
			takeitem = true;		 // for any other item: just take it
		}

		if(takeitem)
		{
			TakeNItems(GetMainCharacter(),itm2, amount);
			TakeNItems(g_refItems        ,itm2,-amount); // PB

	//JRH -->
			if(itm2 == "pistol20")
			{
				if(CheckAttribute(mchref,"quest.pistolclub") && mchref.quest.pistolclub == "know_how")
				{
					GiveItem2Character(mchref, "bladepclub203");

					if(IsEquipCharacterByItem(mchref, "bladeX4"))
					{
						RemoveCharacterEquip(mchref, BLADE_ITEM_TYPE);
						EquipCharacterByItem(mchref, "bladepclub203");
					}

					TakeItemFromCharacter(mchref, "bladeX4");
				}
			}

			if(itm2 == "pistol201")
			{
				if(CheckCharacterItem(GetMainCharacter(),"pistolthrow4"))
				{
					RemoveCharacterEquip(mchref, GUN_ITEM_TYPE);
					TakeItemFromCharacter(mchref, "pistolthrow4");
					TakeItemFromCharacter(mchref, "pistol201");
					GiveItem2Character(mchref, "pistolthrow5");
					EquipCharacterByItem(mchref, "pistolthrow5");

					if(CheckCharacterItem(GetMainCharacter(),"ammobag1"))
					{
						TakeItemFromCharacter(mchref, "ammobag1");
						GiveItem2Character(mchref, "ammobag2");
					}
				}

				if(CheckCharacterItem(GetMainCharacter(),"pistolbelt"))
				{
					if(CheckCharacterItem(GetMainCharacter(),"pistol206") && CheckCharacterItem(GetMainCharacter(),"pistol205")
					&& CheckCharacterItem(GetMainCharacter(),"pistol204") && CheckCharacterItem(GetMainCharacter(),"pistol202"))
					{
						TakeItemFromCharacter(mchref, "pistol201"); TakeItemFromCharacter(mchref, "pistol202");
						TakeItemFromCharacter(mchref, "pistol204"); TakeItemFromCharacter(mchref, "pistol205");
						TakeItemFromCharacter(mchref, "pistol206");
						RemoveCharacterEquip(mchref, BELT_ITEM_TYPE);
						TakeItemFromCharacter(mchref, "pistolbelt");
						GiveItem2Character(mchref, "pistol20");
						EquipCharacterByItem(mchref, "pistol20");
					}
					else
					{
						gp = GetCharacterItem(mchref, "gunpowder");
						pb = GetCharacterItem(mchref, "pistolbullets");

						if(gp >= 1 && pb >= 1 && IsEquipCharacterByItem(mchref, "pistolbelt"))
						{
							EquipCharacterByItem(mchref, "pistol201");
						}
					}
				}

				if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0) LAi_QuestDelay("pchar_outfit_check", 0.1);
			}

			if(itm2 == "pistol202")
			{
				if(CheckCharacterItem(GetMainCharacter(),"pistolthrow3"))
				{
					RemoveCharacterEquip(mchref, GUN_ITEM_TYPE);
					TakeItemFromCharacter(mchref, "pistolthrow3");
					TakeItemFromCharacter(mchref, "pistol202");

					if(CheckCharacterItem(GetMainCharacter(),"pistol201"))
					{
						TakeItemFromCharacter(mchref, "pistol201");
						GiveItem2Character(mchref, "pistolthrow5");
						EquipCharacterByItem(mchref, "pistolthrow5");
					}
					else
					{
						GiveItem2Character(mchref, "pistolthrow4");
						EquipCharacterByItem(mchref, "pistolthrow4");
					}

					if(CheckCharacterItem(GetMainCharacter(),"ammobag1"))
					{
						TakeItemFromCharacter(mchref, "ammobag1");
						GiveItem2Character(mchref, "ammobag2");
					}
				}

				if(CheckCharacterItem(GetMainCharacter(),"pistolbelt"))
				{
					if(CheckCharacterItem(GetMainCharacter(),"pistol206") && CheckCharacterItem(GetMainCharacter(),"pistol205")
					&& CheckCharacterItem(GetMainCharacter(),"pistol204") && CheckCharacterItem(GetMainCharacter(),"pistol201"))
					{
						TakeItemFromCharacter(mchref, "pistol201"); TakeItemFromCharacter(mchref, "pistol202");
						TakeItemFromCharacter(mchref, "pistol204"); TakeItemFromCharacter(mchref, "pistol205");
						TakeItemFromCharacter(mchref, "pistol206");
						RemoveCharacterEquip(mchref, BELT_ITEM_TYPE);
						TakeItemFromCharacter(mchref, "pistolbelt");
						GiveItem2Character(mchref, "pistol20");
						EquipCharacterByItem(mchref, "pistol20");
					}
					else
					{
						gp = GetCharacterItem(mchref, "gunpowder");
						pb = GetCharacterItem(mchref, "pistolbullets");

						if(gp >= 1 && pb >= 1 && IsEquipCharacterByItem(mchref, "pistolbelt"))
						{
							EquipCharacterByItem(mchref, "pistol202");
						}
					}
				}

				if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0) LAi_QuestDelay("pchar_outfit_check", 0.1);
			}

			if(itm2 == "pistol204")
			{
				if(CheckCharacterItem(GetMainCharacter(),"pistolthrow2"))
				{
					RemoveCharacterEquip(mchref, GUN_ITEM_TYPE);
					TakeItemFromCharacter(mchref, "pistolthrow2");
					TakeItemFromCharacter(mchref, "pistol204");

					if(CheckCharacterItem(GetMainCharacter(),"pistol201") && CheckCharacterItem(GetMainCharacter(),"pistol202"))
					{
						TakeItemFromCharacter(mchref, "pistol201"); TakeItemFromCharacter(mchref, "pistol202");
						GiveItem2Character(mchref, "pistolthrow5");
						EquipCharacterByItem(mchref, "pistolthrow5");
					}

					if(CheckCharacterItem(GetMainCharacter(),"pistol202") && !CheckCharacterItem(GetMainCharacter(),"pistol201"))
					{
						TakeItemFromCharacter(mchref, "pistol202");
						GiveItem2Character(mchref, "pistolthrow4");
						EquipCharacterByItem(mchref, "pistolthrow4");
					}

					if(!CheckCharacterItem(GetMainCharacter(),"pistol202"))
					{
						GiveItem2Character(mchref, "pistolthrow3");
						EquipCharacterByItem(mchref, "pistolthrow3");
					}

					if(CheckCharacterItem(GetMainCharacter(),"ammobag1"))
					{
						TakeItemFromCharacter(mchref, "ammobag1");
						GiveItem2Character(mchref, "ammobag2");
					}
				}

				if(CheckCharacterItem(GetMainCharacter(),"pistolbelt"))
				{
					if(CheckCharacterItem(GetMainCharacter(),"pistol206") && CheckCharacterItem(GetMainCharacter(),"pistol205")
					&& CheckCharacterItem(GetMainCharacter(),"pistol202") && CheckCharacterItem(GetMainCharacter(),"pistol201"))
					{
						TakeItemFromCharacter(mchref, "pistol201"); TakeItemFromCharacter(mchref, "pistol202");
						TakeItemFromCharacter(mchref, "pistol204"); TakeItemFromCharacter(mchref, "pistol205");
						TakeItemFromCharacter(mchref, "pistol206");
						RemoveCharacterEquip(mchref, BELT_ITEM_TYPE);
						TakeItemFromCharacter(mchref, "pistolbelt");
						GiveItem2Character(mchref, "pistol20");
						EquipCharacterByItem(mchref, "pistol20");
					}
					else
					{
						gp = GetCharacterItem(mchref, "gunpowder");
						pb = GetCharacterItem(mchref, "pistolbullets");

						if(gp >= 1 && pb >= 1 && IsEquipCharacterByItem(mchref, "pistolbelt"))
						{
							EquipCharacterByItem(mchref, "pistol204");
						}
					}
				}

				if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0) LAi_QuestDelay("pchar_outfit_check", 0.1);
			}

			if(itm2 == "pistol205")
			{
				if(CheckCharacterItem(GetMainCharacter(),"pistolthrow1"))
				{
					RemoveCharacterEquip(mchref, GUN_ITEM_TYPE);
					TakeItemFromCharacter(mchref, "pistolthrow1");
					TakeItemFromCharacter(mchref, "pistol205");

					if(CheckCharacterItem(GetMainCharacter(),"pistol201") && CheckCharacterItem(GetMainCharacter(),"pistol202")
					&& CheckCharacterItem(GetMainCharacter(),"pistol204"))
					{
						TakeItemFromCharacter(mchref, "pistol201"); TakeItemFromCharacter(mchref, "pistol202");
						TakeItemFromCharacter(mchref, "pistol204");
						GiveItem2Character(mchref, "pistolthrow5");
						EquipCharacterByItem(mchref, "pistolthrow5");
					}

					if(CheckCharacterItem(GetMainCharacter(),"pistol202") && CheckCharacterItem(GetMainCharacter(),"pistol204")
					&& !CheckCharacterItem(GetMainCharacter(),"pistol201"))
					{
						TakeItemFromCharacter(mchref, "pistol202"); TakeItemFromCharacter(mchref, "pistol204");
						GiveItem2Character(mchref, "pistolthrow4");
						EquipCharacterByItem(mchref, "pistolthrow4");
					}

					if(CheckCharacterItem(GetMainCharacter(),"pistol204") && !CheckCharacterItem(GetMainCharacter(),"pistol202")
					&& !CheckCharacterItem(GetMainCharacter(),"pistol201"))
					{
						TakeItemFromCharacter(mchref, "pistol204");
						GiveItem2Character(mchref, "pistolthrow3");
						EquipCharacterByItem(mchref, "pistolthrow3");
					}

					if(!CheckCharacterItem(GetMainCharacter(),"pistol204"))
					{
						GiveItem2Character(mchref, "pistolthrow2");
						EquipCharacterByItem(mchref, "pistolthrow2");
					}

					if(CheckCharacterItem(GetMainCharacter(),"ammobag1"))
					{
						TakeItemFromCharacter(mchref, "ammobag1");
						GiveItem2Character(mchref, "ammobag2");
					}
				}

				if(CheckCharacterItem(GetMainCharacter(),"pistolbelt"))
				{
					if(CheckCharacterItem(GetMainCharacter(),"pistol206") && CheckCharacterItem(GetMainCharacter(),"pistol201")
					&& CheckCharacterItem(GetMainCharacter(),"pistol204") && CheckCharacterItem(GetMainCharacter(),"pistol202"))
					{
						TakeItemFromCharacter(mchref, "pistol201"); TakeItemFromCharacter(mchref, "pistol202");
						TakeItemFromCharacter(mchref, "pistol204"); TakeItemFromCharacter(mchref, "pistol205");
						TakeItemFromCharacter(mchref, "pistol206");
						RemoveCharacterEquip(mchref, BELT_ITEM_TYPE);
						TakeItemFromCharacter(mchref, "pistolbelt");
						GiveItem2Character(mchref, "pistol20");
						EquipCharacterByItem(mchref, "pistol20");
					}
					else
					{
						gp = GetCharacterItem(mchref, "gunpowder");
						pb = GetCharacterItem(mchref, "pistolbullets");

						if(gp >= 1 && pb >= 1 && IsEquipCharacterByItem(mchref, "pistolbelt"))
						{
							EquipCharacterByItem(mchref, "pistol205");
						}
					}
				}

				if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0) LAi_QuestDelay("pchar_outfit_check", 0.1);
			}

			if(itm2 == "pistol206")
			{
				if(CheckCharacterItem(GetMainCharacter(),"pistolbelt"))
				{
					RemoveCharacterEquip(mchref, BELT_ITEM_TYPE);
					RemoveCharacterEquip(mchref, GUN_ITEM_TYPE);
					TakeItemFromCharacter(mchref, "pistolbelt");
					TakeItemFromCharacter(mchref, "pistol206");

					if(CheckCharacterItem(GetMainCharacter(),"pistol201") && CheckCharacterItem(GetMainCharacter(),"pistol202")
					&& CheckCharacterItem(GetMainCharacter(),"pistol204") && CheckCharacterItem(GetMainCharacter(),"pistol205"))
					{
						TakeItemFromCharacter(mchref, "pistol201"); TakeItemFromCharacter(mchref, "pistol202");
						TakeItemFromCharacter(mchref, "pistol204"); TakeItemFromCharacter(mchref, "pistol205");
						GiveItem2Character(mchref, "pistolthrow5");
						EquipCharacterByItem(mchref, "pistolthrow5");
					}

					if(CheckCharacterItem(GetMainCharacter(),"pistol202") && CheckCharacterItem(GetMainCharacter(),"pistol204")
					&& CheckCharacterItem(GetMainCharacter(),"pistol205") && !CheckCharacterItem(GetMainCharacter(),"pistol201"))
					{
						TakeItemFromCharacter(mchref, "pistol202"); TakeItemFromCharacter(mchref, "pistol204");
						TakeItemFromCharacter(mchref, "pistol205");
						GiveItem2Character(mchref, "pistolthrow4");
						EquipCharacterByItem(mchref, "pistolthrow4");
					}

					if(CheckCharacterItem(GetMainCharacter(),"pistol204") && CheckCharacterItem(GetMainCharacter(),"pistol205")
					&& !CheckCharacterItem(GetMainCharacter(),"pistol201") && !CheckCharacterItem(GetMainCharacter(),"pistol202"))
					{
						TakeItemFromCharacter(mchref, "pistol204"); TakeItemFromCharacter(mchref, "pistol205");
						GiveItem2Character(mchref, "pistolthrow3");
						EquipCharacterByItem(mchref, "pistolthrow3");
					}

					if(CheckCharacterItem(GetMainCharacter(),"pistol205") && !CheckCharacterItem(GetMainCharacter(),"pistol204")
					&& !CheckCharacterItem(GetMainCharacter(),"pistol201") && !CheckCharacterItem(GetMainCharacter(),"pistol202"))
					{
						TakeItemFromCharacter(mchref, "pistol205");
						GiveItem2Character(mchref, "pistolthrow2");
						EquipCharacterByItem(mchref, "pistolthrow2");
					}

					if(!CheckCharacterItem(GetMainCharacter(),"pistol205"))
					{
						GiveItem2Character(mchref, "pistolthrow1");
						EquipCharacterByItem(mchref, "pistolthrow1");
					}

					if(CheckCharacterItem(GetMainCharacter(),"ammobag1"))
					{
						TakeItemFromCharacter(mchref, "ammobag1");
						GiveItem2Character(mchref, "ammobag2");
					}
				}

				if(CheckCharacterItem(GetMainCharacter(),"pistolbelt"))
				{
					if(CheckCharacterItem(GetMainCharacter(),"pistol201") && CheckCharacterItem(GetMainCharacter(),"pistol205")
					&& CheckCharacterItem(GetMainCharacter(),"pistol204") && CheckCharacterItem(GetMainCharacter(),"pistol202"))
					{
						TakeItemFromCharacter(mchref, "pistol201"); TakeItemFromCharacter(mchref, "pistol202");
						TakeItemFromCharacter(mchref, "pistol204"); TakeItemFromCharacter(mchref, "pistol205");
						TakeItemFromCharacter(mchref, "pistol206");
						RemoveCharacterEquip(mchref, BELT_ITEM_TYPE);
						TakeItemFromCharacter(mchref, "pistolbelt");
						GiveItem2Character(mchref, "pistol20");
						EquipCharacterByItem(mchref, "pistol20");
					}
					else
					{
						gp = GetCharacterItem(mchref, "gunpowder");
						pb = GetCharacterItem(mchref, "pistolbullets");

						if(gp >= 1 && pb >= 1 && IsEquipCharacterByItem(mchref, "pistolbelt"))
						{
							EquipCharacterByItem(mchref, "pistol206");
						}
					}
				}

				if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0) LAi_QuestDelay("pchar_outfit_check", 0.1);
			}

			if(itm2 == "drawing_kit")
			{
				int learned_perk = 0;

				if(!CheckCharacterPerk(mchref, "SailingProfessional") && learned_perk == 0)
				{
					if(CheckCharacterPerk(mchref, "SandbankManeuver") && CheckCharacterPerk(mchref, "StormProfessional"))
					{
						mchref.perks.list.SailingProfessional = true;
						mchref.quest.drawing_kit = "seawolf";
						learned_perk = 1;
					}
				}

				if(!CheckCharacterPerk(mchref, "StormProfessional") && learned_perk == 0)
				{
					if(CheckCharacterPerk(mchref, "ShipTurnRateUp") && CheckCharacterPerk(mchref, "ShipSpeedUp"))
					{
						mchref.perks.list.StormProfessional = true;
						mchref.quest.drawing_kit = "storm";
						learned_perk = 1;
					}
				}

				if(!CheckCharacterPerk(mchref, "SandbankManeuver") && learned_perk == 0)
				{
					if(CheckCharacterPerk(mchref, "ShipTurnRateUp") && CheckCharacterPerk(mchref, "ShipSpeedUp"))
					{
						mchref.perks.list.SandbankManeuver = true;
						mchref.quest.drawing_kit = "sandbank";
						learned_perk = 1;
					}
				}

				if(!CheckCharacterPerk(mchref, "Turn180") && learned_perk == 0)
				{
					if(CheckCharacterPerk(mchref, "ShipTurnRateUp"))
					{
						mchref.perks.list.Turn180 = true;
						mchref.quest.drawing_kit = "turn180";
						learned_perk = 1;
					}
				}

				if(!CheckCharacterPerk(mchref, "ShipTurnRateUp") && learned_perk == 0)
				{
					mchref.perks.list.ShipTurnRateUp = true;
					mchref.quest.drawing_kit = "maneuver";
					learned_perk = 1;
				}

				if(!CheckCharacterPerk(mchref, "ShipSpeedUp") && learned_perk == 0)
				{
					mchref.perks.list.ShipSpeedUp = true;
					mchref.quest.drawing_kit = "speed";
					learned_perk = 1;
				}

				if(!CheckCharacterPerk(mchref, "ProfessionalDamageControl"))
				{
					if(CheckCharacterPerk(mchref, "AdvancedDamageControl") && learned_perk == 0)
					{
						mchref.perks.list.ProfessionalDamageControl = true;
						mchref.quest.drawing_kit = "def3";
						learned_perk = 1;
					}
					else
					{
						if(CheckCharacterPerk(mchref, "BasicDamageControl") && learned_perk == 0)
						{
							mchref.perks.list.AdvancedDamageControl = true;
							mchref.quest.drawing_kit = "def2";
							learned_perk = 1;
						}
						else
						{
							if(learned_perk == 0)
							{
								mchref.perks.list.BasicDamageControl = true;
								mchref.quest.drawing_kit = "def1";
								learned_perk = 1;
							}
						}
					}
				}
			}

			if(itm2 == "temp_purse")
			{
				t_p = GetCharacterItem(mchref, "temp_purse");
				TakeNItems(mchref, "temp_purse", -t_p);
				AddMoneyToCharacter(mchref, t_p);
			}

			if(itm2 == "temp_coins")
			{
				t_c = GetCharacterItem(mchref, "temp_coins");
				TakeNItems(mchref, "temp_coins", -t_c);
				AddMoneyToCharacter(mchref, t_c);
			}

			if(itm2 == "book49")
			{
				TakeNItems(mchref,"book50", 1);
				DeleteAttribute(g_refItems,"Items."+"book50");
			}

			if(itm2=="coin1" || itm2=="coin2" || itm2=="coin3"|| itm2=="coin4" || itm2=="coin5" || itm2=="coin6" || itm2=="coin7"|| itm2=="coin8"
			|| itm2=="coin9" || itm2=="coin10"|| itm2=="coin11" || itm2=="coin12" || itm2=="coin13" || itm2=="coin14"|| itm2=="coin15" || itm2=="coin16")
			{
				PlaySound("INTERFACE\took_item.wav");

				//count how many coins there are in the collection box now!
				mchref.quest.collect_coins = sti(mchref.quest.collect_coins) - 1;

				int price;
				price = GetItemPriceByID(itm2);
				mchref.quest.collect_value = sti(mchref.quest.collect_value) - price;

				if(itm2=="coin2" || itm2=="coin3" || itm2=="coin6" || itm2=="coin7" || itm2=="coin10" || itm2=="coin12" || itm2=="coin15")
				{
					mchref.quest.collect_right_coins = sti(mchref.quest.collect_right_coins) - 1;
				}

				LAi_QuestDelay("collection_box", 0.1);
			}
	//JRH <--

		}
	}
	// Sulan: Quicker Inventory  -->
	// FillScroll();
	if(takeitem)
	{
		if( Items_FindItem(itm2,&arItem)>=0 )
		{
			itm2name = "#";
			if (CheckAttribute(arItem, "QualityName")) itm2name += TranslateString("", "q"+arItem.QualityName) + " ";
			itm2name += GetAssembledString(TranslateString("", arItem.name),arItem);
		}
		MoveItem( 1, itm2, amount, itm2name);
		// <-- Sulan
		SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"ONE_ITEMSLIST",-1);
		SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"TWO_ITEMSLIST",-1);
		SetUpDownUsed();
		SetScrollsUsing();

	//JRH -->
		if(CheckAttribute(mchref, "quest.cannonballs_in_counterbox") && mchref.quest.cannonballs_in_counterbox == "0")
		{
		 	mchref.quest.wr_quest1 = "armory_box3_empty";//JRH
		}
	//<-- JRH

	}
}

// Sulan 07/2010: Function to return the maximum number of bullets or gunpowder
// units which the specified character can take
int HowManyItemsCanITake(string item_ID, ref _refchar)
{
	int i;
	int gp;	// gunpowder
	int pb; // pistol bullets
	int pg; // pistol grapes
	int mb; // musket bullets
	int tb; // total bullet count
	int p;  // max number of gunpowder units
	int s;  // max number of shots
	int ar; // arrows
	int ar2; // small poisoned arrows
	int a;  // max number of arrows
	int a2; // max number of small poisoned arrows
	int bg;
	int ro; // rockets
	int r;  // max number of rockets
	int bmf, pmk, pmkB; //max number of blade_mKnife, pistolmket, pitolmketB

	if(IsMainCharacter(_refchar))
	{
		gp = GetCharacterItem(_refchar, "gunpowder");
		pb = GetCharacterItem(_refchar, "pistolbullets");
		pg = GetCharacterItem(_refchar, "pistolgrapes");
		mb = GetCharacterItem(_refchar, "musketbullets");
		tb = pb + pg + 2*mb;  // musket bullets count double
		ar = GetCharacterItem(_refchar, "bladearrows");
		ar2 = GetCharacterItem(_refchar, "arrows2");
		bg = GetCharacterItem(_refchar, "blowgun");
		ro = GetCharacterItem(_refchar, "rockets");

		if(IsEquipCharacterByItem(_refchar, "ammobag2"))
		{
			p = (3 * MAX_GUNPOWDER);
			s = (3* MAX_SHOTS);
		}
		else
		{
		    if(IsEquipCharacterByItem(_refchar, "powderbarrel"))
		    {
			    p = (4 * MAX_GUNPOWDER);
		    }
		    else
		    {
			if(IsEquipCharacterByItem(_refchar, "powderflask"))
			{
				if(CheckCharacterItem(_refchar,"bladepowderhornP") || CheckCharacterItem(_refchar,"bladepowderhornA"))
				{
					p = (3 * MAX_GUNPOWDER);
				}
				else p = (2 * MAX_GUNPOWDER);
			}
			else
			{
				if(CheckCharacterItem(_refchar,"bladepowderhornP") || CheckCharacterItem(_refchar,"bladepowderhornA"))
				{
					p = (2 * MAX_GUNPOWDER);
				}
				else p = MAX_GUNPOWDER;
			}
		    }

		    if(IsEquipCharacterByItem(_refchar, "ammobag"))
		    {
			    s = (4* MAX_SHOTS);
		    }
		    else
		    {
			if(IsEquipCharacterByItem(_refchar, "ammopouch"))
			{
				s = (2* MAX_SHOTS);
			}
			else s = MAX_SHOTS;
		    }
		}

		if(IsEquipCharacterByItem(_refchar, "quiver"))
		{
			a = (2* MAX_SHOTS);
		}
		else a = 3;

		if(CheckCharacterItem(_refchar,"blowgun"))
		{
			a2 = (bg*MAX_SHOTS);
		}
		else a2 = 0;

		if(IsEquipCharacterByItem(_refchar, "rocketbag"))
		{
			r = 8;		
		}
		else r = 2;

		switch(item_ID)
		{
			case "gunpowder":
				if( gp < p ) i = (p-gp);
				else i=0;
			break;
			case "pistolbullets":
				if(tb < s) i = (s-tb);
				else i=0;
			break;
			case "pistolgrapes":
				if(tb < s) i = (s-tb);
				else i=0;
			break;
			case "musketbullets":
				if(tb < (s-1)) i = ((s-tb)/2);
				else i =0;
			break;
			case "bladearrows":
				if(ar < a) i = (a-ar);
				else i=0;
			break;
			case "arrows2":
				if(ar2 < a2) i = (a2-ar2);
				else i=0;
			break;
			case "rockets":
				if(ro < r) i = (r-ro);
				else i=0;
			break;
		}
	}
	else
	{
		// For Officers
		if(IsOfficer(_refchar))
		{
			gp = GetCharacterItem(_refchar, "gunpowder");
			pb = GetCharacterItem(_refchar, "pistolbullets");
			pg = GetCharacterItem(_refchar, "pistolgrapes");
			mb = GetCharacterItem(_refchar, "musketbullets");
			tb = pb + pg + 2*mb;  // musket bullets count double
			ar = GetCharacterItem(_refchar, "bladearrows");

			bmf = GetCharacterItem(_refchar, "blade_mKnife");
			pmk = GetCharacterItem(_refchar, "pistolmket");
			pmkB = GetCharacterItem(_refchar, "pistolmketB");

			if(CheckCharacterItem(_refchar,"powderbarrel"))
			{
				p = (4 * MAX_GUNPOWDER);
			}
			else
			{
				if(CheckCharacterItem(_refchar,"powderflask"))
				{
					p = (2 * MAX_GUNPOWDER);
				}
				else p = MAX_GUNPOWDER;
			}

	 		if(CheckCharacterItem(_refchar,"ammobag"))
			{
				s = (4* MAX_SHOTS);
			}
			else
			{
				if(CheckCharacterItem(_refchar,"ammopouch"))
				{
					s = (2* MAX_SHOTS);
				}
				else s = MAX_SHOTS;
			}

			if(IsEquipCharacterByItem(_refchar, "quiver"))
			{
				a = (2* MAX_SHOTS);
			}
			else a = 3;

			switch(item_ID)
			{
				case "gunpowder":
					if( gp < p ) i = (p-gp);
					else i=0;
				break;
				case "pistolbullets":
					if(tb < s) i = (s-tb);
					else i=0;
				break;
				case "pistolgrapes":
					if(tb < s) i = (s-tb);
					else i=0;
				break;
				case "musketbullets":
					if(tb < (s-1)) i = ((s-tb)/2);
					else i =0;
				break;
				case "bladearrows":
					if(ar < a) i = (a-ar);
					else i=0;
				break;

				case "blade_mKnife":
					if(bmf == 1) i = 0;
					if(bmf == 0) i = 1;
				break;

				case "pistolmket":
					if(pmk == 1) i = 0;
					if(pmk == 0) i = 1;
				break;

				case "pistolmketB":
					if(pmkB == 1) i = 0;
					if(pmk == 0) i = 1;
				break;
			}
		}
	}
	else
	{
		switch(item_ID)
		{
			case "gunpowder":
				i = 1000000;
			break;
			case "pistolbullets":
				i = 1000;
			break;
			case "pistolgrapes":
				i = 1000;
			break;
			case "musketbullets":
				i = 1000;
			break;
		}
	}
	return i;
}

void InsertItem(int source_itemlist, string source_itemID, int amount, string str2)
{
	string sourceItem;    // name of the item in the array to be deleted
	string tempItem;    // name of the following item in the array
	int i;
	int j;
	int newamount;
	string tempStr1;
	aref list;
	string listname;

	if (amount <= 0) return;

	switch(source_itemlist)
	{
		case 0:                                       // insert into chest
			makearef(list,GameInterface.two_itemslist);
			listname="two_itemslist";
		break;
		case 1:                                       // insert into inventory
			makearef(list,GameInterface.one_itemslist);
			listname="one_itemslist";
		break;
	}
	j = list.ListSize;
	for(i=1; i<=j;i++)   // check, if such item is already in the list
	{
		tempItem = "pic" + i;

		// -> Sulan: Debug trace to identify invalid items (such without itemID)
		if(!CheckAttribute(&GameInterface,listname+"."+tempItem+".ItemID")) trace("Itemsbox.c invalid item: "+tempItem+" source list: "+source_itemlist+" name: "+str2);
		// <- Sulan

		if (list.(tempItem).ItemID == source_itemID )
		{
			if(CheckAttribute(&GameInterface, listname+"."+tempItem+".str1")) // if more than one item already in destination list
			{
				tempStr1 =  striphash(list.(tempItem).str1);
				if(tempStr1=="")
				{
				newamount = 1 + amount;
				}
				else
				{
					newamount = sti(tempStr1) + amount;
				}
			}
			else   // only one item in destination list
			{
				newamount = 1 + amount;
			}
			list.(tempItem).str1 = "#" + newamount;
			SendMessage(&GameInterface, "ls", MSG_INTERFACE_REFRESH_SCROLL, listname);
			return;
		}
	}
	// if item is not in the list, add it
	tempItem = "pic" + i;
	if(source_itemID == "Money")
	{
		list.(tempItem).img1 = GetItemPictureName("Gold");
		list.(tempItem).tex1 = GetItemPictureTexture(listname+".ImagesGroup","Gold");
		if(DynamicInterfaceLevel() > 0) list.(tempItem).str2 = "Gold"; // PB: Dynamic Interfaces
	}
	else
	{
		list.(tempItem).img1 = GetItemPictureName(source_itemID);
		list.(tempItem).tex1 = GetItemPictureTexture(listname+".ImagesGroup",source_itemID);
		if(DynamicInterfaceLevel() > 0) list.(tempItem).str2 = str2; // PB: Dynamic Interfaces
	}
	list.(tempItem).ItemID = source_itemID;
	if (amount > 1) list.(tempItem).str1 = "#"+amount;
	else list.(tempItem).str1 = "";
	list.ListSize = i;
	SendMessage(&GameInterface, "ls", MSG_INTERFACE_REFRESH_SCROLL, listname);
}

void RemoveItem(int item_list, string item_ID, int amount)
{
	string oldItem;    // name of the item in the array to be deleted
	string newItem;    // name of the following item in the array
	string tempItem;
	aref list;
	string listname;
	int i, j, k;
	int item_no;
	int scroll_pos;
	int temp;

	if (amount <= 0) return;

	switch(item_list)
	{
		case 0:                                                                      // is the Player's inventory (upper scrollbar)
			makearef(list,GameInterface.one_itemslist);
			listname="one_itemslist";
		break;
		case 1:
			makearef(list,GameInterface.two_itemslist);
			listname="two_itemslist";
		break;
	}
	j = list.ListSize;
	for(k=1; k <=j;k++)
	{
		tempItem = "pic" + k;

		// -> Sulan: Debug trace to identify invalid items (such without itemID)
		if(!CheckAttribute(&GameInterface,listname+"."+tempItem+".ItemID")) trace("Itemsbox.c invalid item: "+tempItem+" source list: "+item_list);
		// <- Sulan

		if(list.(tempItem).itemID == item_ID)
		{
			item_no = k;
			break;
		}
	}
	if(CheckAttribute(&GameInterface, listname+"."+tempItem+".str1"))
	{
		temp = sti(striphash(list.(tempItem).str1));
	}
	else
	{
		temp = 1;
	}
	if(amount<temp)   // if there are more items in the list than to be removed
	{
		if((temp-amount)>1)
		{
			list.(tempItem).str1 = "#"+(temp-amount);
		}
		else
		{
			list.(tempItem).str1 = "";
		}
	}
	else
	{
		if (j==item_no)                                 // if item is the last item in list
		{
			newItem = "pic" + item_no;
			i = list.ListSize;
		}
		else
		{
			for(i=item_no; i < j ; i++)                   // move all items to the left
			{
				temp = i+1;
				oldItem = "pic" + i;
				newItem = "pic" + temp;

				list.(olditem).img1 = list.(newItem).img1;
				list.(olditem).tex1 = list.(newItem).tex1;
				list.(olditem).itemID = list.(newItem).itemID;
				if(CheckAttribute(&GameInterface, listname+"."+newItem+".str1"))  list.(olditem).str1 = list.(newItem).str1;
				else list.(olditem).str1 = "";
				if(CheckAttribute(&GameInterface, listname+"."+newItem+".img2"))  list.(olditem).img2 = list.(newItem).img2;
				else list.(olditem).img2 = "";
				if(CheckAttribute(&GameInterface, listname+"."+newItem+".tex2"))  list.(olditem).tex2 = list.(newItem).tex2;
				else list.(olditem).tex2 = "";
				if(DynamicInterfaceLevel() > 0) list.(olditem).str2 = list.(newItem).str2; // PB: Dynamic Interfaces
			}
		}
		if(CheckAttribute(&GameInterface,listname+".current")) scroll_pos = (sti(list.current)+1);
		if (scroll_pos>=j)
		{
			list.current = (scroll_pos-2);
		}
		DeleteAttribute(&GameInterface,listname+"." + newItem);        //delete last item
		if (i>=1) {list.ListSize = i-1;}
	}
	if(list.ListSize==0 && item_list==1) noConfirm = true;
	SendMessage(&GameInterface, "ls", MSG_INTERFACE_REFRESH_SCROLL, listname);
}

void MoveItem(int source_itemlist, string source_itemID, int amount, string str2 )
{
	InsertItem( source_itemlist, source_itemID, amount, str2);
	RemoveItem( source_itemlist, source_itemID, amount);
}

void GetDescribeData(int iScroll, int iRect, ref nameStr, ref descrStr, ref picStr, ref texStr)
{
	aref arItem;
	//string descrStr = "";
	string Quality = ""; // NK
	bool bYesDescribe = false;

// KK -->
	nameStr = "";
	descrStr = "";
	picStr = "";
	texStr = "";
// <-- KK

	if (iScroll == 1) bYesDescribe = GetItemRefByOrder(true, nCurScroll1 + iRect, &arItem);
	if (iScroll == 2) bYesDescribe = GetItemRefByOrder(false,nCurScroll2 + iRect, &arItem);

	if( !bYesDescribe ) {
		// KK SetFormatedText("DESCRIBEWINDOW","");
		bEnableDown = false;
		return;
	}
	// NK -->
	if( CheckAttribute(arItem,"name") ) // NK, was checking attr "describe"
	{
		if( GetAttribute(arItem,"groupID") == QUEST_ITEM_TYPE)
		{
			nameStr = PreprocessText(TranslateString("", arItem.name)); // PB
		}
		else
		{
			nameStr += GetAssembledString(TranslateString("", arItem.name),arItem);
		}
	}
	// NK <--
	if( CheckAttribute(arItem,"groupID") )
	{
		// NK -->
		// LDH added quality "q" translation string - 07May09
		if (CheckAttribute(arItem,"QualityName")) { Quality = arItem.QualityName; nameStr = TranslateString("","q"+Quality) + " " + nameStr; }
		//GameInterface.strings.itemname = descrStr;
		//descrStr += newLineStr;
		// NK <--
		if(arItem.groupID==GUN_ITEM_TYPE)
		{
			descrStr = GetAssembledString(TranslateString("","weapon gun parameters"), arItem);
		}
		if(arItem.groupID==BLADE_ITEM_TYPE)
		{
			descrStr = GetAssembledString(TranslateString("","weapon blade parameters"), arItem);
		}
		// GreatZen -->
		if(arItem.groupID==ARMOR_ITEM_TYPE)
		{
			descrStr = GetAssembledString(TranslateString("","weapon armor parameters"),arItem);
		}
		// GreatZen <--
	}
	if( CheckAttribute(arItem,"describe") )
	{
		if(descrStr!="") { descrStr += GlobalStringConvert("newline"); }
		if( GetAttribute(arItem,"groupID") == QUEST_ITEM_TYPE)
		{
			descrStr += PreprocessText(TranslateString("",arItem.describe)) + GetItemBonuses(arItem.id); // PB
		}
		else
		{
			descrStr += GetAssembledString(TranslateString("",arItem.describe),arItem) + GetItemBonuses(arItem.id); // NK
		}
	}

	picStr = GetItemPictureName(arItem.id);
	texStr = GetItemTextureName(arItem.id);

	// KK SetFormatedText("DESCRIBEWINDOW",descrStr);
	//bEnableDown = SendMessage(&GameInterface,"lsll",MSG_INTERFACE_MSG_TO_NODE,"DESCRIBEWINDOW", 6, 0);
	//return;
}

//==============================
// items utilites
//==============================
string GetItemIDByOrder(bool my,int num)
{
	string attrName = "pic"+(num+1);
	if(my)
	{
		if( CheckAttribute(&GameInterface,"one_itemslist."+attrName+".itemID") )
			return GameInterface.one_itemslist.(attrName).itemID;
	}
	else
	{
		if( CheckAttribute(&GameInterface,"two_itemslist."+attrName+".itemID") )
			return GameInterface.two_itemslist.(attrName).itemID;
	}
	return "";
}

bool GetItemRefByOrder(bool my,int num, ref refItem)
{
	aref ar;
	string itemID = GetItemIDByOrder(my,num);
	if(itemID=="Money") itemID="gold";
	if( Items_FindItem(itemID,&ar)<0 ) return false;
	refItem = ar;
	return true;
}

int GetItemQntByOrder(bool my,int num)
{
	string itmName = GetItemIDByOrder(my,num);
// KK -->
	int iqty = 0;
	ref PChar;
	if (my)
	{
		PChar = GetMainCharacter();
		if (itmName == "Money" && CheckAttribute(PChar, "Money") == true) return sti(PChar.Money);
		iqty = GetCharacterItem(PChar, itmName);
		if (IsEquipCharacterByItem(PChar, itmName))
		{
			iqty--;
			if (iqty <= 0) iqty = 0;
		}
	}
	else
	{
		if (itmName == "Money" && CheckAttribute(g_refItems, "Money") == true) return sti(g_refItems.Money);
		if (isItemsBox)
		{
			if (CheckAttribute(g_refItems, "items." + itmName)) iqty = sti(g_refItems.items.(itmName));
		}
		else
		{
			iqty = GetCharacterItem(g_refItems, itmName);
			if (IsEquipCharacterByItem(g_refItems, itmName))
			{
				iqty--;
				if (iqty <= 0) iqty = 0;
			}
		}
	}
	return iqty;
// <-- KK
}

bool CheckConsumedItem(string itemID)
{
	aref arone;
	makearef(arone,Characters[GetMainCharacterIndex()].items);
	aref artwo;
	makearef(artwo,g_refItems.items);

	int n=0;
	if( CheckAttribute(arone,itemID) ) n = sti(arone.(itemID));
	if( CheckAttribute(artwo,itemID) ) n = n + sti(artwo.(itemID));

	if(n>1) return true;
	return false;
}

bool CanCharacterTakeItem(bool myCh,string itemName)
{
	if(!myCh) return true;
	aref chref = GetMainCharacter();
//	makearef(chref,Characters[GetMainCharacterIndex()]);
	if( CheckAttribute(chref,"items."+itemName) ) return true;
	if( GetChrItemQuantity(GetMainCharacter())<MAX_ITEM_TAKE ) return true;
	return false;
}

void SetUpDownUsed()
{
	aref iref; makearef(iref,Characters[GetMainCharacterIndex()].items);

	ref PChar = GetMainCharacter(); //JRH

	string itmName1 = GetItemIDByOrder(true,nCurScroll1);
	int iq1 = GetItemQntByOrder(true,nCurScroll1);
	string itmName2 = GetItemIDByOrder(false,nCurScroll2);
	int iq2 = GetItemQntByOrder(false,nCurScroll2);

	if(iq1<=0)
	{
		SetSelectable("ONEDOWN_BUTTON",false);
		SetSelectable("ALLDOWN_BUTTON",false);
	}
	else
	{
		SetSelectable("ONEDOWN_BUTTON",true);
		SetSelectable("ALLDOWN_BUTTON",true);
	}

	if(iq2<=0)
	{
		SetSelectable("ONEUP_BUTTON",false);
		SetSelectable("ALLUP_BUTTON",false);
	}
	else
	{
		if( CheckAttribute(iref,itmName2) || GetAttributesNum(iref)<MAX_ITEM_TAKE )
		{
			SetSelectable("ONEUP_BUTTON",true);
			SetSelectable("ALLUP_BUTTON",true);
		}
		else
		{
			SetSelectable("ONEUP_BUTTON",false);
			SetSelectable("ALLUP_BUTTON",false);
		}
	}

	if(itmName2=="" || itmName2=="Money" || GetAttributesNum(iref)<MAX_ITEM_TAKE)
	{
		SetSelectable("SWAP_BUTTON",true);
	}
	else
	{
		if( CheckAttribute(iref,itmName2) )	SetSelectable("SWAP_BUTTON",true);
		else
		{
			if(itmName1!="" && itmName1!="Money") SetSelectable("SWAP_BUTTON",true);
			else SetSelectable("SWAP_BUTTON",false);
		}
	}

	if( IsQuestUsedItem(itmName1) )
	{
		if(itmName1=="picture1" || itmName1=="picture2" || itmName1=="picture3"|| itmName1=="picture4"
		|| itmName1=="picture5" || itmName1=="picture6" || itmName1=="picture7"|| itmName1=="picture8"
		|| itmName1=="picture9" || itmName1=="picture10"|| itmName1=="picture11" || itmName1=="picture13"
		|| itmName1=="picture14"|| itmName1=="picture15")
		{
				SetSelectable("SWAP_BUTTON",false);
		}
		else
		{
			if(itmName1 == "book21" || itmName1 == "book22" || itmName1 == "book23" || itmName1 == "book24"
			|| itmName1 == "book25" || itmName1 == "book26" || itmName1 == "book27" || itmName1 == "book28"
			|| itmName1 == "book29" || itmName1 == "book30" || itmName1 == "book31"
			|| itmName1 == "book33" || itmName1 == "book34" || itmName1 == "book35" || itmName1 == "book36")
			{

			}
			else
			{
				SetSelectable("ONEDOWN_BUTTON",false);
				SetSelectable("ALLDOWN_BUTTON",false);
				SetSelectable("SWAP_BUTTON", false); // Aconcagua
			}
		}
	}

	if( IsQuestUsedItem(itmName1) )
	{
		if(itmName1=="Pell_outfit")
		{
			SetSelectable("ONEDOWN_BUTTON",true);
			SetSelectable("ALLDOWN_BUTTON",true);
			SetSelectable("SWAP_BUTTON",false);
		}
	}

     //JRH -->
	//Not meant to move these separate
	if(itmName1 == "book43" || itmName1 == "book44" || itmName1 == "book50" || itmName1 == "pistollog" 
	|| itmName1 == "doc2A" || itmName1 == "doc2B" || itmName1 == "doc2C" || itmName1 == "doc2D" || itmName1 == "doc2E" 
	|| itmName1 == "doc3C" || itmName1 == "doc3D"
	|| itmName1 == "pistolcharcoal_E" || itmName1 == "pistolnitre_E" || itmName1 == "pistolsulphur_E" || itmName1 == "pistoltinderbox"
	|| itmName1 == "book70" || itmName1 == "book70_0" || itmName1 == "book70_1" || itmName1 == "book70_1"
	|| itmName1 == "book70_2" || itmName1 == "book70_3" || itmName1 == "book70_4" || itmName1 == "book70_5"
	|| itmName1 == "book70_6" || itmName1 == "book70_7" || itmName1 == "book70_8" || itmName1 == "book70_9"
	|| itmName1 == "book70_10" || itmName1 == "book70_11" || itmName1 == "book71_9" || itmName1 == "book71_10"
	|| itmName1 == "book71_11" || itmName1 == "book71_12" || itmName1 == "book71_13" || itmName1 == "book71_14"
	|| itmName1 == "book71_15" || itmName1 == "book71_16" || itmName1 == "book71_17" || itmName1 == "book71_18"
	|| itmName1 == "book71_19" || itmName1 == "book71_20" || itmName1 == "book71_21" || itmName1 == "book71_22"
	|| itmName1 == "book71_23" || itmName1 == "book70_start" || itmName1 == "book71_9_start" || itmName1 == "bladebottle_CV1_sc"
	|| itmName1 == "bladebottle_CB2" || itmName1=="incense" || itmName1 == "book72_package" || itmName1 == "book72_closed"
	|| itmName1 == "book72_openL" || itmName1 == "book72_openR" || itmName1 == "book72_edenL" || itmName1 == "book72_edenR"
	|| itmName1 == "book72_caesarL" || itmName1 == "book72_caesarR" || itmName1 == "book72_handsL" || itmName1 == "book72_handsR"	
	|| itmName1 == "book72_richardsL" || itmName1 == "book72_richardsR")
	{
		SetSelectable("ONEDOWN_BUTTON",false);
		SetSelectable("ALLDOWN_BUTTON",false);
		SetSelectable("SWAP_BUTTON",false);
	}
    //<-- JRH

	if (ENABLE_AMMOMOD) {// TIH --> mod toggle 7-7-06
		// added by MAXIMUS [for gunpowder barrels] -->
		if(isGunpowder)
		{// MAXIMUS 21.07.2006: checking for bullets
			if(GetItemIDByOrder(true,nCurScroll1) != "gunpowder" && GetItemIDByOrder(true,nCurScroll1) != "pistolgrapes" && GetItemIDByOrder(true,nCurScroll1) != "pistolbullets" && GetItemIDByOrder(true,nCurScroll1) != "musketbullets")
			{
				SetSelectable("ONEDOWN_BUTTON",false);
				SetSelectable("ALLDOWN_BUTTON",false);
			}
			SetSelectable("SWAP_BUTTON",false);
		}
		// added by MAXIMUS [for gunpowder barrels] <--
	}// TIH <-- mod toggle

    //JRH -->
	if (ENABLE_AMMOMOD)
	{
	    if(CheckAttribute(Pchar,"boxname") && Pchar.boxname == "WeaponsLocker")	
		{
			if(itmName1 == "gunpowder" || itmName1 == "pistolbullets" || itmName1 == "pistolgrapes" || itmName1 == "musketbullets")
			{
				SetSelectable("ONEDOWN_BUTTON",false);
				SetSelectable("ALLDOWN_BUTTON",false);
				SetSelectable("SWAP_BUTTON",false);
				//Log_SetStringToLog("There's already ammunition here!");
			}

			if(itmName2 == "gunpowder" || itmName2 == "pistolbullets" || itmName2 == "pistolgrapes" || itmName2 == "musketbullets")
			{
				SetSelectable("ONEUP_BUTTON",false);
				SetSelectable("ALLUP_BUTTON",false);
				SetSelectable("SWAP_BUTTON",false);
				//Log_SetStringToLog("That ammunition is for the crew!");
			}
		}
	}

	//to avoid overriding the limits by swapping
	//ex: you have 6gp (no pf). you swap in 6 more from any box, officers etc by giving away any other item (not gp).
	if (ENABLE_AMMOMOD)
	{
		if(itmName2 == "gunpowder" || itmName2 == "pistolbullets" || itmName2 == "pistolgrapes" || itmName2 == "musketbullets")
		{
			SetSelectable("SWAP_BUTTON",false); //hmm should be false JRH?
		}
	}

	if(itmName2 == "pistolretort" || itmName2 == "bladetop" || itmName2 == "pistolglass_tube" || itmName2 == "bladebottle_CE0" 
	|| itmName2 == "bladebottle_BE0" || itmName2 == "bladebottle_CP2" || itmName2 == "pistolcalciumsack" || itmName2 == "pistolcloth" 
	|| itmName2 == "pistolsalt" || itmName2 == "pistolcharcoal_WR" || itmName2 == "pistolnitre" || itmName2 == "pistolstonebasket_G" 
	|| itmName2 == "pistolstonebasket_M" || itmName2 == "pistolstonebasket_B" || itmName2 == "pistolstonebasket_R" 
	|| itmName2 == "pistolbucket_dung" || itmName2 == "pistolsulphur_WR" || itmName2 == "pistolretort3") SetSelectable("SWAP_BUTTON",false);

	if(itmName2 == "cannonballs")
	{
		SetSelectable("ALLUP_BUTTON",false);
	 	SetSelectable("SWAP_BUTTON",false);
		SetSelectable("ONEDOWN_BUTTON",true);
	}

	//multi picture items, not meant to move these separate or Broomes ayahuasca + BB treasure items
	if(itmName2 == "book43" || itmName2 == "book44" || itmName2 == "book50" || itmName2=="ayahuasca" || itmName2 == "gold_bars" || itmName2 == "silver_bars"
	|| itmName2 == "gold_coins" || itmName2 == "valuable_weapons")
	{
		SetSelectable("ONEUP_BUTTON",false);
		SetSelectable("ALLUP_BUTTON",false);
		SetSelectable("SWAP_BUTTON",false);
	}

	if(itmName2 == "blade_gp_dry")
	{
		if(CheckAttribute(Pchar,"Caesar_info") && Pchar.Caesar_info == "no")
		{
			SetSelectable("ONEUP_BUTTON",false);
			SetSelectable("ALLUP_BUTTON",false);
			SetSelectable("SWAP_BUTTON",false);
		}
	}

	if(itmName2 == "book42" || itmName2 == "book49")
	{
		SetSelectable("SWAP_BUTTON",false);
	}

	//to keep track of how many pictures
	if(itmName2=="picture1" || itmName2=="picture2" || itmName2=="picture3"|| itmName2=="picture4" || itmName2=="picture5" || itmName2=="picture6" || itmName2=="picture7"|| itmName2=="picture8"
	|| itmName2=="picture9" || itmName2=="picture10"|| itmName2=="picture11" || itmName2=="picture13" || itmName2=="picture14"|| itmName2=="picture15")
	{
		SetSelectable("SWAP_BUTTON",false);

		if(CheckAttribute(Pchar,"quest.wr_book31") && Pchar.quest.wr_book31 == "repaired")
		{
			SetSelectable("ONEUP_BUTTON",false);
			SetSelectable("ALLUP_BUTTON",false);
		}
	}

	if(itmName2=="pistol0" || itmName2=="bladep0")
	{
		PlaySound("VOICE\ENGLISH\gr_wench3_aye.wav");
		EquipCharacterByItem(CharacterFromID("Wench3"), "bladep0");
		EquipCharacterByItem(CharacterFromID("Wench3"), "pistol0");
		SetSelectable("ONEUP_BUTTON",false);
		SetSelectable("ALLUP_BUTTON",false);
		SetSelectable("SWAP_BUTTON",false);	//don't take Carolines pocket pistols
	}

	if(itmName1=="pistol20")
	{
		SetSelectable("ONEDOWN_BUTTON",true);	//enable to get rid of the belt
		SetSelectable("ALLDOWN_BUTTON",true);
		SetSelectable("SWAP_BUTTON",false);	//caused problem
	}

	if(itmName2=="pistol20")
	{
		SetSelectable("SWAP_BUTTON",false);	//caused problem
	}

	if(itmName1=="pistol201" || itmName1=="pistol202" || itmName1=="pistol203"|| itmName1=="pistol204" || itmName1=="pistol205" || itmName1=="pistol206")
	{
		//needed now when swap button fix (above) is made?
		SetSelectable("SWAP_BUTTON",false);	//don't get rid of these before belt is found
	}

	if(itmName2=="bladepowderhornP" || itmName2=="bladepowderhornA")
	{
		//firing cannon didn't work after giving, taking with these
		SetSelectable("ONEDOWN_BUTTON",false);
		SetSelectable("ALLDOWN_BUTTON",false);
		SetSelectable("SWAP_BUTTON",false);
	}

	if(Pchar.location == "wr_church_inside" && boxName == "box1")
	{
		if(itmName1=="coin1" || itmName1=="coin2" || itmName1=="coin3"|| itmName1=="coin4" || itmName1=="coin5" || itmName1=="coin6" || itmName1=="coin7"|| itmName1=="coin8"
		|| itmName1=="coin9" || itmName1=="coin10"|| itmName1=="coin11" || itmName1=="coin12" || itmName1=="coin13" || itmName1=="coin14"|| itmName1=="coin15" || itmName1=="coin16")
		{
				//ok
		}
		else
		{
			SetSelectable("ONEDOWN_BUTTON",false);
			SetSelectable("ALLDOWN_BUTTON",false);
			SetSelectable("SWAP_BUTTON",false);
		}
	}

	if(CheckAttribute(Pchar,"quest.take_items") && Pchar.quest.take_items == "no")
	{
		SetSelectable("ONEUP_BUTTON",false);
		SetSelectable("ALLUP_BUTTON",false);
		SetSelectable("SWAP_BUTTON",false);
	}

	if(CheckAttribute(Pchar,"quest.items_transfer") && Pchar.quest.items_transfer == "no")
	{
		SetSelectable("ONEDOWN_BUTTON",false);
		SetSelectable("ALLDOWN_BUTTON",false);
		SetSelectable("ONEUP_BUTTON",false);
		SetSelectable("ALLUP_BUTTON",false);
		SetSelectable("SWAP_BUTTON",false);
	}

	if(itmName1=="detective_kit1" || itmName1=="detective_kit2" || itmName1=="detective_kit3" || itmName1=="detective_kit4" || itmName1=="detective_kit5"
	|| itmName1=="D_feather" || itmName1=="D_scissors" || itmName1=="D_compasses" || itmName1=="D_scalpel" || itmName1=="D_magnifying" || itmName1=="D_tweezers" || itmName1=="D_hairpin"
	|| itmName1=="book55A" || itmName1=="book55B" || itmName1=="book55C" || itmName1=="book55D" || itmName1=="book56" || itmName1=="book57"
	|| itmName1=="book58" || itmName1=="book59" || itmName1=="book60" || itmName1=="bladeA2" || itmName1=="bladeA4" || itmName1=="bladeA5" || itmName1=="bladeA11" || itmName1=="bladeA17")
	{
		SetSelectable("ONEDOWN_BUTTON",false);
		SetSelectable("ALLDOWN_BUTTON",false);
		SetSelectable("SWAP_BUTTON",false);
	}

	if(itmName2=="book56" || itmName2=="book57" || itmName2=="book58" || itmName2=="book59" || itmName2=="book60")
	{
		if(CheckCharacterItem(Pchar,"bladeemptysack_P") || CheckCharacterItem(Pchar,"bladesemifullsack_P"))
		{
			
		}
		else
		{
			SetSelectable("ONEUP_BUTTON",false);
			SetSelectable("ALLUP_BUTTON",false);
			SetSelectable("SWAP_BUTTON",false);
		}
	}

	if(sti(GetStorylineVar(FindCurrentStoryline(), "BUG_PUZZLES")) > 0))
	{
		if(itmName1=="gunpowder" || itmName1=="pistolmtoon")
		{
			SetSelectable("ONEDOWN_BUTTON",false);
			SetSelectable("ALLDOWN_BUTTON",false);
			SetSelectable("SWAP_BUTTON",false);
		}
	}

	if(itmName2 == "mixed_treasure")
	{
		SetSelectable("SWAP_BUTTON",false);
	}
    //<-- JRH

	ThatOneAndEquiped(itmName1,itmName2);

	if(!GetSelectable(GetCurrentNode()))	SetCurrentNode(oldCurScrollName);
}

void SelectButtonLeft(string startBtnNode)
{
	if(GetSelectable(startBtnNode))	SetCurrentNode(startBtnNode);
	else
	{
		switch(startBtnNode)
		{
		case "ONEDOWN_BUTTON":	SelectButtonLeft("INFO_BUTTON"); break;
		case "ONEUP_BUTTON":	SelectButtonLeft("ONEDOWN_BUTTON"); break;
		case "SWAP_BUTTON":		SelectButtonLeft("ONEUP_BUTTON"); break;
		case "ALLUP_BUTTON":	SelectButtonLeft("SWAP_BUTTON"); break;
		case "ALLDOWN_BUTTON":	SelectButtonLeft("ALLUP_BUTTON"); break;
		}
	}
}

void SelectButtonRight(string startBtnNode)
{
	if(GetSelectable(startBtnNode))	SetCurrentNode(startBtnNode);
	else
	{
		switch(startBtnNode)
		{
		case "INFO_BUTTON":		SelectButtonRight("ONEDOWN_BUTTON"); break;
		case "ONEDOWN_BUTTON":	SelectButtonRight("ONEUP_BUTTON"); break;
		case "ONEUP_BUTTON":	SelectButtonRight("SWAP_BUTTON"); break;
		case "SWAP_BUTTON":		SelectButtonRight("ALLUP_BUTTON"); break;
		case "ALLUP_BUTTON":	SelectButtonRight("ALLDOWN_BUTTON"); break;
		}
	}
}

void ThatOneAndEquiped(string itmName1, string itmName2)
{
	ref PChar = GetMainCharacter();
	if( !GetRemovable(g_refItems) )
	{
		SetSelectable("ONEDOWN_BUTTON",false);
		SetSelectable("ALLDOWN_BUTTON",false);
		SetSelectable("SWAP_BUTTON",false);
		SetSelectable("ONEUP_BUTTON",false);
		SetSelectable("ALLUP_BUTTON",false);
		return;
	}

	if( IsEquipCharacterByItem(PChar,itmName1) )
	{
		if( GetCharacterItem(PChar,itmName1)<=1 )
		{
			SetSelectable("ONEDOWN_BUTTON",false);
			SetSelectable("ALLDOWN_BUTTON",false);
			SetSelectable("SWAP_BUTTON",false);
		}
	}

	if( IsEquipCharacterByItem(g_refItems,itmName2) )
	{
		if( GetCharacterItem(g_refItems,itmName2)<=1 )
		{
			SetSelectable("ONEUP_BUTTON",false);
			SetSelectable("ALLUP_BUTTON",false);
			SetSelectable("SWAP_BUTTON",false);
		}
	}
}

void SetScrollsUsing()
{
	if( CheckAttribute(&GameInterface,"two_itemslist.pic1") ) {
		SendMessage(&GameInterface,"lsll", MSG_INTERFACE_MSG_TO_NODE,"TWO_ITEMSLIST",0, true);
		SetSelectable("TWO_ITEMSLIST",true);
		SetSelectable("TWO_LEFTSCROLLBUTTON",true);
		SetSelectable("TWO_RIGHTSCROLLBUTTON",true);
	} else {
		SendMessage(&GameInterface,"lsll", MSG_INTERFACE_MSG_TO_NODE,"TWO_ITEMSLIST",0, false);
		SetSelectable("TWO_ITEMSLIST",false);
		SetSelectable("TWO_LEFTSCROLLBUTTON",false);
		SetSelectable("TWO_RIGHTSCROLLBUTTON",false);
		if( GetCurrentNode()=="TWO_ITEMSLIST" ) {
			SetCurrentNode("ONE_ITEMSLIST");
		}
	}

	if( CheckAttribute(&GameInterface,"one_itemslist.pic1") ) {
		SendMessage(&GameInterface,"lsll", MSG_INTERFACE_MSG_TO_NODE,"ONE_ITEMSLIST",0, true);
		SetSelectable("ONE_ITEMSLIST",true);
		SetSelectable("ONE_LEFTSCROLLBUTTON",true);
		SetSelectable("ONE_RIGHTSCROLLBUTTON",true);
	} else {
		SendMessage(&GameInterface,"lsll", MSG_INTERFACE_MSG_TO_NODE,"ONE_ITEMSLIST",0, false);
		SetSelectable("ONE_ITEMSLIST",false);
		SetSelectable("ONE_LEFTSCROLLBUTTON",false);
		SetSelectable("ONE_RIGHTSCROLLBUTTON",false);
		if( GetCurrentNode()=="ONE_ITEMSLIST" ) {
			if( GetSelectable("TWO_ITEMSLIST") ) {SetCurrentNode("TWO_ITEMSLIST");}
		}
	}
}

void GoToTopScroll()
{
	if( GetSelectable("ONE_ITEMSLIST") ) SetCurrentNode("ONE_ITEMSLIST");
}

void GoToBottomScroll()
{
	if( GetSelectable("TWO_ITEMSLIST") ) SetCurrentNode("TWO_ITEMSLIST");
}

// KK -->
void ShowDescription(string sNode)
{
	string itmname, itmdescr, picStr, texStr;
	int iScroll = sti(GetSymbol(sNode, 5));
	int iRect = sti(strcut(sNode, 7, strlen(sNode) - 1));
	GetDescribeData(iScroll, iRect, &itmname, &itmdescr, &picStr, &texStr);
	if (itmname == "" && itmdescr == "") return;
	SetToolTipRectangle("");
	SetToolTipHeader("", itmname);
	SetToolTipText("", itmdescr);
	SetToolTipPicture("", texStr, picStr);
	ShowToolTip();
}

void SetImageGroups()
{
	aref arImgGrp, arItem;
	makearef(arImgGrp, GameInterface.one_itemslist.ImagesGroup);
	int iNum = GetAttributesNum(arImgGrp);
	for (int i = 0; i < iNum; i++)
	{
		arItem = GetAttributeN(arImgGrp, i);
		AddToolTipPictureImageGroup(GetAttributeValue(arItem));
	}
	makearef(arImgGrp, GameInterface.two_itemslist.ImagesGroup);
	iNum = GetAttributesNum(arImgGrp);
	for (i = 0; i < iNum; i++)
	{
		arItem = GetAttributeN(arImgGrp, i);
		AddToolTipPictureImageGroup(GetAttributeValue(arItem));
	}
}
// <-- KK
