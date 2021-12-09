void CreateSideQuestCharacters(ref n)
{
	object chobj;
	ref ch;
	makeref(ch, chobj);

			// Rian Dekkers -- towngirl1
	ch.old.name = "Rian";
	ch.old.lastname = "Dekkers";
	ch.name = TranslateString("", "Rian");
	ch.lastname = TranslateString("", "Dekkers");
	ch.id		= "Rian Dekkers";
	ch.model	= "towngirl1";
	ch.sex = "woman";
	LAi_NoRebirthEnable(ch);
	ch.sound_type = "female_citizen";
	ch.location	= "Douwesen_town";
	ch.location.group = "merchant";
	ch.location.locator = "merchant1";
	ch.Dialog.Filename = "Unhappy women_dialog.c";
	ch.greeting = "Gr_Unhappy women";
	ch.nation = HOLLAND;
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
	LAi_SetStayType(ch); // Petros: Was LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.6, 22.0);//MAXIMUS: women near town hall at night look very strange
//	ch.questchar = true;//MAXIMUS: identifier for captives, commented out by Grey Roger to allow name to change
	LAi_group_MoveCharacter(ch, "UNHAPPY_WOMEN"); // Grey Roger: giving them their own AI group prevents confusion from fights with other groups
	AddGameCharacter(n, ch);

			// Janneke Blinkerhof -- towngirl2
	ch.old.name = "Janneke";
	ch.old.lastname = "Blinkerhof";
	ch.name = TranslateString("", "Janneke");
	ch.lastname = TranslateString("", "Blinkerhof");
	ch.id		= "Janneke Blinkerhof";
	ch.model	= "towngirl2";
	ch.sex = "woman";
	LAi_NoRebirthEnable(ch);
	ch.sound_type = "female_citizen";
	ch.location	= "Douwesen_town";
	ch.location.group = "merchant";
	ch.location.locator = "merchant2";
	ch.Dialog.Filename = "Unhappy women_dialog.c";
	ch.greeting = "Gr_Unhappy women";
	ch.nation = HOLLAND;
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
	LAi_SetStayType(ch); // Petros: Was LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.6, 22.0);//MAXIMUS: women near town hall at night look very strange
//	ch.questchar = true;//MAXIMUS: identifier for captives, commented out by Grey Roger to allow name to change
	LAi_group_MoveCharacter(ch, "UNHAPPY_WOMEN"); // Grey Roger: giving them their own AI group prevents confusion from fights with other groups
	AddGameCharacter(n, ch);

			// Lisebet Schefold -- towngirl3
	ch.old.name = "Lisebet";
	ch.old.lastname = "Schefold";
	ch.name = TranslateString("", "Lisebet");
	ch.lastname = TranslateString("", "Schefold");
	ch.id		= "Lisebet Schefold";
	ch.model	= "towngirl3";
	ch.sex = "woman";
	LAi_NoRebirthEnable(ch);
	ch.sound_type = "female_citizen";
	ch.location	= "Douwesen_town";
	ch.location.group = "merchant";
	ch.location.locator = "merchant3";
	ch.Dialog.Filename = "Unhappy women_dialog.c";
	ch.greeting = "Gr_Unhappy women";
	ch.nation = HOLLAND;
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
	LAi_SetStayType(ch); // Petros: Was LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.6, 22.0);
//	ch.questchar = true;//MAXIMUS: identifier for captives, commented out by Grey Roger to allow name to change
	LAi_group_MoveCharacter(ch, "UNHAPPY_WOMEN"); // Grey Roger: giving them their own AI group prevents confusion from fights with other groups
	AddGameCharacter(n, ch);

			// Gheraed Drabbe -- man3
	ch.old.name = "Gheraed";
	ch.old.lastname = "Drabbe";
	ch.name = TranslateString("", "Gheraed");
	ch.lastname = TranslateString("", "Drabbe");
	ch.id		= "Gheraed Drabbe";
	ch.model	= "man3";
	ch.sex = "man";
	LAi_NoRebirthEnable(ch);
	ch.sound_type = "male_citizen";
	ch.location	= "none";
	ch.location.group = "sit";
	ch.location.locator = "sit5";
	ch.Dialog.Filename = "Gheraed Drabbe_dialog.c";
	ch.nation = HOLLAND;
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
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.greeting = "Gr_Gheraed Drabbe";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			// Balltesar Figueiredo -- man3
	ch.old.name = "Balltesar";
	ch.old.lastname = "Figueiredo";
	ch.name = TranslateString("", "Balltesar");
	ch.lastname = TranslateString("", "Figueiredo");
	ch.id		= "Balltesar Figueiredo";
	ch.model	= "man2";
	ch.sex = "man";
	LAi_NoRebirthEnable(ch);
	ch.sound_type = "male_citizen";
	ch.location	= "none";
	ch.location.group = "sit";
	ch.location.locator = "sit7";
	ch.Dialog.Filename = "Balltesar Figueiredo_dialog.c";
	ch.nation = HOLLAND;
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
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.greeting = "Gr_Balltesar Figueiredo";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			// Father Gareth -- man3
	ch.old.name = "Father";
	ch.old.lastname = "Gareth";
	ch.name = TranslateString("", "Father");
	ch.lastname = TranslateString("", "Gareth");
	ch.id		= "Father Gareth";
	ch.model	= "monk2";
	ch.sex = "man";
	LAi_NoRebirthEnable(ch);
	ch.sound_type = "priest";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "goto13";
	ch.Dialog.Filename = "Father Gareth_dialog.c";
	ch.nation = ENGLAND;
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
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Father Gareth";
//	ch.questchar = true;//MAXIMUS: identifier for captives, commented out by Grey Roger to allow name to change
	AddGameCharacter(n, ch);

				// Mergildo Hurtado - капитан барка со священниками
	ch.old.name = "Mergildo";
	ch.old.lastname = "Hurtado";
	ch.name = TranslateString("", "Mergildo");
	ch.lastname = TranslateString("", "Hurtado");
	ch.id		= "Mergildo Hurtado";
	ch.model	= Nations[SPAIN].fantomModel.m0; // PB
	ch.sex = "man";
	ch.sound_type = "seaman";
	LAi_NoRebirthEnable(ch);
	ch.Ship.AI.GroupName = "saints";
	ch.Ship.AI.Task = "attack";
	ch.nation = SPAIN;
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Mergildo Hurtado_dialog.c";
	ch.Ship.Name = "Montanez";
	ch.Ship.Type = "Barque1"; // PRS3
	ch.Ship.Stopped = true;
	ch.skipFalseFlag = true; // PB: Skip False Flag Detection
	ch.nosurrender = 2; // PB
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	ch.rank 	= 1;
	ch.reputation = "22";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "4";
	ch.skill.Accuracy = "2";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_Mergildo Hurtado";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Jordano - сын кузнеца на Муэле
	ch.old.name = "Jordano";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Jordano");
	ch.lastname = "";
	ch.id		= "Jordano";
	ch.model = "Jordano";  // GR (was "Diller", originally was "man4")
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	LAi_NoRebirthEnable(ch);
	GiveItem2Character(ch, "blade36");
	ch.equip.blade = "blade36";
	ch.location	= "none"; //redmond_shore_01
	ch.location.group = "goto";
	ch.location.locator = "none";//locator8
	ch.Dialog.Filename = "Jordano_dialog.c";
	ch.greeting = "Gr_Jordano";
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
	ch.model.height = 1.75;
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				//Yedam Kinne - дивет в Гринфорде - подделывает документы и подчерки.
	ch.old.name = "Yedam";
	ch.old.lastname = "Kinne";
	ch.name = TranslateString("", "Yedam");
	ch.lastname = TranslateString("", "Kinne");
	ch.id		= "Yedam Kinne";
	ch.model	= "man6_1";
	ch.sound_type = "pirate";
	ch.sex = "man";
	ch.nation = ENGLAND;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Yedam Kinne_house";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "Yedam Kinne_dialog.c";
	ch.greeting = "Gr_Yedam Kinne";
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

				// 
	ch.old.name = "Animist";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Animist");
	ch.lastname = "";
	ch.id		= "ANIMISTS_01";
	ch.model = "ANIMISTS2";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade36");
	ch.equip.blade = "blade36";
	ch.location	= "Muelle_ANIMISTS";
	ch.location.group = "goto";
	ch.location.locator = "goto4";
	ch.Dialog.Filename = "Quest_ANIMISTS_dialog.c";
	ch.greeting = "Gr_Quest_ANIMISTS";
	ch.rank 	= 1;
	ch.reputation = "22";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetCivilianPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "ANIMISTS_SOLDIERS");
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// 
	ch.old.name = "Animist";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Animist");
	ch.lastname = "";
	ch.id		= "ANIMISTS_02";
	ch.model = "ANIMISTS2";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade36");
	ch.equip.blade = "blade36";
	ch.location	= "Muelle_ANIMISTS";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "Quest_ANIMISTS_dialog.c";
	ch.greeting = "Gr_Quest_ANIMISTS";
	ch.rank 	= 1;
	ch.reputation = "22";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetCivilianPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "ANIMISTS_SOLDIERS");
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// 
	ch.old.name = "Animist";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Animist");
	ch.lastname = "";
	ch.id		= "ANIMISTS_03";
	ch.model = "ANIMISTS2";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade36");
	ch.equip.blade = "blade36";
	ch.location	= "Muelle_ANIMISTS";
	ch.location.group = "goto";
	ch.location.locator = "goto16";
	ch.Dialog.Filename = "Quest_ANIMISTS_dialog.c";
	ch.greeting = "Gr_Quest_ANIMISTS";
	ch.rank 	= 1;
	ch.reputation = "22";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetCivilianPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "ANIMISTS_SOLDIERS");
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// 
	ch.old.name = "Animist";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Animist");
	ch.lastname = "";
	ch.id		= "ANIMISTS_04";
	ch.model = "ANIMISTS2";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade36");
	ch.equip.blade = "blade36";
	ch.location	= "Muelle_ANIMISTS";
	ch.location.group = "goto";
	ch.location.locator = "goto8";
	ch.Dialog.Filename = "Quest_ANIMISTS_dialog.c";
	ch.greeting = "Gr_Quest_ANIMISTS";
	ch.rank 	= 1;
	ch.reputation = "22";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetCivilianPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "ANIMISTS_SOLDIERS");
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// 
	ch.old.name = "Animist";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Animist");
	ch.lastname = "";
	ch.id		= "ANIMISTS_05";
	ch.model = "ANIMISTS2";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade36");
	ch.equip.blade = "blade36";
	ch.location	= "Muelle_ANIMISTS";
	ch.location.group = "goto";
	ch.location.locator = "goto9";
	ch.Dialog.Filename = "Quest_ANIMISTS_dialog.c";
	ch.greeting = "Gr_Quest_ANIMISTS";
	ch.rank 	= 1;
	ch.reputation = "22";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetCivilianPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "ANIMISTS_SOLDIERS");
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// 
	ch.old.name = "Animist";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Animist");
	ch.lastname = "";
	ch.id		= "ANIMISTS_06";
	ch.model = "ANIMISTS2";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade36");
	ch.equip.blade = "blade36";
	ch.location	= "Muelle_ANIMISTS";
	ch.location.group = "goto";
	ch.location.locator = "goto2";
	ch.Dialog.Filename = "Quest_ANIMISTS_dialog.c";
	ch.greeting = "Gr_Quest_ANIMISTS";
	ch.rank 	= 1;
	ch.reputation = "22";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetCivilianPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "ANIMISTS_SOLDIERS");
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// 
	ch.old.name = "Animist";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Animist");
	ch.lastname = "";
	ch.id		= "ANIMISTS_07";
	ch.model = "ANIMISTS2";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade36");
	ch.equip.blade = "blade36";
	ch.location	= "Muelle_ANIMISTS";
	ch.location.group = "goto";
	ch.location.locator = "goto13";
	ch.Dialog.Filename = "Quest_ANIMISTS_dialog.c";
	ch.greeting = "Gr_Quest_ANIMISTS";
	ch.rank 	= 1;
	ch.reputation = "22";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetCivilianPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "ANIMISTS_SOLDIERS");
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// 
	ch.old.name = "Animist";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Animist");
	ch.lastname = "";
	ch.id		= "ANIMISTS_08";
	ch.model = "ANIMISTS2";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade36");
	ch.equip.blade = "blade36";
	ch.location	= "Muelle_ANIMISTS";
	ch.location.group = "goto";
	ch.location.locator = "goto11";
	ch.Dialog.Filename = "Quest_ANIMISTS_dialog.c";
	ch.greeting = "Gr_Quest_ANIMISTS";
	ch.rank 	= 1;
	ch.reputation = "22";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetCivilianPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "ANIMISTS_SOLDIERS");
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// 
	ch.old.name = "Animist";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Animist");
	ch.lastname = "";
	ch.id		= "ANIMISTS_09";
	ch.model = "ANIMISTS2";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade36");
	ch.equip.blade = "blade36";
	ch.location	= "Muelle_ANIMISTS";
	ch.location.group = "goto";
	ch.location.locator = "goto12";
	ch.Dialog.Filename = "Quest_ANIMISTS_dialog.c";
	ch.greeting = "Gr_Quest_ANIMISTS";
	ch.rank 	= 1;
	ch.reputation = "22";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetCivilianPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "ANIMISTS_SOLDIERS");
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Dark teacher
	ch.old.name = "Dark Teacher";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Dark Teacher");
	ch.lastname = "";
	ch.id		= "Dark Teacher";
	ch.model = "ANIMISTS1";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.nation = PIRATE;
	if (ENABLE_WEAPONSMOD)
	{
//		GiveItem2Character(ch, "blade20+2");	// Asiatic broadsword
		GiveItem2Character(ch, "bladeC36+2");	// Katana
	}
	else
	{
//		GiveItem2Character(ch, "blade20");	// Asiatic broadsword
		GiveItem2Character(ch, "bladeC36");	// Katana
	}
	GiveItem2Character(ch, "commonarmor");
//	ch.equip.blade = "blade20";
	ch.equip.blade = "bladeC36";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "Muelle_ANIMISTS";
	ch.location.group = "goto";
	ch.location.locator = "goto28";
	ch.Dialog.Filename = "Dark teacher_dialog.c";
	ch.rank 	= 10;
	ch.reputation = "22";
	ch.experience = "0";
	ch.skill.Leadership = "10";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "10";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	Ch.Perks.list.Toughness = true;
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 120.0, 120.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// 
	ch.old.name = "Mystery Man";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Mystery Man");
	ch.lastname = "";
	ch.id		= "Mystery_Man_01";
	ch.model = "ANIMISTS2";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.act.escape = 0;
	ch.activity_begin = "0";
	ch.activity_end = "24";
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "Piratesdagger");
	ch.equip.blade = "Piratesdagger";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "none";//"Redmond"; //redmond_shore_01
	ch.location.group = "";
	ch.location.locator = "";//locator8
	ch.Dialog.Filename = "Quest_ANIMISTS_dialog.c";
	ch.greeting = "Gr_Quest_ANIMISTS";
	ch.Ship.Name = "Hundred Devils"; // KK
	ch.Ship.Type = "Barque2"; // PRS3
	ch.Ship.Stopped = true;
// KK -->
	ch.Ship.EmblemedSails.normalTex = "sail_whole_red_plain.tga"; // PB
	ch.Ship.EmblemedSails.nationFileName = "sail_whole_red_plain.tga"; // PB
	ch.nosurrender = 2;
	ch.boardingmodels = "Animists";
// <-- KK
	ch.skipRM = true; // PB: Skip Relations Mod
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

				// 
	ch.old.name = "Mystery Man";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Mystery Man");
	ch.lastname = "";
	ch.id		= "Mystery_Man_02";
	ch.model = "ANIMISTS2";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.act.escape = 0;
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "Piratesdagger");
	ch.equip.blade = "Piratesdagger";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "none";//"Redmond"; //redmond_shore_01
	ch.location.group = "";
	ch.location.locator = "";//locator8
	ch.Dialog.Filename = "Quest_ANIMISTS_dialog.c";
	ch.old.Dialog.Filename = ch.Dialog.Filename; // KK
	ch.greeting = "Gr_Quest_ANIMISTS";
	ch.Ship.Name = "666"; // KK
	ch.Ship.Type = "Brig2"; // PRS3
	ch.Ship.Stopped = true;
	ch.Flags.Pirate = 6; // GR: Animists Pirate Flag
	ch.Flags.Pirate.texture = 1;
// KK -->
	ch.Ship.EmblemedSails.normalTex = "sail_whole_red_plain.tga"; // PB
	ch.Ship.EmblemedSails.nationFileName = "sail_whole_red_plain.tga"; // PB
	ch.nosurrender = 2;
	ch.boardingmodels = "Animists";
