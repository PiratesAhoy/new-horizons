void CreateTempQuestEnemyCharacters(ref n)
{
	object chobj;
	ref ch;

	makeref(ch, chobj);

			// Капитан фрегата с порохом, который мы должны потопить
	ch.old.name = "Captain";
	ch.old.lastname = "";
	ch.name = TranslateString("","Captain");
	ch.lastname = "";
	ch.id		= "Quest_frigate_captain";
	ch.nation	= FRANCE;
	ch.model	= "capitan";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade10");
	ch.equip.blade = "blade10";
	ch.nodisarm	= 1;				// PB: Disable disarming
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
	ch.money = "1000000";
	ch.Ship.Name = "Volcano";
	ch.Ship.Type = "Battleship1"; // PRS3
	ch.Ship.Stopped = true;
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS24;
	ch.quest.killed.pirates = "0";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			// связной партизан для квеста передачи пушек
	ch.old.name = "Kalen";
	ch.old.lastname = "Mottram";
	ch.name = TranslateString("","Kalen");
	ch.lastname = TranslateString("","Mottram");
	ch.id		= "partizan envoy";
	ch.nation	= ENGLAND;
	ch.model	= "man1";
	ch.sound_type = "male_citizen";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "quest_partizan_envoy.c";
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "0";
	ch.skill.Fencing = "0";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "4";
	ch.skill.Sneak = "5";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

/*	Duplicated in "Story.c"
			// Агент перевозимый Дэниель в захваченный Оксбэй
	ch.old.name = "Tobias";
	ch.old.lastname = "";
	ch.name = TranslateString("","Tobias");
	ch.lastname = "";
	ch.id		= "Counterspy";
	ch.nation = ENGLAND;
	ch.model	= Nations[FRANCE].fantomModel.m0; // PB
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Counterspy_dialog.c";
	ch.greeting = "Gr_Ewan Glover"; // was "Gr_Counterspy" which is identical
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "0";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "5";
	ch.skill.Sneak = "7";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);
*/

			// 1-й Патрульный
	ch.old.name = "French Patrol";
	ch.old.lastname = "";
	ch.name = TranslateString("","French Patrol");
	ch.lastname = "";
	ch.id		= "Fra_military_patrol_01";
	ch.nation = FRANCE;
	ch.model	= Nations[FRANCE].fantomModel.m1; // PB
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "French Patrol_dialog.c";
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
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			// 2-й Патрульный
	ch.old.name = "French Patrol";
	ch.old.lastname = "";
	ch.name = TranslateString("","French Patrol");
	ch.lastname = "";
	ch.id		= "Fra_military_patrol_02";
	ch.nation = FRANCE;
	ch.model	= Nations[FRANCE].fantomModel.m1; // PB
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "French Patrol_dialog.c";
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
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			// 3-й Патрульный
	ch.old.name = "French Patrol";
	ch.old.lastname = "";
	ch.name = TranslateString("","French Patrol");
	ch.lastname = "";
	ch.id		= "Fra_military_patrol_03";
	ch.nation = FRANCE;
	ch.model	= Nations[FRANCE].fantomModel.m1; // PB
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "French Patrol_dialog.c";
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
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			// 1-й Солдат, временно участвующий во всех квестовых постановках
	ch.old.name = "French Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","French Soldier");
	ch.lastname = "";
	ch.id		= "Fra_occupant_temp_01";
	ch.model	= Nations[FRANCE].fantomModel.m1; // PB
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Story_French Soldier_dialog.c";
	ch.greeting = "Gr_Story_French Soldier";
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
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			// 2-й Солдат, временно участвующий во всех квестовых постановках
	ch.old.name = "French Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","French Soldier");
	ch.lastname = "";
	ch.id		= "Fra_occupant_temp_02";
	ch.model	= Nations[FRANCE].fantomModel.m1; // PB
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Story_French Soldier_dialog.c";
	ch.greeting = "Gr_Story_French Soldier";
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
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			// наш моряк, временно участвующий во всех квестовых постановках
	ch.old.name = "sailor";
	ch.old.lastname = "";
	ch.name = TranslateString("","sailor");
	ch.lastname = "";
	ch.id		= "quest_sailor_tmp";
	ch.nation = ENGLAND;
	ch.sound_type = "seaman";
	ch.model	= "korsar";
	ch.act.escape = false;
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade6");
	ch.equip.blade = "blade6";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "quest_sailor_tmp.c";
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "0";
	ch.skill.Fencing = "0";
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

			// 1-й французский моряк, временно участвующий во всех квестовых постановках
	ch.old.name = "French";
	ch.old.lastname = "Sailor";
	ch.name = TranslateString("","French");
	ch.lastname = TranslateString("","Sailor");
	ch.id		= "quest_french_sailor_tmp_1";
	ch.model	= Nations[FRANCE].fantomModel.m1; // PB
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "quest_enemy_sailor_tmp.c";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "0";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			// 2-й французский моряк, временно участвующий во всех квестовых постановках
	ch.old.name = "French";
	ch.old.lastname = "Sailor";
	ch.name = TranslateString("","French");
	ch.lastname = TranslateString("","Sailor");
	ch.id		= "quest_french_sailor_tmp_2";
	ch.model	= Nations[FRANCE].fantomModel.m1; // PB
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "quest_enemy_sailor_tmp.c";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "0";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			// 3-й французский моряк, временно участвующий во всех квестовых постановках
	ch.old.name = "French";
	ch.old.lastname = "Sailor";
	ch.name = TranslateString("","French");
	ch.lastname = TranslateString("","Sailor");
	ch.id		= "quest_french_sailor_tmp_3";
	ch.model	= Nations[FRANCE].fantomModel.m1; // PB
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "quest_enemy_sailor_tmp.c";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "0";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			// 4-й французский моряк, временно участвующий во всех квестовых постановках
	ch.old.name = "French";
	ch.old.lastname = "Sailor";
	ch.name = TranslateString("","French");
	ch.lastname = TranslateString("","Sailor");
	ch.id		= "quest_french_sailor_tmp_4";
	ch.model	= Nations[FRANCE].fantomModel.m1; // PB
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "quest_enemy_sailor_tmp.c";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "0";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			// 5-й французский моряк, временно участвующий во всех квестовых постановках
	ch.old.name = "French";
	ch.old.lastname = "Sailor";
	ch.name = TranslateString("","French");
	ch.lastname = TranslateString("","Sailor");
	ch.id		= "quest_french_sailor_tmp_5";
	ch.model	= Nations[FRANCE].fantomModel.m1; // PB
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "quest_enemy_sailor_tmp.c";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "0";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			// 1-й мой моряк, временно участвующий во всех квестовых сражениях
	ch.old.name = "Sailor";
	ch.old.lastname = "";
	ch.name = TranslateString("","Sailor");
	ch.lastname = "";
	ch.id		= "quest_my_sailor_tmp_1";
	ch.model	= "corsair1";
	ch.sound_type = "seaman";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "bladeC12");
	ch.equip.blade = "bladeC12";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "quest_my_sailor_tmp.c";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "0";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			// 2-й мой моряк, временно участвующий во всех квестовых сражениях
	ch.old.name = "Sailor";
	ch.old.lastname = "";
	ch.name = TranslateString("","Sailor");
	ch.lastname = "";
	ch.id		= "quest_my_sailor_tmp_2";
	ch.model	= "corsair2";
	ch.sound_type = "seaman";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "quest_my_sailor_tmp.c";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "0";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			// 3-й мой моряк, временно участвующий во всех квестовых сражениях
	ch.old.name = "Sailor";
	ch.old.lastname = "";
	ch.name = TranslateString("","Sailor");
	ch.lastname = "";
	ch.id		= "quest_my_sailor_tmp_3";
	ch.model	= "corsair3";
	ch.sound_type = "seaman";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade7");
	ch.equip.blade = "blade7";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "quest_my_sailor_tmp.c";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "0";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			// 4-й мой моряк, временно участвующий во всех квестовых сражениях
	ch.old.name = "Sailor";
	ch.old.lastname = "";
	ch.name = TranslateString("","Sailor");
	ch.lastname = "";
	ch.id		= "quest_my_sailor_tmp_4";
	ch.model	= "shkiper";
	ch.sound_type = "seaman";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade6");
	ch.equip.blade = "blade6";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "quest_my_sailor_tmp.c";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "0";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			// сапер, временно участвующий в квестовых постановках
	ch.old.name = "Sapper";
	ch.old.lastname = "";
	ch.name = TranslateString("","Sapper");
	ch.lastname = "";
	ch.id		= "quest_sapper";
	ch.model	= "chelovek";
	ch.sound_type = "seaman";
	ch.act.escape = 0;
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade36");
	ch.equip.blade = "blade36";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "quest_sapper.c";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "0";
	ch.skill.Fencing = "2";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "4";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "5";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			// посыльный от Сайлхарда к Изенбрандту, на арест Даниель
	ch.old.name = "Simon";
	ch.old.lastname = "Buck";
	ch.name = TranslateString("","Simon");
	ch.lastname = TranslateString("","Buck");
	ch.id		= "England Herald";
	ch.model	= "chelovek";
	ch.sound_type = "pirate";
	ch.act.escape = 0;
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Herald_dialog.c";
	ch.greeting = "Gr_Herald";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "0";
	ch.skill.Fencing = "2";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "5";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// 1-й стражник рудников на Оксбэй
	ch.old.name = "Rene";
	ch.old.lastname = "Bouillon";
	ch.name = TranslateString("","Rene");
	ch.lastname = TranslateString("","Bouillon");
	ch.id		= "mine keeper 1";
	ch.model	= "man"+(rand(5)+1);
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade36");
	ch.equip.blade = "blade36";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "mine keeper_dialog.c";
	ch.rank 	= 2;
	ch.reputation = "40";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "4";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetCivilianGuardianType(ch); // PB
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_Mine Keeper";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			// 1-й Телохранитель Сайлхарда
	ch.old.name = "Bodyguard";
	ch.old.lastname = "";
	ch.name = TranslateString("","Bodyguard");
	ch.lastname = "";
	ch.id		= "quest_eng_officer_01";
	ch.model	= "capitan1";
	ch.sound_type = "soldier";
	ch.activity_begin = "0";
	ch.activity_end = "24";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "bladeC33");
	ch.equip.blade = "bladeC33";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Silehard_bodyguard_dialog.c";
	ch.nation = ENGLAND;
	ch.rank 	= 4;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "3";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "4";
	ch.skill.Cannons = "8";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "7";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "1000";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_Silehard_bodyguard";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Rene Dutruel
	ch.old.name = "Rene";
	ch.old.lastname = "Dutruel";
	ch.name = TranslateString("","Rene");
	ch.lastname = TranslateString("","Dutruel");
	ch.id		= "Rene Dutruel";
	ch.model	= "man3";
	ch.sound_type = "male_citizen";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade7");
	ch.equip.blade = "blade7";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Rene Dutruel_dialog.c";
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
	ch.skill.Commerce = "3";
	ch.skill.Sneak = "1";
	ch.money = "500";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

