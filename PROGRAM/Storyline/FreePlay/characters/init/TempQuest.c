void CreateTempQuestCharacters(ref n)
{
	object chobj;
	ref ch;

	makeref(ch, chobj);

	// Bart Renault
	ch.old.name = "Bart";
	ch.old.lastname = "Renault";
	ch.name = TranslateString("","Bart");
	ch.lastname = TranslateString("","Renault");
	ch.id		= "Bart Renault";
	ch.model	= "Corsair2"; // PB
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "Havana_prison";
	ch.location.group = "goto";
	ch.location.locator = "goto12";
	ch.Dialog.Filename = "Bart Renault_dialog.c";// 
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
	LAi_SetImmortal(ch, true);
	LAi_group_MoveCharacter(ch, "FRENCH_JAILER");
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

// Enrique Padilla
	ch.old.name = "Enrique";
	ch.old.lastname = "Padilla";
	ch.name = TranslateString("","Enrique");
	ch.lastname = TranslateString("","Padilla");
	ch.id		= "Enrique Padilla";
	ch.model	= "Offic_spa2_16";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade28");
	ch.equip.blade = "blade28";
	GiveItem2Character(ch, "pistol2");
	ch.equip.gun = "pistol2";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Enrique Padilla_dialog.c";
	ch.greeting = "Gr_isla muelle soldier";
	ch.Ship.Name = "Miguel de Cervantes";	
	ch.Ship.Type = "PO_Fleut50";		
	ch.Ship.Stopped = true;
	ch.rank 	= 10;
	ch.reputation = "None";
	ch.experience = "80";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "2";
	ch.skill.Repair = "1";
	ch.skill.Defence = "4";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "3";
	ch.money = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	AddGameCharacter(n, ch);
	
// Celestino Villalobos
	ch.old.name = "Celestino";
	ch.old.lastname = "Villalobos";
	ch.name = TranslateString("","Celestino");
	ch.lastname = TranslateString("","Villalobos");
	ch.id		= "Celestino Villalobos";
	ch.model	= "man9";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	GiveItem2Character(ch, "pistol1");
	ch.equip.gun = "pistol1";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Celestino Villalobos_dialog.c";
	ch.greeting = "Gr_Francisco Cruz";
	ch.rank 	= 3;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
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
	
	// Havana_Crewmember1
	ch.old.name = "Crewmember";
	ch.old.lastname = "";
	ch.name = TranslateString("","Crewmember");
	ch.lastname = TranslateString("","");
	ch.id		= "Crewmember_Jean1";
	ch.model	= "Sailor5";
	ch.sex = "man";
	ch.sound_type = "sailor";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Havana_Crewmember_dialog.c";
	ch.greeting = "Gr_Francois Chabert";
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
	LAi_SetCivilianGuardianType(ch);
	LAi_group_MoveCharacter(ch, "LAI_GROUP_PLAYER");
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 500.0, 500.0);
	LAi_NoRebirthEnable(ch);
	AddGameCharacter(n, ch);
	
		// Havana_Crewmember2
	ch.old.name = "Crewmember";
	ch.old.lastname = "";
	ch.name = TranslateString("","Crewmember");
	ch.lastname = TranslateString("","");
	ch.id		= "Crewmember_Jean2";
	ch.model	= "Sailor3";
	ch.sex = "man";
	ch.sound_type = "sailor";
	GiveItem2Character(ch, "blade1");
	ch.equip.blade = "blade1";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Crewmember_dialog.c";
	ch.greeting = "Gr_Francois Chabert";
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
	LAi_SetCivilianGuardianType(ch);
	LAi_group_MoveCharacter(ch, "LAI_GROUP_PLAYER");
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 500.0, 500.0);
	LAi_NoRebirthEnable(ch);
	AddGameCharacter(n, ch);
	
		// Havana_Crewmember1
	ch.old.name = "Crewmember";
	ch.old.lastname = "";
	ch.name = TranslateString("","Crewmember");
	ch.lastname = TranslateString("","");
	ch.id		= "Crewmember_Jean3";
	ch.model	= "Sailor6";
	ch.sex = "man";
	ch.sound_type = "sailor";
	GiveItem2Character(ch, "blade1");
	ch.equip.blade = "blade1";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Crewmember_dialog.c";
	ch.greeting = "Gr_Francois Chabert";
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
	LAi_SetCivilianGuardianType(ch);
	LAi_group_MoveCharacter(ch, "LAI_GROUP_PLAYER");
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 500.0, 500.0);
	LAi_NoRebirthEnable(ch);
	AddGameCharacter(n, ch);
	
	// Spanish Commander
	ch.old.name = "Spanish";
	ch.old.lastname = "Commander";
	ch.name = TranslateString("","Spanish");
	ch.lastname = TranslateString("","Commander");
	ch.id		= "SpainCommander";
	ch.model	= "Offic_spa_16";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	GiveItem2Character(ch, "pistol2");
	ch.equip.gun = "pistol2";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Enrique Padilla_dialog.c";
	ch.greeting = "Gr_isla muelle soldier";
	ch.rank 	= 10;
	ch.reputation = "None";
	ch.experience = "80";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "2";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "2";
	ch.skill.Repair = "1";
	ch.skill.Defence = "4";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "3";
	ch.money = "1000";
	LAi_SetStayType(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_SOLDIERS");
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	AddGameCharacter(n, ch);
	
	// PadreGerardo
	ch.old.name = "Padre";
	ch.old.lastname = "Gerardo";
	ch.name = TranslateString("","Padre");
	ch.lastname = TranslateString("","Gerardo");
	ch.id		= "PadreGerardo";
	ch.model	= "PadreGerardo";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "bladeclub");
	ch.equip.blade = "bladeclub";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Padre Gerardo_dialog.c";
	ch.greeting = "Gr_isla muelle soldier";
	ch.rank 	= 10;
	ch.reputation = "None";
	ch.experience = "80";
	ch.skill.Leadership = "7";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "2";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "2";
	ch.skill.Repair = "1";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "9";
	ch.money = "0";
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 1000.0, 1000.0);
	AddGameCharacter(n, ch);

	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","Soldier");
	ch.lastname = TranslateString("","");
	ch.id		= "Shipguard1";
	ch.model	= 1; // PB
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Shipguard_dialog.c";
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
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);
	
	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","Soldier");
	ch.lastname = TranslateString("","");
	ch.id		= "Shipguard2";
	ch.model	= 1; // PB
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
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
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	//====================================================================================================================
}
