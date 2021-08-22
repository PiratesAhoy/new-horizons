void CreateTempQuestEnemyCharacters(ref n)
{

	object chobj;
	ref ch;
	makeref(ch, chobj);

// Guard 1
	ch.old.name = "Guard";
	ch.old.lastname = "1";
	ch.name = TranslateString("", "Guard");
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
	ch.name = TranslateString("", "Guard");
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
	ch.name = TranslateString("", "Guard");
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
	ch.old.name = "Atanagildo";
	ch.old.lastname = "Galíndez";
	ch.name 	= TranslateString("", "Atanagildo");
	ch.lastname 	= TranslateString("", "Galíndez");
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
	ch.name = TranslateString("", "Eldo");
	ch.lastname 	= TranslateString("", "Fiz");
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
	ch.name = TranslateString("", "Javier");
	ch.lastname 	= TranslateString("", "Mendieta");
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
	
	if (ENABLE_WEAPONSMOD) GiveItem2Character(ch, "blade47+1");
	else GiveItem2Character(ch, "blade47");
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
	ch.name = TranslateString("", "Felipe");
	ch.lastname = TranslateString("", "Becerra");
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
	ch.Ship.Type = "FastGalleon4";
	ch.Ship.Stopped = true;
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.nation = SPAIN;
	SetRank(ch, SPAIN, 4);
	ch.professionalnavy = ch.nation;
	ch.quest.officertype = OFFIC_TYPE_CAPNAVY;
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Basilio";
	ch.old.lastname = "Carretero";
	ch.name = TranslateString("", "Basilio");
	ch.lastname = TranslateString("", "Carretero");
	ch.id		= "Spanish_Captain2";
	ch.nation	= SPAIN;
	ch.model	= "9JdSpa";
	ch.sound_type = "soldier";
//	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	if (ENABLE_WEAPONSMOD)
	{
		GiveItem2Character(ch, "blade44+1");
		GiveItem2Character(ch, "pistol27+1");
	}
	else
	{
		GiveItem2Character(ch, "blade44");
		GiveItem2Character(ch, "pistol27");
	}
	ch.equip.blade = "blade44";
	ch.equip.gun = "pistol27";
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
	ch.name = TranslateString("", "Esteban");
	ch.lastname = TranslateString("", "Rovapera");
	ch.id		= "Spanish_Captain3";
	ch.nation	= SPAIN;
	ch.model	= "Man9";
	ch.sound_type = "soldier";
//	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade16");
	ch.equip.blade = "blade16";
	if (ENABLE_WEAPONSMOD) GiveItem2Character(ch, "pistol2+1");
	else GiveItem2Character(ch, "pistol2");
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
	ch.name = TranslateString("", "Mauricio");
	ch.lastname = TranslateString("", "Juradu");
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
	if(ENABLE_WEAPONSMOD)
	{
		GiveItem2Character(ch, "PiratesPistol+1");
	}
	else
	{
		GiveItem2Character(ch, "PiratesPistol");
	}
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
	ch.name = TranslateString("", "Malbert");
	ch.lastname = TranslateString("", "Sangier");
	ch.id		= "Malbert Sangier";
	ch.model	= "Soldier_Spa5_17";
//	ch.model	= "will_3";
	ch.sound_type = "male_citizen";
	ch.sex = "man";
	ch.nation = FRANCE;
	if(ENABLE_WEAPONSMOD)
	{
		GiveItem2Character(ch, "bladeC33+2");
		GiveItem2Character(ch, "pistol11+3");
	}
	else
	{
		GiveItem2Character(ch, "bladeC33");
		GiveItem2Character(ch, "pistol11");
	}
	ch.equip.gun = "pistol11";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2)); }
	//JRH ammo mod <--	
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
	ch.name = TranslateString("", "Randolph");
	ch.lastname = TranslateString("", "Waghorn");
	SetRankTitle(ch, TranslateString("", "Captain"));
	ch.id		= "Convoy_Captain1";
	ch.nation	= ENGLAND;
	ch.model	= "Eitc_cpt1_47";
	ch.sound_type = "soldier";
