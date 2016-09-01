void CreateTempQuestEnemyCharacters(ref n)
{

	object chobj;
	ref ch;

	makeref(ch, chobj);

// Guard 1
	ch.old.name = "Guard";
	ch.old.lastname = "1";
	ch.name = TranslateString("","Guard");
	ch.lastname = "1";
	ch.id		= "Spanish_guard1";
	ch.model	= "soldier_spa6_17";
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = SPAIN;
	GiveItem2Character(ch, "pistolmket");
	ch.equip.gun = "pistolmket";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "musketbullets", 1 + rand(2)); }
	//JRH ammo mod <--	
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Havana_prison";
	ch.location.group = "goto";
	ch.location.locator = "goto14";
	ch.Dialog.Filename = "Soldier_dialog.c";
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
//	LAi_NoRebirthEnable(ch);
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;
	LAi_group_MoveCharacter(ch, "SPAIN_SOLDIERS");
	ch.greeting = "Gr_isla muelle soldier";
	AddGameCharacter(n, ch);

// Guard 2
	ch.old.name = "Guard";
	ch.old.lastname = "2";
	ch.name = TranslateString("","Guard");
	ch.lastname = "2";
	ch.id		= "Spanish_guard2";
	ch.model	= "soldier_spa5_17";
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = SPAIN;
	GiveItem2Character(ch, "pistolmket");
	ch.equip.gun = "pistolmket";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "musketbullets", 1 + rand(2)); }
	//JRH ammo mod <--	
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Havana_prison";
	ch.location.group = "goto";
	ch.location.locator = "goto16";
	ch.Dialog.Filename = "Soldier_dialog.c";
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
//	LAi_NoRebirthEnable(ch);
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;
	LAi_group_MoveCharacter(ch, "SPAIN_SOLDIERS");
	ch.greeting = "Gr_isla muelle soldier";
	AddGameCharacter(n, ch);

// Guard 3
	ch.old.name = "Guard";
	ch.old.lastname = "3";
	ch.name = TranslateString("","Guard");
	ch.lastname = "3";
	ch.id		= "Spanish_guard3";
	ch.model	= "soldier_spa4_17";
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = SPAIN;
	GiveItem2Character(ch, "pistolmket");
	ch.equip.gun = "pistolmket";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "musketbullets", 1 + rand(2)); }
	//JRH ammo mod <--	
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Havana_prison";
	ch.location.group = "goto";
	ch.location.locator = "goto17";
	ch.Dialog.Filename = "Soldier_dialog.c";
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
//	LAi_NoRebirthEnable(ch);
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;
	LAi_group_MoveCharacter(ch, "SPAIN_SOLDIERS");
	ch.greeting = "Gr_isla muelle soldier";
	AddGameCharacter(n, ch);

// Havana prison commandant
	ch.old.name = "Argibaio";
	ch.old.lastname = "Galindez";
	ch.name 	= TranslateString("","Argibaio");
	ch.lastname 	= TranslateString("","Galindez");
	ch.id		= "Havana Prison Commandant";
	ch.model	= "offic_spa_17";
	ch.sex = "man";
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, true);
	ch.location	= "Havana_prison";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Havana Prison Commandant_dialog.c";
	ch.nation = SPAIN;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "4";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "2000";
	LAi_SetHuberType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
//	LAi_group_MoveCharacter(ch, "SPAIN_SOLDIERS");
	ch.greeting = "Gr_christofor manuel de alencar";
	GiveItem2Character(ch, "blade47");
	ch.equip.blade = "blade47";
	GiveItem2Character(ch, "Pistol2");
	ch.equip.gun = "Pistol2";
	LAi_SetHP(ch, 180.0, 180.0);
	ch.questchar = true;
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
     //JRH ammo mod <--
//	ch.isSoldier = true; // KK
	AddGameCharacter(n, ch);

