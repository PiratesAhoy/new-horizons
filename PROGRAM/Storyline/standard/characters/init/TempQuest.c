void CreateTempQuestCharacters(ref n)
{
	object chobj;
	ref ch;

	makeref(ch, chobj);

				// Wilfred Bythesea - так, старый знакомы Ѕлэйза, по€вл€ющийс€ эпизодически
	ch.old.name = "Wilfred";
	ch.old.lastname = "Bythesea";
	ch.name = TranslateString("","Wilfred");
	ch.lastname = TranslateString("","Bythesea");
	ch.id		= "Wilfred Bythesea";
	ch.model = "man4";
	ch.sex = "man";
	ch.sound_type = "seaman";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "none";
	ch.Dialog.Filename = "Wilfred Bythesea_dialog.c";
	ch.greeting = "Gr_Wilfred Bythesea";
	ch.rank 	= 1;
	ch.reputation = "22";
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
	ch.quest.kill_Ogarrio = "0";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Eng Captain who have IDOL
	ch.old.name = "Harold";
	ch.old.lastname = "Barrat";
	ch.name = TranslateString("","Harold");
	ch.lastname = TranslateString("","Barrat");
	ch.id		= "Eng Captain Idol";
	ch.model	= Nations[ENGLAND].fantomModel.m0; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.Ship.AI.GroupName = "Idol_Squadron";
	ch.Ship.AI.Task = "runaway";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "none"
	ch.location.group = "Quest_ships";
	ch.location.locator = "quest_ship_7";
	ch.Dialog.Filename = "falaise de fleur soldier_dialog.c";
	ch.nation = ENGLAND;
	ch.Ship.Name = "Athena"; // KK
	ch.Ship.Type = "HMS_Unicorn"; // PRS3 // KK
	ch.Ship.Stopped = true;
	ch.skipRM = true; // PB: Skip Relations Mod
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
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
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_falaise de fleur soldier";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Danielle_sailor
	ch.old.name = "Sailor";
	ch.old.lastname = "";
	ch.name = TranslateString("","Sailor");
	ch.lastname = "";
	ch.id		= "Danielle_sailor";
	ch.model = "bocman";
	ch.sex = "man";
	ch.sound_type = "seaman";
	LAi_NoRebirthEnable(ch);
	ch.nation = ENGLAND;
	GiveItem2Character(ch, "blade7");
	ch.equip.blade = "blade7";
	ch.Dialog.Filename = "Danielle_sailor_dialog.c";
	ch.greeting = "Gr_danielle_sailor";
	ch.rank 	= 1;
	ch.reputation = "28";
	ch.experience = "35";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "2";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.quest.kill_pirate_06 = "";
	ch.money = "154";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// quest_pirate_01
	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("","Pirate");
	ch.lastname = "";
	ch.id		= "quest_pirate_01";
	ch.model = "korsar";
	ch.sex = "man";
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "goto4";
	ch.Dialog.Filename = "quest_pirate_01_dialog.c";
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
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//  Fernam  Barrios -- korsar
	ch.old.name = "Fernam";
	ch.old.lastname = "Barrios";
	ch.name = TranslateString("","Fernam");
	ch.lastname = TranslateString("","Barrios");
	ch.id		= "Fernam  Barrios";
	ch.model	= "man1";
	ch.sex = "man";
	GiveItem2Character(ch, "blade7");
	ch.equip.blade = "blade7";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "goto28";
	ch.Dialog.Filename = "Evaristo Filho_dialog.c";
	ch.nation = PORTUGAL;
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
	ch.money = "0";
	LAi_SetCivilianGuardianType(ch); // PB
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_Evaristo Filho";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//  Leborio Violate -- korsar
	ch.old.name = "Leborio";
	ch.old.lastname = "Violate";
	ch.name = TranslateString("","Leborio");
	ch.lastname = TranslateString("","Violate");
	ch.id		= "Leborio Violate";
	ch.model	= "man2";
	ch.sex = "man";
	GiveItem2Character(ch, "blade36");
	ch.equip.blade = "blade36";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "goto29";
	ch.Dialog.Filename = "Evaristo Filho_dialog.c";
	ch.nation = PORTUGAL;
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
	ch.money = "0";
	LAi_SetCivilianGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_Evaristo Filho";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//  pirate for abordage 01
	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("","Pirate");
	ch.lastname = "";
	ch.id		= "pirate for abordage 01";
	ch.model	= "man2";
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.act.type = "soldier";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "";
	ch.nation = PORTUGAL;
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
	ch.money = "0";
	LAi_SetCivilianGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//  pirate for abordage 02
	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("","Pirate");
	ch.lastname = "";
	ch.id		= "pirate for abordage 02";
	ch.model	= "man2";
	ch.sex = "man";
	LAi_NoRebirthEnable(ch);
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
	ch.Dialog.Filename = "";
	ch.nation = PORTUGAL;
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
	ch.money = "0";
	LAi_SetCivilianGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//  pirate for abordage 03
	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("","Pirate");
	ch.lastname = "";
	ch.id		= "pirate for abordage 03";
	ch.model	= "man2";
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "goto4";
	ch.Dialog.Filename = "";
	ch.nation = PORTUGAL;
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
	ch.money = "0";
	LAi_SetCivilianGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//  pirate for quest muelle 01
	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("","Pirate");
	ch.lastname = "";
	ch.id		= "pirate for quest muelle 01";
	ch.model	= "man2";
	ch.sex = "man";
	GiveItem2Character(ch, "blade7");
	ch.equip.blade = "blade7";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "goto10";
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
	ch.money = "0";
	LAi_SetCivilianGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//  pirate for quest muelle 02
	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("","Pirate");
	ch.lastname = "";
	ch.id		= "pirate for quest muelle 02";
	ch.model	= "corsair1";
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "goto10";
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
	ch.money = "0";
	LAi_SetCivilianGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//  pirate for quest muelle 03
	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("","Pirate");
	ch.lastname = "";
	ch.id		= "pirate for quest muelle 03";
	ch.model	= "korsar";
	ch.sex = "man";
	GiveItem2Character(ch, "blade6");
	ch.equip.blade = "blade6";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "goto10";
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
	ch.money = "0";
	LAi_SetCivilianGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Pirate Captain 05
	ch.old.name = "Gyles";
	ch.old.lastname = "Dubois";
	ch.name = TranslateString("","Gyles");
	ch.lastname = TranslateString("","Dubois");
	ch.id		= "Pirate Captain 05";
	ch.model = "fisherman";
	ch.sex = "man";
	ch.act.type = "soldier";
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none";//"Redmond"; //redmond_shore_01
	ch.location.group = "ships";
	ch.location.locator = "locator5";//locator8
	ch.Dialog.Filename = "Gyles Dubois_dialog.c";
	ch.Ship.Name = "Sirena";
	ch.Ship.Type = "Barque1"; // PRS3
	ch.Ship.Stopped = true;
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS16;
	ch.rank 	= 1;
	ch.reputation = "22";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "4";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_Gyles Dubois";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Pirate Captain 06
	ch.old.name = "Gyles";
	ch.old.lastname = "Dubois";
	ch.name = TranslateString("","Gyles");
	ch.lastname = TranslateString("","Dubois");
	ch.id		= "Pirate Captain 06";
	ch.model = "fisherman";
	ch.sex = "man";
	ch.act.type = "soldier";
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade7");
	ch.equip.blade = "blade7";
	ch.location	= "none";
	ch.location.group = "quest_ships";
	ch.location.locator = "quest_ship9";
	ch.Dialog.Filename = "Gyles Dubois_dialog.c";
	ch.Ship.Name = "Sirena";
	ch.Ship.Type = "Barque1"; // PRS3
	ch.Ship.Stopped = true;
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS16;
	ch.rank 	= 1;
	ch.reputation = "22";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "4";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_Gyles Dubois";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// greenford citizen 01
	ch.old.name = "citizen";
	ch.old.lastname = "";
	ch.name = TranslateString("","citizen");
	ch.lastname = "";
	ch.id		= "greenford_citizen_01";
	ch.model = "TownGirl5";
	ch.sex = "woman";
	ch.act.type = "merchant";
	ch.sound_type = "female_citizen";
	LAi_NoRebirthEnable(ch);
	ch.nation = ENGLAND;
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "none";
	ch.Dialog.Filename = "greenford_citizen_01_dialog.c";
	ch.greeting = "Gr_greenford_citizen_01";
	ch.rank 	= 1;
	ch.reputation = "42";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "0";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// murderer_in_douwesen_01
	ch.old.name = "citizen";
	ch.old.lastname = "";
	ch.name = TranslateString("","citizen");
	ch.lastname = "";
	ch.id		= "murderer_in_douwesen_01";
	ch.model = "man1_1";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade6");
	ch.equip.blade = "blade6";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "none";
	ch.Dialog.Filename = "murderer_in_greenford_01_dialog.c";
	ch.greeting = "Gr_Murderer_in_Greenford_01";
	ch.rank 	= 1;
	ch.reputation = "19";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "2";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 40.0, 40.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// murderer_in_douwesen_02
	ch.old.name = "citizen";
	ch.old.lastname = "";
	ch.name = TranslateString("","citizen");
	ch.lastname = "";
	ch.id		= "murderer_in_douwesen_02";
	ch.model = "corsair2";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "none";
	ch.Dialog.Filename = "murderer_in_greenford_01_dialog.c";
	ch.greeting = "Gr_Murderer_in_Greenford_01";
	ch.rank 	= 1;
	ch.reputation = "19";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 40.0, 40.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// murderer_in_douwesen_03
	ch.old.name = "citizen";
	ch.old.lastname = "";
	ch.name = TranslateString("","citizen");
	ch.lastname = "";
	ch.id		= "murderer_in_douwesen_03";
	ch.model = "bocman";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade7");
	ch.equip.blade = "blade7";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "none";
	ch.Dialog.Filename = "murderer_in_greenford_01_dialog.c";
	ch.greeting = "Gr_Murderer_in_Greenford_01";
	ch.rank 	= 1;
	ch.reputation = "19";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 40.0, 40.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// murderer_in_greenford_04
	ch.old.name = "citizen";
	ch.old.lastname = "";
	ch.name = TranslateString("","citizen");
	ch.lastname = "";
	ch.id		= "murderer_in_greenford_04";
	ch.model = "man1";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	LAi_NoRebirthEnable(ch);
	ch.nation = ENGLAND;
	GiveItem2Character(ch, "blade6");
	ch.equip.blade = "blade6";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "none";
	ch.Dialog.Filename = "murderer_in_greenford_01_dialog.c";
	ch.greeting = "Gr_Murderer_in_Greenford_01";
	ch.rank 	= 1;
	ch.reputation = "42";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "0";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 40.0, 40.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// murderer_in_greenford_05
	ch.old.name = "citizen";
	ch.old.lastname = "";
	ch.name = TranslateString("","citizen");
	ch.lastname = "";
	ch.id		= "murderer_in_greenford_05";
	ch.model = "man2";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	LAi_NoRebirthEnable(ch);
	ch.nation = ENGLAND;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "none";
	ch.Dialog.Filename = "murderer_in_greenford_01_dialog.c";
	ch.greeting = "Gr_Murderer_in_Greenford_01";
	ch.rank 	= 1;
	ch.reputation = "42";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "0";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 40.0, 40.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// murderer_in_greenford_06
	ch.old.name = "citizen";
	ch.old.lastname = "";
	ch.name = TranslateString("","citizen");
	ch.lastname = "";
	ch.id		= "murderer_in_greenford_06";
	ch.model = "man3";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	LAi_NoRebirthEnable(ch);
	ch.nation = ENGLAND;
	GiveItem2Character(ch, "blade6");
	ch.equip.blade = "blade6";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "none";
	ch.Dialog.Filename = "murderer_in_greenford_01_dialog.c";
	ch.greeting = "Gr_Murderer_in_Greenford_01";
	ch.rank 	= 1;
	ch.reputation = "42";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "0";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 40.0, 40.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Eng Soldier for residence
	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","Soldier");
	ch.lastname = "";
	ch.id		= "Eng Soldier for residence 01";
	ch.model	= Nations[ENGLAND].fantomModel.m1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.location	= "none"
	ch.location.group = "Quest_ships";
	ch.location.locator = "quest_ship_7";
	ch.Dialog.Filename = "falaise de fleur soldier_dialog.c";
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
	ch.greeting = "Gr_falaise de fleur soldier";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Eng Soldier for residence
	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","Soldier");
	ch.lastname = "";
	ch.id		= "Eng Soldier for residence 02";
	ch.model	= Nations[ENGLAND].fantomModel.m1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.location	= "none"
	ch.location.group = "Quest_ships";
	ch.location.locator = "quest_ship_7";
	ch.Dialog.Filename = "falaise de fleur soldier_dialog.c";
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
	ch.greeting = "Gr_falaise de fleur soldier";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "citizen";
	ch.old.lastname = "";
	ch.name = TranslateString("","citizen");
	ch.lastname = "";
	ch.id		= "peasant";
	ch.model = "man5";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	LAi_NoRebirthEnable(ch);
	ch.nation = HOLLAND;
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "none";
	ch.Dialog.Filename = "peasant_dialog.c";
	ch.greeting = "Gr_Peasant";
	ch.rank 	= 1;
	ch.reputation = "42";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "0";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 990.0, 990.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);


