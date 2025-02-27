/*
* Gunsmith_dialog.c
* By RobC (robertcook@piratehideout.com)
* (This version adapted by Alan_Smithee [monkeydog_x@yahoo.com])
* Contains all logic for the dialog between
* the main character and a blacksmith.
* Based on the Gregor Samsa files.
*/


void ProcessDialogEvent()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	// Create a reference to the main character
	ref MainChar;
	MainChar = GetMainCharacter();

	// Clean up the dialog links (start fresh)
	DeleteAttribute(&Dialog,"Links");

	// Create a reference to the dialog links
	aref Link;
	makearef(Link, Dialog.Links);

	// Create a reference to the NPC
	ref NPCChar;
	makeref(NPCChar, CharacterRef);

	// Create a reference to the NPC's dialog
	aref NPCDialog;
	makearef(NPCDialog, NPCChar.Dialog);

	// Set blacksmith's price multiplier
	float pricemult = 1.0/100.0;

	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;

	// Get the main character's blade and the blade's base ID
	string BladeID = ""; if(CheckAttribute(MainChar, "equip.blade")) BladeID = MainChar.equip.blade;
	string GunID = ""; if(CheckAttribute(MainChar, "equip.gun")) GunID = MainChar.equip.gun;
	string BladeBaseID;
	string GunBaseID;
	if (findSubStr(&BladeID, "+", 0) > -1 || findSubStr(&BladeID, "-", 0) > -1)
	BladeBaseID = strcut(&BladeID, 0, strlen(BladeID) - 3);
	else
	BladeBaseID = BladeID;

	if (findSubStr(&GunID, "+", 0) > -1 || findSubStr(&GunID, "-", 0) > -1)
	GunBaseID = strcut(&GunID, 0, strlen(GunID) - 3);
	else
	GunBaseID = GunID;

	// Get the player's money (as int)
	int PlayerMoney;

	if (BLACKSMITH_PAY_OUT_WEALTH == 1) // PB: Toggle blacksmith payment in BS.h
	{PlayerMoney = sti(MainChar.wealth);}
	else
	{PlayerMoney = sti(MainChar.money);}

	// Dialog.CurrentNode holds a value indicating where in the conversation we are,
	// according to that value we will determine where to go next.
	switch(Dialog.CurrentNode)
	{
		// Exit from the dialog
	case "exit":
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
		NPCDialog.CurrentNode = "SelectFix";
		Dialog.text = DLG_TEXT[2] + GetMyAddressForm(NPCChar, MainChar, ADDR_POLITE, false, false) + DLG_TEXT[3];
		link.l1 = DLG_TEXT[4];
		link.l1.go = "SelectFix";
		link.l2 = DLG_TEXT[5];
		link.l2.go = "exit";
		break;

	case "SelectFix":
		Dialog.text = DLG_TEXT[6];
		link.l1 = DLG_TEXT[7];
		link.l1.go = "BladeSelectFix";
		link.l2 = DLG_TEXT[8];
		link.l2.go = "GunSelectFix";
		link.l99 = DLG_TEXT[9];
		link.l99.go = "exit";
		break;


		// Blacksmith asks whether or not the current blade should be fixed
	case "BladeSelectFix":
		bool bneedexit = true;
		BladeID = "";
		if(CheckAttribute(MainChar, "equip.blade")) BladeID = MainChar.equip.blade;

		if(HasSubStr(BladeID,"halberd"))		//JRH
		{
			bneedexit = false;
			Dialog.text = DLG_TEXT[10];
			link.l100 = DLG_TEXT[11];
			link.l100.go = "exit";
		}
		else
		{
			if (BladeID != "")
			{
				// Retrieve blade name, blade quality, and upgrade prices
				string BladeName   = GetItemNameByID(BladeID);
				int BladeQuality   = GetItemQualityByID(BladeID);
				if(BladeQuality >= 0 ) // NK check has quality
				{
				int PriceBladeExcellent = GetItemUpgradePrice(BladeID, BladeQuality, QUALITY_EXELLENT, pricemult);
				int PriceBladeFine      = GetItemUpgradePrice(BladeID, BladeQuality, QUALITY_FINE, pricemult);
				int PriceBladeGood      = GetItemUpgradePrice(BladeID, BladeQuality, QUALITY_GOOD, pricemult);
				int PriceBladeAverage   = GetItemUpgradePrice(BladeID, BladeQuality, QUALITY_AVERAGE, pricemult);
				bneedexit = false;
				// Build the dialog according to the values retrieved above
				switch (BladeQuality)
				{
					// For a badly worn blade, show Excellent, Fine, Good and Average
					// (if the player has enough money that is)
				case QUALITY_BADLYWORN:
					Dialog.text = DLG_TEXT[12] + BladeName + DLG_TEXT[13];
					if (PriceBladeExcellent <= PlayerMoney)
					{
						link.l1 = DLG_TEXT[14] + PriceBladeExcellent;;
						link.l1.go = "BladeMakeExcellent";
					}
					if (PriceBladeFine <= PlayerMoney)
					{
						link.l2 = DLG_TEXT[15] + PriceBladeFine;;
						link.l2.go = "BladeMakeFine";
					}
					if (PriceBladeGood <= PlayerMoney)
					{
						link.l3 = DLG_TEXT[16] + PriceBladeGood;;
						link.l3.go = "BladeMakeGood";
					}
					if (PriceBladeAverage <= PlayerMoney)
					{
						link.l4 = DLG_TEXT[17] + PriceBladeAverage;;
						link.l4.go = "BladeMakeAverage";
					}
					link.l5 = DLG_TEXT[18];
					link.l5.go = "exit";
					break;

					// Same goes for worn as goes for badly worn
				case QUALITY_WORN:
					Dialog.text = DLG_TEXT[19] + BladeName + DLG_TEXT[20];
					if (PriceBladeExcellent <= PlayerMoney)
					{
						link.l1 = DLG_TEXT[21] + PriceBladeExcellent;;
						link.l1.go = "BladeMakeExcellent";
					}
					if (PriceBladeFine <= PlayerMoney)
					{
						link.l2 = DLG_TEXT[22] + PriceBladeFine;;
						link.l2.go = "BladeMakeFine";
					}
					if (PriceBladeGood <= PlayerMoney)
					{
						link.l3 = DLG_TEXT[23] + PriceBladeGood;;
						link.l3.go = "BladeMakeGood";
					}
					if (PriceBladeAverage <= PlayerMoney)
					{
						link.l4 = DLG_TEXT[24] + PriceBladeAverage;;
						link.l4.go = "BladeMakeAverage";
					}
					link.l5 = DLG_TEXT[25];
					link.l5.go = "exit";
					break;

					// If the blade is average, show excellent, fine and good
				case QUALITY_AVERAGE:
					Dialog.text = DLG_TEXT[26] + BladeName + DLG_TEXT[27];
					if (PriceBladeExcellent <= PlayerMoney)
					{
						link.l1 = DLG_TEXT[28] + PriceBladeExcellent;;
						link.l1.go = "BladeMakeExcellent";
					}
					if (PriceBladeFine <= PlayerMoney)
					{
						link.l2 = DLG_TEXT[29] + PriceBladeFine;;
						link.l2.go = "BladeMakeFine";
					}
					if (PriceBladeGood <= PlayerMoney)
					{
						link.l3 = DLG_TEXT[30] + PriceBladeGood;;
						link.l3.go = "BladeMakeGood";
					}
					link.l4 = DLG_TEXT[31];
					link.l4.go = "exit";
					break;

					// If the blade is good, show excellent and fine
				case QUALITY_GOOD:
					Dialog.text = DLG_TEXT[32] + BladeName + DLG_TEXT[33];
					if (PriceBladeExcellent <= PlayerMoney)
					{
						link.l1 = DLG_TEXT[34] + PriceBladeExcellent;;
						link.l1.go = "BladeMakeExcellent";
					}
					if (PriceBladeFine <= PlayerMoney)
					{
						link.l2 = DLG_TEXT[35] + PriceBladeFine;;
						link.l2.go = "BladeMakeFine";
					}
					link.l3 = DLG_TEXT[36];
					link.l3.go = "exit";
					break;

					// If the blade is fine, show only excellent
				case QUALITY_FINE:
					Dialog.text = DLG_TEXT[37] + BladeName + DLG_TEXT[38];
					if (PriceBladeExcellent <= PlayerMoney)
					{
						link.l1 = DLG_TEXT[39] + PriceBladeExcellent;;
						link.l1.go = "BladeMakeExcellent";
					}
					link.l2 = DLG_TEXT[40];
					link.l2.go = "exit";
					break;

					// If the blade is excellent, refuse to repair (as there is nothing to repair...)
				case QUALITY_EXELLENT:
					Dialog.text = DLG_TEXT[41] + BladeName + DLG_TEXT[42];
					link.l1 = DLG_TEXT[43];
					link.l1.go = "exit";
					break;
				}
				}
			}
		}
		if(bneedexit) // NK bugfix 05-05-11
		{
			Dialog.text = DLG_TEXT[44];
			link.l95 = DLG_TEXT[45];
			link.l95.go = "exit";
		}
		break;


		// Repair the player's blade to the excellent state
	case "BladeMakeExcellent":

		// Unequip and remove player's current blade
		RemoveCharacterEquip(MainChar, BLADE_ITEM_TYPE);
		TakeItemFromCharacter(MainChar, BladeID);

		// Make the player pay
		PlayerMoney -= makeint(GetItemUpgradePrice(BladeID, GetItemQualityByID(BladeID), QUALITY_EXELLENT, pricemult));
		// ccc added makeint cause you can't calc with strings :)

		if (BLACKSMITH_PAY_OUT_WEALTH == 1) // PB: Toggle blacksmith payment in BS.h
		{MainChar.wealth = PlayerMoney;}
		else
		{MainChar.money = PlayerMoney;}

		// Wait a day
		WaitDate("", 0, 0, 1, 0, 0);
		Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"You get your blade back one day later."));

		// Give and equip excellent version of the blade
		GiveItem2Character(MainChar, BladeBaseID + "+3");
		EquipCharacterByItem(MainChar, BladeBaseID + "+3");

		Dialog.text = DLG_TEXT[46];
		link.l1 = DLG_TEXT[47];
		link.l1.go = "exit";
		break;


		// Repair the player's blade to the fine state
	case "BladeMakeFine":

		// Unequip and remove player's current blade
		RemoveCharacterEquip(MainChar, BLADE_ITEM_TYPE);
		TakeItemFromCharacter(MainChar, BladeID);

		// Make the player pay
		PlayerMoney -= makeint(GetItemUpgradePrice(BladeID, GetItemQualityByID(BladeID), QUALITY_FINE, pricemult));
		// ccc added makeint cause you can't calc with strings :)
		if (BLACKSMITH_PAY_OUT_WEALTH == 1) // PB: Toggle blacksmith payment in BS.h
		{MainChar.wealth = PlayerMoney;}
		else
		{MainChar.money = PlayerMoney;}

		// Wait a day
		WaitDate("", 0, 0, 1, 0, 0);
		Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"You get your blade back one day later."));

		// Give and equip excellent version of the blade
		GiveItem2Character(MainChar, BladeBaseID + "+2");
		EquipCharacterByItem(MainChar, BladeBaseID + "+2");

		Dialog.text = DLG_TEXT[48];
		link.l1 = DLG_TEXT[49];
		link.l1.go = "exit";
		break;


		// Repair the player's blade to the good state
	case "BladeMakeGood":

		// Unequip and remove player's current blade
		RemoveCharacterEquip(MainChar, BLADE_ITEM_TYPE);
		TakeItemFromCharacter(MainChar, BladeID);

		// Make the player pay
		PlayerMoney -= makeint(GetItemUpgradePrice(BladeID, GetItemQualityByID(BladeID), QUALITY_GOOD, pricemult));
		// ccc added makeint cause you can't calc with strings :)
		if (BLACKSMITH_PAY_OUT_WEALTH == 1) // PB: Toggle blacksmith payment in BS.h
		{MainChar.wealth = PlayerMoney;}
		else
		{MainChar.money = PlayerMoney;}

		// Wait a day
		WaitDate("", 0, 0, 1, 0, 0);
		Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"You get your blade back one day later."));

		// Give and equip excellent version of the blade
		GiveItem2Character(MainChar, BladeBaseID + "+1");
		EquipCharacterByItem(MainChar, BladeBaseID + "+1");

		Dialog.text = DLG_TEXT[50];
		link.l1 = DLG_TEXT[51];
		link.l1.go = "exit";
		break;


		// Repair the player's blade to the average state
	case "BladeMakeAverage":

		// Unequip and remove player's current blade
		RemoveCharacterEquip(MainChar, BLADE_ITEM_TYPE);
		TakeItemFromCharacter(MainChar, BladeID);

		// Make the player pay
		PlayerMoney -= makeint(GetItemUpgradePrice(BladeID, GetItemQualityByID(BladeID), QUALITY_AVERAGE, pricemult));
		// ccc added makeint cause you can't calc with strings :)
		if (BLACKSMITH_PAY_OUT_WEALTH == 1) // PB: Toggle blacksmith payment in BS.h
		{MainChar.wealth = PlayerMoney;}
		else
		{MainChar.money = PlayerMoney;}

		// Wait a day
		WaitDate("", 0, 0, 1, 0, 0);
		Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"You get your blade back one day later."));

		// Give and equip excellent version of the blade
		GiveItem2Character(MainChar, BladeBaseID);
		EquipCharacterByItem(MainChar, BladeBaseID);

		Dialog.text = DLG_TEXT[52];
		link.l1 = DLG_TEXT[53];
		link.l1.go = "exit";
		break;

		// Blacksmith asks whether or not the current gun should be fixed
	case "GunSelectFix":
		bool gneedexit = true;
		GunID = "";
		if(CheckAttribute(MainChar, "equip.gun")) GunID = MainChar.equip.gun;
		if (GunID != "")
		{
			// Retrieve gun name, gun quality, and upgrade prices
			string GunName   = GetItemNameByID(GunID);
			int GunQuality   = GetItemQualityByID(GunID);
			if(GunQuality >= 0 ) // NK check has quality
			{
				int PriceGunExcellent = GetItemUpgradePrice(GunID, GunQuality, QUALITY_EXELLENT, pricemult);
				int PriceGunFine      = GetItemUpgradePrice(GunID, GunQuality, QUALITY_FINE, pricemult);
				int PriceGunGood      = GetItemUpgradePrice(GunID, GunQuality, QUALITY_GOOD, pricemult);
				int PriceGunAverage   = GetItemUpgradePrice(GunID, GunQuality, QUALITY_AVERAGE, pricemult);
				gneedexit = false;

				// Build the dialog according to the values retrieved above
				switch (GunQuality)
				{
					// For a badly worn gun, show Excellent, Fine, Good and Average
					// (if the player has enough money that is)
				case QUALITY_BADLYWORN:
					Dialog.text = DLG_TEXT[54] + GunName + DLG_TEXT[55];
					if (PriceGunExcellent <= PlayerMoney)
					{
						link.l1 = DLG_TEXT[56] + PriceGunExcellent;;
						link.l1.go = "GunMakeExcellent";
					}
					if (PriceGunFine <= PlayerMoney)
					{
						link.l2 = DLG_TEXT[57] + PriceGunFine;;
						link.l2.go = "GunMakeFine";
					}
					if (PriceGunGood <= PlayerMoney)
					{
						link.l3 = DLG_TEXT[58] + PriceGunGood;;
						link.l3.go = "GunMakeGood";
					}
					if (PriceGunAverage <= PlayerMoney)
					{
						link.l4 = DLG_TEXT[59] + PriceGunAverage;;
						link.l4.go = "GunMakeAverage";
					}
					link.l5 = DLG_TEXT[60];
					link.l5.go = "exit";
					break;

					// Same goes for worn as goes for badly worn
				case QUALITY_WORN:
					Dialog.text = DLG_TEXT[61] + GunName + DLG_TEXT[62];
					if (PriceGunExcellent <= PlayerMoney)
					{
						link.l1 = DLG_TEXT[63] + PriceGunExcellent;;
						link.l1.go = "GunMakeExcellent";
					}
					if (PriceGunFine <= PlayerMoney)
					{
						link.l2 = DLG_TEXT[64] + PriceGunFine;;
						link.l2.go = "GunMakeFine";
					}
					if (PriceGunGood <= PlayerMoney)
					{
						link.l3 = DLG_TEXT[65] + PriceGunGood;;
						link.l3.go = "GunMakeGood";
					}
					if (PriceGunAverage <= PlayerMoney)
					{
						link.l4 = DLG_TEXT[66] + PriceGunAverage;;
						link.l4.go = "GunMakeAverage";
					}
					link.l5 = DLG_TEXT[67];
					link.l5.go = "exit";
					break;

					// If the gun is average, show excellent, fine and good
				case QUALITY_AVERAGE:
					Dialog.text = DLG_TEXT[68] + GunName + DLG_TEXT[69];
					if (PriceGunExcellent <= PlayerMoney)
					{
						link.l1 = DLG_TEXT[70] + PriceGunExcellent;;
						link.l1.go = "GunMakeExcellent";
					}
					if (PriceGunFine <= PlayerMoney)
					{
						link.l2 = DLG_TEXT[71] + PriceGunFine;;
						link.l2.go = "GunMakeFine";
					}
					if (PriceGunGood <= PlayerMoney)
					{
						link.l3 = DLG_TEXT[72] + PriceGunGood;;
						link.l3.go = "GunMakeGood";
					}
					link.l4 = DLG_TEXT[73];
					link.l4.go = "exit";
					break;

					// If the gun is good, show excellent and fine
				case QUALITY_GOOD:
					Dialog.text = DLG_TEXT[74] + GunName + DLG_TEXT[75];
					if (PriceGunExcellent <= PlayerMoney)
					{
						link.l1 = DLG_TEXT[76] + PriceGunExcellent;;
						link.l1.go = "GunMakeExcellent";
					}
					if (PriceGunFine <= PlayerMoney)
					{
						link.l2 = DLG_TEXT[77] + PriceGunFine;;
						link.l2.go = "GunMakeFine";
					}
					link.l3 = DLG_TEXT[78];
					link.l3.go = "exit";
					break;

					// If the gun is fine, show only excellent
				case QUALITY_FINE:
					Dialog.text = DLG_TEXT[79] + GunName + DLG_TEXT[80];
					if (PriceGunExcellent <= PlayerMoney)
					{
						link.l1 = DLG_TEXT[81] + PriceGunExcellent;;
						link.l1.go = "GunMakeExcellent";
					}
					link.l2 = DLG_TEXT[82];
					link.l2.go = "exit";
					break;

					// If the gun is excellent, refuse to repair (as there is nothing to repair...)
				case QUALITY_EXELLENT:
					Dialog.text = DLG_TEXT[83] + GunName + DLG_TEXT[84];
					link.l1 = DLG_TEXT[85];
					link.l1.go = "exit";
					break;
				}
			}
		}
		if(gneedexit) // NK bugfix 05-05-11
		{
			Dialog.text = DLG_TEXT[86];
			link.l95 = DLG_TEXT[87];
			link.l95.go = "exit";
		}
		break;


		// Repair the player's gun to the excellent state
	case "GunMakeExcellent":

		// Unequip and remove player's current gun
		RemoveCharacterEquip(MainChar, GUN_ITEM_TYPE);
		TakeItemFromCharacter(MainChar, GunID);

		// Make the player pay
		PlayerMoney -= makeint(GetItemUpgradePrice(GunID, GetItemQualityByID(GunID), QUALITY_EXELLENT, pricemult));
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

		Dialog.text = DLG_TEXT[88];
		link.l1 = DLG_TEXT[89];
		link.l1.go = "exit";
		break;


		// Repair the player's gun to the fine state
	case "GunMakeFine":

		// Unequip and remove player's current gun
		RemoveCharacterEquip(MainChar, GUN_ITEM_TYPE);
		TakeItemFromCharacter(MainChar, GunID);

		// Make the player pay
		PlayerMoney -= makeint(GetItemUpgradePrice(GunID, GetItemQualityByID(GunID), QUALITY_FINE, pricemult));
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

		Dialog.text = DLG_TEXT[90];
		link.l1 = DLG_TEXT[91];
		link.l1.go = "exit";
		break;


		// Repair the player's gun to the good state
	case "GunMakeGood":

		// Unequip and remove player's current gun
		RemoveCharacterEquip(MainChar, GUN_ITEM_TYPE);
		TakeItemFromCharacter(MainChar, GunID);

		// Make the player pay
		PlayerMoney -= makeint(GetItemUpgradePrice(GunID, GetItemQualityByID(GunID), QUALITY_GOOD, pricemult));
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

		Dialog.text = DLG_TEXT[92];
		link.l1 = DLG_TEXT[93];
		link.l1.go = "exit";
		break;


		// Repair the player's gun to the average state
	case "GunMakeAverage":

		// Unequip and remove player's current gun
		RemoveCharacterEquip(MainChar, GUN_ITEM_TYPE);
		TakeItemFromCharacter(MainChar, GunID);

		// Make the player pay
		PlayerMoney -= makeint(GetItemUpgradePrice(GunID, GetItemQualityByID(GunID), QUALITY_AVERAGE, pricemult));
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

		Dialog.text = DLG_TEXT[94];
		link.l1 = DLG_TEXT[95];
		link.l1.go = "exit";
		break;
	}
	LanguageCloseFile(tmpLangFileID);
}