// Havana prison warden
	ch.old.name = "Eldo";
	ch.old.lastname = "Fiz";
	ch.name = TranslateString("","Eldo");
	ch.lastname 	= TranslateString("","Fiz");
	ch.id		= "Warden";
	ch.model	= "fatman1";
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = SPAIN;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Havana_prison";
	ch.location.group = "goto";
	ch.location.locator = "goto22";
	ch.Dialog.Filename = "Warden_dialog.c";
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
	GiveItem2Character(ch, "jerkin");
	LAi_NoRebirthEnable(ch);
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;
//	LAi_group_MoveCharacter(ch, "SPAIN_SOLDIERS");
	ch.greeting = "Gr_isla muelle soldier";
	AddGameCharacter(n, ch);

// Slave camp commander
	ch.old.name = "Javier";
	ch.old.lastname = "Mendieta";
	ch.name = TranslateString("","Javier");
	ch.lastname 	= TranslateString("","Mendieta");
	ch.id		= "Slave Camp Commandant";
	ch.model	= "offic_spa_17";
	ch.sex = "man";
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, true);
	ch.location	= "Smugglers_Fort";
	ch.location.group = "goto";
	ch.location.locator = "goto19";
	ch.Dialog.Filename = "Slave_Commandant_dialog.c";
	ch.nation = SPAIN;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "3";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "500";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
//	LAi_group_MoveCharacter(ch, "SPAIN_SOLDIERS");
//	ch.greeting = "Gr_christofor manuel de alencar";
	GiveItem2Character(ch, "blade47+1");
	ch.equip.blade = "blade47";
	GiveItem2Character(ch, "Pistol2");
	ch.equip.gun = "Pistol2";
	LAi_SetHP(ch, 180.0, 180.0);
	ch.questchar = true;
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
     //JRH ammo mod <--
//	ch.isSoldier = true; // KK
	AddGameCharacter(n, ch);

	ch.old.name = "Felipe";
	ch.old.lastname = "Becerra";
	ch.name = TranslateString("","Felipe");
	ch.lastname = TranslateString("","Becerra");
	SetRankTitle(ch, TranslateString("", "Teniente"));
	ch.id		= "Spanish_Captain1";
	ch.nation	= SPAIN;
	ch.model	= "Offic_spa_17";
	ch.sound_type = "soldier";
//	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "Quest_ships";
	ch.location.locator = "quest_ship_12";
	ch.Dialog.Filename = "Spanish_Captain1_dialog.c";
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
	ch.Ship.Name = "Sabina";
	ch.Ship.Type = "FastGalleon2";
	ch.Ship.Stopped = true;
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Bolimirus";
	ch.old.lastname = "Carretero";
	ch.name = TranslateString("","Bolimirus");
	ch.lastname = TranslateString("","Carretero");
	ch.id		= "Spanish_Captain2";
	ch.nation	= SPAIN;
	ch.model	= "9JdSpa";
	ch.sound_type = "soldier";