//	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	ch.loyality = 5;
	ch.alignment = "bad";
	if(ENABLE_WEAPONSMOD)
	{
		GiveItem2Character(ch, "blade22+2");
		GiveItem2Character(ch, "Pistol2+2");
	}
	else
	{
		GiveItem2Character(ch, "blade22");
		GiveItem2Character(ch, "Pistol2");
	}
	ch.equip.blade = "blade22";
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
	ch.Ship.crew.morale = 65;
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 400.0, 400.0);
	ch.skipRM = true; // PB: Skip Relations Mod
	ch.questchar = true;//MAXIMUS: identifier for captives
	ch.fantomtype = "trade";	// Make sure he doesn't fly naval flag or have naval boarders
	ch.canhire = true;		// Can be hired after being captured
	AddGameCharacter(n, ch);

	ch.old.name = "Leonard";
	ch.old.lastname = "Bowyer";
	ch.name = TranslateString("", "Leonard");
	ch.lastname = TranslateString("", "Bowyer");
	SetRankTitle(ch, TranslateString("", "Captain"));
	ch.id		= "Convoy_Captain2";
	ch.nation	= ENGLAND;
	ch.model	= "Eitc_cpt2_47";
	ch.sound_type = "soldier";
//	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	ch.loyality = 5;
	ch.alignment = "bad";
	if(ENABLE_WEAPONSMOD)
	{
		GiveItem2Character(ch, "blade22+2");
		GiveItem2Character(ch, "Pistol3+2");
	}
	else
	{
		GiveItem2Character(ch, "blade22");
		GiveItem2Character(ch, "Pistol3");
	}
	ch.equip.blade = "blade22";
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
	ch.Ship.crew.morale = 65;
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 400.0, 400.0);
	ch.skipRM = true; // PB: Skip Relations Mod
	ch.questchar = true;//MAXIMUS: identifier for captives
	ch.fantomtype = "trade";	// Make sure he doesn't fly naval flag or have naval boarders
	ch.canhire = true;		// Can be hired if he surrenders
	AddGameCharacter(n, ch);

	ch.old.name = "Marvin";
	ch.old.lastname = "Corker";
	ch.name = TranslateString("", "Marvin");
	ch.lastname = TranslateString("", "Corker");
	SetRankTitle(ch, TranslateString("", "Captain"));
	ch.id		= "Convoy_Captain3";
	ch.nation	= ENGLAND;
	ch.model	= "Eitc_lt1_47";
	ch.sound_type = "soldier";
//	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	ch.loyality = 5;
	ch.alignment = "good";
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
	ch.canhire = true;		// Can be hired if he surrenders
	AddGameCharacter(n, ch);

	ch.old.name = "James";
	ch.old.lastname = "Haresign";
	ch.name = TranslateString("", "James");
	ch.lastname = TranslateString("", "Haresign");
	SetRankTitle(ch, TranslateString("", "Captain"));
	ch.id		= "Convoy_Captain4";
	ch.nation	= ENGLAND;
	ch.model	= "Eitc_lt3_47";
	ch.sound_type = "soldier";
//	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	ch.loyality = 5;
	ch.alignment = "good";
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
	ch.canhire = true;		// Can be hired if he surrenders
	AddGameCharacter(n, ch);

// French Guard 1
	ch.old.name = "Guard";
	ch.old.lastname = "1";
	ch.name = TranslateString("", "Guard");
	ch.lastname = TranslateString("", "1");
	ch.id		= "French_guard1";
	ch.model	= "Soldier_Fra_17";
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = FRANCE;
	GiveItem2Character(ch, "pistolmket");
	ch.equip.gun = "pistolmket";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "musketbullets", 1 + rand(2)); }
	//JRH ammo mod <--	
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Falaise De Fleur Soldier_dialog.c";
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "7";
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
	LAi_SetHP(ch, 240.0, 240.0);
	ch.questchar = true;
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);

// French Guard 2
	ch.old.name = "Guard";
	ch.old.lastname = "2";
	ch.name = TranslateString("", "Guard");
	ch.lastname = TranslateString("", "2");
	ch.id		= "French_guard2";
	ch.model	= "Soldier_Fra3_17";
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = FRANCE;
	GiveItem2Character(ch, "pistolmket");
	ch.equip.gun = "pistolmket";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "musketbullets", 1 + rand(2)); }
	//JRH ammo mod <--	
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Falaise De Fleur Soldier_dialog.c";
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "7";
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
	LAi_SetHP(ch, 240.0, 240.0);
	ch.questchar = true;
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);

// French Guard 3
	ch.old.name = "Guard";
	ch.old.lastname = "3";
	ch.name = TranslateString("", "Guard");
	ch.lastname = TranslateString("", "3");
	ch.id		= "French_guard3";
	ch.model	= "Soldier_Fra5_17";
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = FRANCE;
	GiveItem2Character(ch, "pistolmket");
	ch.equip.gun = "pistolmket";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "musketbullets", 1 + rand(2)); }
	//JRH ammo mod <--	
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Falaise De Fleur Soldier_dialog.c";
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "7";
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
	LAi_SetHP(ch, 240.0, 240.0);
	ch.questchar = true;
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);

	ch.old.name = "Guinemant";
	ch.old.lastname = "Lavignen";
	ch.name = TranslateString("", "Guinemant");
	ch.lastname = TranslateString("", "Lavignen");
	ch.id		= "French_Lieutenant";
	ch.nation	= FRANCE;
	ch.model	= "Offic_fra_17";
	ch.sound_type = "soldier";
