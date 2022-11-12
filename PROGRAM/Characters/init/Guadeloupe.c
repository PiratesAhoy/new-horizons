void CreateGuadeloupeCharacters(ref n)
{
	object chobj;
	ref ch;

	makeref(ch, chobj);

// Point_a_Pitre_Residence:

			// Remy Gatien (townhall)
	ch.name = TranslateString("","Remy");
	ch.lastname = TranslateString("","Gatien");
	ch.id		= "Remy Gatien_gov"; // KK
	ch.model = "Corsair1_4";
	ch.sex = "man";
	ch.location	= "PaP_townhall";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Remy Gatien_dialog.c";
	ch.Dialog.Filename.GroupDialog = "governor.c";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "60";
	ch.experience = "0";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "5";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	ch.greeting = "Gr_joseph claude le moigne";
	AddGameCharacter(n, ch);

// Point_a-Pitre_Church:
	// Pater Dominic
	ch.old.name = "Pater";
	ch.old.lastname = "Dominic";
	ch.name = TranslateString("","Pater");
	ch.lastname = TranslateString("","Dominic");
	ch.id		= "Pater Dominic";
	ch.model	= "monk";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.location	= "PaP_church";
	ch.location.group = "barmen";
	ch.location.locator = "bar1";
	ch.Dialog.Filename = "pater dominic_dialog.c";
	ch.Dialog.Filename.group = "church.c";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "58";
	ch.experience = "0";
	ch.skill.Leadership = "4";
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
	ch.quest.meeting = "0";
	ch.quest.donations = "0";
	ch.quest.prihod = "0";
	LAi_SetPriestType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	ch.greeting = "Gr_Pater Jourdain";
	AddGameCharacter(n, ch);

// citizens
	ch.old.name = "Elliot";
	ch.old.lastname = "Marpeut";
	ch.name = TranslateString("","Elliot");
	ch.lastname = TranslateString("","Marpeut");
	ch.id		= "Elliot Marpeut";
	ch.model = "fisherman";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.location	= "Guadeloupe_port";
	ch.location.group = "goto";
	ch.location.locator = "goto20";
	ch.Dialog.Filename = "PaP citizen_dialog.c";
	ch.greeting = "Gr_falaise de fleur citizen";
	ch.nation = FRANCE;
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
	ch.quest.meeting = "0";
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	AddGameCharacter(n, ch);

	ch.old.name = "Laure";
	ch.old.lastname = "Sinclair";
	ch.name = TranslateString("","Laure");
	ch.lastname = TranslateString("","Sinclair");
	ch.id		= "Laure Sinclair";
	ch.model = "Diz1";
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "Guadeloupe_port";
	ch.location.group = "goto";
	ch.location.locator = "goto11";
	ch.Dialog.Filename = "PaP citizen_dialog.c";
	ch.greeting = "Gr_danielle";
	ch.nation = FRANCE;
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
	ch.quest.meeting = "0";
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	AddGameCharacter(n, ch);

// Pointe_a_Pitre_storehouse:

		//  Albin Bonaventure
	ch.name 	= TranslateString("","Andre");
	ch.lastname = TranslateString("","Dubois");
	ch.id		= "Andre Dubois";
	ch.model	= "Man6_1";
	ch.headmodel = "h_Man6_1";
	ch.sex = "man";
	ch.location	= "PaP_Storehouse";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Item Trader_dialog.c";
	ch.greeting = "Gr_arnaud matton";
	ch.nation = FRANCE;
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
	ch.money = "1";
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	AddGameCharacter(n, ch);

// Guadeloupe_Plantation_inside:

			//François de Vigny
	ch.name 	= TranslateString("","François");
	ch.lastname = TranslateString("","de Vigny");
	ch.id		= "François de Vigny";
	ch.model	= "Nobleman2";
	ch.headmodel = "h_Nobleman2";
	ch.sex = "man";
	ch.location	= "Guadeloupe_Plantation_inside";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
	ch.Dialog.Filename = "Francois de Vigny_dialog.c";
	ch.nation = FRANCE;
	ch.rank 	= 7;
	ch.reputation = "90";
	ch.experience = "0";
	ch.skill.Leadership = "10";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "4";
	ch.skill.Accuracy = "6";
	ch.skill.Cannons = "4";
	ch.skill.Grappling = "2";
	ch.skill.Repair = "0";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "10";
	ch.skill.Sneak = "0";
	ch.money = "100000";
	LAi_SetCitizenType(ch); //LAi_SetHuberStayType(ch);
//	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	ch.greeting = "Gr_Francois de Vigny";
	AddGameCharacter(n, ch);

	// Pointe a Pitre Mistress
	ch.old.name		= "Amarante";
	ch.old.lastname		= "Bontin";
	ch.name			= TranslateString("", "Amarante");
	ch.lastname		= TranslateString("", "Bontin");
	ch.id			= "PaP_Mistress";
	ch.model		= "Brinkley";
	ch.sound_type		= "female_citizen";
	ch.sex			= "woman";
	GiveItem2Character(ch, "Piratesdagger");
	ch.location		= "PaP_Brothel";
	ch.location.group 	= "goto";
	ch.location.locator 	= "goto3";
	ch.Dialog.Filename 	= "mistress_dialog.c";
	ch.greeting		= "Gr_Brothel's mom";//MAXIMUS
	ch.rank			= 1;
	ch.experience		= "10000";
	ch.skill.Leadership	= "1";
	ch.skill.Fencing	= "10";
	ch.skill.Sailing	= "1";
	ch.skill.Accuracy	= "10";
	ch.skill.Cannons	= "1";
	ch.skill.Grappling	= "1";
	ch.skill.Repair		= "1";
	ch.skill.Defence	= "10";
	ch.skill.Commerce	= "1";
	ch.skill.Sneak		= "10";
	ch.money		= "1000";
	LAi_SetHP(ch, 1500.0, 1500.0);
	LAi_SetWarriorType(ch);
	LAi_warrior_DialogEnable(ch, true);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	AddGameCharacter(n, ch);

	///////////////////////////////////////////////////////////////////////////////////////////////
	// SOLDIERS
	///////////////////////////////////////////////////////////////////////////////////////////////
			//guard
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "Guadeloupe_guard_1";
	ch.model = 2; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Guadeloupe_port";
	ch.location.group = "soldiers";
	ch.location.locator = "soldier1";
	ch.Dialog.Filename = "Falaise De Fleur Soldier_dialog.c";
	ch.nation = FRANCE;
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
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);

			//guard
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "Guadeloupe_guard_2";
	ch.model = 3; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Guadeloupe_port";
	ch.location.group = "soldiers";
	ch.location.locator = "soldier2";
	ch.Dialog.Filename = "Falaise De Fleur Soldier_dialog.c";
	ch.nation = FRANCE;
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
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);

			//guard
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "Guadeloupe_guard_3";
	ch.model = 3; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Guadeloupe_port";
	ch.location.group = "soldiers";
	ch.location.locator = "soldier3";
	ch.Dialog.Filename = "Falaise De Fleur Soldier_dialog.c";
	ch.nation = FRANCE;
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
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);

			//guard
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "Guadeloupe_guard_4";
	ch.model = 3; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Guadeloupe_port";
	ch.location.group = "soldiers";
	ch.location.locator = "soldier4";
	ch.Dialog.Filename = "Falaise De Fleur Soldier_dialog.c";
	ch.nation = FRANCE;
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
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);

			//guard
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "Guadeloupe_guard_5";
	ch.model = 3; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Guadeloupe_port";
	ch.location.group = "soldiers";
	ch.location.locator = "soldier5";
	ch.Dialog.Filename = "Falaise De Fleur Soldier_dialog.c";
	ch.nation = FRANCE;
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
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);

			//guard
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "Guadeloupe_guard_6";
	ch.model = 3; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Guadeloupe_port";
	ch.location.group = "soldiers";
	ch.location.locator = "soldier6";
	ch.Dialog.Filename = "Falaise De Fleur Soldier_dialog.c";
	ch.nation = FRANCE;
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
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);

			//guard
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "Guadeloupe_guard_7";
	ch.model = 3; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Guadeloupe_port";
	ch.location.group = "soldiers";
	ch.location.locator = "soldier7";
	ch.Dialog.Filename = "Falaise De Fleur Soldier_dialog.c";
	ch.nation = FRANCE;
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
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);

			//Patrol
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "Guadeloupe_patrol_1";
	ch.model = 5; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Guadeloupe_port";
	ch.location.group = "patrol";
	ch.location.locator = "patrol1";
	ch.Dialog.Filename = "Patrol_dialog.c";
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
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 22.0, 5.98333);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier"; // was "Gr_Patrol"
	AddGameCharacter(n, ch);

			//Patrol
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "Guadeloupe_patrol_2";
	ch.model = 4; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Guadeloupe_port";
	ch.location.group = "patrol";
	ch.location.locator = "patrol2";
	ch.Dialog.Filename = "Patrol_dialog.c";
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
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 22.0, 1.98333);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier"; // was "Gr_Patrol"
	AddGameCharacter(n, ch);

			//Patrol
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "Guadeloupe_patrol_3";
	ch.model = 4; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Guadeloupe_port";
	ch.location.group = "patrol";
	ch.location.locator = "patrol3";
	ch.Dialog.Filename = "Patrol_dialog.c";
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
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 22.0, 1.98333);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier"; // was "Gr_Patrol"
	AddGameCharacter(n, ch);

			//Patrol
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "Guadeloupe_patrol_4";
	ch.model = 4; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Guadeloupe_port";
	ch.location.group = "patrol";
	ch.location.locator = "patrol4";
	ch.Dialog.Filename = "Patrol_dialog.c";
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
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 22.0, 1.98333);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier"; // was "Gr_Patrol"
	AddGameCharacter(n, ch);

			//Patrol
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "Guadeloupe_patrol_5";
	ch.model = 4; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Guadeloupe_port";
	ch.location.group = "patrol";
	ch.location.locator = "patrol5";
	ch.Dialog.Filename = "Patrol_dialog.c";
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
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 22.0, 1.98333);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier"; // was "Gr_Patrol"
	AddGameCharacter(n, ch);

			//Patrol
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "Guadeloupe_patrol_6";
	ch.model = 4; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Guadeloupe_port";
	ch.location.group = "patrol";
	ch.location.locator = "patrol6";
	ch.Dialog.Filename = "Patrol_dialog.c";
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
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 2.0, 5.98333);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier"; // was "Gr_Patrol"
	AddGameCharacter(n, ch);
	AddGameCharacter(n, ch);

	///////////////////////////////////////////////////////////////////////////////////////////////
	// SOLDIERS
	///////////////////////////////////////////////////////////////////////////////////////////////
			//Patrol
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "Guadeloupe_patrol_7";
	ch.model = 4; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Guadeloupe_port";
	ch.location.group = "patrol";
	ch.location.locator = "patrol7";
	ch.Dialog.Filename = "Patrol_dialog.c";
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
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 2.0, 5.98333);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier"; // was "Gr_Patrol"
	AddGameCharacter(n, ch);

			//Patrol
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "Guadeloupe_patrol_8";
	ch.model = 4; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Guadeloupe_port";
	ch.location.group = "patrol";
	ch.location.locator = "patrol8";
	ch.Dialog.Filename = "Patrol_dialog.c";
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
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 2.0, 5.98333);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier"; // was "Gr_Patrol"
	AddGameCharacter(n, ch);

			//Patrol
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "Guadeloupe_patrol_9";
	ch.model = 4; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Guadeloupe_port";
	ch.location.group = "patrol";
	ch.location.locator = "patrol9";
	ch.Dialog.Filename = "Patrol_dialog.c";
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
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 2.0, 5.98333);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier"; // was "Gr_Patrol"
	AddGameCharacter(n, ch);

			//Patrol
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "Guadeloupe_patrol_10";
	ch.model = 4; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Guadeloupe_port";
	ch.location.group = "patrol";
	ch.location.locator = "patrol10";
	ch.Dialog.Filename = "Patrol_dialog.c";
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
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 2.0, 5.98333);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier"; // was "Gr_Patrol"
	AddGameCharacter(n, ch);

// Screwface : old Pointe_a_pitre_town_01 guards reassign to Entrance of fort

			//Soldier near town gates
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "Guadeloupe_Soldier_3";
	ch.model = 2; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Guadeloupe_Jungle_03";
	ch.location.group = "goto";
	ch.location.locator = "goto6";
	ch.Dialog.Filename = "Falaise De Fleur Soldier_dialog.c";
	ch.nation = FRANCE;
	ch.rank 	= 1;
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
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);

			//Soldier near town gates
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "Guadeloupe_soldier_4";
	ch.model = 1; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Guadeloupe_Jungle_03";
	ch.location.group = "goto";
	ch.location.locator = "goto7";
	ch.Dialog.Filename = "Falaise De Fleur Soldier_dialog.c";
	ch.nation = FRANCE;
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
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);
}
