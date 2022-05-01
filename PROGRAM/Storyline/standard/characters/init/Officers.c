void CreateOfficersCharacters(ref n)
{
	object chobj;
	ref ch;

	makeref(ch, chobj);

	//Danielle Даниэль
	ch.old.name = "Danielle";
	ch.old.lastname = "Greene";
	ch.name = TranslateString("","Danielle");
	ch.lastname = TranslateString("","Greene");
	ch.id		= "Danielle";
	ch.nation	= ENGLAND;
	ch.model	= "Danielle";
	ch.model.animation = "woman_sit";
	ch.activity_begin = "0";
	ch.activity_end = "24";
	ch.sex = "woman";
	ch.luck = 4;
	GiveItem2Character(ch, "blade6");
	TakeNItems(ch,"medical1", Rand(4)+1);
	ch.equip.blade = "blade6";
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
	ch.Dialog.Filename = "Danielle_dialog.c";
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
	ch.Ship.Name = "Vertigo";
	ch.Ship.Type = "Schooner2"; // PRS3
	ch.Flags.Pirate = 0;
	ch.Flags.Pirate.texture = 3;
	ch.Flags.Personal = 5;
	ch.Flags.Personal.texture = 0;
	//KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS16;
	// done by setbaseship - NK 05-04-09 ch.ship.cargo.goods.bombs = 1000;
	ch.FaceId = 30;
	// 04-12-5 this is making things worse ch.alwaysload = true; LAi_LoginInCaptureTown(characterFromID("Danielle"),true); // NK 04-11-10 fix
	ch.HPBonus = 100;		// KevAtl 08-26-2007 to correct for game giving low HP
	ch.isOfficer = true;
	AddGameCharacter(n, ch);

	// Ralph Fawn  боцман девушки.
	ch.old.name = "Ralph";
	ch.old.lastname = "Fawn";
	ch.name = TranslateString("","Ralph");
	ch.lastname = TranslateString("","Fawn");
	ch.id		= "Ralph Fawn";
	ch.model = "fawn";
	ch.sex = "man";
	ch.sound_type = "seaman";
	ch.location	= "none";
	ch.location.group = "none";
	ch.location.locator = "none";
	GiveItem2Character(ch, "blade7");
	ch.equip.blade = "blade7";
	ch.Dialog.Filename = "Ralph Fawn_dialog.c";
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
	AddGameCharacter(n, ch);

	// Researcher Изобретатель
	ch.old.name = "Clement";
	ch.old.middlename = "Barnabas";
	ch.old.lastname = "Aurentius";
	ch.name = TranslateString("","Clement");
	ch.middlename = TranslateString("","Barnabas");
	ch.lastname = TranslateString("","Aurentius");
	ch.id		= "Researcher";
	ch.model = "researcher";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "goto7";
	ch.Dialog.Filename = "researcher_dialog.c";
	ch.greeting = "Gr_researcher";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "9";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
	ch.quest.meeting = "0";
	ch.Ship.Name = "Astra";
	ch.Ship.Type = "Tartane1"; // PS - SHIP_TARTANE;
	ch.Ship.Stopped = true;
	ch.Ship.Cannons.Type = CANNON_TYPE_NONECANNON;
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_NoRebirthEnable(ch);
	LAi_SetImmortal(ch, true);
	ch.isOfficer = true;
	ch.quest.officertype = OFFIC_TYPE_CARPENTER;
	ch.questchar = true;	// Protect character from levelling system
	AddGameCharacter(n, ch);

	//Leborio Drago worker in mine
	ch.old.name = "Leborio";
	ch.old.lastname = "Drago";
	ch.name = TranslateString("","Leborio");
	ch.lastname = TranslateString("","Drago");
	ch.id		= "Leborio Drago";
	ch.loyality = 10;
	ch.alignment = "good";
	ch.model	= "blackman";
	ch.sex = "man";
	ch.location	= "Oxbay_mine";
	ch.location.group = "goto";
	ch.location.locator = "goto6";
	ch.homelocation	= "Falaise_de_fleur_port";
	ch.homelocation.group = "goto";
	ch.homelocation.locator = "goto4";
	ch.homestate = "citizen";
	ch.Dialog.Filename = "Leborio Drago_dialog.c";
	ch.greeting = "Gr_Leborio Drago";
	ch.nation = FRANCE;
	ch.rank 	= 4;
	ch.reputation = "42";
	TakeNItems(ch,"medical1", Rand(4)+1);
	ch.experience = CalculateExperienceFromRank(4)+ (CalculateExperienceFromRank(4)/10 + rand(4000));
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "4";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "2";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
	ch.quest.hire = "";
	ch.perks.list.LightRepair = true;
	ch.perks.list.SharedExperience = true;
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.HPBonus = 100;		// KevAtl 08-26-2007 to correct for game giving low HP
	LAi_NoRebirthEnable(ch);
	ch.isOfficer = true;
	AddGameCharacter(n, ch);

	// Gervasio Serrao - в таверне пиратского острова
	ch.old.name = "Gervasio";
	ch.old.lastname = "Serrao";
	ch.name = TranslateString("","Gervasio");
	ch.lastname = TranslateString("","Serrao");
	ch.id		= "Gervasio Serrao";
	ch.model = "bocman4";
	ch.loyality = 10;
	ch.alignment = "bad";
	ch.sex = "man";
	ch.sound_type = "seaman";
	ch.nation	= PIRATE;
	GiveItem2Character(ch, "blade7");
	ch.equip.blade = "blade7";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "Pirate_tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit5";
	ch.homelocation	= "Pirate_tavern";
	ch.homelocation.group = "sit";
	ch.homelocation.locator = "sit5";
	ch.homestate = "sit";
	ch.Dialog.Filename = "Gervasio Serrao_dialog.c";
	ch.rank 	= 4;
	ch.reputation = "22";
	TakeNItems(ch,"medical1", Rand(4)+1);
	ch.experience = CalculateExperienceFromRank(4)+ (CalculateExperienceFromRank(4)/10 + rand(4000));
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
	ch.quest.hire = "0";
	ch.perks.list.Rush = true;
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Gervasio Serrao";
	ch.isOfficer = true;
	AddGameCharacter(n, ch);
}
