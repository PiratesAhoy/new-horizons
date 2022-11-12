void CreateTempQuestEnemyCharacters(ref n)
{
	object chobj;
	ref ch;

	makeref(ch, chobj);

			//Patrol
	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","Soldier");
	ch.lastname = "";
	ch.id		= "Lineship_soldier_1";
	ch.model	= 5; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = FRANCE;
	GiveItem2Character(ch, "pistol1a");
	ch.equip.gun = "pistol1a";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--	
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	ch.location	= "Quest_ShipDeck2";
	ch.location.group = "rld";
	ch.location.locator = "loc3";
	ch.Dialog.Filename = "Patrol_dialog.c";
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
	LAi_NoRebirthEnable(ch);	
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "SHIP_FRENCH_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier"; // was "Gr_Patrol"
	AddGameCharacter(n, ch);
	
			//Patrol
	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","Soldier");
	ch.lastname = "";
	ch.id		= "Lineship_soldier_2";
	ch.model	= 4; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = FRANCE;
	GiveItem2Character(ch, "pistol1a");
	ch.equip.gun = "pistol1a";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--	
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	ch.location	= "Quest_ShipDeck2";
	ch.location.group = "rld";
	ch.location.locator = "aloc15";
	ch.Dialog.Filename = "Patrol_dialog.c";
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
	LAi_NoRebirthEnable(ch);	
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "SHIP_FRENCH_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier"; // was "Gr_Patrol"
	AddGameCharacter(n, ch);

			//Guardian
	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","Soldier");
	ch.lastname = "";
	ch.id		= "Lineship_soldier_3";
	ch.model	= 2; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = FRANCE;
	GiveItem2Character(ch, "pistol1a");
	ch.equip.gun = "pistol1a";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--	
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	ch.location	= "Quest_ShipDeck2";
	ch.location.group = "rld";
	ch.location.locator = "loc6";
	ch.Dialog.Filename = "Patrol_dialog.c";
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
	LAi_NoRebirthEnable(ch);	
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "SHIP_FRENCH_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier"; // was "Gr_Patrol"
	AddGameCharacter(n, ch);	

			//Guardian
	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","Soldier");
	ch.lastname = "";
	ch.id		= "Lineship_soldier_4";
	ch.model	= 3; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = FRANCE;
	GiveItem2Character(ch, "pistol1a");
	ch.equip.gun = "pistol1a";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--	
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	ch.location	= "Quest_ShipDeck2";
	ch.location.group = "reload";
	ch.location.locator = "reload3";
	ch.Dialog.Filename = "Patrol_dialog.c";
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
	LAi_NoRebirthEnable(ch);	
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "SHIP_FRENCH_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier"; // was "Gr_Patrol"
	AddGameCharacter(n, ch);

			//Guardian
	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","Soldier");
	ch.lastname = "";
	ch.id		= "Lineship_soldier_5";
	ch.model	= 4; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = FRANCE;
	GiveItem2Character(ch, "pistol1a");
	ch.equip.gun = "pistol1a";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--	
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	ch.location	= "Quest_Deck1";
	ch.location.group = "reload";
	ch.location.locator = "reload4";
	ch.Dialog.Filename = "Patrol_dialog.c";
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
	LAi_NoRebirthEnable(ch);	
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "SHIP_FRENCH_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier"; // was "Gr_Patrol"
	AddGameCharacter(n, ch);

			//Guardian
	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","Soldier");
	ch.lastname = "";
	ch.id		= "Lineship_soldier_6";
	ch.model	= 2; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = FRANCE;
	GiveItem2Character(ch, "pistol1a");
	ch.equip.gun = "pistol1a";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--	
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	ch.location	= "Quest_Deck3";
	ch.location.group = "reload";
	ch.location.locator = "reload3";
	ch.Dialog.Filename = "Patrol_dialog.c";
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
	LAi_NoRebirthEnable(ch);	
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "SHIP_FRENCH_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier"; // was "Gr_Patrol"
	AddGameCharacter(n, ch);

			//Guardian
	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","Soldier");
	ch.lastname = "";
	ch.id		= "Lineship_soldier_7";
	ch.model	= 3; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = FRANCE;
	GiveItem2Character(ch, "pistol1a");
	ch.equip.gun = "pistol1a";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--	
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	ch.location	= "Quest_Hold1";
	ch.location.group = "rld";
	ch.location.locator = "startloc";
	ch.Dialog.Filename = "Patrol_dialog.c";
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
	LAi_NoRebirthEnable(ch);	
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "SHIP_FRENCH_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier"; // was "Gr_Patrol"
	AddGameCharacter(n, ch);	

//====================================================================================================================
// La Couronne
	ch.old.name = "Gilles";
	ch.old.lastname = "Chennault";
	ch.name = TranslateString("","Gilles");
	ch.lastname = TranslateString("","Chennault");
	ch.id		= "French_Captain1";
	ch.nation	= FRANCE;
	ch.model	= "Huber_Fra_17";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade25");
	ch.equip.blade = "blade25";
	ch.nodisarm	= 1;			
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = " ";
	ch.rank 	= 10;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "7";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "9";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
	ch.Ship.Name = "La Couronne";
	ch.Ship.Type = "FR_Couronne";
	ch.Ship.Stopped = true;
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.Gunman = true;
	ch.perks.list.FastReload = true;
	ch.perks.list.HullDamageUp = true;
	ch.perks.list.CrewDamageUp = true;
	ch.perks.list.BasicDamageControl = true;
	ch.perks.list.Rigging = true;
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;	
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);
	
