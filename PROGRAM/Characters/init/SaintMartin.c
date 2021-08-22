// ccc Mar06 StMartin  -----------------------

void CreateSaintMartinCharacters(ref n)
{
	object chobj;
	ref ch;

	makeref(ch, chobj);

			// governor
	ch.old.name = "Arendt";
	ch.old.lastname = "Dickman";
	ch.name = TranslateString("","Arendt");
	ch.lastname = TranslateString("","Dickman");
	ch.id		= "Arendt Dickman";
	ch.model = "Huber_Hol2_17"; // Thomas the Terror
	ch.sex = "man";
	ch.location	= "Philipsburg_residence";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Arendt Dickman_dialog.c";
	ch.Dialog.Filename.GroupDialog = "governor.c";
	ch.nation = HOLLAND;
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
	ch.quest.meeting = "0";
	LAi_RemoveLoginTime(ch);
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "DOUWESEN_CITIZENS");
	ch.greeting = "Gr_Reynard Grueneveldt";
	AddGameCharacter(n, ch);
// <-- KK


// Dutch soldiers -----------------------------------------------------------


	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "PhilipsburgPatrol1";
	ch.model	= 5; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, true);
	ch.sex = "man";
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
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	ch.location	= "Philipsburg_port";
	ch.location.group = "goto";
	ch.location.locator = "goto4";
	ch.Dialog.Filename = "Philipsburg_Patrol.c";
	ch.nation = HOLLAND;
	ch.rank 	= 5;
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
	LAi_SetHP(ch, 305.0, 305.0);
	LAi_group_MoveCharacter(ch, "DOUWESEN_SOLDIERS");
	ch.greeting = "Gr_Douwesen Soldier";
	AddGameCharacter(n, ch);


	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "PhilipsburgPatrol2";
	ch.model	= 0; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, true);
	ch.sex = "man";
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
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	ch.location	= "Philipsburg_town";
	ch.location.group = "goto";
	ch.location.locator = "character4";
	ch.Dialog.Filename = "Philipsburg_patrol.c";
	ch.nation = HOLLAND;
	ch.rank 	= 5;
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
	LAi_SetHP(ch, 305.0, 305.0);
	LAi_group_MoveCharacter(ch, "DOUWESEN_SOLDIERS");
	ch.greeting = "Gr_Douwesen Soldier";
	AddGameCharacter(n, ch);

// soldiers at Philipsburg_exit


	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "PhilipsburgSoldier1";
	ch.model	= 5; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnationEx(ch, true, true, "camdetector");
	ch.sex = "man";
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
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	ch.location	= "Philipsburg_exit";
	ch.location.group = "goto";
	ch.location.locator = "citizen04";
	ch.Dialog.Filename = "Philipsburg_soldier.c";
	ch.nation = HOLLAND;
	ch.rank 	= 5;
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
	LAi_SetHP(ch, 305.0, 305.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_PLAYER);
	ch.greeting = "Gr_Douwesen Soldier";
	AddGameCharacter(n, ch);


	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "PhilipsburgSoldier2";
	ch.model	= 0; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnationEx(ch, true, true, "camdetector");
	ch.sex = "man";
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

	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	ch.location	= "Philipsburg_exit";
	ch.location.group = "goto";
	ch.location.locator = "citizen05";
	ch.Dialog.Filename = "Philipsburg_soldier.c";
	ch.nation = HOLLAND;
	ch.rank 	= 5;
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
	LAi_SetHP(ch, 305.0, 305.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_PLAYER);
	ch.greeting = "Gr_Douwesen Soldier";
	AddGameCharacter(n, ch);


	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "PhilipsburgSoldier1";
	ch.model	= 6; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnationEx(ch, true, true, "camdetector");
	ch.sex = "man";
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

	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	ch.location	= "Philipsburg_exit";
	ch.location.group = "officers";
	ch.location.locator = "reload2_3";
	ch.Dialog.Filename = "Philipsburg_soldier.c";
	ch.nation = HOLLAND;
	ch.rank 	= 5;
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
	LAi_SetHP(ch, 305.0, 305.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_PLAYER);
	ch.greeting = "Gr_Douwesen Soldier";
	AddGameCharacter(n, ch);

				// governor
	ch.old.name = "Philippe";
	ch.old.lastname = "de Rivarol";
	ch.name = TranslateString("","Philippe");
	ch.lastname = TranslateString("","de Rivarol");
	ch.id		= "Philippe de Rivarol";
	ch.model = "Nobleman2";
	ch.sex = "man";
	ch.location	= "Marigot_mansion_hall";
	ch.location.group = "goto";
	ch.location.locator = "goto8";
	ch.Dialog.Filename = "Philippe de Rivarol_dialog.c";
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
	ch.quest.meeting = "0";
	LAi_RemoveLoginTime(ch);
	LAi_SetHuberStayType(ch);
	LAi_SetStayHuberPointWindow(ch, "goto", "goto10");
	LAi_SetStayHuberPointMap(ch, "goto", "goto9");
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	ch.greeting = "Gr_joseph claude le moigne";
	AddGameCharacter(n, ch);
