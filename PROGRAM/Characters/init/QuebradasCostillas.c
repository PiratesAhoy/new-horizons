void CreateQuebradasCostillasCharacters(ref n)
{
	object chobj;
	ref ch;
	makeref(ch, chobj);

// QC_port:

		// Terry  Snider -- Black_Corsair
	ch.old.name = "Terry";
	ch.old.lastname = "Snider";
	ch.name = TranslateString("", "Terry");
	ch.lastname = TranslateString("", "Snider");
	ch.id		= "Terry Snider";
	ch.model	= "Black_Corsair";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "QC_port";
	ch.location.group = "goto";
	ch.location.locator = "character3";
	ch.Dialog.Filename = "Terry Snider_dialog.c";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
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
	LAi_SetWarriorType(ch);
	LAi_warrior_DialogEnable(ch, true);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "QC_SOLDIERS");
	ch.greeting = "Gr_QC Citizen";
	AddGameCharacter(n, ch);

		// Gilles Roche -- Corsair2
	ch.old.name = "Gilles";
	ch.old.lastname = "Roche";
	ch.name = TranslateString("", "Gilles");
	ch.lastname = TranslateString("", "Roche1");	// Was "Roche", but 'TranslateString' turns that into " roche"
	ch.id		= "Gilles Roche";
	ch.model	= "Corsair2";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "QC_port";
	ch.location.group = "goto";
	ch.location.locator = "character1";
	ch.Dialog.Filename = "QC citizen_dialog.c";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
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
	LAi_SetWarriorType(ch);
	LAi_warrior_DialogEnable(ch, true);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "QC_SOLDIERS");
	ch.greeting = "Gr_QC Citizen";
	AddGameCharacter(n, ch);

		// Alvaro Dimas -- korsar
	ch.old.name = "Alvaro";
	ch.old.lastname = "Dimas";
	ch.name = TranslateString("", "Alvaro");
	ch.lastname = TranslateString("", "Dimas");
	ch.id		= "Alvaro Dimas";
	ch.model	= "korsar";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "QC_port";
	ch.location.group = "goto";
	ch.location.locator = "goto17";
	ch.Dialog.Filename = "QC citizen_dialog.c";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
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
	LAi_SetWarriorType(ch);
	LAi_warrior_DialogEnable(ch, true);
	LAi_SetLoginTime(ch, 22.0, 5.98333);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "QC_SOLDIERS");
	ch.greeting = "Gr_QC Citizen";
	AddGameCharacter(n, ch);


