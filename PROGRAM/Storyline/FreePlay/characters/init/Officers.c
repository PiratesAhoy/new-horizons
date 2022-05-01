void CreateOfficersCharacters(ref n)
{
	object chobj;
	ref ch;
	makeref(ch, chobj);

	//William Sullivan
	//First Mate
	ch.old.name = "William";
	ch.old.lastname = "Sullivan";
	ch.name = TranslateString("", "William");
	ch.lastname = TranslateString("", "Sullivan");
	ch.id		= "William Sullivan";
	ch.model	= "Corsair1_1";
	ch.sex = "man";
	ch.loyality = 15;
	ch.alignment = "good";
	ch.sound_type = "seaman";
	GiveItem2Character(ch, "bladeC30");
	GiveItem2Character(ch, "PiratesPistol");
	GiveItem2Character(ch, "powderflask");
	GiveItem2Character(ch, "ammopouch");
	ch.equip.blade = "bladeC30";
	ch.equip.gun = "PiratesPistol";
	ch.equip.blade = "powderflask";
	ch.equip.blade = "ammopouch";
    //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 12);
		TakenItems(ch, "pistolbullets", 12);
	}
    //JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Enc_Officer_dialog.c"; // KK
	ch.Dialog.CurrentNode = "Hired"; // KK
	ch.rank 	= 5;
	ch.reputation = "50";
	TakeNItems(ch,"medical1", Rand(4)+1);
	ch.experience = CalculateExperienceFromRank(5)+ (CalculateExperienceFromRank(5)/10 + rand(500));
	ch.skill.Leadership = "8";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.Toughness = true;
	ch.money = "1000";
	ch.quest.help = "0";
	ch.quest.dialog = "0";
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	ch.HPBonus = 100;		// KevAtl 08-26-2007 to correct for game giving low HP
	ch.quest.officertype = OFFIC_TYPE_FIRSTMATE;
	ch.isOfficer = true;
	AddGameCharacter(n, ch);

	//David O'Hara
	//Navigator
	ch.old.name = "David";
	ch.old.lastname = "O'Hara";
	ch.name = TranslateString("", "David");
	ch.lastname = TranslateString("", "O'Hara");
	ch.id		= "David O'Hara";
	ch.model	= "Corsair3_J";
	ch.sex = "man";
	ch.loyality = 15;
	ch.alignment = "good";
	ch.sound_type = "seaman";
	GiveItem2Character(ch, "bladeC26");
	GiveItem2Character(ch, "PiratesPistol");
	GiveItem2Character(ch, "powderflask");
	GiveItem2Character(ch, "ammopouch");
	ch.equip.blade = "bladeC26";
	ch.equip.gun = "PiratesPistol";
	ch.equip.blade = "powderflask";
	ch.equip.blade = "ammopouch";
    //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 12);
		TakenItems(ch, "pistolbullets", 12);
	}
    //JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Enc_Officer_dialog.c"; // KK
	ch.Dialog.CurrentNode = "Hired"; // KK
	ch.rank 	= 5;
	ch.reputation = "50";
	TakeNItems(ch,"medical1", Rand(4)+1);
	ch.experience = CalculateExperienceFromRank(5)+ (CalculateExperienceFromRank(5)/10 + rand(500));
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.ShipTurnRateUp = true;
	ch.perks.list.ShipSpeedUp = true;
	ch.perks.list.SandbankManeuver = true;
	ch.perks.list.StormProfessional = true;
	ch.money = "1000";
	ch.quest.help = "0";
	ch.quest.dialog = "0";
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	ch.HPBonus = 100;		// KevAtl 08-26-2007 to correct for game giving low HP
	ch.quest.officertype = OFFIC_TYPE_NAVIGATOR;
	ch.isOfficer = true;
	AddGameCharacter(n, ch);

	//Brian Darcy
	//Gunner
	ch.old.name = "Brian";
	ch.old.lastname = "Darcy";
	ch.name = TranslateString("", "Brian");
	ch.lastname = TranslateString("", "Darcy");
	ch.id		= "Brian Darcy";
	ch.model	= "capstan";
	ch.sex = "man";
	ch.loyality = 15;
	ch.alignment = "good";
	ch.sound_type = "seaman";
	GiveItem2Character(ch, "blade21");
	GiveItem2Character(ch, "PiratesPistol");
	GiveItem2Character(ch, "powderflask");
	GiveItem2Character(ch, "ammopouch");
	ch.equip.blade = "blade21";
	ch.equip.gun = "PiratesPistol";
	ch.equip.blade = "powderflask";
	ch.equip.blade = "ammopouch";
    //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 12);
		TakenItems(ch, "pistolbullets", 12);
	}
    //JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Enc_Officer_dialog.c"; // KK
	ch.Dialog.CurrentNode = "Hired"; // KK
	ch.rank 	= 5;
	ch.reputation = "50";
	TakeNItems(ch,"medical1", Rand(4)+1);
	ch.experience = CalculateExperienceFromRank(5)+ (CalculateExperienceFromRank(5)/10 + rand(500));
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.perks.list.FastReload = true;
	ch.perks.list.HullDamageUp = true;
	ch.perks.list.CrewDamageUp = true;
	ch.perks.list.SailsDamageUp = true;
	ch.perks.list.LongRangeShoot = true;
	ch.money = "1000";
	ch.quest.help = "0";
	ch.quest.dialog = "0";
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	ch.HPBonus = 100;		// KevAtl 08-26-2007 to correct for game giving low HP
	ch.quest.officertype = OFFIC_TYPE_CANNONEER;
	ch.isOfficer = true;
	AddGameCharacter(n, ch);

	//Killian Kildare
	//Boatswain
	ch.old.name = "Killian";
	ch.old.lastname = "Kildare";
	ch.name = TranslateString("", "Killian");
	ch.lastname = TranslateString("", "Kildare");
	ch.id		= "Killian Kildare";
	ch.model	= "CapJRMM";
	ch.sex = "man";
	ch.loyality = 15;
	ch.alignment = "good";
	ch.sound_type = "seaman";
	GiveItem2Character(ch, "bladeaxe2");
	GiveItem2Character(ch, "pistolbbuss");
	GiveItem2Character(ch, "powderflask");
	GiveItem2Character(ch, "ammopouch");
	GiveItem2Character(ch, "cured");
	ch.equip.blade = "blade21";
	ch.equip.gun = "PiratesPistol";
	ch.equip.blade = "powderflask";
	ch.equip.blade = "ammopouch";
	ch.equip.blade = "cured";
    //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 12);
		TakenItems(ch, "pistolgrapes", 12);
	}
    //JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Enc_Officer_dialog.c"; // KK
	ch.Dialog.CurrentNode = "Hired"; // KK
	ch.rank 	= 5;
	ch.reputation = "50";
	TakeNItems(ch,"medical1", Rand(4)+1);
	ch.experience = CalculateExperienceFromRank(5)+ (CalculateExperienceFromRank(5)/10 + rand(500));
	ch.skill.Leadership = "3";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.Toughness = true;
	ch.perks.list.LongRangeGrappling = true;
	ch.perks.list.GrapplingProfessional = true;
	ch.money = "1000";
	ch.quest.help = "0";
	ch.quest.dialog = "0";
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	ch.HPBonus = 100;		// KevAtl 08-26-2007 to correct for game giving low HP
	ch.quest.officertype = OFFIC_TYPE_BOATSWAIN;
	ch.isOfficer = true;
	AddGameCharacter(n, ch);

	//Emily Butler
	//Surgeon
	ch.old.name = "Emily";
	ch.old.lastname = "Butler";
	ch.name = TranslateString("", "Emily");
	ch.lastname = TranslateString("", "Butler");
	ch.id		= "Emily Butler";
	ch.model	= "Fanielle";
	ch.sex = "woman";
	ch.loyality = 15;
	ch.alignment = "good";
	ch.sound_type = "seaman";
	GiveItem2Character(ch, "bladeC6");
	GiveItem2Character(ch, "PiratesPistol");
	ch.equip.blade = "bladeC6";
	ch.equip.gun = "PiratesPistol";
    //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
    //JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Enc_Officer_dialog.c"; // KK
	ch.Dialog.CurrentNode = "Hired"; // KK
	ch.rank 	= 5;
	ch.reputation = "50";
	TakeNItems(ch,"medical1", Rand(4)+1);
	ch.experience = CalculateExperienceFromRank(5)+ (CalculateExperienceFromRank(5)/10 + rand(500));
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.BasicDamageControl = true;
	ch.perks.list.AdvancedDamageControl = true;
	ch.perks.list.ProfessionalDamageControl = true;
	ch.perks.list.Rigging = true;
	ch.perks.list.RiggingAdvance = true;
	ch.perks.list.SharedExperience = true;
	ch.money = "1000";
	ch.quest.help = "0";
	ch.quest.dialog = "0";
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	ch.HPBonus = 100;		// KevAtl 08-26-2007 to correct for game giving low HP
	ch.quest.officertype = OFFIC_TYPE_DOCTOR;
	ch.isOfficer = true;
	AddGameCharacter(n, ch);

	//Uriah O'Bannon
	//Carpenter
	ch.old.name = "Uriah";
	ch.old.lastname = "O'Bannon";
	ch.name = TranslateString("", "Uriah");
	ch.lastname = TranslateString("", "O'Bannon");
	ch.id		= "Uriah O'Bannon";
	ch.model	= "will_2";
	ch.sex = "man";
	ch.loyality = 15;
	ch.alignment = "good";
	ch.sound_type = "seaman";
	GiveItem2Character(ch, "blade21");
	GiveItem2Character(ch, "PiratesPistol");
	ch.equip.blade = "blade21";
	ch.equip.gun = "PiratesPistol";
    //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
    //JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Enc_Officer_dialog.c"; // KK
	ch.Dialog.CurrentNode = "Hired"; // KK
	ch.rank 	= 5;
	ch.reputation = "50";
	TakeNItems(ch,"medical1", Rand(4)+1);
	ch.experience = CalculateExperienceFromRank(5)+ (CalculateExperienceFromRank(5)/10 + rand(500));
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "8";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.LightRepair = true;
	ch.perks.list.InstantRepair = true;
	ch.perks.list.BasicDamageControl = true;
	ch.perks.list.AdvancedDamageControl = true;
	ch.perks.list.Rigging = true;
	ch.perks.list.RiggingAdvance = true;
	ch.money = "1000";
	ch.quest.help = "0";
	ch.quest.dialog = "0";
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	ch.HPBonus = 100;		// KevAtl 08-26-2007 to correct for game giving low HP
	ch.quest.officertype = OFFIC_TYPE_CARPENTER;
	ch.isOfficer = true;
	AddGameCharacter(n, ch);

	//Angus Calhoun
	//Quartermaster
	ch.old.name = "Angus";
	ch.old.lastname = "Calhoun";
	ch.name = TranslateString("", "Angus");
	ch.lastname = TranslateString("", "Calhoun");
	ch.id		= "Angus Calhoun";
	ch.model	= "gm_crew22";
	ch.sex = "man";
	ch.loyality = 15;
	ch.alignment = "good";
	ch.sound_type = "seaman";
	GiveItem2Character(ch, "blade11");
	GiveItem2Character(ch, "PiratesPistol");
	ch.equip.blade = "blade11";
	ch.equip.gun = "PiratesPistol";
    //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
    //JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Enc_Officer_dialog.c"; // KK
	ch.Dialog.CurrentNode = "Hired"; // KK
	ch.rank 	= 5;
	ch.reputation = "50";
	TakeNItems(ch,"medical1", Rand(4)+1);
	ch.experience = CalculateExperienceFromRank(5)+ (CalculateExperienceFromRank(5)/10 + rand(500));
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "8";
	ch.skill.Sneak = "1";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.BasicCommerce = true;
	ch.perks.list.AdvancedCommerce = true;
	ch.perks.list.Trustworthy = true;
	ch.perks.list.BasicLandOwner = true;
	ch.money = "1000";
	ch.quest.help = "0";
	ch.quest.dialog = "0";
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	ch.HPBonus = 100;		// KevAtl 08-26-2007 to correct for game giving low HP
	ch.quest.officertype = OFFIC_TYPE_QMASTER;
	ch.isOfficer = true;
	AddGameCharacter(n, ch);

	ch.old.name = "William";
	ch.old.lastname = "Bush";
	ch.name = TranslateString("","William");
	ch.lastname = TranslateString("","Bush");
	ch.id		= "Lt. William Bush";
	ch.model = "BushLtn_18";
	ch.sex = "man";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	GiveItem2Character(ch, "pistol1");
	ch.equip.gun = "pistol1";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.Dialog.Filename = "Lt. William Bush_dialog.c";
	ch.nation = ENGLAND;
	ch.rank 	= 20;
	ch.reputation = "60";
	ch.experience = "6";
	ch.skill.Leadership = "7";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "7";
	ch.skill.Accuracy = "7";
	ch.skill.Cannons = "8";
	ch.skill.Grappling = "8";
	ch.skill.Repair = "8";
	ch.skill.Defence = "7";
	ch.skill.Commerce = "8";
	ch.skill.Sneak = "8";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.Toughness = true;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.FastReload = true;
	ch.perks.list.Disguiser = true;
	ch.perks.list.BasicCommerce = true;
	ch.perks.list.IronWill = true;
	ch.money = "500";
