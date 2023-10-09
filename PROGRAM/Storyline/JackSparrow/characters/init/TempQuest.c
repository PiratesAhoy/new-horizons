void CreateTempQuestCharacters(ref n)
{
	object chobj;
	ref ch;
	makeref(ch, chobj);
// Early Days & CoTBP -->
	ch.old.name = "Matthew";
	ch.old.lastname = "Shaw";
	ch.name = TranslateString("", "Matthew");
	ch.lastname = TranslateString("", "Shaw");
	ch.id		= "Matthew Shaw";
	ch.model = "albermal";
	ch.sex = "man";
	ch.location	= "Grand_Cayman_townhall";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "Matthew Shaw_dialog.c";
	ch.nation = ENGLAND;
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
//	LAi_RemoveLoginTime(ch);
	LAi_SetActorType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
//	ch.greeting = "Gr_Matthew Shaw";
	AddGameCharacter(n, ch);

	ch.old.name = "Billy";
	ch.old.lastname = "Brock";
	ch.name = TranslateString("", "Billy");
	ch.lastname = TranslateString("", "Brock");
	ch.id		= "Billy Brock";
	ch.model = "BillyBrock2";
	ch.sex = "man";
//	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	GiveItem2Character(ch, "pistol1");
	ch.equip.gun = "pistol1";
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
//	ch.greeting = "Gr_Drunk Billy";
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
	AddGameCharacter(n,ch);

	ch.old.name = "James";
	ch.old.lastname = "Norrington";
	ch.name 	= TranslateString("", "James");
	ch.lastname 	= TranslateString("", "Norrington");
	ch.id		= "James Norrington";
	ch.model	= "Mdnorrington";
	ch.sex = "man";
//	ch.sound_type = "seaman";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "James Norrington_dialog.c";
//	ch.greeting = "Gr_James Norrington";
	ch.Ship.Name = TranslateString("","Interceptor");	//SJG
	ch.Ship.Type = "HMS_Interceptor";		//Kazeite
	ch.Ship.Stopped = true;
	ch.Flags.Pirate = 2;
	ch.Flags.Pirate.texture = 3;
	ch.Flags.Personal = 5;
	ch.Flags.Personal.texture = 2;
	ch.greeting = "Gr_Oxbay Citizen";
	ch.rank 	= 1;
	ch.nation = ENGLAND;
	ch.reputation = "None";
	ch.experience = "2";
	ch.skill.Leadership = "3";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "4";
	ch.skill.Repair = "1";
	ch.skill.Defence = "5";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "100";
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n,ch);

	ch.old.name = "Lieutenant";
	ch.old.lastname = "Bligh";
	ch.name 	= TranslateString("", "Lieutenant");
	ch.lastname 	= TranslateString("", "Bligh");
	ch.id		= "Lieutenant Bligh";
	ch.model	= "Brtlut3_18";
	ch.sex = "man";
//	ch.sound_type = "seaman";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Lieutenant Bligh_dialog.c";
//	ch.greeting = "Gr_Oxbay Citizen";
	ch.Ship.Name = TranslateString("","Bounty1");	//SJG
	ch.Ship.Type = "HMS_Bounty";	//ZarethPL
	ch.Ship.Stopped = true;
	ch.Flags.Pirate = 2;
	ch.Flags.Pirate.texture = 3;
	ch.Flags.Personal = 3; // PB: EITC Flag
	ch.Flags.Personal.texture = 3;
//	ch.greeting = "Gr_Oxbay Citizen";
	ch.rank 	= 1;
	ch.nation = ENGLAND;
	ch.reputation = "None";
	ch.experience = "2";
	ch.skill.Leadership = "3";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "4";
	ch.skill.Repair = "1";
	ch.skill.Defence = "5";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "100";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n,ch);

	ch.old.name = "Edward";
	ch.old.lastname = "Teague";
	ch.name 	= TranslateString("", "Edward");
	ch.lastname 	= TranslateString("", "Teague");
	ch.id		= "Teague Sparrow";
	ch.model	= "CaptainTeague";
	ch.sex = "man";
//	ch.sound_type = "seaman";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Teague Sparrow_dialog.c";
//	ch.greeting = "Gr_Teague Sparrow";
	ch.rank 	= 1;
	ch.nation = ENGLAND;
	ch.reputation = "None";
	ch.experience = "2";
	ch.skill.Leadership = "3";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "4";
	ch.skill.Repair = "1";
	ch.skill.Defence = "5";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "100";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n,ch);

	ch.old.name = "Oswald";
	ch.old.lastname = "Chappel";
	ch.name = TranslateString("", "Oswald");
	ch.lastname = TranslateString("", "Chappel");
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
//	LAi_SetCivilianGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Oswald Chappel";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n,ch);

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
	ch.Ship.Name = TranslateString("","China Vase");
	ch.Ship.Type = "Frigate2";
	ch.Ship.Stopped = true;
	GiveItem2Character(ch, "blade21"); //"blade26+1");
	ch.equip.blade = "blade21"; //"blade26+1";
	GiveItem2Character(ch, "pistol4"); //"pistol5+1");
	ch.equip.gun = "pistol4"; //"pistol5+1";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
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
	ch.money = "1986";
	// PB <--
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Will";
	ch.old.lastname = "Turner";
	ch.name = TranslateString("", "Will");
	ch.lastname = TranslateString("", "Turner");
	ch.id		= "Will Turner";
	ch.nation	= ENGLAND;
//	ch.sound_type = "seaman";
	ch.model	= "Will";
	ch.sex = "man";
	GiveItem2Character(ch, "bladeC30");
	ch.equip.blade = "bladeC30";
	GiveItem2Character(ch, "pistol5");
	ch.equip.gun = "pistol5";
	//JRH ammo mod -->
//	TakenItems(ch, "gunpowder", 6);
//	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Will Turner_dialog.c";
	ch.rank 	= 18;
	ch.reputation = "70";
	ch.experience = "0";
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
	LAi_SetWarriorType(ch); // PB
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 180.0, 180.0);
	ch.greeting = "Gr_Will Turner";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n,ch);

	ch.old.name = "Annabella";
	ch.old.lastname = "Brin";
	ch.name = TranslateString("", "Annabella");
	ch.lastname = TranslateString("", "Brin");
	ch.id		= "Annabella Brin";
	ch.model = "towngirl1";
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Annabella Brin_dialog.c";
	ch.greeting = "Gr_Annabella_Brin";
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
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Bella";
	ch.old.lastname = "Brin";
	ch.name = TranslateString("", "Bella");
	ch.lastname = TranslateString("", "Brin");
	ch.id		= "Bella Brin";
	ch.model = "Liz1";
	ch.sex = "woman";
//	ch.sound_type = "female_citizen";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Annabella Brin_dialog.c";
//	ch.greeting = "Gr_Estrella";
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
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Susan";
	ch.old.lastname = "Shaypen";
	ch.name = TranslateString("", "Susan");
	ch.lastname = TranslateString("", "Shaypen");
	ch.id		= "Susan Shaypen";
	ch.model = "Daniell3"; // GR: was "Daniell1"
	ch.sex = "woman";
	ch.model.animation = "woman";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Susan Shaypen_dialog.c";
	ch.nation = ENGLAND;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.rank 	= 1;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "5";
	ch.skill.Sneak = "5";
	ch.money = "100";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Bootstrap Bill";
	ch.old.lastname = "Turner";
	ch.name = TranslateString("", "Bootstrap Bill");
	ch.lastname = TranslateString("", "Turner");
	ch.id		= "Bootstrap Bill Turner";
	ch.nation	= ENGLAND;
	ch.sound_type = "seaman";
	ch.model	= "BootstrapBill";	// was "Will"
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Bootstrap Bill Turner_dialog.c";
	ch.rank 	= 18;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "8";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "10";
	ch.skill.Cannons = "8";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "9";
	ch.skill.Defence = "9";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = 1000;
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 180.0, 180.0);
	ch.greeting = "Gr_Ewan Glover";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Cutler";
	ch.old.lastname = "Beckett";
	ch.name 	= TranslateString("", "Cutler");
	ch.lastname 	= TranslateString("", "Beckett");
	ch.id		= "Cutler Beckett";
	ch.model	= "Young_Beckett"; // Thomas the Terror
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Cutler Beckett_dialog.c";
//	ch.greeting = "Gr_Cutler Beckett";
	ch.Ship.Name = TranslateString("","Lindesfarne");	// PB
	ch.Ship.Type = "HMS_Bounty";	// PB
	ch.Ship.Stopped = true;
	ch.Flags.Pirate = 2;
	ch.Flags.Pirate.texture = 3;
	ch.Flags.Personal = 3; // PB: EITC Flag
	ch.Flags.Personal.texture = 3;
	ch.rank 	= 1;
	ch.nation = ENGLAND;
	ch.reputation = "10"; // was none SJG
	ch.experience = "4";
	ch.skill.Leadership = "8";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "4";
	ch.skill.Repair = "1";
	ch.skill.Defence = "5";
	ch.skill.Commerce = "9";
	ch.skill.Sneak = "1";
	ch.money = "1000";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n,ch);

	ch.old.name = "Annabella";
	ch.old.lastname = "Brinkley";
	ch.name = TranslateString("", "Annabella");
	ch.lastname = TranslateString("", "Brinkley");
	ch.id		= "Annabella Brinkley";
	ch.model = "Brinkley";
	ch.sex = "woman";
//	ch.sound_type = "female_citizen";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Annabella Brin_dialog.c";
//	ch.greeting = "Gr_Annabella_Brin";
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
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Anamaria";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Anamaria");
	ch.lastname = "";
	ch.id		= "Annamaria";
//	ch.model = "Danblack";
	ch.model = "Anamaria";
	ch.sex = "woman";
