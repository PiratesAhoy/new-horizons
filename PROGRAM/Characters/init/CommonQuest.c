int CreateCommonQuestCharacters(int in)
{
	object chobj;
	ref ch;
	ref n = &in;

	makeref(ch, chobj);

	//Tutorial

	// Malcolm Hatcher
	ch.old.name = "Malcolm";
	ch.old.lastname = "Hatcher";
	ch.name = TranslateString("","Malcolm");
	ch.lastname = TranslateString("","Hatcher");
	ch.id		= "Malcolm Hatcher";
	ch.model = "Salt"; // Estharos Change from bocman3 to this model
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade11");	// Estharos: Temp fix to prevent getting killed in the tutorial
	ch.equip.blade = "blade11";			// Estharos: Temp fix to prevent getting killed in the tutorial
	ch.nodisarm	= 1;					// PB: Disable disarming
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Malcolm Hatcher_dialog.c";
	ch.greeting = "Gr_Malcolm Hatcher";
	ch.rank 	= 7;
	ch.reputation = "30";
	ch.experience = "0";
	ch.Ship.Name = "Margaret Hatcher"; // KK
	ch.Ship.Type = "RN_Poseidon"; // PB: To ensure he uses "Cabin1" aka. "Tut_deck"
	ch.Ship.Stopped = true; // KK
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "2";
	ch.skill.Accuracy = "2";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "2";
	ch.skill.Repair = "1";
	ch.skill.Defence = "6";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "1";
	ch.money = "500";
	ch.quest.meeting = "0";
	ch.hpbonus = 300;
	LAi_SetWarriorTypeNoGroup(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

//Tutorial

	ch.old.name = "Blackbeard";
	ch.old.lastname = "";
	ch.name = TranslateString("","Blackbeard");
	ch.lastname = "";
	ch.id		= "Blackbeard";
	ch.model	= "Blackbeard";
	ch.sex = "man";
	ch.location	= "IslaDeMuerte_shore_03";
	ch.location.group = "goto";
	ch.location.locator = "goto2";
	ch.Dialog.Filename = "Blackbeard_dialog.c";
	ch.nation = PIRATE;
	ch.Ship.Name = "Queen Anne's Revenge";
	ch.Ship.Type = "QueenAnnesRevenge";
	ch.Ship.Stopped = true;
	ch.Flags.Pirate = 5;
	ch.Flags.Pirate.texture = 0;
	ch.Flags.Personal = 2;
	ch.Flags.Personal.texture = 0;
	ch.Dialog.Filename = "Blackbeard_dialog.c";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "Blade_Triton");
	ch.equip.blade = "Blade_Triton";
	ch.rank 	= 100;
	ch.HPBonus = 500;
	ch.reputation = "10";
	ch.experience = "0";
	ch.skill.Leadership = "10";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "10";
	ch.skill.Accuracy = "10";
	ch.skill.Cannons = "10";
	ch.skill.Grappling = "10";
	ch.skill.Repair = "10";
	ch.skill.Defence = "10";
	ch.skill.Commerce = "10";
	ch.skill.Sneak = "10";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.Rush = true;
	ch.money = "1";
	ch.quest.meeting = "0";
	LAi_SetImmortal(ch, true); // PB
	LAi_SetCivilianPatrolType(ch); // KK
	LAi_NoRebirthEnable(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	AddGameCharacter(n, ch);

	ch.old.name = "Winston";
	ch.old.lastname = "Churchill";
	ch.name = TranslateString("","Winston");
	ch.lastname = TranslateString("","Churchill");
	ch.id		= "English Emissary";
	ch.model	= "Man7";
	ch.sex = "man";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "none";
	ch.Dialog.Filename = "Emissary_dialog.c";
	ch.Dialog.Filename.GroupDialog = "governor.c";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "50";
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
	ch.money = "1";
	LAi_SetCivilianPatrolType(ch); // KK
	SetRankTitle(ch, TranslateString("", "Sir"));
	AddGameCharacter(n, ch);

	ch.old.name = "Michiel";
	ch.old.lastname = "de Reyder";
	ch.name = TranslateString("","Michiel");
	ch.lastname = TranslateString("","de Reyder");
	ch.id		= "Dutch Emissary";
	ch.model	= "ThomasLinch";
	ch.sex = "man";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "none";
	ch.Dialog.Filename = "Emissary_dialog.c";
	ch.Dialog.Filename.GroupDialog = "governor.c";
	ch.nation = HOLLAND;
	ch.rank 	= 1;
	ch.reputation = "50";
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
	ch.money = "1";
	LAi_SetSitType(ch);
	AddGameCharacter(n, ch);

	ch.old.name = "Luis";
	ch.old.middlename = "Vas";
	ch.old.lastname = "de Torres";
	ch.name = TranslateString("","Luis");
	ch.middlename = TranslateString("","Vas");
	ch.lastname = TranslateString("","de Torres");
	ch.id		= "Portuguese Emissary";
	ch.model	= "9JdPor";
	ch.sex = "man";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "none";
	ch.Dialog.Filename = "Emissary_dialog.c";
	ch.Dialog.Filename.GroupDialog = "governor.c";
	ch.nation = PORTUGAL;
	ch.rank 	= 1;
	ch.reputation = "50";
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
	ch.money = "1";
	LAi_SetSitType(ch);
	AddGameCharacter(n, ch);

	ch.old.name = "Charlie";
	ch.old.lastname = "Allen";
	ch.name	= TranslateString("", "Charlie");
	ch.lastname	= TranslateString("", "Allen");
	ch.id = "English Tailor";
	ch.model = "Meigger";
	ch.sex = "man";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "none";
	ch.IsTailor = true;
	ch.Dialog.Filename = "tailor_dialog.c";
 	ch.Dialog.Filename.Groupdialog = "tailor.c";
	ch.rank 	= 1;
	ch.nation = ENGLAND;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "0";
	ch.skill.Fencing = "0";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "10";
	ch.skill.Sneak = "0";
	ch.money = "10";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 6.0, 18.0);
	AddGameCharacter(n, ch);

	ch.old.name = "Edgar";
	ch.old.lastname = "Vos";
	ch.name	= TranslateString("", "Edgar");
	ch.lastname	= TranslateString("", "Vos");
	ch.id = "Dutch Tailor";
	ch.model = "Man8";
	ch.sex = "man";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "none";
	ch.IsTailor = true;
	ch.Dialog.Filename = "tailor_dialog.c";
 	ch.Dialog.Filename.Groupdialog = "tailor.c";
	ch.rank 	= 1;
	ch.nation = HOLLAND;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "0";
	ch.skill.Fencing = "0";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "10";
	ch.skill.Sneak = "0";
	ch.money = "10";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 6.0, 18.0);
	AddGameCharacter(n, ch);

	ch.old.name = "Luнs";
	ch.old.lastname = "Buchinho";
	ch.name	= TranslateString("", "Luнs");
	ch.lastname	= TranslateString("", "Buchinho");
	ch.id = "Portuguese Tailor";
	ch.model = "shkiper";
	ch.sex = "man";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "none";
	ch.IsTailor = true;
	ch.Dialog.Filename = "tailor_dialog.c";
 	ch.Dialog.Filename.Groupdialog = "tailor.c";
	ch.rank 	= 1;
	ch.nation = PORTUGAL;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "0";
	ch.skill.Fencing = "0";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "10";
	ch.skill.Sneak = "0";
	ch.money = "10";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 6.0, 18.0);
	AddGameCharacter(n, ch);