// <-- KK

// French monster-soldiers from Marigot ------------------------------------


	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "MarigotSoldier11";
	ch.model	= 0; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	LAi_CharacterReincarnationEx(ch, true, true, "monsters");
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

	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	ch.location	= "Philipsburg_exit";
	ch.location.group = "goto";
	ch.location.locator = "citizen02";
	ch.Dialog.Filename = "Marigot_Soldier.c";
	ch.nation = FRANCE;
	ch.rank 	= 5;
	ch.reputation = "50";
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
	ch.quest.meeting = "0";
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 305.0, 305.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_MONSTERS);
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);


	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "MarigotSoldier12";
	ch.model	= 2; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	LAi_CharacterReincarnationEx(ch, true, true, "monsters");
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
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	ch.location	= "Philipsburg_exit";
	ch.location.group = "goto";
	ch.location.locator = "locator8";
	ch.Dialog.Filename = "Marigot_Soldier.c";
	ch.nation = FRANCE;
	ch.rank 	= 5;
	ch.reputation = "50";
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
	ch.quest.meeting = "0";
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 305.0, 305.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_MONSTERS);
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);


	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "MarigotSoldier13";
	ch.model	= 3; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	LAi_CharacterReincarnationEx(ch, true, true, "monsters");
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
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	ch.location	= "Philipsburg_exit";
	ch.location.group = "goto";
	ch.location.locator = "locator8";
	ch.Dialog.Filename = "Marigot_Soldier.c";
	ch.nation = FRANCE;
	ch.rank 	= 5;
	ch.reputation = "50";
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
	ch.quest.meeting = "0";
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 305.0, 305.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_MONSTERS);
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);


	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "MarigotSoldier14";
	ch.model	= 4; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	LAi_CharacterReincarnationEx(ch, true, true, "monsters");
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
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	ch.location	= "Philipsburg_exit";
	ch.location.group = "goto";
	ch.location.locator = "locator9";
	ch.Dialog.Filename = "Marigot_Soldier.c";
	ch.nation = FRANCE;
	ch.rank 	= 5;
	ch.reputation = "50";
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
	ch.quest.meeting = "0";
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 305.0, 305.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_MONSTERS);
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);


	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "MarigotSoldier15";
	ch.model	= 1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	LAi_CharacterReincarnationEx(ch, true, true, "monsters");
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
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	ch.location	= "Philipsburg_exit";
	ch.location.group = "goto";
	ch.location.locator = "locator9";
	ch.Dialog.Filename = "Marigot_Soldier.c";
	ch.nation = FRANCE;
	ch.rank 	= 5;
	ch.reputation = "50";
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
	ch.quest.meeting = "0";
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 305.0, 305.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_MONSTERS);
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);