// <-- KK
	ch.skipRM = true; // PB: Skip Relations Mod
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

				// 
	ch.old.name = "Mystery Man";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Mystery Man");
	ch.lastname = "";
	ch.id		= "Mystery_Man_03";
	ch.model = "ANIMISTS2";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.act.escape = 0;
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "Piratesdagger");
	ch.equip.blade = "Piratesdagger";
	ch.location	= "none";//"Redmond"; //redmond_shore_01
	ch.location.group = "";
	ch.location.locator = "";//locator8
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

	ch.old.name = "Mystery Man";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Mystery Man");
	ch.lastname = "";
	ch.id		= "Mystery_Man_04";
	ch.model = "ANIMISTS2";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.act.escape = 0;
	ch.activity_begin = "0";
	ch.activity_end = "24";
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "Piratesdagger");
	ch.equip.blade = "Piratesdagger";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "none";//"Redmond"; //redmond_shore_01
	ch.location.group = "";
	ch.location.locator = "";//locator8
	ch.Dialog.Filename = "Quest_ANIMISTS_dialog.c";
	ch.greeting = "Gr_Quest_ANIMISTS";
	ch.Ship.Name = "Hundred Devils"; // KK
	ch.Ship.Type = "Barque2"; // PRS3
	ch.Ship.Stopped = true;
	ch.Flags.Pirate = 6; // GR: Animists Pirate Flag
	ch.Flags.Pirate.texture = 1;
// KK -->
	ch.Ship.EmblemedSails.normalTex = "sail_whole_red_plain.tga"; // PB
	ch.Ship.EmblemedSails.nationFileName = "sail_whole_red_plain.tga"; // PB
	ch.nosurrender = 2;
	ch.boardingmodels = "Animists";
// <-- KK
	ch.skipRM = true; // PB: Skip Relations Mod
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

	ch.old.name = "Mystery Man";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Mystery Man");
	ch.lastname = "";
	ch.id		= "Mystery_Man_05";
	ch.model = "ANIMISTS2";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.act.escape = 0;
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "Piratesdagger");
	ch.equip.blade = "Piratesdagger";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "none";//"Redmond"; //redmond_shore_01
	ch.location.group = "";
	ch.location.locator = "";//locator8
	ch.Dialog.Filename = "Quest_ANIMISTS_dialog.c";
	ch.old.Dialog.Filename = ch.Dialog.Filename; // KK
	ch.greeting = "Gr_Quest_ANIMISTS";
	ch.Ship.Name = "666"; // KK
	ch.Ship.Type = "Brig2"; // PRS3
	ch.Ship.Stopped = true;
// KK -->
	ch.Ship.EmblemedSails.normalTex = "sail_whole_red_plain.tga"; // PB
	ch.Ship.EmblemedSails.nationFileName = "sail_whole_red_plain.tga"; // PB
	ch.nosurrender = 2;
	ch.boardingmodels = "Animists";
// <-- KK
	ch.skipRM = true; // PB: Skip Relations Mod
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

	ch.old.name = "Mystery Man";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Mystery Man");
	ch.lastname = "";
	ch.id		= "Mystery_Man_06";
	ch.model = "ANIMISTS2";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.act.escape = 0;
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "Piratesdagger");
	ch.equip.blade = "Piratesdagger";
	ch.location	= "none";//"Redmond"; //redmond_shore_01
	ch.location.group = "";
	ch.location.locator = "";//locator8
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

	ch.old.name = "Mystery Man";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Mystery Man");
	ch.lastname = "";
	ch.id		= "Mystery_Man_07";
	ch.model = "ANIMISTS2";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.act.escape = 0;
	ch.activity_begin = "0";
	ch.activity_end = "24";
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "Piratesdagger");
	ch.equip.blade = "Piratesdagger";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "none";//"Redmond"; //redmond_shore_01
	ch.location.group = "";
	ch.location.locator = "";//locator8
	ch.Dialog.Filename = "Quest_ANIMISTS_dialog.c";
	ch.greeting = "Gr_Quest_ANIMISTS";
	ch.Ship.Name = "Hundred Devils"; // KK
	ch.Ship.Type = "Barque2"; // PRS3
	ch.Ship.Stopped = true;
// KK -->
	ch.Ship.EmblemedSails.normalTex = "sail_whole_red_plain.tga"; // PB
	ch.Ship.EmblemedSails.nationFileName = "sail_whole_red_plain.tga"; // PB
	ch.nosurrender = 2;
	ch.boardingmodels = "Animists";
// <-- KK
	ch.skipRM = true; // PB: Skip Relations Mod
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

	ch.old.name = "Mystery Man";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Mystery Man");
	ch.lastname = "";
	ch.id		= "Mystery_Man_08";
	ch.model = "ANIMISTS2";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.act.escape = 0;
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "Piratesdagger");
	ch.equip.blade = "Piratesdagger";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "none";//"Redmond"; //redmond_shore_01
	ch.location.group = "";
	ch.location.locator = "";//locator8
	ch.Dialog.Filename = "Quest_ANIMISTS_dialog.c";
	ch.old.Dialog.Filename = ch.Dialog.Filename; // KK
	ch.greeting = "Gr_Quest_ANIMISTS";
	ch.Ship.Name = "666"; // KK
	ch.Ship.Type = "Brig2"; // PRS3
	ch.Ship.Stopped = true;
// KK -->
	ch.Ship.EmblemedSails.normalTex = "sail_whole_red_plain.tga"; // PB
	ch.Ship.EmblemedSails.nationFileName = "sail_whole_red_plain.tga"; // PB
	ch.nosurrender = 2;
	ch.boardingmodels = "Animists";
// <-- KK
	ch.skipRM = true; // PB: Skip Relations Mod
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

	ch.old.name = "Mystery Man";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Mystery Man");
	ch.lastname = "";
	ch.id		= "Mystery_Man_09";
	ch.model = "ANIMISTS2";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.act.escape = 0;
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "Piratesdagger");
	ch.equip.blade = "Piratesdagger";
	ch.location	= "none";//"Redmond"; //redmond_shore_01
	ch.location.group = "";
	ch.location.locator = "";//locator8
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

	ch.old.name = "Mystery Man";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Mystery Man");
	ch.lastname = "";
	ch.id		= "Mystery_Man_10";
	ch.model = "ANIMISTS2";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.act.escape = 0;
	ch.activity_begin = "0";
	ch.activity_end = "24";
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "Piratesdagger");
	ch.equip.blade = "Piratesdagger";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "none";//"Redmond"; //redmond_shore_01
	ch.location.group = "";
	ch.location.locator = "";//locator8
	ch.Dialog.Filename = "Quest_ANIMISTS_dialog.c";
	ch.greeting = "Gr_Quest_ANIMISTS";
	ch.Ship.Name = "Hundred Devils"; // KK
	ch.Ship.Type = "Barque2"; // PRS3
	ch.Ship.Stopped = true;
// KK -->
	ch.Ship.EmblemedSails.normalTex = "sail_whole_red_plain.tga"; // PB
	ch.Ship.EmblemedSails.nationFileName = "sail_whole_red_plain.tga"; // PB
	ch.nosurrender = 2;
	ch.boardingmodels = "Animists";
// <-- KK
	ch.skipRM = true; // PB: Skip Relations Mod
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

	ch.old.name = "Mystery Man";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Mystery Man");
	ch.lastname = "";
	ch.id		= "Mystery_Man_11";
	ch.model = "ANIMISTS2";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.act.escape = 0;
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "Piratesdagger");
	ch.equip.blade = "Piratesdagger";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "none";//"Redmond"; //redmond_shore_01
	ch.location.group = "";
	ch.location.locator = "";//locator8
	ch.Dialog.Filename = "Quest_ANIMISTS_dialog.c";
	ch.old.Dialog.Filename = ch.Dialog.Filename; // KK
	ch.greeting = "Gr_Quest_ANIMISTS";
	ch.Ship.Name = "666"; // KK
	ch.Ship.Type = "Brig2"; // PRS3
	ch.Ship.Stopped = true;
// KK -->
	ch.Ship.EmblemedSails.normalTex = "sail_whole_red_plain.tga"; // PB
	ch.Ship.EmblemedSails.nationFileName = "sail_whole_red_plain.tga"; // PB
	ch.nosurrender = 2;
	ch.boardingmodels = "Animists";
// <-- KK
	ch.skipRM = true; // PB: Skip Relations Mod
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

	ch.old.name = "Teacher";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Teacher");
	ch.lastname = "";
	ch.id		= "Teacher";
	ch.model = "ANIMISTS2";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.act.escape = 0;
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "Piratesdagger");
	ch.equip.blade = "Piratesdagger";
	ch.location	= "none";//"Redmond"; //redmond_shore_01
	ch.location.group = "";
	ch.location.locator = "";//locator8
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

// Eng Captain Near FdF - SINK THE PIRATE CORVETTE
	ch.old.name = "Simon";
	ch.old.lastname = "Blunden";
	ch.name = TranslateString("", "Simon");
	ch.lastname = TranslateString("", "Blunden");
	ch.id		= "Eng Captain Near FdF";
	ch.model = "corsair1_2";			// Petros: was "Offic_eng"
	ch.sex = "man";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.Ship.AI.GroupName = "England_Captain_Near_FdF";
	ch.Ship.AI.Task = "attack"; // KK was: "runaway"
	GiveItem2Character(ch, "bladeC12");
	ch.equip.blade = "bladeC12";
	ch.location	= "none"
	ch.location.group = "Quest_ships";
	ch.location.locator = "quest_ship_12";		// Petros: was "quest_ship_7"
	ch.Dialog.Filename = "falaise de fleur soldier_dialog.c";
	ch.nation = PIRATE;
	switch(GetCurrentPeriod())
	{
		case PERIOD_EARLY_EXPLORERS:
			ch.Ship.Name = "Sea Monster";
			ch.Ship.Type = 	"FleutWar";				// Skyworm
		break;
		case PERIOD_THE_SPANISH_MAIN:
			ch.Ship.Name = "Sea Monster";
			ch.Ship.Type = 	"FleutWar";				// Skyworm
		break;
		case PERIOD_GOLDEN_AGE_OF_PIRACY:
			ch.Ship.Name = "Marauder";
			ch.Ship.Type = 	"PiratFrigateSup";		// Armada
		break;
		case PERIOD_COLONIAL_POWERS:
			ch.Ship.Name = "Fast Death";
			ch.Ship.Type = 	"PiratCorvette";		// Armada
		break;
		case PERIOD_REVOLUTIONS:
			ch.Ship.Name = "Iceni Queen";
			ch.Ship.Type = 	"SuperFrigate";			// JRMM
		break;
		case PERIOD_NAPOLEONIC:
			ch.Ship.Name = "Iceni Queen";
			ch.Ship.Type = 	"SuperFrigate";			// JRMM
		break;
	}
	ch.skipRM = true; // PB: Skip Relations Mod
	ch.Ship.Stopped = true;
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS16;
	ch.rank 	= 5;
	ch.reputation = "52";
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
	ch.money = "5000";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 200.0, 80.0);
	ch.greeting = "Gr_falaise de fleur soldier";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

// первый наймит губернатора для нападения на Даниель
	ch.old.name = "killer";
	ch.old.lastname = "";
	ch.name = TranslateString("", "killer");
	ch.lastname = "";
	ch.id		= "danielle_quests_killer_1";
	ch.model	= "chameleon";
	ch.sound_type = "pirate";
	ch.act.escape = false;
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "bladeC12");
	ch.equip.blade = "bladeC12";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Danielle hireling_dialog.c";
	ch.greeting = "Gr_Danielle hireling";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "0";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "5";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "5";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

// Joaquin Da Saldanha - FIND THE MISSING SON OF THE SPANISH ADMIRAL (Lucas Da Saldanha quest)
	ch.old.name = "Joaquin";
	ch.old.lastname = "Da Saldanha";
	ch.name = TranslateString("", "Joaquin");
	ch.lastname = TranslateString("", "Da Saldanha");
	ch.id		= "Joaquin Da Saldanha";
	if (GetCurrentPeriod() >= PERIOD_COLONIAL_POWERS) ch.model = "spa_adm_18_2";
	else ch.model = "admiral";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade33");
	ch.equip.blade = "blade33";
	if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)
	{
		GiveItem2Character(ch, "pistol1");
		ch.equip.gun = "pistol1";
	}
	else
	{
		GiveItem2Character(ch, "pistol1a");
		ch.equip.gun = "pistol1a";
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.location	= "None";
	ch.location.group = "goto";
	ch.location.locator = "goto6";
	ch.Dialog.Filename = "Joaquin Da Saldanha_dialog.c";
	ch.rank 	= 10;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "8";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "4";
	ch.skill.Cannons = "4";
	ch.skill.Grappling = "6";
	ch.skill.Repair = "3";
	ch.skill.Defence = "4";
	ch.skill.Commerce = "5";
	ch.skill.Sneak = "1";
	ch.money = "10";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 120.0, 120.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

// Arabella Silehard - FIND THE MISSING SON OF THE SPANISH ADMIRAL (Lucas Da Saldanha quest)
	ch.old.name = "Arabella";
	ch.old.lastname = "Silehard";
	ch.name = TranslateString("", "Arabella");
	ch.lastname = TranslateString("", "Silehard");
	ch.id		= "Arabella Silehard";
	ch.model = "towngirl1";
	ch.sex = "woman";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "goto11";
	ch.Dialog.Filename = "Arabella Silehard_dialog.c";
	ch.rank 	= 1;
	ch.reputation = "60";
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
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 8.0, 20.0);
	LAi_SetHP(ch, 40.0, 40.0);
	ch.greeting = "Gr_Arabella Silehard";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

// Arabella's Guard 1 - FIND THE MISSING SON OF THE SPANISH ADMIRAL (Lucas Da Saldanha quest)
	ch.old.name = "Arabella's guard";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Arabella's guard");
	ch.lastname = "";
	ch.id		= "Arabella's guard 1";
	ch.model	= Nations[ENGLAND].fantomModel.m0; // PB
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)
	{
		GiveItem2Character(ch, "pistol1");
		ch.equip.gun = "pistol1";
	}
	else
	{
		GiveItem2Character(ch, "pistol1a");
		ch.equip.gun = "pistol1a";
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Arabella's guard_dialog.c";
	ch.rank 	= 1;
	ch.reputation = "50";
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
	ch.money = "100";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 8.0, 20.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_Arabella's guard";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

// Arabella's Guard 2 - FIND THE MISSING SON OF THE SPANISH ADMIRAL (Lucas Da Saldanha quest)
	ch.old.name = "Arabella's guard";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Arabella's guard");
	ch.lastname = "";
	ch.id		= "Arabella's guard 2";
	ch.model	= Nations[ENGLAND].fantomModel.m0; // PB
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)
	{
		GiveItem2Character(ch, "pistol1");
		ch.equip.gun = "pistol1";
	}
	else
	{
		GiveItem2Character(ch, "pistol1a");
		ch.equip.gun = "pistol1a";
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Arabella's guard_dialog.c";
	ch.rank 	= 1;
	ch.reputation = "50";
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
	ch.money = "100";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 8.0, 20.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_Arabella's guard";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

// Ransom Pirate 1 - FIND THE MISSING SON OF THE SPANISH ADMIRAL (Lucas Da Saldanha quest)
	ch.old.name = "Billy";
	ch.old.lastname = "Brock";
	ch.name = TranslateString("", "Billy");
	ch.lastname = TranslateString("", "Brock");
	ch.id		= "Billy Brock";
	ch.model = "BillyBrock";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)
	{
		GiveItem2Character(ch, "pistol1");
		ch.equip.gun = "pistol1";
	}
	else
	{
		GiveItem2Character(ch, "pistol1a");
		ch.equip.gun = "pistol1a";
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.location = "none";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "Billy Brock_dialog.c";
	ch.greeting = "Gr_Billy Brock";
	ch.rank 	= 1;
	ch.reputation = "50";
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
	ch.money = "100";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 70.0, 70.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

// Ransom Pirate 2 - FIND THE MISSING SON OF THE SPANISH ADMIRAL (Lucas Da Saldanha quest)
	ch.old.name = "Snorri";
	ch.old.lastname = "Baldursson";
	ch.name = TranslateString("", "Snorri");
	ch.lastname = TranslateString("", "Baldursson");
	ch.id		= "Snorri Baldursson";
	ch.model = "sailor6";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade7");
	ch.equip.blade = "blade7";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "goto2";
	ch.Dialog.Filename = "Snorri Baldursson_dialog.c";
	ch.rank 	= 1;
	ch.reputation = "50";
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
	ch.money = "100";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 50.0, 50.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

// Ransom Pirate 3 - FIND THE MISSING SON OF THE SPANISH ADMIRAL (Lucas Da Saldanha quest)
	ch.old.name = "Francis";
	ch.old.lastname = "Snake";
	ch.name = TranslateString("", "Francis");
	ch.lastname = TranslateString("", "Snake");
	ch.id		= "Francis Snake";
	ch.model = "corsair1_1";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade36");
	ch.equip.blade = "blade36";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "";
	ch.rank 	= 1;
	ch.reputation = "50";
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
	ch.money = "100";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 50.0, 50.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

//Lucas

// Missing man quest

// Angelique Moulin - FIND ANGELIQUE MOULIN'S FATHER (Missing Man quest)
	ch.old.name = "Angelique";
	ch.old.lastname = "Moulin";
	ch.name = TranslateString("", "Angelique");
	ch.lastname = TranslateString("", "Moulin");
	ch.id		= "Angelique Moulin";
	ch.model = "towngirl6";
	ch.sex = "woman";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Angelique Moulin_dialog.c";
	ch.rank 	= 1;
	ch.reputation = "none";
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
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 8.0, 20.0);
	LAi_SetHP(ch, 40.0, 40.0);
	ch.greeting = "Gr_Angelique Moulin";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

