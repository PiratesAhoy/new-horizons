void CreateStoryCharacters(ref n)
{
	object chobj;
	ref ch;

	makeref(ch, chobj);

	ch.old.name = "Mystery";
	ch.old.lastname = "Messenger";
	ch.name = TranslateString("", "Mystery");
	ch.lastname = TranslateString("", "Messenger");
	ch.id		= "Mystery Messenger";
	ch.model = "Chameleon";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Mystery Messenger_dialog.c";
	ch.greeting = "Gr_Marc Blacque";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "3";
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
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);

	ch.old.name = "Nicholas";
	ch.old.lastname = "Sharp";
	ch.name = TranslateString("", "Nicholas");
	ch.lastname = TranslateString("", "Sharp");
	ch.id		= "Devlin Jumpstart";
	ch.model = "pirat13";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	GiveItem2Character(ch, "blade18");
	ch.equip.blade = "blade18";
	ch.location	= "Storyteller_house";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Devlin Jumpstart_dialog.c";
	ch.greeting = "";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	ch.questchar = true;
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);

	ch.old.name = "Emmanuel";
	ch.old.lastname = "Devlin";
	ch.name = TranslateString("","Emmanuel");
	ch.lastname = TranslateString("","Devlin");
	ch.id		= "Emmanuel Devlin";
	ch.model = "Old_mat1";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Emmanuel Devlin_dialog.c";
	ch.greeting = "Gr_Uncle Manny";
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
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Bonnie";
	ch.old.lastname = "Devlin";
	ch.name = TranslateString("","Bonnie");
	ch.lastname = TranslateString("","Devlin");
	ch.id		= "Bonnie Devlin";
	ch.model = "BeatriceA";
	ch.model.animation = "woman_sit";
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Bonnie Devlin_dialog.c";
	ch.greeting = "Gr_Bonnie"; //Gr_Stephan Bonser";
	ch.rank 	= 20;
	ch.reputation = "22";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "1000";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Blaze";
	ch.old.lastname = "Devlin";
	ch.name = TranslateString("","Blaze");
	ch.lastname = TranslateString("","Devlin");
	ch.id		= "Blaze Devlin";
	ch.model = "Devlin";
	ch.model.animation = "man";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	GiveItem2Character(ch, "blade21");
	ch.equip.blade = "blade21";
	GiveItem2Character(ch, "pistol27");
	ch.equip.blade = "pistol27";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Blaze Devlin_dialog.c";
	ch.greeting = "Gr_Devlin"; //Gr_Stephan Bonser";
	ch.rank 	= 20;
	ch.reputation = "22";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "1000";
	LAi_SetPoorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Crewmember";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Crewmember");
	ch.lastname = TranslateString("", "");
	ch.id		= "Crewmember Devlin";
	ch.model = "Sailor3";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Crewmember Devlin_dialog.c";
	ch.greeting = "Gr_Marc Blacque";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "3";
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
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);

	ch.old.name = "Short Jack";
	ch.old.lastname = "Gold";
	ch.name = TranslateString("", "Short Jack");
	ch.lastname = TranslateString("", "Gold");
	ch.id		= "Short Jack Gold";
	ch.model	= "50FatJack"; // PB
	ch.sex = "man";
	ch.loyality = 15;
	ch.alignment = "good";
	ch.sound_type = "pirate";
	ch.nation = PIRATE;
	ch.location	= "Turks_townhall";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Short Jack Gold_dialog.c";
	// PB -->
	ch.Ship.Name = "General Source";
	ch.Ship.Type = "RN_RevengeM";
	ch.Ship.Stopped = true;
	GiveItem2Character(ch, "blade26+1");
	ch.equip.blade = "blade26+1";
	GiveItem2Character(ch, "pistol5+1");
	ch.equip.gun = "pistol5+1";
	// PB <--
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.rank 	= 40;
	// PB -->
	ch.reputation = "60";
	ch.experience = "2000000";
	ch.greeting = "Gr_SJG";
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
	ch.money = "1941";
	// PB <--
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Couch Captain";
	ch.old.lastname = "Charles";
	ch.name = TranslateString("", "Couch Captain");
	ch.lastname = TranslateString("", "Charles");
	ch.id		= "Couch Captain Charles";
	ch.model	= "CouchCaptainCharles"; // Thomas the Terror
	ch.sex = "man";
	ch.loyality = 15;
	ch.alignment = "good";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Couch Captain Charles_dialog.c";
	// PB -->
	ch.Ship.Name = "The Comfy Sofa";
	ch.Ship.Type = "Frigate2";
	ch.Ship.Stopped = true;
	GiveItem2Character(ch, "blade26+1");
	ch.equip.blade = "blade26+1";
	GiveItem2Character(ch, "pistol5+1");
	ch.equip.gun = "pistol5+1";
	// PB <--
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.rank 	= 40;
	// PB -->
	ch.reputation = "60";
	ch.experience = "2000000";
	ch.greeting = "Gr_SJG";
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
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Sir Christopher";
	ch.old.lastname = "Mings";
	ch.name = TranslateString("", "Sir Christopher");
	ch.lastname = TranslateString("", "Mings");
	ch.id		= "Sir Christopher Mings";
	ch.model	= "SirChristopherMings";
	ch.sex = "man";
	ch.loyality = 15;
	ch.alignment = "good";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Sir Christopher Mings_dialog.c";
	// PB -->
	ch.Ship.Name = "China Vase";
	ch.Ship.Type = "Frigate2";
	ch.Ship.Stopped = true;
	GiveItem2Character(ch, "blade26+1");
	ch.equip.blade = "blade26+1";
	GiveItem2Character(ch, "pistol5+1");
	ch.equip.gun = "pistol5+1";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.rank 	= 40;
	// PB -->
	ch.reputation = "60";
	ch.experience = "2000000";
	ch.greeting = "Gr_SJG";
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
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Nathan";
	ch.old.lastname = "Kell";
	ch.name = TranslateString("", "Nathan");
	ch.lastname = TranslateString("", "Kell");
	ch.id		= "Nathan Kell";
	ch.model	= "Searcher_navy";
	ch.sex = "man";
	ch.loyality = 15;
	ch.alignment = "good";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Nathan Kell_dialog.c";
	// PB -->
	ch.Ship.Name = "The Coder";
	ch.Ship.Type = "PiratFrigateSup";
	ch.Ship.Stopped = true;
	GiveItem2Character(ch, "blade26+1");
	ch.equip.blade = "blade26+1";
	GiveItem2Character(ch, "pistol5+1");
	ch.equip.gun = "pistol5+1";
	// PB <--
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.rank 	= 40;
	// PB -->
	ch.reputation = "60";
	ch.experience = "2000000";
	ch.greeting = "Gr_SJG";
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
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Petros";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Petros");
	ch.lastname = TranslateString("", "");
	ch.id		= "Petros";
	ch.model	= "50grey1";
	ch.sex = "man";
	ch.loyality = 15;
	ch.alignment = "good";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Petros_dialog.c";
	// PB -->
	ch.Ship.Name = "The Rock";
	ch.Ship.Type = "SP_Galeon50";
	ch.Ship.Stopped = true;
	GiveItem2Character(ch, "blade26+1");
	ch.equip.blade = "blade26+1";
	GiveItem2Character(ch, "pistol5+1");
	ch.equip.gun = "pistol5+1";
	// PB <--
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.rank 	= 40;
	// PB -->
	ch.reputation = "60";
	ch.experience = "2000000";
	ch.greeting = "Gr_SJG";
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
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

