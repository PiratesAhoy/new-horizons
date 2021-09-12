void CreateTempQuestCharacters(ref n)
{

	object chobj;
	ref ch;
	makeref(ch, chobj);

	ch.old.name = "Captain";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Captain");
	ch.lastname = "";
	ch.id		= "Quest_frigate_captain";
	ch.nation	= FRANCE;
	ch.model	= "fra_cpt_18";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "Quest_ships";
	ch.location.locator = "quest_ship_12";
	ch.Dialog.Filename = "falaise de fleur soldier_dialog.c";
	ch.rank 	= 4;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "1000";
	ch.Ship.Name = "Téméraire";
	ch.Ship.Type = "FR_Superbe";
	ch.Ship.Stopped = true;
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Simon";
	ch.old.lastname = "Blunden";
	ch.name = TranslateString("", "Simon");
	ch.lastname = TranslateString("", "Blunden");
	ch.id		= "Eng Captain Near FdF";
	ch.model = "corsair1_2";
	ch.sex = "man";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.Ship.AI.GroupName = "England_Captain_Near_FdF";
	ch.Ship.AI.Task = "attack"; // KK was: "runaway"
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none"
	ch.location.group = "Quest_ships";
	ch.location.locator = "quest_ship_12";
	ch.Dialog.Filename = "falaise de fleur soldier_dialog.c";
	ch.nation = PIRATE;
	ch.Ship.Name = "Fast Death";
	ch.Ship.Type = 	"PiratCorvette";
	ch.Ship.Stopped = true;
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS16;
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

// French Captain	
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "French Captain";
	ch.nation	= FRANCE;
	ch.model	= "fra_cpt2_18";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;			
	ch.location	= "none";
	ch.location.group = "Quest_ships";
	ch.location.locator = "quest_ship_12";
	ch.Dialog.Filename = " ";
	ch.rank 	= 4;
	ch.reputation = "70";
	ch.experience = "1";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "4";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
	ch.Ship.Name = "Téméraire";
	ch.Ship.Type = "FR_Superbe";
	ch.Ship.Stopped = true; 
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);

	ch.old.name = "Cecil Scott";
	ch.old.lastname = "Forester";
	ch.name = TranslateString("", "Cecil Scott");
	ch.lastname = TranslateString("", "Forester");
	ch.id		= "C.S. Forester";
	ch.model	= "Huber_Hol1_17";
	ch.sex = "man";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "C.S. Forester_dialog.c";
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
	ch.money = 10000;
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n,ch);

	ch.old.name = "Capitaine";
	ch.old.lastname = "de Corvette";
	ch.name = TranslateString("", "Capitaine");
	ch.lastname = TranslateString("", "de Corvette");
	ch.id		= "French_patrol_captain";
	ch.nation	= FRANCE;
	ch.model	= "fra_lut_18";
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade9+1");
	ch.equip.blade = "blade9";
	GiveItem2Character(ch, "pistol1");
	ch.equip.gun = "pistol1";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "Quest_ships";
	ch.location.locator = "quest_ship_12";
	ch.Dialog.Filename = "falaise de fleur soldier_dialog.c";
	ch.rank 	= 4;
	ch.reputation = "70";
	ch.experience = "10";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "1000";
	ch.Ship.Name = "Méduse";
	ch.Ship.Type = "FR_Greyhound";
	ch.Ship.Stopped = true;
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 180.0, 180.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);
}
	