// Franзois Moulin - FIND ANGELIQUE MOULIN'S FATHER (Missing Man quest)
	ch.old.name = "Franзois";
	ch.old.lastname = "Moulin";
	ch.name = TranslateString("", "Franзois");
	ch.lastname = TranslateString("", "Moulin");
	ch.id	 = "Francois Moulin";
	ch.model = "old_man1";
	ch.sex = "man";
	ch.sound_type = "old_man2";
	ch.location	= "None";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Francois Moulin_dialog.c";
	ch.greeting = "Gr_Francois Moulin";
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
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 8.0, 20.0);
	LAi_SetHP(ch, 60.0, 60.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

// Antoine Chamfort - FIND ANGELIQUE MOULIN'S FATHER (Missing Man quest)
	ch.old.name = "Antoine";
	ch.old.lastname = "Chamfort";
	if (GetCurrentPeriod() == PERIOD_EARLY_EXPLORERS)
	{
		ch.name = TranslateString("", "Antonio");
		ch.lastname = TranslateString("", "Chamot");
		GiveItem2Character(ch, "blade47");
		ch.equip.blade = "blade47";
		ch.nation = SPAIN;
		ch.model   = GetRandomModelForTypeExSubCheck(true, "Land_Officers", "man", SPAIN);
		ch.greeting = "Gr_Jaoquin de masse";
		LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS"); // PB: Avoid soldiers attacking their own
	}
	else
	{
		ch.name = TranslateString("", "Antoine");
		ch.lastname = TranslateString("", "Chamfort");
		GiveItem2Character(ch, "bladeC6");
		ch.equip.blade = "bladeC6";
		ch.nation = FRANCE;
		ch.model   = GetRandomModelForTypeExSubCheck(true, "Land_Officers", "man", FRANCE);
		ch.greeting = "Gr_Antoine Chamfort";
		LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS"); // PB: Avoid soldiers attacking their own
	}
	ch.id = "Antoine Chamfort";
	ch.sex = "man";
	ch.sound_type = "pirate";
	if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)
	{
		GiveItem2Character(ch, "pistol1");
		ch.equip.gun = "pistol1";
	}
	else
	{
		GiveItem2Character(ch, "pistol1a");
		ch.equip.gun = "pistol1a";
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Antoine Chamfort_dialog.c";
	ch.rank 	= 18;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "8";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
	LAi_SetGuardianType(ch); // PB: Actual soldier
	LAi_SetLoginTime(ch, 0.0, 24.0); // PB: was LAi_SetLoginTime(ch, 8.0, 20.0);
	LAi_SetHP(ch, 180.0, 180.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

// Robert Durand - FIND ANGELIQUE MOULIN'S FATHER (Missing Man quest)
	ch.old.name = "Robert";
	ch.old.lastname = "Durand";
	ch.name = TranslateString("", "Robert_fr");
	ch.lastname = TranslateString("", "Durand");
	ch.id		= "Robert Durand";
	ch.model	= "mongol";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade36");
	ch.equip.blade = "blade36";
	if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)
	{
		GiveItem2Character(ch, "pistol1");
		ch.equip.gun = "pistol1";
	}
	else
	{
		GiveItem2Character(ch, "pistol1a");
		ch.equip.gun = "pistol1a";
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Robert Durand_dialog.c";
	ch.rank 	= 10;
	ch.reputation = "None";
	ch.experience = "0";
	ch.greeting = "Gr_Robert Durand";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "2";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
	LAi_SetCivilianGuardianType(ch); // PB
	LAi_SetLoginTime(ch, 8.0, 20.0);
	LAi_SetHP(ch, 100.0, 100.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

//  Buccaneer - FIND ANGELIQUE MOULIN'S FATHER (Missing Man quest)
	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = "";
	ch.id		= "buccaneer_01";
	ch.model	= "pirat1";
	ch.sex = "man";
	ch.sound_type = "pirate";
	if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)
	{
		GiveItem2Character(ch, "blade4");
		ch.equip.blade = "blade4";
		GiveItem2Character(ch, "pistol1");
		ch.equip.gun = "pistol1";
	}
	else
	{
		GiveItem2Character(ch, "blade10");
		ch.equip.blade = "blade10";
		GiveItem2Character(ch, "pistol1a");
		ch.equip.gun = "pistol1a";
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	//JRH ammo mod <--
//	ch.location	= "none";
//	ch.location.group = "";
//	ch.location.locator = "";
	ch.location	= "Buccaneers_Camp";	// Put him there at game start so that Buccaneers Camp is more populated
	ch.location.group = "goto";
	ch.location.locator = "goto42";
	ch.Dialog.Filename = "Buccaneers_dialog.c";
	ch.rank 	= 6;
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
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

//  Buccaneer - FIND ANGELIQUE MOULIN'S FATHER (Missing Man quest)
	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = "";
	ch.id		= "buccaneer_02";
	ch.model	= "pirat2";
	ch.sex = "man";
	ch.sound_type = "pirate";
	if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)
	{
		GiveItem2Character(ch, "blade4");
		ch.equip.blade = "blade4";
		GiveItem2Character(ch, "pistol1");
		ch.equip.gun = "pistol1";
	}
	else
	{
		GiveItem2Character(ch, "blade10");
		ch.equip.blade = "blade10";
		GiveItem2Character(ch, "pistol1a");
		ch.equip.gun = "pistol1a";
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	//JRH ammo mod <--
//	ch.location	= "none";
//	ch.location.group = "";
//	ch.location.locator = "";
	ch.location	= "Buccaneers_Camp";
	ch.location.group = "goto";
	ch.location.locator = "goto12";
	ch.Dialog.Filename = "Buccaneers_dialog.c";
	ch.rank 	= 7;
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
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);

//  Buccaneer - FIND ANGELIQUE MOULIN'S FATHER (Missing Man quest)
	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = "";
	ch.id		= "buccaneer_03";
	ch.model	= "pirat3";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade7");
	ch.equip.blade = "blade7";
	if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)
	{
		GiveItem2Character(ch, "pistol1");
		ch.equip.gun = "pistol1";
	}
	else
	{
		GiveItem2Character(ch, "pistol1a");
		ch.equip.gun = "pistol1a";
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	//JRH ammo mod <--
//	ch.location	= "none";
//	ch.location.group = "";
//	ch.location.locator = "";
	ch.location	= "Buccaneers_Camp";
	ch.location.group = "goto";
	ch.location.locator = "goto15";
	ch.Dialog.Filename = "Buccaneers_dialog.c";
	ch.rank 	= 8;
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
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);
// Missing man quest

// First Contact quest

// Reynoud Verheugen - ELIZABETH SHAW'S DISAPPEARENCE (Davy Jones First Contact quest)
	ch.old.name = "Reynoud";
	ch.old.lastname = "Verheugen";
	ch.name = TranslateString("", "Reynoud");
	ch.lastname = TranslateString("", "Verheugen");
	ch.id		= "Reynoud Verheugen";
	ch.model	= "fisherman1";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
	ch.Dialog.Filename = "Reynoud Verheugen_dialog.c";
	ch.greeting = "Gr_Toff Oremans";
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
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);       

// Davy Jones - ELIZABETH SHAW'S DISAPPEARENCE (Davy Jones First Contact quest)
	ch.old.name = "Davy";
	ch.old.lastname = "Jones";
	ch.name = TranslateString("", "Davy");
	ch.lastname = TranslateString("", "Jones");
	ch.id		= "Davy Jones";
	ch.model	= "davyjones";
	ch.model.animation = "Rousselet";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade34");
	ch.equip.blade = "blade34";
	ch.Ship.AI.GroupName = "Davy Jones";
	ch.Ship.AI.Task = "attack";
	ch.nation	= PIRATE;
	if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)
	{
		GiveItem2Character(ch, "pistol1");
		ch.equip.gun = "pistol1";
	}
	else
	{
		GiveItem2Character(ch, "pistol1a");
		ch.equip.gun = "pistol1a";
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Davy Jones_dialog.c";
	ch.Ship.Name = "Flying Dutchman";
	ch.Ship.Type = "CursedDutchman";
	ch.Ship.Stopped = true;
	ch.Flags.Pirate = 1;
	ch.Flags.Pirate.texture = 3;
	ch.Flags.Personal = 1;
	ch.Flags.Personal.texture = 2;
	ch.skipRM = true; // PB: Skip Relations Mod
	ch.rank 	= 99;
	ch.reputation = "None";
	ch.experience = "0";
	ch.greeting = "Gr_Pedro Rivera";
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
	ch.money = "0";
	LAi_SetCivilianGuardianType(ch); // PB
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 990.0, 990.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

// Octave Fabre - ELIZABETH SHAW'S DISAPPEARENCE (Davy Jones First Contact quest)
	ch.old.name = "Octave";
	ch.old.lastname = "Fabre";
	ch.name = TranslateString("", "Octave");
	ch.lastname = TranslateString("", "Fabre");
	ch.id		= "Octave Fabre";
	ch.model = "Fra_adm_18"; // PB
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Octave Fabre_dialog.c";
	ch.nation = FRANCE;
	ch.rank 	= 30;
	ch.reputation = "60";
	ch.experience = "0";
	ch.skill.Leadership = "10";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "10";
	ch.skill.Accuracy = "10";
	ch.skill.Cannons = "10";
	ch.skill.Grappling = "10";
	ch.skill.Repair = "10";
	ch.skill.Defence = "10";
	ch.skill.Commerce = "5";
	ch.skill.Sneak = "10";
	ch.money = "10";
	ch.quest.meeting = "0";
	LAi_SetSitType(ch);
	LAi_RemoveLoginTime(ch);
	ch.greeting = "Gr_Francois Moulin";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

// Elizabeth Shaw - ELIZABETH SHAW'S DISAPPEARENCE (Davy Jones First Contact quest)
	ch.old.name = "Elizabeth";
	ch.old.lastname = "Shaw";
	ch.name = TranslateString("", "Elizabeth");
	ch.lastname = TranslateString("", "Shaw");
	ch.id		= "Elizabeth Shaw";
	ch.model = "50_Rachel";
	ch.sex = "woman";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Elizabeth Shaw_dialog.c";
	ch.rank 	= 1;
	ch.reputation = "60";
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
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 40.0, 40.0);
	ch.greeting = "Gr_Arabella Silehard";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

//  Davy's crewmember1 - ELIZABETH SHAW'S DISAPPEARENCE (Davy Jones First Contact quest)
	ch.old.name = "Palafico"; // PB
	ch.old.lastname = "";
	ch.name = TranslateString("", "Palafico"); // PB
	ch.lastname = "";
	ch.id		= "Davycrew_01";
	ch.model	= "Palafico";
	ch.model.animation = "Rousselet";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)
	{
		GiveItem2Character(ch, "pistol1");
		ch.equip.gun = "pistol1";
	}
	else
	{
		GiveItem2Character(ch, "pistol1a");
		ch.equip.gun = "pistol1a";
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Davycrew_dialog.c";
	ch.rank 	= 6;
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
	ch.greeting = "Gr_Laurence Wellman";
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

//  Davy's crewmember2 - ELIZABETH SHAW'S DISAPPEARENCE (Davy Jones First Contact quest)
	ch.old.name = "Penrod";		// was "Jimmy"
	ch.old.lastname = "";		// was "Legs"
	ch.name = TranslateString("", "Penrod");
	ch.lastname = "";
	ch.id		= "Davycrew_02";
	ch.model	= "Penrod";	// New models don't include Jimmy Legs. (Penrod has an extra leg.)
	ch.model.animation = "Rousselet";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)
	{
		GiveItem2Character(ch, "pistol1");
		ch.equip.gun = "pistol1";
	}
	else
	{
		GiveItem2Character(ch, "pistol1a");
		ch.equip.gun = "pistol1a";
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.rank 	= 7;
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
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

// First Contact quest


// Bart Cooke - SMUGGLING FOR THOMAS O'REILY
	ch.old.name = "Bart";
	ch.old.lastname = "Cooke";
	ch.name = TranslateString("", "Bart");
	ch.lastname = TranslateString("", "Cooke");
	ch.id		= "Bart Cooke";
	ch.model = "man4";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade7");
	ch.equip.blade = "blade7";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "none";
	ch.Dialog.Filename = "Bart_Cooke_dialog.c";
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

// Wally Cutty - SMUGGLING FOR THOMAS O'REILY
	ch.old.name = "Wally";
	ch.old.lastname = "Cutty";
	ch.name = TranslateString("", "Wally");
	ch.lastname = TranslateString("", "Cutty");
	ch.id		= "Wally Cutty";
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

// Bill Jellybones - SMUGGLING FOR THOMAS O'REILY
	ch.old.name = "Bill";
	ch.old.lastname = "Jellybones";
	ch.name = TranslateString("", "Bill");
	ch.lastname = TranslateString("", "Jellybones");
	ch.id		= "Bill Jellybones";
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

// Pirate Captain 01 - SMUGGLING FOR THOMAS O'REILY
	ch.old.name = "Xabe";
	ch.old.lastname = "Oraglio";
	ch.name = TranslateString("", "Xabe");
	ch.lastname = TranslateString("", "Oraglio");
	ch.id		= "Pirate Captain 01";
	ch.model = "Monkey_D_Luffy"; // GR: was "fisherman", same as all the others
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.Ship.AI.GroupName = "Enemy_Redmond_Smugglers";
	ch.Ship.AI.Task = "attack";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none";//"Redmond"; //redmond_shore_01
	ch.location.group = "Quest_ships";
	ch.location.locator = "quest_ship_11";//locator8
	ch.Dialog.Filename = "Gyles Dubois_dialog.c";
	ch.Ship.Name = "Fast Death";
	if (GetCurrentPeriod() == PERIOD_EARLY_EXPLORERS) ch.Ship.Type = "Carrack";
	else ch.Ship.Type = "Brig1"; // PRS3
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
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Gyles Dubois";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

// Pirate Captain 02 - SMUGGLING FOR THOMAS O'REILY
	ch.old.name = "Wadham";		// GR: was "Gyles"
	ch.old.lastname = "Notley";	// GR: was "Dubois"
	ch.name = TranslateString("", "Wadham");
	ch.lastname = TranslateString("", "Notley");
	ch.id		= "Pirate Captain 02";
	ch.model = "fisherman";
	ch.sex = "man";
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.Ship.AI.GroupName = "Enemy_Redmond_Smugglers";
	ch.Ship.AI.Task = "attack";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade7");
	ch.equip.blade = "blade7";
	ch.location	= "none";//"Redmond"; //redmond_shore_01
	ch.location.group = "Quest_ships";
	ch.location.locator = "quest_ship_11";//locator8
	ch.Dialog.Filename = "Gyles Dubois_dialog.c";
	ch.Ship.Name = "Madonna";
	ch.Ship.Type = "Lugger1"; // PRS3
	ch.Ship.Stopped = true;
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS16;
	ch.rank 	= 1;
	ch.reputation = "22";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "4";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_Gyles Dubois";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

// Pirate Captain 03 - SMUGGLING FOR THOMAS O'REILY
	ch.old.name = "Morland";	// GR: was "Gyles"
	ch.old.lastname = "Haley";	// GR: was "Dubois"
	ch.name = TranslateString("", "Morland");
	ch.lastname = TranslateString("", "Haley");
	ch.id		= "Pirate Captain 03";
	ch.model = "fisherman";
	ch.sex = "man";
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.Ship.AI.GroupName = "Enemy_Redmond_Smugglers";
	ch.Sea.Task = "attack";
	ch.Ship.AI.Task = "attack";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "MerchantsBlade");
	ch.equip.blade = "MerchantsBlade";
	ch.location	= "none";//"Redmond"; //redmond_shore_01
	ch.location.group = "Quest_ships";
	ch.location.locator = "quest_ship_11";//locator8
	ch.Dialog.Filename = "Gyles Dubois_dialog.c";
	ch.Ship.Name = "Duquesa";	// GR - was "Madonna"
	if (GetCurrentPeriod() == PERIOD_EARLY_EXPLORERS) ch.Ship.Type = "PO_Caravel50";
	else ch.Ship.Type = "BarqueHeavy";	// GR - was "Barque1"
	ch.Ship.Stopped = true;
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS16;
	ch.rank 	= 1;
	ch.reputation = "22";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "4";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_Gyles Dubois";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