//////////////////// v SJG EXPERIMENT WITH CHARACTERS v ///////////////////////////////////

	ch.old.name = "Thomas the";
	ch.old.lastname = "Terror";
	ch.name = TranslateString("","Thomas the");
	ch.lastname = TranslateString("","Terror");
	ch.id		= "Thomas the Terror";
	ch.model = "Thomas_the_Terror"; // Thomas the Terror
	ch.sex = "man";
	ch.loyality = 15;
	ch.sound_type = "pirate";
	ch.Ship.Name = "Wapen van Bergen op Zoom";
	ch.Ship.Type = "NL_Frigate47";
	ch.Ship.Stopped = true;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Thomas the Terror_dialog.c";
	ch.greeting = "Gr_SJG";
	ch.rank 	= 1;
	ch.reputation = "22";
	ch.experience = "2000";
	ch.skill.Leadership = "9";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "7";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "8";
	ch.skill.Grappling = "7";
	ch.skill.Repair = "5";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "5";
	ch.money = "1000";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "John Paul";
	ch.old.lastname = "Jones";
	ch.name = TranslateString("","John Paul");
	ch.lastname = TranslateString("","Jones");
	ch.id		= "John Paul Jones";
	ch.model = "JP_Jones_adm";
	ch.sex = "man";
	ch.loyality = 15;
	ch.sound_type = "pirate";
	ch.Ship.Name = "USS Constitution";
	ch.Ship.Type = "USS_Constitution";
	ch.Ship.Stopped = true;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nation	= ENGLAND;
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "John Paul Jones_dialog.c";
	ch.greeting = "Gr_Stephan Bonser";
	ch.rank 	= 1;
	ch.reputation = "22";
	ch.experience = "2000";
	ch.skill.Leadership = "9";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "7";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "8";
	ch.skill.Grappling = "7";
	ch.skill.Repair = "5";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "5";
	ch.money = "1000";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Captain";
	ch.old.lastname = "Maximus";
	ch.name = TranslateString("", "Captain");
	ch.lastname = TranslateString("", "Maximus");
	ch.id		= "Maximus";
	ch.model	= "Espinosa";
	ch.model.animation = "man"; // PB
	ch.sex = "man";
	ch.loyality = 15;
	ch.alignment = "good";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Maximus_dialog.c";
	// PB -->
	ch.Ship.Name = "Maximus Gigantica";
	ch.Ship.Type = "Frigate2";
	ch.Ship.Stopped = true;
	GiveItem2Character(ch, "blade26+1");
	ch.equip.blade = "blade26+1";
	GiveItem2Character(ch, "pistol5+1");
	ch.equip.gun = "pistol5+1";
	// PB <--
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.rank 	= 40;
	// PB -->
	ch.reputation = "60";
	ch.experience = "2000000";
	ch.greeting = "Gr_SJG";
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
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