// La Licorne	
	ch.old.name = "Aimery";
	ch.old.lastname = "Bourgouin";
	ch.name = TranslateString("","Aimery");
	ch.lastname = TranslateString("","Bourgouin");
	ch.id		= "French_Captain2";
	ch.nation	= FRANCE;
	ch.model	= "Huber_Fra2_17";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "bladeC11");
	ch.equip.blade = "bladeC11";
	ch.nodisarm	= 1;			
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = " ";
	ch.rank 	= 10;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "7";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "9";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
	ch.Ship.Name = "La Licorne";
	ch.Ship.Type = "FR_Licorne";
	ch.Ship.Stopped = true;
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.Gunman = true;
	ch.perks.list.FastReload = true;
	ch.perks.list.HullDamageUp = true;
	ch.perks.list.CrewDamageUp = true;
	ch.perks.list.BasicDamageControl = true;
	ch.perks.list.Rigging = true;
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;	
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);
	
// Le Foudrayant	
	ch.old.name = "Guibert";
	ch.old.lastname = "d'Aigreville";
	ch.name = TranslateString("","Guibert");
	ch.lastname = TranslateString("","d'Aigreville");
	ch.id		= "French_Captain3";
	ch.nation	= FRANCE;
	ch.model	= "Huber_Fra4_17";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade9");
	ch.equip.blade = "blade9";
	ch.nodisarm	= 1;			
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = " ";
	ch.rank 	= 10;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "7";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "9";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
	ch.Ship.Name = "Le Foudrayant";
	ch.Ship.Type = "FR_WarGalleon";
	ch.Ship.Stopped = true;
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.Gunman = true;
	ch.perks.list.FastReload = true;
	ch.perks.list.HullDamageUp = true;
	ch.perks.list.CrewDamageUp = true;
	ch.perks.list.BasicDamageControl = true;
	ch.perks.list.Rigging = true;
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;	
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);