// Pirate Captain 04 - SMUGGLING FOR THOMAS O'REILY
	ch.old.name = "Gyles";
	ch.old.lastname = "Dubois";
	ch.name = TranslateString("", "Gyles");
	ch.lastname = TranslateString("", "Dubois");
	ch.id		= "Pirate Captain 04";
	ch.model = "fisherman";
	ch.sex = "man";
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.Ship.AI.GroupName = "Enemy_Redmond_Smugglers_Away";
	ch.Ship.AI.Task = "runaway";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade6");
	ch.equip.blade = "blade6";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "none";//"Redmond"; //redmond_shore_01
	ch.location.group = "Quest_ships";
	ch.location.locator = "quest_ship_3";//locator8
	ch.Dialog.Filename = "Gyles Dubois_dialog.c";
//	ch.Ship.Name = "Madonna";			// GR: Almost all the ships in this quest were named "Madonna"!
//	ch.Ship.Type = "Caravel1"; // PRS3		   GR: "Caravel1" doesn't exist beyond "Spanish Main"
	ch.Ship.Name = "Comtesse";
	switch(GetCurrentPeriod())
	{
		case PERIOD_EARLY_EXPLORERS:
			ch.Ship.Type = 	"Caravel1";
		break;
		case PERIOD_THE_SPANISH_MAIN:
			ch.Ship.Type = 	"Caravel1";
		break;
		case PERIOD_GOLDEN_AGE_OF_PIRACY:
			ch.Ship.Type = 	"NL_CastelF";
		break;
		case PERIOD_COLONIAL_POWERS:
			ch.Ship.Type = 	"NL_CastelF";
		break;
		case PERIOD_REVOLUTIONS:
			ch.Ship.Type = 	"FastMerchantman2";
			ch.Ship.Cannons.Type = CANNON_TYPE_LONG_LBS6;
		break;
		case PERIOD_NAPOLEONIC:
			ch.Ship.Type = 	"FastMerchantman2";
			ch.Ship.Cannons.Type = CANNON_TYPE_LONG_LBS6;
		break;
	}
	ch.Ship.Stopped = true;
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS16;
	ch.rank 	= 1;
	ch.reputation = "22";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "2";
	ch.skill.Sailing = "2";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "4";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_Gyles Dubois";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Henry Peat
	ch.old.name = "Henry";
	ch.old.lastname = "Peat";
	ch.name = TranslateString("", "Henry");
	ch.lastname = TranslateString("", "Peat");
	ch.id		= "Henry Peat";
	ch.model = "old_man2";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.location	= "None";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Henry Peat_dialog.c";
	ch.greeting = "Gr_Henry Peat";
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
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Gordon Carpenter
	ch.old.name = "Gordon";
	ch.old.lastname = "Carpenter";
	ch.name = TranslateString("", "Gordon");
	ch.lastname = TranslateString("", "Carpenter");
	ch.id		= "Gordon Carpenter";
	ch.model = "bocman4";
	ch.sex = "man";
	ch.sound_type = "old_man2";
	ch.location	= "None";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Gordon Carpenter_dialog.c";
	ch.greeting = "Gr_Gordon Carpenter";
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
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// ANIMISTS
	ch.old.name = "Dark Captain";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Dark Captain");
	ch.lastname = "";
	ch.id		= "Dark Captain";
	ch.model = "ANIMISTS2";
	ch.sex = "man";
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.Ship.AI.GroupName = "Ethilrede Claar";
	ch.Ship.AI.Task = "attack";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade10");
	ch.equip.blade = "blade10";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Gyles Dubois_dialog.c";
	ch.Ship.Name = "Mefisto";
	ch.Ship.Type = "Frigate_sat"; // PRS3
	if (GetCurrentPeriod() < PERIOD_GOLDEN_AGE_OF_PIRACY)
		ch.Ship.Type = "FleutWarSat";		// Grey Roger: alternative for early periods
	if (GetCurrentPeriod() == PERIOD_REVOLUTIONS)
		ch.Ship.Type = "PiratFrigateSat";	// The Nameless Pirate: alternative for Revolutions period
	if (GetCurrentPeriod() == PERIOD_NAPOLEONIC)
		ch.Ship.Type = "Sat_Essex";		// Grey Roger: alternative for Napoleonic period
	ch.Ship.Stopped = true;
	ch.Flags.Pirate = 6; // GR: Animists Pirate Flag
	ch.Flags.Pirate.texture = 1;
	ch.nosurrender = 2;
	ch.boardingmodels = "Animists";
	ch.skipRM = true; // PB: Skip Relations Mod
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	ch.rank 	= 1;
	ch.reputation = "1";
	ch.experience = "0";
	ch.skill.Leadership = "8";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "9";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "9";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "1";
	ch.skill.Defence = "4";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "8";
	ch.money = "10";
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_Gyles Dubois";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Giraldo Figuiera
	ch.old.name = "Giraldo";
	ch.old.lastname = "Figuiera";
	ch.name = TranslateString("", "Giraldo");
	ch.lastname = TranslateString("", "Figuiera");
	ch.id		= "Giraldo Figuiera";
	ch.model = "corsair2";	// KevAtl 08-26-2007 fix missing char model
	ch.sex = "man";
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.Ship.AI.GroupName = "Ethilrede Claar";
	ch.Ship.AI.Task = "attack";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade7");
	ch.equip.blade = "blade7";
	ch.location	= "none";
	ch.location.group = "Quest_ships";
	ch.location.locator = "quest_ship_11";
	ch.Dialog.Filename = "Gyles Dubois_dialog.c";
	ch.Ship.Name = "Inferno"; // KK (second Mefisto?)
	ch.Ship.Type = "PiratFrigateSup"; // PRS3 // KK
	ch.Ship.Stopped = true;
	ch.nosurrender = 2; // TIH: doesn't give up easily
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	ch.rank 	= 1;
	ch.reputation = "1";
	ch.experience = "0";
	ch.skill.Leadership = "8";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "9";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "9";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "1";
	ch.skill.Defence = "4";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "8";
	ch.money = "10";
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_Gyles Dubois";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

// Artois Voysey quest

	ch.old.name = "Pirate";
	ch.old.lastname = "1";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = TranslateString("", "1");
	ch.id		= "Pirates_1";
	ch.model	= "korsar";
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

	ch.old.name = "Pirate";
	ch.old.lastname = "2";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = TranslateString("", "2");
	ch.id		= "Pirates_2";
	ch.model	= "corsair2";
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade11");
	ch.equip.blade = "blade11";
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

	ch.old.name = "Pirate";
	ch.old.lastname = "3";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = TranslateString("", "3");
	ch.id		= "Pirates_3";
	ch.model	= "corsair1";
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade6");
	ch.equip.blade = "blade6";
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

// Artois Voysey quest

// Nigel Blythe quest

			// Friedrich Maxwell
	ch.old.name = "Friedrich";
	ch.old.lastname = "Maxwell";
	ch.name = TranslateString("", "Friedrich");
	ch.lastname = TranslateString("", "Maxwell");
	ch.id		= "Friedrich Maxwell";
	ch.model	= "corsair3";
	ch.sex = "man";
	ch.location	= "none";
	ch.location.group = "sit";
	ch.location.locator = "sit2";
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
	ch.money = "1";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.greeting = "Gr_Maxwell";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			// Luis Meranda
	ch.old.name = "Luis";
	ch.old.lastname = "Meranda";
	ch.name = TranslateString("", "Luis");
	ch.lastname = TranslateString("", "Meranda");
	ch.id		= "Luis Meranda";
	ch.model	= "man1";
	ch.sex = "man";
	ch.location	= "none";
	ch.location.group = "sit";
	ch.location.locator = "sit2";
	ch.Dialog.Filename = "Luis Meranda_dialog.c";
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
	ch.money = "1";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			// Pirates_7 --
	ch.old.name = "Pirate";
	ch.old.lastname = "seven";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = TranslateString("", "seven");
	ch.id		= "Pirates_7";
	ch.model	= "man4";
	ch.sex = "man";
	if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)
	{
		GiveItem2Character(ch, "pistol1");
		ch.equip.gun = "pistol1";
	}
	else
	{
		GiveItem2Character(ch, "pistol1a");
		ch.equip.gun = "pistol1a";
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	GiveItem2Character(ch, "blade7");
	ch.equip.blade = "blade7";
	ch.location	= "None";
	ch.location.group = "sit";
	ch.location.locator = "sit3";
	ch.Dialog.Filename = "Habitue_dialog.c";
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
	ch.Ship.Name = "Duk";
	ch.Ship.Type = "PiratBrig50"; // Petros: was Brig1
	ch.Ship.Stopped = true;
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS12;
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Claudio Murena.
	ch.old.name = "Claudio";
	ch.old.lastname = "Murena";
	ch.name = TranslateString("", "Claudio");
	ch.lastname = TranslateString("", "Murena");
	ch.id		= "Claudio Murena";
	ch.model = "man2";
	ch.sex = "man";
	ch.location	= "None";
	ch.location.group = "sit";
	ch.location.locator = "sit2";
	ch.Dialog.Filename = "";
	ch.greeting = "Gr_Murena";
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
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Ethilrede Claar - пират, который продал в рабство одного из наших офицеров () Leborio Drago
	ch.old.name = "Ethilrede";
	ch.old.lastname = "Claar";
	ch.name = TranslateString("", "Ethilrede");
	ch.lastname = TranslateString("", "Claar");
	ch.id		= "Ethilrede Claar";
	ch.model = "corsair2"; // KevAtl 08-26-2007 fix missing char model
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.Ship.AI.GroupName = "Ethilrede Claar";
	ch.Ship.AI.Task = "attack";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "none";
	ch.location.group = "Quest_ships";
	ch.location.locator = "quest_ship_2"; 		// Petros: was quest_ship_11
	ch.Dialog.Filename = "Gyles Dubois_dialog.c";
	ch.Ship.Name = "Neptunus";
	if (GetCurrentPeriod() < PERIOD_COLONIAL_POWERS)
		ch.Ship.Type = "FleutWar2";		// GR: more appropriate for earlier periods
	else
		ch.Ship.Type = "PiratCorvette"; 	// was Corvette1
	ch.Ship.Stopped = true;
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
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Gyles Dubois";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

// Nigel Blythe quest

// Edgar Attwood quest

					// Martin Warner.
	ch.old.name = "Martin";
	ch.old.lastname = "Warner";
	ch.name = TranslateString("", "Martin");
	ch.lastname = TranslateString("", "Warner");
	ch.id		= "Martin Warner";
	ch.model	= Nations[ENGLAND].fantomModel.m2; // PB
	ch.sex = "man";
	ch.location	= "None";
	ch.location.group = "sit";
	ch.location.locator = "sit4";
	ch.Dialog.Filename = "soldier2.c";
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
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_soldier2";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Jack Greenfield.
	ch.old.name = "Jack";
	ch.old.lastname = "Greenfield";
	ch.name = TranslateString("", "Jack");
	ch.lastname = TranslateString("", "Greenfield");
	ch.id		= "Jack Greenfield";
	ch.model	= Nations[ENGLAND].fantomModel.m3; // PB
	ch.sex = "man";
	ch.location	= "none";
	ch.location.group = "sit";
	ch.location.locator = "sit5";
	ch.Dialog.Filename = "soldier1.c";
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
	ch.Ship.Name = "Prison Ship";
	ch.Ship.Type = "Brig1"; // PRS3
	ch.Ship.Stopped = true;
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS12;
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_soldier1";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// zek
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "zek";
	ch.model = "man2";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
	ch.Dialog.Filename = "";
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
	ch.quest.meeting = "0";
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);


				// zek
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "zek2";
	ch.model = "man4";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
	ch.Dialog.Filename = "";
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
	ch.quest.meeting = "0";
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