// QC_town:

		// Natan Bueno -- Corsair1
	ch.old.name = "Natan";
	ch.old.lastname = "Bueno";
	ch.name = TranslateString("", "Natan");
	ch.lastname = TranslateString("", "Bueno");
	ch.id		= "Natan Bueno";
	ch.model	= "Corsair1";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "QC_town";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "QC citizen_dialog.c";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
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
	LAi_SetWarriorType(ch);
	LAi_warrior_DialogEnable(ch, true);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "QC_SOLDIERS");
	ch.greeting = "Gr_QC Citizen";
	AddGameCharacter(n, ch);

		// Romao  Edhino -- fatman
	ch.old.name = "Romao";
	ch.old.lastname = "Edhino";
	ch.name = TranslateString("", "Romao");
	ch.lastname = TranslateString("", "Edhino");
	ch.id		= "Romao  Edhino";
	ch.model	= "fatman";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "QC_town";
	ch.location.group = "goto";
	ch.location.locator = "goto9";
	ch.Dialog.Filename = "QC citizen_dialog.c";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
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
	LAi_SetWarriorType(ch);
	LAi_warrior_DialogEnable(ch, true);
	LAi_SetLoginTime(ch, 22.0, 5.98333);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "QC_SOLDIERS");
	ch.greeting = "Gr_QC Citizen";
	AddGameCharacter(n, ch);

		// Valerio Tintorero -- Corsair3
	ch.old.name = "Valerio";
	ch.old.lastname = "Tintorero";
	ch.name = TranslateString("", "Valerio");
	ch.lastname = TranslateString("", "Tintorero");
	ch.id		= "Valerio Tintorero";
	ch.model	= "Corsair3";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "QC_town";
	ch.location.group = "goto";
	ch.location.locator = "goto19";
	ch.Dialog.Filename = "QC citizen_dialog.c";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
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
	LAi_SetWarriorType(ch);
	LAi_warrior_DialogEnable(ch, true);
	LAi_SetLoginTime(ch, 22.0, 5.98333);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "QC_SOLDIERS");
	ch.greeting = "Gr_QC Citizen";
	AddGameCharacter(n, ch);

		// Elias  Hafte -- man1
	ch.old.name = "Elias";
	ch.old.lastname = "Hafte";
	ch.name = TranslateString("", "Elias");
	ch.lastname = TranslateString("", "Hafte");
	ch.id		= "Elias Hafte";
	ch.model	= "man1";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "QC_town";
	ch.location.group = "goto";
	ch.location.locator = "goto8";
	ch.Dialog.Filename = "QC citizen_dialog.c";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
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
	LAi_SetWarriorType(ch);
	LAi_warrior_DialogEnable(ch, true);
	LAi_SetLoginTime(ch, 22.0, 5.98333);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "QC_SOLDIERS");
	ch.greeting = "Gr_QC Citizen";
	AddGameCharacter(n, ch);

		// Hamund Verret -- shkiper
	ch.old.name = "Hamund";
	ch.old.lastname = "Verret";
	ch.name = TranslateString("", "Hamund");
	ch.lastname = TranslateString("", "Verret");
	ch.id		= "Hamund Verret";
	ch.model	= "man1_2";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "QC_town";
	ch.location.group = "goto";
	ch.location.locator = "goto13";
	ch.Dialog.Filename = "QC citizen_dialog.c";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
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
	LAi_SetWarriorType(ch);
	LAi_warrior_DialogEnable(ch, true);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "QC_SOLDIERS");
	ch.greeting = "Gr_QC Citizen";
	AddGameCharacter(n, ch);

		// Armand Delacroix -- added by CatalinaThePirate
	ch.old.name = "Armand";
	ch.old.lastname = "Delacroix";
	ch.name = TranslateString("", "Armand");
	ch.lastname = TranslateString("", "Delacroix");
	ch.id		= "Armand Delacroix";
	ch.model	= "armdelfra";
	ch.sex = "man";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Armand Delacroix_dialog.c";
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
	ch.rank 	= 20;
	ch.reputation = "25";
	ch.experience = "250000";
	ch.skill.Leadership = "10";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "6";
	ch.skill.Accuracy = "4";
	ch.skill.Cannons = "7";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "3";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "10";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.Gunman = true;
	ch.perks.list.ProfessionalGunman = true;
	ch.perks.list.Rush = true;
	ch.perks.list.IronWill = true;
	ch.perks.list.FastReload = true;
	ch.perks.list.HullDamageUp = true;
	ch.perks.list.BasicDamageControl = true;
	ch.perks.list.Rigging = true;
	ch.perks.list.LightRepair = true;
	ch.perks.list.SharedExperience = true;
	ch.money = "40000";
	LAi_SetSitType(ch);
	Lai_SetImmortal(ch, true);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 160.0, 160.0);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	ch.greeting = "Gr_Armand Delacroix";
	AddGameCharacter(n, ch);

	// QC Tailor
	ch.old.name = "Howell";
	ch.old.lastname = "Davis";
	ch.name	= TranslateString("",  "Howell");
	ch.lastname	= TranslateString("",  "Davis");
	ch.id = "Howell Davis";
	ch.model = "storeman";
	ch.sex = "man";
	ch.location	= "QC_Town";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.IsTailor = true;
	ch.Dialog.Filename = "tailor_dialog.c";
 	ch.Dialog.Filename.Groupdialog = "tailor.c";
	ch.rank 	= 1;
	ch.nation = PIRATE;
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