//	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade9+1");
	ch.equip.blade = "blade9";
	GiveItem2Character(ch, "pistol8+1");
	ch.equip.gun = "pistol8";
	ch.questchar = true;
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
     //JRH ammo mod <--
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "French_Captain1_dialog.c";
	ch.rank 	= 4;
	ch.reputation = "55";
	ch.experience = "0";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "4";
	ch.skill.Cannons = "4";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "1000";
	ch.quest.officertype = OFFIC_TYPE_CAPNAVY;
	LAi_SetCivilianGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.Ship.Name = "Joli";
	ch.Ship.Type = "RN_RaaFrigate";
	ch.Ship.Stopped = true;
	ch.Ship.crew.morale = 65;
	LAi_SetHP(ch, 300.0, 300.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	SetRank(ch, FRANCE, 3);
	ch.professionalnavy = FRANCE;
	AddGameCharacter(n, ch);

	ch.old.name = "Valerian";
	ch.old.lastname = "Decaux";
	ch.name = TranslateString("", "Valerian");
	ch.lastname = TranslateString("", "Decaux");
	ch.id		= "French_Captain1";
	ch.nation	= FRANCE;
	ch.model	= "Gener_fra_16";
	ch.sound_type = "soldier";
//	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	ch.loyality = 10;
	ch.alignment = "good";
	if(ENABLE_WEAPONSMOD)
	{
		GiveItem2Character(ch, "blade25+2");
		GiveItem2Character(ch, "pistol2+3");
	}
	else
	{
		GiveItem2Character(ch, "blade25");
		GiveItem2Character(ch, "pistol2");
	}
		
	ch.equip.blade = "blade25";
	ch.equip.gun = "pistol2";
	GiveItem2Character(ch, "commonarmor");
	ch.questchar = true;
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
     //JRH ammo mod <--
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "French_Captain1_dialog.c";
	ch.rank 	= 4;
	ch.reputation = "45";
	ch.experience = "0";
	ch.skill.Leadership = "7";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "4";
	ch.skill.Cannons = "4";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "7";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "4000";
	ch.quest.officertype = OFFIC_TYPE_CAPNAVY;
	LAi_SetCivilianGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 400.0, 400.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	SetRank(ch, FRANCE, 5);
	ch.professionalnavy = FRANCE;
	AddGameCharacter(n, ch);

	ch.old.name = "Arnald";
	ch.old.lastname = "Rimeaux";
	ch.name = TranslateString("", "Arnald");
	ch.lastname = TranslateString("", "Rimeaux");
	ch.id		= "French_Captain2";
	ch.nation	= FRANCE;
	ch.model	= "Soldier_Fra4_17";
	ch.sound_type = "soldier";
//	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade9+1");
	ch.equip.blade = "blade9";
	GiveItem2Character(ch, "pistol7+2");
	ch.equip.gun = "pistol7";
	ch.questchar = true;
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
     //JRH ammo mod <--
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "French_Captain1_dialog.c";
	ch.rank 	= 4;
	ch.reputation = "45";
	ch.experience = "0";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "5";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "4000";
	ch.quest.officertype = OFFIC_TYPE_CAPNAVY;
	LAi_SetCivilianGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.Ship.Name = "Bolontaire";
	ch.Ship.Type = "FR_Frigate";
	ch.Ship.Stopped = true;
	ch.Ship.crew.morale = 60;
	LAi_SetHP(ch, 300.0, 300.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	SetRank(ch, FRANCE, 5);
	ch.professionalnavy = FRANCE;
	AddGameCharacter(n, ch);

	ch.old.name = "Bruyant";
	ch.old.lastname = "Moncoutie";
	ch.name = TranslateString("", "Bruyant");
	ch.lastname = TranslateString("", "Moncoutie");
	ch.id		= "French_Captain3";
	ch.nation	= FRANCE;
	ch.model	= "Soldier_Fra3_17";
	ch.sound_type = "soldier";
//	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade9+1");
	ch.equip.blade = "blade9";
	GiveItem2Character(ch, "pistol6+2");
	ch.equip.gun = "pistol6";
	ch.questchar = true;
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
     //JRH ammo mod <--
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "French_Captain1_dialog.c";
	ch.rank 	= 4;
	ch.reputation = "45";
	ch.experience = "0";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "5";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "4000";
	ch.quest.officertype = OFFIC_TYPE_CAPNAVY;
	LAi_SetCivilianGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.Ship.Name = "Salamine";
	ch.Ship.Type = "FR_Frigate";
	ch.Ship.Stopped = true;
	ch.Ship.crew.morale = 65;
	LAi_SetHP(ch, 300.0, 300.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	SetRank(ch, FRANCE, 5);
	ch.professionalnavy = FRANCE;
	AddGameCharacter(n, ch);

	ch.old.name = "Philip";
	ch.old.lastname = "de Malvoisin";
	ch.name = TranslateString("", "Philip");
	ch.lastname = TranslateString("", "de Malvoisin");
	ch.id		= "French_Contre-Amiral";
	ch.greeting = "Gr_Antoine Chamfort";
	SetRankTitle(ch, TranslateString("", "Chevalier"));
	ch.nation	= FRANCE;
	ch.model	= "LaCroix";
	ch.sound_type = "soldier";
//	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	if(ENABLE_WEAPONSMOD)
	{
		GiveItem2Character(ch, "blade9+1");
		GiveItem2Character(ch, "pistol9+3");
	}
	else
	{
		GiveItem2Character(ch, "blade9");
		GiveItem2Character(ch, "pistol9");
	}
	ch.equip.blade = "blade9";
	ch.equip.gun = "pistol9";
	GiveItem2Character(ch, "commonarmor");
	ch.questchar = true;
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
     //JRH ammo mod <--
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "French_Contre-Amiral_dialog.c";
	ch.rank 	= 4;
	ch.reputation = "35";
	ch.experience = "0";
	ch.skill.Leadership = "8";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "10";
	ch.skill.Accuracy = "10";
	ch.skill.Cannons = "10";
	ch.skill.Grappling = "8";
	ch.skill.Repair = "10";
	ch.skill.Defence = "10";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "10";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	Ch.Perks.list.Toughness = true;
	ch.money = "40000";
	ch.quest.officertype = OFFIC_TYPE_CAPNAVY;
	LAi_SetCivilianGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.Ship.Name = "Conquérante";
	ch.Ship.Type = "FR_Fleuron";
	ch.Ship.Stopped = true;
	ch.Ship.crew.morale = 65;
	LAi_SetHP(ch, 1000.0, 1000.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	SetRank(ch, FRANCE, 7);
	ch.professionalnavy = FRANCE;
	AddGameCharacter(n, ch);

	ch.old.name = "François-Louis";
	ch.old.middlename = "Rousselet";
	ch.old.lastname = "de Châteaurenault";
	ch.name = TranslateString("", "François-Louis");
	ch.middlename = TranslateString("", "Rousselet");
	ch.lastname = TranslateString("", "de Châteaurenault");
	ch.id		= "French_Amiral";
	SetRankTitle(ch, TranslateString("", "Chevalier"));
	ch.nation	= FRANCE;
//	ch.model	= "hugnt18";
	ch.model	= "Rousselet";
	ch.model.animation = "Rousselet";
	ch.sound_type = "soldier";
//	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	if(ENABLE_WEAPONSMOD)
	{
		GiveItem2Character(ch, "blade25+3");
		GiveItem2Character(ch, "pistol9+3");
	}
	else
	{
		GiveItem2Character(ch, "blade25");
		GiveItem2Character(ch, "pistol9");
	}
	ch.equip.blade = "blade25";
	ch.equip.gun = "pistol9";
	GiveItem2Character(ch, "commonarmor");
	ch.questchar = true;
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
     //JRH ammo mod <--
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "French_Captain1_dialog.c";
	ch.rank 	= 4;
	ch.reputation = "45";
	ch.experience = "0";
	ch.skill.Leadership = "9";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "9";
	ch.skill.Accuracy = "9";
	ch.skill.Cannons = "9";
	ch.skill.Grappling = "7";
	ch.skill.Repair = "10";
	ch.skill.Defence = "10";
	ch.skill.Commerce = "5";
	ch.skill.Sneak = "10";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	Ch.Perks.list.Toughness = true;
	Ch.Perks.list.IronWill = true;
	ch.money = "100000";
	ch.quest.officertype = OFFIC_TYPE_CAPNAVY;
	LAi_SetCivilianGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.Ship.Name = "Dauphin Royal";
	ch.Ship.Type = "FR_SoleilRoyal";
	ch.Ship.Stopped = true;
	ch.Ship.crew.morale = 75;
	LAi_SetHP(ch, 1000.0, 1000.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	SetRank(ch, FRANCE, 8);
	ch.professionalnavy = FRANCE;
	AddGameCharacter(n, ch);

// French Prison Guard 1
	ch.old.name = "Guard";
	ch.old.lastname = "1";
	ch.name = TranslateString("", "Guard");
	ch.lastname = TranslateString("", "1");
	ch.id		= "Fr_Prison_guard1";
	ch.model	= "Soldier_Fra_17";
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = FRANCE;
	SetRandomNameToCharacter(ch);
	GiveItem2Character(ch, "pistolmket");
	ch.equip.gun = "pistolmket";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "musketbullets", 1 + rand(2)); }
	//JRH ammo mod <--	
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Soldier_dialog.c";
	ch.rank 	= 1;
	ch.reputation = "None";
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
	ch.skill.Sneak = "1";
	ch.money = "10";
//	LAi_NoRebirthEnable(ch);
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 200.0, 200.0);
	ch.questchar = true;
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);

// French Prison Guard 2
	ch.old.name = "Guard";
	ch.old.lastname = "2";
	ch.name = TranslateString("", "Guard");
	ch.lastname = TranslateString("", "2");
	ch.id		= "Fr_Prison_guard2";
	ch.model	= "Soldier_Fra2_17";
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = FRANCE;
	SetRandomNameToCharacter(ch);
	GiveItem2Character(ch, "pistolmket");
	ch.equip.gun = "pistolmket";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "musketbullets", 1 + rand(2)); }
	//JRH ammo mod <--	
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Soldier_dialog.c";
	ch.rank 	= 1;
	ch.reputation = "None";
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
	ch.skill.Sneak = "1";
	ch.money = "10";
