void CreateOfficersCharacters(ref n)
{
	object chobj;
	ref ch;

	makeref(ch, chobj);

	// Capitaine Chevalle
	ch.old.name 	= "Capitaine";
	ch.old.lastname 	= "Chevalle";
	ch.name 	= TranslateString("","Captaine");
	ch.lastname 	= TranslateString("","Chevalle");
	ch.id		= "Captaine Chevalle";
	ch.model = "Captaine_Chevalle";
	ch.sound_type = "pirate";
	ch.sex = "man";
	ch.loyality = 7;
	ch.alignment = "bad";
	GiveItem2Character(ch, "blade14");
	ch.equip.blade = "blade14";
	ch.nation	= FRANCE;
	GiveItem2Character(ch, "pistol1");
	ch.equip.gun = "pistol1";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Captaine Chevalle_dialog.c";
	ch.greeting = "Gr_Captaine Chevalle";
	ch.Flags.Pirate = 1; // PB: Capitaine Chevalle Pirate Flag
	ch.Flags.Pirate.texture = 1;
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
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 150.0, 150.0);
	ch.HPBonus = 100;		// KevAtl 08-26-2007 to correct for game giving low HP
	LAi_NoRebirthEnable(ch);
	ch.isOfficer = true;
	AddGameCharacter(n, ch);

	// Lucas Da Saldanha
	ch.old.name = "Lucas";
	ch.old.lastname = "Da Saldanha";
	ch.name = TranslateString("","Lucas");
	ch.lastname = TranslateString("","Da Saldanha");
	ch.id		= "Lucas Da Saldanha";
	ch.loyality = 10;
	ch.alignment = "good";
	ch.model = "lucas2";
	GiveItem2Character(ch, "goldarmor");
