void CreateTempQuestEnemyCharacters(ref n)
{
	object chobj;
	ref ch;
	makeref(ch, chobj);

//--------------------------------Soldiers-------------------------------
	ch.old.name = "Prison";
	ch.old.lastname = "Guard";
	ch.name = TranslateString("Prison", "Guard");
	ch.lastname = "";
	ch.id		= "Prison_Guard_Spa1";
	ch.model	= 1; // PB
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "Havana_prison";
	ch.location.group = "goto";
	ch.location.locator = "goto13";
	ch.Dialog.Filename = "soldier_dialog.c";// Daniel Arrest
	ch.nation = SPAIN;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetGuardianType(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_SOLDIERS");
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Prison";
	ch.old.lastname = "Guard";
	ch.name = TranslateString("Prison", "Guard");
	ch.lastname = "";
	ch.id		= "Prison_Guard_Spa2";
	ch.model	= 1; // PB
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "Havana_prison";
	ch.location.group = "goto";
	ch.location.locator = "goto12";
	ch.Dialog.Filename = "soldier_dialog.c";
	ch.nation = SPAIN;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetGuardianType(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_SOLDIERS");
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

// Arnold McGill
	ch.old.name = "Arnold";
	ch.old.lastname = "McGill";
	ch.name = TranslateString("", "Arnold");
	ch.lastname = TranslateString("", "McGill");
	ch.id		= "Smuggler";
	ch.model	= "pirat13";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade1");
	ch.equip.blade = "blade1";
	if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)
	{
		GiveItem2Character(ch, "pistol1");
		ch.equip.gun = "pistol1";
	}
	else
	{
		GiveItem2Character(ch, "pistol1a");
		ch.equip.gun = "pistol1a";
	}
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
//	ch.greeting = "Gr_James Norrington";
	ch.Ship.Name = "Seahorse";	
	ch.Ship.Type = "LuggerVML";		
	ch.Ship.Stopped = true;
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Arnold McGill_dialog.c";
	ch.rank 	= 3;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "6";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "3";
	ch.skill.Sneak = "1";
	ch.money = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	AddGameCharacter(n, ch);

	// Watch
	ch.old.name = "Smuggler";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Smuggler");
	ch.lastname = "";
	ch.id		= "Watch";
	ch.model	= "pirat2";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
//	ch.greeting = "Gr_James Norrington";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Watch_dialog.c";
	ch.rank 	= 3;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "6";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "3";
	ch.skill.Sneak = "1";
	ch.money = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	AddGameCharacter(n, ch);

		// Smuggler1
	ch.old.name = "Smuggler";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Smuggler");
	ch.lastname = "";
	ch.id		= "Smuggler1";
	ch.model	= "pirat4";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
//	ch.greeting = "Gr_James Norrington";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Watch_dialog.c";
	ch.rank 	= 3;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "6";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "3";
	ch.skill.Sneak = "1";
	ch.money = "0";
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "ENG_SMUGGLER");
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	AddGameCharacter(n, ch);

	// Smuggler2
	ch.old.name = "Smuggler";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Smuggler");
	ch.lastname = "";
	ch.id		= "Smuggler2";
	ch.model	= "pirat5";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
//	ch.greeting = "Gr_James Norrington";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "";
	ch.rank 	= 3;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "6";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "3";
	ch.skill.Sneak = "1";
	ch.money = "0";
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "ENG_SMUGGLER");
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	AddGameCharacter(n, ch);

	// Smuggler1
	ch.old.name = "Smuggler";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Smuggler");
	ch.lastname = "";
	ch.id		= "Smuggler3";
	ch.model	= "pirat6";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
//	ch.greeting = "Gr_James Norrington";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "";
	ch.rank 	= 3;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "6";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "3";
	ch.skill.Sneak = "1";
	ch.money = "0";
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "ENG_SMUGGLER");
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	AddGameCharacter(n, ch);