//	LAi_NoRebirthEnable(ch);
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 200.0, 200.0);
	ch.questchar = true;
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);

// French Prison Guard 3
	ch.old.name = "Guard";
	ch.old.lastname = "3";
	ch.name = TranslateString("", "Guard");
	ch.lastname = TranslateString("", "3");
	ch.id		= "Fr_Prison_guard3";
	ch.model	= "Soldier_Fra3_17";
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = FRANCE;
	SetRandomNameToCharacter(ch);
	GiveItem2Character(ch, "pistolmket");
	ch.equip.gun = "pistolmket";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "musketbullets", 1 + rand(2)); }
	//JRH ammo mod <--	
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Soldier_dialog.c";
	ch.rank 	= 1;
	ch.reputation = "None";
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
	ch.skill.Sneak = "1";
	ch.money = "10";
//	LAi_NoRebirthEnable(ch);
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 200.0, 200.0);
	ch.questchar = true;
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);

// French Prison Guard 4
	ch.old.name = "Guard";
	ch.old.lastname = "4";
	ch.name = TranslateString("", "Guard");
	ch.lastname = TranslateString("", "4");
	ch.id		= "Fr_Prison_guard4";
	ch.model	= "Offic_Fra_17";
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = FRANCE;
	SetRandomNameToCharacter(ch);
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Soldier_dialog.c";
	ch.rank 	= 1;
	ch.reputation = "None";
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
	ch.skill.Sneak = "1";
	ch.money = "10";
