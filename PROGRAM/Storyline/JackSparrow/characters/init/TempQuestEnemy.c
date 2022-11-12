void CreateTempQuestEnemyCharacters(ref n)
{
	object chobj;
	ref ch;
	makeref(ch, chobj);

	ch.old.name = "Ronald";
	ch.old.lastname = "Blacklock";
	ch.name 	= TranslateString("", "Ronald");
	ch.lastname 	= TranslateString("", "Blacklock");
	ch.id		= "Greenford Prison Commendant";
	ch.model	= "Offic_eng_18";
	ch.sex = "man";
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, true);
	ch.location	= "Greenford_prison";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Greenford Commander_dialog.c";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "9";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "6";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	LAi_SetSitType(ch); //CTM
	ch.greeting = "Gr_Greenford Commander";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	GiveItem2Character(ch, "Pistol1");
	ch.equip.gun = "Pistol1";
	AddGameCharacter(n, ch);
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--

	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name 	= TranslateString("", "Soldier");
	ch.lastname 	= "";
	ch.id		= "Eng_soldier_39";
	ch.model	= "soldier_eng5";
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "soldier_dialog.c";
	ch.rank 	= 1;
	ch.nation = ENGLAND;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "6";
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
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.greeting = "Gr_Greenford Soldier";
	AddGameCharacter(n, ch);

	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name 	= TranslateString("", "Soldier");
	ch.lastname 	= "";
	ch.id		= "Eng_soldier_38";
	ch.model	= "soldier_eng5";
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "soldier_dialog.c";
	ch.rank 	= 1;
	ch.nation = ENGLAND;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "6";
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
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.greeting = "Eng_m_c_065";
	AddGameCharacter(n, ch);

	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Soldier");
	ch.lastname = "";
	ch.id		= "guard_church1";
	ch.model = Nations[ENGLAND].fantomModel.m2; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	ch.act.escape = 0;
	ch.activity_begin = "0";
	ch.activity_end = "24";
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade5");
	ch.equip.blade = "blade5";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Quest_ANIMISTS_dialog.c";
	ch.greeting = "Gr_Quest_ANIMISTS";
	ch.Ship.Name = "Hundred Devils"; // KK
	ch.Ship.Type = "Barque2"; // PRS3
	ch.Ship.Stopped = true;
	ch.skipRM = true; // PB: Skip Relations Mod
	ch.Flags.Pirate = 6; // GR: Animists Pirate Flag
	ch.Flags.Pirate.texture = 1;
// KK -->
	ch.Ship.EmblemedSails.normalTex = "sail_whole_red_plain.tga"; // PB
	ch.Ship.EmblemedSails.nationFileName = "sail_whole_red_plain.tga"; // PB
	ch.nosurrender = 2;
	ch.boardingmodels = "OUTLAWS";
// <-- KK
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	ch.rank 	= 1;
	ch.reputation = "22";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "4";
	ch.skill.Cannons = "6";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Soldier");
	ch.lastname = "";
	ch.id		= "guard_church2";
	ch.model = Nations[ENGLAND].fantomModel.m3; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	ch.act.escape = 0;
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade5");
	ch.equip.blade = "blade5";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Quest_ANIMISTS_dialog.c";
	ch.old.Dialog.Filename = ch.Dialog.Filename; // KK
	ch.greeting = "Gr_Quest_ANIMISTS";
	ch.Ship.Name = "666"; // KK
	ch.Ship.Type = "Brig2"; // PRS3
	ch.Ship.Stopped = true;
	ch.skipRM = true; // PB: Skip Relations Mod
	ch.Flags.Pirate = 6; // GR: Animists Pirate Flag
	ch.Flags.Pirate.texture = 1;
// KK -->
	ch.Ship.EmblemedSails.normalTex = "sail_whole_red_plain.tga"; // PB
	ch.Ship.EmblemedSails.nationFileName = "sail_whole_red_plain.tga"; // PB
	ch.nosurrender = 2;
	ch.boardingmodels = "OUTLAWS";