//	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade10");		//JRH: was Piranha
	ch.equip.blade = "blade10";
	ch.nation	= PIRATE;
	GiveItem2Character(ch, "pistol4");
	ch.equip.gun = "pistol4";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Annamaria_dialog.c";
	ch.rank 	= 8;
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
	ch.perks.list.ProfessionalGunman = true;
//	ch.quest.meeting = "0";
//	LAi_SetCivilianGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
//	ch.greeting = "Gr_Woman_English Citizen";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Tia";
	ch.old.lastname = "Dalma";
	ch.name = TranslateString("", "Tia");
	ch.lastname = TranslateString("", "Dalma");
	ch.id		= "Tia Dalma";
	ch.model	= "TiaDalma"; // Damski
	ch.model.animation = "TiaDalma"; // Damski
	ch.sex = "woman";
//	ch.sound_type = "female_citizen";
	ch.FaceId      =  226;
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Tia Dalma_dialog.c";
	ch.nation = ENGLAND;
	ch.rank 	= 6;
	ch.reputation = "50";
	ch.experience = "60";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "6";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "10";
	ch.skill.Commerce = "5";
	ch.skill.Sneak = "1";
	ch.money = "1000";
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
//	LAi_SetCitizenType(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = "";
	ch.id		= "Pirates_1";
	ch.model	= "korsar";
	ch.sound_type = "pirate";
	//LAi_NoRebirthEnable(ch);
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
	ch.questchar = true;//MAXIMUS: identifier for captives
	ch.Dialog.Filename = "Turks_prison_guard1_dialog.c";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);

	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = "";
	ch.id		= "Pirates_2";
	ch.model	= "corsair2";
	ch.sound_type = "pirate";
	//LAi_NoRebirthEnable(ch);
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
	ch.questchar = true;//MAXIMUS: identifier for captives
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);

	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = "";
	ch.id		= "Pirates_3";
	ch.model	= "corsair1";
	ch.sound_type = "pirate";
	//LAi_NoRebirthEnable(ch);
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
	ch.questchar = true;//MAXIMUS: identifier for captives
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);

	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = "";
	ch.id		= "Pirates_4";
	ch.model	= "Fatman2";
	ch.sound_type = "pirate";
	//LAi_NoRebirthEnable(ch);
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
	ch.questchar = true;//MAXIMUS: identifier for captives
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);
	
	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = "";
	ch.id		= "Pirates_5";
	ch.model	= "33_Ronald";
	ch.sound_type = "pirate";
	//LAi_NoRebirthEnable(ch);
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
	ch.questchar = true;//MAXIMUS: identifier for captives
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);
	
	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = "";
	ch.id		= "Pirates_6";
	ch.model	= "Black_corsair";
	ch.sound_type = "pirate";
	//LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "goto";
	ch.location.locator = "character7";
	ch.Dialog.Filename = "Pirat.c";
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
	ch.questchar = true;//MAXIMUS: identifier for captives
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);
	
	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = "";
	ch.id		= "Pirates_6";
	ch.model	= "Black_corsair";
	ch.sound_type = "pirate";
	//LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "goto";
	ch.location.locator = "character7";
	ch.Dialog.Filename = "Pirat.c";
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
	ch.questchar = true;//MAXIMUS: identifier for captives
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);
	
	
	ch.old.name = "Sailor";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Sailor");
	ch.lastname = "";
	ch.id		= "Sailor_1";
	ch.model	= "Sailor5";
	ch.sound_type = "pirate";
	//LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	//GiveItem2Character(ch, "blade4");
	//ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "goto";
	ch.location.locator = "character7";
	ch.Dialog.Filename = "Turks_prison_guard1_dialog.c";
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
	ch.questchar = true;//MAXIMUS: identifier for captives
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);
	
	ch.old.name = "Sailor";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Sailor");
	ch.lastname = "";
	ch.id		= "Sailor_2";
	ch.model	= "Sailor6";
	ch.sound_type = "pirate";
	//LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	//GiveItem2Character(ch, "blade4");
	//ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "goto";
	ch.location.locator = "character7";
	ch.Dialog.Filename = "Turks_prison_guard1_dialog.c";
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
	ch.questchar = true;//MAXIMUS: identifier for captives
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);
	
	ch.old.name = "Sailor";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Sailor");
	ch.lastname = "";
	ch.id		= "Corpse";
	ch.model	= "davy2";
	ch.sound_type = "pirate";
	//LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "goto";
	ch.location.locator = "character7";
	ch.Dialog.Filename = "Turks_prison_guard1_dialog.c";
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
	ch.questchar = true;//MAXIMUS: identifier for captives
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);
	
	
	
	
	ch.old.name = "Morris";
	ch.old.lastname = "Murtogg";
	ch.name = TranslateString("", "Morris");
	ch.lastname = TranslateString("", "Murtogg");
	ch.id		= "Morris Murtogg";
	ch.model	= 0; // PB
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Morris Murtogg_dialog.c";// Daniel Arrest
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

	ch.old.name = "Malvert";
	ch.old.lastname = "Mullroy";
	ch.name = TranslateString("", "Malvert");
	ch.lastname = TranslateString("", "Mullroy");
	ch.id		= "Malvert Mullroy";
	ch.model	= 1; // PB
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Malvert Mullroy_dialog.c";
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

	ch.old.name = "Captain";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Captain");
	ch.lastname = "";
	ch.id		= "Quest_frigate_captain";
	ch.nation	= FRANCE;
	ch.model	= "capitan";
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
	ch.Ship.Name = TranslateString("","Volcano");
	ch.Ship.Type = "Battleship1"; // PRS3
	ch.Ship.Stopped = true;
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS24;
//	ch.quest.killed.pirates = "0";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Elizabeth";
	ch.old.lastname = "Swann";
	ch.name = TranslateString("", "Elizabeth");
	ch.lastname = TranslateString("", "Swann");
	ch.id		= "Elizabeth Swann";
	ch.model = "Liz1";
	ch.sex = "woman";
	ch.sound_type = "pirate";
	ch.nation	= ENGLAND;
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
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	ch.greeting = "Gr_Arabella Silehard";
	AddGameCharacter(n, ch);

	ch.old.name = "Simon";
	ch.old.lastname = "Blunden";
	ch.name = TranslateString("", "Simon");
	ch.lastname = TranslateString("", "Blunden");
	ch.id		= "Eng Captain Near FdF";
	ch.model = "corsair1_2";
	ch.sex = "man";
	ch.nation	= PIRATE;
	ch.sound_type = "soldier";
	LAi_NoRebirthEnable(ch);
	ch.Ship.AI.GroupName = "England_Captain_Near_FdF";
	ch.Ship.AI.Task = "attack";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none"
	ch.location.group = "Quest_ships";
	ch.location.locator = "quest_ship_12";
	ch.Ship.Stopped = true;	
	ch.Dialog.Filename = "falaise de fleur soldier_dialog.c";
	ch.nation = PIRATE;
	ch.Ship.Name = TranslateString("","Volcano II");
	ch.Ship.Type = 	"Frigate2";
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
//	ch.greeting = "Gr_falaise de fleur soldier";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Turpin";
	ch.old.lastname = "Cabanel";
	ch.name = TranslateString("", "Turpin");
	ch.lastname = TranslateString("", "Cabanel");
	ch.id		= "Turpin Cabanel";
	ch.model = "man6_1";
	ch.sex = "man";
	ch.sound_type = "merchant";
	ch.location	= "Head_port_house";
	ch.location.group = "goto";
	ch.location.locator = "locator1";
	ch.Dialog.Filename = "Turpin Cabanel_dialog.c";
	ch.greeting = "Gr_turpin cabanel";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "65";
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
	ch.money.quest = "0";
	ch.quest.meeting = "0";
	ch.quest.smugglers = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	LAi_SetImmortal(ch, true);
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
	ch.Ship.Name = TranslateString("","Amsterdam");
	ch.Ship.Type = "NL_Amsterdam";
	ch.Ship.Stopped = true;
	ch.Flags.Pirate = 0;
	ch.Flags.Pirate.texture = 0;
	ch.Flags.Personal = 2;
	ch.Flags.Personal.texture = 1;
	GiveItem2Character(ch, "blade4"); //(ch, "blade26+1");
	ch.equip.blade = "blade4"; //"blade26+1";
	GiveItem2Character(ch, "pistol5+1");
	ch.equip.gun = "pistol5+1";
	// PB <--
	//JRH ammo mod -->