//-> Characters for the 'A Family Story' side-quest
	// Robert Acre
	ch.old.name = "Robert";
	ch.old.lastname = "Acre";
	ch.name = TranslateString("","Robert");
	ch.lastname = TranslateString("","Acre");
	ch.id		= "Robert Acre";
	ch.model	= "mask_4";
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "PiratesPistol");
	ch.equip.gun = "PiratesPistol";
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
     //JRH ammo mod <--
	GiveItem2Character(ch, "blade7");
	ch.equip.blade = "blade7";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Backoff";
	ch.nation = FRANCE;
	ch.rank 	= 10;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "2";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "3";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "4";
	ch.skill.Sneak = "3";
	ch.money = "10";
    LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	//Kidnapper1
	ch.old.name = "Jourdain";
	ch.old.lastname = "Anjou";
	ch.name = TranslateString("","Jourdain");
	ch.lastname = TranslateString("","Anjou");
	ch.id		= "kidnapper_1";
	ch.model	= "pirat3";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "pistol1");
	ch.equip.gun = "pistol1";
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
     //JRH ammo mod <--
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.greeting = "Gr_Kidnappers";		
	ch.Dialog.Filename = "kidnappers_dialog.c";//dialog filename
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetCivilianGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	//Kidnapper2
	ch.old.name = "Edam";
	ch.old.lastname = "De Cow";
	ch.name = TranslateString("","Edam");
	ch.lastname = TranslateString("","De Cow");
	ch.id		= "kidnapper_2";
	ch.model	= "pirat1";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "pistol1");
	ch.equip.gun = "pistol1";
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
     //JRH ammo mod <--
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.greeting = "Gr_Kidnappers";		
	ch.Dialog.Filename = "kidnappers_dialog.c";//dialog filename
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetCivilianGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	//Abel Barco
	ch.old.name = "Abel";
	ch.old.lastname = "Barco";
	ch.name = TranslateString("","Abel");
	ch.lastname = TranslateString("","Barco");
	ch.id		= "Abel Barco";
	ch.model	= "pirat5";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "pistol2");
	ch.equip.gun = "pistol2";
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
     //JRH ammo mod <--
	GiveItem2Character(ch, "blade27");
	ch.equip.blade = "blade27";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.greeting = "Gr_Txiki Pijuan";	
	ch.Dialog.Filename = "Abel Barco_dialog.c";//dialog filename
	ch.nation = SPAIN;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetStayType(ch);
    LAi_group_MoveCharacter(ch, "PIRATES_ABEL");
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);
	