// Edgar Attwood quest

	//Hitman SCM changes start

				// Ambroz Bricenos
	ch.old.name = "Ambroz";
	ch.old.lastname = "Bricenos";
	ch.name = TranslateString("", "Ambroz");
	ch.lastname = TranslateString("", "Bricenos");
	ch.id		= "Ambroz Bricenos";
	ch.model = "Storeman";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "MerchantsBlade"); //SCM
	ch.equip.blade = "MerchantsBlade"; //SCM
	GiveItem2Character(ch, "pistol5+3"); //SCM
	ch.equip.gun = "pistol5+3"; //SCM
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Ambroz Bricenos_dialog.c";
	ch.rank 	= 1;
	ch.reputation = "10";
	ch.experience = "0";
	ch.skill.Leadership = "0";
	ch.skill.Fencing = "2";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "3";
	ch.skill.Sneak = "0";
	ch.money = "100";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 50.0, 50.0);
	ch.greeting = "Gr_Ambroz Bricenos";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Mateus Santos
	ch.old.name = "Mateus";
	ch.old.lastname = "Santos";
	ch.name = TranslateString("", "Mateus");
	ch.lastname = TranslateString("", "Santos");
	ch.id		= "Mateus Santos";
	ch.model = "Assassin"; //SCM
	ch.sex = "man";
	ch.sound_type = "Mateus Santos"; //SCM
	GiveItem2Character(ch, "bladeX1"); //SCM
	ch.equip.blade = "bladeX1"; //SCM
	ch.nodisarm	= 1;				// PB: Disable disarming
	GiveItem2Character(ch, "pistol6+3"); //SCM
	ch.equip.gun = "pistol6+3"; //SCM
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Mateus Santos_dialog.c";
	ch.greeting = "Gr_Mateus Santos";
	ch.rank 	= 5;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "4";
	ch.skill.Sneak = "0";
	ch.money = "5000";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 140.0, 140.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Thug 1
	ch.old.name = "Desiree'"; //SCM
	ch.old.lastname = "Muerte"; //SCM
	ch.name = TranslateString("", "Desiree'"); //SCM
	ch.lastname = TranslateString("", "Muerte"); //SCM
	ch.id		= "Desiree' Muerte"; //SCM
	ch.model = "mowngirl7"; //SCM
	ch.sex = "woman"; //SCM
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade5"); //SCM
	ch.equip.blade = "blade5"; //SCM
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Desiree' Muerte_dialog.c";
	ch.greeting = "Gr_Desiree' Muerte";
	ch.rank 	= 3;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "0";
	ch.money = "200";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Thug 2
	ch.old.name = "Thug";
	ch.old.lastname = " ";
	ch.name = TranslateString("", "Thug");
	ch.lastname = " ";
	ch.id		= "Thug2";
	ch.model = "pirat6"; //SCM
	ch.sex = "man";
	ch.sound_type = "Thug"; //SCM
	GiveItem2Character(ch, "blade7"); //SCM
	ch.equip.blade = "blade7"; //SCM
	GiveItem2Character(ch, "pistol2"); //SCM
	ch.equip.gun = "pistol2"; //SCM
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Thug_dialog.c";
	ch.greeting = "Gr_Thug";
	ch.rank 	= 3;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "0";
	ch.money = "200";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Thug 3
	ch.old.name = "Thug";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Vassal"); //SCM
	ch.lastname = TranslateString("", "Bethune"); //SCM
	ch.id		= "Thug3";
	ch.model = "killer"; //SCM
	ch.sex = "man";
	ch.sound_type = "Vassal Bethune"; //SCM
	GiveItem2Character(ch, "bladeX1"); //SCM
	ch.equip.blade = "bladeX1"; //SCM
	ch.nodisarm	= 1;				// PB: Disable disarming
	if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)
	{
		GiveItem2Character(ch, "pistol1+3"); //SCM
		ch.equip.gun = "pistol1+3"; //SCM
	}
	else
	{
		GiveItem2Character(ch, "pistol1a+3");
		ch.equip.gun = "pistol1a+3";
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Vassal Bethune_dialog.c"; //SCM
	ch.greeting = "Gr_Vassal Bethune"; //SCM
	ch.rank 	= 3;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "0";
	ch.money = "200";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Thug 4 //SCM
	ch.old.name = "Daryl"; //SCM
	ch.old.lastname = " ";
	ch.name = TranslateString("", "Daryl"); //SCM
	ch.lastname = " ";
	ch.id		= "Thug4"; //SCM
	ch.model = "pirat2"; //SCM
	ch.sex = "man";
	ch.sound_type = "Daryl"; //SCM
	GiveItem2Character(ch, "blade7"); //SCM
	ch.equip.blade = "blade7"; //SCM
	GiveItem2Character(ch, "pistol2"); //SCM
	ch.equip.gun = "pistol2"; //SCM
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Daryl_dialog.c";
	ch.greeting = "Gr_Daryl";
	ch.rank 	= 3;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "0";
	ch.money = "200";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Thug 5 //SCM
	ch.old.name = "Larry"; //SCM
	ch.old.lastname = " ";
	ch.name = TranslateString("", "Larry"); //SCM
	ch.lastname = " ";
	ch.id		= "Thug5"; //SCM
	ch.model = "bugmanpirat14"; //SCM
	ch.sex = "man";
	ch.sound_type = "Larry"; //SCM
	GiveItem2Character(ch, "blade6"); //SCM
	ch.equip.blade = "blade6"; //SCM
	if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)
	{
		GiveItem2Character(ch, "pistol1"); //SCM
		ch.equip.gun = "pistol1"; //SCM
	}
	else
	{
		GiveItem2Character(ch, "pistol1a");
		ch.equip.gun = "pistol1a";
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Larry_dialog.c"; //SCM
	ch.greeting = "Gr_Larry"; //SCM
	ch.rank 	= 3;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "0";
	ch.money = "200";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Thug 6 //SCM
	ch.old.name = "Daryl"; //SCM
	ch.old.lastname = " ";
	ch.name = TranslateString("", "Daryl"); //SCM
	ch.lastname = " ";
	ch.id		= "Thug6"; //SCM
	ch.model = "korsar1"; //SCM
	ch.sex = "man";
	ch.sound_type = "Daryl"; //SCM
	GiveItem2Character(ch, "blade4"); //SCM
	ch.equip.blade = "blade4"; //SCM
	GiveItem2Character(ch, "pistol2"); //SCM
	ch.equip.gun = "pistol2"; //SCM
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Daryl_dialog.c";
	ch.greeting = "Gr_Daryl";
	ch.rank 	= 3;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "0";
	ch.money = "200";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Thug 7 //SCM
	ch.old.name = "Thug";
	ch.old.lastname = " ";
	ch.name = TranslateString("", "Thug");
	ch.lastname = " ";
	ch.id		= "Thug7"; //SCM
	ch.model = "pirat8"; //SCM
	ch.sex = "man";
	ch.sound_type = "Thug"; //SCM
	GiveItem2Character(ch, "blade4"); //SCM
	ch.equip.blade = "blade4"; //SCM
	if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)
	{
		GiveItem2Character(ch, "pistol1"); //SCM
		ch.equip.gun = "pistol1"; //SCM
	}
	else
	{
		GiveItem2Character(ch, "pistol1a");
		ch.equip.gun = "pistol1a";
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Thug_dialog.c";
	ch.greeting = "Gr_Thug";
	ch.rank 	= 3;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "0";
	ch.money = "200";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Thug 8 //SCM
	ch.old.name = "Thug";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Thug");
	ch.lastname = " ";
	ch.id		= "Thug8"; //SCM
	ch.model = "pirat9"; //SCM
	ch.sex = "man";
	ch.sound_type = "Thug"; //SCM
	GiveItem2Character(ch, "blade7"); //SCM
	ch.equip.blade = "blade7"; //SCM
	GiveItem2Character(ch, "pistol2"); //SCM
	ch.equip.gun = "pistol2"; //SCM
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Thug_dialog.c";
	ch.greeting = "Gr_Thug";
	ch.rank 	= 3;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "0";
	ch.money = "200";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Captain Jack Sparrow //SCM
	ch.old.name = "Captain Jack";
	ch.old.lastname = "Sparrow";
	ch.name = TranslateString("", "Captain Jack");
	ch.lastname = TranslateString("", "Sparrow");
	ch.id		= "Thug9"; //SCM
	ch.model = "depp"; //SCM
	ch.sex = "man";
	ch.sound_type = "Thug"; //SCM
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Jack_dialog.c";
	ch.greeting = "Gr_Captain Jack Sparrow";
	ch.rank 	= 3;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "0";
	ch.money = "200";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Leone's Daughter Camille //SCM
	ch.old.name = "Camille"; //SCM
	ch.old.lastname = "Leone"; //SCM
	ch.name = TranslateString("", "Camille"); //SCM
	ch.lastname = TranslateString("", "Leone"); //SCM
	ch.id		= "Camille Leone"; //SCM
	ch.model = "mowngirl5"; //SCM
	ch.sex = "woman"; //SCM
	ch.sound_type = "Desiree' Muerte";  //SCM
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Camille Leone_dialog.c"; //SCM
	ch.greeting = "Gr_Camille Leone"; //SCM
	ch.rank 	= 3;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "0";
	ch.money = "200";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Pris 1 //SCM
	ch.old.name = "Prisoner";
	ch.old.lastname = " ";
	ch.name = TranslateString("", "Prisoner");
	ch.lastname = " ";
	ch.id		= "Pris1"; //SCM
	ch.model = "rabblack"; //SCM
	ch.sex = "man";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.rank 	= 3;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "0";
	ch.money = "200";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Pris 2 //SCM
	ch.old.name = "Prisoner";
	ch.old.lastname = " ";
	ch.name = TranslateString("", "Prisoner");
	ch.lastname = " ";
	ch.id		= "Pris2"; //SCM
	ch.model = "rabblack_1"; //SCM
	ch.sex = "man";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.rank 	= 3;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "0";
	ch.money = "200";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Pris 3 //SCM
	ch.old.name = "Prisoner";
	ch.old.lastname = " ";
	ch.id		= "Pris3"; //SCM
	ch.model = "rabWhite"; //SCM
	ch.sex = "man";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.rank 	= 3;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "0";
	ch.money = "200";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Pris 4 //SCM
	ch.old.name = "Prisoner";
	ch.old.lastname = " ";
	ch.id		= "Pris4"; //SCM
	ch.model = "rabWhite1"; //SCM
	ch.sex = "man";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.rank 	= 3;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "0";
	ch.money = "200";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Geffrey Bampfylde
	ch.old.name = "Geffrey";
	ch.old.lastname = "Bampfylde";
	ch.name = TranslateString("", "Geffrey");
	ch.lastname = TranslateString("", "Bampfylde");
	ch.id		= "Geffrey Bampfylde";
	ch.model = "Nobleman";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Geffrey Bampfylde_dialog.c";
	ch.rank 	= 1;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "0";
	ch.skill.Fencing = "0";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "6";
	ch.skill.Sneak = "0";
	ch.money = "1000";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 30.0, 30.0);
	ch.greeting = "Gr_Geffrey Bampfylde";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Bucho
	ch.old.name = "Bucho";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Bucho");
	ch.lastname = " ";
	ch.id		= "Bucho";
	ch.model = "man4";
	ch.sex = "man";
	ch.sound_type = "Thug";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Bucho_dialog.c";
	ch.greeting = "Gr_Thug";
	ch.rank 	= 2;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "0";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "0";
	ch.skill.Sneak = "0";
	ch.money = "300";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 60.0, 60.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Pepin Bertillon
	ch.old.name = "Pepin";
	ch.old.lastname = "Bertillon";
	ch.name = TranslateString("", "Pepin");
	ch.lastname = TranslateString("", "Bertillon");
	ch.id		= "Pepin Bertillon";
	ch.model = "Pirat4";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "bladeC12");
	ch.equip.blade = "bladeC12";
	if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)
	{
		GiveItem2Character(ch, "pistol1");
		ch.equip.gun = "pistol1";
	}
	else
	{
		GiveItem2Character(ch, "pistol1a");
		ch.equip.gun = "pistol1a";
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Pepin Bertillon_dialog.c";
	ch.rank 	= 4;
	ch.reputation = "30";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "4";
	ch.skill.Sneak = "0";
	ch.money = "1500";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 90.0, 90.0);
	ch.greeting = "Gr_Pepin Bertillon";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Bertillon's guard 1
	ch.old.name = "Bertillon's guard";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Bertillon's guard");
	ch.lastname = " ";
	ch.id		= "Bertillon's guard1";
	ch.model = "pirat7";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Bertillon's Guard_dialog.c";
	ch.greeting = "Gr_Bertillon's Guard";
	ch.rank 	= 2;
	ch.reputation = "30";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "0";
	ch.skill.Sneak = "0";
	ch.money = "500";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 70.0, 70.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Bertillon's guard 2
	ch.old.name = "Bertillon's guard";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Bertillon's guard");
	ch.lastname = " ";
	ch.id		= "Bertillon's guard2";
	ch.model = "pirat5";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade7");
	ch.equip.blade = "blade7";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Bertillon's Guard_dialog.c";
	ch.greeting = "Gr_Bertillon's Guard";
	ch.rank 	= 2;
	ch.reputation = "30";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "0";
	ch.skill.Sneak = "0";
	ch.money = "500";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 70.0, 70.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Vito Leone
	ch.old.name = "Vito";
	ch.old.lastname = "Leone";
	ch.name = TranslateString("", "Vito");
	ch.lastname = TranslateString("", "Leone");
	ch.id		= "Vito Leone";
	ch.model = "Vito";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Vito Leone_dialog.c";
	ch.rank 	= 7;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "8";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "6";
	ch.skill.Sneak = "0";
	ch.money = "7000";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 90.0, 90.0);
	ch.greeting = "Gr_Vito Leone";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

//Hitman End SCM Changes
	// Bartolomeu quest
			//  crew
	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = "";
	ch.id		= "bart_pirate_01";
	ch.model	= "pirat1";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "goto4";
	ch.Dialog.Filename = "";
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
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//  crew
	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = "";
	ch.id		= "bart_pirate_02";
	ch.model	= "pirat2";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "goto4";
	ch.Dialog.Filename = "";
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
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//  crew
	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = "";
	ch.id		= "bart_pirate_03";
	ch.model	= "pirat3";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "goto4";
	ch.Dialog.Filename = "";
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
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//  crew
	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = "";
	ch.id		= "bart_pirate_04";
	ch.model	= "pirat4";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "goto4";
	ch.Dialog.Filename = "";
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
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//  crew
	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = "";
	ch.id		= "bart_pirate_05";
	ch.model	= "pirat5";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "goto4";
	ch.Dialog.Filename = "";
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
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//  crew
	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = "";
	ch.id		= "bart_pirate_06";
	ch.model	= "pirat6";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "goto4";
	ch.Dialog.Filename = "bartpirate_Dialog.c";
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
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Emilio";
	ch.old.lastname = "Soares";
	ch.name = TranslateString("", "Emilio");
	ch.lastname = TranslateString("", "Soares");
	ch.id		= "Emilio Soares";
	ch.model	= "Emilio1"; // Thomas the Terror
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "lastcrew_dialog.c";
	ch.greeting = "Gr_Emilio Soares";
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
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);
		
	ch.old.name = "Juan";
	ch.old.lastname = "Hernandez";
	ch.name = TranslateString("", "Juan");
	ch.lastname = TranslateString("", "Hernandez");
	ch.id		= "Juan Hernandez";
	ch.model	= "fisherman";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "goto4";
	ch.Dialog.Filename = "friend_dialog.c";
	ch.greeting = "Gr_Juan Hernandez";
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
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);
// Bartolomeu quest

// Turkshelp
			//  lookout
	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = "";
	ch.id		= "lookout";
	ch.model	= "pirat1";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Lookout_dialog.c";
	GiveItem2Character(ch, "blade36");
	ch.equip.blade = "blade36";
	if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)
	{
		GiveItem2Character(ch, "pistol1");
		ch.equip.gun = "pistol1";
	}
	else
	{
		GiveItem2Character(ch, "pistol1a");
		ch.equip.gun = "pistol1a";
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	//JRH ammo mod <--
	ch.rank 	= 3;
	ch.reputation = "None";
	ch.experience = "0";
	ch.greeting = "Gr_Lookout";
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
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	
	ch.old.name = "Pieter";
	ch.old.lastname = "Boelen";
	ch.name = TranslateString("","Pieter");
	ch.lastname = TranslateString("","Boelen");
	ch.id		= "Pieter Boelen";
	ch.model	= "9JdHol"; // PB
	ch.sex = "man";
	ch.loyality = 15;
	ch.alignment = "good";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Pieter Boelen_dialog.c";
	// PB -->
	ch.Ship.Name = "Amsterdam";
	if (GetCurrentPeriod() < PERIOD_COLONIAL_POWERS)
		ch.ship.Type = "NL_Derfflinger";
	else
		ch.Ship.Type = "NL_Amsterdam";
	ch.Ship.Stopped = true;
	ch.Flags.Pirate = 0;
	ch.Flags.Pirate.texture = 0;
	ch.Flags.Personal = 2;
	ch.Flags.Personal.texture = 1;
	GiveItem2Character(ch, "blade26+1");
	ch.equip.blade = "blade26+1";
	GiveItem2Character(ch, "pistol5+1");
	ch.equip.gun = "pistol5+1";
	// PB <--
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	//JRH ammo mod <--
	ch.nation	= HOLLAND;
	ch.rank 	= 40;
	// PB -->
	ch.reputation = "60";
	ch.experience = "2000000";
	ch.greeting = "Gr_Pieter Boelen";
	ch.skill.Leadership = "9";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "9";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "6";
	ch.skill.Grappling = "7";
	ch.skill.Repair = "8";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "7";
	ch.skill.Sneak = "5";
	ch.perks.list.LightRepair = true;
	ch.perks.list.ShipSpeedUp = true;
	ch.perks.list.ShipTurnRateUp = true;
	ch.perks.list.StormProfessional = true;
	ch.perks.list.Turn180 = true;
	ch.perks.list.SandbankManeuver = true;
	ch.perks.list.SailingProfessional = true;
	ch.perks.list.IronWill = true;
	ch.perks.list.BasicCommerce = true;
	ch.perks.list.AdvancedCommerce = true;
	ch.perks.list.Trustworthy = true;
	ch.perks.list.SharedExperience = true;
	ch.money = "1986";
	// PB <--
	LAi_SetCivilianGuardianType(ch); // KK
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	
	ch.old.name = "Diego";
	ch.old.lastname = "Cordoba";
	ch.name = TranslateString("", "Diego");
	ch.lastname = TranslateString("", "Cordoba");
	ch.id		= "Diego Cordoba";
	ch.model	= Nations[SPAIN].fantomModel.m0; // PB
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)
	{
		GiveItem2Character(ch, "pistol1");
		ch.equip.gun = "pistol1";
	}
	else
	{
		GiveItem2Character(ch, "pistol1a");
		ch.equip.gun = "pistol1a";
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	//JRH ammo mod <--
	ch.nation	= SPAIN;
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Diego Cordoba_dialog.c";
	ch.rank 	= 10;
	ch.reputation = "None";
	ch.experience = "0";
	ch.greeting = "Gr_Diego Cordoba";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "10";
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

		
	ch.old.name = "Captain";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Captain");
	ch.lastname = "";
	ch.id		= "Captain";
	ch.nation	= SPAIN;
	ch.model	= "Hugnt18";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.nodisarm	= 1;			
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
	ch.Ship.Name = "Santa Marta";
	ch.Ship.Type = "Galeon2";
	ch.Ship.Stopped = true; 
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);
// Turkshelp