//	TakenItems(ch, "gunpowder", 6);
//	TakenItems(ch, "pistolbullets", 6);
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
	ch.money = "1986";
	// PB <--
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);

	ch.old.name = "John";
	ch.old.middlename = "Clifford";
	ch.old.lastname = "Brin";
	ch.name = TranslateString("", "John");
	ch.middlename = TranslateString("", "Clifford");
	ch.lastname = TranslateString("", "Brin");
	ch.id		= "John Clifford Brin";
	ch.model	= "brin";
	ch.sex = "man";
	ch.location	= "Redmond_residence";
	ch.location.group = "goto";
	ch.location.locator = "goto8";
	ch.Dialog.Filename = "Robert Christopher Silehard_dialog.c";
	ch.rank 	= 10;
	ch.reputation = "80";
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
	ch.money = "100000";
	LAi_SetHuberStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	ch.greeting = "Gr_John Clifford Brin";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n,ch);

	ch.old.name = "Hector";
	ch.old.lastname = "Barbossa";
	ch.name = TranslateString("", "Hector");
	ch.lastname = TranslateString("", "Barbossa");
	ch.id		= "Barbossa";
	ch.nation	= PIRATE;
	ch.model	= "Barbossa"; // SCM
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Flags.Pirate = 0; // PB: Jack Rackham Pirate Flag
	ch.Flags.Pirate.texture = 0;
	ch.Flags.Personal = 2;
	ch.Flags.Personal.texture = 0;
	ch.Dialog.Filename = "Barbossa_dialog.c"; // SJG
	ch.rank 	= 20;
	ch.reputation = "1";
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
	ch.money = 1000; //QUEST_CHAR_MONEY; // PB
	ch.boardingmodels = "Skeletons";
	ch.FaceId = 31;
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	Lai_SetImmortal(ch, true);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n,ch);

	ch.old.name = "Anne";
	ch.old.lastname = "Bonny";
	ch.name = TranslateString("", "Anne");
	ch.lastname = TranslateString("", "Bonny");
	ch.id		= "Anne Bonny";
	ch.nation	= ENGLAND;
	ch.model	= "Fanielle";
	ch.sex = "woman";
	ch.luck = 4;
	GiveItem2Character(ch, "blade4"); //(ch, "blade6");
	TakeNItems(ch,"medical1", Rand(4)+1);
	ch.equip.blade = "blade4"; //"blade6";
	ch.nodisarm	= 1;				// PB: Disable disarming
	GiveItem2Character(ch, "pistol1");
	ch.equip.gun = "pistol1";
    //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
    //JRH ammo mod <--
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Anne Bonny_dialog.c";
	ch.greeting = "Gr_danielle";
	ch.rank 	= 4;
	ch.reputation = "50";
	ch.experience = CalculateExperienceFromRank(4)+ (CalculateExperienceFromRank(4)/10 + rand(4000));
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "2";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "2";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
	ch.perks.list.LongRangeShoot = true;
	ch.Ship.Name = TranslateString("","Vertigo");
	ch.Ship.Type = "PiratHannah"; // PRS3
	ch.FaceId = 30;
	ch.HPBonus = 100;
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	Lai_SetImmortal(ch, true);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n,ch);

	ch.old.name = "Davy";
	ch.old.lastname = "Jones";
	ch.name = TranslateString("", "Davy");
	ch.lastname = TranslateString("", "Jones");
	ch.id		= "Davy Jones";
	ch.model = "DavyJones"; // NikK
	ch.model.animation = "Rousselet";
	ch.sex = "man";
//	ch.sound_type = "pirate";
//	ch.greeting = "Gr_Davy Jones";
	LAi_NoRebirthEnable(ch);
	GiveItem2Character(ch, "blade14");
	ch.equip.blade = "blade14";
	GiveItem2Character(ch, "Pistol3");
	ch.equip.gun = "Pistol3";
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolgrapes", 6);
	ch.nation = PIRATE;
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "none";
	ch.Dialog.Filename = "Davy Jones_dialog.c";
	ch.Ship.Name = TranslateString("Flying Dutchman","");
	ch.Ship.Type = "CursedDutchman";
	ch.Ship.Stopped = true;
	ch.Flags.Pirate = 1;
	ch.Flags.Pirate.texture = 3;
	ch.Flags.Personal = 1;
	ch.Flags.Personal.texture = 2;
	ch.skipRM = true; // PB: Skip Relations Mod
	ch.greeting = "Gr_Davy Jones";
	ch.rank 	= 50;
	ch.reputation = "42";
	ch.experience = "0";
	ch.skill.Leadership = "8";
	ch.skill.Fencing = "9";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "10";
	ch.skill.Cannons = "10";
	ch.skill.Grappling = "6";
	ch.skill.Repair = "5";
	ch.skill.Defence = "9";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "4";
	ch.perks.list.BasicDamageControl = true;
	ch.perks.list.AdvancedDamageControl = true;
	ch.perks.list.Rigging = true;
	ch.perks.list.RiggingAdvance = true;
	ch.perks.list.HullDamageUp = true;
	ch.perks.list.FastReload = true;
	ch.perks.list.SailsDamageUp = true;
	ch.perks.list.CrewDamageUp = true;
	ch.perks.list.CriticalShoot = true;
	ch.perks.list.LongRangeShoot = true;
	ch.perks.list.CannonProfessional = true;
	ch.perks.list.IronWill = true;
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 990.0, 990.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Konrad";
	ch.old.lastname = "Kulczycki";
	ch.name = TranslateString("", "Konrad");
	ch.lastname = TranslateString("", "Kulczycki");
	ch.id		= "Konrad Kulczycki";
	ch.model	= "Corsair4";
	ch.sex = "man";
	ch.loyality = 15;
	ch.alignment = "good";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Konrad Kulczycki_dialog.c";
	// PB -->
	ch.Ship.Name = TranslateString("","Phantom");
	ch.Ship.Type = "FastGalleon2";
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
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Petros";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Petros");
	ch.lastname = "";
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
	ch.Ship.Name = TranslateString("","The Rock");
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
//	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Maykin";
	ch.old.lastname = "Blundas";
	ch.name = TranslateString("", "Maykin");
	ch.lastname = TranslateString("", "Blundas");
	ch.id		= "Maykin Blundas";
	ch.model	= "Killer";
	ch.sex = "man";
	ch.loyality = 15;
	ch.alignment = "good";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Maykin Blundas.c";
	// PB -->
	ch.Ship.Name = TranslateString("","Whisper");
	ch.Ship.Type = "Brig2";
	ch.Ship.Stopped = true;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	GiveItem2Character(ch, "pistol5+1");
	ch.equip.gun = "pistol5+1";
	// PB <--
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.rank 	= 40;
	ch.reputation = "60";
	ch.experience = "2000";
	ch.greeting = "Gr_Pieter Boelen";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "4";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "6";
	ch.skill.Grappling = "7";
	ch.skill.Repair = "2";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "5";
	ch.perks.list.LightRepair = true;
	ch.perks.list.ShipSpeedUp = true;
	ch.perks.list.ShipTurnRateUp = true;
	ch.perks.list.StormProfessional = true;
	ch.perks.list.Turn180 = false;
	ch.perks.list.SandbankManeuver = false;
	ch.perks.list.SailingProfessional = true;
	ch.perks.list.IronWill = true;
	ch.perks.list.BasicCommerce = false;
	ch.perks.list.AdvancedCommerce = false;
	ch.perks.list.Trustworthy = false;
	ch.perks.list.SharedExperience = true;
	ch.money = "2000";
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Cap'n";
	ch.old.lastname = "Drow";
	ch.name = TranslateString("", "Cap'n");
	ch.lastname = TranslateString("", "Drow");
	ch.id		= "Cap'n Drow";
	ch.model	= "Pirat3";
	ch.sex = "man";
	ch.loyality = 15;
	ch.alignment = "good";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Cap'n Drow_dialog.c";
	// PB -->
	ch.Ship.Name = TranslateString("","Vengeance");
	ch.Ship.Type = "Corvette47";
	ch.Ship.Stopped = true;
	GiveItem2Character(ch, "blade4"); //(ch, "blade26+1");
	ch.equip.blade = "blade4"; //"blade26+1";
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
//	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Thomas";
	ch.old.lastname = "the Terror";
	ch.name = TranslateString("","Thomas");
	ch.lastname = TranslateString("","the Terror");
	ch.id		= "Thomas the Terror";
	ch.model = "Thomas_the_Terror"; // Thomas the Terror
	ch.sex = "man";
	ch.loyality = 15;
//	ch.sound_type = "pirate";
	ch.Ship.Name = TranslateString("","Wapen van Bergen op Zoom");
	ch.Ship.Type = "NL_Frigate47";
	ch.Ship.Stopped = true;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Thomas the Terror_dialog.c";
//	ch.greeting = "Gr_Thomas the Terror";
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
//	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
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
	ch.nation = PIRATE;
	// PB -->
	ch.Ship.Name = TranslateString("","The Coder");
	ch.Ship.Type = "PiratFrigateSup";
	ch.Ship.Stopped = true;
	GiveItem2Character(ch, "blade4"); //(ch, "blade26+1");
	ch.equip.blade = "blade4"; //"blade26+1";
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
//	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Jack";
	ch.old.lastname = "Rackham";
	ch.name = TranslateString("", "Jack");
	ch.lastname = TranslateString("", "Rackham");
	ch.id		= "Jack Rackham";
	ch.model	= "Jack_Rackham";
	ch.sex = "man";
	ch.loyality = 15;
	ch.alignment = "good";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Jack Rackham_dialog.c";
	// PB -->
	ch.Ship.Name = TranslateString("","Curlew");
	ch.Ship.Type = "HMS_Sophie";
	ch.Ship.Stopped = true;
	ch.Flags.Pirate = 0;
	ch.Flags.Pirate.texture = 0;
	GiveItem2Character(ch, "blade21"); //"blade26+1");
	ch.equip.blade = "blade21"; //"blade26+1";
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
//	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Peter";
	ch.old.lastname = "Willemoes";
	ch.name = TranslateString("", "Peter");
	ch.lastname = TranslateString("", "Willemoes");
	ch.id		= "Peter Willemoes";
	ch.model	= "Corsair1_4";
	ch.sex = "man";
	ch.loyality = 15;
	ch.alignment = "good";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Peter Willemoes_dialog.c";
	// PB -->
	ch.Ship.Name = TranslateString("","Horn");
	ch.Ship.Type = "Sloop1";
	ch.Ship.Stopped = true;
	GiveItem2Character(ch, "blade4"); //(ch, "blade26+1");
	ch.equip.blade = "blade4"; //"blade26+1";
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
//	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Joshamee";
	ch.old.lastname = "Gibbs";
	ch.name = TranslateString("", "Joshamee");
	ch.lastname = TranslateString("", "Gibbs");
	ch.id		= "Mr. Gibbs";
	ch.model	= "bocman5"; // Thomas the Terror
	ch.sex = "man";
	ch.loyality = 15;
	ch.alignment = "good";
