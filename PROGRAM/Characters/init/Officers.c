void CreateOfficersCharacters(ref n)
{
	object chobj;
	ref ch;

	makeref(ch, chobj);

//Fred Bob - HELP THE BOATSWAIN + HELP THE LADY (CatalinaThePirate FB Quest)
	ch.old.name = "Fred";
	ch.old.lastname = "Bob";
	ch.name = TranslateString("","Fred");
	ch.lastname = TranslateString("","Bob");
	ch.id		= "Fred Bob";
	ch.model	= "FredBob";
	ch.sex = "man";
	ch.loyality = 15;
	ch.alignment = "good";
	ch.sound_type = "seaman";
	ch.nation	= PIRATE;
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Fred Bob_dialog.c";
	ch.greeting = "Gr_FredBob";
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
	ch.perks.list.BasicDefense = true;
	ch.perks.list.AdvancedDefense = true;
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
	ch.quest.help = "0";
	ch.quest.dialog = "0";
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	LAi_SetHP(ch, 280.0, 280.0);
	ch.HPBonus = 200;			// Petros  to correct for game only giving 96
	LAi_NoRebirthEnable(ch);
// added by MAXIMUS [making him a REAL boatswain] -->
	ch.quest.officertype = OFFIC_TYPE_BOATSWAIN;
	ch.quest.officerprice = "500";
// added by MAXIMUS [making him a REAL boatswain] <--
	ch.isOfficer = true;
	AddGameCharacter(n, ch);

// Baldewyn Coffier - BALDEWYN COFFIER & ARNAUD MATTON
	ch.old.name = "Baldewyn";
	ch.old.lastname = "Coffier";
	ch.name = TranslateString("","Baldewyn");
	ch.lastname = TranslateString("","Coffier");
	ch.id		= "Baldewyn Coffier";
	ch.loyality = 10;
	ch.alignment = "good";
	ch.model = "fatman2_1";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	TakeNItems(ch,"medical1", Rand(4)+1);
	GiveItem2Character(ch, "MerchantsBlade");
	ch.equip.blade = "MerchantsBlade";
	ch.location	= "Falaise_de_fleur_tavern"; // NK
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.homelocation	= "Falaise_de_fleur_tavern";
	ch.homelocation.group = "sit";
	ch.homelocation.locator = "sit1";
	ch.homestate = "sit";
	ch.Dialog.Filename = "Baldewyn Coffier_dialog.c";
	ch.nation = FRANCE;
	ch.rank 	= 3;
	ch.reputation = "60";
	ch.experience = CalculateExperienceFromRank(3)+ (CalculateExperienceFromRank(3)/10 + rand(3000));
	ch.skill.Leadership = "0";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "5";
	ch.skill.Sneak = "0";
	ch.money = "0";
	ch.quest.meeting = "0";
	ch.quest.hire = "0";
	ch.perks.list.BasicCommerce = true;
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.HPBonus = 100;		// KevAtl 08-26-2007 to correct for game giving low HP
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_baldewyn coffier";
	ch.quest.officertype = OFFIC_TYPE_QMASTER;
	ch.isOfficer = true;
	AddGameCharacter(n, ch);

	// Lucas Da Saldanha - FIND THE MISSING SON OF THE SPANISH ADMIRAL (Lucas Da Saldanha quest)
	ch.old.name = "Lucas";
	ch.old.lastname = "Da Saldanha";
	ch.name = TranslateString("","Lucas");
	ch.lastname = TranslateString("","Da Saldanha");
	ch.id		= "Lucas Da Saldanha";
	ch.loyality = 10;
	ch.alignment = "good";
	if (GetCurrentPeriod() >= PERIOD_COLONIAL_POWERS)
	{
		ch.model = "lucas2";
		GiveItem2Character(ch, "goldarmor");
	}
	else ch.model = "lucas";
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
	ch.quest.officertype = OFFIC_TYPE_ABORDAGE;
	ch.isOfficer = true;
	AddGameCharacter(n, ch);

//Rys Bloom - RYS BLOOM QUEST
	ch.old.name = "Rys";
	ch.old.lastname = "Bloom";
	ch.name = TranslateString("","Rys");
	ch.lastname = TranslateString("","Bloom");
	ch.id		= "Rys Bloom";
	ch.model	= "Chameleon";
	ch.sex = "man";
	ch.loyality = 15;
	ch.alignment = "good";
	ch.sound_type = "seaman";
	GiveItem2Character(ch, "blade6");
	ch.equip.blade = "blade6";
	ch.location	= "Redmond_port";
	ch.location.group = "goto";
	ch.location.locator = "cityzen_1";
	ch.Dialog.Filename = "Rys Bloom_dialog.c";
	ch.greeting = "Gr_Rys Bloom";
	ch.rank 	= 1;
	ch.reputation = "45";
	TakeNItems(ch,"medical1", Rand(4)+1);
	ch.experience = CalculateExperienceFromRank(1)+ (CalculateExperienceFromRank(1)/10 + rand(500));
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "0";
	ch.skill.Sneak = "0";
	ch.money = "0";
	ch.quest.help = "0";
	ch.quest.dialog = "0";
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	ch.HPBonus = 100;		// KevAtl 08-26-2007 to correct for game giving low HP
	ch.isOfficer = true;
	AddGameCharacter(n, ch);

	// Claire Larrouse французский пират в таверне Исла Муэлле.
	ch.old.name = "Claire";
	ch.old.lastname = "Larrouse";
	ch.name = TranslateString("","Claire"); // was Clair
	ch.lastname = TranslateString("","Larrouse");
	ch.id		= "Claire Larrouse";
	ch.model = "50_33_40Claire"; // was corsair1_1
	ch.model.height = 1.75;
	ch.model.animation = "woman_sit";
	ch.sex = "woman"; // was "man"
	ch.loyality = 10;
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.alignment = "bad";
	ch.nation	= PIRATE;
	ch.sound_type = "female_citizen"; // was "pirate"
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Muelle_tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit6";
	ch.homelocation	= "Muelle_tavern";
	ch.homelocation.group = "sit";
	ch.homelocation.locator = "sit6";
	ch.homestate = "sit";
	ch.Dialog.Filename = "Claire Larrouse_dialog.c"; // boal
	ch.rank 	= 6;
	ch.reputation = "42";
	TakeNItems(ch,"medical1", Rand(4)+1);
	ch.experience = CalculateExperienceFromRank(6)+ (CalculateExperienceFromRank(6)/10 + rand(6000));
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "4";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "2";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
	ch.quest.meeting = "0";
	ch.quest.goldmine = "0";
	ch.Ship.Name = "Cheri";
	ch.Ship.Type = "PiratBrig50"; // Petros: was Brig1
	ch.Ship.Stopped = true;
	//KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS12;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.BasicDefence = true;
	ch.perks.list.CrewDamageUp = true;
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Claire Larrouse";
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
	GiveItem2Character(ch, "blade50");
	ch.equip.blade = "blade50";
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
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "4";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
	ch.quest.meeting = "0";
	ch.perks.list.CriticalHit = true;
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.IronWill = true;
	ch.quest.officertype = OFFIC_TYPE_GUARD;
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.HPBonus = 100;		// KevAtl 08-26-2007 to correct for game giving low HP
	LAi_NoRebirthEnable(ch);
	ch.isOfficer = true;
	ch.quest.officertype = OFFIC_TYPE_GUARD; // Levis
	AddGameCharacter(n, ch);

	// Nigel Blythe.
	ch.old.name = "Nigel";
	ch.old.lastname = "Blythe";
	ch.name = TranslateString("","Nigel");
	ch.lastname = TranslateString("","Blythe");
	ch.id		= "Nigel Blythe";
	ch.model = "will_3";				// PB: was "will_2"; changed into his evil brother skin
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
	ch.Dialog.Filename = "Nigel Blythe_dialog.c";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.rank 	= 4;
	ch.reputation = "24";
	TakeNItems(ch,"medical1", Rand(4)+1);
	ch.experience = CalculateExperienceFromRank(4)+ (CalculateExperienceFromRank(4)/10 + rand(4000));
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "2";			// Petros  changed from 5
	ch.skill.Sailing = "2";
	ch.skill.Accuracy = "4";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "4";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
	//ch.perks.list.BasicDefence = true;		// Petros comment out so he is not too strong at first
	//ch.perks.list.CriticalHit = true;			// Petros ditto
	ch.quest.officertype = OFFIC_TYPE_CAPPIRATE;
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

	// Artois Voysey.
	ch.old.name = "Artois";
	ch.old.lastname = "Voysey";
	ch.name = TranslateString("","Artois");
	ch.lastname = TranslateString("","Voysey");
	ch.id		= "Artois Voysey";
	ch.model = "BadV";				// PB: was "man6"; changed into his evil brother skin
	ch.sex = "man";
	ch.act.type = "merchant";
	ch.loyality = 10;
	ch.alignment = "good";
	ch.nation	= FRANCE;
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
	ch.Dialog.Filename = "Artois Voysey_dialog.c";
	ch.rank 	= 4;
	ch.reputation = "64";
	TakeNItems(ch,"medical1", Rand(4)+1);
	ch.experience = CalculateExperienceFromRank(4)+ (CalculateExperienceFromRank(4)/10 + rand(4000));
	ch.skill.Leadership = "3";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "3";
	ch.skill.Sneak = "1";
	ch.money = "0";
	ch.perks.list.ShipSpeedUp = true;
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 8.0, 8.0);
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Artois Voysey";
	ch.quest.officertype = OFFIC_TYPE_NAVIGATOR; // added by MAXIMUS
	ch.isOfficer = true;
	AddGameCharacter(n, ch);

	//Hitman

	// Amerigo Vieira //SCM Changes
	ch.old.name = "Amerigo";
	ch.old.lastname = "Vieira";
	ch.name = TranslateString("","Amerigo");		// KevAtl - should give him back a first name
	ch.lastname = TranslateString("","Vieira");
	ch.id		= "Amerigo Vieira";
	ch.model = "ancient"; //SCM
	ch.sound_type = "pirate";
	ch.sex = "man";
	ch.loyality = 7;
	ch.alignment = "bad";
	GiveItem2Character(ch, "bladeSC"); // KevAtl 09-09-2007
	ch.equip.blade = "bladeSC"; // KevAtl
	ch.nation	= PORTUGAL; //SC
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.homelocation	= "";
	ch.homelocation.group = "";
	ch.homelocation.locator = "";
	ch.homestate = "stay";
	ch.Dialog.Filename = "Amerigo Vieira_dialog.c";
	ch.greeting = "Gr_Amerigo Vieira";
	ch.rank 	= 9;
	ch.reputation = "50";
	TakeNItems(ch,"medical1", Rand(4)+1);
	ch.experience = CalculateExperienceFromRank(9)+ (CalculateExperienceFromRank(9)/10 + rand(9000));
	ch.skill.Leadership = "3";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "6";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "2";
	ch.money = "0";
	ch.quest.meeting = "0";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.Gunman = true;
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 150.0, 150.0);
	ch.quest.officertype = OFFIC_TYPE_ABORDAGE;	// KevAtl to make him a Deck Fighter AKA Tough
	ch.HPBonus = 100;		// KevAtl to correct for game giving much less than 150hp when hired
	ch.skill.freeskill = 2;		// KevAtl added as points to increase ability later in game
	ch.perks.freepoints = 1;	// KevAtl ditto
	LAi_NoRebirthEnable(ch);
	ch.isOfficer = true;
	ch.questchar = true;		// GR: attempt to make his skills stick, otherwise leveling system resets them and he isn't Fencing 10 any more
	AddGameCharacter(n, ch);

	// Florens Clauss
	ch.old.name = "Florens";
	ch.old.lastname = "Clauss";
	ch.name = TranslateString("","Florens");
	ch.lastname = TranslateString("","Clauss");
	ch.id		= "Florens Clauss";
	ch.model	= "bocman3";
	ch.sex = "man";
	ch.loyality = 10;
	ch.alignment = "bad";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Clauss_dialog.c";
	ch.nation = PIRATE;
	ch.rank 	= 6;
	ch.reputation = "48";
	TakeNItems(ch,"medical1", Rand(4)+1);
	ch.experience = CalculateExperienceFromRank(6)+ (CalculateExperienceFromRank(6)/10 + rand(6000));
	ch.skill.Leadership = "3";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "4";
	ch.skill.Repair = "1";
	ch.skill.Defence = "5";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.LongRangeGrappling = true;
	ch.money = "1";
	LAi_SetCitizenType(ch);
	ch.HPBonus = 100;		// KevAtl 08-26-2007 to correct for game giving low HP
	ch.greeting = "Gr_Clauss";
	ch.isOfficer = true;
	ch.quest.officertype = OFFIC_TYPE_BOATSWAIN;
	AddGameCharacter(n, ch);

	// Edgar Attwood тюремщик на редмонде - канонир.
	ch.old.name = "Edgar";
	ch.old.lastname = "Attwood";
	ch.name = TranslateString("","Edgar");
	ch.lastname = TranslateString("","Attwood");
	ch.id		= "Edgar Attwood";
	ch.loyality = 10;
	ch.alignment = "bad";
	ch.model = "old_man2";
	ch.sex = "man";
	ch.sound_type = "pirate";
	TakeNItems(ch,"medical1", Rand(4)+1);
	GiveItem2Character(ch, "bladeC12");
	ch.equip.blade = "bladeC12";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "Redmond_prison";
	ch.location.group = "goto";
	ch.location.locator = "goto13";
	ch.homelocation	= "Redmond_prison";
	ch.homelocation.group = "goto";
	ch.homelocation.locator = "goto13";
	ch.homestate = "citizen";
	ch.Dialog.Filename = "Edgar Attwood_dialog.c";
	ch.nation = ENGLAND;
	ch.rank 	= 5;
	ch.reputation = "35";
	ch.experience = CalculateExperienceFromRank(5)+ (CalculateExperienceFromRank(5)/10 + rand(5000));
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "2";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "6";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
	ch.quest.meeting = "0";
	ch.quest.to_hire = "0";
	ch.perks.list.FastReload = true;
	ch.perks.list.HullDamageUp = true;
	ch.perks.list.BasicDamageControl = true;
	ch.perks.list.Rigging = true;
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.HPBonus = 100;		// KevAtl 08-26-2007 to correct for game giving low HP
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Edgar Attwood";
	ch.quest.officertype = OFFIC_TYPE_CANNONEER; // PB
	ch.quest.officerprice = "1500";
	ch.isOfficer = true;
	AddGameCharacter(n, ch);

	//Bartolomeu
	// Peter Blood
	ch.old.name 	= "Peter";
	ch.old.lastname 	= "Blood";
	ch.name 	= TranslateString("","Peter");
	ch.lastname 	= TranslateString("","Blood");
	ch.id		= "Bartolomeu o Portugues";
	ch.model = "Peter_Blood";
	ch.sound_type = "pirate";
	ch.sex = "man";
	ch.loyality = 7;
	ch.alignment = "bad";
	GiveItem2Character(ch, "blade27");
	ch.equip.blade = "blade27";
	ch.nation	= PIRATE;
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
		TakenItems(ch, "gunpowder", 6);
		TakenItems(ch, "pistolbullets", 6);
	}
	//JRH ammo mod <--
	ch.location	= "Grand_Cayman_Tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto2";
	ch.Dialog.Filename = "Bartolomeu o Portugues_dialog.c";
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
	SetRankTitle(ch, TranslateString("", "Doctor"));
	ch.isOfficer = true;
	ch.quest.officertype = OFFIC_TYPE_DOCTOR;
	AddGameCharacter(n, ch);

	//Txiki Pijuan
	ch.old.name 	= "Txiki";
	ch.old.lastname 	= "Pijuan";
	ch.name 	= TranslateString("","Txiki");
	ch.lastname 	= TranslateString("","Pijuan");
	ch.id		= "Txiki Pijuan";
	ch.model = "Napitan";
	ch.sound_type = "pirate";
	ch.sex = "man";
	ch.loyality = 7;
	ch.alignment = "bad";
	ch.nation	= SPAIN;
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Txiki Pijuan_dialog.c";
	ch.greeting = "Gr_Txiki Pijuan";
	ch.rank 	= 7;
	ch.reputation = "50";
	TakeNItems(ch,"medical1", Rand(4)+1);
	ch.experience = CalculateExperienceFromRank(7)+ (CalculateExperienceFromRank(7)/10 + rand(7000));
	ch.skill.Leadership = "3";
	ch.skill.Fencing = "2";
	ch.skill.Sailing = "6";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "6";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "2";
	ch.money = "0";
	ch.quest.meeting = "0";
	ch.Ship.Name = "Arabella";
	switch(GetCurrentPeriod())
	{
		case PERIOD_EARLY_EXPLORERS:
			ch.Ship.Type = 	"Caravel1";
		break;
		case PERIOD_THE_SPANISH_MAIN:
			ch.Ship.Type = 	"Caravel1";
		break;
		case PERIOD_GOLDEN_AGE_OF_PIRACY:
			ch.Ship.Type = 	"SP_Postillionen";
		break;
		case PERIOD_COLONIAL_POWERS:
			ch.Ship.Type = 	"SP_Postillionen";
		break;
		case PERIOD_REVOLUTIONS:
			ch.Ship.Type = 	"FastMerchantman1";
		break;
		case PERIOD_NAPOLEONIC:
			ch.Ship.Type = 	"FastMerchantman1";
		break;
	}
//	ch.Ship.Type = "SP_Postillionen";	// Only valid in "Golden Age of Piracy" and "Colonial Powers" periods
	ch.Ship.Stopped = true;
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.Gunman = true;
	ch.perks.list.HullDamageUp = true;
	ch.perks.list.BasicDamageControl = true;
	ch.perks.list.Rigging = true;
	ch.quest.officertype = OFFIC_TYPE_NAVIGATOR;
	ch.quest.officerprice = "500";
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 130.0, 130.0);
	LAi_SetImmortal(ch, true); // PB
	ch.HPBonus = 100;		// KevAtl 08-26-2007 to correct for game giving low HP
	LAi_NoRebirthEnable(ch);
	ch.isOfficer = true;
	AddGameCharacter(n, ch);
}