// boal -->
	//Quest Pirate
	ch.old.name = "Deadly";
	ch.old.lastname = "Pirate";
	ch.name = TranslateString("","Deadly");
	ch.lastname = TranslateString("","Pirate");
	ch.id		= "Quest Pirate";
	ch.model	= "corsair3";
	ch.sound_type = "pirate";
	ch.nation = PIRATE;
	ch.sex = "man";
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
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "none";
	ch.Dialog.Filename = "Vincent Bethune_dialog.c";
	ch.greeting = "Gr_Vincent Bethune";
	ch.rank 	= 6;
	ch.reputation = "40";
	ch.experience = "240000";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "6";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "4";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "8";
	ch.money = "10";
	ch.skipRM = true; // PB: Skip Relations Mod
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);
// boal <--

// PB: Different Character for Treasure Quests -->
	ch.old.name = "Deadly";
	ch.old.lastname = "Pirate";
	ch.name = TranslateString("","Deadly");
	ch.lastname = TranslateString("","Pirate");
	ch.id		= "Treasure Pirate";
	ch.model	= "corsair3";
	ch.sound_type = "pirate";
	ch.nation = PIRATE;
	ch.sex = "man";
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
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "none";
	ch.Dialog.Filename = "Vincent Bethune_dialog.c";
	ch.greeting = "Gr_Vincent Bethune";
	ch.rank 	= 6;
	ch.reputation = "40";
	ch.experience = "240000";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "6";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "4";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "8";
	ch.money = "10";
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);
// PB: Different Character for Treasure Quests <--