// QC_residence:

		// Isenbrandt Jurcksen -- capitan
	ch.old.name = "Isenbrandt";
	ch.old.lastname = "Jurcksen";
	ch.name = TranslateString("", "Isenbrandt");
	ch.lastname = TranslateString("", "Jurcksen");
	ch.id		= "Isenbrandt Jurcksen";
	ch.model	= "50_Boss1"; // was "capitan"
	ch.sex = "man";
	ch.location	= "QC_residence";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
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
	ch.skipRM = true; // PB: Skip Relations Mod
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

//------------QC BROTHEL START--------------------------

			//Morys Biddulph DICE
	ch.old.name = "Morys";
	ch.old.lastname = "Biddulph";
	ch.name = TranslateString("", "Morys");
	ch.lastname = TranslateString("", "Biddulph");
	ch.id		= "Morys Biddulph2";
	ch.model	= "capitan1";
	ch.sound_type = "seaman";
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "QC_brothel";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Habitue_dialog.c";
	ch.greeting = "Gr_QC Citizen";
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
	ch.quest.last_theme = "";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 5.0, 21.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);

			//Roger Hayes DICE
	ch.old.name = "Roger";
	ch.old.lastname = "Hayes";
	ch.name = TranslateString("", "Roger");
	ch.lastname = TranslateString("", "Hayes");
	ch.id		= "Roger Hayes2";
	ch.model	= "capstan"; // <-- Estharos Change from Bocman3 to this model
	ch.sound_type = "seaman";
	ch.sex = "man";
	ch.location	= "QC_brothel";
	ch.location.group = "Sit";
	ch.location.locator = "Sit3";
	ch.Dialog.Filename = "Habitue_dialog.c";
	ch.greeting = "Gr_QC Citizen";
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
	ch.quest.last_theme = "";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 5.0, 21.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);

			//Flann Marrow
	ch.old.name = "Flann";
	ch.old.lastname = "Marrow";
	ch.name = TranslateString("", "Flann");
	ch.lastname = TranslateString("", "Marrow");
	ch.id		= "Flann Marrow2";
	ch.model	= "man1_1";
	ch.sound_type = "male_citizen";
	ch.sex = "man";
	ch.location	= "QC_brothel";
	ch.location.group = "Sit";
	ch.location.locator = "Sit3";
	ch.Dialog.Filename = "Habitue_dialog.c";
	ch.greeting = "Gr_QC Citizen";
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
	LAi_SetLoginTime(ch, 21.1, 4.9);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);

			//Evan Newson
	ch.old.name = "Evan";
	ch.old.lastname = "Newson";
	ch.name = TranslateString("", "Evan");
	ch.lastname = TranslateString("", "Newson");
	ch.id		= "Evan Newson2";
	ch.model	= "man2";
	ch.sound_type = "male_citizen";
	ch.sex = "man";
	ch.location	= "QC_brothel";
	ch.location.group = "Sit";
	ch.location.locator = "Sit1";
	ch.Dialog.Filename = "Habitue_dialog.c";
	ch.greeting = "Gr_QC Citizen";
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
	LAi_SetLoginTime(ch, 21.1, 4.8);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);

			//MISTRESS
	ch.old.name = "Celestine";
	ch.old.lastname = "Maupassant";
	ch.name = TranslateString("", "Celestine");
	ch.lastname = TranslateString("", "Maupassant");
	ch.id		= "Mistress";
	ch.model	= "Liz2"; // KK
	ch.sound_type = "female_citizen";
	ch.sex = "woman";
	ch.location	= "QC_brothel";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "mistress_dialog.c";
	ch.greeting = "Gr_Brothel's mom";//MAXIMUS
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
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);

		// WENCH 1
	ch.old.name = "Natalia";
	ch.old.lastname = "Decoteau";
	ch.name = TranslateString("", "Natalia");
	ch.lastname = TranslateString("", "Decoteau");
	ch.id		= "wench1";
	ch.model	= "towngirl2";
	ch.sound_type = "female_citizen";
	ch.sex = "woman";
	ch.location	= "QC_brothel";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
	ch.Dialog.Filename = "wench_dialog.c";
	ch.greeting = "Gr_Wench";//MAXIMUS
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
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 18.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");

	AddGameCharacter(n, ch);

		// WENCH 1
	ch.old.name = "Natalia";
	ch.old.lastname = "Decoteau";
	ch.name = TranslateString("", "Natalia");
	ch.lastname = TranslateString("", "Decoteau");
	ch.id		= "wench1";
	ch.model	= "towngirl2";
	ch.sound_type = "female_citizen";
	ch.sex = "woman";
	ch.location	= "QC_brothel";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
	ch.Dialog.Filename = "wench_dialog.c";
	ch.greeting = "Gr_Wench";//MAXIMUS
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
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 12.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");

	AddGameCharacter(n, ch);

		// WENCH 2
	ch.old.name = "Serena";
	ch.old.lastname = "Tisserand";
	ch.name = TranslateString("", "Serena");
	ch.lastname = TranslateString("", "Tisserand");
	ch.id		= "wench2";
	ch.model	= "towngirl6";
	ch.sound_type = "female_citizen";
	ch.sex = "woman";
	ch.location	= "QC_brothel";
	ch.location.group = "goto";
	ch.location.locator = "goto4";
	ch.Dialog.Filename = "wench_dialog.c";
	ch.greeting = "Gr_Wench";//MAXIMUS
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
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 18.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");

	AddGameCharacter(n, ch);

		// WENCH 3
	ch.old.name = "Amelia";
	ch.old.lastname = "Frere";
	ch.name = TranslateString("", "Amelia");
	ch.lastname = TranslateString("", "Frere");
	ch.id		= "wench3";
	ch.model	= "towngirl5";
	ch.sound_type = "female_citizen";
	ch.sex = "woman";
	ch.location	= "QC_brothel";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "wench_dialog.c";
	ch.greeting = "Gr_Wench";//MAXIMUS
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
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 12.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");

	AddGameCharacter(n, ch);

		// WENCH 3
	ch.old.name = "Amelia";
	ch.old.lastname = "Frere";
	ch.name = TranslateString("", "Amelia");
	ch.lastname = TranslateString("", "Frere");
	ch.id		= "wench3";
	ch.model	= "towngirl5";
	ch.sound_type = "female_citizen";
	ch.sex = "woman";
	ch.location	= "QC_brothel";
	ch.location.group = "goto";
	ch.location.locator = "goto2";
	ch.Dialog.Filename = "wench_dialog.c";
	ch.greeting = "Gr_Wench";//MAXIMUS
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
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 6.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");

	AddGameCharacter(n, ch);

			//BARTENDER
	ch.old.name = "Valentina";
	ch.old.lastname = "Malter";
	ch.name = TranslateString("", "Valentina");
	ch.lastname = TranslateString("", "Malter");
	ch.id		= "QCbartender";
	ch.model	= "towngirl7";
	ch.sex = "woman";
	ch.location	= "QC_brothel";
	ch.location.group = "merchant";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "barwench_dialog.c";
	ch.greeting = "Gr_Woman_English Citizen";
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
	ch.work = "";
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");

	AddGameCharacter(n, ch);

		// WENCH 4
	ch.old.name = "Celia";
	ch.old.lastname = "Hilder";
	ch.name = TranslateString("", "Celia");
	ch.lastname = TranslateString("", "Hilder");
	ch.id		= "wench4";
	ch.model	= "towngirl4";
	ch.sound_type = "female_citizen";
	ch.sex = "woman";
	ch.location	= "QC_brothel";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "wench_dialog.c";
	ch.greeting = "Gr_Wench";//MAXIMUS
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
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 6.0, 24.0);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");

	AddGameCharacter(n, ch);

		// WENCH 4 (upstairs)
	ch.old.name = "Celia";
	ch.old.lastname = "Hilder";
	ch.name = TranslateString("", "Celia");
	ch.lastname = TranslateString("", "Hilder");
	ch.id		= "wench4";
	ch.model	= "towngirl4";
	ch.sound_type = "female_citizen";
	ch.sex = "woman";
	ch.location	= "QC_brothel_upstairs";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "wenched_dialog.c";
	ch.greeting = "Gr_Wench";//MAXIMUS
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
	ch.quest.sex = 0;
	ch.sex.time = 0;