// <-- KK
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	ch.rank 	= 1;
	ch.reputation = "22";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "4";
	ch.skill.Cannons = "6";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Soldier");
	ch.lastname = "";
	ch.id		= "guard_church3";
	ch.model = Nations[ENGLAND].fantomModel.m4; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	ch.act.escape = 0;
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade5");
	ch.equip.blade = "blade5";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Quest_ANIMISTS_dialog.c";
	ch.greeting = "Gr_Quest_ANIMISTS";
	ch.rank 	= 1;
	ch.reputation = "22";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "4";
	ch.skill.Cannons = "6";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Lieutenant";
	ch.old.lastname = "Harris";
	ch.name = TranslateString("", "Lieutenant");
	ch.lastname = TranslateString("", "Harris");
	ch.id		= "Lighthouse_officer";
	ch.model	= 1; // PB
	ch.nation = ENGLAND;
	ch.sex = "man";
	ch.sound_type = "soldier";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.Dialog.Filename = "Greenford Commander_dialog.c";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "9";
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
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.greeting = "Gr_Greenford Commander";
	AddGameCharacter(n, ch);

	ch.old.name = "Captain";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Captain");
	ch.lastname = "";
	ch.id		= "Quest_frigate_captain";
	ch.nation	= FRANCE;
	ch.model	= "capitan";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "Quest_ships";
	ch.location.locator = "quest_ship_12";
	ch.Dialog.Filename = "falaise de fleur soldier_dialog.c";
	ch.rank 	= 4;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "1000";
	ch.Ship.Name = "Volcano";
	ch.Ship.Type = "Battleship1"; // PRS3
	ch.Ship.Stopped = true;
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS24;
//	ch.quest.killed.pirates = "0";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

// Sumbhajee quest -->
					// Bernardo Gamboa - испанец. корсар на службе голландии
	ch.old.name = "Spanish";
	ch.old.lastname = "Lieutenant";
	ch.name = TranslateString("Spanish", "Lieutenant");
	ch.lastname = "";
	ch.id		= "Bernardo Gamboa";
	ch.model = "spa_lut1_18";
	ch.sex = "man";
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.Dialog.Filename = "Bernardo Gamboa_dialog.c";
	ch.location	= "Gamboa_ship";
	ch.location.group = "goto";
	ch.location.locator = "goto4";
	ch.Ship.Name = "Neptunus";
	ch.Ship.Type = "SP_Neptunus"; // PRS3
	ch.Ship.Stopped = true;
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	ch.rank 	= 1;
	ch.reputation = "22";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "4";
	ch.skill.Cannons = "6";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.money = "10";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_Bernardo Gamboa";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Port Solider
	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Soldier");
	ch.lastname = "";
	ch.id		= "Sp_pris_guard1";
	ch.model = "soldier_spa3_18";
	ch.sex = "man";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.greeting = "Gr_isla muelle soldier";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.rank 	= 1;
	ch.reputation = "26";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "2";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Port Solider
	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Soldier");
	ch.lastname = "";
	ch.id		= "Sp_pris_guard2";
	ch.model = "soldier_spa4_18";
	ch.sex = "man";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.greeting = "Gr_isla muelle soldier";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.rank 	= 1;
	ch.reputation = "26";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "2";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	//Soldier in prison
	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Soldier");
	ch.lastname = "";
	ch.id		= "Havana_Prison_Sold1";
	ch.model	= 6; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "Havana_prison";
	ch.location.group = "goto";
	ch.location.locator = "goto16";
	ch.Dialog.Filename = "isla muelle soldier_dialog.c";
	ch.nation = SPAIN;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "6";
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
	LAi_group_MoveCharacter(ch, "SPAIN_SOLDIERS");
	ch.greeting = "Gr_isla muelle soldier"; // was "Gr_Patrol"
	AddGameCharacter(n, ch);

	//Soldier in prison
	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Soldier");
	ch.lastname = "";
	ch.id		= "Havana_Prison_Sold2";
	ch.model	= 4; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "Havana_prison";
	ch.location.group = "goto";
	ch.location.locator = "goto14";
	ch.Dialog.Filename = "isla muelle soldier_dialog.c";
	ch.nation = SPAIN;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "6";
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
	LAi_group_MoveCharacter(ch, "SPAIN_SOLDIERS");
	ch.greeting = "Gr_isla muelle soldier"; // was "Gr_Patrol"
	AddGameCharacter(n, ch);

	ch.old.name = "Prison";
	ch.old.lastname = "Commendant";
	ch.name 	= TranslateString("Prison", "Commendant");
	ch.lastname 	= "";
	ch.id		= "Havana Prison Commendant";
	ch.model	= "spa_cpt_18";
	ch.sex = "man";
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, true);
	ch.location	= "Havana_prison";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Spanish Prison_dialog.c";
	ch.nation = SPAIN;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "9";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "6";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	LAi_SetSitType(ch); //CTM
	ch.greeting = "Gr_Greenford Commander";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	GiveItem2Character(ch, "Pistol1");
	ch.equip.gun = "Pistol1";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	AddGameCharacter(n, ch);

	ch.old.name = "Spanish";
	ch.old.lastname = "Officer";
	ch.name 	= TranslateString("Spanish", "Officer");
	ch.lastname 	= "";
	ch.id		= "random_spain_off";
	ch.model	= "spa_cpt1_18";
	ch.sex = "man";
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, true);
	//ch.location	= "";
	//ch.location.group = "";
	//ch.location.locator = "";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Rdm Spanish_dialog.c";
	ch.nation = SPAIN;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "9";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "6";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	//LAi_SetSitType(ch); //CTM
	ch.greeting = "Gr_Greenford Commander";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	GiveItem2Character(ch, "Pistol1");
	ch.equip.gun = "Pistol1";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	AddGameCharacter(n, ch);

					// Corentin Lucay - помощник пердыдущего перса
	ch.old.name = "Spanish";
	ch.old.lastname = "Midshipman";
	ch.name = TranslateString("Spanish", "Midshipman");
	ch.lastname = "";
	ch.id		= "Corentin Lucay";
	ch.model = "spa_mds1_18";
	ch.sex = "man";
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.Dialog.Filename = "Corentin Lucay_dialog.c";
	ch.greeting = "Gr_Corentin Lucay";
	ch.location	= "Gamboa_ship";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
	ch.rank 	= 1;
	ch.reputation = "26";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "2";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);