//	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade44+1");
	ch.equip.blade = "blade44";
	GiveItem2Character(ch, "PiratesPistol");
	ch.equip.gun = "PiratesPistol";
	ch.questchar = true;
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
     //JRH ammo mod <--
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location	= "Havana_tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit4";
	ch.Dialog.Filename = "Spanish_Captain2_dialog.c";
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
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.Ship.Name = "Siroco";
	ch.Ship.Type = "SP_CastelF";
	ch.Ship.Stopped = true;
	LAi_SetHP(ch, 200.0, 200.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	SetRank(ch, SPAIN, 3);
	AddGameCharacter(n, ch);

	ch.old.name = "Esteban";
	ch.old.lastname = "Rovapera";
	ch.name = TranslateString("","Esteban");
	ch.lastname = TranslateString("","Rovapera");
	ch.id		= "Spanish_Captain3";
	ch.nation	= SPAIN;
	ch.model	= "Man9";
	ch.sound_type = "soldier";
//	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade16");
	ch.equip.blade = "blade16";
	GiveItem2Character(ch, "pistol2+1");
	ch.equip.gun = "pistol2";
	ch.questchar = true;
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
     //JRH ammo mod <--
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location	= "Santiago_port";
	ch.location.group = "ships_other";
	ch.location.locator = "ship_3";
	ch.Dialog.Filename = "Spanish_Captain3_dialog.c";
	ch.rank 	= 4;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "2";
	ch.skill.Repair = "2";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "2";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.money = "1000";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.Ship.Name = "Tonina";
	ch.Ship.Type = "Shnyava2";
	ch.Ship.Stopped = true;
	LAi_SetHP(ch, 200.0, 200.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	SetRank(ch, SPAIN, 3);
	AddGameCharacter(n, ch);

	ch.old.name = "Mauricio";
	ch.old.lastname = "Juradu";
	ch.name = TranslateString("","Mauricio");
	ch.lastname = TranslateString("","Juradu");
	ch.id		= "Mauricio Juradu";
	ch.model = "sailor14";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "Santo_Domingo_Tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit13";
	ch.Dialog.Filename = "Mauricio Juradu_dialog.c";
	ch.greeting = "Gr_andre juliao";
	GiveItem2Character(ch, "blade10");
	ch.equip.blade = "blade10";
	GiveItem2Character(ch, "PiratesPistol+1");
	ch.equip.gun = "PiratesPistol";
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
     //JRH ammo mod <--
	ch.nation = SPAIN;
	ch.rank 	= 4;
	ch.reputation = "34";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "5";
	ch.perks.list.BasicDefence = true;
	ch.money = "500";
	ch.quest.meeting = "0";
	ch.questchar = true;
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.Ship.Name = "Jacqueline";
	ch.Ship.Type = "Tartane2";
	ch.Ship.Stopped = true;
	LAi_SetHP(ch, 160.0, 160.0);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	LAi_NoRebirthEnable(ch); //NK fix so he doesn't reappear and attack again after killing him.
	AddGameCharacter(n, ch);

// Assassin
	ch.old.name = "Malbert";
	ch.old.lastname = "Sangier";
	ch.name = TranslateString("","Malbert");
	ch.lastname = "Sangier";
	ch.id		= "Malbert Sangier";
	ch.model	= "Soldier_Spa5_17";
//	ch.model	= "will_3";
	ch.sound_type = "male_citizen";
	ch.sex = "man";
	ch.nation = FRANCE;
	GiveItem2Character(ch, "pistol11+3");
	ch.equip.gun = "pistol11";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2)); }
	//JRH ammo mod <--	
	GiveItem2Character(ch, "bladeC33+2");
	ch.equip.blade = "bladeC33";
	GiveItem2Character(ch, "commonarmor");
	GiveItem2Character(ch, "SignetRing");
	ch.location = "none";
	ch.location.group = "goto";
	ch.location.locator = "none";
	ch.Dialog.Filename = "Malbert Sangier_dialog.c";
	ch.greeting = "Gr_isla muelle soldier";
//	ch.greeting = "Gr_Lucien Bescanceny";
	ch.rank 	= 6;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "4";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "6";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "5";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	Ch.Perks.list.Toughness = true;
	Ch.Perks.list.Gunman = true;
	ch.money = "1500";
//	LAi_NoRebirthEnable(ch);
	LAi_SetCitizenType(ch);
//	DeleteAttribute(ch, "isSoldier");
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 200.0, 200.0);
	ch.questchar = true;
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	AddGameCharacter(n, ch);

	ch.old.name = "Randolph";
	ch.old.lastname = "Waghorn";
	ch.name = TranslateString("","Randolph");
	ch.lastname = TranslateString("","Waghorn");
	SetRankTitle(ch, TranslateString("", "Captain"));
	ch.id		= "Convoy_Captain1";
	ch.nation	= ENGLAND;
	ch.model	= "Eitc_cpt1_47";
	ch.sound_type = "soldier";