// PB: Different Character for Convoy Quests -->
	ch.old.name = "Deadly";
	ch.old.lastname = "Pirate";
	ch.name = TranslateString("","Deadly");
	ch.lastname = TranslateString("","Pirate");
	ch.id		= "Convoy Pirate";
	ch.model	= "corsair3";
	ch.sound_type = "pirate";
	ch.nation = PIRATE;
	ch.sex = "man";
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
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "none";
	ch.Dialog.Filename = "Vincent Bethune_dialog.c";
	ch.greeting = "Gr_Vincent Bethune";
	ch.rank 	= 6;
	ch.reputation = "40";
	ch.experience = "240000";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "6";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "4";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "8";
	ch.money = "10";
	ch.skipRM = true; // PB: Skip Relations Mod
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);
// PB: Different Character for Convoy Quests <--

// KK -->
	// governor in boarding residence
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Captured governor";
	ch.model = "korsar";
	ch.sex = "man";
	ch.nation = PIRATE;
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "BOARDING_RESIDENCE";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Captured governor_dialog.c";
	ch.rank 	= 1;
	ch.reputation = "52";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);
// <-- KK
				// контрабандист 1
	ch.old.name = "Smuggler";
	ch.old.lastname = "";
	ch.name = TranslateString("","Smuggler");
	ch.lastname = "";
	ch.id		= "Rand_Smug01";
//	ch.model = "sat_monk";
	ch.sex = "man";
	ch.sound_type = "pirate";
//	ch.act.escape = 0;
	ch.act.rebirth = 1;
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none";//"Redmond"; //redmond_shore_01
	ch.location.group = "";
	ch.location.locator = "";//locator8
	ch.Dialog.Filename = "Smuggler_OnShore_dialog.c";
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
	LAi_SetCivilianGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_Smuggler_OnShore";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// контрабандист 2
	ch.old.name = "Smuggler";
	ch.old.lastname = "";
	ch.name = TranslateString("","Smuggler");
	ch.lastname = "";
	ch.id		= "Rand_Smug02";
//	ch.model = "sat_monk";
	ch.sex = "man";
	ch.sound_type = "pirate";
//	ch.act.escape = 0;
	ch.act.rebirth = 1;
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none";//"Redmond"; //redmond_shore_01
	ch.location.group = "";
	ch.location.locator = "";//locator8
	ch.Dialog.Filename = "Smuggler_OnShore_dialog.c";
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
	LAi_SetCivilianGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_Smuggler_OnShore";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// контрабандист 3
	ch.old.name = "Smuggler";
	ch.old.lastname = "";
	ch.name = TranslateString("","Smuggler");
	ch.lastname = "";
	ch.id		= "Rand_Smug03";
