// ccc Feb06 for Antigua -----------------------

void CreateAntiguaCharacters(ref n)
{
	object chobj;
	ref ch;

	makeref(ch, chobj);

	ch.old.name = "Portadmiral";
	ch.old.lastname = "Lord Barham";
	ch.name 	= TranslateString("","Portadmiral");
	ch.lastname = TranslateString("","Lord Barham");
	ch.id		= "Antigua_Portadmiral";
	ch.model	= "brtadm1_18"; // Thomas the Terror
	ch.sex = "man";
	ch.nation = ENGLAND;
	ch.location	= "Antigua_mansion_study";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "Antigua_Portadmiral.c";
	ch.rank 	= 10;
	ch.reputation = "None";
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
	ch.money = "10000";
	GiveItem2Character(ch, "blade13");
	ch.equip.blade = "blade13";
	LAi_SetCitizenType(ch);
	LAi_SetHP(ch, 200.0, 200.0);
	AddGameCharacter(n, ch);


	ch.old.name = "Regulating";
	ch.old.lastname = "Captain";
	ch.name 	= TranslateString("","Regulating");
	ch.lastname = TranslateString("","RCaptain");
	ch.id		= "Antigua_Regulating";
	ch.model	= "brtadm2_18"; // Thomas the Terror
	ch.sex = "man";
	ch.nation = ENGLAND;
	ch.location	= "Antigua_Residence";
	ch.location.group = "goto";
	ch.location.locator = "goto8";
	ch.Dialog.Filename = "Antigua_Regulating.c";
	ch.rank 	= 10;
	ch.reputation = "None";
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
	ch.money = "10000";
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	LAi_SetCitizenType(ch);
	LAi_SetHP(ch, 200.0, 200.0);
	AddGameCharacter(n, ch);

// SJG For Hornblower5/20/2009 --->
			//Soldier на входе в город
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Ant_soldier_1";
	ch.model	= 3; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	ch.nation = ENGLAND;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Antigua_port";
	ch.location.group = "goto";
	ch.location.locator = "goto26";
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
	ch.id		= "Ant_soldier_2";
	ch.model	= 2; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	ch.nation = ENGLAND;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Antigua_port";
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
	ch.id		= "Ant_soldier_3";
	ch.model	= 4; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	ch.nation = ENGLAND;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Antigua_port";
	ch.location.group = "goto";
	ch.location.locator = "goto28";
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
	ch.id		= "Ant_soldier_4";
	ch.model	= 5; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	ch.nation = ENGLAND;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Antigua_port";
	ch.location.group = "goto";
	ch.location.locator = "goto29";
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
	ch.id		= "Ant_soldier_5";
	ch.model	= 4; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	ch.nation = ENGLAND;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Antigua_port";
	ch.location.group = "goto";
	ch.location.locator = "goto30";
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
	ch.id		= "Ant_soldier_6";
	ch.model	= 5; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	ch.nation = ENGLAND;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Antigua_port";
	ch.location.group = "goto";
	ch.location.locator = "goto31";
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

// <---SJG

}