// Indefatigable	
	ch.old.name = "Barnabas";
	ch.old.lastname = "Delbridge";
	ch.name = TranslateString("","Barnabas");
	ch.lastname = TranslateString("","Delbridge");
	ch.id		= "English_Captain2";
	ch.nation	= ENGLAND;
	ch.model	= "offic_eng_16";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "bladeC30");
	ch.equip.blade = "bladeC30";
	ch.nodisarm	= 1;			
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = " ";
	ch.rank 	= 10;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "7";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "9";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
	ch.Ship.Name = "Unicorn";
	ch.Ship.Type = "RN_WarGalleon";
	ch.Ship.Stopped = true;
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.Gunman = true;
	ch.perks.list.FastReload = true;
	ch.perks.list.HullDamageUp = true;
	ch.perks.list.CrewDamageUp = true;
	ch.perks.list.BasicDamageControl = true;
	ch.perks.list.Rigging = true;
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;	
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);

// Mordaunt	
	ch.old.name = "David";
	ch.old.lastname = "Fewster";
	ch.name = TranslateString("","David");
	ch.lastname = TranslateString("","Fewster");
	ch.id		= "English_Captain3";
	ch.nation	= ENGLAND;
	ch.model	= "offic_eng_16";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "bladeC26");
	ch.equip.blade = "bladeC26";
	ch.nodisarm	= 1;			
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = " ";
	ch.rank 	= 10;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "7";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "9";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
	ch.Ship.Name = "Mordaunt";
	ch.Ship.Type = "HMS_Mordaunt";
	ch.Ship.Stopped = true;
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.Gunman = true;
	ch.perks.list.FastReload = true;
	ch.perks.list.HullDamageUp = true;
	ch.perks.list.CrewDamageUp = true;
	ch.perks.list.BasicDamageControl = true;
	ch.perks.list.Rigging = true;
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;	
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);

// Impartial	
	ch.old.name = "Laurence";
	ch.old.lastname = "Damson";
	ch.name = TranslateString("","Laurence");
	ch.lastname = TranslateString("","Damson");
	ch.id		= "English_Captain4";
	ch.nation	= ENGLAND;
	ch.model	= "offic_eng_16";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade44");
	ch.equip.blade = "blade44";
	ch.nodisarm	= 1;			
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = " ";
	ch.rank 	= 10;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "7";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "9";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
	ch.Ship.Name = "Impartial";
	ch.Ship.Type = "RN_WarGalleon";
	ch.Ship.Stopped = true;
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.Gunman = true;
	ch.perks.list.FastReload = true;
	ch.perks.list.HullDamageUp = true;
	ch.perks.list.CrewDamageUp = true;
	ch.perks.list.BasicDamageControl = true;
	ch.perks.list.Rigging = true;
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;	
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);
	
//	--- Silver Fleet ---

// Spanish Captain2	
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Spanish Captain2";
	ch.nation	= SPAIN;
	ch.model	= "Hugnt18";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";			
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = " ";
	ch.rank 	= 4;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "7";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "9";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
	ch.Ship.Name = "Rio del Plata";
	ch.Ship.Type = "Galeon50";
	ch.Ship.Stopped = true; 
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);

// Spanish Captain3	
	ch.old.name = "Grigorio";
	ch.old.lastname = "Cadena";
	ch.name = TranslateString("","Grigorio");
	ch.lastname = TranslateString("","Cadena");
	ch.id		= "Spanish Captain3";
	ch.nation	= SPAIN;
	ch.model	= "Huber_Spa";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";			
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = " ";
	ch.rank 	= 4;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "7";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "9";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
	ch.Ship.Name = "Madragal";
	ch.Ship.Type = "SP_Galeon50";
	ch.Ship.Stopped = true; 
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);
	
// Spanish Captain1	
	ch.old.name = "Bautista";
	ch.old.lastname = "Lozano";
	ch.name = TranslateString("","Bautista");
	ch.lastname = TranslateString("","Lozano");
	ch.id		= "Spanish Captain1";
	ch.nation	= SPAIN;
	ch.model	= "Hub_Spa2"; // GR: was "Huber_Spa2", which does not exist
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";			
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = " ";
	ch.rank 	= 4;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "7";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "9";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
	ch.Ship.Name = "La Galiza";
	ch.Ship.Type = "SP_ApostolFelipe";
	ch.Ship.Stopped = true; 
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);