//	LAi_NoRebirthEnable(ch);
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 200.0, 200.0);
	ch.questchar = true;
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);
	AddGameCharacter(n, ch);

// French Fort Guard
	ch.old.name = "Guibert";
	ch.old.lastname = "Mollaret";
	ch.name = TranslateString("", "Guibert");
	ch.lastname = TranslateString("", "Mollaret");
	ch.id		= "Fort_guard";
	ch.model	= "Offic_Fra_17";
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = FRANCE;
	SetRandomNameToCharacter(ch);
	GiveItem2Character(ch, "blade13");
	ch.equip.blade = "blade13";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "guard_dialog.c";
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "5";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
//	LAi_NoRebirthEnable(ch);
	LAi_SetCivilianGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 200.0, 200.0);
	ch.questchar = true;
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);

	ch.old.name = "Guillaume";
	ch.old.lastname = "Suguenot";
	ch.name = TranslateString("", "Guillaume");
	ch.lastname = TranslateString("", "Suguenot");
	ch.id		= "French_Ambush_Captain1";
	ch.greeting = "Gr_Antoine Chamfort";
	ch.nation	= FRANCE;
	ch.model	= "Man10";
	ch.sound_type = "soldier";
//	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	if(ENABLE_WEAPONSMOD)
	{
		GiveItem2Character(ch, "blade25+2");
		GiveItem2Character(ch, "pistol5+2");
	}
	else
	{
		GiveItem2Character(ch, "blade25");
		GiveItem2Character(ch, "pistol5");
	}
	ch.equip.blade = "blade25";
	ch.equip.gun = "pistol5";
	GiveItem2Character(ch, "commonarmor");
	ch.questchar = true;
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
     //JRH ammo mod <--
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "French_Captain1_dialog.c";
	ch.rank 	= 4;
	ch.reputation = "35";
	ch.experience = "0";
	ch.skill.Leadership = "8";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "10";
	ch.skill.Accuracy = "10";
	ch.skill.Cannons = "10";
	ch.skill.Grappling = "8";
	ch.skill.Repair = "10";
	ch.skill.Defence = "10";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "10";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	Ch.Perks.list.Toughness = true;
	ch.money = "40000";
	ch.quest.officertype = OFFIC_TYPE_CAPNAVY;
	LAi_SetCivilianGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.Ship.Name = "Victorieuse";
	ch.Ship.Type = "Battleship2";