//	ch.model = "sat_monk";
	ch.sex = "man";
	ch.sound_type = "pirate";
//	ch.act.escape = 0;
	ch.act.rebirth = 1;
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none";//"Redmond"; //redmond_shore_01
	ch.location.group = "";
	ch.location.locator = "";//locator8
	ch.Dialog.Filename = "Smuggler_OnShore_dialog.c";
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
	LAi_SetCivilianGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_Smuggler_OnShore";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// quest_smuggler_01
	ch.old.name = "Smuggler";
	ch.old.lastname = "";
	ch.name = TranslateString("","Smuggler");
	ch.lastname = "";
	ch.id		= "quest_smuggler_01";
	ch.model = "corsair2";
	ch.sex = "man";
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none"
	ch.location.group = "goto";
	ch.location.locator = "goto4";
	ch.Dialog.Filename = "quest_smuggler_01_dialog.c";
	ch.rank 	= 1;
	ch.reputation = "52";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "5";
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
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Quest_Smuggler_01";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//первый капитан береговой стражи
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Coastal_Captain01";
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "None";
	ch.location.group = "";
	ch.location.locator = "";
//	ch.Dialog.Filename = "blaze_dialog.c";
	ch.reputation = "50";
	ch.experience = 0;//CalculateExperienceFromRank(sti(ch.rank));
	ch.Ship.Name = "Dolphine";
	//ch.Ship.Type = SHIP_FRIGATE_ENGLAND;
	ch.Ship.Type = "Lugger1"; // PRS3
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	// done by setbaseship - NK 05-04-09 ch.ship.cargo.goods.bombs = 1000;
	ch.Ship.Stopped = true;
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//второй капитан береговой стражи
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Coastal_Captain02";
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "None";
	ch.location.group = "";
	ch.location.locator = "";
//	ch.Dialog.Filename = "blaze_dialog.c";
	ch.reputation = "50";
	ch.experience = 0;//CalculateExperienceFromRank(sti(ch.rank));
	ch.Ship.Name = "Dolphine";
	//ch.Ship.Type = SHIP_FRIGATE_ENGLAND;
	ch.Ship.Type = "Lugger1"; // PRS3
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	// done by setbaseship - NK 05-04-09 ch.ship.cargo.goods.bombs = 1000;
	ch.Ship.Stopped = true;
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//третий капитан береговой стражи
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Coastal_Captain03";
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "None";
	ch.location.group = "";
	ch.location.locator = "";