// Spanish Captain4	
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Spanish Captain4";
	ch.nation	= SPAIN;
	ch.model	= "Hub_Spa3";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";			
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = " ";
	ch.rank 	= 4;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "7";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "9";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
	ch.Ship.Name = "El Castillo";
	ch.Ship.Type = "GaleonWar";
	ch.Ship.Stopped = true; 
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);

// Dutch Ship in Playa de Sabana

	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Dutch Captain";
	ch.nation	= HOLLAND;
	ch.model	= "Hub_Spa3";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";			
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = " ";
	ch.rank 	= 4;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "7";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "9";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
	ch.Ship.Name = "Westfriesland";
	ch.Ship.Type = "NL_Derfflinger";
	ch.Ship.Stopped = true; 
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);

///////////////////////////////// HAVANA RESIDENCE ////////////////////////////////////

	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name 	= TranslateString("","Soldier");
	ch.lastname 	= "";
	ch.id		= "Quest_Havana_soldier_01";
	ch.model	= 1; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	ch.location	= "Quest_Havana_Town_01";
	ch.location.group = "goto";
	ch.location.locator = "goto11";
	ch.Dialog.Filename = "Eleuthera soldier_dialog.c";
	ch.rank 	= 1;
	ch.nation = SPAIN;
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
	ch.greeting = "Gr_Redmond Soldier";
	AddGameCharacter(n, ch);

	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name 	= TranslateString("","Soldier");
	ch.lastname 	= "";
	ch.id		= "Quest_Havana_soldier_02";
	ch.model	= 2; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	ch.location	= "Quest_Havana_Town_01";
	ch.location.group = "goto";
	ch.location.locator = "goto25";
	ch.Dialog.Filename = "Eleuthera soldier_dialog.c";
	ch.rank 	= 1;
	ch.nation = SPAIN;
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
	ch.greeting = "Gr_Redmond Soldier";
	AddGameCharacter(n, ch);

	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name 	= TranslateString("","Soldier");
	ch.lastname 	= "";
	ch.id		= "Quest_Havana_soldier_03";
	ch.model	= 3; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	ch.location	= "Quest_Havana_Town_01";
	ch.location.group = "goto";
	ch.location.locator = "soldier1";
	ch.Dialog.Filename = "Eleuthera soldier_dialog.c";
	ch.rank 	= 1;
	ch.nation = SPAIN;
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
	ch.greeting = "Gr_Redmond Soldier";
	AddGameCharacter(n, ch);

	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name 	= TranslateString("","Soldier");
	ch.lastname 	= "";
	ch.id		= "Quest_Havana_soldier_04";
	ch.model	= 4; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	ch.location	= "Quest_Havana_Town_01";
	ch.location.group = "goto";
	ch.location.locator = "soldier2";
	ch.Dialog.Filename = "Eleuthera soldier_dialog.c";
	ch.rank 	= 1;
	ch.nation = SPAIN;
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
	ch.greeting = "Gr_Redmond Soldier";
	AddGameCharacter(n, ch);

	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name 	= TranslateString("","Soldier");
	ch.lastname 	= "";
	ch.id		= "Quest_Havana_soldier_05";
	ch.model	= 5; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Eleuthera soldier_dialog.c";
	ch.rank 	= 1;
	ch.nation = SPAIN;
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
	ch.greeting = "Gr_Redmond Soldier";
	AddGameCharacter(n, ch);

	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name 	= TranslateString("","Soldier");
	ch.lastname 	= "";
	ch.id		= "Quest_Havana_soldier_06";
	ch.model	= 5; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Eleuthera soldier_dialog.c";
	ch.rank 	= 1;
	ch.nation = SPAIN;
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
	ch.greeting = "Gr_Redmond Soldier";
	AddGameCharacter(n, ch);