//	LAi_SetStayType(ch);
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 6.0);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");

	AddGameCharacter(n, ch);

		// WENCH 3 (upstairs)
	ch.old.name = "Amelia";
	ch.old.lastname = "Frere";
	ch.name = TranslateString("", "Amelia");
	ch.lastname = TranslateString("", "Frere");
	ch.id		= "wench3";
	ch.model	= "towngirl5";
	ch.sound_type = "female_citizen";
	ch.sex = "woman";
	ch.location	= "QC_brothel_upstairs";
	ch.location.group = "goto";
	ch.location.locator = "goto7";
	ch.Dialog.Filename = "wenched_dialog.c";
	ch.greeting = "Gr_Wench";//MAXIMUS
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
	ch.quest.sex = 0;
	ch.sex.time = 0;
//	LAi_SetStayType(ch);
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 6.0, 12.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");

	AddGameCharacter(n, ch);

		// WENCH 1 (upstairs)
	ch.old.name = "Natalia";
	ch.old.lastname = "Decoteau";
	ch.name = TranslateString("", "Natalia");
	ch.lastname = TranslateString("", "Decoteau");
	ch.id		= "wench1";
	ch.model	= "towngirl2";
	ch.sound_type = "female_citizen";
	ch.sex = "woman";
	ch.location	= "QC_brothel_upstairs";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
	ch.Dialog.Filename = "wenched_dialog.c";
	ch.greeting = "Gr_Wench";//MAXIMUS
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
	ch.quest.sex = 0;
	ch.sex.time = 0;