//	ch.Dialog.Filename = "blaze_dialog.c";
	ch.reputation = "50";
	ch.experience = 0;//CalculateExperienceFromRank(sti(ch.rank));
	ch.Ship.Name = "Dolphine";
	//ch.Ship.Type = SHIP_FRIGATE_ENGLAND;
	ch.Ship.Type = "Lugger1"; // PRS3
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	// done by setbaseship - NK 05-04-09 ch.ship.cargo.goods.bombs = 1000;
	ch.Ship.Stopped = true;
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Enemy_Captain01";
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "None";
	ch.location.group = "";
	ch.location.locator = "";
	ch.reputation = "50";
	ch.experience = 0;
	ch.Ship.Name = "Dolphine";
	ch.Ship.Type = "Lugger1"; // PRS3
	ch.Ship.Stopped = true;
	ch.skipRM = true; // PB: Skip Relations Mod
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Enemy_Captain02";
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "None";
	ch.location.group = "";
	ch.location.locator = "";
	ch.reputation = "50";
	ch.experience = 0;
	ch.Ship.Name = "Dolphine";
	ch.Ship.Type = "Lugger1"; // PRS3
	ch.Ship.Stopped = true;
	ch.skipRM = true; // PB: Skip Relations Mod
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);


	//ASVS moved here soldiers for drunk fight
				// Redmond Soldier for drink fight
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Redmond Soldier";
	ch.model	= 1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none"
	ch.location.group = "none";
	ch.location.locator = "none";
	ch.Dialog.Filename = "Redmond soldier_dialog.c";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "52";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "3";
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
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Greenford Soldier for drink fight
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Greenford Soldier";
	ch.model	= 1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none"
	ch.location.group = "none";
	ch.location.locator = "none";
	ch.Dialog.Filename = "Greenford soldier_dialog.c";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "52";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "3";
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

				// Oxbay Soldier for drink fight
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Oxbay Soldier";
	ch.model	= 1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none"
	ch.location.group = "none";
	ch.location.locator = "none";
	ch.Dialog.Filename = "Oxbay soldier_dialog.c";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "52";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_Oxbay Soldier";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Douwesen Soldier for drink fight
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Douwesen Soldier";
	ch.model	= 1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none"
	ch.location.group = "none";
	ch.location.locator = "none";
	ch.Dialog.Filename = "Douwesen soldier_dialog.c";
	ch.nation = HOLLAND;
	ch.rank 	= 1;
	ch.reputation = "52";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_Douwesen Soldier";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// MUELLE Soldier for drink fight
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Muelle Soldier";
	ch.model	= 1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none"
	ch.location.group = "none";
	ch.location.locator = "none";
	ch.Dialog.Filename = "Isla Muelle soldier_dialog.c";
	ch.nation = SPAIN;
	ch.rank 	= 1;
	ch.reputation = "52";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_isla muelle soldier";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Conceicao Soldier for drink fight
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Conceicao Soldier";
	ch.model	= 1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none"
	ch.location.group = "none";
	ch.location.locator = "none";
	ch.Dialog.Filename = "Conceicao soldier_dialog.c";
	ch.nation = PORTUGAL;
	ch.rank 	= 1;
	ch.reputation = "52";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_Conceicao Soldier";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// QC Soldier for drink fight
	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("","Pirate");
	ch.lastname = "";
	ch.id		= "QC Soldier";
	ch.model = "corsair2";
	ch.sex = "man";
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none"
	ch.location.group = "none";
	ch.location.locator = "none";
	ch.Dialog.Filename = "Pirate Soldier_dialog.c";
	ch.nation = PIRATE;
	ch.rank 	= 1;
	ch.reputation = "52";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "3";
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

				// Smugglers Soldier for drink fight
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Smugglers Soldier";
	ch.model = "korsar";
	ch.sex = "man";
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none"
	ch.location.group = "none";
	ch.location.locator = "none";
	ch.Dialog.Filename = "Conceicao soldier_dialog.c";
	ch.nation = PORTUGAL;
	ch.rank 	= 1;
	ch.reputation = "52";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "3";
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

				// Pirate Soldier for drink fight
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Pirate Soldier";
	ch.model = "man1";
	ch.sex = "man";
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none"
	ch.location.group = "none";
	ch.location.locator = "none";
	ch.Dialog.Filename = "Pirate Soldier_dialog.c";
	ch.nation = PIRATE;
	ch.rank 	= 1;
	ch.reputation = "52";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "3";
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

				// Falaise De Fleur Soldier for drink fight
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Falaise De Fleur Soldier";
	ch.model	= 1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none"
	ch.location.group = "none";
	ch.location.locator = "none";
	ch.Dialog.Filename = "Falaise de Fleur soldier_dialog.c";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "52";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_falaise de fleur soldier";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Giraldo Figuiera
	ch.old.name = "Trader";
	ch.old.lastname = "";
	ch.name = TranslateString("","Trader");
	ch.lastname = "";
	ch.id		= "Quest trader";
	ch.model = "storeman2";
	ch.sex = "man";
	ch.sound_type = "seaman";
	ch.nation = ENGLAND;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "anacleto_dialog.c";
	ch.Ship.Name = "";
	ch.Ship.Type = "Sloop1"; // PRS3
	ch.Ship.Stopped = true;
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS12;
	ch.rank 	= 1;
	ch.reputation = "1";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "4";
	ch.skill.Defence = "4";
	ch.skill.Commerce = "5";
	ch.skill.Sneak = "0";
	ch.money = "1";
	ch.quest.officertype = OFFIC_TYPE_TRADER; // PB: As identifier
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_Anacleto";
	AddGameCharacter(n, ch);

			//первый капитан-мститель за поруганнцю честь ростовщика
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Usurer_Avenger01";
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "None";
	ch.location.group = "";
	ch.location.locator = "";
	ch.reputation = "50";
	ch.experience = 0;
	ch.Ship.Name = "Dolphine";
	ch.Ship.Type = "Lugger1"; // PRS3
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	// done by setbaseship - NK 05-04-09 ch.ship.cargo.goods.bombs = 1000;
	ch.Ship.Stopped = false;
	LAi_SetWarriorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//второй капитан-мститель за поруганнцю честь ростовщика
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Usurer_Avenger02";
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "None";
	ch.location.group = "";
	ch.location.locator = "";
	ch.reputation = "50";
	ch.experience = 0;
	ch.Ship.Name = "Dolphine";
	ch.Ship.Type = "Lugger1"; // PRS3
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	// done by setbaseship - NK 05-04-09 ch.ship.cargo.goods.bombs = 1000;
	ch.Ship.Stopped = false;
	LAi_SetWarriorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//третий капитан-мститель за поруганнцю честь ростовщика
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Usurer_Avenger03";
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "None";
	ch.location.group = "";
	ch.location.locator = "";
	ch.reputation = "50";
	ch.experience = 0;
	ch.Ship.Name = "Dolphine";
	ch.Ship.Type = "Lugger1"; // PRS3
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	// done by setbaseship - NK 05-04-09 ch.ship.cargo.goods.bombs = 1000;
	ch.Ship.Stopped = false;
	LAi_SetWarriorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				//Virginie d'Espivant - Involved in the quest of Bones
	ch.old.name = "Virginie";
	ch.old.lastname = "d'Espivant";
	ch.name = TranslateString("","Virginie");
	ch.lastname = TranslateString("","d'Espivant");
	ch.id		= "Virginie d'Espivant";
	ch.model	= "towngirl1";
	ch.sound_type = "female_citizen";
	ch.sex = "woman";
	ch.nation = FRANCE;
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Virginie d'Espivant_dialog.c";
	ch.greeting = "Gr_Virginie d'Espivant";
	ch.rank 	= 1;
	ch.reputation = "40";
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
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				//Raymond Bouchez - groom Virginie d'Espivant.
	ch.old.name = "Raymond";
	ch.old.lastname = "Bouchez";
	ch.name = TranslateString("","Raymond");
	ch.lastname = TranslateString("","Bouchez");
	ch.id		= "Raymond Bouchez";
	ch.model	= "man6_1";
	ch.sound_type = "male_citizen";
	ch.sex = "man";
	ch.nation = FRANCE;
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "Raymond Bouchez_dialog.c";
	ch.greeting = "Gr_Raymond Bouchez";
	ch.rank 	= 1;
	ch.reputation = "40";
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
	ch.skill.Sneak = "8";
	ch.money = "10";
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Emellio";
	ch.old.lastname = "Fernandez";
	ch.name = TranslateString("","Emellio");
	ch.lastname = TranslateString("","Fernandez");
	ch.id		= "danielle_quests_corsair_1";
	ch.sound_type = "pirate";
	ch.model	= "corsair1";
	ch.sex = "man";
	LAi_NoRebirthEnable(ch);
	GiveItem2Character(ch, "blade7");
	ch.equip.blade = "blade7";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "danielle_quests_pirate_dialog.c";
	ch.greeting = "Gr_danielle_quests_pirate";
	ch.rank 	= 4;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "0";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "4";
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
	ch.old.lastname = "";
	ch.name = TranslateString("","Pirate");
	ch.lastname = "";
	ch.id		= "danielle_quests_corsair_2";
	ch.nation	= PIRATE;
	ch.act.type = "merchant";
	ch.model	= "corsair2";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade36");
	ch.equip.blade = "blade36";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "danielle_quests_pirate_dialog.c";
	ch.greeting = "Gr_danielle_quests_pirate";
	ch.rank 	= 4;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "0";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "4";
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
	ch.old.lastname = "";
	ch.name = TranslateString("","Pirate");
	ch.lastname = "";
	ch.id		= "danielle_quests_corsair_3";
	ch.nation	= PIRATE;
	ch.sound_type = "pirate";
	ch.model	= "corsair3";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "danielle_quests_pirate_dialog.c";
	ch.greeting = "Gr_danielle_quests_pirate";
	ch.rank 	= 4;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "0";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "3";
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
	ch.old.lastname = "";
	ch.name = TranslateString("","Pirate");
	ch.lastname = "";
	ch.id		= "danielle_quests_corsair_4";
	ch.nation	= PIRATE;
	ch.sound_type = "pirate";
	ch.model	= "killer";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "danielle_quests_pirate_dialog.c";
	ch.greeting = "Gr_danielle_quests_pirate";
	ch.rank 	= 4;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "0";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "3";
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
	ch.old.lastname = "";
	ch.name = TranslateString("","Pirate");
	ch.lastname = "";
	ch.id		= "danielle_quests_corsair_5";
	ch.nation	= PIRATE;
	ch.sound_type = "pirate";
	ch.model	= "Man3";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade7");
	ch.equip.blade = "blade7";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "danielle_quests_pirate_dialog.c";
	ch.greeting = "Gr_danielle_quests_pirate";
	ch.rank 	= 4;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "0";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "3";
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

	// NK 05-03-30 now do random officers with a for loop.
	for(int i = 0; i < NUM_RANDOM_OFFICERS; i++)
	{
		// Random Officer
		ch.old.name = "";
		ch.old.lastname = "";
		ch.name = "";
		ch.lastname = "";
		ch.id		= "Enc_Officer_"+i;
		ch.model	= "";
		ch.sex = "man";
		ch.location	= "";
		ch.location.group = "";
		ch.location.locator = "";
		ch.Dialog.Filename = "";
		ch.nation = PIRATE;
		ch.rank 	= 1;
		ch.reputation = "50";
		ch.experience = "";
		ch.skill.Leadership = "";
		ch.skill.Fencing = "";
		ch.skill.Sailing = "";
		ch.skill.Accuracy = "";
		ch.skill.Cannons = "";
		ch.skill.Grappling = "";
		ch.skill.Repair = "";
		ch.skill.Defence = "";
		ch.skill.Commerce = "";
		ch.skill.Sneak = "";

		AddGameCharacter(n, ch);
	}
	// NK <--
	//MAXIMUS: the same way, as Enc_Officer -[it was my first version of this function (rewritten later by TIH)]->
	for(int j=0; j<CABINCAPTAINS_MAX; j++)
	{
		ch.old.name = "";
		ch.old.lastname = "";
		ch.name = "";
		ch.lastname = "";
		ch.id		= "Enc_CabinCaptain_"+j;
		ch.model	= "";
		ch.sex = "man";
		ch.location	= "";
		ch.location.group = "";
		ch.location.locator = "";
		ch.Dialog.Filename = "";
		ch.nation = PIRATE;
		ch.rank 	= 1;
		ch.reputation = "50";
		ch.experience = "";
		ch.skill.Leadership = "";
		ch.skill.Fencing = "";
		ch.skill.Sailing = "";
		ch.skill.Accuracy = "";
		ch.skill.Cannons = "";
		ch.skill.Grappling = "";
		ch.skill.Repair = "";
		ch.skill.Defence = "";
		ch.skill.Commerce = "";
		ch.skill.Sneak = "";

		AddGameCharacter(n, ch);
	}
	//MAXIMUS: the same way, as Enc_Officer <-[it was my first version of this function (rewritten later by TIH)]-

	in = n;
	return in;
}
