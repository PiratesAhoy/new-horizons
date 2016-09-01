void CreateIslaMonaCharacters(ref n)
{
	object chobj;
	ref ch;
	int iNation = sti(Islands[FindIsland("IslaMona")].smuggling_nation);

	makeref(ch, chobj);

//Location: Lighthouse

		// Randolf Blecher- port administrator
	ch.old.name = "Randolf";
	ch.old.lastname = "Blecher";
	ch.name = TranslateString("","Randolf");
	ch.lastname = TranslateString("","Blecher");
	ch.id		= "Randolf Blecher";
	ch.model	= "Man6_1";
	ch.sex = "man";
	ch.location	= "IslaMona_Headport_house";
	ch.sound_type = "male_citizen";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Randolf Blecher_dialog.c";
	ch.greeting = "Gr_Laurence Wellman";
	ch.nation = iNation;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.Ship.Name = "The Elegance";
	ch.Ship.Type = 	"BarqueHeavy";	
	ch.Ship.Stopped = true;		
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
	LAi_SetStayType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);
	
// Wilfred Burman
	ch.old.name = "Wilfred";
	ch.old.lastname = "Burman";
	ch.name = TranslateString("","Wilfred");
	ch.lastname = TranslateString("","Burman");
	ch.id		= "Wilfred Burman";
	ch.model	= 0;
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "IslaMona_residence";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.rank 	= 8;
	ch.reputation = "None";
	ch.experience = "80";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "2";
	ch.skill.Grappling = "2";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "3";
	ch.money = "100";
	ch.Dialog.Filename = "Wilfred Burman_dialog.c";
	ch.greeting = "Gr_Redmond Soldier";
	ch.nation = iNation;
	LAi_SetHuberType(ch);
	ch.isSoldier = true;
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	LAi_NoRebirthEnable(ch);	
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 30.0, 30.0);
	AddGameCharacter(n, ch);		

			//Patrol
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Mona_patrol_1";
	ch.model	= 5; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	ch.nation = iNation;
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
	ch.location	= "IslaMona_port";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
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
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.greeting = "Gr_Patrol";
	AddGameCharacter(n, ch);

			//Patrol
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Mona_patrol_2";
	ch.model	= 4; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	ch.nation = iNation;
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
	ch.location	= "IslaMona_port";
	ch.location.group = "goto";
	ch.location.locator = "goto20";
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
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.greeting = "Gr_Patrol";
	AddGameCharacter(n, ch);
	
			//Patrol
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Mona_patrol_3";
	ch.model	= 2; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	ch.nation = iNation;
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
	ch.location	= "IslaMona_port";
	ch.location.group = "goto";
	ch.location.locator = "goto18";
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
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.greeting = "Gr_Patrol";
	AddGameCharacter(n, ch);

			//Patrol
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Mona_patrol_4";
	ch.model	= 3; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	ch.nation = iNation;
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
	ch.location	= "IslaMona_port_exit";
	ch.location.group = "goto";
	ch.location.locator = "goto13";
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
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.greeting = "Gr_Patrol";
	AddGameCharacter(n, ch);
	
			//Patrol
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Mona_patrol_5";
	ch.model	= 5; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	ch.nation = iNation;
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
	ch.location	= "IslaMona_port_exit";
	ch.location.group = "goto";
	ch.location.locator = "goto12";
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
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.greeting = "Gr_Patrol";
	AddGameCharacter(n, ch);
	
			//Patrol
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Mona_patrol_6";
	ch.model	= 2; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	ch.nation = iNation;
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
	ch.location	= "IslaMona_port_exit";
	ch.location.group = "reload";
	ch.location.locator = "reload6";
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
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.greeting = "Gr_Patrol";
	AddGameCharacter(n, ch);

			//Guardian
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Mona_patrol_7";
	ch.model	= 2; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = ENGLAND;
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
	ch.location	= "IslaMona_passage";
	ch.location.group = "goto";
	ch.location.locator = "goto6";
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
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.greeting = "Gr_Patrol";
	AddGameCharacter(n, ch);

			//Guardian
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Mona_patrol_8";
	ch.model	= 3; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = ENGLAND;
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
	ch.location	= "IslaMona_passage";
	ch.location.group = "goto";
	ch.location.locator = "goto4";
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
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.greeting = "Gr_Patrol";
	AddGameCharacter(n, ch);

			//Guardian
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Mona_patrol_9";
	ch.model	= 4; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = ENGLAND;
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
	ch.location	= "IslaMona_passage";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
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
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.greeting = "Gr_Patrol";
	AddGameCharacter(n, ch);

			//Guardian
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Mona_patrol_10";
	ch.model	= 2; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = ENGLAND;
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
	ch.location	= "Fort_Entry";
	ch.location.group = "Officers";
	ch.location.locator = "reload2_2";
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
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.greeting = "Gr_Patrol";
	AddGameCharacter(n, ch);

			//Guardian
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Mona_patrol_11";
	ch.model	= 3; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = ENGLAND;
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
	ch.location	= "Fort_Entry";
	ch.location.group = "Officers";
	ch.location.locator = "reload2_1";
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
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.greeting = "Gr_Patrol";
	AddGameCharacter(n, ch);

			//Guardian
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Mona_patrol_12";
	ch.model	= 4; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = ENGLAND;
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
	ch.location	= "IslaMona_fort";
	ch.location.group = "rld";
	ch.location.locator = "aloc0";
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
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.greeting = "Gr_Patrol";
	AddGameCharacter(n, ch);

			//Guardian
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Mona_patrol_13";
	ch.model	= 5; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = ENGLAND;
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
	ch.location	= "IslaMona_fort";
	ch.location.group = "rld";
	ch.location.locator = "loc5";
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
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.greeting = "Gr_Patrol";
	AddGameCharacter(n, ch);

			//Guardian
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Mona_patrol_14";
	ch.model	= 2; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = ENGLAND;
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
	ch.location	= "IslaMona_fort";
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
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.greeting = "Gr_Patrol";
	AddGameCharacter(n, ch);

			//Guardian
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Mona_patrol_15";
	ch.model	= 3; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = ENGLAND;
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
	ch.location	= "IslaMona_fort";
	ch.location.group = "rld";
	ch.location.locator = "loc7";
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
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.greeting = "Gr_Patrol";
	AddGameCharacter(n, ch);

			//Guardian
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Mona_patrol_16";
	ch.model	= 2; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = ENGLAND;
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
	ch.location	= "IslaMona_fort";
	ch.location.group = "rld";
	ch.location.locator = "loc8";
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
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.greeting = "Gr_Patrol";
	AddGameCharacter(n, ch);

			//Guardian
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Mona_patrol_17";
	ch.model	= 6; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = ENGLAND;
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
	ch.location	= "IslaMona_fort";
	ch.location.group = "rld";
	ch.location.locator = "loc9";
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
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.greeting = "Gr_Patrol";
	AddGameCharacter(n, ch);

			//Guardian
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Mona_patrol_18";
	ch.model	= 1; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = ENGLAND;
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
	ch.location	= "IslaMona_fort";
	ch.location.group = "reload";
	ch.location.locator = "reload1";
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
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.greeting = "Gr_Patrol";
	AddGameCharacter(n, ch);

			//Guardian
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Mona_patrol_19";
	ch.model	= 1; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = ENGLAND;
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
	ch.location	= "IslaMona_port";
	ch.location.group = "reload";
	ch.location.locator = "reload1";
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
	LAi_SetLoginTime(ch, 23.0, 8.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.greeting = "Gr_Patrol";
	AddGameCharacter(n, ch);		

			//Guardian
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Mona_patrol_20";
	ch.model	= 2; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = ENGLAND;
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
	ch.location	= "IslaMona_port_exit";
	ch.location.group = "reload";
	ch.location.locator = "reload2";
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
	LAi_SetLoginTime(ch, 23.0, 8.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.greeting = "Gr_Patrol";
	AddGameCharacter(n, ch);		
}