//	LAi_SetStayType(ch);
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 12.0, 18.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");

	AddGameCharacter(n, ch);

		// WENCH 2 (upstairs)
	ch.old.name = "Serena";
	ch.old.lastname = "Tisserand";
	ch.name = TranslateString("", "Serena");
	ch.lastname = TranslateString("", "Tisserand");
	ch.id		= "wench2";
	ch.model	= "towngirl6";
	ch.sound_type = "female_citizen";
	ch.sex = "woman";
	ch.location	= "QC_brothel_upstairs";
	ch.location.group = "goto";
	ch.location.locator = "goto2";
	ch.Dialog.Filename = "wenched_dialog.c";
	ch.greeting = "Gr_Wench";//MAXIMUS
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
	ch.quest.sex = 0;
	ch.sex.time = 0;
//	LAi_SetStayType(ch);
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 18.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");

	AddGameCharacter(n, ch);

//-----------END BROTHEL SECTION-------------------

//-----------Thomas the Terror CHARLESTOWN mod--------------
		//  Soldier
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "soldier_02";
	ch.model	= 1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Charlestown_port";
	ch.location.group = "goto";
	ch.location.locator = "goto12";
	ch.Dialog.Filename = "Redmond Soldier_dialog.c";
	ch.greeting = "Gr_Redmond Soldier";
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
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	AddGameCharacter(n, ch);

		// Soldier
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "soldier_01";
	ch.model	= 2; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Charlestown_port";
	ch.location.group = "goto";
	ch.location.locator = "goto2";
	ch.Dialog.Filename = "Redmond Soldier_dialog.c";
	ch.greeting = "Gr_Redmond Soldier";
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
	ch.money = "10";
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	AddGameCharacter(n, ch);

		//  Soldier
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "soldier_04";
	ch.model	= 6; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Charlestown_port";
	ch.location.group = "goto";
	ch.location.locator = "goto23";
	ch.Dialog.Filename = "Redmond Soldier_dialog.c";
	ch.greeting = "Gr_Redmond Soldier";
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
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	AddGameCharacter(n, ch);
	
			//Patrol
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Nev_patrol_1";
	ch.model	= 5; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Charlestown_Port";
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
	LAi_SetLoginTime(ch, 22.0, 5.98333);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.greeting = "Gr_Patrol";
	AddGameCharacter(n, ch);

			//Patrol
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Nev_patrol_2";
	ch.model	= 4; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Charlestown_Port";
	ch.location.group = "goto";
	ch.location.locator = "goto22";
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
	LAi_SetLoginTime(ch, 22.0, 5.98333);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.greeting = "Gr_Patrol";
	AddGameCharacter(n, ch);
	
			//Patrol
	ch.old.name = "Officer";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Officer");
	ch.lastname = "";
	ch.id		= "Nev_patrol_4";
	ch.model	= 0; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Charlestown_Port";
	ch.location.group = "goto";
	ch.location.locator = "goto7";
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
	LAi_SetLoginTime(ch, 6.0, 21.98333);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.greeting = "Gr_Patrol";
	AddGameCharacter(n, ch);
	
			// Jean Filaut (верфь)
	ch.old.name = "Thomas";
	ch.old.lastname = "Modiford";
	ch.name = TranslateString("", "Thomas");
	ch.lastname = TranslateString("", "Modiford");
	ch.id		= "Thomas Modiford";
	ch.model	= Nations[ENGLAND].fantomModel.m0; // PB
	ch.sex = "man";
	ch.location	= "Charlestown_residence";
	ch.location.group = "sit";
	ch.location.locator = "sit3";
	ch.Dialog.Filename = "Thomas Modiford_dialog.c"; // KK
	ch.Dialog.Filename.GroupDialog = "governor.c";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "53";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "4";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "3";
	ch.skill.Sneak = "1";
	ch.money = "10";
	ch.quest.meeting = "0";
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	ch.greeting = "Gr_Robert Christopher Silehard";
	AddGameCharacter(n, ch);