//Cursed Coins Quest

				// First Cursed Pirate
	ch.old.name = "";
	ch.old.lastname = "Ragetti";
	ch.name = TranslateString("","");						// Cursed pirate given the name of
	ch.lastname = TranslateString("","Ragetti");			// Ragetti from the Pirates of the Caribbean movies
	ch.id		= "Cursed_Pirate_01";
	ch.model = "Ragetti";									// was "bocman4"; changed into the pirate counterpart looking like Ragetti
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
	ch.Dialog.Filename = "CursedPirate_Dialog.c";
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "2";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	ch.quest.meeting = "0";
	LAi_SetWarriorType(ch);
	LAi_warrior_SetStay(ch, true);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_SetImmortal(ch, true);
	TakeNItems(ch,"blade4", 1);
	EquipCharacterByItem(Ch, "blade4");
	ch.greeting = "Gr_CursedPirate";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Second Cursed Pirate
	ch.old.name = "";
	ch.old.lastname = "Pintel";
	ch.name = TranslateString("","");
	ch.lastname = TranslateString("","Pintel");
	ch.id		= "Cursed_Pirate_02";
	ch.model	= "Pintel"; // JRH
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
	ch.Dialog.Filename = "CursedPirate_Dialog.c";
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "2";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	ch.quest.meeting = "0";
	LAi_SetWarriorType(ch);
	LAi_warrior_SetStay(ch, true);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_SetImmortal(ch, true);
	TakeNItems(ch,"blade4", 1);
	EquipCharacterByItem(Ch, "blade4");
	ch.greeting = "Gr_CursedPirate";
	AddGameCharacter(n, ch);
}
	