//	ch.model = "lucas";	// Old style armour with old style helmet
	ch.sex = "man";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "goto7";
	ch.homelocation	= "Muelle_residence";
	ch.homelocation.group = "goto";
	ch.homelocation.locator = "goto2";
	ch.homestate = "citizen";
	ch.Dialog.Filename = "Lucas Da Saldanha_dialog.c";
	ch.greeting = "Gr_Lucas Da Saldanha";
	ch.nation = SPAIN;
	ch.rank 	= 5;
	ch.reputation = "70";
	TakeNItems(ch,"medical1", Rand(4)+1);
	ch.experience = CalculateExperienceFromRank(5)+ (CalculateExperienceFromRank(5)/10 + rand(5000));
	ch.skill.Leadership = "3";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "0";
	ch.skill.Sneak = "0";
	ch.money = "0";
	ch.perks.list.CriticalHit = true;
	ch.perks.list.Gunman = true;
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.HPBonus = 100;		// KevAtl 08-26-2007 to correct for game giving low HP
	LAi_NoRebirthEnable(ch);
	ch.isOfficer = true;
	AddGameCharacter(n, ch);

	// Jaoquin De Masse  мальтийский рыцарь.
	ch.old.name = "Jaoquin";
	ch.old.lastname = "De Masse";
	ch.name = TranslateString("","Jaoquin");
	ch.lastname = TranslateString("","De Masse");
	ch.id		= "Jaoquin De Masse";
	ch.model = "maltese";
	ch.sex = "man";
	ch.loyality = 10;
	ch.nation	= SPAIN;
	ch.alignment = "good";
	ch.sound_type = "priest";
	GiveItem2Character(ch, "blade8");
	ch.equip.blade = "blade8";
	ch.location	= "none";
	ch.location.group = "none";
	ch.location.locator = "none";
	ch.homelocation	= "Muelle_church";
	ch.homelocation.group = "goto";
	ch.homelocation.locator = "goto2";
	ch.homestate = "citizen";
	ch.Dialog.Filename = "Jaoquin De Masse_dialog.c";
	ch.greeting = "Gr_Jaoquin de masse";
	ch.rank 	= 8;
	ch.reputation = "75";
	TakeNItems(ch,"medical1", Rand(4)+1);
	ch.experience = CalculateExperienceFromRank(8)+ (CalculateExperienceFromRank(8)/10 + rand(8000));
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "4";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "0";
	ch.money = "0";
	ch.quest.meeting = "0";
	ch.perks.list.CriticalHit = true;
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.IronWill = true;
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.HPBonus = 100;		// KevAtl 08-26-2007 to correct for game giving low HP
	LAi_NoRebirthEnable(ch);
	ch.quest.officertype = OFFIC_TYPE_GUARD; // Levis
	ch.isOfficer = true;
	AddGameCharacter(n, ch);

	// Gentleman Jocard
	ch.old.name = "Gombo";
	ch.old.lastname = "the Slave";
	ch.name = TranslateString("","Gombo");
	ch.lastname = TranslateString("","the Slave");
	ch.id		= "Gentleman Jocard";
	ch.model = "blackman";
	ch.sex = "man";
	ch.act.type = "merchant";
	ch.loyality = 10;
	ch.alignment = "good";
	ch.nation	= PIRATE;
	GiveItem2Character(ch, "blade6");
	ch.equip.blade = "blade6";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "none"; // KK
	ch.location.group = ""; // KK
	ch.location.locator = ""; // KK
	ch.homelocation	= "QC_town";
	ch.homelocation.group = "goto";
	ch.homelocation.locator = "goto5";
	ch.homestate = "citizen";
	ch.Ship.Name = "Ranger";
	ch.Ship.Type = "PiratCorvette";
	ch.Ship.Stopped = true;
	ch.Dialog.Filename = "Gentleman Jocard_dialog.c";
	ch.Flags.Pirate = 0; // PB: Gentleman Jocard Pirate Flag
	ch.Flags.Pirate.texture = 1;
	ch.rank 	= 4;
	ch.reputation = "64";
	TakeNItems(ch,"medical1", Rand(4)+1);
	ch.experience = CalculateExperienceFromRank(4)+ (CalculateExperienceFromRank(4)/10 + rand(4000));
	ch.skill.Leadership = "3";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "3";
	ch.skill.Sneak = "0";
	ch.money = 10;
	ch.perks.list.ShipSpeedUp = true;
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 8.0, 8.0);
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Artois Voysey";
	ch.quest.officertype = OFFIC_TYPE_NAVIGATOR; // added by MAXIMUS
	ch.isOfficer = true;
	AddGameCharacter(n, ch);

	// Slaver
	ch.old.name = "Prognatus";
	ch.old.lastname = "Solvo";
	ch.name = TranslateString("","Prognatus");
	ch.lastname = TranslateString("","Solvo");
	ch.id		= "Slaver";
	ch.model = "killer";
	ch.sex = "man";
	ch.loyality = 10;
	ch.nation	= PIRATE;
	ch.alignment = "bad";
	ch.location	= "none"; // KK
	ch.location.group = ""; // KK
	ch.location.locator = ""; // KK
	ch.homelocation	= "QC_town";
	ch.homelocation.group = "goto";
	ch.homelocation.locator = "character4";
	ch.homestate = "citizen";
	ch.Dialog.Filename = "Slaver_dialog.c";
	GiveItem2Character(ch, "bladeX4");
	ch.equip.blade = "bladeX4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.rank 	= 4;
	ch.reputation = "24";
	TakeNItems(ch,"medical1", Rand(4)+1);
	ch.experience = CalculateExperienceFromRank(4)+ (CalculateExperienceFromRank(4)/10 + rand(4000));
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "2";			// Petros  changed from 5
	ch.skill.Sailing = "2";
	ch.skill.Accuracy = "4";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "4";
	ch.skill.Repair = "0";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "0";
	ch.skill.Sneak = "0";
	ch.money = "0";
	//ch.perks.list.BasicDefence = true;		// Petros comment out so he is not too strong at first
	//ch.perks.list.CriticalHit = true;			// Petros ditto
	ch.skill.freeskill = 3;				// Petros added as points to increase ability later in game
	ch.perks.freepoints = 3;			// Petros ditto
	ch.HPBonus = 50;			// Petros  to correct for game only giving 48
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Nigel Blythe";
	ch.isOfficer = true;
	AddGameCharacter(n, ch);
}
