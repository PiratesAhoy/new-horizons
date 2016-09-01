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

		Dialog.text = "Hello captain, pleased to meet you. I'm the local blacksmith.";
		link.l1 = "A blacksmith eh? So what exactly is it that you do? Can you repair anything for me?";
		link.l1.go = "Introduction";
		break;

		// Blacksmith tells the main char about his trade (and use in the game)
	case "Introduction":
		NPCDialog.CurrentNode = "SelectFix";
		Dialog.text = "Ah yes, of course I can, sir! I can repair any sword or gun you bring to me. Just equip the items that need fixing, and I'll fix it for you. The price varies for each type of sword or gun and level of damage, but I can fix everything in one day.";
		link.l1 = "Good, let's get down to business!";
		link.l1.go = "SelectFix";
		link.l2 = "Thanks, I'll keep it in mind! Goodbye.";
		link.l2.go = "exit";
		break;

	case "SelectFix":
		Dialog.text = "So what do you want to have fixed?";
		link.l1 = "I think my blade could use some fixing.";
		link.l1.go = "BladeSelectFix";
		link.l2 = "Does this gun look good to you? Because to me, it sure doesn't.";
		link.l2.go = "GunSelectFix";
		link.l99 = "Ehm. Come to think of it, I don't really need anything fixed at the moment.";
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
			Dialog.text = "What exactly do you want me to do with that rusty antiquity!?!? No blacksmith in the entire Caribbean could repair it, I'm afraid.";
			link.l100 = "Thanks, I'll keep it in mind! Goodbye.";
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
					Dialog.text = "Wow, your " + BladeName + " is in terrible condition! I HAVE to fix it!";
					if (PriceBladeExcellent <= PlayerMoney)
					{
						link.l1 = "I want you to make this the best sword in the Archipelago, even if it costs me " + PriceBladeExcellent;
						link.l1.go = "BladeMakeExcellent";
					}
					if (PriceBladeFine <= PlayerMoney)
					{
						link.l2 = "Make her a blade to be proud of, I'll give you " + PriceBladeFine;
						link.l2.go = "BladeMakeFine";
					}
					if (PriceBladeGood <= PlayerMoney)
					{
						link.l3 = "A decent sword is all I need. Can you fix her up for, say, " + PriceBladeGood;
						link.l3.go = "BladeMakeGood";
					}
					if (PriceBladeAverage <= PlayerMoney)
					{
						link.l4 = "I'm pretty low on cash, so just give her a quick brush for " + PriceBladeAverage;
						link.l4.go = "BladeMakeAverage";
					}
					link.l5 = "That's too expensive, never mind.";
					link.l5.go = "exit";
					break;

					// Same goes for worn as goes for badly worn
				case QUALITY_WORN:
					Dialog.text = "Hmm, your " + BladeName + " is in pretty bad shape. Do you want me to fix it?";
					if (PriceBladeExcellent <= PlayerMoney)
					{
						link.l1 = "I want you to make this the best sword in the Archipelago, even if it costs me " + PriceBladeExcellent;
						link.l1.go = "BladeMakeExcellent";
					}
					if (PriceBladeFine <= PlayerMoney)
					{
						link.l2 = "Make her a blade to be proud of, I'll give you " + PriceBladeFine;
						link.l2.go = "BladeMakeFine";
					}
					if (PriceBladeGood <= PlayerMoney)
					{
						link.l3 = "A decent sword is all I need. Can you fix her up for, say, " + PriceBladeGood;
						link.l3.go = "BladeMakeGood";
					}
					if (PriceBladeAverage <= PlayerMoney)
					{
						link.l4 = "I'm pretty low on cash, so just give her a quick brush for " + PriceBladeAverage;
						link.l4.go = "BladeMakeAverage";
					}
					link.l5 = "That's too expensive, never mind.";
					link.l5.go = "exit";
					break;

					// If the blade is average, show excellent, fine and good
				case QUALITY_AVERAGE:
					Dialog.text = "Well, your " + BladeName + " is in reasonable condition, but you could do so much more damage with it after I fix it!";
					if (PriceBladeExcellent <= PlayerMoney)
					{
						link.l1 = "I want you to make this the best sword in the Archipelago, even if it costs me " + PriceBladeExcellent;
						link.l1.go = "BladeMakeExcellent";
					}
					if (PriceBladeFine <= PlayerMoney)
					{
						link.l2 = "Make her a blade to be proud of, I'll give you " + PriceBladeFine;
						link.l2.go = "BladeMakeFine";
					}
					if (PriceBladeGood <= PlayerMoney)
					{
						link.l3 = "A decent sword is all I need. Can you fix her up for, say, " + PriceBladeGood;
						link.l3.go = "BladeMakeGood";
					}
					link.l4 = "That's too expensive, never mind.";
					link.l4.go = "exit";
					break;

					// If the blade is good, show excellent and fine
				case QUALITY_GOOD:
					Dialog.text = "Nice " + BladeName + "! I'd say sharpen it a little more, polish her up... What do you say?";
					if (PriceBladeExcellent <= PlayerMoney)
					{
						link.l1 = "I want you to make this the best sword in the Archipelago, even if it costs me " + PriceBladeExcellent;
						link.l1.go = "BladeMakeExcellent";
					}
					if (PriceBladeFine <= PlayerMoney)
					{
						link.l2 = "Make her a blade to be proud of, I'll give you " + PriceBladeFine;
						link.l2.go = "BladeMakeFine";
					}
					link.l3 = "That's too expensive, never mind.";
					link.l3.go = "exit";
					break;

					// If the blade is fine, show only excellent
				case QUALITY_FINE:
					Dialog.text = "Ha! And what exactly would you like me to do with your " + BladeName + "? Just kidding, I can polish her up for you if you like.";
					if (PriceBladeExcellent <= PlayerMoney)
					{
						link.l1 = "I want you to make this the best sword in the Archipelago, even if it costs me " + PriceBladeExcellent;
						link.l1.go = "BladeMakeExcellent";
					}
					link.l2 = "That's too expensive, never mind.";
					link.l2.go = "exit";
					break;

					// If the blade is excellent, refuse to repair (as there is nothing to repair...)
				case QUALITY_EXELLENT:
					Dialog.text = "... That " + BladeName + " is amazing! A true masterpiece! I wouldn't dare do anything to it fearing I'd destroy it!";
					link.l1 = "...";
					link.l1.go = "exit";
					break;
				}
				}
			}
		}
		if(bneedexit) // NK bugfix 05-05-11
		{
			Dialog.text = "If you want my services, equip a blade, a proper blade, before you talk to me!";
			link.l95 = "...";
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

		Dialog.text = "There you go, I'm all done. I hope to see you again when you need my services.";
		link.l1 = "Thanks, I'll know where to find you!";
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

		Dialog.text = "There you go, I'm all done. I hope to see you again when you need my services.";
		link.l1 = "Thanks, I'll know where to find you!";
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

		Dialog.text = "There you go, I'm all done. I hope to see you again when you need my services.";
		link.l1 = "Thanks, I'll know where to find you!";
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

		Dialog.text = "There you go, I'm all done. I hope to see you again when you need my services.";
		link.l1 = "Thanks, I'll know where to find you!";
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
					Dialog.text = "Wow, your " + GunName + " is in terrible condition! I HAVE to fix it!";
					if (PriceGunExcellent <= PlayerMoney)
					{
						link.l1 = "I want you to make this the best gun in the Archipelago, even if it costs me " + PriceGunExcellent;
						link.l1.go = "GunMakeExcellent";
					}
					if (PriceGunFine <= PlayerMoney)
					{
						link.l2 = "Make her a gun to be proud of, I'll give you " + PriceGunFine;
						link.l2.go = "GunMakeFine";
					}
					if (PriceGunGood <= PlayerMoney)
					{
						link.l3 = "A decent gun is all I need. Can you fix her up for, say, " + PriceGunGood;
						link.l3.go = "GunMakeGood";
					}
					if (PriceGunAverage <= PlayerMoney)
					{
						link.l4 = "I'm pretty low on cash, so just give her a quick brush for " + PriceGunAverage;
						link.l4.go = "GunMakeAverage";
					}
					link.l5 = "That's too expensive, never mind.";
					link.l5.go = "exit";
					break;

					// Same goes for worn as goes for badly worn
				case QUALITY_WORN:
					Dialog.text = "Hmm, your " + GunName + " is in pretty bad shape. Do you want me to fix it?";
					if (PriceGunExcellent <= PlayerMoney)
					{
						link.l1 = "I want you to make this the best gun in the Archipelago, even if it costs me " + PriceGunExcellent;
						link.l1.go = "GunMakeExcellent";
					}
					if (PriceGunFine <= PlayerMoney)
					{
						link.l2 = "Make her a gun to be proud of, I'll give you " + PriceGunFine;
						link.l2.go = "GunMakeFine";
					}
					if (PriceGunGood <= PlayerMoney)
					{
						link.l3 = "A decent gun is all I need. Can you fix her up for, say, " + PriceGunGood;
						link.l3.go = "GunMakeGood";
					}
					if (PriceGunAverage <= PlayerMoney)
					{
						link.l4 = "I'm pretty low on cash, so just give her a quick brush for " + PriceGunAverage;
						link.l4.go = "GunMakeAverage";
					}
					link.l5 = "That's too expensive, never mind.";
					link.l5.go = "exit";
					break;

					// If the gun is average, show excellent, fine and good
				case QUALITY_AVERAGE:
					Dialog.text = "Well, your " + GunName + " is in reasonable condition, but you could do so much more damage with it after I fix it!";
					if (PriceGunExcellent <= PlayerMoney)
					{
						link.l1 = "I want you to make this the best gun in the Archipelago, even if it costs me " + PriceGunExcellent;
						link.l1.go = "GunMakeExcellent";
					}
					if (PriceGunFine <= PlayerMoney)
					{
						link.l2 = "Make her a gun to be proud of, I'll give you " + PriceGunFine;
						link.l2.go = "GunMakeFine";
					}
					if (PriceGunGood <= PlayerMoney)
					{
						link.l3 = "A decent gun is all I need. Can you fix her up for, say, " + PriceGunGood;
						link.l3.go = "GunMakeGood";
					}
					link.l4 = "That's too expensive, never mind.";
					link.l4.go = "exit";
					break;

					// If the gun is good, show excellent and fine
				case QUALITY_GOOD:
					Dialog.text = "Nice " + GunName + "! I'd say sharpen it a little more, polish her up... What do you say?";
					if (PriceGunExcellent <= PlayerMoney)
					{
						link.l1 = "I want you to make this the best gun in the Archipelago, even if it costs me " + PriceGunExcellent;
						link.l1.go = "GunMakeExcellent";
					}
					if (PriceGunFine <= PlayerMoney)
					{
						link.l2 = "Make her a gun to be proud of, I'll give you " + PriceGunFine;
						link.l2.go = "GunMakeFine";
					}
					link.l3 = "That's too expensive, never mind.";
					link.l3.go = "exit";
					break;

					// If the gun is fine, show only excellent
				case QUALITY_FINE:
					Dialog.text = "Ha! And what exactly would you like me to do with your " + GunName + "? Just kidding, I can polish her up for you if you like.";
					if (PriceGunExcellent <= PlayerMoney)
					{
						link.l1 = "I want you to make this the best gun in the Archipelago, even if it costs me " + PriceGunExcellent;
						link.l1.go = "GunMakeExcellent";
					}
					link.l2 = "That's too expensive, never mind.";
					link.l2.go = "exit";
					break;

					// If the gun is excellent, refuse to repair (as there is nothing to repair...)
				case QUALITY_EXELLENT:
					Dialog.text = "... That " + GunName + " is amazing! A true masterpiece! I wouldn't dare do anything to it fearing I'd destroy it!";
					link.l1 = "...";
					link.l1.go = "exit";
					break;
				}
			}
		}
		if(gneedexit) // NK bugfix 05-05-11
		{
			Dialog.text = "If you want my services, equip a gun, a proper gun, before you talk to me!";
			link.l95 = "...";
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

		Dialog.text = "There you go, I'm all done. I hope to see you again when you need my services.";
		link.l1 = "Thanks, I'll know where to find you!";
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

		Dialog.text = "There you go, I'm all done. I hope to see you again when you need my services.";
		link.l1 = "Thanks, I'll know where to find you!";
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

		Dialog.text = "There you go, I'm all done. I hope to see you again when you need my services.";
		link.l1 = "Thanks, I'll know where to find you!";
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

		Dialog.text = "There you go, I'm all done. I hope to see you again when you need my services.";
		link.l1 = "Thanks, I'll know where to find you!";
		link.l1.go = "exit";
		break;
	}
	LanguageCloseFile(tmpLangFileID);
}