// Santiago quest
				// Cecile Bienbonne
	ch.old.name = "Cecile";
	ch.old.lastname = "Bienbonne";
	ch.name = TranslateString("", "Cecile");
	ch.lastname = TranslateString("", "Bienbonne");
	ch.id		= "Cecile Bienbonne";
	ch.model = "imgovwife";
	ch.sex = "woman";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Cecile Bienbonne_dialog.c";
	ch.rank 	= 1;
	ch.reputation = "none";
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
	ch.quest.meeting = "0";
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 8.0, 20.0);
	LAi_SetHP(ch, 40.0, 40.0);
	ch.greeting = "Gr_Cecile Bienbonne";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	                       // Francisco Cruz	
	ch.old.name = "Francisco";
	ch.old.lastname = "Cruz";
	ch.name = TranslateString("", "Francisco");
	ch.lastname = TranslateString("", "Cruz");
	ch.id		= "Francisco Cruz";
	ch.model	= "Francisco_Cruz";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade11");
	ch.equip.blade = "blade11";
	if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)
	{
		GiveItem2Character(ch, "pistol1");
		ch.equip.gun = "pistol1";
	}
	else
	{
		GiveItem2Character(ch, "pistol1a");
		ch.equip.gun = "pistol1a";
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Francisco Cruz_dialog.c";
	ch.rank 	= 3;
	ch.reputation = "None";
	ch.experience = "0";
	ch.greeting = "Gr_Francisco Cruz";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "2";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
	LAi_SetCivilianGuardianType(ch); // PB
	LAi_SetLoginTime(ch, 6.0, 22.0);
	LAi_SetHP(ch, 50.0, 50.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	                       // Etienne Dupuis	
	ch.old.name = "Etienne";
	ch.old.lastname = "Dupuis";
	ch.name = TranslateString("", "Etienne");
	ch.lastname = TranslateString("", "Dupuis");
	ch.id		= "Etienne Dupuis";
	ch.model	= Nations[FRANCE].fantomModel.m3; // PB
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)
	{
		GiveItem2Character(ch, "pistol1");
		ch.equip.gun = "pistol1";
	}
	else
	{
		GiveItem2Character(ch, "pistol1a");
		ch.equip.gun = "pistol1a";
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	//JRH ammo mod <--
	ch.nation = FRANCE;
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Etienne Dupuis_dialog.c";
	ch.rank 	= 5;
	ch.reputation = "None";
	ch.experience = "0";
	ch.greeting = "Gr_Etienne Dupuis";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "2";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
	LAi_SetCivilianGuardianType(ch);
	LAi_SetLoginTime(ch, 8.0, 20.0);
	LAi_SetHP(ch, 60.0, 60.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	                       // Pedro Rivera	
	ch.old.name = "Pedro";
	ch.old.lastname = "Rivera";
	ch.name = TranslateString("", "Pedro");
	ch.lastname = TranslateString("", "Rivera");
	ch.id		= "Pedro Rivera";
	ch.model	= "wurmwoode";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade10");
	ch.equip.blade = "blade10";
	if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)
	{
		GiveItem2Character(ch, "pistol1");
		ch.equip.gun = "pistol1";
	}
	else
	{
		GiveItem2Character(ch, "pistol1a");
		ch.equip.gun = "pistol1a";
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Pedro Rivera_dialog.c";
	ch.Dialog.CurrentNode = "First time";
	ch.rank 	= 12;
	ch.reputation = "None";
	ch.experience = "0";
	ch.greeting = "Gr_Pedro Rivera";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "2";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "4";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
	LAi_SetCivilianGuardianType(ch); // PB
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 120.0, 120.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	                          // Jean Dusac
	ch.old.name = "Jean";
	ch.old.lastname = "Dusac";
	ch.name = TranslateString("", "Jean");
	ch.lastname = TranslateString("", "Dusac");
	ch.id		= "Jean Dusac";
	ch.model	= "pirtt7";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)
	{
		GiveItem2Character(ch, "pistol1");
		ch.equip.gun = "pistol1";
	}
	else
	{
		GiveItem2Character(ch, "pistol1a");
		ch.equip.gun = "pistol1a";
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	//JRH ammo mod <--	
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Jean Dusac_dialog.c";
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.greeting = "Gr_Jean Dusac";
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
	LAi_SetLoginTime(ch, 8.0, 20.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);
// Santiago quest

// Jackpot quest
	                       // Konrad Kulczycki
	ch.old.name = "Konrad";
	ch.old.lastname = "Kulczycki";
	ch.name = TranslateString("", "Konrad");
	ch.lastname = TranslateString("", "Kulczycki");
	ch.id		= "Konrad Kulczycki";
	ch.model	= "Corsair4"; // KK
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Konrad Kulczycki_dialog.c";
	ch.rank 	= 10;
	ch.reputation = "None";
	ch.experience = "0";
	ch.greeting = "Gr_Pirate kk";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "2";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.Gunman = true;
	LAi_SetCivilianGuardianType(ch); // PB
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	
	ch.old.name = "Silver";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Silver");
	ch.lastname = "";
	ch.id		= "Silver";
	ch.model	= "Hugnt18";
	ch.sex = "man";	
	ch.Ship.Name = "Leon";
	ch.Ship.Type = "SP_ApostolFelipe";
	ch.Ship.Stopped = true; 
	LAi_SetLoginTime(ch, 0.0, 24.0);
	AddGameCharacter(n, ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
// Jackpot quest

// TALISMAN -- Claire Larrouse crew - French Pirate in Tavern - replaces quest_pirate_01 and quest_smuggler_01 in quest

			// Larrouse_pirate_01 copy of quest_pirate_01
	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = "";
	ch.id		= "Larrouse_pirate_01";  // TALISMAN was quest_pirate_01
	ch.model = "korsar";
	ch.sex = "man";
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade7");
	ch.equip.blade = "blade7";
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
	
	
					// Larrouse_smuggler_01 copy of quest_smuggler_01
	ch.old.name = "Smuggler";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Smuggler");
	ch.lastname = "";
	ch.id		= "Larrouse_smuggler_01"; // TALISMAN was quest_smuggler_01
	ch.model = "corsair2";
	ch.sex = "man";
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade6");
	ch.equip.blade = "blade6";
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

	ch.old.name = "Nathaniel's Crewmember";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Nathaniel's Crewmember");
	ch.lastname = "";
	ch.id		= "Blaze_Crewmember_01";
	ch.model	= "bocman";
	ch.sex = "man";
	ch.sound_type = "seaman";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.Dialog.Filename = "found_blaze_1_dialog.c";
	ch.rank 	= 1;
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
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Nathaniel's Crewmember";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Nathaniel's Crewmember");
	ch.lastname = "";
	ch.id		= "Blaze_Crewmember_02";
	ch.model	= "korsar";
	ch.sex = "man";
	ch.sound_type = "seaman";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "blade7");
	ch.equip.blade = "blade7";
	ch.Dialog.Filename = "found_blaze_2_dialog.c";
	ch.rank 	= 1;
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
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Nathaniel's Crewmember";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Nathaniel's Crewmember");
	ch.lastname = "";
	ch.id		= "Blaze_Crewmember_03";
	ch.model	= "Black_Corsair";
	ch.sex = "man";
	ch.sound_type = "seaman";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.Dialog.Filename = "found_blaze_3_dialog.c";
	ch.rank 	= 1;
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
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	// Clair Larrouse
	ch.old.name = "Clair";
	ch.old.lastname = "Larrouse";
	ch.name = TranslateString("", "Clair");
	ch.lastname = TranslateString("", "Larrousse");
	ch.id		= "Clair Larrouse";
	ch.model = "corsair1_1";
	ch.sex = "man";
	ch.loyality = 10;
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.nation	= PIRATE;
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.Dialog.Filename = "Claire Larrouse_dialog.c"; // boal
	ch.rank 	= 6;
	ch.reputation = "42";
	TakeNItems(ch,"medical1", Rand(4)+1);
	ch.experience = CalculateExperienceFromRank(6)+ (CalculateExperienceFromRank(6)/10 + rand(6000));
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "4";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "2";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
	ch.quest.meeting = "0";
	ch.quest.goldmine = "0";
	ch.Ship.Name = "Cheri";
	ch.Ship.Type = "PiratBrig50"; // Petros: was Brig1
	ch.Ship.Stopped = true;
	//KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS12;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.BasicDefence = true;
	ch.perks.list.CrewDamageUp = true;
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Virgile Boon";
	ch.isOfficer = true;
	AddGameCharacter(n, ch);
	
// End Claire Larrouse

				// France_bukaner_01
	ch.old.name = "France_bukaner_01";
	ch.old.lastname = "";
	ch.name = TranslateString("", "France_bukaner_01");
	ch.lastname = "";
	ch.id		= "France_bukaner_01";
	ch.model = "man2";
	ch.sex = "man";
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none"
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "falaise de fleur soldier_dialog.c";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "28";
	Ch.location = "none";
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
	ch.money = "154";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_falaise de fleur soldier";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	// Skull
	ch.old.name = "Skull";
	ch.old.lastname = "";
	ch.name = TranslateString("","Skull");
	ch.lastname = "";
	ch.id		= "Skull";
	ch.model	= "Skull";
	ch.sex = "man";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "none";
	ch.Dialog.Filename = "Isenbrandt Jurcksen_dialog.c";
	ch.nation = PIRATE;
	if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)
	{
		GiveItem2Character(ch, "pistol1");
		ch.equip.gun = "pistol1";
	}
	else
	{
		GiveItem2Character(ch, "pistol1a");
		ch.equip.gun = "pistol1a";
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.rank 	= 20;
	ch.reputation = "25";
	ch.experience = "250000";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "6";
	ch.skill.Accuracy = "4";
	ch.skill.Cannons = "7";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "2";
	ch.money = "10000";
	ch.Ship.Name = "Dud";
	ch.ship.type = "PiratFrigateSup"; // PRS3
	// done by setbaseship - NK 05-04-09 ch.ship.cargo.goods.bombs = 1000;
	ch.Ship.Stopped = true;
	//KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	LAi_SetWarriorType(ch);
	LAi_warrior_DialogEnable(ch, true);
	LAi_warrior_SetStay(ch, true);
	Lai_SetImmortal(ch, true);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 160.0, 160.0);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	ch.greeting = "Gr_Isenbrandt Jurcksen";
	AddGameCharacter(n, ch);

// Bartolomeu: Jackpot Quest -->
	                       // Will Turner	
	ch.old.name = "Will";
	ch.old.lastname = "Turner";
	ch.name = TranslateString("", "Will");
	ch.lastname = TranslateString("", "Turner");
	ch.id		= "Will Turner";
	ch.nation	= ENGLAND;
	ch.sound_type = "seaman";
	ch.model	= "Will";
	ch.sex = "man";
	GiveItem2Character(ch, "blade18");
	ch.equip.blade = "blade18";
	GiveItem2Character(ch, "pistol5");
	ch.equip.gun = "pistol5";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Will Turner_dialog.c";
	ch.Ship.Name = "The Adventurer";
	if (GetCurrentPeriod() < PERIOD_COLONIAL_POWERS)
		ch.ship.Type = "FastGalleon1";
	else
		ch.Ship.Type = 	"Corvette2";
	ch.Ship.Stopped = true;
	ch.Flags.Pirate = 1;
	ch.Flags.Pirate.texture = 3;
	ch.Flags.Personal = 1;
	ch.Flags.Personal.texture = 2;
	ch.rank 	= 18;
	ch.reputation = "70";
	ch.experience = "0";
	ch.greeting = "Gr_Will Turner";
	ch.skill.Leadership = "8";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "10";
	ch.skill.Cannons = "4";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "9";
	ch.skill.Defence = "9";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = 1000;
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.Gunman = true;
	LAi_SetCivilianGuardianType(ch); // PB
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 180.0, 180.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				   // Elizabeth Swann
	ch.old.name = "Elizabeth";
	ch.old.lastname = "Swann";
	ch.name = TranslateString("", "Elizabeth");
	ch.lastname = TranslateString("", "Swann");
	ch.id		= "Elizabeth Swann";
	ch.model = "liz1"; // PB
	ch.nation	= ENGLAND;
	ch.sex = "woman";
	ch.sound_type = "pirate";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Elizabeth Swann_dialog.c";
	ch.rank 	= 10;
	ch.reputation = "60";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "4";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "6";
	ch.skill.Commerce = "3";
	ch.skill.Sneak = "1";
	ch.money = "500";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.Gunman = true;
	ch.quest.meeting = "0";
	LAi_SetCivilianGuardianType(ch); // PB
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	ch.greeting = "Gr_Arabella Silehard";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);
// Bartolomeu: Jackpot Quest <--

// Thomas the Terror: Sinking the Vogelstruijs -->
	ch.old.name = "Contre-Amirale";
	ch.old.middlename = "Cesar";
	ch.old.lastname = "Beauregard";
	ch.name = TranslateString("", "Contre-Amirale");
	ch.middlename = TranslateString("", "Cesar");
	ch.lastname = TranslateString("", "Beauregard");
	ch.id		= "Contre-Amirale";
	ch.model = "huber_fra";
	ch.sex = "man";
	ch.location	= "PoPrince_townhall";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Contre-Amirale Cesar Beauregard_dialog.c";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "60";
	ch.experience = "0";
	ch.skill.Leadership = "8";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "5";
	ch.skill.Commerce = "5";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_RemoveLoginTime(ch);
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	ch.greeting = "Gr_joseph claude le moigne";
	AddGameCharacter(n, ch);

	//Bonaire Docker
	ch.old.name = "Dockworker";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Dockworker");
	ch.lastname = "";
	ch.id		= "Docker";
	ch.model	= "man5";
	ch.sex = "man";
	ch.sound_type = "sailor";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Docker_dialog.c";
	ch.greeting = "Gr_Pieter Boelen";
	ch.rank 	= 3;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "2";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "3";
	ch.skill.Sneak = "1";
	ch.money = "0";
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	AddGameCharacter(n, ch);
	
	//Captain's Wife
	ch.old.name = "Maartje";
	ch.old.lastname = "Hesselink";
	ch.name = TranslateString("", "Maartje");
	ch.lastname = TranslateString("", "Hesselink");
	ch.id		= "Skipper Wife";
	ch.model	= "towngirl2";
	ch.sex = "woman";
	GiveItem2Character(ch, "blade5");
	ch.equip.blade = "blade5";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Skipper Wife_dialog.c";
	ch.greeting = "Gr_Tanneken Oremans";
	ch.rank 	= 3;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "2";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "3";
	ch.skill.Sneak = "1";
	ch.money = "1000";
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	AddGameCharacter(n, ch);
	
	//Skipper's wife lover
	ch.old.name = "Jan";
	ch.old.lastname = "Barendsz";
	ch.name = TranslateString("", "Jan");
	ch.lastname = TranslateString("", "Barendsz");
	ch.id		= "Cheater";
	ch.model	= "killer";
	ch.sex = "man";
	ch.sound_type = "sailor";
	GiveItem2Character(ch, "blade1");
	ch.equip.blade = "blade1";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Docker_dialog.c";
	ch.greeting = "Gr_Pieter Boelen";
	ch.rank 	= 3;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "2";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "3";
	ch.skill.Sneak = "1";
	ch.money = "100";
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	AddGameCharacter(n, ch);

// Havana_Crewmember
	ch.old.name = "Geoffroi";
	ch.old.lastname = "Albeille";
	ch.name = TranslateString("", "Geoffroi");
	ch.lastname = TranslateString("", "Albeille");
	ch.id		= "Crewmember_Havana";
	ch.model	= "Sailor4";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	if (GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)
	{
		GiveItem2Character(ch, "pistol1");
		ch.equip.gun = "pistol1";
	}
	else
	{
		GiveItem2Character(ch, "pistol1a");
		ch.equip.gun = "pistol1a";
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	//JRH ammo mod <--
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
	LAi_SetStayType(ch);
	LAi_group_MoveCharacter(ch, "LAI_GROUP_PLAYER");
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 500.0, 500.0);
	LAi_NoRebirthEnable(ch);
	AddGameCharacter(n, ch);

	ch.old.name = "Barend";
	ch.old.lastname = "Hesselink";
	ch.name = TranslateString("", "Barend");
	ch.lastname = TranslateString("", "Hesselink");
	ch.id		= "Skipper";
	ch.model	= "man8";
	ch.sex = "man";
	ch.sound_type = "sailor";
	GiveItem2Character(ch, "blade23+2");
	ch.equip.blade = "blade23";
	GiveItem2Character(ch, "cheaparmor");
	GiveItem2Character(ch, "pistol2");
	ch.equip.gun = "pistol2";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Watch_dialog.c";
	ch.greeting = "Gr_Pieter Boelen";
	ch.rank 	= 3;
	ch.nation = HOLLAND;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "8";
	ch.skill.Sneak = "4";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	Ch.Perks.list.Toughness = true;
	ch.money = "1000";
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 150.0, 150.0);
	LAi_NoRebirthEnable(ch);
	AddGameCharacter(n, ch);

	ch.old.name = "Barend";
	ch.old.lastname = "Hesselink";
	ch.name = TranslateString("", "Barend");
	ch.lastname = TranslateString("", "Hesselink");
	ch.id		= "Skipper1";
	ch.model	= "man8";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade23+2");
	ch.equip.blade = "blade23";
	GiveItem2Character(ch, "cheaparmor");
	GiveItem2Character(ch, "pistol2");
	ch.equip.gun = "pistol2";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	//JRH ammo mod <--
	ch.Ship.Name = "Vogelstruijs";	
	ch.Ship.Type = "Pinnace2";		
	ch.Ship.Stopped = true;
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Watch_dialog.c";
	ch.rank 	= 3;
	ch.nation = HOLLAND;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "8";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "6";
	ch.skill.Accuracy = "4";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "3";
	ch.skill.Sneak = "1";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	Ch.Perks.list.Toughness = true;
	ch.money = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 150.0, 150.0);
	LAi_NoRebirthEnable(ch);
	AddGameCharacter(n, ch);