//	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade22+2");
	ch.equip.blade = "blade22";
	GiveItem2Character(ch, "Pistol2+2");
	ch.equip.gun = "Pistol2";
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
     //JRH ammo mod <--
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "Quest_ships";
	ch.location.locator = "quest_ship_1";
	ch.Dialog.Filename = "English_Captain_dialog.c";
	ch.rank 	= 4;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "6";
	ch.skill.Accuracy = "6";
	ch.skill.Cannons = "6";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "3";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "7";
	ch.skill.Sneak = "1";
	ch.money = "4000";
	ch.Ship.Name = "Phaeton";
	ch.Ship.Type = "RN_WarGalleon";
	ch.Ship.Stopped = true;
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 400.0, 400.0);
	ch.skipRM = true; // PB: Skip Relations Mod
	ch.questchar = true;//MAXIMUS: identifier for captives
	ch.fantomtype = "trade"; // Make sure he doesn't fly naval flag or have naval boarders
	AddGameCharacter(n, ch);

	ch.old.name = "Leonard";
	ch.old.lastname = "Bowyer";
	ch.name = TranslateString("","Leonard");
	ch.lastname = TranslateString("","Bowyer");
	SetRankTitle(ch, TranslateString("", "Captain"));
	ch.id		= "Convoy_Captain2";
	ch.nation	= ENGLAND;
	ch.model	= "Eitc_cpt2_47";
	ch.sound_type = "soldier";
//	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade22+2");
	ch.equip.blade = "blade22";
	GiveItem2Character(ch, "Pistol3+2");
	ch.equip.gun = "Pistol3";
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolgrapes", 1 + rand(2));
	}
     //JRH ammo mod <--
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "Quest_ships";
	ch.location.locator = "quest_ship_2";
	ch.Dialog.Filename = "English_Captain_dialog.c";
	ch.rank 	= 4;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "8";
	ch.skill.Fencing = "9";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "9";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "3";
	ch.skill.Defence = "7";
	ch.skill.Commerce = "7";
	ch.skill.Sneak = "1";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	Ch.Perks.list.Toughness = true;
	ch.money = "4000";
	ch.Ship.Name = "Assurance";
	ch.Ship.Type = "RN_WarGalleon";
	ch.Ship.Stopped = true;
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 400.0, 400.0);
	ch.skipRM = true; // PB: Skip Relations Mod
	ch.questchar = true;//MAXIMUS: identifier for captives
	ch.fantomtype = "trade"; // Make sure he doesn't fly naval flag or have naval boarders
	AddGameCharacter(n, ch);

	ch.old.name = "Marvin";
	ch.old.lastname = "Corker";
	ch.name = TranslateString("","Marvin");
	ch.lastname = TranslateString("","Corker");
	SetRankTitle(ch, TranslateString("", "Captain"));
	ch.id		= "Convoy_Captain3";
	ch.nation	= ENGLAND;
	ch.model	= "Eitc_lt1_47";
	ch.sound_type = "soldier";
//	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "MerchantsBlade");
	ch.equip.blade = "MerchantsBlade";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "Quest_ships";
	ch.location.locator = "quest_ship_3";
	ch.Dialog.Filename = "English_Captain_dialog.c";
	ch.rank 	= 4;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "3";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "5";
	ch.skill.Sneak = "1";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.money = "2000";
	ch.Ship.Name = "Cygnet";
	ch.Ship.Type = "Pinnace1";
	ch.Ship.Stopped = true;
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 400.0, 400.0);
	ch.skipRM = true; // PB: Skip Relations Mod
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "James";
	ch.old.lastname = "Haresign";
	ch.name = TranslateString("","James");
	ch.lastname = TranslateString("","Haresign");
	SetRankTitle(ch, TranslateString("", "Captain"));
	ch.id		= "Convoy_Captain4";
	ch.nation	= ENGLAND;
	ch.model	= "Eitc_lt3_47";
	ch.sound_type = "soldier";
//	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "MerchantsBlade");
	ch.equip.blade = "MerchantsBlade";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "Quest_ships";
	ch.location.locator = "quest_ship_4";
	ch.Dialog.Filename = "English_Captain_dialog.c";
	ch.rank 	= 4;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "3";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "5";
	ch.skill.Sneak = "1";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.money = "2000";
	ch.Ship.Name = "Sirius";
	ch.Ship.Type = "PinnaceMerchant";
	ch.Ship.Stopped = true;
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 400.0, 400.0);
	ch.skipRM = true; // PB: Skip Relations Mod
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);
}