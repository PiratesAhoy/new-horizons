void CreateTempQuestEnemyCharacters(ref n)
{
	object chobj;
	ref ch;

	makeref(ch, chobj);

//--------------------------------Soldiers-------------------------------
	ch.old.name = "Prison";
	ch.old.lastname = "Guard";
	ch.name = TranslateString("","Prison");
	ch.lastname = TranslateString("","Guard");
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
	ch.name = TranslateString("","Prison");
	ch.lastname = TranslateString("","Guard");
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
	ch.name = TranslateString("","Arnold");
	ch.lastname = TranslateString("","McGill");
	ch.id		= "Smuggler";
	ch.model	= "pirat13";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade1");
	ch.equip.blade = "blade1";
	GiveItem2Character(ch, "pistol1");
	ch.equip.gun = "pistol1";
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
	ch.name = TranslateString("","Smuggler");
	ch.lastname = TranslateString("","");
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
	ch.name = TranslateString("","Smuggler");
	ch.lastname = TranslateString("","");
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
	ch.name = TranslateString("","Smuggler");
	ch.lastname = TranslateString("","");
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
	ch.name = TranslateString("","Smuggler");
	ch.lastname = TranslateString("","");
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

//====================================================================================================================
}