//	ch.sound_type = "seaman";
	ch.nation	= PIRATE;
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Mr. Gibbs_dialog.c";
	ch.greeting = "Gr_Mr. Gibbs";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.rank 	= 28;
	ch.reputation = "65";
	TakeNItems(ch,"potion1", Rand(4)+1);
	ch.experience = CalculateExperienceFromRank(28)+ (CalculateExperienceFromRank(28)/10 + rand(28000));
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "10";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "8";
	ch.skill.Repair = "10";
	ch.skill.Defence = "10";
	ch.skill.Commerce = "5";
	ch.skill.Sneak = "10";
	ch.Ship.Name = TranslateString("","Interceptor"); // Kazeite
	ch.Ship.Type = "HMS_Interceptor"; // Kazeite
	ch.Ship.Stopped = false; // SJG
	ch.Flags.Pirate = 2;
	ch.Flags.Pirate.texture = 3;
	ch.Flags.Personal = 5;
	ch.Flags.Personal.texture = 2;
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
	ch.money = "100";
	LAi_SetStayType(ch);
	LAi_SetHP(ch, 280.0, 280.0);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.HPBonus = 100;
//	LAi_NoRebirthEnable(ch);
//	ch.quest.officertype = OFFIC_TYPE_BOATSWAIN;
//	ch.quest.officerprice = "500";
	ch.questchar = true; // GR: keep same name if he is killed and respawned
	AddGameCharacter(n, ch);

	ch.old.name = "Captain";
	ch.old.lastname = "Damski";
	ch.name = TranslateString("", "Captain");
	ch.lastname = TranslateString("", "Damski");
	ch.id		= "Captain Damski";
	ch.model	= "Corsair5";
	ch.sex = "man";
	ch.loyality = 15;
	ch.alignment = "good";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Captain Damski_dialog.c";
	// PB -->
	ch.Ship.Name = TranslateString("","Slick Rigging");
	ch.Ship.Type = "Sloop2";
	ch.Ship.Stopped = true;
	GiveItem2Character(ch, "blade4"); //(ch, "blade26+1");
	ch.equip.blade = "blade4"; //"blade26+1";
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
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Captain";
	ch.old.lastname = "Maximus";
	ch.name = TranslateString("", "Captain");
	ch.lastname = TranslateString("", "Maximus");
	ch.id		= "Captain Maximus";
	ch.model	= "Espinosa";
	ch.model.animation = "new_man"; // PB
	ch.sex = "man";
	ch.loyality = 15;
	ch.alignment = "good";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Captain Maximus_dialog.c";
	ch.Ship.Name = TranslateString("","The Big Buccaneer");
	ch.Ship.Type = "Cutter1";
	ch.Ship.Stopped = true;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	GiveItem2Character(ch, "pistol5+1");
	ch.equip.gun = "pistol5+1";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.rank 	= 40;
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
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Captain";
	ch.old.lastname = "Philippe";
	ch.name = TranslateString("", "Captain");
	ch.lastname = TranslateString("", "Philippe");
	ch.id		= "Captain Philippe";
	ch.model = "33_Ronald";
	ch.model.animation = "33_Ronald";
	ch.sex = "man";
	ch.loyality = 15;
	ch.alignment = "good";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Captain Philippe_dialog.c";
	ch.Ship.Name = TranslateString("","Compass Rose");
	ch.Ship.Type = "Sloop1";
	ch.Ship.Stopped = true;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	GiveItem2Character(ch, "pistol2");
	ch.equip.gun = "pistol2";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.rank 	= 40;
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
	ch.money = "2008";
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
	ch.Ship.Name = TranslateString("","The Comfy Sofa");
	ch.Ship.Type = "HMS_Sophie";
	ch.Ship.Stopped = true;
	GiveItem2Character(ch, "blade4"); //(ch, "blade26+1");
	ch.equip.blade = "blade4"; //"blade26+1";
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
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Claudio";
	ch.old.lastname = "Burrieza";
	ch.name = TranslateString("", "Claudio");
	ch.lastname = TranslateString("", "Burrieza");
	ch.id		= "Claudio Burrieza";
	ch.model = "Fatman2";
	ch.sex = "man";
	ch.location	= "Muelle_tavern";
	ch.location.group = "merchant";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Claudio Burrieza_dialog.c";
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
	ch.quest.meeting = "0";
	ch.quest.escort = "0";
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	ch.greeting = "Gr_claudio burrieza";
	AddGameCharacter(n, ch);

	ch.old.name = "Port Guard";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Port Guard");
	ch.lastname = "";
	ch.id		= "Port Guard";
	ch.model	= "BrtSol18_1";
	ch.sound_type = "soldier";
//	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nation	= ENGLAND;
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Port Guard_dialog.c";
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
//	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
//	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	ch.greeting = "Gr_Redmond Soldier";
	AddGameCharacter(n, ch);

	ch.old.name = "Silas";
	ch.old.lastname = "Simpkins";
	ch.name = TranslateString("", "Silas");
	ch.lastname = TranslateString("", "Simpkins");
	ch.id		= "Silas Simpkins";
	ch.model	= "Man6_1";
//	ch.sound_type = "soldier";
//	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Silas Simpkins_dialog.c";
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
//	LAi_SetCivilianGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
//	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
//	ch.greeting = "Gr_Redmond Soldier";
	AddGameCharacter(n, ch);

	ch.old.name = "Thomas";
	ch.old.lastname = "Tipman";
	ch.name = TranslateString("", "Thomas");
	ch.lastname = TranslateString("", "Tipman");
	ch.id		= "Thomas Tipman";
	ch.model	= "Searcher";
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Thomas Tipman_dialog.c";
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
	LAi_SetStayType(ch); // PB
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);

	ch.old.name = "William";
	ch.old.lastname = "Wanderman";
	ch.name = TranslateString("", "William");
	ch.lastname = TranslateString("", "Wanderman");
	ch.id		= "William Wanderman";
	ch.model	= "Eitc_lt1_47";
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "William Wanferman_dialog.c";
	ch.rank 	= 10;
	ch.reputation = "None";
	ch.experience = "5";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "6";
	ch.skill.Cannons = "6";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "100";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_Redmond Soldier";
	AddGameCharacter(n, ch);

	ch.old.name = "Arthur";
	ch.old.lastname = "Straightly";
	ch.name = TranslateString("", "Arthur");
	ch.lastname = TranslateString("", "Straightly");
	ch.id		= "Arthur Straightly";
	ch.model	= "Eitc_lt2_47";
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Arthur Straightly_dialog.c";
	ch.rank 	= 10;
	ch.reputation = "None";
	ch.experience = "5";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "6";
	ch.skill.Cannons = "6";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "100";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_Redmond Soldier";
	AddGameCharacter(n, ch);

	ch.old.name = "Stephen";
	ch.old.lastname = "Walsh";
	ch.name = TranslateString("", "Stephen");
	ch.lastname = TranslateString("", "Walsh");
	ch.id		= "Stephen Walsh";
	ch.model	= "Eitc_lt3_47";
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Stephen Walsh_dialog.c";
	ch.rank 	= 10;
	ch.reputation = "None";
	ch.experience = "5";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "6";
	ch.skill.Cannons = "6";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "100";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_Redmond Soldier";
	AddGameCharacter(n, ch);

	ch.old.name = "Howard";
	ch.old.lastname = "Cummins";
	ch.name = TranslateString("", "Howard");
	ch.lastname = TranslateString("", "Cummins");
	ch.id		= "Howard Cummins";
	ch.model	= "Eitc_cpt1_47";
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Howard Cummins_dialog.c";
	ch.rank 	= 10;
	ch.reputation = "None";
	ch.experience = "8";
	ch.skill.Leadership = "8";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "6";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "1";
	ch.skill.Defence = "5";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "100";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_Redmond Soldier";
	AddGameCharacter(n, ch);

	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Soldier");
	ch.lastname = "";
	ch.id		= "Red_soldier_2";
	ch.model	= "soldier_eng3_16";
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Redmond_port";
	ch.location.group = "goto";
	ch.location.locator = "soldier_2";
	ch.Dialog.Filename = "redmond soldier_dialog.c";
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

	//Ragetti
	ch.old.name = "Ragetti and";
	ch.old.lastname = "Pintel";
	ch.name = TranslateString("", "Ragetti");
	ch.lastname = "";
	ch.id		= "Ragetti";
	ch.model	= "Ragetti"; // Thomas the Terror
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Ragetti_dialog.c";
	ch.rank 	= 28;
	ch.reputation = "15";
	ch.experience = CalculateExperienceFromRank(28)+ (CalculateExperienceFromRank(28)/10 + rand(28000));;
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "8";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "100";
	ch.quest.officerprice = "500";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 280.0, 280.0);
	ch.greeting = "Gr_Pirate";
	ch.quest.officertype = OFFIC_TYPE_CANNONEER; 
	AddGameCharacter(n, ch);

	//Pintel
	ch.old.name = "Ragetti and";
	ch.old.lastname = "Pintel";
	ch.name = TranslateString("", "Pintel");
	ch.lastname = "";
	ch.id		= "Pintel";
	ch.model	= "Pintel";		//JRH
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Pintel_dialog.c";
	ch.rank 	= 28;
	ch.reputation = "15";
	ch.experience = CalculateExperienceFromRank(28)+ (CalculateExperienceFromRank(28)/10 + rand(28000));;
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "8";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "100";
	ch.quest.officerprice = "500";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 280.0, 280.0);
	ch.greeting = "Gr_Pirate";
	ch.quest.officertype = OFFIC_TYPE_CANNONEER;
	AddGameCharacter(n, ch);

	// Bartolomeu o Portugues
	ch.old.name 	= "Bartolomeu";
	ch.old.lastname 	= "o Portugues";
	ch.name 	= TranslateString("", "Bartolomeu");
	ch.lastname 	= TranslateString("", "o Portugues");
	ch.id		= "Bartolomeu o Portugues";
	ch.model = "GypsyCaptn_1";
	ch.sound_type = "pirate";
	ch.sex = "man";
	ch.loyality = 7;
	ch.alignment = "bad";
	GiveItem2Character(ch, "blade14");
	ch.equip.blade = "blade14";
	ch.nation	= PORTUGAL;
	GiveItem2Character(ch, "pistol1");
	ch.equip.gun = "pistol1";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.location	= "None";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "soldier_dialog.c";
	ch.greeting = "Gr_Bartolomeu o Portugues";
	ch.rank 	= 9;
	ch.reputation = "50";
	TakeNItems(ch,"medical1", Rand(4)+1);
	ch.experience = CalculateExperienceFromRank(9)+ (CalculateExperienceFromRank(9)/10 + rand(9000));
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "5";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "2";
	ch.money = "0";
	ch.quest.meeting = "0";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.Gunman = true;
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 150.0, 150.0);
	ch.HPBonus = 100;		// KevAtl 08-26-2007 to correct for game giving low HP
	LAi_NoRebirthEnable(ch);
	AddGameCharacter(n, ch);

	// John Paul Jones
	ch.old.name 	= "John";
	ch.old.lastname 	= "Paul Jones";
	ch.name 	= TranslateString("","John");
	ch.lastname 	= TranslateString("","Paul Jones");
	ch.id		= "John Paul Jones";
	ch.model = "JP_Jones_adm";
	ch.sound_type = "pirate";
	ch.sex = "man";
	ch.loyality = 7;
	ch.alignment = "bad";
	GiveItem2Character(ch, "blade14");
	ch.equip.blade = "blade14";
	ch.nation	= ENGLAND;
	GiveItem2Character(ch, "pistol1");
	ch.equip.gun = "pistol1";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.location	= "None";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "soldier_dialog.c";
	ch.greeting = "Gr_Bartolomeu o Portugues";
	ch.rank 	= 9;
	ch.reputation = "50";
	TakeNItems(ch,"medical1", Rand(4)+1);
	ch.experience = CalculateExperienceFromRank(9)+ (CalculateExperienceFromRank(9)/10 + rand(9000));
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "5";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "2";
	ch.money = "0";
	ch.quest.meeting = "0";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.Gunman = true;
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 150.0, 150.0);
	ch.HPBonus = 100;		// KevAtl 08-26-2007 to correct for game giving low HP
	LAi_NoRebirthEnable(ch);
	SetRank(ch, ENGLAND, 7);
	AddGameCharacter(n, ch);

	// Captain Seb'
	ch.old.name 	= "Captain";
	ch.old.lastname 	= "Seb'";
	ch.name 	= TranslateString("", "Captain");
	ch.lastname 	= TranslateString("", "Seb'");
	ch.id		= "Captain Seb'";
	ch.model = "brtcpt2_18";
	ch.sound_type = "pirate";
	ch.sex = "man";
	ch.loyality = 7;
	ch.alignment = "bad";
	GiveItem2Character(ch, "blade14");
	ch.equip.blade = "blade14";
	ch.nation	= PORTUGAL;
	GiveItem2Character(ch, "pistol1");
	ch.equip.gun = "pistol1";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.location	= "None";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "soldier_dialog.c";
	ch.greeting = "Gr_Bartolomeu o Portugues";
	ch.rank 	= 9;
	ch.reputation = "50";
	TakeNItems(ch,"medical1", Rand(4)+1);
	ch.experience = CalculateExperienceFromRank(9)+ (CalculateExperienceFromRank(9)/10 + rand(9000));
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "5";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "2";
	ch.money = "0";
	ch.quest.meeting = "0";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.Gunman = true;
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 150.0, 150.0);
	ch.HPBonus = 100;		// KevAtl 08-26-2007 to correct for game giving low HP
	LAi_NoRebirthEnable(ch);
	AddGameCharacter(n, ch);

	ch.old.name = "Hylie";
	ch.old.lastname = "Pistof";
	ch.name = TranslateString("", "Hylie");
	ch.lastname = TranslateString("", "Pistof");
	ch.id		= "Hylie Pistof";
	ch.model	= "Eugene_Martin";
	ch.sex = "man";
	ch.loyality = 15;
	ch.alignment = "good";
	ch.sound_type = "seaman";
	ch.nation	= PIRATE;
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Hylie Pistof_dialog.c";
	ch.Dialog.Filename.GroupDialog = "tavern.c";
	ch.greeting = "Gr_Everard Gordon";
	ch.rank 	= 28;
	ch.reputation = "64";
	TakeNItems(ch,"medical1", Rand(4)+1);
	ch.experience = "2050000";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "10";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "8";
	ch.skill.Repair = "10";
	ch.skill.Defence = "10";
	ch.skill.Commerce = "5";
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
	ch.money = "122";
	LAi_SetBarmanType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	LAi_SetHP(ch, 280.0, 280.0);
	ch.HPBonus = 200;			// Petros  to correct for game only giving 96
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	AddGameCharacter(n, ch);
// Early Days & CoTBP <-- 