// Renouart Larrouse
	ch.old.name = "Renouart";
	ch.old.lastname = "Larrouse";
	ch.name = TranslateString("","Renouart");
	ch.lastname = TranslateString("","Larrouse");
	ch.id		= "Renouart Larrouse";
	ch.model	= "Offic_Fra_19";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.nation	= FRANCE;
	GiveItem2Character(ch, "blade25");
	ch.equip.blade = "blade25";
	GiveItem2Character(ch, "pistol6");
	ch.equip.gun = "pistol6";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Cabinfight_dialog.c";
	ch.rank 	= 10;
	ch.reputation = "None";
	ch.experience = "0";
	ch.greeting = "Gr_falaise de fleur soldier";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "4";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "2";
	ch.skill.Repair = "2";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10000";
	ch.Ship.Name = "Victorieuse";
	ch.Ship.Type = "FR_Razee";
	ch.Ship.Stopped = true;
	ch.ShipSlot1.Type=SHIP_NOTUSED;
	ch.ShipSlot1.Name="NoName";
	ch.ShipSlot2.Type=SHIP_NOTUSED;
	ch.ShipSlot2.Name="NoName";
	ch.ShipSlot3.Type=SHIP_NOTUSED;
	ch.ShipSlot3.Name="NoName";
	ch.quest.killed.pirates = "0";
	LAi_NoRebirthEnable(ch);
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 120.0, 120.0);
	AddGameCharacter(n, ch);	
	//<- Characters for the 'A Family Story' side-quest
	
    //-> Characters for the 'A French companion' side-quest
	
    // Nigel Chandler
	ch.old.name = "Nigel";
	ch.old.lastname = "Chandler";
	ch.name = TranslateString("","Nigel");
	ch.lastname = TranslateString("","Chandler");
	ch.id		= "Nigel Chandler";
	ch.model	= "Offic_eng_18";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.nation	= ENGLAND;
	GiveItem2Character(ch, "blade25");
	ch.equip.blade = "blade25";
	GiveItem2Character(ch, "pistol6");
	ch.equip.gun = "pistol6";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Cabinfight_dialog.c";
	ch.rank 	= 10;
	ch.reputation = "None";
	ch.experience = "0";
	ch.greeting = "Gr_Redmond Soldier";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "4";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "2";
	ch.skill.Repair = "2";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10000";
	ch.Ship.Name = "Endeavour";
	ch.Ship.Type = "HMS_Endeavour";
	ch.Ship.Stopped = true;
	ch.ShipSlot1.Type=SHIP_NOTUSED;
	ch.ShipSlot1.Name="NoName";
	ch.ShipSlot2.Type=SHIP_NOTUSED;
	ch.ShipSlot2.Name="NoName";
	ch.ShipSlot3.Type=SHIP_NOTUSED;
	ch.ShipSlot3.Name="NoName";
	ch.quest.killed.pirates = "0";
	LAi_NoRebirthEnable(ch);
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 120.0, 120.0);
	AddGameCharacter(n, ch);
	
	// Killian Bencroft
	ch.old.name = "Killian";
	ch.old.lastname = "Bencroft";
	ch.name = TranslateString("","Killian");
	ch.lastname = TranslateString("","Bencroft");
	ch.id		= "Killian Bencroft";
	ch.model	= "47_Blaze_brtlt";
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "pistol2");
	ch.equip.gun = "pistol2";
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
     //JRH ammo mod <--
	GiveItem2Character(ch, "blade24");
	ch.equip.blade = "blade24";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Backoff";
	ch.nation = ENGLAND;
	ch.rank 	= 10;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "2";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "3";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "4";
	ch.skill.Sneak = "3";
	ch.money = "10";
    LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);
	
     // Royal Navy
	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name 	= TranslateString("","Soldier");
	ch.lastname 	= "";
	ch.id		= "RN_soldier_1";
	ch.model	= 1; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.location	= "Quest_ShipDeck6";
	ch.location.group = "reload";
	ch.location.locator = "reload3";
	ch.Dialog.Filename = "Royal Navy_dialog.c";
	ch.rank 	= 1;
	ch.nation = ENGLAND;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "BRITISH_NAVY_SOLDIERS");
	ch.greeting = "Gr_Redmond Soldier";
	AddGameCharacter(n, ch);

	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name 	= TranslateString("","Soldier");
	ch.lastname 	= "";
	ch.id		= "RN_soldier_2";
	ch.model	= 2; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";	
	ch.location	= "Quest_ShipDeck6";
	ch.location.group = "goto";
	ch.location.locator = "goto13";
	ch.Dialog.Filename = "Royal Navy_dialog.c";
	ch.rank 	= 1;
	ch.nation = ENGLAND;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "BRITISH_NAVY_SOLDIERS");
	ch.greeting = "Gr_Redmond Soldier";
	AddGameCharacter(n, ch);

	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name 	= TranslateString("","Soldier");
	ch.lastname 	= "";
	ch.id		= "RN_soldier_3";
	ch.model	= 3; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";	
	ch.location	= "Quest_ShipDeck6";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Royal Navy_dialog.c";
	ch.rank 	= 1;
	ch.nation = ENGLAND;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "BRITISH_NAVY_SOLDIERS");
	ch.greeting = "Gr_Redmond Soldier";
	AddGameCharacter(n, ch);

	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name 	= TranslateString("","Soldier");
	ch.lastname 	= "";
	ch.id		= "RN_soldier_4";
	ch.model	= 4; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.location	= "Quest_ShipDeck6";
	ch.location.group = "goto";
	ch.location.locator = "goto27";
	ch.Dialog.Filename = "Royal Navy_dialog.c";
	ch.rank 	= 1;
	ch.nation = ENGLAND;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "BRITISH_NAVY_SOLDIERS");
	ch.greeting = "Gr_Redmond Soldier";
	AddGameCharacter(n, ch);

	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name 	= TranslateString("","Soldier");
	ch.lastname 	= "";
	ch.id		= "RN_soldier_5";
	ch.model	= 5; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";	
	ch.location	= "Quest_Deck1";
	ch.location.group = "reload";
	ch.location.locator = "reload4";
	ch.Dialog.Filename = "Royal Navy_dialog.c";
	ch.rank 	= 1;
	ch.nation = ENGLAND;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "BRITISH_NAVY_SOLDIERS_2");
	ch.greeting = "Gr_Redmond Soldier";
	AddGameCharacter(n, ch);

	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name 	= TranslateString("","Soldier");
	ch.lastname 	= "";
	ch.id		= "RN_soldier_6";
	ch.model	= 6; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.location	= "Quest_Deck2";
	ch.location.group = "reload";
	ch.location.locator = "reload3";
	ch.Dialog.Filename = "Royal Navy2_dialog.c";
	ch.rank 	= 1;
	ch.nation = ENGLAND;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "BRITISH_NAVY_SOLDIERS_3");
	ch.greeting = "Gr_Redmond Soldier";
	AddGameCharacter(n, ch);	 	
	
	//<- Characters for the 'A French companion' side-quest		
//====================================================================================================================
}