//	ch.Ship.Stopped = true;
	ch.Ship.crew.morale = 70;
	LAi_SetHP(ch, 1000.0, 1000.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	SetRank(ch, FRANCE, 6);
	ch.professionalnavy = FRANCE;
	AddGameCharacter(n, ch);

	ch.old.name = "Louis";
	ch.old.lastname = "Erignac";
	ch.name = TranslateString("", "Louis");
	ch.lastname = TranslateString("", "Erignac");
	ch.id		= "French_Ambush_Captain2";
	ch.nation	= FRANCE;
	ch.model	= "9JdFra";
	ch.sound_type = "soldier";
//	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	if(ENABLE_WEAPONSMOD)
	{
		GiveItem2Character(ch, "blade9+1");
		GiveItem2Character(ch, "PiratesPistol+1");
	}
	else
	{
		GiveItem2Character(ch, "blade9");
		GiveItem2Character(ch, "PiratesPistol");
	}
	ch.equip.blade = "blade9";
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
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "French_Captain1_dialog.c";
	ch.rank 	= 4;
	ch.reputation = "45";
	ch.experience = "0";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "5";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "4000";
	ch.quest.officertype = OFFIC_TYPE_CAPNAVY;
	LAi_SetCivilianGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.Ship.Name = "Résistance";
	ch.Ship.Type = "FR_Frigate";
//	ch.Ship.Stopped = true;
	LAi_SetHP(ch, 300.0, 300.0);
	ch.Ship.crew.morale = 65;
	ch.questchar = true;//MAXIMUS: identifier for captives
	SetRank(ch, FRANCE, 5);
	ch.professionalnavy = FRANCE;
	AddGameCharacter(n, ch);

	ch.old.name = "Corin";
	ch.old.lastname = "Arzillires";
	ch.name = TranslateString("", "Corin");
	ch.lastname = TranslateString("", "Arzillires");
	ch.id		= "French_Ambush_Captain3";
	ch.nation	= FRANCE;
	ch.model	= "Corsair1_1";
	ch.sound_type = "soldier";
//	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	if(ENABLE_WEAPONSMOD)
	{
		GiveItem2Character(ch, "blade9+1");
		GiveItem2Character(ch, "PiratesPistol+1");
	}
	else
	{
		GiveItem2Character(ch, "blade9");
		GiveItem2Character(ch, "PiratesPistol");
	}
	ch.equip.blade = "blade9";
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
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "French_Captain1_dialog.c";
	ch.rank 	= 4;
	ch.reputation = "45";
	ch.experience = "0";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "5";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "4000";
	ch.quest.officertype = OFFIC_TYPE_CAPNAVY;
	LAi_SetCivilianGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.Ship.Name = "Reprisal";
	ch.Ship.Type = "FR_Frigate";
//	ch.Ship.Stopped = true;
	ch.Ship.crew.morale = 65;
	LAi_SetHP(ch, 300.0, 300.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	SetRank(ch, FRANCE, 5);
	ch.professionalnavy = FRANCE;
	AddGameCharacter(n, ch);

	ch.old.name = "Renouart";
	ch.old.lastname = "Bonnefroy";
	ch.name = TranslateString("", "Renouart");
	ch.lastname = TranslateString("", "Bonnefroy");
	ch.id		= "French_Ambush_Captain4";
	ch.nation	= FRANCE;
	ch.model	= "Corsair3_J";
	ch.sound_type = "soldier";
//	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	if(ENABLE_WEAPONSMOD)
	{
		GiveItem2Character(ch, "blade9+1");
		GiveItem2Character(ch, "PiratesPistol+1");
	}
	else
	{
		GiveItem2Character(ch, "blade9");
		GiveItem2Character(ch, "PiratesPistol");
	}
	ch.equip.blade = "blade9";
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
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "French_Captain1_dialog.c";
	ch.rank 	= 4;
	ch.reputation = "45";
	ch.experience = "0";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "5";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "4000";
	ch.quest.officertype = OFFIC_TYPE_CAPNAVY;
	LAi_SetCivilianGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.Ship.Name = "Impétueuse";
	ch.Ship.Type = "RN_RaaFrigate";
//	ch.Ship.Stopped = true;
	ch.Ship.crew.morale = 65;
	LAi_SetHP(ch, 300.0, 300.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	SetRank(ch, FRANCE, 5);
	ch.professionalnavy = FRANCE;
	AddGameCharacter(n, ch);

// Spanish agent
	ch.old.name = "Jaime";
	ch.old.lastname = "Lezcano";
	ch.name = TranslateString("", "Jaime");
	ch.lastname = TranslateString("", "Lezcano");
	ch.id		= "Jaime Lezcano";
	ch.model	= "Montoya";
	ch.model.animation = "Rousselet";
	ch.sound_type = "male_citizen";
	ch.sex = "man";
	ch.nation = SPAIN;
	if(ENABLE_WEAPONSMOD)
	{
		GiveItem2Character(ch, "blade45+2");
		GiveItem2Character(ch, "pistol25+2");
	}
	else
	{
		GiveItem2Character(ch, "blade45");
		GiveItem2Character(ch, "pistol25");
	}
	ch.equip.blade = "blade45";
	ch.equip.gun = "pistol25";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2)); }
	//JRH ammo mod <--	;
	GiveItem2Character(ch, "commonarmor");
	ch.location = "none";
	ch.location.group = "goto";
	ch.location.locator = "none";
	ch.Dialog.Filename = "Jaime Lezcano_dialog.c";
	ch.greeting = "Gr_Spanish_Spy";
	ch.rank 	= 7;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "7";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "4";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	Ch.Perks.list.Toughness = true;
	Ch.Perks.list.Gunman = true;
	ch.money = "1500";
	LAi_NoRebirthEnable(ch);
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 300.0, 300.0);
	ch.questchar = true;
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	AddGameCharacter(n, ch);