// Chevalle quest -->
	//  crew
	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = "";
	ch.id		= "Chevalle_pirate_01";
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
	ch.id		= "Chevalle_pirate_02";
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
	ch.id		= "Chevalle_pirate_03";
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
	ch.id		= "Chevalle_pirate_04";
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
	ch.id		= "Chevalle_pirate_05";
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
	ch.id		= "Chevalle_pirate_06";
	ch.model	= "pirat6";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "goto4";
	ch.Dialog.Filename = "Chevallepirate_Dialog.c";
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

	ch.old.name = "Jean-Bart";
	ch.old.lastname = "Lafin";
	ch.name = TranslateString("", "Jean-Bart");
	ch.lastname = TranslateString("", "Lafin");
	ch.id		= "Jean-Bart Lafin";
	ch.model	= "Corsair1_4"; // Thomas the Terror
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

	ch.old.name = "Johan";
	ch.old.lastname = "Klaesz";
	ch.name = TranslateString("", "Johan");
	ch.lastname = TranslateString("", "Klaesz");
	ch.id		= "Johan Klaesz";
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
// Chevalle quest <--

// Eduardo Villanueva quest -->
	// Captain Eduardo Villanueva
	ch.old.name 	= "Eduardo";
	ch.old.lastname 	= "Villanueva";
	ch.name 	= TranslateString("", "Eduardo");
	ch.lastname 	= TranslateString("", "Villanueva");
	ch.id		= "Eduardo Villanueva";
	ch.model = "Villanueva"; // JRH
	ch.sound_type = "pirate";
	ch.sex = "man";
	ch.loyality = 7;
	ch.alignment = "bad";
	GiveItem2Character(ch, "blade14");
	ch.equip.blade = "blade14";
	ch.nation	= SPAIN;
	GiveItem2Character(ch, "pistol1");
	ch.equip.gun = "pistol1";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Ship.Name = TranslateString("","Sargento");
	ch.Ship.Type = "SP_Neptunus";
	ch.Ship.Stopped = true;
	ch.Flags.Pirate = 20; // PB: Eduardo Villanueva Pirate Flag
	ch.Flags.Pirate.texture = 0;
	ch.Dialog.Filename = "Eduardo Villanueva_dialog.c";
	ch.greeting = "Gr_Eduardo Villanueva";
	ch.rank 	= 9;
	ch.reputation = "50";
	TakeNItems(ch,"medical1", Rand(4)+1);
	ch.experience = CalculateExperienceFromRank(9)+ (CalculateExperienceFromRank(9)/10 + rand(9000));
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "5";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "3";
	ch.money = "0";
	ch.quest.meeting = "0";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.Gunman = true;
	//LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 150.0, 150.0);
	ch.HPBonus = 100;		// KevAtl 08-26-2007 to correct for game giving low HP
	LAi_NoRebirthEnable(ch);
	AddGameCharacter(n, ch);

	// Francois de Hadoque
	ch.old.name = "Francois";
	ch.old.lastname = "de Hadoque";
	ch.name = TranslateString("", "Francois");
	ch.lastname = TranslateString("", "de Hadoque");
	ch.id		= "Francois de Hadoque";
	ch.model	= "Hadoque";
	ch.nation	= FRANCE;
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Ship.Name = TranslateString("","La Licorne");
	ch.Ship.Type = "FR_Licorne";
	ch.Ship.Stopped = true; 
	ch.Dialog.Filename = "Francois de Hadoque_dialog.c";
	ch.rank 	= 10;
	ch.reputation = "None";
	ch.experience = "0";
	ch.greeting = "Gr_Francois de Hadoque";
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
// Eduardo Villanueva quest <--

// Sumbhajee quest -->
		// Sri Sumbhajee Angria
	ch.old.name = "Sri Sumbhajee";
	ch.old.lastname = "Angria";
	ch.name = TranslateString("", "Sri Sumbhajee");
	ch.lastname = TranslateString("", "Angria");
	ch.id		= "Sumbhajee";
	ch.model	= "Sri_Sumbhajee"; //Thomas the Terror
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Sri Sumbhajee_dialog.c";
	ch.greeting = "Gr_Sri Sumbhajee";
	ch.Flags.Pirate = 3; // JRH: Sri Sumbajee's Pirate Flag
	ch.Flags.Pirate.texture = 4;
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
	ch.money = "0";
	ch.quest.Sumbhajee = "";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "DOUWESEN_CITIZENS");
	AddGameCharacter(n, ch);

		// Sambhajee's Aid2
	ch.old.name = "Pusasn";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Pusasn");
	ch.lastname = "";
	ch.id		= "Sumbhajee Aid2";
	ch.model	= "Sri_Sumbhajee_aid"; 		//JRH
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Sumbhajee Aid2_dialog.c";
	ch.greeting = "Gr_Toff Oremans";
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
	ch.money = "0";
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "DOUWESEN_CITIZENS");
	AddGameCharacter(n, ch);

		//Sumbhajee's Aid1
	ch.old.name = "Askay";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Askay");
	ch.lastname = "";
	ch.id		= "Sumbhajee Aid1";
	ch.model	= "Sri_Sumbhajee_aid"; 		//JRH
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Sumbhajee Aid1_dialog.c";
	ch.greeting = "Gr_Toff Oremans";
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
	ch.money = "0";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "DOUWESEN_CITIZENS");
	AddGameCharacter(n, ch);