//	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	ch.professionalnavy = ch.nation;
	ch.quest.officertype = OFFIC_TYPE_FIRSTMATE;
	ch.questchar = true;
	SetRank(ch, ENGLAND, 4);
	AddGameCharacter(n, ch);

	ch.old.name = "Dark";
	ch.old.lastname = "Captain";
	ch.name = TranslateString("Dark","Captain");
	ch.lastname = "";
	ch.id		= "DarkNavigator";
	ch.model = "animists2";
	ch.sex = "man";
	ch.grsex = "man";
	ch.loyality = 10;
	ch.alignment = "bad";
	ch.sound_type = "priest";
	GiveItem2Character(ch, "blade10");
	ch.equip.blade = "blade10";
	ch.location	= "none";
	ch.location.group = "none";
	ch.location.locator = "none";
	ch.Dialog.Filename = "Enc_Officer_dialog.c";
	ch.Dialog.CurrentNode = "Hired";
	ch.greeting = "Gr_Quest_ANIMISTS";
	ch.nation = PIRATE;
	ch.rank 	= 8;
	ch.reputation = "22";
	TakeNItems(ch,"medical1", Rand(4)+1);
	ch.experience = CalculateExperienceFromRank(8)+ (CalculateExperienceFromRank(8)/10 + rand(8000));
	ch.skill.Leadership = "8";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "9";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "4";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "1";
	ch.skill.Defence = "4";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "8";
	ch.money = "0";
	ch.quest.meeting = "0";
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.isOfficer = true;
	ch.quest.officertype = OFFIC_TYPE_NAVIGATOR;
	ch.questchar = true;
	AddGameCharacter(n, ch);

	ch.old.name = "Dark";
	ch.old.lastname = "Cannoneer";
	ch.name = TranslateString("Dark","Cannoneer");
	ch.lastname = "";
	ch.id		= "DarkGunner";
	ch.model = "animists2";
	ch.sex = "man";
	ch.grsex = "man";
	ch.loyality = 10;
	ch.alignment = "bad";
	ch.sound_type = "male_citizen";
	GiveItem2Character(ch, "blade10");
	ch.equip.blade = "blade10";
	ch.location	= "none";
	ch.location.group = "none";
	ch.location.locator = "none";
	ch.Dialog.Filename = "Enc_Officer_dialog.c";
	ch.Dialog.CurrentNode = "Hired";
	ch.greeting = "Gr_Quest_ANIMISTS";
	ch.nation = PIRATE;
	ch.rank 	= 8;
	ch.reputation = "22";
	TakeNItems(ch,"medical1", Rand(4)+1);
	ch.experience = CalculateExperienceFromRank(8)+ (CalculateExperienceFromRank(8)/10 + rand(8000));
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "6";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "9";
	ch.skill.Grappling = "2";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "6";
	ch.money = "0";
	ch.quest.meeting = "0";
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.isOfficer = true;
	ch.quest.officertype = OFFIC_TYPE_CANNONEER;
	ch.questchar = true;
	AddGameCharacter(n, ch);

	ch.old.name = "Ralph";
	ch.old.lastname = "Fawn";
	ch.name = TranslateString("","Ralph");
	ch.lastname = TranslateString("","Fawn");
	ch.id		= "RalphFawn";
	ch.model = "fawn";
	ch.sex = "man";
	ch.sound_type = "seaman";
	ch.location	= "none";
	ch.location.group = "none";
	ch.location.locator = "none";
	GiveItem2Character(ch, "blade7");
	ch.equip.blade = "blade7";
	ch.Dialog.Filename = "Enc_Officer_dialog.c";
	ch.Dialog.CurrentNode = "Hired";
	ch.greeting = "Gr_Ralph Fawn";
	ch.nation = ENGLAND;
	ch.rank 	= 3;
	ch.reputation = "50";
	ch.experience = CalculateExperienceFromRank(3)+ (CalculateExperienceFromRank(3)/10 + rand(3000));
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
	ch.quest.meeting = "0";
	ch.quest.hire = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 10.0, 10.0);
	LAi_NoRebirthEnable(ch);
	ch.isOfficer = true;
	ch.quest.officertype = OFFIC_TYPE_BOATSWAIN;
	ch.questchar = true;
	AddGameCharacter(n, ch);
}