// Spanish agent's lieutenant
	ch.old.name = "Pelayo";
	ch.old.lastname = "Núñez";
	ch.name = TranslateString("", "Pelayo");
	ch.lastname = TranslateString("", "Núñez");
	ch.id		= "Pelayo Nunez";
	ch.model	= "Pirat9";
	ch.sound_type = "male_citizen";
	ch.sex = "man";
	ch.nation = SPAIN;
	if(ENABLE_WEAPONSMOD)
	{
		GiveItem2Character(ch, "blade50+1");
		GiveItem2Character(ch, "pistol8+1");
	}
	else
	{
		GiveItem2Character(ch, "blade50");
		GiveItem2Character(ch, "pistol8");
	}
	ch.equip.blade = "blade50";
	ch.equip.gun = "pistol8";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2)); }
	//JRH ammo mod <--	;
	GiveItem2Character(ch, "cured");
	ch.location = "none";
	ch.location.group = "goto";
	ch.location.locator = "none";
	ch.Dialog.Filename = "Pelayo Nunez_dialog.c";
	ch.greeting = "Gr_Spanish_Spy";
	ch.rank 	= 6;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "3";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "5";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	Ch.Perks.list.Toughness = true;
	ch.money = "500";
	LAi_NoRebirthEnable(ch);
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.Ship.Name = "Tarantula";
	ch.Ship.Type = "Brig3";
	ch.Ship.Stopped = true;
	LAi_SetHP(ch, 200.0, 200.0);
	ch.questchar = true;
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	ch.canhire = true;		// Can be hired after being captured
	AddGameCharacter(n, ch);

// Rival governor
	ch.old.name = "Emiliano";
	ch.old.lastname = "de Guzmán";
	ch.name = TranslateString("", "Emiliano");
	ch.lastname = TranslateString("", "de Guzmán");
	ch.id		= "Emiliano de Guzmán";
	ch.model	= "hub_por2";
	ch.sex = "man";
	ch.nation	= SPAIN;
	if(ENABLE_WEAPONSMOD)
	{
		GiveItem2Character(ch, "bladeC17+2");
		GiveItem2Character(ch, "pistol7+2");
	}
	else
	{
		GiveItem2Character(ch, "bladeC17");
		GiveItem2Character(ch, "pistol7");
	}
	ch.equip.blade = "bladeC17";
	ch.equip.gun = "pistol7";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2)); }
	//JRH ammo mod <--	;
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Emiliano de Guzmán_dialog.c";
	ch.rank 	= 35;
	ch.reputation = "None";
	ch.experience = "0";
	ch.greeting = "Gr_Diego Cordoba";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "8";
	ch.skill.Sneak = "2";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.money = "10000";
	LAi_NoRebirthEnable(ch);
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 500.0, 500.0);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	AddGameCharacter(n, ch);

	ch.nation = FRANCE;
	ch.old.name = "Gilles";
	ch.old.lastname = "Clouzot";
	ch.name = TranslateString("", "Gilles");
	ch.lastname = TranslateString("", "Clouzot");
	ch.id		= "Gilles Clouzot";
	ch.model = "man2";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.Dialog.Filename = "Gilles Clouzot_dialog.c";