// Sumbhajee

// Captain Sao Feng/Ammand the Corsair
			// Ammand the Corsair
	ch.old.name = "Ammand";
	ch.old.lastname = "the Corsair";
	ch.name = TranslateString("", "Ammand");
	ch.lastname = TranslateString("", "the Corsair");
	ch.id		= "Ammand";
	ch.model	= "couchcaptaincharles"; // Replace with Ammand
	ch.sex = "man";
	LAi_NoRebirthEnable(ch);
	ch.sound_type = "male_citizen";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Ammand_dialog.c";
	ch.greeting = "Gr_Ammand";
	ch.Flags.Pirate = 2; // JRH: Ammand the Corsair's Pirate Flag
	ch.Flags.Pirate.texture = 4;
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

			// Sao Feng
	ch.old.name = "Captain Sao";
	ch.old.lastname = "Feng";
	ch.name = TranslateString("", "Captain Sao");
	ch.lastname = TranslateString("", "Feng");
	ch.id		= "Sao Feng";
	ch.model	= "SaoFeng";
	ch.sex = "man";
	LAi_NoRebirthEnable(ch);
	ch.sound_type = "male_citizen";
	ch.location	= "turks_townhall";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
	ch.Dialog.Filename = "Sao Feng_dialog.c";
	ch.Dialog.Filename.GroupDialog = "governor.c";
	ch.greeting = "Gr_Sao Feng";
	ch.Ship.Name = TranslateString("","Empress");
	ch.Ship.Type = "Empress";
	ch.Ship.Stopped = true;
	ch.Flags.Pirate = 4; // JRH&GR: Sao Feng's Pirate Pennant
	ch.Flags.Pirate.texture = 4;
	ch.Flags.Personal = 1;
	ch.Flags.Personal.texture = 0;
	ch.nation = PIRATE;
	ch.rank 	= 1;
	GiveItem2Character(ch, "bladeC36");
	ch.equip.blade = "bladeC36";
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
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			// Sao Feng Bodyguard1
	ch.old.name = "Park";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Park");
	ch.lastname = "";
	ch.id		= "Sao Feng's body1";
	ch.model	= "SaoFeng_guard";	//JRH
	ch.model.animation = "33_Blazie"; // PB
	ch.sex	  =  "woman";
	LAi_NoRebirthEnable(ch);
	ch.sound_type = "female_citizen";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Sao Feng's body_dialog.c";
	ch.greeting = "Gr_Sao Feng's body";
	ch.nation = HOLLAND;
	GiveItem2Character(ch, "bladeC36");
	ch.equip.blade = "bladeC36";
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
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			// Sao Feng Bodyguard2
	ch.old.name = "Lian";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Lian");
	ch.lastname = "";
	ch.id		= "Sao Feng's body2";
	ch.model	= "SaoFeng_guard";	//JRH
	ch.model.animation = "33_Blazie"; // PB
	ch.sex	  =  "woman";
	LAi_NoRebirthEnable(ch);
	ch.sound_type = "female_citizen";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Sao Feng's body_dialog.c";
	ch.greeting = "Gr_Sao Feng's body";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "bladeC36");
	ch.equip.blade = "bladeC36";
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
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			// Tai Huang
	ch.old.name = "Tai";
	ch.old.lastname = "Huang";
	ch.name = TranslateString("", "Tai");
	ch.lastname = TranslateString("", "Huang");
	ch.id		= "Tai Huang";
	ch.model	= "mongol";
	ch.sex = "man";
	LAi_NoRebirthEnable(ch);
	ch.sound_type = "male_citizen";
	ch.location	= "none";
	ch.location.group = "sit";
	ch.location.locator = "sit5";
	ch.Dialog.Filename = "Tai Huang_dialog.c";
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
	ch.greeting = "Gr_Tai Huang";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			// Short Jack
	ch.old.name = "Short";
	ch.old.lastname = "Jack";
	ch.name = TranslateString("", "Short");
	ch.lastname = TranslateString("", "Jack");
	ch.id		= "Short Jack";
	ch.model	= "pirat15";
	ch.sex = "man";
	LAi_NoRebirthEnable(ch);
	ch.sound_type = "male_citizen";
	ch.location	= "none";
	ch.location.group = "sit";
	ch.location.locator = "sit7";
	ch.Dialog.Filename = "Short Jack_dialog.c";
	ch.nation = ENGLAND;
	GiveItem2Character(ch, "commonarmor");
	ch.equip.armor = "commonarmor";
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
	ch.greeting = "Gr_Short Jack";
	ch.questchar = true;//MAXIMUS: identifier for captives
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
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Mergildo Hurtado_dialog.c";
	ch.Ship.Name = TranslateString("","Montanez");
	ch.Ship.Type = "Barque1"; // PRS3
	ch.Ship.Stopped = true;
	ch.nosurrender = 2; // PB
	ch.skipFalseFlag = true; // PB: Skip False Flag Detection
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
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
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

	ch.old.name = "Marbatico";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Marbatico");
	ch.lastname = "";
	ch.id		= "Mystery_Man_01";
	ch.model	= "33_Ronal2";
	ch.model.animation = "33_Ronald";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.act.escape = 0;
	ch.activity_begin = "0";
	ch.activity_end = "24";
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade5");
	ch.equip.blade = "blade5";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "none";//"Redmond"; //redmond_shore_01
	ch.location.group = "";
	ch.location.locator = "";//locator8
	ch.Dialog.Filename = "Quest_ANIMISTS_dialog.c";
	ch.greeting = "Gr_Quest_ANIMISTS";
	ch.Ship.Name = TranslateString("","Hundred Devils"); // KK
	ch.Ship.Type = "Barque2"; // PRS3
	ch.Ship.Stopped = true;
	ch.skipRM = true; // PB: Skip Relations Mod
// KK -->
	ch.Ship.EmblemedSails.normalTex = "sail_whole_red_plain.tga"; // PB
	ch.Ship.EmblemedSails.nationFileName = "sail_whole_red_plain.tga"; // PB
	ch.nosurrender = 2;
	ch.boardingmodels = "OUTLAWS";
// <-- KK
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

	ch.old.name = "Masked Man";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Masked Man");
	ch.lastname = "";
	ch.id		= "Mystery_Man_02";
	ch.model = "mask";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.act.escape = 0;
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade5");
	ch.equip.blade = "blade5";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "none";//"Redmond"; //redmond_shore_01
	ch.location.group = "";
	ch.location.locator = "";//locator8
	ch.Dialog.Filename = "Quest_ANIMISTS_dialog.c";
	ch.old.Dialog.Filename = ch.Dialog.Filename; // KK
	ch.greeting = "Gr_Quest_ANIMISTS";
	ch.Ship.Name = TranslateString("","666"); // KK
	ch.Ship.Type = "Brig2"; // PRS3
	ch.Ship.Stopped = true;
	ch.skipRM = true; // PB: Skip Relations Mod
// KK -->
	ch.Ship.EmblemedSails.normalTex = "sail_whole_red_plain.tga"; // PB
	ch.Ship.EmblemedSails.nationFileName = "sail_whole_red_plain.tga"; // PB
	ch.nosurrender = 2;
	ch.boardingmodels = "OUTLAWS";
// <-- KK
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

	ch.old.name = "Masked Man";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Masked Man");
	ch.lastname = "";
	ch.id		= "Mystery_Man_03";
	ch.model = "mask_2";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.act.escape = 0;
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade5");
	ch.equip.blade = "blade5";
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

	ch.old.name = "Masked Man";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Masked Man");
	ch.lastname = "";
	ch.id		= "Mystery_Man_04";
	ch.model = "mask_3";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.act.escape = 0;
	ch.activity_begin = "0";
	ch.activity_end = "24";
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade5");
	ch.equip.blade = "blade5";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "none";//"Redmond"; //redmond_shore_01
	ch.location.group = "";
	ch.location.locator = "";//locator8
	ch.Dialog.Filename = "Quest_ANIMISTS_dialog.c";
	ch.greeting = "Gr_Quest_ANIMISTS";
	ch.Ship.Name = TranslateString("","Hundred Devils"); // KK
	ch.Ship.Type = "Barque2"; // PRS3
	ch.Ship.Stopped = true;
	ch.skipRM = true; // PB: Skip Relations Mod
// KK -->
	ch.Ship.EmblemedSails.normalTex = "sail_whole_red_plain.tga"; // PB
	ch.Ship.EmblemedSails.nationFileName = "sail_whole_red_plain.tga"; // PB
	ch.nosurrender = 2;
	ch.boardingmodels = "OUTLAWS";
// <-- KK
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

	ch.old.name = "Old Salt";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Old Salt");
	ch.lastname = "";
	ch.id		= "Mystery_Man_05";
	ch.model = "salt"; //mask salt
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.act.escape = 0;
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade5");
	ch.equip.blade = "blade5";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "none";//"Redmond"; //redmond_shore_01
	ch.location.group = "";
	ch.location.locator = "";//locator8
	ch.Dialog.Filename = "Quest_ANIMISTS_dialog.c";
	ch.old.Dialog.Filename = ch.Dialog.Filename; // KK
	ch.greeting = "Gr_Quest_ANIMISTS";
	ch.Ship.Name = TranslateString("","666"); // KK
	ch.Ship.Type = "Brig2"; // PRS3
	ch.Ship.Stopped = true;
	ch.skipRM = true; // PB: Skip Relations Mod
// KK -->
	ch.Ship.EmblemedSails.normalTex = "sail_whole_red_plain.tga"; // PB
	ch.Ship.EmblemedSails.nationFileName = "sail_whole_red_plain.tga"; // PB
	ch.nosurrender = 2;
	ch.boardingmodels = "OUTLAWS";
