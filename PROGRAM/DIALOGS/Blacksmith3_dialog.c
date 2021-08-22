/*
* Blacksmith3_dialog.c
* By RobC (robertcook@piratehideout.com)
* (This version adapted by Alan_Smithee [monkeydog_x@yahoo.com])
* Contains all logic for the dialog between
* the main character and a blacksmith.
* Based on the Gregor Samsa files.
* PB: Change this blacksmith into the only gunsmith
*/

void ProcessDialogEvent()
{
	int i,j;
	int GunQuantity;
	int GunCount;

	aref curItem;
	aref arItem;
	aref rootItems;

	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	// Create a reference to the main character
	ref MainChar;
	MainChar = GetMainCharacter();
	makearef(rootItems,MainChar.Items);

	// Clean up the dialog links (start fresh)
	DeleteAttribute(&Dialog,"Links");

	// Create a reference to the dialog links
	aref Link;
	makearef(Link, Dialog.Links);

	// Create a reference to the NPC
	ref NPChar;
	makeref(NPChar, CharacterRef);

	// Create a reference to the NPC's dialog
	aref NPCDialog;
	makearef(NPCDialog, NPChar.Dialog);

	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;

	// Get the main character's gun and the gun's base ID
	string GunID = MainChar.equip.gun;
	string GunBaseID;
	if (findSubStr(&GunID, "+", 0) > -1 || findSubStr(&GunID, "-", 0) > -1)
	GunBaseID = strcut(&GunID, 0, strlen(GunID) - 3);
	else
	GunBaseID = GunID;
	string PlayerEquipGun = GunBaseID; // PB

	// Get the player's money (as int)
	int PlayerMoney;
	int RepairCost;

	if (BLACKSMITH_PAY_OUT_WEALTH == 1) // PB: Toggle blacksmith payment in BS.h
	{PlayerMoney = sti(MainChar.wealth);}
	else
	{PlayerMoney = sti(MainChar.money);}
	if(!CheckAttribute(NPChar, "quest.item_date")) NPChar.quest.item_date = NPChar.quest.meeting;

	// Set blacksmith's price multiplier
	float pricemult = 1.0/90.0;
	
	Preprocessor_Add("sir", GetMyAddressForm(NPChar, MainChar, ADDR_POLITE, false, false)); // DeathDaisy

	// Dialog.CurrentNode holds a value indicating where in the conversation we are,
	// according to that value we will determine where to go next.
	switch(Dialog.CurrentNode)
	{
		// Exit from the dialog
	case "exit":
		NPCDialog.CurrentNode = NPCDialog.TempNode; // NK
		DialogExit();
		break;


		// The first time the player talks to the character
	case "First time":
		Dialog.defAni = "dialog_stay1";
		Dialog.defCam = "1";
		Dialog.defSnd = "dialogs\0\017";
		Dialog.defLinkAni = "dialog_1";
		Dialog.defLinkCam = "1";
		Dialog.defLinkSnd = "dialogs\woman\024";
		Dialog.ani = "dialog_stay2";
		Dialog.cam = "1";
		Dialog.snd = "dialogs\0\009";

		Dialog.text = DLG_TEXT[0];
		link.l1 = DLG_TEXT[1];
		link.l1.go = "Introduction";
		break;

		// Blacksmith tells the main char about his trade (and use in the game)
	case "Introduction":
		NPCDialog.TempNode = "SelectFix"; // NK
		Dialog.text = DLG_TEXT[2];
		link.l1 = DLG_TEXT[3];
		link.l1.go = "SelectFix";
		link.l2 = DLG_TEXT[4];
		link.l2.go = "exit";
		break;


		// Blacksmith asks whether or not the current weapon should be fixed
	case "SelectFix":
		GunID = "";
		bool needexit = true;
		if(CheckAttribute(MainChar, "equip.gun")) GunID = MainChar.equip.gun;

			if (GunID != "")
			{
				// Retrieve gun name, gun quality, and upgrade prices
				string GunName   = GetItemNameByID(GunID);
				int GunQuality   = GetItemQualityByID(GunID);
				if(GunQuality >= 0 ) // NK check has quality
				{
					int PriceExcellent = GetItemUpgradePrice(GunID, GunQuality, QUALITY_EXELLENT, pricemult);
					int PriceFine      = GetItemUpgradePrice(GunID, GunQuality, QUALITY_FINE, pricemult);
					int PriceGood      = GetItemUpgradePrice(GunID, GunQuality, QUALITY_GOOD, pricemult);
					int PriceAverage   = GetItemUpgradePrice(GunID, GunQuality, QUALITY_AVERAGE, pricemult);
					needexit = false;
					// Build the dialog according to the values retrieved above
					switch (GunQuality)
					{
						// For a badly worn gun, show Excellent, Fine, Good and Average
						// (if the player has enough money that is)
					case QUALITY_BADLYWORN:
						Dialog.text = DLG_TEXT[5] + GunName + DLG_TEXT[6];
						if (PriceExcellent <= PlayerMoney)
						{
							link.l1 = DLG_TEXT[17] + PriceExcellent + ".";
							link.l1.go = "MakeExcellent";
						}
						if (PriceFine <= PlayerMoney)
						{
							link.l2 = DLG_TEXT[18] + PriceFine + ".";
							link.l2.go = "MakeFine";
						}
						if (PriceGood <= PlayerMoney)
						{
							link.l3 = DLG_TEXT[19] + PriceGood + ".";
							link.l3.go = "MakeGood";
						}
						if (PriceAverage <= PlayerMoney)
						{
							link.l4 = DLG_TEXT[20] + PriceAverage + ".";
							link.l4.go = "MakeAverage";
						}
						link.l5 = DLG_TEXT[22];
						link.l5.go = "exit";
						break;

						// Same goes for worn as goes for badly worn
					case QUALITY_WORN:
						Dialog.text = DLG_TEXT[7] + GunName + DLG_TEXT[8];
						if (PriceExcellent <= PlayerMoney)
						{
							link.l1 = DLG_TEXT[17] + PriceExcellent + ".";
							link.l1.go = "MakeExcellent";
						}
						if (PriceFine <= PlayerMoney)
						{
							link.l2 = DLG_TEXT[18] + PriceFine + ".";
							link.l2.go = "MakeFine";
						}
						if (PriceGood <= PlayerMoney)
						{
							link.l3 = DLG_TEXT[19] + PriceGood + ".";
							link.l3.go = "MakeGood";
						}
						if (PriceAverage <= PlayerMoney)
						{
							link.l4 = DLG_TEXT[20] + PriceAverage + ".";
							link.l4.go = "MakeAverage";
						}
						link.l5 = DLG_TEXT[22];
						link.l5.go = "exit";
						break;

						// If the gun is average, show excellent, fine and good
					case QUALITY_AVERAGE:
						Dialog.text = DLG_TEXT[9] + GunName + DLG_TEXT[10];
						if (PriceExcellent <= PlayerMoney)
						{
							link.l1 = DLG_TEXT[17] + PriceExcellent + ".";
							link.l1.go = "MakeExcellent";
						}
						if (PriceFine <= PlayerMoney)
						{
							link.l2 = DLG_TEXT[18] + PriceFine + ".";
							link.l2.go = "MakeFine";
						}
						if (PriceGood <= PlayerMoney)
						{
							link.l3 = DLG_TEXT[19] + PriceGood + ".";
							link.l3.go = "MakeGood";
						}
						link.l4 = DLG_TEXT[22];
						link.l4.go = "exit";
						break;

						// If the gun is good, show excellent and fine
					case QUALITY_GOOD:
						Dialog.text = DLG_TEXT[11] + GunName + DLG_TEXT[12];
						if (PriceExcellent <= PlayerMoney)
						{
							link.l1 = DLG_TEXT[17] + PriceExcellent + ".";
							link.l1.go = "MakeExcellent";
						}
						if (PriceFine <= PlayerMoney)
						{
							link.l2 = DLG_TEXT[18] + PriceFine + ".";
							link.l2.go = "MakeFine";
						}
						link.l3 = DLG_TEXT[22];
						link.l3.go = "exit";
						break;

						// If the gun is fine, show only excellent
					case QUALITY_FINE:
						Dialog.text = DLG_TEXT[13] + GunName + DLG_TEXT[14];
						if (PriceExcellent <= PlayerMoney)
						{
							link.l1 = DLG_TEXT[17] + PriceExcellent + ".";
							link.l1.go = "MakeExcellent";
						}
						link.l2 = DLG_TEXT[22];
						link.l2.go = "exit";
						break;

						// If the gun is excellent, refuse to repair (as there is nothing to repair...)
					case QUALITY_EXELLENT:
						Dialog.text = DLG_TEXT[15] + GunName + ", " + GetMyAddressForm(NPChar, MainChar, ADDR_POLITE, false, false) + DLG_TEXT[16];
						link.l1 = DLG_TEXT[34];
						link.l1.go = "exit";
						break;
					}
				}
			}
		link.l94 = DLG_TEXT[28];
		link.l94.go = "RepairAllGuns";
		// NK -->
		Link.l95 = DLG_TEXT[26];
		Link.l95.go = "itemstrade";
		if(needexit) // NK bugfix 05-05-11
		{
			Dialog.text = GetMyAddressForm(NPChar, MainChar, ADDR_POLITE, false, false) + DLG_TEXT[25];
			link.l99 = DLG_TEXT[21];
			link.l99.go = "exit";
		}
		break;

	case "RepairAllGuns":
		Dialog.text = DLG_TEXT[29];

		PriceExcellent = 0;
		PriceFine = 0;
		PriceGood = 0;
		PriceAverage = 0;

		for(i=0;i<GetAttributesNum(rootItems);i++)
		{
			curItem = GetAttributeN(rootItems,i);
			if( Items_FindItem(GetAttributeName(curItem),&arItem)>=0 )
			{
				if (CheckAttribute(arItem, "groupID") == true && arItem.groupID == GUN_ITEM_TYPE)
				{
					GunQuality   = GetItemQualityByID(arItem.id);
					GunQuantity  = sti(GetAttributeValue(curItem));
					if(GunQuality >= 0 && GunQuantity > 0) // NK check has quality
					{
						PriceExcellent += sti(GetItemUpgradePrice(arItem.id, GunQuality, QUALITY_EXELLENT, pricemult))*GunQuantity;
						PriceFine      += sti(GetItemUpgradePrice(arItem.id, GunQuality, QUALITY_FINE, pricemult))*GunQuantity;
						PriceGood      += sti(GetItemUpgradePrice(arItem.id, GunQuality, QUALITY_GOOD, pricemult))*GunQuantity;
						PriceAverage   += sti(GetItemUpgradePrice(arItem.id, GunQuality, QUALITY_AVERAGE, pricemult))*GunQuantity;
					}
				}
			}
		}
		if (PriceAverage <= PlayerMoney && PriceAverage >0)
		{
			link.l1 = DLG_TEXT[30]+PriceAverage+DLG_TEXT[27];
			link.l1.go = "MakeAllAverage";
		}
		if (PriceGood <= PlayerMoney && PriceGood >0)
		{
			link.l2 = DLG_TEXT[31]+PriceGood+DLG_TEXT[27];
			link.l2.go = "MakeAllGood";
		}
		if (PriceFine <= PlayerMoney && PriceFine >0)
		{
			link.l3 = DLG_TEXT[32]+PriceFine+DLG_TEXT[27];
			link.l3.go = "MakeAllFine";
		}
		if (PriceExcellent <= PlayerMoney && PriceExcellent >0)
		{
			link.l4 = DLG_TEXT[36]+PriceExcellent+DLG_TEXT[27];
			link.l4.go = "MakeAllExcellent";
		}
		if (PriceAverage <=0 && PriceGood <=0 && PriceFine <=0 && PriceExcellent <=0)
		{
			Dialog.text = DLG_TEXT[33];
			link.l5 = DLG_TEXT[34];
			link.l5.go = "exit";
		}
		else
		{
			link.l95 = DLG_TEXT[22];
			link.l95.go = "exit";
		}
		break;

	case "MakeAllAverage":
		Dialog.text = DLG_TEXT[23];
		PriceAverage = 0;
		GunCount = 0;
		for(i=0;i<GetAttributesNum(rootItems);i++)
		{
			curItem = GetAttributeN(rootItems,i);
			if( Items_FindItem(GetAttributeName(curItem),&arItem)>=0 )
			{
				if (CheckAttribute(arItem, "groupID") == true && arItem.groupID == GUN_ITEM_TYPE)
				{
					GunID = arItem.id;
					if (findSubStr(&GunID, "+", 0) > -1 || findSubStr(&GunID, "-", 0) > -1)
					{
						GunBaseID = strcut(&GunID, 0, strlen(GunID) - 3);
					}
					else
					{
						GunBaseID = GunID;
					}
					GunQuality   = GetItemQualityByID(arItem.id);
					GunQuantity  = sti(GetAttributeValue(curItem));
					if(GunQuality >= 0 && GunQuality < 2 && GunQuantity > 0) // NK check has quality
					{
						PriceAverage   += sti(GetItemUpgradePrice(arItem.id, GunQuality, QUALITY_AVERAGE, pricemult))*GunQuantity;
						for(j=0;j<GunQuantity;j++)
						{
							GiveItem2Character(MainChar, GunBaseID);
							if(GunBaseID == PlayerEquipGun) EquipCharacterByItem(MainChar, GunBaseID); // PB
							GunCount++;
						}
					}
				}
			}
		}
		for(i=0;i<GetAttributesNum(rootItems);i++)
		{
			curItem = GetAttributeN(rootItems,i);
			if (sti(GetAttributeValue(curItem))<=0 ) continue;
			if( Items_FindItem(GetAttributeName(curItem),&arItem)>=0 )
			{
				if (CheckAttribute(arItem, "groupID"))
				{
					if(arItem.groupID == GUN_ITEM_TYPE)

					{
						GunID = arItem.id;
						GunQuality   = GetItemQualityByID(arItem.id);
						GunQuantity  = sti(GetAttributeValue(curItem));
						if(GunQuality >= 0 && GunQuality < 2 && GunQuantity > 0) // NK check has quality
						{
							for(j=0;j<GunQuantity;j++)
							{
								TakeItemFromCharacter(MainChar, GunID);
							}
							i--;
						}
					}
				}
			}
		}
		MainChar.money = sti(MainChar.money) - PriceAverage;

		link.l95 = DLG_TEXT[24];
		link.l95.go = "exit";

		LogIt(GunCount+" hours pass until the work is completed and you receive the guns back.");
		WaitDate("", 0, 0, 0, GunCount, 0);
		break;

	case "MakeAllGood":
		Dialog.text = DLG_TEXT[23];
		PriceGood = 0;
		GunCount = 0;
		for(i=0;i<GetAttributesNum(rootItems);i++)
		{
			curItem = GetAttributeN(rootItems,i);
			if( Items_FindItem(GetAttributeName(curItem),&arItem)>=0 )
			{
				if (CheckAttribute(arItem, "groupID") == true && arItem.groupID == GUN_ITEM_TYPE)
				{
					GunID = arItem.id;
					if (findSubStr(&GunID, "+", 0) > -1 || findSubStr(&GunID, "-", 0) > -1)
					{
						GunBaseID = strcut(&GunID, 0, strlen(GunID) - 3);
					}
					else
					{
						GunBaseID = GunID;
					}
					GunQuality   = GetItemQualityByID(arItem.id);
					GunQuantity  = sti(GetAttributeValue(curItem));
					if(GunQuality >= 0 && GunQuality < 3 && GunQuantity > 0) // NK check has quality
					{
						PriceGood   += sti(GetItemUpgradePrice(arItem.id, GunQuality, QUALITY_GOOD, pricemult))*GunQuantity;
						for(j=0;j<GunQuantity;j++)
						{
							GiveItem2Character(MainChar, GunBaseID+"+1");
							if(GunBaseID == PlayerEquipGun)	EquipCharacterByItem(MainChar, GunBaseID+"+1"); // PB
							GunCount++;
						}
					}
				}
			}
		}
		for(i=0;i<GetAttributesNum(rootItems);i++)
		{
			curItem = GetAttributeN(rootItems,i);
			if (sti(GetAttributeValue(curItem))<=0 ) continue;
			if( Items_FindItem(GetAttributeName(curItem),&arItem)>=0 )
			{
				if (CheckAttribute(arItem, "groupID"))
				{
					if(arItem.groupID == GUN_ITEM_TYPE)

					{
						GunID = arItem.id;
						GunQuality   = GetItemQualityByID(arItem.id);
						GunQuantity  = sti(GetAttributeValue(curItem));
						if(GunQuality >= 0 && GunQuality < 3 && GunQuantity > 0) // NK check has quality
						{
							for(j=0;j<GunQuantity;j++)
							{
								TakeItemFromCharacter(MainChar, GunID);
							}
							i--;
						}
					}
				}
			}
		}
		MainChar.money = sti(MainChar.money) - PriceGood;

		link.l95 = DLG_TEXT[24];
		link.l95.go = "exit";

		LogIt(GunCount+" hours pass until the work is completed and you receive the guns back.");
		WaitDate("", 0, 0, 0, GunCount, 0);

		break;

	case "MakeAllFine":
		Dialog.text = DLG_TEXT[23];
		PriceFine = 0;
		GunCount = 0;
		for(i=0;i<GetAttributesNum(rootItems);i++)
		{
			curItem = GetAttributeN(rootItems,i);
			if( Items_FindItem(GetAttributeName(curItem),&arItem)>=0 )
			{
				if (CheckAttribute(arItem, "groupID") == true && arItem.groupID == GUN_ITEM_TYPE)
				{
					GunID = arItem.id;
					if (findSubStr(&GunID, "+", 0) > -1 || findSubStr(&GunID, "-", 0) > -1)
					{
						GunBaseID = strcut(&GunID, 0, strlen(GunID) - 3);
					}
					else
					{
						GunBaseID = GunID;
					}
					GunQuality   = GetItemQualityByID(arItem.id);
					GunQuantity  = sti(GetAttributeValue(curItem));
					if(GunQuality >= 0 && GunQuality < 4 && GunQuantity > 0) // NK check has quality
					{
						PriceFine   += sti(GetItemUpgradePrice(arItem.id, GunQuality, QUALITY_FINE, pricemult))*GunQuantity;
						for(j=0;j<GunQuantity;j++)
						{
							GiveItem2Character(MainChar, GunBaseID+"+2");
							if(GunBaseID == PlayerEquipGun)	EquipCharacterByItem(MainChar, GunBaseID+"+2"); // PB
							GunCount++;
						}
					}
				}
			}
		}
		for(i=0;i<GetAttributesNum(rootItems);i++)
		{
			curItem = GetAttributeN(rootItems,i);
			if (sti(GetAttributeValue(curItem))<=0 ) continue;
			if( Items_FindItem(GetAttributeName(curItem),&arItem)>=0 )
			{
				if (CheckAttribute(arItem, "groupID"))
				{
					if(arItem.groupID == GUN_ITEM_TYPE)

					{
						GunID = arItem.id;
						GunQuality   = GetItemQualityByID(arItem.id);
						GunQuantity  = sti(GetAttributeValue(curItem));
						if(GunQuality >= 0 && GunQuality < 4 && GunQuantity > 0) // NK check has quality
						{
							for(j=0;j<GunQuantity;j++)
							{
								TakeItemFromCharacter(MainChar, GunID);
							}
							i--;
						}
					}
				}
			}
		}
		MainChar.money = sti(MainChar.money) - PriceFine;

		link.l95 = DLG_TEXT[24];
		link.l95.go = "exit";

		LogIt(GunCount+" hours pass until the work is completed and you receive the guns back.");
		WaitDate("", 0, 0, 0, GunCount, 0);

		break;

	case "MakeAllExcellent":
		Dialog.text = DLG_TEXT[23];
		PriceExcellent = 0;
		GunCount = 0;
		for(i=0;i<GetAttributesNum(rootItems);i++)
		{
			curItem = GetAttributeN(rootItems,i);
			if( Items_FindItem(GetAttributeName(curItem),&arItem)>=0 )
			{
				if (CheckAttribute(arItem, "groupID") == true && arItem.groupID == GUN_ITEM_TYPE)
				{
					GunID = arItem.id;
					if (findSubStr(&GunID, "+", 0) > -1 || findSubStr(&GunID, "-", 0) > -1)
					{
						GunBaseID = strcut(&GunID, 0, strlen(GunID) - 3);
					}
					else
					{
						GunBaseID = GunID;
					}
					GunQuality   = GetItemQualityByID(arItem.id);
					GunQuantity  = sti(GetAttributeValue(curItem));
					if(GunQuality >= 0 && GunQuality < 5 && GunQuantity > 0) // NK check has quality
					{
						PriceExcellent   += sti(GetItemUpgradePrice(arItem.id, GunQuality, QUALITY_EXELLENT, pricemult))*GunQuantity;
						for(j=0;j<GunQuantity;j++)
						{
							GiveItem2Character(MainChar, GunBaseID+"+3");
							if(GunBaseID == PlayerEquipGun)	EquipCharacterByItem(MainChar, GunBaseID+"+3"); // PB
							GunCount++;
						}
					}
				}
			}
		}
		for(i=0;i<GetAttributesNum(rootItems);i++)
		{
			curItem = GetAttributeN(rootItems,i);
			if (sti(GetAttributeValue(curItem))<=0 ) continue;
			if( Items_FindItem(GetAttributeName(curItem),&arItem)>=0 )
			{
				if (CheckAttribute(arItem, "groupID"))
				{
					if(arItem.groupID == GUN_ITEM_TYPE)

					{
						GunID = arItem.id;
						GunQuality   = GetItemQualityByID(arItem.id);
						GunQuantity  = sti(GetAttributeValue(curItem));
						if(GunQuality >= 0 && GunQuality < 5 && GunQuantity > 0) // NK check has quality
						{
							for(j=0;j<GunQuantity;j++)
							{
								TakeItemFromCharacter(MainChar, GunID);
							}
							i--;
						}
					}
				}
			}
		}
		MainChar.money = sti(MainChar.money) - PriceExcellent;

		link.l95 = DLG_TEXT[24];
		link.l95.go = "exit";

		LogIt(GunCount+" hours pass until the work is completed and you receive the guns back.");
		WaitDate("", 0, 0, 0, GunCount, 0);

		break;

	case "itemstrade":
		if(NPChar.quest.item_date != lastspeak_date)
		{
			GiveItemToTrader(NPChar);
			NPChar.quest.item_date = lastspeak_date;
		}
		NPCDialog.CurrentNode = NPCDialog.TempNode;
		DialogExit();
		LaunchItemsTrade(NPChar);
		// NK <--
		break;


		// Repair the player's gun to the excellent state
	case "MakeExcellent":

		// Unequip and remove player's current gun
		RemoveCharacterEquip(MainChar, GUN_ITEM_TYPE);
		TakeItemFromCharacter(MainChar, GunID);

		// Make the player pay
		RepairCost = makeint(GetItemUpgradePrice(GunID, GetItemQualityByID(GunID), QUALITY_EXELLENT, pricemult));
		AddMoneyToCharacter(NPChar,RepairCost); // PB: Blacksmith Gets Paid
		PlayerMoney -= RepairCost;
		// ccc added makeint cause you can't calc with strings :)
		if (BLACKSMITH_PAY_OUT_WEALTH == 1) // PB: Toggle blacksmith payment in BS.h
		{MainChar.wealth = PlayerMoney;}
		else
		{MainChar.money = PlayerMoney;}

		// Wait a day
		WaitDate("", 0, 0, 1, 0, 0);
		Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"You get your gun back one day later."));

		// Give and equip excellent version of the gun
		GiveItem2Character(MainChar, GunBaseID + "+3");
		EquipCharacterByItem(MainChar, GunBaseID + "+3");

		Dialog.text = DLG_TEXT[23];
		link.l1 = DLG_TEXT[24];
		link.l1.go = "exit";
		break;


		// Repair the player's gun to the fine state
	case "MakeFine":

		// Unequip and remove player's current gun
		RemoveCharacterEquip(MainChar, GUN_ITEM_TYPE);
		TakeItemFromCharacter(MainChar, GunID);

		// Make the player pay
		RepairCost = makeint(GetItemUpgradePrice(GunID, GetItemQualityByID(GunID), QUALITY_FINE, pricemult));
		AddMoneyToCharacter(NPChar,RepairCost); // PB: Blacksmith Gets Paid
		PlayerMoney -= RepairCost;
		// ccc added makeint cause you can't calc with strings :)
		if (BLACKSMITH_PAY_OUT_WEALTH == 1) // PB: Toggle blacksmith payment in BS.h
		{MainChar.wealth = PlayerMoney;}
		else
		{MainChar.money = PlayerMoney;}

		// Wait a day
		WaitDate("", 0, 0, 1, 0, 0);
		Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"You get your gun back one day later."));

		// Give and equip excellent version of the gun
		GiveItem2Character(MainChar, GunBaseID + "+2");
		EquipCharacterByItem(MainChar, GunBaseID + "+2");

		Dialog.text = DLG_TEXT[23];
		link.l1 = DLG_TEXT[24];
		link.l1.go = "exit";
		break;


		// Repair the player's gun to the good state
	case "MakeGood":

		// Unequip and remove player's current gun
		RemoveCharacterEquip(MainChar, GUN_ITEM_TYPE);
		TakeItemFromCharacter(MainChar, GunID);

		// Make the player pay
		RepairCost = makeint(GetItemUpgradePrice(GunID, GetItemQualityByID(GunID), QUALITY_GOOD, pricemult));
		AddMoneyToCharacter(NPChar,RepairCost); // PB: Blacksmith Gets Paid
		PlayerMoney -= RepairCost;
		// ccc added makeint cause you can't calc with strings :)
		if (BLACKSMITH_PAY_OUT_WEALTH == 1) // PB: Toggle blacksmith payment in BS.h
		{MainChar.wealth = PlayerMoney;}
		else
		{MainChar.money = PlayerMoney;}

		// Wait a day
		WaitDate("", 0, 0, 1, 0, 0);
		Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"You get your gun back one day later."));

		// Give and equip excellent version of the gun
		GiveItem2Character(MainChar, GunBaseID + "+1");
		EquipCharacterByItem(MainChar, GunBaseID + "+1");

		Dialog.text = DLG_TEXT[23];
		link.l1 = DLG_TEXT[24];
		link.l1.go = "exit";
		break;


		// Repair the player's gun to the average state
	case "MakeAverage":

		// Unequip and remove player's current gun
		RemoveCharacterEquip(MainChar, GUN_ITEM_TYPE);
		TakeItemFromCharacter(MainChar, GunID);

		// Make the player pay
		RepairCost = makeint(GetItemUpgradePrice(GunID, GetItemQualityByID(GunID), QUALITY_AVERAGE, pricemult));
		AddMoneyToCharacter(NPChar,RepairCost); // PB: Blacksmith Gets Paid
		PlayerMoney -= RepairCost;
		// ccc added makeint cause you can't calc with strings :)
		if (BLACKSMITH_PAY_OUT_WEALTH == 1) // PB: Toggle blacksmith payment in BS.h
		{MainChar.wealth = PlayerMoney;}
		else
		{MainChar.money = PlayerMoney;}

		// Wait a day
		WaitDate("", 0, 0, 1, 0, 0);
		Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"You get your gun back one day later."));

		// Give and equip excellent version of the gun
		GiveItem2Character(MainChar, GunBaseID);
		EquipCharacterByItem(MainChar, GunBaseID);

		Dialog.text = DLG_TEXT[23];
		link.l1 = DLG_TEXT[24];
		link.l1.go = "exit";
		break;
	}
	LanguageCloseFile(tmpLangFileID);
}
