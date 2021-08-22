void CreateQuebradasCostillasCharacters(ref n)
{
	object chobj;
	ref ch;

	makeref(ch, chobj);

	// Isenbrandt Jurcksen -- capitan
	ch.old.name	= "Skull";
	ch.old.lastname = "";
	ch.name		= TranslateString("", "Skull");
	ch.lastname	= "";
	ch.id		= "Isenbrandt Jurcksen";
	ch.model	= "Skull";
	ch.sex		= "man";
	ch.location	= "QC_residence";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Skull_dialog.c";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "pistol1a");
	ch.equip.gun = "pistol1a";
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

	ch.old.name = "Sixto";
	ch.old.lastname = "Costa";
	ch.name = TranslateString("","Sixto");
	ch.lastname = TranslateString("","Costa");
	ch.id		= "Sixto Costa";
	ch.model	= "rabWhite";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "QC_port";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "Sixto Costa_dialog.c";
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
	LAi_SetPoorType(ch);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "QC_SOLDIERS");
	ch.greeting = "Gr_QC Citizen";
	AddGameCharacter(n, ch);

	ch.old.name = "Rico";
	ch.old.lastname = "Diaz";
	ch.name = TranslateString("","Rico");
	ch.lastname = TranslateString("","Diaz");
	ch.id		= "Rico Diaz";
	ch.model	= "diller";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Rico Diaz_dialog.c";
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
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "QC_SOLDIERS");
	ch.greeting = "Gr_Rico Diaz";
	AddGameCharacter(n, ch);
}