//  Marigot townguards -------------------------------------


	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "MarigotPatrol1";
	ch.model	= 5; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, true);
	ch.sex = "man";
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
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	ch.location	= "Marigot_port";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Marigot_patrol.c";
	ch.nation = FRANCE;
	ch.rank 	= 5;
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
	LAi_SetHP(ch, 305.0, 305.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);


	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "MarigotPatrol2";
	ch.model	= 6; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, true);
	ch.sex = "man";
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
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	ch.location	= "Marigot_port";
	ch.location.group = "goto";
	ch.location.locator = "goto12";
	ch.Dialog.Filename = "Marigot_patrol.c";
	ch.nation = FRANCE;
	ch.rank 	= 5;
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
	LAi_SetHP(ch, 305.0, 305.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);


	ch.old.name = "";
	ch.old.lastname = "Officer";
	ch.name 	= "";
	ch.lastname 	= TranslateString("","Officer");
	ch.id		= "MarigotPatrol7";
	ch.model	= 0; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, true);
	ch.sex = "man";
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
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	ch.location	= "Marigot_Town_01";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Marigot_patrol.c";
	ch.nation = FRANCE;
	ch.rank 	= 5;
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
	LAi_SetHP(ch, 305.0, 305.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);


	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "MarigotPatrol8";
	ch.model	= 6; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, true);
	ch.sex = "man";
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
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	ch.location	= "Marigot_Town_02";
	ch.location.group = "goto";
	ch.location.locator = "goto2";
	ch.Dialog.Filename = "Marigot_patrol.c";
	ch.nation = FRANCE;
	ch.rank 	= 5;
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
	LAi_SetHP(ch, 305.0, 305.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);
	
// Marigot Citizens
    ch.old.name = "Aubert";
    ch.old.lastname = "Boogard";
    ch.name     = TranslateString("","Aubert");
    ch.lastname     = TranslateString("","Boogard");
    ch.id        = "Aubert Boogard";
    ch.model    = "man2";
    ch.sex = "man";
    ch.sound_type = "seaman";
    ch.location    = "Marigot_port";
    ch.location.group = "goto";
    ch.location.locator = "goto1";
    ch.Dialog.Filename = "Marigot citizen_dialog.c";
    ch.greeting = "Gr_falaise de fleur citizen";
    ch.nation = FRANCE;
    ch.rank     = 1;
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
    LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
    AddGameCharacter(n, ch);	
	
	ch.old.name = "Pierre";
    ch.old.lastname = "Dunere";
    ch.name     = TranslateString("","Pierre");
    ch.lastname     = TranslateString("","Dunere");
    ch.id        = "Pierre Dunere";
    ch.model    = "sailor2";
    ch.sex = "man";
    ch.sound_type = "seaman";
    ch.location    = "Marigot_port";
    ch.location.group = "goto";
    ch.location.locator = "goto10";
    ch.Dialog.Filename = "Marigot citizen_dialog.c";
    ch.greeting = "Gr_falaise de fleur citizen";
    ch.nation = FRANCE;
    ch.rank     = 1;
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
    LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
    AddGameCharacter(n, ch);
	
	ch.old.name = "Juliette";
    ch.old.lastname = "Truffel";
    ch.name     = TranslateString("","Juliette");
    ch.lastname     = TranslateString("","Truffel");
    ch.id        = "Juliette Truffel";
    ch.model    = "caroline_k";
    ch.sex = "woman";
    ch.sound_type = "female_citizen";
    ch.location    = "Marigot_town_01";
    ch.location.group = "goto";
    ch.location.locator = "goto31";
    ch.Dialog.Filename = "Marigot citizen_dialog.c";
    ch.greeting = "Gr_Woman_French citizen";
    ch.nation = FRANCE;
    ch.rank     = 1;
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
    LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
    AddGameCharacter(n, ch);
	
	ch.old.name = "Fulbert";
    ch.old.lastname = "Trebluf";
    ch.name     = TranslateString("","Fulbert");
    ch.lastname     = TranslateString("","Trebluf");
    ch.id        = "Fulbert Trebluf";
    ch.model    = "man7";
    ch.sex = "man";
    ch.sound_type = "seaman";
    ch.location    = "Marigot_town_02";
    ch.location.group = "goto";
    ch.location.locator = "goto23";
    ch.Dialog.Filename = "Marigot citizen_dialog.c";
    ch.greeting = "Gr_falaise de fleur citizen";
    ch.nation = FRANCE;
    ch.rank     = 1;
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
    LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
    AddGameCharacter(n, ch);
	