// Sumbhajee quest <--

// Sao Feng quest -->
	ch.old.name = "Crewmember";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Crewmember");
	ch.lastname = "";
	ch.id		= "Larry";
	ch.model	= "Sailor16";
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "goto";
	ch.location.locator = "character7";
	ch.Dialog.Filename = "";
	ch.nation = PIRATE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Mr.";
	ch.old.lastname = "Mercer";
	ch.name = TranslateString("", "Mr.");
	ch.lastname = TranslateString("", "Mercer");
	ch.id		= "Mr Mercer";
	ch.model	= "Corsair1";
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "goto";
	ch.location.locator = "character7";
	ch.Dialog.Filename = "Lieutenant Bligh_dialog.c";
	ch.nation = PIRATE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Pirate";
	ch.old.lastname = "3";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = TranslateString("", "3");
	ch.id		= "Pirates_3";
	ch.model	= "corsair1";
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "goto";
	ch.location.locator = "character7";
	ch.Dialog.Filename = "";
	ch.nation = PIRATE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);

	// Gentleman Jocard (White).
	ch.old.name = "Gentleman";
	ch.old.lastname = "Jocard";
	ch.name = TranslateString("", "Gentleman");
	ch.lastname = TranslateString("", "Jocard");
	ch.id		= "Gentleman Jocard (White)";
	ch.model = "Huber_Fra4_17";
	ch.sex = "man";
	ch.act.type = "merchant";
	ch.loyality = 10;
	ch.alignment = "good";
	ch.nation	= PIRATE;
	GiveItem2Character(ch, "blade12");
	ch.equip.blade = "blade12";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "none"; // KK
	ch.location.group = ""; // KK
	ch.location.locator = ""; // KK
	ch.homelocation	= "QC_town";
	ch.homelocation.group = "goto";
	ch.homelocation.locator = "goto5";
	ch.homestate = "citizen";
	ch.Dialog.Filename = "Gentleman Jocard (White)_dialog.c";
	ch.rank 	= 15;
	ch.reputation = "23";
	TakeNItems(ch,"medical1", Rand(4)+1);
	ch.experience = CalculateExperienceFromRank(4)+ (CalculateExperienceFromRank(4)/10 + rand(4000));
	ch.skill.Leadership = "9";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "8";
	ch.skill.Grappling = "8";
	ch.skill.Repair = "8";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "10";
	ch.skill.Sneak = "0";
	ch.money = 10000;
	ch.perks.list.ShipSpeedUp = true;
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Artois Voysey";
	ch.quest.officertype = OFFIC_TYPE_NAVIGATOR; // added by MAXIMUS
	AddGameCharacter(n, ch);
}