// Thomas the Terror: Sinking the Vogelstruijs <--

	//Levis: Apothecary quest:
	ch.old.name = "Robert";
	ch.old.lastname = "Cook";
	ch.name = TranslateString("", "Robert");
	ch.lastname = TranslateString("", "Cook");
	ch.id		= "Robert Cook";
	ch.model	= "Corsair4";
	ch.sex = "man";
	ch.loyality = 15;
	ch.alignment = "good";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Robert Cook_dialog.c";
	// PB -->
	ch.Ship.Name = "HMS Challenger";
	ch.Ship.Type = "Frigate1";
	ch.Ship.Stopped = true;
	GiveItem2Character(ch, "blade26+1");
	ch.equip.blade = "blade26+1";
	GiveItem2Character(ch, "pistol5+1");
	ch.equip.gun = "pistol5+1";
	// PB <--
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	//JRH ammo mod <--
	ch.rank 	= 40;
	// PB -->
	ch.reputation = "60";
	ch.experience = "2000000";
	ch.greeting = "Gr_Pieter Boelen";
	ch.skill.Leadership = "9";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "9";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "6";
	ch.skill.Grappling = "7";
	ch.skill.Repair = "8";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "7";
	ch.skill.Sneak = "5";
	ch.perks.list.LightRepair = true;
	ch.perks.list.ShipSpeedUp = true;
	ch.perks.list.ShipTurnRateUp = true;
	ch.perks.list.StormProfessional = true;
	ch.perks.list.Turn180 = true;
	ch.perks.list.SandbankManeuver = true;
	ch.perks.list.SailingProfessional = true;
	ch.perks.list.IronWill = true;
	ch.perks.list.BasicCommerce = true;
	ch.perks.list.AdvancedCommerce = true;
	ch.perks.list.Trustworthy = true;
	ch.perks.list.SharedExperience = true;
	ch.money = "1994";
	// PB <--
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	//JRH: Apothecary quest:
	ch.old.name = "Dusty";
	ch.old.lastname = "Broome";
	ch.name = TranslateString("", "Dusty");
	ch.lastname = TranslateString("", "Broome");
	ch.id        = "Dusty_Broome";
	ch.model    = "Indian_trader";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Cartagena hotel_dialog.c";
	GiveItem2Character(ch, "tomahawk");
	ch.equip.blade = "tomahawk";
	TakeNItems(ch, "ayahuasca", 4);
	//ch.greeting = "Gr_Estrella";
	ch.nation = SPAIN;
	ch.rank    = 1;
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
	ch.money = "1";
	ch.questchar = true;
	Lai_SetImmortal(ch, true);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetStayType(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	AddGameCharacter(n, ch);

	ch.name = TranslateString("", "Surgeon");
	ch.lastname = "";
	ch.id		= "hotel_ghost2";
	ch.model = "wr_mummy2";
	ch.sex = "skeleton";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade4-2");
	ch.equip.blade = "blade4-2";
	ch.location	= "Cartagena_hotel_office";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Cartagena hotel_dialog.c";
//	ch.greeting = "";
	ch.rank 	= 1;
	ch.reputation = "10";
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
	ch.quest.meeting = "0";
	LAi_SetSitType(ch);
	Lai_SetImmortal(ch, true);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;
	AddGameCharacter(n, ch);

	ch.name = TranslateString("", "Priest");
	ch.lastname = "";
	ch.id		= "hotel_ghost3";
	ch.model = "wr_mummy3";
	ch.sex = "skeleton";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade4-2");
	ch.equip.blade = "blade4-2";
	ch.location	= "Cartagena_hotel_room1";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Cartagena hotel_dialog.c";
//	ch.greeting = "";
	ch.rank 	= 1;
	ch.reputation = "10";
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
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	Lai_SetImmortal(ch, true);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;
	AddGameCharacter(n, ch);

	ch.name = TranslateString("", "Captain");
	ch.lastname = "";
	ch.id		= "hotel_ghost6";
	ch.model = "wr_mummy6";
	ch.sex = "skeleton";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade4-2");
	ch.equip.blade = "blade4-2";
	ch.location	= "Cartagena_hotel_room2";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Cartagena hotel_dialog.c";
//	ch.greeting = "";
	ch.rank 	= 1;
	ch.reputation = "10";
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
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	Lai_SetImmortal(ch, true);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;
	AddGameCharacter(n, ch);

	ch.name = TranslateString("", "Boatswain");
	ch.lastname = "";
	ch.id		= "hotel_ghost7";
	ch.model = "wr_mummy7";
	ch.sex = "skeleton";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade4-2");
	ch.equip.blade = "blade4-2";
	ch.location	= "Cartagena_hotel_room3";
	ch.location.group = "goto";
	ch.location.locator = "goto4";
	ch.Dialog.Filename = "Cartagena hotel_dialog.c";
//	ch.greeting = "";
	ch.rank 	= 1;
	ch.reputation = "10";
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
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	Lai_SetImmortal(ch, true);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;
	AddGameCharacter(n, ch);

	ch.name = TranslateString("", "Navigator");
	ch.lastname = "";
	ch.id		= "hotel_ghost8";
	ch.model = "wr_mummy8";
	ch.sex = "skeleton";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade4-2");
	ch.equip.blade = "blade4-2";
	ch.location	= "Cartagena_hotel_room4";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "Cartagena hotel_dialog.c";
//	ch.greeting = "";
	ch.rank 	= 1;
	ch.reputation = "10";
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
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	Lai_SetImmortal(ch, true);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;
	AddGameCharacter(n, ch);

	// Kapitein of Kralendijk sidequest
	ch.old.name = "Willem";
	ch.old.lastname = "Voigt";
	ch.name = TranslateString("", "Willem");
	ch.lastname = TranslateString("", "Voigt");
	ch.id		= "Willem Voigt";
	ch.model	= "man3_1";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.location	= "Philipsburg_tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit13";
	ch.Dialog.Filename = "Willem Voigt_dialog.c";
	ch.greeting = "Gr_Peasant";
	ch.nation = HOLLAND;
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
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "DOUWESEN_CITIZENS");
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	// Hornblower sidequest
	ch.old.name = "Rodney";
	ch.old.lastname = "Leighton";
	ch.name = TranslateString("", "Rodney");
	ch.lastname = TranslateString("", "Leighton");
	ch.id		= "Sir Rodney Leighton";
	ch.model = "brtadm3_18";
	ch.sex = "man";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	GiveItem2Character(ch, "pistol1");
	ch.equip.gun = "pistol1";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	//JRH ammo mod <--
	ch.Dialog.Filename = "Sir Rodney Leighton_dialog.c";
	ch.nation = ENGLAND;
	ch.Ship.Name = "Ardent";
	ch.Ship.Type = "HMS_Bellona";
	ch.Ship.Stopped = true;
	ch.rank 	= 20;
	ch.reputation = "50";
	ch.experience = "10";
	ch.skill.Leadership = "8";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "8";
	ch.skill.Grappling = "8";
	ch.skill.Repair = "8";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "8";
	ch.skill.Sneak = "8";
	ch.money = "1000";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHuberStayType(ch);
	LAi_SetStayHuberPointMap(ch, "goto", "goto4");
	LAi_SetStayHuberPointWindow(ch, "goto", "goto6");
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.professionalnavy = ch.nation;
	ch.quest.officertype = OFFIC_TYPE_CAPNAVY;
	ch.questchar = true;
	SetRank(ch, ENGLAND, 8);
	SetRankTitle(ch, TranslateString("", "Sir"));
	AddGameCharacter(n, ch);

	ch.old.name = "Midshipman";
	ch.old.lastname = "Longley";
	ch.name = TranslateString("","Midshipman");
	ch.lastname	= TranslateString("","Longley");
	ch.id		= "Midshipman Longley";
	ch.model	= "brtmds3_18";
	ch.sex = "man";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	GiveItem2Character(ch, "pistol1");
	ch.equip.gun = "pistol1";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	//JRH ammo mod <--
	ch.Dialog.Filename = "Midshipman Longley_dialog.c";
	ch.nation = ENGLAND;
	ch.rank 	= 8;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.professionalnavy = ch.nation;
	ch.quest.officertype = OFFIC_TYPE_NAVIGATOR;
	ch.questchar = true;
//	SetRank(ch, ENGLAND, 1); // Not if his "name" is "Midshipman"
	AddGameCharacter(n, ch);
	AddGameCharacter(n, ch);

	ch.old.name = "Lieutenant";
	ch.old.lastname = "Gerard";
	ch.name = TranslateString("","Lieutenant");
	ch.lastname	= TranslateString("","Gerard");
	ch.id		= "Lieutenant Gerard";
	ch.model	= "brtlut2_18";
	ch.sex = "man";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	GiveItem2Character(ch, "pistol1");
	ch.equip.gun = "pistol1";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	//JRH ammo mod <--
	ch.Dialog.Filename = "Hornblower_quest_minors_dialog.c";
	ch.nation = ENGLAND;
	ch.rank 	= 10;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "3";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "4";
	ch.skill.Cannons = "4";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.professionalnavy = ch.nation;
	ch.quest.officertype = OFFIC_TYPE_CANNONEER;
	ch.questchar = true;
//	SetRank(ch, ENGLAND, 3); // Not if his "name" is "Lieutenant"
	AddGameCharacter(n, ch);

	ch.old.name = "Julian";
	ch.old.lastname = "Alvarado";
	ch.name = TranslateString("", "Julian");
	ch.lastname = TranslateString("", "Alvarado");
	ch.id		= "El Supremo";
	ch.model	= "El_Supremo";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "El Supremo_dialog.c";
	ch.greeting = "Gr_El Supremo";
	ch.nation = PIRATE;
	ch.rank 	= 1;
	ch.Flags.Personal = 0;		// GR: Latin American blue/white flag
	ch.Flags.Personal.texture = 5;
	ch.reputation = "None";
	ch.skipRM = true; // PB: Skip Relations Mod
	ch.nosurrender = 2;
	ch.experience = "0";
	ch.skill.Leadership = "8";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "3";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	ch.questchar = true;//MAXIMUS: identifier for captives
	SetRankTitle(ch, TranslateString("", "Don"));
	LAi_NoRebirthEnable(ch);
	AddGameCharacter(n, ch);

	ch.old.name = "Jose";
	ch.old.lastname = "Hernandez";
	ch.name = TranslateString("", "Jose");
	ch.lastname = TranslateString("", "Hernandez");
	ch.id		= "Jose Hernandez";
	ch.model	= "fisherman";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Jose Hernandez_dialog.c";
	ch.greeting = "Gr_Juan Hernandez";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade47");
	ch.equip.blade = "blade47";
	ch.Ship.Name = "Valiente";
	ch.Ship.Type = "Tartane1";
	ch.Ship.Stopped = true;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "3";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "3";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "3";
	ch.skill.Sneak = "3";
	ch.money = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	ch.questchar = true;//MAXIMUS: identifier for captives
	SetRankTitle(ch, TranslateString("", "Don"));
	AddGameCharacter(n, ch);

	ch.old.name = "Cristobal";
	ch.old.lastname = "Leon";
	ch.name = TranslateString("", "Cristobal");
	ch.lastname = TranslateString("", "Leon");
	ch.id		= "Natividad_captain";
	ch.nation	= SPAIN;
	ch.model	= "spa_cpt_18";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade14");
	ch.equip.blade = "blade14";
	GiveItem2Character(ch, "pistol2");
	ch.equip.gun = "pistol2";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Hornblower_quest_minors_dialog.c";
	ch.rank 	= 4;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "1000";
	ch.Ship.Name = "Natividad";
	ch.Ship.Type = "SP_Natividad";
	ch.Ship.Stopped = true;
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.professionalnavy = ch.nation;
	ch.quest.officertype = OFFIC_TYPE_CAPNAVY;
	ch.questchar = true;
	SetRank(ch, SPAIN, 6);
	SetRankTitle(ch, TranslateString("", "Don"));
	AddGameCharacter(n, ch);

	ch.old.name = "Escovar";
	ch.old.lastname = "Ententa";
	ch.name = TranslateString("", "Escovar");
	ch.lastname = TranslateString("", "Entenza");
	ch.id		= "Spanish_lugger_captain";
	ch.nation	= SPAIN;
	ch.model	= "spa_lut1_18";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade47");
	ch.equip.blade = "blade47";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Spanish lugger captain_dialog.c";
	ch.greeting = "Gr_Jaoquin de masse";
	ch.rank 	= 4;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "2";
	ch.skill.Accuracy = "2";
	ch.skill.Cannons = "2";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "1000";
	ch.Ship.Name = "Santiano";
	ch.Ship.Type = "Lugger1";
	ch.Ship.Stopped = true;
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.professionalnavy = ch.nation;
	ch.quest.officertype = OFFIC_TYPE_CAPNAVY;
	ch.questchar = true;
	SetRank(ch, SPAIN, 5);
	AddGameCharacter(n, ch);

	ch.old.name = "Seсorita";
	ch.old.lastname = "Hebe";
	ch.name = TranslateString("","Seсorita");
	ch.lastname = TranslateString("","Hebe");
	ch.id		= "Hebe";
	ch.model	= "downgirl2";
	ch.sex = "woman";
	LAi_NoRebirthEnable(ch);
	ch.sound_type = "female_citizen";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Hornblower_quest_minors_dialog.c";
	ch.greeting = "Gr_f_officer";
	ch.nation = SPAIN;
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
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.questchar = true;
	AddGameCharacter(n, ch);

	// Crystal Skull sidequest
	ch.old.name = "Constantino";
	ch.old.lastname = "Avellбn";
	ch.name = TranslateString("","Constantino");
	ch.lastname = TranslateString("","Avellбn");
	ch.id		= "Skull_Researcher";
	ch.model = "9R_Purs";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.location = "Santo_Domingo_Historian_House";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "skull_researcher_dialog.c";
	ch.greeting = "Gr_researcher";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "45";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "5";
	ch.skill.Sneak = "4";
	ch.money = "0";
	ch.quest.meeting = "0";
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;
	AddGameCharacter(n, ch);

	ch.nation = PIRATE;
	ch.old.name = "Growling";
	ch.old.lastname = "Bear";
	ch.name = TranslateString("","Growling");
	ch.lastname = TranslateString("","Bear");
	ch.id		= "Carib_Warrior";
	ch.model = "Native";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.location	= "";
	ch.location.group = "goto";
	ch.location.locator = "goto8";
	ch.Dialog.Filename = "Carib_Warrior_dialog.c";
	ch.greeting = "Gr_Indian";
	ch.rank 	= 5;
	ch.reputation = "40";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "4";
	ch.money = "0";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.isIndian = true;
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	ch.quest.officertype = OFFIC_TYPE_RANDCHAR;
	ch.questchar = true;
	AddGameCharacter(n, ch);

	ch.old.name = "Kicking";
	ch.old.lastname = "Raven";
	ch.name = TranslateString("","Kicking");
	ch.lastname = TranslateString("","Raven");
	ch.id		= "Carib_Chief";
	ch.model	= "Native_Chief";
	ch.sex = "man";
	ch.location	= "";
	ch.location.group = "goto";
	ch.location.locator = "goto2";
	ch.Dialog.Filename = "Carib_Chief_dialog.c";
	ch.nation = PIRATE;
	ch.rank 	= 7;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "4";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.money = "1";
	ch.isIndian = true;
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	ch.quest.officertype = OFFIC_TYPE_RANDCHAR;
	ch.greeting = "Gr_Indian";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Lewis";
	ch.old.lastname = "Vickers";
	ch.name = TranslateString("","Lewis");
	ch.lastname = TranslateString("","Vickers");
	ch.id = "Archaeologist_captain";
	ch.model = "will_3";
	ch.sex = "man";
	ch.sound_type = "seaman";
	LAi_NoRebirthEnable(ch);
	ch.nation = PERSONAL_NATION;
	GiveItem2Character(ch, "bladeC12");
	ch.equip.blade = "bladeC12";
	GiveItem2Character(ch, "pistol2");
	ch.equip.gun = "pistol2";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Archaeologist_captain_dialog.c";
	ch.greeting = "Gr_Gyles Dubois";
	ch.Ship.Name = "Ark Raider"; // KK	
	if (GetCurrentPeriod() <= PERIOD_THE_SPANISH_MAIN)
	{
		ch.Ship.Type = "RN_Galeon_L";		
		if(USE_REAL_CANNONS) ch.Ship.Cannons.Type = CANNON_TYPE_CARRONADE_LBS12;
	}
	else ch.Ship.Type = "BrigQeen1";
	ch.Ship.Stopped = true;
	ch.Ship.crew.morale = 65;
	ch.Flags.Pirate = 3;
	ch.Flags.Pirate.texture = 0;
	ch.Flags.Personal = 4;
	ch.Flags.Personal.texture = 2;