//=====================================================Mosh========================================================

			// 1-й Страж дома Реймса
	ch.old.name = "Ian";
	ch.old.lastname = "Bigg";
	ch.name = TranslateString("","Ian");
	ch.lastname = TranslateString("","Bigg");
	ch.id		= "Rheims_guard_temp_01";//Id For Teleport
	ch.model	= "capitan";
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
	ch.Dialog.Filename = "Backoff";//dialog filename
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


			// 2-й Страж дома Реймса
	ch.old.name = "Rabel";
	ch.old.lastname = "Bonnat";
	ch.name = TranslateString("","Rabel");
	ch.lastname = TranslateString("","Bonnat");
	ch.id		= "Rheims_guard_temp_02";
	ch.model	= "fatman";
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "pistol1");
	ch.equip.gun = "pistol1";
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


//--------------------------------Soldiers-------------------------------
			// Eng_Soldier1
	ch.old.name = "Brendan";
	ch.old.lastname = "Attwick";
	ch.name = TranslateString("","Brendan");
	ch.lastname = TranslateString("","Attwick");
	ch.id		= "Brendan Attwick";
	ch.model	= Nations[ENGLAND].fantomModel.m1; // PB
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Brendan Attwick_dialog.c";// Daniel Arrest
	ch.nation = ENGLAND;
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

			// Eng_Soldier2
	ch.old.name = "Edd";
	ch.old.lastname = "Pease";
	ch.name = TranslateString("","Edd");
	ch.lastname = TranslateString("","Pease");
	ch.id		= "Edd Pease";
	ch.model	= Nations[ENGLAND].fantomModel.m1; // PB
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Brendan Attwick_dialog.c";
	ch.nation = ENGLAND;
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

			// Eng_Soldier3
	ch.old.name = "Kevin";
	ch.old.lastname = "Renner";
	ch.name = TranslateString("","Kevin");
	ch.lastname = TranslateString("","Renner");
	ch.id		= "Kevin Renner";
	ch.model	= Nations[ENGLAND].fantomModel.m1; // PB
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Brendan Attwick_dialog.c";
	ch.nation = ENGLAND;
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

			// Eng_Soldier4
	ch.old.name = "Terry";
	ch.old.lastname = "Sellar";
	ch.name = TranslateString("","Terry");
	ch.lastname = TranslateString("","Sellar");
	ch.id		= "Terry Sellar";
	ch.model	= Nations[ENGLAND].fantomModel.m1; // PB
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Brendan Attwick_dialog.c";
	ch.nation = ENGLAND;
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

			// Eng_Soldier5
	ch.old.name = "Donald";
	ch.old.lastname = "Drake";
	ch.name = TranslateString("","Donald");
	ch.lastname = TranslateString("","Drake");
	ch.id		= "Donald Drake";
	ch.model	= Nations[ENGLAND].fantomModel.m1; // PB
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Brendan Attwick_dialog.c";
	ch.nation = ENGLAND;
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


			// Eng_Soldier6
	ch.old.name = "David";
	ch.old.lastname = "Much";
	ch.name = TranslateString("","David");
	ch.lastname = TranslateString("","Much");
	ch.id		= "David Much";
	ch.model	= Nations[ENGLAND].fantomModel.m1; // PB
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "David Much_dialog.c";
	ch.nation = ENGLAND;
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

				//Prison Guard1
	ch.old.name = "Cole";
	ch.old.lastname = "Brock";
	ch.name = TranslateString("","Cole");
	ch.lastname = TranslateString("","Brock");
	ch.id		= "Cole Brock";
	ch.model	= Nations[ENGLAND].fantomModel.m1; // PB
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "Greenford_prison";
	ch.location.group = "goto";
	ch.location.locator = "goto13";
	ch.Dialog.Filename = "Cole Brock_dialog.c";
	ch.rank 	= 1;
	ch.reputation = "none";
	ch.experience = "10";
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
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			// Shaggy Harry - Pirat
	ch.old.name = "Shaggy";
	ch.old.lastname = "Harry";
	ch.name = TranslateString("","Shaggy");
	ch.lastname = TranslateString("","Harry");
	ch.id		= "Shaggy Harry";
	ch.model	= "shkiper";
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "goto";
	ch.location.locator = "character7";
	ch.Dialog.Filename = "Shaggy Harry_dialog.c";
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
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_Shaggy Harry";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Stephan";
	ch.old.lastname = "Bonser";
	ch.name = TranslateString("","Stephan");
	ch.lastname = TranslateString("","Bonser");
	ch.id		= "Stephan Bonser";
	ch.model = "man4";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade7");
	ch.equip.blade = "blade7";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "none";
	ch.Dialog.Filename = "Stephan Bonser_dialog.c";
	ch.greeting = "Gr_Stephan Bonser";
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
	ch.money = "10";
	LAi_SetCivilianGuardianType(ch); // PB
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Oswald";
	ch.old.lastname = "Chappel";
	ch.name = TranslateString("","Oswald");
	ch.lastname = TranslateString("","Chappel");
	ch.id		= "Oswald Chappel";
	ch.model = "korsar";
	ch.sex = "man";
	ch.sound_type = "seaman";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "none";
	ch.Dialog.Filename = "Oswald Chappel_dialog.c";
	ch.rank 	= 1;
	ch.reputation = "22";
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
	LAi_SetCivilianGuardianType(ch); // PB
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Oswald Chappel";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Gyles";
	ch.old.lastname = "Dubois";
	ch.name = TranslateString("","Gyles");
	ch.lastname = TranslateString("","Dubois");
	ch.id		= "Gyles Dubois";
	ch.model = "fisherman";
	ch.sex = "man";
	ch.sound_type = "seaman";
	GiveItem2Character(ch, "blade48");
	ch.equip.blade = "blade48";
	ch.location	= "none"; //redmond_shore_01
	ch.location.group = "goto";
	ch.location.locator = "none";//locator8
	ch.Dialog.Filename = "Gyles Dubois_dialog.c";
	ch.rank 	= 1;
	ch.reputation = "22";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetCivilianGuardianType(ch); // PB
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Gyles Dubois";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

//====================================================================================================================
}