//////////////////// ^ SJG EXPERIMENT WITH CHARACTERS ^ ///////////////////////////////////

	ch.old.name = "High Sea";
	ch.old.lastname = "Lass";
	ch.name = TranslateString("","High Sea");
	ch.lastname = TranslateString("","Lass");
	ch.id		= "High Sea Lass";
	ch.model = "33_Blazie";
	ch.sex = "woman";
	ch.model.animation = "woman_sit";
	ch.sound_type = "female_citizen";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "High Sea Lass_dialog.c";
	ch.Ship.Name = "Lass of the Seas";
	ch.Ship.Type = "Frigate2";
	ch.Ship.Stopped = true;
	GiveItem2Character(ch, "blade26+1");
	ch.equip.blade = "blade26+1";
	GiveItem2Character(ch, "pistol5+1");
	ch.equip.gun = "pistol5+1";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.greeting = "Gr_SJGfem"; //Gr_Stephan Bonser";
	ch.rank 	= 40;
	ch.reputation = "22";
	ch.experience = "600";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "8";
	ch.skill.Grappling = "8";
	ch.skill.Repair = "8";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "6";
	ch.skill.Sneak = "5";
	ch.money = "1000";
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
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Catalina";
	ch.old.lastname = "the Pirate";
	ch.name = TranslateString("","Catalina");
	ch.lastname = TranslateString("","the Pirate");
	ch.id		= "Catalina the Pirate";
	ch.model = "9CATa";
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Catalina the Pirate_dialog.c";
	ch.Ship.Name = "The Catalina II";
	ch.Ship.Type = "Frigate2";
	ch.Ship.Stopped = true;
	GiveItem2Character(ch, "blade26+1");
	ch.equip.blade = "blade26+1";
	GiveItem2Character(ch, "pistol5+1");
	ch.equip.gun = "pistol5+1";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.greeting = "Gr_SJGfem"; //Gr_Stephan Bonser";
	GiveItem2Character(ch, "commonarmor");
	ch.equip.armor = "commonarmor";
	ch.rank 	= 40;
	ch.reputation = "22";
	ch.experience = "600";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "8";
	ch.skill.Grappling = "8";
	ch.skill.Repair = "8";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "6";
	ch.skill.Sneak = "5";
	ch.money = "1000";
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
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Morgan";
	ch.old.lastname = "Terror";
	ch.name = TranslateString("", "Morgan");
	ch.lastname = TranslateString("", "Terror");
	ch.id		= "Morgan Terror";
	ch.model	= "capnhook";
	ch.sex = "man";
	ch.loyality = 15;
	ch.alignment = "good";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Morgan Terror_dialog.c";
	GiveItem2Character(ch, "blade26+1");
	ch.equip.blade = "blade26+1";
	ch.rank 	= 4;
	ch.reputation = "6";
	ch.experience = "200";
	ch.greeting = "Gr_Pieter Boelen";
	ch.skill.Leadership = "0";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "20";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Bartholomew";
	ch.old.lastname = "Roberts";
	ch.name = TranslateString("", "Bartholomew");
	ch.lastname = TranslateString("", "Roberts");
	ch.id		= "Bartholomew Roberts";
	ch.model	= "Pirat3";
	ch.sex = "man";
	ch.loyality = 15;
	ch.alignment = "good";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Bartholomew Roberts_dialog.c";
	ch.Ship.Name = "Royal Fortune";
	ch.Ship.Type = "Frigate2";
	ch.Ship.Stopped = true;
	ch.Flags.Pirate = 0;
	ch.Flags.Pirate.texture = 2;
	GiveItem2Character(ch, "blade26+1");
	ch.equip.blade = "blade26+1";
	GiveItem2Character(ch, "pistol5+1");
	ch.equip.gun = "pistol5+1";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.rank 	= 40;
	// PB -->
	ch.reputation = "60";
	ch.experience = "2000000";
	ch.greeting = "Gr_SJG";
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
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Merciless";
	ch.old.lastname = "Mark";
	ch.name = TranslateString("", "Merciless");
	ch.lastname = TranslateString("", "Mark");
	ch.id		= "Merciless Mark";
	ch.model	= "Merciless_Mark"; // Thomas the Terror
	ch.sex = "man";
	ch.loyality = 15;
	ch.alignment = "good";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Merciless Mark_dialog.c";
	ch.Ship.Name = "Irrepressible";
	ch.Ship.Type = "HMS_Surprise";
	ch.Ship.Stopped = true;
	GiveItem2Character(ch, "blade26+1");
	ch.equip.blade = "blade26+1";
	GiveItem2Character(ch, "pistol5+1");
	ch.equip.gun = "pistol5+1";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.rank 	= 40;
	// PB -->
	ch.reputation = "60";
	ch.experience = "2000000";
	ch.greeting = "Gr_SJG";
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
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

}