// <-- KK
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

	ch.old.name = "Meigger";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Meigger");
	ch.lastname = "";
	ch.id		= "Mystery_Man_06";
	ch.model = "pirat9"; //pirat9 mask
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.act.escape = 0;
	ch.activity_begin = "0";
	ch.activity_end = "24";
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade5");
	ch.equip.blade = "blade5";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "none";//"Redmond"; //redmond_shore_01
	ch.location.group = "";
	ch.location.locator = "";//locator8
	ch.Dialog.Filename = "Quest_ANIMISTS_dialog.c";
	ch.greeting = "Gr_Quest_ANIMISTS";
	ch.Ship.Name = TranslateString("","Hundred Devils"); // KK
	ch.Ship.Type = "Barque2"; // PRS3
	ch.Ship.Stopped = true;
	ch.skipRM = true; // PB: Skip Relations Mod
// KK -->
	ch.Ship.EmblemedSails.normalTex = "sail_whole_red_plain.tga"; // PB
	ch.Ship.EmblemedSails.nationFileName = "sail_whole_red_plain.tga"; // PB
	ch.nosurrender = 2;
	ch.boardingmodels = "OUTLAWS";
// <-- KK
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

	ch.old.name = "Masked Man";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Masked Man");
	ch.lastname = "";
	ch.id		= "Mystery_Man_07";
	ch.model = "mask_4";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.act.escape = 0;
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade5");
	ch.equip.blade = "blade5";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "none";//"Redmond"; //redmond_shore_01
	ch.location.group = "";
	ch.location.locator = "";//locator8
	ch.Dialog.Filename = "Quest_ANIMISTS_dialog.c";
	ch.old.Dialog.Filename = ch.Dialog.Filename; // KK
	ch.greeting = "Gr_Quest_ANIMISTS";
	ch.Ship.Name = TranslateString("","666"); // KK
	ch.Ship.Type = "Brig2"; // PRS3
	ch.Ship.Stopped = true;
	ch.skipRM = true; // PB: Skip Relations Mod
// KK -->
	ch.Ship.EmblemedSails.normalTex = "sail_whole_red_plain.tga"; // PB
	ch.Ship.EmblemedSails.nationFileName = "sail_whole_red_plain.tga"; // PB
	ch.nosurrender = 2;
	ch.boardingmodels = "OUTLAWS";
// <-- KK
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

	ch.old.name = "Masked Man";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Masked Man");
	ch.lastname = "";
	ch.id		= "Mystery_Man_08";
	ch.model = "mask";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.act.escape = 0;
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade5");
	ch.equip.blade = "blade5";
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

	ch.old.name = "Masked Man";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Masked Man");
	ch.lastname = "";
	ch.id		= "Mystery_Man_09";
	ch.model = "mask_2";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.act.escape = 0;
	ch.activity_begin = "0";
	ch.activity_end = "24";
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade5");
	ch.equip.blade = "blade5";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "none";//"Redmond"; //redmond_shore_01
	ch.location.group = "";
	ch.location.locator = "";//locator8
	ch.Dialog.Filename = "Quest_ANIMISTS_dialog.c";
	ch.greeting = "Gr_Quest_ANIMISTS";
	ch.Ship.Name = TranslateString("","Hundred Devils"); // KK
	ch.Ship.Type = "Barque2"; // PRS3
	ch.Ship.Stopped = true;
	ch.skipRM = true; // PB: Skip Relations Mod
// KK -->
	ch.Ship.EmblemedSails.normalTex = "sail_whole_red_plain.tga"; // PB
	ch.Ship.EmblemedSails.nationFileName = "sail_whole_red_plain.tga"; // PB
	ch.nosurrender = 2;
	ch.boardingmodels = "OUTLAWS";
// <-- KK
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

	ch.old.name = "Masked Man";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Masked Man");
	ch.lastname = "";
	ch.id		= "Mystery_Man_10";
	ch.model = "mask_3";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.act.escape = 0;
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade5");
	ch.equip.blade = "blade5";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "none";//"Redmond"; //redmond_shore_01
	ch.location.group = "";
	ch.location.locator = "";//locator8
	ch.Dialog.Filename = "Quest_ANIMISTS_dialog.c";
	ch.old.Dialog.Filename = ch.Dialog.Filename; // KK
	ch.greeting = "Gr_Quest_ANIMISTS";
	ch.Ship.Name = TranslateString("","666"); // KK
	ch.Ship.Type = "Brig2"; // PRS3
	ch.Ship.Stopped = true;
	ch.skipRM = true; // PB: Skip Relations Mod
// KK -->
	ch.Ship.EmblemedSails.normalTex = "sail_whole_red_plain.tga"; // PB
	ch.Ship.EmblemedSails.nationFileName = "sail_whole_red_plain.tga"; // PB
	ch.nosurrender = 2;
	ch.boardingmodels = "OUTLAWS";
// <-- KK
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

	ch.old.name = "Masked Man";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Masked Man");
	ch.lastname = "";
	ch.id		= "Mystery_Man_11";
	ch.model = "mask_4";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.act.escape = 0;
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade5");
	ch.equip.blade = "blade5";
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

	ch.old.name = "Stallion";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Stallion");
	ch.lastname = "";
	ch.id		= "Teacher";
	ch.model = "DO_Assasin1";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.act.escape = 0;
	ch.activity_begin = "0";
	ch.activity_end = "24";
	LAi_NoRebirthEnable(ch);
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade5");
	ch.equip.blade = "blade5";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "none";//"Redmond"; //redmond_shore_01
	ch.location.group = "";
	ch.location.locator = "";//locator8
	ch.Dialog.Filename = "Quest_ANIMISTS_dialog.c";
	ch.greeting = "Gr_Quest_ANIMISTS";
	ch.Ship.Name = TranslateString("","Hundred Devils"); // KK
	ch.Ship.Type = "Barque2"; // PRS3
	ch.Ship.Stopped = true;
	ch.skipRM = true; // PB: Skip Relations Mod
// KK -->
	ch.Ship.EmblemedSails.normalTex = "sail_whole_red_plain.tga"; // PB
	ch.Ship.EmblemedSails.nationFileName = "sail_whole_red_plain.tga"; // PB
	ch.nosurrender = 2;
	ch.boardingmodels = "OUTLAWS";
// <-- KK
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

	ch.old.name = "Skyliner";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Skyliner");
	ch.lastname = "";
	ch.id		= "Dark Captain";
	ch.model = "Capstan";
	ch.sex = "man";
	ch.sound_type = "pirate";
	LAi_NoRebirthEnable(ch);
	ch.Ship.AI.GroupName = "Ethilrede Claar";
	ch.Ship.AI.Task = "attack";
	ch.nation = PIRATE;
//	GiveItem2Character(ch, "blade4");
//	ch.equip.blade = "blade4";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Gyles Dubois_dialog.c";
	ch.Ship.Name = TranslateString("","Crimson Blood");
	ch.Ship.Type = "CrimsonBlood"; // Cylon13
	ch.Ship.Stopped = true;
	ch.Ship.EmblemedSails.normalTex = "sail_Petros_black_red.tga"; // PB
	ch.Ship.EmblemedSails.nationFileName = "sail_Petros_black_red.tga"; // PB
	ch.skipRM = true; // PB: Skip Relations Mod
	ch.Flags.Pirate = 6; // GR: Animists Pirate Flag
	ch.Flags.Pirate.texture = 1;
	ch.boardingmodels = "OUTLAWS";
	ch.nosurrender = -1;
	GiveItem2Character(ch, "commonarmor");
	ch.equip.armor = "commonarmor";
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
	LAi_SetHuberStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_Gyles Dubois";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Masked Man";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Masked Man");
	ch.lastname = "";
	ch.id		= "Masked Man_01";
	ch.model = "mask";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Turks_Cavern_01";
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

	ch.old.name = "Masked Man";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Masked Man");
	ch.lastname = "";
	ch.id		= "Masked Man_02";
	ch.model = "mask_2";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Turks_Cavern_01";
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

	ch.old.name = "Masked Man";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Masked Man");
	ch.lastname = "";
	ch.id		= "Masked Man_03";
	ch.model = "mask_3";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Turks_Cavern_01";
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

	ch.old.name = "Masked Man";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Masked Man");
	ch.lastname = "";
	ch.id		= "Masked Man_04";
	ch.model = "mask_4";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Turks_Cavern_01";
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

	ch.old.name = "Masked Man";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Masked Man");
	ch.lastname = "";
	ch.id		= "Masked Man_05";
	ch.model = "mask";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Turks_Cavern_01";
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

	ch.old.name = "Masked Man";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Masked Man");
	ch.lastname = "";
	ch.id		= "Masked Man_06";
	ch.model = "mask_2";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Turks_Cavern_01";
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

	ch.old.name = "Masked Man";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Masked Man");
	ch.lastname = "";
	ch.id		= "Masked Man_07";
	ch.model = "mask_3";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Turks_Cavern_01";
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

	ch.old.name = "Masked Man";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Masked Man");
	ch.lastname = "";
	ch.id		= "Masked Man_08";
	ch.model = "mask_4";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Turks_Cavern_01";
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

	ch.old.name = "Masked Man";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Masked Man");
	ch.lastname = "";
	ch.id		= "Masked Man_09";
	ch.model = "mask";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Turks_Cavern_01";
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
	ch.old.name = "Morgan";
	ch.old.lastname = "Terror";
	ch.name = TranslateString("","Morgan");
	ch.lastname = TranslateString("","Terror");
	ch.id		= "Dark Teacher";
	ch.model	= "Terror";
	ch.sex = "man";
	ch.sound_type = "priest";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade20");
	ch.equip.blade = "blade20";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "Turks_Cavern_01";
	ch.location.group = "goto";
	ch.location.locator = "goto28";
	ch.Dialog.Filename = "Dark teacher_dialog.c";
	ch.rank 	= 1;
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
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 120.0, 120.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);
// Captian Sao Feng/Ammand the Corsair

