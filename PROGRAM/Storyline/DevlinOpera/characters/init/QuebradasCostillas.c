void CreateQuebradasCostillasCharacters(ref n)
{
	object chobj;
	ref ch;

	makeref(ch, chobj);

	// Isenbrandt Jurcksen -- capitan
	ch.old.name = "Skull";
	ch.old.lastname = "";
	ch.name = TranslateString("","Skull");
	ch.lastname = TranslateString("","");
	ch.id		= "Isenbrandt Jurcksen";
	ch.model	= "Skull";
	ch.sex = "man";
	ch.location	= "QC_residence";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Skull_dialog.c";
	ch.nation = PIRATE;
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
}