//	GiveItem2Character(ch, "Piratesdagger");
//	if(ENABLE_WEAPONSMOD)
//	{
//		GiveItem2Character(ch, "pistol1a+3");
//	}
//	else
//	{
//		GiveItem2Character(ch, "pistol1a");
//	}
//	ch.equip.blade = "Piratesdagger";
//	ch.equip.gun = "pistol1a";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6); }
	//JRH ammo mod <--	;
	GiveItem2Character(ch, "cured");
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.greeting = "Gr_Etienne Dupuis";
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "3";
	ch.skill.Defence = "5";
	ch.skill.Commerce = "3";
	ch.skill.Sneak = "7";
	ch.money = "1538";
	ch.quest.meeting = "0";
	LAi_NoRebirthEnable(ch);
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

// Spanish soldiers for general use
// Spanish soldier 1
	ch.old.name = "Soldier";
	ch.old.lastname = "1";
	ch.name = TranslateString("", "Soldier");
	ch.lastname = "1";
	ch.id		= "Spanish_soldier1";
	ch.model	= "offic_spa_17";
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
	ch.location	= "None";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Soldier_dialog.c";
	ch.rank 	= 25;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "9";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "7";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "3";
	ch.skill.Defence = "7";
	ch.skill.Commerce = "3";
	ch.skill.Sneak = "7";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.Rush = true;
	ch.perks.list.Gunman = true;
	ch.money = "10";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 500.0, 500.0);
	ch.questchar = true;
	LAi_group_MoveCharacter(ch, "SPAIN_SOLDIERS");
	ch.greeting = "Gr_isla muelle soldier";
	AddGameCharacter(n, ch);

// Spanish soldier 2
	ch.old.name = "Soldier";			// Name will be given by 'SetRandomNameToCharacter' in quest code
	ch.old.lastname = "2";
	ch.name = TranslateString("", "Soldier");
	ch.lastname = "2";
	ch.id		= "Spanish_soldier2";
	ch.model	= "soldier_spa_17";
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
	ch.location	= "None";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Soldier_dialog.c";
	ch.rank 	= 20;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "3";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "6";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "3";
	ch.skill.Defence = "6";
	ch.skill.Commerce = "3";
	ch.skill.Sneak = "6";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.money = "10";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 400.0, 400.0);
	ch.questchar = true;
	LAi_group_MoveCharacter(ch, "SPAIN_SOLDIERS");
	ch.greeting = "Gr_isla muelle soldier";
	AddGameCharacter(n, ch);

// Spanish soldier 3
	ch.old.name = "Soldier";			// Name will be given by 'SetRandomNameToCharacter' in quest code
	ch.old.lastname = "3";
	ch.name = TranslateString("", "Soldier");
	ch.lastname = "3";
	ch.id		= "Spanish_soldier3";
	ch.model	= "soldier_spa3_17";
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
	ch.location	= "None";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Soldier_dialog.c";
	ch.rank 	= 20;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "3";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "6";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "3";
	ch.skill.Defence = "6";
	ch.skill.Commerce = "3";
	ch.skill.Sneak = "6";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.money = "10";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 400.0, 400.0);
	ch.questchar = true;
	LAi_group_MoveCharacter(ch, "SPAIN_SOLDIERS");
	ch.greeting = "Gr_isla muelle soldier";
	AddGameCharacter(n, ch);

// Spanish soldier 4
	ch.old.name = "Soldier";			// Name will be given by 'SetRandomNameToCharacter' in quest code
	ch.old.lastname = "4";
	ch.name = TranslateString("", "Soldier");
	ch.lastname = "4";
	ch.id		= "Spanish_soldier4";
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
	ch.location	= "None";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Soldier_dialog.c";
	ch.rank 	= 20;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "3";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "6";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "3";
	ch.skill.Defence = "6";
	ch.skill.Commerce = "3";
	ch.skill.Sneak = "6";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.money = "10";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 400.0, 400.0);
	ch.questchar = true;
	LAi_group_MoveCharacter(ch, "SPAIN_SOLDIERS");
	ch.greeting = "Gr_isla muelle soldier";
	AddGameCharacter(n, ch);
}