//-----------End CHARLESTOWN mod-------------------------------

//-----------SJG CHARLESTOWN mod-------------------------------
			//Soldier на входе в город
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Nav_soldier_1";
	ch.model	= 2; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	ch.nation = ENGLAND;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Charlestown_port";
	ch.location.group = "goto";
	ch.location.locator = "goto27";
	ch.Dialog.Filename = "Redmond Soldier_dialog.c";
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
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.greeting = "Gr_Redmond Soldier";
	AddGameCharacter(n, ch);

			//Soldier на входе в город
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Nav_soldier_2";
	ch.model	= 3; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Charlestown_port";
	ch.location.group = "goto";
	ch.location.locator = "goto28";
	ch.Dialog.Filename = "redmond soldier_dialog.c";
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
	ch.money = "10";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.greeting = "Gr_Redmond Soldier";
	AddGameCharacter(n, ch);
//--------END SJG CHARLESTOWN MOD-----------------------------

//--------Grey Roger Charlestown Church mod-------------------
			//Father Samuel
	ch.old.name = "Father";
	ch.old.lastname = "Samuel";
	ch.name = TranslateString("", "Father");
	ch.lastname = TranslateString("", "Samuel");
	ch.id		= "Father Samuel";
	ch.model	= "monk";
	ch.sound_type = "priest";
	ch.sex = "man";
	ch.nation = ENGLAND;
	ch.location	= "Charlestown_church";
	ch.location.group = "barmen";
	ch.location.locator = "bar1";
	ch.Dialog.Filename = "Father Abbott_dialog.c";
	ch.Dialog.Filename.group = "church.c";
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
	LAi_SetPriestType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	ch.greeting = "Gr_Father Samuel";
	AddGameCharacter(n, ch);