// soldiers at Marigot_exit -------------------------------------


	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "MarigotSoldier1";
	ch.model	= 5; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnationEx(ch, true, true, "camdetector");
	ch.sex = "man";
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
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	ch.location	= "Marigot_exit";
	ch.location.group = "goto";
	ch.location.locator = "goto7";
	ch.Dialog.Filename = "Marigot_soldier.c";
	ch.nation = FRANCE;
	ch.rank 	= 5;
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
	LAi_SetHP(ch, 305.0, 305.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_PLAYER);
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);


	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "MarigotSoldier2";
	ch.model	= 0; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnationEx(ch, true, true, "camdetector");
	ch.sex = "man";
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
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	ch.location	= "Marigot_exit";
	ch.location.group = "goto";
	ch.location.locator = "goto6";
	ch.Dialog.Filename = "Marigot_soldier.c";
	ch.nation = FRANCE;
	ch.rank 	= 5;
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
	LAi_SetHP(ch, 305.0, 305.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_PLAYER);
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);


	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "MarigotSoldier1";
	ch.model	= 6; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnationEx(ch, true, true, "camdetector");
	ch.sex = "man";
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
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	ch.location	= "Marigot_exit";
	ch.location.group = "officers";
	ch.location.locator = "reload2_3";
	ch.Dialog.Filename = "Marigot_soldier.c";
	ch.nation = FRANCE;
	ch.rank 	= 5;
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
	LAi_SetHP(ch, 305.0, 305.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_PLAYER);
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);


	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "PhilipsburgSoldier11";
	ch.model	= 0; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	LAi_CharacterReincarnationEx(ch, true, true, "monsters");
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
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	ch.location	= "Marigot_exit";
	ch.location.group = "goto";
	ch.location.locator = "goto2";
	ch.Dialog.Filename = "Philipsburg_Soldier.c";
	ch.nation = HOLLAND;
	ch.rank 	= 5;
	ch.reputation = "50";
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
	ch.quest.meeting = "0";
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 305.0, 305.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_MONSTERS);
	AddGameCharacter(n, ch);


	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "PhilipsburgSoldier12";
	ch.model	= 2; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	LAi_CharacterReincarnationEx(ch, true, true, "monsters");
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
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	ch.location	= "Marigot_exit";
	ch.location.group = "goto";
	ch.location.locator = "goto2";
	ch.Dialog.Filename = "Philipsburg_Soldier.c";
	ch.nation = HOLLAND;
	ch.rank 	= 5;
	ch.reputation = "50";
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
	ch.quest.meeting = "0";
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 305.0, 305.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_MONSTERS);
	AddGameCharacter(n, ch);


	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "PhilipsburgSoldier13";
	ch.model	= 3; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	LAi_CharacterReincarnationEx(ch, true, true, "monsters");
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
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	ch.location	= "Marigot_exit";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "Philipsburg_Soldier.c";
	ch.nation = HOLLAND;
	ch.rank 	= 5;
	ch.reputation = "50";
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
	ch.quest.meeting = "0";
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 305.0, 305.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_MONSTERS);
	AddGameCharacter(n, ch);


	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "PhilipsburgSoldier14";
	ch.model	= 4; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	LAi_CharacterReincarnationEx(ch, true, true, "monsters");
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
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	ch.location	= "Marigot_exit";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "Philipsburg_Soldier.c";
	ch.nation = HOLLAND;
	ch.rank 	= 5;
	ch.reputation = "50";
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
	ch.quest.meeting = "0";
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 305.0, 305.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_MONSTERS);
	AddGameCharacter(n, ch);

	ch.old.name = "";
	ch.old.lastname = "";
	ch.name 	= "";
	ch.lastname 	= "";
	ch.id		= "PhilipsburgSoldier15";
	ch.model	= 1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	LAi_CharacterReincarnationEx(ch, true, true, "monsters");
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
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	ch.location	= "Marigot_exit";
	ch.location.group = "goto";
	ch.location.locator = "goto4";
	ch.Dialog.Filename = "Philipsburg_Soldier.c";
	ch.nation = HOLLAND;
	ch.rank 	= 5;
	ch.reputation = "50";
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
	ch.quest.meeting = "0";
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 305.0, 305.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_MONSTERS);
	AddGameCharacter(n, ch);
	
	//Philipsburg citizens
	ch.old.name = "Adam";
    ch.old.lastname = "Groot";
    ch.name     = TranslateString("","Adam");
    ch.lastname     = TranslateString("","Groot");
    ch.id        = "Adam Groot";
    ch.model    = "man10";
    ch.sex = "man";
    ch.sound_type = "seaman";
    ch.location    = "Philipsburg_port";
    ch.location.group = "goto";
    ch.location.locator = "goto19";
    ch.Dialog.Filename = "Philipsburg citizen_dialog.c";
    ch.greeting = "Gr_douwesen citizen";
    ch.nation = HOLLAND;
    ch.rank     = 1;
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
    LAi_group_MoveCharacter(ch, "HOLLAND_CITIZENS");
    AddGameCharacter(n, ch);
	
	ch.old.name = "Hubert";
    ch.old.lastname = "Decker";
    ch.name     = TranslateString("","Hubert");
    ch.lastname     = TranslateString("","Decker");
    ch.id        = "Hubert Decker";
    ch.model    = "fatman";
    ch.sex = "man";
    ch.sound_type = "seaman";
    ch.location    = "Philipsburg_port";
    ch.location.group = "goto";
    ch.location.locator = "goto9";
    ch.Dialog.Filename = "Philipsburg citizen_dialog.c";
    ch.greeting = "Gr_douwesen citizen";
    ch.nation = HOLLAND;
    ch.rank     = 1;
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
    LAi_group_MoveCharacter(ch, "HOLLAND_CITIZENS");
    AddGameCharacter(n, ch);
	
	ch.old.name = "Hanna";
    ch.old.lastname = "Hoff";
    ch.name     = TranslateString("","Hanna");
    ch.lastname     = TranslateString("","Hoff");
    ch.id        = "Hanna Hoff";
    ch.model    = "towngirl2";
    ch.sex = "woman";
    ch.sound_type = "female_citizen";
    ch.location    = "Philipsburg_town";
    ch.location.group = "goto";
    ch.location.locator = "character3";
    ch.Dialog.Filename = "Philipsburg citizen_dialog.c";
    ch.greeting = "Gr_Woman_Dutch Citizen";
    ch.nation = HOLLAND;
    ch.rank     = 1;
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
    LAi_group_MoveCharacter(ch, "HOLLAND_CITIZENS");
    AddGameCharacter(n, ch);
	
	ch.old.name = "Hannes";
    ch.old.lastname = "Jansen";
    ch.name     = TranslateString("","Hannes");
    ch.lastname     = TranslateString("","Jansen");
    ch.id        = "Hannes Jansen";
    ch.model    = "man8";
    ch.sex = "man";
    ch.sound_type = "seaman";
    ch.location    = "Philipsburg_town";
    ch.location.group = "goto";
    ch.location.locator = "goto3";
    ch.Dialog.Filename = "Philipsburg citizen_dialog.c";
    ch.greeting = "Gr_douwesen citizen";
    ch.nation = HOLLAND;
    ch.rank     = 1;
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
    LAi_group_MoveCharacter(ch, "HOLLAND_CITIZENS");
    AddGameCharacter(n, ch);
	
	ch.old.name = "Jana";
    ch.old.lastname = "Smit";
    ch.name     = TranslateString("","Jana");
    ch.lastname     = TranslateString("","Smit");
    ch.id        = "Jana Smit";
    ch.model    = "towngirl4";
    ch.sex = "woman";
    ch.sound_type = "female_citizen";
    ch.location    = "Philipsburg_town_02";
    ch.location.group = "goto";
    ch.location.locator = "goto3";
    ch.Dialog.Filename = "Philipsburg citizen_dialog.c";
    ch.greeting = "Gr_Woman_Dutch Citizen";
    ch.nation = HOLLAND;
    ch.rank     = 1;
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
    LAi_group_MoveCharacter(ch, "HOLLAND_CITIZENS");
    AddGameCharacter(n, ch);
}