// KK -->
	ch.Ship.EmblemedSails.normalTex = "sail_petros_blue_white.tga"; // PB
	ch.Ship.EmblemedSails.nationFileName = "sail_petros_blue_white.tga"; // PB
	ch.nosurrender = 2;
// <-- KK
	ch.skipRM = true; // PB: Skip Relations Mod
	ch.rank 	= 1;
	ch.reputation = "35";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "4";
	ch.skill.Accuracy = "4";
	ch.skill.Cannons = "4";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "4";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "2374";	// Why always use a nice round number?
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;	// Stop levelling from messing him about
	AddGameCharacter(n, ch);

	// Colombian Silver sidequest
	ch.nation = SPAIN;
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "CS_soldier_01";
	ch.model = 1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
//	LAi_CharacterReincarnation(ch, true, false);
	Lai_SetImmortal(ch, true);
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "CS_soldier_dialog.c";
	ch.rank 	= 1;
	ch.nation = SPAIN;
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
	ch.quest.meeting = "0";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "SPAIN_SOLDIERS");
	ch.greeting = "Gr_isla muelle soldier";
	AddGameCharacter(n, ch);

	ch.nation = SPAIN;
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "CS_soldier_02";
	ch.model = 2; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
//	LAi_CharacterReincarnation(ch, true, false);
	Lai_SetImmortal(ch, true);
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "CS_soldier_dialog.c";
	ch.rank 	= 1;
	ch.nation = SPAIN;
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
	ch.quest.meeting = "0";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "SPAIN_SOLDIERS");
	ch.greeting = "Gr_isla muelle soldier";
	AddGameCharacter(n, ch);

	ch.nation = SPAIN;
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "CS_soldier_03";
	ch.model = 3; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
//	LAi_CharacterReincarnation(ch, true, false);
	Lai_SetImmortal(ch, true);
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "CS_soldier_dialog.c";
	ch.rank 	= 1;
	ch.nation = SPAIN;
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
	ch.quest.meeting = "0";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "SPAIN_SOLDIERS");
	ch.greeting = "Gr_isla muelle soldier";
	AddGameCharacter(n, ch);

	ch.nation = SPAIN;
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "CS_soldier_04";
	ch.model = 4; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
//	LAi_CharacterReincarnation(ch, true, false);
	Lai_SetImmortal(ch, true);
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "CS_soldier_dialog.c";
	ch.rank 	= 1;
	ch.nation = SPAIN;
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
	ch.quest.meeting = "0";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "SPAIN_SOLDIERS");
	ch.greeting = "Gr_isla muelle soldier";
	AddGameCharacter(n, ch);

	ch.nation = SPAIN;
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "CS_soldier_05";
	ch.model = 5; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Isla Muelle soldier_dialog.c";
	ch.rank 	= 1;
	ch.nation = SPAIN;
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
	ch.quest.meeting = "0";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "SPAIN_SOLDIERS");
	ch.greeting = "Gr_isla muelle soldier";
	AddGameCharacter(n, ch);

	ch.nation = SPAIN;
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "CS_soldier_06";
	ch.model = 6; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
//	LAi_CharacterReincarnation(ch, true, false);
	Lai_SetImmortal(ch, true);
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Isla Muelle soldier_dialog.c";
	ch.rank 	= 1;
	ch.nation = SPAIN;
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
	ch.quest.meeting = "0";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "SPAIN_SOLDIERS");
	ch.greeting = "Gr_isla muelle soldier";
	AddGameCharacter(n, ch);

	ch.nation = SPAIN;
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "CS_tavern_officer";
	ch.model = 0; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	if (ENABLE_WEAPONSMOD)
	{
		GiveItem2Character(ch, "blade33+2");	// Moorish Sabre
		ch.equip.blade = "blade33+2";
		GiveItem2Character(ch, "pistol27+1");	// Miquelet
		ch.equip.gun = "pistol27+1";
	}
	else
	{
		GiveItem2Character(ch, "blade33");	// Moorish Sabre
		ch.equip.blade = "blade33";
		GiveItem2Character(ch, "pistol27");	// Miquelet
		ch.equip.gun = "pistol27";
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "CS_officer_dialog.c";
	ch.rank 	= 4;
	ch.nation = SPAIN;
	ch.reputation = "None";
	ch.experience = "10000";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "5";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "1000";
	ch.quest.meeting = "0";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	LAi_NoRebirthEnable(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_SOLDIERS");
	ch.greeting = "Gr_isla muelle soldier";
	AddGameCharacter(n, ch);

	ch.old.name = "Gilberto";
	ch.old.lastname = "Solano";
	ch.name = TranslateString("","Gilberto");
	ch.lastname = TranslateString("","Solano");
	ch.id		= "CS_Spanish_Captain1";
	ch.nation	= SPAIN;
	ch.model	= "Espinosa";
	ch.model.animation = "Blaze";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	if (ENABLE_WEAPONSMOD)
	{
		GiveItem2Character(ch, "blade14+2");
		ch.equip.blade = "blade14+2";
		GiveItem2Character(ch, "pistol8+1");
		ch.equip.gun = "pistol8+1";
	}
	else
	{
		GiveItem2Character(ch, "blade14");
		ch.equip.blade = "blade14";
		GiveItem2Character(ch, "pistol8");
		ch.equip.gun = "pistol8";
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "isla muelle soldier_dialog.c";
	ch.rank 	= 6;
	ch.reputation = "45";
	ch.experience = "0";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "6";
	ch.skill.Cannons = "6";
	ch.skill.Grappling = "4";
	ch.skill.Repair = "4";
	ch.skill.Defence = "5";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = 4000 + rand(1000);	
	ch.Ship.Name = "Santa Matilde";
	if (GetCurrentPeriod() <= PERIOD_GOLDEN_AGE_OF_PIRACY) ch.Ship.Type = "Galeon50";
	if (GetCurrentPeriod() == PERIOD_COLONIAL_POWERS) ch.Ship.Type = "FR_Fleuron";
	if (GetCurrentPeriod() >= PERIOD_REVOLUTIONS) ch.Ship.Type = "FR_Superbe";
	ch.Ship.Stopped = true;
	ch.Ship.crew.morale = 70;
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 200.0, 200.0);
	ch.nation = SPAIN;
	SetRank(ch, SPAIN, 7);
	ch.professionalnavy = ch.nation;
	ch.quest.officertype = OFFIC_TYPE_CAPNAVY;
	ch.questchar = true;	// Stop levelling from messing him about
	AddGameCharacter(n, ch);

	ch.old.name = "Rafael";
	ch.old.lastname = "Patiсo";
	ch.name = TranslateString("","Rafael");
	ch.lastname = TranslateString("","Patiсo");
	ch.id		= "CS_Spanish_Captain2";
	ch.nation	= SPAIN;
	ch.model	= "9JdSpa";
	ch.sound_type = "soldier";
//	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	if (ENABLE_WEAPONSMOD)
	{
		GiveItem2Character(ch, "blade44+2");
		ch.equip.blade = "blade44+2";
		GiveItem2Character(ch, "PiratesPistol+1");
		ch.equip.gun = "PiratesPistol+1";
	}
	else
	{
		GiveItem2Character(ch, "blade44");
		ch.equip.blade = "blade44";
		GiveItem2Character(ch, "PiratesPistol");
		ch.equip.gun = "PiratesPistol";
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "isla muelle soldier_dialog.c";
	ch.rank 	= 5;
	ch.reputation = "45";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "4";
	ch.skill.Repair = "4";
	ch.skill.Defence = "4";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = 2500 + rand(1000);	
	ch.Ship.Name = "Marнa Santнsima";
	if (GetCurrentPeriod() <= PERIOD_GOLDEN_AGE_OF_PIRACY) ch.Ship.Type = "GaleonWar";
	if (GetCurrentPeriod() == PERIOD_COLONIAL_POWERS) ch.Ship.Type = "WallerPinnace";
	if (GetCurrentPeriod() >= PERIOD_REVOLUTIONS) ch.Ship.Type = "FR_BattleFrigate";
	ch.Ship.Stopped = true;
	ch.Ship.crew.morale = 70;
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 150.0, 150.0);
	ch.nation = SPAIN;
	SetRank(ch, SPAIN, 6);
	ch.professionalnavy = ch.nation;
	ch.quest.officertype = OFFIC_TYPE_CAPNAVY;
	ch.questchar = true;	// Stop levelling from messing him about
	AddGameCharacter(n, ch);

	ch.old.name = "Miguel";
	ch.old.lastname = "Angulo";
	ch.name = TranslateString("","Miguel");
	ch.lastname = TranslateString("","Angulo");
	ch.id		= "CS_Spanish_Captain3";
	ch.nation	= SPAIN;
	ch.model	= GetRandomModelForTypeExSubCheck(true, "Captains", "man", SPAIN);;
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	if (ENABLE_WEAPONSMOD)
	{
		GiveItem2Character(ch, "blade47+1");
		ch.equip.blade = "blade47+2";
		GiveItem2Character(ch, "pistol27+1");
		ch.equip.gun = "pistol27+1";
	}
	else
	{
		GiveItem2Character(ch, "blade47");
		ch.equip.blade = "blade47";
		GiveItem2Character(ch, "pistol27");
		ch.equip.gun = "pistol27";
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "isla muelle soldier_dialog.c";
	ch.rank 	= 5;
	ch.reputation = "45";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "4";
	ch.skill.Repair = "4";
	ch.skill.Defence = "4";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = 1500 + rand(1000);	
	ch.Ship.Name = "Cardenal Cisneros";
	if (GetCurrentPeriod() <= PERIOD_GOLDEN_AGE_OF_PIRACY) ch.Ship.Type = "GaleonWar";
	if (GetCurrentPeriod() == PERIOD_COLONIAL_POWERS) ch.Ship.Type = "WallerPinnace";
	if (GetCurrentPeriod() >= PERIOD_REVOLUTIONS) ch.Ship.Type = "FR_BattleFrigate";
	ch.Ship.Stopped = true;
	ch.Ship.crew.morale = 70;
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 150.0, 150.0);
	ch.nation = SPAIN;
	SetRank(ch, SPAIN, 6);
	ch.professionalnavy = ch.nation;
	ch.quest.officertype = OFFIC_TYPE_CAPNAVY;
	ch.questchar = true;	// Stop levelling from messing him about
	AddGameCharacter(n, ch);

	ch.old.name = "Donato";
	ch.old.lastname = "Elcano";
	ch.name = TranslateString("","Donato");
	ch.lastname = TranslateString("","Elcano");
	ch.id		= "CS_Spanish_Captain4";
	ch.nation	= SPAIN;
	ch.model	= GetRandomModelForTypeExSubCheck(true, "Captains", "man", SPAIN);;
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	if (ENABLE_WEAPONSMOD)
	{
		GiveItem2Character(ch, "bladeC26+1");
		ch.equip.blade = "bladeC26+1";
		GiveItem2Character(ch, "PiratesPistol+1");
		ch.equip.gun = "PiratesPistol+1";
	}
	else
	{
		GiveItem2Character(ch, "bladeC26");
		ch.equip.blade = "bladeC26";
		GiveItem2Character(ch, "PiratesPistol");
		ch.equip.gun = "PiratesPistol";
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "isla muelle soldier_dialog.c";
	ch.rank 	= 5;
	ch.reputation = "45";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "4";
	ch.skill.Repair = "4";
	ch.skill.Defence = "4";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = 1500 + rand(1000);	
	ch.Ship.Name = "Бngel de la Guarda";
	if (GetCurrentPeriod() <= PERIOD_GOLDEN_AGE_OF_PIRACY) ch.Ship.Type = "GaleonWar";
	if (GetCurrentPeriod() == PERIOD_COLONIAL_POWERS) ch.Ship.Type = "Frigate1";
	if (GetCurrentPeriod() >= PERIOD_REVOLUTIONS) ch.Ship.Type = "SP_Surprise";
	ch.Ship.Stopped = true;
	ch.Ship.crew.morale = 70;
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 150.0, 150.0);
	ch.nation = SPAIN;
	SetRank(ch, SPAIN, 5);
	ch.professionalnavy = ch.nation;
	ch.quest.officertype = OFFIC_TYPE_CAPNAVY;
	ch.questchar = true;	// Stop levelling from messing him about
	AddGameCharacter(n, ch);

	ch.old.name = "Leonardo";
	ch.old.lastname = "Echevarrнa";
	ch.name = TranslateString("","Leonardo");
	ch.lastname = TranslateString("","Echevarrнa");
	ch.id		= "CS_Spanish_Captain5";
	ch.nation	= SPAIN;
	ch.model	= GetRandomModelForTypeExSubCheck(true, "Captains", "man", SPAIN);
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	if (ENABLE_WEAPONSMOD)
	{
		GiveItem2Character(ch, "blade46+2");
		ch.equip.blade = "blade46+2";
		if (GetCurrentPeriod() <= PERIOD_THE_SPANISH_MAIN)
		{
			GiveItem2Character(ch, "pistol7a+2");
			ch.equip.gun = "pistol7a+2";
		}
		else
		{
			GiveItem2Character(ch, "pistol7+2");
			ch.equip.gun = "pistol7+2";
		}
	}
	else
	{
		GiveItem2Character(ch, "bladeC26");
		ch.equip.blade = "bladeC26";
		if (GetCurrentPeriod() <= PERIOD_THE_SPANISH_MAIN)
		{
			GiveItem2Character(ch, "pistol7a");
			ch.equip.gun = "pistol7a";
		}
		else
		{
			GiveItem2Character(ch, "pistol7");
			ch.equip.gun = "pistol7";
		}
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "isla muelle soldier_dialog.c";
	ch.rank 	= 5;
	ch.reputation = "45";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "4";
	ch.skill.Repair = "4";
	ch.skill.Defence = "4";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = 1500 + rand(1000);	
	ch.Ship.Name = "Septentriуn";
	if (GetCurrentPeriod() <= PERIOD_GOLDEN_AGE_OF_PIRACY) ch.Ship.Type = "FastGalleon1";
	if (GetCurrentPeriod() == PERIOD_COLONIAL_POWERS) ch.Ship.Type = "Frigate1";
	if (GetCurrentPeriod() >= PERIOD_REVOLUTIONS) ch.Ship.Type = "SP_Surprise";
	ch.Ship.Stopped = true;
	ch.Ship.crew.morale = 70;
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 150.0, 150.0);
	ch.nation = SPAIN;
	SetRank(ch, SPAIN, 5);
	ch.professionalnavy = ch.nation;
	ch.quest.officertype = OFFIC_TYPE_CAPNAVY;
	ch.questchar = true;	// Stop levelling from messing him about
	AddGameCharacter(n, ch);

	ch.old.name = "Meredith";		// Introduces player to the quest if high enough level and no LoM
	ch.old.lastname = "Byrom";
	ch.name = TranslateString("", "Meredith");
	ch.lastname = TranslateString("", "Byrom");
	ch.id		= "Meredith Byrom";
	ch.model	= "man1_1";
	ch.sex = "man";
	ch.sound_type = "pirate";
	if (GetCurrentPeriod() <= PERIOD_THE_SPANISH_MAIN)
	{
		GiveItem2Character(ch, "blade10");
		ch.equip.blade = "blade10";
		GiveItem2Character(ch, "pistol1a");
		ch.equip.gun = "pistol1a";
	}
	else
	{
		GiveItem2Character(ch, "blade27");
		ch.equip.blade = "blade27";
		GiveItem2Character(ch, "pistol1");
		ch.equip.gun = "pistol1";
	}
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD)
	{
		TakenItems(ch, "gunpowder", 2 + rand(3));
		TakenItems(ch, "pistolbullets", 2 + rand(3));
	}
	//JRH ammo mod <--
	ch.experience = CalculateExperienceFromRank(10)+ (CalculateExperienceFromRank(10)/10 + rand(10000));	
	ch.location	= "none"; // "Smugglers_Tavern"
	ch.location.group = "goto";
	ch.location.locator = "goto6";
	ch.Dialog.Filename = "Meredith Byrom_dialog.c";
	ch.rank 	= 10;
	ch.reputation = "None";
	ch.greeting = "Gr_Clauss";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "2";
	ch.skill.Cannons = "2";
	ch.skill.Grappling = "2";
	ch.skill.Repair = "3";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.Gunman = true;
	ch.quest.officertype = OFFIC_TYPE_SAILOR;
	ch.quest.officerprice = "1000";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	AddGameCharacter(n, ch);
}
	