//--------End Grey Roger Charlestown Church mod---------------

			// Clint Eastwood: Shotgun Easter Egg
	ch.old.name = "Clint";
	ch.old.lastname = "Eastwood";
	ch.name = TranslateString("", "Clint");
	ch.lastname = TranslateString("", "Eastwood");
	ch.id		= "Clint Eastwood";
	ch.model	= "wf1blaze";
	ch.sex = "man";
	ch.location	= "QC_Pirate_house";
	ch.location.group = "goto";
	ch.location.locator = "citizen02";
	ch.Dialog.Filename = "Clint Eastwood_dialog.c";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "bladeX4"); // Fists
	ch.equip.blade = "bladeX4";
	if(iRealismMode == 0 && CLINT_SHOTGUN ==1)
	{
		GiveItem2Character(ch, "pistol10"); // Shotgun
		ch.equip.gun = "pistol10";
		//JRH ammo mod -->
		if (ENABLE_AMMOMOD) {	// LDH change
			TakenItems(ch, "gunpowder", 6);
			TakenItems(ch, "pistolgrapes", 6);
		}
		//JRH ammo mod <--
	}
	else
	{
		if(GetCurrentPeriod() == PERIOD_NAPOLEONIC)
		{
			GiveItem2Character(ch, "pistolcollier"); // Collier revolver
			ch.equip.gun = "pistolcollier";
		}
		else
		{
			GiveItem2Character(ch, "pistol25"); // Brace of 4 Horse Pistols
			ch.equip.gun = "pistol25";
		}
		//JRH ammo mod -->
		if (ENABLE_AMMOMOD) {	// LDH change
			TakenItems(ch, "gunpowder", 6);
			TakenItems(ch, "pistolbullets", 6);
		}
	}
	ch.rank 	= 100;
	ch.HPBonus = 500;
	ch.reputation = "53";
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
	ch.perks.list.Gunman = true;
	ch.perks.list.ProfessionalGunman = true;
	ch.perks.list.Rush = true;
	ch.perks.list.Toughness = true;
	ch.money = "1";
	ch.quest.meeting = "0";
	ch.greeting = "Gr_Robert Christopher Silehard";
	LAi_SetCivilianPatrolType(ch); // KK
	LAi_NoRebirthEnable(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	AddGameCharacter(n, ch);

// --> RobC/Alan_Smithee Blacksmith mod
if (ENABLE_WEAPONSMOD)
{
	//  Blacksmith
	ch.old.name = "Arne";
	ch.old.lastname = "Saknussem";
	ch.name = TranslateString("", "Arne");
	ch.lastname = TranslateString("", "Saknussem");
	ch.id		= "QC_blacksmith";
	ch.model	= "blacksmith6";
	ch.sound_type = "male_citizen";
	ch.sex = "man";
	ch.location	= "QC_Blacksmith";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Blacksmith5_dialog.c";
	ch.Dialog.Filename.Groupdialog = "Blacksmith_fetch.c";
	ch.greeting = "Gr_zaid murro";
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
	LAi_SetStayType(ch); // LDH: Keep him from walking around all the time
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	AddGameCharacter(n, ch);

// Charlestown Citizens

	ch.old.name = "Fred";
	ch.old.lastname = "Goyle";
	ch.name = TranslateString("", "Fred");
	ch.lastname = TranslateString("", "Goyle");
	ch.id		= "Fred Goyle";
	ch.model	= "man3";
	ch.sound_type = "male_citizen";
	ch.sex = "man";
	ch.nation = ENGLAND;
	ch.location	= "Charlestown_port";
	ch.location.group = "goto";
	ch.location.locator = "goto15";
	ch.Dialog.Filename = "Charlestown_citizen_dialog.c";
	ch.greeting = "Gr_redmond Citizen";
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
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);

	ch.old.name = "Bob";
	ch.old.lastname = "Stone";
	ch.name = TranslateString("", "Bob");
	ch.lastname = TranslateString("", "Stone");
	ch.id		= "Bob Stone";
	ch.model	= "bocman";
	ch.sound_type = "male_citizen";
	ch.sex = "man";
	ch.nation = ENGLAND;
	ch.location	= "Charlestown_port";
	ch.location.group = "goto";
	ch.location.locator = "goto25";
	ch.Dialog.Filename = "Charlestown_citizen_dialog.c";
	ch.greeting = "Gr_redmond Citizen";
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
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);

	ch.old.name = "Luna";
	ch.old.lastname = "Grange";
	ch.name = TranslateString("", "Luna");
	ch.lastname = TranslateString("", "Grange");
	ch.id		= "Luna Grange";
	ch.model	= "towngirl3";
	ch.sound_type = "female_citizen";
	ch.sex = "woman";
	ch.nation = ENGLAND;
	ch.location	= "Charlestown_port";
	ch.location.group = "goto";
	ch.location.locator = "goto10";
	ch.Dialog.Filename = "Charlestown_citizen_dialog.c";
	ch.greeting = "Gr_woman_england Citizen";
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
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);

}
// <-- RobC/Alan_Smithee Blacksmith mod
}