///////////////////////////////// MORRO FORT ////////////////////////////////////

	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name 	= TranslateString("","Soldier");
	ch.lastname 	= "";
	ch.id		= "Quest_Morro_soldier_01";
	ch.model	= 5; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	ch.location	= "Morro_Fort";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Eleuthera soldier_dialog.c";
	ch.rank 	= 1;
	ch.nation = SPAIN;
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
	LAi_SetHP(ch, 20.0, 20.0);
	LAi_group_MoveCharacter(ch, "MORRO_SOLDIERS");	
	ch.greeting = "Gr_Redmond Soldier";
	AddGameCharacter(n, ch);

	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name 	= TranslateString("","Soldier");
	ch.lastname 	= "";
	ch.id		= "Quest_Morro_soldier_02";
	ch.model	= 4; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	ch.location	= "Morro_Fort";
	ch.location.group = "goto";
	ch.location.locator = "goto2";
	ch.Dialog.Filename = "Eleuthera soldier_dialog.c";
	ch.rank 	= 1;
	ch.nation = SPAIN;
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
	LAi_SetHP(ch, 20.0, 20.0);
	LAi_group_MoveCharacter(ch, "MORRO_SOLDIERS");	
	ch.greeting = "Gr_Redmond Soldier";
	AddGameCharacter(n, ch);
	
       // Patrol	
	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","Soldier");
	ch.lastname = "";
	ch.id		= "Quest_Morro_soldier_08";
	ch.model	= 5; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = SPAIN;
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	GiveItem2Character(ch, "pistol1a");
	ch.equip.gun = "pistol1a";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--	
	ch.location	= "Morro_Fort";
	ch.location.group = "goto";
	ch.location.locator = "goto14";	
	ch.Dialog.Filename = "Patrol_dialog.c";
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
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 20.0, 20.0);
	LAi_group_MoveCharacter(ch, "MORRO_SOLDIERS");
	ch.greeting = "Gr_isla muelle soldier"; // was "Gr_Patrol"
	AddGameCharacter(n, ch);	

       // Patrol	
	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","Soldier");
	ch.lastname = "";
	ch.id		= "Quest_Morro_soldier_03";
	ch.model	= 1; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = SPAIN;
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	GiveItem2Character(ch, "pistol1a");
	ch.equip.gun = "pistol1a";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--	
	ch.location	= "Morro_Fort";
	ch.location.group = "goto";
	ch.location.locator = "goto46";	
	ch.Dialog.Filename = "Patrol_dialog.c";
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
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 20.0, 20.0);
	LAi_group_MoveCharacter(ch, "MORRO_SOLDIERS");
	ch.greeting = "Gr_isla muelle soldier"; // was "Gr_Patrol"
	AddGameCharacter(n, ch);

			//Patrol
	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","Soldier");
	ch.lastname = "";
	ch.id		= "Quest_Morro_soldier_04";
	ch.model	= 4; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = SPAIN;
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	GiveItem2Character(ch, "pistol1a");
	ch.equip.gun = "pistol1a";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--	
	ch.location	= "Morro_Fort";
	ch.location.group = "goto";
	ch.location.locator = "goto45"; 
	ch.Dialog.Filename = "Patrol_dialog.c";
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
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 20.0, 20.0);
	LAi_group_MoveCharacter(ch, "MORRO_SOLDIERS");
	ch.greeting = "Gr_isla muelle soldier"; // was "Gr_Patrol"
	AddGameCharacter(n, ch);

	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","Soldier");
	ch.lastname = "";
	ch.id		= "Quest_Morro_soldier_05";
	ch.model	= 6; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = SPAIN;
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	GiveItem2Character(ch, "pistol1a");
	ch.equip.gun = "pistol1a";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--	
	ch.location	= "Morro_Fort";
	ch.location.group = "goto";
	ch.location.locator = "goto44";	
	ch.Dialog.Filename = "Patrol_dialog.c";
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
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 20.0, 20.0);
	LAi_group_MoveCharacter(ch, "MORRO_SOLDIERS");
	ch.greeting = "Gr_isla muelle soldier"; // was "Gr_Patrol"
	AddGameCharacter(n, ch);

			//Patrol
	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","Soldier");
	ch.lastname = "";
	ch.id		= "Quest_Morro_soldier_06";
	ch.model	= 4; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = SPAIN;
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	GiveItem2Character(ch, "pistol1a");
	ch.equip.gun = "pistol1a";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--	
	ch.location	= "Morro_Fort";
	ch.location.group = "goto";
	ch.location.locator = "goto43";	
	ch.Dialog.Filename = "Patrol_dialog.c";
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
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 20.0, 20.0);
	LAi_group_MoveCharacter(ch, "MORRO_SOLDIERS");
	ch.greeting = "Gr_isla muelle soldier"; // was "Gr_Patrol"
	AddGameCharacter(n, ch);

	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","Soldier");
	ch.lastname = "";
	ch.id		= "Quest_Morro_soldier_07";
	ch.model	= 5; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = SPAIN;
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	GiveItem2Character(ch, "pistol1a");
	ch.equip.gun = "pistol1a";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--	
	ch.location	= "Morro_Fort";
	ch.location.group = "goto";
	ch.location.locator = "goto11";	
	ch.Dialog.Filename = "Patrol_dialog.c";
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
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 20.0, 20.0);
	LAi_group_MoveCharacter(ch, "MORRO_SOLDIERS");
	ch.greeting = "Gr_isla muelle soldier"; // was "Gr_Patrol"
	AddGameCharacter(n, ch);

	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name 	= TranslateString("","Soldier");
	ch.lastname 	= "";
	ch.id		= "Quest_Morro_soldier_09";
	ch.model	= 2; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	ch.location	= "Morro_Fort";
	ch.location.group = "goto";
	ch.location.locator = "goto16";
	ch.Dialog.Filename = "Eleuthera soldier_dialog.c";
	ch.rank 	= 1;
	ch.nation = SPAIN;
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
	LAi_SetHP(ch, 20.0, 20.0);
	LAi_group_MoveCharacter(ch, "MORRO_SOLDIERS");	
	ch.greeting = "Gr_Redmond Soldier";
	AddGameCharacter(n, ch);

	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name 	= TranslateString("","Soldier");
	ch.lastname 	= "";
	ch.id		= "Quest_Morro_soldier_10";
	ch.model	= 3; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	ch.location	= "Morro_Fort";
	ch.location.group = "goto";
	ch.location.locator = "goto15";
	ch.Dialog.Filename = "Eleuthera soldier_dialog.c";
	ch.rank 	= 1;
	ch.nation = SPAIN;
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
	LAi_SetHP(ch, 20.0, 20.0);
	LAi_group_MoveCharacter(ch, "MORRO_SOLDIERS");	
	ch.greeting = "Gr_Redmond Soldier";
	AddGameCharacter(n, ch);

	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name 	= TranslateString("","Soldier");
	ch.lastname 	= "";
	ch.id		= "Quest_Morro_soldier_11";
	ch.model	= 4; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	ch.location	= "Morro_Fort";
	ch.location.group = "goto";
	ch.location.locator = "goto38";
	ch.Dialog.Filename = "Eleuthera soldier_dialog.c";
	ch.rank 	= 1;
	ch.nation = SPAIN;
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
	LAi_SetHP(ch, 20.0, 20.0);
	LAi_group_MoveCharacter(ch, "MORRO_SOLDIERS");	
	ch.greeting = "Gr_Redmond Soldier";
	AddGameCharacter(n, ch);		
}