// Gentleman Jocard
	ch.old.name = "Bos'un";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Bos'un");
	ch.lastname = "";
	ch.id		= "Bos'un";
	ch.model	= "BlackCaesar"; 
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Bos'un_dialog.c";
	ch.rank 	= 28;
	ch.reputation = "15";
	ch.experience = CalculateExperienceFromRank(28)+ (CalculateExperienceFromRank(28)/10 + rand(28000));;
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "8";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "100";
	ch.quest.officerprice = "500";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 280.0, 280.0);
	ch.greeting = "Gr_Pirate";
	ch.quest.officertype = OFFIC_TYPE_BOATSWAIN; 
	AddGameCharacter(n, ch);

// Dead Man's Chest -->
	// Joaquin Da Saldanha
	ch.old.name = "Joaquin";
	ch.old.lastname = "Da Saldanha";
	ch.name = TranslateString("", "Joaquin");
	ch.lastname = TranslateString("", "Da Saldanha");
	ch.id		= "Joaquin Da Saldanha";
	ch.model = "spa_adm_18_2";	// was "admiral"
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	GiveItem2Character(ch, "pistol1");
	ch.equip.gun = "pistol1";
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

	// Justine Le Moigne
	ch.old.name = "Justine";
	ch.old.lastname = "Le Moigne";
	ch.name = TranslateString("", "Justine");
	ch.lastname = TranslateString("", "Le Moigne");
	ch.id		= "Arabella Silehard";
	ch.model = "50_Petra2";
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

	// Justine's Guard 1
	ch.old.name = "Justine's guard";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Justine's guard");
	ch.lastname = "";
	ch.id		= "Arabella's guard 1";
	ch.model	= Nations[FRANCE].fantomModel.m0; // PB
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	GiveItem2Character(ch, "pistol1");
	ch.equip.gun = "pistol1";
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

	// Justine's Guard 2
	ch.old.name = "Justine's guard";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Justine's guard");
	ch.lastname = "";
	ch.id		= "Arabella's guard 2";
	ch.model	= Nations[FRANCE].fantomModel.m0; // PB
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	GiveItem2Character(ch, "pistol1");
	ch.equip.gun = "pistol1";
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

	// Ransom Pirate 1
	ch.old.name = "John";
	ch.old.lastname = "Smith";
	ch.name = TranslateString("", "John");
	ch.lastname = TranslateString("", "Smith");
	ch.id		= "John Smith";
	ch.model = "Buccaneer1";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	GiveItem2Character(ch, "pistol1");
	ch.equip.gun = "pistol1";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.location = "none";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "John Smith_dialog.c";
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

	// Ransom Pirate 2
	ch.old.name = "Snorri";
	ch.old.lastname = "Baldursson";
	ch.name = TranslateString("", "Snorri");
	ch.lastname = TranslateString("", "Baldursson");
	ch.id		= "Snorri Baldursson";
	ch.model = "sailor6";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
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

	// Ransom Pirate 3
	ch.old.name = "Francis";
	ch.old.lastname = "Snake";
	ch.name = TranslateString("", "Francis");
	ch.lastname = TranslateString("", "Snake");
	ch.id		= "Francis Snake";
	ch.model = "corsair1_1";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
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

	// Captain Maggee
	ch.old.name = "Captain";
	ch.old.lastname = "Maggee";
	ch.name = TranslateString("","Captain");
	ch.lastname = TranslateString("","Maggee");
	ch.id		= "Captain Maggee";
	ch.model = "corsair1_1";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	//--> CTM
	ch.Ship.Name = TranslateString("","Van Diemen");
	ch.Ship.Type = "RN_RevengeW";
	ch.Ship.Stopped = true;
	//<-- CTM
	ch.rank 	= 30;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "10";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "5";
	ch.skill.Defence = "7";
	ch.skill.Commerce = "6";
	ch.skill.Sneak = "4";
	ch.money = "100";
	ch.quest.meeting = "0";
	ch.Dialog.Filename = "Captain Maggee_dialog.c";
	ch.greeting = "Gr_Captain Maggee";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 200.0, 200.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	// Reynoud Verheugen
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
	ch.Ship.Type = "obj_Boat2"; 				//SfsiWreck		
	ch.Ship.Stopped = true;
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

	// Justine Le Moigne
	ch.old.name = "Justine";
	ch.old.lastname = "Le Moigne";
	ch.name = TranslateString("", "Justine");
	ch.lastname = TranslateString("", "Le Moigne");
	ch.id		= "Elizabeth Shaw";
	ch.model = "50_Petra2";
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

	//  Davy's crewmember1
	ch.old.name = "Palafico"; // PB
	ch.old.lastname = "";
	ch.name = TranslateString("", "Palafico"); // PB
	ch.lastname = "";
	ch.id		= "Davycrew_01";
	ch.model	= "Palafico";
	ch.model.animation = "Rousselet";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade1");
	ch.equip.blade = "blade1";
	GiveItem2Character(ch, "pistol1");
	ch.equip.gun = "pistol1";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
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

	//  Davy's crewmember2
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
	GiveItem2Character(ch, "pistol1");
	ch.equip.gun = "pistol1";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
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

	ch.old.name = "Port Admiral";
	ch.old.lastname = "Talicerdor";
	ch.name 	= TranslateString("", "Port Admiral");
	ch.lastname = TranslateString("", "Talicerdor");
	ch.id		= "Havana_Portadmiral";
	ch.model	= "spa_adm_18"; // Thomas the Terror
	ch.sex = "man";
	ch.nation = SPAIN;
	ch.location	= "Havana_House_03";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Havana_Portadmiral.c";
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
	LAi_SetSitType(ch);
	LAi_SetHP(ch, 200.0, 200.0);
	AddGameCharacter(n, ch);

				//Soldier на входе в город
	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Soldier");
	ch.lastname = "";
	ch.id		= "Hav_soldier_1";
	ch.model	= 3; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	ch.nation = SPAIN;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Havana_House_03";
	ch.location.group = "goto";
	ch.location.locator = "goto9";
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
	LAi_group_MoveCharacter(ch, "SPAIN_SOLDIERS");
	ch.greeting = "Gr_Redmond Soldier";
	AddGameCharacter(n, ch);

			//Soldier на входе в город
	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Soldier");
	ch.lastname = "";
	ch.id		= "Hav_soldier_2";
	ch.model	= 2; // PB
	ch.sound_type = "soldier";
	LAi_CharacterReincarnation(ch, true, false);
	ch.sex = "man";
	ch.nation = SPAIN;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Havana_House_03";
	ch.location.group = "goto";
	ch.location.locator = "goto6";
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
	LAi_group_MoveCharacter(ch, "SPAIN_SOLDIERS");
	ch.greeting = "Gr_Redmond Soldier";
	AddGameCharacter(n, ch);
	
	//DMC CHARACTERS//

    // Sailor at Turks Elton Garfield
	ch.old.name = "Elton";
	ch.old.lastname = "Garfield";
	ch.name = TranslateString("","Elton");
	ch.lastname = TranslateString("","Garfield");
	ch.id		= "Elton Garfield";
	ch.model = "corsair1_2";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.rank 	= 30;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "10";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "5";
	ch.skill.Defence = "7";
	ch.skill.Commerce = "6";
	ch.skill.Sneak = "4";
	ch.money = "100";
	ch.quest.meeting = "0";
	ch.Dialog.Filename = "Elton Garfield_dialog.c";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 200.0, 200.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	// Turks prison guard
	ch.old.name = "Prison";
	ch.old.lastname = "Guard";
	ch.name = TranslateString("Prison","Guard");
	ch.lastname = "";
	ch.id		= "turks_prison_guard1";
	ch.model = "50evl2in";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.rank 	= 30;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "10";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "5";
	ch.skill.Defence = "7";
	ch.skill.Commerce = "6";
	ch.skill.Sneak = "4";
	ch.money = "100";
	ch.quest.meeting = "0";
	ch.Dialog.Filename = "Turks_prison_guard1_dialog.c";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 200.0, 200.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);
	
	//Turks prison guard captain
	ch.old.name = "Guard";
	ch.old.lastname = "Captain";
	ch.name = TranslateString("Guard","Captain");
	ch.lastname = "";
	ch.id		= "prison_guard_captain";
	ch.model	= "Corsair5";
	ch.sound_type = "pirate";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.rank 	= 30;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "10";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "5";
	ch.skill.Defence = "7";
	ch.skill.Commerce = "6";
	ch.skill.Sneak = "4";
	ch.money = "100";
	ch.quest.meeting = "0";
	ch.Dialog.Filename = "Turks_prison_captain_dialog.c";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 200.0, 200.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	//Atwood Paddley
	ch.old.name = "Atwood";
	ch.old.lastname = "Paddley";
	ch.name = TranslateString("", "Atwood");
	ch.lastname = TranslateString("","Paddley");
	ch.id		= "Atwood Paddley";
	ch.model	= "Bocman";
	ch.sound_type = "pirate";
	ch.sex = "man";
	ch.sound_type = "pirate";
	//GiveItem2Character(ch, "blade4");
	//ch.equip.blade = "blade4";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.rank 	= 30;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "2";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "5";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "100";
	ch.quest.meeting = "0";
	ch.Dialog.Filename = "Atwood_Paddley_dialog.c";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 200.0, 200.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);
	
	//Cannibal chief
	ch.old.name = "Cannibal";
	ch.old.lastname = "Chief";
	ch.name = TranslateString("Cannibal","Chief");
	ch.lastname = "";	
	ch.id		= "Cannibal_chief";
	ch.model	= "RabBlack_1";
	ch.sound_type = "pirate";
	ch.sex = "man";
	ch.sound_type = "pirate";
	//GiveItem2Character(ch, "blade4");
	//ch.equip.blade = "blade4";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.rank 	= 30;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "2";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "5";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "100";
	ch.quest.meeting = "0";
	ch.Dialog.Filename = "slave_dialog.c";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 200.0, 200.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);
	
}
